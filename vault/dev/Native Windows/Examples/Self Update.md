```C
void DoUpdate()
{
    WCHAR FileName[MAX_PATH];
    ULONG cch = RTL_NUMBER_OF(FileName);
    if (QueryFullProcessImageNameW(GetCurrentProcess(), 0, FileName, &cch))
    {
        if (PWSTR pc = wcsrchr(FileName, '\\'))
        {
            ULONG cb = (ULONG)((ULONG_PTR)++pc - (ULONG_PTR)FileName);
            PWSTR NewFileName = (PWSTR)alloca(cb + 2 * sizeof(WCHAR));
            memcpy((PBYTE)memcpy(NewFileName, FileName, cb) + cb, L"~", 2 * sizeof(WCHAR));
 
            // simulate update
            if (CopyFileW(FileName, NewFileName, FALSE))
            {
                STARTUPINFOEX si = { { sizeof(si) } };
 
                SIZE_T ecb = 0, rcb = 16;
                static volatile UCHAR guz = 0;
                PVOID stack = alloca(guz);
                ULONG dwError;
                do 
                {
                    if (ecb < rcb)
                    {
                        ecb = RtlPointerToOffset(si.lpAttributeList = 
                            (PPROC_THREAD_ATTRIBUTE_LIST)alloca(rcb - ecb), stack);
                    }
 
                    dwError = BOOL_TO_ERROR(InitializeProcThreadAttributeList(si.lpAttributeList, 1, 0, &(rcb = ecb)));
 
                } while (dwError == ERROR_INSUFFICIENT_BUFFER);
 
                if (dwError == NOERROR)
                {
                    if (HANDLE hProcess = OpenProcess(SYNCHRONIZE, TRUE, GetCurrentProcessId()))
                    {
                        if (UpdateProcThreadAttribute(si.lpAttributeList, 0, 
                            PROC_THREAD_ATTRIBUTE_HANDLE_LIST, &hProcess, sizeof(hProcess), 0, 0))
                        {
                            PROCESS_INFORMATION pi;
 
                            PCWSTR lpCommandLine = GetCommandLineW();
                            cb = (ULONG)wcslen(lpCommandLine) * sizeof(WCHAR);
                            cch = cb + ((ULONG)wcslen(pc)+ 28)* sizeof(WCHAR);
                            PWSTR lpNewCommandLine = (PWSTR)alloca(cch);
                            ULONG crc = RtlComputeCrc32(0, lpCommandLine, cb);
                            swprintf_s(lpNewCommandLine, cch/sizeof(WCHAR), L"%s<%x*%p>%s", lpCommandLine, crc, hProcess, pc);
 
                            if (CreateProcessW(NewFileName, lpNewCommandLine, 0, 0, TRUE, 0, 0, 0, &si.StartupInfo, &pi))
                            {
                                CloseHandle(pi.hThread);
                                CloseHandle(pi.hProcess);
                            }
                        }
 
                        CloseHandle(hProcess);
                    }
                }
            }
        }
    }
}
 
void CheckUpdating()
{
    PCWSTR lpCommandLine = GetCommandLineW();
 
    if (PWSTR pc = wcschr(lpCommandLine, '<'))
    {
        HANDLE hProcess;
        ULONG crc = RtlComputeCrc32(0, lpCommandLine, (ULONG)((ULONG_PTR)pc - (ULONG_PTR)lpCommandLine));
 
        PWSTR pz = pc;
        if (crc == wcstoul(pc + 1, &pc, 16) && *pc == '*' && 
            (hProcess = (HANDLE)_wcstoui64(pc + 1, &pc, 16)) && *pc == '>')
        {
            *pz = 0, pc++;// restore cmdline to original
 
            ULONG r = WaitForSingleObject(hProcess, INFINITE);
 
            CloseHandle(hProcess);
 
            if (r == WAIT_OBJECT_0)
            {
                WCHAR FileName[MAX_PATH];
                ULONG cch = RTL_NUMBER_OF(FileName);
                if (QueryFullProcessImageNameW(GetCurrentProcess(), 0, FileName, &cch))
                {
                    HANDLE hFile = CreateFileW(FileName, DELETE, FILE_SHARE_DELETE, 0, OPEN_EXISTING, 0, 0);
 
                    if (hFile != INVALID_HANDLE_VALUE)
                    {
                        ULONG FileNameLength = (ULONG)wcslen(pc) * sizeof(WCHAR);
                        ULONG cb = sizeof(FILE_RENAME_INFORMATION) + FileNameLength;
                        PFILE_RENAME_INFORMATION fri = (PFILE_RENAME_INFORMATION)alloca(cb);
                        fri->ReplaceIfExists = TRUE;
                        fri->RootDirectory = 0;
                        fri->FileNameLength = FileNameLength;
                        memcpy(fri->FileName, pc, FileNameLength);
                        IO_STATUS_BLOCK iosb;
 
                        if (NTSTATUS status = NtSetInformationFile(hFile, &iosb, fri, cb, FileRenameInformation)) 
                        {
                            DbgPrint("Rename=%x\n", status);
                        }
 
                        CloseHandle(hFile);
                    }
                }
            }
        }
    }
}
 
void WINAPI Ep(void*)
{
    MessageBoxW(0, 0, L"Starting..", MB_OK|MB_ICONINFORMATION);
    
    CheckUpdating();
 
    if (MessageBoxW(0, 0, L"Simulate Update ?", MB_YESNO|MB_ICONQUESTION) == IDYES)
    {
        DoUpdate();
    }
 
    MessageBoxW(0, 0, L"Exiting..", MB_OK|MB_ICONINFORMATION);
    
    ExitProcess(0);
}
```
