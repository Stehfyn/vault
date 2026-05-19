# IHxHelpPaneServer - Help Viewer COM

`IHxHelpPaneServer` is an undocumented COM surface around Microsoft Help Viewer / HelpPane-style content display. Its interest is the activation path: Visual Studio-era help systems and shell help entry points could hand `ms-xhelp:` style locations to an out-of-proc help host instead of embedding a browser or CHM viewer directly.

Treat the linked repository as reverse-engineering notes and sample glue, not as a stable SDK contract. It belongs beside COM activation, DocObject/MSHTML hosting, and shell command routing entries because all three show the same older Windows pattern: a visible feature exposed through COM classes and monikers that were meant for Microsoft clients first and public consumers second.

## References
- <https://github.com/mabangde/IHxHelpPaneServer> - small wrapper/research repo for the undocumented help-viewer COM interface.
