# Units, DPI, Timebases, And Coordinate Conversion

[Macros index](<macros.md>)

## Curated Candidates

```c
// shell\lib\util.cpp
#define _ROOTEDPIDL(pidlr)      (LPITEMIDLIST)(((LPBYTE)pidlr)+sizeof(IDREGITEM))

// shell\shdocvw\dochost.h
#define ADJUSTPROGRESSMAX(dw)   (PROGRESS_REBASE * (dw) )
#define ADJUSTPROGRESSPOS(dw)   ((dw) * PROGRESS_REBASE + ((_dwProgressBase * _dwProgressMax) / PROGRESS_REBASE))

// shell\osshell\fontfldr\fontext\t1instal\trans.c
#define ATMSCALE(v)  (((v)*31)/32)
#define IP(v,x1,x2,x1p,x2p)   /*lint -e776 */(short)((long)(v-x1)*(long)(x2p-x1p)/(long)(x2-x1)+(long)x1p)/*lint +e776*/

// enduser\netmeeting\av\codecs\dec\dech261\compress.c
#define Bpos_Y(h261, g, m) (h261->ImageType==IT_QCIF ? (g * 33) + (m % 33) \
                            : (g/2)*66 + (m % 11) + (g&1)*11 + (m/11) * 22)

// shell\browseui\emclient\regdb.cpp
#define BTOM(b, m)  ((b) ? (m) : 0)

// shell\shell32\about.c
#define BytesToK(pDW)   (*(pDW) = (*(pDW) + 512) / 1024)        // round up

// com\oleutest\letest\outline\outline.h
#define DEFFONTSIZE     ((DEFFONTPTSIZE*HIMETRIC_PER_INCH)/PTS_PER_INCH)

// printscan\print\drivers\usermode\msplot\plotter\plotters.h
#define DIVROUND(x,y)                   (((LONG)(x)+(LONG)((y)>>1))/(LONG)(y))
#define DIVRNDUP(x,y)                   (((LONG)(x)+(LONG)((y)-1))/(LONG)(y))

#define DMTOSPL(dm)                     ((LONG)(dm) * 100L)
#define SPLTODM(spl)                    (SHORT)DIVROUND(spl, 100)
#define MMTODM(mm)                      ((LONG)(mm) * 10L)

#define __PLOT_DPI                      (LONG)pPDev->pPlotGPC->PlotXDPI
#define _PLOT_DPI                       (LONG)pPlotGPC->PlotXDPI
#define _CURR_DPI                       (LONG)pPDev->lCurResolution

#define DMTOENGUNITS(pPDev, dm)         DIVROUND((dm)*_CURR_DPI, 254)
#define DMTOPLOTUNITS(pPlotGPC, dm)     DIVROUND((dm)*_PLOT_DPI, 254)

#define MMTOENGUNITS(pPDev, mm)         DMTOENGUNITS(pPDev, MMTODM(mm))
#define MMTOPLOTUNITS(pPlotGPC, mm)     DMTOPLOTUNITS(pPlotGPC, MMTODM(mm))

#define SPLTOENGUNITS(pPDev, spl)       DIVROUND((spl/100)*_CURR_DPI, 254)
#define SPLTOPLOTUNITS(pPlotGPC, spl)   DIVROUND((spl/100)*_PLOT_DPI, 254)

// shell\themes\themeui\util.cpp
#define DPI_SCALEX(nSizeX)          ((int) ((nSizeX) * dScaleX))
#define DPI_SCALEY(nSizeY)          ((int) ((nSizeY) * dScaleY))

// shell\themes\inc\utils.h
#define DPISCALE(val, DcDpi)  MulDiv(val, DcDpi, THEME_DPI)

// drivers\video\ms\cirrus\disp\gamma.c
#define FixedDiv(x,y)   (long) ((y==0) ? 0x7FFFFFFFL : ((x)*FIXEDFUDGE) / (y))

// multimedia\dshow\filters.ks\tvtuner\ctvtuner.h
#define FRAMETO100NS(FrameRate) ((REFERENCE_TIME)(LONG)((double)1e7/FrameRate))

// windows\core\ntgdi\fondrv\tt\mssipotf\fs\scale.c
#define FROUND( x, n, d, s ) \
        ((SHORTMUL (x, n) + (d)) >> s)

#define SROUND( x, n, d, halfd ) \
    (x < 0 ? -((SHORTMUL (-(x), (n)) + (halfd)) / (d)) : ((SHORTMUL ((x), (n)) + (halfd)) / (d)))

// shell\themes\themeui\custfont.cpp
#define GETPERCENT(dpi) ((dpi * 100 + 50) / 96)
#define GETDPI(percent) ((percent * 96 + 48) /100)

// multimedia\media\avi\avifile\aviview\aviview.c
#define GetScrollTime(hwnd) \
    (timeStart + muldiv32(GetScrollPos(hwnd, SB_HORZ), timeLength, SCROLLRANGE))

#define SetScrollTime(hwnd, time) SetScrollPos(hwnd, SB_HORZ, \
    (int)muldiv32((time) - timeStart, SCROLLRANGE, timeLength), TRUE)

// shell\osshell\accesory\notepad\npprint.c
#define  InchesToCM(x)  (((x) * 254L + 50) / 100)
#define  CMToInches(x)  (((x) * 100L + 127) / 254)

// drivers\video\ms\3dlabs\perm2\disp\hw.h
#define INTtoFIXED(i)   ((i) << 16)         // int to 16.16 fixed format
#define FIXEDtoINT(i)   ((i) >> 16)         // 16.16 fixed format to int
#define INTofFIXED(i)   ((i) & 0xffff0000)  // int part of 16.16
#define FRACTofFIXED(i) ((i) & 0xffff)      // fractional part of 16.16

#define FIXtoFIXED(i)   ((i) << 12)         // 12.4 to 16.16
#define FIXtoINT(i)     ((i) >> 4)          // 28.4 to 28

// multimedia\directx\applicationmanager\cominterface\win32api.h
#define KILOBYTES(a)                ((((a).HighPart & 0x3ff) << 22)||(((a).LowPart) >> 10))

// multimedia\dshow\filters\core\builder2\ks.h
#define NANOSECONDS 10000000
#define KSCONVERT_PERFORMANCE_TIME(Frequency, PerformanceTime) \
    ((((ULONGLONG)(ULONG)(PerformanceTime).HighPart * NANOSECONDS / (Frequency)) << 32) + \
    ((((((ULONGLONG)(ULONG)(PerformanceTime).HighPart * NANOSECONDS) % (Frequency)) << 32) + \
    ((ULONGLONG)(PerformanceTime).LowPart * NANOSECONDS)) / (Frequency)))

// drivers\video\ms\s3\disp\lines.h
#define LROUND(x, flRoundDown) (((x) + F/2 - ((flRoundDown) > 0)) >> 4)
#define F                     16
#define FLOG2                 4
#define LFLOOR(x)             ((x) >> 4)
#define FXFRAC(x)             ((x) & (F - 1))

// net\rras\ip\dvmrp\dvmrptimer.c
#define MAP_TO_BUCKET(dwBucket, ilTime) \
    dwBucket = (DWORD) (((ilTime)-g_TimerStruct.SyncTime) \
                        >> (TIMER_BUCKET_GRANULARITY_SHIFT+SEC_CONV_SHIFT)); \
    dwBucket = dwBucket>NUM_TIMER_BUCKETS-1? NUM_TIMER_BUCKETS-1:  dwBucket

// printscan\print\drivers\usermode\inc\pslib.h
#define MICRON_TO_POINT(micron)      MulDiv(micron, 72,  25400)
#define POINT_TO_MICRON(point)       MulDiv(point, 25400, 72)

// drivers\video\ms\s3\disp\hw.h
#define PACKXY(x, y)        (((x) << 16) | ((y) & 0xffff))
#define PACKXY_FAST(x, y)   (((x) << 16) | (y))

// windows\core\ntgdi\client\rectl.hxx
#define POINTL_TO_POINTS(ppts, pptl, cpt)            \
    {                                                \
        for (DWORD i = 0; i < (cpt); i++)            \
            ((PEPOINTS) (ppts))[i] = (pptl)[i];      \
    }

#define POINTS_TO_POINTL(pptl, ppts, cpt)            \
    {                                                \
        for (DWORD i = 0; i < (cpt); i++)            \
            ((PEPOINTL) (pptl))[i] = (ppts)[i];      \
    }

// shell\themes\uxtheme\loader.cpp
#define POINTS_DPI96(pts)   -MulDiv(pts, 96, 72)

// enduser\netmeeting\as\h\oe.h
#define RECT_FROM_RECTFX(dcr, rec)                                         \
                                if (rec.xRight < rec.xLeft)                  \
                                {                                            \
                                    dcr.left  = FXTOLFLOOR(rec.xRight);      \
                                    dcr.right = FXTOLCEILING(rec.xLeft);     \
                                }                                            \
                                else                                         \
                                {                                            \
                                    dcr.left  = FXTOLFLOOR(rec.xLeft);       \
                                    dcr.right = FXTOLCEILING(rec.xRight);    \
                                }                                            \
                                if (rec.yBottom < rec.yTop)                  \
                                {                                            \
                                    dcr.bottom= FXTOLCEILING(rec.yTop);      \
                                    dcr.top   = FXTOLFLOOR(rec.yBottom);     \
                                }                                            \
                                else                                         \
                                {                                            \
                                    dcr.top   = FXTOLFLOOR(rec.yTop);        \
                                    dcr.bottom= FXTOLCEILING(rec.yBottom);   \
                                }

#define POINT_FROM_POINTFIX(dcp, pnt) dcp.x = FXTOLROUND(pnt.x);  \
                                      dcp.y = FXTOLROUND(pnt.y)

// windows\core\ntgdi\fondrv\tt\mssipotf\fs\fontmath.h
#define ROUNDFIXTOINT( x )      (int16)((((Fixed) x) + ONEHALFFIX) >> 16)
#define ROUNDFIXED( x )         (((x) + (Fixed)ONEHALFFIX) & (Fixed)HIWORDMASK)
#define DOT6TOFIX(n)            ((Fixed) (n) << 10)
#define FIXEDTODOT6(n)          (F26Dot6) (((n) + ((1) << (9))) >> 10)
#define INTTOFIX(n)             ((Fixed) (n) << 16)
#define INTTODOT6(n)            ((F26Dot6) (n) << 6)

// shell\browseui\mediaband.cpp
#define SCALEX(x)   (_fHighDPI ? ((INT)(((float)(x))*_scaleX)) : (x))

#define SCALEY(x)   (_fHighDPI ? ((INT)(((float)(x))*_scaleY)) : (x))

// windows\core\ntcon\server\consrv.h
#define SCREEN_BUFFER_POINTER(X,Y,XSIZE,CELLSIZE) (((XSIZE * (Y)) + (X)) * (ULONG)CELLSIZE)

// multimedia\media\avi\mciavi32\graphic.h
#define TimeToMovie(t)         muldiv32(t, npMCI->dwRate, npMCI->dwScale*1000)
#define MovieToTime(l)         muldiv32(l, npMCI->dwScale*1000, npMCI->dwRate)
#define TimeToStream(psi, t)   muldiv32(t, psi->sh.dwRate,       psi->sh.dwScale*1000)
#define StreamToTime(psi, l)   muldiv32(l, psi->sh.dwScale*1000, psi->sh.dwRate)

// windows\core\ntgdi\client\csxobj.hxx
#define WORLD_TO_PAGE       ((COORD_WORLD << 8) + COORD_PAGE)
#define PAGE_TO_DEVICE      ((COORD_PAGE  << 8) + COORD_DEVICE)
#define METAFILE_TO_DEVICE  ((COORD_METAFILE << 8) + COORD_DEVICE)
#define WORLD_TO_DEVICE     ((COORD_WORLD << 8) + COORD_DEVICE)
#define DEVICE_TO_PAGE      ((COORD_DEVICE << 8) + COORD_PAGE)
#define DEVICE_TO_WORLD     ((COORD_DEVICE << 8) + COORD_WORLD)

// printscan\fax\inc\faxutil.h
#define SECONDS_PER_MINUTE  60

#define SECONDS_PER_HOUR    (SECONDS_PER_MINUTE * MINUTES_PER_HOUR)

#define SECONDS_PER_DAY     (MINUTES_PER_DAY * SECONDS_PER_MINUTE)

#define FILETIMETICKS_PER_SECOND    10000000    // 100 nanoseconds / second

#define FILETIMETICKS_PER_DAY       ((LONGLONG) FILETIMETICKS_PER_SECOND * (LONGLONG) SECONDS_PER_DAY)

// net\tcpip\driver\ipv4\ipmcast.h
#define SYS_UNITS_IN_ONE_MILLISEC   (1000 * 10)

// admin\netui\common\src\blt\blt\blttimer.cxx
#define TICKCOUNT_50_PERCENT  ( 1L << ( sizeof( ULONG ) * 8 - 1 ))

// ds\win32\ntcrypto\programs\keymigrt\systok.cpp
#define WSZ_BYTECOUNT(s)     (2 * wcslen(s) + 2)

// multimedia\opengl\toolkits\libmtk\mtk.h
#define SS_DEG_TO_RAD( a ) ( (a*PI) * ONE_OVER_180 )

#define SS_RAD_TO_DEG( a ) ( (a*180.0f) * ONE_OVER_PI )

// multimedia\directx\misc\dpf.h
        #define TIMEVAR(t)    DWORD t ## T; DWORD t ## N

        #define TIMEZERO(t)   t ## T = 0, t ## N = 0

        #define TIMESTART(t)  t ## T -= clock(), t ## N ++

        #define TIMESTOP(t)   t ## T += clock()

        #define TIMEFMT(t)    ((DWORD)(t) / clockrate()), (((DWORD)(t) * 1000 / clockrate())%1000)

        #define TIMEOUT(t)    if (t ## N) DPF(1, #t ": %ld calls, %ld.%03ld sec (%ld.%03ld)", t ## N, TIMEFMT(t ## T), TIMEFMT(t ## T / t ## N))
```

## Backlog

```c
// admin\activec\nodemgr\oncmenu.h
#define START_CRITSEC(critsec)                  \
        CSingleLock lock_##critsec( &critsec ); \
        try {                                   \
            lock_##critsec.Lock();

// admin\admt\common\commonlib\secobj.cpp
#define SDBUFFSIZE (sizeof (SECURITY_DESCRIPTOR) + 10000)

// admin\controls\smonctrl\timerng.cpp
#define dwTimeRangeClassStyle  (CS_HREDRAW | CS_VREDRAW)

// admin\darwin\src\inc\latebind.h
#define LIBLOAD(l) namespace l { static HINSTANCE LoadSystemLibrary(const ICHAR* szPath, bool& rfRetryNextTimeIfWeFailThisTime);

// admin\netui\common\hack\dos\pwin16.h
#define MAKEMPOINT(l)                   (*((MPOINT FAR *)&(l)))
#define MPOINT2POINT(mpt, pt)           (pt = *(POINT FAR *)&(mpt))
#define POINT2MPOINT(pt, mpt)           (mpt = *(MPOINT FAR *)&(pt))

// admin\netui\common\hack\dos\windows.h
#define MAKEPOINT(l)	    (*((POINT FAR*)&(l)))

// admin\netui\common\src\lmobj\lmobj\security.cxx
#define STANDARD_SID_SIZE  (sizeof(SID))
#define STANDARD_ACE_SIZE  (max(sizeof(ACCESS_ALLOWED_ACE),     \
                            max(sizeof(ACCESS_DENIED_ACE),      \
                            max(sizeof(SYSTEM_AUDIT_ACE),       \
                                sizeof(SYSTEM_ALARM_ACE)) ))    \
                            - sizeof(ULONG) + STANDARD_SID_SIZE)
#define STANDARD_ACL_SIZE  (sizeof(ACL) + STANDARD_ACE_SIZE)

// admin\netui\llsmgr\llsimp.h
#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( LSA_OBJECT_ATTRIBUTES );      \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }

// admin\netui\macprint\spooler\macps.h
#define EXECUTE_OTI_HACK(_StartTime)    ( ((GetTickCount() - (_StartTime)) > OTI_EOF_LIMIT) ? \
                                            TRUE : FALSE )

// admin\services\sched\job\security.cxx
#define TASK_ALL    (GENERIC_READ    | GENERIC_WRITE |  \
                     GENERIC_EXECUTE | GENERIC_ALL)

// admin\services\sched\svc_core\atsec.cxx
#define AT_JOB_ALL_ACCESS   (STANDARD_RIGHTS_REQUIRED   |   \
                             AT_JOB_ADD                 |   \
                             AT_JOB_DEL                 |   \
                             AT_JOB_ENUM                |   \
                             AT_JOB_GET_INFO)

// admin\snapin\filemgmt\lsastuff.cpp
#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }

// admin\snapin\filemgmt\svchelp.h
#define IDH_213_291	291	// Recovery: "&Second attempt:" (Static)

// admin\snapin\mtfrmwk\treedata.h
#define DECLARE_MENU(theClass) \
class theClass \
{ \
public: \
	static LPCONTEXTMENUITEM2 GetContextMenuItem() { return GetMenuMap()->ctxMenu; }; \
	static MENUMAP* GetMenuMap(); \
};
#define BEGIN_MENU(theClass) \
	 MENUMAP* theClass::GetMenuMap() {
#define END_MENU \
		static MENUMAP menuMap = { dataRes, ctx }; \
		return &menuMap; }
#define END_TOOLBAR_MAP() \
  return hr; \
}

// admin\snapin\wsecmgr\addgrp.h
#define IsSpace( x ) ((x) == L' ' || ((x) >= 0x09 && (x) <= 0x0D))

// admin\snapin\wsecmgr\chklist.h
#define CLST_CHECKDISABLED  (CLST_CHECKED | CLST_DISABLED)
#define CLM_SETCOLUMNWIDTH  (WM_USER + 1)   // lParam = width (dlg units) of a check column (default=32)
#define CLM_SETSTATE        (WM_USER + 4)   // wParam = row/column, lParam = state
#define CLM_SETITEMDATA     (WM_USER + 6)   // wParam = row, lParam = item data
#define CLM_RESETCONTENT    (WM_USER + 8)   // no parameters
#define CLM_SETTOPINDEX     (WM_USER + 11)  // wParam = index of new top row
#define CLM_ENSUREVISIBLE   (WM_USER + 12)  // wParam = index of item to make fully visible

// admin\snapin\wsecmgr\cookie.cpp
#define PROFILE_DEFAULT(X,Y) ((pspi && (pspi->X != SCE_NO_VALUE)) ? pspi->X : Y)
#define PROFILE_KERB_DEFAULT(X,Y) ((pspi && pspi->pKerberosInfo && (pspi->pKerberosInfo->X != SCE_NO_VALUE)) ? pspi->pKerberosInfo->X : Y)

// admin\snapin\wsecmgr\cprivs.cpp
#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }

// admin\snapin\wsecmgr\getuser.h
#define SCE_SHOW_SCOPE_ALL        (SCE_SHOW_SCOPE_LOCAL|SCE_SHOW_SCOPE_DOMAIN|SCE_SHOW_SCOPE_DIRECTORY)

// admin\snapin\wsecmgr\hidwnd.cpp
#define SCEM_UPDATE_ALL_VIEWS         (WM_APP+101)
#define SCEM_UPDATE_ITEM              (WM_APP+102)
#define SCEM_REFRESH_POLICY           (WM_APP+103)
#define SCEM_RELOAD_LOCATION          (WM_APP+104)
#define SCEM_SET_PROFILE_DESC         (WM_APP+105)
#define SCEM_LOCK_ANAL_PANE           (WM_APP+106)
#define SCEM_SELECT_SCOPE_ITEM        (WM_APP+108)

// admin\snapin\wsecmgr\hlpids.h
#define IDH_183_350	22937783	// Rename Administrator Account: "C&hange template setting to" (Button)
#define IDH_170_304	19923114	// Audit File Access : "E&xclude from future configurations and analyses" (Button)
#define IDH_169_304	19923113	// Secure System Objects: "E&xclude from future configurations and analyses" (Button)
#define IDH_168_304	19923112	// Edit Numeric Attribute: "E&xclude from future configurations and analyses" (Button)
#define IDH_167_304	19923111	// Rename Administrator Account: "E&xclude from future configurations and analyses" (Button)
#define IDH_198_304	19923142	// Analysis Areas: "E&xclude from future configurations and analyses" (Button)
#define IDH_177_352	23068849	// Select Registry Key: "&Registry:" (Static)
#define IDH_173_260	17039533	// Untitled: "&View..." (Button)
#define IDH_169_237	15532201	// Secure System Objects: "&Enabled" (Button)
#define IDH_182_237	15532214	// Edit Enable/Disable Attribute: "&Enabled" (Button)
#define IDH_227_237	15532259	// Secure System Objects: "&Enabled" (Button)
#define IDH_186_353	23134394	// Save Computer Templates: "&Select to save:" (Static)
#define IDH_173_261	17105069	// Untitled: "View/&Edit..." (Button)
#define IDH_169_238	15597737	// Secure System Objects: "&Disabled" (Button)
#define IDH_182_238	15597750	// Edit Enable/Disable Attribute: "&Disabled" (Button)
#define IDH_227_238	15597795	// Secure System Objects: "&Disabled" (Button)
#define IDH_197_311	20381893	// File and Registry Object Configuration: "&Edit Security..." (Button)
#define IDH_170_243	15925418	// Audit File Access : "Audit &successful attempts" (Button)
#define IDH_226_243	15925474	// Audit File Access : "Audit &successful attempts" (Button)
#define IDH_216_336	22020312	// Import Template: "&Browse ..." (Button)
#define IDH_215_336	22020311	// Perform Analysis: "&Browse ..." (Button)
#define IDH_212_336	22020308	// Configure System: "&Browse ..." (Button)
#define IDH_198_313	20512966	// Analysis Areas: "&Edit Security..." (Button)
#define IDH_170_244	15990954	// Audit File Access : "Audit &failed attempts" (Button)
#define IDH_226_244	15991010	// Audit File Access : "Audit &failed attempts" (Button)
#define IDH_191_337	22085823	// Untitled: "E&xclude from future configurations and analyses" (Button)
#define IDH_198_314	20578502	// Analysis Areas: "&View Security..." (Button)
#define IDH_218_361	23658714	// Template Description: "&Description:" (Static)
#define IDH_225_361	23658721	// New Template: "&Description" (Button)
#define IDH_191_246	16122047	// Untitled: "&Add..." (Button)
#define IDH_214_246	16122070	// Untitled: "A&dd..." (Button)
#define IDH_231_246	16122087	// Untitled: "&Add..." (Button)
#define IDH_225_362	23724257	// New Template: "&Template Name:" (Button)
#define IDH_180_271	17760436	// Audit File Access: "Audit &successful attempts" (Button)
#define IDH_180_272	17825972	// Audit File Access: "Audit &failed attempts" (Button)
#define IDH_209_203	13304017	// Untitled: "Security Configuration & Analysis v1.0" (Static)

// admin\snapin\wsecmgr\servperm.cpp
#define FILE_GENERIC_READ_      (FILE_GENERIC_READ    & ~SYNCHRONIZE)
#define FILE_GENERIC_WRITE_     (FILE_GENERIC_WRITE   & ~(SYNCHRONIZE | READ_CONTROL))
#define FILE_GENERIC_EXECUTE_   (FILE_GENERIC_EXECUTE & ~SYNCHRONIZE)
#define FILE_GENERIC_ALL_       (FILE_ALL_ACCESS      & ~SYNCHRONIZE)
#define FILE_GENERAL_PUBLISH    (FILE_GENERIC_READ_  | FILE_GENERIC_WRITE_ | FILE_GENERIC_EXECUTE_)
#define FILE_GENERAL_DEPOSIT    (FILE_GENERIC_WRITE_ | FILE_GENERIC_EXECUTE_)
#define FILE_GENERAL_READ_EX    (FILE_GENERIC_READ_  | FILE_GENERIC_EXECUTE_)
#define SERVICE_GENERIC_EXECUTE     (STANDARD_RIGHTS_EXECUTE |\
                                     SERVICE_START |\
                                     SERVICE_STOP |\
                                     SERVICE_PAUSE_CONTINUE)
#define SERVICE_GENERIC_WRITE       (STANDARD_RIGHTS_WRITE |\
                                     SERVICE_CHANGE_CONFIG )

// admin\snapin\wsecmgr\servperm.h
#define END_SEC_COM_MAP() {NULL, 0, 0}}; return &_entries[1];}
#define END_SEC_COM_MAP() {NULL, 0, 0}}; return _entries;}

// admin\snapin\wsecmgr\snapmgr.cpp
#define CHECK_KERBEROS if( !pLocalInfo->pKerberosInfo ||\
                           !pLocalDeltaInfo->pKerberosInfo ||\
                           !pEffectiveInfo->pKerberosInfo ){\
                              break;\
                       }

// admin\snapin\wsecmgr\snapmgr.h
#define DECLARE_MENU(theClass) \
class theClass \
{ \
public: \
    static LPCONTEXTMENUITEM GetContextMenuItem() { return GetMenuMap()->ctxMenu; }; \
    static MENUMAP* GetMenuMap(); \
};
#define BEGIN_MENU(theClass) \
     MENUMAP* theClass::GetMenuMap() {
#define END_MENU \
        static MENUMAP menuMap = { dataRes, ctx }; \
        return &menuMap; }

// admin\snapin\wsecmgr\uithread.h
#define SCEM_APPLY_PROFILE     (WM_APP+2)
#define SCEM_ASSIGN_PROFILE    (WM_APP+3)
#define SCEM_ANALYZE_PROFILE   (WM_APP+4)
#define SCEM_DESCRIBE_PROFILE  (WM_APP+6)
#define SCEM_DESCRIBE_LOCATION (WM_APP+7)
#define SCEM_NEW_CONFIGURATION (WM_APP+9)
#define SCEM_ADD_PROPSHEET     (WM_APP+10)
#define SCEM_CREATE_MODELESS_SHEET  (WM_APP+12)
#define SCEM_DESTROY_WINDOW         (WM_APP+13)

// admin\snapin\wsecmgr\util.cpp
#define INCBUFFER(sz)\
    if(uRead){\
        (sz)++;\
        uRead--;\
    } else {\
        pStm->Read(szRead, 256 * sizeof(TCHAR), &uRead);\
        uRead = uRead/sizeof(TCHAR);\
        (sz) = szRead;\
    }\
    iTotalRead++;

// admin\wmi\wbem\common\wdmlib\wmi\wmium.h
#define WmiInsertTimestamp(WnodeHeader) \
    GetSystemTimeAsFileTime((FILETIME *)&((PWNODE_HEADER)WnodeHeader)->TimeStamp)

// admin\wmi\wbem\common\wdmlib\wmicom.h
#define SIZEOFWBEMDATETIME sizeof(WCHAR)*25

// admin\wmi\wbem\providers\snmpprovider\common\sclcomm\include\window.h
#define SNMP_WM_TIMER			(WM_USER+7)

// admin\wmi\wbem\sdk\activex\test\controls\nsetest\stdafx.h
#define IMPLEMENT_OLECREATE2(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	AFX_DATADEF COleObjectFactory class_name::factory(class_name::guid, \
		RUNTIME_CLASS(class_name), TRUE, _T(external_name)); \
	const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } };

// admin\wmi\wbem\sdk\activex\test\controls\svtest\stdafx.h
#define IMPLEMENT_OLECREATE2(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	AFX_DATADEF COleObjectFactory class_name::factory(class_name::guid, \
		RUNTIME_CLASS(class_name), TRUE, _T(external_name)); \
	const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } };

// admin\wmi\wbem\sdk\framedyn\private\stopwatch.h
    #define PROVIDER_INSTRUMENTATION_START(pmc, timer) \
        if ( pmc && pmc->pStopWatch) \
            pmc->pStopWatch->Start(timer);
    #define PROVIDER_INSTRUMENTATION_START2(pStopWatch, timer) \
        if (pStopWatch) \
            pStopWatch->Start(timer);

// admin\wmi\wbem\shell\atlui\wmicntl\principal.h
#define VALID_ROOTSEC_STYLE (ACL_INSTANCE_WRITE |\
								ACL_CLASS_WRITE | ACL_WRITE_DAC)

// admin\wmi\wbem\winmgmt\ess3\eventrep.cpp
#define SET_SECOND_OBJECT \
        {  \
            nObjects = 2; \
            aEmbedded[1] = (IWbemClassObject*)V_EMBEDDED_OBJECT(&vEmbed); \
            aEmbedded[1]->AddRef(); \
            VariantClear(&vEmbed); \
        }

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\noncomtest\include\atlddx.h
#define END_DDX_MAP() \
		return TRUE; \
	}

// com\mobile\sens\conn\sensapi\sensapi.hxx
#define RequestLock()       EnterCriticalSection(&gSensapiLock)

// com\mobile\sens\conn\senssvc\sensutil.hxx
#define RequestSensLock()       EnterCriticalSection(&gSensLock)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\atoms.c
#define Atom_EnterCS(this)    EnterCriticalSection(&(this)->cs)
#define Atom_LeaveCS(this)    LeaveCriticalSection(&(this)->cs)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\brfprv.h
#define UB_CHECKING     (UB_CHECKAVI | UB_NOPROGRESS | UB_TIMER)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\cache.c
#define Cache_EnterCS(this)    EnterCriticalSection(&(this)->cs)
#define Cache_LeaveCS(this)    LeaveCriticalSection(&(this)->cs)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\cbs.c
#define CBS_EnterCS()    EnterCriticalSection(&g_cacheCBS.cs)
#define CBS_LeaveCS()    LeaveCriticalSection(&g_cacheCBS.cs)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\cpath.c
#define CPATH_EnterCS()    EnterCriticalSection(&g_cacheCPATH.cs)
#define CPATH_LeaveCS()    LeaveCriticalSection(&g_cacheCPATH.cs)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\crl.c
#define CRL_EnterCS()    EnterCriticalSection(&g_cacheCRL.cs)
#define CRL_LeaveCS()    LeaveCriticalSection(&g_cacheCRL.cs)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\port32.h
#define MAKEPOINTS(l)     (*((POINTS FAR*)&(l)))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\shellp.h
#define SVM_GETANCHORPOINT              (WM_USER + 3)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\port32.h
#define MAKEPOINTS(l)     (*((POINTS *)&(l)))

// com\ole32\common\cruntime\cruntime.h
#define _INTSIZEOF(n)    ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define _VA_START(ap,v) ap = (va_list)&v + _INTSIZEOF(v)

// com\ole32\ih\exports.hxx
#define API_CoFileTimeToDosDateTime             (API_NAMETABLE|(API_START+20))
#define API_CoDosDateTimeToFileTime             (API_NAMETABLE|(API_START+21))
#define API_CoFileTimeNow                       (API_NAMETABLE|(API_START+22))
#define API_StgSetTimes                         (API_NAMETABLE|(API_START+33))

// com\ole32\olethunk\ole16\inc\windows.h
#define MAKEPOINT(l)	    (*((POINT FAR*)&(l)))

// com\ole32\stg\async\layout\laylkb.cxx
#define TAKE_CS CSafeCriticalSection scs(&_cs);

// com\ole32\stg\h\dfmsp.hxx
#define P_COORD(f)      ((f) & DF_COORD)

// com\oleutest\act\client\client.cxx
#define STOP_CLOCK      QueryPerformanceCounter(&liStop); \
                        liElapsedTime.QuadPart += liStop.QuadPart - liStart.QuadPart

// com\oleutest\act\tstsvc\client.cxx
#define STOP_CLOCK      QueryPerformanceCounter(&liStop); \
                        liElapsedTime.QuadPart += liStop.QuadPart - liStart.QuadPart

// com\oleutest\letest\ole2ui\suminfo.h
#define cbNewSummaryInfo(nSection) (sizeof(SUMMARYINFO)-sizeof(SECTION)+sizeof(PROPSETLIST)*((nSection)-1))
#define cbNewSection(nPropIds) (sizeof(SECTION)-sizeof(PROPVALUE)+sizeof(PROPIDLIST)*((nPropIds)-1))

// com\rpc\runtime\epmap\local.h
#define  EnterSem()  EnterCriticalSection(&EpCritSec)
#define  LeaveSem()  LeaveCriticalSection(&EpCritSec)
#define EnLinkContext(p)                        \
                                                \
            (PSAVEDCONTEXT)                     \
            Link(                               \
                (PIENTRY *)(&GlobalContextList),\
                (PIENTRY)(p)                    \
                )
#define UnLinkContext(p)                        \
                                                \
            (PSAVEDCONTEXT)                     \
            UnLink(                             \
                (PIENTRY *)&GlobalContextList,  \
                (PIENTRY) (p)                   \
                )
#define MAKEGLOBALEPID(x,y)   ( ( ((x) &0xFF000000L) | ((y) & 0x00FFFFFFL) ) )

// com\rpc\runtime\exts\rpcexts.hxx
#define GET_RPC_VAR(VarName) \
    fUseTypeInfo ? GetVar("RPCRT4!"#VarName) : VarName
#define GET_TYPE_SIZE(Type, TypeName) \
    fUseTypeInfo ? GetTypeSize(#TypeName) : sizeof(Type)

// com\rpc\runtime\mtrt\bcache.cxx
#define INC_STAT(x) InterlockedIncrement(&x)

// com\rpc\runtime\mtrt\dgclnt.hxx
#define  DG_CCALL_NOT_ACTIVE ((DG_CCALL *) (~0))

// com\rpc\runtime\mtrt\handle.hxx
#define CALL_TYPE (DG_CCALL_TYPE \
                  | DG_SCALL_TYPE \
                  | OSF_CCALL_TYPE \
                  | OSF_SCALL_TYPE \
                  | LRPC_CCALL_TYPE \
                  | LRPC_SCALL_TYPE \
                  | DG_CALLBACK_TYPE)
#define BINDING_HANDLE_TYPE (OSF_BINDING_HANDLE_TYPE \
                            | DG_BINDING_HANDLE_TYPE \
                            | LRPC_BINDING_HANDLE_TYPE \
                            | SVR_BINDING_HANDLE_TYPE )
#define CCALL_TYPE (DG_CCALL_TYPE \
                  | OSF_CCALL_TYPE \
                  | LRPC_CCALL_TYPE)
#define SCALL_TYPE (DG_SCALL_TYPE    \
                  | DG_CALLBACK_TYPE \
                  | OSF_SCALL_TYPE   \
                  | LRPC_SCALL_TYPE )
#define NOT_MULTIPLE_OF_EIGHT(_x_) (_x_ & 0x00000007L)

// com\rpc\runtime\mtrt\lpcsvr.hxx
#define LrpcSetEndpoint(Endpoint) (\
    GlobalLrpcServer->SetEndpoint(Endpoint))
#define LrpcGetEndpoint(Endpoint) (\
    GlobalLrpcServer->GetEndpoint(Endpoint))
#define SERVERKEY(_x_) ((_x_) & 0x80000000)
#define INITMSG(LrpcMessage, CId, Cbd, MId) \
    (LrpcMessage)->LpcHeader.ClientId = ClientIdToMsgClientId(CId) ;\
    (LrpcMessage)->LpcHeader.CallbackId = Cbd ;\
    (LrpcMessage)->LpcHeader.MessageId = MId
#define AllocateMessage() ((LRPC_MESSAGE *) RpcAllocateBuffer(sizeof(LRPC_MESSAGE)))

// com\rpc\runtime\mtrt\osfclnt.hxx
#define InqTransCConnection(RpcTransportConnection) \
    ((OSF_CCONNECTION *) \
            ((char *) RpcTransportConnection - sizeof(OSF_CCONNECTION)))
#define TransConnection() ((RPC_TRANSPORT_CONNECTION) \
                                       ((char *) this+sizeof(OSF_CCONNECTION)))
#define TransResolverHint() ((void *) ((char *) this+sizeof(OSF_CASSOCIATION)))

// com\rpc\runtime\mtrt\osfsvr.hxx
#define InqTransAddress(RpcTransportAddress) \
    ((OSF_ADDRESS *) \
            ((char *) RpcTransportAddress - sizeof(OSF_ADDRESS)))
#define InqTransSConnection(RpcTransportConnection) \
    ((OSF_SCONNECTION *) \
            ((char *) RpcTransportConnection - sizeof(OSF_SCONNECTION)))
#define InqTransSCall(RpcSourceContext) \
    ((OSF_SCALL *) ((char *) RpcSourceContext - sizeof(OSF_SCALL)))

// com\rpc\runtime\trans\common\mqtrans.hxx
#define MQLocateBegin(ctx, r, col, s, e) \
    g_pMqApi->pMQLocateBegin(ctx, r, col, s, e)
#define MQLocateNext(e, p, pv) \
    g_pMqApi->pMQLocateNext(e, p, pv)
#define MQLocateEnd(e) \
    g_pMqApi->pMQLocateEnd(e)
#define MQInstanceToFormatName(g, f, l) \
    g_pMqApi->pMQInstanceToFormatName(g, f, l)
#define MQOpenQueue(f, a, s, q) \
    g_pMqApi->pMQOpenQueue(f, a, s, q)
#define MQReceiveMessage(s, ti, a, p, o, cb, cr, tr) \
    g_pMqApi->pMQReceiveMessage(s, ti, a, p, o, cb, cr, tr)
#define MQPathNameToFormatName(p, f, l) \
    g_pMqApi->pMQPathNameToFormatName(p, f, l)
#define MQCreateQueue(s, p, f, l) \
    g_pMqApi->pMQCreateQueue(s, p, f, l)
#define MQGetMachineProperties(m, g, p) \
    g_pMqApi->pMQGetMachineProperties(m, g, p)
#define MQGetQueueProperties(f, p) \
    g_pMqApi->pMQGetQueueProperties(f, p)
#define MQSetQueueProperties(f, p) \
    g_pMqApi->pMQSetQueueProperties(f, p)

// com\rpc\runtime\trans\common\wswrap.hxx
#define TryUsingAfd() if (InterlockedCompareExchange(&TriedUsingAfd, 1, 0) == 0) TryUsingAfdProc()

// com\rpc\runtime\trans\rpcproxy\filter.h
#define  CHUNK_PREFIX_SIZE               (sizeof( "XXXXXXXX\r\n" ) - 1)
#define  CHUNK_SUFFIX_SIZE               (sizeof( "\r\n" ) - 1)
#define HEX_DIGIT_VALUE(chex)                                   \
                  (  (((chex) >= CHAR_0) && ((chex) <= CHAR_9)) \
                     ? ((chex) - CHAR_0)                        \
                     : ((chex) - CHAR_A + 10) )

// drivers\input\hidport\kbdhid\read.c
#define KbdHid_RestartTimer(HidDevice)           \
    KeSetTimerEx (&(HidDevice)->AutoRepeatTimer, \
                   (HidDevice)->AutoRepeatDelay, \
                   (HidDevice)->AutoRepeatRate,  \
                  &(HidDevice)->AutoRepeatDPC);
#define KbdHid_CancelTimer(HidDevice) \
    KeCancelTimer (&(HidDevice)->AutoRepeatTimer);

// drivers\input\mouclass\mouclass.h
#define SHOULD_SEND_WAITWAKE(port) (WAITWAKE_SUPPORTED(port) && \
                                    !WAITWAKE_ON(port)       && \
                                    MouseClassCheckWaitWakeEnabled(port))

// drivers\input\pnpi8042\i8042prt.h
#define CRASH_BOTH_TIMES (CRASH_FIRST_TIME | CRASH_SECOND_TIME)

// drivers\input\pnpi8042\moupnp.c
#define MOUSE_INIT_POLLED(MouseExtension)                           \
        {                                                           \
            KeInitializeDpc(&MouseExtension->EnableMouse.Dpc,       \
                            (PKDEFERRED_ROUTINE) I8xMouseEnableDpc, \
                            MouseExtension);                        \
            KeInitializeTimerEx(&MouseExtension->EnableMouse.Timer, \
                                SynchronizationTimer);              \
            MouseExtension->InitializePolled = TRUE;                \
        }
#define MOUSE_INIT_INTERRUPT(MouseExtension)                        \
        {                                                           \
            KeInitializeDpc(&MouseExtension->ResetMouse.Dpc,        \
                            (PKDEFERRED_ROUTINE) I8xMouseResetTimeoutProc,  \
                            MouseExtension);                        \
            KeInitializeTimer(&MouseExtension->ResetMouse.Timer);   \
                MouseExtension->InitializePolled = FALSE;           \
        }

// drivers\smartcrd\gempc430\timer.h
#define DELAY(t)\
{if(t){CTimer* timer = kernel->createTimer(NotificationTimer);\
	if(ALLOCATED_OK(timer)) {timer->delay(t);\
timer->dispose();}}}

// drivers\smartcrd\inc\smclib.h
#define SmartcardLockDevice(SmartcardExtension) EnterCriticalSection(&(SmartcardExtension)->OsData->CritSect)
#define SmartcardUnlockDevice(SmartcardExtension) LeaveCriticalSection(&(SmartcardExtension)->OsData->CritSect)

// drivers\storage\disk\disk.c
#define DiskCompareGuid(_First,_Second) \
    (memcmp ((_First),(_Second), sizeof (GUID)))

// drivers\storage\diskperf\diskperf.c
#define DiskPerfGetClock(a, b) KeQuerySystemTime(&(a))

// drivers\storage\iscsiprt\client\port.h
#define WaitForOneSecond() {                                            \
                                                                        \
                             LARGE_INTEGER delayTime;                   \
                             delayTime.QuadPart = -10000000L;           \
                             KeDelayExecutionThread( KernelMode,        \
                                                     FALSE,             \
                                                     &delayTime);       \
                           }

// drivers\storage\iscsiprt\inc\iscsi.h
#define DelayThreadExecution(x) {                       \
                                                        \
             LARGE_INTEGER delayTime;                   \
             delayTime.QuadPart = -10000000L * x;       \
             KeDelayExecutionThread( KernelMode,        \
                                     FALSE,             \
                                     &delayTime);       \
        }

// drivers\storage\partmgr\partmgr.h
#define PmWmiGetClock(a, b) KeQuerySystemTime(&(a))

// drivers\storage\port\scsi\miniport\hipoint\hpt3xx\inc\hptioctl.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// drivers\storage\port\scsi\miniport\hipoint\hpt3xx\winnt\arraydat.h
#define DEVICE_MODE_SET(x) ((x & 0xFFFFFF00)==HPT_MODE_SET)

// drivers\storage\port\scsi\miniport\hipoint\hpt3xx\winnt\atapi.h
#define IDENTIFY_DATA_SIZE sizeof(IDENTIFY_DATA2)

// drivers\storage\port\scsi\miniport\hipoint\hpt3xx\winnt\forwin.h
#define ARG_IDENTIFY    , (PUSHORT)&Identify
#define OutPort(x, y)     ScsiPortWritePortUchar((PUCHAR)(x), y)
#define InPort(x)         ScsiPortReadPortUchar((PUCHAR)(x))
#define RepINS(x,y,z)     ScsiPortReadPortBufferUshort(&x->Data, (PUSHORT)y, z)
#define RepOUTS(x,y,z)    ScsiPortWritePortBufferUshort(&x->Data, (PUSHORT)y, z)
#define IS_RDP(OperationCode)\
							 ((OperationCode == SCSIOP_ERASE)||\
							 (OperationCode == SCSIOP_LOAD_UNLOAD)||\
							 (OperationCode == SCSIOP_LOCATE)||\
							 (OperationCode == SCSIOP_REWIND) ||\
							 (OperationCode == SCSIOP_SPACE)||\
							 (OperationCode == SCSIOP_SEEK)||\
							 (OperationCode == SCSIOP_WRITE_FILEMARKS))
#define OS_Identify(pDev)  ScsiPortMoveMemory((char *)&pDev->IdentifyData,\
						(char *)&Identify, sizeof(IDENTIFY_DATA2))
#define OS_Reset_Channel(pChan) \
								AtapiResetController(pChan->HwDeviceExtension,Srb->PathId);
#define WIN_NextRequest(pChan) { pChan->CurrentSrb = NULL;  \
							   CheckNextRequest(pChan);}

// drivers\storage\port\scsi\miniport\hipoint\hpt3xx\winnt\global.h
#define GetErrorCode(IOPort)         (UCHAR)InPort((PUCHAR)&IOPort->Data+1)
#define SetFeaturePort(IOPort,x)     OutPort((PUCHAR)&IOPort->Data+1, x)
#define SetCylinderLow(IOPort,x)         OutPort(&IOPort->CylinderLow, x)
#define SetCylinderHigh(IOPort,x)    OutPort(&IOPort->CylinderHigh, x)
#define SelectUnit(IOPort,UnitId)    OutPort(&IOPort->DriveSelect, (UCHAR)(UnitId))
#define GetCurrentSelectedUnit(IOPort) (UCHAR)InPort(&IOPort->DriveSelect)
#define IssueCommand(IOPort,Cmd)     OutPort(&IOPort->Command, (UCHAR)Cmd)

// drivers\storage\port\scsi\miniport\hipoint\hpt3xx\winnt\hptchip.h
#define CLK50_PIO370     (CTRL_ENA370(PIO_370MODE)|CMD_PRE370(5)|CMD_LOW370(15)|CMD_HIGH370(10))
#define CLK50_370PIO0    (CLK50_PIO370|DATA_PRE370(3)|DATA_LOW370(8)|DATA_HIGH370(10))
#define CLK50_370PIO1    (CLK50_PIO370|DATA_PRE370(3)|DATA_LOW370(6)|DATA_HIGH370(5))
#define CLK50_370PIO2    (CLK50_PIO370|DATA_PRE370(2)|DATA_LOW370(5)|DATA_HIGH370(4))
#define CLK50_370PIO3    (CLK50_PIO370|DATA_PRE370(2)|DATA_LOW370(4)|DATA_HIGH370(3))
#define CLK50_370PIO4    (CLK50_PIO370|DATA_PRE370(2)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK50_DMA370     (CTRL_ENA370(DMA_370MODE)|CMD_PRE370(1)|CMD_LOW370(4)|CMD_HIGH370(1))
#define CLK50_370DMA0    (CLK50_DMA370|DATA_PRE370(2)|DATA_LOW370(14)|DATA_HIGH370(10))
#define CLK50_370DMA1    (CLK50_DMA370|DATA_PRE370(2)|DATA_LOW370(5)|DATA_HIGH370(4))
#define CLK50_370DMA2    (CLK50_DMA370|DATA_PRE370(2)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK50_UDMA370    (CTRL_ENA370(UDMA_370MODE)|CMD_PRE370(1)|CMD_LOW370(4)|CMD_HIGH370(1))
#define CLK50_370UDMA0   (CLK50_UDMA370|UDMA_CYCLE370(6)|DATA_LOW370(14)|DATA_HIGH370(10))
#define CLK50_370UDMA1   (CLK50_UDMA370|UDMA_CYCLE370(5)|DATA_LOW370(5)|DATA_HIGH370(4))
#define CLK50_370UDMA2   (CLK50_UDMA370|UDMA_CYCLE370(3)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK50_370UDMA3   (CLK50_UDMA370|UDMA_CYCLE370(3)|DATA_PRE370(2)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK50_370UDMA4   (CLK50_UDMA370|UDMA_CYCLE370(11)|DATA_PRE370(2)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK50_370UDMA5   (CLK50_UDMA370|UDMA_CYCLE370(1)|DATA_PRE370(2)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK33_PIOCMD370  (CTRL_ENA370(PIO_370MODE)|CMD_PRE370(3)|CMD_LOW370(10)|CMD_HIGH370(7))
#define CLK33_370PIO0    (CLK33_PIOCMD370|DATA_PRE370(2)|DATA_LOW370(10)|DATA_HIGH370(7))
#define CLK33_370PIO1    (CLK33_PIOCMD370|DATA_PRE370(2)|DATA_LOW370(9)|DATA_HIGH370(3))
#define CLK33_370PIO2    (CLK33_PIOCMD370|DATA_PRE370(1)|DATA_LOW370(5)|DATA_HIGH370(3))
#define CLK33_370PIO3    (CLK33_PIOCMD370|DATA_PRE370(1)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK33_370PIO4    (CLK33_PIOCMD370|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(1))
#define CLK33_DMACMD370  (CTRL_ENA370(DMA_370MODE)|CMD_PRE370(1)|CMD_LOW370(3)|CMD_HIGH370(6))
#define CLK33_370DMA0    (CLK33_DMACMD370|DATA_PRE370(1)|DATA_LOW370(9)|DATA_HIGH370(7))
#define CLK33_370DMA1    (CLK33_DMACMD370|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(3))
#define CLK33_370DMA2    (CLK33_DMACMD370|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(1))
#define CLK33_UDMACMD370 (CTRL_ENA370(UDMA_370MODE)|CMD_PRE370(1)|CMD_LOW370(3)|CMD_HIGH370(1))
#define CLK33_370UDMA0   (CLK33_UDMACMD370|UDMA_CYCLE370(4)|DATA_PRE370(1)|DATA_LOW370(9)|DATA_HIGH370(7))
#define CLK33_370UDMA1   (CLK33_UDMACMD370|UDMA_CYCLE370(3)|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(3))
#define CLK33_370UDMA2   (CLK33_UDMACMD370|UDMA_CYCLE370(2)|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(1))
#define CLK33_370UDMA3   (CLK33_UDMACMD370|UDMA_CYCLE370(11)|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(1))
#define CLK33_370UDMA4   (CLK33_UDMACMD370|UDMA_CYCLE370(1)|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(1))
#define CLK33_370UDMA5   (CLK33_UDMACMD370|UDMA_CYCLE370(1)|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH(1))
#define CLK50_PIO370     (CTRL_ENA370(PIO_370MODE)|CMD_PRE370(5)|CMD_LOW370(15)|CMD_HIGH370(10))
#define CLK50_370PIO0    (CLK50_PIO370|DATA_PRE370(3)|DATA_LOW370(16)|DATA_HIGH370(11))
#define CLK50_370PIO1    (CLK50_PIO370|DATA_PRE370(3)|DATA_LOW370(14)|DATA_HIGH370(5))
#define CLK50_370PIO2    (CLK50_PIO370|DATA_PRE370(2)|DATA_LOW370(8)|DATA_HIGH370(4))
#define CLK50_370PIO3    (CLK50_PIO370|DATA_PRE370(2)|DATA_LOW370(6)|DATA_HIGH370(3))
#define CLK50_370PIO4    (CLK50_PIO370|DATA_PRE370(2)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK50_DMA370     (CTRL_ENA370(DMA_370MODE)|CMD_PRE370(5)|CMD_LOW370(15)|CMD_HIGH370(10))
#define CLK50_370DMA0    (CLK50_DMA370|DATA_PRE370(2)|DATA_LOW370(14)|DATA_HIGH370(10))
#define CLK50_370DMA1    (CLK50_DMA370|DATA_PRE370(2)|DATA_LOW370(5)|DATA_HIGH370(4))
#define CLK50_370DMA2    (CLK50_DMA370|DATA_PRE370(2)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK50_UDMA370    (CTRL_ENA370(UDMA_370MODE)|CMD_PRE370(5)|CMD_LOW370(15)|CMD_HIGH370(10))
#define CLK50_370UDMA0   (CLK50_UDMA370|UDMA_CYCLE370(6)|DATA_LOW370(14)|DATA_HIGH370(10))
#define CLK50_370UDMA1   (CLK50_UDMA370|UDMA_CYCLE370(5)|DATA_LOW370(5)|DATA_HIGH370(4))
#define CLK50_370UDMA2   (CLK50_UDMA370|UDMA_CYCLE370(3)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK50_370UDMA3   (CLK50_UDMA370|UDMA_CYCLE370(3)|DATA_PRE370(2)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK50_370UDMA4   (CLK50_UDMA370|UDMA_CYCLE370(11)|DATA_PRE370(2)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK50_370UDMA5   (CLK50_UDMA370|UDMA_CYCLE370(1)|DATA_PRE370(2)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK33_PIOCMD370  (CTRL_ENA370(PIO_370MODE)|CMD_PRE370(3)|CMD_LOW370(10)|CMD_HIGH370(7))
#define CLK33_370PIO0    (CLK33_PIOCMD370|DATA_PRE370(2)|DATA_LOW370(10)|DATA_HIGH370(7))
#define CLK33_370PIO1    (CLK33_PIOCMD370|DATA_PRE370(2)|DATA_LOW370(9)|DATA_HIGH370(3))
#define CLK33_370PIO2    (CLK33_PIOCMD370|DATA_PRE370(1)|DATA_LOW370(5)|DATA_HIGH370(3))
#define CLK33_370PIO3    (CLK33_PIOCMD370|DATA_PRE370(1)|DATA_LOW370(4)|DATA_HIGH370(2))
#define CLK33_370PIO4    (CLK33_PIOCMD370|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(1))
#define CLK33_DMACMD370  (CTRL_ENA370(DMA_370MODE)|CMD_PRE370(3)|CMD_LOW370(10)|CMD_HIGH370(7))
#define CLK33_370DMA0    (CLK33_DMACMD370|DATA_PRE370(1)|DATA_LOW370(9)|DATA_HIGH370(7))
#define CLK33_370DMA1    (CLK33_DMACMD370|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(3))
#define CLK33_370DMA2    (CLK33_DMACMD370|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(1))
#define CLK33_UDMACMD370 (CTRL_ENA370(UDMA_370MODE)|CMD_PRE370(3)|CMD_LOW370(10)|CMD_HIGH370(7))
#define CLK33_370UDMA0   (CLK33_UDMACMD370|UDMA_CYCLE370(4)|DATA_PRE370(1)|DATA_LOW370(9)|DATA_HIGH370(7))
#define CLK33_370UDMA1   (CLK33_UDMACMD370|UDMA_CYCLE370(3)|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(3))
#define CLK33_370UDMA2   (CLK33_UDMACMD370|UDMA_CYCLE370(2)|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(1))
#define CLK33_370UDMA3   (CLK33_UDMACMD370|UDMA_CYCLE370(11)|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(1))
#define CLK33_370UDMA4   (CLK33_UDMACMD370|UDMA_CYCLE370(1)|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH370(1))
#define CLK33_370UDMA5   (CLK33_UDMACMD370|UDMA_CYCLE370(1)|DATA_PRE370(1)|DATA_LOW370(3)|DATA_HIGH(1))
#define CLK33_PIOCMD  (CTRL_ENA(PIO_366MODE)|CMD_PRE(3)|CMD_LOW(10)|CMD_HIGH(7))
#define CLK33_366PIO0    (CLK33_PIOCMD|DATA_PRE(2)|DATA_LOW(10)|DATA_HIGH(10))
#define CLK33_366PIO1    (CLK33_PIOCMD|DATA_PRE(2)|DATA_LOW(10)|DATA_HIGH(3))
#define CLK33_366PIO2    (CLK33_PIOCMD|DATA_PRE(1)|DATA_LOW(5)|DATA_HIGH(3))
#define CLK33_366PIO3    (CLK33_PIOCMD|DATA_PRE(1)|DATA_LOW(4)|DATA_HIGH(2))
#define CLK33_366PIO4    (CLK33_PIOCMD|DATA_PRE(1)|DATA_LOW(3)|DATA_HIGH(1))
#define CLK33_DMACMD  (CTRL_ENA(DMA_366MODE)|CMD_PRE(3)|CMD_LOW(10)|CMD_HIGH(7))
#define CLK33_366DMA0    (CLK33_DMACMD|DATA_PRE(1)|DATA_LOW(9)|DATA_HIGH(7))
#define CLK33_366DMA1    (CLK33_DMACMD|DATA_PRE(1)|DATA_LOW(3)|DATA_HIGH(2))
#define CLK33_366DMA2    (CLK33_DMACMD|DATA_PRE(1)|DATA_LOW(3)|DATA_HIGH(1))
#define CLK33_UDMACMD (CTRL_ENA(UDMA_366MODE)|CMD_PRE(3)|CMD_LOW(10)|CMD_HIGH(7))
#define CLK33_366UDMA0   (CLK33_UDMACMD|UDMA_CYCLE(0)|DATA_PRE(1)|DATA_LOW(5)|DATA_HIGH(3))
#define CLK33_366UDMA1   (CLK33_UDMACMD|UDMA_CYCLE(3)|DATA_PRE(1)|DATA_LOW(4)|DATA_HIGH(2))
#define CLK33_366UDMA2   (CLK33_UDMACMD|UDMA_CYCLE(2)|DATA_PRE(1)|DATA_LOW(3)|DATA_HIGH(1))
#define CLK33_366UDMA3   (CLK33_UDMACMD|UDMA_CYCLE(7)|DATA_PRE(1)|DATA_LOW(3)|DATA_HIGH(1))
#define CLK33_366UDMA4   (CLK33_UDMACMD|UDMA_CYCLE(1)|DATA_PRE(1)|DATA_LOW(3)|DATA_HIGH(1))

// drivers\storage\port\scsi\miniport\megaide\hyperdisk.h
#define ANY_CHANNEL_INTERRUPT           (PRIMARY_CHANNEL_INTERRUPT | SECONDARY_CHANNEL_INTERRUPT)
#define POWER_ON_RESET_FOR_BOTH_CHANNEL           (POWER_ON_RESET_FOR_PRIMARY_CHANNEL | POWER_ON_RESET_FOR_SECONDARY_CHANNEL)
#define DRIVE_IS_UNUSABLE_STATE(TargetId)                               \
        ( DeviceExtension->PhysicalDrive[TargetId].TimeOutErrorCount >= MAX_TIME_OUT_ERROR_COUNT )

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\drlapi.h
#define	drltime_s	sizeof(drltime_t)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mdacapi.h
#define	mda_time_s	sizeof(mda_time_t)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mdacdrv.h
#define mdac_timeout2dactimeout(to) \
        ((to<=10)? DAC_DCDB_TIMEOUT_10sec : \
        ((to<=60)? DAC_DCDB_TIMEOUT_1min : \
        ((to<=60*20)? DAC_DCDB_TIMEOUT_20min : DAC_DCDB_TIMEOUT_1hr) ))
#define mdac_dactimeout2timeout(to) \
        (((to) == DAC_DCDB_TIMEOUT_10sec)? 10 : \
        (((to) == DAC_DCDB_TIMEOUT_1min)? 60 : \
        (((to) == DAC_DCDB_TIMEOUT_20min)? 20*60 : 60*60) ))

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mlxperf.h
#define	mlxperf_abstime_s	sizeof(mlxperf_abstime_t)
#define	mlxperf_reltime_s	sizeof(mlxperf_reltime_t)
#define	mlxperf_sampletime_s	sizeof(mlxperf_sampletime_t)

// drivers\tpg\hwx\bear\inc\lowlevel.h
#define  ANY_CROSSING(pElem)  (   REF(pElem)->mark==CROSS  \
                               || REF(pElem)->mark==HATCH  \
                               || REF(pElem)->mark==STICK )
#define  CROSS_IN_TIME(p1,p2)      ( p1 && p2 &&  (p1)->iend >= (p2)->ibeg     \
            && (p2)->iend >= (p1)->ibeg )
#define  FIRST_IN_SECOND(p1,p2)    ( p1 && p2 && (p1)->ibeg >= (p2)->ibeg     \
            && (p1)->iend <= (p2)->iend )

// drivers\tpg\hwx\bear\inc\xrlv_p.h
#define  P_XRLV_5                                                               \
 LTime += TimeTicks() - Time;                                                   \
 if (mpr == -6 || mpr == -7) XrlvPrintXrlvPos(xd->pos, xd);

// drivers\tpg\hwx\commonu\inc\locale.h
#define	LocRunIsDenseCode(pLocRunInfo,dch)		\
	((dch) < (pLocRunInfo)->cCodePoints)
#define	LocRunIsFoldedCode(pLocRunInfo,dch)		(							\
	((pLocRunInfo)->cCodePoints <= (dch)) &&  								\
	((dch) < ((pLocRunInfo)->cCodePoints + (pLocRunInfo)->cFoldingSets))	\
)
#define	LocRunFolded2FoldingSet(pLocRunInfo,fch)	(							\
	(wchar_t *)(pLocRunInfo)->pFoldingSets[(fch) - (pLocRunInfo)->cCodePoints]	\
)
#define	LocRunFolded2Dense(pLocRunInfo,fch)	(							\
	(pLocRunInfo)->pFoldingSets[(fch) - (pLocRunInfo)->cCodePoints][0]	\
)

// drivers\tpg\hwx\commonu\inc\recogp.h
#define FLTAbsTime(at1, at2)\
    ((at1).sec < (at2).sec || ((at1).sec == (at2).sec && (at1).ms < (at2).ms))
#define FLTEAbsTime(at1, at2)\
    ((at1).sec < (at2).sec || ((at1).sec == (at2).sec && (at1).ms <= (at2).ms))
#define FEQAbsTime(at1, at2)\
    ((at1).sec == (at2).sec && (at1).ms == (at2).ms)
#define FAbsTimeInInterval(at, lpi)\
    (FLTEAbsTime((lpi)->atBegin, at) && FLTEAbsTime(at, (lpi)->atEnd))
#define FIntervalInInterval(lpiT, lpiS)\
    (FLTEAbsTime((lpiS)->atBegin, (lpiT)->atBegin)\
    && FLTEAbsTime((lpiT)->atEnd, (lpiS)->atEnd))
#define FIntervalXInterval(lpiT, lpiS)\
    (!(FLTAbsTime((lpiT)->atEnd, (lpiS)->atBegin)\
    || FLTAbsTime((lpiS)->atEnd, (lpiT)->atBegin)))
#define MakeAbsTime(lpat, isec, ims) do {\
    (lpat)->sec = isec + ((ims) / 1000);\
    (lpat)->ms = (ims) % 1000;\
    } while (0)

// drivers\tpg\hwx\tsunami\inc\global.h
#define	ENTER_HANDLE_MANAGER	EnterCriticalSection(&global.cs);
#define	LEAVE_HANDLE_MANAGER	LeaveCriticalSection(&global.cs);

// drivers\video\matrox\mga\disp\mcdclip.c
#define __MCD_CLIP_POS(v, a, b, t) \
    v->clipCoord.x = t*(a->clipCoord.x - b->clipCoord.x) + b->clipCoord.x;  \
    v->clipCoord.y = t*(a->clipCoord.y - b->clipCoord.y) + b->clipCoord.y;  \
    v->clipCoord.z = t*(a->clipCoord.z - b->clipCoord.z) + b->clipCoord.z;  \
    v->clipCoord.w = t*(a->clipCoord.w - b->clipCoord.w) + b->clipCoord.w
#define __MCD_CLIP_TEXTURE(v, a, b, t) \
    v->texCoord.x = t*(a->texCoord.x - b->texCoord.x) + b->texCoord.x; \
    v->texCoord.y = t*(a->texCoord.y - b->texCoord.y) + b->texCoord.y;

// drivers\video\matrox\mga\disp\mcdrend.c
#define GET_HALF_AREA(pRc, a, b, c)\
    /* Compute signed half-area of the triangle */                          \
    (pRc)->dxAC = (c)->windowCoord.x - (a)->windowCoord.x;                  \
    (pRc)->dxBC = (c)->windowCoord.x - (b)->windowCoord.x;                  \
    (pRc)->dyAC = (c)->windowCoord.y - (a)->windowCoord.y;                  \
    (pRc)->dyBC = (c)->windowCoord.y - (b)->windowCoord.y;                  \
    (pRc)->dxAB = (b)->windowCoord.x - (a)->windowCoord.x;                  \
    (pRc)->dyAB = (b)->windowCoord.y - (a)->windowCoord.y;                  \
                                                                            \
    (pRc)->halfArea = (pRc)->dxAC * (pRc)->dyBC - (pRc)->dxBC * (pRc)->dyAC;

// drivers\video\matrox\mga\disp\mcdutil.h
#define INTERSECTRECT(RectInter, pRect, Rect)\
{\
    RectInter.left   = max(pRect->left, Rect.left);\
    RectInter.right  = min(pRect->right, Rect.right);\
    RectInter.top    = max(pRect->top, Rect.top);\
    RectInter.bottom = min(pRect->bottom, Rect.bottom);\
}

// drivers\video\ms\3dlabs\perm2\disp\d3ddelta.h
#define RENDER_POINT(a) {a &= ~(0xC0);a |= (0x80);}

// drivers\video\ms\3dlabs\perm2\disp\d3dtext.h
#define RECENTER_TEX_COORDS(Maxf, Maxi, fTC0, fTC1, fTC2)                \
{                                                                        \
    long tcmax;                                                          \
    unsigned long tcmin;                                                 \
    int i;                                                               \
                                                                         \
    tcmax = LONG_AT(fTC0);                                               \
    if (tcmax < LONG_AT(fTC1)) tcmax = LONG_AT(fTC1);                    \
    if (tcmax < LONG_AT(fTC2)) tcmax = LONG_AT(fTC2);                    \
    if (tcmax >= *(long *)&Maxf)                                         \
    {                                                                    \
        myFtoi(&i, *(float *)&tcmax);                                    \
        i -= Maxi;                                                       \
        fTC0 -= i;                                                       \
        fTC1 -= i;                                                       \
        fTC2 -= i;                                                       \
    }                                                                    \
    else                                                                 \
    {                                                                    \
        tcmin = ULONG_AT(fTC0);                                          \
        if (tcmin < ULONG_AT(fTC1)) tcmin = ULONG_AT(fTC1);              \
        if (tcmin < ULONG_AT(fTC2)) tcmin = ULONG_AT(fTC2);              \
        if (*(float *)&tcmin <= -Maxf)                                   \
        {                                                                \
            myFtoi(&i, *(float *)&tcmin);                                \
            i += Maxi;                                                   \
            fTC0 -= i;                                                   \
            fTC1 -= i;                                                   \
            fTC2 -= i;                                                   \
        }                                                                \
    }                                                                    \
}

// drivers\video\ms\3dlabs\perm3\disp\dx\d3dprim.c
#define GET_ONE_TEXCOORD(vtx)                           \
        GET_TC(vtx);                                    \
        if( pContext->iTexStage[1] != -1 )          \
        {                                               \
            GET_TC2(vtx);                               \
        }
#define GET_TEXCOORDS() \
        GET_TC(0); GET_TC(1); GET_TC(2);        \
        if( pContext->iTexStage[1] != -1 )  \
        {                                       \
            GET_TC2(0); GET_TC2(1); GET_TC2(2); \
        }
#define SCALE_BY_Q_3DTEX( Index )           \
    tc[Index].tu1 *= *(float *)&q[Index];   \
    tc[Index].tv1 *= *(float *)&q[Index];   \
    tc[Index].tw1 *= *(float *)&q[Index];
#define SCALE_BY_Q( Index )                 \
    tc[Index].tu1 *= *(float *)&q[Index];   \
    tc[Index].tv1 *= *(float *)&q[Index];
#define SCALE_BY_Q2_3DTEX( Index )          \
    tc[Index].tu2 *= *(float *)&q[Index];   \
    tc[Index].tv2 *= *(float *)&q[Index];   \
    tc[Index].tw2 *= *(float *)&q[Index];
#define SCALE_BY_Q2( Index )                \
    tc[Index].tu2 *= *(float *)&q[Index];   \
    tc[Index].tv2 *= *(float *)&q[Index];
#define TEXTURE_SHIFT( coord )  \
    if((tc[0].##coord >  TEX_SHIFT_LIMIT ) ||                           \
       (tc[0].##coord < -TEX_SHIFT_LIMIT ) )                            \
    {                                                                   \
        myFtoi( &intVal, tc[0].##coord );                               \
                                                                        \
        intVal &= ~1;                                                   \
                                                                        \
        tc[0].##coord -= intVal;                                        \
        tc[1].##coord -= intVal;                                        \
        tc[2].##coord -= intVal;                                        \
                                                                        \
        FLUSH_DUE_TO_WRAP( coord, TRUE );                               \
    }
#define RENDER_ONE_TRIANGLE_CYCLE(pContext, dwFillMode, pv, bVtxInvalid, vtx_a)\
{                                                                            \
    if (dwFillMode == D3DFILL_SOLID)                                         \
    {                                                                        \
        if( bVtxInvalid )                                                    \
            bVtxInvalid = (*pContext->pRendTri_3V)( pContext, pv, ALL_SIDES);    \
        else                                                                 \
            bVtxInvalid = (*pContext->pRendTri_1V)( pContext, pv, vtx_a );          \
    }                                                                        \
    else if (dwFillMode == D3DFILL_WIREFRAME)                                \
    {                                                                        \
        if(!__BackfaceCullNoTexture( pContext, pv ))                         \
        {                                                                    \
            pv[3] = pv[0];                                                   \
            __ProcessLine(pContext, &pv[0], pv[pContext->dwProvokingVertex]);\
            __ProcessLine(pContext, &pv[1], pv[pContext->dwProvokingVertex]);\
            __ProcessLine(pContext, &pv[2], pv[pContext->dwProvokingVertex]);\
        }                                                                    \
    }                                                                        \
    else                                                                     \
/*#if DX8_POINTSPRITES*/                                                     \
    if(IS_POINTSPRITE_ACTIVE(pContext))                                      \
    {                                                                        \
        __ProcessTri_3Vtx_PointSprite( pContext, pv, ALL_SIDES );        \
    }                                                                        \
    else                                                                     \
/*#endif*/                                                                   \
    {                                                                        \
        if(!__BackfaceCullNoTexture( pContext, pv ))                         \
        {                                                                    \
            __ProcessPoints( pContext, &pv[0], 1);                           \
            __ProcessPoints( pContext, &pv[1], 1);                           \
            __ProcessPoints( pContext, &pv[2], 1);                           \
        }                                                                    \
    }                                                                        \
}

// drivers\video\ms\cirrus\disp\hw.h
#define CP_MM_CL_SWITCH(ppdev)                                                 \
{                                                                              \
    if( ppdev->pCommandList == ppdev->pCLFirst )                               \
        ppdev->pCommandList = ppdev->pCLSecond;                                \
    else                                                                       \
        ppdev->pCommandList = ppdev->pCLFirst;                                 \
}

// drivers\video\ms\laguna\disp\cl5465\mcdclip.c
#define __MCD_CLIP_POS(v, a, b, t) \
    v->clipCoord.x = t*(a->clipCoord.x - b->clipCoord.x) + b->clipCoord.x;  \
    v->clipCoord.y = t*(a->clipCoord.y - b->clipCoord.y) + b->clipCoord.y;  \
    v->clipCoord.z = t*(a->clipCoord.z - b->clipCoord.z) + b->clipCoord.z;  \
    v->clipCoord.w = t*(a->clipCoord.w - b->clipCoord.w) + b->clipCoord.w
#define __MCD_CLIP_TEXTURE(v, a, b, t) \
    v->texCoord.x = t*(a->texCoord.x - b->texCoord.x) + b->texCoord.x; \
    v->texCoord.y = t*(a->texCoord.y - b->texCoord.y) + b->texCoord.y;

// drivers\video\ms\laguna\disp\cl5465\mcdrend.c
#define GET_HALF_AREA(pRc, a, b, c)\
    /* Compute signed half-area of the triangle */			    \
    (pRc)->dxAC = (c)->windowCoord.x - (a)->windowCoord.x;		    \
    (pRc)->dxBC = (c)->windowCoord.x - (b)->windowCoord.x;		    \
    (pRc)->dyAC = (c)->windowCoord.y - (a)->windowCoord.y;		    \
    (pRc)->dyBC = (c)->windowCoord.y - (b)->windowCoord.y;		    \
    (pRc)->dxAB = (b)->windowCoord.x - (a)->windowCoord.x;		    \
    (pRc)->dyAB = (b)->windowCoord.y - (a)->windowCoord.y;		    \
                                                                            \
    (pRc)->halfArea = (pRc)->dxAC * (pRc)->dyBC - (pRc)->dxBC * (pRc)->dyAC;

// drivers\video\ms\laguna\disp\cl5465\mcdtri.c
#define EDGE_SUBDIVIDE_TEST(start,end,WRAMAX,WRBMAX,SPLIT) \
  SPLIT = ((start->windowCoord.w > WRAMAX) || (end->windowCoord.w > WRBMAX)) ? 1 : 0;
#define SORT_Y_ORDER(a,b,c)                             \
{                                                       \
	void *ptemp;                                        \
    if( a->windowCoord.y > b->windowCoord.y )           \
        if( c->windowCoord.y < b->windowCoord.y )       \
            EXCHANGE(a,c)                               \
        else                                            \
            if( c->windowCoord.y < a->windowCoord.y )   \
                ROTATE_L(a,b,c)                         \
            else                                        \
                EXCHANGE(a,b)                           \
    else                                                \
        if( c->windowCoord.y < a->windowCoord.y )       \
            ROTATE_L(c,b,a)                             \
        else                                            \
            if( c->windowCoord.y < b->windowCoord.y )   \
                EXCHANGE(b,c)                           \
}

// drivers\video\ms\laguna\disp\cl5465\memmgr.c
	#define END_MUTEX(ppdev)	EngReleaseSemaphore(ppdev->MMhsem)

// drivers\video\ms\laguna\disp\cl546x\memmgr.c
	#define END_MUTEX(ppdev)	EngReleaseSemaphore(ppdev->MMhsem)

// drivers\video\ms\laguna\disp\include\driver.h
#define CLR_DRVSEM_YUV()    (pDriverData->DrvSemaphore &= ~DRVSEM_YUV_ON)

// drivers\video\ms\port\videoprt.h
#define ACQUIRE_DEVICE_LOCK(DeviceExtension)           \
    KeWaitForSingleObject(&DeviceExtension->SyncMutex, \
                          Executive,                   \
                          KernelMode,                  \
                          FALSE,                       \
                          (PTIME)NULL);
#define DELAY_MILLISECONDS(n)                               \
{                                                           \
    ULONG d_ulCount;                                        \
    ULONG d_ulTotal = 20 * (n);                             \
                                                            \
    for (d_ulCount = 0; d_ulCount < d_ulTotal; d_ulCount++) \
        KeStallExecutionProcessor(50);                      \
}
#define DELAY_MICROSECONDS(n)                               \
{                                                           \
    ULONG d_ulCount = (n);                                  \
                                                            \
    while (d_ulCount > 0)                                   \
    {                                                       \
        if (d_ulCount >= 50)                                \
        {                                                   \
            KeStallExecutionProcessor(50);                  \
            d_ulCount -= 50;                                \
        }                                                   \
        else                                                \
        {                                                   \
            KeStallExecutionProcessor(d_ulCount);           \
            d_ulCount = 0;                                  \
        }                                                   \
    }                                                       \
}
#define MAX_SECONDARY_DUMP_SIZE (0x1000 - sizeof(DUMP_BLOB_FILE_HEADER) - sizeof(DUMP_BLOB_HEADER))

// drivers\video\ms\s3\disp\hw.h
    #define ACQUIRE_CRTC_CRITICAL_SECTION(ppdev)                \
        EngAcquireSemaphore(ppdev->csCrtc);

// drivers\wdm\audio\backpln\portcls\ports\dmus\parse.h
#define IS_REALTIME_MSG(x)  (((x) & 0xF8) == 0xF8)

// drivers\wdm\audio\filters\kmixer\private.h
#define START_PERF (StartTick = KeQueryPerformanceCounter(&Freq))

// drivers\wdm\audio\inc\midi.h
#define IS_REALTIME(b)                  (((b) & 0xF8) == 0xF8)

// drivers\wdm\audio\sysaudio\fn.h
#define FILTER_TYPE_ENDPOINT        (FILTER_TYPE_BRIDGE | \
                     FILTER_TYPE_RENDERER | \
                     FILTER_TYPE_CAPTURER)

// drivers\wdm\capture\mini\msdv\msdvfmt.h
#define GET_AVG_TIME_PER_FRAME(format)       ((format == FMT_IDX_SD_DVCR_NTSC || format == FMT_IDX_SDL_DVCR_NTSC) ? (1001000/3)  : FRAME_TIME_PAL)
#define GET_AVG_TIME_PER_FRAME_NUM(format)   ((format == FMT_IDX_SD_DVCR_NTSC || format == FMT_IDX_SDL_DVCR_NTSC) ? 1001000      : 400000)
#define GET_AVG_TIME_PER_FRAME_DENOM(format) ((format == FMT_IDX_SD_DVCR_NTSC || format == FMT_IDX_SDL_DVCR_NTSC) ? 3            : 1)

// drivers\wdm\capture\mini\mstape\mstpfmt.h
    #define EnterAVCStrm(pMutex)  \
        { \
        KeWaitForMutexObject(pMutex, Executive, KernelMode, FALSE, NULL);\
        InterlockedIncrement(&MSDVCRMutextUseCount);\
        }

// drivers\wdm\devbay\dbclass\dbclass.h
#define INITIALIZE_DRB_SERIALIZATION(dc)  KeInitializeSemaphore(&(dc)->DrbSemaphore, 1, 1);
#define DBCLASS_BEGIN_SERIALIZED_DRB(dc)  { DBCLASS_KdPrint((3, "'***WAIT DRB SEM%x\n", &(dc)->DrbSemaphore)); \
                                          KeWaitForSingleObject(&(dc)->DrbSemaphore, \
                                                                Executive,\
                                                                KernelMode, \
                                                                FALSE, \
                                                                NULL); \
                                          }

// drivers\wdm\input\samples\monitor\map.h
#define PUN(T, v) OBJAT(T, &(v))	/* General-purpose type-punning */
#define fLimpFF(f1, f2) (!(f1) || (f2))
#define Primary_Vtbl(C) &c_##C##VI.vtbl
#define Secondary_Vtbl(C, I) &c_##I##_##C##VI.vtbl
#define Common_AddRef(punk) \
		((IUnknown *)(punk))->lpVtbl->AddRef((IUnknown *)(punk))
#define Common_Release(punk) \
		((IUnknown *)(punk))->lpVtbl->Release((IUnknown *)(punk))

// drivers\wdm\rt\exec\rt.c
#define LoadRtDS() \
__asm { \
	__asm mov ax,ds				\
	__asm shl eax,16			\
	__asm mov ax,cs:RealTimeDS	\
	__asm mov ds,ax				\
	}

// drivers\wdm\usb\driver\hub.pnp\usbhub.h
#define STRCAT( pFirst, pSecond )\
    {\
    int j, k;\
    int nLength;\
    STRLEN( j, pFirst );\
    STRLEN( nLength, pSecond );\
    j /= sizeof( *pFirst );\
    nLength /= sizeof( *pSecond);\
    for ( k=0; k < nLength; k++, j++ ) pFirst[j] = pSecond[k];\
    pFirst[j] = 0;\
    }

// drivers\wdm\usb\driver\usbdiag\usbdiag.h
#define InitializeUsbDeviceMutex(de)  KeInitializeSemaphore(&(de)->UsbDeviceMutex, 1, 1);

// drivers\wdm\usb\hcd\openhci\ohcixfer.c
#define INITIALIZE_TD(td, ep, urb) \
    {\
    td->UsbdRequest = (PHCD_URB)(urb);\
    td->Endpoint = (ep);\
    td->Canceled = FALSE;\
    td->TransferCount = 0; \
    td->HcTD.Control = 0; \
    td->HcTD.CBP = 0;\
    td->HcTD.BE = 0;\
    }

// drivers\wdm\usb\hcd\openhci\openhci.c
#define OHCI_WAIT(ms) {\
    LARGE_INTEGER t;\
    t.QuadPart = (((LONG)KeQueryTimeIncrement()-1) + (ms) * 10000) * -1;\
    KeDelayExecutionThread(KernelMode, FALSE, &t);\
    }

// drivers\wdm\usb\hcd\openhci\openhci.h
#define ZERO_LOAD_ENDPOINT(DeviceData) \
        ((PVOID) (&(DeviceData)->ZeroLoadEndpoint_AddrHolder))

// drivers\wdm\usb\hcd\uhcd\uhcd.h
#define LOCK_ENDPOINT_ACTIVE_LIST(ep, irql) \
                        KeAcquireSpinLock(&ep->ActiveListSpin, &irql); \
                        UHCD_LockAccess(&(ep)->AccessActiveList);
#define LOCK_ENDPOINT_LIST(de, irql) \
    KeAcquireSpinLock(&(de)->EndpointListSpin, &irql);

// drivers\wdm\usb\hcd\usbport\usbport.h
#define USBPORT_ACQUIRE_DM_LOCK(de, i) \
    KeAcquireSpinLock(&(de)->Fdo.DM_TimerSpin.sl, &(i))

// drivers\wdm\usb\usbd\usbd.h
#define InitializeUsbDeviceMutex(de)  KeInitializeSemaphore(&(de)->UsbDeviceMutex, 1, 1);

// ds\adsi\ldap\cdispmgr.cxx
#define ENTER_TYPEINFO_CRITSECT()  EnterCriticalSection(&g_TypeInfoCritSect)
#define LEAVE_TYPEINFO_CRITSECT()  LeaveCriticalSection(&g_TypeInfoCritSect)

// ds\adsi\ldap\extension.cxx
#define ENTER_EXTENSION_CRITSECT()  EnterCriticalSection(&g_ExtCritSect)
#define LEAVE_EXTENSION_CRITSECT()  LeaveCriticalSection(&g_ExtCritSect)

// ds\adsi\ldap\globals.hxx
#define ENTER_LOADLIBS_CRITSECT()  EnterCriticalSection(&g_csLoadLibsCritSect)
#define LEAVE_LOADLIBS_CRITSECT()  LeaveCriticalSection(&g_csLoadLibsCritSect)

// ds\adsi\ldap\ldapinc\disptmpl.h
#define LDAP_SYN_TIME		( 10 | LDAP_SYN_TYPE_TEXT )

// ds\adsi\ldap\servtype.cxx
#define ENTER_ROOTDSE_CRITSECT()  EnterCriticalSection(&g_RootDSECritSect)
#define LEAVE_ROOTDSE_CRITSECT()  LeaveCriticalSection(&g_RootDSECritSect)

// ds\adsi\ldapc\encode.c
#define MAPHEXTODIGIT(x) ( x >= '0' && x <= '9' ? (x-'0') :        \
                           x >= 'A' && x <= 'F' ? (x-'A'+10) :     \
                           x >= 'a' && x <= 'f' ? (x-'a'+10) : 0 )

// ds\adsi\ldapc\ldapsch.cxx
#define ENTER_SCHEMA_CRITSECT()  EnterCriticalSection(&g_SchemaCritSect)
#define LEAVE_SCHEMA_CRITSECT()  LeaveCriticalSection(&g_SchemaCritSect)
#define ENTER_SUBSCHEMA_CRITSECT()  EnterCriticalSection(&g_SubSchemaCritSect)
#define LEAVE_SUBSCHEMA_CRITSECT()  LeaveCriticalSection(&g_SubSchemaCritSect)
#define ENTER_DEFAULTSCHEMA_CRITSECT()  EnterCriticalSection(&g_DefaultSchemaCritSect)
#define LEAVE_DEFAULTSCHEMA_CRITSECT()  LeaveCriticalSection(&g_DefaultSchemaCritSect)

// ds\adsi\ldapc\ldpcache.hxx
#define ENTER_BIND_CRITSECT()    EnterCriticalSection(&BindCacheCritSect)
#define LEAVE_BIND_CRITSECT()    LeaveCriticalSection(&BindCacheCritSect)

// ds\adsi\ldapc\srvloc.cxx
#define ENTER_DOMAINDNS_CRITSECT()  EnterCriticalSection(&g_DomainDnsCache)
#define LEAVE_DOMAINDNS_CRITSECT()  LeaveCriticalSection(&g_DomainDnsCache)

// ds\adsi\msext\cdispmgr.cxx
#define ENTER_EXT_TYPEINFO_CRITSECT()  EnterCriticalSection(&g_ExtTypeInfoCritSect)
#define LEAVE_EXT_TYPEINFO_CRITSECT()  LeaveCriticalSection(&g_ExtTypeInfoCritSect)

// ds\adsi\msext\globals.hxx
#define ENTER_SERVERLIST_CRITICAL_SECTION() EnterCriticalSection(&g_ServerListCritSect);
#define LEAVE_SERVERLIST_CRITICAL_SECTION() LeaveCriticalSection(&g_ServerListCritSect);

// ds\adsi\nds\qryparse.cxx
#define MAPHEXTODIGIT(x) ( x >= '0' && x <= '9' ? (x-'0') :        \
                           x >= 'A' && x <= 'F' ? (x-'A'+10) :     \
                           x >= 'a' && x <= 'f' ? (x-'a'+10) : 0 )

// ds\adsi\novellnw\nwcache.hxx
#define ENTER_BIND_CRITSECT()    EnterCriticalSection(&BindCacheCritSect)
#define LEAVE_BIND_CRITSECT()    LeaveCriticalSection(&BindCacheCritSect)

// ds\adsi\nw312\cdispmgr.cxx
#define ENTER_TYPEINFO_CRITSECT()  EnterCriticalSection(&g_TypeInfoCritSect)
#define LEAVE_TYPEINFO_CRITSECT()  LeaveCriticalSection(&g_TypeInfoCritSect)

// ds\adsi\nw312\extension.cxx
#define ENTER_EXTENSION_CRITSECT()  EnterCriticalSection(&g_ExtCritSect)
#define LEAVE_EXTENSION_CRITSECT()  LeaveCriticalSection(&g_ExtCritSect)

// ds\adsi\nwnds\ndscache.hxx
#define ENTER_BIND_CRITSECT()    EnterCriticalSection(&BindCacheCritSect)
#define LEAVE_BIND_CRITSECT()    LeaveCriticalSection(&BindCacheCritSect)

// ds\adsi\nwnds\qryparse.cxx
#define MAPHEXTODIGIT(x) ( x >= '0' && x <= '9' ? (x-'0') :        \
                           x >= 'A' && x <= 'F' ? (x-'A'+10) :     \
                           x >= 'a' && x <= 'f' ? (x-'a'+10) : 0 )

// ds\adsi\utils\cdispmgr.cxx
#define ENTER_DISP_TYPEINFO_CRITSECT()  EnterCriticalSection(&g_DispTypeInfoCritSect)
#define LEAVE_DISP_TYPEINFO_CRITSECT()  LeaveCriticalSection(&g_DispTypeInfoCritSect)

// ds\adsi\winnt\cdispmgr.cxx
#define ENTER_TYPEINFO_CRITSECT()  EnterCriticalSection(&g_TypeInfoCritSect)
#define LEAVE_TYPEINFO_CRITSECT()  LeaveCriticalSection(&g_TypeInfoCritSect)

// ds\adsi\winnt\extension.cxx
#define ENTER_EXTENSION_CRITSECT()  EnterCriticalSection(&g_ExtCritSect)
#define LEAVE_EXTENSION_CRITSECT()  LeaveCriticalSection(&g_ExtCritSect)

// ds\adsi\xml\cdispmgr.cxx
#define ENTER_EXT_TYPEINFO_CRITSECT()  EnterCriticalSection(&g_ExtTypeInfoCritSect)
#define LEAVE_EXT_TYPEINFO_CRITSECT()  LeaveCriticalSection(&g_ExtTypeInfoCritSect)

// ds\dns\dnsapi\local.h
#define LOCK_GENERAL()      EnterCriticalSection( &g_GeneralCS )
#define UNLOCK_GENERAL()    LeaveCriticalSection( &g_GeneralCS )

// ds\dns\resolver\server\ip.c
#define LOCK_IP_NOTIFY_HANDLE()     EnterCriticalSection( &NetworkFailureCritSec )
#define UNLOCK_IP_NOTIFY_HANDLE()   LeaveCriticalSection( &NetworkFailureCritSec )
#define LOCK_IP_LIST()     EnterCriticalSection( &g_IpListCS );
#define UNLOCK_IP_LIST()   LeaveCriticalSection( &g_IpListCS );

// ds\dns\resolver\server\local.h
#define LOCK_NET_LIST()         EnterCriticalSection( &NetworkListCritSec )
#define UNLOCK_NET_LIST()       LeaveCriticalSection( &NetworkListCritSec )
#define LOCK_NET_FAILURE()      EnterCriticalSection( &NetworkFailureCritSec )
#define UNLOCK_NET_FAILURE()    LeaveCriticalSection( &NetworkFailureCritSec )

// ds\dns\server\server\aging.c
#define ZONE_ALLOW_SCAVENGE_TIME(pZone)   \
        ( (pZone)->dwAgingEnabledTime + (pZone)->dwRefreshInterval)

// ds\dns\server\server\dnssrv.h
#define GENERAL_SERVER_LOCK()       EnterCriticalSection( &g_GeneralServerCS );
#define GENERAL_SERVER_UNLOCK()     LeaveCriticalSection( &g_GeneralServerCS );

// ds\dns\server\server\memory.c
#define STANDARD_ALLOC_LOCK(plist)      EnterCriticalSection( &(plist)->Lock );
#define STANDARD_ALLOC_UNLOCK(plist)    LeaveCriticalSection( &(plist)->Lock );

// ds\dns\server\server\msginfo.h
#define DNSMSG_INCLUDE_DNSSEC_IN_RESPONSE( _pMsg )                  \
    ( SrvCfg_dwEnableDnsSec == DNS_DNSSEC_ENABLED_ALWAYS ||         \
        SrvCfg_dwEnableDnsSec == DNS_DNSSEC_ENABLED_IF_EDNS &&      \
            ( _pMsg )->Opt.fFoundOptInIncomingMsg )
#define SET_MESSAGE_FIELDS_AFTER_RECV( pMsg )   \
        {                                       \
            (pMsg)->dwQueryTime     = DNS_TIME();   \
        }
#define SET_TO_WRITE_QUESTION_RECORDS(pMsg) \
            ((pMsg)->Section = QUESTION_SECTION_INDEX)
#define SET_TO_WRITE_ANSWER_RECORDS(pMsg) \
            ((pMsg)->Section = ANSWER_SECTION_INDEX)
#define SET_TO_WRITE_AUTHORITY_RECORDS(pMsg) \
            ((pMsg)->Section = AUTHORITY_SECTION_INDEX)
#define SET_TO_WRITE_ADDITIONAL_RECORDS(pMsg) \
            ((pMsg)->Section = ADDITIONAL_SECTION_INDEX)
#define IS_SET_TO_WRITE_QUESTION_RECORDS(pMsg) \
            ((pMsg)->Section == QUESTION_SECTION_INDEX)
#define IS_SET_TO_WRITE_ANSWER_RECORDS(pMsg) \
            ((pMsg)->Section == ANSWER_SECTION_INDEX)
#define IS_SET_TO_WRITE_AUTHORITY_RECORDS(pMsg) \
            ((pMsg)->Section == AUTHORITY_SECTION_INDEX)
#define IS_SET_TO_WRITE_ADDITIONAL_RECORDS(pMsg) \
            ((pMsg)->Section == ADDITIONAL_SECTION_INDEX)

// ds\dns\server\server\record.h
#define IS_AUTHORITY_SECTION_TYPE(wType)    \
        (   (wType) == DNS_TYPE_NS      ||  \
            (wType) == DNS_TYPE_SOA     ||  \
            (wType) == DNS_TYPE_SIG     ||  \
            (wType) == DNS_TYPE_NXT )
#define IS_ADDITIONAL_SECTION_TYPE(wType)   \
        (   (wType) == DNS_TYPE_A       ||  \
            (wType) == DNS_TYPE_AAAA    ||  \
            (wType) == DNS_TYPE_KEY     ||  \
            (wType) == DNS_TYPE_SIG     ||  \
            (wType) == DNS_TYPE_OPT )
#define IS_DNSSEC_TYPE(wType)               \
        (   (wType) == DNS_TYPE_SIG     ||  \
            (wType) == DNS_TYPE_KEY     ||  \
            (wType) == DNS_TYPE_NXT     )

// ds\dns\server\server\remote.c
#define LOCK_REMOTE()      EnterCriticalSection( &csRemoteLock );
#define UNLOCK_REMOTE()    LeaveCriticalSection( &csRemoteLock );

// ds\dns\server\server\socket.c
#define LOCK_SOCKET_LIST()      EnterCriticalSection( &g_SocketListCs )
#define UNLOCK_SOCKET_LIST()    LeaveCriticalSection( &g_SocketListCs )

// ds\dns\server\server\srvcfg.h
#define DNS_STARTUP_TIME()  (( SrvInfo_dwCurrentTime )       \
                                ? SrvInfo_dwCurrentTime      \
                                : GetCurrentTimeInSeconds() )

// ds\dns\server\server\tcpcon.c
#define LOCK_TCPCON_LIST()     EnterCriticalSection( &mg_TcpConnectionListCS )
#define UNLOCK_TCPCON_LIST()   LeaveCriticalSection( &mg_TcpConnectionListCS )

// ds\dns\server\server\timeout.c
#define LOCK_TIMEOUT()      EnterCriticalSection( &csTimeoutLock );
#define UNLOCK_TIMEOUT()    LeaveCriticalSection( &csTimeoutLock );

// ds\dns\server\server\tree.h
#define IS_NODE_RECENTLY_ACCESSED(pNode) \
            ( (pNode)->uchAccessBin == CurrentTimeoutBin || \
              (pNode)->uchAccessBin == (UCHAR)(CurrentTimeoutBin-1) )
#define SET_NODE_ACCESSED(pNode)    \
            ( (pNode)->uchAccessBin = CurrentTimeoutBin )

// ds\dns\server\server\update.h
#define AGING_ZONE_REFRESH_TIME(pZone)   \
        ( g_CurrentTimeHours - (pZone)->dwNoRefreshInterval)
#define AGING_ZONE_EXPIRE_TIME(pZone)   \
        ( g_CurrentTimeHours - (pZone)->dwNoRefreshInterval - (pZone)->dwRefreshInterval)
#define AGING_IS_RR_EXPIRED( pRR, ExpireBelowTime ) \
        ( (pRR)->dwTimeStamp < (ExpireBelowTime) && (pRR)->dwTimeStamp != 0 )
#define AGING_DOES_RR_NEED_REFRESH( pRR, RefreshBelowTime ) \
        ( (pRR)->dwTimeStamp < (RefreshBelowTime) && (pRR)->dwTimeStamp != 0 )

// ds\dns\server\server\zone.h
#define IS_ZONE_SECONDARY(pZone)        \
                ((pZone)->fZoneType == DNS_ZONE_TYPE_SECONDARY  \
              || (pZone)->fZoneType == DNS_ZONE_TYPE_STUB)
#define ZONE_NEEDS_MASTERS(pZone)       \
                ( (pZone)->fZoneType == DNS_ZONE_TYPE_SECONDARY         \
                    || (pZone)->fZoneType == DNS_ZONE_TYPE_STUB         \
                    || (pZone)->fZoneType == DNS_ZONE_TYPE_FORWARDER )
#define Zone_UpdateLock(pZone)    EnterCriticalSection( &csZoneList );
#define Zone_UpdateUnlock(pZone)  LeaveCriticalSection( &csZoneList );

// ds\ds\src\common\atq\atqdgram.cxx
#define I_SetNextTimeout2( _c, _t ) {                               \
    (_c)->NextTimeout = AtqGetCurrentTick() + (_t);                 \
    if ( (_c)->NextTimeout < (_c)->ContextList->LatestTimeout ) {   \
        (_c)->ContextList->LatestTimeout = (_c)->NextTimeout;       \
    }                                                               \
}

// ds\ds\src\common\atq\atqtypes.hxx
# define TimeToWait(Timeout)   (((Timeout) == INFINITE) ?INFINITE: \
                                (Timeout) * 1000)
#define IS_DATAGRAM_CONTEXT( pContext ) \
    ( ((pContext)->pEndpoint != NULL) && ((pContext)->pEndpoint->fDatagram) )
#define I_SetNextTimeout( _c ) {                                    \
    (_c)->NextTimeout = AtqGetCurrentTick() + (_c)->TimeOut;        \
    if ( (_c)->NextTimeout < (_c)->ContextList->LatestTimeout ) {   \
        (_c)->ContextList->LatestTimeout = (_c)->NextTimeout;       \
    }                                                               \
}

// ds\ds\src\common\atq\sched.cxx
#define LockScheduleList()      EnterCriticalSection( &csSchedulerLock )
#define UnlockScheduleList()    LeaveCriticalSection( &csSchedulerLock )

// ds\ds\src\inc\dsconfig.h
#define DEFAULT_DRSRPC_BIND_TIMEOUT             (10)      // bind & unbind

// ds\ds\src\inc\w32toplspantree.h
#define TOPL_EX_NONINTERSECTING_SCHEDULES (TOPL_EX_PREFIX | 208)

// ds\ds\src\ldap\client\dnfilter\h245pp.h
#define SIZE_H245PP_Module_PDU_0 sizeof(MultimediaSystemControlMessage)

// ds\ds\src\ldap\client\lmacros.h
#define MAPHEXTODIGIT(x) ( x >= '0' && x <= '9' ? (x-'0') :        \
                           x >= 'A' && x <= 'F' ? (x-'A'+10) :     \
                           x >= 'a' && x <= 'f' ? (x-'a'+10) : 0 )

// ds\ds\src\ntdsa\dblayer\dbsyntax.c
#define SEC_INFO_ALL (SACL_SECURITY_INFORMATION  | \
                      OWNER_SECURITY_INFORMATION | \
                      GROUP_SECURITY_INFORMATION | \
                      DACL_SECURITY_INFORMATION    )

// ds\ds\src\ntdsa\dra\draasync.c
#define SAME_SCHED(a,b)                                     \
    ((NULL == (a))                                          \
     ? (NULL == (b))                                        \
     : ((NULL != (b)) && !memcmp(a,b,sizeof(REPLTIMES))))

// ds\ds\src\ntdsa\dra\drameta.c
#define ReplMetaIsOverridden(pTHS, pMeta, pTime, pUsn) \
    ((0 == memcmp(&((pMeta)->uuidDsaOriginating), \
                  &(pTHS)->InvocationID, \
                  sizeof(UUID))) \
     && (*(pTime) == (pMeta)->timeChanged) \
     && (*(pUsn) == (pMeta)->usnOriginating))

// ds\ds\src\ntdsa\include\cracknam.h
#define SetCrackSearchLimits(pCommArg)                          \
    (pCommArg)->StartTick = GetTickCount();                     \
    (pCommArg)->DeltaTick = 1000 * LdapMaxQueryDuration;        \
    (pCommArg)->Svccntl.localScope = TRUE;

// ds\ds\src\ntdsa\src\mdupdate.c
#define SEC_INFO_ALL (SACL_SECURITY_INFORMATION  | \
                      OWNER_SECURITY_INFORMATION | \
                      GROUP_SECURITY_INFORMATION | \
                      DACL_SECURITY_INFORMATION    )

// ds\ds\src\ntdsa\src\samcache.c
#define IS_ZERO_TIME(entry) \
    (!memcmp(&entry, &ZeroTime, sizeof(ZeroTime)))

// ds\ds\src\sam\server\rng.c
#define LockRNG()   EnterCriticalSection( &csRNG )
#define UnlockRNG() LeaveCriticalSection( &csRNG )

// ds\ds\src\sam\server\samsrvp.h
#define SAMP_LOCKOUT_TIME_SET(x) \
     (BOOLEAN)( ((x)->TypeBody.User.LockoutTime.QuadPart)!=0)

// ds\ds\src\sam\server\usrprop.c
#define MAPHEXTODIGIT(x) ( x >= '0' && x <= '9' ? (x-'0') :        \
                           x >= 'A' && x <= 'F' ? (x-'A'+10) :     \
                           x >= 'a' && x <= 'f' ? (x-'a'+10) : 0 )

// ds\ds\src\util\dcdiag\repl\security.c
#define    ALL_REPL_RIGHTS(x)    ((x)->bGetChangesRight && (x)->bSyncRight && (x)->bManageTopoRight)

// ds\ese98\export\jetbcli.h
#define	BFT_CHECKPOINT_DIR			(BFT)(TEXT('\x03') | BFT_DIRECTORY)

// ds\ese98\src\inc\pib.hxx
#define ErrPIBCheck( ppib )											\
	( ( ppib >= PinstFromPpib(ppib)->m_ppibGlobalMin && ppib < PinstFromPpib(ppib)->m_ppibGlobalMax				\
	&& ppib->procid == ProcidPIBOfPpib( ppib ) )					\
	? JET_errSuccess : ErrERRCheck( JET_errInvalidSesid ) )

// ds\netapi\netlib\secobj.c
#define FirstAce(Acl) ((PVOID)((PUCHAR)(Acl) + sizeof(ACL)))

// ds\netapi\netlib\usrprop.c
#define MAPHEXTODIGIT(x) ( x >= '0' && x <= '9' ? (x-'0') :        \
                           x >= 'A' && x <= 'F' ? (x-'A'+10) :     \
                           x >= 'a' && x <= 'f' ? (x-'a'+10) : 0 )

// ds\netapi\svcdlls\browser\server\bowqueue.c
#define LOCK_WORK_QUEUE() EnterCriticalSection(&BrWorkerCritSect);
#define UNLOCK_WORK_QUEUE() LeaveCriticalSection(&BrWorkerCritSect);

// ds\netapi\svcdlls\browser\server\brsec.h
#define BROWSER_ALL_ACCESS           (STANDARD_RIGHTS_REQUIRED    | \
                                      BROWSER_CONTROL_ACCESS      | \
                                      BROWSER_QUERY_ACCESS )

// ds\netapi\svcdlls\dfs\client\dfsstub.c
#define ENTER_NETDFS_API EnterCriticalSection( &NetDfsApiCriticalSection );
#define LEAVE_NETDFS_API LeaveCriticalSection( &NetDfsApiCriticalSection );

// ds\netapi\svcdlls\msgsvc\server\msgsec.h
#define MSGR_MESSAGE_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED   |   \
                                         MSGR_MESSAGE_NAME_INFO_GET |   \
                                         MSGR_MESSAGE_NAME_ENUM     |   \
                                         MSGR_MESSAGE_NAME_ADD      |   \
                                         MSGR_MESSAGE_NAME_DEL)

// ds\netapi\svcdlls\srvsvc\server\sssec.h
#define SRVSVC_CONFIG_ALL_ACCESS ( STANDARD_RIGHTS_REQUIRED     | \
                                   SRVSVC_CONFIG_USER_INFO_GET  | \
                                   SRVSVC_CONFIG_POWER_INFO_GET | \
                                   SRVSVC_CONFIG_ADMIN_INFO_GET | \
                                   SRVSVC_CONFIG_INFO_SET )
#define SRVSVC_CONNECTION_ALL_ACCESS ( STANDARD_RIGHTS_REQUIRED     | \
                                       SRVSVC_CONNECTION_INFO_GET )
#define SRVSVC_DISK_ALL_ACCESS ( STANDARD_RIGHTS_REQUIRED | \
                                 SRVSVC_DISK_ENUM )
#define SRVSVC_SHARE_ALL_ACCESS ( STANDARD_RIGHTS_REQUIRED    | \
                                  SRVSVC_SHARE_USER_INFO_GET  | \
                                  SRVSVC_SHARE_ADMIN_INFO_GET | \
                                  SRVSVC_SHARE_INFO_SET )
#define SRVSVC_STATISTICS_ALL_ACCESS ( STANDARD_RIGHTS_REQUIRED  | \
                                       SRVSVC_STATISTICS_GET )

// ds\netapi\svcdlls\wkssvc\server\wssec.h
#define WKSTA_CONFIG_ALL_ACCESS        (STANDARD_RIGHTS_REQUIRED    | \
                                        WKSTA_CONFIG_GUEST_INFO_GET | \
                                        WKSTA_CONFIG_USER_INFO_GET  | \
                                        WKSTA_CONFIG_ADMIN_INFO_GET | \
                                        WKSTA_CONFIG_INFO_SET)
#define WKSTA_MESSAGE_ALL_ACCESS       (STANDARD_RIGHTS_REQUIRED | \
                                        WKSTA_MESSAGE_SEND)

// ds\netapi\svcimgs\ntrepl\frs\frscomm.c
#define  COMM_SZ_JTIME     sizeof(ULONGLONG) + sizeof(ULONG)

// ds\netapi\svcimgs\ntrepl\frs\replica.c
#define SET_JOINED(_Replica_, _Cxtion_, _S_)                                   \
{                                                                              \
    SetCxtionState(_Cxtion_, CxtionStateJoined);                               \
    PM_INC_CTR_REPSET((_Replica_), Joins, 1);                                  \
    PM_INC_CTR_CXTION((_Cxtion_), Joins, 1);                                   \
                                                                               \
    DPRINT3(0, ":X: ***** %s   CxtG %08x  "FORMAT_CXTION_PATH2"\n",            \
            _S_,                                                               \
            ((_Cxtion_) != NULL) ? ((PCXTION)(_Cxtion_))->Name->Guid->Data1 : 0,\
            PRINT_CXTION_PATH2(_Replica_, _Cxtion_));                          \
    if (_Cxtion_->JoinCmd &&                                                   \
        (LONG)RsTimeout(_Cxtion_->JoinCmd) > (JOIN_RETRY_EVENT * MinJoinRetry)) { \
        if (_Cxtion_->Inbound) {                                               \
            EPRINT3(EVENT_FRS_LONG_JOIN_DONE,                                  \
                    _Cxtion_->Partner->Name, ComputerName, _Replica_->Root);   \
        } else {                                                               \
            EPRINT3(EVENT_FRS_LONG_JOIN_DONE,                                  \
                    ComputerName, _Cxtion_->Partner->Name, _Replica_->Root);   \
        }                                                                      \
    }                                                                          \
}

// ds\netapi\svcimgs\ntrepl\inc\frsalloc.h
#define QHashAcquireLock(_Table_) EnterCriticalSection(&((_Table_)->Lock))
#define LOCK_VME(_pVme_)   EnterCriticalSection(&(_pVme_)->Lock)
#define UNLOCK_VME(_pVme_) LeaveCriticalSection(&(_pVme_)->Lock)

// ds\netapi\svcimgs\ntrepl\inc\replutil.h
#define COPY_TIME(_a_, _b_)   CopyMemory((_a_), (_b_), sizeof(FILETIME))
#define IS_TIME_ZERO(_g_) ((*((PULONG)(&(_g_))+0) | *((PULONG)(&(_g_))+1) ) == 0)
#define OPEN_OPTIONS        (FILE_OPEN_FOR_BACKUP_INTENT     | \
                             FILE_SEQUENTIAL_ONLY            | \
                             FILE_OPEN_NO_RECALL             | \
                             FILE_OPEN_REPARSE_POINT         | \
                             FILE_SYNCHRONOUS_IO_NONALERT)
#define OPEN_OPLOCK_OPTIONS (FILE_RESERVE_OPFILTER | FILE_OPEN_REPARSE_POINT)
#define ID_OPLOCK_OPTIONS   (FILE_OPEN_FOR_BACKUP_INTENT | \
                             FILE_RESERVE_OPFILTER       | \
                             FILE_OPEN_REPARSE_POINT     | \
                             FILE_OPEN_BY_FILE_ID)
#define FrsRtlAcquireQueueLock(_pQueue_) \
            EnterCriticalSection(&(((_pQueue_)->Control)->Lock))
#define FrsRtlAcquireListLock(_pList_) EnterCriticalSection(&(((_pList_)->Control)->Lock))
#define FILETIME_IS_ZERO(_F_) \
    ((_F_.dwLowDateTime == 0) && (_F_.dwHighDateTime == 0))
#define JrnlAcquireChildLock(_replica_) EnterCriticalSection( \
    &JrnlFilterTableChildLock[FILTER_TABLE_CHILD_INDEX(_replica_)] )
#define JrnlAcquireChildLockPair(_replica1_, _replica2_)        \
{                                                               \
    ULONG Lx1, Lx2, Lxt;                                        \
    Lx1 = FILTER_TABLE_CHILD_INDEX(_replica1_);                 \
    Lx2 = FILTER_TABLE_CHILD_INDEX(_replica2_);                 \
    if (Lx1 > Lx2) {                                            \
        Lxt = Lx1; Lx1 = Lx2; Lx2 = Lxt;                        \
    }                                                           \
    EnterCriticalSection(&JrnlFilterTableChildLock[Lx1]);       \
    if (Lx1 != Lx2) {                                           \
        EnterCriticalSection(&JrnlFilterTableChildLock[Lx2]);   \
    }                                                           \
}

// ds\netapi\svcimgs\ntrepl\repl\createdb.c
#define ACQUIRE_DBS_INIT_LOCK  EnterCriticalSection(&DbsInitLock)
#define INITIALIZE_DBS_INIT_LOCK InitializeCriticalSection(&DbsInitLock);

// ds\netapi\svcimgs\ntrepl\test\frsexts\frsexts.cxx
#define DMPTIME(_TEXT_,_Time_)                                              \
        {                                                                   \
            CHAR TimeStr[TIME_STRING_LENGTH];                               \
            FileTimeToString((FILETIME *)&(_Time_),TimeStr);                \
            dprintf((_TEXT_));                                              \
            dprintf("%s\n",TimeStr);                                        \
        }

// ds\nw\convert\nwconv\usrprop.c
#define MAPHEXTODIGIT(x) ( x >= '0' && x <= '9' ? (x-'0') :        \
                           x >= 'A' && x <= 'F' ? (x-'A'+10) :     \
                           x >= 'a' && x <= 'f' ? (x-'a'+10) : 0 )

// ds\nw\vwipxspx\dll\util.h
#define RequestMutex()  EnterCriticalSection(&SerializationCritSec)

// ds\security\asn1\asn1c\scanner.c
#define yy_set_interactive(is_interactive) \
	{ \
	if ( ! yy_current_buffer ) \
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
	yy_current_buffer->yy_is_interactive = is_interactive; \
	}
#define yy_set_bol(at_bol) \
	{ \
	if ( ! yy_current_buffer ) \
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
	yy_current_buffer->yy_at_bol = at_bol; \
	}
#define YY_INPUT(buf,result,max_size) {\
if (!filelen) { result = YY_NULL;\
} else { while (currentfilepos >= allfilestarts[currentfile+1]) currentfile++;\
buf[0] = *currentfilepos++; filelen--;\
last_pos = current_pos;\
if (buf[0] == '\n') { current_pos.line++; current_pos.column = 1; }\
else { current_pos.column++; }\
current_pos.file = allfilenames[currentfile];\
result = 1;\
}}

// ds\security\authz\authzp.c
#define AuthzpAlloc(s) LocalAlloc(LMEM_FIXED | LMEM_ZEROINIT, (s))

// ds\security\authz\authzp.h
#define AuthzpAlloc(s) LocalAlloc(LMEM_FIXED | LMEM_ZEROINIT, (s))
#define AUTHZ_DYNAMIC_EVALUATION_PRESENT  (AUTHZ_PRINCIPAL_SELF_ACE_PRESENT |  \
                                           AUTHZ_DYNAMIC_ALLOW_ACE_PRESENT  |  \
                                           AUTHZ_DYNAMIC_DENY_ACE_PRESENT)
#define AUTHZ_VALID_SID_ATTRIBUTES (SE_GROUP_ENABLED | SE_GROUP_USE_FOR_DENY_ONLY)
#define FirstAce(Acl) ((PVOID)((PUCHAR)(Acl) + sizeof(ACL)))
#define AuthzObjectAceSid(Ace) \
    ((PSID)(((PUCHAR)&(((PKNOWN_OBJECT_ACE)(Ace))->SidStart)) + \
     (RtlObjectAceObjectTypePresent(Ace) ? sizeof(GUID) : 0 ) + \
     (RtlObjectAceInheritedObjectTypePresent(Ace) ? sizeof(GUID) : 0 )))
#define AuthzAceSid(Ace) ((PSID)&((PKNOWN_ACE)Ace)->SidStart)

// ds\security\authz\test\adl\adllexer.cpp
#define RESOLVE_CHAR(CHAR, MAP, ITER, ITEREND) \
   ((((ITER) = (MAP).find((CHAR)) ) == (ITEREND) ) ? (CHAR) : (*(ITER)).second)

// ds\security\authz\test\adl\adlparser.cpp
#define VALIDATE_USERNAME(TOK) \
    if( NetpwNameValidate( \
                          (WCHAR *)(TOK)->GetValue(), \
                          NAMETYPE_USER, \
                          0) != ERROR_SUCCESS) \
    { \
        this->SetErrorToken( TOK ); \
        throw AdlStatement::ERROR_INVALID_USERNAME; \
    }
#define VALIDATE_DOMAIN(TOK) \
    if( NetpwNameValidate( \
                          (WCHAR *)(TOK)->GetValue(), \
                          NAMETYPE_DOMAIN, \
                          0) != ERROR_SUCCESS) \
    { \
        this->SetErrorToken( TOK ); \
        throw AdlStatement::ERROR_INVALID_DOMAIN; \
    }

// ds\security\authz\test\adl\adlstat.cpp
#define APPEND_QUOTED_STRING(POUTSTLSTRING, INSTRING, SPECIALCHARS, QUOTECHAR) \
  if( wcspbrk( (INSTRING), (SPECIALCHARS) ) ) { \
      (POUTSTLSTRING)->append(&(QUOTECHAR), 1); \
      (POUTSTLSTRING)->append(INSTRING); \
      (POUTSTLSTRING)->append(&(QUOTECHAR), 1); \
  } else { \
      (POUTSTLSTRING)->append(INSTRING); \
  }

// ds\security\authz\test\fundsrm\fundsrm.cpp
#define FirstAce(Acl) ((PVOID)((PUCHAR)(Acl) + sizeof(ACL)))

// ds\security\authz\test\god.c
#define FirstAce(Acl) ((PVOID)((PUCHAR)(Acl) + sizeof(ACL)))

// ds\security\authz\test\mailrm\mailrmp.h
#define WITHIN_TIMERANGE(HOUR, START_HOUR, END_HOUR) \
	( ( (START_HOUR) > (END_HOUR) ) ^ \
	( (HOUR) >= min((START_HOUR), (END_HOUR)) && \
	  (HOUR) <  max((START_HOUR), (END_HOUR))))

// ds\security\authz\test\samplerm\samplerm.h
#define FirstAce(Acl) ((PVOID)((PUCHAR)(Acl) + sizeof(ACL)))

// ds\security\azroles\genobj.h
#define AzpIsSidList( _gol ) \
    ((_gol)->GenericObjectHeads[0] != NULL && \
     (_gol)->GenericObjectHeads[0]->ObjectType == OBJECT_TYPE_SID )

// ds\security\azroles\sample.cxx
#define SAMPLE_DELIM_SIZE (sizeof(SAMPLE_DELIM)-sizeof(WCHAR))
#define HUGE_BUFFER_SIZE (70000*sizeof(WCHAR))

// ds\security\azroles\util.h
#define AzpIsLockedExclusive( _Resource ) \
    ((_Resource)->NumberOfActive == -1 )
#define AzpIsLockedShared( _Resource ) \
    ((_Resource)->NumberOfActive != 0 )

// ds\security\common\cryptdll\utest\md5c.c
#define G(x, y, z) (y ^ (z & (x^y)))	/* optimized version of (((x) & (z)) | ((y) & (~z))) */
#define H(x, y, z) (x ^ y ^ z)
#define I(x, y, z) (y ^ (x | ~z))

// ds\security\common\wxlpc\client\rng.c
#define LockRNG()   EnterCriticalSection( &csRNG )
#define UnlockRNG() LeaveCriticalSection( &csRNG )

// ds\security\common\wxlpc\client\testcli.c
#define fromhex(x)  _hex[x & 0xF]

// ds\security\common\wxlpc\client\wxcli.c
#define ToHex( f ) (HexKey[f & 0xF])
#define FromHex( c )    ( ( ( c >= '0' ) && ( c <= '9') ) ? c - '0' :      \
                          ( ( c >= 'a' ) && ( c <= 'f') ) ? c - 'a' + 10:      \
                          ( ( c >= 'A' ) && ( c <= 'F' ) ) ? c - 'A' + 10: -1 )

// ds\security\common\wxlpc\inc\wxlpcp.h
#define PREPARE_MESSAGE( Message, ApiCode ) \
    (Message).Message.u1.s1.DataLength = sizeof((Message)) - sizeof(PORT_MESSAGE); \
    (Message).Message.u1.s1.TotalLength = sizeof((Message)); \
    (Message).Message.u2.ZeroInit = 0L; \
    (Message).Api = ApiCode ;

// ds\security\common\wxlpc\server\testsrv.c
#define fromhex(x)  _hex[x & 0xF]

// ds\security\cryptoapi\common\pkifmt\pkifmt.cpp
#define CB_BEGINCERT	(sizeof(szBeginCert) - sizeof(TCHAR))
#define CB_ENDCERT	(sizeof(szEndCert) - sizeof(TCHAR))
#define CB_BEGINCERTREQUEST	(sizeof(szBeginCertRequest) - sizeof(TCHAR))
#define CB_ENDCERTREQUEST	(sizeof(szEndCertRequest) - sizeof(TCHAR))
#define CB_BEGINCRL	(sizeof(szBeginCRL) - sizeof(TCHAR))
#define CB_ENDCRL	(sizeof(szEndCRL) - sizeof(TCHAR))

// ds\security\cryptoapi\mincrypt\lib\imagehack.cpp
#define InitializeListHead(ListHead) (\
    (ListHead)->Flink = (ListHead)->Blink = (ListHead))

// ds\security\cryptoapi\pki\activex\capicom\stdafx.h
#define CAPICOM_ASN_ENCODING            (X509_ASN_ENCODING | PKCS_7_ASN_ENCODING)

// ds\security\cryptoapi\pki\activex\xenroll\xmsasn.h
#define SIZE_XMSASN_Module_PDU_0 sizeof(EnhancedKeyUsage)
#define SIZE_XMSASN_Module_PDU_2 sizeof(CSPProvider)
#define SIZE_XMSASN_Module_PDU_3 sizeof(EnrollmentNameValuePair)
#define SIZE_XMSASN_Module_PDU_4 sizeof(CmcAddExtensions)
#define SIZE_XMSASN_Module_PDU_5 sizeof(CmcAddAttributes)
#define SIZE_XMSASN_Module_PDU_6 sizeof(CmcData)
#define SIZE_XMSASN_Module_PDU_7 sizeof(CmcResponseBody)

// ds\security\cryptoapi\pki\certperf\certperf.cpp
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// ds\security\cryptoapi\pki\certstor\certstr.cpp
#define NUM_SUBJECT_ALT_OID (sizeof(rgpszSubjectAltOID) / \
                                         sizeof(rgpszSubjectAltOID[0]))
#define NUM_ISSUER_ALT_OID (sizeof(rgpszIssuerAltOID) / \
                                         sizeof(rgpszIssuerAltOID[0]))
#define NUM_SIMPLE_DISPLAY_ATTR_OID (sizeof(rgpszSimpleDisplayAttrOID) / \
                                        sizeof(rgpszSimpleDisplayAttrOID[0]))
#define NUM_EMAIL_ATTR_OID (sizeof(rgpszEmailAttrOID) / \
                                     sizeof(rgpszEmailAttrOID[0]))
#define NUM_DNS_ATTR_OID (sizeof(rgpszDNSAttrOID) / \
                                     sizeof(rgpszDNSAttrOID[0]))

// ds\security\cryptoapi\pki\certstor\oidinfo.cpp
#define OID_INFO_LEN sizeof(CRYPT_OID_INFO)
#define PREDEFINED_NAME_CNT  (sizeof(PredefinedNameTable) / \
                                    sizeof(PredefinedNameTable[0]))
#define LOCALIZED_GROUP_CNT  (sizeof(LocalizedGroupTable) / \
                                    sizeof(LocalizedGroupTable[0]))

// ds\security\cryptoapi\pki\certstor\policy.cpp
#define NTESTROOTS (sizeof(rgTestRootPublicKeyInfo)/ \
                            sizeof(rgTestRootPublicKeyInfo[0]))
#define MICROSOFT_ROOT_LIST_CNT  (sizeof(MicrosoftRootList) / \
                                        sizeof(MicrosoftRootList[0]))

// ds\security\cryptoapi\pki\certstor\x509.h
#define SIZE_X509_Module_PDU_0 sizeof(EncodedObjectID)
#define SIZE_X509_Module_PDU_2 sizeof(IntegerType)
#define SIZE_X509_Module_PDU_3 sizeof(HugeIntegerType)
#define SIZE_X509_Module_PDU_4 sizeof(OctetStringType)
#define SIZE_X509_Module_PDU_5 sizeof(EnumeratedType)
#define SIZE_X509_Module_PDU_6 sizeof(UtcTime)
#define SIZE_X509_Module_PDU_7 sizeof(AnyString)
#define SIZE_X509_Module_PDU_8 sizeof(Name)
#define SIZE_X509_Module_PDU_9 sizeof(Attributes)
#define SIZE_X509_Module_PDU_10 sizeof(RSAPublicKey)
#define SIZE_X509_Module_PDU_11 sizeof(DSSParameters)
#define SIZE_X509_Module_PDU_12 sizeof(DSSSignature)
#define SIZE_X509_Module_PDU_13 sizeof(DHParameters)
#define SIZE_X509_Module_PDU_14 sizeof(RC2CBCParameters)
#define SIZE_X509_Module_PDU_15 sizeof(SMIMECapabilities)
#define SIZE_X509_Module_PDU_16 sizeof(SubjectPublicKeyInfo)
#define SIZE_X509_Module_PDU_17 sizeof(ChoiceOfTime)
#define SIZE_X509_Module_PDU_18 sizeof(Extensions)
#define SIZE_X509_Module_PDU_19 sizeof(SignedContent)
#define SIZE_X509_Module_PDU_20 sizeof(CertificationRequestInfo)
#define SIZE_X509_Module_PDU_21 sizeof(CertificationRequestInfoDecode)
#define SIZE_X509_Module_PDU_22 sizeof(KeygenRequestInfo)
#define SIZE_X509_Module_PDU_23 sizeof(AuthorityKeyId)
#define SIZE_X509_Module_PDU_24 sizeof(AltNames)
#define SIZE_X509_Module_PDU_25 sizeof(EDIPartyName)
#define SIZE_X509_Module_PDU_26 sizeof(BasicConstraints2)
#define SIZE_X509_Module_PDU_27 sizeof(CertificatePolicies)
#define SIZE_X509_Module_PDU_28 sizeof(CertificatePolicies95)
#define SIZE_X509_Module_PDU_29 sizeof(AuthorityKeyId2)
#define SIZE_X509_Module_PDU_30 sizeof(AuthorityInfoAccess)
#define SIZE_X509_Module_PDU_31 sizeof(CRLDistributionPoints)
#define SIZE_X509_Module_PDU_32 sizeof(ContentInfo)
#define SIZE_X509_Module_PDU_33 sizeof(SeqOfAny)
#define SIZE_X509_Module_PDU_34 sizeof(TimeStampRequest)
#define SIZE_X509_Module_PDU_35 sizeof(ContentInfoOTS)
#define SIZE_X509_Module_PDU_36 sizeof(TimeStampRequestOTS)
#define SIZE_X509_Module_PDU_37 sizeof(EnhancedKeyUsage)
#define SIZE_X509_Module_PDU_38 sizeof(EnrollmentNameValuePair)
#define SIZE_X509_Module_PDU_39 sizeof(CSPProvider)
#define SIZE_X509_Module_PDU_40 sizeof(CertificatePair)
#define SIZE_X509_Module_PDU_41 sizeof(IssuingDistributionPoint)
#define SIZE_X509_Module_PDU_42 sizeof(PolicyMappings)
#define SIZE_X509_Module_PDU_43 sizeof(PolicyConstraints)
#define SIZE_X509_Module_PDU_44 sizeof(CmcAddExtensions)
#define SIZE_X509_Module_PDU_45 sizeof(CmcAddAttributes)
#define SIZE_X509_Module_PDU_46 sizeof(CertificateTemplate)
#define SIZE_X509_Module_PDU_47 sizeof(Attribute)
#define SIZE_X509_Module_PDU_48 sizeof(X942DhParameters)
#define SIZE_X509_Module_PDU_49 sizeof(X942DhOtherInfo)
#define SIZE_X509_Module_PDU_50 sizeof(CertificateToBeSigned)
#define SIZE_X509_Module_PDU_51 sizeof(CertificateRevocationListToBeSigned)
#define SIZE_X509_Module_PDU_52 sizeof(KeyAttributes)
#define SIZE_X509_Module_PDU_53 sizeof(KeyUsageRestriction)
#define SIZE_X509_Module_PDU_54 sizeof(BasicConstraints)
#define SIZE_X509_Module_PDU_55 sizeof(UserNotice)
#define SIZE_X509_Module_PDU_56 sizeof(VerisignQualifier1)
#define SIZE_X509_Module_PDU_57 sizeof(ContentInfoSeqOfAny)
#define SIZE_X509_Module_PDU_58 sizeof(CertificateTrustList)
#define SIZE_X509_Module_PDU_59 sizeof(NameConstraints)
#define SIZE_X509_Module_PDU_60 sizeof(CrossCertDistPoints)
#define SIZE_X509_Module_PDU_61 sizeof(CmcData)
#define SIZE_X509_Module_PDU_62 sizeof(CmcResponseBody)

// ds\security\cryptoapi\pki\chain\chain.cpp
#define SKIP_PARTIAL_ISSUER_CNT     (sizeof(rgSkipPartialIssuer)/ \
                                        sizeof(rgSkipPartialIssuer[0]))
#define AUTH_ROOT_INVALID_LIST_CNT  (sizeof(AuthRootInvalidList) / \
                                        sizeof(AuthRootInvalidList[0]))

// ds\security\cryptoapi\pki\chain\chain.h
#define CERT_CHAIN_REVOCATION_CHECK_ALL ( CERT_CHAIN_REVOCATION_CHECK_END_CERT | \
                                          CERT_CHAIN_REVOCATION_CHECK_CHAIN | \
                                          CERT_CHAIN_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT | \
                                          CERT_CHAIN_REVOCATION_CHECK_CACHE_ONLY )

// ds\security\cryptoapi\pki\pfxlib\des.h
#define DES_TABLESIZE	sizeof(DESTable)

// ds\security\cryptoapi\pki\pfxlib\pfxcmn.h
#define MAKEZERO(arg) ZeroMemory( &arg, sizeof(arg))

// ds\security\cryptoapi\pki\pfxlib\pfxnscp.h
#define SIZE_PFXNSCP_Module_PDU_0 sizeof(RSAData)
#define SIZE_PFXNSCP_Module_PDU_1 sizeof(Attributes)
#define SIZE_PFXNSCP_Module_PDU_2 sizeof(PBEParameter)
#define SIZE_PFXNSCP_Module_PDU_3 sizeof(PvkAdditional)
#define SIZE_PFXNSCP_Module_PDU_4 sizeof(SafeContents)
#define SIZE_PFXNSCP_Module_PDU_5 sizeof(SafeBag)
#define SIZE_PFXNSCP_Module_PDU_6 sizeof(KeyBag)
#define SIZE_PFXNSCP_Module_PDU_7 sizeof(CertCRLBag)
#define SIZE_PFXNSCP_Module_PDU_8 sizeof(CertCRL)
#define SIZE_PFXNSCP_Module_PDU_9 sizeof(X509Bag)
#define SIZE_PFXNSCP_Module_PDU_10 sizeof(SDSICertBag)
#define SIZE_PFXNSCP_Module_PDU_11 sizeof(SecretBag)
#define SIZE_PFXNSCP_Module_PDU_12 sizeof(SecretAdditional)
#define SIZE_PFXNSCP_Module_PDU_13 sizeof(AuthenticatedSafe)
#define SIZE_PFXNSCP_Module_PDU_14 sizeof(Secret)
#define SIZE_PFXNSCP_Module_PDU_15 sizeof(PrivateKeyInfo)
#define SIZE_PFXNSCP_Module_PDU_16 sizeof(PFX)
#define SIZE_PFXNSCP_Module_PDU_17 sizeof(PVKSupportingData)
#define SIZE_PFXNSCP_Module_PDU_18 sizeof(PrivateKey)
#define SIZE_PFXNSCP_Module_PDU_19 sizeof(EncryptedData)
#define SIZE_PFXNSCP_Module_PDU_20 sizeof(ESPVK)
#define SIZE_PFXNSCP_Module_PDU_21 sizeof(EncryptedPrivateKeyInfo)

// ds\security\cryptoapi\pki\pfxlib\pfxpkcs.h
#define SIZE_PFXPKCS_Module_PDU_0 sizeof(ObjectIdentifierType)
#define SIZE_PFXPKCS_Module_PDU_1 sizeof(OctetStringType)
#define SIZE_PFXPKCS_Module_PDU_2 sizeof(IntegerType)
#define SIZE_PFXPKCS_Module_PDU_3 sizeof(RSAPublicKey)
#define SIZE_PFXPKCS_Module_PDU_4 sizeof(RSAPrivateKey)
#define SIZE_PFXPKCS_Module_PDU_5 sizeof(PBEParameter)
#define SIZE_PFXPKCS_Module_PDU_6 sizeof(AttributeSetValue)
#define SIZE_PFXPKCS_Module_PDU_7 sizeof(Attributes)
#define SIZE_PFXPKCS_Module_PDU_8 sizeof(AuthenticatedSafes)
#define SIZE_PFXPKCS_Module_PDU_9 sizeof(SafeContents)
#define SIZE_PFXPKCS_Module_PDU_10 sizeof(SafeBag)
#define SIZE_PFXPKCS_Module_PDU_11 sizeof(CertBag)
#define SIZE_PFXPKCS_Module_PDU_12 sizeof(CRLBag)
#define SIZE_PFXPKCS_Module_PDU_13 sizeof(SecretBag)
#define SIZE_PFXPKCS_Module_PDU_14 sizeof(DigestInfo)
#define SIZE_PFXPKCS_Module_PDU_15 sizeof(MacData)
#define SIZE_PFXPKCS_Module_PDU_16 sizeof(PrivateKeyInfo)
#define SIZE_PFXPKCS_Module_PDU_17 sizeof(PFX)
#define SIZE_PFXPKCS_Module_PDU_18 sizeof(KeyBag)
#define SIZE_PFXPKCS_Module_PDU_19 sizeof(EncryptedData)
#define SIZE_PFXPKCS_Module_PDU_20 sizeof(EncryptedPrivateKeyInfo)
#define SIZE_PFXPKCS_Module_PDU_21 sizeof(Pkcs_8ShroudedKeyBag)

// ds\security\cryptoapi\pki\pfxlib\prvtkey.h
#define SIZE_PRVTKEY_Module_PDU_0 sizeof(RSAPrivateKey)
#define SIZE_PRVTKEY_Module_PDU_1 sizeof(PrivateKeyInfo)
#define SIZE_PRVTKEY_Module_PDU_2 sizeof(EncryptedPrivateKeyInfo)
#define SIZE_PRVTKEY_Module_PDU_3 sizeof(Attribute)

// ds\security\cryptoapi\pki\rpor\msctl.cpp
#define NUM_DEFAULT_STORES          (sizeof(rgDefaultStoreInfo) / \
                                        sizeof(rgDefaultStoreInfo[0]))

// ds\security\cryptoapi\pki\rpor\msrevoke.cpp
#define NUM_DEFAULT_ISSUER_STORES (sizeof(rgDefaultIssuerStores) / \
                                   sizeof(rgDefaultIssuerStores[0]))

// ds\security\cryptoapi\pki\setx509\setx509.cpp
#define OID_INFO_LEN sizeof(CRYPT_OID_INFO)
#define OID_INFO_AFTER_CNT (sizeof(OIDInfoAfterTable) / \
                                        sizeof(OIDInfoAfterTable[0]))
#define OID_INFO_BEFORE_CNT (sizeof(OIDInfoBeforeTable) / \
                                        sizeof(OIDInfoBeforeTable[0]))
#define LOCALIZED_NAME_CNT  (sizeof(LocalizedNameTable) / \
                                    sizeof(LocalizedNameTable[0]))

// ds\security\cryptoapi\pki\setx509\x509.h
#define SIZE_X509_Module_PDU_0 sizeof(SETAccountAlias)
#define SIZE_X509_Module_PDU_1 sizeof(SETHashedRootKey)
#define SIZE_X509_Module_PDU_2 sizeof(SETCertificateType)
#define SIZE_X509_Module_PDU_3 sizeof(SETMerchantData)

// ds\security\cryptoapi\pki\wincrmsg\pkcs.h
#define SIZE_PKCS_Module_PDU_0 sizeof(ObjectID)
#define SIZE_PKCS_Module_PDU_1 sizeof(ObjectIdentifierType)
#define SIZE_PKCS_Module_PDU_2 sizeof(OctetStringType)
#define SIZE_PKCS_Module_PDU_3 sizeof(IntegerType)
#define SIZE_PKCS_Module_PDU_4 sizeof(HugeIntegerType)
#define SIZE_PKCS_Module_PDU_5 sizeof(AlgorithmIdentifier)
#define SIZE_PKCS_Module_PDU_6 sizeof(AlgorithmIdentifierNC2)
#define SIZE_PKCS_Module_PDU_7 sizeof(AlgorithmIdentifiers)
#define SIZE_PKCS_Module_PDU_8 sizeof(AttributeSetValue)
#define SIZE_PKCS_Module_PDU_9 sizeof(AttributeSetValueNC)
#define SIZE_PKCS_Module_PDU_10 sizeof(SetOfAny)
#define SIZE_PKCS_Module_PDU_11 sizeof(AttributeNC2)
#define SIZE_PKCS_Module_PDU_12 sizeof(Attributes)
#define SIZE_PKCS_Module_PDU_13 sizeof(AttributesNC)
#define SIZE_PKCS_Module_PDU_14 sizeof(AttributesNC2)
#define SIZE_PKCS_Module_PDU_15 sizeof(CrlsNC)
#define SIZE_PKCS_Module_PDU_16 sizeof(CertificatesNC)
#define SIZE_PKCS_Module_PDU_17 sizeof(IssuerAndSerialNumber)
#define SIZE_PKCS_Module_PDU_18 sizeof(ContentInfo)
#define SIZE_PKCS_Module_PDU_19 sizeof(ContentInfoNC)
#define SIZE_PKCS_Module_PDU_20 sizeof(DigestAlgorithmIdentifiersNC)
#define SIZE_PKCS_Module_PDU_21 sizeof(SignerInfos)
#define SIZE_PKCS_Module_PDU_22 sizeof(DigestAlgorithmBlobs)
#define SIZE_PKCS_Module_PDU_23 sizeof(SignerInfosNC)
#define SIZE_PKCS_Module_PDU_24 sizeof(SignerInfoWithAABlobs)
#define SIZE_PKCS_Module_PDU_25 sizeof(SignerInfoWithAABlob)
#define SIZE_PKCS_Module_PDU_26 sizeof(SignerInfoWithAttrBlobs)
#define SIZE_PKCS_Module_PDU_27 sizeof(SignerInfoWithBlobs)
#define SIZE_PKCS_Module_PDU_28 sizeof(RecipientInfos)
#define SIZE_PKCS_Module_PDU_29 sizeof(EncryptedContentInfo)
#define SIZE_PKCS_Module_PDU_30 sizeof(RecipientInfo)
#define SIZE_PKCS_Module_PDU_31 sizeof(SignedAndEnvelopedData)
#define SIZE_PKCS_Module_PDU_32 sizeof(DigestedData)
#define SIZE_PKCS_Module_PDU_33 sizeof(EncryptedData)
#define SIZE_PKCS_Module_PDU_34 sizeof(CertIdentifier)
#define SIZE_PKCS_Module_PDU_35 sizeof(OriginatorInfo)
#define SIZE_PKCS_Module_PDU_36 sizeof(OriginatorInfoNC)
#define SIZE_PKCS_Module_PDU_37 sizeof(CmsRecipientInfos)
#define SIZE_PKCS_Module_PDU_38 sizeof(KeyTransRecipientInfo)
#define SIZE_PKCS_Module_PDU_39 sizeof(DigestInfo)
#define SIZE_PKCS_Module_PDU_40 sizeof(SignedData)
#define SIZE_PKCS_Module_PDU_41 sizeof(SignerInfo)
#define SIZE_PKCS_Module_PDU_42 sizeof(SignedDataWithBlobs)
#define SIZE_PKCS_Module_PDU_43 sizeof(EnvelopedData)
#define SIZE_PKCS_Module_PDU_44 sizeof(CmsEnvelopedData)
#define SIZE_PKCS_Module_PDU_45 sizeof(MailListRecipientInfo)
#define SIZE_PKCS_Module_PDU_46 sizeof(KeyAgreeRecipientInfo)
#define SIZE_PKCS_Module_PDU_47 sizeof(CmsRecipientInfo)

// ds\security\cryptoapi\pkisign\mssign32\global.hxx
#define ZERO(x) ZeroMemory(&x, sizeof(x))

// ds\security\cryptoapi\pkitrust\common\cbfile.hxx
#define     BFILE_HEADERSIZE    (sizeof(BFILE_HEADER) + BFILE_SIZEOFSIG)

// ds\security\cryptoapi\pkitrust\common\cjetblue.cpp
#define     CHK_FUNC(fp, nm)  this->CheckOrLoadFunc((void **)&fp, nm)

// ds\security\cryptoapi\pkitrust\common\eventlst.h
#define AcquireReadLock(sListLock)              (LockWaitToRead(&sListLock))
#define AcquireWriteLock(sListLock)          (LockWaitToWrite(&sListLock))

// ds\security\cryptoapi\pkitrust\initpki\initacl.cpp
#define HKLM_REGPATH_CNT    (sizeof(rgpwszHKLMRegPath) / \
                                sizeof(rgpwszHKLMRegPath[0]))

// ds\security\cryptoapi\pkitrust\mssip32\cabinet.h
#define IS_CONTD_FORWARD(ifold) ((ifold & 0xfffe) == ifoldCONTINUED_TO_NEXT)
#define IS_CONTD_BACK(ifold) ((ifold & 0xfffd) == ifoldCONTINUED_FROM_PREV)

// ds\security\cryptoapi\pkitrust\mssip32\peimage2.cpp
#define InitializeListHead(ListHead) (\
    (ListHead)->Flink = (ListHead)->Blink = (ListHead))

// ds\security\cryptoapi\pkitrust\mssip32\sipobjcb.hxx
#define RESERVE_CNT_HDR_LEN     (sizeof(USHORT) * 2)    // cbJund & cbSig

// ds\security\cryptoapi\pkitrust\tools\makerootctl\makerootctl.cpp
#define SEQ_LEN     (sizeof(FILETIME) + 1)

// ds\security\cryptoapi\pkitrust\tools\mscrlrev\mscrlrev.cpp
#define NUM_DEFAULT_ISSUER_STORES (sizeof(rgDefaultIssuerStores) / \
                                    sizeof(rgDefaultIssuerStores[0]))

// ds\security\cryptoapi\pkitrust\wintrust\wtasn.h
#define SIZE_WTASN_Module_PDU_0 sizeof(ObjectID)
#define SIZE_WTASN_Module_PDU_1 sizeof(SpcMinimalCriteria)
#define SIZE_WTASN_Module_PDU_2 sizeof(UtcTime)
#define SIZE_WTASN_Module_PDU_3 sizeof(SpcLink)
#define SIZE_WTASN_Module_PDU_4 sizeof(SpcPeImageData)
#define SIZE_WTASN_Module_PDU_5 sizeof(SpcSigInfo)
#define SIZE_WTASN_Module_PDU_6 sizeof(SpcFinancialCriteria)
#define SIZE_WTASN_Module_PDU_7 sizeof(SpcStatementType)
#define SIZE_WTASN_Module_PDU_8 sizeof(SpcSpOpusInfo)
#define SIZE_WTASN_Module_PDU_9 sizeof(NameValue)
#define SIZE_WTASN_Module_PDU_10 sizeof(NameValues)
#define SIZE_WTASN_Module_PDU_12 sizeof(SpcIndirectDataContent)

// ds\security\cryptoapi\pkitrust\wintrust\wvtver1.cpp
#define IsEqualActionID( id1, id2)    (!memcmp(id1, id2, sizeof(GUID)))

// ds\security\cryptoapi\secstor\include\pmacros.h
#define  PSTMAP_EXCEPTION_TO_ERROR(__x__) \
    ((__x__ == 0xC0000005) ? 998 : PST_E_UNKNOWN_EXCEPTION)

// ds\security\cryptoapi\secstor\svr\tlhelp32.h
#define TH32CS_SNAPALL	    (TH32CS_SNAPHEAPLIST | TH32CS_SNAPPROCESS | TH32CS_SNAPTHREAD | TH32CS_SNAPMODULE)

// ds\security\cryptoapi\test\capi20\certtest\certtest.cpp
#define NUM_SYSTEM_LOCATION (sizeof(rgSystemLocationInfo) / \
                                sizeof(rgSystemLocationInfo[0]))

// ds\security\cryptoapi\test\capi20\txenrol\txenrol.cpp
#define HASHFROMCERT(a, b) CryptHashCertificate(NULL, 0, X509_ASN_ENCODING, (a)->pbCertEncoded, (a)->cbCertEncoded, (b)->pbData, &(b)->cbData)

// ds\security\cryptoapi\ui\wizards\mgrcert.cpp
#define TAB_STORE_NAME_CNT (sizeof(rgpwszTabStoreName) / \
                                sizeof(rgpwszTabStoreName[0]))

// ds\security\csps\cryptoflex\scardlib\registry.h
#define REG_OPTION_EXISTS (~REG_LEGAL_OPTION)

// ds\security\csps\cryptoflex\slbzip\trees.cpp
#define Smaller(Tree, Tmp1, Tmp2) \
 (Tree[Tmp1].FrequencyCode.Frequency < Tree[Tmp2].FrequencyCode.Frequency || \
 (Tree[Tmp1].FrequencyCode.Frequency == Tree[Tmp2].FrequencyCode.Frequency \
 && Depth[Tmp1] <= Depth[Tmp2]))

// ds\security\csps\wfsccsp\cspcache.h
#define MAX_KEY_SIZE            (50 * sizeof(CHAR))

// ds\security\dsrole\inc\dssetp.h
#define DSROLEP_MIDL_ALLOC_AND_COPY_STRING_ERROR( dest, src, err )                              \
if ( (src) ) {                                                                                  \
    (dest) = MIDL_user_allocate(  (wcslen( (src) ) + 1) * sizeof( WCHAR ) );                    \
    if ( !(dest) ) {                                                                            \
        err = ERROR_NOT_ENOUGH_MEMORY;                                                          \
    } else {                                                                                    \
        wcscpy((dest), (src));                                                                  \
    }                                                                                           \
} else {                                                                                        \
    (dest) = NULL;                                                                              \
}

// ds\security\dsrole\server\dispatch.c
    #define IS_GUID_PRESENT(x)  (memcmp(&(x), &NullGuid, sizeof(GUID)))

// ds\security\dsrole\server\dsrolepl.h
#define DsRolepUnicodestringtowstr( s, u )                                                      \
{ s = (WCHAR*)malloc(u.Length+sizeof(WCHAR));                                                               \
  if (s){                                                                                       \
      CopyMemory(s,u.Buffer,u.Length);                                                          \
      s[u.Length/sizeof(WCHAR)] = L'\0';                                                        \
  }                                                                                             \
}

// ds\security\dsrole\server\ophandle.h
#define DSROLEP_OPERATION_ACTIVE( Op ) \
    ( (Op == DSROLEP_IDLE) || (Op == DSROLEP_NEED_REBOOT) ? FALSE : TRUE )
#define LockOpHandle() RtlAcquireResourceExclusive( &DsRolepCurrentOperationHandle.CurrentOpLock, TRUE );
#define DSROLEP_CHECK_FOR_CANCEL( WErr )                                  \
{                                                                         \
    LockOpHandle();                                                       \
    if( DsRolepCurrentOperationHandle.OperationState == DSROLEP_CANCELING \
     && (WErr == ERROR_SUCCESS)) {                                        \
                                                                          \
        WErr = ERROR_CANCELLED;                                           \
    }                                                                     \
    UnlockOpHandle();                                                     \
}

// ds\security\dsrole\server\secure.c
#define DSROLE_ALL_ACCESS            (STANDARD_RIGHTS_REQUIRED    | \
                                      DSROLE_ROLE_CHANGE_ACCESS )

// ds\security\gina\gpext\appmgmt\cstore\filter.hxx
#define SERVERSIDE_FILTER_ADMINISTRATIVE       L"(|(|(msiScriptName=*A*)(msiScriptName=*P*))(!(msiScriptName=*)))"
#define SERVERSIDE_FILTER_POLICY               L"(|(|(msiScriptName=*A*)(&(canUpgradeScript=*)(msiScriptName=*P*)))(!(msiScriptName=*)))"

// ds\security\gina\gpext\appmgmt\server\appinfo.hxx
#define AppPresent( AppState )  \
                ( \
                 (INSTALLSTATE_ADVERTISED == AppState) || \
                 (INSTALLSTATE_LOCAL == AppState) || \
                 (INSTALLSTATE_SOURCE == AppState) || \
                 (INSTALLSTATE_DEFAULT == AppState) \
                )

// ds\security\gina\mpnotify\mpnotify.h
#define MPPrint(s)  KdPrint(("MPNOTIFY: ")); \
                    KdPrint(s);            \
                    KdPrint(("\n"));

// ds\security\gina\msgina\brand.h
#define ShowDlgItem(h, i, f)    \
            ShowWindow(GetDlgItem(h, i), f ? SW_SHOW:SW_HIDE)

// ds\security\gina\msgina\domain.c
#define LockDomainCache( x )    RtlEnterCriticalSection( &(x)->CriticalSection )
#define UnlockDomainCache( x )  RtlLeaveCriticalSection( &(x)->CriticalSection )

// ds\security\gina\rsoputil\rsopinc.h
#define RSOP_ALL_PERMS              (WBEM_ENABLE | WBEM_METHOD_EXECUTE | WBEM_FULL_WRITE_REP | WBEM_PARTIAL_WRITE_REP | \
                                    WBEM_WRITE_PROVIDER | WBEM_REMOTE_ACCESS | READ_CONTROL |  WRITE_DAC)
#define RSOP_READ_PERMS             (WBEM_ENABLE | WBEM_METHOD_EXECUTE | WBEM_REMOTE_ACCESS | READ_CONTROL )

// ds\security\gina\snapins\ade\common.h
#define OLESAFE_COPYSTRING(szO, szI) {if (szI) {int i_dontcollidewithanything = wcslen(szI); szO=(OLECHAR *)OLEALLOC(sizeof(OLECHAR) * (i_dontcollidewithanything+1)); if (szO) wcscpy(szO, szI);} else szO=NULL;}

// ds\security\gina\snapins\fde\common.h
#define FIX_THREAD_STATE_MFC_BUG() \
                AFX_MODULE_THREAD_STATE* pState = AfxGetModuleThreadState(); \
                CWinThread _dummyWinThread; \
                if (pState->m_pCurrentWinThread == NULL) \
                { \
                    pState->m_pCurrentWinThread = &_dummyWinThread; \
                }
#define GETINDEX(x)         (((x) < IDS_DIRS_END && (x) >= IDS_DIRS_START) ? ((x) - IDS_DIRS_START) : -1)
#define OLESAFE_COPYSTRING(szO, szI) {if (szI) {int i_dontcollidewithanything = wcslen(szI); szO=(OLECHAR *)OLEALLOC(sizeof(OLECHAR) * (i_dontcollidewithanything+1)); wcscpy(szO, szI);} else szO=NULL;}

// ds\security\gina\snapins\gpedit\events.h
#define ISDIGIT(c)  ((c) >= TEXT('0') && (c) <= TEXT('9'))

// ds\security\gina\snapins\gpedit\gpobj.h
#define PDM_CHANGEBUTTONTEXT    (WM_USER + 1000)

// ds\security\gina\uenvext\uenvext.cpp
#define PRINT_SIZE(_x_) {dprintf(#_x_" - 0x%X\n", sizeof(_x_));}

// ds\security\gina\userenv\profile\hkcr.c
#define MAX_HIVE_DIR_CCH           (MAX_PATH + 1 + sizeof(CLASSES_SUBDIRECTORY))

// ds\security\gina\userenv\utils\profstr.cpp
#define IS_LONG_FILE_NAME(lpFileName) ((lpFileName[0] == TEXT('\\')) && (lpFileName[1] == TEXT('\\')) && (lpFileName[2] == TEXT('?')))

// ds\security\gina\userinit\userinit.h
#define UIPrint(s)  KdPrint(("USERINIT: ")); \
                    KdPrint(s);            \
                    KdPrint(("\n"));

// ds\security\inc\cnvcrypt.h
#define CertHelperVerifySignature(hCryptProv, dwCertEncodingType, \
        pbEncoded, cbEncoded, pIssuerInfo) \
    CryptVerifyCertificateSignature(hCryptProv, dwCertEncodingType, \
        pbEncoded, cbEncoded, &pIssuerInfo->SubjectPublicKeyInfo)
#define CertEncodeToBeSigned(dwEncodingType, dwContentType, pvInfo, \
        pbEncodedToBeSigned, pcbEncodedToBeSigned) \
    CryptEncodeObject(dwEncodingType, \
        (dwContentType == CERT_CONTENT) ? X509_CERT_TO_BE_SIGNED : \
        ((dwContentType == CRL_CONTENT) ? X509_CERT_CRL_TO_BE_SIGNED : \
            X509_CERT_REQUEST_TO_BE_SIGNED), \
        pvInfo, pbEncodedToBeSigned, pcbEncodedToBeSigned)
#define CertDecodeToBeSigned(dwEncodingType, dwContentType, \
        pbEncoded, cbEncoded, pvInfo, pcbInfo) \
    CryptDecodeObject(dwEncodingType, \
        (dwContentType == CERT_CONTENT) ? X509_CERT_TO_BE_SIGNED : \
        ((dwContentType == CRL_CONTENT) ? X509_CERT_CRL_TO_BE_SIGNED : \
            X509_CERT_REQUEST_TO_BE_SIGNED), \
        pbEncoded, cbEncoded, 0, pvInfo, pcbInfo)

// ds\security\inc\pstdef.h
#define     PST_GENERIC_WRITE       (PST_WRITE | PST_CREATE_TYPE | PST_CREATE_SUBTYPE)

// ds\security\inc\safelock.h
#define SafeEnterResourceCritsec( _resrc )          RtlEnterCriticalSection( &(_resrc)->Resource.CriticalSection )
#define SafeLeaveResourceCritsec( _resrc )          RtlLeaveCriticalSection( &(_resrc)->Resource.CriticalSection )
#define SafeEnterResourceCritsec( _resrc )          RtlEnterCriticalSection( &(_resrc)->CriticalSection )
#define SafeLeaveResourceCritsec( _resrc )          RtlLeaveCriticalSection( &(_resrc)->CriticalSection )

// ds\security\ntmarta\newinc\access.hxx
    #define AccAlloc(size)  LocalAlloc(LMEM_FIXED | LMEM_ZEROINIT, size)
#define ACC_ALLOC_AND_COPY_GUID(pInGuid, pOutGuid, err)                 \
pOutGuid = (GUID *)AccAlloc(sizeof(GUID));                              \
if(pOutGuid == NULL)                                                    \
{                                                                       \
    err = ERROR_NOT_ENOUGH_MEMORY;                                      \
}                                                                       \
else                                                                    \
{                                                                       \
    memcpy(pOutGuid, pInGuid, sizeof(GUID));                            \
}
#define IS_UNC_PATH(wsz, wl)                                            \
    ((wl) > 2 && (wsz)[0] == L'\\' && (wsz)[1] == L'\\')
#define IS_FILE_PATH(wsz, wl)                                           \
    ((wl) >= 1 && (wsz)[1] == L':')

// ds\security\ntmarta\newsrc\filctx.cpp
#define I_MartaFileZeroAlloc(size)     \
            LocalAlloc(LMEM_FIXED | LMEM_ZEROINIT, size)

// ds\security\ntmarta\newsrc\init.c
    #define IsObjectAceType(Ace) (                                              \
        (((PACE_HEADER)(Ace))->AceType >= ACCESS_MIN_MS_OBJECT_ACE_TYPE) && \
            (((PACE_HEADER)(Ace))->AceType <= ACCESS_MAX_MS_OBJECT_ACE_TYPE)    \
                )

// ds\security\ntmarta\newsrc\regctx.cpp
#define I_MartaRegZeroAlloc(size)     \
            LocalAlloc(LMEM_FIXED | LMEM_ZEROINIT, size)

// ds\security\ntmarta\newsrc\rewrite.cxx
#define MARTA_SD_NOT_PROTECTED(sd, si)                                         \
        ((MARTA_DACL_NOT_PROTECTED((sd), (si))) ||                             \
         (MARTA_SACL_NOT_PROTECTED((sd), (si))))

// ds\security\ntmarta\test\file\file.c
#define SetSecurityForPath(path,usehandle,handle,access)            \
(usehandle == TRUE ?                                                \
    SetSecurityInfoExW(handle,                                      \
                       SE_FILE_OBJECT,                              \
                       DACL_SECURITY_INFORMATION,                   \
                       NULL,                                        \
                       access,                                      \
                       NULL,                                        \
                       NULL,                                        \
                       NULL,                                        \
                       NULL)        :                               \
    SetNamedSecurityInfoExW(path,                                   \
                            SE_FILE_OBJECT,                         \
                            DACL_SECURITY_INFORMATION,              \
                            NULL,                                   \
                            access,                                 \
                            NULL,                                   \
                            NULL,                                   \
                            NULL,                                   \
                            NULL))

// ds\security\ntmarta\test\service\service.c
#define SetSecurityForService(svc,usehandle,handle,access)          \
(usehandle == TRUE ?                                                \
    SetSecurityInfoExW(handle,                                      \
                       SE_SERVICE,                                  \
                       DACL_SECURITY_INFORMATION,                   \
                       NULL,                                        \
                       access,                                      \
                       NULL,                                        \
                       NULL,                                        \
                       NULL,                                        \
                       NULL)        :                               \
    SetNamedSecurityInfoExW(svc,                                    \
                            SE_SERVICE,                             \
                            DACL_SECURITY_INFORMATION,              \
                            NULL,                                   \
                            access,                                 \
                            NULL,                                   \
                            NULL,                                   \
                            NULL,                                   \
                            NULL))

// ds\security\ntmarta\utest\ntmartat.c
#define CMDLINE_MATCH(index, str, len)                      \
(_strnicmp(argv[index],str,len) == 0 && argv[index][len] == ':')

// ds\security\passport\atlmfc\atlcoll.h
#define _DECLARE_PRIMITIVE_TRAITS( T ) \
	template<> \
	class CElementTraits< T > : \
		public CPrimitiveElementTraits< T > \
	{ \
	};

// ds\security\passport\atlmfc\atlcom.h
#define END_PROPERTY_MAP() \
			{NULL, 0, NULL, &IID_NULL, 0, 0, 0} \
		}; \
		return pPropMap; \
	}
#define END_PROP_MAP() \
			{NULL, 0, NULL, &IID_NULL, 0, 0, 0} \
		}; \
		return pPropMap; \
	}
#define DECLARE_GET_CONTROLLING_UNKNOWN() public:\
	virtual IUnknown* GetControllingUnknown() throw() {return GetUnknown();}
#define END_ATTRCOM_MAP() \
	{NULL, 0, 0}}; return _entries;}
#define IMPLEMENTED_CATEGORY( catid ) { _ATL_CATMAP_ENTRY_IMPLEMENTED, &catid },
#define REQUIRED_CATEGORY( catid ) { _ATL_CATMAP_ENTRY_REQUIRED, &catid },
#define DECLARE_OBJECT_DESCRIPTION(x)\
	static LPCTSTR WINAPI GetObjectDescription() throw()\
	{\
		return _T(x);\
	}
#define DECLARE_NO_REGISTRY()\
	static HRESULT WINAPI UpdateRegistry(BOOL /*bRegister*/) throw()\
	{return S_OK;}
#define END_SERVICE_MAP() \
		return E_NOINTERFACE; \
	}
#define END_SINK_MAP() {0, NULL, 0, 0, NULL, NULL} }; return map;}

// ds\security\passport\atlmfc\atlconv.h
#define A2W(lpa) (\
	((_lpa = lpa) == NULL) ? NULL : (\
		_convert = (lstrlenA(_lpa)+1),\
		ATLA2WHELPER((LPWSTR) alloca(_convert*2), _lpa, _convert, _acp)))
#define W2A(lpw) (\
	((_lpw = lpw) == NULL) ? NULL : (\
		_convert = (lstrlenW(_lpw)+1)*2,\
		ATLW2AHELPER((LPSTR) alloca(_convert), _lpw, _convert, _acp)))
#define DEVMODEW2A(lpw)\
	((lpw == NULL) ? NULL : ATLDEVMODEW2A((LPDEVMODEA)alloca(sizeof(DEVMODEA)+lpw->dmDriverExtra), lpw))
#define DEVMODEA2W(lpa)\
	((lpa == NULL) ? NULL : ATLDEVMODEA2W((LPDEVMODEW)alloca(sizeof(DEVMODEW)+lpa->dmDriverExtra), lpa))
#define TEXTMETRICW2A(lptmw)\
	((lptmw == NULL) ? NULL : ATLTEXTMETRICW2A((LPTEXTMETRICA)alloca(sizeof(TEXTMETRICA)), lptmw))
#define TEXTMETRICA2W(lptma)\
	((lptma == NULL) ? NULL : ATLTEXTMETRICA2W((LPTEXTMETRICW)alloca(sizeof(TEXTMETRICW)), lptma))

// ds\security\passport\atlmfc\atldbcli.h
#define END_ACCESSOR_MAP() \
		; \
		*pColumns = nColumns; \
		return S_OK; \
	}
#define _SIZE_TYPE(data) sizeof(((_classtype*)0)->data)
#define END_PARAM_MAP() \
		*pColumns = nColumns; \
		return S_OK; \
	}

// ds\security\passport\atlmfc\atlisapi.h
#define ATLS_EXTENSION_LEN (sizeof(ATL_DEFAULT_STENCIL_EXTENSION)-2)

// ds\security\passport\atlmfc\atlperf.h
#define END_PERF_MAP() \
			return S_OK; \
		}
#define END_COUNTER_MAP() \
			return S_OK; \
		}
#define BEGIN_PERF_MAP(AppName) \
	private: \
		LPCTSTR GetAppName() const throw() { return AppName; }

// ds\security\passport\atlmfc\atlserr.h
#define VALIDATION_SUCCEEDED(x) (((x == VALIDATION_S_OK) || (x == VALIDATION_S_EMPTY )))

// ds\security\passport\atlmfc\atlsimpstr.h
#define _ST( psz ) ATL::CStaticString< TCHAR, sizeof( _T( psz ) ) >( _T( psz ) )
#define _SA( psz ) ATL::CStaticString< char, sizeof( psz ) >( psz )
#define _SW( psz ) ATL::CStaticString< wchar_t, sizeof( L##psz ) >( L##psz )

// ds\security\passport\atlmfc\atlspriv.h
#define ATL_MAX_QUERYSET (sizeof(WSAQUERYSET) + 4096)

// ds\security\passport\atlmfc\atltrace.h
#define DECLARE_TRACE_CATEGORY( name ) extern ATL::CTraceCategory name;
#define DECLARE_NOUIASSERT() ATL::CNoUIAssertHook _g_NoUIAssertHook;

// ds\security\passport\atlmfc\bmio.h
#define	BMGFLUSH_ALL	( BMGFLUSH_IMPORTERS | BMGFLUSH_EXPORTERS | BMGFLUSH_CONVERTERS )
#define	BMTHINT_ENTIRESURFACE	( 0x8 | BMTHINT_FULLWIDTH | BMTHINT_TOPDOWN | BMTHINT_BOTTOMUP )

// ds\security\passport\common\crypt\sha.cpp
#define R0(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk0(i)+0x5A827999+rol(v,5);w=rol(w,30);
#define R1(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk(i)+0x5A827999+rol(v,5);w=rol(w,30);
#define R2(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0x6ED9EBA1+rol(v,5);w=rol(w,30);
#define R3(v,w,x,y,z,i) z+=(((w|x)&y)|(w&x))+blk(i)+0x8F1BBCDC+rol(v,5);w=rol(w,30);
#define R4(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0xCA62C1D6+rol(v,5);w=rol(w,30);

// ds\security\passport\common\lkrhash\lkhash.cpp
#define INIT_ALLOCATOR_LHTSUBCLASS(CLASS, N)                    \
    LKHASH_ALLOCATOR_INIT(CLKLinearHashTable::CLASS, N, f);     \
#define UNINIT_ALLOCATOR_LHTSUBCLASS(CLASS)            \
    LKHASH_ALLOCATOR_UNINIT(CLKLinearHashTable::CLASS);\

// ds\security\passport\common\lkrhash\lkrhash.cpp
#define INIT_ALLOCATOR_LHTSUBCLASS(CLASS, N)                    \
    LKRHASH_ALLOCATOR_INIT(CLKRLinearHashTable::CLASS, N, f);     \
#define UNINIT_ALLOCATOR_LHTSUBCLASS(CLASS)            \
    LKRHASH_ALLOCATOR_UNINIT(CLKRLinearHashTable::CLASS);\

// ds\security\passport\common\lkrhash\locks.cpp
# define LOCK_STATISTICS_DATA(CLASS)            \
LONG        CLASS::sm_cTotalLocks       = 0;    \
LONG        CLASS::sm_cContendedLocks   = 0;    \
LONG        CLASS::sm_nSleeps           = 0;    \
LONGLONG    CLASS::sm_cTotalSpins       = 0;    \
LONG        CLASS::sm_nReadLocks        = 0;    \
LONG        CLASS::sm_nWriteLocks       = 0

// ds\security\passport\common\perflibrary\perfutils.h
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// ds\security\passport\include\listmacr.h
#define InitializeListHead(ListHead) (\
    (ListHead)->Flink = (ListHead)->Blink = (ListHead))
#define IsListEmpty(ListHead) \
    ((ListHead)->Flink == (ListHead))
#define RemoveHeadList(ListHead) \
    (ListHead)->Flink;\
    {RemoveEntryList((ListHead)->Flink)}
#define RemoveTailList(ListHead) \
    (ListHead)->Blink;\
    {RemoveEntryList((ListHead)->Blink)}
#define InsertTailList(ListHead,Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_ListHead;\
    _EX_ListHead = (ListHead);\
    _EX_Blink = _EX_ListHead->Blink;\
    (Entry)->Flink = _EX_ListHead;\
    (Entry)->Blink = _EX_Blink;\
    _EX_Blink->Flink = (Entry);\
    _EX_ListHead->Blink = (Entry);\
    }
#define InsertHeadList(ListHead,Entry) {\
    PLIST_ENTRY _EX_Flink;\
    PLIST_ENTRY _EX_ListHead;\
    _EX_ListHead = (ListHead);\
    _EX_Flink = _EX_ListHead->Flink;\
    (Entry)->Flink = _EX_Flink;\
    (Entry)->Blink = _EX_ListHead;\
    _EX_Flink->Blink = (Entry);\
    _EX_ListHead->Flink = (Entry);\
    }

// ds\security\passport\include\lkhash.h
# define LKHASH_ALLOCATOR_NEW(C, N)                             \
    const ALLOC_CACHE_CONFIGURATION acc = { 1, N, sizeof(C) };  \
    C::sm_palloc = new ALLOC_CACHE_HANDLER("IISRTL:" #C, &acc);

// ds\security\passport\include\lkrhash.h
# define LKRHASH_ALLOCATOR_NEW(C, N)                            \
    const ALLOC_CACHE_CONFIGURATION acc = { 1, N, sizeof(C) };  \
    C::sm_palloc = new ALLOC_CACHE_HANDLER("IISRTL:" #C, &acc);
# define LKRHASH_ALLOCATOR_NEW(C, N)                            \
    C::sm_palloc = new FastHeap(sizeof(C));

// ds\security\passport\include\locks.h
# define LOCK_INSTRUMENTATION_INIT(pszName)         \
    m_nContentionSpins = 0;                         \
    m_nContentions = 0;                             \
    m_nSleeps = 0;                                  \
    m_nReadLocks = 0;                               \
    m_nWriteLocks = 0;                              \
    ++sm_cTotalLocks;                               \
    if (pszName == NULL)                            \
        m_szName[0] = '\0';                         \
    else                                            \
        strncpy(m_szName, pszName, sizeof(m_szName))

// ds\security\passport\include\nt\des.h
#define DES_TABLESIZE   (sizeof(DESTable))
#define DESX_TABLESIZE  (sizeof(DESXTable))

// ds\security\passport\include\nt\tripldes.h
#define DES3_TABLESIZE  sizeof(DES3TABLE)

// ds\security\passport\include\stock.h
#define ALL_FILE_ATTRIBUTES            (FILE_ATTRIBUTE_READONLY |\
                                        FILE_ATTRIBUTE_HIDDEN |\
                                        FILE_ATTRIBUTE_SYSTEM |\
                                        FILE_ATTRIBUTE_DIRECTORY |\
                                        FILE_ATTRIBUTE_ARCHIVE |\
                                        FILE_ATTRIBUTE_NORMAL |\
                                        FILE_ATTRIBUTE_TEMPORARY |\
                                        FILE_ATTRIBUTE_ATOMIC_WRITE |\
                                        FILE_ATTRIBUTE_XACTION_WRITE)
#define IS_SLASH(ch)                      ((ch) == SLASH || (ch) == BACKSLASH)

// ds\security\passport\passportmanager\helperfuncs.cpp
#define ToHexDigit(x) (('0' <= x && x <= '9') ? (x - '0') : (tolower(x) - 'a' + 10))

// ds\security\passport\passportmanager\ticket.h
#define  SecureLevelFromSecProp(s)  (s & 0x000000ff)

// ds\security\passport\passportmanager\variantutils.h
#define DEFAULTARG(v) (v.vt==VT_ERROR && v.scode==DISP_E_PARAMNOTFOUND)
#define HASARG(v) (v.vt!=VT_ERROR || v.scode!=DISP_E_PARAMNOTFOUND)

// ds\security\passport\pmconfig\pmcfg.h
#define GET_WM_COMMAND_ID(wp, lp)               (wp)

// ds\security\protocols\digest\cred.h
#define SSP_TOKEN_ACCESS (READ_CONTROL              |\
                          WRITE_DAC                 |\
                          TOKEN_DUPLICATE           |\
                          TOKEN_IMPERSONATE         |\
                          TOKEN_QUERY               |\
                          TOKEN_QUERY_SOURCE        |\
                          TOKEN_ADJUST_PRIVILEGES   |\
                          TOKEN_ADJUST_GROUPS       |\
                          TOKEN_ADJUST_DEFAULT)

// ds\security\protocols\kerberos\client2\chicago\ntcalls.cxx
#define IsLeapYear(YEARS) (                        \
    (((YEARS) % 400 == 0) ||                       \
     ((YEARS) % 100 != 0) && ((YEARS) % 4 == 0)) ? \
        TRUE                                       \
    :                                              \
        FALSE                                      \
    )
#define MaxDaysInMonth(YEAR,MONTH) (                                      \
    IsLeapYear(YEAR) ?                                                    \
        LeapYearDaysPrecedingMonth[(MONTH) + 1] -                         \
                                    LeapYearDaysPrecedingMonth[(MONTH)]   \
    :                                                                     \
        NormalYearDaysPrecedingMonth[(MONTH) + 1] -                       \
                                    NormalYearDaysPrecedingMonth[(MONTH)] \
    )

// ds\security\protocols\kerberos\client2\ctxtmgr.h
#define KerbWriteLockContexts() \
    EnterCriticalSection(&KerbContextResource)
#define KerbReadLockContexts() \
    EnterCriticalSection(&KerbContextResource)
#define KerbUnlockContexts() \
    LeaveCriticalSection(&KerbContextResource)
#define KerbWriteLockContexts() \
    RtlAcquireResourceExclusive(&KerbContextResource,TRUE);
#define KerbReadLockContexts() \
    RtlAcquireResourceShared(&KerbContextResource, TRUE);

// ds\security\protocols\kerberos\client2\gssapip.h
#define g_OID_equal(o1,o2) \
   (((o1)->length == (o2)->length) && \
    (memcmp((o1)->elements,(o2)->elements,(int) (o1)->length) == 0))

// ds\security\protocols\kerberos\client2\kerblist.h
#define KerbUnlockList(_List_) RtlLeaveCriticalSection(&(_List_)->Lock)

// ds\security\protocols\kerberos\client2\kerbp.h
#define KerbGlobalReadLock() RtlAcquireResourceShared(&KerberosGlobalResource, TRUE)
#define KerbGlobalWriteLock() RtlAcquireResourceExclusive(&KerberosGlobalResource, TRUE)

// ds\security\protocols\kerberos\client2\kerbtick.h
#define KERB_ENCRYPT_SIZE(_x_) (sizeof(KERB_ENCRYPTED_DATA) - 1 + (_x_))

// ds\security\protocols\kerberos\client2\rpcutil.cxx
#define KerbUnlockKdcData() (RtlLeaveCriticalSection(&KerbCallKdcDataLock))

// ds\security\protocols\kerberos\client2\spncache.cxx
#define KerbUnlockSpnCache()                            KerbUnlockList(&KerbSpnCache);

// ds\security\protocols\kerberos\client2\tktcache.cxx
#define UpdateCacheHits() (InterlockedIncrement(&KerbTicketCacheHits))
#define UpdateCacheMisses() (InterlockedIncrement(&KerbTicketCacheMisses))

// ds\security\protocols\kerberos\client2\tktcache.h
#define KerbWriteLockTicketCache() (EnterCriticalSection(&KerberosTicketCacheLock))
#define KerbReadLockTicketCache() (EnterCriticalSection(&KerberosTicketCacheLock))
#define KerbUnlockTicketCache() (LeaveCriticalSection(&KerberosTicketCacheLock))
#define KerbWriteLockTicketCache() (RtlAcquireResourceExclusive(&KerberosTicketCacheLock,TRUE))
#define KerbReadLockTicketCache() (RtlAcquireResourceShared(&KerberosTicketCacheLock, TRUE))

// ds\security\protocols\kerberos\common2\crypt.c
#define CHECKSUM_SIZE       sizeof(CheckSum)

// ds\security\protocols\kerberos\common2\kerbscav.cxx
#define LockScavengerQueue()   RtlEnterCriticalSection( &ScavengerLock )
#define UnlockScavengerQueue() RtlLeaveCriticalSection( &ScavengerLock )

// ds\security\protocols\kerberos\inc\kerbcomm.h
#define KERB_INTERNAL_NAME_SIZE(NameCount) (sizeof(KERB_INTERNAL_NAME) + ((NameCount) - ANYSIZE_ARRAY) * sizeof(UNICODE_STRING))

// ds\security\protocols\kerberos\inc\krb5.h
#define SIZE_KRB5_Module_PDU_0 sizeof(PKERB_AUTHORIZATION_DATA_LIST)
#define SIZE_KRB5_Module_PDU_1 sizeof(PKERB_IF_RELEVANT_AUTH_DATA)
#define SIZE_KRB5_Module_PDU_2 sizeof(PKERB_PREAUTH_DATA_LIST_Element)
#define SIZE_KRB5_Module_PDU_3 sizeof(KERB_ENCRYPTED_PRIV)
#define SIZE_KRB5_Module_PDU_4 sizeof(KERB_ENCRYPTED_CRED)
#define SIZE_KRB5_Module_PDU_5 sizeof(KERB_ERROR)
#define SIZE_KRB5_Module_PDU_6 sizeof(KERB_ENCRYPTED_DATA)
#define SIZE_KRB5_Module_PDU_7 sizeof(KERB_ENCRYPTION_KEY)
#define SIZE_KRB5_Module_PDU_8 sizeof(KERB_CHECKSUM)
#define SIZE_KRB5_Module_PDU_9 sizeof(KERB_ENCRYPTED_TIMESTAMP)
#define SIZE_KRB5_Module_PDU_10 sizeof(KERB_SALTED_ENCRYPTED_TIMESTAMP)
#define SIZE_KRB5_Module_PDU_11 sizeof(PKERB_ETYPE_INFO_Element)
#define SIZE_KRB5_Module_PDU_12 sizeof(KERB_TGT_REQUEST)
#define SIZE_KRB5_Module_PDU_13 sizeof(KERB_PKCS_SIGNATURE)
#define SIZE_KRB5_Module_PDU_14 sizeof(KERB_PA_PK_AS_REP)
#define SIZE_KRB5_Module_PDU_17 sizeof(KERB_KDC_DH_KEY_INFO)
#define SIZE_KRB5_Module_PDU_18 sizeof(KERB_PA_PK_AS_REQ)
#define SIZE_KRB5_Module_PDU_19 sizeof(KERB_DH_PARAMTER)
#define SIZE_KRB5_Module_PDU_20 sizeof(KERB_KDC_ISSUED_AUTH_DATA)
#define SIZE_KRB5_Module_PDU_21 sizeof(KERB_PA_SERV_REFERRAL)
#define SIZE_KRB5_Module_PDU_22 sizeof(KERB_PA_PAC_REQUEST)
#define SIZE_KRB5_Module_PDU_24 sizeof(KERB_ERROR_METHOD_DATA)
#define SIZE_KRB5_Module_PDU_25 sizeof(KERB_EXT_ERROR)
#define SIZE_KRB5_Module_PDU_26 sizeof(TYPED_DATA_Element)
#define SIZE_KRB5_Module_PDU_27 sizeof(KERB_PA_FOR_USER)
#define SIZE_KRB5_Module_PDU_28 sizeof(KERB_TICKET)
#define SIZE_KRB5_Module_PDU_29 sizeof(KERB_ENCRYPTED_TICKET)
#define SIZE_KRB5_Module_PDU_30 sizeof(KERB_AUTHENTICATOR)
#define SIZE_KRB5_Module_PDU_31 sizeof(KERB_AP_REQUEST)
#define SIZE_KRB5_Module_PDU_32 sizeof(KERB_AP_REPLY)
#define SIZE_KRB5_Module_PDU_33 sizeof(KERB_ENCRYPTED_AP_REPLY)
#define SIZE_KRB5_Module_PDU_34 sizeof(KERB_SAFE_MESSAGE)
#define SIZE_KRB5_Module_PDU_35 sizeof(KERB_PRIV_MESSAGE)
#define SIZE_KRB5_Module_PDU_36 sizeof(KERB_CRED)
#define SIZE_KRB5_Module_PDU_37 sizeof(KERB_TGT_REPLY)
#define SIZE_KRB5_Module_PDU_40 sizeof(KERB_MARSHALLED_REQUEST_BODY)
#define SIZE_KRB5_Module_PDU_41 sizeof(KERB_AS_REPLY)
#define SIZE_KRB5_Module_PDU_42 sizeof(KERB_TGS_REPLY)
#define SIZE_KRB5_Module_PDU_43 sizeof(KERB_ENCRYPTED_AS_REPLY)
#define SIZE_KRB5_Module_PDU_44 sizeof(KERB_ENCRYPTED_TGS_REPLY)
#define SIZE_KRB5_Module_PDU_45 sizeof(KERB_PA_PK_AS_REP2)
#define SIZE_KRB5_Module_PDU_46 sizeof(KERB_AS_REQUEST)
#define SIZE_KRB5_Module_PDU_47 sizeof(KERB_TGS_REQUEST)
#define SIZE_KRB5_Module_PDU_48 sizeof(KERB_PA_PK_AS_REQ2)

// ds\security\protocols\kerberos\inc\tostring.hxx
#define FileTimeToString(ft)    TimeStampToString( *(TimeStamp*)& (ft) )

// ds\security\protocols\kerberos\parser\kerbparser.h
#define TIME_FORMAT_SIZE sizeof("00/00/0000 00:00:00 UTC Time Zone")

// ds\security\protocols\kerberos\server\kdcsvr.hxx
#define MAX_SID_LEN (sizeof(SID) + sizeof(ULONG) * SID_MAX_SUB_AUTHORITIES)

// ds\security\protocols\kerberos\server\refer.cxx
#define KdcLockDomainList() (RtlEnterCriticalSection(&KdcDomainListLock))
#define KdcUnlockDomainList() (RtlLeaveCriticalSection(&KdcDomainListLock))
#define KdcLockReferralCache() (RtlEnterCriticalSection(&KdcReferralCacheLock))
#define KdcUnlockReferralCache() (RtlLeaveCriticalSection(&KdcReferralCacheLock))
#define KdcReferenceDomainInfo(_x_) \
    InterlockedIncrement(&(_x_)->References)

// ds\security\protocols\kerberos\server\sockutil.h
#define KDC_ATQ_SOCKET_USED     (KDC_ATQ_WRITE_CONTEXT | KDC_ATQ_READ_CONTEXT)

// ds\security\protocols\msv_sspi\credhand.cxx
#define IsNullSessionString(x) (((x)->Length == 0) &&    \
                          ((x)->Buffer != NULL))

// ds\security\protocols\msv_sspi\nlpcache.c
#define INVALIDATE_HANDLE(handle) (*((PHANDLE)(&handle)) = INVALID_HANDLE_VALUE)

// ds\security\protocols\msv_sspi\nlpcache.h
#define CACHE_NAME_SIZE     (sizeof(CACHE_NAME) - sizeof(L""))

// ds\security\protocols\msv_sspi\utility.cxx
#define SSP_TOKEN_ACCESS (READ_CONTROL              |\
                          WRITE_DAC                 |\
                          TOKEN_DUPLICATE           |\
                          TOKEN_IMPERSONATE         |\
                          TOKEN_QUERY               |\
                          TOKEN_QUERY_SOURCE        |\
                          TOKEN_ADJUST_PRIVILEGES   |\
                          TOKEN_ADJUST_GROUPS       |\
                          TOKEN_ADJUST_DEFAULT)

// ds\security\protocols\pwdssp\pwdssp.c
#define PwdAlloc(x) LocalAlloc(LMEM_FIXED|LMEM_ZEROINIT,x)

// ds\security\protocols\schannel\inc\_ssl3cli.h
#define     F_RESPONSE(State) (State > SSL3_STATE_GEN_START && State < SSL3_STATE_GEN_END)

// ds\security\protocols\schannel\inc\cache.h
#define HasTimeElapsed(StartTime, CurrentTime, Interval)                \
            (((CurrentTime) > (StartTime) &&                            \
              (CurrentTime) - (StartTime) > (Interval)) ||              \
             ((CurrentTime) < (StartTime) &&                            \
              (CurrentTime) + (MAXULONG - (StartTime)) >= (Interval)))

// ds\security\protocols\schannel\inc\cred.h
#define LockCredential(p)   RtlEnterCriticalSection(&(p)->csLock)
#define UnlockCredential(p) RtlLeaveCriticalSection(&(p)->csLock)

// ds\security\protocols\schannel\inc\pct1msg.h
#define LSBOF(x)    ((UCHAR) ((x) & 0xFF))

// ds\security\protocols\schannel\inc\spdefs.h
#define CALG_NULLCIPHER     (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_ANY | 0)

// ds\security\protocols\schannel\inc\sperr.h
#define PCT_INT_BAD_CERT           (PCT_INT_DROP_CONNECTION | PCT_ERR_BAD_CERTIFICATE)
#define PCT_INT_ILLEGAL_MSG        (PCT_INT_DROP_CONNECTION | PCT_ERR_ILLEGAL_MESSAGE)
#define PCT_INT_SPECS_MISMATCH     (PCT_INT_DROP_CONNECTION | PCT_ERR_SPECS_MISMATCH)
#define PCT_INT_RENEGOTIATE        (PCT_INT_DROP_CONNECTION | PCT_ERR_RENEGOTIATE)
#define PCT_INT_UNKNOWN_CREDENTIAL (PCT_INT_DROP_CONNECTION | PCT_ERR_UNKNOWN_CREDENTIAL)
#define PCT_INT_EXPIRED            (PCT_INT_DROP_CONNECTION | PCT_ERR_EXPIRED)
#define SP_FATAL(s) (PCT_INT_DROP_CONNECTION & (s))

// ds\security\protocols\schannel\inc\ssl2msg.h
#define LSBOF(x)    ((UCHAR) ((x) & 0xFF))

// ds\security\protocols\schannel\inc\ssl3msg.h
#define CB_SSL3_CHANGE_CIPHER_SPEC      (sizeof(SWRAP) + 1)
#define CB_SSL3_FINISHED_MSG        (sizeof(FMWIRE))
#define CB_SSL3_FINISHED_MSG_ONLY   (sizeof(SHSH) + CB_MD5_DIGEST_LEN + CB_SHA_DIGEST_LEN)
#define CB_SSL3_ALERT                   (sizeof(SWRAP) +2)

// ds\security\protocols\xtcb\creds.c
#define ReadLockCredList()  EnterCriticalSection( &XtcbCredListLock )
#define WriteLockCredList() EnterCriticalSection( &XtcbCredListLock )
#define UnlockCredList()    LeaveCriticalSection( &XtcbCredListLock )

// ds\security\protocols\xtcb\md5c.c
#define G(x, y, z) (y ^ (z & (x^y)))	/* optimized version of (((x) & (z)) | ((y) & (~z))) */
#define H(x, y, z) (x ^ y ^ z)
#define I(x, y, z) (y ^ (x | ~z))

// ds\security\protocols\xtcb\protocol.c
#define XtcbHmacUpdate( H, p, s ) \
    HMACMD5Update( &((PXTCB_HMAC)H)->Context, p, s )

// ds\security\protocols\xtcb\userctxt.c
#define LockContextList()   EnterCriticalSection( &XtcbContextListLock )
#define UnlockContextList() LeaveCriticalSection( &XtcbContextListLock )

// ds\security\services\ca\capesnpn\certifct.h
#define MY_ENCODING_TYPE (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)

// ds\security\services\ca\certclib\oidmgr.h
#define OID_ATTR_ALL                    (OID_ATTR_OID | OID_ATTR_TYPE | OID_ATTR_DISPLAY_NAME | OID_ATTR_CPS)

// ds\security\services\ca\certdb\dbtable.h
#define ISTEXTCOLTYP(coltyp) \
	(JET_coltypText == (coltyp) || JET_coltypLongText == (coltyp))
#define IsValidJetTableId(tableid) (0 != (tableid) && 0xffffffff != (tableid))

// ds\security\services\ca\certmmc\csnapin.cpp
#define HIDEVERB(__x__) \
    do {                \
        m_pConsoleVerb->SetVerbState(__x__, HIDDEN, TRUE);  \
        m_pConsoleVerb->SetVerbState(__x__, ENABLED, FALSE); \
    } while(0)
#define SHOWVERB(__x__) \
    do {                \
        m_pConsoleVerb->SetVerbState(__x__, HIDDEN, FALSE);  \
        m_pConsoleVerb->SetVerbState(__x__, ENABLED, TRUE); \
    } while(0)

// ds\security\services\ca\certreq\certreq.cpp
#define ISBLANK(wc)	(L' ' == (wc) || L'\t' == (wc))

// ds\security\services\ca\certsrv\prop.cpp
#define PROPNAMEMATCH(cwcNameVariable, pwszNameVariable, wszNameLiteral) \
    (WSZARRAYSIZE((wszNameLiteral)) == (cwcNameVariable) && \
     0 == lstrcmpi((pwszNameVariable), (wszNameLiteral)))

// ds\security\services\ca\include\certacl.h
#define ACTRL_CERTSRV_READ         (READ_CONTROL | \
                                    ACTRL_DS_READ_PROP | \
                                    ACTRL_DS_LIST | \
                                    ACTRL_DS_LIST_OBJECT)
#define ACTRL_CERTSRV_ENROLL       (ACTRL_DS_READ_PROP | \
                                    ACTRL_DS_WRITE_PROP | \
                                    ACTRL_DS_CONTROL_ACCESS)
#define CERTSRV_STD_OG(owner, group) \
    SDDL_OWNER L":" owner SDDL_GROUP L":" group \
    SDDL_DACL  L":" SDDL_AUTO_INHERITED
#define OBJ_GEN_SIAE(guid, access, ids) \
            {&(guid), (access), MAKEINTRESOURCE((ids)), \
             SI_ACCESS_GENERAL|SI_ACCESS_SPECIFIC}
#define OBJ_SPE_SIAE(guid, ids) \
            {&(guid), ACTRL_CERTSRV_OBJ, MAKEINTRESOURCE((ids)), \
             SI_ACCESS_SPECIFIC}

// ds\security\services\ca\include\certbcli.h
#define	CSBFT_CHECKPOINT_DIR	  ((CSBFT) (TEXT('\x03') | CSBFT_DIRECTORY))

// ds\security\services\ca\include\certsrv.h
#define REQDISP_DEFAULT_STANDALONE	(REQDISP_PENDINGFIRST | REQDISP_ISSUE)
#define EDITF_DEFAULT_STANDALONE	(EDITF_REQUESTEXTENSIONLIST | \
					 EDITF_DISABLEEXTENSIONLIST | \
					 EDITF_ADDOLDKEYUSAGE | \
					 EDITF_ATTRIBUTEENDDATE | \
					 EDITF_BASICCONSTRAINTSCRITICAL | \
					 EDITF_BASICCONSTRAINTSCA | \
					 EDITF_ENABLEAKIKEYID | \
					 EDITF_ATTRIBUTECA | \
					 EDITF_ATTRIBUTEEKU)
#define EDITF_DEFAULT_ENTERPRISE	(EDITF_REQUESTEXTENSIONLIST | \
					 EDITF_DISABLEEXTENSIONLIST | \
                                         EDITF_BASICCONSTRAINTSCRITICAL | \
                                         EDITF_ENABLEAKIKEYID | \
					 EDITF_ADDOLDKEYUSAGE | \
					 EDITF_ENABLEDEFAULTSMIME)

// ds\security\services\ca\include\cs.h
#define InitializeListHead(ListHead) (\
    (ListHead)->Flink = (ListHead)->Blink = (ListHead))
#define InsertTailList(ListHead,Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_ListHead;\
    _EX_ListHead = (ListHead);\
    _EX_Blink = _EX_ListHead->Blink;\
    (Entry)->Flink = _EX_ListHead;\
    (Entry)->Blink = _EX_Blink;\
    _EX_Blink->Flink = (Entry);\
    _EX_ListHead->Blink = (Entry);\
    }

// ds\security\services\ca\include\csprop.h
#define CCH_DBMAXTEXT_MAXINTERNAL (255 / sizeof(WCHAR))    // 127 chars!
#define CB_DBMAXTEXT_MAXINTERNAL  (CCH_DBMAXTEXT_MAXINTERNAL * sizeof(WCHAR))
#define CB_DBMAXTEXT_SHORT        (CCH_DBMAXTEXT_SHORT * sizeof(WCHAR))
#define CB_DBMAXTEXT_MEDIUM       (CCH_DBMAXTEXT_MEDIUM * sizeof(WCHAR))
#define CB_DBMAXTEXT_LONG         (CCH_DBMAXTEXT_LONG * sizeof(WCHAR))

// ds\security\services\ca\include\csregstr.h
#define REQDISP_DEFAULT_STANDALONE	(REQDISP_PENDINGFIRST | REQDISP_ISSUE)
#define EDITF_DEFAULT_STANDALONE	(EDITF_REQUESTEXTENSIONLIST | \
					 EDITF_DISABLEEXTENSIONLIST | \
					 EDITF_ADDOLDKEYUSAGE | \
					 EDITF_ATTRIBUTEENDDATE | \
					 EDITF_BASICCONSTRAINTSCRITICAL | \
					 EDITF_BASICCONSTRAINTSCA | \
					 EDITF_ENABLEAKIKEYID | \
					 EDITF_ATTRIBUTECA | \
					 EDITF_ATTRIBUTEEKU)
#define EDITF_DEFAULT_ENTERPRISE	(EDITF_REQUESTEXTENSIONLIST | \
					 EDITF_DISABLEEXTENSIONLIST | \
                                         EDITF_BASICCONSTRAINTSCRITICAL | \
                                         EDITF_ENABLEAKIKEYID | \
					 EDITF_ADDOLDKEYUSAGE | \
					 EDITF_ENABLEDEFAULTSMIME)

// ds\security\services\ca\initlib\initlib.cpp
#define CSURL_DSDEPENDENT (CSURL_SERVERPUBLISH | CSURL_ADDTOCERTCDP | CSURL_ADDTOFRESHESTCRL)

// ds\security\services\ca\policy\default\request.cpp
#define wszSEARCHUSERCOMPUTER	L"(|" wszSEARCHUSER wszSEARCHCOMPUTER L")"

// ds\security\services\ca\tools\cep\mscep\cepasn.h
#define SIZE_CEPASN_Module_PDU_0 sizeof(IssuerAndSerialNumber)

// ds\security\services\ca\tools\certut\certutil.cpp
#define AF_OPTION_GENERIC	(AF_OPTION_SECONDS | AF_OPTION_GMT | AF_OPTION_VERBOSE)
#define pargDEFAULT	(&aarg[0])	// Default to first entry
#define ISBLANK(wc)	(L' ' == (wc) || L'\t' == (wc))

// ds\security\services\ca\tools\certut\odbc.h
#define ITEMINSERT(l,i) (i).itemPrev = &(l),                        \
                        (i).itemNext = (l).itemNext,                \
                        (l).itemNext = (i).itemNext->itemPrev = &(i)
#define ITEMREMOVE(i)   (i).itemNext->itemPrev = (i).itemPrev,      \
                        (i).itemPrev->itemNext = (i).itemNext

// ds\security\services\scerpc\common.cpp
#define GENERIC_READ_MAPPING     ((STANDARD_RIGHTS_READ)     | \
                                  (ACTRL_DS_LIST)   | \
                                  (ACTRL_DS_READ_PROP))
#define GENERIC_EXECUTE_MAPPING  ((STANDARD_RIGHTS_EXECUTE)  | \
                                  (ACTRL_DS_LIST))
#define GENERIC_WRITE_MAPPING    ((STANDARD_RIGHTS_WRITE)    | \
                                  (ACTRL_DS_SELF)      | \
                                  (ACTRL_DS_WRITE_PROP))

// ds\security\services\scerpc\common.h
#define ScepObjectAceSid( Ace ) \
    ((PSID)(((PUCHAR)&(((SCEP_PKNOWN_OBJECT_ACE)(Ace))->SidStart)) + \
     (ScepObjectAceObjectTypePresent(Ace) ? sizeof(GUID) : 0 ) + \
     (ScepObjectAceInheritedObjectTypePresent(Ace) ? sizeof(GUID) : 0 )))
#define ScepObjectAceObjectType( Ace ) \
     ((GUID *)(ScepObjectAceObjectTypePresent(Ace) ? \
        &((SCEP_PKNOWN_OBJECT_ACE)(Ace))->SidStart : \
        NULL ))
#define ScepObjectAceInheritedObjectType( Ace ) \
     ((GUID *)(ScepObjectAceInheritedObjectTypePresent(Ace) ? \
        ( ScepObjectAceObjectTypePresent(Ace) ? \
            (PULONG)(((PUCHAR)(&((SCEP_PKNOWN_OBJECT_ACE)(Ace))->SidStart)) + sizeof(GUID)) : \
            &((SCEP_PKNOWN_OBJECT_ACE)(Ace))->SidStart ) : \
        NULL ))
#define SERVICE_GENERIC_EXECUTE     (STANDARD_RIGHTS_EXECUTE |\
                                     SERVICE_START |\
                                     SERVICE_STOP |\
                                     SERVICE_PAUSE_CONTINUE |\
                                     SERVICE_INTERROGATE |\
                                     SERVICE_USER_DEFINED_CONTROL)
#define SERVICE_GENERIC_WRITE       (STANDARD_RIGHTS_WRITE |\
                                     SERVICE_CHANGE_CONFIG )

// ds\security\services\scerpc\server\queue.cpp
#define SCEP_IS_SAM_OBJECT(ObjectType) ((ObjectType == SecurityDbObjectSamUser ||\
                                         ObjectType == SecurityDbObjectSamGroup ||\
                                         ObjectType == SecurityDbObjectSamAlias) ?\
                                         TRUE : FALSE)

// ds\security\services\scerpc\server\tree.cpp
#define SCEP_IGNORE_SOME_ERRORS(ErrorCode)  ErrorCode == ERROR_FILE_NOT_FOUND ||\
                                            ErrorCode == ERROR_PATH_NOT_FOUND ||\
                                            ErrorCode == ERROR_ACCESS_DENIED ||\
                                            ErrorCode == ERROR_SHARING_VIOLATION ||\
                                            ErrorCode == ERROR_INVALID_OWNER ||\
                                            ErrorCode == ERROR_INVALID_PRIMARY_GROUP ||\
                                            ErrorCode == ERROR_INVALID_HANDLE ||\
                                            ErrorCode == ERROR_INVALID_SECURITY_DESCR ||\
                                            ErrorCode == ERROR_CANT_ACCESS_FILE

// ds\security\services\smartcrd\inc\registry.h
#define REG_OPTION_EXISTS (~REG_LEGAL_OPTION)

// ds\security\services\smartcrd\newssp\inc\sspguid.h
#define CLSCTX_LOCAL            (CLSCTX_INPROC_SERVER| \
                                 CLSCTX_INPROC_HANDLER| \
                                 CLSCTX_LOCAL_SERVER)

// ds\security\services\smartcrd\server\client\redirect.h
#define TS_REDIRECT_READY       ((g_bRedirectReady || LoadRedirectionDll()) && !TS_REDIRECT_DISABLED)

// ds\security\services\smartcrd\tools\sctest\sctest\apiproxy.c
#define CLA(cla)    UINT82XSCM(&phTmp->xSCM, cla, TYPE_NOTYPE_NOCOUNT)
#define INS(ins)    UINT82XSCM(&phTmp->xSCM, ins, TYPE_NOTYPE_NOCOUNT)
#define P1(p1)      UINT82XSCM(&phTmp->xSCM, p1, TYPE_NOTYPE_NOCOUNT)
#define P2(p2)      UINT82XSCM(&phTmp->xSCM, p2, TYPE_NOTYPE_NOCOUNT)

// ds\security\services\smartcrd\tools\sctest\sctest\marshalpc.h
#define MAKESCODE(r) ((SCODE)((r) & 0x80 ? (r) | 0xC0000000L : (r)))

// ds\security\services\smartcrd\tools\sctest\sctest\wpscproxy.h
#define SCW_RESOURCEOPERATION_FILE_READ             (SCW_RESOURCETYPE_FILE | 0x01)
#define SCW_RESOURCEOPERATION_FILE_WRITE            (SCW_RESOURCETYPE_FILE | 0x02)
#define SCW_RESOURCEOPERATION_FILE_EXECUTE          (SCW_RESOURCETYPE_FILE | 0x03)
#define SCW_RESOURCEOPERATION_FILE_EXTEND           (SCW_RESOURCETYPE_FILE | 0x04)
#define SCW_RESOURCEOPERATION_FILE_GETATTRIBUTES    (SCW_RESOURCETYPE_FILE | 0x06)
#define SCW_RESOURCEOPERATION_FILE_SETATTRIBUTES    (SCW_RESOURCETYPE_FILE | 0x07)
#define SCW_RESOURCEOPERATION_FILE_CRYPTO	        (SCW_RESOURCETYPE_FILE | 0x08)
#define SCW_RESOURCEOPERATION_FILE_INCREASE	        (SCW_RESOURCETYPE_FILE | 0x09)
#define SCW_RESOURCEOPERATION_FILE_INVALIDATE       (SCW_RESOURCETYPE_FILE | 0x0A)
#define SCW_RESOURCEOPERATION_FILE_REHABILITATE     (SCW_RESOURCETYPE_FILE | 0x0B)
#define SCW_RESOURCEOPERATION_DIR_ACCESS            (SCW_RESOURCETYPE_DIR | 0x01)
#define SCW_RESOURCEOPERATION_DIR_CREATEFILE        (SCW_RESOURCETYPE_DIR | 0x02)
#define SCW_RESOURCEOPERATION_DIR_ENUM              (SCW_RESOURCETYPE_DIR | 0x03)
#define SCW_RESOURCEOPERATION_DIR_GETATTRIBUTES     (SCW_RESOURCETYPE_DIR | 0x05)
#define SCW_RESOURCEOPERATION_DIR_SETATTRIBUTES     (SCW_RESOURCETYPE_DIR | 0x06)

// ds\security\services\smartcrd\tools\tclcrypt\tcldllutil.h
#define NEED_MORE_TMP_BUFFER(sz) \
    if (0 == TclEx_tmpBufferSize) { \
        (void)fprintf(stderr, "TMP_BUFFER not locked.\n"); \
        exit(1); } \
    else { if (TclEx_tmpBufferSize < (sz)) { \
            TclEx_tmpBuffer = (char *)ckrealloc(TclEx_tmpBuffer, (sz)); \
            TclEx_tmpBufferSize = (sz); } }
#define NEED_TMP_BUFFER(sz) \
    if (TclEx_tmpBufferSize < (sz)) { \
        if (0 == TclEx_tmpBufferSize) \
                { TclEx_tmpBuffer = (char *)ckalloc(sz); } \
        else \
            { TclEx_tmpBuffer = (char *)ckrealloc(TclEx_tmpBuffer, (sz)); } \
        TclEx_tmpBufferSize = (sz); }
#define NEED_MORE_TMP_BUFFER(sz) \
    if (TclEx_tmpBufferSize < (sz)) { \
        TclEx_tmpBuffer = (char *)ckrealloc((char *)TclEx_tmpBuffer, (sz)); \
        TclEx_tmpBufferSize = (sz); }

// ds\security\tools\delegate\delegate.h
#define IS_ARG_SWITCH(arg)      (arg[0] == '/' || arg[0] == '-')

// ds\security\tools\dsacls\dsacls.h
#define GENERIC_READ_MAPPING     ((STANDARD_RIGHTS_READ)     | \
                                  (RIGHT_DS_LIST_CONTENTS)   | \
                                  (RIGHT_DS_READ_PROPERTY)   | \
                                  (RIGHT_DS_LIST_OBJECT))
#define GENERIC_EXECUTE_MAPPING  ((STANDARD_RIGHTS_EXECUTE)  | \
                                  (RIGHT_DS_LIST_CONTENTS))
#define GENERIC_WRITE_MAPPING    ((STANDARD_RIGHTS_WRITE)    | \
                                  (RIGHT_DS_WRITE_PROPERTY_EXTENDED)  | \
                  (RIGHT_DS_WRITE_PROPERTY))

// ds\security\tools\kerbconf\kerbconf.h
#define	LIST_INIT(head) {						\
	(head)->lh_first = NULL;					\
}
#define LIST_INSERT_HEAD(head, elm, field) {				\
	if (((elm)->field.le_next = (head)->lh_first) != NULL)		\
		(head)->lh_first->field.le_prev = &(elm)->field.le_next;\
	(head)->lh_first = (elm);					\
	(elm)->field.le_prev = &(head)->lh_first;			\
}
#define LIST_REMOVE(elm, field) {					\
	if ((elm)->field.le_next != NULL)				\
		(elm)->field.le_next->field.le_prev = 			\
		    (elm)->field.le_prev;				\
	*(elm)->field.le_prev = (elm)->field.le_next;			\
}
#define NewNameList()							\
		(name_list_t *)calloc(sizeof(name_list_t), 1)
#define NewRealm(l) (krb5_realm_t *)calloc(sizeof(krb5_realm_t) + (l*sizeof(TCHAR)), 1)

// ds\security\tools\keytab2\inc\keytab.h
#define KT_DEFAULT (KT_COMPONENTS | KT_REALM | KT_VNO | KT_KTVNO | KT_KEYTYPE | KT_PRINCTYPE )

// ds\security\tools\keytab2\inc\macros.h
#define MYALLOC( whom, what, howmany, withwhat ) \
( ( (whom) = (what *) (withwhat)( (howmany) * sizeof(what)) ) != NULL )

// ds\security\tools\keytab2\keytab\lib\keytab.c
#define PRINTFIELD( option, format, value ) { if (options & option) { fprintf(stream, format, value); } }

// ds\security\tools\keytab2\keytab\lib\utest2.c
#define CHECK( what, fieldname ) {         \
    printf( "\n" #what " " #fieldname ".\n" );   \
    printf( "sizeof " #what " is %d.\n", sizeof( what ) );  \
    printf( "sizeof k." #fieldname " is %d.\n", sizeof( k.fieldname ) ); \
    printf( "sizeof pk->" #fieldname " is %d.\n", sizeof( pk->fieldname ) );\
}

// ds\security\tools\keytab2\opt\options.h
#define ISSWITCH( ch /*character*/ ) ( (ch=='-') || (ch=='+') || (ch=='/') )

// ds\security\tools\stampdns\stampdns.c
#define PARENT_TAG_LEN  (sizeof( PARENT_TAG ) - 1)

// ds\security\tools\syskey\rng.c
#define LockRNG()   EnterCriticalSection( &csRNG )
#define UnlockRNG() LeaveCriticalSection( &csRNG )

// ds\security\winsafer\safepath.c
#define IS_UCASE_CHARS_EQUAL_U(ch1, ch2) (((ch1) == (ch2)) || (RtlUpcaseUnicodeChar(ch1) == RtlUpcaseUnicodeChar(ch2)))
#define IS_PATH_SEPARATOR_U(ch) (((ch) == L'\\') || ((ch) == L'/'))

// ds\security\winsafer\test\desktops\splash.cpp
#define     TIMER_ID                    (WM_USER + 5007)

// ds\xpress\xencode.c
#define Z_HASH_SUM(b)      (z_hash_map[0][b[0]] ^ z_hash_map[1][b[1]] ^ z_hash_map[2][b[2]])

// enduser\mapistub\mapistub\_smerror.h
#define ScWin(_sc) \
	((SCODE) ((_sc) | scmskWin))
#define ScMapi(_sc) \
	((SCODE) ((_sc) | scmskMapi))
#define	MarkMAPIError(_sc) \
	_sc |= scmskMapi

// enduser\mapistub\mapistub\_spooler.h
#define cbSplSecurity	(sizeof(ULONG) * 4)		// spooler security data

// enduser\mapistub\mapistub\client.h
#define MBS_ERROR           (MB_ICONSTOP | MB_OK)
#define MBS_INFO            (MB_ICONINFORMATION | MB_OK)
#define MBS_OOPS            (MB_ICONEXCLAMATION | MB_OK)

// enduser\mapistub\mapistub\mapi32.cpp
#define ThunkGetProcAddress(hModule, szFnName, bNativeDll, nParams) \
                ::GetProcAddress(hModule, szFnName)

// enduser\netmeeting\as\h\dcg.h
#define IN_TIME_RANGE(BEGIN, END, TIME)                                     \
    (((BEGIN) < (END)) ?                                                    \
    (((TIME) >= (BEGIN)) && ((TIME) <= (END))) :                            \
    (((TIME) >= (BEGIN)) || ((TIME) <= (END))))

// enduser\netmeeting\av\callcont\h245asn.h
#define SIZE_H245ASN_Module_PDU_1 sizeof(MultimediaSystemControlMessage)

// enduser\netmeeting\av\callcont\h245asnv3.h
#define SIZE_H245ASNV3_Module_PDU_0 sizeof(MultimediaSystemControlMessage)

// enduser\netmeeting\av\callcont\h245fsm.h
#define FsmStopTimer(pObject) \
    {H245StopTimer((pObject)->pInstance,(pObject)->dwTimerId); (pObject)->dwTimerId = 0;}

// enduser\netmeeting\av\codecs\dec\dech261\slib.h
#define slibFrameToTime(Info,frame) \
             ((SlibTime_t)((float)(frame*1000)/Info->FramesPerSec))
#define slibFrameToTime100(Info,frame) \
             ((SlibTime_t)((float)(frame*100000)/Info->FramesPerSec))
#define slibHasTimeCode(Info) (slibHasVideo(Info) && SlibTypeIsMPEG(Info->Type))

// enduser\netmeeting\av\codecs\dec\dech263\slib.h
#define slibFrameToTime(Info,frame) \
             ((SlibTime_t)((float)(frame*1000)/Info->FramesPerSec))
#define slibFrameToTime100(Info,frame) \
             ((SlibTime_t)((float)(frame*100000)/Info->FramesPerSec))
#define slibHasTimeCode(Info) (slibHasVideo(Info) && SlibTypeIsMPEG(Info->Type))

// enduser\netmeeting\av\h323\commchan.h
		#define SHOW_OBJ_ETIME(s) RETAILMSG(("\r\n** (%s) ELAPSED TIME(ms):%d, ticks:%d **\r\n", \
			(s), OBJ_ETIME, m_cpt_.dwLast )); OBJ_ETIME_RESET

// enduser\netmeeting\av\intelcc\include\h245asn.h
#define SIZE_H245ASN_Module_PDU_0 sizeof(MultimediaSystemControlMessage)

// enduser\netmeeting\h\shellp.h
#define SVM_GETANCHORPOINT              (WM_USER + 3)

// enduser\netmeeting\t120\mst123\timer.h
#define InstallTimerEvent(duration, control, func) \
    (g_pSystemTimer->CreateTimerEvent((duration),(control),this,(PTimerFunction)(func)))

// enduser\netmeeting\ui\msconfwb\draw.hpp
#define EqualPoint(pt1, pt2)    (((pt1).x == (pt2).x) && ((pt1).y == (pt2).y))

// enduser\netmeeting\ui\wb\draw.hpp
#define EqualPoint(pt1, pt2)    (((pt1).x == (pt2).x) && ((pt1).y == (pt2).y))

// enduser\speech\ce\mmio\winmmi.h
#define ENTER_MM_HANDLE(h) (EnterCriticalSection(&HtoPH(h)->CritSec))
#define LEAVE_MM_HANDLE(h) ((void)LeaveCriticalSection(&HtoPH(h)->CritSec))

// enduser\speech\sapi\sapi\resultheader.h
#define FT64(/*FILETIME*/ filetime) (*((LONGLONG*)&(filetime)))

// enduser\speech\sapi\sapi\spvoice.h
#define ENTER_VOICE_STATE_CHANGE_CRIT( bPurge ) \
    CSPAutoCritSecLock statelck( &m_StateChangeCritSec ); \
    if( bPurge ) PurgeAll(); \
    CSPAutoObjectLock lck(this);

// enduser\speech\sapi\sapi\sraudio.h
#define FT64(/*FILETIME*/ filetime) (*((LONGLONG*)&(filetime)))

// enduser\stuff\hhctrl\secwin.h
#define DEFAULT_STYLE       (WS_THICKFRAME | WS_OVERLAPPED)

// enduser\stuff\itircl\fts\breakers\breaker.c
#define	CP_CLASS(p)	(((LPCMAP)p)->Class & 0xff)

// enduser\windows.com\winupd\wupdinfo\cruntime.cpp
#define ISHEXDIGIT(c) ((c >= '0' && c <= '9') || ((c&0xDF) >= 'A' && ((c&0xDF) <= 'F')))
#define GETHEXDIGIT(c) ((c<'A') ? (c-0x30) : ((c&0xDF)-0x37))

// inetcore\connectionwizard\inc\port32.h
#define MAKEPOINTS(l)     (*((POINTS FAR*)&(l)))

// inetcore\digest\include.hxx
#define LOCK_GLOBALS()    EnterCriticalSection(&DllCritSect)
#define UNLOCK_GLOBALS()  LeaveCriticalSection(&DllCritSect)

// inetcore\mshtml\imgfilt\atlcom.h
#define END_COM_MAP()   {NULL, 0, 0}};\
	return &_entries[1];}
#define END_COM_MAP()   {NULL, 0, 0}};\
	return _entries;}

// inetcore\mshtml\src\core\cdutil\timer.cxx
#define DECLARE_VARIANT_INIT(name, dwInit)  \
    VARIANT name;           \
    VariantInit(&name);     \
    V_VT(&name) = VT_UI4;   \
    V_UI4(&name) = dwInit;

// inetcore\mshtml\src\core\include\cdutil.hxx
#define DECLARE_ONTICK_METHOD(fn, FN, args)\
        virtual HRESULT BUGCALL fn args
#define ONTICK_METHOD(klass, fn, FN)   (PFN_VOID_ONTICK)&klass::fn

// inetcore\mshtml\src\core\include\timer.hxx
#define MAX_TIME                        (~0U)

// inetcore\mshtml\src\time\include\atlutil.h
#define DA_DECLARE_NOT_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< DAComObject< x > >, CComFailCreator<CLASS_E_NOAGGREGATION> > _CreatorClass;
#define DA_DECLARE_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< DAComObject< x > >, CComCreator< CComAggObject< x > > > _CreatorClass;

// inetcore\mshtml\src\time\include\attr.h
#define TIME_GET_VT_R4(hr, pvarAttr, PropGetFn) \
{ \
    float flVal = 0; \
    hr = PropGetFn##(&flVal); \
    if (SUCCEEDED(hr)) \
    { \
        V_VT(##pvarAttr##) = VT_R4; \
        V_R4(##pvarAttr##) = flVal; \
    } \
}
#define TIME_GET_VT_BOOL(hr, pvarAttr, PropGetFn) \
{ \
    VARIANT_BOOL vbVal = VARIANT_TRUE; \
    hr = PropGetFn##(&vbVal); \
    if (SUCCEEDED(hr)) \
    { \
        V_VT(##pvarAttr##) = VT_BOOL; \
        V_BOOL(##pvarAttr##) = vbVal; \
    } \
}
#define TIME_PERSISTGET(hr, pvarAttr, refAttr, idl_arg_type, PropGetFn) \
{ \
    BSTR bstrTemp; \
    /* Try to get string */ \
    hr = THR(refAttr##.GetString(&bstrTemp)); \
    if (SUCCEEDED(hr) && NULL != bstrTemp) \
    { \
        V_VT(##pvarAttr##) = VT_BSTR; \
        V_BSTR(##pvarAttr##) = bstrTemp; \
    } \
    /* else if attr is set, get value */ \
    else if (##refAttr##.IsSet()) \
    { \
        TIME_GET_##idl_arg_type##(hr, pvarAttr, PropGetFn); \
    } \
    /* else indicate that this attr should not be persisted */ \
    else \
    { \
        V_VT(##pvarAttr##) = VT_NULL; \
    } \
}

// inetcore\mshtml\src\time\include\eventmgrmacros.h
#define END_TIME_EVENTMAP()                         hr = THR(pEle->QueryInterface(IID_IHTMLElement, (void **)&pEle2)); \
                                                    if (FAILED(hr))                             \
                                                    {                                           \
                                                        goto done;                              \
                                                    }                                           \
                                                    m_EventMgr->_Init(pEle2, pEleBehaviorSite);  \
                                                  done:                                         \
                                                    return hr;                                  \
                                                }

// inetcore\mshtml\src\time\include\headers.h
#define NO_COPY(cls)    \
    cls(const cls&);    \
    cls& operator=(const cls&)

// inetcore\mshtml\src\time\include\util.h
#define IID_TO_PPV(_type,_src)      IID_##_type, \
                                    reinterpret_cast<void **>(static_cast<_type **>(_src))

// inetcore\mshtml\src\time\proxy\wmp\array.h
#define IID_TO_PPV(_type,_src)      IID_##_type, \
                                    reinterpret_cast<void **>(static_cast<_type **>(_src))

// inetcore\mshtml\src\time\proxy\wmp\playlist.h
#define IID_TO_PPV(_type,_src)      IID_##_type, \
                                    reinterpret_cast<void **>(static_cast<_type **>(_src))

// inetcore\mshtml\src\time\tags\factory.cpp
#define DECLARE_BEHAVIOR(className)                                     \
    HRESULT BEHAVIOR_CREATEINSTANCE(className)(IElementBehavior ** ppBehavior)  \
    {                                                                   \
        HRESULT                 hr;                                     \
        CComObject<className> * pInstance;                              \
                                                                        \
        hr = THR(CComObject<className>::CreateInstance(&pInstance));    \
        if (S_OK != hr)                                                 \
        {                                                               \
            goto done;                                                  \
        }                                                               \
                                                                        \
        hr = THR(pInstance->QueryInterface(IID_IElementBehavior,        \
                                           (void**) ppBehavior));       \
        if (S_OK != hr)                                                 \
        {                                                               \
            goto done;                                                  \
        }                                                               \
                                                                        \
        hr = S_OK;                                                      \
    done:                                                               \
        if (S_OK != hr)                                                 \
        {                                                               \
            delete pInstance;                                           \
        }                                                               \
        return hr;                                                      \
    }                                                                   \

// inetcore\mshtml\tried\triedctl\atlctl.h
#define END_PROPERTY_MAP() \
			{NULL, 0, NULL, &IID_NULL} \
		}; \
		return pPropMap; \
	}

// inetcore\outlookexpress\autodiscovery\client\fromshell.h
#define ENTERCRITICAL Dll_EnterCriticalSection(&g_csDll)
#define LEAVECRITICAL Dll_LeaveCriticalSection(&g_csDll)
#define ENTERCRITICAL EnterCriticalSection(&g_csDll)
#define LEAVECRITICAL LeaveCriticalSection(&g_csDll)

// inetcore\outlookexpress\autodiscovery\test\adstress\main.cpp
#define SZ_HELP_MESSAGE     " USAGE: ADStress.exe <params>\n" \
                            " PARAMS:\n" \
                            " [-? | -h | -help]: Display this help\n" \
                            " [-mail | -VPN]: Lookup email or VPN settings.  -mail is default.\n" \
                            " [-t | -threads <n>]: Create <n> threads to carry out the requests.\n" \
                            " [-S | Stress <n>]: Stress the Service Server.  Call <n> times, default is 1.  Use <domain>.\n" \
                            " [-ST | StressTime <n>]: Stress the Service Server.  Continue stress for <n> seconds, default is 120.  Use <domain>.\n" \
                            " [-C | Count]: Don't Count Stress Successes and Failures.  A little faster when off.\n" \
                            " <email> | <domain>: The email or domain name to lookup.\n" \
                            "               Email is required if -mail is used.\n" \
                            "             Example email: JoeUser@yahoo.com,   Example domain: yahoo.com\n" \
                            " -VPN: Lookup VPN settings.  This requires <email> or <domain> to be specified.\n"

// inetcore\outlookexpress\inetcomm\ess\ess.h
#define SIZE_ESS_Module_PDU_9 sizeof(ESSSecurityLabel)

// inetcore\outlookexpress\inetcomm\imnxport\asynconn.cpp
#define SPM_ASYNCTIMER          (WM_USER + 3)

// inetcore\outlookexpress\inetcomm\imnxport\thorsspi.cpp
#define LOCK_SECURITY()   EnterCriticalSection(&s_csInitializationSecLock)
#define UNLOCK_SECURITY() LeaveCriticalSection(&s_csInitializationSecLock)

// inetcore\outlookexpress\inetcomm\mimeole\smime.cpp
#define CAA_ALL                 (CAA_SIGNING_TIME | CAA_SMIME_CAPABILITIES)

// inetcore\outlookexpress\inetcomm\mimeole\variantx.h
#define ISSUPPORTEDVT(_vt) \
    (VT_LPSTR == _vt || VT_LPWSTR == _vt || VT_FILETIME == _vt || VT_UI4 == _vt || VT_I4 == _vt || VT_STREAM == _vt)

// inetcore\outlookexpress\mailnews\common\seclabel.cpp
#define KEY_USAGE_SIGNING       (CERT_DIGITAL_SIGNATURE_KEY_USAGE|CERT_NON_REPUDIATION_KEY_USAGE)
#define KEY_USAGE_ENCRYPTION    (CERT_KEY_ENCIPHERMENT_KEY_USAGE|CERT_KEY_AGREEMENT_KEY_USAGE)
#define KEY_USAGE_SIGNENCRYPT   (KEY_USAGE_SIGNING|KEY_USAGE_ENCRYPTION)

// inetcore\outlookexpress\mailnews\inc\thormsgs.h
#define IMAIL_WATCHDOGTIMER     (WM_USER + 1703)
#define SPOOLER_POLLTIMER       (WM_USER + 1750)

// inetcore\outlookexpress\wabw\wabapi\gllocal.c
#define LH_EnterCriticalSection(hlh)	EnterCriticalSection(&hlh->cs)
#define LH_LeaveCriticalSection(hlh)	LeaveCriticalSection(&hlh->cs)

// inetcore\outlookexpress\wabw\wabfind\fnd.h
#define Secondary_Vtbl(C, I) &c_##I##_##C##VI.vtbl

// inetcore\setup\ieak5\ieakutil\ieakutil.h
#define InsGetBool(pszSection, pszKey, fDefault, pszIns) \
    (GetPrivateProfileInt((pszSection), (pszKey), (fDefault), (pszIns)) ? TRUE : FALSE)
#define InsWriteBool(pszSection, pszKey, fValue, pszIns) \
    (WritePrivateProfileString((pszSection), (pszKey), (fValue) ? TEXT("1") : NULL, (pszIns)))
#define InsWriteBoolEx(pszSection, pszKey, fDefault, pszIns) \
    (WritePrivateProfileString((pszSection), (pszKey), (fDefault) ? TEXT("1") : TEXT("0"), (pszIns)))
#define InsWriteYesNo(pszSection, pszKey, fValue, pszIns) \
    (WritePrivateProfileString((pszSection), (pszKey), (fValue) ? TEXT("Yes") : TEXT("No"), (pszIns)))
#define ReadBoolAndCheckButton(pszSection, pszKey, fDefault, pszIns, hDlg, idCtrl) \
    (CheckDlgButton((hDlg), (idCtrl), InsGetBool((pszSection), (pszKey), (fDefault), (pszIns)) ? BST_CHECKED : BST_UNCHECKED))

// inetcore\setup\ieak5\ieakutil\insio.cpp
#define WritePrivateProfileStringEx(pszSection, pszKey, pszValue, pszIns) \
    (WritePrivateProfileString((pszSection), (pszKey), \
        ((pszValue) != NULL) ? (*(pszValue) != TEXT('\0') ? (pszValue) : NULL) : NULL, (pszIns)))

// inetcore\setup\iexpress\exescan\chksect.c
#define IsMemZero(pv,cb) (!(*((char *)pv) || memcmp(pv,((char *)pv)+1,cb-1)))

// inetcore\urlmon\astg\filelkb.cxx
#define TAKE_CS CSafeCriticalSection scs(&_cs);

// inetcore\urlmon\utils\cvar.cxx
#define END_TRY } catch (CException* e) \
        { ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); \
                _afxExceptionLink.m_pException = e; } }

// inetcore\urlmon\zones\secmgr.cxx
#define BAR         TEXT('|')

// inetcore\winhttp\v5.1\autoproxy\dhcpdef.h
#define UNLOCK_RENEW_LIST()     LeaveCriticalSection(&DhcpGlobalRenewListCritSect)
#define LOCK_INTERFACE()        EnterCriticalSection(&DhcpGlobalSetInterfaceCritSect)
#define UNLOCK_INTERFACE()      LeaveCriticalSection(&DhcpGlobalSetInterfaceCritSect)
#define LOCK_OPTIONS_LIST()     EnterCriticalSection(&DhcpGlobalOptionsListCritSect)
#define UNLOCK_OPTIONS_LIST()   LeaveCriticalSection(&DhcpGlobalOptionsListCritSect)

// inetcore\winhttp\v5.1\autoproxy\dhcploc.h
#define LOCK_POPUP()   EnterCriticalSection(&DhcpGlobalPopupCritSect)
#define UNLOCK_POPUP() LeaveCriticalSection(&DhcpGlobalPopupCritSect)

// inetcore\winhttp\v5.1\inc\thrdinfo.h
#define _InternetGetMappedObjectHandle(lpThreadInfo) \
    lpThreadInfo->hObjectMapped

// inetcore\winhttp\v5.1\inc\util.h
#define DLL_INFO_INIT(name, entryPoints) { \
    name, \
    NULL, \
    0, \
    ARRAY_ELEMENTS(entryPoints), \
    (LPDLL_ENTRY_POINT)&entryPoints \
}
#define CompareFileTime(ft1, ft2)   ( ((*(LONGLONG *)&ft1) > (*(LONGLONG *)&ft2)) ? 1 : \
                                        ( ((*(LONGLONG *)&ft1) == (*(LONGLONG *)&ft2)) ? 0 : -1 ) )

// inetcore\winhttp\v5\inc\defaults.h
#define DEFAULT_SECURE_PROTOCOLS        (SP_PROT_SSL2_CLIENT | SP_PROT_SSL3_CLIENT)

// inetcore\winhttp\v5\inc\thrdinfo.h
#define _InternetGetMappedObjectHandle(lpThreadInfo) \
    lpThreadInfo->hObjectMapped

// inetcore\winhttp\v5\inc\util.h
#define DLL_INFO_INIT(name, entryPoints) { \
    name, \
    NULL, \
    0, \
    ARRAY_ELEMENTS(entryPoints), \
    (LPDLL_ENTRY_POINT)&entryPoints \
}
#define CompareFileTime(ft1, ft2)   ( ((*(LONGLONG *)&ft1) > (*(LONGLONG *)&ft2)) ? 1 : \
                                        ( ((*(LONGLONG *)&ft1) == (*(LONGLONG *)&ft2)) ? 0 : -1 ) )

// inetcore\winhttp\v5\urlcache\cachedef.h
#define LOCK_CACHE()                    ENTERCRITICAL( &GlobalCacheCritSect )
#define UNLOCK_CACHE()                  LEAVECRITICAL( &GlobalCacheCritSect )

// inetcore\wininet\apdetect\dhcpdef.h
#define UNLOCK_RENEW_LIST()     LeaveCriticalSection(&DhcpGlobalRenewListCritSect)
#define LOCK_INTERFACE()        EnterCriticalSection(&DhcpGlobalSetInterfaceCritSect)
#define UNLOCK_INTERFACE()      LeaveCriticalSection(&DhcpGlobalSetInterfaceCritSect)
#define LOCK_OPTIONS_LIST()     EnterCriticalSection(&DhcpGlobalOptionsListCritSect)
#define UNLOCK_OPTIONS_LIST()   LeaveCriticalSection(&DhcpGlobalOptionsListCritSect)

// inetcore\wininet\apdetect\dhcploc.h
#define LOCK_POPUP()   EnterCriticalSection(&DhcpGlobalPopupCritSect)
#define UNLOCK_POPUP() LeaveCriticalSection(&DhcpGlobalPopupCritSect)

// inetcore\wininet\common\rescache.cxx
#define ENTERCRIT_NAMERESCACHE()  EnterCriticalSection(&vcritNameresCache)
#define LEAVECRIT_NAMERESCACHE()  LeaveCriticalSection(&vcritNameresCache)

// inetcore\wininet\common\secinit.cxx
#define LOCK_FORTEZZA()   EnterCriticalSection( &InitFortezzaLock )
#define UNLOCK_FORTEZZA() LeaveCriticalSection( &InitFortezzaLock )

// inetcore\wininet\ftp\dirlist.cxx
#define ClearFindDataFields(lpFind) \
    ClearFileTime((lpFind)->ftCreationTime); \
    ClearFileTime((lpFind)->ftLastAccessTime); \
    (lpFind)->dwReserved0 = 0; \
    (lpFind)->dwReserved1 = 0; \
    (lpFind)->cAlternateFileName[0] = '\0';

// inetcore\wininet\ftp\session.h
#define SetSessionLastResponseCode(pSession, prc) \
    CopyMemory(&((pSession)->rcResponseOpenFile), (prc), sizeof(FTP_RESPONSE_CODE))
#define GetSessionLastResponseCode(pSession, prc) \
    CopyMemory((prc), &((pSession)->rcResponseOpenFile), sizeof(FTP_RESPONSE_CODE))
#define AcquireFtpSessionLock(lpSessionInfo) \
    EnterCriticalSection(&lpSessionInfo->CriticalSection)

// inetcore\wininet\inc\defaults.h
#define DEFAULT_SECURE_PROTOCOLS        (SP_PROT_SSL2_CLIENT | SP_PROT_SSL3_CLIENT)

// inetcore\wininet\inc\secinit.h
#define LOCK_SECURITY()   EnterCriticalSection( &InitializationSecLock )
#define UNLOCK_SECURITY() LeaveCriticalSection( &InitializationSecLock )

// inetcore\wininet\inc\serialst.h
#define InitializeSerializedList(list) \
    { \
        InitializeListHead(&(list)->List); \
        InitializeCriticalSection(&(list)->Lock); \
        (list)->ElementCount = 0; \
    }
#define LockSerializedList(list) \
    EnterCriticalSection(&(list)->Lock)
#define UnlockSerializedList(list) \
    LeaveCriticalSection(&(list)->Lock)

// inetcore\wininet\inc\thrdinfo.h
#define _InternetGetMappedObjectHandle(lpThreadInfo) \
    lpThreadInfo->hObjectMapped

// inetcore\wininet\inc\util.h
#define DLL_INFO_INIT(name, entryPoints) { \
    name, \
    NULL, \
    0, \
    ARRAY_ELEMENTS(entryPoints), \
    (LPDLL_ENTRY_POINT)&entryPoints \
}

// inetcore\wininet\socks\wsock32.c
#define CREATE_MUTEX()  InitializeCriticalSection(&CritSec)
#define ENTER_MUTEX()   EnterCriticalSection(&CritSec)
#define LEAVE_MUTEX()   LeaveCriticalSection(&CritSec)

// inetcore\wininet\urlcache\cachedef.h
#define LOCK_CACHE()                    ENTERCRITICAL( &GlobalCacheCritSect )
#define UNLOCK_CACHE()                  LEAVECRITICAL( &GlobalCacheCritSect )

// inetsrv\iis\admin\adsi\adsiis\extension.cxx
#define ENTER_EXTENSION_CRITSECT()  EnterCriticalSection(&g_ExtCritSect)
#define LEAVE_EXTENSION_CRITSECT()  LeaveCriticalSection(&g_ExtCritSect)

// inetsrv\iis\admin\adsi\helper\utils\cdispmgr.cxx
#define ENTER_DISP_TYPEINFO_CRITSECT()  EnterCriticalSection(&g_DispTypeInfoCritSect)
#define LEAVE_DISP_TYPEINFO_CRITSECT()  LeaveCriticalSection(&g_DispTypeInfoCritSect)

// inetsrv\iis\admin\common2\error.cpp
    #define RaiseThreadProtection() \
        do {\
            EnterCriticalSection(&_csSect);\
        } while(0)
    #define LowerThreadProtection() \
        do {\
            LeaveCriticalSection(&_csSect);\
        } while (0)

// inetsrv\iis\admin\common\msg.cpp
    #define RaiseThreadProtection() \
        do {\
            EnterCriticalSection(&_csSect);\
        } while(0)
    #define LowerThreadProtection() \
        do {\
            LeaveCriticalSection(&_csSect);\
        } while (0)

// inetsrv\iis\admin\common\strfn.cpp
    #define RaiseThreadProtection() EnterCriticalSection(&_csSect)
    #define LowerThreadProtection() LeaveCriticalSection(&_csSect)

// inetsrv\iis\admin\snapin\wsecure.cpp
#define SHOW_NON_MASTER(x)\
   (x).ShowWindow(IsMasterInstance() ? SW_HIDE : SW_SHOW)

// inetsrv\iis\config\src\core\schemagen\tcomcatmetaxmlfile.cpp
#define     IIS_SYNTAX_ID_MIMEMAP       8   //  MULTISZ  EXTENDEDTYPE3                                             (| EXTENDEDTYPE3")

// inetsrv\iis\config\src\inc\corhdr.h
#define IsMdPinvokeImpl(x)                  ((x) & mdPinvokeImpl)
#define IsFdPinvokeImpl(x)                  ((x) & fdPinvokeImpl)

// inetsrv\iis\config\src\wmi\atl30\atlcom.h
#define END_PROPERTY_MAP() \
			{NULL, 0, NULL, &IID_NULL, 0, 0, 0} \
		}; \
		return pPropMap; \
	}
#define END_PROP_MAP() \
			{NULL, 0, NULL, &IID_NULL, 0, 0, 0} \
		}; \
		return pPropMap; \
	}
#define BEGIN_SERVICE_MAP(x) public: \
	HRESULT _InternalQueryService(REFGUID guidService, REFIID riid, void** ppvObject) \
	{
#define END_SERVICE_MAP() \
		return E_NOINTERFACE; \
	}
#define END_SINK_MAP() {0, NULL, 0, 0, NULL, NULL} }; return map;}

// inetsrv\iis\config\src\wmi\atl30\atldb.h
#define END_SCHEMA_MAP() \
		if (ppGuid != NULL) \
			return hr; \
		return E_INVALIDARG; \
	}

// inetsrv\iis\config\src\wmi\atl30\atldbcli.h
#define END_ACCESSOR_MAP() \
		; \
		*pColumns = nColumns; \
		return S_OK; \
	}
#define END_PARAM_MAP() \
		*pColumns = nColumns; \
		return S_OK; \
	}

// inetsrv\iis\config\src\wmi\atl30\atlsnap.h
#define END_EXTENSION_SNAPIN_NODEINFO_MAP() \
			return CSnapInItem::GetDataClass(pDataObject, ppItem, pType); \
	};
#define END_SNAPINCOMMAND_MAP() \
			return hr; \
	}
#define BEGIN_SNAPINTOOLBARID_MAP(theClass) \
public: \
	static CSnapInToolbarInfo* GetToolbarInfo() \
	{ \
		static CSnapInToolbarInfo m_toolbarInfo[] = \
		{
#define END_SNAPINTOOLBARID_MAP() \
			{ NULL, NULL, NULL, 0, 0} \
		}; \
		return m_toolbarInfo; \
	}

// inetsrv\iis\iisrearc\core\common\util\datetime.cxx
#define APPEND_STR(a,b)  \
    {CopyMemory(a,b,sizeof(b));  a += sizeof(b)-sizeof(CHAR);}

// inetsrv\iis\iisrearc\iisplus\ssinc\ssinc.hxx
#define SSI_DEF_TIMEFMT_LEN     sizeof( SSI_DEF_TIMEFMT )

// inetsrv\iis\iisrearc\ul\drv\httptypes.h
#define IS_VALID_TIMEOUT_TIMER(a) \
    (((a) >= TimerConnectionIdle) && ((a) < TimerMaximumTimer))

// inetsrv\iis\iisrearc\ul\drv\timeouts.h
#define UlLockTimeoutInfo(pInfo, pOldIrql) \
    UlAcquireSpinLock(&(pInfo)->Lock, pOldIrql)

// inetsrv\iis\iisrearc\ul\drv\ultdip.h
#define IS_VALID_ENDPOINT(pEndpoint)                                        \
    ( ((pEndpoint) != NULL) &&                                              \
      ((pEndpoint)->Signature == UL_ENDPOINT_SIGNATURE) )
#define REFERENCE_ENDPOINT_SELF(endp, action)               \
    REFERENCE_ENDPOINT(                                     \
        (endp),                                             \
        (action),                                           \
        UL_ENDPOINT_SIGNATURE,                              \
        (endp),                                             \
        &(endp)->pEndpointRefOwner,                         \
        -1)
#define DEREFERENCE_ENDPOINT_SELF(endp, action)             \
    DEREFERENCE_ENDPOINT(                                   \
        (endp),                                             \
        (action),                                           \
        UL_ENDPOINT_SIGNATURE,                              \
        (endp),                                             \
        &(endp)->pEndpointRefOwner,                         \
        -1)
#define REFERENCE_ENDPOINT_CONNECTION(endp, action, pconn)  \
    REFERENCE_ENDPOINT(                                     \
        (endp),                                             \
        (action),                                           \
        UL_CONNECTION_SIGNATURE,                            \
        (pconn),                                            \
        &(pconn)->pConnRefOwner,                            \
        (pconn)->MonotonicId)
#define DEREFERENCE_ENDPOINT_CONNECTION(endp, action, pconn)\
    DEREFERENCE_ENDPOINT(                                   \
        (endp),                                             \
        (action),                                           \
        UL_CONNECTION_SIGNATURE,                            \
        (pconn),                                            \
        &(pconn)->pConnRefOwner,                            \
        (pconn)->MonotonicId)

// inetsrv\iis\iisrearc\ul\win9x\src\listener\listener.h
#define LISTENER_STR_PARSE_STATE(x)\
	(\
	x==ParseVerbState?"ParseVerbState":\
	x==ParseUrlState?"ParseUrlState":\
	x==ParseVersionState?"ParseVersionState":\
	x==ParseHeadersState?"ParseHeadersState":\
	x==ParseCookState?"ParseCookState":\
	x==ParseEntityBodyState?"ParseEntityBodyState":\
	x==ParseTrailerState?"ParseTrailerState":\
	x==ParseDoneState?"ParseDoneState":\
	x==ParseErrorState?"ParseErrorState":\
	"ParseUNDEFINEDState"\
	)

// inetsrv\iis\inc\inetinfo.h
#define FC_W3_ALL                      (FC_W3_DIR_BROWSE_CONTROL | \
                                        FC_W3_DEFAULT_LOAD_FILE  | \
                                        FC_W3_CHECK_FOR_WAISDB   | \
                                        FC_W3_DIRECTORY_IMAGE    | \
                                        FC_W3_SERVER_AS_PROXY    | \
                                        FC_W3_CATAPULT_USER_AND_PWD |\
                                        FC_W3_SSI_ENABLED        | \
                                        FC_W3_SSI_EXTENSION      | \
                                        FC_W3_GLOBAL_EXPIRE      | \
                                        FC_W3_SCRIPT_MAPPING     | \
                                        FC_W3_CGI_SCRIPT_TIMEOUT | \
                                        FC_W3_POOL_ODBC_CONN_TIME| \
                                        FC_W3_CACHE_ISAPI_APPS   | \
                                        FC_W3_USE_KEEP_ALIVES    | \
                                        FC_W3_ENABLE_HEADER_DOC  | \
                                        FC_W3_HEADER_DOC_NAME    | \
                                        FC_W3_ENABLE_FOOT_DOC    | \
                                        FC_W3_FOOTER_DOC_NAME    | \
                                        FC_W3_CUSTOMER_HEADERS     \
                                        )

// inetsrv\iis\inc\tcpcons.h
#define TCP_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED       | \
                                 TCP_QUERY_SECURITY            | \
                                 TCP_SET_SECURITY              | \
                                 TCP_ENUMERATE_USERS           | \
                                 TCP_DISCONNECT_USER           | \
                                 TCP_QUERY_STATISTICS          | \
                                 TCP_CLEAR_STATISTICS          | \
                                 TCP_QUERY_ADMIN_INFORMATION   | \
                                 TCP_SET_ADMIN_INFORMATION       \
                                )
#define TCP_GENERIC_READ       (STANDARD_RIGHTS_READ           | \
                                 TCP_QUERY_SECURITY            | \
                                 TCP_ENUMERATE_USERS           | \
                                 TCP_QUERY_ADMIN_INFORMATION   | \
                                 TCP_QUERY_STATISTICS)
#define TCP_GENERIC_WRITE      (STANDARD_RIGHTS_WRITE          | \
                                 TCP_SET_SECURITY              | \
                                 TCP_DISCONNECT_USER           | \
                                 TCP_SET_ADMIN_INFORMATION     | \
                                 TCP_CLEAR_STATISTICS)

// inetsrv\iis\setup\osrc\strfn.cpp
    #define RaiseThreadProtection() EnterCriticalSection(&_csSect)
    #define LowerThreadProtection() LeaveCriticalSection(&_csSect)

// inetsrv\iis\staxinc\cpsock.h
#define LockCPInfo(pcpInfo)    EnterCriticalSection( &(pcpInfo)->InfoCriticalSection )
#define UnlockCPInfo(pcpInfo)  LeaveCriticalSection( &(pcpInfo)->InfoCriticalSection )

// inetsrv\iis\staxinc\dnsapi.h
#define DnsModifyRRSet_A( _pCSet,                                    \
                          _pNSet,                                    \
                          _Options,                                  \
                          _Servers )                                 \
            ( _Options & DNS_UPDATE_SHARED ) ?                       \
                DnsModifyRecords_A( NULL,                            \
                                    ( _pCSet ),                      \
                                    ( _pNSet ),                      \
                                    DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                    ( _Servers ) )                   \
            :                                                        \
                DnsModifyRecordSet_A( NULL,                          \
                                    ( _pCSet ),                      \
                                    ( _pNSet ),                      \
                                    DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                    ( _Servers ) )
#define DnsModifyRRSet_W( _pCSet,                                    \
                          _pNSet,                                    \
                          _Options,                                  \
                          _Servers )                                 \
            ( _Options & DNS_UPDATE_SHARED ) ?                       \
                DnsModifyRecords_W( NULL,                            \
                                    ( _pCSet ),                      \
                                    ( _pNSet ),                      \
                                    DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                    ( _Servers ) )                   \
            :                                                        \
                DnsModifyRecordSet_W( NULL,                          \
                                    ( _pCSet ),                      \
                                    ( _pNSet ),                      \
                                    DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                    ( _Servers ) )
#define DnsModifyRRSet( _pCSet,                                      \
                        _pNSet,                                      \
                        _Options,                                    \
                        _Servers )                                   \
            ( _Options & DNS_UPDATE_SHARED ) ?                       \
                DnsModifyRecords_W( NULL,                            \
                                    ( _pCSet ),                      \
                                    ( _pNSet ),                      \
                                    DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                    ( _Servers ) )                   \
            :                                                        \
                DnsModifyRecordSet_W( NULL,                          \
                                    ( _pCSet ),                      \
                                    ( _pNSet ),                      \
                                    DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                    ( _Servers ) )
#define DnsModifyRRSet( _pCSet,                                      \
                        _pNSet,                                      \
                        _Options,                                    \
                        _Servers )                                   \
            ( _Options & DNS_UPDATE_SHARED ) ?                       \
                DnsModifyRecords_A( NULL,                            \
                                    ( _pCSet ),                      \
                                    ( _pNSet ),                      \
                                    DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                    ( _Servers ) )                   \
            :                                                        \
                DnsModifyRecordSet_A( NULL,                          \
                                    ( _pCSet ),                      \
                                    ( _pNSet ),                      \
                                    DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                    ( _Servers ) )
#define DnsRegisterRRSet_A( _pRSet,                                 \
                            _Options,                               \
                            _Servers )                              \
            ( _Options & DNS_UPDATE_SHARED ) ?                      \
                DnsAddRecords_A( NULL,                              \
                                 ( _pRSet ),                        \
                                 DNS_UPDATE_SECURITY_USE_DEFAULT,   \
                                 ( _Servers ) )                     \
            :                                                       \
                DnsAddRecordSet_A( NULL,                            \
                                   ( _pRSet ),                      \
                                   DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                   ( _Servers ) )
#define DnsRegisterRRSet_W( _pRSet,                                 \
                            _Options,                               \
                            _Servers )                              \
            ( _Options & DNS_UPDATE_SHARED ) ?                      \
                DnsAddRecords_W( NULL,                              \
                                 ( _pRSet ),                        \
                                 DNS_UPDATE_SECURITY_USE_DEFAULT,   \
                                 ( _Servers ) )                     \
            :                                                       \
                DnsAddRecordSet_W( NULL,                            \
                                   ( _pRSet ),                      \
                                   DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                   ( _Servers ) )
#define DnsRegisterRRSet( _pRSet,                                   \
                          _Options,                                 \
                          _Servers )                                \
            ( _Options & DNS_UPDATE_SHARED ) ?                      \
                DnsAddRecords_W( NULL,                              \
                                 ( _pRSet ),                        \
                                 DNS_UPDATE_SECURITY_USE_DEFAULT,   \
                                 ( _Servers ) )                     \
            :                                                       \
                DnsAddRecordSet_W( NULL,                            \
                                   ( _pRSet ),                      \
                                   DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                   ( _Servers ) )
#define DnsRegisterRRSet( _pRSet,                                   \
                          _Options,                                 \
                          _Servers )                                \
            ( _Options & DNS_UPDATE_SHARED ) ?                      \
                DnsAddRecords_A( NULL,                              \
                                 ( _pRSet ),                        \
                                 DNS_UPDATE_SECURITY_USE_DEFAULT,   \
                                 ( _Servers ) )                     \
            :                                                       \
                DnsAddRecordSet_A( NULL,                            \
                                   ( _pRSet ),                      \
                                   DNS_UPDATE_SECURITY_USE_DEFAULT, \
                                   ( _Servers ) )

// inetsrv\iis\staxinc\export\dt_ctrl.h
#define TCM_GET_TIME		( WM_USER + 1800 )
#define TCM_SET_TIME		( WM_USER + 1801 )

// inetsrv\iis\staxinc\hashmap.h
#define     UPDATE_HEADER_STATS( ) { \
            if ( (m_nInsertions + m_nDeletions) >= STAT_FLUSH_THRESHOLD ) { \
                FlushHeaderStats( ); \
            } \
}

// inetsrv\iis\staxinc\ipaccess.hxx
#define SIZEOF_INETA_IP_SEC_LIST( IPList )  \
        ( sizeof(INET_INFO_IP_SEC_LIST) +   \
          (IPList)->cEntries *              \
          sizeof(INET_INFO_IP_SEC_ENTRY)    \
         )

// inetsrv\iis\svcs\admex\secex\comobj.cxx
#define CERT_HEADER_SIZE (sizeof(CERT_HEADER) - 1)
#define CTL_HEADER_SIZE (sizeof(CTL_HEADER) - 1)

// inetsrv\iis\svcs\afsvcloc\svcdef.h
#define LOCK_SVC_GLOBAL_DATA()        EnterCriticalSection( &GlobalSvclocCritSect )
#define UNLOCK_SVC_GLOBAL_DATA()      LeaveCriticalSection( &GlobalSvclocCritSect )

// inetsrv\iis\svcs\cmp\asp51\aspdmon.h
#define FILE_NOTIFY_FILTER  (FILE_NOTIFY_CHANGE_FILE_NAME  | \
                               FILE_NOTIFY_CHANGE_DIR_NAME | \
                               FILE_NOTIFY_CHANGE_ATTRIBUTES | \
                               FILE_NOTIFY_CHANGE_SIZE       | \
                               FILE_NOTIFY_CHANGE_LAST_WRITE | \
                               FILE_NOTIFY_CHANGE_SECURITY)

// inetsrv\iis\svcs\cmp\asp51\ntsec.cpp
#define DESKTOP_ALL (DESKTOP_READOBJECTS     | DESKTOP_CREATEWINDOW     | \
                     DESKTOP_CREATEMENU      | DESKTOP_HOOKCONTROL      | \
                     DESKTOP_JOURNALRECORD   | DESKTOP_JOURNALPLAYBACK  | \
                     DESKTOP_ENUMERATE       | DESKTOP_WRITEOBJECTS     | \
                     DESKTOP_SWITCHDESKTOP   | STANDARD_RIGHTS_REQUIRED)

// inetsrv\iis\svcs\cmp\asp\aspdmon.h
#define FILE_NOTIFY_FILTER  (FILE_NOTIFY_CHANGE_FILE_NAME  | \
                               FILE_NOTIFY_CHANGE_DIR_NAME | \
                               FILE_NOTIFY_CHANGE_ATTRIBUTES | \
                               FILE_NOTIFY_CHANGE_SIZE       | \
                               FILE_NOTIFY_CHANGE_LAST_WRITE | \
                               FILE_NOTIFY_CHANGE_SECURITY)

// inetsrv\iis\svcs\cmp\asp\ntsec.cpp
#define DESKTOP_ALL (DESKTOP_READOBJECTS     | DESKTOP_CREATEWINDOW     | \
                     DESKTOP_CREATEMENU      | DESKTOP_HOOKCONTROL      | \
                     DESKTOP_JOURNALRECORD   | DESKTOP_JOURNALPLAYBACK  | \
                     DESKTOP_ENUMERATE       | DESKTOP_WRITEOBJECTS     | \
                     DESKTOP_SWITCHDESKTOP   | STANDARD_RIGHTS_REQUIRED)

// inetsrv\iis\svcs\ftp\server51\aap.cxx
#define AapLockLists()          EnterCriticalSection( &p_AapListLock )
#define AapUnlockLists()        LeaveCriticalSection( &p_AapListLock )

// inetsrv\iis\svcs\ftp\server51\lsaux.hxx
#define NULL_TIME(x)    (((x).LowPart | (x).HighPart) == 0)
#define NULL_FILE_TIME(x)    (((x).dwLowDateTime | (x).dwHighDateTime) == 0)

// inetsrv\iis\svcs\ftp\server51\proc.hxx
#define LockGlobals()          EnterCriticalSection( &g_GlobalLock );
#define UnlockGlobals()        LeaveCriticalSection( &g_GlobalLock );

// inetsrv\iis\svcs\ftp\server\aap.cxx
#define AapLockLists()          EnterCriticalSection( &p_AapListLock )
#define AapUnlockLists()        LeaveCriticalSection( &p_AapListLock )

// inetsrv\iis\svcs\ftp\server\lsaux.hxx
#define NULL_TIME(x)    (((x).LowPart | (x).HighPart) == 0)
#define NULL_FILE_TIME(x)    (((x).dwLowDateTime | (x).dwHighDateTime) == 0)

// inetsrv\iis\svcs\ftp\server\proc.hxx
#define LockGlobals()          EnterCriticalSection( &g_GlobalLock );
#define UnlockGlobals()        LeaveCriticalSection( &g_GlobalLock );

// inetsrv\iis\svcs\iismap\md5c.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// inetsrv\iis\svcs\iisrtl\datetime.cxx
#define APPEND_STR(a,b)  \
    {CopyMemory(a,b,sizeof(b));  a += sizeof(b)-sizeof(CHAR);}

// inetsrv\iis\svcs\infocomm\atq\atqcport.cxx
#define SIOLockGlobals()   EnterCriticalSection( &g_SIOGlobalCriticalSection )
#define SIOUnlockGlobals() LeaveCriticalSection( &g_SIOGlobalCriticalSection )

// inetsrv\iis\svcs\infocomm\atq\atqtypes.hxx
# define TimeToWait(Timeout)   (((Timeout) == INFINITE) ?INFINITE: \
                                (Timeout) * 1000)
#define IS_ACCEPT_EX_CONTEXT( pContext )         \
    ((pContext)->pfnConnComp && !(pContext)->pEndpoint )
#define I_SetNextTimeout( _c ) {                                    \
    (_c)->NextTimeout = AtqGetCurrentTick() + (_c)->TimeOut;        \
    if ( (_c)->NextTimeout < (_c)->ContextList->LatestTimeout ) {   \
        (_c)->ContextList->LatestTimeout = (_c)->NextTimeout;       \
    }                                                               \
}

// inetsrv\iis\svcs\infocomm\atq\oplock\atqcport.cxx
#define SIOLockGlobals()   EnterCriticalSection( &g_SIOGlobalCriticalSection )
#define SIOUnlockGlobals() LeaveCriticalSection( &g_SIOGlobalCriticalSection )

// inetsrv\iis\svcs\infocomm\cache2\fileopen.cxx
#define LockUriInfo()      ( EnterCriticalSection( &g_csUriInfo ) )
#define UnlockUriInfo()    ( LeaveCriticalSection( &g_csUriInfo ) )

// inetsrv\iis\svcs\infocomm\cache2\tlcach.cxx
#define MemCacheLock()      ( EnterCriticalSection( &g_csMemCache ) )
#define MemCacheUnlock()    ( LeaveCriticalSection( &g_csMemCache ) )

// inetsrv\iis\svcs\infocomm\common\security.cxx
#define LockTokenCache()        EnterCriticalSection( &csTokenCacheLock )
#define UnlockTokenCache()      LeaveCriticalSection( &csTokenCacheLock )

// inetsrv\iis\svcs\infocomm\dcomadm\interf2\secdat.cxx
#define UpdateObjectsCreated() InterlockedIncrement( &g_AdmCounters.ObjectsCreated )
#define UpdateObjectsDestroyed() InterlockedIncrement( &g_AdmCounters.ObjectsDestroyed )

// inetsrv\iis\svcs\infocomm\dcomadm\interfac\secdat.cxx
#define UpdateObjectsCreated() InterlockedIncrement( &g_AdmCounters.ObjectsCreated )
#define UpdateObjectsDestroyed() InterlockedIncrement( &g_AdmCounters.ObjectsDestroyed )

// inetsrv\iis\svcs\infocomm\setup\svcsetup.c
# define AllServicesInfo()   \
  ServiceInfo( GOPHER_SERVICE, "GopherSvc",              \
               "Microsoft Gopher Service (1995)",        \
               ( 70), &g_GopherGuid,                     \
               GOPHERD_ANONYMOUS_SECRET_W,               \
               GOPHERD_ROOT_SECRET_W)                    \
                                                         \
  ServiceInfo( W3_SERVICE_NAME, "W3Svc",                 \
               "Microsoft HTTP Service (1995)",          \
               (80), &g_HTTPGuid,                        \
               W3_ANONYMOUS_SECRET_W,                    \
               W3_ROOT_SECRET_W)                         \
                                                         \
  ServiceInfo( FTP_SERVICE_NAME, "FtpSvc",               \
               "Microsoft FTP Service (1995)",           \
               (21), &g_FTPGuid,                         \
               FTPD_ANONYMOUS_SECRET_W,                  \
               FTPD_ROOT_SECRET_W)                       \
                                                         \
  ServiceInfo( MSN_SERVICE_NAME, "MsnSvc",               \
               "MSN Gateway Service (1995)",             \
               (568), &g_MsnGuid,                        \
               MSN_ANONYMOUS_SECRET_W,                   \
               MSN_ROOT_SECRET_W)                        \

// inetsrv\iis\svcs\loadbal\driver\iislbdr.cxx
#define GetTime(a,b)        KeQuerySystemTime( (PLARGE_INTEGER)&a ); b = (ULONG)(a / (ULONGLONG)(10*1000*1000))

// inetsrv\iis\svcs\loadbal\filter\iislbf.cxx
#define LockGlobals()         EnterCriticalSection( &csGlobalLock )
#define UnlockGlobals()       LeaveCriticalSection( &csGlobalLock );

// inetsrv\iis\svcs\mdadmin\ntsec.h
#define DESKTOP_ALL (DESKTOP_READOBJECTS     | DESKTOP_CREATEWINDOW     | \
                     DESKTOP_CREATEMENU      | DESKTOP_HOOKCONTROL      | \
                     DESKTOP_JOURNALRECORD   | DESKTOP_JOURNALPLAYBACK  | \
                     DESKTOP_ENUMERATE       | DESKTOP_WRITEOBJECTS     | \
                     DESKTOP_SWITCHDESKTOP   | STANDARD_RIGHTS_REQUIRED)
#define WINSTA_ALL  (WINSTA_ENUMDESKTOPS     | WINSTA_READATTRIBUTES    | \
                     WINSTA_ACCESSCLIPBOARD  | WINSTA_CREATEDESKTOP     | \
                     WINSTA_WRITEATTRIBUTES  | WINSTA_ACCESSGLOBALATOMS | \
                     WINSTA_EXITWINDOWS      | WINSTA_ENUMERATE         | \
                     WINSTA_READSCREEN       | \
                     STANDARD_RIGHTS_REQUIRED)

// inetsrv\iis\svcs\nntp\core\include\nntpmacr.h
#define LI_FROM_FILETIME( _pLi, _pFt ) {               \
            (_pLi)->LowPart = (_pFt)->dwLowDateTime;   \
            (_pLi)->HighPart = (_pFt)->dwHighDateTime; \
            }
#define FILETIME_FROM_LI( _pFt, _pLi ) {               \
            (_pFt)->dwLowDateTime = (_pLi)->LowPart;   \
            (_pFt)->dwHighDateTime = (_pLi)->HighPart; \
            }

// inetsrv\iis\svcs\nntp\server\article\src\nntpmacr.h
#define LI_FROM_FILETIME( _pLi, _pFt ) {               \
            (_pLi)->LowPart = (_pFt)->dwLowDateTime;   \
            (_pLi)->HighPart = (_pFt)->dwHighDateTime; \
            }
#define FILETIME_FROM_LI( _pFt, _pLi ) {               \
            (_pFt)->dwLowDateTime = (_pLi)->LowPart;   \
            (_pFt)->dwHighDateTime = (_pLi)->HighPart; \
            }

// inetsrv\iis\svcs\nntp\server\dirnot\src\cretryq.cxx
#define TimeToWait(Timeout)   (((Timeout) == INFINITE) ? INFINITE : \
                                (Timeout) * 1000)

// inetsrv\iis\svcs\nntp\server\hash\src\nntphash.cpp
#define LI_FROM_FILETIME( _pLi, _pFt ) {               \
            (_pLi)->LowPart = (_pFt)->dwLowDateTime;   \
            (_pLi)->HighPart = (_pFt)->dwHighDateTime; \
            }

// inetsrv\iis\svcs\nntp\server\server\smtpdll.cpp
#define LOCK_ID()	EnterCriticalSection(&g_csIdLock);
#define UNLOCK_ID()	LeaveCriticalSection(&g_csIdLock);

// inetsrv\iis\svcs\nntp\server\utest\install\main.c
# define AllServicesInfo()   \
                                                         \
  ServiceInfo( NNTP_SERVICE_NAME, "NntpSvc",             \
               "Microsoft NNTP Service",                 \
               ( 0 ), (119), &g_NntpGuid,                \
               NNTP_ANONYMOUS_SECRET_W,                  \
               NNTP_ROOT_SECRET_W)                       \

// inetsrv\iis\svcs\smtp\aqueue\inc\dsnsink.h
#define MIME_BOUNDARY_START_TIME_SIZE 16*sizeof(CHAR) //Size of string with file-time

// inetsrv\iis\svcs\smtp\aqueue\retrsink\timemath.h
#define I64_LI(cli) (*((__int64*)&cli))
#define LI_I64(i) (*((LARGE_INTEGER*)&i))
#define I64_FT(ft) (*((__int64*)&ft))
#define FT_I64(i) (*((FILETIME*)&i))

// inetsrv\iis\svcs\smtp\inc\ims.h
#define FT_I64(i) (*((FILETIME*)&i))

// inetsrv\iis\svcs\staxcore\hashmap\src\hashmacr.h
#define LI_FROM_FILETIME( _pLi, _pFt ) {               \
            (_pLi)->LowPart = (_pFt)->dwLowDateTime;   \
            (_pLi)->HighPart = (_pFt)->dwHighDateTime; \
            }
#define FILETIME_FROM_LI( _pFt, _pLi ) {               \
            (_pFt)->dwLowDateTime = (_pLi)->LowPart;   \
            (_pFt)->dwHighDateTime = (_pLi)->HighPart; \
            }

// inetsrv\iis\svcs\staxcore\hashmap\utest\main.cpp
#define LOCK(__key__) EnterCriticalSection(&(keyinfo[__key__].cs))
#define UNLOCK(__key__) LeaveCriticalSection(&(keyinfo[__key__].cs))

// inetsrv\iis\svcs\staxcore\simssl2\credcach.hxx
#define LockGlobals()         EnterCriticalSection( &csGlobalLock )
#define UnlockGlobals()       LeaveCriticalSection( &csGlobalLock );

// inetsrv\iis\svcs\staxcore\simssl2\simssl.cpp
#define CompareCertTime(ft1, ft2)   (((*(LONGLONG *)&ft1) > (*(LONGLONG *)&ft2))                    \
                                        ? 1                                                         \
                                        : (((*(LONGLONG *)&ft1) == (*(LONGLONG *)&ft2)) ? 0 : -1 ))

// inetsrv\iis\svcs\svcloc\svcdef.h
#define LOCK_SVC_GLOBAL_DATA()        EnterCriticalSection( &GlobalSvclocCritSect )
#define UNLOCK_SVC_GLOBAL_DATA()      LeaveCriticalSection( &GlobalSvclocCritSect )

// inetsrv\iis\svcs\w3\cisa\atl\atlcom.h
#define END_CONNECTION_POINT_MAP() NULL}; return _entries;}

// inetsrv\iis\svcs\w3\filters\pa\raidmap.cxx
#define LockGlobals()         EnterCriticalSection( &csGlobalLock )
#define UnlockGlobals()       LeaveCriticalSection( &csGlobalLock );

// inetsrv\iis\svcs\w3\filters\sspi\credcach.hxx
#define LockSSPIGlobals()         EnterCriticalSection( &g_csGlobalLock )
#define UnlockSSPIGlobals()       LeaveCriticalSection( &g_csGlobalLock )

// inetsrv\iis\svcs\w3\gateways\odbc\qrycache.cxx
#define LockQueryCache()        EnterCriticalSection( &csQueryCacheLock )
#define UnlockQueryCache()      LeaveCriticalSection( &csQueryCacheLock )

// inetsrv\iis\svcs\w3\gateways\ssinc\ssinc.hxx
#define SSI_DEF_TIMEFMT_LEN     sizeof( SSI_DEF_TIMEFMT )

// inetsrv\iis\svcs\w3\gateways\ssincold\ssinc.hxx
#define SSI_DEF_TIMEFMT_LEN     sizeof( SSI_DEF_TIMEFMT )

// inetsrv\iis\svcs\w3\server\filtinit.cxx
#define SECURE_FILTER   (SF_NOTIFY_SECURE_PORT   | \
                         SF_NOTIFY_READ_RAW_DATA | \
                         SF_NOTIFY_SEND_RAW_DATA | \
                         SF_NOTIFY_ORDER_HIGH)

// inetsrv\iis\svcs\w3\server\w3cons.hxx
#define LockGlobals()           EnterCriticalSection( &csGlobalLock )
#define UnlockGlobals()         LeaveCriticalSection( &csGlobalLock )
#define DEFAULT_DIR_BROWSE_CONTROL      (DIRBROW_SHOW_DATE       | \
                                         DIRBROW_SHOW_TIME       | \
                                         DIRBROW_SHOW_SIZE       | \
                                         DIRBROW_SHOW_EXTENSION  | \
                                         DIRBROW_ENABLED         | \
                                         DIRBROW_LOADDEFAULT)

// inetsrv\iis\svcs\wp\inc\resmonp.h
#define RmpSetMonitorState(state, resource)                                \
    EnterCriticalSection(&RmpMonitorStateLock);                            \
    GetSystemTimeAsFileTime((PFILETIME)&RmpSharedState->LastUpdate);       \
    RmpSharedState->State = (state);                                       \
    RmpSharedState->ActiveResource = (HANDLE)(resource);                   \
    LeaveCriticalSection(&RmpMonitorStateLock);

// inetsrv\iis\ui\admin\common2\error.cpp
    #define RaiseThreadProtection() \
        do {\
            EnterCriticalSection(&_csSect);\
        } while(0)
    #define LowerThreadProtection() \
        do {\
            LeaveCriticalSection(&_csSect);\
        } while (0)

// inetsrv\iis\ui\admin\comprop\msg.cpp
    #define RaiseThreadProtection() \
		do {\
			EnterCriticalSection(&_csSect);\
		} while(0)
    #define LowerThreadProtection() \
		do {\
			LeaveCriticalSection(&_csSect);\
		} while (0)

// inetsrv\iis\ui\admin\comprop\strfn.cpp
    #define RaiseThreadProtection() EnterCriticalSection(&_csSect)
    #define LowerThreadProtection() LeaveCriticalSection(&_csSect)

// inetsrv\iis\ui\admin\w3scfg\security.cpp
#define SHOW_NON_MASTER(x)\
   (x).ShowWindow(IsMasterInstance() ? SW_HIDE : SW_SHOW)

// inetsrv\msmq\published\inc\mq.h
#define MQSEC_QUEUE_GENERIC_READ            (MQSEC_GET_QUEUE_PROPERTIES | \
                                             MQSEC_GET_QUEUE_PERMISSIONS | \
                                             MQSEC_RECEIVE_MESSAGE | \
                                             MQSEC_RECEIVE_JOURNAL_MESSAGE)
#define MQSEC_QUEUE_GENERIC_WRITE           (MQSEC_GET_QUEUE_PROPERTIES | \
                                             MQSEC_GET_QUEUE_PERMISSIONS | \
                                             MQSEC_WRITE_MESSAGE)

// inetsrv\msmq\src\ac\win95\ntdef95.h
#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }

// inetsrv\msmq\src\admin\mqsnap\atlsnap.h
#define END_EXTENSION_SNAPIN_NODEINFO_MAP() \
			return CSnapInItem::GetDataClass(pDataObject, ppItem, pType); \
	};
#define END_SNAPINCOMMAND_MAP() \
			return hr; \
	}
#define BEGIN_SNAPINTOOLBARID_MAP(theClass) \
public: \
	static CSnapInToolbarInfo* GetToolbarInfo() \
	{ \
		static CSnapInToolbarInfo m_toolbarInfo[] = \
		{
#define END_SNAPINTOOLBARID_MAP() \
			{ NULL, NULL, NULL, 0, 0} \
		}; \
		return m_toolbarInfo; \
	}

// inetsrv\msmq\src\apps\mqdiag\mqping\sim.h
#define Msg_TIME_TO_REACH_QUEUE(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_TIME_TO_REACH_QUEUE] ].ulVal
#define Msg_TIME_TO_BE_RECEIVED(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_TIME_TO_BE_RECEIVED] ].ulVal
#define Msg_SENTTIME(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_SENTTIME] ].ulVal
#define Msg_ARRIVEDTIME(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_ARRIVEDTIME] ].ulVal
#define Msg_SECURITY_CONTEXT(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_SECURITY_CONTEXT] ].ulVal

// inetsrv\msmq\src\inc\mqsec.h
#define  MQSEC_SD_ALL_INFO  ( OWNER_SECURITY_INFORMATION |      \
                              GROUP_SECURITY_INFORMATION |      \
                              DACL_SECURITY_INFORMATION  |      \
                              SACL_SECURITY_INFORMATION )
#define MQSEC_QUEUE_GENERIC_READ            (MQSEC_GET_QUEUE_PROPERTIES | \
                                             MQSEC_GET_QUEUE_PERMISSIONS | \
                                             MQSEC_RECEIVE_MESSAGE | \
                                             MQSEC_RECEIVE_JOURNAL_MESSAGE)
#define MQSEC_QUEUE_GENERIC_WRITE           (MQSEC_GET_QUEUE_PROPERTIES | \
                                             MQSEC_GET_QUEUE_PERMISSIONS | \
                                             MQSEC_WRITE_MESSAGE)
#define MQSEC_MACHINE_GENERIC_READ          (MQSEC_GET_MACHINE_PROPERTIES | \
                                             MQSEC_GET_MACHINE_PERMISSIONS | \
                                             MQSEC_RECEIVE_DEADLETTER_MESSAGE | \
                                             MQSEC_RECEIVE_JOURNAL_QUEUE_MESSAGE)
#define MQSEC_MACHINE_GENERIC_WRITE         (MQSEC_GET_MACHINE_PROPERTIES | \
                                             MQSEC_GET_MACHINE_PERMISSIONS | \
                                             MQSEC_CREATE_QUEUE)
#define MQSEC_MACHINE_WORLD_RIGHTS          (MQSEC_GET_MACHINE_PROPERTIES | \
                                             MQSEC_GET_MACHINE_PERMISSIONS)
#define MQSEC_MACHINE_SELF_RIGHTS       (MQSEC_GET_MACHINE_PROPERTIES     | \
                                         MQSEC_GET_MACHINE_PERMISSIONS    | \
                                         MQSEC_SET_MACHINE_PROPERTIES     | \
                                         MQSEC_CHANGE_MACHINE_PERMISSIONS | \
                                         MQSEC_CREATE_QUEUE)
#define MQSEC_SITE_GENERIC_READ             (MQSEC_GET_SITE_PROPERTIES | \
                                             MQSEC_GET_SITE_PERMISSIONS)
#define MQSEC_SITE_GENERIC_WRITE            (MQSEC_GET_SITE_PROPERTIES | \
                                             MQSEC_GET_SITE_PERMISSIONS | \
                                             MQSEC_CREATE_MACHINE)
#define MQSEC_CN_GENERIC_READ               (MQSEC_GET_CN_PROPERTIES | \
                                             MQSEC_GET_CN_PERMISSIONS)
#define MQSEC_CN_GENERIC_WRITE              (MQSEC_GET_CN_PROPERTIES | \
                                             MQSEC_GET_CN_PERMISSIONS)
#define MQSEC_ENTERPRISE_GENERIC_READ       (MQSEC_CREATE_USER | \
                                             MQSEC_GET_ENTERPRISE_PROPERTIES | \
                                             MQSEC_GET_ENTERPRISE_PERMISSIONS)
#define MQSEC_ENTERPRISE_GENERIC_WRITE      (MQSEC_CREATE_USER | \
                                             MQSEC_GET_ENTERPRISE_PROPERTIES | \
                                             MQSEC_GET_ENTERPRISE_PERMISSIONS | \
                                             MQSEC_CREATE_SITE | \
                                             MQSEC_CREATE_CN | \
                                             MQSEC_CREATE_USER)

// inetsrv\msmq\src\mqsec\certifct\certifct.h
#define MY_ENCODING_TYPE  (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)

// inetsrv\msmq\src\mqsec\inc\permit.h
#define GENERIC_READ_MAPPING     ((STANDARD_RIGHTS_READ)     | \
                                  (RIGHT_DS_LIST_CONTENTS)   | \
                                  (RIGHT_DS_READ_PROPERTY)   | \
                                  (RIGHT_DS_LIST_OBJECT))
#define GENERIC_EXECUTE_MAPPING  ((STANDARD_RIGHTS_EXECUTE)  | \
                                  (RIGHT_DS_LIST_CONTENTS))
#define GENERIC_WRITE_MAPPING    ((STANDARD_RIGHTS_WRITE)    | \
                                  (RIGHT_DS_SELF_WRITE)      | \
				  (RIGHT_DS_WRITE_PROPERTY))

// inetsrv\msmq\src\qm\ntsecapi.h
#define POLICY_READ           (STANDARD_RIGHTS_READ             |\
                               POLICY_VIEW_AUDIT_INFORMATION    |\
                               POLICY_GET_PRIVATE_INFORMATION)
#define POLICY_EXECUTE        (STANDARD_RIGHTS_EXECUTE          |\
                               POLICY_VIEW_LOCAL_INFORMATION    |\
                               POLICY_LOOKUP_NAMES )

// inetsrv\query\query\ci\cisecret.cxx
#define _InitUnicodeString( pUnicode, pwch )                       \
   {                                                               \
        (pUnicode)->Buffer    = pwch;                              \
        (pUnicode)->Length    = wcslen( pwch ) * sizeof(WCHAR);    \
        (pUnicode)->MaximumLength = (pUnicode)->Length + sizeof(WCHAR); \
   }

// mergedcomponents\advapi32\security.c
#define IS_EQUAL_AUTHORITY(x, y) \
    RtlEqualMemory((x),(y),sizeof(SID_IDENTIFIER_AUTHORITY))

// multimedia\danim\src\appel\backend\bvr.h
#define BVR_TIMEVARYING_ONLY (~BVR_NOT_TIMEVARYING)

// multimedia\danim\src\appel\include\appelles\common.h
#define ZEROMEM(thing)   memset(&(thing),0,sizeof(thing))

// multimedia\danim\src\appel\privinc\comutil.h
#define INJECT_BOOL(b, pV) \
   V_VT(pV) = VT_BOOL; \
   V_BOOL(pV) = b ? 0xFFFF : 0x0000;

// multimedia\danim\src\appel\privinc\dddevice.h
#define FASTPIX2METER(p, res) ( Real(p) / (res) )

// multimedia\danim\src\appel\privinc\ddsurf.h
#define NEWDDSURF(outdds, surf, box, rect, res, clrk1, clrk2, a, b, str) \
DDSurface::CreateSurface(outdds, surf, box, rect, res, clrk1, clrk2, a, b, str);
#define NEWDDSURF(outdds, surf, box, rect, res, clrk1, clrk2, a, b, str) \
DDSurface::CreateSurface(outdds, surf, box, rect, res, clrk1, clrk2, a, b);

// multimedia\danim\src\appel\privinc\dxmatl.h
#define DA_DECLARE_NOT_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< DAComObject< x > >, CComFailCreator<CLASS_E_NOAGGREGATION> > _CreatorClass;
#define DA_DECLARE_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< DAComObject< x > >, CComCreator< CComAggObject< x > > > _CreatorClass;

// multimedia\danim\src\appel\privinc\except.h
#define HANDLE_ANY_DA_EXCEPTION ( \
  GetExceptionCode() == EXCEPTION_STACK_OVERFLOW ?  \
  EXCEPTION_CONTINUE_SEARCH : \
  _HandleAnyDaException( GetExceptionCode() ) )

// multimedia\danim\src\appel\privinc\opt.h
#define REGISTRYENGINEOPT(opttype) (engineOptimization==1 || (engineOptimization & opttype))
#define PERVIEW_DRECTS_ON  (REGISTRYENGINEOPT(DRECT_OPT) && GetCurrentView().GetPreferences()._dirtyRectsOn)

// multimedia\danim\src\appel\server\srvprims.h
#define PRIMPOSTCODE2(ret1,ret2) PRIMPOSTCODE0(*ret1 && *ret2)

// multimedia\danim\src\appel\values\misc\xform2.cpp
#define REAL2PIX(imgCoord, res) (floor((imgCoord) * (res) + 0.5))
#define SPECIALIZED_LOOP(xexp,yexp) \
{                                               \
  int i; \
  for (i=0; i<numPts; i++) \
  { Real x = srcPts[i]->x, y = srcPts[i]->y; \
    gdiPts[i].x = width + REAL2PIX(xexp,resolution); \
    gdiPts[i].y = height - REAL2PIX(yexp,resolution); \
  } \
}
#define SPECIALIZED_LOOP(xexp,yexp) \
{                                               \
  int i; \
  for (i=0; i<numPts; i++) \
  { Real x = srcPts[i].x, y = srcPts[i].y; \
    gdiPts[i].x = width + REAL2PIX(xexp,resolution); \
    gdiPts[i].y = height - REAL2PIX(yexp,resolution); \
  } \
}

// multimedia\danim\src\dalibc\strfns.cpp
#define W2A(lpw) (\
        ((LPCWSTR)lpw == NULL) ? NULL : (\
                _convert = (lstrlenW(lpw)+1)*2,\
                W2AHelper((LPSTR) alloca(_convert), lpw, _convert)))

// multimedia\danim\src\dalite\include\dalatl.h
#define DA_DECLARE_NOT_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< DAComObject< x > >, CComFailCreator<CLASS_E_NOAGGREGATION> > _CreatorClass;
#define DA_DECLARE_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< DAComObject< x > >, CComCreator< CComAggObject< x > > > _CreatorClass;

// multimedia\danim\src\daxctl\controls\mmctl\inc\ochelp.h
#define CI_MMSTANDARD  (CI_MMCONTROL | CI_SAFEFORSCRIPTING \
					    | CI_SAFEFORINITIALIZING)
#define HelpNew(cb) HelpMemAlloc(HM_ZEROINIT | HM_LEAKDETECT, (cb))

// multimedia\danim\src\daxctl\controls\mmseq\seqevent.h
	#define FIRE_EVENTNAME(pConnectionPoint, param1, param2) \
		PConnectionPoint->FireEvent(DISPID_EVENT_EVENTNAME, \
			<VT for param1>, param1, \
			<VT for param2>, param2, \
			0)
#define FIRE_SEQLOAD(pConnectionPoint) \
	pConnectionPoint->FireEvent(DISPID_SEQLOAD_EVENT, 0)

// multimedia\danim\src\daxctl\controls\path\pathevnt.h
    #define FIRE_EVENTNAME(pConnectionPoint, param1, param2) \
        pConnectionPoint->FireEvent(DISPID_PATH_EVENT_EVENTNAME, \
            <VT for param1>, param1, \
            <VT for param2>, param2, \
            0)
#define FIRE_ONSTOP(pConnectionPoint) \
    if (m_fOnWindowLoadFired && !m_fOnStopFiring) \
    { \
        m_fOnStopFiring = true; \
        pConnectionPoint->FireEvent(DISPID_PATH_EVENT_ONSTOP, 0); \
        m_fOnStopFiring = false; \
    }
#define FIRE_ONPLAY(pConnectionPoint) \
    if (m_fOnWindowLoadFired && !m_fOnPlayFiring) \
    { \
        m_fOnPlayFiring = true; \
        pConnectionPoint->FireEvent(DISPID_PATH_EVENT_ONPLAY, 0); \
        m_fOnPlayFiring = false; \
    }
#define FIRE_ONPAUSE(pConnectionPoint) \
    if (m_fOnWindowLoadFired && !m_fOnPauseFiring) \
    { \
        m_fOnPauseFiring = true; \
        pConnectionPoint->FireEvent(DISPID_PATH_EVENT_ONPAUSE, 0); \
        m_fOnPauseFiring = false; \
    }
#define FIRE_ONSEEK(pConnectionPoint, SeekTime) \
    if (m_fOnWindowLoadFired && !m_fOnSeekFiring) \
    { \
        m_fOnSeekFiring = true; \
        pConnectionPoint->FireEvent(DISPID_PATH_EVENT_ONSEEK, VT_R8, SeekTime, 0); \
        m_fOnSeekFiring = false; \
    }

// multimedia\danim\src\daxctl\controls\sgrfx\sgevent.h
	#define FIRE_EVENTNAME(pConnectionPoint, param1, param2) \
		pConnectionPoint->FireEvent(DISPID_SG_EVENT_EVENTNAME, \
			<VT for param1>, param1, \
			<VT for param2>, param2, \
			0)
#define FIRE_MOUSEMOVE(pConnectionPoint, BUTTON, SHIFT, X, Y) \
    if (m_fOnWindowLoadFired) \
	    pConnectionPoint->FireEvent(DISPID_SG_EVENT_MOUSEMOVE, \
		VT_I4, BUTTON, \
		VT_I4, SHIFT, \
		VT_I4, X, \
		VT_I4, Y, \
		0)
#define FIRE_MOUSEDOWN(pConnectionPoint, BUTTON, SHIFT, X, Y) \
    if (m_fOnWindowLoadFired) \
	    pConnectionPoint->FireEvent(DISPID_SG_EVENT_MOUSEDOWN, \
		VT_I4, BUTTON, \
		VT_I4, SHIFT, \
		VT_I4, X, \
		VT_I4, Y, \
		0)
#define FIRE_MOUSEUP(pConnectionPoint, BUTTON, SHIFT, X, Y) \
    if (m_fOnWindowLoadFired) \
	    pConnectionPoint->FireEvent(DISPID_SG_EVENT_MOUSEUP, \
		VT_I4, BUTTON, \
		VT_I4, SHIFT, \
		VT_I4, X, \
		VT_I4, Y, \
		0)
#define FIRE_DBLCLICK(pConnectionPoint) \
    if (m_fOnWindowLoadFired) \
	    pConnectionPoint->FireEvent(DISPID_SG_EVENT_DBLCLICK, 0)
#define FIRE_CLICK(pConnectionPoint) \
    if (m_fOnWindowLoadFired) \
	    pConnectionPoint->FireEvent(DISPID_SG_EVENT_CLICK, 0)

// multimedia\danim\src\daxctl\controls\sprite\sprevent.h
    #define FIRE_EVENTNAME(pConnectionPoint, param1, param2) \
        pConnectionPoint->FireEvent(DISPID_EVENT_EVENTNAME, \
            <VT for param1>, param1, \
            <VT for param2>, param2, \
            0)
#define FIRE_ONPLAYMARKER(pConnectionPoint, MARKER) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_ONPLAYMARKER, \
            VT_BSTR, MARKER, \
            0)
#define FIRE_ONMARKER(pConnectionPoint, MARKER) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_ONMARKER, \
            VT_BSTR, MARKER, \
            0)
#define FIRE_ONSTOP(pConnectionPoint) \
    if (!m_fOnWindowUnloadFired && !m_fOnStopFiring) \
    { \
        m_fOnStopFiring = true; \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_ONSTOP, 0); \
        m_fOnStopFiring = false; \
    }
#define FIRE_ONPLAY(pConnectionPoint) \
    if (!m_fOnWindowUnloadFired && !m_fOnPlayFiring) \
    { \
        m_fOnPlayFiring = true; \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_ONPLAY, 0); \
        m_fOnPlayFiring = false; \
    }
#define FIRE_ONPAUSE(pConnectionPoint) \
    if (!m_fOnWindowUnloadFired && !m_fOnPauseFiring) \
    { \
        m_fOnPauseFiring = true; \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_ONPAUSE, 0);\
        m_fOnPauseFiring = false;\
    }
#define FIRE_CLICK(pConnectionPoint) \
    if (!m_fOnWindowUnloadFired) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_CLICK, 0)
#define FIRE_DBLCLICK(pConnectionPoint) \
    if (!m_fOnWindowUnloadFired) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_DBLCLICK, 0)
#define FIRE_MOUSEDOWN(pConnectionPoint, BUTTON, SHIFT, X, Y) \
    if (!m_fOnWindowUnloadFired) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_MOUSEDOWN, \
            VT_I4, BUTTON, \
            VT_I4, SHIFT, \
            VT_I4, X, \
            VT_I4, Y, \
            0)
#define FIRE_MOUSEENTER(pConnectionPoint) \
    if (!m_fOnWindowUnloadFired) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_MOUSEENTER, 0)
#define FIRE_MOUSELEAVE(pConnectionPoint) \
    if (!m_fOnWindowUnloadFired) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_MOUSELEAVE, 0)
#define FIRE_MOUSEMOVE(pConnectionPoint, BUTTON, SHIFT, X, Y) \
    if (!m_fOnWindowUnloadFired) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_MOUSEMOVE, \
            VT_I4, BUTTON, \
            VT_I4, SHIFT, \
            VT_I4, X, \
            VT_I4, Y, \
            0)
#define FIRE_MOUSEUP(pConnectionPoint, BUTTON, SHIFT, X, Y) \
    if (!m_fOnWindowUnloadFired) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_MOUSEUP, \
            VT_I4, BUTTON, \
            VT_I4, SHIFT, \
            VT_I4, X, \
            VT_I4, Y, \
            0)
#define FIRE_ONMEDIALOADED(pConnectionPoint, URL) \
    if (!m_fOnWindowUnloadFired) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_ONMEDIALOADED, \
            VT_BSTR, URL, \
            0)
#define FIRE_ONSEEK(pConnectionPoint, TIME) \
    if (!m_fOnWindowUnloadFired) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_ONSEEK, \
            VT_R8, TIME, \
            0)
#define FIRE_ONFRAMESEEK(pConnectionPoint, FRAME) \
    if (!m_fOnWindowUnloadFired) \
        pConnectionPoint->FireEvent(DISPID_SPRITE_EVENT_ONFRAMESEEK, \
            VT_I4, FRAME, \
            0)

// multimedia\danim\src\daxctl\inc\memlayer.h
#define ALLOC_EXTRA 4 + (sizeof(int))

// multimedia\danim\src\include\daatl.h
#define DA_DECLARE_NOT_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< DAComObject< x > >, CComFailCreator<CLASS_E_NOAGGREGATION> > _CreatorClass;
#define DA_DECLARE_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< DAComObject< x > >, CComCreator< CComAggObject< x > > > _CreatorClass;

// multimedia\danim\src\lm\chrome\include\utils.h
#define IID_TO_PPV(_type,_src)      IID_##_type, \
                                    reinterpret_cast<void **>(static_cast<_type **>(_src))

// multimedia\danim\src\lm\control\execute.cpp
#define RET_LONG_ADDR			(&longTmp1)
#define RET_COM_ADDR			(_com_count++, &comTmp)
#define RET_COM_ADDR			(&comTmp)

// multimedia\danim\src\time\include\atlutil.h
#define DA_DECLARE_NOT_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< DAComObject< x > >, CComFailCreator<CLASS_E_NOAGGREGATION> > _CreatorClass;
#define DA_DECLARE_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< DAComObject< x > >, CComCreator< CComAggObject< x > > > _CreatorClass;

// multimedia\danim\src\time\include\util.h
#define IID_TO_PPV(_type,_src)      IID_##_type, \
                                    reinterpret_cast<void **>(static_cast<_type **>(_src))

// multimedia\danim\tools\toolsrc\mkdep\mkdep.c
#define FSwitchCh(ch)   ((ch)=='-' || (ch) == '/' || (ch) == '@')

// multimedia\danim\tools\x86\aactive\inc\msimusic.h
#define MAKE_KEY( isflat, root ) ( (isflat) ? ( 0x8000 | (root) ) | (root) )
#define KEY_ROOT( key ) ( (key) & 0x1f )
#define KEY_ISFLAT( key ) ( ( (key) & 0x8000 ) != 0 )

// multimedia\directx\applicationmanager\appmansetup\global.h
#define OS_VERSION_WIN9X              (OS_VERSION_WIN95 | OS_VERSION_WIN98)

// multimedia\directx\applicationmanager\cominterface\applicationentry.cpp
#define VALIDATE_PROPERTY(a)          m_InformationManager.ValidateApplicationPropertyWithIndex((a), &m_sApplicationData)
#define INVALIDATE_PROPERTY(a)        m_InformationManager.InvalidateApplicationPropertyWithIndex((a), &m_sApplicationData)

// multimedia\directx\applicationmanager\cominterface\win32api.h
#define OS_VERSION_9x               (OS_VERSION_WIN95 | OS_VERSION_WIN95_OSR1 | OS_VERSION_WIN95_OSR2 | OS_VERSION_WIN95_OSR3 | OS_VERSION_WIN95_OSR4 | OS_VERSION_WIN98 | OS_VERSION_WIN98_OSR1 | OS_VERSION_WIN98_OSR2 | OS_VERSION_WIN98_OSR3 | OS_VERSION_WIN98_OSR4)

// multimedia\directx\ddrawex\ddrawex.h
#define	DDSCAPS_DATAEXCHANGE	(DDSCAPS_SYSTEMMEMORY|DDSCAPS_VIDEOMEMORY)

// multimedia\directx\ddrawex\dx3inc\d3dcaps.h
#define D3DDEBCAPS_MEM (D3DDEBCAPS_SYSTEMMEMORY|D3DDEBCAPS_VIDEOMEMORY)

// multimedia\directx\ddrawex\dx3inc\d3dhal.h
#define D3DHAL_DEFAULT_TL_NUM	((32 * 1024) / sizeof (D3DTLVERTEX))
#define D3DHAL_DEFAULT_H_NUM	((32 * 1024) / sizeof (D3DHVERTEX))
#define D3DHAL_SIZE_V1 sizeof( D3DHAL_CALLBACKS )

// multimedia\directx\ddrawex\dx3inc\d3dtypes.h
#define CI_GETFRACTION(ci) ((ci) & 0xff)

// multimedia\directx\ddrawex\dx3inc\ddrawex.h
#define	DDSCAPS_DATAEXCHANGE	(DDSCAPS_SYSTEMMEMORY|DDSCAPS_VIDEOMEMORY)

// multimedia\directx\ddrawex\dx3inc\ddrawi.h
#define DDHALINFOSIZE_V1 sizeof( DDHALINFO_V1)
#define DDHALINFOSIZE_V2 sizeof( DDHALINFO )

// multimedia\directx\ddrawex\dx6\d3dcaps.h
#define D3DDEVICEDESCSIZE (sizeof(D3DDEVICEDESC))
#define D3DDEBCAPS_MEM (D3DDEBCAPS_SYSTEMMEMORY|D3DDEBCAPS_VIDEOMEMORY)

// multimedia\directx\ddrawex\dx6\d3drmdef.h
#define D3DRMCLEAR_ALL                  (D3DRMCLEAR_TARGET | \
                                         D3DRMCLEAR_ZBUFFER | \
                                         D3DRMCLEAR_DIRTYRECTS)

// multimedia\directx\ddrawex\dx6\d3dtypes.h
#define CI_GETFRACTION(ci) ((ci) & 0xff)
#define D3DFVF_VERTEX ( D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 )
#define D3DFVF_LVERTEX ( D3DFVF_XYZ | D3DFVF_RESERVED1 | D3DFVF_DIFFUSE | \
                         D3DFVF_SPECULAR | D3DFVF_TEX1 )
#define D3DFVF_TLVERTEX ( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | \
                          D3DFVF_TEX1 )

// multimedia\directx\ddrawex\dx6\dmusicf.h
#define DMUS_PLAYMODE_PEDALPOINT			(DMUS_PLAYMODE_SCALE_ROOT | DMUS_PLAYMODE_SCALE_INTERVALS)
#define DMUS_PLAYMODE_PURPLEIZED			(DMUS_PLAYMODE_SCALE_INTERVALS | DMUS_PLAYMODE_CHORD_INTERVALS | \
											DMUS_PLAYMODE_CHORD_ROOT)
#define DMUS_PLAYMODE_NORMALCHORD		(DMUS_PLAYMODE_CHORD_ROOT | DMUS_PLAYMODE_CHORD_INTERVALS)

// multimedia\directx\ddrawex\dx6\dsetup.h
#define DSETUP_DIRECTX  (DSETUP_DXCORE|DSETUP_DDRAWDRV|DSETUP_DSOUNDDRV)

// multimedia\directx\dinput\diconfig\cdevicecontrol.h
#define CAF_TOPLEFT (CAF_TOP | CAF_LEFT)
#define CAF_TOPRIGHT (CAF_TOP | CAF_RIGHT)
#define CAF_BOTTOMLEFT (CAF_BOTTOM | CAF_LEFT)
#define CAF_BOTTOMRIGHT (CAF_BOTTOM | CAF_RIGHT)

// multimedia\directx\dinput\diconfig\configwnd.h
#define MAP2USER(m) (int((m) & 0x0000ffff))

// multimedia\directx\dinput\diconfig\flextree.cpp
#define FORALLCHILDREN(pChild) \
	for (CFTItem *pChild = m_pFirst; pChild != NULL; pChild = pChild->m_pNext)

// multimedia\directx\dinput\diconfig\privcom.cpp
#define cbX(X) sizeof(X)

// multimedia\directx\dinput\dx7\diquick\diquick.h
#define IsUnicodeDidc(didc)     ((didc) & 1)
#define IsFFDidc(didc)          ((didc) == 2 || (didc) == 3)
#define cbX(X) sizeof(X)
#define ZeroX(x) ZeroMemory(&(x), cbX(x))
#define fLimpFF(f1, f2) (!(f1) || (f2))
#define propReadOnly            MAKEINTRESOURCE(WM_APP)

// multimedia\directx\dinput\dx7\diquick\diqvint.c
#define UDM_SETRANGE32  (WM_USER + 111)
#define UDM_GETRANGE32  (WM_USER + 112)

// multimedia\directx\dinput\dx7\dll\didenum.c
        #define MAKEJOY(n)                                                  \
    {   &rgGUID_Joystick[n],DIDEVTYPE_JOYSTICK, CJoy_New,           }

// multimedia\directx\dinput\dx7\dll\didev.c
    #define g_hgpaExcl      (&g_gpaExcl)

// multimedia\directx\dinput\dx7\dll\diem.c
#define PUN(T, v)   OBJAT(T, &(v))

// multimedia\directx\dinput\dx7\dll\diem.h
#define PostWorkerMessage(thid, lp)                                     \
        PostThreadMessage(thid, WM_NULL, WT_WPARAM, (LPARAM)(lp))       \
#define NudgeWorkerThread(thid)                                         \
        PostThreadMessage(thid, WM_NULL, WT_WPARAM, (LPARAM)NULL)

// multimedia\directx\dinput\dx7\dll\digenj.c
#define c_podfJoyXY         (&c_rgodfJoy[iJoyStateAxisX])
#define c_podfJoyZ          (&c_rgodfJoy[iJoyStateAxisZ])
#define c_podfJoyR          (&c_rgodfJoy[iJoyStateAxisRz])
#define c_podfJoyU          (&c_rgodfJoy[iJoyStateAxisS0])
#define c_podfJoyV          (&c_rgodfJoy[iJoyStateAxisS1])
#define c_podfJoyButtons    (&c_rgodfJoy[cJoyStateAxisMax])
#define c_podfJoyPOV        (&c_rgodfJoy[cJoyStateAxisMax+32])

// multimedia\directx\dinput\dx7\dll\digenm.c
#define c_podfMouseAxes     (&c_rgodfMouse[0])
#define c_podfMouseButtons  (&c_rgodfMouse[3])

// multimedia\directx\dinput\dx7\dll\dihid.c
    #define ConvertValue(f1, f2)                                    \
            JoyPosValue(&cfg.hwc, f1, iAxis) =                          \
                    CHid_CoordinateTransform(Dst, Src, pjrc->f2)        \
        #define ConvertValue(f1, f2)                           \
            pCal->f2 = CHid_CoordinateTransform(Dst, Src,     \
                                             JoyPosValue(&cfg.hwc, f1, iAxis) )

// multimedia\directx\dinput\dx7\dll\dihid.h
    #define VID_PID_TEMPLATE        TEXT("VID_%04X&PID_%04X")

// multimedia\directx\dinput\dx7\dll\dihidini.c
    #define THINGS()                                                        \
        THING(df.rgodf,     cbCxX(this->df.dwNumObjs, DIOBJECTDATAFORMAT)); \
        THING(rghoc,        cbCxX(this->df.dwNumObjs, HIDOBJCAPS));         \
        THING(rgcaps,       cbCxX(this->ccaps, HIDGROUPCAPS));              \
        THING(pjrcNext,     cbCxX(cjrc, JOYRANGECONVERT));                  \
    #define THINGS()                                                        \
        THING(hriIn.rgdata,    cbCxX(this->hriIn.cdataMax, HIDP_DATA));     \
        THING(hriOut.rgdata,   cbCxX(this->hriOut.cdataMax, HIDP_DATA));    \
        THING(hriFea.rgdata,   cbCxX(this->hriFea.cdataMax, HIDP_DATA));    \
        THING(hriIn.pvReport,  this->hriIn.cbReport);                       \
        THING(hriOut.pvReport, this->hriOut.cbReport);                      \
        THING(hriFea.pvReport, this->hriFea.cbReport);                      \
        THING(pvPhys,          this->cbPhys);                               \
        THING(pvStage,         this->cbPhys);                               \

// multimedia\directx\dinput\dx7\dll\dijoycfg.c
#define HAS_VIDPID ( ParseVIDPID( &DontCare, &DontCare, wszType ) )
    #define hresFullValidUVStr(pjuv, f, iarg)                           \
        hresFullValidUVStr_(pjuv->f, cA(pjuv->f), #f, s_szProc,iarg)\

// multimedia\directx\dinput\dx7\dll\dijoyreg.c
#define CopyCalibration(f, ui) \
                cal.l##f = (&phwc->hwv.jrvHardware.jp##f.dwX)[ui]

// multimedia\directx\dinput\dx7\dll\dilib2.c
#define MAKEODF(b)                                                      \
    { &GUID_Key, b,                                                     \
      DIDFT_BUTTON | DIDFT_MAKEINSTANCE(b) | 0x80000000, }              \

// multimedia\directx\dinput\dx7\dll\dinputi.h
#define cbX(X) sizeof(X)
#define ZeroX(x) ZeroBuf(&(x), cbX(x))
#define fLimpFF(f1, f2) (!(f1) || (f2))
    #define ValidateF(c, arg) \
        ((c) ? 0 : (RPF arg, ValidationException(), 0))
#define ecValidation (ERROR_SEVERITY_ERROR | hresLe(ERROR_INVALID_PARAMETER))
#define DI_DAC_OWNER (WRITE_DAC | WRITE_OWNER)
#define DI_KEY_ALL_ACCESS (KEY_ALL_ACCESS & ~DI_DAC_OWNER)
#define __Class_Vtbl(C, I)              &c_##I##_##C##VI.vtbl
#define HRES_MSG(this, msg, fn) \
    case msg: hres = HANDLE_##msg(this, wParam, lParam, fn); break

// multimedia\directx\dinput\dx7\dll\dithunk.c
#define poteExp(pinth) (&(pinth)->OptionalHeader. \
                          DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT])

// multimedia\directx\dinput\dx7\dll\dithunk.h
#define MAKELP(sel, ofs)            (PV)MAKELPARAM(ofs, sel)

// multimedia\directx\dinput\dx7\dll\diutil.c
#define PID_        TEXT("&PID_")

// multimedia\directx\dinput\dx8\dimap\dimapp.h
#define CAF_TOPLEFT (CAF_TOP | CAF_LEFT)
#define CAF_TOPRIGHT (CAF_TOP | CAF_RIGHT)
#define CAF_BOTTOMLEFT (CAF_BOTTOM | CAF_LEFT)
#define CAF_BOTTOMRIGHT (CAF_BOTTOM | CAF_RIGHT)

// multimedia\directx\dinput\dx8\diquick\diquick.h
#define IsUnicodeDidc(didc)     ((didc) & 1)
#define IsFFDidc(didc)          ((didc) == 2 || (didc) == 3)
#define cbX(X) sizeof(X)
#define ZeroX(x) ZeroMemory(&(x), cbX(x))
#define fLimpFF(f1, f2) (!(f1) || (f2))
#define propReadOnly            MAKEINTRESOURCE(WM_APP)

// multimedia\directx\dinput\dx8\diquick\diqvint.c
#define UDM_SETRANGE32  (WM_USER + 111)
#define UDM_GETRANGE32  (WM_USER + 112)

// multimedia\directx\dinput\dx8\dll\didenum.c
        #define MAKEJOY(n)                                                  \
    {   &rgGUID_Joystick[n],DI8DEVCLASS_GAMECTRL, CJoy_New,           }

// multimedia\directx\dinput\dx8\dll\didev.c
    #define g_hgpaExcl      (&g_gpaExcl)

// multimedia\directx\dinput\dx8\dll\didevdf.c
#define MARK_OBJECT_AS_USED( dwSem ) ( dwSem |= DISEM_RES_SET( 1 ) )

// multimedia\directx\dinput\dx8\dll\diem.c
#define PUN(T, v)   OBJAT(T, &(v))

// multimedia\directx\dinput\dx8\dll\diem.h
#define PostWorkerMessage(thid, lp)                                     \
        PostThreadMessage(thid, WM_NULL, WT_WPARAM, (LPARAM)(lp))       \
#define NudgeWorkerThread(thid)                                         \
        PostThreadMessage(thid, WM_NULL, WT_WPARAM, (LPARAM)NULL)

// multimedia\directx\dinput\dx8\dll\digenm.c
#define c_podfMouseAxes     (&c_rgodfMouse[0])
#define c_podfMouseButtons  (&c_rgodfMouse[3])

// multimedia\directx\dinput\dx8\dll\dihid.c
    #define ConvertValue(f1, f2)                                    \
            JoyPosValue(&cfg.hwc, f1, iAxis) =                          \
                    CHid_CoordinateTransform(Dst, Src, pjrc->f2)        \
        #define ConvertValue(f1, f2)                           \
            pCal->f2 = CHid_CoordinateTransform(Dst, Src,     \
                                             JoyPosValue(&cfg.hwc, f1, iAxis) )

// multimedia\directx\dinput\dx8\dll\dihid.h
    #define VID_PID_TEMPLATE        TEXT("VID_%04X&PID_%04X")

// multimedia\directx\dinput\dx8\dll\dihidini.c
    #define THINGS()                                                        \
        THING(df.rgodf,     cbCxX(this->df.dwNumObjs, DIOBJECTDATAFORMAT)); \
        THING(rghoc,        cbCxX(this->df.dwNumObjs, HIDOBJCAPS));         \
        THING(rgcaps,       cbCxX(this->ccaps, HIDGROUPCAPS));              \
        THING(pjrcNext,     cbCxX(cjrc, JOYRANGECONVERT));                  \
    #define THINGS()                                                        \
        THING(hriIn.rgdata,    cbCxX(this->hriIn.cdataMax, HIDP_DATA));     \
        THING(hriOut.rgdata,   cbCxX(this->hriOut.cdataMax, HIDP_DATA));    \
        THING(hriFea.rgdata,   cbCxX(this->hriFea.cdataMax, HIDP_DATA));    \
        THING(hriIn.pvReport,  this->hriIn.cbReport);                       \
        THING(hriOut.pvReport, this->hriOut.cbReport);                      \
        THING(hriFea.pvReport, this->hriFea.cbReport);                      \
        THING(pvPhys,          this->cbPhys);                               \
        THING(pvStage,         this->cbPhys);                               \

// multimedia\directx\dinput\dx8\dll\dijoycfg.c
#define HAS_VIDPID ( ParseVIDPID( &DontCare, &DontCare, wszType ) )
    #define hresFullValidUVStr(pjuv, f, iarg)                           \
        hresFullValidUVStr_(pjuv->f, cA(pjuv->f), #f, s_szProc,iarg)\

// multimedia\directx\dinput\dx8\dll\dijoyreg.c
#define CopyCalibration(f, ui) \
                cal.l##f = (&phwc->hwv.jrvHardware.jp##f.dwX)[ui]

// multimedia\directx\dinput\dx8\dll\dilib2.c
#define MAKEODF(b)                                                      \
    { &GUID_Key, b,                                                     \
      DIDFT_BUTTON | DIDFT_MAKEINSTANCE(b) | 0x80000000, }              \

// multimedia\directx\dinput\dx8\dll\dinputi.h
#define cbX(X) sizeof(X)
#define ZeroX(x) ZeroBuf(&(x), cbX(x))
#define fLimpFF(f1, f2) (!(f1) || (f2))
    #define ValidateF(c, arg) \
        ((c) ? 0 : (RPF arg, ValidationException(), 0))
#define ecValidation (ERROR_SEVERITY_ERROR | hresLe(ERROR_INVALID_PARAMETER))
#define DI_DAC_OWNER (WRITE_DAC | WRITE_OWNER)
#define DI_KEY_ALL_ACCESS (KEY_ALL_ACCESS & ~DI_DAC_OWNER)
#define __Class_Vtbl(C, I)              &c_##I##_##C##VI.vtbl
#define HRES_MSG(this, msg, fn) \
    case msg: hres = HANDLE_##msg(this, wParam, lParam, fn); break

// multimedia\directx\dinput\dx8\dll\dithunk.c
#define poteExp(pinth) (&(pinth)->OptionalHeader. \
                          DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT])

// multimedia\directx\dinput\dx8\dll\dithunk.h
#define MAKELP(sel, ofs)            (PV)MAKELPARAM(ofs, sel)

// multimedia\directx\dinput\dx8\dll\diutil.c
#define PID_        TEXT("&PID_")

// multimedia\directx\dinput\pid\baggage.h
#define cbX(X) sizeof(X)
#define ZeroX(x) ZeroBuf(&(x), cbX(x))
#define fLimpFF(f1, f2) (!(f1) || (f2))
    #define ValidateF(c, arg) \
        ((c) ? 0 : (RPF arg, ValidationException(), 0))

// multimedia\directx\dinput\pid\pidi.h
#define REGSTR_PATH_VID_PID_TEMPLATE    REGSTR_PATH_JOYOEM TEXT("\\VID_%04X&PID_%04X")

// multimedia\directx\dinput\pid\pidinit.c
#define NudgeWorkerThread(thid)                                         \
        PostThreadMessage(thid, WM_NULL, 0x0, (LPARAM)NULL)

// multimedia\directx\dinput\pid\pidreg.c
#define DI_DAC_OWNER (WRITE_DAC | WRITE_OWNER)
#define DI_KEY_ALL_ACCESS (KEY_ALL_ACCESS & ~DI_DAC_OWNER)

// multimedia\directx\dinput\sys\dinput.c
#define IsCtrlDown() \
	(devExt->arbKbdState[DIK_LCONTROL] || devExt->arbKbdState[DIK_RCONTROL])
#define IsAltDown() \
	(devExt->arbKbdState[DIK_LMENU] || devExt->arbKbdState[DIK_RMENU])

// multimedia\directx\dmusic\dmcompos\sjpers.h
#define SP_LETTER   (SP_A | SP_B | SP_C | SP_D | SP_E | SP_F)
#define SP_ROOT     (SP_1 | SP_2 | SP_3 | SP_4 | SP_5 | SP_6 | SP_7)
#define PF_BEATS    ( PF_WHOLE | PF_HALF | PF_QUARTER )
#define PF_RIFF     ( PF_INTRO | PF_BREAK | PF_FILL | PF_END )
#define PF_GROOVE   ( PF_A | PF_B | PF_C | PF_D | PF_E | PF_F | PF_G | PF_H )
#define NEXTCHORD_SIZE  (sizeof(NextChrd)-sizeof(LPNEXTCHRD)-sizeof(LPCHRDENTRY))

// multimedia\directx\dmusic\dmime\dmperf.h
#define IsPlayQueue( dwCount ) ((dwCount >= SQ_PRI_PLAY) && (dwCount <= SQ_SEC_PLAY))

// multimedia\directx\dmusic\dmime\dmsegobj.h
#define COMPOSE_TRANSITION1 (DMUS_TRACKCONFIG_TRANS1_FROMSEGSTART | DMUS_TRACKCONFIG_TRANS1_FROMSEGCURRENT | DMUS_TRACKCONFIG_TRANS1_TOSEGSTART)

// multimedia\directx\dmusic\dmstyle\score.h
#define SP_LETTER   (SP_A | SP_B | SP_C | SP_D | SP_E | SP_F)
#define SP_ROOT     (SP_1 | SP_2 | SP_3 | SP_4 | SP_5 | SP_6 | SP_7)

// multimedia\directx\dmusic\dmstyle\sjdefs.h
#define PF_BEATS    ( PF_WHOLE | PF_HALF | PF_QUARTER )
#define PF_RIFF     ( PF_INTRO | PF_BREAK | PF_FILL | PF_END )
#define PF_GROOVE   ( PF_A | PF_B | PF_C | PF_D | PF_E | PF_F | PF_G | PF_H )

// multimedia\directx\dmusic\dmsynth\miniport.cpp
#define CONST_PCNODE_DESCRIPTOR(n)			{ 0, NULL, &n, NULL }
#define CONST_PCNODE_DESCRIPTOR_AUTO(n,a)	{ 0, &a, &n, NULL }

// multimedia\directx\dmusic\dmsynth\sverb.h
#define CLIP_SHORT_TO_SHORT(x)\
			if (x>32767)\
				x = 32767;\
			else if (x<-32768)\
				x = -32768;

// multimedia\directx\dmusic\dmusic16\dmusic16.h
#define VA_F_EITHER (VA_F_INPUT | VA_F_OUTPUT)

// multimedia\directx\dmusic\dmusic16\midiin.c
#define IS_CHANNEL_MSG(x)     (((x) & 0xF0) != 0xF0)

// multimedia\directx\dmusic\dmusic\dmecport.cpp
#define IS_CHANNEL_MSG(x)     (((x) & 0xF0) != 0xF0)

// multimedia\directx\dmusic\dmusic\dmusicp.h
#define QUEUED_EVENT_SIZE(cbEvent)  (DMUS_EVENT_SIZE(cbEvent) + sizeof(QUEUED_EVENT) - sizeof(DMEVENT))

// multimedia\directx\dmusic\dswave\waveutil.h
#define SIZEOFFORMAT(pwfx)		((WAVE_FORMAT_PCM == pwfx->wFormatTag)? \
								(sizeof(PCMWAVEFORMAT)): \
								(sizeof(WAVEFORMATEX)+pwfx->cbSize))
#define SIZEOFFORMATEX(pwfx)	(sizeof(WAVEFORMATEX) + \
								((WAVE_FORMAT_PCM == pwfx->wFormatTag)?0:pwfx->cbSize))

// multimedia\directx\dmusic\shared\smartref.h
#define NOCOPYANDASSIGN(classname) classname(const classname &o); classname &operator= (const classname &o);

// multimedia\directx\dplay\dnet\common\bilink.h
#define BilinkToList( _pBilink ) \
	(_pBilink)->prev->next=NULL;
#define InitBilink( _pBilink, _pvObject ) \
    (_pBilink)->prev=(_pBilink)->next=(_pBilink); (_pBilink)->pvObject = _pvObject;

// multimedia\directx\dplay\dnet\common\creg.h
#define DPN_KEY_ALL_ACCESS				((KEY_ALL_ACCESS & ~WRITE_DAC) & ~WRITE_OWNER)

// multimedia\directx\dplay\dnet\common\osind.h
#define	DNEnterCriticalSection( arg )	EnterCriticalSection( &((arg)->CriticalSection) )
#define	DNLeaveCriticalSection( arg )	LeaveCriticalSection( &((arg)->CriticalSection) )

// multimedia\directx\dplay\dnet\core\message.h
#define DN_MSG_INTERNAL_PLAYER_CONNECT_INFO				(0x01 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_SEND_CONNECT_INFO				(0x02 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_ACK_CONNECT_INFO				(0x03 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_SEND_PLAYER_DNID				(0x04 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_NAMETABLE_VERSION				(0x09 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_RESYNC_VERSION					(0x0a | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_REQ_NAMETABLE_OP				(0x0b | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_ACK_NAMETABLE_OP				(0x0c | DN_MSG_INTERNAL)
#define DN_MSG_INTERNAL_HOST_MIGRATE					(0x0d | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_HOST_MIGRATE_COMPLETE			(0x0e | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_UPDATE_APPLICATION_DESC			(0x0f | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_ADD_PLAYER						(0x10 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_DESTROY_PLAYER					(0x11 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_REQ_CREATE_GROUP				(0x12 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_REQ_ADD_PLAYER_TO_GROUP			(0x13 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_REQ_DESTROY_GROUP				(0x15 | DN_MSG_INTERNAL)
#define DN_MSG_INTERNAL_REQ_UPDATE_INFO					(0x16 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_CREATE_GROUP					(0x17 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_DESTROY_GROUP					(0x18 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_ADD_PLAYER_TO_GROUP				(0x19 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_UPDATE_INFO						(0x1b | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_VOICE_SEND						(0x1c | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_BUFFER_IN_USE					(0x1d | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_TERMINATE_SESSION				(0x1f | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_REQ_PROCESS_COMPLETION			(0x20 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_PROCESS_COMPLETION				(0x21 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_REQ_INTEGRITY_CHECK				(0x22 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_INTEGRITY_CHECK					(0x23 | DN_MSG_INTERNAL)
#define	DN_MSG_INTERNAL_INTEGRITY_CHECK_RESPONSE		(0x24 | DN_MSG_INTERNAL)

// multimedia\directx\dplay\dnet\inc\dplobby8.h
#define	DPL_MSGID_RECEIVE					(0x0001 | DPL_MSGID_LOBBY)
#define	DPL_MSGID_CONNECT					(0x0002 | DPL_MSGID_LOBBY)
#define DPL_MSGID_DISCONNECT				(0x0003 | DPL_MSGID_LOBBY)
#define DPL_MSGID_CONNECTION_SETTINGS       (0x0005 | DPL_MSGID_LOBBY)

// multimedia\directx\dplay\dnet\lobby\dplobby8int.h
#define DPL_REGISTRY_READ_ACCESS 				(READ_CONTROL | KEY_QUERY_VALUE | KEY_ENUMERATE_SUB_KEYS)

// multimedia\directx\dplay\dnet\lobby\dplprot.h
#define	DPL_MSGID_INTERNAL_DISCONNECT			(0x0001 | DPL_MSGID_INTERNAL)
#define	DPL_MSGID_INTERNAL_CONNECT_REQ			(0x0002 | DPL_MSGID_INTERNAL)
#define	DPL_MSGID_INTERNAL_CONNECT_ACK			(0x0003 | DPL_MSGID_INTERNAL)
#define DPL_MSGID_INTERNAL_IDLE_TIMEOUT         (0x0005 | DPL_MSGID_INTERNAL)
#define DPL_MSGID_INTERNAL_CONNECTION_SETTINGS  (0x0006 | DPL_MSGID_INTERNAL)

// multimedia\directx\dplay\dnet\protocol\receive.cpp
#define MINDATAFRAMESIZE (sizeof(DFRAME))
#define MINCMDFRAMESIZE (MIN(sizeof(CFRAME), sizeof(SACKFRAME8)))

// multimedia\directx\dplay\dnet\sp\serial\dpnmodemlocals.h
#define	MAX_USER_PAYLOAD	( MAX_MESSAGE_SIZE - sizeof( _MESSAGE_HEADER ) )

// multimedia\directx\dplay\dplay\dplay\bilink.h
#define BilinkToList( _pBilink ) \
	(_pBilink)->prev->next=NULL;
#define InitBilink( _pBilink ) \
    (_pBilink)->prev=(_pBilink)->next=(_pBilink);

// multimedia\directx\dplay\dplay\dplay\dpcpl.h
#define FILE_MAP_SIZE sizeof(DP_PERFDATA)

// multimedia\directx\dplay\dplay\dplay\dplay.h
#define DPSEND_SYSMESS              (DPSEND_GUARANTEE|DPSEND_ASYNC)

// multimedia\directx\dplay\dplay\dplay\dpmem.c
#define ENTER_DPMEM() EnterCriticalSection(&gcsMemoryCritSection);
#define LEAVE_DPMEM() LeaveCriticalSection(&gcsMemoryCritSection);

// multimedia\directx\dplay\dplay\dplay\dpmem.h
#define INIT_DPMEM_CSECT() InitializeCriticalSection(&gcsMemoryCritSection);

// multimedia\directx\dplay\dplay\dplay\dpmess.h
#define GET_MESSAGE_SIZE(this,MSG) (this->dwSPHeaderSize + sizeof(MSG))

// multimedia\directx\dplay\dplay\dplay\dpsecure.h
#define DPLAY_SECURITY_CONTEXT_REQ (ISC_REQ_CONFIDENTIALITY | \
                                    ISC_REQ_USE_SESSION_KEY | \
                                    ISC_REQ_REPLAY_DETECT)

// multimedia\directx\dplay\dplay\dplay\handler.c
				#define DPLAYI_PLAYER_LOCALAPPSERVER (DPLAYI_PLAYER_APPSERVER|DPLAYI_PLAYER_PLAYERLOCAL)

// multimedia\directx\dplay\dplay\dplaysvr\dplaysvr.h
#define INIT_DPLAYSVR_CSECT() InitializeCriticalSection(&gcsCritSection);
#define ENTER_DPLAYSVR() EnterCriticalSection(&gcsCritSection),gnCSCount++;
#define ENTER_DPLAYSVR() EnterCriticalSection(&gcsCritSection);
#define LEAVE_DPLAYSVR() LeaveCriticalSection(&gcsCritSection);

// multimedia\directx\dplay\dplay\protocol\bilink.h
#define BilinkToList( _pBilink ) \
	(_pBilink)->prev->next=NULL;
#define InitBilink( _pBilink ) \
    (_pBilink)->prev=(_pBilink)->next=(_pBilink);

// multimedia\directx\dplay\dplay\protocol\protocol.c
	#define ALL_PROTOCOLCAPS	(DPCAPS_SENDPRIORITYSUPPORTED | \
								 DPCAPS_ASYNCSUPPORTED        | \
								 DPCAPS_SENDTIMEOUTSUPPORTED  | \
								 DPCAPS_ASYNCCANCELSUPPORTED  )

// multimedia\directx\dplay\dplay\protocol\protocol.h
#define MAX_SYS_HEADER (sizeof(NACK2)+(128/8)+sizeof(MSG_PROTOCOL))

// multimedia\directx\dplay\dplay\protocol\receive.c
	#define pABT        ((pABT1)(&pData[iEOF]))
	#define pBigABT     ((pABT2)(&pData[iEOF]))
	#define pNACK       ((pNACK1)(&pData[iEOA]))
	#define pBigNACK    ((pNACK2)(&pData[iEOA]))
	#define pCMD        ((pCMD1)(&pData[iEON]))
	#define pBigCMD     ((pCMD2)(&pData[iEON]))

// multimedia\directx\dplay\dplay\serial\bilink.h
#define BilinkToList( _pBilink ) \
	(_pBilink)->prev->next=NULL;
#define InitBilink( _pBilink ) \
    (_pBilink)->prev=(_pBilink)->next=(_pBilink);

// multimedia\directx\dplay\dplay\serial\dpserial.c
#define VERSIONNUMBER		(DPSP_MAJORVERSION | SPMINORVERSION) // version number for service provider
#define MESSAGEHEADERLEN	sizeof(MESSAGEHEADER) // size of message header

// multimedia\directx\dplay\dplay\serial\macros.h
#define INIT_DPSP_CSECT() InitializeCriticalSection(&csMem);

// multimedia\directx\dplay\dplay\wsock\bilink.h
#define BilinkToList( _pBilink ) \
	(_pBilink)->prev->next=NULL;
#define InitBilink( _pBilink ) \
    (_pBilink)->prev=(_pBilink)->next=(_pBilink);

// multimedia\directx\dplay\dplay\wsock\dpsp.h
#define VALID_DPWS_MESSAGE(pMsg) (  VALID_SP_MESSAGE(pMsg) || VALID_HELPER_MESSAGE(pMsg) || \
									VALID_SERVER_MESSAGE(pMsg) || VALID_REUSE_MESSAGE(pMsg) )
#define VALID_DPLAYSVR_MESSAGE(pMsg) (	VALID_SP_MESSAGE(pMsg) || VALID_SERVER_MESSAGE(pMsg) || \
										VALID_REUSE_MESSAGE(pMsg) )
#define VERSIONNUMBER		(DPSP_MAJORVERSION | SPMINORVERSION) // version number for service provider
#define SERVICE_SOCKET(pgd) ( (pgd->AddressFamily == AF_IPX) \
	? pgd->sSystemDGramSocket : pgd->sSystemStreamSocket)
#define SERVICE_SADDR_PUBLIC(pgd)( (pgd->sRsip == INVALID_SOCKET) \
	? (NULL) : (&pgd->saddrpubSystemStreamSocket) )
#define DGRAM_SADDR_RSIP(pgd) ( (pgd->sRsip == INVALID_SOCKET) \
	? (NULL) : (&pgd->saddrpubSystemDGramSocket) )
#define SERVICE_SADDR_PUBLIC(pgd)( (pgd->pINatHelp) \
	? (&pgd->saddrpubSystemStreamSocket):NULL )
#define DGRAM_SADDR_RSIP(pgd) ( (pgd->pINatHelp) \
	? (&pgd->saddrpubSystemDGramSocket):NULL )
#define INIT_DPSP_CSECT() InitializeCriticalSection(&gcsDPSPCritSection);InitializeCriticalSection(&csMem);
#define ENTER_DPSP() EnterCriticalSection(&gcsDPSPCritSection),gCSCount++;
#define LEAVE_DPSP() gCSCount--,LeaveCriticalSection(&gcsDPSPCritSection);
#define ENTER_DPSP() EnterCriticalSection(&gcsDPSPCritSection);
#define LEAVE_DPSP() LeaveCriticalSection(&gcsDPSPCritSection);
#define DGRAM_PSOCKADDR(ppd) ((SOCKADDR *)&(((LPSPPLAYERDATA)ppd)->saddrDatagram))
#define STREAM_PSOCKADDR(ppd) ((SOCKADDR *)&(((LPSPPLAYERDATA)ppd)->saddrStream))
#define AddRefConn(_p) InterlockedIncrement(&((_p)->dwRefCount))

// multimedia\directx\dplay\dplay\wsock\winsock.c
				#define IP_SOCKADDR(a) (((SOCKADDR_IN *)(&a))->sin_addr.s_addr)
				#define IP_SOCKADDR(a) (((SOCKADDR_IN *)(&a))->sin_addr.s_addr)

// multimedia\directx\dplay\dplobby\dplobby\tlhelp32.h
#define TH32CS_SNAPALL	    (TH32CS_SNAPHEAPLIST | TH32CS_SNAPPROCESS | TH32CS_SNAPTHREAD | TH32CS_SNAPMODULE)

// multimedia\directx\dplay\dpnathlp\common\creg.h
#define DPN_KEY_ALL_ACCESS				((KEY_ALL_ACCESS & ~WRITE_DAC) & ~WRITE_OWNER)

// multimedia\directx\dplay\dpnathlp\common\handletracking.cpp
#define IsValidHandle(x) \
	(x != NULL && x != INVALID_HANDLE_VALUE && \
	(x->type == TypeEvent || \
	 x->type == TypeMutex || \
	 x->type == TypeSemaphore || \
	 x->type == TypeFile || \
	 x->type == TypeFileMap || \
	 x->type == TypeThread || \
	 x->type == TypeProcess || \
	 x->type == TypeSpecial))

// multimedia\directx\dplay\dpnathlp\common\osind.h
#define	IsUnicodePlatform (DNGetOSType() == VER_PLATFORM_WIN32_NT || DNGetOSType() == VER_PLATFORM_WIN32_CE)

// multimedia\directx\dplay\dpnathlp\dpnhupnp\dpnhupnpintfobj.h
#define FD_SET(fd, set) do { \
    if (((fd_set FAR *)(set))->fd_count < FD_SETSIZE) \
        ((fd_set FAR *)(set))->fd_array[((fd_set FAR *)(set))->fd_count++]=(fd);\
} while(0)

// multimedia\directx\dplay\dvoice\dxvoice\dvcleng.cpp
#define CLIENT_POOLS_SIZE_MESSAGE           (sizeof(DVPROTOCOLMSG_FULLMESSAGE))

// multimedia\directx\dplay\dvoice\dxvoice\dvcsplay.cpp
#define IsEmpty(x)   (x.next == x.prev && x.next == &x)

// multimedia\directx\dplay\dvoice\dxvoice\dvsereng.cpp
#define SERVER_POOLS_SIZE_MESSAGE       (sizeof(DVPROTOCOLMSG_FULLMESSAGE))

// multimedia\directx\dplay\dvoice\dxvoice\mixserver.cpp
#define IsEmpty(x)   (x.next == x.prev && x.next == &x)

// multimedia\directx\dplay\dvoice\dxvtlib\fdtglob.h
#define InitGlobGuard() 	DNInitializeCriticalSection(&g_csGuard)
#define GlobGuardIn() 		DNEnterCriticalSection(&g_csGuard)
#define GlobGuardOut() 		DNLeaveCriticalSection(&g_csGuard)

// multimedia\directx\dplay\dvoice\inc\dvoice.h
#define DVTRANSPORT_OBJECTTYPE_BOTH         (DVTRANSPORT_OBJECTTYPE_SERVER | DVTRANSPORT_OBJECTTYPE_CLIENT)

// multimedia\directx\dplay\misc\lists.h
#define	LIST_INITIALIZE(root)\
{\
    (root)->Root = 0;\
}
#define	TAIL_QUEUE_INITIALIZE(root)\
{\
    (root)->First = NULL;\
    (root)->Last = &(root)->First;\
}
#define	CIRCLE_QUEUE_INITIALIZE(root,type)\
{   (root)->Last = (type *)(root);\
    (root)->First = (type *)(root);\
}
#define CIRCLE_QUEUE_INSERT_END(root,type,element,field)\
{   (element)->field.Prev = (root)->Last;\
    (element)->field.Next = (type *)(root);\
    if((root)->First != (type *)(root))\
	(root)->Last->field.Next = (element);\
    else\
	(root)->First = (element);\
    (root)->Last = (element);\
}
#define CIRCLE_QUEUE_INSERT_ROOT(root,type,element,field)\
{   (element)->field.Prev = (type *)(root);\
    (element)->field.Next = (root)->First;\
    if ((root)->Last != (void *)(root))\
	(root)->First->field.Prev = (element);\
    else\
	(root)->Last = (element);\
    (root)->First = (element);\
}
#define CIRCLE_QUEUE_INSERT_PREVIOUS(root,current_element,element,field)\
{   (element)->field.Prev = (current_element)->field.Prev;\
    (element)->field.Next = (current_element);\
    if ((current_element)->field.Prev != (void *)(root))\
	(current_element)->field.Prev->field.Next = (element);\
    else\
	(root)->First = (element);\
    (current_element)->field.Prev = (element);\
}
#define CIRCLE_QUEUE_FIRST(root)\
((root)->First == (void *) (root)? 0: (root)->First)
#define CIRCLE_QUEUE_LAST(root)\
((root)->Last == (void *) (root)? 0: (root)->Last)
#define CIRCLE_QUEUE_NEXT(root,element,field)\
((void *) (element)->field.Next == (void *) (root)? 0: (element)->field.Next)
#define CIRCLE_QUEUE_PREVIOUS(root,element,field)\
((element)->field.Prev == (void *) (root)? 0: (element)->field.Prev)

// multimedia\directx\dsound\dsdmo\chorus.cpp
#define GET_PARAM(x,y) \
    if (SUCCEEDED(hr)) { \
        hr = GetParam(x, &mpd); \
        if (SUCCEEDED(hr)) pChorus->y = mpd; \
    }
#define GET_PARAM_LONG(x,y) \
    if (SUCCEEDED(hr)) { \
        hr = GetParam(x, &mpd); \
        if (SUCCEEDED(hr)) pChorus->y = (long)mpd; \
    }

// multimedia\directx\dsound\dsdmo\chorusp.h
#define cALLPASS		((float).61803398875)	// 1-x^2=x.

// multimedia\directx\dsound\dsdmo\compress.cpp
#define GET_PARAM(x,y) \
	if (SUCCEEDED(hr)) { \
		hr = GetParam(x, &mpd);	\
		if (SUCCEEDED(hr)) pCompressor->y = mpd; \
	}

// multimedia\directx\dsound\dsdmo\compressp.h
#define cALLPASS    ((float).61803398875)    // 1-x^2=x.

// multimedia\directx\dsound\dsdmo\distort.cpp
#define GET_PARAM(x,y) \
	if (SUCCEEDED(hr)) { \
		hr = GetParam(x, &mpd);	\
		if (SUCCEEDED(hr)) pDistort->y = mpd; \
	}

// multimedia\directx\dsound\dsdmo\distortp.h
#define cALLPASS		((float).61803398875)	// 1-x^2=x.

// multimedia\directx\dsound\dsdmo\dllmain.cpp
#define GetClassObjectCase(x,t) \
    if (clsid == x) { \
        p = static_cast<IUnknown*> ((IClassFactory*) (new t)); \
    } else
#define DoDMORegister(x)                                                \
         DMORegister(L#x,                                               \
         GUID_DSFX_STANDARD_ ## x,                                      \
         DMOCATEGORY_AUDIO_EFFECT,                                      \
         0, 1, &mt, 1, &mt)
#define DoDMOCaptureRegister(t,w,x,y)                                       \
         DMORegister(L#t,                                               \
         GUID_DSCFX_## w ##_ ## x,                                      \
         y,                                      \
         0, 1, &mt, 1, &mt)

// multimedia\directx\dsound\dsdmo\echo.cpp
#define GET_PARAM(x,y) \
	if (SUCCEEDED(hr)) { \
		hr = GetParam(x, &mpd);	\
		if (SUCCEEDED(hr)) pEcho->y = mpd; \
	}
#define GET_PARAM_LONG(x,y) \
	if (SUCCEEDED(hr)) { \
		hr = GetParam(x, &mpd);	\
		if (SUCCEEDED(hr)) pEcho->y = (long)mpd; \
	}

// multimedia\directx\dsound\dsdmo\echop.h
#define cALLPASS		((float).61803398875)	// 1-x^2=x.

// multimedia\directx\dsound\dsdmo\flanger.cpp
#define GET_PARAM(x,y) \
    if (SUCCEEDED(hr)) { \
        hr = GetParam(x, &mpd);    \
        if (SUCCEEDED(hr)) pFlanger->y = mpd; \
    }
#define GET_PARAM_LONG(x,y) \
    if (SUCCEEDED(hr)) { \
        hr = GetParam(x, &mpd);    \
        if (SUCCEEDED(hr)) pFlanger->y = (long)mpd; \
    }

// multimedia\directx\dsound\dsdmo\flangerp.h
#define cALLPASS		((float).61803398875)	// 1-x^2=x.

// multimedia\directx\dsound\dsdmo\parameq.cpp
#define GET_PARAM(x,y) \
	if (SUCCEEDED(hr)) { \
		hr = GetParam(x, &mpd);	\
		if (SUCCEEDED(hr)) peq->y = mpd; \
	}

// multimedia\directx\dsound\dsdmo\parameqp.h
#define cALLPASS		((float).61803398875)	// 1-x^2=x.

// multimedia\directx\dsound\dsdmo\sverb.h
#define CLIP_SHORT_TO_SHORT(x)\
			if (x>32767)\
				x = 32767;\
			else if (x<-32768)\
				x = -32768;

// multimedia\directx\dsound\dsdmo\sverbdmo.cpp
#define GET_PARAM(x,y) \
    if (SUCCEEDED(hr)) { \
        hr = GetParam(x, &mpd); \
        if (SUCCEEDED(hr)) pwr->y = mpd; \
    }
#define GET_PARAM_LONG(x,y) \
    if (SUCCEEDED(hr)) { \
        hr = GetParam(x, &mpd); \
        if (SUCCEEDED(hr)) pwr->y = (long)mpd; \
    }

// multimedia\directx\dsound\dsound\dsmemmgr.h
#define MEMALLOC_A(type, count) \
            ((type *)MemAlloc(sizeof(type) * (count)))
#define MEMALLOC_A_COPY(type, count, src) \
            ((type *)MemAllocCopy(src, sizeof(type) * (count)))

// multimedia\directx\dsound\dsound\dsvalid.h
#define IsValidHandleValue(h)           ((h) && ((h) != INVALID_HANDLE_VALUE))
#define IS_VALID_INTERFACE(a, b)        ((a) && (b == (a)->m_signature))
#define IS_NULL_GUID(a) \
            (!(a) || CompareMemory(a, &GUID_NULL, sizeof(GUID)))
#define IS_VALID_DS3DLISTENER_DISTANCE_FACTOR(a) \
            (!((a) < DS3D_MINDISTANCEFACTOR || (a) > DS3D_MAXDISTANCEFACTOR))
#define IS_VALID_DS3DLISTENER_DOPPLER_FACTOR(a) \
            (!((a) < DS3D_MINDOPPLERFACTOR || (a) > DS3D_MAXDOPPLERFACTOR))
#define IS_VALID_DS3DLISTENER_ROLLOFF_FACTOR(a) \
            (!((a) < DS3D_MINROLLOFFFACTOR || (a) > DS3D_MAXROLLOFFFACTOR))
#define IS_VALID_DS3DBUFFER_CONE_OUTSIDE_VOLUME(a) \
            (!((a) < DSBVOLUME_MIN || (a) > DSBVOLUME_MAX))
#define IS_VALID_DS3DBUFFER_MAX_DISTANCE(a) \
            ((a) > 0.0f)
#define IS_VALID_DS3DBUFFER_MIN_DISTANCE(a) \
            ((a) > 0.0f)
#define IS_VALID_DS3DBUFFER_MODE(a) \
            (!((a) < DS3DMODE_FIRST || (a) > DS3DMODE_LAST))
#define IS_VALID_DSFULLDUPLEX_MODE(a) \
            (!((a) < DSFULLDUPLEXMODE_FIRST || (a) > DSFULLDUPLEXMODE_LAST))

// multimedia\directx\dsound\dsound\misc.h
#define HRFROMP(p) \
            ((p) ? DS_OK : DSERR_OUTOFMEMORY)
#define ABS(n) \
            ((n) > 0 ? (n) : (-n))

// multimedia\directx\dsound\dsound\synch.h
#define INTERLOCKED_EXCHANGE(a, b) \
            InterlockedExchange((LPLONG)&(a), (LONG)(b))
#define INTERLOCKED_INCREMENT(a) \
            InterlockedIncrement((LPLONG)&(a))
#define INTERLOCKED_DECREMENT(a) \
            InterlockedDecrement((LPLONG)&(a))
#define ENTER_DLL_MUTEX() \
            g_pDllLock->Lock()
#define ENTER_DLL_MUTEX_OR_EVENT(h) \
            g_pDllLock->LockOrEvent(h)
#define LEAVE_DLL_MUTEX() \
            g_pDllLock->Unlock()

// multimedia\directx\dsound\dsound\vxdvad.cpp
#define GetDsPropertyQuick(set, id, data) \
            GetDsProperty(set, id, (LPVOID)(data), sizeof(*(data)))
#define SetDsPropertyQuick(set, id, data) \
            SetDsProperty(set, id, (LPVOID)(data), sizeof(*(data)))

// multimedia\directx\dxdiag\testd3d8.cpp
#define D3DFVF_VERTEX (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1)

// multimedia\directx\dxdiag\testnet.cpp
#define PLAYER_LOCK()                   EnterCriticalSection( &s_csPlayerContext );
#define PLAYER_UNLOCK()                 LeaveCriticalSection( &s_csPlayerContext );

// multimedia\directx\dxg\d3d8\fw\ddcreate.cpp
        #define ENTER_CSDDC() EnterCriticalSection(&ddcCS)
        #define LEAVE_CSDDC() LeaveCriticalSection(&ddcCS)

// multimedia\directx\dxg\d3d8\fw\ddgdi32.c
#define SIZE_OF_A_CLIPLIST(lpRgn) \
        (sizeof(RGNDATAHEADER)+sizeof(RECTL)*lpRgn->rdh.nCount)

// multimedia\directx\dxg\d3d8\fw\ddithunk.h
#define DDHANDLE(x)  \
    (((PDDDEVICEHANDLE)(x))->hDD)
#define IS_SOFTWARE_DRIVER(x)                                       \
    (((PDDDEVICEHANDLE)(x))->pDD != NULL)
#define IS_SURFACE_LOOSABLE(x)                                      \
    (!IS_SOFTWARE_DRIVER_SURFACE(x) &&                              \
    ((((PDDSURFHANDLE)(x))->Pool == D3DPOOL_LOCALVIDMEM) ||        \
    (((PDDSURFHANDLE)(x))->Pool == D3DPOOL_NONLOCALVIDMEM)))

// multimedia\directx\dxg\d3d8\fw\dxcursor.cpp
#define ISOPAQUE(val)   \
    ( 0xFF000000 == (val & 0xFF000000))

// multimedia\directx\dxg\d3d8\inc\d3dfe.hpp
#define __D3DCLIPGB_ALL (__D3DCLIPGB_LEFT | __D3DCLIPGB_RIGHT | \
                         __D3DCLIPGB_TOP | __D3DCLIPGB_BOTTOM)
#define __D3DCS_INGUARDBAND (D3DCS_LEFT | D3DCS_RIGHT | \
                               D3DCS_TOP  | D3DCS_BOTTOM)

// multimedia\directx\dxg\d3d8\inc\fltval.h
#define SAFE_FLOAT_TO_INT(f)	((f) > LONG_MAX	   \
				 ? LONG_MAX				           \
				 : (f) < LONG_MIN			       \
				 ? LONG_MIN				           \
                                 : (int)(f))

// multimedia\directx\dxg\d3d8\inc\lists.hpp
#define LIST_INITIALIZE(root)\
{\
    (root)->Root = 0;\
}
#define TAIL_QUEUE_INITIALIZE(root)\
{\
    (root)->First = NULL;\
    (root)->Last = &(root)->First;\
}
#define CIRCLE_QUEUE_INITIALIZE(root,type)\
{   (root)->Last = (type *)(root);\
    (root)->First = (type *)(root);\
}
#define CIRCLE_QUEUE_INSERT_END(root,type,element,field)\
{   (element)->field.Prev = (root)->Last;\
    (element)->field.Next = (type *)(root);\
    if((root)->First != (type *)(root))\
    (root)->Last->field.Next = (element);\
    else\
    (root)->First = (element);\
    (root)->Last = (element);\
}
#define CIRCLE_QUEUE_INSERT_ROOT(root,type,element,field)\
{   (element)->field.Prev = (type *)(root);\
    (element)->field.Next = (root)->First;\
    if ((root)->Last != (void *)(root))\
    (root)->First->field.Prev = (element);\
    else\
    (root)->Last = (element);\
    (root)->First = (element);\
}
#define CIRCLE_QUEUE_INSERT_PREVIOUS(root,current_element,element,field)\
{   (element)->field.Prev = (current_element)->field.Prev;\
    (element)->field.Next = (current_element);\
    if ((current_element)->field.Prev != (void *)(root))\
    (current_element)->field.Prev->field.Next = (element);\
    else\
    (root)->First = (element);\
    (current_element)->field.Prev = (element);\
}
#define CIRCLE_QUEUE_FIRST(root)\
((root)->First == (void *) (root)? 0: (root)->First)
#define CIRCLE_QUEUE_LAST(root)\
((root)->Last == (void *) (root)? 0: (root)->Last)
#define CIRCLE_QUEUE_NEXT(root,element,field)\
((void *) (element)->field.Next == (void *) (root)? 0: (element)->field.Next)
#define CIRCLE_QUEUE_PREVIOUS(root,element,field)\
((element)->field.Prev == (void *) (root)? 0: (element)->field.Prev)

// multimedia\directx\dxg\d3d8\inc\vshader.hpp
#define D3DVSD_ISLEGACY(ShaderHandle) !(ShaderHandle & D3DFVF_RESERVED0)

// multimedia\directx\dxg\d3d8\shval\psval10.cpp
            #define PREV_READER(_CHAN,_REG) \
                    ((NULL == pRegFile->m_pAccessHistory[_CHAN][_REG].m_pMostRecentReader) ? NULL :\
                    pRegFile->m_pAccessHistory[_CHAN][_REG].m_pMostRecentReader->m_pInst)
    #define PREV_INST_TYPE(_INST) \
                ((_INST && _INST->m_pPrevInst) ? _INST->m_pPrevInst->m_Type : D3DSIO_NOP)
    #define PREV_INST_SRC0_REGNUM(_INST) \
                ((_INST && _INST->m_pPrevInst) ? _INST->m_pPrevInst->m_SrcParam[0].m_RegNum : -1)

// multimedia\directx\dxg\d3d8\shval\psval14.cpp
#define SWIZZLE_XYZZ (D3DVS_X_X | D3DVS_Y_Y | D3DVS_Z_Z | D3DVS_W_Z)
#define SWIZZLE_XYZW (D3DVS_X_X | D3DVS_Y_Y | D3DVS_Z_Z | D3DVS_W_W)
#define SWIZZLE_XYWW (D3DVS_X_X | D3DVS_Y_Y | D3DVS_Z_W | D3DVS_W_W)
            #define PREV_READER(_CHAN,_REG) \
                    ((NULL == pRegFile->m_pAccessHistory[_CHAN][_REG].m_pMostRecentReader) ? NULL :\
                    pRegFile->m_pAccessHistory[_CHAN][_REG].m_pMostRecentReader->m_pInst)

// multimedia\directx\dxg\d3d8\shval\vshdrval.cpp
                #define PREV_READER(_CHAN,_REG) \
                        ((NULL == pRegFile->m_pAccessHistory[_CHAN][_REG].m_pMostRecentReader) ? NULL :\
                        pRegFile->m_pAccessHistory[_CHAN][_REG].m_pMostRecentReader->m_pInst)

// multimedia\directx\dxg\d3d8\tnl\clipper.cpp
#define GET_NEW_CLIP_VERTEX \
&pv->ClipperState.clip_vertices[pv->ClipperState.clip_vertices_used++];

// multimedia\directx\dxg\d3d8\util\d3dflt.h
#define ASFLOAT(i) (*(FLOAT *)&(i))
#define ASINT32(f) (*(INT32 *)&(f))
#define ASUINT32(f) (*(UINT32 *)&(f))
#define FPU_MODE_LOW_PRECISION(uMode) \
    ((uMode) & 0xfcff)
#define FLOAT_EQZ(flt)                  ((ASUINT32(flt) & 0x7fffffff) == 0)
#define FLOAT_NEZ(flt)                  ((ASUINT32(flt) & 0x7fffffff) != 0)

// multimedia\directx\dxg\d3d8\util\d3dutil.cpp
#define MATRIX_PRODUCT(res, a, b)                                           \
res->_11 = a->_11*b->_11 + a->_12*b->_21 + a->_13*b->_31 + a->_14*b->_41;   \
res->_12 = a->_11*b->_12 + a->_12*b->_22 + a->_13*b->_32 + a->_14*b->_42;   \
res->_13 = a->_11*b->_13 + a->_12*b->_23 + a->_13*b->_33 + a->_14*b->_43;   \
res->_14 = a->_11*b->_14 + a->_12*b->_24 + a->_13*b->_34 + a->_14*b->_44;   \
                                                                            \
res->_21 = a->_21*b->_11 + a->_22*b->_21 + a->_23*b->_31 + a->_24*b->_41;   \
res->_22 = a->_21*b->_12 + a->_22*b->_22 + a->_23*b->_32 + a->_24*b->_42;   \
res->_23 = a->_21*b->_13 + a->_22*b->_23 + a->_23*b->_33 + a->_24*b->_43;   \
res->_24 = a->_21*b->_14 + a->_22*b->_24 + a->_23*b->_34 + a->_24*b->_44;   \
                                                                            \
res->_31 = a->_31*b->_11 + a->_32*b->_21 + a->_33*b->_31 + a->_34*b->_41;   \
res->_32 = a->_31*b->_12 + a->_32*b->_22 + a->_33*b->_32 + a->_34*b->_42;   \
res->_33 = a->_31*b->_13 + a->_32*b->_23 + a->_33*b->_33 + a->_34*b->_43;   \
res->_34 = a->_31*b->_14 + a->_32*b->_24 + a->_33*b->_34 + a->_34*b->_44;   \
                                                                            \
res->_41 = a->_41*b->_11 + a->_42*b->_21 + a->_43*b->_31 + a->_44*b->_41;   \
res->_42 = a->_41*b->_12 + a->_42*b->_22 + a->_43*b->_32 + a->_44*b->_42;   \
res->_43 = a->_41*b->_13 + a->_42*b->_23 + a->_43*b->_33 + a->_44*b->_43;   \
res->_44 = a->_41*b->_14 + a->_42*b->_24 + a->_43*b->_34 + a->_44*b->_44;

// multimedia\directx\dxg\d3d8\util\d3dutil.h
#define VecNormalize(Vec)               pVecNormalize(&(Vec))
#define VecNormalize2(Vec, Res)         pVecNormalize2(&(Vec), &(Res))
#define pVecDot(pVec1, pVec2)                                                 \
    ((pVec1)->x * (pVec2)->x + (pVec1)->y * (pVec2)->y +                      \
     (pVec1)->z * (pVec2)->z)
#define pVecAdd(pVec1, pVec2, pRes)                                           \
    ((pRes)->x = (pVec1)->x + (pVec2)->x,                                     \
     (pRes)->y = (pVec1)->y + (pVec2)->y,                                     \
     (pRes)->z = (pVec1)->z + (pVec2)->z)
#define pVecSub(pVec1, pVec2, pRes)                                           \
    ((pRes)->x = (pVec1)->x - (pVec2)->x,                                     \
     (pRes)->y = (pVec1)->y - (pVec2)->y,                                     \
     (pRes)->z = (pVec1)->z - (pVec2)->z)
#define pVecScale(pVec, fScale, pRes)                                         \
    ((pRes)->x = (pVec)->x * (fScale),                                        \
     (pRes)->y = (pVec)->y * (fScale),                                        \
     (pRes)->z = (pVec)->z * (fScale))
#define pVecNeg(pVec, pRes)                                                   \
    ((pRes)->x = NEGF((pVec)->x),                                             \
     (pRes)->y = NEGF((pVec)->y),                                             \
     (pRes)->z = NEGF((pVec)->z))
#define pVecSet(pVec, fX, fY, fZ)                                             \
    ((pVec)->x = (fX), (pVec)->y = (fY), (pVec)->z = (fZ))
#define VecLenSq(Vec)                   pVecLenSq(&(Vec))
#define VecLen(Vec)                     pVecLen(&(Vec))
#define VecNormalizeFast(Vec)          TableVecNormalize((float*)&(Vec), (float*)&(Vec))
#define VecNormalizeFast2(Vec, Res)    TableVecNormalize((float*)&(Res), (float*)&(Vec))
#define VecNormalizeFast(Vec)               pVecNormalize((LPD3DVECTOR)&(Vec))
#define VecNormalizeFast2(Vec, Res)         pVecNormalize2((LPD3DVECTOR)&(Vec), &(Res))
#define VecDot(Vec1, Vec2)              pVecDot(&(Vec1), &(Vec2))
#define VecAdd(Vec1, Vec2, Res)         pVecAdd(&(Vec1), &(Vec2), &(Res))
#define VecSub(Vec1, Vec2, Res)         pVecSub(&(Vec1), &(Vec2), &(Res))
#define VecScale(Vec1, fScale, Res)     pVecScale(&(Vec1), fScale, &(Res))
#define VecNeg(Vec, Res)                pVecNeg(&(Vec), &(Res))
#define VecSet(Vec, fX, fY, fZ)         pVecSet(&(Vec), fX, fY, fZ)

// multimedia\directx\dxg\d3d\dx6\d3dim\d3dcreat.cpp
#define MATCH(cap)      ((matchCaps->cap & primCaps->cap) == matchCaps->cap)

// multimedia\directx\dxg\d3d\dx6\d3dim\dpoldhal.cpp
#define ISCULLED(lpDevI, CullTestRes) ((CullTestRes==0.0) ||   \
                                   ((lpDevI->rstates[D3DRENDERSTATE_CULLMODE]==D3DCULL_CW) ^ (CullTestRes < 0.0)))

// multimedia\directx\dxg\d3d\dx6\d3dim\hwprov.cpp
#define transformCaps { sizeof(D3DTRANSFORMCAPS), D3DTRANSFORMCAPS_CLIP }
#define lightingCaps {                                                  \
        sizeof(D3DLIGHTINGCAPS),                                        \
        (D3DLIGHTCAPS_POINT                                             \
         | D3DLIGHTCAPS_SPOT                                            \
         | D3DLIGHTCAPS_DIRECTIONAL                                     \
         | D3DLIGHTCAPS_PARALLELPOINT),                                 \
        THIS_MODEL,                     /* dwLightingModel */           \
        0,                              /* dwNumLights (infinite) */    \
}

// multimedia\directx\dxg\d3d\dx6\d3dim\inc\d3dpr.hpp
#define ENTER_CBCSECT(device) EnterCriticalSection(&(device)->CommandBufferCSect)
#define LEAVE_CBCSECT(device) LeaveCriticalSection(&(device)->CommandBufferCSect)
#define D3DFINDDEVICERESULTSIZE_V1 (sizeof(D3DFINDDEVICERESULT)-2*(D3DDEVICEDESCSIZE-D3DDEVICEDESCSIZE_V1) )
#define D3DFINDDEVICERESULTSIZE_V2 (sizeof(D3DFINDDEVICERESULT)-2*(D3DDEVICEDESCSIZE-D3DDEVICEDESCSIZE_V2) )

// multimedia\directx\dxg\d3d\dx6\d3dim\inc\lists.hpp
#define LIST_INITIALIZE(root)\
{\
    (root)->Root = 0;\
}
#define TAIL_QUEUE_INITIALIZE(root)\
{\
    (root)->First = NULL;\
    (root)->Last = &(root)->First;\
}
#define CIRCLE_QUEUE_INITIALIZE(root,type)\
{   (root)->Last = (type *)(root);\
    (root)->First = (type *)(root);\
}
#define CIRCLE_QUEUE_INSERT_END(root,type,element,field)\
{   (element)->field.Prev = (root)->Last;\
    (element)->field.Next = (type *)(root);\
    if((root)->First != (type *)(root))\
    (root)->Last->field.Next = (element);\
    else\
    (root)->First = (element);\
    (root)->Last = (element);\
}
#define CIRCLE_QUEUE_INSERT_ROOT(root,type,element,field)\
{   (element)->field.Prev = (type *)(root);\
    (element)->field.Next = (root)->First;\
    if ((root)->Last != (void *)(root))\
    (root)->First->field.Prev = (element);\
    else\
    (root)->Last = (element);\
    (root)->First = (element);\
}
#define CIRCLE_QUEUE_INSERT_PREVIOUS(root,current_element,element,field)\
{   (element)->field.Prev = (current_element)->field.Prev;\
    (element)->field.Next = (current_element);\
    if ((current_element)->field.Prev != (void *)(root))\
    (current_element)->field.Prev->field.Next = (element);\
    else\
    (root)->First = (element);\
    (current_element)->field.Prev = (element);\
}
#define CIRCLE_QUEUE_FIRST(root)\
((root)->First == (void *) (root)? 0: (root)->First)
#define CIRCLE_QUEUE_LAST(root)\
((root)->Last == (void *) (root)? 0: (root)->Last)
#define CIRCLE_QUEUE_NEXT(root,element,field)\
((void *) (element)->field.Next == (void *) (root)? 0: (element)->field.Next)
#define CIRCLE_QUEUE_PREVIOUS(root,element,field)\
((element)->field.Prev == (void *) (root)? 0: (element)->field.Prev)

// multimedia\directx\dxg\d3d\dx6\d3dutil\d3dflt.h
#define ASFLOAT(i) (*(FLOAT *)&(i))
#define ASINT32(f) (*(INT32 *)&(f))
#define ASUINT32(f) (*(UINT32 *)&(f))
#define FPU_MODE_LOW_PRECISION(uMode) \
    ((uMode) & 0xfcff)
#define FLOAT_EQZ(flt)                  ((ASUINT32(flt) & 0x7fffffff) == 0)
#define FLOAT_NEZ(flt)                  ((ASUINT32(flt) & 0x7fffffff) != 0)

// multimedia\directx\dxg\d3d\dx6\d3dutil\d3dutil.h
#define VecNormalize(Vec)               pVecNormalize(&(Vec))
#define VecNormalize2(Vec, Res)         pVecNormalize2(&(Vec), &(Res))
#define pVecDot(pVec1, pVec2)                                                 \
    ((pVec1)->x * (pVec2)->x + (pVec1)->y * (pVec2)->y +                      \
     (pVec1)->z * (pVec2)->z)
#define pVecAdd(pVec1, pVec2, pRes)                                           \
    ((pRes)->x = (pVec1)->x + (pVec2)->x,                                     \
     (pRes)->y = (pVec1)->y + (pVec2)->y,                                     \
     (pRes)->z = (pVec1)->z + (pVec2)->z)
#define pVecSub(pVec1, pVec2, pRes)                                           \
    ((pRes)->x = (pVec1)->x - (pVec2)->x,                                     \
     (pRes)->y = (pVec1)->y - (pVec2)->y,                                     \
     (pRes)->z = (pVec1)->z - (pVec2)->z)
#define pVecScale(pVec, fScale, pRes)                                         \
    ((pRes)->x = (pVec)->x * (fScale),                                        \
     (pRes)->y = (pVec)->y * (fScale),                                        \
     (pRes)->z = (pVec)->z * (fScale))
#define pVecNeg(pVec, pRes)                                                   \
    ((pRes)->x = NEGF((pVec)->x),                                             \
     (pRes)->y = NEGF((pVec)->y),                                             \
     (pRes)->z = NEGF((pVec)->z))
#define pVecSet(pVec, fX, fY, fZ)                                             \
    ((pVec)->x = (fX), (pVec)->y = (fY), (pVec)->z = (fZ))
#define VecLenSq(Vec)                   pVecLenSq(&(Vec))
#define VecLen(Vec)                     pVecLen(&(Vec))
#define VecNormalizeFast(Vec)          TableVecNormalize((float*)&(Vec), (float*)&(Vec))
#define VecNormalizeFast2(Vec, Res)    TableVecNormalize((float*)&(Res), (float*)&(Vec))
#define VecNormalizeFast(Vec)               pVecNormalize(&(Vec))
#define VecNormalizeFast2(Vec, Res)         pVecNormalize2(&(Vec), &(Res))
#define VecDot(Vec1, Vec2)              pVecDot(&(Vec1), &(Vec2))
#define VecAdd(Vec1, Vec2, Res)         pVecAdd(&(Vec1), &(Vec2), &(Res))
#define VecSub(Vec1, Vec2, Res)         pVecSub(&(Vec1), &(Vec2), &(Res))
#define VecScale(Vec1, fScale, Res)     pVecScale(&(Vec1), fScale, &(Res))
#define VecNeg(Vec, Res)                pVecNeg(&(Vec), &(Res))
#define VecSet(Vec, fX, fY, fZ)         pVecSet(&(Vec), fX, fY, fZ)

// multimedia\directx\dxg\d3d\dx6\inc\fltval.h
#define SAFE_FLOAT_TO_INT(f)	((f) > LONG_MAX	   \
				 ? LONG_MAX				           \
				 : (f) < LONG_MIN			       \
				 ? LONG_MIN				           \
                                 : (int)(f))

// multimedia\directx\dxg\d3d\dx6\inc\haldrv.hpp
#define SURFACE_MEMORY(surf) \
(LPVOID)(((LPDDRAWI_DDRAWSURFACE_INT)(surf))->lpLcl->lpGbl->fpVidMem)
#define CALL_HAL3ONLY_OPTIONAL(ret, lpDevI, call, data)                 \
{                                                                       \
    BOOL locked;                                                        \
    ret = DD_OK;                                                        \
    if (lpDevI->lpD3DHALCallbacks3->call)                               \
    {                                                                   \
        CALL_HAL3ONLY(ret, lpDevI, call, data);                         \
    }                                                                   \
}

// multimedia\directx\dxg\d3d\dx6\pipeln\clipper.cpp
#define GET_NEW_CLIP_VERTEX \
&pv->ClipperState.clip_vertices[pv->ClipperState.clip_vertices_used++];

// multimedia\directx\dxg\d3d\dx6\pipeln\helxfrm.cpp
#define MATRIX_PRODUCT(res, a, b)                                           \
res->_11 = a->_11*b->_11 + a->_12*b->_21 + a->_13*b->_31 + a->_14*b->_41;   \
res->_12 = a->_11*b->_12 + a->_12*b->_22 + a->_13*b->_32 + a->_14*b->_42;   \
res->_13 = a->_11*b->_13 + a->_12*b->_23 + a->_13*b->_33 + a->_14*b->_43;   \
res->_14 = a->_11*b->_14 + a->_12*b->_24 + a->_13*b->_34 + a->_14*b->_44;   \
                                                                            \
res->_21 = a->_21*b->_11 + a->_22*b->_21 + a->_23*b->_31 + a->_24*b->_41;   \
res->_22 = a->_21*b->_12 + a->_22*b->_22 + a->_23*b->_32 + a->_24*b->_42;   \
res->_23 = a->_21*b->_13 + a->_22*b->_23 + a->_23*b->_33 + a->_24*b->_43;   \
res->_24 = a->_21*b->_14 + a->_22*b->_24 + a->_23*b->_34 + a->_24*b->_44;   \
                                                                            \
res->_31 = a->_31*b->_11 + a->_32*b->_21 + a->_33*b->_31 + a->_34*b->_41;   \
res->_32 = a->_31*b->_12 + a->_32*b->_22 + a->_33*b->_32 + a->_34*b->_42;   \
res->_33 = a->_31*b->_13 + a->_32*b->_23 + a->_33*b->_33 + a->_34*b->_43;   \
res->_34 = a->_31*b->_14 + a->_32*b->_24 + a->_33*b->_34 + a->_34*b->_44;   \
                                                                            \
res->_41 = a->_41*b->_11 + a->_42*b->_21 + a->_43*b->_31 + a->_44*b->_41;   \
res->_42 = a->_41*b->_12 + a->_42*b->_22 + a->_43*b->_32 + a->_44*b->_42;   \
res->_43 = a->_41*b->_13 + a->_42*b->_23 + a->_43*b->_33 + a->_44*b->_43;   \
res->_44 = a->_41*b->_14 + a->_42*b->_24 + a->_43*b->_34 + a->_44*b->_44;

// multimedia\directx\dxg\d3d\dx6\pipeln\inc\clipper.h
#define CLIPPED_ALL (CLIPPED_LEFT|CLIPPED_RIGHT     \
             |CLIPPED_TOP|CLIPPED_BOTTOM            \
             |CLIPPED_FRONT|CLIPPED_BACK)
#define __D3DCLIPGB_ALL (__D3DCLIPGB_LEFT | __D3DCLIPGB_RIGHT | \
                         __D3DCLIPGB_TOP | __D3DCLIPGB_BOTTOM)
#define __D3DCLIP_INGUARDBAND (D3DCLIP_LEFT | D3DCLIP_RIGHT | \
                               D3DCLIP_TOP  | D3DCLIP_BOTTOM)

// multimedia\directx\dxg\d3d\dx6\rast\d3dif\d3dif.hpp
#define SURFACE_LOCKED(pDDS) \
    (((LPDDRAWI_DDRAWSURFACE_INT)(pDDS))->lpLcl->lpGbl->dwUsageCount > 0)

// multimedia\directx\dxg\d3d\dx6\rast\d3dif\getcaps.h
#define transformCaps { sizeof(D3DTRANSFORMCAPS), D3DTRANSFORMCAPS_CLIP }
#define lightingCaps {							\
	sizeof(D3DLIGHTINGCAPS),					\
	D3DLIGHTCAPS_POINT |						\
	    D3DLIGHTCAPS_SPOT |						\
	    D3DLIGHTCAPS_DIRECTIONAL |					\
	    D3DLIGHTCAPS_PARALLELPOINT,		 			\
	THIS_MODEL,			/* dwLightingModel */		\
	0,				/* dwNumLights (infinite) */	\
}
#define triCaps {					\
    sizeof(D3DPRIMCAPS),				\
    D3DPMISCCAPS_CULLCCW | D3DPMISCCAPS_CULLCW | D3DPMISCCAPS_CULLNONE,	/* miscCaps */		\
    TRIRASTERCAPS,		/* rasterCaps */	\
    D3DPCMPCAPS_NEVER | D3DPCMPCAPS_LESS | D3DPCMPCAPS_EQUAL | D3DPCMPCAPS_LESSEQUAL | D3DPCMPCAPS_GREATER | D3DPCMPCAPS_NOTEQUAL | D3DPCMPCAPS_GREATEREQUAL | D3DPCMPCAPS_ALWAYS,	/* zCmpCaps */		\
    0,				/* sourceBlendCaps */	\
    0,				/* destBlendCaps */	\
    0,				/* alphaBlendCaps */	\
    TRISHADECAPS,		/* shadeCaps */		\
    D3DPTEXTURECAPS_PERSPECTIVE |/* textureCaps */	\
	D3DPTEXTURECAPS_POW2 |				\
	D3DPTEXTURECAPS_TRANSPARENCY,			\
    TRIFILTERCAPS,		/* textureFilterCaps */ \
    D3DPTBLENDCAPS_COPY |	/* textureBlendCaps */	\
	D3DPTBLENDCAPS_MODULATE,			\
    D3DPTADDRESSCAPS_WRAP,	/* textureAddressCaps */\
    4,				/* stippleWidth */	\
    4				/* stippleHeight */	\
}							\

// multimedia\directx\dxg\d3d\dx6\rast\inc\lists.h
#define	LIST_INITIALIZE(root)\
{\
    (root)->Root = 0;\
}
#define	TAIL_QUEUE_INITIALIZE(root)\
{\
    (root)->First = NULL;\
    (root)->Last = &(root)->First;\
}
#define	CIRCLE_QUEUE_INITIALIZE(root,type)\
{   (root)->Last = (type *)(root);\
    (root)->First = (type *)(root);\
}
#define CIRCLE_QUEUE_INSERT_END(root,type,element,field)\
{   (element)->field.Prev = (root)->Last;\
    (element)->field.Next = (type *)(root);\
    if((root)->First != (type *)(root))\
	(root)->Last->field.Next = (element);\
    else\
	(root)->First = (element);\
    (root)->Last = (element);\
}
#define CIRCLE_QUEUE_INSERT_ROOT(root,type,element,field)\
{   (element)->field.Prev = (type *)(root);\
    (element)->field.Next = (root)->First;\
    if ((root)->Last != (void *)(root))\
	(root)->First->field.Prev = (element);\
    else\
	(root)->Last = (element);\
    (root)->First = (element);\
}
#define CIRCLE_QUEUE_INSERT_PREVIOUS(root,current_element,element,field)\
{   (element)->field.Prev = (current_element)->field.Prev;\
    (element)->field.Next = (current_element);\
    if ((current_element)->field.Prev != (void *)(root))\
	(current_element)->field.Prev->field.Next = (element);\
    else\
	(root)->First = (element);\
    (current_element)->field.Prev = (element);\
}
#define CIRCLE_QUEUE_FIRST(root)\
((root)->First == (void *) (root)? 0: (root)->First)
#define CIRCLE_QUEUE_LAST(root)\
((root)->Last == (void *) (root)? 0: (root)->Last)
#define CIRCLE_QUEUE_NEXT(root,element,field)\
((void *) (element)->field.Next == (void *) (root)? 0: (element)->field.Next)
#define CIRCLE_QUEUE_PREVIOUS(root,element,field)\
((element)->field.Prev == (void *) (root)? 0: (element)->field.Prev)

// multimedia\directx\dxg\d3d\dx6\rast\inc\setup.hpp
#define ComputeIntCarry(fV, fDVDS, pICY)                                      \
    ((pICY)->iFrac = (SCALED_FRACTION((fV) - FLOORF(fV)) - 1) & 0x7fffffff,   \
     (pICY)->iNC = FTOI(fDVDS),                                               \
     (pICY)->iDFrac = SCALED_FRACTION((fDVDS) - (pICY)->iNC),                 \
     (pICY)->iCY = FLOAT_LTZ(fDVDS) ? (pICY)->iNC - 1 : (pICY)->iNC + 1)
#define COMMIT_PRIM(bClearAll)                                                \
{                                                                             \
    m_pCur = (PUINT8)(m_StpCtx.pPrim + 1);                                    \
                                                                              \
    if (m_pOldPrim != NULL)                                                   \
    {                                                                         \
        m_pOldPrim->pNext = m_StpCtx.pPrim;                                   \
    }                                                                         \
    m_pOldPrim = m_StpCtx.pPrim;                                              \
                                                                              \
    if (bClearAll)                                                            \
    {                                                                         \
        memset(m_StpCtx.pPrim, 0, sizeof(*m_StpCtx.pPrim));                   \
    }                                                                         \
    else                                                                      \
    {                                                                         \
        m_StpCtx.pPrim->uSpans = 0;                                           \
        m_StpCtx.pPrim->pNext = NULL;                                         \
    }                                                                         \
}
#define ALLOC_SPANS(pStpCtx, pcSpans, ppSpan) \
    ((PrimProcessor *)pStpCtx->PrimProcessor)->AllocSpans(pcSpans, ppSpan)

// multimedia\directx\dxg\d3d\dx6\rast\rampold\dditypes.h
#define CI_GET_FRACTION(ci)	((ci) & 0xff)
#define PIXMAP_POS(pm, x, y)	(void RLFAR*)((char RLFAR*)		\
					      PIXMAP_LINE(pm, y)	\
					      + (x) * (pm)->depth / 8)

// multimedia\directx\dxg\d3d\dx6\rast\rampold\driver.h
#define RLDDIService(stackp, type, arg1, arg2) \
    (*((stackp)->fastService[type].call)) \
    ((stackp)->fastService[type].driver, (type), (arg1), (arg2))

// multimedia\directx\dxg\d3d\dx6\rast\rampold\fltval.h
#define SAFE_FLOAT_TO_INT(f)	((f) > LONG_MAX				      \
				 ? LONG_MAX				      \
				 : (f) < LONG_MIN			      \
				 ? LONG_MIN				      \
				 : (RLDDIFixed)(f))

// multimedia\directx\dxg\d3d\dx6\rast\setup\buffer.cpp
#define AVOID_FLUSH_SPACE (8 * sizeof(D3DI_RASTSPAN))

// multimedia\directx\dxg\d3d\dx6\rast\setup\lstp.cpp
#define NEEDS_NORMALIZE2(fV0, fV1) \
    ((ASUINT32(fV0) | ASUINT32(fV1)) > INT32_FLOAT_ONE)
#define LINEDIR_CMP( _A, _B ) \
    ( bLineMajorNeg ? ( (_A) > (_B) ) : ( (_A) < (_B) ) )

// multimedia\directx\dxg\d3d\dx6\rast\setup\point.cpp
#define NEEDS_NORMALIZE1(fV0) \
    (ASUINT32(fV0) > INT32_FLOAT_ONE)

// multimedia\directx\dxg\d3d\dx7\fe\d3dpr.hpp
#define ENTER_CBCSECT(device) EnterCriticalSection(&(device)->CommandBufferCSect)
#define LEAVE_CBCSECT(device) LeaveCriticalSection(&(device)->CommandBufferCSect)

// multimedia\directx\dxg\d3d\dx7\fe\dpoldhal.cpp
#define ISCULLED(lpDevI, CullTestRes) ((CullTestRes==0.0) ||   \
                                   ((lpDevI->rstates[D3DRENDERSTATE_CULLMODE]==D3DCULL_CW) ^ (CullTestRes < 0.0)))

// multimedia\directx\dxg\d3d\dx7\fe\hwprov.cpp
#define transformCaps { sizeof(D3DTRANSFORMCAPS), D3DTRANSFORMCAPS_CLIP }
#define lightingCaps {                                                  \
        sizeof(D3DLIGHTINGCAPS),                                        \
        (D3DLIGHTCAPS_POINT                                             \
         | D3DLIGHTCAPS_SPOT                                            \
         | D3DLIGHTCAPS_DIRECTIONAL),                                   \
        THIS_MODEL,                     /* dwLightingModel */           \
        0,                              /* dwNumLights (infinite) */    \
}

// multimedia\directx\dxg\d3d\dx7\fe\lists.hpp
#define LIST_INITIALIZE(root)\
{\
    (root)->Root = 0;\
}
#define TAIL_QUEUE_INITIALIZE(root)\
{\
    (root)->First = NULL;\
    (root)->Last = &(root)->First;\
}
#define CIRCLE_QUEUE_INITIALIZE(root,type)\
{   (root)->Last = (type *)(root);\
    (root)->First = (type *)(root);\
}
#define CIRCLE_QUEUE_INSERT_END(root,type,element,field)\
{   (element)->field.Prev = (root)->Last;\
    (element)->field.Next = (type *)(root);\
    if((root)->First != (type *)(root))\
    (root)->Last->field.Next = (element);\
    else\
    (root)->First = (element);\
    (root)->Last = (element);\
}
#define CIRCLE_QUEUE_INSERT_ROOT(root,type,element,field)\
{   (element)->field.Prev = (type *)(root);\
    (element)->field.Next = (root)->First;\
    if ((root)->Last != (void *)(root))\
    (root)->First->field.Prev = (element);\
    else\
    (root)->Last = (element);\
    (root)->First = (element);\
}
#define CIRCLE_QUEUE_INSERT_PREVIOUS(root,current_element,element,field)\
{   (element)->field.Prev = (current_element)->field.Prev;\
    (element)->field.Next = (current_element);\
    if ((current_element)->field.Prev != (void *)(root))\
    (current_element)->field.Prev->field.Next = (element);\
    else\
    (root)->First = (element);\
    (current_element)->field.Prev = (element);\
}
#define CIRCLE_QUEUE_FIRST(root)\
((root)->First == (void *) (root)? 0: (root)->First)
#define CIRCLE_QUEUE_LAST(root)\
((root)->Last == (void *) (root)? 0: (root)->Last)
#define CIRCLE_QUEUE_NEXT(root,element,field)\
((void *) (element)->field.Next == (void *) (root)? 0: (element)->field.Next)
#define CIRCLE_QUEUE_PREVIOUS(root,element,field)\
((element)->field.Prev == (void *) (root)? 0: (element)->field.Prev)

// multimedia\directx\dxg\d3d\dx7\inc\d3dfe.hpp
#define __D3DCLIPGB_ALL (__D3DCLIPGB_LEFT | __D3DCLIPGB_RIGHT | \
                         __D3DCLIPGB_TOP | __D3DCLIPGB_BOTTOM)
#define __D3DCLIP_INGUARDBAND (D3DCLIP_LEFT | D3DCLIP_RIGHT | \
                               D3DCLIP_TOP  | D3DCLIP_BOTTOM)

// multimedia\directx\dxg\d3d\dx7\inc\fltval.h
#define SAFE_FLOAT_TO_INT(f)	((f) > LONG_MAX	   \
				 ? LONG_MAX				           \
				 : (f) < LONG_MIN			       \
				 ? LONG_MIN				           \
                                 : (int)(f))

// multimedia\directx\dxg\d3d\dx7\inc\haldrv.hpp
#define SURFACE_MEMORY(surf) \
(LPVOID)(((LPDDRAWI_DDRAWSURFACE_INT)(surf))->lpLcl->lpGbl->fpVidMem)
#define CALL_HAL3ONLY_OPTIONAL(ret, lpDevI, call, data)                 \
{                                                                       \
    BOOL locked;                                                        \
    ret = DD_OK;                                                        \
    if (lpDevI->lpD3DHALCallbacks3->call)                               \
    {                                                                   \
        CALL_HAL3ONLY(ret, lpDevI, call, data);                         \
    }                                                                   \
}

// multimedia\directx\dxg\d3d\dx7\rast\d3dif\d3dif.hpp
#define SURFACE_LOCKED(pDDS) \
    (((LPDDRAWI_DDRAWSURFACE_INT)(pDDS))->lpLcl->lpGbl->dwUsageCount > 0)

// multimedia\directx\dxg\d3d\dx7\rast\inc\setup.hpp
#define ComputeIntCarry(fV, fDVDS, pICY)                                      \
    ((pICY)->iFrac = (SCALED_FRACTION((fV) - FLOORF(fV)) - 1) & 0x7fffffff,   \
     (pICY)->iNC = FTOI(fDVDS),                                               \
     (pICY)->iDFrac = SCALED_FRACTION((fDVDS) - (pICY)->iNC),                 \
     (pICY)->iCY = FLOAT_LTZ(fDVDS) ? (pICY)->iNC - 1 : (pICY)->iNC + 1)
#define COMMIT_PRIM(bClearAll)                                                \
{                                                                             \
    m_pCur = (PUINT8)(m_StpCtx.pPrim + 1);                                    \
                                                                              \
    if (m_pOldPrim != NULL)                                                   \
    {                                                                         \
        m_pOldPrim->pNext = m_StpCtx.pPrim;                                   \
    }                                                                         \
    m_pOldPrim = m_StpCtx.pPrim;                                              \
                                                                              \
    if (bClearAll)                                                            \
    {                                                                         \
        memset(m_StpCtx.pPrim, 0, sizeof(*m_StpCtx.pPrim));                   \
    }                                                                         \
    else                                                                      \
    {                                                                         \
        m_StpCtx.pPrim->uSpans = 0;                                           \
        m_StpCtx.pPrim->pNext = NULL;                                         \
    }                                                                         \
}
#define ALLOC_SPANS(pStpCtx, pcSpans, ppSpan) \
    ((PrimProcessor *)pStpCtx->PrimProcessor)->AllocSpans(pcSpans, ppSpan)

// multimedia\directx\dxg\d3d\dx7\rast\setup\buffer.cpp
#define AVOID_FLUSH_SPACE (8 * sizeof(D3DI_RASTSPAN))

// multimedia\directx\dxg\d3d\dx7\rast\setup\lstp.cpp
#define NEEDS_NORMALIZE2(fV0, fV1) \
    ((ASUINT32(fV0) | ASUINT32(fV1)) > INT32_FLOAT_ONE)
#define LINEDIR_CMP( _A, _B ) \
    ( bLineMajorNeg ? ( (_A) > (_B) ) : ( (_A) < (_B) ) )

// multimedia\directx\dxg\d3d\dx7\rast\setup\point.cpp
#define NEEDS_NORMALIZE1(fV0) \
    (ASUINT32(fV0) > INT32_FLOAT_ONE)

// multimedia\directx\dxg\d3d\dx7\tnl\clipper.cpp
#define GET_NEW_CLIP_VERTEX \
&pv->ClipperState.clip_vertices[pv->ClipperState.clip_vertices_used++];

// multimedia\directx\dxg\d3d\dx7\tnl\helxfrm.cpp
#define MATRIX_PRODUCT(res, a, b)                                           \
res->_11 = a->_11*b->_11 + a->_12*b->_21 + a->_13*b->_31 + a->_14*b->_41;   \
res->_12 = a->_11*b->_12 + a->_12*b->_22 + a->_13*b->_32 + a->_14*b->_42;   \
res->_13 = a->_11*b->_13 + a->_12*b->_23 + a->_13*b->_33 + a->_14*b->_43;   \
res->_14 = a->_11*b->_14 + a->_12*b->_24 + a->_13*b->_34 + a->_14*b->_44;   \
                                                                            \
res->_21 = a->_21*b->_11 + a->_22*b->_21 + a->_23*b->_31 + a->_24*b->_41;   \
res->_22 = a->_21*b->_12 + a->_22*b->_22 + a->_23*b->_32 + a->_24*b->_42;   \
res->_23 = a->_21*b->_13 + a->_22*b->_23 + a->_23*b->_33 + a->_24*b->_43;   \
res->_24 = a->_21*b->_14 + a->_22*b->_24 + a->_23*b->_34 + a->_24*b->_44;   \
                                                                            \
res->_31 = a->_31*b->_11 + a->_32*b->_21 + a->_33*b->_31 + a->_34*b->_41;   \
res->_32 = a->_31*b->_12 + a->_32*b->_22 + a->_33*b->_32 + a->_34*b->_42;   \
res->_33 = a->_31*b->_13 + a->_32*b->_23 + a->_33*b->_33 + a->_34*b->_43;   \
res->_34 = a->_31*b->_14 + a->_32*b->_24 + a->_33*b->_34 + a->_34*b->_44;   \
                                                                            \
res->_41 = a->_41*b->_11 + a->_42*b->_21 + a->_43*b->_31 + a->_44*b->_41;   \
res->_42 = a->_41*b->_12 + a->_42*b->_22 + a->_43*b->_32 + a->_44*b->_42;   \
res->_43 = a->_41*b->_13 + a->_42*b->_23 + a->_43*b->_33 + a->_44*b->_43;   \
res->_44 = a->_41*b->_14 + a->_42*b->_24 + a->_43*b->_34 + a->_44*b->_44;

// multimedia\directx\dxg\d3d\dx7\util\d3dflt.h
#define ASFLOAT(i) (*(FLOAT *)&(i))
#define ASINT32(f) (*(INT32 *)&(f))
#define ASUINT32(f) (*(UINT32 *)&(f))
#define FPU_MODE_LOW_PRECISION(uMode) \
    ((uMode) & 0xfcff)
#define FLOAT_EQZ(flt)                  ((ASUINT32(flt) & 0x7fffffff) == 0)
#define FLOAT_NEZ(flt)                  ((ASUINT32(flt) & 0x7fffffff) != 0)

// multimedia\directx\dxg\d3d\dx7\util\d3dutil.h
#define VecNormalize(Vec)               pVecNormalize(&(Vec))
#define VecNormalize2(Vec, Res)         pVecNormalize2(&(Vec), &(Res))
#define pVecDot(pVec1, pVec2)                                                 \
    ((pVec1)->x * (pVec2)->x + (pVec1)->y * (pVec2)->y +                      \
     (pVec1)->z * (pVec2)->z)
#define pVecAdd(pVec1, pVec2, pRes)                                           \
    ((pRes)->x = (pVec1)->x + (pVec2)->x,                                     \
     (pRes)->y = (pVec1)->y + (pVec2)->y,                                     \
     (pRes)->z = (pVec1)->z + (pVec2)->z)
#define pVecSub(pVec1, pVec2, pRes)                                           \
    ((pRes)->x = (pVec1)->x - (pVec2)->x,                                     \
     (pRes)->y = (pVec1)->y - (pVec2)->y,                                     \
     (pRes)->z = (pVec1)->z - (pVec2)->z)
#define pVecScale(pVec, fScale, pRes)                                         \
    ((pRes)->x = (pVec)->x * (fScale),                                        \
     (pRes)->y = (pVec)->y * (fScale),                                        \
     (pRes)->z = (pVec)->z * (fScale))
#define pVecNeg(pVec, pRes)                                                   \
    ((pRes)->x = NEGF((pVec)->x),                                             \
     (pRes)->y = NEGF((pVec)->y),                                             \
     (pRes)->z = NEGF((pVec)->z))
#define pVecSet(pVec, fX, fY, fZ)                                             \
    ((pVec)->x = (fX), (pVec)->y = (fY), (pVec)->z = (fZ))
#define VecLenSq(Vec)                   pVecLenSq(&(Vec))
#define VecLen(Vec)                     pVecLen(&(Vec))
#define VecNormalizeFast(Vec)          TableVecNormalize((float*)&(Vec), (float*)&(Vec))
#define VecNormalizeFast2(Vec, Res)    TableVecNormalize((float*)&(Res), (float*)&(Vec))
#define VecNormalizeFast(Vec)               pVecNormalize((LPD3DVECTOR)&(Vec))
#define VecNormalizeFast2(Vec, Res)         pVecNormalize2((LPD3DVECTOR)&(Vec), &(Res))
#define VecDot(Vec1, Vec2)              pVecDot(&(Vec1), &(Vec2))
#define VecAdd(Vec1, Vec2, Res)         pVecAdd(&(Vec1), &(Vec2), &(Res))
#define VecSub(Vec1, Vec2, Res)         pVecSub(&(Vec1), &(Vec2), &(Res))
#define VecScale(Vec1, fScale, Res)     pVecScale(&(Vec1), fScale, &(Res))
#define VecNeg(Vec, Res)                pVecNeg(&(Vec), &(Res))
#define VecSet(Vec, fX, fY, fZ)         pVecSet(&(Vec), fX, fY, fZ)

// multimedia\directx\dxg\d3d\ref\inc\reftnl.hpp
#define RRPV_DIRTY_XFORM       (RRPV_DIRTY_PROJXFM   | \
                                RRPV_DIRTY_VIEWXFM   | \
                                RRPV_DIRTY_VIEWRECT  | \
                                RRPV_DIRTY_WORLDXFM  | \
                                RRPV_DIRTY_WORLD1XFM | \
                                RRPV_DIRTY_WORLD2XFM | \
                                RRPV_DIRTY_WORLD3XFM | \
                                RRPV_DIRTY_ZRANGE)

// multimedia\directx\dxg\d3d\ref\inc\rrutil.hpp
#define AS_FLOAT(i) ( *(FLOAT*)&(i) )
#define AS_INT32(f) ( *(INT32*)&(f) )
#define AS_INT16(f) ( *(INT16*)&(f) )
#define AS_UINT32(f) ( *(UINT32*)&(f) )
#define SURFACE_LOCKED(pDDSLcl) \
    ((pDDSLcl)->lpGbl->dwUsageCount > 0)
#define SURFACE_MEMORY(surfLcl) \
(LPVOID)((surfLcl)->lpGbl->fpVidMem)

// multimedia\directx\dxg\d3d\ref\rast\setup.cpp
#define LINEDIR_CMP( _A, _B ) \
( ( fLineMajorExtent > 0 ) ? ( (_A) < (_B) ) : ( (_A) > (_B) ) )

// multimedia\directx\dxg\d3d\ref\rast\texture.cpp
#define NEG_NX (NEG_NORM | POS_NX)
#define NEG_NY (NEG_NORM | POS_NY)
#define NEG_NZ (NEG_NORM | POS_NZ)

// multimedia\directx\dxg\d3d\ref\tnl\clipping.hpp
#define RRCLIP_ALL (RRCLIP_LEFT  | RRCLIP_RIGHT   |         \
                    RRCLIP_TOP   | RRCLIP_BOTTOM  |         \
                    RRCLIP_FRONT | RRCLIP_BACK    |         \
                    RRCLIP_USERPLANES_ALL)
#define RRCLIPGB_ALL (RRCLIPGB_LEFT | RRCLIPGB_RIGHT |      \
                      RRCLIPGB_TOP | RRCLIPGB_BOTTOM |      \
                      RRCLIP_FRONT | RRCLIP_BACK     |      \
                      RRCLIP_USERPLANES_ALL)
#define RRCLIP_INGUARDBAND (RRCLIP_LEFT | RRCLIP_RIGHT |    \
                            RRCLIP_TOP  | RRCLIP_BOTTOM)
#define CLIPPED_ALL (CLIPPED_LEFT|CLIPPED_RIGHT     \
             |CLIPPED_TOP|CLIPPED_BOTTOM            \
             |CLIPPED_FRONT|CLIPPED_BACK)

// multimedia\directx\dxg\d3d\ref\tnl\xform.cpp
#define MATRIX_PRODUCT(res, a, b)                                           \
res->_11 = a->_11*b->_11 + a->_12*b->_21 + a->_13*b->_31 + a->_14*b->_41;   \
res->_12 = a->_11*b->_12 + a->_12*b->_22 + a->_13*b->_32 + a->_14*b->_42;   \
res->_13 = a->_11*b->_13 + a->_12*b->_23 + a->_13*b->_33 + a->_14*b->_43;   \
res->_14 = a->_11*b->_14 + a->_12*b->_24 + a->_13*b->_34 + a->_14*b->_44;   \
                                                                            \
res->_21 = a->_21*b->_11 + a->_22*b->_21 + a->_23*b->_31 + a->_24*b->_41;   \
res->_22 = a->_21*b->_12 + a->_22*b->_22 + a->_23*b->_32 + a->_24*b->_42;   \
res->_23 = a->_21*b->_13 + a->_22*b->_23 + a->_23*b->_33 + a->_24*b->_43;   \
res->_24 = a->_21*b->_14 + a->_22*b->_24 + a->_23*b->_34 + a->_24*b->_44;   \
                                                                            \
res->_31 = a->_31*b->_11 + a->_32*b->_21 + a->_33*b->_31 + a->_34*b->_41;   \
res->_32 = a->_31*b->_12 + a->_32*b->_22 + a->_33*b->_32 + a->_34*b->_42;   \
res->_33 = a->_31*b->_13 + a->_32*b->_23 + a->_33*b->_33 + a->_34*b->_43;   \
res->_34 = a->_31*b->_14 + a->_32*b->_24 + a->_33*b->_34 + a->_34*b->_44;   \
                                                                            \
res->_41 = a->_41*b->_11 + a->_42*b->_21 + a->_43*b->_31 + a->_44*b->_41;   \
res->_42 = a->_41*b->_12 + a->_42*b->_22 + a->_43*b->_32 + a->_44*b->_42;   \
res->_43 = a->_41*b->_13 + a->_42*b->_23 + a->_43*b->_33 + a->_44*b->_43;   \
res->_44 = a->_41*b->_14 + a->_42*b->_24 + a->_43*b->_34 + a->_44*b->_44;

// multimedia\directx\dxg\dd\ddraw\main\alphablt.c
#define DONE_LOCKS() \
    if (dest_lock_taken) \
    { \
	InternalUnlock(surf_dest_lcl,NULL,NULL,0); \
	dest_lock_taken = FALSE; \
    } \
    if (src_lock_taken && surf_src_lcl) \
    { \
	InternalUnlock(surf_src_lcl,NULL,NULL,0); \
	src_lock_taken = FALSE; \
    }

// multimedia\directx\dxg\dd\ddraw\main\ddagpnt.c
#define GET_AGPI(hdev) (&((EDD_DIRECTDRAW_GLOBAL *)hdev)->AgpInterface)

// multimedia\directx\dxg\dd\ddraw\main\ddalias.c
#define HEAPALIASINFO_MAPPED ( HEAPALIASINFO_MAPPEDREAL | HEAPALIASINFO_MAPPEDDUMMY )
#define MAP_HEAP_ALIAS_TO_VID_MEM( hvxd, lpHeapAlias )      \
    vxdMapVMAliasToVidMem( (hvxd),                          \
	                   (lpHeapAlias)->lpAlias,          \
			   (lpHeapAlias)->dwAliasSize,      \
		           (LPVOID)(lpHeapAlias)->fpVidMem )
#define MAP_HEAP_ALIAS_TO_DUMMY_MEM( hvxd, lpHeapAlias )    \
    vxdMapVMAliasToDummyMem( (hvxd),                        \
	                     (lpHeapAlias)->lpAlias,        \
			     (lpHeapAlias)->dwAliasSize )
#define UNMAP_HEAP_ALIAS( hvxd, lpHeapAlias )               \
    vxdUnmapVMAlias( (hvxd),                                \
	             (lpHeapAlias)->lpAlias,                \
	             (lpHeapAlias)->dwAliasSize )

// multimedia\directx\dxg\dd\ddraw\main\ddclip.c
#define SIZE_OF_A_CLIPLIST(lpRgn) \
        (sizeof(RGNDATAHEADER)+sizeof(RECTL)*lpRgn->rdh.nCount)

// multimedia\directx\dxg\dd\ddraw\main\ddcreate.c
	#define ENTER_CSDDC() EnterCriticalSection( &ddcCS )
	#define LEAVE_CSDDC() LeaveCriticalSection( &ddcCS )

// multimedia\directx\dxg\dd\ddraw\main\ddcsurf.c
#define IS_DX6_D3DDRIVER(pDdGbl) (((pDdGbl)->lpD3DHALCallbacks3!=NULL) &&           \
				  ((pDdGbl)->lpD3DHALCallbacks3->DrawPrimitives2!=NULL))
#define CAPS_NOHEIGHT_REQUIRED ( DDSCAPS_PRIMARYSURFACE | DDSCAPS_EXECUTEBUFFER | DDSCAPS_SHAREDZBUFFER | DDSCAPS_SHAREDBACKBUFFER )
#define CAPS_NOWIDTH_REQUIRED  ( DDSCAPS_PRIMARYSURFACE | DDSCAPS_SHAREDZBUFFER | DDSCAPS_SHAREDBACKBUFFER )
#define CAPS_NOHEIGHT_REQUIRED ( DDSCAPS_PRIMARYSURFACE | DDSCAPS_EXECUTEBUFFER )
#define CAPS_NOWIDTH_REQUIRED  ( DDSCAPS_PRIMARYSURFACE | DDSCAPS_EXECUTEBUFFER )

// multimedia\directx\dxg\dd\ddraw\main\dddefwp.c
    #define ENTERWINDOWLISTCSECT    EnterCriticalSection( &csWindowList );
    #define LEAVEWINDOWLISTCSECT    LeaveCriticalSection( &csWindowList );

// multimedia\directx\dxg\dd\ddraw\main\ddithunk.h
#define IS_SOFTWARE_DRIVER(x)                                       \
    (((PDDDEVICEHANDLE)(x))->pSwDD != NULL)
#define IS_SURFACE_LOOSABLE(x)                                      \
    (!IS_SOFTWARE_DRIVER_SURFACE(x) &&                              \
    ((((PDDSURFACE)(x))->Pool == D3DPOOL_LOCALVIDMEM) ||        \
    (((PDDSURFACE)(x))->Pool == D3DPOOL_NONLOCALVIDMEM) ||      \
    (((PDDSURFACE)(x))->Pool == D3DPOOL_MANAGED)))
#define GET_CACHED_LIGHTWEIGHT_INT(x)                           \
    ((x)->pDevice->pCachedSurfaceTable[INDEX_ENTRY((x)->Surface.pLight->CachedIndex)].pSurface)

// multimedia\directx\dxg\dd\ddraw\main\ddrawpr.h
    #define DOHALCALL( halcall, fn, data, rc, isHEL ) \
        if( (fn != _DDHAL_##halcall) && !isHEL ) { \
            ENTER_WIN16LOCK(); \
            rc = fn( &data ); \
            LEAVE_WIN16LOCK(); \
        } else { \
            rc = fn( &data ); \
        }
    #define DOHALCALL_NOWIN16( halcall, fn, data, rc, isHEL ) \
            rc = fn( &data );
    #define DOHALCALL( halcall, fn, data, rc, isHEL ) \
            if (fn) \
                rc = fn( &data );\
            else\
                rc = DDHAL_DRIVER_NOTHANDLED;
    #define DOHALCALL_NOWIN16( halcall, fn, data, rc, isHEL ) \
            if (fn) \
                rc = fn( &data );\
            else\
                rc = DDHAL_DRIVER_NOTHANDLED;
#define CHEAP_LEAVE {LeaveGlobalCriticalSection(&CheapMutexPerProcess);}
#define CHEAP_ENTER {EnterGlobalCriticalSection(&CheapMutexPerProcess);}
                    #define FINI_DDRAW_CSECT() {DetachFromGlobalCriticalSection(&CheapMutexPerProcess);}
                #define ENTER_DDRAW() \
                        DPF( 7, "*****%08lx ENTER_DDRAW: CNT = %ld," REMIND( "" ), GETCURRPID(), iDLLCSCnt ); \
                        EnterCriticalSection( (LPCRITICAL_SECTION) lpDDCS ); \
                        INCCSCNT(); \
                        DPF( 7, "*****%08lx GOT DDRAW CSECT: CNT = %ld," REMIND(""), GETCURRPID(), iDLLCSCnt );
                #define LEAVE_DDRAW() \
                        DECCSCNT() \
                        DPF( 7, "*****%08lx LEAVE_DDRAW: CNT = %ld," REMIND( "" ), GETCURRPID(), iDLLCSCnt ); \
                        LeaveCriticalSection( (LPCRITICAL_SECTION) lpDDCS );
                #define ENTER_DDRAW()   \
                            DPF( 7, "*****%08lx ENTER_WIN16LOCK: CNT = %ld," REMIND( "" ), GETCURRPID(), iWin16Cnt ); \
                            _EnterSysLevel( lpWin16Lock ); \
                            INCW16CNT(); \
                            DPF( 7, "*****%08lx GOT WIN16LOCK: CNT = %ld," REMIND(""), GETCURRPID(), iWin16Cnt );
                #define LEAVE_DDRAW() \
                            DECW16CNT() \
                            DPF( 7, "*****%08lx LEAVE_WIN16LOCK: CNT = %ld," REMIND( "" ), GETCURRPID(), iWin16Cnt ); \
                            _LeaveSysLevel( lpWin16Lock );
            #define ENTER_DRIVERLISTCSECT() \
                        EnterCriticalSection( &csDriverObjectList );
            #define LEAVE_DRIVERLISTCSECT() \
                        LeaveCriticalSection( &csDriverObjectList );
    #define HIDESHOW_IME()                                          \
            if (gdwSetIME)                                          \
            {                                                       \
                SystemParametersInfo(                               \
                    SPI_SETSHOWIMEUI, gdwSetIME - 1, NULL, 0);      \
                                                                    \
                InterlockedExchange(&gdwSetIME, 0);                 \
            }
        #define ENTER_WIN16LOCK()       \
                    DPF( 7, "*****%08lx ENTER_WIN16LOCK: CNT = %ld," REMIND( "" ), GETCURRPID(), iWin16Cnt ); \
                    _EnterSysLevel( lpWin16Lock ); \
                    INCW16CNT(); \
                    DPF( 7, "*****%08lx GOT WIN16LOCK: CNT = %ld," REMIND(""), GETCURRPID(), iWin16Cnt );
        #define LEAVE_WIN16LOCK()       \
                    DECW16CNT() \
                    DPF( 7,"*****%08lx LEAVE_WIN16LOCK: CNT = %ld," REMIND( "" ), GETCURRPID(), iWin16Cnt ); \
                    _LeaveSysLevel( lpWin16Lock );
    #define GETDDVXDHANDLE( pdrv_lcl ) \
        ( ( GetCurrentProcessId() == ( pdrv_lcl )->dwProcessId ) ? (HANDLE) ( ( pdrv_lcl )->hDDVxd ) : hHelperDDVxd )

// multimedia\directx\dxg\dd\ddraw\main\ddrefrsh.c
#define gMruItemSize sizeof (DDMONITORINFO)

// multimedia\directx\dxg\dd\ddraw\main\ddsblt.c
#define DONE_LOCKS() \
    if( dest_lock_taken ) \
    { \
        if (subrect_lock_taken) \
        {   \
            InternalUnlock( this_dest_lcl, NULL, &subrect_lock_rect, 0);    \
            subrect_lock_taken = FALSE; \
        }       \
        else    \
        {       \
            InternalUnlock( this_dest_lcl,NULL,NULL,0 ); \
        }       \
        dest_lock_taken = FALSE; \
    } \
    if( src_lock_taken && this_src_lcl) \
    { \
        InternalUnlock( this_src_lcl,NULL,NULL,0 ); \
        src_lock_taken = FALSE; \
    }

// multimedia\directx\dxg\dd\ddraw\main\dllmain.c
        #define INITCSINIT() \
	        ReinitializeCriticalSection( &csInit ); \
	        MakeCriticalSectionGlobal( &csInit );
        #define ENTER_CSINIT() EnterCriticalSection( &csInit )
        #define LEAVE_CSINIT() LeaveCriticalSection( &csInit )
        #define INITCSDDC() \
	        ReinitializeCriticalSection( &ddcCS ); \
	        MakeCriticalSectionGlobal( &ddcCS );
#define INITCSWINDLIST() \
	ReinitializeCriticalSection( &csWindowList ); \
	MakeCriticalSectionGlobal( &csWindowList );
#define INITCSDRIVEROBJECTLIST() \
	ReinitializeCriticalSection( &csDriverObjectList ); \
	MakeCriticalSectionGlobal( &csDriverObjectList );

// multimedia\directx\dxg\misc\lists.h
#define	LIST_INITIALIZE(root)\
{\
    (root)->Root = 0;\
}
#define	TAIL_QUEUE_INITIALIZE(root)\
{\
    (root)->First = NULL;\
    (root)->Last = &(root)->First;\
}
#define	CIRCLE_QUEUE_INITIALIZE(root,type)\
{   (root)->Last = (type *)(root);\
    (root)->First = (type *)(root);\
}
#define CIRCLE_QUEUE_INSERT_END(root,type,element,field)\
{   (element)->field.Prev = (root)->Last;\
    (element)->field.Next = (type *)(root);\
    if((root)->First != (type *)(root))\
	(root)->Last->field.Next = (element);\
    else\
	(root)->First = (element);\
    (root)->Last = (element);\
}
#define CIRCLE_QUEUE_INSERT_ROOT(root,type,element,field)\
{   (element)->field.Prev = (type *)(root);\
    (element)->field.Next = (root)->First;\
    if ((root)->Last != (void *)(root))\
	(root)->First->field.Prev = (element);\
    else\
	(root)->Last = (element);\
    (root)->First = (element);\
}
#define CIRCLE_QUEUE_INSERT_PREVIOUS(root,current_element,element,field)\
{   (element)->field.Prev = (current_element)->field.Prev;\
    (element)->field.Next = (current_element);\
    if ((current_element)->field.Prev != (void *)(root))\
	(current_element)->field.Prev->field.Next = (element);\
    else\
	(root)->First = (element);\
    (current_element)->field.Prev = (element);\
}
#define CIRCLE_QUEUE_FIRST(root)\
((root)->First == (void *) (root)? 0: (root)->First)
#define CIRCLE_QUEUE_LAST(root)\
((root)->Last == (void *) (root)? 0: (root)->Last)
#define CIRCLE_QUEUE_NEXT(root,element,field)\
((void *) (element)->field.Next == (void *) (root)? 0: (element)->field.Next)
#define CIRCLE_QUEUE_PREVIOUS(root,element,field)\
((element)->field.Prev == (void *) (root)? 0: (element)->field.Prev)

// multimedia\directx\dxg\ref8\inc\rdcomm.hpp
#define AS_FLOAT(i) ( *(FLOAT*)&(i) )
#define AS_INT32(f) ( *(INT32*)&(f) )
#define AS_INT16(f) ( *(INT16*)&(f) )
#define AS_UINT32(f) ( *(UINT32*)&(f) )
#define SURFACE_LOCKED(pDDSLcl) \
    ((pDDSLcl)->lpGbl->dwUsageCount > 0)
#define SURFACE_MEMORY(surfLcl) \
(LPVOID)((surfLcl)->lpGbl->fpVidMem)

// multimedia\directx\dxg\ref8\inc\reftnl.hpp
#define RDPV_DIRTY_XFORM       (RDPV_DIRTY_PROJXFM   | \
                                RDPV_DIRTY_VIEWXFM   | \
                                RDPV_DIRTY_WORLDXFM  | \
                                RDPV_DIRTY_WORLD1XFM | \
                                RDPV_DIRTY_WORLD2XFM | \
                                RDPV_DIRTY_WORLD3XFM)

// multimedia\directx\dxg\ref8\inc\vstream.h
#define RDVSD_ISLEGACY(ShaderHandle) !(ShaderHandle & D3DFVF_RESERVED0)

// multimedia\directx\dxg\ref8\rast\ctexfilt.cpp
#define NEG_NX (NEG_NORM | POS_NX)
#define NEG_NY (NEG_NORM | POS_NY)
#define NEG_NZ (NEG_NORM | POS_NZ)
#define _MapFaceParams( _Face, _IM, _bFlipM, _IU, _bFlipU, _IV, _bFlipV ) \
{ \
    Face = D3DCUBEMAP_FACE_##_Face; \
    fMajor     = (_bFlipM) ? (-fCrd[_IM]) : ( fCrd[_IM]); \
    fMapCrd[0] = (_bFlipU) ? (-fCrd[_IU]) : ( fCrd[_IU]); \
    fMapCrd[1] = (_bFlipV) ? (-fCrd[_IV]) : ( fCrd[_IV]); \
    fMajorGrad[0]  = m_TexCvg[iStage].fGradients[_IM][0]; if (_bFlipM) fMajorGrad[0]  = -fMajorGrad[0]; \
    fMajorGrad[1]  = m_TexCvg[iStage].fGradients[_IM][1]; if (_bFlipM) fMajorGrad[1]  = -fMajorGrad[1]; \
    fMapGrad[0][0] = m_TexCvg[iStage].fGradients[_IU][0]; if (_bFlipU) fMapGrad[0][0] = -fMapGrad[0][0]; \
    fMapGrad[0][1] = m_TexCvg[iStage].fGradients[_IU][1]; if (_bFlipU) fMapGrad[0][1] = -fMapGrad[0][1]; \
    fMapGrad[1][0] = m_TexCvg[iStage].fGradients[_IV][0]; if (_bFlipV) fMapGrad[1][0] = -fMapGrad[1][0]; \
    fMapGrad[1][1] = m_TexCvg[iStage].fGradients[_IV][1]; if (_bFlipV) fMapGrad[1][1] = -fMapGrad[1][1]; \
}
#define _SetCET( _Face, _Crd0, _Crd1 ) (_Face)|(CET_0##_Crd0)|(CET_1##_Crd1)

// multimedia\directx\dxg\ref8\rast\psexec.cpp
    #define _StepOverInst(__INST)       pRDPSInstBuffer += sizeof(__INST##_PARAMS);
    #define _DeclArgs(__INST)           __INST##_PARAMS& Args = _InstParam(__INST);
    #define _PerChannel(__STATEMENT)                                \
                for( iChn=0; iChn<4; iChn++ )                       \
                {                                                   \
                    __STATEMENT                                     \
                }                                                   \

// multimedia\directx\dxg\ref8\rast\psutil.cpp
    #define _StepOverInst(__INST)       pRDPSInstBuffer += sizeof(__INST##_PARAMS);
    #define _DeclArgs(__INST)           __INST##_PARAMS& Args = _InstParam(__INST);

// multimedia\directx\dxg\ref8\rast\rastprim.cpp
#define LINEDIR_CMP( _A, _B ) \
( ( m_fLineMajorLength > 0 ) ? ( (_A) < (_B) ) : ( (_A) > (_B) ) )

// multimedia\directx\dxg\ref8\tnl\clipping.hpp
#define RDCLIP_ALL (RDCLIP_LEFT  | RDCLIP_RIGHT   |         \
                    RDCLIP_TOP   | RDCLIP_BOTTOM  |         \
                    RDCLIP_FRONT | RDCLIP_BACK    |         \
                    RDCLIP_USERPLANES_ALL)
#define RDCLIPGB_ALL (RDCLIPGB_LEFT | RDCLIPGB_RIGHT |      \
                      RDCLIPGB_TOP | RDCLIPGB_BOTTOM |      \
                      RDCLIP_FRONT | RDCLIP_BACK     |      \
                      RDCLIP_USERPLANES_ALL)
#define RDCLIP_INGUARDBAND (RDCLIP_LEFT | RDCLIP_RIGHT |    \
                            RDCLIP_TOP  | RDCLIP_BOTTOM)
#define CLIPPED_ALL (CLIPPED_LEFT|CLIPPED_RIGHT     \
             |CLIPPED_TOP|CLIPPED_BOTTOM            \
             |CLIPPED_FRONT|CLIPPED_BACK)

// multimedia\directx\dxg\ref8\tnl\xform.cpp
#define MATRIX_PRODUCT(res, a, b)                                           \
res->_11 = a->_11*b->_11 + a->_12*b->_21 + a->_13*b->_31 + a->_14*b->_41;   \
res->_12 = a->_11*b->_12 + a->_12*b->_22 + a->_13*b->_32 + a->_14*b->_42;   \
res->_13 = a->_11*b->_13 + a->_12*b->_23 + a->_13*b->_33 + a->_14*b->_43;   \
res->_14 = a->_11*b->_14 + a->_12*b->_24 + a->_13*b->_34 + a->_14*b->_44;   \
                                                                            \
res->_21 = a->_21*b->_11 + a->_22*b->_21 + a->_23*b->_31 + a->_24*b->_41;   \
res->_22 = a->_21*b->_12 + a->_22*b->_22 + a->_23*b->_32 + a->_24*b->_42;   \
res->_23 = a->_21*b->_13 + a->_22*b->_23 + a->_23*b->_33 + a->_24*b->_43;   \
res->_24 = a->_21*b->_14 + a->_22*b->_24 + a->_23*b->_34 + a->_24*b->_44;   \
                                                                            \
res->_31 = a->_31*b->_11 + a->_32*b->_21 + a->_33*b->_31 + a->_34*b->_41;   \
res->_32 = a->_31*b->_12 + a->_32*b->_22 + a->_33*b->_32 + a->_34*b->_42;   \
res->_33 = a->_31*b->_13 + a->_32*b->_23 + a->_33*b->_33 + a->_34*b->_43;   \
res->_34 = a->_31*b->_14 + a->_32*b->_24 + a->_33*b->_34 + a->_34*b->_44;   \
                                                                            \
res->_41 = a->_41*b->_11 + a->_42*b->_21 + a->_43*b->_31 + a->_44*b->_41;   \
res->_42 = a->_41*b->_12 + a->_42*b->_22 + a->_43*b->_32 + a->_44*b->_42;   \
res->_43 = a->_41*b->_13 + a->_42*b->_23 + a->_43*b->_33 + a->_44*b->_43;   \
res->_44 = a->_41*b->_14 + a->_42*b->_24 + a->_43*b->_34 + a->_44*b->_44;

// multimedia\directx\dxvb\dx7vb\d3d7obj.cpp
#define GUIDISEQUAL(a,b) \
	((((DxGuid *)a)->data1==((DxGuid *)b)->data1) && \
	(((DxGuid *)a)->data2==((DxGuid *)b)->data2) && \
	(((DxGuid *)a)->data3==((DxGuid *)b)->data3) && \
	(((DxGuid *)a)->data4[0]==((DxGuid *)b)->data4[0]) && \
	(((DxGuid *)a)->data4[1]==((DxGuid *)b)->data4[1]) && \
	(((DxGuid *)a)->data4[2]==((DxGuid *)b)->data4[2]) && \
	(((DxGuid *)a)->data4[3]==((DxGuid *)b)->data4[3]) && \
	(((DxGuid *)a)->data4[4]==((DxGuid *)b)->data4[4]) && \
	(((DxGuid *)a)->data4[5]==((DxGuid *)b)->data4[5]) && \
	(((DxGuid *)a)->data4[6]==((DxGuid *)b)->data4[6]) && \
	(((DxGuid *)a)->data4[7]==((DxGuid *)b)->data4[7]))

// multimedia\directx\dxvb\dx7vb\d3drm3obj.cpp
#define DO_GETOBJECT_NOTNULL_VISUAL_ADDREF(v,i) LPDIRECT3DRMVISUAL v=NULL; \
	{ IUnknown *pIUnk=NULL; \
	if(i) i->InternalGetObject((IUnknown **)&pIUnk); \
	if (pIUnk) pIUnk->QueryInterface(IID_IDirect3DRMVisual,(void**)&v); \
	}

// multimedia\directx\dxvb\dx7vb\direct.cpp
#define GUIDS_EQUAL(g,g2) (\
	(g.Data1==g2->Data1) && \
	(g.Data2==g2->Data2) && \
	(g.Data3==g2->Data3) && \
	(g.Data4[0]==g2->Data4[0]) && \
	(g.Data4[1]==g2->Data4[1]) && \
	(g.Data4[2]==g2->Data4[2]) && \
	(g.Data4[3]==g2->Data4[3]) && \
	(g.Data4[4]==g2->Data4[4]) && \
	(g.Data4[5]==g2->Data4[5]) && \
	(g.Data4[6]==g2->Data4[6]) && \
	(g.Data4[7]==g2->Data4[7]) )
#define MYVARIANTINIT(inArg,puser) \
	VariantInit(puser); \
	user.vt=VT_UNKNOWN; \
	user.punkVal = inArg; \
	user.punkVal->AddRef();

// multimedia\directx\dxvb\dx7vb\dms.h
#define IS_NULLGUID(g) (\
	(g->data1==0) && \
	(g->data2==0) && \
	(g->data3==0) && \
	(g->data4[0]==0) && \
	(g->data4[1]==0) && \
	(g->data4[2]==0) && \
	(g->data4[3]==0) && \
	(g->data4[4]==0) && \
	(g->data4[5]==0) && \
	(g->data4[6]==0) && \
	(g->data4[7]==0) )
#define JAVASTRING(item) {sizeof(item)*2-2, L##item}
#define DO_GETOBJECT_NOTNULL(t,v,i) t v=NULL;if(i) i->InternalGetObject((IUnknown **)(&v));

// multimedia\directx\dxvb\dx7vb\dplaylobby3obj.cpp
#define GUIDS_EQUAL(g2,g) (\
	(g.Data1==g2->Data1) && \
	(g.Data2==g2->Data2) && \
	(g.Data3==g2->Data3) && \
	(g.Data4[0]==g2->Data4[0]) && \
	(g.Data4[1]==g2->Data4[1]) && \
	(g.Data4[2]==g2->Data4[2]) && \
	(g.Data4[3]==g2->Data4[3]) && \
	(g.Data4[4]==g2->Data4[4]) && \
	(g.Data4[5]==g2->Data4[5]) && \
	(g.Data4[6]==g2->Data4[6]) && \
	(g.Data4[7]==g2->Data4[7]) )

// multimedia\directx\dxvb\dx7vb\inc\dmusicf.h
#define DMUS_SIGNPOSTF_LETTER   (DMUS_SIGNPOSTF_A | DMUS_SIGNPOSTF_B | DMUS_SIGNPOSTF_C | DMUS_SIGNPOSTF_D | DMUS_SIGNPOSTF_E | DMUS_SIGNPOSTF_F)
#define DMUS_SIGNPOSTF_ROOT     (DMUS_SIGNPOSTF_1 | DMUS_SIGNPOSTF_2 | DMUS_SIGNPOSTF_3 | DMUS_SIGNPOSTF_4 | DMUS_SIGNPOSTF_5 | DMUS_SIGNPOSTF_6 | DMUS_SIGNPOSTF_7)

// multimedia\directx\dxvb\dx7vb\inc\dmusici.h
#define DMUS_PLAYMODE_PEDALPOINT        (DMUS_PLAYMODE_KEY_ROOT | DMUS_PLAYMODE_SCALE_INTERVALS)
#define DMUS_PLAYMODE_MELODIC           (DMUS_PLAYMODE_CHORD_ROOT | DMUS_PLAYMODE_SCALE_INTERVALS)
#define DMUS_PLAYMODE_NORMALCHORD       (DMUS_PLAYMODE_CHORD_ROOT | DMUS_PLAYMODE_CHORD_INTERVALS)
#define DMUS_PLAYMODE_ALWAYSPLAY        (DMUS_PLAYMODE_MELODIC | DMUS_PLAYMODE_NORMALCHORD)

// multimedia\directx\dxvb\dx8vb\d3d7obj.cpp
#define GUIDISEQUAL(a,b) \
	((((DxGuid *)a)->data1==((DxGuid *)b)->data1) && \
	(((DxGuid *)a)->data2==((DxGuid *)b)->data2) && \
	(((DxGuid *)a)->data3==((DxGuid *)b)->data3) && \
	(((DxGuid *)a)->data4[0]==((DxGuid *)b)->data4[0]) && \
	(((DxGuid *)a)->data4[1]==((DxGuid *)b)->data4[1]) && \
	(((DxGuid *)a)->data4[2]==((DxGuid *)b)->data4[2]) && \
	(((DxGuid *)a)->data4[3]==((DxGuid *)b)->data4[3]) && \
	(((DxGuid *)a)->data4[4]==((DxGuid *)b)->data4[4]) && \
	(((DxGuid *)a)->data4[5]==((DxGuid *)b)->data4[5]) && \
	(((DxGuid *)a)->data4[6]==((DxGuid *)b)->data4[6]) && \
	(((DxGuid *)a)->data4[7]==((DxGuid *)b)->data4[7]))

// multimedia\directx\dxvb\dx8vb\direct.cpp
    #define GUIDS_EQUAL(g,g2) (\
	(g.Data1==g2->Data1) && \
	(g.Data2==g2->Data2) && \
	(g.Data3==g2->Data3) && \
	(g.Data4[0]==g2->Data4[0]) && \
	(g.Data4[1]==g2->Data4[1]) && \
	(g.Data4[2]==g2->Data4[2]) && \
	(g.Data4[3]==g2->Data4[3]) && \
	(g.Data4[4]==g2->Data4[4]) && \
	(g.Data4[5]==g2->Data4[5]) && \
	(g.Data4[6]==g2->Data4[6]) && \
	(g.Data4[7]==g2->Data4[7]) )
    #define MYVARIANTINIT(inArg,puser) \
	VariantInit(puser); \
	user.vt=VT_UNKNOWN; \
	user.punkVal = inArg; \
	user.punkVal->AddRef();

// multimedia\directx\dxvb\dx8vb\dms.h
    #define IS_NULLGUID(g) (\
	(g->data1==0) && \
	(g->data2==0) && \
	(g->data3==0) && \
	(g->data4[0]==0) && \
	(g->data4[1]==0) && \
	(g->data4[2]==0) && \
	(g->data4[3]==0) && \
	(g->data4[4]==0) && \
	(g->data4[5]==0) && \
	(g->data4[6]==0) && \
	(g->data4[7]==0) )
    #define JAVASTRING(item) {sizeof(item)*2-2, L##item}
    #define DO_GETOBJECT_NOTNULL(t,v,i) t v=NULL;if(i) i->InternalGetObject((IUnknown **)(&v));

// multimedia\directx\dxvb\dx8vb\xfileobj.cpp
    #define GUIDS_EQUAL2(g,g2) (\
	(g->Data1==g2->Data1) && \
	(g->Data2==g2->Data2) && \
	(g->Data3==g2->Data3) && \
	(g->Data4[0]==g2->Data4[0]) && \
	(g->Data4[1]==g2->Data4[1]) && \
	(g->Data4[2]==g2->Data4[2]) && \
	(g->Data4[3]==g2->Data4[3]) && \
	(g->Data4[4]==g2->Data4[4]) && \
	(g->Data4[5]==g2->Data4[5]) && \
	(g->Data4[6]==g2->Data4[6]) && \
	(g->Data4[7]==g2->Data4[7]) )

// multimedia\directx\gamectrl\client\appman.cpp
#define ISVALID(item) ( (item < MAX_DEVICES) && (item>=0) )

// multimedia\directx\gamectrl\default\dicputil.cpp
#define GETRANGE( n ) \
		pDIPropCal->lMin	  = lpMyRanges->jpMin.dw##n##;		\
		pDIPropCal->lCenter = lpMyRanges->jpCenter.dw##n##;	\
		pDIPropCal->lMax	  = lpMyRanges->jpMax.dw##n##;		\
#define SETRANGE( n ) \
      lpMyRanges->jpMin.dw##n##    = pDIPropRange->lMin;		\
      lpMyRanges->jpCenter.dw##n## = pDIPropRange->lCenter;	\
      lpMyRanges->jpMax.dw##n##    = pDIPropRange->lMax;		\

// multimedia\directx\gamectrl\gcdef\joycal.cpp
#define NewLoadString(a, b, c, d)     \
	pszCommonString->LoadString(b); \
	lstrcpy( c, (LPCTSTR)*pszCommonString )
#define NEWMINMAX( a ) \
    if( pji->dw##a##pos > pcv->jr.jpMax.dw##a ) { \
	pcv->jr.jpMax.dw##a = pji->dw##a##pos; \
    } \
    if( pji->dw##a##pos < pcv->jr.jpMin.dw##a ) { \
	pcv->jr.jpMin.dw##a = pji->dw##a##pos; \
    } \
    pji->dw##a##pos *= RAW_SHIFT;

// multimedia\directx\gamectrl\gcdef\joycpl.h
#define ALL_BUTTONS	(JOY_BUTTON1  | \
					 JOY_BUTTON2  | \
					 JOY_BUTTON3  | \
					 JOY_BUTTON4  | \
					 JOY_BUTTON5  | \
					 JOY_BUTTON6  | \
					 JOY_BUTTON7  | \
					 JOY_BUTTON8  | \
					 JOY_BUTTON9  | \
					 JOY_BUTTON10 | \
					 JOY_BUTTON11 | \
					 JOY_BUTTON12 | \
					 JOY_BUTTON13 | \
					 JOY_BUTTON14 | \
					 JOY_BUTTON15 | \
					 JOY_BUTTON16 | \
					 JOY_BUTTON17 | \
					 JOY_BUTTON18 | \
					 JOY_BUTTON19 | \
					 JOY_BUTTON20 | \
					 JOY_BUTTON21 | \
					 JOY_BUTTON22 | \
					 JOY_BUTTON23 | \
					 JOY_BUTTON24 | \
					 JOY_BUTTON25 | \
					 JOY_BUTTON26 | \
					 JOY_BUTTON27 | \
					 JOY_BUTTON28 | \
					 JOY_BUTTON29 | \
					 JOY_BUTTON30 | \
					 JOY_BUTTON31 | \
					 JOY_BUTTON32 )

// multimedia\directx\inc\dciddi.h
#define DCI_CAN_STRETCHXY           		(DCI_CAN_STRETCHX | DCI_CAN_STRETCHY)
#define DCI_CAN_STRETCHXYN          		(DCI_CAN_STRETCHXN | DCI_CAN_STRETCHYN)

// multimedia\dshow\filters.ks\bdaplugin\pch.h
#define IN_RANGE(v,min,max)             (((min) <= (v)) && ((v) <= (max)))

// multimedia\dshow\filters.ks\drvstubs\msmid32\middrv.c
#define IS_REALTIME(b)      (((b) & 0xF8) == 0xF8)
#define IS_SYSTEM(b)        (((b) & 0xF0) == 0xF0)
#define IS_CHANNEL(b)       ((b) & 0x80)

// multimedia\dshow\filters.ks\ipsink\myconfig.h
#define NEW(thing)  (thing *)calloc(1, sizeof(thing))

// multimedia\dshow\filters.ks\ksproxy\ksiproxy.h
#define InitializeAsyncItem( pItm, autoRemove, evnt, routine, ctxt ) \
    (pItm)->link.fLink  = (pItm)->link.bLink = NULL;     \
    (pItm)->remove      = (autoRemove);                  \
    (pItm)->event       = (evnt);                        \
    (pItm)->itemRoutine = (routine);                     \
    (pItm)->context     = (ctxt);
#define UM_IOTHREAD_STOP    (WM_USER + 0x100)
#define UM_IOTHREAD_DELIVER (WM_USER + 0x101)

// multimedia\dshow\filters.ks\tests\inc\waveutil.h
#define SIZEOFWAVEFORMAT(pwfx)  ((WAVE_FORMAT_PCM == pwfx->wFormatTag)?\
                                (sizeof(PCMWAVEFORMAT)):\
                                (sizeof(WAVEFORMATEX)+pwfx->cbSize))

// multimedia\dshow\filters.ks\tests\iphone\common.h
#define RCOPY(X,Y,N) memcpy(Y, X,(N)*sizeof(real))
#define REALZEROP(x) ((x<EPSILON)&&(x>-EPSILON))
#define sig_scale(SCALE,A,B) \
{int __i;for(__i=0;__i<IDIM;__i++)(B)[__i]=SCALE*(A)[__i];}
#define sub_sig(A,B,C) \
{int __i;for(__i=0;__i<IDIM;__i++) (C)[__i]=(A)[__i]-(B)[__i];}
#define RCOPY(X,Y,N) memcpy(Y, X,(N)*sizeof(real))
#define CHECK1(V) ({if (! (V>=-10000. && V<=10000.)) abort();})
#define CIRCOPY(X,CIRC,EOS,L,CL) {int _i1,_i2,_i,_lx=0;\
 if((EOS)>=(L)){_i1=(EOS)-(L);_i2=(CL);} \
 else            {_i1=0;        _i2=(CL)+(EOS)-(L);}\
 for(_i=_i2; _i<(CL);   _i++)X[_lx++]=CIRC[_i];\
 for(_i=_i1; _i<(EOS); _i++)X[_lx++]=CIRC[_i];}
#define QINDEX  ({int __qx=vector_end-thequeue; \
		      __qx ? QSIZE-IDIM : __qx-IDIM;})

// multimedia\dshow\filters.ks\tests\iphone\fast.h
#define PROD5(A,B,R) \
{ typeof (R) __x,__y,__t;	\
  typeof (&A[0]) __pa=A;	\
  typeof (&B[0]) __pb=B;	\
                          __x=*__pa++;__y=*__pb++;	\
  R=R-R;    __t=__x*__y;  __x=*__pa++;__y=*__pb++;	\
  R+=__t;   __t=__x*__y;  __x=*__pa++;__y=*__pb++;	\
  R+=__t;   __t=__x*__y;  __x=*__pa++;__y=*__pb++;	\
  R+=__t;   __t=__x*__y;  __x=*__pa++;__y=*__pb++;	\
  R+=__t;   __t=__x*__y;	\
  R+=__t;}
#define AUTOCORR(X,R,K,M,N) \
{\
    int  ii,jj;\
    for(ii=0; ii<=K; ii++) {\
	R[ii] = 0;\
	for(jj=M; jj<N; jj++) R[ii] += X[jj]*X[jj-ii];}}
#define RECACORR(X,R,K,M,N,D)	\
{   int __k,__i,__M1=M+1;	\
    typeof (&R[0]) __rp=R;	\
    for(__k=0; __k<=K; __k++) {	\
	typeof (*R) __corr, __t;	\
	typeof (&X[0]) __xip=X+M, __xkp=__xip-__k;	\
	typeof(X[0]) __xi,__xk;	\
	__corr=__corr-__corr;	\
	__xi=*__xip++;	\
	__xk=*__xkp++;	\
	for(__i=__M1;__i<N;__i++) {	\
	    __t=__xi*__xk; __xi=*__xip++;	\
	    __corr+=__t; __xk=*__xkp++;	\
	}	\
	__t=__xi*__xk;	\
	__corr+=__t;	\
	__corr=*__rp*(D)+__corr;	\
	*__rp++=__corr;}}
#define VPROD(X,Y,Z,N)	\
{   typeof (&X[0]) __xp=X;	\
    typeof (&Y[0]) __yp=Y;	\
    typeof (&Z[0]) __zp=Z;	\
    int i;	\
    typeof (X[0]) __xi=*__xp++;	\
    typeof (Y[0]) __yi=*__yp++;	\
    typeof (Z[0]) __zi;	\
    for(i=1;i<N;i++) {	\
	__zi=__xi*__yi;	\
	__xi=*__xp++;	\
	__yi=*__yp++;	\
	*__zp++=__zi;}	\
    __zi=__xi*__yi;	\
    *__zp=__zi;}
#define RSHIFT(START,LENGTH,SHIFT) \
{ typeof (&(START)[0]) __from = &(START)[LENGTH-1]; \
  typeof (&(START)[0]) __to = &(START)[LENGTH+SHIFT-1]; \
  int __i; for(__i=0; __i<LENGTH; __i++)      *__to-- = *__from--;\
}
#define DOTPROD(X,Y,N) \
({ int __i;	\
  typeof((X)[0]*(Y)[0]) __r=0, __t;	\
  typeof ((X)[0]) __x1;	\
  typeof ((Y)[0]) __y1;	\
  typeof (&(X)[0]) __xp = &(X)[0]; \
  typeof (&(Y)[0]) __yp = &(Y)[0]; \
                              __x1=*__xp++; __y1=*__yp++; 	\
             __t=__x1*__y1;   __x1=*__xp++; __y1=*__yp++; 	\
   for(__i=0; __i<(N)-2; __i++) {	\
   __r+=__t; __t=__x1*__y1;   __x1=*__xp++; __y1=*__yp++; }	\
   __r+=__t; __t=__x1*__y1;   	\
   __r+=__t; __r;})

// multimedia\dshow\filters.ks\tests\iphone\parm.h
#define KPMAX	140	/* Max Pitch Period (~ 57 Hz) */

// multimedia\dshow\filters.ks\tests\midirec\midirec.c
#define	IS_SYSTEM(b)		(((b) & 0xF0) == 0xF0)

// multimedia\dshow\filters.ks\tests\tstshell\support.h
    #define GET_WM_COMMAND_ID(wp, lp)                   (wp)

// multimedia\dshow\filters.ks\tests\tstshell\tsseltst.c
#define GetItem(item) GetPrivateProfileString("settings", item, "", szBuf,\
                                              sizeof (szBuf), szTSProfile)

// multimedia\dshow\filters.ks\tests\tstshell\wpf.c
#define VK(vk)  ((vk) | 0x0100)

// multimedia\dshow\filters.ks\tests\tstshell\wpf.h
#define WPF_GETNLINES   (WM_USER + 2)
#define WPF_SETTABSTOPS (WM_USER + 4)
#define WPF_GETTABSTOPS (WM_USER + 5)
#define WPF_GETNUMTABS  (WM_USER + 6)
#define WPF_SETOUTPUT   (WM_USER + 7)
#define WPF_GETOUTPUT   (WM_USER + 8)
#define WPF_CLEARWINDOW (WM_USER + 9)

// multimedia\dshow\filters.ks\tests\wavetest\exe\appport.h
    #define GET_WM_ACTIVATE_STATE(wp, lp)           (wp)
    #define GET_WM_CHARTOITEM_CHAR(wp, lp)          (CHAR)(wp)
    #define GET_WM_COMMAND_ID(wp, lp)               (wp)
    #define GET_WM_MENUSELECT_CMD(wp, lp)           (wp)
    #define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)    (WPARAM)(cmd), MAKELONG(f, hmenu)
    #define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW)   0, MAKELONG(hmenuF, hmenuW)
    #define GET_WM_MENUCHAR_CHAR(wp, lp)            (CHAR)(wp)
    #define GET_WM_MENUCHAR_MPS(ch, hmenu, f)       (WPARAM)(ch), MAKELONG(hmenu, f)
    #define GET_WM_PARENTNOTIFY_MSG(wp, lp)         (wp)
    #define GET_WM_PARENTNOTIFY2_MPS(msg, x, y)     (WPARAM)(msg), MAKELONG(x, y)
    #define GET_WM_VKEYTOITEM_CODE(wp, lp)          (wp)
    #define GET_WM_HSCROLL_CODE(wp, lp)             (wp)
    #define GET_WM_VSCROLL_CODE(wp, lp)             (wp)

// multimedia\dshow\filters.ks\tests\wavetest\exe\wavetest.h
#define SPACES(n)           ((LPSTR)(&gszSpaces[40 - (n)]))

// multimedia\dshow\filters.ks\vfw\raytube\videoin.cpp
#define PBIHDR(A)        (&(A->VideoInfoHeader.bmiHeader))
#define CFGCAPS(A)            (&(A->ConfigCaps))

// multimedia\dshow\filters\avi\capture\thunk.c
#define poteExp(pinth) (&(pinth)->OptionalHeader. \
                          DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT])

// multimedia\dshow\filters\avi\draw\draw.cpp
#define SLASH(c)     ((c) == TEXT('/') || (c) == TEXT('\\'))

// multimedia\dshow\filters\avi\midi\smfi.h
#define EV_DRUM_EXT         (MIDI_NOTEON | CH_DRUM_EXT)

// multimedia\dshow\filters\avi\mjpeg\jmorecfg.h
#define GETJSAMPLE(value)  ((int) (value) & 0xFF)
#define GETJOCTET(value)  ((value) & 0xFF)

// multimedia\dshow\filters\avi\mjpeg\pmjpeg32\jinclude.h
#define JFREAD(file,buf,sizeofbuf)  \
  ((size_t) fread((void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))
#define JFWRITE(file,buf,sizeofbuf)  \
  ((size_t) fwrite((const void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))

// multimedia\dshow\filters\avi\mjpeg\pmjpeg32\jmorecfg.h
#define GETJSAMPLE(value)  ((int) (value) & 0xFF)
#define GETJOCTET(value)  ((value) & 0xFF)

// multimedia\dshow\filters\core\asyncrdr\url\urlostrm.cpp
#define IS_E_PENDING(x)	( (x == 0x8000000A) || (x == 0x80070007) )

// multimedia\dshow\filters\core\builder2\ks.h
#define DEFINE_KSPROPERTY_ITEM_GENERAL_COMPONENTID(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_GENERAL_COMPONENTID,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSCOMPONENTID),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_MEDIASEEKING_CAPABILITIES(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_MEDIASEEKING_CAPABILITIES,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KS_SEEKING_CAPABILITIES),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_MEDIASEEKING_FORMATS(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_MEDIASEEKING_FORMATS,\
        (Handler),\
        sizeof(KSPROPERTY),\
        0,\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_MEDIASEEKING_TIMEFORMAT(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_MEDIASEEKING_TIMEFORMAT,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(GUID),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_MEDIASEEKING_POSITION(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_MEDIASEEKING_POSITION,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(LONGLONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_MEDIASEEKING_STOPPOSITION(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_MEDIASEEKING_STOPPOSITION,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(LONGLONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_MEDIASEEKING_POSITIONS(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_MEDIASEEKING_POSITIONS,\
        NULL,\
        sizeof(KSPROPERTY),\
        sizeof(KSPROPERTY_POSITIONS),\
        (Handler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_MEDIASEEKING_DURATION(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_MEDIASEEKING_DURATION,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(LONGLONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_MEDIASEEKING_AVAILABLE(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_MEDIASEEKING_AVAILABLE,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSPROPERTY_MEDIAAVAILABLE),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_MEDIASEEKING_PREROLL(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_MEDIASEEKING_PREROLL,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(LONGLONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_MEDIASEEKING_CONVERTTIMEFORMAT(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_MEDIASEEKING_CONVERTTIMEFORMAT,\
        (Handler),\
        sizeof(KSP_TIMEFORMAT),\
        sizeof(LONGLONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_CINSTANCES(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_CINSTANCES,\
        (Handler),\
        sizeof(KSP_PIN),\
        sizeof(KSPIN_CINSTANCES),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_CTYPES(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_CTYPES,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(ULONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_DATAFLOW(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_DATAFLOW,\
        (Handler),\
        sizeof(KSP_PIN),\
        sizeof(KSPIN_DATAFLOW),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_DATARANGES(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_DATARANGES,\
        (Handler),\
        sizeof(KSP_PIN),\
        0,\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_DATAINTERSECTION(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_DATAINTERSECTION,\
        (Handler),\
        sizeof(KSP_PIN) + sizeof(KSMULTIPLE_ITEM),\
        0,\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_INTERFACES(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_INTERFACES,\
        (Handler),\
        sizeof(KSP_PIN),\
        0,\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_MEDIUMS(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_MEDIUMS,\
        (Handler),\
        sizeof(KSP_PIN),\
        0,\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_COMMUNICATION(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_COMMUNICATION,\
        (Handler),\
        sizeof(KSP_PIN),\
        sizeof(KSPIN_COMMUNICATION),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_GLOBALCINSTANCES(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_GLOBALCINSTANCES,\
        (Handler),\
        sizeof(KSP_PIN),\
        sizeof(KSPIN_CINSTANCES),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_NECESSARYINSTANCES(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_NECESSARYINSTANCES,\
        (Handler),\
        sizeof(KSP_PIN),\
        sizeof(ULONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_PHYSICALCONNECTION(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_PHYSICALCONNECTION,\
        (Handler),\
        sizeof(KSP_PIN),\
        0,\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_CATEGORY(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_CATEGORY,\
        (Handler),\
        sizeof(KSP_PIN),\
        sizeof(GUID),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_NAME(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_NAME,\
        (Handler),\
        sizeof(KSP_PIN),\
        0,\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_CONSTRAINEDDATARANGES(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_CONSTRAINEDDATARANGES,\
        (Handler),\
        sizeof(KSP_PIN),\
        0,\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_PROPOSEDATAFORMAT(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_PROPOSEDATAFORMAT,\
        NULL,\
        sizeof(KSP_PIN),\
        sizeof(KSDATAFORMAT),\
        (Handler), NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_PIN_COMPLETEDATAFORMAT(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_PIN_COMPLETEDATAFORMAT,\
        (GetHandler),\
        sizeof(KSP_PIN),\
        0,\
        (SetHandler), NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_QUALITY_REPORT(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_QUALITY_REPORT,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(KSQUALITY),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CONNECTION_STATE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CONNECTION_STATE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(KSSTATE),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CONNECTION_PRIORITY(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CONNECTION_PRIORITY,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(KSPRIORITY),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CONNECTION_DATAFORMAT(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CONNECTION_DATAFORMAT,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        0,\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CONNECTION_ALLOCATORFRAMING(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CONNECTION_ALLOCATORFRAMING,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSALLOCATOR_FRAMING),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CONNECTION_ALLOCATORFRAMING_EX(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CONNECTION_ALLOCATORFRAMING_EX,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(KSALLOCATOR_FRAMING_EX),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CONNECTION_PROPOSEDATAFORMAT(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CONNECTION_PROPOSEDATAFORMAT,\
        NULL,\
        sizeof(KSPROPERTY),\
        sizeof(KSDATAFORMAT),\
        (Handler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CONNECTION_ACQUIREORDERING(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CONNECTION_ACQUIREORDERING,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(BOOL),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSMETHOD_ITEM_STREAMALLOCATOR_ALLOC(Handler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_STREAMALLOCATOR_ALLOC,\
        KSMETHOD_TYPE_WRITE,\
        (Handler),\
        sizeof(KSMETHOD),\
        sizeof(PVOID),\
        NULL)
#define DEFINE_KSPROPERTY_ITEM_STREAMALLOCATOR_FUNCTIONTABLE(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAMALLOCATOR_FUNCTIONTABLE,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSSTREAMALLOCATOR_FUNCTIONTABLE),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAMINTERFACE_HEADERSIZE( GetHandler )\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAMINTERFACE_HEADERSIZE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(ULONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAM_ALLOCATOR(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAM_ALLOCATOR,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(HANDLE),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAM_QUALITY(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAM_QUALITY,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSQUALITY_MANAGER),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAM_DEGRADATION(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAM_DEGRADATION,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        0,\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAM_MASTERCLOCK(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAM_MASTERCLOCK,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(HANDLE),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAM_TIMEFORMAT(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAM_TIMEFORMAT,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(GUID),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAM_PRESENTATIONTIME(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAM_PRESENTATIONTIME,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(KSTIME),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAM_PRESENTATIONEXTENT(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAM_PRESENTATIONEXTENT,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(LONGLONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAM_FRAMETIME(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAM_FRAMETIME,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSFRAMETIME),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAM_RATECAPABILITY(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAM_RATECAPABILITY,\
        (Handler),\
        sizeof(KSRATE_CAPABILITY),\
        sizeof(KSRATE),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAM_RATE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAM_RATE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(KSRATE),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_STREAM_PIPE_ID(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAM_PIPE_ID,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(HANDLE),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CLOCK_TIME(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CLOCK_TIME,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(LONGLONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CLOCK_PHYSICALTIME(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CLOCK_PHYSICALTIME,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(LONGLONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CLOCK_CORRELATEDTIME(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CLOCK_CORRELATEDTIME,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSCORRELATED_TIME),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CLOCK_CORRELATEDPHYSICALTIME(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CLOCK_CORRELATEDPHYSICALTIME,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSCORRELATED_TIME),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CLOCK_RESOLUTION(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CLOCK_RESOLUTION,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSRESOLUTION),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CLOCK_STATE(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CLOCK_STATE,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSSTATE),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CLOCK_FUNCTIONTABLE(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CLOCK_FUNCTIONTABLE,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSCLOCK_FUNCTIONTABLE),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSCREATE_ITEM(DispatchCreate, TypeName, Context)\
{\
    (DispatchCreate),\
    (PVOID)(Context),\
    {\
        sizeof(TypeName) - sizeof(UNICODE_NULL),\
        sizeof(TypeName),\
        (PWCHAR)(TypeName)\
    },\
    NULL, 0\
}

// multimedia\dshow\filters\image2\inc\vmrwindow.h
#define VMR_ACTIVATE_WINDOW TEXT("WM_VMR_ACTIVATE_WINDOW")

// multimedia\dshow\filters\image2\rndless\app.h
#define VCD_SEEKING          (VCD_FF | VCD_RW)

// multimedia\dshow\filters\image2\rndlessplayer\app.h
#define VCD_SEEKING          (VCD_FF | VCD_RW)

// multimedia\dshow\filters\image2\video\vmrenderer.h
#define ValidTVStandard(dw)  (dw & 0x7FFF)

// multimedia\dshow\filters\image2\vmrplyer\app.h
#define VCD_SEEKING          (VCD_FF | VCD_RW)

// multimedia\dshow\filters\image\video\vrmacvis.h
#define ValidTVStandard(dw)  (dw & 0x7FFF)

// multimedia\dshow\filters\lin21dec2\l21dfilt.h
#define ISRECTEQUAL(r1, r2) ((r1).top == (r2).top     && \
                             (r1).left == (r2).left   && \
                             (r1).right == (r2).right && \
                             (r1).bottom == (r2).bottom)

// multimedia\dshow\filters\lin21dec\l21dfilt.h
#define ISRECTEQUAL(r1, r2) (r1.top == r2.top && r1.left == r2.left && r1.right == r2.right && r1.bottom == r2.bottom)

// multimedia\dshow\filters\mixer\ovmixer\ddmc.h
#define IMotionComp_Release(p)                 (p)->lpVtbl->Release(p)

// multimedia\dshow\filters\mixer\ovmixer\ddva.h
#define IVideoAccelerator_Release(p)                 (p)->lpVtbl->Release(p)

// multimedia\dshow\filters\mixer\ovmixer\macvis.h
#define ValidTVStandard(dw)  (dw & 0x7FFF)

// multimedia\dshow\filters\mpeg1\mpegapi\mpegmini.h
#define MP_UNINITIALIZED_VALUE ((ULONG) ~0)

// multimedia\dshow\filters\netshow\inc\jmorecfg.h
#define GETJSAMPLE(value)  ((int) (value) & 0xFF)
#define GETJOCTET(value)  ((value) & 0xFF)

// multimedia\dshow\filters\sbe\inc\dvrdef.h
#define REG_WM_BUFFER_WINDOW_NAME               TEXT ("WMBufferWindowMillis")

// multimedia\dshow\filters\tsdvr\inc\dvrdef.h
#define REG_WM_BUFFER_WINDOW_KEYNAME            TEXT ("WMBufferWindowMillis")

// multimedia\dshow\filters\tsdvr\tools\dsnet\include\le.h
#define InitializeListHead(ListHead) (\
    (ListHead)->Flink = (ListHead)->Blink = (ListHead))
#define IsListEmpty(ListHead) \
    ((ListHead)->Flink == (ListHead))
#define RemoveHeadList(ListHead) \
    (ListHead)->Flink;\
    {RemoveEntryList((ListHead)->Flink)}
#define RemoveTailList(ListHead) \
    (ListHead)->Blink;\
    {RemoveEntryList((ListHead)->Blink)}
#define InsertTailList(ListHead,Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_ListHead;\
    _EX_ListHead = (ListHead);\
    _EX_Blink = _EX_ListHead->Blink;\
    (Entry)->Flink = _EX_ListHead;\
    (Entry)->Blink = _EX_Blink;\
    _EX_Blink->Flink = (Entry);\
    _EX_ListHead->Blink = (Entry);\
    }
#define InsertHeadList(ListHead,Entry) {\
    PLIST_ENTRY _EX_Flink;\
    PLIST_ENTRY _EX_ListHead;\
    _EX_ListHead = (ListHead);\
    _EX_Flink = _EX_ListHead->Flink;\
    (Entry)->Flink = _EX_Flink;\
    (Entry)->Blink = _EX_ListHead;\
    _EX_Flink->Blink = (Entry);\
    _EX_ListHead->Flink = (Entry);\
    }

// multimedia\dshow\filters\tsdvr\tools\dsnet\include\projpch.h
#define UNDEFINED                       ((-1) & ~1)

// multimedia\dshow\filters\tsdvr\tools\dvrapp\main.h
#define MENU_NAME_CAPTURE_GRAPHS        __T("&Capture Graphs")
#define MENU_NAME_CREATE                __T("&Create")
#define MENU_NAME_RECORDINGS            __T("&Recordings")

// multimedia\dshow\filters\tsdvr\tools\statsapp\main.h
#define STATS_CATEGORY_MENU_TITLE           __T("&Category")
#define STATS_MENU_TITLE                    __T("&Stats")
#define OPTIONS_MENU_TITLE                  __T("&Options")
#define     CMD_ALWAYS_ON_TOP_STRING            __T("Always On &Top")
#define     CMD_STATS_ON                        __T("Stats &On")
#define REFRESH_RATE_MENU_TITLE             __T("&Refresh Rate")
#define ACTIONS_MENU_TITLE                  __T("&Actions")
#define     CMD_PAUSE_REFRESH                   __T("&Pause")
#define     CMD_RESET_STATS                     __T("&Reset")
#define CMD_ABOUT_STRING                    __T("A&bout")

// multimedia\dshow\filters\tsdvr\wmsdk\inc\des.h
#define DES_TABLESIZE   (sizeof(DESTable))
#define DESX_TABLESIZE  (sizeof(DESXTable))

// multimedia\dshow\filters\tve\atvefsend\deflate.c
#define CLEAR_HASH(s) \
    s->head[s->hash_size-1] = NIL; \
    zmemzero((charf *)s->head, (unsigned)(s->hash_size-1)*sizeof(*s->head));

// multimedia\dshow\filters\tve\atvefsend\mgatesdefs.h
#define IN_BOUNDS(v,min,max)                    ((min) <= (v) && (v) <= (max))

// multimedia\dshow\filters\tve\atvefsend\msbdnapi.h
#define	IMPLEMENT_IBDNAPPLICATION() public: \
	STDMETHODIMP	SetApplicationID	(const GUID *); \
	STDMETHODIMP	GetApplicationID	(GUID *); \
	STDMETHODIMP	StoreDescription	(LPCOLESTR); \
	STDMETHODIMP	DeleteDescription	(void);

// multimedia\dshow\filters\tve\atvefsend\trees.c
#define Buf_size (8 * 2*sizeof(char))
#define pqremove(s, tree, top) \
{\
    top = s->heap[SMALLEST]; \
    s->heap[SMALLEST] = s->heap[s->heap_len--]; \
    pqdownheap(s, tree, SMALLEST); \
}
#define smaller(tree, n, m, depth) \
   (tree[n].Freq < tree[m].Freq || \
   (tree[n].Freq == tree[m].Freq && depth[n] <= depth[m]))

// multimedia\dshow\filters\tve\atvefsend\trees.cpp
#define Buf_size (8 * 2*sizeof(char))
#define pqremove(s, tree, top) \
{\
    top = s->heap[SMALLEST]; \
    s->heap[SMALLEST] = s->heap[s->heap_len--]; \
    pqdownheap(s, tree, SMALLEST); \
}
#define smaller(tree, n, m, depth) \
   (tree[n].Freq < tree[m].Freq || \
   (tree[n].Freq == tree[m].Freq && depth[n] <= depth[m]))

// multimedia\dshow\filters\tve\atvefsend\zlib.h
#define deflateInit(strm, level) \
        deflateInit_((strm), (level),       ZLIB_VERSION, sizeof(z_stream))
#define inflateInit(strm) \
        inflateInit_((strm),                ZLIB_VERSION, sizeof(z_stream))

// multimedia\dshow\filters\tve\atvefsend\zutil.h
#define ZALLOC(strm, items, size) \
           (*((strm)->zalloc))((strm)->opaque, (items), (size))

// multimedia\dshow\filters\tve\include\mgatesdefs.h
#define IN_BOUNDS(v,min,max)                    ((min) <= (v) && (v) <= (max))

// multimedia\dshow\filters\tve\mstve\infutil.h
#define WRAP {if(q==s->end&&s->read!=s->window){q=s->window;m=(uInt)WAVAIL;}}

// multimedia\dshow\filters\tve\mstve\zlib.h
#define deflateInit(strm, level) \
        deflateInit_((strm), (level),       ZLIB_VERSION, sizeof(z_stream))
#define inflateInit(strm) \
        inflateInit_((strm),                ZLIB_VERSION, sizeof(z_stream))

// multimedia\dshow\filters\tve\mstve\zutil.h
#define ZALLOC(strm, items, size) \
           (*((strm)->zalloc))((strm)->opaque, (items), (size))

// multimedia\dshow\filters\wav\audio\qksaud\ksaudtop.h
#define AddToList( pNodeList, pNode )                                   \
            if( pNodeList ) {                                           \
                (pNode)->List.Next = (SINGLE_LIST_ENTRY *) (pNodeList); \
                (pNodeList)        = (pNode);                           \
            } else {                                                    \
                (pNodeList) = (pNode);                                  \
            }
#define RemoveFirstChildNode( pNode )                                 \
            RemoveFirstEntry( (pNode)->Children, PEERNODE )
#define RemoveFirstParentNode( pNode )                                \
            RemoveFirstEntry( (pNode)->Parents, PEERNODE )
#define RemoveFirstCloneNode( pNode )                                \
            RemoveFirstEntry( (pNode)->Clones, PEERNODE )

// multimedia\dshow\filterus\dexter\jpeglib\jinclude.h
#define JFREAD(file,buf,sizeofbuf)  \
  ((size_t) fread((void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))
#define JFWRITE(file,buf,sizeofbuf)  \
  ((size_t) fwrite((const void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))

// multimedia\dshow\filterus\dexter\jpeglib\jmemdos.c
#define ODD(X)	(((X) & 1L) != 0)

// multimedia\dshow\filterus\dexter\jpeglib\jmorecfg.h
#define GETJSAMPLE(value)  ((int) (value) & 0xFF)
#define GETJOCTET(value)  ((value) & 0xFF)

// multimedia\dshow\filterus\dexter\jpeglib\rdbmp.c
#define UCH(x)	((int) (x) & 0xFF)

// multimedia\dshow\filterus\dexter\jpeglib\rdppm.c
#define UCH(x)	((int) (x) & 0xFF)

// multimedia\dshow\filterus\dexter\jpeglib\rdtarga.c
#define UCH(x)	((int) (x) & 0xFF)

// multimedia\dshow\filterus\midi\midirdr\smfi.h
#define EV_DRUM_EXT         (MIDI_NOTEON | CH_DRUM_EXT)

// multimedia\dshow\guidestore\guidedb.cpp
#define IndexDescInit(b, n, fUnique) {_T(#n), fUnique, sizeofarray(g_rgpcolumndesc##b##_##n), g_rgpcolumndesc##b##_##n}
#define PrimaryKeyInit(b, n) {_T("PK_") _T(#b), TRUE, sizeofarray(g_rgpcolumndesc##b##_##n), g_rgpcolumndesc##b##_##n}
#define TableDescInit(n) \
	{_T(#n), &g_indexdescPrimaryKey##n, g_rgcolumndesc##n, g_rgindexdesc##n}

// multimedia\dshow\guidestore\stdafx.h
#define END_ADO_BINDING()   {0, ADODB::adEmpty, 0, 0, 0, 0, 0, 0, 0, FALSE}};\
	return rgADOBindingEntries;}

// multimedia\dshow\streams\foxbear\foxbear.c
#define IS_NUM(c)     ((c) >= '0' && (c) <= '9')
#define IS_SPACE(c)   ((c) == ' ' || (c) == '\r' || (c) == '\n' || (c) == '\t' || (c) == 'x')

// multimedia\dshow\streams\foxbear\vidsrc.c
#define RELEASE(x) if ((x) != NULL) (x)->lpVtbl->Release(x);

// multimedia\dshow\tools\vcdplyer\app.h
#define VCD_SEEKING          (VCD_FF | VCD_RW)

// multimedia\dshow\vidctl\atl\atlcom.h
#define END_PROPERTY_MAP() \
			{NULL, 0, NULL, &IID_NULL, 0, 0, 0, &IID_NULL} \
		}; \
		return pPropMap; \
	}
#define END_PROP_MAP() \
			{NULL, 0, NULL, &IID_NULL, 0, 0, 0, &IID_NULL} \
		}; \
		return pPropMap; \
	}
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
#define DESTROY_OBJMAP(x) delete[] x;
#define DECLARE_OBJECT_DESCRIPTION(x)\
	static LPCTSTR WINAPI GetObjectDescription()\
	{\
		return _T(x);\
	}
#define DECLARE_NO_REGISTRY()\
	static HRESULT WINAPI UpdateRegistry(BOOL /*bRegister*/)\
	{return S_OK;}
#define DECLARE_REGISTRY_RESOURCE(x)\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister)\
	{\
	return _Module.UpdateRegistryFromResource(_T(#x), bRegister);\
	}
#define DECLARE_REGISTRY_RESOURCEID(x)\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister)\
	{\
	return _Module.UpdateRegistryFromResource(x, bRegister);\
	}
#define BEGIN_SERVICE_MAP(x) public: \
	HRESULT _InternalQueryService(REFGUID guidService, REFIID riid, void** ppvObject) \
	{
#define END_SERVICE_MAP() \
		return E_NOINTERFACE; \
	}
#define END_SINK_MAP() {0, NULL, 0, 0, NULL, NULL} }; return map;}

// multimedia\dshow\vidctl\objreghelp.h
#define MAX_GUID_LEN (39 * sizeof(OLECHAR))

// multimedia\dshow\vidctl\trace.h
#define BEGIN_TRACEL(level) if (dwTraceLevel >= level) {

// multimedia\media\avi\avicap.io\avicapi.h
  #define FIELDOFF(type,field)  (&(((type)0)->field))
  #define FIELDSIZ(type,field)  (sizeof(((type)0)->field))

// multimedia\media\avi\avicap.io\pentime.h
  #define pentimeGetDeltaTicks(ppt) pentime.bActive ? pentimeGetMicrosecDelta(ppt) : \
    ((ppt)->dwhi = (ppt)->dwlo, (ppt)->dwlo = timeGetTime(), (ppt)->dwlo - (ppt)->dwhi)
  #define pentimeGetDeltaTicks(ppt) \
    ((ppt)->dwhi = (ppt)->dwlo, (ppt)->dwlo = timeGetTime(), (ppt)->dwlo - (ppt)->dwhi)

// multimedia\media\avi\avicap\avicapi.h
  #define FIELDOFF(type,field)  (&(((type)0)->field))
  #define FIELDSIZ(type,field)  (sizeof(((type)0)->field))

// multimedia\media\avi\avicap\pentime.h
  #define pentimeGetDeltaTicks(ppt) pentime.bActive ? pentimeGetMicrosecDelta(ppt) : \
    ((ppt)->dwhi = (ppt)->dwlo, (ppt)->dwlo = timeGetTime(), (ppt)->dwlo - (ppt)->dwhi)
  #define pentimeGetDeltaTicks(ppt) \
    ((ppt)->dwhi = (ppt)->dwlo, (ppt)->dwlo = timeGetTime(), (ppt)->dwlo - (ppt)->dwhi)

// multimedia\media\avi\avifile.16\avifile.cpp
#define SLASH(c)     ((c) == '/' || (c) == '\\')

// multimedia\media\avi\avifile.16\avifile.h
#define     AVIStreamNextSample(pavi, l) \
            AVIStreamFindSample(pavi,l+1,FIND_NEXT|FIND_ANY)
#define     AVIStreamPrevSample(pavi, l) \
            AVIStreamFindSample(pavi,l-1,FIND_PREV|FIND_ANY)
#define     AVIStreamNearestSample(pavi, l) \
            AVIStreamFindSample(pavi,l,FIND_PREV|FIND_ANY)
#define     AVIStreamNextKeyFrame(pavi,l) \
            AVIStreamFindSample(pavi,l+1,FIND_NEXT|FIND_KEY)
#define     AVIStreamPrevKeyFrame(pavi, l) \
            AVIStreamFindSample(pavi,l-1,FIND_PREV|FIND_KEY)
#define     AVIStreamNearestKeyFrame(pavi, l) \
            AVIStreamFindSample(pavi,l,FIND_PREV|FIND_KEY)

// multimedia\media\avi\avifile.16\editstrm.cpp
#define SIZEMISMATCH(rc1, rc2) \
    (((rc1.right - rc1.left) != (rc2.right - rc2.left)) || \
     ((rc1.bottom - rc1.top) != (rc2.bottom - rc2.top)))

// multimedia\media\avi\avifile\acmcmprs.cpp
#define WAVEFORMATSIZE(pwf) \
	((((LPWAVEFORMAT)(pwf))->wFormatTag == WAVE_FORMAT_PCM) ? \
		sizeof(PCMWAVEFORMAT) : \
		sizeof(WAVEFORMATEX) + ((LPWAVEFORMATEX)(pwf))->cbSize)

// multimedia\media\avi\avifile\acmcmprs\acmcmprs.cpp
#define WAVEFORMATSIZE(pwf) \
	((((LPWAVEFORMAT)(pwf))->wFormatTag == WAVE_FORMAT_PCM) ? \
		sizeof(PCMWAVEFORMAT) : \
		sizeof(WAVEFORMATEX) + ((LPWAVEFORMATEX)(pwf))->cbSize)

// multimedia\media\avi\avifile\avifile.cpp
#define SLASH(c)     ((c) == TEXT('/') || (c) == TEXT('\\'))

// multimedia\media\avi\avifile\avifile.h
#define     AVIStreamNextSample(pavi, l) \
            AVIStreamFindSample(pavi,l+1,FIND_NEXT|FIND_ANY)
#define     AVIStreamPrevSample(pavi, l) \
            AVIStreamFindSample(pavi,l-1,FIND_PREV|FIND_ANY)
#define     AVIStreamNearestSample(pavi, l) \
            AVIStreamFindSample(pavi,l,FIND_PREV|FIND_ANY)
#define     AVIStreamNextKeyFrame(pavi,l) \
            AVIStreamFindSample(pavi,l+1,FIND_NEXT|FIND_KEY)
#define     AVIStreamPrevKeyFrame(pavi, l) \
            AVIStreamFindSample(pavi,l-1,FIND_PREV|FIND_KEY)
#define     AVIStreamNearestKeyFrame(pavi, l) \
            AVIStreamFindSample(pavi,l,FIND_PREV|FIND_KEY)

// multimedia\media\avi\avifile\avifilei.h
#define EnterCrit(pfile)	(EnterCriticalSection(&pfile->m_critsec))
#define LeaveCrit(p)		(LeaveCriticalSection(&pfile->m_critsec))

// multimedia\media\avi\avifile\avilib.cpp
#define CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv) \
		SHCoCreateInstance(NULL, (const CLSID FAR *)&rclsid, pUnkOuter, riid, ppv)

// multimedia\media\avi\avifile\compobj.cpp
#define GUIDSTR_MAX (1+ 3*sizeof(GUID) +sizeof(GUID)-1 +1 +1)
#define CLSIDSTR_MAX (sizeof(aszCLSID)-1+GUIDSTR_MAX)

// multimedia\media\avi\avifile\disk32.c
#define LockList(pHead)    EnterCriticalSection (&pHead->csList)
#define UnlockList(pHead)  LeaveCriticalSection (&pHead->csList)

// multimedia\media\avi\avifile\editstrm.cpp
#define SIZEMISMATCH(rc1, rc2) \
    (((rc1.right - rc1.left) != (rc2.right - rc2.left)) || \
     ((rc1.bottom - rc1.top) != (rc2.bottom - rc2.top)))

// multimedia\media\avi\avifile\wavefile.c
#define SLASH(c)	((c) == TEXT('/') || (c) == TEXT('\\'))

// multimedia\media\avi\compman\compmani.h
  #define FIELDOFF(type,field)  (&(((type)0)->field))
  #define FIELDSIZ(type,field)  (sizeof(((type)0)->field))

// multimedia\media\avi\inc.16\avifile.h
#define     AVIStreamNextSample(pavi, l) \
            AVIStreamFindSample(pavi,l+1,FIND_NEXT|FIND_ANY)
#define     AVIStreamPrevSample(pavi, l) \
            AVIStreamFindSample(pavi,l-1,FIND_PREV|FIND_ANY)
#define     AVIStreamNearestSample(pavi, l) \
            AVIStreamFindSample(pavi,l,FIND_PREV|FIND_ANY)
#define     AVIStreamNextKeyFrame(pavi,l) \
            AVIStreamFindSample(pavi,l+1,FIND_NEXT|FIND_KEY)
#define     AVIStreamPrevKeyFrame(pavi, l) \
            AVIStreamFindSample(pavi,l-1,FIND_PREV|FIND_KEY)
#define     AVIStreamNearestKeyFrame(pavi, l) \
            AVIStreamFindSample(pavi,l,FIND_PREV|FIND_KEY)

// multimedia\media\avi\inc.16\bmpublic.h
#define BMWM_NOTIFYICON                 (WM_USER + 1)
#define BMWM_DESTROY                    (WM_USER + 2)

// multimedia\media\avi\inc.16\commctrl.h
#define TB_ENABLEBUTTON		(WM_USER + 1)
#define TB_CHECKBUTTON		(WM_USER + 2)
#define TB_PRESSBUTTON		(WM_USER + 3)
#define TB_HIDEBUTTON		(WM_USER + 4)
#define TB_INDETERMINATE	(WM_USER + 5)
#define TB_ISBUTTONENABLED	(WM_USER + 9)
#define TB_ISBUTTONCHECKED	(WM_USER + 10)
#define TB_ISBUTTONPRESSED	(WM_USER + 11)
#define TB_ISBUTTONHIDDEN	(WM_USER + 12)
#define TB_ISBUTTONINDETERMINATE    (WM_USER + 13)
#define TB_SETSTATE             (WM_USER + 17)
#define TB_GETSTATE             (WM_USER + 18)
#define TB_ADDBUTTONS		(WM_USER + 20)
#define TB_INSERTBUTTON		(WM_USER + 21)
#define TB_GETBUTTON		(WM_USER + 23)
#define TB_COMMANDTOINDEX	(WM_USER + 25)
#define TB_SAVERESTORE		(WM_USER + 26)
#define TB_CUSTOMIZE            (WM_USER + 27)
#define TB_ADDSTRING		(WM_USER + 28)
#define TB_GETITEMRECT		(WM_USER + 29)
#define TB_SETBUTTONSIZE	(WM_USER + 31)
#define TB_AUTOSIZE		(WM_USER + 33)
#define TB_SETBUTTONTYPE	(WM_USER + 34)
#define TB_GETTOOLTIPS		(WM_USER + 35)
#define TB_SETTOOLTIPS		(WM_USER + 36)
#define TB_SETPARENT		(WM_USER + 37)
#define TB_SETROWS		(WM_USER + 39)
#define TB_GETROWS		(WM_USER + 40)
#define TB_SETCMDID		(WM_USER + 42)
#define TTM_ACTIVATE		(WM_USER + 1)   // wparam = BOOL (true or false  = activate or deactivate)
#define TTM_SETDELAYTIME	(WM_USER + 3)
#define TTM_ADDTOOL		(WM_USER + 4)
#define TTM_DELTOOL		(WM_USER + 5)
#define TTM_NEWTOOLRECT		(WM_USER + 6)
#define TTM_RELAYEVENT		(WM_USER + 7)
#define TTM_GETTOOLINFO    	(WM_USER + 8)
#define TTM_SETTOOLINFO    	(WM_USER + 9)
#define TTM_HITTEST             (WM_USER +10)
#define TTM_GETTEXT             (WM_USER +11)
#define TTM_UPDATETIPTEXT       (WM_USER +12)
#define TTM_ENUMTOOLS           (WM_USER +14)
#define SB_SETTEXT		(WM_USER+1)
#define SB_GETTEXT		(WM_USER+2)
#define SB_SETPARTS		(WM_USER+4)
#define SB_SETBORDERS		(WM_USER+5)
#define SB_GETPARTS		(WM_USER+6)
#define SB_GETBORDERS		(WM_USER+7)
#define SB_SETMINHEIGHT		(WM_USER+8)
#define SB_SIMPLE		(WM_USER+9)
#define SB_GETRECT              (WM_USER + 10)
#define TBM_GETPOS              (WM_USER)
#define TBM_GETRANGEMIN         (WM_USER+1)
#define TBM_GETRANGEMAX         (WM_USER+2)
#define TBM_GETTIC              (WM_USER+3)
#define TBM_SETTIC              (WM_USER+4)
#define TBM_SETPOS              (WM_USER+5)
#define TBM_SETRANGE            (WM_USER+6)
#define TBM_SETRANGEMIN         (WM_USER+7)
#define TBM_SETRANGEMAX         (WM_USER+8)
#define TBM_CLEARTICS           (WM_USER+9)
#define TBM_SETSEL              (WM_USER+10)
#define TBM_SETSELSTART         (WM_USER+11)
#define TBM_SETSELEND           (WM_USER+12)
#define TBM_GETPTICS            (WM_USER+14)
#define TBM_GETTICPOS           (WM_USER+15)
#define TBM_GETNUMTICS          (WM_USER+16)
#define TBM_GETSELSTART         (WM_USER+17)
#define TBM_GETSELEND  	        (WM_USER+18)
#define TBM_CLEARSEL  	        (WM_USER+19)
#define TBM_SETTICFREQ		(WM_USER+20)
#define TBM_SETLINESIZE         (WM_USER+23)
#define TBM_GETLINESIZE         (WM_USER+24)
#define DL_BEGINDRAG    (WM_USER+133)
#define DL_DRAGGING     (WM_USER+134)
#define DL_DROPPED      (WM_USER+135)
#define DL_CANCELDRAG   (WM_USER+136)
#define UDM_SETRANGE		(WM_USER+101)
#define UDM_GETRANGE		(WM_USER+102)
#define UDM_SETPOS		(WM_USER+103)
#define UDM_GETPOS		(WM_USER+104)
#define UDM_SETBUDDY		(WM_USER+105)
#define UDM_GETBUDDY		(WM_USER+106)
#define UDM_SETACCEL		(WM_USER+107)
#define UDM_GETACCEL		(WM_USER+108)
#define PBM_SETRANGE         (WM_USER+1)
#define PBM_SETPOS           (WM_USER+2)
#define PBM_DELTAPOS         (WM_USER+3)
#define PBM_SETSTEP          (WM_USER+4)
#define PBM_STEPIT	     (WM_USER+5)
#define HKM_SETHOTKEY         (WM_USER+1)
#define HKM_GETHOTKEY         (WM_USER+2)
#define HKM_SETRULES         (WM_USER+3)
#define LVHT_ONITEM         (LVHT_ONITEMICON | LVHT_ONITEMLABEL | LVHT_ONITEMSTATEICON)
#define TVHT_ONITEM         (TVHT_ONITEMICON | TVHT_ONITEMLABEL | TVHT_ONITEMSTATEICON)
#define TCHT_ONITEM         (TCHT_ONITEMICON | TCHT_ONITEMLABEL)
#define ACM_OPEN    (WM_USER+100)
#define ACM_PLAY            (WM_USER+101)
#define ACM_STOP            (WM_USER+102)

// multimedia\media\avi\inc.16\commdlg.h
#define CF_BOTH                      (CF_SCREENFONTS | CF_PRINTERFONTS)

// multimedia\media\avi\inc.16\compobj.h
#define CLSCTX_ALL              (CLSCTX_INPROC_SERVER| \
                                 CLSCTX_INPROC_HANDLER| \
                                 CLSCTX_LOCAL_SERVER)
#define CLSCTX_INPROC           (CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER)
#define CLSCTX_SERVER           (CLSCTX_INPROC_SERVER|CLSCTX_LOCAL_SERVER)

// multimedia\media\avi\inc.16\ctype.h
#define isalpha(_c) ( (_ctype+1)[_c] & (_UPPER|_LOWER) )
#define isupper(_c) ( (_ctype+1)[_c] & _UPPER )
#define islower(_c) ( (_ctype+1)[_c] & _LOWER )
#define isdigit(_c) ( (_ctype+1)[_c] & _DIGIT )
#define isxdigit(_c)    ( (_ctype+1)[_c] & _HEX )
#define isspace(_c) ( (_ctype+1)[_c] & _SPACE )
#define ispunct(_c) ( (_ctype+1)[_c] & _PUNCT )
#define isalnum(_c) ( (_ctype+1)[_c] & (_UPPER|_LOWER|_DIGIT) )
#define isprint(_c) ( (_ctype+1)[_c] & (_BLANK|_PUNCT|_UPPER|_LOWER|_DIGIT) )
#define isgraph(_c) ( (_ctype+1)[_c] & (_PUNCT|_UPPER|_LOWER|_DIGIT) )
#define iscntrl(_c) ( (_ctype+1)[_c] & _CONTROL )
#define __toascii(_c)   ( (_c) & 0x7f )
#define __iscsymf(_c)   (isalpha(_c) || ((_c) == '_'))
#define __iscsym(_c)    (isalnum(_c) || ((_c) == '_'))

// multimedia\media\avi\inc.16\ddeml.h
#define     XTYP_ADVSTART           (0x0030 | XCLASS_BOOL          )
#define     XTYP_ADVSTOP            (0x0040 | XCLASS_NOTIFICATION)
#define     XTYP_XACT_COMPLETE      (0x0080 | XCLASS_NOTIFICATION  )
#define     XTYP_REQUEST            (0x00B0 | XCLASS_DATA          )

// multimedia\media\avi\inc.16\dos.h
#define _FP_SEG(fp) (*((unsigned __far *)&(fp)+1))
#define _FP_OFF(fp) (*((unsigned __far *)&(fp)))

// multimedia\media\avi\inc.16\dosdll.h
#define	DLL_GET_DISK_FREE		5				// DllGetDiskFree()
#define	DLL_RELEASE				28				// DllReleaseInstance()

// multimedia\media\avi\inc.16\err.h
#define	ERR_MEM_CORRUPT			-26	// Error returned on MemFree()

// multimedia\media\avi\inc.16\find.h
#define	STRING_LST_LEN		((TRTABLEN + 1) * sizeof(char *))
#define s_text(x) ( ((char *)(x)) + (sizeof( STRINGNODE ) + ((x)->s_must & 1)) )
#define	INIT_LEN		(sizeof( int ) * 8)

// multimedia\media\avi\inc.16\mciwnd.h
#define MCIWNDM_GETDEVICEID	(WM_USER + 100)
#define MCIWNDM_GETSTART	(WM_USER + 103)
#define MCIWNDM_GETEND		(WM_USER + 105)
#define MCIWNDM_EJECT		(WM_USER + 107)
#define MCIWNDM_SETZOOM		(WM_USER + 108)
#define MCIWNDM_GETZOOM         (WM_USER + 109)
#define MCIWNDM_SETVOLUME	(WM_USER + 110)
#define MCIWNDM_GETVOLUME	(WM_USER + 111)
#define MCIWNDM_SETSPEED	(WM_USER + 112)
#define MCIWNDM_GETSPEED	(WM_USER + 113)
#define MCIWNDM_SETREPEAT	(WM_USER + 114)
#define MCIWNDM_GETREPEAT	(WM_USER + 115)
#define MCIWNDM_REALIZE         (WM_USER + 118)
#define MCIWNDM_VALIDATEMEDIA   (WM_USER + 121)
#define MCIWNDM_PLAYFROM	(WM_USER + 122)
#define MCIWNDM_PLAYTO          (WM_USER + 123)
#define MCIWNDM_SETTIMERS	(WM_USER + 129)
#define MCIWNDM_SETACTIVETIMER	(WM_USER + 130)
#define MCIWNDM_SETINACTIVETIMER (WM_USER + 131)
#define MCIWNDM_GETACTIVETIMER	(WM_USER + 132)
#define MCIWNDM_GETINACTIVETIMER (WM_USER + 133)
#define MCIWNDM_CHANGESTYLES	(WM_USER + 135)
#define MCIWNDM_GETSTYLES	(WM_USER + 136)
#define MCIWNDM_GETALIAS	(WM_USER + 137)
#define MCIWNDM_PLAYREVERSE	(WM_USER + 139)
#define MCIWNDM_GET_SOURCE      (WM_USER + 140)
#define MCIWNDM_PUT_SOURCE      (WM_USER + 141)
#define MCIWNDM_GET_DEST        (WM_USER + 142)
#define MCIWNDM_PUT_DEST        (WM_USER + 143)
#define MCIWNDM_CAN_PLAY        (WM_USER + 144)
#define MCIWNDM_CAN_WINDOW      (WM_USER + 145)
#define MCIWNDM_CAN_RECORD      (WM_USER + 146)
#define MCIWNDM_CAN_SAVE        (WM_USER + 147)
#define MCIWNDM_CAN_EJECT       (WM_USER + 148)
#define MCIWNDM_CAN_CONFIG      (WM_USER + 149)
#define MCIWNDM_OPENINTERFACE	(WM_USER + 151)
#define MCIWNDM_SETOWNER	(WM_USER + 152)
#define MCIWNDM_SENDSTRINGA	(WM_USER + 101)
#define MCIWNDM_GETPOSITIONA	(WM_USER + 102)
#define MCIWNDM_GETMODEA	(WM_USER + 106)
#define MCIWNDM_SETTIMEFORMATA  (WM_USER + 119)
#define MCIWNDM_GETTIMEFORMATA  (WM_USER + 120)
#define MCIWNDM_GETFILENAMEA    (WM_USER + 124)
#define MCIWNDM_GETDEVICEA      (WM_USER + 125)
#define MCIWNDM_GETERRORA       (WM_USER + 128)
#define MCIWNDM_NEWA		(WM_USER + 134)
#define MCIWNDM_OPENA		(WM_USER + 153)
#define MCIWNDM_SENDSTRINGW	(WM_USER + 201)
#define MCIWNDM_GETPOSITIONW	(WM_USER + 202)
#define MCIWNDM_GETMODEW	(WM_USER + 206)
#define MCIWNDM_SETTIMEFORMATW  (WM_USER + 219)
#define MCIWNDM_GETTIMEFORMATW  (WM_USER + 220)
#define MCIWNDM_GETFILENAMEW    (WM_USER + 224)
#define MCIWNDM_GETDEVICEW      (WM_USER + 225)
#define MCIWNDM_GETERRORW       (WM_USER + 228)
#define MCIWNDM_NEWW		(WM_USER + 234)
#define MCIWNDM_OPENW		(WM_USER + 252)
#define MCIWNDM_SENDSTRING	(WM_USER + 101)
#define MCIWNDM_GETPOSITION	(WM_USER + 102)
#define MCIWNDM_GETMODE		(WM_USER + 106)
#define MCIWNDM_SETTIMEFORMAT   (WM_USER + 119)
#define MCIWNDM_GETTIMEFORMAT   (WM_USER + 120)
#define MCIWNDM_GETFILENAME     (WM_USER + 124)
#define MCIWNDM_GETDEVICE       (WM_USER + 125)
#define MCIWNDM_GETERROR        (WM_USER + 128)
#define MCIWNDM_NEW		(WM_USER + 134)

// multimedia\media\avi\inc.16\mmsystem.h
#define MIXER_OBJECTF_HMIXER    (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIXER)
#define MIXER_OBJECTF_HWAVEOUT  (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEOUT)
#define MIXER_OBJECTF_HWAVEIN   (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEIN)
#define MIXER_OBJECTF_HMIDIOUT  (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIOUT)
#define MIXER_OBJECTF_HMIDIIN   (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIIN)
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
#define MIXERCONTROL_CONTROLTYPE_SINGLESELECT   (MIXERCONTROL_CT_CLASS_LIST | MIXERCONTROL_CT_SC_LIST_SINGLE | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT (MIXERCONTROL_CT_CLASS_LIST | MIXERCONTROL_CT_SC_LIST_MULTIPLE | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_MICROTIME      (MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MICROSECS | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_MILLITIME      (MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MILLISECS | MIXERCONTROL_CT_UNITS_UNSIGNED)

// multimedia\media\avi\inc.16\penwin.h
#define ALC_PUNC					0x00000008L	// !-;`"?()&.,; and backslash
#define ALC_MATH					0x00000010L	// %^*()-+={}<>,/.
#define MAP_GESTOGES				(RCRT_GESTURE|RCRT_GESTURETRANSLATED)
#define MAP_GESTOVKEYS			(RCRT_GESTURETOKEYS|RCRT_ALREADYPROCESSED)
#define TRAIN_BOTH				(TRAIN_DEFAULT | TRAIN_CUSTOM)
#define PCMR_SELECT				(-12)	// ret because of tap & hold
#define CWR_SINGLELINEEDIT		(CWR_STRIPCR|CWR_STRIPLF|CWR_STRIPTAB)	// all of the above
#define PMI_TIMEOUTSEL				10	// select (press&hold) timeout
#define RCP_MAPCHAR				0x0004	// fill in syg.lpsyc (ink) for training
#define IE_MSGFIRST			(WM_USER+150)		// 0x496 == 1174
#define FIsLoAppGesture(syv)	(syv >= SYV_CIRCLELOA && syv <= SYV_CIRCLELOZ)
#define FIsUpAppGesture(syv)	(syv >= SYV_CIRCLEUPA && syv <= SYV_CIRCLEUPZ)
#define FIsAppGesture(syv)		(syv>=SYV_CIRCLEUPA && syv<=SYV_CIRCLELOZ)
#define AnsiFromSyvAppGesture(syv)		ChSyvToAnsi( \
	syv-(FIsUpAppGesture(syv)? SYV_CIRCLEUPA-(SYV)'A': SYV_CIRCLELOA-(SYV)'a'))
#define IsGestureToGesture(lprcresult) \
	(((lprcresult)->wResultstype & MAP_GESTOGES) == MAP_GESTOGES)
#define IsGestureToVkeys(lprcresult) \
	(((lprcresult)->wResultstype & MAP_GESTOVKEYS) == MAP_GESTOVKEYS)
#define SetAlreadyProcessed(lprcresult) \
	((lprcresult)->wResultsType = ((lprcresult)->wResultsType \
	& ~RCRT_GESTURETOKEYS) | RCRT_ALREADYPROCESSED)
#define FLTAbsTime(at1, at2)\
	((at1).sec < (at2).sec || ((at1).sec == (at2).sec && (at1).ms < (at2).ms))
#define FLTEAbsTime(at1, at2)\
	((at1).sec < (at2).sec || ((at1).sec == (at2).sec && (at1).ms <= (at2).ms))
#define FEQAbsTime(at1, at2)\
	((at1).sec == (at2).sec && (at1).ms == (at2).ms)
#define FAbsTimeInInterval(at, lpi)\
	(FLTEAbsTime((lpi)->atBegin, at) && FLTEAbsTime(at, (lpi)->atEnd))
#define FIntervalInInterval(lpiT, lpiS)\
	(FLTEAbsTime((lpiS)->atBegin, (lpiT)->atBegin)\
	&& FLTEAbsTime((lpiT)->atEnd, (lpiS)->atEnd))
#define FIntervalXInterval(lpiT, lpiS)\
	(!(FLTAbsTime((lpiT)->atEnd, (lpiS)->atBegin)\
	|| FLTAbsTime((lpiS)->atEnd, (lpiT)->atBegin)))
#define MakeAbsTime(lpat, sec, ms) do {\
	(lpat)->sec = sec + ((ms) / 1000);\
	(lpat)->ms = (ms) % 1000;\
	} while (0)
#define SyvCharacterToSymbol(c)	((LONG)(unsigned char)(c) | 0x00010000)
#define SyvKanjiToSymbol(c)		((LONG)(UINT)(c) | 0x00030000)
#define FIsSelectGesture(syv)	\
   ((syv) >= SYVSELECTFIRST && (syv) <= SYVSELECTLAST)

// multimedia\media\avi\inc.16\pif.h
#define LARGEST_GROUP   sizeof(STDPIF)
#define VID_DEFAULT             (VID_TEXTEMULATE | VID_FULLSCREENGRFX | VID_AUTOSUSPEND)
#define FNT_BOTHFONTS           (FNT_RASTERFONTS | FNT_TTFONTS)

// multimedia\media\avi\inc.16\prsht.h
#define PSM_SETCURSEL           (WM_USER + 101)
#define PSM_CHANGED             (WM_USER + 104)
#define PSM_RESTARTWINDOWS            (WM_USER + 105)
#define PSM_REBOOTSYSTEM              (WM_USER + 106)
#define PSM_QUERYSIBLINGS       (WM_USER + 108)
#define PSM_UNCHANGED           (WM_USER + 109)
#define PSM_APPLY               (WM_USER + 110)
#define PSM_SETTITLE            (WM_USER + 111)
#define ID_PSREBOOTSYSTEM   (ID_PSRESTARTWINDOWS | 0x1)

// multimedia\media\avi\inc.16\pwin16.h
#define MAKEMPOINT(l)                   (*((MPOINT FAR *)&(l)))
#define MPOINT2POINT(mpt, pt)           (pt = *(POINT FAR *)&(mpt))
#define POINT2MPOINT(pt, mpt)           (mpt = *(MPOINT FAR *)&(pt))
#define GET_WM_ACTIVATE_STATE(wp, lp)               (wp)
#define GET_WM_CHARTOITEM_CHAR(wp, lp)              (CHAR)(wp)
#define GET_WM_COMMAND_ID(wp, lp)                   (wp)
#define GET_WM_MENUSELECT_CMD(wp, lp)               (wp)
#define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)  \
        (WPARAM)(cmd), MAKELONG(f, hmenu)
#define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW) 0, MAKELONG(hmenuF, hmenuW)
#define GET_WM_MENUCHAR_CHAR(wp, lp)                (CHAR)(wp)
#define GET_WM_MENUCHAR_MPS(ch, hmenu, f)    \
        (WPARAM)(ch), MAKELONG(hmenu, f)
#define GET_WM_PARENTNOTIFY_MSG(wp, lp)             (wp)
#define GET_WM_PARENTNOTIFY2_MPS(msg, x, y) \
        (WPARAM)(msg), MAKELONG(x, y)
#define GET_WM_VKEYTOITEM_CODE(wp, lp)              (wp)
#define GET_WM_HSCROLL_CODE(wp, lp)                 (wp)
#define GET_WM_VSCROLL_CODE(wp, lp)                 (wp)
#define MPostWM_DDE_ADVISE(hTo, hFrom, hOptions, aItem) \
        PostMessage(hTo, WM_DDE_ADVISE, (WPARAM)hFrom, MAKELONG(hOptions, aItem))
#define MPostWM_DDE_DATA(hTo, hFrom, hData, aItem) \
        PostMessage(hTo, WM_DDE_DATA, (WPARAM)hFrom, MAKELONG(hData, aItem))
#define MPostWM_DDE_EXECUTE(hTo, hFrom, hDataExec) \
        PostMessage(hTo, WM_DDE_EXECUTE, (WPARAM)hFrom, MAKELONG(0, hDataExec))
#define MPostWM_DDE_POKE(hTo, hFrom, hData, aItem) \
        PostMessage(hTo, WM_DDE_POKE, (WPARAM)hFrom, MAKELONG(hData, aItem))
#define MPostWM_DDE_REQUEST(hTo, hFrom, fmt, aItem) \
        PostMessage(hTo, WM_DDE_REQUEST, (WPARAM)hFrom, MAKELONG(fmt, aItem))
#define MPostWM_DDE_UNADVISE(hTo, hFrom, fmt, aItem) \
        PostMessage(hTo, WM_DDE_UNADVISE, (WPARAM)hFrom, MAKELONG(fmt, aItem))
#define MPostWM_DDE_TERMINATE(hTo, hFrom) \
        PostMessage(hTo, WM_DDE_TERMINATE, (WPARAM)hFrom, 0)

// multimedia\media\avi\inc.16\scode.h
#define SCODE_CODE(sc)      ((sc) & 0xFFFF)
#define GetScode(hr)        ((SCODE)(hr) & 0x800FFFFF)

// multimedia\media\avi\inc.16\sdmerror.h
#define SDMERR_INVALID_PARAM	(0x80000000 | IDSERR_INVALID_PARAM)
#define SDMERR_OUTOFMEM 	(0x80000000 | IDSERR_OUTOFMEM)
#define SDMERR_REG_ACCESS	(0x80000000 | IDSERR_REG_ACCESS)
#define SDMERR_SD_ALREADYOPEN	(0x80000000 | IDSERR_SD_ALREADYOPEN)
#define SDMERR_SD_NOTOPEN	(0x80000000 | IDSERR_SD_NOTOPEN)
#define SDMERR_HOOK_R0CODE	(0x80000000 | IDSERR_HOOK_R0CODE)
#define SDMERR_DUPINF		(0x80000000 | IDSERR_DUPINF)
#define SDMERR_OPENINF		(0x80000000 | IDSERR_OPENINF)
#define SDMERR_INF_LISTSECT	(0x80000000 | IDSERR_INF_LISTSECT)
#define SDMERR_INF_LISTLINE	(0x80000000 | IDSERR_INF_LISTLINE)
#define SDMERR_INF_MODSECT	(0x80000000 | IDSERR_INF_MODSECT)
#define SDMERR_INF_MODLINE	(0x80000000 | IDSERR_INF_MODLINE)
#define SDMERR_INF_MODNAME	(0x80000000 | IDSERR_INF_MODNAME)
#define SDMERR_INF_FUNCSECT	(0x80000000 | IDSERR_INF_FUNCSECT)
#define SDMERR_INF_FUNCLINE	(0x80000000 | IDSERR_INF_FUNCLINE)
#define SDMERR_LOADMOD		(0x80000000 | IDSERR_LOADMOD)
#define SDMERR_INF_CLASSNAME	(0x80000000 | IDSERR_INF_CLASSNAME)
#define SDMERR_INF_DANGERSECT	(0x80000000 | IDSERR_INF_DANGERSECT)
#define SDMERR_INF_DANGERLINE	(0x80000000 | IDSERR_INF_DANGERLINE)
#define SDMERR_INF_DANGERFORMAT (0x80000000 | IDSERR_INF_DANGERFORMAT)
#define SDMERR_DANGER_INVALID	(0x80000000 | IDSERR_DANGER_INVALID)
#define SDMERR_IOMEM_INVALID	(0x80000000 | IDSERR_IOMEM_INVALID)
#define SDMERR_IOMEM_CONFLICT	(0x80000000 | IDSERR_IOMEM_CONFLICT)
#define SDMERR_IRQDMA_INVALID	(0x80000000 | IDSERR_IRQDMA_INVALID)
#define SDMERR_IRQDMA_CONFLICT	(0x80000000 | IDSERR_IRQDMA_CONFLICT)
#define SDMERR_INF_BUSTYPE	(0x80000000 | IDSERR_INF_BUSTYPE)
#define SDMERR_DETFUNC_DMSERR	(0x80000000 | IDSERR_DETFUNC_DMSERR)
#define SDMERR_DETFUNC_REGERR	(0x80000000 | IDSERR_DETFUNC_REGERR)
#define SDMERR_DETFUNC_ERROR	(0x80000000 | IDSERR_DETFUNC_ERROR)
#define SDMERR_GENINSTALL	(0x80000000 | IDSERR_GENINSTALL)
#define SDMERR_NOSUCH_DEV	(0x80000000 | IDSERR_NOSUCH_DEV)
#define SDMERR_BUFF_TOOSMALL	(0x80000000 | IDSERR_BUFF_TOOSMALL)
#define SDMERR_DEV_ALREADYREG	(0x80000000 | IDSERR_DEV_ALREADYREG)
#define SDMERR_NOT_EISA 	(0x80000000 | IDSERR_NOT_EISA)
#define SDMERR_GETEISACONFIG	(0x80000000 | IDSERR_GETEISACONFIG)
#define SDMERR_INF_CLASS	(0x80000000 | IDSERR_INF_CLASS)
#define SDMERR_DUPFUNC		(0x80000000 | IDSERR_DUPFUNC)
#define SDMERR_NOT_MCA		(0x80000000 | IDSERR_NOT_MCA)
#define SDMERR_ABORT		(0x80000000 | IDSERR_ABORT)
#define SDMERR_GETFUNCADDR	(0x80000000 | IDSERR_GETFUNCADDR)
#define SDMERR_HOOKINT86X	(0x80000000 | IDSERR_HOOKINT86X)
#define SDMERR_QUERYDOSDEV	(0x80000000 | IDSERR_QUERYDOSDEV)
#define SDMERR_INF_RISKCAT	(0x80000000 | IDSERR_INF_RISKCAT)
#define SDMERR_NODOSDEV 	(0x80000000 | IDSERR_NODOSDEV)
#define SDMERR_IOMEM_NOTFOUND	(0x80000000 | IDSERR_IOMEM_NOTFOUND)
#define SDMERR_IRQDMA_NOTFOUND	(0x80000000 | IDSERR_IRQDMA_NOTFOUND)
#define SDMERR_NODOSTSR 	(0x80000000 | IDSERR_NODOSTSR)
#define SDMERR_REGHW_DUP	(0x80000000 | IDSERR_REGHW_DUP)
#define SDMERR_CALLRMPROC	(0x80000000 | IDSERR_CALLRMPROC)
#define SDMERR_NEEDREBOOT	(0x80000000 | IDSERR_NEEDREBOOT)

// multimedia\media\avi\inc.16\setupx.h
#define MAX_FILENAME_LEN    20      // Max. filename length. ( > sizeof( "x:\\12345678.123" )
#define DriveAtoI( chDrv )      ((int)(chDrv & 31))
#define VCPFL_BACKUPANDCOPY     (VCPFL_BACKUP | VCPFL_COPY)
#define GENINSTALL_DO_INIREG    (GENINSTALL_DO_INI | \
                                 GENINSTALL_DO_REG | \
                                 GENINSTALL_DO_INI2REG)

// multimedia\media\avi\inc.16\stdarg.h
#define _INTSIZEOF(n)    ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v) ap = (va_list)&v + _INTSIZEOF(v)

// multimedia\media\avi\inc.16\stdio.h
#define  L_tmpnam sizeof(_P_tmpdir)+8
#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])
#define _stdaux (&_iob[3])
#define _stdprn (&_iob[4])

// multimedia\media\avi\inc.16\style.h
#define LBS_STANDARD      (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

// multimedia\media\avi\inc.16\varargs.h
#define _INTSIZEOF(n)    ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap) ap = (va_list)&va_alist

// multimedia\media\avi\inc.16\variant.h
#define V_ISBYREF(X)     (V_VT(X)&VT_BYREF)
#define V_ISVECTOR(X)    (V_VT(X)&VT_VECTOR)

// multimedia\media\avi\inc.16\version.h
#define VER_PRODUCTVERSION_DW       (0x04000000 | 105)

// multimedia\media\avi\inc.16\wfext.h
#define FM_GETFOCUS		(WM_USER + 0x0200)
#define FM_GETDRIVEINFO		(WM_USER + 0x0201)
#define FM_GETFILESEL		(WM_USER + 0x0204)
#define FM_GETFILESELLFN	(WM_USER + 0x0205)	/* LFN versions are odd */
#define FM_REFRESH_WINDOWS	(WM_USER + 0x0206)
#define FM_RELOAD_EXTENSIONS	(WM_USER + 0x0207)

// multimedia\media\avi\inc.16\win32.h
    #define GET_WM_ACTIVATE_STATE(wp, lp)               (wp)
    #define GET_WM_CHARTOITEM_CHAR(wp, lp)              (CHAR)(wp)
    #define GET_WM_COMMAND_ID(wp, lp)                   (wp)
    #define GET_WM_MENUSELECT_CMD(wp, lp)               (wp)
    #define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)  \
            (WPARAM)(cmd), MAKELONG(f, hmenu)
    #define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW) 0, MAKELONG(hmenuF, hmenuW)
    #define GET_WM_MENUCHAR_CHAR(wp, lp)                (CHAR)(wp)
    #define GET_WM_MENUCHAR_MPS(ch, hmenu, f)    \
            (WPARAM)(ch), MAKELONG(hmenu, f)
    #define GET_WM_PARENTNOTIFY_MSG(wp, lp)             (wp)
    #define GET_WM_PARENTNOTIFY2_MPS(msg, x, y) \
            (WPARAM)(msg), MAKELONG(x, y)
    #define GET_WM_VKEYTOITEM_CODE(wp, lp)              (wp)
    #define GET_WM_HSCROLL_CODE(wp, lp)                 (wp)
    #define GET_WM_VSCROLL_CODE(wp, lp)                 (wp)

// multimedia\media\avi\inc.16\windows.h
#define MAKELPARAM(low, high)   ((LPARAM)MAKELONG(low, high))
#define GHND                (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define LHND                (LMEM_MOVEABLE | LMEM_ZEROINIT)
#define MAKEPOINT(l)     (*((POINT FAR*)&(l)))
#define DCB_SET         (DCB_RESET | DCB_ACCUMULATE)
#define QS_MOUSE        (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#define WVR_REDRAW          (WVR_HREDRAW | WVR_VREDRAW)
#define DM_GETDEFID         (WM_USER+0)
#define DM_SETDEFID         (WM_USER+1)
#define STM_SETICON         (WM_USER+0)
#define STM_GETICON         (WM_USER+1)
#define BM_GETCHECK         (WM_USER+0)
#define BM_SETCHECK         (WM_USER+1)
#define BM_GETSTATE         (WM_USER+2)
#define BM_SETSTATE         (WM_USER+3)
#define BM_SETSTYLE         (WM_USER+4)
#define BM_CLICK            (WM_USER+5)
#define EM_GETSEL               (WM_USER+0)
#define EM_SETSEL               (WM_USER+1)
#define EM_GETRECT              (WM_USER+2)
#define EM_SETRECT              (WM_USER+3)
#define EM_SETRECTNP            (WM_USER+4)
#define EM_LINESCROLL           (WM_USER+6)
#define EM_SCROLLCARET          (WM_USER+7)
#define EM_GETMODIFY            (WM_USER+8)
#define EM_SETMODIFY            (WM_USER+9)
#define EM_LINEINDEX            (WM_USER+11)
#define EM_SETHANDLE            (WM_USER+12)
#define EM_GETHANDLE            (WM_USER+13)
#define EM_REPLACESEL           (WM_USER+18)
#define EM_SETFONT              (WM_USER+19)    /* NOT IMPLEMENTED: use WM_SETFONT */
#define EM_GETLINE              (WM_USER+20)
#define EM_SETLIMITTEXT         (WM_USER+21)
#define EM_CANUNDO              (WM_USER+22)
#define EM_UNDO                 (WM_USER+23)
#define EM_FMTLINES             (WM_USER+24)
#define EM_LINEFROMCHAR         (WM_USER+25)
#define EM_SETTABSTOPS          (WM_USER+27)
#define EM_EMPTYUNDOBUFFER      (WM_USER+29)
#define EM_GETFIRSTVISIBLELINE  (WM_USER+30)
#define EM_SETREADONLY          (WM_USER+31)
#define LBS_STANDARD            (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)
#define LB_ADDSTRING            (WM_USER+1)
#define LB_INSERTSTRING         (WM_USER+2)
#define LB_RESETCONTENT         (WM_USER+5)
#define LB_SETSEL               (WM_USER+6)
#define LB_SETCURSEL            (WM_USER+7)
#define LB_GETSEL               (WM_USER+8)
#define LB_GETCURSEL            (WM_USER+9)
#define LB_GETTEXT              (WM_USER+10)
#define LB_GETTEXTLEN           (WM_USER+11)
#define LB_SELECTSTRING         (WM_USER+13)
#define LB_DIR                  (WM_USER+14)
#define LB_GETTOPINDEX          (WM_USER+15)
#define LB_FINDSTRING           (WM_USER+16)
#define LB_GETSELITEMS          (WM_USER+18)
#define LB_SETTABSTOPS          (WM_USER+19)
#define LB_GETHORIZONTALEXTENT  (WM_USER+20)
#define LB_SETHORIZONTALEXTENT  (WM_USER+21)
#define LB_SETCOLUMNWIDTH       (WM_USER+22)
#define LB_SETTOPINDEX          (WM_USER+24)
#define LB_GETITEMRECT          (WM_USER+25)
#define LB_GETITEMDATA          (WM_USER+26)
#define LB_SETITEMDATA          (WM_USER+27)
#define LB_SELITEMRANGE         (WM_USER+28)
#define LB_SETANCHORINDEX       (WM_USER+29)
#define LB_GETANCHORINDEX       (WM_USER+30)
#define LB_SETCARETINDEX        (WM_USER+31)
#define LB_GETCARETINDEX        (WM_USER+32)
#define LB_SETITEMHEIGHT        (WM_USER+33)
#define LB_GETITEMHEIGHT        (WM_USER+34)
#define LB_FINDSTRINGEXACT      (WM_USER+35)
#define CB_GETEDITSEL           (WM_USER+0)
#define CB_LIMITTEXT            (WM_USER+1)
#define CB_SETEDITSEL           (WM_USER+2)
#define CB_ADDSTRING            (WM_USER+3)
#define CB_DIR                  (WM_USER+5)
#define CB_GETCURSEL            (WM_USER+7)
#define CB_GETLBTEXT            (WM_USER+8)
#define CB_GETLBTEXTLEN         (WM_USER+9)
#define CB_INSERTSTRING         (WM_USER+10)
#define CB_RESETCONTENT         (WM_USER+11)
#define CB_FINDSTRING           (WM_USER+12)
#define CB_SELECTSTRING         (WM_USER+13)
#define CB_SETCURSEL            (WM_USER+14)
#define CB_SHOWDROPDOWN         (WM_USER+15)
#define CB_GETITEMDATA          (WM_USER+16)
#define CB_SETITEMDATA          (WM_USER+17)
#define CB_GETDROPPEDCONTROLRECT (WM_USER+18)
#define CB_SETITEMHEIGHT        (WM_USER+19)
#define CB_GETITEMHEIGHT        (WM_USER+20)
#define CB_SETEXTENDEDUI        (WM_USER+21)
#define CB_GETEXTENDEDUI        (WM_USER+22)
#define CB_GETDROPPEDSTATE      (WM_USER+23)
#define CB_FINDSTRINGEXACT      (WM_USER+24)

// multimedia\media\avi\inc.16\windowsx.h
#define GET_WM_ACTIVATE_STATE(wp, lp)           (wp)
#define GET_WM_CHARTOITEM_CHAR(wp, lp)          ((CHAR)wp)
#define GET_WM_COMMAND_ID(wp, lp)               (wp)
#define GET_WM_MENUSELECT_CMD(wp, lp)               (wp)
#define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)  \
        (WPARAM)cmd, (LPARAM)MAKELONG(f, hmenu)
#define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW)   \
    (WPARAM)TRUE, (LPARAM)MAKELONG(hmenuF, hmenuW)
#define GET_WM_MENUCHAR_CHAR(wp, lp)                (CHAR)(wp)
#define GET_WM_MENUCHAR_MPS(ch, hmenu, f)    \
        (WPARAM)ch, (LPARAM)MAKELONG(f, hmenu)
#define GET_WM_PARENTNOTIFY_MSG(wp, lp)             (wp)
#define GET_WM_PARENTNOTIFY2_MPS(msg, x, y) \
        (WPARAM)msg, (LPARAM)MAKELONG(x, y)
#define GET_WM_VKEYTOITEM_CODE(wp, lp)              (wp)
#define GET_WM_HSCROLL_CODE(wp, lp)                 (wp)
#define GET_WM_VSCROLL_CODE(wp, lp)                 (wp)

// multimedia\media\avi\inc.16\winsock.h
#define FD_CLR(fd, set) do { \
    u_int __i; \
    for (__i = 0; __i < ((fd_set FAR *)(set))->fd_count ; __i++) { \
        if (((fd_set FAR *)(set))->fd_array[__i] == fd) { \
            while (__i < ((fd_set FAR *)(set))->fd_count-1) { \
                ((fd_set FAR *)(set))->fd_array[__i] = \
                    ((fd_set FAR *)(set))->fd_array[__i+1]; \
                __i++; \
            } \
            ((fd_set FAR *)(set))->fd_count--; \
            break; \
        } \
    } \
} while(0)
#define FD_SET(fd, set) do { \
    if (((fd_set FAR *)(set))->fd_count < FD_SETSIZE) \
        ((fd_set FAR *)(set))->fd_array[((fd_set FAR *)(set))->fd_count++]=fd;\
} while(0)
#define timerisset(tvp)         ((tvp)->tv_sec || (tvp)->tv_usec)
#define timercmp(tvp, uvp, cmp) \
        ((tvp)->tv_sec cmp (uvp)->tv_sec || \
         (tvp)->tv_sec == (uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#define IOC_INOUT       (IOC_IN|IOC_OUT)
#define IPPROTO_GGP             2               /* gateway^2 (deprecated) */
#define IN_CLASSA(i)            (((long)(i) & 0x80000000) == 0)
#define IN_CLASSB(i)            (((long)(i) & 0xc0000000) == 0x80000000)
#define IN_CLASSC(i)            (((long)(i) & 0xe0000000) == 0xc0000000)
#define INVALID_SOCKET  (SOCKET)(~0)
#define SO_DONTLINGER   (u_int)(~SO_LINGER)

// multimedia\media\avi\inc\aviffmt.h
#define AVIIF_MIDPART       (AVIIF_LASTPART|AVIIF_FIRSTPART)

// multimedia\media\avi\inc\avifmt.h
#define AVIIF_MIDPART       (AVIIF_LASTPART|AVIIF_FIRSTPART)

// multimedia\media\avi\inc\mediaman.h
#define medInfoInstance(medinfo)	((LPSTR) &((medinfo)->achInst[0]))

// multimedia\media\avi\inc\wincom.h
#define DLGOPEN_SETEXTEN	(WM_USER + 3)	// sets default extensions
#define DLGOPEN_CHANGED		(WM_USER + 6)	// edit box has been changed
#define DLGOPEN_RESETDIR	(WM_USER + 7)	// directory change
#define DOS_FILES	(DOS_READONLY | DOS_SYSTEM)
#define DOS_ALL		(DOS_FILES | DOS_DIRECTORY | DOS_HIDDEN)
#define BAR_SETRANGE	(WM_USER + 0)
#define BAR_SETPOS	(WM_USER + 2)
#define BAR_DELTAPOS	(WM_USER + 4)
#define ST_SETRIGHTSIDE		(WM_USER + 1)
#define ST_GETRIGHTSIDE		(WM_USER + 2)
#define CM_SETITEMRECTSIZE	(WM_USER + 1)
#define CM_CALCSIZE		(WM_USER + 2)
#define CM_ADDITEM		(WM_USER + 3)
#define CM_INSERTITEM		(WM_USER + 4)
#define CM_GETITEMDATA		(WM_USER + 7)
#define CM_GETCURSEL		(WM_USER + 8)
#define CM_SETCURSEL		(WM_USER + 9)
#define CM_FINDITEM		(WM_USER + 10)
#define WPF_GETNLINES	(WM_USER + 2)
#define WPF_SETTABSTOPS	(WM_USER + 4)
#define WPF_GETTABSTOPS	(WM_USER + 5)
#define WPF_GETNUMTABS	(WM_USER + 6)
#define WPF_SETOUTPUT	(WM_USER + 7)
#define WPF_GETOUTPUT	(WM_USER + 8)
#define WPF_CLEARWINDOW (WM_USER + 9)

// multimedia\media\avi\mciavi.16\aviffmt.h
#define AVIIF_MIDPART       (AVIIF_LASTPART|AVIIF_FIRSTPART)

// multimedia\media\avi\mciavi.16\graphic.c
#define SLASH(c)     ((c) == TEXT('/') || (c) == TEXT('\\'))

// multimedia\media\avi\mciavi.16\ntaviprt.h
#define EnterCrit(p)  { EnterCriticalSection(&(p)->CritSec); 	\
			if ((p)->lCritRefCount++ > 0)	\
	LeaveCriticalSection(&(p)->CritSec);\
                      }
#define LeaveCrit(p)  { if (--(p)->lCritRefCount <= 0) {	\
				LeaveCriticalSection(&(p)->CritSec);\
                                Sleep(0);               \
                        }				\
                      }

// multimedia\media\avi\mciavi32\avidraw.c
    #define GETDCORG(hdc, dwOrg)  GetDCOrgEx(hdc, &dwOrg)

// multimedia\media\avi\mciavi32\aviffmt.h
#define AVIIF_MIDPART       (AVIIF_LASTPART|AVIIF_FIRSTPART)

// multimedia\media\avi\mciavi32\aviplay.c
#define AllocMem(dw) GlobalLock(GlobalAlloc(GMEM_MOVEABLE|GMEM_SHARE, (dw)))

// multimedia\media\avi\mciavi32\avitask.h
#define AVIM_DESTROY		(WM_USER+103)
#define AVIM_SHOWSTAGE		(WM_USER+104)

// multimedia\media\avi\mciavi32\graphic.c
#define SLASH(c)     ((c) == TEXT('/') || (c) == TEXT('\\'))

// multimedia\media\avi\mciavi32\graphic.h
#define EnterList()   { EnterCriticalSection(&MCIListCritSec);  \
			ListOwner=GetCurrentThreadId();\
		      }
#define LeaveList()   { ListOwner=0;\
			LeaveCriticalSection(&MCIListCritSec);\
		      }
#define EnterList()   EnterCriticalSection(&MCIListCritSec);
#define LeaveList()   LeaveCriticalSection(&MCIListCritSec);
#define EnterWinCrit(p) {   EnterCriticalSection(&(p)->WinCritSec);     \
			    (p)->WinCritSecOwner=GetCurrentThreadId();  \
			    /* The first enter should mean that we do */\
			    /* NOT own the HDC critical section       */\
			    if (!((p)->WinCritSecDepth++))              \
				{ HDCCritCheckOut(p) };                 \
			}
#define EnterHDCCrit(p) {   EnterCriticalSection(&(p)->HDCCritSec);     \
			    (p)->HDCCritSecOwner=GetCurrentThreadId();  \
			    (p)->HDCCritSecDepth++;                     \
			}
#define EnterWinCrit(npMCI)     EnterCriticalSection(&npMCI->WinCritSec)
#define LeaveWinCrit(npMCI)     LeaveCriticalSection(&npMCI->WinCritSec)
#define EnterHDCCrit(npMCI)     EnterCriticalSection(&npMCI->HDCCritSec)
#define LeaveHDCCrit(npMCI)     LeaveCriticalSection(&npMCI->HDCCritSec)

// multimedia\media\avi\mciavi32\window.c
    #define GETDCORG(hdc, dwOrg)  GetDCOrgEx(hdc, &dwOrg)

// multimedia\media\avi\mciwnd.16\commctrl.h
#define TB_ENABLEBUTTON	(WM_USER + 1)
#define TB_CHECKBUTTON	(WM_USER + 2)
#define TB_PRESSBUTTON	(WM_USER + 3)
#define TB_HIDEBUTTON	(WM_USER + 4)
#define TB_INDETERMINATE	(WM_USER + 5)
#define TB_ISBUTTONENABLED	(WM_USER + 9)
#define TB_ISBUTTONCHECKED	(WM_USER + 10)
#define TB_ISBUTTONPRESSED	(WM_USER + 11)
#define TB_ISBUTTONHIDDEN	(WM_USER + 12)
#define TB_ISBUTTONINDETERMINATE	(WM_USER + 13)
#define TB_SETSTATE             (WM_USER + 17)
#define TB_GETSTATE             (WM_USER + 18)
#define TB_ADDBUTTONS		(WM_USER + 20)
#define TB_INSERTBUTTON		(WM_USER + 21)
#define TB_GETBUTTON		(WM_USER + 23)
#define TB_COMMANDTOINDEX	(WM_USER + 25)
#define TB_SAVERESTORE		(WM_USER + 26)
#define TB_CUSTOMIZE            (WM_USER + 27)
#define TB_ADDSTRING		(WM_USER + 28)
#define TB_GETITEMRECT		(WM_USER + 29)
#define TB_SETBUTTONSIZE	(WM_USER + 31)
#define TB_AUTOSIZE		(WM_USER + 33)
#define TB_SETBUTTONTYPE	(WM_USER + 34)
#define SB_SETTEXT		(WM_USER+1)
#define SB_GETTEXT		(WM_USER+2)
#define SB_SETPARTS		(WM_USER+4)
#define SB_SETBORDERS		(WM_USER+5)
#define SB_GETPARTS		(WM_USER+6)
#define SB_GETBORDERS		(WM_USER+7)
#define SB_SETMINHEIGHT		(WM_USER+8)
#define SB_SIMPLE		(WM_USER+9)
#define HB_SAVERESTORE		(WM_USER+256)
#define HB_ADJUST		(WM_USER+257)
#define HB_GETPARTS		(WM_USER+258)
#define HB_SHOWTOGGLE		(WM_USER+259)
#define BL_ADDBUTTON        (WM_USER+1)
#define BL_GETCARETINDEX    (WM_USER+3)
#define BL_GETCURSEL        (WM_USER+5)
#define BL_GETITEMDATA      (WM_USER+6)
#define BL_GETITEMRECT      (WM_USER+7)
#define BL_GETTEXT          (WM_USER+8)
#define BL_GETTEXTLEN       (WM_USER+9)
#define BL_GETTOPINDEX      (WM_USER+10)
#define BL_INSERTBUTTON     (WM_USER+11)
#define BL_RESETCONTENT     (WM_USER+12)
#define BL_SETCARETINDEX    (WM_USER+13)
#define BL_SETCURSEL        (WM_USER+14)
#define BL_SETITEMDATA      (WM_USER+15)
#define BL_SETTOPINDEX      (WM_USER+16)
#define BL_MSGMAX           (WM_USER+17) /* ;Internal */
#define TBM_GETPOS              (WM_USER)
#define TBM_GETRANGEMIN         (WM_USER+1)
#define TBM_GETRANGEMAX         (WM_USER+2)
#define TBM_GETTIC              (WM_USER+3)
#define TBM_SETTIC              (WM_USER+4)
#define TBM_SETPOS              (WM_USER+5)
#define TBM_SETRANGE            (WM_USER+6)
#define TBM_SETRANGEMIN         (WM_USER+7)
#define TBM_SETRANGEMAX         (WM_USER+8)
#define TBM_CLEARTICS           (WM_USER+9)
#define TBM_SETSEL              (WM_USER+10)
#define TBM_SETSELSTART         (WM_USER+11)
#define TBM_SETSELEND           (WM_USER+12)
#define TBM_GETPTICS            (WM_USER+14)
#define TBM_GETTICPOS           (WM_USER+15)
#define TBM_GETNUMTICS          (WM_USER+16)
#define TBM_GETSELSTART         (WM_USER+17)
#define TBM_GETSELEND  	        (WM_USER+18)
#define TBM_CLEARSEL  	        (WM_USER+19)
#define UDM_SETRANGE		(WM_USER+101)
#define UDM_GETRANGE		(WM_USER+102)
#define UDM_SETPOS		(WM_USER+103)
#define UDM_GETPOS		(WM_USER+104)
#define UDM_SETBUDDY		(WM_USER+105)
#define UDM_GETBUDDY		(WM_USER+106)
#define UDM_SETACCEL		(WM_USER+107)
#define UDM_GETACCEL		(WM_USER+108)
#define PBM_SETRANGE         (WM_USER+1)
#define PBM_SETPOS           (WM_USER+2)
#define PBM_DELTAPOS         (WM_USER+3)
#define PBM_SETSTEP          (WM_USER+4)
#define PBM_STEPIT	     (WM_USER+5)

// multimedia\media\avi\mciwnd.16\mciwnd.c
#define SLASH(c)     ((c) == '/' || (c) == '\\')
#define SLASH(c)     ((c) == '/' || (c) == '\\')

// multimedia\media\avi\mciwnd.16\mciwnd.h
#define MCIWNDM_GETDEVICEID	(WM_USER + 100)
#define MCIWNDM_SENDSTRING	(WM_USER + 101)
#define MCIWNDM_GETPOSITION	(WM_USER + 102)
#define MCIWNDM_GETSTART	(WM_USER + 103)
#define MCIWNDM_GETEND		(WM_USER + 105)
#define MCIWNDM_GETMODE		(WM_USER + 106)
#define MCIWNDM_EJECT		(WM_USER + 107)
#define MCIWNDM_SETZOOM		(WM_USER + 108)
#define MCIWNDM_GETZOOM         (WM_USER + 109)
#define MCIWNDM_SETVOLUME	(WM_USER + 110)
#define MCIWNDM_GETVOLUME	(WM_USER + 111)
#define MCIWNDM_SETSPEED	(WM_USER + 112)
#define MCIWNDM_GETSPEED	(WM_USER + 113)
#define MCIWNDM_SETREPEAT	(WM_USER + 114)
#define MCIWNDM_GETREPEAT	(WM_USER + 115)
#define MCIWNDM_REALIZE         (WM_USER + 118)
#define MCIWNDM_SETTIMEFORMAT   (WM_USER + 119)
#define MCIWNDM_GETTIMEFORMAT   (WM_USER + 120)
#define MCIWNDM_VALIDATEMEDIA   (WM_USER + 121)
#define MCIWNDM_PLAYFROM	(WM_USER + 122)
#define MCIWNDM_PLAYTO          (WM_USER + 123)
#define MCIWNDM_GETFILENAME     (WM_USER + 124)
#define MCIWNDM_GETDEVICE       (WM_USER + 125)
#define MCIWNDM_GETERROR        (WM_USER + 128)
#define MCIWNDM_SETTIMERS	(WM_USER + 129)
#define MCIWNDM_SETACTIVETIMER	(WM_USER + 130)
#define MCIWNDM_SETINACTIVETIMER (WM_USER + 131)
#define MCIWNDM_GETACTIVETIMER	(WM_USER + 132)
#define MCIWNDM_GETINACTIVETIMER (WM_USER + 133)
#define MCIWNDM_NEW		(WM_USER + 134)
#define MCIWNDM_CHANGESTYLES	(WM_USER + 135)
#define MCIWNDM_GETSTYLES	(WM_USER + 136)
#define MCIWNDM_GETALIAS	(WM_USER + 137)
#define MCIWNDM_PLAYREVERSE	(WM_USER + 139)
#define MCIWNDM_GET_SOURCE      (WM_USER + 140)
#define MCIWNDM_PUT_SOURCE      (WM_USER + 141)
#define MCIWNDM_GET_DEST        (WM_USER + 142)
#define MCIWNDM_PUT_DEST        (WM_USER + 143)
#define MCIWNDM_CAN_PLAY        (WM_USER + 144)
#define MCIWNDM_CAN_WINDOW      (WM_USER + 145)
#define MCIWNDM_CAN_RECORD      (WM_USER + 146)
#define MCIWNDM_CAN_SAVE        (WM_USER + 147)
#define MCIWNDM_CAN_EJECT       (WM_USER + 148)
#define MCIWNDM_CAN_CONFIG      (WM_USER + 149)
#define MCIWNDM_OPENINTERFACE	(WM_USER + 151)
#define MCIWNDM_SETOWNER	(WM_USER + 152)

// multimedia\media\avi\mciwnd.16\mciwndi.h
#define LoadSz(ID) (LoadString(hInst, ID, szString, sizeof(szString)), szString)

// multimedia\media\avi\mciwnd.16\preview.c
#define SLASH(c)     ((c) == '/' || (c) == '\\')

// multimedia\media\avi\mciwnd\mciwnd.c
#define SLASH(c)     ((c) == TEXT('/') || (c) == TEXT('\\'))
#define SLASH(c)     ((c) == TEXT('/') || (c) == TEXT('\\'))

// multimedia\media\avi\mciwnd\mciwnd.h
#define MCIWNDM_GETDEVICEID	(WM_USER + 100)
#define MCIWNDM_GETSTART	(WM_USER + 103)
#define MCIWNDM_GETEND		(WM_USER + 105)
#define MCIWNDM_EJECT		(WM_USER + 107)
#define MCIWNDM_SETZOOM		(WM_USER + 108)
#define MCIWNDM_GETZOOM         (WM_USER + 109)
#define MCIWNDM_SETVOLUME	(WM_USER + 110)
#define MCIWNDM_GETVOLUME	(WM_USER + 111)
#define MCIWNDM_SETSPEED	(WM_USER + 112)
#define MCIWNDM_GETSPEED	(WM_USER + 113)
#define MCIWNDM_SETREPEAT	(WM_USER + 114)
#define MCIWNDM_GETREPEAT	(WM_USER + 115)
#define MCIWNDM_REALIZE         (WM_USER + 118)
#define MCIWNDM_VALIDATEMEDIA   (WM_USER + 121)
#define MCIWNDM_PLAYFROM	(WM_USER + 122)
#define MCIWNDM_PLAYTO          (WM_USER + 123)
#define MCIWNDM_SETTIMERS	(WM_USER + 129)
#define MCIWNDM_SETACTIVETIMER	(WM_USER + 130)
#define MCIWNDM_SETINACTIVETIMER (WM_USER + 131)
#define MCIWNDM_GETACTIVETIMER	(WM_USER + 132)
#define MCIWNDM_GETINACTIVETIMER (WM_USER + 133)
#define MCIWNDM_CHANGESTYLES	(WM_USER + 135)
#define MCIWNDM_GETSTYLES	(WM_USER + 136)
#define MCIWNDM_GETALIAS	(WM_USER + 137)
#define MCIWNDM_PLAYREVERSE	(WM_USER + 139)
#define MCIWNDM_GET_SOURCE      (WM_USER + 140)
#define MCIWNDM_PUT_SOURCE      (WM_USER + 141)
#define MCIWNDM_GET_DEST        (WM_USER + 142)
#define MCIWNDM_PUT_DEST        (WM_USER + 143)
#define MCIWNDM_CAN_PLAY        (WM_USER + 144)
#define MCIWNDM_CAN_WINDOW      (WM_USER + 145)
#define MCIWNDM_CAN_RECORD      (WM_USER + 146)
#define MCIWNDM_CAN_SAVE        (WM_USER + 147)
#define MCIWNDM_CAN_EJECT       (WM_USER + 148)
#define MCIWNDM_CAN_CONFIG      (WM_USER + 149)
#define MCIWNDM_OPENINTERFACE	(WM_USER + 151)
#define MCIWNDM_SETOWNER	(WM_USER + 152)
#define MCIWNDM_SENDSTRINGA	(WM_USER + 101)
#define MCIWNDM_GETPOSITIONA	(WM_USER + 102)
#define MCIWNDM_GETMODEA	(WM_USER + 106)
#define MCIWNDM_SETTIMEFORMATA  (WM_USER + 119)
#define MCIWNDM_GETTIMEFORMATA  (WM_USER + 120)
#define MCIWNDM_GETFILENAMEA    (WM_USER + 124)
#define MCIWNDM_GETDEVICEA      (WM_USER + 125)
#define MCIWNDM_GETERRORA       (WM_USER + 128)
#define MCIWNDM_NEWA		(WM_USER + 134)
#define MCIWNDM_OPENA		(WM_USER + 153)
#define MCIWNDM_SENDSTRINGW	(WM_USER + 201)
#define MCIWNDM_GETPOSITIONW	(WM_USER + 202)
#define MCIWNDM_GETMODEW	(WM_USER + 206)
#define MCIWNDM_SETTIMEFORMATW  (WM_USER + 219)
#define MCIWNDM_GETTIMEFORMATW  (WM_USER + 220)
#define MCIWNDM_GETFILENAMEW    (WM_USER + 224)
#define MCIWNDM_GETDEVICEW      (WM_USER + 225)
#define MCIWNDM_GETERRORW       (WM_USER + 228)
#define MCIWNDM_NEWW		(WM_USER + 234)
#define MCIWNDM_OPENW		(WM_USER + 252)
#define MCIWNDM_SENDSTRING	(WM_USER + 101)
#define MCIWNDM_GETPOSITION	(WM_USER + 102)
#define MCIWNDM_GETMODE		(WM_USER + 106)
#define MCIWNDM_SETTIMEFORMAT   (WM_USER + 119)
#define MCIWNDM_GETTIMEFORMAT   (WM_USER + 120)
#define MCIWNDM_GETFILENAME     (WM_USER + 124)
#define MCIWNDM_GETDEVICE       (WM_USER + 125)
#define MCIWNDM_GETERROR        (WM_USER + 128)
#define MCIWNDM_NEW		(WM_USER + 134)

// multimedia\media\avi\mciwnd\preview.c
#define SLASH(c)     ((c) == TEXT('/') || (c) == TEXT('\\'))

// multimedia\media\avi\msvidc\compress.c
#define SUMSQ(a,b)                          \
    if (a > b)                              \
        dw += (UINT)(a-b) * (UINT)(a-b);    \
    else                                    \
        dw += (UINT)(b-a) * (UINT)(b-a);

// multimedia\media\avi\msvidc\decmprss.c
#define DITHER16TO8(col, x, y)		lpLookup[col + ditherr[(y)&3][(x)&3]]

// multimedia\media\avi\vidcap32\rlmeter.c
#define WD_PREVMAX  (WD_MAX + sizeof(UINT))     // currently drawn max
#define WD_PREVLVL  (WD_PREVMAX + sizeof(UINT)) // currently drawn level
#define WD_PEN      (WD_PREVLVL + sizeof(UINT)) // pen for max line

// multimedia\media\avi\vidcap32\rlmeter.h
#define WMRL_SETLEVEL   (WM_USER+1)

// multimedia\media\avi\vidcap32\vidcap.h
#define IsDriverIndex(w) ( ((w) >= IDM_O_DRIVERS)  &&  \
                           ((w) - IDM_O_DRIVERS < MAXVIDDRIVERS) )

// multimedia\media\cdplayer\cdapi.h
#define CD_SEEKING          (CD_FF | CD_RW)
#define CDROM_TOC_SIZE sizeof(CDROM_TOC)

// multimedia\media\cdplayer\cdplayer.h
    #define NUMELEMS(a) (sizeof((a))/sizeof((a)[0]))

// multimedia\media\deluxe2\cdopt\cddata.cpp
#define SQL_SUCCEEDED(rc) (((rc)&(~1))==0)

// multimedia\media\deluxe2\cdopt\cdoptimp.h
#define CDINFO_TRACK        (CDINFO_EDIT | 0x0010)
#define CDINFO_TITLE        (CDINFO_EDIT | 0x0020)
#define CDINFO_ARTIST       (CDINFO_EDIT | 0x0040)
#define CDINFO_DISC         (CDINFO_NOEDIT | 0x0020)
#define CDINFO_ALBUMS       (CDINFO_NOEDIT | 0x0080)
#define CDINFO_DRIVES       (CDINFO_NOEDIT | 0x0100)
#define CDINFO_LABEL        (CDINFO_NOEDIT | 0x0200)
#define CDINFO_CDROM        (CDINFO_NOEDIT | 0x0400)
#define CDINFO_OTHER        (CDINFO_NOEDIT | 0x0800)

// multimedia\media\deluxe2\cdplay\cdapi.h
#define CD_SEEKING          (CD_FF | CD_RW)
#define CDROM_TOC_SIZE sizeof(CDROM_TOC)

// multimedia\media\deluxe2\cdplay\cdplayer.h
    #define NUMELEMS(a) (sizeof((a))/sizeof((a)[0]))

// multimedia\media\deluxe2\main\mbutton.h
#define IS_DBCS_CHARSET( CharSet )									\
                   ( ((CharSet) == SHIFTJIS_CHARSET)    ? TRUE :       \
                     ((CharSet) == HANGEUL_CHARSET)     ? TRUE :       \
                     ((CharSet) == CHINESEBIG5_CHARSET) ? TRUE :       \
                     ((CharSet) == GB2312_CHARSET)      ? TRUE :       \
                     ((CharSet) == JOHAB_CHARSET)	? TRUE : FALSE \
                   )

// multimedia\media\deluxe2\main\shellico.h
#define SHELLMESSAGE_CDICON (WM_USER+210)

// multimedia\media\deluxecd\cdopt\cddata.cpp
#define SQL_SUCCEEDED(rc) (((rc)&(~1))==0)

// multimedia\media\deluxecd\cdopt\cdoptimp.h
#define CDINFO_TRACK        (CDINFO_EDIT | 0x0010)
#define CDINFO_TITLE        (CDINFO_EDIT | 0x0020)
#define CDINFO_ARTIST       (CDINFO_EDIT | 0x0040)
#define CDINFO_DISC         (CDINFO_NOEDIT | 0x0020)
#define CDINFO_ALBUMS       (CDINFO_NOEDIT | 0x0080)
#define CDINFO_DRIVES       (CDINFO_NOEDIT | 0x0100)
#define CDINFO_LABEL        (CDINFO_NOEDIT | 0x0200)
#define CDINFO_CDROM        (CDINFO_NOEDIT | 0x0400)
#define CDINFO_OTHER        (CDINFO_NOEDIT | 0x0800)

// multimedia\media\deluxecd\cdplay\cdapi.h
#define CD_SEEKING          (CD_FF | CD_RW)
#define CDROM_TOC_SIZE sizeof(CDROM_TOC)

// multimedia\media\deluxecd\cdplay\cdplayer.h
    #define NUMELEMS(a) (sizeof((a))/sizeof((a)[0]))

// multimedia\media\deluxecd\main\mbutton.h
#define IS_DBCS_CHARSET( CharSet )									\
                   ( ((CharSet) == SHIFTJIS_CHARSET)    ? TRUE :       \
                     ((CharSet) == HANGEUL_CHARSET)     ? TRUE :       \
                     ((CharSet) == CHINESEBIG5_CHARSET) ? TRUE :       \
                     ((CharSet) == GB2312_CHARSET)      ? TRUE :       \
                     ((CharSet) == JOHAB_CHARSET)	? TRUE : FALSE \
                   )

// multimedia\media\deluxecd\main\shellico.h
#define SHELLMESSAGE_CDICON (WM_USER+210)

// multimedia\media\dplay\dplay\dpimp.cpp
#define Lock()   EnterCriticalSection( &g_critSection )
#define Unlock() LeaveCriticalSection( &g_critSection )

// multimedia\media\dplay\dpwsock\dpspimp.h
#define MAX_MSG      (512 + sizeof(DPHDR))
#define SIZE_GENERIC (sizeof(SPMSG_GENERIC) - sizeof(DPHDR))
#define SIZE_GETPLAYER  (sizeof(SPMSG_GETPLAYER) - sizeof(DPHDR))
#define SIZE_ADDPLAYER (sizeof(SPMSG_ADDPLAYER) - sizeof(DPHDR))
#define SIZE_SETPLAYER (sizeof(SPMSG_SETPLAYER) - sizeof(DPHDR))
#define SIZE_PING (sizeof(SPMSG_PING) - sizeof(DPHDR))
#define SIZE_GETPLAYERCAPS (sizeof(SPMSG_GETPLAYERCAPS) - sizeof(DPHDR))
#define SIZE_SENDDESC (sizeof(SPMSG_SENDDESC) - sizeof(DPHDR))

// multimedia\media\dplay\dpwsock\wsnetbs.h
#define SET_NETBIOS_SOCKADDR(_snb,_type,_name,_port)                          \
    {                                                                         \
        int _i;                                                               \
        (_snb)->snb_family = AF_NETBIOS;                                      \
        (_snb)->snb_type = (_type);                                           \
        for (_i=0; _i<NETBIOS_NAME_LENGTH-1; _i++) {                          \
            (_snb)->snb_name[_i] = ' ';                                       \
        }                                                                     \
        for (_i=0; *((_name)+_i) != '\0' && _i<NETBIOS_NAME_LENGTH-1; _i++) { \
            (_snb)->snb_name[_i] = *((_name)+_i);                             \
        }                                                                     \
        (_snb)->snb_name[NETBIOS_NAME_LENGTH-1] = (_port);                    \
    }

// multimedia\media\dplay\serial\dpspimp.h
#define MAX_MSG      (512 + sizeof(DPHDR))
#define SIZE_GENERIC (sizeof(SPMSG_GENERIC) - sizeof(DPHDR))
#define SIZE_GETPLAYER  (sizeof(SPMSG_GETPLAYER) - sizeof(DPHDR))
#define SIZE_ADDPLAYER (sizeof(SPMSG_ADDPLAYER) - sizeof(DPHDR))
#define SIZE_PING (sizeof(SPMSG_PING) - sizeof(DPHDR))
#define SIZE_GETPLAYERCAPS (sizeof(SPMSG_GETPLAYERCAPS) - sizeof(DPHDR))
#define SIZE_SENDDESC (sizeof(SPMSG_SENDDESC) - sizeof(DPHDR))

// multimedia\media\dplayx\dplay\dplay\bilink.h
#define BilinkToList( _pBilink ) \
	(_pBilink)->prev->next=NULL;
#define InitBilink( _pBilink ) \
    (_pBilink)->prev=(_pBilink)->next=(_pBilink);

// multimedia\media\dplayx\dplay\dplay\dpcpl.h
#define FILE_MAP_SIZE sizeof(DP_PERFDATA)

// multimedia\media\dplayx\dplay\dplay\dplay.h
#define DPSEND_SYSMESS              (DPSEND_GUARANTEE|DPSEND_ASYNC)

// multimedia\media\dplayx\dplay\dplay\dpmem.c
#define ENTER_DPMEM() EnterCriticalSection(&gcsMemoryCritSection);
#define LEAVE_DPMEM() LeaveCriticalSection(&gcsMemoryCritSection);

// multimedia\media\dplayx\dplay\dplay\dpmem.h
#define INIT_DPMEM_CSECT() InitializeCriticalSection(&gcsMemoryCritSection);

// multimedia\media\dplayx\dplay\dplay\dpmess.h
#define GET_MESSAGE_SIZE(this,MSG) (this->dwSPHeaderSize + sizeof(MSG))

// multimedia\media\dplayx\dplay\dplay\dpsecure.h
#define DPLAY_SECURITY_CONTEXT_REQ (ISC_REQ_CONFIDENTIALITY | \
                                    ISC_REQ_USE_SESSION_KEY | \
                                    ISC_REQ_REPLAY_DETECT)

// multimedia\media\dplayx\dplay\dplay\handler.c
				#define DPLAYI_PLAYER_LOCALAPPSERVER (DPLAYI_PLAYER_APPSERVER|DPLAYI_PLAYER_PLAYERLOCAL)

// multimedia\media\dplayx\dplay\dplaysvr\dplaysvr.h
#define INIT_DPLAYSVR_CSECT() InitializeCriticalSection(&gcsCritSection);
#define ENTER_DPLAYSVR() EnterCriticalSection(&gcsCritSection),gnCSCount++;
#define ENTER_DPLAYSVR() EnterCriticalSection(&gcsCritSection);
#define LEAVE_DPLAYSVR() LeaveCriticalSection(&gcsCritSection);

// multimedia\media\dplayx\dplay\protocol\bilink.h
#define BilinkToList( _pBilink ) \
	(_pBilink)->prev->next=NULL;
#define InitBilink( _pBilink ) \
    (_pBilink)->prev=(_pBilink)->next=(_pBilink);

// multimedia\media\dplayx\dplay\protocol\protocol.c
	#define ALL_PROTOCOLCAPS	(DPCAPS_SENDPRIORITYSUPPORTED | \
								 DPCAPS_ASYNCSUPPORTED        | \
								 DPCAPS_SENDTIMEOUTSUPPORTED  | \
								 DPCAPS_ASYNCCANCELSUPPORTED  )

// multimedia\media\dplayx\dplay\protocol\protocol.h
#define MAX_SYS_HEADER (sizeof(NACK2)+(128/8)+sizeof(MSG_PROTOCOL))

// multimedia\media\dplayx\dplay\protocol\receive.c
	#define pABT        ((pABT1)(&pData[iEOF]))
	#define pBigABT     ((pABT2)(&pData[iEOF]))
	#define pNACK       ((pNACK1)(&pData[iEOA]))
	#define pBigNACK    ((pNACK2)(&pData[iEOA]))
	#define pCMD        ((pCMD1)(&pData[iEON]))
	#define pBigCMD     ((pCMD2)(&pData[iEON]))

// multimedia\media\dplayx\dplay\serial\bilink.h
#define BilinkToList( _pBilink ) \
	(_pBilink)->prev->next=NULL;
#define InitBilink( _pBilink ) \
    (_pBilink)->prev=(_pBilink)->next=(_pBilink);

// multimedia\media\dplayx\dplay\serial\dpserial.c
#define VERSIONNUMBER		(DPSP_MAJORVERSION | SPMINORVERSION) // version number for service provider
#define MESSAGEHEADERLEN	sizeof(MESSAGEHEADER) // size of message header

// multimedia\media\dplayx\dplay\wsock\bilink.h
#define BilinkToList( _pBilink ) \
	(_pBilink)->prev->next=NULL;
#define InitBilink( _pBilink ) \
    (_pBilink)->prev=(_pBilink)->next=(_pBilink);

// multimedia\media\dplayx\dplay\wsock\dpsp.h
#define VALID_DPWS_MESSAGE(pMsg) (  VALID_SP_MESSAGE(pMsg) || VALID_HELPER_MESSAGE(pMsg) || \
									VALID_SERVER_MESSAGE(pMsg) || VALID_REUSE_MESSAGE(pMsg) )
#define VALID_DPLAYSVR_MESSAGE(pMsg) (	VALID_SP_MESSAGE(pMsg) || VALID_SERVER_MESSAGE(pMsg) || \
										VALID_REUSE_MESSAGE(pMsg) )
#define VERSIONNUMBER		(DPSP_MAJORVERSION | SPMINORVERSION) // version number for service provider
#define SERVICE_SOCKET(pgd) ( (pgd->AddressFamily == AF_IPX) \
	? pgd->sSystemDGramSocket : pgd->sSystemStreamSocket)
#define INIT_DPSP_CSECT() InitializeCriticalSection(&gcsDPSPCritSection);
#define ENTER_DPSP() EnterCriticalSection(&gcsDPSPCritSection),gCSCount++;
#define LEAVE_DPSP() gCSCount--,LeaveCriticalSection(&gcsDPSPCritSection);
#define ENTER_DPSP() EnterCriticalSection(&gcsDPSPCritSection);
#define LEAVE_DPSP() LeaveCriticalSection(&gcsDPSPCritSection);
#define DGRAM_PSOCKADDR(ppd) ((SOCKADDR *)&(((LPSPPLAYERDATA)ppd)->saddrDatagram))
#define STREAM_PSOCKADDR(ppd) ((SOCKADDR *)&(((LPSPPLAYERDATA)ppd)->saddrStream))

// multimedia\media\dplayx\dplobby\dplobby\tlhelp32.h
#define TH32CS_SNAPALL	    (TH32CS_SNAPHEAPLIST | TH32CS_SNAPPROCESS | TH32CS_SNAPTHREAD | TH32CS_SNAPMODULE)

// multimedia\media\dplayx\misc\lists.h
#define	LIST_INITIALIZE(root)\
{\
    (root)->Root = 0;\
}
#define	TAIL_QUEUE_INITIALIZE(root)\
{\
    (root)->First = NULL;\
    (root)->Last = &(root)->First;\
}
#define	CIRCLE_QUEUE_INITIALIZE(root,type)\
{   (root)->Last = (type *)(root);\
    (root)->First = (type *)(root);\
}
#define CIRCLE_QUEUE_INSERT_END(root,type,element,field)\
{   (element)->field.Prev = (root)->Last;\
    (element)->field.Next = (type *)(root);\
    if((root)->First != (type *)(root))\
	(root)->Last->field.Next = (element);\
    else\
	(root)->First = (element);\
    (root)->Last = (element);\
}
#define CIRCLE_QUEUE_INSERT_ROOT(root,type,element,field)\
{   (element)->field.Prev = (type *)(root);\
    (element)->field.Next = (root)->First;\
    if ((root)->Last != (void *)(root))\
	(root)->First->field.Prev = (element);\
    else\
	(root)->Last = (element);\
    (root)->First = (element);\
}
#define CIRCLE_QUEUE_INSERT_PREVIOUS(root,current_element,element,field)\
{   (element)->field.Prev = (current_element)->field.Prev;\
    (element)->field.Next = (current_element);\
    if ((current_element)->field.Prev != (void *)(root))\
	(current_element)->field.Prev->field.Next = (element);\
    else\
	(root)->First = (element);\
    (current_element)->field.Prev = (element);\
}
#define CIRCLE_QUEUE_FIRST(root)\
((root)->First == (void *) (root)? 0: (root)->First)
#define CIRCLE_QUEUE_LAST(root)\
((root)->Last == (void *) (root)? 0: (root)->Last)
#define CIRCLE_QUEUE_NEXT(root,element,field)\
((void *) (element)->field.Next == (void *) (root)? 0: (element)->field.Next)
#define CIRCLE_QUEUE_PREVIOUS(root,element,field)\
((element)->field.Prev == (void *) (root)? 0: (element)->field.Prev)

// multimedia\media\inc\mmcntrls.h
#define TB_ENABLEBUTTON	(WM_USER + 1)
#define TB_CHECKBUTTON	(WM_USER + 2)
#define TB_PRESSBUTTON	(WM_USER + 3)
#define TB_HIDEBUTTON	(WM_USER + 4)
#define TB_INDETERMINATE	(WM_USER + 5)
#define TB_ISBUTTONENABLED	(WM_USER + 9)
#define TB_ISBUTTONCHECKED	(WM_USER + 10)
#define TB_ISBUTTONPRESSED	(WM_USER + 11)
#define TB_ISBUTTONHIDDEN	(WM_USER + 12)
#define TB_ISBUTTONINDETERMINATE	(WM_USER + 13)
#define TB_SETSTATE             (WM_USER + 17)
#define TB_GETSTATE             (WM_USER + 18)
#define TB_ADDBUTTONS		(WM_USER + 20)
#define TB_INSERTBUTTON		(WM_USER + 21)
#define TB_GETBUTTON		(WM_USER + 23)
#define TB_COMMANDTOINDEX	(WM_USER + 25)
#define TB_SAVERESTORE		(WM_USER + 26)
#define TB_CUSTOMIZE            (WM_USER + 27)
#define TB_ADDSTRING		(WM_USER + 28)
#define TB_GETITEMRECT		(WM_USER + 29)
#define TB_SETBUTTONSIZE	(WM_USER + 31)
#define TB_AUTOSIZE		(WM_USER + 33)
#define TB_SETBUTTONTYPE	(WM_USER + 34)
#define TB_GETTOOLTIPS		(WM_USER + 35)
#define TB_SETTOOLTIPS		(WM_USER + 36)
#define TB_ACTIVATE_TOOLTIPS	(WM_USER + 37)
#define TTM_ACTIVATE		(WM_USER + 1)   // wparam = BOOL (true or false  = activate or deactivate)
#define TTM_SETDELAYTIME	(WM_USER + 3)
#define TTM_ADDTOOL		(WM_USER + 4)
#define TTM_DELTOOL		(WM_USER + 5)
#define TTM_NEWTOOLRECT		(WM_USER + 6)
#define TTM_RELAYEVENT		(WM_USER + 7)
#define TTM_GETTOOLINFO    	(WM_USER + 8)
#define TTM_SETTOOLINFO    	(WM_USER + 9)
#define TTM_HITTEST             (WM_USER +10)
#define TTM_GETTEXT             (WM_USER +11)
#define TTM_UPDATETIPTEXT       (WM_USER +12)
#define TBM_GETPOS              (WM_USER)
#define TBM_GETRANGEMIN         (WM_USER+1)
#define TBM_GETRANGEMAX         (WM_USER+2)
#define TBM_GETTIC              (WM_USER+3)
#define TBM_SETTIC              (WM_USER+4)
#define TBM_SETPOS              (WM_USER+5)
#define TBM_SETRANGE            (WM_USER+6)
#define TBM_SETRANGEMIN         (WM_USER+7)
#define TBM_SETRANGEMAX         (WM_USER+8)
#define TBM_CLEARTICS           (WM_USER+9)
#define TBM_SETSEL              (WM_USER+10)
#define TBM_SETSELSTART         (WM_USER+11)
#define TBM_SETSELEND           (WM_USER+12)
#define TBM_GETPTICS            (WM_USER+14)
#define TBM_GETTICPOS           (WM_USER+15)
#define TBM_GETNUMTICS          (WM_USER+16)
#define TBM_GETSELSTART         (WM_USER+17)
#define TBM_GETSELEND  	        (WM_USER+18)
#define TBM_CLEARSEL  	        (WM_USER+19)

// multimedia\media\inc\win32.h
    #define GET_WM_ACTIVATE_STATE(wp, lp)               (wp)
    #define GET_WM_CHARTOITEM_CHAR(wp, lp)              (CHAR)(wp)
    #define GET_WM_COMMAND_ID(wp, lp)                   (wp)
    #define GET_WM_MENUSELECT_CMD(wp, lp)               (wp)
    #define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)  \
	    (WPARAM)(cmd), MAKELONG(f, hmenu)
    #define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW) 0, MAKELONG(hmenuF, hmenuW)
    #define GET_WM_MENUCHAR_CHAR(wp, lp)                (CHAR)(wp)
    #define GET_WM_MENUCHAR_MPS(ch, hmenu, f)    \
	    (WPARAM)(ch), MAKELONG(hmenu, f)
    #define GET_WM_PARENTNOTIFY_MSG(wp, lp)             (wp)
    #define GET_WM_PARENTNOTIFY2_MPS(msg, x, y) \
	    (WPARAM)(msg), MAKELONG(x, y)
    #define GET_WM_VKEYTOITEM_CODE(wp, lp)              (wp)
    #define GET_WM_HSCROLL_CODE(wp, lp)                 (wp)
    #define GET_WM_VSCROLL_CODE(wp, lp)                 (wp)

// multimedia\media\mcicda\cda.c
#define validdisk(did) ((did) >= 0 && (did) < MCIRBOOK_MAX_DRIVES && \
                        CdInfo[did].hDevice != NULL)

// multimedia\media\mcicda\cda.h
#define REDFRAME(x)  ((UCHAR)((int)( (x) & 0x000000FF)))

// multimedia\media\mciole\mciole.c
#define PUSHRC(prc) *((prc) ? (prc) : &rcNull)
#define CARETPOS()  // {POINT pt; GetCaretPos(&pt); DPRINTF(("CaretPos: [%d, %d]", pt.x, pt.y));}
#   define SHMEMSIZE (sizeof(MCIOLE32_SHARED_MEMORY))

// multimedia\media\mciseq\list.h
#define  NODEHDRSIZE sizeof(Node)

// multimedia\media\mciseq\mciseq.c
#define ASYNCMESSAGE(w)         (((w) == MCI_PLAY) || ((w) == MCI_SEEK))

// multimedia\media\mciseq\mmsys.h
#define WTM_DONEPLAY    (WM_USER+0)
#define WTM_QUITTASK    (WM_USER+1)
#define WTM_FILLBUFFER  (WM_USER+2)

// multimedia\media\mcivisca\mcivisca\appport.h
    #define GET_WM_ACTIVATE_STATE(wp, lp)           (wp)
    #define GET_WM_CHARTOITEM_CHAR(wp, lp)          (CHAR)(wp)
    #define GET_WM_COMMAND_ID(wp, lp)               (wp)
    #define GET_WM_MENUSELECT_CMD(wp, lp)           (wp)
    #define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)    (WPARAM)(cmd), MAKELONG(f, hmenu)
    #define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW)   0, MAKELONG(hmenuF, hmenuW)
    #define GET_WM_MENUCHAR_CHAR(wp, lp)            (CHAR)(wp)
    #define GET_WM_MENUCHAR_MPS(ch, hmenu, f)       (WPARAM)(ch), MAKELONG(hmenu, f)
    #define GET_WM_PARENTNOTIFY_MSG(wp, lp)         (wp)
    #define GET_WM_PARENTNOTIFY2_MPS(msg, x, y)     (WPARAM)(msg), MAKELONG(x, y)
    #define GET_WM_VKEYTOITEM_CODE(wp, lp)          (wp)
    #define GET_WM_HSCROLL_CODE(wp, lp)             (wp)
    #define GET_WM_VSCROLL_CODE(wp, lp)             (wp)

// multimedia\media\mcivisca\mcivisca\mcivisca.h
#define OWNED(a)        &a
#define INRANGE(x,l,u)  (((x) >= (l)) && ((x) <= (u)))
#define MShortWait(st, t, w) (((t < st) && ((t + (ROLLOVER - st)) > w)) || ((t - st) > w))
#define ISACKTIMER(a)               (((UINT)a & 0xf000) ? TRUE : FALSE)

// multimedia\media\mciwave\mciwave.h
#define ADDMODE(pwd, m)     ((pwd)->wMode |= (m))
#define REMOVEMODE(pwd, m)  ((pwd)->wMode &= ~(m))
#define ISMODE(pwd, m)      ((pwd)->wMode & (m))
#define WTM_STATECHANGE (WM_USER + 1)

// multimedia\media\mixerapp\vu.h
#define VU_SETPOS               (WM_USER + 3)
#define VU_GETPOS               (WM_USER + 4)
#define VU_SETRANGEMAX          (WM_USER + 5)
#define VU_SETRANGEMIN          (WM_USER + 6)
#define VU_GETRANGEMAX          (WM_USER + 7)
#define VU_GETRANGEMIN          (WM_USER + 8)
#define VU_SETBREAKFREQ         (WM_USER + 9)
#define VU_GETBREAKFREQ         (WM_USER + 10)

// multimedia\media\mmcaps2k\appport.h
    #define GET_WM_ACTIVATE_STATE(wp, lp)           (wp)
    #define GET_WM_CHARTOITEM_CHAR(wp, lp)          (CHAR)(wp)
    #define GET_WM_COMMAND_ID(wp, lp)               (wp)
    #define GET_WM_MENUSELECT_CMD(wp, lp)           (wp)
    #define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)    (WPARAM)(cmd), MAKELONG(f, hmenu)
    #define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW)   0, MAKELONG(hmenuF, hmenuW)
    #define GET_WM_MENUCHAR_CHAR(wp, lp)            (CHAR)(wp)
    #define GET_WM_MENUCHAR_MPS(ch, hmenu, f)       (WPARAM)(ch), MAKELONG(hmenu, f)
    #define GET_WM_PARENTNOTIFY_MSG(wp, lp)         (wp)
    #define GET_WM_PARENTNOTIFY2_MPS(msg, x, y)     (WPARAM)(msg), MAKELONG(x, y)
    #define GET_WM_VKEYTOITEM_CODE(wp, lp)          (wp)
    #define GET_WM_HSCROLL_CODE(wp, lp)             (wp)
    #define GET_WM_VSCROLL_CODE(wp, lp)             (wp)

// multimedia\media\mmcaps2k\zyztlb.c
    #define TLB_DEF_STYLE   (WS_VISIBLE|WS_CHILD|WS_VSCROLL|WS_BORDER|  \
			     LBS_NOTIFY|LBS_NOINTEGRALHEIGHT|LBS_USETABSTOPS)

// multimedia\media\mplayer2\bltprop.c
#define ALL_HITHRESH	(RED_HITHRESH | GREEN_HITHRESH | BLUE_HITHRESH)
#define ALL_LOTHRESH	(RED_LOTHRESH | GREEN_LOTHRESH | BLUE_LOTHRESH)

// multimedia\media\mplayer2\cdrag.c
#define STGM_SALL (STGM_READWRITE | STGM_SHARE_EXCLUSIVE)

// multimedia\media\mplayer2\doverb.c
#define SLASH(c)     ((c) == TEXT('/') || (c) == TEXT('\\'))

// multimedia\media\mplayer2\dynalink.h
#define LOAD_IF_NEEDED( Library, ProcInfo, phLibrary ) ( PROCS_LOADED( ProcInfo ) ||   \
                                    LoadLibraryAndProcs( Library, ProcInfo, phLibrary ) )
#define GetOpenFileNameW              (LOAD_IF_NEEDED(szComDlg32, ComDlg32Procs, &hComDlg32),\
                                       (*ComDlg32Procs[0].Address))
#define GetOpenFileNameA              (LOAD_IF_NEEDED(szComDlg32, ComDlg32Procs, &hComDlg32),\
                                       (*ComDlg32Procs[0].Address))
#define WNetGetUniversalNameW         (LOAD_IF_NEEDED(szMPR, MPRProcs, &hMPR),   \
                                       (*MPRProcs[0].Address))
#define WNetGetUniversalNameA         (LOAD_IF_NEEDED(szMPR, MPRProcs, &hMPR),   \
                                       (*MPRProcs[0].Address))
#define OleInitialize                 (LOAD_IF_NEEDED(szOLE32, OLE32Procs, &hOLE32),    \
                                       (*OLE32Procs[16].Address))

// multimedia\media\mplayer2\framebox.c
#define GWI_EDITBOX     (0 * sizeof(INT)) // edit box window handle
#define GWI_SPINARROWS  (1 * sizeof(INT)) // spinarrow window handle
#define GWL_MAXFRAME    (2 * sizeof(INT)) // max frame value
#define IsCharNumeric( ch ) ( IsCharAlphaNumeric( ch ) && !IsCharAlpha( ch ) )

// multimedia\media\mplayer2\framebox.h
#define FBOX_SETMAXFRAME    (WM_USER+100)

// multimedia\media\mplayer2\hatch.c
#define EB_HATCHWIDTH       (0 * sizeof(INT))
#define EB_HATCHRECT_LEFT   (1 * sizeof(INT))
#define EB_HATCHRECT_TOP    (2 * sizeof(INT))
#define EB_HATCHRECT_RIGHT  (3 * sizeof(INT))
#define EB_HATCHRECT_BOTTOM (4 * sizeof(INT))
#define EB_HATCHRECT_HANDLE (5 * sizeof(INT))

// multimedia\media\mplayer2\init.c
#define INITIAL_SIZE    ( 8192 * sizeof( TCHAR ) )

// multimedia\media\mplayer2\inplace.c
#define EB_HATCHWIDTH       (0 * sizeof(INT))

// multimedia\media\mplayer2\mplayer.h
#define TBM_SHOWTICS    (WM_USER+30)
#define OPT_DEFAULT     (ID_TIME|OPT_TITLE|OPT_BORDER|OPT_PLAY|OPT_BAR)
#define MB_ERROR    (MB_ICONEXCLAMATION | MB_OK)

// multimedia\media\mplayer2\persist.c
#define STGM_SALL (STGM_READWRITE | STGM_SHARE_EXCLUSIVE)

// multimedia\media\mplayer2\sbutton.h
#define SSB_GETPOS        (WM_USER)
#define SSB_SETPOS        (WM_USER+1)
#define SSB_GETRANGE      (WM_USER+2)
#define SSB_SETRANGE      (WM_USER+3)
#define SSB_GETWIDTHS     (WM_USER+4)

// multimedia\media\mplayer2\track.h
#define TBM_GETPOS              (WM_USER)
#define TBM_GETRANGEMIN         (WM_USER+1)
#define TBM_GETRANGEMAX         (WM_USER+2)
#define TBM_GETTIC              (WM_USER+3)
#define TBM_SETTIC              (WM_USER+4)
#define TBM_SETPOS              (WM_USER+5)
#define TBM_SETRANGE            (WM_USER+6)
#define TBM_SETRANGEMIN         (WM_USER+7)
#define TBM_SETRANGEMAX         (WM_USER+8)
#define TBM_CLEARTICS           (WM_USER+9)
#define TBM_SETSEL              (WM_USER+10)
#define TBM_SETSELSTART         (WM_USER+11)
#define TBM_SETSELEND           (WM_USER+12)
#define TBM_SETTICTOK           (WM_USER+13)
#define TBM_GETPTICS            (WM_USER+14)
#define TBM_GETTICPOS           (WM_USER+15)
#define TBM_GETNUMTICS          (WM_USER+16)
#define TBM_GETSELSTART         (WM_USER+17)
#define TBM_GETSELEND           (WM_USER+18)
#define TBM_CLEARSEL            (WM_USER+19)
#define TBM_SHOWTICS            (WM_USER+30)

// multimedia\media\msacm\g711\codec.h
    #define SIZEOFACMSTR(x) sizeof(x)

// multimedia\media\msacm\gsm610\codec.h
    #define SIZEOFACMSTR(x) sizeof(x)

// multimedia\media\msacm\imaadpcm\codec.h
    #define SIZEOFACMSTR(x) sizeof(x)

// multimedia\media\msacm\msacm\acmi.h
#define SIZEOF_WAVEFORMATEX(pwfx)   ((WAVE_FORMAT_PCM==(pwfx)->wFormatTag)?sizeof(PCMWAVEFORMAT):(sizeof(WAVEFORMATEX)+(pwfx)->cbSize))
    #define SIZEOFA(x) (sizeof(x))
    #define GET_WM_ACTIVATE_STATE(wp, lp)           (wp)
    #define GET_WM_CHARTOITEM_CHAR(wp, lp)          (CHAR)(wp)
    #define GET_WM_COMMAND_ID(wp, lp)               (wp)
    #define GET_WM_MENUSELECT_CMD(wp, lp)           (wp)
    #define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)    (WPARAM)(cmd), MAKELONG(f, hmenu)
    #define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW)   0, MAKELONG(hmenuF, hmenuW)
    #define GET_WM_MENUCHAR_CHAR(wp, lp)            (CHAR)(wp)
    #define GET_WM_MENUCHAR_MPS(ch, hmenu, f)       (WPARAM)(ch), MAKELONG(hmenu, f)
    #define GET_WM_PARENTNOTIFY_MSG(wp, lp)         (wp)
    #define GET_WM_PARENTNOTIFY2_MPS(msg, x, y)     (WPARAM)(msg), MAKELONG(x, y)
    #define GET_WM_VKEYTOITEM_CODE(wp, lp)          (wp)
    #define GET_WM_HSCROLL_CODE(wp, lp)             (wp)
    #define GET_WM_VSCROLL_CODE(wp, lp)             (wp)
    #define EnterHandle(h) EnterCriticalSection(&HtoPh(h)->CritSec)
    #define LeaveHandle(h) LeaveCriticalSection(&HtoPh(h)->CritSec)
    #define ENTER_LIST_EXCLUSIVE AcquireLockExclusive(&pag->lockDriverIds)
    #define ENTER_LIST_SHARED {AcquireLockShared(&pag->lockDriverIds); threadEnterListShared(pag);}

// multimedia\media\msacm\msacm\chooseri.h
#define NAMELEN(x) (((x)->cbSize-sizeof(NameStore))/sizeof(TCHAR))

// multimedia\media\msacm\msacm\profile.h
#define KEY_READ                ( KEY_QUERY_VALUE            |\
                                  KEY_ENUMERATE_SUB_KEYS     |\
                                  KEY_NOTIFY )
#define KEY_WRITE               ( KEY_SET_VALUE              |\
                                  KEY_CREATE_SUB_KEY )

// multimedia\media\msacm\msacmmap\msacmmap.h
#define SIZEOF_WAVEFORMATEX(pwfx)   ((WAVE_FORMAT_PCM==(pwfx)->wFormatTag)?sizeof(PCMWAVEFORMAT):(sizeof(WAVEFORMATEX)+(pwfx)->cbSize))
    #define GET_WM_ACTIVATE_STATE(wp, lp)           (wp)
    #define GET_WM_CHARTOITEM_CHAR(wp, lp)          (CHAR)(wp)
    #define GET_WM_COMMAND_ID(wp, lp)               (wp)
    #define GET_WM_MENUSELECT_CMD(wp, lp)           (wp)
    #define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)    (WPARAM)(cmd), MAKELONG(f, hmenu)
    #define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW)   0, MAKELONG(hmenuF, hmenuW)
    #define GET_WM_MENUCHAR_CHAR(wp, lp)            (CHAR)(wp)
    #define GET_WM_MENUCHAR_MPS(ch, hmenu, f)       (WPARAM)(ch), MAKELONG(hmenu, f)
    #define GET_WM_PARENTNOTIFY_MSG(wp, lp)         (wp)
    #define GET_WM_PARENTNOTIFY2_MPS(msg, x, y)     (WPARAM)(msg), MAKELONG(x, y)
    #define GET_WM_VKEYTOITEM_CODE(wp, lp)          (wp)
    #define GET_WM_HSCROLL_CODE(wp, lp)             (wp)
    #define GET_WM_VSCROLL_CODE(wp, lp)             (wp)
#define ZYZPCMF_OUT_FORMATS (ZYZPCMF_OUT_M08 | ZYZPCMF_OUT_S08 | ZYZPCMF_OUT_M16 | ZYZPCMF_OUT_S16)
#define ZYZPCMF_OUT_STEREO  (ZYZPCMF_OUT_S08 | ZYZPCMF_OUT_S16)
#define ZYZPCMF_OUT_MONO    (ZYZPCMF_OUT_M08 | ZYZPCMF_OUT_M16)
#define ZYZPCMF_IN_FORMATS  (ZYZPCMF_IN_M08 | ZYZPCMF_IN_S08 | ZYZPCMF_IN_M16 | ZYZPCMF_IN_S16)
#define ZYZPCMF_IN_STEREO   (ZYZPCMF_IN_S08 | ZYZPCMF_IN_S16)
#define ZYZPCMF_IN_MONO     (ZYZPCMF_IN_M08 | ZYZPCMF_IN_M16)
#define WAVE_FORMAT_STEREO8     (WAVE_FORMAT_1S08 | WAVE_FORMAT_2S08 | WAVE_FORMAT_4S08)
#define WAVE_FORMAT_STEREO16    (WAVE_FORMAT_1S16 | WAVE_FORMAT_2S16 | WAVE_FORMAT_4S16)
#define WAVE_FORMAT_MONO8       (WAVE_FORMAT_1M08 | WAVE_FORMAT_2M08 | WAVE_FORMAT_4M08)
#define WAVE_FORMAT_MONO16      (WAVE_FORMAT_1M16 | WAVE_FORMAT_2M16 | WAVE_FORMAT_4M16)
#define WAVE_FORMAT_44k         (WAVE_FORMAT_4M16 | WAVE_FORMAT_4S16 | WAVE_FORMAT_4M08 | WAVE_FORMAT_4S08)
#define WAVE_FORMAT_22k         (WAVE_FORMAT_2M16 | WAVE_FORMAT_2S16 | WAVE_FORMAT_2M08 | WAVE_FORMAT_2S08)
#define WAVE_FORMAT_11k         (WAVE_FORMAT_1M16 | WAVE_FORMAT_1S16 | WAVE_FORMAT_1M08 | WAVE_FORMAT_1S08)
#define WAVE_FORMAT_MONO_44k    (WAVE_FORMAT_4M16 | WAVE_FORMAT_4M08)
#define WAVE_FORMAT_MONO_22k    (WAVE_FORMAT_2M16 | WAVE_FORMAT_2M08)
#define WAVE_FORMAT_MONO_11k    (WAVE_FORMAT_1M16 | WAVE_FORMAT_1M08)
#define WAVE_FORMAT_STEREO_44k  (WAVE_FORMAT_4S16 | WAVE_FORMAT_4S08)
#define WAVE_FORMAT_STEREO_22k  (WAVE_FORMAT_2S16 | WAVE_FORMAT_2S08)
#define WAVE_FORMAT_STEREO_11k  (WAVE_FORMAT_1S16 | WAVE_FORMAT_1S08)
#define WAVE_FORMAT_STEREO      (WAVE_FORMAT_STEREO16 | WAVE_FORMAT_STEREO8)
#define WAVE_FORMAT_MONO        (WAVE_FORMAT_MONO16   | WAVE_FORMAT_MONO8)

// multimedia\media\msacm\msadpcm\codec.h
    #define SIZEOFACMSTR(x) sizeof(x)

// multimedia\media\msacm\msfilter\codec.h
    #define SIZEOFACMSTR(x) sizeof(x)

// multimedia\media\samples\acmapp\acmapp.c
    #define IS_SLASH(c)     ('/' == (c) || '\\' == (c))

// multimedia\media\samples\acmapp\acmapp.h
#define SIZEOF_WAVEFORMATEX(pwfx)   ((WAVE_FORMAT_PCM==(pwfx)->wFormatTag)?sizeof(PCMWAVEFORMAT):(sizeof(WAVEFORMATEX)+(pwfx)->cbSize))

// multimedia\media\samples\acmapp\appport.h
    #define GET_WM_ACTIVATE_STATE(wp, lp)           (wp)
    #define GET_WM_CHARTOITEM_CHAR(wp, lp)          (CHAR)(wp)
    #define GET_WM_COMMAND_ID(wp, lp)               (wp)
    #define GET_WM_MENUSELECT_CMD(wp, lp)           (wp)
    #define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)    (WPARAM)(cmd), MAKELONG(f, hmenu)
    #define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW)   0, MAKELONG(hmenuF, hmenuW)
    #define GET_WM_MENUCHAR_CHAR(wp, lp)            (CHAR)(wp)
    #define GET_WM_MENUCHAR_MPS(ch, hmenu, f)       (WPARAM)(ch), MAKELONG(hmenu, f)
    #define GET_WM_PARENTNOTIFY_MSG(wp, lp)         (wp)
    #define GET_WM_PARENTNOTIFY2_MPS(msg, x, y)     (WPARAM)(msg), MAKELONG(x, y)
    #define GET_WM_VKEYTOITEM_CODE(wp, lp)          (wp)
    #define GET_WM_HSCROLL_CODE(wp, lp)             (wp)
    #define GET_WM_VSCROLL_CODE(wp, lp)             (wp)

// multimedia\media\samples\acmapp\tlb.c
    #define TLB_DEF_STYLE   (WS_VISIBLE|WS_CHILD|WS_VSCROLL|WS_BORDER|  \
                             WS_TABSTOP|WS_GROUP|LBS_NOTIFY|            \
                             LBS_NOINTEGRALHEIGHT|LBS_USETABSTOPS)

// multimedia\media\samples\mcipionr\mcipionr.h
#define EnterCrit(nPort) EnterCriticalSection(&comport[nPort].DeviceCritSec)
#define LeaveCrit(nPort) LeaveCriticalSection(&comport[nPort].DeviceCritSec)

// multimedia\media\samples\mmcapsex\appport.h
    #define GET_WM_ACTIVATE_STATE(wp, lp)           (wp)
    #define GET_WM_CHARTOITEM_CHAR(wp, lp)          (CHAR)(wp)
    #define GET_WM_COMMAND_ID(wp, lp)               (wp)
    #define GET_WM_MENUSELECT_CMD(wp, lp)           (wp)
    #define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)    (WPARAM)(cmd), MAKELONG(f, hmenu)
    #define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW)   0, MAKELONG(hmenuF, hmenuW)
    #define GET_WM_MENUCHAR_CHAR(wp, lp)            (CHAR)(wp)
    #define GET_WM_MENUCHAR_MPS(ch, hmenu, f)       (WPARAM)(ch), MAKELONG(hmenu, f)
    #define GET_WM_PARENTNOTIFY_MSG(wp, lp)         (wp)
    #define GET_WM_PARENTNOTIFY2_MPS(msg, x, y)     (WPARAM)(msg), MAKELONG(x, y)
    #define GET_WM_VKEYTOITEM_CODE(wp, lp)          (wp)
    #define GET_WM_HSCROLL_CODE(wp, lp)             (wp)
    #define GET_WM_VSCROLL_CODE(wp, lp)             (wp)

// multimedia\media\samples\mmcapsex\zyztlb.c
    #define TLB_DEF_STYLE   (WS_VISIBLE|WS_CHILD|WS_VSCROLL|WS_BORDER|  \
			     LBS_NOTIFY|LBS_NOINTEGRALHEIGHT|LBS_USETABSTOPS)

// multimedia\media\sndrec32\soundrec\convert.c
#define MYWM_CANCEL      (WM_APP+0)
#define MYWM_PROGRESS    (WM_APP+1)

// multimedia\media\sndrec32\soundrec\file.c
#define SLASH(c)     ((c) == TEXT('/') || (c) == TEXT('\\'))

// multimedia\media\test\mcitest\edit.c
#define ISEOL(c)   ((c) == '\n'|| (c) == '\r')
#define ISWHITE(c) (ISSPACE(c) || ISEOL(c))

// multimedia\media\test\mcitest\mcitest.c
#define SLASH(c)      ((c) == '/' || (c) == '\\')

// multimedia\media\test\sbtest\wincom.h
#define DLGOPEN_SETEXTEN	(WM_USER + 3)	// sets default extensions
#define DLGOPEN_CHANGED		(WM_USER + 6)	// edit box has been changed
#define DLGOPEN_RESETDIR	(WM_USER + 7)	// directory change
#define DOS_FILES	(DOS_READONLY | DOS_SYSTEM)
#define DOS_ALL		(DOS_FILES | DOS_DIRECTORY | DOS_HIDDEN)
#define BAR_SETRANGE	(WM_USER + 0)
#define BAR_SETPOS	(WM_USER + 2)
#define BAR_DELTAPOS	(WM_USER + 4)
#define ST_SETRIGHTSIDE		(WM_USER + 1)
#define ST_GETRIGHTSIDE		(WM_USER + 2)
#define CM_SETITEMRECTSIZE	(WM_USER + 1)
#define CM_CALCSIZE		(WM_USER + 2)
#define CM_ADDITEM		(WM_USER + 3)
#define CM_INSERTITEM		(WM_USER + 4)
#define CM_GETITEMDATA		(WM_USER + 7)
#define CM_GETCURSEL		(WM_USER + 8)
#define CM_SETCURSEL		(WM_USER + 9)
#define CM_FINDITEM		(WM_USER + 10)
#define WPF_GETNLINES	(WM_USER + 2)
#define WPF_SETTABSTOPS	(WM_USER + 4)
#define WPF_GETTABSTOPS	(WM_USER + 5)
#define WPF_GETNUMTABS	(WM_USER + 6)
#define WPF_SETOUTPUT	(WM_USER + 7)
#define WPF_GETOUTPUT	(WM_USER + 8)
#define WPF_CLEARWINDOW (WM_USER + 9)

// multimedia\media\test\sbtest\wpf.c
#define VK(vk)  ((vk) | 0x0100)

// multimedia\media\tools\docfmt\rtf.c
#define ERRORMARK(w)	for(j=0;j<w;j++) fprintf(errfp," "); fprintf(errfp,"^\n");

// multimedia\media\tools\extract\bfuncs.c
#define SPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\n')
#define SEPSPACE(c) ((c)==' ' || (c)=='\n' || (c)=='\t' ||(c)==','||(c)==';')

// multimedia\media\tools\extract\parsearg.c
#define SLASH(c) ((c) == '\\' || (c) == '/')

// multimedia\media\winmm\drvr.h
#define DrvEnter() EnterCriticalSection(&DriverListCritSec)
#define DrvLeave() LeaveCriticalSection(&DriverListCritSec)

// multimedia\media\winmm\mci.c
#define MCI_DO_NOT_NEED_OPEN(wMessage) \
    (wMessage == MCI_OPEN || wMessage == MCI_SOUND || wMessage == MCI_SYSINFO)

// multimedia\media\winmm\mci.h
    #define mciEnter(id) dprintf4(("Entering MCI crit sec at %s   Current count is %d", id, cmciCritSec));    \
                        EnterCriticalSection(&mciCritSec),          \
                        uCritSecOwner=GetCurrentThreadId(),         \
                        ++cmciCritSec
    #define mciLeave(id) dprintf4(("Leaving MCI crit sec at %s", id)); mciCheckIn(); if(!--cmciCritSec) uCritSecOwner=0; LeaveCriticalSection(&mciCritSec)
    #define mciEnter(id)  EnterCriticalSection(&mciCritSec)
    #define mciLeave(id)  LeaveCriticalSection(&mciCritSec)
#define LockMCIGlobal  EnterCriticalSection(&mciGlobalCritSec);
#define UnlockMCIGlobal LeaveCriticalSection(&mciGlobalCritSec);
#define MCI_VALID_DEVICE_ID(wID) ((wID) > 0 && (wID) < MCI_wNextDeviceID && MCI_lpDeviceList[wID])
#define MCI_TOLOWER(c)  ((WCHAR)((c) >= 'A' && (c) <= 'Z' ? (c) + 0x20 : (c)))

// multimedia\media\winmm\mixer.h
#define MIXMGR_ENTER EnterCriticalSection(&HandleListCritSec)
#define MIXMGR_LEAVE LeaveCriticalSection(&HandleListCritSec)

// multimedia\media\winmm\playsnd.c
#define EnterSound()   EnterCriticalSection(&SoundCritSec);
#define LeaveSound()   LeaveCriticalSection(&SoundCritSec);

// multimedia\media\winmm\playwav.c
#define EnterWavHdr()   EnterCriticalSection(&WavHdrCritSec);
#define LeaveWavHdr()   LeaveCriticalSection(&WavHdrCritSec);

// multimedia\media\winmm\winmmi.h
#define MM_POLYMSGBUFRDONE  (WM_MM_RESERVED_FIRST+0x2B)
#define MM_SND_PLAY         (WM_MM_RESERVED_FIRST+0x2C)
#define MM_SND_ABORT        (WM_MM_RESERVED_FIRST+0x2D)
#define MM_SND_SEND         (WM_MM_RESERVED_FIRST+0x2E)
#define MM_SND_WAIT         (WM_MM_RESERVED_FIRST+0x2F)
#define EnterNumDevs(a) Squirt("Allocating NumDevs CS [%s]", a); EnterCriticalSection(&NumDevsCritSec)
#define LeaveNumDevs(a) LeaveCriticalSection(&NumDevsCritSec); Squirt("Releasing NumDevs CS [%s]", a)
#define EnterNumDevs(a) EnterCriticalSection(&NumDevsCritSec)
#define LeaveNumDevs(a) LeaveCriticalSection(&NumDevsCritSec)
    #define TICKS_PER_QN(dw) (UINT)((dw)&0x7FFF)
    #define TICKS_PER_FRAME(dw) (UINT)((dw)&0x00FF)
    #define ELESIZE(t,e) (sizeof(((t*)NULL)->e))
#define ENTER_MM_HANDLE(h) (EnterCriticalSection(&HtoPH(h)->CritSec))
#define LEAVE_MM_HANDLE(h) ((void)LeaveCriticalSection(&HtoPH(h)->CritSec))

// multimedia\opengl\client\array.h
#define VA_COPY_VERTEX_V2F(dataCoord)           \
    pd->obj.x = ((__GLcoord *) dataCoord)->x;   \
    pd->obj.y = ((__GLcoord *) dataCoord)->y;   \
    pd->obj.z = __glZero;                       \
    pd->obj.w = __glOne;
#define VA_COPY_VERTEX_V3F(dataCoord)           \
    pd->obj.x = ((__GLcoord *) dataCoord)->x;   \
    pd->obj.y = ((__GLcoord *) dataCoord)->y;   \
    pd->obj.z = ((__GLcoord *) dataCoord)->z;   \
    pd->obj.w = __glOne;
#define VA_COPY_VERTEX_V4F(dataCoord)           \
    pd->obj = *((__GLcoord *) data);
#define VA_COPY_TEXTURE_T2F(dataTexture)            \
    pd->texture.x = ((__GLcoord *) dataTexture)->x; \
    pd->texture.y = ((__GLcoord *) dataTexture)->y; \
    pd->texture.z = __glZero;                       \
    pd->texture.w = __glOne;
#define VA_COPY_NORMAL_N3F(dataNormal)                              \
            pd->normal.x = ((__GLcoord *) dataNormal)->x;           \
            pd->normal.y = ((__GLcoord *) dataNormal)->y;           \
            pd->normal.z = ((__GLcoord *) dataNormal)->z;

// multimedia\opengl\client\eval.c
#define COPYMESHVERTEX(m,v)                                          \
{                                                                    \
    (m)->vertex.x = (v)[0];                                          \
    (m)->vertex.y = (v)[1];                                          \
    (m)->vertex.z = (v)[2];                                          \
    (m)->vertex.w = (v)[3];                                          \
}
#define COPYMESHNORMAL(m,n)                                          \
{                                                                    \
    (m)->normal.x = (n)[0];                                          \
    (m)->normal.y = (n)[1];                                          \
    (m)->normal.z = (n)[2];                                          \
}
#define COPYMESHTEXTURE(m,t)                                          \
{                                                                     \
    (m)->texture.x = (t)[0];                                          \
    (m)->texture.y = (t)[1];                                          \
    (m)->texture.z = (t)[2];                                          \
    (m)->texture.w = (t)[3];                                          \
}

// multimedia\opengl\client\fontextr.c
#define NEAR_ZERO( fAngle ) \
    ( fabs(fAngle) < 0.00001 )

// multimedia\opengl\client\fontoutl.c
#define POINT2DEQUAL( p1, p2 ) \
    ( (p1->x == p2->x) && (p1->y == p2->y) )

// multimedia\opengl\client\local.h
#define HIPART(x) *(((USHORT *) &(x))+1)

// multimedia\opengl\client\metasup.c
#define ScaleLongX(plrc, l) \
    MulDiv(l, plrc->iGlsNumeratorX, plrc->iGlsDenominatorX)
#define ScaleLongY(plrc, l) \
    MulDiv(l, plrc->iGlsNumeratorY, plrc->iGlsDenominatorY)

// multimedia\opengl\dlist\dl_opt.c
#define VTYPE_T2F	      (POLYDATA_TEXTURE_VALID | POLYDATA_DLIST_TEXTURE2)
#define VTYPE_C3F_V3F         (VTYPE_C3F | VTYPE_V3F)
#define VTYPE_N3F_V3F         (VTYPE_N3F | VTYPE_V3F)
#define VTYPE_C3F_N3F_V3F     (VTYPE_C3F | VTYPE_N3F | VTYPE_V3F)
#define VTYPE_C4F_N3F_V3F     (VTYPE_C4F | VTYPE_N3F | VTYPE_V3F)
#define VTYPE_T2F_V3F         (VTYPE_T2F | VTYPE_V3F)
#define VTYPE_T2F_C3F_V3F     (VTYPE_T2F | VTYPE_C3F | VTYPE_V3F)
#define VTYPE_T2F_N3F_V3F     (VTYPE_T2F | VTYPE_N3F | VTYPE_V3F)
#define VTYPE_T2F_C3F_N3F_V3F (VTYPE_T2F | VTYPE_C3F | VTYPE_N3F | VTYPE_V3F)
#define VTYPE_T2F_C4F_N3F_V3F (VTYPE_T2F | VTYPE_C4F | VTYPE_N3F | VTYPE_V3F)

// multimedia\opengl\dlist\dl_pdata.h
#define __PDATA_SIZE_T2F         (2 * sizeof(__GLfloat))
#define __PDATA_SIZE_C3F         (3 * sizeof(__GLfloat))
#define __PDATA_SIZE_N3F         (3 * sizeof(__GLfloat))
#define __PDATA_SIZE_V3F         (3 * sizeof(__GLfloat))

// multimedia\opengl\glexts\hacklocl.h
#define HIPART(x) *(((USHORT *) &(x))+1)

// multimedia\opengl\gls\inc\ctx.h
#define __GLS_C_LOCALE_BEGIN \
    if ( \
        __saveLocale && \
        __glsString_assign(&__GLS_CONTEXT->savedLocale, __locale) \
    ) { \
        setlocale(LC_NUMERIC, "C"); \
    } else { \
        __saveLocale = GL_FALSE; \
    }

// multimedia\opengl\gls\inc\encoding.h
#define __GLS_JUMP_ALLOC (sizeof(__GLSbinCommand_jump) + 4)

// multimedia\opengl\gls\lib\platform.c
#define __GLS_DIGIT(c) ( \
    isdigit(c) ? c - '0' : islower(c) ? c - 'a' + 10 : c - 'A' + 10 \
)

// multimedia\opengl\gls\lib\writebin.c
#define __GLS_PUT_BIN_ENUM_VAL(inType, inEnum) \
static void __glsWriter_put##inType##Or##inEnum##_bin( \
    __GLSwriter *inoutWriter, inEnum inParam, inType inVal \
) { \
    inoutWriter->put##inType(inoutWriter, inVal); \
}
#define __GLS_PUT_BIN_ENUM_VEC(inType, inEnum) \
static void __glsWriter_put##inType##Or##inEnum##v_bin( \
    __GLSwriter *inoutWriter, \
    inEnum inParam, \
    GLuint inCount, \
    const inType *inVec \
) { \
    inoutWriter->put##inType##v(inoutWriter, inCount, inVec); \
}
#define __GLS_INIT_PUT_BIN_VAL(inDst, inSrc) \
    inoutWriter->put##inDst = __glsWriter_put##inSrc##_bin;
#define __GLS_INIT_PUT_BIN_VEC(inDst, inSrc) \
    inoutWriter->put##inDst##v = __glsWriter_put##inSrc##v_bin;
#define __GLS_INIT_PUT_BIN_VECSTRIDE(inDst, inSrc) \
    inoutWriter->put##inDst##vs = __glsWriter_put##inSrc##vs_bin;

// multimedia\opengl\gls\lib\writetxt.c
#define __GLS_PARAM_SEP(inoutWriter) \
    if (inoutWriter->paramCount++) { \
        __GLS_PUT_CHAR(inoutWriter, ','); \
        __GLS_PUT_CHAR(inoutWriter, ' '); \
    }
#define __GLS_PUT_DOUBLE(inoutWriter, inVal) \
    if (__GLS_FINITE(inVal)) { \
        __GLS_C_LOCALE_DECLARE; \
        __GLS_C_LOCALE_BEGIN; \
        __GLS_PUT_NUM(inoutWriter, "%.16g", inVal); \
        __GLS_C_LOCALE_END; \
    } else { \
        __GLS_PUT_HEX16(inoutWriter, *(const GLulong *)&(inVal)); \
    }
#define __GLS_PUT_DOUBLE17(inoutWriter, inVal) \
    if (__GLS_FINITE(inVal)) { \
        __GLS_C_LOCALE_DECLARE; \
        __GLS_C_LOCALE_BEGIN; \
        __GLS_PUT_NUM(inoutWriter, "%-17.16g", inVal); \
        __GLS_C_LOCALE_END; \
    } else { \
        __GLS_PUT_HEX16(inoutWriter, *(const GLulong *)&(inVal)); \
    }
#define __GLS_PUT_FLOAT(inoutWriter, inVal) \
    if (__GLS_FINITE((GLdouble)inVal)) { \
        __GLS_C_LOCALE_DECLARE; \
        __GLS_C_LOCALE_BEGIN; \
        __GLS_PUT_NUM(inoutWriter, "%.7g", inVal); \
        __GLS_C_LOCALE_END; \
    } else { \
        __GLS_PUT_HEX8(inoutWriter, *(const GLuint *)&(inVal)); \
    }
#define __GLS_PUT_FLOAT11(inoutWriter, inVal) \
    if (__GLS_FINITE((GLdouble)inVal)) { \
        __GLS_C_LOCALE_DECLARE; \
        __GLS_C_LOCALE_BEGIN; \
        __GLS_PUT_NUM(inoutWriter, "%-11.7g", inVal); \
        __GLS_C_LOCALE_END; \
    } else { \
        __GLS_PUT_HEX8(inoutWriter, *(const GLuint *)&(inVal)); \
    }
    #define __GLS_PUT_HEX16(inoutWriter, inVal) \
        __GLS_PUT_NUM( \
            inoutWriter, "0x%.8x", glsULongHigh(*(const GLulong *)&(inVal)) \
        ); \
        __GLS_PUT_NUM( \
            inoutWriter, "%.8x", glsULongLow(*(const GLulong *)&(inVal)) \
        );
#define __GLS_PUT_TEXT_ENUM_VAL(inType, inEnum, inCategory) \
static void __glsWriter_put##inType##Or##inEnum##_text( \
    __GLSwriter *inoutWriter, \
    GLenum inParam, \
    inType inVal \
) { \
    __GLS_PARAM_SETUP(inoutWriter); \
    if ( \
        !__GLS_FINITE((GLdouble)inVal) || \
        floor((GLdouble)inVal) != (GLdouble)inVal || \
        (GLdouble)inVal < 0. || \
        (GLdouble)inVal > (GLdouble)UINT_MAX || \
        !__glsWriter_put##inEnum##ParamVal_text( \
            inoutWriter, inParam, (inEnum)inVal \
        ) \
    ) { \
        __GLS_PUT_##inCategory(inoutWriter, inVal); \
    } \
}
#define __GLS_PUT_TEXT_ENUM_VEC(inType, inEnum, inCategory) \
static void __glsWriter_put##inType##Or##inEnum##v_text( \
    __GLSwriter *inoutWriter, \
    GLenum inParam, \
    GLuint inCount, \
    const inType *inVec \
) { \
    GLuint i; \
    const GLboolean multiLine = (GLboolean)(inCount > 4); \
    __GLS_PARAM_SETUP(inoutWriter); \
    __GLS_PUT_CHAR(inoutWriter, '{'); \
    for (i = 0 ; i < inCount ; ++i) { \
        __GLS_ALLOC(inoutWriter, __GLS_NULL); \
        if (i) __GLS_PUT_CHAR(inoutWriter, ','); \
        if (multiLine && !(i & 7)) { \
            __GLS_PUT_STRING(inoutWriter, "\n    "); \
        } else if (i) { \
            __GLS_PUT_CHAR(inoutWriter, ' '); \
        } \
        if ( \
            !__GLS_FINITE((GLdouble)inVec[i]) || \
            floor((GLdouble)inVec[i]) != (GLdouble)inVec[i] || \
            (GLdouble)inVec[i] < 0. || \
            (GLdouble)inVec[i] > (GLdouble)UINT_MAX || \
            !__glsWriter_put##inEnum##ParamVal_text( \
                inoutWriter, inParam, (inEnum)inVec[i] \
            ) \
        ) { \
            __GLS_PUT_##inCategory(inoutWriter, inVec[i]); \
        } \
    } \
    if (multiLine) __GLS_PUT_CHAR(inoutWriter, '\n'); \
    __GLS_PUT_CHAR(inoutWriter, '}'); \
}
#define __GLS_PUT_TEXT_MAT(inType, inCategory) \
static void __glsWriter_put##inType##m_text( \
    __GLSwriter *inoutWriter, \
    const inType *inMat \
) { \
    GLuint i, j; \
    __GLS_PARAM_SETUP(inoutWriter); \
    __GLS_PUT_CHAR(inoutWriter, '{'); \
    for (i = 0 ; i < 4 ; ++i) { \
        __GLS_ALLOC(inoutWriter, __GLS_NULL); \
        if (i) __GLS_PUT_CHAR(inoutWriter, ','); \
        __GLS_PUT_STRING(inoutWriter, "\n    "); \
        for (j = 0 ; j < 4 ; ++j) { \
            if (j) __GLS_PUT_STRING(inoutWriter, ", "); \
            __GLS_PUT_##inCategory(inoutWriter, inMat[i * 4 + j]); \
        } \
    } \
    __GLS_PUT_STRING(inoutWriter, "\n}"); \
}
#define __GLS_PUT_TEXT_VEC(inType, inSize, inCategory) \
static void __glsWriter_put##inType##v_text( \
    __GLSwriter *inoutWriter, \
    GLuint inCount, \
    const inType *inVec \
) { \
    GLuint i; \
    const GLboolean multiLine = (GLboolean)(inCount > 4); \
    __GLS_PARAM_SETUP(inoutWriter); \
    __GLS_PUT_CHAR(inoutWriter, '{'); \
    for (i = 0 ; i < inCount ; ++i) { \
        __GLS_ALLOC(inoutWriter, __GLS_NULL); \
        if (i) __GLS_PUT_CHAR(inoutWriter, ','); \
        if (multiLine && !(i & 7)) { \
            __GLS_PUT_STRING(inoutWriter, "\n    "); \
        } else if (i) { \
            __GLS_PUT_CHAR(inoutWriter, ' '); \
        } \
        __GLS_PUT_##inCategory(inoutWriter, inVec[i]); \
    } \
    if (multiLine) __GLS_PUT_CHAR(inoutWriter, '\n'); \
    __GLS_PUT_CHAR(inoutWriter, '}'); \
}
#define __GLS_INIT_PUT_TEXT(inType) \
    inoutWriter->put##inType = __glsWriter_put##inType##_text

// multimedia\opengl\glu\libtess\dict-lis.h
#define	       __gl_dictListInsert(d,k) (dictInsertBefore((d),&(d)->head,(k)))

// multimedia\opengl\glu\libtess\dict.h
#define	       __gl_dictListInsert(d,k) (dictInsertBefore((d),&(d)->head,(k)))

// multimedia\opengl\glu\libtess\geom.c
#define RealInterpolate(a,x,b,y)			\
  (a = (a < 0) ? 0 : a, b = (b < 0) ? 0 : b,		\
  ((a <= b) ? ((b == 0) ? ((x+y) / 2)			\
                        : (x + (y-x) * (a/(a+b))))	\
            : (y + (x-y) * (b/(a+b)))))

// multimedia\opengl\glu\libtess\geom.h
#define VertEq(u,v)	(((u)->s == (v)->s) & ((u)->t == (v)->t))
#define VertLeq(u,v)	(((u)->s < (v)->s) | \
                         ((u)->s == (v)->s & (u)->t <= (v)->t))
#define VertEq(u,v)	((u)->s == (v)->s && (u)->t == (v)->t)
#define VertLeq(u,v)	(((u)->s < (v)->s) || \
                         ((u)->s == (v)->s && (u)->t <= (v)->t))
#define TransLeq(u,v)	(((u)->t < (v)->t) || \
                         ((u)->t == (v)->t && (u)->s <= (v)->s))

// multimedia\opengl\glu\libtess\mem-mf.c
#define calloc(nobj, size)  LocalAlloc(LMEM_FIXED|LMEM_ZEROINIT, (UINT)((nobj) * (size)))

// multimedia\opengl\glu\libtess\mem-mf.h
#define calloc(nobj, size)  LocalAlloc(LMEM_FIXED|LMEM_ZEROINIT, (UINT)((nobj) * (size)))

// multimedia\opengl\glu\libtess\render.c
#define Marked(f)	(! (f)->inside || (f)->marked)
#define IsEven(n)	(((n) & 1) == 0)

// multimedia\opengl\glu\libtess\stack.h
#define StackPush(s,d)	{ if ((s)->size >= (s)->max) __gl_StackGrow( s ); \
			    (s)->data[((s)->size)++] = (d); }

// multimedia\opengl\glu\libtess\sweep.c
#define AddWinding(eDst,eSrc)	(eDst->winding += eSrc->winding, \
				 eDst->Sym->winding += eSrc->Sym->winding)

// multimedia\opengl\glu\libtess\tess.c
#define MAX_FAST_ALLOC	(MAX(sizeof(EdgePair), \
			 MAX(sizeof(GLUvertex),sizeof(GLUface))))

// multimedia\opengl\glu\libtess\tess.h
#define CALL_BEGIN_OR_BEGIN_DATA(a) \
   if (tess->callBeginData != &__gl_noBeginData) \
      (*tess->callBeginData)((a),tess->polygonData); \
   else (*tess->callBegin)((a));
#define CALL_VERTEX_OR_VERTEX_DATA(a) \
   if (tess->callVertexData != &__gl_noVertexData) \
      (*tess->callVertexData)((a),tess->polygonData); \
   else (*tess->callVertex)((a));
#define CALL_END_OR_END_DATA() \
   if (tess->callEndData != &__gl_noEndData) \
      (*tess->callEndData)(tess->polygonData); \
   else (*tess->callEnd)();
#define CALL_COMBINE_OR_COMBINE_DATA(a,b,c,d) \
   if (tess->callCombineData != &__gl_noCombineData) \
      (*tess->callCombineData)((a),(b),(c),(d),tess->polygonData); \
   else (*tess->callCombine)((a),(b),(c),(d));
#define CALL_ERROR_OR_ERROR_DATA(a) \
   if (tess->callErrorData != &__gl_noErrorData) \
      (*tess->callErrorData)((a),tess->polygonData); \
   else (*tess->callError)((a));

// multimedia\opengl\glu\libtess\tessmono.c
#define AddWinding(eDst,eSrc)	(eDst->winding += eSrc->winding, \
				 eDst->Sym->winding += eSrc->Sym->winding)

// multimedia\opengl\glu\nurbs\core\nurbsint.cxx
#define THREAD2( work ) \
	if( dl ) {\
	    dl->append( (PFVS)&NurbsTessellator::work, 0, 0 );\
	} else {\
	    work( );\
	}

// multimedia\opengl\inc\compsize.h
#define __glGetMapdv_size(target,query)                         \
        (__glGetMap_size(target,query)*sizeof(GLdouble))
#define __glGetMapfv_size(target,query)                         \
        (__glGetMap_size(target,query)*sizeof(GLfloat))
#define __glGetMapiv_size(target,query)                         \
        (__glGetMap_size(target,query)*sizeof(GLint))

// multimedia\opengl\inc\glsize.h
#define RANGE(n, a, b)  \
	(((unsigned)(n) >= (unsigned)(a)) && ((unsigned)(n) <= (unsigned)(b)))

// multimedia\opengl\inc\glteb.h
#define GLTEB_CLTPOLYMATERIAL() \
    ((POLYMATERIAL *)(NT_CURRENT_TEB()->glReserved2))
#define GLTEB_SET_CLTPOLYMATERIAL(pm) \
    (NT_CURRENT_TEB()->glReserved2 = (PVOID)(pm))
#define GLTEB_CLTDISPATCHTABLE_FAST()                                   \
    ((PGLDISPATCHTABLE_FAST)(NT_CURRENT_TEB()->glDispatchTable))
#define GLTEB_CLTCURRENTRC()                                            \
    (NT_CURRENT_TEB() ? (PLRC)NT_CURRENT_TEB()->glCurrentRC : (PLRC)0)
#define GLTEB_CLTCURRENTRC()                                            \
    ((PLRC)NT_CURRENT_TEB()->glCurrentRC)
#define GLTEB_SET_CLTCURRENTRC(RC)                                      \
    (NT_CURRENT_TEB()->glCurrentRC = (PVOID)(RC))
#define GLTEB_CLTDRIVERSLOT()                                           \
    (NT_CURRENT_TEB()->glContext)
#define GLTEB_SET_CLTDRIVERSLOT(pv)                                     \
    (NT_CURRENT_TEB()->glContext = (pv))
#define GLTEB_SET_SRVCONTEXT(Context)                                   \
    (NT_CURRENT_TEB()->glSectionInfo = (PVOID)(Context))
#define GLTEB_CLTDISPATCHTABLE()                                        \
    ((PGLDISPATCHTABLE)(CURRENT_GLTEBINFO()->glCltDispatchTable))
#define GLTEB_SHAREDMEMORYSECTION()                                     \
    ((GLMSGBATCHINFO *) (CURRENT_GLTEBINFO()->glMsgBatchInfo))

// multimedia\opengl\mcd\client\mcd.c
#define SUPPORTS_DIRECT() \
    (verMinor >= 0x10 || verMajor > 1)
#define SUPPORTS_20() \
    (verMajor >= 2)
#define InitMcdEscEmpty(pmeh) \
    (InitMcdEsc(pmeh), \
     (pmeh)->hRC = NULL, \
     (pmeh)->hSharedMem = NULL, \
     (pmeh)->pSharedMem = NULL, \
     (pmeh)->dwWindow = 0, \
     (pmeh))
#define InitMcdEscContext(pmeh, pmctx) \
    (InitMcdEsc(pmeh), \
     (pmeh)->hRC = (pmctx)->hMCDContext, \
     (pmeh)->dwWindow = (pmctx)->dwMcdWindow, \
     (pmeh))

// multimedia\opengl\mcd\inc\mcd2hack.h
#define MCDDRIVER_V11_SIZE      (MCDDRIVER_V10_SIZE+2*sizeof(void *))
#define MCDDRIVER_V20_SIZE      (MCDDRIVER_V11_SIZE+1*sizeof(void *))

// multimedia\opengl\mcd\server\mcdsrv.c
#define SUPPORTS_DIRECT(pGlobal) \
    ((pGlobal)->verMinor >= 0x10 || (pGlobal)->verMajor > 1)
#define MGDF_SIZE (sizeof(ULONG)+sizeof(void *))

// multimedia\opengl\scrsave\3dfo\genwin.c
#define FACE_VERTEX(i) \
    iPtInList(mesh, startBlend, pts + i, &mesh->faces[faceCount].norm, TRUE)

// multimedia\opengl\scrsave\common\sscommon.h
#define SS_MAX( a, b ) \
    ( a > b ? a : b )
#define SS_MIN( a, b ) \
    ( a < b ? a : b )

// multimedia\opengl\scrsave\common\sswindow.cxx
#define NULL_UPDATE_RECT( pRect ) \
     (  ((pRect)->left == 0) && \
        ((pRect)->right == 0) && \
        ((pRect)->top == 0) && \
        ((pRect)->bottom == 0) )

// multimedia\opengl\scrsave\flwbox\ssflwbox.h
#define V3Sub(a, b, r) \
    ((r)->x = (a)->x-(b)->x, (r)->y = (a)->y-(b)->y, (r)->z = (a)->z-(b)->z)
#define V3Add(a, b, r) \
    ((r)->x = (a)->x+(b)->x, (r)->y = (a)->y+(b)->y, (r)->z = (a)->z+(b)->z)
#define V3Cross(a, b, r) \
    ((r)->x = (a)->y*(b)->z-(b)->y*(a)->z,\
     (r)->y = (a)->z*(b)->x-(b)->z*(a)->x,\
     (r)->z = (a)->x*(b)->y-(b)->x*(a)->y)

// multimedia\opengl\scrsave\maze\fixed.h
#define FxV2Set(v, xv, yv) \
    ((v)->x = (xv), (v)->y = (yv))
#define FxV2Add(a, b, r) \
    ((r)->x = (a)->x+(b)->x, (r)->y = (a)->y+(b)->y)
#define FxV2Sub(a, b, r) \
    ((r)->x = (a)->x-(b)->x, (r)->y = (a)->y-(b)->y)
#define FxV2Dot(a, b) \
    (FxMul((a)->x, (b)->x)+FxMul((a)->y, (b)->y))
#define FxV2Neg(v, r) \
    ((r)->x = -(v)->x, (r)->y = -(v)->y)
#define FxvV2Set(v, xv, yv) FxV2Set(&(v), xv, yv)
#define FxvV2Add(a, b, r) FxV2Add(&(a), &(b), &(r))
#define FxvV2Sub(a, b, r) FxV2Sub(&(a), &(b), &(r))
#define FxvV2Dot(a, b) FxV2Dot(&(a), &(b))
#define FxvV2Neg(v, r) FxV2Neg(&(v), &(r))
#define FxvV2NegV(v) FxV2NegV(&(v))
#define FxvV2Len(v) FxV2Len(&(v))
#define FxvV2Norm(v, r) FxV2Norm(&(v), &(r))
#define FxvV2NormV(v) FxV2NormV(&(v))
#define FxV3Set(v, xv, yv, zv) \
    ((v)->x = (xv), (v)->y = (yv), (v)->z = (zv))
#define FxV3Add(a, b, r) \
    ((r)->x = (a)->x+(b)->x, (r)->y = (a)->y+(b)->y, (r)->z = (a)->z+(b)->z)
#define FxV3Sub(a, b, r) \
    ((r)->x = (a)->x-(b)->x, (r)->y = (a)->y-(b)->y, (r)->z = (a)->z-(b)->z)
#define FxV3Dot(a, b) \
    (FxMul((a)->x, (b)->x)+FxMul((a)->y, (b)->y)+FxMul((a)->z, (b)->z))
#define FxV3Neg(v, r) \
    ((r)->x = -(v)->x, (r)->y = -(v)->y, (r)->z = -(v)->z)
#define FxV3Cross(a, b, r) \
    ((r)->x = (a)->y*(b)->z-(b)->y*(a)->z,\
     (r)->y = (a)->z*(b)->x-(b)->z*(a)->x,\
     (r)->z = (a)->x*(b)->y-(b)->x*(a)->y)
#define FxvV3Set(v, xv, yv, zv) FxV3Set(&(v), xv, yv, zv)
#define FxvV3Add(a, b, r) FxV3Add(&(a), &(b), &(r))
#define FxvV3Sub(a, b, r) FxV3Sub(&(a), &(b), &(r))
#define FxvV3Dot(a, b) FxV3Dot(&(a), &(b))
#define FxvV3Neg(v, r) FxV3Neg(&(v), &(r))
#define FxvV3NegV(v) FxV3NegV(&(v))
#define FxvV3Cross(a, b, r) FxV3Cross(&(a), &(b), &(r))
#define FxvV3Len(v) FxV3Len(&(v))
#define FxvV3Norm(v, r) FxV3Norm(&(v), &(r))
#define FxvV3NormV(v) FxV3NormV(&(v))

// multimedia\opengl\scrsave\maze\genmaze.c
#define SetsAreConnected(a, b) \
    ((a)->set == (b)->set)

// multimedia\opengl\scrsave\maze\ssmaze.c
#define CellAt(x, y) (&maze_cells[y][x])

// multimedia\opengl\server\generic\alloc.c
#define MEM_HDR_SIZE sizeof(MEM_HDR)

// multimedia\opengl\server\generic\genaccel.c
#define DO_NICEST_FOG(gc)\
         (gc->state.hints.fog == GL_NICEST)

// multimedia\opengl\server\generic\genaline.c
#define __GL_FLOAT_SIMPLE_BEGIN_DIVIDE(a, b, c) \
    __GL_FLOAT_BEGIN_DIVIDE(a, b, &(c))
#define __GL_FLOAT_SIMPLE_END_DIVIDE(r) \
    __GL_FLOAT_END_DIVIDE(&(r))
#define READ_PIX(pPix) \
    *((USHORT *)(pPix))
#define WRITE_PIX(pPix) \
    *((USHORT *)pPix) = (USHORT)(r | g | b)
#define READ_PIX(pPix) \
    *((USHORT *)(pPix))
#define WRITE_PIX(pPix) \
    *((USHORT *)pPix) = (USHORT)(r | g | b)
#define READ_PIX(pPix) \
    *((USHORT *)(pPix))
#define WRITE_PIX(pPix) \
    *((USHORT *)pPix) = (USHORT)(r | g | b)
#define READ_PIX(pPix) \
    *((USHORT *)(pPix))
#define WRITE_PIX(pPix) \
    *((USHORT *)pPix) = (USHORT)(r | g | b)
#define WRITE_PIX(pPix) \
    *((USHORT *)pPix) = (USHORT)(r | g | b)
#define WRITE_PIX(pPix) \
    *((USHORT *)pPix) = (USHORT)(r | g | b)

// multimedia\opengl\server\generic\genline.c
#define FAST_LINE_FIRST_POINT(genAccel) \
    ((POINT *)(genAccel)->pFastLineBuffer)

// multimedia\opengl\server\generic\i386\fastpoly.c
#define FLT_TO_FIX(value) \
    *((GLint *)&value) = (GLint)(*((__GLfloat *)&(value)) * (__GLfloat)65536.0)

// multimedia\opengl\server\generic\mcdcx.c
#define SUPPORTS_DIRECT() \
    (McdDriverInfo.mcdDriverInfo.verMinor >= 0x10 || \
     McdDriverInfo.mcdDriverInfo.verMajor > 1)
#define SUPPORTS_20() \
    (McdDriverInfo.mcdDriverInfo.verMajor >= 2)

// multimedia\opengl\server\inc\context.h
#define __GL_CLAMP_CI(target, gc, r)                            \
{                                                               \
    if ((r) > (GLfloat)(gc)->frontBuffer.redMax) {              \
        GLfloat fraction;                                       \
        GLint integer;                                          \
                                                                \
        integer = (GLint) (r);                                  \
        fraction = (r) - (GLfloat) integer;                     \
        integer = integer & (GLint)(gc)->frontBuffer.redMax;    \
        target = (GLfloat) integer + fraction;                  \
    } else if ((r) < 0) {                                       \
        GLfloat fraction;                                       \
        GLint integer;                                          \
                                                                \
        integer = (GLint) __GL_FLOORF(r);                       \
        fraction = (r) - (GLfloat) integer;                     \
        integer = integer & (GLint)(gc)->frontBuffer.redMax;    \
        target = (GLfloat) integer + fraction;                  \
    } else {                                                    \
        target = r;                                             \
    }\
}
#define __GL_SCALE_R(target, gc, r)                                         \
    (target) = (r) * (gc)->redVertexScale
#define __GL_SCALE_G(target, gc, g)                                         \
    (target) = (g) * (gc)->greenVertexScale
#define __GL_SCALE_B(target, gc, b)                                         \
    (target) = (b) * (gc)->blueVertexScale
#define __GL_SCALE_A(target, gc, a)                                         \
    (target) = (a) * (gc)->alphaVertexScale

// multimedia\opengl\server\inc\cpu.h
#define __GL_FLOAT_GTZ(flt)             (*(LONG *)&(flt) > 0)
#define __GL_FLOAT_LTZ(flt)             (*(ULONG *)&(flt) > 0x80000000)
#define __GL_FLOAT_GEZ(flt)             (*(ULONG *)&(flt) <= 0x80000000)
#define __GL_FLOAT_LEZ(flt)             (*(LONG *)&(flt) <= 0)
#define __GL_FLOAT_EQZ(flt)             ((*(ULONG *)&(flt) & 0x7fffffff) == 0)
#define __GL_FLOAT_NEZ(flt)             ((*(ULONG *)&(flt) & 0x7fffffff) != 0)
#define __GL_FLOAT_COMPARE_PONE(flt, op) (*(LONG *)&(flt) op 0x3f800000)
#define __GL_FLOAT_EQPZ(flt)            (*(LONG *)&(flt) == 0)
#define __GL_FLOAT_NEPZ(flt)            (*(LONG *)&(flt) != 0)
#define __GL_FLOAT_EQ(f1, f2)           (*(LONG *)&(f1) == *(LONG *)&(f2))
#define __GL_FLOAT_NE(f1, f2)           (*(LONG *)&(f1) != *(LONG *)&(f2))
#define CASTFIX(a)              (*((LONG *)&(a)))
#define CASTFLOAT(a)            (*((__GLfloat *)&(a)))

// multimedia\opengl\server\inc\dlist.h
#define DLIST_SIZE(n) ((n)+sizeof(__GLlistExecFunc *))

// multimedia\opengl\server\inc\eval.h
#define GET_EVALSTACKSTATE(gc)                                    \
    ((gc)->eval.evalStackState)

// multimedia\opengl\server\inc\fixed.h
#define __GL_VERTEX_COMPARE(a, op, b) \
    ((*(LONG *)&(a)) op (*(LONG *)&(b)))

// multimedia\opengl\server\inc\gencx.h
#define __GL_UNBIAS_AND_INVERT_Y(gc, y) \
        ((gc)->constants.height - __GL_UNBIAS_Y((gc), (y)))

// multimedia\opengl\server\inc\global.h
#define __GL_IN_BEGIN() \
    (gc->beginMode == __GL_IN_BEGIN)

// multimedia\opengl\server\inc\lighting.h
#define __GL_I_TO_FLOAT(i) \
	((((__GLfloat)(i) * (__GLfloat) 2.0) + 1) * \
	    gc->constants.oneOver4294965000)
#define __GL_UI_TO_FLOAT(ui) \
	((__GLfloat)(ui) * gc->constants.oneOver4294965000)
#define __GL_FLOAT_TO_S(f) \
	((GLshort) __GL_FLOORF(((f) * gc->constants.val65535) * __glHalf))
#define __GL_FLOAT_TO_US(f) \
	((GLushort) ((f) * gc->constants.val65535 + __glHalf))
#define __GL_FLOAT_TO_I(f) \
    ((GLint) __GL_FLOORF(((f) * gc->constants.val4294965000) * __glHalf))
#define __GL_FLOAT_TO_UI(f) \
    ((GLuint) ((f) * gc->constants.val4294965000 + __glHalf))

// multimedia\opengl\server\inc\listcomp.h
#define __glLightfv_size(pname)						\
    ((pname) == GL_SPOT_DIRECTION					\
	? 3								\
	: (RANGE((pname),GL_AMBIENT,GL_POSITION)			\
	    ? 4								\
	    : (RANGE((pname),GL_SPOT_EXPONENT,GL_QUADRATIC_ATTENUATION)	\
		? 1							\
		: -1)))
#define __glLightModelfv_size(pname)					\
    (((pname) == GL_LIGHT_MODEL_LOCAL_VIEWER ||				\
      (pname) == GL_LIGHT_MODEL_TWO_SIDE)				\
	? 1								\
	: ((pname) == GL_LIGHT_MODEL_AMBIENT				\
	    ? 4								\
	    : -1))
#define __glTexGendv_size(pname)					\
    (((pname) == GL_OBJECT_PLANE || (pname) == GL_EYE_PLANE)		\
	? 4								\
	: ((pname) == GL_TEXTURE_GEN_MODE				\
	    ? 1								\
	    : -1))

// multimedia\opengl\server\inc\mcdcx.h
#define MCD_STATE_DIRTY(gc, stateName)\
{\
    if (((__GLGENcontext *) (gc))->pMcdState)\
        ((__GLGENcontext *) (gc))->pMcdState->mcdDirtyState |= MCD_DIRTY_##stateName;\
}
#define MCD_STATE_CLEAR(gc, stateName)\
{\
    if (((__GLGENcontext *) (gc))->pMcdState)\
        ((__GLGENcontext *) (gc))->pMcdState->mcdDirtyState &= ~MCD_DIRTY_##stateName;\
}
#define MCD_STATE_RESET(gc)\
{\
    if (((__GLGENcontext *) (gc))->pMcdState)\
        ((__GLGENcontext *) (gc))->pMcdState->mcdDirtyState = 0;\
}
#define MCD_STATE_DIRTYTEST(gc, stateName)\
(\
    (((__GLGENcontext *) (gc))->pMcdState) &&\
    (((__GLGENcontext *) (gc))->pMcdState->mcdDirtyState & MCD_DIRTY_##stateName)\
)

// multimedia\opengl\server\inc\namesint.h
#define __GL_NAMES_LOCK(array)   EnterCriticalSection(&(array)->critsec)
#define __GL_NAMES_UNLOCK(array) LeaveCriticalSection(&(array)->critsec)

// multimedia\opengl\server\inc\render.h
#define __GL_POLYGON_MODE_FILL	(GL_FILL & 0xf)
#define __GL_POLYGON_MODE_LINE	(GL_LINE & 0xf)
#define __GL_POLYGON_MODE_POINT	(GL_POINT & 0xf)

// multimedia\opengl\server\inc\vertex.h
#define __GL_HAS_LIGHTING	(__GL_HAS_EYE | __GL_HAS_NORMAL)

// multimedia\opengl\server\soft\so_clip.c
#define __GL_CLIP_POS(d,a,b,t) \
    d->clip.x = t*(a->clip.x - b->clip.x) + b->clip.x;	\
    d->clip.y = t*(a->clip.y - b->clip.y) + b->clip.y;	\
    d->clip.z = t*(a->clip.z - b->clip.z) + b->clip.z;  \
    d->clip.w = t*(a->clip.w - b->clip.w) + b->clip.w
#define __GL_CLIP_POS(d,a,b,t) \
    d->clip.w = t*(a->clip.w - b->clip.w) + b->clip.w;	\
    /* XXX (mf) Handle w=0.0.  Mathematically incorrect, but prevents /0 */    \
    if( d->clip.w == (__GLfloat) 0.0 ) {		\
	d->window.w = (__GLfloat) 0.0;			\
    }							\
    else						\
	d->window.w = ((__GLfloat) 1.0) / d->clip.w;    \
    d->clip.x = t*(a->clip.x - b->clip.x) + b->clip.x;	\
    d->clip.y = t*(a->clip.y - b->clip.y) + b->clip.y;	\
    d->clip.z = t*(a->clip.z - b->clip.z) + b->clip.z
#define __GL_CLIP_TEXTURE(d,a,b,t) \
    d->texture.x = t*(a->texture.x - b->texture.x) + b->texture.x; \
    d->texture.y = t*(a->texture.y - b->texture.y) + b->texture.y; \
    d->texture.z = t*(a->texture.z - b->texture.z) + b->texture.z; \
    d->texture.w = t*(a->texture.w - b->texture.w) + b->texture.w
#define __GL_CLIP_NORMAL(d,a,b,t)				      \
    d->normal.x = t*(a->normal.x - b->normal.x) + b->normal.x; \
    d->normal.y = t*(a->normal.y - b->normal.y) + b->normal.y; \
    d->normal.z = t*(a->normal.z - b->normal.z) + b->normal.z;
#define __GL_CLIP_EYE(d,a,b,t)				      \
    d->eyeX = t*(a->eyeX - b->eyeX) + b->eyeX; \
    d->eyeY = t*(a->eyeY - b->eyeY) + b->eyeY; \
    d->eyeZ = t*(a->eyeZ - b->eyeZ) + b->eyeZ;
#define __GL_CLIP_FOG(d,a,b,t)	\
    if (a->has & __GL_HAS_FOG)  \
        d->fog = t * (a->fog - b->fog) + b->fog; \
    else \
        d->eyeZ = t*(a->eyeZ - b->eyeZ) + b->eyeZ

// multimedia\opengl\server\soft\so_phong.c
#define GET_HALF_AREA(gc, a, b, c)\
    /* Compute signed half-area of the triangle */                  \
    dxAC = a->window.x - c->window.x;                               \
    dxBC = b->window.x - c->window.x;                               \
    dyAC = a->window.y - c->window.y;                               \
    dyBC = b->window.y - c->window.y;                               \
    gc->polygon.shader.area = dxAC * dyBC - dxBC * dyAC;

// multimedia\opengl\server\soft\so_polya.c
#define In(eq,x,y) \
    (((eq)->a * (x) + (eq)->b * (y) + (eq)->c > 0) == (eq)->edgeSign)
#define Inside(tm,x,y) \
    (In(&(tm)->ab, x, y) && In(&(tm)->bc, x, y) && In(&(tm)->ca, x, y))

// multimedia\opengl\server\soft\so_polym.c
#define GET_HALF_AREA(gc, a, b, c)\
    /* Compute signed half-area of the triangle */                  \
    dxAC = a->window.x - c->window.x;                               \
    dxBC = b->window.x - c->window.x;                               \
    dyAC = a->window.y - c->window.y;                               \
    dyBC = b->window.y - c->window.y;                               \
    gc->polygon.shader.area = dxAC * dyBC - dxBC * dyAC;

// multimedia\opengl\server\soft\so_prim.c
#define PERF_CHECK(expr,str)            \
    {                                   \
        static BOOL bPrinted = FALSE;   \
        if (!(expr) && !bPrinted)       \
        {                               \
            bPrinted = TRUE;            \
            WARNING("PERF_CHECK: " str);\
        }                               \
    }

// multimedia\opengl\server\soft\so_texfi.c
#define REPEAT_SCALED_VAL(val, scale, repeat)                           \
    (__GL_FLOAT_GEZ(val) ? (FTOL((val) * (scale)) & ((repeat)-1)) :     \
     ((repeat)-1)-(FTOL(-(val) * (scale)) & ((repeat)-1)))
#define CLAMP_SCALED_VAL(val, scale)                                    \
    (__GL_FLOAT_LEZ(val) ? 0 :                                          \
     __GL_FLOAT_COMPARE_PONE(val, >=) ? (FTOL(scale)-1) :               \
     FTOL((val) * (scale)))

// multimedia\opengl\server\soft\so_txobj.c
#define __GL_CHECK_VALID_N_PARAM(failStatement)                         \
    if (n < 0) {                                                        \
        __glSetError(GL_INVALID_VALUE);                                 \
    }                                                                   \
    if (n == 0) {                                                       \
        failStatement;                                                  \
    }                                                                   \
#define _DIFFERENT_TEX_PARAMS( tex1, tex2 ) \
      ( ! RtlEqualMemory( &(tex1)->params, &(tex2)->params, sizeof(__GLtextureParamState)) )
#define _DIFFERENT_TEXDATA_FORMATS( tex1, tex2 ) \
    ( (tex1)->level[0].internalFormat != (tex2)->level[0].internalFormat )

// multimedia\opengl\server\soft\so_xform.c
#define __glGenericPickIdentityMatrixProcs(gc, m)	    \
{							                            \
    (m)->xf1 = __glXForm1_2DNRW;			            \
    (m)->xf2 = __glXForm2_2DNRW;			            \
    (m)->xf3 = __glXForm3_2DNRW;			            \
    (m)->xf4 = __glXForm4_2DNRW;			            \
    (m)->xfNorm = __glXForm3_2DNRW;			            \
    (m)->xf1Batch = __glXForm1_2DNRWBatch;		        \
    (m)->xf2Batch = __glXForm2_2DNRWBatch;		        \
    (m)->xf3Batch = __glXForm3_2DNRWBatch;		        \
    (m)->xf4Batch = __glXForm4_2DNRWBatch;		        \
    (m)->xfNormBatch = __glXForm3_2DNRWBatchNormal;		\
    (m)->xfNormBatchN = __glXForm3_2DNRWBatchNormalN;	\
}
#define __GLXFORM1_INIT(v)                  \
    __GLfloat x = (v)[0];                   \
    __GLfloat mat00, mat01, mat02, mat03;   \
    __GLfloat mat30, mat31, mat32, mat33;   \
    __GLfloat a0, a1, a2, a3;               \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
    mat02 = m->matrix[0][2];                \
    mat03 = m->matrix[0][3];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];                \
    mat33 = m->matrix[3][3];
#define __GLXFORM1(res)                     \
    a0 = x * mat00;                         \
    a1 = x * mat01;                         \
    a2 = x * mat02;                         \
    a3 = x * mat03;                         \
                                            \
    res->x = a0 + mat30;                    \
    res->y = a1 + mat31;                    \
    res->z = a2 + mat32;                    \
    res->w = a3 + mat33;
#define __GLXFORM1_W_INIT(v)                \
    __GLfloat x = (v)[0];                   \
    __GLfloat mat00, mat01, mat02;          \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0, a1, a2;                   \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
    mat02 = m->matrix[0][2];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];
#define __GLXFORM1_W(res)                   \
    a0 = x * mat00;                         \
    a1 = x * mat01;                         \
    a2 = x * mat02;                         \
                                            \
    res->x = a0 + mat30;                    \
    res->y = a1 + mat31;                    \
    res->z = a2 + mat32;                    \
    res->w = ((__GLfloat) 1.0);
#define __GLXFORM1_2DW_INIT(v)              \
    __GLfloat x = (v)[0];                   \
    __GLfloat mat00, mat01;                 \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0, a1;                       \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
                                            \
    mat32 = m->matrix[3][2];
#define __GLXFORM1_2DW(res)                 \
    a0 = x * mat00;                         \
    a1 = x * mat01;                         \
                                            \
    res->x = a0 + mat30;                    \
    res->y = a1 + mat31;                    \
    res->z = mat32;                         \
    res->w = ((__GLfloat) 1.0);
#define __GLXFORM1_2DNRW_INIT(v)            \
    __GLfloat x = (v)[0];                   \
    __GLfloat mat00, mat01;                 \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0;                           \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
                                            \
    mat32 = m->matrix[3][2];
#define __GLXFORM1_2DNRW(res)               \
    a0 = x * mat00;                         \
                                            \
    res->x = a0 + mat30;                    \
    res->y = mat31;                         \
    res->z = mat32;                         \
    res->w = ((__GLfloat) 1.0);
#define __GLXFORM2_INIT(v)                  \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat mat00, mat01, mat02, mat03;   \
    __GLfloat mat10, mat11, mat12, mat13;   \
    __GLfloat mat30, mat31, mat32, mat33;   \
    __GLfloat a0, a1, a2, a3;               \
    __GLfloat b0, b1, b2, b3;               \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
    mat02 = m->matrix[0][2];                \
    mat03 = m->matrix[0][3];                \
                                            \
    mat10 = m->matrix[1][0];                \
    mat11 = m->matrix[1][1];                \
    mat12 = m->matrix[1][2];                \
    mat13 = m->matrix[1][3];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];                \
    mat33 = m->matrix[3][3];
#define __GLXFORM2(res)                     \
    a0 = x * mat00;                         \
    a1 = x * mat01;                         \
    a2 = x * mat02;                         \
    a3 = x * mat03;                         \
                                            \
    b0 = y * mat10;                         \
    b1 = y * mat11;                         \
    b2 = y * mat12;                         \
    b3 = y * mat13;                         \
                                            \
    a0 += mat30;                            \
    a1 += mat31;                            \
    a2 += mat32;                            \
    a3 += mat33;                            \
                                            \
    res->x = a0 + b0;                       \
    res->y = a1 + b1;                       \
    res->z = a2 + b2;                       \
    res->w = a3 + b3;
#define __GLXFORM2_W_INIT(v)                \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat mat00, mat01, mat02;          \
    __GLfloat mat10, mat11, mat12;          \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0, a1, a2;                   \
    __GLfloat b0, b1, b2;                   \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
    mat02 = m->matrix[0][2];                \
                                            \
    mat10 = m->matrix[1][0];                \
    mat11 = m->matrix[1][1];                \
    mat12 = m->matrix[1][2];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];
#define __GLXFORM2_W(res)                   \
    a0 = x * mat00;                         \
    a1 = x * mat01;                         \
    a2 = x * mat02;                         \
                                            \
    b0 = y * mat10;                         \
    b1 = y * mat11;                         \
    b2 = y * mat12;                         \
                                            \
    a0 += mat30;                            \
    a1 += mat31;                            \
    a2 += mat32;                            \
                                            \
    res->x = a0 + b0;                       \
    res->y = a1 + b1;                       \
    res->z = a2 + b2;                       \
    res->w = ((__GLfloat) 1.0);
#define __GLXFORM2_2DW_INIT(v)              \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat mat00, mat01;                 \
    __GLfloat mat10, mat11;                 \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0, a1;                       \
    __GLfloat b0, b1;                       \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
                                            \
    mat10 = m->matrix[1][0];                \
    mat11 = m->matrix[1][1];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];
#define __GLXFORM2_2DW(res)                 \
    a0 = x * mat00;                         \
    a1 = x * mat01;                         \
                                            \
    b0 = y * mat10;                         \
    b1 = y * mat11;                         \
                                            \
    a0 += mat30;                            \
    a1 += mat31;                            \
                                            \
    res->x = a0 + b0;                       \
    res->y = a1 + b1;                       \
    res->z = mat32;                         \
    res->w = ((__GLfloat) 1.0);
#define __GLXFORM2_2DNRW_INIT(v)            \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat mat00;                        \
    __GLfloat mat11;                        \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0, b0;                       \
                                            \
    mat00 = m->matrix[0][0];                \
                                            \
    mat11 = m->matrix[1][1];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];
#define __GLXFORM2_2DNRW(res)               \
    a0 = x * mat00;                         \
                                            \
    b0 = y * mat11;                         \
                                            \
    res->x = a0 + mat30;                    \
    res->y = b0 + mat31;                    \
    res->z = mat32;                         \
    res->w = ((__GLfloat) 1.0);
#define __GLXFORM3_INIT(v)                  \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat z = (v)[2];                   \
    __GLfloat mat00, mat01, mat02, mat03;   \
    __GLfloat mat10, mat11, mat12, mat13;   \
    __GLfloat mat20, mat21, mat22, mat23;   \
    __GLfloat mat30, mat31, mat32, mat33;   \
    __GLfloat a0, a1, a2, a3;               \
    __GLfloat b0, b1, b2, b3;               \
    __GLfloat c0, c1, c2, c3;               \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
    mat02 = m->matrix[0][2];                \
    mat03 = m->matrix[0][3];                \
                                            \
    mat10 = m->matrix[1][0];                \
    mat11 = m->matrix[1][1];                \
    mat12 = m->matrix[1][2];                \
    mat13 = m->matrix[1][3];                \
                                            \
    mat20 = m->matrix[2][0];                \
    mat21 = m->matrix[2][1];                \
    mat22 = m->matrix[2][2];                \
    mat23 = m->matrix[2][3];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];                \
    mat33 = m->matrix[3][3];
#define __GLXFORM3(res)                     \
    a0 = mat00 * x;                         \
    a1 = mat01 * x;                         \
    a2 = mat02 * x;                         \
    a3 = mat03 * x;                         \
                                            \
    b0 = mat10 * y;                         \
    b1 = mat11 * y;                         \
    b2 = mat12 * y;                         \
    b3 = mat13 * y;                         \
                                            \
    c0 = mat20 * z;                         \
    c1 = mat21 * z;                         \
    c2 = mat22 * z;                         \
    c3 = mat23 * z;                         \
                                            \
    a0 += mat30;                            \
    a1 += mat31;                            \
    a2 += mat32;                            \
    a3 += mat33;                            \
                                            \
    a0 += b0;                               \
    a1 += b1;                               \
    a2 += b2;                               \
    a3 += b3;                               \
                                            \
    res->x = a0 + c0;                       \
    res->y = a1 + c1;                       \
    res->z = a2 + c2;                       \
    res->w = a3 + c3;
#define __GLXFORM3_W_INIT(v)                \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat z = (v)[2];                   \
    __GLfloat mat00, mat01, mat02;          \
    __GLfloat mat10, mat11, mat12;          \
    __GLfloat mat20, mat21, mat22;          \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0, a1, a2;                   \
    __GLfloat b0, b1, b2;                   \
    __GLfloat c0, c1, c2;                   \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
    mat02 = m->matrix[0][2];                \
                                            \
    mat10 = m->matrix[1][0];                \
    mat11 = m->matrix[1][1];                \
    mat12 = m->matrix[1][2];                \
                                            \
    mat20 = m->matrix[2][0];                \
    mat21 = m->matrix[2][1];                \
    mat22 = m->matrix[2][2];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];
#define __GLXFORM3x3_INIT(v)                \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat z = (v)[2];                   \
    __GLfloat mat00, mat01, mat02;          \
    __GLfloat mat10, mat11, mat12;          \
    __GLfloat mat20, mat21, mat22;          \
    __GLfloat a0, a1, a2;                   \
    __GLfloat b0, b1, b2;                   \
    __GLfloat c0, c1, c2;                   \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
    mat02 = m->matrix[0][2];                \
                                            \
    mat10 = m->matrix[1][0];                \
    mat11 = m->matrix[1][1];                \
    mat12 = m->matrix[1][2];                \
                                            \
    mat20 = m->matrix[2][0];                \
    mat21 = m->matrix[2][1];                \
    mat22 = m->matrix[2][2];                \
                                            \
#define __GLXFORM3x3(res)                   \
    a0 = mat00 * x;                         \
    a1 = mat01 * x;                         \
    a2 = mat02 * x;                         \
                                            \
    b0 = mat10 * y;                         \
    b1 = mat11 * y;                         \
    b2 = mat12 * y;                         \
                                            \
    c0 = mat20 * z;                         \
    c1 = mat21 * z;                         \
    c2 = mat22 * z;                         \
                                            \
    a0 += b0;                               \
    a1 += b1;                               \
    a2 += b2;                               \
                                            \
    res->x = a0 + c0;                       \
    res->y = a1 + c1;                       \
    res->z = a2 + c2;
#define __GLXFORM3_W(res)                   \
    a0 = mat00 * x;                         \
    a1 = mat01 * x;                         \
    a2 = mat02 * x;                         \
                                            \
    b0 = mat10 * y;                         \
    b1 = mat11 * y;                         \
    b2 = mat12 * y;                         \
                                            \
    c0 = mat20 * z;                         \
    c1 = mat21 * z;                         \
    c2 = mat22 * z;                         \
                                            \
    a0 += mat30;                            \
    a1 += mat31;                            \
    a2 += mat32;                            \
                                            \
    a0 += b0;                               \
    a1 += b1;                               \
    a2 += b2;                               \
                                            \
    res->x = a0 + c0;                       \
    res->y = a1 + c1;                       \
    res->z = a2 + c2;                       \
    res->w = ((__GLfloat) 1.0);
#define __GLXFORM3_2DW_INIT(v)              \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat z = (v)[2];                   \
    __GLfloat mat00, mat01;                 \
    __GLfloat mat10, mat11;                 \
    __GLfloat mat22;                        \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0, a1;                       \
    __GLfloat b0, b1;                       \
    __GLfloat c0;                           \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
    mat22 = m->matrix[2][2];                \
                                            \
    mat10 = m->matrix[1][0];                \
    mat11 = m->matrix[1][1];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];
#define __GLXFORM3_2DW(res)                 \
    a0 = mat00 * x;                         \
    a1 = mat01 * x;                         \
                                            \
    c0 = mat22 * z;                         \
                                            \
    b0 = mat10 * y;                         \
    b1 = mat11 * y;                         \
                                            \
    a0 += mat30;                            \
    a1 += mat31;                            \
                                            \
    res->x = a0 + b0;                       \
    res->y = a1 + b1;                       \
    res->z = c0 + mat32;                    \
    res->w = ((__GLfloat) 1.0);
#define __GLXFORM3_2DNRW_INIT(v)            \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat z = (v)[2];                   \
    __GLfloat mat00, mat11, mat22;          \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0;                           \
    __GLfloat b0;                           \
    __GLfloat c0;                           \
                                            \
    mat00 = m->matrix[0][0];                \
    mat11 = m->matrix[1][1];                \
    mat22 = m->matrix[2][2];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];
#define __GLXFORM3_2DNRW(res)               \
    a0 = mat00 * x;                         \
    b0 = mat11 * y;                         \
    c0 = mat22 * z;                         \
                                            \
    res->x = a0 + mat30;                    \
    res->y = b0 + mat31;                    \
    res->z = c0 + mat32;                    \
    res->w = ((__GLfloat) 1.0);
#define __GLXFORM4_INIT(v)                  \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat z = (v)[2];                   \
    __GLfloat w = (v)[3];                   \
                                            \
    __GLfloat mat00, mat01, mat02, mat03;   \
    __GLfloat mat10, mat11, mat12, mat13;   \
    __GLfloat mat20, mat21, mat22, mat23;   \
    __GLfloat mat30, mat31, mat32, mat33;   \
    __GLfloat a0, a1, a2, a3;               \
    __GLfloat b0, b1, b2, b3;               \
    __GLfloat c0, c1, c2, c3;               \
    __GLfloat d0, d1, d2, d3;               \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
    mat02 = m->matrix[0][2];                \
    mat03 = m->matrix[0][3];                \
                                            \
    mat10 = m->matrix[1][0];                \
    mat11 = m->matrix[1][1];                \
    mat12 = m->matrix[1][2];                \
    mat13 = m->matrix[1][3];                \
                                            \
    mat20 = m->matrix[2][0];                \
    mat21 = m->matrix[2][1];                \
    mat22 = m->matrix[2][2];                \
    mat23 = m->matrix[2][3];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];                \
    mat33 = m->matrix[3][3];
#define __GLXFORM4(res)                     \
    a0 = mat00 * x;                         \
    a1 = mat01 * x;                         \
    a2 = mat02 * x;                         \
    a3 = mat03 * x;                         \
                                            \
    b0 = mat10 * y;                         \
    b1 = mat11 * y;                         \
    b2 = mat12 * y;                         \
    b3 = mat13 * y;                         \
                                            \
    c0 = mat20 * z;                         \
    c1 = mat21 * z;                         \
    c2 = mat22 * z;                         \
    c3 = mat23 * z;                         \
                                            \
    d0 = mat30 * w;                         \
    d1 = mat31 * w;                         \
    d2 = mat32 * w;                         \
    d3 = mat33 * w;                         \
                                            \
    a0 += b0;                               \
    a1 += b1;                               \
    a2 += b2;                               \
    a3 += b3;                               \
                                            \
    a0 += c0;                               \
    a1 += c1;                               \
    a2 += c2;	                            \
    a3 += c3;                               \
                                            \
    res->x = a0 + d0;                       \
    res->y = a1 + d1;                       \
    res->z = a2 + d2;                       \
    res->w = a3 + d3;
#define __GLXFORM4_W_INIT(v)                \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat z = (v)[2];                   \
    __GLfloat w = (v)[3];                   \
    __GLfloat mat00, mat01, mat02;          \
    __GLfloat mat10, mat11, mat12;          \
    __GLfloat mat20, mat21, mat22;          \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0, a1, a2;                   \
    __GLfloat b0, b1, b2;                   \
    __GLfloat c0, c1, c2;                   \
    __GLfloat d0, d1, d2;                   \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
    mat02 = m->matrix[0][2];                \
                                            \
    mat10 = m->matrix[1][0];                \
    mat11 = m->matrix[1][1];                \
    mat12 = m->matrix[1][2];                \
                                            \
    mat20 = m->matrix[2][0];                \
    mat21 = m->matrix[2][1];                \
    mat22 = m->matrix[2][2];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];
#define __GLXFORM4_W(res)                   \
    a0 = mat00 * x;                         \
    a1 = mat01 * x;                         \
    a2 = mat02 * x;                         \
                                            \
    b0 = mat10 * y;                         \
    b1 = mat11 * y;                         \
    b2 = mat12 * y;                         \
                                            \
    c0 = mat20 * z;                         \
    c1 = mat21 * z;                         \
    c2 = mat22 * z;                         \
                                            \
    d0 = mat30 * w;                         \
    d1 = mat31 * w;                         \
    d2 = mat32 * w;                         \
                                            \
    a0 += b0;                               \
    a1 += b1;                               \
    a2 += b2;                               \
                                            \
    a0 += c0;                               \
    a1 += c1;                               \
    a2 += c2;                               \
                                            \
    res->x = a0 + d0;                       \
    res->y = a1 + d1;                       \
    res->z = a2 + d2;                       \
    res->w = w;
#define __GLXFORM4_2DW_INIT(v)              \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat z = (v)[2];                   \
    __GLfloat w = (v)[3];                   \
    __GLfloat mat00, mat01;                 \
    __GLfloat mat10, mat11;                 \
    __GLfloat mat22;                        \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0, a1;                       \
    __GLfloat b0, b1;                       \
    __GLfloat c0;                           \
    __GLfloat d0;                           \
                                            \
    mat00 = m->matrix[0][0];                \
    mat01 = m->matrix[0][1];                \
    mat22 = m->matrix[2][2];                \
                                            \
    mat10 = m->matrix[1][0];                \
    mat11 = m->matrix[1][1];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];
#define __GLXFORM4_2DW(res)                 \
    a0 = mat00 * x;                         \
    a1 = mat01 * x;                         \
    c0 = mat22 * z;                         \
                                            \
    b0 = mat10 * y;                         \
    b1 = mat11 * y;                         \
                                            \
    d0 = mat32 * w;                         \
                                            \
    a0 += mat30;                            \
    a1 += mat31;                            \
                                            \
    res->x = a0 + b0;                       \
	res->y = a1 + b1;                       \
    res->z = c0 + d0;                       \
    res->w = w;
#define __GLXFORM4_2DNRW_INIT(v)            \
    __GLfloat x = (v)[0];                   \
    __GLfloat y = (v)[1];                   \
    __GLfloat z = (v)[2];                   \
    __GLfloat w = (v)[3];                   \
    __GLfloat mat00;                        \
    __GLfloat mat11;                        \
    __GLfloat mat22;                        \
    __GLfloat mat30, mat31, mat32;          \
    __GLfloat a0;                           \
    __GLfloat b0;                           \
    __GLfloat c0;                           \
    __GLfloat d0, d1, d2;                   \
                                            \
    mat00 = m->matrix[0][0];                \
    mat11 = m->matrix[1][1];                \
    mat22 = m->matrix[2][2];                \
                                            \
    mat30 = m->matrix[3][0];                \
    mat31 = m->matrix[3][1];                \
    mat32 = m->matrix[3][2];
#define __GLXFORM4_2DNRW(res)               \
    a0 = mat00 * x;                         \
    b0 = mat11 * y;                         \
    c0 = mat22 * z;                         \
                                            \
    d0 = mat30 * w;                         \
    d1 = mat31 * w;                         \
    d2 = mat32 * w;                         \
                                            \
    res->x = a0 + d0;                       \
    res->y = b0 + d1;                       \
    res->z = c0 + d2;                       \
    res->w = w;
#define __GLXFORM_BATCH(funcName, initFunc, workFunc, continueFunc)         \
void FASTCALL funcName(__GLcoord *res, __GLcoord *end, const __GLmatrix *m) \
{                                                                           \
    initFunc((__GLfloat *)res);                                             \
                                                                            \
    for (;;) {                                                              \
        workFunc(res);                                                      \
        (char *)res += sizeof(POLYDATA);                                    \
        if (res > end)                                                      \
            break;                                                          \
        continueFunc((__GLfloat *)res);                                     \
    }                                                                       \
}

// multimedia\opengl\test\conform\ctk\ctk.h
#define TK_WIND_IS_CI(x)	((x) & TK_WIND_CI)
#define TK_WIND_IS_SB(x)	(((x) & TK_WIND_DB) == 0)
#define TK_WIND_IS_DB(x)	((x) & TK_WIND_DB)

// multimedia\opengl\test\demos\viewer\viewer.rc
#define SBS_VERT_TAB    ( SBS_VERT | WS_TABSTOP )

// multimedia\opengl\test\gldd\single\ddwave.c
#define GETCOORD(frame, x, y) (&(theMesh.coords[frame*theMesh.numCoords+(x)+(y)*(theMesh.widthX+1)]))
#define GETFACET(frame, x, y) (&(theMesh.facets[frame*theMesh.numFacets+(x)+(y)*theMesh.widthX]))

// multimedia\opengl\test\glut\glut.h
#define GLUT_STROKE_ROMAN		(&glutStrokeRoman)
#define GLUT_STROKE_MONO_ROMAN		(&glutStrokeMonoRoman)

// multimedia\opengl\test\glut\src\gltcindx.c
#define CLAMP(i) \
    ((i) > (GLfloat) 1.0 ? \
     (GLfloat) 1.0 : \
     ((i) < (GLfloat) 0.0 ? \
      (GLfloat) 0.0 : \
      (i)))

// multimedia\opengl\test\glut\src\gltint.h
#define GLUT_WIND_IS_INDEX(x)       (((x) & GLUT_INDEX) != 0)
#define GLUT_WIND_IS_SINGLE(x)      (((x) & GLUT_DOUBLE) == 0)
#define GLUT_WIND_IS_DOUBLE(x)      (((x) & GLUT_DOUBLE) != 0)
#define GLUT_WIND_IS_INDIRECT(x)    (((x) & GLUT_INDIRECT) != 0)
#define GLUT_WIND_IS_DIRECT(x)      (((x) & GLUT_INDIRECT) == 0)
#define GLUT_WIND_HAS_ACCUM(x)      (((x) & GLUT_ACCUM) != 0)
#define GLUT_WIND_HAS_ALPHA(x)      (((x) & GLUT_ALPHA) != 0)
#define GLUT_WIND_HAS_DEPTH(x)      (((x) & GLUT_DEPTH) != 0)
#define GLUT_WIND_HAS_STENCIL(x)    (((x) & GLUT_STENCIL) != 0)
#define GLUT_WIND_IS_MULTISAMPLE(x) (((x) & GLUT_MULTISAMPLE) != 0)
#define GLUT_WIND_IS_STEREO(x)      (((x) & GLUT_STEREO) != 0)

// multimedia\opengl\test\glut\src\stroke.h
#define START_PATH(_num_ch_, _num_props)  (START_DISPATCH(_num_props) + sizeof(Dispatch) * _num_ch_)

// multimedia\opengl\test\glut\src\xgltget.c
#define GET_CONFIG(attrib) \
  glXGetConfig(__glutXDisplay, __glutCurrentWindow->osurf, \
    attrib, &value);

// multimedia\opengl\test\glwin\single\glw.c
#define GETCOORD(frame, x, y) (&(theMesh.coords[frame*theMesh.numCoords+(x)+(y)*(theMesh.widthX+1)]))
#define GETFACET(frame, x, y) (&(theMesh.facets[frame*theMesh.numFacets+(x)+(y)*theMesh.widthX]))

// multimedia\opengl\test\misc\font\charspin\charspin.rc
#define SBS_VERT_TAB    ( SBS_VERT | WS_TABSTOP )

// multimedia\opengl\test\misc\membrane\wave.cxx
#define GETWCOORD(frame, x, y) (&(mesh.coords[frame*mesh.numCoords+(x)+(y)*(iWidthX+1)]))
#define GETFACET(frame, x, y) (&(mesh.facets[frame*mesh.numFacets+(x)+(y)*iWidthX]))

// multimedia\opengl\test\profiler\macros.h
#define CB_DlgSetRedraw(hDlg, iControl, bDraw) \
        SendDlgItemMessage(hDlg, iControl, WM_SETREDRAW, bDraw, 0)

// multimedia\opengl\test\samples\ddtex.c
#define NEXT_TRAIL_IDX(idx) (((idx)+1) & (TRAIL-1))
#define NEXT_TRAIL_HUE(hue) \
    ((hue) < (360.0-HUE_STEP) ? (hue)+HUE_STEP : (hue)+HUE_STEP-360.0)

// multimedia\opengl\test\samples\twave.c
#define GETCOORD(frame, x, y) (&(theMesh.coords[frame*theMesh.numCoords+(x)+(y)*(theMesh.widthX+1)]))
#define GETFACET(frame, x, y) (&(theMesh.facets[frame*theMesh.numFacets+(x)+(y)*theMesh.widthX]))

// multimedia\opengl\test\samples\twave2.c
#define GETCOORD(frame, x, y) (&(theMesh.coords[frame*theMesh.numCoords+(x)+(y)*(theMesh.widthX+1)]))
#define GETFACET(frame, x, y) (&(theMesh.facets[frame*theMesh.numFacets+(x)+(y)*theMesh.widthX]))

// multimedia\opengl\test\seepal\seepal.rc
#define SBS_VERT_TAB    ( SBS_VERT | WS_TABSTOP )

// multimedia\opengl\test\simple\ci\timecube\timecube.rc
#define SBS_VERT_TAB    ( SBS_VERT | WS_TABSTOP )

// multimedia\opengl\toolkits\libaux\tk.h
#define TK_IS_INDEX(x)		(((x) & TK_INDEX) != 0)
#define TK_IS_SINGLE(x)		(((x) & TK_DOUBLE) == 0)
#define TK_IS_DOUBLE(x)		(((x) & TK_DOUBLE) != 0)
#define TK_HAS_ACCUM(x)		(((x) & TK_ACCUM) != 0)
#define TK_HAS_ALPHA(x)		(((x) & TK_ALPHA) != 0)
#define TK_HAS_DEPTH(x)         (((x) & (TK_DEPTH24 | TK_DEPTH16)) != 0)
#define TK_HAS_STENCIL(x)	(((x) & TK_STENCIL) != 0)
#define TK_IS_DIRECT(x)		(((x) & TK_INDIRECT) == 0)
#define TK_IS_INDIRECT(x)       (((x) & TK_INDIRECT) != 0)
#define TK_USE_FIXED_332_PAL(x) (((x) & TK_FIXED_332_PAL) != 0)
#define TK_IS_DEPTH16(x)        (((x) & TK_DEPTH16) != 0)

// multimedia\opengl\toolkits\libmtk\mtk.h
#define SS_MAX( a, b ) \
    ( a > b ? a : b )
#define SS_MIN( a, b ) \
    ( a < b ? a : b )

// multimedia\opengl\toolkits\libmtk\mtkwin.cxx
#define NULL_UPDATE_RECT( pRect ) \
     (  ((pRect)->left == 0) && \
        ((pRect)->right == 0) && \
        ((pRect)->top == 0) && \
        ((pRect)->bottom == 0) )

// multimedia\opengl\toolkits\libtk\tk.h
#define TK_IS_INDEX(x)		(((x) & TK_INDEX) != 0)
#define TK_IS_SINGLE(x)		(((x) & TK_DOUBLE) == 0)
#define TK_IS_DOUBLE(x)		(((x) & TK_DOUBLE) != 0)
#define TK_HAS_ACCUM(x)		(((x) & TK_ACCUM) != 0)
#define TK_HAS_ALPHA(x)		(((x) & TK_ALPHA) != 0)
#define TK_HAS_DEPTH(x)		(((x) & TK_DEPTH) != 0)
#define TK_HAS_STENCIL(x)	(((x) & TK_STENCIL) != 0)
#define TK_IS_DIRECT(x)		(((x) & TK_INDIRECT) == 0)
#define TK_IS_INDIRECT(x)	(((x) & TK_INDIRECT) != 0)

// multimedia\published\directx\dmusic\inc\dmusicc.h
#define DSBUSID_IS_SPKR_LOC(id) ( ((id) >= DSBUSID_FIRST_SPKR_LOC) && ((id) <= DSBUSID_LAST_SPKR_LOC) )

// multimedia\published\directx\dmusic\inc\dmusicf.h
#define DMUS_VARIATIONF_MODES_EX     (0x20000000 | 0x80000000)
#define DMUS_SIGNPOSTF_LETTER   (DMUS_SIGNPOSTF_A | DMUS_SIGNPOSTF_B | DMUS_SIGNPOSTF_C | DMUS_SIGNPOSTF_D | DMUS_SIGNPOSTF_E | DMUS_SIGNPOSTF_F)
#define DMUS_SIGNPOSTF_ROOT     (DMUS_SIGNPOSTF_1 | DMUS_SIGNPOSTF_2 | DMUS_SIGNPOSTF_3 | DMUS_SIGNPOSTF_4 | DMUS_SIGNPOSTF_5 | DMUS_SIGNPOSTF_6 | DMUS_SIGNPOSTF_7)

// multimedia\published\directx\dmusic\inc\dmusici.h
#define DMUS_PLAYMODE_PEDALPOINT        (DMUS_PLAYMODE_KEY_ROOT | DMUS_PLAYMODE_SCALE_INTERVALS)
#define DMUS_PLAYMODE_MELODIC           (DMUS_PLAYMODE_CHORD_ROOT | DMUS_PLAYMODE_SCALE_INTERVALS)
#define DMUS_PLAYMODE_NORMALCHORD       (DMUS_PLAYMODE_CHORD_ROOT | DMUS_PLAYMODE_CHORD_INTERVALS)
#define DMUS_PLAYMODE_ALWAYSPLAY        (DMUS_PLAYMODE_MELODIC | DMUS_PLAYMODE_NORMALCHORD)
#define DMUS_PLAYMODE_PEDALPOINTCHORD   (DMUS_PLAYMODE_KEY_ROOT | DMUS_PLAYMODE_CHORD_INTERVALS)
#define DMUS_PLAYMODE_PEDALPOINTALWAYS  (DMUS_PLAYMODE_PEDALPOINT | DMUS_PLAYMODE_PEDALPOINTCHORD)
#define DMUS_TRACKCONFIG_DEFAULT    (DMUS_TRACKCONFIG_CONTROL_ENABLED | DMUS_TRACKCONFIG_PLAY_ENABLED | DMUS_TRACKCONFIG_NOTIFICATION_ENABLED)

// multimedia\published\directx\dsetup\dsetup.h
#define DSETUP_DIRECTX  (DSETUP_DXCORE|DSETUP_DDRAWDRV|DSETUP_DSOUNDDRV)

// multimedia\published\dxmdev\dshowdev\dmodev\include\dmoimpl.h
#define INTERNAL_CALL(_T_, _X_) \
    static_cast<_T_ *>(this)->Internal##_X_

// multimedia\published\dxmdev\dshowdev\include\amvideo.h
#define AMDDS_YUV (AMDDS_YUVOFF | AMDDS_YUVOVR | AMDDS_YUVFLP)
#define AMDDS_PRIMARY (AMDDS_DCIPS | AMDDS_PS)
#define HEADER(pVideoInfo) (&(((VIDEOINFOHEADER *) (pVideoInfo))->bmiHeader))

// multimedia\published\dxmdev\dshowdev\include\bdamedia.h
#define DEFINE_KSPROPERTY_ITEM_BDA_ETHERNET_FILTER_MULTICAST_LIST_SIZE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_ETHERNET_FILTER_MULTICAST_LIST_SIZE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(ULONG),\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_ETHERNET_FILTER_MULTICAST_LIST(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_ETHERNET_FILTER_MULTICAST_LIST,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(BDA_ETHERNET_ADDRESS_LIST),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_ETHERNET_FILTER_MULTICAST_MODE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_ETHERNET_FILTER_MULTICAST_MODE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(BDA_MULTICAST_MODE),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_IPv4_FILTER_MULTICAST_LIST_SIZE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_IPv4_FILTER_MULTICAST_LIST_SIZE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(ULONG),\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_IPv4_FILTER_MULTICAST_LIST(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_IPv4_FILTER_MULTICAST_LIST,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(BDA_IPv4_ADDRESS_LIST),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_IPv4_FILTER_MULTICAST_MODE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_IPv4_FILTER_MULTICAST_MODE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(BDA_MULTICAST_MODE),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_IPv6_FILTER_MULTICAST_LIST_SIZE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_IPv6_FILTER_MULTICAST_LIST_SIZE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(ULONG),\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_IPv6_FILTER_MULTICAST_LIST(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_IPv6_FILTER_MULTICAST_LIST,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(BDA_IPv6_ADDRESS_LIST),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_IPv6_FILTER_MULTICAST_MODE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_IPv6_FILTER_MULTICAST_MODE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(BDA_MULTICAST_MODE),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_SIGNAL_STRENGTH(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_SIGNAL_STRENGTH,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(LONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_SIGNAL_QUALITY(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_SIGNAL_QUALITY,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(LONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_SIGNAL_PRESENT(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_SIGNAL_PRESENT,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(BOOL),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_SIGNAL_LOCKED(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_SIGNAL_LOCKED,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(BOOL),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_SAMPLE_TIME(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_SAMPLE_TIME,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(LONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSMETHOD_ITEM_BDA_START_CHANGES(MethodHandler, SupportHandler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_BDA_START_CHANGES,\
        KSMETHOD_TYPE_NONE,\
        (MethodHandler),\
        sizeof(KSMETHOD),\
        0,\
        SupportHandler)
#define DEFINE_KSMETHOD_ITEM_BDA_CHECK_CHANGES(MethodHandler, SupportHandler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_BDA_CHECK_CHANGES,\
        KSMETHOD_TYPE_NONE,\
        (MethodHandler),\
        sizeof(KSMETHOD),\
        0,\
        SupportHandler)
#define DEFINE_KSMETHOD_ITEM_BDA_COMMIT_CHANGES(MethodHandler, SupportHandler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_BDA_COMMIT_CHANGES,\
        KSMETHOD_TYPE_NONE,\
        (MethodHandler),\
        sizeof(KSMETHOD),\
        0,\
        SupportHandler)
#define DEFINE_KSMETHOD_ITEM_BDA_GET_CHANGE_STATE(MethodHandler, SupportHandler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_BDA_GET_CHANGE_STATE,\
        KSMETHOD_TYPE_READ,\
        (MethodHandler),\
        sizeof(KSMETHOD),\
        0,\
        SupportHandler)
#define DEFINE_KSMETHOD_ITEM_BDA_CREATE_PIN_FACTORY(MethodHandler, SupportHandler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_BDA_CREATE_PIN_FACTORY,\
        KSMETHOD_TYPE_READ,\
        (MethodHandler),\
        sizeof(KSM_BDA_PIN),\
        sizeof(ULONG),\
        SupportHandler)
#define DEFINE_KSPROPERTY_ITEM_BDA_NODE_TYPES(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_NODE_TYPES,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        0,\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_PIN_TYPES(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_PIN_TYPES,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        0,\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_TEMPLATE_CONNECTIONS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_TEMPLATE_CONNECTIONS,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof( BDA_TEMPLATE_CONNECTION),\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_NODE_METHODS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_NODE_METHODS,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        0,\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_NODE_PROPERTIES(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_NODE_PROPERTIES,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        0,\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_NODE_EVENTS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_NODE_EVENTS,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        0,\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_CONTROLLING_PIN_ID(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_CONTROLLING_PIN_ID,\
        (GetHandler),\
        sizeof(KSP_BDA_NODE_PIN),\
        sizeof( ULONG),\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_NODE_DESCRIPTORS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_NODE_DESCRIPTORS,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        0,\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_PIN_ID(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_PIN_ID,\
        (GetHandler),\
        sizeof( KSPROPERTY),\
        sizeof( ULONG),\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_PIN_TYPE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_PIN_TYPE,\
        (GetHandler),\
        sizeof( KSPROPERTY),\
        sizeof( ULONG),\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSEVENT_ITEM_BDA_PIN_CONNECTED(AddHandler, RemoveHandler, SupportHandler)\
    DEFINE_KSEVENT_ITEM(\
        KSEVENT_BDA_PIN_CONNECTED,\
        sizeof( KSEVENTDATA), \
        0, \
        (AddHandler),\
        (RemoveHandler),\
        (SupportHandler)\
        )
#define DEFINE_KSEVENT_ITEM_BDA_PIN_DISCONNECTED(AddHandler, RemoveHandler, SupportHandler)\
    DEFINE_KSEVENT_ITEM(\
        KSEVENT_BDA_PIN_DISCONNECTED,\
        sizeof( KSEVENTDATA), \
        0, \
        (AddHandler),\
        (RemoveHandler),\
        (SupportHandler)\
        )
#define DEFINE_KSPROPERTY_ITEM_BDA_VOID_TRANSFORM_START(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_VOID_TRANSFORM_START,\
        FALSE,\
        sizeof(KSPROPERTY),\
        0,\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_VOID_TRANSFORM_STOP(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_VOID_TRANSFORM_STOP,\
        FALSE,\
        sizeof(KSPROPERTY),\
        0,\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_NULL_TRANSFORM_START(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_NULL_TRANSFORM_START,\
        FALSE,\
        sizeof(KSPROPERTY),\
        0,\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_NULL_TRANSFORM_STOP(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_NULL_TRANSFORM_STOP,\
        FALSE,\
        sizeof(KSPROPERTY),\
        0,\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_FREQUENCY(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_RF_TUNER_FREQUENCY,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_POLARITY(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_RF_TUNER_POLARITY,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_RANGE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_RF_TUNER_RANGE,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_TRANSPONDER(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_RF_TUNER_TRANSPONDER,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_BANDWIDTH(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_RF_TUNER_BANDWIDTH,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_FREQUENCY_MULTIPLIER(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_RF_TUNER_FREQUENCY_MULTIPLIER,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_LNB_LOF_LOW_BAND(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_LNB_LOF_LOW_BAND,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_LNB_LOF_HIGH_BAND(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_LNB_LOF_HIGH_BAND,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_LNB_SWITCH_FREQUENCY(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_LNB_SWITCH_FREQUENCY,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_MODULATION_TYPE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_MODULATION_TYPE,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ModulationType),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_INNER_FEC_TYPE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_INNER_FEC_TYPE,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(FECMethod),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_INNER_FEC_RATE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_INNER_FEC_RATE,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(BinaryConvolutionCodeRate),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_OUTER_FEC_TYPE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_OUTER_FEC_TYPE,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(FECMethod),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_OUTER_FEC_RATE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_OUTER_FEC_RATE,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(BinaryConvolutionCodeRate),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_SYMBOL_RATE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_SYMBOL_RATE,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_SPECTRAL_INVERSION(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_SPECTRAL_INVERSION,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(SpectralInversion),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_GUARD_INTERVAL(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_GUARD_INTERVAL,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(GuardInterval),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_TRANSMISSION_MODE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_TRANSMISSION_MODE,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(TransmissionMode),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_AUTODEMODULATE_START(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_AUTODEMODULATE_START,\
        FALSE,\
        sizeof(KSP_NODE),\
        0,\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_AUTODEMODULATE_STOP(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_AUTODEMODULATE_STOP,\
        FALSE,\
        sizeof(KSP_NODE),\
        0,\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_TABLE_SECTION(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_TABLE_SECTION,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(BDA_TABLE_SECTION),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_PIDFILTER_MAP_PIDS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_PIDFILTER_MAP_PIDS,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(BDA_PID_MAP),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_PIDFILTER_UNMAP_PIDS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_PIDFILTER_UNMAP_PIDS,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(BDA_PID_UNMAP),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_PIDFILTER_LIST_PIDS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_PIDFILTER_LIST_PIDS,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        0,\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_CA_MODULE_UI(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_CA_MODULE_UI,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(BDA_CA_MODULE_UI),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_CA_SET_PROGRAM_PIDS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_CA_SET_PROGRAM_PIDS,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(BDA_PROGRAM_PID_LIST),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_CA_REMOVE_PROGRAM(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_CA_REMOVE_PROGRAM,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSEVENT_BDA_CA_MODULE_UI_REQUESTED(AddHandler, RemoveHandler, SupportHandler)\
    DEFINE_KSEVENT_ITEM(\
        KSEVENT_BDA_CA_MODULE_UI_REQUESTED,\
        sizeof( KSEVENTDATA), \
        0, \
        (AddHandler),\
        (RemoveHandler),\
        (SupportHandler)\
        )

// multimedia\published\wmsdk\inc\des.h
#define DES_TABLESIZE   (sizeof(DESTable))
#define DESX_TABLESIZE  (sizeof(DESXTable))

// multimedia\reality\misc\lists.h
#define	LIST_INITIALIZE(root)\
{\
    (root)->Root = 0;\
}
#define	TAIL_QUEUE_INITIALIZE(root)\
{\
    (root)->First = NULL;\
    (root)->Last = &(root)->First;\
}
#define	CIRCLE_QUEUE_INITIALIZE(root,type)\
{   (root)->Last = (type *)(root);\
    (root)->First = (type *)(root);\
}
#define CIRCLE_QUEUE_INSERT_END(root,type,element,field)\
{   (element)->field.Prev = (root)->Last;\
    (element)->field.Next = (type *)(root);\
    if((root)->First != (type *)(root))\
	(root)->Last->field.Next = (element);\
    else\
	(root)->First = (element);\
    (root)->Last = (element);\
}
#define CIRCLE_QUEUE_INSERT_ROOT(root,type,element,field)\
{   (element)->field.Prev = (type *)(root);\
    (element)->field.Next = (root)->First;\
    if ((root)->Last != (void *)(root))\
	(root)->First->field.Prev = (element);\
    else\
	(root)->Last = (element);\
    (root)->First = (element);\
}
#define CIRCLE_QUEUE_INSERT_PREVIOUS(root,current_element,element,field)\
{   (element)->field.Prev = (current_element)->field.Prev;\
    (element)->field.Next = (current_element);\
    if ((current_element)->field.Prev != (void *)(root))\
	(current_element)->field.Prev->field.Next = (element);\
    else\
	(root)->First = (element);\
    (current_element)->field.Prev = (element);\
}
#define CIRCLE_QUEUE_FIRST(root)\
((root)->First == (void *) (root)? 0: (root)->First)
#define CIRCLE_QUEUE_LAST(root)\
((root)->Last == (void *) (root)? 0: (root)->Last)
#define CIRCLE_QUEUE_NEXT(root,element,field)\
((void *) (element)->field.Next == (void *) (root)? 0: (element)->field.Next)
#define CIRCLE_QUEUE_PREVIOUS(root,element,field)\
((element)->field.Prev == (void *) (root)? 0: (element)->field.Prev)

// net\1394\arp\kdext\parse.c
#define TL_LOCK(_ptl)   EnterCriticalSection(&(_ptl)->crit)
#define TL_UNLOCK(_ptl) LeaveCriticalSection(&(_ptl)->crit)

// net\1394\arp\sys\priv.h
    #define  TIMESTAMPX(_FormatString) \
        arpTimeStamp("TIMESTAMP %lu:%lu.%lu ARP1394 " _FormatString "\n", 0)
        #define  TIMESTAMP(_FormatString) \
            arpTimeStamp("TIMESTAMP %lu:%lu.%lu ARP1394 " _FormatString "\n", 0)
        #define  TIMESTAMP1(_FormatString, _Val) \
            arpTimeStamp("TIMESTAMP %lu:%lu.%lu ARP1394 " _FormatString "\n", (_Val))

// net\atm\arp\atmarpc\macros.h
#define AA_INIT_IF_TIMER_LOCK(pIf)		\
				AA_INIT_LOCK(&((pIf)->TimerLock))
#define AA_ACQUIRE_IF_TIMER_LOCK(pIf)		\
				AA_ACQUIRE_LOCK(&((pIf)->TimerLock))
#define AA_ACQUIRE_IF_TIMER_LOCK_DPC(pIf)		\
				AA_ACQUIRE_LOCK_DPC(&((pIf)->TimerLock))
#define AA_STOP_SYSTEM_TIMER(pTimer)						\
			{												\
				BOOLEAN		WasCancelled;					\
				NdisCancelTimer(pTimer, &WasCancelled);		\
			}
#define AtmArpRefreshTimer(_pTmr)												\
{																				\
	PATMARP_TIMER_LIST	_pTimerList;											\
																				\
	if ((_pTimerList = (_pTmr)->pTimerList) != (PATMARP_TIMER_LIST)NULL)		\
	{																			\
		(_pTmr)->LastRefreshTime = _pTimerList->CurrentTick;					\
	}																			\
}

// net\atm\arp\atmarps\timer.h
#define	ArpSTimerInitialize(pTimer, TimerRoutine, DeltaTime)	\
	{															\
		(pTimer)->Routine = TimerRoutine;						\
		(pTimer)->AbsTime = DeltaTime;							\
	}

// net\atm\arp\kdext\parse.c
#define TL_LOCK(_ptl)   EnterCriticalSection(&(_ptl)->crit)
#define TL_UNLOCK(_ptl) LeaveCriticalSection(&(_ptl)->crit)

// net\atm\epvc\sys\macros.h
    #define  TIMESTAMP(_FormatString) \
        epvcTimeStamp( "TIMESTAMP %lu:%lu.%lu ATMEPVC " _FormatString "\n", 0)
    #define  TIMESTAMP1(_FormatString, _Val) \
        epvcTimeStamp( "TIMESTAMP %lu:%lu.%lu ATMEPVC " _FormatString "\n", (_Val))

// net\atm\lane\sys\macros.h
#define INIT_ELAN_TIMER_LOCK(pElan)		\
				INIT_LOCK(&((pElan)->TimerLock), "timer")
#define INIT_ELAN_TIMER_LOCK(pElan)		\
				INIT_LOCK(&((pElan)->TimerLock))
#define ACQUIRE_ELAN_TIMER_LOCK(pElan)		\
				ACQUIRE_LOCK(&((pElan)->TimerLock), "timer")
#define ACQUIRE_ELAN_TIMER_LOCK(pElan)		\
				ACQUIRE_LOCK(&((pElan)->TimerLock))
#define ACQUIRE_ELAN_TIMER_LOCK_DPC(pElan)		\
				ACQUIRE_LOCK_DPC(&((pElan)->TimerLock), "timer")
#define ACQUIRE_ELAN_TIMER_LOCK_DPC(pElan)		\
				ACQUIRE_LOCK_DPC(&((pElan)->TimerLock))
#define STOP_SYSTEM_TIMER(pTimer)						\
			{												\
				BOOLEAN		WasCancelled;					\
				NdisCancelTimer(pTimer, &WasCancelled);		\
			}

// net\atm\samples\atmsmpl\driver\atmsmdrv.h
#define SET_ADAPTER_RECV_TIMER(pA, uiTimerDelay) {  \
        NdisSetTimer(&pA->RecvTimerOb,              \
                      uiTimerDelay);                \
        pA->fRecvTimerQueued = TRUE;                \
    }
#define CANCEL_ADAPTER_RECV_TIMER(pA, pfTimerCancelled) {   \
        NdisCancelTimer(&pA->RecvTimerOb,                   \
                         pfTimerCancelled);                 \
        pA->fRecvTimerQueued = FALSE;                       \
    }

// net\config\netman\eapol\service\elsync.h
#define INITIALIZE_LOCKED_LIST(pLL, szName)                         \
{                                                                   \
    do                                                              \
    {                                                               \
        sprintf((pLL)->name, "%.3s", szName);                       \
        __try {                                                     \
            InitializeCriticalSection(&((pLL)->lock));              \
        }                                                           \
        __except (EXCEPTION_EXECUTE_HANDLER) {                      \
            break;                                                  \
        }                                                           \
        InitializeListHead(&((pLL)->head));                         \
        (pLL)->created = 0x12345678;                                \
    } while (FALSE);                                                \
}
#define AcquireListLock(pLL)    EnterCriticalSection(&(pLL)->lock)

// net\config\netoc\sfmsec.cpp
#define AFP_MIN_ACCESS          (FILE_READ_ATTRIBUTES | READ_CONTROL)
#define AFP_READ_ACCESS         (READ_CONTROL           |      \
                                                        FILE_READ_ATTRIBUTES |  \
                                                        FILE_TRAVERSE            |      \
                                                        FILE_LIST_DIRECTORY      |      \
                                                        FILE_READ_EA)
#define AFP_OWNER_ACCESS        (WRITE_DAC                        | \
                                                         WRITE_OWNER)

// net\config\shell\inc\cfpidl.h
#define CBCONFOLDPIDLV1_MIN      sizeof(ConFoldPidl_v1)
#define CBCONFOLDPIDLV2_MIN      sizeof(ConFoldPidl_v2)
#define CBCONFOLDPIDL98_MIN      sizeof(CONFOLDPIDL98)

// net\dhcp\client\inc\dhcpdef.h
#define LOCK_RENEW_LIST()       EnterCriticalSection(&DhcpGlobalRenewListCritSect)
#define UNLOCK_RENEW_LIST()     LeaveCriticalSection(&DhcpGlobalRenewListCritSect)
#define LOCK_INTERFACE()        EnterCriticalSection(&DhcpGlobalSetInterfaceCritSect)
#define UNLOCK_INTERFACE()      LeaveCriticalSection(&DhcpGlobalSetInterfaceCritSect)
#define LOCK_OPTIONS_LIST()     EnterCriticalSection(&DhcpGlobalOptionsListCritSect)
#define UNLOCK_OPTIONS_LIST()   LeaveCriticalSection(&DhcpGlobalOptionsListCritSect)

// net\dhcp\client\inc\mdhcpcli.h
#define LOCK_MSCOPE_LIST()   EnterCriticalSection(&MadcapGlobalScopeListCritSect)
#define UNLOCK_MSCOPE_LIST() LeaveCriticalSection(&MadcapGlobalScopeListCritSect)

// net\dhcp\client\nt\dhcploc.h
#define LOCK_POPUP()   EnterCriticalSection(&DhcpGlobalPopupCritSect)
#define UNLOCK_POPUP() LeaveCriticalSection(&DhcpGlobalPopupCritSect)

// net\dhcp\server\binl\binldef.h
#define LOCK_INPROGRESS_LIST()   EnterCriticalSection(&BinlGlobalInProgressCritSect)
#define UNLOCK_INPROGRESS_LIST() LeaveCriticalSection(&BinlGlobalInProgressCritSect)
#define LOCK_RECV_LIST()   EnterCriticalSection(&BinlGlobalRecvListCritSect)
#define UNLOCK_RECV_LIST() LeaveCriticalSection(&BinlGlobalRecvListCritSect)

// net\dhcp\server\mmreg\regflush.c
#define LOCK_MEMORY()            EnterCriticalSection(&DhcpGlobalMemoryCritSect)
#define UNLOCK_MEMORY()          LeaveCriticalSection(&DhcpGlobalMemoryCritSect)
#define LOCK_INPROGRESS_LIST()   EnterCriticalSection(&DhcpGlobalInProgressCritSect)
#define UNLOCK_INPROGRESS_LIST() LeaveCriticalSection(&DhcpGlobalInProgressCritSect)

// net\dhcp\server\server\callout.c
#define    CALLOUT_RENEW_DHCP(P,Addr,Time,Exists) \
    _GiveAddrPkt(P, (Exists)?DHCP_GIVE_ADDRESS_OLD: \
       DHCP_GIVE_ADDRESS_NEW,DHCP_CLIENT_DHCP, Addr, Time)

// net\dhcp\server\server\callout.h
#define    CALLOUT_RENEW_DHCP(P,Addr,Time,Exists) \
    _GiveAddrPkt(P, (Exists)?DHCP_GIVE_ADDRESS_OLD: \
       DHCP_GIVE_ADDRESS_NEW,DHCP_CLIENT_DHCP, Addr, Time)

// net\dhcp\server\server\cltapi.c
#define IS_INFINITE_LEASE(DateTime)  \
    ( (DateTime).dwLowDateTime == DHCP_DATE_TIME_INFINIT_LOW && \
      (DateTime).dwHighDateTime == DHCP_DATE_TIME_INFINIT_HIGH )
#define IS_ZERO_LEASE(DateTime) \
    ((DateTime).dwLowDateTime == 0 && (DateTime).dwHighDateTime == 0)

// net\dhcp\server\server\dhcpreg.h
#define LOCK_REGISTRY()                           EnterCriticalSection(&DhcpGlobalRegCritSect)
#define UNLOCK_REGISTRY()                         LeaveCriticalSection(&DhcpGlobalRegCritSect)

// net\dhcp\server\server\dnsdb.c
#define LOCK_MEM() EnterCriticalSection(&DhcpGlobalDnsMemoryCriticalSection)
#define UNLOCK_MEM() LeaveCriticalSection(&DhcpGlobalDnsMemoryCriticalSection)

// net\dhcp\server\server\ping.c
#define LOCK_REPLIES_LIST()    EnterCriticalSection(&IcmpRepliesCritSect)
#define LOCK_REQUESTS_LIST()   EnterCriticalSection(&IcmpRequestsCritSect)
#define LOCK_OUTPUT()          EnterCriticalSection(&OutputCritSect)
#define UNLOCK_REPLIES_LIST()  LeaveCriticalSection(&IcmpRepliesCritSect)
#define UNLOCK_REQUESTS_LIST() LeaveCriticalSection(&IcmpRequestsCritSect)
#define UNLOCK_OUTPUT()        LeaveCriticalSection(&OutputCritSect)

// net\diagnostics\netdiag\modemtst.c
#define PRINT_MODEM( _i, _ids, _mdm) \
        PrintMessage(pParams, _ids, \
         MAP_ON_OFF(pResults->Modem.pModemDevice[_i].dwModemOptions & _mdm))

// net\homenet\alg\alg_icq\nathlpp.h
#define ACQUIRE_LOCK(x)         EnterCriticalSection(&(x)->Lock)

// net\homenet\alg\exe\scopecriticalsection.h
#define ENTER_AUTO_CS CScopeCriticalSection _ScopeAutoCriticalSection(&m_AutoCS);

// net\ias\mmc\atl25\atlsnap.h
#define END_EXTENSION_SNAPIN_NODEINFO_MAP() \
         return CSnapInItem::GetDataClass(pDataObject, ppItem, pType); \
   };
#define END_SNAPINCOMMAND_MAP() \
         return hr; \
   }
#define BEGIN_SNAPINTOOLBARID_MAP(theClass) \
public: \
   static CSnapInToolbarInfo* GetToolbarInfo() \
   { \
      static CSnapInToolbarInfo m_toolbarInfo[] = \
      {
#define END_SNAPINTOOLBARID_MAP() \
         { NULL, NULL, NULL, 0, 0} \
      }; \
      return m_toolbarInfo; \
   }

// net\inc\cxport.h
#define CTEStopTimer(Timer)  ((int) KeCancelTimer(&((Timer)->t_timer)))

// net\inc\ipsecshr.h
#define IN_CLASSE(i)    (((long)(i) & 0xF0000000) == 0xF0000000)

// net\inc\nbfhdrs.h
#define RESPONSE_CORR(_Hdr)      (*TempUShortCast( &(_Hdr)->ResponseCorrelator ))

// net\inc\stropts.h
#define	I_SETCLTIME	(STR|27)
#define	I_GETCLTIME	(STR|28)

// net\ipsec\spd\server\address.h
#define IN_CLASSE(i)    (((long)(i) & 0xF0000000) == 0xF0000000)

// net\ipsec\spd\server\precomp.h
#define ENTER_SPD_SECTION()             \
    EnterCriticalSection(&gcSPDSection) \
#define LEAVE_SPD_SECTION()             \
    LeaveCriticalSection(&gcSPDSection) \

// net\ipsec\spd\server\security.h
#define SERVER_READ (STANDARD_RIGHTS_READ |\
                     SERVER_ACCESS_ENUMERATE)
#define SERVER_WRITE (STANDARD_RIGHTS_WRITE |\
                      SERVER_ACCESS_ADMINISTER |\
                      SERVER_ACCESS_ENUMERATE)
#define SERVER_EXECUTE (STANDARD_RIGHTS_EXECUTE |\
                        SERVER_ACCESS_ENUMERATE)
#define SERVER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED |\
                           SERVER_ACCESS_ADMINISTER |\
                           SERVER_ACCESS_ENUMERATE)

// net\irda\irxfer\xfer.h
#define TIMEOUT_INFINITE            (~0UL)
#define OBEX_PARAM_ISO_TIME           ( 0x04 | OBEX_PARAM_STREAM  )

// net\jet500\jet\dae\inc\dirapi.h
#define DIRSetFresh( pfucb )		 									   	\
	{																	   	\
	PcsrCurrent( pfucb )->ulDBTime = UlSTDBTimePssib( &(pfucb)->ssib ); 	\
	}
#define DIRSetRefresh( pfucb )  										   	\
	{																	   	\
	PcsrCurrent( pfucb )->ulDBTime = ulDBTimeNull; 						   	\
	}

// net\jet500\jet\dae\src\dir.c
#define ErrDIRIRefresh( pfucb )													\
	( !( FBFReadLatchConflict( pfucb->ppib, pfucb->ssib.pbf ) ) &&							\
		PcsrCurrent(pfucb)->ulDBTime == UlSTDBTimePssib( &pfucb->ssib ) ?		\
		JET_errSuccess : ErrDIRIIRefresh( pfucb ) )

// net\jet500\xjet\inc\dirapi.h
#define DIRSetFresh( pfucb )		 									   	\
	{																	   	\
	PcsrCurrent( pfucb )->qwDBTime = QwSTDBTimePssib( &(pfucb)->ssib ); 	\
	}
#define DIRSetRefresh( pfucb )  										   	\
	{																	   	\
	PcsrCurrent( pfucb )->qwDBTime = qwDBTimeNull; 						   	\
	}

// net\jet500\xjet\src\dir.c
#define ErrDIRIRefresh( pfucb )													\
	( !( FBFReadLatchConflict( pfucb->ppib, pfucb->ssib.pbf ) ) &&							\
		PcsrCurrent(pfucb)->qwDBTime == QwSTDBTimePssib( &pfucb->ssib ) ?		\
		JET_errSuccess : ErrDIRIIRefresh( pfucb ) )

// net\layer2svc\eapol\service\elsync.h
#define INITIALIZE_LOCKED_LIST(pLL, szName)                         \
{                                                                   \
    do                                                              \
    {                                                               \
        sprintf((pLL)->name, "%.3s", szName);                       \
        __try {                                                     \
            InitializeCriticalSection(&((pLL)->lock));              \
        }                                                           \
        __except (EXCEPTION_EXECUTE_HANDLER) {                      \
            break;                                                  \
        }                                                           \
        InitializeListHead(&((pLL)->head));                         \
        (pLL)->created = 0x12345678;                                \
    } while (FALSE);                                                \
}
#define AcquireListLock(pLL)    EnterCriticalSection(&(pLL)->lock)

// net\layer2svc\wlpolicy\precomp.h
#define ENTER_SPD_SECTION()             \
    EnterCriticalSection(&gcSPDSection) \
#define LEAVE_SPD_SECTION()             \
    LeaveCriticalSection(&gcSPDSection) \

// net\layer2svc\wlpolicy\security.h
#define SERVER_READ (STANDARD_RIGHTS_READ |\
                     SERVER_ACCESS_ENUMERATE)
#define SERVER_WRITE (STANDARD_RIGHTS_WRITE |\
                      SERVER_ACCESS_ADMINISTER |\
                      SERVER_ACCESS_ENUMERATE)
#define SERVER_EXECUTE (STANDARD_RIGHTS_EXECUTE |\
                        SERVER_ACCESS_ENUMERATE)
#define SERVER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED |\
                           SERVER_ACCESS_ADMINISTER |\
                           SERVER_ACCESS_ENUMERATE)

// net\layer2svc\wlsnp\snpdata.h
#define BEGIN_SNAPINTOOLBARID_MAP(theClass) \
public: \
    STDMETHOD_(CSnapInToolbarInfo*, GetToolbarInfo)(void) \
{ \
    if (NULL == m_aToolbarInfo) \
{ \
    CSnapInToolbarInfo m_tbInfo_##theClass[] = \
{

// net\mcast\pgm\inc\macroes.h
#define PgmInitTimer(_PgmTimer)    \
    KeInitializeTimer (&((_PgmTimer)->t_timer));
#define PgmStartTimer(_PgmTimer, _DeltaTimeInMilliSecs, _TimerExpiryRoutine, _Context)  \
{                                                                                       \
    LARGE_INTEGER   Time;                                                               \
    Time.QuadPart = UInt32x32To64 (_DeltaTimeInMilliSecs, MILLISEC_TO_100NS);           \
    Time.QuadPart = -(Time.QuadPart);                                                   \
    KeInitializeDpc (&((_PgmTimer)->t_dpc), (PVOID)_TimerExpiryRoutine, _Context);      \
    KeSetTimer (&((_PgmTimer)->t_timer), Time, &((_PgmTimer))->t_dpc);                  \
}
#define PgmStopTimer(_PgmTimer)     \
    ((int) KeCancelTimer(&((_PgmTimer)->t_timer)))

// net\mmc\common\intltime.cpp
    #define GETINTFIELD(field, integer)\
         ::GetLocaleInfo(GetUserDefaultLCID(), field, str, MAXSTR);\
         integer = _ttol(str)
    #define GETBOOLFIELD(field, boolean)\
         ::GetLocaleInfo(GetUserDefaultLCID(), field, str, MAXSTR);\
         boolean=*str == '1'
    #define GETINTFIELD(field, integer, defint)\
        integer = ::GetProfileInt("Intl", field, defint)
    #define GETBOOLFIELD(field, boolean, defint)\
        boolean = ::GetProfileInt("Intl", field, defint)==1

// net\mmc\ipsecmon\gtusrdlg.h
#define USRBROWS_INCL_ALL           (USRBROWS_INCL_REMOTE_USERS |\
                                     USRBROWS_INCL_INTERACTIVE  |\
                                     USRBROWS_INCL_EVERYONE     |\
                                     USRBROWS_INCL_CREATOR      |\
                                     USRBROWS_INCL_SYSTEM)
#define USRBROWS_SHOW_ALL	    (USRBROWS_SHOW_ALIASES |\
				     USRBROWS_SHOW_GROUPS  |\
				     USRBROWS_SHOW_USERS)

// net\mmc\snmp\snmp_cn.h
#define IDH_11704_238	15609272	// Security: "A&dd..." (Button)
#define IDH_11704_240	15740344	// Security: "Add&..." (Button)
#define IDH_11704_241	15805880	// Security: "Re&move" (Button)
#define IDH_11704_233	15281592	// Security: "Send A&uthentication Trap" (Button)
#define IDH_11704_234	15347128	// Security: "&Edit..." (Button)
#define IDH_11704_235	15412664	// Security: "&Remove" (Button)
#define IDH_11704_236	15478200	// Security: "Ed&it..." (Button)

// net\mmc\tapi\lsastuff.cpp
#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }

// net\ndis\sys\ndisnt.h
#define GET_CURRENT_TICK_IN_SECONDS(_pCurrTick)                             \
    {                                                                       \
        LARGE_INTEGER       _CurrentTick;                                   \
                                                                            \
        KeQueryTickCount(&_CurrentTick);                                    \
        /* Convert to seconds */                                            \
        _CurrentTick.QuadPart = (_CurrentTick.QuadPart*ndisTimeIncrement)/(10*1000*1000);\
        *(_pCurrTick) = _CurrentTick.LowPart;                               \
    }

// net\ndis\tunmp\sys\macros.h
#define TUN_SLEEP(_Seconds)                             \
{                                                       \
    NDIS_EVENT  _SleepEvent;                            \
    NdisInitializeEvent(&_SleepEvent);                  \
    (VOID)NdisWaitEvent(&_SleepEvent, _Seconds*1000);   \
}

// net\ndis\uio\sys\macros.h
#define NUIO_SLEEP(_Seconds)                            \
{                                                       \
    NDIS_EVENT  _SleepEvent;                            \
    NdisInitializeEvent(&_SleepEvent);                  \
    (VOID)NdisWaitEvent(&_SleepEvent, _Seconds*1000);   \
}

// net\netbeui\sys\nbfprocs.h
#define StopT2(_Link) \
    { \
        (_Link)->ConsecutiveIFrames = 0; \
        (_Link)->T2 = 0; \
    }
#define TIMERS_INITIALIZED(DeviceContext)                                   \
        (DeviceContext->TimerState == TIMERS_DISABLED)                      \

// net\netbt\inc\ctemacro.h
#define CTEQuerySystemTime( _Time )    \
    KeQuerySystemTime( &(_Time) )
#define CTEGetTimeout(pTimeout,pRetTime) \
{                                       \
    LARGE_INTEGER   _Timeout;                \
    ULONG           Remainder;              \
    _Timeout.QuadPart = -(((PLARGE_INTEGER)pTimeout)->QuadPart); \
    _Timeout = RtlExtendedLargeIntegerDivide(_Timeout,MILLISEC_TO_100NS,&Remainder);\
    *pRetTime = (ULONG)_Timeout.LowPart; \
}
#define STOP_IMPERSONATE_CLIENT(_pClientSecurity)    \
    /*NtSetInformationThread(PsGetCurrentThread(),ThreadImpersonationToken,NULL,sizeof(HANDLE))*/

// net\netbt\inc\types.h
#define SET_STATE_LOWER(_L, _S)         \
    _L->State = _S;                     \
    _L->TimeUnitsInLastState = 0;
#define SET_STATERCV_LOWER(_L, _S, _P)  \
    _L->StateRcv = _S;                  \
    SetStateProc(_L, _P);               \
    _L->TimeUnitsInLastState = 0;

// net\netbt\sys\nt\ntpnp.c
#define IsBootTime()    (InterlockedExchange(&JustBooted, FALSE))

// net\nwlink\spx\spxtimer.h
#define	VALID_TMR(pTmr)		(((pTmr) != NULL) && \
							 ((pTmr)->tmr_Signature == TMR_SIGNATURE))

// net\qos\psched\netshell\diffserv\qos-protocol\sync.h
#define CREATE_LOCKED_LIST(pLL)                                             \
            InitializeListHead(&(pLL)->LL_Head);                            \
            InitializeCriticalSection(&(pLL)->LL_Lock);                     \
            (pLL)->LL_Created = 0x12345678
#define ACQUIRE_LIST_LOCK(pLL)                                              \
            EnterCriticalSection(&(pLL)->LL_Lock)

// net\qos\psched\sys\conformr.c
#define FlowIsEligible(_flow, _curtime, _r) \
    ( (_flow)->FlowEligibilityTime.QuadPart <= ((_curtime).QuadPart  + (_r)) )

// net\qos\tc\dll\refcnt.h
#define RefInitLock( _s1 )    InitializeCriticalSection( &(_s1))
#define RefGetLock( _s1 )     EnterCriticalSection( &(_s1))

// net\qos\tc\dll\tcmacro.h
#define InitLock( _s1 )    InitializeCriticalSection( &(_s1).Lock)
#define GetLock( _s1 )     EnterCriticalSection( &(_s1).Lock)
#define SafeGetLock( _s1 ) __try { EnterCriticalSection( &(_s1).Lock);

// net\qos\tools\timestmp\timestmp.c
#define IPPROTO_GGP             3               /* gateway^2 (deprecated) */

// net\rndis\rndismp\rndismp.h
#define RNDISMP_GET_TIME_STAMP(_pTs)                                        \
{                                                                           \
    LONGLONG systime_usec;                                                  \
    NdisGetCurrentSystemTime((PVOID)&systime_usec);                         \
    *_pTs = (ULONG)((*(PULONG)&systime_usec)/1000);                         \
}

// net\rras\cm\cmdial\ntlsa.cpp
#define InitializeLsaObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( LSA_OBJECT_ATTRIBUTES );       \
    (p)->RootDirectory = r;                              \
    (p)->Attributes = a;                                 \
    (p)->ObjectName = n;                                 \
    (p)->SecurityDescriptor = s;                         \
    (p)->SecurityQualityOfService = NULL;                \
    }

// net\rras\cm\cmdial\pbmap.cpp
#define CPBMAP_DECODE_IDX(cookie)	((cookie)&(CPBMAP_IDX_CNT-1))

// net\rras\dim\admindll\rtcfg.c
#define AcquireMprConfigLock() EnterCriticalSection(&CfgLock)

// net\rras\ip\bootp\sync.h
#define CREATE_LOCKED_LIST(pLL)                                             \
            InitializeListHead(&(pLL)->LL_Head);                            \
            InitializeCriticalSection(&(pLL)->LL_Lock);                     \
            (pLL)->LL_Created = 0x12345678
#define ACQUIRE_LIST_LOCK(pLL)                              \
            EnterCriticalSection(&(pLL)->LL_Lock)

// net\rras\ip\btpagnt\defs.h
#define GetAsnTimeTicks(srcBuf, defval) \
    ( ( (srcBuf)-> asnType ) ? (srcBuf)-> asnValue.ticks : (defval) )

// net\rras\ip\dvmrp\main.h
#define ACQUIRE_WORKITEM_LOCK(proc) EnterCriticalSection(&Globals1.WorkItemCS)
#define ACQUIRE_IF_LIST_LOCK(_proc) \
        ENTER_CRITICAL_SECTION(&G_pIfTable->IfList_CS, "G_IfListCS", _proc);

// net\rras\ip\dvmrp\peer.h
#define ACQUIRE_PEER_LISTS_LOCK(_proc) \
        ENTER_CRITICAL_SECTION(&G_pIfTable->PeerLists_CS, \
            "G_PeerListsCS", _proc);

// net\rras\ip\dvmrp\sync.h
#define ACQUIRE_LIST_LOCK(pLL, type, name)                              \
            ENTER_CRITICAL_SECTION(&(pLL)->Lock, type, name)

// net\rras\ip\fltrdrvr\match.c
#define RecordTimeOut(){                                                         \
        KeQuerySystemTime(&liTimeOut);                                           \
        ExInterlockedAddLargeInteger(&g_liTotalTime,                             \
                                     liTimeOut.QuadPart - liTimeIn.QuadPart),    \
                                     &g_slPerfLock);                             \
   }
#define SIZE_OF_IPSECAH sizeof(AH)

// net\rras\ip\igmp\igmptimer.h
#define SET_TIMER_ID(_pTimer, _Id1, _IfIndex, _Group, _Source) {\
    (_pTimer)->Id = _Id1; \
    (_pTimer)->Id2 = TimerId++;\
    (_pTimer)->IfIndex = _IfIndex;\
    (_pTimer)->Group = _Group; \
    (_pTimer)->Source = _Source; \
    (_pTimer)->Signature = 0xfadfad01; \
    }

// net\rras\ip\igmp\macros.h
#define ACQUIRE_IF_LIST_LOCK(_proc) \
        ENTER_CRITICAL_SECTION(&g_pIfTable->IfLists_CS, "g_IfListsCS", _proc);
#define ACQUIRE_PROXY_ALERT_LOCK(proc) \
    ENTER_CRITICAL_SECTION(&g_ProxyAlertCS, "g_ProxyAlertCS", proc)
#define ACQUIRE_GLOBAL_LOCK(proc) ENTER_CRITICAL_SECTION(&g_CS, "g_CS", proc)

// net\rras\ip\igmp\sync.h
#define ACQUIRE_LIST_LOCK(pLL, type, name)                              \
            ENTER_CRITICAL_SECTION(&(pLL)->Lock, type, name)

// net\rras\ip\igmpagnt\defs.h
#define GetAsnTimeTicks(srcBuf, defval) \
    ( ( (srcBuf)-> asnType ) ? (srcBuf)-> asnValue.ticks : (defval) )

// net\rras\ip\mcastmib\defs.h
#define GetAsnTimeTicks(srcBuf, defval) \
    ( ( (srcBuf)-> asnType ) ? (srcBuf)-> asnValue.ticks : (defval) )

// net\rras\ip\nat\ticket.h
#define DYNAMIC_TICKET_PORT(Key)        ((USHORT)((Key) & 0xFFFF))

// net\rras\ip\nath323\h245pp.h
#define SIZE_H245PP_Module_PDU_1 sizeof(MultimediaSystemControlMessage)

// net\rras\ip\nathlp\inc\nathlpp.h
#define ACQUIRE_LOCK(x)         EnterCriticalSection(&(x)->Lock)

// net\rras\ip\rip\iprip.h
#define ENTER_GLOBAL_SECTION() \
        EnterCriticalSection(&ig.IG_CS)
#define LEAVE_GLOBAL_SECTION() \
        LeaveCriticalSection(&ig.IG_CS)
#define ENTER_IF_SECTION() \
        EnterCriticalSection(&ig.IG_IfTable->IT_CS)
#define LEAVE_IF_SECTION() \
        LeaveCriticalSection(&ig.IG_IfTable->IT_CS)

// net\rras\ip\rip\sync.h
#define CREATE_LOCKED_LIST(pLL)                                             \
            InitializeListHead(&(pLL)->LL_Head);                            \
            InitializeCriticalSection(&(pLL)->LL_Lock);                     \
            (pLL)->LL_Created = 0x12345678
#define ACQUIRE_LIST_LOCK(pLL)                              \
            EnterCriticalSection(&(pLL)->LL_Lock)

// net\rras\ip\ripagnt\defs.h
#define GetAsnTimeTicks(srcBuf, defval) \
    ( ( (srcBuf)-> asnType ) ? (srcBuf)-> asnValue.ticks : (defval) )

// net\rras\ip\rtrmgr\defs.h
#define ExitRouterApi() {                                \
            EnterCriticalSection(&RouterStateLock) ;     \
            RouterState.IRS_RefCount-- ;                 \
            LeaveCriticalSection(&RouterStateLock) ;     \
        }

// net\rras\ip\sample\sync.h
#define INITIALIZE_LOCKED_LIST(pLL)                                 \
{                                                                   \
    do                                                              \
    {                                                               \
        __try {                                                     \
            InitializeCriticalSection(&((pLL)->lock));              \
        }                                                           \
        __except (EXCEPTION_EXECUTE_HANDLER) {                      \
            break;                                                  \
        }                                                           \
        InitializeListHead(&((pLL)->head));                         \
        (pLL)->created = 0x12345678;                                \
    } while (FALSE);                                                \
}
#define ACQUIRE_LIST_LOCK(pLL)                                      \
     EnterCriticalSection(&(pLL)->lock)

// net\rras\ipx\adptif\ipxdefs.h
#define IPX_ENDPOINT_SPEC_BUFFER_SIZE (\
		sizeof (FILE_FULL_EA_INFORMATION)-1	\
			+ ROUTER_INTERFACE_LENGTH+1		\
			+ sizeof (TRANSPORT_ADDRESS)-1	\
			+ sizeof (TDI_ADDRESS_IPX))

// net\rras\ipx\ipxwan\ipxwan.h
#define ACQUIRE_QUEUES_LOCK	  EnterCriticalSection(&QueuesCritSec)
#define ACQUIRE_ADAPTER_LOCK(acbp)	EnterCriticalSection(&(acbp)->AdapterLock)

// net\rras\ipx\rip\ripint.h
#define ACQUIRE_QUEUES_LOCK	  EnterCriticalSection(&QueuesCritSec)
#define ACQUIRE_RIP_CHANGED_LIST_LOCK	  EnterCriticalSection(&RipChangedListCritSec)
#define ACQUIRE_IF_LOCK(icbp)	  EnterCriticalSection(&(icbp)->InterfaceLock)
#define IfRefStartWiTimer(wip, delay)	 (wip)->icbp->RefCount++;\
					 StartWiTimer((wip), (delay));

// net\rras\ipx\sap\filters.h
#define ACQUIRE_SHARED_FILTER_TABLE_LOCK(Table) {						\
		EnterCriticalSection (&Table->FT_Lock);							\
		InterlockedIncrement (&Table->FT_ReaderCount);					\
		LeaveCriticalSection (&Table->FT_Lock);							\
		}

// net\rras\ipx\sap\syncpool.h
#define InitializeProtectedObj(ProtectedObj) {			\
					(ProtectedObj)->PO_Sync = NULL; 	\
					(ProtectedObj)->PO_UseCount = -1;	\
					(ProtectedObj)->PO_AccessCount = 0;	\
					(ProtectedObj)->PO_WaitCount = 0;	\
					(ProtectedObj)->PO_TotalWait = 0;	\
					}
#define InitializeProtectedObj(ProtectedObj) {			\
					(ProtectedObj)->PO_Sync = NULL; 	\
					(ProtectedObj)->PO_UseCount = -1;	\
					}

// net\rras\mgm\defs.h
#define MgmElapsedTime( p, q, u )                                           \
{                                                                           \
    LARGE_INTEGER __li1, __li2;                                             \
    ULONG         __rem;                                                    \
    MgmQuerySystemTime( &__li1);                                            \
    __li2 = RtlLargeIntegerSubtract( __li1, *(p) );                         \
    __li1 = RtlExtendedLargeIntegerDivide( __li2, u, &__rem );              \
    *(q) = __li1.LowPart;                                                   \
}

// net\rras\mgm\ipmgm.h
#define ENTER_GLOBAL_SECTION() \
        EnterCriticalSection(&ig.csGlobal)
#define LEAVE_GLOBAL_SECTION() \
        LeaveCriticalSection(&ig.csGlobal)
#define ENTER_GLOBAL_LOCK_LIST_SECTION() \
        EnterCriticalSection(&ig.llStackOfLocks.csListLock)
#define LEAVE_GLOBAL_LOCK_LIST_SECTION() \
        LeaveCriticalSection(&ig.llStackOfLocks.csListLock)

// net\rras\ndis\ndiswan\wandefs.h
#define NdisWanGetSystemTime(_pTime)                    \
{                                                       \
    LARGE_INTEGER   _tc;                                \
    ULONG           _ti;                                \
    KeQueryTickCount(&_tc);                             \
    _ti = KeQueryTimeIncrement();                       \
    (_pTime)->QuadPart = _tc.QuadPart * _ti;            \
}
#define NdisWanCalcTimeDiff(_pDest, _pEnd, _pBegin) \
        (_pDest)->QuadPart = (_pEnd)->QuadPart - (_pBegin)->QuadPart
#define NdisWanInitWanTime(_pTime, _Val) \
        (_pTime)->QuadPart = _Val
#define NdisWanMultiplyWanTime(_pDest, _pMulti1, _pMulti2)  \
        (_pDest)->QuadPart = (_pMulti1)->QuadPart * (_pMulti2)->QuadPart
#define NdisWanDivideWanTime(_pDest, _pDivi1, _pDivi2)  \
        (_pDest)->QuadPart = (_pDivi1)->QuadPart / (_pDivi2)->QuadPart
#define NdisWanIsTimeDiffLess(_pTime1, _pTime2) \
        ((_pTime1)->QuadPart < (_pTime2)->QuadPart)
#define NdisWanIsTimeDiffGreater(_pTime1, _pTime2) \
        ((_pTime1)->QuadPart > (_pTime2)->QuadPart)
#define NdisWanIsTimeEqual(_pTime1, _pTime2) \
        ((_pTime1)->QuadPart == (_pTime2)->QuadPart)

// net\rras\ras\inc\rasfile.h
#define RFL_ANYHEADER           (RFL_SECTION | RFL_GROUP)

// net\rras\ras\ui\inc\pbk.h
#define AR_F_TypicalUnsecure   (AR_F_AuthPAP | AR_F_AuthSPAP | AR_F_AuthMD5CHAP | AR_F_AuthMSCHAP | AR_F_AuthMSCHAP2)
#define AR_F_TypicalSecure     (AR_F_AuthMD5CHAP | AR_F_AuthMSCHAP | AR_F_AuthMSCHAP2)

// net\rras\ras\ui\rasscrpt\proj.h
#define ENTERCRITICALSECTION(x)         EnterCriticalSection(&x)
#define LEAVECRITICALSECTION(x)         LeaveCriticalSection(&x)

// net\rras\ras\ui\rassrvui\utils.h
#define GBL_LOCK EnterCriticalSection(&(Globals.csLock))
#define GBL_UNLOCK LeaveCriticalSection(&(Globals.csLock))

// net\rras\rtm\rtmdlg.h
#define IsLater(Time1,Time2)	\
			(((Time1-Time2)&MaxTicks)<MaxTicks/2)
#define TimeDiff(Time1,Time2)	\
			((Time1-Time2)&MaxTicks)
#define IsPositiveTimeDiff(TimeDiff) \
			(TimeDiff<MaxTicks/2)

// net\rras\rtm\rtmp.h
#define IsLater(Time1,Time2)	\
			(Time1-Time2<MAXTICKS/2)
#define IsPositiveTimeDiff(TimeDiff) \
			(TimeDiff<MAXTICKS/2)

// net\rras\rtmv2\apitest.h
#define    ADDPROF      timer = (double)(PCStop.QuadPart - PCStart.QuadPart) \
                                     * 1000 * 1000 * 1000 / PCFreq.QuadPart; \
                        duration += timer;                                   \
                        // Print("Add : %.3f ns\n\n", timer);
#define    SUBPROF      timer = (double)(PCStop.QuadPart - PCStart.QuadPart) \
                                     * 1000 * 1000 * 1000 / PCFreq.QuadPart; \
                        duration -= timer;                                   \
                        // Print("Sub : %.3f ns\n\n", timer);
#define    PRINTPROF    // Print("Total Time Taken To Finish : %.3f ns\n",   \
                        //          duration);

// net\rras\rtmv2\lkuptst.h
#define    ADDPROF      timer = (double)(PCStop.QuadPart - PCStart.QuadPart) \
                                     * 1000 * 1000 * 1000 / PCFreq.QuadPart; \
                        duration += timer;                                   \
                        // Print("Add : %.3f ns\n\n", timer);
#define    SUBPROF      timer = (double)(PCStop.QuadPart - PCStart.QuadPart) \
                                     * 1000 * 1000 * 1000 / PCFreq.QuadPart; \
                        duration -= timer;                                   \
                        // Print("Sub : %.3f ns\n\n", timer);
#define    PRINTPROF    // Print("Total Time Taken To Finish : %.3f ns\n",   \
                        //          duration);

// net\rras\rtmv2\rtmregn.h
#define ACQUIRE_NOTIF_TIMER_LOCK(AF)                         \
    ACQUIRE_LOCK(&AF->NotifsTimerLock)

// net\sfm\afp\server\afpinfo.h
#define AfpInitAfpInfo(_pAfpInfo, _AfpId, _IsDir, _BackupTime)	\
{																\
	RtlZeroMemory(&(_pAfpInfo)->afpi_FinderInfo,				\
				  sizeof(FINDERINFO)+sizeof(PRODOSINFO)+sizeof(USHORT));	\
	(_pAfpInfo)->afpi_Signature = AFP_SERVER_SIGNATURE;			\
	(_pAfpInfo)->afpi_Version = AFP_SERVER_VERSION;				\
	(_pAfpInfo)->afpi_BackupTime = (_BackupTime);				\
	(_pAfpInfo)->afpi_Id = (_AfpId);							\
	if (_IsDir)													\
	{															\
		(_pAfpInfo)->afpi_AccessOwner =							\
		(_pAfpInfo)->afpi_AccessGroup =							\
		(_pAfpInfo)->afpi_AccessWorld = DIR_ACCESS_READ | DIR_ACCESS_SEARCH;	\
		(_pAfpInfo)->afpi_ProDosInfo.pd_FileType[0] = PRODOS_TYPE_DIR;\
		(_pAfpInfo)->afpi_ProDosInfo.pd_AuxType[1] = PRODOS_AUX_DIR;\
	}															\
	else														\
	{															\
		(_pAfpInfo)->afpi_ProDosInfo.pd_FileType[0] = PRODOS_TYPE_FILE; \
	}															\
}

// net\sfm\afp\server\idindex.h
#define	afpConvertBasicToBothDirInfo(_pFBasInfo, _pFBDInfo)			\
{																	\
	(_pFBDInfo)->CreationTime = (_pFBasInfo)->CreationTime;			\
	(_pFBDInfo)->LastWriteTime = (_pFBasInfo)->LastWriteTime;		\
	(_pFBDInfo)->ChangeTime = (_pFBasInfo)->ChangeTime;				\
	(_pFBDInfo)->FileAttributes = (_pFBasInfo)->FileAttributes;		\
	(_pFBDInfo)->EndOfFile.QuadPart = 0;																\
}
#define	afpInitializeIdDb(_pVolDesc)									\
	{																	\
		AFPTIME		CurrentTime;										\
		PDFENTRY	pDfEntry;											\
																		\
		/* RO volumes don't use the network trash folder at all */		\
		(_pVolDesc)->vds_LastId	= AFP_ID_NETWORK_TRASH;					\
																		\
		AfpGetCurrentTimeInMacFormat(&CurrentTime);						\
		(_pVolDesc)->vds_CreateTime = CurrentTime;						\
		(_pVolDesc)->vds_ModifiedTime = CurrentTime;					\
		(_pVolDesc)->vds_BackupTime = BEGINNING_OF_TIME;				\
																		\
		/* Create a DFE for the root directory */						\
		afpCreateParentOfRoot(_pVolDesc, &pDfEntry);					\
	}
#define	afpUpdateDfeAccessTime(_pVolDesc, _pDfEntry)					\
	{																	\
		if (IS_VOLUME_AGING_DFES(_pVolDesc))							\
		{																\
			if (DFE_IS_DIRECTORY(_pDfEntry))							\
				AfpGetCurrentTimeInMacFormat(&(_pDfEntry)->dfe_pDirEntry->de_LastAccessTime);\
			else AfpGetCurrentTimeInMacFormat(&(_pDfEntry)->dfe_Parent->dfe_pDirEntry->de_LastAccessTime);\
		}																\
	}

// net\sfm\afp\server\volume.h
#define	AfpVolumeInsertChangeNotifyList(pVolNotify, pVolDesc)			\
	{																	\
		PLIST_ENTRY	pListHead;											\
																		\
		pListHead = &AfpVolumeNotifyList[(pVolDesc)->vds_VolId % NUM_NOTIFY_QUEUES]; \
		if (pVolNotify->vn_TimeStamp != AFP_QUEUE_NOTIFY_IMMEDIATELY)	\
		{																\
			ExInterlockedInsertTailList(pListHead,						\
										&(pVolNotify)->vn_List,			\
										&(AfpVolumeListLock.SpinLock));			\
		}																\
		else															\
		{																\
			ExInterlockedInsertHeadList(pListHead,						\
										&(pVolNotify)->vn_List,			\
										&(AfpVolumeListLock.SpinLock));			\
		}																\
		INTERLOCKED_ADD_ULONG(&AfpNotifyListCount[(pVolDesc)->vds_VolId % NUM_NOTIFY_QUEUES], \
							  1,										\
										&AfpVolumeListLock);			\
	}
#define	AfpIdDbHdrToVolDesc(_pIdDbHdr, _pVolDesc)						\
	{																	\
		(_pVolDesc)->vds_LastId = (_pIdDbHdr)->idh_LastId;				\
		(_pVolDesc)->vds_CreateTime   = (_pIdDbHdr)->idh_CreateTime;	\
		(_pVolDesc)->vds_ModifiedTime = (_pIdDbHdr)->idh_ModifiedTime;	\
		(_pVolDesc)->vds_BackupTime   = (_pIdDbHdr)->idh_BackupTime;	\
	}
#define	AfpVolDescToIdDbHdr(_pVolDesc, _pIdDbHdr)						\
	{																	\
		(_pIdDbHdr)->idh_Signature = AFP_SERVER_SIGNATURE;				\
		(_pIdDbHdr)->idh_Version = AFP_IDDBHDR_VERSION;					\
		(_pIdDbHdr)->idh_LastId = (_pVolDesc)->vds_LastId;				\
		(_pIdDbHdr)->idh_CreateTime   = (_pVolDesc)->vds_CreateTime;	\
		(_pIdDbHdr)->idh_ModifiedTime = (_pVolDesc)->vds_ModifiedTime;	\
		(_pIdDbHdr)->idh_BackupTime   = (_pVolDesc)->vds_BackupTime;	\
	}

// net\sfm\atalk\sys\atktdi.h
#define	AtalkLockAdspIfNecessary()		AtalkLockUnlock(TRUE,							\
														&AtalkPgLkSection[ADSP_SECTION])
#define	AtalkUnlockAdspIfNecessary()	AtalkLockUnlock(FALSE,							\
														&AtalkPgLkSection[ADSP_SECTION])
#define	AtalkLockPapIfNecessary()		AtalkLockUnlock(TRUE,							\
														&AtalkPgLkSection[PAP_SECTION])
#define	AtalkUnlockPapIfNecessary()		AtalkLockUnlock(FALSE,							\
														&AtalkPgLkSection[PAP_SECTION])
#define	AtalkLockNbpIfNecessary()		AtalkLockUnlock(TRUE,							\
														&AtalkPgLkSection[NBP_SECTION])
#define	AtalkUnlockNbpIfNecessary()		AtalkLockUnlock(FALSE,							\
														&AtalkPgLkSection[NBP_SECTION])
#define	AtalkLockZipIfNecessary()		AtalkLockUnlock(TRUE,							\
														&AtalkPgLkSection[ZIP_SECTION])
#define	AtalkUnlockZipIfNecessary()		AtalkLockUnlock(FALSE,							\
														&AtalkPgLkSection[ZIP_SECTION])
#define	AtalkLockRouterIfNecessary()	AtalkLockUnlock(TRUE,							\
														&AtalkPgLkSection[ROUTER_SECTION])
#define	AtalkUnlockRouterIfNecessary()	AtalkLockUnlock(FALSE,							\
														&AtalkPgLkSection[ROUTER_SECTION])
#define	AtalkLockTdiIfNecessary()		AtalkLockUnlock(TRUE,							\
														&AtalkPgLkSection[TDI_SECTION])
#define	AtalkUnlockTdiIfNecessary()		AtalkLockUnlock(FALSE,			        		\
														&AtalkPgLkSection[TDI_SECTION])
#define	AtalkLockAspIfNecessary()		AtalkLockUnlock(TRUE,							\
														&AtalkPgLkSection[ASP_SECTION])
#define	AtalkUnlockAspIfNecessary()		AtalkLockUnlock(FALSE,			        		\
														&AtalkPgLkSection[ASP_SECTION])
#define	AtalkLockAspCIfNecessary()		AtalkLockUnlock(TRUE,							\
														&AtalkPgLkSection[ASPC_SECTION])
#define	AtalkUnlockAspCIfNecessary()	AtalkLockUnlock(FALSE,			        		\
														&AtalkPgLkSection[ASPC_SECTION])
#define	AtalkLockAtpIfNecessary()		AtalkLockUnlock(TRUE,							\
														&AtalkPgLkSection[ATP_SECTION])
#define	AtalkUnlockAtpIfNecessary()		AtalkLockUnlock(FALSE,			        		\
														&AtalkPgLkSection[ATP_SECTION])
#define	AtalkLockInitIfNecessary()		AtalkLockUnlock(TRUE,							\
														&AtalkPgLkSection[INIT_SECTION])
#define	AtalkUnlockInitIfNecessary()		AtalkLockUnlock(FALSE,		            		\
														&AtalkPgLkSection[INIT_SECTION])
#define	AtalkLockArapIfNecessary()		AtalkLockUnlock(TRUE,		            		\
														&AtalkPgLkSection[ARAP_SECTION])
#define	AtalkUnlockArapIfNecessary()		AtalkLockUnlock(FALSE,		            		\
														&AtalkPgLkSection[ARAP_SECTION])
#define	AtalkLockPPPIfNecessary()		AtalkLockUnlock(TRUE,		            		\
														&AtalkPgLkSection[PPP_SECTION])
#define	AtalkUnlockPPPIfNecessary()		AtalkLockUnlock(FALSE,		            		\
														&AtalkPgLkSection[PPP_SECTION])

// net\sfm\atalk\sys\atktimer.h
#define	VALID_TMR(pTmr)		(((pTmr) != NULL) && \
							 ((pTmr)->tmr_Signature == TMR_SIGNATURE))
#define	AtalkTimerInitialize(pList, TimerRoutine, DeltaTime)	\
	{															\
		(pList)->tmr_Signature = TMR_SIGNATURE;					\
		(pList)->tmr_Routine = TimerRoutine;					\
		(pList)->tmr_AbsTime = DeltaTime;						\
		(pList)->tmr_Bools = 0;									\
	}
#define	AtalkTimerInitialize(pList, TimerRoutine, DeltaTime)	\
	{															\
		(pList)->tmr_Routine = TimerRoutine;					\
		(pList)->tmr_AbsTime = DeltaTime;						\
		(pList)->tmr_Bools = 0;									\
	}

// net\sockets\winsock2\ws2_32\src\async.cpp
#define SockAcquireGlobalLock() EnterCriticalSection( &SockAsyncLock )

// net\sockets\winsock2\ws2help\ws2help\nt\newctx.c
#define AcquireTableReaderLock(tbl,idx)                             \
            idx = (EnterCriticalSection(&tbl->WriterLock),0)
#define AcquireTableWriterLock(tbl) EnterCriticalSection(&(tbl)->WriterLock)

// net\sockets\winsock2\ws2help\ws2help\nt\whcperf.c
#define USAGE(x)    \
    "Usage:\n"\
    "   %s <num_threads> <num_handles> <write_access_%%> <time_to_run> <spins\n"\
    "   where\n"\
    "       <num_threads>   - number of threads (1-64);\n"\
    "       <num_handles>   - number of handles;\n"\
    "       <write_access_%%>  - percentage of write accesses (0-100);\n"\
    "       <time_to_run>   - time to run in sec;\n"\
    "       <spins>          - number of spins between operations.\n"\
    ,x

// net\sockets\winsock2\wsp\afdsys\afdp.h
#define AFD_ENDPOINT_POOL_TAG           ( (ULONG)'EdfA' | PROTECTED_POOL )

// net\sockets\winsock2\wsp\afdsys\afdprocs.h
#define REFERENCE_ENDPOINT(_e) (VOID)InterlockedIncrement( (PLONG)&(_e)->ReferenceCount )
#define REFERENCE_ENDPOINT2(_e,_s,_p) InterlockedIncrement( (PLONG)&(_e)->ReferenceCount )
#define IS_MESSAGE_ENDPOINT(endp) \
            ((endp)->afdMessageMode)
#define IS_RAW_ENDPOINT(endp) \
            ((endp)->afdRaw)
#define IS_CROOT_ENDPOINT(endp) \
            ((endp)->afdMultipoint && (endp)->afdC_Root)
#define IS_DELAYED_ACCEPTANCE_ENDPOINT(endp) \
            ((endp)->DelayedAcceptance)
#define ARE_DATAGRAMS_ON_ENDPOINT(endp)                          \
            ( (endp)->DgBufferredReceiveCount != 0 )
#define AfdRecordEndpointsReused()               InterlockedIncrement( &AfdConnectionStats.EndpointsReused )

// net\sockets\winsock2\wsp\afdsys\afdstr.h
#define AfdEnqueueRequest(Endpoint,Request)                     \
    ExInterlockedInsertTailList(&(Endpoint)->RequestList,       \
                                &(Request)->EndpointListLink,   \
                                &(Endpoint)->SpinLock)
#define AfdIsRequestInQueue(Request)                           \
            ((Request)->EndpointListLink.Flink!=NULL)
#define AfdMarkRequestCompleted(Request)                       \
            (Request)->EndpointListLink.Blink = NULL
#define AfdIsRequestCompleted(Request)                         \
            ((Request)->EndpointListLink.Blink==NULL)

// net\tapi\rtc\phoenix\src\sip\asock.cpp
#define IsSecHandleValid(Handle) \
    !(((Handle) -> dwLower == -1 && (Handle) -> dwUpper == -1))

// net\tapi\rtc\phoenix\src\sip\register.cpp
#define IsSecHandleValid(Handle) \
    !(((Handle) -> dwLower == -1 && (Handle) -> dwUpper == -1))

// net\tapi\skywalker\apps\avdialer\confprop\objsec.cpp
#define DSOP_FILTER_COMMON ( DSOP_FILTER_USERS |					\
							 DSOP_FILTER_UNIVERSAL_GROUPS_SE |		\
							 DSOP_FILTER_GLOBAL_GROUPS_SE )
#define DSOP_FILTER_DL_COMMON1      ( DSOP_DOWNLEVEL_FILTER_USERS           \
                                    | DSOP_DOWNLEVEL_FILTER_GLOBAL_GROUPS   \
                                    | DSOP_DOWNLEVEL_FILTER_COMPUTERS       \
                                    )
#define DSOP_FILTER_DL_COMMON2      ( DSOP_FILTER_DL_COMMON1                    \
                                    | DSOP_DOWNLEVEL_FILTER_ALL_WELLKNOWN_SIDS  \
                                    )
#define DSOP_FILTER_DL_COMMON3      ( DSOP_FILTER_DL_COMMON2                \
                                    | DSOP_DOWNLEVEL_FILTER_LOCAL_GROUPS    \
                                    )

// net\tapi\skywalker\apps\avdialer\confprop\objsec.h
#define ACCESS_MODIFY   (ACCESS_WRITE | WRITE_DAC)

// net\tapi\skywalker\cc\h245\inc\h245fsm.h
#define FsmStopTimer(pObject) \
    {H245StopTimer((pObject)->pInstance,(pObject)->dwTimerId); (pObject)->dwTimerId = 0;}

// net\tapi\skywalker\filters\rtp\inc\rtpchan.h
#define IsRtpChannelInitialized(pCh) \
(IsRtpCritSectInitialized(&(pCh)->ChannelCritSect))

// net\tapi\skywalker\filters\rtp\inc\rtpcrit.h
#define IsRtpCritSectInitialized(pRtpCritSect) \
        ((pRtpCritSect)->dwObjectID == OBJECTID_RTPCRITSECT)

// net\tapi\skywalker\filters\video\tapivcap\dbgxtra.h
    #define BEGIN_TICK QueryPerformanceCounter(&liTicks)
    #define END_TICK   QueryPerformanceCounter(&liTicks1)

// net\tapi\skywalker\h323\inc\h245asn.h
#define SIZE_H245ASN_Module_PDU_1 sizeof(MultimediaSystemControlMessage)

// net\tapi\skywalker\h323tsp\line.h
#define H323LockLine(_pLine_) \
    {EnterCriticalSection(&(_pLine_)->Lock);}
#define H323UnlockLine(_pLine_) \
    {LeaveCriticalSection(&(_pLine_)->Lock);}

// net\tapi\skywalker\h323tsp\provider.h
#define H323LockProvider() \
    {EnterCriticalSection(&g_GlobalLock);}
#define H323UnlockProvider() \
    {LeaveCriticalSection(&g_GlobalLock);}

// net\tapi\skywalker\inc\h245.h
#define SIZE_H245_Module_PDU_0 sizeof(MultimediaSystemControlMessage)

// net\tapi\skywalker\tapi3\call.h
#define ISHOULDUSECALLPARAMS() ( ( NULL != m_pCallParams ) && ( CS_IDLE == m_CallState ) )

// net\tapi\sp\kmddsp\kmddsp.c
#define REF_ASYNC_REQUEST_WRAPPER(_pAsyncReqWrapper)    \
{                                                       \
    EnterCriticalSection(&_pAsyncReqWrapper->CritSec);  \
    _pAsyncReqWrapper->RefCount++;                      \
    LeaveCriticalSection(&_pAsyncReqWrapper->CritSec);  \
}

// net\tapi\sp\ndptsp\tsp\ndptsp.c
#define REF_ASYNC_REQUEST_WRAPPER(_pAsyncReqWrapper)    \
{                                                       \
    EnterCriticalSection(&_pAsyncReqWrapper->CritSec);  \
    _pAsyncReqWrapper->RefCount++;                      \
    LeaveCriticalSection(&_pAsyncReqWrapper->CritSec);  \
}

// net\tapi\thunk\windows.h
#define MAKEPOINT(l)     (*((POINT FAR*)&(l)))
#define FLASHW_VALID        (FLASHW_ALL | FLASHW_TIMERNOFG)  // ;internal 4.1
#define LB_ITEMFROMPOINT        (WM_USER+42)    // ;Internal 4.0

// net\tcpip\apis\iphlpapi\icmptest\icmptest.c
#define LOCK_REPLIES_LIST()    EnterCriticalSection(&IcmpRepliesCritSect)
#define LOCK_REQUESTS_LIST()   EnterCriticalSection(&IcmpRequestsCritSect)
#define LOCK_OUTPUT()          EnterCriticalSection(&OutputCritSect)
#define UNLOCK_REPLIES_LIST()  LeaveCriticalSection(&IcmpRepliesCritSect)
#define UNLOCK_REQUESTS_LIST() LeaveCriticalSection(&IcmpRequestsCritSect)
#define UNLOCK_OUTPUT()        LeaveCriticalSection(&OutputCritSect)

// net\tcpip\driver\inc\tcp.h
#define TCB_TIMER_FIRED_R(tcb, type, time)   \
        ((tcb->tcb_timer[type]) && (tcb->tcb_timer[type] == time))

// net\tcpip\driver\ipsec\kdext\kdmacros.h
#define PrintJoin() { ppchCurrentEol = &pchBlank; }
#define EOL (( ppchTempEol = ppchCurrentEol ), ( ppchCurrentEol = &pchEol ), ( *ppchTempEol ))
#define PrintFieldName(_fieldName) \
        if ( strlen(_fieldName) > 35 ) {                                                \
            dprintf("%s%-.25s..%s = ",IndentBuf,_fieldName, &(_fieldName[strlen(_fieldName)-8]));   \
        }else {                                                                         \
            dprintf("%s%-35.35s = ",IndentBuf,_fieldName );                                        \
        }
#define PrintFieldNameAt(_fieldName) \
        if ( strlen(_fieldName) > 35 ) {                                                \
            dprintf("%s%-.25s..%s @ ",IndentBuf,_fieldName, &(_fieldName[strlen(_fieldName)-8]));   \
        }else {                                                                         \
            dprintf("%s%-35.35s @ ",IndentBuf,_fieldName );                                        \
        }
#define PrintListTcpFieldName(_fieldName) \
        if ( strlen(_fieldName) > 40 ) {                                                \
            dprintf("%s%-.30s...%s q_next = ",IndentBuf,_fieldName, &(_fieldName[strlen(_fieldName)-7]));   \
        }else {                                                                        \
            dprintf("%s%-40.40s q_next = ",IndentBuf,_fieldName );                                        \
        }
#define PrintListFieldName(_fieldName) \
        if ( strlen(_fieldName) > 40 ) {                                                \
            dprintf("%s%-.30s...%s FLink = ",IndentBuf,_fieldName, &(_fieldName[strlen(_fieldName)-7]));   \
        }else {                                                                        \
            dprintf("%s%-40.40s FLink = ",IndentBuf,_fieldName );                                        \
        }
#define PrintRawBool( _bValue ) \
            dprintf("%-10s%s", (_obj._bValue) ? "True" : "False", EOL)
#define PrintBool(_field) \
            PrintFieldName(#_field)  \
            dprintf("%-10s%s", (_obj._field) ? "True" : "False", EOL)
#define PrintNChar( _field, count )        \
            PrintFieldName(#_field)  \
            dprint_nchar( ( PCHAR )_obj._field, count ); \
            dprintf("%s", EOL)
#define PrintLL(_field)                                     \
            PrintEnd;                                       \
            PrintListFieldName(#_field );                  \
            dprintf("%-10lx",  _obj._field.Flink );         \
            dprintf("Blink = %-10lx",  _obj._field.Blink );         \
            dprintf("%s\n", ( _obj._field.Flink == _obj._field.Blink ) ? " (Empty)" : "" );
#define PrintLLTcp(_field)                                     \
            PrintEnd;                                       \
            PrintListTcpFieldName(#_field );                  \
            dprintf("%-10lx",  _obj._field.q_next );         \
            dprintf("q_prev = %-10lx",  _obj._field.q_prev );         \
            dprintf("%s\n", ( _obj._field.q_next == _obj._field.q_prev ) ? " (Empty)" : "" );
#define PrintGUID( _field )                                 \
            PrintFieldName(#_field);                        \
            dprintf("{%lx.%lx.%lx.%lx}",                    \
                    *(PULONG)(&_obj._field),                \
                    *((PUCHAR)(&_obj._field)+4),            \
                    *((PUCHAR)(&_obj._field)+8),            \
                    *((PUCHAR)(&_obj._field)+12));          \
            dprintf( "%s", EOL );
#define PrintLock(_field) \
            PrintFieldName(#_field)  \
            dprintf("( 0x%08lx ) %-10s%s", (_obj._field), (_obj._field) ? "Locked" : "UnLocked", EOL)

// net\tcpip\driver\ipsec\sys\ah.h
#define AH_SIZE (sizeof(AH) + MD5DIGESTLEN * sizeof(UCHAR))

// net\tcpip\driver\ipsec\sys\filter.h
#define REQUEST_NDIS_BUFFER(_Request) \
    ((PNDIS_BUFFER)((_Request)->MdlAddress))

// net\tcpip\driver\ipsec\sys\macros.h
#define IS_CLASSD(i)            (((long)(i) & 0xf0000000) == 0xe0000000)
#define IPSEC_SA_EXPIRED(__pSA, __fexpired) {           \
    LARGE_INTEGER   __curtime;                          \
    KeQuerySystemTime(&__curtime);                      \
    (__fexpired) = FALSE;                               \
    __curtime.QuadPart -= pSA->sa_LastUsedTime.QuadPart;\
    if (__pSA->sa_IdleTime.QuadPart < __curtime.QuadPart) { \
        __fexpired = TRUE;                              \
    }                                                   \
}
#define IPSEC_GET_TOTAL_LEN_RCV_BUF(_pbuf, _plen)       {   \
    IPRcvBuf *_ptemp = (_pbuf);                             \
    *(_plen) = 0;                                           \
    while (_ptemp) {                                        \
        *(_plen) += _ptemp->ipr_size;                       \
        _ptemp = IPSEC_BUFFER_LINKAGE(_ptemp);              \
    }                                                       \
}
#define IPSecQueryRcvBuf(_Buffer, _VirtualAddress, _Length) \
{                                                           \
    IPRcvBuf    *__buf = (IPRcvBuf *) (_Buffer);            \
    if (ARGUMENT_PRESENT(_VirtualAddress)) {                \
        *(PVOID *)(_VirtualAddress) = (__buf)->ipr_buffer;  \
    }                                                       \
    *(_Length) = (__buf)->ipr_size;                         \
}
#define IPSEC_ADJUST_BUFFER_LEN(_pBuf, _len)    \
    ((IPRcvBuf *)(_pBuf))->ipr_size = (_len)
#define IPSEC_BUFFER_LINKAGE(_pBuf) \
    ((IPRcvBuf *)(_pBuf))->ipr_next
#define IPSEC_BUFFER_LEN(_pBuf) \
    ((IPRcvBuf *)(_pBuf))->ipr_size
#define IPSEC_BUFFER_OWNER(_pBuf)   \
    (((IPRcvBuf *)(_pBuf))->ipr_owner)
#define IPSEC_ADD_VALUE(_val, _inc) InterlockedExchangeAdd((PULONG)&(_val), _inc)
#define IPSEC_INCREMENT(_val)  InterlockedIncrement(&(_val))
#define IPSEC_DECREMENT(_val)  InterlockedDecrement(&(_val))
#define IPSEC_GET_VALUE(_val)  InterlockedExchangeAdd((PULONG)&(_val), 0)
#define IPSEC_SET_VALUE(_target, _val)  \
    InterlockedExchange((PULONG)&(_target), _val)
#define IPSEC_DRIVER_IS_INACTIVE()  (g_ipsec.DriverUnloading || !g_ipsec.InitTcpip)
#define IS_MULTICAST_FILTER(f)  (IS_CLASSD(NET_LONG((f)->SRC_ADDR)) || \
                                 IS_CLASSD(NET_LONG((f)->DEST_ADDR)))
#define CacheMatch(uliAddr, uliPort, pInCache)              \
        ((uliAddr).QuadPart == pInCache->uliSrcDstAddr.QuadPart) &&    \
        ((uliPort).QuadPart == pInCache->uliProtoSrcDstPort.QuadPart)
#define IPSecGetAcquireContext()        IPSecAllocateMemory(sizeof(IPSEC_ACQUIRE_CONTEXT), IPSEC_TAG_ACQUIRE_CTX)
#define IPSecGetNotifyExpire()        IPSecAllocateMemory(sizeof(IPSEC_NOTIFY_EXPIRE), IPSEC_TAG_ACQUIRE_CTX)
#define IS_AH_SA(_psa)  ((_psa)->sa_Operation[0] == Auth ||     \
                         (_psa)->sa_Operation[1] == Auth ||     \
                         (_psa)->sa_Operation[2] == Auth)
#define IS_ESP_SA(_psa) ((_psa)->sa_Operation[0] == Encrypt ||  \
                         (_psa)->sa_Operation[1] == Encrypt ||  \
                         (_psa)->sa_Operation[2] == Encrypt)
#define IPSEC_DELAY_EXECUTION()                                     \
{                                                                   \
    IPSecDelayInterval.QuadPart = IPSEC_DELAY_INTERVAL;             \
    KeDelayExecutionThread(UserMode, FALSE, &IPSecDelayInterval);   \
}
#define IS_CLASS_D_ADDR(x)  (((x) & 0x000000f0) == 0x000000e0)
#define xsum(Buffer, Length)    ((USHORT)TCPIP_TCP_XSUM(0, (PUCHAR)(Buffer), (Length)))
#define IPSEC_COMPARE_SD_PORT(_pport, _port)    \
    (   ((_pport)[0] == (_port)) ||     \
        ((_pport)[1] == (_port)))
#define IPSEC_KERBEROS_TRAFFIC()                            \
    ((pIPHeader->iph_protocol == PROTOCOL_UDP ||            \
      pIPHeader->iph_protocol == PROTOCOL_TCP) &&           \
     IPSEC_COMPARE_SD_PORT(pwPort, IPSEC_KERBEROS_PORT))
#define IPSEC_ISAKMP_TRAFFIC()                              \
    (pIPHeader->iph_protocol == PROTOCOL_UDP &&             \
     IPSEC_COMPARE_D_PORT(pwPort, IPSEC_ISAKMP_PORT))       \
#define IPSEC_RSVP_TRAFFIC()                                \
    (pIPHeader->iph_protocol == PROTOCOL_RSVP)
#define IPSEC_NO_DEFAULT_EXEMPT()   (g_ipsec.NoDefaultExempt & IPSEC_NO_UNICAST_EXEMPT)
#define IPSEC_HANDLE_MANDBCAST()   (g_ipsec.NoDefaultExempt & IPSEC_NO_MANDBCAST_EXEMPT)
#define IPSEC_MANDBCAST_PROCESS() (IPSEC_GET_VALUE(g_ipsec.NumMulticastFilters) || \
                                   IPSEC_HANDLE_MANDBCAST())
#define IPSEC_BYPASS_TRAFFIC()                              \
    (IPSEC_ISAKMP_TRAFFIC() ||                              \
     (!IPSEC_NO_DEFAULT_EXEMPT() &&                         \
      (IPSEC_KERBEROS_TRAFFIC() ||                          \
       IPSEC_RSVP_TRAFFIC())))

// net\tcpip\driver\ipsec\sys\timer.h
#define IPSEC_STOP_SYSTEM_TIMER(pTimer)						\
			{												\
				BOOLEAN		WasCancelled;					\
				NdisCancelTimer(pTimer, &WasCancelled);		\
			}

// net\tcpip\driver\ipv4\igmp.c
#define IS_GROUP_DELETABLE(Grp) \
    (!IS_GROUP_ALLOWED(Grp) && ((Grp)->iga_xmitleft == 0) \
     && ((Grp)->iga_resptimer == 0))

// net\tcpip\driver\ipv4\ipmcast.h
#define UpdateActivityTime(pSource)     \
    KeQueryTickCount((PLARGE_INTEGER)&(((pSource)->llLastActivity)))

// net\tcpip\driver\kdext2\inc\tcpdump.h
#define Print_CTETimer(_p, _f)          \
    PrintFieldName(#_f);                \
    DumpCTETimer(&_p->_f)

// net\tcpip\driver\tcp\addr.h
#define LOCKED_DELAY_DEREF_AO(a) \
    (a)->ao_usecnt--; \
    if (!(a)->ao_usecnt && !AO_BUSY((a)) && AO_PENDING((a))) { \
        SET_AO_BUSY((a)); \
        CTEScheduleEvent(&(a)->ao_event, (a)); \
    }

// net\tcpip\services\rip\rip.h
#define RIP_CREATE_ROUTETABLE_LOCK() InitializeCriticalSection(&g_csRoutes)
#define RIP_LOCK_ROUTETABLE()       EnterCriticalSection(&g_csRoutes)
#define RIP_UNLOCK_ROUTETABLE()     LeaveCriticalSection(&g_csRoutes)
#define RIP_CREATE_PARAMS_LOCK()    InitializeCriticalSection(&g_csParameters)
#define RIP_LOCK_PARAMS()           EnterCriticalSection(&g_csParameters)
#define RIP_UNLOCK_PARAMS()         LeaveCriticalSection(&g_csParameters)
#define RIP_CREATE_ADDRTABLE_LOCK() InitializeCriticalSection(&g_csAddrtables)
#define RIP_LOCK_ADDRTABLE()       EnterCriticalSection(&g_csAddrtables)
#define RIP_UNLOCK_ADDRTABLE()     LeaveCriticalSection(&g_csAddrtables)
#define RIP_CREATE_ANNOUNCE_FILTERS_LOCK()  \
        InitializeCriticalSection( &g_csAnnFilters )
#define RIP_LOCK_ANNOUNCE_FILTERS()         \
        EnterCriticalSection( &g_csAnnFilters )
#define RIP_UNLOCK_ANNOUNCE_FILTERS()       \
        LeaveCriticalSection( &g_csAnnFilters )
#define RIP_CREATE_ACCEPT_FILTERS_LOCK()  \
        InitializeCriticalSection( &g_csAccFilters )
#define RIP_LOCK_ACCEPT_FILTERS()         \
        EnterCriticalSection( &g_csAccFilters )
#define RIP_UNLOCK_ACCEPT_FILTERS()                \
        LeaveCriticalSection( &g_csAccFilters )

// net\tcpip\services\telnet\server\common\tlntutils.h
#define INHERITABLE_NULL_DESCRIPTOR_ATTRIBUTE( sa ) \
    sa.nLength = sizeof( SECURITY_ATTRIBUTES ); \
    sa.bInheritHandle = TRUE; \
    sa.lpSecurityDescriptor = NULL;

// net\tcpip\services\telnet\server\tlntsess\rfcproto.cpp
#define INCREMENT_ROWS( rows, inc ) \
        { \
            rows += inc; \
            if( rows >= m_pSession->CSession::m_wRows ) \
            { \
                rows = m_pSession->CSession::m_wRows - 1;\
                wTypeOfCoords       = RELATIVE_COORDS;\
            }\
        }

// net\tcpip\services\telnet\server\tlntsess\scraper.h
#define ISSESSION_TIMEOUT_DISABLED( dwIdleSessionTimeOut ) ( dwIdleSessionTimeOut == ~0 )

// net\tcpip\tpipv6\dplayip6\dplaysvr.h
#define INIT_DPLAYSVR_CSECT() InitializeCriticalSection(&gcsCritSection);
#define ENTER_DPLAYSVR() EnterCriticalSection(&gcsCritSection),gnCSCount++;
#define ENTER_DPLAYSVR() EnterCriticalSection(&gcsCritSection);
#define LEAVE_DPLAYSVR() LeaveCriticalSection(&gcsCritSection);

// net\tcpip\tpipv6\dplayip6\dpsp.h
#define INIT_DPSP_CSECT() InitializeCriticalSection(&gcsDPSPCritSection);
#define ENTER_DPSP() EnterCriticalSection(&gcsDPSPCritSection),gCSCount++;
#define LEAVE_DPSP() gCSCount--,LeaveCriticalSection(&gcsDPSPCritSection);
#define ENTER_DPSP() EnterCriticalSection(&gcsDPSPCritSection);
#define LEAVE_DPSP() LeaveCriticalSection(&gcsDPSPCritSection);

// net\tcpip\tpipv6\dplsvr6\dplaysvr.h
#define INIT_DPLAYSVR_CSECT() InitializeCriticalSection(&gcsCritSection);
#define ENTER_DPLAYSVR() EnterCriticalSection(&gcsCritSection),gnCSCount++;
#define ENTER_DPLAYSVR() EnterCriticalSection(&gcsCritSection);
#define LEAVE_DPLAYSVR() LeaveCriticalSection(&gcsCritSection);

// net\tcpip\tpipv6\tcpip6\inc\addr.h
#define LOCKED_DELAY_DEREF_AO(a) (a)->ao_usecnt--; \
\
    if (!(a)->ao_usecnt && !AO_BUSY((a)) && AO_PENDING((a))) { \
        SET_AO_BUSY((a)); \
        ExQueueWorkItem(&(a)->ao_workitem, CriticalWorkQueue); \
    }

// net\unimodem\src\tsp\appdlg.cpp
#define INITCRITICALSECTION(_x) InitializeCriticalSection(&(_x))
#define ENTERCRITICALSECTION(_x) EnterCriticalSection(&(_x))
#define LEAVECRITICALSECTION(_x) LeaveCriticalSection(&(_x))

// net\unimodem\src\tsp\cdevcall.cpp
#define NEW_CALLSTATE(_X,_S,_M,_psl)\
                    {\
                        CALLINFO *pCall = m_pLine->pCall; \
                        pCall->dwCallState = (_S); \
                        pCall->dwCallStateMode = (_M); \
                        GetSystemTime (&pCall->stStateChange); \
                             mfn_LineEventProc( \
                             pCall->htCall, \
                             LINE_CALLSTATE, \
                             (_S), (_M), \
                             pCall->dwCurMediaModes, \
                             _psl\
                             );\
                    }

// net\upnp\upnpui\dll\updpidl.h
#define CBUPNPDEVICEFOLDPIDL_MIN    sizeof(UPNPUI_PIDL_HEADER)

// net\wins\mib\winsmib.c
#define PULL_ID_M(pMib, Val_Id_e) { \
  if (pMib->Storage == &MIB_CommRetryCountStore) { Val_Id_e = COMM_RETRY_E; }else{\
  if (pMib->Storage == &MIB_PullInitTimeStore) { Val_Id_e = PULL_INIT_TIME_E;} else{\
 }}}
#define PUSH_ID_M(pMib, Val_Id_e) { \
  if (pMib->Storage == &MIB_RplOnAddChgStore) { Val_Id_e = RPL_ON_ADD_CHG_E;} else{\
  if (pMib->Storage == &MIB_PushInitTimeStore) { Val_Id_e = PUSH_INIT_TIME_E;}else{ \
 }}}

// net\wins\server\inc\rplpush.h
#define RPLPUSH_INIT_PUSH_RECS_M(pWinsCnf)				\
   {									\
	if (LiGtrZero(NmsNmhMyMaxVersNo))			        \
	{								\
		if (							\
			((pWinsCnf)->PushInfo.InitTimePush == 0) && 	\
			((pWinsCnf)->PushInfo.NoPushRecsWValUpdCnt != 0)\
		   )							\
		{							\
			WinsCnfSetLastUpdCnt((pWinsCnf));		\
		}							\
	}								\
  }

// net\wlbs\driver\load.h
#define NLB_SESSION_SUPPORT_ENABLED()                   \
            (NLB_PPTP_SESSION_SUPPORT_ENABLED()         \
             || NLB_IPSEC_SESSION_SUPPORT_ENABLED())

// printscan\fax\faxcover\src\cpeobj.cpp
#define XinBOUNDS          \
   ((position.right > position.left) \
                 ? point.x > position.left && point.x < position.right \
         : point.x > position.right && point.x < position.left)
#define YinBOUNDS          \
   ((position.top > position.bottom) \
                 ? point.y > position.bottom && point.y < position.top \
         : point.y > position.top && point.y < position.bottom)

// printscan\fax\print\faxprint\faxui\faxui.h
#define EnterDrvSem() EnterCriticalSection(&faxuiSemaphore)
#define LeaveDrvSem() LeaveCriticalSection(&faxuiSemaphore)

// printscan\fax\provider\t30\comm\modem.c
#define TIME_DELTA(prev, now)\
        (((prev)<=(now)) ?((now)-(prev)) : (now) + (0xffffffffL-(prev)))

// printscan\fax\provider\t30\headers\nsfmacro.h
#define SetBCSTD2(p, s, c, d)				\
			(((p)->vSecurity)	 = (s));	\
			(((p)->vMsgCompress) = (c));	\
			(((p)->fDontCache)   = (d));

// printscan\fax\setup\wizdll\dlgsec.c
#define MY_SET_FOCUS    (WM_USER+1000)

// printscan\fax\test\faxvrfy\faxvrfy.h
#define UM_TIMEOUT_ENDED        (WM_USER + 4)

// printscan\faxsrv\src\faxcover\src\cpeobj.cpp
#define XinBOUNDS		   \
   ((position.right > position.left) \
				 ? point.x > position.left && point.x < position.right \
		 : point.x > position.right && point.x < position.left)
#define YinBOUNDS		   \
   ((position.top > position.bottom) \
				 ? point.y > position.bottom && point.y < position.top \
		 : point.y > position.top && point.y < position.bottom)

// printscan\faxsrv\src\faxverify\faxvrfy\faxvrfy.h
#define UM_TIMEOUT_ENDED        (WM_USER + 4)

// printscan\faxsrv\src\print\faxprint\faxui\faxui.h
#define EnterDrvSem() EnterCriticalSection(&faxuiSemaphore)
#define LeaveDrvSem() LeaveCriticalSection(&faxuiSemaphore)

// printscan\faxsrv\src\provider\t30\comm\modem.c
#define TIME_DELTA(prev, now)\
    (((prev)<=(now)) ?((now)-(prev)) : (now) + (0xffffffffL-(prev)))

// printscan\faxsrv\src\provider\t30\headers\nsfmacro.h
#define SetBCSTD2(p, s, c, d)				\
			(((p)->vSecurity)	 = (s));	\
			(((p)->vMsgCompress) = (c));	\
			(((p)->fDontCache)   = (d));

// printscan\faxsrv\src\sdktools\msvc15\include\penwin.h
#define PDTT_ALL (PDTT_PENINFO|PDTT_UPPOINTS|PDTT_OEMDATA|PDTT_COLINEAR)

// printscan\faxsrv\src\sdktools\msvc15\include\windows.h
#define MAKEPOINT(l)	    (*((POINT FAR*)&(l)))

// printscan\faxsrv\src\sdktools\msvc15\include\winsock.h
#define timerisset(tvp)         ((tvp)->tv_sec || (tvp)->tv_usec)
#define timercmp(tvp, uvp, cmp) \
        ((tvp)->tv_sec cmp (uvp)->tv_sec || \
         (tvp)->tv_sec == (uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)

// printscan\faxsrv\src\test\src\xxxunusedxxx\deviceioctls\myntdefs.h
#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }

// printscan\print\drivers\usermode\driverui\driverui.h
#define ENTER_CRITICAL_SECTION() EnterCriticalSection(&gCriticalSection)
#define LEAVE_CRITICAL_SECTION() LeaveCriticalSection(&gCriticalSection)

// printscan\print\drivers\usermode\inc\parser.h
#define GETQUALITY_X(pRes) \
    (((INT)pRes->dwResolutionID >= DMRES_HIGH  &&  (INT)pRes->dwResolutionID <= DMRES_DRAFT) ? (INT)pRes->dwResolutionID : pRes->iXdpi)
#define GETQUALITY_Y(pRes) \
    (((INT)pRes->dwResolutionID >= DMRES_HIGH  &&  (INT)pRes->dwResolutionID <= DMRES_DRAFT) ? (INT)pRes->dwResolutionID : pRes->iYdpi)

// printscan\print\drivers\usermode\msplot\lib\cachegpc.c
    #define ACQUIREGPCSEM()     EnterCriticalSection(&CachedGPCDataCS)
    #define CREATEGPCSEM()      InitializeCriticalSection(&CachedGPCDataCS)

// printscan\print\drivers\usermode\msplot\plotui\devcaps.c
#define pptsdwRet   ((POINTS *)&dwRet)

// printscan\print\drivers\usermode\unidrv2\font\fmcallbk.c
#define CALL_OEMOUTPUTCHARSTR(type, count, startpoint) \
    if(bCOMInterface) \
    { \
        HComOutputCharStr((POEM_PLUGIN_ENTRY)pPDev->pOemEntry, \
                        &pPDev->devobj, \
                        (PUNIFONTOBJ)pUFObj, \
                        (type), \
                        (count), \
                        (startpoint)); \
    } \
    else \
    { \
        if (pfnOEMOutputCharStr) \
        pfnOEMOutputCharStr(&pPDev->devobj, \
                            (PUNIFONTOBJ)pUFObj, \
                            (type), \
                            (count), \
                            (startpoint)); \
    }

// printscan\print\drivers\usermode\unidrv2\font\fmmacro.h
#define POINTEQUAL(pt1,pt2)         ((pt1.x == pt2.x) && (pt1.y == pt2.y))

// printscan\print\drivers\usermode\unidrv2\inc\pdev.h
#define INIT_CRITICAL_SECTION()     InitializeCriticalSection(&gUniCritSection)
#define ENTER_CRITICAL_SECTION()    EnterCriticalSection(&gUniCritSection)
#define LEAVE_CRITICAL_SECTION()    LeaveCriticalSection(&gUniCritSection)

// printscan\print\spooler\inetpp2\server\anycon.hxx
    #define WIN9X_TIMEOUT_ASYNC(ContextX, BoolX) \
        (ContextX)->TimeoutWait(BoolX)

// printscan\print\spooler\inetpp2\server\basicsec.cxx
#define GETTOK_FLGS (TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY)

// printscan\print\spooler\inetpp2\server\sem.h
#define semEnterCrit() EnterCriticalSection(&g_csMonitorSection)
#define semLeaveCrit() LeaveCriticalSection(&g_csMonitorSection)
#define semInitCrit()  InitializeCriticalSection(&g_csMonitorSection)

// printscan\print\spooler\inetsrv\gencab.h
#define InitCABCrit()   InitializeCriticalSection(&g_csGenCab)

// printscan\print\spooler\inetsrv\spool.cxx
#define EnterSplSem()    EnterCriticalSection(&SplCritSect)
#define LeaveSplSem()    LeaveCriticalSection(&SplCritSect)

// printscan\print\spooler\localspl\inet.cxx
#define EnterClient()  EnterCriticalSection( &ClientCS );
#define EnterServer()  EnterCriticalSection( &ServerCS );
#define LeaveClient()  LeaveCriticalSection( &ClientCS );
#define LeaveServer()  LeaveCriticalSection( &ServerCS );

// printscan\print\spooler\monitors\dynamon\dynadefs.h
#define  ECS(arg1)   EnterCriticalSection( &arg1 )
#define  LCS(arg1)   LeaveCriticalSection( &arg1 )
#define  ICS(arg1)   InitializeCriticalSection( &arg1 )

// printscan\print\spooler\spoolss\client\client.h
#define vEnterSem() EnterCriticalSection(&ClientSection)
#define vLeaveSem() LeaveCriticalSection(&ClientSection)

// printscan\print\spooler\spoolss\dll\router.h
#define EnterRouterSem() EnterCriticalSection(&RouterNotifySection)
#define LeaveRouterSem() LeaveCriticalSection(&RouterNotifySection)

// printscan\print\spooler\spoolss\dll\threadm.c
#define ENTER_CRITICAL(pTMStateVar) \
    EnterCriticalSection(pTMStateVar->pTMStateStatic->pCritSec)
#define LEAVE_CRITICAL(pTMStateVar) \
    LeaveCriticalSection(pTMStateVar->pTMStateStatic->pCritSec)

// printscan\print\spooler\spoolss\server\kmspool.c
#define ENTER_WAIT_LIST() EnterCriticalSection(&ThreadCriticalSection)
#define EXIT_WAIT_LIST()  LeaveCriticalSection(&ThreadCriticalSection)

// printscan\print\spooler\wpnpinst\wow\inc\penwin.h
#define PDTT_ALL (PDTT_PENINFO|PDTT_UPPOINTS|PDTT_OEMDATA|PDTT_COLINEAR)

// printscan\print\spooler\wpnpinst\wow\inc\printer.h
#define MAKEPOINT(l)    (*((POINT *)&l))

// printscan\print\spooler\wpnpinst\wow\inc\windows.h
#define MAKEPOINT(l)        (*((POINT FAR*)&(l)))

// printscan\ui\photowiz\seltemp.h
#define STP_MSG_DO_READ_NUM_PICS (WM_USER+351)   // post back to ourselves to read the number of time to use each picture

// printscan\wia\drivers\util\rwspy\detours.h
#define DETOUR_SECTION_HEADER_DECLARE(cbSectionSize) \
{ \
      sizeof(DETOUR_SECTION_HEADER),\
      DETOUR_SECTION_HEADER_SIGNATURE,\
      sizeof(DETOUR_SECTION_HEADER),\
      (cbSectionSize),\
      \
      0,\
      0,\
      0,\
      0,\
      \
      0,\
      0,\
      0,\
      0,\
}

// printscan\wia\inc\stisvc.h
#define STI_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED       | \
                                 SYNCHRONIZE                   | \
                                 STI_QUERY_SECURITY            | \
                                 STI_SET_SECURITY              | \
                                 STI_QUERY_STATISTICS          | \
                                 STI_CLEAR_STATISTICS          | \
                                 STI_QUERY_ADMIN_INFORMATION   | \
                                 STI_SET_ADMIN_INFORMATION       \
                                )
#define STI_GENERIC_READ       (STANDARD_RIGHTS_READ           | \
                                 STI_QUERY_SECURITY            | \
                                 STI_QUERY_ADMIN_INFORMATION   | \
                                 STI_QUERY_STATISTICS)
#define STI_GENERIC_WRITE      (STANDARD_RIGHTS_WRITE          | \
                                 STI_SET_SECURITY              | \
                                 STI_SET_ADMIN_INFORMATION     | \
                                 STI_CLEAR_STATISTICS)

// printscan\wia\setup\clsinst\sti_ci.h
#define MAX_DATA_SECTION        512*sizeof(TCHAR)

// public\ddk\inc\hbapiwmi.h
    #define MSFC_FibrePortHBAStatistics_SecondsSinceLastReset_SIZE sizeof(LONGLONG)

// public\ddk\inc\mountmgr.h
#define IOCTL_MOUNTMGR_CREATE_POINT                 CTL_CODE(MOUNTMGRCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_CREATED   CTL_CODE(MOUNTMGRCONTROLTYPE, 6, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\ddk\inc\ntddk.h
#define CONTEXT_FLOATING_POINT  (CONTEXT_i386 | 0x00000008L) // 387 state
#define CONTEXT_FLOATING_POINT  (CONTEXT_AMD64 | 0x8L)
#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)
#define CONTEXT_LOWER_FLOATING_POINT    (CONTEXT_IA64 | 0x00000002L)
#define CONTEXT_HIGHER_FLOATING_POINT   (CONTEXT_IA64 | 0x00000004L)
#define CONTEXT_FLOATING_POINT          (CONTEXT_LOWER_FLOATING_POINT | CONTEXT_HIGHER_FLOATING_POINT)
#define CONTEXT_FULL                    (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#define VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))
#define FILE_CHARACTERISTICS_PROPAGATED (   FILE_REMOVABLE_MEDIA   | \
                                            FILE_READ_ONLY_DEVICE  | \
                                            FILE_FLOPPY_DISKETTE   | \
                                            FILE_WRITE_ONCE_MEDIA  | \
                                            FILE_DEVICE_SECURE_OPEN  )
#define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY|\
                            SECTION_MAP_WRITE |      \
                            SECTION_MAP_READ |       \
                            SECTION_MAP_EXECUTE |    \
                            SECTION_EXTEND_SIZE)
#define SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3) // winnt

// public\ddk\inc\ntdef.h
#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }

// public\ddk\inc\ntia64.h
#define CONTEXT_LOWER_FLOATING_POINT    (CONTEXT_IA64 | 0x00000002L)
#define CONTEXT_HIGHER_FLOATING_POINT   (CONTEXT_IA64 | 0x00000004L)
#define CONTEXT_FLOATING_POINT          (CONTEXT_LOWER_FLOATING_POINT | CONTEXT_HIGHER_FLOATING_POINT)
#define CONTEXT_FULL                    (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)

// public\ddk\inc\wdm\usbdlib.h
#define GET_USBD_INTERFACE_SIZE(numEndpoints) (sizeof(USBD_INTERFACE_INFORMATION) + \
                        sizeof(USBD_PIPE_INFORMATION)*(numEndpoints))
#define GET_USBD_INTERFACE_SIZE(numEndpoints) (sizeof(USBD_INTERFACE_INFORMATION) + \
                        (sizeof(USBD_PIPE_INFORMATION)*(numEndpoints)) \
                         - sizeof(USBD_PIPE_INFORMATION))

// public\ddk\inc\wdm\wdm.h
#define VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))
#define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY|\
                            SECTION_MAP_WRITE |      \
                            SECTION_MAP_READ |       \
                            SECTION_MAP_EXECUTE |    \
                            SECTION_EXTEND_SIZE)
#define SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

// public\ddk\inc\wdm\wmidata.h
    #define MSMCAEvent_SystemEventError_SEL_TIME_STAMP_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_ConfigurationFH_DwellTime_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_PassiveTripPoint_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_CriticalTripPoint_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_ActiveTripPoint_SIZE sizeof(ULONG[10])
    #define WMI_DISK_PERFORMANCE_ReadTime_SIZE sizeof(LONGLONG)
    #define WMI_DISK_PERFORMANCE_WriteTime_SIZE sizeof(LONGLONG)
    #define WMI_DISK_PERFORMANCE_IdleTime_SIZE sizeof(LONGLONG)
    #define WMI_DISK_PERFORMANCE_QueryTime_SIZE sizeof(LONGLONG)
    #define ATAPI_FAILURE_PREDICT_DATA_TotalTime_SIZE sizeof(USHORT)
    #define ATAPI_FAILURE_PREDICT_DATA_ShortPollTimeInMinutes_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_ExtendedPollTimeInMinutes_SIZE sizeof(UCHAR)
    #define STORAGE_SCSI_INFO_EXCEPTIONS_IntervalTimer_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_SupportIntervalTimeouts_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_PERF_TIME_READING_DELAY_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_TIME_READING_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_TIME_STREAMING_DELAY_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_TIME_STREAMING_SIZE sizeof(LONGLONG)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_TimetoCleanDrive_SIZE sizeof(BOOLEAN)

// public\halkit\inc\nthal.h
#define CONTEXT_FLOATING_POINT  (CONTEXT_i386 | 0x00000008L) // 387 state
#define CONTEXT_FLOATING_POINT  (CONTEXT_AMD64 | 0x8L)
#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)
#define CONTEXT_LOWER_FLOATING_POINT    (CONTEXT_IA64 | 0x00000002L)
#define CONTEXT_HIGHER_FLOATING_POINT   (CONTEXT_IA64 | 0x00000004L)
#define CONTEXT_FLOATING_POINT          (CONTEXT_LOWER_FLOATING_POINT | CONTEXT_HIGHER_FLOATING_POINT)
#define CONTEXT_FULL                    (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#define VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))
#define FILE_CHARACTERISTICS_PROPAGATED (   FILE_REMOVABLE_MEDIA   | \
                                            FILE_READ_ONLY_DEVICE  | \
                                            FILE_FLOPPY_DISKETTE   | \
                                            FILE_WRITE_ONCE_MEDIA  | \
                                            FILE_DEVICE_SECURE_OPEN  )

// public\ifskit\inc\ntifs.h
#define VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))
#define CONTEXT_FLOATING_POINT  (CONTEXT_i386 | 0x00000008L) // 387 state
#define CONTEXT_FLOATING_POINT  (CONTEXT_AMD64 | 0x8L)
#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)
#define CONTEXT_LOWER_FLOATING_POINT    (CONTEXT_IA64 | 0x00000002L)
#define CONTEXT_HIGHER_FLOATING_POINT   (CONTEXT_IA64 | 0x00000004L)
#define CONTEXT_FLOATING_POINT          (CONTEXT_LOWER_FLOATING_POINT | CONTEXT_HIGHER_FLOATING_POINT)
#define CONTEXT_FULL                    (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#define FILE_CHARACTERISTICS_PROPAGATED (   FILE_REMOVABLE_MEDIA   | \
                                            FILE_READ_ONLY_DEVICE  | \
                                            FILE_FLOPPY_DISKETTE   | \
                                            FILE_WRITE_ONCE_MEDIA  | \
                                            FILE_DEVICE_SECURE_OPEN  )
#define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY|\
                            SECTION_MAP_WRITE |      \
                            SECTION_MAP_READ |       \
                            SECTION_MAP_EXECUTE |    \
                            SECTION_EXTEND_SIZE)
#define SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3) // winnt
#define SeQuerySubjectContextToken( SubjectContext ) \
        ( ARGUMENT_PRESENT( ((PSECURITY_SUBJECT_CONTEXT) SubjectContext)->ClientToken) ? \
            ((PSECURITY_SUBJECT_CONTEXT) SubjectContext)->ClientToken : \
            ((PSECURITY_SUBJECT_CONTEXT) SubjectContext)->PrimaryToken )

// public\internal\com\inc\corhdr.h
#define IsTdHasSecurity(x)                  ((x) & tdHasSecurity)
#define IsMdPinvokeImpl(x)                  ((x) & mdPinvokeImpl)
#define IsMdHasSecurity(x)                  ((x) & mdHasSecurity)
#define IsMdRequireSecObject(x)             ((x) & mdRequireSecObject)
#define IsFdPinvokeImpl(x)                  ((x) & fdPinvokeImpl)
#define IsFdHasSecurity(x)                  ((x) & fdHasSecurity)

// public\internal\ds\inc\nlmon.h
#define LOCK_LISTS()   EnterCriticalSection( &GlobalListCritSect )
#define UNLOCK_LISTS() LeaveCriticalSection( &GlobalListCritSect )

// public\internal\ds\inc\secedit.h
#define AREA_LOCAL_POLICY        (AREA_AUDIT_POLICY |\
                                  AREA_PRIVILEGES |\
                                  AREA_SECURITY_OPTIONS)

// public\internal\multimedia\inc\d3prmdef.h
#define D3DRMCLEAR_ALL                  (D3DRMCLEAR_TARGET | \
					 D3DRMCLEAR_ZBUFFER | \
					 D3DRMCLEAR_DIRTYRECTS)

// public\internal\multimedia\inc\ddmc.h
#define IVideoAccelerator_Release(p)                 (p)->lpVtbl->Release(p)

// public\internal\multimedia\inc\ddmcp.h
#define IVideoAccelerator_Release(p)                 (p)->lpVtbl->Release(p)

// public\internal\multimedia\inc\ddrawp.h
#define GET_WHQL_MONTH( dwWHQLLevel ) \
    ( ( (dwWHQLLevel) / 0x100 ) & 0x00ff )
#define GET_WHQL_DAY( dwWHQLLevel ) \
    ( (dwWHQLLevel) & 0xff )
#define DDSCAPS2_CUBEMAP_ALLFACES ( DDSCAPS2_CUBEMAP_POSITIVEX |\
                                    DDSCAPS2_CUBEMAP_NEGATIVEX |\
                                    DDSCAPS2_CUBEMAP_POSITIVEY |\
                                    DDSCAPS2_CUBEMAP_NEGATIVEY |\
                                    DDSCAPS2_CUBEMAP_POSITIVEZ |\
                                    DDSCAPS2_CUBEMAP_NEGATIVEZ )

// public\internal\multimedia\inc\ddrawpr.h
    #define DOHALCALL( halcall, fn, data, rc, isHEL ) \
        if( (fn != _DDHAL_##halcall) && !isHEL ) { \
            ENTER_WIN16LOCK(); \
            rc = fn( &data ); \
            LEAVE_WIN16LOCK(); \
        } else { \
            rc = fn( &data ); \
        }
    #define DOHALCALL_NOWIN16( halcall, fn, data, rc, isHEL ) \
            rc = fn( &data );
    #define DOHALCALL( halcall, fn, data, rc, isHEL ) \
            if (fn) \
                rc = fn( &data );\
            else\
                rc = DDHAL_DRIVER_NOTHANDLED;
    #define DOHALCALL_NOWIN16( halcall, fn, data, rc, isHEL ) \
            if (fn) \
                rc = fn( &data );\
            else\
                rc = DDHAL_DRIVER_NOTHANDLED;
#define CHEAP_LEAVE {LeaveGlobalCriticalSection(&CheapMutexPerProcess);}
#define CHEAP_ENTER {EnterGlobalCriticalSection(&CheapMutexPerProcess);}
                    #define FINI_DDRAW_CSECT() {DetachFromGlobalCriticalSection(&CheapMutexPerProcess);}
                #define ENTER_DDRAW() \
                        DPF( 7, "*****%08lx ENTER_DDRAW: CNT = %ld," REMIND( "" ), GETCURRPID(), iDLLCSCnt ); \
                        EnterCriticalSection( (LPCRITICAL_SECTION) lpDDCS ); \
                        INCCSCNT(); \
                        DPF( 7, "*****%08lx GOT DDRAW CSECT: CNT = %ld," REMIND(""), GETCURRPID(), iDLLCSCnt );
                #define LEAVE_DDRAW() \
                        DECCSCNT() \
                        DPF( 7, "*****%08lx LEAVE_DDRAW: CNT = %ld," REMIND( "" ), GETCURRPID(), iDLLCSCnt ); \
                        LeaveCriticalSection( (LPCRITICAL_SECTION) lpDDCS );
                #define ENTER_DDRAW()   \
                            DPF( 7, "*****%08lx ENTER_WIN16LOCK: CNT = %ld," REMIND( "" ), GETCURRPID(), iWin16Cnt ); \
                            _EnterSysLevel( lpWin16Lock ); \
                            INCW16CNT(); \
                            DPF( 7, "*****%08lx GOT WIN16LOCK: CNT = %ld," REMIND(""), GETCURRPID(), iWin16Cnt );
                #define LEAVE_DDRAW() \
                            DECW16CNT() \
                            DPF( 7, "*****%08lx LEAVE_WIN16LOCK: CNT = %ld," REMIND( "" ), GETCURRPID(), iWin16Cnt ); \
                            _LeaveSysLevel( lpWin16Lock );
            #define ENTER_DRIVERLISTCSECT() \
                        EnterCriticalSection( &csDriverObjectList );
            #define LEAVE_DRIVERLISTCSECT() \
                        LeaveCriticalSection( &csDriverObjectList );
        #define ENTER_WIN16LOCK()       \
                    DPF( 7, "*****%08lx ENTER_WIN16LOCK: CNT = %ld," REMIND( "" ), GETCURRPID(), iWin16Cnt ); \
                    _EnterSysLevel( lpWin16Lock ); \
                    INCW16CNT(); \
                    DPF( 7, "*****%08lx GOT WIN16LOCK: CNT = %ld," REMIND(""), GETCURRPID(), iWin16Cnt );
        #define LEAVE_WIN16LOCK() \
                    DECW16CNT() \
                    DPF( 7,"*****%08lx LEAVE_WIN16LOCK: CNT = %ld," REMIND( "" ), GETCURRPID(), iWin16Cnt ); \
                    _LeaveSysLevel( lpWin16Lock );
    #define GETDDVXDHANDLE( pdrv_lcl ) \
        ( ( GetCurrentProcessId() == ( pdrv_lcl )->dwProcessId ) ? (HANDLE) ( ( pdrv_lcl )->hDDVxd ) : hHelperDDVxd )

// public\internal\multimedia\inc\dinputp.h
#define DI8DEVTYPEJOYSTICK_MIN_CAPS                 ( JOY_HWS_HASPOV | JOY_HWS_HASZ )
#define DI8DEVTYPEFLIGHT_MIN_CAPS                   ( JOY_HWS_HASPOV | JOY_HWS_HASZ )

// public\internal\multimedia\inc\dsoundp.h
#define IUnknown_Release(p)             (p)->lpVtbl->Release(p)
#define DSBCAPS_CTRLATTENUATION     (DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN)
#define DSBCAPS_CTRLNOVIRT          (DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN | DSBCAPS_CTRLFREQUENCY)

// public\internal\multimedia\inc\dvpp.h
#define IVideoPort_Release(p)                   (p)->lpVtbl->Release(p)
#define IVideoPortNotify_Release(p)                 (p)->lpVtbl->Release(p)
#define IVideoPortNotify_ReleaseNotification(p,a)   (p)->lpVtbl->ReleaseNotification(p,a)
#define IVideoPortNotify_ReleaseNotification(p,a)   (p)->lpVtbl->ReleaseNotification(a)

// public\internal\multimedia\inc\ehui\dusercore.h
#define IGTM_NONE               (0)     // | No special threading model
#define IGTM_SINGLE             (1)     // | Single threaded application
#define IGTM_SEPARATE           (2)     // | MT with single thread per context
#define IGMM_COMPATIBLE         (1)     // | Core running in Compatible mode
#define IGMM_ADVANCED           (2)     // | Core running in Advanced mode
#define IGMM_STANDARD           (3)     // | Standard mode on Whistler
#define IGPM_BLEND              (0)     // | Optimize for blend between speed / size
#define IGPM_SPEED              (1)     // | Optimize for pure speed
#define IGPM_SIZE               (2)     // | Optimize for minimum working set
#define EVENT_DELEGATE(instance, function) \
    DUser::EventDelegate::Build(reinterpret_cast<DUser::Gadget *>(instance), \
            reinterpret_cast<DUser::EventDelegate::Proc>(function))
#define GMFI_VALID         (GMFI_PAINT |                                                 \
                            GMFI_INPUTKEYBOARD | GMFI_INPUTMOUSE | GMFI_INPUTMOUSEMOVE | \
                            GMFI_CHANGESTATE | GMFI_CHANGERECT | GMFI_CHANGESTYLE)
#define GMODIFIER_CONTROL   (GMODIFIER_LCONTROL | GMODIFIER_RCONTROL)
#define GMODIFIER_SHIFT     (GMODIFIER_LSHIFT   | GMODIFIER_RSHIFT)
#define GMODIFIER_ALT       (GMODIFIER_LALT     | GMODIFIER_RALT)
#define SGM_VALID          (SGM_FULL | SGM_RECEIVECONTEXT)
#define GENUM_TYPE         (GENUM_PARENTSUP | GENUM_PARENTSDOWN | \
                            GENUM_SHALLOWCHILD | GENUM_DEEPCHILD)
#define GENUM_VALID         (GENUM_CURRENT | GENUM_SIBLINGS | GENUM_TYPE | GENUM_MODIFYTREE)
#define GS_VALID           (GS_VISIBLE | GS_ENABLED | GS_KEYBOARDFOCUS | GS_MOUSEFOCUS | \
                            GS_CLIPINSIDE | GS_HREDRAW | GS_VREDRAW | GS_ZEROORIGIN | \
                            GS_CUSTOMHITTEST | GS_ADAPTOR | GS_NORESETINVALID)
#define IG_VALID           (IG_ME | IG_CHILDREN)

// public\internal\multimedia\inc\mmsysp.h
#define  WAVE_FORMAT_DIRECT_QUERY  (WAVE_FORMAT_QUERY | WAVE_FORMAT_DIRECT)
#define MIDI_CACHE_VALID    (MIDI_CACHE_ALL | MIDI_CACHE_BESTFIT | MIDI_CACHE_QUERY | MIDI_UNCACHE)
#define MMIO_DESCEND_VALID (MMIO_FINDCHUNK | MMIO_FINDRIFF | MMIO_FINDLIST)
#define MMIO_CREATE_VALID (MMIO_CREATERIFF | MMIO_CREATELIST)

// public\internal\net\inc\isnkrnl.h
#define MIPX_SETRIPTO      (I_MIPX | 113) /* Set RIP timeout              */
#define MIPX_SETRIPUSAGE   (I_MIPX | 128) /* Set RIP usage timeout        */
#define MIPX_SETSROUTEUSAGE (I_MIPX| 129) /* Set the SROUTE usage timeout */
#define MIPX_SETDELAYTIME  (I_MIPX | 136) /* Set cards delay time         */
#define MIPX_SETROUTEADV   (I_MIPX | 137) /* Route advertise timeout      */
#define MSPX_SETCONNTO     (I_MSPX | 112) /* Set the conn req timeout     */
#define MSPX_SETALIVETO    (I_MSPX | 114) /* Set the keepalive timeout    */

// public\internal\shell\inc\imapi\burnv.h
#define FILE_READ_ACCESS        ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS       ( 0x0002 )    // file & pipe

// public\internal\shell\inc\shlwapip.h
#define FDTF_DEFAULT        (FDTF_SHORTDATE | FDTF_SHORTTIME) // eg, "3/29/98 7:48 PM"

// public\internal\shell\inc\systrayp.h
#define STWM_NOTIFYSTICKYKEYS           (WM_USER + 204)

// public\internal\windows\inc\winuserp.h
#define FLASHW_VALID        (FLASHW_ALL | FLASHW_TIMERNOFG)

// public\sdk\amovie\inc\wxdebug.h
    #define DbgBreak(_x_)                   \
        DbgBreakPoint(TEXT(#_x_),TEXT(__FILE__),__LINE__)

// public\sdk\inc16\windows.h
#define MAKEPOINT(l)        (*((POINT FAR*)&(l)))

// public\sdk\inc16\windowsx.h
#define FORWARD_WM_WININICHANGE(hwnd, lpszSectionName, fn) \
    (void)(fn)((hwnd), WM_WININICHANGE, 0, (LPARAM)(LPCSTR)(lpszSectionName))
#define HANDLE_WM_TIMECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_TIMECHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_TIMECHANGE, 0, 0L)
#define HANDLE_WM_TIMER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_TIMER(hwnd, id, fn) \
    (void)(fn)((hwnd), WM_TIMER, (WPARAM)(UINT)(id), 0L)

// public\sdk\inc\allerror.h
#define DB_SEC_E_PERMISSIONDENIED        ((HRESULT)0x80040E09L)
#define DB_E_BADSCALE                    ((HRESULT)0x80040E3BL)
#define DB_SEC_E_AUTH_FAILED             ((HRESULT)0x80040E4DL)
#define MD_E_BADCOORDINATE               ((HRESULT)0x80040E62L)
#define SEC_E_BADTRUSTEEID               ((HRESULT)0x80040E6AL)
#define SEC_E_NOTRUSTEEID                ((HRESULT)0x80040E6BL)
#define SEC_E_INVALIDOBJECT              ((HRESULT)0x80040E6DL)
#define SEC_E_NOOWNER                    ((HRESULT)0x80040E6EL)
#define SEC_E_INVALIDOWNER               ((HRESULT)0x80040E70L)

// public\sdk\inc\atl21\atlcom.h
#define END_COM_MAP()   {NULL, 0, 0}};\
	return &_entries[1];}
#define END_COM_MAP()   {NULL, 0, 0}};\
	return _entries;}

// public\sdk\inc\atl21\atlctl.h
#define END_PROPERTY_MAP() \
			{NULL, 0, NULL, &IID_NULL} \
		}; \
		return pPropMap; \
	}

// public\sdk\inc\atl30\atlcom.h
#define END_PROPERTY_MAP() \
                        {NULL, 0, NULL, &IID_NULL, 0, 0, 0} \
                }; \
                return pPropMap; \
        }
#define END_PROP_MAP() \
                        {NULL, 0, NULL, &IID_NULL, 0, 0, 0} \
                }; \
                return pPropMap; \
        }
#define BEGIN_SERVICE_MAP(x) public: \
        HRESULT _InternalQueryService(REFGUID guidService, REFIID riid, void** ppvObject) \
        {
#define END_SERVICE_MAP() \
                return E_NOINTERFACE; \
        }
#define END_SINK_MAP() {0, NULL, 0, 0, NULL, NULL} }; return map;}

// public\sdk\inc\atl30\atldb.h
#define END_SCHEMA_MAP() \
		if (ppGuid != NULL) \
			return hr; \
		return E_INVALIDARG; \
	}
#define BEGIN_PROVIDER_COLUMN_MAP(theClass) \
	typedef theClass _Class; \
	template <class T> \
	static ATLCOLUMNINFO* GetColumnInfo(T* pv, DBORDINAL* pcCols) \
	{ \
	pv; \
	static ATLCOLUMNINFO _rgColumns [] = \
	{

// public\sdk\inc\atl30\atldbcli.h
#define END_ACCESSOR_MAP() \
		; \
		*pColumns = nColumns; \
		return S_OK; \
	}
#define END_PARAM_MAP() \
		*pColumns = nColumns; \
		return S_OK; \
	}

// public\sdk\inc\atl30\atlsnap.h
#define END_EXTENSION_SNAPIN_NODEINFO_MAP() \
			return CSnapInItem::GetDataClass(pDataObject, ppItem, pType); \
	};
#define END_SNAPINCOMMAND_MAP() \
			return hr; \
	}
#define BEGIN_SNAPINTOOLBARID_MAP(theClass) \
public: \
	static CSnapInToolbarInfo* GetToolbarInfo() \
	{ \
		static CSnapInToolbarInfo m_toolbarInfo[] = \
		{
#define END_SNAPINTOOLBARID_MAP() \
			{ NULL, NULL, NULL, 0, 0} \
		}; \
		return m_toolbarInfo; \
	}

// public\sdk\inc\cierror.h
#define QUERY_E_TIMEDOUT                 ((HRESULT)0x80041607L)
#define FILTER_S_NO_SECURITY_DESCRIPTOR  ((HRESULT)0x0004173CL)
#define CI_E_TIMEOUT                     ((HRESULT)0x8004181FL)

// public\sdk\inc\commctrl.h
#define TB_MAPACCELERATORA      (WM_USER + 78)  // wParam == ch, lParam int * pidBtn
#define TB_MAPACCELERATORW      (WM_USER + 90)  // wParam == ch, lParam int * pidBtn
#define TTM_SETDELAYTIME        (WM_USER + 3)
#define TTM_WINDOWFROMPOINT     (WM_USER + 16)
#define TTM_GETDELAYTIME        (WM_USER + 21)
#define TreeView_SetScrollTime(hwnd, uTime) \
    (UINT)SNDMSG((hwnd), TVM_SETSCROLLTIME, uTime, 0)
#define TreeView_GetScrollTime(hwnd) \
    (UINT)SNDMSG((hwnd), TVM_GETSCROLLTIME, 0, 0)
#define TreeView_MapAccIDToHTREEITEM(hwnd, id) \
    (HTREEITEM)SNDMSG((hwnd), TVM_MAPACCIDTOHTREEITEM, id, 0)
#define TreeView_MapHTREEITEMToAccID(hwnd, htreeitem) \
    (UINT)SNDMSG((hwnd), TVM_MAPHTREEITEMTOACCID, (WPARAM)htreeitem, 0)
#define DTS_TIMEFORMAT      0x0009 // use the time format (app must forward WM_WININICHANGE messages)

// public\sdk\inc\commctrl.rh
#define DTS_TIMEFORMAT      0x0009 // use the time format (app must forward WM_WININICHANGE messages)

// public\sdk\inc\d3dtypes.h
#define D3DSTATUS_CLIPINTERSECTIONALL   (       \
        D3DSTATUS_CLIPINTERSECTIONLEFT  |   \
        D3DSTATUS_CLIPINTERSECTIONRIGHT |   \
        D3DSTATUS_CLIPINTERSECTIONTOP   |   \
        D3DSTATUS_CLIPINTERSECTIONBOTTOM    |   \
        D3DSTATUS_CLIPINTERSECTIONFRONT |   \
        D3DSTATUS_CLIPINTERSECTIONBACK  |   \
        D3DSTATUS_CLIPINTERSECTIONGEN0  |   \
        D3DSTATUS_CLIPINTERSECTIONGEN1  |   \
        D3DSTATUS_CLIPINTERSECTIONGEN2  |   \
        D3DSTATUS_CLIPINTERSECTIONGEN3  |   \
        D3DSTATUS_CLIPINTERSECTIONGEN4  |   \
        D3DSTATUS_CLIPINTERSECTIONGEN5      \
        )
#define D3DSTATUS_DEFAULT   (           \
        D3DSTATUS_CLIPINTERSECTIONALL   |   \
        D3DSTATUS_ZNOTVISIBLE)

// public\sdk\inc\ddraw.h
#define DDSCAPS2_CUBEMAP_ALLFACES ( DDSCAPS2_CUBEMAP_POSITIVEX |\
                                    DDSCAPS2_CUBEMAP_NEGATIVEX |\
                                    DDSCAPS2_CUBEMAP_POSITIVEY |\
                                    DDSCAPS2_CUBEMAP_NEGATIVEY |\
                                    DDSCAPS2_CUBEMAP_POSITIVEZ |\
                                    DDSCAPS2_CUBEMAP_NEGATIVEZ )
#define DDERR_NOMIPMAPHW                        MAKE_DDHRESULT( 591 )
#define DDERR_NOTONMIPMAPSUBLEVEL               MAKE_DDHRESULT( 603 )

// public\sdk\inc\dinput.h
#define DIMOUSE_XAXISAB                         (0x82000200 |DIMOFS_X ) /* X Axis-absolute: Some mice natively report absolute coordinates  */
#define DIMOUSE_YAXISAB                         (0x82000200 |DIMOFS_Y ) /* Y Axis-absolute: Some mice natively report absolute coordinates */

// public\sdk\inc\dmerror.h
#define DMUS_E_TIME_PAST                MAKE_DMHRESULTERROR(0x0165)
#define DMUS_E_AUDIOVBSCRIPT_RUNTIMEERROR     MAKE_DMHRESULTERROR(0x0224)

// public\sdk\inc\dmusici.h
#define DMUS_PLAYMODE_PEDALPOINT        (DMUS_PLAYMODE_KEY_ROOT | DMUS_PLAYMODE_SCALE_INTERVALS)
#define DMUS_PLAYMODE_PEDALPOINTCHORD   (DMUS_PLAYMODE_KEY_ROOT | DMUS_PLAYMODE_CHORD_INTERVALS)
#define DMUS_PLAYMODE_PEDALPOINTALWAYS  (DMUS_PLAYMODE_PEDALPOINT | DMUS_PLAYMODE_PEDALPOINTCHORD)

// public\sdk\inc\dplay.h
#define DPERR_TIMEOUT                   MAKE_DPHRESULT( 240 )

// public\sdk\inc\dplay8.h
#define DPNERR_ENDPOINTNOTRECEIVING		MAKE_DPNHRESULT( 0x200 )
#define DPNERR_INVALIDENDPOINT			MAKE_DPNHRESULT( 0x330 )
#define DPNERR_TIMEDOUT					MAKE_DPNHRESULT( 0x630 )

// public\sdk\inc\dvoice.h
#define DVERR_TIMEOUT                   MAKE_DVHRESULT( 0x0175 )

// public\sdk\inc\esebkmsg.h
#define hrRestoreMapExists               ((HRESULT)0xC7FF07D8L)
#define hrBadCSectionParameter           ((HRESULT)0xC7FF0BC4L)
#define hrErrorFromESECall               ((HRESULT)0xC7FF1004L)
#define hrBadCheckpointSignature         ((HRESULT)0xC8000214L)
#define hrCheckpointCorrupt              ((HRESULT)0xC8000215L)
#define hrConsistentTimeMismatch         ((HRESULT)0xC8000227L)

// public\sdk\inc\imnxport.h
#define IXP_E_SECURE_CONNECT_FAILED			HR_E(0xCC1A)

// public\sdk\inc\indicml.h
#define INDICM_SETIMEICON                 (WM_USER+100)
#define INDICM_SETIMETOOLTIPS             (WM_USER+101)

// public\sdk\inc\ksdebug.h
   #define _DbgPrintF(lvl, strings) \
{ \
    if (((lvl)==DEBUG_VARIABLE) || (lvl < DEBUG_VARIABLE)) {\
        DbgPrint(STR_MODULENAME);\
        DbgPrint##strings;\
        DbgPrint("\n");\
        if ((lvl) == DEBUGLVL_ERROR) {\
            DbgBreakPoint();\
        } \
    } \
}
   #define _DbgPrintFEx(component, lvl, strings) \
{ \
    if ((lvl) <= DEBUG_VARIABLE) {\
        DbgPrintEx(component, lvl, STR_MODULENAME);\
        DbgPrintEx(component, lvl, strings);\
        DbgPrintEx(component, lvl, "\n");\
        if ((lvl) == DEBUGLVL_ERROR) {\
            DbgBreakPoint();\
        } \
    } \
}

// public\sdk\inc\mapicode.h
#define	HR_FAILED(_hr) FAILED((SCODE)(_hr))

// public\sdk\inc\mapidbg.h
#define Assert(t)										IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,"Assertion Failure: " #t),0))
#define AssertSz(t,psz)									IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz),0))
#define AssertSz1(t,psz,a1)								IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1),0))
#define AssertSz2(t,psz,a1,a2)							IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2),0))
#define AssertSz3(t,psz,a1,a2,a3)						IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3),0))
#define AssertSz4(t,psz,a1,a2,a3,a4)					IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4),0))
#define AssertSz5(t,psz,a1,a2,a3,a4,a5)					IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5),0))
#define AssertSz6(t,psz,a1,a2,a3,a4,a5,a6)				IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6),0))
#define AssertSz7(t,psz,a1,a2,a3,a4,a5,a6,a7)			IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7),0))
#define AssertSz8(t,psz,a1,a2,a3,a4,a5,a6,a7,a8)		IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8),0))
#define AssertSz9(t,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)		IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9),0))
#define SideAssert(t)									((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,"Assertion Failure: " #t)),0)
#define SideAssertSz(t,psz)								((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz)),0)
#define SideAssertSz1(t,psz,a1)							((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1)),0)
#define SideAssertSz2(t,psz,a1,a2)						((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2)),0)
#define SideAssertSz3(t,psz,a1,a2,a3)					((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3)),0)
#define SideAssertSz4(t,psz,a1,a2,a3,a4)				((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4)),0)
#define SideAssertSz5(t,psz,a1,a2,a3,a4,a5)				((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5)),0)
#define SideAssertSz6(t,psz,a1,a2,a3,a4,a5,a6)			((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6)),0)
#define SideAssertSz7(t,psz,a1,a2,a3,a4,a5,a6,a7)		((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7)),0)
#define SideAssertSz8(t,psz,a1,a2,a3,a4,a5,a6,a7,a8)	((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8)),0)
#define SideAssertSz9(t,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)	((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)),0)
#define NFAssert(t)										IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,"Assertion Failure: " #t),0))
#define NFAssertSz(t,psz)								IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz),0))
#define NFAssertSz1(t,psz,a1)							IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1),0))
#define NFAssertSz2(t,psz,a1,a2)						IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2),0))
#define NFAssertSz3(t,psz,a1,a2,a3)						IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3),0))
#define NFAssertSz4(t,psz,a1,a2,a3,a4)					IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4),0))
#define NFAssertSz5(t,psz,a1,a2,a3,a4,a5)				IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5),0))
#define NFAssertSz6(t,psz,a1,a2,a3,a4,a5,a6)			IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6),0))
#define NFAssertSz7(t,psz,a1,a2,a3,a4,a5,a6,a7)			IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7),0))
#define NFAssertSz8(t,psz,a1,a2,a3,a4,a5,a6,a7,a8)		IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8),0))
#define NFAssertSz9(t,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)	IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9),0))
#define NFSideAssert(t)									((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,"Assertion Failure: " #t)),0)
#define NFSideAssertSz(t,psz)							((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz)),0)
#define NFSideAssertSz1(t,psz,a1)						((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1)),0)
#define NFSideAssertSz2(t,psz,a1,a2)					((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2)),0)
#define NFSideAssertSz3(t,psz,a1,a2,a3)					((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3)),0)
#define NFSideAssertSz4(t,psz,a1,a2,a3,a4)				((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4)),0)
#define NFSideAssertSz5(t,psz,a1,a2,a3,a4,a5)			((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5)),0)
#define NFSideAssertSz6(t,psz,a1,a2,a3,a4,a5,a6)		((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6)),0)
#define NFSideAssertSz7(t,psz,a1,a2,a3,a4,a5,a6,a7)		((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7)),0)
#define NFSideAssertSz8(t,psz,a1,a2,a3,a4,a5,a6,a7,a8)	((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8)),0)
#define NFSideAssertSz9(t,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)	((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)),0)
#define DebugTraceResult(f,hr)							IFTRACE(((hr) ? DebugTraceFn(#f " returns 0x%08lX %s\n", GetScode(hr), SzDecodeScode(GetScode(hr))) : 0))
#define DebugTraceSc(f,sc)								IFTRACE(((sc) ? DebugTraceFn(#f " returns 0x%08lX %s\n", sc, SzDecodeScode(sc)) : 0))
#define DebugTraceArg(f,s)								IFTRACE(DebugTraceFn(#f ": bad parameter: " s "\n"))
#define TraceSz(psz)									IFTRACE(DebugTraceFn("~" psz))
#define TraceSz1(psz,a1)								IFTRACE(DebugTraceFn("~" psz,a1))
#define TraceSz2(psz,a1,a2)								IFTRACE(DebugTraceFn("~" psz,a1,a2))
#define TraceSz3(psz,a1,a2,a3)							IFTRACE(DebugTraceFn("~" psz,a1,a2,a3))
#define TraceSz4(psz,a1,a2,a3,a4)						IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4))
#define TraceSz5(psz,a1,a2,a3,a4,a5)					IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4,a5))
#define TraceSz6(psz,a1,a2,a3,a4,a5,a6)					IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4,a5,a6))
#define TraceSz7(psz,a1,a2,a3,a4,a5,a6,a7)				IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4,a5,a6,a7))
#define TraceSz8(psz,a1,a2,a3,a4,a5,a6,a7,a8)			IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4,a5,a6,a7,a8))
#define TraceSz9(psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)		IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4,a5,a6,a7,a8,a9))

// public\sdk\inc\mapidefs.h
#define MAPIMETHOD(method)				MAPIMETHOD_(HRESULT, method)
#define MAPI_DIAG_EXPANSION_FAILED					MAPI_DIAG( 30 )

// public\sdk\inc\mapival.h
#define ValidateParameters(eMethod, First)				\
		{	HRESULT   _hr_;								\
			_hr_ = __CPPValidateParameters(eMethod, (LPVOID) &First);	\
			if (HR_FAILED(_hr_)) return (_hr_);	}
#define CheckParameters(eMethod, First)				\
		AssertSz(HR_SUCCEEDED(__CPPValidateParameters(eMethod, &First)), "Parameter validation failed for method called by MAPI!")
#define FBadPropVal( lpPropVal)	(FAILED(ScCountProps( 1, lpPropVal, NULL)))
#define FBadRgPropVal( lpPropVal, cValues) \
		(FAILED(ScCountProps( cValues, lpPropVal, NULL)))
#define FBadRelease( lpObj)	FALSE
#define ValidateParms(x)	{ HRESULT _hr_ = HrValidateParameters x; if (HR_FAILED(_hr_)) return (_hr_); }
#define ValidateParms(x)	{ HRESULT _hr_ = HrValidateParametersV x; if (HR_FAILED(_hr_)) return (_hr_); }
#define ValidateParameters2( m, a1, a2 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters3( m, a1, a2, a3 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters4( m, a1, a2, a3, a4 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters5( m, a1, a2, a3, a4, a5 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters6( m, a1, a2, a3, a4, a5, a6 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters7( m, a1, a2, a3, a4, a5, a6, a7 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters8( m, a1, a2, a3, a4, a5, a6, a7, a8 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters9( m, a1, a2, a3, a4, a5, a6, a7, a8, a9 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters10( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters11( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters12( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters13( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters14( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters15( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters16( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters2( m, a1, a2 )	\
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters3( m, a1, a2, a3 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters4( m, a1, a2, a3, a4 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters5( m, a1, a2, a3, a4, a5 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters6( m, a1, a2, a3, a4, a5, a6 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters7( m, a1, a2, a3, a4, a5, a6, a7 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters8( m, a1, a2, a3, a4, a5, a6, a7, a8 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters9( m, a1, a2, a3, a4, a5, a6, a7, a8, a9 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters10( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters11( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters12( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters13( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters14( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters15( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters16( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters2( m, a1, a2 )	\
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters3( m, a1, a2, a3)	\
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters4( m, a1, a2, a3, a4 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters5( m, a1, a2, a3, a4, a5 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters6( m, a1, a2, a3, a4, a5, a6 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters7( m, a1, a2, a3, a4, a5, a6, a7 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters8( m, a1, a2, a3, a4, a5, a6, a7, a8 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters9( m, a1, a2, a3, a4, a5, a6, a7, a8, a9 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters10( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters11( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters12( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters13( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters14( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters15( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters16( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define Validate_IUnknown_Release( a1 ) \
			 ValidateParameters1( IUnknown_Release, a1 )
#define UlValidate_IUnknown_Release( a1 ) \
			 UlValidateParameters1( IUnknown_Release, a1 )
#define CheckParameters_IUnknown_Release( a1 ) \
			 CheckParameters1( IUnknown_Release, a1 )

// public\sdk\inc\mapiwin.h
#define ReleaseMutex(hObj)				((BOOL)1)

// public\sdk\inc\mfc42\afx.h
#define RUNTIME_CLASS(class_name) ((CRuntimeClass*)(&class_name::class##class_name))
#define ASSERT_KINDOF(class_name, object) \
	ASSERT((object)->IsKindOf(RUNTIME_CLASS(class_name)))
#define DECLARE_DYNAMIC(class_name) \
public: \
	static const AFX_DATA CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \
#define _DECLARE_DYNAMIC(class_name) \
public: \
	static AFX_DATA CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \
#define CATCH(class, e) } catch (class* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(class))); \
		_afxExceptionLink.m_pException = e;
#define AND_CATCH(class, e) } catch (class* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(class))); \
		_afxExceptionLink.m_pException = e;
#define CATCH_ALL(e) } catch (CException* e) \
	{ { ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); \
		_afxExceptionLink.m_pException = e;
#define AND_CATCH_ALL(e) } catch (CException* e) \
	{ { ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); \
		_afxExceptionLink.m_pException = e;
#define END_TRY } catch (CException* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); \
		_afxExceptionLink.m_pException = e; } }
#define CATCH(class, e) \
	else if (::AfxCatchProc(RUNTIME_CLASS(class))) \
	{ class* e = (class*)_afxExceptionLink.m_pException;
#define AND_CATCH(class, e) \
	} else if (::AfxCatchProc(RUNTIME_CLASS(class))) \
	{ class* e = (class*)_afxExceptionLink.m_pException;

// public\sdk\inc\mfc42\afxctl.h
#define BEGIN_OLEFACTORY(class_name) \
protected: \
	class class_name##Factory : public COleObjectFactoryEx \
	{ \
	public: \
		class_name##Factory(REFCLSID clsid, CRuntimeClass* pRuntimeClass, \
			BOOL bMultiInstance, LPCTSTR lpszProgID) : \
				COleObjectFactoryEx(clsid, pRuntimeClass, bMultiInstance, \
				lpszProgID) {} \
		virtual BOOL UpdateRegistry(BOOL);
#define IMPLEMENT_OLECREATE_EX(class_name, external_name, \
			l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	const TCHAR _szProgID_##class_name[] = _T(external_name); \
	AFX_DATADEF class_name::class_name##Factory class_name::factory( \
		class_name::guid, RUNTIME_CLASS(class_name), FALSE, \
		_szProgID_##class_name); \
	const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }; \
	HRESULT class_name::GetClassID(LPCLSID pclsid) \
		{ *pclsid = guid; return NOERROR; }
#define IMPLEMENT_OLECREATE_EX(class_name, external_name, \
			l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	static const TCHAR _szProgID_##class_name[] = _T(external_name); \
	AFX_DATADEF class_name::class_name##Factory class_name::factory( \
		class_name::guid, RUNTIME_CLASS(class_name), FALSE, \
		_szProgID_##class_name); \
	const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }; \
	HRESULT class_name::GetClassID(LPCLSID pclsid) \
		{ *pclsid = guid; return NOERROR; }

// public\sdk\inc\mfc42\afxdisp.h
#define IMPLEMENT_OLECREATE(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	AFX_DATADEF COleObjectFactory class_name::factory(class_name::guid, \
		RUNTIME_CLASS(class_name), FALSE, _T(external_name)); \
	AFX_COMDAT const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }; \

// public\sdk\inc\mfc42\afxisapi.h
#define ON_PARSE_COMMAND(FnName, mapClass, Args) \
	{ _T(#FnName), (AFX_PISAPICMD) (mapClass##CALL)mapClass::FnName,\
		Args, NULL },
#define DEFAULT_PARSE_COMMAND(FnName, mapClass) \
	{ _T(#FnName), (AFX_PISAPICMD) (mapClass##CALL)mapClass::FnName,\
		NULL, NULL },

// public\sdk\inc\mfc42\afxmsg_.h
#define ON_WM_TIMECHANGE() \
	{ WM_TIMECHANGE, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))&OnTimeChange },
#define ON_WM_NCMOUSEMOVE() \
	{ WM_NCMOUSEMOVE, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnNcMouseMove },
#define ON_WM_NCLBUTTONDOWN() \
	{ WM_NCLBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnNcLButtonDown },
#define ON_WM_NCLBUTTONUP() \
	{ WM_NCLBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnNcLButtonUp },
#define ON_WM_NCLBUTTONDBLCLK() \
	{ WM_NCLBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnNcLButtonDblClk },
#define ON_WM_NCRBUTTONDOWN() \
	{ WM_NCRBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnNcRButtonDown },
#define ON_WM_NCRBUTTONUP() \
	{ WM_NCRBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnNcRButtonUp },
#define ON_WM_NCRBUTTONDBLCLK() \
	{ WM_NCRBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnNcRButtonDblClk },
#define ON_WM_NCMBUTTONDOWN() \
	{ WM_NCMBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnNcMButtonDown },
#define ON_WM_NCMBUTTONUP() \
	{ WM_NCMBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnNcMButtonUp },
#define ON_WM_NCMBUTTONDBLCLK() \
	{ WM_NCMBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnNcMButtonDblClk },
#define ON_WM_MOUSEMOVE() \
	{ WM_MOUSEMOVE, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnMouseMove },
#define ON_WM_MOUSEWHEEL() \
	{ WM_MOUSEWHEEL, 0, 0, 0, AfxSig_bwsp, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(UINT, short, CPoint))&OnMouseWheel },
#define ON_WM_LBUTTONDOWN() \
	{ WM_LBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnLButtonDown },
#define ON_WM_LBUTTONUP() \
	{ WM_LBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnLButtonUp },
#define ON_WM_LBUTTONDBLCLK() \
	{ WM_LBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnLButtonDblClk },
#define ON_WM_RBUTTONDOWN() \
	{ WM_RBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnRButtonDown },
#define ON_WM_RBUTTONUP() \
	{ WM_RBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnRButtonUp },
#define ON_WM_RBUTTONDBLCLK() \
	{ WM_RBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnRButtonDblClk },
#define ON_WM_MBUTTONDOWN() \
	{ WM_MBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnMButtonDown },
#define ON_WM_MBUTTONUP() \
	{ WM_MBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnMButtonUp },
#define ON_WM_MBUTTONDBLCLK() \
	{ WM_MBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))&OnMButtonDblClk },
#define ON_WM_CONTEXTMENU() \
	{ WM_CONTEXTMENU, 0, 0, 0, AfxSig_vWp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*, CPoint))&OnContextMenu },

// public\sdk\inc\mimeole.h
#define OID_SECURITY_RG_CERT_ENCRYPT     TYPEDID(VT_VECTOR | VT_UI4, 0x0023)
#define OID_SECURITY_RG_CERT_BAG         TYPEDID(VT_VECTOR | VT_UI4, 0x0025)
#define OID_SECURITY_SEARCHSTORES        TYPEDID(VT_VECTOR | VT_UI4, 0x0027)
#define OID_SECURITY_RG_IASN             TYPEDID(VT_VECTOR | VT_UI4, 0x0028)
#define OID_SECURITY_ALG_HASH_RG         TYPEDID(VT_VECTOR | VT_VARIANT, 	0x0019)
#define OID_SECURITY_CERT_SIGNING_RG     TYPEDID(VT_VECTOR | VT_UI4,     	0x0021)
#define OID_SECURITY_SYMCAPS_RG          TYPEDID(VT_VECTOR | VT_VARIANT, 	0x0029)
#define OID_SECURITY_AUTHATTR_RG         TYPEDID(VT_VECTOR | VT_VARIANT, 	0x002A)
#define OID_SECURITY_UNAUTHATTR_RG       TYPEDID(VT_VECTOR | VT_VARIANT, 	0x002B)
#define OID_SECURITY_SIGNTIME_RG         TYPEDID(VT_VECTOR | VT_FILETIME,	0x002C)
#define OID_SECURITY_USER_VALIDITY_RG    TYPEDID(VT_VECTOR | VT_UI4,     	0x002D)
#define OID_SECURITY_RO_MSG_VALIDITY_RG  TYPEDID(VT_VECTOR | VT_UI4,     	0x002E) // read-only

// public\sdk\inc\mmsystem.h
#define MIXERCONTROL_CONTROLTYPE_MICROTIME      (MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MICROSECS | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_MILLITIME      (MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MILLISECS | MIXERCONTROL_CT_UNITS_UNSIGNED)

// public\sdk\inc\mq.h
#define MQSEC_RECEIVE_MESSAGE               (MQSEC_DELETE_MESSAGE | \
                                             MQSEC_PEEK_MESSAGE)
#define MQSEC_RECEIVE_JOURNAL_MESSAGE       (MQSEC_DELETE_JOURNAL_MESSAGE | \
                                             MQSEC_PEEK_MESSAGE)

// public\sdk\inc\msctf.h
#define TF_E_INVALIDPOINT    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0207)

// public\sdk\inc\nddesec.h
#define NDDE_SHARE_GENERIC_WRITE (NDDE_SHARE_INITIATE_STATIC |		\
			          NDDE_SHARE_INITIATE_LINK |		\
				  NDDE_SHARE_POKE |			\
				  DELETE)
#define NDDE_SHARE_GENERIC_EXECUTE (NDDE_SHARE_INITIATE_STATIC |	\
			            NDDE_SHARE_INITIATE_LINK |		\
				    NDDE_SHARE_EXECUTE)
#define NDDE_ITEM_GENERIC_READ	  (NDDE_ITEM_REQUEST | NDDE_ITEM_ADVISE)
#define NDDE_ITEM_GENERIC_ALL     (NDDE_ITEM_REQUEST |			\
				   NDDE_ITEM_ADVISE |			\
				   NDDE_ITEM_POKE |			\
				   DELETE |				\
				   READ_CONTROL |			\
				   WRITE_DAC |				\
				   WRITE_OWNER)
#define NDDE_GUI_READ_LINK	(NDDE_SHARE_GENERIC_READ |		\
				 NDDE_SHARE_INITIATE_LINK)
#define NDDE_GUI_CHANGE		(NDDE_SHARE_GENERIC_READ |		\
				 NDDE_SHARE_GENERIC_WRITE |		\
				 NDDE_SHARE_GENERIC_EXECUTE)

// public\sdk\inc\netmon.h
#define	NMERR_SETTIMER_FAILED	( 98 )

// public\sdk\inc\ntdsbmsg.h
#define hrRestoreMapExists               ((HRESULT)0xC7FF0008L)
#define hrBadCheckpointSignature         ((HRESULT)0xC8000214L)
#define hrCheckpointCorrupt              ((HRESULT)0xC8000215L)
#define hrConsistentTimeMismatch         ((HRESULT)0xC8000227L)

// public\sdk\inc\ntexapi.h
#define SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3) // winnt

// public\sdk\inc\ntlsa.h
#define SECRET_READ           (STANDARD_RIGHTS_READ             |\
                               SECRET_QUERY_VALUE)

// public\sdk\inc\ntmips.h
#define QUERY_SYSTEM_TIME(CurrentTime) \
    *((DOUBLE *)(CurrentTime)) = *((DOUBLE *)(&USER_SHARED_DATA->SystemTime))

// public\sdk\inc\ntmmapi.h
#define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY|\
                            SECTION_MAP_WRITE |      \
                            SECTION_MAP_READ |       \
                            SECTION_MAP_EXECUTE |    \
                            SECTION_EXTEND_SIZE)

// public\sdk\inc\ntseapi.h
#define VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

// public\sdk\inc\ntsecapi.h
#define POLICY_READ           (STANDARD_RIGHTS_READ             |\
                               POLICY_VIEW_AUDIT_INFORMATION    |\
                               POLICY_GET_PRIVATE_INFORMATION)
#define KERB_IS_MS_PRINCIPAL(_x_) (((_x_) <= KRB_NT_MS_PRINCIPAL) || ((_x_) >= KRB_NT_ENTERPRISE_PRINCIPAL))

// public\sdk\inc\oledberr.h
#define DB_SEC_E_PERMISSIONDENIED        ((HRESULT)0x80040E09L)
#define DB_E_BADSCALE                    ((HRESULT)0x80040E3BL)
#define DB_SEC_E_AUTH_FAILED             ((HRESULT)0x80040E4DL)
#define MD_E_BADCOORDINATE               ((HRESULT)0x80040E62L)
#define SEC_E_BADTRUSTEEID               ((HRESULT)0x80040E6AL)
#define SEC_E_NOTRUSTEEID                ((HRESULT)0x80040E6BL)
#define SEC_E_INVALIDOBJECT              ((HRESULT)0x80040E6DL)
#define SEC_E_NOOWNER                    ((HRESULT)0x80040E6EL)
#define SEC_E_INVALIDOWNER               ((HRESULT)0x80040E70L)
#define DB_E_TIMEOUT                     ((HRESULT)0x80040E97L)
#define DB_SEC_E_SAFEMODE_DENIED         ((HRESULT)0x80040E9BL)

// public\sdk\inc\parttype.h
#define XINT13_DESIRED(geom,endsect)                                                \
                                                                                    \
    (((endsect) / ((geom)->TracksPerCylinder * (geom)->SectorsPerTrack)) > 1023)

// public\sdk\inc\penwin.h
#define PMI_TIMEOUTSEL          10      // select (press&hold) timeout
#define RCP_MAPCHAR             0x0004  // fill in syg.lpsyc (ink) for training
#define FLTAbsTime(at1, at2)\
    ((at1).sec < (at2).sec || ((at1).sec == (at2).sec && (at1).ms < (at2).ms))
#define FLTEAbsTime(at1, at2)\
    ((at1).sec < (at2).sec || ((at1).sec == (at2).sec && (at1).ms <= (at2).ms))
#define FEQAbsTime(at1, at2)\
    ((at1).sec == (at2).sec && (at1).ms == (at2).ms)
#define FAbsTimeInInterval(at, lpi)\
    (FLTEAbsTime((lpi)->atBegin, at) && FLTEAbsTime(at, (lpi)->atEnd))
#define FIntervalInInterval(lpiT, lpiS)\
    (FLTEAbsTime((lpiS)->atBegin, (lpiT)->atBegin)\
    && FLTEAbsTime((lpiT)->atEnd, (lpiS)->atEnd))
#define FIntervalXInterval(lpiT, lpiS)\
    (!(FLTAbsTime((lpiT)->atEnd, (lpiS)->atBegin)\
    || FLTAbsTime((lpiS)->atEnd, (lpiT)->atBegin)))

// public\sdk\inc\pwin16.h
#define MAKEMPOINT(l)                   (*((MPOINT FAR *)&(l)))
#define MPOINT2POINT(mpt, pt)           (pt = *(POINT FAR *)&(mpt))
#define POINT2MPOINT(pt, mpt)           (mpt = *(MPOINT FAR *)&(pt))

// public\sdk\inc\pwin32.h
#define MAKEMPOINT(l)                   (*((MPOINT *)&(l)))

// public\sdk\inc\richedit.h
#define EM_SETIMEOPTIONS		(WM_USER + 106)
#define EM_GETIMEOPTIONS		(WM_USER + 107)
#define EM_GETIMECOMPMODE		(WM_USER + 122)
#define EM_SETIMEMODEBIAS		(WM_USER + 126)
#define EM_GETIMEMODEBIAS		(WM_USER + 127)
#define EM_GETIMECOMPTEXT		(WM_USER + 242)
#define EM_GETIMEPROPERTY		(WM_USER + 244)

// public\sdk\inc\rtcerr.h
#define RTC_E_SIP_TIMEOUT                ((HRESULT)0x80EE000CL)
#define RTC_E_SIP_SSL_NEGOTIATION_TIMEOUT ((HRESULT)0x80EE001DL)
#define RTC_E_PORT_MAPPING_UNAVAILABLE   ((HRESULT)0x80EE0044L)
#define RTC_E_PORT_MAPPING_FAILED        ((HRESULT)0x80EE0045L)
#define RTC_E_STATUS_CLIENT_REQUEST_TIMEOUT ((HRESULT)0x80EF0198L)
#define RTC_E_STATUS_SERVER_SERVER_TIMEOUT ((HRESULT)0x80EF01F8L)

// public\sdk\inc\schannel.h
#define SECPKG_ATTR_REMOTE_CRED          0x51   // (OBSOLETE) returns SecPkgContext_RemoteCredentialInfo

// public\sdk\inc\snmp.h
#define ASN_TIMETICKS               (ASN_APPLICATION | ASN_PRIMITIVE | 0x03)

// public\sdk\inc\sxs.h
#define SXS_FIND_CLR_SURROGATE_GET_ALL              (SXS_FIND_CLR_SURROGATE_GET_IDENTITY | SXS_FIND_CLR_SURROGATE_GET_RUNTIME_VERSION | SXS_FIND_CLR_SURROGATE_GET_TYPE_NAME)
#define SXS_FIND_CLR_CLASS_GET_ALL                  (SXS_FIND_CLR_CLASS_GET_PROGID | SXS_FIND_CLR_CLASS_GET_IDENTITY | SXS_FIND_CLR_CLASS_GET_TYPE_NAME | SXS_FIND_CLR_CLASS_GET_RUNTIME_VERSION)

// public\sdk\inc\tapi3err.h
#define TAPI_E_INVALTIMEOUT              ((HRESULT)0x8004001CL)
#define TAPI_E_TIMEOUT                   ((HRESULT)0x80040044L)

// public\sdk\inc\textstor.h
#define TS_E_INVALIDPOINT    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0207)

// public\sdk\inc\upnp.h
#define UPNP_E_DEVICE_TIMEOUT            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0217)

// public\sdk\inc\urlmki.h
#define INET_E_CONNECTION_TIMEOUT        _HRESULT_TYPEDEF_(0x800C000BL)
#define INET_E_SECURITY_PROBLEM          _HRESULT_TYPEDEF_(0x800C000EL)

// public\sdk\inc\urlmon.h
#define INET_E_CONNECTION_TIMEOUT        _HRESULT_TYPEDEF_(0x800C000BL)
#define INET_E_SECURITY_PROBLEM          _HRESULT_TYPEDEF_(0x800C000EL)

// public\sdk\inc\vfw.h
#define MCIWNDM_SETTIMERS	(WM_USER + 129)
#define MCIWNDM_SETACTIVETIMER	(WM_USER + 130)
#define MCIWNDM_SETINACTIVETIMER (WM_USER + 131)
#define MCIWNDM_GETACTIVETIMER	(WM_USER + 132)
#define MCIWNDM_GETINACTIVETIMER (WM_USER + 133)
#define MCIWNDM_SETTIMEFORMATA  (WM_USER + 119)
#define MCIWNDM_GETTIMEFORMATA  (WM_USER + 120)
#define MCIWNDM_SETTIMEFORMATW  (WM_USER + 219)
#define MCIWNDM_GETTIMEFORMATW  (WM_USER + 220)

// public\sdk\inc\vfwmsgs.h
#define VFW_E_RUNTIME_ERROR              ((HRESULT)0x8004020BL)
#define VFW_E_START_TIME_AFTER_END       ((HRESULT)0x80040228L)
#define VFW_E_TIMEOUT                    ((HRESULT)0x8004022EL)
#define VFW_E_TIME_ALREADY_PASSED        ((HRESULT)0x80040233L)
#define VFW_E_SAMPLE_TIME_NOT_SET        ((HRESULT)0x80040249L)
#define VFW_E_MEDIA_TIME_NOT_SET         ((HRESULT)0x80040251L)
#define VFW_E_NO_TIME_FORMAT_SET         ((HRESULT)0x80040252L)
#define VFW_E_NO_TIME_FORMAT             ((HRESULT)0x80040261L)
#define VFW_S_NO_STOP_TIME               ((HRESULT)0x00040270L)
#define VFW_E_TIME_EXPIRED               ((HRESULT)0x8004027FL)

// public\sdk\inc\wabdefs.h
#define MAPIMETHOD(method)              MAPIMETHOD_(HRESULT, method)
#define MAPI_DIAG_EXPANSION_FAILED                  MAPI_DIAG( 30 )

// public\sdk\inc\wdm.h
#define VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))
#define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY|\
                            SECTION_MAP_WRITE |      \
                            SECTION_MAP_READ |       \
                            SECTION_MAP_EXECUTE |    \
                            SECTION_EXTEND_SIZE)
#define SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#define IoIsErrorUserInduced( Status ) ((BOOLEAN)  \
    (((Status) == STATUS_DEVICE_NOT_READY) ||      \
     ((Status) == STATUS_IO_TIMEOUT) ||            \
     ((Status) == STATUS_MEDIA_WRITE_PROTECTED) || \
     ((Status) == STATUS_NO_MEDIA_IN_DEVICE) ||    \
     ((Status) == STATUS_VERIFY_REQUIRED) ||       \
     ((Status) == STATUS_UNRECOGNIZED_MEDIA) ||    \
     ((Status) == STATUS_WRONG_VOLUME)))

// public\sdk\inc\wincrypt.h
#define CALG_SSL3_MASTER        (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SSL3_MASTER)
#define CALG_SCHANNEL_MASTER_HASH   (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SCHANNEL_MASTER_HASH)
#define CALG_SCHANNEL_MAC_KEY   (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SCHANNEL_MAC_KEY)
#define CALG_SCHANNEL_ENC_KEY   (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SCHANNEL_ENC_KEY)
#define CALG_PCT1_MASTER        (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_PCT1_MASTER)
#define CALG_SSL2_MASTER        (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SSL2_MASTER)
#define CALG_TLS1_MASTER        (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_TLS1_MASTER)

// public\sdk\inc\windowsx.h
#define FORWARD_WM_WININICHANGE(hwnd, lpszSectionName, fn) \
    (void)(fn)((hwnd), WM_WININICHANGE, 0L, (LPARAM)(LPCTSTR)(lpszSectionName))
#define HANDLE_WM_TIMECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_TIMECHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_TIMECHANGE, 0L, 0L)
#define HANDLE_WM_TIMER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_TIMER(hwnd, id, fn) \
    (void)(fn)((hwnd), WM_TIMER, (WPARAM)(UINT)(id), 0L)

// public\sdk\inc\winerror.h
#define SEC_E_OK                         ((HRESULT)0x00000000L)
#define CO_E_INIT_SCM_FILE_MAPPING_EXISTS _HRESULT_TYPEDEF_(0x8000400FL)
#define CO_E_INIT_SCM_MAP_VIEW_OF_FILE   _HRESULT_TYPEDEF_(0x80004010L)
#define CO_E_SERVER_START_TIMEOUT        _HRESULT_TYPEDEF_(0x8000401EL)
#define CO_E_SERVER_INIT_TIMEOUT         _HRESULT_TYPEDEF_(0x8000402AL)
#define CO_E_NO_SECCTX_IN_ACTIVATE       _HRESULT_TYPEDEF_(0x8000402BL)
#define XACT_E_NOTIMEOUT                 _HRESULT_TYPEDEF_(0x8004D017L)
#define CONTEXT_E_SYNCH_TIMEOUT          _HRESULT_TYPEDEF_(0x8004E006L)
#define CO_E_ACTIVATIONFAILED_TIMEOUT    _HRESULT_TYPEDEF_(0x8004E024L)
#define SCHED_E_NO_SECURITY_SERVICES     _HRESULT_TYPEDEF_(0x80041312L)
#define STG_E_CSS_SCRAMBLED_SECTOR       _HRESULT_TYPEDEF_(0x80030309L)
#define RPC_S_WAITONTIMER                _HRESULT_TYPEDEF_(0x80010116L)
#define RPC_E_UNSECURE_CALL              _HRESULT_TYPEDEF_(0x80010118L)
#define RPC_E_TIMEOUT                    _HRESULT_TYPEDEF_(0x8001011FL)
#define CO_E_FAILEDTOGETSECCTX           _HRESULT_TYPEDEF_(0x80010124L)
#define SEC_E_INSUFFICIENT_MEMORY        _HRESULT_TYPEDEF_(0x80090300L)
#define SEC_E_INVALID_HANDLE             _HRESULT_TYPEDEF_(0x80090301L)
#define SEC_E_UNSUPPORTED_FUNCTION       _HRESULT_TYPEDEF_(0x80090302L)
#define SEC_E_TARGET_UNKNOWN             _HRESULT_TYPEDEF_(0x80090303L)
#define SEC_E_INTERNAL_ERROR             _HRESULT_TYPEDEF_(0x80090304L)
#define SEC_E_SECPKG_NOT_FOUND           _HRESULT_TYPEDEF_(0x80090305L)
#define SEC_E_NOT_OWNER                  _HRESULT_TYPEDEF_(0x80090306L)
#define SEC_E_CANNOT_INSTALL             _HRESULT_TYPEDEF_(0x80090307L)
#define SEC_E_INVALID_TOKEN              _HRESULT_TYPEDEF_(0x80090308L)
#define SEC_E_QOP_NOT_SUPPORTED          _HRESULT_TYPEDEF_(0x8009030AL)
#define SEC_E_NO_IMPERSONATION           _HRESULT_TYPEDEF_(0x8009030BL)
#define SEC_E_UNKNOWN_CREDENTIALS        _HRESULT_TYPEDEF_(0x8009030DL)
#define SEC_E_NO_CREDENTIALS             _HRESULT_TYPEDEF_(0x8009030EL)
#define SEC_E_MESSAGE_ALTERED            _HRESULT_TYPEDEF_(0x8009030FL)
#define SEC_E_OUT_OF_SEQUENCE            _HRESULT_TYPEDEF_(0x80090310L)
#define SEC_E_NO_AUTHENTICATING_AUTHORITY _HRESULT_TYPEDEF_(0x80090311L)
#define SEC_I_CONTINUE_NEEDED            _HRESULT_TYPEDEF_(0x00090312L)
#define SEC_I_COMPLETE_NEEDED            _HRESULT_TYPEDEF_(0x00090313L)
#define SEC_I_COMPLETE_AND_CONTINUE      _HRESULT_TYPEDEF_(0x00090314L)
#define SEC_E_BAD_PKGID                  _HRESULT_TYPEDEF_(0x80090316L)
#define SEC_E_CONTEXT_EXPIRED            _HRESULT_TYPEDEF_(0x80090317L)
#define SEC_I_CONTEXT_EXPIRED            _HRESULT_TYPEDEF_(0x00090317L)
#define SEC_E_INCOMPLETE_MESSAGE         _HRESULT_TYPEDEF_(0x80090318L)
#define SEC_E_INCOMPLETE_CREDENTIALS     _HRESULT_TYPEDEF_(0x80090320L)
#define SEC_I_INCOMPLETE_CREDENTIALS     _HRESULT_TYPEDEF_(0x00090320L)
#define SEC_I_RENEGOTIATE                _HRESULT_TYPEDEF_(0x00090321L)
#define SEC_E_WRONG_PRINCIPAL            _HRESULT_TYPEDEF_(0x80090322L)
#define SEC_I_NO_LSA_CONTEXT             _HRESULT_TYPEDEF_(0x00090323L)
#define SEC_E_TIME_SKEW                  _HRESULT_TYPEDEF_(0x80090324L)
#define SEC_E_UNTRUSTED_ROOT             _HRESULT_TYPEDEF_(0x80090325L)
#define SEC_E_ILLEGAL_MESSAGE            _HRESULT_TYPEDEF_(0x80090326L)
#define SEC_E_CERT_UNKNOWN               _HRESULT_TYPEDEF_(0x80090327L)
#define SEC_E_CERT_EXPIRED               _HRESULT_TYPEDEF_(0x80090328L)
#define SEC_E_ENCRYPT_FAILURE            _HRESULT_TYPEDEF_(0x80090329L)
#define SEC_E_DECRYPT_FAILURE            _HRESULT_TYPEDEF_(0x80090330L)
#define SEC_E_ALGORITHM_MISMATCH         _HRESULT_TYPEDEF_(0x80090331L)
#define SEC_E_SECURITY_QOS_FAILED        _HRESULT_TYPEDEF_(0x80090332L)
#define SEC_E_UNFINISHED_CONTEXT_DELETED _HRESULT_TYPEDEF_(0x80090333L)
#define SEC_E_NO_TGT_REPLY               _HRESULT_TYPEDEF_(0x80090334L)
#define SEC_E_NO_IP_ADDRESSES            _HRESULT_TYPEDEF_(0x80090335L)
#define SEC_E_WRONG_CREDENTIAL_HANDLE    _HRESULT_TYPEDEF_(0x80090336L)
#define SEC_E_CRYPTO_SYSTEM_INVALID      _HRESULT_TYPEDEF_(0x80090337L)
#define SEC_E_MAX_REFERRALS_EXCEEDED     _HRESULT_TYPEDEF_(0x80090338L)
#define SEC_E_MUST_BE_KDC                _HRESULT_TYPEDEF_(0x80090339L)
#define SEC_E_STRONG_CRYPTO_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x8009033AL)
#define SEC_E_TOO_MANY_PRINCIPALS        _HRESULT_TYPEDEF_(0x8009033BL)
#define SEC_E_NO_PA_DATA                 _HRESULT_TYPEDEF_(0x8009033CL)
#define SEC_E_PKINIT_NAME_MISMATCH       _HRESULT_TYPEDEF_(0x8009033DL)
#define SEC_E_SHUTDOWN_IN_PROGRESS       _HRESULT_TYPEDEF_(0x8009033FL)
#define SEC_E_KDC_INVALID_REQUEST        _HRESULT_TYPEDEF_(0x80090340L)
#define SEC_E_KDC_UNABLE_TO_REFER        _HRESULT_TYPEDEF_(0x80090341L)
#define SEC_E_KDC_UNKNOWN_ETYPE          _HRESULT_TYPEDEF_(0x80090342L)
#define SEC_E_UNSUPPORTED_PREAUTH        _HRESULT_TYPEDEF_(0x80090343L)
#define SEC_E_DELEGATION_REQUIRED        _HRESULT_TYPEDEF_(0x80090345L)
#define SEC_E_BAD_BINDINGS               _HRESULT_TYPEDEF_(0x80090346L)
#define SEC_E_MULTIPLE_ACCOUNTS          _HRESULT_TYPEDEF_(0x80090347L)
#define SEC_E_NO_KERB_KEY                _HRESULT_TYPEDEF_(0x80090348L)
#define CRYPT_E_SECURITY_SETTINGS        _HRESULT_TYPEDEF_(0x80092026L)
#define OSS_BAD_TIME                     _HRESULT_TYPEDEF_(0x8009300CL)
#define TRUST_E_TIME_STAMP               _HRESULT_TYPEDEF_(0x80096005L)
#define SPAPI_E_EXPECTED_SECTION_NAME    _HRESULT_TYPEDEF_(0x800F0000L)
#define SPAPI_E_BAD_SECTION_NAME_LINE    _HRESULT_TYPEDEF_(0x800F0001L)
#define SPAPI_E_SECTION_NOT_FOUND        _HRESULT_TYPEDEF_(0x800F0101L)
#define SPAPI_E_BAD_SERVICE_INSTALLSECT  _HRESULT_TYPEDEF_(0x800F0217L)
#define SPAPI_E_BAD_INTERFACE_INSTALLSECT _HRESULT_TYPEDEF_(0x800F021DL)
#define SCARD_E_TIMEOUT                  _HRESULT_TYPEDEF_(0x8010000AL)
#define SCARD_W_SECURITY_VIOLATION       _HRESULT_TYPEDEF_(0x8010006AL)
#define COMADMIN_E_SYSTEMAPP             _HRESULT_TYPEDEF_(0x80110433L)

// public\sdk\inc\wingdi.h
#define MAKEPOINTS(l)       (*((POINTS FAR *)&(l)))

// public\sdk\inc\winnt.h
#define VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))
#define SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY|\
                            SECTION_MAP_WRITE |      \
                            SECTION_MAP_READ |       \
                            SECTION_MAP_EXECUTE |    \
                            SECTION_EXTEND_SIZE)

// public\sdk\inc\winsnmp.h
#define SNMP_SYNTAX_TIMETICKS (ASN_APPLICATION | ASN_PRIMITIVE | 0x03)

// public\sdk\inc\winsock.h
#define timerisset(tvp)         ((tvp)->tv_sec || (tvp)->tv_usec)
#define timercmp(tvp, uvp, cmp) \
        ((tvp)->tv_sec cmp (uvp)->tv_sec || \
         (tvp)->tv_sec == (uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)

// public\sdk\inc\winsock2.h
#define timerisset(tvp)         ((tvp)->tv_sec || (tvp)->tv_usec)
#define timercmp(tvp, uvp, cmp) \
        ((tvp)->tv_sec cmp (uvp)->tv_sec || \
         (tvp)->tv_sec == (uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)

// public\sdk\inc\winuser.h
#define QS_ALLEVENTS       (QS_INPUT         | \
                            QS_POSTMESSAGE   | \
                            QS_TIMER         | \
                            QS_PAINT         | \
                            QS_HOTKEY)
#define QS_ALLINPUT        (QS_INPUT         | \
                            QS_POSTMESSAGE   | \
                            QS_TIMER         | \
                            QS_PAINT         | \
                            QS_HOTKEY        | \
                            QS_SENDMESSAGE)

// public\sdk\inc\wmium.h
#define WmiInsertTimestamp(WnodeHeader) \
    GetSystemTimeAsFileTime((FILETIME *)&((PWNODE_HEADER)WnodeHeader)->TimeStamp)

// public\sdk\inc\wtl10\atlddx.h
#define END_DDX_MAP() \
		return TRUE; \
	}

// public\sdk\inc\wtl10\atlframe.h
#define END_DLGRESIZE_MAP() \
			{ -1, 0 }, \
		}; \
		return theMap; \
	}

// published\sdk\inc\mapicode.h
#define	HR_FAILED(_hr) FAILED((SCODE)(_hr))

// published\sdk\inc\mapidbg.h
#define Assert(t)										IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,"Assertion Failure: " #t),0))
#define AssertSz(t,psz)									IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz),0))
#define AssertSz1(t,psz,a1)								IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1),0))
#define AssertSz2(t,psz,a1,a2)							IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2),0))
#define AssertSz3(t,psz,a1,a2,a3)						IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3),0))
#define AssertSz4(t,psz,a1,a2,a3,a4)					IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4),0))
#define AssertSz5(t,psz,a1,a2,a3,a4,a5)					IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5),0))
#define AssertSz6(t,psz,a1,a2,a3,a4,a5,a6)				IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6),0))
#define AssertSz7(t,psz,a1,a2,a3,a4,a5,a6,a7)			IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7),0))
#define AssertSz8(t,psz,a1,a2,a3,a4,a5,a6,a7,a8)		IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8),0))
#define AssertSz9(t,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)		IFTRAP(((t) ? 0 : DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9),0))
#define SideAssert(t)									((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,"Assertion Failure: " #t)),0)
#define SideAssertSz(t,psz)								((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz)),0)
#define SideAssertSz1(t,psz,a1)							((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1)),0)
#define SideAssertSz2(t,psz,a1,a2)						((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2)),0)
#define SideAssertSz3(t,psz,a1,a2,a3)					((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3)),0)
#define SideAssertSz4(t,psz,a1,a2,a3,a4)				((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4)),0)
#define SideAssertSz5(t,psz,a1,a2,a3,a4,a5)				((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5)),0)
#define SideAssertSz6(t,psz,a1,a2,a3,a4,a5,a6)			((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6)),0)
#define SideAssertSz7(t,psz,a1,a2,a3,a4,a5,a6,a7)		((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7)),0)
#define SideAssertSz8(t,psz,a1,a2,a3,a4,a5,a6,a7,a8)	((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8)),0)
#define SideAssertSz9(t,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)	((t) ? 0 : IFTRAP(DebugTrapFn(1,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)),0)
#define NFAssert(t)										IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,"Assertion Failure: " #t),0))
#define NFAssertSz(t,psz)								IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz),0))
#define NFAssertSz1(t,psz,a1)							IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1),0))
#define NFAssertSz2(t,psz,a1,a2)						IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2),0))
#define NFAssertSz3(t,psz,a1,a2,a3)						IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3),0))
#define NFAssertSz4(t,psz,a1,a2,a3,a4)					IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4),0))
#define NFAssertSz5(t,psz,a1,a2,a3,a4,a5)				IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5),0))
#define NFAssertSz6(t,psz,a1,a2,a3,a4,a5,a6)			IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6),0))
#define NFAssertSz7(t,psz,a1,a2,a3,a4,a5,a6,a7)			IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7),0))
#define NFAssertSz8(t,psz,a1,a2,a3,a4,a5,a6,a7,a8)		IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8),0))
#define NFAssertSz9(t,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)	IFTRAP(((t) ? 0 : DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9),0))
#define NFSideAssert(t)									((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,"Assertion Failure: " #t)),0)
#define NFSideAssertSz(t,psz)							((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz)),0)
#define NFSideAssertSz1(t,psz,a1)						((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1)),0)
#define NFSideAssertSz2(t,psz,a1,a2)					((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2)),0)
#define NFSideAssertSz3(t,psz,a1,a2,a3)					((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3)),0)
#define NFSideAssertSz4(t,psz,a1,a2,a3,a4)				((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4)),0)
#define NFSideAssertSz5(t,psz,a1,a2,a3,a4,a5)			((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5)),0)
#define NFSideAssertSz6(t,psz,a1,a2,a3,a4,a5,a6)		((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6)),0)
#define NFSideAssertSz7(t,psz,a1,a2,a3,a4,a5,a6,a7)		((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7)),0)
#define NFSideAssertSz8(t,psz,a1,a2,a3,a4,a5,a6,a7,a8)	((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8)),0)
#define NFSideAssertSz9(t,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)	((t) ? 0 : IFTRAP(DebugTrapFn(0,__FILE__,__LINE__,psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)),0)
#define DebugTraceResult(f,hr)							IFTRACE(((hr) ? DebugTraceFn(#f " returns 0x%08lX %s\n", GetScode(hr), SzDecodeScode(GetScode(hr))) : 0))
#define DebugTraceSc(f,sc)								IFTRACE(((sc) ? DebugTraceFn(#f " returns 0x%08lX %s\n", sc, SzDecodeScode(sc)) : 0))
#define DebugTraceArg(f,s)								IFTRACE(DebugTraceFn(#f ": bad parameter: " s "\n"))
#define TraceSz(psz)									IFTRACE(DebugTraceFn("~" psz))
#define TraceSz1(psz,a1)								IFTRACE(DebugTraceFn("~" psz,a1))
#define TraceSz2(psz,a1,a2)								IFTRACE(DebugTraceFn("~" psz,a1,a2))
#define TraceSz3(psz,a1,a2,a3)							IFTRACE(DebugTraceFn("~" psz,a1,a2,a3))
#define TraceSz4(psz,a1,a2,a3,a4)						IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4))
#define TraceSz5(psz,a1,a2,a3,a4,a5)					IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4,a5))
#define TraceSz6(psz,a1,a2,a3,a4,a5,a6)					IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4,a5,a6))
#define TraceSz7(psz,a1,a2,a3,a4,a5,a6,a7)				IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4,a5,a6,a7))
#define TraceSz8(psz,a1,a2,a3,a4,a5,a6,a7,a8)			IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4,a5,a6,a7,a8))
#define TraceSz9(psz,a1,a2,a3,a4,a5,a6,a7,a8,a9)		IFTRACE(DebugTraceFn("~" psz,a1,a2,a3,a4,a5,a6,a7,a8,a9))

// published\sdk\inc\mapival.h
#define ValidateParameters(eMethod, First)				\
		{	HRESULT   _hr_;								\
			_hr_ = __CPPValidateParameters(eMethod, (LPVOID) &First);	\
			if (HR_FAILED(_hr_)) return (_hr_);	}
#define CheckParameters(eMethod, First)				\
		AssertSz(HR_SUCCEEDED(__CPPValidateParameters(eMethod, &First)), "Parameter validation failed for method called by MAPI!")
#define FBadPropVal( lpPropVal)	(FAILED(ScCountProps( 1, lpPropVal, NULL)))
#define FBadRgPropVal( lpPropVal, cValues) \
		(FAILED(ScCountProps( cValues, lpPropVal, NULL)))
#define FBadRelease( lpObj)	FALSE
#define ValidateParms(x)	{ HRESULT _hr_ = HrValidateParameters x; if (HR_FAILED(_hr_)) return (_hr_); }
#define ValidateParms(x)	{ HRESULT _hr_ = HrValidateParametersV x; if (HR_FAILED(_hr_)) return (_hr_); }
#define ValidateParameters2( m, a1, a2 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters3( m, a1, a2, a3 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters4( m, a1, a2, a3, a4 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters5( m, a1, a2, a3, a4, a5 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters6( m, a1, a2, a3, a4, a5, a6 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters7( m, a1, a2, a3, a4, a5, a6, a7 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters8( m, a1, a2, a3, a4, a5, a6, a7, a8 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters9( m, a1, a2, a3, a4, a5, a6, a7, a8, a9 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters10( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters11( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters12( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters13( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters14( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters15( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define ValidateParameters16( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16 ) \
			ValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters2( m, a1, a2 )	\
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters3( m, a1, a2, a3 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters4( m, a1, a2, a3, a4 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters5( m, a1, a2, a3, a4, a5 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters6( m, a1, a2, a3, a4, a5, a6 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters7( m, a1, a2, a3, a4, a5, a6, a7 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters8( m, a1, a2, a3, a4, a5, a6, a7, a8 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters9( m, a1, a2, a3, a4, a5, a6, a7, a8, a9 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters10( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters11( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters12( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters13( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters14( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters15( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define UlValidateParameters16( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16 ) \
			UlValidateParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters2( m, a1, a2 )	\
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters3( m, a1, a2, a3)	\
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters4( m, a1, a2, a3, a4 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters5( m, a1, a2, a3, a4, a5 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters6( m, a1, a2, a3, a4, a5, a6 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters7( m, a1, a2, a3, a4, a5, a6, a7 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters8( m, a1, a2, a3, a4, a5, a6, a7, a8 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters9( m, a1, a2, a3, a4, a5, a6, a7, a8, a9 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters10( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters11( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters12( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters13( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters14( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters15( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define CheckParameters16( m, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16 ) \
			CheckParms( ( m, (LPVOID FAR *) &a2 ) )
#define Validate_IUnknown_Release( a1 ) \
			 ValidateParameters1( IUnknown_Release, a1 )
#define UlValidate_IUnknown_Release( a1 ) \
			 UlValidateParameters1( IUnknown_Release, a1 )
#define CheckParameters_IUnknown_Release( a1 ) \
			 CheckParameters1( IUnknown_Release, a1 )

// published\sdk\inc\mapiwin.h
#define ReleaseMutex(hObj)				((BOOL)1)

// published\sdk\inc\nddesec.h
#define NDDE_SHARE_GENERIC_WRITE (NDDE_SHARE_INITIATE_STATIC |		\
			          NDDE_SHARE_INITIATE_LINK |		\
				  NDDE_SHARE_POKE |			\
				  DELETE)
#define NDDE_SHARE_GENERIC_EXECUTE (NDDE_SHARE_INITIATE_STATIC |	\
			            NDDE_SHARE_INITIATE_LINK |		\
				    NDDE_SHARE_EXECUTE)
#define NDDE_ITEM_GENERIC_READ	  (NDDE_ITEM_REQUEST | NDDE_ITEM_ADVISE)
#define NDDE_ITEM_GENERIC_ALL     (NDDE_ITEM_REQUEST |			\
				   NDDE_ITEM_ADVISE |			\
				   NDDE_ITEM_POKE |			\
				   DELETE |				\
				   READ_CONTROL |			\
				   WRITE_DAC |				\
				   WRITE_OWNER)
#define NDDE_GUI_READ_LINK	(NDDE_SHARE_GENERIC_READ |		\
				 NDDE_SHARE_INITIATE_LINK)
#define NDDE_GUI_CHANGE		(NDDE_SHARE_GENERIC_READ |		\
				 NDDE_SHARE_GENERIC_WRITE |		\
				 NDDE_SHARE_GENERIC_EXECUTE)

// published\sdk\inc\parttype.h
#define XINT13_DESIRED(geom,endsect)                                                \
                                                                                    \
    (((endsect) / ((geom)->TracksPerCylinder * (geom)->SectorsPerTrack)) > 1023)

// published\sdk\inc\penwin.h
#define PMI_TIMEOUTSEL          10      // select (press&hold) timeout
#define RCP_MAPCHAR             0x0004  // fill in syg.lpsyc (ink) for training
#define FLTAbsTime(at1, at2)\
    ((at1).sec < (at2).sec || ((at1).sec == (at2).sec && (at1).ms < (at2).ms))
#define FLTEAbsTime(at1, at2)\
    ((at1).sec < (at2).sec || ((at1).sec == (at2).sec && (at1).ms <= (at2).ms))
#define FEQAbsTime(at1, at2)\
    ((at1).sec == (at2).sec && (at1).ms == (at2).ms)
#define FAbsTimeInInterval(at, lpi)\
    (FLTEAbsTime((lpi)->atBegin, at) && FLTEAbsTime(at, (lpi)->atEnd))
#define FIntervalInInterval(lpiT, lpiS)\
    (FLTEAbsTime((lpiS)->atBegin, (lpiT)->atBegin)\
    && FLTEAbsTime((lpiT)->atEnd, (lpiS)->atEnd))
#define FIntervalXInterval(lpiT, lpiS)\
    (!(FLTAbsTime((lpiT)->atEnd, (lpiS)->atBegin)\
    || FLTAbsTime((lpiS)->atEnd, (lpiT)->atBegin)))

// published\sdk\inc\pwin16.h
#define MAKEMPOINT(l)                   (*((MPOINT FAR *)&(l)))
#define MPOINT2POINT(mpt, pt)           (pt = *(POINT FAR *)&(mpt))
#define POINT2MPOINT(pt, mpt)           (mpt = *(MPOINT FAR *)&(pt))

// published\sdk\inc\pwin32.h
#define MAKEMPOINT(l)                   (*((MPOINT *)&(l)))

// published\sdk\inc\snmp.h
#define ASN_TIMETICKS               (ASN_APPLICATION | ASN_PRIMITIVE | 0x03)

// published\sdk\inc\vfw.h
#define MCIWNDM_SETTIMERS	(WM_USER + 129)
#define MCIWNDM_SETACTIVETIMER	(WM_USER + 130)
#define MCIWNDM_SETINACTIVETIMER (WM_USER + 131)
#define MCIWNDM_GETACTIVETIMER	(WM_USER + 132)
#define MCIWNDM_GETINACTIVETIMER (WM_USER + 133)
#define MCIWNDM_SETTIMEFORMATA  (WM_USER + 119)
#define MCIWNDM_GETTIMEFORMATA  (WM_USER + 120)
#define MCIWNDM_SETTIMEFORMATW  (WM_USER + 219)
#define MCIWNDM_GETTIMEFORMATW  (WM_USER + 220)

// published\sdk\inc\windowsx.h
#define FORWARD_WM_WININICHANGE(hwnd, lpszSectionName, fn) \
    (void)(fn)((hwnd), WM_WININICHANGE, 0L, (LPARAM)(LPCTSTR)(lpszSectionName))
#define HANDLE_WM_TIMECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_TIMECHANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_TIMECHANGE, 0L, 0L)
#define HANDLE_WM_TIMER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), 0L)
#define FORWARD_WM_TIMER(hwnd, id, fn) \
    (void)(fn)((hwnd), WM_TIMER, (WPARAM)(UINT)(id), 0L)

// published\sdk\inc\winsnmp.h
#define SNMP_SYNTAX_TIMETICKS (ASN_APPLICATION | ASN_PRIMITIVE | 0x03)

// published\sdk\inc\wmium.h
#define WmiInsertTimestamp(WnodeHeader) \
    GetSystemTimeAsFileTime((FILETIME *)&((PWNODE_HEADER)WnodeHeader)->TimeStamp)

// sdktools\apimon\apimon\apimonp.h
#define IsBreakpoint(I) (*(PUCHAR)(I) == BP_INSTR)
#define IsBreakpoint(I) \
    (*(PULONG)(I) == (CALLPAL_OP | CALLKD_FUNC)) || \
    (*(PULONG)(I) == (CALLPAL_OP |    BPT_FUNC)) || \
    (*(PULONG)(I) == (CALLPAL_OP |   KBPT_FUNC))

// sdktools\idlemon\idlemon.c
#define printtime(_x_) {                                        \
        ULONGLONG ms = (_x_)/10000;                              \
        ULONG hours, minutes, seconds;                           \
        hours = (ULONG)ms/(1000*60*60);                                 \
        if (hours) printf("%3d:",(ULONG)(ms/(1000*60*60)));                 \
        ms=ms%(1000*60*60);                                     \
        minutes = (ULONG)ms/(1000*60);                                 \
        if (minutes || hours) printf("%02d:",(ULONG)(ms/(1000*60)));                 \
        ms=ms%(1000*60);                                        \
        seconds = (ULONG)ms/1000;                                      \
        printf("%02d.",seconds);                      \
        ms=ms%1000;                                             \
        printf("%03d",(ULONG)ms);                       \
    }

// sdktools\perfmon\timeline.c
#define dwTLineClassStyle     (CS_HREDRAW | CS_VREDRAW)
#define iTLineWindowExtra     (sizeof (PTLINE))
#define dwTLineWindowStyle    (WS_CHILD | WS_VISIBLE)

// sdktools\perfmon\timeline.h
#define TL_INTERVAL           (WM_USER + 0x301)

// sdktools\procmon\procmon.c
#define printtime(_x_) {                                               \
        ULONGLONG ms = (_x_)/10000;                                    \
        ULONG hours, minutes, seconds;                                 \
        hours = (ULONG)ms/(1000*60*60);                                \
        if (hours) printf("%3d:",(ULONG)(ms/(1000*60*60)));            \
        ms=ms%(1000*60*60);                                            \
        minutes = (ULONG)ms/(1000*60);                                 \
        if (minutes || hours) printf("%02d:",(ULONG)(ms/(1000*60)));   \
        ms=ms%(1000*60);                                               \
        seconds = (ULONG)ms/1000;                                      \
        printf("%02d.",seconds);                                       \
        ms=ms%1000;                                                    \
        printf("%03d",(ULONG)ms);                                      \
    }

// sdktools\remote\srvutil.c
#define CMDSTRING(OutBuff,OutSize,InpBuff,Client,szTime,ForceShow) \
{                                                                  \
    char *pch;                                                     \
                                                                   \
    for (pch = InpBuff;                                            \
         *pch;                                                     \
         pch++) {                                                  \
                                                                   \
        if (ENDMARK == *pch ||                                     \
            BEGINMARK == *pch) {                                   \
                                                                   \
            *pch = '`';                                            \
        }                                                          \
    }                                                              \
                                                                   \
    OutSize =                                                      \
        sprintf(                                                   \
            (OutBuff),                                             \
            COMMANDFORMAT,                                         \
            BEGINMARK,                                             \
            (InpBuff),                                             \
            (Client)->Name,                                        \
            (szTime),                                              \
            (ForceShow) ? 0 : (Client)->dwID,                      \
            ENDMARK                                                \
            );                                                     \
}

// sdktools\windiff\windiff\view.c
#define ViewEnter()     EnterCriticalSection(&CSView);
#define ViewLeave()     LeaveCriticalSection(&CSView);

// sdktools\windiff\windiff\windiff.h
#define WDEnter()       EnterCriticalSection(&CSWindiff);
#define WDLeave()       LeaveCriticalSection(&CSWindiff);

// sdktools\wsremote\server.c
#define CMDSTRING(OutBuff,InpBuff,Client,szTime)  {                              \
                                                    _stprintf                      \
                                                    (                            \
                                                       &OutBuff[0],COMMANDFORMAT,\
                                                       BEGINMARK,InpBuff,        \
                                                       Client->Name,szTime,      \
                                                       ENDMARK                   \
                                                    );                           \
                                                 }                               \

// shell\browseui\emclient\uemapp.cpp
#define FoldCSIDL(csidl) \
    ((csidl) == CSIDL_COMMON_PROGRAMS ? CSIDL_PROGRAMS : (csidl))
#define UAXF_XSETTINGS  (UAXF_NOPURGE|UAXF_BACKUP|UAXF_NOENCRYPT)

// shell\browseui\schedule.cpp
#define ENTER_CRITICAL_SECTION(x)           EnterCriticalSection(&x);                        \
                                            dwThread##x = GetCurrentThreadId();
#define OBJECT_ENTER_CRITICAL_SECTION(o,x)  EnterCriticalSection(&o->x);                        \
                                            o->dwThread##x = GetCurrentThreadId();
#define ENTER_CRITICAL_SECTION(x)           EnterCriticalSection(&x);
#define OBJECT_ENTER_CRITICAL_SECTION(o,x)  EnterCriticalSection(&o->x);
#define LEAVE_CRITICAL_SECTION(x)           LeaveCriticalSection(&x);
#define OBJECT_LEAVE_CRITICAL_SECTION(o,x)  LeaveCriticalSection(&o->x);

// shell\comctl32\v5\animate.c
#define Enter(p)    EnterCriticalSection(&p->crit)
#define Leave(p)    LeaveCriticalSection(&p->crit)
#define Ani_UseThread(p) (!((p)->style & ACS_TIMER))

// shell\comctl32\v5\monthcal.c
        #define YearAffected(psec, ise)                             \
                (ise == SUBEDIT_ALL ||                              \
                 (ise >= 0 && psec->pse[ise].id == SE_YEARALT))

// shell\comctl32\v5\rebar.c
#define RBBUSECHEVRON(prb, prbb)    ((prbb->fStyle & RBBS_USECHEVRON) &&              \
                                    !((prbb)->fStyle & RBBS_FIXEDSIZE) &&          \
                                    ((UINT)(prbb)->cxIdeal > (prbb)->cxMinChild))

// shell\comctl32\v6\animate.c
#define Enter(p)    EnterCriticalSection(&p->crit)
#define Leave(p)    LeaveCriticalSection(&p->crit)

// shell\comctl32\v6\ctlspriv.h
#define ENTERCRITICAL do { if (g_fCriticalInitialized) EnterCriticalSection(&g_csDll); } while (0);
#define LEAVECRITICAL do { if (g_fCriticalInitialized) LeaveCriticalSection(&g_csDll); } while (0);

// shell\comctl32\v6\monthcal.c
        #define YearAffected(psec, ise)                             \
                (ise == SUBEDIT_ALL ||                              \
                 (ise >= 0 && psec->pse[ise].id == SE_YEARALT))

// shell\cpls\utc\clock.h
#define CLM_UPDATETIME       (WM_USER + 102)

// shell\cpls\utc\inettime.h
#define WMUSER_ADDINTERNETTAB (WM_USER + 10)

// shell\explorer\traynot.h
#define TNM_ICONDEMOTETIMER         (WM_USER + 61)
#define TNM_INFOTIPTIMER            (WM_USER + 62)

// shell\ext\brfcase\filesync\syncui\atoms.c
#define Atom_EnterCS(this)    EnterCriticalSection(&(this)->cs)
#define Atom_LeaveCS(this)    LeaveCriticalSection(&(this)->cs)

// shell\ext\brfcase\filesync\syncui\brfprv.h
#define UB_CHECKING     (UB_CHECKAVI | UB_NOPROGRESS | UB_TIMER)

// shell\ext\brfcase\filesync\syncui\cache.c
#define Cache_EnterCS(this)    EnterCriticalSection(&(this)->cs)
#define Cache_LeaveCS(this)    LeaveCriticalSection(&(this)->cs)

// shell\ext\brfcase\filesync\syncui\cbs.c
#define CBS_EnterCS()    EnterCriticalSection(&g_cacheCBS.cs)
#define CBS_LeaveCS()    LeaveCriticalSection(&g_cacheCBS.cs)

// shell\ext\brfcase\filesync\syncui\cpath.c
#define CPATH_EnterCS()    EnterCriticalSection(&g_cacheCPATH.cs)
#define CPATH_LeaveCS()    LeaveCriticalSection(&g_cacheCPATH.cs)

// shell\ext\brfcase\filesync\syncui\crl.c
#define CRL_EnterCS()    EnterCriticalSection(&g_cacheCRL.cs)
#define CRL_LeaveCS()    LeaveCriticalSection(&g_cacheCRL.cs)

// shell\ext\cscui\cscst.h
#define PWM_RESET_REMINDERTIMER   (WM_USER + 403)

// shell\ext\docprop\propvar.h
#define ISUDTYPE(vt)        \
        ( vt == VT_LPSTR    \
          ||                \
          vt == VT_LPWSTR   \
          ||                \
          vt == VT_I4       \
          ||                \
          vt == VT_R8       \
          ||                \
          vt == VT_FILETIME \
          ||                \
          vt == VT_BOOL )

// shell\ext\dsui\dsuiext\cache.h
#define CLASSCACHE_SIMPLEAUTHENTICATE   0x80000000  // = 1 => perform simple authentication (eg ~ADS_SECURE_AUTHENTICATION)

// shell\ext\ftp\ftpcm.cpp
#define FILEATTRIB_DIRSOFTLINK (FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_REPARSE_POINT)

// shell\ext\ftp\ftppidl.cpp
#define IDTYPE_FRAGMENT          (0x00000020 | IDTYPE_ISVALID)    // File Fragment (i.e. foobar.htm#SECTION_3)

// shell\ext\ftp\ftppidl.h
#define FILEATTRIB_DIRSOFTLINK (FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_REPARSE_POINT)
#define FtpPidl_IsSoftLink(pidl)        (FILE_ATTRIBUTE_REPARSE_POINT & FtpPidl_GetAttributes(pidl))

// shell\ext\inetfind\fnd.h
#define Secondary_Vtbl(C, I) &c_##I##_##C##VI.vtbl

// shell\ext\keyremap\map.h
#define PUN(T, v) OBJAT(T, &(v))	/* General-purpose type-punning */
#define fLimpFF(f1, f2) (!(f1) || (f2))
#define Primary_Vtbl(C) &c_##C##VI.vtbl
#define Secondary_Vtbl(C, I) &c_##I##_##C##VI.vtbl
#define Common_AddRef(punk) \
		((IUnknown *)(punk))->lpVtbl->AddRef((IUnknown *)(punk))
#define Common_Release(punk) \
		((IUnknown *)(punk))->lpVtbl->Release((IUnknown *)(punk))

// shell\ext\ratings\npstub\npstub.cpp
#define ENTERCRITICAL EnterCriticalSection(&::critsec);
#define LEAVECRITICAL LeaveCriticalSection(&::critsec);

// shell\inc\ccstock.h
#define FILETIMEtoInt64(ft) _FILETIMEtoInt64(&(ft))
#define ENTERCRITICAL Dll_EnterCriticalSection(&g_csDll)
#define LEAVECRITICAL Dll_LeaveCriticalSection(&g_csDll)
#define ENTERCRITICAL EnterCriticalSection(&g_csDll)
#define LEAVECRITICAL LeaveCriticalSection(&g_csDll)

// shell\inc\port32.h
#define MAKEPOINTS(l)     (*((POINTS FAR*)&(l)))

// shell\inc\trayp.h
#define TM_KILLTIMER                (WM_USER + 0x160)
#define TM_SETTIMER                 (WM_USER + 0x162)

// shell\inc\uemapp.h
#define XMB_ICONERROR   (MB_ICONERROR|MB_ICONSTOP|MB_ICONEXCLAMATION|MB_ICONHAND)

// shell\osshell\accesory\netclip\netclip\server.h
#define IMPLEMENT_NETCLIPCREATE(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	AFX_DATADEF CNetClipObjectFactory class_name::factory(class_name::guid, \
		RUNTIME_CLASS(class_name), FALSE, _T(external_name)); \
	const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }; \

// shell\osshell\accesory\terminal\fsemacro.h
#define MAKE_MOUSE_POINT(l)                     (*((POINTS FAR *)&(l)))

// shell\osshell\control\midi\mapcopy.c
#define SLASH(c)            ((c) == '/' || (c) == '\\')

// shell\osshell\control\scrnsave\museum\util.h
#define ENTERCRITICAL Dll_EnterCriticalSection(&g_csDll)
#define LEAVECRITICAL Dll_LeaveCriticalSection(&g_csDll)
#define ENTERCRITICAL EnterCriticalSection(&g_csDll)
#define LEAVECRITICAL LeaveCriticalSection(&g_csDll)

// shell\osshell\control\t1instal\charstr.c
#define AddPoint(ps, px, py) {ps->pts[ps->numpts].x = px;\
                              ps->pts[ps->numpts].y = py;\
                              ps->numpts++;}

// shell\osshell\fontfldr\fontext\src\fontman.cpp
#define ECS    EnterCriticalSection( &m_cs )
#define LCS    LeaveCriticalSection( &m_cs )

// shell\osshell\fontfldr\fontext\t1instal\charstr.c
#define AddPoint(ps, px, py) {ps->pts[ps->numpts].x = px;\
                              ps->pts[ps->numpts].y = py;\
                              ps->numpts++;}

// shell\osshell\fontfldr\ole2map\pan1ptbl.c
#define M_EOL(ch)( ((ch ) == '\r') ||( (ch ) == '\n'))

// shell\osshell\security\aclui\ace.h
#define IsAuditAlarmACE(type) ( ((type) == SYSTEM_AUDIT_ACE_TYPE)        || \
                                ((type) == SYSTEM_AUDIT_OBJECT_ACE_TYPE) || \
                                ((type) == SYSTEM_ALARM_ACE_TYPE)        || \
                                ((type) == SYSTEM_ALARM_OBJECT_ACE_TYPE) )

// shell\osshell\security\aclui\chklist.h
#define CLST_CHECKDISABLED  (CLST_CHECKED | CLST_DISABLED)
#define CLM_SETCOLUMNWIDTH  (WM_USER + 1)   // lParam = width (dlg units) of a check column (default=32)
#define CLM_SETSTATE        (WM_USER + 4)   // wParam = row/column, lParam = state
#define CLM_SETITEMDATA     (WM_USER + 6)   // wParam = row, lParam = item data
#define CLM_RESETCONTENT    (WM_USER + 8)   // no parameters
#define CLM_SETTOPINDEX     (WM_USER + 11)  // wParam = index of new top row
#define CLM_ENSUREVISIBLE   (WM_USER + 12)  // wParam = index of item to make fully visible

// shell\osshell\security\aclui\misc.h
#define IsNullGUID(p)   (!(p) || IsSameGUID((p), &GUID_NULL))

// shell\osshell\security\rshx32\ntfssi.cpp
#define FILE_GENERIC_READ_      (FILE_GENERIC_READ    & ~SYNCHRONIZE)
#define FILE_GENERIC_WRITE_     (FILE_GENERIC_WRITE   & ~(SYNCHRONIZE | READ_CONTROL))
#define FILE_GENERIC_EXECUTE_   (FILE_GENERIC_EXECUTE & ~SYNCHRONIZE)
#define FILE_GENERIC_ALL_       (FILE_ALL_ACCESS      & ~SYNCHRONIZE)
#define FILE_GENERAL_PUBLISH    (FILE_GENERIC_READ_  | FILE_GENERIC_WRITE_ | FILE_GENERIC_EXECUTE_)
#define FILE_GENERAL_DEPOSIT    (FILE_GENERIC_WRITE_ | FILE_GENERIC_EXECUTE_)
#define FILE_GENERAL_READ_EX    (FILE_GENERIC_READ_  | FILE_GENERIC_EXECUTE_)

// shell\osshell\security\rshx32\printsi.cpp
#define PRINTER_ALL_AUDIT           (PRINTER_ALL_ACCESS | ACCESS_SYSTEM_SECURITY)
#define JOB_ALL_AUDIT               (JOB_ALL_ACCESS | ACCESS_SYSTEM_SECURITY)
#define PRINTER_JOB_ALL_AUDIT       (PRINTER_ALL_ACCESS | JOB_ALL_ACCESS | ACCESS_SYSTEM_SECURITY)

// shell\osshell\security\rshx32\rshx32.h
#define ALL_SECURITY_ACCESS     (READ_CONTROL | WRITE_DAC | WRITE_OWNER | ACCESS_SYSTEM_SECURITY)

// shell\published\inc\systrayp.h
#define STWM_NOTIFYSTICKYKEYS           (WM_USER + 204)

// shell\shdocvw\hist\local.h
#define VALID_IDSIGN(usSign) ((usSign) == IDIPIDL_SIGN || (usSign) == IDTPIDL_SIGN || (usSign) == IDDPIDL_SIGN)

// shell\shdocvw\iformsp.h
#define FILETIME_TO_INT(ft) (ft.dwLowDateTime | ft.dwHighDateTime)

// shell\shdocvw\impexp.cpp
#define FILETIME_TO_UNIXTIME(ft) (UINT)((*(LONGLONG*)&ft-116444736000000000)/10000000)

// shell\shell32\copy.h
#define ISREPARSEFINDDATA(finddata) ((finddata).dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT)

// shell\shell32\obex.h
#define	OBEX_HEADER_TIME_ISO	( 0x4 | OBEX_HEADER_STREAM )

// shell\shell32\prop.h
#define CompareSCIDFMTIDPID(fmtid, pid, scid)   ((pid == (scid).pid) && IsEqualIID(fmtid, (scid).fmtid))

// shell\shell32\treewalk.cpp
#define IS_FILE_REPARSE_POINT(pwfd) ((pwfd)->dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT)

// shell\shell32\unicpp\sendto.cpp
#define REGVAL_SESSION_SHELLNEW_TIMESTAMP TEXT("~reserved~")

// shell\shell32\unicpp\startmnu.cpp
#define ENTERCRITICAL_DARWINADS EnterCriticalSection(&g_csDarwinAds)
#define LEAVECRITICAL_DARWINADS LeaveCriticalSection(&g_csDarwinAds)

// shell\shlwapi\assocapi.cpp
#define ASSOCF_INIT_ALL      (ASSOCF_INIT_BYEXENAME | ASSOCF_INIT_DEFAULTTOFOLDER | ASSOCF_INIT_DEFAULTTOSTAR | ASSOCF_INIT_NOREMAPCLSID)

// termsrv\cdmodem\inc\cdmodem.h
#define STACK_ENDPOINT_SIZE(_sz) ( \
    (_sz) == 0 ? 0 : (_sz) - sizeof(CDMODEM_ENDPOINT) \
    )

// termsrv\cdmodem\inc\rasfile.h
#define RFL_ANYHEADER		(RFL_SECTION | RFL_GROUP)

// termsrv\inc\adcgmcro.h
#define IN_TIME_RANGE(BEGIN, END, TIME)                                     \
    (((BEGIN) < (END)) ?                                                    \
    (((TIME) >= (BEGIN)) && ((TIME) <= (END))) :                            \
    (((TIME) >= (BEGIN)) || ((TIME) <= (END))))

// termsrv\inc\at120ex.h
#define RNS_SEC_NONDATA_PKT (RNS_SEC_EXCHANGE_PKT |                         \
                             RNS_SEC_INFO_PKT     |                         \
                             RNS_SEC_LICENSE_PKT  |                         \
                             RDP_SEC_REDIRECTION_PKT |                      \
                             RDP_SEC_REDIRECTION_PKT2 |                     \
                             RDP_SEC_REDIRECTION_PKT3)

// termsrv\regapi\usrprop.c
#define MAPHEXTODIGIT(x) ( x >= '0' && x <= '9' ? (x-'0') :        \
                           x >= 'A' && x <= 'F' ? (x-'A'+10) :     \
                           x >= 'a' && x <= 'f' ? (x-'a'+10) : 0 )

// termsrv\remdsk\rds\as\h\dcg.h
#define IN_TIME_RANGE(BEGIN, END, TIME)                                     \
    (((BEGIN) < (END)) ?                                                    \
    (((TIME) >= (BEGIN)) && ((TIME) <= (END))) :                            \
    (((TIME) >= (BEGIN)) || ((TIME) <= (END))))

// termsrv\remdsk\rds\dev\inc16\mmsystem.h
#define MIXERCONTROL_CONTROLTYPE_MICROTIME      (MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MICROSECS | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_MILLITIME      (MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MILLISECS | MIXERCONTROL_CT_UNITS_UNSIGNED)

// termsrv\remdsk\rds\dev\inc16\windows.h
#define MAKEPOINT(l)     (*((POINT FAR*)&(l)))
#define LB_ITEMFROMPOINT        (WM_USER+42)    // ;Internal 4.0

// termsrv\remdsk\server\sessmgr\mktime.cpp
#define IsLeapYear(YEARS) (                        \
    (((YEARS) % 400 == 0) ||                       \
     ((YEARS) % 100 != 0) && ((YEARS) % 4 == 0)) ? \
        TRUE                                       \
    :                                              \
        FALSE                                      \
    )
#define MaxDaysInMonth(YEAR,MONTH) (                                      \
    IsLeapYear(YEAR) ?                                                    \
        LeapYearDaysPrecedingMonth[(MONTH) + 1] -                         \
                                    LeapYearDaysPrecedingMonth[(MONTH)]   \
    :                                                                     \
        NormalYearDaysPrecedingMonth[(MONTH) + 1] -                       \
                                    NormalYearDaysPrecedingMonth[(MONTH)] \
    )

// tools\x86\perl\lib\core\cc_runtime.h
#define PP_LIST(g) do {			\
	dMARK;				\
	if (g != G_ARRAY) {		\
	    if (++MARK <= SP)		\
		*MARK = *SP;		\
	    else			\
		*MARK = &PL_sv_undef;	\
	    SP = MARK;			\
	}				\
   } while (0)
#define MAYBE_TAINT_SASSIGN_SRC(sv) \
    if (PL_tainting && PL_tainted && (!SvGMAGICAL(left) || !SvSMAGICAL(left) || \
                                !((mg=mg_find(left, 't')) && mg->mg_len & 1)))\
        TAINT_NOT

// tools\x86\perl\lib\core\iperlsys.h
#define PerlLIO_utime(file, time)					\
	PL_piLIO->Utime((file), (time), ErrorNo())

// tools\x86\perl\lib\core\op.h
#define PMf_COMPILETIME	(PMf_MULTILINE|PMf_SINGLELINE|PMf_LOCALE|PMf_FOLD|PMf_EXTENDED)

// windows\advcore\ctf\inc\ccstock.h
#define ENTERCRITICAL Dll_EnterCriticalSection(&g_csDll)
#define LEAVECRITICAL Dll_LeaveCriticalSection(&g_csDll)
#define ENTERCRITICAL EnterCriticalSection(&g_csDll)
#define LEAVECRITICAL LeaveCriticalSection(&g_csDll)

// windows\advcore\gdiplus\engine\entry\metaplay.cpp
#define SCALEWORLDTRANSFORMEPR_MINSIZE    (sizeof(REAL) + sizeof(REAL))
#define DRAWIMAGEPOINTSEPR_MINSIZE    (sizeof(INT32) + sizeof(GpRectF) + sizeof(UINT32))

// windows\advcore\gdiplus\engine\fondrv\tt\scaler\fontmath.c
#define ISNOTPOWEROF2(n)        ((n) & ((n)-1))
  #define mth_Max45Trick(x,y)     (x == y || x == -y)

// windows\advcore\gdiplus\engine\fondrv\tt\scaler\fscdefs.h
	#define ProjVectInX(localGS)	((localGS).proj.x == ONEVECTOR && (localGS).proj.y == 0)
	#define	ProjVectInY(localGS)	((localGS).proj.y == ONEVECTOR && (localGS).proj.x == 0)

// windows\advcore\gdiplus\engine\fondrv\tt\scaler\fsglue.c
#define NotSameKnot(a,b) ((a).x != (b).x || (a).y != (b).y)

// windows\advcore\gdiplus\engine\fondrv\tt\scaler\interp.c
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

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\cvt.h
#define IS_GRAY(p) ((p)->flFontType & FO_GRAYSCALE)

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\fd_query.c
#define CJ_TT_SCAN(cx,p) \
    (4*((((((p)->flFontType & FO_GRAYSCALE)?(8):(1))*(cx))+31)/32))

// windows\advcore\gdiplus\engine\runtime\mem.cpp
#define GPMEM_OVERHEAD (GPMEM_GS + GPMEM_GE + sizeof(AllocTrackHeader))

// windows\advcore\gdiplus\engine\runtime\real.hpp
#define RemainderI(a, b)\
    ((a) >= 0 ? (a) % (b) : \
    (b) - 1 - ((-(a) - 1) % (b)))
    #define FPU_GET_STATE()                 \
        UINT32 cwSave = this->cwSave;       \
        UINT32 cwTemp = this->cwTemp;
    #define FPU_SAVE_STATE()                \
        this->cwSave = cwSave;              \
        this->cwTemp = cwTemp;

// windows\advcore\gdiplus\engine\runtime\standalone\mem.cpp
#define GPMEM_OVERHEAD (GPMEM_GS + GPMEM_GE + sizeof(AllocTrackHeader))

// windows\advcore\rcml\xmllib\xml\tokenizer\parser\xmlparser.cxx
#define CRITICALSECTIONLOCK CSLock lock(&_cs);

// windows\appcompat\shims\inc\heap.h
    #define hpInitializeCriticalSection(hheap)              \
         {                                        \
            hheap->hi_pcritsec = &(hheap->hi_critsec);  \
            InitializeCriticalSection(hheap->hi_pcritsec);               \
         }

// windows\appcompat\shims\inc\secutils.h
#define ComputeDeniedAccesses(GrantedAccess, DesiredAccess) \
    ((~(GrantedAccess)) & (DesiredAccess))

// windows\appcompat\shims\inc\shimstack.h
#define OLD_STACK()                                                           \
    __asm { mov esp,dwTempESP                   }                             \
    LeaveCriticalSection(&g_csStack);

// windows\appcompat\shims\layer\emulateheap_heap.h
    #define hpInitializeCriticalSection(hheap) \
        hheap->hi_pcritsec = &(hheap->hi_critsec); \
        mmInitMutex(hheap->hi_pcritsec)
    #define hpInitializeCriticalSection(hheap)              \
        {                                        \
            hheap->hi_pcritsec = &(hheap->hi_critsec);  \
            InitCrst(hheap->hi_pcritsec);               \
        }

// windows\core\ntcon\client\condll.h
#define LockDll() RtlEnterCriticalSection(&DllLock)
#define UnlockDll() RtlLeaveCriticalSection(&DllLock)

// windows\core\ntcon\conime\conime.c
#define LockConsoleTable()   RtlEnterCriticalSection(&ConsoleTableLock)
#define UnlockConsoleTable() RtlLeaveCriticalSection(&ConsoleTableLock)

// windows\core\ntcon\server\consrv.h
#define LockConsoleHandleTable()   RtlEnterCriticalSection(&ConsoleHandleLock)
#define UnlockConsoleHandleTable() RtlLeaveCriticalSection(&ConsoleHandleLock)
#define LockConsole(Con)           RtlEnterCriticalSection(&(Con)->ConsoleLock)

// windows\core\ntcon\server\output.c
#define LockScrollBuffer() RtlEnterCriticalSection(&ScrollBufferLock)
#define UnlockScrollBuffer() RtlLeaveCriticalSection(&ScrollBufferLock)

// windows\core\ntgdi\client\gdiicm.h
#define IcmMarkInUseIcmInfo(pIcmInfo,bInUse)           \
        ENTERCRITICALSECTION(&semListIcmInfo);         \
        if ((bInUse))                                  \
            (pIcmInfo)->flInfo |= ICM_UNDER_CHANGING;  \
        else                                           \
            (pIcmInfo)->flInfo &= ~ICM_UNDER_CHANGING; \
        LEAVECRITICALSECTION(&semListIcmInfo);

// windows\core\ntgdi\client\mfrec.hxx
#define SIZEOF_MRBP(cptl)  (sizeof(MRBP)-sizeof(POINTL)+(cptl)*sizeof(POINTL))
#define SIZEOF_MRBP16(cpts)     \
        (sizeof(MRBP16)-sizeof(POINTS)+(cpts)*sizeof(POINTS))

// windows\core\ntgdi\fondrv\tt\scaler\fontmath.c
#define ISNOTPOWEROF2(n)        ((n) & ((n)-1))
  #define mth_Max45Trick(x,y)     (x == y || x == -y)

// windows\core\ntgdi\fondrv\tt\scaler\fscdefs.h
	#define ProjVectInX(localGS)	((localGS).proj.x == ONEVECTOR && (localGS).proj.y == 0)
	#define	ProjVectInY(localGS)	((localGS).proj.y == ONEVECTOR && (localGS).proj.x == 0)

// windows\core\ntgdi\fondrv\tt\scaler\fsglue.c
#define NotSameKnot(a,b) ((a).x != (b).x || (a).y != (b).y)

// windows\core\ntgdi\fondrv\tt\scaler\interp.c
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

// windows\core\ntgdi\gre\engine.h
#define GreEnterMonitoredSection(ppdev, n)                                      \
{                                                                               \
    if ((ppdev)->pWatchdogData)                                                 \
    {                                                                           \
        WdEnterMonitoredSection((ppdev)->pWatchdogData[n].pWatchdog);           \
    }                                                                           \
}
#define GreExitMonitoredSection(ppdev, n)                                       \
{                                                                               \
    if ((ppdev)->pWatchdogData)                                                 \
    {                                                                           \
        WdExitMonitoredSection((ppdev)->pWatchdogData[n].pWatchdog);            \
    }                                                                           \
}

// windows\core\ntgdi\gre\fontmap.hxx
#define FF_SET    (FF_DONTCARE | FF_ROMAN | FF_SWISS | FF_MODERN | FF_SCRIPT | FF_DECORATIVE)

// windows\core\ntgdi\gre\umpdeng.cxx
#define MAP_UM_BRUSHOBJ(pUMObjs, pbo, pboTemp) \
        { \
            BRUSHOBJ   *tempVar; \
            tempVar = (pUMObjs)->GetDDIOBJ(pbo); \
            pbo = tempVar ? tempVar : CaptureAndFakeBRUSHOBJ(pbo, pboTemp); \
        }

// windows\core\ntgdi\halftone\ht\htalias.h
#define AAHF_DO_CLR_MAPPING     (AAHF_DO_SRC_CLR_MAPPING |                  \
                                 AAHF_DO_DST_CLR_MAPPING)

// windows\core\ntgdi\halftone\ht\htmapclr.c
#define fXYZFromXYZ(f,n,w)  (f) = ((((f)=NORM_XYZ((n),(w))) >= FD6_p008856) ? \
                                    (CubeRoot((f))) :                         \
                                    (MulFD6((f), FD6_7p787) + FD6_16Div116))
#define XYZFromfXYZ(n,f,w)  (n)=((f)>(FD6)206893) ?                          \
                                (Cube((f))) :                                \
                                (DivFD6((f) - FD6_16Div116, FD6_7p787));                   \
                            if ((w)!=FD6_1) { (n)=MulFD6((n),(w)); }

// windows\core\ntgdi\halftone\ht\htmapclr.h
#define CLIP_TO_NORMALIZED_BW(x)    if ((FD6)(x) < FD6_0) (x) = FD6_0;  \
                                    if ((FD6)(x) > FD6_1) (x) = FD6_1

// windows\core\ntuser\client\ddemlcli.h
#define EnterDDECrit       RtlEnterCriticalSection(&gcsDDEML);
#define LeaveDDECrit       RtlLeaveCriticalSection(&gcsDDEML);

// windows\core\ntuser\kdexts\userexts.c
#define DUMPTIME(time)     if (tryMoveExpValue(&Time, VAR(g ## time))) {     \
                               Print("g%s = %lx\n", #time, Time);            \
                           }
#define DUMPTIME(time)     moveExpValue(&Time, VAR(g ## time));             \
                           Print("g%s = %lx\n", #time, Time);

// windows\core\ntuser\kernel\timers.c
#define SYSRIT_TIMER  (TMRF_SYSTEM | TMRF_RIT)

// windows\core\ntuser\kernel\userk.h
#define ProbeAndReadPoint(Address)                         \
    (((Address) >= (POINT * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile POINT * const)MM_USER_PROBE_ADDRESS) : (*(volatile POINT *)(Address)))
#define ProbeForWritePoint(Address) {                                        \
    if ((Address) >= (POINT * const)MM_USER_PROBE_ADDRESS) {                 \
        *(volatile ULONG * const)MM_USER_PROBE_ADDRESS = 0;                  \
    }                                                                        \
                                                                             \
    *(volatile POINT *)(Address) = *(volatile POINT *)(Address);             \
}
#define ProbeForWritePoint5(Address) {                                     \
    if ((Address) >= (POINT5 * const)MM_USER_PROBE_ADDRESS) {              \
        *(volatile ULONG * const)MM_USER_PROBE_ADDRESS = 0;                         \
    }                                                                               \
                                                                                    \
    *(volatile POINT5 *)(Address) = *(volatile POINT5 *)(Address);\
}
#define PREVPOINT(i)    \
    ((i == 0) ? (MAX_MOUSEPOINTS - 1) : ((i - 1) % MAX_MOUSEPOINTS))
#define LINP_POWERTIMEOUTS  (LINP_LOWPOWER | LINP_POWEROFF)
#define LINP_INPUTTIMEOUTS  (LINP_SCREENSAVER | LINP_LOWPOWER | LINP_POWEROFF)

// windows\core\ntuser\kernel\visrgn.c
#define CheckIntersectRect(prc1, prc2)        \
    (   prc1->left < prc2->right              \
     && prc2->left < prc1->right              \
     && prc1->top < prc2->bottom              \
     && prc2->top < prc1->bottom)

// windows\core\ntuser\server\usersrv.h
#define EnterCrit()     RtlEnterCriticalSection(&gcsUserSrv)
#define LeaveCrit()     RtlLeaveCriticalSection(&gcsUserSrv)

// windows\core\rtl\heap.c
    #define EnterHeapCrit()         RtlEnterCriticalSection(&pheap->critSec)
    #define LeaveHeapCrit()         RtlLeaveCriticalSection(&pheap->critSec)
    #define EnterGlobalHeapCrit()   RtlEnterCriticalSection(&gheapCritSec)
    #define LeaveGlobalHeapCrit()   RtlLeaveCriticalSection(&gheapCritSec)

// windows\core\termspl\kmspool.c
#define ENTER_WAIT_LIST() EnterCriticalSection(&ThreadCriticalSection)
#define EXIT_WAIT_LIST()  LeaveCriticalSection(&ThreadCriticalSection)

// windows\core\w32inc\immuser.h
#define InitImcCrit(pClientImc)     RtlInitializeCriticalSection(&pClientImc->cs)
#define EnterImcCrit(pClientImc)    RtlEnterCriticalSection(&pClientImc->cs)
#define LeaveImcCrit(pClientImc)    RtlLeaveCriticalSection(&pClientImc->cs)

// windows\feime\chs\ntime\imedefs.h
#define ISC_SETCONTEXT_UI       (ISC_SHOWUIALL|ISC_SHOW_SOFTKBD)

// windows\feime\ddk\inc\indicml.h
#define INDICM_SETIMEICON                 (WM_USER+100)
#define INDICM_SETIMETOOLTIPS             (WM_USER+101)

// windows\feime\kor\ime2k\cicerolib\inc\ccstock.h
#define ENTERCRITICAL Dll_EnterCriticalSection(&g_csDll)
#define LEAVECRITICAL Dll_LeaveCriticalSection(&g_csDll)
#define ENTERCRITICAL EnterCriticalSection(&g_csDll)
#define LEAVECRITICAL LeaveCriticalSection(&g_csDll)

// windows\feime\kor\ime2k\imm32\immsys.h
#define INDICM_SETIMEICON         (WM_USER+100)
#define INDICM_SETIMETOOLTIPS     (WM_USER+101)

// windows\feime\kor\ime2k\imm32\indicml.h
#define INDICM_SETIMEICON         (WM_USER+100)
#define INDICM_SETIMETOOLTIPS     (WM_USER+101)

// windows\netdde\incs\critsec.h
#define EnterCrit() (EnterCriticalSection(&csNetDde))
#define LeaveCrit() (LeaveCriticalSection(&csNetDde))

// windows\netdde\incs\nddesec.h
#define NDDE_SHAREDB_OPER       (NDDE_SHAREDB_ADD |         \
                                 NDDE_SHAREDB_LIST)
#define NDDE_SHAREDB_POWER      (NDDE_SHAREDB_ADD |         \
                                 NDDE_SHAREDB_FSERVICE |    \
                                 NDDE_SHAREDB_LIST)
#define NDDE_SHAREDB_USER       (NDDE_SHAREDB_ADD |         \
                                 NDDE_SHAREDB_LIST)
#define NDDE_SHARE_GENERIC_READ     (NDDE_SHARE_READ |               \
                                    NDDE_SHARE_INITIATE_STATIC |     \
                                    NDDE_SHARE_REQUEST |             \
                                    NDDE_SHARE_ADVISE |              \
                                    NDDE_SHARE_LIST_ITEMS)
#define NDDE_SHARE_GENERIC_EXECUTE (NDDE_SHARE_INITIATE_STATIC |     \
                                    NDDE_SHARE_INITIATE_LINK |       \
                                    NDDE_SHARE_EXECUTE)
#define NDDE_ITEM_GENERIC_READ     (NDDE_ITEM_REQUEST | NDDE_ITEM_ADVISE)
#define NDDE_GUI_READ_LINK         (NDDE_SHARE_GENERIC_READ |         \
                                    NDDE_SHARE_INITIATE_LINK)
#define NDDE_GUI_CHANGE            (NDDE_SHARE_GENERIC_READ |         \
                                    NDDE_SHARE_GENERIC_WRITE |        \
                                    NDDE_SHARE_GENERIC_EXECUTE)

// windows\richedit\inci\chnutils.h
#define GetPointChunkStart(plocchnk, point) \
			point.u = plocchnk->lsfgi.urPen;  \
			point.v = plocchnk->lsfgi.vrPen;

// windows\richedit\inci\dnutils.h
#define MovePointBack(ptpen, dur, dvr) \
		(ptpen)->u -= (dur); \
		(ptpen)->v -= (dvr);

// windows\richedit\inci\getfmtst.h
#define GetCurrentPointSubl(plssubl,point)	(((point).u =(plssubl)->urCur), \
									 ((point).v =(plssubl)->vrCur))

// windows\richedit\lssrc\break.c
#define	ResolvePosInChunk(plschunkcontext, posichnk, pposinline) \
					(pposinline)->dcp = (posichnk).dcp; \
					LocDnodeFromChunk((plschunkcontext), (posichnk).ichnk, \
							&((pposinline)->plsdn),&((pposinline)->pointStart));

// windows\winstate\v1\imported\net\rras\ras\inc\rasfile.h
#define RFL_ANYHEADER           (RFL_SECTION | RFL_GROUP)

// windows\winstate\v1\imported\net\rras\ras\ui\inc\pbk.h
#define AR_F_TypicalUnsecure   (AR_F_AuthPAP | AR_F_AuthSPAP | AR_F_AuthMD5CHAP | AR_F_AuthMSCHAP | AR_F_AuthMSCHAP2)
#define AR_F_TypicalSecure     (AR_F_AuthMD5CHAP | AR_F_AuthMSCHAP | AR_F_AuthMSCHAP2)
```

