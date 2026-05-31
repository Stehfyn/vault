/*
 * 13_patch_iat.c — launch gui_target.exe suspended, patch its IAT so
 * MessageBoxW returns IDOK without showing the dialog, then resume.
 *
 * Why CreateProcess cannot do this cleanly
 * -----------------------------------------
 * CreateProcessW + CREATE_SUSPENDED gives you a process whose initial
 * thread is suspended -- but the kernel has *already* run loader init
 * for the main image's static imports. By the time you get the handle,
 * the IAT has been populated. You can still patch it, but you race
 * against any TLS callback or .CRT$ early init that already executed.
 *
 * NtCreateUserProcess in this sample combines the section map with the
 * thread create in a way where the image is in memory but no user-mode
 * code (loader or otherwise) has executed in the child. We patch the
 * IAT before that first instruction.
 *
 * Mechanism
 *   1. Spawn gui_target.exe via NtCreateUserProcess, suspended.
 *   2. PsAttributeImageInfo gives us its image base.
 *   3. Read PE headers from the child.
 *   4. Walk import directory, find USER32.DLL.
 *   5. Walk that descriptor's Original First Thunk (the name table) to
 *      locate MessageBoxW by name; record the IAT slot offset.
 *   6. Allocate a small RX page in the child via NtAllocateVirtualMemory.
 *   7. Write a tiny x64 stub there:  mov eax, 1 ; ret    (returns IDOK)
 *   8. NtProtectVirtualMemory the IAT slot to RW.
 *   9. NtWriteVirtualMemory the new function pointer into that slot.
 *  10. Restore IAT to R, restore stub page to RX.
 *  11. Resume.
 *
 * Verify by checking the marker: MessageBoxW returned=1 with no dialog.
 */

#include "common.h"

/* The 6-byte x64 stub: "return IDOK (1)" */
static const UCHAR g_stub[] = {
    0xB8, 0x01, 0x00, 0x00, 0x00, /* mov eax, 1  (IDOK) */
    0xC3                          /* ret               */
};

static NTSTATUS readmem(HANDLE p, PVOID addr, PVOID buf, SIZE_T n)
{
    SIZE_T got = 0;
    return NtReadVirtualMemory(p, addr, buf, n, &got);
}

static NTSTATUS writemem(HANDLE p, PVOID addr, const void *buf, SIZE_T n)
{
    SIZE_T put = 0;
    return NtWriteVirtualMemory(p, addr, (PVOID)buf, n, &put);
}

/* Read a NUL-terminated ANSI string out of the child. */
static int read_asciiz(HANDLE p, PVOID addr, char *buf, SIZE_T cap)
{
    SIZE_T i;
    for (i = 0; i + 1 < cap; ++i) {
        char c = 0;
        if (!NT_SUCCESS(readmem(p, (UCHAR*)addr + i, &c, 1))) return -1;
        buf[i] = c;
        if (c == 0) return (int)i;
    }
    buf[cap - 1] = 0;
    return (int)cap;
}

