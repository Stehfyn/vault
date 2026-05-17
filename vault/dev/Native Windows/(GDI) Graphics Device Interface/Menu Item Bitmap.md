1. https://stackoverflow.com/questions/60176811/win32-menu-item-bitmap-with-transparent-background
2. https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-loadimagew

Snippet (preserve alpha + MIIM_BITMAP/SetMenuItemInfo):

```cpp
HBITMAP hbmp = (HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(ID_BITMAP_EXIT),
                                  IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);

MENUITEMINFO mii = { sizeof(mii) };
mii.fMask = MIIM_BITMAP;
mii.hbmpItem = hbmp; // or SetMenuItemBitmaps(menu, id, MF_BYCOMMAND, hbmp, hbmp)
SetMenuItemInfo(menu, ID_FILE_EXIT, FALSE, &mii);
```
