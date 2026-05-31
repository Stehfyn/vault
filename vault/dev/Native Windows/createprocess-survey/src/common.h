// common.h — shared helpers across every native-process-creation example.

#ifndef COMMON_H
#define COMMON_H

#define PHNT_VERSION PHNT_WINDOWS_11_24H2

#include <phnt_windows.h>
#include <phnt.h>

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define EXPECTED_CHILD_EXIT 0x4D  /* must match test_target.c */

/* ---------- NT path / Unicode-string helpers ------------------------------ */

static inline VOID Cps_InitUnicodeString(PUNICODE_STRING us, PCWSTR src)
{
    if (src == NULL) {
        us->Buffer = NULL;
        us->Length = us->MaximumLength = 0;
        return;
    }
    SIZE_T n = wcslen(src);
    us->Buffer = (PWSTR)src;
    us->Length = (USHORT)(n * sizeof(WCHAR));
    us->MaximumLength = (USHORT)((n + 1) * sizeof(WCHAR));
}

/* Resolve a DOS path (e.g. "C:\\dir\\file.exe") to an NT path
 * (\??\C:\dir\file.exe) in a freshly-allocated UNICODE_STRING.
 * Caller frees with RtlFreeUnicodeString. */
static inline NTSTATUS Cps_DosToNtPath(PCWSTR DosPath, PUNICODE_STRING NtPath)
{
    return RtlDosPathNameToNtPathName_U_WithStatus(DosPath, NtPath, NULL, NULL);
}

/* ---------- Status reporting --------------------------------------------- */

static inline void Cps_PrintStatus(const char *what, NTSTATUS s)
{
    fprintf(stderr, "  %-40s : 0x%08lX %s\n",
            what, (unsigned long)s,
            NT_SUCCESS(s) ? "(NT_SUCCESS)" : "(FAILED)");
}

#define CPS_CHECK(call) do {                                  \
    NTSTATUS _s = (call);                                     \
    Cps_PrintStatus(#call, _s);                               \
    if (!NT_SUCCESS(_s)) return (int)_s;                      \
} while (0)

/* ---------- Environment block builder ------------------------------------ */
/* Build a UNICODE-environment block of the form  KEY=VAL\0KEY=VAL\0\0.
 * Returns a heap block the caller frees with HeapFree(GetProcessHeap(),...). */
static inline PVOID Cps_BuildEnvBlock(PCWSTR const *entries, SIZE_T count)
{
    SIZE_T total_chars = 1; /* trailing extra L'\0' */
    for (SIZE_T i = 0; i < count; ++i)
        total_chars += wcslen(entries[i]) + 1;

    SIZE_T bytes = total_chars * sizeof(WCHAR);
    PWSTR p = (PWSTR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, bytes);
    if (!p) return NULL;

    PWSTR w = p;
    for (SIZE_T i = 0; i < count; ++i) {
        SIZE_T n = wcslen(entries[i]);
        wmemcpy(w, entries[i], n);
        w += n + 1; /* skip the embedded \0 the HEAP_ZERO_MEMORY already placed */
    }
    return p;
}

/* ---------- Process-parameter convenience -------------------------------- */
/* Build a RTL_USER_PROCESS_PARAMETERS with sane defaults: WindowTitle and
 * DesktopInfo inherited from current process via the PEB, current-directory
 * = caller cwd, env = optional. */
static inline NTSTATUS Cps_MakeParams(
    PCUNICODE_STRING NtImagePath,   /* in: \??\C:\... form */
    PCUNICODE_STRING DosCommandLine,/* in: full DOS-style command line */
    PVOID Environment,              /* in opt: env block, NULL = inherit */
    PRTL_USER_PROCESS_PARAMETERS *OutParams)
{
    UNICODE_STRING current_dir = {0};
    /* RtlGetCurrentDirectory_U gives the DOS-style cwd; we feed that back. */
    {
        WCHAR cwd[MAX_PATH];
        DWORD cn = GetCurrentDirectoryW(MAX_PATH, cwd);
        if (cn == 0 || cn >= MAX_PATH) return STATUS_BUFFER_TOO_SMALL;
        Cps_InitUnicodeString(&current_dir, cwd);
        /* Note: Buffer points into a stack buffer, but RtlCreateProcessParametersEx
         * copies all strings into the params block, so this is safe. */
        return RtlCreateProcessParametersEx(
            OutParams,
            NtImagePath,
            NULL,                /* DllPath — let loader pick up from registry */
            &current_dir,
            DosCommandLine,
            Environment,
            NULL,                /* WindowTitle */
            NULL,                /* DesktopInfo */
            NULL,                /* ShellInfo */
            NULL,                /* RuntimeData */
            RTL_USER_PROC_PARAMS_NORMALIZED);
    }
}

