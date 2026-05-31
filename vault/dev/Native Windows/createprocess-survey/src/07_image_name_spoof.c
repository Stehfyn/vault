/*
 * 07_image_name_spoof.c — child believes it is running as a different
 * binary than the one the kernel actually mapped.
 *
 * Why CreateProcess cannot do this
 * ---------------------------------
 * CreateProcessW takes a single lpApplicationName. The kernel maps that
 * file as the image AND copies the name into PEB->ProcessParameters->
 * ImagePathName. The two are inextricably bound — there is no API
 * surface that lets you ask the kernel to map A while telling user mode
 * "you are B".
 *
 * NtCreateUserProcess separates these:
 *   - PsAttributeImageName     -> what the kernel maps (REAL image)
 *   - params->ImagePathName    -> what the PEB reports to user code
 *   - params->CommandLine      -> what GetCommandLineW returns
 *
 * The loader-database entry (PEB->Ldr->InMemoryOrderModuleList) is
 * populated from the actual loaded image, so GetModuleFileNameW(NULL)
 * still returns the REAL path. This asymmetry is the basis for both
 * a) sandbox cheats ("I'm pretending to be Notepad") and
 * b) defensive detection ("PEB says X, loader says Y -> spoof").
 *
 * This sample uses test_target.exe as the real image and claims to be
 * \??\C:\Windows\System32\notepad.exe in the PEB. The marker the child
 * writes will show BOTH views.
 */

#include "common.h"

#define ATTR_COUNT 5

