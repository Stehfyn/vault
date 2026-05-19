<!-- generated-from-dump2 -->
# Windows Driver DDI Reference Source

Source markdown for the Windows Driver Kit DDI (Device Driver Interface) reference site on learn.microsoft.com. Useful as a fast offline grep target for IOCTLs, dispatch routine prototypes, and WDM/WDF struct definitions when the online docs are slow or rate-limited. Each topic is one .md per function/struct keyed by header name.

```bash
# Find every dispatch routine reference for a header.
git clone --depth 1 https://github.com/MicrosoftDocs/windows-driver-docs-ddi
rg -l 'IRP_MJ_DEVICE_CONTROL' wdk-ddi-src/content/
```

## References
- <https://github.com/MicrosoftDocs/windows-driver-docs-ddi>
