# Aero Non-Client Metrics Tweaker

A live tweaker for the DWM/non-client metrics that Windows 10/11 hardcoded — border thickness, caption height, accent-color application, the things `SystemParametersInfo(SPI_SETNONCLIENTMETRICS, ...)` used to do before Microsoft locked half of it down post-Aero. Sits in the Aero-revival cluster (cf. ALTaleX531/OpenGlass #13, Maplespe/DWMBlurGlass #54, clifford269/FrutigerFX #39) but on the *geometry* side instead of the *blur/translucency* side. Mostly drives `DwmSetWindowAttribute` and the documented-but-rarely-used `SetSysColors` / NCM path.

## References
- <https://github.com/Dulappy/aero-window-manager>
