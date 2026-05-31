#requires -Version 5.1
<#
runtests.ps1 — drive each survey-NN.exe in turn and assert:
  * the parent returns 0
  * the matching <tag>.marker file is written
  * the marker contains the expected tag
Build first with .\build.ps1.
#>
param([switch]$Verbose)

$ErrorActionPreference = 'Stop'
$root  = $PSScriptRoot
$build = Join-Path $root 'build'
if (-not (Test-Path $build)) { throw 'build/ missing; run .\build.ps1 first.' }

$cases = @(
    @{ Exe = '01_rtl_create_user_process.exe';    Tag = '01_rtl_create_user_process' },
    @{ Exe = '02_rtl_create_user_process_ex.exe'; Tag = '02_rtl_create_user_process_ex' },
    @{ Exe = '03_nt_create_user_process.exe';     Tag = '03_nt_create_user_process' },
    @{ Exe = '04_nt_create_process_ex.exe';       Tag = '04_nt_create_process_ex' }
)

# Wipe any old markers
Get-ChildItem $build -Filter *.marker -ErrorAction SilentlyContinue | Remove-Item

$results = New-Object System.Collections.ArrayList
foreach ($c in $cases) {
    $exe   = Join-Path $build $c.Exe
    $tag   = $c.Tag
    $mark  = Join-Path $build "$tag.marker"
    if (-not (Test-Path $exe)) { throw "missing: $exe" }

    Write-Host "==> $($c.Exe)" -ForegroundColor Cyan
    # cd into build/ first — the child inherits cwd and writes its
    # marker there. cmd.exe wrapper sinks stderr so PowerShell 5.1
    # doesn't wrap each stderr line in an ErrorRecord.
    Push-Location $build
    try {
        if ($Verbose) {
            & cmd.exe /c "`"$exe`""
        } else {
            & cmd.exe /c "`"$exe`" >nul 2>&1"
        }
        $exit = $LASTEXITCODE
    } finally { Pop-Location }

    $passParent = $exit -eq 0
    $markerExists = Test-Path $mark
    $markerOK = $false
    $markerContent = ''
    if ($markerExists) {
        $markerContent = (Get-Content $mark -Raw).Trim()
        $markerOK = $markerContent.StartsWith($tag)
    }

    $verdict = if ($passParent -and $markerOK) { 'PASS' } else { 'FAIL' }
    $color   = if ($verdict -eq 'PASS') { 'Green' } else { 'Red' }
    Write-Host ("    {0}  exit={1}  marker={2}" -f $verdict, $exit, $(if ($markerExists) { 'yes' } else { 'NO' })) -ForegroundColor $color
    if ($markerOK) { Write-Host "    $markerContent" -ForegroundColor DarkGray }

    [void]$results.Add([pscustomobject]@{
        Exe = $c.Exe; Exit = $exit; MarkerExists = $markerExists;
        MarkerOK = $markerOK; Verdict = $verdict; Marker = $markerContent
    })
}

Write-Host ''
$results | Format-Table Exe, Exit, MarkerExists, MarkerOK, Verdict -AutoSize
$failures = @($results | Where-Object Verdict -eq 'FAIL').Count
if ($failures -gt 0) {
    Write-Host "$failures test(s) failed" -ForegroundColor Red
    exit 1
} else {
    Write-Host 'All tests passed.' -ForegroundColor Green
}
