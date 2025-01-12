@echo off
setlocal enabledelayedexpansion
cd "%~dp0"

for /f "usebackq tokens=*" %%a in (`call "%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -prerelease -products * -requires Microsoft.Component.MSBuild -property installationPath`) do (
   set "VSINSTALLPATH=%%a"
)

if not defined VSINSTALLPATH (
   echo No Visual Studio installation detected.
   exit /b 0
)

set out=out
set cflags=/nologo /EHsc /openmp /O2 /Oi /MT /std:c++20 /D _NDEBUG /D UNICODE /D _UNICODE
set libs=Kernel32.lib user32.lib libcmt.lib
set lflags=/CGTHREADS:8

set "buiild_tool=/?"

if exist "%VSINSTALLPATH%\VC\Auxiliary\Build\vcvarsall.bat" (
	rmdir /s /q %out% 2>nul
	mkdir %out%
	pushd %out%
	call :%%buiild_tool%% add_github_compatible_links x64 3>&1 >nul
	popd
)

if "%0" == ":%buiild_tool%" (
	echo Build %1 %2 @call:
	call "%VSINSTALLPATH%\VC\Auxiliary\Build\vcvarsall.bat" %2
	taskkill /f /im %1%2.exe >NUL 2>&1
	rmdir /s /q %2 2>nul
	mkdir %2
	pushd %2
	echo. && echo %2 %1 exe
	cl %cflags% ..\..\%1.cpp %libs% /link /MACHINE:%2 /OUT:%1.exe /SUBSYSTEM:Console
	move %1.exe ..\%1%2.exe
	popd
	rmdir /s /q %2 2>nul
)>&3

exit /b 0