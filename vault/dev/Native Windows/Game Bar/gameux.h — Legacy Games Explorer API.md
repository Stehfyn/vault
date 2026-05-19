# gameux.h - Legacy Games Explorer API

`gameux.h` documents the Vista/Windows 7 Games Explorer COM surface, chiefly `IGameExplorer::AddGame` and `RemoveGame`. Its value today is archaeological: it shows how Windows once treated games as shell-registered catalog items with metadata, ratings, tasks, and launch verbs before Game Bar, MSIX, and Xbox Live presence absorbed that role.

Read it when debugging old installers or shell extensions that still try to register games into the Games folder. It connects to `Shell Items and Folders`, `Known Folders`, and the Game Bar entries because all three are different generations of the same problem: mapping an executable into a shell-visible game identity.

## References
- `gameux.h`
