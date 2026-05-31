# vdproj2wix — VS Installer to WiX Converter

`vdproj2wix` converts deprecated Visual Studio Installer `.vdproj` projects into WiX source. The useful part is not perfect translation; it is extracting installer intent from a brittle project format: files, registry values, shortcuts, custom actions, and component-ish groupings.

Treat the output as a migration scaffold. WiX requires explicit component identity, key paths, upgrade codes, sequencing, and ICE-clean table relationships that `.vdproj` often hid or modeled poorly. The converter saves archaeology time; it does not absolve you from rebuilding the MSI component model.

## Source Code Reading

The linked repository is intentionally small: the implementation is `vdproj2wix.ps1`, backed by fixture pairs under `Tests/*/Test.vdproj` and `Tests/*/Expected.wxs`.

`vdproj2wix.ps1` does not parse `.vdproj` as a formal grammar. It line-scans sections and uses regexes for the subset it supports:
- Product metadata: `ProductCode`, `ProductName`, `ProductVersion`, `Manufacturer`, `UpgradeCode`.
- File entries: `SourcePath`, `TargetName`, `Folder`, `Exclude`.
- Folder entries: `DefaultLocation`, `Name`, `Property`, nested `Folders`.

Composition:

```powershell
read Test.vdproj
foreach line:
  toggle Product/File/Folder section state
  capture product fields, files, folders
sort files by leaf name
attach files to folderMap
expand DefaultLocation tokens:
  [ProgramFilesFolder], [Manufacturer], [ProductName]
write .wxs:
  <Product> metadata
  <Package> / <Media>
  recursive <Directory> tree
  one <Component> per folder's file set
  <Feature> with ComponentRef entries
```

The buried caveat is in the implementation: component IDs and folder IDs are generated sequentially (`_1`, `_2`, ...), while GUIDs come from the source folder metadata. That is good enough for migration scaffolding, but not good enough to declare the resulting MSI production-correct. After conversion, inspect component key paths, upgrade rules, 64-bit flags, shortcut targets, services, custom actions, and ICE validation output.

Actionable test loop:
1. Run `PowerShell -File vdproj2wix.ps1 Tests/1-FileSystem/Test.vdproj`.
2. Diff generated `Test.wxs` against `Tests/1-FileSystem/Expected.wxs`.
3. Add one unsupported `.vdproj` concept at a time, then decide whether to extend regex extraction or hand-author WiX.

## Connections
- `MsiQuery.h` is useful after conversion to inspect the generated MSI tables.
- `MSI Search Conditions` and `Registry Setup (RegInstallW)` are common areas where legacy installer projects need hand correction.

## References
- <https://github.com/chrisoldwood/vdproj2wix>
