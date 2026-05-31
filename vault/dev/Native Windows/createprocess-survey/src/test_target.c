// test_target.exe — the child every parent launches.
//
// Reads its own PEB->ProcessParameters and dumps every interesting field
// into <CPS_TARGET_TAG>.marker as key=value lines. Exit code = 0x4D.
//
// The point: each native parent claims to plumb dozens of fields through
// to us; this file is the audit log proving (or disproving) each one
// round-trips.

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winternl.h>
#include <stdio.h>
#include <wchar.h>

/* Minimal layout that mirrors RTL_USER_PROCESS_PARAMETERS for the fields
 * we care about. winternl.h's RTL_USER_PROCESS_PARAMETERS is truncated;
 * use NtCurrentTeb() to pull our own PEB and rely on the kernel's layout. */

typedef struct _CPS_UNICODE_STRING { USHORT Length, MaximumLength; PWSTR Buffer; } CPS_USTR;
typedef struct _CPS_CURDIR { CPS_USTR DosPath; HANDLE Handle; } CPS_CURDIR;

typedef struct _CPS_PROCESS_PARAMETERS {
    ULONG  MaximumLength;
    ULONG  Length;
    ULONG  Flags;
    ULONG  DebugFlags;
    HANDLE ConsoleHandle;
    ULONG  ConsoleFlags;
    HANDLE StandardInput;
    HANDLE StandardOutput;
    HANDLE StandardError;
    CPS_CURDIR CurrentDirectory;
    CPS_USTR DllPath;
    CPS_USTR ImagePathName;
    CPS_USTR CommandLine;
    PVOID    Environment;
    ULONG    StartingX;
    ULONG    StartingY;
    ULONG    CountX;
    ULONG    CountY;
    ULONG    CountCharsX;
    ULONG    CountCharsY;
    ULONG    FillAttribute;
    ULONG    WindowFlags;
    ULONG    ShowWindowFlags;
    CPS_USTR WindowTitle;
    CPS_USTR DesktopInfo;
    CPS_USTR ShellInfo;
    CPS_USTR RuntimeData;
    /* RTL_DRIVE_LETTER_CURDIR[32]: each is 24 bytes (USHORT, USHORT,
     * ULONG, ANSI_STRING with 4 bytes pad) -> 32 * 24 = 768 bytes. */
    UCHAR    CurrentDirectories[32 * 24];
    ULONG_PTR EnvironmentSize;
    ULONG_PTR EnvironmentVersion;
    PVOID    PackageDependencyData;
    ULONG    ProcessGroupId;
    ULONG    LoaderThreads;
    CPS_USTR RedirectionDllName;
    CPS_USTR HeapPartitionName;
    PULONGLONG DefaultThreadpoolCpuSetMasks;
    ULONG    DefaultThreadpoolCpuSetMaskCount;
    ULONG    DefaultThreadpoolThreadMaximum;
    ULONG    HeapMemoryTypeMask;
} CPS_PARAMS;

typedef NTSTATUS (NTAPI *PFN_NtQueryInformationProcess)(HANDLE, ULONG, PVOID, ULONG, PULONG);

static DWORD GetParentPid(void)
{
    HMODULE nt = GetModuleHandleW(L"ntdll.dll");
    if (!nt) return 0;
    PFN_NtQueryInformationProcess pNtQ =
        (PFN_NtQueryInformationProcess)GetProcAddress(nt, "NtQueryInformationProcess");
    if (!pNtQ) return 0;
    PROCESS_BASIC_INFORMATION pbi = {0};
    ULONG ret = 0;
    if (pNtQ(GetCurrentProcess(), 0, &pbi, sizeof(pbi), &ret) < 0) return 0;
    return (DWORD)(ULONG_PTR)pbi.Reserved3;
}

static void put_ustr(FILE *f, const char *key, const CPS_USTR *u)
{
    if (u->Length == 0 || u->Buffer == NULL) {
        fprintf(f, "%s=(empty)\n", key);
        return;
    }
    fprintf(f, "%s=%.*ls\n", key, u->Length / 2, u->Buffer);
}

