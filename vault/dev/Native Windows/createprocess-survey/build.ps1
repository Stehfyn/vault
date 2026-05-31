#requires -Version 5.1
<#
build.ps1 — compile every src\*.c into build\*.exe with MSVC.
Run from project root.   .\build.ps1 [-Clean]
#>
param([switch]$Clean)

$ErrorActionPreference = 'Stop'

$root  = $PSScriptRoot
$src   = Join-Path $root 'src'
$build = Join-Path $root 'build'
$phnt  = Join-Path $root 'vendor\phnt'

if ($Clean -and (Test-Path $build)) {
    Remove-Item -Recurse -Force $build
}
if (-not (Test-Path $build)) { New-Item -ItemType Directory -Path $build | Out-Null }

# Locate vcvars64.bat
$vcvars = 'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat'
if (-not (Test-Path $vcvars)) {
    throw "vcvars64.bat not found at $vcvars"
}

# Compose env-importer wrapper (run vcvars then cl with whatever args we pass).
# We pre-fetch env once and re-use to compile each source.
if (-not $env:CPS_VC_ENV_IMPORTED) {
    Write-Host 'Importing MSVC environment...' -ForegroundColor DarkGray
    # vcvars64.bat shells out to vswhere; make sure it can find it.
    $vswhereDir = 'C:\Program Files (x86)\Microsoft Visual Studio\Installer'
    $oldPath = $env:Path
    if (Test-Path (Join-Path $vswhereDir 'vswhere.exe')) {
        $env:Path = "$vswhereDir;$($env:Path)"
    }
    $envDump = & cmd.exe /c "`"$vcvars`" >nul 2>&1 && set"
    foreach ($line in $envDump) {
        if ($line -match '^(?<k>[^=]+)=(?<v>.*)$') {
            Set-Item "env:$($Matches.k)" $Matches.v
        }
    }
    $env:CPS_VC_ENV_IMPORTED = '1'
}

function Invoke-Cl {
    param(
        [string]$Source,
        [string]$Out,
        [string[]]$ExtraLibs,
        [string[]]$ExtraLink = @(),
        [string[]]$ExtraCl = @(),
        [switch]$NoCRT,
        [switch]$NoDebug)

    $inc  = @(
        "/I`"$phnt`""
    )
    $libs = @(
        'ntdll.lib',
        'kernel32.lib',
        'user32.lib',
        'advapi32.lib'
    ) + $ExtraLibs

    $clOpts = @('/nologo','/W3','/TC','/D_CRT_SECURE_NO_WARNINGS','/DUNICODE','/D_UNICODE')
    if (-not $NoDebug) { $clOpts += '/Zi' }
    $clOpts += $ExtraCl

    $linkOpts = @('/INCREMENTAL:NO') + $ExtraLink
    if (-not $NoDebug) { $linkOpts += '/DEBUG' }

    if ($NoCRT) {
        # No CRT, no GS, no default libs. Caller still passes any libs
        # they actually need via -ExtraLibs (kernel32, user32, ntdll).
        $clOpts += '/GS-'
        $linkOpts += @('/NODEFAULTLIB')
        if ($linkOpts -notcontains '/SUBSYSTEM:CONSOLE' -and
            $linkOpts -notcontains '/SUBSYSTEM:WINDOWS') {
            $linkOpts += '/SUBSYSTEM:CONSOLE'
        }
        # Only zero out the default libs if caller didn't explicitly
        # pass any. tiny_target.exe wants truly nothing.
        if ($ExtraLibs.Count -eq 0) { $libs = @() }
    } else {
        $clOpts += '/MT'
    }

    $args = $clOpts + $inc + @(
        $Source, '/Fe:', $Out, '/link') + $linkOpts + $libs

    Write-Host "  cl $Source -> $(Split-Path -Leaf $Out)" -ForegroundColor DarkCyan
    & cl.exe @args | ForEach-Object {
        if ($_ -match 'error|warning C') { Write-Host "    $_" } else { Write-Host "    $_" -ForegroundColor DarkGray }
    }
    if ($LASTEXITCODE -ne 0) { throw "cl failed for $Source (exit $LASTEXITCODE)" }
}

Push-Location $build
try {
    foreach ($s in Get-ChildItem $src -Filter *.c) {
        $name = [IO.Path]::GetFileNameWithoutExtension($s.Name)
        $out  = Join-Path $build "$name.exe"
        if ($name -eq 'tiny_target') {
            Invoke-Cl -Source $s.FullName -Out $out `
                      -ExtraLink @('/ENTRY:my_entry') `
                      -NoCRT
        } elseif ($name -eq 'gui_target') {
            Invoke-Cl -Source $s.FullName -Out $out `
                      -ExtraLibs @('gdi32.lib') `
                      -ExtraLink @('/SUBSYSTEM:WINDOWS')
        } elseif ($name -eq 'gui_no_cursor') {
            # COM-activated GUI launch: registers as a LocalServer32
            # under HKCU and uses shell DelegateExecute so Explorer
            # double-click routes through rpcss (no kernelbase
            # cursor-arm). Needs ole32 for COM, shell32 for
            # CommandLineToArgvW + SHChangeNotify, advapi32 for
            # the registry helpers. Regular CRT — the NoCRT/custom
            # entry scaffolding from prior revisions was for in-
            # process cursor tricks that didn't beat the launcher.
            Invoke-Cl -Source $s.FullName -Out $out `
                      -ExtraLibs @('ole32.lib','user32.lib','advapi32.lib','kernel32.lib') `
                      -ExtraCl   @('/Os','/Oy','/Oi','/Gy','/Gw','/GL') `
                      -ExtraLink @('/SUBSYSTEM:WINDOWS','/ENTRY:my_entry',
                                   '/MERGE:.rdata=.text',
                                   '/MERGE:.pdata=.text',
                                   '/OPT:REF','/OPT:ICF',
                                   '/LTCG',
                                   '/MANIFEST:NO',
                                   '/FIXED',
                                   '/DYNAMICBASE:NO') `
                      -NoCRT -NoDebug
        } else {
            Invoke-Cl -Source $s.FullName -Out $out -ExtraLibs @()
        }
    }
} finally { Pop-Location }

Write-Host 'Build complete.' -ForegroundColor Green
Get-ChildItem $build -Filter *.exe | Format-Table Name, Length -AutoSize