int wmain(void)
{
    NTSTATUS status;
    int rc = 1;
    PRTL_USER_PROCESS_PARAMETERS params = NULL;
    HANDLE hProcess = NULL, hThread = NULL;
    PPS_ATTRIBUTE_LIST attrs = NULL;
    PVOID env = NULL;

    /* --------- the REAL image (what the kernel will map) ----------- */
    WCHAR dos_real[MAX_PATH];
    GetModuleFileNameW(NULL, dos_real, MAX_PATH);
    PWSTR slash = wcsrchr(dos_real, L'\\');
    wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - dos_real), L"test_target.exe");
    UNICODE_STRING nt_real;
    status = Cps_DosToNtPath(dos_real, &nt_real);
    Cps_PrintStatus("RtlDosPathNameToNtPathName(real)", status);
    if (!NT_SUCCESS(status)) return 1;

    /* --------- the LIE (what the PEB will say) --------------------- */
    /* We pick an image that exists so that consumers which try to
     * RtlDosPathNameToNtPathName the spoofed name won't fail. */
    UNICODE_STRING nt_fake;
    status = Cps_DosToNtPath(L"C:\\Windows\\System32\\notepad.exe", &nt_fake);
    Cps_PrintStatus("RtlDosPathNameToNtPathName(spoof)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    fwprintf(stderr, L"[07] real image  = %ls\n", dos_real);
    fwprintf(stderr, L"[07] PEB will say = C:\\Windows\\System32\\notepad.exe\n");

    /* --------- spoofed command line -------------------------------- */
    UNICODE_STRING cmdline;
    Cps_InitUnicodeString(&cmdline,
        L"\"C:\\Windows\\System32\\notepad.exe\" untitled.txt /spoofed");

    /* --------- env (we still need CPS_TARGET_TAG for the marker) --- */
    PCWSTR env_entries[] = {
        L"CPS_TARGET_TAG=07_image_name_spoof",
        L"PATH=C:\\Windows\\System32;C:\\Windows",
        L"SystemRoot=C:\\Windows",
        L"TEMP=C:\\Windows\\Temp",
        L"TMP=C:\\Windows\\Temp",
    };
    env = Cps_BuildEnvBlock(env_entries, _countof(env_entries));

    /* Critically: ImagePathName in the params is the FAKE one. */
    status = Cps_MakeParams(&nt_fake, &cmdline, env, &params);
    Cps_PrintStatus("RtlCreateProcessParametersEx(spoofed name in params)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    params->StandardInput  = GetStdHandle(STD_INPUT_HANDLE);
    params->StandardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    params->StandardError  = GetStdHandle(STD_ERROR_HANDLE);

    /* --------- attribute list: ImageName attribute carries REAL ---- */
    SIZE_T list_bytes = sizeof(SIZE_T) + ATTR_COUNT * sizeof(PS_ATTRIBUTE);
    attrs = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, list_bytes);
    if (!attrs) goto cleanup;
    attrs->TotalLength = list_bytes;

    CLIENT_ID cid = {0};
    SECTION_IMAGE_INFORMATION sii = {0};
    PTEB teb = NULL;

    attrs->Attributes[0].Attribute = PS_ATTRIBUTE_IMAGE_NAME;
    attrs->Attributes[0].Size      = nt_real.Length;   /* <- REAL image */
    attrs->Attributes[0].ValuePtr  = nt_real.Buffer;
    attrs->Attributes[1].Attribute = PS_ATTRIBUTE_PARENT_PROCESS;
    attrs->Attributes[1].Size      = sizeof(HANDLE);
    attrs->Attributes[1].Value     = (ULONG_PTR)NtCurrentProcess();
    attrs->Attributes[2].Attribute = PS_ATTRIBUTE_CLIENT_ID;
    attrs->Attributes[2].Size      = sizeof(cid);
    attrs->Attributes[2].ValuePtr  = &cid;
    attrs->Attributes[3].Attribute = PS_ATTRIBUTE_IMAGE_INFO;
    attrs->Attributes[3].Size      = sizeof(sii);
    attrs->Attributes[3].ValuePtr  = &sii;
    attrs->Attributes[4].Attribute = PS_ATTRIBUTE_TEB_ADDRESS;
    attrs->Attributes[4].Size      = sizeof(teb);
    attrs->Attributes[4].ValuePtr  = &teb;

    PS_CREATE_INFO ci = {0};
    ci.Size  = sizeof(ci);
    ci.State = PsCreateInitialState;

    status = NtCreateUserProcess(
        &hProcess, &hThread,
        PROCESS_ALL_ACCESS, THREAD_ALL_ACCESS,
        NULL, NULL,
        PROCESS_CREATE_FLAGS_INHERIT_HANDLES,
        THREAD_CREATE_FLAGS_CREATE_SUSPENDED,
        params, &ci, attrs);
    Cps_PrintStatus("NtCreateUserProcess", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    fwprintf(stderr,
        L"  spawned: pid=%llu, image_base=%p (this is the REAL test_target.exe)\n",
        (unsigned long long)(ULONG_PTR)cid.UniqueProcess,
        sii.TransferAddress);

    ULONG prev = 0;
    NtResumeThread(hThread, &prev);
    NtWaitForSingleObject(hProcess, FALSE, NULL);

    PROCESS_BASIC_INFORMATION pbi = {0};
    NtQueryInformationProcess(hProcess, ProcessBasicInformation,
                              &pbi, sizeof(pbi), NULL);
    fwprintf(stderr, L"  child exit = 0x%08lX\n", (unsigned long)pbi.ExitStatus);
    fwprintf(stderr, L"  Check 07_image_name_spoof.marker for both views.\n");

    rc = (pbi.ExitStatus == EXPECTED_CHILD_EXIT) ? 0 : 2;

cleanup:
    if (hThread)  NtClose(hThread);
    if (hProcess) NtClose(hProcess);
    if (attrs)    HeapFree(GetProcessHeap(), 0, attrs);
    if (params)   RtlDestroyProcessParameters(params);
    if (env)      HeapFree(GetProcessHeap(), 0, env);
    RtlFreeUnicodeString(&nt_fake);
    RtlFreeUnicodeString(&nt_real);
    return rc;
}
