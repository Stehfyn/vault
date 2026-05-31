# COM, Shell, Window, And Control Helpers

[Macros index](<macros.md>)

## Curated Candidates

```c
// shell\comdlg32\filenew.cpp
#define CD_SendIncludeItemNotify(_hwndTo, _hwndFrom, _psf, _pidl, _pofn, _pofi) \
    SendOFNotifyEx(_hwndTo, _hwndFrom, CDN_INCLUDEITEM, (void *)_psf, (void *)_pidl, _pofn, _pofi)

// shell\comdlg32\comdlg32.h
#ifdef WX86
  #define ISWX86APP(p)            ((p)->Flags & CD_WX86APP)
  #define GETGENERICHOOKFN(p,fn)  (ISWX86APP(p) ? Wx86GetX86Callback((p)->fn) : (p)->fn)
#else
  #define ISWX86APP(p)            (FALSE)
  #define GETGENERICHOOKFN(p,fn)  ((p)->fn)
#endif

#define GETHOOKFN(p)            GETGENERICHOOKFN(p,lpfnHook)
#define GETPRINTHOOKFN(p)       GETGENERICHOOKFN(p,lpfnPrintHook)
#define GETSETUPHOOKFN(p)       GETGENERICHOOKFN(p,lpfnSetupHook)
#define GETPAGEPAINTHOOKFN(p)   GETGENERICHOOKFN(p,lpfnPagePaintHook)

// shell\comdlg32\filenew.cpp
#define HwndToBrowser(_hwnd) (CFileOpenBrowser *)GetWindowLongPtr(_hwnd, DWLP_USER)
#define StoreBrowser(_hwnd, _pbrs) \
    SetWindowLongPtr(_hwnd, DWLP_USER, (LONG_PTR)_pbrs);

// shell\inc\ccstock.h
#ifdef __cplusplus
#define IID_PPV_ARG(IType, ppType) IID_##IType, reinterpret_cast<void**>(static_cast<IType**>(ppType))
#define IID_X_PPV_ARG(IType, X, ppType) IID_##IType, X, reinterpret_cast<void**>(static_cast<IType**>(ppType))
#else
#define IID_PPV_ARG(IType, ppType) &IID_##IType, (void**)(ppType)
#define IID_X_PPV_ARG(IType, X, ppType) &IID_##IType, X, (void**)(ppType)
#endif
#define IID_PPV_ARG_NULL(IType, ppType) IID_X_PPV_ARG(IType, NULL, ppType)

// shell\comctl32\v6\edit.h
#define Pundo(ped)             ((PUNDO)&(ped)->undoType)

#define DECLARE_LPK_CALLOUT(_ret, _fn, _args) \
            _ret (__stdcall *##_fn) _args

// admin\activec\designer\vb98ctls\include\macros.h
#define BASICBOOLOF(f)    ((f) ? -1 : 0 )

#define FMAKEBOOL(f)      (!!(f))

// admin\activec\conui\amcview.cpp
    #define GET_APPCOMMAND_LPARAM(lParam) ((short)(HIWORD(lParam) & ~FAPPCOMMAND_MASK))

// multimedia\media\avi\vidcap32\toolbar.h
#define GWLP_ARRAYBUTT	0		/* Pointer to array of buttons  */

#define GWL_NUMBUTTONS	(GWLP_ARRAYBUTT + sizeof(HANDLE))	/* Number of buttons in array   */

#define GWL_PRESSED	(GWL_NUMBUTTONS + sizeof(int))		/* Is a button currently pressed*/

#define GWL_KEYPRESSED	(GWL_PRESSED + sizeof(BOOL))      	/* Is a key currently pressed?  */

#define GWL_WHICH	(GWL_KEYPRESSED + sizeof(BOOL))	        /* Which button has the focus?  */

#define GWL_SHIFTED	(GWL_WHICH + sizeof(int))		/* Is it rt-click or shift-left?*/

#define GWLP_BMPHANDLE	(GWL_SHIFTED + sizeof(BOOL))		/* handle to bmp of the buttons */

#define GWL_BMPINT	(GWLP_BMPHANDLE + sizeof(HANDLE))	/* resource int of button bmp	*/

#define GWL_BUTTONSIZE	(GWL_BMPINT + sizeof(int))		/* a point (x=hi y=lo)		*/

#define GWLP_HINST	(GWL_BUTTONSIZE + sizeof(long))	/* hinst of the app   		*/

#define TOOLBAR_EXTRABYTES	(GWLP_HINST + sizeof(HANDLE))

// multimedia\media\avi\vidcap32\toolbar.c
#define GETARRAYBUTT(hwnd)	((HANDLE)GetWindowLongPtr(hwnd,GWLP_ARRAYBUTT))

#define GETNUMBUTTONS(hwnd)	((int)GetWindowLong(hwnd,GWL_NUMBUTTONS))

#define GETPRESSED(hwnd)	((BOOL)GetWindowLong(hwnd,GWL_PRESSED))

#define GETKEYPRESSED(hwnd)	((BOOL)GetWindowLong(hwnd,GWL_KEYPRESSED))

#define GETWHICH(hwnd)		((int)GetWindowLong(hwnd,GWL_WHICH))

#define GETSHIFTED(hwnd)	((BOOL)GetWindowLong(hwnd,GWL_SHIFTED))

#define GETBMPHANDLE(hwnd)	((HANDLE)GetWindowLongPtr(hwnd,GWLP_BMPHANDLE))

#define GETBMPINT(hwnd)		((int)GetWindowLong(hwnd,GWL_BMPINT))

#define GETBUTTONSIZE(hwnd)	GetWindowLong(hwnd,GWL_BUTTONSIZE)

#define GETHINST(hwnd)		((HANDLE)GetWindowLongPtr(hwnd,GWLP_HINST))

#define SETARRAYBUTT(hwnd, h) SetWindowLongPtr(hwnd, GWLP_ARRAYBUTT, (UINT_PTR)h)

#define SETNUMBUTTONS(hwnd, wNumButtons) \
			SetWindowLong(hwnd, GWL_NUMBUTTONS, wNumButtons)

#define SETPRESSED(hwnd, f)	SetWindowLong(hwnd, GWL_PRESSED, (UINT)f)

#define SETKEYPRESSED(hwnd, f)	SetWindowLong(hwnd, GWL_KEYPRESSED, (UINT)f)

#define SETWHICH(hwnd, i)	SetWindowLong(hwnd, GWL_WHICH, (UINT)i)

#define SETSHIFTED(hwnd, i)	SetWindowLong(hwnd, GWL_SHIFTED, (UINT)i)

#define SETBMPHANDLE(hwnd, h)	SetWindowLongPtr(hwnd, GWLP_BMPHANDLE, (UINT_PTR)h)

#define SETBMPINT(hwnd, i)	SetWindowLong(hwnd, GWL_BMPINT, (UINT)i)

#define SETBUTTONSIZE(hwnd, l)	SetWindowLong(hwnd, GWL_BUTTONSIZE, l)

#define SETHINST(hwnd, h)	SetWindowLongPtr(hwnd, GWLP_HINST, (UINT_PTR)h)

// multimedia\media\winmm\mmwowmci.h
#define MMGETOPTPTR(vp,cb,p)  {p=NULL; if (HIWORD(FETCHDWORD(vp))) p = GETVDMPTR(vp);}

// sdktools\gutils\tpriv.h
#define WW_HEAP         (WW_OWNER + sizeof(HWND))       /* gmem heap */

#define WL_TABLE        (WW_HEAP + sizeof(HANDLE))      /* lpTable */

#define WLTOTAL         (WL_TABLE + sizeof(lpTable))    /* total extra bytes */
```

## Backlog

```c
// admin\controls\smonctrl\hatchwnd.h
#define CBHATCHWNDEXTRA                 (sizeof(LONG_PTR))

// admin\controls\smonctrl\owndraw.h
#define DIWindow(lpDI)              \
   (lpDI->hwndItem)

// admin\controls\smonctrl\utils.h
#define WindowShow(hWnd, bShow) \
   ShowWindow (hWnd, (bShow) ? SW_SHOW : SW_HIDE)

// admin\controls\smonctrl\winhelpr.h
#define SetFont(hWnd, hFont)                          \
   (SendMessage ((hWnd), WM_SETFONT, (WPARAM)hFont, (LPARAM)0))
#define GetFont(hWnd) \
    (HFONT)(SendMessage((hWnd), WM_GETFONT, (WPARAM)0, (LPARAM)0))
#define PrintClient(hWnd, hDC, uFlags) \
    (SendMessage((hWnd), WM_PRINTCLIENT, (WPARAM)hDC, (LPARAM)(uFlags)) )
#define CBData(hWndCB, iIndex)                        \
   (SendMessage (hWndCB, CB_GETITEMDATA, (WPARAM)iIndex, (LPARAM)0))
#define CBSetData(hWndCB, iIndex, lData)              \
   (SendMessage (hWndCB, CB_SETITEMDATA, (WPARAM)iIndex, (LPARAM)lData))
#define CBAdd(hWndCB, lpszText)                       \
   ((INT)(DWORD)SendMessage((hWndCB), CB_ADDSTRING,   \
    (WPARAM)0, (LPARAM)(LPCTSTR)(lpszText)))
#define CBFind(hWndCB, lpszText)                      \
   (SendMessage (hWndCB, CB_FINDSTRING, (WPARAM)(-1), (LPARAM) lpszText))
#define CBInsert(hWndCB, iIndex, lpszText)            \
   (SendMessage (hWndCB, CB_INSERTSTRING, (WPARAM)iIndex, (LPARAM) lpszText))
#define CBNumItems(hWndCB)                            \
   ((INT) SendMessage (hWndCB, CB_GETCOUNT, (WPARAM)0, (LPARAM)0))
#define CBReset(hWndCB)                               \
   ((INT)(DWORD)SendMessage((hWndCB), CB_RESETCONTENT,\
    (WPARAM)0, (LPARAM)0))
#define CBSelection(hWndCB)                           \
   (SendMessage (hWndCB, CB_GETCURSEL, (WPARAM)0, (LPARAM)0))
#define CBSetSelection(hWndCB, iIndex)                \
   (SendMessage (hWndCB, CB_SETCURSEL, (WPARAM)iIndex, (LPARAM)0))
#define CBString(hWndCB, iIndex, lpszText)            \
   (SendMessage (hWndCB, CB_GETLBTEXT, (WPARAM)iIndex, (LPARAM)lpszText))
#define CBStringLen(hWndCB, iIndex)                   \
   (SendMessage (hWndCB, CB_GETLBTEXTLEN, (WPARAM)iIndex, (LPARAM)0))
#define LBAdd(hWndLB, lpszText)                       \
   (SendMessage (hWndLB, LB_ADDSTRING, (WPARAM)0, (LPARAM)lpszText))
#define LBData(hWndLB, iIndex)                        \
(SendMessage (hWndLB, LB_GETITEMDATA, (WPARAM)iIndex, (LPARAM)0))
#define LBFind(hWndLB, lpszText)                      \
   (SendMessage (hWndLB, LB_FINDSTRING, (WPARAM)-1, (LPARAM)lpszText))
#define LBFocus(hWndLB)                               \
   (SendMessage (hWndLB, LB_GETCARETINDEX, (WPARAM)0, (LPARAM)0))
#define LBInsert(hWndLB, iIndex, lpszText)            \
   (SendMessage (hWndLB, LB_INSERTSTRING, (WPARAM)iIndex, (LPARAM)lpszText))
#define LBNumItems(hWndLB)                            \
   ((INT) SendMessage (hWndLB, LB_GETCOUNT, (WPARAM)0, (LPARAM)0))
#define LBReset(hWndLB)                               \
   ((INT)(DWORD)SendMessage((hWndLB), LB_RESETCONTENT,\
    (WPARAM)0, (LPARAM)0))
#define LBSelected(hwndLB, index)                     \
   ((INT)(DWORD)SendMessage((hwndLB), LB_GETSEL,      \
    (WPARAM)(INT)(index), (LPARAM)0))
#define LBSelection(hWndLB)                           \
   ((INT)(DWORD)SendMessage (hWndLB, LB_GETCURSEL, (WPARAM)0, (LPARAM)0))
#define LBSetData(hWndLB, iIndex, lData)              \
   (SendMessage (hWndLB, LB_SETITEMDATA, (WPARAM)iIndex, (LPARAM)lData))
#define LBSetSelection(hWndLB, iIndex)                \
   (SendMessage (hWndLB, LB_SETCURSEL, (WPARAM)iIndex, (LPARAM)0))
#define MLBSetSelection(hWndMLB, iIndex, bSet)        \
   (SendMessage (hWndMLB, LB_SETSEL, (WPARAM)bSet, (LPARAM)iIndex))
#define LBSetVisible(hWndLB, iIndex)                  \
   (SendMessage (hWndLB, LB_SETCARETINDEX, (WPARAM)iIndex, (LPARAM)0))
#define LBSetRedraw(hWndLB, bDrawOnOff)               \
   (SendMessage (hWndLB, WM_SETREDRAW, (WPARAM)bDrawOnOff, (LPARAM)0))
#define LBSetHorzExtent(hWndLB, wExtent)              \
   (SendMessage (hWndLB, LB_SETHORIZONTALEXTENT, (WPARAM)wExtent, (LPARAM)0))
#define LBSetItemHeight(hWndLB, iHeight)              \
    (SendMessage (hWndLB, LB_SETITEMHEIGHT, (WPARAM)0, (LPARAM)iHeight))
#define LBGetTextLen(hWndLB, iIndex)                  \
    (SendMessage (hWndLB, LB_GETTEXTLEN, (WPARAM)iIndex, (LPARAM)0))
#define LBGetText(hWndLB, iIndex, szPath)             \
    (SendMessage (hWndLB, LB_GETTEXT, (WPARAM)iIndex, (LPARAM)szPath))
#define EditModified(hWndEdit)                        \
   (SendMessage ((hWndEdit), EM_GETMODIFY, (WPARAM)0, (LPARAM)0))
#define EditSetModified(hWndEdit, bModified)                     \
   (SendMessage ((hWndEdit), EM_SETMODIFY, (WPARAM)bModified, (LPARAM)0))
#define EditSetLimit(hWndEdit, iLimit)                \
   (SendMessage ((hWndEdit), EM_LIMITTEXT, (WPARAM)iLimit, (LPARAM)0))
#define EditSetTextPos(hWnd, idControl, iStartPos, iEndPos)    \
   (SendMessage (GetDlgItem(hWnd, idControl), EM_SETSEL, (WPARAM)iStartPos, (LPARAM)iEndPos))

// admin\extens\oudeleg\pch.h
#define GET_WM_COMMAND_HWND(wp, lp)             (HWND)(lp)
#define GET_WM_COMMAND_MPS(id, hwnd, cmd)    \
        (WPARAM)MAKELONG(id, cmd), (LONG)(hwnd)
#define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)(lp)
#define GET_WM_VSCROLL_MPS(code, pos, hwnd)    \
        (WPARAM)MAKELONG(code, pos), (LONG)(hwnd)

// admin\netui\common\hack\dos\pwin16.h
#define GET_WM_ACTIVATE_HWND(wp, lp)                (HWND)LOWORD(lp)
#define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)   \
        (WPARAM)(s), MAKELONG(hwnd, fmin)
#define GET_WM_CHARTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
#define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd) \
        (WPARAM)(ch), MAKELONG(hwnd, pos)
#define GET_WM_COMMAND_HWND(wp, lp)                 (HWND)LOWORD(lp)
#define GET_WM_COMMAND_MPS(id, hwnd, cmd)    \
        (WPARAM)(id), MAKELONG(hwnd, cmd)
#define GET_WM_CTLCOLOR_HWND(wp, lp, msg)           (HWND)LOWORD(lp)
#define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type) \
        (WPARAM)(hdc), MAKELONG(hwnd, type)
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
#define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
#define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
        (WPARAM)(hwndA), 0
#define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)       (HWND)LOWORD(lp)
#define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd) \
        (WPARAM)(msg), MAKELONG(hwnd, id)
#define GET_WM_VKEYTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
#define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) \
        (WPARAM)(code), MAKELONG(hwnd, item)
#define GET_WM_HSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
#define GET_WM_HSCROLL_MPS(code, pos, hwnd)    \
        (WPARAM)(code), MAKELONG(pos, hwnd)
#define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
#define GET_WM_VSCROLL_MPS(code, pos, hwnd)    \
        (WPARAM)(code), MAKELONG(pos, hwnd)
#define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)       (HWND)LOWORD(lp)

// admin\netui\macprint\pstodib\ti\src\win\wintt.c
#define FONTLOCK() \
     hdc = GetDC (hwndMain); \
     font = (FONT FAR *) GlobalLock (enumer2.hGMem) + nFontID; \
     hFont = SelectObject (hdc, CreateFontIndirect (&font->lf))

// admin\pchealth\sysinfo\msconfig\exe\stdafx.h
   #define ListView_SetCheckState(hwndLV, i, fCheck) \
      ListView_SetItemState(hwndLV, i, \
      INDEXTOSTATEIMAGEMASK((fCheck)+1), LVIS_STATEIMAGEMASK)

// admin\select\src\macros.hxx
#define ComboBoxEx_InsertItem(hwnd, lpcCBItem)  \
    (int)SendMessage((hwnd), CBEM_INSERTITEM, 0, (LPARAM)(lpcCBItem))
#define ComboBoxEx_GetItem(hwnd, pcbxi)         \
    (int)SendMessage((hwnd), CBEM_GETITEM, 0, (LPARAM)(pcbxi))
#define ComboBoxEx_GetCount(hwnd)               \
    (int)SendMessage((hwnd), CB_GETCOUNT, 0, 0);
#define ComboBoxEx_SetImageList(hwnd, himl)               \
    (int)SendMessage((hwnd), CBEM_SETIMAGELIST, 0, (LPARAM)(himl));

// admin\select\test\opt\main.cxx
#define GetFirstSelected(hwndLv) ListView_GetNextItem(hwndLv, -1, LVNI_SELECTED)

// admin\services\sched\folderui\menubg.cxx
#define SORT_BY(X)  \
    case FSIDM_SORTBY##X: ShellFolderView_ReArrange(m_hwnd, COLUMN_##X); break

// admin\services\sched\svc_core\events.hxx
#define SetNextIdleNotification(wIdleWait)  \
    SendMessage(g_hwndSchedSvc, WM_SCHED_SetNextIdleNotification, wIdleWait, 0)
#define SetIdleLossNotification()   \
    SendMessage(g_hwndSchedSvc, WM_SCHED_SetIdleLossNotification, 0, 0)

// admin\services\sched\wizard\util.hxx
#define UpDown_SetPos(hCtrl, sPos)          (SHORT)SendMessage((hCtrl), UDM_SETPOS, 0, (LPARAM) MAKELONG((short) sPos, 0))
#define UpDown_GetPos(hCtrl)                (SHORT)SendMessage((hCtrl), UDM_GETPOS, 0, 0)

// admin\wmi\wbem\shell\atlui\wmicntl\chklist.h
#define CBL_GetItemCount(x) (SendMessage(x, CLM_GETITEMCOUNT, 0,0))
#define CBL_GetItemData(x,y) (SendMessage(x, CLM_GETITEMDATA,(WPARAM)y, 0))
#define CBL_GetState(x, r, c) (SendMessage(x, CLM_GETSTATE, MAKEWPARAM(r, c), 0))
#define CBL_SetState(x, r, c, s) (SendMessage(x, CLM_SETSTATE, MAKEWPARAM(r, c),(LPARAM)s))

// admin\wmi\wbem\shell\atlui\wmicntl\genpage.cpp
#define Static_SetIcon(hwndCtl, hIcon) ((HICON)(UINT)(DWORD)::SendMessage((hwndCtl), STM_SETICON, (WPARAM)(HICON)(hIcon), 0L))

// base\busdrv\pccard\inc\pcmcia.h
#define PcmciaSetWindowPage(fdoExtension, Socket, Index, Page)                                        \
   ((DeviceDispatchTable[fdoExtension->DeviceDispatchIndex].SetWindowPage) ?                          \
      (*DeviceDispatchTable[fdoExtension->DeviceDispatchIndex].SetWindowPage)(Socket, Index, Page) :  \
      FALSE)
#define HasWindowPageRegister(fdoExtension)  \
   ((BOOLEAN)(DeviceDispatchTable[fdoExtension->DeviceDispatchIndex].SetWindowPage))

// base\fs\dfs\ui\inc\tb.h
#define Toolbar_AddBitmap(hwnd, nButtons, hBMInst, nBMID) \
	{ TBADDBITMAP _tbBM; \
	  _tbBM.hInst = hBMInst; \
	  _tbBM.nID   = nBMID; \
	  (int)SendMessage((hwnd),TB_ADDBITMAP,(WPARAM)(nButtons),(LPARAM)&_tbBM); \
	}
#define Toolbar_AddButtons(hwnd, nButtons, lpButtons) \
	(BOOL)SendMessage((hwnd),TB_ADDBUTTONS,(WPARAM)(nButtons),(LPARAM)(LPTBBUTTON)(lpButtons))
#define Toolbar_AddString(hwnd, hInst, idString) \
	(int)SendMessage((hwnd),TB_ADDSTRING,(WPARAM)(HINSTANCE)(hInst),(LPARAM)(MAKELPARAM((idString),0)))
#define Toolbar_AutoSize(hwnd) \
	(void)SendMessage((hwnd),TB_AUTOSIZE,(WPARAM)0,(LPARAM)0)
#define Toolbar_ButtonCount(hwnd) \
	(int)SendMessage((hwnd),TB_BUTTONCOUNT,(WPARAM)0,(LPARAM)0)
#define Toolbar_ButtonStructSize(hwnd, cb) \
	(int)SendMessage((hwnd),TB_BUTTONSTRUCTSIZE,(WPARAM)(cb),(LPARAM)0)
#define Toolbar_CheckButton(hwnd, idButton, fCheck) \
	(BOOL)SendMessage((hwnd),TB_CHECKBUTTON,(WPARAM)(idButton),(LPARAM)MAKELPARAM((fCheck),0))
#define Toolbar_CommandToIndex(hwnd, idButton) \
	(int)SendMessage((hwnd),TB_COMMANDTOINDEX,(WPARAM)(idButton),(LPARAM)0)
#define Toolbar_Customize(hwnd) \
	(void)SendMessage((hwnd),TB_CUSTOMIZE,(WPARAM)0,(LPARAM)0)
#define Toolbar_EnableButton(hwnd, idButton, fEnable) \
	(BOOL)SendMessage((hwnd),TB_ENABLEBUTTON,(WPARAM)(idButton),(LPARAM)MAKELPARAM((fEnable),0))
#define Toolbar_GetButton(hwnd, iButton, lpButton) \
	(BOOL)SendMessage((hwnd),TB_GETBUTTON,(WPARAM)(iButton),(LPARAM)(LPTBBUTTON)(lpButton))
#define Toolbar_GetItemRect(hwnd, iButton, lpRect) \
	(BOOL)SendMessage((hwnd),TB_GETITEMRECT,(WPARAM)(iButton),(LPARAM)(LPRECT)(lpRect))
#define Toolbar_GetState(hwnd, iButton, lpRect) \
	(int)SendMessage((hwnd),TB_GETSTATE,(WPARAM)(iButton),(LPARAM)0)
#define Toolbar_HideButton(hwnd, idButton, fShow) \
	(BOOL)SendMessage((hwnd),TB_HIDEBUTTON,(WPARAM)(idButton),(LPARAM)MAKELPARAM((fShow),0))
#define Toolbar_Indeterminate(hwnd, iButton, fIndeterminate) \
	(BOOL)SendMessage((hwnd),TB_INDETERMINATE,(WPARAM)(iButton),(LPARAM)MAKELPARAM((fIndeterminate),0))
#define Toolbar_InsertButton(hwnd, iButton, lpButton) \
	(BOOL)SendMessage((hwnd),TB_INSERTBUTTON,(WPARAM)(iButton),(LPARAM)(LPTBBUTTON)(lpButton))
#define Toolbar_IsButtonChecked(hwnd, idButton) \
	(int)SendMessage((hwnd),TB_ISBUTTONCHECKED,(WPARAM)(idButton),(LPARAM)0)
#define Toolbar_IsButtonEnabled(hwnd, idButton) \
	(int)SendMessage((hwnd),TB_ISBUTTONENABLED,(WPARAM)(idButton),(LPARAM)0)
#define Toolbar_IsButtonHidden(hwnd, idButton) \
	(int)SendMessage((hwnd),TB_ISBUTTONHIDDEN,(WPARAM)(idButton),(LPARAM)0)
#define Toolbar_IsButtonIndeterminate(hwnd, idButton) \
	(int)SendMessage((hwnd),TB_ISBUTTONINDETERMINATE,(WPARAM)(idButton),(LPARAM)0)
#define Toolbar_IsButtonPressed(hwnd, idButton) \
	(int)SendMessage((hwnd),TB_ISBUTTONPRESSED,(WPARAM)(idButton),(LPARAM)0)
#define Toolbar_PressButton(hwnd, idButton, fPress) \
	(BOOL)SendMessage((hwnd),TB_PRESSBUTTON,(WPARAM)(idButton),(LPARAM)MAKELPARAM((fPress),0))
#define Toolbar_SaveRestore(hwnd, fSave, lpSaveRestore) \
	(BOOL)SendMessage((hwnd),TB_SAVERESTORE,(WPARAM)(fSave),(LPARAM)(TBSAVEPARAMS*)(lpSaveRestore))
#define Toolbar_SetBitmapSize(hwnd, dxBitmap, dyBitmap) \
	(BOOL)SendMessage((hwnd),TB_SETBITMAPSIZE,(WPARAM)0,(LPARAM)MAKELPARAM((dxBitmap),(dyBitmap)))
#define Toolbar_SetButtonSize(hwnd, dxButton, dyButton) \
	(BOOL)SendMessage((hwnd),TB_SETBUTTONSIZE,(WPARAM)0,(LPARAM)MAKELPARAM((dxButton),(dyButton)))
#define Toolbar_SetState(hwnd, idButton, fState) \
	(BOOL)SendMessage((hwnd),TB_SETSTATE,(WPARAM)(idButton),(LPARAM)MAKELPARAM((fState),0))

// base\fs\rdr2\csc\usermode\reint\extra.h
#define HANDLE_WM_CONTEXTMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)

// base\fs\rdr2\csc\usermode\reint\recact.h
#define RecAct_GetItemCount(hwnd) \
		(int)SendMessage(hwnd, RAM_GETITEMCOUNT, 0, 0L)
#define RecAct_InsertItem(hwnd, pitem) \
		(int)SendMessage((hwnd), RAM_INSERTITEM, 0, (LPARAM)(const LPRA_ITEM)(pitem))
#define RecAct_GetItem(hwnd, pitem) \
		(BOOL)SendMessage((hwnd), RAM_GETITEM, 0, (LPARAM)(LPRA_ITEM)(pitem))
#define RecAct_SetItem(hwnd, pitem) \
		(BOOL)SendMessage((hwnd), RAM_SETITEM, 0, (LPARAM)(const LPRA_ITEM)(pitem))
#define RecAct_GetCurSel(hwnd) \
		(int)SendMessage((hwnd), RAM_GETCURSEL, (WPARAM)0, 0L)
#define RecAct_SetCurSel(hwnd, i) \
		(int)SendMessage((hwnd), RAM_SETCURSEL, (WPARAM)(i), 0L)
#define RecAct_FindItem(hwnd, iStart, prafi) \
		(int)SendMessage((hwnd), RAM_FINDITEM, (WPARAM)(int)(iStart), (LPARAM)(const RA_FINDINFO FAR*)(prafi))
#define RecAct_Refresh(hwnd) \
		SendMessage((hwnd), RAM_REFRESH, 0, 0L)

// base\mvdm\v86\scaffold\i386\x86.h
#define FIXHWND(h)	((HWND)((INT)(h) & 0x00ffffff))

// base\mvdm\wow16\ctl3dv2\ctl3d.c
#define SEND_COLOR_BUTTON_MESSAGE( hwndParent, hwnd, hdc )      \
    ((HBRUSH) SendMessage(hwndParent, WM_CTLCOLORBTN, (WPARAM) hdc, (LPARAM) hwnd))
#define SEND_COLOR_STATIC_MESSAGE( hwndParent, hwnd, hdc )      \
    ((HBRUSH) SendMessage(hwndParent, WM_CTLCOLORSTATIC, (WPARAM) hdc, (LPARAM) hwnd))
#define SEND_COLOR_BUTTON_MESSAGE( hwndParent, hwnd, hdc )      \
    ((HBRUSH) SendMessage(hwndParent, WM_CTLCOLOR, (WORD) hdc, MAKELONG(hwnd, CTLCOLOR_BTN)))
#define SEND_COLOR_STATIC_MESSAGE( hwndParent, hwnd, hdc )      \
    ((HBRUSH) SendMessage(hwndParent, WM_CTLCOLOR, (WORD) hdc, MAKELONG(hwnd, CTLCOLOR_STATIC)))

// base\mvdm\wow16\ddeml\ddemlp.h
#define MAKEHCONV(hwnd)     (IsWindow(hwnd) ? hwnd | ((DWORD)GetWindowWord(hwnd, GWW_CHECKVAL) << 16) : 0)

// base\mvdm\wow16\inc\windowsx.h
#define     SetWindowRedraw(hwnd, fRedraw)  \
                    ((void)SendMessage(hwnd, WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L))
#define     IsRestored(hwnd)    ((GetWindowStyle(hwnd) & (WS_MINIMIZE | WS_MAXIMIZE)) == 0L)
#define     SetWindowFont(hwnd, hfont, fRedraw) FORWARD_WM_SETFONT((hwnd), (hfont), (fRedraw), SendMessage)
#define     GetWindowFont(hwnd)                 FORWARD_WM_GETFONT((hwnd), SendMessage)
#define HANDLE_WM_COMPACTING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_COMPACTING(hwnd, compactRatio, fn) \
    (void)(fn)((hwnd), WM_COMPACTING, (WPARAM)(UINT)(compactRatio), 0L)
#define HANDLE_WM_WININICHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_WININICHANGE(hwnd, lpszSectionName, fn) \
    (void)(fn)((hwnd), WM_WININICHANGE, 0, (LPARAM)(LPCSTR)(lpszSectionName))
#define HANDLE_WM_SYSCOLORCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_SYSCOLORCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_SYSCOLORCHANGE, 0, 0L)
#define HANDLE_WM_QUERYNEWPALETTE(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYNEWPALETTE(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYNEWPALETTE, 0, 0L)
#define HANDLE_WM_PALETTEISCHANGING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTEISCHANGING(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTEISCHANGING, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_PALETTECHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTECHANGED(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTECHANGED, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_FONTCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_FONTCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_FONTCHANGE, 0, 0L)
#define HANDLE_WM_DEVMODECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_DEVMODECHANGE(hwnd, lpszDeviceName, fn) \
    (void)(fn)((hwnd), WM_DEVMODECHANGE, 0,(LPARAM)(LPCSTR)(lpszDeviceName))
#define HANDLE_WM_TIMECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_TIMECHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_TIMECHANGE, 0, 0L)
#define HANDLE_WM_POWER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_POWER(hwnd, code, fn) \
    (void)(fn)((hwnd), WM_POWER, (WPARAM)(code), 0L)
#define HANDLE_WM_QUERYENDSESSION(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYENDSESSION(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYENDSESSION, 0, 0L)
#define HANDLE_WM_ENDSESSION(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENDSESSION(hwnd, fEnding, fn) \
    (void)(fn)((hwnd), WM_ENDSESSION, (WPARAM)(BOOL)(fEnding), 0L)
#define HANDLE_WM_QUIT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_QUIT(hwnd, exitCode, fn) \
    (void)(fn)((hwnd), WM_QUIT, (WPARAM)(exitCode), 0L)
#define HANDLE_WM_SYSTEMERROR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_SYSTEMERROR(hwnd, errCode, fn) \
    (void)(fn)((hwnd), WM_SYSTEMERROR, (WPARAM)(errCode), 0L)
#define HANDLE_WM_CREATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (CREATESTRUCT FAR*)(lParam)) ? 0L : (LRESULT)-1L)
#define FORWARD_WM_CREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_CREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_NCCREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (CREATESTRUCT FAR*)(lParam))
#define FORWARD_WM_NCCREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCCREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_DESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROY, 0, 0L)
#define HANDLE_WM_NCDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_NCDESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_NCDESTROY, 0, 0L)
#define HANDLE_WM_SHOWWINDOW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), LOWORD(lParam)), 0L)
#define HANDLE_WM_SETREDRAW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_SETREDRAW(hwnd, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETREDRAW, (WPARAM)(fRedraw), 0L)
#define HANDLE_WM_ENABLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENABLE(hwnd, fEnable, fn) \
    (void)(fn)((hwnd), WM_ENABLE, (WPARAM)(BOOL)(fEnable), 0L)
#define HANDLE_WM_SETTEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_SETTEXT(hwnd, lpszText, fn) \
    (void)(fn)((hwnd), WM_SETTEXT, 0, (LPARAM)(LPCSTR)(lpszText))
#define HANDLE_WM_GETTEXT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (int)(wParam), (LPSTR)(lParam))
#define FORWARD_WM_GETTEXT(hwnd, cchTextMax, lpszText, fn) \
    (int)(DWORD)(fn)((hwnd), WM_GETTEXT, (WPARAM)(int)(cchTextMax), (LPARAM)(LPSTR)(lpszText))
#define HANDLE_WM_GETTEXTLENGTH(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)(hwnd)
#define FORWARD_WM_GETTEXTLENGTH(hwnd, fn) \
    (int)(DWORD)(fn)((hwnd), WM_GETTEXTLENGTH, 0, 0L)
#define HANDLE_WM_WINDOWPOSCHANGING(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (WINDOWPOS FAR*)(lParam))
#define FORWARD_WM_WINDOWPOSCHANGING(hwnd, lpwpos, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_WINDOWPOSCHANGING, 0, (LPARAM)(WINDOWPOS FAR*)(lpwpos))
#define HANDLE_WM_WINDOWPOSCHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const WINDOWPOS FAR*)(lParam)), 0L)
#define FORWARD_WM_WINDOWPOSCHANGED(hwnd, lpwpos, fn) \
    (void)(fn)((hwnd), WM_WINDOWPOSCHANGED, 0, (LPARAM)(const WINDOWPOS FAR*)(lpwpos))
#define HANDLE_WM_MOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_MOVE(hwnd, x, y, fn) \
    (void)(fn)((hwnd), WM_MOVE, 0, MAKELPARAM((int)(x), (int)(y)))
#define HANDLE_WM_SIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_SIZE(hwnd, state, cx, cy, fn) \
    (void)(fn)((hwnd), WM_SIZE, (WPARAM)(UINT)(state), MAKELPARAM((int)(cx), (int)(cy)))
#define HANDLE_WM_QUERYOPEN(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYOPEN(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYOPEN, 0, 0L)
#define HANDLE_WM_GETMINMAXINFO(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MINMAXINFO FAR*)(lParam)), 0L)
#define FORWARD_WM_GETMINMAXINFO(hwnd, lpMinMaxInfo, fn) \
    (void)(fn)((hwnd), WM_GETMINMAXINFO, 0, (LPARAM)(MINMAXINFO FAR*)(lpMinMaxInfo))
#define HANDLE_WM_PAINT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PAINT(hwnd, fn) \
    (void)(fn)((hwnd), WM_PAINT, 0, 0L)
#define HANDLE_WM_ERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define FORWARD_WM_ERASEBKGND(hwnd, hdc, fn) \
   (BOOL)(DWORD)(fn)((hwnd), WM_ERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define HANDLE_WM_ICONERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define FORWARD_WM_ICONERASEBKGND(hwnd, hdc, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_ICONERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define HANDLE_WM_NCPAINT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HRGN)(wParam)), 0L)
#define FORWARD_WM_NCPAINT(hwnd, hrgn, fn) \
    (void)(fn)((hwnd), WM_NCPAINT, (WPARAM)(HRGN)(hrgn), 0L)
#define HANDLE_WM_NCCALCSIZE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (NCCALCSIZE_PARAMS FAR*)(lParam))
#define FORWARD_WM_NCCALCSIZE(hwnd, fCalcValidRects, lpcsp, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_NCCALCSIZE, (WPARAM)(fCalcValidRects), (LPARAM)(NCCALCSIZE_PARAMS FAR*)(lpcsp))
#define HANDLE_WM_NCHITTEST(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_NCHITTEST(hwnd, x, y, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_NCHITTEST, 0, MAKELPARAM((int)(x), (int)(y)))
#define HANDLE_WM_QUERYDRAGICON(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define FORWARD_WM_QUERYDRAGICON(hwnd, fn) \
    (HICON)(UINT)(DWORD)(fn)((hwnd), WM_QUERYDRAGICON, 0, 0L)
#define HANDLE_WM_DROPFILES(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HDROP)(wParam)), 0L)
#define FORWARD_WM_DROPFILES(hwnd, hdrop, fn) \
    (void)(fn)((hwnd), WM_DROPFILES, (WPARAM)(hdrop), 0L)
#define HANDLE_WM_ACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define FORWARD_WM_ACTIVATE(hwnd, state, hwndActDeact, fMinimized, fn) \
    (void)(fn)((hwnd), WM_ACTIVATE, (WPARAM)(UINT)(state), MAKELPARAM((UINT)(HWND)(hwndActDeact), (UINT)(BOOL)(fMinimized)))
#define HANDLE_WM_ACTIVATEAPP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (HTASK)LOWORD(lParam)), 0L)
#define FORWARD_WM_ACTIVATEAPP(hwnd, fActivate, htaskActDeact, fn) \
    (void)(fn)((hwnd), WM_ACTIVATEAPP, (WPARAM)(BOOL)(fActivate), MAKELPARAM((htaskActDeact),0))
#define HANDLE_WM_NCACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (BOOL)(wParam), (HWND)LOWORD(lParam), (BOOL)HIWORD(lParam))
#define FORWARD_WM_NCACTIVATE(hwnd, fActive, hwndActDeact, fMinimized, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCACTIVATE, (WPARAM)(BOOL)(fActive), MAKELPARAM((UINT)(HWND)(hwndActDeact), (UINT)(BOOL)(fMinimized)))
#define HANDLE_WM_SETFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_SETFOCUS(hwnd, hwndOldFocus, fn) \
    (void)(fn)((hwnd), WM_SETFOCUS, (WPARAM)(HWND)(hwndOldFocus), 0L)
#define HANDLE_WM_KILLFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_KILLFOCUS(hwnd, hwndNewFocus, fn) \
    (void)(fn)((hwnd), WM_KILLFOCUS, (WPARAM)(HWND)(hwndNewFocus), 0L)
#define HANDLE_WM_KEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_KEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_KEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_KEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_CHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_CHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_CHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define HANDLE_WM_DEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_DEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_DEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define HANDLE_WM_SYSKEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSKEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_SYSKEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSKEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_SYSCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_SYSCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define HANDLE_WM_SYSDEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_SYSDEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSDEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define HANDLE_WM_MOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MOUSEMOVE(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MOUSEMOVE, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_LBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_LBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_LBUTTONDBLCLK : WM_LBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_LBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_LBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_LBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_LBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_RBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_RBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_RBUTTONDBLCLK : WM_RBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_RBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_RBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_RBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_RBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_MBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_MBUTTONDBLCLK : WM_MBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_MBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_MBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCMOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMOUSEMOVE(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMOUSEMOVE, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCLBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCLBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCLBUTTONDBLCLK : WM_NCLBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCLBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCLBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCLBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCLBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCRBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCRBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCRBUTTONDBLCLK : WM_NCRBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCRBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCRBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCRBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCRBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCMBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCMBUTTONDBLCLK : WM_NCMBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCMBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCMBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_MOUSEACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))
#define FORWARD_WM_MOUSEACTIVATE(hwnd, hwndTopLevel, codeHitTest, msg, fn) \
    (int)(DWORD)(fn)((hwnd), WM_MOUSEACTIVATE, (WPARAM)(HWND)(hwndTopLevel), MAKELPARAM((codeHitTest), (msg)))
#define HANDLE_WM_CANCELMODE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CANCELMODE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CANCELMODE, 0, 0L)
#define HANDLE_WM_TIMER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_TIMER(hwnd, id, fn) \
    (void)(fn)((hwnd), WM_TIMER, (WPARAM)(UINT)(id), 0L)
#define HANDLE_WM_INITMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam)), 0L)
#define FORWARD_WM_INITMENU(hwnd, hMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENU, (WPARAM)(HMENU)(hMenu), 0L)
#define HANDLE_WM_INITMENUPOPUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam), (int)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define FORWARD_WM_INITMENUPOPUP(hwnd, hMenu, item, fSystemMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENUPOPUP, (WPARAM)(HMENU)(hMenu), MAKELPARAM((item),(fSystemMenu)))
#define HANDLE_WM_MENUSELECT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)HIWORD(lParam), (LOWORD(lParam) & MF_POPUP) ? 0 : (int)(wParam), \
                            (LOWORD(lParam) & MF_POPUP) ? (HMENU)(wParam) : 0, LOWORD(lParam)), 0L)
#define FORWARD_WM_MENUSELECT(hwnd, hmenu, item, hmenuPopup, flags, fn) \
    (void)(fn)((hwnd), WM_MENUSELECT, ((flags) & MF_POPUP) ? (WPARAM)(HMENU)(hmenuPopup) : (WPARAM)(int)(item), MAKELPARAM((flags), (hmenu)))
#define HANDLE_WM_MENUCHAR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam), LOWORD(lParam), (HMENU)HIWORD(lParam));
#define FORWARD_WM_MENUCHAR(hwnd, ch, flags, hmenu, fn) \
    (DWORD)(fn)((hwnd), WM_MENUCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((flags), (UINT)(hmenu)))
#define HANDLE_WM_COMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (HWND)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_COMMAND(hwnd, id, hwndCtl, codeNotify, fn) \
    (void)(fn)((hwnd), WM_COMMAND, (WPARAM)(int)(id), MAKELPARAM((UINT)(hwndCtl), (codeNotify)))
#define HANDLE_WM_HSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)HIWORD(lParam), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_HSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define HANDLE_WM_VSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)HIWORD(lParam), (UINT)(wParam),  (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_VSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define HANDLE_WM_CUT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CUT(hwnd, fn) \
    (void)(fn)((hwnd), WM_CUT, 0, 0L)
#define HANDLE_WM_COPY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_COPY(hwnd, fn) \
    (void)(fn)((hwnd), WM_COPY, 0, 0L)
#define HANDLE_WM_PASTE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PASTE(hwnd, fn) \
    (void)(fn)((hwnd), WM_PASTE, 0, 0L)
#define HANDLE_WM_CLEAR(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CLEAR(hwnd, fn) \
    (void)(fn)((hwnd), WM_CLEAR, 0, 0L)
#define HANDLE_WM_UNDO(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_UNDO(hwnd, fn) \
    (void)(fn)((hwnd), WM_UNDO, 0, 0L)
#define HANDLE_WM_RENDERFORMAT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HANDLE)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_RENDERFORMAT(hwnd, fmt, fn) \
    (HANDLE)(UINT)(DWORD)(fn)((hwnd), WM_RENDERFORMAT, (WPARAM)(UINT)(fmt), 0L)
#define HANDLE_WM_RENDERALLFORMATS(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_RENDERALLFORMATS(hwnd, fn) \
    (void)(fn)((hwnd), WM_RENDERALLFORMATS, 0, 0L)
#define HANDLE_WM_DESTROYCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROYCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROYCLIPBOARD, 0, 0L)
#define HANDLE_WM_DRAWCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DRAWCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DRAWCLIPBOARD, 0, 0L)
#define HANDLE_WM_PAINTCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const PAINTSTRUCT FAR*)GlobalLock((HGLOBAL)LOWORD(lParam))), GlobalUnlock((HGLOBAL)LOWORD(lParam)), 0L)
#define FORWARD_WM_PAINTCLIPBOARD(hwnd, hwndCBViewer, lpPaintStruct, fn) \
    (void)(fn)((hwnd), WM_PAINTCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(lpPaintStruct))
#define HANDLE_WM_SIZECLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const RECT FAR*)GlobalLock((HGLOBAL)LOWORD(lParam))), GlobalUnlock((HGLOBAL)LOWORD(lParam)), 0L)
#define FORWARD_WM_SIZECLIPBOARD(hwnd, hwndCBViewer, lprc, fn) \
    (void)(fn)((hwnd), WM_SIZECLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(lprc))
#define HANDLE_WM_VSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_VSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_HSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_HSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_ASKCBFORMATNAME(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (LPSTR)(lParam)), 0L)
#define FORWARD_WM_ASKCBFORMATNAME(hwnd, cchMax, rgchName, fn) \
    (void)(fn)((hwnd), WM_ASKCBFORMATNAME, (WPARAM)(int)(cchMax), (LPARAM)(rgchName))
#define HANDLE_WM_CHANGECBCHAIN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (HWND)LOWORD(lParam)), 0L)
#define FORWARD_WM_CHANGECBCHAIN(hwnd, hwndRemove, hwndNext, fn) \
    (void)(fn)((hwnd), WM_CHANGECBCHAIN, (WPARAM)(HWND)(hwndRemove), MAKELPARAM((UINT)(hwndNext), 0))
#define HANDLE_WM_SETCURSOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam));
#define FORWARD_WM_SETCURSOR(hwnd, hwndCursor, codeHitTest, msg, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_SETCURSOR, (WPARAM)(HWND)(hwndCursor), MAKELPARAM((codeHitTest), (msg)))
#define HANDLE_WM_SYSCOMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSCOMMAND(hwnd, cmd, x, y, fn) \
    (void)(fn)((hwnd), WM_SYSCOMMAND, (WPARAM)(UINT)(cmd), MAKELPARAM((x), (y)))
#define HANDLE_WM_MDICREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (MDICREATESTRUCT FAR*)(lParam))
#define FORWARD_WM_MDICREATE(hwnd, lpmcs, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDICREATE, 0, (LPARAM)(lpmcs))
#define HANDLE_WM_MDIDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIDESTROY(hwnd, hwndDestroy, fn) \
    (void)(fn)((hwnd), WM_MDIDESTROY, (WPARAM)(hwndDestroy), 0L)
#define HANDLE_WM_MDIACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (HWND)LOWORD(lParam), (HWND)HIWORD(lParam)), 0L)
#define FORWARD_WM_MDIACTIVATE(hwnd, fActive, hwndActivate, hwndDeactivate, fn) \
    (void)(fn)(hwnd, WM_MDIACTIVATE, (WPARAM)(fActive), MAKELPARAM((hwndActivate), (hwndDeactivate)))
#define HANDLE_WM_MDIRESTORE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIRESTORE(hwnd, hwndRestore, fn) \
    (void)(fn)((hwnd), WM_MDIRESTORE, (WPARAM)(hwndRestore), 0L)
#define HANDLE_WM_MDINEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (BOOL)LOWORD(lParam)), 0L)
#define FORWARD_WM_MDINEXT(hwnd, hwndCur, fPrev, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDINEXT, (WPARAM)(hwndCur), MAKELPARAM((fPrev), 0))
#define HANDLE_WM_MDIMAXIMIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIMAXIMIZE(hwnd, hwndMaximize, fn) \
    (void)(fn)((hwnd), WM_MDIMAXIMIZE, (WPARAM)(hwndMaximize), 0L)
#define HANDLE_WM_MDITILE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_MDITILE(hwnd, cmd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_MDITILE, (WPARAM)(cmd), 0L)
#define HANDLE_WM_MDICASCADE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_MDICASCADE(hwnd, cmd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_MDICASCADE, (WPARAM)(cmd), 0L)
#define HANDLE_WM_MDIICONARRANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_MDIICONARRANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_MDIICONARRANGE, 0, 0L)
#define HANDLE_WM_MDIGETACTIVE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define FORWARD_WM_MDIGETACTIVE(hwnd, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDIGETACTIVE, 0, 0L)
#define HANDLE_WM_MDISETMENU(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (HMENU)LOWORD(lParam), (HMENU)HIWORD(lParam))
#define FORWARD_WM_MDISETMENU(hwnd, fRefresh, hmenuFrame, hmenuWindow, fn) \
    (HMENU)(UINT)(DWORD)(fn)((hwnd), WM_MDISETMENU, (WPARAM)(fRefresh), MAKELPARAM((hmenuFrame), (hmenuWindow)))
#define HANDLE_WM_CHILDACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CHILDACTIVATE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CHILDACTIVATE, 0, 0L)
#define HANDLE_WM_NEXTDLGCTL(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HWND)(fn)((hwnd), (HWND)(wParam), (BOOL)LOWORD(lParam))
#define FORWARD_WM_NEXTDLGCTL(hwnd, hwndSetFocus, fNext, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_NEXTDLGCTL, (WPARAM)(HWND)(hwndSetFocus), MAKELPARAM((fNext), 0))
#define HANDLE_WM_PARENTNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_PARENTNOTIFY(hwnd, msg, hwndChild, idChild, fn) \
    (void)(fn)((hwnd), WM_PARENTNOTIFY, (WPARAM)(UINT)(msg), MAKELPARAM((UINT)(HWND)(hwndChild), (UINT)(idChild)))
#define HANDLE_WM_ENTERIDLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam)), 0L)
#define FORWARD_WM_ENTERIDLE(hwnd, source, hwndSource, fn) \
    (void)(fn)((hwnd), WM_ENTERIDLE, (WPARAM)(UINT)(source), MAKELPARAM((UINT)(HWND)(hwndSource), 0))
#define HANDLE_WM_GETDLGCODE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd, (MSG FAR*)(lParam))
#define FORWARD_WM_GETDLGCODE(hwnd, lpmsg, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_GETDLGCODE, (SELECTOROF(lpmsg) ? lpmsg->wParam : 0), (LPARAM)(lpmsg))
#define HANDLE_WM_CTLCOLOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)LOWORD(lParam), (int)(HIWORD(lParam)))
#define FORWARD_WM_CTLCOLOR(hwnd, hdc, hwndChild, type, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLOR, (WPARAM)(HDC)(hdc), MAKELPARAM((UINT)(HWND)(hwndChild), (UINT)(int)(type)))
#define HANDLE_WM_SETFONT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HFONT)(wParam), (BOOL)LOWORD(lParam)), 0L)
#define FORWARD_WM_SETFONT(hwnd, hfont, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETFONT, (WPARAM)(HFONT)(hfont), MAKELPARAM((UINT)(BOOL)(fRedraw), 0))
#define HANDLE_WM_GETFONT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HFONT)(fn)(hwnd)
#define FORWARD_WM_GETFONT(hwnd, fn) \
    (HFONT)(UINT)(DWORD)(fn)((hwnd), WM_GETFONT, 0, 0L)
#define HANDLE_WM_DRAWITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DRAWITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_DRAWITEM(hwnd, lpDrawItem, fn) \
    (void)(fn)((hwnd), WM_DRAWITEM, 0, (LPARAM)(const DRAWITEMSTRUCT FAR*)(lpDrawItem))
#define HANDLE_WM_MEASUREITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MEASUREITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_MEASUREITEM(hwnd, lpMeasureItem, fn) \
    (void)(fn)((hwnd), WM_MEASUREITEM, 0, (LPARAM)(MEASUREITEMSTRUCT FAR*)(lpMeasureItem))
#define HANDLE_WM_COMPAREITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (const COMPAREITEMSTRUCT FAR*)(lParam))
#define FORWARD_WM_COMPAREITEM(hwnd, lpCompareItem, fn) \
    (int)(DWORD)(fn)((hwnd), WM_COMPAREITEM, 0, (LPARAM)(const COMPAREITEMSTRUCT FAR*)(lpCompareItem))
#define HANDLE_WM_VKEYTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_VKEYTOITEM(hwnd, vk, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_VKEYTOITEM, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(hwndListBox), (UINT)(iCaret)))
#define HANDLE_WM_CHARTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_CHARTOITEM(hwnd, ch, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_CHARTOITEM, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(hwndListBox), (UINT)(iCaret)))
#define HANDLE_WM_QUEUESYNC(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_QUEUESYNC(hwnd, fn) \
    (void)(fn)((hwnd), WM_QUEUESYNC, 0, 0L)
#define HANDLE_WM_COMMNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), LOWORD(lParam)), 0L)
#define FORWARD_WM_COMMNOTIFY(hwnd, cid, flags, fn) \
    (void)(fn)((hwnd), WM_COMMNOTIFY, (WPARAM)(cid), MAKELPARAM((flags), 0))
#define Static_SetIcon(hwndCtl, hIcon)          ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_SETICON, (WPARAM)(HICON)(hIcon), 0L))
#define Static_GetIcon(hwndCtl, hIcon)          ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_GETICON, 0, 0L))
#define Button_GetCheck(hwndCtl)            ((int)(DWORD)SendMessage((hwndCtl), BM_GETCHECK, 0, 0L))
#define Button_SetCheck(hwndCtl, check)     ((void)SendMessage((hwndCtl), BM_SETCHECK, (WPARAM)(int)(check), 0L))
#define Button_GetState(hwndCtl)            ((int)(DWORD)SendMessage((hwndCtl), BM_GETSTATE, 0, 0L))
#define Button_SetState(hwndCtl, state)     ((UINT)(DWORD)SendMessage((hwndCtl), BM_SETSTATE, (WPARAM)(int)(state), 0L))
#define Button_SetStyle(hwndCtl, style, fRedraw) ((void)SendMessage((hwndCtl), BM_SETSTYLE, (WPARAM)LOWORD(style), MAKELPARAM(((fRedraw) ? TRUE : FALSE), 0)))
#define Edit_LimitText(hwndCtl, cchMax)         ((void)SendMessage((hwndCtl), EM_LIMITTEXT, (WPARAM)(cchMax), 0L))
#define Edit_GetLineCount(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINECOUNT, 0, 0L))
#define Edit_GetLine(hwndCtl, line, lpch, cchMax) ((*((int FAR*)(lpch)) = (cchMax)), ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINE, (WPARAM)(int)(line), (LPARAM)(LPSTR)(lpch))))
#define Edit_GetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_GETRECT, 0, (LPARAM)(RECT FAR*)(lprc)))
#define Edit_SetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_SETRECT, 0, (LPARAM)(const RECT FAR*)(lprc)))
#define Edit_SetRectNoPaint(hwndCtl, lprc)      ((void)SendMessage((hwndCtl), EM_SETRECTNP, 0, (LPARAM)(const RECT FAR*)(lprc)))
#define Edit_GetSel(hwndCtl)                    ((DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L))
#define Edit_SetSel(hwndCtl, ichStart, ichEnd)  ((void)SendMessage((hwndCtl), EM_SETSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define Edit_ReplaceSel(hwndCtl, lpszReplace)   ((void)SendMessage((hwndCtl), EM_REPLACESEL, 0, (LPARAM)(LPCSTR)(lpszReplace)))
#define Edit_GetModify(hwndCtl)                 ((BOOL)(DWORD)SendMessage((hwndCtl), EM_GETMODIFY, 0, 0L))
#define Edit_SetModify(hwndCtl, fModified)      ((void)SendMessage((hwndCtl), EM_SETMODIFY, (WPARAM)(UINT)(fModified), 0L))
#define Edit_LineFromChar(hwndCtl, ich)         ((int)(DWORD)SendMessage((hwndCtl), EM_LINEFROMCHAR, (WPARAM)(int)(ich), 0L))
#define Edit_LineIndex(hwndCtl, line)           ((int)(DWORD)SendMessage((hwndCtl), EM_LINEINDEX, (WPARAM)(int)(line), 0L))
#define Edit_LineLength(hwndCtl, line)          ((int)(DWORD)SendMessage((hwndCtl), EM_LINELENGTH, (WPARAM)(int)(line), 0L))
#define Edit_Scroll(hwndCtl, dv, dh)            ((void)SendMessage((hwndCtl), EM_LINESCROLL, 0, MAKELPARAM((dv), (dh))))
#define Edit_CanUndo(hwndCtl)                   ((BOOL)(DWORD)SendMessage((hwndCtl), EM_CANUNDO, 0, 0L))
#define Edit_Undo(hwndCtl)                      ((BOOL)(DWORD)SendMessage((hwndCtl), EM_UNDO, 0, 0L))
#define Edit_EmptyUndoBuffer(hwndCtl)           ((void)SendMessage((hwndCtl), EM_EMPTYUNDOBUFFER, 0, 0L))
#define Edit_SetPasswordChar(hwndCtl, ch)       ((void)SendMessage((hwndCtl), EM_SETPASSWORDCHAR, (WPARAM)(UINT)(ch), 0L))
#define Edit_SetTabStops(hwndCtl, cTabs, lpTabs) ((void)SendMessage((hwndCtl), EM_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(const int FAR*)(lpTabs)))
#define Edit_FmtLines(hwndCtl, fAddEOL)         ((BOOL)(DWORD)SendMessage((hwndCtl), EM_FMTLINES, (WPARAM)(BOOL)(fAddEOL), 0L))
#define Edit_GetHandle(hwndCtl)                 ((HLOCAL)(UINT)(DWORD)SendMessage((hwndCtl), EM_GETHANDLE, 0, 0L))
#define Edit_SetHandle(hwndCtl, h)              ((void)SendMessage((hwndCtl), EM_SETHANDLE, (WPARAM)(UINT)(HLOCAL)(h), 0L))
#define Edit_GetFirstVisibleLine(hwndCtl)       ((int)(DWORD)SendMessage((hwndCtl), EM_GETFIRSTVISIBLELINE, 0, 0L))
#define Edit_SetReadOnly(hwndCtl, fReadOnly)    ((BOOL)(DWORD)SendMessage((hwndCtl), EM_SETREADONLY, (WPARAM)(BOOL)(fReadOnly), 0L))
#define Edit_GetPasswordChar(hwndCtl)           ((char)(DWORD)SendMessage((hwndCtl), EM_GETPASSWORDCHAR, 0, 0L))
#define Edit_SetWordBreakProc(hwndCtl, lpfnWordBreak) ((void)SendMessage((hwndCtl), EM_SETWORDBREAKPROC, 0, (LPARAM)(EDITWORDBREAKPROC)(lpfnWordBreak)))
#define Edit_GetWordBreakProc(hwndCtl)          ((EDITWORDBREAKPROC)SendMessage((hwndCtl), EM_GETWORDBREAKPROC, 0, 0L))
#define ListBox_GetCount(hwndCtl)                   ((int)(DWORD)SendMessage((hwndCtl), LB_GETCOUNT, 0, 0L))
#define ListBox_ResetContent(hwndCtl)               ((BOOL)(DWORD)SendMessage((hwndCtl), LB_RESETCONTENT, 0, 0L))
#define ListBox_AddString(hwndCtl, lpsz)            ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0, (LPARAM)(LPCSTR)(lpsz)))
#define ListBox_InsertString(hwndCtl, index, lpsz)  ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpsz)))
#define ListBox_AddItemData(hwndCtl, data)          ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0, (LPARAM)(data)))
#define ListBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_GetTextLen(hwndCtl, index)          ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXTLEN, (WPARAM)(int)(index), 0L))
#define ListBox_GetText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXT, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpszBuffer)))
#define ListBox_GetItemData(hwndCtl, index)         ((LRESULT)(DWORD)SendMessage((hwndCtl), LB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ListBox_SetItemData(hwndCtl, index, data)   ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_FindString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_FindItemData(hwndCtl, indexStart, data) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_SetSel(hwndCtl, fSelect, index)     ((int)(DWORD)SendMessage((hwndCtl), LB_SETSEL, (WPARAM)(BOOL)(fSelect), MAKELPARAM((index), 0)))
#define ListBox_SelItemRange(hwndCtl, fSelect, first, last)    ((int)(DWORD)SendMessage((hwndCtl), LB_SELITEMRANGE, (WPARAM)(BOOL)(fSelect), MAKELPARAM((first), (last))))
#define ListBox_GetCurSel(hwndCtl)                  ((int)(DWORD)SendMessage((hwndCtl), LB_GETCURSEL, 0, 0L))
#define ListBox_SetCurSel(hwndCtl, index)           ((int)(DWORD)SendMessage((hwndCtl), LB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ListBox_SelectString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_SelectItemData(hwndCtl, indexStart, data)   ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_GetSel(hwndCtl, index)              ((int)(DWORD)SendMessage((hwndCtl), LB_GETSEL, (WPARAM)(int)(index), 0L))
#define ListBox_GetSelCount(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELCOUNT, 0, 0L))
#define ListBox_GetTopIndex(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), LB_GETTOPINDEX, 0, 0L))
#define ListBox_GetSelItems(hwndCtl, cItems, lpItems) ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELITEMS, (WPARAM)(int)(cItems), (LPARAM)(int FAR*)(lpItems)))
#define ListBox_SetTopIndex(hwndCtl, indexTop)      ((int)(DWORD)SendMessage((hwndCtl), LB_SETTOPINDEX, (WPARAM)(int)(indexTop), 0L))
#define ListBox_SetColumnWidth(hwndCtl, cxColumn)   ((void)SendMessage((hwndCtl), LB_SETCOLUMNWIDTH, (WPARAM)(int)(cxColumn), 0L))
#define ListBox_GetHorizontalExtent(hwndCtl)        ((int)(DWORD)SendMessage((hwndCtl), LB_GETHORIZONTALEXTENT, 0, 0L))
#define ListBox_SetHorizontalExtent(hwndCtl, cxExtent)     ((void)SendMessage((hwndCtl), LB_SETHORIZONTALEXTENT, (WPARAM)(int)(cxExtent), 0L))
#define ListBox_SetTabStops(hwndCtl, cTabs, lpTabs) ((BOOL)(DWORD)SendMessage((hwndCtl), LB_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(int FAR*)(lpTabs)))
#define ListBox_GetItemRect(hwndCtl, index, lprc)   ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMRECT, (WPARAM)(int)(index), (LPARAM)(RECT FAR*)(lprc)))
#define ListBox_SetCaretIndex(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), LB_SETCARETINDEX, (WPARAM)(int)(index), 0L))
#define ListBox_GetCaretIndex(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), LB_GETCARETINDEX, 0, 0L))
#define ListBox_SetAnchorIndex(hwndCtl, index)      ((void)SendMessage((hwndCtl), LB_SETANCHORINDEX, (WPARAM)(int)(index), 0L))            /* ;Internal */
#define ListBox_GetAnchorIndex(hwndCtl)             ((int)(DWORD)SendMessage((hwndCtl), LB_GETANCHORINDEX, 0, 0L))                        /* ;Internal */
#define ListBox_FindStringExact(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_SetItemHeight(hwndCtl, index, cy)   ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMHEIGHT, (WPARAM)(int)(index), MAKELPARAM((cy), 0)))
#define ListBox_GetItemHeight(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMHEIGHT, (WPARAM)(int)(index), 0L))
#define ListBox_Dir(hwndCtl, attrs, lpszFileSpec)   ((int)(DWORD)SendMessage((hwndCtl), LB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCSTR)(lpszFileSpec)))
#define ListBox_AddFile(hwndCtl, lpszFilename)      ((int)(DWORD)SendMessage((hwndCtl), LB_ADDFILE, 0, (LPARAM)(LPCSTR)(lpszFilename)))    /* ;Internal */
#define ComboBox_Enable(hwndCtl, fEnable)       EnableWindow((hwndCtl), (fEnable))
#define ComboBox_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))
#define ComboBox_GetTextLength(hwndCtl)         GetWindowTextLength(hwndCtl)
#define ComboBox_SetText(hwndCtl, lpsz)         SetWindowText((hwndCtl), (lpsz))
#define ComboBox_LimitText(hwndCtl, cchLimit)   ((int)(DWORD)SendMessage((hwndCtl), CB_LIMITTEXT, (WPARAM)(int)(cchLimit), 0L))
#define ComboBox_GetEditSel(hwndCtl)            ((DWORD)SendMessage((hwndCtl), CB_GETEDITSEL, 0, 0L))
#define ComboBox_SetEditSel(hwndCtl, ichStart, ichEnd) ((int)(DWORD)SendMessage((hwndCtl), CB_SETEDITSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define ComboBox_GetCount(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), CB_GETCOUNT, 0, 0L))
#define ComboBox_ResetContent(hwndCtl)          ((int)(DWORD)SendMessage((hwndCtl), CB_RESETCONTENT, 0, 0L))
#define ComboBox_AddString(hwndCtl, lpsz)       ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_InsertString(hwndCtl, index, lpsz) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_AddItemData(hwndCtl, data)     ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(data)))
#define ComboBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_GetLBTextLen(hwndCtl, index)           ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXTLEN, (WPARAM)(int)(index), 0L))
#define ComboBox_GetLBText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXT, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpszBuffer)))
#define ComboBox_GetItemData(hwndCtl, index)        ((LRESULT)(DWORD)SendMessage((hwndCtl), CB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ComboBox_SetItemData(hwndCtl, index, data)  ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_FindString(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ComboBox_FindItemData(hwndCtl, indexStart, data)    ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_GetCurSel(hwndCtl)                 ((int)(DWORD)SendMessage((hwndCtl), CB_GETCURSEL, 0, 0L))
#define ComboBox_SetCurSel(hwndCtl, index)          ((int)(DWORD)SendMessage((hwndCtl), CB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ComboBox_SelectString(hwndCtl, indexStart, lpszSelect)  ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszSelect)))
#define ComboBox_SelectItemData(hwndCtl, indexStart, data)      ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_Dir(hwndCtl, attrs, lpszFileSpec)  ((int)(DWORD)SendMessage((hwndCtl), CB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCSTR)(lpszFileSpec)))
#define ComboBox_ShowDropdown(hwndCtl, fShow)       ((BOOL)(DWORD)SendMessage((hwndCtl), CB_SHOWDROPDOWN, (WPARAM)(BOOL)(fShow), 0L))
#define ComboBox_FindStringExact(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ComboBox_GetDroppedState(hwndCtl)           ((BOOL)(DWORD)SendMessage((hwndCtl), CB_GETDROPPEDSTATE, 0, 0L))
#define ComboBox_GetDroppedControlRect(hwndCtl, lprc) ((void)SendMessage((hwndCtl), CB_GETDROPPEDCONTROLRECT, 0, (LPARAM)(RECT FAR*)(lprc)))
#define ComboBox_GetItemHeight(hwndCtl)             ((int)(DWORD)SendMessage((hwndCtl), CB_GETITEMHEIGHT, 0, 0L))
#define ComboBox_SetItemHeight(hwndCtl, cyItem)     ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMHEIGHT, (WPARAM)(int)(index), 0L))
#define ComboBox_GetExtendedUI(hwndCtl)             ((UINT)(DWORD)SendMessage((hwndCtl), CB_GETEXTENDEDUI, 0, 0L))
#define ComboBox_SetExtendedUI(hwndCtl, flags)      ((int)(DWORD)SendMessage((hwndCtl), CB_SETEXTENDEDUI, (WPARAM)(UINT)(flags), 0L))

// base\mvdm\wow16\mmsystem\idrv.h
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)    \
        ((DWORD)SendMessage((hwndCtl), EM_GETSEL, (WPARAM)pnS, (LPARAM)pnE))
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)                        \
    {                                                               \
        DWORD   dw;                                                 \
        dw = (DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L);       \
        *pnE = (int)HIWORD(dw);                                     \
        *pnS = (int)LOWORD(dw);                                     \
    }
    #define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)LOWORD(lp)
    #define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)      (WPARAM)(s), MAKELONG(hwnd, fmin)
    #define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd)    (WPARAM)(ch), MAKELONG(hwnd, pos)
    #define GET_WM_COMMAND_HWND(wp, lp)             (HWND)LOWORD(lp)
    #define GET_WM_COMMAND_MPS(id, hwnd, cmd)       (WPARAM)(id), MAKELONG(hwnd, cmd)
    #define GET_WM_CTLCOLOR_HWND(wp, lp, msg)       (HWND)LOWORD(lp)
    #define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type)    (WPARAM)(hdc), MAKELONG(hwnd, type)
    #define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
    #define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
    #define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
    #define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA) (WPARAM)(hwndA), 0
    #define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd)  (WPARAM)(msg), MAKELONG(hwnd, id)
    #define GET_WM_VKEYTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) (WPARAM)(code), MAKELONG(hwnd, item)
    #define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_HSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_HSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)
    #define GET_WM_VSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_VSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)

// base\mvdm\wow16\user\user.h
#define TestWF(hwnd, flag)   ((BYTE)*((BYTE *)(&(hwnd)->state) + HIBYTE(flag)) & (BYTE)LOBYTE(flag))
#define SetWF(hwnd, flag)    ((BYTE)*((BYTE *)(&(hwnd)->state) + HIBYTE(flag)) |= (BYTE)LOBYTE(flag))
#define ClrWF(hwnd, flag)    ((BYTE)*((BYTE *)(&(hwnd)->state) + HIBYTE(flag)) &= ~(BYTE)LOBYTE(flag))
#define TestCF(hwnd, flag)   (*((BYTE *)(&(hwnd)->pcls->style) + HIBYTE(flag)) & LOBYTE(flag))
#define SetCF(hwnd, flag)    (*((BYTE *)(&(hwnd)->pcls->style) + HIBYTE(flag)) |= LOBYTE(flag))
#define ClrCF(hwnd, flag)    (*((BYTE *)(&(hwnd)->pcls->style) + HIBYTE(flag)) &= ~LOBYTE(flag))
#define TestwndPopup(hwnd)   (TestwndNIPopup(hwnd) || TestwndIPopup(hwnd))
#define TestwndHI(hwnd)      (TestwndTiled(hwnd) || TestwndIPopup(hwnd))
#define NEEDSPAINT(hwnd)    (hwnd->hrgnUpdate != NULL || TestWF(hwnd, WFINTERNALPAINT))
#define RedrawScreen()              \
    InternalInvalidate(hwndDesktop, (HRGN)1,   \
        RDW_INVALIDATE | RDW_ERASE | RDW_FRAME | RDW_ALLCHILDREN)
#define InternalGetClientRect(hwnd, lprc)   CopyRect(lprc, &hwnd->rcClient)

// base\mvdm\wow16\wfwnet\locals.h
#define TO_HWND32(x)     (0xFFFF0000 | (DWORD)x)

// base\mvdm\wow16\write\commdlg.c
#define hPARENTWINDOW  ((vhWndMsgBoxParent == NULL) ? \
                    hParentWw : vhWndMsgBoxParent)

// base\mvdm\wow16\write\diaalert.c
#define FInModeless(hWnd) (hWnd == vhDlgFind || hWnd == vhDlgChange || \
 hWnd == vhDlgRunningHead)

// base\mvdm\wow16\write\obj.h
#define hPARENTWINDOW  ((vhWndMsgBoxParent == NULL) ? \
                    hParentWw : vhWndMsgBoxParent)

// base\mvdm\wow32\walias.h
#define GETICLASS(pww, hwnd) (                                                 \
(((((PWW)pww)->fnid & 0xfff) >= FNID_START) &&                                 \
                                   ((((PWW)pww)->fnid & 0xfff) <= FNID_END)) ? \
    (pfnOut.aiWowClass[(((PWW)pww)->fnid & 0xfff) - FNID_START]) :             \
((((PWW)pww)->state2 & WINDOW_IS_INITIALIZED) ?                                \
    WOWCLASS_WIN16 : GetiClassTheHardWay(hwnd)) )

// base\mvdm\wow32\wowhooks.h
#define PUTMSGFILTER16(pMsg16,lpMsg) {\
        STOREWORD(pMsg16->hwnd, GETHWND16((lpMsg)->hwnd));\
        STOREWORD(pMsg16->message,  (lpMsg)->message);\
        STOREWORD(pMsg16->wParam,   (lpMsg)->wParam);\
        STORELONG(pMsg16->lParam,   (lpMsg)->lParam);\
        STORELONG(pMsg16->time, (lpMsg)->time);\
        STOREWORD(pMsg16->pt.x, (lpMsg)->pt.x);\
        STOREWORD(pMsg16->pt.y, (lpMsg)->pt.y);\
    }
#define GETMSGFILTER16(pMsg16,lpMsg) {\
        (lpMsg)->hwnd      = HWND32(FETCHWORD(pMsg16->hwnd));\
        (lpMsg)->message   = FETCHWORD(pMsg16->message);\
        (lpMsg)->wParam    = FETCHWORD(pMsg16->wParam);\
        (lpMsg)->lParam    = FETCHLONG(pMsg16->lParam);\
        (lpMsg)->time      = FETCHLONG(pMsg16->time);\
        (lpMsg)->pt.x      = FETCHSHORT(pMsg16->pt.x);\
        (lpMsg)->pt.y      = FETCHSHORT(pMsg16->pt.y);\
    }
#define PUTMOUSEHOOKSTRUCT16(pMHStruct16,lpMHStruct) {\
        STOREWORD(pMHStruct16->pt.x, (lpMHStruct)->pt.x);\
        STOREWORD(pMHStruct16->pt.y, (lpMHStruct)->pt.y);\
        STOREWORD(pMHStruct16->hwnd, GETHWND16((lpMHStruct)->hwnd));\
        STOREWORD(pMHStruct16->wHitTestCode,   (lpMHStruct)->wHitTestCode);\
        STORELONG(pMHStruct16->dwExtraInfo,   (lpMHStruct)->dwExtraInfo);\
    }
#define GETMOUSEHOOKSTRUCT16(pMHStruct16,lpMHStruct) {\
        (lpMHStruct)->pt.x        = FETCHSHORT(pMHStruct16->pt.x);\
        (lpMHStruct)->pt.y        = FETCHSHORT(pMHStruct16->pt.y);\
        (lpMHStruct)->hwnd           = HWND32(FETCHWORD(pMHStruct16->hwnd));\
        (lpMHStruct)->wHitTestCode   = FETCHWORD(pMHStruct16->wHitTestCode);\
        (lpMHStruct)->dwExtraInfo    = FETCHLONG(pMHStruct16->dwExtraInfo);\
    }
#define PUTCBTACTIVATESTRUCT16(pCbtAStruct16,lpCbtAStruct) {\
     STOREWORD(pCbtAStruct16->fMouse,  (lpCbtAStruct)->fMouse);\
     STOREWORD(pCbtAStruct16->hWndActive, (GETHWND16((lpCbtAStruct)->hWndActive)));\
    }
#define GETCBTACTIVATESTRUCT16(pCbtAStruct16,lpCbtAStruct) {\
     (lpCbtAStruct)->fMouse = FETCHWORD(pCbtAStruct16->fMouse);\
     (lpCbtAStruct)->hWndActive = HWND32(FETCHWORD(pCbtAStruct16->hWndActive));\
    }

// base\ntsetup\hwdb\utils\inc\strings.h
#define YesNoBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_YESNO|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define YesNoCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_YESNOCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define OkBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_OK|MB_ICONINFORMATION|MB_SETFOREGROUND,NULL)
#define OkCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_OKCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define RetryCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_RETRYCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)

// base\ntsetup\legacy\dll\comstf.h
#define  MessBoxSzSz(szTitle, szText) \
                MessageBox((HWND)NULL, (LPSTR)szText, (LPSTR)szTitle, \
                                MB_TASKMODAL | MB_ICONHAND | MB_OK)

// base\ntsetup\migdlls\src\utils\inc\strings.h
#define YesNoBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_YESNO|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define YesNoCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_YESNOCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define OkBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_OK|MB_ICONINFORMATION|MB_SETFOREGROUND,NULL)
#define OkCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_OKCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define RetryCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_RETRYCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)

// base\ntsetup\opktools\setupmgr\include\wizard.h
#define WIZ_CANCEL(hwnd) \
            ( ( (GET_FLAG(OPK_EXIT)) || (MsgBox(GetParent(hwnd), IDS_WARN_CANCEL_WIZARD, IDS_WIZARD_TITLE, MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON2 ) == IDYES) ) ? \
            ( (WIZ_RESULT(hwnd, 0)) ? TRUE : TRUE ) : \
            ( (WIZ_RESULT(hwnd, -1)) ? FALSE : FALSE ) )
#define WIZ_HELP() \
            g_App.hwndHelp = HtmlHelp(NULL, g_App.szHelpFile, HH_HELP_CONTEXT, GET_FLAG(OPK_OEM) ? g_App.dwCurrentHelp+200 : g_App.dwCurrentHelp)

// base\ntsetup\syssetup\ps2ppg.c
#define UpDown_GetPos(hwndUD)                                   \
    (DWORD) SendMessage((hwndUD), UDM_GETPOS, (WPARAM) 0, (LPARAM) 0)
#define UpDown_SetPos(hwndUD, nPos)                             \
    (short) SendMessage((hwndUD), UDM_SETPOS, (WPARAM) 0,       \
                        (LPARAM) MAKELONG((short) (nPos), 0) )
#define UpDown_SetAccel(hwndUD, nCount, pAccels)                \
    (BOOL) SendMessage((hwndUD), UDM_SETACCEL, (WPARAM) nCount, \
                        (LPARAM) pAccels)

// base\ntsetup\win95upg\inc\strings.h
#define YesNoBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_YESNO|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define YesNoCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_YESNOCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define OkBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_OK|MB_ICONINFORMATION|MB_SETFOREGROUND,NULL)
#define OkCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_OKCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define RetryCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_RETRYCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)

// base\ntsetup\winnt32\dll\winnt32.h
#define HideWindow(_hwnd)   SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)&~WS_VISIBLE)
#define UnHideWindow(_hwnd) SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)|WS_VISIBLE)

// base\remoteboot\riprep\compat.cpp
#define HideWindow(_hwnd)   SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)&~WS_VISIBLE)
#define UnHideWindow(_hwnd) SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)|WS_VISIBLE)

// base\screg\winreg\cntrtext\showperf\showperf.h
#define SEND_WM_COMMAND(w,c,n,cw)  SendMessage (w, WM_COMMAND, MAKEWPARAM(c,n), (LPARAM)cw)

// base\subsys\sm\sfc\dll\sfcp.h
#define HideWindow(_hwnd)   SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)&~WS_VISIBLE)

// base\win32\fusion\tools\sxspad\sxspad.c
#define DeepTrouble() MessageBox(hwndSP, szErrSpace, szNN, MB_SYSTEMMODAL|MB_OK|MB_ICONHAND);

// com\mobile\syncmgr\dll\precomp.h
#define ListView_GetSelectionMark(hwnd) \
    (int)SNDMSG((hwnd), LVM_GETSELECTIONMARK, 0, 0)

// com\mobile\syncmgr\exe\dlg.h
#define BASEDLG_SHOWWINDOW(hwnd,nCmdShow) SendMessage(hwnd,WM_BASEDLG_SHOWWINDOW,nCmdShow,0);

// com\mobile\syncmgr\exe\precomp.h
#define ListView_GetSelectionMark(hwnd) \
    (int)SNDMSG((hwnd), LVM_GETSELECTIONMARK, 0, 0)

// com\mobile\syncmgr\h\util.hxx
#define UpDown_SetPos(hCtrl, sPos)          (SHORT)SendMessage((hCtrl), UDM_SETPOS, 0, (LPARAM) MAKELONG((short) sPos, 0))
#define UpDown_GetPos(hCtrl)                (SHORT)SendMessage((hCtrl), UDM_GETPOS, 0, 0)
#define TASK_WEEKDAYS       (TASK_MONDAY    | \
                             TASK_TUESDAY   | \
                             TASK_WEDNESDAY | \
                             TASK_THURSDAY  | \
                             TASK_FRIDAY)

// com\mobile\syncmgr\h\widewrap.h
#define SendDlgItemMessage(h,id,msg,wp,lp) SendMessageA(GetDlgItem(h,id),msg,wp,lp)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\core\stub.c
#define GetStubTypeDescriptor(pcs)     (&(Mrgcstd[pcs->st]))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\brfprv.h
#define MB_WARNING  (MB_OK | MB_ICONWARNING)
#define MB_INFO     (MB_OK | MB_ICONINFORMATION)
#define MB_ERROR    (MB_OK | MB_ICONERROR)
#define MB_QUESTION (MB_YESNO | MB_ICONQUESTION)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\cache.h
#define CRL_Init()                      Cache_Init(&g_cacheCRL)
#define CRL_InitCS()                    Cache_InitCS(&g_cacheCRL)
#define CPATH_Init()                    Cache_Init(&g_cacheCPATH)
#define CPATH_InitCS()                  Cache_InitCS(&g_cacheCPATH)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\comm.h
#define SetDlgHandle(hwnd, msg, lp)     if((msg)==WM_SETFONT) (lp)->hdlg=(hwnd);

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\da.c
#define IsDSA(pdsa) ((pdsa) && (pdsa)->magic == DSA_MAGIC)
#define IsDPA(pdpa) ((pdpa) && (pdpa)->magic == DPA_MAGIC)
#define SortCompare(psp, pp1, i1, pp2, i2) \
        (psp->pfnCmp(pp1[i1], pp2[i2], psp->lParam))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\err.h
#define GET_TR(hr)              ((TWINRESULT)((hr) & 0x0000FFFF) - TR_DELTAVALUE)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\comctrlp.h
#define TB_SETBUTTONTYPE        (WM_USER + 34)
#define SB_SETBORDERS           (WM_USER+5)
#define BL_ADDBUTTON            (WM_USER+1)
#define BL_GETCARETINDEX        (WM_USER+3)
#define BL_GETCURSEL            (WM_USER+5)
#define BL_GETITEMDATA          (WM_USER+6)
#define BL_GETTOPINDEX          (WM_USER+10)
#define BL_INSERTBUTTON         (WM_USER+11)
#define BL_RESETCONTENT         (WM_USER+12)
#define BL_SETCARETINDEX        (WM_USER+13)
#define BL_SETCURSEL            (WM_USER+14)
#define BL_SETITEMDATA          (WM_USER+15)
#define BL_SETTOPINDEX          (WM_USER+16)
#define TabCtrl_GetBkColor(hwnd)  (COLORREF)SNDMSG((hwnd), TCM_GETBKCOLOR, 0, 0L)
#define TabCtrl_SetBkColor(hwnd, clrBk)  (BOOL)SNDMSG((hwnd), TCM_SETBKCOLOR, 0, (LPARAM)(COLORREF)(clrBk))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\shellp.h
#define ShellFolderView_GetAnchorPoint(_hwnd, _fStart, _ppt) \
        (BOOL)((_fStart) ? ShellFolderView_GetDragPoint(_hwnd, _ppt) : ShellFolderView_GetDropPoint(_hwnd, _ppt))
#define ShellFolderView_SetItemPos(_hwnd, _pidl, _x, _y) \
{       SFV_SETITEMPOS _sip = {_pidl, {_x, _y}}; \
        SHShellFolderView_Message(_hwnd, SFVM_SETITEMPOS, (LPARAM)(LPSFV_SETITEMPOS)&_sip);}
#define SVM_SELECTITEM                  (WM_USER + 1)
#define SVM_MOVESELECTEDITEMS           (WM_USER + 2)
#define SVM_GETITEMPOSITION             (WM_USER + 4)
#define SVM_SELECTANDPOSITIONITEM       (WM_USER + 5)
#define PRF_TRYPROGRAMEXTENSIONS    (0x0002 | PRF_VERIFYEXISTS)		  /* ;Internal */

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\shlobj.h
#define FileCabinet_GetSetCurrentInfo(_hwnd, _bSet, _lpfs)                  /* ;Internal */ \
	SendMessage(_hwnd, CWM_GETSETCURRENTINFO, (WPARAM)(_bSet),          /* ;Internal */ \
	(LPARAM)(LPFOLDERSETTINGS)_lpfs)                                     /* ;Internal */
#define FileCabinet_SelectItem(_hwnd, _sel, _item)                          /* ;Internal */ \
    SendMessage(_hwnd, CWM_SELECTITEM, _sel, (LPARAM)(LPCITEMIDLIST)(_item)) /* ;Internal */
#define FileCabinet_SelectPath(_hwnd, _sel, _path)                          /* ;Internal */ \
	SendMessage(_hwnd, CWM_SELECTPATH, _sel, (LPARAM)(LPCSTR)(_path))    /* ;Internal */
#define FileCabinet_GetIShellBrowser(_hwnd)                                 /* ;Internal */ \
	(IShellBrowser  *)SendMessage(_hwnd, CWM_GETISHELLBROWSER, 0, 0L)    /* ;Internal */

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\shsemip.h
#define DRIVEID(path)   ((path[0] - 'A') & 31)
#define PRF_TRYPROGRAMEXTENSIONS    (0x0002 | PRF_VERIFYEXISTS)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\trayp.h
#define TM_POSTEDRCLICK 	(WM_USER+0x101)
#define TM_ACTASTASKSW          (WM_USER+0x104)
#define TM_TASKTAB              (WM_USER+0x106)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\vmm.h
#define VMM_TRUE    (~FALSE)    // The opposite of False!
#define CONFIGMG_DEVICE_ID  0x00033 /* Configuration manager (Plug&Play) */
#define P_AVAIL     (P_PRES+P_WRITE+P_USER) /* avail to user & present */

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\winuserp.h
#define DC_NC               (DC_CAPTION | DC_FRAME)
#define PAS_HORZ        (PAS_LEFT | PAS_RIGHT)
#define PAS_VERT        (PAS_UP | PAS_DOWN)
#define SWP_NOCHANGE        (SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOCLIENTSIZE | SWP_NOCLIENTMOVE)
#define QS_VALID           (QS_KEY           | \
                            QS_MOUSEMOVE     | \
                            QS_MOUSEBUTTON   | \
                            QS_POSTMESSAGE   | \
                            QS_TIMER         | \
                            QS_PAINT         | \
                            QS_SENDMESSAGE   | \
                            QS_TRANSFER      | \
                            QS_HOTKEY        | \
                            QS_ALLPOSTMESSAGE)
#define QS_EVENTSET        (QS_EVENT | QS_SENDMESSAGE)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\port32.h
#define HANDLE_WM_CONTEXTMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)
#define FORWARD_WM_CONTEXTMENU(hwnd, hwndClick, x, y, fn) \
    (void)(fn)((hwnd), WM_CONTEXTMENU, (WPARAM)(HWND)(hwndClick), MAKELPARAM((x), (y)))
#define HANDLE_WM_CONTEXTMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_CONTEXTMENU(hwnd, hwndClick, x, y, fn) \
    (void)(fn)((hwnd), WM_CONTEXTMENU, (WPARAM)(HWND)(hwndClick), MAKELPARAM((x), (y)))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\recact.h
#define RAM_FIRST       (WM_USER+1)
#define RAM_LAST        (WM_USER+20)
#define RecAct_GetItemCount(hwnd) \
                (int)SendMessage(hwnd, RAM_GETITEMCOUNT, 0, 0L)
#define RecAct_InsertItem(hwnd, pitem) \
                (int)SendMessage((hwnd), RAM_INSERTITEM, 0, (LPARAM)(const LPRA_ITEM)(pitem))
#define RecAct_GetItem(hwnd, pitem) \
                (BOOL)SendMessage((hwnd), RAM_GETITEM, 0, (LPARAM)(LPRA_ITEM)(pitem))
#define RecAct_SetItem(hwnd, pitem) \
                (BOOL)SendMessage((hwnd), RAM_SETITEM, 0, (LPARAM)(const LPRA_ITEM)(pitem))
#define RecAct_GetCurSel(hwnd) \
                (int)SendMessage((hwnd), RAM_GETCURSEL, (WPARAM)0, 0L)
#define RecAct_SetCurSel(hwnd, i) \
                (int)SendMessage((hwnd), RAM_SETCURSEL, (WPARAM)(i), 0L)
#define RecAct_FindItem(hwnd, iStart, prafi) \
                (int)SendMessage((hwnd), RAM_FINDITEM, (WPARAM)(int)(iStart), (LPARAM)(const RA_FINDINFO *)(prafi))
#define RecAct_Refresh(hwnd) \
                SendMessage((hwnd), RAM_REFRESH, 0, 0L)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\thread.c
#define STUBM_SETDATA   (WM_USER)
#define STUBM_GETDATA   (WM_USER+1)

// com\mobile\syncmgr\test\outhndlr\edkmdb.h
#define ROW_EMPTY			(ROW_ADD|ROW_REMOVE)
#define	rightsReadWrite			(frightsReadAny|frightsEditAny)

// com\ole2ui32\common.h
#define SendCommand(hWnd, wID, wCode, hControl)                     \
                        SendMessage(hWnd, WM_COMMAND, MAKELONG(wID, wCode)      \
                                                , (LPARAM)hControl)

// com\ole2ui32\iconbox.h
#define IBXM_LABELENABLE                (WM_USER+3)

// com\ole2ui32\winres.h
#define LBS_STANDARD    (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

// com\ole32\com\class\ole1guid.cxx
	#define DEFINE_OLE1GUID(clsid,x,xx,xxx,sz) sz, &clsid, /##/

// com\ole32\com\dcomrem\marshal.hxx
#define OBJREF_RSRVD_MBZ ~(OBJREF_STANDARD | OBJREF_HANDLER | \
                           OBJREF_CUSTOM | OBJREF_EXTENDED)
#define SORF_RSRVD_MBZ   ~(SORF_NOPING | SORF_OXRES1 | SORF_OXRES2 |   \
                           SORF_OXRES3 | SORF_OXRES4 | SORF_OXRES5 |   \
                           SORF_OXRES6 | SORF_OXRES7 | SORF_OXRES8)

// com\ole32\com\dde\client\ddeproxy.cxx
    #define macro(Notif, NOTIF) \
    if (iAdvOn == ON_##NOTIF)   \
       m_iAdv##Notif += cDelta; \
    if (m_iAdv##Notif < 0)      \
        m_iAdv##Notif = 0;      \
    else if (m_iAdv##Notif > 2) \
        m_iAdv##Notif = 2;

// com\ole32\com\dde\server\srvr.h
#define   ISATOM(a)     ((a >= 0xC000) && (a <= 0xFFFF))

// com\ole32\com\moniker2\cmonimp.cxx
#define IsFileSystemSeparator(ch)   ('\\' == (ch) || '/' == (ch) || ':' == (ch))
#define IsItemMonikerSeparator(ch)  ('!' == (ch) || '/' == (ch) || '[' == (ch) || '#' == (ch))
#define IsDriveLetter(ch) ( ( (ch) >= L'A' && (ch) <= L'Z') ||  ( (ch) >= L'a' && (ch) <= L'z'))

// com\ole32\com\objact\objact.cxx
#define INTERNAL_CLSCTX(clsctx) (clsctx & CLSCTX_PS_DLL)

// com\ole32\com\txf\callframe\stublessclient.h
    #define CLSCTX_PROXY_STUB   (CLSCTX_KERNEL_SERVER | CLSCTX_PS_DLL)
    #define CLSCTX_PROXY_STUB   (CLSCTX_INPROC_SERVER | CLSCTX_PS_DLL)

// com\ole32\com\txf\inc\probe.h
#define ProbeAndReadBoolean(Address) \
    (((Address) >= (BOOLEAN * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile BOOLEAN * const)MM_USER_PROBE_ADDRESS) : (*(volatile BOOLEAN *)(Address)))
#define ProbeAndReadShort(Address) \
    (((Address) >= (SHORT * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile SHORT * const)MM_USER_PROBE_ADDRESS) : (*(volatile SHORT *)(Address)))
#define ProbeAndReadUshort(Address) \
    (((Address) >= (USHORT * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile USHORT * const)MM_USER_PROBE_ADDRESS) : (*(volatile USHORT *)(Address)))
#define ProbeAndReadHandle(Address) \
    (((Address) >= (HANDLE * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile HANDLE * const)MM_USER_PROBE_ADDRESS) : (*(volatile HANDLE *)(Address)))
#define ProbeAndReadQuad(Address) \
    (((Address) >= (QUAD * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile QUAD * const)MM_USER_PROBE_ADDRESS) : (*(volatile QUAD *)(Address)))
#define ProbeAndReadUquad(Address) \
    (((Address) >= (UQUAD * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile UQUAD * const)MM_USER_PROBE_ADDRESS) : (*(volatile UQUAD *)(Address)))
#define ProbeAndReadLargeInteger(Source)  \
    (((Source) >= (LARGE_INTEGER * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile LARGE_INTEGER * const)MM_USER_PROBE_ADDRESS) : (*(volatile LARGE_INTEGER *)(Source)))
#define ProbeAndReadUlargeInteger(Source)  \
    (((Source) >= (ULARGE_INTEGER * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile ULARGE_INTEGER * const)MM_USER_PROBE_ADDRESS) : (*(volatile ULARGE_INTEGER *)(Source)))
#define ProbeForWriteBoolean(Address) {                                      \
    if ((Address) >= (BOOLEAN * const)MM_USER_PROBE_ADDRESS) {               \
        *(volatile BOOLEAN * const)MM_USER_PROBE_ADDRESS = 0;                \
    }                                                                        \
                                                                             \
    *(volatile BOOLEAN *)(Address) = *(volatile BOOLEAN *)(Address);         \
}
#define ProbeForWriteShort(Address) {                                        \
    if ((Address) >= (SHORT * const)MM_USER_PROBE_ADDRESS) {                 \
        *(volatile SHORT * const)MM_USER_PROBE_ADDRESS = 0;                  \
    }                                                                        \
                                                                             \
    *(volatile SHORT *)(Address) = *(volatile SHORT *)(Address);             \
}
#define ProbeForWriteUshort(Address) {                                       \
    if ((Address) >= (USHORT * const)MM_USER_PROBE_ADDRESS) {                \
        *(volatile USHORT * const)MM_USER_PROBE_ADDRESS = 0;                 \
    }                                                                        \
                                                                             \
    *(volatile USHORT *)(Address) = *(volatile USHORT *)(Address);           \
}
#define ProbeForWriteHandle(Address) {                                       \
    if ((Address) >= (HANDLE * const)MM_USER_PROBE_ADDRESS) {                \
        *(volatile HANDLE * const)MM_USER_PROBE_ADDRESS = 0;                 \
    }                                                                        \
                                                                             \
    *(volatile HANDLE *)(Address) = *(volatile HANDLE *)(Address);           \
}
#define ProbeAndWriteBoolean(Address, Value) {                               \
    if ((Address) >= (BOOLEAN * const)MM_USER_PROBE_ADDRESS) {               \
        *(volatile BOOLEAN * const)MM_USER_PROBE_ADDRESS = 0;                \
    }                                                                        \
                                                                             \
    *(Address) = (Value);                                                    \
}
#define ProbeAndWriteShort(Address, Value) {                                 \
    if ((Address) >= (SHORT * const)MM_USER_PROBE_ADDRESS) {                 \
        *(volatile SHORT * const)MM_USER_PROBE_ADDRESS = 0;                  \
    }                                                                        \
                                                                             \
    *(Address) = (Value);                                                    \
}
#define ProbeAndWriteUshort(Address, Value) {                                \
    if ((Address) >= (USHORT * const)MM_USER_PROBE_ADDRESS) {                \
        *(volatile USHORT * const)MM_USER_PROBE_ADDRESS = 0;                 \
    }                                                                        \
                                                                             \
    *(Address) = (Value);                                                    \
}
#define ProbeAndWriteHandle(Address, Value) {                                \
    if ((Address) >= (HANDLE * const)MM_USER_PROBE_ADDRESS) {                \
        *(volatile HANDLE * const)MM_USER_PROBE_ADDRESS = 0;                 \
    }                                                                        \
                                                                             \
    *(Address) = (Value);                                                    \
}

// com\ole32\com\txf\txfaux\md5.cpp
    #define G(x, y, z) ((((x) ^ (y)) & (z)) ^ (y))          // an alternate encoding
    #define H(x, y, z) ((x) ^ (y) ^ (z))
    #define I(x, y, z) ((y) ^ ((x) | (~z)))

// com\ole32\comcat\fwd\comcat.rc
#define VER_PRODUCTVERSION_DW       (0x04460000 | VER_PRODUCTBUILD)

// com\ole32\comcat\src\comcat.rc
#define VER_PRODUCTVERSION_DW       (0x04460000 | VER_PRODUCTBUILD)

// com\ole32\ih\exports.hxx
#define IFM_IUnknown_AddRef                     (IFACE_IUNKNOWN|1)

// com\ole32\ih\ole2com.h
#define CLSCTX_INPROC_HANDLERS (CLSCTX_INPROC_HANDLER16 | CLSCTX_INPROC_HANDLER | CLSCTX_INPROC_HANDLERX86)
#define CLSCTX_INPROC_SERVERS (CLSCTX_INPROC_SERVER16 | CLSCTX_INPROC_SERVER | CLSCTX_INPROC_SERVERX86 | CLSCTX_PS_DLL)

// com\ole32\ih\ole2sp.h
#define STGM_DFRALL (STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_DENY_WRITE)
#define STGM_DFALL (STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_EXCLUSIVE)
#define STGM_SALL (STGM_READWRITE | STGM_SHARE_EXCLUSIVE)

// com\ole32\ih\olecoll.h
#define _AFX_FP_SEG(lp) (*((UINT FAR*)&(lp)+1))

// com\ole32\ih\stkswtch.h
#define SSONBIGSTACK()   (fSSOn && IsWOWThread() && SSOnBigStack())
#define SSONSMALLSTACK() (fSSOn && IsWOWThread() && !SSOnBigStack())
#define SSONBIGSTACK() 	 (IsWOWThread() && SSOnBigStack())
#define SSONSMALLSTACK() (IsWOWThread() && !SSOnBigStack())
#define SendMessage( hWnd,  Msg,  wParam,  lParam)   SS_STOP_STR
#define InSendMessage() SS_STOP_STR
#define InSendMessageEx(lpResvd) SS_STOP_STR

// com\ole32\ole232\cache\olecache.cpp
#define FREEZE_CONSTANT 143             // Used by Freeze() and Unfreeze()

// com\ole32\oleprx32\proxy\transmit.h
#define NON_STANDARD_CLIPFORMAT(pcf)((0xC000<= *pcf) && (*pcf <=0xFFFF))

// com\ole32\olethunk\h\stksw.hxx
#define SSONBIGSTACK()   (fSSOn && SSOnBigStack())
#define SSONSMALLSTACK() (fSSOn && !SSOnBigStack())

// com\ole32\olethunk\ole16\inc\compobj.h
#define CLSCTX_INPROC           (CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER)

// com\ole32\olethunk\ole16\inc\ctype.h
#define isupper(_c)	( (_ctype+1)[_c] & _UPPER )
#define isdigit(_c)	( (_ctype+1)[_c] & _DIGIT )
#define isxdigit(_c)	( (_ctype+1)[_c] & _HEX )
#define isspace(_c)	( (_ctype+1)[_c] & _SPACE )
#define ispunct(_c)	( (_ctype+1)[_c] & _PUNCT )
#define iscntrl(_c)	( (_ctype+1)[_c] & _CONTROL )
#define __toascii(_c)	( (_c) & 0x7f )
#define __iscsymf(_c)	(isalpha(_c) || ((_c) == '_'))
#define __iscsym(_c)	(isalnum(_c) || ((_c) == '_'))

// com\ole32\olethunk\ole16\inc\debnot.h
#  define DEF_INFOLEVEL (DEB_ERROR | DEB_WARN)
#  define DECLARE_DEBUGVALUE(Name,hGroup,Value) \
    CDebugValue Name((L#Name),hGroup,Value)
#  define DECLARE_DEBUGVALUEEX(Name,Title,hGroup,Value) \
    CDebugValue Name(Title,hGroup,Value)

// com\ole32\olethunk\ole16\inc\dos.h
#define _FP_SEG(fp) (*((unsigned __far *)&(fp)+1))
#define _FP_OFF(fp) (*((unsigned __far *)&(fp)))

// com\ole32\olethunk\ole16\inc\dvobj.h
#define UPDFCACHE_IFBLANKORONSAVECACHE	(UPDFCACHE_IFBLANK | UPDFCACHE_ONSAVECACHE )
#define UPDFCACHE_ALL					(~UPDFCACHE_ONLYIFBLANK)
#define UPDFCACHE_ALLBUTNODATACACHE		(UPDFCACHE_ALL & ~UPDFCACHE_NODATACACHE)

// com\ole32\olethunk\ole16\inc\ole2sp.h
#define STGM_DFRALL (STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_DENY_WRITE)
#define STGM_DFALL (STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_EXCLUSIVE)
#define STGM_SALL (STGM_READWRITE | STGM_SHARE_EXCLUSIVE)

// com\ole32\olethunk\ole16\inc\ole2ui.h
#define isspace(j) (j==' ' || j=='\t' || j=='\n')

// com\ole32\olethunk\ole16\inc\olecoll.h
#define _AFX_FP_SEG(lp) (*((UINT FAR*)&(lp)+1))

// com\ole32\olethunk\ole16\inc\olerem.h
#define FNITYPE_Send    0x10    // Use SendMessage (not PostMessage)

// com\ole32\olethunk\ole16\inc\olestd.h
#define STGM_DFRALL (STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_DENY_WRITE)
#define STGM_DFALL (STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_EXCLUSIVE)
#define STGM_SALL (STGM_READWRITE | STGM_SHARE_EXCLUSIVE)
#define IsEqualFORMATETC(fe1, fe2)  \
    (OleStdCompareFormatEtc(&(fe1), &(fe2))==0)
#define OleStdQueryOleObjectData(lpformatetc)   \
    (((lpformatetc)->tymed & TYMED_ISTORAGE) ?    \
            NOERROR : ResultFromScode(DV_E_FORMATETC))
#define OleStdQueryFormatMedium(lpformatetc, tymd)  \
    (((lpformatetc)->tymed & tymd) ?    \
            NOERROR : ResultFromScode(DV_E_FORMATETC))
#define OleStdCopyMetafilePict(hpictin, phpictout)  \
    (*(phpictout) = OleDuplicateData(hpictin,CF_METAFILEPICT,GHND|GMEM_SHARE))

// com\ole32\olethunk\ole16\inc\scode.h
#define SCODE_CODE(sc)      ((sc) & 0xFFFF)
#define GetScode(hr)        ((SCODE)(hr) & 0x800FFFFF)

// com\ole32\olethunk\ole16\inc\stdio.h
#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])
#define _stdaux (&_iob[3])
#define _stdprn (&_iob[4])

// com\ole32\olethunk\ole16\inc\windows.h
#define GHND		    (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define LHND		    (LMEM_MOVEABLE | LMEM_ZEROINIT)
#define QS_MOUSE	(QS_MOUSEMOVE | QS_MOUSEBUTTON)
#define WVR_REDRAW	    (WVR_HREDRAW | WVR_VREDRAW)
#define DM_GETDEFID	    (WM_USER+0)
#define DM_SETDEFID	    (WM_USER+1)
#define STM_SETICON	    (WM_USER+0)
#define STM_GETICON	    (WM_USER+1)
#define BM_SETSTYLE	    (WM_USER+4)
#define EM_GETSEL	        (WM_USER+0)
#define EM_SETSEL	        (WM_USER+1)
#define EM_LINESCROLL	        (WM_USER+6)
#define EM_GETMODIFY	        (WM_USER+8)
#define EM_SETMODIFY	        (WM_USER+9)
#define EM_LINEINDEX	        (WM_USER+11)
#define EM_SETHANDLE	        (WM_USER+12)
#define EM_GETHANDLE	        (WM_USER+13)
#define EM_REPLACESEL	        (WM_USER+18)
#define EM_SETFONT              (WM_USER+19)    /* NOT IMPLEMENTED: use WM_SETFONT */
#define EM_GETLINE	        (WM_USER+20)
#define EM_CANUNDO	        (WM_USER+22)
#define EM_UNDO 	        (WM_USER+23)
#define EM_FMTLINES	        (WM_USER+24)
#define EM_SETTABSTOPS	        (WM_USER+27)
#define EM_GETFIRSTVISIBLELINE	(WM_USER+30)
#define EM_SETREADONLY	        (WM_USER+31)
#define LBS_STANDARD	      (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)
#define LB_RESETCONTENT        (WM_USER+5)
#define LB_SETSEL	       (WM_USER+6)
#define LB_SETCURSEL	       (WM_USER+7)
#define LB_GETSEL	       (WM_USER+8)
#define LB_GETCURSEL	       (WM_USER+9)
#define LB_DIR		       (WM_USER+14)
#define LB_GETTOPINDEX	       (WM_USER+15)
#define LB_GETSELITEMS	       (WM_USER+18)
#define LB_SETTABSTOPS         (WM_USER+19)
#define LB_GETHORIZONTALEXTENT (WM_USER+20)
#define LB_SETHORIZONTALEXTENT (WM_USER+21)
#define LB_SETCOLUMNWIDTH      (WM_USER+22)
#define LB_SETTOPINDEX	       (WM_USER+24)
#define LB_GETITEMDATA         (WM_USER+26)
#define LB_SETITEMDATA         (WM_USER+27)
#define LB_SETCARETINDEX       (WM_USER+31)
#define LB_GETCARETINDEX       (WM_USER+32)
#define LB_SETITEMHEIGHT       (WM_USER+33)
#define LB_GETITEMHEIGHT       (WM_USER+34)

// com\ole32\olethunk\olethk32\thop.hxx
#define PEEK_STACK32(pti, val, typ) \
    (val) = *(typ *)(pti)->s32.pbCurrent
#define INDEX_STACK32(pti, val, typ, idx) \
    (val) = *(typ *)((pti)->s32.pbCurrent-(idx))
#define EXECUTE_ENUMTHOP1632(pti) \
    (*aThopEnumFunctions1632[*(pti)->pThop])(pti)
#define EXECUTE_ENUMTHOP3216(pti) \
    (*aThopEnumFunctions3216[*(pti)->pThop])(pti)

// com\ole32\olethunk\olethk32\thoputil.cxx
#define OBJDESC_CF(cf) \
    ((cf) == g_cfObjectDescriptor || (cf) == g_cfLinkSourceDescriptor)

// com\ole32\olethunk\olethk32\tlsthk.hxx
#define TlsThkGetStack16() (&TlsThkGetData()->sa16)
#define TlsThkGetStack32() (&TlsThkGetData()->sa32)

// com\ole32\olethunk\thc\thpp\compobj.h
#define CLSCTX_INPROC           (CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER)

// com\ole32\olethunk\thc\thpp\dvobj.h
#define UPDFCACHE_IFBLANKORONSAVECACHE	(UPDFCACHE_IFBLANK | UPDFCACHE_ONSAVECACHE )
#define UPDFCACHE_ALL					(~UPDFCACHE_ONLYIFBLANK)
#define UPDFCACHE_ALLBUTNODATACACHE		(UPDFCACHE_ALL & ~UPDFCACHE_NODATACACHE)

// com\ole32\olethunk\thc\thpp\scode.h
#define SCODE_CODE(sc)      ((sc) & 0xFFFF)
#define GetScode(hr)        ((SCODE)(hr) & 0x800FFFFF)

// com\ole32\olethunk\tools\clschk\classchk.h
#define VERBOSITY( level, x) if( level & g_VerbosityLevel ) x

// com\ole32\stg\drt\drt.hxx
#define ROOTP(x) ((x) | dwTransacted | dwRootDenyWrite)
#define STGP(x) ((x) | dwTransacted | STGM_SHARE_EXCLUSIVE)
#define STMP(x) ((x) | STGM_SHARE_EXCLUSIVE)

// com\ole32\stg\exp\docfile.cxx
#define RSF_MSF (RSF_CONVERT | RSF_TRUNCATE | RSF_ENCRYPTED)

// com\ole32\stg\h\async.hxx
#define ISPENDINGERROR(x) ((x == E_PENDING) || (x == STG_E_PENDINGCONTROL))

// com\ole32\stg\h\dfmsp.hxx
#define RSF_TEMPFILE    (RSF_SCRATCH | RSF_SNAPSHOT)
#define DF_READWRITE            (DF_READ | DF_WRITE)
#define DF_DENYALL              (DF_DENYREAD | DF_DENYWRITE)
#define P_READ(f)       ((f) & DF_READ)
#define P_WRITE(f)      ((f) & DF_WRITE)
#define P_READWRITE(f)  (((f) & (DF_READ | DF_WRITE)) == (DF_READ | DF_WRITE))
#define P_DENYREAD(f)   ((f) & DF_DENYREAD)
#define P_DENYWRITE(f)  ((f) & DF_DENYWRITE)
#define P_DENYALL(f)    (((f) & (DF_DENYREAD | DF_DENYWRITE)) == \
                         (DF_DENYREAD | DF_DENYWRITE))
#define P_PRIORITY(f)   ((f) & DF_PRIORITY)
#define P_TRANSACTED(f) ((f) & DF_TRANSACTED)
#define P_TSELF(f)      ((f) & DF_TRANSACTEDSELF)
#define P_REVERTED(f)   ((f) & DF_REVERTED)
#define P_COMMIT(f)     ((f) & DF_COMMIT)
#define P_CREATE(f)     ((f) & DF_CREATE)
#define P_CACHE(f)      ((f) & DF_CACHE)
#define P_NOUPDATE(f)   ((f) & DF_NOUPDATE)
#define P_COMMITTING(f) ((f) & DF_COMMITTING)
#define P_NOSCRATCH(f)  ((f) & DF_NOSCRATCH)
#define P_NOSNAPSHOT(f) ((f) & DF_NOSNAPSHOT)

// com\ole32\stg\h\dir.hxx
#define STORAGELIKE(mse) \
    (((mse) & STGTY_REAL) == STGTY_STORAGE || (mse) == STGTY_ROOT)

// com\ole32\stg\h\docfilep.hxx
#define STGM_RDWR (STGM_READ | STGM_WRITE | STGM_READWRITE)
#define STGM_DENY (STGM_SHARE_DENY_NONE | STGM_SHARE_DENY_READ | \
		   STGM_SHARE_DENY_WRITE | STGM_SHARE_EXCLUSIVE)
#define FLUSH_CACHE(cf) \
     ((cf & STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE) == 0)
#define NOT_SINGLE(md) (((md) & STGM_DENY) != STGM_SHARE_EXCLUSIVE)

// com\ole32\stg\ole2flat\compobj.h
#define CLSCTX_INPROC           (CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER)

// com\ole32\stg\ole2flat\dvobj.h
#define UPDFCACHE_IFBLANKORONSAVECACHE	(UPDFCACHE_IFBLANK | UPDFCACHE_ONSAVECACHE )
#define UPDFCACHE_ALL					(~UPDFCACHE_ONLYIFBLANK)
#define UPDFCACHE_ALLBUTNODATACACHE		(UPDFCACHE_ALL & ~UPDFCACHE_NODATACACHE)

// com\ole32\stg\ole2flat\scode.h
#define SCODE_CODE(sc)      ((sc) & 0xFFFF)
#define GetScode(hr)        ((SCODE)(hr) & 0x800FFFFF)

// com\ole32\stg\ole2h\compobj.h
#define CLSCTX_INPROC           (CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER)

// com\ole32\stg\ole2h\scode.h
#define SCODE_CODE(sc)      ((sc) & 0xFFFF)
#define GetScode(hr) 		((SCODE)(hr) & 0x800FFFFF)

// com\ole32\stg\props\propstm.cxx
#define PID_HEADINGPAIR 0x0000000c // heading pair (VT_VECTOR | VT_VARIANT):

// com\ole32\stg\props\utest\cpropvar.hxx
#define DECLARE_CPROPVARIANT_ASSIGNMENT_OPERATOR(Type) \
        CPropVariant & operator =( Type);

// com\ole32\stg\ref\expdf.cxx
#define NOT_SINGLE(md) (((md) & STGM_DENY) != STGM_SHARE_EXCLUSIVE)

// com\ole32\stg\ref\h\dfmsp.hxx
#define DF_READWRITE            (DF_READ | DF_WRITE)
#define DF_DENYALL              (DF_DENYREAD | DF_DENYWRITE)
#define P_READ(f)       ((f) & DF_READ)
#define P_WRITE(f)      ((f) & DF_WRITE)
#define P_READWRITE(f)  (((f) & (DF_READ | DF_WRITE)) == (DF_READ | DF_WRITE))
#define P_DENYREAD(f)   ((f) & DF_DENYREAD)
#define P_DENYWRITE(f)  ((f) & DF_DENYWRITE)
#define P_DENYALL(f)    (((f) & (DF_DENYREAD | DF_DENYWRITE)) == \
			 (DF_DENYREAD | DF_DENYWRITE))
#define P_PRIORITY(f)   ((f) & DF_PRIORITY)
#define P_TRANSACTED(f) ((f) & DF_TRANSACTED)
#define P_INDEPENDENT(f) ((f) & DF_INDEPENDENT)
#define P_TSELF(f)      ((f) & DF_TRANSACTEDSELF)
#define P_REVERTED(f)   ((f) & DF_REVERTED)
#define P_COMMIT(f)     ((f) & DF_COMMIT)
#define P_CREATE(f)     ((f) & DF_CREATE)
#define P_CACHE(f)      ((f) & DF_CACHE)
#define P_NOUPDATE(f)   ((f) & DF_NOUPDATE)

// com\ole32\stg\ref\h\dir.hxx
#define STORAGELIKE(mse) \
    (((mse) & STGTY_REAL) == STGTY_STORAGE || (mse) == STGTY_ROOT)

// com\ole32\stg\ref\h\docfilep.hxx
#define STGM_RDWR (STGM_READ | STGM_WRITE | STGM_READWRITE)
#define STGM_DENY (STGM_SHARE_DENY_NONE | STGM_SHARE_DENY_READ | \
		   STGM_SHARE_DENY_WRITE | STGM_SHARE_EXCLUSIVE)
#define FLUSH_CACHE(cf) \
     ((cf & STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE) == 0)

// com\ole32\stg\ref\props\propstm.cxx
#define PID_HEADINGPAIR 0x0000000c // heading pair (VT_VECTOR | VT_VARIANT):

// com\ole32\stg\ref\test\proptest\cpropvar.hxx
#define DECLARE_CPROPVARIANT_ASSIGNMENT_OPERATOR(Type) \
        CPropVariant & operator =(const Type);

// com\ole32\stg\ref\test\reftest\reftest.cxx
#define STGP(x) STGM_SHARE_EXCLUSIVE | x
#define STMP(x) STGM_SHARE_EXCLUSIVE | x

// com\ole32\stg\ref\test\stgdrt\drt.hxx
#define ROOTP(x) ((x) | dwRootDenyWrite)
#define STGP(x) ((x) | STGM_SHARE_EXCLUSIVE)
#define STMP(x) ((x) | STGM_SHARE_EXCLUSIVE)

// com\ole32\stg\utils\df2t\w4ctsupp.hxx
#define ERR (SCODE) ~0

// com\oleutest\balls\client\tmarshal\objref.cxx
#define OBJREF_RSRVD_MBZ ~(OBJREF_STANDARD | OBJREF_HANDLER | OBJREF_CUSTOM)
#define SORF_RSRVD_MBZ	 ~(SORF_NOPING | SORF_OXRES1 | SORF_OXRES2 |   \
			   SORF_OXRES3 | SORF_OXRES4 | SORF_OXRES5 |   \
			   SORF_OXRES6 | SORF_OXRES7 | SORF_OXRES8)

// com\oleutest\dll\oleimpl.hxx
#define STGM_DFRALL (STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_DENY_WRITE)

// com\oleutest\letest\bttncur\bttncur.h
#define COMMANDBUTTON_MOUSEDOWN         (BUTTONGROUP_ACTIVE | BUTTONGROUP_DOWN)
#define ATTRIBUTEBUTTON_MOUSEDOWN       (BUTTONGROUP_ACTIVE | BUTTONGROUP_DOWN)
#define ATTRIBUTEBUTTON_DOWN            (BUTTONGROUP_ACTIVE | BUTTONGROUP_DOWN | BUTTONGROUP_LIGHTFACE)
#define ATTRIBUTEBUTTON_DOWNDISABLED    (BUTTONGROUP_DISABLED | BUTTONGROUP_DOWN | BUTTONGROUP_LIGHTFACE)
#define BLANKBUTTON_UP                  (BUTTONGROUP_ACTIVE | BUTTONGROUP_BLANK)
#define BLANKBUTTON_DOWN                (BUTTONGROUP_ACTIVE | BUTTONGROUP_BLANK | BUTTONGROUP_DOWN | BUTTONGROUP_LIGHTFACE)
#define BLANKBUTTON_MOUSEDOWN           (BUTTONGROUP_ACTIVE | BUTTONGROUP_BLANK | BUTTONGROUP_DOWN)

// com\oleutest\letest\gizmobar\book1632.h
#define SendCommand(hWnd, wID, wCode, hControl)                     \
            SendMessage(hWnd, WM_COMMAND, MAKELONG(wID, wCode)      \
                        , (LPARAM)hControl)
#define SendMenuSelect(hWnd, wID, wFlags, hMenu)                    \
            SendMessage(hWnd, WM_MENUSELECT, MAKELONG(wID, wFlags)  \
                        , (LPARAM)hMenu)
#define SendScrollPosition(hWnd, iMsg, iPos)                        \
            SendMessage(hWnd, iMsg, MAKELONG(SB_THUMBPOSITION, iPos), 0)
#define MDIREFRESHMENU(h) SendMessage(h, WM_MDIREFRESHMENU, 0, 0L)
#define SendCommand(hWnd, wID, wCode, hControl)                     \
            SendMessage(hWnd, WM_COMMAND, wID                       \
                        , MAKELONG(hControl, wCode))
#define SendMenuSelect(hWnd, wID, wFlags, hMenu)                    \
            SendMessage(hWnd, WM_MENUSELECT, wID                    \
                        , MAKELONG(wFlags, hMenu))
#define SendScrollPosition(hWnd, iMsg, iPos)                        \
            SendMessage(hWnd, iMsg, SB_THUMBPOSITION, MAKELONG(iPos, 0))
#define MDIREFRESHMENU(h) SendMessage(h, WM_MDISETMENU, TRUE, 0L)

// com\oleutest\letest\gizmobar\gizmo.h
#define GIZMOTYPE_BUTTONS           (GIZMOTYPE_BUTTONATTRIBUTEIN | GIZMOTYPE_BUTTONATTRIBUTEEX | GIZMOTYPE_BUTTONCOMMAND | GIZMOTYPE_BUTTONNORMAL)
#define GIZMOTYPE_DRAWN             (GIZMOTYPE_BUTTONATTRIBUTEIN | GIZMOTYPE_BUTTONATTRIBUTEEX | GIZMOTYPE_BUTTONCOMMAND)

// com\oleutest\letest\gizmobar\gizmobar.h
#define GBM_HWNDASSOCIATESET            (WM_USER+0)
#define GBM_HWNDASSOCIATEGET            (WM_USER+1)
#define GBM_GIZMOADD                    (WM_USER+2)
#define GBM_GIZMOREMOVE                 (WM_USER+3)
#define GBM_GIZMOSENDMESSAGE            (WM_USER+4)
#define GBM_GIZMOSHOW                   (WM_USER+5)
#define GBM_GIZMOENABLE                 (WM_USER+6)
#define GBM_GIZMOFOCUSSET               (WM_USER+8)
#define GBM_GIZMOEXIST                  (WM_USER+9)
#define GBM_GIZMOTYPEGET                (WM_USER+10)
#define GBM_GIZMODATASET                (WM_USER+11)
#define GBM_GIZMODATAGET                (WM_USER+12)
#define GBM_GIZMONOTIFYSET              (WM_USER+13)
#define GBM_GIZMONOTIFYGET              (WM_USER+14)
#define GBM_GIZMOINTGET                 (WM_USER+17)
#define GBM_GIZMOINTSET                 (WM_USER+18)

// com\oleutest\letest\ole2ui\common.h
#define SendCommand(hWnd, wID, wCode, hControl)                     \
            SendMessage(hWnd, WM_COMMAND, MAKELONG(wID, wCode)      \
                        , (LPARAM)hControl)
#define SendCommand(hWnd, wID, wCode, hControl)                     \
            SendMessage(hWnd, WM_COMMAND, wID                       \
                        , MAKELONG(hControl, wCode))

// com\oleutest\letest\ole2ui\iconbox.h
#define IBXM_LABELENABLE                (WM_USER+3)

// com\oleutest\letest\ole2ui\ole2ui.h
      #define isspace(j) (j==' ' || j=='\t' || j=='\n')

// com\oleutest\letest\ole2ui\olestd.h
#define STGM_DFRALL (STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_DENY_WRITE)
#define STGM_DFALL (STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_EXCLUSIVE)
#define STGM_SALL (STGM_READWRITE | STGM_SHARE_EXCLUSIVE)
#define IsEqualFORMATETC(fe1, fe2)  \
    (OleStdCompareFormatEtc(&(fe1), &(fe2))==0)
#define OleStdQueryOleObjectData(lpformatetc)   \
    (((lpformatetc)->tymed & TYMED_ISTORAGE) ?    \
            NOERROR : ResultFromScode(DV_E_FORMATETC))
#define OleStdQueryFormatMedium(lpformatetc, tymd)  \
    (((lpformatetc)->tymed & tymd) ?    \
            NOERROR : ResultFromScode(DV_E_FORMATETC))
#define OleStdCopyMetafilePict(hpictin, phpictout)  \
    (*(phpictout) = OleDuplicateData(hpictin,CF_METAFILEPICT,GHND|GMEM_SHARE))

// com\oleutest\letest\outline\oleoutl.h
#define APPFILENAMEFILTER   "Outline Files (*.OLN)|*.oln|All files (*.*)|*.*|"
#define APPFILENAMEFILTER   "CntrOutl Files (*.OLC)|*.olc|Outline Files (*.OLN)|*.oln|All files (*.*)|*.*|"
#define APPFILENAMEFILTER   "Outline Files (*.OLN)|*.oln|All files (*.*)|*.*|"
#define APPFILENAMEFILTER   "CntrOutl Files (*.OLC)|*.olc|Outline Files (*.OLN)|*.oln|All files (*.*)|*.*|"

// com\oleutest\letest\outline\outline.h
#define APPFILENAMEFILTER   "Outline Files (*.OLN)|*.oln|All files (*.*)|*.*|"

// com\oleutest\simpdnd\idt.cpp
#define SetTopLeft(rc, pt)		\
	((rc)->top = (pt)->y,(rc)->left = (pt)->x)
#define SetBottomRight(rc, pt)		\
	((rc)->bottom = (pt)->y,(rc)->right = (pt)->x)

// com\oleutest\stgbvt\comtools\h\uisift.h
#define UI_SIFT_INIT(name) \
    UiSiftDeclare(&g_ptsoTestSift);          \
    UiSiftInit(&g_ptsoTestSift, (name))

// com\oleutest\stgbvt\ctolestg\common\inc\getmach.hxx
#define GM_OS_ANY          (GM_NT | GM_WIN9X | GM_MACINTOSH)
#define GM_PROTO_ANY       (GM_PROTO_TCP | GM_PROTO_IPX | GM_PROTO_NETB)

// com\oleutest\stgdrt\drt.hxx
#define ROOTP(x) ((x) | dwTransacted | dwRootDenyWrite)
#define STGP(x) ((x) | dwTransacted | STGM_SHARE_EXCLUSIVE)
#define STMP(x) ((x) | STGM_SHARE_EXCLUSIVE)

// com\oleutest\utests16\ole2ui\ole2ui.h
#define isspace(j) (j==' ' || j=='\t' || j=='\n')

// com\oleutest\utests16\simpdnd\idt.cpp
#define SetTopLeft(rc, pt)      \
	((rc)->top = (pt)->y,(rc)->left = (pt)->x)
#define SetBottomRight(rc, pt)      \
	((rc)->bottom = (pt)->y,(rc)->right = (pt)->x)

// com\rpc\midl\codegen\filecls.cxx
#define IsAlphaNum_(x)    (((x) >= '0' && (x) <= '9') || ((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z') || (x) == '_')

// com\rpc\midl\codegen\proccls.hxx
#define IN_OUT_PARAM         (IN_PARAM | OUT_PARAM)
#define PARTIAL_IGNORE_PARAM (IN_PARAM | OUT_PARAM | 0x4 )

// com\rpc\midl\common\errdb.h
#define MS_EXT_SET				( ZZM | ZCM | ACM | AZM )
#define C_EXT_SET				( ZCM | ZCZ | ACM | ACZ )
#define MS_OR_C_EXT_SET			( MS_EXT_SET | C_EXT_SET )
#define APP_CONFIG_SET			( AZZ | AZM | ACZ | ACM )

// com\rpc\midl\front\gramutil.hxx
#define GET_ATTRIB(x)       (x & 0x000f)

// com\rpc\midl\front\lex.cxx
#define O23     ('~'  *256 + 12)            /* ~ 23 */

// com\rpc\midl\front\lex.h
#define KW_IN_BOTH	( KW_IN_IDL | KW_IN_ACF )
#define M_ALL		(M_OSF | M_MSE | M_CPORT)

// com\rpc\midl\front\lexutils.cxx
#define __isdigit(c)      (((c) >= '0' && (c) <= '9'))

// com\rpc\midl\front\semantic.cxx
#define IsCoclassOrDispKind(x)  ( (x) == NODE_DISPINTERFACE || (x) == NODE_COCLASS )
#define IsInterfaceKind(x)      ( (x) == NODE_INTERFACE_REFERENCE || (x) == NODE_INTERFACE )

// com\rpc\midl\inc\fldattr.hxx
#define FA_CONFORMANT_VARYING   (FA_CONFORMANT | FA_VARYING)

// com\rpc\midl\inc\prttype.hxx
#define PRT_BOTH_PREFIX	( PRT_CSTUB_PREFIX | PRT_SSTUB_PREFIX)
#define PRT_INTERFACE	( PRT_TRAILING_SEMI | PRT_CONVERT_CONSTS )
#define PRT_DECLARATION	( PRT_TRAILING_SEMI | PRT_NONE )
#define PRT_DUMP		( PRT_ALL_FILES | PRT_INTERFACE )
#define PRT_PARAM_DECLARATION		( PRT_TRAILING_SEMI | PRT_ALL_NAMES )
#define PRT_ID_DECLARATION			( PRT_TRAILING_SEMI | PRT_ALL_NAMES )
#define PRT_PARAM_OR_ID_DECLARATION	( PRT_TRAILING_SEMI | PRT_ALL_NAMES )
#define PRT_PROC_PROTOTYPE_WITH_SEMI ( PRT_PROC_PROTOTYPE | PRT_TRAILING_SEMI )

// com\rpc\midl\inc\semantic.hxx
#define     IN_FUNCTION_RESULT     0x0000000000000004 // used as (part of) a return type

// com\rpc\ndr20\attack.h
#define SAVE_CORRELATION_MEMORY()  \
            pCorrMemorySave = pStubMsg->pCorrMemory;
#define CORRELATION_DESC_INCREMENT( pFormat ) \
            if ( pStubMsg->fHasNewCorrDesc ) \
                pFormat += NDR_CORR_EXTENSION_SIZE;

// com\rpc\ndr20\ndrp.h
#define ROUTINE_INDEX(FC)       ((FC) & 0x3F)

// com\rpc\ndrexts\ndrexts\bufout.cxx
#define DISPATCH_TYPE(type)         \
   case type:                       \
      HANDLE_##type ();             \
      break;

// com\rpc\ndrexts\ndrexts\format.cxx
#define DISPATCH_TYPE(type)         \
   case type:                       \
      HANDLE_##type ();             \
      break;

// com\rpc\perf\inc\rpcperf.h
#define PERF_TEST_NOTIFY        (WM_USER + 101)
#define WMSG_RPCMSG     (WM_USER + 'w'+'m'+'s'+'g')

// com\rpc\runtime\trans\common\mqtrans.hxx
#define MQSendMessage(q, p, t) \
    g_pMqApi->pMQSendMessage(q, p, t)

// com\rpc\tools\yacc\dtxtrn.h
#define ASSOC(i) ((i)&03)
#define SETASC(i,j) i|=j

// com\winole\client\dll.h
#define GET_WM_DDE_EXECUTE_LPARAM(hdataExec)    ((UINT)hdataExec)

// com\winole\server\srvr.h
#define   ISATOM(a)     ((a >= 0xC000) && (a <= 0xFFFF))

// drivers\net\irda\mknet\sys\mk7comm.h
#define GOOD_FCS ((USHORT) ~0xf0b8)

// drivers\net\irda\sigmatel\sys\ircommon.h
#define GOOD_FCS                        ((USHORT) ~0xf0b8)

// drivers\serial\mps\comtrol\rocket\driver\asic.h
#define STMERROR   (STMBREAK | STMFRAME | STMPARITY)
#define STMERRORH   (STMBREAKH | STMFRAMEH | STMPARITYH)
#define DRAINED (TXFIFOMT | TXSHRMT)  /* indicates Tx is drained */

// drivers\serial\mps\comtrol\rocket\driver\nic.h
#define HDR_DEST_ADDR(_buf)  (&_buf[6])

// drivers\serial\mps\comtrol\rocket\driver\port.h
#define PortGetTxCnt(p) (q_count(&p->QOut))
#define PortGetTxRoom(p) (q_room(&p->QOut))
#define PortGetRxCnt(p) (q_count(&p->QIn))
#define pModemReset(p) \
  { (p)->action_reg |= ACT_MODEM_RESET; }
#define pFlushOutput(p) \
  { (p)->action_reg |= ACT_FLUSH_OUTPUT; }
#define DRAINED (TXFIFOMT | TXSHRMT)  /* indicates Tx is drained */
#define STMERROR   (STMBREAK | STMFRAME | STMPARITY)
#define STMERRORH   (STMBREAKH | STMFRAMEH | STMPARITYH)
#define DRAINED (TXFIFOMT | TXSHRMT)  /* indicates Tx is drained */

// drivers\serial\mps\comtrol\rocket\driver\ssci.h
#define sGetChanIntID(CHP) (sInB((CHP)->IntID) & (RXF_TRIG | TXFIFO_MT | SRC_INT | DELTA_CD | DELTA_CTS | DELTA_DSR))

// drivers\serial\mps\cyclades\y\cyyports\advandlg.c
#define Trackbar_SetTic(hwndTb, Tic)\
    (VOID) SendMessage(hwndTb, TBM_SETTIC, (WPARAM) 0, (LPARAM) Tic)

// drivers\serial\mps\cyclades\z\cyzports\advandlg.c
#define Trackbar_SetTic(hwndTb, Tic)\
    (VOID) SendMessage(hwndTb, TBM_SETTIC, (WPARAM) 0, (LPARAM) Tic)

// drivers\serial\mps\spx\mps\sx\inc\sxwindow.h
#define 	TA4		(TA | FOUR_PORTS)
#define 	TA8		(TA | EIGHT_PORTS)
#define		C_EN		0x0400		/* Cooking enabled (on MTA means port is also || */
#define		MR1_ODDPARITY	(MR1_WITH|MR1_ODD)	/* Odd parity */
#define		MR1_EVENPARITY	(MR1_WITH|MR1_EVEN)	/* Even parity */
#define		MR1_MARKPARITY	(MR1_FORCE|MR1_ODD)	/* Mark parity */
#define		MR1_SPACEPARITY	(MR1_FORCE|MR1_EVEN)	/* Space parity */

// drivers\serial\mps\spx\speed\uartlib\inc\private\16c65x.h
#define READ_FIFO_CONTROL_65X(pUart)			\
	((PUART_DATA_16C65X)((pUart)->pUartData))->CurrentFCR
#define READ_LINE_CONTROL_65X(pUart)		\
	((PUART_DATA_16C65X)((pUart)->pUartData))->CurrentLCR
#define READ_MODEM_CONTROL_65X(pUart)	\
	((PUART_DATA_16C65X)((pUart)->pUartData))->CurrentMCR

// drivers\serial\mps\spx\speed\uartlib\inc\private\16c95x.h
#define READ_FIFO_CONTROL(pUart)			\
	((PUART_DATA_16C95X)((pUart)->pUartData))->CurrentFCR
#define READ_LINE_CONTROL(pUart)		\
	((PUART_DATA_16C95X)((pUart)->pUartData))->CurrentLCR
#define READ_MODEM_CONTROL(pUart)	\
	((PUART_DATA_16C95X)((pUart)->pUartData))->CurrentMCR

// drivers\tpg\hwx\common\inc\frame.h
#define LpframeinfoFRAME(frame)		(&(frame)->info)

// drivers\tpg\hwx\common\inc\math16.h
#define Need(dw) (dw & 0xFF000000 ? 32 : (dw & 0x00FF0000 ? 24 : (dw & 0x0000FF00 ? 16 : 8)))

// drivers\tpg\hwx\common\inc\mathx.h
#define ANGLEDIFF(a,b,c)  {	\
	c	= b - a;			\
	if (c > 180) {			\
		c	-= 360;			\
	} else if (c <= -180) {	\
		c	+= 360;			\
	}						\
}

// drivers\tpg\hwx\commonu\inc\frame.h
#define LpframeinfoFRAME(frame)		(&(frame)->info)

// drivers\tpg\hwx\commonu\inc\math16.h
#define Need(dw) (dw & 0xFF000000 ? 32 : (dw & 0x00FF0000 ? 24 : (dw & 0x0000FF00 ? 16 : 8)))

// drivers\tpg\hwx\commonu\inc\mathx.h
#define ANGLEDIFF(a,b,c)  {	\
	c	= b - a;			\
	if (c > 180) {			\
		c	-= 360;			\
	} else if (c <= -180) {	\
		c	+= 360;			\
	}						\
}

// drivers\tpg\hwx\commonu\inc\recog.h
#define ALC_MATH			0x00000040	// %^*()-+={}<>,/.  (??? language dependent ???)
#define ALC_ALPHA			(ALC_LCALPHA | ALC_UCALPHA)
#define ALC_ALPHANUMERIC	(ALC_ALPHA | ALC_NUMERIC)
#define	ALC_KANJI_ALL		(ALC_KANJI_COMMON | ALC_KANJI_RARE)
#define	ALC_HANGUL_ALL		(ALC_HANGUL_COMMON | ALC_HANGUL_RARE)
#define	ALC_EXTENDED_SYM	(ALC_MATH | ALC_MONETARY | ALC_OTHER)
#define	ALC_USA_EXTENDED	(ALC_USA_COMMON | ALC_EXTENDED_SYM)
#define	ALC_JPN_COMMON		(ALC_SYS_DEFAULT | ALC_KANA | ALC_KANJI_COMMON)
#define	ALC_JPN_EXTENDED	(ALC_JPN_COMMON | ALC_EXTENDED_SYM | ALC_KANJI_RARE)
#define	ALC_CHS_COMMON		(ALC_SYS_DEFAULT | ALC_KANJI_COMMON)
#define	ALC_CHS_EXTENDED	(ALC_CHS_COMMON | ALC_EXTENDED_SYM | ALC_KANJI_RARE)
#define	ALC_CHT_COMMON		(ALC_SYS_DEFAULT | ALC_KANJI_COMMON)
#define	ALC_CHT_EXTENDED	(ALC_CHT_COMMON | ALC_EXTENDED_SYM | ALC_KANJI_RARE)
#define	ALC_KOR_COMMON		(ALC_SYS_DEFAULT | ALC_HANGUL_COMMON | ALC_JAMO)
#define	ALC_KOR_EXTENDED	(ALC_KOR_COMMON | ALC_EXTENDED_SYM | ALC_HANGUL_RARE | ALC_KANJI_COMMON | ALC_KANJI_RARE)

// drivers\tpg\hwx\commonu\inc\recogp.h
#define FIsSelectGesture(syv)   \
   ((syv) >= SYVSELECTFIRST && (syv) <= SYVSELECTLAST)
#define TRAIN_BOTH              (TRAIN_DEFAULT | TRAIN_CUSTOM)

// drivers\video\matrox\mga\disp\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\3dlabs\perm2\disp\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\3dlabs\perm3\disp\gdi\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\8514a\disp\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\ati\disp\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\cirrus\disp\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\compaq.qv\disp\driver.h
#define GLYPH_HASH_FUNC(x)  ((x) & (GLYPH_HASH_SIZE - 1))
#define OVERLAP(prcl, pptl)                                             \
    (((prcl)->right  > (pptl)->x)                                   &&  \
     ((prcl)->bottom > (pptl)->y)                                   &&  \
     ((prcl)->left   < ((pptl)->x + (prcl)->right - (prcl)->left))  &&  \
     ((prcl)->top    < ((pptl)->y + (prcl)->bottom - (prcl)->top)))

// drivers\video\ms\compaq.qv\disp\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\fsvga\drawscrn.c
#define CalcGRAMOffs(WindowSize,ScreenIfno,EmulateInfo) \
    (EmulateInfo->StartAddress + \
     CalcGRAMSize(WindowSize,ScreenInfo,EmulateInfo) \
    )

// drivers\video\ms\laguna\disp\cl5465\memmgr.c
	#define END_MUTEX(ppdev)	ReleaseMutex(ppdev->MutexHdl)

// drivers\video\ms\laguna\disp\cl5465\precomp.h
#define AVEC_NEED_SOURCE  (AVEC_S | AVEC_DS | AVEC_SP | AVEC_DSP)
#define AVEC_NEED_PATTERN (AVEC_P | AVEC_DP | AVEC_SP | AVEC_DSP)
#define AVEC_NEED_DEST    (AVEC_D | AVEC_DP | AVEC_DS | AVEC_DSP)

// drivers\video\ms\laguna\disp\cl546x\memmgr.c
	#define END_MUTEX(ppdev)	ReleaseMutex(ppdev->MutexHdl)

// drivers\video\ms\laguna\disp\cl546x\precomp.h
#define AVEC_NEED_SOURCE  (AVEC_S | AVEC_DS | AVEC_SP | AVEC_DSP)
#define AVEC_NEED_PATTERN (AVEC_P | AVEC_DP | AVEC_SP | AVEC_DSP)
#define AVEC_NEED_DEST    (AVEC_D | AVEC_DP | AVEC_DS | AVEC_DSP)

// drivers\video\ms\laguna\disp\include\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\s3\disp\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\vga\disp\4bpp\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\vga\disp\8bpp\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\w32\disp\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\weitek\disp\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\wdm\audio\legacy\wdmaud.sys\mixer.c
#define TargetTypeWaveIn( pmxobj, pLine )                             \
        (pLine)->Line.Target.dwType = MIXERLINE_TARGETTYPE_WAVEIN;    \
        (pLine)->Line.Target.wPid   = MM_MSFT_WDMAUDIO_WAVEIN;        \
        TargetCommon( pmxobj, pLine, WaveInDevice )
#define TargetTypeMidiOut( pmxobj, pLine )                          \
        (pLine)->Line.Target.dwType = MIXERLINE_TARGETTYPE_MIDIOUT; \
        (pLine)->Line.Target.wPid   = MM_MSFT_WDMAUDIO_MIDIOUT;     \
        TargetCommon( pmxobj, pLine, MidiOutDevice )
#define TargetTypeMidiIn( pmxobj, pLine )                             \
        (aLine)->Line.Target.dwType = MIXERLINE_TARGETTYPE_MIDIOUT;   \
        (aLine)->Line.Target.wPid   = MM_MSFT_WDMAUDIO_MIDIIN;        \
        TargetCommon( pmxobj, pLine, MidiInDevice )
#define TargetTypeAuxCD( pmxobj, pLine )                              \
        (pLine)->Line.Target.dwType = MIXERLINE_TARGETTYPE_AUX;       \
        TargetCommon( pmxobj, pLine, WaveOutDevice );   \
        (pLine)->Line.Target.wPid   = MM_MSFT_SB16_AUX_CD
#define TargetTypeAuxLine( pmxobj, pLine )                         \
        (pLine)->Line.Target.dwType = MIXERLINE_TARGETTYPE_AUX;    \
        TargetCommon( pmxobj, pLine, WaveOutDevice );\
        (pLine)->Line.Target.wPid   = MM_MSFT_SB16_AUX_LINE

// drivers\wdm\audio\sysaudio\fn.h
#define FILTER_TYPE_RENDER      (FILTER_TYPE_INTERFACE_TRANSFORM | \
                     FILTER_TYPE_GFX | \
                         FILTER_TYPE_AEC |  \
                     FILTER_TYPE_MIXER | \
                     FILTER_TYPE_SYNTHESIZER | \
                     FILTER_TYPE_DRM_DESCRAMBLE | \
                     FILTER_TYPE_VIRTUAL)
#define FILTER_TYPE_PRE_MIXER       (FILTER_TYPE_SYNTHESIZER | \
                     FILTER_TYPE_DRM_DESCRAMBLE | \
                     FILTER_TYPE_INTERFACE_TRANSFORM )

// drivers\wdm\input\client\hclient\ddksrc\ecdisp.c
#define OUTSTRING(win, str)         SendMessage(win, LB_ADDSTRING, 0, (LPARAM) str)

// drivers\wdm\input\client\hclient\ddksrc\extcalls.c
#define OUTSTRING(win, str)         SendMessage(win, LB_ADDSTRING, 0, (LPARAM) str)

// drivers\wdm\input\client\hclient\ecdisp.c
#define OUTSTRING(win, str)         SendMessage(win, LB_ADDSTRING, 0, (LPARAM) str)

// drivers\wdm\input\client\hidserv\hidserv.h
#define CrossSessionWindowMessage(m, w, l) \
    if (WinStaProc) { LONG response; \
    WinStaProc (NULL, InputSessionId, 5, HandleToUlong(hWndHidServ), (m), (w), (l), &response); }

// drivers\wdm\input\legacy\mshgame\gckernel.sys\gckshell.h
#define FILTER_DEVICE_OBJECT_PDO(__pDO__)\
		( ((PGCK_FILTER_EXT)__pDO__->DeviceExtension)->pPDO )

// drivers\wdm\usb\driver\isoperf\iso.h
#define PIPEINFO_FROM_DEVOBJ(D,I,P) (&(D->Interface[I]->Pipes[P]));

// ds\dns\server\server\msginfo.h
#define INITIALIZE_COMPRESSION( pMsg )  \
        {                               \
            (pMsg)->Compression.cCount      = 0;    \
            (pMsg)->Compression.pLastNode   = 0;    \
        }

// ds\ds\src\common\atq\auxctrs.h
# define AcIncrement( acCounter)   \
 (((acCounter) < NUM_AUX_COUNTERS) ?  \
   g_AuxCounters[acCounter]++ : \
  0)
# define AcDecrement( acCounter)   \
 (((acCounter) < NUM_AUX_COUNTERS) ?  \
  g_AuxCounters[acCounter]-- : \
  0)

// ds\netapi\svcimgs\ntrepl\inc\frs.h
#define FrsSetCompletionRoutine(_CmdPkt, _CompletionRoutine, _CompletionArg) { \
    (_CmdPkt)->CompletionRoutine = (_CompletionRoutine); \
    (_CmdPkt)->CompletionArg = (_CompletionArg); \
}

// ds\nw\convert\nwconv\columnlb.h
#define ColumnLB_GetNumberCols(hwndCtl)             ((int)(DWORD)SendMessage((hwndCtl), CLB_GETNUMBERCOLS, 0L, (LPARAM)0))
#define ColumnLB_SetNumberCols(hwndCtl,Number)      ((int)(DWORD)SendMessage((hwndCtl), CLB_SETNUMBERCOLS, (WPARAM)Number, (LPARAM)0))
#define ColumnLB_GetColWidth(hwndCtl,Column)        ((int)(DWORD)SendMessage((hwndCtl), CLB_GETCOLWIDTH, (WPARAM)Column, (LPARAM)0))
#define ColumnLB_SetColWidth(hwndCtl,Column, Width) ((int)(DWORD)SendMessage((hwndCtl), CLB_SETCOLWIDTH, (WPARAM)Column, (LPARAM)Width))
#define ColumnLB_GetColTitle(hwndCtl,Column)        ((LPTSTR)(DWORD)SendMessage((hwndCtl), CLB_GETCOLTITLE, (WPARAM)Column, (LPARAM)0))
#define ColumnLB_SetColTitle(hwndCtl,Column, Title) ((LPTSTR)(DWORD)SendMessage((hwndCtl), CLB_SETCOLTITLE, (WPARAM)Column, (LPARAM)Title))
#define ColumnLB_GetSortCol(hwndCtl)                ((DWORD)SendMessage((hwndCtl), CLB_GETSORTCOL, (WPARAM)0, (LPARAM)0))
#define ColumnLB_SetSortCol(hwndCtl,Column)         ((int)(DWORD)SendMessage((hwndCtl), CLB_SETSORTCOL, (WPARAM)Column, (LPARAM)0))
#define ColumnLB_AutoWidth(hwndCtl, Width)          ((int)(DWORD)SendMessage((hwndCtl), CLB_AUTOWIDTH, (WPARAM)Width, (LPARAM)0))
#define ColumnLB_GetColOffsets(hwndCtl)             ((LPINT)(DWORD)SendMessage((hwndCtl), CLB_GETCOLOFFSETS, (WPARAM)0, (LPARAM)0))
#define ColumnLB_SetColOffsets(hwndCtl,Offsets)     ((int)(DWORD)SendMessage((hwndCtl), CLB_SETCOLOFFSETS, (WPARAM)Offsets, (LPARAM)0))
#define ColumnLB_GetColOrder(hwndCtl)               ((LPBYTE)(DWORD)SendMessage((hwndCtl), CLB_GETCOLORDER, (WPARAM)0, (LPARAM)0))
#define ColumnLB_SetColOrder(hwndCtl, Order)        ((LPBYTE)(DWORD)SendMessage((hwndCtl), CLB_SETCOLORDER, (WPARAM)0, (LPARAM)Order))
#define ColumnLB_CheckFocus(hwndCtl)                ((BOOL)(DWORD)SendMessage((hwndCtl), CLB_CHECKFOCUS, (WPARAM)0, (LPARAM)0))
#define ColumnLB_GetCount(hwndCtl)                   ((int)(DWORD)SendMessage((hwndCtl), CLB_GETCOUNT, 0L, 0L))
#define ColumnLB_ResetContent(hwndCtl)               ((BOOL)(DWORD)SendMessage((hwndCtl), CLB_RESETCONTENT, 0L, 0L))
#define ColumnLB_AddString(hwndCtl, lpsz)            ((int)(DWORD)SendMessage((hwndCtl), CLB_ADDSTRING, 0L, (LPARAM)(LPCTSTR)(lpsz)))
#define ColumnLB_InsertString(hwndCtl, index, lpsz)  ((int)(DWORD)SendMessage((hwndCtl), CLB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCTSTR)(lpsz)))
#define ColumnLB_AddItemData(hwndCtl, data)          ((int)(DWORD)SendMessage((hwndCtl), CLB_ADDSTRING, 0L, (LPARAM)(data)))
#define ColumnLB_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), CLB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ColumnLB_GetTextLen(hwndCtl, index)          ((int)(DWORD)SendMessage((hwndCtl), CLB_GETTEXTLEN, (WPARAM)(int)(index), 0L))
#define ColumnLB_GetText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SendMessage((hwndCtl), CLB_GETTEXT, (WPARAM)(int)(index), (LPARAM)(LPCTSTR)(lpszBuffer)))
#define ColumnLB_GetTextPtrs(hwndCtl, index)        ((LPTSTR *)(DWORD)SendMessage((hwndCtl), CLB_GETTEXTPTRS, (WPARAM)(int)(index), (LPARAM)0))
#define ColumnLB_GetRowColText(hwndCtl, index, col)  (LPBYTE)(DWORD)SendMessage((hwndCtl), CLB_GETROWCOLTEXT, (WPARAM)(int) (col), (LPARAM)(int)(index))
#define ColumnLB_GetItemData(hwndCtl, index)         ((LRESULT)(DWORD)SendMessage((hwndCtl), CLB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ColumnLB_SetItemData(hwndCtl, index, data)   ((int)(DWORD)SendMessage((hwndCtl), CLB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ColumnLB_FindString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), CLB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ColumnLB_FindItemData(hwndCtl, indexStart, data) ((int)(DWORD)SendMessage((hwndCtl), CLB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ColumnLB_SetSel(hwndCtl, fSelect, index)     ((int)(DWORD)SendMessage((hwndCtl), CLB_SETSEL, (WPARAM)(BOOL)(fSelect), (LPARAM)(index)))
#define ColumnLB_SelItemRange(hwndCtl, fSelect, first, last)    ((int)(DWORD)SendMessage((hwndCtl), CLB_SELITEMRANGE, (WPARAM)(BOOL)(fSelect), MAKELPARAM((first), (last))))
#define ColumnLB_GetCurSel(hwndCtl)                  ((int)(DWORD)SendMessage((hwndCtl), CLB_GETCURSEL, 0L, 0L))
#define ColumnLB_SetCurSel(hwndCtl, index)           ((int)(DWORD)SendMessage((hwndCtl), CLB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ColumnLB_SelectString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), CLB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ColumnLB_SelectItemData(hwndCtl, indexStart, data)   ((int)(DWORD)SendMessage((hwndCtl), CLB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ColumnLB_GetSel(hwndCtl, index)              ((int)(DWORD)SendMessage((hwndCtl), CLB_GETSEL, (WPARAM)(int)(index), 0L))
#define ColumnLB_GetSelCount(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), CLB_GETSELCOUNT, 0L, 0L))
#define ColumnLB_GetTopIndex(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), CLB_GETTOPINDEX, 0L, 0L))
#define ColumnLB_GetSelItems(hwndCtl, cItems, lpItems) ((int)(DWORD)SendMessage((hwndCtl), CLB_GETSELITEMS, (WPARAM)(int)(cItems), (LPARAM)(int *)(lpItems)))
#define ColumnLB_SetTopIndex(hwndCtl, indexTop)      ((int)(DWORD)SendMessage((hwndCtl), CLB_SETTOPINDEX, (WPARAM)(int)(indexTop), 0L))
#define ColumnLB_SetColumnWidth(hwndCtl, cxColumn)   ((void)SendMessage((hwndCtl), CLB_SETCOLUMNWIDTH, (WPARAM)(int)(cxColumn), 0L))
#define ColumnLB_GetHorizontalExtent(hwndCtl)        ((int)(DWORD)SendMessage((hwndCtl), CLB_GETHORIZONTALEXTENT, 0L, 0L))
#define ColumnLB_SetHorizontalExtent(hwndCtl, cxExtent)     ((void)SendMessage((hwndCtl), CLB_SETHORIZONTALEXTENT, (WPARAM)(int)(cxExtent), 0L))
#define ColumnLB_SetTabStops(hwndCtl, cTabs, lpTabs) ((BOOL)(DWORD)SendMessage((hwndCtl), CLB_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(int *)(lpTabs)))
#define ColumnLB_GetItemRect(hwndCtl, index, lprc)   ((int)(DWORD)SendMessage((hwndCtl), CLB_GETITEMRECT, (WPARAM)(int)(index), (LPARAM)(RECT *)(lprc)))
#define ColumnLB_SetCaretIndex(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), CLB_SETCARETINDEX, (WPARAM)(int)(index), 0L))
#define ColumnLB_GetCaretIndex(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), CLB_GETCARETINDEX, 0L, 0L))
#define ColumnLB_FindStringExact(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), CLB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ColumnLB_SetItemHeight(hwndCtl, index, cy)   ((int)(DWORD)SendMessage((hwndCtl), CLB_SETITEMHEIGHT, (WPARAM)(int)(index), MAKELPARAM((cy), 0)))
#define ColumnLB_GetItemHeight(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), CLB_GETITEMHEIGHT, (WPARAM)(int)(index), 0L))
#define ColumnLB_Dir(hwndCtl, attrs, lpszFileSpec)   ((int)(DWORD)SendMessage((hwndCtl), CLB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCTSTR)(lpszFileSpec)))
#define ColumnLB_GetFocus(hwndCtl)   ((HWND)(DWORD)SendMessage((hwndCtl), CLB_GETFOCUS, 0L, 0L))

// ds\nw\convert\nwconv\tab.c
#define SetInstanceDataPtr(hwnd,x) (SetWindowLongPtr(hwnd, 0, (DWORD_PTR)x))

// ds\nw\convert\nwconv\tab.h
#define BookTab_AddItem(hwndCtl, text)            ((UINT)(DWORD)SendMessage((hwndCtl), BT_ADDITEM,        (WPARAM)(0),           (LPARAM)(LPCTSTR)(text) ))
#define BookTab_InsertItem(hwndCtl, index, text)  ((UINT)(DWORD)SendMessage((hwndCtl), BT_INSERTITEM,     (WPARAM)(UINT)(index), (LPARAM)(LPCTSTR)(text) ))
#define BookTab_SetItem(hwndCtl, index, text)     ((BOOL)(DWORD)SendMessage((hwndCtl), BT_SETITEM,        (WPARAM)(UINT)(index), (LPARAM)(LPCTSTR)(text) ))
#define BookTab_GetItem(hwndCtl, index, text)     ((BOOL)(DWORD)SendMessage((hwndCtl), BT_GETITEM,        (WPARAM)(UINT)(index), (LPARAM)(LPCTSTR)(text) ))
#define BookTab_SetCurSel(hwndCtl, index)         ((BOOL)(DWORD)SendMessage((hwndCtl), BT_SETCURSEL,      (WPARAM)(UINT)(index), (LPARAM)(0)            ))
#define BookTab_GetCurSel(hwndCtl)                ((UINT)(DWORD)SendMessage((hwndCtl), BT_GETCURSEL,      (WPARAM)(0),           (LPARAM)(0)            ))
#define BookTab_GetItemCount(hwndCtl)             ((UINT)(DWORD)SendMessage((hwndCtl), BT_GETITEMCOUNT,   (WPARAM)(0),           (LPARAM)(0)            ))
#define BookTab_SetItemData(hwndCtl, index, data) ((BOOL)(DWORD)SendMessage((hwndCtl), BT_SETITEMDATA,    (WPARAM)(UINT)(index), (LPARAM)(DWORD)(data)  ))
#define BookTab_GetItemData(hwndCtl, index)      ((DWORD)(DWORD)SendMessage((hwndCtl), BT_GETITEMDATA,    (WPARAM)(UINT)(index), (LPARAM)(0)            ))

// ds\nw\convert\nwconv\userdlg.c
#define SetStyleOn(hWnd, Style) SetWindowLong(hWnd, GWL_STYLE, Style | GetWindowLong(hWnd, GWL_STYLE));
#define SetStyleOff(hWnd, Style) SetWindowLong(hWnd, GWL_STYLE, ~Style & GetWindowLong(hWnd, GWL_STYLE));

// ds\nw\convert\nwconv\vlist.h
#define VLB_GETFOCUSHWND        (WM_USER+527)

// ds\nw\inc\ntddnwfs.h
#define NWR_ANY_NCP(X)                  _NWRDR_CONTROL_CODE(0x400 | (X), METHOD_NEITHER, FILE_ANY_ACCESS)
#define NWR_ANY_F2_NCP(X)               _NWRDR_CONTROL_CODE(0x500 | (X), METHOD_NEITHER, FILE_ANY_ACCESS)
#define NWR_ANY_HANDLE_NCP(X)           _NWRDR_CONTROL_CODE(0x600 | (X), METHOD_NEITHER, FILE_ANY_ACCESS)
#define NWR_ANY_NDS(X)                  _NWRDR_CONTROL_CODE(0x700 | (X), METHOD_NEITHER, FILE_ANY_ACCESS)

// ds\security\passport\pmconfig\pmcfg.h
#define GET_WM_COMMAND_HWND(wp, lp)             (HWND)(LOWORD(lp))

// enduser\netmeeting\as\h\dcs.h
#define     ETO_WINDOWS         (0x0001 | ETO_OPAQUE | ETO_CLIPPED)

// enduser\netmeeting\as\h\oa.h
#define ORDER_WIDTH(pOrder) \
 ( pOrder->OrderHeader.Common.rcsDst.right - \
                                pOrder->OrderHeader.Common.rcsDst.left + 1 )
#define ORDER_HEIGHT(pOrder) \
 ( pOrder->OrderHeader.Common.rcsDst.bottom - \
                                pOrder->OrderHeader.Common.rcsDst.top + 1 )

// enduser\netmeeting\h\confcli.h
#define CONFSENDMESSAGENAME	("ConfSendMessage")

// enduser\netmeeting\h\shell2.h
#define DRIVEID(path)   ((path[0] - 'A') & 31)
#define PRF_TRYPROGRAMEXTENSIONS    (0x0002 | PRF_VERIFYEXISTS)

// enduser\netmeeting\h\shellp.h
#define ShellFolderView_GetAnchorPoint(_hwnd, _fStart, _ppt) \
	(BOOL)((_fStart) ? ShellFolderView_GetDragPoint(_hwnd, _ppt) : ShellFolderView_GetDropPoint(_hwnd, _ppt))
#define ShellFolderView_SetItemPos(_hwnd, _pidl, _x, _y) \
{	SFV_SETITEMPOS _sip = {_pidl, {_x, _y}}; \
	SHShellFolderView_Message(_hwnd, SFVM_SETITEMPOS, (LPARAM)(LPSFV_SETITEMPOS)&_sip);}
#define SVM_SELECTITEM       		(WM_USER + 1)
#define SVM_MOVESELECTEDITEMS           (WM_USER + 2)
#define SVM_GETITEMPOSITION             (WM_USER + 4)
#define SVM_SELECTANDPOSITIONITEM       (WM_USER + 5)

// enduser\netmeeting\nmrk\util.h
#define TrackBar_ClearSel(hwnd, fRedraw) \
    (void)SendMessage((hwnd), TBM_CLEARSEL, (WPARAM) (BOOL) fRedraw, 0L)
#define TrackBar_ClearTics(hwnd, fRedraw) \
    (void)SendMessage((hwnd), TBM_CLEARTICS, (WPARAM) (BOOL) fRedraw, 0L)
#define TrackBar_GetChannelRect(hwnd, lprc) \
    (void)SendMessage((hwnd), TBM_GETCHANNELRECT, 0, (LPARAM) (LPRECT) lprc)
#define TrackBar_GetLineSize(hwnd) \
    (LONG)SendMessage((hwnd), TBM_GETLINESIZE, 0, 0L)
#define TrackBar_GetNumTics(hwnd) \
    (LONG)SendMessage((hwnd), TBM_GETNUMTICS, 0, 0L)
#define TrackBar_GetPageSize(hwnd) \
    (LONG)SendMessage((hwnd), TBM_GETPAGESIZE, 0, 0L)
#define TrackBar_GetPos(hwnd) \
    (LONG)SendMessage((hwnd), TBM_GETPOS, 0, 0L)
#define TrackBar_GetPTics(hwnd) \
    (LPLONG)SendMessage((hwnd), TBM_GETPTICS, 0, 0L)
#define TrackBar_GetRangeMax(hwnd) \
    (LONG)SendMessage((hwnd), TBM_GETRANGEMAX, 0, 0L)
#define TrackBar_GetRangeMin(hwnd) \
    (LONG)SendMessage((hwnd), TBM_GETRANGEMIN, 0, 0L)
#define TrackBar_GetSelEnd(hwnd) \
    (LONG)SendMessage((hwnd), TBM_GETSELEND, 0, 0L)
#define TrackBar_GetSelStart(hwnd) \
    (LONG)SendMessage((hwnd), TBM_GETSELSTART, 0, 0L)
#define TrackBar_GetThumbLength(hwnd) \
    (UINT)SendMessage((hwnd), TBM_GETTHUMBLENGTH, 0, 0L)
#define TrackBar_GetThumbRect(hwnd, lprc) \
    (void)SendMessage((hwnd), TBM_GETTHUMBRECT, 0, (LPARAM) (LPRECT) lprc)
#define TrackBar_GetTic(hwnd, iTic) \
    (LONG)SendMessage((hwnd), TBM_GETTIC, (WPARAM) (WORD) iTic, 0L)
#define TrackBar_GetTicPos(hwnd, iTic) \
    (LONG)SendMessage((hwnd), TBM_GETTICPOS, (WPARAM) (WORD) iTic, 0L)
#define TrackBar_SetLineSize(hwnd, lLineSize) \
    (LONG)SendMessage((hwnd), TBM_SETLINESIZE, 0, (LONG) lLineSize)
#define TrackBar_SetPageSize(hwnd, lPageSize) \
    (LONG)SendMessage((hwnd), TBM_SETPAGESIZE, 0, (LONG) lPageSize)
#define TrackBar_SetPos(hwnd, bPosition, lPosition) \
    (void)SendMessage((hwnd), TBM_SETPOS, (WPARAM) (BOOL) bPosition, (LPARAM) (LONG) lPosition)
#define TrackBar_SetRange(hwnd, bRedraw, lMinimum, lMaximum) \
    (void)SendMessage((hwnd), TBM_SETRANGE, (WPARAM) (BOOL) bRedraw, (LPARAM) MAKELONG(lMinimum, lMaximum))
#define TrackBar_SetRangeMax(hwnd, bRedraw, lMaximum) \
    (void)SendMessage((hwnd), TBM_SETRANGEMAX, (WPARAM) bRedraw, (LPARAM) lMaximum)
#define TrackBar_SetRangeMin(hwnd, bRedraw, lMinimum) \
    (void)SendMessage((hwnd), TBM_SETRANGEMIN, (WPARAM) bRedraw, (LPARAM) lMinimum)
#define TrackBar_SetSel(hwnd, bRedraw, lMinimum, lMaximum) \
    (void)SendMessage((hwnd), TBM_SETSEL, (WPARAM) (BOOL) bRedraw, (LPARAM) MAKELONG(lMinimum, lMaximum))
#define TrackBar_SetSelEnd(hwnd, bRedraw, lEnd) \
    (void)SendMessage((hwnd), TBM_SETSELEND, (WPARAM) (BOOL) bRedraw, (LPARAM) (LONG) lEnd)
#define TrackBar_SetSelStart(hwnd, bRedraw, lStart) \
    (void)SendMessage((hwnd), TBM_SETSELSTART, (WPARAM) (BOOL) bRedraw, (LPARAM) (LONG) lStart)
#define TrackBar_SetThumbLength(hwnd, iLength) \
    (void)SendMessage((hwnd), TBM_SETTHUMBLENGTH, (WPARAM) (UINT) iLength, 0L)
#define TrackBar_SetTic(hwnd, lPosition) \
    (BOOL)SendMessage((hwnd), TBM_SETTIC, 0, (LPARAM) (LONG) lPosition)
#define TrackBar_SetTicFreq(hwnd, wFreq, lPosition) \
    (void)SendMessage((hwnd), TBM_SETTICFREQ, (WPARAM) wFreq, (LPARAM) (LONG) lPosition)

// enduser\stuff\hhctrl\autoobj.h
#define DECLARE_STANDARD_SUPPORTERRORINFO() \
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) { \
		return CAutomationObject::InterfaceSupportsErrorInfo(riid); \
	} \

// enduser\stuff\hhctrl\cctlww.h
#define W_ComboBox_AddString(hwnd, psz)              ((int)(DWORD)W_SendStringMessage((hwnd), CB_ADDSTRING, 0L, psz))
#define W_ComboBox_InsertString(hwnd, index, psz)    ((int)(DWORD)W_SendStringMessage((hwnd), CB_INSERTSTRING,    (WPARAM)(int)(index), psz))
#define W_ComboBox_FindStringExact(hwnd, index, psz) ((int)(DWORD)W_SendStringMessage((hwnd), CB_FINDSTRINGEXACT, (WPARAM)(int)(index), psz))
#define W_ComboBox_SelectString(hwnd, index, psz)    ((int)(DWORD)W_SendStringMessage((hwnd), CB_SELECTSTRING,    (WPARAM)(int)(index), psz))
#define W_ListView_GetBkColor(hwnd)                         ListView_GetBkColor(hwnd)
#define W_ListView_SetBkColor(hwnd, clrBk)                  ListView_SetBkColor(hwnd, clrBk)
#define W_ListView_GetImageList(hwnd, iImageList)           ListView_GetImageList(hwnd, iImageList)
#define W_ListView_SetImageList(hwnd, himl, iImageList)     ListView_SetImageList(hwnd, himl, iImageList)
#define W_ListView_GetItemCount(hwnd)                       ListView_GetItemCount(hwnd)
#define W_ListView_GetItem(hwnd, pitem)                   W_ListView_GetItem_fn(hwnd, pitem)
#define W_ListView_SetItem(hwnd, pitem)                   W_ListView_SetItem_fn(hwnd, pitem)
#define W_ListView_InsertItem(hwnd, pitem)                W_ListView_InsertItem_fn(hwnd, pitem)
#define W_ListView_GetCallbackMask(hwnd)                    ListView_GetCallbackMask(hwnd)
#define W_ListView_SetCallbackMask(hwnd, mask)              ListView_SetCallbackMask(hwnd, mask)
#define W_ListView_GetNextItem(hwnd, i, flags)              ListView_GetNextItem(hwnd, i, flags)
#define W_ListView_FindItem(hwnd, iStart, plvfi)          W_ListView_FindItem_fn(hwnd, iStart, plvfi)
#define W_ListView_GetItemRect(hwnd, i, prc, code)          ListView_GetItemRect(hwnd, i, prc, code)
#define W_ListView_SetItemPosition(hwndLV, i, x, y)         ListView_SetItemPosition(hwndLV, i, x, y)
#define W_ListView_GetItemPosition(hwndLV, i, ppt)          ListView_GetItemPosition(hwndLV, i, ppt)
#define W_ListView_GetStringWidth(hwndLV, psz)            W_ListView_GetStringWidth_fn(hwndLV, psz)
#define W_ListView_HitTest(hwndLV, pinfo)                   ListView_HitTest(hwndLV, pinfo)
#define W_ListView_EnsureVisible(hwndLV, i, fPartialOK)     ListView_EnsureVisible(hwndLV, i, fPartialOK)
#define W_ListView_Scroll(hwndLV, dx, dy)                   ListView_Scroll(hwndLV, dx, dy)
#define W_ListView_RedrawItems(hwndLV, iFirst, iLast)       ListView_RedrawItems(hwndLV, iFirst, iLast)
#define W_ListView_Arrange(hwndLV, code)                    ListView_Arrange(hwndLV, code)
#define W_ListView_EditLabel(hwndLV, i)                   W_ListView_EditLabel_fn(hwndLV, i)
#define W_ListView_GetEditControl(hwndLV)                   ListView_GetEditControl(hwndLV)
#define W_ListView_GetColumn(hwnd, iCol, pcol)            W_ListView_GetColumn_fn(hwnd, iCol, pcol)
#define W_ListView_SetColumn(hwnd, iCol, pcol)            W_ListView_SetColumn_fn(hwnd, iCol, pcol)
#define W_ListView_InsertColumn(hwnd, iCol, pcol)         W_ListView_InsertColumn_fn(hwnd, iCol, pcol)
#define W_ListView_GetColumnWidth(hwnd, iCol)               ListView_GetColumnWidth(hwnd, iCol)
#define W_ListView_SetColumnWidth(hwnd, iCol, cx)           ListView_SetColumnWidth(hwnd, iCol, cx)
#define W_ListView_GetHeader(hwnd)                          ListView_GetHeader(hwnd)
#define W_ListView_CreateDragImage(hwnd, i, lpptUpLeft)     ListView_CreateDragImage(hwnd, i, lpptUpLeft)
#define W_ListView_GetViewRect(hwnd, prc)                   ListView_GetViewRect(hwnd, prc)
#define W_ListView_GetTextColor(hwnd)                       ListView_GetTextColor(hwnd)
#define W_ListView_SetTextColor(hwnd, clrText)              ListView_SetTextColor(hwnd, clrText)
#define W_ListView_GetTextBkColor(hwnd)                     ListView_GetTextBkColor(hwnd)
#define W_ListView_SetTextBkColor(hwnd, clrTextBk)          ListView_SetTextBkColor(hwnd, clrTextBk)
#define W_ListView_GetTopIndex(hwndLV)                      ListView_GetTopIndex(hwndLV)
#define W_ListView_GetCountPerPage(hwndLV)                  ListView_GetCountPerPage(hwndLV)
#define W_ListView_GetOrigin(hwndLV, ppt)                   ListView_GetOrigin(hwndLV, ppt)
#define W_ListView_Update(hwndLV, i)                        ListView_Update(hwndLV, i)
#define W_ListView_SetItemState(hwndLV, i, data, mask)      ListView_SetItemState(hwndLV, i, data, mask)
#define W_ListView_GetItemState(hwndLV, i, mask)            ListView_GetItemState(hwndLV, i, mask)
#define W_ListView_GetCheckState(hwndLV, i)                 ListView_GetCheckState(hwndLV, i)
#define W_ListView_GetItemText(hwndLV, i, iSubItem_, pszText_, cchTextMax_) W_ListView_GetItemText_fn(hwndLV, i, iSubItem_, pszText_, cchTextMax_)
#define W_ListView_SetItemText(hwndLV, i, iSubItem_, pszText_)              W_ListView_SetItemText_fn(hwndLV, i, iSubItem_, pszText_)
#define W_ListView_SetItemCount(hwndLV, cItems)             ListView_SetItemCount(hwndLV, cItems)
#define W_ListView_SetItemCountEx(hwndLV, cItems, dwFlags)  ListView_SetItemCountEx(hwndLV, cItems, dwFlags)
#define W_ListView_SortItems(hwndLV, _pfnCompare, _lPrm)    ListView_SortItems(hwndLV, _pfnCompare, _lPrm)
#define W_ListView_SetItemPosition32(hwndLV, i, x, y)       ListView_SetItemPosition32(hwndLV, i, x, y)
#define W_ListView_GetSelectedCount(hwndLV)                 ListView_GetSelectedCount(hwndLV)
#define W_ListView_GetItemSpacing(hwndLV, fSmall)           ListView_GetItemSpacing(hwndLV, fSmall)
#define W_ListView_GetISearchString(hwndLV, lpsz)         W_ListView_GetISearchString_fn(hwndLV, lpsz)
#define W_ListView_SetIconSpacing(hwndLV, cx, cy)           ListView_SetIconSpacing(hwndLV, cx, cy)
#define W_ListView_SetExtendedListViewStyle(hwndLV, dw)             ListView_SetExtendedListViewStyle(hwndLV, dw)
#define W_ListView_SetExtendedListViewStyleEx(hwndLV, dwMask, dw)   ListView_SetExtendedListViewStyleEx(hwndLV, dwMask, dw)
#define W_ListView_GetExtendedListViewStyle(hwndLV)                 ListView_GetExtendedListViewStyle(hwndLV)
#define W_ListView_GetExtendedListViewStyle(hwndLV)                 ListView_GetExtendedListViewStyle(hwndLV)
#define W_ListView_GetSubItemRect(hwnd, iItem, iSubItem, code, prc) ListView_GetSubItemRect(hwnd, iItem, iSubItem, code, prc)
#define W_ListView_SubItemHitTest(hwnd, plvhti)                     ListView_SubItemHitTest(hwnd, plvhti)
#define W_ListView_SetColumnOrderArray(hwnd, iCount, pi)            ListView_SetColumnOrderArray(hwnd, iCount, pi)
#define W_ListView_GetColumnOrderArray(hwnd, iCount, pi)            ListView_GetColumnOrderArray(hwnd, iCount, pi)
#define W_ListView_SetHotItem(hwnd, i)                              ListView_SetHotItem(hwnd, i)
#define W_ListView_GetHotItem(hwnd)                                 ListView_GetHotItem(hwnd)
#define W_ListView_SetHotCursor(hwnd, hcur)                         ListView_SetHotCursor(hwnd, hcur)
#define W_ListView_GetHotCursor(hwnd)                               ListView_GetHotCursor(hwnd)
#define W_ListView_ApproximateViewRect(hwnd, iWidth, iHeight, iCount)   ListView_ApproximateViewRect(hwnd, iWidth, iHeight, iCount)
#define W_ListView_SetWorkAreas(hwnd, nWorkAreas, prc)              ListView_SetWorkAreas(hwnd, nWorkAreas, prc)
#define W_ListView_GetWorkAreas(hwnd, nWorkAreas, prc)              ListView_GetWorkAreas(hwnd, nWorkAreas, prc)
#define W_ListView_GetNumberOfWorkAreas(hwnd, pnWorkAreas)          ListView_GetNumberOfWorkAreas(hwnd, pnWorkAreas)
#define W_ListView_GetSelectionMark(hwnd)                           ListView_GetSelectionMark(hwnd)
#define W_ListView_SetSelectionMark(hwnd, i)                        ListView_SetSelectionMark(hwnd, i)
#define W_ListView_SetHoverTime(hwndLV, dwHoverTimeMs)              ListView_SetHoverTime(hwndLV, dwHoverTimeMs)
#define W_ListView_GetHoverTime(hwndLV)                             ListView_GetHoverTime(hwndLV)
#define W_ListView_SetToolTipHwnd(hwndLV, hwndNewHwnd)              ListView_SetToolTipHwnd(hwndLV, hwndNewHwnd)
#define W_ListView_GetToolTipHwnd(hwndLV)                           ListView_GetToolTipHwnd(hwndLV)
#define W_ListView_SetBkImage(hwnd, plvbki)                       W_ListView_SetBkImage_fn(hwnd, plvbki)
#define W_ListView_GetBkImage(hwnd, plvbki)                       W_ListView_GetBkImage_fn(hwnd, plvbki)
#define W_TreeView_InsertItem(hwnd, lpis)                   W_TreeView_InsertItem_fn(hwnd, lpis)
#define W_TreeView_Expand(hwnd, hitem, code)                TreeView_Expand(hwnd, hitem, code)
#define W_TreeView_GetItemRect(hwnd, hitem, prc, code)      TreeView_GetItemRect(hwnd, hitem, prc, code)
#define W_TreeView_GetCount(hwnd)                           TreeView_GetCount(hwnd)
#define W_TreeView_GetIndent(hwnd)                          TreeView_GetIndent(hwnd)
#define W_TreeView_SetIndent(hwnd, indent)                  TreeView_SetIndent(hwnd, indent)
#define W_TreeView_GetImageList(hwnd, iImage)               TreeView_GetImageList(hwnd, iImage)
#define W_TreeView_SetImageList(hwnd, himl, iImage)         TreeView_SetImageList(hwnd, himl, iImage)
#define W_TreeView_GetNextItem(hwnd, hitem, code)           TreeView_GetNextItem(hwnd, hitem, code)
#define W_TreeView_GetChild(hwnd, hitem)                    TreeView_GetChild(hwnd, hitem)
#define W_TreeView_GetNextSibling(hwnd, hitem)              TreeView_GetNextSibling(hwnd, hitem)
#define W_TreeView_GetPrevSibling(hwnd, hitem)              TreeView_GetPrevSibling(hwnd, hitem)
#define W_TreeView_GetParent(hwnd, hitem)                   TreeView_GetParent(hwnd, hitem)
#define W_TreeView_GetFirstVisible(hwnd)                    TreeView_GetFirstVisible(hwnd)
#define W_TreeView_GetNextVisible(hwnd, hitem)              TreeView_GetNextVisible(hwnd, hitem)
#define W_TreeView_GetPrevVisible(hwnd, hitem)              TreeView_GetPrevVisible(hwnd, hitem)
#define W_TreeView_GetSelection(hwnd)                       TreeView_GetSelection(hwnd)
#define W_TreeView_GetDropHilight(hwnd)                     TreeView_GetDropHilight(hwnd)
#define W_TreeView_GetRoot(hwnd)                            TreeView_GetRoot(hwnd)
#define W_TreeView_GetLastVisible(hwnd)                     TreeView_GetLastVisible(hwnd)
#define W_TreeView_Select(hwnd, hitem, code)                TreeView_Select(hwnd, hitem, code)
#define W_TreeView_SelectItem(hwnd, hitem)                  TreeView_SelectItem(hwnd, hitem)
#define W_TreeView_SelectDropTarget(hwnd, hitem)            TreeView_SelectDropTarget(hwnd, hitem)
#define W_TreeView_SelectSetFirstVisible(hwnd, hitem)       TreeView_SelectSetFirstVisible(hwnd, hitem)
#define W_TreeView_GetItem(hwnd, pitem)                   W_TreeView_GetItem_fn(hwnd, pitem)
#define W_TreeView_SetItem(hwnd, pitem)                   W_TreeView_SetItem_fn(hwnd, pitem)
#define W_TreeView_EditLabel(hwnd, hitem)                 W_TreeView_EditLabel_fn(hwnd, hitem)
#define W_TreeView_GetEditControl(hwnd)                     TreeView_GetEditControl(hwnd)
#define W_TreeView_GetVisibleCount(hwnd)                    TreeView_GetVisibleCount(hwnd)
#define W_TreeView_HitTest(hwnd, lpht)                      TreeView_HitTest(hwnd, lpht)
#define W_TreeView_CreateDragImage(hwnd, hitem)             TreeView_CreateDragImage(hwnd, hitem)
#define W_TreeView_SortChildren(hwnd, hitem, recurse)       TreeView_SortChildren(hwnd, hitem, recurse)
#define W_TreeView_EnsureVisible(hwnd, hitem)               TreeView_EnsureVisible(hwnd, hitem)
#define W_TreeView_SortChildrenCB(hwnd, psort, recurse)     TreeView_SortChildrenCB(hwnd, psort, recurse)
#define W_TreeView_EndEditLabelNow(hwnd, fCancel)           TreeView_EndEditLabelNow(hwnd, fCancel)
#define W_TreeView_SetToolTips(hwnd,  hwndTT)               TreeView_SetToolTips(hwnd,  hwndTT)
#define W_TreeView_GetToolTips(hwnd)                        TreeView_GetToolTips(hwnd)
#define W_TreeView_GetISearchString(hwndTV, lpsz)         W_TreeView_GetISearchString_fn(hwndTV, lpsz)
#define W_TreeView_SetInsertMark(hwnd, hItem, fAfter)       TreeView_SetInsertMark(hwnd, hItem, fAfter)
#define W_TreeView_SetItemHeight(hwnd,  iHeight)            TreeView_SetItemHeight(hwnd,  iHeight)
#define W_TreeView_GetItemHeight(hwnd)                      TreeView_GetItemHeight(hwnd)
#define W_TreeView_SetBkColor(hwnd, clr)                    TreeView_SetBkColor(hwnd, clr)
#define W_TreeView_SetTextColor(hwnd, clr)                  TreeView_SetTextColor(hwnd, clr)
#define W_TreeView_GetBkColor(hwnd)                         TreeView_GetBkColor(hwnd)
#define W_TreeView_GetTextColor(hwnd)                       TreeView_GetTextColor(hwnd)
#define W_TreeView_SetScrollTime(hwnd, uTime)               TreeView_SetScrollTime(hwnd, uTime)
#define W_TreeView_GetScrollTime(hwnd)                      TreeView_GetScrollTime(hwnd)
#define W_TabCtrl_GetImageList(hwnd)                        TabCtrl_GetImageList(hwnd)
#define W_TabCtrl_SetImageList(hwnd, himl)                  TabCtrl_SetImageList(hwnd, himl)
#define W_TabCtrl_GetItemCount(hwnd)                        TabCtrl_GetItemCount(hwnd)
#define W_TabCtrl_GetItem(hwnd, iItem, pitem)             W_TabCtrl_GetItem_fn(hwnd, iItem, pitem)
#define W_TabCtrl_SetItem(hwnd, iItem, pitem)             W_TabCtrl_SetItem_fn(hwnd, iItem, pitem)
#define W_TabCtrl_InsertItem(hwnd, iItem, pitem)          W_TabCtrl_InsertItem_fn(hwnd, iItem, pitem)
#define W_TabCtrl_GetItemRect(hwnd, i, prc)                 TabCtrl_GetItemRect(hwnd, i, prc)
#define W_TabCtrl_GetCurSel(hwnd)                           TabCtrl_GetCurSel(hwnd)
#define W_TabCtrl_SetCurSel(hwnd, i)                        TabCtrl_SetCurSel(hwnd, i)
#define W_TabCtrl_HitTest(hwndTC, pinfo)                    TabCtrl_HitTest(hwndTC, pinfo)
#define W_TabCtrl_SetItemExtra(hwndTC, cb)                  TabCtrl_SetItemExtra(hwndTC, cb)
#define W_TabCtrl_AdjustRect(hwnd, bLarger, prc)            TabCtrl_AdjustRect(hwnd, bLarger, prc)
#define W_TabCtrl_SetItemSize(hwnd, x, y)                   TabCtrl_SetItemSize(hwnd, x, y)
#define W_TabCtrl_RemoveImage(hwnd, i)                      TabCtrl_RemoveImage(hwnd, i)
#define W_TabCtrl_SetPadding(hwnd,  cx, cy)                 TabCtrl_SetPadding(hwnd,  cx, cy)
#define W_TabCtrl_GetRowCount(hwnd)                         TabCtrl_GetRowCount(hwnd)
#define W_TabCtrl_GetToolTips(hwnd)                         TabCtrl_GetToolTips(hwnd)
#define W_TabCtrl_SetToolTips(hwnd, hwndTT)                 TabCtrl_SetToolTips(hwnd, hwndTT)
#define W_TabCtrl_GetCurFocus(hwnd)                         TabCtrl_GetCurFocus(hwnd)
#define W_TabCtrl_SetCurFocus(hwnd, i)                      TabCtrl_SetCurFocus(hwnd, i)
#define W_TabCtrl_SetMinTabWidth(hwnd, x)                   TabCtrl_SetMinTabWidth(hwnd, x)
#define W_TabCtrl_DeselectAll(hwnd, fExcludeFocus)          TabCtrl_DeselectAll(hwnd, fExcludeFocus)
#define W_TabCtrl_HighlightItem(hwnd, i, fHighlight)        TabCtrl_HighlightItem(hwnd, i, fHighlight)
#define W_TabCtrl_SetExtendedStyle(hwnd, dw)                TabCtrl_SetExtendedStyle(hwnd, dw)
#define W_TabCtrl_GetExtendedStyle(hwnd)                    TabCtrl_GetExtendedStyle(hwnd)
#define W_TabCtrl_SetUnicodeFormat(hwnd, fUnicode)          TabCtrl_SetUnicodeFormat(hwnd, fUnicode)
#define W_TabCtrl_GetUnicodeFormat(hwnd)                    TabCtrl_GetUnicodeFormat(hwnd)

// enduser\stuff\itircl\common\wrapstor.cpp
#define LI_To_FO(LI)    (*PLI_To_PFO(&LI))
#define FO_To_LI(FO) (*PFO_To_PLI(&FO))

// enduser\stuff\itircl\fts\common\common.h
#define DLLGMEM_ZEROINIT        (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define DLLGMEM                 (GMEM_MOVEABLE | GMEM_SHARE)

// enduser\stuff\itircl\inc\address.h
#define MVAddrCompare(x1, x2) (\
								((x1).tpid != (x2).tpid) ? \
                                    (((x1).tpid > (x2).tpid) ? 1 : -1) : \
                                    ( \
										((x1).tpo != (x2).tpo) ? (((x1).tpo > (x2).tpo) ? 1 : -1) : 0 \
									) \
                              )

// enduser\windows.com\iuengine\wubios\inc\vmm.h
#define VMM_TRUE    (~FALSE)	// The opposite of False!
#define CONFIGMG_DEVICE_ID  0x00033 /* Configuration manager (Plug&Play) */
#define P_AVAIL     (P_PRES+P_WRITE+P_USER) /* avail to user & present */

// enduser\windows.com\wuau\wuaueng\prsheet.cpp
#define HANDLE_WM_HELP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HELPINFO *)(lParam)))
#define FORWARD_WM_HELP(hwnd, pHelpInfo, fn) \
    (void)(fn)((hwnd), WM_HELP, (WPARAM)0, (LPARAM)pHelpInfo)
#define HANDLE_PWM_INITUPDATESOBJECT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (UPDATESOBJ_DATA *)(lParam)))

// enduser\windows.com\wuv3\wudetect\utils2.h
#define IsSpace(c)  ((c) == ' '  ||  (c) == '\t'  ||  (c) == '\r'  ||  (c) == '\n'  ||  (c) == '\v'  ||  (c) == '\f')

// inetcore\connectionwizard\inc\ocdb.h
#define ICursor_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursor_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursor_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorMove_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorMove_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorMove_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorScroll_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorScroll_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorScroll_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorUpdateARow_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorUpdateARow_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorUpdateARow_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorFind_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorFind_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorFind_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define INotifyDBEvents_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define INotifyDBEvents_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define INotifyDBEvents_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))

// inetcore\datacab\viaduct\msr2c\fastguid.h
#define QI_INTERFACE_SUPPORTED(pObj, itf)              \
    case Data1_##itf:                       \
      if(DO_GUIDS_MATCH(riid, IID_##itf))    \
      {                                     \
        *ppvObjOut = (void *)(itf *)pObj;   \
      }                                     \
      break;
#define QI_INTERFACE_SUPPORTED_IF(pObj, itf, supportif) \
    case Data1_##itf:                       \
      if(supportif && DO_GUIDS_MATCH(riid, IID_##itf))    \
      {                                     \
        *ppvObjOut = (void *)(itf *)pObj;   \
      }                                     \
      break;

// inetcore\datacab\viaduct\msr2c\ocdb.h
#define ICursor_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursor_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursor_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorMove_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorMove_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorMove_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorScroll_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorScroll_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorScroll_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorUpdateARow_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorUpdateARow_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorUpdateARow_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorFind_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorFind_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorFind_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define INotifyDBEvents_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define INotifyDBEvents_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define INotifyDBEvents_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))

// inetcore\mshtml\external\inc\vbcursor\ocdb.h
#define ICursor_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursor_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursor_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorMove_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorMove_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorMove_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorScroll_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorScroll_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorScroll_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorUpdateARow_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorUpdateARow_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorUpdateARow_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define ICursorFind_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define ICursorFind_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define ICursorFind_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define INotifyDBEvents_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define INotifyDBEvents_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define INotifyDBEvents_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))

// inetcore\mshtml\iextag\peerfact.cxx
#define DECLARE_BEHAVIOR(className)                                     \
    HRESULT className##_CreateInstance(IElementBehavior ** ppBehavior)  \
    {                                                                   \
        HRESULT                 hr;                                     \
        CComObject<className> * pInstance;                              \
                                                                        \
        hr = CComObject<className>::CreateInstance(&pInstance);         \
        if (hr)                                                         \
            goto Cleanup;                                               \
                                                                        \
        hr = pInstance->QueryInterface(                                 \
                IID_IElementBehavior, (void**) ppBehavior);             \
                                                                        \
    Cleanup:                                                            \
        return hr;                                                      \
    }                                                                   \

// inetcore\mshtml\imgfilt\atlcom.h
#define DECLARE_GET_CONTROLLING_UNKNOWN() public:\
	virtual IUnknown* GetControllingUnknown() {return GetUnknown();}

// inetcore\mshtml\src\site\dbind\provider.cxx
#define TEST(intf, EnsureFn, _pIntf) \
    if (IsEqualIID(riid, intf))     \
    {                               \
        if (EnsureFn())             \
        {                           \
            _pIntf->AddRef();       \
            *ppvUnk = _pIntf;       \
            hr = S_OK;              \
        }                           \
    }

// inetcore\mshtml\src\site\display\dispnode.hxx
#define DISPEX_ANYBORDER      (DISPEX_SIMPLEBORDER | DISPEX_COMPLEXBORDER)

// inetcore\mshtml\tried\triedctl\dhtmledit.h
#define DOCUMENT_COMPETE_MESSAGE	(WM_USER+18)

// inetcore\outlookexpress\autodiscovery\client\fromshell.h
#define ISVISIBLE(hwnd)  ((GetWindowStyle(hwnd) & WS_VISIBLE) == WS_VISIBLE)

// inetcore\outlookexpress\import\dllmain.cpp
#define ICC_FLAGS (ICC_LISTVIEW_CLASSES|ICC_PROGRESS_CLASS|ICC_NATIVEFNTCTL_CLASS)

// inetcore\outlookexpress\inc\athena16.h
#define HANDLE_WM_CONTEXTMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define HANDLE_WM_CTLCOLORSTATIC(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_STATIC)

// inetcore\outlookexpress\inc\mirror.h
#define IS_WINDOW_RTL_MIRRORED(hwnd)     (g_bMirroredOS && Mirror_IsWindowMirroredRTL(hwnd))

// inetcore\outlookexpress\inc\msoert.h
#define HANDLE_COMMAND(hwnd, id, hwndCtl, codeNotify, fn) \
                case (id): { (fn)((HWND)(hwnd), (HWND)(hwndCtl), (UINT)(codeNotify)); break; }
#define SetWndThisPtrOnCreate(hwnd, lpcs) \
    SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)(((LPCREATESTRUCT)lpcs)->lpCreateParams))
#define ListView_GetSelFocused(_hwndlist)        ListView_GetNextItem(_hwndlist, -1, LVNI_SELECTED|LVIS_FOCUSED)
#define ListView_GetFirstSel(_hwndlist)          ListView_GetNextItem(_hwndlist, -1, LVNI_SELECTED)
#define ListView_GetFocusedItem(_hwndlist)       ListView_GetNextItem(_hwndlist, -1, LVNI_FOCUSED)
#define ListView_SelectItem(_hwndlist, _i)       ListView_SetItemState(_hwndlist, _i, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED)
#define ListView_UnSelectItem(_hwndlist, _i)     ListView_SetItemState(_hwndlist, _i, 0, LVIS_SELECTED)
#define ListView_FocusItem(_hwndlist, _i)        ListView_SetItemState(_hwndlist, _i, LVIS_FOCUSED, LVIS_FOCUSED)
#define ListView_UnSelectAll(_hwndlist)          { \
                                                 ListView_SetItemState(_hwndlist, -1, 0, LVIS_SELECTED|LVIS_FOCUSED); \
                                                 ListView_SetSelectionMark(_hwndlist, -1); \
                                                 }
#define ListView_UnSelectAll(_hwndlist)          ListView_SetItemState(_hwndlist, -1, 0, LVIS_SELECTED|LVIS_FOCUSED);
#define ListView_SelectAll(_hwndlist)            ListView_SetItemState(_hwndlist, -1, LVIS_SELECTED, LVIS_SELECTED)

// inetcore\outlookexpress\mailnews\common\tbbands.cpp
#define IS_LIST_STYLE(hwnd) (!!(GetWindowLong(hwnd, GWL_STYLE) & TBSTYLE_LIST))

// inetcore\outlookexpress\mailnews\common\util.h
#define FReadOnlyEdit(hwndEdit)  (BOOL)(GetWindowLong(hwndEdit, GWL_STYLE)&ES_READONLY)

// inetcore\outlookexpress\mailnews\mail\header.cpp
#define GET_WM_COMMAND_HWND(wp, lp) (HWND)(lp)

// inetcore\outlookexpress\mailnews\view\msgview.cpp
#define HANDLE_WM_POSTCREATE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_POSTCREATE(hwnd, fn) \
    (void)(fn)((hwnd), WM_POSTCREATE, 0L, 0L)
#define HANDLE_WM_TEST_GETMSGID(hwnd, wParam, lParam, fn) \
    (LRESULT)((fn)(hwnd))
#define FORWARD_WM_TEST_GETMSGID(hwnd, fn) \
    (LRESULT)(fn)((hwnd), WM_TEST_GETMSGID, 0L, 0L)
#define HANDLE_WM_TEST_SAVEMSG(hwnd, wParam, lParam, fn) \
    (LRESULT)((fn)(hwnd))
#define FORWARD_WM_TEST_SAVEMSG(hwnd, fn) \
    (LRESULT)(fn)((hwnd), WM_TEST_SAVEMSG, 0L, 0L)

// inetcore\outlookexpress\mailnews\view\msgview.h
#define HANDLE_WM_FOLDER_LOADED(hwnd, wParam, lParam, fn)    \
    OnFolderLoaded((hwnd), (wParam), (lParam))

// inetcore\outlookexpress\wabw\wabapi\ui_cflct.c
#define ListView_GetFirstSel(_hwndlist)          ListView_GetNextItem(_hwndlist, -1, LVNI_SELECTED)

// inetcore\outlookexpress\wabw\wabapi\ui_pwd.c
#define HANDLE_COMMAND(hwnd, id, hwndCtl, codeNotify, fn) \
                case (id): { (fn)((HWND)(hwnd), (HWND)(hwndCtl), (UINT)(codeNotify)); break; }

// inetcore\setup\active\iernonce\iernonce.cpp
#define FillExecInfo(_info, _hwnd, _verb, _file, _params, _dir, _show) \
        (_info).hwnd            = _hwnd;        \
        (_info).lpVerb          = _verb;        \
        (_info).lpFile          = _file;        \
        (_info).lpParameters    = _params;      \
        (_info).lpDirectory     = _dir;         \
        (_info).nShow           = _show;        \
        (_info).fMask           = 0;            \
        (_info).cbSize          = sizeof(SHELLEXECUTEINFO);

// inetcore\setup\active\inc\autoobj.h
#define DECLARE_STANDARD_SUPPORTERRORINFO() \
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) { \
        return CAutomationObject::InterfaceSupportsErrorInfo(riid); \
    } \

// inetcore\setup\active\inc\prsht.h
#define PSM_RESTARTWINDOWS      (WM_USER + 105)
#define PSM_GETTABCONTROL       (WM_USER + 116)
#define PSM_GETCURRENTPAGEHWND  (WM_USER + 118)
#define ID_PSREBOOTSYSTEM       (ID_PSRESTARTWINDOWS | 0x1)

// inetcore\setup\ieak5\ieakeng\adm.cpp
#define GetFirstPolicyItem(hTreeView)    ((g_hPolicyRootItem != NULL) ? TreeView_GetChild(hTreeView, g_hPolicyRootItem) : TreeView_GetRoot(hTreeView))

// inetcore\setup\ieak5\ieaksie\privacy.cpp
#define ENABLEAPPLY(hDlg) SendMessage( GetParent(hDlg), PSM_CHANGED, (WPARAM)hDlg, 0L )

// inetcore\setup\ieak5\parser\controls.h
#define CSW_BOLDLABEL       (CSW_LABEL | 0x00000010)
#define CSW_ITALICLABEL     (CSW_LABEL | 0x00000020)

// inetcore\winhttp\tools\w3spoof\inc\resources.h
#define SHELLMESSAGE_W3SICON (WM_USER+12387)

// inetcore\winhttp\v5.1\common\parsers.cxx
#define isspace(ch) ((ch==0x20) || ((ch >= 0x09) && (ch <= 0x0d)))

// inetcore\winhttp\v5\common\parsers.cxx
#define isspace(ch) ((ch==0x20) || ((ch >= 0x09) && (ch <= 0x0d)))

// inetcore\wininet\common\parsers.cxx
#define isspace(ch) ((ch==0x20) || ((ch >= 0x09) && (ch <= 0x0d)))

// inetsrv\iis\config\src\complib\inc\crtwrap.h
#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

// inetsrv\iis\config\src\complib\stgdb\stgdef.h
#define COL_NO_DATA_LIMIT	((USHORT) ~0)

// inetsrv\iis\config\src\inc\corhdr.h
#define IsAfImplicitComTypes(x)             ((x) & afImplicitComTypes)

// inetsrv\iis\config\src\wmi\atl30\atlcom.h
#define DECLARE_GET_CONTROLLING_UNKNOWN() public:\
	virtual IUnknown* GetControllingUnknown() {return GetUnknown();}

// inetsrv\iis\config\src\wmi\atl30\atldb.h
#define INIT_HWND_Flags ( DBPROPFLAGS_DBINIT | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE )

// inetsrv\iis\iisrearc\core\common\util\useracl.cxx
#define GENERIC_ACCESS (GENERIC_READ | GENERIC_WRITE |GENERIC_EXECUTE | GENERIC_ALL)

// inetsrv\iis\svcs\infocomm\atq\auxctrs.h
# define AcIncrement( acCounter)   \
 (((acCounter) < NUM_AUX_COUNTERS) ?  \
   g_AuxCounters[acCounter]++ : \
  0)
# define AcDecrement( acCounter)   \
 (((acCounter) < NUM_AUX_COUNTERS) ?  \
  g_AuxCounters[acCounter]-- : \
  0)

// inetsrv\iis\svcs\infocomm\cache\creatfil.cxx
#define WAIT_FOR_PHYS_INIT_COMPLETE( lpPFInfo )                             \
    if( !lpPFInfo->fInitComplete ) {                                        \
        WaitForPhysInitComplete( lpPFInfo );                                \
    } else

// inetsrv\iis\svcs\infocomm\common\md5c.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// inetsrv\iis\svcs\infocomm\common\tcputil.cxx
#define UC(b)   (((int)b)&0xff)

// inetsrv\iis\svcs\infocomm\dcomadm\dll\admacl.hxx
#define ISPATHDELIM(a) ((a)=='/' || (a)=='\\')

// inetsrv\iis\svcs\infocomm\setup\svcsetup.c
# define SetServiceTypeValues( pSvcTypeValue, dwNS, dwType, dwSize, lpValName, lpVal)   \
       ( pSvcTypeValue)->dwNameSpace = ( dwNS);           \
       ( pSvcTypeValue)->dwValueType = ( dwType);         \
       ( pSvcTypeValue)->dwValueSize = ( dwSize);         \
       ( pSvcTypeValue)->lpValueName = ( lpValName);      \
       ( pSvcTypeValue)->lpValue     = (PVOID ) ( lpVal); \

// inetsrv\iis\svcs\smtp\server\smtpcli.hxx
     #define SmtpDef(Smtp) &SMTP_CONNECTION::Do##Smtp##Command,

// inetsrv\iis\svcs\w3\filters\compress\inc\compfilt.h
#define RAW_DATA_AND_END_OF_REQ (SF_NOTIFY_SEND_RAW_DATA | SF_NOTIFY_END_OF_REQUEST )

// inetsrv\msmq\src\ac\win95\ntddk95.h
#define IRP_MN_COMPLETE_MDL             (IRP_MN_COMPLETE | IRP_MN_MDL)
#define IRP_MN_COMPLETE_MDL_DPC         (IRP_MN_COMPLETE_MDL | IRP_MN_DPC)

// inetsrv\msmq\src\apps\mqdiag\mqtry\msmqdefs.h
#define MQSendMessage_FUNCTION  		(*pf_MQSendMessage)

// inetsrv\msmq\src\qm\qmnotify.cpp
#define QM_NOTIFICATION_INPUT_MARSHALLING_FORMAT \
		L"<Notification>" \
			L"<Event>%d</Event>" \
			L"<ObjectGuid>%40[^<]</ObjectGuid>" \
			L"<DomainController>%260[^<]</DomainController>" \
		L"</Notification>"

// inetsrv\msmq\src\rtdep\acrt.h
#define IF_USING_RPC  \
   if ((g_fDependentClient) || (g_dwPlatformId == VER_PLATFORM_WIN32_WINDOWS))

// inetsrv\query\filters\html\source\cidebnot.h
#  define DECLARE_INFOLEVEL(comp, pszName)            \
     extern CTracerTag * comp##TracerTag = 0;         \
     void InitTracerTags()                            \
     {                                                \
        comp##TracerTag = new CTracerTag( pszName );  \
     }                                                \
     void DeleteTracerTags()                          \
     {                                                \
         delete comp##TracerTag;                      \
         comp##TracerTag = 0;                         \
     }                                                \

// multimedia\directx\dplay\misc\dxvalid.h
#define VALID_HWND_PTR( ptr ) \
	(!IsBadWritePtr( (LPVOID) ptr, sizeof( HWND )) )

// multimedia\directx\dxg\d3d8\fw\ddrawpr.h
#define VALID_HWND_PTR( ptr ) \
        (!IsBadWritePtr( (LPVOID) ptr, sizeof( HWND )) )

// multimedia\directx\dxg\dd\ddraw\main\ddrawpr.h
#define VALID_HWND_PTR( ptr ) \
        (!IsBadWritePtr( (LPVOID) ptr, sizeof( HWND )) )

// multimedia\directx\dxg\misc\dxvalid.h
#define VALID_HWND_PTR( ptr ) \
	(!IsBadWritePtr( (LPVOID) ptr, sizeof( HWND )) )

// multimedia\directx\gamectrl\gcdef\joymisc.cpp
#define FILLBAR( a, id ) \
    /* \
     * make sure we aren't out of alleged range \
     */ \
    if( pji->dw##a##pos > pgv->joyRange.jpMax.dw##a ) { \
    pji->dw##a##pos = pgv->joyRange.jpMax.dw##a; \
    } else if( pji->dw##a##pos < pgv->joyRange.jpMin.dw##a ) { \
    pji->dw##a##pos = pgv->joyRange.jpMin.dw##a; \
    } \
 \
    /* \
     * fill the bar if we haven't moved since last time \
     */ \
    if( pji->dw##a##pos != poji->dw##a##pos ) { \
    fillBar( pgv, hwnd, pji->dw##a##pos, id ); \
    poji->dw##a##pos = pji->dw##a##pos; \
    }

// multimedia\dshow\filters.ks\tests\tstshell\support.h
    #define GET_WM_COMMAND_HWND(wp, lp)                 (HWND)LOWORD(lp)
    #define GET_WM_VSCROLL_HWND(wp, lp)     (HWND)(lp)

// multimedia\dshow\filters.ks\tests\tstshell\text.h
#define Text_Copy(hWnd)             SendMessage(hWnd,WM_COPY,0,0L)
#define Text_GetBufferLimit(hWnd)   SendMessage(hWnd,TM_GETSIZELIMIT,0,0L)
#define Text_SetBufferLimit(hWnd,cbSize,uFlags)  \
            SendMessage(hWnd,TM_SETSIZELIMIT,(WPARAM)(uFlags),(LPARAM)(cbSize))
#define Text_SearchString(hWnd,pszString,uFlags)  \
            (BOOL)(SendMessage(hWnd,TM_SEARCH,(WPARAM)(uFlags), \
            (LPARAM)(LPSTR)(pszString)))

// multimedia\dshow\filters.ks\tests\wavetest\exe\appport.h
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)    \
        ((DWORD)SendMessage((hwndCtl), EM_GETSEL, (WPARAM)pnS, (LPARAM)pnE))
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)                        \
    {                                                               \
        DWORD   dw;                                                 \
        dw = (DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L);       \
        *pnE = (int)HIWORD(dw);                                     \
        *pnS = (int)LOWORD(dw);                                     \
    }
    #define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)LOWORD(lp)
    #define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)      (WPARAM)(s), MAKELONG(hwnd, fmin)
    #define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd)    (WPARAM)(ch), MAKELONG(hwnd, pos)
    #define GET_WM_COMMAND_HWND(wp, lp)             (HWND)LOWORD(lp)
    #define GET_WM_COMMAND_MPS(id, hwnd, cmd)       (WPARAM)(id), MAKELONG(hwnd, cmd)
    #define GET_WM_CTLCOLOR_HWND(wp, lp, msg)       (HWND)LOWORD(lp)
    #define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type)    (WPARAM)(hdc), MAKELONG(hwnd, type)
    #define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
    #define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
    #define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
    #define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA) (WPARAM)(hwndA), 0
    #define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd)  (WPARAM)(msg), MAKELONG(hwnd, id)
    #define GET_WM_VKEYTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) (WPARAM)(code), MAKELONG(hwnd, item)
    #define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_HSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_HSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)
    #define GET_WM_VSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_VSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)

// multimedia\dshow\filters\image2\rndless\app.h
#define HANDLE_WM_USER(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd, wParam, lParam), 0L)
#define HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn) \
    (fn)((hwnd), (int)(wParam), (NMHDR FAR*)(lParam))

// multimedia\dshow\filters\image2\rndlessplayer\app.h
#define HANDLE_WM_USER(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd, wParam, lParam), 0L)
#define HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn) \
    (fn)((hwnd), (int)(wParam), (NMHDR FAR*)(lParam))

// multimedia\dshow\filters\image2\vmrplyer\app.h
#define HANDLE_WM_USER(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd, wParam, lParam), 0L)
#define HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn) \
    (fn)((hwnd), (int)(wParam), (NMHDR FAR*)(lParam))

// multimedia\dshow\filters\tve\mstve\tvefiltprops.cpp
#define _SETBUT(buttonIDC, grfFlag)	SetDlgItemTextW(m_hwnd, (buttonIDC), (lGrfHaltFlags & (grfFlag)) ? L"Stopped" : L"Running");

// multimedia\dshow\tools\graphedt\proppage\msdvbnp\stdafx.h
#define MESSAGEBOX(wnd, ID) \
        {\
            TCHAR szPath[MAX_PATH];\
            if (0 != LoadString (_Module.GetModuleInstance (), ID, szPath, MAX_PATH))\
            {\
                TCHAR szCaption[MAX_PATH];\
                if (NULL != LoadString (_Module.GetModuleInstance (), IDS_ERROR_CAPTION, szCaption, MAX_PATH))\
                {\
                    ::MessageBox (wnd->m_hWnd, szPath, szCaption, MB_OK);\
                }\
            }\
        }
#define MESSAGEBOX_ERROR(wnd, ID) \
        {\
            TCHAR szPath[MAX_PATH];\
            if (0 != LoadString (_Module.GetModuleInstance (), ID, szPath, MAX_PATH))\
            {\
                TCHAR szCaption[MAX_PATH];\
                if (NULL != LoadString (_Module.GetModuleInstance (), IDS_ERROR_CAPTION, szCaption, MAX_PATH))\
                {\
                    ::MessageBox (wnd->m_hWnd, szPath, szCaption, MB_OK|MB_ICONSTOP);\
                }\
            }\
        }

// multimedia\dshow\tools\vcdplyer\app.h
#define HANDLE_WM_USER(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd, wParam, lParam), 0L)
#define HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn) \
    (fn)((hwnd), (int)(wParam), (NMHDR FAR*)(lParam))

// multimedia\media\avi\avicap.16\avicap.h
#define capSetCallbackOnError(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_ERROR, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnYield(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_YIELD, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnFrame(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_FRAME, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnVideoStream(hwnd, fpProc)  ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_VIDEOSTREAM, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnWaveStream(hwnd, fpProc)   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_WAVESTREAM, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnCapControl(hwnd, fpProc)   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_CAPCONTROL, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetUserData(hwnd, lUser)                ((BOOL)AVICapSM(hwnd, WM_CAP_SET_USER_DATA, 0, (LPARAM)lUser))
#define capGetUserData(hwnd)                       (AVICapSM(hwnd, WM_CAP_GET_USER_DATA, 0, 0))
#define capDriverConnect(hwnd, i)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_CONNECT, (WPARAM)(i), 0L))
#define capDriverDisconnect(hwnd)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_DISCONNECT, (WPARAM)0, 0L))
#define capDriverGetName(hwnd, szName, wSize)      ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_NAME, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capDriverGetVersion(hwnd, szVer, wSize)    ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_VERSION, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPSTR)(szVer)))
#define capDriverGetCaps(hwnd, s, wSize)           ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_CAPS, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPDRIVERCAPS)(s)))
#define capFileSetCaptureFile(hwnd, szName)        ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SET_CAPTURE_FILE, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capFileGetCaptureFile(hwnd, szName, wSize) ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_GET_CAPTURE_FILE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capFileAlloc(hwnd, dwSize)                 ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_ALLOCATE, 0, (LPARAM)(DWORD)(dwSize)))
#define capFileSaveAs(hwnd, szName)                ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEAS, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capFileSetInfoChunk(hwnd, lpInfoChunk)     ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SET_INFOCHUNK, (WPARAM)0, (LPARAM)(LPCAPINFOCHUNK)(lpInfoChunk)))
#define capFileSaveDIB(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEDIB, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capEditCopy(hwnd)                          ((BOOL)AVICapSM(hwnd, WM_CAP_EDIT_COPY, 0, 0L))
#define capSetAudioFormat(hwnd, s, wSize)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_AUDIOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPWAVEFORMATEX)(s)))
#define capGetAudioFormat(hwnd, s, wSize)          ((DWORD)AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPWAVEFORMATEX)(s)))
#define capGetAudioFormatSize(hwnd)                ((DWORD)AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, (WPARAM)0, (LPARAM) NULL))
#define capDlgVideoFormat(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOFORMAT, 0, 0L))
#define capDlgVideoSource(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOSOURCE, 0, 0L))
#define capDlgVideoDisplay(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEODISPLAY, 0, 0L))
#define capDlgVideoCompression(hwnd)               ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOCOMPRESSION, 0, 0L))
#define capGetVideoFormat(hwnd, s, wSize)          ((DWORD)AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(s)))
#define capGetVideoFormatSize(hwnd)                ((DWORD)AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, 0, NULL))
#define capSetVideoFormat(hwnd, s, wSize)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_VIDEOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(s)))
#define capPreview(hwnd, f)                        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_PREVIEW, (WPARAM)(BOOL)(f), 0L))
#define capPreviewRate(hwnd, wMS)                  ((BOOL)AVICapSM(hwnd, WM_CAP_SET_PREVIEWRATE, (WPARAM)(wMS), 0))
#define capOverlay(hwnd, f)                        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_OVERLAY, (WPARAM)(BOOL)(f), 0L))
#define capPreviewScale(hwnd, f)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SCALE, (WPARAM)(BOOL)f, 0L))
#define capSetScrollPos(hwnd, lpP)                 ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SCROLL, (WPARAM)0, (LPARAM)(LPPOINT)(lpP)))
#define capGrabFrame(hwnd)                         ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME, (WPARAM)0, (LPARAM)0L))
#define capGrabFrameNoStop(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME_NOSTOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequence(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequenceNoFile(hwnd)             ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE_NOFILE, (WPARAM)0, (LPARAM)0L))
#define capCaptureStop(hwnd)                       ((BOOL)AVICapSM(hwnd, WM_CAP_STOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureAbort(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_ABORT, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrameOpen(hwnd)            ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME_OPEN, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrame(hwnd)                ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME, (WPARAM)0, (LPARAM)0L))
#define capCaptureGetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_GET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))
#define capCaptureSetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))
#define capSetMCIDeviceName(hwnd, szName)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_MCI_DEVICE, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capGetMCIDeviceName(hwnd, szName, wSize)   ((BOOL)AVICapSM(hwnd, WM_CAP_GET_MCI_DEVICE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capPaletteOpen(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_OPEN, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capPaletteSave(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_SAVE, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capPalettePaste(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_PASTE, (WPARAM) 0, (LPARAM)0L))
#define capPaletteAuto(hwnd, iFrames, iColors)     ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_AUTOCREATE, (WPARAM)(iFrames), (LPARAM)(DWORD)(iColors)))
#define capPaletteManual(hwnd, fGrab, iColors)     ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_MANUALCREATE, (WPARAM)(fGrab), (LPARAM)(DWORD)(iColors)))

// multimedia\media\avi\avicap.io\avicap.h
#define AVICapSM(hwnd,m,w,l) ( (IsWindow(hwnd)) ? ::SendMessage(hwnd,m,w,l) : 0)
#define AVICapSM(hwnd,m,w,l) ( (IsWindow(hwnd)) ?   SendMessage(hwnd,m,w,l) : 0)
#define capSetCallbackOnError(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_ERROR, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnYield(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_YIELD, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnFrame(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_FRAME, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnVideoStream(hwnd, fpProc)  ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_VIDEOSTREAM, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnWaveStream(hwnd, fpProc)   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_WAVESTREAM, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnCapControl(hwnd, fpProc)   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_CAPCONTROL, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetUserData(hwnd, lUser)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_USER_DATA, 0, (LPARAM)lUser))
#define capGetUserData(hwnd)               (AVICapSM(hwnd, WM_CAP_GET_USER_DATA, 0, 0))
#define capDriverConnect(hwnd, i)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_CONNECT, (WPARAM)(i), 0L))
#define capDriverDisconnect(hwnd)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_DISCONNECT, (WPARAM)0, 0L))
#define capDriverGetName(hwnd, szName, wSize)      ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_NAME, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capDriverGetVersion(hwnd, szVer, wSize)    ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_VERSION, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szVer)))
#define capDriverGetCaps(hwnd, s, wSize)           ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_CAPS, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPDRIVERCAPS)(s)))
#define capFileSetCaptureFile(hwnd, szName)        ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SET_CAPTURE_FILE, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capFileGetCaptureFile(hwnd, szName, wSize) ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_GET_CAPTURE_FILE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capFileAlloc(hwnd, dwSize)                 ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_ALLOCATE, 0, (LPARAM)(DWORD)(dwSize)))
#define capFileSaveAs(hwnd, szName)                ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEAS, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capFileSetInfoChunk(hwnd, lpInfoChunk)     ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SET_INFOCHUNK, (WPARAM)0, (LPARAM)(LPCAPINFOCHUNK)(lpInfoChunk)))
#define capFileSaveDIB(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEDIB, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capEditCopy(hwnd)                          ((BOOL)AVICapSM(hwnd, WM_CAP_EDIT_COPY, 0, 0L))
#define capSetAudioFormat(hwnd, s, wSize)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_AUDIOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPWAVEFORMATEX)(s)))
#define capGetAudioFormat(hwnd, s, wSize)          ((DWORD)AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPWAVEFORMATEX)(s)))
#define capGetAudioFormatSize(hwnd)                ((DWORD)AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, (WPARAM)0, (LPARAM)0L))
#define capDlgVideoFormat(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOFORMAT, 0, 0L))
#define capDlgVideoSource(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOSOURCE, 0, 0L))
#define capDlgVideoDisplay(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEODISPLAY, 0, 0L))
#define capDlgVideoCompression(hwnd)               ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOCOMPRESSION, 0, 0L))
#define capGetVideoFormat(hwnd, s, wSize)          ((DWORD)AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(s)))
#define capGetVideoFormatSize(hwnd)            ((DWORD)AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, 0, 0L))
#define capSetVideoFormat(hwnd, s, wSize)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_VIDEOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(s)))
#define capPreview(hwnd, f)                        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_PREVIEW, (WPARAM)(BOOL)(f), 0L))
#define capPreviewRate(hwnd, wMS)                  ((BOOL)AVICapSM(hwnd, WM_CAP_SET_PREVIEWRATE, (WPARAM)(wMS), 0))
#define capOverlay(hwnd, f)                        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_OVERLAY, (WPARAM)(BOOL)(f), 0L))
#define capPreviewScale(hwnd, f)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SCALE, (WPARAM)(BOOL)f, 0L))
#define capSetScrollPos(hwnd, lpP)                 ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SCROLL, (WPARAM)0, (LPARAM)(LPPOINT)(lpP)))
#define capGrabFrame(hwnd)                         ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME, (WPARAM)0, (LPARAM)0L))
#define capGrabFrameNoStop(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME_NOSTOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequence(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequenceNoFile(hwnd)             ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE_NOFILE, (WPARAM)0, (LPARAM)0L))
#define capCaptureStop(hwnd)                       ((BOOL)AVICapSM(hwnd, WM_CAP_STOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureAbort(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_ABORT, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrameOpen(hwnd)            ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME_OPEN, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrame(hwnd)                ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME, (WPARAM)0, (LPARAM)0L))
#define capCaptureGetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_GET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))
#define capCaptureSetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))
#define capSetMCIDeviceName(hwnd, szName)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_MCI_DEVICE, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capGetMCIDeviceName(hwnd, szName, wSize)   ((BOOL)AVICapSM(hwnd, WM_CAP_GET_MCI_DEVICE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPaletteOpen(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_OPEN, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPaletteSave(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_SAVE, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPalettePaste(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_PASTE, (WPARAM) 0, (LPARAM)0L))
#define capPaletteAuto(hwnd, iFrames, iColors)     ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_AUTOCREATE, (WPARAM)(iFrames), (LPARAM)(DWORD)(iColors)))
#define capPaletteManual(hwnd, fGrab, iColors)     ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_MANUALCREATE, (WPARAM)(fGrab), (LPARAM)(DWORD)(iColors)))

// multimedia\media\avi\avicap\avicap.h
#define AVICapSM(hwnd,m,w,l) ( (IsWindow(hwnd)) ? ::SendMessage(hwnd,m,w,l) : 0)
#define AVICapSM(hwnd,m,w,l) ( (IsWindow(hwnd)) ?   SendMessage(hwnd,m,w,l) : 0)
#define capSetCallbackOnError(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_ERROR, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnYield(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_YIELD, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnFrame(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_FRAME, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnVideoStream(hwnd, fpProc)  ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_VIDEOSTREAM, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnWaveStream(hwnd, fpProc)   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_WAVESTREAM, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnCapControl(hwnd, fpProc)   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_CAPCONTROL, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetUserData(hwnd, lUser)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_USER_DATA, 0, (LPARAM)lUser))
#define capGetUserData(hwnd)               (AVICapSM(hwnd, WM_CAP_GET_USER_DATA, 0, 0))
#define capDriverConnect(hwnd, i)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_CONNECT, (WPARAM)(i), 0L))
#define capDriverDisconnect(hwnd)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_DISCONNECT, (WPARAM)0, 0L))
#define capDriverGetName(hwnd, szName, wSize)      ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_NAME, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capDriverGetVersion(hwnd, szVer, wSize)    ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_VERSION, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szVer)))
#define capDriverGetCaps(hwnd, s, wSize)           ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_CAPS, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPDRIVERCAPS)(s)))
#define capFileSetCaptureFile(hwnd, szName)        ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SET_CAPTURE_FILE, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capFileGetCaptureFile(hwnd, szName, wSize) ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_GET_CAPTURE_FILE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capFileAlloc(hwnd, dwSize)                 ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_ALLOCATE, 0, (LPARAM)(DWORD)(dwSize)))
#define capFileSaveAs(hwnd, szName)                ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEAS, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capFileSetInfoChunk(hwnd, lpInfoChunk)     ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SET_INFOCHUNK, (WPARAM)0, (LPARAM)(LPCAPINFOCHUNK)(lpInfoChunk)))
#define capFileSaveDIB(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEDIB, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capEditCopy(hwnd)                          ((BOOL)AVICapSM(hwnd, WM_CAP_EDIT_COPY, 0, 0L))
#define capSetAudioFormat(hwnd, s, wSize)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_AUDIOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPWAVEFORMATEX)(s)))
#define capGetAudioFormat(hwnd, s, wSize)          ((DWORD)AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPWAVEFORMATEX)(s)))
#define capGetAudioFormatSize(hwnd)                ((DWORD)AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, (WPARAM)0, (LPARAM)0L))
#define capDlgVideoFormat(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOFORMAT, 0, 0L))
#define capDlgVideoSource(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOSOURCE, 0, 0L))
#define capDlgVideoDisplay(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEODISPLAY, 0, 0L))
#define capDlgVideoCompression(hwnd)               ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOCOMPRESSION, 0, 0L))
#define capGetVideoFormat(hwnd, s, wSize)          ((DWORD)AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(s)))
#define capGetVideoFormatSize(hwnd)            ((DWORD)AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, 0, 0L))
#define capSetVideoFormat(hwnd, s, wSize)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_VIDEOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(s)))
#define capPreview(hwnd, f)                        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_PREVIEW, (WPARAM)(BOOL)(f), 0L))
#define capPreviewRate(hwnd, wMS)                  ((BOOL)AVICapSM(hwnd, WM_CAP_SET_PREVIEWRATE, (WPARAM)(wMS), 0))
#define capOverlay(hwnd, f)                        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_OVERLAY, (WPARAM)(BOOL)(f), 0L))
#define capPreviewScale(hwnd, f)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SCALE, (WPARAM)(BOOL)f, 0L))
#define capSetScrollPos(hwnd, lpP)                 ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SCROLL, (WPARAM)0, (LPARAM)(LPPOINT)(lpP)))
#define capGrabFrame(hwnd)                         ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME, (WPARAM)0, (LPARAM)0L))
#define capGrabFrameNoStop(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME_NOSTOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequence(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequenceNoFile(hwnd)             ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE_NOFILE, (WPARAM)0, (LPARAM)0L))
#define capCaptureStop(hwnd)                       ((BOOL)AVICapSM(hwnd, WM_CAP_STOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureAbort(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_ABORT, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrameOpen(hwnd)            ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME_OPEN, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrame(hwnd)                ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME, (WPARAM)0, (LPARAM)0L))
#define capCaptureGetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_GET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))
#define capCaptureSetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))
#define capSetMCIDeviceName(hwnd, szName)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_MCI_DEVICE, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capGetMCIDeviceName(hwnd, szName, wSize)   ((BOOL)AVICapSM(hwnd, WM_CAP_GET_MCI_DEVICE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPaletteOpen(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_OPEN, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPaletteSave(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_SAVE, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPalettePaste(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_PASTE, (WPARAM) 0, (LPARAM)0L))
#define capPaletteAuto(hwnd, iFrames, iColors)     ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_AUTOCREATE, (WPARAM)(iFrames), (LPARAM)(DWORD)(iColors)))
#define capPaletteManual(hwnd, fGrab, iColors)     ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_MANUALCREATE, (WPARAM)(fGrab), (LPARAM)(DWORD)(iColors)))

// multimedia\media\avi\avifile.16\riffdisp.c
#define GetHInstance()  (HINSTANCE)(SELECTOROF((LPVOID)&hwndPreview))

// multimedia\media\avi\avifile\riffdisp.c
#define GetHInstance()  (HINSTANCE)(SELECTOROF((LPVOID)&hwndPreview))

// multimedia\media\avi\compman.16\compman.h
#define ICQueryAbout(hic) \
    (ICSendMessage(hic, ICM_ABOUT, (DWORD) -1, ICMF_ABOUT_QUERY) == ICERR_OK)
#define ICAbout(hic, hwnd) \
    ICSendMessage(hic, ICM_ABOUT, (DWORD)(UINT)(hwnd), 0)
#define ICQueryConfigure(hic) \
    (ICSendMessage(hic, ICM_CONFIGURE, (DWORD) -1, ICMF_CONFIGURE_QUERY) == ICERR_OK)
#define ICConfigure(hic, hwnd) \
    ICSendMessage(hic, ICM_CONFIGURE, (DWORD)(UINT)(hwnd), 0)
#define ICGetState(hic, pv, cb) \
    ICSendMessage(hic, ICM_GETSTATE, (DWORD)(LPVOID)(pv), (DWORD)(cb))
#define ICSetState(hic, pv, cb) \
    ICSendMessage(hic, ICM_SETSTATE, (DWORD)(LPVOID)(pv), (DWORD)(cb))
#define ICGetDefaultQuality(hic) \
    (ICSendMessage(hic, ICM_GETDEFAULTQUALITY, (DWORD)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)
#define ICGetDefaultKeyFrameRate(hic) \
    (ICSendMessage(hic, ICM_GETDEFAULTKEYFRAMERATE, (DWORD)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)
#define ICDrawWindow(hic, prc) \
    ICSendMessage(hic, ICM_DRAW_WINDOW, (DWORD)(LPVOID)(prc), sizeof(RECT))
#define ICCompressBegin(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_COMPRESS_BEGIN, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICCompressQuery(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_COMPRESS_QUERY, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICCompressGetFormat(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_COMPRESS_GET_FORMAT, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICCompressGetSize(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_COMPRESS_GET_SIZE, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICCompressEnd(hic) \
    ICSendMessage(hic, ICM_COMPRESS_END, 0, 0)
#define ICDecompressBegin(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_DECOMPRESS_BEGIN, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICDecompressQuery(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_DECOMPRESS_QUERY, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICDecompressGetFormat(hic, lpbiInput, lpbiOutput) \
    ((LONG) ICSendMessage(hic, ICM_DECOMPRESS_GET_FORMAT, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput)))
#define ICDecompressGetPalette(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_DECOMPRESS_GET_PALETTE, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICDecompressSetPalette(hic, lpbiPalette) \
    ICSendMessage(hic, ICM_DECOMPRESS_SET_PALETTE, (DWORD)(LPVOID)(lpbiPalette), 0)
#define ICDecompressEnd(hic) \
    ICSendMessage(hic, ICM_DECOMPRESS_END, 0, 0)
#define ICDecompressExEnd(hic) \
    ICSendMessage(hic, ICM_DECOMPRESSEX_END, 0, 0)
#define ICDrawQuery(hic, lpbiInput) \
    ICSendMessage(hic, ICM_DRAW_QUERY, (DWORD)(LPVOID)(lpbiInput), 0L)
#define ICDrawChangePalette(hic, lpbiInput) \
    ICSendMessage(hic, ICM_DRAW_CHANGEPALETTE, (DWORD)(LPVOID)(lpbiInput), 0L)
#define ICGetBuffersWanted(hic, lpdwBuffers) \
    ICSendMessage(hic, ICM_GETBUFFERSWANTED, (DWORD)(LPVOID)(lpdwBuffers), 0)
#define ICDrawEnd(hic) \
    ICSendMessage(hic, ICM_DRAW_END, 0, 0)
#define ICDrawStart(hic) \
    ICSendMessage(hic, ICM_DRAW_START, 0, 0)
#define ICDrawStartPlay(hic, lFrom, lTo) \
    ICSendMessage(hic, ICM_DRAW_START_PLAY, (DWORD)(lFrom), (DWORD)(lTo))
#define ICDrawStop(hic) \
    ICSendMessage(hic, ICM_DRAW_STOP, 0, 0)
#define ICDrawStopPlay(hic) \
    ICSendMessage(hic, ICM_DRAW_STOP_PLAY, 0, 0)
#define ICDrawGetTime(hic, lplTime) \
    ICSendMessage(hic, ICM_DRAW_GETTIME, (DWORD)(LPVOID)(lplTime), 0)
#define ICDrawSetTime(hic, lTime) \
    ICSendMessage(hic, ICM_DRAW_SETTIME, (DWORD)lTime, 0)
#define ICDrawRealize(hic, hdc, fBackground) \
    ICSendMessage(hic, ICM_DRAW_REALIZE, (DWORD)(UINT)(HDC)(hdc), (DWORD)(BOOL)(fBackground))
#define ICDrawFlush(hic) \
    ICSendMessage(hic, ICM_DRAW_FLUSH, 0, 0)
#define ICDrawRenderBuffer(hic) \
    ICSendMessage(hic, ICM_DRAW_RENDERBUFFER, 0, 0)

// multimedia\media\avi\compman\compman.h
#define ICQueryAbout(hic) \
    (ICSendMessage(hic, ICM_ABOUT, (DWORD_PTR) -1, ICMF_ABOUT_QUERY) == ICERR_OK)
#define ICAbout(hic, hwnd) \
    ICSendMessage(hic, ICM_ABOUT, (DWORD_PTR)(UINT_PTR)(hwnd), 0)
#define ICQueryConfigure(hic) \
    (ICSendMessage(hic, ICM_CONFIGURE, (DWORD_PTR) -1, ICMF_CONFIGURE_QUERY) == ICERR_OK)
#define ICConfigure(hic, hwnd) \
    ICSendMessage(hic, ICM_CONFIGURE, (DWORD_PTR)(UINT_PTR)(hwnd), 0)
#define ICGetState(hic, pv, cb) \
    ICSendMessage(hic, ICM_GETSTATE, (DWORD_PTR)(LPVOID)(pv), (DWORD_PTR)(cb))
#define ICSetState(hic, pv, cb) \
    ICSendMessage(hic, ICM_SETSTATE, (DWORD_PTR)(LPVOID)(pv), (DWORD_PTR)(cb))
#define ICGetDefaultQuality(hic) \
    (ICSendMessage(hic, ICM_GETDEFAULTQUALITY, (DWORD_PTR)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)
#define ICGetDefaultKeyFrameRate(hic) \
    (ICSendMessage(hic, ICM_GETDEFAULTKEYFRAMERATE, (DWORD_PTR)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)
#define ICDrawWindow(hic, prc) \
    ICSendMessage(hic, ICM_DRAW_WINDOW, (DWORD_PTR)(LPVOID)(prc), sizeof(RECT))
#define ICCompressBegin(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_COMPRESS_BEGIN, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))
#define ICCompressQuery(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_COMPRESS_QUERY, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))
#define ICCompressGetFormat(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_COMPRESS_GET_FORMAT, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))
#define ICCompressGetSize(hic, lpbiInput, lpbiOutput) \
    (DWORD) ICSendMessage(hic, ICM_COMPRESS_GET_SIZE, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))
#define ICCompressEnd(hic) \
    ICSendMessage(hic, ICM_COMPRESS_END, 0, 0)
#define ICDecompressBegin(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_DECOMPRESS_BEGIN, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))
#define ICDecompressQuery(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_DECOMPRESS_QUERY, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))
#define ICDecompressGetFormat(hic, lpbiInput, lpbiOutput) \
    ((LONG) ICSendMessage(hic, ICM_DECOMPRESS_GET_FORMAT, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput)))
#define ICDecompressGetPalette(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_DECOMPRESS_GET_PALETTE, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))
#define ICDecompressSetPalette(hic, lpbiPalette) \
    ICSendMessage(hic, ICM_DECOMPRESS_SET_PALETTE, (DWORD_PTR)(LPVOID)(lpbiPalette), 0)
#define ICDecompressEnd(hic) \
    ICSendMessage(hic, ICM_DECOMPRESS_END, 0, 0)
#define ICDecompressExEnd(hic) \
    ICSendMessage(hic, ICM_DECOMPRESSEX_END, 0, 0)
#define ICDrawQuery(hic, lpbiInput) \
    ICSendMessage(hic, ICM_DRAW_QUERY, (DWORD_PTR)(LPVOID)(lpbiInput), 0L)
#define ICDrawChangePalette(hic, lpbiInput) \
    ICSendMessage(hic, ICM_DRAW_CHANGEPALETTE, (DWORD_PTR)(LPVOID)(lpbiInput), 0L)
#define ICGetBuffersWanted(hic, lpdwBuffers) \
    ICSendMessage(hic, ICM_GETBUFFERSWANTED, (DWORD_PTR)(LPVOID)(lpdwBuffers), 0)
#define ICDrawEnd(hic) \
    ICSendMessage(hic, ICM_DRAW_END, 0, 0)
#define ICDrawStart(hic) \
    ICSendMessage(hic, ICM_DRAW_START, 0, 0)
#define ICDrawStartPlay(hic, lFrom, lTo) \
    ICSendMessage(hic, ICM_DRAW_START_PLAY, (DWORD_PTR)(lFrom), (DWORD_PTR)(lTo))
#define ICDrawStop(hic) \
    ICSendMessage(hic, ICM_DRAW_STOP, 0, 0)
#define ICDrawStopPlay(hic) \
    ICSendMessage(hic, ICM_DRAW_STOP_PLAY, 0, 0)
#define ICDrawGetTime(hic, lplTime) \
    ICSendMessage(hic, ICM_DRAW_GETTIME, (DWORD_PTR)(LPVOID)(lplTime), 0)
#define ICDrawSetTime(hic, lTime) \
    ICSendMessage(hic, ICM_DRAW_SETTIME, (DWORD_PTR)lTime, 0)
#define ICDrawRealize(hic, hdc, fBackground) \
    ICSendMessage(hic, ICM_DRAW_REALIZE, (DWORD_PTR)(UINT_PTR)(HDC)(hdc), (DWORD_PTR)(BOOL)(fBackground))
#define ICDrawFlush(hic) \
    ICSendMessage(hic, ICM_DRAW_FLUSH, 0, 0)
#define ICDrawRenderBuffer(hic) \
    ICSendMessage(hic, ICM_DRAW_RENDERBUFFER, 0, 0)

// multimedia\media\avi\compman\icm.c
#define GetHIC(hwnd,index) ((HIC)LOWORD(ComboBox_GetItemData((hwnd),(index))))

// multimedia\media\avi\drawdib.16\dcilib\dvaclip.c
#define TestWF(hwnd, f) (GetWindowLong(hwnd, GWL_STYLE) & (f))
#define TestWX(hwnd, f) (GetWindowLong(hwnd, GWL_EX_STYLE) & (f))

// multimedia\media\avi\drawdib.16\dva\dvaclip.c
#define TestWF(hwnf, f) (GetWindowLong(hwnd, GWL_STYLE) & (f))

// multimedia\media\avi\drawdib\dva\dvaclip.c
#define TestWF(hwnf, f) (GetWindowLong(hwnd, GWL_STYLE) & (f))

// multimedia\media\avi\inc.16\avicap.h
#define capSetCallbackOnError(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_ERROR, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnYield(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_YIELD, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnFrame(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_FRAME, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnVideoStream(hwnd, fpProc)  ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_VIDEOSTREAM, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnWaveStream(hwnd, fpProc)   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_WAVESTREAM, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnCapControl(hwnd, fpProc)   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_CAPCONTROL, 0, (LPARAM)(LPVOID)(fpProc)))
#define capSetUserData(hwnd, lUser)                ((BOOL)AVICapSM(hwnd, WM_CAP_SET_USER_DATA, 0, (LPARAM)lUser))
#define capGetUserData(hwnd)                       (AVICapSM(hwnd, WM_CAP_GET_USER_DATA, 0, 0))
#define capDriverConnect(hwnd, i)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_CONNECT, (WPARAM)(i), 0L))
#define capDriverDisconnect(hwnd)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_DISCONNECT, (WPARAM)0, 0L))
#define capDriverGetName(hwnd, szName, wSize)      ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_NAME, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capDriverGetVersion(hwnd, szVer, wSize)    ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_VERSION, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPSTR)(szVer)))
#define capDriverGetCaps(hwnd, s, wSize)           ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_CAPS, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPDRIVERCAPS)(s)))
#define capFileSetCaptureFile(hwnd, szName)        ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SET_CAPTURE_FILE, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capFileGetCaptureFile(hwnd, szName, wSize) ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_GET_CAPTURE_FILE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capFileAlloc(hwnd, dwSize)                 ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_ALLOCATE, 0, (LPARAM)(DWORD)(dwSize)))
#define capFileSaveAs(hwnd, szName)                ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEAS, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capFileSetInfoChunk(hwnd, lpInfoChunk)     ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SET_INFOCHUNK, (WPARAM)0, (LPARAM)(LPCAPINFOCHUNK)(lpInfoChunk)))
#define capFileSaveDIB(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEDIB, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capEditCopy(hwnd)                          ((BOOL)AVICapSM(hwnd, WM_CAP_EDIT_COPY, 0, 0L))
#define capSetAudioFormat(hwnd, s, wSize)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_AUDIOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPWAVEFORMATEX)(s)))
#define capGetAudioFormat(hwnd, s, wSize)          ((DWORD)AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPWAVEFORMATEX)(s)))
#define capGetAudioFormatSize(hwnd)                ((DWORD)AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, (WPARAM)0, (LPARAM) NULL))
#define capDlgVideoFormat(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOFORMAT, 0, 0L))
#define capDlgVideoSource(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOSOURCE, 0, 0L))
#define capDlgVideoDisplay(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEODISPLAY, 0, 0L))
#define capDlgVideoCompression(hwnd)               ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOCOMPRESSION, 0, 0L))
#define capGetVideoFormat(hwnd, s, wSize)          ((DWORD)AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(s)))
#define capGetVideoFormatSize(hwnd)                ((DWORD)AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, 0, NULL))
#define capSetVideoFormat(hwnd, s, wSize)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_VIDEOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(s)))
#define capPreview(hwnd, f)                        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_PREVIEW, (WPARAM)(BOOL)(f), 0L))
#define capPreviewRate(hwnd, wMS)                  ((BOOL)AVICapSM(hwnd, WM_CAP_SET_PREVIEWRATE, (WPARAM)(wMS), 0))
#define capOverlay(hwnd, f)                        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_OVERLAY, (WPARAM)(BOOL)(f), 0L))
#define capPreviewScale(hwnd, f)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SCALE, (WPARAM)(BOOL)f, 0L))
#define capSetScrollPos(hwnd, lpP)                 ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SCROLL, (WPARAM)0, (LPARAM)(LPPOINT)(lpP)))
#define capGrabFrame(hwnd)                         ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME, (WPARAM)0, (LPARAM)0L))
#define capGrabFrameNoStop(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME_NOSTOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequence(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequenceNoFile(hwnd)             ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE_NOFILE, (WPARAM)0, (LPARAM)0L))
#define capCaptureStop(hwnd)                       ((BOOL)AVICapSM(hwnd, WM_CAP_STOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureAbort(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_ABORT, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrameOpen(hwnd)            ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME_OPEN, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrame(hwnd)                ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME, (WPARAM)0, (LPARAM)0L))
#define capCaptureGetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_GET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))
#define capCaptureSetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))
#define capSetMCIDeviceName(hwnd, szName)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_MCI_DEVICE, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capGetMCIDeviceName(hwnd, szName, wSize)   ((BOOL)AVICapSM(hwnd, WM_CAP_GET_MCI_DEVICE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capPaletteOpen(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_OPEN, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capPaletteSave(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_SAVE, 0, (LPARAM)(LPVOID)(LPSTR)(szName)))
#define capPalettePaste(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_PASTE, (WPARAM) 0, (LPARAM)0L))
#define capPaletteAuto(hwnd, iFrames, iColors)     ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_AUTOCREATE, (WPARAM)(iFrames), (LPARAM)(DWORD)(iColors)))
#define capPaletteManual(hwnd, fGrab, iColors)     ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_MANUALCREATE, (WPARAM)(fGrab), (LPARAM)(DWORD)(iColors)))

// multimedia\media\avi\inc.16\commctrl.h
#define HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn) \
    (fn)((hwnd), (int)(wParam), (NMHDR FAR*)(lParam))
#define FORWARD_WM_NOTIFY(hwnd, idFrom, pnmhdr, fn) \
    (void)(fn)((hwnd), WM_NOTIFY, (WPARAM)(int)(id), (LPARAM)(NMHDR FAR*)(pnmhdr))
#define Header_GetItemCount(hwndHD) \
    (int)SendMessage((hwndHD), HDM_GETITEMCOUNT, 0, 0L)
#define Header_InsertItem(hwndHD, i, phdi) \
    (int)SendMessage((hwndHD), HDM_INSERTITEM, (WPARAM)(int)(i), (LPARAM)(const HD_ITEM FAR*)(phdi))
#define Header_GetItem(hwndHD, i, phdi) \
    (BOOL)SendMessage((hwndHD), HDM_GETITEM, (WPARAM)(int)(i), (LPARAM)(HD_ITEM FAR*)(phdi))
#define Header_SetItem(hwndHD, i, phdi) \
    (BOOL)SendMessage((hwndHD), HDM_SETITEM, (WPARAM)(int)(i), (LPARAM)(const HD_ITEM FAR*)(phdi))
#define Header_Layout(hwndHD, playout) \
    (BOOL)SendMessage((hwndHD), HDM_LAYOUT, 0, (LPARAM)(HD_LAYOUT FAR*)(playout))
#define ListView_GetBkColor(hwnd)  \
    (COLORREF)SendMessage((hwnd), LVM_GETBKCOLOR, 0, 0L)
#define ListView_SetBkColor(hwnd, clrBk) \
    (BOOL)SendMessage((hwnd), LVM_SETBKCOLOR, 0, (LPARAM)(COLORREF)(clrBk))
#define ListView_GetImageList(hwnd, iImageList) \
    (HIMAGELIST)SendMessage((hwnd), LVM_GETIMAGELIST, (WPARAM)(INT)(iImageList), 0L)
#define ListView_SetImageList(hwnd, himl, iImageList) \
    (HIMAGELIST)(UINT)SendMessage((hwnd), LVM_SETIMAGELIST, (WPARAM)(iImageList), (LPARAM)(UINT)(HIMAGELIST)(himl))
#define ListView_GetItemCount(hwnd) \
    (int)SendMessage((hwnd), LVM_GETITEMCOUNT, 0, 0L)
#define ListView_GetItem(hwnd, pitem) \
    (BOOL)SendMessage((hwnd), LVM_GETITEM, 0, (LPARAM)(LV_ITEM FAR*)(pitem))
#define ListView_SetItem(hwnd, pitem) \
    (BOOL)SendMessage((hwnd), LVM_SETITEM, 0, (LPARAM)(const LV_ITEM FAR*)(pitem))
#define ListView_InsertItem(hwnd, pitem)   \
    (int)SendMessage((hwnd), LVM_INSERTITEM, 0, (LPARAM)(const LV_ITEM FAR*)(pitem))
#define ListView_GetCallbackMask(hwnd) \
    (BOOL)SendMessage((hwnd), LVM_GETCALLBACKMASK, 0, 0)
#define ListView_SetCallbackMask(hwnd, mask) \
    (BOOL)SendMessage((hwnd), LVM_SETCALLBACKMASK, (WPARAM)(UINT)(mask), 0)
#define ListView_GetNextItem(hwnd, i, flags) \
    (int)SendMessage((hwnd), LVM_GETNEXTITEM, (WPARAM)(int)(i), MAKELPARAM((flags), 0))
#define ListView_FindItem(hwnd, iStart, plvfi) \
    (int)SendMessage((hwnd), LVM_FINDITEM, (WPARAM)(int)(iStart), (LPARAM)(const LV_FINDINFO FAR*)(plvfi))
#define ListView_GetItemRect(hwnd, i, prc, code) \
    ((prc)->left = (code), (BOOL)SendMessage((hwnd), LVM_GETITEMRECT, (WPARAM)(int)(i), (LPARAM)(RECT FAR*)(prc)))
#define ListView_SetItemPosition(hwndLV, i, x, y) \
    (BOOL)SendMessage((hwndLV), LVM_SETITEMPOSITION, (WPARAM)(int)(i), MAKELPARAM((x), (y)))
#define ListView_GetItemPosition(hwndLV, i, ppt) \
    (BOOL)SendMessage((hwndLV), LVM_GETITEMPOSITION, (WPARAM)(int)(i), (LPARAM)(POINT FAR*)(ppt))
#define ListView_GetStringWidth(hwndLV, psz) \
    (int)SendMessage((hwndLV), LVM_GETSTRINGWIDTH, 0, (LPARAM)(LPCSTR)(psz))
#define ListView_HitTest(hwndLV, pinfo) \
    (int)SendMessage((hwndLV), LVM_HITTEST, 0, (LPARAM)(LV_HITTESTINFO FAR*)(pinfo))
#define ListView_EnsureVisible(hwndLV, i, fPartialOK) \
    (BOOL)SendMessage((hwndLV), LVM_ENSUREVISIBLE, (WPARAM)(int)(i), MAKELPARAM((fPartialOK), 0))
#define ListView_Scroll(hwndLV, dx, dy) \
    (BOOL)SendMessage((hwndLV), LVM_SCROLL, 0, MAKELPARAM((dx), (dy)))
#define ListView_RedrawItems(hwndLV, iFirst, iLast) \
    (BOOL)SendMessage((hwndLV), LVM_REDRAWITEMS, 0, MAKELPARAM((iFirst), (iLast)))
#define ListView_Arrange(hwndLV, code) \
    (BOOL)SendMessage((hwndLV), LVM_ARRANGE, (WPARAM)(UINT)(code), 0L)
#define ListView_EditLabel(hwndLV, i) \
    (HWND)SendMessage((hwndLV), LVM_EDITLABEL, (WPARAM)(int)(i), 0L)
#define ListView_GetEditControl(hwndLV) \
    (HWND)SendMessage((hwndLV), LVM_GETEDITCONTROL, 0, 0L)
#define ListView_GetColumn(hwnd, iCol, pcol) \
    (BOOL)SendMessage((hwnd), LVM_GETCOLUMN, (WPARAM)(int)(iCol), (LPARAM)(LV_COLUMN FAR*)(pcol))
#define ListView_SetColumn(hwnd, iCol, pcol) \
    (BOOL)SendMessage((hwnd), LVM_SETCOLUMN, (WPARAM)(int)(iCol), (LPARAM)(const LV_COLUMN FAR*)(pcol))
#define ListView_InsertColumn(hwnd, iCol, pcol) \
    (int)SendMessage((hwnd), LVM_INSERTCOLUMN, (WPARAM)(int)(iCol), (LPARAM)(const LV_COLUMN FAR*)(pcol))
#define ListView_GetColumnWidth(hwnd, iCol) \
    (int)SendMessage((hwnd), LVM_GETCOLUMNWIDTH, (WPARAM)(int)(iCol), 0)
#define ListView_SetColumnWidth(hwnd, iCol, cx) \
    (BOOL)SendMessage((hwnd), LVM_SETCOLUMNWIDTH, (WPARAM)(int)(iCol), MAKELPARAM((cx), 0))
#define ListView_CreateDragImage(hwnd, i, lpptUpLeft) \
    (HIMAGELIST)SendMessage((hwnd), LVM_CREATEDRAGIMAGE, (WPARAM)(int)(i), (LPARAM)(LPPOINT)(lpptUpLeft))
#define ListView_GetViewRect(hwnd, prc) \
    (BOOL)SendMessage((hwnd), LVM_GETVIEWRECT, 0, (LPARAM)(RECT FAR*)(prc))
#define ListView_GetTextColor(hwnd)  \
    (COLORREF)SendMessage((hwnd), LVM_GETTEXTCOLOR, 0, 0L)
#define ListView_SetTextColor(hwnd, clrText) \
    (BOOL)SendMessage((hwnd), LVM_SETTEXTCOLOR, 0, (LPARAM)(COLORREF)(clrText))
#define ListView_GetTextBkColor(hwnd)  \
    (COLORREF)SendMessage((hwnd), LVM_GETTEXTBKCOLOR, 0, 0L)
#define ListView_SetTextBkColor(hwnd, clrTextBk) \
    (BOOL)SendMessage((hwnd), LVM_SETTEXTBKCOLOR, 0, (LPARAM)(COLORREF)(clrTextBk))
#define ListView_GetTopIndex(hwndLV, ppt) \
    (int)SendMessage((hwndLV), LVM_GETTOPINDEX, 0, 0)
#define ListView_GetCountPerPage(hwndLV, ppt) \
    (int)SendMessage((hwndLV), LVM_GETCOUNTPERPAGE, 0, 0)
#define ListView_GetOrigin(hwndLV, ppt) \
    (BOOL)SendMessage((hwndLV), LVM_GETORIGIN, (WPARAM)0, (LPARAM)(POINT FAR*)(ppt))
#define ListView_Update(hwndLV, i) \
    (BOOL)SendMessage((hwndLV), LVM_UPDATE, (WPARAM)i, 0L)
#define ListView_SetItemState(hwndLV, i, data, mask) \
{ LV_ITEM lvi;\
  lvi.stateMask = mask;\
  lvi.state = data;\
  SendMessage((hwndLV), LVM_SETITEMSTATE, (WPARAM)i, (LPARAM)(LV_ITEM FAR *)&lvi);\
}
#define ListView_GetItemState(hwndLV, i, mask) \
   (UINT)SendMessage((hwndLV), LVM_GETITEMSTATE, (WPARAM)i, (LPARAM)mask)
#define ListView_GetItemText(hwndLV, i, iSubItem_, pszText_, cchTextMax_) \
{ LV_ITEM lvi;\
  lvi.iSubItem = iSubItem_;\
  lvi.cchTextMax = cchTextMax_;\
  lvi.pszText = pszText_;\
  SendMessage((hwndLV), LVM_GETITEMTEXT, (WPARAM)i, (LPARAM)(LV_ITEM FAR *)&lvi);\
}
#define ListView_SetItemText(hwndLV, i, iSubItem_, pszText_) \
{ LV_ITEM lvi;\
  lvi.iSubItem = iSubItem_;\
  lvi.pszText = pszText_;\
  SendMessage((hwndLV), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)(LV_ITEM FAR *)&lvi);\
}
#define ListView_SetItemCount(hwndLV, cItems) \
  SendMessage((hwndLV), LVM_SETITEMCOUNT, (WPARAM)cItems, 0)
#define ListView_SortItems(hwndLV, _pfnCompare, _lPrm) \
  (BOOL)SendMessage((hwndLV), LVM_SORTITEMS, (WPARAM)(LPARAM)_lPrm, \
  (LPARAM)(PFNLVCOMPARE)_pfnCompare)
#define ListView_SetItemPosition32(hwndLV, i, x, y) \
{ POINT ptNewPos = {x,y}; \
    SendMessage((hwndLV), LVM_SETITEMPOSITION32, (WPARAM)(int)(i), (LPARAM)&ptNewPos); \
}
#define ListView_GetSelectedCount(hwndLV) \
    (UINT)SendMessage((hwndLV), LVM_GETSELECTEDCOUNT, 0, 0L)
#define ListView_GetItemSpacing(hwndLV, fSmall) \
        (DWORD)SendMessage((hwndLV), LVM_GETITEMSPACING, fSmall, 0L)
#define TreeView_InsertItem(hwnd, lpis) \
    (HTREEITEM)SendMessage((hwnd), TVM_INSERTITEM, 0, (LPARAM)(LPTV_INSERTSTRUCT)(lpis))
#define TreeView_Expand(hwnd, hitem, code) \
    (BOOL)SendMessage((hwnd), TVM_EXPAND, (WPARAM)code, (LPARAM)(HTREEITEM)(hitem))
#define TreeView_GetItemRect(hwnd, hitem, prc, code) \
    (*(HTREEITEM FAR *)prc = (hitem), (BOOL)SendMessage((hwnd), TVM_GETITEMRECT, (WPARAM)(code), (LPARAM)(RECT FAR*)(prc)))
#define TreeView_GetCount(hwnd) \
    (UINT)SendMessage((hwnd), TVM_GETCOUNT, 0, 0)
#define TreeView_GetIndent(hwnd) \
    (UINT)SendMessage((hwnd), TVM_GETINDENT, 0, 0)
#define TreeView_SetIndent(hwnd, indent) \
    (BOOL)SendMessage((hwnd), TVM_SETINDENT, (WPARAM)indent, 0)
#define TreeView_GetImageList(hwnd, iImage) \
    (HIMAGELIST)SendMessage((hwnd), TVM_GETIMAGELIST, iImage, 0)
#define TreeView_SetImageList(hwnd, himl, iImage) \
    (HIMAGELIST)SendMessage((hwnd), TVM_SETIMAGELIST, iImage, (LPARAM)(UINT)(HIMAGELIST)(himl))
#define TreeView_GetNextItem(hwnd, hitem, code) \
    (HTREEITEM)SendMessage((hwnd), TVM_GETNEXTITEM, (WPARAM)code, (LPARAM)(HTREEITEM)(hitem))
#define TreeView_GetChild(hwnd, hitem)		TreeView_GetNextItem(hwnd, hitem, TVGN_CHILD)
#define TreeView_GetNextSibling(hwnd, hitem)	TreeView_GetNextItem(hwnd, hitem, TVGN_NEXT)
#define TreeView_GetPrevSibling(hwnd, hitem)    TreeView_GetNextItem(hwnd, hitem, TVGN_PREVIOUS)
#define TreeView_GetParent(hwnd, hitem)		TreeView_GetNextItem(hwnd, hitem, TVGN_PARENT)
#define TreeView_GetFirstVisible(hwnd)		TreeView_GetNextItem(hwnd, NULL,  TVGN_FIRSTVISIBLE)
#define TreeView_GetNextVisible(hwnd, hitem)	TreeView_GetNextItem(hwnd, hitem, TVGN_NEXTVISIBLE)
#define TreeView_GetPrevVisible(hwnd, hitem)    TreeView_GetNextItem(hwnd, hitem, TVGN_PREVIOUSVISIBLE)
#define TreeView_GetSelection(hwnd)		TreeView_GetNextItem(hwnd, NULL,  TVGN_CARET)
#define TreeView_GetDropHilight(hwnd)		TreeView_GetNextItem(hwnd, NULL,  TVGN_DROPHILITE)
#define TreeView_GetRoot(hwnd)		    	TreeView_GetNextItem(hwnd, NULL,  TVGN_ROOT)
#define TreeView_Select(hwnd, hitem, code) \
    (HTREEITEM)SendMessage((hwnd), TVM_SELECTITEM, (WPARAM)code, (LPARAM)(HTREEITEM)(hitem))
#define TreeView_SelectItem(hwnd, hitem)	    TreeView_Select(hwnd, hitem, TVGN_CARET)
#define TreeView_SelectDropTarget(hwnd, hitem)	    TreeView_Select(hwnd, hitem, TVGN_DROPHILITE)
#define TreeView_GetItem(hwnd, pitem) \
    (BOOL)SendMessage((hwnd), TVM_GETITEM, 0, (LPARAM)(TV_ITEM FAR*)(pitem))
#define TreeView_SetItem(hwnd, pitem) \
    (BOOL)SendMessage((hwnd), TVM_SETITEM, 0, (LPARAM)(const TV_ITEM FAR*)(pitem))
#define TreeView_EditLabel(hwnd, hitem) \
    (HWND)SendMessage((hwnd), TVM_EDITLABEL, 0, (LPARAM)(HTREEITEM)(hitem))
#define TreeView_GetEditControl(hwnd) \
    (HWND)SendMessage((hwnd), TVM_GETEDITCONTROL, 0, 0)
#define TreeView_GetVisibleCount(hwnd) \
    (UINT)SendMessage((hwnd), TVM_GETVISIBLECOUNT, 0, 0)
#define TreeView_HitTest(hwnd, lpht) \
    (HTREEITEM)SendMessage((hwnd), TVM_HITTEST, 0, (LPARAM)(LPTV_HITTESTINFO)(lpht))
#define TreeView_CreateDragImage(hwnd, hitem) \
    (HIMAGELIST)SendMessage((hwnd), TVM_CREATEDRAGIMAGE, 0, (LPARAM)(HTREEITEM)(hitem))
#define TreeView_SortChildren(hwnd, hitem, recurse) \
    (BOOL)SendMessage((hwnd), TVM_SORTCHILDREN, (WPARAM)recurse, (LPARAM)(HTREEITEM)(hitem))
#define TreeView_EnsureVisible(hwnd, hitem) \
    (BOOL)SendMessage((hwnd), TVM_ENSUREVISIBLE, 0, (LPARAM)(HTREEITEM)(hitem))
#define TreeView_SortChildrenCB(hwnd, psort, recurse) \
    (BOOL)SendMessage((hwnd), TVM_SORTCHILDRENCB, (WPARAM)recurse, \
    (LPARAM)(LPTV_SORTCB)(psort))
#define TabCtrl_GetBkColor(hwnd)  \
    (COLORREF)SendMessage((hwnd), TCM_GETBKCOLOR, 0, 0L)
#define TabCtrl_SetBkColor(hwnd, clrBk) \
    (BOOL)SendMessage((hwnd), TCM_SETBKCOLOR, 0, (LPARAM)(COLORREF)(clrBk))
#define TabCtrl_GetImageList(hwnd) \
    (HIMAGELIST)SendMessage((hwnd), TCM_GETIMAGELIST, 0, 0L)
#define TabCtrl_SetImageList(hwnd, himl) \
    (HIMAGELIST)SendMessage((hwnd), TCM_SETIMAGELIST, 0, (LPARAM)(UINT)(HIMAGELIST)(himl))
#define TabCtrl_GetItemCount(hwnd) \
    (int)SendMessage((hwnd), TCM_GETITEMCOUNT, 0, 0L)
#define TabCtrl_GetItem(hwnd, iItem, pitem) \
    (BOOL)SendMessage((hwnd), TCM_GETITEM, (WPARAM)(int)iItem, (LPARAM)(TC_ITEM FAR*)(pitem))
#define TabCtrl_SetItem(hwnd, iItem, pitem) \
    (BOOL)SendMessage((hwnd), TCM_SETITEM, (WPARAM)(int)iItem, (LPARAM)(TC_ITEM FAR*)(pitem))
#define TabCtrl_InsertItem(hwnd, iItem, pitem)   \
    (int)SendMessage((hwnd), TCM_INSERTITEM, (WPARAM)(int)iItem, (LPARAM)(const TC_ITEM FAR*)(pitem))
#define TabCtrl_GetItemRect(hwnd, i, prc) \
    (BOOL)SendMessage((hwnd), TCM_GETITEMRECT, (WPARAM)(int)(i), (LPARAM)(RECT FAR*)(prc))
#define TabCtrl_GetCurSel(hwnd) \
    (int)SendMessage((hwnd), TCM_GETCURSEL, 0, 0)
#define TabCtrl_SetCurSel(hwnd, i) \
    (int)SendMessage((hwnd), TCM_SETCURSEL, (WPARAM)i, 0)
#define TabCtrl_HitTest(hwndTC, pinfo) \
    (int)SendMessage((hwndTC), TCM_HITTEST, 0, (LPARAM)(TC_HITTESTINFO FAR*)(pinfo))
#define TabCtrl_SetItemExtra(hwndTC, cb) \
    (BOOL)SendMessage((hwndTC), TCM_SETITEMEXTRA, (WPARAM)(cb), 0L)
#define TabCtrl_GetTextColor(hwnd)  \
    (COLORREF)SendMessage((hwnd), TCM_GETTEXTCOLOR, 0, 0L)
#define TabCtrl_SetTextColor(hwnd, clrText) \
    (BOOL)SendMessage((hwnd), TCM_SETTEXTCOLOR, 0, (LPARAM)(COLORREF)(clrText))
#define TabCtrl_GetTextColor(hwnd)  \
    (COLORREF)SendMessage((hwnd), TCM_GETTEXTCOLOR, 0, 0L)
#define TabCtrl_SetTextBkColor(hwnd, clrTextBk) \
    (BOOL)SendMessage((hwnd), TCM_SETTEXTBKCOLOR, 0, (LPARAM)(COLORREF)(clrTextBk))
#define TabCtrl_AdjustRect(hwnd, bLarger, prc) \
    (void)SendMessage(hwnd, TCM_ADJUSTRECT, (WPARAM)(BOOL)bLarger, (LPARAM)(RECT FAR *)prc)
#define TabCtrl_SetItemSize(hwnd, x, y) \
    (DWORD)SendMessage((hwnd), TCM_SETITEMSIZE, 0, MAKELPARAM(x,y))
#define TabCtrl_RemoveImage(hwnd, i) \
        (void)SendMessage((hwnd), TCM_REMOVEIMAGE, i, 0L)
#define TabCtrl_SetPadding(hwnd,  cx, cy) \
        (void)SendMessage((hwnd), TCM_SETPADDING, 0, MAKELPARAM(cx, cy))
#define TabCtrl_GetRowCount(hwnd) \
        (int)SendMessage((hwnd), TCM_GETROWCOUNT, 0, 0L)
#define TabCtrl_GetToolTips(hwnd) \
        (HWND)SendMessage((hwnd), TCM_GETTOOLTIPS, 0, 0L)
#define TabCtrl_SetToolTips(hwnd, hwndTT) \
        (void)SendMessage((hwnd), TCM_SETTOOLTIPS, (WPARAM)hwndTT, 0L)
#define TabCtrl_GetCurFocus(hwnd) \
    (int)SendMessage((hwnd), TCM_GETCURFOCUS, 0, 0)
#define Animate_Open(hwnd, szName)          (BOOL)SendMessage(hwnd, ACM_OPEN, 0, (LPARAM)(LPSTR)(szName))
#define Animate_Play(hwnd, from, to, rep)   (BOOL)SendMessage(hwnd, ACM_PLAY, (WPARAM)(UINT)(rep), (LPARAM)MAKELONG(from, to))
#define Animate_Stop(hwnd)                  (BOOL)SendMessage(hwnd, ACM_STOP, 0, 0)

// multimedia\media\avi\inc.16\compman.h
#define ICQueryAbout(hic) \
    (ICSendMessage(hic, ICM_ABOUT, (DWORD) -1, ICMF_ABOUT_QUERY) == ICERR_OK)
#define ICAbout(hic, hwnd) \
    ICSendMessage(hic, ICM_ABOUT, (DWORD)(UINT)(hwnd), 0)
#define ICQueryConfigure(hic) \
    (ICSendMessage(hic, ICM_CONFIGURE, (DWORD) -1, ICMF_CONFIGURE_QUERY) == ICERR_OK)
#define ICConfigure(hic, hwnd) \
    ICSendMessage(hic, ICM_CONFIGURE, (DWORD)(UINT)(hwnd), 0)
#define ICGetState(hic, pv, cb) \
    ICSendMessage(hic, ICM_GETSTATE, (DWORD)(LPVOID)(pv), (DWORD)(cb))
#define ICSetState(hic, pv, cb) \
    ICSendMessage(hic, ICM_SETSTATE, (DWORD)(LPVOID)(pv), (DWORD)(cb))
#define ICGetDefaultQuality(hic) \
    (ICSendMessage(hic, ICM_GETDEFAULTQUALITY, (DWORD)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)
#define ICGetDefaultKeyFrameRate(hic) \
    (ICSendMessage(hic, ICM_GETDEFAULTKEYFRAMERATE, (DWORD)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)
#define ICDrawWindow(hic, prc) \
    ICSendMessage(hic, ICM_DRAW_WINDOW, (DWORD)(LPVOID)(prc), sizeof(RECT))
#define ICCompressBegin(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_COMPRESS_BEGIN, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICCompressQuery(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_COMPRESS_QUERY, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICCompressGetFormat(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_COMPRESS_GET_FORMAT, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICCompressGetSize(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_COMPRESS_GET_SIZE, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICCompressEnd(hic) \
    ICSendMessage(hic, ICM_COMPRESS_END, 0, 0)
#define ICDecompressBegin(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_DECOMPRESS_BEGIN, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICDecompressQuery(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_DECOMPRESS_QUERY, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICDecompressGetFormat(hic, lpbiInput, lpbiOutput) \
    ((LONG) ICSendMessage(hic, ICM_DECOMPRESS_GET_FORMAT, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput)))
#define ICDecompressGetPalette(hic, lpbiInput, lpbiOutput) \
    ICSendMessage(hic, ICM_DECOMPRESS_GET_PALETTE, (DWORD)(LPVOID)(lpbiInput), (DWORD)(LPVOID)(lpbiOutput))
#define ICDecompressSetPalette(hic, lpbiPalette) \
    ICSendMessage(hic, ICM_DECOMPRESS_SET_PALETTE, (DWORD)(LPVOID)(lpbiPalette), 0)
#define ICDecompressEnd(hic) \
    ICSendMessage(hic, ICM_DECOMPRESS_END, 0, 0)
#define ICDecompressExEnd(hic) \
    ICSendMessage(hic, ICM_DECOMPRESSEX_END, 0, 0)
#define ICDrawQuery(hic, lpbiInput) \
    ICSendMessage(hic, ICM_DRAW_QUERY, (DWORD)(LPVOID)(lpbiInput), 0L)
#define ICDrawChangePalette(hic, lpbiInput) \
    ICSendMessage(hic, ICM_DRAW_CHANGEPALETTE, (DWORD)(LPVOID)(lpbiInput), 0L)
#define ICGetBuffersWanted(hic, lpdwBuffers) \
    ICSendMessage(hic, ICM_GETBUFFERSWANTED, (DWORD)(LPVOID)(lpdwBuffers), 0)
#define ICDrawEnd(hic) \
    ICSendMessage(hic, ICM_DRAW_END, 0, 0)
#define ICDrawStart(hic) \
    ICSendMessage(hic, ICM_DRAW_START, 0, 0)
#define ICDrawStartPlay(hic, lFrom, lTo) \
    ICSendMessage(hic, ICM_DRAW_START_PLAY, (DWORD)(lFrom), (DWORD)(lTo))
#define ICDrawStop(hic) \
    ICSendMessage(hic, ICM_DRAW_STOP, 0, 0)
#define ICDrawStopPlay(hic) \
    ICSendMessage(hic, ICM_DRAW_STOP_PLAY, 0, 0)
#define ICDrawGetTime(hic, lplTime) \
    ICSendMessage(hic, ICM_DRAW_GETTIME, (DWORD)(LPVOID)(lplTime), 0)
#define ICDrawSetTime(hic, lTime) \
    ICSendMessage(hic, ICM_DRAW_SETTIME, (DWORD)lTime, 0)
#define ICDrawRealize(hic, hdc, fBackground) \
    ICSendMessage(hic, ICM_DRAW_REALIZE, (DWORD)(UINT)(HDC)(hdc), (DWORD)(BOOL)(fBackground))
#define ICDrawFlush(hic) \
    ICSendMessage(hic, ICM_DRAW_FLUSH, 0, 0)
#define ICDrawRenderBuffer(hic) \
    ICSendMessage(hic, ICM_DRAW_RENDERBUFFER, 0, 0)

// multimedia\media\avi\inc.16\mciwnd.h
#define MCIWndPaletteKick(hwnd)     (BOOL)MCIWndSM(hwnd,MCIWNDM_PALETTEKICK,0,0)
#define MCIWndGetPalette(hwnd)      (HPALETTE)MCIWndSM(hwnd, MCIWNDM_GETPALETTE, 0, 0)
#define MCIWndSetPalette(hwnd, hpal) (LONG)MCIWndSM(hwnd, MCIWNDM_SETPALETTE, (WPARAM)(HPALETTE)(hpal), 0)
#define MCIWNDM_NOTIFYMODE      (WM_USER + 200)  // wp = hwnd, lp = mode
#define MCIWNDM_NOTIFYPOS	(WM_USER + 201)  // wp = hwnd, lp = pos
#define MCIWNDM_NOTIFYSIZE	(WM_USER + 202)  // wp = hwnd
#define MCIWNDM_NOTIFYMEDIA     (WM_USER + 203)  // wp = hwnd, lp = fn
#define MCIWNDM_NOTIFYERROR     (WM_USER + 205)  // wp = hwnd, lp = error

// multimedia\media\avi\inc.16\prsht.h
#define PropSheet_SetCurSel(hDlg, hpage, index) \
        SendMessage(hDlg, PSM_SETCURSEL, (WPARAM)index, (LPARAM)hpage)
#define PropSheet_RemovePage(hDlg, index, hpage) \
        SendMessage(hDlg, PSM_REMOVEPAGE, index, (LPARAM)hpage)
#define PropSheet_AddPage(hDlg, hpage) \
        SendMessage(hDlg, PSM_ADDPAGE, 0, (LPARAM)hpage)
#define PropSheet_Changed(hDlg, hwnd) \
        SendMessage(hDlg, PSM_CHANGED, (WPARAM)hwnd, 0L)
#define PropSheet_RestartWindows(hDlg) \
        SendMessage(hDlg, PSM_RESTARTWINDOWS, 0, 0L)
#define PropSheet_RebootSystem(hDlg) \
        SendMessage(hDlg, PSM_REBOOTSYSTEM, 0, 0L)
#define PropSheet_QuerySiblings(hDlg, wParam, lParam) \
        SendMessage(hDlg, PSM_QUERYSIBLINGS, wParam, lParam)
#define PropSheet_UnChanged(hDlg, hwnd) \
        SendMessage(hDlg, PSM_UNCHANGED, (WPARAM)hwnd, 0L)
#define PropSheet_Apply(hDlg) \
        SendMessage(hDlg, PSM_APPLY, 0, 0L)
#define PropSheet_SetTitle(hDlg, wStyle, lpszText)\
        SendMessage(hDlg, PSM_SETTITLE, wStyle, (LPARAM)(LPCSTR)lpszText)

// multimedia\media\avi\inc.16\pwin16.h
#define GET_WM_ACTIVATE_HWND(wp, lp)                (HWND)LOWORD(lp)
#define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)   \
        (WPARAM)(s), MAKELONG(hwnd, fmin)
#define GET_WM_CHARTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
#define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd) \
        (WPARAM)(ch), MAKELONG(hwnd, pos)
#define GET_WM_COMMAND_HWND(wp, lp)                 (HWND)LOWORD(lp)
#define GET_WM_COMMAND_MPS(id, hwnd, cmd)    \
        (WPARAM)(id), MAKELONG(hwnd, cmd)
#define GET_WM_CTLCOLOR_HWND(wp, lp, msg)           (HWND)LOWORD(lp)
#define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type) \
        (WPARAM)(hdc), MAKELONG(hwnd, type)
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
#define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
#define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
        (WPARAM)(hwndA), 0
#define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)       (HWND)LOWORD(lp)
#define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd) \
        (WPARAM)(msg), MAKELONG(hwnd, id)
#define GET_WM_VKEYTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
#define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) \
        (WPARAM)(code), MAKELONG(hwnd, item)
#define GET_WM_HSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
#define GET_WM_HSCROLL_MPS(code, pos, hwnd)    \
        (WPARAM)(code), MAKELONG(pos, hwnd)
#define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
#define GET_WM_VSCROLL_MPS(code, pos, hwnd)    \
        (WPARAM)(code), MAKELONG(pos, hwnd)
#define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)       (HWND)LOWORD(lp)

// multimedia\media\avi\inc.16\win32.h
    #define GET_WM_ACTIVATE_HWND(wp, lp)                (HWND)LOWORD(lp)
    #define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)   \
            (WPARAM)(s), MAKELONG(hwnd, fmin)
    #define GET_WM_CHARTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
    #define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd) \
            (WPARAM)(ch), MAKELONG(hwnd, pos)
    #define GET_WM_COMMAND_HWND(wp, lp)                 (HWND)LOWORD(lp)
    #define GET_WM_COMMAND_MPS(id, hwnd, cmd)    \
            (WPARAM)(id), MAKELONG(hwnd, cmd)
    #define GET_WM_CTLCOLOR_HWND(wp, lp, msg)           (HWND)LOWORD(lp)
    #define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type) \
            (WPARAM)(hdc), MAKELONG(hwnd, type)
    #define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
    #define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
    #define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
    #define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
            (WPARAM)(hwndA), 0
    #define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)       (HWND)LOWORD(lp)
    #define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd) \
            (WPARAM)(msg), MAKELONG(hwnd, id)
    #define GET_WM_VKEYTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
    #define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) \
            (WPARAM)(code), MAKELONG(hwnd, item)
    #define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)       (HWND)LOWORD(lp)
    #define GET_WM_HSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
    #define GET_WM_HSCROLL_MPS(code, pos, hwnd)    \
            (WPARAM)(code), MAKELONG(pos, hwnd)
    #define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
    #define GET_WM_VSCROLL_MPS(code, pos, hwnd)    \
            (WPARAM)(code), MAKELONG(pos, hwnd)

// multimedia\media\avi\inc.16\windowsx.h
#define     SetWindowRedraw(hwnd, fRedraw)  \
                    ((void)SendMessage(hwnd, WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L))
#define     IsRestored(hwnd)    ((GetWindowStyle(hwnd) & (WS_MINIMIZE | WS_MAXIMIZE)) == 0L)
#define     SetWindowFont(hwnd, hfont, fRedraw) FORWARD_WM_SETFONT((hwnd), (hfont), (fRedraw), SendMessage)
#define     GetWindowFont(hwnd)                 FORWARD_WM_GETFONT((hwnd), SendMessage)
#define HANDLE_WM_COMPACTING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_COMPACTING(hwnd, compactRatio, fn) \
    (void)(fn)((hwnd), WM_COMPACTING, (WPARAM)(UINT)(compactRatio), 0L)
#define HANDLE_WM_WININICHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_WININICHANGE(hwnd, lpszSectionName, fn) \
    (void)(fn)((hwnd), WM_WININICHANGE, 0, (LPARAM)(LPCSTR)(lpszSectionName))
#define HANDLE_WM_SYSCOLORCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_SYSCOLORCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_SYSCOLORCHANGE, 0, 0L)
#define HANDLE_WM_QUERYNEWPALETTE(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYNEWPALETTE(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYNEWPALETTE, 0, 0L)
#define HANDLE_WM_PALETTEISCHANGING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTEISCHANGING(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTEISCHANGING, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_PALETTECHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTECHANGED(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTECHANGED, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_FONTCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_FONTCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_FONTCHANGE, 0, 0L)
#define HANDLE_WM_DEVMODECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_DEVMODECHANGE(hwnd, lpszDeviceName, fn) \
    (void)(fn)((hwnd), WM_DEVMODECHANGE, 0,(LPARAM)(LPCSTR)(lpszDeviceName))
#define HANDLE_WM_TIMECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_TIMECHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_TIMECHANGE, 0, 0L)
#define HANDLE_WM_POWER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_POWER(hwnd, code, fn) \
    (void)(fn)((hwnd), WM_POWER, (WPARAM)(code), 0L)
#define HANDLE_WM_QUERYENDSESSION(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYENDSESSION(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYENDSESSION, 0, 0L)
#define HANDLE_WM_ENDSESSION(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENDSESSION(hwnd, fEnding, fn) \
    (void)(fn)((hwnd), WM_ENDSESSION, (WPARAM)(BOOL)(fEnding), 0L)
#define HANDLE_WM_QUIT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_QUIT(hwnd, exitCode, fn) \
    (void)(fn)((hwnd), WM_QUIT, (WPARAM)(exitCode), 0L)
#define HANDLE_WM_SYSTEMERROR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_SYSTEMERROR(hwnd, errCode, fn) \
    (void)(fn)((hwnd), WM_SYSTEMERROR, (WPARAM)(errCode), 0L)
#define HANDLE_WM_CREATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (CREATESTRUCT FAR*)(lParam)) ? 0L : (LRESULT)-1L)
#define FORWARD_WM_CREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_CREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_NCCREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (CREATESTRUCT FAR*)(lParam))
#define FORWARD_WM_NCCREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCCREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_DESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROY, 0, 0L)
#define HANDLE_WM_NCDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_NCDESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_NCDESTROY, 0, 0L)
#define HANDLE_WM_SHOWWINDOW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), LOWORD(lParam)), 0L)
#define HANDLE_WM_SETREDRAW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_SETREDRAW(hwnd, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETREDRAW, (WPARAM)(fRedraw), 0L)
#define HANDLE_WM_ENABLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENABLE(hwnd, fEnable, fn) \
    (void)(fn)((hwnd), WM_ENABLE, (WPARAM)(BOOL)(fEnable), 0L)
#define HANDLE_WM_SETTEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_SETTEXT(hwnd, lpszText, fn) \
    (void)(fn)((hwnd), WM_SETTEXT, 0, (LPARAM)(LPCSTR)(lpszText))
#define HANDLE_WM_GETTEXT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (int)(wParam), (LPSTR)(lParam))
#define FORWARD_WM_GETTEXT(hwnd, cchTextMax, lpszText, fn) \
    (int)(DWORD)(fn)((hwnd), WM_GETTEXT, (WPARAM)(int)(cchTextMax), (LPARAM)(LPSTR)(lpszText))
#define HANDLE_WM_GETTEXTLENGTH(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)(hwnd)
#define FORWARD_WM_GETTEXTLENGTH(hwnd, fn) \
    (int)(DWORD)(fn)((hwnd), WM_GETTEXTLENGTH, 0, 0L)
#define HANDLE_WM_WINDOWPOSCHANGING(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (WINDOWPOS FAR*)(lParam))
#define FORWARD_WM_WINDOWPOSCHANGING(hwnd, lpwpos, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_WINDOWPOSCHANGING, 0, (LPARAM)(WINDOWPOS FAR*)(lpwpos))
#define HANDLE_WM_WINDOWPOSCHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const WINDOWPOS FAR*)(lParam)), 0L)
#define FORWARD_WM_WINDOWPOSCHANGED(hwnd, lpwpos, fn) \
    (void)(fn)((hwnd), WM_WINDOWPOSCHANGED, 0, (LPARAM)(const WINDOWPOS FAR*)(lpwpos))
#define HANDLE_WM_MOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_MOVE(hwnd, x, y, fn) \
    (void)(fn)((hwnd), WM_MOVE, 0, MAKELPARAM((int)(x), (int)(y)))
#define HANDLE_WM_SIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_SIZE(hwnd, state, cx, cy, fn) \
    (void)(fn)((hwnd), WM_SIZE, (WPARAM)(UINT)(state), MAKELPARAM((int)(cx), (int)(cy)))
#define HANDLE_WM_QUERYOPEN(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYOPEN(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYOPEN, 0, 0L)
#define HANDLE_WM_GETMINMAXINFO(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MINMAXINFO FAR*)(lParam)), 0L)
#define FORWARD_WM_GETMINMAXINFO(hwnd, lpMinMaxInfo, fn) \
    (void)(fn)((hwnd), WM_GETMINMAXINFO, 0, (LPARAM)(MINMAXINFO FAR*)(lpMinMaxInfo))
#define HANDLE_WM_PAINT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PAINT(hwnd, fn) \
    (void)(fn)((hwnd), WM_PAINT, 0, 0L)
#define HANDLE_WM_ERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define FORWARD_WM_ERASEBKGND(hwnd, hdc, fn) \
   (BOOL)(DWORD)(fn)((hwnd), WM_ERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define HANDLE_WM_ICONERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define FORWARD_WM_ICONERASEBKGND(hwnd, hdc, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_ICONERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define HANDLE_WM_NCPAINT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HRGN)(wParam)), 0L)
#define FORWARD_WM_NCPAINT(hwnd, hrgn, fn) \
    (void)(fn)((hwnd), WM_NCPAINT, (WPARAM)(HRGN)(hrgn), 0L)
#define HANDLE_WM_NCCALCSIZE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (NCCALCSIZE_PARAMS FAR*)(lParam))
#define FORWARD_WM_NCCALCSIZE(hwnd, fCalcValidRects, lpcsp, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_NCCALCSIZE, (WPARAM)(fCalcValidRects), (LPARAM)(NCCALCSIZE_PARAMS FAR*)(lpcsp))
#define HANDLE_WM_NCHITTEST(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_NCHITTEST(hwnd, x, y, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_NCHITTEST, 0, MAKELPARAM((int)(x), (int)(y)))
#define HANDLE_WM_QUERYDRAGICON(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define FORWARD_WM_QUERYDRAGICON(hwnd, fn) \
    (HICON)(UINT)(DWORD)(fn)((hwnd), WM_QUERYDRAGICON, 0, 0L)
#define HANDLE_WM_DROPFILES(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HDROP)(wParam)), 0L)
#define FORWARD_WM_DROPFILES(hwnd, hdrop, fn) \
    (void)(fn)((hwnd), WM_DROPFILES, (WPARAM)(hdrop), 0L)
#define HANDLE_WM_ACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define FORWARD_WM_ACTIVATE(hwnd, state, hwndActDeact, fMinimized, fn) \
    (void)(fn)((hwnd), WM_ACTIVATE, (WPARAM)(UINT)(state), MAKELPARAM((UINT)(HWND)(hwndActDeact), (UINT)(BOOL)(fMinimized)))
#define HANDLE_WM_ACTIVATEAPP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (HTASK)LOWORD(lParam)), 0L)
#define FORWARD_WM_ACTIVATEAPP(hwnd, fActivate, htaskActDeact, fn) \
    (void)(fn)((hwnd), WM_ACTIVATEAPP, (WPARAM)(BOOL)(fActivate), MAKELPARAM((htaskActDeact),0))
#define HANDLE_WM_NCACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (BOOL)(wParam), (HWND)LOWORD(lParam), (BOOL)HIWORD(lParam))
#define FORWARD_WM_NCACTIVATE(hwnd, fActive, hwndActDeact, fMinimized, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCACTIVATE, (WPARAM)(BOOL)(fActive), MAKELPARAM((UINT)(HWND)(hwndActDeact), (UINT)(BOOL)(fMinimized)))
#define HANDLE_WM_SETFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_SETFOCUS(hwnd, hwndOldFocus, fn) \
    (void)(fn)((hwnd), WM_SETFOCUS, (WPARAM)(HWND)(hwndOldFocus), 0L)
#define HANDLE_WM_KILLFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_KILLFOCUS(hwnd, hwndNewFocus, fn) \
    (void)(fn)((hwnd), WM_KILLFOCUS, (WPARAM)(HWND)(hwndNewFocus), 0L)
#define HANDLE_WM_KEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_KEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_KEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_KEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_CHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_CHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_CHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define HANDLE_WM_DEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_DEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_DEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define HANDLE_WM_SYSKEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSKEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_SYSKEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSKEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_SYSCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_SYSCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define HANDLE_WM_SYSDEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_SYSDEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSDEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define HANDLE_WM_MOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MOUSEMOVE(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MOUSEMOVE, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_LBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_LBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_LBUTTONDBLCLK : WM_LBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_LBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_LBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_LBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_LBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_RBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_RBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_RBUTTONDBLCLK : WM_RBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_RBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_RBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_RBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_RBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_MBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_MBUTTONDBLCLK : WM_MBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_MBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_MBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCMOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMOUSEMOVE(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMOUSEMOVE, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCLBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCLBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCLBUTTONDBLCLK : WM_NCLBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCLBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCLBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCLBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCLBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCRBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCRBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCRBUTTONDBLCLK : WM_NCRBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCRBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCRBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCRBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCRBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCMBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCMBUTTONDBLCLK : WM_NCMBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCMBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCMBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_MOUSEACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))
#define FORWARD_WM_MOUSEACTIVATE(hwnd, hwndTopLevel, codeHitTest, msg, fn) \
    (int)(DWORD)(fn)((hwnd), WM_MOUSEACTIVATE, (WPARAM)(HWND)(hwndTopLevel), MAKELPARAM((codeHitTest), (msg)))
#define HANDLE_WM_CANCELMODE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CANCELMODE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CANCELMODE, 0, 0L)
#define HANDLE_WM_TIMER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_TIMER(hwnd, id, fn) \
    (void)(fn)((hwnd), WM_TIMER, (WPARAM)(UINT)(id), 0L)
#define HANDLE_WM_INITMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam)), 0L)
#define FORWARD_WM_INITMENU(hwnd, hMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENU, (WPARAM)(HMENU)(hMenu), 0L)
#define HANDLE_WM_INITMENUPOPUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam), (int)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define FORWARD_WM_INITMENUPOPUP(hwnd, hMenu, item, fSystemMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENUPOPUP, (WPARAM)(HMENU)(hMenu), MAKELPARAM((item),(fSystemMenu)))
#define HANDLE_WM_MENUSELECT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)HIWORD(lParam), (LOWORD(lParam) & MF_POPUP) ? 0 : (int)(wParam), \
                            (LOWORD(lParam) & MF_POPUP) ? (HMENU)(wParam) : 0, LOWORD(lParam)), 0L)
#define FORWARD_WM_MENUSELECT(hwnd, hmenu, item, hmenuPopup, flags, fn) \
    (void)(fn)((hwnd), WM_MENUSELECT, ((flags) & MF_POPUP) ? (WPARAM)(HMENU)(hmenuPopup) : (WPARAM)(int)(item), MAKELPARAM((flags), (hmenu)))
#define HANDLE_WM_MENUCHAR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam), LOWORD(lParam), (HMENU)HIWORD(lParam));
#define FORWARD_WM_MENUCHAR(hwnd, ch, flags, hmenu, fn) \
    (DWORD)(fn)((hwnd), WM_MENUCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((flags), (UINT)(hmenu)))
#define HANDLE_WM_COMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (HWND)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_COMMAND(hwnd, id, hwndCtl, codeNotify, fn) \
    (void)(fn)((hwnd), WM_COMMAND, (WPARAM)(int)(id), MAKELPARAM((UINT)(hwndCtl), (codeNotify)))
#define HANDLE_WM_HSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)HIWORD(lParam), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_HSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define HANDLE_WM_VSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)HIWORD(lParam), (UINT)(wParam),  (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_VSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define HANDLE_WM_CUT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CUT(hwnd, fn) \
    (void)(fn)((hwnd), WM_CUT, 0, 0L)
#define HANDLE_WM_COPY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_COPY(hwnd, fn) \
    (void)(fn)((hwnd), WM_COPY, 0, 0L)
#define HANDLE_WM_PASTE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PASTE(hwnd, fn) \
    (void)(fn)((hwnd), WM_PASTE, 0, 0L)
#define HANDLE_WM_CLEAR(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CLEAR(hwnd, fn) \
    (void)(fn)((hwnd), WM_CLEAR, 0, 0L)
#define HANDLE_WM_UNDO(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_UNDO(hwnd, fn) \
    (void)(fn)((hwnd), WM_UNDO, 0, 0L)
#define HANDLE_WM_RENDERFORMAT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HANDLE)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_RENDERFORMAT(hwnd, fmt, fn) \
    (HANDLE)(UINT)(DWORD)(fn)((hwnd), WM_RENDERFORMAT, (WPARAM)(UINT)(fmt), 0L)
#define HANDLE_WM_RENDERALLFORMATS(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_RENDERALLFORMATS(hwnd, fn) \
    (void)(fn)((hwnd), WM_RENDERALLFORMATS, 0, 0L)
#define HANDLE_WM_DESTROYCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROYCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROYCLIPBOARD, 0, 0L)
#define HANDLE_WM_DRAWCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DRAWCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DRAWCLIPBOARD, 0, 0L)
#define HANDLE_WM_PAINTCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const PAINTSTRUCT FAR*)GlobalLock((HGLOBAL)LOWORD(lParam))), GlobalUnlock((HGLOBAL)LOWORD(lParam)), 0L)
#define FORWARD_WM_PAINTCLIPBOARD(hwnd, hwndCBViewer, lpPaintStruct, fn) \
    (void)(fn)((hwnd), WM_PAINTCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(lpPaintStruct))
#define HANDLE_WM_SIZECLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const RECT FAR*)GlobalLock((HGLOBAL)LOWORD(lParam))), GlobalUnlock((HGLOBAL)LOWORD(lParam)), 0L)
#define FORWARD_WM_SIZECLIPBOARD(hwnd, hwndCBViewer, lprc, fn) \
    (void)(fn)((hwnd), WM_SIZECLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(lprc))
#define HANDLE_WM_VSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_VSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_HSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_HSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_ASKCBFORMATNAME(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (LPSTR)(lParam)), 0L)
#define FORWARD_WM_ASKCBFORMATNAME(hwnd, cchMax, rgchName, fn) \
    (void)(fn)((hwnd), WM_ASKCBFORMATNAME, (WPARAM)(int)(cchMax), (LPARAM)(rgchName))
#define HANDLE_WM_CHANGECBCHAIN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (HWND)LOWORD(lParam)), 0L)
#define FORWARD_WM_CHANGECBCHAIN(hwnd, hwndRemove, hwndNext, fn) \
    (void)(fn)((hwnd), WM_CHANGECBCHAIN, (WPARAM)(HWND)(hwndRemove), MAKELPARAM((UINT)(hwndNext), 0))
#define HANDLE_WM_SETCURSOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam));
#define FORWARD_WM_SETCURSOR(hwnd, hwndCursor, codeHitTest, msg, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_SETCURSOR, (WPARAM)(HWND)(hwndCursor), MAKELPARAM((codeHitTest), (msg)))
#define HANDLE_WM_SYSCOMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSCOMMAND(hwnd, cmd, x, y, fn) \
    (void)(fn)((hwnd), WM_SYSCOMMAND, (WPARAM)(UINT)(cmd), MAKELPARAM((x), (y)))
#define HANDLE_WM_MDICREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (MDICREATESTRUCT FAR*)(lParam))
#define FORWARD_WM_MDICREATE(hwnd, lpmcs, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDICREATE, 0, (LPARAM)(lpmcs))
#define HANDLE_WM_MDIDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIDESTROY(hwnd, hwndDestroy, fn) \
    (void)(fn)((hwnd), WM_MDIDESTROY, (WPARAM)(hwndDestroy), 0L)
#define HANDLE_WM_MDIACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (HWND)LOWORD(lParam), (HWND)HIWORD(lParam)), 0L)
#define FORWARD_WM_MDIACTIVATE(hwnd, fActive, hwndActivate, hwndDeactivate, fn) \
    (void)(fn)(hwnd, WM_MDIACTIVATE, (WPARAM)(fActive), MAKELPARAM((hwndActivate), (hwndDeactivate)))
#define HANDLE_WM_MDIRESTORE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIRESTORE(hwnd, hwndRestore, fn) \
    (void)(fn)((hwnd), WM_MDIRESTORE, (WPARAM)(hwndRestore), 0L)
#define HANDLE_WM_MDINEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (BOOL)LOWORD(lParam)), 0L)
#define FORWARD_WM_MDINEXT(hwnd, hwndCur, fPrev, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDINEXT, (WPARAM)(hwndCur), MAKELPARAM((fPrev), 0))
#define HANDLE_WM_MDIMAXIMIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIMAXIMIZE(hwnd, hwndMaximize, fn) \
    (void)(fn)((hwnd), WM_MDIMAXIMIZE, (WPARAM)(hwndMaximize), 0L)
#define HANDLE_WM_MDITILE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_MDITILE(hwnd, cmd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_MDITILE, (WPARAM)(cmd), 0L)
#define HANDLE_WM_MDICASCADE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_MDICASCADE(hwnd, cmd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_MDICASCADE, (WPARAM)(cmd), 0L)
#define HANDLE_WM_MDIICONARRANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_MDIICONARRANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_MDIICONARRANGE, 0, 0L)
#define HANDLE_WM_MDIGETACTIVE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define FORWARD_WM_MDIGETACTIVE(hwnd, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDIGETACTIVE, 0, 0L)
#define HANDLE_WM_MDISETMENU(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (HMENU)LOWORD(lParam), (HMENU)HIWORD(lParam))
#define FORWARD_WM_MDISETMENU(hwnd, fRefresh, hmenuFrame, hmenuWindow, fn) \
    (HMENU)(UINT)(DWORD)(fn)((hwnd), WM_MDISETMENU, (WPARAM)(fRefresh), MAKELPARAM((hmenuFrame), (hmenuWindow)))
#define HANDLE_WM_CHILDACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CHILDACTIVATE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CHILDACTIVATE, 0, 0L)
#define HANDLE_WM_NEXTDLGCTL(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HWND)(fn)((hwnd), (HWND)(wParam), (BOOL)LOWORD(lParam))
#define FORWARD_WM_NEXTDLGCTL(hwnd, hwndSetFocus, fNext, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_NEXTDLGCTL, (WPARAM)(HWND)(hwndSetFocus), MAKELPARAM((fNext), 0))
#define HANDLE_WM_PARENTNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_PARENTNOTIFY(hwnd, msg, hwndChild, idChild, fn) \
    (void)(fn)((hwnd), WM_PARENTNOTIFY, (WPARAM)(UINT)(msg), MAKELPARAM((UINT)(HWND)(hwndChild), (UINT)(idChild)))
#define HANDLE_WM_ENTERIDLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam)), 0L)
#define FORWARD_WM_ENTERIDLE(hwnd, source, hwndSource, fn) \
    (void)(fn)((hwnd), WM_ENTERIDLE, (WPARAM)(UINT)(source), MAKELPARAM((UINT)(HWND)(hwndSource), 0))
#define HANDLE_WM_GETDLGCODE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd, (MSG FAR*)(lParam))
#define FORWARD_WM_GETDLGCODE(hwnd, lpmsg, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_GETDLGCODE, (SELECTOROF(lpmsg) ? lpmsg->wParam : 0), (LPARAM)(lpmsg))
#define HANDLE_WM_CTLCOLOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)LOWORD(lParam), (int)(HIWORD(lParam)))
#define FORWARD_WM_CTLCOLOR(hwnd, hdc, hwndChild, type, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLOR, (WPARAM)(HDC)(hdc), MAKELPARAM((UINT)(HWND)(hwndChild), (UINT)(int)(type)))
#define HANDLE_WM_SETFONT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HFONT)(wParam), (BOOL)LOWORD(lParam)), 0L)
#define FORWARD_WM_SETFONT(hwnd, hfont, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETFONT, (WPARAM)(HFONT)(hfont), MAKELPARAM((UINT)(BOOL)(fRedraw), 0))
#define HANDLE_WM_GETFONT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HFONT)(fn)(hwnd)
#define FORWARD_WM_GETFONT(hwnd, fn) \
    (HFONT)(UINT)(DWORD)(fn)((hwnd), WM_GETFONT, 0, 0L)
#define HANDLE_WM_DRAWITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DRAWITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_DRAWITEM(hwnd, lpDrawItem, fn) \
    (void)(fn)((hwnd), WM_DRAWITEM, 0, (LPARAM)(const DRAWITEMSTRUCT FAR*)(lpDrawItem))
#define HANDLE_WM_MEASUREITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MEASUREITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_MEASUREITEM(hwnd, lpMeasureItem, fn) \
    (void)(fn)((hwnd), WM_MEASUREITEM, 0, (LPARAM)(MEASUREITEMSTRUCT FAR*)(lpMeasureItem))
#define HANDLE_WM_COMPAREITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (const COMPAREITEMSTRUCT FAR*)(lParam))
#define FORWARD_WM_COMPAREITEM(hwnd, lpCompareItem, fn) \
    (int)(DWORD)(fn)((hwnd), WM_COMPAREITEM, 0, (LPARAM)(const COMPAREITEMSTRUCT FAR*)(lpCompareItem))
#define HANDLE_WM_VKEYTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_VKEYTOITEM(hwnd, vk, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_VKEYTOITEM, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(hwndListBox), (UINT)(iCaret)))
#define HANDLE_WM_CHARTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_CHARTOITEM(hwnd, ch, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_CHARTOITEM, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(hwndListBox), (UINT)(iCaret)))
#define HANDLE_WM_QUEUESYNC(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_QUEUESYNC(hwnd, fn) \
    (void)(fn)((hwnd), WM_QUEUESYNC, 0, 0L)
#define HANDLE_WM_COMMNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), LOWORD(lParam)), 0L)
#define FORWARD_WM_COMMNOTIFY(hwnd, cid, flags, fn) \
    (void)(fn)((hwnd), WM_COMMNOTIFY, (WPARAM)(cid), MAKELPARAM((flags), 0))
#define Static_SetIcon(hwndCtl, hIcon)          ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_SETICON, (WPARAM)(HICON)(hIcon), 0L))
#define Static_GetIcon(hwndCtl, hIcon)          ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_GETICON, 0, 0L))
#define Button_GetCheck(hwndCtl)            ((int)(DWORD)SendMessage((hwndCtl), BM_GETCHECK, 0, 0L))
#define Button_SetCheck(hwndCtl, check)     ((void)SendMessage((hwndCtl), BM_SETCHECK, (WPARAM)(int)(check), 0L))
#define Button_GetState(hwndCtl)            ((int)(DWORD)SendMessage((hwndCtl), BM_GETSTATE, 0, 0L))
#define Button_SetState(hwndCtl, state)     ((UINT)(DWORD)SendMessage((hwndCtl), BM_SETSTATE, (WPARAM)(int)(state), 0L))
#define Button_SetStyle(hwndCtl, style, fRedraw) ((void)SendMessage((hwndCtl), BM_SETSTYLE, (WPARAM)LOWORD(style), MAKELPARAM(((fRedraw) ? TRUE : FALSE), 0)))
#define Edit_LimitText(hwndCtl, cchMax)         ((void)SendMessage((hwndCtl), EM_LIMITTEXT, (WPARAM)(cchMax), 0L))
#define Edit_GetLineCount(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINECOUNT, 0, 0L))
#define Edit_GetLine(hwndCtl, line, lpch, cchMax) ((*((int FAR*)(lpch)) = (cchMax)), ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINE, (WPARAM)(int)(line), (LPARAM)(LPSTR)(lpch))))
#define Edit_GetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_GETRECT, 0, (LPARAM)(RECT FAR*)(lprc)))
#define Edit_SetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_SETRECT, 0, (LPARAM)(const RECT FAR*)(lprc)))
#define Edit_SetRectNoPaint(hwndCtl, lprc)      ((void)SendMessage((hwndCtl), EM_SETRECTNP, 0, (LPARAM)(const RECT FAR*)(lprc)))
#define Edit_GetSel(hwndCtl)                    ((DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L))
#define Edit_SetSel(hwndCtl, ichStart, ichEnd)  ((void)SendMessage((hwndCtl), EM_SETSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define Edit_ReplaceSel(hwndCtl, lpszReplace)   ((void)SendMessage((hwndCtl), EM_REPLACESEL, 0, (LPARAM)(LPCSTR)(lpszReplace)))
#define Edit_GetModify(hwndCtl)                 ((BOOL)(DWORD)SendMessage((hwndCtl), EM_GETMODIFY, 0, 0L))
#define Edit_SetModify(hwndCtl, fModified)      ((void)SendMessage((hwndCtl), EM_SETMODIFY, (WPARAM)(UINT)(fModified), 0L))
#define Edit_LineFromChar(hwndCtl, ich)         ((int)(DWORD)SendMessage((hwndCtl), EM_LINEFROMCHAR, (WPARAM)(int)(ich), 0L))
#define Edit_LineIndex(hwndCtl, line)           ((int)(DWORD)SendMessage((hwndCtl), EM_LINEINDEX, (WPARAM)(int)(line), 0L))
#define Edit_LineLength(hwndCtl, line)          ((int)(DWORD)SendMessage((hwndCtl), EM_LINELENGTH, (WPARAM)(int)(line), 0L))
#define Edit_Scroll(hwndCtl, dv, dh)            ((void)SendMessage((hwndCtl), EM_LINESCROLL, 0, MAKELPARAM((dv), (dh))))
#define Edit_CanUndo(hwndCtl)                   ((BOOL)(DWORD)SendMessage((hwndCtl), EM_CANUNDO, 0, 0L))
#define Edit_Undo(hwndCtl)                      ((BOOL)(DWORD)SendMessage((hwndCtl), EM_UNDO, 0, 0L))
#define Edit_EmptyUndoBuffer(hwndCtl)           ((void)SendMessage((hwndCtl), EM_EMPTYUNDOBUFFER, 0, 0L))
#define Edit_SetPasswordChar(hwndCtl, ch)       ((void)SendMessage((hwndCtl), EM_SETPASSWORDCHAR, (WPARAM)(UINT)(ch), 0L))
#define Edit_SetTabStops(hwndCtl, cTabs, lpTabs) ((void)SendMessage((hwndCtl), EM_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(const int FAR*)(lpTabs)))
#define Edit_FmtLines(hwndCtl, fAddEOL)         ((BOOL)(DWORD)SendMessage((hwndCtl), EM_FMTLINES, (WPARAM)(BOOL)(fAddEOL), 0L))
#define Edit_GetHandle(hwndCtl)                 ((HLOCAL)(UINT)(DWORD)SendMessage((hwndCtl), EM_GETHANDLE, 0, 0L))
#define Edit_SetHandle(hwndCtl, h)              ((void)SendMessage((hwndCtl), EM_SETHANDLE, (WPARAM)(UINT)(HLOCAL)(h), 0L))
#define Edit_GetFirstVisibleLine(hwndCtl)       ((int)(DWORD)SendMessage((hwndCtl), EM_GETFIRSTVISIBLELINE, 0, 0L))
#define Edit_SetReadOnly(hwndCtl, fReadOnly)    ((BOOL)(DWORD)SendMessage((hwndCtl), EM_SETREADONLY, (WPARAM)(BOOL)(fReadOnly), 0L))
#define Edit_GetPasswordChar(hwndCtl)           ((char)(DWORD)SendMessage((hwndCtl), EM_GETPASSWORDCHAR, 0, 0L))
#define Edit_SetWordBreakProc(hwndCtl, lpfnWordBreak) ((void)SendMessage((hwndCtl), EM_SETWORDBREAKPROC, 0, (LPARAM)(EDITWORDBREAKPROC)(lpfnWordBreak)))
#define Edit_GetWordBreakProc(hwndCtl)          ((EDITWORDBREAKPROC)SendMessage((hwndCtl), EM_GETWORDBREAKPROC, 0, 0L))
#define ListBox_GetCount(hwndCtl)                   ((int)(DWORD)SendMessage((hwndCtl), LB_GETCOUNT, 0, 0L))
#define ListBox_ResetContent(hwndCtl)               ((BOOL)(DWORD)SendMessage((hwndCtl), LB_RESETCONTENT, 0, 0L))
#define ListBox_AddString(hwndCtl, lpsz)            ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0, (LPARAM)(LPCSTR)(lpsz)))
#define ListBox_InsertString(hwndCtl, index, lpsz)  ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpsz)))
#define ListBox_AddItemData(hwndCtl, data)          ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0, (LPARAM)(data)))
#define ListBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_GetTextLen(hwndCtl, index)          ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXTLEN, (WPARAM)(int)(index), 0L))
#define ListBox_GetText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXT, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpszBuffer)))
#define ListBox_GetItemData(hwndCtl, index)         ((LRESULT)(DWORD)SendMessage((hwndCtl), LB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ListBox_SetItemData(hwndCtl, index, data)   ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_FindString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_FindItemData(hwndCtl, indexStart, data) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_SetSel(hwndCtl, fSelect, index)     ((int)(DWORD)SendMessage((hwndCtl), LB_SETSEL, (WPARAM)(BOOL)(fSelect), MAKELPARAM((index), 0)))
#define ListBox_SelItemRange(hwndCtl, fSelect, first, last)    ((int)(DWORD)SendMessage((hwndCtl), LB_SELITEMRANGE, (WPARAM)(BOOL)(fSelect), MAKELPARAM((first), (last))))
#define ListBox_GetCurSel(hwndCtl)                  ((int)(DWORD)SendMessage((hwndCtl), LB_GETCURSEL, 0, 0L))
#define ListBox_SetCurSel(hwndCtl, index)           ((int)(DWORD)SendMessage((hwndCtl), LB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ListBox_SelectString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_SelectItemData(hwndCtl, indexStart, data)   ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_GetSel(hwndCtl, index)              ((int)(DWORD)SendMessage((hwndCtl), LB_GETSEL, (WPARAM)(int)(index), 0L))
#define ListBox_GetSelCount(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELCOUNT, 0, 0L))
#define ListBox_GetTopIndex(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), LB_GETTOPINDEX, 0, 0L))
#define ListBox_GetSelItems(hwndCtl, cItems, lpItems) ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELITEMS, (WPARAM)(int)(cItems), (LPARAM)(int FAR*)(lpItems)))
#define ListBox_SetTopIndex(hwndCtl, indexTop)      ((int)(DWORD)SendMessage((hwndCtl), LB_SETTOPINDEX, (WPARAM)(int)(indexTop), 0L))
#define ListBox_SetColumnWidth(hwndCtl, cxColumn)   ((void)SendMessage((hwndCtl), LB_SETCOLUMNWIDTH, (WPARAM)(int)(cxColumn), 0L))
#define ListBox_GetHorizontalExtent(hwndCtl)        ((int)(DWORD)SendMessage((hwndCtl), LB_GETHORIZONTALEXTENT, 0, 0L))
#define ListBox_SetHorizontalExtent(hwndCtl, cxExtent)     ((void)SendMessage((hwndCtl), LB_SETHORIZONTALEXTENT, (WPARAM)(int)(cxExtent), 0L))
#define ListBox_SetTabStops(hwndCtl, cTabs, lpTabs) ((BOOL)(DWORD)SendMessage((hwndCtl), LB_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(int FAR*)(lpTabs)))
#define ListBox_GetItemRect(hwndCtl, index, lprc)   ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMRECT, (WPARAM)(int)(index), (LPARAM)(RECT FAR*)(lprc)))
#define ListBox_SetCaretIndex(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), LB_SETCARETINDEX, (WPARAM)(int)(index), 0L))
#define ListBox_GetCaretIndex(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), LB_GETCARETINDEX, 0, 0L))
#define ListBox_SetAnchorIndex(hwndCtl, index)      ((void)SendMessage((hwndCtl), LB_SETANCHORINDEX, (WPARAM)(int)(index), 0L))
#define ListBox_GetAnchorIndex(hwndCtl)             ((int)(DWORD)SendMessage((hwndCtl), LB_GETANCHORINDEX, 0, 0L))
#define ListBox_FindStringExact(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_SetItemHeight(hwndCtl, index, cy)   ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMHEIGHT, (WPARAM)(int)(index), MAKELPARAM((cy), 0)))
#define ListBox_GetItemHeight(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMHEIGHT, (WPARAM)(int)(index), 0L))
#define ListBox_Dir(hwndCtl, attrs, lpszFileSpec)   ((int)(DWORD)SendMessage((hwndCtl), LB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCSTR)(lpszFileSpec)))
#define ComboBox_Enable(hwndCtl, fEnable)       EnableWindow((hwndCtl), (fEnable))
#define ComboBox_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))
#define ComboBox_GetTextLength(hwndCtl)         GetWindowTextLength(hwndCtl)
#define ComboBox_SetText(hwndCtl, lpsz)         SetWindowText((hwndCtl), (lpsz))
#define ComboBox_LimitText(hwndCtl, cchLimit)   ((int)(DWORD)SendMessage((hwndCtl), CB_LIMITTEXT, (WPARAM)(int)(cchLimit), 0L))
#define ComboBox_GetEditSel(hwndCtl)            ((DWORD)SendMessage((hwndCtl), CB_GETEDITSEL, 0, 0L))
#define ComboBox_SetEditSel(hwndCtl, ichStart, ichEnd) ((int)(DWORD)SendMessage((hwndCtl), CB_SETEDITSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define ComboBox_GetCount(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), CB_GETCOUNT, 0, 0L))
#define ComboBox_ResetContent(hwndCtl)          ((int)(DWORD)SendMessage((hwndCtl), CB_RESETCONTENT, 0, 0L))
#define ComboBox_AddString(hwndCtl, lpsz)       ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_InsertString(hwndCtl, index, lpsz) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_AddItemData(hwndCtl, data)     ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(data)))
#define ComboBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_GetLBTextLen(hwndCtl, index)           ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXTLEN, (WPARAM)(int)(index), 0L))
#define ComboBox_GetLBText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXT, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpszBuffer)))
#define ComboBox_GetItemData(hwndCtl, index)        ((LRESULT)(DWORD)SendMessage((hwndCtl), CB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ComboBox_SetItemData(hwndCtl, index, data)  ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_FindString(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ComboBox_FindItemData(hwndCtl, indexStart, data)    ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_GetCurSel(hwndCtl)                 ((int)(DWORD)SendMessage((hwndCtl), CB_GETCURSEL, 0, 0L))
#define ComboBox_SetCurSel(hwndCtl, index)          ((int)(DWORD)SendMessage((hwndCtl), CB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ComboBox_SelectString(hwndCtl, indexStart, lpszSelect)  ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszSelect)))
#define ComboBox_SelectItemData(hwndCtl, indexStart, data)      ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_Dir(hwndCtl, attrs, lpszFileSpec)  ((int)(DWORD)SendMessage((hwndCtl), CB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCSTR)(lpszFileSpec)))
#define ComboBox_ShowDropdown(hwndCtl, fShow)       ((BOOL)(DWORD)SendMessage((hwndCtl), CB_SHOWDROPDOWN, (WPARAM)(BOOL)(fShow), 0L))
#define ComboBox_FindStringExact(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ComboBox_GetDroppedState(hwndCtl)           ((BOOL)(DWORD)SendMessage((hwndCtl), CB_GETDROPPEDSTATE, 0, 0L))
#define ComboBox_GetDroppedControlRect(hwndCtl, lprc) ((void)SendMessage((hwndCtl), CB_GETDROPPEDCONTROLRECT, 0, (LPARAM)(RECT FAR*)(lprc)))
#define ComboBox_GetItemHeight(hwndCtl)             ((int)(DWORD)SendMessage((hwndCtl), CB_GETITEMHEIGHT, 0, 0L))
#define ComboBox_SetItemHeight(hwndCtl, cyItem)     ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMHEIGHT, (WPARAM)(int)(index), 0L))
#define ComboBox_GetExtendedUI(hwndCtl)             ((UINT)(DWORD)SendMessage((hwndCtl), CB_GETEXTENDEDUI, 0, 0L))
#define ComboBox_SetExtendedUI(hwndCtl, flags)      ((int)(DWORD)SendMessage((hwndCtl), CB_SETEXTENDEDUI, (WPARAM)(UINT)(flags), 0L))
#define GET_WM_ACTIVATE_HWND(wp, lp)            ((HWND)LOWORD(lp))
#define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)      \
        (WPARAM)(s), (LPARAM)MAKELONG(hwnd, fmin)
#define GET_WM_CHARTOITEM_HWND(wp, lp)          LOWORD(lp)
#define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd)    \
        (WPARAM)ch, (LPARAM)MAKELONG(hwnd, pos)
#define GET_WM_COMMAND_HWND(wp, lp)             (HWND)(LOWORD(lp))
#define GET_WM_COMMAND_MPS(id, hwnd, cmd)    \
        (WPARAM)id, MAKELONG(hwnd, cmd)
#define GET_WM_CTLCOLOR_HWND(wp, lp, msg)       (HWND)(LOWORD(lp))
#define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type) \
        (WPARAM)(hdc), (LPARAM)MAKELONG(hwnd, type)
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (wp)
#define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
#define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
        (WPARAM)(hwndA), 0
#define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)       (HWND)LOWORD(lp)
#define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd) \
        (WPARAM)msg, (LPARAM)MAKELONG(hwnd, id)
#define GET_WM_VKEYTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
#define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) \
        (WPARAM)code, (LPARAM)MAKELONG(hwnd, item)
#define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)       (HWND)LOWORD(lp)
#define GET_WM_HSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
#define GET_WM_HSCROLL_MPS(code, pos, hwnd)    \
        (WPARAM)code, (LPARAM)MAKELONG(pos, hwnd)
#define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
#define GET_WM_VSCROLL_MPS(code, pos, hwnd)    \
        (WPARAM)code, (LPARAM)MAKELONG(pos, hwnd)

// multimedia\media\avi\inc.16\woahack.h
#define WinOldApFlag(hwnd, flag) ((UINT)GetPropEx(hwnd, MAKEINTATOM(atmWinOldAp)) & woaprop##flag)

// multimedia\media\avi\mciwnd.16\mciwnd.c
    #define GetCurrentInstance()    SELECTOROF(((LPVOID)&hwndParent))

// multimedia\media\avi\mciwnd.16\mciwnd.h
#define MCIWndPaletteKick(hwnd)     (BOOL)MCIWndSM(hwnd,MCIWNDM_PALETTEKICK,0,0)
#define MCIWndGetPalette(hwnd)      (HPALETTE)MCIWndSM(hwnd, MCIWNDM_GETPALETTE, 0, 0)
#define MCIWndSetPalette(hwnd, hpal) (LONG)MCIWndSM(hwnd, MCIWNDM_SETPALETTE, (WPARAM)(HPALETTE)(hpal), 0)
#define MCIWNDM_NOTIFYMODE      (WM_USER + 200)  // wp = hwnd, lp = mode
#define MCIWNDM_NOTIFYPOS	(WM_USER + 201)  // wp = hwnd, lp = pos
#define MCIWNDM_NOTIFYSIZE	(WM_USER + 202)  // wp = hwnd
#define MCIWNDM_NOTIFYMEDIA     (WM_USER + 203)  // wp = hwnd, lp = fn
#define MCIWNDM_NOTIFYERROR     (WM_USER + 205)  // wp = hwnd, lp = error

// multimedia\media\avi\mciwnd.16\mciwndi.h
#define TestWS(hwnd,f)  (GetWS(hwnd) & f)
#define SetWS(hwnd, f)  ((PutWS(hwnd, GetWS(hwnd) | f) & (f)) != (f))
#define ClrWS(hwnd, f)  ((PutWS(hwnd, GetWS(hwnd) & ~(f)) & (f)) != 0)

// multimedia\media\avi\mciwnd.16\movplay.c
#define mdiActiveDoc() \
    (HWND)SendMessage(hwndMdi,WM_MDIGETACTIVE,0,0L)
#define ISCHECKED() (BOOL)(GetMenuState(GetMenu(hwnd), wParam, 0) & MF_CHECKED)

// multimedia\media\avi\mciwnd.16\tracki.h
#define TrackBarCreate(hwnd)    SetWindowWord(hwnd,GWW_TRACKMEM,(WORD)LocalAlloc(LPTR,sizeof(TrackBar)))

// multimedia\media\avi\mciwnd\mciwnd.c
    #define GetCurrentInstance()    SELECTOROF(((LPVOID)&hwndParent))

// multimedia\media\avi\mciwnd\mciwnd.h
#define MCIWndPaletteKick(hwnd)     (BOOL)MCIWndSM(hwnd,MCIWNDM_PALETTEKICK,0,0)
#define MCIWndGetPalette(hwnd)      (HPALETTE)MCIWndSM(hwnd, MCIWNDM_GETPALETTE, 0, 0)
#define MCIWndSetPalette(hwnd, hpal) (LONG)MCIWndSM(hwnd, MCIWNDM_SETPALETTE, (WPARAM)(HPALETTE)(hpal), 0)
#define MCIWNDM_NOTIFYMODE      (WM_USER + 200)  // wp = hwnd, lp = mode
#define MCIWNDM_NOTIFYPOS	(WM_USER + 201)  // wp = hwnd, lp = pos
#define MCIWNDM_NOTIFYSIZE	(WM_USER + 202)  // wp = hwnd
#define MCIWNDM_NOTIFYMEDIA     (WM_USER + 203)  // wp = hwnd, lp = fn
#define MCIWNDM_NOTIFYERROR     (WM_USER + 205)  // wp = hwnd, lp = error

// multimedia\media\avi\mciwnd\mciwndi.h
#define TestWS(hwnd,f)  (GetWS(hwnd) & f)
#define SetWS(hwnd, f)  ((PutWS(hwnd, GetWS(hwnd) | f) & (f)) != (f))
#define ClrWS(hwnd, f)  ((PutWS(hwnd, GetWS(hwnd) & ~(f)) & (f)) != 0)

// multimedia\media\avi\mciwnd\tracki.h
#define TrackBarCreate(hwnd)    SetWindowLong(hwnd,GWW_TRACKMEM,(LONG)LocalAlloc(LPTR,sizeof(TrackBar)))
#define TrackBarCreate(hwnd)    SetWindowWord(hwnd,GWW_TRACKMEM,(WORD)LocalAlloc(LPTR,sizeof(TrackBar)))

// multimedia\media\avi\vidcap32\arrow.c
#define SENDSCROLL(hwnd, msg, a, b, h)           \
        SendMessage(hwnd, msg, (UINT)MAKELONG(a,b), (LONG_PTR)(h))

// multimedia\media\cdplayer\cdplayer.h
#define HANDLE_WM_MENUSELECT(hwnd, wParam, lParam, fn)                  \
    ((fn)( (hwnd), (HMENU)(lParam),                                     \
           (UINT)LOWORD(wParam), NULL, (UINT)HIWORD(wParam)), 0L)

// multimedia\media\deluxe2\cdplay\cdplayer.h
#define HANDLE_WM_MENUSELECT(hwnd, wParam, lParam, fn)                  \
    ((fn)( (hwnd), (HMENU)(lParam),                                     \
           (UINT)LOWORD(wParam), NULL, (UINT)HIWORD(wParam)), 0L)

// multimedia\media\deluxecd\cdplay\cdplayer.h
#define HANDLE_WM_MENUSELECT(hwnd, wParam, lParam, fn)                  \
    ((fn)( (hwnd), (HMENU)(lParam),                                     \
           (UINT)LOWORD(wParam), NULL, (UINT)HIWORD(wParam)), 0L)

// multimedia\media\dplayx\misc\dxvalid.h
#define VALID_HWND_PTR( ptr ) \
	(!IsBadWritePtr( (LPVOID) ptr, sizeof( HWND )) )

// multimedia\media\inc\mmcntrls.h
#define HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn) \
    (fn)((hwnd), (int)(wParam), (NMHDR FAR*)(lParam))
#define FORWARD_WM_NOTIFY(hwnd, idFrom, pnmhdr, fn) \
    (void)(fn)((hwnd), WM_NOTIFY, (WPARAM)(int)(id), (LPARAM)(NMHDR FAR*)(pnmhdr))

// multimedia\media\inc\win32.h
    #define GET_WM_ACTIVATE_HWND(wp, lp)                (HWND)LOWORD(lp)
    #define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)   \
	    (WPARAM)(s), MAKELONG(hwnd, fmin)
    #define GET_WM_CHARTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
    #define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd) \
	    (WPARAM)(ch), MAKELONG(hwnd, pos)
    #define GET_WM_COMMAND_HWND(wp, lp)                 (HWND)LOWORD(lp)
    #define GET_WM_COMMAND_MPS(id, hwnd, cmd)    \
	    (WPARAM)(id), MAKELONG(hwnd, cmd)
    #define GET_WM_CTLCOLOR_HWND(wp, lp, msg)           (HWND)LOWORD(lp)
    #define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type) \
	    (WPARAM)(hdc), MAKELONG(hwnd, type)
    #define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
    #define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
    #define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
    #define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
	    (WPARAM)(hwndA), 0
    #define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)       (HWND)LOWORD(lp)
    #define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd) \
	    (WPARAM)(msg), MAKELONG(hwnd, id)
    #define GET_WM_VKEYTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
    #define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) \
	    (WPARAM)(code), MAKELONG(hwnd, item)
    #define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)       (HWND)LOWORD(lp)
    #define GET_WM_HSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
    #define GET_WM_HSCROLL_MPS(code, pos, hwnd)    \
	    (WPARAM)(code), MAKELONG(pos, hwnd)
    #define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
    #define GET_WM_VSCROLL_MPS(code, pos, hwnd)    \
	    (WPARAM)(code), MAKELONG(pos, hwnd)

// multimedia\media\mcivisca\mcivisca\appport.h
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)    \
        ((DWORD)SendMessage((hwndCtl), EM_GETSEL, (WPARAM)pnS, (LPARAM)pnE))
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)                        \
    {                                                               \
        DWORD   dw;                                                 \
        dw = (DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L);       \
        *pnE = (int)HIWORD(dw);                                     \
        *pnS = (int)LOWORD(dw);                                     \
    }
    #define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)LOWORD(lp)
    #define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)      (WPARAM)(s), MAKELONG(hwnd, fmin)
    #define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd)    (WPARAM)(ch), MAKELONG(hwnd, pos)
    #define GET_WM_COMMAND_HWND(wp, lp)             (HWND)LOWORD(lp)
    #define GET_WM_COMMAND_MPS(id, hwnd, cmd)       (WPARAM)(id), MAKELONG(hwnd, cmd)
    #define GET_WM_CTLCOLOR_HWND(wp, lp, msg)       (HWND)LOWORD(lp)
    #define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type)    (WPARAM)(hdc), MAKELONG(hwnd, type)
    #define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
    #define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
    #define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
    #define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA) (WPARAM)(hwndA), 0
    #define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd)  (WPARAM)(msg), MAKELONG(hwnd, id)
    #define GET_WM_VKEYTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) (WPARAM)(code), MAKELONG(hwnd, item)
    #define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_HSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_HSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)
    #define GET_WM_VSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_VSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)

// multimedia\media\mixerapp\volumei.h
#define HANDLE_WM_XSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(lParam), (UINT)(LOWORD(wParam)),  (int)(short)HIWORD(wParam)), 0L)
#define HANDLE_MYWM_TIMER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd)))
#define HANDLE_WM_IDEVICECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), wParam, lParam))
#define HANDLE_MYWM_WAKEUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), wParam))

// multimedia\media\mmcaps2k\appport.h
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)    \
	((DWORD)SendMessage((hwndCtl), EM_GETSEL, (WPARAM)pnS, (LPARAM)pnE))
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)                        \
    {                                                               \
	DWORD   dw;                                                 \
	dw = (DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L);       \
	*pnE = (int)HIWORD(dw);                                     \
	*pnS = (int)LOWORD(dw);                                     \
    }
    #define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)LOWORD(lp)
    #define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)      (WPARAM)(s), MAKELONG(hwnd, fmin)
    #define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd)    (WPARAM)(ch), MAKELONG(hwnd, pos)
    #define GET_WM_COMMAND_HWND(wp, lp)             (HWND)LOWORD(lp)
    #define GET_WM_COMMAND_MPS(id, hwnd, cmd)       (WPARAM)(id), MAKELONG(hwnd, cmd)
    #define GET_WM_CTLCOLOR_HWND(wp, lp, msg)       (HWND)LOWORD(lp)
    #define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type)    (WPARAM)(hdc), MAKELONG(hwnd, type)
    #define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
    #define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
    #define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
    #define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA) (WPARAM)(hwndA), 0
    #define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd)  (WPARAM)(msg), MAKELONG(hwnd, id)
    #define GET_WM_VKEYTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) (WPARAM)(code), MAKELONG(hwnd, item)
    #define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_HSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_HSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)
    #define GET_WM_VSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_VSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)

// multimedia\media\mplayer2\arrow.c
#define SENDSCROLL(hwnd, msg, a, b, h)           \
        SendMessage(hwnd, msg, (UINT_PTR)MAKELONG(a,b), (LONG_PTR)(h))

// multimedia\media\mplayer2\doverb.c
#define TestWS(hwnd,f)  (GetWS(hwnd) & f)
#define SetWS(hwnd, f)  PutWS(hwnd, GetWS(hwnd) | f)
#define ClrWS(hwnd, f)  PutWS(hwnd, GetWS(hwnd) & ~(f))

// multimedia\media\mplayer2\framebox.c
#define HILIGHTEDITBOX(hwnd) \
        SendMessage(GETEDITBOXWND(hwnd), EM_SETSEL, (WPARAM)0, (LPARAM)(UINT)-1);

// multimedia\media\mplayer2\mplayer.c
#define HANDLE_MPLAYER_WM_MENUSELECT(hwnd, message, fn)                  \
    case (message): if(lParam)  ((fn)((hwnd), (HMENU)(lParam), (UINT)LOWORD(wParam), 0L, 0L )); break;

// multimedia\media\mplayer2\mplayer.h
#define SetDlgFocus(hwnd) SendMessage(ghwndApp, WM_NEXTDLGCTL, (WPARAM)(hwnd), 1L)
#define TestWS(hwnd,f)  (GetWS(hwnd) & f)
#define SetWS(hwnd, f)  ((PutWS(hwnd, GetWS(hwnd) | f) & (f)) != (f))
#define ClrWS(hwnd, f)  ((PutWS(hwnd, GetWS(hwnd) & ~(f)) & (f)) != 0)
#define SetWSEx(hwnd, f) ((PutWSEx(hwnd, GetWSEx(hwnd) | f) & (f)) != (f))
#define ClrWSEx(hwnd, f) ((PutWSEx(hwnd, GetWSEx(hwnd) & ~(f)) & (f)) != 0)

// multimedia\media\mplayer2\ole1.c
#define TestWS(hwnd,f)  (GetWS(hwnd) & f)
#define SetWS(hwnd, f)  PutWS(hwnd, GetWS(hwnd) | f)
#define ClrWS(hwnd, f)  PutWS(hwnd, GetWS(hwnd) & ~(f))

// multimedia\media\mplayer2\riffdisp.c
#define GetHInstance()  (HINSTANCE)(SELECTOROF((LPVOID)&hwndPreview))

// multimedia\media\mplayer2\tracki.h
#define CREATETRACKBAR(hwnd) SetWindowLongPtr( hwnd                                 \
                                             , GWW_TRACKMEM                         \
                                             , AllocMem(sizeof(TrackBar))           \
                                             )

// multimedia\media\msacm\msacm\acmi.h
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)    \
	((DWORD)SendMessage((hwndCtl), EM_GETSEL, (WPARAM)pnS, (LPARAM)pnE))
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)                        \
    {                                                               \
	DWORD   dw;                                                 \
	dw = (DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L);       \
	*pnE = (int)HIWORD(dw);                                     \
	*pnS = (int)LOWORD(dw);                                     \
    }
    #define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)LOWORD(lp)
    #define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)      (WPARAM)(s), MAKELONG(hwnd, fmin)
    #define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd)    (WPARAM)(ch), MAKELONG(hwnd, pos)
    #define GET_WM_COMMAND_HWND(wp, lp)             (HWND)LOWORD(lp)
    #define GET_WM_COMMAND_MPS(id, hwnd, cmd)       (WPARAM)(id), MAKELONG(hwnd, cmd)
    #define GET_WM_CTLCOLOR_HWND(wp, lp, msg)       (HWND)LOWORD(lp)
    #define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type)    (WPARAM)(hdc), MAKELONG(hwnd, type)
    #define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
    #define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
    #define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
    #define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA) (WPARAM)(hwndA), 0
    #define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd)  (WPARAM)(msg), MAKELONG(hwnd, id)
    #define GET_WM_VKEYTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) (WPARAM)(code), MAKELONG(hwnd, item)
    #define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_HSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_HSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)
    #define GET_WM_VSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_VSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)

// multimedia\media\msacm\msacmmap\msacmmap.h
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)    \
        ((DWORD)SendMessage((hwndCtl), EM_GETSEL, (WPARAM)pnS, (LPARAM)pnE))
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)                        \
    {                                                               \
        DWORD   dw;                                                 \
        dw = (DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L);       \
        *pnE = (int)HIWORD(dw);                                     \
        *pnS = (int)LOWORD(dw);                                     \
    }
    #define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)LOWORD(lp)
    #define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)      (WPARAM)(s), MAKELONG(hwnd, fmin)
    #define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd)    (WPARAM)(ch), MAKELONG(hwnd, pos)
    #define GET_WM_COMMAND_HWND(wp, lp)             (HWND)LOWORD(lp)
    #define GET_WM_COMMAND_MPS(id, hwnd, cmd)       (WPARAM)(id), MAKELONG(hwnd, cmd)
    #define GET_WM_CTLCOLOR_HWND(wp, lp, msg)       (HWND)LOWORD(lp)
    #define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type)    (WPARAM)(hdc), MAKELONG(hwnd, type)
    #define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
    #define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
    #define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
    #define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA) (WPARAM)(hwndA), 0
    #define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd)  (WPARAM)(msg), MAKELONG(hwnd, id)
    #define GET_WM_VKEYTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) (WPARAM)(code), MAKELONG(hwnd, item)
    #define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_HSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_HSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)
    #define GET_WM_VSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_VSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)

// multimedia\media\samples\acmapp\aafile.c
#define BeginConvert(hwnd, paacd)   PostMessage(hwnd, WM_CONVERT_BEGIN, 0, (LPARAM)(UINT)paacd)
#define EndConvert(hwnd, f, paacd)  PostMessage(hwnd, WM_CONVERT_END, (WPARAM)f, (LPARAM)(UINT)paacd)

// multimedia\media\samples\acmapp\appport.h
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)    \
        ((DWORD)SendMessage((hwndCtl), EM_GETSEL, (WPARAM)pnS, (LPARAM)pnE))
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)                        \
    {                                                               \
        DWORD   dw;                                                 \
        dw = (DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L);       \
        *pnE = (int)HIWORD(dw);                                     \
        *pnS = (int)LOWORD(dw);                                     \
    }
    #define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)LOWORD(lp)
    #define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)      (WPARAM)(s), MAKELONG(hwnd, fmin)
    #define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd)    (WPARAM)(ch), MAKELONG(hwnd, pos)
    #define GET_WM_COMMAND_HWND(wp, lp)             (HWND)LOWORD(lp)
    #define GET_WM_COMMAND_MPS(id, hwnd, cmd)       (WPARAM)(id), MAKELONG(hwnd, cmd)
    #define GET_WM_CTLCOLOR_HWND(wp, lp, msg)       (HWND)LOWORD(lp)
    #define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type)    (WPARAM)(hdc), MAKELONG(hwnd, type)
    #define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
    #define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
    #define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
    #define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA) (WPARAM)(hwndA), 0
    #define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd)  (WPARAM)(msg), MAKELONG(hwnd, id)
    #define GET_WM_VKEYTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) (WPARAM)(code), MAKELONG(hwnd, item)
    #define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_HSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_HSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)
    #define GET_WM_VSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_VSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)

// multimedia\media\samples\mmcapsex\appport.h
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)    \
	((DWORD)SendMessage((hwndCtl), EM_GETSEL, (WPARAM)pnS, (LPARAM)pnE))
    #define Edit_GetSelEx(hwndCtl, pnS, pnE)                        \
    {                                                               \
	DWORD   dw;                                                 \
	dw = (DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L);       \
	*pnE = (int)HIWORD(dw);                                     \
	*pnS = (int)LOWORD(dw);                                     \
    }
    #define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)LOWORD(lp)
    #define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)      (WPARAM)(s), MAKELONG(hwnd, fmin)
    #define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd)    (WPARAM)(ch), MAKELONG(hwnd, pos)
    #define GET_WM_COMMAND_HWND(wp, lp)             (HWND)LOWORD(lp)
    #define GET_WM_COMMAND_MPS(id, hwnd, cmd)       (WPARAM)(id), MAKELONG(hwnd, cmd)
    #define GET_WM_CTLCOLOR_HWND(wp, lp, msg)       (HWND)LOWORD(lp)
    #define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type)    (WPARAM)(hdc), MAKELONG(hwnd, type)
    #define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
    #define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
    #define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
    #define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA) (WPARAM)(hwndA), 0
    #define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd)  (WPARAM)(msg), MAKELONG(hwnd, id)
    #define GET_WM_VKEYTOITEM_HWND(wp, lp)          (HWND)LOWORD(lp)
    #define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) (WPARAM)(code), MAKELONG(hwnd, item)
    #define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)   (HWND)LOWORD(lp)
    #define GET_WM_HSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_HSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)
    #define GET_WM_VSCROLL_HWND(wp, lp)             (HWND)HIWORD(lp)
    #define GET_WM_VSCROLL_MPS(code, pos, hwnd)     (WPARAM)(code), MAKELONG(pos, hwnd)

// multimedia\media\sndrec32\o2base\ipborder.cxx
#define SetWF(hwnd,wf)  SetWindowLongPtr(hwnd, GWL_STYLE, \
            GetWindowLongPtr(hwnd,GWL_STYLE) | (wf))
#define ClrWF(hwnd,wf)  SetWindowLongPtr(hwnd, GWL_STYLE, \
            GetWindowLongPtr(hwnd,GWL_STYLE) &~(wf))
#define TestWF(hwnd,wf) (GetWindowLongPtr(hwnd,GWL_STYLE) & (wf))

// multimedia\media\sndrec32\soundrec\soundrec.h
#define SetDlgFocus(hwnd)   SendMessage(ghwndApp, WM_NEXTDLGCTL, (WPARAM)(hwnd), 1L)

// net\atm\arp\atmarpc\aawmi.h
#define AA_PDO_TO_INTERFACE(_pDevObj)	\
			(*(PATMARP_INTERFACE *)((_pDevObj)->DeviceExtension))

// net\atm\arp\atmarps\intf.h
#define	COMP_ATM_ADDR(_a1_, _a2_)	(((_a1_)->AddressType == (_a2_)->AddressType) &&						\
									 ((_a1_)->NumberOfDigits == (_a2_)->NumberOfDigits) &&					\
									 COMP_MEM((_a1_)->Address,												\
											  (_a2_)->Address,												\
											  (_a1_)->NumberOfDigits))

// net\config\netcfg\tcpipcfg\tcpmacro.h
#define Tcp_ComboBox_SetCurSel(hwndCtl, index) ((int)(DWORD)SNDMSG((hwndCtl), CB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define Tcp_ComboBox_GetCurSel(hwndCtl)  ((int)(DWORD)SNDMSG((hwndCtl), CB_GETCURSEL, 0L, 0L))
#define Tcp_ComboBox_GetCount(hwndCtl)  ((int)(DWORD)SNDMSG((hwndCtl), CB_GETCOUNT, 0L, 0L))

// net\config\shell\folder\ishellf2.cpp
#define IsEqualSCID(a, b)   (((a).pid == (b).pid) && IsEqualIID((a).fmtid, (b).fmtid) )
#define IsEqualSCID(a, b)   (((a).pid == (b).pid) && IsEqualIID(&((a).fmtid),&((b).fmtid)))

// net\config\shell\folder\traymsgs.h
#define MYWM_NOTIFYICON         (WM_USER+1)
#define MYWM_ADDTRAYICON        (WM_USER+3)
#define MYWM_REMOVETRAYICON     (WM_USER+4)
#define MYWM_UPDATETRAYICON     (WM_USER+5)
#define MYWM_FLUSHNOOP          (WM_USER+6) // For flushing the tray messages via SendMessage()

// net\dhcp\server\server\callout.c
#define    CALLOUT_SENDPKT(P)      \
WRAPPER(PktSend, (&((P)->ReqContext.SendBuffer),\
    &((P)->ReqContext.SendMessageSize),\
    DHCP_SEND_PACKET,\
    (P)->ReqContext.EndPointIpAddress,\
    (LPVOID)(P),\
    (LPVOID)((P)->CalloutContext))\
)

// net\dhcp\server\server\callout.h
#define    CALLOUT_SENDPKT(P)      \
WRAPPER(PktSend, (&((P)->ReqContext.SendBuffer),\
    &((P)->ReqContext.SendMessageSize),\
    DHCP_SEND_PACKET,\
    (P)->ReqContext.EndPointIpAddress,\
    (LPVOID)(P),\
    (LPVOID)((P)->CalloutContext))\
)

// net\diagnostics\netdiag\nwtest.h
#define NWR_ANY_NCP(X)                  _NWRDR_CONTROL_CODE(0x400 | (X), METHOD_NEITHER, FILE_ANY_ACCESS)
#define NWR_ANY_F2_NCP(X)               _NWRDR_CONTROL_CODE(0x500 | (X), METHOD_NEITHER, FILE_ANY_ACCESS)
#define NWR_ANY_HANDLE_NCP(X)           _NWRDR_CONTROL_CODE(0x600 | (X), METHOD_NEITHER, FILE_ANY_ACCESS)
#define NWR_ANY_NDS(X)                  _NWRDR_CONTROL_CODE(0x700 | (X), METHOD_NEITHER, FILE_ANY_ACCESS)

// net\dlc\driver\llcsm.c
#define SEND_RNR_CMD( a )    SendLlcFrame( pLink, DLC_RNR_TOKEN | \
    DLC_TOKEN_COMMAND | a )
#define SEND_RR_CMD( a )     SendLlcFrame( pLink, DLC_RR_TOKEN | \
    DLC_TOKEN_COMMAND | a )

// net\homenet\alg\alg_ftp\ftpcontrol.cpp
#define TOUPPER(c)      ((c) > 'z' ? (c) : ((c) < 'a' ? (c) : (c) ^ 0x20))

// net\inc\cxport.h
#define CTEMemCmp(Src1, Src2, Len)    \
            ((RtlCompareMemory((Src1), (Src2), (Len)) == (Len)) ? 0 : 1)

// net\irda\irlap\irlapp.h
#define IRLAP_DEFAULT_WINDOWSIZE        (FRAMES_1 | FRAMES_2 | FRAMES_3 | \
                                         FRAMES_4 | FRAMES_5 | FRAMES_6 | \
                                         FRAMES_7)

// net\irda\samples\nscirda\comm.h
	#define XMIT_MODE_INTS_ENABLE	(READY_FOR_XMIT_INT_ENABLE|DATA_AVAIL_INT_ENABLE)
	#define ALL_INTS_ENABLE			(RCV_MODE_INTS_ENABLE | XMIT_MODE_INTS_ENABLE)

// net\mmc\mprsnap\iface.h
#define GET_INTERFACENODEDATA(pNode) \
						((InterfaceNodeData *) pNode->GetData(TFS_DATA_USER))

// net\mmc\snmp\snmp_cn.h
#define IDH_11705_251	16461241	// SNMP Service Configuration: "Community &Rights" (Static)
#define IDH_210_251	16449746	// SNMP Service Configuration: "Community &Rights" (Static)

// net\mmc\tfscore\ipaddr.cpp
#define IPADDR_GET_SUBSTYLE(hwnd) (GetWindowLongPtr((hwnd), sizeof(LONG_PTR) * 1))
#define IPADDR_SET_SUBSTYLE(hwnd, style) (SetWindowLongPtr((hwnd), sizeof(LONG_PTR) * 1, (style)))

// net\mmc\wins\common.h
  #define GETIP_FOURTH(x)            ((x)     & 0xff)

// net\netbeui\kdext\nbfcom.h
#define EOL (( ppchTempEol = ppchCurrentEol ), ( ppchCurrentEol = &pchEol ), ( *ppchTempEol ))

// net\rras\cm\common\inc\cmutil.h
#define OS_NT6 ((GetOSVersion() == VER_PLATFORM_WIN32_NT) && (GetOSMajorVersion() >= 6))
#define OS_NT51 ((GetOSVersion() == VER_PLATFORM_WIN32_NT) && (GetOSMajorVersion() >= 5) && (GetOSBuildNumber() > 2195))
#define OS_NT5 ((GetOSVersion() == VER_PLATFORM_WIN32_NT) && (GetOSMajorVersion() >= 5))
#define OS_NT4 ((GetOSVersion() == VER_PLATFORM_WIN32_NT) && (GetOSMajorVersion() < 5))
#define OS_W2K ((GetOSVersion() == VER_PLATFORM_WIN32_NT) && (GetOSBuildNumber() == 2195))
#define OS_W98 ((GetOSVersion() == VER_PLATFORM_WIN32_WINDOWS98) || (GetOSVersion() == VER_PLATFORM_WIN32_MILLENNIUM))

// net\rras\cm\common\source\modelessdlg.cpp
#define FLASHW_ALL          (FLASHW_CAPTION | FLASHW_TRAY)

// net\rras\common\rtutils\wt.h
#define ENTER_WAIT_API() \
      ((ENTER_WORKER_API) && (WTG.g_Initialized==0x12345678))

// net\rras\ip\nathlp\inc\rmalg.h
#define REFERENCE_ALG() \
    REFERENCE_COMPONENT(&AlgComponentReference)
#define DEREFERENCE_ALG() \
    DEREFERENCE_COMPONENT(&AlgComponentReference)

// net\rras\ip\nathlp\inc\rmdhcp.h
#define REFERENCE_DHCP() \
    REFERENCE_COMPONENT(&DhcpComponentReference)
#define DEREFERENCE_DHCP() \
    DEREFERENCE_COMPONENT(&DhcpComponentReference)

// net\rras\ip\nathlp\inc\rmdns.h
#define REFERENCE_DNS() \
    REFERENCE_COMPONENT(&DnsComponentReference)
#define DEREFERENCE_DNS() \
    DEREFERENCE_COMPONENT(&DnsComponentReference)

// net\rras\ip\nathlp\inc\rmftp.h
#define REFERENCE_FTP() \
    REFERENCE_COMPONENT(&FtpComponentReference)
#define DEREFERENCE_FTP() \
    DEREFERENCE_COMPONENT(&FtpComponentReference)

// net\rras\ip\nathlp\inc\rmh323.h
#define REFERENCE_H323() \
    REFERENCE_COMPONENT(&H323ComponentReference)
#define DEREFERENCE_H323() \
    DEREFERENCE_COMPONENT(&H323ComponentReference)

// net\rras\ip\nathlp\inc\rmnat.h
#define REFERENCE_NAT() \
    REFERENCE_COMPONENT(&NatComponentReference)
#define DEREFERENCE_NAT() \
    DEREFERENCE_COMPONENT(&NatComponentReference)

// net\rras\ip\sample\defs.h
#define IP_COMPARE(a, b)            (((a) < (b)) ? -1       \
                                                 : (((a) is (b)) ? 0 : 1))

// net\rras\ipx\sap\routerif.c
#define sapInfo (&((PSAP_IF_CONFIG)InterfaceInfo)->SapIfInfo)
#define sapFilters (&((PSAP_IF_CONFIG)InterfaceInfo)->SapIfFilters)
#define sapInfo (&((PSAP_IF_CONFIG)InterfaceInfo)->SapIfInfo)
#define sapFilters (&((PSAP_IF_CONFIG)InterfaceInfo)->SapIfFilters)
#define sapInfo (&((PSAP_IF_CONFIG)InterfaceInfo)->SapIfInfo)
#define sapFilters (&((PSAP_IF_CONFIG)InterfaceInfo)->SapIfFilters)

// net\rras\ndis\ndiswan\compress.h
#define G(x, y, z) ((x) ^ (y) ^ (z))
#define H(x, y, z) (((x) & (y)) | ((x) & (z)) | ((y) & (z)))
#define I(x, y, z) ((x) ^ (y) ^ (z))

// net\rras\ndis\ndiswan\wandefs.h
#define IsCompleteFrame(_fl) \
    ((_fl & MULTILINK_BEGIN_FRAME) && (_fl & MULTILINK_END_FRAME))

// net\rras\ndis\ndproxy\pxtapi.h
#define ALL_DISCONNECT_MODES       (LINEDISCONNECTMODE_NORMAL        | \
                                    LINEDISCONNECTMODE_UNKNOWN       | \
                                    LINEDISCONNECTMODE_REJECT        | \
                                    LINEDISCONNECTMODE_PICKUP        | \
                                    LINEDISCONNECTMODE_FORWARDED     | \
                                    LINEDISCONNECTMODE_BUSY          | \
                                    LINEDISCONNECTMODE_NOANSWER      | \
                                    LINEDISCONNECTMODE_BADADDRESS    | \
                                    LINEDISCONNECTMODE_UNREACHABLE   | \
                                    LINEDISCONNECTMODE_CONGESTION    | \
                                    LINEDISCONNECTMODE_INCOMPATIBLE  | \
                                    LINEDISCONNECTMODE_UNAVAIL       | \
                                    LINEDISCONNECTMODE_NODIALTONE)

// net\rras\ndis\raspptp\common\raspptp.h
#define TapiLineHandleToId(h)  ((h)&0x7fffffff)
#define TapiIdToLineHandle(id) ((id)|0x80000000)
#define DeviceIdToLinkHandle(id) ((id)|0x80000000)

// net\rras\netsh\if\repair.c
#define DHCP_OPT_TCPIP_INTERFACE(_name) \
    "SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Interfaces\\?\\"_name"\0"
#define DHCP_OPT_LEGACY_TCPIP_INTERFACE(_name) \
    "SYSTEM\\CurrentControlSet\\Services\\?\\Parameters\\Tcpip\\"_name"\0"
#define DHCP_OPT_NETBT_INTERFACE(_name) \
    "SYSTEM\\CurrentControlSet\\Services\\NetBT\\Parameters\\Interfaces\\Tcpip_?\\"_name"\0"
#define DHCP_OPT_NETBT_ADAPTER(_name) \
    "SYSTEM\\CurrentControlSet\\Services\\NetBT\\Adapters\\?\\"_name"\0"

// net\rras\netsh\ipx\protocols\common.h
#define IsHelpToken(pwszToken)\
    (MatchToken(pwszToken, TOKEN_HELP1)  \
    || MatchToken(pwszToken, TOKEN_HELP2) \
    || MatchToken(pwszToken, TOKEN_HELP3))

// net\rras\netsh\shell\utils.h
#define IsHelpToken(pwszToken)\
    (MatchToken(pwszToken, CMD_HELP1)  \
    || MatchToken(pwszToken, CMD_HELP2))

// net\rras\ras\inc\rasfile.h
#define RFL_ANYINACTIVE         (RFL_BLANK | RFL_COMMENT)
#define RFL_ANYACTIVE           (RFL_KEYVALUE | RFL_COMMAND)

// net\rras\ras\ppp\common\md5c.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// net\rras\ras\ui\common\uiutil\bubble.h
#define BP_SetPtr(hwnd,ptr)     (BPOPUP *)SetWindowLongPtr((hwnd), 0, (ULONG_PTR)ptr)

// net\rras\ras\ui\common\uiutil\ipaddr.c
#define SAVE_CONTROL_HANDLE(hWnd,x) (SetWindowLongPtr((hWnd), GWLP_USERDATA, (ULONG_PTR)x))

// net\rras\ras\ui\common\uiutil\tldef.h
#define TL_SetPtr(hwnd,ptr)     (TL *)SetWindowLongPtr((hwnd), 0, (ULONG_PTR)(ptr))

// net\rras\ras\ui\inc\bpopup.h
#define BubblePopup_Activate(hwnd) \
        (VOID)SendMessage((HWND)hwnd, BPM_ACTIVATE, 0, 0)
#define BubblePopup_Deactivate(hwnd) \
        (VOID)SendMessage((HWND)hwnd, BPM_DEACTIVATE, 0, 0)
#define BubblePopup_SetTimeout(hwnd, uiTimeout) \
        (VOID)SendMessage((HWND)hwnd, BPM_SETTIMEOUT, 0,(LPARAM)(UINT)uiTimeout)

// net\rras\ras\ui\inc\common.h
#define MB_WARNING      (MB_OK | MB_ICONWARNING)
#define MB_INFO         (MB_OK | MB_ICONINFORMATION)
#define MB_ERROR        (MB_OK | MB_ICONERROR)
#define MB_QUESTION     (MB_YESNO | MB_ICONQUESTION)
#define SetDlgHandle(hwnd, msg, lp)     if((msg)==WM_SETFONT) (lp)->hdlg=(hwnd);

// net\rras\ras\ui\inc\treelist.h
#define TreeList_InsertItem(hwnd, ptlis) \
        (HTLITEM)SendMessage( \
            (hwnd), TLM_INSERTITEM, 0, (LPARAM)(CONST TL_INSERTSTRUCT *)(ptlis)\
            )
#define TreeList_GetItem(hwnd, pItem) \
        (BOOL)SendMessage( \
            (hwnd), TLM_GETITEM, 0, (LPARAM)(LV_ITEM *)(pItem) \
            )
#define TreeList_SetItem(hwnd, pItem) \
        (BOOL)SendMessage( \
            (hwnd), TLM_SETITEM, 0, (LPARAM)(CONST LV_ITEM *)(pItem) \
            )
#define TreeList_GetItemCount(hwnd) \
        (UINT)SendMessage((hwnd), TLM_GETITEMCOUNT, 0, 0)
#define TreeList_GetNextItem(hwnd, hItem, flag) \
        (HTLITEM)SendMessage( \
            (hwnd), TLM_GETNEXTITEM, (WPARAM)(UINT)(flag), \
            (LPARAM)(CONST HTLITEM)(hItem) \
            )
#define TreeList_Expand(hwnd, hItem, flag) \
        (BOOL)SendMessage( \
            (hwnd), TLM_EXPAND, (WPARAM)(UINT)(flag), \
            (LPARAM)(CONST HTLITEM)(hItem) \
            )
#define TreeList_SetImageList(hwnd, himl) \
        (BOOL)SendMessage( \
            (hwnd), TLM_SETIMAGELIST, 0, (LPARAM)(CONST HIMAGELIST)(himl) \
            )
#define TreeList_GetImageList(hwnd, himl) \
        (HIMAGELIST)SendMessage((hwnd), TLM_GETIMAGELIST, 0, 0)
#define TreeList_InsertColumn(hwnd, iCol, pCol) \
        (INT)SendMessage( \
            (hwnd),  TLM_INSERTCOLUMN, (WPARAM)(INT)(iCol), \
            (LPARAM)(CONST LV_COLUMN *)(pCol) \
            )
#define TreeList_SetSelection(hwnd, hItem) \
        (BOOL)SendMessage( \
            (hwnd), TLM_SETSELECTION, 0, (LPARAM)(CONST HTLITEM)(hItem) \
            )
#define TreeList_Redraw(hwnd) \
        (BOOL)SendMessage((hwnd), TLM_REDRAW, 0, 0)
#define TreeList_IsItemExpanded(hwnd, hItem) \
        (BOOL)SendMessage( \
            (hwnd), TLM_ISITEMEXPANDED, 0, (LPARAM)(CONST HTLITEM)(hItem) \
            )
#define TreeList_GetColumnWidth(hwnd, iCol) \
        (INT)SendMessage((hwnd), TLM_GETCOLUMNWIDTH, (WPARAM)(int)(iCol), 0)
#define TreeList_SetColumnWidth(hwnd, iCol, cx) \
        (BOOL)SendMessage( \
            (hwnd), TLM_SETCOLUMNWIDTH, (WPARAM)(int)(iCol), \
            MAKELPARAM((cx), 0) \
            )

// net\rras\ras\ui\nt4\inc\bpopup.h
#define BubblePopup_Activate(hwnd) \
        (VOID)SendMessage((HWND)hwnd, BPM_ACTIVATE, 0, 0)
#define BubblePopup_Deactivate(hwnd) \
        (VOID)SendMessage((HWND)hwnd, BPM_DEACTIVATE, 0, 0)
#define BubblePopup_SetTimeout(hwnd, uiTimeout) \
        (VOID)SendMessage((HWND)hwnd, BPM_SETTIMEOUT, 0,(LPARAM)(UINT)uiTimeout)

// net\rras\ras\ui\nt4\inc\treelist.h
#define TreeList_InsertItem(hwnd, ptlis) \
        (HTLITEM)SendMessage( \
            (hwnd), TLM_INSERTITEM, 0, (LPARAM)(CONST TL_INSERTSTRUCT *)(ptlis)\
            )
#define TreeList_GetItem(hwnd, pItem) \
        (BOOL)SendMessage( \
            (hwnd), TLM_GETITEM, 0, (LPARAM)(LV_ITEM *)(pItem) \
            )
#define TreeList_SetItem(hwnd, pItem) \
        (BOOL)SendMessage( \
            (hwnd), TLM_SETITEM, 0, (LPARAM)(CONST LV_ITEM *)(pItem) \
            )
#define TreeList_GetItemCount(hwnd) \
        (UINT)SendMessage((hwnd), TLM_GETITEMCOUNT, 0, 0)
#define TreeList_GetNextItem(hwnd, hItem, flag) \
        (HTLITEM)SendMessage( \
            (hwnd), TLM_GETNEXTITEM, (WPARAM)(UINT)(flag), \
            (LPARAM)(CONST HTLITEM)(hItem) \
            )
#define TreeList_Expand(hwnd, hItem, flag) \
        (BOOL)SendMessage( \
            (hwnd), TLM_EXPAND, (WPARAM)(UINT)(flag), \
            (LPARAM)(CONST HTLITEM)(hItem) \
            )
#define TreeList_SetImageList(hwnd, himl) \
        (BOOL)SendMessage( \
            (hwnd), TLM_SETIMAGELIST, 0, (LPARAM)(CONST HIMAGELIST)(himl) \
            )
#define TreeList_GetImageList(hwnd, himl) \
        (HIMAGELIST)SendMessage((hwnd), TLM_GETIMAGELIST, 0, 0)
#define TreeList_InsertColumn(hwnd, iCol, pCol) \
        (INT)SendMessage( \
            (hwnd),  TLM_INSERTCOLUMN, (WPARAM)(INT)(iCol), \
            (LPARAM)(CONST LV_COLUMN *)(pCol) \
            )
#define TreeList_SetSelection(hwnd, hItem) \
        (BOOL)SendMessage( \
            (hwnd), TLM_SETSELECTION, 0, (LPARAM)(CONST HTLITEM)(hItem) \
            )
#define TreeList_Redraw(hwnd) \
        (BOOL)SendMessage((hwnd), TLM_REDRAW, 0, 0)
#define TreeList_IsItemExpanded(hwnd, hItem) \
        (BOOL)SendMessage( \
            (hwnd), TLM_ISITEMEXPANDED, 0, (LPARAM)(CONST HTLITEM)(hItem) \
            )
#define TreeList_GetColumnWidth(hwnd, iCol) \
        (INT)SendMessage((hwnd), TLM_GETCOLUMNWIDTH, (WPARAM)(int)(iCol), 0)
#define TreeList_SetColumnWidth(hwnd, iCol, cx) \
        (BOOL)SendMessage( \
            (hwnd), TLM_SETCOLUMNWIDTH, (WPARAM)(int)(iCol), \
            MAKELPARAM((cx), 0) \
            )

// net\rras\ras\ui\rasscrpt\mem.c
#define SortCompare(psp, pp1, i1, pp2, i2) \
    (psp->pfnCmp(pp1[i1], pp2[i2], psp->lParam))

// net\sfm\atalk\sys\arap.h
#define ATALK_CC_METHOD(_ControlCode)  ((_ControlCode) & 0x03)

// net\sfm\atalk\sys\atkutils.h
#define	AtalkFixedCompareCaseInsensitive(s1, l1, s2, l2)						\
		(((l1) == (l2)) && AtalkCompareFixedCaseInsensitive(s1, s2, l1))
#define	AtalkFixedCompareCaseSensitive(s1, l1, s2, l2)							\
			((l1 == l2) && !memcmp(s1, s2, l1))

// net\sfm\atalk\sys\zip.h
#define	ZONES_EQUAL(pZ1, pZ2)	AtalkFixedCompareCaseInsensitive(	\
									(pZ1)->zn_Zone,					\
									(pZ1)->zn_ZoneLen,				\
									(pZ2)->zn_Zone,					\
									(pZ1)->zn_ZoneLen)				\

// net\snmp\subagent\snmpevnt\evntwin\portable.h
#define GET_WM_COMMAND_HWND(wp, lp)     (HWND)(lp)
#define NOTIFYPARENT(hwnd,code) { \
                                    UINT nID; \
                                    nID = GET_WINDOW_ID(hwnd); \
                                    (::SendMessage)(::GetParent(hwnd), \
                                        WM_COMMAND, MAKEWPARAM(nID, code), \
                                        (LPARAM)hwnd); \
                                }
#define SENDCOMMAND(hwnd, cmd)  { \
                                    (::SendMessage)(hwnd, WM_COMMAND, \
                                        MAKEWPARAM(cmd, 0), (LPARAM)0); \
                                }
#define POSTCOMMAND(hwnd, cmd)  { \
                                    (::PostMessage)(hwnd, WM_COMMAND, \
                                        MAKEWPARAM(cmd, 0), (LPARAM)0); \
                                }
#define NOTIFYPARENT(hwnd,code) { \
                                    UINT nID; \
                                    nID = GET_WINDOW_ID(hwnd); \
                                    SendMessage(GetParent(hwnd), WM_COMMAND, \
                                        MAKEWPARAM(nID, code), \
                                        (LPARAM)hwnd); \
                                }
#define SENDCOMMAND(hwnd, cmd)  { \
                                    SendMessage(hwnd, WM_COMMAND, \
                                        MAKEWPARAM(cmd, 0), (LPARAM)0); \
                                }
#define POSTCOMMAND(hwnd, cmd)  { \
                                    PostMessage(hwnd, WM_COMMAND, \
                                        MAKEWPARAM(cmd, 0), (LPARAM)0); \
                                }
#define GET_WM_COMMAND_HWND(wp, lp)     (HWND)LOWORD(lp)
#define NOTIFYPARENT(hwnd,code) { \
                                    UINT nID; \
                                    nID = GET_WINDOW_ID(hwnd); \
                                    (::SendMessage)(::GetParent(hwnd), \
                                        WM_COMMAND, nID, \
                                        MAKELPARAM(hwnd, code)); \
                                }
#define SENDCOMMAND(hwnd, cmd)  { \
                                    (::SendMessage)(hwnd,WM_COMMAND,cmd,0); \
                                }
#define POSTCOMMAND(hwnd, cmd)  { \
                                    (::PostMessage)(hwnd,WM_COMMAND,cmd,0); \
                                }
#define NOTIFYPARENT(hwnd,code) { \
                                    UINT nID; \
                                    nID = GET_WINDOW_ID(hwnd); \
                                    SendMessage(GetParent(hwnd), WM_COMMAND, \
                                        nID, MAKELPARAM(hwnd, code)); \
                                }
#define SENDCOMMAND(hwnd, cmd)  { \
                                    SendMessage(hwnd, WM_COMMAND, cmd, 0); \
                                }
#define POSTCOMMAND(hwnd, cmd)  { \
                                    PostMessage(hwnd, WM_COMMAND, cmd, 0); \
                                }

// net\sockets\winsock2\util\sporder\exe\globals.h
#define ADDSTRING(x)   SendMessage (GetDlgItem (hwnd, DID_LISTCTL), LB_ADDSTRING, 0 ,(LPARAM) x)

// net\sockets\winsock2\ws2help\ws2help\precomp.h
#define ENTER_WS2HELP_API()                                         \
    (Ws2helpInitialized ? 0 : Ws2helpInitialize())

// net\tapi\rtc\phoenix\src\axctl\rtcaxctl.cpp
#define CREATE_BUTTON(m,id,ttid)                                    \
    {                                                               \
        RECT    rcButton;                                           \
                                                                    \
        rcButton.left = 0;                                          \
        rcButton.right = 0;                                         \
        rcButton.top = 0;                                           \
        rcButton.bottom = 0;                                        \
                                                                    \
        m.Create(                                                   \
            m_hWnd,                                                 \
            rcButton,                                               \
            _T(""),                                                 \
            WS_TABSTOP,                                             \
            MAKEINTRESOURCE(IDB_AV_INACTIVE),                       \
            MAKEINTRESOURCE(IDB_AV_INACTIVE_PUSH),                  \
            MAKEINTRESOURCE(IDB_AV_DISABLED),                       \
            MAKEINTRESOURCE(IDB_AV_INACTIVE_HOT),                   \
            MAKEINTRESOURCE(IDB_AV_ACTIVE),                         \
            MAKEINTRESOURCE(IDB_AV_ACTIVE_PUSH),                    \
            MAKEINTRESOURCE(IDB_AV_DISABLED),                       \
            MAKEINTRESOURCE(IDB_AV_ACTIVE_HOT),                     \
            NULL,                                                   \
            id);                                                    \
                                                                    \
        TOOLINFO    ti;                                             \
                                                                    \
        ti.cbSize = TTTOOLINFO_V1_SIZE;                             \
        ti.uFlags = TTF_IDISHWND | TTF_SUBCLASS;                    \
        ti.hwnd = m_hWnd;                                           \
        ti.uId = (UINT_PTR)(HWND)m;                                 \
        ti.hinst = _Module.GetResourceInstance();                   \
        ti.lpszText = MAKEINTRESOURCE(ttid);                        \
                                                                    \
        m_hTooltip.SendMessage(TTM_ADDTOOL, 0,                      \
                (LPARAM)(LPTOOLINFO)&ti);                           \
    }
#define CREATE_BUTTON(m,id,sid,ttid)                                \
    {                                                               \
        RECT    rcButton;                                           \
        TCHAR   szText[0x100];                                      \
                                                                    \
        rcButton.left = 0;                                          \
        rcButton.right = 0;                                         \
        rcButton.top = 0;                                           \
        rcButton.bottom = 0;                                        \
                                                                    \
        szText[0] = _T('\0');                                       \
        ::LoadString(_Module.GetResourceInstance(),sid,             \
                szText, sizeof(szText)/sizeof(szText[0]));          \
                                                                    \
        m.Create(                                                   \
            m_hWnd,                                                 \
            rcButton,                                               \
            szText,                                                 \
            WS_TABSTOP,                                             \
            MAKEINTRESOURCE(IDB_BUTTON_NORM),                       \
            MAKEINTRESOURCE(IDB_BUTTON_PRESS),                      \
            MAKEINTRESOURCE(IDB_BUTTON_DIS),                        \
            MAKEINTRESOURCE(IDB_BUTTON_HOT),                        \
            NULL,                                                   \
            id);                                                    \
                                                                    \
        TOOLINFO    ti;                                             \
                                                                    \
        ti.cbSize = TTTOOLINFO_V1_SIZE;                             \
        ti.uFlags = TTF_IDISHWND | TTF_SUBCLASS;                    \
        ti.hwnd = m_hWnd;                                           \
        ti.uId = (UINT_PTR)(HWND)m;                                 \
        ti.hinst = _Module.GetResourceInstance();                   \
        ti.lpszText = MAKEINTRESOURCE(ttid);                        \
                                                                    \
        m_hTooltip.SendMessage(TTM_ADDTOOL, 0,                      \
                (LPARAM)(LPTOOLINFO)&ti);                           \
    }
#define POSITION_WINDOW(m,x,y,cx,cy,f)                  \
    m.SetWindowPos(                                     \
        hPrevious,                                      \
        x,                                              \
        y,                                              \
        cx,                                             \
        cy,                                             \
        SWP_NOACTIVATE | f );                           \
    hPrevious = (HWND)m;

// net\tapi\rtc\phoenix\src\exe\mainfrm.cpp
#define     CREATE_DIALPAD_BUTTON(s1,s2)                    \
    m_hKeypad##s1.Create(m_hWnd, rcDummy, NULL, WS_TABSTOP, \
        MAKEINTRESOURCE(IDB_KEYPAD##s2##_NORM),             \
        MAKEINTRESOURCE(IDB_KEYPAD##s2##_PRESS),            \
        MAKEINTRESOURCE(IDB_KEYPAD##s2##_DIS),              \
        MAKEINTRESOURCE(IDB_KEYPAD##s2##_HOT),              \
        NULL,                                               \
        ID_KEYPAD##s2);                                     \
                                                            \
        ti.cbSize = TTTOOLINFO_V1_SIZE;                     \
        ti.uFlags = TTF_IDISHWND | TTF_SUBCLASS;            \
        ti.hwnd = m_hWnd;                                   \
        ti.uId = (UINT_PTR)(HWND)m_hKeypad##s1;             \
        ti.hinst = _Module.GetResourceInstance();           \
        ti.lpszText = MAKEINTRESOURCE(IDS_TIPS_KEYPAD##s2); \
                                                            \
        m_hTooltip.SendMessage(TTM_ADDTOOL, 0,              \
                (LPARAM)(LPTOOLINFO)&ti);
#define POSITION_WINDOW(m,x,y,cx,cy,f)                  \
    m.SetWindowPos(                                     \
        hPrevious,                                      \
        x,                                              \
        y,                                              \
        cx,                                             \
        cy,                                             \
        SWP_NOACTIVATE | f );                           \
    hPrevious = (HWND)m;

// net\tapi\skywalker\apps\avdialer\avmeter\tmeter.c
#define HANDLE_WM_CAPTURECHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_CAPTURECHANEGED(hwnd, hwndNewCapture, fn) \
    (void)(fn)((hwnd), WM_CAPTURECHANGED, (WPARAM)(HWND)(hwndNewCapture), 0L)

// net\tapi\skywalker\apps\avdialer\confprop\cpgen.cpp
#define ConfPropGeneral_DefProc(hwnd, msg, wParam, lParam) \
	DefDlgProcEx(hwnd, msg, wParam, lParam, &g_bDefDlgEx)

// net\tapi\skywalker\filters\rtp\inc\rtpfwrap.h
#define RTPCTRL_ENABLED(ControlW)   (ControlW & 0x8000)

// net\tapi\skywalker\filters\rtp\msrtp\funcs\rtpfwrap.c
#define GETDIR(Control)      (Control & 0x01000000)

// net\tapi\skywalker\h323tsp\line.h
#define H323IsTapiControlCode(_wch_) \
    (((_wch_) == L'T') || ((_wch_) == L'P'))

// net\tapi\skywalker\tapi3\common.h
#define AUDIOMEDIAMODES (LINEMEDIAMODE_INTERACTIVEVOICE | LINEMEDIAMODE_AUTOMATEDVOICE)
#define ALLMEDIAMODES   (LINEMEDIAMODE_AUTOMATEDVOICE | LINEMEDIAMODE_VIDEO | \
                        LINEMEDIAMODE_G3FAX | LINEMEDIAMODE_DATAMODEM )

// net\tapi\thunk\windows.h
#define GHND                (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define LHND                (LMEM_MOVEABLE | LMEM_ZEROINIT)
#define QS_MOUSE        (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#define EDGE_RAISED     (BDR_RAISEDOUTER | BDR_RAISEDINNER) // ;Internal 4.0
#define EDGE_SUNKEN     (BDR_SUNKENOUTER | BDR_SUNKENINNER) // ;Internal 4.0
#define EDGE_ETCHED     (BDR_SUNKENOUTER | BDR_RAISEDINNER) // ;Internal 4.0
#define EDGE_BUMP       (BDR_RAISEDOUTER | BDR_SUNKENINNER) // ;Internal 4.0
#define BF_TOPLEFT      (BF_TOP | BF_LEFT)                  // ;Internal 4.0
#define BF_TOPRIGHT     (BF_TOP | BF_RIGHT)                 // ;Internal 4.0
#define BF_BOTTOMLEFT   (BF_BOTTOM | BF_LEFT)               // ;Internal 4.0
#define BF_BOTTOMRIGHT  (BF_BOTTOM | BF_RIGHT)              // ;Internal 4.0
#define BF_DIAGONAL_ENDTOPRIGHT     (BF_DIAGONAL | BF_TOP | BF_RIGHT)       // ;Internal 4.0
#define BF_DIAGONAL_ENDTOPLEFT      (BF_DIAGONAL | BF_TOP | BF_LEFT)        // ;Internal 4.0
#define BF_DIAGONAL_ENDBOTTOMLEFT   (BF_DIAGONAL | BF_BOTTOM | BF_LEFT)     // ;Internal 4.0
#define BF_DIAGONAL_ENDBOTTOMRIGHT  (BF_DIAGONAL | BF_BOTTOM | BF_RIGHT)    // ;Internal 4.0
#define DC_NC               (DC_CAPTION | DC_FRAME)         // ;Internal
#define PAS_HORZ        (PAS_LEFT | PAS_RIGHT)              // ;Internal
#define PAS_VERT        (PAS_UP | PAS_DOWN)                 // ;Internal
#define SWP_NOCHANGE   (SWP_NOSIZE | SWP_NOMOVE |           /* ;Internal */ \
                        SWP_NOZORDER | SWP_NOCLIENTSIZE |   /* ;Internal */ \
                        SWP_NOCLIENTMOVE)                   /* ;Internal */
#define FLASHW_ALL          (FLASHW_CAPTION | FLASHW_TRAY)   // ;internal 4.1
#define WVR_REDRAW          (WVR_HREDRAW | WVR_VREDRAW)
#define MFS_GAPDROP      (MFS_TOPGAPDROP | MFS_BOTTOMGAPDROP) // ;Internal 4.1
#define SBM_SETPOS          (WM_USER)                       // ;Internal
#define SBM_GETPOS          (WM_USER+1)                     // ;Internal
#define SBM_ENABLE_ARROWS   (WM_USER+4)                     // ;Internal
#define SBM_SETSCROLLINFO   (WM_USER+9)                     // ;Internal 4.0
#define SBM_GETSCROLLINFO   (WM_USER+10)                    // ;Internal 4.0
#define DM_GETDEFID         (WM_USER+0)
#define DM_SETDEFID         (WM_USER+1)
#define DM_REPOSITION       (WM_USER+2)     /* ;Internal 4.0 */
#define PSM_SHEETINFO       (WM_USER+101)   /* ;Internal 4.0 */
#define STM_SETICON         (WM_USER+0)
#define STM_GETICON         (WM_USER+1)
#define BM_SETSTYLE         (WM_USER+4)
#define BM_CLICK            (WM_USER+5)
#define EM_GETSEL               (WM_USER+0)
#define EM_SETSEL               (WM_USER+1)
#define EM_SCROLL               (WM_USER+5)     // ;Internal
#define EM_LINESCROLL           (WM_USER+6)
#define EM_SCROLLCARET          (WM_USER+7)
#define EM_GETMODIFY            (WM_USER+8)
#define EM_SETMODIFY            (WM_USER+9)
#define EM_LINEINDEX            (WM_USER+11)
#define EM_SETHANDLE            (WM_USER+12)
#define EM_GETHANDLE            (WM_USER+13)
#define EM_GETTHUMB             (WM_USER+14)    // ;Internal
#define EM_REPLACESEL           (WM_USER+18)
#define EM_SETFONT              (WM_USER+19)    /* NOT IMPLEMENTED: use WM_SETFONT */
#define EM_GETLINE              (WM_USER+20)
#define EM_CANUNDO              (WM_USER+22)
#define EM_UNDO                 (WM_USER+23)
#define EM_FMTLINES             (WM_USER+24)
#define EM_SETTABSTOPS          (WM_USER+27)
#define EM_GETFIRSTVISIBLELINE  (WM_USER+30)
#define EM_SETREADONLY          (WM_USER+31)
#define EM_SETMARGINS           (WM_USER+35)    /* ;Internal 4.0 */
#define EM_GETMARGINS           (WM_USER+36)    /* ;Internal 4.0 */
#define EM_RESERVED1		    (WM_USER+0x40)  // ;Internal
#define EM_RESERVED2			(WM_USER+0x41)  // ;Internal
#define EM_RESERVED3			(WM_USER+0x42)  // ;Internal
#define EM_RESERVED4			(WM_USER+0x43)  // ;Internal
#define EM_RESERVED5			(WM_USER+0x44)  // ;Internal
#define LBS_STANDARD            (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)
#define LB_FIRST_16             (WM_USER+1)     // ;Internal
#define LB_RESETCONTENT         (WM_USER+5)
#define LB_SETSEL               (WM_USER+6)
#define LB_SETCURSEL            (WM_USER+7)
#define LB_GETSEL               (WM_USER+8)
#define LB_GETCURSEL            (WM_USER+9)
#define LB_DIR                  (WM_USER+14)
#define LB_GETTOPINDEX          (WM_USER+15)
#define LB_GETSELITEMS          (WM_USER+18)
#define LB_SETTABSTOPS          (WM_USER+19)
#define LB_GETHORIZONTALEXTENT  (WM_USER+20)
#define LB_SETHORIZONTALEXTENT  (WM_USER+21)
#define LB_SETCOLUMNWIDTH       (WM_USER+22)
#define LB_ADDFILE              (WM_USER+23)    // ;Internal
#define LB_SETTOPINDEX          (WM_USER+24)
#define LB_GETITEMDATA          (WM_USER+26)
#define LB_SETITEMDATA          (WM_USER+27)
#define LB_SETANCHORINDEX       (WM_USER+29)
#define LB_GETANCHORINDEX       (WM_USER+30)
#define LB_SETCARETINDEX        (WM_USER+31)
#define LB_GETCARETINDEX        (WM_USER+32)
#define LB_SETITEMHEIGHT        (WM_USER+33)
#define LB_GETITEMHEIGHT        (WM_USER+34)
#define LB_FIRST_40             (WM_USER+41)    // ;Internal 4.0
#define LB_INITSTORAGE          (WM_USER+41)    // ;Internal 4.0

// net\tcpip\driver\tcp\tcprcv.h
#define ANY_REQUEST_COMPLETE    (CONN_REQUEST_COMPLETE | SEND_REQUEST_COMPLETE)

// net\tcpip\tpipv6\tcpip6\tcp\tcprcv.h
#define ANY_REQUEST_COMPLETE (CONN_REQUEST_COMPLETE | SEND_REQUEST_COMPLETE)

// net\unimodem\inc\rovcomm.h
#define MB_WARNING      (MB_OK | MB_ICONWARNING)
#define MB_INFO         (MB_OK | MB_ICONINFORMATION)
#define MB_ERROR        (MB_OK | MB_ICONERROR)
#define MB_QUESTION     (MB_YESNO | MB_ICONQUESTION)
#define SetDlgHandle(hwnd, msg, lp)     if((msg)==WM_SETFONT) (lp)->hdlg=(hwnd);

// net\unimodem\serialui\port.c
#define Port_SetPtr(hwnd, lp)       (PPORT)SetWindowLongPtr(hwnd, DWLP_USER, (ULONG_PTR)(lp))

// net\unimodem\src\mdminst\ui.c
#define SetDlgFocus(hDlg, idc)      SendMessage(hDlg, WM_NEXTDLGCTL, (WPARAM)GetDlgItem(hDlg, idc), 1L)

// net\unimodem\src\modemui\cpldiag.c
#define Diag_SetPtr(hwnd, lp)       (PDIAG)SetWindowLongPtr(hwnd, DWLP_USER, (ULONG_PTR)(lp))

// net\wins\server\inc\comm.h
#define  COMM_GET_FAMILY_M(pDlgHdl, Family)	{		  	  \
			PCOMMASSOC_DLG_CTX_T	_pEnt = (pDlgHdl)->pEnt;  \
			Family = _pEnt->FromAdd.sin_family; 	          \
					}

// printscan\fax\admin\faxadmin\dgenprop.cpp
#define MyHideWindow(_hwnd)   ::SetWindowLong((_hwnd),GWL_STYLE,::GetWindowLong((_hwnd),GWL_STYLE)&~WS_VISIBLE)

// printscan\fax\admin\routeext\route.cpp
#define MyHideWindow(_hwnd)   ::SetWindowLong((_hwnd),GWL_STYLE,::GetWindowLong((_hwnd),GWL_STYLE)&~WS_VISIBLE)

// printscan\fax\config\dll\faxcpl.h
#define HideWindow(_hwnd)   SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)&~WS_VISIBLE)
#define UnHideWindow(_hwnd) SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)|WS_VISIBLE)

// printscan\fax\config\dll\util.h
#define IsListViewItemChecked(hwndLV, index) \
        (ListView_GetItemState(hwndLV, index, LVIS_STATEIMAGEMASK) == CHECKED_STATE)
#define CheckListViewItem(hwndLV, index) \
        ListView_SetItemState(hwndLV, index, CHECKED_STATE, LVIS_STATEIMAGEMASK)
#define UncheckListViewItem(hwndLV, index) \
        ListView_SetItemState(hwndLV, index, UNCHECKED_STATE, LVIS_STATEIMAGEMASK)

// printscan\fax\inc\faxutil.h
#define HideWindow(_hwnd)   SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)&~WS_VISIBLE)
#define UnHideWindow(_hwnd) SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)|WS_VISIBLE)

// printscan\fax\print\faxprint\faxui\faxui.h
#define MyHideWindow(_hwnd) SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)&~WS_VISIBLE)

// printscan\fax\print\faxprint\faxui\wizard.c
#define Scan_Init(_pUserMem)    (SendMessage(_pUserMem->hWndTwain, WM_SCAN_INIT,0,(LPARAM)_pUserMem))
#define Scan_OpenDSM(_pUserMem) ((DWORD)SendMessage(_pUserMem->hWndTwain, WM_SCAN_OPENDSM,0,(LPARAM)&_pUserMem->hWndTwain))
#define Scan_GetDefault(_pUserMem,_TwIdentity) ((DWORD)SendMessage(_pUserMem->hWndTwain, WM_SCAN_GETDEFAULT,0,(LPARAM)_TwIdentity))
#define Scan_GetFirst(_pUserMem,_TwIdentity) ((DWORD)SendMessage(_pUserMem->hWndTwain, WM_SCAN_GETFIRST,0,(LPARAM)_TwIdentity))
#define Scan_GetNext(_pUserMem,_TwIdentity) ((DWORD)SendMessage(_pUserMem->hWndTwain, WM_SCAN_GETNEXT,0,(LPARAM)_TwIdentity))
#define Scan_OpenDS(_pUserMem,_TwIdentity)  (SendMessage(_pUserMem->hWndTwain, WM_SCAN_OPENDS,0,(LPARAM)_TwIdentity))
#define Scan_EnableDS(_pUserMem,_TwUi)      (SendMessage(_pUserMem->hWndTwain, WM_SCAN_ENABLEDS,0,(LPARAM)_TwUi))
#define Scan_DisableDS(_pUserMem,_TwUi)     (SendMessage(_pUserMem->hWndTwain, WM_SCAN_DISABLEDS,0,(LPARAM)_TwUi))
#define Scan_ControlGet(_pUserMem,_What,_Data) ((DWORD)SendMessage(_pUserMem->hWndTwain, WM_SCAN_CONTROLGET,(WPARAM)_What,(LPARAM)_Data))
#define Scan_ControlGetDef(_pUserMem,_What,_Data) (SendMessage(_pUserMem->hWndTwain, WM_SCAN_CONTROLGETDEF,(WPARAM)_What,(LPARAM)_Data))
#define Scan_ControlReset(_pUserMem,_What,_Data) ((DWORD)SendMessage(_pUserMem->hWndTwain, WM_SCAN_CONTROLRESET,(WPARAM)_What,(LPARAM)_Data))
#define Scan_ControlSet(_pUserMem,_What,_Data) ((DWORD)SendMessage(_pUserMem->hWndTwain, WM_SCAN_CONTROLSET,(WPARAM)_What,(LPARAM)_Data))
#define Scan_ControlEndXfer(_pUserMem,_What,_Data) ((DWORD)SendMessage(_pUserMem->hWndTwain, WM_SCAN_CONTROLENDXFER,(WPARAM)_What,(LPARAM)_Data))
#define Scan_ImageGet(_pUserMem,_What,_Data) ((DWORD)SendMessage(_pUserMem->hWndTwain, WM_SCAN_IMAGEGET,(WPARAM)_What,(LPARAM)_Data))

// printscan\fax\provider\t30\comm\fcom.c
#       define MyGetMessage(x)                                                                                  \
          ( GetMessage(&x, NULL, 0, 0),                                                                 \
            (x.hwnd ? (DispatchMessage(&x), x.message=WM_NULL) : 0),    \
            (x.message != WM_QUIT) )
#       define MyPeekMessage(x)                                                                                         \
          ( (x.message=WM_NULL),                                                                                        \
                ( PeekMessage(&x, NULL, 0, 0, PM_RNOY) ?                                                \
                        (x.hwnd ? (DispatchMessage(&x), x.message=WM_NULL) : TRUE)      \
                          : FALSE ) )
#       define MyGetMessage(x)   (      GetMessage(&x, NULL, 0, 0),                     \
                                                                BG_CHK(x.hwnd==0),                                      \
                                                                (x.message != IF_QUIT) )
#       define MyPeekMessage(x)  (      (x.message = WM_NULL),                                  \
                                                                PeekMessage(&x, NULL, 0, 0, PM_RNOY),   \
                                                                BG_CHK(x.hwnd==0),                                      \
                                                                (x.message != WM_NULL) )

// printscan\fax\provider\t30\headers\uiutil.h
#define GET_WM_COMMAND_CONTROL_HANDLE(wp, lp)				(HWND)(LOWORD)(lp)
#define GET_WM_COMMAND_CONTROL_HANDLE(wp, lp)				(HWND)(lp)

// printscan\faxsrv\src\inc\faxhelp.h
#define FAXWINHELP( iMsg, wParam, lParam, HelpIDs )       \
                                                          \
    if ((iMsg) == WM_HELP) {                              \
                                                          \
        WinHelp((HWND)((LPHELPINFO) (lParam))->hItemHandle,     \
                FAXCFG_HELP_FILENAME,                     \
                HELP_WM_HELP,                             \
                (ULONG_PTR) (HelpIDs));                    \
                                                          \
    } else {                                              \
                                                          \
        WinHelp((HWND) (wParam),                          \
                FAXCFG_HELP_FILENAME,                     \
                HELP_CONTEXTMENU,                         \
                (ULONG_PTR) (HelpIDs));                    \
    }

// printscan\faxsrv\src\inc\faxutil.h
#define HideWindow(_hwnd)   SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)&~WS_VISIBLE)
#define UnHideWindow(_hwnd) SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)|WS_VISIBLE)

// printscan\faxsrv\src\print\faxprint\prnwzrd\faxui.h
#define MyHideWindow(_hwnd) SetWindowLong((_hwnd),GWL_STYLE,GetWindowLong((_hwnd),GWL_STYLE)&~WS_VISIBLE)

// printscan\faxsrv\src\provider\t30\comm\fcom.c
#       define MyGetMessage(x)                                                                                  \
          ( GetMessage(&x, NULL, 0, 0),                                                                 \
            (x.hwnd ? (DispatchMessage(&x), x.message=WM_NULL) : 0),    \
            (x.message != WM_QUIT) )
#       define MyPeekMessage(x)                                                                                         \
          ( (x.message=WM_NULL),                                                                                        \
                ( PeekMessage(&x, NULL, 0, 0, PM_RNOY) ?                                                \
                        (x.hwnd ? (DispatchMessage(&x), x.message=WM_NULL) : TRUE)      \
                          : FALSE ) )
#       define MyGetMessage(x)   (      GetMessage(&x, NULL, 0, 0),                     \
                                                                BG_CHK(x.hwnd==0),                                      \
                                                                (x.message != IF_QUIT) )
#       define MyPeekMessage(x)  (      (x.message = WM_NULL),                                  \
                                                                PeekMessage(&x, NULL, 0, 0, PM_RNOY),   \
                                                                BG_CHK(x.hwnd==0),                                      \
                                                                (x.message != WM_NULL) )

// printscan\faxsrv\src\sdktools\msvc15\include\windowsx.h
#define     SetWindowRedraw(hwnd, fRedraw)  \
                    ((void)SendMessage(hwnd, WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L))
#define     IsRestored(hwnd)    ((GetWindowStyle(hwnd) & (WS_MINIMIZE | WS_MAXIMIZE)) == 0L)
#define     SetWindowFont(hwnd, hfont, fRedraw) FORWARD_WM_SETFONT((hwnd), (hfont), (fRedraw), SendMessage)
#define     GetWindowFont(hwnd)                 FORWARD_WM_GETFONT((hwnd), SendMessage)
#define HANDLE_WM_COMPACTING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_COMPACTING(hwnd, compactRatio, fn) \
    (void)(fn)((hwnd), WM_COMPACTING, (WPARAM)(UINT)(compactRatio), 0L)
#define HANDLE_WM_WININICHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_WININICHANGE(hwnd, lpszSectionName, fn) \
    (void)(fn)((hwnd), WM_WININICHANGE, 0, (LPARAM)(LPCSTR)(lpszSectionName))
#define HANDLE_WM_SYSCOLORCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_SYSCOLORCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_SYSCOLORCHANGE, 0, 0L)
#define HANDLE_WM_QUERYNEWPALETTE(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYNEWPALETTE(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYNEWPALETTE, 0, 0L)
#define HANDLE_WM_PALETTEISCHANGING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTEISCHANGING(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTEISCHANGING, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_PALETTECHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTECHANGED(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTECHANGED, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_FONTCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_FONTCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_FONTCHANGE, 0, 0L)
#define HANDLE_WM_DEVMODECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_DEVMODECHANGE(hwnd, lpszDeviceName, fn) \
    (void)(fn)((hwnd), WM_DEVMODECHANGE, 0,(LPARAM)(LPCSTR)(lpszDeviceName))
#define HANDLE_WM_TIMECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_TIMECHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_TIMECHANGE, 0, 0L)
#define HANDLE_WM_POWER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_POWER(hwnd, code, fn) \
    (void)(fn)((hwnd), WM_POWER, (WPARAM)(code), 0L)
#define HANDLE_WM_QUERYENDSESSION(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYENDSESSION(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYENDSESSION, 0, 0L)
#define HANDLE_WM_ENDSESSION(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENDSESSION(hwnd, fEnding, fn) \
    (void)(fn)((hwnd), WM_ENDSESSION, (WPARAM)(BOOL)(fEnding), 0L)
#define HANDLE_WM_QUIT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_QUIT(hwnd, exitCode, fn) \
    (void)(fn)((hwnd), WM_QUIT, (WPARAM)(exitCode), 0L)
#define HANDLE_WM_SYSTEMERROR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_SYSTEMERROR(hwnd, errCode, fn) \
    (void)(fn)((hwnd), WM_SYSTEMERROR, (WPARAM)(errCode), 0L)
#define HANDLE_WM_CREATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (CREATESTRUCT FAR*)(lParam)) ? 0L : (LRESULT)-1L)
#define FORWARD_WM_CREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_CREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_NCCREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (CREATESTRUCT FAR*)(lParam))
#define FORWARD_WM_NCCREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCCREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_DESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROY, 0, 0L)
#define HANDLE_WM_NCDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_NCDESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_NCDESTROY, 0, 0L)
#define HANDLE_WM_SHOWWINDOW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), LOWORD(lParam)), 0L)
#define HANDLE_WM_SETREDRAW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_SETREDRAW(hwnd, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETREDRAW, (WPARAM)(fRedraw), 0L)
#define HANDLE_WM_ENABLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENABLE(hwnd, fEnable, fn) \
    (void)(fn)((hwnd), WM_ENABLE, (WPARAM)(BOOL)(fEnable), 0L)
#define HANDLE_WM_SETTEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_SETTEXT(hwnd, lpszText, fn) \
    (void)(fn)((hwnd), WM_SETTEXT, 0, (LPARAM)(LPCSTR)(lpszText))
#define HANDLE_WM_GETTEXT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (int)(wParam), (LPSTR)(lParam))
#define FORWARD_WM_GETTEXT(hwnd, cchTextMax, lpszText, fn) \
    (int)(DWORD)(fn)((hwnd), WM_GETTEXT, (WPARAM)(int)(cchTextMax), (LPARAM)(LPSTR)(lpszText))
#define HANDLE_WM_GETTEXTLENGTH(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)(hwnd)
#define FORWARD_WM_GETTEXTLENGTH(hwnd, fn) \
    (int)(DWORD)(fn)((hwnd), WM_GETTEXTLENGTH, 0, 0L)
#define HANDLE_WM_WINDOWPOSCHANGING(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (WINDOWPOS FAR*)(lParam))
#define FORWARD_WM_WINDOWPOSCHANGING(hwnd, lpwpos, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_WINDOWPOSCHANGING, 0, (LPARAM)(WINDOWPOS FAR*)(lpwpos))
#define HANDLE_WM_WINDOWPOSCHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const WINDOWPOS FAR*)(lParam)), 0L)
#define FORWARD_WM_WINDOWPOSCHANGED(hwnd, lpwpos, fn) \
    (void)(fn)((hwnd), WM_WINDOWPOSCHANGED, 0, (LPARAM)(const WINDOWPOS FAR*)(lpwpos))
#define HANDLE_WM_MOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_MOVE(hwnd, x, y, fn) \
    (void)(fn)((hwnd), WM_MOVE, 0, MAKELPARAM((int)(x), (int)(y)))
#define HANDLE_WM_SIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_SIZE(hwnd, state, cx, cy, fn) \
    (void)(fn)((hwnd), WM_SIZE, (WPARAM)(UINT)(state), MAKELPARAM((int)(cx), (int)(cy)))
#define HANDLE_WM_QUERYOPEN(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYOPEN(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYOPEN, 0, 0L)
#define HANDLE_WM_GETMINMAXINFO(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MINMAXINFO FAR*)(lParam)), 0L)
#define FORWARD_WM_GETMINMAXINFO(hwnd, lpMinMaxInfo, fn) \
    (void)(fn)((hwnd), WM_GETMINMAXINFO, 0, (LPARAM)(MINMAXINFO FAR*)(lpMinMaxInfo))
#define HANDLE_WM_PAINT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PAINT(hwnd, fn) \
    (void)(fn)((hwnd), WM_PAINT, 0, 0L)
#define HANDLE_WM_ERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define FORWARD_WM_ERASEBKGND(hwnd, hdc, fn) \
   (BOOL)(DWORD)(fn)((hwnd), WM_ERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define HANDLE_WM_ICONERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define FORWARD_WM_ICONERASEBKGND(hwnd, hdc, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_ICONERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define HANDLE_WM_NCPAINT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HRGN)(wParam)), 0L)
#define FORWARD_WM_NCPAINT(hwnd, hrgn, fn) \
    (void)(fn)((hwnd), WM_NCPAINT, (WPARAM)(HRGN)(hrgn), 0L)
#define HANDLE_WM_NCCALCSIZE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (NCCALCSIZE_PARAMS FAR*)(lParam))
#define FORWARD_WM_NCCALCSIZE(hwnd, fCalcValidRects, lpcsp, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_NCCALCSIZE, (WPARAM)(fCalcValidRects), (LPARAM)(NCCALCSIZE_PARAMS FAR*)(lpcsp))
#define HANDLE_WM_NCHITTEST(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_NCHITTEST(hwnd, x, y, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_NCHITTEST, 0, MAKELPARAM((int)(x), (int)(y)))
#define HANDLE_WM_QUERYDRAGICON(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define FORWARD_WM_QUERYDRAGICON(hwnd, fn) \
    (HICON)(UINT)(DWORD)(fn)((hwnd), WM_QUERYDRAGICON, 0, 0L)
#define HANDLE_WM_DROPFILES(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HDROP)(wParam)), 0L)
#define FORWARD_WM_DROPFILES(hwnd, hdrop, fn) \
    (void)(fn)((hwnd), WM_DROPFILES, (WPARAM)(hdrop), 0L)
#define HANDLE_WM_ACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define FORWARD_WM_ACTIVATE(hwnd, state, hwndActDeact, fMinimized, fn) \
    (void)(fn)((hwnd), WM_ACTIVATE, (WPARAM)(UINT)(state), MAKELPARAM((UINT)(HWND)(hwndActDeact), (UINT)(BOOL)(fMinimized)))
#define HANDLE_WM_ACTIVATEAPP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (HTASK)LOWORD(lParam)), 0L)
#define FORWARD_WM_ACTIVATEAPP(hwnd, fActivate, htaskActDeact, fn) \
    (void)(fn)((hwnd), WM_ACTIVATEAPP, (WPARAM)(BOOL)(fActivate), MAKELPARAM((htaskActDeact),0))
#define HANDLE_WM_NCACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (BOOL)(wParam), (HWND)LOWORD(lParam), (BOOL)HIWORD(lParam))
#define FORWARD_WM_NCACTIVATE(hwnd, fActive, hwndActDeact, fMinimized, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCACTIVATE, (WPARAM)(BOOL)(fActive), MAKELPARAM((UINT)(HWND)(hwndActDeact), (UINT)(BOOL)(fMinimized)))
#define HANDLE_WM_SETFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_SETFOCUS(hwnd, hwndOldFocus, fn) \
    (void)(fn)((hwnd), WM_SETFOCUS, (WPARAM)(HWND)(hwndOldFocus), 0L)
#define HANDLE_WM_KILLFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_KILLFOCUS(hwnd, hwndNewFocus, fn) \
    (void)(fn)((hwnd), WM_KILLFOCUS, (WPARAM)(HWND)(hwndNewFocus), 0L)
#define HANDLE_WM_KEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_KEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_KEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_KEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_CHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_CHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_CHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define HANDLE_WM_DEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_DEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_DEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define HANDLE_WM_SYSKEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSKEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_SYSKEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSKEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_SYSCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_SYSCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define HANDLE_WM_SYSDEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_SYSDEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSDEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define HANDLE_WM_MOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MOUSEMOVE(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MOUSEMOVE, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_LBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_LBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_LBUTTONDBLCLK : WM_LBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_LBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_LBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_LBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_LBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_RBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_RBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_RBUTTONDBLCLK : WM_RBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_RBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_RBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_RBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_RBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_MBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_MBUTTONDBLCLK : WM_MBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_MBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_MBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCMOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMOUSEMOVE(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMOUSEMOVE, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCLBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCLBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCLBUTTONDBLCLK : WM_NCLBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCLBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCLBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCLBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCLBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCRBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCRBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCRBUTTONDBLCLK : WM_NCRBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCRBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCRBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCRBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCRBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCMBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCMBUTTONDBLCLK : WM_NCMBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCMBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCMBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_MOUSEACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))
#define FORWARD_WM_MOUSEACTIVATE(hwnd, hwndTopLevel, codeHitTest, msg, fn) \
    (int)(DWORD)(fn)((hwnd), WM_MOUSEACTIVATE, (WPARAM)(HWND)(hwndTopLevel), MAKELPARAM((codeHitTest), (msg)))
#define HANDLE_WM_CANCELMODE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CANCELMODE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CANCELMODE, 0, 0L)
#define HANDLE_WM_TIMER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_TIMER(hwnd, id, fn) \
    (void)(fn)((hwnd), WM_TIMER, (WPARAM)(UINT)(id), 0L)
#define HANDLE_WM_INITMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam)), 0L)
#define FORWARD_WM_INITMENU(hwnd, hMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENU, (WPARAM)(HMENU)(hMenu), 0L)
#define HANDLE_WM_INITMENUPOPUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam), (int)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define FORWARD_WM_INITMENUPOPUP(hwnd, hMenu, item, fSystemMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENUPOPUP, (WPARAM)(HMENU)(hMenu), MAKELPARAM((item),(fSystemMenu)))
#define HANDLE_WM_MENUSELECT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)HIWORD(lParam), (LOWORD(lParam) & MF_POPUP) ? 0 : (int)(wParam), \
                            (LOWORD(lParam) & MF_POPUP) ? (HMENU)(wParam) : 0, LOWORD(lParam)), 0L)
#define FORWARD_WM_MENUSELECT(hwnd, hmenu, item, hmenuPopup, flags, fn) \
    (void)(fn)((hwnd), WM_MENUSELECT, ((flags) & MF_POPUP) ? (WPARAM)(HMENU)(hmenuPopup) : (WPARAM)(int)(item), MAKELPARAM((flags), (hmenu)))
#define HANDLE_WM_MENUCHAR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam), LOWORD(lParam), (HMENU)HIWORD(lParam));
#define FORWARD_WM_MENUCHAR(hwnd, ch, flags, hmenu, fn) \
    (DWORD)(fn)((hwnd), WM_MENUCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((flags), (UINT)(hmenu)))
#define HANDLE_WM_COMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (HWND)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_COMMAND(hwnd, id, hwndCtl, codeNotify, fn) \
    (void)(fn)((hwnd), WM_COMMAND, (WPARAM)(int)(id), MAKELPARAM((UINT)(hwndCtl), (codeNotify)))
#define HANDLE_WM_HSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)HIWORD(lParam), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_HSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define HANDLE_WM_VSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)HIWORD(lParam), (UINT)(wParam),  (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_VSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define HANDLE_WM_CUT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CUT(hwnd, fn) \
    (void)(fn)((hwnd), WM_CUT, 0, 0L)
#define HANDLE_WM_COPY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_COPY(hwnd, fn) \
    (void)(fn)((hwnd), WM_COPY, 0, 0L)
#define HANDLE_WM_PASTE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PASTE(hwnd, fn) \
    (void)(fn)((hwnd), WM_PASTE, 0, 0L)
#define HANDLE_WM_CLEAR(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CLEAR(hwnd, fn) \
    (void)(fn)((hwnd), WM_CLEAR, 0, 0L)
#define HANDLE_WM_UNDO(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_UNDO(hwnd, fn) \
    (void)(fn)((hwnd), WM_UNDO, 0, 0L)
#define HANDLE_WM_RENDERFORMAT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HANDLE)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_RENDERFORMAT(hwnd, fmt, fn) \
    (HANDLE)(UINT)(DWORD)(fn)((hwnd), WM_RENDERFORMAT, (WPARAM)(UINT)(fmt), 0L)
#define HANDLE_WM_RENDERALLFORMATS(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_RENDERALLFORMATS(hwnd, fn) \
    (void)(fn)((hwnd), WM_RENDERALLFORMATS, 0, 0L)
#define HANDLE_WM_DESTROYCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROYCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROYCLIPBOARD, 0, 0L)
#define HANDLE_WM_DRAWCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DRAWCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DRAWCLIPBOARD, 0, 0L)
#define HANDLE_WM_PAINTCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const PAINTSTRUCT FAR*)GlobalLock((HGLOBAL)LOWORD(lParam))), GlobalUnlock((HGLOBAL)LOWORD(lParam)), 0L)
#define FORWARD_WM_PAINTCLIPBOARD(hwnd, hwndCBViewer, lpPaintStruct, fn) \
    (void)(fn)((hwnd), WM_PAINTCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(lpPaintStruct))
#define HANDLE_WM_SIZECLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const RECT FAR*)GlobalLock((HGLOBAL)LOWORD(lParam))), GlobalUnlock((HGLOBAL)LOWORD(lParam)), 0L)
#define FORWARD_WM_SIZECLIPBOARD(hwnd, hwndCBViewer, lprc, fn) \
    (void)(fn)((hwnd), WM_SIZECLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(lprc))
#define HANDLE_WM_VSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_VSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_HSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_HSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_ASKCBFORMATNAME(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (LPSTR)(lParam)), 0L)
#define FORWARD_WM_ASKCBFORMATNAME(hwnd, cchMax, rgchName, fn) \
    (void)(fn)((hwnd), WM_ASKCBFORMATNAME, (WPARAM)(int)(cchMax), (LPARAM)(rgchName))
#define HANDLE_WM_CHANGECBCHAIN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (HWND)LOWORD(lParam)), 0L)
#define FORWARD_WM_CHANGECBCHAIN(hwnd, hwndRemove, hwndNext, fn) \
    (void)(fn)((hwnd), WM_CHANGECBCHAIN, (WPARAM)(HWND)(hwndRemove), MAKELPARAM((UINT)(hwndNext), 0))
#define HANDLE_WM_SETCURSOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam));
#define FORWARD_WM_SETCURSOR(hwnd, hwndCursor, codeHitTest, msg, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_SETCURSOR, (WPARAM)(HWND)(hwndCursor), MAKELPARAM((codeHitTest), (msg)))
#define HANDLE_WM_SYSCOMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSCOMMAND(hwnd, cmd, x, y, fn) \
    (void)(fn)((hwnd), WM_SYSCOMMAND, (WPARAM)(UINT)(cmd), MAKELPARAM((x), (y)))
#define HANDLE_WM_MDICREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (MDICREATESTRUCT FAR*)(lParam))
#define FORWARD_WM_MDICREATE(hwnd, lpmcs, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDICREATE, 0, (LPARAM)(lpmcs))
#define HANDLE_WM_MDIDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIDESTROY(hwnd, hwndDestroy, fn) \
    (void)(fn)((hwnd), WM_MDIDESTROY, (WPARAM)(hwndDestroy), 0L)
#define HANDLE_WM_MDIACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (HWND)LOWORD(lParam), (HWND)HIWORD(lParam)), 0L)
#define FORWARD_WM_MDIACTIVATE(hwnd, fActive, hwndActivate, hwndDeactivate, fn) \
    (void)(fn)(hwnd, WM_MDIACTIVATE, (WPARAM)(fActive), MAKELPARAM((hwndActivate), (hwndDeactivate)))
#define HANDLE_WM_MDIRESTORE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIRESTORE(hwnd, hwndRestore, fn) \
    (void)(fn)((hwnd), WM_MDIRESTORE, (WPARAM)(hwndRestore), 0L)
#define HANDLE_WM_MDINEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (BOOL)LOWORD(lParam)), 0L)
#define FORWARD_WM_MDINEXT(hwnd, hwndCur, fPrev, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDINEXT, (WPARAM)(hwndCur), MAKELPARAM((fPrev), 0))
#define HANDLE_WM_MDIMAXIMIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIMAXIMIZE(hwnd, hwndMaximize, fn) \
    (void)(fn)((hwnd), WM_MDIMAXIMIZE, (WPARAM)(hwndMaximize), 0L)
#define HANDLE_WM_MDITILE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_MDITILE(hwnd, cmd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_MDITILE, (WPARAM)(cmd), 0L)
#define HANDLE_WM_MDICASCADE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_MDICASCADE(hwnd, cmd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_MDICASCADE, (WPARAM)(cmd), 0L)
#define HANDLE_WM_MDIICONARRANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_MDIICONARRANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_MDIICONARRANGE, 0, 0L)
#define HANDLE_WM_MDIGETACTIVE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define FORWARD_WM_MDIGETACTIVE(hwnd, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDIGETACTIVE, 0, 0L)
#define HANDLE_WM_MDISETMENU(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (HMENU)LOWORD(lParam), (HMENU)HIWORD(lParam))
#define FORWARD_WM_MDISETMENU(hwnd, fRefresh, hmenuFrame, hmenuWindow, fn) \
    (HMENU)(UINT)(DWORD)(fn)((hwnd), WM_MDISETMENU, (WPARAM)(fRefresh), MAKELPARAM((hmenuFrame), (hmenuWindow)))
#define HANDLE_WM_CHILDACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CHILDACTIVATE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CHILDACTIVATE, 0, 0L)
#define HANDLE_WM_NEXTDLGCTL(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HWND)(fn)((hwnd), (HWND)(wParam), (BOOL)LOWORD(lParam))
#define FORWARD_WM_NEXTDLGCTL(hwnd, hwndSetFocus, fNext, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_NEXTDLGCTL, (WPARAM)(HWND)(hwndSetFocus), MAKELPARAM((fNext), 0))
#define HANDLE_WM_PARENTNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_PARENTNOTIFY(hwnd, msg, hwndChild, idChild, fn) \
    (void)(fn)((hwnd), WM_PARENTNOTIFY, (WPARAM)(UINT)(msg), MAKELPARAM((UINT)(HWND)(hwndChild), (UINT)(idChild)))
#define HANDLE_WM_ENTERIDLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam)), 0L)
#define FORWARD_WM_ENTERIDLE(hwnd, source, hwndSource, fn) \
    (void)(fn)((hwnd), WM_ENTERIDLE, (WPARAM)(UINT)(source), MAKELPARAM((UINT)(HWND)(hwndSource), 0))
#define HANDLE_WM_GETDLGCODE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd, (MSG FAR*)(lParam))
#define FORWARD_WM_GETDLGCODE(hwnd, lpmsg, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_GETDLGCODE, (SELECTOROF(lpmsg) ? lpmsg->wParam : 0), (LPARAM)(lpmsg))
#define HANDLE_WM_CTLCOLOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)LOWORD(lParam), (int)(HIWORD(lParam)))
#define FORWARD_WM_CTLCOLOR(hwnd, hdc, hwndChild, type, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLOR, (WPARAM)(HDC)(hdc), MAKELPARAM((UINT)(HWND)(hwndChild), (UINT)(int)(type)))
#define HANDLE_WM_SETFONT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HFONT)(wParam), (BOOL)LOWORD(lParam)), 0L)
#define FORWARD_WM_SETFONT(hwnd, hfont, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETFONT, (WPARAM)(HFONT)(hfont), MAKELPARAM((UINT)(BOOL)(fRedraw), 0))
#define HANDLE_WM_GETFONT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HFONT)(fn)(hwnd)
#define FORWARD_WM_GETFONT(hwnd, fn) \
    (HFONT)(UINT)(DWORD)(fn)((hwnd), WM_GETFONT, 0, 0L)
#define HANDLE_WM_DRAWITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DRAWITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_DRAWITEM(hwnd, lpDrawItem, fn) \
    (void)(fn)((hwnd), WM_DRAWITEM, 0, (LPARAM)(const DRAWITEMSTRUCT FAR*)(lpDrawItem))
#define HANDLE_WM_MEASUREITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MEASUREITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_MEASUREITEM(hwnd, lpMeasureItem, fn) \
    (void)(fn)((hwnd), WM_MEASUREITEM, 0, (LPARAM)(MEASUREITEMSTRUCT FAR*)(lpMeasureItem))
#define HANDLE_WM_COMPAREITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (const COMPAREITEMSTRUCT FAR*)(lParam))
#define FORWARD_WM_COMPAREITEM(hwnd, lpCompareItem, fn) \
    (int)(DWORD)(fn)((hwnd), WM_COMPAREITEM, 0, (LPARAM)(const COMPAREITEMSTRUCT FAR*)(lpCompareItem))
#define HANDLE_WM_VKEYTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_VKEYTOITEM(hwnd, vk, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_VKEYTOITEM, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(hwndListBox), (UINT)(iCaret)))
#define HANDLE_WM_CHARTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_CHARTOITEM(hwnd, ch, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_CHARTOITEM, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(hwndListBox), (UINT)(iCaret)))
#define HANDLE_WM_QUEUESYNC(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_QUEUESYNC(hwnd, fn) \
    (void)(fn)((hwnd), WM_QUEUESYNC, 0, 0L)
#define HANDLE_WM_COMMNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), LOWORD(lParam)), 0L)
#define FORWARD_WM_COMMNOTIFY(hwnd, cid, flags, fn) \
    (void)(fn)((hwnd), WM_COMMNOTIFY, (WPARAM)(cid), MAKELPARAM((flags), 0))
#define Static_SetIcon(hwndCtl, hIcon)          ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_SETICON, (WPARAM)(HICON)(hIcon), 0L))
#define Static_GetIcon(hwndCtl, hIcon)          ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_GETICON, 0, 0L))
#define Button_GetCheck(hwndCtl)            ((int)(DWORD)SendMessage((hwndCtl), BM_GETCHECK, 0, 0L))
#define Button_SetCheck(hwndCtl, check)     ((void)SendMessage((hwndCtl), BM_SETCHECK, (WPARAM)(int)(check), 0L))
#define Button_GetState(hwndCtl)            ((int)(DWORD)SendMessage((hwndCtl), BM_GETSTATE, 0, 0L))
#define Button_SetState(hwndCtl, state)     ((UINT)(DWORD)SendMessage((hwndCtl), BM_SETSTATE, (WPARAM)(int)(state), 0L))
#define Button_SetStyle(hwndCtl, style, fRedraw) ((void)SendMessage((hwndCtl), BM_SETSTYLE, (WPARAM)LOWORD(style), MAKELPARAM(((fRedraw) ? TRUE : FALSE), 0)))
#define Edit_LimitText(hwndCtl, cchMax)         ((void)SendMessage((hwndCtl), EM_LIMITTEXT, (WPARAM)(cchMax), 0L))
#define Edit_GetLineCount(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINECOUNT, 0, 0L))
#define Edit_GetLine(hwndCtl, line, lpch, cchMax) ((*((int FAR*)(lpch)) = (cchMax)), ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINE, (WPARAM)(int)(line), (LPARAM)(LPSTR)(lpch))))
#define Edit_GetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_GETRECT, 0, (LPARAM)(RECT FAR*)(lprc)))
#define Edit_SetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_SETRECT, 0, (LPARAM)(const RECT FAR*)(lprc)))
#define Edit_SetRectNoPaint(hwndCtl, lprc)      ((void)SendMessage((hwndCtl), EM_SETRECTNP, 0, (LPARAM)(const RECT FAR*)(lprc)))
#define Edit_GetSel(hwndCtl)                    ((DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L))
#define Edit_SetSel(hwndCtl, ichStart, ichEnd)  ((void)SendMessage((hwndCtl), EM_SETSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define Edit_ReplaceSel(hwndCtl, lpszReplace)   ((void)SendMessage((hwndCtl), EM_REPLACESEL, 0, (LPARAM)(LPCSTR)(lpszReplace)))
#define Edit_GetModify(hwndCtl)                 ((BOOL)(DWORD)SendMessage((hwndCtl), EM_GETMODIFY, 0, 0L))
#define Edit_SetModify(hwndCtl, fModified)      ((void)SendMessage((hwndCtl), EM_SETMODIFY, (WPARAM)(UINT)(fModified), 0L))
#define Edit_LineFromChar(hwndCtl, ich)         ((int)(DWORD)SendMessage((hwndCtl), EM_LINEFROMCHAR, (WPARAM)(int)(ich), 0L))
#define Edit_LineIndex(hwndCtl, line)           ((int)(DWORD)SendMessage((hwndCtl), EM_LINEINDEX, (WPARAM)(int)(line), 0L))
#define Edit_LineLength(hwndCtl, line)          ((int)(DWORD)SendMessage((hwndCtl), EM_LINELENGTH, (WPARAM)(int)(line), 0L))
#define Edit_Scroll(hwndCtl, dv, dh)            ((void)SendMessage((hwndCtl), EM_LINESCROLL, 0, MAKELPARAM((dv), (dh))))
#define Edit_CanUndo(hwndCtl)                   ((BOOL)(DWORD)SendMessage((hwndCtl), EM_CANUNDO, 0, 0L))
#define Edit_Undo(hwndCtl)                      ((BOOL)(DWORD)SendMessage((hwndCtl), EM_UNDO, 0, 0L))
#define Edit_EmptyUndoBuffer(hwndCtl)           ((void)SendMessage((hwndCtl), EM_EMPTYUNDOBUFFER, 0, 0L))
#define Edit_SetPasswordChar(hwndCtl, ch)       ((void)SendMessage((hwndCtl), EM_SETPASSWORDCHAR, (WPARAM)(UINT)(ch), 0L))
#define Edit_SetTabStops(hwndCtl, cTabs, lpTabs) ((void)SendMessage((hwndCtl), EM_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(const int FAR*)(lpTabs)))
#define Edit_FmtLines(hwndCtl, fAddEOL)         ((BOOL)(DWORD)SendMessage((hwndCtl), EM_FMTLINES, (WPARAM)(BOOL)(fAddEOL), 0L))
#define Edit_GetHandle(hwndCtl)                 ((HLOCAL)(UINT)(DWORD)SendMessage((hwndCtl), EM_GETHANDLE, 0, 0L))
#define Edit_SetHandle(hwndCtl, h)              ((void)SendMessage((hwndCtl), EM_SETHANDLE, (WPARAM)(UINT)(HLOCAL)(h), 0L))
#define Edit_GetFirstVisibleLine(hwndCtl)       ((int)(DWORD)SendMessage((hwndCtl), EM_GETFIRSTVISIBLELINE, 0, 0L))
#define Edit_SetReadOnly(hwndCtl, fReadOnly)    ((BOOL)(DWORD)SendMessage((hwndCtl), EM_SETREADONLY, (WPARAM)(BOOL)(fReadOnly), 0L))
#define Edit_GetPasswordChar(hwndCtl)           ((char)(DWORD)SendMessage((hwndCtl), EM_GETPASSWORDCHAR, 0, 0L))
#define Edit_SetWordBreakProc(hwndCtl, lpfnWordBreak) ((void)SendMessage((hwndCtl), EM_SETWORDBREAKPROC, 0, (LPARAM)(EDITWORDBREAKPROC)(lpfnWordBreak)))
#define Edit_GetWordBreakProc(hwndCtl)          ((EDITWORDBREAKPROC)SendMessage((hwndCtl), EM_GETWORDBREAKPROC, 0, 0L))
#define ListBox_GetCount(hwndCtl)                   ((int)(DWORD)SendMessage((hwndCtl), LB_GETCOUNT, 0, 0L))
#define ListBox_ResetContent(hwndCtl)               ((BOOL)(DWORD)SendMessage((hwndCtl), LB_RESETCONTENT, 0, 0L))
#define ListBox_AddString(hwndCtl, lpsz)            ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0, (LPARAM)(LPCSTR)(lpsz)))
#define ListBox_InsertString(hwndCtl, index, lpsz)  ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpsz)))
#define ListBox_AddItemData(hwndCtl, data)          ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0, (LPARAM)(data)))
#define ListBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_GetTextLen(hwndCtl, index)          ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXTLEN, (WPARAM)(int)(index), 0L))
#define ListBox_GetText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXT, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpszBuffer)))
#define ListBox_GetItemData(hwndCtl, index)         ((LRESULT)(DWORD)SendMessage((hwndCtl), LB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ListBox_SetItemData(hwndCtl, index, data)   ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_FindString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_FindItemData(hwndCtl, indexStart, data) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_SetSel(hwndCtl, fSelect, index)     ((int)(DWORD)SendMessage((hwndCtl), LB_SETSEL, (WPARAM)(BOOL)(fSelect), MAKELPARAM((index), 0)))
#define ListBox_SelItemRange(hwndCtl, fSelect, first, last)    ((int)(DWORD)SendMessage((hwndCtl), LB_SELITEMRANGE, (WPARAM)(BOOL)(fSelect), MAKELPARAM((first), (last))))
#define ListBox_GetCurSel(hwndCtl)                  ((int)(DWORD)SendMessage((hwndCtl), LB_GETCURSEL, 0, 0L))
#define ListBox_SetCurSel(hwndCtl, index)           ((int)(DWORD)SendMessage((hwndCtl), LB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ListBox_SelectString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_SelectItemData(hwndCtl, indexStart, data)   ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_GetSel(hwndCtl, index)              ((int)(DWORD)SendMessage((hwndCtl), LB_GETSEL, (WPARAM)(int)(index), 0L))
#define ListBox_GetSelCount(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELCOUNT, 0, 0L))
#define ListBox_GetTopIndex(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), LB_GETTOPINDEX, 0, 0L))
#define ListBox_GetSelItems(hwndCtl, cItems, lpItems) ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELITEMS, (WPARAM)(int)(cItems), (LPARAM)(int FAR*)(lpItems)))
#define ListBox_SetTopIndex(hwndCtl, indexTop)      ((int)(DWORD)SendMessage((hwndCtl), LB_SETTOPINDEX, (WPARAM)(int)(indexTop), 0L))
#define ListBox_SetColumnWidth(hwndCtl, cxColumn)   ((void)SendMessage((hwndCtl), LB_SETCOLUMNWIDTH, (WPARAM)(int)(cxColumn), 0L))
#define ListBox_GetHorizontalExtent(hwndCtl)        ((int)(DWORD)SendMessage((hwndCtl), LB_GETHORIZONTALEXTENT, 0, 0L))
#define ListBox_SetHorizontalExtent(hwndCtl, cxExtent)     ((void)SendMessage((hwndCtl), LB_SETHORIZONTALEXTENT, (WPARAM)(int)(cxExtent), 0L))
#define ListBox_SetTabStops(hwndCtl, cTabs, lpTabs) ((BOOL)(DWORD)SendMessage((hwndCtl), LB_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(int FAR*)(lpTabs)))
#define ListBox_GetItemRect(hwndCtl, index, lprc)   ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMRECT, (WPARAM)(int)(index), (LPARAM)(RECT FAR*)(lprc)))
#define ListBox_SetCaretIndex(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), LB_SETCARETINDEX, (WPARAM)(int)(index), 0L))
#define ListBox_GetCaretIndex(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), LB_GETCARETINDEX, 0, 0L))
#define ListBox_FindStringExact(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_SetItemHeight(hwndCtl, index, cy)   ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMHEIGHT, (WPARAM)(int)(index), MAKELPARAM((cy), 0)))
#define ListBox_GetItemHeight(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMHEIGHT, (WPARAM)(int)(index), 0L))
#define ListBox_Dir(hwndCtl, attrs, lpszFileSpec)   ((int)(DWORD)SendMessage((hwndCtl), LB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCSTR)(lpszFileSpec)))
#define ComboBox_Enable(hwndCtl, fEnable)       EnableWindow((hwndCtl), (fEnable))
#define ComboBox_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))
#define ComboBox_GetTextLength(hwndCtl)         GetWindowTextLength(hwndCtl)
#define ComboBox_SetText(hwndCtl, lpsz)         SetWindowText((hwndCtl), (lpsz))
#define ComboBox_LimitText(hwndCtl, cchLimit)   ((int)(DWORD)SendMessage((hwndCtl), CB_LIMITTEXT, (WPARAM)(int)(cchLimit), 0L))
#define ComboBox_GetEditSel(hwndCtl)            ((DWORD)SendMessage((hwndCtl), CB_GETEDITSEL, 0, 0L))
#define ComboBox_SetEditSel(hwndCtl, ichStart, ichEnd) ((int)(DWORD)SendMessage((hwndCtl), CB_SETEDITSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define ComboBox_GetCount(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), CB_GETCOUNT, 0, 0L))
#define ComboBox_ResetContent(hwndCtl)          ((int)(DWORD)SendMessage((hwndCtl), CB_RESETCONTENT, 0, 0L))
#define ComboBox_AddString(hwndCtl, lpsz)       ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_InsertString(hwndCtl, index, lpsz) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_AddItemData(hwndCtl, data)     ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(data)))
#define ComboBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_GetLBTextLen(hwndCtl, index)           ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXTLEN, (WPARAM)(int)(index), 0L))
#define ComboBox_GetLBText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXT, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpszBuffer)))
#define ComboBox_GetItemData(hwndCtl, index)        ((LRESULT)(DWORD)SendMessage((hwndCtl), CB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ComboBox_SetItemData(hwndCtl, index, data)  ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_FindString(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ComboBox_FindItemData(hwndCtl, indexStart, data)    ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_GetCurSel(hwndCtl)                 ((int)(DWORD)SendMessage((hwndCtl), CB_GETCURSEL, 0, 0L))
#define ComboBox_SetCurSel(hwndCtl, index)          ((int)(DWORD)SendMessage((hwndCtl), CB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ComboBox_SelectString(hwndCtl, indexStart, lpszSelect)  ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszSelect)))
#define ComboBox_SelectItemData(hwndCtl, indexStart, data)      ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_Dir(hwndCtl, attrs, lpszFileSpec)  ((int)(DWORD)SendMessage((hwndCtl), CB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCSTR)(lpszFileSpec)))
#define ComboBox_ShowDropdown(hwndCtl, fShow)       ((BOOL)(DWORD)SendMessage((hwndCtl), CB_SHOWDROPDOWN, (WPARAM)(BOOL)(fShow), 0L))
#define ComboBox_FindStringExact(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ComboBox_GetDroppedState(hwndCtl)           ((BOOL)(DWORD)SendMessage((hwndCtl), CB_GETDROPPEDSTATE, 0, 0L))
#define ComboBox_GetDroppedControlRect(hwndCtl, lprc) ((void)SendMessage((hwndCtl), CB_GETDROPPEDCONTROLRECT, 0, (LPARAM)(RECT FAR*)(lprc)))
#define ComboBox_GetItemHeight(hwndCtl)             ((int)(DWORD)SendMessage((hwndCtl), CB_GETITEMHEIGHT, 0, 0L))
#define ComboBox_SetItemHeight(hwndCtl, cyItem)     ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMHEIGHT, (WPARAM)(int)(index), 0L))
#define ComboBox_GetExtendedUI(hwndCtl)             ((UINT)(DWORD)SendMessage((hwndCtl), CB_GETEXTENDEDUI, 0, 0L))
#define ComboBox_SetExtendedUI(hwndCtl, flags)      ((int)(DWORD)SendMessage((hwndCtl), CB_SETEXTENDEDUI, (WPARAM)(UINT)(flags), 0L))

// printscan\print\spooler\wpnpinst\wow\inc\prsht.h
#define PSM_GETCURRENTPAGEHWND  (WM_USER + 118)

// printscan\print\spooler\wpnpinst\wow\inc\windowsx.h
#define     SetWindowRedraw(hwnd, fRedraw)  \
                    ((void)SendMessage(hwnd, WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L))
#define     IsRestored(hwnd)    ((GetWindowStyle(hwnd) & (WS_MINIMIZE | WS_MAXIMIZE)) == 0L)
#define     SetWindowFont(hwnd, hfont, fRedraw) FORWARD_WM_SETFONT((hwnd), (hfont), (fRedraw), SendMessage)
#define     GetWindowFont(hwnd)                 FORWARD_WM_GETFONT((hwnd), SendMessage)
#define HANDLE_WM_COMPACTING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_COMPACTING(hwnd, compactRatio, fn) \
    (void)(fn)((hwnd), WM_COMPACTING, (WPARAM)(UINT)(compactRatio), 0L)
#define HANDLE_WM_WININICHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_WININICHANGE(hwnd, lpszSectionName, fn) \
    (void)(fn)((hwnd), WM_WININICHANGE, 0, (LPARAM)(LPCSTR)(lpszSectionName))
#define HANDLE_WM_SYSCOLORCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_SYSCOLORCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_SYSCOLORCHANGE, 0, 0L)
#define HANDLE_WM_QUERYNEWPALETTE(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYNEWPALETTE(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYNEWPALETTE, 0, 0L)
#define HANDLE_WM_PALETTEISCHANGING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTEISCHANGING(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTEISCHANGING, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_PALETTECHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTECHANGED(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTECHANGED, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_FONTCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_FONTCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_FONTCHANGE, 0, 0L)
#define HANDLE_WM_DEVMODECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_DEVMODECHANGE(hwnd, lpszDeviceName, fn) \
    (void)(fn)((hwnd), WM_DEVMODECHANGE, 0,(LPARAM)(LPCSTR)(lpszDeviceName))
#define HANDLE_WM_TIMECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_TIMECHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_TIMECHANGE, 0, 0L)
#define HANDLE_WM_POWER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_POWER(hwnd, code, fn) \
    (void)(fn)((hwnd), WM_POWER, (WPARAM)(code), 0L)
#define HANDLE_WM_QUERYENDSESSION(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYENDSESSION(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYENDSESSION, 0, 0L)
#define HANDLE_WM_ENDSESSION(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENDSESSION(hwnd, fEnding, fn) \
    (void)(fn)((hwnd), WM_ENDSESSION, (WPARAM)(BOOL)(fEnding), 0L)
#define HANDLE_WM_QUIT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_QUIT(hwnd, exitCode, fn) \
    (void)(fn)((hwnd), WM_QUIT, (WPARAM)(exitCode), 0L)
#define HANDLE_WM_SYSTEMERROR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_SYSTEMERROR(hwnd, errCode, fn) \
    (void)(fn)((hwnd), WM_SYSTEMERROR, (WPARAM)(errCode), 0L)
#define HANDLE_WM_CREATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (CREATESTRUCT FAR*)(lParam)) ? 0L : (LRESULT)-1L)
#define FORWARD_WM_CREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_CREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_NCCREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (CREATESTRUCT FAR*)(lParam))
#define FORWARD_WM_NCCREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCCREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_DESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROY, 0, 0L)
#define HANDLE_WM_NCDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_NCDESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_NCDESTROY, 0, 0L)
#define HANDLE_WM_SHOWWINDOW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), LOWORD(lParam)), 0L)
#define HANDLE_WM_SETREDRAW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_SETREDRAW(hwnd, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETREDRAW, (WPARAM)(fRedraw), 0L)
#define HANDLE_WM_ENABLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENABLE(hwnd, fEnable, fn) \
    (void)(fn)((hwnd), WM_ENABLE, (WPARAM)(BOOL)(fEnable), 0L)
#define HANDLE_WM_SETTEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_SETTEXT(hwnd, lpszText, fn) \
    (void)(fn)((hwnd), WM_SETTEXT, 0, (LPARAM)(LPCSTR)(lpszText))
#define HANDLE_WM_GETTEXT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (int)(wParam), (LPSTR)(lParam))
#define FORWARD_WM_GETTEXT(hwnd, cchTextMax, lpszText, fn) \
    (int)(DWORD)(fn)((hwnd), WM_GETTEXT, (WPARAM)(int)(cchTextMax), (LPARAM)(LPSTR)(lpszText))
#define HANDLE_WM_GETTEXTLENGTH(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)(hwnd)
#define FORWARD_WM_GETTEXTLENGTH(hwnd, fn) \
    (int)(DWORD)(fn)((hwnd), WM_GETTEXTLENGTH, 0, 0L)
#define HANDLE_WM_WINDOWPOSCHANGING(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (WINDOWPOS FAR*)(lParam))
#define FORWARD_WM_WINDOWPOSCHANGING(hwnd, lpwpos, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_WINDOWPOSCHANGING, 0, (LPARAM)(WINDOWPOS FAR*)(lpwpos))
#define HANDLE_WM_WINDOWPOSCHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const WINDOWPOS FAR*)(lParam)), 0L)
#define FORWARD_WM_WINDOWPOSCHANGED(hwnd, lpwpos, fn) \
    (void)(fn)((hwnd), WM_WINDOWPOSCHANGED, 0, (LPARAM)(const WINDOWPOS FAR*)(lpwpos))
#define HANDLE_WM_MOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_MOVE(hwnd, x, y, fn) \
    (void)(fn)((hwnd), WM_MOVE, 0, MAKELPARAM((int)(x), (int)(y)))
#define HANDLE_WM_SIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_SIZE(hwnd, state, cx, cy, fn) \
    (void)(fn)((hwnd), WM_SIZE, (WPARAM)(UINT)(state), MAKELPARAM((int)(cx), (int)(cy)))
#define HANDLE_WM_QUERYOPEN(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYOPEN(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYOPEN, 0, 0L)
#define HANDLE_WM_GETMINMAXINFO(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MINMAXINFO FAR*)(lParam)), 0L)
#define FORWARD_WM_GETMINMAXINFO(hwnd, lpMinMaxInfo, fn) \
    (void)(fn)((hwnd), WM_GETMINMAXINFO, 0, (LPARAM)(MINMAXINFO FAR*)(lpMinMaxInfo))
#define HANDLE_WM_PAINT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PAINT(hwnd, fn) \
    (void)(fn)((hwnd), WM_PAINT, 0, 0L)
#define HANDLE_WM_ERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define FORWARD_WM_ERASEBKGND(hwnd, hdc, fn) \
   (BOOL)(DWORD)(fn)((hwnd), WM_ERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define HANDLE_WM_ICONERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define FORWARD_WM_ICONERASEBKGND(hwnd, hdc, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_ICONERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define HANDLE_WM_NCPAINT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HRGN)(wParam)), 0L)
#define FORWARD_WM_NCPAINT(hwnd, hrgn, fn) \
    (void)(fn)((hwnd), WM_NCPAINT, (WPARAM)(HRGN)(hrgn), 0L)
#define HANDLE_WM_NCCALCSIZE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (NCCALCSIZE_PARAMS FAR*)(lParam))
#define FORWARD_WM_NCCALCSIZE(hwnd, fCalcValidRects, lpcsp, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_NCCALCSIZE, (WPARAM)(fCalcValidRects), (LPARAM)(NCCALCSIZE_PARAMS FAR*)(lpcsp))
#define HANDLE_WM_NCHITTEST(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_NCHITTEST(hwnd, x, y, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_NCHITTEST, 0, MAKELPARAM((int)(x), (int)(y)))
#define HANDLE_WM_QUERYDRAGICON(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define FORWARD_WM_QUERYDRAGICON(hwnd, fn) \
    (HICON)(UINT)(DWORD)(fn)((hwnd), WM_QUERYDRAGICON, 0, 0L)
#define HANDLE_WM_DROPFILES(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HDROP)(wParam)), 0L)
#define FORWARD_WM_DROPFILES(hwnd, hdrop, fn) \
    (void)(fn)((hwnd), WM_DROPFILES, (WPARAM)(hdrop), 0L)
#define HANDLE_WM_ACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define FORWARD_WM_ACTIVATE(hwnd, state, hwndActDeact, fMinimized, fn) \
    (void)(fn)((hwnd), WM_ACTIVATE, (WPARAM)(UINT)(state), MAKELPARAM((UINT)(HWND)(hwndActDeact), (UINT)(BOOL)(fMinimized)))
#define HANDLE_WM_ACTIVATEAPP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (HTASK)LOWORD(lParam)), 0L)
#define FORWARD_WM_ACTIVATEAPP(hwnd, fActivate, htaskActDeact, fn) \
    (void)(fn)((hwnd), WM_ACTIVATEAPP, (WPARAM)(BOOL)(fActivate), MAKELPARAM((htaskActDeact),0))
#define HANDLE_WM_NCACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (BOOL)(wParam), (HWND)LOWORD(lParam), (BOOL)HIWORD(lParam))
#define FORWARD_WM_NCACTIVATE(hwnd, fActive, hwndActDeact, fMinimized, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCACTIVATE, (WPARAM)(BOOL)(fActive), MAKELPARAM((UINT)(HWND)(hwndActDeact), (UINT)(BOOL)(fMinimized)))
#define HANDLE_WM_SETFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_SETFOCUS(hwnd, hwndOldFocus, fn) \
    (void)(fn)((hwnd), WM_SETFOCUS, (WPARAM)(HWND)(hwndOldFocus), 0L)
#define HANDLE_WM_KILLFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_KILLFOCUS(hwnd, hwndNewFocus, fn) \
    (void)(fn)((hwnd), WM_KILLFOCUS, (WPARAM)(HWND)(hwndNewFocus), 0L)
#define HANDLE_WM_KEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_KEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_KEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_KEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_CHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_CHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_CHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define HANDLE_WM_DEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_DEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_DEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define HANDLE_WM_SYSKEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSKEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_SYSKEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSKEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_SYSCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_SYSCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define HANDLE_WM_SYSDEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_SYSDEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSDEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define HANDLE_WM_MOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MOUSEMOVE(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MOUSEMOVE, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_LBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_LBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_LBUTTONDBLCLK : WM_LBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_LBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_LBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_LBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_LBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_RBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_RBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_RBUTTONDBLCLK : WM_RBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_RBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_RBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_RBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_RBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_MBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_MBUTTONDBLCLK : WM_MBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_MBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_MBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCMOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMOUSEMOVE(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMOUSEMOVE, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCLBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCLBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCLBUTTONDBLCLK : WM_NCLBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCLBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCLBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCLBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCLBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCRBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCRBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCRBUTTONDBLCLK : WM_NCRBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCRBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCRBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCRBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCRBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCMBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCMBUTTONDBLCLK : WM_NCMBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCMBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCMBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_MOUSEACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))
#define FORWARD_WM_MOUSEACTIVATE(hwnd, hwndTopLevel, codeHitTest, msg, fn) \
    (int)(DWORD)(fn)((hwnd), WM_MOUSEACTIVATE, (WPARAM)(HWND)(hwndTopLevel), MAKELPARAM((codeHitTest), (msg)))
#define HANDLE_WM_CANCELMODE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CANCELMODE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CANCELMODE, 0, 0L)
#define HANDLE_WM_TIMER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_TIMER(hwnd, id, fn) \
    (void)(fn)((hwnd), WM_TIMER, (WPARAM)(UINT)(id), 0L)
#define HANDLE_WM_INITMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam)), 0L)
#define FORWARD_WM_INITMENU(hwnd, hMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENU, (WPARAM)(HMENU)(hMenu), 0L)
#define HANDLE_WM_INITMENUPOPUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam), (int)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define FORWARD_WM_INITMENUPOPUP(hwnd, hMenu, item, fSystemMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENUPOPUP, (WPARAM)(HMENU)(hMenu), MAKELPARAM((item),(fSystemMenu)))
#define HANDLE_WM_MENUSELECT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)HIWORD(lParam), (LOWORD(lParam) & MF_POPUP) ? 0 : (int)(wParam), \
                            (LOWORD(lParam) & MF_POPUP) ? (HMENU)(wParam) : 0, LOWORD(lParam)), 0L)
#define FORWARD_WM_MENUSELECT(hwnd, hmenu, item, hmenuPopup, flags, fn) \
    (void)(fn)((hwnd), WM_MENUSELECT, ((flags) & MF_POPUP) ? (WPARAM)(HMENU)(hmenuPopup) : (WPARAM)(int)(item), MAKELPARAM((flags), (hmenu)))
#define HANDLE_WM_MENUCHAR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam), LOWORD(lParam), (HMENU)HIWORD(lParam));
#define FORWARD_WM_MENUCHAR(hwnd, ch, flags, hmenu, fn) \
    (DWORD)(fn)((hwnd), WM_MENUCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((flags), (UINT)(hmenu)))
#define HANDLE_WM_COMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (HWND)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_COMMAND(hwnd, id, hwndCtl, codeNotify, fn) \
    (void)(fn)((hwnd), WM_COMMAND, (WPARAM)(int)(id), MAKELPARAM((UINT)(hwndCtl), (codeNotify)))
#define HANDLE_WM_HSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)HIWORD(lParam), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_HSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define HANDLE_WM_VSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)HIWORD(lParam), (UINT)(wParam),  (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_VSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define HANDLE_WM_CUT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CUT(hwnd, fn) \
    (void)(fn)((hwnd), WM_CUT, 0, 0L)
#define HANDLE_WM_COPY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_COPY(hwnd, fn) \
    (void)(fn)((hwnd), WM_COPY, 0, 0L)
#define HANDLE_WM_PASTE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PASTE(hwnd, fn) \
    (void)(fn)((hwnd), WM_PASTE, 0, 0L)
#define HANDLE_WM_CLEAR(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CLEAR(hwnd, fn) \
    (void)(fn)((hwnd), WM_CLEAR, 0, 0L)
#define HANDLE_WM_UNDO(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_UNDO(hwnd, fn) \
    (void)(fn)((hwnd), WM_UNDO, 0, 0L)
#define HANDLE_WM_RENDERFORMAT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HANDLE)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_RENDERFORMAT(hwnd, fmt, fn) \
    (HANDLE)(UINT)(DWORD)(fn)((hwnd), WM_RENDERFORMAT, (WPARAM)(UINT)(fmt), 0L)
#define HANDLE_WM_RENDERALLFORMATS(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_RENDERALLFORMATS(hwnd, fn) \
    (void)(fn)((hwnd), WM_RENDERALLFORMATS, 0, 0L)
#define HANDLE_WM_DESTROYCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROYCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROYCLIPBOARD, 0, 0L)
#define HANDLE_WM_DRAWCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DRAWCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DRAWCLIPBOARD, 0, 0L)
#define HANDLE_WM_PAINTCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const PAINTSTRUCT FAR*)GlobalLock((HGLOBAL)LOWORD(lParam))), GlobalUnlock((HGLOBAL)LOWORD(lParam)), 0L)
#define FORWARD_WM_PAINTCLIPBOARD(hwnd, hwndCBViewer, lpPaintStruct, fn) \
    (void)(fn)((hwnd), WM_PAINTCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(lpPaintStruct))
#define HANDLE_WM_SIZECLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const RECT FAR*)GlobalLock((HGLOBAL)LOWORD(lParam))), GlobalUnlock((HGLOBAL)LOWORD(lParam)), 0L)
#define FORWARD_WM_SIZECLIPBOARD(hwnd, hwndCBViewer, lprc, fn) \
    (void)(fn)((hwnd), WM_SIZECLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(lprc))
#define HANDLE_WM_VSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_VSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_HSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_HSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_ASKCBFORMATNAME(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (LPSTR)(lParam)), 0L)
#define FORWARD_WM_ASKCBFORMATNAME(hwnd, cchMax, rgchName, fn) \
    (void)(fn)((hwnd), WM_ASKCBFORMATNAME, (WPARAM)(int)(cchMax), (LPARAM)(rgchName))
#define HANDLE_WM_CHANGECBCHAIN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (HWND)LOWORD(lParam)), 0L)
#define FORWARD_WM_CHANGECBCHAIN(hwnd, hwndRemove, hwndNext, fn) \
    (void)(fn)((hwnd), WM_CHANGECBCHAIN, (WPARAM)(HWND)(hwndRemove), MAKELPARAM((UINT)(hwndNext), 0))
#define HANDLE_WM_SETCURSOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam));
#define FORWARD_WM_SETCURSOR(hwnd, hwndCursor, codeHitTest, msg, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_SETCURSOR, (WPARAM)(HWND)(hwndCursor), MAKELPARAM((codeHitTest), (msg)))
#define HANDLE_WM_SYSCOMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSCOMMAND(hwnd, cmd, x, y, fn) \
    (void)(fn)((hwnd), WM_SYSCOMMAND, (WPARAM)(UINT)(cmd), MAKELPARAM((x), (y)))
#define HANDLE_WM_MDICREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (MDICREATESTRUCT FAR*)(lParam))
#define FORWARD_WM_MDICREATE(hwnd, lpmcs, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDICREATE, 0, (LPARAM)(lpmcs))
#define HANDLE_WM_MDIDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIDESTROY(hwnd, hwndDestroy, fn) \
    (void)(fn)((hwnd), WM_MDIDESTROY, (WPARAM)(hwndDestroy), 0L)
#define HANDLE_WM_MDIACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (HWND)LOWORD(lParam), (HWND)HIWORD(lParam)), 0L)
#define FORWARD_WM_MDIACTIVATE(hwnd, fActive, hwndActivate, hwndDeactivate, fn) \
    (void)(fn)(hwnd, WM_MDIACTIVATE, (WPARAM)(fActive), MAKELPARAM((hwndActivate), (hwndDeactivate)))
#define HANDLE_WM_MDIRESTORE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIRESTORE(hwnd, hwndRestore, fn) \
    (void)(fn)((hwnd), WM_MDIRESTORE, (WPARAM)(hwndRestore), 0L)
#define HANDLE_WM_MDINEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (BOOL)LOWORD(lParam)), 0L)
#define FORWARD_WM_MDINEXT(hwnd, hwndCur, fPrev, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDINEXT, (WPARAM)(hwndCur), MAKELPARAM((fPrev), 0))
#define HANDLE_WM_MDIMAXIMIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIMAXIMIZE(hwnd, hwndMaximize, fn) \
    (void)(fn)((hwnd), WM_MDIMAXIMIZE, (WPARAM)(hwndMaximize), 0L)
#define HANDLE_WM_MDITILE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_MDITILE(hwnd, cmd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_MDITILE, (WPARAM)(cmd), 0L)
#define HANDLE_WM_MDICASCADE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_MDICASCADE(hwnd, cmd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_MDICASCADE, (WPARAM)(cmd), 0L)
#define HANDLE_WM_MDIICONARRANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_MDIICONARRANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_MDIICONARRANGE, 0, 0L)
#define HANDLE_WM_MDIGETACTIVE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define FORWARD_WM_MDIGETACTIVE(hwnd, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDIGETACTIVE, 0, 0L)
#define HANDLE_WM_MDISETMENU(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (HMENU)LOWORD(lParam), (HMENU)HIWORD(lParam))
#define FORWARD_WM_MDISETMENU(hwnd, fRefresh, hmenuFrame, hmenuWindow, fn) \
    (HMENU)(UINT)(DWORD)(fn)((hwnd), WM_MDISETMENU, (WPARAM)(fRefresh), MAKELPARAM((hmenuFrame), (hmenuWindow)))
#define HANDLE_WM_CHILDACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CHILDACTIVATE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CHILDACTIVATE, 0, 0L)
#define HANDLE_WM_NEXTDLGCTL(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HWND)(fn)((hwnd), (HWND)(wParam), (BOOL)LOWORD(lParam))
#define FORWARD_WM_NEXTDLGCTL(hwnd, hwndSetFocus, fNext, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_NEXTDLGCTL, (WPARAM)(HWND)(hwndSetFocus), MAKELPARAM((fNext), 0))
#define HANDLE_WM_PARENTNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_PARENTNOTIFY(hwnd, msg, hwndChild, idChild, fn) \
    (void)(fn)((hwnd), WM_PARENTNOTIFY, (WPARAM)(UINT)(msg), MAKELPARAM((UINT)(HWND)(hwndChild), (UINT)(idChild)))
#define HANDLE_WM_ENTERIDLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam)), 0L)
#define FORWARD_WM_ENTERIDLE(hwnd, source, hwndSource, fn) \
    (void)(fn)((hwnd), WM_ENTERIDLE, (WPARAM)(UINT)(source), MAKELPARAM((UINT)(HWND)(hwndSource), 0))
#define HANDLE_WM_GETDLGCODE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd, (MSG FAR*)(lParam))
#define FORWARD_WM_GETDLGCODE(hwnd, lpmsg, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_GETDLGCODE, (SELECTOROF(lpmsg) ? lpmsg->wParam : 0), (LPARAM)(lpmsg))
#define HANDLE_WM_CTLCOLOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)LOWORD(lParam), (int)(HIWORD(lParam)))
#define FORWARD_WM_CTLCOLOR(hwnd, hdc, hwndChild, type, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLOR, (WPARAM)(HDC)(hdc), MAKELPARAM((UINT)(HWND)(hwndChild), (UINT)(int)(type)))
#define HANDLE_WM_SETFONT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HFONT)(wParam), (BOOL)LOWORD(lParam)), 0L)
#define FORWARD_WM_SETFONT(hwnd, hfont, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETFONT, (WPARAM)(HFONT)(hfont), MAKELPARAM((UINT)(BOOL)(fRedraw), 0))
#define HANDLE_WM_GETFONT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HFONT)(fn)(hwnd)
#define FORWARD_WM_GETFONT(hwnd, fn) \
    (HFONT)(UINT)(DWORD)(fn)((hwnd), WM_GETFONT, 0, 0L)
#define HANDLE_WM_DRAWITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DRAWITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_DRAWITEM(hwnd, lpDrawItem, fn) \
    (void)(fn)((hwnd), WM_DRAWITEM, 0, (LPARAM)(const DRAWITEMSTRUCT FAR*)(lpDrawItem))
#define HANDLE_WM_MEASUREITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MEASUREITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_MEASUREITEM(hwnd, lpMeasureItem, fn) \
    (void)(fn)((hwnd), WM_MEASUREITEM, 0, (LPARAM)(MEASUREITEMSTRUCT FAR*)(lpMeasureItem))
#define HANDLE_WM_COMPAREITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (const COMPAREITEMSTRUCT FAR*)(lParam))
#define FORWARD_WM_COMPAREITEM(hwnd, lpCompareItem, fn) \
    (int)(DWORD)(fn)((hwnd), WM_COMPAREITEM, 0, (LPARAM)(const COMPAREITEMSTRUCT FAR*)(lpCompareItem))
#define HANDLE_WM_VKEYTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_VKEYTOITEM(hwnd, vk, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_VKEYTOITEM, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(hwndListBox), (UINT)(iCaret)))
#define HANDLE_WM_CHARTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_CHARTOITEM(hwnd, ch, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_CHARTOITEM, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(hwndListBox), (UINT)(iCaret)))
#define HANDLE_WM_QUEUESYNC(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_QUEUESYNC(hwnd, fn) \
    (void)(fn)((hwnd), WM_QUEUESYNC, 0, 0L)
#define HANDLE_WM_COMMNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), LOWORD(lParam)), 0L)
#define FORWARD_WM_COMMNOTIFY(hwnd, cid, flags, fn) \
    (void)(fn)((hwnd), WM_COMMNOTIFY, (WPARAM)(cid), MAKELPARAM((flags), 0))
#define Static_SetIcon(hwndCtl, hIcon)          ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_SETICON, (WPARAM)(HICON)(hIcon), 0L))
#define Static_GetIcon(hwndCtl, hIcon)          ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_GETICON, 0, 0L))
#define Button_GetCheck(hwndCtl)            ((int)(DWORD)SendMessage((hwndCtl), BM_GETCHECK, 0, 0L))
#define Button_SetCheck(hwndCtl, check)     ((void)SendMessage((hwndCtl), BM_SETCHECK, (WPARAM)(int)(check), 0L))
#define Button_GetState(hwndCtl)            ((int)(DWORD)SendMessage((hwndCtl), BM_GETSTATE, 0, 0L))
#define Button_SetState(hwndCtl, state)     ((UINT)(DWORD)SendMessage((hwndCtl), BM_SETSTATE, (WPARAM)(int)(state), 0L))
#define Button_SetStyle(hwndCtl, style, fRedraw) ((void)SendMessage((hwndCtl), BM_SETSTYLE, (WPARAM)LOWORD(style), MAKELPARAM(((fRedraw) ? TRUE : FALSE), 0)))
#define Edit_LimitText(hwndCtl, cchMax)         ((void)SendMessage((hwndCtl), EM_LIMITTEXT, (WPARAM)(cchMax), 0L))
#define Edit_GetLineCount(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINECOUNT, 0, 0L))
#define Edit_GetLine(hwndCtl, line, lpch, cchMax) ((*((int FAR*)(lpch)) = (cchMax)), ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINE, (WPARAM)(int)(line), (LPARAM)(LPSTR)(lpch))))
#define Edit_GetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_GETRECT, 0, (LPARAM)(RECT FAR*)(lprc)))
#define Edit_SetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_SETRECT, 0, (LPARAM)(const RECT FAR*)(lprc)))
#define Edit_SetRectNoPaint(hwndCtl, lprc)      ((void)SendMessage((hwndCtl), EM_SETRECTNP, 0, (LPARAM)(const RECT FAR*)(lprc)))
#define Edit_GetSel(hwndCtl)                    ((DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L))
#define Edit_SetSel(hwndCtl, ichStart, ichEnd)  ((void)SendMessage((hwndCtl), EM_SETSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define Edit_ReplaceSel(hwndCtl, lpszReplace)   ((void)SendMessage((hwndCtl), EM_REPLACESEL, 0, (LPARAM)(LPCSTR)(lpszReplace)))
#define Edit_GetModify(hwndCtl)                 ((BOOL)(DWORD)SendMessage((hwndCtl), EM_GETMODIFY, 0, 0L))
#define Edit_SetModify(hwndCtl, fModified)      ((void)SendMessage((hwndCtl), EM_SETMODIFY, (WPARAM)(UINT)(fModified), 0L))
#define Edit_LineFromChar(hwndCtl, ich)         ((int)(DWORD)SendMessage((hwndCtl), EM_LINEFROMCHAR, (WPARAM)(int)(ich), 0L))
#define Edit_LineIndex(hwndCtl, line)           ((int)(DWORD)SendMessage((hwndCtl), EM_LINEINDEX, (WPARAM)(int)(line), 0L))
#define Edit_LineLength(hwndCtl, line)          ((int)(DWORD)SendMessage((hwndCtl), EM_LINELENGTH, (WPARAM)(int)(line), 0L))
#define Edit_Scroll(hwndCtl, dv, dh)            ((void)SendMessage((hwndCtl), EM_LINESCROLL, 0, MAKELPARAM((dv), (dh))))
#define Edit_CanUndo(hwndCtl)                   ((BOOL)(DWORD)SendMessage((hwndCtl), EM_CANUNDO, 0, 0L))
#define Edit_Undo(hwndCtl)                      ((BOOL)(DWORD)SendMessage((hwndCtl), EM_UNDO, 0, 0L))
#define Edit_EmptyUndoBuffer(hwndCtl)           ((void)SendMessage((hwndCtl), EM_EMPTYUNDOBUFFER, 0, 0L))
#define Edit_SetPasswordChar(hwndCtl, ch)       ((void)SendMessage((hwndCtl), EM_SETPASSWORDCHAR, (WPARAM)(UINT)(ch), 0L))
#define Edit_SetTabStops(hwndCtl, cTabs, lpTabs) ((void)SendMessage((hwndCtl), EM_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(const int FAR*)(lpTabs)))
#define Edit_FmtLines(hwndCtl, fAddEOL)         ((BOOL)(DWORD)SendMessage((hwndCtl), EM_FMTLINES, (WPARAM)(BOOL)(fAddEOL), 0L))
#define Edit_GetHandle(hwndCtl)                 ((HLOCAL)(UINT)(DWORD)SendMessage((hwndCtl), EM_GETHANDLE, 0, 0L))
#define Edit_SetHandle(hwndCtl, h)              ((void)SendMessage((hwndCtl), EM_SETHANDLE, (WPARAM)(UINT)(HLOCAL)(h), 0L))
#define Edit_GetFirstVisibleLine(hwndCtl)       ((int)(DWORD)SendMessage((hwndCtl), EM_GETFIRSTVISIBLELINE, 0, 0L))
#define Edit_SetReadOnly(hwndCtl, fReadOnly)    ((BOOL)(DWORD)SendMessage((hwndCtl), EM_SETREADONLY, (WPARAM)(BOOL)(fReadOnly), 0L))
#define Edit_GetPasswordChar(hwndCtl)           ((char)(DWORD)SendMessage((hwndCtl), EM_GETPASSWORDCHAR, 0, 0L))
#define Edit_SetWordBreakProc(hwndCtl, lpfnWordBreak) ((void)SendMessage((hwndCtl), EM_SETWORDBREAKPROC, 0, (LPARAM)(EDITWORDBREAKPROC)(lpfnWordBreak)))
#define Edit_GetWordBreakProc(hwndCtl)          ((EDITWORDBREAKPROC)SendMessage((hwndCtl), EM_GETWORDBREAKPROC, 0, 0L))
#define ListBox_GetCount(hwndCtl)                   ((int)(DWORD)SendMessage((hwndCtl), LB_GETCOUNT, 0, 0L))
#define ListBox_ResetContent(hwndCtl)               ((BOOL)(DWORD)SendMessage((hwndCtl), LB_RESETCONTENT, 0, 0L))
#define ListBox_AddString(hwndCtl, lpsz)            ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0, (LPARAM)(LPCSTR)(lpsz)))
#define ListBox_InsertString(hwndCtl, index, lpsz)  ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpsz)))
#define ListBox_AddItemData(hwndCtl, data)          ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0, (LPARAM)(data)))
#define ListBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_GetTextLen(hwndCtl, index)          ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXTLEN, (WPARAM)(int)(index), 0L))
#define ListBox_GetText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXT, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpszBuffer)))
#define ListBox_GetItemData(hwndCtl, index)         ((LRESULT)(DWORD)SendMessage((hwndCtl), LB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ListBox_SetItemData(hwndCtl, index, data)   ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_FindString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_FindItemData(hwndCtl, indexStart, data) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_SetSel(hwndCtl, fSelect, index)     ((int)(DWORD)SendMessage((hwndCtl), LB_SETSEL, (WPARAM)(BOOL)(fSelect), MAKELPARAM((index), 0)))
#define ListBox_SelItemRange(hwndCtl, fSelect, first, last)    ((int)(DWORD)SendMessage((hwndCtl), LB_SELITEMRANGE, (WPARAM)(BOOL)(fSelect), MAKELPARAM((first), (last))))
#define ListBox_GetCurSel(hwndCtl)                  ((int)(DWORD)SendMessage((hwndCtl), LB_GETCURSEL, 0, 0L))
#define ListBox_SetCurSel(hwndCtl, index)           ((int)(DWORD)SendMessage((hwndCtl), LB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ListBox_SelectString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_SelectItemData(hwndCtl, indexStart, data)   ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_GetSel(hwndCtl, index)              ((int)(DWORD)SendMessage((hwndCtl), LB_GETSEL, (WPARAM)(int)(index), 0L))
#define ListBox_GetSelCount(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELCOUNT, 0, 0L))
#define ListBox_GetTopIndex(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), LB_GETTOPINDEX, 0, 0L))
#define ListBox_GetSelItems(hwndCtl, cItems, lpItems) ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELITEMS, (WPARAM)(int)(cItems), (LPARAM)(int FAR*)(lpItems)))
#define ListBox_SetTopIndex(hwndCtl, indexTop)      ((int)(DWORD)SendMessage((hwndCtl), LB_SETTOPINDEX, (WPARAM)(int)(indexTop), 0L))
#define ListBox_SetColumnWidth(hwndCtl, cxColumn)   ((void)SendMessage((hwndCtl), LB_SETCOLUMNWIDTH, (WPARAM)(int)(cxColumn), 0L))
#define ListBox_GetHorizontalExtent(hwndCtl)        ((int)(DWORD)SendMessage((hwndCtl), LB_GETHORIZONTALEXTENT, 0, 0L))
#define ListBox_SetHorizontalExtent(hwndCtl, cxExtent)     ((void)SendMessage((hwndCtl), LB_SETHORIZONTALEXTENT, (WPARAM)(int)(cxExtent), 0L))
#define ListBox_SetTabStops(hwndCtl, cTabs, lpTabs) ((BOOL)(DWORD)SendMessage((hwndCtl), LB_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(int FAR*)(lpTabs)))
#define ListBox_GetItemRect(hwndCtl, index, lprc)   ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMRECT, (WPARAM)(int)(index), (LPARAM)(RECT FAR*)(lprc)))
#define ListBox_SetCaretIndex(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), LB_SETCARETINDEX, (WPARAM)(int)(index), 0L))
#define ListBox_GetCaretIndex(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), LB_GETCARETINDEX, 0, 0L))
#define ListBox_SetAnchorIndex(hwndCtl, index)      ((void)SendMessage((hwndCtl), LB_SETANCHORINDEX, (WPARAM)(int)(index), 0L))            /* ;Internal */
#define ListBox_GetAnchorIndex(hwndCtl)             ((int)(DWORD)SendMessage((hwndCtl), LB_GETANCHORINDEX, 0, 0L))                        /* ;Internal */
#define ListBox_FindStringExact(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_SetItemHeight(hwndCtl, index, cy)   ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMHEIGHT, (WPARAM)(int)(index), MAKELPARAM((cy), 0)))
#define ListBox_GetItemHeight(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMHEIGHT, (WPARAM)(int)(index), 0L))
#define ListBox_Dir(hwndCtl, attrs, lpszFileSpec)   ((int)(DWORD)SendMessage((hwndCtl), LB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCSTR)(lpszFileSpec)))
#define ListBox_AddFile(hwndCtl, lpszFilename)      ((int)(DWORD)SendMessage((hwndCtl), LB_ADDFILE, 0, (LPARAM)(LPCSTR)(lpszFilename)))    /* ;Internal */
#define ComboBox_Enable(hwndCtl, fEnable)       EnableWindow((hwndCtl), (fEnable))
#define ComboBox_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))
#define ComboBox_GetTextLength(hwndCtl)         GetWindowTextLength(hwndCtl)
#define ComboBox_SetText(hwndCtl, lpsz)         SetWindowText((hwndCtl), (lpsz))
#define ComboBox_LimitText(hwndCtl, cchLimit)   ((int)(DWORD)SendMessage((hwndCtl), CB_LIMITTEXT, (WPARAM)(int)(cchLimit), 0L))
#define ComboBox_GetEditSel(hwndCtl)            ((DWORD)SendMessage((hwndCtl), CB_GETEDITSEL, 0, 0L))
#define ComboBox_SetEditSel(hwndCtl, ichStart, ichEnd) ((int)(DWORD)SendMessage((hwndCtl), CB_SETEDITSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define ComboBox_GetCount(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), CB_GETCOUNT, 0, 0L))
#define ComboBox_ResetContent(hwndCtl)          ((int)(DWORD)SendMessage((hwndCtl), CB_RESETCONTENT, 0, 0L))
#define ComboBox_AddString(hwndCtl, lpsz)       ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_InsertString(hwndCtl, index, lpsz) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_AddItemData(hwndCtl, data)     ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(data)))
#define ComboBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_GetLBTextLen(hwndCtl, index)           ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXTLEN, (WPARAM)(int)(index), 0L))
#define ComboBox_GetLBText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXT, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpszBuffer)))
#define ComboBox_GetItemData(hwndCtl, index)        ((LRESULT)(DWORD)SendMessage((hwndCtl), CB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ComboBox_SetItemData(hwndCtl, index, data)  ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_FindString(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ComboBox_FindItemData(hwndCtl, indexStart, data)    ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_GetCurSel(hwndCtl)                 ((int)(DWORD)SendMessage((hwndCtl), CB_GETCURSEL, 0, 0L))
#define ComboBox_SetCurSel(hwndCtl, index)          ((int)(DWORD)SendMessage((hwndCtl), CB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ComboBox_SelectString(hwndCtl, indexStart, lpszSelect)  ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszSelect)))
#define ComboBox_SelectItemData(hwndCtl, indexStart, data)      ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_Dir(hwndCtl, attrs, lpszFileSpec)  ((int)(DWORD)SendMessage((hwndCtl), CB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCSTR)(lpszFileSpec)))
#define ComboBox_ShowDropdown(hwndCtl, fShow)       ((BOOL)(DWORD)SendMessage((hwndCtl), CB_SHOWDROPDOWN, (WPARAM)(BOOL)(fShow), 0L))
#define ComboBox_FindStringExact(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ComboBox_GetDroppedState(hwndCtl)           ((BOOL)(DWORD)SendMessage((hwndCtl), CB_GETDROPPEDSTATE, 0, 0L))
#define ComboBox_GetDroppedControlRect(hwndCtl, lprc) ((void)SendMessage((hwndCtl), CB_GETDROPPEDCONTROLRECT, 0, (LPARAM)(RECT FAR*)(lprc)))
#define ComboBox_GetItemHeight(hwndCtl)             ((int)(DWORD)SendMessage((hwndCtl), CB_GETITEMHEIGHT, 0, 0L))
#define ComboBox_SetItemHeight(hwndCtl, cyItem)     ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMHEIGHT, (WPARAM)(int)(index), 0L))
#define ComboBox_GetExtendedUI(hwndCtl)             ((UINT)(DWORD)SendMessage((hwndCtl), CB_GETEXTENDEDUI, 0, 0L))
#define ComboBox_SetExtendedUI(hwndCtl, flags)      ((int)(DWORD)SendMessage((hwndCtl), CB_SETEXTENDEDUI, (WPARAM)(UINT)(flags), 0L))

// printscan\ui\camdlg\camdlg.cpp
#define ListView_SetExtendedListViewStyleEx( h, m, s )

// printscan\ui\compstui\apilayer.h
#define SET_APPLY_BUTTON(pTVWnd, hDlg)                                      \
{                                                                           \
    if (!(*((pTVWnd)->pRootFlags) & CPF_NO_APPLY_BUTTON)) {                 \
                                                                            \
        if (CountRevertOptItem((pTVWnd),                                    \
                               NULL,                                        \
                               TreeView_GetRoot((pTVWnd)->hWndTV),          \
                               0)) {                                        \
                                                                            \
            PropSheet_Changed(GetParent(hDlg), hDlg);                       \
                                                                            \
        } else {                                                            \
                                                                            \
            PropSheet_UnChanged(GetParent(hDlg), hDlg);                     \
        }                                                                   \
    }                                                                       \
}

// printscan\ui\printui\browse.hxx
#define GET_BROWSE_DLG_DATA(hwnd) \
    reinterpret_cast<PBROWSE_DLG_DATA>(GetWindowLongPtr(hwnd, GWLP_USERDATA))
#define SET_BROWSE_DLG_DATA(hwnd, pBrowseDlgData) \
    SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<ULONG_PTR>(pBrowseDlgData))

// printscan\ui\printui\forms.hxx
#define SETUNITS( hwnd, fMetric )                                               \
        CheckRadioButton( hwnd, IDD_FM_RB_METRIC, IDD_FM_RB_ENGLISH,                \
                      ( (fMetric) ? IDD_FM_RB_METRIC : IDD_FM_RB_ENGLISH ) )

// public\ddk\inc\ndis.h
#define PCI_CONFIGURATION_TYPE(PciData) \
    (((PPCI_COMMON_CONFIG)(PciData))->HeaderType & ~PCI_MULTIFUNCTION)
#define PCI_MULTIFUNCTION_DEVICE(PciData) \
    ((((PPCI_COMMON_CONFIG)(PciData))->HeaderType & PCI_MULTIFUNCTION) != 0)

// public\ddk\inc\ntddk.h
#define IRP_MN_COMPLETE_MDL             (IRP_MN_COMPLETE | IRP_MN_MDL)
#define IRP_MN_COMPLETE_MDL_DPC         (IRP_MN_COMPLETE_MDL | IRP_MN_DPC)
#define PCI_CONFIGURATION_TYPE(PciData) \
    (((PPCI_COMMON_CONFIG)(PciData))->HeaderType & ~PCI_MULTIFUNCTION)
#define PCI_MULTIFUNCTION_DEVICE(PciData) \
    ((((PPCI_COMMON_CONFIG)(PciData))->HeaderType & PCI_MULTIFUNCTION) != 0)

// public\ddk\inc\ntddpcm.h
#define PcmciaClassFromControllerType(type) ((PCMCIA_CONTROLLER_CLASS)((type) & 0xff))

// public\ddk\inc\sti.h
#define IStiDevice_Release(p)                   (p)->lpVtbl->Release(p)

// public\ddk\inc\stiusd.h
#define IStiDeviceControl_Release(p)               (p)->lpVtbl->Release(p)
#define IStiUSD_Release(p)               (p)->lpVtbl->Release(p)

// public\ddk\inc\wdm\usbdlib.h
#define UsbBuildSelectInterfaceRequest(urb, \
                                      length, \
                                      configurationHandle, \
                                      interfaceNumber, \
                                      alternateSetting) { \
            (urb)->UrbHeader.Function =  URB_FUNCTION_SELECT_INTERFACE; \
            (urb)->UrbHeader.Length = (length); \
            (urb)->UrbSelectInterface.Interface.AlternateSetting = (alternateSetting); \
            (urb)->UrbSelectInterface.Interface.InterfaceNumber = (interfaceNumber); \
            (urb)->UrbSelectInterface.ConfigurationHandle = (configurationHandle);    }

// public\ddk\inc\wdm\wdm.h
#define PCI_CONFIGURATION_TYPE(PciData) \
    (((PPCI_COMMON_CONFIG)(PciData))->HeaderType & ~PCI_MULTIFUNCTION)
#define PCI_MULTIFUNCTION_DEVICE(PciData) \
    ((((PPCI_COMMON_CONFIG)(PciData))->HeaderType & PCI_MULTIFUNCTION) != 0)

// public\halkit\inc\nthal.h
#define IRP_MN_COMPLETE_MDL             (IRP_MN_COMPLETE | IRP_MN_MDL)
#define IRP_MN_COMPLETE_MDL_DPC         (IRP_MN_COMPLETE_MDL | IRP_MN_DPC)

// public\ifskit\inc\ntifs.h
#define IRP_MN_COMPLETE_MDL             (IRP_MN_COMPLETE | IRP_MN_MDL)
#define IRP_MN_COMPLETE_MDL_DPC         (IRP_MN_COMPLETE_MDL | IRP_MN_DPC)

// public\internal\com\inc\corhdr.h
#define IsTdSealed(x)                       ((x) & tdSealed)
#define IsTdEnum(x)                         ((x) & tdEnum)
#define IsTdSpecialName(x)                  ((x) & tdSpecialName)
#define IsTdImport(x)                       ((x) & tdImport)
#define IsTdSerializable(x)                 ((x) & tdSerializable)
#define IsTdLateInit(x)                     ((x) &tdLateInit)
#define IsTdRTSpecialName(x)                ((x) & tdRTSpecialName)
#define IsMdStatic(x)                       ((x) & mdStatic)
#define IsMdFinal(x)                        ((x) & mdFinal)
#define IsMdVirtual(x)                      ((x) & mdVirtual)
#define IsMdSpecialName(x)                  ((x) & mdSpecialName)
#define IsMdUnmanagedExport(x)              ((x) & mdUnmanagedExport)
#define IsMdRTSpecialName(x)                ((x) & mdRTSpecialName)
#define IsFdStatic(x)                       ((x) & fdStatic)
#define IsFdInitOnly(x)                     ((x) & fdInitOnly)
#define IsFdLiteral(x)                      ((x) & fdLiteral)
#define IsFdNotSerialized(x)                ((x) & fdNotSerialized)
#define IsFdSpecialName(x)                  ((x) & fdSpecialName)
#define IsFdRTSpecialName(x)                ((x) & fdRTSpecialName)
#define IsFdHasDefault(x)                   ((x) & fdHasDefault)
#define IsPdIn(x)                           ((x) & pdIn)
#define IsPdOut(x)                          ((x) & pdOut)
#define IsPdLcid(x)                         ((x) & pdLcid)
#define IsPdRetval(x)                       ((x) & pdRetval)
#define IsPdOptional(x)                     ((x) & pdOptional)
#define IsPdHasDefault(x)                   ((x) & pdHasDefault)
#define IsPrSpecialName(x)                  ((x) & prSpecialName)
#define IsPrRTSpecialName(x)                ((x) & prRTSpecialName)
#define IsPrHasDefault(x)                   ((x) & prHasDefault)
#define IsEvSpecialName(x)                  ((x) & evSpecialName)
#define IsEvRTSpecialName(x)                ((x) & evRTSpecialName)
#define IsMsSetter(x)                       ((x) & msSetter)
#define IsMsGetter(x)                       ((x) & msGetter)
#define IsMsOther(x)                        ((x) & msOther)
#define IsMsAddOn(x)                        ((x) & msAddOn)
#define IsMsRemoveOn(x)                     ((x) & msRemoveOn)
#define IsMsFire(x)                         ((x) & msFire)
#define IsMiForwardRef(x)                   ((x) & miForwardRef)
#define IsMiOLE(x)                          ((x) & miOLE)
#define IsMiInternalCall(x)                 ((x) & miInternalCall)
#define IsMiSynchronized(x)                 ((x) & miSynchronized)
#define IsPmNoMangle(x)                     ((x) & pmNoMangle)
#define IsPmPinvokeOLE(x)                   ((x) & pmPinvokeOLE)
#define IsPmSupportsLastError(x)            ((x) & pmSupportsLastError)
#define IsAfImplicitComTypes(x)             ((x) & afImplicitComTypes)
#define IsAfImplicitResources(x)            ((x) & afImplicitResources)
#define IsFfWriteable(x)                    ((x) & ffWriteable)
#define RidToToken(rid,tktype) ((rid) |= (tktype))
#define TokenFromRid(rid,tktype) ((rid) | (tktype))
#define RidFromToken(tk) ((RID) ((tk) & 0x00ffffff))

// public\internal\ds\inc\crypto\bignum.h
#define COMPILER_NAME  ( \
        COMPILER == COMPILER_GCC ? "GCC compiler" \
      : COMPILER == COMPILER_VC  ? "Microsoft Visual C++ compiler" \
      : "Unknown compiler")

// public\internal\ds\inc\fpnwcomm.h
#define NCP_WELL_KNOWN_RID(rid)                     (0xD1000000 | (rid))

// public\internal\multimedia\inc\ddrawpr.h
#define VALID_HWND_PTR( ptr ) \
        (!IsBadWritePtr( (LPVOID) ptr, sizeof( HWND )) )

// public\internal\net\inc\icanon.h
#define ITYPE_SYS_COMM          (ITYPE_SYS|0x400)
#define   ITYPE_UNC_COMPNAME    (ITYPE_UNC|ITYPE_COMPNAME)
#define   ITYPE_UNC_WC          (ITYPE_UNC|ITYPE_COMPNAME|ITYPE_WILD)
#define   ITYPE_PATH_SYS_COMM   (ITYPE_PATH_SYS|ITYPE_SYS_COMM)
#define   ITYPE_PATH_SYS_COMM_M (ITYPE_PATH_SYS|ITYPE_SYS_COMM|ITYPE_META)
#define   ITYPE_DEVICE_COM      (ITYPE_DEVICE|ITYPE_COM)

// public\internal\net\inc\isnkrnl.h
#define MSPX_SETWINDOWCARD (I_MSPX | 106) /* Set window size for card     */
#define MSPX_SETWINDOWSOCK (I_MSPX | 107) /* Set window size for 1 socket */

// public\internal\net\inc\winsintf.h
#define  WINS_ALL_ACCESS	(STANDARD_RIGHTS_REQUIRED | \
				  WINS_CONTROL_ACCESS |WINS_QUERY_ACCESS)

// public\internal\shell\inc\cmnquryp.h
#define CQFWM_ADDSCOPE (WM_USER+256)
#define CQFWM_GETFRAME (WM_USER+257)
#define CQFWM_ALLSCOPESADDED (WM_USER+258)
#define CQFWM_STARTQUERY (WM_USER+259)
#define CQFWM_SETDEFAULTFOCUS (WM_USER+260)

// public\internal\shell\inc\comctrlp.h
#define TB_SETBUTTONTYPE        (WM_USER + 34)
#define TB_GETIDEALSIZE         (WM_USER + 99)  // wParam == fHeight, lParam = psize
#define TB_SETDROPDOWNGAP       (WM_USER + 100)
#define RB_GETBANDINFOOLD (WM_USER +  5)  //
#define RB_GETOBJECT    (WM_USER +  15) //
#define RB_PRIV_RESIZE   (WM_USER + 33)   //
#define RB_PRIV_DODELAYEDSTUFF (WM_USER+36)  // Private to delay doing toolbar stuff
#define SB_SETBORDERS           (WM_USER+5)
#define BL_ADDBUTTON            (WM_USER+1)
#define BL_GETCARETINDEX        (WM_USER+3)
#define BL_GETCURSEL            (WM_USER+5)
#define BL_GETITEMDATA          (WM_USER+6)
#define BL_GETTOPINDEX          (WM_USER+10)
#define BL_INSERTBUTTON         (WM_USER+11)
#define BL_RESETCONTENT         (WM_USER+12)
#define BL_SETCARETINDEX        (WM_USER+13)
#define BL_SETCURSEL            (WM_USER+14)
#define BL_SETITEMDATA          (WM_USER+15)
#define BL_SETTOPINDEX          (WM_USER+16)
#define ListView_GetHotlightColor(hwndLV)\
        (COLORREF)SNDMSG((hwndLV), LVM_GETHOTLIGHTCOLOR, 0, 0)
#define ListView_SetHotlightColor(hwndLV, clrHotlight)\
        (BOOL)SNDMSG((hwndLV), LVM_SETHOTLIGHTCOLOR, 0,  (LPARAM)(clrHotlight))
#define ListView_KeyboardSelected(hwnd, i) \
    (BOOL)SNDMSG((hwnd), LVM_KEYBOARDSELECTED, (WPARAM)(i), 0)
#define ListView_IsItemVisible(hwnd, index) \
    (UINT)SNDMSG((hwnd), LVM_ISITEMVISIBLE, (WPARAM)index, (LPARAM)0)
#define ListView_SetLVRangeObject(hwndLV, iWhich, pilvRange)\
        (BOOL)SNDMSG((hwndLV), LVM_SETLVRANGEOBJECT, (WPARAM)(iWhich),  (LPARAM)(pilvRange))
#define ListView_ResetEmptyText(hwndLV)\
        (BOOL)SNDMSG((hwndLV), LVM_RESETEMPTYTEXT, 0, 0)
#define ListView_GetFrozenItem(hwndLV)\
        (int)SNDMSG((hwndLV), LVM_GETFROZENITEM, 0, 0)
#define ListView_GetFrozenSlot(hwndLV, lpRect)\
        (BOOL)SNDMSG((hwndLV), LVM_GETFROZENSLOT, (WPARAM)(0), (LPARAM)(lpRect))
#define ListView_SetViewMargins(hwndLV, lpRect)\
        (BOOL)SNDMSG((hwndLV), LVM_SETVIEWMARGINS, (WPARAM)(0), (LPARAM)(lpRect))
#define ListView_GetViewMargins(hwndLV, lpRect)\
        (BOOL)SNDMSG((hwndLV), LVM_SETVIEWMARGINS, (WPARAM)(0), (LPARAM)(lpRect))
#define TreeView_SetBorder(hwnd,  dwFlags, xBorder, yBorder) \
    (int)SNDMSG((hwnd), TVM_SETBORDER, (WPARAM)(dwFlags), MAKELPARAM(xBorder, yBorder))
#define TreeView_GetBorder(hwnd) \
    (int)SNDMSG((hwnd), TVM_GETBORDER, 0, 0)
#define TreeView_SetExtendedStyle(hwnd, dw, mask) \
    (DWORD)SNDMSG((hwnd), TVM_SETEXTENDEDSTYLE, mask, dw)
#define TreeView_GetExtendedStyle(hwnd) \
    (DWORD)SNDMSG((hwnd), TVM_GETEXTENDEDSTYLE, 0, 0)
#define TabCtrl_GetBkColor(hwnd)  (COLORREF)SNDMSG((hwnd), TCM_GETBKCOLOR, 0, 0L)
#define TabCtrl_SetBkColor(hwnd, clrBk)  (BOOL)SNDMSG((hwnd), TCM_SETBKCOLOR, 0, (LPARAM)(COLORREF)(clrBk))
#define TabCtrl_GetObject(hwnd, piid, ppv) \
        (DWORD)SNDMSG((hwnd), TCM_GETOBJECT, (WPARAM)(piid), (LPARAM)(ppv))

// public\internal\shell\inc\cscuiext.h
#define STWM_CSCNETUP                   (WM_USER + 209)
#define STWM_CSCQUERYNETDOWN            (WM_USER + 210)
#define STWM_CSCNETDOWN                 (WM_USER + 213)
#define STWM_CACHE_CORRUPTED            (WM_USER + 214)
#define CSCWM_DONESYNCING               (WM_USER + 300)
#define CSCWM_RECONNECT                 (WM_USER + 302)
#define CSCWM_SYNCHRONIZE               (WM_USER + 303)
#define CSCWM_ISSERVERBACK              (WM_USER + 304)
#define CSCWM_VIEWFILES                 (WM_USER + 305)
#define CSCWM_SETTINGS                  (WM_USER + 306)

// public\internal\shell\inc\pif.h
#define FNT_DEFAULT             (FNT_BOTHFONTS | FNT_AUTOSIZE)
#define FNT_BOTHFONTS           (FNT_RASTERFONTS | FNT_TTFONTS)
#define WIN_DEFAULT             (WIN_SAVESETTINGS | WIN_TOOLBAR)

// public\internal\shell\inc\prshtp.h
#define PSM_DISABLEAPPLY        (WM_USER + 122)
#define PropSheet_DisableApply(hDlg) \
        SendMessage(hDlg, PSM_DISABLEAPPLY, 0, 0L)
#define PSM_ENABLEAPPLY         (WM_USER + 123)
#define PropSheet_EnableApply(hDlg) \
        SendMessage(hDlg, PSM_ENABLEAPPLY, 0, 0L)

// public\internal\shell\inc\shlobjp.h
#define FileCabinet_GetSetCurrentInfo(_hwnd, _bSet, _lpfs) \
             SendMessage(_hwnd, CWM_GETSETCURRENTINFO, (WPARAM)(_bSet), (LPARAM)(LPFOLDERSETTINGS)_lpfs)
#define FileCabinet_SelectItem(_hwnd, _sel, _item) \
            SendMessage(_hwnd, CWM_SELECTITEM, _sel, (LPARAM)(LPCITEMIDLIST)(_item))
#define FileCabinet_SelectPath(_hwnd, _sel, _path)  \
            SendMessage(_hwnd, CWM_SELECTPATH, _sel, (LPARAM)(LPCSTR)(_path))
#define FileCabinet_GetIShellBrowser(_hwnd)     \
            (IShellBrowser*)SendMessage(_hwnd, CWM_GETISHELLBROWSER, 0, 0L)
#define INSTRUMENT_WNDPROC(t,h,u,w,l)                           \
{                                                               \
    SHCNF_INSTRUMENT_INFO s;                                    \
    s.dwEventType=(t);                                          \
    s.dwEventStructure=SHCNFI_EVENT_WNDPROC;                    \
    s.e.wndproc.hwnd=(h);                                       \
    s.e.wndproc.uMsg=(u);                                       \
    s.e.wndproc.wParam=(w);                                     \
    s.e.wndproc.lParam=(l);                                     \
    SHChangeNotify(SHCNE_INSTRUMENT,SHCNF_INSTRUMENT,&s,NULL);  \
}
#define INSTRUMENT_WNDPROC_HOOK(h,u,w,l)                        \
{                                                               \
    SHCNF_INSTRUMENT_INFO s;                                    \
    s.dwEventType=0;                                            \
    s.dwEventStructure=SHCNFI_EVENT_WNDPROC_HOOK;               \
    s.e.wndproc.hwnd=(h);                                       \
    s.e.wndproc.uMsg=(u);                                       \
    s.e.wndproc.wParam=(w);                                     \
    s.e.wndproc.lParam=(l);                                     \
    SHChangeNotify(SHCNE_INSTRUMENT,SHCNF_INSTRUMENT,&s,NULL);  \
}
#define INSTRUMENT_ONCOMMAND(t,h,u)                             \
{                                                               \
    SHCNF_INSTRUMENT_INFO s;                                    \
    s.dwEventType=(t);                                          \
    s.dwEventStructure=SHCNFI_EVENT_ONCOMMAND;                  \
    s.e.command.hwnd=(h);                                       \
    s.e.command.idCmd=(u);                                      \
    SHChangeNotify(SHCNE_INSTRUMENT,SHCNF_INSTRUMENT,&s,NULL);  \
}
#define INSTRUMENT_INVOKECOMMAND(t,h,u)                         \
{                                                               \
    SHCNF_INSTRUMENT_INFO s;                                    \
    s.dwEventType=(t);                                          \
    s.dwEventStructure=SHCNFI_EVENT_INVOKECOMMAND;              \
    s.e.command.hwnd=(h);                                       \
    s.e.command.idCmd=(u);                                      \
    SHChangeNotify(SHCNE_INSTRUMENT,SHCNF_INSTRUMENT,&s,NULL);  \
}
#define INSTRUMENT_TRACKPOPUPMENU(t,h,u)                        \
{                                                               \
    SHCNF_INSTRUMENT_INFO s;                                    \
    s.dwEventType=(t);                                          \
    s.dwEventStructure=SHCNFI_EVENT_TRACKPOPUPMENU;             \
    s.e.command.hwnd=(h);                                       \
    s.e.command.idCmd=(u);                                      \
    SHChangeNotify(SHCNE_INSTRUMENT,SHCNF_INSTRUMENT,&s,NULL);  \
}
#define INSTRUMENT_DROP(t,h,u,p)                                \
{                                                               \
    SHCNF_INSTRUMENT_INFO s;                                    \
    s.dwEventType=(t);                                          \
    s.dwEventStructure=SHCNFI_EVENT_DROP;                       \
    s.e.drop.hwnd=(h);                                          \
    s.e.drop.idCmd=(u);                                         \
    SHChangeNotify(SHCNE_INSTRUMENT,SHCNF_INSTRUMENT,&s,NULL);  \
}
#define OCHost_QueryInterface(hwndOCH, riid, ppv) \
{ QIMSG qimsg = {&riid, ppv}; \
  SNDMSG((hwndOCH), OCM_QUERYINTERFACE, (WPARAM)sizeof(qimsg), (LPARAM)&qimsg); \
}
#define ShellFolderView_GetAnchorPoint(_hwnd, _fStart, _ppt) \
        (BOOL)((_fStart) ? ShellFolderView_GetDragPoint(_hwnd, _ppt) : ShellFolderView_GetDropPoint(_hwnd, _ppt))
#define ShellFolderView_RefreshAll(_hwnd) \
        (LPARAM)PostMessage(_hwnd, WM_KEYDOWN, (WPARAM)VK_F5, (LPARAM)0);

// public\internal\shell\inc\shlwapip.h
#define PFOPEX_DEFAULT     (PFOPEX_CMD | PFOPEX_COM | PFOPEX_BAT | PFOPEX_PIF | PFOPEX_EXE | PFOPEX_LNK)
    #define IsExecForward(pguidCmdGroup, nCmdID) \
        IsQSForward(pguidCmdGroup, 1, (OLECMD *) &nCmdID)

// public\internal\windows\inc\ddemlp.h
#define     ST_FREE_CONV_RES_NOW    0x0800  // See FreeConversationResources()
#define UM_REGISTER         (WM_USER + 200)
#define UM_UNREGISTER       (WM_USER + 201)

// public\internal\windows\inc\ddetrack.h
#define FAIL_POST       0       // return values from DDETrackPostHook()

// public\internal\windows\inc\ddmc.h
#define IVideoAccelerator_Release(p)                 (p)->lpVtbl->Release(p)

// public\internal\windows\inc\duser\duiaccessibility.h
#define SUPPRESS(ClassName) \
private: \
ClassName(const ClassName & copy); \
ClassName & operator=(const ClassName & rhs); \
public:

// public\internal\windows\inc\duser\duielement.h
#define NAV_UP         (NAV_RELATIVE | NAV_VERTICAL)
#define NAV_DOWN       (NAV_RELATIVE | NAV_VERTICAL | NAV_FORWARD)
#define NAV_RIGHT      (NAV_RELATIVE | NAV_FORWARD)
#define AE_MouseAndKeyboard     (AE_Mouse | AE_Keyboard)

// public\internal\windows\inc\duser\dusercore.h
#define IGTM_NONE               (0)     // | No special threading model
#define IGTM_SINGLE             (1)     // | Single threaded application
#define IGMM_COMPATIBLE         (1)     // | Core running in Compatible mode
#define IGMM_ADVANCED           (2)     // | Core running in Advanced mode
#define IGPM_BLEND              (0)     // | Optimize for blend between speed / size
#define IGPM_SPEED              (1)     // | Optimize for pure speed
#define GMODIFIER_CONTROL   (GMODIFIER_LCONTROL | GMODIFIER_RCONTROL)
#define GMODIFIER_ALT       (GMODIFIER_LALT     | GMODIFIER_RALT)

// public\internal\windows\inc\immp.h
#define SCS_CHANGEATTR                  (GCS_COMPREADATTR|GCS_COMPATTR)
#define SCS_CHANGECLAUSE                (GCS_COMPREADCLAUSE|GCS_COMPCLAUSE)

// public\internal\windows\inc\winconp.h
#define CM_PROPERTIES_START          (WM_USER+200)
#define CM_PROPERTIES_UPDATE         (WM_USER+201)
#define CM_PROPERTIES_END            (WM_USER+202)

// public\internal\windows\inc\winuserp.h
#define DC_NC               (DC_CAPTION | DC_FRAME)
#define PM_VALID           (PM_NOREMOVE | \
                            PM_REMOVE   | \
                            PM_NOYIELD  | \
                            PM_QS_INPUT | \
                            PM_QS_POSTMESSAGE | \
                            PM_QS_PAINT | \
                            PM_QS_SENDMESSAGE)
#define BSF_ASYNC               (BSF_POSTMESSAGE | BSF_SENDNOTIFYMESSAGE)
#define SWP_NOCHANGE        (SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOCLIENTSIZE | SWP_NOCLIENTMOVE)
#define QS_VALID           (QS_KEY           | \
                            QS_MOUSEMOVE     | \
                            QS_MOUSEBUTTON   | \
                            QS_POSTMESSAGE   | \
                            QS_TIMER         | \
                            QS_PAINT         | \
                            QS_SENDMESSAGE   | \
                            QS_TRANSFER      | \
                            QS_HOTKEY        | \
                            QS_ALLPOSTMESSAGE| \
                            QS_RAWINPUT)
#define QS_EVENTSET        (QS_EVENT | QS_SENDMESSAGE)
#define WHF_ALL                 (WHF_DESKTOP | WHF_SHAREDHEAP | WHF_CSRSS)

// public\oak\inc\ddrawi.h
#define ADDREFTRACK(pInt)           AddRefTrack(&pInt)

// public\oak\inc\immdev.h
#define SCS_CHANGEATTR                  (GCS_COMPREADATTR|GCS_COMPATTR)
#define SCS_CHANGECLAUSE                (GCS_COMPREADCLAUSE|GCS_COMPCLAUSE)

// public\sdk\amovie\inc\amfilter.h
#define QueryFilterInfoReleaseGraph(fi) if ((fi).pGraph) (fi).pGraph->Release();
#define QueryPinInfoReleaseFilter(pi) if ((pi).pFilter) (pi).pFilter->Release();

// public\sdk\inc16\windows.h
#define GHND                (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define LHND                (LMEM_MOVEABLE | LMEM_ZEROINIT)
#define QS_MOUSE        (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#define SWP_NOCHANGE        (SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | /* ;Internal */ \
                            SWP_NOCLIENTSIZE | SWP_NOCLIENTMOVE)      /* ;Internal */
#define WVR_REDRAW          (WVR_HREDRAW | WVR_VREDRAW)
#define DM_GETDEFID         (WM_USER+0)
#define DM_SETDEFID         (WM_USER+1)
#define STM_SETICON         (WM_USER+0)
#define STM_GETICON         (WM_USER+1)
#define BM_SETSTYLE         (WM_USER+4)
#define EM_GETSEL               (WM_USER+0)
#define EM_SETSEL               (WM_USER+1)
#define EM_SCROLL               (WM_USER+5)     /* ;Internal */
#define EM_LINESCROLL           (WM_USER+6)
#define EM_GETMODIFY            (WM_USER+8)
#define EM_SETMODIFY            (WM_USER+9)
#define EM_GETLINECOUNT         (WM_USER+10)
#define EM_LINEINDEX            (WM_USER+11)
#define EM_SETHANDLE            (WM_USER+12)
#define EM_GETHANDLE            (WM_USER+13)
#define EM_GETTHUMB             (WM_USER+14)    /* ;Internal */
#define EM_LINELENGTH           (WM_USER+17)
#define EM_REPLACESEL           (WM_USER+18)
#define EM_SETFONT              (WM_USER+19)    /* NOT IMPLEMENTED: use WM_SETFONT */
#define EM_GETLINE              (WM_USER+20)
#define EM_CANUNDO              (WM_USER+22)
#define EM_UNDO                 (WM_USER+23)
#define EM_FMTLINES             (WM_USER+24)
#define EM_SETTABSTOPS          (WM_USER+27)
#define EM_GETFIRSTVISIBLELINE  (WM_USER+30)
#define EM_SETREADONLY          (WM_USER+31)
#define LBS_STANDARD          (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)
#define LB_RESETCONTENT        (WM_USER+5)
#define LB_SETSEL              (WM_USER+6)
#define LB_SETCURSEL           (WM_USER+7)
#define LB_GETSEL              (WM_USER+8)
#define LB_GETCURSEL           (WM_USER+9)
#define LB_GETCOUNT            (WM_USER+12)
#define LB_DIR                 (WM_USER+14)
#define LB_GETTOPINDEX         (WM_USER+15)
#define LB_GETSELCOUNT         (WM_USER+17)
#define LB_GETSELITEMS         (WM_USER+18)
#define LB_SETTABSTOPS         (WM_USER+19)
#define LB_GETHORIZONTALEXTENT (WM_USER+20)
#define LB_SETHORIZONTALEXTENT (WM_USER+21)
#define LB_SETCOLUMNWIDTH      (WM_USER+22)
#define LB_ADDFILE             (WM_USER+23)     /* ;Internal */
#define LB_SETTOPINDEX         (WM_USER+24)
#define LB_GETITEMDATA         (WM_USER+26)
#define LB_SETITEMDATA         (WM_USER+27)
#define LB_SETANCHORINDEX      (WM_USER+29)     /* ;Internal */
#define LB_GETANCHORINDEX      (WM_USER+30)     /* ;Internal */
#define LB_SETCARETINDEX       (WM_USER+31)
#define LB_GETCARETINDEX       (WM_USER+32)
#define LB_SETITEMHEIGHT       (WM_USER+33)
#define LB_GETITEMHEIGHT       (WM_USER+34)

// public\sdk\inc16\windowsx.h
#define     SetWindowRedraw(hwnd, fRedraw)  \
                    ((void)SendMessage(hwnd, WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L))
#define     SetWindowFont(hwnd, hfont, fRedraw) FORWARD_WM_SETFONT((hwnd), (hfont), (fRedraw), SendMessage)
#define     GetWindowFont(hwnd)                 FORWARD_WM_GETFONT((hwnd), SendMessage)
#define HANDLE_MSG(hwnd, message, fn)    \
    case (message): return HANDLE_##message((hwnd), (wParam), (lParam), (fn))
#define HANDLE_WM_COMPACTING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_COMPACTING(hwnd, compactRatio, fn) \
    (void)(fn)((hwnd), WM_COMPACTING, (WPARAM)(UINT)(compactRatio), 0L)
#define HANDLE_WM_FONTCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_FONTCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_FONTCHANGE, 0, 0L)
#define HANDLE_WM_POWER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_POWER(hwnd, code, fn) \
    (void)(fn)((hwnd), WM_POWER, (WPARAM)(code), 0L)
#define HANDLE_WM_QUERYENDSESSION(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define HANDLE_WM_ENDSESSION(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENDSESSION(hwnd, fEnding, fn) \
    (void)(fn)((hwnd), WM_ENDSESSION, (WPARAM)(BOOL)(fEnding), 0L)
#define HANDLE_WM_QUIT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_QUIT(hwnd, exitCode, fn) \
    (void)(fn)((hwnd), WM_QUIT, (WPARAM)(exitCode), 0L)
#define HANDLE_WM_SYSTEMERROR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_SYSTEMERROR(hwnd, errCode, fn) \
    (void)(fn)((hwnd), WM_SYSTEMERROR, (WPARAM)(errCode), 0L)
#define FORWARD_WM_SHOWWINDOW(hwnd, fShow, status, fn) \
    (void)(fn)((hwnd), WM_SHOWWINDOW, (WPARAM)(BOOL)(fShow), MAKELPARAM((UINT)(status), 0))
#define HANDLE_WM_SETREDRAW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_SETREDRAW(hwnd, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETREDRAW, (WPARAM)(fRedraw), 0L)
#define HANDLE_WM_ENABLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENABLE(hwnd, fEnable, fn) \
    (void)(fn)((hwnd), WM_ENABLE, (WPARAM)(BOOL)(fEnable), 0L)
#define HANDLE_WM_WINDOWPOSCHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const WINDOWPOS FAR*)(lParam)), 0L)
#define FORWARD_WM_WINDOWPOSCHANGED(hwnd, lpwpos, fn) \
    (void)(fn)((hwnd), WM_WINDOWPOSCHANGED, 0, (LPARAM)(const WINDOWPOS FAR*)(lpwpos))
#define FORWARD_WM_MOVE(hwnd, x, y, fn) \
    (void)(fn)((hwnd), WM_MOVE, 0, MAKELPARAM((int)(x), (int)(y)))
#define HANDLE_WM_QUERYOPEN(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define HANDLE_WM_PAINT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PAINT(hwnd, fn) \
    (void)(fn)((hwnd), WM_PAINT, 0, 0L)
#define HANDLE_WM_NCPAINT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HRGN)(wParam)), 0L)
#define FORWARD_WM_NCPAINT(hwnd, hrgn, fn) \
    (void)(fn)((hwnd), WM_NCPAINT, (WPARAM)(HRGN)(hrgn), 0L)
#define HANDLE_WM_DROPFILES(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HDROP)(wParam)), 0L)
#define FORWARD_WM_DROPFILES(hwnd, hdrop, fn) \
    (void)(fn)((hwnd), WM_DROPFILES, (WPARAM)(hdrop), 0L)
#define FORWARD_WM_ACTIVATEAPP(hwnd, fActivate, htaskActDeact, fn) \
    (void)(fn)((hwnd), WM_ACTIVATEAPP, (WPARAM)(BOOL)(fActivate), MAKELPARAM((htaskActDeact),0))
#define HANDLE_WM_SETFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_SETFOCUS(hwnd, hwndOldFocus, fn) \
    (void)(fn)((hwnd), WM_SETFOCUS, (WPARAM)(HWND)(hwndOldFocus), 0L)
#define HANDLE_WM_KILLFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_KILLFOCUS(hwnd, hwndNewFocus, fn) \
    (void)(fn)((hwnd), WM_KILLFOCUS, (WPARAM)(HWND)(hwndNewFocus), 0L)
#define HANDLE_WM_CANCELMODE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CANCELMODE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CANCELMODE, 0, 0L)
#define HANDLE_WM_INITMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam)), 0L)
#define FORWARD_WM_INITMENU(hwnd, hMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENU, (WPARAM)(HMENU)(hMenu), 0L)
#define FORWARD_WM_INITMENUPOPUP(hwnd, hMenu, item, fSystemMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENUPOPUP, (WPARAM)(HMENU)(hMenu), MAKELPARAM((item),(fSystemMenu)))
#define FORWARD_WM_COMMAND(hwnd, id, hwndCtl, codeNotify, fn) \
    (void)(fn)((hwnd), WM_COMMAND, (WPARAM)(int)(id), MAKELPARAM((UINT)(hwndCtl), (codeNotify)))
#define FORWARD_WM_HSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define FORWARD_WM_VSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define HANDLE_WM_CUT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CUT(hwnd, fn) \
    (void)(fn)((hwnd), WM_CUT, 0, 0L)
#define HANDLE_WM_COPY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_COPY(hwnd, fn) \
    (void)(fn)((hwnd), WM_COPY, 0, 0L)
#define HANDLE_WM_PASTE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PASTE(hwnd, fn) \
    (void)(fn)((hwnd), WM_PASTE, 0, 0L)
#define HANDLE_WM_CLEAR(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CLEAR(hwnd, fn) \
    (void)(fn)((hwnd), WM_CLEAR, 0, 0L)
#define HANDLE_WM_UNDO(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_UNDO(hwnd, fn) \
    (void)(fn)((hwnd), WM_UNDO, 0, 0L)
#define HANDLE_WM_RENDERALLFORMATS(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_RENDERALLFORMATS(hwnd, fn) \
    (void)(fn)((hwnd), WM_RENDERALLFORMATS, 0, 0L)
#define HANDLE_WM_DRAWCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DRAWCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DRAWCLIPBOARD, 0, 0L)
#define FORWARD_WM_SYSCOMMAND(hwnd, cmd, x, y, fn) \
    (void)(fn)((hwnd), WM_SYSCOMMAND, (WPARAM)(UINT)(cmd), MAKELPARAM((x), (y)))
#define FORWARD_WM_MDIACTIVATE(hwnd, fActive, hwndActivate, hwndDeactivate, fn) \
    (void)(fn)(hwnd, WM_MDIACTIVATE, (WPARAM)(fActive), MAKELPARAM((hwndActivate), (hwndDeactivate)))
#define HANDLE_WM_MDIRESTORE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIRESTORE(hwnd, hwndRestore, fn) \
    (void)(fn)((hwnd), WM_MDIRESTORE, (WPARAM)(hwndRestore), 0L)
#define FORWARD_WM_ENTERIDLE(hwnd, source, hwndSource, fn) \
    (void)(fn)((hwnd), WM_ENTERIDLE, (WPARAM)(UINT)(source), MAKELPARAM((UINT)(HWND)(hwndSource), 0))
#define FORWARD_WM_SETFONT(hwnd, hfont, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETFONT, (WPARAM)(HFONT)(hfont), MAKELPARAM((UINT)(BOOL)(fRedraw), 0))
#define Edit_SetSel(hwndCtl, ichStart, ichEnd)  ((void)SendMessage((hwndCtl), EM_SETSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define Edit_SetModify(hwndCtl, fModified)      ((void)SendMessage((hwndCtl), EM_SETMODIFY, (WPARAM)(UINT)(fModified), 0L))
#define Edit_Scroll(hwndCtl, dv, dh)            ((void)SendMessage((hwndCtl), EM_LINESCROLL, 0, MAKELPARAM((dv), (dh))))
#define Edit_SetTabStops(hwndCtl, cTabs, lpTabs) ((void)SendMessage((hwndCtl), EM_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(const int FAR*)(lpTabs)))
#define ComboBox_Enable(hwndCtl, fEnable)       EnableWindow((hwndCtl), (fEnable))

// public\sdk\inc\allerror.h
#define DB_E_NOCOMMAND                   ((HRESULT)0x80040E0CL)
#define DB_E_ERRORSINCOMMAND             ((HRESULT)0x80040E14L)
#define DB_E_ROWSNOTRELEASED             ((HRESULT)0x80040E25L)
#define DB_E_BADCOMPAREOP                ((HRESULT)0x80040E27L)
#define DB_E_ROWSETINCOMMAND             ((HRESULT)0x80040E32L)
#define DB_E_CHAPTERNOTRELEASED          ((HRESULT)0x80040E4FL)
#define DB_E_COMMANDNOTPERSISTED         ((HRESULT)0x80040E67L)
#define DB_S_COMMANDREEXECUTED           ((HRESULT)0x00040EC7L)
#define DB_S_CANTRELEASE                 ((HRESULT)0x00040ECAL)

// public\sdk\inc\atl21\atlcom.h
#define DECLARE_GET_CONTROLLING_UNKNOWN() public:\
	virtual IUnknown* GetControllingUnknown() {return GetUnknown();}

// public\sdk\inc\atl21\atlwin21.h
#define DEFAULT_REFLECTION_HANDLER() \
    if(DefaultReflectionHandler(hWnd, uMsg, wParam, lParam, lResult)) \
        return TRUE;

// public\sdk\inc\atl30\atlcom.h
#define _ATL_DECLARE_GET_UNKNOWN(x)\
        IUnknown* GetUnknown() \
        { \
                IUnknown* p; \
                _Module.AddNonAddRefThunk(_GetRawUnknown(), _T(#x), &p); \
                return p; \
        }
#define _ATL_DECLARE_GET_UNKNOWN(x) IUnknown* GetUnknown() {return _GetRawUnknown();}
#define DECLARE_GET_CONTROLLING_UNKNOWN() public:\
        virtual IUnknown* GetControllingUnknown() {return GetUnknown();}

// public\sdk\inc\atl30\atlwin.h
#define DEFAULT_REFLECTION_HANDLER() \
	if(DefaultReflectionHandler(hWnd, uMsg, wParam, lParam, lResult)) \
		return TRUE;

// public\sdk\inc\cierror.h
#define QUERY_E_TOOCOMPLEX               ((HRESULT)0x80041606L)
#define QPARSE_E_EXPECTING_COMMA         ((HRESULT)0x80041671L)

// public\sdk\inc\commctrl.h
#define HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn) \
    (fn)((hwnd), (int)(wParam), (NMHDR *)(lParam))
#define FORWARD_WM_NOTIFY(hwnd, idFrom, pnmhdr, fn) \
    (LRESULT)(fn)((hwnd), WM_NOTIFY, (WPARAM)(int)(idFrom), (LPARAM)(NMHDR *)(pnmhdr))
#define CDDS_ITEMPREPAINT       (CDDS_ITEM | CDDS_PREPAINT)
#define CDDS_ITEMPOSTPAINT      (CDDS_ITEM | CDDS_POSTPAINT)
#define CDDS_ITEMPREERASE       (CDDS_ITEM | CDDS_PREERASE)
#define CDDS_ITEMPOSTERASE      (CDDS_ITEM | CDDS_POSTERASE)
#define Header_EditFilter(hwnd, i, fDiscardChanges) \
        (int)SNDMSG((hwnd), HDM_EDITFILTER, (WPARAM)(i), MAKELPARAM(fDiscardChanges, 0))
#define TB_ENABLEBUTTON         (WM_USER + 1)
#define TB_PRESSBUTTON          (WM_USER + 3)
#define TB_MARKBUTTON           (WM_USER + 6)
#define TB_ISBUTTONENABLED      (WM_USER + 9)
#define TB_ISBUTTONPRESSED      (WM_USER + 11)
#define TB_ADDBUTTONSA          (WM_USER + 20)
#define TB_INSERTBUTTONA        (WM_USER + 21)
#define TB_ADDBUTTONS           (WM_USER + 20)
#define TB_INSERTBUTTON         (WM_USER + 21)
#define TB_DELETEBUTTON         (WM_USER + 22)
#define TB_GETBUTTON            (WM_USER + 23)
#define TB_BUTTONCOUNT          (WM_USER + 24)
#define TB_COMMANDTOINDEX       (WM_USER + 25)
#define TB_SAVERESTOREA         (WM_USER + 26)
#define TB_SAVERESTOREW         (WM_USER + 76)
#define TB_CUSTOMIZE            (WM_USER + 27)
#define TB_SETBUTTONSIZE        (WM_USER + 31)
#define TB_AUTOSIZE             (WM_USER + 33)
#define TB_GETTOOLTIPS          (WM_USER + 35)
#define TB_SETTOOLTIPS          (WM_USER + 36)
#define TB_SETPARENT            (WM_USER + 37)
#define TB_SETROWS              (WM_USER + 39)
#define TB_GETROWS              (WM_USER + 40)
#define TB_SETCMDID             (WM_USER + 42)
#define TB_SETINDENT            (WM_USER + 47)
#define TB_SETSTYLE             (WM_USER + 56)
#define TB_GETSTYLE             (WM_USER + 57)
#define TB_GETBUTTONSIZE        (WM_USER + 58)
#define TB_SETBUTTONWIDTH       (WM_USER + 59)
#define TB_GETOBJECT            (WM_USER + 62)  // wParam == IID, lParam void **ppv
#define TB_GETHOTITEM           (WM_USER + 71)
#define TB_SETHOTITEM           (WM_USER + 72)  // wParam == iHotItem
#define TB_GETINSERTMARK        (WM_USER + 79)  // lParam == LPTBINSERTMARK
#define TB_SETINSERTMARK        (WM_USER + 80)  // lParam == LPTBINSERTMARK
#define TB_MOVEBUTTON           (WM_USER + 82)
#define TB_GETPADDING           (WM_USER + 86)
#define TB_SETPADDING           (WM_USER + 87)
#define TB_GETBUTTONINFOW        (WM_USER + 63)
#define TB_SETBUTTONINFOW        (WM_USER + 64)
#define TB_GETBUTTONINFOA        (WM_USER + 65)
#define TB_SETBUTTONINFOA        (WM_USER + 66)
#define TB_INSERTBUTTONW        (WM_USER + 67)
#define TB_ADDBUTTONSW          (WM_USER + 68)
#define TB_GETMETRICS           (WM_USER + 101)
#define TB_SETMETRICS           (WM_USER + 102)
#define RB_INSERTBANDA  (WM_USER +  1)
#define RB_DELETEBAND   (WM_USER +  2)
#define RB_GETBARINFO   (WM_USER +  3)
#define RB_SETBARINFO   (WM_USER +  4)
#define RB_GETBANDINFO  (WM_USER +  5)
#define RB_SETBANDINFOA (WM_USER +  6)
#define RB_SETPARENT    (WM_USER +  7)
#define RB_INSERTBANDW  (WM_USER +  10)
#define RB_SETBANDINFOW (WM_USER +  11)
#define RB_GETBANDCOUNT (WM_USER +  12)
#define RB_GETROWCOUNT  (WM_USER +  13)
#define RB_GETROWHEIGHT (WM_USER +  14)
#define RB_IDTOINDEX    (WM_USER +  16) // wParam == id
#define RB_GETTOOLTIPS  (WM_USER +  17)
#define RB_SETTOOLTIPS  (WM_USER +  18)
#define RB_BEGINDRAG    (WM_USER + 24)
#define RB_ENDDRAG      (WM_USER + 25)
#define RB_DRAGMOVE     (WM_USER + 26)
#define RB_GETBARHEIGHT (WM_USER + 27)
#define RB_GETBANDINFOW (WM_USER + 28)
#define RB_GETBANDINFOA (WM_USER + 29)
#define RB_GETBANDBORDERS (WM_USER + 34)  // returns in lparam = lprc the amount of edges added to band wparam
#define RB_MOVEBAND     (WM_USER + 39)
#define RB_GETBANDMARGINS   (WM_USER + 40)
#define RB_PUSHCHEVRON  (WM_USER + 43)
#define TTM_ACTIVATE            (WM_USER + 1)
#define TTM_ADDTOOLA            (WM_USER + 4)
#define TTM_ADDTOOLW            (WM_USER + 50)
#define TTM_DELTOOLA            (WM_USER + 5)
#define TTM_DELTOOLW            (WM_USER + 51)
#define TTM_RELAYEVENT          (WM_USER + 7)
#define TTM_GETTOOLINFOA        (WM_USER + 8)
#define TTM_GETTOOLINFOW        (WM_USER + 53)
#define TTM_SETTOOLINFOA        (WM_USER + 9)
#define TTM_SETTOOLINFOW        (WM_USER + 54)
#define TTM_GETTOOLCOUNT        (WM_USER +13)
#define TTM_ENUMTOOLSA          (WM_USER +14)
#define TTM_ENUMTOOLSW          (WM_USER +58)
#define TTM_GETCURRENTTOOLA     (WM_USER + 15)
#define TTM_GETCURRENTTOOLW     (WM_USER + 59)
#define TTM_TRACKACTIVATE       (WM_USER + 17)  // wParam = TRUE/FALSE start end  lparam = LPTOOLINFO
#define TTM_TRACKPOSITION       (WM_USER + 18)  // lParam = dwPos
#define TTM_SETMARGIN           (WM_USER + 26)  // lParam = lprc
#define TTM_GETMARGIN           (WM_USER + 27)  // lParam = lprc
#define TTM_POP                 (WM_USER + 28)
#define TTM_UPDATE              (WM_USER + 29)
#define TTM_GETBUBBLESIZE       (WM_USER + 30)
#define TTM_POPUP               (WM_USER + 34)
#define TTM_GETTITLE            (WM_USER + 35) // wParam = 0, lParam = TTGETTITLE*
#define SB_SETPARTS             (WM_USER+4)
#define SB_GETPARTS             (WM_USER+6)
#define SB_GETBORDERS           (WM_USER+7)
#define SB_SIMPLE               (WM_USER+9)
#define SB_ISSIMPLE             (WM_USER+14)
#define SB_SETICON              (WM_USER+15)
#define SB_GETICON              (WM_USER+20)
#define TBM_GETPOS              (WM_USER)
#define TBM_GETTIC              (WM_USER+3)
#define TBM_SETTIC              (WM_USER+4)
#define TBM_SETPOS              (WM_USER+5)
#define TBM_CLEARTICS           (WM_USER+9)
#define TBM_SETSEL              (WM_USER+10)
#define TBM_SETSELSTART         (WM_USER+11)
#define TBM_SETSELEND           (WM_USER+12)
#define TBM_GETPTICS            (WM_USER+14)
#define TBM_GETTICPOS           (WM_USER+15)
#define TBM_GETNUMTICS          (WM_USER+16)
#define TBM_GETSELSTART         (WM_USER+17)
#define TBM_GETSELEND           (WM_USER+18)
#define TBM_CLEARSEL            (WM_USER+19)
#define TBM_SETTICFREQ          (WM_USER+20)
#define TBM_SETLINESIZE         (WM_USER+23)
#define TBM_GETLINESIZE         (WM_USER+24)
#define TBM_SETTHUMBLENGTH      (WM_USER+27)
#define TBM_GETTHUMBLENGTH      (WM_USER+28)
#define TBM_SETTOOLTIPS         (WM_USER+29)
#define TBM_GETTOOLTIPS         (WM_USER+30)
#define TBM_SETTIPSIDE          (WM_USER+31)
#define TBM_SETBUDDY            (WM_USER+32) // wparam = BOOL fLeft; (or right)
#define TBM_GETBUDDY            (WM_USER+33) // wparam = BOOL fLeft; (or right)
#define DL_BEGINDRAG            (WM_USER+133)
#define DL_DRAGGING             (WM_USER+134)
#define DL_DROPPED              (WM_USER+135)
#define DL_CANCELDRAG           (WM_USER+136)
#define UDM_SETPOS              (WM_USER+103)
#define UDM_GETPOS              (WM_USER+104)
#define UDM_SETBUDDY            (WM_USER+105)
#define UDM_GETBUDDY            (WM_USER+106)
#define UDM_SETACCEL            (WM_USER+107)
#define UDM_GETACCEL            (WM_USER+108)
#define UDM_SETPOS32            (WM_USER+113)
#define UDM_GETPOS32            (WM_USER+114)
#define PBM_SETPOS              (WM_USER+2)
#define PBM_DELTAPOS            (WM_USER+3)
#define PBM_SETSTEP             (WM_USER+4)
#define PBM_STEPIT              (WM_USER+5)
#define PBM_GETPOS              (WM_USER+8)
#define PBM_SETMARQUEE          (WM_USER+10)
#define HKM_SETHOTKEY           (WM_USER+1)
#define HKM_GETHOTKEY           (WM_USER+2)
#define HKM_SETRULES            (WM_USER+3)
#define CCS_LEFT                (CCS_VERT | CCS_TOP)
#define CCS_RIGHT               (CCS_VERT | CCS_BOTTOM)
#define CCS_NOMOVEX             (CCS_VERT | CCS_NOMOVEY)
#define TreeView_DeleteAllItems(hwnd) \
    (BOOL)SNDMSG((hwnd), TVM_DELETEITEM, 0, (LPARAM)TVI_ROOT)
#define TreeView_GetCount(hwnd) \
    (UINT)SNDMSG((hwnd), TVM_GETCOUNT, 0, 0)
#define TreeView_GetIndent(hwnd) \
    (UINT)SNDMSG((hwnd), TVM_GETINDENT, 0, 0)
#define TreeView_SetIndent(hwnd, indent) \
    (BOOL)SNDMSG((hwnd), TVM_SETINDENT, (WPARAM)(indent), 0)
#define TreeView_GetItem(hwnd, pitem) \
    (BOOL)SNDMSG((hwnd), TVM_GETITEM, 0, (LPARAM)(TV_ITEM *)(pitem))
#define TreeView_SetItem(hwnd, pitem) \
    (BOOL)SNDMSG((hwnd), TVM_SETITEM, 0, (LPARAM)(const TV_ITEM *)(pitem))
#define TreeView_GetEditControl(hwnd) \
    (HWND)SNDMSG((hwnd), TVM_GETEDITCONTROL, 0, 0)
#define TreeView_GetVisibleCount(hwnd) \
    (UINT)SNDMSG((hwnd), TVM_GETVISIBLECOUNT, 0, 0)
#define TreeView_EndEditLabelNow(hwnd, fCancel) \
    (BOOL)SNDMSG((hwnd), TVM_ENDEDITLABELNOW, (WPARAM)(fCancel), 0)
#define TreeView_SetToolTips(hwnd,  hwndTT) \
    (HWND)SNDMSG((hwnd), TVM_SETTOOLTIPS, (WPARAM)(hwndTT), 0)
#define TreeView_GetToolTips(hwnd) \
    (HWND)SNDMSG((hwnd), TVM_GETTOOLTIPS, 0, 0)
#define TreeView_SetItemHeight(hwnd,  iHeight) \
    (int)SNDMSG((hwnd), TVM_SETITEMHEIGHT, (WPARAM)(iHeight), 0)
#define TreeView_GetItemHeight(hwnd) \
    (int)SNDMSG((hwnd), TVM_GETITEMHEIGHT, 0, 0)
#define TabCtrl_GetItemCount(hwnd) \
    (int)SNDMSG((hwnd), TCM_GETITEMCOUNT, 0, 0L)
#define TabCtrl_GetItem(hwnd, iItem, pitem) \
    (BOOL)SNDMSG((hwnd), TCM_GETITEM, (WPARAM)(int)(iItem), (LPARAM)(TC_ITEM *)(pitem))
#define TabCtrl_SetItem(hwnd, iItem, pitem) \
    (BOOL)SNDMSG((hwnd), TCM_SETITEM, (WPARAM)(int)(iItem), (LPARAM)(TC_ITEM *)(pitem))
#define TabCtrl_InsertItem(hwnd, iItem, pitem)   \
    (int)SNDMSG((hwnd), TCM_INSERTITEM, (WPARAM)(int)(iItem), (LPARAM)(const TC_ITEM *)(pitem))
#define TabCtrl_DeleteItem(hwnd, i) \
    (BOOL)SNDMSG((hwnd), TCM_DELETEITEM, (WPARAM)(int)(i), 0L)
#define TabCtrl_DeleteAllItems(hwnd) \
    (BOOL)SNDMSG((hwnd), TCM_DELETEALLITEMS, 0, 0L)
#define TabCtrl_GetCurSel(hwnd) \
    (int)SNDMSG((hwnd), TCM_GETCURSEL, 0, 0)
#define TabCtrl_SetCurSel(hwnd, i) \
    (int)SNDMSG((hwnd), TCM_SETCURSEL, (WPARAM)(i), 0)
#define TCHT_ONITEM             (TCHT_ONITEMICON | TCHT_ONITEMLABEL)
#define TabCtrl_SetPadding(hwnd,  cx, cy) \
        (void)SNDMSG((hwnd), TCM_SETPADDING, 0, MAKELPARAM(cx, cy))
#define TabCtrl_GetRowCount(hwnd) \
        (int)SNDMSG((hwnd), TCM_GETROWCOUNT, 0, 0L)
#define TabCtrl_GetToolTips(hwnd) \
        (HWND)SNDMSG((hwnd), TCM_GETTOOLTIPS, 0, 0L)
#define TabCtrl_SetToolTips(hwnd, hwndTT) \
        (void)SNDMSG((hwnd), TCM_SETTOOLTIPS, (WPARAM)(hwndTT), 0L)
#define TabCtrl_GetCurFocus(hwnd) \
    (int)SNDMSG((hwnd), TCM_GETCURFOCUS, 0, 0)
#define TabCtrl_SetCurFocus(hwnd, i) \
    SNDMSG((hwnd),TCM_SETCURFOCUS, i, 0)
#define TabCtrl_DeselectAll(hwnd, fExcludeFocus)\
        (void)SNDMSG((hwnd), TCM_DESELECTALL, fExcludeFocus, 0)
#define ACM_OPENA               (WM_USER+100)
#define ACM_OPENW               (WM_USER+103)
#define ACM_PLAY                (WM_USER+101)
#define ACM_STOP                (WM_USER+102)
#define MCHT_TITLEMONTH                 (MCHT_TITLE | 0x0001)
#define MCHT_TITLEYEAR                  (MCHT_TITLE | 0x0002)
#define MCHT_CALENDARDATE               (MCHT_CALENDAR | 0x0001)
#define MCHT_CALENDARDAY                (MCHT_CALENDAR | 0x0002)
#define MCHT_CALENDARWEEKNUM            (MCHT_CALENDAR | 0x0003)
#define DTS_SHORTDATEFORMAT 0x0000 // use the short date format (app must forward WM_WININICHANGE messages)
#define DTS_SHORTDATECENTURYFORMAT 0x000C// short date format with century (app must forward WM_WININICHANGE messages)
#define IPM_CLEARADDRESS (WM_USER+100) // no parameters
#define IPM_SETADDRESS   (WM_USER+101) // lparam = TCP/IP address
#define IPM_ISBLANK  (WM_USER+105) // no parameters
#define LM_GETIDEALHEIGHT  (WM_USER+0x301)  // wParam: n/a, lparam: n/a, ret: cy
#define LM_SETITEM         (WM_USER+0x302)  // wParam: n/a, lparam: LITEM*, ret: BOOL
#define LM_GETITEM         (WM_USER+0x303)  // wParam: n/a, lparam: LITEM*, ret: BOOL

// public\sdk\inc\commctrl.rh
#define CCS_LEFT                (CCS_VERT | CCS_TOP)
#define CCS_RIGHT               (CCS_VERT | CCS_BOTTOM)
#define CCS_NOMOVEX             (CCS_VERT | CCS_NOMOVEY)
#define DTS_SHORTDATEFORMAT 0x0000 // use the short date format (app must forward WM_WININICHANGE messages)
#define DTS_SHORTDATECENTURYFORMAT 0x000C// short date format with century (app must forward WM_WININICHANGE messages)

// public\sdk\inc\commdlg.h
#define CDM_FIRST       (WM_USER + 100)
#define CDM_LAST        (WM_USER + 200)
#define PD_EXCL_COPIESANDCOLLATE       (DM_COPIES | DM_COLLATE)

// public\sdk\inc\d3dxerr.h
#define D3DXERR_CANNOTRESIZENONWINDOWED    ((HRESULT)0xC8770BD0L)

// public\sdk\inc\ddeml.h
#define DDE_FDATRESERVED        (~(DDE_FACKREQ | DDE_FRELEASE | DDE_FREQUESTED))
#define DDE_FPOKRESERVED        (~(DDE_FRELEASE))
#define     XTYP_XACT_COMPLETE      (0x0080 | XCLASS_NOTIFICATION  )

// public\sdk\inc\ddraw.h
#define DDERR_INCOMPATIBLEPRIMARY               MAKE_DDHRESULT( 95 )
#define DDERR_DDSCAPSCOMPLEXREQUIRED            MAKE_DDHRESULT( 542 )
#define DDERR_CLIPPERISUSINGHWND                MAKE_DDHRESULT( 567 )
#define DDERR_NOHWND                            MAKE_DDHRESULT( 569 )
#define DDERR_HWNDSUBCLASSED                    MAKE_DDHRESULT( 570 )
#define DDERR_HWNDALREADYSET                    MAKE_DDHRESULT( 571 )
#define DDERR_NOFOCUSWINDOW                     MAKE_DDHRESULT( 602 )

// public\sdk\inc\dmerror.h
#define DMUS_E_DMUSIC_RELEASED          MAKE_DMHRESULTERROR(0x0134)
#define DMUS_E_SCRIPT_LANGUAGE_INCOMPATIBLE  MAKE_DMHRESULTERROR(0x0213)

// public\sdk\inc\dmusici.h
#define DMUS_TRACKCONFIG_DEFAULT    (DMUS_TRACKCONFIG_CONTROL_ENABLED | DMUS_TRACKCONFIG_PLAY_ENABLED | DMUS_TRACKCONFIG_NOTIFICATION_ENABLED)

// public\sdk\inc\dplay8.h
#define DPNERR_DUPLICATECOMMAND			MAKE_DPNHRESULT( 0x190 )
#define DPNERR_INCOMPLETEADDRESS		MAKE_DPNHRESULT( 0x280 )
#define DPNERR_NOMOREADDRESSCOMPONENTS	MAKE_DPNHRESULT( 0x500 )

// public\sdk\inc\dsound.h
#define IUnknown_Release(p)             (p)->lpVtbl->Release(p)
#define IUnknown_Release(p)             (p)->Release()
#define DSERR_CONTROLUNAVAIL            MAKE_DSHRESULT(30)

// public\sdk\inc\dvoice.h
#define DVERR_COMPRESSIONNOTSUPPORTED   MAKE_DVHRESULT( 0x0172 )
#define DVERR_INCOMPATIBLEVERSION       MAKE_DVHRESULT( 0x0184 )

// public\sdk\inc\dvp.h
#define IVideoPort_Release(p)                   (p)->lpVtbl->Release(p)
#define IVideoPort_Release(p)                   (p)->Release()
#define IVideoPortNotify_Release(p)                 (p)->lpVtbl->Release(p)
#define IVideoPortNotify_ReleaseNotification(p,a)   (p)->lpVtbl->ReleaseNotification(p,a)
#define IVideoPortNotify_Release(p)                 (p)->Release()
#define IVideoPortNotify_ReleaseNotification(p,a)   (p)->lpVtbl->ReleaseNotification(a)

// public\sdk\inc\dxfile.h
#define DXFILEERR_BADFILECOMPRESSIONTYPE    MAKE_DDHRESULT(864)

// public\sdk\inc\esebkmsg.h
#define hrCommunicationError             ((HRESULT)0xC7FF07DDL)
#define RESTORE_COMPLETE_START_ID        ((HRESULT)0xC8000385L)
#define RESTORE_COMPLETE_STOP_ID         ((HRESULT)0xC8000386L)
#define RESTORE_COMPLETE_ERROR_ID        ((HRESULT)0xC8000387L)

// public\sdk\inc\evntrace.h
#define QueryTrace(a,b,c)       ControlTraceW((a),(b),(c), \
                                        EVENT_TRACE_CONTROL_QUERY)
#define UpdateTrace(a,b,c)      ControlTraceW((a),(b),(c), \
                                        EVENT_TRACE_CONTROL_UPDATE)
#define QueryTrace(a,b,c)       ControlTraceA((a),(b),(c), \
                                        EVENT_TRACE_CONTROL_QUERY)
#define UpdateTrace(a,b,c)      ControlTraceA((a),(b),(c), \
                                        EVENT_TRACE_CONTROL_UPDATE)

// public\sdk\inc\exchext.h
#define EEME_COMPLETE_FAILED			(0x00000002)

// public\sdk\inc\imm.h
#define SCS_CHANGEATTR                  (GCS_COMPREADATTR|GCS_COMPATTR)
#define SCS_CHANGECLAUSE                (GCS_COMPREADCLAUSE|GCS_COMPCLAUSE)

// public\sdk\inc\mdcommsg.h
#define RETURNCODETOHRESULT(rc)                             \
            (((rc) < 0x10000)                               \
                ? HRESULT_FROM_WIN32(rc)                    \
                : (rc))
#define HRESULTTOWIN32(hres)                                \
            ((HRESULT_FACILITY(hres) == FACILITY_WIN32)     \
                ? HRESULT_CODE(hres)                        \
                : (hres))

// public\sdk\inc\mfc42\afxctl.h
#define DISP_STOCKPROP_APPEARANCE() \
	DISP_PROPERTY_STOCK(COleControl, "Appearance", DISPID_APPEARANCE, \
		COleControl::GetAppearance, COleControl::SetAppearance, VT_I2)
#define DISP_STOCKPROP_BORDERSTYLE() \
	DISP_PROPERTY_STOCK(COleControl, "BorderStyle", DISPID_BORDERSTYLE, \
		COleControl::GetBorderStyle, COleControl::SetBorderStyle, VT_I2)
#define DISP_STOCKPROP_ENABLED() \
	DISP_PROPERTY_STOCK(COleControl, "Enabled", DISPID_ENABLED, \
		COleControl::GetEnabled, COleControl::SetEnabled, VT_BOOL)
#define DISP_STOCKPROP_FONT() \
	DISP_PROPERTY_STOCK(COleControl, "Font", DISPID_FONT, \
		COleControl::GetFont, COleControl::SetFont, VT_FONT)
#define DISP_STOCKPROP_HWND() \
	DISP_PROPERTY_STOCK(COleControl, "hWnd", DISPID_HWND, \
		COleControl::GetHwnd, SetNotSupported, VT_HANDLE)
#define DISP_STOCKFUNC_REFRESH() \
	DISP_FUNCTION_STOCK(COleControl, "Refresh", DISPID_REFRESH, \
			COleControl::Refresh, VT_EMPTY, VTS_NONE)
#define DISP_STOCKFUNC_DOCLICK() \
	DISP_FUNCTION_STOCK(COleControl, "DoClick", DISPID_DOCLICK, \
			COleControl::DoClick, VT_EMPTY, VTS_NONE)

// public\sdk\inc\mfc42\afxmsg_.h
#define ON_WM_SHOWWINDOW() \
	{ WM_SHOWWINDOW, 0, 0, 0, AfxSig_vbw, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL, UINT))&OnShowWindow },
#define ON_WM_COMPACTING() \
	{ WM_COMPACTING, 0, 0, 0, AfxSig_vw, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT))&OnCompacting },
#define ON_WM_SYSCOMMAND() \
	{ WM_SYSCOMMAND, 0, 0, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, LPARAM))&OnSysCommand },
#define ON_WM_WINDOWPOSCHANGING() \
	{ WM_WINDOWPOSCHANGING, 0, 0, 0, AfxSig_vPOS, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(WINDOWPOS*))&OnWindowPosChanging },
#define ON_WM_WINDOWPOSCHANGED() \
	{ WM_WINDOWPOSCHANGED, 0, 0, 0, AfxSig_vPOS, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(WINDOWPOS*))&OnWindowPosChanged },

// public\sdk\inc\mmsystem.h
#define MIXERCONTROL_CONTROLTYPE_CUSTOM         (MIXERCONTROL_CT_CLASS_CUSTOM | MIXERCONTROL_CT_UNITS_CUSTOM)
#define MIXERCONTROL_CONTROLTYPE_BOOLEANMETER   (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_SIGNEDMETER    (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER  (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_BOOLEAN        (MIXERCONTROL_CT_CLASS_SWITCH | MIXERCONTROL_CT_SC_SWITCH_BOOLEAN | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_BUTTON         (MIXERCONTROL_CT_CLASS_SWITCH | MIXERCONTROL_CT_SC_SWITCH_BUTTON | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_DECIBELS       (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_DECIBELS)
#define MIXERCONTROL_CONTROLTYPE_SIGNED         (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_UNSIGNED       (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_PERCENT        (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_PERCENT)
#define MIXERCONTROL_CONTROLTYPE_SLIDER         (MIXERCONTROL_CT_CLASS_SLIDER | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_FADER          (MIXERCONTROL_CT_CLASS_FADER | MIXERCONTROL_CT_UNITS_UNSIGNED)

// public\sdk\inc\msctf.h
#define TF_E_COMPOSITION_REJECTED MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0508)
#define TF_E_NOINTERFACE     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0204)

// public\sdk\inc\netcfgx.h
#define NETCFG_E_COMPONENT_REMOVED_PENDING_REBOOT    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xA028)
#define NETCFG_S_COMMIT_NOW                          MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, 0xA025)

// public\sdk\inc\ntddpcm.h
#define PcmciaClassFromControllerType(type) ((PCMCIA_CONTROLLER_CLASS)((type) & 0xff))

// public\sdk\inc\ntdsbmsg.h
#define hrCommunicationError             ((HRESULT)0xC7FF000DL)

// public\sdk\inc\ntexapi.h
#define PROFILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | PROFILE_CONTROL)

// public\sdk\inc\ntioapi.h
#define IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3) // winnt

// public\sdk\inc\ntlsa.h
#define TRUSTED_EXECUTE        (STANDARD_RIGHTS_EXECUTE      |\
                                TRUSTED_QUERY_CONTROLLERS    |\
                                TRUSTED_QUERY_POSIX)

// public\sdk\inc\ntrtl.h
#define RtlCompoundAceServerSid( Ace ) ((PSID)&((PKNOWN_COMPOUND_ACE)(Ace))->SidStart)

// public\sdk\inc\oleauto.h
#define IsHashValCompatible(lhashval1, lhashval2) \
            ((BOOL) ((0x00ff0000 & (lhashval1)) == (0x00ff0000 & (lhashval2))))

// public\sdk\inc\oledberr.h
#define DB_E_NOCOMMAND                   ((HRESULT)0x80040E0CL)
#define DB_E_ERRORSINCOMMAND             ((HRESULT)0x80040E14L)
#define DB_E_ROWSNOTRELEASED             ((HRESULT)0x80040E25L)
#define DB_E_BADCOMPAREOP                ((HRESULT)0x80040E27L)
#define DB_E_ROWSETINCOMMAND             ((HRESULT)0x80040E32L)
#define DB_E_CHAPTERNOTRELEASED          ((HRESULT)0x80040E4FL)
#define DB_E_COMMANDNOTPERSISTED         ((HRESULT)0x80040E67L)
#define DB_E_BADCOMMANDID                ((HRESULT)0x80040E76L)
#define DB_S_COMMANDREEXECUTED           ((HRESULT)0x00040EC7L)
#define DB_S_CANTRELEASE                 ((HRESULT)0x00040ECAL)

// public\sdk\inc\prsht.h
#define PSM_RESTARTWINDOWS      (WM_USER + 105)
#define PSM_GETTABCONTROL       (WM_USER + 116)
#define PSM_HWNDTOINDEX            (WM_USER + 129)
#define PSM_INDEXTOHWND            (WM_USER + 130)
#define ID_PSREBOOTSYSTEM       (ID_PSRESTARTWINDOWS | 0x1)

// public\sdk\inc\pwin16.h
#define GET_WM_COMMAND_ID(wp, lp)                   (wp)
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
        (WPARAM)(hwndA), 0

// public\sdk\inc\pwin32.h
#define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)(lp)
#define GET_WM_COMMAND_HWND(wp, lp)             (HWND)(lp)
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (lp == (LPARAM)hwnd)
#define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)(wp)
#define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)(lp)
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
        (WPARAM)(hwndA), 0
#define GET_WM_VKEYTOITEM_HWND(wp, lp)              (HWND)(lp)
#define GET_WM_HSCROLL_HWND(wp, lp)                 (HWND)(lp)
#define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)(lp)

// public\sdk\inc\richedit.h
#define EM_GETOLEINTERFACE		(WM_USER + 60)

// public\sdk\inc\rtcerr.h
#define RTC_E_PROFILE_NO_ACCESSCONTROL   ((HRESULT)0x80EE003EL)
#define RTC_E_PROFILE_NO_ACCESSCONTROL_DOMAIN ((HRESULT)0x80EE003FL)
#define RTC_E_PROFILE_NO_ACCESSCONTROL_SIGNATURE ((HRESULT)0x80EE0040L)
#define RTC_E_STATUS_CLIENT_ADDRESS_INCOMPLETE ((HRESULT)0x80EF01E4L)

// public\sdk\inc\shellapi.h
#define FOF_WANTNUKEWARNING        0x4000  // during delete operation, warn if nuking instead of recycling (partially overrides FOF_NOCONFIRMATION)
#define NIN_SELECT          (WM_USER + 0)
#define NIN_KEYSELECT       (NIN_SELECT | NINF_KEY)

// public\sdk\inc\stdclass.hxx
#define DECLARE_CLASSFACTORY(cls)                       \
                                                        \
class cls##CF : public CStdClassFactory                 \
{                                                       \
public:                                                 \
    cls##CF() :                                     	\
            CStdClassFactory(CLSID_##cls) {};           \
protected:                                              \
    STDMETHOD(_CreateInstance)(IUnknown* pUnkOuter,     \
                              REFIID iidInterface,      \
                              void** ppv);              \
};

// public\sdk\inc\stdobj.hxx
#define INIT_CLASS(cls)	CStdComponentObject ( &CLASSDESCRIPTOR_NAME(cls) )

// public\sdk\inc\sti.h
#define IStiDevice_Release(p)                   (p)->lpVtbl->Release(p)

// public\sdk\inc\tapi3err.h
#define TAPI_E_COMPLETIONOVERRUN         ((HRESULT)0x80040008L)
#define TAPI_E_INVALCOMPLETIONID         ((HRESULT)0x80040012L)

// public\sdk\inc\upnp.h
#define UPNP_E_SERVICE_NODE_INCOMPLETE   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0203)
#define UPNP_E_DEVICE_NODE_INCOMPLETE    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0204)
#define UPNP_E_ICON_NODE_INCOMPLETE      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0206)

// public\sdk\inc\vfw.h
#define MCIWNDM_CAN_WINDOW      (WM_USER + 145)
#define MCIWNDM_OPENINTERFACE	(WM_USER + 151)
#define MCIWNDM_NOTIFYMODE      (WM_USER + 200)  // wp = hwnd, lp = mode
#define MCIWNDM_NOTIFYPOS	(WM_USER + 201)  // wp = hwnd, lp = pos
#define MCIWNDM_NOTIFYSIZE	(WM_USER + 202)  // wp = hwnd
#define MCIWNDM_NOTIFYMEDIA     (WM_USER + 203)  // wp = hwnd, lp = fn
#define MCIWNDM_NOTIFYERROR     (WM_USER + 205)  // wp = hwnd, lp = error
#define AVICapSM(hwnd,m,w,l) ( (::IsWindow(hwnd)) ? ::SendMessage(hwnd,m,w,l) : 0)
#define AVICapSM(hwnd,m,w,l) ( (IsWindow(hwnd)) ?   SendMessage(hwnd,m,w,l) : 0)
#define capGetUserData(hwnd)               (AVICapSM(hwnd, WM_CAP_GET_USER_DATA, 0, 0))
#define capDriverConnect(hwnd, i)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_CONNECT, (WPARAM)(i), 0L))
#define capDriverDisconnect(hwnd)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_DISCONNECT, (WPARAM)0, 0L))
#define capDriverGetCaps(hwnd, s, wSize)           ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_CAPS, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPDRIVERCAPS)(s)))
#define capEditCopy(hwnd)                          ((BOOL)AVICapSM(hwnd, WM_CAP_EDIT_COPY, 0, 0L))
#define capDlgVideoFormat(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOFORMAT, 0, 0L))
#define capDlgVideoSource(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOSOURCE, 0, 0L))
#define capDlgVideoDisplay(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEODISPLAY, 0, 0L))
#define capDlgVideoCompression(hwnd)               ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOCOMPRESSION, 0, 0L))
#define capGetStatus(hwnd, s, wSize)               ((BOOL)AVICapSM(hwnd, WM_CAP_GET_STATUS, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPSTATUS)(s)))
#define capGrabFrame(hwnd)                         ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME, (WPARAM)0, (LPARAM)0L))
#define capGrabFrameNoStop(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME_NOSTOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequence(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequenceNoFile(hwnd)             ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE_NOFILE, (WPARAM)0, (LPARAM)0L))
#define capCaptureStop(hwnd)                       ((BOOL)AVICapSM(hwnd, WM_CAP_STOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureAbort(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_ABORT, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrameOpen(hwnd)            ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME_OPEN, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrame(hwnd)                ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME, (WPARAM)0, (LPARAM)0L))
#define capCaptureGetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_GET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))

// public\sdk\inc\vfwmsgs.h
#define VFW_E_ALREADY_COMMITTED          ((HRESULT)0x8004020FL)
#define VFW_E_NOT_COMMITTED              ((HRESULT)0x80040211L)
#define VFW_E_NO_INTERFACE               ((HRESULT)0x80040215L)
#define VFW_E_NO_DECOMPRESSOR            ((HRESULT)0x80040255L)
#define VFW_E_DVD_INCOMPATIBLE_REGION    ((HRESULT)0x80040287L)

// public\sdk\inc\wdm.h
#define ExReleaseResource(R) (ExReleaseResourceLite(R))
#define PCI_CONFIGURATION_TYPE(PciData) \
    (((PPCI_COMMON_CONFIG)(PciData))->HeaderType & ~PCI_MULTIFUNCTION)
#define PCI_MULTIFUNCTION_DEVICE(PciData) \
    ((((PPCI_COMMON_CONFIG)(PciData))->HeaderType & PCI_MULTIFUNCTION) != 0)

// public\sdk\inc\wfext.h
#define FM_REFRESH_WINDOWS    (WM_USER + 0x0206)

// public\sdk\inc\wincrui.h
#define Credential_InitStyle(hwnd, style)\
    (BOOL) SendMessage(hwnd, CRM_INITSTYLE, (WPARAM)(style), 0)
#define Credential_EnableUserName(hwnd)\
    (BOOL) SendMessage(hwnd, CRM_ENABLEUSERNAME, (WPARAM)(0), 0)
#define Credential_DisableUserName(hwnd)\
    (BOOL) SendMessage(hwnd, CRM_DISABLEUSERNAME, (WPARAM)(0), 0)
#define Credential_SetUserName(hwnd, pszUserName)\
    (BOOL) SendMessage(hwnd, CRM_SETUSERNAME, 0, (LPARAM)(pszUserName))
#define Credential_SetUserNameFocus(hwnd)\
    (BOOL) SendMessage(hwnd, CRM_SETFOCUS, CREDUI_CONTROL_USERNAME, 0)

// public\sdk\inc\windowsx.h
#define     SetWindowRedraw(hwnd, fRedraw)  \
                    ((void)SNDMSG(hwnd, WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L))
#define     SetWindowFont(hwnd, hfont, fRedraw) FORWARD_WM_SETFONT((hwnd), (hfont), (fRedraw), SNDMSG)
#define     GetWindowFont(hwnd)                 FORWARD_WM_GETFONT((hwnd), SNDMSG)
#define HANDLE_MSG(hwnd, message, fn)    \
    case (message): return HANDLE_##message((hwnd), (wParam), (lParam), (fn))
#define HANDLE_WM_COMPACTING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_COMPACTING(hwnd, compactRatio, fn) \
    (void)(fn)((hwnd), WM_COMPACTING, (WPARAM)(UINT)(compactRatio), 0L)
#define HANDLE_WM_FONTCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_FONTCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_FONTCHANGE, 0L, 0L)
#define HANDLE_WM_POWER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_POWER(hwnd, code, fn) \
    (void)(fn)((hwnd), WM_POWER, (WPARAM)(int)(code), 0L)
#define HANDLE_WM_QUERYENDSESSION(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0L)
#define HANDLE_WM_ENDSESSION(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENDSESSION(hwnd, fEnding, fn) \
    (void)(fn)((hwnd), WM_ENDSESSION, (WPARAM)(BOOL)(fEnding), 0L)
#define HANDLE_WM_QUIT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_QUIT(hwnd, exitCode, fn) \
    (void)(fn)((hwnd), WM_QUIT, (WPARAM)(exitCode), 0L)
#define HANDLE_WM_SYSTEMERROR(hwnd, wParam, lParam, fn) 0L
#define FORWARD_WM_SYSTEMERROR(hwnd, errCode, fn) 0L
#define HANDLE_WM_SHOWWINDOW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (UINT)(lParam)), 0L)
#define FORWARD_WM_SHOWWINDOW(hwnd, fShow, status, fn) \
    (void)(fn)((hwnd), WM_SHOWWINDOW, (WPARAM)(BOOL)(fShow), (LPARAM)(UINT)(status))
#define HANDLE_WM_SETREDRAW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_SETREDRAW(hwnd, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L)
#define HANDLE_WM_ENABLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENABLE(hwnd, fEnable, fn) \
    (void)(fn)((hwnd), WM_ENABLE, (WPARAM)(BOOL)(fEnable), 0L)
#define HANDLE_WM_WINDOWPOSCHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const LPWINDOWPOS)(lParam)), 0L)
#define FORWARD_WM_WINDOWPOSCHANGED(hwnd, lpwpos, fn) \
    (void)(fn)((hwnd), WM_WINDOWPOSCHANGED, 0L, (LPARAM)(const LPWINDOWPOS)(lpwpos))
#define FORWARD_WM_MOVE(hwnd, x, y, fn) \
    (void)(fn)((hwnd), WM_MOVE, 0L, MAKELPARAM((x), (y)))
#define HANDLE_WM_QUERYOPEN(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0L)
#define HANDLE_WM_PAINT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PAINT(hwnd, fn) \
    (void)(fn)((hwnd), WM_PAINT, 0L, 0L)
#define HANDLE_WM_NCPAINT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HRGN)(wParam)), 0L)
#define FORWARD_WM_NCPAINT(hwnd, hrgn, fn) \
    (void)(fn)((hwnd), WM_NCPAINT, (WPARAM)(HRGN)(hrgn), 0L)
#define HANDLE_WM_DROPFILES(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HDROP)(wParam)), 0L)
#define FORWARD_WM_DROPFILES(hwnd, hdrop, fn) \
    (void)(fn)((hwnd), WM_DROPFILES, (WPARAM)(HDROP)(hdrop), 0L)
#define FORWARD_WM_ACTIVATEAPP(hwnd, fActivate, dwThreadId, fn) \
    (void)(fn)((hwnd), WM_ACTIVATEAPP, (WPARAM)(BOOL)(fActivate), (LPARAM)(dwThreadId))
#define HANDLE_WM_SETFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_SETFOCUS(hwnd, hwndOldFocus, fn) \
    (void)(fn)((hwnd), WM_SETFOCUS, (WPARAM)(HWND)(hwndOldFocus), 0L)
#define HANDLE_WM_KILLFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_KILLFOCUS(hwnd, hwndNewFocus, fn) \
    (void)(fn)((hwnd), WM_KILLFOCUS, (WPARAM)(HWND)(hwndNewFocus), 0L)
#define FORWARD_WM_MOUSEWHEEL(hwnd, xPos, yPos, zDelta, fwKeys, fn) \
    (void)(fn)((hwnd), WM_MOUSEWHEEL, MAKEWPARAM((fwKeys),(zDelta)), MAKELPARAM((x),(y)))
#define HANDLE_WM_CANCELMODE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CANCELMODE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CANCELMODE, 0L, 0L)
#define HANDLE_WM_INITMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam)), 0L)
#define FORWARD_WM_INITMENU(hwnd, hMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENU, (WPARAM)(HMENU)(hMenu), 0L)
#define FORWARD_WM_INITMENUPOPUP(hwnd, hMenu, item, fSystemMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENUPOPUP, (WPARAM)(HMENU)(hMenu), MAKELPARAM((item),(fSystemMenu)))
#define FORWARD_WM_COMMAND(hwnd, id, hwndCtl, codeNotify, fn) \
    (void)(fn)((hwnd), WM_COMMAND, MAKEWPARAM((UINT)(id),(UINT)(codeNotify)), (LPARAM)(HWND)(hwndCtl))
#define FORWARD_WM_HSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLL, MAKEWPARAM((UINT)(int)(code),(UINT)(int)(pos)), (LPARAM)(HWND)(hwndCtl))
#define FORWARD_WM_VSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLL, MAKEWPARAM((UINT)(int)(code), (UINT)(int)(pos)), (LPARAM)(HWND)(hwndCtl))
#define HANDLE_WM_CUT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CUT(hwnd, fn) \
    (void)(fn)((hwnd), WM_CUT, 0L, 0L)
#define HANDLE_WM_COPY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_COPY(hwnd, fn) \
    (void)(fn)((hwnd), WM_COPY, 0L, 0L)
#define HANDLE_WM_PASTE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PASTE(hwnd, fn) \
    (void)(fn)((hwnd), WM_PASTE, 0L, 0L)
#define HANDLE_WM_CLEAR(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CLEAR(hwnd, fn) \
    (void)(fn)((hwnd), WM_CLEAR, 0L, 0L)
#define HANDLE_WM_UNDO(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_UNDO(hwnd, fn) \
    (void)(fn)((hwnd), WM_UNDO, 0L, 0L)
#define HANDLE_WM_RENDERALLFORMATS(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_RENDERALLFORMATS(hwnd, fn) \
    (void)(fn)((hwnd), WM_RENDERALLFORMATS, 0L, 0L)
#define HANDLE_WM_DRAWCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DRAWCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DRAWCLIPBOARD, 0L, 0L)
#define FORWARD_WM_SYSCOMMAND(hwnd, cmd, x, y, fn) \
    (void)(fn)((hwnd), WM_SYSCOMMAND, (WPARAM)(UINT)(cmd), MAKELPARAM((x), (y)))
#define HANDLE_WM_MDIACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(lParam == (LPARAM)hwnd), (HWND)(lParam), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIACTIVATE(hwnd, fActive, hwndActivate, hwndDeactivate, fn) \
    (void)(fn)(hwnd, WM_MDIACTIVATE, (WPARAM)(hwndDeactivate), (LPARAM)(hwndActivate))
#define HANDLE_WM_MDIRESTORE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIRESTORE(hwnd, hwndRestore, fn) \
    (void)(fn)((hwnd), WM_MDIRESTORE, (WPARAM)(hwndRestore), 0L)
#define HANDLE_WM_ENTERIDLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)(lParam)), 0L)
#define FORWARD_WM_ENTERIDLE(hwnd, source, hwndSource, fn) \
    (void)(fn)((hwnd), WM_ENTERIDLE, (WPARAM)(UINT)(source), (LPARAM)(HWND)(hwndSource))
#define HANDLE_WM_SETFONT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HFONT)(wParam), (BOOL)(lParam)), 0L)
#define FORWARD_WM_SETFONT(hwnd, hfont, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETFONT, (WPARAM)(HFONT)(hfont), (LPARAM)(BOOL)(fRedraw))
#define FORWARD_WM_HOTKEY(hwnd, idHotKey, fuModifiers, vk, fn) \
    (void)(fn)((hwnd), WM_HOTKEY, (WPARAM)(idHotKey), MAKELPARAM((fuModifiers), (vk)))
#define ComboBox_Enable(hwndCtl, fEnable)       EnableWindow((hwndCtl), (fEnable))
#define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)(lp)
#define GET_WM_COMMAND_HWND(wp, lp)             (HWND)(lp)
#define GET_WM_MENUSELECT_HMENU(wp, lp)             (HMENU)(lp)
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (lp == (LPARAM)hwnd)
#define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)(wp)
#define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)(lp)
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
        (WPARAM)(hwndA), 0
#define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW) (WPARAM)hmenuF, (LPARAM)hmenuW
#define GET_WM_VKEYTOITEM_HWND(wp, lp)              (HWND)(lp)
#define GET_WM_HSCROLL_HWND(wp, lp)                 (HWND)(lp)
#define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)(lp)

// public\sdk\inc\winerror.h
#define CO_E_INIT_TLS_CHANNEL_CONTROL    _HRESULT_TYPEDEF_(0x8000400CL)
#define CO_E_REMOTE_COMMUNICATION_FAILURE _HRESULT_TYPEDEF_(0x8000401DL)
#define OLE_E_WRONGCOMPOBJ               _HRESULT_TYPEDEF_(0x8004000EL)
#define MK_E_INTERMEDIATEINTERFACENOTSUPPORTED _HRESULT_TYPEDEF_(0x800401E7L)
#define CO_E_RELEASED                    _HRESULT_TYPEDEF_(0x800401FFL)
#define EVENT_E_COMPLUS_NOT_INSTALLED    _HRESULT_TYPEDEF_(0x8004020CL)
#define XACT_E_COMMITFAILED              _HRESULT_TYPEDEF_(0x8004D002L)
#define XACT_E_HEURISTICCOMMIT           _HRESULT_TYPEDEF_(0x8004D005L)
#define CO_S_NOTALLINTERFACES            _HRESULT_TYPEDEF_(0x00080012L)
#define DISP_E_UNKNOWNINTERFACE          _HRESULT_TYPEDEF_(0x80020001L)
#define STG_E_INCOMPLETE                 _HRESULT_TYPEDEF_(0x80030201L)
#define RPC_E_CALL_COMPLETE              _HRESULT_TYPEDEF_(0x80010117L)
#define CRYPT_E_CONTROL_TYPE             _HRESULT_TYPEDEF_(0x8009100CL)
#define OSS_CANT_OPEN_TRACE_WINDOW       _HRESULT_TYPEDEF_(0x80093018L)
#define OSS_COMPARATOR_DLL_NOT_LINKED    _HRESULT_TYPEDEF_(0x80093024L)
#define OSS_COMPARATOR_CODE_NOT_LINKED   _HRESULT_TYPEDEF_(0x80093025L)
#define SPAPI_E_NO_DEFAULT_DEVICE_INTERFACE _HRESULT_TYPEDEF_(0x800F021AL)
#define SPAPI_E_DEVICE_INTERFACE_ACTIVE  _HRESULT_TYPEDEF_(0x800F021BL)
#define SPAPI_E_DEVICE_INTERFACE_REMOVED _HRESULT_TYPEDEF_(0x800F021CL)
#define SPAPI_E_NO_SUCH_INTERFACE_CLASS  _HRESULT_TYPEDEF_(0x800F021EL)
#define SPAPI_E_REMOTE_COMM_FAILURE      _HRESULT_TYPEDEF_(0x800F0221L)
#define SPAPI_E_NO_SUCH_DEVICE_INTERFACE _HRESULT_TYPEDEF_(0x800F0225L)
#define SPAPI_E_NO_COMPAT_DRIVERS        _HRESULT_TYPEDEF_(0x800F0228L)
#define SPAPI_E_NON_WINDOWS_NT_DRIVER    _HRESULT_TYPEDEF_(0x800F022DL)
#define SPAPI_E_NON_WINDOWS_DRIVER       _HRESULT_TYPEDEF_(0x800F022EL)
#define SCARD_F_COMM_ERROR               _HRESULT_TYPEDEF_(0x80100013L)
#define COMQC_E_QUEUING_SERVICE_NOT_AVAILABLE _HRESULT_TYPEDEF_(0x80110602L)
#define COMQC_E_BAD_MESSAGE              _HRESULT_TYPEDEF_(0x80110604L)
#define COMQC_E_UNAUTHENTICATED          _HRESULT_TYPEDEF_(0x80110605L)

// public\sdk\inc\winnt.h
#define IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

// public\sdk\inc\winsvc.h
#define SERVICE_ALL_ACCESS             (STANDARD_RIGHTS_REQUIRED     | \
                                        SERVICE_QUERY_CONFIG         | \
                                        SERVICE_CHANGE_CONFIG        | \
                                        SERVICE_QUERY_STATUS         | \
                                        SERVICE_ENUMERATE_DEPENDENTS | \
                                        SERVICE_START                | \
                                        SERVICE_STOP                 | \
                                        SERVICE_PAUSE_CONTINUE       | \
                                        SERVICE_INTERROGATE          | \
                                        SERVICE_USER_DEFINED_CONTROL)

// public\sdk\inc\wtl10\atlapp.h
#define FORWARD_NOTIFICATIONS() \
	{ \
		bHandled = TRUE; \
		lResult = Atl3ForwardNotifications(m_hWnd, uMsg, wParam, lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}

// published\sdk\inc\exchext.h
#define EEME_COMPLETE_FAILED			(0x00000002)

// published\sdk\inc\ntddpcm.h
#define PcmciaClassFromControllerType(type) ((PCMCIA_CONTROLLER_CLASS)((type) & 0xff))

// published\sdk\inc\pwin16.h
#define GET_WM_COMMAND_ID(wp, lp)                   (wp)
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
        (WPARAM)(hwndA), 0

// published\sdk\inc\pwin32.h
#define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)(lp)
#define GET_WM_COMMAND_HWND(wp, lp)             (HWND)(lp)
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (lp == (LPARAM)hwnd)
#define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)(wp)
#define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)(lp)
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
        (WPARAM)(hwndA), 0
#define GET_WM_VKEYTOITEM_HWND(wp, lp)              (HWND)(lp)
#define GET_WM_HSCROLL_HWND(wp, lp)                 (HWND)(lp)
#define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)(lp)

// published\sdk\inc\vfw.h
#define MCIWNDM_CAN_WINDOW      (WM_USER + 145)
#define MCIWNDM_OPENINTERFACE	(WM_USER + 151)
#define MCIWNDM_NOTIFYMODE      (WM_USER + 200)  // wp = hwnd, lp = mode
#define MCIWNDM_NOTIFYPOS	(WM_USER + 201)  // wp = hwnd, lp = pos
#define MCIWNDM_NOTIFYSIZE	(WM_USER + 202)  // wp = hwnd
#define MCIWNDM_NOTIFYMEDIA     (WM_USER + 203)  // wp = hwnd, lp = fn
#define MCIWNDM_NOTIFYERROR     (WM_USER + 205)  // wp = hwnd, lp = error
#define AVICapSM(hwnd,m,w,l) ( (::IsWindow(hwnd)) ? ::SendMessage(hwnd,m,w,l) : 0)
#define AVICapSM(hwnd,m,w,l) ( (IsWindow(hwnd)) ?   SendMessage(hwnd,m,w,l) : 0)
#define capGetUserData(hwnd)               (AVICapSM(hwnd, WM_CAP_GET_USER_DATA, 0, 0))
#define capDriverConnect(hwnd, i)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_CONNECT, (WPARAM)(i), 0L))
#define capDriverDisconnect(hwnd)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_DISCONNECT, (WPARAM)0, 0L))
#define capDriverGetCaps(hwnd, s, wSize)           ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_CAPS, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPDRIVERCAPS)(s)))
#define capEditCopy(hwnd)                          ((BOOL)AVICapSM(hwnd, WM_CAP_EDIT_COPY, 0, 0L))
#define capDlgVideoFormat(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOFORMAT, 0, 0L))
#define capDlgVideoSource(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOSOURCE, 0, 0L))
#define capDlgVideoDisplay(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEODISPLAY, 0, 0L))
#define capDlgVideoCompression(hwnd)               ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOCOMPRESSION, 0, 0L))
#define capGetStatus(hwnd, s, wSize)               ((BOOL)AVICapSM(hwnd, WM_CAP_GET_STATUS, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPSTATUS)(s)))
#define capGrabFrame(hwnd)                         ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME, (WPARAM)0, (LPARAM)0L))
#define capGrabFrameNoStop(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME_NOSTOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequence(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE, (WPARAM)0, (LPARAM)0L))
#define capCaptureSequenceNoFile(hwnd)             ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE_NOFILE, (WPARAM)0, (LPARAM)0L))
#define capCaptureStop(hwnd)                       ((BOOL)AVICapSM(hwnd, WM_CAP_STOP, (WPARAM)0, (LPARAM)0L))
#define capCaptureAbort(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_ABORT, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrameOpen(hwnd)            ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME_OPEN, (WPARAM)0, (LPARAM)0L))
#define capCaptureSingleFrame(hwnd)                ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME, (WPARAM)0, (LPARAM)0L))
#define capCaptureGetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_GET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))

// published\sdk\inc\wfext.h
#define FM_REFRESH_WINDOWS    (WM_USER + 0x0206)

// published\sdk\inc\windowsx.h
#define     SetWindowRedraw(hwnd, fRedraw)  \
                    ((void)SNDMSG(hwnd, WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L))
#define     SetWindowFont(hwnd, hfont, fRedraw) FORWARD_WM_SETFONT((hwnd), (hfont), (fRedraw), SNDMSG)
#define     GetWindowFont(hwnd)                 FORWARD_WM_GETFONT((hwnd), SNDMSG)
#define HANDLE_MSG(hwnd, message, fn)    \
    case (message): return HANDLE_##message((hwnd), (wParam), (lParam), (fn))
#define HANDLE_WM_COMPACTING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_COMPACTING(hwnd, compactRatio, fn) \
    (void)(fn)((hwnd), WM_COMPACTING, (WPARAM)(UINT)(compactRatio), 0L)
#define HANDLE_WM_FONTCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_FONTCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_FONTCHANGE, 0L, 0L)
#define HANDLE_WM_POWER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_POWER(hwnd, code, fn) \
    (void)(fn)((hwnd), WM_POWER, (WPARAM)(int)(code), 0L)
#define HANDLE_WM_QUERYENDSESSION(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0L)
#define HANDLE_WM_ENDSESSION(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENDSESSION(hwnd, fEnding, fn) \
    (void)(fn)((hwnd), WM_ENDSESSION, (WPARAM)(BOOL)(fEnding), 0L)
#define HANDLE_WM_QUIT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_QUIT(hwnd, exitCode, fn) \
    (void)(fn)((hwnd), WM_QUIT, (WPARAM)(exitCode), 0L)
#define HANDLE_WM_SYSTEMERROR(hwnd, wParam, lParam, fn) 0L
#define FORWARD_WM_SYSTEMERROR(hwnd, errCode, fn) 0L
#define HANDLE_WM_SHOWWINDOW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (UINT)(lParam)), 0L)
#define FORWARD_WM_SHOWWINDOW(hwnd, fShow, status, fn) \
    (void)(fn)((hwnd), WM_SHOWWINDOW, (WPARAM)(BOOL)(fShow), (LPARAM)(UINT)(status))
#define HANDLE_WM_SETREDRAW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_SETREDRAW(hwnd, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L)
#define HANDLE_WM_ENABLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENABLE(hwnd, fEnable, fn) \
    (void)(fn)((hwnd), WM_ENABLE, (WPARAM)(BOOL)(fEnable), 0L)
#define HANDLE_WM_WINDOWPOSCHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const LPWINDOWPOS)(lParam)), 0L)
#define FORWARD_WM_WINDOWPOSCHANGED(hwnd, lpwpos, fn) \
    (void)(fn)((hwnd), WM_WINDOWPOSCHANGED, 0L, (LPARAM)(const LPWINDOWPOS)(lpwpos))
#define FORWARD_WM_MOVE(hwnd, x, y, fn) \
    (void)(fn)((hwnd), WM_MOVE, 0L, MAKELPARAM((x), (y)))
#define HANDLE_WM_QUERYOPEN(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0L)
#define HANDLE_WM_PAINT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PAINT(hwnd, fn) \
    (void)(fn)((hwnd), WM_PAINT, 0L, 0L)
#define HANDLE_WM_NCPAINT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HRGN)(wParam)), 0L)
#define FORWARD_WM_NCPAINT(hwnd, hrgn, fn) \
    (void)(fn)((hwnd), WM_NCPAINT, (WPARAM)(HRGN)(hrgn), 0L)
#define HANDLE_WM_DROPFILES(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HDROP)(wParam)), 0L)
#define FORWARD_WM_DROPFILES(hwnd, hdrop, fn) \
    (void)(fn)((hwnd), WM_DROPFILES, (WPARAM)(HDROP)(hdrop), 0L)
#define FORWARD_WM_ACTIVATEAPP(hwnd, fActivate, dwThreadId, fn) \
    (void)(fn)((hwnd), WM_ACTIVATEAPP, (WPARAM)(BOOL)(fActivate), (LPARAM)(dwThreadId))
#define HANDLE_WM_SETFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_SETFOCUS(hwnd, hwndOldFocus, fn) \
    (void)(fn)((hwnd), WM_SETFOCUS, (WPARAM)(HWND)(hwndOldFocus), 0L)
#define HANDLE_WM_KILLFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_KILLFOCUS(hwnd, hwndNewFocus, fn) \
    (void)(fn)((hwnd), WM_KILLFOCUS, (WPARAM)(HWND)(hwndNewFocus), 0L)
#define FORWARD_WM_MOUSEWHEEL(hwnd, xPos, yPos, zDelta, fwKeys, fn) \
    (void)(fn)((hwnd), WM_MOUSEWHEEL, MAKEWPARAM((fwKeys),(zDelta)), MAKELPARAM((x),(y)))
#define HANDLE_WM_CANCELMODE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CANCELMODE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CANCELMODE, 0L, 0L)
#define HANDLE_WM_INITMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam)), 0L)
#define FORWARD_WM_INITMENU(hwnd, hMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENU, (WPARAM)(HMENU)(hMenu), 0L)
#define FORWARD_WM_INITMENUPOPUP(hwnd, hMenu, item, fSystemMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENUPOPUP, (WPARAM)(HMENU)(hMenu), MAKELPARAM((item),(fSystemMenu)))
#define FORWARD_WM_COMMAND(hwnd, id, hwndCtl, codeNotify, fn) \
    (void)(fn)((hwnd), WM_COMMAND, MAKEWPARAM((UINT)(id),(UINT)(codeNotify)), (LPARAM)(HWND)(hwndCtl))
#define FORWARD_WM_HSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLL, MAKEWPARAM((UINT)(int)(code),(UINT)(int)(pos)), (LPARAM)(HWND)(hwndCtl))
#define FORWARD_WM_VSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLL, MAKEWPARAM((UINT)(int)(code), (UINT)(int)(pos)), (LPARAM)(HWND)(hwndCtl))
#define HANDLE_WM_CUT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CUT(hwnd, fn) \
    (void)(fn)((hwnd), WM_CUT, 0L, 0L)
#define HANDLE_WM_COPY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_COPY(hwnd, fn) \
    (void)(fn)((hwnd), WM_COPY, 0L, 0L)
#define HANDLE_WM_PASTE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PASTE(hwnd, fn) \
    (void)(fn)((hwnd), WM_PASTE, 0L, 0L)
#define HANDLE_WM_CLEAR(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CLEAR(hwnd, fn) \
    (void)(fn)((hwnd), WM_CLEAR, 0L, 0L)
#define HANDLE_WM_UNDO(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_UNDO(hwnd, fn) \
    (void)(fn)((hwnd), WM_UNDO, 0L, 0L)
#define HANDLE_WM_RENDERALLFORMATS(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_RENDERALLFORMATS(hwnd, fn) \
    (void)(fn)((hwnd), WM_RENDERALLFORMATS, 0L, 0L)
#define HANDLE_WM_DRAWCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DRAWCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DRAWCLIPBOARD, 0L, 0L)
#define FORWARD_WM_SYSCOMMAND(hwnd, cmd, x, y, fn) \
    (void)(fn)((hwnd), WM_SYSCOMMAND, (WPARAM)(UINT)(cmd), MAKELPARAM((x), (y)))
#define HANDLE_WM_MDIACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(lParam == (LPARAM)hwnd), (HWND)(lParam), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIACTIVATE(hwnd, fActive, hwndActivate, hwndDeactivate, fn) \
    (void)(fn)(hwnd, WM_MDIACTIVATE, (WPARAM)(hwndDeactivate), (LPARAM)(hwndActivate))
#define HANDLE_WM_MDIRESTORE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIRESTORE(hwnd, hwndRestore, fn) \
    (void)(fn)((hwnd), WM_MDIRESTORE, (WPARAM)(hwndRestore), 0L)
#define HANDLE_WM_ENTERIDLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)(lParam)), 0L)
#define FORWARD_WM_ENTERIDLE(hwnd, source, hwndSource, fn) \
    (void)(fn)((hwnd), WM_ENTERIDLE, (WPARAM)(UINT)(source), (LPARAM)(HWND)(hwndSource))
#define HANDLE_WM_SETFONT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HFONT)(wParam), (BOOL)(lParam)), 0L)
#define FORWARD_WM_SETFONT(hwnd, hfont, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETFONT, (WPARAM)(HFONT)(hfont), (LPARAM)(BOOL)(fRedraw))
#define FORWARD_WM_HOTKEY(hwnd, idHotKey, fuModifiers, vk, fn) \
    (void)(fn)((hwnd), WM_HOTKEY, (WPARAM)(idHotKey), MAKELPARAM((fuModifiers), (vk)))
#define ComboBox_Enable(hwndCtl, fEnable)       EnableWindow((hwndCtl), (fEnable))
#define GET_WM_ACTIVATE_HWND(wp, lp)            (HWND)(lp)
#define GET_WM_COMMAND_HWND(wp, lp)             (HWND)(lp)
#define GET_WM_MENUSELECT_HMENU(wp, lp)             (HMENU)(lp)
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (lp == (LPARAM)hwnd)
#define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)(wp)
#define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)(lp)
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
        (WPARAM)(hwndA), 0
#define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW) (WPARAM)hmenuF, (LPARAM)hmenuW
#define GET_WM_VKEYTOITEM_HWND(wp, lp)              (HWND)(lp)
#define GET_WM_HSCROLL_HWND(wp, lp)                 (HWND)(lp)
#define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)(lp)

// sdktools\appcompat\appcompat.rc
#define TABGRP  (WS_TABSTOP | WS_GROUP)

// sdktools\cntrtext\showperf\showperf.h
#define SEND_WM_COMMAND(w,c,n,cw)  SendMessage (w, WM_COMMAND, MAKEWPARAM(c,n), (LPARAM)cw)

// sdktools\gutils\gutils.h
#define GET_WM_COMMAND_HWND(w, l) (l)

// sdktools\mttf\setup\comstf.h
#define FEolChp(chp)         ((BOOL)((chp) == '\n' || (chp) == '\r'))
#define  ofmWrite          ((OFM)OF_WRITE | OF_SHARE_EXCLUSIVE)
#define  ofmReadWrite      ((OFM)OF_READWRITE | OF_SHARE_EXCLUSIVE)
#define  ofmCreate         ((OFM)OF_CREATE | OF_SHARE_EXCLUSIVE)
#define  MessBoxSzSz(szTitle, szText) \
		MessageBox((HWND)NULL, (LPSTR)szText, (LPSTR)szTitle, \
				MB_TASKMODAL | MB_ICONHAND | MB_OK)

// sdktools\nmake\lexer.cpp
#define COMMENT(A,B,C)      (((A) == ';' && B && C) || ((A) == '#'))

// sdktools\perfmon\alert.h
#define AlertData(hWndAlert)        \
   (&Alert)

// sdktools\perfmon\legend.c
#define  LegendData(hWnd)     \
   ((hWnd == hWndGraphLegend) ? pGraphLegendData : pAlertLegendData )

// sdktools\perfmon\owndraw.h
#define DIWindow(lpDI)              \
   (lpDI->hwndItem)

// sdktools\perfmon\report.h
#define ReportData(hWndReport)      \
   (&Report)

// sdktools\perfmon\utils.h
#define WindowShow(hWnd, bShow)                       \
   (ShowWindow (hWnd, (bShow) ? SW_SHOW : SW_HIDE))

// sdktools\perfmon\winhelpr.h
#define SetFont(hWnd, hFont)                          \
   (SendMessage ((hWnd), WM_SETFONT, (WPARAM) hFont, 0))
#define CBData(hWndCB, iIndex)                        \
   (SendMessage (hWndCB, CB_GETITEMDATA, iIndex, 0L))
#define CBSetData(hWndCB, iIndex, lData)              \
   (SendMessage (hWndCB, CB_SETITEMDATA, iIndex, (LPARAM) lData))
#define CBAdd(hWndCB, lpszText)                       \
   ((int)(DWORD)SendMessage((hWndCB), CB_ADDSTRING,   \
    0, (LPARAM)(LPCSTR)(lpszText)))
#define CBFind(hWndCB, lpszText)                      \
   (SendMessage (hWndCB, CB_FINDSTRING, 0xFFFFFFFF, (LPARAM) lpszText))
#define CBInsert(hWndCB, iIndex, lpszText)            \
   (SendMessage (hWndCB, CB_INSERTSTRING, (WPARAM) iIndex, (LPARAM) lpszText))
#define CBReset(hWndCB)                               \
   ((int)(DWORD)SendMessage((hWndCB), CB_RESETCONTENT,\
    0, (LPARAM)0))
#define CBSelection(hWndCB)                           \
   (SendMessage (hWndCB, CB_GETCURSEL, 0, 0L))
#define CBSetSelection(hWndCB, iIndex)                \
   (SendMessage (hWndCB, CB_SETCURSEL, iIndex, 0L))
#define CBString(hWndCB, iIndex, lpszText)            \
   (SendMessage (hWndCB, CB_GETLBTEXT, iIndex, (LPARAM) lpszText))
#define CBStringLen(hWndCB, iIndex)                   \
   (SendMessage (hWndCB, CB_GETLBTEXTLEN, iIndex, 0L))
#define LBAdd(hWndLB, lpszText)                       \
   (SendMessage (hWndLB, LB_ADDSTRING, 0, (LPARAM) lpszText))
#define LBData(hWndLB, iIndex)                        \
   (SendMessage (hWndLB, LB_GETITEMDATA, iIndex, 0L))
#define LBFind(hWndLB, lpszText)                      \
   (SendMessage (hWndLB, LB_FINDSTRING, (WPARAM) -1, (LPARAM) lpszText))
#define LBFocus(hWndLB)                               \
   (SendMessage (hWndLB, LB_GETCARETINDEX, 0, 0))
#define LBInsert(hWndLB, iIndex, lpszText)            \
   (SendMessage (hWndLB, LB_INSERTSTRING, (WPARAM) iIndex, (LPARAM) lpszText))
#define LBNumItems(hWndLB)                            \
   ((int) SendMessage (hWndLB, LB_GETCOUNT, 0, 0))
#define LBReset(hWndLB)                               \
   ((int)(DWORD)SendMessage((hWndLB), LB_RESETCONTENT,\
    0, (LPARAM)0))
#define LBSelected(hwndLB, index)                     \
   ((int)(DWORD)SendMessage((hwndLB), LB_GETSEL,      \
    (WPARAM)(int)(index), 0L))
#define LBSelection(hWndLB)                           \
   (SendMessage (hWndLB, LB_GETCURSEL, 0, 0L))
#define LBSetData(hWndLB, iIndex, lData)              \
   (SendMessage (hWndLB, LB_SETITEMDATA, iIndex, (LPARAM) lData))
#define LBSetSelection(hWndLB, iIndex)                \
   (SendMessage (hWndLB, LB_SETCURSEL, iIndex, 0L))
#define LBString(hwndLB, iIndex, lpszText)            \
   ((int)(DWORD)SendMessage((hwndLB), LB_GETTEXT,     \
    (WPARAM)(int)(iIndex), (LPARAM)(LPCSTR)(lpszText)))
#define MLBSetSelection(hWndMLB, iIndex, bSet)        \
   (SendMessage (hWndMLB, LB_SETSEL, (WPARAM) bSet, (LPARAM) iIndex))
#define LBSetVisible(hWndLB, iIndex)                  \
   (SendMessage (hWndLB, LB_SETCARETINDEX, (WPARAM) iIndex, 0L))
#define LBSetRedraw(hWndLB, bDrawOnOff)               \
   (SendMessage (hWndLB, WM_SETREDRAW, (WPARAM) bDrawOnOff, 0L))
#define LBSetHorzExtent(hWndLB, wExtent)              \
   (SendMessage (hWndLB, LB_SETHORIZONTALEXTENT, (WPARAM)wExtent, 0L))
#define EditModified(hWndEdit)                        \
   (SendMessage ((hWndEdit), EM_GETMODIFY, (WPARAM) 0, (LPARAM) 0))
#define EditSetModified(hWndEdit, bModified)                     \
   (SendMessage ((hWndEdit), EM_SETMODIFY, (WPARAM) bModified, 0))
#define EditSetLimit(hWndEdit, iLimit)                \
   (SendMessage ((hWndEdit), EM_LIMITTEXT, (WPARAM) iLimit, 0))
#define EditSetTextPos(hWnd, idControl, iStartPos, iEndPos)    \
   (SendMessage (GetDlgItem(hWnd, idControl), EM_SETSEL, (WPARAM) iStartPos, (LPARAM) iEndPos))

// sdktools\restools\mui\muisetup\muisetup.h
   #define ListView_SetCheckState(hwndLV, i, fCheck) \
      ListView_SetItemState(hwndLV, i, \
      INDEXTOSTATEIMAGEMASK((fCheck)+1), LVIS_STATEIMAGEMASK)

// sdktools\restools\rltools\common\dosdefs.h
#define FOPEN(sz)                ((_ret=-1),(_error=_dos_open(sz,O_RDONLY,&_ret)),_ret)
#define FCREATE(sz)              ((_ret=-1),(_error=_dos_creat(sz,_A_NORMAL,&_ret)),_ret)
#define FREAD(fh,buf,len)        ((_error=_dos_read(fh,buf,len,&_ret)),_ret)
#define FWRITE(fh,buf,len)       ((_error=_dos_write(fh,buf,len,&_ret)),_ret)

// sdktools\sdv\sdview.h
#define ListView_GetItemText(hwnd, iItem, pszBuf, cch) \
        ListView_GetSubItemText(hwnd, iItem, 0, pszBuf, cch)

// sdktools\setedit\owndraw.h
#define DIWindow(lpDI)              \
   (lpDI->hwndItem)

// sdktools\setedit\utils.h
#define WindowShow(hWnd, bShow)                       \
   (ShowWindow (hWnd, (bShow) ? SW_SHOW : SW_HIDE))

// sdktools\setedit\winhelpr.h
#define SetFont(hWnd, hFont)                          \
   (SendMessage ((hWnd), WM_SETFONT, (WPARAM) hFont, 0))
#define CBData(hWndCB, iIndex)                        \
   (SendMessage (hWndCB, CB_GETITEMDATA, iIndex, 0L))
#define CBSetData(hWndCB, iIndex, lData)              \
   (SendMessage (hWndCB, CB_SETITEMDATA, iIndex, (LONG) lData))
#define CBAdd(hWndCB, lpszText)                       \
   ((int)(DWORD)SendMessage((hWndCB), CB_ADDSTRING,   \
    0, (LPARAM)(LPCSTR)(lpszText)))
#define CBFind(hWndCB, lpszText)                      \
   (SendMessage (hWndCB, CB_FINDSTRING, 0xFFFFFFFF, (LPARAM) lpszText))
#define CBInsert(hWndCB, iIndex, lpszText)            \
   (SendMessage (hWndCB, CB_INSERTSTRING, (WPARAM) iIndex, (LPARAM) lpszText))
#define CBReset(hWndCB)                               \
   ((int)(DWORD)SendMessage((hWndCB), CB_RESETCONTENT,\
    0, (LPARAM)0))
#define CBSelection(hWndCB)                           \
   (SendMessage (hWndCB, CB_GETCURSEL, 0, 0L))
#define CBSetSelection(hWndCB, iIndex)                \
   (SendMessage (hWndCB, CB_SETCURSEL, iIndex, 0L))
#define CBString(hWndCB, iIndex, lpszText)            \
   (SendMessage (hWndCB, CB_GETLBTEXT, iIndex, (LPARAM) lpszText))
#define CBStringLen(hWndCB, iIndex)                   \
   (SendMessage (hWndCB, CB_GETLBTEXTLEN, iIndex, 0L))
#define LBAdd(hWndLB, lpszText)                       \
   (SendMessage (hWndLB, LB_ADDSTRING, 0, (LPARAM) lpszText))
#define LBData(hWndLB, iIndex)                        \
   (SendMessage (hWndLB, LB_GETITEMDATA, iIndex, 0L))
#define LBFind(hWndLB, lpszText)                      \
   (SendMessage (hWndLB, LB_FINDSTRING, (WPARAM) -1, (LPARAM) lpszText))
#define LBFocus(hWndLB)                               \
   (SendMessage (hWndLB, LB_GETCARETINDEX, 0, 0))
#define LBInsert(hWndLB, iIndex, lpszText)            \
   (SendMessage (hWndLB, LB_INSERTSTRING, (WPARAM) iIndex, (LPARAM) lpszText))
#define LBNumItems(hWndLB)                            \
   ((int) SendMessage (hWndLB, LB_GETCOUNT, 0, 0))
#define LBReset(hWndLB)                               \
   ((int)(DWORD)SendMessage((hWndLB), LB_RESETCONTENT,\
    0, (LPARAM)0))
#define LBSelected(hwndLB, index)                     \
   ((int)(DWORD)SendMessage((hwndLB), LB_GETSEL,      \
    (WPARAM)(int)(index), 0L))
#define LBSelection(hWndLB)                           \
   (SendMessage (hWndLB, LB_GETCURSEL, 0, 0L))
#define LBSetData(hWndLB, iIndex, lData)              \
   (SendMessage (hWndLB, LB_SETITEMDATA, iIndex, (LONG) lData))
#define LBSetSelection(hWndLB, iIndex)                \
   (SendMessage (hWndLB, LB_SETCURSEL, iIndex, 0L))
#define LBString(hwndLB, iIndex, lpszText)            \
   ((int)(DWORD)SendMessage((hwndLB), LB_GETTEXT,     \
    (WPARAM)(int)(iIndex), (LPARAM)(LPCSTR)(lpszText)))
#define MLBSetSelection(hWndMLB, iIndex, bSet)        \
   (SendMessage (hWndMLB, LB_SETSEL, (WPARAM) bSet, (LPARAM) iIndex))
#define LBSetVisible(hWndLB, iIndex)                  \
   (SendMessage (hWndLB, LB_SETCARETINDEX, (WPARAM) iIndex, 0L))
#define LBSetRedraw(hWndLB, bDrawOnOff)               \
   (SendMessage (hWndLB, WM_SETREDRAW, (WPARAM) bDrawOnOff, 0L))
#define LBSetHorzExtent(hWndLB, wExtent)              \
   (SendMessage (hWndLB, LB_SETHORIZONTALEXTENT, (WPARAM)wExtent, 0L))
#define EditModified(hWndEdit)                        \
   (SendMessage ((hWndEdit), EM_GETMODIFY, (WPARAM) 0, (LPARAM) 0))
#define EditSetModified(hWndEdit, bModified)                     \
   (SendMessage ((hWndEdit), EM_SETMODIFY, (WPARAM) bModified, 0))
#define EditSetLimit(hWndEdit, iLimit)                \
   (SendMessage ((hWndEdit), EM_LIMITTEXT, (WPARAM) iLimit, 0))
#define EditSetTextPos(hWnd, idControl, iStartPos, iEndPos)    \
   (SendMessage (GetDlgItem(hWnd, idControl), EM_SETSEL, (WPARAM) iStartPos, (LPARAM) iEndPos))

// sdktools\tweakui\control.cpp
#define pcplIcpl(icpl) (&pcpii->pcpl[icpl])
#define pcpii (&cpii)

// sdktools\tweakui\lv.cpp
#define ListView_SetExtendedListViewStyle(hwndLV, dw)\
        (DWORD)SNDMSG((hwndLV), LVM_SETEXTENDEDLISTVIEWSTYLE, 0, dw)

// sdktools\tweakui\mycomp.cpp
#define pdmi (&mdi)

// sdktools\tweakui\tweakui.h
#define g_fBuggyComCtl32        (g_flWeirdStuff & flbsComCtl32)
#define g_fShellSz              (g_flWeirdStuff & flbsShellSz)

// sdktools\unicows\godot\hook.h
#define INIT_WINDOW_SNIFF(h) \
    h = SetWindowsHookExA(WH_CBT, &CBTProc, NULL, GetCurrentThreadId())

// sdktools\vi\nt.c
#define CONTROL_ALT (ALT_PRESSED | CTL_PRESSED)

// sdktools\winobj\wfext.h
#define FM_REFRESH_WINDOWS  (WM_USER + 0x0206)

// shell\applets\taskmgr\taskmgr.h
#define PM_NOTIFYWAITING    (WM_USER + 2)
#define PM_QUITTRAYTHREAD   (WM_USER + 3)
#define PM_INITIALIZEICONS  (WM_USER + 4)

// shell\browseui\admovr2.h
#define OLEMISMOVR (OLEMISC_ALWAYSRUN|OLEMISC_NOUIACTIVATE|OLEMISC_SETCLIENTSITEFIRST|OLEMISC_ACTIVATEWHENVISIBLE|OLEMISC_RECOMPOSEONRESIZE|OLEMISC_CANTLINKINSIDE|OLEMISC_INSIDEOUT)

// shell\browseui\brand.cpp
#define BM_BANDINFOCHANGED  (WM_USER + 1)

// shell\browseui\dockbar.h
#define ABE_HORIZ(e)    ((e) & 1)
#define ISWBM_EDGELESS(eMode) \
    ((eMode==WBM_BBOTTOMMOST && ISWSX_EDGELESS(WS_BBTMMOST, WS_EX_BBTMMOST)) \
    || (eMode==WBM_BOTTOMMOST && ISWSX_EDGELESS(WS_BTMMOST, WS_EX_BTMMOST)))
#define WBM_BBOTTOMMOST (WBMF_BROWSER|WBM_BOTTOMMOST)
#define ISWBM_BOTTOM(eMode) \
    ((eMode) == WBM_BOTTOMMOST || (eMode) == WBM_BBOTTOMMOST)
#define ISWBM_DESKTOP()     (!(_eMode & WBMF_BROWSER))
#define CHKWBM_CHANGE(eModeNew, eModeCur) \
    (((eModeNew) & WBMF_BROWSER) == ((eModeCur) & WBMF_BROWSER) \
        || (eModeNew) == WBM_NIL || (eModeCur) == WBM_NIL)
#define MSTOSIDE(ms)    (((UINT) (ms)) & 0x7)

// shell\browseui\emclient\regdb.cpp
#define IsREG_XX_SZ(dwTyp) \
    ((dwTyp) == REG_SZ || (dwTyp) == REG_MULTI_SZ || (dwTyp) == REG_EXPAND_SZ)

// shell\browseui\globals.h
#define ISVISIBLE(hwnd)  ((GetWindowStyle(hwnd) & WS_VISIBLE) == WS_VISIBLE)
#define FillExecInfo(_info, _hwnd, _verb, _file, _params, _dir, _show) \
        (_info).hwnd            = _hwnd;        \
        (_info).lpVerb          = _verb;        \
        (_info).lpFile          = _file;        \
        (_info).lpParameters    = _params;      \
        (_info).lpDirectory     = _dir;         \
        (_info).nShow           = _show;        \
        (_info).fMask           = 0;            \
        (_info).cbSize          = sizeof(SHELLEXECUTEINFO);

// shell\browseui\itbar.cpp
#define IS_LIST_STYLE(hwnd) (BOOLIFY(GetWindowLong(hwnd, GWL_STYLE) & TBSTYLE_LIST))

// shell\browseui\itbar.h
#define BandIDtoIndex(hwnd, idx) SendMessage(hwnd, RB_IDTOINDEX, idx, 0)

// shell\browseui\legacy\isfband.cpp
#define CISFBAND_GETBUTTONSIZE()  (_hwndTB ?  (LONG)SendMessage(_hwndTB, TB_GETBUTTONSIZE, 0, 0L) : MAKELONG(16, 16))

// shell\browseui\mediaband.h
#define ISVALIDWIDGET(x)    (x && x->_hwnd)

// shell\browseui\onetree.h
#define OTIsShared(lpnd)                    ((lpnd)->dwAttribs & SFGAO_SHARE)
#define OTIsRemovableRoot(lpnd)             (((lpnd)->dwAttribs & (SFGAO_REMOVABLE | SFGAO_FILESYSANCESTOR)) == (SFGAO_REMOVABLE | SFGAO_FILESYSANCESTOR))

// shell\browseui\progress.cpp
#define PDM_TERMTHREAD  (WM_APP + 1)
#define PDM_UPDATE      (WM_APP + 2)

// shell\browseui\shbrows2.cpp
#define CWM_THEATERMODE                 (WM_USER + 400)
#define FRAME_OPTIONS_TO_TEST      (BFO_ADD_IE_TOCAPTIONBAR | BFO_USE_DIALUP_REF | BFO_USE_IE_TOOLBAR | \
                                    BFO_BROWSER_PERSIST_SETTINGS | BFO_USE_IE_OFFLINE_SUPPORT)

// shell\browseui\unixstuff.cpp
#define WMC_UNIX_NEWWINDOW            (WM_USER + 0x0400)

// shell\browseui\util.h
#define PVAREMPTY ((VARIANT*)&c_vaEmpty)

// shell\comctl32\v5\ccver.h
#define VER_FILEVERSION_DW          (0x05520000 | VER_PRODUCTBUILD)

// shell\comctl32\v5\ccverp.h
#define VER_PRODUCTVERSION_DW       (0x04460000 | COMCTL32_BUILD_NUMBER)

// shell\comctl32\v5\comboex.c
#define ComboEx_GetItemPtr(pce, iItem) \
        ((PCEITEM)SendMessage((pce)->hwndCombo, CB_GETITEMDATA, iItem, 0))
#define ComboEx_Count(pce) \
        ((int)SendMessage((pce)->hwndCombo, CB_GETCOUNT, 0, 0))

// shell\comctl32\v5\ctlspriv.h
#define CCResetInfoTipWidth(hwndOwner, hwndToolTips) \
    SendMessage(hwndToolTips, TTM_SETMAXTIPWIDTH, 0, -1)

// shell\comctl32\v5\cutils.c
#define ISDIGIT(c)  ((c) >= '0' && (c) <= '9')

// shell\comctl32\v5\da.c
#define IsDSA(pdsa) ((pdsa) && (pdsa)->magic == DSA_MAGIC)
#define IsDPA(pdpa) ((pdpa) && (pdpa)->magic == DPA_MAGIC)
#define SortCompare(psp, pp1, i1, pp2, i2) \
    (psp->pfnCmp(pp1[i1], pp2[i2], psp->lParam))

// shell\comctl32\v5\flat_sb.c
#define IsHottrackable(STYLE)   ((STYLE == FSB_FLAT_MODE) || (STYLE == FSB_ENCARTA_MODE))

// shell\comctl32\v5\flat_sb.h
#define WSB_VERT   (WSB_VERT_UP | WSB_VERT_DN)
#define WSB_HORZ   (WSB_HORZ_LF | WSB_HORZ_RT)

// shell\comctl32\v5\hotkey.c
            #define IsFUNKEY(vk) ((vk) >= VK_F1 && (vk) <= VK_F24)

// shell\comctl32\v5\listview.c
#define ListView_CancelPendingEdit(plv) ListView_CancelPendingTimer(plv, LVF_NMEDITPEND, IDT_NAMEEDIT)
#define ListView_CancelScrollWait(plv) ListView_CancelPendingTimer(plv, LVF_SCROLLWAIT, IDT_SCROLLWAIT)

// shell\comctl32\v5\listview.h
#define ListView_GetPtr(hwnd)      (LV*)GetWindowPtr(hwnd, 0)
#define ListView_SetPtr(hwnd, p)   (LV*)SetWindowPtr(hwnd, 0, p)
#define ListView_IsIconView(plv)    (((plv)->ci.style & (UINT)LVS_TYPEMASK) == (UINT)LVS_ICON)
#define ListView_IsSmallView(plv)   (((plv)->ci.style & (UINT)LVS_TYPEMASK) == (UINT)LVS_SMALLICON)
#define ListView_IsListView(plv)    (((plv)->ci.style & (UINT)LVS_TYPEMASK) == (UINT)LVS_LIST)
#define ListView_IsReportView(plv)  (((plv)->ci.style & (UINT)LVS_TYPEMASK) == (UINT)LVS_REPORT)
#define ListView_IsOwnerData( plv )     (plv->ci.style & (UINT)LVS_OWNERDATA)
#define ListView_CheckBoxes(plv)        (plv->exStyle & LVS_EX_CHECKBOXES)
#define ListView_FullRowSelect(plv)     (plv->exStyle & LVS_EX_FULLROWSELECT)
#define ListView_IsInfoTip(plv)         (plv->exStyle & LVS_EX_INFOTIP)
#define ListView_OwnerDraw(plv)         (plv->ci.style & LVS_OWNERDRAWFIXED)
#define ListView_IsLabelTip(plv)        (plv->exStyle & LVS_EX_LABELTIP)
#define ListView_RedrawEnabled(plv) ((plv->flags & (LVF_REDRAW | LVF_VISIBLE)) == (LVF_REDRAW|LVF_VISIBLE))
#define ListView_ZOrderIndex(plv, i) DPA_GetPtrIndex((plv)->hdpaZOrder, IntToPtr(i))
#define ListView_CancelPendingEdit(plv) ListView_CancelPendingTimer(plv, LVF_NMEDITPEND, IDT_NAMEEDIT)
#define ListView_CancelScrollWait(plv) ListView_CancelPendingTimer(plv, LVF_SCROLLWAIT, IDT_SCROLLWAIT)
#define ListView_InvalidateItem(p,i,s,r) ListView_InvalidateItemEx(p,i,s,r,0)
#define ListView_GetItemPtr(plv, i)         ((LISTITEM FAR*)DPA_GetPtr((plv)->hdpa, (i)))
#define ListView_FastGetItemPtr(plv, i)     ((LISTITEM FAR*)DPA_GetPtr((plv)->hdpa, (i)))
#define ListView_FastGetZItemPtr(plv, i)    ((LISTITEM FAR*)DPA_GetPtr((plv)->hdpa, \
                                                  (int)OFFSETOF(DPA_GetPtr((plv)->hdpaZOrder, (i)))))
#define ListView_FastGetItemPtr(plv, i)     ((LISTITEM FAR*)DPA_FastGetPtr((plv)->hdpa, (i)))
#define ListView_FastGetZItemPtr(plv, i)    ((LISTITEM FAR*)DPA_FastGetPtr((plv)->hdpa, \
                                                  (int)OFFSETOF(DPA_FastGetPtr((plv)->hdpaZOrder, (i)))))
#define ListView_GetScrollInfo(plv, flag, lpsi)                             \
    ((plv)->exStyle & LVS_EX_FLATSB ?                                       \
        FlatSB_GetScrollInfo((plv)->ci.hwnd, (flag), (lpsi)) :              \
        GetScrollInfo((plv)->ci.hwnd, (flag), (lpsi)))
#define ListView_SetScrollRange(plv, flag, min, max, fredraw)               \
    ((plv)->exStyle & LVS_EX_FLATSB ?                                       \
        FlatSB_SetScrollRange((plv)->ci.hwnd, (flag), (min), (max), (fredraw)) : \
        SetScrollRange((plv)->ci.hwnd, (flag), (min), (max), (fredraw)))
#define ListView_DrawImage(plv, pitem, hdc, x, y, fDraw) \
        ListView_DrawImageEx(plv, pitem, hdc, x, y, fDraw, -1)
#define ListView_RYHitTest(plv, cy)  ((int)(((cy) + plv->ptlRptOrigin.y - plv->yTop) / plv->cyItem))
#define ListView_GetSubItemDPA(plv, idpa) \
    ((HDPA)DPA_GetPtr((plv)->hdpaSubItems, (idpa)))
#define _ListView_DrawItem(plvdi) \
        pfnListView_DrawItem[LV_TYPEINDEX(plvdi->plv)](plvdi)
#define _ListView_UpdateScrollBars(plv) \
        pfnListView_UpdateScrollBars[LV_TYPEINDEX(plv)](plv)
#define _ListView_ApproximateViewRect(plv, iCount, iWidth, iHeight) \
        pfnListView_ApproximateViewRect[LV_TYPEINDEX(plv)](plv, iCount, iWidth, iHeight)
#define _ListView_ItemHitTest(plv, x, y, pflags, piSubItem) \
        pfnListView_ItemHitTest[LV_TYPEINDEX(plv)](plv, x, y, pflags, piSubItem)
#define _ListView_OnScroll(plv, x, y, pflags) \
        pfnListView_OnScroll[LV_TYPEINDEX(plv)](plv, x, y, pflags)
#define _ListView_Scroll2(plv, x, y, pflags) \
        pfnListView_Scroll2[LV_TYPEINDEX(plv)](plv, x, y, pflags)
#define _ListView_GetScrollUnitsPerLine(plv, sb) \
        pfnListView_GetScrollUnitsPerLine[LV_TYPEINDEX(plv)](plv, sb)

// shell\comctl32\v5\lvfile.c
#define ListView_Write(hwndLV, pstm, flags)     /* ;Internal */ \
    (BOOL)SendMessage((hwndLV), LVM_WRITE,      /* ;Internal */ \
    (WPARAM)(BOOL)(flags),                      /* ;Internal */  \
            (LPARAM)(STREAM FAR*)(pstm))                                  /* ;Internal */
#define ListView_Read(plv, pinfo)                                         /* ;Internal */

// shell\comctl32\v5\monthcal.c
#define MCMP_WINDOWPOSCHANGED (MCM_FIRST - 1) // MCM_FIRST is way over WM_USER
#define DTMP_WINDOWPOSCHANGED (DTM_FIRST - 1) // DTM_FIRST is way over WM_USER

// shell\comctl32\v5\monthcal.h
#define SE_YEARLIKE(s)      ((s) == SE_YEAR || (s) == SE_YEARALT)
#define MonthCal_IsMultiSelect(pmc)     ((pmc)->ci.style & MCS_MULTISELECT)
#define MonthCal_ShowWeekNumbers(pmc)   ((pmc)->ci.style & MCS_WEEKNUMBERS)
#define MonthCal_ShowTodayCircle(pmc)   (!((pmc)->ci.style & MCS_NOTODAYCIRCLE))
#define MonthCal_ShowToday(pmc)         (!((pmc)->ci.style & MCS_NOTODAY))
#define DatePick_AppCanParse(pdp)   ((pdp)->ci.style & DTS_APPCANPARSE)

// shell\comctl32\v5\prshti.h
#define PSH_WIZARD97        (PSH_WIZARD97IE4 | PSH_WIZARD97IE5)
#define GETPPSP(ppd, i) (&GETPISP(ppd, i)->_psp)

// shell\comctl32\v5\rebar.c
#define RB_ISVERT(prb)  ((prb)->ci.style & CCS_VERT)
#define RB_ISVERTICALGRIPPER(prb) (RB_ISVERT(prb) && (prb)->ci.style & RBS_VERTICALGRIPPER)

// shell\comctl32\v5\tab.c
#define ETO_ME_CLIPPED (ETO_CLIPPED | pitem->etoRtlReading | (ptc->ci.dwExStyle & WS_EX_RTLREADING ? ETO_RTLREADING : 0 ))

// shell\comctl32\v5\tab.h
#define Tab_DrawButtons(ptc)            ((BOOL)(ptc->ci.style & TCS_BUTTONS))
#define Tab_MultiLine(ptc)              ((BOOL)(ptc->ci.style & TCS_MULTILINE))
#define Tab_RaggedRight(ptc)            ((BOOL)(ptc->ci.style & TCS_RAGGEDRIGHT))
#define Tab_FixedWidth(ptc)             ((BOOL)(ptc->ci.style & TCS_FIXEDWIDTH))
#define Tab_Vertical(ptc)               ((BOOL)(ptc->ci.style & TCS_VERTICAL))
#define Tab_Bottom(ptc)                 ((BOOL)(ptc->ci.style & TCS_BOTTOM))
#define Tab_ForceLabelLeft(ptc)         ((BOOL)(ptc->ci.style & TCS_FORCELABELLEFT))
#define Tab_ForceIconLeft(ptc)          ((BOOL)(ptc->ci.style & TCS_FORCEICONLEFT))
#define Tab_FocusOnButtonDown(ptc)      ((BOOL)(ptc->ci.style & TCS_FOCUSONBUTTONDOWN))
#define Tab_OwnerDraw(ptc)              ((BOOL)(ptc->ci.style & TCS_OWNERDRAWFIXED))
#define Tab_FocusNever(ptc)             ((BOOL)(ptc->ci.style & TCS_FOCUSNEVER))
#define Tab_HotTrack(ptc)             ((BOOL)(ptc->ci.style & TCS_HOTTRACK))
#define Tab_MultiSelect(ptc)            ((BOOL)(ptc->ci.style & TCS_MULTISELECT))
#define Tab_FlatButtons(ptc)            ((BOOL)((ptc)->ci.style & TCS_FLATBUTTONS))
#define Tab_FlatSeparators(ptc)         ((BOOL)((ptc)->dwStyleEx & TCS_EX_FLATSEPARATORS))

// shell\comctl32\v5\tbcust.c
#define SEND_WM_COMMAND(hwnd, id, hwndCtl, codeNotify) \
    (void)SendMessage((hwnd), WM_COMMAND, MAKEWPARAM((UINT)(id),(UINT)(codeNotify)), (LPARAM)(HWND)(hwndCtl))

// shell\comctl32\v5\tooltips.c
#define TTToolHwnd(pTool)  ((pTool->uFlags & TTF_IDISHWND) ? (HWND)pTool->uId : pTool->hwnd)
#define IsToolbarWindow(hwnd) \
    (SendMessage(hwnd, WM_GETOBJECT, 0, OBJID_QUERYCLASSNAMEIDX) == MSAA_CLASSNAMEIDX_TOOLBAR)
#define HittestInTool(pTool, hwnd, ht) \
    ((pTool->uFlags & TTF_USEHITTEST) && pTool->hwnd == hwnd && ht == pTool->rect.left)

// shell\comctl32\v5\trackbar.c
#define ISVERT(tb) (tb->ci.style & TBS_VERT)

// shell\comctl32\v5\treeview.c
#define REPEATTIME      SendMessage(pTree->hwndToolTips,TTM_GETDELAYTIME,(WPARAM)TTDT_RESHOW, 0)

// shell\comctl32\v6\ccver.h
#define VER_FILEVERSION_DW          (0x05500000 | VER_PRODUCTBUILD)
#define VER_FILEVERSION_DW          (0x05510000 | VER_PRODUCTBUILD)
#define VER_FILEVERSION_DW          (0x06000000 | VER_PRODUCTBUILD)

// shell\comctl32\v6\ccverp.h
#define VER_PRODUCTVERSION_DW       (0x04460000 | COMCTL32_BUILD_NUMBER)

// shell\comctl32\v6\combo.h
#define IsComboVisible(pcbox)   \
            (!pcbox->fNoRedraw && IsWindowVisible(pcbox->hwnd))
#define ComboBox_GetPtr(hwnd)    \
            (PCBOX)GetWindowPtr(hwnd, 0)
#define ComboBox_SetPtr(hwnd, p) \
            (PCBOX)SetWindowPtr(hwnd, 0, p)

// shell\comctl32\v6\comboex.c
#define ComboEx_GetItemPtr(pce, iItem) \
        ((PCEITEM)SendMessage((pce)->hwndCombo, CB_GETITEMDATA, iItem, 0))
#define ComboEx_Count(pce) \
        ((int)SendMessage((pce)->hwndCombo, CB_GETCOUNT, 0, 0))

// shell\comctl32\v6\ctlspriv.h
#define CCResetInfoTipWidth(hwndOwner, hwndToolTips) \
    SendMessage(hwndToolTips, TTM_SETMAXTIPWIDTH, 0, -1)

// shell\comctl32\v6\da.c
#define IsDSA(pdsa) ((pdsa) && (pdsa)->magic == DSA_MAGIC)
#define IsDPA(pdpa) ((pdpa) && (pdpa)->magic == DPA_MAGIC)
#define SortCompare(psp, pp1, i1, pp2, i2) \
    (psp->pfnCmp(pp1[i1], pp2[i2], psp->lParam))

// shell\comctl32\v6\edit.h
#define ISDELIMETERA(ch)    \
            ((ch == ' ') || (ch == '\t'))
#define ISDELIMETERW(ch)    \
            ((ch == L' ') || (ch == L'\t'))

// shell\comctl32\v6\header.c
#define Header_IsFilter(phd) ((phd)->ci.style & HDS_FILTERBAR)

// shell\comctl32\v6\hotkey.c
            #define IsFUNKEY(vk) ((vk) >= VK_F1 && (vk) <= VK_F24)

// shell\comctl32\v6\link.cpp
#define TEST_CAPTURE(fTest)           ((_fCapture & fTest) != 0)
#define MODIFY_CAPTURE(fSet, fRemove) {if (fSet){_fCapture |= fSet;} if (fRemove){_fCapture &= ~fRemove;}}

// shell\comctl32\v6\listbox.h
#define IsLBoxVisible(plb)  \
            (plb->fRedraw && IsWindowVisible(plb->hwnd))

// shell\comctl32\v6\listview.h
#define ListView_GetPtr(hwnd)      (LV*)GetWindowPtr(hwnd, 0)
#define ListView_SetPtr(hwnd, p)   (LV*)SetWindowPtr(hwnd, 0, p)
#define ListView_IsIconView(plv)    ((plv)->wView == LV_VIEW_ICON)
#define ListView_IsTileView(plv)    ((plv)->wView == LV_VIEW_TILE)
#define ListView_IsSmallView(plv)   ((plv)->wView == LV_VIEW_SMALLICON)
#define ListView_IsListView(plv)    ((plv)->wView == LV_VIEW_LIST)
#define ListView_IsReportView(plv)  ((plv)->wView == LV_VIEW_DETAILS)
#define ListView_IsAutoArrangeView(plv) ((((plv)->wView == LV_VIEW_ICON) || ((plv)->wView == LV_VIEW_SMALLICON) || ((plv)->wView == LV_VIEW_TILE)))
#define ListView_IsSlotView(plv) ((((plv)->wView == LV_VIEW_ICON) || ((plv)->wView == LV_VIEW_SMALLICON) || ((plv)->wView == LV_VIEW_TILE)))
#define ListView_UseLargeIcons(plv) (((plv)->wView == LV_VIEW_ICON) || ((plv)->wView == LV_VIEW_TILE))
#define ListView_IsRearrangeableView(plv) (((plv)->wView == LV_VIEW_ICON) || ((plv)->wView == LV_VIEW_SMALLICON) || ((plv)->wView == LV_VIEW_TILE))
#define ListView_IsIScrollView(plv) (((plv)->wView == LV_VIEW_ICON) || ((plv)->wView == LV_VIEW_SMALLICON) || ((plv)->wView == LV_VIEW_TILE))
#define ListView_IsGroupedView(plv) ((plv)->wView != LV_VIEW_LIST)
#define ListView_IsOwnerData( plv )     (plv->ci.style & (UINT)LVS_OWNERDATA)
#define ListView_CheckBoxes(plv)        (plv->exStyle & LVS_EX_CHECKBOXES)
#define ListView_FullRowSelect(plv)     (plv->exStyle & LVS_EX_FULLROWSELECT)
#define ListView_IsInfoTip(plv)         (plv->exStyle & LVS_EX_INFOTIP)
#define ListView_OwnerDraw(plv)         (plv->ci.style & LVS_OWNERDRAWFIXED)
#define ListView_IsLabelTip(plv)        (plv->exStyle & LVS_EX_LABELTIP)
#define ListView_SingleRow(plv)         (plv->exStyle & LVS_EX_SINGLEROW)
#define ListView_HideLabels(plv)        (plv->exStyle & LVS_EX_HIDELABELS)
#define ListView_IsBorderSelect(plv)    (plv->exStyle & LVS_EX_BORDERSELECT)
#define ListView_IsWatermarked(plv)     ((plv)->fListviewEnableWatermark && (plv)->hbmpWatermark)
#define ListView_IsWatermarkedBackground(plv)     ((plv)->fListviewWatermarkBackgroundImages && (plv)->pImgCtx && (plv)->fImgCtxComplete)
#define ListView_IsSimpleSelect(plv)    (plv->exStyle & LVS_EX_SIMPLESELECT)
#define ListView_IsDPIScaled(plv)        TRUE
#define ListView_IsDPIScaled(plv)       (CCDPIScale((plv)->ci))
#define ListView_IsDoubleBuffer(plv)    (FALSE)
#define ListView_IsDoubleBuffer(plv)    (plv->exStyle & LVS_EX_DOUBLEBUFFER)
#define ListView_IsKbdTipTracking(plv)  (plv->iTracking != LVKTT_NOTRACK)
#define ListView_RedrawEnabled(plv) ((plv->flags & (LVF_REDRAW | LVF_VISIBLE)) == (LVF_REDRAW|LVF_VISIBLE))
#define ListView_ZOrderIndex(plv, i) DPA_GetPtrIndex((plv)->hdpaZOrder, IntToPtr(i))
#define ListView_CancelPendingEdit(plv) ListView_CancelPendingTimer(plv, LVF_NMEDITPEND, IDT_NAMEEDIT)
#define ListView_CancelScrollWait(plv) ListView_CancelPendingTimer(plv, LVF_SCROLLWAIT, IDT_SCROLLWAIT)
#define ListView_InvalidateItem(p,i,s,r) ListView_InvalidateItemEx(p,i,s,r,0)
#define ListView_GetItemPtr(plv, i)         ((LISTITEM*)DPA_GetPtr((plv)->hdpa, (i)))
#define ListView_FastGetItemPtr(plv, i)     ((LISTITEM*)DPA_GetPtr((plv)->hdpa, (i)))
#define ListView_FastGetZItemPtr(plv, i)    ((LISTITEM*)DPA_GetPtr((plv)->hdpa, \
                                                  (int)OFFSETOF(DPA_GetPtr((plv)->hdpaZOrder, (i)))))
#define ListView_FastGetItemPtr(plv, i)     ((LISTITEM*)DPA_FastGetPtr((plv)->hdpa, (i)))
#define ListView_FastGetZItemPtr(plv, i)    ((LISTITEM*)DPA_FastGetPtr((plv)->hdpa, \
                                                  (int)OFFSETOF(DPA_FastGetPtr((plv)->hdpaZOrder, (i)))))
#define ListView_GetScrollInfo(plv, flag, lpsi)                             \
    ((plv)->exStyle & LVS_EX_FLATSB ?                                       \
        FlatSB_GetScrollInfo((plv)->ci.hwnd, (flag), (lpsi)) :              \
        GetScrollInfo((plv)->ci.hwnd, (flag), (lpsi)))
#define ListView_SetScrollRange(plv, flag, min, max, fredraw)               \
    ((plv)->exStyle & LVS_EX_FLATSB ?                                       \
        FlatSB_SetScrollRange((plv)->ci.hwnd, (flag), (min), (max), (fredraw)) : \
        SetScrollRange((plv)->ci.hwnd, (flag), (min), (max), (fredraw)))
#define ListView_DrawImage(plv, pitem, hdc, x, y, fDraw) \
        ListView_DrawImageEx(plv, pitem, hdc, x, y, plv->clrBk, fDraw, -1)
#define ListView_GetSubItemDPA(plv, idpa) \
    ((HDPA)DPA_GetPtr((plv)->hdpaSubItems, (idpa)))
#define _ListView_DrawItem(plvdi) \
        pfnListView_DrawItem[LV_TYPEINDEX(plvdi->plv)](plvdi)
#define _ListView_UpdateScrollBars(plv) \
        pfnListView_UpdateScrollBars[LV_TYPEINDEX(plv)](plv)
#define _ListView_ApproximateViewRect(plv, iCount, iWidth, iHeight) \
        pfnListView_ApproximateViewRect[LV_TYPEINDEX(plv)](plv, iCount, iWidth, iHeight)
#define _ListView_ItemHitTest(plv, x, y, pflags, piSubItem) \
        pfnListView_ItemHitTest[LV_TYPEINDEX(plv)](plv, x, y, pflags, piSubItem)
#define _ListView_OnScroll(plv, x, y, pflags) \
        pfnListView_OnScroll[LV_TYPEINDEX(plv)](plv, x, y, pflags)
#define _ListView_RecomputeLabelSize(plv, pitem, i, hdc, fUsepitem) \
        pfnListView_RecomputeLabelSize[LV_TYPEINDEX(plv)](plv, pitem, i, hdc, fUsepitem)
#define _ListView_Scroll2(plv, x, y, pflags) \
        pfnListView_Scroll2[LV_TYPEINDEX(plv)](plv, x, y, pflags)
#define _ListView_GetScrollUnitsPerLine(plv, sb) \
        pfnListView_GetScrollUnitsPerLine[LV_TYPEINDEX(plv)](plv, sb)
#define _ListView_RecomputeEx(plv, hdpaSort, iFrom, fForce)\
        pfnListView_RecomputeEx[LV_TYPEINDEX(plv)](plv, hdpaSort, iFrom, fForce);
#define ListView_Recompute(plv) _ListView_RecomputeEx(plv, NULL, 0, FALSE)

// shell\comctl32\v6\monthcal.c
#define MCMP_WINDOWPOSCHANGED (MCM_FIRST - 1) // MCM_FIRST is way over WM_USER
#define DTMP_WINDOWPOSCHANGED (DTM_FIRST - 1) // DTM_FIRST is way over WM_USER

// shell\comctl32\v6\monthcal.h
#define SE_YEARLIKE(s)      ((s) == SE_YEAR || (s) == SE_YEARALT)
#define MonthCal_IsMultiSelect(pmc)     ((pmc)->ci.style & MCS_MULTISELECT)
#define MonthCal_ShowWeekNumbers(pmc)   ((pmc)->ci.style & MCS_WEEKNUMBERS)
#define MonthCal_ShowTodayCircle(pmc)   (!((pmc)->ci.style & MCS_NOTODAYCIRCLE))
#define MonthCal_ShowToday(pmc)         (!((pmc)->ci.style & MCS_NOTODAY))
#define DatePick_AppCanParse(pdp)   ((pdp)->ci.style & DTS_APPCANPARSE)

// shell\comctl32\v6\prshti.h
#define PSH_WIZARD97        (PSH_WIZARD97IE4 | PSH_WIZARD97IE5)
#define GETPPSP(ppd, i) (&GETPISP(ppd, i)->_psp)

// shell\comctl32\v6\scroll.cpp
#define WSB_VERT (WSB_VERT_UP | WSB_VERT_DN)
#define WSB_HORZ   (WSB_HORZ_LF | WSB_HORZ_RT)
    #define REEVALUATE_PSBTRACK(pSBTrack, hwnd, str)          \
        if ((pSBTrack) != CUxScrollBar::GetSBTrack(hwnd)) {             \
            RIPMSG3(RIP_WARNING,                              \
                    "%s: pSBTrack changed from %#p to %#p",   \
                    (str), (pSBTrack), CUxScrollBar::GetSBTrack(hwnd)); \
        }                                                     \
        (pSBTrack) = CUxScrollBar::GetSBTrack(hwnd)
    #define REEVALUATE_PSBTRACK(pSBTrack, hwnd, str)          \
        (pSBTrack) = CUxScrollBar::GetSBTrack(hwnd)

// shell\comctl32\v6\tab.h
#define Tab_DrawButtons(ptc)            ((BOOL)(ptc->ci.style & TCS_BUTTONS))
#define Tab_MultiLine(ptc)              ((BOOL)(ptc->ci.style & TCS_MULTILINE))
#define Tab_RaggedRight(ptc)            ((BOOL)(ptc->ci.style & TCS_RAGGEDRIGHT))
#define Tab_FixedWidth(ptc)             ((BOOL)(ptc->ci.style & TCS_FIXEDWIDTH))
#define Tab_Vertical(ptc)               ((BOOL)(ptc->ci.style & TCS_VERTICAL))
#define Tab_Bottom(ptc)                 ((BOOL)(ptc->ci.style & TCS_BOTTOM))
#define Tab_ForceLabelLeft(ptc)         ((BOOL)(ptc->ci.style & TCS_FORCELABELLEFT))
#define Tab_ForceIconLeft(ptc)          ((BOOL)(ptc->ci.style & TCS_FORCEICONLEFT))
#define Tab_FocusOnButtonDown(ptc)      ((BOOL)(ptc->ci.style & TCS_FOCUSONBUTTONDOWN))
#define Tab_OwnerDraw(ptc)              ((BOOL)(ptc->ci.style & TCS_OWNERDRAWFIXED))
#define Tab_FocusNever(ptc)             ((BOOL)(ptc->ci.style & TCS_FOCUSNEVER))
#define Tab_HotTrack(ptc)             ((BOOL)(ptc->ci.style & TCS_HOTTRACK))
#define Tab_MultiSelect(ptc)            ((BOOL)(ptc->ci.style & TCS_MULTISELECT))
#define Tab_FlatButtons(ptc)            ((BOOL)((ptc)->ci.style & TCS_FLATBUTTONS))
#define Tab_FlatSeparators(ptc)         ((BOOL)((ptc)->dwStyleEx & TCS_EX_FLATSEPARATORS))

// shell\comctl32\v6\tbcust.c
#define SEND_WM_COMMAND(hwnd, id, hwndCtl, codeNotify) \
    (void)SendMessage((hwnd), WM_COMMAND, MAKEWPARAM((UINT)(id),(UINT)(codeNotify)), (LPARAM)(HWND)(hwndCtl))

// shell\comctl32\v6\tooltips.cpp
#define TTToolHwnd(pTool)  ((pTool->uFlags & TTF_IDISHWND) ? (HWND)pTool->uId : pTool->hwnd)
#define IsToolbarWindow(hwnd) \
    (SendMessage(hwnd, WM_GETOBJECT, 0, OBJID_QUERYCLASSNAMEIDX) == MSAA_CLASSNAMEIDX_TOOLBAR)
#define HittestInTool(pTool, hwnd, ht) \
    ((pTool->uFlags & TTF_USEHITTEST) && pTool->hwnd == hwnd && ht == pTool->rect.left)

// shell\comctl32\v6\trackbar.c
#define ISVERT(tb) (tb->ci.style & TBS_VERT)

// shell\comctl32\v6\treeview.c
#define REPEATTIME      SendMessage(pTree->hwndToolTips,TTM_GETDELAYTIME,(WPARAM)TTDT_RESHOW, 0)

// shell\comctl32\v6\usrctl32.h
#define SetWindowState(hwnd, flags)   \
            SetWindowLong(hwnd, GWL_STYLE, GetWindowStyle(hwnd) | (flags))
#define ClearWindowState(hwnd, flags)   \
            SetWindowLong(hwnd, GWL_STYLE, GetWindowStyle(hwnd) & ~(flags))
#define WFPIXIEHACK             0x0680  // Send (HRGN)1 to WM_NCPAINT (see PixieHack)

// shell\comdlg32\filenew.cpp
#define IsVisible(_hwnd)     (GetWindowLong(_hwnd, GWL_STYLE) & WS_VISIBLE)

// shell\cpls\appwzdui\appwiz.c
       #define lpwd (&wd)

// shell\cpls\appwzdui\instapp.cpp
#define APPACTION_STANDARD  (APPACTION_UNINSTALL | APPACTION_MODIFY | APPACTION_REPAIR)

// shell\cpls\appwzdui\instapp.h
#define CIA_LM_NATIVE       (CIA_LM | CIA_NATIVE)
#define CIA_CU_NATIVE       (CIA_CU | CIA_NATIVE)
#define CIA_LM_ALT          (CIA_LM | CIA_ALT)
#define CIA_CU_ALT          (CIA_CU | CIA_ALT)

// shell\cpls\appwzdui\util.cpp
#define PVAREMPTY ((VARIANT*)&c_vaEmpty)

// shell\cpls\appwzdui\worker.h
#define WORKERWIN_FIRE_ROW_READY          (WM_USER + 0x0101)  // wParam is row #
#define WORKERWIN_FIRE_FINISHED           (WM_USER + 0X0102)
#define WORKERWIN_FIRE_DATASETCHANGED     (WM_USER + 0X0103)

// shell\cpls\common\deskcmmn.h
#define DCDSF_PROBABLY      (DCDSF_ASK  | DCDSF_DYNA)
#define DCDSF_PROBABLY_NOT  (DCDSF_ASK  |          0)
#define DCDSF_YES           (0          | DCDSF_DYNA)
#define DCDSF_NO            (0          |          0)

// shell\cpls\inetcpl\inetcplp.h
#define INM_UPDATE              (WM_USER + 100)
#define ENABLEAPPLY(hDlg) SendMessage( GetParent(hDlg), PSM_CHANGED, (WPARAM)hDlg, 0L )

// shell\cpls\inetcpl\proxysup.cpp
#define isdigit(ch) (ch >= '0' && ch <= '9')

// shell\cpls\inetcpl\shassoc.cpp
#define REMOVE_DEF_BORDER(hDlg, cntrl )  \
    SendMessage( hDlg,  DM_SETDEFID, -1, 0 ); \
    SendDlgItemMessage( hDlg, cntrl, BM_SETSTYLE, BS_PUSHBUTTON, TRUE );  \
#define SET_DEF_BORDER(hDlg, cntrl )  \
    SendMessage( hDlg, DM_SETDEFID, cntrl, 0 );   \
    SendDlgItemMessage( hDlg, cntrl, BM_SETSTYLE, BS_DEFPUSHBUTTON, TRUE );  \

// shell\cpls\main\applet.h
#define APPLET_REBOOT             (APPLET_RESTART | 0x4)

// shell\cpls\nusrmgr\toolbar.h
#define PWM_UPDATESIZE          (WM_APP + 143)

// shell\cpls\system\general.cpp
#define SYSCPL_ASYNC_COMPUTER_INFO (WM_APP + 1)

// shell\cpls\system\perf.h
#define RET_VIRT_AND_RECOVER (RET_VIRTUAL_CHANGE | RET_RECOVER_CHANGE)

// shell\cpls\utc\clock.h
#define CLM_TIMEHWND         (WM_USER + 103)

// shell\evtmon\inc\emact.h
#define PObjectPact(pact) \
            ((pact)->rec1_ca.ca.pObject)
#define CpFirstPact(pact) \
            ((pact)->rec1_ca.ca.cpFirst)
#define CpLimPact(pact) \
            ((pact)->rec1_ca.ca.cpLim)
#define MsoActfActt(actt, pacttbl) \
            (MsoPActtrec((actt), (pacttbl))->actf)
#define MsoPActtrec(actt, pacttbl) \
            (&(pacttbl)->rgacttrec[actt])
#define MsoPendingActions(pacttbl) \
            ((pacttbl)->pactPending)
#define MsoLPact(pact, iarg) \
            ((pact)->rec1.rgl[iarg])
#define MsoReversePactPending(pacttbl) \
            MsoReversePact(&pacttbl->pactPending)       // Reverse pending acts

// shell\evtmon\inc\emkwd.h
#define MsoPpkwdGetHashAddr(pkwtb, ikwd) \
            (&(MsoRgpkwdHashFromKwtb(pkwtb)[ikwd]))
#define MsoPpkwdlhGetHashAddr(pkwtb, ikwd) \
            (&(MsoRgpkwdlhFromKwtb(pkwtb)[ikwd]))

// shell\evtmon\inc\emoci.h
#define MsoOcvEventAddr(iocv, pocis) \
            ((*(pocis)->pfnPocvGetVar)(iocv))
#define MsoOcvStackAddr(docv, pocis) \
            (&(pocis)->pocvFP[docv])
#define OcadArgDecripOcii(ocii, pocis) \
            ((pocis)->rgocadArgDesc[ocii])

// shell\evtmon\inc\emrule.h
#define DiscardIrul(irul) \
            (vlpruls->irulLim--)
#define IrulFromLprul(prul)  \
            ((prul)->irul)
#define FPrimaryRule(prul)      ((prul)->rultType & rultPrimaryRule)
#define FIsEventPrul(prul)          ((prul)->rultType & rultEvent)
#define FImmediateRulePrul(prul)    ((prul)->rultType & rultImmediateRule)
#define FSpecialKwdLprul(prul)      ((prul)->rultType & rultSpecialKwd)
#define SetFSpecialKwdLprul(prul)  \
            ((prul)->rultType |= rultSpecialKwd)
#define FPersistentLprul(prul) \
            ((prul)->rultType & rultPersistentRule)
#define SetFPersistentLprul(prul) \
            ((prul)->rultType |= rultPersistentRule)
#define FAlwaysPersistLprul(prul) \
            ((prul)->rultType & rultAlwaysPersist)
#define SetFAlwaysPersistLprul(prul) \
            ((prul)->rultType |= rultAlwaysPersist)
#define FPersistLprulGrf(prul, grf) \
            ((prul)->rultType & (grf))
#define RulvOfIrul(irul) \
            (LprulFromIrul(irul)->svl.lValue)
#define SetRulvOfIrul(irul, rulv) \
            (LprulFromIrul(irul)->svl.lValue = (rulv))
#define PlValueOfIrul(irul) \
            (&LprulFromIrul(irul)->svl.lValue)
#define PsvOfLprul(prul)                (&(prul)->svl.sv)
#define Rulv1(rulv)                     W1OfPsv((SV *) &(rulv))
#define SetRulv1(rulv, w)               SetW1OfPsv(((SV *) &(rulv)), (w))
#define Rulv2(rulv)                     W2OfPsv((SV *) &(rulv))
#define SetRulv2(rulv, w)               SetW2OfPsv(((SV *) &(rulv)), (w))
#define RulevtOfRulevl(rulevl) \
            (vlpruls->rgrulevtFromRulevl[rulevl])
#define LpruldepFromIrul(irul) \
            (vlpruls->rgpruldepDependents[irul])
#define SetLpruldepFromIrul(irul, pruldep) \
            (vlpruls->rgpruldepDependents[irul] = (pruldep))
#define LplpruldepForRulgIrul(rulg, irul) \
            (&(vlpruls->rgrgpruldepDependents[rulg][irul]))
#define RulgAppendedFrom(rulg) \
            (vlpruls->prulgAppendedFrom[rulg])
#define PrulgAppendedFrom() \
            (vlpruls->prulgAppendedFrom)
#define RulgAppendTo(rulg) \
            (vlpruls->prulgAppendTo[rulg])
#define PrulgAppendTo() \
            (vlpruls->prulgAppendTo)
#define LpirulGetDependsOn(prul) \
            (&vlpruls->lpgrpirulDependBack[(prul)->birulDependsOn])
#define FEvalRule(irul) \
            (*vlpruls->lpfnEvalRule)(irul)
#define FDeferIrul(irul) \
            (vlpruls->fEvaluatingDeferred ||  _MsoFDeferIrul(irul))
#define FDeferIrulExpr(irul, lExpr) \
            (vlpruls->fEvaluatingDeferred \
                ||  (((int) lExpr)  &&  _MsoFDeferIrul(irul)))
#define FDeferIrulExprL(irul, lExpr, lValue) \
            (vlpruls->fEvaluatingDeferred \
                ||  (((int) lExpr)  &&  _MsoFDeferIrulL((irul), (lValue))))
#define CIntervalsRulevt(rulevt) \
            (vlpruls->rgdtkiRulevt[rulevt])
#define IncrIntervalsRsct(rulevt, dc) \
            (vlpruls->rgdtkiRulevt[rulevt] += (dc))
#define CDelaySignalRulv(rulvVar, lValue, cDelay) \
            MsoDelayScheduleIrul(LprulFromRulv(rulvVar)->irul, (lValue), \
                                 (cDelay))
#define FAutoDeactivateIrul(irul, fTest) \
            ((fTest) ? FALSE : (_MsoFDeactivateIrul(irul), TRUE))
#define SetCurrRulg(rulgGroup) \
            (vlpruls->rgpruldepDependents \
                = vlpruls->rgrgpruldepDependents[vlpruls->rulgCurr \
                                                        = rulgGroup])
#define FCurrRulg(rulg) \
            (vlpruls->rulgCurr == (rulg))

// shell\evtmon\inc\emrultk.h
#define PrultkFromIrultk(irultk, prultk) \
            (&prultk[irultk])

// shell\evtmon\inc\emutil.h
#define MsoCpFirstOfDtk(dtk, ptkh) \
        (MsoPrultkFromDtk(dtk, ptkh)->cpFirst)

// shell\evtmon\inc\mso.h
#define MSOAPIX_(t)             t MSOAPICALLTYPE

// shell\evtmon\inc\msolex.h
#define PobjectLexToken(plexs) \
            ((plexs)->pObject)
#define CpLexTokenFirst(plexs) \
            ((plexs)->cpTokenFirst)
#define SetCpLexTokenFirst(plexs, cp) \
            ((plexs)->cpTokenFirst = (cp))
#define DcpLexToken(plexs) \
            ((plexs)->dcpToken)
#define SetDcpLexToken(plexs, dcp) \
            ((plexs)->dcpToken = (dcp))
#define IncrDcpLexToken(plexs, dcp) \
            ((plexs)->dcpToken += (dcp))
#define ClearDcpLexToken(plexs) \
            (SetDcpLexToken(plexs, 0L), \
             plexs->cpFirstVanished = 0L, \
             plexs->dcpVanished = 0L)
#define CchTokenLen(plexs) \
            (CchTokenUncachedLen(plexs) + (plexs)->ichCache)
#define InvalLexFetch(plexs) \
            ((plexs)->cchRemain = 0, \
             (plexs)->fInvalLexer = fTrue)
#define FInvalLexFetch(plexs) \
            ((plexs)->fInvalLexer)
#define PrultkFromTokenIrultk(plexs, irultk) \
            PrultkFromIrultk(irultk, (plexs)->rultkhToken.rgrultkCache)
#define IncrTokenPirultk(plexs, pirultk, dirultk) \
            IncrPirultk(pirultk, dirultk, (plexs)->rultkhToken.irultkMac)
#define DecrTokenPirultk(plexs, pirultk, dirultk) \
            DecrPirultk(pirultk, dirultk, (plexs)->rultkhToken.irultkMac)
#define PrultkFormatFromIrultk(plexs, irultk) \
            PrultkFromIrultk(irultk, (plexs)->rultkhFormat.rgrultkCache)
#define IncrFormatPirultk(pirultk, dirultk) \
            IncrPirultk(pirultk, dirultk, (plexs)->rultkhFormat.irultkMac)
#define DecrFormatPirultk(pirultk, dirultk) \
            DecrPirultk(pirultk, dirultk, (plexs)->rultkhFormat.irultkMac)

// shell\explorer\desktop2\deskhost.h
#define DesktopHost_Dismiss(hwnd)   SendMessage(hwnd, DHM_DISMISS, 0, 0)

// shell\ext\audiodevice\wmfldr.cpp
#define IsEqualSCID(a, b)   (((a).pid == (b).pid) && IsEqualIID((a).fmtid, (b).fmtid) )

// shell\ext\brfcase\filesync\core\stub.c
#define GetStubTypeDescriptor(pcs)     (&(Mrgcstd[pcs->st]))

// shell\ext\brfcase\filesync\syncui\brfprv.h
#define MB_WARNING  (MB_OK | MB_ICONWARNING)
#define MB_INFO     (MB_OK | MB_ICONINFORMATION)
#define MB_ERROR    (MB_OK | MB_ICONERROR)
#define MB_QUESTION (MB_YESNO | MB_ICONQUESTION)

// shell\ext\brfcase\filesync\syncui\cache.h
#define CRL_Init()                      Cache_Init(&g_cacheCRL)
#define CRL_InitCS()                    Cache_InitCS(&g_cacheCRL)
#define CPATH_Init()                    Cache_Init(&g_cacheCPATH)
#define CPATH_InitCS()                  Cache_InitCS(&g_cacheCPATH)

// shell\ext\brfcase\filesync\syncui\comm.h
#define SetDlgHandle(hwnd, msg, lp)     if((msg)==WM_SETFONT) (lp)->hdlg=(hwnd);

// shell\ext\brfcase\filesync\syncui\da.c
#define IsDSA(pdsa) ((pdsa) && (pdsa)->magic == DSA_MAGIC)
#define IsDPA(pdpa) ((pdpa) && (pdpa)->magic == DPA_MAGIC)
#define SortCompare(psp, pp1, i1, pp2, i2) \
        (psp->pfnCmp(pp1[i1], pp2[i2], psp->lParam))

// shell\ext\brfcase\filesync\syncui\err.h
#define GET_TR(hr)              ((TWINRESULT)((hr) & 0x0000FFFF) - TR_DELTAVALUE)

// shell\ext\brfcase\filesync\syncui\recact.h
#define RAM_FIRST       (WM_USER+1)
#define RAM_LAST        (WM_USER+20)
#define RecAct_GetItemCount(hwnd) \
                (int)SendMessage(hwnd, RAM_GETITEMCOUNT, 0, 0L)
#define RecAct_InsertItem(hwnd, pitem) \
                (int)SendMessage((hwnd), RAM_INSERTITEM, 0, (LPARAM)(const LPRA_ITEM)(pitem))
#define RecAct_GetItem(hwnd, pitem) \
                (BOOL)SendMessage((hwnd), RAM_GETITEM, 0, (LPARAM)(LPRA_ITEM)(pitem))
#define RecAct_SetItem(hwnd, pitem) \
                (BOOL)SendMessage((hwnd), RAM_SETITEM, 0, (LPARAM)(const LPRA_ITEM)(pitem))
#define RecAct_GetCurSel(hwnd) \
                (int)SendMessage((hwnd), RAM_GETCURSEL, (WPARAM)0, 0L)
#define RecAct_SetCurSel(hwnd, i) \
                (int)SendMessage((hwnd), RAM_SETCURSEL, (WPARAM)(i), 0L)
#define RecAct_FindItem(hwnd, iStart, prafi) \
                (int)SendMessage((hwnd), RAM_FINDITEM, (WPARAM)(int)(iStart), (LPARAM)(const RA_FINDINFO *)(prafi))
#define RecAct_Refresh(hwnd) \
                SendMessage((hwnd), RAM_REFRESH, 0, 0L)

// shell\ext\cabview\da.c
#define IsDPA(pdpa) ((pdpa) && (pdpa)->magic == DPA_MAGIC)
#define SortCompare(psp, pp1, i1, pp2, i2) \
	(psp->pfnCmp(pp1[i1], pp2[i2], psp->lParam))

// shell\ext\cabview\folder.h
#define IsEqualSCID(a, b)   (((a).pid == (b).pid) && IsEqualIID((a).fmtid, (b).fmtid) )

// shell\ext\cscui\cscst.h
#define PWM_TRAYCALLBACK          (WM_USER + 402)
#define PWM_REFRESH_SHELL         (WM_USER + 406)
#define PWM_HANDLE_POLICY_CHANGE  (WM_USER + 409)

// shell\ext\cscui\cscuiext.h
#define STWM_CSCNETUP                   (WM_USER + 209)
#define STWM_CSCQUERYNETDOWN            (WM_USER + 210)
#define STWM_CSCNETDOWN                 (WM_USER + 213)
#define STWM_CACHE_CORRUPTED            (WM_USER + 214)
#define CSCWM_DONESYNCING               (WM_USER + 300)
#define CSCWM_RECONNECT                 (WM_USER + 302)
#define CSCWM_SYNCHRONIZE               (WM_USER + 303)
#define CSCWM_ISSERVERBACK              (WM_USER + 304)
#define CSCWM_VIEWFILES                 (WM_USER + 305)
#define CSCWM_SETTINGS                  (WM_USER + 306)

// shell\ext\cscui\update.cpp
#define RDC_RESTORE_ALL (RDC_APPLY_ALL | RDC_RESTORE)
#define PINEFS_NO_TOALL   (PINEFS_NO | PINEFS_APPLYTOALL)
#define PINEFS_YES_TOALL  (PINEFS_YES | PINEFS_APPLYTOALL)

// shell\ext\docprop\offcapi.h
#define PRT_FRAME_SHOW          (PRT_FRAME_LEFT|PRT_FRAME_TOP|PRT_FRAME_RIGHT|PRT_FRAME_BOTTOM)
#define facACStaticACX                  (facACX|facACStatic)

// shell\ext\docpropv3\simpledlg.cpp
#define SUMMARYPROP(s)      { &FMTID_SummaryInformation,    PIDSI_##s,  IDC_##s }
#define DOCSUMMARYPROP(s)   { &FMTID_DocSummaryInformation, PIDDSI_##s, IDC_##s }

// shell\ext\dsui\dsquery\frame.cpp
#define REAL_WINDOW(hwnd)                   \
        (hwnd &&                            \
            IsWindowVisible(hwnd) &&        \
                IsWindowEnabled(hwnd) &&    \
                    (GetWindowLong(hwnd, GWL_STYLE) & WS_TABSTOP))

// shell\ext\dsui\dsquery\qf_pwell.cpp
#define CONDITION_FROM_COMBO(hwnd)    \
            (int)ComboBox_GetItemData(hwnd, ComboBox_GetCurSel(hwnd))

// shell\ext\dsui\dsquery\query.cpp
#define ENABLE_MENU_ITEM(hMenu, id, fEnabled) \
                EnableMenuItem(hMenu, id, (fEnabled) ? (MF_BYCOMMAND|MF_ENABLED):(MF_BYCOMMAND|MF_GRAYED))
#define SET_BTN_STYLE(hwnd, idc, style) \
            SendDlgItemMessage(hwnd, idc, BM_SETSTYLE, MAKEWPARAM(style, 0), MAKELPARAM(TRUE, 0));

// shell\ext\dsui\dsquery\query.h
#define RVTM_FIRST                  (WM_USER)
#define RVTM_LAST                   (WM_USER+32)
#define RVTM_STOPQUERY              (WM_USER)           // wParam = 0, lParam =0
#define RVTM_REFRESH                (WM_USER+1)         // wParam = 0, lParam = 0

// shell\ext\dsui\dsquery\thread.cpp
#define SEND_VIEW_MESSAGE(ptid, uMsg, lParam) \
        SendMessage(GetParent(ptid->hwndView), uMsg, (ptid)->dwReference, lParam)

// shell\ext\ftp\ftppidl.h
#define FtpPidl_IsDirSoftLink(pidl)        (FILEATTRIB_DIRSOFTLINK == (FILEATTRIB_DIRSOFTLINK & FtpPidl_GetAttributes(pidl)))

// shell\ext\ftp\priv.h
#define ISVISIBLE(hwnd)  ((GetWindowStyle(hwnd) & WS_VISIBLE) == WS_VISIBLE)

// shell\ext\ftp\util.cpp
#define PVAREMPTY ((VARIANT*)&c_vaEmpty)

// shell\ext\hnw\nconn32\mycfgmgr.cpp
#define CONFIGMG_DEVICE_ID              0x00033 /* Configuration manager (Plug&Play) */

// shell\ext\hnw\win95\setupx.h
#define DriveAtoI( chDrv )      ((int)(chDrv & 31))
#define VCPFL_BACKUPANDCOPY     (VCPFL_BACKUP | VCPFL_COPY)
#define FLG_ADDREG_TYPE_BINARY          ( 0x00000000 | FLG_ADDREG_BINVALUETYPE )
#define GENINSTALL_DO_INIREG    (GENINSTALL_DO_INI | \
								 GENINSTALL_DO_REG | \
								 GENINSTALL_DO_INI2REG)

// shell\ext\hnw\win95\setupx1.h
#define DriveAtoI( chDrv )      ((int)(chDrv & 31))
#define VCPFL_BACKUPANDCOPY     (VCPFL_BACKUP | VCPFL_COPY)
#define	GENINSTALL_DO_INIREG	(GENINSTALL_DO_INI | GENINSTALL_DO_REG)

// shell\ext\hnw\win95\setupx2.h
#define DriveAtoI( chDrv )      ((int)(chDrv & 31))
#define VCPFL_BACKUPANDCOPY     (VCPFL_BACKUP | VCPFL_COPY)
#define GENINSTALL_DO_INIREG    (GENINSTALL_DO_INI | \
                                 GENINSTALL_DO_REG | \
                                 GENINSTALL_DO_INI2REG)

// shell\ext\hnw\win95\setupx3.h
#define DriveAtoI( chDrv )      ((int)(chDrv & 31))
#define VCPFL_BACKUPANDCOPY     (VCPFL_BACKUP | VCPFL_COPY)
#define GENINSTALL_DO_INIREG    (GENINSTALL_DO_INI | \
                                 GENINSTALL_DO_REG | \
                                 GENINSTALL_DO_INI2REG)

// shell\ext\hnw\win95\setupx4.h
#define DriveAtoI( chDrv )      ((int)(chDrv & 31))
#define VCPFL_BACKUPANDCOPY     (VCPFL_BACKUP | VCPFL_COPY)
#define GENINSTALL_DO_INIREG    (GENINSTALL_DO_INI | \
                                 GENINSTALL_DO_REG | \
                                 GENINSTALL_DO_INI2REG)

// shell\ext\hnw\wizard\sharing.h
#define NETACCESS_DEPENDSON       (NETACCESS_READONLY | NETACCESS_FULL)

// shell\ext\inetfind\fnd.h
#define PUN(T, v) OBJAT(T, &(v))	/* General-purpose type-punning */
#define fLimpFF(f1, f2) (!(f1) || (f2))
#define Primary_Vtbl(C) &c_##C##VI.vtbl
#define Common_AddRef(punk) \
		((IUnknown *)(punk))->lpVtbl->AddRef((IUnknown *)(punk))
#define Common_Release(punk) \
		((IUnknown *)(punk))->lpVtbl->Release((IUnknown *)(punk))

// shell\ext\media\mediaprop.h
#define IsEqualSCID(a, b)   (((a).pid == (b).pid) && IsEqualIID((a).fmtid, (b).fmtid) )

// shell\ext\mlang\cpdetect.h
#define IsNoise(c) ((unsigned)(c) <= 0x20 && (c) != 0 && (c) != 0x1B)

// shell\ext\mlang\jislex.cpp
#define ASC		(TST) (grfFinal | 0x00)		// Ascii
#define JS0		(TST) (grfFinal | 0x01)		// JIS-Roman
#define JS1		(TST) (grfFinal | 0x02)		// Half-Width Katakana
#define JS2 	(TST) (grfFinal | 0x03)		// JIS C 6226-1978
#define JS3		(TST) (grfFinal | 0x04)		// JIS X 0208-1983
#define JS4		(TST) (grfFinal | 0x05)		// JIS X 0208-1990
#define JS5		(TST) (grfFinal | 0x06)		// JIS X 0212-1990
#define CS0		(TST) (grfFinal | 0x07)		// GB 1988-89 Roman
#define CS1		(TST) (grfFinal | 0x08)		// GB 2312-80
#define TS0		(TST) (grfFinal | 0x09)		// CNS 11643-1992 Plane 1
#define TS1		(TST) (grfFinal | 0x0a)		// CNS 11643-1992 Plane 2
#define TS2		(TST) (grfFinal | 0x0b)		// CNS 11643-1992 Plane 3
#define TS3		(TST) (grfFinal | 0x0c)		// CNS 11643-1992 Plane 4
#define TS4		(TST) (grfFinal | 0x0d)		// CNS 11643-1992 Plane 5
#define TS5		(TST) (grfFinal | 0x0e)		// CNS 11643-1992 Plane 6
#define TS6		(TST) (grfFinal | 0x0f)		// CNS 11643-1992 Plane 7
#define KS0		(TST) (grfFinal | 0x10)		// KS C 5601-1992
#define KSD		(TST) (grfFinal | 0x11)		// ISO-2022-KR Document Signal
#define FIN		(TST) (grfFinal | (cCsEsc + 3))		// Finish
#define EOI		(TST) (grfFinal | (cCsEsc + 4))		// Unexpected End-Of-Input
#define ERR		(TST) (grfFinal | (cCsEsc + 6))		// Read Error

// shell\ext\neptune\aidanl\davtrans\common\inc\xmlhlpr.h
#define CANSKIP(a) ((L'\t' == (a)) || (L' ' == (a)) || (L'\n' == (a)) || (L'\r' == (a)))

// shell\ext\nsc\common.h
#define Release(punk)			(punk)->lpVtbl->Release(punk)

// shell\ext\nsc\nsc.h
#define NSM_SETROOT	(WM_USER + 1)
#define NameSpace_SetRoot(hwnd, psr) \
    (BOOL)SendMessage(hwnd, NSM_SETROOT, (WPARAM)0, (LPARAM)psr)
#define NameSpace_GetIDList(hwnd, hitem) \
    (LPITEMIDLIST)SendMessage(hwnd, NSM_GETPIDL, 0, (WPARAM)hitem)
#define NameSpace_GetFullIDList(hwnd, hitem) \
    (LPITEMIDLIST)SendMessage(hwnd, NSM_GETPIDL, 1, (WPARAM)hitem)
#define NameSpace_GetItemInfo(hwnd, hitem, pinfo) \
    (BOOL)SendMessage(hwnd, NSM_GETITEMINFO, (WPARAM)hitem, (LPARAM)pinfo)
#define NSM_FINDITEM	(WM_USER + 4)
#define NameSpace_FindItem(hwnd, pidl, pinfo) \
    (HNAMESPACEITEM)SendMessage(hwnd, NSM_FINDITEM, (WPARAM)pidl, (LPARAM)pinfo)
#define NSM_DOVERB      (WM_USER + 5)
#define NameSpace_DoVerb(hwnd, hitem, pszVerb) \
    (HNAMESPACEITEM)SendMessage(hwnd, NSM_DOVERB, (WPARAM)hitem, (LPARAM)pszVerb)

// shell\ext\ratings\sample\sample.rc
#define VER_PRODUCTVERSION_DW       (0x01000000 | 0001)

// shell\ext\shfolder\folder.c
#define FILE_MODIFY         (FILE_ALL_ACCESS & ~(WRITE_DAC | WRITE_OWNER))

// shell\ext\shtl\shtl.h
#define DECLARE_WM_HANDLER( handler ) LRESULT handler( UINT, WPARAM, LPARAM, BOOL& )
#define DECLARE_NM_HANDLER( handler ) LRESULT handler( int, LPNMHDR, BOOL& );

// shell\ext\sshow\sshow.cpp
#define UWM_FINDFILE               (WM_USER+1301)

// shell\ext\url\contmenu.cpp
#define ISQUOTE(ch) ((ch) == '\"' || (ch) == '\'')

// shell\ext\webcheck\schedui.h
#define UpDown_GetRange(hwndCtl)                    ((DWORD)SendMessage((hwndCtl), UDM_GETRANGE, 0, 0))
#define UpDown_GetBuddy(hwndCtl)                    ((HWND)SendMessage((hwndCtl), UDM_GETBUDDY, 0, 0))
#define UpDown_SetBuddy(hwndCtl, hwndBuddy)         ((HWND)SendMessage((hwndCtl), UDM_SETBUDDY, (WPARAM)(hwndBuddy), 0))
#define UpDown_SetAccel(hwndCtl, nAccels, aAccels)  ((BOOL)SendMessage((hwndCtl), UDM_SETACCEL, nAccels, (LPARAM)(aAccels)))

// shell\iecontrols\inc\autoobj.h
#define PPTYPEINFOOFOBJECT(index)      &((((AUTOMATIONOBJECTINFO *)(g_ObjectInfo[(index)]).pInfo)->pTypeInfo))
#define DECLARE_STANDARD_SUPPORTERRORINFO() \
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) { \
        return CAutomationObject::InterfaceSupportsErrorInfo(riid); \
    } \

// shell\iecontrols\inc\ipserver.h
#define DO_GUIDS_MATCH(riid1, riid2) ((riid1.Data1 == riid2.Data1) && (riid1 == riid2))
#define QI_INHERITS(pObj, itf)              \
    case Data1_##itf:                       \
      if(DO_GUIDS_MATCH(riid, IID_##itf))    \
      {                                     \
        *ppvObjOut = (void *)(itf *)pObj;   \
      }                                     \
      break;

// shell\iecontrols\inc\prsht.h
#define PSM_SETCURSEL           (WM_USER + 101)
#define PSM_CHANGED             (WM_USER + 104)
#define PSM_RESTARTWINDOWS      (WM_USER + 105)
#define PSM_REBOOTSYSTEM        (WM_USER + 106)
#define PSM_QUERYSIBLINGS       (WM_USER + 108)
#define PSM_UNCHANGED           (WM_USER + 109)
#define PSM_APPLY               (WM_USER + 110)
#define PSM_SETTITLEA           (WM_USER + 111)
#define PSM_SETTITLEW           (WM_USER + 120)
#define PSM_SETWIZBUTTONS       (WM_USER + 112)
#define PSM_PRESSBUTTON         (WM_USER + 113)
#define PSM_SETCURSELID         (WM_USER + 114)
#define PSM_GETTABCONTROL       (WM_USER + 116)
#define PSM_GETCURRENTPAGEHWND  (WM_USER + 118)
#define ID_PSREBOOTSYSTEM       (ID_PSRESTARTWINDOWS | 0x1)

// shell\iecontrols\licmgr\core\include\core.hxx
#define NO_COPY(x)      x(const x& srp);    \
	                    x& operator=(const x& srp);

// shell\iecontrols\licmgr\core\include\dll.hxx
#define FACTORY(clsid, pfnFactory, pfnLicense)  \
                { &clsid, pfnFactory, pfnLicense },

// shell\inc\ccstock.h
#define IS_WINDOW_RTL_MIRRORED(hwnd)    (g_bMirroredOS && Mirror_IsWindowMirroredRTL(hwnd))
#define GET_PROCESS_DEF_LAYOUT(pdwl)    (g_bMirroredOS && Mirror_GetProcessDefaultLayout(pdwl))

// shell\inc\desktopp.h
#define DTM_THREADEXIT              (WM_USER + 76)
#define DTM_SHELLSERVICEOBJECTS     (WM_USER + 79)
#define DTM_STARTWAIT               (WM_USER + 80)
#define DTM_ENDWAIT                 (WM_USER + 81)
#define DTM_RAISE                       (WM_USER + 83)
#define DTM_ADDREFPROXYDESKTOP      (WM_USER + 84)
#define DTM_CREATESAVEDWINDOWS      (WM_USER + 85)
#define DTM_ENUMBANDS               (WM_USER + 86)
#define DTM_UIACTIVATEIO            (WM_USER + 88)
#define DTM_ONFOCUSCHANGEIS         (WM_USER + 89)
#define DTM_UPDATENOW               (WM_USER + 93)
#define DTM_QUERYHKCRCHANGED        (WM_USER + 94)  // ask the desktop if HKCR has changed
#define DTM_MAKEHTMLCHANGES         (WM_USER + 95)  // Make changes to desktop html using dynamic HTML
#define DTM_REFRESHACTIVEDESKTOP    (WM_USER + 97)  // Refresh the active desktop.

// shell\inc\err.h
#define	ERR_MEM_CORRUPT			-26	// Error returned on MemFree()

// shell\inc\evtmon\emact.h
#define PObjectPact(pact) \
            ((pact)->rec1_ca.ca.pObject)
#define CpFirstPact(pact) \
            ((pact)->rec1_ca.ca.cpFirst)
#define CpLimPact(pact) \
            ((pact)->rec1_ca.ca.cpLim)
#define MsoActfActt(actt, pacttbl) \
            (MsoPActtrec((actt), (pacttbl))->actf)
#define MsoPActtrec(actt, pacttbl) \
            (&(pacttbl)->rgacttrec[actt])
#define MsoPendingActions(pacttbl) \
            ((pacttbl)->pactPending)
#define MsoLPact(pact, iarg) \
            ((pact)->rec1.rgl[iarg])
#define MsoReversePactPending(pacttbl) \
            MsoReversePact(&pacttbl->pactPending)       // Reverse pending acts

// shell\inc\evtmon\emkwd.h
#define MsoPpkwdGetHashAddr(pkwtb, ikwd) \
            (&(MsoRgpkwdHashFromKwtb(pkwtb)[ikwd]))
#define MsoPpkwdlhGetHashAddr(pkwtb, ikwd) \
            (&(MsoRgpkwdlhFromKwtb(pkwtb)[ikwd]))

// shell\inc\evtmon\emoci.h
#define MsoOcvEventAddr(iocv, pocis) \
            ((*(pocis)->pfnPocvGetVar)(iocv))
#define MsoOcvStackAddr(docv, pocis) \
            (&(pocis)->pocvFP[docv])
#define OcadArgDecripOcii(ocii, pocis) \
            ((pocis)->rgocadArgDesc[ocii])

// shell\inc\evtmon\emrule.h
#define DiscardIrul(irul) \
            (vlpruls->irulLim--)
#define IrulFromLprul(prul)  \
            ((prul)->irul)
#define FPrimaryRule(prul)      ((prul)->rultType & rultPrimaryRule)
#define FIsEventPrul(prul)          ((prul)->rultType & rultEvent)
#define FImmediateRulePrul(prul)    ((prul)->rultType & rultImmediateRule)
#define FSpecialKwdLprul(prul)      ((prul)->rultType & rultSpecialKwd)
#define SetFSpecialKwdLprul(prul)  \
            ((prul)->rultType |= rultSpecialKwd)
#define FPersistentLprul(prul) \
            ((prul)->rultType & rultPersistentRule)
#define SetFPersistentLprul(prul) \
            ((prul)->rultType |= rultPersistentRule)
#define FAlwaysPersistLprul(prul) \
            ((prul)->rultType & rultAlwaysPersist)
#define SetFAlwaysPersistLprul(prul) \
            ((prul)->rultType |= rultAlwaysPersist)
#define FPersistLprulGrf(prul, grf) \
            ((prul)->rultType & (grf))
#define RulvOfIrul(irul) \
            (LprulFromIrul(irul)->svl.lValue)
#define SetRulvOfIrul(irul, rulv) \
            (LprulFromIrul(irul)->svl.lValue = (rulv))
#define PlValueOfIrul(irul) \
            (&LprulFromIrul(irul)->svl.lValue)
#define PsvOfLprul(prul)                (&(prul)->svl.sv)
#define Rulv1(rulv)                     W1OfPsv((SV *) &(rulv))
#define SetRulv1(rulv, w)               SetW1OfPsv(((SV *) &(rulv)), (w))
#define Rulv2(rulv)                     W2OfPsv((SV *) &(rulv))
#define SetRulv2(rulv, w)               SetW2OfPsv(((SV *) &(rulv)), (w))
#define RulevtOfRulevl(rulevl) \
            (vlpruls->rgrulevtFromRulevl[rulevl])
#define LpruldepFromIrul(irul) \
            (vlpruls->rgpruldepDependents[irul])
#define SetLpruldepFromIrul(irul, pruldep) \
            (vlpruls->rgpruldepDependents[irul] = (pruldep))
#define LplpruldepForRulgIrul(rulg, irul) \
            (&(vlpruls->rgrgpruldepDependents[rulg][irul]))
#define RulgAppendedFrom(rulg) \
            (vlpruls->prulgAppendedFrom[rulg])
#define PrulgAppendedFrom() \
            (vlpruls->prulgAppendedFrom)
#define RulgAppendTo(rulg) \
            (vlpruls->prulgAppendTo[rulg])
#define PrulgAppendTo() \
            (vlpruls->prulgAppendTo)
#define LpirulGetDependsOn(prul) \
            (&vlpruls->lpgrpirulDependBack[(prul)->birulDependsOn])
#define FEvalRule(irul) \
            (*vlpruls->lpfnEvalRule)(irul)
#define FDeferIrul(irul) \
            (vlpruls->fEvaluatingDeferred ||  _MsoFDeferIrul(irul))
#define FDeferIrulExpr(irul, lExpr) \
            (vlpruls->fEvaluatingDeferred \
                ||  (((int) lExpr)  &&  _MsoFDeferIrul(irul)))
#define FDeferIrulExprL(irul, lExpr, lValue) \
            (vlpruls->fEvaluatingDeferred \
                ||  (((int) lExpr)  &&  _MsoFDeferIrulL((irul), (lValue))))
#define CIntervalsRulevt(rulevt) \
            (vlpruls->rgdtkiRulevt[rulevt])
#define IncrIntervalsRsct(rulevt, dc) \
            (vlpruls->rgdtkiRulevt[rulevt] += (dc))
#define CDelaySignalRulv(rulvVar, lValue, cDelay) \
            MsoDelayScheduleIrul(LprulFromRulv(rulvVar)->irul, (lValue), \
                                 (cDelay))
#define FAutoDeactivateIrul(irul, fTest) \
            ((fTest) ? FALSE : (_MsoFDeactivateIrul(irul), TRUE))
#define SetCurrRulg(rulgGroup) \
            (vlpruls->rgpruldepDependents \
                = vlpruls->rgrgpruldepDependents[vlpruls->rulgCurr \
                                                        = rulgGroup])
#define FCurrRulg(rulg) \
            (vlpruls->rulgCurr == (rulg))

// shell\inc\evtmon\emrultk.h
#define PrultkFromIrultk(irultk, prultk) \
            (&prultk[irultk])

// shell\inc\evtmon\emutil.h
#define MsoCpFirstOfDtk(dtk, ptkh) \
        (MsoPrultkFromDtk(dtk, ptkh)->cpFirst)

// shell\inc\evtmon\mso.h
#define MSOAPIX_(t)             t MSOAPICALLTYPE

// shell\inc\evtmon\msolex.h
#define PobjectLexToken(plexs) \
            ((plexs)->pObject)
#define CpLexTokenFirst(plexs) \
            ((plexs)->cpTokenFirst)
#define SetCpLexTokenFirst(plexs, cp) \
            ((plexs)->cpTokenFirst = (cp))
#define DcpLexToken(plexs) \
            ((plexs)->dcpToken)
#define SetDcpLexToken(plexs, dcp) \
            ((plexs)->dcpToken = (dcp))
#define IncrDcpLexToken(plexs, dcp) \
            ((plexs)->dcpToken += (dcp))
#define ClearDcpLexToken(plexs) \
            (SetDcpLexToken(plexs, 0L), \
             plexs->cpFirstVanished = 0L, \
             plexs->dcpVanished = 0L)
#define CchTokenLen(plexs) \
            (CchTokenUncachedLen(plexs) + (plexs)->ichCache)
#define InvalLexFetch(plexs) \
            ((plexs)->cchRemain = 0, \
             (plexs)->fInvalLexer = fTrue)
#define FInvalLexFetch(plexs) \
            ((plexs)->fInvalLexer)
#define PrultkFromTokenIrultk(plexs, irultk) \
            PrultkFromIrultk(irultk, (plexs)->rultkhToken.rgrultkCache)
#define IncrTokenPirultk(plexs, pirultk, dirultk) \
            IncrPirultk(pirultk, dirultk, (plexs)->rultkhToken.irultkMac)
#define DecrTokenPirultk(plexs, pirultk, dirultk) \
            DecrPirultk(pirultk, dirultk, (plexs)->rultkhToken.irultkMac)
#define PrultkFormatFromIrultk(plexs, irultk) \
            PrultkFromIrultk(irultk, (plexs)->rultkhFormat.rgrultkCache)
#define IncrFormatPirultk(pirultk, dirultk) \
            IncrPirultk(pirultk, dirultk, (plexs)->rultkhFormat.irultkMac)
#define DecrFormatPirultk(pirultk, dirultk) \
            DecrPirultk(pirultk, dirultk, (plexs)->rultkhFormat.irultkMac)

// shell\inc\powercfp.h
#define PCWM_NOTIFYPOWER                (WM_USER + 201)

// shell\inc\shdocvw.h
#define UQF_DEFAULT                 (UQF_GUESS_PROTOCOL | UQF_USE_DEFAULT_PROTOCOL)

// shell\inc\trayp.h
#define TBC_SETACTIVEALT            (WM_USER + 50)      //  50=0x32
#define TBC_VERIFYBUTTONHEIGHT      (WM_USER + 51)
#define TBC_WARNNODROP              (WM_USER + 54)
#define TBC_CHANGENOTIFY            (WM_USER + 58)
#define TBC_POSTEDRCLICK            (WM_USER + 59)
#define TBC_MARKFULLSCREEN          (WM_USER + 60)
#define TBC_TASKTAB                 (WM_USER + 61)
#define TBC_BUTTONHEIGHT            (WM_USER + 62)
#define WMTRAY_PROGCHANGE           (WM_USER + 200)     // 200=0xc8
#define WMTRAY_RECCHANGE            (WM_USER + 201)
#define WMTRAY_FASTCHANGE           (WM_USER + 202)
#define WMTRAY_COMMONPROGCHANGE     (WM_USER + 205)
#define WMTRAY_COMMONFASTCHANGE     (WM_USER + 206)
#define WMTRAY_FAVORITESCHANGE      (WM_USER + 207)
#define WMTRAY_REGISTERHOTKEY       (WM_USER + 230)
#define WMTRAY_UNREGISTERHOTKEY     (WM_USER + 231)
#define WMTRAY_SETHOTKEYENABLE      (WM_USER + 232)
#define WMTRAY_SCREGISTERHOTKEY     (WM_USER + 233)
#define WMTRAY_SCUNREGISTERHOTKEY   (WM_USER + 234)
#define WMTRAY_QUERY_MENU           (WM_USER + 235)
#define WMTRAY_QUERY_VIEW           (WM_USER + 236)     // 236=0xec
#define TM_ACTASTASKSW              (WM_USER+0x104)
#define TM_LANGUAGEBAND             (WM_USER+0x105)
#define TM_RELAYPOSCHANGED          (WM_USER + 0x150)
#define TM_CHANGENOTIFY             (WM_USER + 0x151)
#define TM_BRINGTOTOP               (WM_USER + 0x152)
#define TM_DOEXITWINDOWS            (WM_USER + 0x156)
#define TM_SHELLSERVICEOBJECTS      (WM_USER + 0x157)
#define TM_HANDLEDELAYBOOTSTUFF     (WM_USER + 0x159)
#define TM_GETHMONITOR              (WM_USER + 0x15a)
#define TM_UIACTIVATEIO             (WM_USER + 0x15c)
#define TM_ONFOCUSCHANGEIS          (WM_USER + 0x15d)
#define TM_MARSHALBS                (WM_USER + 0x15e)
#define TM_REFRESH                  (WM_USER + 0x161)
#define TM_DOTRAYPROPERTIES         (WM_USER + 0x163)
#define TM_PRIVATECOMMAND           (WM_USER + 0x175)
#define TM_STARTUPAPPSLAUNCHED      (WM_USER + 0x178)
#define TM_RAISEDESKTOP             (WM_USER + 0x179)
#define TM_SETPUMPHOOK              (WM_USER + 0x180)
#define TM_STARTMENUDISMISSED       (WM_USER + 0x182)
#define Tray_GetHMonitor(hwndTray, phMon) \
        (DWORD)SendMessage((hwndTray), TM_GETHMONITOR, 0, (LPARAM)(HMONITOR *)phMon)

// shell\inc\win95\vmm.h
#define VMM_TRUE    (~FALSE)	// The opposite of False!
#define CONFIGMG_DEVICE_ID  0x00033 /* Configuration manager (Plug&Play) */
#define P_AVAIL     (P_PRES+P_WRITE+P_USER) /* avail to user & present */

// shell\lib\shfusion\delaycc.c
#define STUB_COMCTL32_VOID(_fn, _args, _nargs)                                \
void __stdcall _fn _args                                                      \
{                                                                             \
    static void (__stdcall *_pfn##_fn) _args = (void (__stdcall *)_args)-1;   \
    if (_pfn##_fn == (void (__stdcall *)_args)-1)                             \
         _GetProcFromComCtl32((FARPROC*)&_pfn##_fn, #_fn);                    \
    STUB_INVOKE_VOID_FN(_pfn ## _fn, _nargs);                                 \
}

// shell\osshell\accesory\calc\scicalc.h
#define xwParam(x,y) ((wParam >=x) && (wParam <=y))

// shell\osshell\accesory\hypertrm\emu\emu.hh
#define VK_BACKSPACE	(VK_BACK   | VIRTUAL_KEY)

// shell\osshell\accesory\hypertrm\emu\keydef.h
#define HVK_BUTTON1			(0x01 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_BUTTON2			(0x02 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_BUTTON3			(0x03 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_BREAK			(0x04 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_BACKSPACE		(0x05 | VIRTUAL_KEY | HVIRTUAL_KEY)   // can't be used in shared code - mrw
#define HVK_TAB				(0x06 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_BACKTAB			(0x07 | VIRTUAL_KEY | HVIRTUAL_KEY)   // can't be used in shared code - mrw
#define HVK_NEWLINE			(0x08 | VIRTUAL_KEY | HVIRTUAL_KEY)   // can't be used in shared code - mrw
#define HVK_CTRL			(0x0A | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_ALT				(0x0B | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_ALTGRAF			(0x0C | VIRTUAL_KEY | HVIRTUAL_KEY)   // can't be used in shared code - mrw
#define HVK_PAUSE			(0x0D | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_ESC				(0x0F | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_SPACE			(0x10 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_END				(0x13 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_HOME			(VK_HOME | VIRTUAL_KEY)
#define HVK_LEFT			(VK_LEFT | VIRTUAL_KEY)
#define HVK_UP				(VK_UP | VIRTUAL_KEY)
#define HVK_HOME			(0x14 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_LEFT			(0x15 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_UP				(0x16 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_RIGHT			(0x17 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_DOWN			(0x18 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_INSERT			(0x1A | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_ENTER			(0x1E | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_SYSRQ			(0x1F | VIRTUAL_KEY | HVIRTUAL_KEY)   // can't be used in shared code - mrw
#define HVK_F1				(0x20 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F2				(0x21 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F3				(0x22 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F4				(0x23 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F5				(0x24 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F6				(VK_F6 | VIRTUAL_KEY)
#define HVK_F7				(VK_F7 | VIRTUAL_KEY)
#define HVK_F8				(VK_F8 | VIRTUAL_KEY)
#define HVK_F9				(VK_F9 | VIRTUAL_KEY)
#define HVK_F6				(0x25 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F7				(0x26 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F8				(0x27 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F9				(0x28 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F10				(0x29 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F11				(0x2A | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F12				(0x2B | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F13				(0x2C | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F14				(0x2D | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F15				(0x2E | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F16				(0x2F | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F17				(0x30 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F18				(0x31 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F19				(0x32 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F20				(0x33 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F21				(0x34 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F22				(0x35 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F23				(0x36 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_F24				(0x37 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_ENDDRAG			(0x38 | VIRTUAL_KEY | HVIRTUAL_KEY)   // can't be used in shared code - mrw
#define HVK_EREOF			(0x3A | VIRTUAL_KEY | HVIRTUAL_KEY)   // can't be used in shared code - mrw
#define HVK_PA1				(0x3B | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_DECIMAL			(0x4E | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_FSLASH			(0x50 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_MULTIPLY		(0x51 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_CENTER			(0x52 | VIRTUAL_KEY | HVIRTUAL_KEY)

// shell\osshell\accesory\hypertrm\htrn_jis\htrn_jis.hh
#define	SJIS1(A)	(((A >= 129) && (A <= 159)) || ((A >= 224) && (A <= 239)))
#define	SJIS2(A)	((A >= 64) && (A <= 252))
#define	HANKATA(A)	((A >= 161) && (A <= 223))
#define	ISEUC(A)	((A >= 161) && (A <= 254))
#define	ISMARU(A)	((A >= 202) && (A <= 206))
#define	ISNIGORI(A)	(((A >= 182) && (A <= 196)) || ((A >= 202) && (A <= 206)) || (A == 179))

// shell\osshell\accesory\hypertrm\tdll\com.h
#define mComRcvBufrPeek(h,p) ((((PCOM)h)->puchRBData < ((PCOM)h)->puchRBDataLimit) ? \
							 (*(p) = *((PCOM)h)->puchRBData, TRUE) : \
							 ComRcvBufrRefill((h), (p), FALSE))

// shell\osshell\accesory\hypertrm\xfer\krm.hh
#define ctl(ch) ((ch) ^ 0x40)

// shell\osshell\accesory\hypertrm\xfer\krm_rcv.c
#define	isadigit(x)	((x >= '0') && (x <= '9'))

// shell\osshell\accesory\hypertrm\xfer\zmodem.h
#define ZDLEE (ZDLE^0100)	/* Escaped ZDLE as transmitted */

// shell\osshell\accesory\hypertrm\xfer\zmodem.hh
#define CAN ('X'&037)
#define XOFF ('s'&037)
#define XON ('q'&037)

// shell\osshell\accesory\mspaint\toolbox.h
#define TM_TOOLDOWN     (WM_USER+0x0010)
#define TM_TOOLUP       (WM_USER+0x0011)
#define TM_TOOLDBLCLK   (WM_USER+0x0012)
#define TM_QUERYDROP    (WM_USER+0x0013)
#define TM_DROP         (WM_USER+0x0014)
#define TM_ABORTDROP    (WM_USER+0x0015)

// shell\osshell\accesory\netclip\netclip\server.h
#define DECLARE_NETCLIPCREATE(class_name) \
public: \
	static AFX_DATA CNetClipObjectFactory factory; \
	static AFX_DATA const GUID guid; \

// shell\osshell\accesory\newpad\notepad.c
#define DeepTrouble() MessageBox(hwndNP, szErrSpace, szNN, MB_SYSTEMMODAL|MB_OK|MB_ICONSTOP);

// shell\osshell\accesory\notepad\notepad.c
#define DeepTrouble() MessageBox(hwndNP, szErrSpace, szNN, MB_SYSTEMMODAL|MB_OK|MB_ICONHAND);

// shell\osshell\accesory\ratpak\ratpak.h
#define RENORMALIZE(x) if ( (x)->pp->exp < 0 ) { \
	(x)->pq->exp -= (x)->pp->exp; \
	(x)->pp->exp = 0; \
	} \
	if ( (x)->pq->exp < 0 ) { \
	(x)->pp->exp -= (x)->pq->exp; \
	(x)->pq->exp = 0; \
	}

// shell\osshell\accesory\ratpak\support.c
#define READRAWRAT(v) createrat(v); DUPNUM(v->pp,(&(init_p_##v))); \
DUPNUM(v->pq,(&(init_q_##v)));
#define READRAWNUM(v) DUPNUM(v,(&(init_##v)))

// shell\osshell\accesory\terminal\fsemacro.h
#define GET_WM_COMMAND_HWND(wParam, lParam)     ((HWND) lParam)
#define MDI_CREATE(hwnd, long)                  ((HWND) SendMessage(hwnd, WM_MDICREATE, (UINT) 0, (LONG)long))
#define GET_MDI_ACTIVE(hwnd, w, l)              ((HWND) SendMessage(hwnd, WM_MDIGETACTIVE, (UINT) 0, 0L))
#define MDI_SETMENU(hwnd, a, b)                 ((HMENU) SendMessage(hwnd, WM_MDISETMENU, (UINT) a, (LONG) b))
#define MDI_TILE(hwnd)                          ((LONG) SendMessage(hwnd, WM_MDITILE, (UINT) 0, 0L))
#define GET_WM_CTLCOLOR_HWND(w, l)              ((HWND)  l)
#define GET_WM_ACTIVATE_HWND(w, l)              ((HWND) l)

// shell\osshell\accesory\uce\uce\kd.cxx
#define  NOT_EUDC(wc)  ((wc)<0xE000||(wc)>0xF8FF)

// shell\osshell\accesory\winchat\winchat.h
#define GET_WM_MENUSELECT_HMENU(wParam,lParam)  (HMENU)lParam
#define GET_WM_CTLCOLOREDIT_HWND(wParam,lParam) (HWND)lParam
#define GET_WM_MENUSELECT_CMD(wParam,lParam)    (UINT)wParam
#define GET_WM_CTLCOLOREDIT_HWND(wParam,lParam) (HWND)(LOWORD(lParam))

// shell\osshell\accessib\narrator\narrator\speech.h
#define  VCMDRF_ALLMESSAGES     (VCMDRF_ALLBUTVUMETER | VCMDRF_VUMETER)

// shell\osshell\accessib\osk\src\kbmain.c
    #define GET_KEY_INDEX(sc, i, fext) \
    { \
	    i = FindKey(sc, fext); \
	    if (i < 0) \
		    break;	/* internal error! */ \
    }

// shell\osshell\control\console\console.h
#define IsBilingualCP(cp) ((cp)==CP_JPN || (cp)==CP_WANSUNG)
#define IsFarEastCP(cp) ((cp)==CP_JPN || (cp)==CP_WANSUNG || (cp)==CP_TC || (cp)==CP_SC)

// shell\osshell\control\console\font.h
#define SIZE_EQUAL(s1, s2)   (((s1).X == (s2).X) && ((s1).Y == (s2).Y))

// shell\osshell\control\console\fontdlg.h
#define lcbRESETCONTENT(hWnd, bLB) \
        SendMessage(hWnd, bLB ? LB_RESETCONTENT : CB_RESETCONTENT, 0, 0L)
#define lcbGETTEXT(hWnd, bLB, w) \
        SendMessage(hWnd, bLB ? LB_GETTEXT : CB_GETLBTEXT, w, 0L)
#define lcbFINDSTRINGEXACT(hWnd, bLB, pwsz) \
        (LONG)SendMessage(hWnd, bLB ? LB_FINDSTRINGEXACT : CB_FINDSTRINGEXACT, \
                          (WPARAM)-1, (LPARAM)pwsz)
#define lcbADDSTRING(hWnd, bLB, pwsz) \
        (LONG)SendMessage(hWnd, bLB ? LB_ADDSTRING : CB_ADDSTRING, 0, (LPARAM)pwsz)
#define lcbSETITEMDATA(hWnd, bLB, w, nFont) \
        SendMessage(hWnd, bLB ? LB_SETITEMDATA : CB_SETITEMDATA, w, nFont)
#define lcbGETITEMDATA(hWnd, bLB, w) \
        (LONG)SendMessage(hWnd, bLB ? LB_GETITEMDATA : CB_GETITEMDATA, w, 0L)
#define lcbGETCOUNT(hWnd, bLB) \
        (LONG)SendMessage(hWnd, bLB ? LB_GETCOUNT : CB_GETCOUNT, 0, 0L)
#define lcbGETCURSEL(hWnd, bLB) \
        (LONG)SendMessage(hWnd, bLB ? LB_GETCURSEL : CB_GETCURSEL, 0, 0L)
#define lcbSETCURSEL(hWnd, bLB, w) \
        SendMessage(hWnd, bLB ? LB_SETCURSEL : CB_SETCURSEL, w, 0L)

// shell\osshell\control\drivers\infparse.c
#define ISEOL(c)     ((c) == '\n' || (c) == '\r' || (c) == '\0' || (c) == EOF)
#define ISSEP(c)   ((c) == '='  || (c) == ',')

// shell\osshell\control\drivers\sulib.h
#define SLASH(c)     ((c) == '/' || (c) == '\\')

// shell\osshell\control\joy\joycpl.h
#define ALL_BUTTONS	(JOY_BUTTON1|JOY_BUTTON2|JOY_BUTTON3|JOY_BUTTON4)

// shell\osshell\control\joy\joymisc.c
#define FILLBAR( a, id ) \
    /* \
     * make sure we aren't out of alleged range \
     */ \
    if( pji->dw##a##pos > pgv->joyRange.jpMax.dw##a ) { \
	pji->dw##a##pos = pgv->joyRange.jpMax.dw##a; \
    } else if( pji->dw##a##pos < pgv->joyRange.jpMin.dw##a ) { \
	pji->dw##a##pos = pgv->joyRange.jpMin.dw##a; \
    } \
 \
    /* \
     * fill the bar if we haven't moved since last time \
     */ \
    if( pji->dw##a##pos != poji->dw##a##pos ) { \
	fillBar( pgv, hwnd, pji->dw##a##pos, id ); \
	poji->dw##a##pos = pji->dw##a##pos; \
    }

// shell\osshell\control\mmsys\draw.h
#define DF_GET_BMPHANDLE    (HBITMAP)(GetWindowLongPtr(hWnd, 0))
#define DF_GET_BMPPAL       (HPALETTE)(GetWindowLong(hWnd, 4))
#define DF_GET_BMPPAL       (HPALETTE)(GetWindowLongPtr(hWnd, sizeof(UINT_PTR)))
#define DF_SET_BMPPAL(x)    (SetWindowLongPtr(hWnd, sizeof(UINT_PTR), (LONG_PTR)(x)))

// shell\osshell\control\mmsys\drivers.c
#define TreeView_GetGrandParent(_htree,_hti) \
        TreeView_GetParent(_htree,TreeView_GetParent(_htree,_hti))

// shell\osshell\control\mmsys\infparse.c
#define ISEOL(c)     ((c) == '\n' || (c) == '\r' || (c) == '\0' || (c) == EOF)
#define ISSEP(c)   ((c) == '='  || (c) == ',')

// shell\osshell\control\mmsys\utils.h
#define SetDlgHandle(hwnd, msg, lp)     if((msg)==WM_SETFONT) (lp)->hdlg=(hwnd);

// shell\osshell\control\schemes\cursors.c
#define PM_NEWCURSOR            (WM_USER + 1)
#define PM_PAUSEANIMATION       (WM_USER + 2)
#define PM_UNPAUSEANIMATION     (WM_USER + 3)

// shell\osshell\control\scrnsave\flyingobjects\flyingobjects.h
#define D3DFVF_MYVERTEX ( D3DFVF_XYZ | D3DFVF_NORMAL )
#define D3DFVF_MYVERTEX2 ( D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 )
#define D3DFVF_MYVERTEX3 ( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1 )
#define V3Sub(a, b, r) \
    ((r)->x = (a)->x-(b)->x, (r)->y = (a)->y-(b)->y, (r)->z = (a)->z-(b)->z)
#define V3Add(a, b, r) \
    ((r)->x = (a)->x+(b)->x, (r)->y = (a)->y+(b)->y, (r)->z = (a)->z+(b)->z)
#define V3Cross(a, b, r) \
    ((r)->x = (a)->y*(b)->z-(b)->y*(a)->z,\
     (r)->y = (a)->z*(b)->x-(b)->z*(a)->x,\
     (r)->z = (a)->x*(b)->y-(b)->x*(a)->y)

// shell\osshell\control\scrnsave\museum\d3dfont.cpp
#define D3DFVF_FONT2DVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
#define D3DFVF_FONT3DVERTEX (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1)

// shell\osshell\control\scrnsave\museum\object.h
#define D3DFVF_MYVERTEX (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1)

// shell\osshell\control\scrnsave\museum\util.h
#define TaskBar_SetRange(hwndControl, fRedraw, nMin, nMax)  SendMessage(hwndControl, TBM_SETRANGE, (WPARAM) (BOOL) fRedraw, (LPARAM) MAKELONG(nMin, nMax))
#define TaskBar_SetPos(hwndControl, fRedraw, nPosition)  SendMessage(hwndControl, TBM_SETPOS, (WPARAM) (BOOL) fRedraw, (LPARAM) (LONG) nPosition)
#define TaskBar_GetPos(hwndControl)  (int) SendMessage(hwndControl, TBM_GETPOS, 0, 0)

// shell\osshell\control\scrnsave\pipes\pipes.cpp
#define D3DFVF_MYVERTEX (D3DFVF_XYZ | D3DFVF_TEX1)

// shell\osshell\control\scrnsave\pipes\stdafx.h
#define D3DFVF_VERTEX (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1)
#define D3DFVF_TLVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)

// shell\osshell\control\scrnsave\swoosh\swoosh.cpp
#define	FVF_SimpleVertex	(D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1)

// shell\osshell\control\sound\snd.c
#define     SetWindowRedraw(hwnd, fRedraw)  \
            ((VOID)SendMessage(hwnd, WM_SETREDRAW, (UINT)(BOOL)(fRedraw), 0L))
#define SLASH(c)        ((c) == '/' || (c) == '\\')

// shell\osshell\control\t1instal\fvscodes.h
#define FVS_FILE(c)          ((c) & 0x00FF)        // Get file part

// shell\osshell\control\t1instal\metrics.h
#define GetWeight(t1m)           &(t1m->stems)
#define GetBlues(t1m)            &(t1m->blues)
#define SyntheticOblique(t1m)    (t1m->fmatrix && t1m->fmatrix[2])

// shell\osshell\cpls\intl\intl.h
#define ML_STATIC            (ML_PERMANENT | ML_DEFAULT | ML_DISABLE)

// shell\osshell\cpls\main\applet.h
#define APPLET_REBOOT             (APPLET_RESTART | 0x4)

// shell\osshell\cpls\ports\advandlg.c
#define Trackbar_SetTic(hwndTb, Tic)\
    (VOID) SendMessage(hwndTb, TBM_SETTIC, (WPARAM) 0, (LPARAM) Tic)

// shell\osshell\cpls\powercfg\pwrmn_cs.h
#define IDH_100_1001	65601636	// Power Schemes: "&Save As..." (Button)
#define IDH_100_1002	65667172	// Power Schemes: "&Delete" (Button)
#define IDH_100_1009	66125924	// Power Schemes: "Go on s&tandby:" (Static)
#define IDH_100_1010	66191460	// Power Schemes: "Turn off &monitor:" (Static)
#define IDH_100_1003	65732708	// Power Schemes: "Ad&vanced..." (Button)
#define IDH_101_1001	65601637	// Power Schemes: "&Save As..." (Button)
#define IDH_101_1002	65667173	// Power Schemes: "&Delete" (Button)
#define IDH_101_1009	66125925	// Power Schemes: "Go on s&tandby:" (Static)
#define IDH_101_1010	66191461	// Power Schemes: "Turn off &monitor:" (Static)
#define IDH_101_1003	65732709	// Power Schemes: "Ad&vanced..." (Button)
#define IDH_107_1509	98893931	// Advanced Power Scheme Settings: "Turn off hard &disks:" (Static)
#define IDH_108_1509    98893932    // Advanced Power Scheme Settings: "Turn off hard &disks:" (Static)
#define IDH_103_1101	72155239	// Alarms: "Alar&m Action..." (Button)
#define IDH_103_1107	72548455	// Alarms: "Set off &critical battery alarm when power level reaches:" (Button)
#define IDH_103_1100	72089703	// Alarms: "Ala&rm Action..." (Button)
#define IDH_106_1603	105054314	// Alarm Actions: "&Sound alarm" (Button)
#define IDH_106_1605	105185386	// Alarm Actions: "&Display message" (Button)
#define IDH_106_1600	104857706	// Alarm Actions: "When the &alarm goes off, the computer will:" (Button)
#define IDH_106_1602	104988778	// Alarm Actions: "&Force standby or shutdown even if a program stops responding." (Button)
#define IDH_102_1203	78839910	// Battery Meter: "&Show meter on taskbar." (Button)

// shell\osshell\dskquota\control\sidname.cpp
#define SNRM_EXIT_THREAD         (WM_USER + 2)

// shell\osshell\dskquota\ui\userprop.cpp
#define DQM_QUERY_USER_ICON        (WM_USER + 2)
#define DQM_ENABLE_APPLY_BUTTON    (WM_USER + 3)

// shell\osshell\dskquota\ui\volprop.cpp
#define VPPM_FOCUS_ON_THRESHOLDEDIT  (WM_USER + 1)

// shell\osshell\ep\carddll\cards.h
#define CardSuit(index)          ((index) & 3)

// shell\osshell\ep\carddll\crd.h
#define SuFromCd(cd) ((cd)&0x03)

// shell\osshell\ep\oldtp\taipei.c
#define CYAN		(GREEN | BLUE)
#define PURPLE		(RED | BLUE)

// shell\osshell\ep\snake\blk.c
#define SurFromBlk(blk)  ((SUR) ((blk) & 0x0007))

// shell\osshell\ep\snake\rtns.c
#define DirFromBlk(blk)      ((DIR) ((blk) & 0x0003))

// shell\osshell\ep\snake\snake.h
#define FMenuOn()          ((Preferences.fMenu &  0x01) == 0)

// shell\osshell\ep\tictac\main.h
#define FMenuOn()          ((Preferences.fMenu &  0x01) == 0)

// shell\osshell\fontfldr\fontview\fontview.c
#define IsZeroFSig( fs )  ( (fs)->fsUsb[0] == 0 && (fs)->fsUsb[1] == 0 && (fs)->fsUsb[2] == 0 && \
                                (fs)->fsUsb[3] == 0 && (fs)->fsCsb[0] == 0 && (fs)->fsCsb[1] == 0 )

// shell\osshell\games\mshearts\computer.h
#define QKA_CARDS		(VECTOR_QUEEN | VECTOR_KING | VECTOR_ACE)
#define JQKA_CARDS		(VECTOR_JACK | VECTOR_QUEEN | VECTOR_KING \
				 | VECTOR_ACE)

// shell\osshell\games\sol\back.c
#define ropDPSao 0x00EA02E9   /* (Source & Pattern) | Dest */

// shell\osshell\games\sol\col.h
#define SendColMsg(pcol, msgc, wp1, wp2) \
    (*((pcol)->lpfnColProc))((pcol), (msgc), (wp1), (wp2))

// shell\osshell\games\sol\crd.h
#define SuFromCd(cd) ((cd)&0x03)

// shell\osshell\games\sol\game.h
#define SendGmMsg(pgm, msgg, wp1, wp2) \
	(*((pgm)->lpfnGmProc))((pgm), (msgg), (wp1), (wp2))

// shell\osshell\lmui\ntshrui\acl.hxx
#define FILE_PERM_GEN_READ               (GENERIC_READ    |\
                                          GENERIC_EXECUTE)

// shell\osshell\lmui\shareui\acl.hxx
#define FILE_PERM_GEN_READ               (GENERIC_READ    |\
                                          GENERIC_EXECUTE)

// shell\osshell\lmui\shareui\shares.h
#define Share_IsSpecial(pidl)           (Share_IsNetWareWizard(pidl) || Share_IsMacWizard(pidl) || Share_IsNewShareWizard(pidl))

// shell\osshell\regwiz\regwizexe\rwexemain.h
  #define GET_WM_COMMAND_ID(w,l) (w)
  #define GET_WM_COMMAND_HWND(w,l) LOWORD(l)

// shell\osshell\regwiz\regwizpost\dconv.cpp
#define  NAME_SEPERATOR         _T("&") 	 // Seperator between the names

// shell\osshell\snapins\devmgr\snapin\devdrvpg.h
#define idh_devmgr_driver_change_driver 106140  // Driver: "&Change Driver..." (Button)
#define idh_devmgr_devdrv_uninstall     400500  // Driver: "&Uninstall" (Button)

// shell\osshell\snapins\devmgr\snapin\devrmdlg.h
#define idh_devmgr_confirmremoval_all   210110  // Confirm Device Removal: "Remove from &all configurations." (Button)
#define idh_devmgr_confirmremoval_specific  210120  // Confirm Device Removal: "Remove from &specific configuration." (Button)

// shell\osshell\taskman\taskman.h
#define LBS_MYSTYLE         (LBS_NOTIFY | LBS_OWNERDRAWFIXED | WS_VSCROLL)

// shell\osshell\themes\themesw\schedule.cpp
#define EVERY_MONTH (TASK_JANUARY | TASK_FEBRUARY | TASK_MARCH | TASK_APRIL |\
                     TASK_MAY | TASK_JUNE | TASK_JULY | TASK_AUGUST |\
                     TASK_SEPTEMBER | TASK_OCTOBER | TASK_NOVEMBER |\
                     TASK_DECEMBER)

// shell\published\inc\aclui.h
#define SI_EDIT_ALL     (SI_EDIT_PERMS | SI_EDIT_OWNER | SI_EDIT_AUDITS)

// shell\published\inc\pif.h
#define FNT_DEFAULT             (FNT_BOTHFONTS | FNT_AUTOSIZE)
#define FNT_BOTHFONTS           (FNT_RASTERFONTS | FNT_TTFONTS)
#define WIN_DEFAULT             (WIN_SAVESETTINGS | WIN_TOOLBAR)

// shell\published\inc\uxtheme.h
#define HTTB_RESIZINGBORDER         (HTTB_RESIZINGBORDER_LEFT|HTTB_RESIZINGBORDER_TOP|\
                                     HTTB_RESIZINGBORDER_RIGHT|HTTB_RESIZINGBORDER_BOTTOM)

// shell\shdocvw\admovr2.h
#define OLEMISMOVR (OLEMISC_ALWAYSRUN|OLEMISC_NOUIACTIVATE|OLEMISC_SETCLIENTSITEFIRST|OLEMISC_ACTIVATEWHENVISIBLE|OLEMISC_RECOMPOSEONRESIZE|OLEMISC_CANTLINKINSIDE|OLEMISC_INSIDEOUT)

// shell\shdocvw\common.h
#define Release(punk)                   (punk)->lpVtbl->Release(punk)

// shell\shdocvw\dochost.h
#define SHOULD_DO_SEARCH(x,y) (y || (x && x != DONE_SUFFIXES))

// shell\shdocvw\fldset.cpp
#define IShellView2_GetView(_pi, _pv, _flg) \
    (_pi)->GetView(_pv, _flg)
#define IShellView2_CreateViewWindow2(_pi, _cParams) \
    (_pi)->CreateViewWindow2(_cParams)
#define IUnknown_QueryInterface(_pu, _riid, _pi) \
        (_pu)->QueryInterface(_riid, (LPVOID*)_pi)

// shell\shdocvw\nsc.cpp
#define IsEqualSCID(a, b)   (((a).pid == (b).pid) && IsEqualIID((a).fmtid, (b).fmtid))
#define TreeView_GetFont(hwnd)  (HFONT)::SendMessage(hwnd, WM_GETFONT, 0, 0)

// shell\shdocvw\priv.h
#define ISVISIBLE(hwnd)  ((GetWindowStyle(hwnd) & WS_VISIBLE) == WS_VISIBLE)

// shell\shdocvw\util.h
#define FillExecInfo(_info, _hwnd, _verb, _file, _params, _dir, _show) \
        (_info).hwnd            = _hwnd;        \
        (_info).lpVerb          = _verb;        \
        (_info).lpFile          = _file;        \
        (_info).lpParameters    = _params;      \
        (_info).lpDirectory     = _dir;         \
        (_info).nShow           = _show;        \
        (_info).fMask           = 0;            \
        (_info).cbSize          = sizeof(SHELLEXECUTEINFO);
#define FORCE_COPY (MK_LBUTTON | MK_CONTROL)                // means copy
#define PVAREMPTY ((VARIANT*)&c_vaEmpty)

// shell\shell32\browse.cpp
#define WINDOWSTYLES_EX_BFF    (WS_EX_LEFT | WS_EX_LTRREADING)

// shell\shell32\cdburn.cpp
#define SUPPORTED(x) ((x) && !((x) == DRIVE_NOTSUPPORTED))

// shell\shell32\combview.cpp
#define ISMOUSEDOWN(msg) ((msg) == WM_LBUTTONDOWN || (msg) == WM_RBUTTONDOWN || (msg) == WM_MBUTTONDOWN)
        #define MK_BUTTON (MK_LBUTTON | MK_RBUTTON | MK_MBUTTON)

// shell\shell32\control.h
#define REGCPL_CPLNAME(pRegCPLInfo)  (&((pRegCPLInfo)->buf[(pRegCPLInfo)->oName]))
#define REGCPL_CPLINFO(pRegCPLInfo)  (&((pRegCPLInfo)->buf[(pRegCPLInfo)->oInfo]))

// shell\shell32\copy.c
#define PDM_NOOP        (WM_APP + 1)
#define PDM_UPDATE      (WM_APP + 2)
#define     DTF_FILES_AND_FOLDERS  (DTF_FILES_ONLY | DTF_FOLDERS_ONLY)  //Operate on files AND folders.
#define DTNIsConnected(pdtn)    (pdtn && (pdtn->fConnectedElement))

// shell\shell32\ctrlfldr.cpp
#define HANDLE_SFVM_GETWEBVIEWBARRICADE(pv, wP, lP, fn) \
    ((fn)((pv), (DUI::Element**)(lP)))

// shell\shell32\defview.cpp
#define ViewRequiresColumns(x)  ((x) == FVM_DETAILS || (x) == FVM_TILE)
#define SFGAO_RELEVANT      (SFGAO_CANCOPY | SFGAO_CANMOVE)

// shell\shell32\dragdrop.cpp
#define ListView_IsIconView(hwndLV)    ((GetWindowLong(hwndLV, GWL_STYLE) & (UINT)LVS_TYPEMASK) == (UINT)LVS_ICON)

// shell\shell32\execute.cpp
#define ISONE2ONE(e)   (e == SE_ERR_FNF || e == SE_ERR_PNF || e == SE_ERR_ACCESSDENIED || e == SE_ERR_OOM)

// shell\shell32\filefldr.cpp
#define SFGAO_NOT_RECENT    (SFGAO_CANRENAME | SFGAO_CANLINK)

// shell\shell32\filetbl.cpp
#define GIL_COMPARE (GIL_SIMULATEDOC | GIL_NOTFILENAME)

// shell\shell32\filtgrep.h
#define FGIF_BLANKETGREP        (FGIF_GREPCONTENT|FGIF_GREPPROPERTIES)

// shell\shell32\finddlg.h
#define WMU_COMBOPOPULATIONCOMPLETE     (WM_USER+0x200) // (wParam: HWND of combo).
#define WMU_RESTORESEARCH               (WM_USER+0x203) // (wParam: n/a, lParam: n/a, ret: n/a).
#define WMU_NAMESPACERECONCILE          (WM_USER+0x205) // (wParam: n/a, LPARAM: n/a).
#define  DWM_FIRST          (WM_USER+0x300)

// shell\shell32\findfilter.cpp
#define SFGAO_FS_SEARCH (SFGAO_FILESYSANCESTOR | SFGAO_FOLDER)

// shell\shell32\fsassoc.cpp
#define WMUSER_CREATETOOLTIP        (WM_USER + 1)       // lParam is the hwndParent, wParam is the WSTR.

// shell\shell32\hwcmmn.h
#define CT_ANYAUTOPLAYCONTENT          (   CT_AUTOPLAYMUSIC | \
                                                        CT_AUTOPLAYPIX | \
                                                        CT_AUTOPLAYMOVIE)

// shell\shell32\idltree.cpp
#define _IsEmptyNode(pin)       (!(pin)->_pinKids && !(pin)->_pidDatas)

// shell\shell32\linkwnd.cpp
#define TEST_CAPTURE(fTest)           ((_fCapture & fTest) != 0)
#define MODIFY_CAPTURE(fSet, fRemove) {if (fSet){_fCapture |= fSet;} if (fRemove){_fCapture &= ~fRemove;}}

// shell\shell32\lnkcon.c
#define pcpd (&pld->cpd)
#define pcpd (&pld->cpd)

// shell\shell32\lnkcon.h
#define SIZE_EQUAL(s1, s2)   (((s1).X == (s2).X) && ((s1).Y == (s2).Y))
#define lcbRESETCONTENT(hWnd, bLB) \
        SendMessage(hWnd, bLB ? LB_RESETCONTENT : CB_RESETCONTENT, 0, 0L)
#define lcbGETTEXT(hWnd, bLB, w) \
        SendMessage(hWnd, bLB ? LB_GETTEXT : CB_GETLBTEXT, w, 0L)
#define lcbFINDSTRINGEXACT(hWnd, bLB, pwsz) \
        SendMessage(hWnd, bLB ? LB_FINDSTRINGEXACT : CB_FINDSTRINGEXACT, \
                          (DWORD)-1, (LPARAM)pwsz)
#define lcbADDSTRING(hWnd, bLB, pwsz) \
        SendMessage(hWnd, bLB ? LB_ADDSTRING : CB_ADDSTRING, 0, (LPARAM)pwsz)
#define lcbSETITEMDATA(hWnd, bLB, w, nFont) \
        SendMessage(hWnd, bLB ? LB_SETITEMDATA : CB_SETITEMDATA, w, nFont)
#define lcbGETITEMDATA(hWnd, bLB, w) \
        SendMessage(hWnd, bLB ? LB_GETITEMDATA : CB_GETITEMDATA, w, 0L)
#define lcbGETCOUNT(hWnd, bLB) \
        SendMessage(hWnd, bLB ? LB_GETCOUNT : CB_GETCOUNT, 0, 0L)
#define lcbGETCURSEL(hWnd, bLB) \
        SendMessage(hWnd, bLB ? LB_GETCURSEL : CB_GETCURSEL, 0, 0L)
#define lcbSETCURSEL(hWnd, bLB, w) \
        SendMessage(hWnd, bLB ? LB_SETCURSEL : CB_SETCURSEL, w, 0L)

// shell\shell32\menuband\isfband.cpp
#define CISFBAND_GETBUTTONSIZE()  (_hwndTB ?  (LONG)SendMessage(_hwndTB, TB_GETBUTTONSIZE, 0, 0L) : MAKELONG(16, 16))

// shell\shell32\menuband\util.cpp
#define PVAREMPTY ((VARIANT*)&c_vaEmpty)

// shell\shell32\menuband\util.h
#define PVAREMPTY ((VARIANT*)&c_vaEmpty)

// shell\shell32\mergfldr.cpp
#define CDBURNEVENTS (SHCNE_MEDIAREMOVED | SHCNE_MEDIAINSERTED)

// shell\shell32\mtpt.h
#define DT_ANYCDDRIVES                   (   DT_CDROM | \
                                                        DT_CDR | \
                                                        DT_CDRW | \
                                                        DT_DVDROM | \
                                                        DT_DVDRAM | \
                                                        DT_DVDR | \
                                                        DT_DVDRW )
#define DT_ANYDVDDRIVES                  (   DT_DVDROM | \
                                                        DT_DVDRAM | \
                                                        DT_DVDR | \
                                                        DT_DVDRW )

// shell\shell32\mydocsfldr.cpp
#define SFGAO_ATTRIBS_MERGE    (SFGAO_SHARE | SFGAO_HASPROPSHEET)

// shell\shell32\netview.h
#define NET_GetUsage(pidnRel)           ((pidnRel)->uUsage & 0x0f)
#define NET_FHasComment(pidnRel)        ((pidnRel)->uUsage & NET_HASCOMMENT)
#define NET_FHasProvider(pidnRel)       ((pidnRel)->uUsage & NET_HASPROVIDER)
#define NET_IsRemoteFld(pidnRel)        ((pidnRel)->uUsage & NET_REMOTEFLD)

// shell\shell32\piffnt.c
#define HasScrollbars(z) \
    (pfi->winOriginal.c##z##Cells * pfi->fntProposed.c##z##FontActual > \
     pfi->winOriginal.c##z##Client)

// shell\shell32\piffntp.h
#define lcbFindStringExact(hwnd, fListBox, lpsz) \
        (DWORD)SendMessage(hwnd, fListBox ? LB_FINDSTRINGEXACT : CB_FINDSTRINGEXACT, \
                          (WPARAM)-1, (LPARAM)(LPTSTR)lpsz)
#define lcbAddString(hwnd, fListBox, lpsz) \
        (DWORD)SendMessage(hwnd, fListBox ? LB_ADDSTRING : CB_ADDSTRING, \
                          0, (LPARAM)(LPTSTR)lpsz)
#define lcbSetItemDataPair(hwnd, fListBox, w, bpfdi, fIsTrueType) \
        if (!IsSpecialBpfdi((BPFDI)bpfdi)) \
            ((BPFDI)bpfdi)->bTT = fIsTrueType; \
        (DWORD)SendMessage(hwnd, fListBox ? LB_SETITEMDATA : CB_SETITEMDATA, \
                    (WPARAM)w, (LPARAM)bpfdi)
#define lcbGetCount(hwnd, fListBox) \
        (DWORD)SendMessage(hwnd, fListBox ? LB_GETCOUNT : CB_GETCOUNT, (WPARAM)0, (LPARAM)0)
#define lcbGetCurSel(hwnd, fListBox) \
        (DWORD)SendMessage(hwnd, fListBox ? LB_GETCURSEL : CB_GETCURSEL, (WPARAM)0, (LPARAM)0)
#define lcbSetCurSel(hwnd, fListBox, w) \
        (DWORD)SendMessage(hwnd, fListBox ? LB_SETCURSEL : CB_SETCURSEL, (WPARAM)w, (LPARAM)0)
#define lcbGetItemDataPair(hwnd, fListBox, w) \
        (DWORD_PTR)SendMessage(hwnd, fListBox ? LB_GETITEMDATA : CB_GETITEMDATA, (WPARAM)w, (LPARAM)0)
#define lcbInsertString(hwnd, fListBox, lpsz, i) \
        (DWORD)SendMessage(hwnd, fListBox ? LB_INSERTSTRING : CB_INSERTSTRING, \
                           (WPARAM)i, (LPARAM)(LPTSTR)lpsz)

// shell\shell32\pifmgrp.h
#define Z2(m)               ((m)&1?0:(m)&2?1:2)
#define IsBilingualCP(cp) ((cp)==CP_JPN || (cp)==CP_WANSUNG)
#define IsFarEastCP(cp) ((cp)==CP_JPN || (cp)==CP_WANSUNG || (cp)==CP_TC || (cp)==CP_SC)

// shell\shell32\regfldr.cpp
#define SHAppCompatCreateViewObject(psf, hwnd, riid, ppv) \
        psf->CreateViewObject(hwnd, riid, ppv)

// shell\shell32\scnotify.cpp
#define FFCN_INTERESTING_EVENTS     (FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_DIR_NAME | FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_ATTRIBUTES)

// shell\shell32\shell.h
#define SE_ERR_FNF                      2       // ShellExec() error returns

// shell\shell32\shellprv.h
#define STUBM_SETDATA       (WM_USER)
#define STUBM_GETDATA       (WM_USER + 1)
#define STUBM_SETICONTITLE  (WM_USER + 2)

// shell\shell32\tngen\include\jmorecfg.h
#define GETJSAMPLE(value)  ((int) (value) & 0xFF)
#define GETJOCTET(value)  ((value) & 0xFF)

// shell\shell32\unicpp\admovr2.h
#define OLEMISMOVR (OLEMISC_ALWAYSRUN|OLEMISC_NOUIACTIVATE|OLEMISC_SETCLIENTSITEFIRST|OLEMISC_ACTIVATEWHENVISIBLE|OLEMISC_RECOMPOSEONRESIZE|OLEMISC_CANTLINKINSIDE|OLEMISC_INSIDEOUT)

// shell\shell32\unicpp\advanced.cpp
#define ENABLEAPPLY(hDlg) SendMessage(GetParent(hDlg), PSM_CHANGED, (WPARAM)hDlg, 0L)

// shell\shell32\unicpp\deskhtm.h
#define REFRESHACTIVEDESKTOP() (PokeWebViewDesktop(AD_APPLY_FORCE | AD_APPLY_HTMLGEN | AD_APPLY_REFRESH | AD_APPLY_DYNAMICREFRESH))

// shell\shell32\unicpp\deskmovr.cpp
#define CAPTIONBAR_HOTAREA(cyDefaultCaption, cyCurrentCaption) (((cyCurrentCaption == 0) && CAPTION_ONLY) ? (cyDefaultCaption / 2) : 3 * cyDefaultCaption)

// shell\shell32\unicpp\deskstat.h
#define IsWindowLessComponent(pcomp) (((pcomp)->iComponentType == COMP_TYPE_PICTURE) || ((pcomp)->iComponentType == COMP_TYPE_HTMLDOC))

// shell\shell32\util.h
#define IsEqualSCID(a, b)   (((a).pid == (b).pid) && IsEqualIID((a).fmtid, (b).fmtid) )
#define IsEqualSCID(a, b)   (((a).pid == (b).pid) && IsEqualIID(&((a).fmtid),&((b).fmtid)))

// shell\shlwapi\reg.c
#define FillExecInfo(_info, _hwnd, _verb, _file, _params, _dir, _show) \
        (_info).hwnd            = _hwnd;        \
        (_info).lpVerb          = _verb;        \
        (_info).lpFile          = _file;        \
        (_info).lpParameters    = _params;      \
        (_info).lpDirectory     = _dir;         \
        (_info).nShow           = _show;        \
        (_info).fMask           = 0;            \
        (_info).cbSize          = sizeof(SHELLEXECUTEINFOW);

// shell\shlwapi\unicwrap.cpp
#define IsUnicodeComboEx(hWnd) SendMessageA(hWnd, CCM_GETUNICODEFORMAT, 0, 0)

// shell\shlwapi\urlpars.cpp
#define IsUpper(c)              ((c) >= 'A' && (c) <= 'Z')

// shell\shlwapi\util.cpp
#define ISPOW2(i)   (((i) & ~((i) - 1)) == (i))

// shell\themes\test\framemetrics\framemetrics.cpp
                #define IMPLEMENT_NCCOMMANDID(cmd) \
                    case ID_##cmd: _rgf[NC##cmd] = !_rgf[NC##cmd]; fSwp = TRUE; break;

// shell\themes\themesel\stylespage.cpp
    #define ASSIGN_TEST_STYLE(uID, dwStyle) if( IsDlgButtonChecked(hwndPage, uID) ) {(*pdwStyle) |= dwStyle;}
    #define ASSIGN_TEST_EXSTYLE(uID, dwStyle) if( IsDlgButtonChecked(hwndPage, uID) ) {(*pdwExStyle) |= dwStyle;}

// shell\themes\themeui\deskcmmn.h
#define DCDSF_PROBABLY      (DCDSF_ASK  | DCDSF_DYNA)
#define DCDSF_PROBABLY_NOT  (DCDSF_ASK  |          0)
#define DCDSF_YES           (0          | DCDSF_DYNA)
#define DCDSF_NO            (0          |          0)

// shell\themes\themeui\dragsize.h
#define DSM_DRAGPOS	(WM_USER)

// shell\themes\themeui\screensaverpg.cpp
#define WMUSER_SETINITSS        (WM_USER + 1)

// shell\themes\themeui\settingspg.cpp
#define MM_MONITORMOVED  (WM_USER + 2)
#define ToolTip_Activate(hTT, activate) \
    SendMessage(hTT, TTM_ACTIVATE, (WPARAM) activate, (LPARAM) 0)
#define ToolTip_AddTool(hTT, lpti) \
    SendMessage(hTT, TTM_ADDTOOL, (WPARAM) 0, (LPARAM) (lpti))
#define ToolTip_DelTool(hTT, lpti) \
    SendMessage(hTT, TTM_DELTOOL, (WPARAM) 0, (LPARAM) (lpti))
#define ToolTip_GetCurrentTool(hTT, lpti) \
    SendMessage(hTT, TTM_GETCURRENTTOOL, (WPARAM) 0, (LPARAM) (lpti))
#define ToolTip_RelayEvent(hTT, _msg, h, m, wp, lp)                         \
    _msg.hwnd = h; _msg.message = m; _msg.wParam = wp; _msg.lParam = lp;\
    SendMessage(hTT, TTM_RELAYEVENT, (WPARAM) 0, (LPARAM) &_msg);
#define ToolTip_SetDelayTime(hTT, d, t) \
    SendMessage(hTT, TTM_SETDELAYTIME, (WPARAM) d, (LPARAM)MAKELONG((t), 0))
#define ToolTip_SetToolInfo(hTT, lpti) \
    SendMessage(hTT, TTM_SETTOOLINFO, (WPARAM) 0, (LPARAM) (lpti))
#define ToolTip_TrackActivate(hTT, bActivate, lpti) \
    SendMessage(hTT, TTM_TRACKACTIVATE, (WPARAM) (bActivate), (LPARAM) (lpti))
#define ToolTip_TrackPosition(hTT, x, y) \
    SendMessage(hTT, TTM_TRACKPOSITION, (WPARAM) 0, (LPARAM) MAKELONG((x), (y)))
#define ToolTip_Update(hTT) \
    SendMessage(hTT, TTM_UPDATE, (WPARAM) 0, (LPARAM) 0)
    #define SNAPX(f,x) \
        d = rcT.x - rc.f; if (abs(d) <= SNAP_DX) rc.left+=d, rc.right+=d;
    #define SNAPY(f,y) \
        d = rcT.y - rc.f; if (abs(d) <= SNAP_DY) rc.top+=d, rc.bottom+=d;

// shell\themes\themeui\themepg.cpp
#define WMUSER_DELAYENABLEAPPLY            (WM_USER + 1)

// shell\themes\uxtheme\globals.h
#define PROPFLAGS_RESET_TRANSPARENT   (1 << 0)   // hwnd needs WS_EX_TRANSPARENT reset
#define PROPFLAGS_RESET_COMPOSITED    (1 << 1)   // hwnd needs WS_EX_COMPOSITED reset

// shell\themes\uxtheme\handlers.h
#define DECL_SPIHANDLER(handler)                  BOOL CALLBACK handler(NCTHEMEMET*, UINT, UINT, PVOID, UINT, SYSTEMPARAMETERSINFO, BOOL& )
#define DECL_GSMHANDLER(handler)                  int CALLBACK handler(NCTHEMEMET*, int, GETSYSTEMMETRICSPROC, BOOL& )

// shell\themes\uxtheme\nctheme.cpp
#define IsTopLevelWindow(hwnd)          (IsWindow(hwnd) && NULL==GetParent(hwnd))
#define IsHTScrollBar(htCode)           (((htCode) == HTVSCROLL) || ((htCode) == HTHSCROLL))

// shell\themes\uxtheme\scroll.cpp
#define WSB_VERT (WSB_VERT_UP | WSB_VERT_DN)
#define WSB_HORZ   (WSB_HORZ_LF | WSB_HORZ_RT)
    #define REEVALUATE_PSBTRACK(pSBTrack, hwnd, str)          \
        if ((pSBTrack) != CUxScrollBar::GetSBTrack(hwnd)) {             \
            RIPMSG3(RIP_WARNING,                              \
                    "%s: pSBTrack changed from %#p to %#p",   \
                    (str), (pSBTrack), CUxScrollBar::GetSBTrack(hwnd)); \
        }                                                     \
        (pSBTrack) = CUxScrollBar::GetSBTrack(hwnd)
    #define REEVALUATE_PSBTRACK(pSBTrack, hwnd, str)          \
        (pSBTrack) = CUxScrollBar::GetSBTrack(hwnd)

// shell\themes\uxtheme\scrollp.h
#define WFPIXIEHACK             0x0680  // Send (HRGN)1 to WM_NCPAINT (see PixieHack)

// shell\themes\uxtheme\sethook.h
#define ISWINDOW(hwnd)         ((hwnd) && (hwnd != INVALID_HANDLE_VALUE) && (IsWindow(hwnd)))

// termsrv\admtools\c2config\c2config\mainwnd.h
#define  MAINWND_SHOW_MAIN_WINDOW    (WM_USER + 201)

// termsrv\admtools\c2config\c2config\splash.h
#define SWM_DISPLAY_COMPLETE  (WM_USER + 101)
#define SWM_INIT_COMPLETE     (WM_USER + 102)

// termsrv\admtools\c2config\inc\c2inc.h
#define SEND_WM_COMMAND(w,c,n,cw)  SendMessage (w, WM_COMMAND, MAKEWPARAM(c,n), (LPARAM)cw)
#define POST_WM_COMMAND(w,c,n,cw)  PostMessage (w, WM_COMMAND, MAKEWPARAM(c,n), (LPARAM)cw)

// termsrv\cdmodem\inc\rasfile.h
#define RFL_ANYINACTIVE		(RFL_BLANK | RFL_COMMENT)
#define RFL_ANYACTIVE		(RFL_KEYVALUE | RFL_COMMAND)

// termsrv\clcreator\otnboot.h
#define NCDU_UPDATE_WINDOW_POS      (WM_USER+22)

// termsrv\common\license\common\certlib\include\msasnlib.h
#define FTINT(tm) (*(_int64 *)&(tm))

// termsrv\common\license\common\certlib\licecert\certcate.h
#define GET_SIGN_ALG( _Alg )    _Alg & 0xFFFF0000
#define GET_HASH_ALG( _Alg )    _Alg & 0x0000FFFF

// termsrv\common\license\inc\tlsdef.h
#define ISPOLICYMODULECODE(x) (0x08000000 & x)

// termsrv\inc\at128.h
#define TS_DATAPKT_LEN(pPkt) \
        ((pPkt)->shareDataHeader.shareControlHeader.totalLength)
#define TS_CTRLPKT_LEN(pPkt) \
        ((pPkt)->shareControlHeader.totalLength)

// termsrv\inc\ddcgctyp.h
#define DC_GET_WM_COMMAND_ID(wParam) (wParam)
#define DC_GET_WM_COMMAND_HWND(lParam) ((HWND)LOWORD(lParam))
#define DC_GET_WM_ACTIVATE_HWND(lParam) ((HWND)LOWORD(lParam))
#define DC_GET_WM_SCROLL_HWND(lParam) ((HWND)LOWORD(lParam))

// termsrv\inc\ndcgctyp.h
#define DC_GET_WM_COMMAND_HWND(lParam) ((HWND)(lParam))
#define DC_GET_WM_ACTIVATE_HWND(lParam) ((HWND)(lParam))
#define DC_GET_WM_SCROLL_HWND(lParam) ((HWND)(lParam))

// termsrv\inc\wdcgmcro.h
#define CO_SEND_MSG(a,b,c,d) \
            SendMessage(CO_FROM_DCWINID(a),(b),(WPARAM)(c),(LPARAM)(d))

// termsrv\license\tlserver\server\srvdef.h
#define COMMIT_TRANSACTION(stmt) \
    g_DbWorkSpace->CommitTransaction();
#define COMMIT_TRANSACTION(pStmt) \
    pStmt->CommitTransaction();

// termsrv\remdsk\rds\as\h\dcs.h
#define     ETO_WINDOWS         (0x0001 | ETO_OPAQUE | ETO_CLIPPED)

// termsrv\remdsk\rds\as\h\oa.h
#define ORDER_WIDTH(pOrder) \
 ( pOrder->OrderHeader.Common.rcsDst.right - \
                                pOrder->OrderHeader.Common.rcsDst.left + 1 )
#define ORDER_HEIGHT(pOrder) \
 ( pOrder->OrderHeader.Common.rcsDst.bottom - \
                                pOrder->OrderHeader.Common.rcsDst.top + 1 )

// termsrv\remdsk\rds\dev\inc16\ctype.h
#define iscntrl(_c) ( (_ctype+1)[_c] & _CONTROL )

// termsrv\remdsk\rds\dev\inc16\mmsystem.h
#define MIXERCONTROL_CONTROLTYPE_CUSTOM         (MIXERCONTROL_CT_CLASS_CUSTOM | MIXERCONTROL_CT_UNITS_CUSTOM)
#define MIXERCONTROL_CONTROLTYPE_BOOLEANMETER   (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_SIGNEDMETER    (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER  (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_BOOLEAN        (MIXERCONTROL_CT_CLASS_SWITCH | MIXERCONTROL_CT_SC_SWITCH_BOOLEAN | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_BUTTON         (MIXERCONTROL_CT_CLASS_SWITCH | MIXERCONTROL_CT_SC_SWITCH_BUTTON | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_DECIBELS       (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_DECIBELS)
#define MIXERCONTROL_CONTROLTYPE_SIGNED         (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_UNSIGNED       (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_PERCENT        (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_PERCENT)
#define MIXERCONTROL_CONTROLTYPE_SLIDER         (MIXERCONTROL_CT_CLASS_SLIDER | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_FADER          (MIXERCONTROL_CT_CLASS_FADER | MIXERCONTROL_CT_UNITS_UNSIGNED)

// termsrv\remdsk\rds\dev\inc16\windows.h
#define GHND                (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define LHND                (LMEM_MOVEABLE | LMEM_ZEROINIT)
#define QS_MOUSE        (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#define EDGE_RAISED     (BDR_RAISEDOUTER | BDR_RAISEDINNER) // ;Internal 4.0
#define EDGE_SUNKEN     (BDR_SUNKENOUTER | BDR_SUNKENINNER) // ;Internal 4.0
#define EDGE_ETCHED     (BDR_SUNKENOUTER | BDR_RAISEDINNER) // ;Internal 4.0
#define EDGE_BUMP       (BDR_RAISEDOUTER | BDR_SUNKENINNER) // ;Internal 4.0
#define BF_TOPLEFT      (BF_TOP | BF_LEFT)                  // ;Internal 4.0
#define BF_TOPRIGHT     (BF_TOP | BF_RIGHT)                 // ;Internal 4.0
#define BF_BOTTOMLEFT   (BF_BOTTOM | BF_LEFT)               // ;Internal 4.0
#define BF_BOTTOMRIGHT  (BF_BOTTOM | BF_RIGHT)              // ;Internal 4.0
#define BF_DIAGONAL_ENDTOPRIGHT     (BF_DIAGONAL | BF_TOP | BF_RIGHT)       // ;Internal 4.0
#define BF_DIAGONAL_ENDTOPLEFT      (BF_DIAGONAL | BF_TOP | BF_LEFT)        // ;Internal 4.0
#define BF_DIAGONAL_ENDBOTTOMLEFT   (BF_DIAGONAL | BF_BOTTOM | BF_LEFT)     // ;Internal 4.0
#define BF_DIAGONAL_ENDBOTTOMRIGHT  (BF_DIAGONAL | BF_BOTTOM | BF_RIGHT)    // ;Internal 4.0
#define DC_NC               (DC_CAPTION | DC_FRAME)         // ;Internal
#define PAS_HORZ        (PAS_LEFT | PAS_RIGHT)              // ;Internal
#define PAS_VERT        (PAS_UP | PAS_DOWN)                 // ;Internal
#define SWP_NOCHANGE   (SWP_NOSIZE | SWP_NOMOVE |           /* ;Internal */ \
                        SWP_NOZORDER | SWP_NOCLIENTSIZE |   /* ;Internal */ \
                        SWP_NOCLIENTMOVE)                   /* ;Internal */
#define WVR_REDRAW          (WVR_HREDRAW | WVR_VREDRAW)
#define SBM_SETPOS          (WM_USER)                       // ;Internal
#define SBM_GETPOS          (WM_USER+1)                     // ;Internal
#define SBM_ENABLE_ARROWS   (WM_USER+4)                     // ;Internal
#define SBM_SETSCROLLINFO   (WM_USER+9)                     // ;Internal 4.0
#define SBM_GETSCROLLINFO   (WM_USER+10)                    // ;Internal 4.0
#define DM_GETDEFID         (WM_USER+0)
#define DM_SETDEFID         (WM_USER+1)
#define DM_REPOSITION       (WM_USER+2)     /* ;Internal 4.0 */
#define PSM_SHEETINFO       (WM_USER+101)   /* ;Internal 4.0 */
#define STM_SETICON         (WM_USER+0)
#define STM_GETICON         (WM_USER+1)
#define BM_SETSTYLE         (WM_USER+4)
#define BM_CLICK            (WM_USER+5)
#define EM_GETSEL               (WM_USER+0)
#define EM_SETSEL               (WM_USER+1)
#define EM_SCROLL               (WM_USER+5)     // ;Internal
#define EM_LINESCROLL           (WM_USER+6)
#define EM_SCROLLCARET          (WM_USER+7)
#define EM_GETMODIFY            (WM_USER+8)
#define EM_SETMODIFY            (WM_USER+9)
#define EM_LINEINDEX            (WM_USER+11)
#define EM_SETHANDLE            (WM_USER+12)
#define EM_GETHANDLE            (WM_USER+13)
#define EM_GETTHUMB             (WM_USER+14)    // ;Internal
#define EM_REPLACESEL           (WM_USER+18)
#define EM_SETFONT              (WM_USER+19)    /* NOT IMPLEMENTED: use WM_SETFONT */
#define EM_GETLINE              (WM_USER+20)
#define EM_CANUNDO              (WM_USER+22)
#define EM_UNDO                 (WM_USER+23)
#define EM_FMTLINES             (WM_USER+24)
#define EM_SETTABSTOPS          (WM_USER+27)
#define EM_GETFIRSTVISIBLELINE  (WM_USER+30)
#define EM_SETREADONLY          (WM_USER+31)
#define EM_SETMARGINS           (WM_USER+35)    /* ;Internal 4.0 */
#define EM_GETMARGINS           (WM_USER+36)    /* ;Internal 4.0 */
#define EM_RESERVED1		    (WM_USER+0x40)  // ;Internal
#define EM_RESERVED2			(WM_USER+0x41)  // ;Internal
#define EM_RESERVED3			(WM_USER+0x42)  // ;Internal
#define EM_RESERVED4			(WM_USER+0x43)  // ;Internal
#define EM_RESERVED5			(WM_USER+0x44)  // ;Internal
#define LBS_STANDARD            (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)
#define LB_FIRST_16             (WM_USER+1)     // ;Internal
#define LB_RESETCONTENT         (WM_USER+5)
#define LB_SETSEL               (WM_USER+6)
#define LB_SETCURSEL            (WM_USER+7)
#define LB_GETSEL               (WM_USER+8)
#define LB_GETCURSEL            (WM_USER+9)
#define LB_DIR                  (WM_USER+14)
#define LB_GETTOPINDEX          (WM_USER+15)
#define LB_GETSELITEMS          (WM_USER+18)
#define LB_SETTABSTOPS          (WM_USER+19)
#define LB_GETHORIZONTALEXTENT  (WM_USER+20)
#define LB_SETHORIZONTALEXTENT  (WM_USER+21)
#define LB_SETCOLUMNWIDTH       (WM_USER+22)
#define LB_ADDFILE              (WM_USER+23)    // ;Internal
#define LB_SETTOPINDEX          (WM_USER+24)
#define LB_GETITEMDATA          (WM_USER+26)
#define LB_SETITEMDATA          (WM_USER+27)
#define LB_SETANCHORINDEX       (WM_USER+29)
#define LB_GETANCHORINDEX       (WM_USER+30)
#define LB_SETCARETINDEX        (WM_USER+31)
#define LB_GETCARETINDEX        (WM_USER+32)
#define LB_SETITEMHEIGHT        (WM_USER+33)
#define LB_GETITEMHEIGHT        (WM_USER+34)
#define LB_FIRST_40             (WM_USER+41)    // ;Internal 4.0
#define LB_INITSTORAGE          (WM_USER+41)    // ;Internal 4.0

// termsrv\remdsk\rds\dev\inc16\windowsx.h
#define     SetWindowRedraw(hwnd, fRedraw)  \
                    ((void)SendMessage(hwnd, WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L))
#define     IsRestored(hwnd)    ((GetWindowStyle(hwnd) & (WS_MINIMIZE | WS_MAXIMIZE)) == 0L)
#define     SetWindowFont(hwnd, hfont, fRedraw) FORWARD_WM_SETFONT((hwnd), (hfont), (fRedraw), SendMessage)
#define     GetWindowFont(hwnd)                 FORWARD_WM_GETFONT((hwnd), SendMessage)
#define HANDLE_WM_COMPACTING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_COMPACTING(hwnd, compactRatio, fn) \
    (void)(fn)((hwnd), WM_COMPACTING, (WPARAM)(UINT)(compactRatio), 0L)
#define HANDLE_WM_WININICHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_WININICHANGE(hwnd, lpszSectionName, fn) \
    (void)(fn)((hwnd), WM_WININICHANGE, 0, (LPARAM)(LPCSTR)(lpszSectionName))
#define HANDLE_WM_SYSCOLORCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_SYSCOLORCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_SYSCOLORCHANGE, 0, 0L)
#define HANDLE_WM_QUERYNEWPALETTE(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYNEWPALETTE(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYNEWPALETTE, 0, 0L)
#define HANDLE_WM_PALETTEISCHANGING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTEISCHANGING(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTEISCHANGING, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_PALETTECHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTECHANGED(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTECHANGED, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_FONTCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_FONTCHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_FONTCHANGE, 0, 0L)
#define HANDLE_WM_DEVMODECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_DEVMODECHANGE(hwnd, lpszDeviceName, fn) \
    (void)(fn)((hwnd), WM_DEVMODECHANGE, 0,(LPARAM)(LPCSTR)(lpszDeviceName))
#define HANDLE_WM_TIMECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_TIMECHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_TIMECHANGE, 0, 0L)
#define HANDLE_WM_POWER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_POWER(hwnd, code, fn) \
    (void)(fn)((hwnd), WM_POWER, (WPARAM)(code), 0L)
#define HANDLE_WM_QUERYENDSESSION(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYENDSESSION(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYENDSESSION, 0, 0L)
#define HANDLE_WM_ENDSESSION(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENDSESSION(hwnd, fEnding, fn) \
    (void)(fn)((hwnd), WM_ENDSESSION, (WPARAM)(BOOL)(fEnding), 0L)
#define HANDLE_WM_QUIT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_QUIT(hwnd, exitCode, fn) \
    (void)(fn)((hwnd), WM_QUIT, (WPARAM)(exitCode), 0L)
#define HANDLE_WM_SYSTEMERROR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), 0L)
#define FORWARD_WM_SYSTEMERROR(hwnd, errCode, fn) \
    (void)(fn)((hwnd), WM_SYSTEMERROR, (WPARAM)(errCode), 0L)
#define HANDLE_WM_CREATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (CREATESTRUCT FAR*)(lParam)) ? 0L : (LRESULT)-1L)
#define FORWARD_WM_CREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_CREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_NCCREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (CREATESTRUCT FAR*)(lParam))
#define FORWARD_WM_NCCREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCCREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_DESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROY, 0, 0L)
#define HANDLE_WM_NCDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_NCDESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_NCDESTROY, 0, 0L)
#define HANDLE_WM_SHOWWINDOW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), LOWORD(lParam)), 0L)
#define HANDLE_WM_SETREDRAW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_SETREDRAW(hwnd, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETREDRAW, (WPARAM)(fRedraw), 0L)
#define HANDLE_WM_ENABLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define FORWARD_WM_ENABLE(hwnd, fEnable, fn) \
    (void)(fn)((hwnd), WM_ENABLE, (WPARAM)(BOOL)(fEnable), 0L)
#define HANDLE_WM_SETTEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_SETTEXT(hwnd, lpszText, fn) \
    (void)(fn)((hwnd), WM_SETTEXT, 0, (LPARAM)(LPCSTR)(lpszText))
#define HANDLE_WM_GETTEXT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (int)(wParam), (LPSTR)(lParam))
#define FORWARD_WM_GETTEXT(hwnd, cchTextMax, lpszText, fn) \
    (int)(DWORD)(fn)((hwnd), WM_GETTEXT, (WPARAM)(int)(cchTextMax), (LPARAM)(LPSTR)(lpszText))
#define HANDLE_WM_GETTEXTLENGTH(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)(hwnd)
#define FORWARD_WM_GETTEXTLENGTH(hwnd, fn) \
    (int)(DWORD)(fn)((hwnd), WM_GETTEXTLENGTH, 0, 0L)
#define HANDLE_WM_WINDOWPOSCHANGING(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (WINDOWPOS FAR*)(lParam))
#define FORWARD_WM_WINDOWPOSCHANGING(hwnd, lpwpos, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_WINDOWPOSCHANGING, 0, (LPARAM)(WINDOWPOS FAR*)(lpwpos))
#define HANDLE_WM_WINDOWPOSCHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const WINDOWPOS FAR*)(lParam)), 0L)
#define FORWARD_WM_WINDOWPOSCHANGED(hwnd, lpwpos, fn) \
    (void)(fn)((hwnd), WM_WINDOWPOSCHANGED, 0, (LPARAM)(const WINDOWPOS FAR*)(lpwpos))
#define HANDLE_WM_MOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_MOVE(hwnd, x, y, fn) \
    (void)(fn)((hwnd), WM_MOVE, 0, MAKELPARAM((int)(x), (int)(y)))
#define HANDLE_WM_SIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_SIZE(hwnd, state, cx, cy, fn) \
    (void)(fn)((hwnd), WM_SIZE, (WPARAM)(UINT)(state), MAKELPARAM((int)(cx), (int)(cy)))
#define HANDLE_WM_QUERYOPEN(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define FORWARD_WM_QUERYOPEN(hwnd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_QUERYOPEN, 0, 0L)
#define HANDLE_WM_GETMINMAXINFO(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MINMAXINFO FAR*)(lParam)), 0L)
#define FORWARD_WM_GETMINMAXINFO(hwnd, lpMinMaxInfo, fn) \
    (void)(fn)((hwnd), WM_GETMINMAXINFO, 0, (LPARAM)(MINMAXINFO FAR*)(lpMinMaxInfo))
#define HANDLE_WM_PAINT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PAINT(hwnd, fn) \
    (void)(fn)((hwnd), WM_PAINT, 0, 0L)
#define HANDLE_WM_ERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define FORWARD_WM_ERASEBKGND(hwnd, hdc, fn) \
   (BOOL)(DWORD)(fn)((hwnd), WM_ERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define HANDLE_WM_ICONERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define FORWARD_WM_ICONERASEBKGND(hwnd, hdc, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_ICONERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define HANDLE_WM_NCPAINT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HRGN)(wParam)), 0L)
#define FORWARD_WM_NCPAINT(hwnd, hrgn, fn) \
    (void)(fn)((hwnd), WM_NCPAINT, (WPARAM)(HRGN)(hrgn), 0L)
#define HANDLE_WM_NCCALCSIZE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (NCCALCSIZE_PARAMS FAR*)(lParam))
#define FORWARD_WM_NCCALCSIZE(hwnd, fCalcValidRects, lpcsp, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_NCCALCSIZE, (WPARAM)(fCalcValidRects), (LPARAM)(NCCALCSIZE_PARAMS FAR*)(lpcsp))
#define HANDLE_WM_NCHITTEST(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_NCHITTEST(hwnd, x, y, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_NCHITTEST, 0, MAKELPARAM((int)(x), (int)(y)))
#define HANDLE_WM_QUERYDRAGICON(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define FORWARD_WM_QUERYDRAGICON(hwnd, fn) \
    (HICON)(UINT)(DWORD)(fn)((hwnd), WM_QUERYDRAGICON, 0, 0L)
#define HANDLE_WM_DROPFILES(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HDROP)(wParam)), 0L)
#define FORWARD_WM_DROPFILES(hwnd, hdrop, fn) \
    (void)(fn)((hwnd), WM_DROPFILES, (WPARAM)(hdrop), 0L)
#define HANDLE_WM_ACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define FORWARD_WM_ACTIVATE(hwnd, state, hwndActDeact, fMinimized, fn) \
    (void)(fn)((hwnd), WM_ACTIVATE, (WPARAM)(UINT)(state), MAKELPARAM((UINT)(HWND)(hwndActDeact), (UINT)(BOOL)(fMinimized)))
#define HANDLE_WM_ACTIVATEAPP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (HTASK)LOWORD(lParam)), 0L)
#define FORWARD_WM_ACTIVATEAPP(hwnd, fActivate, htaskActDeact, fn) \
    (void)(fn)((hwnd), WM_ACTIVATEAPP, (WPARAM)(BOOL)(fActivate), MAKELPARAM((htaskActDeact),0))
#define HANDLE_WM_NCACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (BOOL)(wParam), (HWND)LOWORD(lParam), (BOOL)HIWORD(lParam))
#define FORWARD_WM_NCACTIVATE(hwnd, fActive, hwndActDeact, fMinimized, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCACTIVATE, (WPARAM)(BOOL)(fActive), MAKELPARAM((UINT)(HWND)(hwndActDeact), (UINT)(BOOL)(fMinimized)))
#define HANDLE_WM_SETFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_SETFOCUS(hwnd, hwndOldFocus, fn) \
    (void)(fn)((hwnd), WM_SETFOCUS, (WPARAM)(HWND)(hwndOldFocus), 0L)
#define HANDLE_WM_KILLFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_KILLFOCUS(hwnd, hwndNewFocus, fn) \
    (void)(fn)((hwnd), WM_KILLFOCUS, (WPARAM)(HWND)(hwndNewFocus), 0L)
#define HANDLE_WM_KEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_KEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_KEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_KEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_CHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_CHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_CHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define HANDLE_WM_DEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_DEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_DEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define HANDLE_WM_SYSKEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSKEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_SYSKEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSKEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(cRepeat), (UINT)(flags)))
#define HANDLE_WM_SYSCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_SYSCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define HANDLE_WM_SYSDEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_SYSDEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSDEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define HANDLE_WM_MOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MOUSEMOVE(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MOUSEMOVE, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_LBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_LBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_LBUTTONDBLCLK : WM_LBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_LBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_LBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_LBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_LBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_RBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_RBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_RBUTTONDBLCLK : WM_RBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_RBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_RBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_RBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_RBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_MBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_MBUTTONDBLCLK : WM_MBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_MBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_MBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_MBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCMOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMOUSEMOVE(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMOUSEMOVE, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCLBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCLBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCLBUTTONDBLCLK : WM_NCLBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define HANDLE_WM_NCLBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCLBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCLBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCLBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCRBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCRBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCRBUTTONDBLCLK : WM_NCRBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCRBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCRBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCRBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCRBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCMBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCMBUTTONDBLCLK : WM_NCMBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_NCMBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCMBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)LOWORD(lParam), (int)HIWORD(lParam), (UINT)(wParam)), 0L)
#define FORWARD_WM_NCMBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )
#define HANDLE_WM_MOUSEACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))
#define FORWARD_WM_MOUSEACTIVATE(hwnd, hwndTopLevel, codeHitTest, msg, fn) \
    (int)(DWORD)(fn)((hwnd), WM_MOUSEACTIVATE, (WPARAM)(HWND)(hwndTopLevel), MAKELPARAM((codeHitTest), (msg)))
#define HANDLE_WM_CANCELMODE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CANCELMODE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CANCELMODE, 0, 0L)
#define HANDLE_WM_TIMER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_TIMER(hwnd, id, fn) \
    (void)(fn)((hwnd), WM_TIMER, (WPARAM)(UINT)(id), 0L)
#define HANDLE_WM_INITMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam)), 0L)
#define FORWARD_WM_INITMENU(hwnd, hMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENU, (WPARAM)(HMENU)(hMenu), 0L)
#define HANDLE_WM_INITMENUPOPUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam), (int)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define FORWARD_WM_INITMENUPOPUP(hwnd, hMenu, item, fSystemMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENUPOPUP, (WPARAM)(HMENU)(hMenu), MAKELPARAM((item),(fSystemMenu)))
#define HANDLE_WM_MENUSELECT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)HIWORD(lParam), (LOWORD(lParam) & MF_POPUP) ? 0 : (int)(wParam), \
                            (LOWORD(lParam) & MF_POPUP) ? (HMENU)(wParam) : 0, LOWORD(lParam)), 0L)
#define FORWARD_WM_MENUSELECT(hwnd, hmenu, item, hmenuPopup, flags, fn) \
    (void)(fn)((hwnd), WM_MENUSELECT, ((flags) & MF_POPUP) ? (WPARAM)(HMENU)(hmenuPopup) : (WPARAM)(int)(item), MAKELPARAM((flags), (hmenu)))
#define HANDLE_WM_MENUCHAR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam), LOWORD(lParam), (HMENU)HIWORD(lParam))
#define FORWARD_WM_MENUCHAR(hwnd, ch, flags, hmenu, fn) \
    (DWORD)(fn)((hwnd), WM_MENUCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((flags), (UINT)(hmenu)))
#define HANDLE_WM_COMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (HWND)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_COMMAND(hwnd, id, hwndCtl, codeNotify, fn) \
    (void)(fn)((hwnd), WM_COMMAND, (WPARAM)(int)(id), MAKELPARAM((UINT)(hwndCtl), (codeNotify)))
#define HANDLE_WM_HSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)HIWORD(lParam), (UINT)(wParam), (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_HSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define HANDLE_WM_VSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)HIWORD(lParam), (UINT)(wParam),  (int)LOWORD(lParam)), 0L)
#define FORWARD_WM_VSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLL, (WPARAM)(UINT)(code), MAKELPARAM((pos), (UINT)(hwndCtl)))
#define HANDLE_WM_CUT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CUT(hwnd, fn) \
    (void)(fn)((hwnd), WM_CUT, 0, 0L)
#define HANDLE_WM_COPY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_COPY(hwnd, fn) \
    (void)(fn)((hwnd), WM_COPY, 0, 0L)
#define HANDLE_WM_PASTE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_PASTE(hwnd, fn) \
    (void)(fn)((hwnd), WM_PASTE, 0, 0L)
#define HANDLE_WM_CLEAR(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CLEAR(hwnd, fn) \
    (void)(fn)((hwnd), WM_CLEAR, 0, 0L)
#define HANDLE_WM_UNDO(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_UNDO(hwnd, fn) \
    (void)(fn)((hwnd), WM_UNDO, 0, 0L)
#define HANDLE_WM_RENDERFORMAT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HANDLE)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_RENDERFORMAT(hwnd, fmt, fn) \
    (HANDLE)(UINT)(DWORD)(fn)((hwnd), WM_RENDERFORMAT, (WPARAM)(UINT)(fmt), 0L)
#define HANDLE_WM_RENDERALLFORMATS(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_RENDERALLFORMATS(hwnd, fn) \
    (void)(fn)((hwnd), WM_RENDERALLFORMATS, 0, 0L)
#define HANDLE_WM_DESTROYCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROYCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROYCLIPBOARD, 0, 0L)
#define HANDLE_WM_DRAWCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DRAWCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DRAWCLIPBOARD, 0, 0L)
#define HANDLE_WM_PAINTCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const PAINTSTRUCT FAR*)GlobalLock((HGLOBAL)LOWORD(lParam))), GlobalUnlock((HGLOBAL)LOWORD(lParam)), 0L)
#define FORWARD_WM_PAINTCLIPBOARD(hwnd, hwndCBViewer, lpPaintStruct, fn) \
    (void)(fn)((hwnd), WM_PAINTCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(LPPAINTSTRUCT)(lpPaintStruct))
#define HANDLE_WM_SIZECLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const RECT FAR*)GlobalLock((HGLOBAL)LOWORD(lParam))), GlobalUnlock((HGLOBAL)LOWORD(lParam)), 0L)
#define FORWARD_WM_SIZECLIPBOARD(hwnd, hwndCBViewer, lprc, fn) \
    (void)(fn)((hwnd), WM_SIZECLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(LPRECT)(lprc))
#define HANDLE_WM_VSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_VSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_HSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_HSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_ASKCBFORMATNAME(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (LPSTR)(lParam)), 0L)
#define FORWARD_WM_ASKCBFORMATNAME(hwnd, cchMax, rgchName, fn) \
    (void)(fn)((hwnd), WM_ASKCBFORMATNAME, (WPARAM)(int)(cchMax), (LPARAM)(rgchName))
#define HANDLE_WM_CHANGECBCHAIN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (HWND)LOWORD(lParam)), 0L)
#define FORWARD_WM_CHANGECBCHAIN(hwnd, hwndRemove, hwndNext, fn) \
    (void)(fn)((hwnd), WM_CHANGECBCHAIN, (WPARAM)(HWND)(hwndRemove), MAKELPARAM((UINT)(hwndNext), 0))
#define HANDLE_WM_SETCURSOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))
#define FORWARD_WM_SETCURSOR(hwnd, hwndCursor, codeHitTest, msg, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_SETCURSOR, (WPARAM)(HWND)(hwndCursor), MAKELPARAM((codeHitTest), (msg)))
#define HANDLE_WM_SYSCOMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)LOWORD(lParam), (int)HIWORD(lParam)), 0L)
#define FORWARD_WM_SYSCOMMAND(hwnd, cmd, x, y, fn) \
    (void)(fn)((hwnd), WM_SYSCOMMAND, (WPARAM)(UINT)(cmd), MAKELPARAM((x), (y)))
#define HANDLE_WM_MDICREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (MDICREATESTRUCT FAR*)(lParam))
#define FORWARD_WM_MDICREATE(hwnd, lpmcs, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDICREATE, 0, (LPARAM)(LPMDICREATESTRUCT)(lpmcs))
#define HANDLE_WM_MDIDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIDESTROY(hwnd, hwndDestroy, fn) \
    (void)(fn)((hwnd), WM_MDIDESTROY, (WPARAM)(hwndDestroy), 0L)
#define HANDLE_WM_MDIACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (HWND)LOWORD(lParam), (HWND)HIWORD(lParam)), 0L)
#define FORWARD_WM_MDIACTIVATE(hwnd, fActive, hwndActivate, hwndDeactivate, fn) \
    (void)(fn)(hwnd, WM_MDIACTIVATE, (WPARAM)(fActive), MAKELPARAM((hwndActivate), (hwndDeactivate)))
#define HANDLE_WM_MDIRESTORE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIRESTORE(hwnd, hwndRestore, fn) \
    (void)(fn)((hwnd), WM_MDIRESTORE, (WPARAM)(hwndRestore), 0L)
#define HANDLE_WM_MDINEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (BOOL)LOWORD(lParam)), 0L)
#define FORWARD_WM_MDINEXT(hwnd, hwndCur, fPrev, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDINEXT, (WPARAM)(hwndCur), MAKELPARAM((fPrev), 0))
#define HANDLE_WM_MDIMAXIMIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIMAXIMIZE(hwnd, hwndMaximize, fn) \
    (void)(fn)((hwnd), WM_MDIMAXIMIZE, (WPARAM)(hwndMaximize), 0L)
#define HANDLE_WM_MDITILE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_MDITILE(hwnd, cmd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_MDITILE, (WPARAM)(cmd), 0L)
#define HANDLE_WM_MDICASCADE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define FORWARD_WM_MDICASCADE(hwnd, cmd, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_MDICASCADE, (WPARAM)(cmd), 0L)
#define HANDLE_WM_MDIICONARRANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_MDIICONARRANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_MDIICONARRANGE, 0, 0L)
#define HANDLE_WM_MDIGETACTIVE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define FORWARD_WM_MDIGETACTIVE(hwnd, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDIGETACTIVE, 0, 0L)
#define HANDLE_WM_MDISETMENU(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (HMENU)LOWORD(lParam), (HMENU)HIWORD(lParam))
#define FORWARD_WM_MDISETMENU(hwnd, fRefresh, hmenuFrame, hmenuWindow, fn) \
    (HMENU)(UINT)(DWORD)(fn)((hwnd), WM_MDISETMENU, (WPARAM)(fRefresh), MAKELPARAM((hmenuFrame), (hmenuWindow)))
#define HANDLE_WM_CHILDACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_CHILDACTIVATE(hwnd, fn) \
    (void)(fn)((hwnd), WM_CHILDACTIVATE, 0, 0L)
#define HANDLE_WM_NEXTDLGCTL(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HWND)(fn)((hwnd), (HWND)(wParam), (BOOL)LOWORD(lParam))
#define FORWARD_WM_NEXTDLGCTL(hwnd, hwndSetFocus, fNext, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_NEXTDLGCTL, (WPARAM)(HWND)(hwndSetFocus), MAKELPARAM((fNext), 0))
#define HANDLE_WM_PARENTNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_PARENTNOTIFY(hwnd, msg, hwndChild, idChild, fn) \
    (void)(fn)((hwnd), WM_PARENTNOTIFY, (WPARAM)(UINT)(msg), MAKELPARAM((UINT)(HWND)(hwndChild), (UINT)(idChild)))
#define HANDLE_WM_ENTERIDLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam)), 0L)
#define FORWARD_WM_ENTERIDLE(hwnd, source, hwndSource, fn) \
    (void)(fn)((hwnd), WM_ENTERIDLE, (WPARAM)(UINT)(source), MAKELPARAM((UINT)(HWND)(hwndSource), 0))
#define HANDLE_WM_GETDLGCODE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd, (MSG FAR*)(lParam))
#define FORWARD_WM_GETDLGCODE(hwnd, lpmsg, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_GETDLGCODE, (SELECTOROF(lpmsg) ? lpmsg->wParam : 0), (LPARAM)(LPMSG)(lpmsg))
#define HANDLE_WM_CTLCOLOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)LOWORD(lParam), (int)(HIWORD(lParam)))
#define FORWARD_WM_CTLCOLOR(hwnd, hdc, hwndChild, type, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLOR, (WPARAM)(HDC)(hdc), MAKELPARAM((UINT)(HWND)(hwndChild), (UINT)(int)(type)))
#define HANDLE_WM_SETFONT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HFONT)(wParam), (BOOL)LOWORD(lParam)), 0L)
#define FORWARD_WM_SETFONT(hwnd, hfont, fRedraw, fn) \
    (void)(fn)((hwnd), WM_SETFONT, (WPARAM)(HFONT)(hfont), MAKELPARAM((UINT)(BOOL)(fRedraw), 0))
#define HANDLE_WM_GETFONT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HFONT)(fn)(hwnd)
#define FORWARD_WM_GETFONT(hwnd, fn) \
    (HFONT)(UINT)(DWORD)(fn)((hwnd), WM_GETFONT, 0, 0L)
#define HANDLE_WM_DRAWITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DRAWITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_DRAWITEM(hwnd, lpDrawItem, fn) \
    (void)(fn)((hwnd), WM_DRAWITEM, 0, (LPARAM)(const DRAWITEMSTRUCT FAR*)(lpDrawItem))
#define HANDLE_WM_MEASUREITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MEASUREITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_MEASUREITEM(hwnd, lpMeasureItem, fn) \
    (void)(fn)((hwnd), WM_MEASUREITEM, 0, (LPARAM)(MEASUREITEMSTRUCT FAR*)(lpMeasureItem))
#define HANDLE_WM_COMPAREITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (const COMPAREITEMSTRUCT FAR*)(lParam))
#define FORWARD_WM_COMPAREITEM(hwnd, lpCompareItem, fn) \
    (int)(DWORD)(fn)((hwnd), WM_COMPAREITEM, 0, (LPARAM)(const COMPAREITEMSTRUCT FAR*)(lpCompareItem))
#define HANDLE_WM_VKEYTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_VKEYTOITEM(hwnd, vk, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_VKEYTOITEM, (WPARAM)(UINT)(vk), MAKELPARAM((UINT)(hwndListBox), (UINT)(iCaret)))
#define HANDLE_WM_CHARTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)(wParam), (HWND)LOWORD(lParam), (int)HIWORD(lParam))
#define FORWARD_WM_CHARTOITEM(hwnd, ch, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_CHARTOITEM, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(hwndListBox), (UINT)(iCaret)))
#define HANDLE_WM_QUEUESYNC(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_QUEUESYNC(hwnd, fn) \
    (void)(fn)((hwnd), WM_QUEUESYNC, 0, 0L)
#define HANDLE_WM_COMMNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), LOWORD(lParam)), 0L)
#define FORWARD_WM_COMMNOTIFY(hwnd, cid, flags, fn) \
    (void)(fn)((hwnd), WM_COMMNOTIFY, (WPARAM)(cid), MAKELPARAM((flags), 0))
#define Static_SetIcon(hwndCtl, hIcon)          ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_SETICON, (WPARAM)(HICON)(hIcon), 0L))
#define Static_GetIcon(hwndCtl, hIcon)          ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_GETICON, 0, 0L))
#define Button_GetCheck(hwndCtl)            ((int)(DWORD)SendMessage((hwndCtl), BM_GETCHECK, 0, 0L))
#define Button_SetCheck(hwndCtl, check)     ((void)SendMessage((hwndCtl), BM_SETCHECK, (WPARAM)(int)(check), 0L))
#define Button_GetState(hwndCtl)            ((int)(DWORD)SendMessage((hwndCtl), BM_GETSTATE, 0, 0L))
#define Button_SetState(hwndCtl, state)     ((UINT)(DWORD)SendMessage((hwndCtl), BM_SETSTATE, (WPARAM)(int)(state), 0L))
#define Button_SetStyle(hwndCtl, style, fRedraw) ((void)SendMessage((hwndCtl), BM_SETSTYLE, (WPARAM)LOWORD(style), MAKELPARAM(((fRedraw) ? TRUE : FALSE), 0)))
#define Edit_LimitText(hwndCtl, cchMax)         ((void)SendMessage((hwndCtl), EM_LIMITTEXT, (WPARAM)(cchMax), 0L))
#define Edit_GetLineCount(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINECOUNT, 0, 0L))
#define Edit_GetLine(hwndCtl, line, lpch, cchMax) ((*((int FAR*)(lpch)) = (cchMax)), ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINE, (WPARAM)(int)(line), (LPARAM)(LPSTR)(lpch))))
#define Edit_GetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_GETRECT, 0, (LPARAM)(RECT FAR*)(lprc)))
#define Edit_SetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_SETRECT, 0, (LPARAM)(const RECT FAR*)(lprc)))
#define Edit_SetRectNoPaint(hwndCtl, lprc)      ((void)SendMessage((hwndCtl), EM_SETRECTNP, 0, (LPARAM)(const RECT FAR*)(lprc)))
#define Edit_GetSel(hwndCtl)                    ((DWORD)SendMessage((hwndCtl), EM_GETSEL, 0, 0L))
#define Edit_SetSel(hwndCtl, ichStart, ichEnd)  ((void)SendMessage((hwndCtl), EM_SETSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define Edit_ReplaceSel(hwndCtl, lpszReplace)   ((void)SendMessage((hwndCtl), EM_REPLACESEL, 0, (LPARAM)(LPCSTR)(lpszReplace)))
#define Edit_GetModify(hwndCtl)                 ((BOOL)(DWORD)SendMessage((hwndCtl), EM_GETMODIFY, 0, 0L))
#define Edit_SetModify(hwndCtl, fModified)      ((void)SendMessage((hwndCtl), EM_SETMODIFY, (WPARAM)(UINT)(fModified), 0L))
#define Edit_LineFromChar(hwndCtl, ich)         ((int)(DWORD)SendMessage((hwndCtl), EM_LINEFROMCHAR, (WPARAM)(int)(ich), 0L))
#define Edit_LineIndex(hwndCtl, line)           ((int)(DWORD)SendMessage((hwndCtl), EM_LINEINDEX, (WPARAM)(int)(line), 0L))
#define Edit_LineLength(hwndCtl, line)          ((int)(DWORD)SendMessage((hwndCtl), EM_LINELENGTH, (WPARAM)(int)(line), 0L))
#define Edit_Scroll(hwndCtl, dv, dh)            ((void)SendMessage((hwndCtl), EM_LINESCROLL, 0, MAKELPARAM((dv), (dh))))
#define Edit_CanUndo(hwndCtl)                   ((BOOL)(DWORD)SendMessage((hwndCtl), EM_CANUNDO, 0, 0L))
#define Edit_Undo(hwndCtl)                      ((BOOL)(DWORD)SendMessage((hwndCtl), EM_UNDO, 0, 0L))
#define Edit_EmptyUndoBuffer(hwndCtl)           ((void)SendMessage((hwndCtl), EM_EMPTYUNDOBUFFER, 0, 0L))
#define Edit_SetPasswordChar(hwndCtl, ch)       ((void)SendMessage((hwndCtl), EM_SETPASSWORDCHAR, (WPARAM)(UINT)(ch), 0L))
#define Edit_SetTabStops(hwndCtl, cTabs, lpTabs) ((void)SendMessage((hwndCtl), EM_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(const int FAR*)(lpTabs)))
#define Edit_FmtLines(hwndCtl, fAddEOL)         ((BOOL)(DWORD)SendMessage((hwndCtl), EM_FMTLINES, (WPARAM)(BOOL)(fAddEOL), 0L))
#define Edit_GetHandle(hwndCtl)                 ((HLOCAL)(UINT)(DWORD)SendMessage((hwndCtl), EM_GETHANDLE, 0, 0L))
#define Edit_SetHandle(hwndCtl, h)              ((void)SendMessage((hwndCtl), EM_SETHANDLE, (WPARAM)(UINT)(HLOCAL)(h), 0L))
#define Edit_GetFirstVisibleLine(hwndCtl)       ((int)(DWORD)SendMessage((hwndCtl), EM_GETFIRSTVISIBLELINE, 0, 0L))
#define Edit_SetReadOnly(hwndCtl, fReadOnly)    ((BOOL)(DWORD)SendMessage((hwndCtl), EM_SETREADONLY, (WPARAM)(BOOL)(fReadOnly), 0L))
#define Edit_GetPasswordChar(hwndCtl)           ((char)(DWORD)SendMessage((hwndCtl), EM_GETPASSWORDCHAR, 0, 0L))
#define Edit_SetWordBreakProc(hwndCtl, lpfnWordBreak) ((void)SendMessage((hwndCtl), EM_SETWORDBREAKPROC, 0, (LPARAM)(EDITWORDBREAKPROC)(lpfnWordBreak)))
#define Edit_GetWordBreakProc(hwndCtl)          ((EDITWORDBREAKPROC)SendMessage((hwndCtl), EM_GETWORDBREAKPROC, 0, 0L))
#define ListBox_GetCount(hwndCtl)                   ((int)(DWORD)SendMessage((hwndCtl), LB_GETCOUNT, 0, 0L))
#define ListBox_ResetContent(hwndCtl)               ((BOOL)(DWORD)SendMessage((hwndCtl), LB_RESETCONTENT, 0, 0L))
#define ListBox_AddString(hwndCtl, lpsz)            ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0, (LPARAM)(LPCSTR)(lpsz)))
#define ListBox_InsertString(hwndCtl, index, lpsz)  ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpsz)))
#define ListBox_AddItemData(hwndCtl, data)          ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0, (LPARAM)(data)))
#define ListBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_GetTextLen(hwndCtl, index)          ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXTLEN, (WPARAM)(int)(index), 0L))
#define ListBox_GetText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXT, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpszBuffer)))
#define ListBox_GetItemData(hwndCtl, index)         ((LRESULT)(DWORD)SendMessage((hwndCtl), LB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ListBox_SetItemData(hwndCtl, index, data)   ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_FindString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_FindItemData(hwndCtl, indexStart, data) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_SetSel(hwndCtl, fSelect, index)     ((int)(DWORD)SendMessage((hwndCtl), LB_SETSEL, (WPARAM)(BOOL)(fSelect), MAKELPARAM((index), 0)))
#define ListBox_SelItemRange(hwndCtl, fSelect, first, last)    ((int)(DWORD)SendMessage((hwndCtl), LB_SELITEMRANGE, (WPARAM)(BOOL)(fSelect), MAKELPARAM((first), (last))))
#define ListBox_GetCurSel(hwndCtl)                  ((int)(DWORD)SendMessage((hwndCtl), LB_GETCURSEL, 0, 0L))
#define ListBox_SetCurSel(hwndCtl, index)           ((int)(DWORD)SendMessage((hwndCtl), LB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ListBox_SelectString(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_SelectItemData(hwndCtl, indexStart, data)   ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_GetSel(hwndCtl, index)              ((int)(DWORD)SendMessage((hwndCtl), LB_GETSEL, (WPARAM)(int)(index), 0L))
#define ListBox_GetSelCount(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELCOUNT, 0, 0L))
#define ListBox_GetTopIndex(hwndCtl)                ((int)(DWORD)SendMessage((hwndCtl), LB_GETTOPINDEX, 0, 0L))
#define ListBox_GetSelItems(hwndCtl, cItems, lpItems) ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELITEMS, (WPARAM)(int)(cItems), (LPARAM)(int FAR*)(lpItems)))
#define ListBox_SetTopIndex(hwndCtl, indexTop)      ((int)(DWORD)SendMessage((hwndCtl), LB_SETTOPINDEX, (WPARAM)(int)(indexTop), 0L))
#define ListBox_SetColumnWidth(hwndCtl, cxColumn)   ((void)SendMessage((hwndCtl), LB_SETCOLUMNWIDTH, (WPARAM)(int)(cxColumn), 0L))
#define ListBox_GetHorizontalExtent(hwndCtl)        ((int)(DWORD)SendMessage((hwndCtl), LB_GETHORIZONTALEXTENT, 0, 0L))
#define ListBox_SetHorizontalExtent(hwndCtl, cxExtent)     ((void)SendMessage((hwndCtl), LB_SETHORIZONTALEXTENT, (WPARAM)(int)(cxExtent), 0L))
#define ListBox_SetTabStops(hwndCtl, cTabs, lpTabs) ((BOOL)(DWORD)SendMessage((hwndCtl), LB_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(int FAR*)(lpTabs)))
#define ListBox_GetItemRect(hwndCtl, index, lprc)   ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMRECT, (WPARAM)(int)(index), (LPARAM)(RECT FAR*)(lprc)))
#define ListBox_SetCaretIndex(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), LB_SETCARETINDEX, (WPARAM)(int)(index), 0L))
#define ListBox_GetCaretIndex(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), LB_GETCARETINDEX, 0, 0L))
#define ListBox_SetAnchorIndex(hwndCtl, index)      ((void)SendMessage((hwndCtl), LB_SETANCHORINDEX, (WPARAM)(int)(index), 0L))
#define ListBox_GetAnchorIndex(hwndCtl)             ((int)(DWORD)SendMessage((hwndCtl), LB_GETANCHORINDEX, 0, 0L))
#define ListBox_FindStringExact(hwndCtl, indexStart, lpszFind) ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ListBox_SetItemHeight(hwndCtl, index, cy)   ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMHEIGHT, (WPARAM)(int)(index), MAKELPARAM((cy), 0)))
#define ListBox_GetItemHeight(hwndCtl, index)       ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMHEIGHT, (WPARAM)(int)(index), 0L))
#define ListBox_Dir(hwndCtl, attrs, lpszFileSpec)   ((int)(DWORD)SendMessage((hwndCtl), LB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCSTR)(lpszFileSpec)))
#define ListBox_AddFile(hwndCtl, lpszFilename)      ((int)(DWORD)SendMessage((hwndCtl), LB_ADDFILE, 0, (LPARAM)(LPCSTR)(lpszFilename)))    /* ;Internal */
#define ComboBox_Enable(hwndCtl, fEnable)       EnableWindow((hwndCtl), (fEnable))
#define ComboBox_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))
#define ComboBox_GetTextLength(hwndCtl)         GetWindowTextLength(hwndCtl)
#define ComboBox_SetText(hwndCtl, lpsz)         SetWindowText((hwndCtl), (lpsz))
#define ComboBox_LimitText(hwndCtl, cchLimit)   ((int)(DWORD)SendMessage((hwndCtl), CB_LIMITTEXT, (WPARAM)(int)(cchLimit), 0L))
#define ComboBox_GetEditSel(hwndCtl)            ((DWORD)SendMessage((hwndCtl), CB_GETEDITSEL, 0, 0L))
#define ComboBox_SetEditSel(hwndCtl, ichStart, ichEnd) ((int)(DWORD)SendMessage((hwndCtl), CB_SETEDITSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define ComboBox_GetCount(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), CB_GETCOUNT, 0, 0L))
#define ComboBox_ResetContent(hwndCtl)          ((int)(DWORD)SendMessage((hwndCtl), CB_RESETCONTENT, 0, 0L))
#define ComboBox_AddString(hwndCtl, lpsz)       ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_InsertString(hwndCtl, index, lpsz) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_AddItemData(hwndCtl, data)     ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(data)))
#define ComboBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_GetLBTextLen(hwndCtl, index)           ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXTLEN, (WPARAM)(int)(index), 0L))
#define ComboBox_GetLBText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXT, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpszBuffer)))
#define ComboBox_GetItemData(hwndCtl, index)        ((LRESULT)(DWORD)SendMessage((hwndCtl), CB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ComboBox_SetItemData(hwndCtl, index, data)  ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_FindString(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ComboBox_FindItemData(hwndCtl, indexStart, data)    ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_GetCurSel(hwndCtl)                 ((int)(DWORD)SendMessage((hwndCtl), CB_GETCURSEL, 0, 0L))
#define ComboBox_SetCurSel(hwndCtl, index)          ((int)(DWORD)SendMessage((hwndCtl), CB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ComboBox_SelectString(hwndCtl, indexStart, lpszSelect)  ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszSelect)))
#define ComboBox_SelectItemData(hwndCtl, indexStart, data)      ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_Dir(hwndCtl, attrs, lpszFileSpec)  ((int)(DWORD)SendMessage((hwndCtl), CB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCSTR)(lpszFileSpec)))
#define ComboBox_ShowDropdown(hwndCtl, fShow)       ((BOOL)(DWORD)SendMessage((hwndCtl), CB_SHOWDROPDOWN, (WPARAM)(BOOL)(fShow), 0L))
#define ComboBox_FindStringExact(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCSTR)(lpszFind)))
#define ComboBox_GetDroppedState(hwndCtl)           ((BOOL)(DWORD)SendMessage((hwndCtl), CB_GETDROPPEDSTATE, 0, 0L))
#define ComboBox_GetDroppedControlRect(hwndCtl, lprc) ((void)SendMessage((hwndCtl), CB_GETDROPPEDCONTROLRECT, 0, (LPARAM)(RECT FAR*)(lprc)))
#define ComboBox_GetItemHeight(hwndCtl)             ((int)(DWORD)SendMessage((hwndCtl), CB_GETITEMHEIGHT, 0, 0L))
#define ComboBox_SetItemHeight(hwndCtl, cyItem)     ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMHEIGHT, (WPARAM)(int)(index), (LPARAM)(int)cyItem))
#define ComboBox_GetExtendedUI(hwndCtl)             ((UINT)(DWORD)SendMessage((hwndCtl), CB_GETEXTENDEDUI, 0, 0L))
#define ComboBox_SetExtendedUI(hwndCtl, flags)      ((int)(DWORD)SendMessage((hwndCtl), CB_SETEXTENDEDUI, (WPARAM)(UINT)(flags), 0L))
#define GET_WM_ACTIVATE_HWND(wp, lp)            ((HWND)LOWORD(lp))
#define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)      \
        (WPARAM)(s), (LPARAM)MAKELONG(hwnd, fmin)
#define GET_WM_CHARTOITEM_HWND(wp, lp)          LOWORD(lp)
#define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd)    \
        (WPARAM)ch, (LPARAM)MAKELONG(hwnd, pos)
#define GET_WM_COMMAND_ID(wp, lp)               (wp)
#define GET_WM_COMMAND_HWND(wp, lp)             (HWND)(LOWORD(lp))
#define GET_WM_COMMAND_MPS(id, hwnd, cmd)    \
        (WPARAM)id, MAKELONG(hwnd, cmd)
#define GET_WM_CTLCOLOR_HWND(wp, lp, msg)       (HWND)(LOWORD(lp))
#define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type) \
        (WPARAM)(hdc), (LPARAM)MAKELONG(hwnd, type)
#define GET_WM_MENUSELECT_CMD(wp, lp)               (wp)
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (wp)
#define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
#define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
        (WPARAM)(hwndA), 0
#define GET_WM_PARENTNOTIFY_MSG(wp, lp)             (wp)
#define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)       (HWND)LOWORD(lp)
#define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd) \
        (WPARAM)msg, (LPARAM)MAKELONG(hwnd, id)
#define GET_WM_VKEYTOITEM_CODE(wp, lp)              (wp)
#define GET_WM_VKEYTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
#define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) \
        (WPARAM)code, (LPARAM)MAKELONG(hwnd, item)
#define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)       (HWND)LOWORD(lp)
#define GET_WM_HSCROLL_CODE(wp, lp)                 (wp)
#define GET_WM_HSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
#define GET_WM_HSCROLL_MPS(code, pos, hwnd)    \
        (WPARAM)code, (LPARAM)MAKELONG(pos, hwnd)
#define GET_WM_VSCROLL_CODE(wp, lp)                 (wp)
#define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
#define GET_WM_VSCROLL_MPS(code, pos, hwnd)    \
        (WPARAM)code, (LPARAM)MAKELONG(pos, hwnd)

// tools\x86\perl\lib\core\regcomp.h
#define SIZE_ONLY (PL_regcode == &PL_regdummy)

// windows\advcore\ctf\aimm1.2\inc\imeapp.h
#define VERSION_ID_IMEJP98  (VERSION_ID_JAPANESE | 0x980)
#define VERSION_ID_IMEJP98A (VERSION_ID_JAPANESE | 0x98a)

// windows\advcore\ctf\aimm1.2\win32\a_wrappers.cpp
#define IsAIMM() (ptls && ptls->pAImm)

// windows\advcore\ctf\cuilib\cuiobj.h
#define UIWNDFRAME_RESIZEALL        (UIWNDFRAME_RESIZELEFT | UIWNDFRAME_RESIZETOP | UIWNDFRAME_RESIZERIGHT | UIWNDFRAME_RESIZEBOTTOM)

// windows\advcore\ctf\cuilib\cuischem.h
#define UIFDCF_BUTTON                       (UIFDCF_FLATONNORMAL | UIFDCF_RAISEDONMOUSEOVER | UIFDCF_RAISEDONMOUSEDOWN | UIFDCF_RAISEDONSELECT)
#define UIFDCF_BUTTONSUNKEN                 (UIFDCF_RAISEDONNORMAL | UIFDCF_RAISEDONMOUSEOVER | UIFDCF_SUNKENONMOUSEDOWN | UIFDCF_SUNKENONSELECT)
#define UIFDCF_CAPTIONBUTTON                (UIFDCF_RAISEDONNORMAL | UIFDCF_RAISEDONMOUSEOVER | UIFDCF_SUNKENONMOUSEDOWN | UIFDCF_SUNKENONSELECT)
#define UIFDCS_MOUSEOVERSELECTED            (UIFDCS_MOUSEOVER | UIFDCS_SELECTED)
#define UIFDCS_MOUSEDOWNSELECTED            (UIFDCS_MOUSEDOWN | UIFDCS_SELECTED)
#define UIFDCS_DISABLEDSELECTED             (UIFDCS_DISABLED  | UIFDCS_SELECTED)
#define UIFDCS_MOUSEOVERDISABLED            (UIFDCS_MOUSEOVER | UIFDCS_DISABLED)
#define UIFDCS_MOUSEOVERDISABLEDSELECTED    (UIFDCS_MOUSEOVER | UIFDCS_DISABLED | UIFDCS_SELECTED)

// windows\advcore\ctf\inc\aimmver.h
#define VER_PRODUCTVERSION_DW		(0x01000000 | VER_PRODUCTBUILD)

// windows\advcore\ctf\inc\ccstock.h
#define IS_WINDOW_RTL_MIRRORED(hwnd)    (g_bMirroredOS && Mirror_IsWindowMirroredRTL(hwnd))
#define GET_PROCESS_DEF_LAYOUT(pdwl)    (g_bMirroredOS && Mirror_GetProcessDefaultLayout(pdwl))

// windows\advcore\ctf\inc\msime.h
#define VERSION_ID_IMEJP98  (VERSION_ID_JAPANESE | 0x980)
#define VERSION_ID_IMEJP2000 (VERSION_ID_JAPANESE | 0x98a)

// windows\advcore\ctf\inc\osver.h
#define IsOnNT()       (g_dwOsVer & OSVER_ONNT)
#define IsOnNT5()      (g_dwOsVer & OSVER_ONNT5)
#define IsOn95()       (g_dwOsVer & OSVER_ON95)
#define IsOn98()       (g_dwOsVer & OSVER_ON98)
#define IsOn98orNT5()  (g_dwOsVer & (OSVER_ON98 | OSVER_ONNT5))
#define IsOnFE()       (g_dwOsVer & OSVER_ONFE)
#define IsOnImm()      (g_dwOsVer & OSVER_ONIMM)
#define IsOnDBCS()     (g_dwOsVer & OSVER_ONDBCS)
#define IsOnNT51()     (g_dwOsVer & OSVER_ONNT51)

// windows\advcore\ctf\inputdll\inputdlg.h
#define LANG_OAC             (LANG_ORIGACTIVE | LANG_ACTIVE | LANG_CHANGED)

// windows\advcore\ctf\uim\hotkey.cpp
#define IsAlt(u)     ((u & TF_MOD_ALT) ? 1 : 0)
#define IsControl(u) ((u & TF_MOD_CONTROL) ? 1 : 0)
#define IsWin(u)     ((u & TF_MOD_WIN) ? 1 : 0)

// windows\advcore\ctf\uim\hotkey.h
#define TF_MOD_ALLALT     (TF_MOD_RALT | TF_MOD_LALT | TF_MOD_ALT)
#define TF_MOD_ALLCONTROL (TF_MOD_RCONTROL | TF_MOD_LCONTROL | TF_MOD_CONTROL)
#define TF_MOD_RLALT     (TF_MOD_RALT | TF_MOD_LALT)
#define TF_MOD_RLCONTROL (TF_MOD_RCONTROL | TF_MOD_LCONTROL)
#define TF_MOD_RLWIN   (TF_MOD_RWIN | TF_MOD_LWIN)

// windows\advcore\ctf\uim\ic.h
#define TF_ES_WRITE                  (TF_ES_READWRITE & ~TF_ES_READ)
#define TF_ES_PROPERTY_WRITE         (TF_ES_READ_PROPERTY_WRITE & ~TF_ES_READ)

// windows\advcore\ctf\uim\marshal.cpp
#define WRM_MARSHALWNDDISPATCH (WRM_DISPATCH | WRM_MARSHALWND)

// windows\advcore\ctf\uim\marshal.h
#define QS_ALLINPUT400  (QS_ALLINPUT & ~QS_RAWINPUT)
#define MPARAM_IN_INTERFACE       (MPARAM_IN | MPARAM_INTERFACE)
#define MPARAM_OUT_INTERFACE      (MPARAM_OUT | MPARAM_INTERFACE)
#define MPARAM_IN_OUT_INTERFACE   (MPARAM_IN | MPARAM_OUT | MPARAM_INTERFACE)

// windows\advcore\ctf\uim\tsi.cpp
#define TS_LF_WRITE (TS_LF_READWRITE & ~TS_LF_READ)

// windows\advcore\duser\engine\msg\msgobject.h
#define DECLARE_INTERNAL(name) \
    static HCLASS CALLBACK \
    Demote##name(HCLASS hclCur, DUser::Gadget * pgad, void * pvData) \
    { \
        return DemoteInternal(hclCur, pgad, pvData); \
    } \
    \
    static void MarkInternal() \
    { \
        GetClassLibrary()->MarkInternal(s_mc.hclNew); \
    } \

// windows\advcore\duser\inc\autoutil.h
#define SUPPRESS(ClassName) \
private: \
ClassName(const ClassName & copy); \
ClassName & operator=(const ClassName & rhs); \
public:

// windows\advcore\gdiplus\engine\flat\gpverp.h
#define VER_PRODUCTVERSION_DW       (0x05010000 | VER_PRODUCTBUILD)

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\fd.h
#define BLTOF16_16OK(l)  (((l) < 0x00007fff) && ((l) > -0x00007fff))
#define B28_4TO16_16OK(X) (((X) < 0x0007ffff) && ((X) > -0x0007ffff))
#define B26_6TO16_16OK(X) (((X) < 0x003fffff) && ((X) > -0x003fffff))

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\tt.h
#define  CV_LANG_ID(ui16PlatformID, Id)                               \
(                                                                     \
(ui16PlatformID == BE_PLAT_ID_MS) ? (Id) : ui16Mac2Lang((uint16)(Id)) \
)

// windows\advcore\gdiplus\engine\imaging\jpeg\libjpeg\jmemdos.c
#define ODD(X)	(((X) & 1L) != 0)

// windows\advcore\gdiplus\engine\imaging\jpeg\libjpeg\jmorecfg.h
#define GETJSAMPLE(value)  ((int) (value) & 0xFF)
#define GETJOCTET(value)  ((value) & 0xFF)

// windows\advcore\gdiplus\engine\imaging\jpeg\libjpeg\rdbmp.c
#define UCH(x)	((int) (x) & 0xFF)

// windows\advcore\gdiplus\engine\imaging\jpeg\libjpeg\rdppm.c
#define UCH(x)	((int) (x) & 0xFF)

// windows\advcore\gdiplus\engine\imaging\jpeg\libjpeg\rdtarga.c
#define UCH(x)	((int) (x) & 0xFF)

// windows\advcore\gdiplus\engine\imaging\png\libpng\spngconf.h
#define FPNGCRITICAL(c) (((c) & PNGCHUNK(0x20,0,0,0)) == 0)

// windows\advcore\gdiplus\engine\imaging\png\libpng\spngdeinterlace.cpp
#define B_(u) ((u)&0xffU)

// windows\advcore\gdiplus\engine\imaging\png\libpng\spngthousands.cpp
#define B8(b5) B8_( (b5) & 0x1F )

// windows\advcore\gdiplus\engine\imaging\png\zlib\deflate.h
# define _tr_tally_lit(s, c, flush) \
  { uch cc = (uch)(c); \
    s->d_buf[s->last_lit] = 0; \
    s->l_buf[s->last_lit++] = cc; \
    s->dyn_ltree[cc].Freq++; \
    flush = (s->last_lit == s->lit_bufsize-1); \
   }
# define _tr_tally_dist(s, distance, length, flush) \
  { uch len = (uch)(length); \
    ush dist = (ush)(distance); \
    s->d_buf[s->last_lit] = dist; \
    s->l_buf[s->last_lit++] = len; \
    dist--; \
    s->dyn_ltree[_length_code[len]+LITERALS+1].Freq++; \
    s->dyn_dtree[d_code(dist)].Freq++; \
    flush = (s->last_lit == s->lit_bufsize-1); \
  }

// windows\advcore\gdiplus\engine\imaging\png\zlib\infutil.h
#define WRAP {if(q==s->end&&s->read!=s->window){q=s->window;m=(uInt)WAVAIL;}}

// windows\advcore\gdiplus\engine\imaging\png\zlib\office.h
		#define isgraph(c) (((c) & 0x7f) > 0x20)

// windows\advcore\gdiplus\engine\imaging\png\zlib\trees.c
#  define SEPARATOR(i, last, width) \
      ((i) == (last)? "\n};\n\n" :    \
       ((i) % (width) == (width)-1 ? ",\n" : ", "))
#define pqremove(s, tree, top) \
{\
    top = s->heap[SMALLEST]; \
    s->heap[SMALLEST] = s->heap[s->heap_len--]; \
    pqdownheap(s, tree, SMALLEST); \
}
#define smaller(tree, n, m, depth) \
   (tree[n].Freq < tree[m].Freq || \
   (tree[n].Freq == tree[m].Freq && depth[n] <= depth[m]))

// windows\advcore\rcml\rcml\quickref.h
#define DEFINE_QUICKREF(ClassName) \
typedef CQuickRef<ClassName> ClassName##Ref; \
typedef CQuickRef<const ClassName> ClassName##CRef

// windows\advcore\rcml\rcml\shlwapi.h
#define UrlEscapeSpaces(pszUrl, pszEscaped, pcchEscaped)        UrlCanonicalize(pszUrl, pszEscaped, pcchEscaped, URL_ESCAPE_SPACES_ONLY |URL_DONT_ESCAPE_EXTRA_INFO )
#define SHACF_DEFAULT                   0x00000000  // Currently (SHACF_FILESYSTEM | SHACF_URLALL)

// windows\advcore\rcml\rcml\xmlcaption.cpp
#define PROPERTY(p,id, def) m_Style |= YesNo( id , def )?p:0;

// windows\advcore\rcml\rcml\xmldlg.cpp
#define PROPERTY(p,id, def) m_Style |= pNode->YesNo( id , def )?p:0;

// windows\advcore\rcml\rcml\xmllistview.cpp
#define ListView_SetCheckState(hwndLV, i, fCheck) \
  ListView_SetItemState(hwndLV, i, INDEXTOSTATEIMAGEMASK((fCheck)?2:1), LVIS_STATEIMAGEMASK)

// windows\core\dxkernel\inc\dxg.h
#define DxEngGetRedirectionBitmap(hWnd) \
                                   ((HBITMAP)(CALL_DXENG(GetRedirectionBitmap)(hWnd)))

// windows\core\ntcon\inc\conime.h
#define CONIME_CREATE                   (WM_USER+0)
#define CONIME_SETFOCUS                 (WM_USER+2)
#define CONIME_KILLFOCUS                (WM_USER+3)
#define CONIME_HOTKEY                   (WM_USER+4)
#define CONIME_GET_NLSMODE              (WM_USER+5)
#define CONIME_NOTIFY_VK_KANA           (WM_USER+8)
#define CONIME_INPUTLANGCHANGE          (WM_USER+9)
#define CONIME_INPUTLANGCHANGEREQUEST   (WM_USER+11)
#define CONIME_INPUTLANGCHANGEREQUESTFORWARD   (WM_USER+12)
#define CONIME_INPUTLANGCHANGEREQUESTBACKWARD   (WM_USER+13)
#define CONIME_KEYDATA                  (WM_USER+1024)
#define CM_CONIME_KL_ACTIVATE           (WM_USER+15)

// windows\core\ntcon\inc\font.h
#define SIZE_EQUAL(s1, s2)   (((s1).X == (s2).X) && ((s1).Y == (s2).Y))

// windows\core\ntcon\inc\output.h
#define CONSOLE_WINDOW_SIZE_X(SCREEN) (WINDOW_SIZE_X(&(SCREEN)->Window))
#define CONSOLE_WINDOW_SIZE_Y(SCREEN) (WINDOW_SIZE_Y(&(SCREEN)->Window))

// windows\core\ntcon\inc\server.h
#define SCROLL_BAR_CHANGE (ADD_SCROLL_BARS_X | REMOVE_SCROLL_BARS_X | ADD_SCROLL_BARS_Y | REMOVE_SCROLL_BARS_Y | RESIZE_SCROLL_BARS)
#define INPUT_MODES (ENABLE_LINE_INPUT | ENABLE_PROCESSED_INPUT | ENABLE_ECHO_INPUT | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT)
#define OUTPUT_MODES (ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT)
#define CM_CREATE_CONSOLE_WINDOW (WM_USER+0)
#define CM_BEEP                  (WM_USER+3)
#define CM_UPDATE_SCROLL_BARS    (WM_USER+4)
#define CM_UPDATE_TITLE          (WM_USER+5)
#define CM_CONSOLE_SHUTDOWN      (WM_USER+7)
#define CM_CONIME_CREATE         (WM_USER+9)
#define CM_WAIT_CONIME_PROCESS   (WM_USER+11)
#define CM_GET_NLSMODE           (WM_USER+14)
#define CM_CONIME_KL_ACTIVATE    (WM_USER+15)
#define CM_CONSOLE_MSG           (WM_USER+16)
#define CM_CONSOLE_INPUT_THREAD_MSG (WM_USER+17)
#define CONSOLE_CLIENTPROCESSHANDLE() \
    ((CSR_SERVER_QUERYCLIENTTHREAD())->Process->ProcessHandle)
#define CONSOLE_CLIENTPROCESSID() \
    ((CSR_SERVER_QUERYCLIENTTHREAD())->Process->ClientId.UniqueProcess)
#define CONSOLE_FROMPROCESSPROCESSHANDLE(pcsrprocess) \
                                               ((pcsrprocess)->ProcessHandle)
#define CONSOLE_FROMPROCESSPERPROCESSDATA(pcsrprocess) \
    ((pcsrprocess)->ServerDllPerProcessData[CONSRV_SERVERDLL_INDEX])
#define CONSOLE_FROMTHREADPERPROCESSDATA(pcsrthread) \
    CONSOLE_FROMPROCESSPERPROCESSDATA((pcsrthread)->Process)

// windows\core\ntcon\server\cmdline.c
#define ALT_PRESSED     (RIGHT_ALT_PRESSED | LEFT_ALT_PRESSED)
#define CTRL_PRESSED    (RIGHT_CTRL_PRESSED | LEFT_CTRL_PRESSED)
#define CTRL_BUT_NOT_ALT(n) \
        (((n) & (LEFT_CTRL_PRESSED | RIGHT_CTRL_PRESSED)) && \
        !((n) & (LEFT_ALT_PRESSED | RIGHT_ALT_PRESSED)))

// windows\core\ntcon\server\input.c
#define CTRL_BUT_NOT_ALT(n) \
        (((n) & (LEFT_CTRL_PRESSED | RIGHT_CTRL_PRESSED)) && \
        !((n) & (LEFT_ALT_PRESSED | RIGHT_ALT_PRESSED)))

// windows\core\ntcon\server\private.c
#define PAL_CYAN        (PAL_GREEN | PAL_BLUE)
#define PAL_MAGENTA     (PAL_BLUE | PAL_RED)

// windows\core\ntgdi\client\csxobj.cxx
#define bIsIdentity(fl) ((fl & (XFORM_UNITY | XFORM_NO_TRANSLATION)) == \
                               (XFORM_UNITY | XFORM_NO_TRANSLATION))

// windows\core\ntgdi\client\csxobj.hxx
#define XFORM_FORMAT  (XFORM_FORMAT_LTOFX|XFORM_FORMAT_FXTOL|XFORM_FORMAT_LTOL)

// windows\core\ntgdi\client\d3d.c
#define DDS_HANDLE(lpDDSLcl) \
    ((HANDLE)(lpDDSLcl->hDDSurface))

// windows\core\ntgdi\client\dcquery.c
#define GCW_WIN3_INT   (GCW_WIN3 | GCW_INT)

// windows\core\ntgdi\client\gdiicm.h
#define ICM_IN_USE                   (ICM_UNDER_INITIALIZING|ICM_UNDER_CHANGING)

// windows\core\ntgdi\client\ldc.c
#define MIRRORED_DC(pDcAttr)     (pDcAttr->dwLayout & LAYOUT_RTL)

// windows\core\ntgdi\client\mfrec.cxx
#define STOCK_IMHE(imhe)                                             \
        (                                                            \
            ((imhe) & ENHMETA_STOCK_OBJECT) &&                       \
            (((imhe) & ~ENHMETA_STOCK_OBJECT) <= PRIV_STOCK_LAST)    \
        )

// windows\core\ntgdi\client\xform.c
#define MIRROR_WINDOW_ORG(hdc, pdcAttr)                 \
{                                                       \
    if (pdcAttr->dwLayout & LAYOUT_RTL) {               \
        NtGdiMirrorWindowOrg(hdc);                      \
    }                                                   \
}
#define MIRROR_X(pdcAttr, x)                            \
{                                                       \
    if (pdcAttr->dwLayout & LAYOUT_RTL)                 \
        x = -x;                                         \
}

// windows\core\ntgdi\fondrv\bmfd\cvt.h
#define ISIMULATE(x)                                 \
                                                     \
        (x) == 0 ?                                   \
            FC_SIM_NONE :                            \
            (                                        \
                (x) == FO_SIM_BOLD ?            \
                    FC_SIM_BOLD :                    \
                    (                                \
                        (x) == FO_SIM_ITALIC ?  \
                            FC_SIMULATE_ITALIC :     \
                            FC_SIMULATE_BOLDITALIC   \
                    )                                \
            )
#define bIsZero(ef)     ( ((ef).lMant == 0) && ((ef).lExp == 0) )

// windows\core\ntgdi\fondrv\tt\mssipotf\fs\fontmath.c
#define ISNOTPOWEROF2(n)        ((n) & ((n)-1))

// windows\core\ntgdi\fondrv\tt\mssipotf\fs\fsglue.c
#define NotSameKnot(a,b) ((a).x != (b).x || (a).y != (b).y)

// windows\core\ntgdi\fondrv\tt\mssipotf\fs\interp.c
#define RTDG(x,engine,resolution)	\
	if (x >= 0) {					\
		x += engine;				\
		x += resolution / 4;		\
		x &= ~(resolution / 2 - 1);	\
	} else {						\
		x = -x;						\
		x += engine;				\
		x += resolution / 4;		\
		x &= ~(resolution / 2 - 1);	\
		x = -x;						\
	}
#define RDTG(x,engine,resolution)	\
	if (x >= 0) {					\
		x += engine;				\
		x &= ~(resolution - 1);		\
	} else {						\
		x = -x;						\
		x += engine;				\
		x &= ~(resolution - 1);		\
		x = -x;						\
	}
#define RUTG(x,engine,resolution)	\
	if (x >= 0) {					\
		x += engine;				\
		x += resolution - 1;		\
		x &= ~(resolution - 1);		\
	} else {						\
		x = -x;						\
		x += engine;				\
		x += resolution - 1;		\
		x &= ~(resolution - 1);		\
		x = -x;						\
	}
#define RTG(x,engine,resolution)	\
	if (x >= 0) {					\
		x += engine;				\
		x += resolution / 2;		\
		x &= ~(resolution - 1);		\
	} else {						\
		x = -x;						\
		x += engine;				\
		x += resolution / 2;		\
		x &= ~(resolution - 1);		\
		x = -x;						\
	}
#define RTHG(x,engine,resolution)	\
	if (x >= 0) {					\
		x += engine;				\
		x &= ~(resolution - 1);		\
		x += resolution / 2;		\
	} else {						\
		x = -x;						\
		x += engine;				\
		x &= ~(resolution - 1);		\
		x += resolution / 2;		\
		x = -x;						\
	}
#define ROFF(x,engine,resolution)	\
	if (x >= 0) {					\
		x += engine;				\
	} else {						\
		x -= engine;				\
	}

// windows\core\ntgdi\fondrv\tt\ttfd\fd.h
#define BLTOF16_16OK(l)  (((l) < 0x00007fff) && ((l) > -0x00007fff))
#define B28_4TO16_16OK(X) (((X) < 0x0007ffff) && ((X) > -0x0007ffff))
#define B26_6TO16_16OK(X) (((X) < 0x003fffff) && ((X) > -0x003fffff))

// windows\core\ntgdi\fondrv\tt\ttfd\tt.h
#define  CV_LANG_ID(ui16PlatformID, Id)                               \
(                                                                     \
(ui16PlatformID == BE_PLAT_ID_MS) ? (Id) : ui16Mac2Lang((uint16)(Id)) \
)

// windows\core\ntgdi\fondrv\vtfd\service.h
#define bIsZero(ef)         ((ef.lMant == 0) && (ef.lExp == 0))

// windows\core\ntgdi\gre\dcobj.hxx
#define MIRRORED_DC(pdc)                 (pdc->dwLayout() & LAYOUT_RTL)

// windows\core\ntgdi\gre\dda.hxx
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// windows\core\ntgdi\gre\draweng.hxx
#define OCTANT_2        (NEGATE_X | SWITCH_X_AND_Y)
#define OCTANT_4        (NEGATE_X | NEGATE_Y)
#define OCTANT_5        (NEGATE_X | NEGATE_Y | SWITCH_X_AND_Y)
#define OCTANT_6        (NEGATE_Y | SWITCH_X_AND_Y)

// windows\core\ntgdi\gre\engine.h
#define AVEC_NEED_SOURCE  (AVEC_S | AVEC_DS | AVEC_SP | AVEC_DSP)
#define AVEC_NEED_PATTERN (AVEC_P | AVEC_DP | AVEC_SP | AVEC_DSP)
#define GreSuspendWatch(ppdev, n)                                               \
{                                                                               \
    if ((ppdev)->pWatchdogData)                                                 \
    {                                                                           \
        WdSuspendDeferredWatch((ppdev)->pWatchdogData[n].pWatchdog);            \
    }                                                                           \
}
#define GreResumeWatch(ppdev, n)                                                \
{                                                                               \
    if ((ppdev)->pWatchdogData)                                                 \
    {                                                                           \
        WdResumeDeferredWatch((ppdev)->pWatchdogData[n].pWatchdog, TRUE);       \
    }                                                                           \
}

// windows\core\ntgdi\gre\equad.hxx
#define DIVREM(u64,u32,pul) \
    RtlEnlargedUnsignedDivide(*(ULARGE_INTEGER*) &(u64), (u32), (pul))

// windows\core\ntgdi\gre\ifiobj.hxx
#define BCONTINUOUSSCALING(x)                    \
   ((x) & (                                      \
            FM_INFO_ARB_XFORMS                   \
          | FM_INFO_ISOTROPIC_SCALING_ONLY       \
          | FM_INFO_ANISOTROPIC_SCALING_ONLY))
#define BARBXFORMS(x) ((x) & FM_INFO_ARB_XFORMS)

// windows\core\ntgdi\gre\rleblt.h
#define bIsOdd(x) ((x) & 1)
#define RLE_SourceExhausted(Count)                                           \
    ((ulSrcIndex += (Count)) > ulSrcLength)

// windows\core\ntgdi\gre\rotate.hxx
#define DDA(d,i)		\
    (d)->lQuo += (i)->dt.lQuo;	\
    (d)->lRem += (i)->dt.lRem;	\
    if ((d)->lRem >= (i)->lDen) \
    {				\
	(d)->lQuo += 1; 	\
	(d)->lRem -= (i)->lDen; \
    }

// windows\core\ntgdi\gre\ttgdi.cxx
#define B_ONE(e)  (((e).value == 1) &&  ((e).fract == 0))
#define B_ZERO(e) (((e).value == 0) &&  ((e).fract == 0))

// windows\core\ntgdi\gre\xformobj.hxx
#define XFORM_FORMAT  (XFORM_FORMAT_LTOFX|XFORM_FORMAT_FXTOL|XFORM_FORMAT_LTOL)
#define BLTOFXOK(x)         (((x) < 0x07FFFFFF) && ((x) > -0x07FFFFFF))

// windows\core\ntgdi\halftone\ht\htmath.h
#define SquareRoot(x)   RaisePower((FD6)(x), (FD6)2, RPF_RADICAL | RPF_INTEXP)
#define CubeRoot(x)     RaisePower((FD6)(x), (FD6)3, RPF_RADICAL | RPF_INTEXP)
#define CIE_L2I(L)      (((L) > (FD6)79996) ?                               \
                            Cube(DivFD6((L) + (FD6)160000, (FD6)1160000)) : \
                            DivFD6((L), (FD6)9033000))
#define CIE_y3I2L(Y,y3) (((Y) > (FD6)8856) ?                                \
                            MulFD6((y3),(FD6)1160000) - (FD6)160000  :      \
                            MulFD6((Y), (FD6)9033000))

// windows\core\ntgdi\halftone\ht\htsetbmp.c
#define bm8i    (*(PBM8BPPINFO)&ExtBGR[3])
#define bm8i    (*(PBM8BPPINFO)&ExtBGR[3])

// windows\core\ntgdi\icm\mscms\sti.h
#define IStiDevice_Release(p)                   (p)->lpVtbl->Release(p)

// windows\core\ntgdi\inc\hmgshare.h
#define REQ_ICM_MODE(x)       ((x) & 0x00000F00)
#define DEC_CFONT_REF(pcf)  {if (!((pcf)->fl & CFONT_PUBLIC)) --(pcf)->cRef;}

// windows\core\ntgdi\kdexts2\output.hxx
#define PARSE_OUTPUT_DEFAULT    (PARSE_OUTPUT_DISCARD | PARSE_OUTPUT_UNPARSED)
#define OUTFILTER_REPLACE_ALL_INSTANCES     (OUTFILTER_REPLACE_EVERY | OUTFILTER_QUERY_EVERY_LINE)
#define OUTFILTER_REPLACE_ONCE_PER_LINE     (OUTFILTER_REPLACE_ONCE  | OUTFILTER_QUERY_EVERY_LINE)
#define OUTFILTER_REPLACE_EXACTLY_ONCE      (OUTFILTER_REPLACE_ONCE  | OUTFILTER_QUERY_ONE_LINE)
#define OUTFILTER_FINDMATCH_DEFAULT     (OUTFILTER_FINDMATCH_ANYWHERE | OUTFILTER_FINDMATCH_MARK)

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\filenew.cpp
#define IsVisible(_hwnd)     (GetWindowLong(_hwnd, GWL_STYLE) & WS_VISIBLE)

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\font.c
#define GDI_FONTTYPE_STUFF (RASTER_FONTTYPE | DEVICE_FONTTYPE | TRUETYPE_FONTTYPE)

// windows\core\ntgdi\test\gdibench\gdibench.c
#define SUBITEM(fmt, v) \
                sprintf(szT, fmt, v); \
                ListView_SetItemText(hwndList, lvl.iItem, ++lvl.iSubItem, szT);

// windows\core\ntgdi\test\icmview\child.h
#define GetCurrentMDIWnd() (HWND)(SendMessage(ghWndMDIClient, WM_MDIGETACTIVE, 0, 0L))

// windows\core\ntgdi\test\icmview\icmview.h
#define SUPPORT_GAMMA_RAMPS(hDC) (BOOL)((GetDeviceCaps(hDC, CAPS1) & C1_GAMMA_RAMP) != 0)

// windows\core\ntgdi\test\imgtest\disp.cxx
#define DISP_SUBITEM(fmt, v)                                                     \
                sprintf(szT, fmt, v);                                            \
                ListView_SetItemText(hwndList, lvl.iItem, ++lvl.iSubItem, szT);

// windows\core\ntuser\client\connect.c
#define ORPATH(x) path |= x;

// windows\core\ntuser\client\crecv.c
#define PCALLDATA(x) (&(pmsg->x))

// windows\core\ntuser\client\mdiwin.c
#define SBJ_BOTH  (SBJ_HORZ | SBJ_VERT)

// windows\core\ntuser\client\usercli.h
#define MIRRORED_HDC(hdc)     (GetLayout(hdc) & LAYOUT_RTL)
#define MIRRORED_HWND(hwnd)   (GetWindowLong(hwnd, GWL_EXSTYLE) & WS_EX_LAYOUTRTL)
#define CsSendMessage(hwnd, msg, wParam, lParam, xParam, pfn, bAnsi) \
        (((msg) >= WM_USER) ? \
            NtUserMessageCall(hwnd, msg, wParam, lParam, xParam, pfn, bAnsi) : \
            gapfnScSendMessage[MessageTable[msg].iFunction](hwnd, msg, wParam, lParam, xParam, pfn, bAnsi))
#define IsLBoxVisible(plb)  (plb->fRedraw && IsVisible(plb->spwnd))
#define ISDELIMETERA(ch) ((ch == ' ') || (ch == '\t'))
#define ISDELIMETERW(ch) ((ch == L' ') || (ch == L'\t'))
#define MESSAGEPROTO(func) \
LRESULT CALLBACK fn ## func(                               \
        HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, \
        ULONG_PTR xParam, DWORD xpfnWndProc, BOOL bAnsi)
#define IsHooked(pci, fsHook) \
    ((fsHook & (pci->fsHooks | pci->pDeskInfo->fsHooks)) != 0)
#define GetDispatchDbcsInfo()          (&(GetClientInfo()->achDbcsCF[0]))
#define GetForwardDbcsInfo()           (&(GetClientInfo()->achDbcsCF[1]))
#define BUILD_DBCS_MESSAGE_TO_CLIENTA_FROM_CLIENTW(_hwnd,_msg,_wParam,_lParam,_time,_pt,_bDbcs) \
                                                                                                \
        if (IS_DBCS_ENABLED() && (((_msg) == WM_CHAR) || ((_msg) == EM_SETPASSWORDCHAR))) {     \
            /*                                                                                  \
             * Check this message is DBCS Message or not..                                      \
             */                                                                                 \
            if (IS_DBCS_MESSAGE((_wParam))) {                                                   \
                PKERNEL_MSG pmsgDbcsCB = GetCallBackDbcsInfo();                                 \
                /*                                                                              \
                 * Mark this is DBCS character.                                                 \
                 */                                                                             \
                (_bDbcs) = TRUE;                                                                \
                /*                                                                              \
                 * Backup current message. this backupped message will be used                  \
                 * when Apps peek (or get) message from thier WndProc.                          \
                 * (see GetMessageA(), PeekMessageA()...)                                       \
                 */                                                                             \
                pmsgDbcsCB->hwnd    = (_hwnd);                                                  \
                pmsgDbcsCB->message = (_msg);                                                   \
                pmsgDbcsCB->lParam  = (_lParam);                                                \
                pmsgDbcsCB->time    = (_time);                                                  \
                pmsgDbcsCB->pt      = (_pt);                                                    \
                /*                                                                              \
                 * DbcsLeadByte will be sent below soon, we just need DbcsTrailByte             \
                 * for further usage..                                                          \
                 */                                                                             \
                pmsgDbcsCB->wParam = ((_wParam) & 0x000000FF);                                  \
                /*                                                                              \
                 * Pass the LeadingByte of the DBCS character to an ANSI WndProc.               \
                 */                                                                             \
                (_wParam) = ((_wParam) & 0x0000FF00) >> 8;                                      \
            } else {                                                                            \
                /*                                                                              \
                 * Validate only BYTE for WM_CHAR.                                              \
                 */                                                                             \
                (_wParam) &= 0x000000FF;                                                        \
            }                                                                                   \
        }

// windows\core\ntuser\client\winmgrc.c
#define AW_HOR          (AW_HOR_POSITIVE | AW_HOR_NEGATIVE | AW_CENTER)
#define AW_VER          (AW_VER_POSITIVE | AW_VER_NEGATIVE | AW_CENTER)

// windows\core\ntuser\imm\ctxtinfo.c
#define SEND_MESSAGE(bAnsi)   ((bAnsi) ? SendMessageA : SendMessageW)

// windows\core\ntuser\imm\immcli.h
#define ValidateHwnd(hwnd)   (((hwnd) == (HWND)NULL || !bUser32Initialized) \
        ? (PWND)NULL : HMValidateHandle(hwnd, TYPE_WINDOW))
#define GetWindowProcess(hwnd) \
            (ULONG_PTR)NtUserQueryWindow(hwnd, WindowProcess)
#define IsWndEqual(hWnd1, hWnd2) (LOWORD(HandleToUlong(hWnd1)) == LOWORD(HandleToUlong(hWnd2)) && \
            ValidateHwnd(hWnd1) == ValidateHwnd(hWnd2))

// windows\core\ntuser\imm\sftkbdt1.c
#define INIT_WIDTH(name, width) \
            lpSKT1Ctxt->nButtonWidth[SKT1_ ## name ## _TYPE] = (width)

// windows\core\ntuser\inc\ntsend.h
#define MESSAGECALL(api) \
LRESULT api(             \
    HWND hwnd,           \
    UINT msg,            \
    WPARAM wParam,       \
    LPARAM lParam,       \
    ULONG_PTR xParam,     \
    DWORD xpfnProc,      \
    BOOL bAnsi)

// windows\core\ntuser\inc\user.h
#define TEST_EffectInvertPUSIF(f) (TEST_PUSIF(f) || !TEST_PUSIF(PUSIF_UIEFFECTS))
#define TestCF(hwnd, flag)   (*((KPBYTE)((PWND)(hwnd))->pcls + CFOFFSET + HIBYTE(flag)) & LOBYTE(flag))
#define SetCF(hwnd, flag)    (*((KPBYTE)((PWND)(hwnd))->pcls + CFOFFSET + HIBYTE(flag)) |= LOBYTE(flag))
#define ClrCF(pcls, flag)    (*((KPBYTE)((PWND)(hwnd))->pcls + CFOFFSET + HIBYTE(flag)) &= ~LOBYTE(flag))
#define WFPIXIEHACK             0x0680  // Send (HRGN)1 to WM_NCPAINT (see PixieHack)
#define TestWF(hwnd, flag)   (*(((KPBYTE)(hwnd)) + STATEOFFSET + (int)HIBYTE(flag)) & LOBYTE(flag))
#define SetWF(hwnd, flag)    (*(((KPBYTE)(hwnd)) + STATEOFFSET + (int)HIBYTE(flag)) |= LOBYTE(flag))
#define ClrWF(hwnd, flag)    (*(((KPBYTE)(hwnd)) + STATEOFFSET + (int)HIBYTE(flag)) &= ~LOBYTE(flag))
#define TestwndPopup(hwnd)   (TestwndNIPopup(hwnd) || TestwndIPopup(hwnd))
#define TestwndHI(hwnd)      (TestwndTiled(hwnd) || TestwndIPopup(hwnd))
#define QF_MOUSEMOVED             (UINT)0x00020 // Mouse has moved but no move posted yet. Coalescing & performance
#define RTL_UI()              (ARABIC_UI_LANGID() || HEBREW_UI_LANGID())

// windows\core\ntuser\kdexts\userexts.c
#define GETSHAREDINFO(psi) moveExp(&psi, VAR(gSharedInfo))

// windows\core\ntuser\kernel\access.h
#define UNION(x, y) ((x) | (y))

// windows\core\ntuser\kernel\input.c
#define PATHTAKEN(x)  pathTaken  |= x
#define PATHTAKEN(x)  pathTaken  |= x
#define PATHTAKEN2(x) pathTaken2 |= x
#define PATHTAKEN3(x) pathTaken3 |= x

// windows\core\ntuser\kernel\ntstubs.c
#define ValidateHWNDND(p,h)                 \
    if ( ((p = ValidateHwnd(h)) == NULL) || \
         (GETFNID(p) == FNID_DESKTOP) ||    \
         (GETFNID(p) == FNID_MESSAGEWND)    \
        )       \
        MSGERROR(0);
#define ValidateHWNDIA(p,h)                      \
    if (h != HWND_TOP &&                         \
        h != HWND_BOTTOM &&                      \
        h != HWND_TOPMOST &&                     \
        h != HWND_NOTOPMOST) {                   \
        if ( ((p = ValidateHwnd(h)) == NULL) ||  \
             (GETFNID(p) == FNID_DESKTOP) ||     \
             (GETFNID(p) == FNID_MESSAGEWND)     \
            )        \
            MSGERROR(0);                          \
    } else {                                     \
        p = (PWND)h;                             \
    }

// windows\core\ntuser\kernel\queue.c
#define QS_TEST_AND_CLEAR (QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_SENDMESSAGE)

// windows\core\ntuser\kernel\sbctl.c
#define WSB_VERT (WSB_VERT_UP | WSB_VERT_DN)
#define WSB_HORZ   (WSB_HORZ_LF | WSB_HORZ_RT)

// windows\core\ntuser\kernel\sendmsg.c
#define IsASwitchWnd( pw )  \
        (gpsi->atomSysClass[ICLS_SWITCH] == pw->pcls->atomClassName)
#define IsOleMainThreadWnd( pw )  \
        (gaOleMainThreadWndClass == pw->pcls->atomClassName)
#define fBroadcastProc( pwnd )  \
    (!(ISAMENU(pwnd) || IsASwitchWnd(pwnd) || IsOleMainThreadWnd(pwnd)))

// windows\core\ntuser\kernel\ssend.c
#define LOCKPWND() \
    ThreadLock(pwnd, &tlpwnd);                  \
    cbwin = pci->CallbackWnd;                   \
    pci->CallbackWnd.pwnd = pwndClient;         \
    pci->CallbackWnd.hwnd = HW(pwnd);           \
    pci->CallbackWnd.pActCtx = ((pwnd == NULL) ? NULL : pwnd->pActCtx);
#define BEGIN_ENDSENDCAPTURE(type, error) \
exit:
#define END_ENDSENDCAPTURE(type, error) \
       return (type)error
#define BEGIN_ENDSENDCAPTUREVOID() \
errorexit:
#define END_ENDSENDCAPTUREVOID() \
   return

// windows\core\ntuser\kernel\swp.c
#define SWP_BOZO ( SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOREDRAW | SWP_NOACTIVATE )

// windows\core\ntuser\kernel\userk.h
#define MIRRORED_HDC(hdc)     (GreGetLayout(hdc) & LAYOUT_RTL)
#define ProbeAndReadSize(Address)                         \
    (((Address) >= (SIZE * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile SIZE * const)MM_USER_PROBE_ADDRESS) : (*(volatile SIZE *)(Address)))
#define ProbeAndReadBlendfunction(Address)                         \
    (((Address) >= (BLENDFUNCTION * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile BLENDFUNCTION * const)MM_USER_PROBE_ADDRESS) : (*(volatile BLENDFUNCTION *)(Address)))
#define ProbeAndReadMessage(Address)                     \
    (((Address) >= (MSG * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile MSG * const)MM_USER_PROBE_ADDRESS) : (*(volatile MSG *)(Address)))
#define ProbeAndReadWindowPlacement(Address)                         \
    (((Address) >= (WINDOWPLACEMENT * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile WINDOWPLACEMENT * const)MM_USER_PROBE_ADDRESS) : (*(volatile WINDOWPLACEMENT *)(Address)))
#define ProbeAndReadMenuInfo(Address)                             \
    (((Address) >= (MENUINFO * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile MENUINFO * const)MM_USER_PROBE_ADDRESS) : (*(volatile MENUINFO *)(Address)))
#define ProbeAndReadScrollInfo(Address)                         \
    (((Address) >= (SCROLLINFO * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile SCROLLINFO * const)MM_USER_PROBE_ADDRESS) : (*(volatile SCROLLINFO *)(Address)))
#define ProbeAndReadPopupParams(Address)                       \
    (((Address) >= (TPMPARAMS * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile TPMPARAMS * const)MM_USER_PROBE_ADDRESS) : (*(volatile TPMPARAMS *)(Address)))
#define ProbeAndReadHelp(Address)                        \
    (((Address) >= (HLP * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile HLP * const)MM_USER_PROBE_ADDRESS) : (*(volatile HLP *)(Address)))
#define ProbeAndReadHelpInfo(Address)                         \
    (((Address) >= (HELPINFO * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile HELPINFO * const)MM_USER_PROBE_ADDRESS) : (*(volatile HELPINFO *)(Address)))
#define ProbeAndReadTrackMouseEvent(Address) \
    (((Address) >= (TRACKMOUSEEVENT * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile TRACKMOUSEEVENT * const)MM_USER_PROBE_ADDRESS) : (*(volatile TRACKMOUSEEVENT *)(Address)))
#define ProbeAndReadWindowPos(Address) \
    (((Address) >= (WINDOWPOS * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile WINDOWPOS * const)MM_USER_PROBE_ADDRESS) : (*(volatile WINDOWPOS *)(Address)))
#define ProbeAndReadCursorFind(Address) \
    (((Address) >= (CURSORFIND * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile CURSORFIND * const)MM_USER_PROBE_ADDRESS) : (*(volatile CURSORFIND *)(Address)))
#define ProbeAndReadSetClipBData(Address) \
    (((Address) >= (SETCLIPBDATA * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile SETCLIPBDATA * const)MM_USER_PROBE_ADDRESS) : (*(volatile SETCLIPBDATA *)(Address)))
#define ProbeAndReadCursorData(Address) \
    (((Address) >= (CURSORDATA * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile CURSORDATA * const)MM_USER_PROBE_ADDRESS) : (*(volatile CURSORDATA *)(Address)))
    #define ProbeAndReadCandidateForm(Address) \
        (((Address) >= (CANDIDATEFORM * const)MM_USER_PROBE_ADDRESS) ? \
            (*(volatile CANDIDATEFORM * const)MM_USER_PROBE_ADDRESS) : (*(volatile CANDIDATEFORM *)(Address)))
    #define ProbeAndReadCompositionForm(Address) \
        (((Address) >= (COMPOSITIONFORM * const)MM_USER_PROBE_ADDRESS) ? \
            (*(volatile COMPOSITIONFORM * const)MM_USER_PROBE_ADDRESS) : (*(volatile COMPOSITIONFORM *)(Address)))
#define ProbeAndReadMenuGetObjectInfo(Address) \
    (((Address) >= (MENUGETOBJECTINFO * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile MENUGETOBJECTINFO * const)MM_USER_PROBE_ADDRESS) : (*(volatile MENUGETOBJECTINFO *)(Address)))
#define GDIAF_ARRIVED         (USHORT)0x0001 // open & start reading
#define ScSendMessageSMS(pwnd, msg, wParam, lParam, xParam, xpfn, dwSCMSFlags, psms) \
        (((msg) & ~MSGFLAG_MASK) >= WM_USER) ? \
        SfnDWORD(pwnd, msg, wParam, lParam, xParam, xpfn, dwSCMSFlags, psms) : \
        gapfnScSendMessage[MessageTable[msg & 0xffff].iFunction](pwnd, msg, wParam, lParam, xParam, xpfn, dwSCMSFlags, psms)
#define ScSendMessage(pwnd, msg, wParam, lParam, xParam, xpfn, dwSCMSFlags) \
        ScSendMessageSMS(pwnd, msg, wParam, lParam, xParam, xpfn, dwSCMSFlags, NULL)
#define PLAST_ELEM(a) (&LAST_ELEM(a))
#define NEEDSSYNCPAINT(pwnd) TestWF(pwnd, WFSENDERASEBKGND | WFSENDNCPAINT)
#define DF_TOOLTIP          (DF_TOOLTIPACTIVE | DF_TOOLTIPSHOWING)
#define DF_TRACKMOUSEEVENT  (DF_TRACKMOUSELEAVE | DF_TRACKMOUSEHOVER)
#define DF_MOUSEMOVETRK     (DF_HOTTRACKING | DF_TOOLTIPACTIVE | DF_TRACKMOUSELEAVE | DF_TRACKMOUSEHOVER)
#define DTM_SETUPAPPRAN (WM_USER+90)
#define LINP_INPUTSOURCES   (LINP_KEYBOARD | LINP_JOURNALLING)
#define IsHooked(pti, fsHook) \
    ((fsHook & (pti->fsHooks | pti->pDeskInfo->fsHooks)) != 0)
#define PWND_INPUTOWNER (PWND)1    // Means send WM_HOTKEY to input owner.
#define xxxReceiveMessages(pti) \
    while ((pti)->pcti->fsWakeBits & QS_SENDMESSAGE) { xxxReceiveMessage((pti)); }
#define PAS_HORZ        (PAS_LEFT | PAS_RIGHT)
#define PAS_VERT        (PAS_UP | PAS_DOWN)
#define TestEffectInvertUP(uSetting) (TestUP(uSetting) || !TestUP(UIEFFECTS))
#define __GetWindowLong(pwnd, index) ((LONG)(*(DWORD UNALIGNED *)((BYTE *)((pwnd) + 1) + (index))))
#define __GetWindowLongPtr(pwnd, index) ((LONG_PTR)(*(ULONG_PTR UNALIGNED *)((BYTE *)((pwnd) + 1) + (index))))
#define FCallTray(p) (FDoTray() && ( FCallHookTray()|| FPostTray(p) ))
#define GETPCI(pcur) ((PCURSINFO)&(pcur->CI_FIRST))
#define TestALPHA(uSetting) (!gbDisableAlpha && TestEffectUP(uSetting))
#define IsWndImeRelated(pwnd)   \
    (pwnd->pcls->atomClassName == gpsi->atomSysClass[ICLS_IME] || \
     TestCF(pwnd, CFIME))

// windows\core\ntuser\kernel\wmicon.c
#define GetCWidth(cxOrg, lrF, cxDes) \
    (cxOrg ? cxOrg : ((lrF & DI_DEFAULTSIZE) ? SYSMET(CXICON) : cxDes))
#define GetCHeight(cyOrg, lrF, cyDes) \
    (cyOrg ? cyOrg : ((lrF & DI_DEFAULTSIZE) ? SYSMET(CYICON) : cyDes))

// windows\core\ntuser\server\exitwin.c
#define BEGIN_LPC_RECV(API)                                                 \
    P##API##MSG a = (P##API##MSG)&m->u.ApiMessageData;                      \
    PCSR_THREAD pcsrt;                                                      \
    PTEB Teb = NtCurrentTeb();                                              \
    NTSTATUS Status = STATUS_SUCCESS;                                       \
    UNREFERENCED_PARAMETER(ReplyStatus);                                    \
                                                                            \
    Teb->LastErrorValue = 0;                                                \
    pcsrt = CSR_SERVER_QUERYCLIENTTHREAD();
#define END_LPC_RECV()                                                  \
    a->dwLastError = Teb->LastErrorValue;                               \
    return Status;

// windows\core\ntuser\tools\perf\userdata.h
#define NUM_SETWINDOWPOS_OFFSET   NUM_CURSORS_OFFSET    + sizeof(DWORD)
#define NUM_HOOKS_OFFSET          NUM_SETWINDOWPOS_OFFSET   + sizeof(DWORD)

// windows\core\ntuser\tools\usrbench\usrbench.c
#define SUBITEM(fmt, v) \
                sprintf(szT, fmt, v); \
                ListView_SetItemText(hwndList, lvl.iItem, ++lvl.iSubItem, szT);

// windows\core\w32inc\w32err.h
#define ZERO(t)     ((*(t *)&gZero))
#define PZERO(t)    ((t *)&gZero)

// windows\core\w32inc\w32wow64.h
    #define KHWND_TO_HWND(h)                 ((HWND)(KERNEL_ULONG_PTR)(h))

// windows\core\wow64win\cgen\cgenhdr.h
#define PCALLDATA(x) (&(pmsg->x))

// windows\core\wow64win\whwin32\whwin32.tpl
#define ClientSharedInfo() (&gSharedInfo)

// windows\feime\ddk\inc\indicml.h
#define INDICM_REMOVEDEFAULTMENUITEMS     (WM_USER+102)

// windows\feime\ddk\jpn\fakeime.h
#define IsCTLPushed(x)          ((x)[VK_CONTROL] & 0x80)
#define IsALTPushed(x)          ((x)[VK_ALT] & 0x80)

// windows\feime\kor\ime2k\cicerolib\inc\ccstock.h
#define IS_WINDOW_RTL_MIRRORED(hwnd)    (g_bMirroredOS && Mirror_IsWindowMirroredRTL(hwnd))
#define GET_PROCESS_DEF_LAYOUT(pdwl)    (g_bMirroredOS && Mirror_GetProcessDefaultLayout(pdwl))

// windows\feime\kor\ime2k\cicerolib\inc\osver.h
#define IsOnNT()       (g_dwOsVer & OSVER_ONNT)
#define IsOnNT5()      (g_dwOsVer & OSVER_ONNT5)
#define IsOn95()       (g_dwOsVer & OSVER_ON95)
#define IsOn98()       (g_dwOsVer & OSVER_ON98)
#define IsOn98orNT5()  (g_dwOsVer & (OSVER_ON98 | OSVER_ONNT5))
#define IsOnFE()       (g_dwOsVer & OSVER_ONFE)
#define IsOnImm()      (g_dwOsVer & OSVER_ONIMM)
#define IsOnDBCS()     (g_dwOsVer & OSVER_ONDBCS)
#define IsOnNT51()     (g_dwOsVer & OSVER_ONNT51)

// windows\feime\kor\ime2k\fecommon\common\winapi.h
#define WinComboBox_Enable(hwndCtl, fEnable)        EnableWindow((hwndCtl), (fEnable))
#define WinComboBox_GetText(hwndCtl, lpch, cchMax)  GetWindowText((hwndCtl), (lpch), (cchMax))
#define WinComboBox_GetTextA(hwndCtl, lpch, cchMax) WinGetWindowTextA((hwndCtl), (lpch), (cchMax))
#define WinComboBox_GetTextW(hwndCtl, lpch, cchMax) WinGetWindowTextW((hwndCtl), (lpch), (cchMax))
#define WinComboBox_GetTextLength(hwndCtl)          GetWindowTextLength(hwndCtl)
#define WinComboBox_GetTextLengthA(hwndCtl)         WinGetWindowTextLengthA(hwndCtl)
#define WinComboBox_GetTextLengthW(hwndCtl)         WinGetWindowTextLengthW(hwndCtl)
#define WinComboBox_SetText(hwndCtl, lpsz)          SetWindowText((hwndCtl), (lpsz))
#define WinComboBox_SetTextA(hwndCtl, lpsz)         WinSetWindowTextA((hwndCtl), (lpsz))
#define WinComboBox_SetTextW(hwndCtl, lpsz)         WinSetWindowTextW((hwndCtl), (lpsz))
#define WinComboBox_LimitText(hwndCtl, cchLimit)   ((int)(DWORD)WinSendMessage((hwndCtl), \
																			   CB_LIMITTEXT, \
																			   (WPARAM)(int)(cchLimit), \
																			   0L))
#define WinComboBox_GetEditSel(hwndCtl)            ((DWORD)WinSendMessage((hwndCtl), \
																		  CB_GETEDITSEL, \
																		  0L, 0L))
#define WinComboBox_SetEditSel(hwndCtl, ichStart, ichEnd) ((int)(DWORD)WinSendMessage((hwndCtl), \
																					  CB_SETEDITSEL, \
																					  0L, \
																					  MAKELPARAM((ichStart), \
																								 (ichEnd))))
#define WinComboBox_GetCount(hwndCtl)              ((int)(DWORD)WinSendMessage((hwndCtl), \
																			   CB_GETCOUNT, \
																			   0L, 0L))
#define WinComboBox_ResetContent(hwndCtl)          ((int)(DWORD)WinSendMessage((hwndCtl), \
																			   CB_RESETCONTENT, \
																			   0L, 0L))
#define WinComboBox_AddString(hwndCtl, lpsz)       ((int)(DWORD)WinSendMessage((hwndCtl), \
																			   CB_ADDSTRING, \
																			   0L, \
																			   (LPARAM)(LPCTSTR)(lpsz)))
#define WinComboBox_AddStringA(hwndCtl, lpsz)       CB_AddStringA((hwndCtl), lpsz)
#define WinComboBox_AddStringW(hwndCtl, lpsz)       CB_AddStringW((hwndCtl), lpsz)
#define WinComboBox_InsertString(hwndCtl, index, lpsz) ((int)(DWORD)WinSendMessage((hwndCtl), \
																				   CB_INSERTSTRING, \
																				   (WPARAM)(int)(index), \
																				   (LPARAM)(LPCTSTR)(lpsz)))
#define WinComboBox_InsertStringA(hwndCtl, index, lpsz) CB_InsertStringA((hwndCtl), index, lpsz)
#define WinComboBox_InsertStringW(hwndCtl, index, lpsz) CB_InsertStringW((hwndCtl), index, lpsz)
#define WinComboBox_AddItemData(hwndCtl, data)     ((int)(DWORD)WinSendMessage((hwndCtl), \
																			   CB_ADDSTRING, \
																			   0L, \
																			   (LPARAM)(data)))
#define WinComboBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)WinSendMessage((hwndCtl), \
																					 CB_INSERTSTRING, \
																					 (WPARAM)(int)(index), \
																					 (LPARAM)(data)))
#define WinComboBox_GetLBTextLen(hwndCtl, index)           ((int)(DWORD)WinSendMessage((hwndCtl), \
																					   CB_GETLBTEXTLEN, \
																					   (WPARAM)(int)(index), \
																					   0L))
#define WinComboBox_GetLBText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)WinSendMessage((hwndCtl), \
																					   CB_GETLBTEXT, \
																					   (WPARAM)(int)(index), \
																					   (LPARAM)(LPCTSTR)(lpszBuffer)))
#define WinComboBox_GetLBTextA(hwndCtl, index, lpszBuffer)  CB_GetLBTextA((hwndCtl), (index), lpszBuffer)
#define WinComboBox_GetLBTextW(hwndCtl, index, lpszBuffer)  CB_GetLBTextW((hwndCtl), (index), lpszBuffer)
#define WinComboBox_GetItemData(hwndCtl, index)        ((LRESULT)(DWORD)WinSendMessage((hwndCtl), \
																					   CB_GETITEMDATA, \
																					   (WPARAM)(int)(index), \
																					   0L))
#define WinComboBox_SetItemData(hwndCtl, index, data)  ((int)(DWORD)WinSendMessage((hwndCtl), \
																				   CB_SETITEMDATA, \
																				   (WPARAM)(int)(index), \
																				   (LPARAM)(data)))
#define WinComboBox_FindString(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)WinSendMessage((hwndCtl), \
																						   CB_FINDSTRING, \
																						   (WPARAM)(int)(indexStart), \
																						   (LPARAM)(LPCTSTR)(lpszFind)))
#define WinComboBox_FindStringA(hwndCtl,indexStart,lpszFind)  CB_FindStringA((hwndCtl), indexStart,lpszFind)
#define WinComboBox_FindStringW(hwndCtl,indexStart,lpszFind)  CB_FindStringW((hwndCtl), indexStart,lpszFind)
#define WinComboBox_FindItemData(hwndCtl, indexStart, data)    ((int)(DWORD)WinSendMessage((hwndCtl), \
																						   CB_FINDSTRING, \
																						   (WPARAM)(int)(indexStart), \
																						   (LPARAM)(data)))
#define WinComboBox_GetCurSel(hwndCtl)                 ((int)(DWORD)WinSendMessage((hwndCtl), \
																				   CB_GETCURSEL, \
																				   0L, 0L))
#define WinComboBox_SetCurSel(hwndCtl, index)          ((int)(DWORD)WinSendMessage((hwndCtl), \
																				   CB_SETCURSEL, \
																				   (WPARAM)(int)(index), \
																				   0L))
#define WinComboBox_SelectString(hwndCtl, indexStart, lpszSelect) ((int)WinSendMessage((hwndCtl), \
																					   CB_SELECTSTRING, \
																					   (WPARAM)(indexStart), \
																					   (LPARAM)(lpszSelect)))
#define WinComboBox_SelectStringA(hwndCtl, indexStart, lpszSelect) CB_SelectStringA((hwndCtl), \
																					(indexStart), \
																					(lpszSelect))
#define WinComboBox_SelectStringW(hwndCtl, indexStart, lpszSelect) CB_SelectStringW((hwndCtl), \
																					(indexStart), \
																					(lpszSelect))
#define WinComboBox_SelectItemData(hwndCtl, indexStart, data) ((int)WinSendMessage((hwndCtl), \
																				   CB_SELECTSTRING, \
																				   (WPARAM)(indexStart), \
																				   (LPARAM)(data)))
#define WinComboBox_Dir(hwndCtl, attrs, lpszFileSpec)  ((int)(DWORD)WinSendMessage((hwndCtl), \
																				   CB_DIR, \
																				   (WPARAM)(UINT)(attrs), \
																				   (LPARAM)(LPCTSTR)(lpszFileSpec)))
#define WinComboBox_ShowDropdown(hwndCtl, fShow)       ((BOOL)(DWORD)WinSendMessage((hwndCtl), \
																					CB_SHOWDROPDOWN, \
																					(WPARAM)(BOOL)(fShow), \
																					0L))
#define WinComboBox_FindStringExact(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)WinSendMessage((hwndCtl), CB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define WinComboBox_FindStringExactA(hwndCtl,indexStart,lpszFind)  CB_FindStringExactA((hwndCtl), indexStart,lpszFind)
#define WinComboBox_FindStringExactW(hwndCtl,indexStart,lpszFind)  CB_FindStringExactW((hwndCtl), indexStart,lpszFind)
#define WinComboBox_GetDroppedState(hwndCtl)           ((BOOL)(DWORD)WinSendMessage((hwndCtl), \
																					CB_GETDROPPEDSTATE, \
																					0L, 0L))
#define WinComboBox_GetDroppedControlRect(hwndCtl, lprc) ((void)WinSendMessage((hwndCtl), \
																			   CB_GETDROPPEDCONTROLRECT, \
																			   0L, (LPARAM)(RECT *)(lprc)))
#define WinComboBox_GetItemHeight(hwndCtl)             ((int)(DWORD)WinSendMessage((hwndCtl), \
																				   CB_GETITEMHEIGHT, \
																				   0L, 0L))
#define WinComboBox_SetItemHeight(hwndCtl, index, cyItem) ((int)(DWORD)WinSendMessage((hwndCtl), \
																					  CB_SETITEMHEIGHT, \
																					  (WPARAM)(int)(index), \
																					  (LPARAM)(int)cyItem))
#define WinComboBox_GetExtendedUI(hwndCtl)             ((UINT)(DWORD)WinSendMessage((hwndCtl), \
																					CB_GETEXTENDEDUI, \
																					0L, 0L))
#define WinComboBox_SetExtendedUI(hwndCtl, flags)      ((int)(DWORD)WinSendMessage((hwndCtl), \
																				   CB_SETEXTENDEDUI, \
																				   (WPARAM)(UINT)(flags), \
																				   0L))

// windows\feime\kor\ime2k\fecommon\imembx\helpid.h
#define IDH_PAD_HW_INPUT_INPUT		3201		//è«üÍ-üÍ{^(button)
#define IDH_PAD_HW_INPUT_RECOG		3202		//è«üÍ-F¯{^(button)
#define IDH_PAD_HW_INPUT_CLEAR		3203		//è«üÍ-Á{^(button)
#define IDH_PAD_HW_INPUT_PROP		3204		//è«üÍ-vpeB{^(button)
#define IDH_PAD_HW_SEARCH_SEARCH		3207		//è«õ-õ{^(button)
#define IDH_PAD_HW_SEARCH_RECOG		3208		//è«õ-F¯{^(button)
#define IDH_PAD_HW_SEARCH_REVERT		3209		//è«õ-ß·{^(button)
#define IDH_PAD_HW_SEARCH_CLEAR		3210		//è«õ-Á{^(button)
#define IDH_PAD_HW_SEARCH_DETAIL		3211		//è«õ-ê/Ú×{^(button)

// windows\feime\kor\ime2k\fecommon\imembx\hlpidjpn.h
#define IDH_PAD_HW_INPUT_INPUT		3201		//è«üÍ-üÍ{^(button)
#define IDH_PAD_HW_INPUT_RECOG		3202		//è«üÍ-F¯{^(button)
#define IDH_PAD_HW_INPUT_CLEAR		3203		//è«üÍ-Á{^(button)
#define IDH_PAD_HW_INPUT_PROP		3204		//è«üÍ-vpeB{^(button)
#define IDH_PAD_HW_SEARCH_SEARCH		3207		//è«õ-õ{^(button)
#define IDH_PAD_HW_SEARCH_RECOG		3208		//è«õ-F¯{^(button)
#define IDH_PAD_HW_SEARCH_REVERT		3209		//è«õ-ß·{^(button)
#define IDH_PAD_HW_SEARCH_CLEAR		3210		//è«õ-Á{^(button)
#define IDH_PAD_HW_SEARCH_DETAIL		3211		//è«õ-ê/Ú×{^(button)

// windows\feime\kor\ime2k\fecommon\imembx\recog.h
#define ALC_MATH			0x00000040	// %^*()-+={}<>,/.  (??? language dependent ???)
#define ALC_ALPHA			(ALC_LCALPHA | ALC_UCALPHA)
#define ALC_ALPHANUMERIC	(ALC_ALPHA | ALC_NUMERIC)
#define	ALC_KANJI_ALL		(ALC_KANJI_COMMON | ALC_KANJI_RARE)
#define	ALC_HANGUL_ALL		(ALC_HANGUL_COMMON | ALC_HANGUL_RARE)
#define	ALC_EXTENDED_SYM	(ALC_MATH | ALC_MONETARY | ALC_OTHER)
#define	ALC_USA_EXTENDED	(ALC_USA_COMMON | ALC_EXTENDED_SYM)
#define	ALC_JPN_COMMON		(ALC_SYS_DEFAULT | ALC_KANA | ALC_KANJI_COMMON)
#define	ALC_JPN_EXTENDED	(ALC_JPN_COMMON | ALC_EXTENDED_SYM | ALC_KANJI_RARE)
#define	ALC_CHS_COMMON		(ALC_SYS_DEFAULT | ALC_KANJI_COMMON)
#define	ALC_CHS_EXTENDED	(ALC_CHS_COMMON | ALC_EXTENDED_SYM | ALC_KANJI_RARE)
#define	ALC_CHT_COMMON		(ALC_SYS_DEFAULT | ALC_KANJI_COMMON)
#define	ALC_CHT_EXTENDED	(ALC_CHT_COMMON | ALC_EXTENDED_SYM | ALC_KANJI_RARE)
#define	ALC_KOR_COMMON		(ALC_SYS_DEFAULT | ALC_HANGUL_COMMON | ALC_KANJI_COMMON)
#define	ALC_KOR_EXTENDED	(ALC_KOR_COMMON | ALC_EXTENDED_SYM | ALC_HANGUL_RARE | ALC_KANJI_RARE)

// windows\feime\kor\ime2k\fecommon\lib\ddbtn\cddbtn.h
#define BID_ALL			(BID_BUTTON | BID_DROPDOWN)

// windows\feime\kor\ime2k\fecommon\lib\ddbtn\ddbtn.h
#define DDBM_ADDITEM			(WM_USER + 100)
#define DDBM_INSERTITEM			(WM_USER + 101)
#define DDBM_SETCURSEL			(WM_USER + 102)
#define DDBM_GETCURSEL			(WM_USER + 103)
#define DDBM_SETICON			(WM_USER + 104)
#define DDBM_SETSTYLE			(WM_USER + 106)
#define DDButton_AddItem(hwndCtrl, pddbItem) \
		((int)(DWORD)SendMessage((hwndCtrl), DDBM_ADDITEM, 0, (LPARAM)pddbItem))
#define DDButton_InsertItem(hwndCtrl, index, pddbItem) \
		((int)(DWORD)SendMessage((hwndCtrl), DDBM_INSERTITEM, (WPARAM)(index), (LPARAM)(pddbItem)))
#define DDButton_SetCurSel(hwndCtrl, index) \
		((int)(DWORD)SendMessage((hwndCtrl), DDBM_SETCURSEL, (WPARAM)(index), (LPARAM)0))
#define DDButton_GetCurSel(hwndCtrl) \
		((int)(DWORD)SendMessage((hwndCtrl), DDBM_GETCURSEL, (WPARAM)0, (LPARAM)0))
#define DDButton_SetIcon(hwndCtrl, hIcon) \
		((int)(DWORD)SendMessage((hwndCtrl), DDBM_SETICON, (WPARAM)hIcon, (LPARAM)0))
#define DDButton_SetText(hwndCtrl, lpsz) \
		((int)(DWORD)SendMessage((hwndCtrl), DDBM_SETTEXT, (WPARAM)lpsz, (LPARAM)0))
#define DDButton_SetStyle(hwndCtrl, dwStyle) \
		((int)(DWORD)SendMessage((hwndCtrl), DDBM_SETSTYLE, (WPARAM)dwStyle, (LPARAM)0))

// windows\feime\kor\ime2k\fecommon\lib\exbtn\exbtn.h
#define EXBM_SETICON			(WM_USER + 102)
#define EXBM_SETSTYLE			(WM_USER + 104)
#define EXButton_GetCheck(hwndCtrl) \
		((int)(DWORD)SendMessage((hwndCtrl), EXBM_GETCHECK, (WPARAM)0, (LPARAM)0))
#define EXButton_SetCheck(hwndCtrl, fCheck) \
		((int)(DWORD)SendMessage((hwndCtrl), EXBM_SETCHECK, (WPARAM)(BOOL)fCheck, (LPARAM)0))
#define EXButton_SetIcon(hwndCtrl, hIcon) \
		((int)(DWORD)SendMessage((hwndCtrl), EXBM_SETICON, (WPARAM)hIcon, (LPARAM)0))
#define EXButton_SetText(hwndCtrl, lpsz) \
		((int)(DWORD)SendMessage((hwndCtrl), EXBM_SETTEXT, (WPARAM)lpsz, (LPARAM)0))
#define EXButton_SetStyle(hwndCtrl, dwStyle) \
		((int)(DWORD)SendMessage((hwndCtrl), EXBM_SETSTYLE, (WPARAM)dwStyle, (LPARAM)0))

// windows\feime\kor\ime2k\fecommon\lib\ptt\ptt.h
#define TTM_RELAYEVENT_WITHUSERINFO		(WM_USER+101)

// windows\feime\kor\ime2k\imm32\immsys.h
#define INDICM_REMOVEDEFAULTMENUITEMS     (WM_USER+102)

// windows\feime\kor\ime2k\imm32\indicml.h
#define INDICM_REMOVEDEFAULTMENUITEMS     (WM_USER+102)

// windows\feime\kor\ime2k\tip\toolbar.h
#define UPDTTB_ALL (UPDTTB_CMODE|UPDTTB_FHMODE|UPDTTB_HJMODE|UPDTTB_SKDMODE)

// windows\feime\kor\johab\johab.rc
#define TABGRP  (WS_TABSTOP | WS_GROUP)

// windows\feime\kor\uhc\msime95k.rc
#define TABGRP  (WS_TABSTOP | WS_GROUP)

// windows\feime\kor\wansung\wansung.rc
#define TABGRP  (WS_TABSTOP | WS_GROUP)

// windows\netdde\incs\scrnupdt.h
#define UpdateScreenStatistics()                                    \
    {                                                               \
        if( bShowStatistics && !bIconic )  {                        \
        if (ptdHead != NULL)                                        \
                InvalidateRect( ptdHead->hwndDDE, NULL, FALSE );    \
        }                                                           \
    }
#define UpdateScreenState()                                         \
    {                                                               \
        if( !bIconic )  {                                           \
        if (ptdHead != NULL) {                                      \
                InvalidateRect( ptdHead->hwndDDE, NULL, TRUE );     \
                UpdateWindow(ptdHead->hwndDDE);                     \
        }                                                           \
        }                                                           \
    }

// windows\netdde\incs\udselbox.h
#define SB_BUTTON_NORMAL   (SB_BUTTON_CANCEL | SB_BUTTON_OK)

// windows\oleacc\oleacc\listview.cpp
#define ListView_GetView(hwnd) \
    SNDMSG((hwnd), LVM_GETVIEW, 0, 0)
#define ListView_GetSelectedColumn(hwnd) \
    (UINT)SNDMSG((hwnd), LVM_GETSELECTEDCOLUMN, 0, 0)

// windows\oleacc\oleacc\listview.h
    #define ListView_GetHeader(hwnd)\
        (HWND)SNDMSG((hwnd), LVM_GETHEADER, 0, 0L)

// windows\oleacc\oleacc\outline.cpp
#define TreeView_GetItemState(hwndTV, hti, mask) \
   (UINT)SNDMSG((hwndTV), TVM_GETITEMSTATE, (WPARAM)hti, (LPARAM)mask)
#define TreeView_GetCheckState(hwndTV, hti) \
   ((((UINT)(SNDMSG((hwndTV), TVM_GETITEMSTATE, (WPARAM)hti, TVIS_STATEIMAGEMASK))) >> 12) -1)
#define TreeView_MapAccIDToHTREEITEM(hwnd, id) \
    (HTREEITEM)SNDMSG((hwnd), TVM_MAPACCIDTOHTREEITEM, id, 0)
#define TreeView_MapHTREEITEMToAccID(hwnd, htreeitem) \
    (UINT)SNDMSG((hwnd), TVM_MAPHTREEITEMTOACCID, (WPARAM)htreeitem, 0)

// windows\oleacc\oleacc\propmgr_util.h
#define HWNDKEYSIZE    (sizeof(DWORD)*4)

// windows\oleacc\oleacc\win64helper.h
#define TTM_GETTITLE            (WM_USER + 35)

// windows\richedit\inc30\imeapp.h
#define	VERSION_ID_IMEJP98	(VERSION_ID_JAPAN | 0x980)
#define	VERSION_ID_IMEJP98A	(VERSION_ID_JAPAN | 0x98a)

// windows\richedit\inc30\imm.h
#define SCS_CHANGEATTR                  (GCS_COMPREADATTR|GCS_COMPATTR)
#define SCS_CHANGECLAUSE                (GCS_COMPREADCLAUSE|GCS_COMPCLAUSE)

// windows\richedit\inc41\imeapp.h
#define	VERSION_ID_IMEJP98	(VERSION_ID_JAPAN | 0x980)
#define	VERSION_ID_IMEJP98A	(VERSION_ID_JAPAN | 0x98a)

// windows\richedit\inc41\imm.h
#define SCS_CHANGEATTR                  (GCS_COMPREADATTR|GCS_COMPATTR)
#define SCS_CHANGECLAUSE                (GCS_COMPREADCLAUSE|GCS_COMPCLAUSE)

// windows\richedit\inci\lsdnode.h
#define FIsDnodeOpenBorder(plsdn)  (FIsDnodeBorder(plsdn) && \
								   ((plsdn)->fOpenBorder))

// windows\richedit\inci\lsidefs.h
#define FImplies(a,b) (!(a)||(b))

// windows\richedit\lsinc\zqfromza.h
#define UpFromUa(tfl,pdevres,ua) (((tfl) & fUVertical) ? \
		I_VpFromVa(pdevres,ua) :\
		I_UpFromUa(pdevres,ua) \
)
#define UrFromUa(tfl,pdevres,ua) (((tfl) & fUVertical) ? \
		I_VrFromVa(pdevres,ua) :\
		I_UrFromUa(pdevres,ua) \
)
#define VpFromVa(tfl,pdevres,va) ((tfl) & fUVertical) ? \
		I_UpFromUa(pdevres,va) :\
		I_VpFromVa(pdevres,va) \
)
#define VrFromVa(tfl,pdevres,va) (((tfl) & fUVertical) ? \
		I_UrFromUa(pdevres,va) :\
		I_VrFromVa(pdevres,va) \
)
#define UaFromUp(tfl,pdevres,up) (((tfl) & fUVertical) ? \
		I_VaFromVp(pdevres,up) :\
		I_UaFromUp(pdevres,up) \
)
#define VaFromVp(tfl,pdevres,vp)	(((tfl) & fUVertical) ? \
		I_UaFromUp(pdevres,vp) :\
		I_VaFromVp(pdevres,vp) \
)
#define UaFromUr(tfl,pdevres,ur)	(((tfl) & fUVertical) ?	\
		I_VaFromVr(pdevres,ur) :\
		I_UaFromUr(pdevres,ur) \
)
#define VaFromVr(tfl,pdevres,vr)	(((tfl) & fUVertical) ?	\
		I_UaFromUr(pdevres,vr) :\
		I_VaFromVr(pdevres,vr) \
)
#define UpFromUr(tfl,pdevres,ur)	(((tfl) & fUVertical) ? \
								LsLwMultDivR(ur, (pdevres)->dypInch, (pdevres)->dyrInch): \
								LsLwMultDivR(ur, (pdevres)->dxpInch, (pdevres)->dxrInch) \
									)
#define VpFromVr(tfl,pdevres,vr)	(((tfl) & fUVertical) ? \
								LsLwMultDivR(vr, (pdevres)->dxpInch, (pdevres)->dxrInch): \
								LsLwMultDivR(vr, (pdevres)->dypInch, (pdevres)->dyrInch) \
									)
#define UrFromUp(tfl,pdevres,up)	(((tfl) & fUVertical) ? \
								LsLwMultDivR(up, (pdevres)->dyrInch, (pdevres)->dypInch): \
								LsLwMultDivR(up, (pdevres)->dxrInch, (pdevres)->dxpInch) \
									)
#define VrFromVp(tfl,pdevres,vp)	(((tfl) & fUVertical) ? \
								LsLwMultDivR(vp, (pdevres)->dxrInch, (pdevres)->dxpInch): \
								LsLwMultDivR(vp, (pdevres)->dyrInch, (pdevres)->dypInch) \
									)

// windows\richedit\lssrc\break.c
#define GetCpLimFromPosInLine(posinline) \
			(((posinline).plsdn->dcp == (posinline).dcp) ? \
				((posinline).plsdn->cpLimOriginal) : \
				((posinline).plsdn->cpFirst + (posinline).dcp ))

// windows\richedit\lssrc\chnutils.c
#define  LschnkeFromDnode(plschnke, plsdn) \
		 (plschnke)->cpFirst = plsdn->cpFirst; \
		 (plschnke)->dcp = (plsdn)->dcp; \
		 (plschnke)->plschp = &((plsdn)->u.real.lschp); \
		 (plschnke)->plsrun = (plsdn)->u.real.plsrun; \
		 (plschnke)->pdobj = (plsdn)->u.real.pdobj;
#define FDnodeInsideSubline(plssubl, plsdn) \
	    (FDnodeBeforeCpLim(plsdn, (plssubl)->cpLim) \
		&& FDnodeAfterCpFirst(plsdn, (plssubl)->cpFirst))
#define FUseForPurpose(plsdn, purpose)  \
		(*(&((plsdn)->u.real.pinfosubl->fUseForJustification) + (purpose -1)))

// windows\richedit\lssrc\dispmain.c
#define FIsDnodeToShade(pdn, cpLim) 	(FDnodeBeforeCpLim(pdn, cpLim) && FIsDnodeReal(pdn) && 	\
									!(pdn)->u.real.lschp.fInvisible && (pdn)->u.real.lschp.fShade)

// windows\richedit\lssrc\lscrline.c
#define  fFmiAdvancedFormatting  (fFmiPunctStartLine | fFmiHangingPunct)
#define FBreakJustSimple(lsbrj)  (lsbrj == lsbrjBreakJustify || lsbrj == lsbrjBreakThenSqueeze)
#define FPapInconsistent(plspap)	\
					((((plspap)->lsbrj == lsbrjBreakJustify ||  \
					   (plspap)->lsbrj == lsbrjBreakWithCompJustify) \
							&& (plspap)->uaRightBreak < uLsInfiniteRM \
							&& (plspap)->uaRightBreak != (plspap)->uaRightJustify) \
				||	 ((plspap)->lsbrj == lsbrjBreakThenExpand \
							&& (plspap)->uaRightBreak < (plspap)->uaRightJustify) \
				||	 ((plspap)->lsbrj == lsbrjBreakThenSqueeze \
							&& (plspap)->uaRightBreak > (plspap)->uaRightJustify) \
				||	 ((plspap)->lsbrj != lsbrjBreakWithCompJustify \
							&& (plspap)->grpf & fFmiHangingPunct) \
				||   ((plspap)->lsbrj == lsbrjBreakWithCompJustify \
							&& (plspap)->lskj == lskjFullGlyphs))

// windows\richedit\lssrc\lsfetch.c
#define CreatePenDnode(plsc,plsdnNew)\
		CreateDnode((plsc), (plsdnNew));\
		(plsdnNew)->dcp = 0;\
		(plsdnNew)->cpLimOriginal = (plsdnNew)->cpFirst;\
		(plsdnNew)->u.pen.dur = 0;\
		(plsdnNew)->u.pen.dup = 0;\
		(plsdnNew)->u.pen.dvr = 0;\
		(plsdnNew)->u.pen.dvp = 0;\
		(plsdnNew)->klsdn = klsdnPenBorder;
#define CreateBorderDnode(plsc,plsdnNew, durBorder, dupBorder)\
		CreateDnode((plsc), (plsdnNew));\
		(plsdnNew)->dcp = 0;\
		(plsdnNew)->cpLimOriginal = (plsdnNew)->cpFirst;\
		(plsdnNew)->u.pen.dur = (durBorder);\
		(plsdnNew)->u.pen.dup = (dupBorder);\
		(plsdnNew)->u.pen.dvr = 0;\
		(plsdnNew)->u.pen.dvp = 0;\
		(plsdnNew)->klsdn = klsdnPenBorder; \
		(plsdnNew)->fBorderNode = fTrue; \
		TurnOnNonRealDnodeEncounted(plsc);

// windows\richedit\lssrc\lsqcore.c
#define FIsZeroWidth(pdn)			(FIsDnodeReal(pdn) && (pdn)->u.real.dup == 0)

// windows\richedit\lssrc\lstxtnti.c
#define FModWidthSomeDobj(n)	(rglschnk[(n)].plschp->fModWidthOnRun || \
								rglschnk[(n)].plschp->fModWidthSpace || \
								rglschnk[(n)].plschp->fModWidthPairs)

// windows\richedit\lssrc\prepdisp.c
#define FIsWall(p, cpLim)	 (!FDnodeBeforeCpLim(p, cpLim) || p->fTab || FIsDnodePen(p))
#define FIsDnodeNormalPen(plsdn) 		(FIsDnodePen(plsdn) && (!(plsdn)->fAdvancedPen))

// windows\richedit\re30\_cfpf.h
#define IsHeadingStyle(Style)	(Style <= STYLE_HEADING_1 && \
								 Style >= STYLE_HEADING_9)
#define IsKnownStyle(Style)		(IsHeadingStyle(Style) || Style == STYLE_NORMAL)
#define IsStyleCommand(Style)	((Style & 0xFF00) == STYLE_COMMAND)
#define	GetTabPos(tab)		((tab) & 0xffffff)

// windows\richedit\re30\_edit.h
#define fABOVEX7FF  (fTHAI | fFE | fDEVANAGARI | fTAMIL | fOTHER)
#define fCOMPLEX_SCRIPT     (fBIDI | fARABIC | fHEBREW | fTHAI | fDEVANAGARI | fTAMIL | fCOMBINING | fDIGITSHAPE | fSURROGATE)

// windows\richedit\re30\_rtfconv.h
#define IsLC(_ch)			((Classify(_ch) & fLC))
#define IsXDigit(_ch)		((Classify(_ch) & fHX))
#define IsAlphaNum(_ch) 	((Classify(_ch) & fAlphaNum))
#define IsAlphaNumBlank(_ch) ((Classify(_ch) & (fAlphaNum + fBL)))

// windows\richedit\re30\_uspi.h
#define cli_Shape					(cli_pwgi | cli_psva | cli_pcluster)
#define cli_ShapePlace				(cli_Shape | cli_Place)

// windows\richedit\re30\cfpf.cpp
#define PFM_IGNORE	(PFM_OUTLINELEVEL | PFM_COLLAPSED | PFM_PARAFORMAT | PFM_BOX)

// windows\richedit\re30\clasifyc.cpp
#define IsSameNonFEClass(_c1, _c2)	(!(((_c1) ^ (_c2)) & WBF_CLASS))
#define IdeoTypes	  (IdeoKanaTypes | C3_IDEOGRAPH)

// windows\richedit\re30\hash.h
#define			MOD257_1(k) ((k) & 255)	// MOD (257 - 1)

// windows\richedit\re30\iaccess.cpp
#define HwndFromHWNDID(lId)         (HWND)((DWORD_PTR)(lId) & ~0x80000000)
#define HwndFromHWNDID(lId)         (HWND)((lId) & ~0x80000000)
#define IsHWNDID(lId)               ((lId) & 0x80000000)

// windows\richedit\re30\lbhost.cpp
#define LBSEL_DEFAULT (LBSEL_SELECT | LBSEL_NEWANCHOR | LBSEL_NEWCURSOR | LBSEL_RESET)

// windows\richedit\re30\rtfread.cpp
#define PFM_ALLRTF      (PFM_ALL2 | PFM_COLLAPSED | PFM_OUTLINELEVEL | PFM_BOX)

// windows\richedit\re30\winresrc.h
#define WVR_REDRAW         (WVR_HREDRAW | \
                            WVR_VREDRAW)
#define LBS_STANDARD          (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

// windows\richedit\re41\_cfpf.h
#define IsHeadingStyle(Style)	(Style <= STYLE_HEADING_1 && \
								 Style >= STYLE_HEADING_9)
#define IsKnownStyle(Style)		(IsHeadingStyle(Style) || Style == STYLE_NORMAL)
#define IsStyleCommand(Style)	((Style & 0xFF00) == STYLE_COMMAND)
#define	GetTabPos(tab)		((tab) & 0xFFFFFF)
#define	GetCellWidth(x)	((x) & 0xFFFFFF)
#define IsTopCell(x)	(((x) & fTopCell) != 0)
#define IsVerticalCell(x)	((x) & fVerticalCell)

// windows\richedit\re41\_edit.h
#define FBIDI		(FRTL | FARABIC | FHEBREW | FSYRIAC | FTHAANA | FDIGITSHAPE)
#define FFE2		(FJPN2 | FCHS2 | FCHT2 | FKOR2)
#define FCOMPLEX_SCRIPT	(FBIDI | FTHAI | FINDIC | FJAMO | FCOMBINING | FSURROGATE)

// windows\richedit\re41\_ime.h
#define TEST_ALL		(TEST_LEFT | TEST_RIGHT | TEST_TOP | TEST_BOTTOM)

// windows\richedit\re41\_msremsg.h
#define	EM_PRI_MSG					(WM_USER + 0x07000)

// windows\richedit\re41\_rtfconv.h
#define IsLC(_ch)			((Classify(_ch) & fLC))
#define IsASCIIAlpha(_ch)	((Classify(_ch) & fAlpha))
#define IsXDigit(_ch)		((Classify(_ch) & fHX))
#define IsAlphaNum(_ch) 	((Classify(_ch) & fAlphaNum))
#define IsAlphaNumBlank(_ch) ((Classify(_ch) & (fAlphaNum + fBL)))

// windows\richedit\re41\_uspi.h
#define cli_Shape					(cli_pwgi | cli_psva | cli_pcluster)
#define cli_ShapePlace				(cli_Shape | cli_Place)

// windows\richedit\re41\clasifyc.cpp
#define IsSameNonFEClass(_c1, _c2)	(!(((_c1) ^ (_c2)) & WBF_CLASS))
#define IdeoTypes	  (IdeoKanaTypes | C3_IDEOGRAPH)

// windows\richedit\re41\hash.h
#define			MOD257_1(k) ((k) & 255)	// MOD (257 - 1)

// windows\richedit\re41\iaccess.cpp
#define HwndFromHWNDID(lId)         (HWND)((DWORD_PTR)(lId) & ~0x80000000)
#define HwndFromHWNDID(lId)         (HWND)((lId) & ~0x80000000)
#define IsHWNDID(lId)               ((lId) & 0x80000000)

// windows\richedit\re41\lbhost.cpp
#define LBSEL_DEFAULT (LBSEL_SELECT | LBSEL_NEWANCHOR | LBSEL_NEWCURSOR | LBSEL_RESET)

// windows\richedit\re41\rtfread.cpp
#define	PFM_ALLRTF		(PFM_ALL2 | PFM_COLLAPSED | PFM_OUTLINELEVEL | PFM_BOX)

// windows\richedit\re41\winresrc.h
#define WVR_REDRAW         (WVR_HREDRAW | \
                            WVR_VREDRAW)
#define LBS_STANDARD          (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

// windows\winstate\cobra\utils\inc\strings.h
#define YesNoBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_YESNO|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define YesNoCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_YESNOCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define OkBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_OK|MB_ICONINFORMATION|MB_SETFOREGROUND,NULL)
#define OkCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_OKCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
#define RetryCancelBox(hwnd,ID) ResourceMessageBox(hwnd,ID,MB_RETRYCANCEL|MB_ICONQUESTION|MB_SETFOREGROUND,NULL)
```