/* Bundle of optional/extra params we use to drive the exhaustive examples. */
typedef struct _CPS_EXTRAS {
    PCWSTR  DllPath;                /* params->DllPath */
    PCWSTR  WindowTitle;            /* params->WindowTitle */
    PCWSTR  DesktopInfo;            /* params->DesktopInfo */
    PCWSTR  ShellInfo;              /* params->ShellInfo */
    PCWSTR  RuntimeData;            /* params->RuntimeData */
    /* These get poked into params *after* RtlCreate, since the Rtl
     * builder ignores them. */
    ULONG   StartingX, StartingY;
    ULONG   CountX, CountY;
    ULONG   CountCharsX, CountCharsY;
    ULONG   FillAttribute;
    ULONG   WindowFlags;            /* STARTUPINFO.dwFlags equivalent */
    ULONG   ShowWindowFlags;        /* STARTUPINFO.wShowWindow equivalent */
    ULONG   ConsoleFlags;           /* params->ConsoleFlags */
    HANDLE  ConsoleHandle;          /* params->ConsoleHandle */
    HANDLE  StdInput, StdOutput, StdError;
} CPS_EXTRAS;

/* Build params with every optional field populated.  All UNICODE_STRING
 * "extras" are taken from the caller-provided wide strings. */
static inline NTSTATUS Cps_MakeParamsFull(
    PCUNICODE_STRING NtImagePath,
    PCUNICODE_STRING DosCommandLine,
    PVOID            Environment,
    const CPS_EXTRAS *Extras,
    PRTL_USER_PROCESS_PARAMETERS *OutParams)
{
    UNICODE_STRING current_dir;
    UNICODE_STRING us_dll, us_title, us_desk, us_shell, us_runtime;
    WCHAR cwd[MAX_PATH];

    DWORD cn = GetCurrentDirectoryW(MAX_PATH, cwd);
    if (cn == 0 || cn >= MAX_PATH) return STATUS_BUFFER_TOO_SMALL;
    Cps_InitUnicodeString(&current_dir, cwd);

    Cps_InitUnicodeString(&us_dll,     Extras->DllPath);
    Cps_InitUnicodeString(&us_title,   Extras->WindowTitle);
    Cps_InitUnicodeString(&us_desk,    Extras->DesktopInfo);
    Cps_InitUnicodeString(&us_shell,   Extras->ShellInfo);
    Cps_InitUnicodeString(&us_runtime, Extras->RuntimeData);

    NTSTATUS s = RtlCreateProcessParametersEx(
        OutParams,
        NtImagePath,
        Extras->DllPath     ? &us_dll     : NULL,
        &current_dir,
        DosCommandLine,
        Environment,
        Extras->WindowTitle ? &us_title   : NULL,
        Extras->DesktopInfo ? &us_desk    : NULL,
        Extras->ShellInfo   ? &us_shell   : NULL,
        Extras->RuntimeData ? &us_runtime : NULL,
        RTL_USER_PROC_PARAMS_NORMALIZED);
    if (!NT_SUCCESS(s)) return s;

    /* Post-poke the numeric / handle fields RtlCreate doesn't accept. */
    PRTL_USER_PROCESS_PARAMETERS p = *OutParams;
    p->StartingX       = Extras->StartingX;
    p->StartingY       = Extras->StartingY;
    p->CountX          = Extras->CountX;
    p->CountY          = Extras->CountY;
    p->CountCharsX     = Extras->CountCharsX;
    p->CountCharsY     = Extras->CountCharsY;
    p->FillAttribute   = Extras->FillAttribute;
    p->WindowFlags     = Extras->WindowFlags;
    p->ShowWindowFlags = Extras->ShowWindowFlags;
    p->ConsoleFlags    = Extras->ConsoleFlags;
    p->ConsoleHandle   = Extras->ConsoleHandle;
    if (Extras->StdInput)  p->StandardInput  = Extras->StdInput;
    if (Extras->StdOutput) p->StandardOutput = Extras->StdOutput;
    if (Extras->StdError)  p->StandardError  = Extras->StdError;

    /* Post-19H1 fields not exposed through RtlCreateProcessParametersEx.
     * Setting these tests whether anything downstream honors them. */
    p->ProcessGroupId               = 0xC0FFEE;
    p->DefaultThreadpoolThreadMaximum = 7;
    p->HeapMemoryTypeMask           = 0;          /* keep default */
    return s;
}

