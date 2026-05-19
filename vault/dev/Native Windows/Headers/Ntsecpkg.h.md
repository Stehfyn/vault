# Ntsecpkg.h

The contract LSA imposes on a Security Support Provider (SSP) / Authentication Package (AP). If you are writing -- or reverse-engineering -- Kerberos, NTLM, Negotiate, Schannel, CredSSP, or a custom SSP/AP that LSASS loads, this is the header. Defines the two big function tables `LSA_SECPKG_FUNCTION_TABLE` (LSA -> package, with entries like `InitializePackage`, `LogonUserEx`, `CallPackage`, `AcceptCredentials`, `SpAcceptLsaModeContext`, `SpAcquireCredentialsHandle`) and `SECPKG_FUNCTION_TABLE`, plus the dispatch table LSA hands the package on load. Not a public SDK surface in the everyday sense -- it lives in the WDK / specialized auth-package documentation. Pair with `ntsecapi.h` (LSA client API), `sspi.h` (the consumer-facing SSPI), `secext.h`.

## References
- <https://learn.microsoft.com/en-us/windows/win32/secauthn/ssp-ap-interface>
