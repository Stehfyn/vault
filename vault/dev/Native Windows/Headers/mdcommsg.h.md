# mdcommsg.h

Message-table / `mc.exe`-generated common messages for the IIS Metabase (`Metadata.dll`) and its server-side consumers. The Metabase was IIS 6's hierarchical configuration store (`MD_*` paths, `IMSAdminBase`) -- superseded by `applicationHost.config` + `Microsoft.Web.Administration` in IIS 7 (2008). Numeric constants here are `MD_ERROR_*` / `MD_WARNING_*` codes returned through `IMSAdminBase::GetData`/`SetData`. Outside of IIS6-compat or migration tooling there's nothing here you'd ever need. Cluster: `iiscnfg.h`, `mdmsg.h`, `iadmw.h`.

## References
- <https://learn.microsoft.com/en-us/previous-versions/iis/6.0-sdk/ms525463(v=vs.90)>