int wmain(void)
{
    NTSTATUS status;
    int rc = 1;
    HANDLE hProcess = NULL, hThread = NULL;
    PRTL_USER_PROCESS_PARAMETERS params = NULL;
    PPS_ATTRIBUTE_LIST attrs = NULL;
    PVOID env = NULL;
    PVOID remote_stub = NULL;

    WCHAR dos_image[MAX_PATH];
    GetModuleFileNameW(NULL, dos_image, MAX_PATH);
    PWSTR slash = wcsrchr(dos_image, L'\\');
    wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - dos_image), L"gui_target.exe");
    fwprintf(stderr, L"[13] target = %ls\n", dos_image);

    UNICODE_STRING nt_image;
    status = Cps_DosToNtPath(dos_image, &nt_image);
    if (!NT_SUCCESS(status)) return 1;

    WCHAR cmdbuf[MAX_PATH + 32];
    swprintf_s(cmdbuf, _countof(cmdbuf), L"\"%s\"", dos_image);
    UNICODE_STRING cmdline;
    Cps_InitUnicodeString(&cmdline, cmdbuf);

    PCWSTR env_entries[] = {
        L"PATH=C:\\Windows\\System32;C:\\Windows",
        L"SystemRoot=C:\\Windows",
        L"TEMP=C:\\Windows\\Temp",
        L"TMP=C:\\Windows\\Temp",
    };
    env = Cps_BuildEnvBlock(env_entries, _countof(env_entries));

    status = Cps_MakeParams(&nt_image, &cmdline, env, &params);
    Cps_PrintStatus("RtlCreateProcessParametersEx", status);
    if (!NT_SUCCESS(status)) goto cleanup;
    params->StandardInput  = GetStdHandle(STD_INPUT_HANDLE);
    params->StandardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    params->StandardError  = GetStdHandle(STD_ERROR_HANDLE);

    SIZE_T list_bytes = sizeof(SIZE_T) + 3 * sizeof(PS_ATTRIBUTE);
    attrs = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, list_bytes);
    attrs->TotalLength = list_bytes;
    CLIENT_ID cid = {0};
    SECTION_IMAGE_INFORMATION sii = {0};
    attrs->Attributes[0].Attribute = PS_ATTRIBUTE_IMAGE_NAME;
    attrs->Attributes[0].Size      = nt_image.Length;
    attrs->Attributes[0].ValuePtr  = nt_image.Buffer;
    attrs->Attributes[1].Attribute = PS_ATTRIBUTE_CLIENT_ID;
    attrs->Attributes[1].Size      = sizeof(cid);
    attrs->Attributes[1].ValuePtr  = &cid;
    attrs->Attributes[2].Attribute = PS_ATTRIBUTE_IMAGE_INFO;
    attrs->Attributes[2].Size      = sizeof(sii);
    attrs->Attributes[2].ValuePtr  = &sii;

    PS_CREATE_INFO ci = { sizeof(ci) };
    ci.State = PsCreateInitialState;

    status = NtCreateUserProcess(
        &hProcess, &hThread,
        PROCESS_ALL_ACCESS, THREAD_ALL_ACCESS,
        NULL, NULL,
        PROCESS_CREATE_FLAGS_INHERIT_HANDLES,
        THREAD_CREATE_FLAGS_CREATE_SUSPENDED,   /* suspended! */
        params, &ci, attrs);
    Cps_PrintStatus("NtCreateUserProcess(suspended)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    fwprintf(stderr, L"  child pid=%llu  entry=%p\n",
        (unsigned long long)(ULONG_PTR)cid.UniqueProcess, sii.TransferAddress);

    /* --------- locate image base via PEB ---------------------------- */
    PROCESS_BASIC_INFORMATION pbi = {0};
    NtQueryInformationProcess(hProcess, ProcessBasicInformation,
                              &pbi, sizeof(pbi), NULL);
    PVOID image_base = NULL;
    readmem(hProcess, (PUCHAR)pbi.PebBaseAddress + 0x10,
            &image_base, sizeof(image_base));
    fwprintf(stderr, L"  child image base = %p\n", image_base);

    /* --------- parse PE headers ------------------------------------- */
    IMAGE_DOS_HEADER dos;
    readmem(hProcess, image_base, &dos, sizeof(dos));
    if (dos.e_magic != IMAGE_DOS_SIGNATURE) {
        fwprintf(stderr, L"  bad DOS sig\n"); goto cleanup;
    }
    IMAGE_NT_HEADERS64 nt;
    readmem(hProcess, (UCHAR*)image_base + dos.e_lfanew, &nt, sizeof(nt));
    if (nt.Signature != IMAGE_NT_SIGNATURE) {
        fwprintf(stderr, L"  bad NT sig\n"); goto cleanup;
    }
    DWORD imp_rva  = nt.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
    DWORD imp_size = nt.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size;
    fwprintf(stderr, L"  import dir: RVA=0x%lX size=0x%lX\n", imp_rva, imp_size);
    if (!imp_rva) { fwprintf(stderr, L"  no imports\n"); goto cleanup; }

    /* --------- walk import descriptors to find user32 --------------- */
    IMAGE_IMPORT_DESCRIPTOR desc;
    PVOID user32_iat = NULL;
    PVOID user32_int = NULL;
    int found_user32 = 0;
    for (DWORD i = 0; ; ++i) {
        PVOID addr = (UCHAR*)image_base + imp_rva + i * sizeof(desc);
        readmem(hProcess, addr, &desc, sizeof(desc));
        if (desc.Name == 0) break;     /* terminator */
        char dll_name[64] = {0};
        read_asciiz(hProcess, (UCHAR*)image_base + desc.Name, dll_name, sizeof(dll_name));
        if (_stricmp(dll_name, "USER32.dll") == 0 ||
            _stricmp(dll_name, "USER32.DLL") == 0) {
            user32_iat = (UCHAR*)image_base + desc.FirstThunk;          /* IAT */
            user32_int = (UCHAR*)image_base + desc.OriginalFirstThunk;  /* name table */
            fwprintf(stderr, L"  found %hs: IAT=%p INT=%p\n",
                     dll_name, user32_iat, user32_int);
            found_user32 = 1;
            break;
        }
    }
    if (!found_user32) {
        fwprintf(stderr, L"  USER32.dll not in imports\n"); goto cleanup;
    }

    /* --------- locate MessageBoxW slot via INT ---------------------- */
    PVOID iat_slot = NULL;
    for (DWORD i = 0; ; ++i) {
        ULONGLONG int_entry = 0;
        readmem(hProcess, (ULONGLONG*)user32_int + i, &int_entry, sizeof(int_entry));
        if (int_entry == 0) break;
        if (int_entry & IMAGE_ORDINAL_FLAG64) continue;  /* by ordinal, no name */
        /* Name table entry points at IMAGE_IMPORT_BY_NAME (WORD Hint + string). */
        PVOID name_addr = (UCHAR*)image_base + (DWORD)(int_entry & 0x7FFFFFFF) + 2 /*skip Hint*/;
        char name[64] = {0};
        read_asciiz(hProcess, name_addr, name, sizeof(name));
        if (strcmp(name, "MessageBoxW") == 0) {
            iat_slot = (ULONGLONG*)user32_iat + i;
            fwprintf(stderr, L"  MessageBoxW IAT slot at %p (import #%lu)\n",
                     iat_slot, i);
            break;
        }
    }
    if (!iat_slot) {
        fwprintf(stderr, L"  MessageBoxW not found in INT\n"); goto cleanup;
    }

    /* --------- read current IAT value for verification -------------- */
    ULONGLONG orig_target = 0;
    readmem(hProcess, iat_slot, &orig_target, sizeof(orig_target));
    fwprintf(stderr, L"  IAT slot currently points at %llX  (loader hadn't bound yet)\n",
             (unsigned long long)orig_target);

    /* --------- allocate stub page, write shellcode ------------------ */
    SIZE_T page_sz = 4096;
    status = NtAllocateVirtualMemory(hProcess, &remote_stub, 0, &page_sz,
                                     MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    Cps_PrintStatus("NtAllocateVirtualMemory(stub page)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    status = writemem(hProcess, remote_stub, g_stub, sizeof(g_stub));
    Cps_PrintStatus("write stub bytes", status);

    /* Flip stub page to RX. */
    {
        SIZE_T sz = sizeof(g_stub);
        ULONG old = 0;
        PVOID base = remote_stub;
        SIZE_T region = sz;
        status = NtProtectVirtualMemory(hProcess, &base, &region,
                                        PAGE_EXECUTE_READ, &old);
        Cps_PrintStatus("NtProtectVirtualMemory(stub -> RX)", status);
    }

    /* --------- flip IAT slot to RW, write, flip back ---------------- */
    {
        SIZE_T region = sizeof(ULONGLONG);
        ULONG old = 0;
        PVOID base = iat_slot;
        status = NtProtectVirtualMemory(hProcess, &base, &region,
                                        PAGE_READWRITE, &old);
        Cps_PrintStatus("NtProtectVirtualMemory(IAT -> RW)", status);

        ULONGLONG new_target = (ULONGLONG)remote_stub;
        status = writemem(hProcess, iat_slot, &new_target, sizeof(new_target));
        Cps_PrintStatus("write new IAT target", status);

        base = iat_slot; region = sizeof(ULONGLONG);
        status = NtProtectVirtualMemory(hProcess, &base, &region, old, &old);
        Cps_PrintStatus("NtProtectVirtualMemory(IAT restore)", status);
    }

    fwprintf(stderr, L"  patched IAT[MessageBoxW] -> %p (our 6-byte stub)\n",
             remote_stub);

    /* --------- resume and wait -------------------------------------- */
    NtResumeThread(hThread, NULL);
    NtWaitForSingleObject(hProcess, FALSE, NULL);

    PROCESS_BASIC_INFORMATION pbi2 = {0};
    NtQueryInformationProcess(hProcess, ProcessBasicInformation,
                              &pbi2, sizeof(pbi2), NULL);
    fwprintf(stderr, L"  child exit = 0x%08lX\n", (unsigned long)pbi2.ExitStatus);

    /* --------- read marker to confirm patch took effect ------------- */
    HANDLE f = CreateFileW(L"gui_target.marker", GENERIC_READ, FILE_SHARE_READ,
                          NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (f != INVALID_HANDLE_VALUE) {
        char buf[512] = {0};
        DWORD r = 0;
        ReadFile(f, buf, sizeof(buf) - 1, &r, NULL);
        CloseHandle(f);
        fwprintf(stderr, L"  --- gui_target.marker ---\n%hs\n", buf);
        if (strstr(buf, "MessageBoxW returned=1")) {
            fwprintf(stderr, L"  PATCH SUCCEEDED: child got IDOK without UI.\n");
            rc = 0;
        } else {
            fwprintf(stderr, L"  PATCH FAILED: dialog likely shown.\n");
            rc = 2;
        }
    }

cleanup:
    if (hThread)  NtClose(hThread);
    if (hProcess) NtClose(hProcess);
    if (attrs)    HeapFree(GetProcessHeap(), 0, attrs);
    if (params)   RtlDestroyProcessParameters(params);
    if (env)      HeapFree(GetProcessHeap(), 0, env);
    RtlFreeUnicodeString(&nt_image);
    return rc;
}
