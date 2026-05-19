# BuildCast - Fluent UWP Showcase

BuildCast is a Build-era C#/XAML UWP sample that tried to exercise the whole Windows 10 app-model pitch in one app: adaptive layout, acrylic/Fluent styling, background media, inking, connected animations, and mixed-reality views. Its value is not a single API trick; it shows how those features were meant to compose inside a packaged UWP application with XAML as the organizing layer.

Keep it as a historical UWP reference beside WinUI 3 and Windows App SDK notes. It is useful when comparing the old UWP-only platform story with the later "bring modern APIs to Win32" story: BuildCast assumes package identity and UWP lifecycle by default, while Windows App SDK samples spend much of their effort escaping that assumption.

Code contribution: inspect `Package.appxmanifest`, XAML pages, `AcrylicBrush`, connected-animation calls, media elements, and async WinRT projections to see the packaged-UWP assumptions.

## References
- <https://github.com/microsoft/BuildCast> - complete UWP app sample for Fluent-era XAML, media, ink, and adaptive layout.
