# Frutiger Aero Firefox Restyle

Firefox userChrome.css restyle in the "Frutiger Aero" idiom — the late-2000s Vista/early-Win7 visual language (glass, bokeh, glossy rounded chrome, aqua-blue gradients, nature/sky photography). Listed here as the aesthetic anchor for the Aero-revival cluster in this dump that actually re-implements the rendering: Maplespe/DWMBlurGlass (#54), ALTaleX531/OpenGlass (#13), Maplespe/ExplorerBlurMica (#66), Dulappy/aero-window-manager (#43). Not Win32 code itself — included as a reference for the look those projects are chasing.

```css
/* userChrome.css — the kind of rule FrutigerFX leans on */
#navigator-toolbox {
  background: linear-gradient(to bottom,
    rgba(180,220,255,0.55), rgba(120,180,230,0.35)) !important;
  backdrop-filter: blur(18px) saturate(140%);
  border-bottom: 1px solid rgba(255,255,255,0.4);
}
```

## References
- <https://github.com/clifford269/FrutigerFX>