/* Sentinels we use across every example so the marker file is comparable. */
#define CPS_X            0x11
#define CPS_Y            0x22
#define CPS_XSIZE        0x33
#define CPS_YSIZE        0x44
#define CPS_XCHARS       0x55
#define CPS_YCHARS       0x66
#define CPS_FILLATTR     0x77

/* WindowFlags bits — these are the STARTF_* values from winbase.h. */
#define CPS_WINDOWFLAGS (STARTF_USESHOWWINDOW | STARTF_USESIZE | \
                        STARTF_USEPOSITION  | STARTF_USECOUNTCHARS | \
                        STARTF_USEFILLATTRIBUTE | STARTF_USESTDHANDLES)

#define CPS_SHOWFLAGS    SW_SHOWNORMAL

static inline void Cps_FillExtras(CPS_EXTRAS *e, PCWSTR tag)
{
    static WCHAR title  [128];
    static WCHAR desktop[128];
    static WCHAR shell  [128];
    static WCHAR runtime[128];

    /* Each tag gets its own buffers (we only call once per process, ok). */
    swprintf_s(title,   128, L"cps:%s:title",   tag);
    swprintf_s(desktop, 128, L"WinSta0\\Default");  /* must be a real desktop */
    swprintf_s(shell,   128, L"cps:%s:shell",   tag);
    swprintf_s(runtime, 128, L"cps:%s:runtime", tag);

    e->DllPath         = L"C:\\Windows\\System32";
    e->WindowTitle     = title;
    e->DesktopInfo     = desktop;
    e->ShellInfo       = shell;
    /* RuntimeData == STARTUPINFO.lpReserved2. The MSVC CRT consumes it
     * during DLL_PROCESS_ATTACH as a binary fd-inheritance blob (count
     * followed by per-fd flags/OSHandle pairs). An exhaustive parent
     * cannot pass *arbitrary* wide text here — it crashes the child
     * with STATUS_STACK_BUFFER_OVERRUN (/GS) before main() runs.
     * Confirmed by bisecting Cps_FillExtras. Either leave NULL or
     * construct the exact CRT format. We leave NULL. */
    e->RuntimeData     = NULL;
    (void)runtime;
    e->StartingX       = CPS_X;
    e->StartingY       = CPS_Y;
    e->CountX          = CPS_XSIZE;
    e->CountY          = CPS_YSIZE;
    e->CountCharsX     = CPS_XCHARS;
    e->CountCharsY     = CPS_YCHARS;
    e->FillAttribute   = CPS_FILLATTR;
    e->WindowFlags     = CPS_WINDOWFLAGS;
    e->ShowWindowFlags = CPS_SHOWFLAGS;
    e->ConsoleFlags    = 0;
    e->ConsoleHandle   = NULL;
    e->StdInput        = GetStdHandle(STD_INPUT_HANDLE);
    e->StdOutput       = GetStdHandle(STD_OUTPUT_HANDLE);
    e->StdError        = GetStdHandle(STD_ERROR_HANDLE);
}

#endif /* COMMON_H */