int wmain(int argc, wchar_t **argv)
{
    wchar_t tag[256] = L"untagged";
    DWORD got = GetEnvironmentVariableW(L"CPS_TARGET_TAG", tag, 256);
    if (got == 0 || got >= 256) wcscpy_s(tag, 256, L"untagged");

    wchar_t marker[MAX_PATH];
    swprintf_s(marker, MAX_PATH, L"%s.marker", tag);

    FILE *f = NULL;
    if (_wfopen_s(&f, marker, L"w") != 0 || f == NULL) return 0x10;

    /* Top-of-file canary so the test runner can do a prefix check. */
    fprintf(f, "%ls\n", tag);

    /* Reach the PEB. */
#ifdef _WIN64
    PVOID peb = (PVOID)__readgsqword(0x60);
#else
    PVOID peb = (PVOID)__readfsdword(0x30);
#endif
    /* PEB->ProcessParameters lives at +0x20 on x64, +0x10 on x86. */
    CPS_PARAMS *p = *(CPS_PARAMS **)((char *)peb + (sizeof(void*) == 8 ? 0x20 : 0x10));
    if (!p) {
        fprintf(f, "ERROR: PEB->ProcessParameters is NULL\n");
        fclose(f);
        return 0x11;
    }

    /* ----- basic identity ----- */
    fprintf(f, "pid=%lu\n",        GetCurrentProcessId());
    fprintf(f, "argc=%d\n",        argc);
    fprintf(f, "argv0=%ls\n",      argc ? argv[0] : L"(null)");
    fprintf(f, "parent_pid=%lu\n", GetParentPid());

    /* ----- params block layout ----- */
    fprintf(f, "params.MaximumLength=%lu\n", p->MaximumLength);
    fprintf(f, "params.Length=%lu\n",        p->Length);
    fprintf(f, "params.Flags=0x%08lX\n",     p->Flags);
    fprintf(f, "params.DebugFlags=0x%08lX\n", p->DebugFlags);

    /* ----- console + standard handles ----- */
    fprintf(f, "ConsoleHandle=%p\n",  p->ConsoleHandle);
    fprintf(f, "ConsoleFlags=0x%08lX\n", p->ConsoleFlags);
    fprintf(f, "StandardInput=%p\n",  p->StandardInput);
    fprintf(f, "StandardOutput=%p\n", p->StandardOutput);
    fprintf(f, "StandardError=%p\n",  p->StandardError);

    /* ----- strings ----- */
    fprintf(f, "CurrentDirectory.DosPath=%.*ls\n",
            p->CurrentDirectory.DosPath.Length / 2,
            p->CurrentDirectory.DosPath.Buffer);
    put_ustr(f, "DllPath",       &p->DllPath);
    put_ustr(f, "ImagePathName", &p->ImagePathName);  /* spoofable */
    put_ustr(f, "CommandLine",   &p->CommandLine);    /* spoofable */
    /* Loader's view. On modern Windows the loader copies its main-module
     * FullDllName from PEB->ProcessParameters->ImagePathName, so this
     * field follows the spoof too. Listed for completeness. */
    WCHAR loader_path[MAX_PATH] = {0};
    DWORD lp = GetModuleFileNameW(NULL, loader_path, MAX_PATH);
    fprintf(f, "Loader.GetModuleFileNameW=%.*ls\n", (int)lp, loader_path);
    fprintf(f, "Loader.GetModuleHandleW(NULL)=%p\n", GetModuleHandleW(NULL));

    /* Kernel's view: NtQueryInformationProcess(ProcessImageFileName).
     * The kernel returns the actual section-backing file path from
     * EPROCESS->SectionObject — this CANNOT be spoofed from user mode.
     * Diff against ImagePathName above to detect image-name spoofing. */
    HMODULE nt = GetModuleHandleW(L"ntdll.dll");
    typedef NTSTATUS (NTAPI *PFN_NtQueryInformationProcess)(HANDLE, ULONG, PVOID, ULONG, PULONG);
    PFN_NtQueryInformationProcess pNtQ =
        (PFN_NtQueryInformationProcess)GetProcAddress(nt, "NtQueryInformationProcess");
    if (pNtQ) {
        BYTE buf[512] = {0};
        ULONG ret = 0;
        /* ProcessImageFileName = 27. Returns UNICODE_STRING whose
         * Buffer follows the struct in the same allocation. */
        NTSTATUS s = pNtQ(GetCurrentProcess(), 27, buf, sizeof(buf), &ret);
        if (s == 0) {
            UNICODE_STRING *us = (UNICODE_STRING*)buf;
            fprintf(f, "Kernel.ProcessImageFileName=%.*ls\n",
                    us->Length / 2, us->Buffer);
        } else {
            fprintf(f, "Kernel.ProcessImageFileName=<err 0x%08lX>\n", (unsigned long)s);
        }
        /* ProcessImageFileNameWin32 = 43 — Win32 form with drive letter. */
        memset(buf, 0, sizeof(buf));
        s = pNtQ(GetCurrentProcess(), 43, buf, sizeof(buf), &ret);
        if (s == 0) {
            UNICODE_STRING *us = (UNICODE_STRING*)buf;
            fprintf(f, "Kernel.ProcessImageFileNameWin32=%.*ls\n",
                    us->Length / 2, us->Buffer);
        }
    }
    put_ustr(f, "WindowTitle",   &p->WindowTitle);
    put_ustr(f, "DesktopInfo",   &p->DesktopInfo);
    put_ustr(f, "ShellInfo",     &p->ShellInfo);
    put_ustr(f, "RuntimeData",   &p->RuntimeData);

    /* ----- STARTUPINFO mirrors ----- */
    fprintf(f, "StartingX=%lu\n",       p->StartingX);
    fprintf(f, "StartingY=%lu\n",       p->StartingY);
    fprintf(f, "CountX=%lu\n",          p->CountX);
    fprintf(f, "CountY=%lu\n",          p->CountY);
    fprintf(f, "CountCharsX=%lu\n",     p->CountCharsX);
    fprintf(f, "CountCharsY=%lu\n",     p->CountCharsY);
    fprintf(f, "FillAttribute=0x%08lX\n", p->FillAttribute);
    fprintf(f, "WindowFlags=0x%08lX\n",   p->WindowFlags);  /* a.k.a. STARTUPINFO.dwFlags */
    fprintf(f, "ShowWindowFlags=0x%lX\n", p->ShowWindowFlags); /* a.k.a. wShowWindow */

    /* ----- Win32 view, for comparison ----- */
    STARTUPINFOW si = {0};
    GetStartupInfoW(&si);
    fprintf(f, "Win32.dwFlags=0x%08lX\n",         si.dwFlags);
    fprintf(f, "Win32.dwX=%lu Win32.dwY=%lu\n",   si.dwX, si.dwY);
    fprintf(f, "Win32.dwXSize=%lu Win32.dwYSize=%lu\n", si.dwXSize, si.dwYSize);
    fprintf(f, "Win32.dwXCountChars=%lu dwYCountChars=%lu\n",
            si.dwXCountChars, si.dwYCountChars);
    fprintf(f, "Win32.dwFillAttribute=0x%08lX\n", si.dwFillAttribute);
    fprintf(f, "Win32.wShowWindow=%u\n",          si.wShowWindow);
    fprintf(f, "Win32.lpTitle=%ls\n",   si.lpTitle   ? si.lpTitle   : L"(null)");
    fprintf(f, "Win32.lpDesktop=%ls\n", si.lpDesktop ? si.lpDesktop : L"(null)");
    fprintf(f, "Win32.hStdInput=%p hStdOutput=%p hStdError=%p\n",
            si.hStdInput, si.hStdOutput, si.hStdError);

    /* ----- post-19H1 fields we post-poked in the parent ----- */
    fprintf(f, "EnvironmentSize=%llu\n",       (unsigned long long)p->EnvironmentSize);
    fprintf(f, "ProcessGroupId=0x%lX\n",        p->ProcessGroupId);
    fprintf(f, "LoaderThreads=%lu\n",           p->LoaderThreads);
    put_ustr(f, "RedirectionDllName", &p->RedirectionDllName);
    put_ustr(f, "HeapPartitionName",  &p->HeapPartitionName);
    fprintf(f, "DefaultThreadpoolCpuSetMaskCount=%lu\n", p->DefaultThreadpoolCpuSetMaskCount);
    fprintf(f, "DefaultThreadpoolThreadMaximum=%lu\n",   p->DefaultThreadpoolThreadMaximum);
    fprintf(f, "HeapMemoryTypeMask=0x%lX\n",    p->HeapMemoryTypeMask);

    /* ----- env var sentinel ----- */
    wchar_t check[256] = L"";
    GetEnvironmentVariableW(L"CPS_TARGET_TAG", check, 256);
    fprintf(f, "env.CPS_TARGET_TAG=%ls\n", check);

    fclose(f);
    fflush(stdout);
    return 0x4D;
}
