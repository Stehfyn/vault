# Alignment, Rounding, And Numeric Size Math

[Macros index](<macros.md>)

## Curated Candidates

```c
// com\inc\ndrshared\ndrmisc.h
#define ALIGN( pStuff, cAlign ) \
                pStuff = (uchar *)((LONG_PTR)((pStuff) + (cAlign)) \
                                   & ~ ((LONG_PTR)(cAlign)))

#define LENGTH_ALIGN( Length, cAlign ) \
                Length = (((Length) + (cAlign)) & ~ (cAlign))

// base\boot\efi\efiutil.c
#define ALIGN_SIZE(a)   ((a % MIN_ALIGNMENT_SIZE) ? MIN_ALIGNMENT_SIZE - (a % MIN_ALIGNMENT_SIZE) : 0)

// multimedia\dshow\filters\avi\capture\capture.h
#define ALIGNUP(dw,align) ((LONG_PTR)(((LONG_PTR)(dw)+(align)-1) / (align)) * (align))

// base\fs\fastfat\fskd\pch.h
#define AVERAGE(TOTAL,COUNT) ((COUNT) != 0 ? (TOTAL)/(COUNT) : 0)

// multimedia\directx\dmusic\dswave\waveutil.h
#define BLOCKALIGN(cb, b)		((DWORD)((DWORD)((DWORD)((cb) + (b) - 1) / (b)) * (b)))

// multimedia\directx\dsound\dsound\misc.h
#define BLOCKALIGNPAD(a, b) \
            (BLOCKALIGN(a, b) + (((a) % (b)) ? (b) : 0))

// base\boot\lib\vmode.c
#define	BYTES(b)		(((b)/8)+(((b)%8)?1:0))

// base\crts\crtw32\time\mktime.c
#define ChkMul(dest, src1, src2)   ( src1 ? (dest/src1 != src2) : 0 )

// printscan\print\drivers\usermode\driverui\ps\custsize.c
#define CUSTSIZE_ROUNDUP(x)        (ceil((x) * 100.0) / 100.0 + 0.001)
#define CUSTSIZE_ROUNDDOWN(x)      (floor((x) * 100.0) / 100.0 + 0.001)

// shell\osshell\control\t1instal\metrics.h
#define ONOFFSIZE(n)	((((n+7)/8)+sizeof(long)-1)/sizeof(long)*sizeof(long))

// base\boot\bldr\hiber.c
#define PAGE_MASK   (PAGE_SIZE - 1)
#define PAGE_PAGES(n)   (((n) + PAGE_MASK) >> PAGE_SHIFT)

// base\tools\resmon\analog.h
#define PERCENT(delta, base) (base!=0?(100*delta)/base:0)

// multimedia\directx\dmusic\shared\dmstrm.h
#define RIFF_ALIGN(dwSize) (dwSize + (dwSize & 1))

// inetsrv\iis\svcs\infocomm\atq\dpte.hxx
#define ROUND_CHUNK_SIZE( cb )  ( (((cb) + 512)/1024) * 1024)

// base\ntos\inc\heap.h
#define ROUND_DOWN_TO_POWER2( x, n ) ((ULONG_PTR)(x) & ~((ULONG_PTR)(n)-1))

#define ROUND_UP_TO_POWER2( x, n ) (((ULONG_PTR)(x) + ((n)-1)) & ~((ULONG_PTR)(n)-1))

// inetcore\wininet\urlcache\cachedef.h
#define ROUNDUPBLOCKS(bytesize) ((bytesize + NORMAL_ENTRY_SIZE-1) & ~(NORMAL_ENTRY_SIZE-1))

// base\efiutil\efilib\src\usa\rfatsa.cxx
#define RoundUpDiv(num,div)  ((num) / (div) + ((num) % (div) ? 1 : 0))

// inetcore\wininet\urlcache\cachedef.h
#define ROUNDUPDWORD(bytesize) ((bytesize + sizeof(DWORD)-1) & ~(sizeof(DWORD)-1))

#define ROUNDUPPAGE(bytesize) ((bytesize + PAGE_SIZE-1) & ~(PAGE_SIZE-1))

#define ROUNDUPTOPOWEROF2(bytesize, powerof2) (((bytesize) + (powerof2) - 1) & ~((powerof2) - 1))

// base\boot\lib\udfsboot.c
#define UDF_ROUND_TO(X, Y)  (((X) % (Y)) ? (X) + (Y) - ((X) % (Y)) : (X))

// inetsrv\query\kbyacc\defs.h
#define WORDSIZE(n)     (((n)+(BITS_PER_WORD-1))/BITS_PER_WORD)

// inetsrv\intlwb\thai2\sth\dbgmemp.h
#define PAD(a,n)  ( ((a)+(n)-1) / (n) * (n) )

// inetcore\wininet\inc\macros.h
#define ROUND_UP_NK(n, k)   (((n) + ((_ ## k ## K) - 1)) & -(_ ## k ## K))

#define ROUND_UP_DWORD(value) \
    (((value) + sizeof(DWORD) - 1) & ~(sizeof(DWORD) - 1))

// net\winnet\mpransi.cxx
#define ROUND_UP_TO_WCHAR(x)    (((DWORD)(x) + sizeof(WCHAR) - 1) & ~(sizeof(WCHAR) - 1))

#define IS_WCHAR_ALIGNED(x)     (((ULONG_PTR)(x) & (sizeof(WCHAR) - 1)) == 0)

// net\netbios\winsock\wshnetbs.c
#define ALIGN_TO_MAX_NATURAL(_sz)  \
        (((_sz) + (MAX_NATURAL_ALIGNMENT-1)) & (~(MAX_NATURAL_ALIGNMENT-1)))

// com\rpc\ndr20\pipendr.h
#define WIRE_PAD(size, al)   ((((ulong)size)&al) ? ((ulong)(al+1)-(((ulong)size)&al)) : 0)

// com\rpc\ndr20\picklep.hxx
#define MES_HEADER_PAD(x)    ((((unsigned long)x)&7) ? (8-(((unsigned long)x)&7)) : 0)

// ds\security\services\ca\tools\certut\dump.cpp
#define BLOB_ROUND(cb) \
	(((cb) + sizeof(CRYPT_DATA_BLOB) - 1) / sizeof(CRYPT_DATA_BLOB))

// windows\advcore\gdiplus\engine\entry\fontfilecache.hpp
#define QWORD_ALIGN(x) (((x) + 7L) & ~7L)

#define SZ_FONTCACHE_HEADER() QWORD_ALIGN(sizeof(FONTFILECACHEHEADER))

// windows\advcore\gdiplus\engine\render\scan.hpp
#define MAKE_QWORD_ALIGNED(type, p) (\
    reinterpret_cast<type>((reinterpret_cast<INT_PTR>(p) + 7) & ~7))

#define MAKE_DWORD_ALIGNED(type, p) (\
    reinterpret_cast<type>((reinterpret_cast<INT_PTR>(p) + 3) & ~3))

#define ADD_POINTER(type, p, increment) (\
    reinterpret_cast<type>(reinterpret_cast<BYTE *>(p) + (increment)))

// windows\advcore\gdiplus\engine\render\scandib.cpp
#define RoundDWORD(x) (x + ((x%sizeof(DWORD))>0?(sizeof(DWORD)-(x%sizeof(DWORD))):0))

// base\fsrec\udfs_rec.h
#define SectorAlignN(SECTORSIZE, L) (                                           \
    ((((ULONG)(L)) + ((SECTORSIZE) - 1)) & ~((SECTORSIZE) - 1))                 \
)

// base\win32\client\updres.h
#define ROUNDUP(cbin, align) (((cbin) + (align) - 1) & ~((align) - 1))

#define REMAINDER(cbin,align) (((align)-((cbin)&((align)-1)))&((align)-1))

// base\ntdll\ldrp.h
#define NATIVE_BYTES_TO_PAGES(Size)  ((ULONG)((ULONG_PTR)(Size) >> NATIVE_PAGE_SHIFT) + \
                                    (((ULONG)(Size) & (NATIVE_PAGE_SIZE - 1)) != 0))
```

## Backlog

```c
// admin\activec\designer\vb98ctls\include\asp.h
#define IResponse_WriteBlock(This,iBlockNumber)	\
    (This)->lpVtbl -> WriteBlock(This,iBlockNumber)

// admin\activec\designer\vb98ctls\include\kxalpha.h
#define NESTED_ENTRY(Name, fsize, retrg) \
        .text;                          \
        .align  4;                      \
        .globl  Name;                   \
        .ent    Name, 0;                \
Name:;                                  \
        .frame  sp, fsize, retrg;

// admin\activec\designer\vb98ctls\include\localsrv.h
#define PROPERTYPAGE(name)     { OI_PROPERTYPAGE, (void *)&(name##Page) }

// admin\activec\designer\vb98ctls\include\proppage.h
#define PPM_NEWOBJECTS    (WM_USER + 100)
#define PPM_APPLY         (WM_USER + 101)
#define PPM_EDITPROPERTY  (WM_USER + 102)

// admin\activec\designer\vb98ctls\mssnapr\mssnapr\rtconst.h
#define CCH_DEFAULT_TASKPAD         ((sizeof(DEFAULT_TASKPAD) / sizeof(WCHAR)) - 1)
#define CCH_LISTPAD                 ((sizeof(LISTPAD) / sizeof(WCHAR)) - 1)
#define CCH_LISTPAD_HORIZ           ((sizeof(LISTPAD_HORIZ) / sizeof(WCHAR)) - 1)
#define CCH_DEFAULT_TASKPAD2        ((sizeof(DEFAULT_TASKPAD2) / sizeof(WCHAR)) - 1)
#define CCH_LISTPAD2                ((sizeof(LISTPAD2) / sizeof(WCHAR)) - 1)
#define CCH_LISTPAD3                ((sizeof(LISTPAD3) / sizeof(WCHAR)) - 1)

// admin\activec\samples\sdksamples\atl_samp\compsvrext\compsvrext.h
#define IPropPageExt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IPropPageExt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IPropPageExt_Release(This)	\
    (This)->lpVtbl -> Release(This)

// admin\activec\samples\sdksamples\atl_samp\dsadminext\dsadminext.h
#define IPropPageExt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IPropPageExt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IPropPageExt_Release(This)	\
    (This)->lpVtbl -> Release(This)

// admin\activec\samples\sdksamples\atl_samp\iissnapinext\iissnapinext.h
#define IPropPageExt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IPropPageExt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IPropPageExt_Release(This)	\
    (This)->lpVtbl -> Release(This)

// admin\activec\samples\sdksamples\proppage\globals.h
        #define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
        #define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\taskpads\globals.h
        #define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
        #define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\cmdline\bootini\bootcfg64.h
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))

// admin\cys\win32\fpcyscom.h
#define ISpCys_SPNonDefaultHomePage(This,pszHomePage)	\
    (This)->lpVtbl -> SPNonDefaultHomePage(This,pszHomePage)
#define ISpCys_SPInstall(This,bReplaceHomePage,szDiskName,pszErrorString)	\
    (This)->lpVtbl -> SPInstall(This,bReplaceHomePage,szDiskName,pszErrorString)

// admin\darwin\src\inc\msoalloc.h
#define MsoCbHeapAlign(cb)	(((cb) + MsoMskAlign()) & ~MsoMskAlign())
#define MsoCbFrMin()	MsoCbHeapAlign(sizeof(MSOFB))
#define MsoCbFrMax()	((cbHeapMax - sizeof(MSOHB)) & ~MsoMskAlign())

// admin\display\proppage\admin\certifct.h
#define MY_ENCODING_TYPE (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)

// admin\display\proppage\admin\chklist.h
#define ARRAYLENGTH(x)	(sizeof(x)/sizeof((x)[0]))
#define CLST_CHECKDISABLED  (CLST_CHECKED | CLST_DISABLED)
#define CLM_SETCOLUMNWIDTH  (WM_USER + 1)   // lParam = width (dlg units) of a check column (default=32)
#define CLM_GETITEMCOUNT    (WM_USER + 3)   // no parameters
#define CLM_SETSTATE        (WM_USER + 4)   // wParam = row/column, lParam = state
#define CLM_SETITEMDATA     (WM_USER + 6)   // wParam = row, lParam = item data
#define CLM_RESETCONTENT    (WM_USER + 8)   // no parameters
#define CLM_SETTOPINDEX     (WM_USER + 11)  // wParam = index of new top row
#define CLM_ENSUREVISIBLE   (WM_USER + 12)  // wParam = index of item to make fully visible

// admin\display\proppage\debug.h
 #define DECLARE_DEBUG(comp) \
    extern EXTRNC unsigned long comp##InfoLevel; \
    extern EXTRNC char *comp##InfoLevelString; \
    _inline void \
    comp##InlineDebugOut(unsigned long fDebugMask, char const *pszfmt, ...) \
    { \
        CheckInit(comp##InfoLevelString, &comp##InfoLevel); \
        if (comp##InfoLevel & fDebugMask) \
        { \
            va_list va; \
            va_start (va, pszfmt); \
            smprintf(fDebugMask, comp##InfoLevelString, pszfmt, va);\
            va_end(va); \
        } \
    }     \
    \
    class comp##CDbgTrace\
    {\
    private:\
        unsigned long _ulFlags;\
        char const * const _pszName;\
    public:\
        comp##CDbgTrace(unsigned long ulFlags, char const * const pszName);\
        ~comp##CDbgTrace();\
    };\
    \
    inline comp##CDbgTrace::comp##CDbgTrace(\
            unsigned long ulFlags,\
            char const * const pszName)\
    : _ulFlags(ulFlags), _pszName(pszName)\
    {\
        comp##InlineDebugOut(_ulFlags, "Entering %s\n", _pszName);\
    }\
    \
    inline comp##CDbgTrace::~comp##CDbgTrace()\
    {\
        comp##InlineDebugOut(_ulFlags, "Exiting %s\n", _pszName);\
    }
 #define DECLARE_DEBUG(comp) \
    extern EXTRNC unsigned long comp##InfoLevel; \
    extern EXTRNC char *comp##InfoLevelString; \
    _inline void \
    comp##InlineDebugOut(unsigned long fDebugMask, char const *pszfmt, ...) \
    { \
        CheckInit(comp##InfoLevelString, &comp##InfoLevel);

// admin\display\proppage\proputil.h
#define ARRAYLENGTH(x)  (sizeof(x)/sizeof((x)[0]))

// admin\netui\admin\user\h\usrmain.hxx
#define IS_USERPRIV_GROUP( psz )                                \
 (    ::stricmpf( psz, ::pszSpecialGroupUsers )  == 0           \
   || ::stricmpf( psz, ::pszSpecialGroupAdmins ) == 0           \
   || ::stricmpf( psz, ::pszSpecialGroupGuests ) == 0 )

// admin\netui\macprint\pstodib\ti\pstodib\psti.h
#define LWALIGN_L(n) ((n) & 0xffffffe0)

// admin\netui\macprint\pstodib\ti\src\bass\sc.c
#define DROUND(a) ((a + HALFM) & INTPART)

// admin\netui\macprint\pstodib\ti\src\gei\geipm.c
#define     SIZEpagetype        sizeof( unsigned char )
#define SIZEdostartpage         sizeof( unsigned char )
#define SIZEpagestckorder       sizeof( unsigned char )
#define     SIZEpagetype        sizeof( unsigned char )
#define SIZEdostartpage         sizeof( unsigned char )
#define SIZEpagestckorder       sizeof( unsigned char )

// admin\netui\macprint\pstodib\ti\src\graph\graphics.h
#define ALIGN_L(x)    ( (x) & 0xfff0 )
#define ALIGN_R(x)    ( ((x) & 0xfff0) + 15 )

// admin\netui\macprint\pstodib\ti\src\graph\halftone.h
#define CGS_GrayValue(no_pixels, grayindex)                     (* 04-21-89 *) \
                       ((fix) (no_pixels >= MAXGRAYVALUE)                      \
                              ? (((CGS_GrayLevel + CGS_GrayRound) / GrayEntry) \
                                 * no_pixels / MAXGRAYVALUE)                   \
                              : (((CGS_GrayLevel + CGS_GrayRound))             \
                                 * no_pixels / GrayScale))

// admin\netui\macprint\pstodib\ti\src\graph\scaling.c
#define     W_ALIGN(size) (((size) + sizeof(fix) - 1) & ~(sizeof(fix) - 1))

// admin\netui\shell\enum\wnetenum.cxx
#define ROUND_DOWN(x)   ((x) & ~(sizeof(TCHAR) - 1))
#define ROUND_UP(x)     (((x) + sizeof(TCHAR) - 1) & ~(sizeof(TCHAR) - 1))

// admin\pchealth\helpctr\rc\bdychannel\im_inc\mdisp.h
#define IMessengerApp_LaunchOptionsUI(This,mOptDlgPage)	\
    (This)->lpVtbl -> LaunchOptionsUI(This,mOptDlgPage)
#define IMessengerApp2_LaunchOptionsUI(This,mOptDlgPage)	\
    (This)->lpVtbl -> LaunchOptionsUI(This,mOptDlgPage)
#define IMessengerApp3_LaunchOptionsUI(This,mOptDlgPage)	\
    (This)->lpVtbl -> LaunchOptionsUI(This,mOptDlgPage)
#define IMessengerApp3_LaunchPagerUI(This,vUser,ppIMWindow)	\
    (This)->lpVtbl -> LaunchPagerUI(This,vUser,ppIMWindow)
#define IMsgrObject2_SendPage(This,pUser,bstrMessage,ePhoneType,plCookie)	\
    (This)->lpVtbl -> SendPage(This,pUser,bstrMessage,ePhoneType,plCookie)
#define IMsgrSP2_SendPage(This,pUser,bstrMessage,ePhoneType,plCookie)	\
    (This)->lpVtbl -> SendPage(This,pUser,bstrMessage,ePhoneType,plCookie)
#define IMsnMessengerIMWindow_get_IsPageMode(This,pBoolPager)	\
    (This)->lpVtbl -> get_IsPageMode(This,pBoolPager)
#define IMsnMessengerIMWindow2_get_IsPageMode(This,pBoolPager)	\
    (This)->lpVtbl -> get_IsPageMode(This,pBoolPager)

// admin\pchealth\sr\api\precomp.h
#define ALIGN_DOWN(length, type)                                            \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type)                                              \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))

// admin\pchealth\sr\kernel\srpriv.h
#define LongAlignSize(Size) (((ULONG)(Size) + 3) & -4)
#define IS_BLOB_LOCK_ACQUIRED_EXCLUSIVE()                         \
    (ExIsResourceAcquiredExclusiveLite(&(global->BlobLock)))
#define IS_BLOB_LOCK_ACQUIRED()                                   \
    (ExIsResourceAcquiredExclusiveLite(&(global->BlobLock)) ||    \
     ExIsResourceAcquiredSharedLite( &(global->BlobLock) ))
#define SrAcquireBlobLockExclusive()                                  \
    SrAcquireResourceExclusive( &(global->BlobLock), TRUE )
#define SrAcquireBlobLockShared()                        \
    SrAcquireResourceShared( &(global->BlobLock), TRUE )

// admin\pchealth\sr\rstrcore\srshutil.h
#define FA_BLOCK  ( FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM )

// admin\pchealth\sysinfo\msconfig\exe\pageinternational.cpp
#define cbX(X) sizeof(X)

// admin\services\sched\schedui\jobpages.cxx
#define STUBM_SETDATA   (WM_USER + 1)
#define STUBM_GETDATA   (WM_USER + 2)

// admin\snapin\certentp\securitypropertypage.cpp
#define ACTRL_CERTSRV_ENROLL       (ACTRL_DS_READ_PROP | \
                                    ACTRL_DS_WRITE_PROP | \
                                    ACTRL_DS_CONTROL_ACCESS)
#define ACTRL_CERTSRV_READ           ( READ_CONTROL | \
                                       ACTRL_DS_READ_PROP | \
                                       ACTRL_DS_LIST | \
                                       ACTRL_DS_LIST_OBJECT )
#define ACTRL_CERTSRV_WRITE         ( WRITE_DAC | \
                                        WRITE_OWNER | \
                                        ACTRL_DS_WRITE_PROP )

// admin\snapin\corecopy\ndmgr.h
#define IPropertySheetCallback_AddPage(This,hPage)	\
    (This)->lpVtbl -> AddPage(This,hPage)
#define IPropertySheetCallback_RemovePage(This,hPage)	\
    (This)->lpVtbl -> RemovePage(This,hPage)
#define IPropertySheetProvider_AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)	\
    (This)->lpVtbl -> AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)
#define IPropertySheetProvider_AddExtensionPages(This)	\
    (This)->lpVtbl -> AddExtensionPages(This)
#define IPropertySheetProvider_Show(This,window,page)	\
    (This)->lpVtbl -> Show(This,window,page)
#define IExtendPropertySheet_CreatePropertyPages(This,lpProvider,handle,lpIDataObject)	\
    (This)->lpVtbl -> CreatePropertyPages(This,lpProvider,handle,lpIDataObject)
#define IExtendPropertySheet_QueryPagesFor(This,lpDataObject)	\
    (This)->lpVtbl -> QueryPagesFor(This,lpDataObject)
#define IPropertySheetProviderPrivate_AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)	\
    (This)->lpVtbl -> AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)
#define IPropertySheetProviderPrivate_AddExtensionPages(This)	\
    (This)->lpVtbl -> AddExtensionPages(This)
#define IPropertySheetProviderPrivate_Show(This,window,page)	\
    (This)->lpVtbl -> Show(This,window,page)
#define IPropertySheetProviderPrivate_ShowEx(This,window,page,bModalPage)	\
    (This)->lpVtbl -> ShowEx(This,window,page,bModalPage)

// admin\snapin\dsadmin\profile.h
	#define BEGIN_PROFILING_BLOCK( comment ) \
		CMaxProfilingObject::SCreateNewNode( comment );
	#define END_PROFILING_BLOCK \
		CMaxProfilingObject::SCloseCurrentNode();

// admin\snapin\filemgmt\permpage.cpp
#define FILE_PERM_GEN_READ               (GENERIC_READ    |\
                                          GENERIC_EXECUTE)

// admin\wizards\shrwiz\aclpage.h
#define SHARE_PERM_READ_ONLY          (FILE_GENERIC_READ | FILE_EXECUTE)

// admin\wmi\wbem\providers\win32provider\providers\tapedrive.h
#define SPECIAL_TAPEINFO			( SPECIAL_PROPS_ECC | \
									SPECIAL_PROPS_COMPRESSION | \
									SPECIAL_PROPS_PADDING | \
									SPECIAL_PROPS_REPORTSETMARKS | \
									SPECIAL_PROPS_DEFAULTBLOCKSIZE | \
									SPECIAL_PROPS_MAXIMUMBLOCKSIZE | \
									SPECIAL_PROPS_MINIMUMBLOCKSIZE | \
									SPECIAL_PROPS_MAXPARTITIONCOUNT | \
									SPECIAL_PROPS_FEATURESLOW | \
									SPECIAL_PROPS_FEATUREHIGH | \
									SPECIAL_PROPS_ENDOFTAPEWARNINGZONESIZE )

// admin\wmi\wbem\sdk\activex\controls\commondlls\hmmvgrid\gca.cpp
#define HIGH_BIT (1 << ((8 * sizeof(char) * sizeof(int)) - 1))

// admin\wmi\wbem\sdk\activex\controls\eventviewer\container\container.cpp
#define TCHAR_LEN_IN_BYTES(str)	 _tcslen(str)*sizeof(TCHAR)+sizeof(TCHAR)

// admin\wmi\wbem\sdk\activex\controls\security\securityctl.cpp
#define DEFAULT_BACKGROUND_COLOR RGB(0xff, 0xff, 192)  // Yellow background color

// admin\wmi\wbem\sdk\activex\controls\singleview\agraph.cpp
#define DEFAULT_BACKGROUND_COLOR RGB(0xff, 0xff, 192)  // Yellow background color

// admin\wmi\wbem\sdk\activex\controls\singleview\ppgmethodparms.cpp
#define BLOCKSIZE (32 * sizeof(WCHAR))

// admin\wmi\wbem\sdk\psstools\utillib\utillib.h
#define BLOCKSIZE (32 * sizeof(WCHAR))

// admin\wmi\wbem\sdk\samples\diskperfwbem\dpdetail.cpp
#define BLOCKSIZE (32 * sizeof(WCHAR))

// admin\wmi\wbem\sdk\samples\nondistrib\incidenttracker\mca\mca.cpp
#define TCHAR_LEN_IN_BYTES(str)	 _tcslen(str)*sizeof(TCHAR)+sizeof(TCHAR)

// admin\wmi\wbem\sdk\samples\nondistrib\incidenttracker\msa\msa.cpp
#define TCHAR_LEN_IN_BYTES(str)	 _tcslen(str)*sizeof(TCHAR)+sizeof(TCHAR)

// admin\wmi\wbem\sdk\samples\vc\advclient\advclientdlg.cpp
#define BLOCKSIZE (32 * sizeof(WCHAR))

// admin\wmi\wbem\sdk\samples\vc\cmdlineconsumer\src\cmdlineconsumer.cpp
#define TCHAR_LEN_IN_BYTES(str)	 (unsigned long)(_tcslen(str)*sizeof(TCHAR)+sizeof(TCHAR))

// admin\wmi\wbem\sdk\samples\vc\customviews\win32logicaldisk\diskview.cpp
#define COLOR_BG RGB(0, 96, 129)				// Background color

// admin\wmi\wbem\sdk\samples\vc\diskperfwbem\dpdetail.cpp
#define BLOCKSIZE (32 * sizeof(WCHAR))

// admin\wmi\wbem\sdk\samples\vc\eventconsumer\consumer.cpp
#define BLOCKSIZE (32 * sizeof(WCHAR))

// admin\wmi\wbem\sdk\samples\vc\eventconsumer\permevents.cpp
#define TCHAR_LEN_IN_BYTES(str)	 (unsigned long)(_tcslen(str)*sizeof(TCHAR)+sizeof(TCHAR))

// admin\wmi\wbem\sdk\samples\vc\snapin\globals.h
#define MAKE_WIDEPTR_FROMTSTR(ptrname, tstr) \
    long __l##ptrname = (lstrlenW(tstr) + 1) * sizeof(WCHAR); \
    TempBuffer __TempBuffer##ptrname(__l##ptrname); \
    lstrcpyW((LPWSTR)__TempBuffer##ptrname.GetBuffer(), tstr); \
    LPWSTR ptrname = (LPWSTR)__TempBuffer##ptrname.GetBuffer()
#define MAKE_WIDEPTR_FROMTSTR(ptrname, tstr) \
    long __l##ptrname = (lstrlenA(tstr) + 1) * sizeof(WCHAR); \
    TempBuffer __TempBuffer##ptrname(__l##ptrname); \
    MultiByteToWideChar(CP_ACP, 0, tstr, -1, (LPWSTR)__TempBuffer##ptrname.GetBuffer(), __l##ptrname); \
    LPWSTR ptrname = (LPWSTR)__TempBuffer##ptrname.GetBuffer()
#define MAKE_WIDEPTR_FROMTSTR_ALLOC(ptrname, tstr) \
    long __l##ptrname = (lstrlenW(tstr) + 1) * sizeof(WCHAR); \
    LPWSTR ptrname = (LPWSTR)CoTaskMemAlloc(__l##ptrname); \
    lstrcpyW((LPWSTR)ptrname, tstr)
#define MAKE_WIDEPTR_FROMTSTR_ALLOC(ptrname, tstr) \
    long __l##ptrname = (lstrlenA(tstr) + 1) * sizeof(WCHAR); \
    LPWSTR ptrname = (LPWSTR)CoTaskMemAlloc(__l##ptrname); \
    MultiByteToWideChar(CP_ACP, 0, tstr, -1, ptrname, __l##ptrname)
#define MAKE_TSTRPTR_FROMWIDE(ptrname, widestr) \
    long __l##ptrname = (long)((wcslen(widestr) + 1) * 2 * sizeof(TCHAR)); \
    TempBuffer __TempBuffer##ptrname(__l##ptrname); \
    lstrcpyW((LPTSTR)__TempBuffer##ptrname.GetBuffer(), widestr); \
    LPTSTR ptrname = (LPTSTR)__TempBuffer##ptrname.GetBuffer()
#define MAKE_TSTRPTR_FROMWIDE(ptrname, widestr) \
    long __l##ptrname = (long)((wcslen(widestr) + 1) * 2 * sizeof(TCHAR)); \
    TempBuffer __TempBuffer##ptrname(__l##ptrname); \
    WideCharToMultiByte(CP_ACP, 0, widestr, -1, (LPSTR)__TempBuffer##ptrname.GetBuffer(), __l##ptrname, NULL, NULL); \
    LPTSTR ptrname = (LPTSTR)__TempBuffer##ptrname.GetBuffer()

// admin\wmi\wbem\shell\atlui\cmprops\perfpage.h
#define RET_VIRT_AND_RECOVER (RET_VIRTUAL_CHANGE | RET_RECOVER_CHANGE)

// admin\wmi\wbem\shell\atlui\cmprops\startuppage.cpp
#define RET_VIRT_AND_RECOVER (RET_VIRTUAL_CHANGE | RET_RECOVER_CHANGE)

// admin\wmi\wbem\shell\atlui\inc\snapins.inc\mmc.h
#define IPropertySheetCallback_AddPage(This,hPage)	\
    (This)->lpVtbl -> AddPage(This,hPage)
#define IPropertySheetCallback_RemovePage(This,hPage)	\
    (This)->lpVtbl -> RemovePage(This,hPage)
#define IPropertySheetProvider_AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)	\
    (This)->lpVtbl -> AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)
#define IPropertySheetProvider_AddExtensionPages(This)	\
    (This)->lpVtbl -> AddExtensionPages(This)
#define IPropertySheetProvider_Show(This,window,page)	\
    (This)->lpVtbl -> Show(This,window,page)
#define IExtendPropertySheet_CreatePropertyPages(This,lpProvider,handle,lpIDataObject)	\
    (This)->lpVtbl -> CreatePropertyPages(This,lpProvider,handle,lpIDataObject)
#define IExtendPropertySheet_QueryPagesFor(This,lpDataObject)	\
    (This)->lpVtbl -> QueryPagesFor(This,lpDataObject)
#define IExtendPropertySheet2_CreatePropertyPages(This,lpProvider,handle,lpIDataObject)	\
    (This)->lpVtbl -> CreatePropertyPages(This,lpProvider,handle,lpIDataObject)
#define IExtendPropertySheet2_QueryPagesFor(This,lpDataObject)	\
    (This)->lpVtbl -> QueryPagesFor(This,lpDataObject)
#define IExtendTaskPad_GetBackground(This,pszGroup,pTDO)	\
    (This)->lpVtbl -> GetBackground(This,pszGroup,pTDO)

// admin\wmi\wbem\winmgmt\coretest\perfsrv\perfsrvidl.h
#define IPerfBlock_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IPerfBlock_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IPerfBlock_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IPerfBlock_Update(This)	\
    (This)->lpVtbl -> Update(This)
#define IPerfBlock_GetSysName(This,pstrName)	\
    (This)->lpVtbl -> GetSysName(This,pstrName)
#define IPerfBlock_BeginEnum(This)	\
    (This)->lpVtbl -> BeginEnum(This)
#define IPerfBlock_Next(This,ppPerfObject)	\
    (This)->lpVtbl -> Next(This,ppPerfObject)
#define IPerfBlock_EndEnum(This)	\
    (This)->lpVtbl -> EndEnum(This)
#define IPerfService_CreatePerfBlock(This,lNumIDs,alID,ppPerfBlock)	\
    (This)->lpVtbl -> CreatePerfBlock(This,lNumIDs,alID,ppPerfBlock)
#define IPerfService_CreatePerfBlockFromString(This,strIds,ppPerfBlock)	\
    (This)->lpVtbl -> CreatePerfBlockFromString(This,strIds,ppPerfBlock)

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\noncomtest\include\atlframe.h
#define DECLARE_FRAME_WND_CLASS(WndClassName, uCommonResourceID) \
static CFrameWndClassInfo& GetWndClassInfo() \
{ \
	static CFrameWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), 0, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(COLOR_WINDOW + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T(""), uCommonResourceID \
	}; \
	return wc; \
}
#define DECLARE_FRAME_WND_CLASS_EX(WndClassName, uCommonResourceID, style, bkgnd) \
static CFrameWndClassInfo& GetWndClassInfo() \
{ \
	static CFrameWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), style, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(bkgnd + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T(""), uCommonResourceID \
	}; \
	return wc; \
}
#define DECLARE_FRAME_WND_SUPERCLASS(WndClassName, OrigWndClassName, uCommonResourceID) \
static CFrameWndClassInfo& GetWndClassInfo() \
{ \
	static CFrameWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), 0, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, NULL, NULL, WndClassName, NULL }, \
		OrigWndClassName, NULL, NULL, TRUE, 0, _T(""), uCommonResourceID \
	}; \
	return wc; \
}

// admin\wmi\wbem\winmgmt\esscomp\stdcons\wbemcons\cdonts.h
#define INewMail_SetLocaleIDs(This,CodePageID)	\
    (This)->lpVtbl -> SetLocaleIDs(This,CodePageID)
#define ISession_SetLocaleIDs(This,CodePageID)	\
    (This)->lpVtbl -> SetLocaleIDs(This,CodePageID)

// admin\wmi\wbem\winmgmt\xfiles\pagemgr.cpp
#define MERE_PAGE_ID(x)              (x & 0x3FFFFFFF)

// base\boot\bd\i386\cpuapi.c
#define END_OF_CONTROL_SPACE ((PCHAR)(sizeof(KPROCESSOR_STATE)))

// base\boot\bd\ia64\cpuapi.c
#define END_OF_CONTROL_SPACE ((PCHAR)(sizeof(KPROCESSOR_STATE)))

// base\cluster\admin\cluadmex\aclbase.h
#define DECLARE_SCOPE(t,f,b,m,n,d)  \
{ sizeof(DSOP_SCOPE_INIT_INFO), (t), (f), { { (b), (m), (n) }, (d) }, NULL, NULL, S_OK }

// base\cluster\ext\atlsnap\inc\atlsnap.h
#define BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname) \
	HRESULT GetDataClass(IDataObject* pDataObject, CSnapInItem** ppItem, DATA_OBJECT_TYPES* pType) \
	{ \
		if (ppItem == NULL) \
			return E_POINTER; \
		if (pType == NULL) \
			return E_POINTER; \
\
		*ppItem = NULL; \
\
		*pType = CCT_UNINITIALIZED; \
\
		STGMEDIUM stgmedium = { TYMED_HGLOBAL, NULL }; \
		FORMATETC formatetc = { CSnapInItem::m_CCF_NODETYPE, \
			NULL, \
			DVASPECT_CONTENT, \
			-1, \
			TYMED_HGLOBAL \
		}; \
\
		stgmedium.hGlobal = GlobalAlloc(0, sizeof(GUID)); \
		if (stgmedium.hGlobal == NULL) \
			return E_OUTOFMEMORY; \
\
		HRESULT hr = pDataObject->GetDataHere(&formatetc, &stgmedium); \
		if (FAILED(hr)) \
		{ \
			GlobalFree(stgmedium.hGlobal); \
			return hr; \
		} \
\
		GUID guid; \
		memcpy(&guid, stgmedium.hGlobal, sizeof(GUID)); \
\
		GlobalFree(stgmedium.hGlobal); \
		hr = S_OK;

// base\crts\crtw32\rtc\shadow.cpp
#define IDX_ALIGN(addr) ((addr) & ~(MEM_PER_IDX - 1))

// base\efiutil\sdk\inc\eficon.h
#define EFI_BACKGROUND_CYAN         (EFI_BACKGROUND_BLUE | EFI_BACKGROUND_GREEN)
#define EFI_BACKGROUND_MAGENTA      (EFI_BACKGROUND_BLUE | EFI_BACKGROUND_RED)
#define EFI_BACKGROUND_BROWN        (EFI_BACKGROUND_GREEN | EFI_BACKGROUND_RED)
#define EFI_BACKGROUND_LIGHTGRAY    (EFI_BACKGROUND_BLUE | EFI_BACKGROUND_GREEN | EFI_BACKGROUND_RED)

// base\efiutil\sdk\inc\efidef.h
#define SIZE_TO_PAGES(a)  \
    ( ((a) >> PAGE_SHIFT) + ((a) & PAGE_MASK ? 1 : 0) )

// base\efiutil\sdk\inc\efidevp.h
#define END_DEVICE_PATH_LENGTH              (sizeof(EFI_DEVICE_PATH))
#define SetDevicePathEndNode(a)  {                      \
            (a)->Type = END_DEVICE_PATH_TYPE;           \
            (a)->SubType = END_ENTIRE_DEVICE_PATH_SUBTYPE;     \
            (a)->Length[0] = sizeof(EFI_DEVICE_PATH);   \
            (a)->Length[1] = 0;                         \
            }

// base\efiutil\sdk\inc\efistdarg.h
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(UINTN) - 1) & ~(sizeof(UINTN) - 1) )
#define va_start(ap,v)  ( ap = (va_list)&v + _INTSIZEOF(v) )

// base\efiutil\sdk\inc\ia32\pe.h
#define IMAGE_FIRST_SECTION( ntheader ) ((PIMAGE_SECTION_HEADER)        \
    ((UINT32)ntheader +                                                  \
     FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +                 \
     ((PIMAGE_NT_HEADERS)(ntheader))->FileHeader.SizeOfOptionalHeader   \
    ))

// base\efiutil\sdk\inc\ia64\pe.h
#define IMAGE_FIRST_SECTION( ntheader ) ((PIMAGE_SECTION_HEADER)        \
    ((UINT32)ntheader +                                                  \
     FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +                 \
     ((PIMAGE_NT_HEADERS)(ntheader))->FileHeader.SizeOfOptionalHeader   \
    ))

// base\efiutil\sdk\shell\shellenv\exec.c
#define ArgTooLong(i) (i > MAX_ARG_LENGTH-sizeof(CHAR16))

// base\fs\utils\dfrg\inc\atlsnap.h
#define BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname) \
	HRESULT GetDataClass(IDataObject* pDataObject, CSnapInItem** ppItem, DATA_OBJECT_TYPES* pType) \
	{ \
		if (ppItem == NULL) \
			return E_POINTER; \
		if (pType == NULL) \
			return E_POINTER; \
\
		*ppItem = NULL; \
\
		*pType = CCT_UNINITIALIZED; \
\
		STGMEDIUM stgmedium = { TYMED_HGLOBAL, NULL }; \
		FORMATETC formatetc = { CSnapInItem::m_CCF_NODETYPE, \
			NULL, \
			DVASPECT_CONTENT, \
			-1, \
			TYMED_HGLOBAL \
		}; \
\
		stgmedium.hGlobal = GlobalAlloc(0, sizeof(GUID)); \
		if (stgmedium.hGlobal == NULL) \
			return E_OUTOFMEMORY; \
\
		HRESULT hr = pDataObject->GetDataHere(&formatetc, &stgmedium); \
		if (FAILED(hr)) \
		{ \
			GlobalFree(stgmedium.hGlobal); \
			return hr; \
		} \
\
		GUID guid; \
		memcpy(&guid, stgmedium.hGlobal, sizeof(GUID)); \
\
		GlobalFree(stgmedium.hGlobal); \
		hr = S_OK;

// base\mvdm\inc\wowcmpat.h
#define WOWCF_FE_AMIPRO_PM4J_IME         0x00000001   // AMIPRO, set sizeof(DEVMODE of Win3.1) into dmSize , ExtDeviceMode; selectively ignore IME_SETCONVERSIONWINDOW MCW_DEFAULT

// base\ntos\inc\efidevp.h
#define END_DEVICE_PATH_LENGTH              (sizeof(EFI_DEVICE_PATH))

// base\ntos\kd64\ia64\kdcpuapi.c
#define END_OF_CONTROL_SPACE    (sizeof(KPROCESSOR_STATE))

// base\ntos\ke\i386\kernlini.c
#define IDT_SKIP   (7 * sizeof (KIDTENTRY))

// base\ntsetup\hwdb\utils\main\log.c
#define END_OF_BUFFER(buf)      ((buf) + (sizeof(buf) / sizeof(buf[0])) - 1)

// base\ntsetup\migdlls\src\utils\main\log.c
#define END_OF_BUFFER(buf)      ((buf) + (sizeof(buf) / sizeof(buf[0])) - 1)

// base\ntsetup\win95upg\common\migutil\log.c
#define END_OF_BUFFER(buf)  ((buf) + (sizeof(buf) / sizeof(buf[0])) - 1)

// base\remoteboot\admin\qi.h
#define BEGIN_QITABLE_IMP( _Class, _IUnknownPrimaryInterface ) \
    int _i = 0; \
    CopyMemory( _QITable, &QIT_##_Class, sizeof( QIT_##_Class ) ); \
	_QITable[_i].pvtbl = (_IUnknownPrimaryInterface *) this;
#define BEGIN_QITABLE_IMP( _Class, _IUnknownPrimaryInterface ) \
    int _i = 0; \
    LPVOID pCITracker; \
    CopyMemory( _QITable, &QIT_##_Class, sizeof( QIT_##_Class ) ); \
	_QITable[_i].pvtbl = (_IUnknownPrimaryInterface *) this;
#define BEGIN_QITABLE_IMP( _Class, _IUnknownPrimaryInterface ) \
    int _i = 0; \
    CopyMemory( _QITable, &QIT_##_Class, sizeof( QIT_##_Class ) ); \
	_QITable[_i++].pvtbl = (_IUnknownPrimaryInterface *) this;

// base\tools\kdexts2\wsle.c
#define NUMBER_OF_WSLE_TO_READ  1000 // ((PACKET_MAX_SIZE/sizeof(MMWSLE))-1)

// base\win32\fusion\installer\includes\bits.h
#define IBackgroundCopyFile_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyFile_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyFile_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyFile_GetRemoteName(This,pVal)	\
    (This)->lpVtbl -> GetRemoteName(This,pVal)
#define IBackgroundCopyFile_GetLocalName(This,pVal)	\
    (This)->lpVtbl -> GetLocalName(This,pVal)
#define IBackgroundCopyFile_GetProgress(This,pVal)	\
    (This)->lpVtbl -> GetProgress(This,pVal)
#define IEnumBackgroundCopyFiles_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumBackgroundCopyFiles_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumBackgroundCopyFiles_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumBackgroundCopyFiles_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)
#define IEnumBackgroundCopyFiles_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IEnumBackgroundCopyFiles_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumBackgroundCopyFiles_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)
#define IEnumBackgroundCopyFiles_GetCount(This,puCount)	\
    (This)->lpVtbl -> GetCount(This,puCount)
#define IBackgroundCopyError_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyError_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyError_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyError_GetError(This,pContext,pCode)	\
    (This)->lpVtbl -> GetError(This,pContext,pCode)
#define IBackgroundCopyError_GetFile(This,pVal)	\
    (This)->lpVtbl -> GetFile(This,pVal)
#define IBackgroundCopyError_GetErrorDescription(This,LanguageId,pErrorDescription)	\
    (This)->lpVtbl -> GetErrorDescription(This,LanguageId,pErrorDescription)
#define IBackgroundCopyError_GetErrorContextDescription(This,LanguageId,pContextDescription)	\
    (This)->lpVtbl -> GetErrorContextDescription(This,LanguageId,pContextDescription)
#define IBackgroundCopyError_GetProtocol(This,pProtocol)	\
    (This)->lpVtbl -> GetProtocol(This,pProtocol)
#define IBackgroundCopyJob_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyJob_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyJob_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyJob_AddFileSet(This,cFileCount,pFileSet)	\
    (This)->lpVtbl -> AddFileSet(This,cFileCount,pFileSet)
#define IBackgroundCopyJob_AddFile(This,RemoteUrl,LocalName)	\
    (This)->lpVtbl -> AddFile(This,RemoteUrl,LocalName)
#define IBackgroundCopyJob_EnumFiles(This,pEnum)	\
    (This)->lpVtbl -> EnumFiles(This,pEnum)
#define IBackgroundCopyJob_Suspend(This)	\
    (This)->lpVtbl -> Suspend(This)
#define IBackgroundCopyJob_Resume(This)	\
    (This)->lpVtbl -> Resume(This)
#define IBackgroundCopyJob_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)
#define IBackgroundCopyJob_Complete(This)	\
    (This)->lpVtbl -> Complete(This)
#define IBackgroundCopyJob_GetId(This,pVal)	\
    (This)->lpVtbl -> GetId(This,pVal)
#define IBackgroundCopyJob_GetType(This,pVal)	\
    (This)->lpVtbl -> GetType(This,pVal)
#define IBackgroundCopyJob_GetProgress(This,pVal)	\
    (This)->lpVtbl -> GetProgress(This,pVal)
#define IBackgroundCopyJob_GetTimes(This,pVal)	\
    (This)->lpVtbl -> GetTimes(This,pVal)
#define IBackgroundCopyJob_GetState(This,pVal)	\
    (This)->lpVtbl -> GetState(This,pVal)
#define IBackgroundCopyJob_GetError(This,ppError)	\
    (This)->lpVtbl -> GetError(This,ppError)
#define IBackgroundCopyJob_GetOwner(This,pVal)	\
    (This)->lpVtbl -> GetOwner(This,pVal)
#define IBackgroundCopyJob_SetDisplayName(This,Val)	\
    (This)->lpVtbl -> SetDisplayName(This,Val)
#define IBackgroundCopyJob_GetDisplayName(This,pVal)	\
    (This)->lpVtbl -> GetDisplayName(This,pVal)
#define IBackgroundCopyJob_SetDescription(This,Val)	\
    (This)->lpVtbl -> SetDescription(This,Val)
#define IBackgroundCopyJob_GetDescription(This,pVal)	\
    (This)->lpVtbl -> GetDescription(This,pVal)
#define IBackgroundCopyJob_SetPriority(This,Val)	\
    (This)->lpVtbl -> SetPriority(This,Val)
#define IBackgroundCopyJob_GetPriority(This,pVal)	\
    (This)->lpVtbl -> GetPriority(This,pVal)
#define IBackgroundCopyJob_SetNotifyFlags(This,Val)	\
    (This)->lpVtbl -> SetNotifyFlags(This,Val)
#define IBackgroundCopyJob_GetNotifyFlags(This,pVal)	\
    (This)->lpVtbl -> GetNotifyFlags(This,pVal)
#define IBackgroundCopyJob_SetNotifyInterface(This,Val)	\
    (This)->lpVtbl -> SetNotifyInterface(This,Val)
#define IBackgroundCopyJob_GetNotifyInterface(This,pVal)	\
    (This)->lpVtbl -> GetNotifyInterface(This,pVal)
#define IBackgroundCopyJob_SetMinimumRetryDelay(This,Seconds)	\
    (This)->lpVtbl -> SetMinimumRetryDelay(This,Seconds)
#define IBackgroundCopyJob_GetMinimumRetryDelay(This,Seconds)	\
    (This)->lpVtbl -> GetMinimumRetryDelay(This,Seconds)
#define IBackgroundCopyJob_SetNoProgressTimeout(This,Seconds)	\
    (This)->lpVtbl -> SetNoProgressTimeout(This,Seconds)
#define IBackgroundCopyJob_GetNoProgressTimeout(This,Seconds)	\
    (This)->lpVtbl -> GetNoProgressTimeout(This,Seconds)
#define IBackgroundCopyJob_GetErrorCount(This,Errors)	\
    (This)->lpVtbl -> GetErrorCount(This,Errors)
#define IBackgroundCopyJob_SetProxySettings(This,ProxyUsage,ProxyList,ProxyBypassList)	\
    (This)->lpVtbl -> SetProxySettings(This,ProxyUsage,ProxyList,ProxyBypassList)
#define IBackgroundCopyJob_GetProxySettings(This,pProxyUsage,pProxyList,pProxyBypassList)	\
    (This)->lpVtbl -> GetProxySettings(This,pProxyUsage,pProxyList,pProxyBypassList)
#define IBackgroundCopyJob_TakeOwnership(This)	\
    (This)->lpVtbl -> TakeOwnership(This)
#define IEnumBackgroundCopyJobs_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumBackgroundCopyJobs_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumBackgroundCopyJobs_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumBackgroundCopyJobs_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)
#define IEnumBackgroundCopyJobs_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IEnumBackgroundCopyJobs_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumBackgroundCopyJobs_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)
#define IEnumBackgroundCopyJobs_GetCount(This,puCount)	\
    (This)->lpVtbl -> GetCount(This,puCount)
#define IBackgroundCopyCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyCallback_JobTransferred(This,pJob)	\
    (This)->lpVtbl -> JobTransferred(This,pJob)
#define IBackgroundCopyCallback_JobError(This,pJob,pError)	\
    (This)->lpVtbl -> JobError(This,pJob,pError)
#define IBackgroundCopyCallback_JobModification(This,pJob,dwReserved)	\
    (This)->lpVtbl -> JobModification(This,pJob,dwReserved)
#define AsyncIBackgroundCopyCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define AsyncIBackgroundCopyCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define AsyncIBackgroundCopyCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define AsyncIBackgroundCopyCallback_Begin_JobTransferred(This,pJob)	\
    (This)->lpVtbl -> Begin_JobTransferred(This,pJob)
#define AsyncIBackgroundCopyCallback_Finish_JobTransferred(This)	\
    (This)->lpVtbl -> Finish_JobTransferred(This)
#define AsyncIBackgroundCopyCallback_Begin_JobError(This,pJob,pError)	\
    (This)->lpVtbl -> Begin_JobError(This,pJob,pError)
#define AsyncIBackgroundCopyCallback_Finish_JobError(This)	\
    (This)->lpVtbl -> Finish_JobError(This)
#define AsyncIBackgroundCopyCallback_Begin_JobModification(This,pJob,dwReserved)	\
    (This)->lpVtbl -> Begin_JobModification(This,pJob,dwReserved)
#define AsyncIBackgroundCopyCallback_Finish_JobModification(This)	\
    (This)->lpVtbl -> Finish_JobModification(This)
#define IBackgroundCopyManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyManager_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyManager_CreateJob(This,DisplayName,Type,pJobId,ppJob)	\
    (This)->lpVtbl -> CreateJob(This,DisplayName,Type,pJobId,ppJob)
#define IBackgroundCopyManager_GetJob(This,jobID,ppJob)	\
    (This)->lpVtbl -> GetJob(This,jobID,ppJob)
#define IBackgroundCopyManager_EnumJobs(This,dwFlags,ppEnum)	\
    (This)->lpVtbl -> EnumJobs(This,dwFlags,ppEnum)
#define IBackgroundCopyManager_GetErrorDescription(This,hResult,LanguageId,pErrorDescription)	\
    (This)->lpVtbl -> GetErrorDescription(This,hResult,LanguageId,pErrorDescription)

// base\win32\fusion\sxs\sxsp.h
#define DECLARE_ATTRIBUTE_NAME_DESCRIPTOR(_AttributeNamespace, _AttributeName) \
static const WCHAR __AttributeName_ ## _AttributeName [] = L ## #_AttributeName; \
static const ATTRIBUTE_NAME_DESCRIPTOR s_AttributeName_ ## _AttributeName = { _AttributeNamespace, sizeof(_AttributeNamespace) / sizeof(_AttributeNamespace[0]) - 1, __AttributeName_ ## _AttributeName, sizeof(#_AttributeName) / sizeof(#_AttributeName [0]) - 1 }
#define DECLARE_STD_ATTRIBUTE_NAME_DESCRIPTOR(_AttributeName) \
static const WCHAR __AttributeName_ ## _AttributeName [] = L ## #_AttributeName; \
static const ATTRIBUTE_NAME_DESCRIPTOR s_AttributeName_ ## _AttributeName = { NULL, 0, __AttributeName_ ## _AttributeName, sizeof(#_AttributeName) / sizeof(#_AttributeName [0]) - 1 }

// base\wow64\mscpu\fraglib\cpu\codeseqp.h
#define END_FRAGMENT                    \
    return (ULONG)(ULONGLONG)(d - CodeLocation) * sizeof(ULONG);      \
}

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\linkinfo\project.h
#define ALIGN_CNT(x,y)    (((x)+(y)-1) & ~((y)-1))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\comm.h
#define GAllocType(type)                (type *)GAlloc(sizeof(type))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\configmg.h
#define	SIZEOF_DMA		sizeof(DMA_DES)
#define	SIZEOF_IRQ		sizeof(IRQ_DES)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\deballoc.c
#define CBALLOCEXTRA        (sizeof(LPARAM)+sizeof(UINT))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\o2base.hxx
#define DECLARE_ARY(_Cls, _Ty, _pTy) \
    class _Cls : public CAry { public: \
        _Cls(void) : CAry(sizeof(_Ty)) { ; } \
        _Ty& operator[] (int i) { return * (_pTy) Deref(i); } \
        operator _pTy(void) { return (_pTy) _pv; } };
#define DECLARE_ARY(_Cls, _Ty, _pTy) \
    class _Cls : public CAry { public: \
        _Cls(void) : CAry(sizeof(_Ty)) { ; } \
        _Ty& operator[] (int i) { return * (_pTy) Deref(i); } \
        operator _pTy(void) { return (_pTy) _pv; } };

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\mem.h
#define SharedAllocType(type)           (type _huge *)SharedAlloc(sizeof(type))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\twin.h
#define Sync_Dump(lpvBuf, type)     Sync_FnDump((LPVOID)lpvBuf, sizeof(type))

// com\ole2ui32\iconbox.h
#define CBICONBOXWNDEXTRA              (sizeof(HGLOBAL)+sizeof(BOOL))
#define IBWW_FLABEL                    (sizeof(HGLOBAL))

// com\ole2ui32\resimage.h
#define CBRESULTIMAGEWNDEXTRA          sizeof(UINT)

// com\ole32\com\class\bestfit.hxx
#define SIZE_BEST_FIT_HEADER (sizeof(CAvailBlock *) + sizeof(size_t))

// com\ole32\com\inc\ole2int.h
#define OLE2INT_ROUND_UP( x, y )  ((size_t)(x) + ((y)-1) & ~((y)-1))

// com\ole32\com\moniker2\extents.hxx
#define MONIKEREXTENT_HEADERSIZE (sizeof(ULONG) + sizeof(USHORT))

// com\ole32\com\objact\dllcache.hxx
#define STACK_FC_ADD(FC, p, pIF) \
    p = new (alloca(sizeof(CClassCache::CFinishComposite::node))) CClassCache::CFinishComposite::node; \
    p->_pIF = pIF; \
    p->_pPrev = FC._pFinishNodesBack; \
    p->_pNext = (CClassCache::CFinishComposite::node *) &(FC._pFinishNodesFront); \
    p->_pPrev->_pNext = p; \
    p->_pNext->_pPrev = p;

// com\ole32\com\objact\svrholdr.cxx
#define AllocA(type) (type*) _alloca(sizeof(type));

// com\ole32\com\txf\callframe\callframeworker.cpp
#define ALIGNED_VALUE(pStuff, cAlign)           ((uchar *)((ulong)((pStuff) + (cAlign)) & ~ (cAlign)))
#define ALIGNED_VALUE(pStuff, cAlign)           ((uchar *)((ULONGLONG)((pStuff) + (cAlign)) & ~ (cAlign)))

// com\ole32\com\txf\callframe\forwarder.h
#define ForwardingInterfaceProxy_m_pProxyVtbl   (sizeof(void*) * 2)

// com\ole32\dcomss\objex\or.hxx
#define REALLOC(a, f, t, v, oldCount, newCount, sc) \
{ \
  t *tmp = (t *) a((newCount) * sizeof(t)); \
  if (tmp) \
  { \
      if (oldCount) \
      { \
          memcpy(tmp, v, (oldCount) * sizeof(t)); \
          f(v); \
      } \
      sc = RPC_S_OK; \
      v = tmp; \
  } \
  else \
      sc = E_OUTOFMEMORY; \
}

// com\ole32\dcomss\objex\shrmem\dcom95\globals.cxx
#define AssignAndAdvance(Var,Type)  \
    Type **Var = (Type **) pb;      \
    pb += sizeof(Type *);

// com\ole32\dcomss\objex\shrmem\dcom95\globals.hxx
#define ASSIGN_PAGE_ALLOCATOR(TYPE)                                        \
    TYPE##::_pAlloc = &_aPageAllocators[TYPE##_ALLOCATOR_INDEX];           \
    TYPE##::_fPageAllocatorInitialized = TRUE;

// com\ole32\olecnv32\quickdrw.c
#define  POLYLIST       ((sizeof( Integer ) + sizeof( Rect )) / sizeof( Integer ))

// com\ole32\olethunk\ole16\compobj\stdalloc.cxx
#define cbTotalOH	(cbWinRes + sizeof(StdAllocHdr) + cbWinOH + 32)

// com\ole32\olethunk\ole16\inc\stdarg.h
#define _INTSIZEOF(n)	 ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v) ap = (va_list)&v + _INTSIZEOF(v)

// com\ole32\olethunk\ole16\inc\stdio.h
#define  L_tmpnam sizeof(_P_tmpdir)+8

// com\ole32\olethunk\olethk32\stalloc.cxx
#define ALIGN_CB(cb, align) \
    (((cb)+(align)) & ~(align))
#define BLOCK_OVERHEAD (sizeof(SStackBlock))

// com\ole32\olethunk\olethk32\thop.hxx
#define GET_STACK32(pti, val, typ) \
    (val) = *(typ *)(pti)->s32.pbCurrent; \
    SKIP_STACK32(&(pti)->s32, sizeof(typ))
#define TO_STACK32(pti, val, typ) \
    *(typ *)(pti)->s32.pbCurrent = (val);\
    SKIP_STACK32(&(pti)->s32, sizeof(typ))

// com\ole32\stg\props\ntdllmac.hxx
#define QuadAlign(n)  (((n) + sizeof(LONGLONG) - 1) & ~(sizeof(LONGLONG) - 1))

// com\ole32\stg\props\propstm.cxx
#define CB_LOCALE	    (CB_SERIALIZEDPROPERTYVALUE + sizeof(ULONG))
#define CB_BEHAVIOR        (CB_SERIALIZEDPROPERTYVALUE + sizeof(ULONG))

// com\ole32\stg\ref\h\props.h
#define CBPCLIPDATA(clipdata)  \
    ( (clipdata).cbSize - sizeof((clipdata).ulClipFmt) )
#define PropVariantInit(pvar) memset ( pvar, 0, sizeof(PROPVARIANT) )

// com\ole32\stg\ref\h\tchar.h
#define DECLARE_OLESTR(ocsName, pchContents)                       \
        OLECHAR ocsName[sizeof(pchContents)+1];                    \
        _tbstowcs(ocsName, pchContents, sizeof(pchContents)+1)
#define DECLARE_CONST_OLESTR(cocsName, pchContents)                     \
        OLECHAR temp##cocsName[sizeof(pchContents)+1];                  \
        _tbstowcs(temp##cocsName, pchContents, sizeof(pchContents)+1);  \
        const LPOLESTR cocsName = temp##cocsName
#define DECLARE_WIDESTR(wcsName, pchContents)                      \
        WCHAR wcsName[sizeof(pchContents)+1];                      \
        _tbstowcs(wcsName, pchContents, sizeof(pchContents)+1)

// com\ole32\stg\ref\props\h\propmac.hxx
#define QuadAlign(n)  (((n) + sizeof(LONGLONG) - 1) & ~(sizeof(LONGLONG) - 1))

// com\ole32\stg\ref\props\h\propset.hxx
#define CB_PROPERTYSETHEADER	sizeof(PROPERTYSETHEADER)

// com\ole32\stg\ref\props\propstm.cxx
#define CB_LOCALE	    (sizeof(ULONG) + sizeof(ULONG))

// com\ole32\stg\utils\chkdsk\chkdsk.hxx
#define TABLE_SIZE		(SECTORSIZE/sizeof(SECT))

// com\oleutest\cfmex\ctest.hxx
#define SIZE_OF_LARGE_BIND_OPTS  ( 2 * sizeof( BIND_OPTS2 ))

// com\oleutest\letest\gizmobar\gizmo.h
#define CBGIZMO sizeof(GIZMO)

// com\oleutest\letest\gizmobar\gizmobar.h
#define CBCREATEGIZMO sizeof(CREATEGIZMO)
#define CBGBMSG sizeof(GBMSG);
#define CBGBGETINT sizeof(GBGETINT);
#define CBGBSETINT sizeof(GBSETINT);

// com\oleutest\letest\gizmobar\gizmoint.h
#define CBGIZMOBAR sizeof(GIZMOBAR)
#define CBWINDOWEXTRA       sizeof(LPGIZMOBAR)

// com\oleutest\letest\ole2ui\iconbox.h
#define CBICONBOXWNDEXTRA              (sizeof(HGLOBAL)+sizeof(BOOL))
#define IBWW_FLABEL                    (sizeof(HGLOBAL))

// com\oleutest\letest\ole2ui\resimage.h
#define CBRESULTIMAGEWNDEXTRA          sizeof(UINT)

// com\oleutest\perf16\idata\client\datausr.h
#define CBWNDEXTRA               sizeof(PAPPVARS)

// com\oleutest\stgbvt\comtools\h\pathgen.hxx
#define VOLROOT_NAMELEN (sizeof("c:\\") - 1)

// com\rpc\midl\codegen\cgcommon.hxx
#define SIZEOF_RPC_CLIENT_INTERFACE		"sizeof("RPC_C_INT_INFO_TYPE_NAME")"
#define SIZEOF_RPC_SERVER_INTERFACE		"sizeof("RPC_S_INT_INFO_TYPE_NAME")"

// com\rpc\midl\inc\ndrtypes.h
#define INTERPRETER_THUNK_PARAM_SIZE_THRESHOLD  (sizeof(long) * 32)

// com\rpc\midl\support\memory.cxx
#define BUFSIZE (32748 & ~ROUNDING)

// com\rpc\ndr20\asyncndr.h
#define NDR_ASYNC_VERSION           sizeof( NDR_ASYNC_MESSAGE )

// com\rpc\ndr20\asyncu.h
#define NDR_DCOM_ASYNC_VERSION      sizeof( NDR_DCOM_ASYNC_MESSAGE )

// com\rpc\ndr20\picklep.hxx
#define MES_NDR64_CTYPE_HEADER_SIZE ( 24 + 2 * sizeof(RPC_SYNTAX_IDENTIFIER) )

// com\rpc\ndr20\rpcssm.hxx
#define ALIGN_TO_8(x)     (size_t)(((x)+7) & 0xfffffff8)

// com\rpc\perf\raw\inc\dgnb.h
#define ClearNCB( PNCB ) {                                          \
    RtlZeroMemory( PNCB , sizeof (NCB) );                           \
    RtlMoveMemory( (PNCB)->ncb_name,     SPACES, sizeof(SPACES)-1 );\
    RtlMoveMemory( (PNCB)->ncb_callname, SPACES, sizeof(SPACES)-1 );\
    }

// com\rpc\perf\raw\inc\dgsccomn.h
#define ClearSocket(PSOCK) {RtlZeroMemory(PSOCK ,sizeof (SOCKADDR));}

// com\rpc\perf\raw\inc\nb.h
#define ClearNCB( PNCB ) {                                          \
    RtlZeroMemory( PNCB , sizeof (NCB) );                           \
    RtlMoveMemory( (PNCB)->ncb_name,     SPACES, sizeof(SPACES)-1 );\
    RtlMoveMemory( (PNCB)->ncb_callname, SPACES, sizeof(SPACES)-1 );\
    }

// com\rpc\perf\raw\inc\sccomn.h
#define ClearSocket(PSOCK) {RtlZeroMemory(PSOCK ,sizeof (SOCKADDR));}

// com\rpc\perf\raw\inc\scipx.h
#define ClearSocket(PSOCK) {RtlZeroMemory(PSOCK ,sizeof (SOCKADDR));}

// com\rpc\perf\raw\inc\sct.h
#define ClearSocket(PSOCK) {RtlZeroMemory(PSOCK ,sizeof (SOCKADDR));}

// com\rpc\perf\raw\inc\scudp.h
#define ClearSocket(PSOCK) {RtlZeroMemory(PSOCK ,sizeof (SOCKADDR));}

// com\rpc\perf\raw\inc\scx.h
#define ClearSocket(PSOCK) {RtlZeroMemory(PSOCK ,sizeof (SOCKADDR));}

// com\rpc\runtime\mtrt\align.h
#define ConstPadN(p, poft) ( (-(long)p) & (poft - 1) )
#define AlignN(p, poft) ( ((unsigned long)(p) + ((poft)-1)) & ~(poft - 1) )
#define PadN(p, poft) ( (-(long)p) & (poft - 1) )

// com\winole\server\srvr.h
#define   WW_LE         WW_HANDLE + sizeof(PVOID) // signature

// drivers\net\irda\mknet\sys\mk7comm.h
#define SIR_EXTRA_BOF_SIZE	sizeof(SIR_EXTRA_BOF_TYPE)

// drivers\net\irda\mknet\sys\wincomm.h
#define MK7_SIZE(field)	  		sizeof( ((MK7_ADAPTER *)0)->field )

// drivers\net\irda\sigmatel\sys\ircommon.h
#define SLOW_IR_BOF_SIZE			sizeof(SLOW_IR_BOF_TYPE)
#define SLOW_IR_EOF_SIZE			sizeof(SLOW_IR_EOF_TYPE)
#define SLOW_IR_FCS_SIZE			sizeof(SLOW_IR_FCS_TYPE)
#define SLOW_IR_EXTRA_BOF_SIZE      sizeof(SLOW_IR_EXTRA_BOF_TYPE)
#define MEDIUM_IR_FCS_SIZE			sizeof(MEDIUM_IR_FCS_TYPE)
#define FAST_IR_FCS_SIZE            sizeof(FAST_IR_FCS_TYPE)
#define FAST_IR_EOF_SIZE			sizeof(FAST_IR_EOF_TYPE)

// drivers\net\ms\e100bex\kd\e100kd.h
#define SIGN_EXTEND(_v) \
   if (GetTypeSize("PVOID") != sizeof(ULONG64)) \
      (_v) = (ULONG64) (LONG64) (LONG) (_v)

// drivers\net\ms\e100bex\mp.h
#define MP_SIZE(field)     sizeof(((PMP_ADAPTER)0)->field)

// drivers\net\ms\e100bex\private\mp_pm.c
#define CSR_SIZE sizeof (*Adapter->CSRAddress)

// drivers\net\ms\ne2000\ne2000hw.h
#define CardStart(Adapter) \
    NdisRawWritePortUchar(((Adapter->IoPAddr)+NIC_XMIT_CONFIG), TCR_NO_LOOPBACK)

// drivers\parallel\parclass\parclass.h
#define ParCompareGuid(g1, g2)  (                                    \
        ( (g1) == (g2) ) ?                                           \
        TRUE :                                                       \
        RtlCompareMemory( (g1), (g2), sizeof(GUID) ) == sizeof(GUID) \
        )

// drivers\parallel\parport2\parport.h
#define ParCompareGuid(g1, g2)  (                                    \
        ( (g1) == (g2) ) ?                                           \
        TRUE :                                                       \
        RtlCompareMemory( (g1), (g2), sizeof(GUID) ) == sizeof(GUID) \
        )

// drivers\serial\mps\cyclades\y\cyclom-y\cd1400.h
#define CD1400_DISABLE_ALL_INTERRUPTS(ChipAddress,IsPci,CdChannel)  \
do                                                                  \
{                                                                   \
    CD1400_WRITE((ChipAddress),(IsPci),CAR,(CdChannel & 0x03));     \
    CD1400_WRITE((ChipAddress),(IsPci),SRER,0x00);                  \
                                                                    \
} while (0);

// drivers\serial\mps\cyclades\y\cyyport\cd1400.h
#define CD1400_DISABLE_ALL_INTERRUPTS(ChipAddress,IsPci,CdChannel)  \
do                                                                  \
{                                                                   \
    CD1400_WRITE((ChipAddress),(IsPci),CAR,(CdChannel & 0x03));     \
    CD1400_WRITE((ChipAddress),(IsPci),SRER,0x00);                  \
                                                                    \
} while (0);

// drivers\serial\mps\cyclades\y\cyyport\cyyport.h
#define CyyLockPagableSectionByHandle(_secHandle) \
{ \
    MmLockPagableSectionByHandle((_secHandle)); \
    InterlockedIncrement(&CyyGlobals.PAGESER_Count); \
}
#define CyyUnlockPagableImageSection(_secHandle) \
{ \
   InterlockedDecrement(&CyyGlobals.PAGESER_Count); \
   MmUnlockPagableImageSection(_secHandle); \
}

// drivers\serial\mps\cyclades\z\cyzport\cyzport.h
#define CyzLockPagableSectionByHandle(_secHandle) \
{ \
    MmLockPagableSectionByHandle((_secHandle)); \
    InterlockedIncrement(&CyzGlobals.PAGESER_Count); \
}
#define CyzUnlockPagableImageSection(_secHandle) \
{ \
   InterlockedDecrement(&CyzGlobals.PAGESER_Count); \
   MmUnlockPagableImageSection(_secHandle); \
}

// drivers\serial\mps\moxa\intellio\driver\mxport\moxa.h
#define MoxaLockPagableSectionByHandle(_secHandle) \
{ \
    MmLockPagableSectionByHandle((_secHandle)); \
    InterlockedIncrement(&MoxaGlobalData->PAGESER_Count); \
}
#define MoxaUnlockPagableImageSection(_secHandle) \
{ \
   InterlockedDecrement(&MoxaGlobalData->PAGESER_Count); \
   MmUnlockPagableImageSection(_secHandle); \
}

// drivers\serial\mps\spx\speed\driver\inc\speedwmi.h
    #define SPX_SPEED_WMI_FIFO_PROP_DefaultTxFiFoLimit_SIZE sizeof(ULONG)
    #define SPX_SPEED_WMI_FIFO_PROP_TxFiFoLimit_SIZE sizeof(ULONG)
    #define SPX_SPEED_WMI_FIFO_PROP_DefaultTxFiFoTrigger_SIZE sizeof(ULONG)
    #define SPX_SPEED_WMI_FIFO_PROP_TxFiFoTrigger_SIZE sizeof(ULONG)
    #define SPX_SPEED_WMI_FIFO_PROP_DefaultRxFiFoTrigger_SIZE sizeof(ULONG)
    #define SPX_SPEED_WMI_FIFO_PROP_RxFiFoTrigger_SIZE sizeof(ULONG)
    #define SPX_SPEED_WMI_FIFO_PROP_DefaultLoFlowCtrlThreshold_SIZE sizeof(ULONG)
    #define SPX_SPEED_WMI_FIFO_PROP_LoFlowCtrlThreshold_SIZE sizeof(ULONG)
    #define SPX_SPEED_WMI_FIFO_PROP_DefaultHiFlowCtrlThreshold_SIZE sizeof(ULONG)
    #define SPX_SPEED_WMI_FIFO_PROP_HiFlowCtrlThreshold_SIZE sizeof(ULONG)
    #define SPX_SPEED_WMI_FAST_CARD_PROP_DelayCardIntrrupt_SIZE sizeof(BOOLEAN)

// drivers\serial\ser101\serial.h
#define SerialLockPagableSectionByHandle(_secHandle) \
{ \
    MmLockPagableSectionByHandle((_secHandle)); \
    InterlockedIncrement(&SerialGlobals.PAGESER_Count); \
}
#define SerialUnlockPagableImageSection(_secHandle) \
{ \
   InterlockedDecrement(&SerialGlobals.PAGESER_Count); \
   MmUnlockPagableImageSection(_secHandle); \
}

// drivers\serial\ser71051\serial.h
#define SerialLockPagableSectionByHandle(_secHandle) \
{ \
    MmLockPagableSectionByHandle((_secHandle)); \
    InterlockedIncrement(&SerialGlobals.PAGESER_Count); \
}
#define SerialUnlockPagableImageSection(_secHandle) \
{ \
   InterlockedDecrement(&SerialGlobals.PAGESER_Count); \
   MmUnlockPagableImageSection(_secHandle); \
}

// drivers\serial\serial\serial.h
#define SerialLockPagableSectionByHandle(_secHandle) \
{ \
    MmLockPagableSectionByHandle((_secHandle)); \
    InterlockedIncrement(&SerialGlobals.PAGESER_Count); \
}
#define SerialUnlockPagableImageSection(_secHandle) \
{ \
   InterlockedDecrement(&SerialGlobals.PAGESER_Count); \
   MmUnlockPagableImageSection(_secHandle); \
}

// drivers\smartcrd\pscr\pscrnt.h
#define SIZEOF_VERSION_CONTROL  sizeof( VERSION_CONTROL )
#define SIZEOF_PSCR_CONFIGURATION   sizeof( PSCR_CONFIGURATION )

// drivers\smartcrd\pscr\pscrrdwr.h
#define SIZEOF_PSCR_REGISTERS		( sizeof( PSCR_REGISTERS  )
#define SIZEOF_READER_EXTENSION		( sizeof( READER_EXTENSION ))

// drivers\smartcrd\stcusb\common.h
#define SIZEOF_READER_EXTENSION     ( sizeof( READER_EXTENSION ))

// drivers\storage\cdaudio\cdaudio.h
#define CD_DEVICE_EXTENSION_SIZE sizeof(CD_DEVICE_EXTENSION)

// drivers\storage\cdrom\cdrom.h
#define DEVICE_EXTENSION_SIZE sizeof(FUNCTIONAL_DEVICE_EXTENSION) + sizeof(CDROM_DATA)

// drivers\storage\changer\cdchgr.h
#define DEVICE_EXTENSION_SIZE sizeof(DEVICE_EXTENSION)

// drivers\storage\class\filters\simbad\simbad.c
#define SIMBAD_DEVICE_EXTENSION_SIZE sizeof( SIMBAD_DEVICE_EXTENSION )

// drivers\storage\disk\disk.h
#define FUNCTIONAL_EXTENSION_SIZE sizeof(FUNCTIONAL_DEVICE_EXTENSION) + sizeof(DISK_DATA)
#define PHYSICAL_EXTENSION_SIZE sizeof(PHYSICAL_DEVICE_EXTENSION) + sizeof(DISK_DATA)

// drivers\storage\diskperf\diskperf.c
#define DEVICE_EXTENSION_SIZE sizeof(DEVICE_EXTENSION)

// drivers\storage\fdc\fdc\q117_dat.h
#define FSC_FTK             (FSC_SEG*SEG_FTK)    // floppy sectors per floppy track (QIC-40 205ft & 310ft)
#define MAX_BAD_BLOCKS          ((1024*27)/sizeof(ULONG))

// drivers\storage\fdc\inc\q117_dat.h
#define FSC_FTK             (FSC_SEG*SEG_FTK)    // floppy sectors per floppy track (QIC-40 205ft & 310ft)
#define MAX_BAD_BLOCKS          ((1024*27)/sizeof(ULONG))

// drivers\storage\fdc\mode3fdc\desk2fdc\q117_dat.h
#define FSC_FTK             (FSC_SEG*SEG_FTK)    // floppy sectors per floppy track (QIC-40 205ft & 310ft)
#define MAX_BAD_BLOCKS          ((1024*27)/sizeof(ULONG))

// drivers\storage\fpfilter\fpfilter.c
#define DEVICE_EXTENSION_SIZE sizeof(DEVICE_EXTENSION)

// drivers\storage\ide\atapi\atapi.h
#define IDENTIFY_DATA_SIZE sizeof(IDENTIFY_DATA)
#define SAVE_ORIGINAL_CDB(DeviceExtension, Srb) \
	RtlCopyMemory(DeviceExtension->OriginalCdb, Srb->Cdb, sizeof(CDB));
#define RESTORE_ORIGINAL_CDB(DeviceExtension, Srb) \
	RtlCopyMemory(Srb->Cdb, DeviceExtension->OriginalCdb, sizeof(CDB));

// drivers\storage\ide\atapi\devpdo.h
#define PDOS_QUEUE_BLOCKED        (PDOS_MUST_QUEUE | PDOS_QUEUE_FROZEN_BY_POWER_DOWN)

// drivers\storage\ide\atapi\ideport.h
#define FULL_RESOURCE_LIST_SIZE(n) (sizeof (CM_FULL_RESOURCE_DESCRIPTOR) + (sizeof (CM_PARTIAL_RESOURCE_DESCRIPTOR) * (n - 1)))

// drivers\storage\ide\atapi\port.h
#define LONG_ALIGN (sizeof(LONG) - 1)
#define DEVICE_EXTENSION_SIZE sizeof(DEVICE_EXTENSION)

// drivers\storage\ide\inc\ide.h
#define IDENTIFY_DATA_SIZE sizeof(IDENTIFY_DATA)

// drivers\storage\ide\pciidex\pciidex.h
#define FULL_RESOURCE_LIST_SIZE(n) (sizeof (CM_FULL_RESOURCE_DESCRIPTOR) + (sizeof (CM_PARTIAL_RESOURCE_DESCRIPTOR) * (n - 1)))

// drivers\storage\mcd\drivers\atl\atlmc.h
#define ATL_PARTIAL_SIZE sizeof(struct _ATL_PED)
#define ATL_FULL_SIZE sizeof(struct _ATL_FED)

// drivers\storage\mpath\control\pdowmi.h
    #define PDO_INFORMATION_ScsiAddress_SIZE sizeof(SCSI_ADDR)
    #define PDO_INFORMATION_PathIdentifier_SIZE sizeof(ULONGLONG)
    #define PDO_INFORMATION_ControllerIdentifier_SIZE sizeof(ULONGLONG)
    #define MPIO_GET_DESCRIPTOR_NumberPdos_SIZE sizeof(ULONG)
    #define MPIO_GET_DESCRIPTOR_DeviceName_SIZE sizeof(CName)

// drivers\storage\mpath\control\wmi.h
    #define MPIO_DRIVE_INFO_NumberPaths_SIZE sizeof(ULONG)
    #define MPIO_DISK_INFO_NumberDrives_SIZE sizeof(ULONG)
    #define MPIO_ADAPTER_INFORMATION_PathId_SIZE sizeof(ULONGLONG)
    #define MPIO_ADAPTER_INFORMATION_Pad_SIZE sizeof(UCHAR)
    #define MPIO_PATH_INFORMATION_NumberPaths_SIZE sizeof(ULONG)
    #define MPIO_CONTROLLER_INFO_ControllerId_SIZE sizeof(ULONGLONG)
    #define MPIO_CONTROLLER_INFO_ControllerState_SIZE sizeof(ULONG)
    #define MPIO_CONTROLLER_CONFIGURATION_NumberControllers_SIZE sizeof(ULONG)

// drivers\storage\mpath\dsm\wmi.h
    #define GENDSM_CONFIGINFO_NumberFOGroups_SIZE sizeof(ULONG)
    #define GENDSM_CONFIGINFO_NumberMPGroups_SIZE sizeof(ULONG)
    #define GENDSM_CONFIGINFO_LoadBalancePolicy_SIZE sizeof(ULONG)

// drivers\storage\port\diskdump\diskdump.h
#define DEVICE_EXTENSION_SIZE sizeof(DEVICE_EXTENSION)

// drivers\storage\port\scsi\miniport\advansys\asc3550\a_advlib.h
#define ADV_DWALIGN(addr)       (((ulong) (addr) + 0x3) & ~0x3)

// drivers\storage\port\scsi\miniport\agilent\afc\mapping.h
#define PADEV_SIZE			(gMaxPaDevices)*sizeof(PA_DEVICE)
#define FCDEV_SIZE			(gMaxPaDevices)*sizeof(agFCDev_t)
#define FCNODE_INFO_SIZE	(gMaxPaDevices)*sizeof(NODE_INFO)

// drivers\storage\port\scsi\miniport\aha154x\support.c
#define LONG_ALIGN (sizeof(LONG) - 1)

// drivers\storage\port\scsi\miniport\hipoint\hpt3xx\winnt\global.h
#define SetBlockCount(IOPort,x)      OutPort(&IOPort->BlockCount, x)
#define SetBlockNumber(IOPort,x)     OutPort(&IOPort->BlockNumber, x)
#define GetBlockNumber(IOPort)       (UCHAR)InPort((PUCHAR)&IOPort->BlockNumber)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\dac960if.h
#define	dac_badblock_v2x_s	sizeof(dac_badblock_v2x_t)
#define	dac_badblock_v4x_s	sizeof(dac_badblock_v4x_t)
#define	dac_badblocktable_s	sizeof(dac_badblocktable_t)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mlxscsi.h
#define	ucscsi_badblock_s	sizeof(ucscsi_badblock_t)
#define	ucscsi_badblocktable_s	sizeof(ucscsi_badblocktable_t)
#define	ucs_blockdescriptor_s	sizeof(ucs_blockdescriptor_t)
#define	ucsdad_modepage1_s	sizeof(ucsdad_modepage1_t)
#define	ucsdad_modepage2_s	sizeof(ucsdad_modepage2_t)
#define	ucsdad_modepage3_s	sizeof(ucsdad_modepage3_t)
#define	ucsdad_modepage4_s	sizeof(ucsdad_modepage4_t)
#define	ucsdad_modepage5_s	sizeof(ucsdad_modepage5_t)
#define	ucsdad_modepage8_s	sizeof(ucsdad_modepage8_t)
#define	ucscsi_ecpagecode_s	sizeof(ucscsi_ecpagecode_t)

// drivers\storage\proppage\dvdprop.c
#define NUM_LCID_ENTRIES (sizeof(Lcid2DvdTable)/sizeof(LCID_2_DVD_TABLE))

// drivers\storage\redbook\redbook.h
#define TAG_MODE_PAGE  'apBR' // mode pages (returned to caller)

// drivers\storage\sbp2port\sbp2port.h
#define SBP2_NUM_PAGE_TABLE_ENTRIES (ULONG) (PAGE_SIZE / sizeof (OCTLET))

// drivers\storage\scsiport\port.h
#define ROUND_UP_COUNT(Count,Pow2) \
        ( ((Count)+(Pow2)-1) & (~(((LONG)(Pow2))-1)) )
#define LONG_ALIGN (sizeof(LONG) - 1)
#define ADAPTER_EXTENSION_SIZE sizeof(ADAPTER_EXTENSION)
#define GET_VA_MAPPING_INFO(adapter, block)\
    (PSP_VA_MAPPING_INFO)((PUCHAR)(block) + ((adapter)->CommonBufferSize - PAGE_SIZE))

// drivers\storage\scsiprnt\printpnp.h
#define DEVICE_EXTENSION_SIZE       sizeof(FUNCTIONAL_DEVICE_EXTENSION) + sizeof(PRINTER_DATA)

// drivers\storage\tape\drivers\4mmsony\4mmsony.h
#define DEVICE_EXTENSION_SIZE sizeof(DEVICE_EXTENSION) + sizeof(TAPE_DATA)

// drivers\storage\volsnap\vss\modules\sqllib\inc\vdi.h
#define IServerVirtualDeviceSet_AllocateBuffer(This,ppBuffer,dwSize,dwAlignment)	\
    (This)->lpVtbl -> AllocateBuffer(This,ppBuffer,dwSize,dwAlignment)
#define IServerVirtualDeviceSet2_BeginConfiguration(This,dwFeatures,dwAlignment,dwBlockSize,dwMaxTransferSize,dwTimeout)	\
    (This)->lpVtbl -> BeginConfiguration(This,dwFeatures,dwAlignment,dwBlockSize,dwMaxTransferSize,dwTimeout)
#define IServerVirtualDeviceSet2_RequestBuffers(This,dwSize,dwAlignment,dwCount)	\
    (This)->lpVtbl -> RequestBuffers(This,dwSize,dwAlignment,dwCount)
#define IServerVirtualDeviceSet2_QueryAvailableBuffers(This,dwSize,dwAlignment,pCount)	\
    (This)->lpVtbl -> QueryAvailableBuffers(This,dwSize,dwAlignment,pCount)
#define IServerVirtualDeviceSet2_AllocateBuffer(This,ppBuffer,dwSize,dwAlignment)	\
    (This)->lpVtbl -> AllocateBuffer(This,ppBuffer,dwSize,dwAlignment)

// drivers\storage\volsnap\vss\server\modules\sqllib\inc\vdi.h
#define IServerVirtualDeviceSet_AllocateBuffer(This,ppBuffer,dwSize,dwAlignment)	\
    (This)->lpVtbl -> AllocateBuffer(This,ppBuffer,dwSize,dwAlignment)
#define IServerVirtualDeviceSet2_BeginConfiguration(This,dwFeatures,dwAlignment,dwBlockSize,dwMaxTransferSize,dwTimeout)	\
    (This)->lpVtbl -> BeginConfiguration(This,dwFeatures,dwAlignment,dwBlockSize,dwMaxTransferSize,dwTimeout)
#define IServerVirtualDeviceSet2_RequestBuffers(This,dwSize,dwAlignment,dwCount)	\
    (This)->lpVtbl -> RequestBuffers(This,dwSize,dwAlignment,dwCount)
#define IServerVirtualDeviceSet2_QueryAvailableBuffers(This,dwSize,dwAlignment,pCount)	\
    (This)->lpVtbl -> QueryAvailableBuffers(This,dwSize,dwAlignment,pCount)
#define IServerVirtualDeviceSet2_AllocateBuffer(This,ppBuffer,dwSize,dwAlignment)	\
    (This)->lpVtbl -> AllocateBuffer(This,ppBuffer,dwSize,dwAlignment)

// drivers\storage\volsnap\vss\tests\harness\common\bsstring.cxx
#define ROUND(x,y) (((x)+(y-1))&~(y-1))

// drivers\storage\volsnap\vss\tests\harness\inc\bsfixalloc.hxx
#define IMPLEMENT_FIXED_ALLOC(class_name, block_size) \
CBsFixedAlloc class_name::s_alloc(sizeof(class_name), block_size) \

// drivers\tpg\hwx\bear\inc\hwr_sys.h
#define MAX_MBLOCKSIZE        0xfffffff0 //(0xFFFF-sizeof(_HMEM))
#define HWRMathFloor(d) (HWRMathSystemFloor(d,&dTmpResult),dTmpResult)

// drivers\tpg\hwx\bear\inc\palk.h
#define PalkHeaderSize(IsMerged) ( (IsMerged) ?  \
            PALK_VER_ID_LEN+sizeof(int)+sizeof(int)+sizeof(int)+sizeof(int) :   \
            PALK_VER_ID_LEN+sizeof(int)+sizeof(int) )
#define PalkGetGraphSize(pV) (*(int *)( VBeg(pV)+sizeof(int) ))
#define PalkGetChsetTablSize(pV) (*(int *)( VBeg(pV)+sizeof(int)+sizeof(int) ))
#define PalkGetDvsetTablSize(pV) (*(int *)( VBeg(pV)+sizeof(int)+sizeof(int)+sizeof(int) ))

// drivers\video\matrox\mga\disp\driver.h
#define ROUND_UP_TO_64K(x)  (((ULONG)(x) + 0x10000 - 1) & ~(0x10000 - 1))

// drivers\video\ms\3dlabs\perm2\disp\d3ddx6.c
#define STARTVERTEXSIZE (sizeof(D3DHAL_DP2STARTVERTEX))

// drivers\video\ms\3dlabs\perm2\disp\dd.h
#define ROUND_UP_TO_64K(x)  (((ULONG)(x) + 0x10000 - 1) & ~(0x10000 - 1))

// drivers\video\ms\3dlabs\perm2\mini\permedia.h
#define PADRANGE(id, n)         PAD(id, (n)-sizeof(P2_REG))

// drivers\video\ms\3dlabs\perm3\disp\dx\d3ddp2p3.c
#define STARTVERTEXSIZE (sizeof(D3DHAL_DP2STARTVERTEX))

// drivers\video\ms\3dlabs\perm3\disp\gdi\glint.h
#define INTERRUPTS_ENABLED  ((ppdev->flCaps & CAPS_INTERRUPTS) && glintInfo->pInterruptCommandBlock)
#define PADRANGE(id, n)         PAD(id, (n)-sizeof(GLINT_REG))

// drivers\video\ms\3dlabs\perm3\disp\gdi\pxrx.h
#define LOAD_FOREGROUNDCOLOUR(value)                                                    \
    do {                                                                                \
        if( (value) != glintInfo->foregroundColour ) {                                    \
            glintInfo->foregroundColour = (value);                                        \
            QUEUE_PXRX_DMA_TAG( __GlintTagForegroundColor, glintInfo->foregroundColour );    \
        }                                                                                \
    } while(0)
#define LOAD_BACKGROUNDCOLOUR(value)                                                    \
    do {                                                                                \
        if( (value) != glintInfo->backgroundColour ) {                                    \
            glintInfo->backgroundColour = (value);                                        \
            QUEUE_PXRX_DMA_TAG( __GlintTagBackgroundColor, glintInfo->backgroundColour );    \
        }                                                                                \
    } while(0)
#define __CONFIG2D_ENABLES              (__CONFIG2D_OPAQUESPANS | \
                                         __CONFIG2D_USERSCISSOR | \
                                         __CONFIG2D_FBDESTREAD  | \
                                         __CONFIG2D_ALPHABLEND  | \
                                         __CONFIG2D_DITHER      | \
                                         __CONFIG2D_CONSTANTSRC | \
                                         __CONFIG2D_FBWRITE     | \
                                         __CONFIG2D_FBBLOCKING  | \
                                         __CONFIG2D_EXTERNALSRC | \
                                         __CONFIG2D_LUTENABLE)

// drivers\video\ms\3dlabs\perm3\disp\inc\driver.h
#define ROUND_UP_TO_64K(x)  (((ULONG)(x) + 0x10000 - 1) & ~(0x10000 - 1))

// drivers\video\ms\3dlabs\perm3\mini\interupt.h
#define REQUEST_INTR_CMD_BLOCK_MUTEX(pBlock, bHaveMutex) \
{ \
    pBlock->bMiniportHasAccess = TRUE; \
    if(!pBlock->bDisplayDriverHasAccess) \
    { \
        bHaveMutex = TRUE; \
    } \
    else \
    { \
        bHaveMutex = FALSE; \
        pBlock->bMiniportHasAccess = FALSE; \
    } \
}

// drivers\video\ms\3dlabs\perm3\mini\perm3.h
#define PADRANGE(id, n)         PAD(id, (n)-sizeof(PERM3_REG))

// drivers\video\ms\ati\disp\dci.h
#define ROUND_UP_TO_64K(x)  (((ULONG)(x) + 0x10000 - 1) & ~(0x10000 - 1))

// drivers\video\ms\ati\disp\driver.h
#define ROUND8(x)   (((x)+7)&~7)
#define ROUND_UP_TO_64K(x)  (((ULONG)(x) + 0x10000 - 1) & ~(0x10000 - 1))
#define ROUND_DOWN_TO_64K(x)  (((ULONG)(x) & 0xFFFF0000 ))

// drivers\video\ms\ati\mini\amachcx.h
#define GP_IO                   (REG_BLOCK_0 | 0x1E)

// drivers\video\ms\cirrus\disp\driver.h
#define ROUND_UP_TO_64K(x)      (((ULONG)(x) + 0xFFFF) & ~0xFFFF)

// drivers\video\ms\laguna\disp\cl5465\mcdtri.c
#define PREC_1616(inval,outval) {                                                           \
float bias = (inval>=0) ? PREC_ROUND : -PREC_ROUND;                                         \
outval=(float)(FTOL((inval+bias)*PREC_FLOAT)) * ((FLT_TYPE 1.0) / PREC_FLOAT);              \
}
#define NEG_PREC_1616(inval,outval) {                                                       \
float bias = (inval>0) ? -PREC_ROUND : 0;                                                   \
outval=(float)(FTOL((inval+bias)*PREC_FLOAT)) * ((FLT_TYPE 1.0) / PREC_FLOAT);              \
}

// drivers\video\ms\laguna\disp\include\driver.h
#define ROUND_UP_TO_64K(x)  (((ULONG)(x) + 0x10000 - 1) & ~(0x10000 - 1))

// drivers\video\ms\laguna\mini\include\driver.h
#define ROUND_UP_TO_64K(x)  (((ULONG)(x) + 0x10000 - 1) & ~(0x10000 - 1))

// drivers\video\ms\port\dump.c
#define TRIAGE_DUMP_DATA_SIZE (TRIAGE_DUMP_SIZE - sizeof(ULONG))

// drivers\video\ms\s3\disp\driver.h
#define ROUND_UP_TO_64K(x)  (((ULONG)(x) + 0x10000 - 1) & ~(0x10000 - 1))

// drivers\video\ms\w32\disp\driver.h
#define ROUND_UP_TO_64K(x)  (((ULONG)(x) + 0x10000 - 1) & ~(0x10000 - 1))

// drivers\wdm\audio\backpln\portcls\ports\dmus\allocatr.h
#define kNumEvtsPerPage     (PAGE_SIZE / sizeof(DMUS_KERNEL_EVENT))

// drivers\wdm\audio\backpln\portcls\ports\midi\private.h
#define kMaxSysExMessageSize (PAGE_SIZE / sizeof(PVOID) * PAGE_SIZE)

// drivers\wdm\audio\filters\kmixer\rfiir.c
#define SizeOfFloat sizeof(FLOAT)

// drivers\wdm\audio\filters\kmixer\slocal.c
#define SizeOfShort sizeof(SHORT)

// drivers\wdm\audio\legacy\wdmaud.sys\robust.h
#define AudioAllocateMemory_Paged(b,t,f,p) AudioAllocateMemory(b,t,f|PAGED_MEMORY,p)

// drivers\wdm\bda\samples\casamp\driver\casamp.h
#define IsEqualGUID(rguid1, rguid2) (!memcmp(rguid1, rguid2, sizeof(GUID)))

// drivers\wdm\bda\samples\casamp\driver\inc\bdamedia.h
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
#define DEFINE_KSPROPERTY_ITEM_BDA_SIGNAL_SOURCE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_SIGNAL_SOURCE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_SIGNAL_TUNING_SPACE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_SIGNAL_TUNING_SPACE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(GUID),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_SIGNAL_NETWORK_TYPE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_SIGNAL_NETWORK_TYPE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(GUID),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_SIGNAL_STATE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_SIGNAL_STATE,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(BDA_SIGNAL_STATE),\
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
        sizeof(KSM_PIN),\
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
        sizeof(KSPROPERTY),\
        0,\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_NODE_PROPERTIES(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_NODE_PROPERTIES,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        0,\
        FALSE,\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_NODE_EVENTS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_NODE_EVENTS,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
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
#define DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_TRANSPONDER(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_RF_TUNER_TRANSPONDER,\
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
#define DEFINE_KSPROPERTY_ITEM_BDA_ECMMAP_EMM_PID(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_ECMMAP_EMM_PID,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_ECMMAP_MAP_LIST(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_ECMMAP_MAP_LIST,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        0,\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_ECMMAP_UPDATE_MAP(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_ECMMAP_UPDATE_MAP,\
        FALSE,\
        sizeof(KSPROPERTY),\
        sizeof(BDA_ECM_MAP),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_ECMMAP_REMOVE_MAP(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_ECMMAP_REMOVE_MAP,\
        FALSE,\
        sizeof(KSPROPERTY),\
        sizeof(BDA_ECM_MAP),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_ECMMAP_UPDATE_ES_DESCRIPTOR(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_ECMMAP_UPDATE_ES_DESCRIPTOR,\
        FALSE,\
        sizeof(KSPROPERTY),\
        sizeof(BDA_ES_DESCRIPTOR),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_ECMMAP_UPDATE_PROGRAM_DESCRIPTOR(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_ECMMAP_UPDATE_PROGRAM_DESCRIPTOR,\
        FALSE,\
        sizeof(KSPROPERTY),\
        sizeof(BDA_PROGRAM_DESCRIPTOR),\
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
#define DEFINE_KSEVENT_BDA_CA_MODULE_UI_REQUESTED(AddHandler, RemoveHandler, SupportHandler)\
    DEFINE_KSEVENT_ITEM(\
        KSEVENT_BDA_CA_MODULE_UI_REQUESTED,\
        sizeof( KSEVENTDATA), \
        0, \
        (AddHandler),\
        (RemoveHandler),\
        (SupportHandler)\
        )

// drivers\wdm\bda\samples\mauitune\philtune.h
#define IsEqualGUID(rguid1, rguid2) (!memcmp(rguid1, rguid2, sizeof(GUID)))

// drivers\wdm\capture\mini\usbcamd\philips\vfwext\phvcmext.h
#define VFW_HIDE_ALL_PAGES           (VFW_HIDE_SETTINGS_PAGE | VFW_HIDE_IMAGEFORMAT_PAGE | VFW_HIDE_CAMERACONTROL_PAGE)

// drivers\wdm\dvd\mini\dxr2\avint.h
#define DEFCOLOR_AUTOALIGN	RGB( 0, 0, 255 )

// drivers\wdm\dvd\mini\sgsorig\board.h
#define SendBlock8(Address,  Buffer, Size) BoardSendBlock8((PUCHAR)(Address),   (PUCHAR)(Buffer),  (ULONG)(Size))

// drivers\wdm\input\client\hidtest\hidtest.c
#define COMPARE_GUIDS(guid1, guid2) ((0 == memcmp(&(guid1), &(guid2), sizeof(GUID))))

// drivers\wdm\input\hidir\hidir.h
#define HIDIR_REPORT_SIZE sizeof(ULONG)

// drivers\wdm\input\legacy\mshgame\controlitemcollection\dumpcommandblock.cpp
#define SKIP_TO_NEXT_COMMAND_DIRECTORY(pCommandDirectory)\
	(reinterpret_cast<PCOMMAND_DIRECTORY>\
		(reinterpret_cast<PUCHAR>(pCommandDirectory) +\
		pCommandDirectory->ulEntireSize)\
	)

// drivers\wdm\input\samples\monitor\map.h
#define cbX(X) sizeof(X)

// drivers\wdm\input\tabletpc\cpl\tabletpc.c
#define MAX_PAGES       (sizeof(TabletPCPropPages)/sizeof(TABLETPC_PROPPAGE))

// drivers\wdm\input\tabletpc\tabsrv\supertip_obj.h
#define ISuperTip_ShowPropertyPages(This)	\
    (This)->lpVtbl -> ShowPropertyPages(This)

// drivers\wdm\input\tools\dt\dt.h
#define BACKGROUND_BRUSH   COLOR_MENU+1//RGB(128,128,128)

// drivers\wdm\input\tools\hidmon\class.h
#define CBWNDEXTRA sizeof(ULONG)*5

// drivers\wdm\usb\driver\usbser\utils.h
#define UsbSerLockPagableSectionByHandle(_secHandle) \
{ \
    MmLockPagableSectionByHandle((_secHandle)); \
    InterlockedIncrement(&PAGEUSBSER_Count); \
}
#define UsbSerUnlockPagableImageSection(_secHandle) \
{ \
   InterlockedDecrement(&PAGEUSBSER_Count); \
   MmUnlockPagableImageSection(_secHandle); \
}

// drivers\wdm\usb\hcd\miniport\usbohci\usbohci.h
#define OHCI_COMMON_BUFFER_SIZE (sizeof(HCCA_BLOCK)+\
            NO_ED_LISTS*sizeof(HW_ENDPOINT_DESCRIPTOR) +\
            (17*2)*sizeof(HCD_ENDPOINT_DESCRIPTOR))

// drivers\wdm\usb\hcd\miniport\usbuhci\usbuhci.h
#define PAGE_CROSSING(PhysicalAddress, length) \
    ((PhysicalAddress+length)%PAGE_SIZE < length && (PhysicalAddress+length)%PAGE_SIZE != 0)

// drivers\wdm\usb\hcd\uhcd\uhcd.h
#define UHCD_SPAD(T, align) \
     ((align) - (sizeof(T) % (align)) + sizeof(T))
#define UHCD_HW_DESCRIPTOR_SIZE     (sizeof(HW_TRANSFER_DESCRIPTOR))

// drivers\wdm\vbi\nabtsfec\wdm\bpcstore.h
#define NF_BUFFER_SIZE(nbp) \
	(sizeof (*(nbp)) - (sizeof ((nbp)->data) - ((nbp)->dataSize)))

// drivers\wdm\vbi\tests\testfec\testfec.cpp
#define READ_BUFFER_SIZE    sizeof(NABTSFEC_BUFFER)

// drivers\wdm\vbi\tests\testnab\testnab.cpp
#define READ_BUFFER_SIZE    sizeof(NABTSFEC_BUFFER)

// ds\adsi\include\netolary.hxx
#define DECLARE_ADsPTRARY(_Cls, _Ty, _pTy)                    \
    class _Cls : public CADsPtrAry                            \
    {                                                           \
    public:                                                     \
        _Cls(void) : CADsPtrAry() { ; }                       \
        _Ty& operator[] (int i) { return * (_pTy) Deref(sizeof(void *), i); } \
        operator _pTy(void) { return (_pTy) _pv; }              \
        _Cls(const _Cls &);                                     \
        _Cls& operator=(const _Cls &);                          \
    };

// ds\adsi\router\crowset.hxx
#define ADSI_BMK_SIZE (sizeof(RBOOKMARK))

// ds\dns\server\client\dnsc_wmi.cpp
    #define BLOCKSIZE                   ( 32 * sizeof( WCHAR ) )

// ds\dns\server\server\memory.c
#define SIZEOF_MEMHEAD      sizeof(MEMHEAD)

// ds\dns\server\server\msginfo.h
#define HAVE_MORE_ADDITIONAL_RECORDS( pAdd ) \
            ( (pAdd)->cCount > (pAdd)->iIndex )

// ds\dns\server\server\wins.h
#define SIZEOF_WINS_REQUEST     (sizeof(WINS_REQUEST_MSG))

// ds\dns\server\wmi\source\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// ds\ds\src\inc\_entryid.h
#define CBUSR_PERMID sizeof(USR_PERMID)

// ds\ds\src\inc\allocaln.h
#define allocalign(x) alloca((x+3)&(~3))
#define allocalign(x) alloca((x+1)&(~1))
#define PAD64(_size)            ((_size) + sizeof(ULONGLONG))

// ds\ds\src\inc\mdglobal.h
#define DsIsEqualGUID(rguid1, rguid2) (!memcmp(rguid1, rguid2, sizeof(GUID)))

// ds\ds\src\ism\include\memory.h
#define NEW_TYPE( type ) (type *) malloc( sizeof( type ) )
#define REALLOC_TYPE( p, type ) (type *) realloc( p, sizeof( type ) )
#define NEW_TYPE_ZERO( type ) (type *) calloc( 1, sizeof( type ) )

// ds\ds\src\ism\trnsprts\common\route.c
#define SiteTableCreate() TableCreate( SITE_HASH_TABLE_SIZE, sizeof( SITE_INSTANCE ) )

// ds\ds\src\ism\trnsprts\common\table.c
#define SiteTableCreate() TableCreate( SITE_HASH_TABLE_SIZE, sizeof( SITE_INSTANCE ) )

// ds\ds\src\kcc\sim\util.h
#define KCCSIM_NEW(x) \
    (x *) KCCSimAlloc (sizeof (x))
#define KCCSIM_THNEW(x) \
    (x *) KCCSimThreadAlloc (sizeof (x))

// ds\ds\src\ldap\client\debug.h
#define END_LOGGING             RELEASE_LOCK(&LoadLibLock)

// ds\ds\src\ldap\client\dnfilter\h225pp.h
#define SIZE_H225PP_Module_PDU_0 sizeof(RasMessage)
#define SIZE_H225PP_Module_PDU_1 sizeof(H323_UserInformation)

// ds\ds\src\ldap\client\dnfilter\ldap.h
#define SIZE_LDAP_Module_ID_0 sizeof(LDAPMessage)

// ds\ds\src\ldap\client\ping.cxx
#define ICMP_REPLY_BUFFER_SIZE (sizeof(ICMP_ECHO_REPLY) + 128)

// ds\ds\src\ntdsa\dblayer\dbconstr.c
#define END_TAG_SIZE              (sizeof(END_TAG) - sizeof(WCHAR))

// ds\ds\src\ntdsa\dra\draasync.c
#define SAME_UUID(a,b)                                  \
    ((NULL == (a))                                      \
     ? (NULL == (b))                                    \
     : ((NULL != (b)) && !memcmp(a,b,sizeof(GUID))))

// ds\ds\src\ntdsa\include\dramail.h
#define MAIL_REP_MSG_EXT_ALIGN  sizeof(LONGLONG)
#define MAIL_REP_MSG_DATA_ALIGN sizeof(LONGLONG)

// ds\ds\src\ntdsa\include\dsatools.h
#define HEAPCACHE_ALLOCATION_SIZE ((sizeof(HEAPCACHE)+CACHE_BLOCK_SIZE-1)/CACHE_BLOCK_SIZE*CACHE_BLOCK_SIZE)
#define SZUUID_LEN ((2*sizeof(UUID))+1)

// ds\ds\src\ntdsa\include\pek.h
#define ClearPekListSize(n) (sizeof(CLEAR_PEK_LIST)+(n-1)*sizeof(PEK))

// ds\ds\src\ntdsa\ldap\const.hxx
#define GET_ALIGNED_LENGTH(x) ((x+7) & ~7)

// ds\ds\src\ntdsa\ldap\ldapconv.cxx
#define NUM_KNOWNLIMITS (sizeof(KnownLimits)/sizeof(LIMIT_BLOCK) - 1)
#define NUM_KNOWNCONFSETS (sizeof(KnownConfSets)/sizeof(LIMIT_BLOCK) - 1)

// ds\ds\src\ntdsa\ldap\ldapcore.cxx
#define LDAP_PRES_ADD_PREFIX_SIZE (sizeof(LDAP_PRES_ADD_PREFIX)-1)
#define LDAP_DNPART_PREFIX_LEN    (sizeof(LDAP_DNPART_PREFIX)-1)
#define LDAP_ADDRESS_PREFIX_LEN   (sizeof(LDAP_ADDRESS_PREFIX)-1)

// ds\ds\src\ntdsa\src\dsatools.c
#define DNT_HASH_TABLE_SIZE         (    NUM_DNT_HASH_TABLE_ENTRIES \
                                      * sizeof( DNT_HASH_ENTRY )    \
                                    )

// ds\ds\src\ntdsa\src\mdbind.c
#define VERSIONSIZE (sizeof(gszVersion)-1)

// ds\ds\src\ntdsa\src\mdname.c
#define RoundToBlock(x)  (((x) + 7) & ~7)

// ds\ds\src\ntdsa\src\refcount.c
#define DSNAME_SAME_GUID_SID(a,b)                       \
    ((NULL != (a)) && (NULL != (b))                     \
     && !memcmp(&(a)->Guid, &(b)->Guid, sizeof(GUID))   \
     && ((a)->SidLen == (b)->SidLen)                    \
     && !memcmp(&(a)->Sid, &(b)->Sid, (a)->SidLen))

// ds\ds\src\ntdsa\src\servinfo.c
#define INC_AttrIndex AttrIndex++;                                                      \
                  if (AttrIndex>=cAllocated) {                                          \
                      cAllocated+=16;                                                   \
                      AttrVal = THReAllocEx(pTHS, AttrVal, cAllocated*sizeof(ATTRVAL)); \
                  }                                                                     \

// ds\ds\src\sam\server\dslayer.h
#define DEFINE_ATTRBLOCK1(_Name_, _AttrTypes_,_AttrValues_)\
ATTR    _AttrList_##_Name_[]=\
{\
    {_AttrTypes_[0], {1,&_AttrValues_[0]}}\
};\
ATTRBLOCK _Name_=\
{\
    sizeof(_AttrTypes_)/sizeof(_AttrTypes_[0]),\
    _AttrList_##_Name_\
}
#define DEFINE_ATTRBLOCK2(_Name_, _AttrTypes_,_AttrValues_)\
ATTR    _AttrList_##_Name_[]=\
{\
    {_AttrTypes_[0], {1,&_AttrValues_[0]}},\
    {_AttrTypes_[1], {1,&_AttrValues_[1]}}\
};\
ATTRBLOCK _Name_=\
{\
    sizeof(_AttrTypes_)/sizeof(_AttrTypes_[0]),\
    _AttrList_##_Name_\
}
#define DEFINE_ATTRBLOCK3(_Name_, _AttrTypes_,_AttrValues_)\
ATTR    _AttrList_##_Name_[]=\
{\
    {_AttrTypes_[0], {1,&_AttrValues_[0]}},\
    {_AttrTypes_[1], {1,&_AttrValues_[1]}},\
    {_AttrTypes_[2], {1,&_AttrValues_[2]}}\
};\
ATTRBLOCK _Name_=\
{\
    sizeof(_AttrTypes_)/sizeof(_AttrTypes_[0]),\
    _AttrList_##_Name_\
}
#define DEFINE_ATTRBLOCK4(_Name_, _AttrTypes_,_AttrValues_)\
ATTR    _AttrList_##_Name_[]=\
{\
    {_AttrTypes_[0], {1,&_AttrValues_[0]}},\
    {_AttrTypes_[1], {1,&_AttrValues_[1]}},\
    {_AttrTypes_[2], {1,&_AttrValues_[2]}},\
    {_AttrTypes_[3], {1,&_AttrValues_[3]}}\
};\
ATTRBLOCK _Name_=\
{\
    sizeof(_AttrTypes_)/sizeof(_AttrTypes_[0]),\
    _AttrList_##_Name_\
}
#define DEFINE_ATTRBLOCK5(_Name_, _AttrTypes_,_AttrValues_)\
ATTR    _AttrList_##_Name_[]=\
{\
    {_AttrTypes_[0], {1,&_AttrValues_[0]}},\
    {_AttrTypes_[1], {1,&_AttrValues_[1]}},\
    {_AttrTypes_[2], {1,&_AttrValues_[2]}},\
    {_AttrTypes_[3], {1,&_AttrValues_[3]}},\
    {_AttrTypes_[4], {1,&_AttrValues_[4]}}\
};\
ATTRBLOCK _Name_=\
{\
    sizeof(_AttrTypes_)/sizeof(_AttrTypes_[0]),\
    _AttrList_##_Name_\
}
#define DEFINE_ATTRBLOCK6(_Name_, _AttrTypes_,_AttrValues_)\
ATTR    _AttrList_##_Name_[]=\
{\
    {_AttrTypes_[0], {1,&_AttrValues_[0]}},\
    {_AttrTypes_[1], {1,&_AttrValues_[1]}},\
    {_AttrTypes_[2], {1,&_AttrValues_[2]}},\
    {_AttrTypes_[3], {1,&_AttrValues_[3]}},\
    {_AttrTypes_[4], {1,&_AttrValues_[4]}},\
    {_AttrTypes_[5], {1,&_AttrValues_[5]}}\
};\
ATTRBLOCK _Name_=\
{\
    sizeof(_AttrTypes_)/sizeof(_AttrTypes_[0]),\
    _AttrList_##_Name_\
}
#define DEFINE_ATTRBLOCK7(_Name_, _AttrTypes_,_AttrValues_)\
ATTR    _AttrList_##_Name_[]=\
{\
    {_AttrTypes_[0], {1,&_AttrValues_[0]}},\
    {_AttrTypes_[1], {1,&_AttrValues_[1]}},\
    {_AttrTypes_[2], {1,&_AttrValues_[2]}},\
    {_AttrTypes_[3], {1,&_AttrValues_[3]}},\
    {_AttrTypes_[4], {1,&_AttrValues_[4]}},\
    {_AttrTypes_[5], {1,&_AttrValues_[5]}},\
    {_AttrTypes_[6], {1,&_AttrValues_[6]}}\
};\
ATTRBLOCK _Name_=\
{\
    sizeof(_AttrTypes_)/sizeof(_AttrTypes_[0]),\
    _AttrList_##_Name_\
}

// ds\ds\src\sam\server\sdconvrt.h
#define ADMINISTRATOR_SID        (&(SampAdministratorsAliasSid))

// ds\ese98\eximport\exifs.h
#define WIN32_DIGIT_LEN             (sizeof(IOCTL_WIN32_FILENAME) - sizeof(IOCTL_WIN32_FILENAME_START))
#define UMRX_PREFIX_LEN             (sizeof(IOCTL_WIN32_UMRX_NAME)-2)

// ds\ese98\src\ese\db.cxx
#define PbNDBackLink(pb)											\
	( PbNDSonTable(pb) + ( FNDNullSon( *(pb) ) ? 0 :				\
	( ( ( *PbNDSonTable(pb) == 1 ) && FNDInvisibleSons( *(pb) ) ) ?	\
	sizeof(PGNO) + 1 : *PbNDSonTable(pb) + 1 ) ) )
#define PbNDData(pb) ( PbNDBackLink(pb) + ( FNDBackLink( *(pb) ) ? sizeof(SRID) : 0 ) )

// ds\inc\ndssntx.h
#define SIZE_OF_ASN1_1  sizeof( ASN1_TYPE_1 )
#define SIZE_OF_ASN1_2  sizeof( ASN1_TYPE_2 )
#define SIZE_OF_ASN1_3  sizeof( ASN1_TYPE_3 )
#define SIZE_OF_ASN1_4  sizeof( ASN1_TYPE_4 )
#define SIZE_OF_ASN1_5  sizeof( ASN1_TYPE_5 )
#define SIZE_OF_ASN1_6  sizeof( ASN1_TYPE_6 )
#define SIZE_OF_ASN1_7  sizeof( ASN1_TYPE_7 )
#define SIZE_OF_ASN1_8  sizeof( ASN1_TYPE_8 )
#define SIZE_OF_ASN1_9  sizeof( ASN1_TYPE_9 )
#define SIZE_OF_ASN1_10 sizeof( ASN1_TYPE_10 )
#define SIZE_OF_ASN1_11 sizeof( ASN1_TYPE_11 )
#define SIZE_OF_ASN1_12 sizeof( ASN1_TYPE_12 )
#define SIZE_OF_ASN1_13 sizeof( ASN1_TYPE_13 )
#define SIZE_OF_ASN1_14 sizeof( ASN1_TYPE_14 )
#define SIZE_OF_ASN1_15 sizeof( ASN1_TYPE_15 )
#define SIZE_OF_ASN1_16 sizeof( ASN1_TYPE_16 )
#define SIZE_OF_ASN1_17 sizeof( ASN1_TYPE_17 )
#define SIZE_OF_ASN1_18 sizeof( ASN1_TYPE_18 )
#define SIZE_OF_ASN1_19 sizeof( ASN1_TYPE_19 )
#define SIZE_OF_ASN1_20 sizeof( ASN1_TYPE_20 )
#define SIZE_OF_ASN1_21 sizeof( ASN1_TYPE_21 )
#define SIZE_OF_ASN1_22 sizeof( ASN1_TYPE_22 )
#define SIZE_OF_ASN1_23 sizeof( ASN1_TYPE_23 )
#define SIZE_OF_ASN1_24 sizeof( ASN1_TYPE_24 )
#define SIZE_OF_ASN1_25 sizeof( ASN1_TYPE_25 )
#define SIZE_OF_ASN1_26 sizeof( ASN1_TYPE_26 )
#define SIZE_OF_ASN1_27 sizeof( ASN1_TYPE_27 )

// ds\nameres\rnr\winrnr.c
#define GuidEqual(x,y)          RtlEqualMemory( x, y, sizeof(GUID) )

// ds\netapi\api\alert.c
#define TEMP_VARIABLE_SIZE (512-sizeof(STD_ALERT))

// ds\netapi\inc\ntfrsapi.h
#define NTFRSAPI_INFO_HEADER_SIZE   (5 * sizeof(ULONG))

// ds\netapi\netcmd\netcmd\comp.c
#define TRUST_ENUM_PERF_BUF_SIZE    sizeof(LSA_TRUST_INFORMATION) * 1000

// ds\netapi\rap\examine.c
#define UPDATE_WORST_ALIGNMENT(value)      \
    if ( (value) > worstAlignmentSoFar) {  \
       worstAlignmentSoFar = value;        \
    }

// ds\netapi\svcdlls\browser\client\browdeb.c
#define ClearNcb( PNCB ) {                                          \
    RtlZeroMemory( PNCB , sizeof (NCB) );                           \
    RtlCopyMemory( (PNCB)->ncb_name,     SPACES, sizeof(SPACES)-1 );\
    RtlCopyMemory( (PNCB)->ncb_callname, SPACES, sizeof(SPACES)-1 );\
    }

// ds\netapi\svcdlls\browser\common\utils.c
#define ClearNcb( PNCB ) {                                          \
    RtlZeroMemory( PNCB , sizeof (NCB) );                           \
    RtlCopyMemory( (PNCB)->ncb_name,     SPACES, sizeof(SPACES)-1 );\
    RtlCopyMemory( (PNCB)->ncb_callname, SPACES, sizeof(SPACES)-1 );\
    }

// ds\netapi\svcdlls\msgsvc\server\mesprint.c
#define SINGLE_SPACE_LEN    (sizeof("\n\r") - 1)

// ds\netapi\svcdlls\msgsvc\server\msginit.c
#define BOOKKEEPING_SIZE(n) (n * sizeof(NET_DATA))

// ds\netapi\svcdlls\srvsvc\server\srvsvcp.h
#define FIXED_SIZE_OF_SHARE(level)                  \
    ( (level) == 0 ? sizeof(SHARE_INFO_0) :         \
      (level) == 1 ? sizeof(SHARE_INFO_1) :         \
      (level) == 2 ? sizeof(SHARE_INFO_2) :         \
                     sizeof(SHARE_INFO_502) )

// ds\netapi\svcimgs\ntrepl\frs\frscomm.c
#define  COMM_SZ_UL        sizeof(ULONG)
#define  COMM_SZ_ULL       sizeof(ULONGLONG)
#define  COMM_SZ_GUID      sizeof(GUID)
#define  COMM_SZ_GUL       sizeof(GUID) + sizeof(ULONG)
#define  COMM_SZ_GVSN      sizeof(GVSN) + sizeof(ULONG)
#define  COMM_SZ_COC       sizeof(CHANGE_ORDER_COMMAND) + sizeof(ULONG)
#define  COMM_SZ_COEXT_W2K sizeof(CO_RECORD_EXTENSION_WIN2K) + sizeof(ULONG)
#define  COMM_SZ_MD5       MD5DIGESTLEN + sizeof(ULONG)

// ds\netapi\svcimgs\ntrepl\inc\frs.h
#define LOCK_GEN_TABLE(_vv_)                                \
    GTabLockTable(_vv_);                                    \
    DPRINT1(5, "LOCK_GEN_TABLE: "#_vv_":%08x\n", _vv_);

// ds\netapi\svcimgs\ntrepl\inc\frsalloc.h
#define REPLICA_NAME_CONFLICT_TABLE_SIZE   sizeof(QHASH_ENTRY)*100
#define NAME_SPACE_TABLE_SIZE              sizeof(QHASH_ENTRY)*100
#define FRS_WRITE_FILTER_SIZE              sizeof(QHASH_ENTRY)*100
#define RECOVERY_CONFLICT_TABLE_SIZE       sizeof(QHASH_ENTRY)*100
#define PARENT_FILEID_TABLE_SIZE           sizeof(QHASH_ENTRY)*500
#define ACTIVE_CHILDREN_TABLE_SIZE         sizeof(QHASH_ENTRY)*100
#define RsBlock(Cmd)        ((PUCHAR)Cmd->Parameters.UnionRs.Block)

// ds\netapi\svcimgs\ntrepl\inc\perrepsr.h
#define HASHTABLESIZE sizeof(QHASH_ENTRY)*100

// ds\netapi\svcimgs\ntrepl\inc\replutil.h
#define GUIDS_EQUAL(_a_, _b_) (memcmp((_a_), (_b_), sizeof(GUID)) == 0)
#define COPY_GUID(_a_, _b_)    CopyMemory((_a_), (_b_), sizeof(GUID))
#define QuadQuadAlignSize(Size) ((((ULONG)(Size)) + 31) & ~31)

// ds\netapi\svcimgs\ntrepl\inc\schema.h
#define FILE_OBJECTID_SIZE sizeof(FILE_OBJECTID_BUFFER)

// ds\netapi\svcimgs\ntrepl\repl\schema.c
#define CBJCC sizeof(JET_COLUMNCREATE)
#define CBJIC sizeof(JET_INDEXCREATE)
#define CBJTC sizeof(JET_TABLECREATE)

// ds\nw\convert\nwconv\vlist.h
#define VLB_UPDATEPAGE          (WM_USER+520)
#define VLB_PAGEDOWN            (WM_USER+524)
#define VLB_PAGEUP              (WM_USER+525)

// ds\nw\inc\nds.h
#define ROUNDUP4(x)                     ( ( (x) + 3 ) & ( ~3 ) )
#define ROUNDUP2(x)                     ( ( (x) + 1 ) & ( ~1 ) )

// ds\nw\ndsutils\utils.c
#define ROUNDUP4(x)         ( ( (x) + 3 ) & ( ~3 ) )

// ds\nw\nwlib\win95\nds95.h
#define ROUNDUP4(x) (((x)+3)&(~3))

// ds\nw\nwlib\win95\nwapi95.h
#define ROUNDUP4(x) (((x)+3)&(~3))

// ds\nw\nwscript\inc\nwlibs.h
#define PS_JOB_RECORD_SIZE      sizeof(PS_JOB_RECORD)

// ds\nw\nwscript\ps40db.c
#define PRINTCON_40_HEADER_SIZE    sizeof(PRINTCON_40_HEADER)
#define PRINTCON_41_HEADER_SIZE    sizeof(PRINTCON_41_HEADER)
#define JOB_NAME_AREA_SIZE       sizeof(JOB_NAME_AREA)
#define JOB_RECORD_AREA_SIZE    sizeof(JOB_RECORD_AREA)

// ds\nw\nwscript\psdb.c
#define PRINTCON_HEADER_SIZE    sizeof(PRINTCON_HEADER)
#define JOB_NAME_AREA_SIZE    sizeof(JOB_NAME_AREA)
#define JOB_RECORD_AREA_SIZE    sizeof(JOB_RECORD_AREA)

// ds\nw\rdr\procs.h
#define DIFFERENT_PAGES( START, SIZE ) \
    (((ULONG)START & ~(4096-1)) != (((ULONG)START + SIZE) & ~(4096-1)))

// ds\nw\svcdlls\nwwks\client\gtadrnr.c
#define GuidEqual(x,y) RtlEqualMemory(x, y, sizeof(GUID))
#define SIZENEEDED (sizeof(WSASERVICECLASSINFO) +   \
                    sizeof(WSANSCLASSINFO) + \
                    sizeof(WSANSCLASSINFO) + \
                    10 + 2                 + \
                    sizeof(GUID) +  12 + 2)

// ds\security\common\cryptdll\deswrap.c
#define XORBLOCK(x,y) \
{ \
    PULONG tx = (PULONG) x; \
    PULONG ty = (PULONG) y; \
    *tx++ ^= *ty++; \
    *tx++ ^= *ty++; \
}

// ds\security\cryptoapi\common\ossutil\ossutil.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\common\pkiutil\pkiasn1.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\activex\xenroll\xasnx.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\activex\xenroll\xmsasnx.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\certstor\certhlpr.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\certstor\certstr.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\certstor\newstor.cpp
#define ENCODE_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\certstor\oidconv.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\certstor\oidfunc.cpp
#define LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\certstor\oidinfo.cpp
#define LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\certstor\wincert.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\pfxlib\encdecpk.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\pfxlib\impexppk.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\pfxlib\pfxhelp.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\setx509\setx509.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pki\wincrmsg\crmsgp.h
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pkitrust\mssip32\sipobjcb.hxx
#define RESERVE_LEN_ALIGN(Len)  ((Len + 3) & ~3)        // all abReserve is alligned @ 4

// ds\security\cryptoapi\pkitrust\softpub\expapis.cpp
#define ALIGN_LEN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pkitrust\wintrust\ossfunc.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\cryptoapi\pkitrust\wintrust\wtasn.h
#define SIZE_WTASN_Module_PDU_13 sizeof(SpcSpAgencyInformation)

// ds\security\inc\cnvcrypt.h
#define CertEncode(dwEncodingType, pbEncodedToBeSigned, cbEncodedToBeSigned, \
        pSignatureAlgorithm, pbSignature, cbSignature, pAdditionalInfo, \
        pbEncoded, pcbEncoded) \
    CryptEncodeObject(dwEncodingType, X509_CERT, &CertSignedContentInfo, \
        pbEncoded, pcbEncoded)
#define CertDecode(dwEncodingType, pbEncoded, cbEncoded, \
        pSignatureAlgorithm, pcbSignatureAlgorithm, \
        ppbSignature, pcbSignature, \
        ppbEncodedToBeSigned, pcbEncodedToBeSigned, \
        pAdditionalInfo, pcbAdditionalInfo) \
    CryptDecodeObject(dwEncodingType, X509_CERT, pbEncoded, cbEncoded, 0, \
        pCertSignedContentInfo, &cbCertSignedContentInfo)

// ds\security\inc\dsysdbg.h
#define DECLARE_DEBUG2(comp)                                \
extern PVOID    comp##ControlBlock;                         \
extern DWORD    comp##InfoLevel;                            \
void   comp##DebugPrint(ULONG Mask, CHAR * Format, ... );   \

// ds\security\passport\atlmfc\asptlb.h
#define IResponse_WriteBlock(This,iBlockNumber)	\
    (This)->lpVtbl -> WriteBlock(This,iBlockNumber)
#define ISessionObject_get_CodePage(This,plvar)	\
    (This)->lpVtbl -> get_CodePage(This,plvar)
#define ISessionObject_put_CodePage(This,lvar)	\
    (This)->lpVtbl -> put_CodePage(This,lvar)

// ds\security\passport\atlmfc\atlcom.h
#define END_PROP_VAL_MAP() \
		}; \
		if (cnt)	\
			*cnt = sizeof(pPropMap)/sizeof(pPropMap[0]);	\
		return pPropMap; \
	}
#define BEGIN_PROPERTY_MAP(theClass) \
	__if_not_exists(__ATL_PROP_NOTIFY_EVENT_CLASS) \
	{ \
		typedef ATL::_ATL_PROP_NOTIFY_EVENT_CLASS __ATL_PROP_NOTIFY_EVENT_CLASS; \
	} \
	typedef theClass _PropMapClass; \
	static ATL::ATL_PROPMAP_ENTRY* GetPropertyMap()\
	{\
		static ATL::ATL_PROPMAP_ENTRY pPropMap[] = \
		{ \
			{OLESTR("_cx"), 0, &CLSID_NULL, NULL, offsetof(_PropMapClass, m_sizeExtent.cx), sizeof(long), VT_UI4}, \
			{OLESTR("_cy"), 0, &CLSID_NULL, NULL, offsetof(_PropMapClass, m_sizeExtent.cy), sizeof(long), VT_UI4},
#define PROP_PAGE(clsid) \
		{NULL, NULL, &clsid, &IID_NULL, 0, 0, 0},
#define DECLARE_REGISTRY_RESOURCE(x)\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) throw()\
	{\
		__if_exists(_GetMiscStatus) \
		{ \
			ATL::_ATL_REGMAP_ENTRY regMapEntries[2]; \
			memset(&regMapEntries[1], 0, sizeof(ATL::_ATL_REGMAP_ENTRY)); \
			regMapEntries[0].szKey = L"OLEMISC"; \
			TCHAR szOleMisc[10]; \
			wsprintf(szOleMisc, _T("%d"), _GetMiscStatus()); \
			USES_CONVERSION; \
			regMapEntries[0].szData = T2OLE(szOleMisc); \
			__if_exists(_Module) \
			{ \
				return _Module.UpdateRegistryFromResource(_T(#x), bRegister, regMapEntries); \
			} \
			__if_not_exists(_Module) \
			{ \
				return ATL::_pAtlModule->UpdateRegistryFromResource(_T(#x), bRegister, regMapEntries); \
			} \
		} \
		__if_not_exists(_GetMiscStatus) \
		{ \
			__if_exists(_Module) \
			{ \
				return _Module.UpdateRegistryFromResource(_T(#x), bRegister); \
			} \
			__if_not_exists(_Module) \
			{ \
				return ATL::_pAtlModule->UpdateRegistryFromResource(_T(#x), bRegister); \
			} \
		} \
	}
#define DECLARE_REGISTRY_RESOURCEID(x)\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) throw()\
	{\
		__if_exists(_GetMiscStatus) \
		{ \
			ATL::_ATL_REGMAP_ENTRY regMapEntries[2]; \
			memset(&regMapEntries[1], 0, sizeof(ATL::_ATL_REGMAP_ENTRY)); \
			regMapEntries[0].szKey = L"OLEMISC"; \
			TCHAR szOleMisc[10]; \
			wsprintf(szOleMisc, _T("%d"), _GetMiscStatus()); \
			USES_CONVERSION; \
			regMapEntries[0].szData = T2OLE(szOleMisc); \
			__if_exists(_Module) \
			{ \
				return _Module.UpdateRegistryFromResource(x, bRegister, regMapEntries); \
			} \
			__if_not_exists(_Module) \
			{ \
				return ATL::_pAtlModule->UpdateRegistryFromResource(x, bRegister, regMapEntries); \
			} \
		} \
		__if_not_exists(_GetMiscStatus) \
		{ \
			__if_exists(_Module) \
			{ \
				return _Module.UpdateRegistryFromResource(x, bRegister); \
			} \
			__if_not_exists(_Module) \
			{ \
				return ATL::_pAtlModule->UpdateRegistryFromResource(x, bRegister); \
			} \
		} \
	}
#define END_CONNECTION_POINT_MAP() \
	__if_exists(GetAttrConnMap) \
	{ \
		{(DWORD_PTR) -2}, \
		{(DWORD_PTR) GetAttrConnMap }, \
	} \
	{(DWORD_PTR)-1} }; \
	if (pnEntries) \
	{ \
		__if_exists(GetAttrConnMap) \
		{ \
			GetAttrConnMap(pnEntries); \
			*pnEntries += sizeof(_entries)/sizeof(ATL::_ATL_CONNMAP_ENTRY) - 3; \
		} \
		__if_not_exists(GetAttrConnMap) \
		{ \
		*pnEntries = sizeof(_entries)/sizeof(ATL::_ATL_CONNMAP_ENTRY) - 1; \
		} \
	} \
	return _entries;}
#define END_ATTRCONNECTION_POINT_MAP() \
	{(DWORD_PTR)-1} }; \
	if (pnEntries) \
	{ \
		*pnEntries = sizeof(_entries)/sizeof(ATL::_ATL_CONNMAP_ENTRY) - 1; \
	} \
	return _entries;}

// ds\security\passport\atlmfc\atliface.h
#define IAxWinAmbientDispatch_put_BackColor(This,clrBackground)	\
    (This)->lpVtbl -> put_BackColor(This,clrBackground)
#define IAxWinAmbientDispatch_get_BackColor(This,pclrBackground)	\
    (This)->lpVtbl -> get_BackColor(This,pclrBackground)
#define IAxWinAmbientDispatch_put_ForeColor(This,clrForeground)	\
    (This)->lpVtbl -> put_ForeColor(This,clrForeground)
#define IAxWinAmbientDispatch_get_ForeColor(This,pclrForeground)	\
    (This)->lpVtbl -> get_ForeColor(This,pclrForeground)
#define IAxWinAmbientDispatchEx_put_BackColor(This,clrBackground)	\
    (This)->lpVtbl -> put_BackColor(This,clrBackground)
#define IAxWinAmbientDispatchEx_get_BackColor(This,pclrBackground)	\
    (This)->lpVtbl -> get_BackColor(This,pclrBackground)
#define IAxWinAmbientDispatchEx_put_ForeColor(This,clrForeground)	\
    (This)->lpVtbl -> put_ForeColor(This,clrForeground)
#define IAxWinAmbientDispatchEx_get_ForeColor(This,pclrForeground)	\
    (This)->lpVtbl -> get_ForeColor(This,pclrForeground)

// ds\security\passport\atlmfc\atlperf.h
#define DECLARE_PERF_OBJECT(objectclass, dwObjectId, namestring, helpstring, defcounter) \
	DECLARE_PERF_OBJECT_EX(dwObjectId, namestring, helpstring, PERF_DETAIL_NOVICE, 0, sizeof(objectclass), ATLPERF_DEFAULT_MAXINSTNAMELENGTH, defcounter)
#define DECLARE_PERF_OBJECT_NO_INSTANCES(objectclass, dwObjectId, namestring, helpstring, defcounter) \
	DECLARE_PERF_OBJECT_EX(dwObjectId, namestring, helpstring, PERF_DETAIL_NOVICE, PERF_NO_INSTANCES, sizeof(objectclass), 0, defcounter)

// ds\security\passport\atlmfc\atlwin.h
#define DECLARE_WND_CLASS(WndClassName) \
static ATL::CWndClassInfo& GetWndClassInfo() \
{ \
	static ATL::CWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(COLOR_WINDOW + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T("") \
	}; \
	return wc; \
}
#define DECLARE_WND_CLASS_EX(WndClassName, style, bkgnd) \
static ATL::CWndClassInfo& GetWndClassInfo() \
{ \
	static ATL::CWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), style, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(bkgnd + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T("") \
	}; \
	return wc; \
}
#define DECLARE_WND_SUPERCLASS(WndClassName, OrigWndClassName) \
static ATL::CWndClassInfo& GetWndClassInfo() \
{ \
	static ATL::CWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), 0, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, NULL, NULL, WndClassName, NULL }, \
		OrigWndClassName, NULL, NULL, TRUE, 0, _T("") \
	}; \
	return wc; \
}

// ds\security\passport\atlmfc\bmio.h
#define IBitmapTarget_SetBackgroundColor(This,pColor)	\
    (This)->lpVtbl -> SetBackgroundColor(This,pColor)

// ds\security\passport\common\crypt\sha.cpp
#define blk0(i) (block->l[i] = (rol(block->l[i],24)&0xFF00FF00) \
    |(rol(block->l[i],8)&0x00FF00FF))
#define blk(i) (block->l[i&15] = rol(block->l[(i+13)&15]^block->l[(i+8)&15] \
    ^block->l[(i+2)&15]^block->l[i&15],1))

// ds\security\protocols\digest\auth.h
#define MAC_BLOCK_SIZE   sizeof(SASL_MAC_BLOCK)

// ds\security\protocols\kerberos\client2\kerblist.h
#define KerbLockList(_List_) RtlEnterCriticalSection(&(_List_)->Lock)

// ds\security\protocols\kerberos\client2\rpcutil.cxx
#define KerbLockKdcData() (RtlEnterCriticalSection(&KerbCallKdcDataLock))

// ds\security\protocols\kerberos\client2\spncache.cxx
#define KerbWriteLockSpnCache()                         KerbLockList(&KerbSpnCache);
#define KerbReadLockSpnCache()                          KerbLockList(&KerbSpnCache);

// ds\security\protocols\kerberos\kernel\kerblist.h
#define KerbLockList(_List_)                                \
{                                                           \
    KeEnterCriticalRegion();                                \
    ExAcquireResourceExclusiveLite(&(_List_)->Lock, TRUE ); \
}

// ds\security\protocols\kerberos\server\pkserv.cxx
#define MAX_TEMPLATE_NAME_VALUE_SIZE             80 // sizeof (CERT_NAME_VALUE) + wcslen(SmartcardLogon)

// ds\security\protocols\schannel\pkiutil\pkiasn1.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// ds\security\services\ca\certlib\keygen2.cpp
#define INFO_LEN_ALIGN(Len)  (((Len) + 7) & ~7)

// ds\security\services\ca\exit\default\exit.cpp
#define cbVALUEZEROPAD     (3 * sizeof(WCHAR))

// ds\security\services\ca\ocmsetup\wizpage.cpp
#define NUM_SERVERWIZPAGES  sizeof(aWizPageResources)/sizeof(WIZPAGERESENTRY)

// ds\security\services\ca\tools\certut\reg.cpp
#define cbVALUEZEROPAD	(3 * sizeof(WCHAR))

// ds\security\services\ca\tools\tcertcli\auto\autoenrl.c
#define MAX_TEMPLATE_NAME_VALUE_SIZE             64 // sizeof (CERT_NAME_VALUE) + wcslen(wszCERTTYPE_DC)
#define MAX_KEY_USAGE_SIZE  20   // sizeof(CRYPT_BIT_BLOB) for 64bit + sizeof(DWORD)

// ds\security\tools\keytab2\opt\options.h
#define OPT_NOHEADER ( OPT_NOSWITCH | OPT_NOCOMMAND | OPT_NOALIGN | \
		       OPT_NOSEPARATOR )

// ds\win32\ntcrypto\contman\contman.c
#define RSA_REG_KEY_LOC_LEN     sizeof(RSA_REG_KEY_LOC)
#define RSA_MACH_REG_KEY_LOC_LEN sizeof(RSA_MACH_REG_KEY_LOC)
#define DSS_REG_KEY_LOC_LEN     sizeof(DSS_REG_KEY_LOC)
#define DSS_MACH_REG_KEY_LOC_LEN sizeof(DSS_MACH_REG_KEY_LOC)

// ds\win32\ntcrypto\programs\dssinstl\dssinstl.c
#define PROVPATH_LEN    sizeof(PROVPATH)
#define TYPEPATH_LEN    sizeof(TYPEPATH)
#define IMAGEPATH_LEN    sizeof(IMAGEPATH)

// ds\win32\ntcrypto\rsaaes\manage.c
#define PROVPATH_LEN        sizeof(PROVPATH)
#define TYPEPATH_LEN        sizeof(TYPEPATH)

// ds\win32\ntcrypto\rsaaes\ntagum.c
#define NTAG_DEF_MACH_CONT_NAME_LEN sizeof(NTAG_DEF_MACH_CONT_NAME)

// ds\win32\ntcrypto\rsaaes\swnt_pk.c
#define GetNextAlignedValue(c, alignment)   ((c + alignment) & ~(alignment - 1))

// ds\xpress\xdecode.c
  #define RESERVE_DST ((8 * 8 + 2) * sizeof (tag_t))
  #define RESERVE_SRC ((7 * 8 + 2) * sizeof (tag_t))

// ds\xpress\xprs.h
#define CRC_STAMP_SIZE  sizeof (uint32)

// enduser\mapistub\mapistub\_mapiu.h
#define FBadIfacePtr(param, iface)                                      \
                (       IsBadReadPtr((param), sizeof(iface))    \
                 ||     IsBadReadPtr((param)->lpVtbl, sizeof(iface##Vtbl)))

// enduser\mapistub\mapistub\mapidefs.h
#define IsEqualMAPIUID(lpuid1, lpuid2)	(!memcmp(lpuid1, lpuid2, sizeof(MAPIUID)))

// enduser\mapistub\mapistub\unkobj.h
#define IsEqualGUID(a, b)			(memcmp((a), (b), sizeof(GUID)) == 0)

// enduser\netmeeting\as\h\dcg.h
#define FIELD_SIZE(type, field)   (sizeof(((type FAR *)0L)->field))
#define DC_ROUND_UP_4(x)  (((x) + 3L) & ~(3L))

// enduser\netmeeting\as\h\oa.h
#define INT_ORDER_SIZE(pOrder) \
(pOrder->OrderHeader.Common.cbOrderDataLength + sizeof(INT_ORDER_HEADER))

// enduser\netmeeting\as\h\om.h
#define GET_NEXT_OBJECT_ID(objectID, pDomain, pomPrimary)                 \
   (objectID).creator     = pDomain->userID;                             \
   (objectID).sequence    = pomPrimary->objectIDsequence++;                  \
   (objectID).pad1        = 0
#define OBJECT_IDS_ARE_EQUAL(objectID1, objectID2)                          \
                                                                            \
   (memcmp(&(objectID1), &(objectID2), sizeof(OM_OBJECT_ID)) == 0)

// enduser\netmeeting\as\h\osi.h
#define SHM_SIZE_USED   (sizeof(SHM_SHARED_MEMORY) + 2*sizeof(OA_SHARED_DATA))

// enduser\netmeeting\as\h\t_share.h
#define COM_ORDER_SIZE(pOrder) \
    (pOrder->OrderHeader.cbOrderDataLength + sizeof(COM_ORDER_HEADER))

// enduser\netmeeting\as\h\wb.hpp
#define WB_SYNC_CONTROL_SIZE (sizeof(OM_OBJECT_ID) + WB_SYNC_SIZE)
#define QUIT_GRAPHIC_LOCKED(hPage, hGraphic, result)                \
  {                                                                          \
    POM_OBJECT pObjPerson;                                              \
    if (wbGraphicLocked(hPage, hGraphic, &pObjPerson))    \
    {                                                                        \
      if (pObjPerson != m_pObjLocal)                             \
      {                                                                      \
          result = WB_RC_GRAPHIC_LOCKED;                                     \
          DC_QUIT;                                                           \
      }                                                                      \
    }                                                                        \
  }

// enduser\netmeeting\av\callcont\ccmain.h
#define NUM_TERMINAL_ALLOCATION_SLOTS	24		// 24*sizeof(BYTE) = 192 = max. terminal number
#define NUM_CHANNEL_ALLOCATION_SLOTS	32		// 32*sizeof(BYTE) = 256 = max. channel number

// enduser\netmeeting\av\callcont\h225asn.h
#define SIZE_H225ASN_Module_PDU_0 sizeof(RasMessage)
#define SIZE_H225ASN_Module_PDU_1 sizeof(H323_UserInformation)

// enduser\netmeeting\av\callcont\h245asn.h
#define SIZE_H245ASN_Module_PDU_0 sizeof(FastConnectOLC)

// enduser\netmeeting\av\codecs\dec\dech263\getpic.c
#define clearblk(comp) memset(H263Info->block[comp], 0, sizeof(int [66]));

// enduser\netmeeting\av\codecs\intel\h261\d1bvriq.cpp
#define LOCALSIZE           ((128+3)&~3)             // keep aligned

// enduser\netmeeting\av\codecs\intel\h261\d1idct.cpp
#define LOCALSIZE		    ((512+3)&~3)		     // keep aligned

// enduser\netmeeting\av\intelcc\include\gkpdu.h
#define SIZE_GKPDU_Module_PDU_0 sizeof(RasMessage)

// enduser\netmeeting\av\nac\inscodec.h
#define COMPARE_GUIDS(a,b)	RtlEqualMemory((a), (b), sizeof(GUID))

// enduser\netmeeting\av\nac\utils.h
#define SIZEOF_WAVEFORMATEX(pwfx)   ((WAVE_FORMAT_PCM==(pwfx)->wFormatTag)?sizeof(PCMWAVEFORMAT):(sizeof(WAVEFORMATEX)+(pwfx)->cbSize))

// enduser\netmeeting\av\qos\qosint.h
#define COMPARE_GUIDS(a,b)	RtlEqualMemory((a), (b), sizeof(GUID))

// enduser\netmeeting\h\confguid.h
#define CB_H221_GUIDKEY    (5 + sizeof(GUID))

// enduser\netmeeting\h\t120\mcspdu.h
#define SIZE_MCSPDU_Module_PDU_0 sizeof(ConnectMCSPDU)
#define SIZE_MCSPDU_Module_PDU_1 sizeof(DomainMCSPDU)

// enduser\netmeeting\t120\h\gccpdu.h
#define SIZE_GCCPDU_Module_PDU_0 sizeof(ConnectData)
#define SIZE_GCCPDU_Module_PDU_1 sizeof(ConnectGCCPDU)
#define SIZE_GCCPDU_Module_PDU_2 sizeof(GCCPDU)

// enduser\netmeeting\t120\h\ms_util.h
#define ROUNDTOBOUNDARY(num)	(((UINT)(num) + 0x03) & 0xfffffffcL)

// enduser\netmeeting\t120\mst120\cnppdu.h
#define SIZE_CNPPDU_Module_PDU_0 sizeof(CNPPDU)

// enduser\netmeeting\t120\mst123\memmgr2.h
#define EXPAND_TO_PAGE_BOUNDARY(p)	(((p) + dwSystemPageSize - 1) & (~ (dwSystemPageSize - 1)))

// enduser\netmeeting\ui\wb\t126.h
#define SIZE_T126_Module_PDU_0 sizeof(SIPDU)

// enduser\speech\ce\public\sdk\inc\crtdbg.h
#define _BLOCK_TYPE(block)          (block & 0xFFFF)
#define _BLOCK_SUBTYPE(block)       (block >> 16 & 0xFFFF)

// enduser\speech\ce\public\sdk\inc\wincestub.h
#define UNALIGNED_PROPERTY( propertytype, propertyname) propertytype internal_##propertyname; \
    __declspec( property( get=get_##propertyname, put=put_##propertyname ) ) propertytype propertyname; \
	inline void put_##propertyname( propertytype newvalue) { CopyMemory( &internal_##propertyname, &newvalue, sizeof(propertytype));};  \
	inline propertytype get_##propertyname ( ) { propertytype value; CopyMemory( &value, &internal_##propertyname, sizeof(propertytype)); return value;};

// enduser\speech\external\include\tapi3.h
#define ITAgent_CreateSession(This,pACDGroup,pAddress,ppAgentSession)	\
    (This)->lpVtbl -> CreateSession(This,pACDGroup,pAddress,ppAgentSession)
#define ITAgent_CreateSessionWithPIN(This,pACDGroup,pAddress,pPIN,ppAgentSession)	\
    (This)->lpVtbl -> CreateSessionWithPIN(This,pACDGroup,pAddress,pPIN,ppAgentSession)
#define ITAgent_get_State(This,pAgentState)	\
    (This)->lpVtbl -> get_State(This,pAgentState)
#define ITAgentSession_get_Agent(This,ppAgent)	\
    (This)->lpVtbl -> get_Agent(This,ppAgent)
#define ITAgentEvent_get_Agent(This,ppAgent)	\
    (This)->lpVtbl -> get_Agent(This,ppAgent)
#define ITAgentHandlerEvent_get_AgentHandler(This,ppAgentHandler)	\
    (This)->lpVtbl -> get_AgentHandler(This,ppAgentHandler)
#define ITAgentHandler_CreateAgent(This,ppAgent)	\
    (This)->lpVtbl -> CreateAgent(This,ppAgent)
#define ITAgentHandler_CreateAgentWithID(This,pID,pPIN,ppAgent)	\
    (This)->lpVtbl -> CreateAgentWithID(This,pID,pPIN,ppAgent)

// enduser\speech\sapi\cpl\tom.h
#define ITextDocument_Open(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Open(This,pVar,Flags,CodePage)
#define ITextDocument_Save(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Save(This,pVar,Flags,CodePage)
#define ITextPara_GetAlignment(This,pValue)	\
    (This)->lpVtbl -> GetAlignment(This,pValue)
#define ITextPara_SetAlignment(This,Value)	\
    (This)->lpVtbl -> SetAlignment(This,Value)
#define ITextPara_GetListAlignment(This,pValue)	\
    (This)->lpVtbl -> GetListAlignment(This,pValue)
#define ITextPara_SetListAlignment(This,Value)	\
    (This)->lpVtbl -> SetListAlignment(This,Value)
#define ITextPara_GetPageBreakBefore(This,pValue)	\
    (This)->lpVtbl -> GetPageBreakBefore(This,pValue)
#define ITextPara_SetPageBreakBefore(This,Value)	\
    (This)->lpVtbl -> SetPageBreakBefore(This,Value)
#define ITextPara_AddTab(This,tbPos,tbAlign,tbLeader)	\
    (This)->lpVtbl -> AddTab(This,tbPos,tbAlign,tbLeader)
#define ITextPara_GetTab(This,iTab,ptbPos,ptbAlign,ptbLeader)	\
    (This)->lpVtbl -> GetTab(This,iTab,ptbPos,ptbAlign,ptbLeader)
#define ITextDocument2_Open(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Open(This,pVar,Flags,CodePage)
#define ITextDocument2_Save(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Save(This,pVar,Flags,CodePage)
#define ITextDocument2_GetPreferredFont(This,cp,CodePage,Option,pbstr,pPitchAndFamily)	\
    (This)->lpVtbl -> GetPreferredFont(This,cp,CodePage,Option,pbstr,pPitchAndFamily)

// enduser\speech\sapi\include\spddkhlp.h
#define STACK_ALLOC(TYPE, COUNT) (TYPE *)_alloca(sizeof(TYPE) * (COUNT))
#define STACK_ALLOC_AND_ZERO(TYPE, COUNT) (TYPE *)memset(_alloca(sizeof(TYPE) * (COUNT)), 0, (sizeof(TYPE) * (COUNT)))
#define STACK_ALLOC_AND_COPY(TYPE, COUNT, SOURCE) (TYPE *)memcpy(_alloca(sizeof(TYPE) * (COUNT)), (SOURCE), (sizeof(TYPE) * (COUNT)))

// enduser\stuff\atl30\atliface.h
#define IAxWinAmbientDispatch_put_BackColor(This,clrBackground)	\
    (This)->lpVtbl -> put_BackColor(This,clrBackground)
#define IAxWinAmbientDispatch_get_BackColor(This,pclrBackground)	\
    (This)->lpVtbl -> get_BackColor(This,pclrBackground)
#define IAxWinAmbientDispatch_put_ForeColor(This,clrForeground)	\
    (This)->lpVtbl -> put_ForeColor(This,clrForeground)
#define IAxWinAmbientDispatch_get_ForeColor(This,pclrForeground)	\
    (This)->lpVtbl -> get_ForeColor(This,pclrForeground)

// enduser\stuff\hhctrl\localsrv.h
#define PROPERTYPAGE(name)	   { OI_PROPERTYPAGE, (void *)&(name##Page) }

// enduser\stuff\hhctrl\mvopsys.h
#define GETMBHD(p,q) QvCopy((p),(q), sizeof(MBHD))
#define GETMFCP(p,q) QvCopy((p),(q), sizeof(MFCP))
#define GETMBHD(p,q) QvCopy((p),(q), sizeof(MBHD))
#define GETMFCP(p,q) QvCopy((p),(q), sizeof(MFCP))

// enduser\stuff\hhctrl\proppage.h
#define PPM_NEWOBJECTS    (WM_USER + 100)
#define PPM_APPLY         (WM_USER + 101)
#define PPM_EDITPROPERTY  (WM_USER + 102)

// enduser\stuff\itircl\common\util\dynarray.c
#define DYN_ARRAY_SIZEOF_NEXT(lpdl)     ( DYN_ARRAY_IS_SINGLE_BLOCK(lpdl) ? 0: sizeof(LPVOID))

// enduser\stuff\itircl\fts\search\search.h
#define STRING_BLOCK_SIZE   (sizeof(STRING_TOKEN) + 6) * 20
#define QUERY_BLOCK_SIZE    sizeof(QTNODE)*16

// enduser\stuff\itircl\inc\_mvutil.h
#define CbCacheBlock( qbthr ) \
      ( sizeof( CACHE_BLOCK ) - sizeof( DISK_BLOCK ) + (qbthr)->bth.cbBlock )
#define QCacheBlock( qbthr, wLevel ) \
        ((QCB)( (qbthr)->qCache + (wLevel) * CbCacheBlock( qbthr ) ))
#define LcbFromBk(x) ((LONG)sizeof( short ) + x * sizeof( MAPREC ))

// enduser\stuff\itircl\inc\dynarray.h
#define CALC_BLOCK_SIZE(x, y) (sizeof(x) * (y))
#define DynArrayInitDef(lpdl, s, wAvg) \
		DynArrayInit(lpdl, CALC_BLOCK_SIZE(s, wAvg), DEFAULT_BLOCK_MAX, sizeof(s), 0)

// enduser\stuff\itircl\inc\misc.h
#define LSizeOf( t )	         (LONG)sizeof( t )

// enduser\stuff\itircl\inc\mvopsys.h
#define GETMBHD(p,q) QvCopy((p),(q), sizeof(MBHD))
#define GETMFCP(p,q) QvCopy((p),(q), sizeof(MFCP))
#define GETMBHD(p,q) QvCopy((p),(q), sizeof(MBHD))
#define GETMFCP(p,q) QvCopy((p),(q), sizeof(MFCP))

// enduser\windows.com\inc\asptlb.h
#define IResponse_WriteBlock(This,iBlockNumber)	\
    (This)->lpVtbl -> WriteBlock(This,iBlockNumber)
#define ISessionObject_get_CodePage(This,plvar)	\
    (This)->lpVtbl -> get_CodePage(This,plvar)
#define ISessionObject_put_CodePage(This,lvar)	\
    (This)->lpVtbl -> put_CodePage(This,lvar)

// enduser\windows.com\iuengine\sysspec.cpp
#define SIZEOF_DRIVERVER sizeof(SZ_UNKNOWN_DRIVERVER)

// enduser\windows.com\iuengine\wubios\inc\configmg.h
#define	SIZEOF_DMA		sizeof(DMA_DES)
#define	SIZEOF_IRQ		sizeof(IRQ_DES)

// enduser\windows.com\iuengine\wubios\inc\vmm.h
#define PAGEOUT_ALL	(PAGEOUT_PRIVATE | PAGEOUT_SHARED | PAGEOUT_SYSTEM)

// inetcore\connectionwizard\icwconn1\reboot.cpp
#define MB_MYERROR (MB_APPLMODAL | MB_ICONERROR | MB_SETFOREGROUND)

// inetcore\connectionwizard\icwconn2\globals.h
#define LEN_CONNECTOID           sizeof(CMD_CONNECTOID)
#define LEN_INS                  sizeof(CMD_INS)
#define MB_MYERROR               (MB_APPLMODAL | MB_ICONERROR | MB_SETFOREGROUND)

// inetcore\connectionwizard\icwdial\globals.h
#define MB_MYERROR (MB_APPLMODAL | MB_ICONERROR | MB_SETFOREGROUND)

// inetcore\connectionwizard\icwdl\download.h
#define SIGNUP_LEN              (sizeof(SIGNUP)-1)
#define SYSTEM_LEN              (sizeof(SYSTEM)-1)
#define WINDOWS_LEN             (sizeof(WINDOWS)-1)
#define TEMP_LEN                (sizeof(TEMP)-1)
#define ICW98DIR_LEN            (sizeof(ICW98DIR)-1)
#define MULTIPART_MIXED_LEN     (sizeof(MULTIPART_MIXED)-1)
#define CONTENT_DISPOSITION_LEN (sizeof(CONTENT_DISPOSITION)-1)
#define FILENAME_LEN            (sizeof(FILENAME)-1)
#define INLINE_LEN              (sizeof(INLINE)-1)
#define ATTACHMENT_LEN          (sizeof(ATTACHMENT)-1)
#define DOUBLE_CRLF_LEN         (sizeof(DOUBLE_CRLF)-1)

// inetcore\connectionwizard\icwhelp\icwglob.h
#define MB_MYERROR (MB_APPLMODAL | MB_ICONERROR | MB_SETFOREGROUND)
#define MB_MYINFORMATION (MB_APPLMODAL | MB_ICONINFORMATION | MB_SETFOREGROUND)
#define MB_MYEXCLAMATION (MB_APPLMODAL | MB_ICONEXCLAMATION | MB_SETFOREGROUND)

// inetcore\connectionwizard\icwhelp\inshandler.cpp
#define CLIENT_SIZE(elem)      sizeof(((LPINETCLIENTINFO)(NULL))->elem)

// inetcore\connectionwizard\icwphbk\suapi.cpp
#define MB_MYERROR (MB_APPLMODAL | MB_ICONERROR | MB_SETFOREGROUND)

// inetcore\connectionwizard\inc\icwhelp.h
#define IWebGate_FetchPage(This,dwKeepPage,dwDoWait,pbRetVal)	\
    (This)->lpVtbl -> FetchPage(This,dwKeepPage,dwDoWait,pbRetVal)

// inetcore\connectionwizard\isign32\client.cpp
#define CLIENT_SIZE(elem)      sizeof(((LPINETCLIENTINFO)(NULL))->elem)

// inetcore\connectionwizard\mapi\inc\mapidefs.h
#define IsEqualMAPIUID(lpuid1, lpuid2)  (!memcmp(lpuid1, lpuid2, sizeof(MAPIUID)))

// inetcore\connectionwizard\mapi\inc\mapiwin.h
#define HexCchOf(_s)    (sizeof(_s)*2+1)

// inetcore\digest\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// inetcore\digest\digest.hxx
#define AUTH_LEN sizeof(AUTH_SZ) - 1

// inetcore\digest\mmfile.hxx
#define MMF_SIG_SIZE    sizeof(MMF_SIG_SZ)

// inetcore\mshtml\src\core\include\cdutil.hxx
#define SIZE_OF(s, m) sizeof(((s *)0)->m)
#define CALL_METHOD(pObj,pfnMethod,args) \
    ((CMethodThunk*) malloc(sizeof(CMethodThunk)))->Init(pObj,&pfnMethod)->doThunk args
#define CALL_METHOD(pObj,pfnMethod,args) \
    ((CMethodThunk*) alloca(sizeof(CMethodThunk)))->Init(pObj,&pfnMethod)->doThunk args

// inetcore\mshtml\src\core\wrappers\imm32.cxx
#define ns_CodePageTable  (sizeof(s_CodePageTable)/sizeof(s_CodePageTable[0]))

// inetcore\mshtml\src\dxt\core\mscanner\msupport.h
#define FIX_FLOOR(a)	        ((a)&sfixedOver1)

// inetcore\mshtml\src\edit\inscmd.cxx
#define BREAK_CONDITION_Insert  (BREAK_CONDITION_OMIT_PHRASE | BREAK_CONDITION_NoScope) - BREAK_CONDITION_EnterBlock

// inetcore\mshtml\src\edit\pastecmd.cxx
#define FIXUP_FORMATTING(index, cmd, attr)                                      \
    if (fAllEqual == VB_TRUE)                                                   \
    {                                                                           \
        IFC( FixupBoolCharFormat(index, cmd, pTarget, TRUE) );                  \
    }                                                                           \
    else                                                                        \
    {                                                                           \
        IFC( spStyleSource->get_ ## attr(&bSourceAttribute) );                  \
        IFC( spStyleTarget->get_ ## attr(&bTargetAttribute) )                   \
        IFC( spStyleSourceBlock->get_ ## attr(&bSourceBlockAttribute) );        \
        IFC( spStyleTargetBlock->get_ ## attr(&bTargetBlockAttribute) );        \
        fEqual = !ShouldFixupFormatting(bSourceAttribute, bSourceBlockAttribute, bTargetAttribute, bTargetBlockAttribute, fForceFixup);  \
        IFC( FixupBoolCharFormat(index, cmd, pTarget, fEqual) );                \
    }

// inetcore\mshtml\src\f3\htmlpad\msg.hxx
#define PAD4(x)         (((x)+3)&~3)

// inetcore\mshtml\src\f3\htmlpad\msgform.h
#define DEFINE_EXCHFORMGUID(name, b) \
    DEFINE_GUID(name, 0x00020D00 | (b), 0, 0, 0xC0,0,0,0,0,0,0,0x46)

// inetcore\mshtml\src\f3\htmlpad\msgreply.cxx
#define cvalReplieeAdrEntry (sizeof(rgulPropTagRepAdrEntry) / sizeof(rgulPropTagRepAdrEntry[0]))

// inetcore\mshtml\src\f3\htmlpad\msgtripl.cxx
#define cformatetcTRIPOLE (sizeof(s_rgformatetcTRIPOLE) / sizeof(FORMATETC))

// inetcore\mshtml\src\f3\htmlpad\padauto.cxx
#define MSGNAME_WM_HTML_GETOBJECT   _T("WM_HTML_GETOBJECT")

// inetcore\mshtml\src\f3\htmlpad\tvdlg.h
#define Align4(_cb) (((_cb) + 3) & ~3)

// inetcore\mshtml\src\site\display\dispnode.hxx
#define DECLARE_DISPNODE_DEBUG(NODECLASS) \
    virtual size_t GetMemorySizeOfThis() const \
        {return sizeof(NODECLASS) + GetExtraSize(_flags & DISPEX_ALL);} \
    virtual TCHAR* ClassName() const \
        {return _T(#NODECLASS);}

// inetcore\mshtml\src\site\display\grafrot.hxx
#define cbSDBBLT          (sizeof(SDBBLT))

// inetcore\mshtml\src\site\display\pubrot.hxx
#define cbDRC (sizeof(DRC))
#define cbMDE   (sizeof(MDE))
#define cbMRS   (sizeof(MRS))

// inetcore\mshtml\src\site\display\xgdi2.hxx
#define CopyLpsw(lpsw1, lpsw2, lcsw) CopyLpb((lpsw1), (lpsw2), (lcsw) * sizeof(short))

// inetcore\mshtml\src\site\download\dwnbind.cxx
#define Align64(n)              (((n) + 63) & ~63)

// inetcore\mshtml\src\site\download\jpglib6a\jinclude.h
#define JFREAD(file,buf,sizeofbuf)  \
  ((size_t) fread((void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))
#define JFWRITE(file,buf,sizeofbuf)  \
  ((size_t) fwrite((const void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))

// inetcore\mshtml\src\site\include\props.hxx
#define IMPLEMENT_NUM_GETPROP(CLASS, PROP, TYPE)                     \
    STDMETHODIMP CLASS::Get##PROP(TYPE * p)                                 \
        {                                                                   \
            return ((NUMPROPPARAMS *)((BYTE *)&s_propdesc##CLASS##PROP + sizeof(PROPERTYDESC)))->GetNumberProperty( p, this, this);    \
        }
#define IMPLEMENT_NUM_SETPROP(CLASS, PROP, TYPE)                     \
    STDMETHODIMP CLASS::Set##PROP(TYPE v)                                   \
        {                                                                   \
            return ((NUMPROPPARAMS *)((BYTE *)&s_propdesc##CLASS##PROP + sizeof(PROPERTYDESC)))->SetNumberProperty( v, this, this, 1, 1);  \
        }
#define IMPLEMENT_CSTR_GETPROP(CLASS, PROP)                          \
    STDMETHODIMP CLASS::Get##PROP(BSTR *pbstr)                              \
        {                                                                   \
            return ((BASICPROPPARAMS *)((BYTE *)&s_propdesc##CLASS##PROP + sizeof(PROPERTYDESC)))->GetStringProperty(pbstr, this, this);    \
        }
#define IMPLEMENT_CSTR_SETPROP(CLASS, PROP)                          \
    STDMETHODIMP CLASS::Set##PROP(BSTR bstr)                                \
        {                                                                   \
            return ((BASICPROPPARAMS *)((BYTE *)&s_propdesc##CLASS##PROP + sizeof(PROPERTYDESC)))->SetStringProperty(bstr, this, this);  \
        }
#define IMPLEMENT_COLOR_GETPROP(CLASS, PROP, TYPE)                   \
    STDMETHODIMP CLASS::Get##PROP(TYPE * p)                                 \
        {                                                                   \
            return ((BASICPROPPARAMS *)((BYTE *)&s_propdesc##CLASS##PROP + sizeof(PROPERTYDESC)))->GetColorProperty( p, this, this);    \
        }
#define IMPLEMENT_COLOR_SETPROP(CLASS, PROP, TYPE)                   \
    STDMETHODIMP CLASS::Set##PROP(TYPE v)                                   \
        {                                                                   \
            return ((BASICPROPPARAMS *)((BYTE *)&s_propdesc##CLASS##PROP + sizeof(PROPERTYDESC)))->SetColorProperty( v, this, this);    \
        }
#define IMPLEMENT_ENUM_GETPROP(CLASS, PROP, TYPE)                    \
    STDMETHODIMP CLASS::Get##PROP(TYPE * p)                                 \
        {                                                                   \
            return ((NUMPROPPARAMS *)((BYTE *)&s_propdesc##CLASS##PROP + sizeof(PROPERTYDESC)))->GetNumberProperty( p, this, this);    \
        }
#define IMPLEMENT_ENUM_SETPROP(CLASS, PROP, TYPE)                    \
    STDMETHODIMP CLASS::Set##PROP(TYPE v)                                   \
        {                                                                   \
            return ((NUMPROPPARAMS *)((BYTE *)&s_propdesc##CLASS##PROP + sizeof(PROPERTYDESC)))->SetNumberProperty( v, this, this, 1, 1);  \
        }

// inetcore\mshtml\src\site\layout\layout.hxx
#define RFE_BACKGROUND      (RFE_IGNORE_ALIGNED | RFE_TIGHT_RECTS | RFE_IGNORE_CLIP_RC_BOUNDS | RFE_NO_EXTENT)

// inetcore\mshtml\src\time\media\wmsbuffer.h
#define IWMSBufferAllocator_AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)

// inetcore\mshtml\tried\triedctl\atlctl.h
#define PROP_PAGE(clsid) \
		{NULL, NULL, &clsid, &IID_NULL},

// inetcore\mshtml\tried\triedctl\dhtmledit.h
#define DECLARE_WND_CLASS_EX(WndClassName, style, bkgnd) \
static CWndClassInfo& GetWndClassInfo() \
{ \
	static CWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), style, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(bkgnd + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T("") \
	}; \
	return wc; \
}

// inetcore\outlookexpress\cryptdlg\util.cpp
#define LcbAlignLcb(lcb)	(((lcb) + ALIGN) & ~ALIGN)

// inetcore\outlookexpress\inc\msoert.h
#define LcbAlignLcb(lcb)	(((lcb) + ALIGN) & ~ALIGN)
#define PAD4(x)         (((x)+3)&~3)

// inetcore\outlookexpress\inetcomm\ess\ess.h
#define SIZE_ESS_Module_PDU_0 sizeof(Receipt)
#define SIZE_ESS_Module_PDU_1 sizeof(ContentHints)
#define SIZE_ESS_Module_PDU_2 sizeof(ContentReference)
#define SIZE_ESS_Module_PDU_3 sizeof(EquivalentLabels)
#define SIZE_ESS_Module_PDU_5 sizeof(SigningCertificate)
#define SIZE_ESS_Module_PDU_6 sizeof(SMimeEncryptCerts)
#define SIZE_ESS_Module_PDU_8 sizeof(SMIMEEncryptionKeyPreference)

// inetcore\outlookexpress\inetcomm\ess\ossutil.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// inetcore\outlookexpress\inetcomm\ess\pkiasn1.cpp
#define INFO_LEN_ALIGN(Len)  ((Len + 7) & ~7)

// inetcore\outlookexpress\inetcomm\mepad\frame.cpp
#define ctbbutton           (sizeof(rgtbbutton) / sizeof(TBBUTTON))

// inetcore\outlookexpress\inetcomm\mepad\mehost.cpp
#define SetMenuItem(_hmenu, _id, _fOn)     EnableMenuItem(_hmenu, _id, (_fOn)?MF_ENABLED:MF_DISABLED|MF_GRAYED)

// inetcore\outlookexpress\inetcomm\mimeole\enriched.cpp
#define CCHGLOBAL(_szGlobal)    (sizeof(_szGlobal) - 1)

// inetcore\outlookexpress\inetcomm\mimeole\internat.h
#define IsDBCSCodePage(_cpi) \
    (932 == _cpi || 936 == _cpi || 950 == _cpi || 949 == _cpi || 874 == _cpi || 10001 == _cpi)

// inetcore\outlookexpress\mailnews\common\thumb.h
#define THM_LOADPAGE    (WM_USER + 1)

// inetcore\outlookexpress\mailnews\extinc\msouser.h
#define msocbMSOGV (sizeof(MSOGV))
#define msocbMSOCLR (sizeof(MSOCLR))

// inetcore\outlookexpress\mailnews\shell\smapi16.cpp
#define WriteVar2File( hf, v )    _lwrite( (hf), &(v), sizeof(v) );
#define ReadVarFromFile( hf, v )  _lread( (hf), &(v), sizeof(v) );

// inetcore\outlookexpress\mailnews\shell\smapimem.h
#define INT_SIZE(a) ((a) + sizeof(BufInternal))

// inetcore\outlookexpress\mailnews\spooler\spoolapi.h
#define DELIVER_BACKGROUND_POLL         (DELIVER_NODIAL | DELIVER_BACKGROUND | DELIVER_NOUI | DELIVER_POLL | DELIVER_WATCH | \
                                         DELIVER_MAIL_RECV | DELIVER_SEND | DELIVER_SERVER_TYPE_ALL)
#define DELIVER_BACKGROUND_POLL_DIAL    (DELIVER_BACKGROUND | DELIVER_NOUI | DELIVER_POLL | DELIVER_WATCH | \
                                         DELIVER_MAIL_RECV | DELIVER_SEND | DELIVER_SERVER_TYPE_ALL)
#define DELIVER_BACKGROUND_POLL_DIAL_ALWAYS (DELIVER_DIAL_ALWAYS | DELIVER_BACKGROUND | DELIVER_NOUI | DELIVER_POLL | DELIVER_WATCH | \
                                             DELIVER_MAIL_RECV | DELIVER_SEND | DELIVER_SERVER_TYPE_ALL)

// inetcore\outlookexpress\msoeacct\crypt16.h
#define DES_KEY_SZ 	(sizeof(des_cblock))

// inetcore\outlookexpress\public\inc\wabapi.h
#define CBIWABOBJECT sizeof(IWABOBJECT)

// inetcore\outlookexpress\public\inc\wabdefs.h
#define IsEqualMAPIUID(lpuid1, lpuid2)  (!memcmp(lpuid1, lpuid2, sizeof(MAPIUID)))

// inetcore\outlookexpress\wabw\convert\wmnets\wabimp.h
#define CBABCREC sizeof(ABCREC)

// inetcore\outlookexpress\wabw\test\wabtests\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// inetcore\outlookexpress\wabw\wabapi\_abroot.h
#define CBROOT	sizeof(ROOT)

// inetcore\outlookexpress\wabw\wabapi\_dochost.h
#define CBIWDH_OLEWINDOW sizeof(IWDH_OLEWINDOW)
#define CBIWDH_OLEINPLACEFRAME sizeof(IWDH_OLEINPLACEFRAME)
#define CBIWDH_OLEINPLACESITE sizeof(IWDH_OLEINPLACESITE)
#define CBIWDH_OLECLIENTSITE sizeof(IWDH_OLECLIENTSITE)
#define CBIWDH_OLEDOCUMENTSITE sizeof(IWDH_OLEDOCUMENTSITE)

// inetcore\outlookexpress\wabw\wabapi\_idrgdrp.h
#define CBIWAB_DROPTARGET sizeof(IWAB_DROPTARGET)
#define CBIWAB_DROPSOURCE sizeof(IWAB_DROPSOURCE)
#define CBIWAB_DRAGDROP sizeof(IWAB_DRAGDROP)
#define CBIWAB_DATAOBJECT sizeof(IWAB_DATAOBJECT)
#define CBIWAB_ENUMFORMATETC sizeof(IWAB_ENUMFORMATETC)

// inetcore\outlookexpress\wabw\wabapi\_iprop.h
#define CBLSTSPV sizeof(LSTSPV)
#define CBIPDAT sizeof(IPDAT)

// inetcore\outlookexpress\wabw\wabapi\_itable.h
#define LcbAlignLcb(lcb)	(((lcb) + ALIGN) & ~ALIGN)

// inetcore\outlookexpress\wabw\wabapi\_ldapcnt.h
#define CBLDAP	sizeof(LDAPCONT)

// inetcore\outlookexpress\wabw\wabapi\_mapiu.h
#define	FBadIfacePtr(param, iface)					\
		(	IsBadReadPtr((param), sizeof(iface)) 	\
		 ||	IsBadReadPtr((param)->lpVtbl, sizeof(iface##Vtbl)))

// inetcore\outlookexpress\wabw\wabapi\_wabobj.h
#define CBLSTSPV sizeof(LSTSPV)
#define CBIWOINT sizeof(IWOINT)

// inetcore\outlookexpress\wabw\wabapi\_wrap.h
#define CBWRAP sizeof(WRAP)
#define CBOOP sizeof(OOP)
#define CBOOE sizeof(OOE)

// inetcore\outlookexpress\wabw\wabapi\advise.c
#define VALIDATE_ADVS(m, p, v) \
    if (IsBadWritePtr((p), sizeof(ADVS)) || \
      IsBadReadPtr((p)->lpVtbl, sizeof(ADVS_Vtbl)) || \
      (p)->lpVtbl != &vtblADVS) { \
        DebugTraceArg(m,  TEXT("Invalid object pointer")); \
        return v; \
    }
#define VALIDATE_SAS(m, p, v) \
    if (IsBadWritePtr((p), sizeof(SAS)) || \
      IsBadReadPtr((p)->lpVtbl, sizeof(SAS_Vtbl)) || \
      (p)->lpVtbl != &vtblSAS) { \
        DebugTraceArg(m,  TEXT("Invalid object pointer")); \
        return v; \
    }

// inetcore\outlookexpress\wabw\wabapi\hotsync.h
#define CBIHTTPCALLBACK sizeof(IHTTPCALLBACK)

// inetcore\outlookexpress\wabw\wabapi\iadrbook.c
#define CB_SMTP sizeof(szSMTP)

// inetcore\outlookexpress\wabw\wabapi\imemx.c
#define TOKENBUFFSIZE (256*6) + sizeof (TOKEN_USER)

// inetcore\outlookexpress\wabw\wabapi\memory.c
#define INT_SIZE(a)	((a) + sizeof (BufInternal))

// inetcore\outlookexpress\wabw\wabapi\msvalid.c
#define	IsBadIfacePtr(param, iface)					\
			(IsBadReadPtr((param), sizeof(iface)) 	\
		||	IsBadReadPtr((param)->lpVtbl, sizeof(iface##Vtbl)))

// inetcore\outlookexpress\wabw\wabapi\unkobj.h
#define IsEqualGUID(a, b)			(memcmp((a), (b), sizeof(GUID)) == 0)

// inetcore\outlookexpress\wabw\wabapi\vcard.c
#define cbAtSign    sizeof(szAtSign)
#define cbMSNpostfix    sizeof(szMSNpostfix)
#define cbAOLpostfix    sizeof(szAOLpostfix)
#define cbCOMPUSERVEpostfix    sizeof(szCOMPUSERVEpostfix)

// inetcore\outlookexpress\wabw\wabapi\wabspi.h
#define CBIWABSTORAGEPROVIDER sizeof(IWABSTORAGEPROVIDER)

// inetcore\outlookexpress\wabw\wabapi\wabval.h
#define BAD_STANDARD_OBJ( lpObj, prefix, method, lpVtbl) \
	(   IsBadWritePtr( (lpObj), sizeof(*lpObj)) \
	 || IsBadReadPtr( (void *) &(lpObj->lpVtbl->method), sizeof(LPVOID)) \
	 ||( ( LPVOID) (lpObj->lpVtbl->method) != (LPVOID) (prefix##method)))
#define FBadUnknown( lpObj ) \
	(	IsBadReadPtr( (lpObj), sizeof(LPVOID) ) \
	 ||	IsBadReadPtr( (lpObj)->lpVtbl, 3 * sizeof(LPUNKNOWN) ) \
	 ||	IsBadCodePtr( (FARPROC)(lpObj)->lpVtbl->QueryInterface ))

// inetcore\outlookexpress\wabw\wabfind\fnd.h
#define LcbAlignLcb(lcb)        (((lcb) + ALIGN) & ~ALIGN)
#define cbX(X) sizeof(X)

// inetcore\published\inc\dtbase.h
#define DECLARE_GET_CAPABILITIES(Caps)\
STDMETHODIMP get_Capabilities(long *pVal) { if (DXIsBadWritePtr(pVal, sizeof(*pVal))) return E_POINTER; *pVal = Caps; return S_OK; }

// inetcore\published\inc\dxhelper.h
#define DXSAMPLE_Alloca( ulNumSamples ) \
    (DXSAMPLE *)_alloca( (ulNumSamples) * sizeof( DXSAMPLE ) )
#define DXPMSAMPLE_Alloca( ulNumSamples ) \
    (DXPMSAMPLE *)_alloca( (ulNumSamples) * sizeof( DXPMSAMPLE ) )

// inetcore\published\inc\marqinfo.h
#define IMarqueeInfo_GetDocCoords(This,prcView,bGetOnlyIfFullyLoaded,pfFullyLoaded,WidthToFormatPageTo)	\
    (This)->lpVtbl -> GetDocCoords(This,prcView,bGetOnlyIfFullyLoaded,pfFullyLoaded,WidthToFormatPageTo)

// inetcore\published\inc\wabapi.h
#define CBIWABOBJECT sizeof(IWABOBJECT)

// inetcore\published\inc\wabdefs.h
#define IsEqualMAPIUID(lpuid1, lpuid2)  (!memcmp(lpuid1, lpuid2, sizeof(MAPIUID)))

// inetcore\setup\active\inc\localsrv.h
#define PROPERTYPAGE(name)     { OI_PROPERTYPAGE, (void *)&(name##Page) }

// inetcore\setup\active\inc\proppage.h
#define PPM_NEWOBJECTS    (WM_USER + 100)
#define PPM_APPLY         (WM_USER + 101)
#define PPM_EDITPROPERTY  (WM_USER + 102)

// inetcore\setup\active\inc\prsht.h
#define PSM_REMOVEPAGE          (WM_USER + 102)
#define PSM_ADDPAGE             (WM_USER + 103)

// inetcore\setup\ieak5\ieakeng\utils.h
#define LcbAlignLcb(lcb)    (((lcb) + ALIGN) & ~ALIGN)

// inetcore\setup\iexpress\advpext\util.h
#define ROUNDUP2( x, n ) ((((ULONG)(x)) + (((ULONG)(n)) - 1 )) & ~(((ULONG)(n)) - 1 ))

// inetcore\setup\iexpress\updfile\updres.h
#define CBLONG		(sizeof(LONG))

// inetcore\urlmon\download\cdl.h
#define MAX_VERSIONLENGTH                          27  // sizeof(2DWORDS)/(log 10 base 2) + 3 (seperators)

// inetcore\urlmon\iapp\cnet.cxx
    #define UA_VAL_LEN           (sizeof(UA_VAL_SZ) - 1)
    #define COMPATIBLE_VAL_LEN   (sizeof(COMPATIBLE_VAL_SZ) - 1)
    #define VERSION_VAL_LEN      (sizeof(VERSION_VAL_SZ) - 1)

// inetcore\urlmon\zones\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// inetcore\winhttp\tools\spork\inc\resources.h
#define NEWVARIANT(x) VARIANT x; memset(&x, 0, sizeof(VARIANT)); VariantInit(&x);

// inetcore\winhttp\tools\w3spoof\inc\resources.h
#define SOCKADDRBUFSIZE (sizeof(SOCKADDR_IN)+16)

// inetcore\winhttp\v5.1\api\autoprox.cxx
        #define HTTP_IF_MODIFIED_SINCE_LEN  (sizeof(HTTP_IF_MODIFIED_SINCE_SZ) - 1)

// inetcore\winhttp\v5.1\auth\auth.h
#define HTTP_AUTHORIZATION_LEN          (sizeof(HTTP_AUTHORIZATION_SZ)-1)
#define HTTP_PROXY_AUTHORIZATION_LEN    (sizeof(HTTP_PROXY_AUTHORIZATION_SZ)-1)

// inetcore\winhttp\v5.1\auth\basic.cxx
    #define BASIC_LEN sizeof(szBasic)-1

// inetcore\winhttp\v5.1\auth\passport.cxx
    #define PASSPORT_LEN sizeof(szPassport)-1

// inetcore\winhttp\v5.1\autoproxy\dhcploc.h
#define DHCP_CLASS_SIZE                 sizeof(DHCP_CLASS)

// inetcore\winhttp\v5.1\http\headers.cxx
    #define NSEPLEN (sizeof(NSEP) - 1)
    #define NSFTLEN (sizeof(NSFT) - 1)
    #define NSCSLEN (sizeof(NSCS) - 1)
#define MAKE_REQUEST_METHOD_TYPE(Type) \
    sizeof(# Type) - 1, # Type, HTTP_METHOD_TYPE_ ## Type
#define MAKE_REQUEST_METHOD_TYPE2(EnumType,Type) \
    sizeof(# Type) - 1, # Type, HTTP_METHOD_TYPE_ ## EnumType

// inetcore\winhttp\v5.1\http\headers.h
#define HTTP_DATE_LEN                   (sizeof(HTTP_DATE_SZ) - 1)
#define HTTP_EXPIRES_LEN                (sizeof(HTTP_EXPIRES_SZ) - 1)
#define HTTP_CONTENT_DISPOSITION_LEN     (sizeof(HTTP_CONTENT_DISPOSITION_SZ) - 1)
#define HTTP_LAST_MODIFIED_LEN          (sizeof(HTTP_LAST_MODIFIED_SZ) - 1)
#define HTTP_SERVER_LEN                 (sizeof(HTTP_SERVER_SZ) - 1)
#define HTTP_CONNECTION_LEN             (sizeof(HTTP_CONNECTION_SZ) - 1)
#define HTTP_PROXY_CONNECTION_LEN       (sizeof(HTTP_PROXY_CONNECTION_SZ) - 1)
#define HTTP_SET_COOKIE_LEN             (sizeof(HTTP_SET_COOKIE_SZ)-1)
#define CHUNKED_LEN                     (sizeof(CHUNKED_SZ) - 1)
#define KEEP_ALIVE_LEN                  (sizeof(KEEP_ALIVE_SZ) - 1)
#define HTTP_VIA_LEN                    (sizeof(HTTP_VIA_SZ) - 1)
#define HTTP_AGE_LEN                    (sizeof(HTTP_AGE_SZ)-1)
#define HTTP_VARY_LEN                   (sizeof(HTTP_VARY_SZ)-1)
#define NO_CACHE_LEN                    (sizeof(NO_CACHE_SZ) -1)
#define NO_STORE_LEN                    (sizeof(NO_STORE_SZ) -1)
#define PRIVATE_LEN                     (sizeof(PRIVATE_SZ) - 1)
#define FILENAME_LEN                    (sizeof(FILENAME_SZ) - 1)
#define USER_AGENT_LEN                  (sizeof(USER_AGENT_SZ) - 1)

// inetcore\winhttp\v5.1\http\read.cxx
#define PWS_LEN     (sizeof(PWS) - 1)
#define PWS95_LEN   (sizeof(PWS95) - 1)
#define IIS10_LEN   (sizeof(IIS10) - 1)

// inetcore\winhttp\v5.1\http\response.cxx
#define MICROSOFT_PWS_SERVER_LEN (sizeof(MICROSOFT_PWS_SERVER_SZ) - 1)

// inetcore\winhttp\v5.1\inc\macros.h
#define NEW(object) \
    (object FAR *)ALLOCATE_ZERO_MEMORY(sizeof(object))
#define NEW_MEMORY(n, type) \
    (type FAR *)ALLOCATE_FIXED_MEMORY(n * sizeof(type))
#define ZAP(thing) \
    ZeroMemory((PVOID)&thing, sizeof(thing))

// inetcore\winhttp\v5\auth\auth.h
#define HTTP_AUTHORIZATION_LEN          (sizeof(HTTP_AUTHORIZATION_SZ)-1)
#define HTTP_PROXY_AUTHORIZATION_LEN    (sizeof(HTTP_PROXY_AUTHORIZATION_SZ)-1)

// inetcore\winhttp\v5\auth\basic.cxx
    #define BASIC_LEN sizeof(szBasic)-1

// inetcore\winhttp\v5\auth\passport.cxx
    #define PASSPORT_LEN sizeof(szPassport)-1

// inetcore\winhttp\v5\http\headers.cxx
    #define NSEPLEN (sizeof(NSEP) - 1)
    #define NSFTLEN (sizeof(NSFT) - 1)
    #define NSCSLEN (sizeof(NSCS) - 1)
#define MAKE_REQUEST_METHOD_TYPE(Type) \
    sizeof(# Type) - 1, # Type, HTTP_METHOD_TYPE_ ## Type
#define MAKE_REQUEST_METHOD_TYPE2(EnumType,Type) \
    sizeof(# Type) - 1, # Type, HTTP_METHOD_TYPE_ ## EnumType

// inetcore\winhttp\v5\http\headers.h
#define HTTP_DATE_LEN                   (sizeof(HTTP_DATE_SZ) - 1)
#define HTTP_EXPIRES_LEN                (sizeof(HTTP_EXPIRES_SZ) - 1)
#define HTTP_CONTENT_DISPOSITION_LEN     (sizeof(HTTP_CONTENT_DISPOSITION_SZ) - 1)
#define HTTP_LAST_MODIFIED_LEN          (sizeof(HTTP_LAST_MODIFIED_SZ) - 1)
#define HTTP_SERVER_LEN                 (sizeof(HTTP_SERVER_SZ) - 1)
#define HTTP_CONNECTION_LEN             (sizeof(HTTP_CONNECTION_SZ) - 1)
#define HTTP_PROXY_CONNECTION_LEN       (sizeof(HTTP_PROXY_CONNECTION_SZ) - 1)
#define HTTP_SET_COOKIE_LEN             (sizeof(HTTP_SET_COOKIE_SZ)-1)
#define CHUNKED_LEN                     (sizeof(CHUNKED_SZ) - 1)
#define KEEP_ALIVE_LEN                  (sizeof(KEEP_ALIVE_SZ) - 1)
#define HTTP_VIA_LEN                    (sizeof(HTTP_VIA_SZ) - 1)
#define HTTP_AGE_LEN                    (sizeof(HTTP_AGE_SZ)-1)
#define HTTP_VARY_LEN                   (sizeof(HTTP_VARY_SZ)-1)
#define NO_CACHE_LEN                    (sizeof(NO_CACHE_SZ) -1)
#define NO_STORE_LEN                    (sizeof(NO_STORE_SZ) -1)
#define PRIVATE_LEN                     (sizeof(PRIVATE_SZ) - 1)
#define FILENAME_LEN                    (sizeof(FILENAME_SZ) - 1)
#define USER_AGENT_LEN                  (sizeof(USER_AGENT_SZ) - 1)

// inetcore\winhttp\v5\http\read.cxx
#define PWS_LEN     (sizeof(PWS) - 1)
#define PWS95_LEN   (sizeof(PWS95) - 1)
#define IIS10_LEN   (sizeof(IIS10) - 1)

// inetcore\winhttp\v5\http\response.cxx
#define MICROSOFT_PWS_SERVER_LEN (sizeof(MICROSOFT_PWS_SERVER_SZ) - 1)

// inetcore\winhttp\v5\inc\macros.h
#define NEW(object) \
    (object FAR *)ALLOCATE_ZERO_MEMORY(sizeof(object))
#define NEW_MEMORY(n, type) \
    (type FAR *)ALLOCATE_FIXED_MEMORY(n * sizeof(type))
#define ZAP(thing) \
    ZeroMemory((PVOID)&thing, sizeof(thing))

// inetcore\winhttp\v5\urlcache\cachedef.h
#define URL_CACHE_VERSION_NUM  sizeof(CACHE_ENTRY_INFO);
#define USER_PROFILE_LEN                (sizeof(USER_PROFILE_SZ) - 1)
#define PAGE_SIZE_FOR_GROUPS    (PAGE_SIZE - sizeof(FILEMAP_ENTRY))
#define GROUPS_PER_PAGE         PAGE_SIZE_FOR_GROUPS / sizeof(GROUP_ENTRY)
#define GROUPS_DATA_PER_PAGE    PAGE_SIZE_FOR_GROUPS / sizeof(GROUP_DATA_ENTRY)
#define LIST_GROUPS_PER_PAGE    PAGE_SIZE_FOR_GROUPS / sizeof(LIST_GROUP_ENTRY)

// inetcore\winhttp\v5\urlcache\reg.hxx
#define DEFAULT_CLASS_SIZE  sizeof(DEFAULT_CLASS)

// inetcore\wininet\apdetect\dhcploc.h
#define DHCP_CLASS_SIZE                 sizeof(DHCP_CLASS)

// inetcore\wininet\auth\auth.h
#define HTTP_AUTHORIZATION_LEN          (sizeof(HTTP_AUTHORIZATION_SZ)-1)
#define HTTP_PROXY_AUTHORIZATION_LEN    (sizeof(HTTP_PROXY_AUTHORIZATION_SZ)-1)

// inetcore\wininet\auth\basic.cxx
    #define BASIC_LEN sizeof(szBasic)-1

// inetcore\wininet\auth\passport.cxx
    #define PASSPORT_LEN sizeof(szPassport)-1

// inetcore\wininet\ftp\test\ftpcat\ftpcatp.h
#define nelems(a) ((sizeof(a))/sizeof((a)[0]))

// inetcore\wininet\http\headers.cxx
    #define NSEPLEN (sizeof(NSEP) - 1)
    #define NSFTLEN (sizeof(NSFT) - 1)
    #define NSCSLEN (sizeof(NSCS) - 1)
#define MAKE_REQUEST_METHOD_TYPE(Type) \
    sizeof(# Type) - 1, # Type, HTTP_METHOD_TYPE_ ## Type
#define MAKE_REQUEST_METHOD_TYPE2(EnumType,Type) \
    sizeof(# Type) - 1, # Type, HTTP_METHOD_TYPE_ ## EnumType

// inetcore\wininet\http\headers.h
#define HTTP_DATE_LEN                   (sizeof(HTTP_DATE_SZ) - 1)
#define HTTP_EXPIRES_LEN                (sizeof(HTTP_EXPIRES_SZ) - 1)
#define HTTP_CONTENT_DISPOSITION_LEN     (sizeof(HTTP_CONTENT_DISPOSITION_SZ) - 1)
#define HTTP_LAST_MODIFIED_LEN          (sizeof(HTTP_LAST_MODIFIED_SZ) - 1)
#define HTTP_SERVER_LEN                 (sizeof(HTTP_SERVER_SZ) - 1)
#define HTTP_CONNECTION_LEN             (sizeof(HTTP_CONNECTION_SZ) - 1)
#define HTTP_PROXY_CONNECTION_LEN       (sizeof(HTTP_PROXY_CONNECTION_SZ) - 1)
#define HTTP_SET_COOKIE_LEN             (sizeof(HTTP_SET_COOKIE_SZ)-1)
#define CHUNKED_LEN                     (sizeof(CHUNKED_SZ) - 1)
#define KEEP_ALIVE_LEN                  (sizeof(KEEP_ALIVE_SZ) - 1)
#define HTTP_VIA_LEN                    (sizeof(HTTP_VIA_SZ) - 1)
#define HTTP_AGE_LEN                    (sizeof(HTTP_AGE_SZ)-1)
#define HTTP_VARY_LEN                   (sizeof(HTTP_VARY_SZ)-1)
#define NO_CACHE_LEN                    (sizeof(NO_CACHE_SZ) -1)
#define NO_STORE_LEN                    (sizeof(NO_STORE_SZ) -1)
#define PRIVATE_LEN                     (sizeof(PRIVATE_SZ) - 1)
#define FILENAME_LEN                    (sizeof(FILENAME_SZ) - 1)
#define USER_AGENT_LEN                  (sizeof(USER_AGENT_SZ) - 1)

// inetcore\wininet\http\read.cxx
#define PWS_LEN     (sizeof(PWS) - 1)
#define PWS95_LEN   (sizeof(PWS95) - 1)
#define IIS10_LEN   (sizeof(IIS10) - 1)

// inetcore\wininet\http\response.cxx
#define MICROSOFT_PWS_SERVER_LEN (sizeof(MICROSOFT_PWS_SERVER_SZ) - 1)

// inetcore\wininet\inc\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// inetcore\wininet\inc\macros.h
#define NEW(object) \
    (object FAR *)ALLOCATE_ZERO_MEMORY(sizeof(object))
#define NEW_MEMORY(n, type) \
    (type FAR *)ALLOCATE_FIXED_MEMORY(n * sizeof(type))
#define ZAP(thing) \
    ZeroMemory((PVOID)&thing, sizeof(thing))

// inetcore\wininet\inc\util.h
#define START_GUARD_AGAINST_ASYNC_AUTOPROXY_CALL \
    LPINTERNET_THREAD_INFO lpThreadInfo = InternetGetThreadInfo();\
    BOOL bSetNonBlocking = FALSE;\
    CFsm* pFsm;\
    if (lpThreadInfo && (pFsm=lpThreadInfo->Fsm) && lpThreadInfo->IsAsyncWorkerThread && !pFsm->IsBlocking())\
    {\
        pFsm->SetBlocking(TRUE);\
        bSetNonBlocking = TRUE;\
    }

// inetcore\wininet\urlcache\cachedef.h
#define URL_CACHE_VERSION_NUM  sizeof(CACHE_ENTRY_INFO);
#define USER_PROFILE_LEN                (sizeof(USER_PROFILE_SZ) - 1)
#define PAGE_SIZE_FOR_GROUPS    (PAGE_SIZE - sizeof(FILEMAP_ENTRY))
#define GROUPS_PER_PAGE         PAGE_SIZE_FOR_GROUPS / sizeof(GROUP_ENTRY)
#define GROUPS_DATA_PER_PAGE    PAGE_SIZE_FOR_GROUPS / sizeof(GROUP_DATA_ENTRY)
#define LIST_GROUPS_PER_PAGE    PAGE_SIZE_FOR_GROUPS / sizeof(LIST_GROUP_ENTRY)

// inetcore\wininet\urlcache\reg.hxx
#define DEFAULT_CLASS_SIZE  sizeof(DEFAULT_CLASS)

// inetsrv\iis\admin\adsi\helper\include\netolary.hxx
#define DECLARE_ADsPTRARY(_Cls, _Ty, _pTy)                    \
    class _Cls : public CADsPtrAry                            \
    {                                                           \
    public:                                                     \
        _Cls(void) : CADsPtrAry() { ; }                       \
        _Ty& operator[] (int i) { return * (_pTy) Deref(sizeof(void *), i); } \
        operator _pTy(void) { return (_pTy) _pv; }              \
        _Cls(const _Cls &);                                     \
        _Cls& operator=(const _Cls &);                          \
    };

// inetsrv\iis\admin\adsi\oleds2.0\include\netolary.hxx
#define DECLARE_ADsPTRARY(_Cls, _Ty, _pTy)                    \
    class _Cls : public CADsPtrAry                            \
    {                                                           \
    public:                                                     \
        _Cls(void) : CADsPtrAry() { ; }                       \
        _Ty& operator[] (int i) { return * (_pTy) Deref(sizeof(void *), i); } \
        operator _pTy(void) { return (_pTy) _pv; }              \
        _Cls(const _Cls &);                                     \
        _Cls& operator=(const _Cls &);                          \
    };

// inetsrv\iis\admin\appconfig\mappingpage.cpp
#define CHECK_VERBS()\
   m_bVerbsValid = \
      (m_verbs_index > 0 && lstrlen(m_verbs) != 0) || (m_verbs_index == 0)
#define ENABLE_OK()\
   ::EnableWindow(GetDlgItem(IDOK), m_bExtValid && m_bExecValid && m_bVerbsValid)

// inetsrv\iis\admin\certwiz\securitysettingspage.cpp
#define COUNT_KEYLENGTH sizeof(dwPredefinedKeyLength)/sizeof(dwPredefinedKeyLength[0])

// inetsrv\iis\config\src\appcenter\inc\acsmacro.h
#define ACS_GUID_SIZE                   (sizeof(ACS_A_SAMPLE_GUID))

// inetsrv\iis\config\src\appcenter\inc\cluscmmn.h
#define PORT_RULE_SIZE sizeof(CVY_RULE)

// inetsrv\iis\config\src\complib\inc\crtwrap.h
#define _INTSIZEOF(n)	( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v)	( ap = (va_list)&v + _INTSIZEOF(v) )

// inetsrv\iis\config\src\complib\inc\tigger.h
#define _OID_COLUMNPK(Name)	__COLUMN_PROPS(L"OID", sizeof(OID), Name, DBTYPE_OID, DBCF_PK)
#define _OID_COLUMN(Name)	__COLUMN(L"OID", sizeof(OID), Name, DBTYPE_OID)
#define I2_COLUMN(Name)		__COLUMN(L"short", sizeof(short), Name, DBTYPE_I2)
#define UI2_COLUMN(Name)	__COLUMN(L"unsigned short", sizeof(unsigned short), Name, DBTYPE_UI2)
#define I4_COLUMN(Name)		__COLUMN(L"long", sizeof(long), Name, DBTYPE_I4)
#define UI4_COLUMN(Name)	__COLUMN(L"unsigned long", sizeof(unsigned long), Name, DBTYPE_UI4)
#define BOOL_COLUMN(Name)	__COLUMN(L"bool", sizeof(VARIANT_BOOL), Name, DBTYPE_BOOL)
#define GUID_COLUMN(Name)	__COLUMN(L"GUID", sizeof(GUID), Name, DBTYPE_GUID)
#define VARIANT_COLUMN(Name) __COLUMN(L"variant", sizeof(VARIANT), Name, DBTYPE_VARIANT)

// inetsrv\iis\config\src\wmi\atl30\atlcom.h
#define BEGIN_PROPERTY_MAP(theClass) \
	typedef _ATL_PROP_NOTIFY_EVENT_CLASS __ATL_PROP_NOTIFY_EVENT_CLASS; \
	typedef theClass _PropMapClass; \
	static ATL_PROPMAP_ENTRY* GetPropertyMap()\
	{\
		static ATL_PROPMAP_ENTRY pPropMap[] = \
		{ \
			{OLESTR("_cx"), 0, &CLSID_NULL, NULL, offsetof(_PropMapClass, m_sizeExtent.cx), sizeof(long), VT_UI4}, \
			{OLESTR("_cy"), 0, &CLSID_NULL, NULL, offsetof(_PropMapClass, m_sizeExtent.cy), sizeof(long), VT_UI4},
#define PROP_PAGE(clsid) \
		{NULL, NULL, &clsid, &IID_NULL, 0, 0, 0},
#define END_CONNECTION_POINT_MAP() {(DWORD_PTR)-1} }; \
	if (pnEntries) *pnEntries = sizeof(_entries)/sizeof(_ATL_CONNMAP_ENTRY) - 1; \
	return _entries;}

// inetsrv\iis\config\src\wmi\atl30\atlconv.h
#define DEVMODEW2A(lpw)\
	((lpw == NULL) ? NULL : ATLDEVMODEW2A((LPDEVMODEA)alloca(sizeof(DEVMODEA)+lpw->dmDriverExtra), lpw))
#define DEVMODEA2W(lpa)\
	((lpa == NULL) ? NULL : ATLDEVMODEA2W((LPDEVMODEW)alloca(sizeof(DEVMODEW)+lpa->dmDriverExtra), lpa))

// inetsrv\iis\config\src\wmi\atl30\atldb.h
#define END_PROPERTY_SET(guid) \
		}; \
		if (pNumPropSets != NULL) \
		{ \
			pSet[nCurProp].pUPropInfo = (UPROPINFO*)aProperty##guid; \
			pSet[nCurProp].cUPropInfo = sizeof(aProperty##guid) / sizeof(UPROPINFO); \
			cRemainder = (pSet[nCurProp].cUPropInfo % 32) ? 1 : 0; \
			if (cElemsMax < (pSet[nCurProp].cUPropInfo / 32 + cRemainder)) \
			{ \
				cElemsMax = (pSet[nCurProp].cUPropInfo / 32 + cRemainder); \
			} \
		} \
		nCurProp++;
#define END_PROPSET_MAP() \
	if (pNumPropSets != NULL) \
	{ \
		if (IsEqualGUID(*pguidSet, GUID_NULL)) \
		{ \
			*pNumPropSets = nCurProp; \
			return pSet; \
		} \
		else \
		{ \
			*pNumPropSets = 1; \
			UINT i = 0; \
			for (; i < sizeof(pSet)/sizeof(UPROPSET) && IsEqualGUID(*(pSet[i].pPropSet), *pguidSet); i++); \
			return (i == sizeof(pSet)/sizeof(UPROPSET)) ? &pSet[0] : &pSet[i]; \
		} \
	} \
	return (UPROPSET*)nCurProp; \
	}
#define END_PROVIDER_COLUMN_MAP() \
}; *pcCols = sizeof(_rgColumns)/sizeof(ATLCOLUMNINFO); return _rgColumns;}

// inetsrv\iis\config\src\wmi\atl30\atldbcli.h
#define _SIZE_TYPE(data) sizeof(((_classtype*)0)->data)

// inetsrv\iis\config\src\wmi\atl30\atliface.h
#define IAxWinAmbientDispatch_put_BackColor(This,clrBackground)	\
    (This)->lpVtbl -> put_BackColor(This,clrBackground)
#define IAxWinAmbientDispatch_get_BackColor(This,pclrBackground)	\
    (This)->lpVtbl -> get_BackColor(This,pclrBackground)
#define IAxWinAmbientDispatch_put_ForeColor(This,clrForeground)	\
    (This)->lpVtbl -> put_ForeColor(This,clrForeground)
#define IAxWinAmbientDispatch_get_ForeColor(This,pclrForeground)	\
    (This)->lpVtbl -> get_ForeColor(This,pclrForeground)

// inetsrv\iis\config\src\wmi\atl30\atlsnap.h
#define BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname) \
	HRESULT GetDataClass(IDataObject* pDataObject, CSnapInItem** ppItem, DATA_OBJECT_TYPES* pType) \
	{ \
		if (ppItem == NULL) \
			return E_POINTER; \
		if (pType == NULL) \
			return E_POINTER; \
\
		*ppItem = NULL; \
\
		*pType = CCT_UNINITIALIZED; \
\
		STGMEDIUM stgmedium = { TYMED_HGLOBAL, NULL }; \
		FORMATETC formatetc = { CSnapInItem::m_CCF_NODETYPE, \
			NULL, \
			DVASPECT_CONTENT, \
			-1, \
			TYMED_HGLOBAL \
		}; \
\
		stgmedium.hGlobal = GlobalAlloc(0, sizeof(GUID)); \
		if (stgmedium.hGlobal == NULL) \
			return E_OUTOFMEMORY; \
\
		HRESULT hr = pDataObject->GetDataHere(&formatetc, &stgmedium); \
		if (FAILED(hr)) \
		{ \
			GlobalFree(stgmedium.hGlobal); \
			return hr; \
		} \
\
		GUID guid; \
		memcpy(&guid, stgmedium.hGlobal, sizeof(GUID)); \
\
		GlobalFree(stgmedium.hGlobal); \
		hr = S_OK;

// inetsrv\iis\config\src\wmi\atl30\atlwin.h
#define DECLARE_WND_CLASS(WndClassName) \
static CWndClassInfo& GetWndClassInfo() \
{ \
	static CWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(COLOR_WINDOW + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T("") \
	}; \
	return wc; \
}
#define DECLARE_WND_CLASS_EX(WndClassName, style, bkgnd) \
static CWndClassInfo& GetWndClassInfo() \
{ \
	static CWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), style, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(bkgnd + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T("") \
	}; \
	return wc; \
}
#define DECLARE_WND_SUPERCLASS(WndClassName, OrigWndClassName) \
static CWndClassInfo& GetWndClassInfo() \
{ \
	static CWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), 0, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, NULL, NULL, WndClassName, NULL }, \
		OrigWndClassName, NULL, NULL, TRUE, 0, _T("") \
	}; \
	return wc; \
}

// inetsrv\iis\iisrearc\core\ap\was\dll\perf_manager.cxx
#define DECLARE_MAX_GLOBAL(Counter)  \
        {   \
        FIELD_OFFSET( GLOBAL_MAX_DATA, Counter ),\
        FIELD_OFFSET( W3_GLOBAL_COUNTER_BLOCK, Counter ),\
        RTL_FIELD_SIZE( W3_GLOBAL_COUNTER_BLOCK, Counter )\
    }

// inetsrv\iis\iisrearc\core\ap\was\dll\virtual_site.cxx
#define DECLARE_MAX_SITE(Counter)  \
        {   \
        FIELD_OFFSET( W3_MAX_DATA, Counter ),\
        FIELD_OFFSET( W3_COUNTER_BLOCK, Counter ),\
        RTL_FIELD_SIZE( W3_COUNTER_BLOCK, Counter )\
    }

// inetsrv\iis\iisrearc\core\inc\lkrhash.h
# define LKRHASH_ALLOCATOR_NEW(C, N)                            \
    const ALLOC_CACHE_CONFIGURATION acc = { 1, N, sizeof(C) };  \
    C::sm_palloc = new ALLOC_CACHE_HANDLER("LKRhash:" #C, &acc);
# define LKRHASH_ALLOCATOR_NEW(C, N)                            \
    C::sm_palloc = new FastHeap(sizeof(C));

// inetsrv\iis\iisrearc\core\perfctrs\inc\counters.h
#define BEGIN_COUNTER_BINDING(cperfclass)                               \
cperfclass * cperfclass ## ::m_pCounters = NULL;                        \
CCounterDef CCounterDef_IISCtrs::m_CounterDef;                          \
WCHAR CCounterDef_IISCtrs::m_szClassName[MAX_NAME_CHARS+1]={0};         \
PBYTE CCounterDef_IISCtrs::m_pDataStart = NULL;                         \
SMACCESSOR_TYPE CCounterDef_IISCtrs::m_fAccessorType = SM_ACC_UNKNOWN;  \
CComPtr<ISMManager>  CCounterDef_IISCtrs::m_pSM = NULL;                 \
cperfclass ## :: cperfclass ## ()                                       \
{                                                                       \
    ::ZeroMemory ( m_szInstanceName, sizeof(m_szInstanceName) );        \
    ::ZeroMemory ( m_szClassName, sizeof(m_szClassName) );              \
    m_pCounters = this;                                                 \
    static CCounterInfo _s_aBoundCounterDef[] =                         \
    {                                                                   \

// inetsrv\iis\iisrearc\core\wp\modules\static\dirlist.cxx
#define PAD_COL_SPACING       (sizeof(COL_SPACE) - 1)

// inetsrv\iis\iisrearc\core\wp\modules\static\responseheaders.cxx
# define InitItem( sti, pszConstantItem)  \
    { pszConstantItem, (sizeof(pszConstantItem) - 1) }

// inetsrv\iis\iisrearc\core\wp\ulsim\parsep.h
#define HTTP_PREFIX_SIZE    (sizeof("http") - 1)
#define HTTP_PREFIX1_SIZE   (sizeof("://") - 1)
#define HTTP_PREFIX2_SIZE   (sizeof("s://") - 1)

// inetsrv\iis\iisrearc\iisplus\ssinc\ssinc.hxx
#define SSI_DEF_ERRMSG_LEN      sizeof( SSI_DEF_ERRMSG )
#define SSI_DEF_ABBREV_LEN      sizeof( SSI_DEF_ABBREV )

// inetsrv\iis\iisrearc\iisplus\ulatq\workerrequest.hxx
#define INLINE_REQUEST_BUFFER_LEN           (sizeof(HTTP_REQUEST)+2048)

// inetsrv\iis\iisrearc\iisplus\ulw3\cgi_handler.h
#define PIPENAME_SIZE       ( sizeof( "\\\\.\\pipe\\IISCgiStdOut" ) + 64 )

// inetsrv\iis\iisrearc\iisplus\ulw3\w3metadata.cxx
# define DEF_MD_REC_SIZE   ((1 + DEFAULT_MD_RECORDS) * \
                            (sizeof(METADATA_GETALL_RECORD) + DEFAULT_RECORD_SIZE))

// inetsrv\iis\iisrearc\iisplus\w3isapi\isapi_context.hxx
#define ISAPI_CONTEXT_SIGNATURE         sizeof( EXTENSION_CONTROL_BLOCK )

// inetsrv\iis\iisrearc\ul\api\precomp.h
#define ALIGN_DOWN(length, type)                                \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type)                                  \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))

// inetsrv\iis\iisrearc\ul\drv\httptypes.h
#define VERSION_SIZE            (sizeof("HTTP/1.1") - 1)

// inetsrv\iis\iisrearc\ul\drv\misc.h
#define IS_VALID_UL_NONPAGED_RESOURCE(pResource)                            \
    (((pResource) != NULL) &&                                               \
     ((pResource)->Signature == UL_NONPAGED_RESOURCE_SIGNATURE) &&          \
     ((pResource)->RefCount > 0))

// inetsrv\iis\iisrearc\ul\drv\proc.h
#define UlPplAllocateIrpContext()                                           \
    (PUL_IRP_CONTEXT)(PplAllocate(                                          \
        g_pUlNonpagedData->IrpContextLookaside                              \
        ))
#define UlPplAllocateReceiveBuffer()                                        \
    (PUL_RECEIVE_BUFFER)(PplAllocate(                                       \
        g_pUlNonpagedData->ReceiveBufferLookaside                           \
        ))
#define UlPplAllocateRequestBuffer()                                        \
    (PUL_REQUEST_BUFFER)(PplAllocate(                                       \
        g_pUlNonpagedData->RequestBufferLookaside                           \
        ))
#define UlPplAllocateInternalRequest()                                      \
    (PUL_INTERNAL_REQUEST)(PplAllocate(                                     \
        g_pUlNonpagedData->InternalRequestLookaside                         \
        ))
#define UlPplAllocateChunkTracker()                                         \
    (PUL_CHUNK_TRACKER)(PplAllocate(                                        \
        g_pUlNonpagedData->ChunkTrackerLookaside                            \
        ))
#define UlPplAllocateFullTracker()                                          \
    (PUL_FULL_TRACKER)(PplAllocate(                                         \
        g_pUlNonpagedData->FullTrackerLookaside                             \
        ))
#define UlPplAllocateResponseBuffer()                                       \
    (PUL_INTERNAL_RESPONSE)(PplAllocate(                                    \
        g_pUlNonpagedData->ResponseBufferLookaside                          \
        ))

// inetsrv\iis\iisrearc\ul\drv\rcvhdrs.h
#define WILDCARD_SIZE       (sizeof("*/*"))

// inetsrv\iis\iisrearc\ul\drv\type.h
#define CG_LOCK_READ() \
do { \
    UlAcquireResourceShared(&(g_pUlNonpagedData->ConfigGroupResource), TRUE); \
} while (0)
#define CG_LOCK_WRITE() \
do { \
    UlAcquireResourceExclusive(&(g_pUlNonpagedData->ConfigGroupResource), TRUE); \
} while (0)

// inetsrv\iis\iisrearc\ul\drv\ultcip.h
#define UL_COMPARE_QOS_NOTIFICATION(rguid1, rguid2)  \
    (RtlCompareMemory((PVOID)rguid1,(PVOID)rguid2,sizeof(GUID)) == sizeof(GUID))

// inetsrv\iis\iisrearc\ul\test\dll\tupfilt.c
#define ACCEPT_INFO (sizeof(HTTP_RAW_CONNECTION_INFO) + 2 * sizeof(HTTP_NETWORK_ADDRESS_IPV4))

// inetsrv\iis\iisrearc\ul\ulkd\glob.c
#define MAKE_ORDINAL( name, type )                                          \
    {                                                                       \
        "&http!" name,                                                        \
        0,                                                                  \
        0,                                                                  \
        (ULONG)sizeof(type),                                                \
        FALSE                                                               \
    }

// inetsrv\iis\iisrearc\ul\win9x\src\test\vxd\vxd.c
#define URL_SIZE sizeof(URL)

// inetsrv\iis\iisrearc\ulrtl\httptypes.h
#define VERSION_SIZE            (sizeof("HTTP/1.1") - 1)

// inetsrv\iis\iisrearc\ulrtl\misc.h
#define IS_VALID_UL_NONPAGED_RESOURCE(pResource)                            \
    (((pResource) != NULL) &&                                               \
     ((pResource)->Signature == UL_NONPAGED_RESOURCE_SIGNATURE) &&          \
     ((pResource)->RefCount > 0))

// inetsrv\iis\inc\lkrhash.h
# define LKRHASH_ALLOCATOR_NEW(C, N)                            \
    const ALLOC_CACHE_CONFIGURATION acc = { 1, N, sizeof(C) };  \
    C::sm_palloc = new ALLOC_CACHE_HANDLER("IISRTL:" #C, &acc);

// inetsrv\iis\inc\manodel.hxx
#define BLOCK_HEADER_SIZE   sizeof(PVOID)

// inetsrv\iis\inc\replseed.hxx
#define SEED_HEADER_SIZE (3 + sizeof(ALG_ID)) //size of header info at beginning of seed

// inetsrv\iis\lkrhash\inc\klkrhash.h
# define LKRHASH_ALLOCATOR_NEW(C, N, Tag) \
    C::sm_palloc = new CNonPagedHeap(sizeof(C), Tag)
# define LKRHASH_ALLOCATOR_NEW(C, N, Tag) \
    C::sm_palloc = new CPagedHeap(sizeof(C), Tag)
# define LKRHASH_ALLOCATOR_NEW(C, N, Tag) \
    C::sm_palloc = new CNonPagedLookasideList(sizeof(C), Tag)
# define LKRHASH_ALLOCATOR_NEW(C, N, Tag) \
    C::sm_palloc = new CPagedLookasideList(sizeof(C), Tag)

// inetsrv\iis\lkrhash\inc\lkrhash.h
# define LKRHASH_ALLOCATOR_NEW(C, N, Tag)                       \
    const ALLOC_CACHE_CONFIGURATION acc = { 1, N, sizeof(C) };  \
    C::sm_palloc = new ACache("LKRhash:" #C, &acc);
# define LKRHASH_ALLOCATOR_NEW(C, N, Tag) \
    C::sm_palloc = new FastHeap(sizeof(C))

// inetsrv\iis\setup\util\migrate\poolmem.h
#define PoolMemCreateString(h,x)        ((LPTSTR) PoolMemGetAlignedMemory((h),(x)*sizeof(TCHAR)))

// inetsrv\iis\staxinc\align.h
#define COUNT_IS_ALIGNED(Count,Pow2) \
        ( ( ( (Count) & (((Pow2)-1)) ) == 0) ? TRUE : FALSE )
#define ROUND_DOWN_COUNT(Count,Pow2) \
        ( (Count) & (~((Pow2)-1)) )
#define ROUND_UP_COUNT(Count,Pow2) \
        ( ((Count)+(Pow2)-1) & (~((Pow2)-1)) )
#define ALIGN_DESC_CHAR         sizeof(DESC_CHAR)
#define ALIGN_TCHAR             sizeof(TCHAR)
#define ALIGN_WCHAR             sizeof(WCHAR)
#define ALIGN_DESC_CHAR         sizeof(DESC_CHAR)
#define ALIGN_TCHAR             sizeof(TCHAR)
#define ALIGN_WCHAR             sizeof(WCHAR)

// inetsrv\iis\staxinc\crsapi.h
#define SELECT_LIST_SIZE(p) ((p->nEntries * sizeof(SELECTION_ENTRY))+sizeof(p->nEntries))

// inetsrv\iis\staxinc\exchmole.h
#define IMimeInternational_GetCodePageCharset(This,cpiCodePage,ctCsetType,phCharset)	\
    (This)->lpVtbl -> GetCodePageCharset(This,cpiCodePage,ctCsetType,phCharset)
#define IMimeInternational_GetCodePageInfo(This,cpiCodePage,pCodePageInfo)	\
    (This)->lpVtbl -> GetCodePageInfo(This,cpiCodePage,pCodePageInfo)
#define IMimeInternational_CanConvertCodePages(This,cpiSource,cpiDest)	\
    (This)->lpVtbl -> CanConvertCodePages(This,cpiSource,cpiDest)
#define IMimeInternational_MLANG_ConvertInetString(This,cpiSource,cpiDest,pSource,pnSizeOfSource,pDestination,pnDstSize)	\
    (This)->lpVtbl -> MLANG_ConvertInetString(This,cpiSource,cpiDest,pSource,pnSizeOfSource,pDestination,pnDstSize)

// inetsrv\iis\staxinc\export\blockmgr.h
#define BLOCK_HEAP_NODE_SIZE	(sizeof(BLOCK_HEAP_NODE))

// inetsrv\iis\staxinc\export\cmmtypes.h
#define GLOBAL_PROPERTY_ITEM_SIZE			sizeof(GLOBAL_PROPERTY_ITEM)
#define GLOBAL_PROPERTY_TABLE_FRAGMENT_SIZE	sizeof(GLOBAL_PROPERTY_TABLE_FRAGMENT)
#define RECIPIENTS_PROPERTY_ITEM_SIZE			sizeof(RECIPIENTS_PROPERTY_ITEM)
#define RECIPIENTS_PROPERTY_ITEM_SIZE_EX	sizeof(RECIPIENTS_PROPERTY_ITEM_EX)
#define RECIPIENTS_PROPERTY_TABLE_FRAGMENT_SIZE	sizeof(RECIPIENTS_PROPERTY_TABLE_FRAGMENT)
#define PROPID_MGMT_PROPERTY_ITEM_SIZE			sizeof(PROPID_MGMT_PROPERTY_ITEM)
#define PROPID_MGMT_PROPERTY_TABLE_FRAGMENT_SIZE	sizeof(PROPID_MGMT_PROPERTY_TABLE_FRAGMENT)
#define RECIPIENT_PROPERTY_ITEM_SIZE			sizeof(RECIPIENT_PROPERTY_ITEM)
#define RECIPIENT_PROPERTY_TABLE_FRAGMENT_SIZE	sizeof(RECIPIENT_PROPERTY_TABLE_FRAGMENT)

// inetsrv\iis\staxinc\export\cpoolmac.h
    #define F_INIT_CPOOL(CMyClass, NumPreAlloc)  \
                CMyClass::m_MyClassPool.ReserveMemory(NumPreAlloc, sizeof(CMyClass))

// inetsrv\iis\staxinc\export\flatfile.h
#define RECORD_HEADER_SIZE sizeof(RECORDHDR)

// inetsrv\iis\staxinc\export\nntpapi.h
#define FC_NNTP_ALL                 (                             \
                                      FC_NNTP_POSTINGMODES			| \
                                      FC_NNTP_ORGANIZATION			| \
                                      FC_NNTP_POSTLIMITS			| \
                                      FC_NNTP_FEEDLIMITS        	| \
                                      FC_NNTP_ENCRYPTCAPS       	| \
                                      FC_NNTP_SMTPADDRESS       	| \
                                      FC_NNTP_UUCPNAME				| \
                                      FC_NNTP_CONTROLSMSGS      	| \
                                      FC_NNTP_DEFAULTMODERATOR  	| \
                                      FC_NNTP_AUTHORIZATION     	| \
                                      FC_NNTP_DISABLE_NEWNEWS   	| \
                                      FC_MD_SERVER_SS_AUTH_MAPPING  | \
                                      FC_NNTP_CLEARTEXT_AUTH_PROVIDER	| \
                                      FC_NTAUTHENTICATION_PROVIDERS | \
                                      0 )

// inetsrv\iis\staxinc\msnsspi.h
#define NTLMSSP_MESSAGE_SIGNATURE_SIZE sizeof(NTLMSSP_MESSAGE_SIGNATURE)

// inetsrv\iis\svcs\admex\cmdline\admext.cxx
#define PAD4(a) (((a)+3)&~3)

// inetsrv\iis\svcs\admex\secex\comobj.cxx
#define PAD4(a) (((a)+3)&~3)

// inetsrv\iis\svcs\afsvcloc\reg.hxx
#define DEFAULT_CLASS_SIZE  sizeof(DEFAULT_CLASS)

// inetsrv\iis\svcs\cmp\asp51\dbgprop.h
#define IPerPropertyBrowsing2_MapPropertyToPage(This,dispid,pClsidPropPage)	\
    (This)->lpVtbl -> MapPropertyToPage(This,dispid,pClsidPropPage)

// inetsrv\iis\svcs\cmp\asp51\vecimpl.h
#define __vec_rounded_size(s) \
			(((s) + (VEC_GROW_SIZE - 1)) & ~(VEC_GROW_SIZE - 1))

// inetsrv\iis\svcs\cmp\asp\dbgprop.h
#define IPerPropertyBrowsing2_MapPropertyToPage(This,dispid,pClsidPropPage)	\
    (This)->lpVtbl -> MapPropertyToPage(This,dispid,pClsidPropPage)

// inetsrv\iis\svcs\cmp\asp\vecimpl.h
#define __vec_rounded_size(s) \
			(((s) + (VEC_GROW_SIZE - 1)) & ~(VEC_GROW_SIZE - 1))

// inetsrv\iis\svcs\cmp\webdav\httpext\voltype.cpp
#define cbDriveSpec	(sizeof(L"c:\\"))

// inetsrv\iis\svcs\ftp\mib\mib.h
#define OID_SIZEOF( Oid )      ( sizeof Oid / sizeof(UINT) )

// inetsrv\iis\svcs\infocomm\cache2\metacach.cxx
# define DEF_MD_REC_SIZE   ((1 + DEFAULT_MD_RECORDS) * \
                            (sizeof(METADATA_RECORD) + DEFAULT_RECORD_SIZE))

// inetsrv\iis\svcs\infocomm\cache2\tsmemp.hxx
#define TYPE_ALLOC( Type )          (ALLOC( sizeof( Type )))
#define TYPE_ALLOC( Type )          (ALLOC( sizeof( Type )))

// inetsrv\iis\svcs\infocomm\cache\getdirp.cxx
        #define DIR_ALLOC_SIZE  (DIRECTORY_BUFFER_SIZE + sizeof (LIST_ENTRY))

// inetsrv\iis\svcs\infocomm\cache\metacach.cxx
# define DEF_MD_REC_SIZE   ((1 + DEFAULT_MD_RECORDS) * \
                            (sizeof(METADATA_RECORD) + DEFAULT_RECORD_SIZE))

// inetsrv\iis\svcs\infocomm\cache\tsmemp.hxx
#define TYPE_ALLOC( Type )          (ALLOC( sizeof( Type )))
#define TYPE_ALLOC( Type )          (ALLOC( sizeof( Type )))

// inetsrv\iis\svcs\infocomm\cache\win95\getdirpw.cxx
        #define DIR_ALLOC_SIZE  (DIRECTORY_BUFFER_SIZE + sizeof (LIST_ENTRY))

// inetsrv\iis\svcs\infocomm\common\iisassoc.cxx
#define HASH_FROM_CONTEXT(ctx)                                      \
            (                                                       \
                (m_HashIpAddress ? ctx->IpAddressHash : 0) +        \
                (m_HashHostName ? ctx->HostNameHash : 0)            \
            )

// inetsrv\iis\svcs\infocomm\common\vroots.cxx
#define CCH_VROOT_ROOT   (sizeof(VROOT_ROOT) - 1)

// inetsrv\iis\svcs\infocomm\spuddrv\context.c
#define LOCK_HANDLE_TABLE()                                                 \
    if( TRUE ) {                                                            \
        KeEnterCriticalRegion();                                            \
        ExAcquireResourceExclusiveLite(                                     \
            &SpudNonpagedData->ReqHandleTableLock,                          \
            TRUE                                                            \
            );                                                              \
    } else

// inetsrv\iis\svcs\irtl\iiscrypt\lib\icryptp.h
#define ALIGN_DOWN(count,size) \
            ((ULONG)(count) & ~((ULONG)(size) - 1))
#define CALC_BLOB_DATA_LENGTH(datalen,siglen) \
            ((sizeof(IC_BLOB) - sizeof(IIS_CRYPTO_BLOB)) + \
                ((siglen) + ( (siglen) ? ALIGN_8(datalen) : (datalen) )))
#define CALC_BLOB_DATA_LENGTH2(datalen,saltlen) \
            ((sizeof(IC_BLOB2) - sizeof(IIS_CRYPTO_BLOB)) + \
                (saltlen) + (ALIGN_8(datalen)))

// inetsrv\iis\svcs\irtl\svmap\svmap.cpp
#define DEFINE_SV( token ) { #token, sizeof(#token) - 1 },

// inetsrv\iis\svcs\nntp\nntpctrs\perfutil.h
#define PVOID_MULTIPLE(x) (((x+sizeof(PVOID)-1)/sizeof(PVOID))*sizeof(PVOID))

// inetsrv\iis\svcs\nntp\search\faildrive\fail.h
#define Iss_OnStartPage(This,piUnk)	\
    (This)->lpVtbl -> OnStartPage(This,piUnk)
#define Iss_OnEndPage(This)	\
    (This)->lpVtbl -> OnEndPage(This)

// inetsrv\iis\svcs\nntp\search\qrydb\asptlb5.h
#define IResponse_WriteBlock(This,iBlockNumber)	\
    (This)->lpVtbl -> WriteBlock(This,iBlockNumber)
#define ISessionObject_get_CodePage(This,plvar)	\
    (This)->lpVtbl -> get_CodePage(This,plvar)
#define ISessionObject_put_CodePage(This,lvar)	\
    (This)->lpVtbl -> put_CodePage(This,lvar)

// inetsrv\iis\svcs\nntp\search\qryobj\asptlb5.h
#define IResponse_WriteBlock(This,iBlockNumber)	\
    (This)->lpVtbl -> WriteBlock(This,iBlockNumber)
#define ISessionObject_get_CodePage(This,plvar)	\
    (This)->lpVtbl -> get_CodePage(This,plvar)
#define ISessionObject_put_CodePage(This,lvar)	\
    (This)->lpVtbl -> put_CodePage(This,lvar)

// inetsrv\iis\svcs\nntp\search\utest\meta2.h
#define Ireq_OnStartPage(This,piUnk)	\
    (This)->lpVtbl -> OnStartPage(This,piUnk)
#define Ireq_OnEndPage(This)	\
    (This)->lpVtbl -> OnEndPage(This)

// inetsrv\iis\svcs\nntp\search\utest\search.h
#define Iqry_OnStartPage(This,piUnk)	\
    (This)->lpVtbl -> OnStartPage(This,piUnk)
#define Iqry_OnEndPage(This)	\
    (This)->lpVtbl -> OnEndPage(This)

// inetsrv\iis\svcs\nntp\server\server\feedmgr.h
#define FEEDBLOCK_SIZE( _fb )                       \
            (sizeof(NNTP_FEED_INFO) +               \
            (lstrlen(feedBlock->ServerName) + 1 +    \
            MultiListSize(feedBlock->Newsgroups) +  \
            MultiListSize(feedBlock->Distribution)) * sizeof(WCHAR))	\
			(lstrlen(FeedTempDirectory) + 1)

// inetsrv\iis\svcs\smtp\aqueue\advqueue\msgref.h
#define MSGREF_STANDARD_CPOOL_SIZE \
    (((sizeof(CPoolMsgRef) - sizeof(CMsgRef) + \
      CMsgRef::size(MSGREF_STANDARD_DOMAINS)) + 0x10) & ~0xF)

// inetsrv\iis\svcs\smtp\aqueue\cat\inc\catperf.h
#define INCREMENT_BLOCK_COUNTER_AMOUNT(PBlock, CounterName, Amount) \
    InterlockedExchangeAdd((PLONG) (& ((PBlock)->CounterName)), (Amount))
#define INCREMENT_BLOCK_COUNTER(PBlock, CounterName) \
    InterlockedIncrement((PLONG) (& ((PBlock)->CounterName)))
#define DECREMENT_BLOCK_COUNTER(PBlock, CounterName) \
    InterlockedDecrement((PLONG) (& ((PBlock)->CounterName)))
#define INCREMENT_LDAP_COUNTER(CounterName) \
    INCREMENT_BLOCK_COUNTER(&g_LDAPPerfBlock, CounterName)
#define DECREMENT_LDAP_COUNTER(CounterName) \
    DECREMENT_BLOCK_COUNTER(&g_LDAPPerfBlock, CounterName)

// inetsrv\iis\svcs\staxcore\setup\ndmgr.h
#define IPropertySheetCallback_AddPage(This,hPage)	\
    (This)->lpVtbl -> AddPage(This,hPage)
#define IPropertySheetCallback_RemovePage(This,hPage)	\
    (This)->lpVtbl -> RemovePage(This,hPage)
#define IPropertySheetProvider_AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)	\
    (This)->lpVtbl -> AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)
#define IPropertySheetProvider_AddExtensionPages(This)	\
    (This)->lpVtbl -> AddExtensionPages(This)
#define IPropertySheetProvider_Show(This,window,page)	\
    (This)->lpVtbl -> Show(This,window,page)
#define IExtendPropertySheet_CreatePropertyPages(This,lpProvider,handle,lpIDataObject)	\
    (This)->lpVtbl -> CreatePropertyPages(This,lpProvider,handle,lpIDataObject)
#define IExtendPropertySheet_QueryPagesFor(This,lpDataObject)	\
    (This)->lpVtbl -> QueryPagesFor(This,lpDataObject)
#define WINDOW_DATA_SIZE (sizeof(long) * 4)
#define IPropertySheetProviderPrivate_AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)	\
    (This)->lpVtbl -> AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)
#define IPropertySheetProviderPrivate_AddExtensionPages(This)	\
    (This)->lpVtbl -> AddExtensionPages(This)
#define IPropertySheetProviderPrivate_Show(This,window,page)	\
    (This)->lpVtbl -> Show(This,window,page)
#define IPropertySheetProviderPrivate_ShowEx(This,window,page,bModalPage)	\
    (This)->lpVtbl -> ShowEx(This,window,page,bModalPage)

// inetsrv\iis\svcs\staxcore\staxmem\_exchmem.h
#define	cbMHeapHeader		sizeof(HANDLE)
#define	cbMHeapHeader		(2*sizeof(HANDLE))

// inetsrv\iis\svcs\svcloc\reg.hxx
#define DEFAULT_CLASS_SIZE  sizeof(DEFAULT_CLASS)

// inetsrv\iis\svcs\w3\cisa\isattest\isattest.cpp
# define LEN_PSZ_FAILURE_MSG (sizeof(PSZ_FAILURE_MSG) - 1)

// inetsrv\iis\svcs\w3\cisa\tisat1\tisat1.cpp
# define LEN_PSZ_FAILURE_MSG (sizeof(PSZ_FAILURE_MSG) - 1)

// inetsrv\iis\svcs\w3\gateways\probe\worker.cxx
# define DefunSizeInfo( a)  { #a , sizeof(a) }

// inetsrv\iis\svcs\w3\gateways\ssinc\ssinc.hxx
#define SSI_DEF_ERRMSG_LEN      sizeof( SSI_DEF_ERRMSG )
#define SSI_DEF_ABBREV_LEN      sizeof( SSI_DEF_ABBREV )

// inetsrv\iis\svcs\w3\gateways\ssincold\ssinc.hxx
#define SSI_DEF_ERRMSG_LEN      sizeof( SSI_DEF_ERRMSG )
#define SSI_DEF_CMDPREFIX_LEN   sizeof( SSI_DEF_CMDPREFIX )
#define SSI_DEF_CMDPOSTFIX_LEN  sizeof( SSI_DEF_CMDPOSTFIX )
#define SSI_DEF_ABBREV_LEN      sizeof( SSI_DEF_ABBREV )
#define SSI_DEF_ON_LEN          sizeof( SSI_DEF_ON )
#define SSI_DEF_OFF_LEN         sizeof( SSI_DEF_OFF )

// inetsrv\iis\svcs\w3\server\dirlist.cxx
#define PAD_COL_SPACING       (sizeof(COL_SPACE) - 1)

// inetsrv\iis\svcs\w3\server\doget.cxx
#define ADJ_FIRST                   (2-(sizeof(DELIMIT_FIRST)-1))
        #define SetAppend(s)  (szAppend=(s), cbAppend=sizeof(s)-1)

// inetsrv\iis\svcs\w3\server\extmap.cxx
#define GET_SIZE (sizeof("GET"))

// inetsrv\iis\svcs\w3\server\hgetinfo.cxx
# define LEN_PSZ_HTTP_PREFIX  (sizeof(PSZ_HTTP_PREFIX) - 1)

// inetsrv\iis\svcs\w3\server\httpreq.cxx
#define CGI_HEADER_PREFIX_CCH   (sizeof(CGI_HEADER_PREFIX_SZ) - 1)
#define EXTRA_PRECOND_SIZE  (sizeof("Connection: keep-alive\r\n") - 1 +\
                            sizeof("Content-Length: 4294967295\r\n\r\n") - 1)

// inetsrv\iis\svcs\w3\server\w3meta.cxx
#define SIZEOF_EXPIRE_HEADER            sizeof("Expires: \r\n")

// inetsrv\iis\svcs\wam\tests\isagen\dofunc.cxx
# define DefunVariable( a)  { #a , sizeof(#a) }

// inetsrv\iis\svcs\wp\inc\cluadmex.h
#define IWCPropertySheetCallback_AddPropertySheetPage(This,hpage)	\
    (This)->lpVtbl -> AddPropertySheetPage(This,hpage)
#define IWEExtendPropertySheet_CreatePropertySheetPages(This,piData,piCallback)	\
    (This)->lpVtbl -> CreatePropertySheetPages(This,piData,piCallback)
#define IWCWizardCallback_AddWizardPage(This,hpage)	\
    (This)->lpVtbl -> AddWizardPage(This,hpage)
#define IWCWizardCallback_EnableNext(This,hpage,bEnable)	\
    (This)->lpVtbl -> EnableNext(This,hpage,bEnable)
#define IWEExtendWizard_CreateWizardPages(This,piData,piCallback)	\
    (This)->lpVtbl -> CreateWizardPages(This,piData,piCallback)

// inetsrv\iis\svcs\wp\inc\clusapi.h
#define ALIGN_CLUSPROP( count ) ((count + 3) & ~3)

// inetsrv\iis\ui\admin\appconfig\mappingpage.cpp
#define CHECK_VERBS()\
   m_bVerbsValid = \
      (m_verbs_index > 0 && lstrlen(m_verbs) != 0) || (m_verbs_index == 0)
#define CHECK_EXT()\
   m_bExtValid = (lstrlen(m_ext) != 0 && StrCmp(m_ext, _T(".")) != 0)
#define CHECK_EXEC(buf)\
   m_bExecValid = (lstrlen((buf)) != 0 && !PathIsUNC((buf)))
#define ENABLE_OK()\
   ::EnableWindow(GetDlgItem(IDOK), m_bExtValid && m_bExecValid && m_bVerbsValid)

// inetsrv\iis\ui\admin\certwiz\securitysettingspage.cpp
#define COUNT_KEYLENGTH sizeof(dwPredefinedKeyLength)/sizeof(dwPredefinedKeyLength[0])

// inetsrv\iis\ui\admin\comprop\ipaddres.h
  #define GETIP_FOURTH(x)            ((x)     & 0xff)

// inetsrv\iis\ui\admin\fscfg\fscfg.cpp
#define BUTTON_BMP_BACKGROUND       RGB(192, 192, 192)      // Lt. Gray
#define SERVICE_BMP_BACKGROUND      RGB(255,0,255)          // Purple
#define CHILD_BMP_BACKGROUND         RGB(255, 0, 255)      // Purple

// inetsrv\iis\ui\admin\mmc\ndmgr.h
#define IPropertySheetProviderPrivate_AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)    \
    (This)->lpVtbl -> AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)
#define IPropertySheetProviderPrivate_AddExtensionPages(This)   \
    (This)->lpVtbl -> AddExtensionPages(This)
#define IPropertySheetProviderPrivate_Show(This,window,page)    \
    (This)->lpVtbl -> Show(This,window,page)
#define IPropertySheetProviderPrivate_ShowEx(This,hwnd,page,bModalPage) \
    (This)->lpVtbl -> ShowEx(This,hwnd,page,bModalPage)
#define IPropertySheetProviderPrivate_AddMultiSelectionExtensionPages(This,lMultiSelection) \
    (This)->lpVtbl -> AddMultiSelectionExtensionPages(This,lMultiSelection)
#define ITaskPadHost_GetBackground(This,szTaskGroup,szBitmapResource)   \
    (This)->lpVtbl -> GetBackground(This,szTaskGroup,szBitmapResource)

// inetsrv\iis\ui\admin\template\cfg\tmscfg.cpp
#define BUTTON_BMP_BACKGROUND       RGB(192, 192, 192)      // Lt. Gray

// inetsrv\iis\ui\admin\template\cfgk2\tmscfg.cpp
#define BUTTON_BMP_BACKGROUND       RGB(192, 192, 192)      // Lt. Gray
#define SERVICE_BMP_BACKGROUND      RGB(192, 192, 192)      // Lt. Gray
#define VDIR_BMP_BACKGROUND         RGB(192, 192, 192)      // Lt. Gray

// inetsrv\iis\ui\admin\w3scfg\w3scfg.cpp
#define BUTTON_BMP_BACKGROUND       RGB(192, 192, 192)      // Lt. Gray
#define SERVICE_BMP_BACKGROUND      RGB(255, 0, 255)      // Magenta
#define CHILD_BMP_BACKGROUND         RGB(255, 0, 255)      // Magenta

// inetsrv\iis\utils\pwalker\pwalker.c
#define Clear(x) memset(&x, 0, sizeof(x))

// inetsrv\intlwb\thai2\sth\lextable.hpp
#define INUPPERPAGES(ch) (ch & 0xff00)  // this is the same as ch > 0x00ff

// inetsrv\intlwb\thai2\sth\nlglib.h
#define INUPPERPAGES(ch) (ch & 0xff00)  // this is the same as ch > 0x00ff

// inetsrv\msmq\sdk\samples\direncrypt\direncrypt.cpp
    #define QMPROPS (sizeof(aQmPropId) / sizeof(*aQmPropId))
    #define MSGPROPS (sizeof(aMsgPropId) / sizeof(*aMsgPropId))

// inetsrv\msmq\src\ac\internal.h
#define ALIGNUP_ULONG(x, g) (((ULONG)((x) + ((g)-1))) & ~((ULONG)((g)-1)))

// inetsrv\msmq\src\ac\win95\ntddk95.h
#define RtlAnsiStringToUnicodeSize(STRING) (                 \
    NLS_MB_CODE_PAGE_TAG ?                                   \
    RtlxAnsiStringToUnicodeSize(STRING) :                    \
    ((STRING)->Length + sizeof((UCHAR)NULL)) * sizeof(WCHAR) \
)
#define SHORT_SIZE  (sizeof(USHORT))
#define LONG_SIZE       (sizeof(LONG))
#define ROUND_TO_PAGES(Size)  (((ULONG)(Size) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))
#define PAGE_ALIGN(Va) ((PVOID)((ULONG)(Va) & ~(PAGE_SIZE - 1)))
#define IoSizeOfIrp( StackSize ) \
    ((USHORT) (sizeof( IRP ) + ((StackSize) * (sizeof( IO_STACK_LOCATION )))))

// inetsrv\msmq\src\admin\mqsnap\atlsnap.h
#define BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname) \
	HRESULT GetDataClass(IDataObject* pDataObject, CSnapInItem** ppItem, DATA_OBJECT_TYPES* pType) \
	{ \
		if (ppItem == NULL) \
			return E_POINTER; \
		if (pType == NULL) \
			return E_POINTER; \
\
		*ppItem = NULL; \
\
		*pType = CCT_UNINITIALIZED; \
\
		STGMEDIUM stgmedium = { TYMED_HGLOBAL, NULL }; \
		FORMATETC formatetc = { CSnapInItem::m_CCF_NODETYPE, \
			NULL, \
			DVASPECT_CONTENT, \
			-1, \
			TYMED_HGLOBAL \
		}; \
\
		stgmedium.hGlobal = GlobalAlloc(0, sizeof(GUID)); \
		if (stgmedium.hGlobal == NULL) \
			return E_OUTOFMEMORY; \
\
		HRESULT hr = pDataObject->GetDataHere(&formatetc, &stgmedium); \
		if (FAILED(hr)) \
		{ \
			GlobalFree(stgmedium.hGlobal); \
			return hr; \
		} \
\
		GUID guid; \
		memcpy(&guid, stgmedium.hGlobal, sizeof(GUID)); \
\
		GlobalFree(stgmedium.hGlobal); \
		hr = S_OK;

// inetsrv\msmq\src\admin\mqsnap\strconv.cpp
#define END_CONVERSION_FUNCTION \
    }; \
    static const  DWORD x_dwMapSize = sizeof(l_astrIdMap) / sizeof(l_astrIdMap[0]); \
    static BOOL l_fFirstTime = TRUE; \
    static TCHAR l_atstrResults[x_dwMapSize][x_dwMaxDisplayLen]; \
    return CodeToString(dwCode, l_atstrResults, l_astrIdMap, \
                        x_dwMapSize, &l_fFirstTime); \
}

// inetsrv\msmq\src\apps\mqdiag\mqstore\xact.cpp
#define readvar(type)   *(type *)p; p += sizeof(type)

// inetsrv\msmq\src\apps\nmparser\attachfalcon.cpp
#define ALIGNUP4(x) ((((ULONG)(x))+3) & ~3)

// inetsrv\msmq\src\ds\mqdscli\rpcdscli.h
#define sizeof_tls_bind_data   (sizeof(MQISCLI_RPCBINDING))

// inetsrv\msmq\src\inc\mfc\afx.h
#define AFX_ZERO_INIT_OBJECT(base_class) \
	memset(((base_class*)this)+1, 0, sizeof(*this) - sizeof(class base_class));

// inetsrv\msmq\src\inc\mqdbmgr.h
#define INIT_COLUMNDEFEX(Col)                         \
   Col.cbSize         = sizeof(MQDBCOLUMNDEFEX) ;     \
   Col.lpszColumnName = NULL ;                        \
   Col.mqdbColumnType = MQDB_LONG ;                   \
   Col.nColumnLength  = 0 ;                           \
   Col.fPrimaryKey    = FALSE ;                       \
   Col.fUnique        = FALSE ;                       \
   Col.fNull          = TRUE ;
#define INIT_COLUMNVAL(Col)                        \
   Col.cbSize         = sizeof(MQDBCOLUMNVAL) ;    \
   Col.lpszColumnName = NULL ;                     \
   Col.nColumnValue   = 0 ;                        \
   Col.nColumnLength  = 0 ;                        \
   Col.mqdbColumnType = MQDB_LONG ;                \
   Col.dwReserve_A    = 0

// inetsrv\msmq\src\inc\mqwin64.h
#define ALIGNUP_ULONG(x, g) (((ULONG)((x) + ((g)-1))) & ~((ULONG)((g)-1)))

// inetsrv\msmq\src\inc\perfctr.h
#define OBJECT_DEFINITION_SIZE(NumCounters) (sizeof (PERF_OBJECT_TYPE)+\
                                             NumCounters*sizeof(PERF_COUNTER_DEFINITION))

// inetsrv\msmq\src\inc\ph.h
#define ALIGNUP4_ULONG(x) ((((ULONG)(x))+3) & ~((ULONG)3))
#define ALIGNUP2_ULONG(x) ((((ULONG)(x))+1) & ~((ULONG)1))

// inetsrv\msmq\src\replserv\mq1repl\migrepl.h
#define  OBJECTCLASS_FILTER_LEN  (sizeof(OBJECTCLASS_FILTER))

// inetsrv\msmq\src\replserv\mqrpperf\mqrepst.h
#define DATA_BLOCK_SIZE(num)    (sizeof(PERF_OBJECT_TYPE )+\
							     sizeof(PERF_COUNTER_DEFINITION )*num +\
							     sizeof(PERF_COUNTER_BLOCK ) +\
							     COUNTER_DATA_SIZE * num)
#define CONFIG_BLOCK_SIZE(num) (sizeof(PERF_OBJECT_TYPE )+\
							    sizeof(PERF_COUNTER_DEFINITION )*num +\
							    sizeof(PERF_COUNTER_BLOCK ))
#define OBJECT_DEFINITION_SIZE(num) (sizeof (PERF_OBJECT_TYPE)+\
                                     num*sizeof(PERF_COUNTER_DEFINITION))
#define OBJECT_TYPE_SIZE        sizeof(PERF_OBJECT_TYPE)
#define COUNTER_BLOCK_SIZE      sizeof(PERF_COUNTER_BLOCK)

// inetsrv\query\cindex\set.hxx
#define SIMPLE_SET_SIZE  (8 * sizeof(set_t))

// inetsrv\query\common\spy.hxx
#define ROUNDUP_(size,amount)       (((ULONG)(size)+((amount)-1))&~((amount)-1))

// inetsrv\query\filters\office\src\findfast\convapi.h
#define cbFIC sizeof(FIC)

// inetsrv\query\filters\office\src\findfast\dmixlrd.c
   #define ROW_COL_SIZE  (long)(sizeof(RC))
   #define HDR_SIZE  (long)(sizeof(RECHDR))
   #define NHDR_SIZE (long)(sizeof(noteHdr))

// inetsrv\query\filters\office\src\findfast\dmwnaloc.c
#define MEM_MAX_ALLOC       (MEM_PAGE_SIZE - (sizeof(PageNode) + MEM_ALLOC_EXTRA))
#define MEM_EMPTY_PAGE_SIZE (MEM_PAGE_SIZE - sizeof(PageNode))

// inetsrv\query\h\ciexcpt.hxx
#define END_CONSTRUCTION(class)                                 \
                                                                \
        _Activate( sizeof(class), &class::_ObjectUnwind );
#define END_MULTINHERITED_CONSTRUCTION(class, base1)    \
                                                        \
        base1::_Activate(sizeof(class), &class::_ObjectUnwind);

// inetsrv\query\kbyacc\defs.h
#define NEW(t)          ((t*)allocate(sizeof(t)))
#define NEW2(n,t)       ((t*)allocate((unsigned)((n)*sizeof(t))))

// inetsrv\query\ntciutil\oleprop.cxx
#define VCASE( vvar, type )                                             \
    cb += var[0].vvar.cElems * sizeof(var[0].vvar.pElems[0]);           \
    if ( cb <= *pcb )                                                   \
    {                                                                   \
        pbData->vvar.pElems = (type *)PastHeader(pbData);               \
        memcpy( pbData->vvar.pElems,                                    \
                var[0].vvar.pElems,                                     \
                var[0].vvar.cElems * sizeof(var[0].vvar.pElems[0]) );   \
    }

// inetsrv\query\sdk\htmlprop\filtreg.hxx
#define DEFINE_REGISTERFILTER( Name, Handler, Filter, aClasses )  \
                                                               \
STDAPI Name##UnregisterServer()                                \
{                                                              \
    /*                                                         \
     * Always remove Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = UnRegisterAHandler( Handler );              \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = UnRegisterAFilter( Filter );                 \
    else                                                       \
        UnRegisterAFilter( Filter );                           \
                                                               \
    for ( unsigned i = 0; i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
    {                                                          \
        if ( ERROR_SUCCESS == dwError )                        \
            dwError = UnRegisterAnExt( aClasses[i] );          \
        else                                                   \
             UnRegisterAnExt( aClasses[i] );                   \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return S_FALSE;                                        \
}                                                              \
                                                               \
STDAPI Name##RegisterServer()                                  \
{                                                              \
    /*                                                         \
     * Always create Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = RegisterAHandler( Handler );                \
                                                               \
    /*                                                         \
     * First, register the CLSID and persistent handler,       \
     * then work back to the class description and the         \
     * extension. This ensures we cover all possible           \
     * mappings.                                               \
     *                                                         \
     */                                                        \
                                                               \
    OSVERSIONINFO Version;                                     \
    Version.dwOSVersionInfoSize = sizeof(Version);             \
                                                               \
    BOOL fAppendOnly = FALSE;                                  \
                                                               \
    if ( GetVersionEx( &Version ) &&                           \
         Version.dwPlatformId == VER_PLATFORM_WIN32_NT &&      \
         Version.dwMajorVersion >= 5 )                         \
    {                                                          \
        fAppendOnly = TRUE;                                    \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = RegisterAFilter( Filter );                   \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterACLSID( aClasses[i], Handler.pwszClassId, 0, fAppendOnly );                        \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClass( aClasses[i], Handler.pwszClassId, 0, fAppendOnly );                        \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClassAndExt( aClasses[i], Handler.pwszClassId, fAppendOnly );                     \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return SELFREG_E_CLASS;                                \
}
#define DEFINE_REGISTERFILTER2( Name, Handler, Filter, aClasses )  \
                                                               \
STDAPI Name##UnregisterServer()                                \
{                                                              \
    /*                                                         \
     * Always remove Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = UnRegisterAHandler( Handler );              \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = UnRegisterAFilter( Filter );                 \
    else                                                       \
        UnRegisterAFilter( Filter );                           \
                                                               \
    for ( unsigned i = 0; i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
    {                                                          \
        if ( ERROR_SUCCESS == dwError )                        \
            dwError = UnRegisterAnExt( aClasses[i] );          \
        else                                                   \
            UnRegisterAnExt( aClasses[i] );                    \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return S_FALSE;                                        \
}                                                              \
                                                               \
STDAPI Name##RegisterServer()                                  \
{                                                              \
    /*                                                         \
     * Always create Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = RegisterAHandler( Handler );                \
                                                               \
    /*                                                         \
     * First, register the CLSID and persistent handler,       \
     * then work back to the class description and the         \
     * extension. This ensures we cover all possible           \
     * mappings.                                               \
     *                                                         \
     */                                                        \
                                                               \
    OSVERSIONINFO Version;                                     \
    Version.dwOSVersionInfoSize = sizeof(Version);             \
                                                               \
    BOOL fAppendOnly = FALSE;                                  \
                                                               \
    if ( GetVersionEx( &Version ) &&                           \
         Version.dwPlatformId == VER_PLATFORM_WIN32_NT &&      \
         Version.dwMajorVersion >= 5 )                         \
    {                                                          \
        fAppendOnly = TRUE;                                    \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = RegisterAFilter( Filter );                   \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterACLSID( aClasses[i], Handler.pwszClassId, 0, FALSE, FALSE );                \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClass( aClasses[i], Handler.pwszClassId, 0, fAppendOnly );                        \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClassAndExt( aClasses[i], Handler.pwszClassId, fAppendOnly );                     \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return SELFREG_E_CLASS;                                \
}

// inetsrv\query\sdk\ifilter\filtreg.hxx
#define DEFINE_REGISTERFILTER( Name, Handler, Filter, aClasses )  \
                                                               \
STDAPI Name##UnregisterServer()                                \
{                                                              \
    /*                                                         \
     * Always remove Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = UnRegisterAHandler( Handler );              \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = UnRegisterAFilter( Filter );                 \
    else                                                       \
        UnRegisterAFilter( Filter );                           \
                                                               \
    for ( unsigned i = 0; i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
    {                                                          \
        if ( ERROR_SUCCESS == dwError )                        \
            dwError = UnRegisterAnExt( aClasses[i] );          \
        else                                                   \
             UnRegisterAnExt( aClasses[i] );                   \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return S_FALSE;                                        \
}                                                              \
                                                               \
STDAPI Name##RegisterServer()                                  \
{                                                              \
    /*                                                         \
     * Always create Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = RegisterAHandler( Handler );                \
                                                               \
    /*                                                         \
     * First, register the CLSID and persistent handler,       \
     * then work back to the class description and the         \
     * extension. This ensures we cover all possible           \
     * mappings.                                               \
     *                                                         \
     */                                                        \
                                                               \
    OSVERSIONINFO Version;                                     \
    Version.dwOSVersionInfoSize = sizeof(Version);             \
                                                               \
    BOOL fAppendOnly = FALSE;                                  \
                                                               \
    if ( GetVersionEx( &Version ) &&                           \
         Version.dwPlatformId == VER_PLATFORM_WIN32_NT &&      \
         Version.dwMajorVersion >= 5 )                         \
    {                                                          \
        fAppendOnly = TRUE;                                    \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = RegisterAFilter( Filter );                   \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterACLSID( aClasses[i], Handler.pwszClassId, 0, fAppendOnly );                        \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClass( aClasses[i], Handler.pwszClassId, 0, fAppendOnly );                        \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClassAndExt( aClasses[i], Handler.pwszClassId, fAppendOnly );                     \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return SELFREG_E_CLASS;                                \
}
#define DEFINE_REGISTERFILTER2( Name, Handler, Filter, aClasses )  \
                                                               \
STDAPI Name##UnregisterServer()                                \
{                                                              \
    /*                                                         \
     * Always remove Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = UnRegisterAHandler( Handler );              \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = UnRegisterAFilter( Filter );                 \
    else                                                       \
        UnRegisterAFilter( Filter );                           \
                                                               \
    for ( unsigned i = 0; i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
    {                                                          \
        if ( ERROR_SUCCESS == dwError )                        \
            dwError = UnRegisterAnExt( aClasses[i] );          \
        else                                                   \
            UnRegisterAnExt( aClasses[i] );                    \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return S_FALSE;                                        \
}                                                              \
                                                               \
STDAPI Name##RegisterServer()                                  \
{                                                              \
    /*                                                         \
     * Always create Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = RegisterAHandler( Handler );                \
                                                               \
    /*                                                         \
     * First, register the CLSID and persistent handler,       \
     * then work back to the class description and the         \
     * extension. This ensures we cover all possible           \
     * mappings.                                               \
     *                                                         \
     */                                                        \
                                                               \
    OSVERSIONINFO Version;                                     \
    Version.dwOSVersionInfoSize = sizeof(Version);             \
                                                               \
    BOOL fAppendOnly = FALSE;                                  \
                                                               \
    if ( GetVersionEx( &Version ) &&                           \
         Version.dwPlatformId == VER_PLATFORM_WIN32_NT &&      \
         Version.dwMajorVersion >= 5 )                         \
    {                                                          \
        fAppendOnly = TRUE;                                    \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = RegisterAFilter( Filter );                   \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterACLSID( aClasses[i], Handler.pwszClassId, 0, FALSE, FALSE );                \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClass( aClasses[i], Handler.pwszClassId, 0, fAppendOnly );                        \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClassAndExt( aClasses[i], Handler.pwszClassId, fAppendOnly );                     \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return SELFREG_E_CLASS;                                \
}

// inetsrv\query\sdk\smpfilt\filtreg.hxx
#define DEFINE_REGISTERFILTER( Name, Handler, Filter, aClasses )  \
                                                               \
STDAPI Name##UnregisterServer()                                \
{                                                              \
    /*                                                         \
     * Always remove Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = UnRegisterAHandler( Handler );              \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = UnRegisterAFilter( Filter );                 \
    else                                                       \
        UnRegisterAFilter( Filter );                           \
                                                               \
    for ( unsigned i = 0; i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
    {                                                          \
        if ( ERROR_SUCCESS == dwError )                        \
            dwError = UnRegisterAnExt( aClasses[i] );          \
        else                                                   \
             UnRegisterAnExt( aClasses[i] );                   \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return S_FALSE;                                        \
}                                                              \
                                                               \
STDAPI Name##RegisterServer()                                  \
{                                                              \
    /*                                                         \
     * Always create Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = RegisterAHandler( Handler );                \
                                                               \
    /*                                                         \
     * First, register the CLSID and persistent handler,       \
     * then work back to the class description and the         \
     * extension. This ensures we cover all possible           \
     * mappings.                                               \
     *                                                         \
     */                                                        \
                                                               \
    OSVERSIONINFO Version;                                     \
    Version.dwOSVersionInfoSize = sizeof(Version);             \
                                                               \
    BOOL fAppendOnly = FALSE;                                  \
                                                               \
    if ( GetVersionEx( &Version ) &&                           \
         Version.dwPlatformId == VER_PLATFORM_WIN32_NT &&      \
         Version.dwMajorVersion >= 5 )                         \
    {                                                          \
        fAppendOnly = TRUE;                                    \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = RegisterAFilter( Filter );                   \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterACLSID( aClasses[i], Handler.pwszClassId, 0, fAppendOnly );                        \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClass( aClasses[i], Handler.pwszClassId, 0, fAppendOnly );                        \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClassAndExt( aClasses[i], Handler.pwszClassId, fAppendOnly );                     \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return SELFREG_E_CLASS;                                \
}
#define DEFINE_REGISTERFILTER2( Name, Handler, Filter, aClasses )  \
                                                               \
STDAPI Name##UnregisterServer()                                \
{                                                              \
    /*                                                         \
     * Always remove Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = UnRegisterAHandler( Handler );              \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = UnRegisterAFilter( Filter );                 \
    else                                                       \
        UnRegisterAFilter( Filter );                           \
                                                               \
    for ( unsigned i = 0; i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
    {                                                          \
        if ( ERROR_SUCCESS == dwError )                        \
            dwError = UnRegisterAnExt( aClasses[i] );          \
        else                                                   \
            UnRegisterAnExt( aClasses[i] );                    \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return S_FALSE;                                        \
}                                                              \
                                                               \
STDAPI Name##RegisterServer()                                  \
{                                                              \
    /*                                                         \
     * Always create Persistent Handler and Filter entries     \
     */                                                        \
                                                               \
    long dwError = RegisterAHandler( Handler );                \
                                                               \
    /*                                                         \
     * First, register the CLSID and persistent handler,       \
     * then work back to the class description and the         \
     * extension. This ensures we cover all possible           \
     * mappings.                                               \
     *                                                         \
     */                                                        \
                                                               \
    OSVERSIONINFO Version;                                     \
    Version.dwOSVersionInfoSize = sizeof(Version);             \
                                                               \
    BOOL fAppendOnly = FALSE;                                  \
                                                               \
    if ( GetVersionEx( &Version ) &&                           \
         Version.dwPlatformId == VER_PLATFORM_WIN32_NT &&      \
         Version.dwMajorVersion >= 5 )                         \
    {                                                          \
        fAppendOnly = TRUE;                                    \
    }                                                          \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        dwError = RegisterAFilter( Filter );                   \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterACLSID( aClasses[i], Handler.pwszClassId, 0, FALSE, FALSE );                \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClass( aClasses[i], Handler.pwszClassId, 0, fAppendOnly );                        \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        for ( unsigned i = 0; ERROR_SUCCESS == dwError && i < sizeof(aClasses)/sizeof(aClasses[0]); i++ ) \
            dwError = RegisterAClassAndExt( aClasses[i], Handler.pwszClassId, fAppendOnly );                     \
                                                               \
    if ( ERROR_SUCCESS == dwError )                            \
        return S_OK;                                           \
    else                                                       \
        return SELFREG_E_CLASS;                                \
}

// inetsrv\query\tdbv1\tdbv1.cxx
#define PROP1_cb ( sizeof ULONG )
#define PROP6_cb ( sizeof PROPVARIANT )
#define PROP7_cb ( sizeof GUID )
#define PROP9_cb ( sizeof ULONG )
#define PROP14_cb ( sizeof short )
#define PROP15_cb ( sizeof (unsigned short) )
#define PROP16_cb ( sizeof int )
#define PROP17_cb ( sizeof (float) )
#define PROP18_cb ( sizeof double )
#define PROP21_cb (sizeof( void *) )
#define PROP22_CVALS ( sizeof aClipData / sizeof aClipData[0] )

// inetsrv\query\web\ixsso\asp\asptlb.h
#define IResponse_WriteBlock(This,iBlockNumber)	\
    (This)->lpVtbl -> WriteBlock(This,iBlockNumber)
#define ISessionObject_get_CodePage(This,plvar)	\
    (This)->lpVtbl -> get_CodePage(This,plvar)
#define ISessionObject_put_CodePage(This,lvar)	\
    (This)->lpVtbl -> put_CodePage(This,lvar)

// multimedia\danim\extinc\dxtmsft.h
#define IDXTMetaPageTurn_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IDXTMetaPageTurn_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IDXTMetaPageTurn_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IDXTMetaPageTurn_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IDXTMetaPageTurn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDXTMetaPageTurn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDXTMetaPageTurn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IDXTMetaPageTurn_get_Capabilities(This,pVal)	\
    (This)->lpVtbl -> get_Capabilities(This,pVal)
#define IDXTMetaPageTurn_get_Progress(This,pVal)	\
    (This)->lpVtbl -> get_Progress(This,pVal)
#define IDXTMetaPageTurn_put_Progress(This,newVal)	\
    (This)->lpVtbl -> put_Progress(This,newVal)
#define IDXTMetaPageTurn_get_StepResolution(This,pVal)	\
    (This)->lpVtbl -> get_StepResolution(This,pVal)
#define IDXTMetaPageTurn_get_Duration(This,pVal)	\
    (This)->lpVtbl -> get_Duration(This,pVal)
#define IDXTMetaPageTurn_put_Duration(This,newVal)	\
    (This)->lpVtbl -> put_Duration(This,newVal)
#define IDXTMetaPageTurn_get_Copyright(This,pVal)	\
    (This)->lpVtbl -> get_Copyright(This,pVal)
#define IDXTMetaPageTurn_put_Copyright(This,newVal)	\
    (This)->lpVtbl -> put_Copyright(This,newVal)

// multimedia\danim\extinc\dxtmsft3.h
#define IDXTText3D_get_XAlign(This,pbstr)	\
    (This)->lpVtbl -> get_XAlign(This,pbstr)
#define IDXTText3D_put_XAlign(This,pbstr)	\
    (This)->lpVtbl -> put_XAlign(This,pbstr)
#define IDXTText3D_get_YAlign(This,pbstr)	\
    (This)->lpVtbl -> get_YAlign(This,pbstr)
#define IDXTText3D_put_YAlign(This,pbstr)	\
    (This)->lpVtbl -> put_YAlign(This,pbstr)
#define IDXTText3D_get_ZAlign(This,pbstr)	\
    (This)->lpVtbl -> get_ZAlign(This,pbstr)
#define IDXTText3D_put_ZAlign(This,pbstr)	\
    (This)->lpVtbl -> put_ZAlign(This,pbstr)

// multimedia\danim\extinc\dxtrans.h
#define IDXSurfaceModifier_SetBackground(This,pSurface)	\
    (This)->lpVtbl -> SetBackground(This,pSurface)
#define IDXSurfaceModifier_GetBackground(This,ppSurface)	\
    (This)->lpVtbl -> GetBackground(This,ppSurface)
#define IDXSurfaceModifier_SetForeground(This,pSurface,bTile,pOrigin)	\
    (This)->lpVtbl -> SetForeground(This,pSurface,bTile,pOrigin)
#define IDXSurfaceModifier_GetForeground(This,ppSurface,pbTile,pOrigin)	\
    (This)->lpVtbl -> GetForeground(This,ppSurface,pbTile,pOrigin)
#define IDXTLabel_GetBackgroundColor(This,pVal)	\
    (This)->lpVtbl -> GetBackgroundColor(This,pVal)
#define IDXTLabel_SetBackgroundColor(This,newVal)	\
    (This)->lpVtbl -> SetBackgroundColor(This,newVal)
#define IDX2D_SetBackgroundBrush(This,pBrush)	\
    (This)->lpVtbl -> SetBackgroundBrush(This,pBrush)
#define IDX2D_GetBackgroundBrush(This,pBrush)	\
    (This)->lpVtbl -> GetBackgroundBrush(This,pBrush)

// multimedia\directx\ddrawex\dx3inc\ddrawi.h
#define VALID_ALIGNMENT( align ) (!((align == 0) || (align % 2) != 0 ))

// multimedia\directx\dinput\dx7\dll\diaphack.c
#define DECLARE_APPHACK_ENTRY(name, type, osmask) \
                { TEXT(#name), sizeof(type), osmask },

// multimedia\directx\dinput\dx8\dimap\dimap.cpp
#define OBJECT_ENTRY(MethodName,MethodID) \
        CAdvancedTracer \
        There_can_be_only_one_USETRACER_macro_per_block\
        (eObjectEntryBT,MethodName,MethodID,this);

// multimedia\directx\dinput\dx8\dll\diaphack.c
#define DECLARE_APPHACK_ENTRY(name, type, osmask) \
                { TEXT(#name), sizeof(type), osmask },

// multimedia\directx\dinput\pid\pidi.h
    #define PIDUSAGETXT(UsagePage, Usage )  \
        ( ( UsagePage == HID_USAGE_PAGE_PID && Usage < PIDUSAGETXT_MAX) ? g_rgUsageTxt[Usage] : NULL )

// multimedia\directx\dmusic\dmusic\dmcrchk.h
#define CHUNK_ALIGN(x) (((x) + SIZE_ALIGN - 1) & ~(SIZE_ALIGN - 1))

// multimedia\directx\dmusic\dmusic\dmextchk.h
#define CHUNK_ALIGN(x) (((x) + SIZE_ALIGN - 1) & ~(SIZE_ALIGN - 1))

// multimedia\directx\dmusic\dmusic\dswave.h
#define CHUNK_ALIGN(x) (((x) + SIZE_ALIGN - 1) & ~(SIZE_ALIGN - 1))

// multimedia\directx\dplay\dnet\common\perfinfo.cpp
#define PERF_INSTANCE_BLOCK_SIZE        ((sizeof( PERF_APPLICATION ) * PERF_INSTANCE_BLOCK_MAXENTRIES) + sizeof( PERF_HEADER ))

// multimedia\directx\dplay\dplay\dplay\classfac.c
#define VALIDEX_DIRECTPLAYCF_PTR( ptr ) \
        ((!IsBadWritePtr( ptr, sizeof( DPLAYCLASSFACTORY ))) && \
        ((ptr->lpVtbl == &directPlayClassFactoryVtbl) || \
		(ptr->lpVtbl == &directPlayLobbyClassFactoryVtbl)))

// multimedia\directx\dplay\dplay\dplay\dplaypr.h
#define VALID_DPLAY_INT( ptr ) \
        ( ptr && !IsBadWritePtr( ptr, sizeof( DPLAYI_DPLAY_INT )) && \
        ((ptr->lpVtbl == &dpCallbacks) || (ptr->lpVtbl == &dpCallbacks2) \
        || (ptr->lpVtbl == &dpCallbacks2A) || (ptr->lpVtbl == &dpCallbacksSP) \
		|| (ptr->lpVtbl == &dpCallbacks3) || (ptr->lpVtbl == &dpCallbacks3A) \
		|| (ptr->lpVtbl == &dpCallbacks4) || (ptr->lpVtbl == &dpCallbacks4A) \
		|| (ptr->lpVtbl == &dvtCallbacks) \
		) )

// multimedia\directx\dplay\dplobby\dplobby\dplobpr.h
#define VALID_DPLOBBY_INTERFACE( ptr ) \
        (!IsBadWritePtr(ptr, sizeof(DPLOBBYI_INTERFACE)) && \
        ((((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacks) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacksA) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacks2) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacks2A) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacks3) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacks3A) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacksSP)))

// multimedia\directx\dsound\dsound\dsaphack.c
#define DECLARE_APPHACK_ENTRY(name, type) \
                { TEXT(#name), sizeof(type) },

// multimedia\directx\dsound\dsound\dsmemmgr.c
#define MEMALIGN(size)      BLOCKALIGNPAD(size, sizeof(SIZE_T))
#define DSMEMBLOCK_SIZE     MEMALIGN(sizeof(DSMEMBLOCK))

// multimedia\directx\dsound\dsound\pset.h
#define DECLARE_PROPERTY_HANDLER2(property, get, set, datatype) \
                DECLARE_PROPERTY_HANDLER3(property, get, set, sizeof(datatype))

// multimedia\directx\dxg\d3d8\util\d3dflt.h
#define FPU_MODE_CHOP_ROUND(uMode) \
    ((uMode) | 0xc00)

// multimedia\directx\dxg\d3d\dx6\d3dutil\d3dflt.h
#define FPU_MODE_CHOP_ROUND(uMode) \
    ((uMode) | 0xc00)

// multimedia\directx\dxg\d3d\dx7\util\d3dflt.h
#define FPU_MODE_CHOP_ROUND(uMode) \
    ((uMode) | 0xc00)

// multimedia\directx\dxg\d3d\ref\rast\refs3tc.cpp
#define ForAllPixels            for(pixel=0; pixel < DXT_BLOCK_PIXELS; ++pixel)

// multimedia\directx\dxg\dd\ddraw\main\classfac.c
#define VALIDEX_DIRECTDRAWCF_PTR( ptr ) \
	( !IsBadWritePtr( ptr, sizeof( DDRAWCLASSFACTORY )) && \
	(ptr->lpVtbl == &directDrawClassFactoryVtbl) )

// multimedia\directx\dxg\dd\ddraw\main\ddrawpr.h
#define VALIDEX_DIRECTDRAWFACTORY2_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDFACTORY2 )) && \
        (ptr->lpVtbl == &ddFactory2Callbacks) )
#define VALIDEX_DIRECTDRAW_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DIRECTDRAW_INT )) && \
        ( (ptr->lpVtbl == &ddCallbacks) || \
          (ptr->lpVtbl == &dd2Callbacks) || \
          (ptr->lpVtbl == &dd4Callbacks) || \
          (ptr->lpVtbl == &dd7Callbacks) || \
          (ptr->lpVtbl == &dd2UninitCallbacks) || \
          (ptr->lpVtbl == &dd4UninitCallbacks) || \
          (ptr->lpVtbl == &dd7UninitCallbacks) || \
          (ptr->lpVtbl == &ddVideoPortContainerCallbacks) || \
          (ptr->lpVtbl == &ddKernelCallbacks) || \
          (ptr->lpVtbl == &ddMotionCompContainerCallbacks) || \
          (ptr->lpVtbl == &ddUninitCallbacks) ) )
#define VALIDEX_DIRECTDRAWSURFACE_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDRAWSURFACE_INT )) && \
        ( (ptr->lpVtbl == &ddSurfaceCallbacks ) || \
          (ptr->lpVtbl == &ddSurface7Callbacks ) || \
          (ptr->lpVtbl == &ddSurface4Callbacks ) || \
          (ptr->lpVtbl == &ddSurface3Callbacks ) || \
          (ptr->lpVtbl == &ddSurface2Callbacks ) || \
          (ptr->lpVtbl == &ddSurfaceKernelCallbacks ) || \
          (ptr->lpVtbl == &ddColorControlCallbacks ) || \
          (ptr->lpVtbl == &ddGammaControlCallbacks ) ) )
#define VALIDEX_DIRECTDRAWPALETTE_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDRAWPALETTE_INT )) && \
        (ptr->lpVtbl == &ddPaletteCallbacks) )
#define VALIDEX_DIRECTDRAWCLIPPER_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDRAWCLIPPER_INT )) && \
        ( (ptr->lpVtbl == &ddClipperCallbacks) || \
          (ptr->lpVtbl == &ddUninitClipperCallbacks) ) )
#define VALIDEX_DDCOLORCONTROL_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDCOLORCONTROL_INT )) && \
        (ptr->lpVtbl == &ddColorControlCallbacks) )
#define VALID_DDVIDEOPORT_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDVIDEOPORT_INT )) && \
        (   (ptr->lpVtbl == &ddVideoPortCallbacks) ||              \
            (ptr->lpVtbl == &ddVideoPortNotifyCallbacks)))
#define VALID_DDMOTIONCOMP_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDMOTIONCOMP_INT )) && \
        (ptr->lpVtbl == &ddMotionCompCallbacks) )

// multimedia\directx\dxg\ref8\common\dxtn.cpp
#define ForAllPixels        for(pixel=0; pixel < DXT_BLOCK_PIXELS; ++pixel)

// multimedia\directx\dxg\swrast\rgb\pch\d3dflt.h
#define FPU_MODE_CHOP_ROUND(uMode) \
    ((uMode) | 0xc00)

// multimedia\dshow\filters\asf\wmsdk\inc\wmsbuffer.h
#define IWMSBufferAllocator_AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)

// multimedia\dshow\filters\core\filgraph\filgraph\cachemap.cpp
#define ROUND(_x_) (((_x_) + 3) & ~ 3)

// multimedia\dshow\filters\mpeg1\inc\videocd.h
#define IS_MPEG_VIDEO_SECTOR(pSector)             \
    (((pSector)->SubHeader[1] >= 0x01 &&          \
      (pSector)->SubHeader[1] <= 0x03 ) &&        \
     ((pSector)->SubHeader[2] & 0x6E) == 0x62 &&  \
     ((pSector)->SubHeader[3] & 0x0F) == 0x0F)
#define IS_MPEG_AUDIO_SECTOR(pSector)             \
    ((pSector)->SubHeader[1] == 0x01 &&           \
     ((pSector)->SubHeader[2] & 0x6E) == 0x64 &&  \
     (pSector)->SubHeader[3] == 0x7F)
#define IS_MPEG_SECTOR(pSector)                   \
     (IS_MPEG_VIDEO_SECTOR(pSector) ||            \
      IS_MPEG_AUDIO_SECTOR(pSector))
#define IS_AUTOPAUSE(pSector)                     \
      (0 != ((pSector)->SubHeader[2] & 0x10))

// multimedia\dshow\filters\mpeg1\mpegapi\mpegmini.h
#define MPEG_REQUEST_BLOCK_SIZE sizeof(MPEG_REQUEST_BLOCK)

// multimedia\dshow\filters\sbe\wmsdk\inc\wmsbuffer.h
#define IWMSBufferAllocator_AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)

// multimedia\dshow\filters\sbe\wmsdk\inc\wmsdkidl.h
#define IWMWriterAdvanced3_SetNonBlocking(This)	\
    (This)->lpVtbl -> SetNonBlocking(This)

// multimedia\dshow\filters\tsdvr\wmsdk\inc\mswmdm.h
#define IWMDMDevice2_GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)	\
    (This)->lpVtbl -> GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)
#define IMDSPDevice2_GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)	\
    (This)->lpVtbl -> GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)

// multimedia\dshow\filters\tsdvr\wmsdk\inc\wmsbuffer.h
#define IWMSBufferAllocator_AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)

// multimedia\dshow\filters\tsdvr\wmsdk\inc\wmsdkidl.h
#define IWMWriterAdvanced3_SetNonBlocking(This)	\
    (This)->lpVtbl -> SetNonBlocking(This)

// multimedia\dshow\mfvideo\tvplayer\msmfcnt\msmfcnt.h
#define IMSMFBar_get_BackgroundImage(This,pVal)	\
    (This)->lpVtbl -> get_BackgroundImage(This,pVal)
#define IMSMFBar_put_BackgroundImage(This,newVal)	\
    (This)->lpVtbl -> put_BackgroundImage(This,newVal)
#define IMSMFBar_SetRoundRectRgn(This,x1,y1,x2,y2,width,height)	\
    (This)->lpVtbl -> SetRoundRectRgn(This,x1,y1,x2,y2,width,height)
#define IMSMFText_get_TextAlignment(This,pVal)	\
    (This)->lpVtbl -> get_TextAlignment(This,pVal)
#define IMSMFText_put_TextAlignment(This,newVal)	\
    (This)->lpVtbl -> put_TextAlignment(This,newVal)

// multimedia\dshow\tools\graphedt\proppage\vmrprop\vmrprop.cpp
#define DibSize(lpbi)           ((lpbi)->biSize + (lpbi)->biSizeImage + \
                                 (int)(lpbi)->biClrUsed * sizeof(RGBQUAD))
#define DibPaletteSize(lpbi)    (DibNumColors(lpbi) * sizeof(RGBQUAD))

// multimedia\dshow\vidctl\atl\atlcom.h
#define BEGIN_PROPERTY_MAP(theClass) \
	typedef _ATL_PROP_NOTIFY_EVENT_CLASS __ATL_PROP_NOTIFY_EVENT_CLASS; \
	typedef theClass _PropMapClass; \
	static ATL_PROPMAP_ENTRY* GetPropertyMap()\
	{\
		static ATL_PROPMAP_ENTRY pPropMap[] = \
		{ \
			{OLESTR("_cx"), 0, &CLSID_NULL, NULL, offsetof(_PropMapClass, m_sizeExtent.cx), sizeof(long), VT_UI4, &IID_NULL}, \
			{OLESTR("_cy"), 0, &CLSID_NULL, NULL, offsetof(_PropMapClass, m_sizeExtent.cy), sizeof(long), VT_UI4, &IID_NULL},
#define PROP_PAGE(clsid) \
		{NULL, NULL, &clsid, &IID_NULL, 0, 0, 0, &IID_NULL},
#define PROP_DATA_ENTRY(szDesc, member, vt) \
		{OLESTR(szDesc), 0, &CLSID_NULL, NULL, offsetof(_PropMapClass, member), sizeof(((_PropMapClass*)0)->member), vt, &IID_NULL},
#define PROP_DATA_QI_ENTRY(szDesc, member, iid) \
		{OLESTR(szDesc), 0, &CLSID_NULL, NULL, offsetof(_PropMapClass, member), sizeof(((_PropMapClass*)0)->member), VT_UNKNOWN, &iid},
#define END_CONNECTION_POINT_MAP() {(DWORD_PTR)-1} }; \
	if (pnEntries) *pnEntries = sizeof(_entries)/sizeof(_ATL_CONNMAP_ENTRY) - 1; \
	return _entries;}

// multimedia\dshow\vidctl\atl\atlconv.h
#define DEVMODEW2A(lpw)\
	((lpw == NULL) ? NULL : ATLDEVMODEW2A((LPDEVMODEA)alloca(sizeof(DEVMODEA)+lpw->dmDriverExtra), lpw))
#define DEVMODEA2W(lpa)\
	((lpa == NULL) ? NULL : ATLDEVMODEA2W((LPDEVMODEW)alloca(sizeof(DEVMODEW)+lpa->dmDriverExtra), lpa))
#define TEXTMETRICW2A(lptmw)\
	((lptmw == NULL) ? NULL : ATLTEXTMETRICW2A((LPTEXTMETRICA)alloca(sizeof(TEXTMETRICA)), lptmw))
#define TEXTMETRICA2W(lptma)\
	((lptma == NULL) ? NULL : ATLTEXTMETRICA2W((LPTEXTMETRICW)alloca(sizeof(TEXTMETRICW)), lptma))

// multimedia\media\avi\avifile.16\avicmprs.cpp
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\avi\avifile\avicmprs.cpp
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\avi\avifile\aviplay\aviball.c
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\avi\avifile\aviplay\aviplay.c
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\avi\avifile\aviview\aviball.c
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\avi\inc.16\commctrl.h
#define TBM_GETPAGESIZE         (WM_USER+22)

// multimedia\media\avi\inc.16\ddeml.h
#define     XTYP_ERROR              (0x0000 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK )
#define     XTYP_ADVREQ             (0x0020 | XCLASS_DATA | XTYPF_NOBLOCK )
#define     XTYP_CONNECT            (0x0060 | XCLASS_BOOL | XTYPF_NOBLOCK)
#define     XTYP_CONNECT_CONFIRM    (0x0070 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_REGISTER           (0x00A0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_DISCONNECT         (0x00C0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_UNREGISTER         (0x00D0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_WILDCONNECT        (0x00E0 | XCLASS_DATA | XTYPF_NOBLOCK)
#define     XTYP_MONITOR            (0x00F0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)

// multimedia\media\avi\inc.16\pif.h
#define TSK_BACKGROUND          0x0002      // PfW386Flags & fBackground  (SAME BIT)

// multimedia\media\avi\inc.16\prsht.h
#define PSM_REMOVEPAGE          (WM_USER + 102)
#define PSM_ADDPAGE             (WM_USER + 103)

// multimedia\media\avi\mciavi.16\avidraw.c
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\avi\mciavi.16\aviplay.c
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\avi\mciavi.16\device.c
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\avi\mciavi32\avidraw.c
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\avi\mciavi32\aviplay.c
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\avi\mciavi32\device.c
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\avi\mciwnd.16\bmpload.c
#define RGB_BACKGROUNDSEL   (RGB(000,000,255))  // blue
#define RGB_BACKGROUND      (RGB(255,000,255))  // magenta

// multimedia\media\avi\mciwnd.16\cutils.c
#define CCS_ALIGN (CCS_TOP|CCS_NOMOVEY|CCS_BOTTOM)

// multimedia\media\avi\mciwnd\bmpload.c
#define RGB_BACKGROUNDSEL   (RGB(000,000,255))  // blue
#define RGB_BACKGROUND      (RGB(255,000,255))  // magenta

// multimedia\media\avi\mciwnd\cutils.c
#define CCS_ALIGN (CCS_TOP|CCS_NOMOVEY|CCS_BOTTOM)

// multimedia\media\avi\msvidc\decmprss.h
#define NEXT_BLOCK_ROW( row, bpr, height ) ((HPRGBTRIPLE)NEXT_BLOCK( row, bpr, height ))

// multimedia\media\avi\msvidc\msvidc.h
#define ALIGNULONG(i)     ((i+3)&(~3))                  /* ULONG aligned ! */

// multimedia\media\deluxe2\main\frame.cpp
#define BACKGROUND_COLOR    RGB(0x7F, 0x7F, 0x7F)
#define BACKGROUND_COLOR_16 RGB(0xC0, 0xC0, 0xC0)
#define BACKGROUND_COLOR_HI RGB(0xFF, 0xFF, 0xFF)

// multimedia\media\deluxecd\main\frame.cpp
#define BACKGROUND_COLOR    RGB(0x7F, 0x7F, 0x7F)
#define BACKGROUND_COLOR_16 RGB(0xC0, 0xC0, 0xC0)
#define BACKGROUND_COLOR_HI RGB(0xFF, 0xFF, 0xFF)

// multimedia\media\dplay\dpwsock\dpspimp.h
#define SIZE_GROUPADD (sizeof(SPMSG_GROUPADD) - sizeof(DPHDR))

// multimedia\media\dplayx\dplay\dplay\classfac.c
#define VALIDEX_DIRECTPLAYCF_PTR( ptr ) \
        ((!IsBadWritePtr( ptr, sizeof( DPLAYCLASSFACTORY ))) && \
        ((ptr->lpVtbl == &directPlayClassFactoryVtbl) || \
		(ptr->lpVtbl == &directPlayLobbyClassFactoryVtbl)))

// multimedia\media\dplayx\dplay\dplay\dplaypr.h
#define VALID_DPLAY_INT( ptr ) \
        ( ptr && !IsBadWritePtr( ptr, sizeof( DPLAYI_DPLAY_INT )) && \
        ((ptr->lpVtbl == &dpCallbacks) || (ptr->lpVtbl == &dpCallbacks2) \
        || (ptr->lpVtbl == &dpCallbacks2A) || (ptr->lpVtbl == &dpCallbacksSP) \
		|| (ptr->lpVtbl == &dpCallbacks3) || (ptr->lpVtbl == &dpCallbacks3A) \
		|| (ptr->lpVtbl == &dpCallbacks4) || (ptr->lpVtbl == &dpCallbacks4A) ) )

// multimedia\media\dplayx\dplobby\dplobby\dplobpr.h
#define VALID_DPLOBBY_INTERFACE( ptr ) \
        (!IsBadWritePtr(ptr, sizeof(DPLOBBYI_INTERFACE)) && \
        ((((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacks) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacksA) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacks2) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacks2A) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacks3) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacks3A) || \
        (((LPDPLOBBYI_INTERFACE)ptr)->lpVtbl == &dplCallbacksSP)))

// multimedia\media\msacm\msacm\msacm.h
#define ACM_STREAMCONVERTF_VALID        (ACM_STREAMCONVERTF_BLOCKALIGN | /* ;Internal */ \
                                         ACM_STREAMCONVERTF_END | /* ;Internal */ \
                                         ACM_STREAMCONVERTF_START) /* ;Internal */

// multimedia\media\msacm\msfilter\codec.c
#define ABOUT_BACKGROUNDCOLOR                   RGB(128,128,128)

// multimedia\media\sndrec32\soundrec\soundrec.h
#define RGB_PANEL           GetSysColor(COLOR_BTNFACE)   // main window background
#define RGB_FGNFTEXT        GetSysColor(COLOR_BTNTEXT) // NoFlickerText foreground
#define RGB_BGNFTEXT        GetSysColor(COLOR_BTNFACE) // NoFlickerText background
#define RGB_FGWAVEDISP      RGB(  0, 255,   0)  // WaveDisplay foreground
#define RGB_BGWAVEDISP      RGB(  0,   0,   0)  // WaveDisplay background

// multimedia\opengl\dlist\dl_opt.c
#define __GL_PAD8(x)    (((x) + 7) & ~7)

// multimedia\opengl\gls\inc\glsutil.h
#define __GLS_PAD_EIGHT(v) (((v) + 7) & ~7)

// multimedia\opengl\glu\libtess\memalloc.c
#define CHUNK_PAD	sizeof(Chunk)
#define CHUNK_SIZE(n)	(((n) + CHUNK_PAD + ALIGN - 1) & (-ALIGN))
#define ALIGNED_CHUNK_PAD	((CHUNK_PAD + ALIGN - 1) & (-ALIGN))

// multimedia\opengl\test\auxprogs\ogpt\mv\ogpt.c
#define	QUAD_ROUND(x) (((x)+0x0f)&(~0x0f))

// multimedia\opengl\test\auxprogs\ogpt\ogpt.c
#define	QUAD_ROUND(x) (((x)+0x0f)&(~0x0f))

// multimedia\published\dxmdev\dshowdev\include\aviriff.h
#define RIFFROUND(cb) ((cb) + ((cb)&1))

// multimedia\published\wmsdk\inc\mswmdm.h
#define IWMDMDevice2_GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)	\
    (This)->lpVtbl -> GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)
#define IMDSPDevice2_GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)	\
    (This)->lpVtbl -> GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)

// multimedia\published\wmsdk\inc\wmsbuffer.h
#define IWMSBufferAllocator_AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)

// net\1394\arp\kdext\util.h
#define FIELD_SIZE(type, field)  sizeof(((type *)0)->field)

// net\1394\arp\sys\priv.h
#define REMOTE_DEST_IP_ADDRESS(_R) ((&(_R)->IpAddress))

// net\1394\nic\sys\priv.h
#define ALLOC_NDIS_WORK_ITEM( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistWorkItems )
#define ALLOC_TIMERQITEM( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistTimerQItems )
#define ALLOC_TUNNELCB( pA ) \
    ALLOC_NONPAGED( sizeof(TUNNELCB), MTAG_TUNNELCB )
#define ALLOC_VCCB( pA ) \
    ALLOC_NONPAGED( sizeof(VCCB), MTAG_VCCB )
#define ALLOC_TIMERQ( pA ) \
    ALLOC_NONPAGED( sizeof(TIMERQ), MTAG_TIMERQ )
#define AF_ACQUIRE_LOCK(_pAF)               NdisAcquireSpinLock (&_pAF->pAdapter->lock);
#define REMOTE_NODE_ACQUIRE_LOCK(_pP)       NdisAcquireSpinLock (&_pP->pAdapter->lock);
#define nicReassemblyStarted(_pAdapter)     \
{                                       \
    NdisInterlockedIncrement( &(_pAdapter->AdaptStats.TempStats.ulNumOutstandingReassemblies)); \
    NdisInterlockedIncrement ( &(_pAdapter->Reassembly.PktsInQueue)); \
    NdisInterlockedIncrement ( &(_pAdapter->OutstandingReassemblies));\
}
#define nicIncrementFifoSendPktCount(_Vc, _Pkt)         NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.Fifo.ulSendNicSucess));
#define nicIncrementFifoSendFailures(_Vc, _Pkt)         NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.Fifo.ulSendNicFail));
#define nicIncrementFifoBusSendFailures(_Vc,_Pkt)               NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.Fifo.ulSendBusFail));
#define nicIncrementFifoBusSendSucess(_Vc,_Pkt)                 NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.Fifo.ulSendBusSuccess));
#define nicIncrementFifoRcvPktCount(_Vc, _Pkt)              NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.Fifo.ulRecv));
#define nicIncrementChannelSendPktCount(_Vc, _Pkt)      NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.Channel.ulSendNicSucess));
#define nicIncrementChannelSendFailures(_Vc, _Pkt)      NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.Channel.ulSendNicFail));
#define nicIncrementChannelBusSendFailures(_Vc,_Pkt)                NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.Channel.ulSendBusFail));
#define nicIncrementChannelBusSendSucess(_Vc, _Pkt)             NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.Channel.ulSendBusSuccess));
#define nicIncrementChannelRcvPktCount(_Vc, _Pkt)           NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.Channel.ulRecv));
#define nicIncrementSendCompletes(_Vc)  NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.ulNumSendsCompleted   )); \
                                NdisInterlockedIncrement(&NicSendCompletes);
#define nicIncrementSends(_Vc)  NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.ulNumSends)); \
                                NdisInterlockedIncrement (&NicSends);
#define nicIncrementBusSends(_Vc)  NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.ulNumBusSends)); \
                                   NdisInterlockedIncrement (&BusSends);
#define nicIncrementBusSendCompletes(_Vc)  NdisInterlockedIncrement(&((_Vc)->Hdr.pAF->pAdapter->AdaptStats.TempStats.ulNumBusSendsCompleted )); \
                                NdisInterlockedIncrement(&BusSendCompletes);
#define nicSetTagInFifoWrapper(_pF, _Tag)           \
{                                                   \
    ((PADDRESS_FIFO_WRAPPER)(_pF))->Tag = _Tag;     \
                                                    \
}

// net\atm\arp\atmarpc\arppkt.h
#define ROUND_OFF(_size)		(((_size) + 3) & ~0x3)
#define SIZEOF_Q2931_IE	 ROUND_OFF(sizeof(Q2931_IE))
#define SIZEOF_AAL_PARAMETERS_IE	ROUND_OFF(sizeof(AAL_PARAMETERS_IE))
#define SIZEOF_ATM_TRAFFIC_DESCR_IE	ROUND_OFF(sizeof(ATM_TRAFFIC_DESCRIPTOR_IE))
#define SIZEOF_ATM_BBC_IE			ROUND_OFF(sizeof(ATM_BROADBAND_BEARER_CAPABILITY_IE))
#define SIZEOF_ATM_BLLI_IE			ROUND_OFF(sizeof(ATM_BLLI_IE))
#define SIZEOF_ATM_QOS_IE			ROUND_OFF(sizeof(ATM_QOS_CLASS_IE))

// net\atm\arp\atmarpc\macros.h
#define ROUND_UP(Val)	(((Val) + 3) & ~0x3)

// net\atm\arp\atmarps\arp.h
#define	IP_ADDR_LEN				sizeof(IPADDR)

// net\atm\arp\atmarps\intf.h
#define	ARP_HASH(_ipaddr)			((((PUCHAR)&(_ipaddr))[3]) & (ARP_TABLE_SIZE - 1))
#define	MARS_HASH(_ipaddr)			((((PUCHAR)&(_ipaddr))[3]) & (MARS_TABLE_SIZE - 1))
#define ROUND_OFF(_size)		(((_size) + 3) & ~0x4)
#define SIZEOF_Q2931_IE	 ROUND_OFF(sizeof(Q2931_IE))
#define SIZEOF_AAL_PARAMETERS_IE	ROUND_OFF(sizeof(AAL_PARAMETERS_IE))
#define SIZEOF_ATM_TRAFFIC_DESCR_IE	ROUND_OFF(sizeof(ATM_TRAFFIC_DESCRIPTOR_IE))
#define SIZEOF_ATM_BBC_IE			ROUND_OFF(sizeof(ATM_BROADBAND_BEARER_CAPABILITY_IE))
#define SIZEOF_ATM_BLLI_IE			ROUND_OFF(sizeof(ATM_BLLI_IE))
#define SIZEOF_ATM_QOS_IE			ROUND_OFF(sizeof(ATM_QOS_CLASS_IE))

// net\atm\arp\atmarps\mars.h
#define ROUND_OFF(_size)		(((_size) + 3) & ~0x4)
#define SIZEOF_Q2931_IE	 ROUND_OFF(sizeof(Q2931_IE))
#define SIZEOF_AAL_PARAMETERS_IE	ROUND_OFF(sizeof(AAL_PARAMETERS_IE))
#define SIZEOF_ATM_TRAFFIC_DESCR_IE	ROUND_OFF(sizeof(ATM_TRAFFIC_DESCRIPTOR_IE))
#define SIZEOF_ATM_BBC_IE			ROUND_OFF(sizeof(ATM_BROADBAND_BEARER_CAPABILITY_IE))
#define SIZEOF_ATM_BLLI_IE			ROUND_OFF(sizeof(ATM_BLLI_IE))
#define SIZEOF_ATM_QOS_IE			ROUND_OFF(sizeof(ATM_QOS_CLASS_IE))

// net\atm\arp\kdext\util.h
#define FIELD_SIZE(type, field)  sizeof(((type *)0)->field)

// net\atm\epvc\sys\macros.h
#define CALL_PARAMETER_SIZE     sizeof(CO_CALL_PARAMETERS) +   \
                                sizeof(CO_CALL_MANAGER_PARAMETERS) + \
                                sizeof(CO_MEDIA_PARAMETERS) + \
                                sizeof(ATM_MEDIA_PARAMETERS)

// net\atm\lane\sys\atmlane.h
#define DEF_PROTOCOL_BUF_SIZE			sizeof(LANE_CONTROL_FRAME)

// net\atm\lane\sys\callmgr.c
#define SIZEOF_Q2931_IE	 			ROUND_OFF(sizeof(Q2931_IE))
#define SIZEOF_AAL_PARAMETERS_IE	ROUND_OFF(sizeof(AAL_PARAMETERS_IE))
#define SIZEOF_ATM_TRAFFIC_DESCR_IE	ROUND_OFF(sizeof(ATM_TRAFFIC_DESCRIPTOR_IE))
#define SIZEOF_ATM_BBC_IE			ROUND_OFF(sizeof(ATM_BROADBAND_BEARER_CAPABILITY_IE))
#define SIZEOF_ATM_BLLI_IE			ROUND_OFF(sizeof(ATM_BLLI_IE))
#define SIZEOF_ATM_QOS_IE			ROUND_OFF(sizeof(ATM_QOS_CLASS_IE))

// net\atm\lane\sys\macros.h
#define ROUND_OFF(_size)		(((_size) + 7) & ~0x7)
#define INIT_ADAPTER_LOCK(pAdapter)		\
				INIT_LOCK(&((pAdapter)->AdapterLock), "adapter")
#define INIT_ADAPTER_LOCK(pAdapter)		\
				INIT_LOCK(&((pAdapter)->AdapterLock))
#define ACQUIRE_ADAPTER_LOCK(pAdapter)		\
				ACQUIRE_LOCK(&((pAdapter)->AdapterLock), "adapter")
#define ACQUIRE_ADAPTER_LOCK(pAdapter)		\
				ACQUIRE_LOCK(&((pAdapter)->AdapterLock))
#define ACQUIRE_ADAPTER_LOCK_DPC(pAdapter)		\
				ACQUIRE_LOCK_DPC(&((pAdapter)->AdapterLock), "adapter")
#define ACQUIRE_ADAPTER_LOCK_DPC(pAdapter)		\
				ACQUIRE_LOCK_DPC(&((pAdapter)->AdapterLock))

// net\atm\rawwan\sys\macros.h
#define RWAN_INIT_ADDRESS_LOCK(pAddrObj)	\
				RWAN_INIT_LOCK(&(pAddrObj)->Lock)
#define RWAN_ACQUIRE_ADDRESS_LOCK(pAddrObj)	\
				RWAN_ACQUIRE_LOCK(&(pAddrObj)->Lock)
#define RWAN_ACQUIRE_ADDRESS_LOCK_DPC(pAddrObj)	\
				RWAN_ACQUIRE_LOCK_DPC(&(pAddrObj)->Lock)
#define ROUND_UP(Val)	(((Val) + 3) & ~0x3)

// net\atm\rawwan\tdi\macros.h
#define ROUND_UP(Val)	(((Val) + 3) & ~0x3)

// net\atm\samples\atmsmpl\driver\atmsmdrv.h
#define ROUND_OFF(_size)        (((_size) + 3) & ~0x4)
#define SIZEOF_Q2931_IE             ROUND_OFF(sizeof(Q2931_IE))
#define SIZEOF_AAL_PARAMETERS_IE    ROUND_OFF(sizeof(AAL_PARAMETERS_IE))
#define SIZEOF_ATM_TRAFFIC_DESCR_IE ROUND_OFF(sizeof(ATM_TRAFFIC_DESCRIPTOR_IE))
#define SIZEOF_ATM_BBC_IE           ROUND_OFF(sizeof(ATM_BROADBAND_BEARER_CAPABILITY_IE))
#define SIZEOF_ATM_BLLI_IE          ROUND_OFF(sizeof(ATM_BLLI_IE))
#define SIZEOF_ATM_QOS_IE           ROUND_OFF(sizeof(ATM_QOS_CLASS_IE))

// net\config\inc\stldeque.h
#define _DEQUESIZ (4096 < sizeof (_Ty) ? 1 : 4096 / sizeof (_Ty))

// net\config\netcfg\engine\persist.cpp
#define alignedsizeof(x) ALIGNUP(sizeof(x))

// net\dhcp\client\inc\vxdprocs.h
#define InitIPAddress( ptaip, port, addr )                            \
{                                                                     \
    (ptaip)->TAAddressCount           = 1 ;                           \
    (ptaip)->Address[0].AddressLength = sizeof( TDI_ADDRESS_IP );     \
    (ptaip)->Address[0].AddressType   = TDI_ADDRESS_TYPE_IP ;         \
    (ptaip)->Address[0].Address[0].sin_port = (port) ;                \
    (ptaip)->Address[0].Address[0].in_addr  =  (addr) ;               \
    memset((ptaip)->Address[0].Address[0].sin_zero, 8, 0) ;           \
}
#define InitIPTDIConnectInfo( pConnInfo, ptaip, port, addr )          \
{                                                                     \
    InitIPAddress( ((PTA_IP_ADDRESS)ptaip), (port), (addr) ) ;        \
    (pConnInfo)->RemoteAddressLength = sizeof( TA_IP_ADDRESS ) ;      \
    (pConnInfo)->RemoteAddress       = (ptaip) ;                      \
}

// net\dhcp\client\nt\dhcploc.h
#define DHCP_CLASS_SIZE                 sizeof(DHCP_CLASS)

// net\dhcp\dhcpmib\dhcpmib.h
#define OID_SIZEOF( Oid )      ( sizeof Oid / sizeof(UINT) )

// net\dhcp\server\binl\binlt.c
#define ClearNcb( PNCB ) {                                          \
    ZeroMemory( PNCB , sizeof (NCB) );                           \
    MoveMemory( (PNCB)->ncb_name,     SPACES, sizeof(SPACES)-1 );\
    MoveMemory( (PNCB)->ncb_callname, SPACES, sizeof(SPACES)-1 );\
    }

// net\dhcp\server\server\callout.c
#define    _GiveAddrPkt(P,Code,Type,A,Time) \
WRAPPER(AddressOffer, ((P)->ReqContext.ReceiveBuffer,\
    (P)->ReqContext.ReceiveMessageSize,\
    (Code),\
    ntohl((P)->ReqContext.EndPointIpAddress),\
    (A),\
    (Type),\
    (Time),\
    (LPVOID)(P),\
    (LPVOID)((P)->CalloutContext))\
)
#define    _DropPkt(P,Drop,Code)   \
WRAPPER(PktDrop, (&((P)->ReqContext.ReceiveBuffer),\
    &((P)->ReqContext.ReceiveMessageSize),\
    (Code),\
    (P)->ReqContext.EndPointIpAddress,\
    (LPVOID)(P),\
    (LPVOID)((P)->CalloutContext))\
)
#define    _NewPkt(P,Dropit)       \
WRAPPER(NewPkt, ( &((P)->ReqContext.ReceiveBuffer),\
    &((P)->ReqContext.ReceiveMessageSize),\
    (P)->ReqContext.EndPointIpAddress,\
    (LPVOID)(P),\
    (LPVOID*)&((P)->CalloutContext),\
     Dropit)\
)
#define    _ProbPkt(P,Code,A)      \
WRAPPER(AddressDel, ((P)->ReqContext.ReceiveBuffer,\
    (P)->ReqContext.ReceiveMessageSize,\
    (Code),\
    (P)->ReqContext.EndPointIpAddress,\
    (A),\
    (LPVOID)(P),\
    (LPVOID)((P)->CalloutContext))\
)

// net\dhcp\server\server\callout.h
#define    _GiveAddrPkt(P,Code,Type,A,Time) \
WRAPPER(AddressOffer, ((P)->ReqContext.ReceiveBuffer,\
    (P)->ReqContext.ReceiveMessageSize,\
    (Code),\
    ntohl((P)->ReqContext.EndPointIpAddress),\
    (A),\
    (Type),\
    (Time),\
    (LPVOID)(P),\
    (LPVOID)((P)->CalloutContext))\
)
#define    _DropPkt(P,Drop,Code)   \
WRAPPER(PktDrop, (&((P)->ReqContext.ReceiveBuffer),\
    &((P)->ReqContext.ReceiveMessageSize),\
    (Code),\
    (P)->ReqContext.EndPointIpAddress,\
    (LPVOID)(P),\
    (LPVOID)((P)->CalloutContext))\
)
#define    _NewPkt(P,Dropit)       \
WRAPPER(NewPkt, ( &((P)->ReqContext.ReceiveBuffer),\
    &((P)->ReqContext.ReceiveMessageSize),\
    (P)->ReqContext.EndPointIpAddress,\
    (LPVOID)(P),\
    (LPVOID*)&((P)->CalloutContext),\
     Dropit)\
)
#define    _ProbPkt(P,Code,A)      \
WRAPPER(AddressDel, ((P)->ReqContext.ReceiveBuffer,\
    (P)->ReqContext.ReceiveMessageSize,\
    (Code),\
    (P)->ReqContext.EndPointIpAddress,\
    (A),\
    (LPVOID)(P),\
    (LPVOID)((P)->CalloutContext))\
)

// net\dhcp\server\server\dhcpreg.h
#define DHCP_CLASS_SIZE                           sizeof(DHCP_CLASS)

// net\dhcp\server\server\dnsdb.c
#define MEM_NODE_SIZE              ROUND_UP_COUNT(sizeof(MEM_NODE),ALIGN_WORST)

// net\dhcp\server\server\iptbl.c
#define TCPPREFIX_LEN sizeof("\\DEVICE\\TCPIP")

// net\dhcp\server\server\ping.c
#define AlignSizeof(X)     ROUND_UP_COUNT(sizeof(X),ALIGN_WORST)

// net\dlc\driver\llcapi.h
#define IS_SNA_DIX_FRAME(p) \
    (((PADAPTER_CONTEXT)(p))->IsSnaDixFrame)
#define LlcGetReceivedLanHeaderLength(pBinding) \
    ((((PBINDING_CONTEXT)(pBinding))->pAdapterContext->NdisMedium == NdisMedium802_3) \
        ? (((PBINDING_CONTEXT)(pBinding))->pAdapterContext->FrameType == LLC_DIRECT_ETHERNET_TYPE) \
            ? 12 \
            : 14 \
        : (((PBINDING_CONTEXT)(pBinding))->pAdapterContext->NdisMedium == NdisMediumFddi) \
            ? 14 \
            : ((PBINDING_CONTEXT)(pBinding))->pAdapterContext->RcvLanHeaderLength)
#define LlcGetReceivedLanHeaderLength(pBinding) \
    ((((PBINDING_CONTEXT)(pBinding))->pAdapterContext->NdisMedium == NdisMedium802_3) \
        ? 14 \
        : (((PBINDING_CONTEXT)(pBinding))->pAdapterContext->NdisMedium == NdisMediumFddi) \
            ? 14 \
            : ((PBINDING_CONTEXT)(pBinding))->pAdapterContext->RcvLanHeaderLength)
#define LlcGetEthernetType(hContext) \
    (((PBINDING_CONTEXT)(hContext))->pAdapterContext->EthernetType)

// net\dlc\driver\llcmac.h
#define SEARCH_LINK( pAdapterContext, LanAddr, pLink )\
{ \
    USHORT      usHash; \
    usHash = \
        LanAddr.aus.Raw[0] ^ LanAddr.aus.Raw[1] ^ \
        LanAddr.aus.Raw[2] ^ LanAddr.aus.Raw[3]; \
    pLink = \
        pAdapterContext->aLinkHash[ \
            ((((PUCHAR)&usHash)[0] ^ ((PUCHAR)&usHash)[1]) % LINK_HASH_SIZE)]; \
    while (pLink != NULL && \
           (pLink->LinkAddr.ul.Low != LanAddr.ul.Low || \
            pLink->LinkAddr.ul.High != LanAddr.ul.High)) \
    { \
        pLink = pLink->pNextNode; \
    } \
}

// net\dlc\driver\llcmem.h
#define ALLOCATE_MEMORY_ADAPTER(n) \
    AllocateMemory(&pAdapterContext->MemoryUsage, (ULONG)(n))
#define ALLOCATE_ZEROMEMORY_ADAPTER(n) \
    AllocateZeroMemory(&pAdapterContext->MemoryUsage, (ULONG)(n))
#define ALLOCATE_STRING_ADAPTER(n) \
    AllocateZeroMemory(&pAdapterContext->StringUsage, (ULONG)(n))

// net\homenet\alg\alg_ftp\buffer.h
#define NH_ALLOCATE_BUFFER() \
    reinterpret_cast<PNH_BUFFER>(NH_ALLOCATE(sizeof(NH_BUFFER)))

// net\homenet\alg\alg_icq\buffer.h
#define NH_ALLOCATE_BUFFER() \
    reinterpret_cast<PNH_BUFFER>(NH_ALLOCATE(sizeof(NH_BUFFER)))

// net\ias\iasjet\dnary\simtable.cpp
#define stack_new(obj, num) new (_alloca(sizeof(obj)*num)) obj[num]

// net\ias\iasjet\dstore\bind.h
#define END_BIND_MAP() \
  }; const DBCOUNTITEM count = sizeof(binding)/sizeof(DBBINDING); \
  static const DBLENGTH rowsize = Bind::getRowSize(count, binding); \
  return Bind::createAccessor(p, dbFlags, count, binding, rowsize); \
}

// net\ias\mmc\atl25\atlsnap.h
#define BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname) \
   HRESULT GetDataClass(IDataObject* pDataObject, CSnapInItem** ppItem, DATA_OBJECT_TYPES* pType) \
   { \
      if (ppItem == NULL) \
         return E_POINTER; \
      if (pType == NULL) \
         return E_POINTER; \
\
      *ppItem = NULL; \
\
      *pType = CCT_UNINITIALIZED; \
\
      STGMEDIUM stgmedium = { TYMED_HGLOBAL, NULL }; \
      FORMATETC formatetc = { CSnapInItem::m_CCF_NODETYPE, \
         NULL, \
         DVASPECT_CONTENT, \
         -1, \
         TYMED_HGLOBAL \
      }; \
\
      stgmedium.hGlobal = GlobalAlloc(0, sizeof(GUID)); \
      if (stgmedium.hGlobal == NULL) \
         return E_OUTOFMEMORY; \
\
      HRESULT hr = pDataObject->GetDataHere(&formatetc, &stgmedium); \
      if (FAILED(hr)) \
      { \
         GlobalFree(stgmedium.hGlobal); \
         return hr; \
      } \
\
      GUID guid; \
      memcpy(&guid, stgmedium.hGlobal, sizeof(GUID)); \
\
      GlobalFree(stgmedium.hGlobal); \
      hr = S_OK;

// net\ias\providers\accounting\account.cpp
#define STACK_ALLOC(type, num) (type*)_alloca(sizeof(type) * (num))

// net\ias\sdo\datastore2\oledb\bind.h
#define END_BIND_MAP() \
  }; const DBCOUNTITEM count = sizeof(binding)/sizeof(DBBINDING); \
  static const DBLENGTH rowsize = Bind::getRowSize(count, binding); \
  return Bind::createAccessor(p, dbFlags, count, binding, rowsize); \
}

// net\ias\services\inc\iastlutl.h
#define IASAttributeVectorOnStack(identifier, request, extra) \
   IAS_VECCAP = 0; \
   if (static_cast<IAttributesRaw*>(request) != NULL) \
      static_cast<IAttributesRaw*>(request)->GetAttributeCount(&IAS_VECCAP); \
   IAS_VECCAP += (extra); \
   IASAttributeVector identifier( \
                          (PATTRIBUTEPOSITION) \
                          _alloca(IAS_VECCAP * sizeof(ATTRIBUTEPOSITION)), \
                          IAS_VECCAP \
                          )

// net\ias\services\inc\iasutil.h
#define IAS_STACK_NEW(type, count) \
   new (_alloca(sizeof(type) * count)) type[count]

// net\inc\ddipmcst.h
#define SIZEOF_MFE(X)       \
    (SIZEOF_BASIC_MFE + ((X) * sizeof(IPMCAST_OIF)))
#define SIZEOF_MFE_STATS(X)       \
    (SIZEOF_BASIC_MFE_STATS + ((X) * sizeof(IPMCAST_OIF_STATS)))

// net\inc\isnipx.h
#define IPX_HEADER_SIZE  ((sizeof(IPX_HEADER) + 3) & ~3)

// net\inc\snmpexts.h
#define MIB_SIZEOF_GB(x)    sizeof(MIB_ID(gb_ ## x))
#define MIB_SIZEOF_SB(x)    sizeof(MIB_ID(sb_ ## x))

// net\irda\inc\irda.h
#define IRDA_MSG_DATA_SIZE_INTERNAL sizeof(IRDA_MSG)+128 // can this be smaller?

// net\irda\irmon\irdisc.c
#define DISCOVERY_BUFFER_SIZE    (sizeof(DEVICELIST) -                           \
                                   sizeof(IRDA_DEVICE_INFO) +                    \
                                   (sizeof(IRDA_DEVICE_INFO) * DEVICE_LIST_LEN))

// net\irda\irsir\settings.h
#define SLOW_IR_BOF_SIZE        sizeof(SLOW_IR_BOF_TYPE)
#define SLOW_IR_EXTRA_BOF_SIZE  sizeof(SLOW_IR_EXTRA_BOF_TYPE)
#define SLOW_IR_EOF_SIZE        sizeof(SLOW_IR_EOF_TYPE)
#define SLOW_IR_FCS_SIZE        sizeof(SLOW_IR_FCS_TYPE)

// net\irda\samples\nscirda\settings.h
#define SLOW_IR_BOF_SIZE		sizeof(SLOW_IR_BOF_TYPE)
#define SLOW_IR_EXTRA_BOF_SIZE		sizeof(SLOW_IR_EXTRA_BOF_TYPE)
#define SLOW_IR_EOF_SIZE		sizeof(SLOW_IR_EOF_TYPE)
#define SLOW_IR_FCS_SIZE		sizeof(SLOW_IR_FCS_TYPE)

// net\irda\sys\irdap.h
#define GET_ADDR_LOCK(pAddr,Handle)    CTEGetLock(&(pAddr)->Lock, Handle)

// net\jet500\jet\dae\inc\dirapi.h
#define BTIInitLeafSplitKey(plfinfo) memset((plfinfo), 0, sizeof(LFINFO));

// net\jet500\jet\dae\inc\fcb.h
#define FCBInit( pfcb )							\
	{											\
	memset( pfcb, '\0', sizeof( FCB ) );		\
	}

// net\jet500\jet\dae\inc\fucb.h
#define	csridAppendItemMax	((cbPage - sizeof(INT))/sizeof(SRID))

// net\jet500\jet\dae\inc\node.h
#define	cbFOPNoSon				( sizeof(TAG) + 1 + 1 )		// 6
#define	cbPageAvailMost	 		( cbPage - sizeof(PGHDR) - sizeof(PGTRLR) )
#define	cbAvailMost				( cbPageAvailMost - cbFOPNoSon - sizeof(SRID) )
#define	cbNodeMost				( cbAvailMost - ( cbFOPOneSon - cbFOPNoSon ) - sizeof(TAG) - sizeof(SRID) )
#define	cbNullKeyData			( cbFOPOneSon - cbFOPNoSon + sizeof(TAG) + 1 + 1 )
#define	cbChunkMost 			( cbNullKeyDataMost - sizeof(LONG) )
#define PbNDBackLink(pb)											\
	( PbNDSonTable(pb) + ( FNDNullSon( *(pb) ) ? 0 :				\
	( ( ( *PbNDSonTable(pb) == 1 ) && FNDInvisibleSons( *(pb) ) ) ?	\
	sizeof(PGNO) + 1 : *PbNDSonTable(pb) + 1 ) ) )
#define PbNDData(pb) \
	( PbNDBackLink(pb) + ( FNDBackLink( *(pb) ) ? sizeof(SRID) : 0 ) )
#define	CitemND(pb, cb) \
	( ( cb - (UINT)( PbNDData(pb) - pb ) ) / sizeof(ITEM) )
#define	CitemNDData(pb, cb, pbData)	\
	( ( cb - (UINT)( (pbData) - pb ) ) / sizeof(ITEM) )
#define FNDSingleItem( pfucb )											\
	( ( (pfucb)->ssib.line.cb -		 									\
	(UINT)( PbNDData( (pfucb)->ssib.line.pb ) - (pfucb)->ssib.line.pb ) )  	\
	/ sizeof(ITEM) == 1	)

// net\jet500\jet\dae\inc\nver.h
#define cbReplaceRCEOverhead    (2 * sizeof(SHORT))

// net\jet500\jet\dae\inc\page.h
#define PMDecVersion( ppage )						\
	{														\
	if ( (ppage)->pghdr.cVersion > 0 )			\
		--(ppage)->pghdr.cVersion;					\
	}
#define pgdiscont( pgno1, pgno2 ) \
	( ( (pgno1) == 0 ) || ( (pgno2) == 0 ) ? 0 \
	: absdiff( (pgno1), (pgno2) ) /  cpgDiscont )
#define IbCbFromPtag( ibP, cbP, ptagP )							\
			{	TAG *_ptagT = ptagP;										\
				(ibP) = _ptagT->ib;										\
				(cbP) = _ptagT->cb;										\
			}
#define PtagFromIbCb( ptagP, ibP, cbP )	  						\
			{	TAG *_ptagT = ptagP;							\
				_ptagT->ib = (SHORT)(ibP);						\
				_ptagT->cb = (SHORT)(cbP);						\
			}

// net\jet500\jet\dae\inc\stapi.h
#define	ErrSTAccessPage( pfucb, pgnoT )			\
	( ErrBFAccessPage( pfucb->ppib, &(pfucb)->ssib.pbf, PnOfDbidPgno( (pfucb)->dbid, pgnoT ) ) )

// net\jet500\jet\dae\src\dir.c
#define ErrDIRINextItem( pfucb )								\
	( pfucb->lineData.cb == sizeof(SRID) ?                      \
		errNDNoItem : ErrNDNextItem( pfucb ) )
#define ErrDIRRefresh( pfucb )                                                                                            \
	( FReadAccessPage( pfucb, PcsrCurrent( pfucb )->pgno ) ?                                \
		ErrDIRIRefresh( pfucb ) : ErrDIRIIRefresh( pfucb ) )

// net\jet500\jet\dae\src\sysdb.c
#define cbsidUsers sizeof(sidUsers)
#define cbsidGuests sizeof(sidGuests)
#define cbsidEngine sizeof(sidEngine)
#define cbsidCreator sizeof(sidCreator)
#define cbsidGuestUser sizeof(sidGuestUser)

// net\jet500\xjet\inc\fcb.h
#define FCBInitFCB( pfcb )	  					\
	{											\
	memset( pfcb, '\0', sizeof(FCB) );			\
	}

// net\jet500\xjet\inc\fucb.h
#define	csridAppendItemMax	((cbPage - sizeof(INT))/sizeof(SRID))

// net\jet500\xjet\inc\node.h
#define	cbFOPNoSon				( sizeof(TAG) + 1 + 1 )		// 6
#define	cbAvailMost				( cbPage - sizeof(PGHDR) - sizeof(PGTRLR) - cbFOPNoSon - 1 )
#define	cbNodeMost				( cbAvailMost - 1 - 1 - sizeof(TAG) - sizeof(SRID) )
#define	cbNullKeyData			( cbFOPOneSon - cbFOPNoSon + sizeof(TAG) + 1 + 1 )
#define	cbChunkMost 			( cbNodeMost - cbNullKeyData - sizeof(LONG) )
#define PbNDBackLink(pb)											\
	( PbNDSonTable(pb) + ( FNDNullSon( *(pb) ) ? 0 :				\
	( ( ( *PbNDSonTable(pb) == 1 ) && FNDInvisibleSons( *(pb) ) ) ?	\
	sizeof(PGNO) + 1 : *PbNDSonTable(pb) + 1 ) ) )
#define PbNDData(pb) \
	( PbNDBackLink(pb) + ( FNDBackLink( *(pb) ) ? sizeof(SRID) : 0 ) )
#define	CitemND(pb, cb) \
	( ( cb - ( PbNDData(pb) - pb ) ) / sizeof(ITEM) )
#define	CitemNDData(pb, cb, pbData)	\
	( ( cb - ( (pbData) - pb ) ) / sizeof(ITEM) )
#define FNDSingleItem( pfucb )											\
	( ( (pfucb)->ssib.line.cb -		 									\
	( PbNDData( (pfucb)->ssib.line.pb ) - (pfucb)->ssib.line.pb ) )  	\
	/ sizeof(ITEM) == 1	)

// net\jet500\xjet\inc\nver.h
#define cbReplaceRCEOverhead    (2 * sizeof(SHORT))

// net\jet500\xjet\inc\page.h
#define pgdiscont( pgno1, pgno2 ) \
	( ( (pgno1) == 0 ) || ( (pgno2) == 0 ) ? 0 \
	: absdiff( (pgno1), (pgno2) ) /  cpgDiscont )
#define IbCbFromPtag( ibP, cbP, ptagP )							\
			{	TAG *_ptagT = ptagP;					 		\
			(ibP) = _ptagT->ib;							 		\
			(cbP) = _ptagT->cb;							 		\
			}
#define PtagFromIbCb( ptagP, ibP, cbP )	  						\
			{	TAG *_ptagT = ptagP;							\
			_ptagT->ib = (SHORT)(ibP);  						\
			_ptagT->cb = (SHORT)(cbP);							\
			}

// net\jet500\xjet\inc\scb.h
#define PrunlinkRUNLINKAlloc()			( (RUNLINK *) LAlloc( 1, sizeof( RUNLINK ) ) )
#define PotnodeOTNODEAlloc()			( (OTNODE *) LAlloc( 1, sizeof( OTNODE ) ) )
#define PrcbRCBAlloc()			( (RCB *) LAlloc( 1, sizeof( RCB ) ) )

// net\jet500\xjet\src\dbutil.c
#define	ccolumndefPageInfoTable	( sizeof ( rgcolumndefPageInfoTable ) / sizeof(JET_COLUMNDEF) )
#define cbOneIndent		(sizeof(szOneIndent))

// net\jet500\xjet\src\dir.c
#define ErrDIRRefresh( pfucb )                                                                                            \
	( FBFReadAccessPage( pfucb, PcsrCurrent( pfucb )->pgno ) ?                                \
		ErrDIRIRefresh( pfucb ) : ErrDIRIIRefresh( pfucb ) )

// net\layer2svc\wlsnp\snppage.h
#define PSM_QUERYSIBLING_ACTIVATED  (WM_USER + 1)

// net\layer2svc\wlsnp\snputils.h
#define DimensionOf(rgx) (sizeof((rgx)) / sizeof(*(rgx)))

// net\mcast\pgm\inc\macroes.h
#define IS_MCAST_ADDRESS(IpAddress) ((((PUCHAR)(&IpAddress))[3]) >= ((UCHAR)0xe0))

// net\mmc\common\ipaddres.h
  #define GETIP_FOURTH(x)            ((x)     & 0xff)

// net\mmc\mprsnap\rraswiz.h
#define IMPLEMENT_NEWRTRWIZ_FINISH_PAGE(classname, saveflag, helpflag)  \
classname::classname() :                             \
   CNewRtrWizFinishPageBase(classname::IDD, saveflag, helpflag) \
{                                                   \
    InitWiz97(TRUE, 0, 0);                          \
}                                                   \
                                                    \
BEGIN_MESSAGE_MAP(classname, CNewRtrWizFinishPageBase)    \
END_MESSAGE_MAP()                                   \

// net\mmc\tfscore\std.h
#define DimensionOf(rgx)	(sizeof((rgx)) / sizeof(*(rgx)))

// net\mmc\wins\ipaddres.h
  #define GETIP_FOURTH(x)            ((x)     & 0xff)

// net\mmc\wins\verify.h
#define NAME_RESPONSE_BUFFER_SIZE sizeof(NameResponse) * 10

// net\ndis\samples\coisdn\bchannel.h
#define IS_VALID_BCHANNEL(pAdapter, pBChannel) \
        (pBChannel && pBChannel->ObjectType == BCHANNEL_OBJECT_TYPE)

// net\ndis\samples\isdnwan\bchannel.h
#define IS_VALID_BCHANNEL(pAdapter, pBChannel) \
        (pBChannel && pBChannel->ObjectType == BCHANNEL_OBJECT_TYPE)

// net\ndis\samples\isdnwan\tspi.c
#define TSPI_OPTIONAL_SIZE      sizeof(ULONG)

// net\ndis\samples\isdnwan\tspidev.c
#   define SIZEOF_DEVCONFIG     0 // sizeof(DEVCONFIG_INFO)

// net\ndis\samples\muxim\mux.h
#define MUX_INIT_ADAPT_RW_LOCK(_pAdapt) \
            NdisInitializeReadWriteLock(&(_pAdapt)->ReadWriteLock)
#define MUX_ACQUIRE_ADAPT_READ_LOCK(_pAdapt, _pLockState)       \
            NdisAcquireReadWriteLock(&(_pAdapt)->ReadWriteLock, \
                                     FALSE,                     \
                                     _pLockState)
#define MUX_ACQUIRE_ADAPT_WRITE_LOCK(_pAdapt, _pLockState)      \
            NdisAcquireReadWriteLock(&(_pAdapt)->ReadWriteLock, \
                                     TRUE,                      \
                                     _pLockState)

// net\ndis\sys\filter.h
#define FilterIndicateReceiveComplete(NdisBindingHandle)                                \
{                                                                                       \
    (((PNDIS_OPEN_BLOCK)(NdisBindingHandle))->ReceiveCompleteHandler)(                  \
        ((PNDIS_OPEN_BLOCK)(NdisBindingHandle))->ProtocolBindingContext);               \
}

// net\ndis\sys\mini.h
#define ALIGN_8_LENGTH(_length) (((ULONG)(_length) + 7) & ~7)
#define ALIGN_8_TYPE(_type) ((sizeof(_type) + 7) & ~7)

// net\netbeui\sys\nbfcnfg.c
#define InsertAdapter(ConfigurationInfo, Subscript, Name)                \
{ \
    PWSTR _S; \
    PWSTR _N = (Name); \
    UINT _L = NbfWstrLength(_N)+sizeof(WCHAR); \
    _S = (PWSTR)ExAllocatePoolWithTag(NonPagedPool, _L, NBF_MEM_TAG_DEVICE_EXPORT); \
    if (_S != NULL) { \
        RtlCopyMemory(_S, _N, _L); \
        RtlInitUnicodeString (&(ConfigurationInfo)->Names[Subscript], _S); \
    } \
}

// net\netbios\lib\tnetbios.c
#define ClearNcb( PNCB ) {                                          \
    RtlZeroMemory( PNCB , sizeof (NCB) );                           \
    RtlMoveMemory( (PNCB)->ncb_name,     SPACES, sizeof(SPACES)-1 );\
    RtlMoveMemory( (PNCB)->ncb_callname, SPACES, sizeof(SPACES)-1 );\
    }

// net\netbios\lib\tnetbl.c
#define ClearNcb( PNCB ) {                                          \
    RtlZeroMemory( PNCB , sizeof (NCB) );                           \
    RtlMoveMemory( (PNCB)->ncb_name,     SPACES, sizeof(SPACES)-1 );\
    RtlMoveMemory( (PNCB)->ncb_callname, SPACES, sizeof(SPACES)-1 );\
    }

// net\netbios\sys\registry.c
#define ROUNDUP_TO_LONG(x) (((x) + sizeof(PVOID) - 1) & ~(sizeof(PVOID) - 1))

// net\netbt\inc\ctemacro.h
#define IS_UNIQUE_ADDR(IpAddress) ((((PUCHAR)(&IpAddress))[3]) < ((UCHAR)0xe0))

// net\netbt\inc\types.h
#define INITIAL_DOM_SIZE sizeof(tIPADDRESS)*6
#define NBT_ALIGN(x,b)  (((x)+(b)-1) & (~((b)-1)))

// net\netbt\inc\vxdprocs.h
#define InitNBAddress( ptanb, pName )                                 \
{                                                                     \
    (ptanb)->TAAddressCount           = 1 ;                           \
    (ptanb)->Address[0].AddressLength = sizeof( TDI_ADDRESS_NETBIOS );\
    (ptanb)->Address[0].AddressType   = TDI_ADDRESS_TYPE_NETBIOS ;    \
    (ptanb)->Address[0].Address[0].NetbiosNameType = 0 ;              \
    CTEMemCopy( (ptanb)->Address[0].Address[0].NetbiosName,           \
                pName,                                                \
                NCBNAMSZ ) ;                                          \
}
#define InitNBTDIConnectInfo( pConnInfo, ptanb, pName )               \
{                                                                     \
    InitNBAddress( ((PTA_NETBIOS_ADDRESS)ptanb), (pName) ) ;          \
    (pConnInfo)->RemoteAddressLength = sizeof( TA_NETBIOS_ADDRESS ) ; \
    (pConnInfo)->RemoteAddress       = (ptanb) ;                      \
}

// net\netbt\nbtstat\nbtstat.h
#define ClearNcb( PNCB ) {                                          \
    RtlZeroMemory( PNCB , sizeof (NCB) );                           \
    RtlMoveMemory( (PNCB)->ncb_name,     SPACES, sizeof(SPACES)-1 );\
    RtlMoveMemory( (PNCB)->ncb_callname, SPACES, sizeof(SPACES)-1 );\
    }

// net\netbt\sys\nt\ntisol.c
#define SESSION_HDR_SIZE   sizeof(tSESSIONHDR)

// net\nwlink\fwd\send.c
#define IsLocalSapNonAgentAdvertisement(hdr,data,ln,ifCB) (		\
	(DontSuppressNonAgentSapAdvertisements==0)					\
	&& (GETUSHORT(hdr+IPXH_DESTSOCK)==IPX_SAP_SOCKET)			\
	&& (GETUSHORT(hdr+IPXH_SRCSOCK)!=IPX_SAP_SOCKET)			\
	&& (ln>=IPXH_HDRSIZE+2)										\
	&& (GETUSHORT(data)==2)										\
	&& ((IPX_NODE_CMP(hdr+IPXH_DESTNODE,BROADCAST_NODE)==0)		\
        || (IPX_NODE_CMP(hdr+IPXH_DESTNODE,ifCB->ICB_RemoteNode)==0)) \
)

// net\nwlink\ipx\loopback.c
#define LOOP_LOOKAHEAD_SIZE   128 + sizeof(IPX_HEADER) + 8 + 34

// net\qos\pclass\gpc\handfact.h
#define NEW_HandleFactory(_h)   GpcAllocMem(&(_h),\
                                            sizeof(HandleFactory),\
                                            HandleFactoryTag)

// net\qos\pclass\gpc\pathash.c
#define NEW_PHTableGroup(group_size, _pg) \
	GpcAllocMem(&_pg,\
                sizeof(PHTableGroup) + \
                ((group_size) - 1) * sizeof(PHTableEntry *),\
                PathHashTag)

// net\qos\pclass\gpc\pathash.h
#define AllocatePatHashTable(_ph)    GpcAllocMem(&_ph, \
                                                 sizeof(PatHashTable), \
                                                 PathHashTag)

// net\qos\pclass\gpc\rhizome.h
#define AllocateRhizome(_r)   GpcAllocMem(&(_r), sizeof(Rhizome), RhizomeTag)

// net\qos\tc\dll\handfact.h
#define NEW_HandleFactory(_h) AllocMem(&(_h), sizeof(HandleFactory))

// net\qos\tc\dll\tctypes.h
#define CompareGUIDs(rguid1, rguid2)  (memcmp(rguid1,rguid2,sizeof(GUID))==0)

// net\rndis\rndismp\rndismp.h
#define RNDISMP_ACQUIRE_ADAPTER_LOCK(_pAdapter) \
    NdisAcquireSpinLock(&(_pAdapter)->Lock);
#define RNDISMP_INCR_STAT(_pAdapter, _StatsCount)               \
    NdisInterlockedIncrement(&(_pAdapter)->Statistics._StatsCount)
#define RNDISMP_GET_ADAPTER_STATS(_pAdapter, _StatsCount)           \
    ((_pAdapter)->Statistics._StatsCount)

// net\rras\cm\ccfgnt\icfgnt4.cpp
#define NSERVICES (sizeof g_netsetup / sizeof g_netsetup[0])

// net\rras\cm\cmdial\icm.h
#define CELEMS(x) ((sizeof(x))/(sizeof(x[0])))
#define NElems(a)  (sizeof a / sizeof a[0])

// net\rras\cm\cmdial\ras.cpp
#define SIZE_ALIGNED_FOR_TYPE(_size, _type) \
    (((_size) + sizeof(_type)-1) & ~(sizeof(_type)-1))

// net\rras\cm\cmutil\mem.cpp
#define TAGSIZE (sizeof(long))// Size of the tags appended to the end of the block

// net\rras\cm\common\inc\cmsetup.h
#define CELEMS(x) ((sizeof(x))/(sizeof(x[0])))

// net\rras\cm\common\source\getpbk.cpp
#define SIZE_ALIGNED_FOR_TYPE(_size, _type) \
    (((_size) + sizeof(_type)-1) & ~(sizeof(_type)-1))

// net\rras\inc\bpool.h
#define ALIGN8_BLOCK_SIZE       (ALIGN_UP(sizeof(BUFFER_BLOCK), ULONGLONG))
#define ALIGN8_HEAD_SIZE    (ALIGN_UP(sizeof(BUFFER_HEAD), ULONGLONG))

// net\rras\inc\igmprm.h
#define IGMP_MIB_IF_CONFIG_SIZE(pConfig) \
                        (sizeof(IGMP_MIB_IF_CONFIG) + \
                        (pConfig)->NumStaticGroups*sizeof(IGMP_STATIC_GROUP))

// net\rras\inc\ipbootp.h
#define IPBOOTP_IF_BINDING_SIZE(bind) \
        (sizeof(IPBOOTP_IF_BINDING) + \
         (bind)->IB_AddrCount * sizeof(IPBOOTP_IP_ADDRESS))

// net\rras\inc\ipriprm.h
#define IPRIP_IF_BINDING_SIZE(bind) \
        (sizeof(IPRIP_IF_BINDING) + \
         (bind)->IB_AddrCount * sizeof(IPRIP_IP_ADDRESS))

// net\rras\inc\rasman.h
#define RASMAN_ALIGN8(_x) ((_x + 7) & (~7))

// net\rras\ip\bootp\api.h
#define IC_SIZEOF(ic)   sizeof(IPBOOTP_IF_CONFIG)

// net\rras\ip\btpagnt\defs.h
#define IsAsnIPAddressTypeNull(asnObj) (!((asnObj)->asnType && (asnObj)->asnValue.address.length))
#define InetCmp(dwIpAddr1,dwIpAddr2,res)                                                    \
    ((LONG)(((res) = (((dwIpAddr1) & 0x000000ff) - ((dwIpAddr2) & 0x000000ff))) ? (res)   : \
            (((res) = (((dwIpAddr1) & 0x0000ff00) - ((dwIpAddr2) & 0x0000ff00))) ? (res)  : \
             (((res) = (((dwIpAddr1) & 0x00ff0000) - ((dwIpAddr2) & 0x00ff0000))) ? (res) : \
              (((dwIpAddr1) & 0xff000000) - ((dwIpAddr2) & 0xff000000))))))

// net\rras\ip\dvmrp\dvmrp.h
#define DVMRP_IF_CONFIG_SIZE(pIfConfig) \
    (sizeof(DVMRP_IF_CONFIG) \
    + (pIfConfig->NumPeerFilters*sizeof(DVMRP_PEER_FILTER)))

// net\rras\ip\fltrdrvr\defs.h
#define SIZEOF_FILTERS(X) (sizeof(FILTER_DRIVER_GET_FILTERS) + SIZEOF_FILTERS1(X))

// net\rras\ip\fltrdrvr\globals.h
#define FILTER_INTERFACE_SIZE (sizeof(FILTER_INTERFACE) - sizeof(LIST_ENTRY) \
               + ((g_dwHashLists + 2) * sizeof(LIST_ENTRY)))
#define PAGED_INTERFACE_SIZE (sizeof(PAGED_FILTER_INTERFACE) - \
       sizeof(LIST_ENTRY) + (2 * (g_dwHashLists * sizeof(LIST_ENTRY))))

// net\rras\ip\igmp\table.h
#define GET_NEXT_STATIC_GROUP_V3(pStaticGroupV3) \
    ((PSTATIC_GROUP_V3) ((PCHAR)pStaticGroupV3+sizeof(IGMP_STATIC_GROUP_V3) \
                            +sizeof(IPADDR)*pStaticGroupV3->NumSources))

// net\rras\ip\igmpagnt\defs.h
#define IsAsnIPAddressTypeNull(asnObj) (!((asnObj)->asnType && (asnObj)->asnValue.address.length))
#define InetCmp(dwIpAddr1,dwIpAddr2,res)                                                    \
    ((LONG)(((res) = (((dwIpAddr1) & 0x000000ff) - ((dwIpAddr2) & 0x000000ff))) ? (res)   : \
            (((res) = (((dwIpAddr1) & 0x0000ff00) - ((dwIpAddr2) & 0x0000ff00))) ? (res)  : \
             (((res) = (((dwIpAddr1) & 0x00ff0000) - ((dwIpAddr2) & 0x00ff0000))) ? (res) : \
              (((dwIpAddr1) & 0xff000000) - ((dwIpAddr2) & 0xff000000))))))

// net\rras\ip\inc\ddipinip.h
#define SIZEOF_TUNNEL_TABLE(X)      \
    SIZEOF_BASIC_TUNNEL_TABLE + ((X) * sizeof(TUNNEL_INFO))

// net\rras\ip\ipinip\ioctl.h
#define AllocateMessage()              \
            RtAllocate(NonPagedPool, sizeof(PENDING_MESSAGE), MESSAGE_TAG)

// net\rras\ip\ipinip\ipinip.h
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))

// net\rras\ip\ipinip\tdix.h
#define AllocateSendContext()               \
            ExAllocateFromNPagedLookasideList(&g_llSendCtxtBlocks)
#define AllocateTransferContext()           \
            ExAllocateFromNPagedLookasideList(&g_llTransferCtxtBlocks)
#define AllocateQueueNode()                     \
            ExAllocateFromNPagedLookasideList(&g_llQueueNodeBlocks)

// net\rras\ip\mcastmib\defs.h
#define IsAsnIPAddressTypeNull(asnObj) (!((asnObj)->asnType && (asnObj)->asnValue.address.length))

// net\rras\ip\nat\icmp.h
#define ALLOCATE_ICMP_BLOCK() \
    ExAllocateFromNPagedLookasideList(&IcmpLookasideList)

// net\rras\ip\nat\mapping.h
#define ALLOCATE_MAPPING_BLOCK() \
    ExAllocateFromNPagedLookasideList(&MappingLookasideList)

// net\rras\ip\nat\nbt.h
#define ALLOCATE_NBT_BLOCK() \
    ExAllocateFromNPagedLookasideList(&NbtLookasideList)

// net\rras\ip\nat\pptp.h
#define ALLOCATE_PPTP_BLOCK() \
    ExAllocateFromNPagedLookasideList(&PptpLookasideList)

// net\rras\ip\nat\raw.h
#define ALLOCATE_IP_BLOCK() \
    ExAllocateFromNPagedLookasideList(&IpLookasideList)

// net\rras\ip\nat\rhizome.h
#define AllocateRhizome(_r)   GpcAllocMem(&(_r), sizeof(Rhizome), NAT_TAG_RHIZOME)

// net\rras\ip\nat\ticket.h
#define ALLOCATE_TICKET_BLOCK() \
    (PNAT_TICKET)ExAllocatePoolWithTag( \
        NonPagedPool,sizeof(NAT_TICKET), NAT_TAG_TICKET \
        )

// net\rras\ip\nath323\h225pp.h
#define SIZE_H225PP_Module_PDU_0 sizeof(RasMessage)
#define SIZE_H225PP_Module_PDU_1 sizeof(H323_UserInformation)

// net\rras\ip\nath323\h245pp.h
#define SIZE_H245PP_Module_PDU_0 sizeof(FastConnectOLC)

// net\rras\ip\nath323\ldap.h
#define SIZE_LDAP_Module_ID_0 sizeof(LDAPMessage)

// net\rras\ip\nathlp\inc\buffer.h
#define NH_ALLOCATE_BUFFER() \
    reinterpret_cast<PNH_BUFFER>(NH_ALLOCATE(sizeof(NH_BUFFER)))

// net\rras\ip\ripagnt\defs.h
#define IsAsnIPAddressTypeNull(asnObj) (!((asnObj)->asnType && (asnObj)->asnValue.address.length))
#define InetCmp(dwIpAddr1,dwIpAddr2,res)                                                    \
    ((LONG)(((res) = (((dwIpAddr1) & 0x000000ff) - ((dwIpAddr2) & 0x000000ff))) ? (res)   : \
            (((res) = (((dwIpAddr1) & 0x0000ff00) - ((dwIpAddr2) & 0x0000ff00))) ? (res)  : \
             (((res) = (((dwIpAddr1) & 0x00ff0000) - ((dwIpAddr2) & 0x00ff0000))) ? (res) : \
              (((dwIpAddr1) & 0xff000000) - ((dwIpAddr2) & 0xff000000))))))

// net\rras\ip\rtrmgr\defs.h
#define IsValidIpAddress(a)                                     \
    ((((ULONG)((a) & 0x000000FF)) <  ((ULONG)0x000000E0)) &&    \
     (((a) & 0x000000FF) != 0))
#define SIZEOF_ROUTEINFO(X)     ((X) * sizeof (MIB_IPFORWARDROW))

// net\rras\ip\sample\ipsamplerm.h
#define IPSAMPLE_IF_BINDING_SIZE(bind)                          \
    (sizeof(IPSAMPLE_IF_BINDING) +                              \
     (bind)->ulCount * sizeof(IPSAMPLE_IP_ADDRESS))

// net\rras\ip\sample\rtmapi.h
#define RTM_SetAddress(prnaAddress,                                 \
                       ipAddress)                                   \
RTM_IPV4_SET_ADDR_AND_LEN(prnaAddress,                              \
                          ipAddress,                                \
                          sizeof(IPADDRESS))

// net\rras\ip\wanarp2\conn.h
#define AllocateConnection()                        \
            ExAllocateFromNPagedLookasideList(&g_llConnBlocks)

// net\rras\ip\wanarp2\ioctl.h
#define AllocateNotification()              \
            ExAllocateFromNPagedLookasideList(&g_llNotificationBlocks)

// net\rras\ip\wanarp2\send.h
#define HEADER_BUFFER_SIZE  sizeof(ETH_HEADER)

// net\rras\ip\wanarp2\wanarp.h
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))

// net\rras\ipx\adptif\ipxdefs.h
#define IPX_NETNUM_CMP(net1,net2) memcmp(net1,net2,sizeof(IPX_NET_NUM))
#define IPX_NODENUM_CPY(dst,src) memcpy(dst,src,sizeof(IPX_NODE_NUM))
#define IPX_NODENUM_CMP(node1,node2) memcmp(node1,node2,sizeof(IPX_NODE_NUM))
#define IPX_SET_BCAST_NODE(node) memset (node,0xFF,sizeof (IPX_NODE_NUM))

// net\rras\ipx\sap\sapdefs.h
#define RoundUpToSec(msecTime) (((msecTime)&0xFFFFFC00)+0x00000400)

// net\rras\ipx\sap\workers.c
#define AllocateWorker(worker,type) 												\
		((worker=(type *)HeapAlloc(WorkerQueue.WQ_Heap, 0,  sizeof (WORK_ITEM)))	\
			? InterlockedIncrement (&WorkerQueue.WQ_WorkerCount)					\
			: 0)

// net\rras\ndis\ndiswan\adapter.h
#define OPENCB_SIZE     sizeof(OPENCB)

// net\rras\ndis\ndiswan\wandefs.h
#define NdisWanChangeMiniportAddress(_a, _addr)                             \
{                                                                           \
    PNDIS_MINIPORT_BLOCK    Miniport;                                       \
                                                                            \
    Miniport = (PNDIS_MINIPORT_BLOCK)((_a)->MiniportHandle);                \
    ETH_COPY_NETWORK_ADDRESS(Miniport->EthDB->AdapterAddress, _addr);       \
}
#define NdisWanAllocateDataBuffer() \
        NdisAllocateFromNPagedLookasideList(&DataBufferList)
#define NdisWanAllocateMemory(_AllocatedMemory, _Size, _t)                                  \
{                                                                                           \
    (PVOID)*(_AllocatedMemory) = (PVOID)ExAllocatePoolWithTag(NonPagedPool, _Size, _t);     \
    if ((PVOID)*(_AllocatedMemory) != NULL) {                                               \
        NdisZeroMemory((PUCHAR)*(_AllocatedMemory), _Size);                                 \
    }                                                                                       \
}
#define NdisWanAllocatePriorityMemory(_AllocatedMemory, _Size, _t, _p)                      \
{                                                                                           \
    (PVOID)*(_AllocatedMemory) = (PVOID)ExAllocatePoolWithTagPriority(NonPagedPool, _Size, _t, _p);\
    if ((PVOID)*(_AllocatedMemory) != NULL) {                                               \
        NdisZeroMemory((PUCHAR)*(_AllocatedMemory), _Size);                                 \
    }                                                                                       \
}

// net\rras\ndis\ndiswan\wantypes.h
#define DATADESC_SIZE   sizeof(DATA_DESC) + sizeof(PVOID)
#define LINKCB_SIZE (sizeof(LINKCB))
#define PROTOCOLCB_SIZE (sizeof(PROTOCOLCB))
#define LINKPROTOCB_SIZE (sizeof(LINKPROTOCB))
#define CLSAP_BUFFERSIZE    (sizeof(CO_SAP) +  \
                             sizeof(DEVICECLASS_NDISWAN_SAP))
#define AFSAPVCCB_SIZE sizeof(AFSAPVCCB)

// net\rras\ndis\ndproxy\pxdefs.h
#define ROUND_UP(_Val)  (((_Val) + 3) & ~3)
#define PxInitBlockStruc(pBlock)    NdisInitializeEvent(&((pBlock)->Event))

// net\rras\ndis\rasl2tp\l2tpp.h
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))
#define ALLOC_NDIS_WORK_ITEM( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistWorkItems )
#define ALLOC_TIMERQITEM( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistTimerQItems )
#define ALLOC_CONTROLSENT( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistControlSents )
#define ALLOC_PAYLOADSENT( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistPayloadSents )
#define ALLOC_TUNNELWORK( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistTunnelWorks )
#define ALLOC_TUNNELCB( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistTunnels )
#define ALLOC_VCCB( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistVcs )
#define ALLOC_TIMERQ( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistTimerQs )
#define ALLOC_CONTROLRECEIVED( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistControlReceiveds )
#define ALLOC_PAYLOADRECEIVED( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistPayloadReceiveds )
#define ALLOC_INCALLSETUP( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistInCallSetups )
#define ALLOC_TUNNELCB( pA ) \
    ALLOC_NONPAGED( sizeof(TUNNELCB), MTAG_TUNNELCB )
#define ALLOC_VCCB( pA ) \
    ALLOC_NONPAGED( sizeof(VCCB), MTAG_VCCB )
#define ALLOC_TIMERQ( pA ) \
    ALLOC_NONPAGED( sizeof(TIMERQ), MTAG_TIMERQ )
#define ALLOC_CONTROLRECEIVED( pA ) \
    ALLOC_NONPAGED( sizeof(CONTROLRECEIVED), MTAG_CTRLRECD )
#define ALLOC_PAYLOADRECEIVED( pA ) \
    ALLOC_NONPAGED( sizeof(PAYLOADRECEIVED), MTAG_PAYLRECD )
#define ALLOC_INCALLSETUP( pA ) \
    ALLOC_NONPAGED( sizeof(INCALLSETUP), MTAG_INCALL )
#define ALLOC_CONTROLMSGINFO( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistControlMsgInfos )

// net\rras\ndis\rasl2tp\tdix.h
#define ALLOC_TDIXRDGINFO( pTdix ) \
    NdisAllocateFromNPagedLookasideList( &(pTdix)->llistRdg )
#define ALLOC_TDIXSDGINFO( pTdix ) \
    NdisAllocateFromNPagedLookasideList( &(pTdix)->llistSdg )
#define ALLOC_TDIXROUTE( pTdix ) \
    ALLOC_NONPAGED( sizeof(TDIXROUTE), MTAG_TDIXROUTE )

// net\rras\ndis\raspppoe\miniport.h
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))

// net\rras\ndis\raspppoe\protocol.h
#define ALLOC_BINDING( ppB )    NdisAllocateMemoryWithTag( ppB, sizeof( BINDING ), MTAG_BINDING )

// net\rras\ndis\raspppoe\tapi.h
#define ALLOC_LINE( ppL ) NdisAllocateMemoryWithTag( (PVOID*) ppL, sizeof( LINE ), MTAG_LINE )
#define ALLOC_CALL( ppC ) NdisAllocateMemoryWithTag( (PVOID*) ppC, sizeof( CALL ), MTAG_CALL )

// net\rras\ndis\raspptp\nt\ctdi.c
#define NUM_STACKS_FOR_CONTEXT(ContextSize) \
    BLOCKS_NEEDED_FOR_SIZE(sizeof(IO_STACK_LOCATION), (ContextSize))

// net\rras\ndis\raspptp\nt\osinc.h
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))

// net\rras\ndis\raspti\ptiwan.h
#define ALLOC_VCCB( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistVcs )
#define ALLOC_NDIS_WORK_ITEM( pA ) \
    NdisAllocateFromNPagedLookasideList( &(pA)->llistWorkItems )

// net\rras\netsh\ip\sample\ipsamplerm.h
#define IPSAMPLE_IF_BINDING_SIZE(bind)                          \
    (sizeof(IPSAMPLE_IF_BINDING) +                              \
     (bind)->ulCount * sizeof(IPSAMPLE_IP_ADDRESS))

// net\rras\ras\autodial\rasadhlp\winsock.c
#define GuidEqual(g1, g2)   RtlEqualMemory((g1), (g2), sizeof (GUID))

// net\rras\ras\inc\pppcp.h
#define PPP_CONFIG_HDR_LEN 	( sizeof( PPP_CONFIG ) - 1 )
#define BAP_RESPONSE_HDR_LEN    ( sizeof( BAP_RESPONSE ) - 1 )
#define PPP_OPTION_HDR_LEN 	( sizeof( PPP_OPTION ) - 1 )

// net\rras\ras\ppp\rasatcp\rasatcp.h
#define ARAP_BIND_SIZE      sizeof(PROTOCOL_CONFIG_INFO)+sizeof(ARAP_BIND_INFO)

// net\rras\ras\ui\common\pbk\file.c
#define SIZE_ALIGNED_FOR_TYPE(_size, _type) \
    (((_size) + sizeof(_type)-1) & ~(sizeof(_type)-1))

// net\rras\ras\ui\inc\common.h
#define ZeroInit(pobj, type)        MyZeroMemory(pobj, sizeof(type))

// net\rras\ras\ui\inc\mem.h
#define GAllocType(type)                (type *)GAlloc(sizeof(type))
#define SharedAllocType(type)           (type *)SharedAlloc(sizeof(type))
#define SharedAllocType(type)           (type *)SharedAlloc(sizeof(type))

// net\rras\ras\ui\perf\dataras.h
#define ALIGN8(_x)   (((_x) + 7) & ~7)

// net\rras\ras\ui\rasdlg\entryw.c
#define c_cWizPages    (sizeof (c_aWizInfo) / sizeof(c_aWizInfo[0]))

// net\rras\ras\ui\rasdlg\ifw.c
#define c_cDdWizPages    (sizeof (c_aDdWizInfo) / sizeof(c_aDdWizInfo[0]))

// net\rras\ras\ui\rasscrpt\rnap.h
#define DEVCONFIGSIZE(diSize)  (diSize+(sizeof(DEVCONFIG)-sizeof(DEVICEINFO)))

// net\rras\rtm\rtmtest.c
#define IPX_NETNUM_CPY(dst,src) memcpy(dst,src,sizeof(IPX_NETNUM))
#define IPX_NETNUM_CMP(addr1,addr2) memcmp(net1,net2,sizeof(IPX_NETNUM))
#define IPX_NODENUM_CPY(dst,src) memcpy(dst,src,sizeof(IPX_NODENUM))
#define IPX_NODENUM_CMP(node1,node2) memcmp(node1,node2,sizeof(IPX_NODENUM))
#define IPX_ADDR_CPY(dst,src) memcpy(dst,src,sizeof(IPX_ADDRESS_BLOCK))
#define IPX_ADDR_CMP(addr1,addr2) memcmp(addr1,addr2,sizeof(IPX_ADDRESS_BLOCK))

// net\rras\rtmv2\pattrie.h
#define NODE_KEY_SIZE        sizeof(ULONG)

// net\rras\rtmv2\rtm1to2.h
#define V1CopyRoute(RouteDst, RouteSrc, ProtocolFamily)                     \
        if (ProtocolFamily == RTM_PROTOCOL_FAMILY_IP)                       \
        {                                                                   \
            CopyMemory(RouteDst, RouteSrc, sizeof(RTM_IP_ROUTE));           \
        }                                                                   \
        else                                                                \
        {                                                                   \
            CopyMemory(RouteDst, RouteSrc, sizeof(RTM_IPX_ROUTE));          \
        }                                                                   \
#define ALLOC_HANDLES(NumHandles)                                           \
        (HANDLE *) _alloca(sizeof(HANDLE) * NumHandles)                     \

// net\rras\rtmv2\rtmconst.h
#define RTM_CONFIG_ROOT_SIZE          sizeof(RTM_CONFIG_ROOT)

// net\sfm\afp\server\afpmem.h
#define	AfpAllocNonPagedMemory(_S)			AfpAllocMemory((_S) | NON_PAGED_MEMORY_TAG)
#define	AfpAllocZeroedNonPagedMemory(_S)	AfpAllocMemory((_S) | NON_PAGED_MEMORY_TAG | ZEROED_MEMORY_TAG)
#define	AfpAllocPANonPagedMemory(_S)		AfpAllocPAMemory((_S) | NON_PAGED_MEMORY_TAG)
#define	AfpAllocPagedMemory(_S)				AfpAllocMemory((_S) | PAGED_MEMORY_TAG)
#define	AfpAllocZeroedPagedMemory(_S)		AfpAllocMemory((_S) | PAGED_MEMORY_TAG | ZEROED_MEMORY_TAG)
#define	AfpAllocPAPagedMemory(_S)			AfpAllocPAMemory((_S) | PAGED_MEMORY_TAG)

// net\sfm\afp\server\desktop.h
#define	ALLOC_ICONINFO(IconLen)	(PICONINFO)AfpAllocPagedMemory((IconLen) + sizeof(ICONINFO))
#define	ALLOC_APPLINFO()		(PAPPLINFO2)AfpAllocPagedMemory(sizeof(APPLINFO2))

// net\sfm\afp\server\fdparm.h
#define	EVENALIGN(n)	(((n) + 1) & ~1)

// net\sfm\afp\server\idindex.h
#define	afpCheckDfEntry(_pVolDesc, _AfpId, _pUName, _IsDir, _pParent, _ppDfEntry)	\
	{																	\
		PDFENTRY	pDfeNew;											\
																		\
		if (((_AfpId) > (_pVolDesc)->vds_LastId)	||					\
			((_AfpId) <= AFP_ID_NETWORK_TRASH)		||					\
			(AfpFindDfEntryById(_pVolDesc, _AfpId, DFE_ANY) != NULL))	\
		{																\
			/* add the item to the DB but assign it a new AFP Id */     \
			_AfpId = 0;												 	\
		}																\
																		\
		pDfeNew = AfpAddDfEntry(_pVolDesc,								\
								_pParent,								\
								_pUName,								\
								_IsDir,								 	\
								_AfpId);								\
																		\
		*(_ppDfEntry) = pDfeNew;										\
	}

// net\sfm\afp\server\iopool.h
#define	LONGLONGSIZEBLOCK(Size)		((Size) + (sizeof(LONGLONG) - (Size)%(sizeof(LONGLONG))))
#define	LOCKS_BUF_SPACE		(POOL_ALLOC_SIZE - sizeof(IOPOOL) -				\
							 POOL_ALLOC_1 - POOL_ALLOC_2 - POOL_ALLOC_3	-	\
							 (NUM_BUFS_IN_POOL * sizeof(IOPOOL_HDR)))
#define	NUM_LOCKS_IN_POOL	((LOCKS_BUF_SPACE)/(sizeof(IOPOOL_HDR) + sizeof(FORKLOCK)))

// net\sfm\afp\server\secutil.h
#define	ALLOC_SWI()	(PSEC_WORK_ITEM)AfpAllocNonPagedMemory(sizeof(SEC_WORK_ITEM))

// net\sfm\afp\service\server\afpsvcp.h
#define AFP_FIELD_SIZE(type, field)    sizeof(((type *)0)->field)

// net\sfm\atalk\sys\adsp.h
#define	AtalkAdspGetDdpAddress(pAdspAddr)								\
		((pAdspAddr)->adspao_pDdpAddr)

// net\sfm\atalk\sys\arap.h
#define ARAP_GET_RIGHTSIZE_RCVBUF(_size, _ppNewBuf)                            \
{                                                                              \
    UCHAR       _BlkId;                                                        \
    PARAPBUF    _pRcvBuf;                                                      \
    USHORT      _BufSize;                                                      \
                                                                               \
    *(_ppNewBuf) = NULL;                                                       \
    _pRcvBuf = NULL;                                                           \
                                                                               \
    if ((_size) <= ARAP_SMPKT_SIZE)                                            \
    {                                                                          \
        _BlkId = BLKID_ARAP_SMPKT;                                             \
        _BufSize = ARAP_SMPKT_SIZE;                                            \
    }                                                                          \
    else if ((_size) <= ARAP_MDPKT_SIZE)                                       \
    {                                                                          \
        _BlkId = BLKID_ARAP_MDPKT;                                             \
        _BufSize = ARAP_MDPKT_SIZE;                                            \
    }                                                                          \
    else if ((_size) <= ARAP_LGPKT_SIZE)                                       \
    {                                                                          \
        _BlkId = BLKID_ARAP_LGPKT;                                             \
        _BufSize = ARAP_LGPKT_SIZE;                                            \
    }                                                                          \
    else if ((_size) <= ARAP_LGBUF_SIZE)                                       \
    {                                                                          \
        _BlkId = BLKID_ARAP_LGBUF;                                             \
        _BufSize = ARAP_LGBUF_SIZE;                                            \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        _BlkId = ARAP_UNLMTD_BUFF_ID;                                          \
        _BufSize = (USHORT)(_size);                                            \
    }                                                                          \
                                                                               \
    if (_BlkId == ARAP_UNLMTD_BUFF_ID)                                         \
    {                                                                          \
        _pRcvBuf = (PARAPBUF)AtalkAllocMemory((_size) + sizeof(ARAPBUF));      \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        _pRcvBuf = (PARAPBUF)AtalkBPAllocBlock(_BlkId);                        \
    }                                                                          \
                                                                               \
    if (_pRcvBuf != NULL)                                                      \
    {                                                                          \
        _pRcvBuf->BlockId = _BlkId;                                            \
        _pRcvBuf->BufferSize = _BufSize;                                       \
	    _pRcvBuf->DataSize = 0;                                                \
	    _pRcvBuf->CurrentBuffer = &(_pRcvBuf->Buffer[0]);                      \
        *(_ppNewBuf) = _pRcvBuf;                                               \
    }                                                                          \
}

// net\sfm\atalk\sys\asp.h
#define	VALID_ASPAO(pAspAddr)	(((pAspAddr) != NULL) && \
								 ((pAspAddr)->aspao_Signature == ASPAO_SIGNATURE))
#define	AtalkAspGetDdpAddress(pAspAddr)	\
							AtalkAtpGetDdpAddress((pAspAddr)->aspao_pSlsAtpAddr)

// net\sfm\atalk\sys\aspc.h
#define	AtalkAspCGetDdpAddress(pAspAddr)	\
							AtalkAtpGetDdpAddress((pAspAddr)->aspcao_pAtpAddr)

// net\sfm\atalk\sys\atkmem.h
#define	AtalkSizeOfBuffDescData(pBuf, pLen)			\
		{			 								\
			PBUFFER_DESC	_B = (pBuf);			\
			USHORT			_L = 0;					\
													\
			while (_B)								\
			{										\
				_L += _B->bd_Length;				\
				_B  = _B->bd_Next;					\
			}										\
			*(pLen) = _L;							\
		}

// net\sfm\atalk\sys\atkutils.h
#define	INVALID_ADDRESS(pAddr)													\
				(((pAddr)->ata_Network > LAST_VALID_NETWORK)	||				\
				(((pAddr)->ata_Node > MAX_USABLE_ATALKNODE)	&&					\
				 ((pAddr)->ata_Node != ATALK_BROADCAST_NODE))	||				\
				((pAddr)->ata_Socket < FIRST_VALID_SOCKET)		||				\
				((pAddr)->ata_Socket > LAST_VALID_SOCKET))
#define	ATALKADDR_TO_TDI(pTdiAddr, pAtalkAddr)									\
	{																			\
		(pTdiAddr)->TAAddressCount = 1;											\
		(pTdiAddr)->Address[0].AddressLength = sizeof(TDI_ADDRESS_APPLETALK);	\
		(pTdiAddr)->Address[0].AddressType = TDI_ADDRESS_TYPE_APPLETALK;		\
		(pTdiAddr)->Address[0].Address[0].Network = (pAtalkAddr)->ata_Network;	\
		(pTdiAddr)->Address[0].Address[0].Node = (pAtalkAddr)->ata_Node;		\
		(pTdiAddr)->Address[0].Address[0].Socket = (pAtalkAddr)->ata_Socket;	\
	}

// net\sfm\atalk\sys\atp.h
#define	VALID_ATPAO(pAtpAddr)	(((pAtpAddr) != NULL) &&						\
								 ((pAtpAddr)->atpao_Signature == ATPAO_SIGNATURE))
#define	ATP_HASH_TID_DESTADDR(_tid, _pAddr, _BucketSize)						\
			(((_pAddr)->ata_Node+((_pAddr)->ata_Network & 0xFF)+_tid)%(_BucketSize))

// net\sfm\atalk\sys\blkpool.h
#define	NUM_BLOCKS(VirginSize, ChunkSize)	\
			((ChunkSize) - BC_OVERHEAD - sizeof(BLK_CHUNK))/BLOCK_SIZE(VirginSize)

// net\sfm\atalk\sys\pap.h
#define	AtalkPapGetDdpAddress(pPapAddr)									\
		AtalkAtpGetDdpAddress((pPapAddr)->papao_pAtpAddr)
#define	PAPCONN_DDPSOCKET(pPapConn)										\
		AtalkAtpGetDdpAddress((pPapConn)->papco_pAtpAddr)->ddpao_Addr.ata_Socket
#define	PAPADDR_DDPSOCKET(pPapAddr)										\
		AtalkAtpGetDdpAddress((pPapAddr)->papao_pAtpAddr)->ddpao_Addr.ata_Socket
#define	PAP_HASH_ID_ADDR(_id, _pAddr)			\
			(((_pAddr)->ata_Node+((_pAddr)->ata_Network & 0xFF)+_id)%PAP_CONN_HASH_SIZE)

// net\sfm\atalk\winsock\wshatalk.h
#define	SOCK_TO_TDI_ATALKADDR(tdiAddr, sockAddr)								\
		{																		\
			(tdiAddr)->TAAddressCount	= 1;										\
			(tdiAddr)->Address[0].AddressLength = sizeof(TDI_ADDRESS_APPLETALK);	\
			(tdiAddr)->Address[0].AddressType = TDI_ADDRESS_TYPE_APPLETALK;		\
			(tdiAddr)->Address[0].Address[0].Network = (sockAddr)->sat_net;			\
			(tdiAddr)->Address[0].Address[0].Node = (sockAddr)->sat_node;			\
			(tdiAddr)->Address[0].Address[0].Socket = (sockAddr)->sat_socket;		\
		}

// net\snmp\manager\mgmtapi\dll\oidconv.c
#define FILENODE_SIZE     sizeof(T_FILE_NODE)
#define OID_PREFIX_LEN    (sizeof MIB_Prefix / sizeof(UINT))
#define FILENODE_SIZE_EX     sizeof(T_FILE_NODE_EX)

// net\snmp\subagent\snmpevnt\evntagnt\snmpelea.h
#define HANDLESIZE      sizeof(HANDLE)

// net\sockets\samples\wshsmple\wshsmple.c
#define MAX_FAST_ADDRESS_BUFFER ( sizeof(IPAddrEntry) * 4 )

// net\sockets\winsock2\ws2_32\inc\trycatch.h
#define TRY_END(block_label) \
    end_##block_label:

// net\sockets\winsock2\ws2_32\src\getxbyy.cpp
#define RNR_BUFFER_SIZE (sizeof(WSAQUERYSET) + 256)

// net\sockets\winsock2\ws2_32\src\qshelpr.cpp
#define ROUND_TO_WCHAR(c)   ( ((c) + 1) & ~1 )

// net\sockets\winsock2\ws2help\inc\ws2ifsl.h
#define ADDR_ALIGN(sz)  (((sz)+1)&(~3))

// net\sockets\winsock2\wsp\afdsys\afdp.h
#define AFD_POOL_OVERHEAD  (sizeof(AFD_POOL_HEADER))

// net\sockets\winsock2\wsp\afdsys\afdprocs.h
#define IS_DGRAM_ENDPOINT(endp) \
            ((endp)->Type==AfdBlockTypeDatagram)
#define IS_VC_ENDPOINT(endp)                            \
        ( ((endp)->Type==AfdBlockTypeEndpoint) ||       \
          ((endp)->Type==AfdBlockTypeVcConnecting) ||   \
          ((endp)->Type==AfdBlockTypeVcListening) ||    \
          ((endp)->Type==AfdBlockTypeVcBoth) )
#define IS_SAN_ENDPOINT(endp)                                   \
        ((endp)->Type==AfdBlockTypeSanEndpoint)
#define IS_SAN_HELPER(endp)                                     \
        ((endp)->Type==AfdBlockTypeSanHelper)
#define AFD_ALLOCATE_REMOTE_ADDRESS(_l)                         \
    (((ULONG)(_l)<=AfdStandardAddressLength)                    \
            ? ExAllocateFromNPagedLookasideList(                \
                            &AfdLookasideLists->RemoteAddrList )\
            : AFD_ALLOCATE_POOL(NonPagedPool,                   \
                            (_l), AFD_REMOTE_ADDRESS_POOL_TAG)  \
        )

// net\sockets\winsock2\wsp\afdsys\afdstr.h
#define IS_AFD_ENDPOINT_TYPE( endpoint )                         \
            ( (endpoint)->Type == AfdBlockTypeEndpoint ||        \
              (endpoint)->Type == AfdBlockTypeDatagram ||        \
              (endpoint)->Type == AfdBlockTypeVcConnecting ||    \
              (endpoint)->Type == AfdBlockTypeVcListening ||     \
              (endpoint)->Type == AfdBlockTypeVcBoth ||          \
              (endpoint)->Type == AfdBlockTypeHelper ||          \
              (endpoint)->Type == AfdBlockTypeSanHelper ||       \
              (endpoint)->Type == AfdBlockTypeSanEndpoint )
#define AFD_CONNECTION_FROM_ENDPOINT( endpoint ) (  \
        (((endpoint)->Type & AfdBlockTypeVcConnecting)==AfdBlockTypeVcConnecting) \
            ? (endpoint)->Common.VirtualCircuit.Connection                        \
            : NULL                                                                \
     )
#define ALIGN_DOWN_A(length,alignment)   \
    (((ULONG)(length)) & ~ ((alignment)-1))
#define ALIGN_UP_A(length,alignment)   \
    ((((ULONG)(length)) + (alignment)-1) & ~ ((alignment)-1))
#define AFD_MAX_NATURAL_ALIGNMENT32  sizeof(ULONG)
#define TDI_CMSGHDR_ALIGN32(length)                         \
            ( ((length) + TYPE_ALIGNMENT(TDI_CMSGHDR32)-1) &\
                (~(TYPE_ALIGNMENT(TDI_CMSGHDR32)-1)) )      \
#define TDI_CMSGDATA_ALIGN32(length)                        \
            ( ((length) + AFD_MAX_NATURAL_ALIGNMENT32-1) &  \
                (~(AFD_MAX_NATURAL_ALIGNMENT32-1)) )

// net\sockets\winsock2\wsp\afdsys\buffer.c
#define AfdInitAlignmentTableRow(_size,_plcmnt)                     \
    AfdAlignmentTable[                                              \
            ((AfdBufferAlignment-(_size&(AfdBufferAlignment-1)))    \
                /AFD_MINIMUM_BUFFER_ALIGNMENT)                      \
                &(AfdAlignmentTableSize-1)] = _plcmnt

// net\tapi\inc\server.h
#define ALIGNED(a)                  (0 == ((a)&TALIGN_COUNT))

// net\tapi\litesabr\filters\amrtpdmx\template.h
#define CFT_AMRTPDMX_DMX_FILTER_PROP \
{ \
	  RTP_DEMUX_FILTER_PROP, \
      &CLSID_IntelRTPDemuxPropertyPage, \
      CRTPDemuxPropertyPage::CreateInstance \
	  }

// net\tapi\litesabr\filters\codecs\g711\template.h
#define CFT_G711_FILTER_PROP \
{ \
	  CODECG711LPROP, \
	  &CLSID_G711CodecPropertyPage, \
	  CG711CodecProperties::CreateInstance \
	  }

// net\tapi\litesabr\filters\inc\rrcmdata.h
#define QOS_BFR_LIST_HEAP_SIZE (sizeof(RTP_QOSNOTIFY)*4)

// net\tapi\litesabr\filters\ppm\core.h
#define IMPLEMENT_CREATEPROC( class_name )                                                                      \
STDMETHODIMP                                                                                                    \
class_name::_CreateObject(                                                                                      \
    const LPUNKNOWN     pUnkOuter,              /* pointer to controlling outer if we're being aggregated */    \
    const DESTROYEDPROC pfnObjectDestroyed,     /* pointer to function to call when object is destroyed */      \
    LPUNKNOWN FAR*      ppUnkInner              /* return pointer to object here */                             \
    )                                                                                                           \
{                                                                                                               \
    SetObjectDestroyed( pfnObjectDestroyed );                                                                   \
                                                                                                                \
    /* check the other parameters; if these tests are made in a release build, */                               \
    /* return E_INVALIDARG on failure. */                                                                       \
    assert( pUnkOuter == NULL || ! ::IsBadReadPtr( pUnkOuter, sizeof(LPUNKNOWN)) );                             \
    assert( ! ::IsBadWritePtr( ppUnkInner, sizeof(LPUNKNOWN) ) );                                               \
    *ppUnkInner = NULL;                                                                                         \
                                                                                                                \
	class_name* pNewObject = NULL;                                                                              \
	                                                                                                            \
    /* create the new object */                                                                                 \
                                                                                                                \
                                                                                                                \
	pNewObject = new class_name( pUnkOuter, ppUnkInner );                                                   \
                                                                                                                \
                                                                                                                \
                                                                                                                \
                                                                                                                \
    /* check the returned pointer */                                                                            \
    if( ! pNewObject )                                                                                          \
        return ResultFromScode( E_OUTOFMEMORY );                                                                \
                                                                                                                \
    /* make sure ppUnkInner is returned. If we're not */                                                        \
    /* aggregated it's ok to use pVideoView */                                                                  \
    if( ! *ppUnkInner )                                                                                         \
    {                                                                                                           \
        if( ! pUnkOuter )                                                                                       \
            return ResultFromScode( E_UNEXPECTED );                                                             \
        else                                                                                                    \
        {                                                                                                       \
            delete pNewObject;                                                                                  \
            return ResultFromScode( CLASS_E_NOAGGREGATION );                                                    \
        }                                                                                                       \
    }                                                                                                           \
                                                                                                                \
    return NOERROR;                                                                                             \
}                                                                                                               \
/* end of IMPLEMENT_CREATEPROC */

// net\tapi\litesabr\filters\ppm\thrdsafe.h
#define SERIALIZEDBLOCKENTRY(CS)	CSerialBlockGuard serialBlockGuard(&(CS))

// net\tapi\litesabr\filters\rph\rphaud\template.h
#define CFT_RPHAUD_FILTER_PROP \
{ \
	  RPH_FOR_AUD_PROP, \
	  &CLSID_INTEL_RPHAUD_PROPPAGE, \
	  CRPHGENPropPage::CreateInstance_aud \
	  }

// net\tapi\litesabr\filters\rph\rphgena\template.h
#define CFT_RPH_GENA_PROP \
{ \
	  RPH_FOR_GENA_PROP, \
	  &CLSID_INTEL_RPHGENA_PROPPAGE, \
	  CRPHGENPropPage::CreateInstance_gena \
	  }
#define CFT_RPH_GENA_PROP_PAGE \
{ \
	  RPH_FOR_GENA_PROP_PAGE, \
	  &CLSID_INTEL_RPHGENA_MEDIATYPE_PROPPAGE, \
	  CRPHGENAPropPage::CreateInstance \
	  }

// net\tapi\litesabr\filters\rph\rphgenv\template.h
#define CFT_RPHGENV_PROP \
{ \
	  RPH_FOR_GENV_PROP, \
	  &CLSID_INTEL_RPHGENV_PROPPAGE, \
	  CRPHGENPropPage::CreateInstance_genv \
	  }
#define CFT_RPHGENV_PROP_PAGE \
{ \
	  RPH_FOR_GENV_PROP_PAGE, \
	  &CLSID_INTEL_RPHGENV_MEDIATYPE_PROPPAGE, \
	  CRPHGENVPropPage::CreateInstance \
	  }

// net\tapi\litesabr\filters\rph\rphh26x\template.h
#define CFT_RPHH26X_COMCONTROL \
{ \
	  RPH_FOR_H26X_COMCONTROL, \
	  &CLSID_INTEL_RPHH26X_PROPPAGE, \
	  CRPHGENPropPage::CreateInstance_h26x \
	  }
#define CFT_RPHH26X_CONTROLS \
{ \
	  RPH_FOR_H26X_CONTROLS, \
	  &CLSID_INTEL_RPHH26X1_PROPPAGE, \
	  CRPHH26XPropPage::CreateInstance \
	  }

// net\tapi\litesabr\filters\sph\sphaud\template.h
#define CFT_SPHAUD_FILTER_PROP \
{ \
	  L"Intel RTP SPH Property Page", \
	  &CLSID_INTEL_SPHAUD_PROPPAGE, \
	  CSPHPropertyPage::CreateInstance_aud \
	  }

// net\tapi\litesabr\filters\sph\sphgena\template.h
#define CFT_SPHGENA_FILTER_PROP \
{ \
	  L"Intel RTP SPH Property Page", \
	  &CLSID_INTEL_SPHGENA_PROPPAGE, \
	  CSPHPropertyPage::CreateInstance_gena \
	  }
#define CFT_SPHGENA_GENERIC_PROP \
{ \
	  L"Intel RTP SPH Generic Audio Property Page", \
	  &CLSID_INTEL_SPHGENA_PIN_PROPPAGE, \
	  CSPHGENAPropertyPage::CreateInstance \
	  }

// net\tapi\litesabr\filters\sph\sphgenv\template.h
#define CFT_SPHGENV_FILTER_PROP \
{ \
	  L"Intel RTP SPH Property Page", \
	  &CLSID_INTEL_SPHGENV_PROPPAGE, \
	  CSPHPropertyPage::CreateInstance_genv \
	  }
#define CFT_SPHGENV_GENERIC_PROP \
{ \
	  L"Intel RTP SPH Generic Video Property Page", \
	  &CLSID_INTEL_SPHGENV_PIN_PROPPAGE, \
	  CSPHGENVPropertyPage::CreateInstance \
	  }

// net\tapi\litesabr\filters\sph\sphh26x\template.h
#define CFT_SPHH26X_FILTER_PROP \
{ \
	  L"Intel RTP SPH Property Page", \
	  &CLSID_INTEL_SPHH26X_PROPPAGE, \
	  CSPHPropertyPage::CreateInstance_h26x \
	  }

// net\tapi\rca\rca.h
#define RCAInitBlockStruc(pBlock)	NdisInitializeEvent(&(pBlock)->Event)

// net\tapi\skywalker\apps\avdialer\avdialer\avdialer.cpp
#define PAGE_BKCOLOR    RGB(255,255,166)

// net\tapi\skywalker\apps\avdialer\avmeter\tmeter.c
#define TMR_ALL (TMR_TRACK | TMR_METER | TMR_LEVEL | TMR_THUMB | TMR_COLORS | TMR_PAGESIZE)

// net\tapi\skywalker\apps\avdialer\confprop\objsec.cpp
#define DECLARE_SCOPE(t,f,b,m,n,d)  \
{ sizeof(DSOP_SCOPE_INIT_INFO), (t), (f), { { (b), (m), (n) }, (d) }, NULL, NULL, S_OK }

// net\tapi\skywalker\cc\callcont\ccmain.h
#define NUM_TERMINAL_ALLOCATION_SLOTS	24		// 24*sizeof(BYTE) = 192 = max. terminal number
#define NUM_CHANNEL_ALLOCATION_SLOTS	32		// 32*sizeof(BYTE) = 256 = max. channel number

// net\tapi\skywalker\cc\inc\core.h
#define IMPLEMENT_CREATEPROC( class_name )                                                                      \
STDMETHODIMP                                                                                                    \
class_name::_CreateObject(                                                                                      \
    const LPUNKNOWN     pUnkOuter,              /* pointer to controlling outer if we're being aggregated */    \
    const DESTROYEDPROC pfnObjectDestroyed,     /* pointer to function to call when object is destroyed */      \
    LPUNKNOWN FAR*      ppUnkInner              /* return pointer to object here */                             \
    )                                                                                                           \
{                                                                                                               \
    SetObjectDestroyed( pfnObjectDestroyed );                                                                   \
                                                                                                                \
    /* check the other parameters; if these tests are made in a release build, */                               \
    /* return E_INVALIDARG on failure. */                                                                       \
    assert( pUnkOuter == NULL || ! ::IsBadReadPtr( pUnkOuter, sizeof(LPUNKNOWN)) );                             \
    assert( ! ::IsBadWritePtr( ppUnkInner, sizeof(LPUNKNOWN) ) );                                               \
    *ppUnkInner = NULL;                                                                                         \
                                                                                                                \
	class_name* pNewObject = NULL;                                                                              \
	                                                                                                            \
    /* create the new object */                                                                                 \
                                                                                                                \
                                                                                                                \
	pNewObject = new class_name( pUnkOuter, ppUnkInner );                                                   \
                                                                                                                \
                                                                                                                \
                                                                                                                \
                                                                                                                \
    /* check the returned pointer */                                                                            \
    if( ! pNewObject )                                                                                          \
        return ResultFromScode( E_OUTOFMEMORY );                                                                \
                                                                                                                \
    /* make sure ppUnkInner is returned. If we're not */                                                        \
    /* aggregated it's ok to use pVideoView */                                                                  \
    if( ! *ppUnkInner )                                                                                         \
    {                                                                                                           \
        if( ! pUnkOuter )                                                                                       \
            return ResultFromScode( E_UNEXPECTED );                                                             \
        else                                                                                                    \
        {                                                                                                       \
            delete pNewObject;                                                                                  \
            return ResultFromScode( CLASS_E_NOAGGREGATION );                                                    \
        }                                                                                                       \
    }                                                                                                           \
                                                                                                                \
    return NOERROR;                                                                                             \
}                                                                                                               \
/* end of IMPLEMENT_CREATEPROC */

// net\tapi\skywalker\cc\q931\q931asn.h
#define SIZE_Q931ASN_Module_PDU_0 sizeof(H323_UserInformation)

// net\tapi\skywalker\filters\rtp\dsrtp\inc\dsglob.h
#define RTPDEFAULT_SAMPLE_PREFIX     sizeof(RtpPrefixHdr_t)

// net\tapi\skywalker\filters\rtp\inc\gtypes.h
#define RTP_ALIGNED_SIZE(_size) \
        (((_size) + sizeof(void *) - 1) & ~(sizeof(void *) - 1))
#define RTP_ALIGNED_SIZEOF(_type) RTP_ALIGNED_SIZE(sizeof(_type))

// net\tapi\skywalker\filters\video\tapivcap\devicew.cpp
#define CLEAR_GetOvResErr   memset(GetOvResErr,0,sizeof(GetOvResErr))

// net\tapi\skywalker\h323\inc\h225asn.h
#define SIZE_H225ASN_Module_PDU_0 sizeof(RasMessage)
#define SIZE_H225ASN_Module_PDU_1 sizeof(H323_UserInformation)

// net\tapi\skywalker\h323\inc\h245asn.h
#define SIZE_H245ASN_Module_PDU_0 sizeof(FastConnectOLC)

// net\tapi\skywalker\h323\inc\h4503pp.h
#define SIZE_H4503PP_Module_PDU_0 sizeof(GroupIndicationOnRes)
#define SIZE_H4503PP_Module_PDU_1 sizeof(GroupIndicationOffRes)
#define SIZE_H4503PP_Module_PDU_2 sizeof(PickupRes)
#define SIZE_H4503PP_Module_PDU_3 sizeof(PickExeRes)
#define SIZE_H4503PP_Module_PDU_4 sizeof(PickrequRes)
#define SIZE_H4503PP_Module_PDU_5 sizeof(DummyArg)
#define SIZE_H4503PP_Module_PDU_6 sizeof(DummyRes)
#define SIZE_H4503PP_Module_PDU_8 sizeof(ActivateDiversionQArgument)
#define SIZE_H4503PP_Module_PDU_9 sizeof(DeactivateDiversionQArgument)
#define SIZE_H4503PP_Module_PDU_10 sizeof(InterrogateDiversionQArgument)
#define SIZE_H4503PP_Module_PDU_12 sizeof(CallReroutingArgument)
#define SIZE_H4503PP_Module_PDU_13 sizeof(DivertingLegInformation1Argument)
#define SIZE_H4503PP_Module_PDU_14 sizeof(DivertingLegInformation2Argument)
#define SIZE_H4503PP_Module_PDU_15 sizeof(DivertingLegInformation3Argument)
#define SIZE_H4503PP_Module_PDU_16 sizeof(DivertingLegInformation4Argument)
#define SIZE_H4503PP_Module_PDU_17 sizeof(CTInitiateArg)
#define SIZE_H4503PP_Module_PDU_18 sizeof(CTSetupArg)
#define SIZE_H4503PP_Module_PDU_19 sizeof(CTIdentifyRes)
#define SIZE_H4503PP_Module_PDU_20 sizeof(CTUpdateArg)
#define SIZE_H4503PP_Module_PDU_21 sizeof(CTCompleteArg)
#define SIZE_H4503PP_Module_PDU_22 sizeof(CTActiveArg)
#define SIZE_H4503PP_Module_PDU_23 sizeof(CpRequestArg)
#define SIZE_H4503PP_Module_PDU_25 sizeof(CpSetupArg)
#define SIZE_H4503PP_Module_PDU_26 sizeof(CpSetupRes)
#define SIZE_H4503PP_Module_PDU_27 sizeof(GroupIndicationOnArg)
#define SIZE_H4503PP_Module_PDU_28 sizeof(GroupIndicationOffArg)
#define SIZE_H4503PP_Module_PDU_29 sizeof(PickrequArg)
#define SIZE_H4503PP_Module_PDU_30 sizeof(PickupArg)
#define SIZE_H4503PP_Module_PDU_31 sizeof(PickExeArg)
#define SIZE_H4503PP_Module_PDU_32 sizeof(CpNotifyArg)
#define SIZE_H4503PP_Module_PDU_33 sizeof(CpickupNotifyArg)
#define SIZE_H4503PP_Module_PDU_34 sizeof(H4501SupplementaryService)
#define SIZE_H4503PP_Module_PDU_35 sizeof(IntResultList)

// net\tapi\skywalker\h323\tsp\line.h
#define H323_LINE_ADDRESSTYPES     (LINEADDRESSTYPE_DOMAINNAME  | \
                                    LINEADDRESSTYPE_IPADDRESS   | \
                                    LINEADDRESSTYPE_PHONENUMBER | \
                                    LINEADDRESSTYPE_EMAILNAME)

// net\tapi\skywalker\h323tsp\line.h
#define H323_LINE_ADDRESSTYPES     (LINEADDRESSTYPE_DOMAINNAME | \
                                    LINEADDRESSTYPE_IPADDRESS  | \
                                    LINEADDRESSTYPE_PHONENUMBER | \
                                    LINEADDRESSTYPE_EMAILNAME)
#define H323IsLineEqualIP(_pLine_,_dwIPAddr_) \
    (H323IsLineInUse(_pLine_) && \
     ((_pLine_)->dwIPAddr == (_dwIPAddr_)))

// net\tapi\thunk\windows.h
#define SIF_ALL             (SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)// ;Internal
#define PSM_PAGEINFO        (WM_USER+100)   /* ;Internal 4.0 */

// net\tcpip\apis\iphlpapi\dll\stack.c
#define REQ_SIZE    sizeof(TCP_REQUEST_SET_INFORMATION_EX) +    \
                    sizeof(MIB_TCPROW) - 1
#define REQ_SIZE    sizeof(TCP_REQUEST_SET_INFORMATION_EX) +    \
                    sizeof(MIB_IPSTATS) - 1
#define REQ_SIZE    sizeof(TCP_REQUEST_SET_INFORMATION_EX) +    \
                    sizeof(MIB_IPNETROW) - 1
#define REQ_SIZE    sizeof(TCP_REQUEST_SET_INFORMATION_EX) +    \
                    sizeof(ProxyArpEntry) - 1
#define REQ_SIZE    sizeof(TCP_REQUEST_SET_INFORMATION_EX) + sizeof(IPRouteEntry) - 1
#define REQ_SIZE    sizeof(TCP_REQUEST_QUERY_INFORMATION_EX) +  \
                    sizeof(IPRouteLookupData) - 1

// net\tcpip\apis\iphlpapi\icmptest\icmptest.c
#define AlignSizeof(X)     ROUND_UP_COUNT(sizeof(X),ALIGN_WORST)

// net\tcpip\apis\iphlpapi\lib\ipconfig.c
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))

// net\tcpip\driver\common\nt\mdlpool.c
#define MDLSIZE sizeof(MDL) + sizeof(PFN_NUMBER)

// net\tcpip\driver\ipsec\sys\globals.h
#define ESP_SIZE (sizeof(ESP) + DES_BLOCKLEN * sizeof(UCHAR))

// net\tcpip\driver\ipsec\sys\macros.h
#define IPSecAllocateSendCompleteCtx(__tag)                 \
    ExAllocateFromNPagedLookasideList(&g_ipsec.IPSecLookasideLists->SendCompleteCtxList)

// net\tcpip\driver\ipv4\arp.c
#define BUFSIZE_ENET_HEADER_POOL sizeof(ENetHeader) + sizeof(ARPHeader)

// net\tcpip\driver\ipv4\igmp.c
#define RECORD_SIZE(numsrc, datalen) (sizeof(IGMPv3GroupRecord) + (numsrc) * sizeof(IPAddr) + (datalen * sizeof(ulong)))
#define IGMPV3_QUERY_SIZE(NumSrc) \
    (sizeof(IGMPv3QueryHeader) + (NumSrc) * sizeof(IPAddr))

// net\tcpip\driver\ipv4\init.c
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v)  ( ap = (va_list)&v + _INTSIZEOF(v) )

// net\tcpip\driver\ipv4\iprtdef.h
#define ADDR_FROM_RTE(R, A) \
    (IP_ADDR_EQUAL((R)->rte_addr, IPADDR_LOCAL) ? (A) : (R)->rte_addr)

// net\tcpip\driver\kdext2\inc\tcpdump.h
#define Print_IPAddr(_p, _f)    \
    PrintFieldName(#_f);        \
    DumpIPAddr(_p->_f);         \
    printx(ENDL)
#define Print_CTEBlockStruc(_p, _f)     \
    PrintFieldName(#_f);                \
    DumpCTEBlockStruc(&_p->_f)

// net\tcpip\driver\tcp\9x\ipr9x.c
#define SMALL_TCP_IPR_BUFFER_SIZE  (sizeof(IPRcvBuf) + sizeof(HANDLE) + 576)
#define MEDIUM_TCP_IPR_BUFFER_SIZE (sizeof(IPRcvBuf) + sizeof(HANDLE) + 1500)

// net\tcpip\driver\tcp\ntautodl.c
#define UC(pIpAddr, i)   ((ULONG)(((PCHAR)(pIpAddr))[i]) & 0xff)

// net\tcpip\services\telnet\client\wintel.h
#define IS_NUMPAD_DIGIT_KEY( KeyEvent ) \
    ( !( KeyEvent.dwControlKeyState & ENHANCED_KEY ) && \
      ( ( KeyEvent.wVirtualKeyCode == VK_INSERT   ) || \
      ( KeyEvent.wVirtualKeyCode == VK_END      ) || \
      ( KeyEvent.wVirtualKeyCode == VK_DOWN     ) || \
      ( KeyEvent.wVirtualKeyCode == VK_NEXT     ) || \
      ( KeyEvent.wVirtualKeyCode == VK_LEFT     ) || \
      ( KeyEvent.wVirtualKeyCode == VK_CLEAR    ) || \
      ( KeyEvent.wVirtualKeyCode == VK_RIGHT    ) || \
      ( KeyEvent.wVirtualKeyCode == VK_HOME     ) || \
      ( KeyEvent.wVirtualKeyCode == VK_UP       ) || \
      ( KeyEvent.wVirtualKeyCode == VK_PRIOR    ) ) )

// net\tcpip\services\telnet\server\tlntsess\iohandlr.h
#define AVAILABE_BUFFER_SIZE( p, c ) ( sizeof( p ) - ( c - p ) )

// net\tcpip\services\telnet\server\tlntsess\scraper.h
#define COMPARE_AND_UPDATE( wRows, wCols, pCurrent,pLastSeen,CSBI,LastCSBI,fDiff)  \
           (m_dwCurrentCodePage == 932 ||m_dwCurrentCodePage == 949 || m_dwCurrentCodePage == 950 || m_dwCurrentCodePage == 936) ? \
           CompareAndUpdateVT80(wRows,wCols,pCurrent,pLastSeen,CSBI,LastCSBI,fDiff) : \
           CompareAndUpdateVT100(wRows,wCols,pCurrent,pLastSeen,CSBI,LastCSBI,fDiff)

// net\tcpip\services\tftp\tftpd.h
#define CHECK_ACK(BUFFER, ACK_TYPE, BLOCK_NUMBER) \
   ((*((unsigned short *) (BUFFER)) == ntohs((short)ACK_TYPE)) \
    && ((((unsigned short *) (BUFFER))[1]) == ntohs((short)(BLOCK_NUMBER))))

// net\tcpip\snmp\defs.h
#define IsAsnIPAddressTypeNull(asnObj) (!((asnObj)->asnType && (asnObj)->asnValue.address.length))

// net\tcpip\tpipv6\6to4svc\proxy.c
#define ADDR_BUFF_LEN (16+sizeof(SOCKADDR_IN6))

// net\tcpip\tpipv6\wship6\wship6.c
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))

// net\tcpip\winsock\wshtcpip.c
#define MAX_FAST_ADDRESS_BUFFER ( sizeof(IPAddrEntry) * 4 )

// net\tdi\sys\tdikd\tdikd.c
#define PROV_SIZE       sizeof(TDI_PROVIDER_RESOURCE) + 32

// net\unimodem\inc\rovcomm.h
#define ZeroInit(pobj)              MyZeroMemory(pobj, sizeof(*(pobj)))

// net\unimodem\src\modemui\modemui.h
#define CB_PROVIDERSIZE             (sizeof(MODEMSETTINGS))

// net\unimodem\src\tsp\asyncipc.h
#define AIPC_MSG_SIZE    sizeof(AIPC_PARAMS)
#define COLOR_AIPC_INIT             (FOREGROUND_RED | FOREGROUND_GREEN)
#define COLOR_AIPC_SUBMIT_COMPLETE  (FOREGROUND_RED | FOREGROUND_GREEN)

// net\unimodem\src\tsp\cdevll.cpp
#define COLOR_MD_ASYNC_NOTIF (FOREGROUND_BLUE | FOREGROUND_GREEN)
    #define COLOR_AIPC_CALL             (BACKGROUND_GREEN | BACKGROUND_RED)

// net\unimodem\src\tsp\cdevtask.cpp
#define COLOR_APC_TASK_COMPLETION (FOREGROUND_RED | FOREGROUND_GREEN)

// net\unimodem\src\tsp\umrtl.cpp
#define CB_PROVIDERSIZE             (sizeof(MODEMSETTINGS))

// net\upnp\host\upnphost\inc\servutil.h
#define ZEROMEM(p)      memset(p, 0, sizeof(*(p)))
#define MyAllocZ(typ)       ((typ*)svsutil_AllocZ(sizeof(typ), g_pvAllocData))
#define MyAllocNZ(typ)      ((typ*)g_funcAlloc(sizeof(typ), g_pvAllocData))
#define MyRgAllocZ(typ, n)  ((typ*)svsutil_AllocZ((n)*sizeof(typ), g_pvAllocData))
#define MyRgAllocNZ(typ, n) ((typ*)g_funcAlloc((n)*sizeof(typ), g_pvAllocData))

// net\winnet\enum.cxx
#define ROUND_DOWN(x)   ((x) & ~(sizeof(WCHAR) - 1))
#define ROUND_UP(x)     (((x) + sizeof(WCHAR) - 1) & ~(sizeof(WCHAR) - 1))

// net\wins\mib\winsmib.c
#define DATAFILE_INFO_SZ        sizeof(DATAFILE_INFO_T)

// net\wins\mib\winsmib.h
#define OID_SIZEOF( Oid )      ( sizeof Oid / sizeof(UINT) )

// net\wins\netsh\common.h
#define NAME_RESPONSE_BUFFER_SIZE sizeof(NameResponse) * 10

// net\wins\server\inc\assoc.h
#define COMMASSOC_DLG_DS_SZ		sizeof(COMMASSOC_DLG_CTX_T)
#define COMMASSOC_ASSOC_DS_SZ		sizeof(COMMASSOC_ASSOC_CTX_T)
#define  COMMASSOC_TBL_HDR_SIZE   (sizeof(RTL_SPLAY_LINKS) + sizeof(LIST_ENTRY))
#define COMMASSOC_START_REQ_ASSOC_MSG_SIZE	(32 + sizeof(COMM_HEADER_T))
#define COMMASSOC_START_RSP_ASSOC_MSG_SIZE      (16 + sizeof(COMM_HEADER_T))
#define COMMASSOC_STOP_REQ_ASSOC_MSG_SIZE	(16 + sizeof(COMM_HEADER_T))

// net\wins\server\inc\comm.h
#define COMM_NETBT_REM_ADD_SIZE		sizeof(tREM_ADDRESS)
#define 	COMM_HEADER_SIZE 	(sizeof(COMM_HEADER_T))
#define 	COMM_N_TCP_HDR_SZ	sizeof(COMM_TCP_HDR_T)
#define COMM_IP_ADD_SIZE		sizeof(COMM_IP_ADD_T)
#define COMM_BUFF_HEADER_SIZE		(sizeof(COMM_BUFF_HEADER_T))
#define  COMM_GET_IPADD_M(pDlgHdl, pIPAdd)	{		  	  \
			PCOMMASSOC_DLG_CTX_T	_pEnt = (pDlgHdl)->pEnt;  \
			*(pIPAdd) = _pEnt->FromAdd.sin_addr.s_addr; 	  \
					}
#define COMM_INIT_ADD_M(pWinsAdd, IPAddress)	{			\
			(pWinsAdd)->AddLen   = sizeof(PCOMM_IP_ADD_T); 	\
			(pWinsAdd)->AddTyp_e  = COMM_ADD_E_TCPUDPIP; 	\
			(pWinsAdd)->Add.IPAdd = (IPAddress);			\
						}
#define COMM_INIT_ADD_FR_DLG_HDL_M(pWinsAdd, pDlgHdl)	{		\
			COMM_IP_ADD_T	IPAdd;				\
			COMM_GET_IPADD_M((pDlgHdl), &IPAdd);		\
			COMM_INIT_ADD_M((pWinsAdd), IPAdd);		\
						}
#define  COMM_NTF_MSG_SZ 	sizeof(COMM_NTF_MSG_T)
#define   COMM_MCAST_MSG_SZ 	 sizeof(COMM_MCAST_MSG_T)

// net\wins\server\inc\rpl.h
#define  RPL_CONFIG_REC_SIZE        (sizeof(RPL_CONFIG_REC_T) + \
                                   (8 - sizeof(RPL_CONFIG_REC_T)%8))

// net\wins\server\inc\rplmsgf.h
#define RPLMSGF_ADDVERSMAP_REQ_SIZE	 (sizeof(LONG) +  COMM_N_TCP_HDR_SZ)
#define RPLMSGF_SNDENTRIES_REQ_SIZE  (COMM_N_TCP_HDR_SZ + sizeof(RPLMSGF_SENDENTRIES_REQ_T))
#define RPLMSGF_ADDVERSMAP_RSP_SIZE_M(_NoOfOwners) \
                       (COMM_N_TCP_HDR_SZ +  \
                       sizeof(RPLMSGF_ADDVERSMAP_RSP_T) + \
                       (sizeof(RPLMSGF_OWNER_MAP_INFO_T) * (_NoOfOwners)));
#define RPLMSGF_UPDVERSNO_REQ_SIZE	 sizeof(RPLMSGF_UPD_VERS_NO_REQ_T)
#define RPLMSGF_UPDVERSNO_RSP_SIZE	 (sizeof(RPLMSGF_UPD_VERS_NO_RSP_T) +  \
					  COMM_N_TCP_HDR_SZ)

// net\wins\server\inc\wins.h
#define WINS_VERS_NO_SIZE		sizeof(LARGE_INTEGER)

// net\wins\server\inc\winscnf.h
#define  WINSCNF_FILE_INFO_SZ         sizeof(WINSCNF_DATAFILE_INFO_T)

// net\wins\server\inc\winsque.h
#define QUE_NBT_WRK_ITM_SZ        sizeof(NBT_REQ_WRK_ITM_T)

// net\wins\server\msc\winsprs.c
#define   DOMAIN_TOKEN_SIZE 	(sizeof(DOMAIN_TOKEN) - 1)
#define   SPEC_GRP_TOKEN_SIZE 	(sizeof(SPEC_GRP_TOKEN) - 1)
#define   MH_TOKEN_SIZE          (sizeof(MH_TOKEN) - 1)

// net\wins\server\rpl\rpl.c
#define LOCAL_RPL_MSG_SZ        (RPL_OPCODE_SIZE + COMM_BUFF_HEADER_SIZE + sizeof(LONG))
#define USER_PORTION_M(pMsg)        (pMsg + COMM_BUFF_HEADER_SIZE + sizeof(LONG))
#define USER_LEN_M(TotalLen)        (TotalLen - COMM_BUFF_HEADER_SIZE - sizeof(LONG))

// net\wlbs\driver\load.h
#define CVY_CONN_MATCH(ep, sa, sp, ca, cp, prot)  ((ep)->used &&                          \
                                                   (ep)->client_ipaddr == (ca) &&         \
                                                   (ep)->client_port == ((USHORT)(cp)) && \
                                                   (ep)->svr_ipaddr == (sa) &&            \
                                                   (ep)->svr_port == ((USHORT)(sp)) &&    \
                                                   (ep)->protocol == ((USHORT)(prot)))
#define CVY_CONN_MATCH(ep, sa, sp, ca, cp, prot)        ((ep)->used &&                          \
                                                   (ep)->client_ipaddr == (ca) &&         \
                                                   (ep)->client_port == ((USHORT)(cp)) && \
                                                   (ep)->svr_ipaddr == (sa) &&            \
                                                   (ep)->svr_port == ((USHORT)(sp)))
#define CVY_CONN_SET(ep, sa, sp, ca, cp, prot) {                                    \
                                                 (ep)->svr_ipaddr = (sa);           \
                                                 (ep)->svr_port = (USHORT)(sp);     \
                                                 (ep)->client_ipaddr = (ca);        \
                                                 (ep)->client_port = (USHORT)(cp);  \
                                                 (ep)->protocol = (USHORT)(prot);   \
                                                 (ep)->used = TRUE;                 \
                                               }
#define CVY_CONN_SET(ep, sa, sp, ca, cp, prot) {                                    \
                                                 (ep)->svr_ipaddr = (sa);           \
                                                 (ep)->svr_port = (USHORT)(sp);     \
                                                 (ep)->client_ipaddr = (ca);        \
                                                 (ep)->client_port = (USHORT)(cp);  \
                                                 (ep)->used = TRUE;                 \
                                               }

// net\wlbs\driver\util.h
#define CVY_MAC_HDR_LEN(m)             ((m) == NdisMedium802_3 ? sizeof (CVY_ETHERNET_HDR) : sizeof (CVY_ETHERNET_HDR))

// net\wlbs\inc\wlbsip.h
#define TCP_GET_DGRAM_LEN(i,t)  (IP_GET_PLEN (i) - ((IP_GET_HLEN (i) + TCP_GET_HLEN (t)) * sizeof (ULONG)))

// printscan\fax\admin\fspext\atlsnap.h
#define BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname) \
	ISnapInDataInterface* GetDataClass(IDataObject* pDataObject) \
	{ \
		STGMEDIUM stgmedium = { TYMED_HGLOBAL, NULL }; \
		FORMATETC formatetc = { ISnapInDataInterface::m_CCF_NODETYPE, \
			NULL, \
			DVASPECT_CONTENT, \
			-1, \
			TYMED_HGLOBAL \
		}; \
\
		stgmedium.hGlobal = GlobalAlloc(0, sizeof(GUID)); \
\
		if (FAILED(pDataObject->GetDataHere(&formatetc, &stgmedium))) \
			return NULL; \
\
		GUID guid; \
		memcpy(&guid, stgmedium.hGlobal, sizeof(GUID)); \
\
		GlobalFree(stgmedium.hGlobal);

// printscan\fax\admin\routeext\atlsnap.h
#define BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname) \
        ISnapInDataInterface* GetDataClass(IDataObject* pDataObject) \
        { \
                STGMEDIUM stgmedium = { TYMED_HGLOBAL, NULL }; \
                FORMATETC formatetc = { ISnapInDataInterface::m_CCF_NODETYPE, \
                        NULL, \
                        DVASPECT_CONTENT, \
                        -1, \
                        TYMED_HGLOBAL \
                }; \
\
                stgmedium.hGlobal = GlobalAlloc(0, sizeof(GUID)); \
\
                if (FAILED(pDataObject->GetDataHere(&formatetc, &stgmedium))) \
                        return NULL; \
\
                GUID guid; \
                memcpy(&guid, stgmedium.hGlobal, sizeof(GUID)); \
\
                GlobalFree(stgmedium.hGlobal);

// printscan\fax\config\dll\faxcpl.c
#define MAX_CLIENT_PAGES (sizeof(ClientConfigPageInfo) / sizeof(FAXCFG_PAGEINFO))
#define MAX_SERVER_PAGES (sizeof(ServerConfigPageInfo) / sizeof(FAXCFG_PAGEINFO))
#define MAX_WORKSTATION_PAGES (sizeof(WorkstationConfigPageInfo) / sizeof(FAXCFG_PAGEINFO))

// printscan\fax\exchange\ab\abcont.h
#define CBABC	sizeof(ABCNT)
#define CBABCBUTT	sizeof(ABCBUTT)

// printscan\fax\exchange\ab\abctbl.h
#define CBABCBK sizeof(ABCBK)
#define CBIVTABC sizeof(IVTABC)

// printscan\fax\exchange\ab\abeid.h
#define CBABCREC  sizeof(ABCREC)
#define CBONEOFFREC  sizeof(ONEOFFREC)

// printscan\fax\exchange\ab\abp.h
#define CBOBJECTLIST sizeof(OBJECTLIST)
#define CBABP sizeof(ABP)

// printscan\fax\exchange\ab\abuser.h
#define CBABUSER	sizeof(ABUSER)
#define CBABUBUTT	sizeof(ABUBUTT)

// printscan\fax\exchange\ab\ootid.h
#define CBOOTID sizeof(OOTID)

// printscan\fax\exchange\ab\oouser.h
#define CBABOOUSER	sizeof(ABOOUSER)

// printscan\fax\exchange\ab\root.h
#define CBROOT	sizeof(ROOT)

// printscan\fax\exchange\ab\tblwrap.h
#define CBIVTWRAP sizeof(IVTWRAP)

// printscan\fax\exchange\ab\tid.h
#define CBTID sizeof(TID)

// printscan\fax\exchange\ab\wrap.h
#define CBWRAP sizeof(WRAP)

// printscan\fax\print\faxprint\faxdrv\faxdrv.h
#define GetForegroundRop3(rop4) ((rop4) & 0xFF)

// printscan\fax\print\faxprint\faxui\wizard.c
#define Align(p, x)  (((x) & ((p)-1)) ? (((x) & ~((p)-1)) + p) : (x))

// printscan\fax\print\faxprint\inc\devmode.h
#define CurrentVersionDevmode(pDevmode) \
        ((pDevmode) != NULL && \
         (pDevmode)->dmSpecVersion == DM_SPECVERSION && \
         (pDevmode)->dmDriverVersion == DRIVER_VERSION && \
         (pDevmode)->dmSize == sizeof(DEVMODE) && \
         (pDevmode)->dmDriverExtra == sizeof(DMPRIVATE))

// printscan\fax\print\faxprint\lib\devmode.c
#define DM_SIZE320  sizeof(DEVMODE320)
#define DM_SIZE400  (DM_SIZE320 + sizeof(DMEXTRA400))
#define DM_SIZE401  (DM_SIZE400 + sizeof(DMEXTRA401))
#define DM_SIZE_CURRENT sizeof(DEVMODEW)
#define DM_SIZE_CURRENT sizeof(DEVMODEA)

// printscan\fax\print\faxprint\sendnote\sendnote.c
#define Align(p, x)  (((x) & ((p)-1)) ? (((x) & ~((p)-1)) + p) : (x))

// printscan\fax\provider\t30\comm\filter.c
#define NCsize          (sizeof("NO CARRIER")-1)
#define OKsize          (sizeof(cbszOK_CRLF)-1)

// printscan\fax\provider\t30\headers\awnsfint.h
#define BC_SIZE sizeof(BC)
#define InitBC(lpbc, uSize, t)                                                          \
{                                                                                                                       \
        _fmemset((lpbc), 0, (uSize));                                                   \
        (lpbc)->bctype  = (t);                                                                  \
        (lpbc)->wBCSize = sizeof(BC);                                                   \
        (lpbc)->wBCVer  = VER_AWFXPROT100;                                              \
        (lpbc)->wBCSig  = VER_AWFXPROT100;                                              \
        (lpbc)->wTotalSize = sizeof(BC);                                                \
}
#define OFF_CHK(lpbc, off)      BG_CHK((lpbc)->off >= sizeof(BC) && (lpbc)->off <= (lpbc)->wTotalSize)

// printscan\fax\provider\t30\headers\buffers.h
#define ISPAGEDATT(e) (((e)==MMR_DATA) || ((e)==MR_DATA) || \
                        ((e)==MH_DATA)|| ((e)==LRAW_DATA)|| ((e)==HRAW_DATA))

// printscan\fax\provider\t30\headers\mem.h
#define CBPROPMEM  sizeof(PROPMEM)

// printscan\fax\provider\t30\main\protocol.h
#define fsLim(pTG, npfs)                     (((npfs)->b) + sizeof((npfs)->b))
#define fsSize(pTG, npfs)            (sizeof((npfs)->b))
#define ZeroRFS(pTG, lp)     _fmemset(lp, 0, sizeof(RFS))

// printscan\fax\provider\t30\main\t30util.c
#define CALLPARAMS_SIZE (sizeof(LINECALLPARAMS)+512)

// printscan\fax\samples\broadcast\adoint.h
#define _Recordset_get_AbsolutePage(This,pl)	\
    (This)->lpVtbl -> get_AbsolutePage(This,pl)
#define _Recordset_put_AbsolutePage(This,Page)	\
    (This)->lpVtbl -> put_AbsolutePage(This,Page)
#define _Recordset_get_PageCount(This,pl)	\
    (This)->lpVtbl -> get_PageCount(This,pl)
#define _Recordset_get_PageSize(This,pl)	\
    (This)->lpVtbl -> get_PageSize(This,pl)
#define _Recordset_put_PageSize(This,PageSize)	\
    (This)->lpVtbl -> put_PageSize(This,PageSize)

// printscan\fax\setup\win9xupg\inc\buffers.h
#define ISPAGEDATT(e) (((e)==MMR_DATA) || ((e)==MR_DATA) || \
                        ((e)==MH_DATA)|| ((e)==LRAW_DATA)|| ((e)==HRAW_DATA))

// printscan\fax\setup\win9xupg\inc\viewerob.h
#define TEXT_FOREGROUND		RGB( 255,255,255 )
#define TEXT_BACKGROUND		RGB( 128,128,128 )

// printscan\fax\tiff\src\tifflibp.h
#define Align(p, x)  (((x) & ((p)-1)) ? (((x) & ~((p)-1)) + p) : (x))

// printscan\fax\tiff\test\test.h
#define Align(p, x)  (((x) & ((p)-1)) ? (((x) & ~((p)-1)) + p) : (x))

// printscan\faxsrv\src\admin\cfgwzrd\faxcfgwz.c
#define NUM_PAGES (sizeof(g_FaxWizardPage)/sizeof(WIZARDPAGEINFO))

// printscan\faxsrv\src\admin\inc\atlsnap.h
#define BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname) \
	HRESULT GetDataClass(IDataObject* pDataObject, CSnapInItem** ppItem, DATA_OBJECT_TYPES* pType) \
	{ \
		if (ppItem == NULL) \
			return E_POINTER; \
		if (pType == NULL) \
			return E_POINTER; \
\
		*ppItem = NULL; \
\
		*pType = CCT_UNINITIALIZED; \
\
		STGMEDIUM stgmedium = { TYMED_HGLOBAL, NULL }; \
		FORMATETC formatetc = { CSnapInItem::m_CCF_NODETYPE, \
			NULL, \
			DVASPECT_CONTENT, \
			-1, \
			TYMED_HGLOBAL \
		}; \
\
		stgmedium.hGlobal = GlobalAlloc(0, sizeof(GUID)); \
		if (stgmedium.hGlobal == NULL) \
			return E_OUTOFMEMORY; \
\
		HRESULT hr = pDataObject->GetDataHere(&formatetc, &stgmedium); \
		if (FAILED(hr)) \
		{ \
			GlobalFree(stgmedium.hGlobal); \
			return hr; \
		} \
\
		GUID guid; \
		memcpy(&guid, stgmedium.hGlobal, sizeof(GUID)); \
\
		GlobalFree(stgmedium.hGlobal); \
		hr = S_OK;

// printscan\faxsrv\src\faxbvt\tiff\tifftools\test.h
#define Align(p, x)  (((x) & ((p)-1)) ? (((x) & ~((p)-1)) + p) : (x))

// printscan\faxsrv\src\faxbvt\tiff\tifftools\tiffcomp.h
#define Align(p, x)  (((x) & ((p)-1)) ? (((x) & ~((p)-1)) + p) : (x))

// printscan\faxsrv\src\faxbvt\tiff\tifftools\tifftools.h
#define Align(p, x)  (((x) & ((p)-1)) ? (((x) & ~((p)-1)) + p) : (x))

// printscan\faxsrv\src\print\faxprint\faxdrv\faxdrv.h
#define GetForegroundRop3(rop4) ((rop4) & 0xFF)

// printscan\faxsrv\src\print\faxprint\inc\devmode.h
#define CurrentVersionDevmode(pDevmode) \
        ((pDevmode) != NULL && \
         (pDevmode)->dmSpecVersion == DM_SPECVERSION && \
         (pDevmode)->dmDriverVersion == DRIVER_VERSION && \
         (pDevmode)->dmSize == sizeof(DEVMODE) && \
         (pDevmode)->dmDriverExtra == sizeof(DMPRIVATE))

// printscan\faxsrv\src\print\faxprint\lib\devmode.c
#define DM_SIZE320  sizeof(DEVMODE320)
#define DM_SIZE400  (DM_SIZE320 + sizeof(DMEXTRA400))
#define DM_SIZE401  (DM_SIZE400 + sizeof(DMEXTRA401))
#define DM_SIZE_CURRENT sizeof(DEVMODEW)
#define DM_SIZE_CURRENT sizeof(DEVMODEA)

// printscan\faxsrv\src\provider\t30\comm\filter.c
#define NCsize          (sizeof("NO CARRIER")-1)
#define OKsize          (sizeof(cbszOK_CRLF)-1)

// printscan\faxsrv\src\provider\t30\headers\awnsfint.h
#define BC_SIZE sizeof(BC)
#define InitBC(lpbc, uSize, t)                                                          \
{                                                                                                                       \
        _fmemset((lpbc), 0, (uSize));                                                   \
        (lpbc)->bctype  = (t);                                                                  \
        (lpbc)->wBCSize = sizeof(BC);                                                   \
        (lpbc)->wBCVer  = VER_AWFXPROT100;                                              \
        (lpbc)->wBCSig  = VER_AWFXPROT100;                                              \
        (lpbc)->wTotalSize = sizeof(BC);                                                \
}
#define OFF_CHK(lpbc, off)      BG_CHK((lpbc)->off >= sizeof(BC) && (lpbc)->off <= (lpbc)->wTotalSize)

// printscan\faxsrv\src\provider\t30\headers\buffers.h
#define ISPAGEDATT(e) (((e)==MMR_DATA) || ((e)==MR_DATA) || \
                        ((e)==MH_DATA)|| ((e)==LRAW_DATA)|| ((e)==HRAW_DATA))

// printscan\faxsrv\src\provider\t30\main\protocol.h
#define fsLim(pTG, npfs)                     (((npfs)->b) + sizeof((npfs)->b))
#define fsSize(pTG, npfs)            (sizeof((npfs)->b))
#define ZeroRFS(pTG, lp)     _fmemset(lp, 0, sizeof(RFS))

// printscan\faxsrv\src\provider\t30\main\t30util.c
#define CALLPARAMS_SIZE (sizeof(LINECALLPARAMS)+512)

// printscan\faxsrv\src\sdktools\msvc15\include\ddeml.h
#define     XTYP_ERROR              (0x0000 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK )
#define     XTYP_ADVREQ             (0x0020 | XCLASS_DATA | XTYPF_NOBLOCK )
#define     XTYP_CONNECT            (0x0060 | XCLASS_BOOL | XTYPF_NOBLOCK)
#define     XTYP_CONNECT_CONFIRM    (0x0070 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_REGISTER           (0x00A0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_DISCONNECT         (0x00C0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_UNREGISTER         (0x00D0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_WILDCONNECT        (0x00E0 | XCLASS_DATA | XTYPF_NOBLOCK)
#define     XTYP_MONITOR            (0x00F0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)

// printscan\faxsrv\src\sdktools\msvc15\include\stdarg.h
#define _INTSIZEOF(n)    ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v) ap = (va_list)&v + _INTSIZEOF(v)

// printscan\faxsrv\src\sdktools\msvc15\include\stdio.h
#define  L_tmpnam sizeof(_P_tmpdir)+8

// printscan\faxsrv\src\sdktools\msvc15\include\varargs.h
#define _INTSIZEOF(n)    ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

// printscan\faxsrv\src\sdktools\msvc15\mfc\include\afx.h
#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew) \
	static char BASED_CODE _lpsz##class_name[] = #class_name; \
	CRuntimeClass AFXAPP_DATA class_name::class##class_name = { \
		_lpsz##class_name, sizeof(class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL }; \
	static AFX_CLASSINIT _init_##class_name(&class_name::class##class_name); \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return &class_name::class##class_name; } \
// end of _IMPLEMENT_RUNTIMECLASS
#define AFX_ZERO_INIT_OBJECT(base_class) \
	memset(((base_class*)this)+1, 0, sizeof(*this) - sizeof(base_class));

// printscan\faxsrv\src\setup\win9xupg\inc\buffers.h
#define ISPAGEDATT(e) (((e)==MMR_DATA) || ((e)==MR_DATA) || \
                        ((e)==MH_DATA)|| ((e)==LRAW_DATA)|| ((e)==HRAW_DATA))

// printscan\faxsrv\src\setup\win9xupg\inc\viewerob.h
#define TEXT_FOREGROUND		RGB( 255,255,255 )
#define TEXT_BACKGROUND		RGB( 128,128,128 )

// printscan\faxsrv\src\test\src\tapitools\querymodemcaps\main.h
#define REG_FAX_ADAPTIVE_SIZE	sizeof(REG_FAX_ADAPTIVE)

// printscan\faxsrv\src\test\src\util\fax\tiffutils\bmp2tiff.c
#define Align(p, x)  (((x) & ((p)-1)) ? (((x) & ~((p)-1)) + p) : (x))

// printscan\faxsrv\src\tiff\src\tifflibp.h
#define Align(p, x)  (((x) & ((p)-1)) ? (((x) & ~((p)-1)) + p) : (x))

// printscan\print\drivers\usermode\ddk\samples\oemdll\nt4\inc\minidrv.h
#define IS_DBCSCODEPAGE(j) \
    (((j) == 932)   || \
    ((j) == 936)   || \
    ((j) == 949)   || \
    ((j) == 950)   || \
    ((j) == 1361))

// printscan\print\drivers\usermode\driverui\dm.c
#define DM_SIZE320  sizeof(DEVMODE320)
#define DM_SIZE400  (DM_SIZE320 + sizeof(DMEXTRA400))
#define DM_SIZE401  (DM_SIZE400 + sizeof(DMEXTRA401))

// printscan\print\drivers\usermode\driverui\driverui.h
#define LOAD_STRING_PAGESIZE_NAME(pci, pPageSize, pwch, maxsize) \
        BLoadPageSizeNameString(pci, (pPageSize)->GenericOption.loDisplayName, pwch, maxsize, (pPageSize)->dwPaperSizeID)

// printscan\print\drivers\usermode\gpdres\csn46res\n403diz.h
#define    N403_CCHCMYSIZ        (N403_CCHNUM * sizeof(CMYK))    // Cache table size(CMYK)

// printscan\print\drivers\usermode\gpdres\csn46res\n4diz.h
#define    N4_CCHCMYSIZ        (N4_CCHNUM * sizeof(CMYK))   // Table size(CMYK)

// printscan\print\drivers\usermode\gpdres\csn5res\comdiz.h
#define LUTSIZCMY           LUTSIZ016 * sizeof(CMYK)        // LUT size
#define CCHCMYSIZ           (CCHTBLSIZ * sizeof(CMYK))      // Cache table size(CMYK)

// printscan\print\drivers\usermode\gpdres\epageres\epageres.c
#define WRITESPOOLBUF(p,s,n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf((p), (s), (n)))
#define SYMBOLSET_LEN (sizeof(DLI_SYMBOLSET) - 1)    // adjust for terminating NULL

// printscan\print\drivers\usermode\gpdres\epageres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs && \
         (pdevobj)->pdevOEM )

// printscan\print\drivers\usermode\gpdres\fuprjres\pdev.h
#define ESCCMDDEF(n,s) ESCCMD n = {sizeof(s)-1, s};

// printscan\print\drivers\usermode\gpdres\fxartres\fxartres.c
#define YMoveAbs(p, i) \
{   ((POEM_EXTRADATA)((p)->pOEMDM))->ptlCur.y = (i); \
    ((POEM_EXTRADATA)((p)->pOEMDM))->ptlCur.x += ((((POEM_EXTRADATA)((p)->pOEMDM))->lInternalXAdd +VALUE_FONTWIDTH2XPOS_ROUNDUP5 ) \
                                                 / RATE_FONTWIDTH2XPOS ); \
    ((POEM_EXTRADATA)((p)->pOEMDM))->lInternalXAdd = 0;    \
    ZeroMemory(((POEM_EXTRADATA)((p)->pOEMDM))->widBuf, sizeof(LONG) * STRBUFSIZE); \
    XYMoveUpdate(p); }

// printscan\print\drivers\usermode\gpdres\nt4lib\minidrv.h
#define IS_DBCSCODEPAGE(j) \
    (((j) == 932)   || \
    ((j) == 936)   || \
    ((j) == 949)   || \
    ((j) == 950)   || \
    ((j) == 1361))

// printscan\print\drivers\usermode\gpdres\pagesres\pagesres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\gpdres\pagesres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )
#define BVERTFONT(p) \
    ((p)->ulFontID == 6 || (p)->ulFontID == 8)

// printscan\print\drivers\usermode\inc\lib.h
#define IS_DBCSCODEPAGE(j) \
    (((j) == 932)   || \
     ((j) == 936)   || \
     ((j) == 949)   || \
     ((j) == 950)   || \
     ((j) == 1361))

// printscan\print\drivers\usermode\inc\pfm.h
#define WCHARALIGN(a) ((a + (sizeof(WCHAR) - 1)) & ~(sizeof(WCHAR) - 1))

// printscan\print\drivers\usermode\lib\ufl\api\uflmath.h
#define UFLRoundFixed( x )              (((x) + 0x08000) & 0xffff0000)

// printscan\print\drivers\usermode\lib\xcf\algndjmp.h
#define LONGJMP(x,y)            do { (void)memcpy(PS_AlignedJmpBuf, (x), sizeof(jmp_buf)); (void)longjmp(PS_AlignedJmpBuf, (y)); } while (0)

// printscan\print\drivers\usermode\lib\xcf\xcf_priv.h
#define SIZEOF_STACK_VALUES(numMasters)	(sizeof(boolean) + (sizeof(Fixed) * (numMasters)))

// printscan\print\drivers\usermode\msplot\inc\plotdm.h
#define PLOTDM_PRIV_SIZE            (sizeof(PLOTDEVMODE) - sizeof(DEVMODE))

// printscan\print\drivers\usermode\msplot\lib\devmode.c
#define DM_SIZE320  sizeof(DEVMODE320)
#define DM_SIZE400  (DM_SIZE320 + sizeof(DMEXTRA400))
#define DM_SIZE401  (DM_SIZE400 + sizeof(DMEXTRA401))
#define DM_SIZE_CURRENT sizeof(DEVMODEW)
#define DM_SIZE_CURRENT sizeof(DEVMODEA)

// printscan\print\drivers\usermode\msplot\plotter\htblt.h
#define HTXB_TABLE_SIZE     (HTXB_COUNT * sizeof(HTXB))

// printscan\print\drivers\usermode\msplot\plotui\cpsui.c
#define SIZE_OPTTYPE(cOP)   (sizeof(OPTPARAM) + ((cOP) * sizeof(OPTPARAM)))

// printscan\print\drivers\usermode\msplot\plotui\plotui.h
#define PI_PADJHTINFO(pPI)      (PDEVHTINFO)&((pPI)->ExtraData)

// printscan\print\drivers\usermode\tools\uni\gpc2gpd\gpc2gpd.h
#define GETPAGEPROMEM(pdh, pps) (((pdh)->wVersion >= GPC_VERSION3) ? \
                                 pps->wPageProtMem : LETTER300X300MEM)

// printscan\print\drivers\usermode\unidrv2\font\fmmacro.h
#define  SIZEOFDEVPFM()        (sizeof( FONTMAP ) + sizeof(FONTMAP_DEV))

// printscan\print\drivers\usermode\unidrv2\vector\pclxl\xloutput.h
#define GET_FOREGROUND_ROP3(rop4) ((rop4) & 0xFF)

// printscan\print\spooler\localspl\local.h
#define SplWmiCopyEndJobData(WmiData, pIniJob, CreateInfo) \
{ \
    if ((pIniJob)->pDatatype && \
        (_wcsnicmp((pIniJob)->pDatatype, L"TEXT", 4) == 0)) \
        (WmiData)->uJobData.eDataType = eDataTypeTEXT; \
    else if ((pIniJob)->pDatatype && \
             (_wcsnicmp((pIniJob)->pDatatype, L"NT EMF", 6) == 0)) \
        (WmiData)->uJobData.eDataType = eDataTypeEMF; \
    else \
        (WmiData)->uJobData.eDataType = eDataTypeRAW; \
    (WmiData)->uJobData.ulSize = (pIniJob)->Size; \
    (WmiData)->uJobData.ulPages = (pIniJob)->cPagesPrinted; \
    (WmiData)->uJobData.ulPagesPerSide = (pIniJob)->dwJobNumberOfPagesPerSide; \
    (WmiData)->uJobData.sFilesOpened = 0; \
    (WmiData)->uJobData.sFilesOpened += \
        (((CreateInfo) & FP_SHD_CREATED) ? 1 : 0); \
    (WmiData)->uJobData.sFilesOpened += \
        (((CreateInfo) & FP_SPL_WRITER_CREATED) ? 1 : 0); \
    (WmiData)->uJobData.sFilesOpened += \
        (((CreateInfo) & FP_SPL_READER_CREATED) ? 1 : 0); \
}

// printscan\print\spooler\localspl\spltypes.h
#define SPOOL_SIZE  sizeof( SPOOL )
#define RESIZEPORTPRINTERS(a, c)   ReallocSplMem((a)->ppIniPrinter, \
                                     (a)->cPrinters * sizeof((a)->ppIniPrinter), \
                                   ( (a)->cPrinters + (c) ) * sizeof( (a)->ppIniPrinter ) )
#define RESIZEPRINTERPORTS(a, c)   ReallocSplMem((a)->ppIniPorts, \
                                     (a)->cPorts * sizeof((a)->ppIniPorts), \
                                   ( (a)->cPorts + (c) ) * sizeof( (a)->ppIniPorts ) )

// printscan\print\spooler\monitors\local\irda.c
#define     BUF_SIZE            sizeof(DEVICELIST) + (DEVICE_LIST_LEN - 1) * sizeof(IRDA_DEVICE_INFO)

// printscan\print\spooler\monitors\tcpmon\tcpmib\stdoids.h
#define OID_SIZEOF( Oid )      ( sizeof Oid / sizeof(UINT) )

// printscan\print\spooler\spoolss\bidispl\globals.h
#define BIDI_INT_SIZE (sizeof (ULONG))
#define BIDI_FLOAT_SIZE (sizeof (FLOAT))
#define BIDI_BOOL_SIZE (sizeof (BOOL))

// printscan\print\spooler\wpnpinst\wow\inc\ddeml.h
#define     XTYP_ERROR              (0x0000 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK )
#define     XTYP_ADVREQ             (0x0020 | XCLASS_DATA | XTYPF_NOBLOCK )
#define     XTYP_CONNECT            (0x0060 | XCLASS_BOOL | XTYPF_NOBLOCK)
#define     XTYP_CONNECT_CONFIRM    (0x0070 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_REGISTER           (0x00A0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_DISCONNECT         (0x00C0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_UNREGISTER         (0x00D0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_WILDCONNECT        (0x00E0 | XCLASS_DATA | XTYPF_NOBLOCK)
#define     XTYP_MONITOR            (0x00F0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)

// printscan\print\spooler\wpnpinst\wow\inc\prsht.h
#define PSM_REMOVEPAGE          (WM_USER + 102)
#define PSM_ADDPAGE             (WM_USER + 103)

// printscan\print\spooler\wpnpinst\wow\inc\stdarg.h
#define va_start(ap,v) ap = (va_list)&v + sizeof(v)
#define va_arg(ap,t) ((t _FAR_ *)(ap += sizeof(t)))[-1]

// printscan\print\spooler\wpnpinst\wow\inc\stdio.h
#define  L_tmpnam sizeof(P_tmpdir)+8

// printscan\publish\minidrv.h
#define IS_DBCSCODEPAGE(j) \
    (((j) == 932)   || \
    ((j) == 936)   || \
    ((j) == 949)   || \
    ((j) == 950)   || \
    ((j) == 1361))

// printscan\ui\compstui\apilayer.h
#define SIZE_DB(c)      (sizeof(MYDATABLOCK) + (c))

// printscan\ui\inc\pviewids.h
#define PWM_SETPREVIEWALIGNMENT      (WM_USER+635)

// printscan\ui\photowiz\start.h
#define STARTPAGE_MSG_LOAD_ITEMS    (WM_USER+150)   // start loading items...

// printscan\ui\printui\prhlpids.h
#define IDH_PPGENL_PRINT_TEST_PAGE        1110       // General: "Print &Test Page" (Button) (ctrl id 3007)
#define IDH_PPADV_SEPARATOR_PAGE_BROWSE   1510       // Separator Page: "&Browse..." (Button) (ctrl id 4400)
#define IDH_PPADV_SPOOL_ALL                        1380       // Scheduling: "S&tart printing after last page is spooled" (Button) (ctrl id 3222)
#define IDH_PPADV_SEPARATOR_PAGE                   1470       // General: "&Separator Page..." (Button) (ctrl id 3008)

// printscan\wia\common\jpeglib\jinclude.h
#define JFREAD(file,buf,sizeofbuf)  \
  ((size_t) fread((void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))
#define JFWRITE(file,buf,sizeofbuf)  \
  ((size_t) fwrite((const void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))

// printscan\wia\common\jpeglib\jpegapi.h
#define ALIGNIT(ap,t) \
    ((((size_t)(ap))+(sizeof(t)<8?3:7)) & (sizeof(t)<8?~3:~7))

// printscan\wia\inc\stipriv.h
#define cbX(X) sizeof(X)

// printscan\wia\kernel\qv2kux\qv2kux.c
#define FDO_EXTENSION_SIZE sizeof(FDO_EXTENSION)

// printscan\wia\test\wiastress\wrappers.h
#define DECLARE_TOOLHELP32_FIND(CLASSNAME, STRUCT, FINDFIRST, FINDNEXT) \
                                                                        \
class CLASSNAME : public STRUCT                                         \
{                                                                       \
public:                                                                 \
	CLASSNAME(                                                          \
		HANDLE hSnapShot                                                \
	)                                                                   \
    {                                                                   \
		m_hSnapShot = hSnapShot;                                        \
		dwSize = sizeof(STRUCT);                                        \
        m_bFound = FINDFIRST(m_hSnapShot, this);                        \
	}                                                                   \
                                                                        \
	VOID                                                                \
	FindNext()                                                          \
	{                                                                   \
		m_bFound = FINDNEXT(m_hSnapShot, this);                         \
	}                                                                   \
                                                                        \
	BOOL                                                                \
	IsFound() const                                                     \
	{                                                                   \
		return m_bFound;                                                \
	}                                                                   \
                                                                        \
private:                                                                \
	HANDLE m_hSnapShot;                                                 \
	BOOL   m_bFound;                                                    \
};                                                                      \

// public\ddk\inc\afilter.h
#define ARC_PROTOCOL_HEADER_SIZE        (sizeof(ARC_PROTOCOL_HEADER))

// public\ddk\inc\classpnp.h
#define ClasspAllocateSrb(ext)                      \
    ExAllocateFromNPagedLookasideList(              \
        &((ext)->CommonExtension.SrbLookasideList))

// public\ddk\inc\d3dhal.h
#define D3DHAL_DEFAULT_TL_NUM   ((32 * 1024) / sizeof (D3DTLVERTEX))
#define D3DHAL_DEFAULT_H_NUM    ((32 * 1024) / sizeof (D3DHVERTEX))
#define D3DDEVICEDESCSIZE_V1 (sizeof(D3DDEVICEDESC_V1))
#define D3DDEVICEDESCSIZE_V2 (sizeof(D3DDEVICEDESC_V2))
#define D3DDEVICEDESCSIZE_V3 (sizeof(D3DDEVICEDESC_V3))
#define D3DHAL_GLOBALDRIVERDATASIZE (sizeof(D3DHAL_GLOBALDRIVERDATA))
#define D3DHAL_D3DEXTENDEDCAPSSIZE (sizeof(D3DHAL_D3DEXTENDEDCAPS))
#define D3DHAL_D3DDX6EXTENDEDCAPSSIZE (sizeof(D3DHAL_D3DDX6EXTENDEDCAPS))
#define D3DHAL_SIZE_V1 sizeof( D3DHAL_CALLBACKS )
#define D3DHAL_CALLBACKS2SIZE       sizeof(D3DHAL_CALLBACKS2)
#define D3DHAL_CALLBACKS3SIZE       sizeof(D3DHAL_CALLBACKS3)

// public\ddk\inc\hbapiwmi.h
    #define MSFC_FibrePortHBAStatistics_UniquePortId_SIZE sizeof(ULONGLONG)
    #define MSFC_FibrePortHBAStatistics_TxFrames_SIZE sizeof(LONGLONG)
    #define MSFC_FibrePortHBAStatistics_RxFrames_SIZE sizeof(LONGLONG)
    #define MSFC_FibrePortHBAStatistics_ErrorFrames_SIZE sizeof(LONGLONG)
    #define MSFC_FibrePortHBAStatistics_DumpedFrames_SIZE sizeof(LONGLONG)
    #define MSFC_HBAPortAttributesResults_PortFcId_SIZE sizeof(ULONG)
    #define MSFC_HBAPortAttributesResults_PortType_SIZE sizeof(ULONG)
    #define MSFC_HBAPortAttributesResults_PortState_SIZE sizeof(ULONG)
    #define MSFC_HBAPortAttributesResults_PortSupportedClassofService_SIZE sizeof(ULONG)
    #define MSFC_HBAPortAttributesResults_PortSupportedSpeed_SIZE sizeof(ULONG)
    #define MSFC_HBAPortAttributesResults_PortSpeed_SIZE sizeof(ULONG)
    #define MSFC_HBAPortAttributesResults_NumberofDiscoveredPorts_SIZE sizeof(ULONG)
    #define MSFC_FibrePortHBAAttributes_UniquePortId_SIZE sizeof(ULONGLONG)
    #define MSFC_FibrePortHBAAttributes_Attributes_SIZE sizeof(MSFC_HBAPortAttributesResults)
    #define MSFC_FCAdapterHBAAttributes_UniqueAdapterId_SIZE sizeof(ULONGLONG)
    #define MSFC_FCAdapterHBAAttributes_VendorSpecificID_SIZE sizeof(ULONG)
    #define MSFC_FCAdapterHBAAttributes_NumberOfPorts_SIZE sizeof(ULONG)
    #define HBAFC3MgmtInfo_UniqueAdapterId_SIZE sizeof(ULONGLONG)
    #define HBAFC3MgmtInfo_unittype_SIZE sizeof(ULONG)
    #define HBAFC3MgmtInfo_PortId_SIZE sizeof(ULONG)
    #define HBAFC3MgmtInfo_NumberOfAttachedNodes_SIZE sizeof(ULONG)
    #define HBAFC3MgmtInfo_IPVersion_SIZE sizeof(USHORT)
    #define HBAFC3MgmtInfo_UDPPort_SIZE sizeof(USHORT)
    #define HBAFC3MgmtInfo_IPAddress_SIZE sizeof(UCHAR[16])
    #define HBAFC3MgmtInfo_reserved_SIZE sizeof(USHORT)
    #define GetDiscoveredPortAttributes_IN_PortIndex_SIZE sizeof(ULONG)
    #define GetDiscoveredPortAttributes_IN_DiscoveredPortIndex_SIZE sizeof(ULONG)
    #define GetDiscoveredPortAttributes_OUT_PortAttributes_SIZE sizeof(MSFC_HBAPortAttributesResults)
    #define GetPortAttributesByWWN_OUT_PortAttributes_SIZE sizeof(MSFC_HBAPortAttributesResults)
    #define SendRNID_IN_wwntype_SIZE sizeof(ULONG)
    #define GetFC3MgmtInfo_OUT_MgmtInfo_SIZE sizeof(HBAFC3MgmtInfo)
    #define SetFC3MgmtInfo_IN_MgmtInfo_SIZE sizeof(HBAFC3MgmtInfo)
    #define HBAScsiID_ScsiBusNumber_SIZE sizeof(ULONG)
    #define HBAScsiID_ScsiTargetNumber_SIZE sizeof(ULONG)
    #define HBAScsiID_ScsiOSLun_SIZE sizeof(ULONG)
    #define HBAFCPID_Fcid_SIZE sizeof(ULONG)
    #define HBAFCPID_FcpLun_SIZE sizeof(ULONGLONG)

// public\ddk\inc\ksi.h
#define DEFINE_KSPROPERTY_ITEM_SERVICE_BUILDCACHE(SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_SERVICE_BUILDCACHE,\
        NULL,\
        sizeof(KSPROPERTY),\
        sizeof(L"\\\\?\\"),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_SERVICE_MERIT(SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_SERVICE_MERIT,\
        NULL,\
        sizeof(KSPROPERTY),\
        sizeof(ULONG) + sizeof(L"\\\\?\\"),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)

// public\ddk\inc\miniport.h
#define MAX_NATURAL_ALIGNMENT sizeof(ULONGLONG)
#define MAX_NATURAL_ALIGNMENT sizeof(ULONG)
#define PROBE_ALIGNMENT( _s ) (TYPE_ALIGNMENT( _s ) > TYPE_ALIGNMENT( ULONG ) ? \
                               TYPE_ALIGNMENT( _s ) : TYPE_ALIGNMENT( ULONG ))

// public\ddk\inc\minitape.h
#define MAX_NATURAL_ALIGNMENT sizeof(ULONGLONG)
#define MAX_NATURAL_ALIGNMENT sizeof(ULONG)
#define PROBE_ALIGNMENT( _s ) (TYPE_ALIGNMENT( _s ) > TYPE_ALIGNMENT( ULONG ) ? \
                               TYPE_ALIGNMENT( _s ) : TYPE_ALIGNMENT( ULONG ))
#define SCSI_REQUEST_BLOCK_SIZE sizeof(SCSI_REQUEST_BLOCK)

// public\ddk\inc\ndis.h
#define MAX_NATURAL_ALIGNMENT sizeof(ULONGLONG)
#define MAX_NATURAL_ALIGNMENT sizeof(ULONG)
#define PROBE_ALIGNMENT( _s ) (TYPE_ALIGNMENT( _s ) > TYPE_ALIGNMENT( ULONG ) ? \
                               TYPE_ALIGNMENT( _s ) : TYPE_ALIGNMENT( ULONG ))
#define DECLARE_CONST_UNICODE_STRING(_variablename, _string) \
const WCHAR _variablename ## _buffer[] = _string; \
const UNICODE_STRING _variablename = { sizeof(_string) - sizeof(WCHAR), sizeof(_string), (PWSTR) _variablename ## _buffer };
#define RTL_FIELD_SIZE(type, field) (sizeof(((type *)0)->field))
#define NdisMTransferDataComplete(_M, _P, _S, _B)   \
                                        (*((PNDIS_MINIPORT_BLOCK)(_M))->TDCompleteHandler)(_M, _P, _S, _B)
#define NdisMWanSendComplete(_M_, _P_, _S_)                                             \
                (*((PNDIS_MINIPORT_BLOCK)(_M_))->WanSendCompleteHandler)(_M_, _P_, _S_)
#define NdisMQueryInformationComplete(_M, _S)   \
                                        (*((PNDIS_MINIPORT_BLOCK)(_M))->QueryCompleteHandler)(_M, _S)
#define NdisMSetInformationComplete(_M, _S) \
                                        (*((PNDIS_MINIPORT_BLOCK)(_M))->SetCompleteHandler)(_M, _S)
#define NdisMWanIndicateReceive(_S_, _M_, _C_, _P_, _Z_)                        \
                (*((PNDIS_MINIPORT_BLOCK)(_M_))->WanRcvHandler)(_S_, _M_, _C_, _P_, _Z_)
#define NdisMWanIndicateReceiveComplete(_M_, _C_)                                   \
                (*((PNDIS_MINIPORT_BLOCK)(_M_))->WanRcvCompleteHandler)(_M_, _C_)
#define NdisMEthIndicateReceive( _H, _C, _B, _SZ, _L, _LSZ, _PSZ)               \
{                                                                               \
    (*((PNDIS_MINIPORT_BLOCK)(_H))->EthRxIndicateHandler)(                      \
        ((PNDIS_MINIPORT_BLOCK)(_H))->EthDB,                                    \
        _C,                                                                     \
        _B,                                                                     \
        _B,                                                                     \
        _SZ,                                                                    \
        _L,                                                                     \
        _LSZ,                                                                   \
        _PSZ                                                                    \
        );                                                                      \
}
#define NdisMTrIndicateReceive( _H, _C, _B, _SZ, _L, _LSZ, _PSZ)                \
{                                                                               \
    (*((PNDIS_MINIPORT_BLOCK)(_H))->TrRxIndicateHandler)(                       \
        ((PNDIS_MINIPORT_BLOCK)(_H))->TrDB,                                     \
        _C,                                                                     \
        _B,                                                                     \
        _SZ,                                                                    \
        _L,                                                                     \
        _LSZ,                                                                   \
        _PSZ                                                                    \
        );                                                                      \
}
#define NdisMFddiIndicateReceive( _H, _C, _B, _SZ, _L, _LSZ, _PSZ)              \
{                                                                               \
    (*((PNDIS_MINIPORT_BLOCK)(_H))->FddiRxIndicateHandler)(                     \
            ((PNDIS_MINIPORT_BLOCK)(_H))->FddiDB,                               \
            _C,                                                                 \
            (PUCHAR)_B + 1,                                                     \
            ((((PUCHAR)_B)[0] & 0x40) ? FDDI_LENGTH_OF_LONG_ADDRESS             \
                            : FDDI_LENGTH_OF_SHORT_ADDRESS),                    \
            _B,                                                                 \
            _SZ,                                                                \
            _L,                                                                 \
            _LSZ,                                                               \
            _PSZ                                                                \
    );                                                                          \
}
#define NdisMArcIndicateReceive( _H, _HD, _D, _SZ)                              \
{                                                                               \
    ArcFilterDprIndicateReceive(((PNDIS_MINIPORT_BLOCK)(_H))->ArcDB,            \
                                _HD,                                            \
                                _D,                                             \
                                _SZ                                             \
                                );                                              \
}
#define NdisMEthIndicateReceiveComplete( _H )                                   \
{                                                                               \
    (*((PNDIS_MINIPORT_BLOCK)(_H))->EthRxCompleteHandler)(                      \
                                        ((PNDIS_MINIPORT_BLOCK)_H)->EthDB);     \
}
#define NdisMTrIndicateReceiveComplete( _H )                                    \
{                                                                               \
    (*((PNDIS_MINIPORT_BLOCK)(_H))->TrRxCompleteHandler)(                       \
                                        ((PNDIS_MINIPORT_BLOCK)_H)->TrDB);      \
}
#define NdisMFddiIndicateReceiveComplete( _H )                                  \
{                                                                               \
    (*((PNDIS_MINIPORT_BLOCK)(_H))->FddiRxCompleteHandler)(                     \
                                        ((PNDIS_MINIPORT_BLOCK)_H)->FddiDB);    \
}
#define NdisMArcIndicateReceiveComplete( _H )                                   \
{                                                                               \
    if (((PNDIS_MINIPORT_BLOCK)_H)->EthDB)                                      \
    {                                                                           \
        NdisMEthIndicateReceiveComplete(_H);                                    \
    }                                                                           \
                                                                                \
    ArcFilterDprIndicateReceiveComplete(((PNDIS_MINIPORT_BLOCK)_H)->ArcDB);     \
}

// public\ddk\inc\netcfgn.h
#define INetCfgPnpReconfigCallback_SendPnpReconfig(This,Layer,pszwUpper,pszwLower,pvData,dwSizeOfData)	\
    (This)->lpVtbl -> SendPnpReconfig(This,Layer,pszwUpper,pszwLower,pvData,dwSizeOfData)
#define INetCfgComponentPropertyUi_MergePropPages(This,pdwDefPages,pahpspPrivate,pcPages,hwndParent,pszStartPage)	\
    (This)->lpVtbl -> MergePropPages(This,pdwDefPages,pahpspPrivate,pcPages,hwndParent,pszStartPage)

// public\ddk\inc\ntddcdrm.h
#define CDROM_TOC_SIZE sizeof(CDROM_TOC)

// public\ddk\inc\ntdddisk.h
#define HISTOGRAM_BUCKET_SIZE   sizeof(HISTOGRAM_BUCKET)
#define DISK_HISTOGRAM_SIZE sizeof(DISK_HISTOGRAM)

// public\ddk\inc\ntddk.h
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))
#define RtlAnsiStringToUnicodeSize(STRING) (                 \
    NLS_MB_CODE_PAGE_TAG ?                                   \
    RtlxAnsiStringToUnicodeSize(STRING) :                    \
    ((STRING)->Length + sizeof(ANSI_NULL)) * sizeof(WCHAR) \
)
        #define IsEqualGUIDAligned(guid1, guid2) \
            ((*(PLONGLONG)(guid1) == *(PLONGLONG)(guid2)) && (*((PLONGLONG)(guid1) + 1) == *((PLONGLONG)(guid2) + 1)))
#define SHORT_SIZE  (sizeof(USHORT))
#define LONG_SIZE       (sizeof(LONG))
#define LONGLONG_SIZE   (sizeof(LONGLONG))
#define IoSizeOfIrp( StackSize ) \
    ((USHORT) (sizeof( IRP ) + ((StackSize) * (sizeof( IO_STACK_LOCATION )))))

// public\ddk\inc\ntdef.h
#define MAX_NATURAL_ALIGNMENT sizeof(ULONGLONG)
#define MAX_NATURAL_ALIGNMENT sizeof(ULONG)
#define PROBE_ALIGNMENT( _s ) (TYPE_ALIGNMENT( _s ) > TYPE_ALIGNMENT( ULONG ) ? \
                               TYPE_ALIGNMENT( _s ) : TYPE_ALIGNMENT( ULONG ))
#define DECLARE_CONST_UNICODE_STRING(_variablename, _string) \
const WCHAR _variablename ## _buffer[] = _string; \
const UNICODE_STRING _variablename = { sizeof(_string) - sizeof(WCHAR), sizeof(_string), (PWSTR) _variablename ## _buffer };
#define RTL_FIELD_SIZE(type, field) (sizeof(((type *)0)->field))

// public\ddk\inc\srb.h
#define CONFIG_INFO_VERSION_2 sizeof(PORT_CONFIGURATION_INFORMATION)
#define SCSI_REQUEST_BLOCK_SIZE sizeof(SCSI_REQUEST_BLOCK)

// public\ddk\inc\storport.h
#define CONFIG_INFO_VERSION_2 sizeof(PORT_CONFIGURATION_INFORMATION)
#define SCSI_REQUEST_BLOCK_SIZE sizeof(SCSI_REQUEST_BLOCK)

// public\ddk\inc\tdikrnl.h
#define TDI_CMSGHDR_ALIGN(length)                           \
            ( ((length) + TYPE_ALIGNMENT(TDI_CMSGHDR)-1) &   \
                (~(TYPE_ALIGNMENT(TDI_CMSGHDR)-1)) )         \
#define TDI_CMSGDATA_ALIGN(length)                          \
            ( ((length) + MAX_NATURAL_ALIGNMENT-1) &        \
                (~(MAX_NATURAL_ALIGNMENT-1)) )
#define TDI_CMSG_DATA(cmsg)             \
            ( (UCHAR *)(cmsg) + TDI_CMSGDATA_ALIGN(sizeof(TDI_CMSGHDR)) )
#define TDI_CMSG_SPACE(length)  \
        (TDI_CMSGDATA_ALIGN(sizeof(TDI_CMSGHDR) + TDI_CMSGHDR_ALIGN(length)))
#define TDI_CMSG_LEN(length)    \
        (TDI_CMSGDATA_ALIGN(sizeof(TDI_CMSGHDR)) + length)

// public\ddk\inc\vfwext.h
#define VFW_HIDE_ALL_PAGES           (VFW_HIDE_SETTINGS_PAGE |\
                                     VFW_HIDE_VIDEOSRC_PAGE  |\
                                     VFW_HIDE_CAMERACONTROL_PAGE)

// public\ddk\inc\wdm\avcstrm.h
#define INIT_AVCSTRM_HEADER( AVCStrm, Request )             \
        (AVCStrm)->SizeOfThisBlock = sizeof(AVC_STREAM_REQUEST_BLOCK); \
        (AVCStrm)->Function = Request;                    \
        (AVCStrm)->Version  = CURRENT_AVCSTRM_DDI_VERSION;

// public\ddk\inc\wdm\hidpi.h
#define HidP_IsSameUsageAndPage(u1, u2) ((* (PULONG) &u1) == (* (PULONG) &u2))

// public\ddk\inc\wdm\strmini.h
#define STREAM_REQUEST_BLOCK_SIZE sizeof(STREAM_REQUEST_BLOCK)

// public\ddk\inc\wdm\wdm.h
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))
#define RtlUnicodeStringToAnsiSize(STRING) (                  \
    NLS_MB_CODE_PAGE_TAG ?                                    \
    RtlxUnicodeStringToAnsiSize(STRING) :                     \
    ((STRING)->Length + sizeof(UNICODE_NULL)) / sizeof(WCHAR) \
)
#define RtlAnsiStringToUnicodeSize(STRING) (                 \
    NLS_MB_CODE_PAGE_TAG ?                                   \
    RtlxAnsiStringToUnicodeSize(STRING) :                    \
    ((STRING)->Length + sizeof(ANSI_NULL)) * sizeof(WCHAR) \
)
        #define IsEqualGUIDAligned(guid1, guid2) \
            ((*(PLONGLONG)(guid1) == *(PLONGLONG)(guid2)) && (*((PLONGLONG)(guid1) + 1) == *((PLONGLONG)(guid2) + 1)))
#define SHORT_SIZE  (sizeof(USHORT))
#define LONG_SIZE       (sizeof(LONG))
#define LONGLONG_SIZE   (sizeof(LONGLONG))
#define IoSizeOfIrp( StackSize ) \
    ((USHORT) (sizeof( IRP ) + ((StackSize) * (sizeof( IO_STACK_LOCATION )))))

// public\ddk\inc\wdm\wmidata.h
    #define MSWmi_MofData_Unused1_SIZE sizeof(ULONG)
    #define MSWmi_MofData_Unused2_SIZE sizeof(ULONG)
    #define MSWmi_MofData_Size_SIZE sizeof(ULONG)
    #define MSWmi_MofData_Unused4_SIZE sizeof(ULONG)
    #define MSAcpiInfo_BootArchitecture_SIZE sizeof(ULONG)
    #define MSAcpiInfo_PreferredProfile_SIZE sizeof(ULONG)
    #define MSAcpiInfo_Capabilities_SIZE sizeof(ULONG)
    #define MSSmBios_RawSMBiosTables_Used20CallingMethod_SIZE sizeof(BOOLEAN)
    #define MSSmBios_RawSMBiosTables_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_Header_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_Header_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_Header_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_Header_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_CPUError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_CPUError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_CPUError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_CPUError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_CPUError_Level_SIZE sizeof(ULONG)
    #define MSMCAEvent_CPUError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_MemoryError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_MemoryError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_MemoryError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_MemoryError_MEM_PHYSICAL_ADDR_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_RESPONDER_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_TARGET_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_REQUESTOR_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_BUS_SPECIFIC_DATA_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_MEM_NODE_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_MEM_CARD_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_MEM_BANK_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_xMEM_DEVICE_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_MEM_MODULE_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_MEM_ROW_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_MEM_COLUMN_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIBusError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIBusError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIBusError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_ADDRESS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_DATA_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_CMD_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_REQUESTOR_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_RESPONDER_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_TARGET_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_ERROR_TYPE_SIZE sizeof(USHORT)
    #define MSMCAEvent_PCIBusError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIComponentError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIComponentError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIComponentError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIComponentError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_VendorId_SIZE sizeof(USHORT)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_DeviceId_SIZE sizeof(USHORT)
    #define MSMCAEvent_PCIComponentError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_SystemEventError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_SystemEventError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_SystemEventError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_SystemEventError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_SystemEventError_SEL_RECORD_ID_SIZE sizeof(USHORT)
    #define MSMCAEvent_SystemEventError_SEL_GENERATOR_ID_SIZE sizeof(USHORT)
    #define MSMCAEvent_SystemEventError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_SMBIOSError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_SMBIOSError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_SMBIOSError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_SMBIOSError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_SMBIOSError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_PlatformSpecificError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_PlatformSpecificError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_PlatformSpecificError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_PlatformSpecificError_PLATFORM_REQUESTOR_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_PLATFORM_RESPONDER_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_PLATFORM_TARGET_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_PLATFORM_BUS_SPECIFIC_DATA_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_Size_SIZE sizeof(ULONG)
    #define MSMCAInfo_CPEControl_CPEPollingInterval_SIZE sizeof(ULONG)
    #define MSMCAInfo_CPEControl_CPEGenerationEnabled_SIZE sizeof(BOOLEAN)
    #define MSPower_DeviceEnable_Enable_SIZE sizeof(BOOLEAN)
    #define MSPower_DeviceWakeEnable_Enable_SIZE sizeof(BOOLEAN)
    #define MSNdis_TransmitBlockSize_NdisTransmitBlockSize_SIZE sizeof(ULONG)
    #define MSNdis_ReceiveBlockSize_NdisReceiveBlockSize_SIZE sizeof(ULONG)
    #define MSNdis_EthernetReceiveErrorAlignment_NdisEthernetReceiveErrorAlignment_SIZE sizeof(ULONG)
    #define KEYBOARD_PORT_WMI_STD_DATA_ConnectorType_SIZE sizeof(ULONG)
    #define KEYBOARD_PORT_WMI_STD_DATA_DataQueueSize_SIZE sizeof(ULONG)
    #define KEYBOARD_PORT_WMI_STD_DATA_FunctionKeys_SIZE sizeof(ULONG)
    #define KEYBOARD_PORT_WMI_STD_DATA_Indicators_SIZE sizeof(ULONG)
    #define KEYBOARD_ID_EX_Type_SIZE sizeof(ULONG)
    #define KEYBOARD_ID_EX_Subtype_SIZE sizeof(ULONG)
    #define MSMouse_ClassInformation_DeviceId_SIZE sizeof(ULONGLONG)
    #define MSKeyboard_ClassInformation_DeviceId_SIZE sizeof(ULONGLONG)
    #define MSAcpi_ThermalZoneTemperature_ThermalStamp_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_ThermalConstant1_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_ThermalConstant2_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_Reserved_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_SamplingPeriod_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_CurrentTemperature_SIZE sizeof(ULONG)
    #define WMI_DISK_GEOMETRY_Cylinders_SIZE sizeof(LONGLONG)
    #define WMI_DISK_GEOMETRY_MediaType_SIZE sizeof(ULONG)
    #define WMI_DISK_GEOMETRY_TracksPerCylinder_SIZE sizeof(ULONG)
    #define WMI_DISK_GEOMETRY_SectorsPerTrack_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_QueueDepth_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_StorageDeviceNumber_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_StorageManagerName_SIZE sizeof(USHORT[8])
    #define MSDiskDriver_Performance_PerfData_SIZE sizeof(WMI_DISK_PERFORMANCE)
    #define ATAPI_FAILURE_PREDICT_DATA_SmartCapability_SIZE sizeof(USHORT)
    #define ALLOW_PERFORMANCE_HIT_IN_Allow_SIZE sizeof(BOOLEAN)
    #define ENABLE_DISABLE_FP_IN_Enable_SIZE sizeof(BOOLEAN)
    #define ENABLE_DISABLE_FP_POLLING_IN_Period_SIZE sizeof(ULONG)
    #define ENABLE_DISABLE_FP_POLLING_IN_Enable_SIZE sizeof(BOOLEAN)
    #define GET_FP_CAPABILITY_OUT_Capability_SIZE sizeof(ULONG)
    #define ENABLE_OFFLINE_DIAGS_OUT_Success_SIZE sizeof(BOOLEAN)
    #define STORAGE_SCSI_INFO_EXCEPTIONS_PageSavable_SIZE sizeof(BOOLEAN)
    #define STORAGE_SCSI_INFO_EXCEPTIONS_Padding_SIZE sizeof(UCHAR)
    #define SERIAL_WMI_COMM_DATA_BaudRate_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_Parity_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_XoffXmitThreshold_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_XonXmitThreshold_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_SupportDTRDSR_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SupportRTSCTS_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SupportXonXoff_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SettableBaudRate_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SettableFlowControl_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SettableParity_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_IsBusy_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_HW_DATA_IrqNumber_SIZE sizeof(ULONG)
    #define SERIAL_WMI_HW_DATA_IrqVector_SIZE sizeof(ULONG)
    #define SERIAL_WMI_HW_DATA_IrqLevel_SIZE sizeof(ULONG)
    #define SERIAL_WMI_HW_DATA_InterruptType_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwReserved1_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwProvSubType_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwProvCapabilities_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwSettableParams_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwSettableBaud_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_wSettableData_SIZE sizeof(USHORT)
    #define SERIAL_WMI_COMMPROP_wSettableStopParity_SIZE sizeof(USHORT)
    #define SERIAL_WMI_COMMPROP_dwCurrentTxQueue_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwCurrentRxQueue_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwProvSpec1_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwProvSpec2_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_SECTORS_PER_READ_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_MAX_SECTORS_PER_READ_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_PLAY_ENABLED_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_CDDA_SUPPORTED_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_CDDA_ACCURATE_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_STD_DATA_Reserved1_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_PERF_DATA_PROCESSED_SIZE sizeof(LONGLONG)
    #define RegisteredGuids_GuidType_SIZE sizeof(ULONG)
    #define RegisteredGuids_EnableLevel_SIZE sizeof(ULONG)
    #define RegisteredGuids_IsEnabled_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_DRIVE_PARAMETERS_MaximumBlockSize_SIZE sizeof(ULONG)
    #define WMI_TAPE_DRIVE_PARAMETERS_MinimumBlockSize_SIZE sizeof(ULONG)
    #define WMI_TAPE_DRIVE_PARAMETERS_DefaultBlockSize_SIZE sizeof(ULONG)
    #define WMI_TAPE_DRIVE_PARAMETERS_CompressionCapable_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_DRIVE_PARAMETERS_CompressionEnabled_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_DRIVE_PARAMETERS_ReportSetmarks_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_DRIVE_PARAMETERS_HardwareErrorCorrection_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_MEDIA_PARAMETERS_AvailableCapacity_SIZE sizeof(ULONGLONG)
    #define WMI_TAPE_MEDIA_PARAMETERS_BlockSize_SIZE sizeof(ULONG)
    #define WMI_TAPE_MEDIA_PARAMETERS_MediaWriteProtected_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_WARNING_DriveProblemType_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadCorrectedWithoutDelay_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadCorrectedWithDelay_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadTotalErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadTotalCorrectedErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadTotalUncorrectedErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadCorrectionAlgorithmProcessed_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteCorrectedWithoutDelay_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteCorrectedWithDelay_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteTotalErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteTotalCorrectedErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteTotalUncorrectedErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteCorrectionAlgorithmProcessed_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_NonMediumErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_ReadWarning_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_WriteWarning_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_HardError_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_ReadFailure_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_WriteFailure_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_UnsupportedFormat_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_TapeSnapped_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_DriveRequiresCleaning_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_DriveHardwareError_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_ScsiInterfaceError_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_MediaLife_SIZE sizeof(BOOLEAN)
    #define WMI_CHANGER_PARAMETERS_NumberOfSlots_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_NumberOfDrives_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_NumberOfIEPorts_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_NumberOfTransports_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_NumberOfDoors_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_NumberOfCleanerSlots_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_MagazineSize_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PROBLEM_WARNING_ChangerProblemType_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PROBLEM_DEVICE_ERROR_ChangerProblemType_SIZE sizeof(ULONG)

// public\halkit\inc\arc.h
#define SYSTEM_BLOCK (&GlobalSystemBlock)
#define SYSTEM_BLOCK (&GlobalSystemBlock)
#define ArcExecute(ImagePath, Argc, Argv, Envp) \
    ((PARC_EXECUTE_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[ExecuteRoutine])) \
        ((ImagePath), (Argc), (Argv), (Envp))
#define ArcInvoke(EntryAddress, StackAddress, Argc, Argv, Envp) \
    ((PARC_INVOKE_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[InvokeRoutine])) \
        ((EntryAddress), (StackAddress), (Argc), (Argv), (Envp))
#define ArcLoad(ImagePath, TopAddress, EntryAddress, LowAddress) \
    ((PARC_LOAD_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[LoadRoutine])) \
        ((ImagePath), (TopAddress), (EntryAddress), (LowAddress))
#define ArcHalt() \
    ((PARC_HALT_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[HaltRoutine]))()
#define ArcPowerDown() \
    ((PARC_POWERDOWN_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[PowerDownRoutine]))()
#define ArcRestart() \
    ((PARC_RESTART_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[RestartRoutine]))()
#define ArcReboot() \
    ((PARC_REBOOT_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[RebootRoutine]))()
#define ArcEnterInteractiveMode() \
    ((PARC_INTERACTIVE_MODE_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[InteractiveModeRoutine]))()
#define ArcGetChild(Component) \
    ((PARC_GET_CHILD_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[GetChildRoutine])) \
        ((Component))
#define ArcGetParent(Component) \
    ((PARC_GET_PARENT_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[GetParentRoutine])) \
        ((Component))
#define ArcGetPeer(Component) \
    ((PARC_GET_PEER_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[GetPeerRoutine])) \
        ((Component))
#define ArcAddChild(Component, NewComponent, ConfigurationData) \
    ((PARC_ADD_CHILD_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[AddChildRoutine])) \
        ((Component), (NewComponent), (ConfigurationData))
#define ArcGetComponent(Path) \
    ((PARC_GET_COMPONENT_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[GetComponentRoutine])) \
        ((Path))
#define ArcGetConfigurationData(ConfigurationData, Component) \
    ((PARC_GET_DATA_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[GetDataRoutine])) \
        ((ConfigurationData), (Component))
#define ArcSaveConfiguration() \
    ((PARC_SAVE_CONFIGURATION_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[SaveConfigurationRoutine]))()
#define ArcGetSystemId() \
    ((PARC_GET_SYSTEM_ID_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[GetSystemIdRoutine]))()
#define ArcGetMemoryDescriptor(MemoryDescriptor) \
    ((PARC_MEMORY_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[MemoryRoutine])) \
        ((MemoryDescriptor))
#define ArcGetTime() \
    ((PARC_GET_TIME_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[GetTimeRoutine]))()
#define ArcGetRelativeTime() \
    ((PARC_GET_RELATIVE_TIME_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[GetRelativeTimeRoutine]))()
#define ArcMount(MountPath, Operation) \
    ((PARC_MOUNT_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[MountRoutine])) \
        ((MountPath), (Operation))
#define ArcOpen(OpenPath, OpenMode, FileId) \
    ((PARC_OPEN_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[OpenRoutine])) \
        ((OpenPath), (OpenMode), (FileId))
#define ArcRead(FileId, Buffer, Length, Count) \
    ((PARC_READ_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[ReadRoutine])) \
        ((FileId), (Buffer), (Length), (Count))
#define ArcWrite(FileId, Buffer, Length, Count) \
    ((PARC_WRITE_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[WriteRoutine])) \
        ((FileId), (Buffer), (Length), (Count))
#define ArcGetFileInformation(FileId, FileInformation) \
    ((PARC_GET_FILE_INFO_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[GetFileInformationRoutine])) \
        ((FileId), (FileInformation))
#define ArcGetDirectoryEntry(FileId, Buffer, Length, Count) \
    ((PARC_GET_DIRECTORY_ENTRY_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[GetDirectoryEntryRoutine])) \
        ((FileId), (Buffer), (Length), (Count))
#define ArcGetEnvironmentVariable(Variable) \
    ((PARC_GET_ENVIRONMENT_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[GetEnvironmentRoutine])) \
        ((Variable))
#define ArcSetEnvironmentVariable(Variable, Value) \
    ((PARC_SET_ENVIRONMENT_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[SetEnvironmentRoutine])) \
        ((Variable), (Value))
#define ArcFlushAllCaches() \
    ((PARC_FLUSH_ALL_CACHES_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[FlushAllCachesRoutine]))()
#define ArcTestUnicodeCharacter(FileId, UnicodeCharacter) \
    ((PARC_TEST_UNICODE_CHARACTER_ROUTINE)(SYSTEM_BLOCK->FirmwareVector[TestUnicodeCharacterRoutine])) \
        ((FileId), (UnicodeCharacter))

// public\halkit\inc\ntapm.h
#define HAL_APM_TABLE_SIZE  (sizeof(PM_DISPATCH_TABLE)+sizeof(PVOID))

// public\halkit\inc\nthal.h
        #define IsEqualGUIDAligned(guid1, guid2) \
            ((*(PLONGLONG)(guid1) == *(PLONGLONG)(guid2)) && (*((PLONGLONG)(guid1) + 1) == *((PLONGLONG)(guid2) + 1)))
#define SHORT_SIZE  (sizeof(USHORT))
#define LONG_SIZE       (sizeof(LONG))
#define LONGLONG_SIZE   (sizeof(LONGLONG))
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))
#define KTRAP_FRAME_ALIGN   (sizeof(ULONG))
#define EXCEPTION_RECORD_LENGTH                                              \
    ((sizeof(EXCEPTION_RECORD) + STACK_ROUND) & ~STACK_ROUND)
#define IoSizeOfIrp( StackSize ) \
    ((USHORT) (sizeof( IRP ) + ((StackSize) * (sizeof( IO_STACK_LOCATION )))))

// public\ifskit\inc\ntifs.h
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))
#define RtlUnicodeStringToAnsiSize(STRING) (                  \
    NLS_MB_CODE_PAGE_TAG ?                                    \
    RtlxUnicodeStringToAnsiSize(STRING) :                     \
    ((STRING)->Length + sizeof(UNICODE_NULL)) / sizeof(WCHAR) \
)
#define RtlUnicodeStringToOemSize(STRING) (                   \
    NLS_MB_OEM_CODE_PAGE_TAG ?                                \
    RtlxUnicodeStringToOemSize(STRING) :                      \
    ((STRING)->Length + sizeof(UNICODE_NULL)) / sizeof(WCHAR) \
)
#define RtlAnsiStringToUnicodeSize(STRING) (                 \
    NLS_MB_CODE_PAGE_TAG ?                                   \
    RtlxAnsiStringToUnicodeSize(STRING) :                    \
    ((STRING)->Length + sizeof(ANSI_NULL)) * sizeof(WCHAR) \
)
#define RtlOemStringToUnicodeSize(STRING) (                  \
    NLS_MB_OEM_CODE_PAGE_TAG ?                               \
    RtlxOemStringToUnicodeSize(STRING) :                     \
    ((STRING)->Length + sizeof(ANSI_NULL)) * sizeof(WCHAR) \
)
        #define IsEqualGUIDAligned(guid1, guid2) \
            ((*(PLONGLONG)(guid1) == *(PLONGLONG)(guid2)) && (*((PLONGLONG)(guid1) + 1) == *((PLONGLONG)(guid2) + 1)))
#define SHORT_SIZE  (sizeof(USHORT))
#define LONG_SIZE       (sizeof(LONG))
#define LONGLONG_SIZE   (sizeof(LONGLONG))
#define IoSizeOfIrp( StackSize ) \
    ((USHORT) (sizeof( IRP ) + ((StackSize) * (sizeof( IO_STACK_LOCATION )))))

// public\internal\admin\inc\cmdline.h
#define __realloc( block, size )		\
	(((block) != NULL) ? realloc( block, size ) : __malloc( size ))

// public\internal\admin\inc\qmgr.h
#define IBackgroundCopyJob1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyJob1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyJob1_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyJob1_CancelJob(This)	\
    (This)->lpVtbl -> CancelJob(This)
#define IBackgroundCopyJob1_GetProgress(This,dwFlags,pdwProgress)	\
    (This)->lpVtbl -> GetProgress(This,dwFlags,pdwProgress)
#define IBackgroundCopyJob1_GetStatus(This,pdwStatus,pdwWin32Result,pdwTransportResult,pdwNumOfRetries)	\
    (This)->lpVtbl -> GetStatus(This,pdwStatus,pdwWin32Result,pdwTransportResult,pdwNumOfRetries)
#define IBackgroundCopyJob1_AddFiles(This,cFileCount,ppFileSet)	\
    (This)->lpVtbl -> AddFiles(This,cFileCount,ppFileSet)
#define IBackgroundCopyJob1_GetFile(This,cFileIndex,pFileInfo)	\
    (This)->lpVtbl -> GetFile(This,cFileIndex,pFileInfo)
#define IBackgroundCopyJob1_GetFileCount(This,pdwFileCount)	\
    (This)->lpVtbl -> GetFileCount(This,pdwFileCount)
#define IBackgroundCopyJob1_SwitchToForeground(This)	\
    (This)->lpVtbl -> SwitchToForeground(This)
#define IBackgroundCopyJob1_get_JobID(This,pguidJobID)	\
    (This)->lpVtbl -> get_JobID(This,pguidJobID)
#define IEnumBackgroundCopyJobs1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumBackgroundCopyJobs1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumBackgroundCopyJobs1_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumBackgroundCopyJobs1_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)
#define IEnumBackgroundCopyJobs1_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IEnumBackgroundCopyJobs1_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumBackgroundCopyJobs1_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)
#define IEnumBackgroundCopyJobs1_GetCount(This,puCount)	\
    (This)->lpVtbl -> GetCount(This,puCount)
#define IBackgroundCopyGroup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyGroup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyGroup_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyGroup_GetProp(This,propID,pvarVal)	\
    (This)->lpVtbl -> GetProp(This,propID,pvarVal)
#define IBackgroundCopyGroup_SetProp(This,propID,pvarVal)	\
    (This)->lpVtbl -> SetProp(This,propID,pvarVal)
#define IBackgroundCopyGroup_GetProgress(This,dwFlags,pdwProgress)	\
    (This)->lpVtbl -> GetProgress(This,dwFlags,pdwProgress)
#define IBackgroundCopyGroup_GetStatus(This,pdwStatus,pdwJobIndex)	\
    (This)->lpVtbl -> GetStatus(This,pdwStatus,pdwJobIndex)
#define IBackgroundCopyGroup_GetJob(This,jobID,ppJob)	\
    (This)->lpVtbl -> GetJob(This,jobID,ppJob)
#define IBackgroundCopyGroup_SuspendGroup(This)	\
    (This)->lpVtbl -> SuspendGroup(This)
#define IBackgroundCopyGroup_ResumeGroup(This)	\
    (This)->lpVtbl -> ResumeGroup(This)
#define IBackgroundCopyGroup_CancelGroup(This)	\
    (This)->lpVtbl -> CancelGroup(This)
#define IBackgroundCopyGroup_get_Size(This,pdwSize)	\
    (This)->lpVtbl -> get_Size(This,pdwSize)
#define IBackgroundCopyGroup_get_GroupID(This,pguidGroupID)	\
    (This)->lpVtbl -> get_GroupID(This,pguidGroupID)
#define IBackgroundCopyGroup_CreateJob(This,guidJobID,ppJob)	\
    (This)->lpVtbl -> CreateJob(This,guidJobID,ppJob)
#define IBackgroundCopyGroup_EnumJobs(This,dwFlags,ppEnumJobs)	\
    (This)->lpVtbl -> EnumJobs(This,dwFlags,ppEnumJobs)
#define IBackgroundCopyGroup_SwitchToForeground(This)	\
    (This)->lpVtbl -> SwitchToForeground(This)
#define IBackgroundCopyGroup_QueryNewJobInterface(This,iid,pUnk)	\
    (This)->lpVtbl -> QueryNewJobInterface(This,iid,pUnk)
#define IBackgroundCopyGroup_SetNotificationPointer(This,iid,pUnk)	\
    (This)->lpVtbl -> SetNotificationPointer(This,iid,pUnk)
#define IEnumBackgroundCopyGroups_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumBackgroundCopyGroups_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumBackgroundCopyGroups_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumBackgroundCopyGroups_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)
#define IEnumBackgroundCopyGroups_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IEnumBackgroundCopyGroups_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumBackgroundCopyGroups_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)
#define IEnumBackgroundCopyGroups_GetCount(This,puCount)	\
    (This)->lpVtbl -> GetCount(This,puCount)
#define IBackgroundCopyCallback1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyCallback1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyCallback1_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyCallback1_OnStatus(This,pGroup,pJob,dwFileIndex,dwStatus,dwNumOfRetries,dwWin32Result,dwTransportResult)	\
    (This)->lpVtbl -> OnStatus(This,pGroup,pJob,dwFileIndex,dwStatus,dwNumOfRetries,dwWin32Result,dwTransportResult)
#define IBackgroundCopyCallback1_OnProgress(This,ProgressType,pGroup,pJob,dwFileIndex,dwProgressValue)	\
    (This)->lpVtbl -> OnProgress(This,ProgressType,pGroup,pJob,dwFileIndex,dwProgressValue)
#define IBackgroundCopyQMgr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyQMgr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyQMgr_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyQMgr_CreateGroup(This,guidGroupID,ppGroup)	\
    (This)->lpVtbl -> CreateGroup(This,guidGroupID,ppGroup)
#define IBackgroundCopyQMgr_GetGroup(This,groupID,ppGroup)	\
    (This)->lpVtbl -> GetGroup(This,groupID,ppGroup)
#define IBackgroundCopyQMgr_EnumGroups(This,dwFlags,ppEnumGroups)	\
    (This)->lpVtbl -> EnumGroups(This,dwFlags,ppEnumGroups)

// public\internal\com\inc\iface.h
#define IFD_SIZE(pIFD) (sizeof(InterfaceData) + pIFD->ulCntData - 1024)

// public\internal\com\inc\propmac.hxx
#define QuadAlign(n)  (((n) + sizeof(LONGLONG) - 1) & ~(sizeof(LONGLONG) - 1))

// public\internal\drivers\inc\agp.h
    #define IsEqualGUID(guid1, guid2) \
        (!memcmp((guid1), (guid2), sizeof(GUID)))

// public\internal\ds\inc\crypto\aes.h
#define AES_TABLESIZE   (sizeof(AESTable))
#define AES_TABLESIZE_128   (sizeof(AESTable_128))
#define AES_TABLESIZE_192   (sizeof(AESTable_192))
#define AES_TABLESIZE_256   (sizeof(AESTable_256))

// public\internal\ds\inc\crypto\bignum.h
#define mp_copy(src, dest, lng) \
            memcpy((void *)(dest), (const void *)(src), (lng)*sizeof(digit_t))
#define mp_clear(dest, lng) (void)memset((void *)(dest), 0, (lng)*sizeof(digit_t))

// public\internal\ds\inc\crypto\des.h
#define DES_TABLESIZE   (sizeof(DESTable))
#define DESX_TABLESIZE  (sizeof(DESXTable))

// public\internal\ds\inc\crypto\des3.h
#define DES3_TABLESIZE  sizeof(DES3TABLE)

// public\internal\ds\inc\crypto\tripldes.h
#define DES3_TABLESIZE  sizeof(DES3TABLE)

// public\internal\ds\inc\dnslib.h
#define SIZEOF_MSG_BUF_OVERHEAD (sizeof(DNS_MSG_BUF) - sizeof(DNS_HEADER) - 1)

// public\internal\ds\inc\ntfrsipi.h
#define NTFRSAPI_INFO_HEADER_SIZE   (5 * sizeof(ULONG))

// public\internal\ds\inc\passport.h
#define IPassportManager_OnStartPage(This,piUnk)	\
    (This)->lpVtbl -> OnStartPage(This,piUnk)
#define IPassportManager_OnEndPage(This)	\
    (This)->lpVtbl -> OnEndPage(This)
#define IPassportManager_OnStartPageECB(This,pECB,pBufSize,pCookieHeader)	\
    (This)->lpVtbl -> OnStartPageECB(This,pECB,pBufSize,pCookieHeader)
#define IPassportManager_OnStartPageFilter(This,pPFC,pBufSize,pCookieHeader)	\
    (This)->lpVtbl -> OnStartPageFilter(This,pPFC,pBufSize,pCookieHeader)
#define IPassportManager_OnStartPageASP(This,pdispRequest,pdispResponse)	\
    (This)->lpVtbl -> OnStartPageASP(This,pdispRequest,pdispResponse)
#define IPassportManager2_OnStartPage(This,piUnk)	\
    (This)->lpVtbl -> OnStartPage(This,piUnk)
#define IPassportManager2_OnEndPage(This)	\
    (This)->lpVtbl -> OnEndPage(This)
#define IPassportManager2_OnStartPageECB(This,pECB,pBufSize,pCookieHeader)	\
    (This)->lpVtbl -> OnStartPageECB(This,pECB,pBufSize,pCookieHeader)
#define IPassportManager2_OnStartPageFilter(This,pPFC,pBufSize,pCookieHeader)	\
    (This)->lpVtbl -> OnStartPageFilter(This,pPFC,pBufSize,pCookieHeader)
#define IPassportManager2_OnStartPageASP(This,pdispRequest,pdispResponse)	\
    (This)->lpVtbl -> OnStartPageASP(This,pdispRequest,pdispResponse)
#define IPassportManager3_OnStartPage(This,piUnk)	\
    (This)->lpVtbl -> OnStartPage(This,piUnk)
#define IPassportManager3_OnEndPage(This)	\
    (This)->lpVtbl -> OnEndPage(This)
#define IPassportManager3_OnStartPageECB(This,pECB,pBufSize,pCookieHeader)	\
    (This)->lpVtbl -> OnStartPageECB(This,pECB,pBufSize,pCookieHeader)
#define IPassportManager3_OnStartPageFilter(This,pPFC,pBufSize,pCookieHeader)	\
    (This)->lpVtbl -> OnStartPageFilter(This,pPFC,pBufSize,pCookieHeader)
#define IPassportManager3_OnStartPageASP(This,pdispRequest,pdispResponse)	\
    (This)->lpVtbl -> OnStartPageASP(This,pdispRequest,pdispResponse)
#define IPassportCrypt_OnStartPage(This,piUnk)	\
    (This)->lpVtbl -> OnStartPage(This,piUnk)

// public\internal\ds\inc\permit.h
#define UAS_GROUP_HASH_START    ((sizeof(UAS_AHDR) + 511) & ~511)
#define UAS_HASH_TBL_SIZE       (sizeof(UAS_DISKUSERHASH)*UAS_USER_HASH_ENTRIES)
#define UAS_GRECSIZE        sizeof(UAS_GROUPREC)
#define UAS_ACL_RECORD_SIZE(acl,namelen,permcnt) \
                (((sizeof(UAS_ACCESSREC) + namelen \
                    + sizeof (UAS_VPERM) \
                    + sizeof (UAS_PERM) * (permcnt - 1)) + 1) & ~1)

// public\internal\inetcore\inc\dxtransp.h
#define IDXTLabel_GetBackgroundColor(This,pVal)	\
    (This)->lpVtbl -> GetBackgroundColor(This,pVal)
#define IDXTLabel_SetBackgroundColor(This,newVal)	\
    (This)->lpVtbl -> SetBackgroundColor(This,newVal)
#define IDX2D_SetBackgroundBrush(This,pBrush)	\
    (This)->lpVtbl -> SetBackgroundBrush(This,pBrush)
#define IDX2D_GetBackgroundBrush(This,pBrush)	\
    (This)->lpVtbl -> GetBackgroundBrush(This,pBrush)

// public\internal\multimedia\inc\ddrawpr.h
#define VALIDEX_DIRECTDRAWFACTORY2_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDFACTORY2 )) && \
        (ptr->lpVtbl == &ddFactory2Callbacks) )
#define VALIDEX_DIRECTDRAW_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DIRECTDRAW_INT )) && \
        ( (ptr->lpVtbl == &ddCallbacks) || \
          (ptr->lpVtbl == &dd2Callbacks) || \
          (ptr->lpVtbl == &dd4Callbacks) || \
          (ptr->lpVtbl == &dd7Callbacks) || \
          (ptr->lpVtbl == &dd2UninitCallbacks) || \
          (ptr->lpVtbl == &dd4UninitCallbacks) || \
          (ptr->lpVtbl == &dd7UninitCallbacks) || \
          (ptr->lpVtbl == &ddVideoPortContainerCallbacks) || \
          (ptr->lpVtbl == &ddKernelCallbacks) || \
          (ptr->lpVtbl == &ddMotionCompContainerCallbacks) || \
          (ptr->lpVtbl == &ddUninitCallbacks) ) )
#define VALIDEX_DIRECTDRAWSURFACE_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDRAWSURFACE_INT )) && \
        ( (ptr->lpVtbl == &ddSurfaceCallbacks ) || \
          (ptr->lpVtbl == &ddSurface7Callbacks ) || \
          (ptr->lpVtbl == &ddSurface4Callbacks ) || \
          (ptr->lpVtbl == &ddSurface3Callbacks ) || \
          (ptr->lpVtbl == &ddSurface2Callbacks ) || \
          (ptr->lpVtbl == &ddSurfaceKernelCallbacks ) || \
          (ptr->lpVtbl == &ddColorControlCallbacks ) || \
          (ptr->lpVtbl == &ddGammaControlCallbacks ) ) )
#define VALIDEX_DIRECTDRAWPALETTE_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDRAWPALETTE_INT )) && \
        (ptr->lpVtbl == &ddPaletteCallbacks) )
#define VALIDEX_DIRECTDRAWCLIPPER_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDRAWCLIPPER_INT )) && \
        ( (ptr->lpVtbl == &ddClipperCallbacks) || \
          (ptr->lpVtbl == &ddUninitClipperCallbacks) ) )
#define VALIDEX_DDCOLORCONTROL_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDCOLORCONTROL_INT )) && \
        (ptr->lpVtbl == &ddColorControlCallbacks) )
#define VALID_DDVIDEOPORT_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDVIDEOPORT_INT )) && \
        (ptr->lpVtbl == &ddVideoPortCallbacks) )
#define VALID_DDMOTIONCOMP_PTR( ptr ) \
        (!IsBadWritePtr( ptr, sizeof( DDRAWI_DDMOTIONCOMP_INT )) && \
        (ptr->lpVtbl == &ddMotionCompCallbacks) )

// public\internal\net\inc\apiworke.h
#define APIEXTR         (sizeof(REM_APITXT))

// public\internal\net\inc\hnetbcon.h
#define IInternetConnectionDevice_IsICSDeviceAvailable(This,fBlock)	\
    (This)->lpVtbl -> IsICSDeviceAvailable(This,fBlock)
#define IInternetConnectionDevice_GetICSDeviceNameInfo(This,ppszMachineName,ppszDomainName,ppszSharedAdapterName,fBlock)	\
    (This)->lpVtbl -> GetICSDeviceNameInfo(This,ppszMachineName,ppszDomainName,ppszSharedAdapterName,fBlock)
#define IInternetConnectionDevice_GetICSDeviceSystemTime(This,pTime,fBlock)	\
    (This)->lpVtbl -> GetICSDeviceSystemTime(This,pTime,fBlock)
#define IInternetConnectionDevice_GetICSDeviceOSVersion(This,pOSVersion,pdwOSMajorVersion,pdwOSMinorVersion,pdwOSBuildNumber,ppszOSName,ppszPlatformName,fBlock)	\
    (This)->lpVtbl -> GetICSDeviceOSVersion(This,pOSVersion,pdwOSMajorVersion,pdwOSMinorVersion,pdwOSBuildNumber,ppszOSName,ppszPlatformName,fBlock)
#define IInternetConnectionDeviceSharedConnection_GetDialState(This,pDialState,fBlock)	\
    (This)->lpVtbl -> GetDialState(This,pDialState,fBlock)
#define IInternetConnectionDeviceSharedConnection_GetConnectionInfo(This,pBytesSent,pBytesRecv,pPktsSent,pPktsRecv,pUptime,fBlock)	\
    (This)->lpVtbl -> GetConnectionInfo(This,pBytesSent,pBytesRecv,pPktsSent,pPktsRecv,pUptime,fBlock)
#define IInternetConnectionDeviceSharedConnection_GetConnectionSpeed(This,pdwBps,fBlock)	\
    (This)->lpVtbl -> GetConnectionSpeed(This,pdwBps,fBlock)
#define IInternetConnectionDeviceSharedConnection_GetConnectionType(This,pConnectionType,fBlock)	\
    (This)->lpVtbl -> GetConnectionType(This,pConnectionType,fBlock)

// public\internal\net\inc\isnkrnl.h
#define MIPX_SETRIPAGE     (I_MIPX | 127) /* Set RIP age timeout          */

// public\internal\net\inc\nbtioctl.h
#define IOCTL_NETBT_NEW_IPADDRESS    _NETBT_CTRL_CODE( 35, METHOD_BUFFERED, \
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\internal\net\inc\netconp.h
#define INetConnectionWizardUi_QueryMaxPageCount(This,pContext,pcMaxPages)	\
    (This)->lpVtbl -> QueryMaxPageCount(This,pContext,pcMaxPages)
#define INetConnectionWizardUi_AddPages(This,pContext,pfnAddPage,lParam)	\
    (This)->lpVtbl -> AddPages(This,pContext,pfnAddPage,lParam)

// public\internal\net\inc\rap.h
#define RapPossiblyAlignCount(count,pow2,native) \
        ( (!(native)) ? (count) : (ROUND_UP_COUNT( (count), (pow2) )) )

// public\internal\net\inc\rasuip.h
#define RasGuidToSharedConnection( _guid, _pConn ) \
( \
    ZeroMemory((_pConn), sizeof(RASSHARECONN)), \
    (_pConn)->dwSize = sizeof(RASSHARECONN), \
    (_pConn)->fIsLanConnection = TRUE, \
    CopyMemory(&(_pConn)->guid, (_guid), sizeof(GUID)) \
)

// public\internal\shell\inc\pif.h
#define LARGEST_GROUP   sizeof(PROPPRG)

// public\internal\shell\inc\shimgdata.h
#define IShellImageData_NextPage(This)	\
    (This)->lpVtbl -> NextPage(This)
#define IShellImageData_PrevPage(This)	\
    (This)->lpVtbl -> PrevPage(This)
#define IShellImageData_IsMultipage(This)	\
    (This)->lpVtbl -> IsMultipage(This)
#define IShellImageData_GetCurrentPage(This,pnPage)	\
    (This)->lpVtbl -> GetCurrentPage(This,pnPage)
#define IShellImageData_GetPageCount(This,pcPages)	\
    (This)->lpVtbl -> GetPageCount(This,pcPages)
#define IShellImageData_SelectPage(This,iPage)	\
    (This)->lpVtbl -> SelectPage(This,iPage)

// public\internal\shell\inc\shpriv.h
#define IThemeUIPages_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IThemeUIPages_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IThemeUIPages_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IThemeUIPages_AddPage(This,pfnAddPage,lParam,nPageID)	\
    (This)->lpVtbl -> AddPage(This,pfnAddPage,lParam,nPageID)
#define IThemeUIPages_AddBasePage(This,pBasePage)	\
    (This)->lpVtbl -> AddBasePage(This,pBasePage)
#define IThemeUIPages_ApplyPressed(This,dwFlags)	\
    (This)->lpVtbl -> ApplyPressed(This,dwFlags)
#define IThemeUIPages_GetBasePagesEnum(This,ppEnumUnknown)	\
    (This)->lpVtbl -> GetBasePagesEnum(This,ppEnumUnknown)
#define IThemeUIPages_UpdatePreview(This,dwFlags)	\
    (This)->lpVtbl -> UpdatePreview(This,dwFlags)
#define IThemeUIPages_AddFakeSettingsPage(This,pVoid)	\
    (This)->lpVtbl -> AddFakeSettingsPage(This,pVoid)
#define IThemeUIPages_SetExecMode(This,dwEM)	\
    (This)->lpVtbl -> SetExecMode(This,dwEM)
#define IThemeUIPages_GetExecMode(This,pdwEM)	\
    (This)->lpVtbl -> GetExecMode(This,pdwEM)
#define IThemeUIPages_LoadMonitorBitmap(This,fFillDesktop,phbmMon)	\
    (This)->lpVtbl -> LoadMonitorBitmap(This,fFillDesktop,phbmMon)
#define IThemeUIPages_DisplaySaveSettings(This,pContext,hwnd,piRet)	\
    (This)->lpVtbl -> DisplaySaveSettings(This,pContext,hwnd,piRet)
#define IAdvancedDialog_DisplayAdvancedDialog(This,hwndParent,pBasePage,pfEnableApply)	\
    (This)->lpVtbl -> DisplayAdvancedDialog(This,hwndParent,pBasePage,pfEnableApply)
#define IBasePropPage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBasePropPage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBasePropPage_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBasePropPage_AddPages(This,pfnAddPage,lParam)	\
    (This)->lpVtbl -> AddPages(This,pfnAddPage,lParam)
#define IBasePropPage_ReplacePage(This,uPageID,pfnReplaceWith,lParam)	\
    (This)->lpVtbl -> ReplacePage(This,uPageID,pfnReplaceWith,lParam)
#define IBasePropPage_GetAdvancedDialog(This,ppAdvDialog)	\
    (This)->lpVtbl -> GetAdvancedDialog(This,ppAdvDialog)
#define IBasePropPage_OnApply(This,oaAction)	\
    (This)->lpVtbl -> OnApply(This,oaAction)
#define SZ_PBPROP_BACKGROUND_COLOR           TEXT("BackgroundColor")                       // VT_UI4. Get or set the COLORREF (RGB) color for the background system metric.
#define IMagic_Illusion(This,hmod,uId,cFrames,interval,align,rc)	\
    (This)->lpVtbl -> Illusion(This,hmod,uId,cFrames,interval,align,rc)

// public\internal\termsrv\inc\icadd.h
#define DEFAULT_MOUSE_THROTTLE_SIZE (200 * sizeof(MOUSE_INPUT_DATA))
#define DEFAULT_KEYBOARD_THROTTLE_SIZE (200 * sizeof(KEYBOARD_INPUT_DATA))

// public\internal\windows\inc\aimm12.h
#define IActiveIMMApp_GetCodePageA(This,hKL,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage)

// public\internal\windows\inc\aimmex.h
#define IActiveIMMAppEx_GetCodePageA(This,hKL,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage)

// public\internal\windows\inc\duser\duierror.h
#define StartBlockTimer()  __int64 _dFreq, _dStart, _dStop; \
                           QueryPerformanceFrequency((LARGE_INTEGER*)&_dFreq); \
                           QueryPerformanceCounter((LARGE_INTEGER*)&_dStart)
#define StopBlockTimer()   QueryPerformanceCounter((LARGE_INTEGER*)&_dStop)

// public\internal\windows\inc\immp.h
#define IMMGWL_PRIVATE                  (sizeof(LONG))

// public\internal\windows\inc\msctfp.h
#define ITfKeystrokeMgr_P_AdviseKeyEventSink(This,tid,pSink,fForeground)	\
    (This)->lpVtbl -> AdviseKeyEventSink(This,tid,pSink,fForeground)
#define ITfKeystrokeMgr_P_GetForeground(This,pclsid)	\
    (This)->lpVtbl -> GetForeground(This,pclsid)
#define ITfBackgroundThreadMgr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITfBackgroundThreadMgr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITfBackgroundThreadMgr_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITfBackgroundThreadMgr_AppInitBackgroundThread(This,pfnWakeThread,ppfnCallback,ppvPrivate)	\
    (This)->lpVtbl -> AppInitBackgroundThread(This,pfnWakeThread,ppfnCallback,ppvPrivate)
#define ITfBackgroundThreadMgr_AppUninitBackgroundThread(This)	\
    (This)->lpVtbl -> AppUninitBackgroundThread(This)
#define ITfBackgroundThreadMgr_AdviseBackgroundCallback(This,pfnCallback,pvPrivate,pdwCookie)	\
    (This)->lpVtbl -> AdviseBackgroundCallback(This,pfnCallback,pvPrivate,pdwCookie)
#define ITfBackgroundThreadMgr_UnadviseBackgroundCallback(This,dwCookie)	\
    (This)->lpVtbl -> UnadviseBackgroundCallback(This,dwCookie)
#define ITfBackgroundThreadMgr_WakeBackgroundThread(This)	\
    (This)->lpVtbl -> WakeBackgroundThread(This)

// public\internal\windows\inc\ntgdistr.h
#define ALIGN4(X) (((X) + 3) & ~3)
#define ALIGN8(X) (((X) + 7) & ~7)

// public\internal\windows\inc\stdexts.h
#define move(dst, src)  moveBlock(&(dst), src, sizeof(dst))
#define tryMove(dst, src)  tryMoveBlock(&(dst), src, sizeof(dst))

// public\internal\windows\inc\winfont.h
#define ALIGN4(X) (((X) + 3) & ~3)

// public\oak\inc\d3dnthal.h
#define D3DNTHAL_DEFAULT_TL_NUM ((32 * 1024) / sizeof (D3DTLVERTEX))
#define D3DNTHAL_DEFAULT_H_NUM  ((32 * 1024) / sizeof (D3DHVERTEX))
#define D3DNTHALDEVICEDESCSIZE_V1 (sizeof(D3DNTHALDEVICEDESC_V1))
#define D3DNTHALDEVICEDESCSIZE_V2 (sizeof(D3DNTHALDEVICEDESC_V2))
#define D3DNTDEVICEDESCSIZE_V3 (sizeof(D3DNTDEVICEDESC_V3))
#define D3DNTHAL_GLOBALDRIVERDATASIZE (sizeof(D3DNTHAL_GLOBALDRIVERDATA))
#define D3DNTHAL_D3DEXTENDEDCAPSSIZE (sizeof(D3DNTHAL_D3DEXTENDEDCAPS))
#define D3DNTHAL_D3DDX6EXTENDEDCAPSSIZE (sizeof(D3DNTHAL_D3DDX6EXTENDEDCAPS))
#define D3DNTHAL_SIZE_V1 sizeof( D3DNTHAL_CALLBACKS )

// public\oak\inc\ddrawi.h
#define VALID_ALIGNMENT( align ) (!((align == 0) || (align % 2) != 0 ))
#define DDCALLBACKSSIZE    sizeof( DDHAL_DDCALLBACKS )
#define DDSURFACECALLBACKSSIZE sizeof( DDHAL_DDSURFACECALLBACKS )
#define DDMISCELLANEOUSCALLBACKSSIZE sizeof(DDHAL_DDMISCELLANEOUSCALLBACKS)
#define DDNTCALLBACKSSIZE sizeof(DDHAL_DDNTCALLBACKS)
#define DDVPE2CALLBACKSSIZE sizeof(DDHAL_DDVPE2CALLBACKS)
#define DDMISCELLANEOUS2CALLBACKSSIZE sizeof(DDHAL_DDMISCELLANEOUS2CALLBACKS)
#define DDEXEBUFCALLBACKSSIZE sizeof( DDHAL_DDEXEBUFCALLBACKS )
#define DDVIDEOPORTCALLBACKSSIZE sizeof( DDHAL_DDVIDEOPORTCALLBACKS )
#define DDKERNELCALLBACKSSIZE sizeof(DDHAL_DDKERNELCALLBACKS)
#define DDMOTIONCOMPCALLBACKSSIZE sizeof( DDHAL_DDMOTIONCOMPCALLBACKS )
#define DDHAL_DDUMODEDRVINFOSIZE    sizeof( DDHAL_DDUMODEDRVINFO )
#define DDHAL_DDUMODEDRVPASSWDSIZE    sizeof( DDHAL_DDUMODEDRVPASSWD )
#define DDOPTSURFACEKMODEINFOSIZE   sizeof( DDHAL_DDOPTSURFACEKMODEINFO )
#define DDOPTSURFACEUMODEINFOSIZE    sizeof( DDHAL_DDOPTSURFACEUMODEINFO )
#define EQUAL_DISPLAYMODE(a, b) (0 == memcmp(&(a), &(b), sizeof (DISPLAYMODEINFO)))
#define DDHALINFOSIZE_V1 sizeof( DDHALINFO_V1)
#define DDHALINFOSIZE_V2 sizeof( DDHALINFO )
#define DDHAL_ALIGNVALIDCAPS   (DDSCAPS_OFFSCREENPLAIN | \
                                DDSCAPS_EXECUTEBUFFER | \
                                DDSCAPS_OVERLAY | \
                                DDSCAPS_TEXTURE | \
                                DDSCAPS_ZBUFFER | \
                                DDSCAPS_ALPHA | \
                                DDSCAPS_FLIP )

// public\oak\inc\dx95type.h
#define D3DHAL_DEFAULT_TL_NUM   ((32 * 1024) / sizeof (D3DTLVERTEX))
#define D3DHAL_DEFAULT_H_NUM    ((32 * 1024) / sizeof (D3DHVERTEX))
#define D3DDEVICEDESCSIZE_V1 (sizeof(D3DDEVICEDESC_V1))
#define D3DHAL_GLOBALDRIVERDATASIZE (sizeof(D3DHAL_GLOBALDRIVERDATA))
#define D3DHAL_D3DEXTENDEDCAPSSIZE (sizeof(D3DHAL_D3DEXTENDEDCAPS))

// public\oak\inc\immdev.h
#define IMMGWL_PRIVATE                  (sizeof(LONG))

// public\oak\inc\mcdrv.h
#define MCDDRIVER_V10_SIZE      (sizeof(ULONG)+31*sizeof(void *))

// public\oak\inc\minidrv.h
#define IS_DBCSCODEPAGE(j) \
    (((j) == 932)   || \
    ((j) == 936)   || \
    ((j) == 949)   || \
    ((j) == 950)   || \
    ((j) == 1361))

// public\oak\inc\winddi.h
    #define IsEqualGUID(guid1, guid2) \
        (!memcmp((guid1), (guid2), sizeof(GUID)))

// public\sdk\amovie\inc\amvideo.h
#define SIZE_EGA_PALETTE (iEGA_COLORS * sizeof(RGBQUAD))
#define SIZE_PALETTE (iPALETTE_COLORS * sizeof(RGBQUAD))
#define SIZE_MASKS (iMASK_COLORS * sizeof(DWORD))
#define SIZE_VIDEOHEADER (sizeof(BITMAPINFOHEADER) + SIZE_PREHEADER)
#define RESET_HEADER(pbmi) (ZeroMemory((PVOID)(pbmi), SIZE_PREHEADER +	    \
			sizeof(BITMAPINFOHEADER)))

// public\sdk\amovie\inc\aviriff.h
  #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))
#define RIFFROUND(cb) ((cb) + ((cb)&1))
#define RIFFNEXT(pChunk) (LPRIFFCHUNK)((LPBYTE)(pChunk) \
                          + sizeof(RIFFCHUNK) \
                          + RIFFROUND(((LPRIFFCHUNK)pChunk)->cb))

// public\sdk\amovie\inc\bdamedia.h
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
#define DEFINE_KSMETHOD_ITEM_BDA_DELETE_PIN_FACTORY(MethodHandler, SupportHandler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_BDA_DELETE_PIN_FACTORY,\
        KSMETHOD_TYPE_NONE,\
        (MethodHandler),\
        sizeof(KSM_BDA_PIN),\
        0,\
        SupportHandler)
#define DEFINE_KSMETHOD_ITEM_BDA_CREATE_TOPOLOGY(MethodHandler, SupportHandler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_BDA_CREATE_TOPOLOGY,\
        KSMETHOD_TYPE_WRITE,\
        (MethodHandler),\
        sizeof(KSM_BDA_PIN_PAIR),\
        0,\
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
#define DEFINE_KSPROPERTY_ITEM_BDA_ECM_MAP_STATUS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_ECM_MAP_STATUS,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_CA_MODULE_STATUS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_CA_MODULE_STATUS,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_BDA_CA_SMART_CARD_STATUS(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_CA_SMART_CARD_STATUS,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
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
#define DEFINE_KSEVENT_BDA_PROGRAM_FLOW_STATUS_CHANGED(AddHandler, RemoveHandler, SupportHandler)\
    DEFINE_KSEVENT_ITEM(\
        KSEVENT_BDA_PROGRAM_FLOW_STATUS_CHANGED,\
        sizeof( KSEVENTDATA), \
        0, \
        (AddHandler),\
        (RemoveHandler),\
        (SupportHandler)\
        )
#define DEFINE_KSEVENT_BDA_CA_MODULE_STATUS_CHANGED(AddHandler, RemoveHandler, SupportHandler)\
    DEFINE_KSEVENT_ITEM(\
        KSEVENT_BDA_CA_MODULE_STATUS_CHANGED,\
        sizeof( KSEVENTDATA), \
        0, \
        (AddHandler),\
        (RemoveHandler),\
        (SupportHandler)\
        )
#define DEFINE_KSEVENT_BDA_CA_SMART_CARD_STATUS_CHANGED(AddHandler, RemoveHandler, SupportHandler)\
    DEFINE_KSEVENT_ITEM(\
        KSEVENT_BDA_CA_SMART_CARD_STATUS_CHANGED,\
        sizeof( KSEVENTDATA), \
        0, \
        (AddHandler),\
        (RemoveHandler),\
        (SupportHandler)\
        )
#define DEFINE_KSEVENT_BDA_CA_MODULE_UI_REQUESTED(AddHandler, RemoveHandler, SupportHandler)\
    DEFINE_KSEVENT_ITEM(\
        KSEVENT_BDA_CA_MODULE_UI_REQUESTED,\
        sizeof( KSEVENTDATA), \
        0, \
        (AddHandler),\
        (RemoveHandler),\
        (SupportHandler)\
        )

// public\sdk\amovie\inc\dxmperf.h
#define PERFLOG_GETTIME( clock, time )    /*{ \
    PERFINFO_WMI_GETTIME    perfData; \
    if (NULL != g_pTraceEvent) { \
        memset( &perfData, 0, sizeof( perfData ) ); \
        perfData.header.Size  = sizeof( perfData ); \
        perfData.header.Flags = WNODE_FLAG_TRACED_GUID; \
        perfData.header.Guid  = GUID_GETTIME; \
        perfData.data.cycleCounter = _RDTSC(); \
        perfData.data.dshowClock   = (ULONGLONG) (time); \
        if (g_perfMasks[GETTIME_INDEX] & GETTIME_BIT) \
            (*g_pTraceEvent)( g_traceHandle, (PEVENT_TRACE_HEADER) &perfData ); \
        } \
    }*/
#define PERFLOG_AUDIOREND( clocktime, sampletime, psample, bytetime, cbytes ) /*{ \
    PERFINFO_WMI_AVREND    perfData; \
    if (NULL != g_pTraceEvent) { \
        memset( &perfData, 0, sizeof( perfData ) ); \
        perfData.header.Size  = sizeof( perfData ); \
        perfData.header.Flags = WNODE_FLAG_TRACED_GUID; \
        perfData.header.Guid  = GUID_AUDIOREND; \
        perfData.data.cycleCounter = _RDTSC(); \
        perfData.data.dshowClock   = (clocktime); \
        perfData.data.sampleTime   = (sampletime); \
        if (g_perfMasks[AUDIOREND_INDEX] & AUDIOREND_BIT) \
            (*g_pTraceEvent)( g_traceHandle, (PEVENT_TRACE_HEADER) &perfData ); \
        } \
    }*/
#define PERFLOG_VIDEOREND( sampletime, clocktime, psample ) \
    if (PerflogEnableFlags & DXMPERF_VIDEOREND) { \
        PERFINFO_WMI_AVREND perfData; \
        memset( &perfData, 0, sizeof( perfData ) ); \
        perfData.header.Size = sizeof( perfData ); \
        perfData.header.Flags = WNODE_FLAG_TRACED_GUID; \
        perfData.header.Guid = GUID_VIDEOREND; \
        perfData.data.cycleCounter = _RDTSC(); \
        perfData.data.dshowClock = (clocktime); \
        perfData.data.sampleTime = (sampletime); \
        PerflogTraceEvent ((PEVENT_TRACE_HEADER) &perfData); \
    }
#define PERFLOG_AUDIOGLITCH( instance, glitchtype, currenttime, previoustime ) \
    if (PerflogEnableFlags & DXMPERF_AUDIOGLITCH) { \
        PERFINFO_WMI_AUDIOGLITCH perfData; \
        memset( &perfData, 0, sizeof( perfData ) ); \
        perfData.header.Size = sizeof( perfData ); \
        perfData.header.Flags = WNODE_FLAG_TRACED_GUID; \
        perfData.header.Guid = GUID_DSOUNDGLITCH; \
        perfData.data.cycleCounter = _RDTSC(); \
        perfData.data.glitchType = (glitchtype); \
        perfData.data.sampleTime = (currenttime); \
        perfData.data.previousTime = (previoustime); \
        perfData.data.instanceId = (instance); \
        PerflogTraceEvent ((PEVENT_TRACE_HEADER) &perfData); \
    }
#define PERFLOG_FRAMEDROP( sampletime, clocktime, psample, renderer )    /*{ \
    PERFINFO_WMI_FRAMEDROP    perfData; \
    if (NULL != g_pTraceEvent) { \
        memset( &perfData, 0, sizeof( perfData ) ); \
        perfData.header.Size  = sizeof( perfData ); \
        perfData.header.Flags = WNODE_FLAG_TRACED_GUID; \
        perfData.header.Guid  = GUID_FRAMEDROP; \
        perfData.data.cycleCounter = _RDTSC(); \
        perfData.data.dshowClock   = (clocktime); \
        perfData.data.frameTime    = (sampletime); \
        if (g_perfMasks[FRAMEDROP_INDEX] & FRAMEDROP_BIT) \
            (*g_pTraceEvent)( g_traceHandle, (PEVENT_TRACE_HEADER) &perfData ); \
        } \
    }*/
#define PERFLOG_AUDIOBREAK( nextwrite, writepos, msecs )    { \
    PERFINFO_WMI_AUDIOBREAK    perfData; \
    if (NULL != g_pTraceEvent) { \
        memset( &perfData, 0, sizeof( perfData ) ); \
        perfData.header.Size  = sizeof( perfData ); \
        perfData.header.Flags = WNODE_FLAG_TRACED_GUID; \
        perfData.header.Guid  = GUID_AUDIOBREAK; \
        perfData.data.cycleCounter   = _RDTSC(); \
        perfData.data.dshowClock     = (writepos); \
        perfData.data.sampleTime     = (nextwrite); \
        perfData.data.sampleDuration = (msecs); \
        if (g_perfMasks[AUDIOBREAK_INDEX] & AUDIOBREAK_BIT) \
            (*g_pTraceEvent)( g_traceHandle, (PEVENT_TRACE_HEADER) &perfData ); \
        } \
    }
#define PERFLOG_AUDIOBREAK( nextwrite, writepos, msecs )  \
    if (PerflogEnableFlags & AUDIOBREAK_BIT) { \
        PERFINFO_WMI_AUDIOBREAK    perfData; \
        memset( &perfData, 0, sizeof( perfData ) ); \
        perfData.header.Size  = sizeof( perfData ); \
        perfData.header.Flags = WNODE_FLAG_TRACED_GUID; \
        perfData.header.Guid  = GUID_AUDIOBREAK; \
        perfData.data.cycleCounter   = _RDTSC(); \
        perfData.data.dshowClock     = (writepos); \
        perfData.data.sampleTime     = (nextwrite); \
        perfData.data.sampleDuration = (msecs); \
        PerflogTraceEvent ((PEVENT_TRACE_HEADER) &perfData); \
    } \

// public\sdk\amovie\inc\dxva.h
#define writeDXVA_DeblockingEdgeControl(ptr, str, fon) ((*(ptr)) = ((str) << 1) | (fon))
#define readDXVA_IntraMacroblock(ptr)    (((ptr)->wMBtype & 0x0001))
#define setDXVA_IntraMacroblock(ptr)     ((ptr)->wMBtype |= 0x0001)

// public\sdk\amovie\inc\playlist.h
#define ISpecifyParticularPages_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISpecifyParticularPages_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISpecifyParticularPages_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISpecifyParticularPages_GetPages(This,guidWhatPages,pPages)	\
    (This)->lpVtbl -> GetPages(This,guidWhatPages,pPages)

// public\sdk\amovie\inc\streams.h
   #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))
  #define DWLP_DLGPROC    DWLP_MSGRESULT + sizeof(LRESULT)
  #define DWLP_USER       DWLP_DLGPROC + sizeof(DLGPROC)

// public\sdk\amovie\inc\wxdebug.h
    #define DbgAssertAligned( _ptr_, _alignment_ ) ASSERT( ((DWORD_PTR) (_ptr_)) % (_alignment_) == 0)

// public\sdk\inc\1394wmi.h
    #define BUS1394_WMI_DDI_VERSION_SIZE sizeof(ULONG)
    #define BUS1394_WMI_MAX_PHY_SPEED_SUPPORTED_SIZE sizeof(ULONG)
    #define BUS1394_WMI_CONTROLLER_EUI_64_SIZE sizeof(ULONGLONG)
    #define BUS1394_WMI_CONFIG_ROM_SIZE_SIZE sizeof(ULONG)
    #define BUS1394_WMI_CONFIG_ROM_SIZE sizeof(UCHAR[1024])
    #define BUS1394_WMI_STD_DATA_Reserved1_SIZE sizeof(BOOLEAN)
    #define BUS1394_WMI_GENERATION_COUNT_SIZE sizeof(ULONG)
    #define BUS1394_WMI_LOCAL_HOST_SELF_ID_SIZE sizeof(ULONG[4])
    #define BUS1394_WMI_TOPOLOGY_MAP_SIZE sizeof(ULONG[256])
    #define BUS1394_WMI_TREE_TOPOLOGY_MAP_SIZE sizeof(ULONG[64])
    #define BUS1394_WMI_BUS_DATA_Reserved1_SIZE sizeof(BOOLEAN)
    #define BUS1394_WMI_ERROR_DATA_GENERATION_COUNT_SIZE sizeof(ULONG)
    #define BUS1394_WMI_NUMBER_OF_UNPOWERED_DEVICES_SIZE sizeof(ULONG)
    #define BUS1394_WMI_SELF_ID_PACKETS_OF_UNPOWERED_DEVICES_SIZE sizeof(ULONG[63])
    #define BUS1394_WMI_NUMBER_OF_NONENUMERATED_DEVICES_SIZE sizeof(ULONG)
    #define BUS1394_WMI_SELF_ID_PACKETS_OF_NON_ENUMERATED_DEVICES_SIZE sizeof(ULONG[63])
    #define BUS1394_WMI_ERROR_DATA_Reserved1_SIZE sizeof(BOOLEAN)
    #define BUS1394_WMI_ENUM_CONTROL_FLAGS_SIZE sizeof(ULONG)
    #define BUS1394_WMI_ENUM_CONTROL_EXCLUSION_ELEMENT_TYPE_SIZE sizeof(ULONG[63])
    #define BUS1394_WMI_DEVICE_ENUMERATION_CONTROL_DATA_ExclusionElementFlags_SIZE sizeof(ULONG[63])
    #define BUS1394_WMI_DEVICE_ENUMERATION_CONTROL_DATA_ExclusionElementList_SIZE sizeof(ULONGLONG[63])
    #define BUS1394_WMI_DEVICE_ENUMERATION_CONTROL_DATA_Reserved1_SIZE sizeof(BOOLEAN)
    #define DEVICE1394_WMI_NOTIFICATION_BUS_GENERATION_SIZE sizeof(ULONG)
    #define BUS1394_WMI_NOTIFICATION_TYPE_SIZE sizeof(ULONG)
    #define PORT1394_WMI_LINK_SPEED_SIZE sizeof(ULONG)
    #define PORT1394_WMI_PHY_SPEED_SIZE sizeof(ULONG)
    #define PORT1394_WMI_NUMBER_OF_PORTS_SIZE sizeof(ULONG)
    #define PORT1394_WMI_MAX_ASYNC_WRITE_PACKET_SIZE sizeof(ULONG)
    #define PORT1394_WMI_MAX_ASYNC_READ_PACKET_SIZE sizeof(ULONG)
    #define PORT1394_WMI_NUMBER_OF_ISOCH_TX_DMA_CONTEXTS_SIZE sizeof(ULONG)
    #define PORT1394_WMI_NUMBER_OF_ISOCH_RX_DMA_CONTEXTS_SIZE sizeof(ULONG)
    #define PORT1394_WMI_NUMBER_OF_RESPONSE_WORKERS_SIZE sizeof(ULONG)
    #define PORT1394_WMI_NUMBER_OF_TRANSMIT_WORKERS_SIZE sizeof(ULONG)
    #define PORT1394_WMI_RECEIVE_BUFFER_SIZE_SIZE sizeof(ULONG)
    #define PORT1394_WMI_RESPONSE_BUFFER_SIZE_SIZE sizeof(ULONG)
    #define PORT1394_WMI_POWER_DECIWATTS_SUPPLIED_SIZE sizeof(ULONG)
    #define PORT1394_WMI_POWER_DECIVOLTS_SUPPLIED_SIZE sizeof(ULONG)
    #define PORT1394_WMI_CONTROLLER_CAPABILITIES_SIZE sizeof(ULONG)
    #define PORT1394_WMI_EUI_64_SIZE sizeof(ULONGLONG)
    #define PORT1394_WMI_STD_DATA_Reserved1_SIZE sizeof(BOOLEAN)
    #define PORT1394_ERROR_FLAGS_SIZE sizeof(ULONG)
    #define PORT1394_WMI_ERROR_DATA_Reserved1_SIZE sizeof(BOOLEAN)
    #define PORT1394_WMI_NUMBER_OF_VENDOR_REGISTERS_SIZE sizeof(ULONG)
    #define PORT1394_WMI_VENDOR_REGISTER_SIZE_SIZE sizeof(ULONG[10])
    #define PORT1394_WMI_VENDOR_REGISTER_OPERATION_SIZE sizeof(ULONG[10])
    #define PORT1394_WMI_VENDOR_REGISTER_BASE_SIZE sizeof(ULONG[10])
    #define PORT1394_WMI_VENDOR_REGISTER_DATA_SIZE sizeof(ULONGLONG[10])
    #define PORT1394_WMI_VENDOR_REGISTER_ACCESS_Reserved1_SIZE sizeof(BOOLEAN)
    #define AccessVendorSpace_IN_RegisterData_SIZE sizeof(PORT1394_WMI_VENDOR_REGISTER_ACCESS)
    #define AccessVendorSpace_OUT_RegisterData_SIZE sizeof(PORT1394_WMI_VENDOR_REGISTER_ACCESS)
    #define DEVICE1394_WMI_CURRENT_GENERATION_SIZE sizeof(ULONG)
    #define DEVICE1394_WMI_TYPE_SIZE sizeof(ULONG)
    #define DEVICE1394_WMI_PHY_SPEED_SIZE sizeof(ULONG)
    #define DEVICE1394_WMI_NODE_ADDRESS_SIZE sizeof(USHORT)
    #define DEVICE1394_WMI_POWERCLASS_SIZE sizeof(ULONG)
    #define DEVICE1394_WMI_PHYSICAL_DELAY_SIZE sizeof(ULONG)
    #define DEVICE1394_WMI_SELF_ID_PACKET_SIZE sizeof(ULONG[4])
    #define DEVICE1394_WMI_EUI_64_SIZE sizeof(ULONGLONG)
    #define DEVICE1394_WMI_CONFIG_ROM_SIZE sizeof(ULONG[32])
    #define DEVICE1394_WMI_UNIT_DIRECTORY_SIZE sizeof(ULONG[32])
    #define DEVICE1394_WMI_STD_DATA_Reserved1_SIZE sizeof(BOOLEAN)
    #define DEVICE1394_WMI_ACCESS_VERSION_SIZE sizeof(ULONG)
    #define DEVICE1394_WMI_ACCESS_FLAGS_SIZE sizeof(ULONG)
    #define DEVICE1394_WMI_ACCESS_NOTIFICATION_FLAGS_SIZE sizeof(ULONG)
    #define DEVICE1394_WMI_ACCESS_REMOTE_OWNER_EUI64_SIZE sizeof(ULONGLONG)
    #define DEVICE1394_WMI_ACCESS_DATA_Reserved1_SIZE sizeof(BOOLEAN)
    #define DEVICE1394_WMI_ACCESS_NOTIFY_VERSION_SIZE sizeof(ULONG)
    #define DEVICE1394_WMI_ACCESS_NOTIFY_GENERATION_SIZE sizeof(ULONG)
    #define DEVICE1394_WMI_ACCESS_NOTIFY_TYPE_SIZE sizeof(ULONG)
    #define DEVICE1394_WMI_ACCESS_NOTIFY_FLAGS_SIZE sizeof(ULONGLONG)
    #define DEVICE1394_WMI_ACCESS_NOTIFY_REMOTE_OWNER_EUI64_SIZE sizeof(ULONGLONG)
    #define DEVICE1394_WMI_ACCESS_NOTIFICATION_Reserved1_SIZE sizeof(BOOLEAN)

// public\sdk\inc\activdbg.h
#define IDebugDocumentHelper32_DefineScriptBlock(This,ulCharOffset,cChars,pas,fScriptlet,pdwSourceContext)	\
    (This)->lpVtbl -> DefineScriptBlock(This,ulCharOffset,cChars,pas,fScriptlet,pdwSourceContext)
#define IDebugDocumentHelper32_GetScriptBlockInfo(This,dwSourceContext,ppasd,piCharPos,pcChars)	\
    (This)->lpVtbl -> GetScriptBlockInfo(This,dwSourceContext,ppasd,piCharPos,pcChars)
#define IDebugDocumentHelper64_DefineScriptBlock(This,ulCharOffset,cChars,pas,fScriptlet,pdwSourceContext)	\
    (This)->lpVtbl -> DefineScriptBlock(This,ulCharOffset,cChars,pas,fScriptlet,pdwSourceContext)
#define IDebugDocumentHelper64_GetScriptBlockInfo(This,dwSourceContext,ppasd,piCharPos,pcChars)	\
    (This)->lpVtbl -> GetScriptBlockInfo(This,dwSourceContext,ppasd,piCharPos,pcChars)

// public\sdk\inc\adoint.h
#define Recordset15_get_AbsolutePage(This,pl)	\
    (This)->lpVtbl -> get_AbsolutePage(This,pl)
#define Recordset15_put_AbsolutePage(This,Page)	\
    (This)->lpVtbl -> put_AbsolutePage(This,Page)
#define Recordset15_get_PageCount(This,pl)	\
    (This)->lpVtbl -> get_PageCount(This,pl)
#define Recordset15_get_PageSize(This,pl)	\
    (This)->lpVtbl -> get_PageSize(This,pl)
#define Recordset15_put_PageSize(This,PageSize)	\
    (This)->lpVtbl -> put_PageSize(This,PageSize)
#define Recordset20_get_AbsolutePage(This,pl)	\
    (This)->lpVtbl -> get_AbsolutePage(This,pl)
#define Recordset20_put_AbsolutePage(This,Page)	\
    (This)->lpVtbl -> put_AbsolutePage(This,Page)
#define Recordset20_get_PageCount(This,pl)	\
    (This)->lpVtbl -> get_PageCount(This,pl)
#define Recordset20_get_PageSize(This,pl)	\
    (This)->lpVtbl -> get_PageSize(This,pl)
#define Recordset20_put_PageSize(This,PageSize)	\
    (This)->lpVtbl -> put_PageSize(This,PageSize)
#define Recordset21_get_AbsolutePage(This,pl)	\
    (This)->lpVtbl -> get_AbsolutePage(This,pl)
#define Recordset21_put_AbsolutePage(This,Page)	\
    (This)->lpVtbl -> put_AbsolutePage(This,Page)
#define Recordset21_get_PageCount(This,pl)	\
    (This)->lpVtbl -> get_PageCount(This,pl)
#define Recordset21_get_PageSize(This,pl)	\
    (This)->lpVtbl -> get_PageSize(This,pl)
#define Recordset21_put_PageSize(This,PageSize)	\
    (This)->lpVtbl -> put_PageSize(This,PageSize)
#define _Recordset_get_AbsolutePage(This,pl)	\
    (This)->lpVtbl -> get_AbsolutePage(This,pl)
#define _Recordset_put_AbsolutePage(This,Page)	\
    (This)->lpVtbl -> put_AbsolutePage(This,Page)
#define _Recordset_get_PageCount(This,pl)	\
    (This)->lpVtbl -> get_PageCount(This,pl)
#define _Recordset_get_PageSize(This,pl)	\
    (This)->lpVtbl -> get_PageSize(This,pl)
#define _Recordset_put_PageSize(This,PageSize)	\
    (This)->lpVtbl -> put_PageSize(This,PageSize)

// public\sdk\inc\align.h
#define COUNT_IS_ALIGNED(Count,Pow2) \
        ( ( ( (Count) & (((Pow2)-1)) ) == 0) ? TRUE : FALSE )
#define POINTER_IS_ALIGNED(Ptr,Pow2) \
        ( ( ( ((ULONG_PTR)(Ptr)) & (((Pow2)-1)) ) == 0) ? TRUE : FALSE )
#define ROUND_DOWN_COUNT(Count,Pow2) \
        ( (Count) & (~(((LONG)(Pow2))-1)) )
#define ROUND_DOWN_POINTER(Ptr,Pow2) \
        ( (LPVOID) ROUND_DOWN_COUNT( ((ULONG_PTR)(Ptr)), (Pow2) ) )
#define ROUND_UP_COUNT(Count,Pow2) \
        ( ((Count)+(Pow2)-1) & (~(((LONG)(Pow2))-1)) )
#define ROUND_UP_POINTER(Ptr,Pow2) \
        ( (LPVOID) ( (((ULONG_PTR)(Ptr))+(Pow2)-1) & (~(((LONG)(Pow2))-1)) ) )
#define ALIGN_BYTE              sizeof(UCHAR)
#define ALIGN_CHAR              sizeof(CHAR)
#define ALIGN_DESC_CHAR         sizeof(DESC_CHAR)
#define ALIGN_DWORD             sizeof(DWORD)
#define ALIGN_LONG              sizeof(LONG)
#define ALIGN_LPBYTE            sizeof(LPBYTE)
#define ALIGN_LPDWORD           sizeof(LPDWORD)
#define ALIGN_LPSTR             sizeof(LPSTR)
#define ALIGN_LPTSTR            sizeof(LPTSTR)
#define ALIGN_LPVOID            sizeof(LPVOID)
#define ALIGN_LPWORD            sizeof(LPWORD)
#define ALIGN_TCHAR             sizeof(TCHAR)
#define ALIGN_WCHAR             sizeof(WCHAR)
#define ALIGN_WORD              sizeof(WORD)

// public\sdk\inc\atl21\atlcom.h
#define END_CONNECTION_POINT_MAP() {(DWORD_PTR)-1} }; \
	if (pnEntries) *pnEntries = sizeof(_entries)/sizeof(_ATL_CONNMAP_ENTRY) - 1; \
	return _entries;}

// public\sdk\inc\atl21\atlconv.h
#define DEVMODEW2A(lpw)\
	((lpw == NULL) ? NULL : ATLDEVMODEW2A((LPDEVMODEA)alloca(sizeof(DEVMODEA)+lpw->dmDriverExtra), lpw))
#define DEVMODEA2W(lpa)\
	((lpa == NULL) ? NULL : ATLDEVMODEA2W((LPDEVMODEW)alloca(sizeof(DEVMODEW)+lpa->dmDriverExtra), lpa))
#define TEXTMETRICW2A(lptmw)\
	((lptmw == NULL) ? NULL : ATLTEXTMETRICW2A((LPTEXTMETRICA)alloca(sizeof(TEXTMETRICA)), lptmw))
#define TEXTMETRICA2W(lptma)\
	((lptma == NULL) ? NULL : ATLTEXTMETRICA2W((LPTEXTMETRICW)alloca(sizeof(TEXTMETRICW)), lptma))

// public\sdk\inc\atl21\atlctl.h
#define PROP_PAGE(clsid) \
		{NULL, NULL, &clsid, &IID_NULL},

// public\sdk\inc\atl21\atlframe.h
#define DECLARE_FRAME_WND_CLASS(WndClassName, uCommonResourceID) \
static CFrameWndClassInfo& GetWndClassInfo() \
{ \
	static CFrameWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), 0, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(COLOR_WINDOW + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T(""), uCommonResourceID \
	}; \
	return wc; \
}
#define DECLARE_FRAME_WND_CLASS_EX(WndClassName, uCommonResourceID, style, bkgnd) \
static CFrameWndClassInfo& GetWndClassInfo() \
{ \
	static CFrameWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), style, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(bkgnd + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T(""), uCommonResourceID \
	}; \
	return wc; \
}
#define DECLARE_FRAME_WND_SUPERCLASS(WndClassName, OrigWndClassName, uCommonResourceID) \
static CFrameWndClassInfo& GetWndClassInfo() \
{ \
	static CFrameWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), 0, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, NULL, NULL, WndClassName, NULL }, \
		OrigWndClassName, NULL, NULL, TRUE, 0, _T(""), uCommonResourceID \
	}; \
	return wc; \
}

// public\sdk\inc\atl21\atlwin.h
#define DECLARE_WND_CLASS(WndClassName) \
static CWndClassInfo& GetWndClassInfo() \
{ \
        static CWndClassInfo wc = \
        { \
                { sizeof(WNDCLASSEX), CS_HREDRAW|CS_VREDRAW, StartWindowProc, \
                  0, 0, 0, 0, 0, (HBRUSH)(COLOR_WINDOW+1), 0, WndClassName, 0 }, \
                NULL, NULL, IDC_ARROW, TRUE, 0, _T("") \
        }; \
        return wc; \
}
#define DECLARE_WND_SUPERCLASS(WndClassName, OrigWndClassName) \
static CWndClassInfo& GetWndClassInfo() \
{ \
        static CWndClassInfo wc = \
        { \
                { sizeof(WNDCLASSEX), NULL, StartWindowProc, \
                  0, 0, 0, 0, 0, NULL, 0, WndClassName, 0 }, \
                OrigWndClassName, NULL, NULL, TRUE, 0, _T("") \
        }; \
        return wc; \
}

// public\sdk\inc\atl30\atlcom.h
#define BEGIN_PROPERTY_MAP(theClass) \
        typedef _ATL_PROP_NOTIFY_EVENT_CLASS __ATL_PROP_NOTIFY_EVENT_CLASS; \
        typedef theClass _PropMapClass; \
        static ATL_PROPMAP_ENTRY* GetPropertyMap()\
        {\
                static ATL_PROPMAP_ENTRY pPropMap[] = \
                { \
                        {OLESTR("_cx"), 0, &CLSID_NULL, NULL, offsetof(_PropMapClass, m_sizeExtent.cx), sizeof(long), VT_UI4}, \
                        {OLESTR("_cy"), 0, &CLSID_NULL, NULL, offsetof(_PropMapClass, m_sizeExtent.cy), sizeof(long), VT_UI4},
#define PROP_PAGE(clsid) \
                {NULL, NULL, &clsid, &IID_NULL, 0, 0, 0},
#define PROP_DATA_ENTRY(szDesc, member, vt) \
                {OLESTR(szDesc), 0, &CLSID_NULL, NULL, offsetof(_PropMapClass, member), sizeof(((_PropMapClass*)0)->member), vt},
#define END_CONNECTION_POINT_MAP() {(DWORD_PTR)-1} }; \
        if (pnEntries) *pnEntries = sizeof(_entries)/sizeof(_ATL_CONNMAP_ENTRY) - 1; \
        return _entries;}

// public\sdk\inc\atl30\atlconv.h
#define DEVMODEW2A(lpw)\
	((lpw == NULL) ? NULL : ATLDEVMODEW2A((LPDEVMODEA)alloca(sizeof(DEVMODEA)+lpw->dmDriverExtra), lpw))
#define DEVMODEA2W(lpa)\
	((lpa == NULL) ? NULL : ATLDEVMODEA2W((LPDEVMODEW)alloca(sizeof(DEVMODEW)+lpa->dmDriverExtra), lpa))
#define TEXTMETRICW2A(lptmw)\
	((lptmw == NULL) ? NULL : ATLTEXTMETRICW2A((LPTEXTMETRICA)alloca(sizeof(TEXTMETRICA)), lptmw))
#define TEXTMETRICA2W(lptma)\
	((lptma == NULL) ? NULL : ATLTEXTMETRICA2W((LPTEXTMETRICW)alloca(sizeof(TEXTMETRICW)), lptma))

// public\sdk\inc\atl30\atldb.h
#define BLOCKINGSTORAGEOBJECTS_Flags ( DBPROPFLAGS_DATASOURCEINFO | DBPROPFLAGS_READ )
#define END_PROPERTY_SET(guid) \
		}; \
		if (pNumPropSets != NULL) \
		{ \
			pSet[nCurProp].pUPropInfo = (UPROPINFO*)aProperty##guid; \
			pSet[nCurProp].cUPropInfo = sizeof(aProperty##guid) / sizeof(UPROPINFO); \
			cRemainder = (pSet[nCurProp].cUPropInfo % 32) ? 1 : 0; \
			if (cElemsMax < (pSet[nCurProp].cUPropInfo / 32 + cRemainder)) \
			{ \
				cElemsMax = (pSet[nCurProp].cUPropInfo / 32 + cRemainder); \
			} \
		} \
		nCurProp++;
#define END_PROPSET_MAP() \
	if (pNumPropSets != NULL) \
	{ \
		if (IsEqualGUID(*pguidSet, GUID_NULL)) \
		{ \
			*pNumPropSets = nCurProp; \
			return pSet; \
		} \
		else \
		{ \
			*pNumPropSets = 1; \
			UINT i = 0; \
			for (; i < sizeof(pSet)/sizeof(UPROPSET) && IsEqualGUID(*(pSet[i].pPropSet), *pguidSet); i++); \
			return (i == sizeof(pSet)/sizeof(UPROPSET)) ? &pSet[0] : &pSet[i]; \
		} \
	} \
	return (UPROPSET*)(DWORD_PTR)nCurProp; \
	}
#define DivDword(dw) (dw >> 5)      // dw / 32 = dw / (sizeof(DWORD)*8)
#define SCHEMA_ENTRY(guid, rowsetClass) \
	if (ppGuid != NULL && SUCCEEDED(hr)) \
	{ \
		cGuids++; \
		*ppGuid = (GUID*)CoTaskMemRealloc(*ppGuid, cGuids * sizeof(GUID)); \
		hr = (*ppGuid == NULL) ? E_OUTOFMEMORY : S_OK; \
		if (SUCCEEDED(hr)) \
			(*ppGuid)[cGuids - 1] = guid; \
	} \
	else \
	{ \
		if (InlineIsEqualGUID(guid, rguidSchema)) \
		{ \
			rowsetClass* pRowset; \
			hr =  CreateSchemaRowset(pUnkOuter, cRestrictions, \
							   rgRestrictions, riid, cPropertySets, \
							   rgPropertySets, ppRowset, pRowset); \
			return hr; \
		} \
	}
#define PROVIDER_COLUMN_ENTRY(name, ordinal, member) \
	{ \
		(LPOLESTR)OLESTR(name), \
		(ITypeInfo*)NULL, \
		(ULONG)ordinal, \
		DBCOLUMNFLAGS_ISFIXEDLENGTH, \
		(ULONG)sizeof(((_Class*)0)->member), \
		_GetOleDBType(((_Class*)0)->member), \
		(BYTE)0, \
		(BYTE)0, \
		{ \
			EXPANDGUID(GUID_NULL), \
			(DWORD)2, \
			(LPOLESTR) name \
		}, \
		offsetof(_Class, member) \
	},
#define PROVIDER_COLUMN_ENTRY_FIXED(name, ordinal, dbtype, member) \
	{ \
		(LPOLESTR)OLESTR(name), \
		(ITypeInfo*)NULL, \
		(ULONG)ordinal, \
		DBCOLUMNFLAGS_ISFIXEDLENGTH, \
		(ULONG)sizeof(((_Class*)0)->member), \
		(DBTYPE)dbtype, \
		(BYTE)0, \
		(BYTE)0, \
		{ \
			EXPANDGUID(GUID_NULL), \
			(DWORD)2, \
			(LPOLESTR) name \
		}, \
		offsetof(_Class, member) \
	},
#define PROVIDER_COLUMN_ENTRY_STR(name, ordinal, member) \
	{ \
		(LPOLESTR)OLESTR(name), \
		(ITypeInfo*)NULL, \
		(ULONG)ordinal, \
		0, \
		(ULONG)sizeof(((_Class*)0)->member), \
		DBTYPE_STR, \
		(BYTE)0xFF, \
		(BYTE)0xFF, \
		{ \
			EXPANDGUID(GUID_NULL), \
			(DWORD)2, \
			(LPOLESTR) name \
		}, \
		offsetof(_Class, member) \
	},
#define PROVIDER_COLUMN_ENTRY_WSTR(name, ordinal, member) \
	{ \
		(LPOLESTR)OLESTR(name), \
		(ITypeInfo*)NULL, \
		(ULONG)ordinal, \
		0, \
		(ULONG)sizeof(((_Class*)0)->member), \
		DBTYPE_WSTR, \
		(BYTE)0xFF, \
		(BYTE)0xFF, \
		{ \
			EXPANDGUID(GUID_NULL), \
			(DWORD)2, \
			(LPOLESTR) name \
		}, \
		offsetof(_Class, member) \
	},
#define END_PROVIDER_COLUMN_MAP() \
}; *pcCols = sizeof(_rgColumns)/sizeof(ATLCOLUMNINFO); return _rgColumns;}

// public\sdk\inc\atl30\atldbcli.h
#define _SIZE_TYPE(data) sizeof(((_classtype*)0)->data)
#define _BLOB_ENTRY_CODE(nOrdinal, IID, flags, dataOffset, statusOffset) \
	if (pBuffer != NULL) \
	{ \
		CAccessorBase::FreeType(DBTYPE_IUNKNOWN, pBuffer + dataOffset); \
	} \
	else if (pBinding != NULL) \
	{ \
		DBOBJECT* pObject = NULL; \
		ATLTRY(pObject = new DBOBJECT); \
		if (pObject == NULL) \
			return E_OUTOFMEMORY; \
		pObject->dwFlags = flags; \
		pObject->iid     = IID; \
		CAccessorBase::Bind(pBinding, nOrdinal, DBTYPE_IUNKNOWN, sizeof(IUnknown*), 0, 0, eParamIO, \
			dataOffset, 0, statusOffset, pObject); \
		pBinding++; \
	} \
	nColumns++;

// public\sdk\inc\atl30\atliface.h
#define IAxWinAmbientDispatch_put_BackColor(This,clrBackground)	\
    (This)->lpVtbl -> put_BackColor(This,clrBackground)
#define IAxWinAmbientDispatch_get_BackColor(This,pclrBackground)	\
    (This)->lpVtbl -> get_BackColor(This,pclrBackground)
#define IAxWinAmbientDispatch_put_ForeColor(This,clrForeground)	\
    (This)->lpVtbl -> put_ForeColor(This,clrForeground)
#define IAxWinAmbientDispatch_get_ForeColor(This,pclrForeground)	\
    (This)->lpVtbl -> get_ForeColor(This,pclrForeground)

// public\sdk\inc\atl30\atlsnap.h
#define BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname) \
	HRESULT GetDataClass(IDataObject* pDataObject, CSnapInItem** ppItem, DATA_OBJECT_TYPES* pType) \
	{ \
		if (ppItem == NULL) \
			return E_POINTER; \
		if (pType == NULL) \
			return E_POINTER; \
\
		*ppItem = NULL; \
\
		*pType = CCT_UNINITIALIZED; \
\
		STGMEDIUM stgmedium = { TYMED_HGLOBAL, NULL }; \
		FORMATETC formatetc = { CSnapInItem::m_CCF_NODETYPE, \
			NULL, \
			DVASPECT_CONTENT, \
			-1, \
			TYMED_HGLOBAL \
		}; \
\
		stgmedium.hGlobal = GlobalAlloc(0, sizeof(GUID)); \
		if (stgmedium.hGlobal == NULL) \
			return E_OUTOFMEMORY; \
\
		HRESULT hr = pDataObject->GetDataHere(&formatetc, &stgmedium); \
		if (FAILED(hr)) \
		{ \
			GlobalFree(stgmedium.hGlobal); \
			return hr; \
		} \
\
		GUID guid; \
		memcpy(&guid, stgmedium.hGlobal, sizeof(GUID)); \
\
		GlobalFree(stgmedium.hGlobal); \
		hr = S_OK;

// public\sdk\inc\atl30\atlwin.h
#define DECLARE_WND_CLASS(WndClassName) \
static CWndClassInfo& GetWndClassInfo() \
{ \
	static CWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(COLOR_WINDOW + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T("") \
	}; \
	return wc; \
}
#define DECLARE_WND_CLASS_EX(WndClassName, style, bkgnd) \
static CWndClassInfo& GetWndClassInfo() \
{ \
	static CWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), style, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(bkgnd + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T("") \
	}; \
	return wc; \
}
#define DECLARE_WND_SUPERCLASS(WndClassName, OrigWndClassName) \
static CWndClassInfo& GetWndClassInfo() \
{ \
	static CWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), 0, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, NULL, NULL, WndClassName, NULL }, \
		OrigWndClassName, NULL, NULL, TRUE, 0, _T("") \
	}; \
	return wc; \
}

// public\sdk\inc\bits.h
#define IBackgroundCopyFile_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyFile_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyFile_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyFile_GetRemoteName(This,pVal)	\
    (This)->lpVtbl -> GetRemoteName(This,pVal)
#define IBackgroundCopyFile_GetLocalName(This,pVal)	\
    (This)->lpVtbl -> GetLocalName(This,pVal)
#define IBackgroundCopyFile_GetProgress(This,pVal)	\
    (This)->lpVtbl -> GetProgress(This,pVal)
#define IEnumBackgroundCopyFiles_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumBackgroundCopyFiles_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumBackgroundCopyFiles_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumBackgroundCopyFiles_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)
#define IEnumBackgroundCopyFiles_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IEnumBackgroundCopyFiles_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumBackgroundCopyFiles_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)
#define IEnumBackgroundCopyFiles_GetCount(This,puCount)	\
    (This)->lpVtbl -> GetCount(This,puCount)
#define IBackgroundCopyError_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyError_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyError_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyError_GetError(This,pContext,pCode)	\
    (This)->lpVtbl -> GetError(This,pContext,pCode)
#define IBackgroundCopyError_GetFile(This,pVal)	\
    (This)->lpVtbl -> GetFile(This,pVal)
#define IBackgroundCopyError_GetErrorDescription(This,LanguageId,pErrorDescription)	\
    (This)->lpVtbl -> GetErrorDescription(This,LanguageId,pErrorDescription)
#define IBackgroundCopyError_GetErrorContextDescription(This,LanguageId,pContextDescription)	\
    (This)->lpVtbl -> GetErrorContextDescription(This,LanguageId,pContextDescription)
#define IBackgroundCopyError_GetProtocol(This,pProtocol)	\
    (This)->lpVtbl -> GetProtocol(This,pProtocol)
#define IBackgroundCopyJob_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyJob_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyJob_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyJob_AddFileSet(This,cFileCount,pFileSet)	\
    (This)->lpVtbl -> AddFileSet(This,cFileCount,pFileSet)
#define IBackgroundCopyJob_AddFile(This,RemoteUrl,LocalName)	\
    (This)->lpVtbl -> AddFile(This,RemoteUrl,LocalName)
#define IBackgroundCopyJob_EnumFiles(This,pEnum)	\
    (This)->lpVtbl -> EnumFiles(This,pEnum)
#define IBackgroundCopyJob_Suspend(This)	\
    (This)->lpVtbl -> Suspend(This)
#define IBackgroundCopyJob_Resume(This)	\
    (This)->lpVtbl -> Resume(This)
#define IBackgroundCopyJob_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)
#define IBackgroundCopyJob_Complete(This)	\
    (This)->lpVtbl -> Complete(This)
#define IBackgroundCopyJob_GetId(This,pVal)	\
    (This)->lpVtbl -> GetId(This,pVal)
#define IBackgroundCopyJob_GetType(This,pVal)	\
    (This)->lpVtbl -> GetType(This,pVal)
#define IBackgroundCopyJob_GetProgress(This,pVal)	\
    (This)->lpVtbl -> GetProgress(This,pVal)
#define IBackgroundCopyJob_GetTimes(This,pVal)	\
    (This)->lpVtbl -> GetTimes(This,pVal)
#define IBackgroundCopyJob_GetState(This,pVal)	\
    (This)->lpVtbl -> GetState(This,pVal)
#define IBackgroundCopyJob_GetError(This,ppError)	\
    (This)->lpVtbl -> GetError(This,ppError)
#define IBackgroundCopyJob_GetOwner(This,pVal)	\
    (This)->lpVtbl -> GetOwner(This,pVal)
#define IBackgroundCopyJob_SetDisplayName(This,Val)	\
    (This)->lpVtbl -> SetDisplayName(This,Val)
#define IBackgroundCopyJob_GetDisplayName(This,pVal)	\
    (This)->lpVtbl -> GetDisplayName(This,pVal)
#define IBackgroundCopyJob_SetDescription(This,Val)	\
    (This)->lpVtbl -> SetDescription(This,Val)
#define IBackgroundCopyJob_GetDescription(This,pVal)	\
    (This)->lpVtbl -> GetDescription(This,pVal)
#define IBackgroundCopyJob_SetPriority(This,Val)	\
    (This)->lpVtbl -> SetPriority(This,Val)
#define IBackgroundCopyJob_GetPriority(This,pVal)	\
    (This)->lpVtbl -> GetPriority(This,pVal)
#define IBackgroundCopyJob_SetNotifyFlags(This,Val)	\
    (This)->lpVtbl -> SetNotifyFlags(This,Val)
#define IBackgroundCopyJob_GetNotifyFlags(This,pVal)	\
    (This)->lpVtbl -> GetNotifyFlags(This,pVal)
#define IBackgroundCopyJob_SetNotifyInterface(This,Val)	\
    (This)->lpVtbl -> SetNotifyInterface(This,Val)
#define IBackgroundCopyJob_GetNotifyInterface(This,pVal)	\
    (This)->lpVtbl -> GetNotifyInterface(This,pVal)
#define IBackgroundCopyJob_SetMinimumRetryDelay(This,Seconds)	\
    (This)->lpVtbl -> SetMinimumRetryDelay(This,Seconds)
#define IBackgroundCopyJob_GetMinimumRetryDelay(This,Seconds)	\
    (This)->lpVtbl -> GetMinimumRetryDelay(This,Seconds)
#define IBackgroundCopyJob_SetNoProgressTimeout(This,Seconds)	\
    (This)->lpVtbl -> SetNoProgressTimeout(This,Seconds)
#define IBackgroundCopyJob_GetNoProgressTimeout(This,Seconds)	\
    (This)->lpVtbl -> GetNoProgressTimeout(This,Seconds)
#define IBackgroundCopyJob_GetErrorCount(This,Errors)	\
    (This)->lpVtbl -> GetErrorCount(This,Errors)
#define IBackgroundCopyJob_SetProxySettings(This,ProxyUsage,ProxyList,ProxyBypassList)	\
    (This)->lpVtbl -> SetProxySettings(This,ProxyUsage,ProxyList,ProxyBypassList)
#define IBackgroundCopyJob_GetProxySettings(This,pProxyUsage,pProxyList,pProxyBypassList)	\
    (This)->lpVtbl -> GetProxySettings(This,pProxyUsage,pProxyList,pProxyBypassList)
#define IBackgroundCopyJob_TakeOwnership(This)	\
    (This)->lpVtbl -> TakeOwnership(This)
#define IEnumBackgroundCopyJobs_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumBackgroundCopyJobs_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumBackgroundCopyJobs_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumBackgroundCopyJobs_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)
#define IEnumBackgroundCopyJobs_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IEnumBackgroundCopyJobs_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumBackgroundCopyJobs_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)
#define IEnumBackgroundCopyJobs_GetCount(This,puCount)	\
    (This)->lpVtbl -> GetCount(This,puCount)
#define IBackgroundCopyCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyCallback_JobTransferred(This,pJob)	\
    (This)->lpVtbl -> JobTransferred(This,pJob)
#define IBackgroundCopyCallback_JobError(This,pJob,pError)	\
    (This)->lpVtbl -> JobError(This,pJob,pError)
#define IBackgroundCopyCallback_JobModification(This,pJob,dwReserved)	\
    (This)->lpVtbl -> JobModification(This,pJob,dwReserved)
#define AsyncIBackgroundCopyCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define AsyncIBackgroundCopyCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define AsyncIBackgroundCopyCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define AsyncIBackgroundCopyCallback_Begin_JobTransferred(This,pJob)	\
    (This)->lpVtbl -> Begin_JobTransferred(This,pJob)
#define AsyncIBackgroundCopyCallback_Finish_JobTransferred(This)	\
    (This)->lpVtbl -> Finish_JobTransferred(This)
#define AsyncIBackgroundCopyCallback_Begin_JobError(This,pJob,pError)	\
    (This)->lpVtbl -> Begin_JobError(This,pJob,pError)
#define AsyncIBackgroundCopyCallback_Finish_JobError(This)	\
    (This)->lpVtbl -> Finish_JobError(This)
#define AsyncIBackgroundCopyCallback_Begin_JobModification(This,pJob,dwReserved)	\
    (This)->lpVtbl -> Begin_JobModification(This,pJob,dwReserved)
#define AsyncIBackgroundCopyCallback_Finish_JobModification(This)	\
    (This)->lpVtbl -> Finish_JobModification(This)
#define IBackgroundCopyManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyManager_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyManager_CreateJob(This,DisplayName,Type,pJobId,ppJob)	\
    (This)->lpVtbl -> CreateJob(This,DisplayName,Type,pJobId,ppJob)
#define IBackgroundCopyManager_GetJob(This,jobID,ppJob)	\
    (This)->lpVtbl -> GetJob(This,jobID,ppJob)
#define IBackgroundCopyManager_EnumJobs(This,dwFlags,ppEnum)	\
    (This)->lpVtbl -> EnumJobs(This,dwFlags,ppEnum)
#define IBackgroundCopyManager_GetErrorDescription(This,hResult,LanguageId,pErrorDescription)	\
    (This)->lpVtbl -> GetErrorDescription(This,hResult,LanguageId,pErrorDescription)

// public\sdk\inc\bits1_5.h
#define IBackgroundCopyJob2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBackgroundCopyJob2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBackgroundCopyJob2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBackgroundCopyJob2_AddFileSet(This,cFileCount,pFileSet)	\
    (This)->lpVtbl -> AddFileSet(This,cFileCount,pFileSet)
#define IBackgroundCopyJob2_AddFile(This,RemoteUrl,LocalName)	\
    (This)->lpVtbl -> AddFile(This,RemoteUrl,LocalName)
#define IBackgroundCopyJob2_EnumFiles(This,pEnum)	\
    (This)->lpVtbl -> EnumFiles(This,pEnum)
#define IBackgroundCopyJob2_Suspend(This)	\
    (This)->lpVtbl -> Suspend(This)
#define IBackgroundCopyJob2_Resume(This)	\
    (This)->lpVtbl -> Resume(This)
#define IBackgroundCopyJob2_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)
#define IBackgroundCopyJob2_Complete(This)	\
    (This)->lpVtbl -> Complete(This)
#define IBackgroundCopyJob2_GetId(This,pVal)	\
    (This)->lpVtbl -> GetId(This,pVal)
#define IBackgroundCopyJob2_GetType(This,pVal)	\
    (This)->lpVtbl -> GetType(This,pVal)
#define IBackgroundCopyJob2_GetProgress(This,pVal)	\
    (This)->lpVtbl -> GetProgress(This,pVal)
#define IBackgroundCopyJob2_GetTimes(This,pVal)	\
    (This)->lpVtbl -> GetTimes(This,pVal)
#define IBackgroundCopyJob2_GetState(This,pVal)	\
    (This)->lpVtbl -> GetState(This,pVal)
#define IBackgroundCopyJob2_GetError(This,ppError)	\
    (This)->lpVtbl -> GetError(This,ppError)
#define IBackgroundCopyJob2_GetOwner(This,pVal)	\
    (This)->lpVtbl -> GetOwner(This,pVal)
#define IBackgroundCopyJob2_SetDisplayName(This,Val)	\
    (This)->lpVtbl -> SetDisplayName(This,Val)
#define IBackgroundCopyJob2_GetDisplayName(This,pVal)	\
    (This)->lpVtbl -> GetDisplayName(This,pVal)
#define IBackgroundCopyJob2_SetDescription(This,Val)	\
    (This)->lpVtbl -> SetDescription(This,Val)
#define IBackgroundCopyJob2_GetDescription(This,pVal)	\
    (This)->lpVtbl -> GetDescription(This,pVal)
#define IBackgroundCopyJob2_SetPriority(This,Val)	\
    (This)->lpVtbl -> SetPriority(This,Val)
#define IBackgroundCopyJob2_GetPriority(This,pVal)	\
    (This)->lpVtbl -> GetPriority(This,pVal)
#define IBackgroundCopyJob2_SetNotifyFlags(This,Val)	\
    (This)->lpVtbl -> SetNotifyFlags(This,Val)
#define IBackgroundCopyJob2_GetNotifyFlags(This,pVal)	\
    (This)->lpVtbl -> GetNotifyFlags(This,pVal)
#define IBackgroundCopyJob2_SetNotifyInterface(This,Val)	\
    (This)->lpVtbl -> SetNotifyInterface(This,Val)
#define IBackgroundCopyJob2_GetNotifyInterface(This,pVal)	\
    (This)->lpVtbl -> GetNotifyInterface(This,pVal)
#define IBackgroundCopyJob2_SetMinimumRetryDelay(This,Seconds)	\
    (This)->lpVtbl -> SetMinimumRetryDelay(This,Seconds)
#define IBackgroundCopyJob2_GetMinimumRetryDelay(This,Seconds)	\
    (This)->lpVtbl -> GetMinimumRetryDelay(This,Seconds)
#define IBackgroundCopyJob2_SetNoProgressTimeout(This,Seconds)	\
    (This)->lpVtbl -> SetNoProgressTimeout(This,Seconds)
#define IBackgroundCopyJob2_GetNoProgressTimeout(This,Seconds)	\
    (This)->lpVtbl -> GetNoProgressTimeout(This,Seconds)
#define IBackgroundCopyJob2_GetErrorCount(This,Errors)	\
    (This)->lpVtbl -> GetErrorCount(This,Errors)
#define IBackgroundCopyJob2_SetProxySettings(This,ProxyUsage,ProxyList,ProxyBypassList)	\
    (This)->lpVtbl -> SetProxySettings(This,ProxyUsage,ProxyList,ProxyBypassList)
#define IBackgroundCopyJob2_GetProxySettings(This,pProxyUsage,pProxyList,pProxyBypassList)	\
    (This)->lpVtbl -> GetProxySettings(This,pProxyUsage,pProxyList,pProxyBypassList)
#define IBackgroundCopyJob2_TakeOwnership(This)	\
    (This)->lpVtbl -> TakeOwnership(This)
#define IBackgroundCopyJob2_SetNotifyCmdLine(This,Val)	\
    (This)->lpVtbl -> SetNotifyCmdLine(This,Val)
#define IBackgroundCopyJob2_GetNotifyCmdLine(This,pVal)	\
    (This)->lpVtbl -> GetNotifyCmdLine(This,pVal)
#define IBackgroundCopyJob2_GetReplyProgress(This,pProgress)	\
    (This)->lpVtbl -> GetReplyProgress(This,pProgress)
#define IBackgroundCopyJob2_GetReplyData(This,ppBuffer,pLength)	\
    (This)->lpVtbl -> GetReplyData(This,ppBuffer,pLength)
#define IBackgroundCopyJob2_SetReplyFileName(This,ReplyFileName)	\
    (This)->lpVtbl -> SetReplyFileName(This,ReplyFileName)
#define IBackgroundCopyJob2_GetReplyFileName(This,pReplyFileName)	\
    (This)->lpVtbl -> GetReplyFileName(This,pReplyFileName)
#define IBackgroundCopyJob2_SetCredentials(This,credentials)	\
    (This)->lpVtbl -> SetCredentials(This,credentials)
#define IBackgroundCopyJob2_RemoveCredentials(This,Target,Scheme)	\
    (This)->lpVtbl -> RemoveCredentials(This,Target,Scheme)

// public\sdk\inc\cfgmgr32.h
#define MType_Range     sizeof(struct Mem_Range_s)
#define IOType_Range    sizeof(struct IO_Range_s)
#define DType_Range     sizeof(struct DMA_Range_s)
#define IRQType_Range   sizeof(struct IRQ_Range_s)
#define PType_Range    sizeof(struct DevPrivate_Range_s)
#define BusNumberType_Range   sizeof(struct BusNumber_Range_s)

// public\sdk\inc\cierror.h
#define QUTIL_E_INVALID_CODEPAGE         ((HRESULT)0xC0041678L)
#define FDAEMON_E_TOOMANYFILTEREDBLOCKS  ((HRESULT)0x80041688L)
#define CI_E_STRANGE_PAGEORSECTOR_SIZE   ((HRESULT)0x8004181EL)

// public\sdk\inc\cluadmex.h
#define IWCPropertySheetCallback_AddPropertySheetPage(This,hpage)	\
    (This)->lpVtbl -> AddPropertySheetPage(This,hpage)
#define IWEExtendPropertySheet_CreatePropertySheetPages(This,piData,piCallback)	\
    (This)->lpVtbl -> CreatePropertySheetPages(This,piData,piCallback)
#define IWCWizardCallback_AddWizardPage(This,hpage)	\
    (This)->lpVtbl -> AddWizardPage(This,hpage)
#define IWCWizardCallback_EnableNext(This,hpage,bEnable)	\
    (This)->lpVtbl -> EnableNext(This,hpage,bEnable)
#define IWEExtendWizard_CreateWizardPages(This,piData,piCallback)	\
    (This)->lpVtbl -> CreateWizardPages(This,piData,piCallback)
#define IWCWizard97Callback_AddWizard97Page(This,hpage)	\
    (This)->lpVtbl -> AddWizard97Page(This,hpage)
#define IWCWizard97Callback_EnableNext(This,hpage,bEnable)	\
    (This)->lpVtbl -> EnableNext(This,hpage,bEnable)
#define IWEExtendWizard97_CreateWizard97Pages(This,piData,piCallback)	\
    (This)->lpVtbl -> CreateWizard97Pages(This,piData,piCallback)

// public\sdk\inc\clusapi.h
#define ALIGN_CLUSPROP( count ) ((count + 3) & ~3)

// public\sdk\inc\commctrl.h
#define CCSIZEOF_STRUCT(structname, member)  (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))
#define TBM_SETPAGESIZE         (WM_USER+21)
#define TBM_GETPAGESIZE         (WM_USER+22)
#define ListView_GetCountPerPage(hwndLV) \
    (int)SNDMSG((hwndLV), LVM_GETCOUNTPERPAGE, 0, 0)
#define L_MAX_URL_LENGTH    (2048 + 32 + sizeof("://"))

// public\sdk\inc\commdlg.h
#define CDSIZEOF_STRUCT(structname, member)  (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))

// public\sdk\inc\control.h
#define IVideoWindow_put_BackgroundPalette(This,BackgroundPalette)	\
    (This)->lpVtbl -> put_BackgroundPalette(This,BackgroundPalette)
#define IVideoWindow_get_BackgroundPalette(This,pBackgroundPalette)	\
    (This)->lpVtbl -> get_BackgroundPalette(This,pBackgroundPalette)
#define IVideoWindow_SetWindowForeground(This,Focus)	\
    (This)->lpVtbl -> SetWindowForeground(This,Focus)

// public\sdk\inc\crt\crtdbg.h
#define _BLOCK_TYPE(block)          (block & 0xFFFF)
#define _BLOCK_SUBTYPE(block)       (block >> 16 & 0xFFFF)

// public\sdk\inc\crt\stdarg.h
#define va_start(ap,v)  ( __va_start(&ap, _ADDRESSOF(v), sizeof(v), \
                                __builtin_alignof(v), _ADDRESSOF(v)) )
#define va_arg(ap,t)    ( *(t *)__va_arg(&ap, sizeof(t), \
                                __builtin_alignof(t), (t *)0) )
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v) ap  = (va_list)_ADDRESSOF(v) + sizeof(v)
#define va_arg(list, mode) ((mode *)(list =\
 (char *) ((((int)list + (__builtin_alignof(mode)<=4?3:7)) &\
 (__builtin_alignof(mode)<=4?-4:-8))+sizeof(mode))))[-1]
#define va_arg(list, mode) \
    ( *(        ((list).offset += ((int)sizeof(mode) + 7) & -8) , \
        (mode *)((list).a0 + (list).offset - \
                    ((__builtin_isfloat(mode) && (list).offset <= (6 * 8)) ? \
                        (6 * 8) + 8 : ((int)sizeof(mode) + 7) & -8) \
                ) \
       ) \
    )
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define _ALIGNIT(ap,t) \
        ((((int)(ap))+(sizeof(t)<8?3:7)) & (sizeof(t)<8?~3:~7))
#define _ALIGNOF(ap) ((((ap)+_VA_STRUCT_ALIGN - 1) & ~(_VA_STRUCT_ALIGN -1)) \
                            - (ap))
#define _SLOTSIZEOF(t)   ( (sizeof(t) + _VA_ALIGN - 1) & ~(_VA_ALIGN - 1) )
#define va_start(ap,v)  ( __va_start(&ap, _ADDRESSOF(v), _SLOTSIZEOF(v), \
				     _ADDRESSOF(v)) )
#define va_arg(ap, t)   \
    ( ( sizeof(t) > sizeof(__int64) || ( sizeof(t) & (sizeof(t) - 1) ) != 0 ) \
        ? **(t **)( ( ap += sizeof(__int64) ) - sizeof(__int64) ) \
        :  *(t  *)( ( ap += sizeof(__int64) ) - sizeof(__int64) ) )
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

// public\sdk\inc\crt\stdio.h
#define L_tmpnam sizeof(_P_tmpdir)+12

// public\sdk\inc\crt\varargs.h
#define _INTSIZEOF(n)    ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_arg(list, mode) ((mode *)(list =\
 (char *) ((((int)list + (__builtin_alignof(mode)<=4?3:7)) &\
 (__builtin_alignof(mode)<=4?-4:-8))+sizeof(mode))))[-1]
#define va_arg(list, mode) \
    ( *(        ((list).offset += ((int)sizeof(mode) + 7) & -8) , \
        (mode *)((list).a0 + (list).offset - \
                    ((__builtin_isfloat(mode) && (list).offset <= (6 * 8)) ? \
                        (6 * 8) + 8 : ((int)sizeof(mode) + 7) & -8) \
                ) \
       ) \
    )
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define _ALIGNIT(ap,t) \
        ((((int)(ap))+(sizeof(t)<8?3:7)) & (sizeof(t)<8?~3:~7))
#define _ALIGNOF(ap) ((((ap)+_VA_STRUCT_ALIGN - 1) & ~(_VA_STRUCT_ALIGN -1)) \
                            - (ap))
#define _SLOTSIZEOF(t)   ( (sizeof(t) + _VA_ALIGN - 1) & ~(_VA_ALIGN - 1) )
#define va_arg(ap, t)   \
    ( ( sizeof(t) > sizeof(__int64) || ( sizeof(t) & (sizeof(t) - 1) ) != 0 ) \
        ? **(t **)( ( ap += sizeof(__int64) ) - sizeof(__int64) ) \
        :  *(t  *)( ( ap += sizeof(__int64) ) - sizeof(__int64) ) )
#define _INTSIZEOF(n)    ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

// public\sdk\inc\d3d.h
#define D3DERR_INVALIDSTATEBLOCK        MAKE_DDHRESULT(2100)
#define D3DERR_INBEGINSTATEBLOCK        MAKE_DDHRESULT(2101)
#define D3DERR_NOTINBEGINSTATEBLOCK     MAKE_DDHRESULT(2102)

// public\sdk\inc\d3dcaps.h
#define D3DDEVICEDESCSIZE (sizeof(D3DDEVICEDESC))
#define D3DDEVICEDESC7SIZE (sizeof(D3DDEVICEDESC7))

// public\sdk\inc\danim.h
#define IDABehavior_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDANumber_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDADrawingSurface_FillColor(This,foreground)	\
    (This)->lpVtbl -> FillColor(This,foreground)
#define IDADrawingSurface_RoundRect(This,xPos,yPos,w,h,arcWidth,arcHeight)	\
    (This)->lpVtbl -> RoundRect(This,xPos,yPos,w,h,arcWidth,arcHeight)
#define IDAEvent_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDA2Behavior_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAImport_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAModifiableBehavior_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDABoolean_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDACamera_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAColor_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAGeometry_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAImage_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAMatte_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAMicrophone_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAMontage_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAPath2_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAPoint2_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAPoint3_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDASound_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAString_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDATransform2_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDATransform3_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAVector2_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAVector3_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAFontStyle_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDALineStyle_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAEndStyle_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAJoinStyle_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDADashStyle_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDABbox2_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDABbox3_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAPair_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDATuple_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAUserData_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDA2Geometry_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDA2Image_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDA2FontStyle_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDA2LineStyle_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDA2Event_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDA2Color_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDA3Geometry_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDA3Image_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAStatics_Floor(This,a_0,ret_1)	\
    (This)->lpVtbl -> Floor(This,a_0,ret_1)
#define IDAStatics_Round(This,a_0,ret_1)	\
    (This)->lpVtbl -> Round(This,a_0,ret_1)
#define IDAStatics_Ceiling(This,a_0,ret_1)	\
    (This)->lpVtbl -> Ceiling(This,a_0,ret_1)
#define IDAStatics_get_JoinStyleRound(This,ret_0)	\
    (This)->lpVtbl -> get_JoinStyleRound(This,ret_0)
#define IDAStatics_get_EndStyleRound(This,ret_0)	\
    (This)->lpVtbl -> get_EndStyleRound(This,ret_0)
#define IDAStatics_RoundRect(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)	\
    (This)->lpVtbl -> RoundRect(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)
#define IDAStatics_RoundRectAnim(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)	\
    (This)->lpVtbl -> RoundRectAnim(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)
#define IDAStatics_get_AreBlockingImportsComplete(This,bComplete)	\
    (This)->lpVtbl -> get_AreBlockingImportsComplete(This,bComplete)
#define IDA2Statics_Floor(This,a_0,ret_1)	\
    (This)->lpVtbl -> Floor(This,a_0,ret_1)
#define IDA2Statics_Round(This,a_0,ret_1)	\
    (This)->lpVtbl -> Round(This,a_0,ret_1)
#define IDA2Statics_Ceiling(This,a_0,ret_1)	\
    (This)->lpVtbl -> Ceiling(This,a_0,ret_1)
#define IDA2Statics_get_JoinStyleRound(This,ret_0)	\
    (This)->lpVtbl -> get_JoinStyleRound(This,ret_0)
#define IDA2Statics_get_EndStyleRound(This,ret_0)	\
    (This)->lpVtbl -> get_EndStyleRound(This,ret_0)
#define IDA2Statics_RoundRect(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)	\
    (This)->lpVtbl -> RoundRect(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)
#define IDA2Statics_RoundRectAnim(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)	\
    (This)->lpVtbl -> RoundRectAnim(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)
#define IDA2Statics_get_AreBlockingImportsComplete(This,bComplete)	\
    (This)->lpVtbl -> get_AreBlockingImportsComplete(This,bComplete)
#define IDA3Statics_Floor(This,a_0,ret_1)	\
    (This)->lpVtbl -> Floor(This,a_0,ret_1)
#define IDA3Statics_Round(This,a_0,ret_1)	\
    (This)->lpVtbl -> Round(This,a_0,ret_1)
#define IDA3Statics_Ceiling(This,a_0,ret_1)	\
    (This)->lpVtbl -> Ceiling(This,a_0,ret_1)
#define IDA3Statics_get_JoinStyleRound(This,ret_0)	\
    (This)->lpVtbl -> get_JoinStyleRound(This,ret_0)
#define IDA3Statics_get_EndStyleRound(This,ret_0)	\
    (This)->lpVtbl -> get_EndStyleRound(This,ret_0)
#define IDA3Statics_RoundRect(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)	\
    (This)->lpVtbl -> RoundRect(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)
#define IDA3Statics_RoundRectAnim(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)	\
    (This)->lpVtbl -> RoundRectAnim(This,width_0,height_1,cornerArcWidth_2,cornerArcHeight_3,ret_4)
#define IDA3Statics_get_AreBlockingImportsComplete(This,bComplete)	\
    (This)->lpVtbl -> get_AreBlockingImportsComplete(This,bComplete)
#define IDAViewerControl_get_BackgroundImage(This,ppImage)	\
    (This)->lpVtbl -> get_BackgroundImage(This,ppImage)
#define IDAViewerControl_put_BackgroundImage(This,pImage)	\
    (This)->lpVtbl -> put_BackgroundImage(This,pImage)
#define IDAViewerControlWindowed_get_BackgroundImage(This,ppImage)	\
    (This)->lpVtbl -> get_BackgroundImage(This,ppImage)
#define IDAViewerControlWindowed_put_BackgroundImage(This,pImage)	\
    (This)->lpVtbl -> put_BackgroundImage(This,pImage)
#define IDA2ViewerControl_get_BackgroundImage(This,ppImage)	\
    (This)->lpVtbl -> get_BackgroundImage(This,ppImage)
#define IDA2ViewerControl_put_BackgroundImage(This,pImage)	\
    (This)->lpVtbl -> put_BackgroundImage(This,pImage)
#define IDA2ViewerControlWindowed_get_BackgroundImage(This,ppImage)	\
    (This)->lpVtbl -> get_BackgroundImage(This,ppImage)
#define IDA2ViewerControlWindowed_put_BackgroundImage(This,pImage)	\
    (This)->lpVtbl -> put_BackgroundImage(This,pImage)
#define IDA3ViewerControl_get_BackgroundImage(This,ppImage)	\
    (This)->lpVtbl -> get_BackgroundImage(This,ppImage)
#define IDA3ViewerControl_put_BackgroundImage(This,pImage)	\
    (This)->lpVtbl -> put_BackgroundImage(This,pImage)
#define IDA3ViewerControlWindowed_get_BackgroundImage(This,ppImage)	\
    (This)->lpVtbl -> get_BackgroundImage(This,ppImage)
#define IDA3ViewerControlWindowed_put_BackgroundImage(This,pImage)	\
    (This)->lpVtbl -> put_BackgroundImage(This,pImage)

// public\sdk\inc\dbgprop.h
#define IPerPropertyBrowsing2_MapPropertyToPage(This,dispid,pClsidPropPage)	\
    (This)->lpVtbl -> MapPropertyToPage(This,dispid,pClsidPropPage)

// public\sdk\inc\ddeml.h
#define     XTYP_ERROR              (0x0000 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK )
#define     XTYP_ADVREQ             (0x0020 | XCLASS_DATA | XTYPF_NOBLOCK )
#define     XTYP_CONNECT            (0x0060 | XCLASS_BOOL | XTYPF_NOBLOCK)
#define     XTYP_CONNECT_CONFIRM    (0x0070 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_REGISTER           (0x00A0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_DISCONNECT         (0x00C0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_UNREGISTER         (0x00D0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define     XTYP_WILDCONNECT        (0x00E0 | XCLASS_DATA | XTYPF_NOBLOCK)
#define     XTYP_MONITOR            (0x00F0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)

// public\sdk\inc\ddraw.h
#define DDERR_HEIGHTALIGN                       MAKE_DDHRESULT( 90 )
#define DDERR_XALIGN                            MAKE_DDHRESULT( 560 )
#define DDERR_CANTPAGELOCK                      MAKE_DDHRESULT( 640 )
#define DDERR_CANTPAGEUNLOCK                    MAKE_DDHRESULT( 660 )
#define DDERR_NOTPAGELOCKED                     MAKE_DDHRESULT( 680 )

// public\sdk\inc\des.h
#define DES_TABLESIZE   (sizeof(DESTable))
#define DESX_TABLESIZE  (sizeof(DESXTable))

// public\sdk\inc\dimm.h
#define IActiveIMMApp_GetCodePageA(This,hKL,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage)
#define IActiveIMMIME_GetCodePageA(This,hKL,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage)
#define IActiveIME_GetCodePageA(This,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,uCodePage)
#define IActiveIME2_GetCodePageA(This,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,uCodePage)

// public\sdk\inc\dinput.h
#define DIJOFS_SLIDER(n)   (FIELD_OFFSET(DIJOYSTATE, rglSlider) + \
                                                        (n) * sizeof(LONG))
#define DIJOFS_POV(n)      (FIELD_OFFSET(DIJOYSTATE, rgdwPOV) + \
                                                        (n) * sizeof(DWORD))

// public\sdk\inc\dlcapi.h
#define LLC_XMIT_BUFFER_SIZE sizeof(LLC_XMIT_BUFFER)

// public\sdk\inc\dmusbuff.h
#define DMUS_EVENT_SIZE(cb) QWORD_ALIGN(sizeof(DMUS_EVENTHEADER) + cb)

// public\sdk\inc\docobj.h
#define IContinueCallback_FContinuePrinting(This,nCntPrinted,nCurPage,pwszPrintStatus)	\
    (This)->lpVtbl -> FContinuePrinting(This,nCntPrinted,nCurPage,pwszPrintStatus)
#define IPrint_SetInitialPageNum(This,nFirstPage)	\
    (This)->lpVtbl -> SetInitialPageNum(This,nFirstPage)
#define IPrint_GetPageInfo(This,pnFirstPage,pcPages)	\
    (This)->lpVtbl -> GetPageInfo(This,pnFirstPage,pcPages)
#define IPrint_Print(This,grfFlags,pptd,ppPageSet,pstgmOptions,pcallback,nFirstPage,pcPagesPrinted,pnLastPage)	\
    (This)->lpVtbl -> Print(This,grfFlags,pptd,ppPageSet,pstgmOptions,pcallback,nFirstPage,pcPagesPrinted,pnLastPage)

// public\sdk\inc\dsgetdc.h
#define DSGETDC_VALID_FLAGS ( \
            DS_FORCE_REDISCOVERY | \
            DS_DIRECTORY_SERVICE_REQUIRED | \
            DS_DIRECTORY_SERVICE_PREFERRED | \
            DS_GC_SERVER_REQUIRED | \
            DS_PDC_REQUIRED | \
            DS_BACKGROUND_ONLY | \
            DS_IP_REQUIRED | \
            DS_KDC_REQUIRED | \
            DS_TIMESERV_REQUIRED | \
            DS_WRITABLE_REQUIRED | \
            DS_GOOD_TIMESERV_PREFERRED | \
            DS_AVOID_SELF | \
            DS_ONLY_LDAP_NEEDED | \
            DS_IS_FLAT_NAME | \
            DS_IS_DNS_NAME | \
            DS_RETURN_FLAT_NAME  | \
            DS_RETURN_DNS_NAME )

// public\sdk\inc\dtbase.h
#define DECLARE_GET_CAPABILITIES(Caps)\
STDMETHODIMP get_Capabilities(long *pVal) { if (DXIsBadWritePtr(pVal, sizeof(*pVal))) return E_POINTER; *pVal = Caps; return S_OK; }

// public\sdk\inc\dxclrhlp.h
#define SIZE_OF_COLOR_TABLE (sizeof(rgColorNames) / sizeof(COLORVALUE_PAIR))
#define SIZE_OF_SYSTEM_COLOR_TABLE (sizeof(rgSystemColorNames) / sizeof(COLORVALUE_PAIR))

// public\sdk\inc\dxhelper.h
#define DXBASESAMPLE_Alloca( ulNumSamples ) \
    (DXBASESAMPLE *)_alloca( (ulNumSamples) * sizeof( DXBASESAMPLE ) )
#define DXSAMPLE_Alloca( ulNumSamples ) \
    (DXSAMPLE *)_alloca( (ulNumSamples) * sizeof( DXSAMPLE ) )
#define DXPMSAMPLE_Alloca( ulNumSamples ) \
    (DXPMSAMPLE *)_alloca( (ulNumSamples) * sizeof( DXPMSAMPLE ) )
#define DX_IS_BAD_OPTIONAL_WRITE_PTR(p) ((p) && DXIsBadWritePtr(p, sizeof(p)))
#define DX_IS_BAD_OPTIONAL_READ_PTR(p) ((p) && DXIsBadReadPtr(p, sizeof(p)))

// public\sdk\inc\dxtmsft.h
#define IDXTMetaPageTurn_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IDXTMetaPageTurn_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IDXTMetaPageTurn_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IDXTMetaPageTurn_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IDXTMetaPageTurn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDXTMetaPageTurn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDXTMetaPageTurn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IDXTMetaPageTurn_get_Capabilities(This,pVal)	\
    (This)->lpVtbl -> get_Capabilities(This,pVal)
#define IDXTMetaPageTurn_get_Progress(This,pVal)	\
    (This)->lpVtbl -> get_Progress(This,pVal)
#define IDXTMetaPageTurn_put_Progress(This,newVal)	\
    (This)->lpVtbl -> put_Progress(This,newVal)
#define IDXTMetaPageTurn_get_StepResolution(This,pVal)	\
    (This)->lpVtbl -> get_StepResolution(This,pVal)
#define IDXTMetaPageTurn_get_Duration(This,pVal)	\
    (This)->lpVtbl -> get_Duration(This,pVal)
#define IDXTMetaPageTurn_put_Duration(This,newVal)	\
    (This)->lpVtbl -> put_Duration(This,newVal)
#define IDXTMetaPageTurn_get_Copyright(This,pVal)	\
    (This)->lpVtbl -> get_Copyright(This,pVal)
#define IDXTMetaPageTurn_put_Copyright(This,newVal)	\
    (This)->lpVtbl -> put_Copyright(This,newVal)

// public\sdk\inc\dxtmsft3.h
#define IDXTText3D_get_XAlign(This,pbstr)	\
    (This)->lpVtbl -> get_XAlign(This,pbstr)
#define IDXTText3D_put_XAlign(This,pbstr)	\
    (This)->lpVtbl -> put_XAlign(This,pbstr)
#define IDXTText3D_get_YAlign(This,pbstr)	\
    (This)->lpVtbl -> get_YAlign(This,pbstr)
#define IDXTText3D_put_YAlign(This,pbstr)	\
    (This)->lpVtbl -> put_YAlign(This,pbstr)
#define IDXTText3D_get_ZAlign(This,pbstr)	\
    (This)->lpVtbl -> get_ZAlign(This,pbstr)
#define IDXTText3D_put_ZAlign(This,pbstr)	\
    (This)->lpVtbl -> put_ZAlign(This,pbstr)

// public\sdk\inc\dxtrans.h
#define IDXSurfaceModifier_SetBackground(This,pSurface)	\
    (This)->lpVtbl -> SetBackground(This,pSurface)
#define IDXSurfaceModifier_GetBackground(This,ppSurface)	\
    (This)->lpVtbl -> GetBackground(This,ppSurface)
#define IDXSurfaceModifier_SetForeground(This,pSurface,bTile,pOrigin)	\
    (This)->lpVtbl -> SetForeground(This,pSurface,bTile,pOrigin)
#define IDXSurfaceModifier_GetForeground(This,ppSurface,pbTile,pOrigin)	\
    (This)->lpVtbl -> GetForeground(This,ppSurface,pbTile,pOrigin)

// public\sdk\inc\encdec.h
#define IDTFilter_get_BlockedRatingAttributes(This,enSystem,enLevel,plbfEnAttr)	\
    (This)->lpVtbl -> get_BlockedRatingAttributes(This,enSystem,enLevel,plbfEnAttr)
#define IDTFilter_put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs)	\
    (This)->lpVtbl -> put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs)
#define IDTFilter_get_BlockUnRated(This,pfBlockUnRatedShows)	\
    (This)->lpVtbl -> get_BlockUnRated(This,pfBlockUnRatedShows)
#define IDTFilter_put_BlockUnRated(This,fBlockUnRatedShows)	\
    (This)->lpVtbl -> put_BlockUnRated(This,fBlockUnRatedShows)
#define IDTFilter_get_BlockUnRatedDelay(This,pmsecsDelayBeforeBlock)	\
    (This)->lpVtbl -> get_BlockUnRatedDelay(This,pmsecsDelayBeforeBlock)
#define IDTFilter_put_BlockUnRatedDelay(This,msecsDelayBeforeBlock)	\
    (This)->lpVtbl -> put_BlockUnRatedDelay(This,msecsDelayBeforeBlock)

// public\sdk\inc\esebkmsg.h
#define hrBFPageNotFound                 ((HRESULT)0x880000C9L)
#define hrInvalidCodePage                ((HRESULT)0xC8000427L)
#define hrDatabaseInvalidPages           ((HRESULT)0xC80004B5L)

// public\sdk\inc\except.hxx
#define END_MULTINHERITED_CONSTRUCTION(class, base1)    \
                                                        \
        base1::_Activate(sizeof(class), &class::_ObjectUnwind);
#define END_CONSTRUCTION(class)                                 \
                                                                \
        _Activate( sizeof(class), &class::_ObjectUnwind );

// public\sdk\inc\faxcom.h
#define IFaxServer_get_ServerCoverpage(This,pVal)	\
    (This)->lpVtbl -> get_ServerCoverpage(This,pVal)
#define IFaxServer_put_ServerCoverpage(This,newVal)	\
    (This)->lpVtbl -> put_ServerCoverpage(This,newVal)
#define IFaxStatus_get_CurrentPage(This,pVal)	\
    (This)->lpVtbl -> get_CurrentPage(This,pVal)
#define IFaxStatus_get_PageCount(This,pVal)	\
    (This)->lpVtbl -> get_PageCount(This,pVal)
#define IFaxDoc_get_CoverpageName(This,pVal)	\
    (This)->lpVtbl -> get_CoverpageName(This,pVal)
#define IFaxDoc_put_CoverpageName(This,newVal)	\
    (This)->lpVtbl -> put_CoverpageName(This,newVal)
#define IFaxDoc_get_SendCoverpage(This,pVal)	\
    (This)->lpVtbl -> get_SendCoverpage(This,pVal)
#define IFaxDoc_put_SendCoverpage(This,newVal)	\
    (This)->lpVtbl -> put_SendCoverpage(This,newVal)
#define IFaxDoc_get_ServerCoverpage(This,pVal)	\
    (This)->lpVtbl -> get_ServerCoverpage(This,pVal)
#define IFaxDoc_put_ServerCoverpage(This,newVal)	\
    (This)->lpVtbl -> put_ServerCoverpage(This,newVal)
#define IFaxDoc_get_CoverpageNote(This,pVal)	\
    (This)->lpVtbl -> get_CoverpageNote(This,pVal)
#define IFaxDoc_put_CoverpageNote(This,newVal)	\
    (This)->lpVtbl -> put_CoverpageNote(This,newVal)
#define IFaxDoc_get_CoverpageSubject(This,pVal)	\
    (This)->lpVtbl -> get_CoverpageSubject(This,pVal)
#define IFaxDoc_put_CoverpageSubject(This,newVal)	\
    (This)->lpVtbl -> put_CoverpageSubject(This,newVal)
#define IFaxJob_get_PageCount(This,pVal)	\
    (This)->lpVtbl -> get_PageCount(This,pVal)

// public\sdk\inc\faxcomex.h
#define IFaxJobStatus_get_Pages(This,plPages)	\
    (This)->lpVtbl -> get_Pages(This,plPages)
#define IFaxJobStatus_get_CurrentPage(This,plCurrentPage)	\
    (This)->lpVtbl -> get_CurrentPage(This,plCurrentPage)
#define IFaxDocument_get_CoverPage(This,pbstrCoverPage)	\
    (This)->lpVtbl -> get_CoverPage(This,pbstrCoverPage)
#define IFaxDocument_put_CoverPage(This,bstrCoverPage)	\
    (This)->lpVtbl -> put_CoverPage(This,bstrCoverPage)
#define IFaxDocument_get_CoverPageType(This,pCoverPageType)	\
    (This)->lpVtbl -> get_CoverPageType(This,pCoverPageType)
#define IFaxDocument_put_CoverPageType(This,CoverPageType)	\
    (This)->lpVtbl -> put_CoverPageType(This,CoverPageType)
#define IFaxIncomingQueue_get_Blocked(This,pbBlocked)	\
    (This)->lpVtbl -> get_Blocked(This,pbBlocked)
#define IFaxIncomingQueue_put_Blocked(This,bBlocked)	\
    (This)->lpVtbl -> put_Blocked(This,bBlocked)
#define IFaxOutgoingQueue_get_Blocked(This,pbBlocked)	\
    (This)->lpVtbl -> get_Blocked(This,pbBlocked)
#define IFaxOutgoingQueue_put_Blocked(This,bBlocked)	\
    (This)->lpVtbl -> put_Blocked(This,bBlocked)
#define IFaxOutgoingQueue_get_AllowPersonalCoverPages(This,pbAllowPersonalCoverPages)	\
    (This)->lpVtbl -> get_AllowPersonalCoverPages(This,pbAllowPersonalCoverPages)
#define IFaxOutgoingQueue_put_AllowPersonalCoverPages(This,bAllowPersonalCoverPages)	\
    (This)->lpVtbl -> put_AllowPersonalCoverPages(This,bAllowPersonalCoverPages)
#define IFaxIncomingMessage_get_Pages(This,plPages)	\
    (This)->lpVtbl -> get_Pages(This,plPages)
#define IFaxOutgoingJob_get_Pages(This,plPages)	\
    (This)->lpVtbl -> get_Pages(This,plPages)
#define IFaxOutgoingJob_get_CurrentPage(This,plCurrentPage)	\
    (This)->lpVtbl -> get_CurrentPage(This,plCurrentPage)
#define IFaxOutgoingMessage_get_Pages(This,plPages)	\
    (This)->lpVtbl -> get_Pages(This,plPages)
#define IFaxIncomingJob_get_CurrentPage(This,plCurrentPage)	\
    (This)->lpVtbl -> get_CurrentPage(This,plCurrentPage)

// public\sdk\inc\faxmmc.h
#define FAXSRV_MAX_GUID_LEN              sizeof(FAXSRV_DEVICE_NODETYPE_GUID_STR)/sizeof(WCHAR)

// public\sdk\inc\fltdefs.h
#define FILTERSIZE                                      \
    (sizeof(PF_FILTER_DESCRIPTOR) -                     \
     (DWORD)(&((PPF_FILTER_DESCRIPTOR)0)->SrcAddr))

// public\sdk\inc\guiddef.h
#define IsEqualGUID(rguid1, rguid2) (!memcmp(rguid1, rguid2, sizeof(GUID)))

// public\sdk\inc\helpcenterinterfaces.h
#define IPCHHelpSession_VisitedHelpPages(This,hsMode,ppC)	\
    (This)->lpVtbl -> VisitedHelpPages(This,hsMode,ppC)

// public\sdk\inc\helpserviceinterfaces.h
#define ISAFIncident_get_StartPage(This,pbstrVal)	\
    (This)->lpVtbl -> get_StartPage(This,pbstrVal)
#define ISAFIncident_put_StartPage(This,bstrVal)	\
    (This)->lpVtbl -> put_StartPage(This,bstrVal)
#define IPCHSlaveProcess_OpenBlockingStream(This,bstrURL,ppvObject)	\
    (This)->lpVtbl -> OpenBlockingStream(This,bstrURL,ppvObject)

// public\sdk\inc\hidpi.h
#define HidP_IsSameUsageAndPage(u1, u2) ((* (PULONG) &u1) == (* (PULONG) &u2))

// public\sdk\inc\ia64inst.h
#define BUNDLE_SIZE sizeof(IA64_INSTRUCTION)

// public\sdk\inc\iads.h
#define IADsUser_get_TelephonePager(This,retval)	\
    (This)->lpVtbl -> get_TelephonePager(This,retval)
#define IADsUser_put_TelephonePager(This,vTelephonePager)	\
    (This)->lpVtbl -> put_TelephonePager(This,vTelephonePager)
#define IADsUser_get_HomePage(This,retval)	\
    (This)->lpVtbl -> get_HomePage(This,retval)
#define IADsUser_put_HomePage(This,bstrHomePage)	\
    (This)->lpVtbl -> put_HomePage(This,bstrHomePage)
#define IADsPrintQueue_get_BannerPage(This,retval)	\
    (This)->lpVtbl -> get_BannerPage(This,retval)
#define IADsPrintQueue_put_BannerPage(This,bstrBannerPage)	\
    (This)->lpVtbl -> put_BannerPage(This,bstrBannerPage)
#define IADsPrintJob_get_TotalPages(This,retval)	\
    (This)->lpVtbl -> get_TotalPages(This,retval)
#define IADsPrintJobOperations_get_PagesPrinted(This,retval)	\
    (This)->lpVtbl -> get_PagesPrinted(This,retval)

// public\sdk\inc\iextag.h
#define IHomePage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHomePage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHomePage_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHomePage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHomePage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHomePage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHomePage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IHomePage_navigateHomePage(This)	\
    (This)->lpVtbl -> navigateHomePage(This)
#define IHomePage_setHomePage(This,bstrURL)	\
    (This)->lpVtbl -> setHomePage(This,bstrURL)
#define IHomePage_isHomePage(This,bstrURL,p)	\
    (This)->lpVtbl -> isHomePage(This,bstrURL,p)
#define ILayoutRect_put_honorPageBreaks(This,v)	\
    (This)->lpVtbl -> put_honorPageBreaks(This,v)
#define ILayoutRect_get_honorPageBreaks(This,p)	\
    (This)->lpVtbl -> get_honorPageBreaks(This,p)
#define ILayoutRect_put_honorPageRules(This,v)	\
    (This)->lpVtbl -> put_honorPageRules(This,v)
#define ILayoutRect_get_honorPageRules(This,p)	\
    (This)->lpVtbl -> get_honorPageRules(This,p)
#define ITemplatePrinter_printBlankPage(This)	\
    (This)->lpVtbl -> printBlankPage(This)
#define ITemplatePrinter_printPage(This,pElemDisp)	\
    (This)->lpVtbl -> printPage(This,pElemDisp)
#define ITemplatePrinter_showPageSetupDialog(This,p)	\
    (This)->lpVtbl -> showPageSetupDialog(This,p)
#define ITemplatePrinter_put_selectedPages(This,v)	\
    (This)->lpVtbl -> put_selectedPages(This,v)
#define ITemplatePrinter_get_selectedPages(This,p)	\
    (This)->lpVtbl -> get_selectedPages(This,p)
#define ITemplatePrinter_put_currentPage(This,v)	\
    (This)->lpVtbl -> put_currentPage(This,v)
#define ITemplatePrinter_get_currentPage(This,p)	\
    (This)->lpVtbl -> get_currentPage(This,p)
#define ITemplatePrinter_put_currentPageAvail(This,v)	\
    (This)->lpVtbl -> put_currentPageAvail(This,v)
#define ITemplatePrinter_get_currentPageAvail(This,p)	\
    (This)->lpVtbl -> get_currentPageAvail(This,p)
#define ITemplatePrinter_put_pageFrom(This,v)	\
    (This)->lpVtbl -> put_pageFrom(This,v)
#define ITemplatePrinter_get_pageFrom(This,p)	\
    (This)->lpVtbl -> get_pageFrom(This,p)
#define ITemplatePrinter_put_pageTo(This,v)	\
    (This)->lpVtbl -> put_pageTo(This,v)
#define ITemplatePrinter_get_pageTo(This,p)	\
    (This)->lpVtbl -> get_pageTo(This,p)
#define ITemplatePrinter_get_pageWidth(This,p)	\
    (This)->lpVtbl -> get_pageWidth(This,p)
#define ITemplatePrinter_get_pageHeight(This,p)	\
    (This)->lpVtbl -> get_pageHeight(This,p)
#define ITemplatePrinter_updatePageStatus(This,p)	\
    (This)->lpVtbl -> updatePageStatus(This,p)
#define ITemplatePrinter2_printBlankPage(This)	\
    (This)->lpVtbl -> printBlankPage(This)
#define ITemplatePrinter2_printPage(This,pElemDisp)	\
    (This)->lpVtbl -> printPage(This,pElemDisp)
#define ITemplatePrinter2_showPageSetupDialog(This,p)	\
    (This)->lpVtbl -> showPageSetupDialog(This,p)
#define ITemplatePrinter2_put_selectedPages(This,v)	\
    (This)->lpVtbl -> put_selectedPages(This,v)
#define ITemplatePrinter2_get_selectedPages(This,p)	\
    (This)->lpVtbl -> get_selectedPages(This,p)
#define ITemplatePrinter2_put_currentPage(This,v)	\
    (This)->lpVtbl -> put_currentPage(This,v)
#define ITemplatePrinter2_get_currentPage(This,p)	\
    (This)->lpVtbl -> get_currentPage(This,p)
#define ITemplatePrinter2_put_currentPageAvail(This,v)	\
    (This)->lpVtbl -> put_currentPageAvail(This,v)
#define ITemplatePrinter2_get_currentPageAvail(This,p)	\
    (This)->lpVtbl -> get_currentPageAvail(This,p)
#define ITemplatePrinter2_put_pageFrom(This,v)	\
    (This)->lpVtbl -> put_pageFrom(This,v)
#define ITemplatePrinter2_get_pageFrom(This,p)	\
    (This)->lpVtbl -> get_pageFrom(This,p)
#define ITemplatePrinter2_put_pageTo(This,v)	\
    (This)->lpVtbl -> put_pageTo(This,v)
#define ITemplatePrinter2_get_pageTo(This,p)	\
    (This)->lpVtbl -> get_pageTo(This,p)
#define ITemplatePrinter2_get_pageWidth(This,p)	\
    (This)->lpVtbl -> get_pageWidth(This,p)
#define ITemplatePrinter2_get_pageHeight(This,p)	\
    (This)->lpVtbl -> get_pageHeight(This,p)
#define ITemplatePrinter2_updatePageStatus(This,p)	\
    (This)->lpVtbl -> updatePageStatus(This,p)
#define IHeaderFooter_put_page(This,v)	\
    (This)->lpVtbl -> put_page(This,v)
#define IHeaderFooter_get_page(This,p)	\
    (This)->lpVtbl -> get_page(This,p)
#define IHeaderFooter_put_pageTotal(This,v)	\
    (This)->lpVtbl -> put_pageTotal(This,v)
#define IHeaderFooter_get_pageTotal(This,p)	\
    (This)->lpVtbl -> get_pageTotal(This,p)
#define IScrollBar_put_block(This,v)	\
    (This)->lpVtbl -> put_block(This,v)
#define IScrollBar_get_block(This,p)	\
    (This)->lpVtbl -> get_block(This,p)
#define ISliderBar_put_block(This,v)	\
    (This)->lpVtbl -> put_block(This,v)
#define ISliderBar_get_block(This,p)	\
    (This)->lpVtbl -> get_block(This,p)

// public\sdk\inc\imapi.h
#define IDiscRecorder_QueryMediaInfo(This,pbSessions,pbLastTrack,ulStartAddress,ulNextWritable,ulFreeBlocks)	\
    (This)->lpVtbl -> QueryMediaInfo(This,pbSessions,pbLastTrack,ulStartAddress,ulNextWritable,ulFreeBlocks)
#define IRedbookDiscMaster_GetTotalAudioBlocks(This,pnBlocks)	\
    (This)->lpVtbl -> GetTotalAudioBlocks(This,pnBlocks)
#define IRedbookDiscMaster_GetUsedAudioBlocks(This,pnBlocks)	\
    (This)->lpVtbl -> GetUsedAudioBlocks(This,pnBlocks)
#define IRedbookDiscMaster_GetAvailableAudioTrackBlocks(This,pnBlocks)	\
    (This)->lpVtbl -> GetAvailableAudioTrackBlocks(This,pnBlocks)
#define IRedbookDiscMaster_GetAudioBlockSize(This,pnBlockBytes)	\
    (This)->lpVtbl -> GetAudioBlockSize(This,pnBlockBytes)
#define IRedbookDiscMaster_CreateAudioTrack(This,nBlocks)	\
    (This)->lpVtbl -> CreateAudioTrack(This,nBlocks)
#define IRedbookDiscMaster_AddAudioTrackBlocks(This,pby,cb)	\
    (This)->lpVtbl -> AddAudioTrackBlocks(This,pby,cb)
#define IJolietDiscMaster_GetTotalDataBlocks(This,pnBlocks)	\
    (This)->lpVtbl -> GetTotalDataBlocks(This,pnBlocks)
#define IJolietDiscMaster_GetUsedDataBlocks(This,pnBlocks)	\
    (This)->lpVtbl -> GetUsedDataBlocks(This,pnBlocks)
#define IJolietDiscMaster_GetDataBlockSize(This,pnBlockBytes)	\
    (This)->lpVtbl -> GetDataBlockSize(This,pnBlockBytes)
#define IDiscMasterProgressEvents_NotifyBlockProgress(This,nCompleted,nTotal)	\
    (This)->lpVtbl -> NotifyBlockProgress(This,nCompleted,nTotal)
#define IBurnEngine_GetSessionInfo(This,pbsessions,pblasttrack,ulstartaddress,ulnextwritable,ulfreeblocks)	\
    (This)->lpVtbl -> GetSessionInfo(This,pbsessions,pblasttrack,ulstartaddress,ulnextwritable,ulfreeblocks)

// public\sdk\inc\imnxport.h
#define IRangeList_Save(This,ppbDestination,pulSizeOfDestination)	\
    (This)->lpVtbl -> Save(This,ppbDestination,pulSizeOfDestination)
#define IRangeList_Load(This,pbSource,ulSizeOfSource)	\
    (This)->lpVtbl -> Load(This,pbSource,ulSizeOfSource)
#define IIMAPTransport_ResizeMsgSeqNumTable(This,dwSizeOfMbox)	\
    (This)->lpVtbl -> ResizeMsgSeqNumTable(This,dwSizeOfMbox)
#define IIMAPTransport2_ResizeMsgSeqNumTable(This,dwSizeOfMbox)	\
    (This)->lpVtbl -> ResizeMsgSeqNumTable(This,dwSizeOfMbox)
#define IIMAPTransport2_SetDefaultCP(This,dwTranslateFlags,uiCodePage)	\
    (This)->lpVtbl -> SetDefaultCP(This,dwTranslateFlags,uiCodePage)

// public\sdk\inc\iprtrmib.h
#define SIZEOF_IFTABLE(X) (FIELD_OFFSET(MIB_IFTABLE,table[0]) + ((X) * sizeof(MIB_IFROW)) + ALIGN_SIZE)
#define SIZEOF_UDPTABLE(X) (FIELD_OFFSET(MIB_UDPTABLE, table[0]) + ((X) * sizeof(MIB_UDPROW)) + ALIGN_SIZE)
#define SIZEOF_TCPTABLE(X) (FIELD_OFFSET(MIB_TCPTABLE,table[0]) + ((X) * sizeof(MIB_TCPROW)) + ALIGN_SIZE)
#define SIZEOF_IPADDRTABLE(X) (FIELD_OFFSET(MIB_IPADDRTABLE,table[0]) + ((X) * sizeof(MIB_IPADDRROW)) + ALIGN_SIZE)
#define SIZEOF_IPFORWARDTABLE(X) (FIELD_OFFSET(MIB_IPFORWARDTABLE,table[0]) + ((X) * sizeof(MIB_IPFORWARDROW)) + ALIGN_SIZE)
#define SIZEOF_IPNETTABLE(X) (FIELD_OFFSET(MIB_IPNETTABLE, table[0]) + ((X) * sizeof(MIB_IPNETROW)) + ALIGN_SIZE)
#define SIZEOF_MIB_MFE(X)             \
    (SIZEOF_BASIC_MIB_MFE + ((X) * sizeof(MIB_IPMCAST_OIF)))
#define SIZEOF_MIB_MFE_STATS(X)       \
    (SIZEOF_BASIC_MIB_MFE_STATS + ((X) * sizeof(MIB_IPMCAST_OIF_STATS)))
#define SIZEOF_MIB_MFE_STATS_EX(X)       \
    (SIZEOF_BASIC_MIB_MFE_STATS_EX + ((X) * sizeof(MIB_IPMCAST_OIF_STATS)))
#define SIZEOF_MCAST_IF_TABLE(X) (FIELD_OFFSET(MIB_IPMCAST_IF_TABLE,table[0]) + ((X) * sizeof(MIB_IPMCAST_IF_ENTRY)) + ALIGN_SIZE)
#define SIZEOF_BOUNDARY_TABLE(X) (FIELD_OFFSET(MIB_IPMCAST_BOUNDARY_TABLE,table[0]) + ((X) * sizeof(MIB_IPMCAST_BOUNDARY)) + ALIGN_SIZE)
#define MIB_INFO_SIZE(S)                \
    (MAX_MIB_OFFSET + sizeof(S))
#define MIB_INFO_SIZE_IN_DWORDS(S)      \
    ((MIB_INFO_SIZE(S))/sizeof(DWORD) + 1)

// public\sdk\inc\ks.h
#define DEFINE_KSPROPERTY_ITEM_GENERAL_COMPONENTID(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_GENERAL_COMPONENTID,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSCOMPONENTID),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSMETHOD_ITEM_STREAMIO_READ(Handler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_STREAMIO_READ,\
        KSMETHOD_TYPE_WRITE,\
        (Handler),\
        sizeof(KSMETHOD),\
        0,\
        NULL)
#define DEFINE_KSMETHOD_ITEM_STREAMIO_WRITE(Handler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_STREAMIO_WRITE,\
        KSMETHOD_TYPE_READ,\
        (Handler),\
        sizeof(KSMETHOD),\
        0,\
        NULL)
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
#define DEFINE_KSPROPERTY_ITEM_TOPOLOGY_CATEGORIES(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_TOPOLOGY_CATEGORIES,\
        (Handler),\
        sizeof(KSPROPERTY),\
        0,\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_TOPOLOGY_NODES(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_TOPOLOGY_NODES,\
        (Handler),\
        sizeof(KSPROPERTY),\
        0,\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_TOPOLOGY_CONNECTIONS(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_TOPOLOGY_CONNECTIONS,\
        (Handler),\
        sizeof(KSPROPERTY),\
        0,\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_TOPOLOGY_NAME(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_TOPOLOGY_NAME,\
        (Handler),\
        sizeof(KSP_NODE),\
        0,\
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
#define DEFINE_KSPROPERTY_ITEM_QUALITY_REPORT(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_QUALITY_REPORT,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(KSQUALITY),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_QUALITY_ERROR(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_QUALITY_ERROR,\
        (GetHandler),\
        sizeof(KSPROPERTY),\
        sizeof(KSERROR),\
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
#define DEFINE_KSPROPERTY_ITEM_CONNECTION_ALLOCATORFRAMING_EX(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CONNECTION_ALLOCATORFRAMING_EX,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSALLOCATOR_FRAMING_EX),\
        NULL, NULL, 0, NULL, NULL, 0)
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
        sizeof(int),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_CONNECTION_STARTAT(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_CONNECTION_STARTAT,\
        NULL,\
        sizeof(KSPROPERTY),\
        sizeof(KSRELATIVEEVENT),\
        (Handler),\
        NULL, 0, NULL, NULL, 0)
#define INITIALIZE_SIMPLE_FRAMING_EX(FramingExPointer, P_MemoryType, P_Flags, P_Frames, P_Alignment, P_MinFrameSize, P_MaxFrameSize) \
{\
    KS_COMPRESSION *KsCompression = &FramingExPointer->OutputCompression;\
    KS_FRAMING_RANGE *KsFramingRange = &FramingExPointer->FramingItem[0].PhysicalRange;\
    KS_FRAMING_RANGE_WEIGHTED *KsFramingRangeWeighted = &FramingExPointer->FramingItem[0].FramingRange;\
    FramingExPointer->CountItems = 1;\
    FramingExPointer->PinFlags = 0;\
    SetDefaultKsCompression(KsCompression);\
    FramingExPointer->PinWeight = 0;\
    FramingExPointer->FramingItem[0].MemoryType = P_MemoryType;\
    FramingExPointer->FramingItem[0].BusType = KS_TYPE_DONT_CARE;\
    FramingExPointer->FramingItem[0].MemoryFlags = 0;\
    FramingExPointer->FramingItem[0].BusFlags = 0;\
    FramingExPointer->FramingItem[0].Flags = P_Flags;\
    FramingExPointer->FramingItem[0].Frames = P_Frames;\
    FramingExPointer->FramingItem[0].FileAlignment = P_Alignment;\
    FramingExPointer->FramingItem[0].MemoryTypeWeight = 0;\
    SetDontCareKsFramingRange(KsFramingRange);\
    SetKsFramingRangeWeighted(KsFramingRangeWeighted, P_MinFrameSize, P_MaxFrameSize);\
}
#define DEFINE_KSMETHOD_ITEM_STREAMALLOCATOR_ALLOC(Handler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_STREAMALLOCATOR_ALLOC,\
        KSMETHOD_TYPE_WRITE,\
        (Handler),\
        sizeof(KSMETHOD),\
        sizeof(PVOID),\
        NULL)
#define DEFINE_KSMETHOD_ITEM_STREAMALLOCATOR_FREE(Handler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_STREAMALLOCATOR_FREE,\
        KSMETHOD_TYPE_READ,\
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
#define DEFINE_KSPROPERTY_ITEM_STREAMALLOCATOR_STATUS(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_STREAMALLOCATOR_STATUS,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(KSSTREAMALLOCATOR_STATUS),\
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
#define DEFINE_KSCREATE_ITEMEX(DispatchCreate, TypeName, Context, Flags)\
{\
    (DispatchCreate),\
    (PVOID)(Context),\
    {\
        sizeof(TypeName) - sizeof(UNICODE_NULL),\
        sizeof(TypeName),\
        (PWCHAR)(TypeName)\
    },\
    NULL, (Flags)\
}
#define KsEdit(Object,PointerToPointer,Tag)\
    _KsEdit(\
        (Object)->Bag,\
        (PVOID*)(PointerToPointer),\
        sizeof(**(PointerToPointer)),\
        sizeof(**(PointerToPointer)),\
        (Tag))

// public\sdk\inc\ksi.h
#define DEFINE_KSPROPERTY_ITEM_SERVICE_BUILDCACHE(SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_SERVICE_BUILDCACHE,\
        NULL,\
        sizeof(KSPROPERTY),\
        sizeof(L"\\\\?\\"),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_SERVICE_MERIT(SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_SERVICE_MERIT,\
        NULL,\
        sizeof(KSPROPERTY),\
        sizeof(ULONG) + sizeof(L"\\\\?\\"),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)

// public\sdk\inc\ksmedia.h
#define IS_VALID_WAVEFORMATEX_GUID(Guid)\
    (!memcmp(((PUSHORT)&KSDATAFORMAT_SUBTYPE_WAVEFORMATEX) + 1, ((PUSHORT)(Guid)) + 1, sizeof(GUID) - sizeof(USHORT)))
#define KSAUDIO_SPEAKER_SURROUND        (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | \
                                         SPEAKER_FRONT_CENTER | SPEAKER_BACK_CENTER)
#define KS_SIZE_EGA_PALETTE (KS_iEGA_COLORS * sizeof(KS_RGBQUAD))
#define KS_SIZE_PALETTE (KS_iPALETTE_COLORS * sizeof(KS_RGBQUAD))
#define KS_SIZE_MASKS (KS_iMASK_COLORS * sizeof(DWORD))
#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_INTERESTS(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_OVERLAYUPDATE_INTERESTS,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(ULONG),\
        NULL, NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_PALETTE(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_OVERLAYUPDATE_PALETTE,\
        NULL,\
        sizeof(KSPROPERTY),\
        0,\
        (Handler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_COLORKEY(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_OVERLAYUPDATE_COLORKEY,\
        NULL,\
        sizeof(KSPROPERTY),\
        sizeof(COLORKEY),\
        (Handler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_CLIPLIST(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_OVERLAYUPDATE_CLIPLIST,\
        NULL,\
        sizeof(KSPROPERTY),\
        2 * sizeof(RECT) + sizeof(RGNDATAHEADER),\
        (Handler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_VIDEOPOSITION(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_OVERLAYUPDATE_VIDEOPOSITION,\
        NULL,\
        sizeof(KSPROPERTY),\
        2 * sizeof(RECT),\
        (Handler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_DISPLAYCHANGE(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_OVERLAYUPDATE_DISPLAYCHANGE,\
        NULL,\
        sizeof(KSPROPERTY),\
        sizeof(KSDISPLAYCHANGE),\
        (Handler),\
        NULL, 0, NULL, NULL, 0)
#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_COLORREF(Handler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_OVERLAYUPDATE_COLORREF,\
        (Handler),\
        sizeof(KSPROPERTY),\
        sizeof(COLORREF),\
        NULL,\
        NULL, 0, NULL, NULL, 0)

// public\sdk\inc\kxalpha.h
#define LEAF_ENTRY(Name)                \
        .text;                          \
        .align  4;                      \
        .globl  Name;                   \
        .ent    Name, 0;                \
Name:;                                  \
        .frame  sp, 0, ra;              \
        .prologue 0;
#define NESTED_ENTRY(Name, fsize, retrg) \
        .text;                          \
        .align  4;                      \
        .globl  Name;                   \
        .ent    Name, 0;                \
Name:;                                  \
        .frame  sp, fsize, retrg;

// public\sdk\inc\kxia64.h
#define RNAT_ALIGNMENT           (NAT_BITS_PER_RNAT_REG << 3)
#define RR_PS_VE  ( (PAGE_SHIFT<<RR_PS) | (1<<RR_VE) )

// public\sdk\inc\lendian.hpp
#define MAKE_TEMPLATE(size,type,sfx)                            \
template<class BASE>                                            \
class LEndian##sfx##size                                        \
{                                                               \
  protected:                                                    \
    type data[ size / sizeof(type) ];                           \
                                                                \
  public:                                                       \
                                                                \
    GROUP( signed char,      size, GET##sfx, SET##sfx, sfx )    \
    GROUP( short,            size, GET##sfx, SET##sfx, sfx )    \
    GROUP( int,              size, GET##sfx, SET##sfx, sfx )    \
    GROUP( wchar_t,          size, GET##sfx, SET##sfx, sfx )    \
    GROUP( long,             size, GET##sfx, SET##sfx, sfx )    \
    GROUP( __int64,          size, GET##sfx, SET##sfx, sfx )    \
    GROUP( unsigned char,    size, GET##sfx, SET##sfx, sfx )    \
    GROUP( unsigned short,   size, GET##sfx, SET##sfx, sfx )    \
    GROUP( unsigned int,     size, GET##sfx, SET##sfx, sfx )    \
    GROUP( unsigned long,    size, GET##sfx, SET##sfx, sfx )    \
    GROUP( unsigned __int64, size, GET##sfx, SET##sfx, sfx )    \
}
#define MAKE_LENDIAN_TYPE(base,size)            \
   typedef LEndian0##size<base>   base##_LENDIAN; \
   typedef LEndian0##size<base>   base##_LENDIAN_UNALIGNED
#define MAKE_LENDIAN_TYPE(base,size)            \
   typedef LEndian##size<base>   base##_LENDIAN; \
   typedef LEndian##size<base>   base##_LENDIAN_UNALIGNED
#define MAKE_LENDIAN64_TYPE(base,size)                          \
  typedef LEndian64##size<base> base##_LENDIAN64;                \
  typedef LEndian64##size<base> base##_LENDIAN64_UNALIGNED
#define MAKE_LENDIANPTR_TYPE(base)                              \
  typedef LEndianPtr<base>      base##_LENDIANPTR;               \
  typedef LEndianPtr<base>      base##_LENDIANPTR_UNALIGNED

// public\sdk\inc\lmalert.h
#define ALERT_OTHER_INFO(x)    ((LPBYTE)(x) + sizeof(STD_ALERT))
#define ALERT_VAR_DATA(p)      ((LPBYTE)(p) + sizeof(*p))

// public\sdk\inc\lmcons.h
#define MAXDEVENTRIES (sizeof (int)*8)  // Max number of device entries

// public\sdk\inc\lpmapi.h
#define ScopeCnt(scp)   ((ObjLength(scp)-sizeof(RsvpObjHdr))/sizeof(struct in_addr))
#define ScopeLen(cnt)   (cnt*sizeof(struct in_addr)+sizeof(RsvpObjHdr))
#define PD_HDR_LEN  sizeof(POLICY_DATA)
#define PE_HDR_LEN  (2 * sizeof(USHORT))
#define Intserv_Obj_size(x) (((IntServMainHdr *)(x))->ismh_len32b * 4 + \
                            sizeof(IntServMainHdr) + sizeof(RsvpObjHdr))
#define gtspec_len      (sizeof(GenTspec) - sizeof(IntServServiceHdr))
#define CLspec_len      (sizeof(CtrlLoadFlowspec) - sizeof(IntServServiceHdr))
#define Gspec_len       (sizeof(GuarFlowSpec) - sizeof(IntServServiceHdr))
#define GEN_ADSPEC_LEN (sizeof(Object_header) + sizeof(IS_adsbody_t ) )
#define ID_ERR_OBJ_HDR_LEN     (sizeof(ID_ERROR_OBJECT) - 4 * sizeof(UCHAR) )

// public\sdk\inc\macfile.h
#define AFP_SERVER_PARMNUM_ALL				( AFP_SERVER_PARMNUM_LOGINMSG 		\
											| AFP_SERVER_PARMNUM_MAX_SESSIONS	\
											| AFP_SERVER_PARMNUM_OPTIONS 		\
											| AFP_SERVER_PARMNUM_NAME			\
											| AFP_SERVER_PARMNUM_PAGEMEMLIM		\
											| AFP_SERVER_PARMNUM_NONPAGEMEMLIM	\
											| AFP_SERVER_PARMNUM_CODEPAGE       \
                                            | AFP_SERVER_GUEST_ACCT_NOTIFY)

// public\sdk\inc\mapidbg.h
#define dimensionof(a) 		(sizeof(a)/sizeof(*(a)))

// public\sdk\inc\mapidefs.h
#define IsEqualMAPIUID(lpuid1, lpuid2)	(!memcmp(lpuid1, lpuid2, sizeof(MAPIUID)))
#define CbNewADRLIST(_centries) \
	(offsetof(ADRLIST,aEntries) + (_centries)*sizeof(ADRENTRY))
#define CbADRLIST(_lpadrlist) \
	(offsetof(ADRLIST,aEntries) + (UINT)(_lpadrlist)->cEntries*sizeof(ADRENTRY))
#define CbNewSRowSet(_crow)		(offsetof(SRowSet,aRow) + (_crow)*sizeof(SRow))
#define CbSRowSet(_lprowset)	(offsetof(SRowSet,aRow) + \
									(UINT)((_lprowset)->cRows*sizeof(SRow)))
#define CbNewSSortOrderSet(_csort) \
	(offsetof(SSortOrderSet,aSort) + (_csort)*sizeof(SSortOrder))
#define CbSSortOrderSet(_lpset) \
	(offsetof(SSortOrderSet,aSort) + \
	(UINT)((_lpset)->cSorts*sizeof(SSortOrder)))

// public\sdk\inc\mapiform.h
#define MAPI_IMAPIVIEWADVISESINK_METHODS(IPURE)                         \
    MAPIMETHOD(OnShutdown)(THIS) IPURE;                                    \
    MAPIMETHOD(OnNewMessage)(THIS) IPURE;                               \
    MAPIMETHOD(OnPrint)(THIS_                                           \
        /*in*/ ULONG dwPageNumber,                                      \
        /*in*/ HRESULT hrStatus) IPURE;                                 \
    MAPIMETHOD(OnSubmitted) (THIS) IPURE;                               \
    MAPIMETHOD(OnSaved) (THIS) IPURE;                                   \

// public\sdk\inc\mapival.h
#define BAD_STANDARD_OBJ( lpObj, prefix, method, lpVtbl) \
	(   IsBadWritePtr( (lpObj), sizeof(*lpObj)) \
	 || IsBadReadPtr( (void *) &(lpObj->lpVtbl->method), sizeof(LPVOID)) \
	 ||( ( LPVOID) (lpObj->lpVtbl->method) != (LPVOID) (prefix##method)))
#define FBadUnknown( lpObj ) \
	(	IsBadReadPtr( (lpObj), sizeof(LPVOID) ) \
	 ||	IsBadReadPtr( (lpObj)->lpVtbl, 3 * sizeof(LPUNKNOWN) ) \
	 ||	IsBadCodePtr( (FARPROC)(lpObj)->lpVtbl->QueryInterface ))
#define FBadQueryInterface( lpObj, riid, ppvObj)	\
	(   IsBadReadPtr( riid, sizeof(IID)) \
	 || IsBadWritePtr( ppvObj, sizeof(LPVOID)))
#define FBadGetLastError( lpObj, hResult, ulFlags, lppMAPIError )\
	(IsBadWritePtr( lppMAPIError, sizeof(LPMAPIERROR)))
#define FBadOpenProperty( lpObj, ulPropTag, lpiid, ulInterfaceOptions, ulFlags \
						, lppUnk) \
	(   IsBadReadPtr( lpiid, sizeof(IID)) \
	 || IsBadWritePtr( lppUnk, sizeof (LPUNKNOWN FAR *)))
#define FBadGetIDsFromNames( lpIPDAT, cPropNames, lppPropNames, ulFlags \
						   , lppPropTags) \
	(   (cPropNames && FBadRglpNameID( lppPropNames, cPropNames)) \
	 || IsBadWritePtr( lppPropTags, sizeof(LPULONG FAR *)))

// public\sdk\inc\mapiwin.h
#define	Cbtszsize(_a)	((lstrlen(_a)+1)*sizeof(TCHAR))
#define	CbtszsizeW(_a)	((lstrlenW(_a) + 1) * sizeof(WCHAR))
#define HexCchOf(_s)	(sizeof(_s)*2+1)
#define HexSizeOf(_s)	(HexCchOf(_s)*sizeof(TCHAR))

// public\sdk\inc\mapiwz.h
#define	WIZ_QUERYNUMPAGES	(WM_USER +10)

// public\sdk\inc\marqinfo.h
#define IMarqueeInfo_GetDocCoords(This,prcView,bGetOnlyIfFullyLoaded,pfFullyLoaded,WidthToFormatPageTo)	\
    (This)->lpVtbl -> GetDocCoords(This,prcView,bGetOnlyIfFullyLoaded,pfFullyLoaded,WidthToFormatPageTo)

// public\sdk\inc\mce.h
#define MCA_EXCEPTION_V2_SIZE sizeof(struct _MCA_EXCEPTION)

// public\sdk\inc\mediaobj.h
#define IMediaObject_GetInputSizeInfo(This,dwInputStreamIndex,pcbSize,pcbMaxLookahead,pcbAlignment)	\
    (This)->lpVtbl -> GetInputSizeInfo(This,dwInputStreamIndex,pcbSize,pcbMaxLookahead,pcbAlignment)
#define IMediaObject_GetOutputSizeInfo(This,dwOutputStreamIndex,pcbSize,pcbAlignment)	\
    (This)->lpVtbl -> GetOutputSizeInfo(This,dwOutputStreamIndex,pcbSize,pcbAlignment)
#define IMediaObject_Lock(This,bLock)	\
    (This)->lpVtbl -> Lock(This,bLock)

// public\sdk\inc\mfc42\afx.h
#define IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew) \
	CRuntimeClass* PASCAL class_name::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	AFX_COMDAT const AFX_DATADEF CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			&class_name::_GetBaseClass, NULL }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); } \
#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew) \
	CRuntimeClass* PASCAL class_name::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	AFX_COMDAT AFX_DATADEF CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			&class_name::_GetBaseClass, NULL }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); } \
#define IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew) \
	AFX_COMDAT const AFX_DATADEF CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); } \
#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew) \
	AFX_DATADEF CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); } \
#define AFX_ZERO_INIT_OBJECT(base_class) \
	memset(((base_class*)this)+1, 0, sizeof(*this) - sizeof(class base_class));

// public\sdk\inc\mfc42\afxctl.h
#define DECLARE_PROPPAGEIDS(class_name) \
	protected: \
		virtual LPCLSID GetPropPageIDs(ULONG& cPropPages);
#define BEGIN_PROPPAGEIDS(class_name, count) \
	static CLSID _rgPropPageIDs_##class_name[count]; \
	AFX_COMDAT ULONG _cPropPages_##class_name = (ULONG)-1; \
	LPCLSID class_name::GetPropPageIDs(ULONG& cPropPages) { \
		if (_cPropPages_##class_name == (ULONG)-1) { \
			_cPropPages_##class_name = count; \
			LPCLSID pIDs = _rgPropPageIDs_##class_name; \
			ULONG iPageMax = count; \
			ULONG iPage = 0;
#define BEGIN_PROPPAGEIDS(class_name, count) \
	static CLSID _rgPropPageIDs_##class_name[count]; \
	static ULONG _cPropPages_##class_name = (ULONG)-1; \
	LPCLSID class_name::GetPropPageIDs(ULONG& cPropPages) { \
		if (_cPropPages_##class_name == (ULONG)-1) { \
			_cPropPages_##class_name = count; \
			LPCLSID pIDs = _rgPropPageIDs_##class_name; \
			ULONG iPageMax = count; \
			ULONG iPage = 0;
#define PROPPAGEID(clsid) \
			ASSERT(iPage < iPageMax); \
			if (iPage < iPageMax) \
				pIDs[iPage++] = clsid;
#define END_PROPPAGEIDS(class_name) \
			ASSERT(iPage == iPageMax); \
		} \
		cPropPages = _cPropPages_##class_name; \
		return _rgPropPageIDs_##class_name; }

// public\sdk\inc\mfc42\afxisapi.h
#define END_PARSE_MAP(theClass) \
	}; \
	UINT PASCAL theClass::GetNumMapEntries() { \
		return sizeof(theClass::_parseEntries) /\
		sizeof(AFX_PARSEMAP_ENTRY); } \

// public\sdk\inc\mfc42\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// public\sdk\inc\mfc42\atlconv.h
#define DEVMODEW2A(lpw)\
	((lpw == NULL) ? NULL : ATLDEVMODEW2A((LPDEVMODEA)alloca(sizeof(DEVMODEA)+lpw->dmDriverExtra), lpw))
#define DEVMODEA2W(lpa)\
	((lpa == NULL) ? NULL : ATLDEVMODEA2W((LPDEVMODEW)alloca(sizeof(DEVMODEW)+lpa->dmDriverExtra), lpa))
#define TEXTMETRICW2A(lptmw)\
	((lptmw == NULL) ? NULL : ATLTEXTMETRICW2A((LPTEXTMETRICA)alloca(sizeof(TEXTMETRICA)), lptmw))
#define TEXTMETRICA2W(lptma)\
	((lptma == NULL) ? NULL : ATLTEXTMETRICA2W((LPTEXTMETRICW)alloca(sizeof(TEXTMETRICW)), lptma))

// public\sdk\inc\mimeole.h
#define IMimeInternational_GetCodePageCharset(This,cpiCodePage,ctCsetType,phCharset)	\
    (This)->lpVtbl -> GetCodePageCharset(This,cpiCodePage,ctCsetType,phCharset)
#define IMimeInternational_GetCodePageInfo(This,cpiCodePage,pCodePageInfo)	\
    (This)->lpVtbl -> GetCodePageInfo(This,cpiCodePage,pCodePageInfo)
#define IMimeInternational_CanConvertCodePages(This,cpiSource,cpiDest)	\
    (This)->lpVtbl -> CanConvertCodePages(This,cpiSource,cpiDest)
#define IMimeInternational_MLANG_ConvertInetString(This,cpiSource,cpiDest,pSource,pnSizeOfSource,pDestination,pnDstSize)	\
    (This)->lpVtbl -> MLANG_ConvertInetString(This,cpiSource,cpiDest,pSource,pnSizeOfSource,pDestination,pnDstSize)
#define IMimeMessage_CreateWebPage(This,pRootStm,pOptions,pCallback,ppMoniker)	\
    (This)->lpVtbl -> CreateWebPage(This,pRootStm,pOptions,pCallback,ppMoniker)
#define IMimeMessageCallback_OnWebPageSplitter(This,cInlined,ppStream)	\
    (This)->lpVtbl -> OnWebPageSplitter(This,cInlined,ppStream)
#define MimeOleVariantInit(_pProp) \
    ZeroMemory(_pProp, sizeof(PROPVARIANT))

// public\sdk\inc\mlang.h
#define IMLangStringAStr_SetAStr(This,lDestPos,lDestLen,uCodePage,pszSrc,cchSrc,pcchActual,plActualLen)	\
    (This)->lpVtbl -> SetAStr(This,lDestPos,lDestLen,uCodePage,pszSrc,cchSrc,pcchActual,plActualLen)
#define IMLangStringAStr_SetStrBufA(This,lDestPos,lDestLen,uCodePage,pSrcBuf,pcchActual,plActualLen)	\
    (This)->lpVtbl -> SetStrBufA(This,lDestPos,lDestLen,uCodePage,pSrcBuf,pcchActual,plActualLen)
#define IMLangStringAStr_GetAStr(This,lSrcPos,lSrcLen,uCodePageIn,puCodePageOut,pszDest,cchDest,pcchActual,plActualLen)	\
    (This)->lpVtbl -> GetAStr(This,lSrcPos,lSrcLen,uCodePageIn,puCodePageOut,pszDest,cchDest,pcchActual,plActualLen)
#define IMLangStringAStr_GetStrBufA(This,lSrcPos,lSrcMaxLen,puDestCodePage,ppDestBuf,plDestLen)	\
    (This)->lpVtbl -> GetStrBufA(This,lSrcPos,lSrcMaxLen,puDestCodePage,ppDestBuf,plDestLen)
#define IMLangStringAStr_LockAStr(This,lSrcPos,lSrcLen,lFlags,uCodePageIn,cchRequest,puCodePageOut,ppszDest,pcchDest,plDestLen)	\
    (This)->lpVtbl -> LockAStr(This,lSrcPos,lSrcLen,lFlags,uCodePageIn,cchRequest,puCodePageOut,ppszDest,pcchDest,plDestLen)
#define IMLangLineBreakConsole_BreakLineA(This,locale,uCodePage,pszSrc,cchSrc,cMaxColumns,pcchLine,pcchSkip)	\
    (This)->lpVtbl -> BreakLineA(This,locale,uCodePage,pszSrc,cchSrc,cMaxColumns,pcchLine,pcchSkip)
#define IEnumCodePage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumCodePage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumCodePage_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumCodePage_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)
#define IEnumCodePage_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)
#define IEnumCodePage_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumCodePage_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IMLangConvertCharset_Initialize(This,uiSrcCodePage,uiDstCodePage,dwProperty)	\
    (This)->lpVtbl -> Initialize(This,uiSrcCodePage,uiDstCodePage,dwProperty)
#define IMLangConvertCharset_GetSourceCodePage(This,puiSrcCodePage)	\
    (This)->lpVtbl -> GetSourceCodePage(This,puiSrcCodePage)
#define IMLangConvertCharset_GetDestinationCodePage(This,puiDstCodePage)	\
    (This)->lpVtbl -> GetDestinationCodePage(This,puiDstCodePage)
#define IMultiLanguage_GetNumberOfCodePageInfo(This,pcCodePage)	\
    (This)->lpVtbl -> GetNumberOfCodePageInfo(This,pcCodePage)
#define IMultiLanguage_GetCodePageInfo(This,uiCodePage,pCodePageInfo)	\
    (This)->lpVtbl -> GetCodePageInfo(This,uiCodePage,pCodePageInfo)
#define IMultiLanguage_GetFamilyCodePage(This,uiCodePage,puiFamilyCodePage)	\
    (This)->lpVtbl -> GetFamilyCodePage(This,uiCodePage,puiFamilyCodePage)
#define IMultiLanguage_EnumCodePages(This,grfFlags,ppEnumCodePage)	\
    (This)->lpVtbl -> EnumCodePages(This,grfFlags,ppEnumCodePage)
#define IMultiLanguage_CreateConvertCharset(This,uiSrcCodePage,uiDstCodePage,dwProperty,ppMLangConvertCharset)	\
    (This)->lpVtbl -> CreateConvertCharset(This,uiSrcCodePage,uiDstCodePage,dwProperty,ppMLangConvertCharset)
#define IMultiLanguage2_GetNumberOfCodePageInfo(This,pcCodePage)	\
    (This)->lpVtbl -> GetNumberOfCodePageInfo(This,pcCodePage)
#define IMultiLanguage2_GetCodePageInfo(This,uiCodePage,LangId,pCodePageInfo)	\
    (This)->lpVtbl -> GetCodePageInfo(This,uiCodePage,LangId,pCodePageInfo)
#define IMultiLanguage2_GetFamilyCodePage(This,uiCodePage,puiFamilyCodePage)	\
    (This)->lpVtbl -> GetFamilyCodePage(This,uiCodePage,puiFamilyCodePage)
#define IMultiLanguage2_EnumCodePages(This,grfFlags,LangId,ppEnumCodePage)	\
    (This)->lpVtbl -> EnumCodePages(This,grfFlags,LangId,ppEnumCodePage)
#define IMultiLanguage2_CreateConvertCharset(This,uiSrcCodePage,uiDstCodePage,dwProperty,ppMLangConvertCharset)	\
    (This)->lpVtbl -> CreateConvertCharset(This,uiSrcCodePage,uiDstCodePage,dwProperty,ppMLangConvertCharset)
#define IMultiLanguage2_DetectCodepageInIStream(This,dwFlag,dwPrefWinCodePage,pstmIn,lpEncoding,pnScores)	\
    (This)->lpVtbl -> DetectCodepageInIStream(This,dwFlag,dwPrefWinCodePage,pstmIn,lpEncoding,pnScores)
#define IMultiLanguage2_DetectInputCodepage(This,dwFlag,dwPrefWinCodePage,pSrcStr,pcSrcSize,lpEncoding,pnScores)	\
    (This)->lpVtbl -> DetectInputCodepage(This,dwFlag,dwPrefWinCodePage,pSrcStr,pcSrcSize,lpEncoding,pnScores)
#define IMultiLanguage2_ValidateCodePage(This,uiCodePage,hwnd)	\
    (This)->lpVtbl -> ValidateCodePage(This,uiCodePage,hwnd)
#define IMultiLanguage2_GetCodePageDescription(This,uiCodePage,lcid,lpWideCharStr,cchWideChar)	\
    (This)->lpVtbl -> GetCodePageDescription(This,uiCodePage,lcid,lpWideCharStr,cchWideChar)
#define IMultiLanguage2_IsCodePageInstallable(This,uiCodePage)	\
    (This)->lpVtbl -> IsCodePageInstallable(This,uiCodePage)
#define IMultiLanguage2_ValidateCodePageEx(This,uiCodePage,hwnd,dwfIODControl)	\
    (This)->lpVtbl -> ValidateCodePageEx(This,uiCodePage,hwnd,dwfIODControl)
#define IMLangCodePages_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMLangCodePages_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMLangCodePages_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMLangCodePages_GetCharCodePages(This,chSrc,pdwCodePages)	\
    (This)->lpVtbl -> GetCharCodePages(This,chSrc,pdwCodePages)
#define IMLangCodePages_GetStrCodePages(This,pszSrc,cchSrc,dwPriorityCodePages,pdwCodePages,pcchCodePages)	\
    (This)->lpVtbl -> GetStrCodePages(This,pszSrc,cchSrc,dwPriorityCodePages,pdwCodePages,pcchCodePages)
#define IMLangCodePages_CodePageToCodePages(This,uCodePage,pdwCodePages)	\
    (This)->lpVtbl -> CodePageToCodePages(This,uCodePage,pdwCodePages)
#define IMLangCodePages_CodePagesToCodePage(This,dwCodePages,uDefaultCodePage,puCodePage)	\
    (This)->lpVtbl -> CodePagesToCodePage(This,dwCodePages,uDefaultCodePage,puCodePage)
#define IMLangFontLink_GetCharCodePages(This,chSrc,pdwCodePages)	\
    (This)->lpVtbl -> GetCharCodePages(This,chSrc,pdwCodePages)
#define IMLangFontLink_GetStrCodePages(This,pszSrc,cchSrc,dwPriorityCodePages,pdwCodePages,pcchCodePages)	\
    (This)->lpVtbl -> GetStrCodePages(This,pszSrc,cchSrc,dwPriorityCodePages,pdwCodePages,pcchCodePages)
#define IMLangFontLink_CodePageToCodePages(This,uCodePage,pdwCodePages)	\
    (This)->lpVtbl -> CodePageToCodePages(This,uCodePage,pdwCodePages)
#define IMLangFontLink_CodePagesToCodePage(This,dwCodePages,uDefaultCodePage,puCodePage)	\
    (This)->lpVtbl -> CodePagesToCodePage(This,dwCodePages,uDefaultCodePage,puCodePage)
#define IMLangFontLink_GetFontCodePages(This,hDC,hFont,pdwCodePages)	\
    (This)->lpVtbl -> GetFontCodePages(This,hDC,hFont,pdwCodePages)
#define IMLangFontLink_MapFont(This,hDC,dwCodePages,hSrcFont,phDestFont)	\
    (This)->lpVtbl -> MapFont(This,hDC,dwCodePages,hSrcFont,phDestFont)
#define IMLangFontLink2_GetCharCodePages(This,chSrc,pdwCodePages)	\
    (This)->lpVtbl -> GetCharCodePages(This,chSrc,pdwCodePages)
#define IMLangFontLink2_GetStrCodePages(This,pszSrc,cchSrc,dwPriorityCodePages,pdwCodePages,pcchCodePages)	\
    (This)->lpVtbl -> GetStrCodePages(This,pszSrc,cchSrc,dwPriorityCodePages,pdwCodePages,pcchCodePages)
#define IMLangFontLink2_CodePageToCodePages(This,uCodePage,pdwCodePages)	\
    (This)->lpVtbl -> CodePageToCodePages(This,uCodePage,pdwCodePages)
#define IMLangFontLink2_CodePagesToCodePage(This,dwCodePages,uDefaultCodePage,puCodePage)	\
    (This)->lpVtbl -> CodePagesToCodePage(This,dwCodePages,uDefaultCodePage,puCodePage)
#define IMLangFontLink2_GetFontCodePages(This,hDC,hFont,pdwCodePages)	\
    (This)->lpVtbl -> GetFontCodePages(This,hDC,hFont,pdwCodePages)
#define IMLangFontLink2_MapFont(This,hDC,dwCodePages,chSrc,pFont)	\
    (This)->lpVtbl -> MapFont(This,hDC,dwCodePages,chSrc,pFont)
#define IMLangFontLink2_CodePageToScriptID(This,uiCodePage,pSid)	\
    (This)->lpVtbl -> CodePageToScriptID(This,uiCodePage,pSid)
#define IMultiLanguage3_GetNumberOfCodePageInfo(This,pcCodePage)	\
    (This)->lpVtbl -> GetNumberOfCodePageInfo(This,pcCodePage)
#define IMultiLanguage3_GetCodePageInfo(This,uiCodePage,LangId,pCodePageInfo)	\
    (This)->lpVtbl -> GetCodePageInfo(This,uiCodePage,LangId,pCodePageInfo)
#define IMultiLanguage3_GetFamilyCodePage(This,uiCodePage,puiFamilyCodePage)	\
    (This)->lpVtbl -> GetFamilyCodePage(This,uiCodePage,puiFamilyCodePage)
#define IMultiLanguage3_EnumCodePages(This,grfFlags,LangId,ppEnumCodePage)	\
    (This)->lpVtbl -> EnumCodePages(This,grfFlags,LangId,ppEnumCodePage)
#define IMultiLanguage3_CreateConvertCharset(This,uiSrcCodePage,uiDstCodePage,dwProperty,ppMLangConvertCharset)	\
    (This)->lpVtbl -> CreateConvertCharset(This,uiSrcCodePage,uiDstCodePage,dwProperty,ppMLangConvertCharset)
#define IMultiLanguage3_DetectCodepageInIStream(This,dwFlag,dwPrefWinCodePage,pstmIn,lpEncoding,pnScores)	\
    (This)->lpVtbl -> DetectCodepageInIStream(This,dwFlag,dwPrefWinCodePage,pstmIn,lpEncoding,pnScores)
#define IMultiLanguage3_DetectInputCodepage(This,dwFlag,dwPrefWinCodePage,pSrcStr,pcSrcSize,lpEncoding,pnScores)	\
    (This)->lpVtbl -> DetectInputCodepage(This,dwFlag,dwPrefWinCodePage,pSrcStr,pcSrcSize,lpEncoding,pnScores)
#define IMultiLanguage3_ValidateCodePage(This,uiCodePage,hwnd)	\
    (This)->lpVtbl -> ValidateCodePage(This,uiCodePage,hwnd)
#define IMultiLanguage3_GetCodePageDescription(This,uiCodePage,lcid,lpWideCharStr,cchWideChar)	\
    (This)->lpVtbl -> GetCodePageDescription(This,uiCodePage,lcid,lpWideCharStr,cchWideChar)
#define IMultiLanguage3_IsCodePageInstallable(This,uiCodePage)	\
    (This)->lpVtbl -> IsCodePageInstallable(This,uiCodePage)
#define IMultiLanguage3_ValidateCodePageEx(This,uiCodePage,hwnd,dwfIODControl)	\
    (This)->lpVtbl -> ValidateCodePageEx(This,uiCodePage,hwnd,dwfIODControl)
#define IMultiLanguage3_DetectOutboundCodePage(This,dwFlags,lpWideCharStr,cchWideChar,puiPreferredCodePages,nPreferredCodePages,puiDetectedCodePages,pnDetectedCodePages,lpSpecialChar)	\
    (This)->lpVtbl -> DetectOutboundCodePage(This,dwFlags,lpWideCharStr,cchWideChar,puiPreferredCodePages,nPreferredCodePages,puiDetectedCodePages,pnDetectedCodePages,lpSpecialChar)
#define IMultiLanguage3_DetectOutboundCodePageInIStream(This,dwFlags,pStrIn,puiPreferredCodePages,nPreferredCodePages,puiDetectedCodePages,pnDetectedCodePages,lpSpecialChar)	\
    (This)->lpVtbl -> DetectOutboundCodePageInIStream(This,dwFlags,pStrIn,puiPreferredCodePages,nPreferredCodePages,puiDetectedCodePages,pnDetectedCodePages,lpSpecialChar)

// public\sdk\inc\mmc.h
#define IPropertySheetCallback_AddPage(This,hPage)	\
    (This)->lpVtbl -> AddPage(This,hPage)
#define IPropertySheetCallback_RemovePage(This,hPage)	\
    (This)->lpVtbl -> RemovePage(This,hPage)
#define IPropertySheetProvider_AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)	\
    (This)->lpVtbl -> AddPrimaryPages(This,lpUnknown,bCreateHandle,hNotifyWindow,bScopePane)
#define IPropertySheetProvider_AddExtensionPages(This)	\
    (This)->lpVtbl -> AddExtensionPages(This)
#define IPropertySheetProvider_Show(This,window,page)	\
    (This)->lpVtbl -> Show(This,window,page)
#define IExtendPropertySheet_CreatePropertyPages(This,lpProvider,handle,lpIDataObject)	\
    (This)->lpVtbl -> CreatePropertyPages(This,lpProvider,handle,lpIDataObject)
#define IExtendPropertySheet_QueryPagesFor(This,lpDataObject)	\
    (This)->lpVtbl -> QueryPagesFor(This,lpDataObject)
#define IExtendPropertySheet2_CreatePropertyPages(This,lpProvider,handle,lpIDataObject)	\
    (This)->lpVtbl -> CreatePropertyPages(This,lpProvider,handle,lpIDataObject)
#define IExtendPropertySheet2_QueryPagesFor(This,lpDataObject)	\
    (This)->lpVtbl -> QueryPagesFor(This,lpDataObject)
#define IExtendTaskPad_GetBackground(This,pszGroup,pTDO)	\
    (This)->lpVtbl -> GetBackground(This,pszGroup,pTDO)

// public\sdk\inc\mscoree.h
#define IGCThreadControl_ThreadIsBlockingForSuspension(This)	\
    (This)->lpVtbl -> ThreadIsBlockingForSuspension(This)
#define IDebuggerThreadControl_ThreadIsBlockingForDebugger(This)	\
    (This)->lpVtbl -> ThreadIsBlockingForDebugger(This)
#define IDebuggerThreadControl_StartBlockingForDebugger(This,dwUnused)	\
    (This)->lpVtbl -> StartBlockingForDebugger(This,dwUnused)

// public\sdk\inc\msctf.h
#define ITfKeystrokeMgr_AdviseKeyEventSink(This,tid,pSink,fForeground)	\
    (This)->lpVtbl -> AdviseKeyEventSink(This,tid,pSink,fForeground)
#define ITfKeystrokeMgr_GetForeground(This,pclsid)	\
    (This)->lpVtbl -> GetForeground(This,pclsid)
#define ITfKeyEventSink_OnSetFocus(This,fForeground)	\
    (This)->lpVtbl -> OnSetFocus(This,fForeground)

// public\sdk\inc\mshtmlc.h
#define IHTMLStyle_put_background(This,v)	\
    (This)->lpVtbl -> put_background(This,v)
#define IHTMLStyle_get_background(This,p)	\
    (This)->lpVtbl -> get_background(This,p)
#define IHTMLStyle_put_backgroundColor(This,v)	\
    (This)->lpVtbl -> put_backgroundColor(This,v)
#define IHTMLStyle_get_backgroundColor(This,p)	\
    (This)->lpVtbl -> get_backgroundColor(This,p)
#define IHTMLStyle_put_backgroundImage(This,v)	\
    (This)->lpVtbl -> put_backgroundImage(This,v)
#define IHTMLStyle_get_backgroundImage(This,p)	\
    (This)->lpVtbl -> get_backgroundImage(This,p)
#define IHTMLStyle_put_backgroundRepeat(This,v)	\
    (This)->lpVtbl -> put_backgroundRepeat(This,v)
#define IHTMLStyle_get_backgroundRepeat(This,p)	\
    (This)->lpVtbl -> get_backgroundRepeat(This,p)
#define IHTMLStyle_put_backgroundAttachment(This,v)	\
    (This)->lpVtbl -> put_backgroundAttachment(This,v)
#define IHTMLStyle_get_backgroundAttachment(This,p)	\
    (This)->lpVtbl -> get_backgroundAttachment(This,p)
#define IHTMLStyle_put_backgroundPosition(This,v)	\
    (This)->lpVtbl -> put_backgroundPosition(This,v)
#define IHTMLStyle_get_backgroundPosition(This,p)	\
    (This)->lpVtbl -> get_backgroundPosition(This,p)
#define IHTMLStyle_put_backgroundPositionX(This,v)	\
    (This)->lpVtbl -> put_backgroundPositionX(This,v)
#define IHTMLStyle_get_backgroundPositionX(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionX(This,p)
#define IHTMLStyle_put_backgroundPositionY(This,v)	\
    (This)->lpVtbl -> put_backgroundPositionY(This,v)
#define IHTMLStyle_get_backgroundPositionY(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionY(This,p)
#define IHTMLStyle_put_verticalAlign(This,v)	\
    (This)->lpVtbl -> put_verticalAlign(This,v)
#define IHTMLStyle_get_verticalAlign(This,p)	\
    (This)->lpVtbl -> get_verticalAlign(This,p)
#define IHTMLStyle_put_textAlign(This,v)	\
    (This)->lpVtbl -> put_textAlign(This,v)
#define IHTMLStyle_get_textAlign(This,p)	\
    (This)->lpVtbl -> get_textAlign(This,p)
#define IHTMLStyle_put_pageBreakBefore(This,v)	\
    (This)->lpVtbl -> put_pageBreakBefore(This,v)
#define IHTMLStyle_get_pageBreakBefore(This,p)	\
    (This)->lpVtbl -> get_pageBreakBefore(This,p)
#define IHTMLStyle_put_pageBreakAfter(This,v)	\
    (This)->lpVtbl -> put_pageBreakAfter(This,v)
#define IHTMLStyle_get_pageBreakAfter(This,p)	\
    (This)->lpVtbl -> get_pageBreakAfter(This,p)
#define IHTMLStyle2_put_rubyAlign(This,v)	\
    (This)->lpVtbl -> put_rubyAlign(This,v)
#define IHTMLStyle2_get_rubyAlign(This,p)	\
    (This)->lpVtbl -> get_rubyAlign(This,p)
#define IHTMLStyle3_put_textAlignLast(This,v)	\
    (This)->lpVtbl -> put_textAlignLast(This,v)
#define IHTMLStyle3_get_textAlignLast(This,p)	\
    (This)->lpVtbl -> get_textAlignLast(This,p)
#define IHTMLRuleStyle_put_background(This,v)	\
    (This)->lpVtbl -> put_background(This,v)
#define IHTMLRuleStyle_get_background(This,p)	\
    (This)->lpVtbl -> get_background(This,p)
#define IHTMLRuleStyle_put_backgroundColor(This,v)	\
    (This)->lpVtbl -> put_backgroundColor(This,v)
#define IHTMLRuleStyle_get_backgroundColor(This,p)	\
    (This)->lpVtbl -> get_backgroundColor(This,p)
#define IHTMLRuleStyle_put_backgroundImage(This,v)	\
    (This)->lpVtbl -> put_backgroundImage(This,v)
#define IHTMLRuleStyle_get_backgroundImage(This,p)	\
    (This)->lpVtbl -> get_backgroundImage(This,p)
#define IHTMLRuleStyle_put_backgroundRepeat(This,v)	\
    (This)->lpVtbl -> put_backgroundRepeat(This,v)
#define IHTMLRuleStyle_get_backgroundRepeat(This,p)	\
    (This)->lpVtbl -> get_backgroundRepeat(This,p)
#define IHTMLRuleStyle_put_backgroundAttachment(This,v)	\
    (This)->lpVtbl -> put_backgroundAttachment(This,v)
#define IHTMLRuleStyle_get_backgroundAttachment(This,p)	\
    (This)->lpVtbl -> get_backgroundAttachment(This,p)
#define IHTMLRuleStyle_put_backgroundPosition(This,v)	\
    (This)->lpVtbl -> put_backgroundPosition(This,v)
#define IHTMLRuleStyle_get_backgroundPosition(This,p)	\
    (This)->lpVtbl -> get_backgroundPosition(This,p)
#define IHTMLRuleStyle_put_backgroundPositionX(This,v)	\
    (This)->lpVtbl -> put_backgroundPositionX(This,v)
#define IHTMLRuleStyle_get_backgroundPositionX(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionX(This,p)
#define IHTMLRuleStyle_put_backgroundPositionY(This,v)	\
    (This)->lpVtbl -> put_backgroundPositionY(This,v)
#define IHTMLRuleStyle_get_backgroundPositionY(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionY(This,p)
#define IHTMLRuleStyle_put_verticalAlign(This,v)	\
    (This)->lpVtbl -> put_verticalAlign(This,v)
#define IHTMLRuleStyle_get_verticalAlign(This,p)	\
    (This)->lpVtbl -> get_verticalAlign(This,p)
#define IHTMLRuleStyle_put_textAlign(This,v)	\
    (This)->lpVtbl -> put_textAlign(This,v)
#define IHTMLRuleStyle_get_textAlign(This,p)	\
    (This)->lpVtbl -> get_textAlign(This,p)
#define IHTMLRuleStyle_put_pageBreakBefore(This,v)	\
    (This)->lpVtbl -> put_pageBreakBefore(This,v)
#define IHTMLRuleStyle_get_pageBreakBefore(This,p)	\
    (This)->lpVtbl -> get_pageBreakBefore(This,p)
#define IHTMLRuleStyle_put_pageBreakAfter(This,v)	\
    (This)->lpVtbl -> put_pageBreakAfter(This,v)
#define IHTMLRuleStyle_get_pageBreakAfter(This,p)	\
    (This)->lpVtbl -> get_pageBreakAfter(This,p)
#define IHTMLRuleStyle2_put_rubyAlign(This,v)	\
    (This)->lpVtbl -> put_rubyAlign(This,v)
#define IHTMLRuleStyle2_get_rubyAlign(This,p)	\
    (This)->lpVtbl -> get_rubyAlign(This,p)
#define IHTMLRuleStyle3_put_textAlignLast(This,v)	\
    (This)->lpVtbl -> put_textAlignLast(This,v)
#define IHTMLRuleStyle3_get_textAlignLast(This,p)	\
    (This)->lpVtbl -> get_textAlignLast(This,p)
#define IHTMLRenderStyle_put_textBackgroundColor(This,v)	\
    (This)->lpVtbl -> put_textBackgroundColor(This,v)
#define IHTMLRenderStyle_get_textBackgroundColor(This,p)	\
    (This)->lpVtbl -> get_textBackgroundColor(This,p)
#define IHTMLCurrentStyle_get_backgroundColor(This,p)	\
    (This)->lpVtbl -> get_backgroundColor(This,p)
#define IHTMLCurrentStyle_get_backgroundImage(This,p)	\
    (This)->lpVtbl -> get_backgroundImage(This,p)
#define IHTMLCurrentStyle_get_backgroundPositionX(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionX(This,p)
#define IHTMLCurrentStyle_get_backgroundPositionY(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionY(This,p)
#define IHTMLCurrentStyle_get_backgroundRepeat(This,p)	\
    (This)->lpVtbl -> get_backgroundRepeat(This,p)
#define IHTMLCurrentStyle_get_textAlign(This,p)	\
    (This)->lpVtbl -> get_textAlign(This,p)
#define IHTMLCurrentStyle_get_verticalAlign(This,p)	\
    (This)->lpVtbl -> get_verticalAlign(This,p)
#define IHTMLCurrentStyle_get_backgroundAttachment(This,p)	\
    (This)->lpVtbl -> get_backgroundAttachment(This,p)
#define IHTMLCurrentStyle_get_pageBreakBefore(This,p)	\
    (This)->lpVtbl -> get_pageBreakBefore(This,p)
#define IHTMLCurrentStyle_get_pageBreakAfter(This,p)	\
    (This)->lpVtbl -> get_pageBreakAfter(This,p)
#define IHTMLCurrentStyle_get_rubyAlign(This,p)	\
    (This)->lpVtbl -> get_rubyAlign(This,p)
#define IHTMLCurrentStyle_get_blockDirection(This,p)	\
    (This)->lpVtbl -> get_blockDirection(This,p)
#define IHTMLCurrentStyle2_get_textAlignLast(This,p)	\
    (This)->lpVtbl -> get_textAlignLast(This,p)
#define IHTMLCurrentStyle2_get_isBlock(This,p)	\
    (This)->lpVtbl -> get_isBlock(This,p)
#define IHTMLElement3_put_onpage(This,v)	\
    (This)->lpVtbl -> put_onpage(This,v)
#define IHTMLElement3_get_onpage(This,p)	\
    (This)->lpVtbl -> get_onpage(This,p)
#define IHTMLElement3_put_inflateBlock(This,v)	\
    (This)->lpVtbl -> put_inflateBlock(This,v)
#define IHTMLElement3_get_inflateBlock(This,p)	\
    (This)->lpVtbl -> get_inflateBlock(This,p)
#define IHTMLStyleSheetPage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLStyleSheetPage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLStyleSheetPage_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLStyleSheetPage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLStyleSheetPage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLStyleSheetPage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLStyleSheetPage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IHTMLStyleSheetPage_get_selector(This,p)	\
    (This)->lpVtbl -> get_selector(This,p)
#define IHTMLStyleSheetPage_get_pseudoClass(This,p)	\
    (This)->lpVtbl -> get_pseudoClass(This,p)
#define IHTMLStyleSheetPagesCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLStyleSheetPagesCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLStyleSheetPagesCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLStyleSheetPagesCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLStyleSheetPagesCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLStyleSheetPagesCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLStyleSheetPagesCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IHTMLStyleSheetPagesCollection_get_length(This,p)	\
    (This)->lpVtbl -> get_length(This,p)
#define IHTMLStyleSheetPagesCollection_item(This,index,ppHTMLStyleSheetPage)	\
    (This)->lpVtbl -> item(This,index,ppHTMLStyleSheetPage)
#define IHTMLStyleSheet2_get_pages(This,p)	\
    (This)->lpVtbl -> get_pages(This,p)
#define IHTMLStyleSheet2_addPageRule(This,bstrSelector,bstrStyle,lIndex,plNewIndex)	\
    (This)->lpVtbl -> addPageRule(This,bstrSelector,bstrStyle,lIndex,plNewIndex)
#define IHTMLImgElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLImgElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLBodyElement_put_background(This,v)	\
    (This)->lpVtbl -> put_background(This,v)
#define IHTMLBodyElement_get_background(This,p)	\
    (This)->lpVtbl -> get_background(This,p)
#define IHTMLBlockElement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLBlockElement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLBlockElement_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLBlockElement_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLBlockElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLBlockElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLBlockElement_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IHTMLBlockElement_put_clear(This,v)	\
    (This)->lpVtbl -> put_clear(This,v)
#define IHTMLBlockElement_get_clear(This,p)	\
    (This)->lpVtbl -> get_clear(This,p)
#define IHTMLBlockElement2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLBlockElement2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLBlockElement2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLBlockElement2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLBlockElement2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLBlockElement2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLBlockElement2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IHTMLBlockElement2_put_cite(This,v)	\
    (This)->lpVtbl -> put_cite(This,v)
#define IHTMLBlockElement2_get_cite(This,p)	\
    (This)->lpVtbl -> get_cite(This,p)
#define IHTMLBlockElement2_put_width(This,v)	\
    (This)->lpVtbl -> put_width(This,v)
#define IHTMLBlockElement2_get_width(This,p)	\
    (This)->lpVtbl -> get_width(This,p)
#define DispHTMLBlockElement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLBlockElement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLBlockElement_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLBlockElement_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLBlockElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLBlockElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLBlockElement_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IHTMLDivElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLDivElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLHRElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLHRElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLParaElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLParaElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLHeaderElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLHeaderElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLInputElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLInputElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLInputImage_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLInputImage_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLEventObj3_get_nextPage(This,p)	\
    (This)->lpVtbl -> get_nextPage(This,p)
#define IHTMLEmbedElement_get_pluginspage(This,p)	\
    (This)->lpVtbl -> get_pluginspage(This,p)
#define IHTMLTableCaption_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTableCaption_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTableCaption_put_vAlign(This,v)	\
    (This)->lpVtbl -> put_vAlign(This,v)
#define IHTMLTableCaption_get_vAlign(This,p)	\
    (This)->lpVtbl -> get_vAlign(This,p)
#define IHTMLTableSection_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTableSection_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTableSection_put_vAlign(This,v)	\
    (This)->lpVtbl -> put_vAlign(This,v)
#define IHTMLTableSection_get_vAlign(This,p)	\
    (This)->lpVtbl -> get_vAlign(This,p)
#define IHTMLTable_put_background(This,v)	\
    (This)->lpVtbl -> put_background(This,v)
#define IHTMLTable_get_background(This,p)	\
    (This)->lpVtbl -> get_background(This,p)
#define IHTMLTable_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTable_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTable_put_dataPageSize(This,v)	\
    (This)->lpVtbl -> put_dataPageSize(This,v)
#define IHTMLTable_get_dataPageSize(This,p)	\
    (This)->lpVtbl -> get_dataPageSize(This,p)
#define IHTMLTable_nextPage(This)	\
    (This)->lpVtbl -> nextPage(This)
#define IHTMLTable_previousPage(This)	\
    (This)->lpVtbl -> previousPage(This)
#define IHTMLTable2_firstPage(This)	\
    (This)->lpVtbl -> firstPage(This)
#define IHTMLTable2_lastPage(This)	\
    (This)->lpVtbl -> lastPage(This)
#define IHTMLTableCol_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTableCol_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTableCol_put_vAlign(This,v)	\
    (This)->lpVtbl -> put_vAlign(This,v)
#define IHTMLTableCol_get_vAlign(This,p)	\
    (This)->lpVtbl -> get_vAlign(This,p)
#define IHTMLTableRow_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTableRow_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTableRow_put_vAlign(This,v)	\
    (This)->lpVtbl -> put_vAlign(This,v)
#define IHTMLTableRow_get_vAlign(This,p)	\
    (This)->lpVtbl -> get_vAlign(This,p)
#define IHTMLTableCell_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTableCell_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTableCell_put_vAlign(This,v)	\
    (This)->lpVtbl -> put_vAlign(This,v)
#define IHTMLTableCell_get_vAlign(This,p)	\
    (This)->lpVtbl -> get_vAlign(This,p)
#define IHTMLTableCell_put_background(This,v)	\
    (This)->lpVtbl -> put_background(This,v)
#define IHTMLTableCell_get_background(This,p)	\
    (This)->lpVtbl -> get_background(This,p)
#define IHTMLObjectElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLObjectElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLIFrameElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLIFrameElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLDivPosition_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLDivPosition_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLFieldSetElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLFieldSetElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLLegendElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLLegendElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLSpanFlow_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLSpanFlow_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IActiveIMMApp_GetCodePageA(This,hKL,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage)
#define IHtmlDlgSafeHelper_get_BlockFormats(This,p)	\
    (This)->lpVtbl -> get_BlockFormats(This,p)
#define IBlockFormats_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBlockFormats_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBlockFormats_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBlockFormats_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IBlockFormats_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IBlockFormats_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IBlockFormats_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IBlockFormats_get__NewEnum(This,p)	\
    (This)->lpVtbl -> get__NewEnum(This,p)
#define IBlockFormats_get_Count(This,p)	\
    (This)->lpVtbl -> get_Count(This,p)
#define IBlockFormats_Item(This,pvarIndex,pbstrBlockFormat)	\
    (This)->lpVtbl -> Item(This,pvarIndex,pbstrBlockFormat)
#define IHTMLComputedStyle_get_backgroundColor(This,p)	\
    (This)->lpVtbl -> get_backgroundColor(This,p)
#define IHTMLComputedStyle_get_blockDirection(This,p)	\
    (This)->lpVtbl -> get_blockDirection(This,p)

// public\sdk\inc\msiquery.h
#define MSIDBOPEN_PATCHFILE    32/sizeof(*MSIDBOPEN_READONLY) // add flag to indicate patch file

// public\sdk\inc\mstask.h
#define IProvideTaskPage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IProvideTaskPage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IProvideTaskPage_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IProvideTaskPage_GetPage(This,tpType,fPersistChanges,phPage)	\
    (This)->lpVtbl -> GetPage(This,tpType,fPersistChanges,phPage)

// public\sdk\inc\mstve.h
#define ITVETriggerCtrl_Helper_get_TopLevelPage(This,pURL)	\
    (This)->lpVtbl -> get_TopLevelPage(This,pURL)

// public\sdk\inc\mswmdm.h
#define IWMDMDevice2_GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)	\
    (This)->lpVtbl -> GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)
#define IMDSPDevice2_GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)	\
    (This)->lpVtbl -> GetSpecifyPropertyPages(This,ppSpecifyPropPages,pppUnknowns,pcUnks)

// public\sdk\inc\mswsock.h
#define WSA_CMSGHDR_ALIGN(length)                           \
            ( ((length) + TYPE_ALIGNMENT(WSACMSGHDR)-1) &   \
                (~(TYPE_ALIGNMENT(WSACMSGHDR)-1)) )         \
#define WSA_CMSGDATA_ALIGN(length)                          \
            ( ((length) + MAX_NATURAL_ALIGNMENT-1) &        \
                (~(MAX_NATURAL_ALIGNMENT-1)) )
#define WSA_CMSG_FIRSTHDR(msg) \
    ( ((msg)->Control.len >= sizeof(WSACMSGHDR))            \
        ? (LPWSACMSGHDR)(msg)->Control.buf                  \
        : (LPWSACMSGHDR)NULL )
#define WSA_CMSG_NXTHDR(msg, cmsg)                          \
    ( ((cmsg) == NULL)                                      \
        ? WSA_CMSG_FIRSTHDR(msg)                            \
        : ( ( ((u_char *)(cmsg) +                           \
                    WSA_CMSGHDR_ALIGN((cmsg)->cmsg_len) +   \
                    sizeof(WSACMSGHDR) ) >                  \
                (u_char *)((msg)->Control.buf) +            \
                    (msg)->Control.len )                    \
            ? (LPWSACMSGHDR)NULL                            \
            : (LPWSACMSGHDR)((u_char *)(cmsg) +             \
                WSA_CMSGHDR_ALIGN((cmsg)->cmsg_len)) ) )
#define WSA_CMSG_DATA(cmsg)             \
            ( (u_char *)(cmsg) + WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR)) )
#define WSA_CMSG_SPACE(length)  \
        (WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR) + WSA_CMSGHDR_ALIGN(length)))
#define WSA_CMSG_LEN(length)    \
         (WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR)) + length)

// public\sdk\inc\ndr64types.h
#define NDR64_PTR_WIRE_ALIGN (sizeof(NDR64_PTR_WIRE_TYPE)-1)
#define NDR64_WIRE_COUNT_ALIGN (sizeof(NDR64_WIRE_COUNT_TYPE)-1)

// public\sdk\inc\netcfgn.h
#define INetCfgPnpReconfigCallback_SendPnpReconfig(This,Layer,pszwUpper,pszwLower,pvData,dwSizeOfData)	\
    (This)->lpVtbl -> SendPnpReconfig(This,Layer,pszwUpper,pszwLower,pvData,dwSizeOfData)
#define INetCfgComponentPropertyUi_MergePropPages(This,pdwDefPages,pahpspPrivate,pcPages,hwndParent,pszStartPage)	\
    (This)->lpVtbl -> MergePropPages(This,pdwDefPages,pahpspPrivate,pcPages,hwndParent,pszStartPage)

// public\sdk\inc\netcon.h
#define INetConnectionPropertyUi_AddPages(This,hwndParent,pfnAddPage,lParam)	\
    (This)->lpVtbl -> AddPages(This,hwndParent,pfnAddPage,lParam)
#define INetConnectionPropertyUi2_AddPages(This,hwndParent,pfnAddPage,lParam)	\
    (This)->lpVtbl -> AddPages(This,hwndParent,pfnAddPage,lParam)

// public\sdk\inc\netmon.h
#define	TRANSMITSTATS_SIZE	( sizeof( TRANSMITSTATS  ) )
#define	STATISTICS_SIZE	( sizeof( STATISTICS  ) )
#define	VINES_IP_ADDRESS_SIZE	( sizeof( VINES_IP_ADDRESS  ) )
#define	IPX_ADDR_SIZE	( sizeof( IPX_ADDR  ) )
#define ADDRESS_SIZE   sizeof(ADDRESS)
#define ADDRESSPAIR_SIZE  sizeof(ADDRESSPAIR)
#define ADDRESSTABLE_SIZE sizeof(ADDRESSTABLE)
#define NETWORKINFO_SIZE    sizeof(NETWORKINFO)
#define	PATTERNMATCH_SIZE	( sizeof( PATTERNMATCH  ) )
#define	ANDEXP_SIZE	( sizeof( ANDEXP  ) )
#define	EXPRESSION_SIZE	( sizeof( EXPRESSION  ) )
#define	TRIGGER_SIZE	( sizeof( TRIGGER  ) )
#define CAPTUREFILTER_SIZE    sizeof(CAPTUREFILTER)
#define	FRAME_SIZE	( sizeof( FRAME  ) )
#define	FRAME_DESCRIPTOR_SIZE	( sizeof( FRAME_DESCRIPTOR  ) )
#define	STATIONSTATS_SIZE	( sizeof( STATIONSTATS  ) )
#define	SESSIONSTATS_SIZE	( sizeof( SESSIONSTATS  ) )
#define	OLDSTATIONQUERY_SIZE	( sizeof( OLDSTATIONQUERY  ) )
#define	STATIONQUERY_SIZE	( sizeof( STATIONQUERY  ) )
#define	QUERYTABLE_SIZE	( sizeof( QUERYTABLE  ) )
#define	SECURITY_PERMISSION_CHECK_SIZE	( sizeof( SECURITY_PERMISSION_CHECK  ) )
#define	SECURITY_PERMISSION_RESPONSE_SIZE	( sizeof( SECURITY_PERMISSION_RESPONSE  ) )
#define	NETWORKSTATUS_SIZE	( sizeof( NETWORKSTATUS  ) )
#define	BONEPACKET_SIZE	( sizeof( BONEPACKET  ) )
#define	ALERT_SIZE	( sizeof( ALERT  ) )
#define	STATISTICSPARAM_SIZE	( sizeof( STATISTICSPARAM  ) )
#define	CAPTUREFILE_HEADER_VALUES_SIZE	( sizeof( CAPTUREFILE_HEADER_VALUES  ) )
#define	CAPTUREFILE_HEADER_SIZE	( sizeof( CAPTUREFILE_HEADER  ) )
#define	FDDISTATFRAME_SIZE	( sizeof( FDDISTATFRAME  ) )
#define	ATMSTATFRAME_SIZE	( sizeof( ATMSTATFRAME  ) )
#define	TRSTATFRAME_SIZE	( sizeof( TRSTATFRAME  ) )
#define	ESTATFRAME_SIZE	( sizeof( ESTATFRAME  ) )
#define	MAX_STATSFRAME_SIZE	( sizeof( TRSTATFRAME  ) )
#define STRINGTABLE_SIZE    sizeof(STRINGTABLE)
#define	PROPERTYINFO_SIZE	( sizeof( PROPERTYINFO  ) )
#define PROPERTYINSTEX_SIZE     sizeof(PROPERTYINSTEX)
#define PROPERTYINST_SIZE   sizeof(PROPERTYINST)
#define	PROPERTYINSTTABLE_SIZE	( sizeof( PROPERTYINSTTABLE  ) )
#define PROPERTYTABLE_SIZE sizeof(PROPERTYTABLE)
#define ENTRYPOINTS_SIZE sizeof(ENTRYPOINTS)
#define PROPERTYDATABASE_SIZE   sizeof(PROPERTYDATABASE)
#define PROTOCOLINFO_SIZE   sizeof(PROTOCOLINFO)
#define	PROTOCOLTABLE_SIZE	( sizeof( PROTOCOLTABLE  ) - sizeof( HPROTOCOL  ) )
#define PROTOCOLTABLE_ACTUAL_SIZE(p) GetTableSize(PROTOCOLTABLE_SIZE, (p)->nProtocols, sizeof(HPROTOCOL))
#define ADDRESSINFO_SIZE    sizeof(ADDRESSINFO)
#define ADDRESSINFOTABLE_SIZE   sizeof(ADDRESSINFOTABLE)
#define FILTERINFO_SIZE (sizeof(FILTEROBJECT) )
#define FILTERDESC_SIZE sizeof(FILTERDESC)
#define ETHERNET_SIZE   sizeof(ETHERNET)
#define NM_ATM_HEADER_LENGTH sizeof(NM_ATM)
#define NM_1394_HEADER_LENGTH sizeof(NM_1394)
#define TOKENRING_SIZE  sizeof(TOKENRING)
#define FDDI_SIZE       sizeof(FDDI)
#define	LLC_SIZE	( sizeof( LLC  ) )

// public\sdk\inc\netsh.h
#define CREATE_CMD_GROUP_ENTRY(t,s)            {CMD_##t, HLP_##t, sizeof(s)/sizeof(CMD_ENTRY), 0, s, NULL }
#define CREATE_CMD_GROUP_ENTRY_EX(t,s,i)	   {CMD_##t, HLP_##t, sizeof(s)/sizeof(CMD_ENTRY), i, s, NULL }
#define CREATE_CMD_GROUP_ENTRY_EX_VER(t,s,i,v) {CMD_##t, HLP_##t, sizeof(s)/sizeof(CMD_ENTRY), i, s, v }

// public\sdk\inc\ntalpha.h
#define CONTEXT_LENGTH (sizeof(CONTEXT))
#define CONTEXT_ALIGN (sizeof(ULONG))

// public\sdk\inc\ntamd64.h
#define LEGACY_SAVE_AREA_LENGTH  ((sizeof(LEGACY_SAVE_AREA) + 15) & ~15)
#define CONTEXT_LENGTH ((sizeof(CONTEXT) + STACK_ROUND) & ~STACK_ROUND)

// public\sdk\inc\ntddcdrm.h
#define CDROM_TOC_SIZE sizeof(CDROM_TOC)

// public\sdk\inc\ntddcdvd.h
#define DVD_CHALLENGE_KEY_LENGTH    (12 + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_BUS_KEY_LENGTH          (8 + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_TITLE_KEY_LENGTH        (8 + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_DISK_KEY_LENGTH         (2048 + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_RPC_KEY_LENGTH          (sizeof(DVD_RPC_KEY) + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_SET_RPC_KEY_LENGTH      (sizeof(DVD_SET_RPC_KEY) + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_ASF_LENGTH              (sizeof(DVD_ASF) + sizeof(DVD_COPY_PROTECT_KEY))

// public\sdk\inc\ntdddisk.h
#define IOCTL_DISK_REASSIGN_BLOCKS      CTL_CODE(IOCTL_DISK_BASE, 0x0007, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define DiskGeometryGetDetect(Geometry)\
                        ((PDISK_DETECTION_INFO)(((PBYTE)DiskGeometryGetPartition(Geometry)+\
                                        DiskGeometryGetPartition(Geometry)->SizeOfPartitionInfo)))
#define HISTOGRAM_BUCKET_SIZE   sizeof(HISTOGRAM_BUCKET)
#define DISK_HISTOGRAM_SIZE sizeof(DISK_HISTOGRAM)

// public\sdk\inc\ntddndis.h
#define NETWORK_ADDRESS_LENGTH_IP sizeof (NETWORK_ADDRESS_IP)
#define NETWORK_ADDRESS_LENGTH_IPX sizeof (NETWORK_ADDRESS_IPX)
#define CbDevices(cnt) (FIELD_OFFSET(NDIS_BPC_DEVICES, rgnhDevices) + (cnt) * sizeof(BPC_HANDLE))
#define CbDeviceCaps(cnt) (FIELD_OFFSET(NDIS_BPC_DEVICE_CAPS, rgulStreamTypes) + (cnt) * sizeof(ULONG))
#define CbDeviceSettings(cnt) (FIELD_OFFSET(NDIS_BPC_DEVICE_SETTINGS, rgulAddressConnection) + (cnt) * sizeof(ULONG))
#define CbConnect(cnt)  (FIELD_OFFSET(NDIS_BPC_CONNECT, rgulAddress) + (cnt) * sizeof(ULONG))

// public\sdk\inc\ntddpcm.h
#define PCMRES_SET_DESCRIPTOR_TYPE(IoResourceDesc, Type)    (IoResourceDesc)->u.DevicePrivate.Data[0] |= ((Type) << sizeof(UCHAR)*8*2)
#define PCMRES_GET_DESCRIPTOR_TYPE(IoResourceDesc) ((UCHAR) ((IoResourceDesc)->u.DevicePrivate.Data[0] >> sizeof(UCHAR)*8*2))

// public\sdk\inc\ntddramd.h
#define RAMDISK_MAX_DEVICE_NAME ( sizeof( L"\\Device\\Ramdisk{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}" ) / sizeof( WCHAR ) )

// public\sdk\inc\ntddredb.h
    #define REDBOOK_WMI_NUMBER_OF_BUFFERS_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_SECTORS_PER_READ_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_SECTORS_PER_READ_MASK_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_MAX_SECTORS_PER_READ_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_PLAY_ENABLED_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_CDDA_SUPPORTED_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_CDDA_ACCURATE_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_STD_DATA_Reserved1_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_PERF_TIME_READING_DELAY_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_TIME_READING_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_TIME_STREAMING_DELAY_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_TIME_STREAMING_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_DATA_PROCESSED_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_STREAM_PAUSED_COUNT_SIZE sizeof(ULONG)

// public\sdk\inc\ntddstrm.h
#define NORMAL_STREAM_EA_LENGTH             (sizeof(NormalStreamEA) - 1)

// public\sdk\inc\ntddvdeo.h
#define BYTE_ALIGN  sizeof(UCHAR)
#define WORD_ALIGN  sizeof(USHORT)

// public\sdk\inc\ntdef.h
#define MAX_NATURAL_ALIGNMENT sizeof(ULONGLONG)
#define MAX_NATURAL_ALIGNMENT sizeof(ULONG)
#define TYPE_ALIGNMENT( t ) \
    FIELD_OFFSET( struct { char x; t test; }, test )
#define PROBE_ALIGNMENT( _s ) (TYPE_ALIGNMENT( _s ) > TYPE_ALIGNMENT( ULONG ) ? \
                               TYPE_ALIGNMENT( _s ) : TYPE_ALIGNMENT( ULONG ))
#define DECLARE_CONST_UNICODE_STRING(_variablename, _string) \
const WCHAR _variablename ## _buffer[] = _string; \
const UNICODE_STRING _variablename = { sizeof(_string) - sizeof(WCHAR), sizeof(_string), (PWSTR) _variablename ## _buffer };
#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }
#define RTL_CONSTANT_OBJECT_ATTRIBUTES(n, a) \
    { sizeof(OBJECT_ATTRIBUTES), NULL, RTL_CONST_CAST(PUNICODE_STRING)(n), a, NULL, NULL }
#define RTL_FIELD_SIZE(type, field) (sizeof(((type *)0)->field))
#define RTL_SIZEOF_THROUGH_FIELD(type, field) \
    (FIELD_OFFSET(type, field) + RTL_FIELD_SIZE(type, field))
#define RTL_CONTAINS_FIELD(Struct, Size, Field) \
    ( (((PCHAR)(&(Struct)->Field)) + sizeof((Struct)->Field)) <= (((PCHAR)(Struct))+(Size)) )
#define RTL_CONSTANT_STRING(s) { sizeof( s ) - sizeof( (s)[0] ), sizeof( s ), s }
#define RTL_BITS_OF(sizeOfArg) (sizeof(sizeOfArg) * 8)

// public\sdk\inc\ntdsbmsg.h
#define hrBFPageNotFound                 ((HRESULT)0x880000C9L)
#define hrInvalidCodePage                ((HRESULT)0xC8000427L)
#define hrDatabaseInvalidPages           ((HRESULT)0xC80004B5L)

// public\sdk\inc\ntexapi.h
#define FLG_USERMODE_VALID_BITS        (FLG_STOP_ON_EXCEPTION           | \
                                        FLG_SHOW_LDR_SNAPS              | \
                                        FLG_HEAP_ENABLE_TAIL_CHECK      | \
                                        FLG_HEAP_ENABLE_FREE_CHECK      | \
                                        FLG_HEAP_VALIDATE_PARAMETERS    | \
                                        FLG_HEAP_VALIDATE_ALL           | \
                                        FLG_APPLICATION_VERIFIER        | \
                                        FLG_HEAP_ENABLE_TAGGING         | \
                                        FLG_USER_STACK_TRACE_DB         | \
                                        FLG_HEAP_ENABLE_TAG_BY_DLL      | \
                                        FLG_DISABLE_STACK_EXTENSION     | \
                                        FLG_ENABLE_SYSTEM_CRIT_BREAKS   | \
                                        FLG_HEAP_DISABLE_COALESCING     | \
                                        FLG_DISABLE_PROTDLLS            | \
                                        FLG_HEAP_PAGE_ALLOCS            | \
                                        FLG_CRITSEC_EVENT_CREATION      | \
                                        FLG_LDR_TOP_DOWN)
#define FLG_BOOTONLY_VALID_BITS        (FLG_KERNEL_STACK_TRACE_DB       | \
                                        FLG_MAINTAIN_OBJECT_TYPELIST    | \
                                        FLG_ENABLE_CSRDEBUG             | \
                                        FLG_DEBUG_INITIAL_COMMAND       | \
                                        FLG_DEBUG_INITIAL_COMMAND_EX    | \
                                        FLG_DISABLE_PAGE_KERNEL_STACKS)

// public\sdk\inc\ntfsprop.h
#define VARIABLE_STRUCTURE_SIZE(S,V,C) ((int)sizeof( S ) + ((C) - 1) * (int)sizeof( V ))
#define COUNTED_STRING_SIZE(l)      \
    (sizeof( COUNTED_STRING ) - sizeof ( WCHAR ) + (l))

// public\sdk\inc\nti386.h
#define CONTEXT_LENGTH  (sizeof(CONTEXT))
#define CONTEXT_ALIGN   (sizeof(ULONG))

// public\sdk\inc\ntia64.h
#define CONTEXT_LENGTH (sizeof(CONTEXT))
#define GetLanguageSpecificData(f, base)                                      \
    ((((PUNWIND_INFO)(base + f->UnwindInfoAddress))->Version <= 2)  ?          \
    (((PVOID)(base + f->UnwindInfoAddress + sizeof(UNWIND_INFO) +             \
        ((PUNWIND_INFO)(base+f->UnwindInfoAddress))->DataLength*sizeof(ULONGLONG) + sizeof(ULONGLONG)))) : \
    (((PVOID)(base + f->UnwindInfoAddress + sizeof(UNWIND_INFO) +             \
        ((PUNWIND_INFO)(base+f->UnwindInfoAddress))->DataLength*sizeof(ULONGLONG) + sizeof(ULONG)))))

// public\sdk\inc\ntimage.h
#define IMAGE_FIRST_SECTION( ntheader ) ((PIMAGE_SECTION_HEADER)        \
    ((ULONG_PTR)ntheader +                                              \
     FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +                 \
     ((PIMAGE_NT_HEADERS)(ntheader))->FileHeader.SizeOfOptionalHeader   \
    ))

// public\sdk\inc\ntiolog.h
#define IO_ERROR_LOG_MESSAGE_HEADER_LENGTH (sizeof(IO_ERROR_LOG_MESSAGE) -    \
                                            sizeof(IO_ERROR_LOG_PACKET) +     \
                                            (sizeof(WCHAR) * 40))

// public\sdk\inc\ntiologc.h
#define IO_DUMP_PAGE_CONFIG_FAILED       ((NTSTATUS)0xC0040031L)

// public\sdk\inc\ntlmsp.h
#define NTLMSP_NAME_SIZE        (sizeof(NTLMSP_NAME) - sizeof(WCHAR))  // ntifs
#define TARGET_INFO_LEN ((2*DNSLEN + DNLEN + CNLEN) * sizeof(WCHAR) +  \
                         5 * sizeof(MSV1_0_AV_PAIR))
#define NTLM2_RESPONSE_LENGTH (sizeof(MSV1_0_NTLM3_RESPONSE) + \
                               TARGET_INFO_LEN)
#define NTLMSSP_MAX_MESSAGE_SIZE (sizeof(AUTHENTICATE_MESSAGE) +  \
                                  LM_RESPONSE_LENGTH +            \
                                  NTLM2_RESPONSE_LENGTH +         \
                                  (DNLEN + 1) * sizeof(WCHAR) +   \
                                  (UNLEN + 1) * sizeof(WCHAR) +   \
                                  (CNLEN + 1) * sizeof(WCHAR))
#define NTLMSSP_MESSAGE_SIGNATURE_SIZE sizeof(NTLMSSP_MESSAGE_SIGNATURE)

// public\sdk\inc\ntmips.h
#define CONTEXT_LENGTH (sizeof(CONTEXT))
#define CONTEXT_ALIGN (sizeof(double))
#define INITIALIZE_DIRECTORY_TABLE_BASE(dirbase, pfn) \
     ((HARDWARE_PTE *)(dirbase))->PageFrameNumber = pfn; \
     ((HARDWARE_PTE *)(dirbase))->Global = 0; \
     ((HARDWARE_PTE *)(dirbase))->Valid = 1; \
     ((HARDWARE_PTE *)(dirbase))->Dirty = 1; \
     ((HARDWARE_PTE *)(dirbase))->CachePolicy = PCR->CachePolicy

// public\sdk\inc\ntmppc.h
#define CONTEXT_LENGTH (sizeof(CONTEXT))
#define CONTEXT_ALIGN (sizeof(double))

// public\sdk\inc\ntmsv1_0.h
#define MSV1_0_PACKAGE_NAMEW_LENGTH sizeof(MSV1_0_PACKAGE_NAMEW) - sizeof(WCHAR)
#define MSV1_0_NTLM3_INPUT_LENGTH (sizeof(MSV1_0_NTLM3_RESPONSE) - MSV1_0_NTLM3_RESPONSE_LENGTH)

// public\sdk\inc\ntppc.h
#define CONTEXT_LENGTH (sizeof(CONTEXT))
#define CONTEXT_ALIGN (sizeof(double))

// public\sdk\inc\ntrtl.h
#define HEAP_CREATE_VALID_MASK         (HEAP_NO_SERIALIZE |             \
                                        HEAP_GROWABLE |                 \
                                        HEAP_GENERATE_EXCEPTIONS |      \
                                        HEAP_ZERO_MEMORY |              \
                                        HEAP_REALLOC_IN_PLACE_ONLY |    \
                                        HEAP_TAIL_CHECKING_ENABLED |    \
                                        HEAP_FREE_CHECKING_ENABLED |    \
                                        HEAP_DISABLE_COALESCE_ON_FREE | \
                                        HEAP_CLASS_MASK |               \
                                        HEAP_CREATE_ALIGN_16 |          \
                                        HEAP_CREATE_ENABLE_TRACING)
#define RtlUnicodeStringToAnsiSize(STRING) (                  \
    NLS_MB_CODE_PAGE_TAG ?                                    \
    RtlxUnicodeStringToAnsiSize(STRING) :                     \
    ((STRING)->Length + sizeof(UNICODE_NULL)) / sizeof(WCHAR) \
)
#define RtlUnicodeStringToOemSize(STRING) (                   \
    NLS_MB_OEM_CODE_PAGE_TAG ?                                \
    RtlxUnicodeStringToOemSize(STRING) :                      \
    ((STRING)->Length + sizeof(UNICODE_NULL)) / sizeof(WCHAR) \
)
#define RtlUnicodeStringToCountedOemSize(STRING) (                   \
    (ULONG)(RtlUnicodeStringToOemSize(STRING) - sizeof(ANSI_NULL)) \
    )
#define RtlAnsiStringToUnicodeSize(STRING) (                 \
    NLS_MB_CODE_PAGE_TAG ?                                   \
    RtlxAnsiStringToUnicodeSize(STRING) :                    \
    ((STRING)->Length + sizeof(ANSI_NULL)) * sizeof(WCHAR) \
)
#define RtlOemStringToUnicodeSize(STRING) (                  \
    NLS_MB_OEM_CODE_PAGE_TAG ?                               \
    RtlxOemStringToUnicodeSize(STRING) :                     \
    ((STRING)->Length + sizeof(ANSI_NULL)) * sizeof(WCHAR) \
)
#define RtlOemStringToCountedUnicodeSize(STRING) (                    \
    (ULONG)(RtlOemStringToUnicodeSize(STRING) - sizeof(UNICODE_NULL)) \
    )
        #define IsEqualGUIDAligned(guid1, guid2) \
            ((*(PLONGLONG)(guid1) == *(PLONGLONG)(guid2)) && (*((PLONGLONG)(guid1) + 1) == *((PLONGLONG)(guid2) + 1)))
#define SHORT_SIZE  (sizeof(USHORT))
#define LONG_SIZE       (sizeof(LONG))
#define LONGLONG_SIZE   (sizeof(LONGLONG))
#define RtlStoreUlonglong(ADDRESS,VALUE)                        \
         if ((ULONG_PTR)(ADDRESS) & LONGLONG_MASK) {            \
             RtlStoreUlong((ULONG_PTR)(ADDRESS),                \
                           (ULONGLONG)(VALUE) & 0xFFFFFFFF);    \
             RtlStoreUlong((ULONG_PTR)(ADDRESS)+sizeof(ULONG),  \
                           (ULONGLONG)(VALUE) >> 32);           \
         } else {                                               \
             *((PULONGLONG)(ADDRESS)) = (ULONGLONG)(VALUE);     \
         }

// public\sdk\inc\ntrtlpath.h
#define RtlRemoveLastNtPathElement(Flags, Path) \
    (RtlpApplyLengthFunction((Flags), sizeof(*Path), (Path), RtlGetLengthWithoutLastNtPathElement))
#define RtlRemoveLastFullDosPathElement(Flags, Path) \
    (RtlpApplyLengthFunction((Flags), sizeof(*Path), (Path), RtlGetLengthWithoutLastFullDosPathElement))
#define RtlRemoveLastFullDosOrNtPathElement(Flags, Path) \
    (RtlpApplyLengthFunction((Flags), sizeof(*Path), (Path), RtlGetLengthWithoutLastFullDosOrNtPathElement))
#define RtlRemoveTrailingPathSeperators(Flags, Path) \
    (RtlpApplyLengthFunction((Flags), sizeof(*Path), (Path), RtlGetLengthWithoutTrailingPathSeperators))

// public\sdk\inc\ntrtlstringandbuffer.h
#define RTL_STRING_MAKE_LENGTH_INCLUDE_TERMINAL_NUL(s) ((VOID)(ASSERT(RTL_STRING_IS_NUL_TERMINATED(s)), \
                                                       ((s)->Length += sizeof((s)->Buffer[0]))))
#define RTL_STRING_GET_LENGTH_CHARS(s)     ((s)->Length / sizeof((s)->Buffer[0]))
#define RTL_STRING_SET_LENGTH_CHARS_UNSAFE(s,n) ((s) = (((n) / sizeof(s)->Buffer[0])))
#define RTL_STRING_GET_MAX_LENGTH_CHARS(s) ((s)->MaximumLength / sizeof((s)->Buffer[0]))
#define MAX_UNICODE_STRING_MAXLENGTH  ((~((~(SIZE_T)0) << (RTL_FIELD_SIZE(UNICODE_STRING, Length) * CHAR_BIT))) & ~(sizeof(((PCUNICODE_STRING)0)->Buffer[0]) - 1))
#define MAX_UNICODE_STRING_LENGTH     (MAX_UNICODE_STRING_MAXLENGTH - sizeof(((PCUNICODE_STRING)0)->Buffer[0]))
#define RtlInitUnicodeStringBuffer(Buff, StatBuff, StatSize)      \
    STATUS_SUCCESS;                                               \
    do {                                                          \
        SIZE_T TempStaticSize = (StatSize);                       \
        PUCHAR TempStaticBuff = (StatBuff);                       \
        NTSTATUS TempStatus;                                      \
        TempStaticSize &= ~(sizeof((Buff)->String.Buffer[0]) - 1);  \
        if (TempStaticSize > UNICODE_STRING_MAX_BYTES) {          \
            TempStaticSize = UNICODE_STRING_MAX_BYTES;            \
        }                                                         \
        if (TempStaticSize < sizeof(WCHAR)) {                     \
            TempStaticBuff = (Buff)->MinimumStaticBufferForTerminalNul; \
            TempStaticSize = sizeof(WCHAR);                       \
        }                                                         \
        RtlInitBuffer(&(Buff)->ByteBuffer, TempStaticBuff, TempStaticSize); \
        (Buff)->String.Buffer = (WCHAR*)TempStaticBuff;           \
        if ((Buff)->String.Buffer != NULL)                        \
            (Buff)->String.Buffer[0] = 0;                         \
        (Buff)->String.Length = 0;                                \
        (Buff)->String.MaximumLength = (RTL_STRING_LENGTH_TYPE)TempStaticSize;    \
    } while (0)
#define RtlEnsureUnicodeStringBufferSizeBytes(Buff_, NewSizeBytes_)                            \
    (     ( ((NewSizeBytes_) + sizeof((Buff_)->String.Buffer[0])) > UNICODE_STRING_MAX_BYTES ) \
        ? STATUS_NAME_TOO_LONG                                                                 \
        : !NT_SUCCESS(RtlEnsureBufferSize(0, &(Buff_)->ByteBuffer, ((NewSizeBytes_) + sizeof((Buff_)->String.Buffer[0])))) \
        ? STATUS_NO_MEMORY                                                                      \
        : (RtlSyncStringToBuffer(Buff_))                                                       \
    )
#define RtlEnsureUnicodeStringBufferSizeChars(Buff_, NewSizeChars_) \
    (RtlEnsureUnicodeStringBufferSizeBytes((Buff_), (NewSizeChars_) * sizeof((Buff_)->String.Buffer[0])))
#define RtlAppendUnicodeStringBuffer(Dest, Source)                            \
    ( ( ( (Dest)->String.Length + (Source)->Length + sizeof((Dest)->String.Buffer[0]) ) > UNICODE_STRING_MAX_BYTES ) \
        ? STATUS_NAME_TOO_LONG                                                \
        : (!NT_SUCCESS(                                                       \
                RtlEnsureBufferSize(                                          \
                    0,                                                        \
                    &(Dest)->ByteBuffer,                                          \
                    (Dest)->String.Length + (Source)->Length + sizeof((Dest)->String.Buffer[0]) ) ) \
                ? STATUS_NO_MEMORY                                            \
                : ( ( (Dest)->String.Buffer = (PWSTR)(Dest)->ByteBuffer.Buffer ), \
                    ( RtlMoveMemory(                                          \
                        (Dest)->String.Buffer + (Dest)->String.Length / sizeof((Dest)->String.Buffer[0]), \
                        (Source)->Buffer,                                     \
                        (Source)->Length) ),                                  \
                    ( (Dest)->String.MaximumLength = (RTL_STRING_LENGTH_TYPE)((Dest)->String.Length + (Source)->Length + sizeof((Dest)->String.Buffer[0]))), \
                    ( (Dest)->String.Length += (Source)->Length ),            \
                    ( (Dest)->String.Buffer[(Dest)->String.Length / sizeof((Dest)->String.Buffer[0])] = 0 ), \
                    ( STATUS_SUCCESS ) ) ) )

// public\sdk\inc\ntsam.h
#define USER_ALL_READ_PREFERENCES_MASK (USER_ALL_COUNTRYCODE         | \
                                    USER_ALL_CODEPAGE)
#define USER_ALL_WRITE_PREFERENCES_MASK (USER_ALL_USERCOMMENT        | \
                                        USER_ALL_COUNTRYCODE         | \
                                        USER_ALL_CODEPAGE)

// public\sdk\inc\ntseapi.h
#define SECURITY_DESCRIPTOR_MIN_LENGTH   (sizeof(SECURITY_DESCRIPTOR))

// public\sdk\inc\ntsecapi.h
#define MSV1_0_PACKAGE_NAMEW_LENGTH sizeof(MSV1_0_PACKAGE_NAMEW) - sizeof(WCHAR)
#define MSV1_0_NTLM3_INPUT_LENGTH (sizeof(MSV1_0_NTLM3_RESPONSE) - MSV1_0_NTLM3_RESPONSE_LENGTH)

// public\sdk\inc\ntstatus.h
#define STATUS_PAGEFILE_CREATE_FAILED    ((NTSTATUS)0xC0000146L)

// public\sdk\inc\nturtl.h
#define RtlAssociatePerThreadCurdir(BLOCK,CURRENTDIRECTORIES,IMAGENAME,ENVIRONMENT)\
        (BLOCK)->CurrentDirectories = (CURRENTDIRECTORIES); \
        (BLOCK)->ImageName = (IMAGENAME);                   \
        (BLOCK)->Environment = (ENVIRONMENT);               \
        NtCurrentTeb()->NtTib.SubSystemTib = (PVOID)(BLOCK) \

// public\sdk\inc\oaidl.h
#define ICreateTypeInfo_SetAlignment(This,cbAlignment)	\
    (This)->lpVtbl -> SetAlignment(This,cbAlignment)
#define ICreateTypeInfo2_SetAlignment(This,cbAlignment)	\
    (This)->lpVtbl -> SetAlignment(This,cbAlignment)

// public\sdk\inc\objidl.h
#define IBlockingLock_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBlockingLock_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBlockingLock_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBlockingLock_Lock(This,dwTimeout)	\
    (This)->lpVtbl -> Lock(This,dwTimeout)
#define IBlockingLock_Unlock(This)	\
    (This)->lpVtbl -> Unlock(This)
#define IForegroundTransfer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IForegroundTransfer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IForegroundTransfer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IForegroundTransfer_AllowForegroundTransfer(This,lpvReserved)	\
    (This)->lpVtbl -> AllowForegroundTransfer(This,lpvReserved)

// public\sdk\inc\ocidl.h
#define IPropertyPage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IPropertyPage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IPropertyPage_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IPropertyPage_SetPageSite(This,pPageSite)	\
    (This)->lpVtbl -> SetPageSite(This,pPageSite)
#define IPropertyPage_Activate(This,hWndParent,pRect,bModal)	\
    (This)->lpVtbl -> Activate(This,hWndParent,pRect,bModal)
#define IPropertyPage_Deactivate(This)	\
    (This)->lpVtbl -> Deactivate(This)
#define IPropertyPage_GetPageInfo(This,pPageInfo)	\
    (This)->lpVtbl -> GetPageInfo(This,pPageInfo)
#define IPropertyPage_SetObjects(This,cObjects,ppUnk)	\
    (This)->lpVtbl -> SetObjects(This,cObjects,ppUnk)
#define IPropertyPage_Show(This,nCmdShow)	\
    (This)->lpVtbl -> Show(This,nCmdShow)
#define IPropertyPage_Move(This,pRect)	\
    (This)->lpVtbl -> Move(This,pRect)
#define IPropertyPage_IsPageDirty(This)	\
    (This)->lpVtbl -> IsPageDirty(This)
#define IPropertyPage_Apply(This)	\
    (This)->lpVtbl -> Apply(This)
#define IPropertyPage_Help(This,pszHelpDir)	\
    (This)->lpVtbl -> Help(This,pszHelpDir)
#define IPropertyPage_TranslateAccelerator(This,pMsg)	\
    (This)->lpVtbl -> TranslateAccelerator(This,pMsg)
#define IPropertyPage2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IPropertyPage2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IPropertyPage2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IPropertyPage2_SetPageSite(This,pPageSite)	\
    (This)->lpVtbl -> SetPageSite(This,pPageSite)
#define IPropertyPage2_Activate(This,hWndParent,pRect,bModal)	\
    (This)->lpVtbl -> Activate(This,hWndParent,pRect,bModal)
#define IPropertyPage2_Deactivate(This)	\
    (This)->lpVtbl -> Deactivate(This)
#define IPropertyPage2_GetPageInfo(This,pPageInfo)	\
    (This)->lpVtbl -> GetPageInfo(This,pPageInfo)
#define IPropertyPage2_SetObjects(This,cObjects,ppUnk)	\
    (This)->lpVtbl -> SetObjects(This,cObjects,ppUnk)
#define IPropertyPage2_Show(This,nCmdShow)	\
    (This)->lpVtbl -> Show(This,nCmdShow)
#define IPropertyPage2_Move(This,pRect)	\
    (This)->lpVtbl -> Move(This,pRect)
#define IPropertyPage2_IsPageDirty(This)	\
    (This)->lpVtbl -> IsPageDirty(This)
#define IPropertyPage2_Apply(This)	\
    (This)->lpVtbl -> Apply(This)
#define IPropertyPage2_Help(This,pszHelpDir)	\
    (This)->lpVtbl -> Help(This,pszHelpDir)
#define IPropertyPage2_TranslateAccelerator(This,pMsg)	\
    (This)->lpVtbl -> TranslateAccelerator(This,pMsg)
#define IPropertyPage2_EditProperty(This,dispID)	\
    (This)->lpVtbl -> EditProperty(This,dispID)
#define IPropertyPageSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IPropertyPageSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IPropertyPageSite_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IPropertyPageSite_OnStatusChange(This,dwFlags)	\
    (This)->lpVtbl -> OnStatusChange(This,dwFlags)
#define IPropertyPageSite_GetLocaleID(This,pLocaleID)	\
    (This)->lpVtbl -> GetLocaleID(This,pLocaleID)
#define IPropertyPageSite_GetPageContainer(This,ppUnk)	\
    (This)->lpVtbl -> GetPageContainer(This,ppUnk)
#define IPropertyPageSite_TranslateAccelerator(This,pMsg)	\
    (This)->lpVtbl -> TranslateAccelerator(This,pMsg)
#define ISpecifyPropertyPages_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISpecifyPropertyPages_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISpecifyPropertyPages_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISpecifyPropertyPages_GetPages(This,pPages)	\
    (This)->lpVtbl -> GetPages(This,pPages)
#define IPerPropertyBrowsing_MapPropertyToPage(This,dispID,pClsid)	\
    (This)->lpVtbl -> MapPropertyToPage(This,dispID,pClsid)

// public\sdk\inc\oledb.h
#define IsEqualGuidBase(rguid1, rguid2) (!memcmp(&((rguid1).Data2), &((rguid2).Data2), sizeof(GUID) - sizeof((rguid1).Data1)))

// public\sdk\inc\omscript.h
#define IHTMLStyle_put_background(This,v)	\
    (This)->lpVtbl -> put_background(This,v)
#define IHTMLStyle_get_background(This,p)	\
    (This)->lpVtbl -> get_background(This,p)
#define IHTMLStyle_put_backgroundColor(This,v)	\
    (This)->lpVtbl -> put_backgroundColor(This,v)
#define IHTMLStyle_get_backgroundColor(This,p)	\
    (This)->lpVtbl -> get_backgroundColor(This,p)
#define IHTMLStyle_put_backgroundImage(This,v)	\
    (This)->lpVtbl -> put_backgroundImage(This,v)
#define IHTMLStyle_get_backgroundImage(This,p)	\
    (This)->lpVtbl -> get_backgroundImage(This,p)
#define IHTMLStyle_put_backgroundRepeat(This,v)	\
    (This)->lpVtbl -> put_backgroundRepeat(This,v)
#define IHTMLStyle_get_backgroundRepeat(This,p)	\
    (This)->lpVtbl -> get_backgroundRepeat(This,p)
#define IHTMLStyle_put_backgroundAttachment(This,v)	\
    (This)->lpVtbl -> put_backgroundAttachment(This,v)
#define IHTMLStyle_get_backgroundAttachment(This,p)	\
    (This)->lpVtbl -> get_backgroundAttachment(This,p)
#define IHTMLStyle_put_backgroundPosition(This,v)	\
    (This)->lpVtbl -> put_backgroundPosition(This,v)
#define IHTMLStyle_get_backgroundPosition(This,p)	\
    (This)->lpVtbl -> get_backgroundPosition(This,p)
#define IHTMLStyle_put_backgroundPositionX(This,v)	\
    (This)->lpVtbl -> put_backgroundPositionX(This,v)
#define IHTMLStyle_get_backgroundPositionX(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionX(This,p)
#define IHTMLStyle_put_backgroundPositionY(This,v)	\
    (This)->lpVtbl -> put_backgroundPositionY(This,v)
#define IHTMLStyle_get_backgroundPositionY(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionY(This,p)
#define IHTMLStyle_put_verticalAlign(This,v)	\
    (This)->lpVtbl -> put_verticalAlign(This,v)
#define IHTMLStyle_get_verticalAlign(This,p)	\
    (This)->lpVtbl -> get_verticalAlign(This,p)
#define IHTMLStyle_put_textAlign(This,v)	\
    (This)->lpVtbl -> put_textAlign(This,v)
#define IHTMLStyle_get_textAlign(This,p)	\
    (This)->lpVtbl -> get_textAlign(This,p)
#define IHTMLStyle_put_pageBreakBefore(This,v)	\
    (This)->lpVtbl -> put_pageBreakBefore(This,v)
#define IHTMLStyle_get_pageBreakBefore(This,p)	\
    (This)->lpVtbl -> get_pageBreakBefore(This,p)
#define IHTMLStyle_put_pageBreakAfter(This,v)	\
    (This)->lpVtbl -> put_pageBreakAfter(This,v)
#define IHTMLStyle_get_pageBreakAfter(This,p)	\
    (This)->lpVtbl -> get_pageBreakAfter(This,p)
#define IHTMLStyle2_put_rubyAlign(This,v)	\
    (This)->lpVtbl -> put_rubyAlign(This,v)
#define IHTMLStyle2_get_rubyAlign(This,p)	\
    (This)->lpVtbl -> get_rubyAlign(This,p)
#define IHTMLStyle3_put_textAlignLast(This,v)	\
    (This)->lpVtbl -> put_textAlignLast(This,v)
#define IHTMLStyle3_get_textAlignLast(This,p)	\
    (This)->lpVtbl -> get_textAlignLast(This,p)
#define IHTMLRuleStyle_put_background(This,v)	\
    (This)->lpVtbl -> put_background(This,v)
#define IHTMLRuleStyle_get_background(This,p)	\
    (This)->lpVtbl -> get_background(This,p)
#define IHTMLRuleStyle_put_backgroundColor(This,v)	\
    (This)->lpVtbl -> put_backgroundColor(This,v)
#define IHTMLRuleStyle_get_backgroundColor(This,p)	\
    (This)->lpVtbl -> get_backgroundColor(This,p)
#define IHTMLRuleStyle_put_backgroundImage(This,v)	\
    (This)->lpVtbl -> put_backgroundImage(This,v)
#define IHTMLRuleStyle_get_backgroundImage(This,p)	\
    (This)->lpVtbl -> get_backgroundImage(This,p)
#define IHTMLRuleStyle_put_backgroundRepeat(This,v)	\
    (This)->lpVtbl -> put_backgroundRepeat(This,v)
#define IHTMLRuleStyle_get_backgroundRepeat(This,p)	\
    (This)->lpVtbl -> get_backgroundRepeat(This,p)
#define IHTMLRuleStyle_put_backgroundAttachment(This,v)	\
    (This)->lpVtbl -> put_backgroundAttachment(This,v)
#define IHTMLRuleStyle_get_backgroundAttachment(This,p)	\
    (This)->lpVtbl -> get_backgroundAttachment(This,p)
#define IHTMLRuleStyle_put_backgroundPosition(This,v)	\
    (This)->lpVtbl -> put_backgroundPosition(This,v)
#define IHTMLRuleStyle_get_backgroundPosition(This,p)	\
    (This)->lpVtbl -> get_backgroundPosition(This,p)
#define IHTMLRuleStyle_put_backgroundPositionX(This,v)	\
    (This)->lpVtbl -> put_backgroundPositionX(This,v)
#define IHTMLRuleStyle_get_backgroundPositionX(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionX(This,p)
#define IHTMLRuleStyle_put_backgroundPositionY(This,v)	\
    (This)->lpVtbl -> put_backgroundPositionY(This,v)
#define IHTMLRuleStyle_get_backgroundPositionY(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionY(This,p)
#define IHTMLRuleStyle_put_verticalAlign(This,v)	\
    (This)->lpVtbl -> put_verticalAlign(This,v)
#define IHTMLRuleStyle_get_verticalAlign(This,p)	\
    (This)->lpVtbl -> get_verticalAlign(This,p)
#define IHTMLRuleStyle_put_textAlign(This,v)	\
    (This)->lpVtbl -> put_textAlign(This,v)
#define IHTMLRuleStyle_get_textAlign(This,p)	\
    (This)->lpVtbl -> get_textAlign(This,p)
#define IHTMLRuleStyle_put_pageBreakBefore(This,v)	\
    (This)->lpVtbl -> put_pageBreakBefore(This,v)
#define IHTMLRuleStyle_get_pageBreakBefore(This,p)	\
    (This)->lpVtbl -> get_pageBreakBefore(This,p)
#define IHTMLRuleStyle_put_pageBreakAfter(This,v)	\
    (This)->lpVtbl -> put_pageBreakAfter(This,v)
#define IHTMLRuleStyle_get_pageBreakAfter(This,p)	\
    (This)->lpVtbl -> get_pageBreakAfter(This,p)
#define IHTMLRuleStyle2_put_rubyAlign(This,v)	\
    (This)->lpVtbl -> put_rubyAlign(This,v)
#define IHTMLRuleStyle2_get_rubyAlign(This,p)	\
    (This)->lpVtbl -> get_rubyAlign(This,p)
#define IHTMLRuleStyle3_put_textAlignLast(This,v)	\
    (This)->lpVtbl -> put_textAlignLast(This,v)
#define IHTMLRuleStyle3_get_textAlignLast(This,p)	\
    (This)->lpVtbl -> get_textAlignLast(This,p)
#define IHTMLRenderStyle_put_textBackgroundColor(This,v)	\
    (This)->lpVtbl -> put_textBackgroundColor(This,v)
#define IHTMLRenderStyle_get_textBackgroundColor(This,p)	\
    (This)->lpVtbl -> get_textBackgroundColor(This,p)
#define IHTMLCurrentStyle_get_backgroundColor(This,p)	\
    (This)->lpVtbl -> get_backgroundColor(This,p)
#define IHTMLCurrentStyle_get_backgroundImage(This,p)	\
    (This)->lpVtbl -> get_backgroundImage(This,p)
#define IHTMLCurrentStyle_get_backgroundPositionX(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionX(This,p)
#define IHTMLCurrentStyle_get_backgroundPositionY(This,p)	\
    (This)->lpVtbl -> get_backgroundPositionY(This,p)
#define IHTMLCurrentStyle_get_backgroundRepeat(This,p)	\
    (This)->lpVtbl -> get_backgroundRepeat(This,p)
#define IHTMLCurrentStyle_get_textAlign(This,p)	\
    (This)->lpVtbl -> get_textAlign(This,p)
#define IHTMLCurrentStyle_get_verticalAlign(This,p)	\
    (This)->lpVtbl -> get_verticalAlign(This,p)
#define IHTMLCurrentStyle_get_backgroundAttachment(This,p)	\
    (This)->lpVtbl -> get_backgroundAttachment(This,p)
#define IHTMLCurrentStyle_get_pageBreakBefore(This,p)	\
    (This)->lpVtbl -> get_pageBreakBefore(This,p)
#define IHTMLCurrentStyle_get_pageBreakAfter(This,p)	\
    (This)->lpVtbl -> get_pageBreakAfter(This,p)
#define IHTMLCurrentStyle_get_rubyAlign(This,p)	\
    (This)->lpVtbl -> get_rubyAlign(This,p)
#define IHTMLCurrentStyle_get_blockDirection(This,p)	\
    (This)->lpVtbl -> get_blockDirection(This,p)
#define IHTMLCurrentStyle2_get_textAlignLast(This,p)	\
    (This)->lpVtbl -> get_textAlignLast(This,p)
#define IHTMLCurrentStyle2_get_isBlock(This,p)	\
    (This)->lpVtbl -> get_isBlock(This,p)
#define IHTMLElement3_put_onpage(This,v)	\
    (This)->lpVtbl -> put_onpage(This,v)
#define IHTMLElement3_get_onpage(This,p)	\
    (This)->lpVtbl -> get_onpage(This,p)
#define IHTMLElement3_put_inflateBlock(This,v)	\
    (This)->lpVtbl -> put_inflateBlock(This,v)
#define IHTMLElement3_get_inflateBlock(This,p)	\
    (This)->lpVtbl -> get_inflateBlock(This,p)
#define IHTMLStyleSheetPage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLStyleSheetPage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLStyleSheetPage_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLStyleSheetPage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLStyleSheetPage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLStyleSheetPage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLStyleSheetPage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IHTMLStyleSheetPage_get_selector(This,p)	\
    (This)->lpVtbl -> get_selector(This,p)
#define IHTMLStyleSheetPage_get_pseudoClass(This,p)	\
    (This)->lpVtbl -> get_pseudoClass(This,p)
#define IHTMLStyleSheetPagesCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLStyleSheetPagesCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLStyleSheetPagesCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLStyleSheetPagesCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLStyleSheetPagesCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLStyleSheetPagesCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLStyleSheetPagesCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IHTMLStyleSheetPagesCollection_get_length(This,p)	\
    (This)->lpVtbl -> get_length(This,p)
#define IHTMLStyleSheetPagesCollection_item(This,index,ppHTMLStyleSheetPage)	\
    (This)->lpVtbl -> item(This,index,ppHTMLStyleSheetPage)
#define IHTMLStyleSheet2_get_pages(This,p)	\
    (This)->lpVtbl -> get_pages(This,p)
#define IHTMLStyleSheet2_addPageRule(This,bstrSelector,bstrStyle,lIndex,plNewIndex)	\
    (This)->lpVtbl -> addPageRule(This,bstrSelector,bstrStyle,lIndex,plNewIndex)
#define IHTMLImgElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLImgElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLBodyElement_put_background(This,v)	\
    (This)->lpVtbl -> put_background(This,v)
#define IHTMLBodyElement_get_background(This,p)	\
    (This)->lpVtbl -> get_background(This,p)
#define IHTMLBlockElement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLBlockElement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLBlockElement_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLBlockElement_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLBlockElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLBlockElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLBlockElement_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IHTMLBlockElement_put_clear(This,v)	\
    (This)->lpVtbl -> put_clear(This,v)
#define IHTMLBlockElement_get_clear(This,p)	\
    (This)->lpVtbl -> get_clear(This,p)
#define IHTMLBlockElement2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLBlockElement2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLBlockElement2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLBlockElement2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLBlockElement2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLBlockElement2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLBlockElement2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IHTMLBlockElement2_put_cite(This,v)	\
    (This)->lpVtbl -> put_cite(This,v)
#define IHTMLBlockElement2_get_cite(This,p)	\
    (This)->lpVtbl -> get_cite(This,p)
#define IHTMLBlockElement2_put_width(This,v)	\
    (This)->lpVtbl -> put_width(This,v)
#define IHTMLBlockElement2_get_width(This,p)	\
    (This)->lpVtbl -> get_width(This,p)
#define DispHTMLBlockElement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLBlockElement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLBlockElement_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLBlockElement_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLBlockElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLBlockElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLBlockElement_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IHTMLDivElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLDivElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLHRElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLHRElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLParaElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLParaElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLHeaderElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLHeaderElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLInputElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLInputElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLInputImage_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLInputImage_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLEventObj3_get_nextPage(This,p)	\
    (This)->lpVtbl -> get_nextPage(This,p)
#define IHTMLEmbedElement_get_pluginspage(This,p)	\
    (This)->lpVtbl -> get_pluginspage(This,p)
#define IHTMLTableCaption_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTableCaption_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTableCaption_put_vAlign(This,v)	\
    (This)->lpVtbl -> put_vAlign(This,v)
#define IHTMLTableCaption_get_vAlign(This,p)	\
    (This)->lpVtbl -> get_vAlign(This,p)
#define IHTMLTableSection_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTableSection_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTableSection_put_vAlign(This,v)	\
    (This)->lpVtbl -> put_vAlign(This,v)
#define IHTMLTableSection_get_vAlign(This,p)	\
    (This)->lpVtbl -> get_vAlign(This,p)
#define IHTMLTable_put_background(This,v)	\
    (This)->lpVtbl -> put_background(This,v)
#define IHTMLTable_get_background(This,p)	\
    (This)->lpVtbl -> get_background(This,p)
#define IHTMLTable_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTable_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTable_put_dataPageSize(This,v)	\
    (This)->lpVtbl -> put_dataPageSize(This,v)
#define IHTMLTable_get_dataPageSize(This,p)	\
    (This)->lpVtbl -> get_dataPageSize(This,p)
#define IHTMLTable_nextPage(This)	\
    (This)->lpVtbl -> nextPage(This)
#define IHTMLTable_previousPage(This)	\
    (This)->lpVtbl -> previousPage(This)
#define IHTMLTable2_firstPage(This)	\
    (This)->lpVtbl -> firstPage(This)
#define IHTMLTable2_lastPage(This)	\
    (This)->lpVtbl -> lastPage(This)
#define IHTMLTableCol_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTableCol_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTableCol_put_vAlign(This,v)	\
    (This)->lpVtbl -> put_vAlign(This,v)
#define IHTMLTableCol_get_vAlign(This,p)	\
    (This)->lpVtbl -> get_vAlign(This,p)
#define IHTMLTableRow_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTableRow_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTableRow_put_vAlign(This,v)	\
    (This)->lpVtbl -> put_vAlign(This,v)
#define IHTMLTableRow_get_vAlign(This,p)	\
    (This)->lpVtbl -> get_vAlign(This,p)
#define IHTMLTableCell_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLTableCell_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLTableCell_put_vAlign(This,v)	\
    (This)->lpVtbl -> put_vAlign(This,v)
#define IHTMLTableCell_get_vAlign(This,p)	\
    (This)->lpVtbl -> get_vAlign(This,p)
#define IHTMLTableCell_put_background(This,v)	\
    (This)->lpVtbl -> put_background(This,v)
#define IHTMLTableCell_get_background(This,p)	\
    (This)->lpVtbl -> get_background(This,p)
#define IHTMLObjectElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLObjectElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLIFrameElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLIFrameElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLDivPosition_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLDivPosition_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLFieldSetElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLFieldSetElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLLegendElement_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLLegendElement_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IHTMLSpanFlow_put_align(This,v)	\
    (This)->lpVtbl -> put_align(This,v)
#define IHTMLSpanFlow_get_align(This,p)	\
    (This)->lpVtbl -> get_align(This,p)
#define IActiveIMMApp_GetCodePageA(This,hKL,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage)
#define IHtmlDlgSafeHelper_get_BlockFormats(This,p)	\
    (This)->lpVtbl -> get_BlockFormats(This,p)
#define IBlockFormats_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IBlockFormats_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IBlockFormats_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IBlockFormats_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IBlockFormats_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IBlockFormats_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IBlockFormats_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IBlockFormats_get__NewEnum(This,p)	\
    (This)->lpVtbl -> get__NewEnum(This,p)
#define IBlockFormats_get_Count(This,p)	\
    (This)->lpVtbl -> get_Count(This,p)
#define IBlockFormats_Item(This,pvarIndex,pbstrBlockFormat)	\
    (This)->lpVtbl -> Item(This,pvarIndex,pbstrBlockFormat)
#define IHTMLComputedStyle_get_backgroundColor(This,p)	\
    (This)->lpVtbl -> get_backgroundColor(This,p)
#define IHTMLComputedStyle_get_blockDirection(This,p)	\
    (This)->lpVtbl -> get_blockDirection(This,p)

// public\sdk\inc\playlist.h
#define ISpecifyParticularPages_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISpecifyParticularPages_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISpecifyParticularPages_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISpecifyParticularPages_GetPages(This,guidWhatPages,pPages)	\
    (This)->lpVtbl -> GetPages(This,guidWhatPages,pPages)

// public\sdk\inc\powrprof.h
#define STRSIZE(psz) ((lstrlen(psz) + 1) * sizeof(TCHAR))
#define MAX_NAME_SIZE (MAX_NAME_LEN +1) * sizeof(TCHAR)
#define MAX_DESC_SIZE (MAX_DESC_LEN +1) * sizeof(TCHAR)
#define SIZE_DEC_DIGITS (10+1+1) * sizeof(TCHAR)

// public\sdk\inc\propapi.h
#   define PROPGENPROPERTYNAME(s,n) \
    { \
        memcpy ((s), OLESTR("prop"), sizeof (OLESTR("prop"))); \
        ULTOO  ((n), &(s)[sizeof("prop") - 1], 10); \
    }
#define CBIT_GUID       (CBIT_BYTE * sizeof(GUID))

// public\sdk\inc\propidl.h
#   define PropVariantInit(pvar) memset ( (pvar), 0, sizeof(PROPVARIANT) )

// public\sdk\inc\propset.h
#define CB_FORMATIDOFFSET	sizeof(FORMATIDOFFSET)
#define CB_PROPERTYSETHEADER	sizeof(PROPERTYSETHEADER)
#define CB_PROPERTYIDOFFSET	sizeof(PROPERTYIDOFFSET)

// public\sdk\inc\propvar.h
#define AssertVarField(field, cb) \
  PROPASSERT(FIELD_OFFSET(PROPVARIANT, iVal) == FIELD_OFFSET(PROPVARIANT, field) && \
	 sizeof(((PROPVARIANT *) 0)->field) == (cb))
#define AssertVarVector(field, cbElem) \
  PROPASSERT(FIELD_OFFSET(PROPVARIANT, cai.cElems) == \
	     FIELD_OFFSET(PROPVARIANT, field.cElems) && \
         FIELD_OFFSET(PROPVARIANT, cai.pElems) == \
	     FIELD_OFFSET(PROPVARIANT, field.pElems) && \
	 sizeof(((PROPVARIANT *) 0)->field.pElems[0]) == (cbElem))
#define AssertByteField(field)	    AssertVarField(field, sizeof(BYTE))
#define AssertShortField(field)	    AssertVarField(field, sizeof(SHORT))
#define AssertLongField(field)	    AssertVarField(field, sizeof(LONG))
#define AssertLongLongField(field)  AssertVarField(field, sizeof(LONGLONG))
#define AssertStringField(field)    AssertVarField(field, sizeof(VOID *))
#define AssertByteVector(field)	    AssertVarVector(field, sizeof(BYTE))
#define AssertShortVector(field)    AssertVarVector(field, sizeof(SHORT))
#define AssertLongVector(field)	    AssertVarVector(field, sizeof(LONG))
#define AssertLongLongVector(field) AssertVarVector(field, sizeof(LONGLONG))
#define AssertStringVector(field)   AssertVarVector(field, sizeof(VOID *))
#define AssertVariantVector(field)  AssertVarVector(field, sizeof(PROPVARIANT))
#define DEFINE_CBufferAllocator__Allocate			\
VOID *								\
CBufferAllocator::Allocate(ULONG cb)				\
{								\
    VOID *pv;							\
								\
    cb = (cb + sizeof(LONGLONG) - 1) & ~(sizeof(LONGLONG) - 1);	\
    if (cb > _cbFree)						\
    {								\
        return(NULL);						\
    }								\
    pv = _pvCur;						\
    _pvCur = (BYTE *) _pvCur + cb;				\
    _cbFree -= cb;						\
    return(pv);							\
}

// public\sdk\inc\prsht.h
#define CCSIZEOF_STRUCT(structname, member)  (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))
#define PSM_REMOVEPAGE          (WM_USER + 102)
#define PSM_ADDPAGE             (WM_USER + 103)
#define PSM_GETCURRENTPAGEHWND  (WM_USER + 118)
#define PSM_INSERTPAGE          (WM_USER + 119)
#define PSM_PAGETOINDEX            (WM_USER + 131)
#define PSM_INDEXTOPAGE            (WM_USER + 132)
#define PSM_RECALCPAGESIZES        (WM_USER + 136)
#define CCSIZEOF_STRUCT(structname, member)  (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))

// public\sdk\inc\qospol.h
#define IDPE_ATTR_HDR_LEN    (sizeof(USHORT)+sizeof(UCHAR)+sizeof(UCHAR))

// public\sdk\inc\qossp.h
#define RSVP_POLICY_HDR_LEN    ( sizeof(USHORT) + sizeof(USHORT) )

// public\sdk\inc\raseapif.h
#define PPP_EAP_PACKET_HDR_LEN  ( sizeof( PPP_EAP_PACKET ) - 1 )

// public\sdk\inc\resapi.h
#define CLRES_V1_FUNCTION_SIZE   sizeof(CLRES_V1_FUNCTIONS)
#define ResUtilInitializeResourceStatus( _resource_status_ ) \
    ZeroMemory( _resource_status_, sizeof(RESOURCE_STATUS) )

// public\sdk\inc\richedit.h
#define EM_GETPAGE				(WM_USER + 228)
#define EM_SETPAGE				(WM_USER + 229)
#define EM_GETPAGEROTATE		(WM_USER + 235)
#define EM_SETPAGEROTATE		(WM_USER + 236)
#define CHARFORMATDELTA		(sizeof(CHARFORMAT2) - sizeof(CHARFORMAT))
#define	PFM_ALL (PFM_STARTINDENT | PFM_RIGHTINDENT | PFM_OFFSET	| \
				 PFM_ALIGNMENT   | PFM_TABSTOPS    | PFM_NUMBERING | \
				 PFM_OFFSETINDENT| PFM_RTLPARA)
#define PFM_EFFECTS (PFM_RTLPARA | PFM_KEEP | PFM_KEEPNEXT | PFM_TABLE \
					| PFM_PAGEBREAKBEFORE | PFM_NOLINENUMBER  \
					| PFM_NOWIDOWCONTROL | PFM_DONOTHYPHEN | PFM_SIDEBYSIDE \
					| PFM_TABLE | PFM_TABLEROWDELIMITER)
#define PFE_PAGEBREAKBEFORE		(PFM_PAGEBREAKBEFORE >> 16)	// (*)

// public\sdk\inc\routprot.h
#define SIZEOF_IP_BINDING(X)                                \
    (FIELD_OFFSET(IP_ADAPTER_BINDING_INFO,Address[0]) +     \
     ((X) * sizeof(IP_LOCAL_BINDING)))

// public\sdk\inc\rpc.h
#define RPCXCWORD (sizeof(jmp_buf)/sizeof(int))

// public\sdk\inc\rpcasync.h
#define RPC_ASYNC_VERSION_1_0     sizeof(RPC_ASYNC_STATE)

// public\sdk\inc\rpcndr.h
#define NdrFieldPad(s,f,p,t)    ((unsigned long)(NdrFieldOffset(s,f) - NdrFieldOffset(s,p)) - sizeof(t))
#define RPC_BAD_STUB_DATA_EXCEPTION_FILTER  \
                 ( (RpcExceptionCode() == STATUS_ACCESS_VIOLATION)  || \
                   (RpcExceptionCode() == STATUS_DATATYPE_MISALIGNMENT) || \
                   (RpcExceptionCode() == RPC_X_BAD_STUB_DATA) || \
                   (RpcExceptionCode() == RPC_S_INVALID_BOUND) )

// public\sdk\inc\rrascfg.h
#define IEAPProviderConfig_RouterInvokeConfigUI(This,dwEapTypeId,uConnectionParam,hwndParent,dwFlags,pConnectionDataIn,dwSizeOfConnectionDataIn,ppConnectionDataOut,pdwSizeOfConnectionDataOut)	\
    (This)->lpVtbl -> RouterInvokeConfigUI(This,dwEapTypeId,uConnectionParam,hwndParent,dwFlags,pConnectionDataIn,dwSizeOfConnectionDataIn,ppConnectionDataOut,pdwSizeOfConnectionDataOut)
#define IEAPProviderConfig_RouterInvokeCredentialsUI(This,dwEapTypeId,uConnectionParam,hwndParent,dwFlags,pConnectionDataIn,dwSizeOfConnectionDataIn,pUserDataIn,dwSizeOfUserDataIn,ppUserDataOut,pdwSizeOfUserDataOut)	\
    (This)->lpVtbl -> RouterInvokeCredentialsUI(This,dwEapTypeId,uConnectionParam,hwndParent,dwFlags,pConnectionDataIn,dwSizeOfConnectionDataIn,pUserDataIn,dwSizeOfUserDataIn,ppUserDataOut,pdwSizeOfUserDataOut)
#define DeclareIEAPProviderConfigMembers(IPURE) \
	STDMETHOD(Initialize)(THIS_ \
		LPCOLESTR 	pszMachineName, \
	DWORD       dwEapTypeId, \
		ULONG_PTR*	puConnectionParam) IPURE; \
	STDMETHOD(Uninitialize)(THIS_ \
	DWORD       dwEapTypeId, \
		ULONG_PTR 	uConnectionParam) IPURE; \
	STDMETHOD(ServerInvokeConfigUI)(THIS_ \
	DWORD       dwEapTypeId, \
		ULONG_PTR 	uConnectionParam, \
		HWND 		hWnd, \
		ULONG_PTR 	dwRes1, \
		ULONG_PTR 	dwRes2) IPURE; \
 STDMETHOD(RouterInvokeConfigUI)(THIS_ \
	DWORD       dwEapTypeId, \
		ULONG_PTR 	uConnectionParam, \
	HWND        hwndParent, \
	DWORD       dwFlags, \
	BYTE* 		pConnectionDataIn, \
	DWORD		dwSizeOfConnectionDataIn, \
	BYTE**		ppConnectionDataOut, \
	DWORD*		pdwSizeOfConnectionDataOut) IPURE; \
 STDMETHOD(RouterInvokeCredentialsUI)(THIS_  \
	DWORD   	dwEapTypeId, \
		ULONG_PTR 	uConnectionParam, \
	HWND    	hwndParent, \
	DWORD   	dwFlags, \
	BYTE*   	pConnectionDataIn, \
	DWORD   	dwSizeOfConnectionDataIn, \
	BYTE*   	pUserDataIn, \
	DWORD   	dwSizeOfUserDataIn, \
	BYTE**  	ppUserDataOut, \
	DWORD*  	pdwSizeOfUserDataOut) IPURE; \

// public\sdk\inc\rtccore.h
#define IRTCClientPresence_AddWatcher(This,bstrPresentityURI,bstrUserName,bstrData,fBlocked,fPersistent,ppWatcher)	\
    (This)->lpVtbl -> AddWatcher(This,bstrPresentityURI,bstrUserName,bstrData,fBlocked,fPersistent,ppWatcher)

// public\sdk\inc\rtinfo.h
#define ALIGN_MASK_POINTER  (~(UINT_PTR)ALIGN_SHIFT)    // 0xfffffff8
#define ALIGN_MASK_LENGTH   (~ALIGN_SHIFT)              // 0xfffffff8
#define ALIGN_MASK          (~ALIGN_SHIFT)              // 0xfffffff8
#define ALIGN_POINTER(ptr) {                                    \
    (ptr) = (PVOID)((DWORD_PTR)(ptr) + ALIGN_SHIFT);            \
    (ptr) = (PVOID)((DWORD_PTR)(ptr) & ALIGN_MASK_POINTER);     \
}
#define ALIGN_LENGTH(length) {                                  \
    (length) = (DWORD)((length) + ALIGN_SHIFT);                 \
    (length) = (DWORD)((length) & ALIGN_MASK_LENGTH);           \
}
#define IS_ALIGNED(ptr)  (((UINT_PTR)(ptr) & ALIGN_SHIFT) == 0x00000000)

// public\sdk\inc\rtmv2.h
#define RTM_SIZE_OF_ROUTE_INFO(NumHops)                                  \
    (RTM_BASIC_ROUTE_INFO_SIZE + (NumHops) * sizeof(RTM_NEXTHOP_HANDLE))

// public\sdk\inc\sapi.h
#define ISpeechAudioStatus_get_NonBlockingIO(This,NonBlockingIO)	\
    (This)->lpVtbl -> get_NonBlockingIO(This,NonBlockingIO)
#define ISpeechWaveFormatEx_get_AvgBytesPerSec(This,AvgBytesPerSec)	\
    (This)->lpVtbl -> get_AvgBytesPerSec(This,AvgBytesPerSec)
#define ISpeechWaveFormatEx_put_AvgBytesPerSec(This,AvgBytesPerSec)	\
    (This)->lpVtbl -> put_AvgBytesPerSec(This,AvgBytesPerSec)
#define ISpeechWaveFormatEx_get_BlockAlign(This,BlockAlign)	\
    (This)->lpVtbl -> get_BlockAlign(This,BlockAlign)
#define ISpeechWaveFormatEx_put_BlockAlign(This,BlockAlign)	\
    (This)->lpVtbl -> put_BlockAlign(This,BlockAlign)
#define ISpeechRecoContext_CreateResultFromMemory(This,ResultBlock,Result)	\
    (This)->lpVtbl -> CreateResultFromMemory(This,ResultBlock,Result)
#define ISpeechRecoResult_SaveToMemory(This,ResultBlock)	\
    (This)->lpVtbl -> SaveToMemory(This,ResultBlock)
#define ISpeechPhraseInfo_SaveToMemory(This,PhraseBlock)	\
    (This)->lpVtbl -> SaveToMemory(This,PhraseBlock)

// public\sdk\inc\schemadef.h
#define END_TM_SCHEMA(name)                };  \
    static const TMSCHEMAINFO *GetSchemaInfo() \
    {  \
        static TMSCHEMAINFO si = {sizeof(si)};  \
        si.iSchemaDefVersion = SCHEMADEF_VERSION; \
        si.iThemeMgrVersion = THEMEMGR_VERSION; \
        si.iPropCount = sizeof(name)/sizeof(name[0]); \
        si.pPropTable = name; \
        \
        return &si; \
    }

// public\sdk\inc\segment.h
#define IMSVidStreamBufferSource_put_BlockUnrated(This,bBlock)	\
    (This)->lpVtbl -> put_BlockUnrated(This,bBlock)
#define IMSVidStreamBufferSourceEvent_RatingsBlocked(This)	\
    (This)->lpVtbl -> RatingsBlocked(This)
#define IMSVidStreamBufferSourceEvent_RatingsUnblocked(This)	\
    (This)->lpVtbl -> RatingsUnblocked(This)

// public\sdk\inc\setupapi.h
#define ERROR_INVALID_PROPPAGE_PROVIDER   (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x224)

// public\sdk\inc\shldisp.h
#define IWebWizardHost_SetWizardButtons(This,vfEnableBack,vfEnableNext,vfLastPage)	\
    (This)->lpVtbl -> SetWizardButtons(This,vfEnableBack,vfEnableNext,vfLastPage)
#define INewWDEvents_SetWizardButtons(This,vfEnableBack,vfEnableNext,vfLastPage)	\
    (This)->lpVtbl -> SetWizardButtons(This,vfEnableBack,vfEnableNext,vfLastPage)

// public\sdk\inc\shlobj.h
#define SHELLSTATE_SIZE_WIN2K sizeof(SHELLSTATE)

// public\sdk\inc\shobjidl.h
#define IShellView_AddPropertySheetPages(This,dwReserved,pfn,lparam)	\
    (This)->lpVtbl -> AddPropertySheetPages(This,dwReserved,pfn,lparam)
#define IShellView2_AddPropertySheetPages(This,dwReserved,pfn,lparam)	\
    (This)->lpVtbl -> AddPropertySheetPages(This,dwReserved,pfn,lparam)
#define IShellPropSheetExt_AddPages(This,pfnAddPage,lParam)	\
    (This)->lpVtbl -> AddPages(This,pfnAddPage,lParam)
#define IShellPropSheetExt_ReplacePage(This,uPageID,pfnReplaceWith,lParam)	\
    (This)->lpVtbl -> ReplacePage(This,uPageID,pfnReplaceWith,lParam)
#define IWizardSite_GetPreviousPage(This,phpage)	\
    (This)->lpVtbl -> GetPreviousPage(This,phpage)
#define IWizardSite_GetNextPage(This,phpage)	\
    (This)->lpVtbl -> GetNextPage(This,phpage)
#define IWizardSite_GetCancelledPage(This,phpage)	\
    (This)->lpVtbl -> GetCancelledPage(This,phpage)
#define IWizardExtension_AddPages(This,aPages,cPages,pnPagesAdded)	\
    (This)->lpVtbl -> AddPages(This,aPages,cPages,pnPagesAdded)
#define IWizardExtension_GetFirstPage(This,phpage)	\
    (This)->lpVtbl -> GetFirstPage(This,phpage)
#define IWizardExtension_GetLastPage(This,phpage)	\
    (This)->lpVtbl -> GetLastPage(This,phpage)
#define IWebWizardExtension_AddPages(This,aPages,cPages,pnPagesAdded)	\
    (This)->lpVtbl -> AddPages(This,aPages,cPages,pnPagesAdded)
#define IWebWizardExtension_GetFirstPage(This,phpage)	\
    (This)->lpVtbl -> GetFirstPage(This,phpage)
#define IWebWizardExtension_GetLastPage(This,phpage)	\
    (This)->lpVtbl -> GetLastPage(This,phpage)
#define IPublishingWizard_AddPages(This,aPages,cPages,pnPagesAdded)	\
    (This)->lpVtbl -> AddPages(This,aPages,cPages,pnPagesAdded)
#define IPublishingWizard_GetFirstPage(This,phpage)	\
    (This)->lpVtbl -> GetFirstPage(This,phpage)
#define IPublishingWizard_GetLastPage(This,phpage)	\
    (This)->lpVtbl -> GetLastPage(This,phpage)
#define IDefViewSafety_IsSafePage(This)	\
    (This)->lpVtbl -> IsSafePage(This)

// public\sdk\inc\spddkhlp.h
#define SP_IS_BAD_WRITE_PTR(p)     ( SPIsBadWritePtr( p, sizeof(*(p)) ))
#define SP_IS_BAD_READ_PTR(p)      ( SPIsBadReadPtr(  p, sizeof(*(p)) ))
#define SP_IS_BAD_OPTIONAL_WRITE_PTR(p)     ((p) && SPIsBadWritePtr( p, sizeof(*(p)) ))
#define SP_IS_BAD_OPTIONAL_READ_PTR(p)      ((p) && SPIsBadReadPtr(  p, sizeof(*(p)) ))
#define STACK_ALLOC(TYPE, COUNT) (TYPE *)_alloca(sizeof(TYPE) * (COUNT))
#define STACK_ALLOC_AND_ZERO(TYPE, COUNT) (TYPE *)memset(_alloca(sizeof(TYPE) * (COUNT)), 0, (sizeof(TYPE) * (COUNT)))
#define STACK_ALLOC_AND_COPY(TYPE, COUNT, SOURCE) (TYPE *)memcpy(_alloca(sizeof(TYPE) * (COUNT)), (SOURCE), (sizeof(TYPE) * (COUNT)))

// public\sdk\inc\stralign.h
#define WSTR_ALIGNED(s) (((DWORD_PTR)(s) & (sizeof(WCHAR)-1)) == 0)
#define __UA_WSTRSIZE(s)    ((__UA_WCSLEN(s)+1)*sizeof(WCHAR))
#define __UA_STRUC_ALIGNED(t,s) \
    (((DWORD_PTR)(s) & (TYPE_ALIGNMENT(t)-1)) == 0)
#define STRUC_ALIGNED_STACK_COPY(t,s) \
    __UA_STRUC_ALIGNED(t,s) ?   \
        ((t const *)(s)) :      \
        ((t const *)__UA_STACKCOPY((s),sizeof(t)))

// public\sdk\inc\strmif.h
#define IMemInputPin_ReceiveCanBlock(This)	\
    (This)->lpVtbl -> ReceiveCanBlock(This)
#define IAsyncReader_SyncReadAligned(This,pSample)	\
    (This)->lpVtbl -> SyncReadAligned(This,pSample)
#define IPinFlowControl_Block(This,dwBlockFlags,hEvent)	\
    (This)->lpVtbl -> Block(This,dwBlockFlags,hEvent)
#define IVMRMixerControl_SetBackgroundClr(This,ClrBkg)	\
    (This)->lpVtbl -> SetBackgroundClr(This,ClrBkg)
#define IVMRMixerControl_GetBackgroundClr(This,lpClrBkg)	\
    (This)->lpVtbl -> GetBackgroundClr(This,lpClrBkg)

// public\sdk\inc\tapi3.h
#define ITAgent_CreateSession(This,pACDGroup,pAddress,ppAgentSession)	\
    (This)->lpVtbl -> CreateSession(This,pACDGroup,pAddress,ppAgentSession)
#define ITAgent_CreateSessionWithPIN(This,pACDGroup,pAddress,pPIN,ppAgentSession)	\
    (This)->lpVtbl -> CreateSessionWithPIN(This,pACDGroup,pAddress,pPIN,ppAgentSession)
#define ITAgent_get_State(This,pAgentState)	\
    (This)->lpVtbl -> get_State(This,pAgentState)
#define ITAgentSession_get_Agent(This,ppAgent)	\
    (This)->lpVtbl -> get_Agent(This,ppAgent)
#define ITAgentEvent_get_Agent(This,ppAgent)	\
    (This)->lpVtbl -> get_Agent(This,ppAgent)
#define ITAgentHandlerEvent_get_AgentHandler(This,ppAgentHandler)	\
    (This)->lpVtbl -> get_AgentHandler(This,ppAgentHandler)
#define ITAgentHandler_CreateAgent(This,ppAgent)	\
    (This)->lpVtbl -> CreateAgent(This,ppAgent)
#define ITAgentHandler_CreateAgentWithID(This,pID,pPIN,ppAgent)	\
    (This)->lpVtbl -> CreateAgentWithID(This,pID,pPIN,ppAgent)

// public\sdk\inc\tapi3cc.h
#define ITAgent_CreateSession(This,pACDGroup,pAddress,ppAgentSession)	\
    (This)->lpVtbl -> CreateSession(This,pACDGroup,pAddress,ppAgentSession)
#define ITAgent_CreateSessionWithPIN(This,pACDGroup,pAddress,pPIN,ppAgentSession)	\
    (This)->lpVtbl -> CreateSessionWithPIN(This,pACDGroup,pAddress,pPIN,ppAgentSession)
#define ITAgent_get_State(This,pAgentState)	\
    (This)->lpVtbl -> get_State(This,pAgentState)
#define ITAgentSession_get_Agent(This,ppAgent)	\
    (This)->lpVtbl -> get_Agent(This,ppAgent)
#define ITAgentEvent_get_Agent(This,ppAgent)	\
    (This)->lpVtbl -> get_Agent(This,ppAgent)
#define ITAgentHandlerEvent_get_AgentHandler(This,ppAgentHandler)	\
    (This)->lpVtbl -> get_AgentHandler(This,ppAgentHandler)
#define ITAgentHandler_CreateAgent(This,ppAgent)	\
    (This)->lpVtbl -> CreateAgent(This,ppAgent)
#define ITAgentHandler_CreateAgentWithID(This,pID,pPIN,ppAgent)	\
    (This)->lpVtbl -> CreateAgentWithID(This,pID,pPIN,ppAgent)

// public\sdk\inc\tapi3err.h
#define TAPI_E_ADDRESSBLOCKED            ((HRESULT)0x8004002AL)

// public\sdk\inc\tapi3if.h
#define ITScriptableAudioFormat_get_AvgBytesPerSec(This,pVal)	\
    (This)->lpVtbl -> get_AvgBytesPerSec(This,pVal)
#define ITScriptableAudioFormat_put_AvgBytesPerSec(This,nNewVal)	\
    (This)->lpVtbl -> put_AvgBytesPerSec(This,nNewVal)
#define ITScriptableAudioFormat_get_BlockAlign(This,pVal)	\
    (This)->lpVtbl -> get_BlockAlign(This,pVal)
#define ITScriptableAudioFormat_put_BlockAlign(This,nNewVal)	\
    (This)->lpVtbl -> put_BlockAlign(This,nNewVal)

// public\sdk\inc\tdi.h
#define TDI_TRANSPORT_ADDRESS_LENGTH (sizeof (TdiTransportAddress) - 1)
#define TDI_CONNECTION_CONTEXT_LENGTH (sizeof (TdiConnectionContext) - 1)
#define TDI_ADDRESS_LENGTH_NETBIOS sizeof (TDI_ADDRESS_NETBIOS)
#define TDI_ADDRESS_LENGTH_NETBIOS_EX sizeof(TDI_ADDRESS_NETBIOS_EX)
#define TDI_ADDRESS_LENGTH_NETONE sizeof (TDI_ADDRESS_NETONE)
#define TDI_ADDRESS_LENGTH_APPLETALK sizeof (TDI_ADDRESS_APPLETALK)
#define TDI_ADDRESS_LENGTH_8022  sizeof (TDI_ADDRESS_8022);
#define TDI_ADDRESS_LENGTH_IP sizeof (TDI_ADDRESS_IP)
#define TDI_ADDRESS_LENGTH_IP6 sizeof (TDI_ADDRESS_IP6)
#define TDI_ADDRESS_LENGTH_IPX sizeof (TDI_ADDRESS_IPX)
#define TDI_ADDRESS_LENGTH_NS sizeof (TDI_ADDRESS_NS)
#define TDI_ADDRESS_LENGTH_VNS sizeof (TDI_ADDRESS_VNS)
#define TDI_ADDRESS_LENGTH_OSI_TSAP sizeof (TDI_ADDRESS_OSI_TSAP)

// public\sdk\inc\tnef.h
#define CbOfTrp(_p)		(sizeof(TRP) + (_p)->cch + (_p)->cbRgb)
#define cbALIAS sizeof(ALIAS)
#define cbNSID sizeof(NSID)

// public\sdk\inc\tom.h
#define ITextDocument_Open(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Open(This,pVar,Flags,CodePage)
#define ITextDocument_Save(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Save(This,pVar,Flags,CodePage)
#define ITextPara_GetAlignment(This,pValue)	\
    (This)->lpVtbl -> GetAlignment(This,pValue)
#define ITextPara_SetAlignment(This,Value)	\
    (This)->lpVtbl -> SetAlignment(This,Value)
#define ITextPara_GetListAlignment(This,pValue)	\
    (This)->lpVtbl -> GetListAlignment(This,pValue)
#define ITextPara_SetListAlignment(This,Value)	\
    (This)->lpVtbl -> SetListAlignment(This,Value)
#define ITextPara_GetPageBreakBefore(This,pValue)	\
    (This)->lpVtbl -> GetPageBreakBefore(This,pValue)
#define ITextPara_SetPageBreakBefore(This,Value)	\
    (This)->lpVtbl -> SetPageBreakBefore(This,Value)
#define ITextPara_AddTab(This,tbPos,tbAlign,tbLeader)	\
    (This)->lpVtbl -> AddTab(This,tbPos,tbAlign,tbLeader)
#define ITextPara_GetTab(This,iTab,ptbPos,ptbAlign,ptbLeader)	\
    (This)->lpVtbl -> GetTab(This,iTab,ptbPos,ptbAlign,ptbLeader)
#define ITextDocument2_Open(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Open(This,pVar,Flags,CodePage)
#define ITextDocument2_Save(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Save(This,pVar,Flags,CodePage)
#define ITextDocument2_GetPreferredFont(This,cp,CodePage,Option,curCodepage,curFontSize,pbstr,pPitchAndFamily,pNewFontSize)	\
    (This)->lpVtbl -> GetPreferredFont(This,cp,CodePage,Option,curCodepage,curFontSize,pbstr,pPitchAndFamily,pNewFontSize)

// public\sdk\inc\tstr.h
#define STRSIZE(p)      ((STRLEN(p)+1) * sizeof(TCHAR))
#define WCSSIZE(s)      ((MAKE_STR_FUNCTION(wcslen)(s)+1) * sizeof(WCHAR))
#define STRING_SPACE_REQD(n)    ((n) * sizeof(_CHAR_TYPE))
#define DOWN_LEVEL_STRSIZE(n)   ((n) / sizeof(_CHAR_TYPE))

// public\sdk\inc\tvratings.h
#define IEvalRat_get_BlockedRatingAttributes(This,enSystem,enLevel,plbfAttrs)	\
    (This)->lpVtbl -> get_BlockedRatingAttributes(This,enSystem,enLevel,plbfAttrs)
#define IEvalRat_put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs)	\
    (This)->lpVtbl -> put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs)
#define IEvalRat_get_BlockUnRated(This,pfBlockUnRatedShows)	\
    (This)->lpVtbl -> get_BlockUnRated(This,pfBlockUnRatedShows)
#define IEvalRat_put_BlockUnRated(This,fBlockUnRatedShows)	\
    (This)->lpVtbl -> put_BlockUnRated(This,fBlockUnRatedShows)

// public\sdk\inc\unaligned.hpp
#define SET2(val,data)                          \
    data[0] = (val) >> 8,                       \
    data[1] = (val)
#define GET2(data)                              \
    ( ( data[0] << 8 ) |                        \
      ( data[1] ) )
#define SET4(val,data)                          \
    data[0] = (val) >> 24,                      \
    data[1] = (val) >> 16,                      \
    data[2] = (val) >> 8,                       \
    data[3] = (val)
#define GET4(data)                              \
    ( ( data[0] << 24 ) |                       \
      ( data[1] << 16 ) |                       \
      ( data[2] << 8 ) |                        \
      ( data[3] ) )
#define SET8(val,data)                          \
    data[0] = (val) >> 56,                      \
    data[1] = (val) >> 48,                      \
    data[2] = (val) >> 40,                      \
    data[3] = (val) >> 32                       \
    data[4] = (val) >> 24,                      \
    data[5] = (val) >> 16,                      \
    data[6] = (val) >> 8,                       \
    data[7] = (val)
#define GET8(data)                              \
    ( ( data[0] << 56 ) |                       \
      ( data[1] << 48 ) |                       \
      ( data[2] << 40 ) |                       \
      ( data[3] << 32 ) |                       \
      ( data[4] << 24 ) |                       \
      ( data[5] << 16 ) |                       \
      ( data[6] << 8 ) |                        \
      ( data[7] ) )
#define SET648(val,data)                        \
    data[0] = (val) >> 32,                      \
    data[1] = (val)
#define GET648(data)                            \
    ( ( data[0] << 32 ) |                       \
      ( data[1] ) )
#define SET2(val,data)                          \
    data[1] = (val) >> 8,                       \
    data[0] = (val)
#define GET2(data)                              \
    ( ( data[1] << 8 ) |                        \
      ( data[0] ) )
#define SET4(val,data)                          \
    data[3] = (val) >> 24,                      \
    data[2] = (val) >> 16,                      \
    data[1] = (val) >> 8,                       \
    data[0] = (val)
#define GET4(data)                              \
    ( ( data[3] << 24 ) |                       \
      ( data[2] << 16 ) |                       \
      ( data[1] << 8 ) |                        \
      ( data[0] ) )
#define SET8(val,data)                          \
    data[7] = (val) >> 56,                      \
    data[6] = (val) >> 48,                      \
    data[5] = (val) >> 40,                      \
    data[4] = (val) >> 32,                      \
    data[3] = (val) >> 24,                      \
    data[2] = (val) >> 16,                      \
    data[1] = (val) >> 8,                       \
    data[0] = (val)
#define GET8(data)                              \
    ( ( data[7] << 56 ) |                       \
      ( data[6] << 48 ) |                       \
      ( data[5] << 40 ) |                       \
      ( data[4] << 32 ) |                       \
      ( data[3] << 24 ) |                       \
      ( data[2] << 16 ) |                       \
      ( data[1] << 8 ) |                        \
      ( data[0] ) )
#define SET648(val,data)                        \
    data[1] = (val) >> 32,                      \
    data[0] = (val)
#define GET648(data)                            \
    ( ( data[1] << 32 ) |                       \
      ( data[0] ) )
#define GROUP(type,size,get,set,sfx)                                    \
    Unaligned##sfx##size( type v ) { set##size( v, data ); }            \
    type operator = ( type v )     { set##size( v, data ); return v; }  \
    operator type()           { return get##size( data ); }             \
    type operator += (const type v) { set##size( get##size(data) + v, data); return *this; } \
    type operator -= (const type v) { set##size( get##size(data) - v, data); return *this; } \
    type operator <<= (const type v) { set##size( get##size(data) << v, data); return *this; } \
    type operator *= (const type v) { set##size( get##size(data) * v, data); return *this; } \
    type operator /= (const type v) { set##size( get##size(data) / v, data); return *this; } \
    type operator %= (const type v) { set##size( get##size(data) % v, data); return *this; } \
    type operator >>= (const type v) { set##size( get##size(data) >> v, data); return *this; } \
    type operator ^= (const type v) { set##size( get##size(data) ^ v, data); return *this; } \
    type operator &= (const type v) { set##size( get##size(data) & v, data); return *this; } \
    type operator |= (const type v) { set##size( get##size(data) | v, data); return *this; } \
#define MAKE_TEMPLATE(size,type,sfx)                            \
template<class BASE>                                            \
class Unaligned##sfx##size<BASE>                                \
{                                                               \
  protected:                                                    \
    type data[ size / sizeof(type) ];                           \
                                                                \
  public:                                                       \
                                                                \
    GROUP( signed char,      size, GET##sfx, SET##sfx, sfx )    \
    GROUP( short,            size, GET##sfx, SET##sfx, sfx )    \
    GROUP( int,              size, GET##sfx, SET##sfx, sfx )    \
    GROUP( wchar_t,          size, GET##sfx, SET##sfx, sfx )    \
    GROUP( long,             size, GET##sfx, SET##sfx, sfx )    \
    GROUP( __int64,          size, GET##sfx, SET##sfx, sfx )    \
    GROUP( unsigned char,    size, GET##sfx, SET##sfx, sfx )    \
    GROUP( unsigned short,   size, GET##sfx, SET##sfx, sfx )    \
    GROUP( unsigned int,     size, GET##sfx, SET##sfx, sfx )    \
    GROUP( unsigned long,    size, GET##sfx, SET##sfx, sfx )    \
    GROUP( unsigned __int64, size, GET##sfx, SET##sfx, sfx )    \
}

// public\sdk\inc\unimodem.h
    #define RAWDIAGNOSTICS_DATA(_plinediagnostics)                          \
            (  (BYTE*)(_plinediagnostics)                                   \
             + ((_plinediagnostics)->dwRawDiagnosticsOffset)                \
             + sizeof(LINEDIAGNOSTICSOBJECTHEADER))
    #define PARSEDDIAGNOSTICS_DATA(_plinediagnostics)                       \
                            ((LINEDIAGNOSTICS_PARSEREC*)                    \
                            (  (BYTE*)(_plinediagnostics)                   \
                             + ((_plinediagnostics)->dwParsedDiagnosticsOffset)\
                             + sizeof(LINEDIAGNOSTICSOBJECTHEADER)))

// public\sdk\inc\vdmdbg.h
#define VDMCONTEXT_LENGTH  (sizeof(VDMCONTEXT))
#define VDMCONTEXT_ALIGN   (sizeof(ULONG))

// public\sdk\inc\vfw.h
#define ICGetDefaultQuality(hic) \
    (ICSendMessage(hic, ICM_GETDEFAULTQUALITY, (DWORD_PTR)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)
#define ICGetDefaultKeyFrameRate(hic) \
    (ICSendMessage(hic, ICM_GETDEFAULTKEYFRAMERATE, (DWORD_PTR)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)
#define ICDrawWindow(hic, prc) \
    ICSendMessage(hic, ICM_DRAW_WINDOW, (DWORD_PTR)(LPVOID)(prc), sizeof(RECT))
#define ICDrawRealize(hic, hdc, fBackground) \
    ICSendMessage(hic, ICM_DRAW_REALIZE, (DWORD_PTR)(UINT_PTR)(HDC)(hdc), (DWORD_PTR)(BOOL)(fBackground))

// public\sdk\inc\vfwext.h
#define VFW_HIDE_ALL_PAGES           (VFW_HIDE_SETTINGS_PAGE |\
                                     VFW_HIDE_VIDEOSRC_PAGE  |\
                                     VFW_HIDE_CAMERACONTROL_PAGE)

// public\sdk\inc\vfwmsgs.h
#define VFW_E_BADALIGN                   ((HRESULT)0x8004020EL)
#define VFW_E_PIN_ALREADY_BLOCKED_ON_THIS_THREAD ((HRESULT)0x80040293L)
#define VFW_E_PIN_ALREADY_BLOCKED        ((HRESULT)0x80040294L)

// public\sdk\inc\wabapi.h
#define CBIWABOBJECT sizeof(IWABOBJECT)

// public\sdk\inc\wabdefs.h
#define IsEqualMAPIUID(lpuid1, lpuid2)  (!memcmp(lpuid1, lpuid2, sizeof(MAPIUID)))
#define CbNewADRLIST(_centries) \
    (offsetof(ADRLIST,aEntries) + (_centries)*sizeof(ADRENTRY))
#define CbADRLIST(_lpadrlist) \
    (offsetof(ADRLIST,aEntries) + (UINT)(_lpadrlist)->cEntries*sizeof(ADRENTRY))
#define CbNewSRowSet(_crow)     (offsetof(SRowSet,aRow) + (_crow)*sizeof(SRow))
#define CbSRowSet(_lprowset)    (offsetof(SRowSet,aRow) + \
                                    (UINT)((_lprowset)->cRows*sizeof(SRow)))
#define CbNewSSortOrderSet(_csort) \
    (offsetof(SSortOrderSet,aSort) + (_csort)*sizeof(SSortOrder))
#define CbSSortOrderSet(_lpset) \
    (offsetof(SSortOrderSet,aSort) + \
    (UINT)((_lpset)->cSorts*sizeof(SSortOrder)))

// public\sdk\inc\wdbgexts.h
#define GetKdContext(ppi) \
    Ioctl( IG_KD_CONTEXT, (PVOID)ppi, sizeof(*ppi) )
#define ReadTypedControlSpace32( _Proc, _Addr, _Buf )  \
     ReadControlSpace64( (USHORT)(_Proc), (ULONG)(_Addr), (PVOID)&(_Buf), (ULONG)sizeof(_Buf) )
#define ReadTypedControlSpace64( _Proc, _Addr, _Buf )  \
     ReadControlSpace64( (USHORT)(_Proc), (ULONG64)(_Addr), (PVOID)&(_Buf), (ULONG)sizeof(_Buf) )
#define GetFieldValue(Addr, Type, Field, OutValue)         \
     GetFieldData(Addr, Type, Field, sizeof(OutValue), (PVOID) &(OutValue))

// public\sdk\inc\wdm.h
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))
#define ALIGN_DOWN_POINTER(address, type) \
    ((PVOID)((ULONG_PTR)(address) & ~((ULONG_PTR)sizeof(type) - 1)))
#define ALIGN_UP_POINTER(address, type) \
    (ALIGN_DOWN_POINTER(((ULONG_PTR)(address) + sizeof(type) - 1), type))
#define MDL_MAPPING_FLAGS (MDL_MAPPED_TO_SYSTEM_VA     | \
                           MDL_PAGES_LOCKED            | \
                           MDL_SOURCE_IS_NONPAGED_POOL | \
                           MDL_PARTIAL_HAS_BEEN_MAPPED | \
                           MDL_PARENT_MAPPED_SYSTEM_VA | \
                           MDL_SYSTEM_VA               | \
                           MDL_IO_SPACE )
#define PAGED_CODE() \
    { if (KeGetCurrentIrql() > APC_LEVEL) { \
          KdPrint(( "EX: Pageable code called at IRQL %d\n", KeGetCurrentIrql() )); \
          ASSERT(FALSE); \
       } \
    }
#define RtlUnicodeStringToAnsiSize(STRING) (                  \
    NLS_MB_CODE_PAGE_TAG ?                                    \
    RtlxUnicodeStringToAnsiSize(STRING) :                     \
    ((STRING)->Length + sizeof(UNICODE_NULL)) / sizeof(WCHAR) \
)
#define RtlAnsiStringToUnicodeSize(STRING) (                 \
    NLS_MB_CODE_PAGE_TAG ?                                   \
    RtlxAnsiStringToUnicodeSize(STRING) :                    \
    ((STRING)->Length + sizeof(ANSI_NULL)) * sizeof(WCHAR) \
)
        #define IsEqualGUIDAligned(guid1, guid2) \
            ((*(PLONGLONG)(guid1) == *(PLONGLONG)(guid2)) && (*((PLONGLONG)(guid1) + 1) == *((PLONGLONG)(guid2) + 1)))
#define SHORT_SIZE  (sizeof(USHORT))
#define LONG_SIZE       (sizeof(LONG))
#define LONGLONG_SIZE   (sizeof(LONGLONG))
#define RtlStoreUlonglong(ADDRESS,VALUE)                        \
         if ((ULONG_PTR)(ADDRESS) & LONGLONG_MASK) {            \
             RtlStoreUlong((ULONG_PTR)(ADDRESS),                \
                           (ULONGLONG)(VALUE) & 0xFFFFFFFF);    \
             RtlStoreUlong((ULONG_PTR)(ADDRESS)+sizeof(ULONG),  \
                           (ULONGLONG)(VALUE) >> 32);           \
         } else {                                               \
             *((PULONGLONG)(ADDRESS)) = (ULONGLONG)(VALUE);     \
         }
#define IO_ERROR_LOG_MESSAGE_HEADER_LENGTH (sizeof(IO_ERROR_LOG_MESSAGE) -    \
                                            sizeof(IO_ERROR_LOG_PACKET) +     \
                                            (sizeof(WCHAR) * 40))
#define ROUND_TO_PAGES(Size)  (((ULONG_PTR)(Size) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))
#define BYTES_TO_PAGES(Size)  ((ULONG)((ULONG_PTR)(Size) >> PAGE_SHIFT) + \
                               (((ULONG)(Size) & (PAGE_SIZE - 1)) != 0))
#define BYTE_OFFSET(Va) ((ULONG)((LONG_PTR)(Va) & (PAGE_SIZE - 1)))
#define PAGE_ALIGN(Va) ((PVOID)((ULONG_PTR)(Va) & ~(PAGE_SIZE - 1)))
#define ADDRESS_AND_SIZE_TO_SPAN_PAGES(Va,Size) \
    ((ULONG)((((ULONG_PTR)(Va) & (PAGE_SIZE -1)) + (Size) + (PAGE_SIZE - 1)) >> PAGE_SHIFT))
#define MmInitializeMdl(MemoryDescriptorList, BaseVa, Length) { \
    (MemoryDescriptorList)->Next = (PMDL) NULL; \
    (MemoryDescriptorList)->Size = (CSHORT)(sizeof(MDL) +  \
            (sizeof(PFN_NUMBER) * ADDRESS_AND_SIZE_TO_SPAN_PAGES((BaseVa), (Length)))); \
    (MemoryDescriptorList)->MdlFlags = 0; \
    (MemoryDescriptorList)->StartVa = (PVOID) PAGE_ALIGN((BaseVa)); \
    (MemoryDescriptorList)->ByteOffset = BYTE_OFFSET((BaseVa)); \
    (MemoryDescriptorList)->ByteCount = (ULONG)(Length); \
    }
#define MmGetSystemAddressForMdlSafe(MDL, PRIORITY)                    \
     (((MDL)->MdlFlags & (MDL_MAPPED_TO_SYSTEM_VA |                    \
                        MDL_SOURCE_IS_NONPAGED_POOL)) ?                \
                             ((MDL)->MappedSystemVa) :                 \
                             (MmMapLockedPagesSpecifyCache((MDL),      \
                                                           KernelMode, \
                                                           MmCached,   \
                                                           NULL,       \
                                                           FALSE,      \
                                                           (PRIORITY))))
#define MmGetSystemAddressForMdl(MDL)                                  \
     (((MDL)->MdlFlags & (MDL_MAPPED_TO_SYSTEM_VA |                    \
                        MDL_SOURCE_IS_NONPAGED_POOL)) ?                \
                             ((MDL)->MappedSystemVa) :                 \
                             (MmMapLockedPages((MDL),KernelMode)))
#define MmPrepareMdlForReuse(MDL)                                       \
    if (((MDL)->MdlFlags & MDL_PARTIAL_HAS_BEEN_MAPPED) != 0) {         \
        ASSERT(((MDL)->MdlFlags & MDL_PARTIAL) != 0);                   \
        MmUnmapLockedPages( (MDL)->MappedSystemVa, (MDL) );             \
    } else if (((MDL)->MdlFlags & MDL_PARTIAL) == 0) {                  \
        ASSERT(((MDL)->MdlFlags & MDL_MAPPED_TO_SYSTEM_VA) == 0);       \
    }
#define IoInitializeRemoveLock(Lock, Tag, Maxmin, HighWater) \
        IoInitializeRemoveLockEx (Lock, Tag, Maxmin, HighWater, sizeof (IO_REMOVE_LOCK))
#define IoAcquireRemoveLock(RemoveLock, Tag) \
        IoAcquireRemoveLockEx(RemoveLock, Tag, __FILE__, __LINE__, sizeof (IO_REMOVE_LOCK))
#define IoReleaseRemoveLock(RemoveLock, Tag) \
        IoReleaseRemoveLockEx(RemoveLock, Tag, sizeof (IO_REMOVE_LOCK))
#define IoReleaseRemoveLockAndWait(RemoveLock, Tag) \
        IoReleaseRemoveLockAndWaitEx(RemoveLock, Tag, sizeof (IO_REMOVE_LOCK))
#define IoSizeOfIrp( StackSize ) \
    ((USHORT) (sizeof( IRP ) + ((StackSize) * (sizeof( IO_STACK_LOCATION )))))

// public\sdk\inc\webcheck.h
#define ISubscriptionAgentShellExt_RemovePages(This,hdlg)	\
    (This)->lpVtbl -> RemovePages(This,hdlg)
#define ISubscriptionMgrPriv_RemovePages(This,hdlg)	\
    (This)->lpVtbl -> RemovePages(This,hdlg)

// public\sdk\inc\winbase.inl
#define WINBASE_NUMBER_OF(x) (sizeof(x) / sizeof((x)[0]))

// public\sdk\inc\wincred.h
#define CRED_SESSION_WILDCARD_NAME_LENGTH (sizeof(CRED_SESSION_WILDCARD_NAME_A)-1)

// public\sdk\inc\wincrypt.h
#define ALG_TYPE_BLOCK                  (3 << 9)
#define CALG_DES                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_DES)
#define CALG_3DES_112           (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_3DES_112)
#define CALG_3DES               (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_3DES)
#define CALG_DESX               (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_DESX)
#define CALG_RC2                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_RC2)
#define CALG_SKIPJACK           (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_SKIPJACK)
#define CALG_TEK                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_TEK)
#define CALG_CYLINK_MEK         (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_CYLINK_MEK)
#define CALG_RC5                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_RC5)
#define CALG_AES_128            (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES_128)
#define CALG_AES_192            (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES_192)
#define CALG_AES_256            (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES_256)
#define CALG_AES                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES)

// public\sdk\inc\windns.h
#define DNS_OFFSET_TO_QUESTION_NAME     sizeof(DNS_HEADER)
#define IS_WORD_ALIGNED(p)      ( !((UINT_PTR)(p) & (UINT_PTR)1) )
#define IS_QWORD_ALIGNED(p)     ( !((UINT_PTR)(p) & (UINT_PTR)7) )
#define DNS_WINS_RECORD_LENGTH(IpCount) \
            (FIELD_OFFSET(DNS_WINS_DATA, WinsServers) + ((IpCount) * sizeof(IP4_ADDRESS)))

// public\sdk\inc\winerror.h
#define STG_S_BLOCK                      _HRESULT_TYPEDEF_(0x00030201L)
#define CERTSRV_E_ALIGNMENT_FAULT        _HRESULT_TYPEDEF_(0x80094010L)
#define SPAPI_E_INVALID_PROPPAGE_PROVIDER _HRESULT_TYPEDEF_(0x800F0224L)
#define SCARD_W_CHV_BLOCKED              _HRESULT_TYPEDEF_(0x8010006CL)

// public\sdk\inc\wininet.h
#define INTERNET_MAX_URL_LENGTH         (INTERNET_MAX_SCHEME_LENGTH \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// public\sdk\inc\winioctl.h
#define IOCTL_DISK_REASSIGN_BLOCKS      CTL_CODE(IOCTL_DISK_BASE, 0x0007, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define DiskGeometryGetDetect(Geometry)\
                        ((PDISK_DETECTION_INFO)(((PBYTE)DiskGeometryGetPartition(Geometry)+\
                                        DiskGeometryGetPartition(Geometry)->SizeOfPartitionInfo)))
#define HISTOGRAM_BUCKET_SIZE   sizeof(HISTOGRAM_BUCKET)
#define DISK_HISTOGRAM_SIZE sizeof(DISK_HISTOGRAM)

// public\sdk\inc\winnt.h
#define MAX_NATURAL_ALIGNMENT sizeof(ULONGLONG)
#define MAX_NATURAL_ALIGNMENT sizeof(DWORD)
#define TYPE_ALIGNMENT( t ) \
    FIELD_OFFSET( struct { char x; t test; }, test )
#define PROBE_ALIGNMENT( _s ) (TYPE_ALIGNMENT( _s ) > TYPE_ALIGNMENT( DWORD ) ? \
                               TYPE_ALIGNMENT( _s ) : TYPE_ALIGNMENT( DWORD ))
#define RTL_FIELD_SIZE(type, field) (sizeof(((type *)0)->field))
#define RTL_SIZEOF_THROUGH_FIELD(type, field) \
    (FIELD_OFFSET(type, field) + RTL_FIELD_SIZE(type, field))
#define RTL_CONTAINS_FIELD(Struct, Size, Field) \
    ( (((PCHAR)(&(Struct)->Field)) + sizeof((Struct)->Field)) <= (((PCHAR)(Struct))+(Size)) )
#define RTL_BITS_OF(sizeOfArg) (sizeof(sizeOfArg) * 8)
#define LEGACY_SAVE_AREA_LENGTH  ((sizeof(LEGACY_SAVE_AREA) + 15) & ~15)
#define SECURITY_DESCRIPTOR_MIN_LENGTH   (sizeof(SECURITY_DESCRIPTOR))
#define IMAGE_FIRST_SECTION( ntheader ) ((PIMAGE_SECTION_HEADER)        \
    ((ULONG_PTR)ntheader +                                              \
     FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +                 \
     ((PIMAGE_NT_HEADERS)(ntheader))->FileHeader.SizeOfOptionalHeader   \
    ))

// public\sdk\inc\winsock.h
#define _IOR(x,y,t)     (IOC_OUT|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))
#define _IOW(x,y,t)     (IOC_IN|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))

// public\sdk\inc\winsock2.h
#define _IOR(x,y,t)     (IOC_OUT|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))
#define _IOW(x,y,t)     (IOC_IN|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))
#define _SS_ALIGNSIZE (sizeof(__int64))  // Desired alignment.
#define _SS_PAD1SIZE (_SS_ALIGNSIZE - sizeof (short))
#define _SS_PAD2SIZE (_SS_MAXSIZE - (sizeof (short) + _SS_PAD1SIZE \
                                                    + _SS_ALIGNSIZE))

// public\sdk\inc\winuser.h
#define DWLP_DLGPROC    DWLP_MSGRESULT + sizeof(LRESULT)
#define DWLP_USER       DWLP_DLGPROC + sizeof(DLGPROC)
#define SIF_ALL             (SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)
#define RAWINPUT_ALIGN(x)   (((x) + sizeof(QWORD) - 1) & ~(sizeof(QWORD) - 1))
#define RAWINPUT_ALIGN(x)   (((x) + sizeof(DWORD) - 1) & ~(sizeof(DWORD) - 1))
#define NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->header.dwSize)))

// public\sdk\inc\wmidata.h
    #define MSWmi_MofData_Unused1_SIZE sizeof(ULONG)
    #define MSWmi_MofData_Unused2_SIZE sizeof(ULONG)
    #define MSWmi_MofData_Size_SIZE sizeof(ULONG)
    #define MSWmi_MofData_Unused4_SIZE sizeof(ULONG)
    #define MSWmi_PnPInstanceNames_Count_SIZE sizeof(ULONG)
    #define MSWmi_Guid_Guid_SIZE sizeof(UCHAR[16])
    #define MSWmi_GuidRegistrationInfo_Operation_SIZE sizeof(ULONG)
    #define MSWmi_GuidRegistrationInfo_GuidCount_SIZE sizeof(ULONG)
    #define MSAcpiInfo_BootArchitecture_SIZE sizeof(ULONG)
    #define MSAcpiInfo_PreferredProfile_SIZE sizeof(ULONG)
    #define MSAcpiInfo_Capabilities_SIZE sizeof(ULONG)
    #define MSSmBios_RawSMBiosTables_Used20CallingMethod_SIZE sizeof(BOOLEAN)
    #define MSSmBios_RawSMBiosTables_SmbiosMajorVersion_SIZE sizeof(UCHAR)
    #define MSSmBios_RawSMBiosTables_SmbiosMinorVersion_SIZE sizeof(UCHAR)
    #define MSSmBios_RawSMBiosTables_DmiRevision_SIZE sizeof(UCHAR)
    #define MSSmBios_RawSMBiosTables_Size_SIZE sizeof(ULONG)
    #define SYSID_UUID_Uuid_SIZE sizeof(UCHAR[16])
    #define MSSmBios_SysidUUIDList_Count_SIZE sizeof(ULONG)
    #define SYSID_1394_x1394_SIZE sizeof(UCHAR[8])
    #define MSSmBios_Sysid1394List_Count_SIZE sizeof(ULONG)
    #define MSMCAEvent_Header_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_Header_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_Header_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_Header_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_Header_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_CPUError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_CPUError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_CPUError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_CPUError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_CPUError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_CPUError_Level_SIZE sizeof(ULONG)
    #define MSMCAEvent_CPUError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_MemoryError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_MemoryError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_MemoryError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_MemoryError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_MemoryError_VALIDATION_BITS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_MEM_ERROR_STATUS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_MEM_PHYSICAL_ADDR_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_MEM_PHYSICAL_MASK_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_RESPONDER_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_TARGET_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_REQUESTOR_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_BUS_SPECIFIC_DATA_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_MemoryError_MEM_NODE_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_MEM_CARD_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_MEM_BANK_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_xMEM_DEVICE_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_MEM_MODULE_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_MEM_ROW_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_MEM_COLUMN_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_MEM_BIT_POSITION_SIZE sizeof(USHORT)
    #define MSMCAEvent_MemoryError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIBusError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIBusError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIBusError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIBusError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIBusError_VALIDATION_BITS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_ERROR_STATUS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_ADDRESS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_DATA_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_CMD_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_REQUESTOR_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_RESPONDER_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_TARGET_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIBusError_PCI_BUS_ERROR_TYPE_SIZE sizeof(USHORT)
    #define MSMCAEvent_PCIBusError_PCI_BUS_ID_BusNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIBusError_PCI_BUS_ID_SegmentNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIBusError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIComponentError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIComponentError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIComponentError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIComponentError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_PCIComponentError_VALIDATION_BITS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_ERROR_STATUS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_VendorId_SIZE sizeof(USHORT)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_DeviceId_SIZE sizeof(USHORT)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_ClassCodeInterface_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_ClassCodeSubClass_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_ClassCodeBaseClass_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_FunctionNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_DeviceNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_BusNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_SegmentNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_SystemEventError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_SystemEventError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_SystemEventError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_SystemEventError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_SystemEventError_VALIDATION_BITS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_SystemEventError_SEL_TIME_STAMP_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_SystemEventError_SEL_RECORD_ID_SIZE sizeof(USHORT)
    #define MSMCAEvent_SystemEventError_SEL_GENERATOR_ID_SIZE sizeof(USHORT)
    #define MSMCAEvent_SystemEventError_SEL_RECORD_TYPE_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_EVM_REV_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_SENSOR_TYPE_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_SENSOR_NUM_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_EVENT_DIR_TYPE_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_DATA1_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_DATA2_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_DATA3_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_SMBIOSError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_SMBIOSError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SMBIOSError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_SMBIOSError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_SMBIOSError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_SMBIOSError_VALIDATION_BITS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_SMBIOSError_SMBIOS_EVENT_TYPE_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SMBIOSError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_PlatformSpecificError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PlatformSpecificError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_PlatformSpecificError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_PlatformSpecificError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_PlatformSpecificError_VALIDATION_BITS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_PLATFORM_ERROR_STATUS_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_PLATFORM_REQUESTOR_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_PLATFORM_RESPONDER_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_PLATFORM_TARGET_ID_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_PLATFORM_BUS_SPECIFIC_DATA_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_PlatformSpecificError_OEM_COMPONENT_ID_SIZE sizeof(UCHAR[16])
    #define MSMCAEvent_PlatformSpecificError_Size_SIZE sizeof(ULONG)
    #define MSMCAEvent_InvalidError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_InvalidError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_InvalidError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_InvalidError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_InvalidError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_InvalidError_Size_SIZE sizeof(ULONG)
    #define MSMCAInfo_Entry_Length_SIZE sizeof(ULONG)
    #define MSMCAInfo_RawMCAData_Count_SIZE sizeof(ULONG)
    #define MSMCAInfo_RawCMCEvent_Count_SIZE sizeof(ULONG)
    #define MSMCAInfo_RawMCAEvent_Count_SIZE sizeof(ULONG)
    #define MSMCAInfo_RawCorrectedPlatformEvent_Count_SIZE sizeof(ULONG)
    #define MSMCAInfo_CPEControl_CPEPollingInterval_SIZE sizeof(ULONG)
    #define MSMCAInfo_CPEControl_CPEGenerationEnabled_SIZE sizeof(BOOLEAN)
    #define MSPower_DeviceEnable_Enable_SIZE sizeof(BOOLEAN)
    #define MSPower_DeviceWakeEnable_Enable_SIZE sizeof(BOOLEAN)
    #define MSNdis_NetworkAddress_Address_SIZE sizeof(UCHAR[6])
    #define MSNdis_NetworkShortAddress_Address_SIZE sizeof(UCHAR[2])
    #define MSNdis_NetworkLinkSpeed_Outbound_SIZE sizeof(ULONG)
    #define MSNdis_NetworkLinkSpeed_Inbound_SIZE sizeof(ULONG)
    #define MSNdis_DeviceWakeOnMagicPacketOnly_EnableWakeOnMagicPacketOnly_SIZE sizeof(BOOLEAN)
    #define MSNdis_HardwareStatus_NdisHardwareStatus_SIZE sizeof(ULONG)
    #define MSNdis_MaximumLookahead_NdisMaximumLookahead_SIZE sizeof(ULONG)
    #define MSNdis_MaximumFrameSize_NdisMaximumFrameSize_SIZE sizeof(ULONG)
    #define MSNdis_LinkSpeed_NdisLinkSpeed_SIZE sizeof(ULONG)
    #define MSNdis_TransmitBufferSpace_NdisTransmitBufferSpace_SIZE sizeof(ULONG)
    #define MSNdis_ReceiveBufferSpace_NdisReceiveBufferSpace_SIZE sizeof(ULONG)
    #define MSNdis_TransmitBlockSize_NdisTransmitBlockSize_SIZE sizeof(ULONG)
    #define MSNdis_ReceiveBlockSize_NdisReceiveBlockSize_SIZE sizeof(ULONG)
    #define MSNdis_VendorID_NdisVendorID_SIZE sizeof(ULONG)
    #define MSNdis_CurrentPacketFilter_NdisCurrentPacketFilter_SIZE sizeof(ULONG)
    #define MSNdis_CurrentLookahead_NdisCurrentLookahead_SIZE sizeof(ULONG)
    #define MSNdis_DriverVersion_NdisDriverVersion_SIZE sizeof(USHORT)
    #define MSNdis_MaximumTotalSize_NdisMaximumTotalSize_SIZE sizeof(ULONG)
    #define MSNdis_MacOptions_NdisMacOptions_SIZE sizeof(ULONG)
    #define MSNdis_MediaConnectStatus_NdisMediaConnectStatus_SIZE sizeof(ULONG)
    #define MSNdis_MaximumSendPackets_NdisMaximumSendPackets_SIZE sizeof(ULONG)
    #define MSNdis_VendorDriverVersion_NdisVendorDriverVersion_SIZE sizeof(ULONG)
    #define MSNdis_VlanIdentifier_NdisVlanId_SIZE sizeof(ULONG)
    #define MSNdis_PhysicalMediumType_NdisPhysicalMediumType_SIZE sizeof(ULONG)
    #define MSNdis_TransmitsOk_NdisTransmitsOk_SIZE sizeof(ULONGLONG)
    #define MSNdis_ReceivesOk_NdisReceivesOk_SIZE sizeof(ULONGLONG)
    #define MSNdis_TransmitsError_NdisTransmitsError_SIZE sizeof(ULONG)
    #define MSNdis_ReceiveError_NdisReceiveError_SIZE sizeof(ULONG)
    #define MSNdis_ReceiveNoBuffer_NdisReceiveNoBuffer_SIZE sizeof(ULONG)
    #define MSNdis_CoHardwareStatus_NdisCoHardwareStatus_SIZE sizeof(ULONG)
    #define MSNdis_CoLinkSpeed_NdisCoLinkSpeed_SIZE sizeof(MSNdis_NetworkLinkSpeed)
    #define MSNdis_CoVendorId_NdisCoVendorID_SIZE sizeof(ULONG)
    #define MSNdis_CoDriverVersion_NdisCoDriverVersion_SIZE sizeof(USHORT)
    #define MSNdis_CoMacOptions_NdisCoMacOptions_SIZE sizeof(ULONG)
    #define MSNdis_CoMediaConnectStatus_NdisCoMediaConnectStatus_SIZE sizeof(ULONG)
    #define MSNdis_CoVendorDriverVersion_NdisCoVendorDriverVersion_SIZE sizeof(ULONG)
    #define MSNdis_CoMinimumLinkSpeed_NdisCoMinimumLinkSpeed_SIZE sizeof(MSNdis_NetworkLinkSpeed)
    #define MSNdis_CoTransmitPdusOk_NdisCoTransmitPdusOk_SIZE sizeof(ULONGLONG)
    #define MSNdis_CoReceivePdusOk_NdisCoReceivePdusOk_SIZE sizeof(ULONGLONG)
    #define MSNdis_CoTransmitPduErrors_NdisCoTransmitPduErrors_SIZE sizeof(ULONG)
    #define MSNdis_CoReceivePduErrors_NdisCoReceivePduErrors_SIZE sizeof(ULONG)
    #define MSNdis_CoReceivePdusNoBuffer_NdisCoReceivePdusNoBuffer_SIZE sizeof(ULONG)
    #define MSNdis_AtmSupportedVcRates_MinCellRate_SIZE sizeof(ULONG)
    #define MSNdis_AtmSupportedVcRates_MaxCellRate_SIZE sizeof(ULONG)
    #define MSNdis_AtmSupportedServiceCategory_NdisAtmSupportedServiceCategory_SIZE sizeof(ULONG)
    #define MSNdis_AtmSupportedAalTypes_NdisAtmSupportedAalTypes_SIZE sizeof(ULONG)
    #define MSNdis_AtmHardwareCurrentAddress_NdisAtmHardwareCurrentAddress_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_AtmMaxActiveVcs_NdisAtmMaxActiveVcs_SIZE sizeof(ULONG)
    #define MSNdis_AtmMaxActiveVciBits_NdisAtmMaxActiveVciBits_SIZE sizeof(ULONG)
    #define MSNdis_AtmMaxActiveVpiBits_NdisAtmMaxActiveVpiBits_SIZE sizeof(ULONG)
    #define MSNdis_AtmMaxAal0PacketSize_NdisAtmMaxAal0PacketSize_SIZE sizeof(ULONG)
    #define MSNdis_AtmMaxAal1PacketSize_NdisAtmMaxAal1PacketSize_SIZE sizeof(ULONG)
    #define MSNdis_AtmMaxAal34PacketSize_NdisAtmMaxAal34PacketSize_SIZE sizeof(ULONG)
    #define MSNdis_AtmMaxAal5PacketSize_NdisAtmMaxAal5PacketSize_SIZE sizeof(ULONG)
    #define MSNdis_AtmReceiveCellsOk_NdisAtmReceiveCellsOk_SIZE sizeof(ULONGLONG)
    #define MSNdis_AtmTransmitCellsOk_NdisAtmTransmitCellsOk_SIZE sizeof(ULONGLONG)
    #define MSNdis_AtmReceiveCellsDropped_NdisAtmReceiveCellsDropped_SIZE sizeof(ULONGLONG)
    #define MSNdis_EthernetPermanentAddress_NdisPermanentAddress_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_EthernetCurrentAddress_NdisCurrentAddress_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_EthernetMaximumMulticastListSize_NdisEthernetMaximumMulticastListSize_SIZE sizeof(ULONG)
    #define MSNdis_EthernetMacOptions_NdisEthernetMacOptions_SIZE sizeof(ULONG)
    #define MSNdis_EthernetReceiveErrorAlignment_NdisEthernetReceiveErrorAlignment_SIZE sizeof(ULONG)
    #define MSNdis_EthernetOneTransmitCollision_NdisEthernetOneTransmitCollision_SIZE sizeof(ULONG)
    #define MSNdis_EthernetMoreTransmitCollisions_NdisEthernetMoreTransmitCollisions_SIZE sizeof(ULONG)
    #define MSNdis_TokenRingPermanentAddress_NdisPermanentAddress_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_TokenRingCurrentAddress_NdisCurrentAddress_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_TokenRingCurrentFunctional_NdisTokenRingCurrentFunctional_SIZE sizeof(ULONG)
    #define MSNdis_TokenRingCurrentGroup_NdisTokenRingCurrentGroup_SIZE sizeof(ULONG)
    #define MSNdis_TokenRingLastOpenStatus_NdisTokenRingLastOpenStatus_SIZE sizeof(ULONG)
    #define MSNdis_TokenRingCurrentRingStatus_NdisTokenRingCurrentRingStatus_SIZE sizeof(ULONG)
    #define MSNdis_TokenRingCurrentRingState_NdisTokenRingCurrentRingState_SIZE sizeof(ULONG)
    #define MSNdis_TokenRingLineErrors_NdisTokenRingLineErrors_SIZE sizeof(ULONG)
    #define MSNdis_TokenRingLostFrames_NdisTokenRingLostFrames_SIZE sizeof(ULONG)
    #define MSNdis_FddiLongPermanentAddress_NdisPermanentAddress_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_FddiLongCurrentAddress_NdisCurrentAddress_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_FddiLongMaximumListSize_NdisFddiLongMaximumListSize_SIZE sizeof(ULONG)
    #define MSNdis_FddiShortPermanentAddress_NdisPermanentAddress_SIZE sizeof(MSNdis_NetworkShortAddress)
    #define MSNdis_FddiShortCurrentAddress_NdisCurrentAddress_SIZE sizeof(MSNdis_NetworkShortAddress)
    #define MSNdis_FddiShortMaximumListSize_NdisFddiShortMaximumListSize_SIZE sizeof(ULONG)
    #define MSNdis_FddiAttachmentType_NdisFddiAttachmentType_SIZE sizeof(ULONG)
    #define MSNdis_FddiUpstreamNodeLong_NdisFddiUpstreamNodeLong_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_FddiDownstreamNodeLong_NdisFddiDownstreamNodeLong_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_FddiFrameErrors_NdisFddiFrameErrors_SIZE sizeof(ULONG)
    #define MSNdis_FddiFramesLost_NdisFddiFramesLost_SIZE sizeof(ULONG)
    #define MSNdis_FddiRingManagmentState_NdisFddiRingManagmentState_SIZE sizeof(ULONG)
    #define MSNdis_FddiLctFailures_NdisFddiLctFailures_SIZE sizeof(ULONG)
    #define MSNdis_FddiLemRejects_NdisFddiLemRejects_SIZE sizeof(ULONG)
    #define MSNdis_FddiLConnectionState_NdisFddiLConnectionState_SIZE sizeof(ULONG)
    #define MSNdis_80211_BaseServiceSetIdentifier_Ndis80211MacAddress_SIZE sizeof(UCHAR[6])
    #define MSNdis_80211_ServiceSetIdentifier_Ndis80211SsId_SIZE sizeof(UCHAR[33])
    #define MSNdis_80211_NetworkType_Ndis80211NetworkType_SIZE sizeof(ULONG)
    #define MSNdis_80211_NetworkTypesSupported_NumberOfItems_SIZE sizeof(ULONG)
    #define MSNdis_80211_NetworkTypeInUse_Ndis80211NetworkTypeInUse_SIZE sizeof(MSNdis_80211_NetworkType)
    #define MSNdis_80211_PowerMode_Ndis80211PowerMode_SIZE sizeof(ULONG)
    #define MSNdis_80211_TransmitPowerLevel_Ndis80211TransmitPowerLevel_SIZE sizeof(ULONG)
    #define MSNdis_80211_ReceivedSignalStrength_Ndis80211ReceivedSignalStrength_SIZE sizeof(LONG)
    #define MSNdis_80211_ReceivedSignalStrengthEventTrigger_Ndis80211ReceivedSignalStrengthTrigger_SIZE sizeof(LONG)
    #define MSNdis_80211_NetworkInfrastructure_Ndis80211NetworkInfrastructure_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationFH_FHLength_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationFH_HopPattern_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationFH_HopSet_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationFH_DwellTime_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationInfo_ConfigLength_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationInfo_BeaconPeriod_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationInfo_ATIMWindow_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationInfo_DSConfig_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationInfo_FHConfig_SIZE sizeof(MSNdis_80211_ConfigurationFH)
    #define MSNdis_80211_WLanBssId_Ndis80211WLanBssIdLength_SIZE sizeof(ULONG)
    #define MSNdis_80211_WLanBssId_Ndis80211MacAddress_SIZE sizeof(UCHAR[6])
    #define MSNdis_80211_WLanBssId_Reserved_SIZE sizeof(USHORT)
    #define MSNdis_80211_WLanBssId_Ndis80211SsIdLength_SIZE sizeof(ULONG)
    #define MSNdis_80211_WLanBssId_Ndis80211SsId_SIZE sizeof(UCHAR[32])
    #define MSNdis_80211_WLanBssId_Ndis80211Privacy_SIZE sizeof(ULONG)
    #define MSNdis_80211_WLanBssId_Ndis80211Rssi_SIZE sizeof(ULONG)
    #define MSNdis_80211_WLanBssId_Ndis80211NetworkTypeInUse_SIZE sizeof(MSNdis_80211_NetworkType)
    #define MSNdis_80211_WLanBssId_Ndis80211Configuration_SIZE sizeof(MSNdis_80211_ConfigurationInfo)
    #define MSNdis_80211_WLanBssId_Ndis80211InfrastructureMode_SIZE sizeof(MSNdis_80211_NetworkInfrastructure)
    #define MSNdis_80211_WLanBssId_Ndis80211SupportedRate_SIZE sizeof(UCHAR[8])
    #define MSNdis_80211_BSSIList_NumberOfItems_SIZE sizeof(ULONG)
    #define MSNdis_80211_InfrastructureMode_Ndis80211InfrastructureMode_SIZE sizeof(MSNdis_80211_NetworkInfrastructure)
    #define MSNdis_80211_FragmentationThreshold_Ndis80211FragmentationThreshold_SIZE sizeof(ULONG)
    #define MSNdis_80211_RTSThreshold_Ndis80211RTSThreshold_SIZE sizeof(ULONG)
    #define MSNdis_80211_NumberOfAntennas_Ndis80211NumberOfAntennas_SIZE sizeof(ULONG)
    #define MSNdis_80211_ReceiveAntennaSelected_Ndis80211ReceiveAntennaSelected_SIZE sizeof(ULONG)
    #define MSNdis_80211_TransmitAntennaSelected_Ndis80211TransmitAntennaSelected_SIZE sizeof(ULONG)
    #define MSNdis_80211_DataRates_Ndis80211DataRate_SIZE sizeof(UCHAR[8])
    #define MSNdis_80211_DesiredDataRates_Ndis80211DesiredRate_SIZE sizeof(UCHAR[8])
    #define MSNdis_80211_Configuration_Ndis80211Config_SIZE sizeof(MSNdis_80211_ConfigurationInfo)
    #define MSNdis_80211_Statistics_StatisticsLength_SIZE sizeof(ULONG)
    #define MSNdis_80211_Statistics_TransmittedFragmentCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_MulticastTransmittedFrameCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_FailedCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_RetryCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_MultipleRetryCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_RTSSuccessCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_RTSFailureCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_ACKFailureCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_FrameDuplicateCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_ReceivedFragmentCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_MulticastReceivedFrameCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_FCSErrorCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_AddWEP_Length_SIZE sizeof(ULONG)
    #define MSNdis_80211_AddWEP_KeyIndex_SIZE sizeof(ULONG)
    #define MSNdis_80211_AddWEP_KeyLength_SIZE sizeof(ULONG)
    #define MSNdis_80211_RemoveWEP_Ndis80211KeyIndex_SIZE sizeof(ULONG)
    #define MSNdis_80211_Disassociate_UnusedParameter_SIZE sizeof(ULONG)
    #define MSNdis_80211_BssIdListScan_UnusedParameter_SIZE sizeof(ULONG)
    #define MSNdis_80211_AuthenticationMode_Ndis80211AuthenticationMode_SIZE sizeof(ULONG)
    #define MSNdis_80211_PrivacyFilter_Ndis80211PrivacyFilter_SIZE sizeof(ULONG)
    #define MSNdis_80211_WEPStatus_Ndis80211WEPStatus_SIZE sizeof(ULONG)
    #define MSNdis_80211_ReloadDefaults_Ndis80211ReloadDefaults_SIZE sizeof(ULONG)
    #define MSNdis_StatusLinkSpeedChange_NdisStatusLinkSpeedChange_SIZE sizeof(MSNdis_NetworkLinkSpeed)
    #define KEYBOARD_PORT_WMI_STD_DATA_ConnectorType_SIZE sizeof(ULONG)
    #define KEYBOARD_PORT_WMI_STD_DATA_DataQueueSize_SIZE sizeof(ULONG)
    #define KEYBOARD_PORT_WMI_STD_DATA_ErrorCount_SIZE sizeof(ULONG)
    #define KEYBOARD_PORT_WMI_STD_DATA_FunctionKeys_SIZE sizeof(ULONG)
    #define KEYBOARD_PORT_WMI_STD_DATA_Indicators_SIZE sizeof(ULONG)
    #define KEYBOARD_ID_EX_Type_SIZE sizeof(ULONG)
    #define KEYBOARD_ID_EX_Subtype_SIZE sizeof(ULONG)
    #define POINTER_PORT_WMI_STD_DATA_ConnectorType_SIZE sizeof(ULONG)
    #define POINTER_PORT_WMI_STD_DATA_DataQueueSize_SIZE sizeof(ULONG)
    #define POINTER_PORT_WMI_STD_DATA_ErrorCount_SIZE sizeof(ULONG)
    #define POINTER_PORT_WMI_STD_DATA_Buttons_SIZE sizeof(ULONG)
    #define POINTER_PORT_WMI_STD_DATA_HardwareType_SIZE sizeof(ULONG)
    #define MSMouse_ClassInformation_DeviceId_SIZE sizeof(ULONGLONG)
    #define MSKeyboard_ClassInformation_DeviceId_SIZE sizeof(ULONGLONG)
    #define MSAcpi_ThermalZoneTemperature_ThermalStamp_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_ThermalConstant1_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_ThermalConstant2_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_Reserved_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_SamplingPeriod_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_CurrentTemperature_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_PassiveTripPoint_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_CriticalTripPoint_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_ActiveTripPointCount_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_ActiveTripPoint_SIZE sizeof(ULONG[10])
    #define WMI_DISK_GEOMETRY_Cylinders_SIZE sizeof(LONGLONG)
    #define WMI_DISK_GEOMETRY_MediaType_SIZE sizeof(ULONG)
    #define WMI_DISK_GEOMETRY_TracksPerCylinder_SIZE sizeof(ULONG)
    #define WMI_DISK_GEOMETRY_SectorsPerTrack_SIZE sizeof(ULONG)
    #define WMI_DISK_GEOMETRY_BytesPerSector_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_BytesRead_SIZE sizeof(LONGLONG)
    #define WMI_DISK_PERFORMANCE_BytesWritten_SIZE sizeof(LONGLONG)
    #define WMI_DISK_PERFORMANCE_ReadTime_SIZE sizeof(LONGLONG)
    #define WMI_DISK_PERFORMANCE_WriteTime_SIZE sizeof(LONGLONG)
    #define WMI_DISK_PERFORMANCE_IdleTime_SIZE sizeof(LONGLONG)
    #define WMI_DISK_PERFORMANCE_ReadCount_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_WriteCount_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_QueueDepth_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_SplitCount_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_QueryTime_SIZE sizeof(LONGLONG)
    #define WMI_DISK_PERFORMANCE_StorageDeviceNumber_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_StorageManagerName_SIZE sizeof(USHORT[8])
    #define MSDiskDriver_Performance_PerfData_SIZE sizeof(WMI_DISK_PERFORMANCE)
    #define STORAGE_FAILURE_PREDICT_STATUS_Reason_SIZE sizeof(ULONG)
    #define STORAGE_FAILURE_PREDICT_STATUS_PredictFailure_SIZE sizeof(BOOLEAN)
    #define STORAGE_FAILURE_PREDICT_DATA_Length_SIZE sizeof(ULONG)
    #define STORAGE_FAILURE_PREDICT_DATA_VendorSpecific_SIZE sizeof(UCHAR[512])
    #define ATAPI_FAILURE_PREDICT_DATA_Length_SIZE sizeof(ULONG)
    #define ATAPI_FAILURE_PREDICT_DATA_VendorSpecific_SIZE sizeof(UCHAR[362])
    #define ATAPI_FAILURE_PREDICT_DATA_OfflineCollectionStatus_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_SelfTestStatus_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_TotalTime_SIZE sizeof(USHORT)
    #define ATAPI_FAILURE_PREDICT_DATA_VendorSpecific2_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_OfflineCollectCapability_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_SmartCapability_SIZE sizeof(USHORT)
    #define ATAPI_FAILURE_PREDICT_DATA_ErrorLogCapability_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_VendorSpecific3_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_ShortPollTimeInMinutes_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_ExtendedPollTimeInMinutes_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_Reserved_SIZE sizeof(UCHAR[12])
    #define ATAPI_FAILURE_PREDICT_DATA_VendorSpecific4_SIZE sizeof(UCHAR[125])
    #define ATAPI_FAILURE_PREDICT_DATA_Checksum_SIZE sizeof(UCHAR)
    #define STORAGE_FAILURE_PREDICT_THRESHOLDS_VendorSpecific_SIZE sizeof(UCHAR[512])
    #define STORAGE_FAILURE_PREDICT_EVENT_Length_SIZE sizeof(ULONG)
    #define ALLOW_PERFORMANCE_HIT_IN_Allow_SIZE sizeof(BOOLEAN)
    #define ENABLE_DISABLE_FP_IN_Enable_SIZE sizeof(BOOLEAN)
    #define ENABLE_DISABLE_FP_POLLING_IN_Period_SIZE sizeof(ULONG)
    #define ENABLE_DISABLE_FP_POLLING_IN_Enable_SIZE sizeof(BOOLEAN)
    #define GET_FP_CAPABILITY_OUT_Capability_SIZE sizeof(ULONG)
    #define ENABLE_OFFLINE_DIAGS_OUT_Success_SIZE sizeof(BOOLEAN)
    #define READ_LOG_SECTORS_IN_LogAddress_SIZE sizeof(UCHAR)
    #define READ_LOG_SECTORS_IN_SectorCount_SIZE sizeof(UCHAR)
    #define READ_LOG_SECTORS_OUT_Length_SIZE sizeof(ULONG)
    #define WRITE_LOG_SECTORS_IN_LogAddress_SIZE sizeof(UCHAR)
    #define WRITE_LOG_SECTORS_IN_SectorCount_SIZE sizeof(UCHAR)
    #define WRITE_LOG_SECTORS_IN_Length_SIZE sizeof(ULONG)
    #define WRITE_LOG_SECTORS_OUT_Success_SIZE sizeof(BOOLEAN)
    #define EXECUTE_SELF_TEST_IN_Subcommand_SIZE sizeof(UCHAR)
    #define EXECUTE_SELF_TEST_OUT_ReturnCode_SIZE sizeof(ULONG)
    #define STORAGE_SCSI_INFO_EXCEPTIONS_PageSavable_SIZE sizeof(BOOLEAN)
    #define STORAGE_SCSI_INFO_EXCEPTIONS_Flags_SIZE sizeof(UCHAR)
    #define STORAGE_SCSI_INFO_EXCEPTIONS_MRIE_SIZE sizeof(UCHAR)
    #define STORAGE_SCSI_INFO_EXCEPTIONS_Padding_SIZE sizeof(UCHAR)
    #define STORAGE_SCSI_INFO_EXCEPTIONS_IntervalTimer_SIZE sizeof(ULONG)
    #define STORAGE_SCSI_INFO_EXCEPTIONS_ReportCount_SIZE sizeof(ULONG)
    #define MSIde_PortDeviceInfo_Bus_SIZE sizeof(UCHAR)
    #define MSIde_PortDeviceInfo_Target_SIZE sizeof(UCHAR)
    #define MSIde_PortDeviceInfo_Lun_SIZE sizeof(UCHAR)
    #define SERIAL_WMI_COMM_DATA_BaudRate_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_BitsPerByte_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_Parity_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_ParityCheckEnable_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_StopBits_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_XoffCharacter_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_XoffXmitThreshold_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_XonCharacter_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_XonXmitThreshold_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_MaximumBaudRate_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_MaximumOutputBufferSize_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_MaximumInputBufferSize_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_Support16BitMode_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SupportDTRDSR_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SupportIntervalTimeouts_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SupportParityCheck_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SupportRTSCTS_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SupportXonXoff_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SettableBaudRate_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SettableDataBits_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SettableFlowControl_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SettableParity_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SettableParityCheck_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SettableStopBits_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_IsBusy_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_HW_DATA_IrqNumber_SIZE sizeof(ULONG)
    #define SERIAL_WMI_HW_DATA_IrqVector_SIZE sizeof(ULONG)
    #define SERIAL_WMI_HW_DATA_IrqLevel_SIZE sizeof(ULONG)
    #define SERIAL_WMI_HW_DATA_IrqAffinityMask_SIZE sizeof(ULONGLONG)
    #define SERIAL_WMI_HW_DATA_InterruptType_SIZE sizeof(ULONG)
    #define SERIAL_WMI_HW_DATA_BaseIOAddress_SIZE sizeof(ULONGLONG)
    #define SERIAL_WMI_PERF_DATA_ReceivedCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_PERF_DATA_TransmittedCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_PERF_DATA_FrameErrorCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_PERF_DATA_SerialOverrunErrorCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_PERF_DATA_BufferOverrunErrorCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_PERF_DATA_ParityErrorCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_wPacketLength_SIZE sizeof(USHORT)
    #define SERIAL_WMI_COMMPROP_wPacketVersion_SIZE sizeof(USHORT)
    #define SERIAL_WMI_COMMPROP_dwServiceMask_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwReserved1_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwMaxTxQueue_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwMaxRxQueue_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwMaxBaud_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwProvSubType_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwProvCapabilities_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwSettableParams_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwSettableBaud_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_wSettableData_SIZE sizeof(USHORT)
    #define SERIAL_WMI_COMMPROP_wSettableStopParity_SIZE sizeof(USHORT)
    #define SERIAL_WMI_COMMPROP_dwCurrentTxQueue_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwCurrentRxQueue_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwProvSpec1_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwProvSpec2_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwProvCharSize_SIZE sizeof(ULONG)
    #define PARPORT_WMI_ALLOC_FREE_COUNTS_PortAllocates_SIZE sizeof(ULONG)
    #define PARPORT_WMI_ALLOC_FREE_COUNTS_PortFrees_SIZE sizeof(ULONG)
    #define PARALLEL_WMI_LOG_INFO_Flags1_SIZE sizeof(ULONG)
    #define PARALLEL_WMI_LOG_INFO_Flags2_SIZE sizeof(ULONG)
    #define PARALLEL_WMI_LOG_INFO_spare_SIZE sizeof(ULONG[2])
    #define PARALLEL_WMI_LOG_INFO_SppWriteCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_NibbleReadCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_BoundedEcpWriteCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_BoundedEcpReadCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_HwEcpWriteCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_HwEcpReadCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_SwEcpWriteCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_SwEcpReadCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_HwEppWriteCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_HwEppReadCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_SwEppWriteCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_SwEppReadCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_ByteReadCount_SIZE sizeof(LONGLONG)
    #define PARALLEL_WMI_LOG_INFO_ChannelNibbleReadCount_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_NUMBER_OF_BUFFERS_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_SECTORS_PER_READ_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_SECTORS_PER_READ_MASK_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_MAX_SECTORS_PER_READ_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_PLAY_ENABLED_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_CDDA_SUPPORTED_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_CDDA_ACCURATE_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_STD_DATA_Reserved1_SIZE sizeof(BOOLEAN)
    #define REDBOOK_WMI_PERF_TIME_READING_DELAY_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_TIME_READING_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_TIME_STREAMING_DELAY_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_TIME_STREAMING_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_DATA_PROCESSED_SIZE sizeof(LONGLONG)
    #define REDBOOK_WMI_PERF_STREAM_PAUSED_COUNT_SIZE sizeof(ULONG)
    #define RegisteredGuids_GuidType_SIZE sizeof(ULONG)
    #define RegisteredGuids_LoggerId_SIZE sizeof(ULONG)
    #define RegisteredGuids_EnableLevel_SIZE sizeof(ULONG)
    #define RegisteredGuids_EnableFlags_SIZE sizeof(ULONG)
    #define RegisteredGuids_IsEnabled_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_DRIVE_PARAMETERS_MaximumBlockSize_SIZE sizeof(ULONG)
    #define WMI_TAPE_DRIVE_PARAMETERS_MinimumBlockSize_SIZE sizeof(ULONG)
    #define WMI_TAPE_DRIVE_PARAMETERS_DefaultBlockSize_SIZE sizeof(ULONG)
    #define WMI_TAPE_DRIVE_PARAMETERS_MaximumPartitionCount_SIZE sizeof(ULONG)
    #define WMI_TAPE_DRIVE_PARAMETERS_CompressionCapable_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_DRIVE_PARAMETERS_CompressionEnabled_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_DRIVE_PARAMETERS_ReportSetmarks_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_DRIVE_PARAMETERS_HardwareErrorCorrection_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_MEDIA_PARAMETERS_MaximumCapacity_SIZE sizeof(ULONGLONG)
    #define WMI_TAPE_MEDIA_PARAMETERS_AvailableCapacity_SIZE sizeof(ULONGLONG)
    #define WMI_TAPE_MEDIA_PARAMETERS_BlockSize_SIZE sizeof(ULONG)
    #define WMI_TAPE_MEDIA_PARAMETERS_PartitionCount_SIZE sizeof(ULONG)
    #define WMI_TAPE_MEDIA_PARAMETERS_MediaWriteProtected_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_WARNING_DriveProblemType_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_WARNING_TapeData_SIZE sizeof(UCHAR[512])
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadCorrectedWithoutDelay_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadCorrectedWithDelay_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadTotalErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadTotalCorrectedErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadTotalUncorrectedErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_ReadCorrectionAlgorithmProcessed_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteCorrectedWithoutDelay_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteCorrectedWithDelay_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteTotalErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteTotalCorrectedErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteTotalUncorrectedErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_WriteCorrectionAlgorithmProcessed_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_IO_ERROR_NonMediumErrors_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_ReadWarning_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_WriteWarning_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_HardError_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_ReadFailure_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_WriteFailure_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_UnsupportedFormat_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_TapeSnapped_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_DriveRequiresCleaning_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_TimetoCleanDrive_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_DriveHardwareError_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_ScsiInterfaceError_SIZE sizeof(BOOLEAN)
    #define WMI_TAPE_PROBLEM_DEVICE_ERROR_MediaLife_SIZE sizeof(BOOLEAN)
    #define WMI_CHANGER_PARAMETERS_NumberOfSlots_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_NumberOfDrives_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_NumberOfIEPorts_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_NumberOfTransports_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_NumberOfDoors_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_NumberOfCleanerSlots_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PARAMETERS_MagazineSize_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PROBLEM_WARNING_ChangerProblemType_SIZE sizeof(ULONG)
    #define WMI_CHANGER_PROBLEM_WARNING_ChangerData_SIZE sizeof(UCHAR[512])
    #define WMI_CHANGER_PROBLEM_DEVICE_ERROR_ChangerProblemType_SIZE sizeof(ULONG)

// public\sdk\inc\wmsbuffer.h
#define IWMSBufferAllocator_AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)

// public\sdk\inc\ws2tcpip.h
#define IP_MSFILTER_SIZE(numsrc) \
    (sizeof(struct ip_msfilter)-sizeof(struct in_addr) + (numsrc)*sizeof(struct in_addr))

// public\sdk\inc\wtl10\atlddx.h
#define DDX_TEXT(nID, var) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
		{ \
			if(!DDX_Text(nID, var, sizeof(var), bSaveAndValidate)) \
				return FALSE; \
		}
#define DDX_TEXT_LEN(nID, var, len) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
		{ \
			if(!DDX_Text(nID, var, sizeof(var), bSaveAndValidate, TRUE, len)) \
				return FALSE; \
		}

// public\sdk\inc\wtl10\atldlgs.h
#define CDSIZEOF_STRUCT(structname, member)  (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))

// public\sdk\inc\wtl10\atlframe.h
#define DECLARE_FRAME_WND_CLASS(WndClassName, uCommonResourceID) \
static CFrameWndClassInfo& GetWndClassInfo() \
{ \
	static CFrameWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), 0, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(COLOR_WINDOW + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T(""), uCommonResourceID \
	}; \
	return wc; \
}
#define DECLARE_FRAME_WND_CLASS_EX(WndClassName, uCommonResourceID, style, bkgnd) \
static CFrameWndClassInfo& GetWndClassInfo() \
{ \
	static CFrameWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), style, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(bkgnd + 1), NULL, WndClassName, NULL }, \
		NULL, NULL, IDC_ARROW, TRUE, 0, _T(""), uCommonResourceID \
	}; \
	return wc; \
}
#define DECLARE_FRAME_WND_SUPERCLASS(WndClassName, OrigWndClassName, uCommonResourceID) \
static CFrameWndClassInfo& GetWndClassInfo() \
{ \
	static CFrameWndClassInfo wc = \
	{ \
		{ sizeof(WNDCLASSEX), 0, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, NULL, NULL, WndClassName, NULL }, \
		OrigWndClassName, NULL, NULL, TRUE, 0, _T(""), uCommonResourceID \
	}; \
	return wc; \
}

// public\sdk\inc\wtypes.h
#define CBPCLIPDATA(clipdata)    ( (clipdata).cbSize - sizeof((clipdata).ulClipFmt) )

// published\ddk\inc\wdm\strmini.h
#define STREAM_REQUEST_BLOCK_SIZE sizeof(STREAM_REQUEST_BLOCK)

// published\genxddk\vfwext.h
#define VFW_HIDE_ALL_PAGES           (VFW_HIDE_SETTINGS_PAGE |\
                                     VFW_HIDE_VIDEOSRC_PAGE  |\
                                     VFW_HIDE_CAMERACONTROL_PAGE)

// published\oak\inc\mcdrv.h
#define MCDDRIVER_V10_SIZE      (sizeof(ULONG)+31*sizeof(void *))

// published\sdk\inc\align.h
#define COUNT_IS_ALIGNED(Count,Pow2) \
        ( ( ( (Count) & (((Pow2)-1)) ) == 0) ? TRUE : FALSE )
#define POINTER_IS_ALIGNED(Ptr,Pow2) \
        ( ( ( ((ULONG_PTR)(Ptr)) & (((Pow2)-1)) ) == 0) ? TRUE : FALSE )
#define ROUND_DOWN_COUNT(Count,Pow2) \
        ( (Count) & (~(((LONG)(Pow2))-1)) )
#define ROUND_DOWN_POINTER(Ptr,Pow2) \
        ( (LPVOID) ROUND_DOWN_COUNT( ((ULONG_PTR)(Ptr)), (Pow2) ) )
#define ROUND_UP_COUNT(Count,Pow2) \
        ( ((Count)+(Pow2)-1) & (~(((LONG)(Pow2))-1)) )
#define ROUND_UP_POINTER(Ptr,Pow2) \
        ( (LPVOID) ( (((ULONG_PTR)(Ptr))+(Pow2)-1) & (~(((LONG)(Pow2))-1)) ) )
#define ALIGN_BYTE              sizeof(UCHAR)
#define ALIGN_CHAR              sizeof(CHAR)
#define ALIGN_DESC_CHAR         sizeof(DESC_CHAR)
#define ALIGN_DWORD             sizeof(DWORD)
#define ALIGN_LONG              sizeof(LONG)
#define ALIGN_LPBYTE            sizeof(LPBYTE)
#define ALIGN_LPDWORD           sizeof(LPDWORD)
#define ALIGN_LPSTR             sizeof(LPSTR)
#define ALIGN_LPTSTR            sizeof(LPTSTR)
#define ALIGN_LPVOID            sizeof(LPVOID)
#define ALIGN_LPWORD            sizeof(LPWORD)
#define ALIGN_TCHAR             sizeof(TCHAR)
#define ALIGN_WCHAR             sizeof(WCHAR)
#define ALIGN_WORD              sizeof(WORD)

// published\sdk\inc\dlcapi.h
#define LLC_XMIT_BUFFER_SIZE sizeof(LLC_XMIT_BUFFER)

// published\sdk\inc\except.hxx
#define END_MULTINHERITED_CONSTRUCTION(class, base1)    \
                                                        \
        base1::_Activate(sizeof(class), &class::_ObjectUnwind);
#define END_CONSTRUCTION(class)                                 \
                                                                \
        _Activate( sizeof(class), &class::_ObjectUnwind );

// published\sdk\inc\fltdefs.h
#define FILTERSIZE                                      \
    (sizeof(PF_FILTER_DESCRIPTOR) -                     \
     (DWORD)(&((PPF_FILTER_DESCRIPTOR)0)->SrcAddr))

// published\sdk\inc\ia64inst.h
#define BUNDLE_SIZE sizeof(IA64_INSTRUCTION)

// published\sdk\inc\mapidbg.h
#define dimensionof(a) 		(sizeof(a)/sizeof(*(a)))

// published\sdk\inc\mapiform.h
#define MAPI_IMAPIVIEWADVISESINK_METHODS(IPURE)                         \
    MAPIMETHOD(OnShutdown)(THIS) IPURE;                                    \
    MAPIMETHOD(OnNewMessage)(THIS) IPURE;                               \
    MAPIMETHOD(OnPrint)(THIS_                                           \
        /*in*/ ULONG dwPageNumber,                                      \
        /*in*/ HRESULT hrStatus) IPURE;                                 \
    MAPIMETHOD(OnSubmitted) (THIS) IPURE;                               \
    MAPIMETHOD(OnSaved) (THIS) IPURE;                                   \

// published\sdk\inc\mapival.h
#define BAD_STANDARD_OBJ( lpObj, prefix, method, lpVtbl) \
	(   IsBadWritePtr( (lpObj), sizeof(*lpObj)) \
	 || IsBadReadPtr( (void *) &(lpObj->lpVtbl->method), sizeof(LPVOID)) \
	 ||( ( LPVOID) (lpObj->lpVtbl->method) != (LPVOID) (prefix##method)))
#define FBadUnknown( lpObj ) \
	(	IsBadReadPtr( (lpObj), sizeof(LPVOID) ) \
	 ||	IsBadReadPtr( (lpObj)->lpVtbl, 3 * sizeof(LPUNKNOWN) ) \
	 ||	IsBadCodePtr( (FARPROC)(lpObj)->lpVtbl->QueryInterface ))
#define FBadQueryInterface( lpObj, riid, ppvObj)	\
	(   IsBadReadPtr( riid, sizeof(IID)) \
	 || IsBadWritePtr( ppvObj, sizeof(LPVOID)))
#define FBadGetLastError( lpObj, hResult, ulFlags, lppMAPIError )\
	(IsBadWritePtr( lppMAPIError, sizeof(LPMAPIERROR)))
#define FBadOpenProperty( lpObj, ulPropTag, lpiid, ulInterfaceOptions, ulFlags \
						, lppUnk) \
	(   IsBadReadPtr( lpiid, sizeof(IID)) \
	 || IsBadWritePtr( lppUnk, sizeof (LPUNKNOWN FAR *)))
#define FBadGetIDsFromNames( lpIPDAT, cPropNames, lppPropNames, ulFlags \
						   , lppPropTags) \
	(   (cPropNames && FBadRglpNameID( lppPropNames, cPropNames)) \
	 || IsBadWritePtr( lppPropTags, sizeof(LPULONG FAR *)))

// published\sdk\inc\mapiwin.h
#define	Cbtszsize(_a)	((lstrlen(_a)+1)*sizeof(TCHAR))
#define	CbtszsizeW(_a)	((lstrlenW(_a) + 1) * sizeof(WCHAR))
#define HexCchOf(_s)	(sizeof(_s)*2+1)
#define HexSizeOf(_s)	(HexCchOf(_s)*sizeof(TCHAR))

// published\sdk\inc\mapiwz.h
#define	WIZ_QUERYNUMPAGES	(WM_USER +10)

// published\sdk\inc\ntddpcm.h
#define PCMRES_SET_DESCRIPTOR_TYPE(IoResourceDesc, Type)    (IoResourceDesc)->u.DevicePrivate.Data[0] |= ((Type) << sizeof(UCHAR)*8*2)
#define PCMRES_GET_DESCRIPTOR_TYPE(IoResourceDesc) ((UCHAR) ((IoResourceDesc)->u.DevicePrivate.Data[0] >> sizeof(UCHAR)*8*2))

// published\sdk\inc\ntddstrm.h
#define NORMAL_STREAM_EA_LENGTH             (sizeof(NormalStreamEA) - 1)

// published\sdk\inc\ntfsprop.h
#define VARIABLE_STRUCTURE_SIZE(S,V,C) ((int)sizeof( S ) + ((C) - 1) * (int)sizeof( V ))
#define COUNTED_STRING_SIZE(l)      \
    (sizeof( COUNTED_STRING ) - sizeof ( WCHAR ) + (l))

// published\sdk\inc\propapi.h
#   define PROPGENPROPERTYNAME(s,n) \
    { \
        memcpy ((s), OLESTR("prop"), sizeof (OLESTR("prop"))); \
        ULTOO  ((n), &(s)[sizeof("prop") - 1], 10); \
    }
#define CBIT_GUID       (CBIT_BYTE * sizeof(GUID))

// published\sdk\inc\propset.h
#define CB_FORMATIDOFFSET	sizeof(FORMATIDOFFSET)
#define CB_PROPERTYSETHEADER	sizeof(PROPERTYSETHEADER)
#define CB_PROPERTYIDOFFSET	sizeof(PROPERTYIDOFFSET)

// published\sdk\inc\rrascfg.h
#define IEAPProviderConfig_RouterInvokeConfigUI(This,dwEapTypeId,uConnectionParam,hwndParent,dwFlags,pConnectionDataIn,dwSizeOfConnectionDataIn,ppConnectionDataOut,pdwSizeOfConnectionDataOut)	\
    (This)->lpVtbl -> RouterInvokeConfigUI(This,dwEapTypeId,uConnectionParam,hwndParent,dwFlags,pConnectionDataIn,dwSizeOfConnectionDataIn,ppConnectionDataOut,pdwSizeOfConnectionDataOut)
#define IEAPProviderConfig_RouterInvokeCredentialsUI(This,dwEapTypeId,uConnectionParam,hwndParent,dwFlags,pConnectionDataIn,dwSizeOfConnectionDataIn,pUserDataIn,dwSizeOfUserDataIn,ppUserDataOut,pdwSizeOfUserDataOut)	\
    (This)->lpVtbl -> RouterInvokeCredentialsUI(This,dwEapTypeId,uConnectionParam,hwndParent,dwFlags,pConnectionDataIn,dwSizeOfConnectionDataIn,pUserDataIn,dwSizeOfUserDataIn,ppUserDataOut,pdwSizeOfUserDataOut)
#define DeclareIEAPProviderConfigMembers(IPURE) \
	STDMETHOD(Initialize)(THIS_ \
		LPCOLESTR 	pszMachineName, \
	DWORD       dwEapTypeId, \
		ULONG_PTR*	puConnectionParam) IPURE; \
	STDMETHOD(Uninitialize)(THIS_ \
	DWORD       dwEapTypeId, \
		ULONG_PTR 	uConnectionParam) IPURE; \
	STDMETHOD(ServerInvokeConfigUI)(THIS_ \
	DWORD       dwEapTypeId, \
		ULONG_PTR 	uConnectionParam, \
		HWND 		hWnd, \
		ULONG_PTR 	dwRes1, \
		ULONG_PTR 	dwRes2) IPURE; \
 STDMETHOD(RouterInvokeConfigUI)(THIS_ \
	DWORD       dwEapTypeId, \
		ULONG_PTR 	uConnectionParam, \
	HWND        hwndParent, \
	DWORD       dwFlags, \
	BYTE* 		pConnectionDataIn, \
	DWORD		dwSizeOfConnectionDataIn, \
	BYTE**		ppConnectionDataOut, \
	DWORD*		pdwSizeOfConnectionDataOut) IPURE; \
 STDMETHOD(RouterInvokeCredentialsUI)(THIS_  \
	DWORD   	dwEapTypeId, \
		ULONG_PTR 	uConnectionParam, \
	HWND    	hwndParent, \
	DWORD   	dwFlags, \
	BYTE*   	pConnectionDataIn, \
	DWORD   	dwSizeOfConnectionDataIn, \
	BYTE*   	pUserDataIn, \
	DWORD   	dwSizeOfUserDataIn, \
	BYTE**  	ppUserDataOut, \
	DWORD*  	pdwSizeOfUserDataOut) IPURE; \

// published\sdk\inc\stralign.h
#define WSTR_ALIGNED(s) (((DWORD_PTR)(s) & (sizeof(WCHAR)-1)) == 0)
#define __UA_WSTRSIZE(s)    ((__UA_WCSLEN(s)+1)*sizeof(WCHAR))
#define __UA_STRUC_ALIGNED(t,s) \
    (((DWORD_PTR)(s) & (TYPE_ALIGNMENT(t)-1)) == 0)
#define STRUC_ALIGNED_STACK_COPY(t,s) \
    __UA_STRUC_ALIGNED(t,s) ?   \
        ((t const *)(s)) :      \
        ((t const *)__UA_STACKCOPY((s),sizeof(t)))

// published\sdk\inc\tnef.h
#define CbOfTrp(_p)		(sizeof(TRP) + (_p)->cch + (_p)->cbRgb)
#define cbALIAS sizeof(ALIAS)
#define cbNSID sizeof(NSID)

// published\sdk\inc\unimodem.h
    #define RAWDIAGNOSTICS_DATA(_plinediagnostics)                          \
            (  (BYTE*)(_plinediagnostics)                                   \
             + ((_plinediagnostics)->dwRawDiagnosticsOffset)                \
             + sizeof(LINEDIAGNOSTICSOBJECTHEADER))
    #define PARSEDDIAGNOSTICS_DATA(_plinediagnostics)                       \
                            ((LINEDIAGNOSTICS_PARSEREC*)                    \
                            (  (BYTE*)(_plinediagnostics)                   \
                             + ((_plinediagnostics)->dwParsedDiagnosticsOffset)\
                             + sizeof(LINEDIAGNOSTICSOBJECTHEADER)))

// published\sdk\inc\vdmdbg.h
#define VDMCONTEXT_LENGTH  (sizeof(VDMCONTEXT))
#define VDMCONTEXT_ALIGN   (sizeof(ULONG))

// published\sdk\inc\vfw.h
#define ICGetDefaultQuality(hic) \
    (ICSendMessage(hic, ICM_GETDEFAULTQUALITY, (DWORD_PTR)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)
#define ICGetDefaultKeyFrameRate(hic) \
    (ICSendMessage(hic, ICM_GETDEFAULTKEYFRAMERATE, (DWORD_PTR)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)
#define ICDrawWindow(hic, prc) \
    ICSendMessage(hic, ICM_DRAW_WINDOW, (DWORD_PTR)(LPVOID)(prc), sizeof(RECT))
#define ICDrawRealize(hic, hdc, fBackground) \
    ICSendMessage(hic, ICM_DRAW_REALIZE, (DWORD_PTR)(UINT_PTR)(HDC)(hdc), (DWORD_PTR)(BOOL)(fBackground))

// sdktools\apimon\include\apimon.h
#define Align(p,x)                      (((x) & ((p)-1)) ? (((x) & ~((p)-1)) + p) : (x))

// sdktools\build\buildutl.c
#define CBHEADER        sizeof(MEMHEADER)
#define CBTAIL          sizeof(ULONG)

// sdktools\bvtsigvf\sigverif.h
#define     cbX(X)      sizeof(X)

// sdktools\cddump\common.h
#define SAMPLES_PER_SECTOR ( RAW_SECTOR_SIZE / sizeof(SAMPLE) )

// sdktools\compdir\multithd.c
#define ROUND_UP( Size, Amount ) (((Size) + ((Amount) - 1)) & ~((Amount) - 1))

// sdktools\debuggers\imagehlp\vc\dia2.h
#define IDiaAddressMap_get_imageAlign(This,pRetVal)	\
    (This)->lpVtbl -> get_imageAlign(This,pRetVal)
#define IDiaAddressMap_put_imageAlign(This,NewVal)	\
    (This)->lpVtbl -> put_imageAlign(This,NewVal)
#define IDiaSymbol_get_unalignedType(This,pRetVal)	\
    (This)->lpVtbl -> get_unalignedType(This,pRetVal)
#define IDiaSectionContrib_get_notPaged(This,pRetVal)	\
    (This)->lpVtbl -> get_notPaged(This,pRetVal)
#define IDiaFrameData_get_lengthBlock(This,pRetVal)	\
    (This)->lpVtbl -> get_lengthBlock(This,pRetVal)

// sdktools\efinvram\efinvram.h
#define ALIGN_DOWN(length, type) \
    ((ULONG)(length) & ~(sizeof(type) - 1))
#define ALIGN_UP(length, type) \
    (ALIGN_DOWN(((ULONG)(length) + sizeof(type) - 1), type))

// sdktools\fsdump\inc\bsfixalloc.h
#define IMPLEMENT_FIXED_ALLOC(class_name, block_size) \
CBsFixedAlloc class_name::s_alloc(sizeof(class_name), block_size) \

// sdktools\fsdump\lib\bsstring.cpp
#define ROUND(x,y) (((x)+(y-1))&~(y-1))

// sdktools\hivepp\p0defs.h
#define	LIMIT(a)	&(a)[sizeof(a)]

// sdktools\hivepp\p0macros.c
#define ELIMIT			(&Macro_buffer[BIG_BUFFER * 4] - EXP_PAD)

// sdktools\hivepp\symbols.h
#define	SOB_sym_190	(sizeof(sym_190_t) - sizeof(sym_200_t))
#define	SOB_sym_130	(sizeof(sym_130_t) - sizeof(sym_135_t))
#define	SOB_sym_120	(sizeof(sym_120_t) - sizeof(sym_125_t))
#define	SOB_sym_110	(sizeof(sym_110_t) - sizeof(sym_115_t))
#define	SOB_sym_100	(sizeof(sym_100_t) - sizeof(sym_105_t))
#define	SO_BASICSYM	(sizeof(sym_t) - sizeof(sym_95_t))
#define	SO_RAWSYMBOL	(	SO_SYMBOL\
							+ sizeof(sym_140_t)\
							)
#define	SO_FORMAL		(	SO_SYMBOL\
							+ sizeof(sym_150_t)\
							)
#define	SO_LABEL		(	SO_SYMBOL\
							+ sizeof(sym_160_t)\
							)
#define	SO_INTRINSIC	(	SO_BASICSYM\
							+ SOB_sym_100\
							+ SOB_sym_110\
							+ SOB_sym_120\
							+ sizeof(sym_170_t)\
							)
#define	SO_TAG			(	SO_BASICSYM\
							+ SOB_sym_100\
							+ SOB_sym_110\
							+ sizeof(sym_180_t)\
							)
#define	SO_MOE			(SO_BASICSYM + sizeof(long))	/* sizeof(moe_value) */

// sdktools\hsplit\hsplit.h
#define HST_BLOCK               (HST_BEGIN | HST_END)
#define HST_USERBLOCK           (HST_USERINTERNALBLOCK | HST_USERBOTHBLOCK)
#define HSO_USERBLOCK           (HSO_USERINTERNALBLOCK | HSO_USERBOTHBLOCK)
#define HSCSZSIZE(sz) sizeof(sz)-1

// sdktools\iasinfdb\simtable.cpp
#define stack_new(obj, num) new (_alloca(sizeof(obj)*num)) obj[num]

// sdktools\link16\bndrel.h
#define CBRLE           sizeof(DOSRLC)

// sdktools\link16\bndtrn.h
#define CBHTE           (sizeof(AHTETYPE))
#define CBPROPSN        (sizeof(APROPSNTYPE))
#define CBPROPNAME      (sizeof(APROPNAMETYPE))
#define CBPROPFILE      (sizeof(APROPFILETYPE))
#define CBPROPGROUP     (sizeof(APROPGROUPTYPE))
#define CBPROPUNDEF     (sizeof(APROPUNDEFTYPE))
#define CBPROPEXP       (sizeof(APROPEXPTYPE))
#define CBPROPIMP       (sizeof(APROPIMPTYPE))
#define CBPROPCOMDAT    (sizeof(APROPCOMDAT))
#define CBPROPALIAS     (sizeof(APROPALIAS))
#define CBLONG          sizeof(long)
#define RoundTo64k(x)   (((x) + 0xffffL) & ~0xffffL)

// sdktools\link16\hsort.c
#define VMBuffer(x)     (RBTYPE *)mapva((long)(AREASORT+((long)(x)*sizeof(RBTYPE))),FALSE)

// sdktools\link16\newdeb.h
#define CBSSTMODULES    (sizeof(sstModules))

// sdktools\link16\qbsym.c
#define CBQBHDR         sizeof(QBHDRTYPE)

// sdktools\link16\vm.h
#define AREAHRC         (AREAEP + (LXIVK * sizeof(EPTYPE)))
#define AREAHRC         (AREAEP + (LXIVK * sizeof(EPTYPE)))

// sdktools\list\list.c
#define FOREGROUND_WHITE (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define BACKGROUND_WHITE (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE)
#define HIWHITE_ON_BLUE (BACKGROUND_BLUE | FOREGROUND_WHITE | FOREGROUND_INTENSITY)

// sdktools\mep\browser\bsc\bsc.c
#define BSCIn(v) ReadBSC(&v, sizeof(v));

// sdktools\mep\browser\mbrmake\list.h
#define ENM_VA(type) (va##type##s + sizeof(c##type)*idx##type)

// sdktools\mep\browser\mbrmake\mbrwbsc.c
#define BSCOut(v) BSCWrite(&(v), sizeof(v))

// sdktools\mep\browser\mbrmake\readbsc.c
#define BSCIn(v) ReadBSC(&v, sizeof(v))

// sdktools\mep\help\htest\cons.c
#define     CYAN_FGD	    (FOREGROUND_BLUE | FOREGROUND_GREEN)
#define     MAGENTA_FGD     (FOREGROUND_BLUE | FOREGROUND_RED)
#define     YELLOW_FGD	    (FOREGROUND_GREEN | FOREGROUND_RED)
#define     WHITE_FGD	    (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
#define     CYAN_BGD	    (BACKGROUND_BLUE | BACKGROUND_GREEN)
#define     MAGENTA_BGD     (BACKGROUND_BLUE | BACKGROUND_RED)
#define     YELLOW_BGD	    (BACKGROUND_GREEN | BACKGROUND_RED)
#define     WHITE_BGD	    (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED)

// sdktools\mep\src\console.c
#define     CYAN_FGD	    (FOREGROUND_BLUE | FOREGROUND_GREEN)
#define     MAGENTA_FGD     (FOREGROUND_BLUE | FOREGROUND_RED)
#define     YELLOW_FGD	    (FOREGROUND_GREEN | FOREGROUND_RED)
#define     WHITE_FGD	    (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
#define     CYAN_BGD	    (BACKGROUND_BLUE | BACKGROUND_GREEN)
#define     MAGENTA_BGD     (BACKGROUND_BLUE | BACKGROUND_RED)
#define     YELLOW_BGD	    (BACKGROUND_GREEN | BACKGROUND_RED)
#define     WHITE_BGD	    (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED)

// sdktools\netjoin\netjoin.c
#define TRUST_ENUM_PERF_BUF_SIZE    sizeof(LSA_TRUST_INFORMATION) * 1000

// sdktools\nmake\nmake.h
#define ALLOCATE_OBJECT(type) ((type *) allocate(sizeof(type)))

// sdktools\perfmon\intrline.c
#define iILineWindowExtra     (sizeof (PILINE))

// sdktools\perfmon\legend.c
#define iGraphLegendWindowExtra     (sizeof (PLEGEND))

// sdktools\perfmtr\lookmon.c
#define BUFFER_SIZE (64 * 1024 / sizeof(ULONG))

// sdktools\perfmtr\pmon.c
#define TOPCPU_BUFFER_SIZE (((300*sizeof(TOPCPU))/4096+1)*4096)

// sdktools\ramdiskctrl\ramdiskctrl.c
#define ROUND_TO_PAGE_SIZE(_x) (((_x) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))

// sdktools\rasdiag\private\stldeque.h
#define _DEQUESIZ (4096 < sizeof (_Ty) ? 1 : 4096 / sizeof (_Ty))

// sdktools\rcdll\p0macros.c
#define ELIMIT                  (&Macro_buffer[BIG_BUFFER * 4] - EXP_PAD)

// sdktools\rcdll\rctg.c
#define FONT_FIXED sizeof(ffh)
#define FONT_ALL sizeof(ffh) + 64

// sdktools\rcdll\symbols.h
#define SOB_sym_190     (sizeof(sym_190_t) - sizeof(sym_200_t))
#define SOB_sym_130     (sizeof(sym_130_t) - sizeof(sym_135_t))
#define SOB_sym_120     (sizeof(sym_120_t) - sizeof(sym_125_t))
#define SOB_sym_110     (sizeof(sym_110_t) - sizeof(sym_115_t))
#define SOB_sym_100     (sizeof(sym_100_t) - sizeof(sym_105_t))
#define SO_BASICSYM     (sizeof(sym_t) - sizeof(sym_95_t))
#define SO_RAWSYMBOL            (SO_SYMBOL \
                                           + sizeof(sym_140_t)\
                                           )
#define SO_FORMAL               (SO_SYMBOL \
                                           + sizeof(sym_150_t)\
                                           )
#define SO_LABEL                (SO_SYMBOL \
                                           + sizeof(sym_160_t)\
                                           )
#define SO_INTRINSIC            (SO_BASICSYM \
                                             + SOB_sym_100\
                                             + SOB_sym_110\
                                             + SOB_sym_120\
                                             + sizeof(sym_170_t)\
                                             )
#define SO_TAG                  (SO_BASICSYM \
                                             + SOB_sym_100\
                                             + SOB_sym_110\
                                             + sizeof(sym_180_t)\
                                             )
#define SO_MOE                  (SO_BASICSYM + sizeof(long))    /* sizeof(moe_value) */

// sdktools\setedit\legend.c
#define iGraphLegendWindowExtra     (sizeof (PLEGEND))

// sdktools\spt\cdp\cdp.c
        #define MRW_FEATURE_DATA_SIZE (sizeof(GET_CONFIGURATION_HEADER)+sizeof(FEATURE_DATA_MRW))
        #define MRW_MODE_PAGE_DATA_SIZE (sizeof(MODE_PARAMETER_HEADER10) + sizeof(MRW_MODE_PAGE))

// sdktools\tweakui\addrm.cpp
#define pariIari(iari) (&padii->pari[iari])
#define padii (&adii)

// sdktools\tweakui\tweakui.h
#define cbX(x) sizeof(x)
#define cbCtch(ctch) ((ctch) * sizeof(TCH))

// sdktools\tztool\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// sdktools\unicows\godot\updres.h
#define CBLONG        (sizeof(LONG))

// sdktools\vi\nt.c
#define FOREGROUND_WHITE (FOREGROUND_BLUE | \
                          FOREGROUND_GREEN | \
                          FOREGROUND_RED | \
                          FOREGROUND_INTENSITY)

// sdktools\vmmreg32\pch.h
#define SIZEOF_WORK_BUFFER          (sizeof(W95KEYNODE_BLOCK))

// sdktools\vmmreg32\regfinfo.h
#define KEYNODES_PER_PAGE	    (PAGESIZE / sizeof(KEYNODE))
#define KEYNODES_PER_PAGE	    (PAGESIZE / sizeof(KEYNODE))
#define RgAlignBlockSize(size) \
    (((size) + (DATABLOCK_GRANULARITY - 1)) & ~(DATABLOCK_GRANULARITY - 1))

// sdktools\vmmreg32\regknode.c
#define SIZEOF_KEYNODE_BLOCK(lpfi)      \
    ((HAS_COMPACT_KEYNODES(lpfi)) ? sizeof(KEYNODE_BLOCK) : sizeof(W95KEYNODE_BLOCK))
#define SIZEOF_FILE_KEYNODE(lpfi)       \
    ((HAS_COMPACT_KEYNODES(lpfi)) ? sizeof(KEYNODE) : sizeof(W95KEYNODE))
#define W95KEYNODES_PER_PAGE            (PAGESIZE / sizeof(W95KEYNODE))

// sdktools\z\src\console.c
#define     CYAN_FGD	    (FOREGROUND_BLUE | FOREGROUND_GREEN)
#define     MAGENTA_FGD     (FOREGROUND_BLUE | FOREGROUND_RED)
#define     YELLOW_FGD	    (FOREGROUND_GREEN | FOREGROUND_RED)
#define     WHITE_FGD	    (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
#define     CYAN_BGD	    (BACKGROUND_BLUE | BACKGROUND_GREEN)
#define     MAGENTA_BGD     (BACKGROUND_BLUE | BACKGROUND_RED)
#define     YELLOW_BGD	    (BACKGROUND_GREEN | BACKGROUND_RED)
#define     WHITE_BGD	    (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED)

// sdktools\ztools\src\re_mi.c
#define PAD1        sizeof(RE_OPCODE)
#define PAD2        (sizeof(RE_OPCODE)+sizeof(RE_OPCODE))
#define LCCL        (sizeof(RE_OPCODE)+LALLIGN+(256/8))
#define LNCCL       (sizeof(RE_OPCODE)+LALLIGN+(256/8))
#define LMATCH      (sizeof(RE_OPCODE)+LALLIGN)
#define LFAIL       (sizeof(RE_OPCODE)+LALLIGN)
#define LPUSHP      (sizeof(RE_OPCODE)+LALLIGN)
#define LPOPP       (sizeof(RE_OPCODE)+LALLIGN)
#define LPREV       (sizeof(RE_OPCODE)+sizeof(RE_OPCODE)+PAD2)

// shell\applets\taskmgr\perfpage.cpp
#define GRAPH_LINE_COLOR    RGB(0, 128, 64)
#define GRAPH_TEXT_COLOR    RGB(0, 255, 0)

// shell\browseui\itbar.cpp
#define CB_V12  (sizeof(COOLBARSAVEv12))
#define CB_V13  (sizeof(COOLBARSAVEv15))
#define CB_V17  (sizeof(COOLBARSAVE))

// shell\browseui\priv.h
#define VariantInit(p) memset(p, 0, sizeof(*(p)))

// shell\browseui\util.cpp
#define DEFAULT_IEUPDATECHECK_PAGE      TEXT("http://www.microsoft.com/isapi/redir.dll?Prd=ie&Pver=5.0&Ar=ie5update&O1=b1")

// shell\comctl32\v5\cutils.c
#define CCS_ALIGN (CCS_TOP | CCS_NOMOVEY | CCS_BOTTOM)
#define RGB_BACKGROUNDSEL   (RGB(000,000,255))  // blue
#define RGB_BACKGROUND      (RGB(255,000,255))  // magenta

// shell\comctl32\v5\hotkey.c
            #define IsNUMKEY(vk) ((vk) >= VK_NUMPAD0 && (vk) <= VK_DIVIDE)

// shell\comctl32\v5\monthcal.h
#define DatePick_RightAlign(pdp)    ((pdp)->ci.style & DTS_RIGHTALIGN)

// shell\comctl32\v5\prsht.c
#define CB_ITEMEXTRA (sizeof(TC_ITEMEXTRA) - sizeof(TC_ITEMHEADER))

// shell\comctl32\v6\cutils.c
#define CCS_ALIGN (CCS_TOP | CCS_NOMOVEY | CCS_BOTTOM)
#define RGB_BACKGROUNDSEL   (RGB(000,000,255))  // blue
#define RGB_BACKGROUND      (RGB(255,000,255))  // magenta

// shell\comctl32\v6\hotkey.c
            #define IsNUMKEY(vk) ((vk) >= VK_NUMPAD0 && (vk) <= VK_DIVIDE)

// shell\comctl32\v6\markup.cpp
#define IS_LINK(pBlock)     ((pBlock) && (pBlock)->iLink != INVALID_LINK_INDEX)

// shell\comctl32\v6\monthcal.h
#define DatePick_RightAlign(pdp)    ((pdp)->ci.style & DTS_RIGHTALIGN)

// shell\comctl32\v6\prsht.c
#define CB_ITEMEXTRA (sizeof(TC_ITEMEXTRA) - sizeof(TC_ITEMHEADER))

// shell\comdlg32\filenew.cpp
#define PLACESBAR_THEMEPADDING MAKELPARAM(2, 2)

// shell\cpls\appwzdui\priv.h
#define VariantInit(p) memset(p, 0, sizeof(*(p)))

// shell\cpls\inetcpl\mainwnd.cpp
#define IsPropPageEnabled(iPage)  (c_PropInfo[iPage].pfDisabled==NULL || *c_PropInfo[iPage].pfDisabled==FALSE)

// shell\cpls\system\virtual.c
#define PAGEFILE_INFO_BUFFER_SIZE MAX_DRIVES * sizeof(SYSTEM_PAGEFILE_INFORMATION) + \
                                  MAX_DRIVES * MAX_PATH * sizeof(TCHAR)

// shell\evtmon\inc\msoem.h
#define ClearLp(lpv, type) \
            MsoMemset((lpv), '\0', sizeof(type))
#define ClearLprgBlocked(lpv, type, iMax) \
            MsoMemset((lpv), '\0', (sizeof(type) * (iMax) + sizeof(void *)))
#define IMaxRgBlocked(dcl, type) \
            ((sizeof(dcl) / sizeof(type)) - sizeof(void *))
#define MsoPNewEm(type) \
            ((type *) MsoPvAllocEmCb((unsigned int) sizeof(type)))
#define MsoClearPv(pv, type) \
            MsoClearPvCb((pv), sizeof(type))
#define MsoPNewEmRgBlocked(type_blk, type, iMax) \
            ((type_blk *) MsoPvAllocEmCb \
                ((unsigned int) (sizeof(type) * (iMax) + sizeof(void *))))

// shell\explorer\tray.h
#define MAYBE_WIN95_TVSD(t) (t.dwSize == sizeof(TVSD95))

// shell\ext\brfcase\filesync\linkinfo\project.h
#define ALIGN_CNT(x,y)    (((x)+(y)-1) & ~((y)-1))
#define IS_ALIGNED_CNT(x,y)  (((x) & ((y)-1)) == 0)

// shell\ext\brfcase\filesync\syncui\comm.h
#define GAllocType(type)                (type *)GAlloc(sizeof(type))

// shell\ext\brfcase\filesync\syncui\mem.h
#define SharedAllocType(type)           (type _huge *)SharedAlloc(sizeof(type))

// shell\ext\brfcase\filesync\syncui\twin.h
#define Sync_Dump(lpvBuf, type)     Sync_FnDump((LPVOID)lpvBuf, sizeof(type))

// shell\ext\cdfview\cdfidl.h
#define ALIGN4(sz) (((sz)+3)&~3)

// shell\ext\docprop\plex.h
#define WAlign(w) (((w)+1)&~1)

// shell\ext\docprop\propvar.h
#define PROPVAR_STRING_CONVERSION_REQUIRED(lppropvar,codepage)  \
            ( IS_PROPVAR_STRING( lppropvar )                    \
              &&                                                \
              ((codepage) != CP_WINUNICODE)                     \
            )
#define PROPVAR_STRING_CONVERSION_REQUIRED(lppropvar,codepage)  \
            ( IS_PROPVAR_STRING( lppropvar )                    \
              &&                                                \
              ((codepage) == CP_WINUNICODE)                     \
            )

// shell\ext\ftp\util.cpp
#define FTP_PROPPAGES_FROM_INETCPL          (INET_PAGE_SECURITY | INET_PAGE_CONTENT | INET_PAGE_CONNECTION)

// shell\ext\inetfind\fnd.h
#define cbX(X) sizeof(X)

// shell\ext\keyremap\map.h
#define cbX(X) sizeof(X)

// shell\ext\mlang\util.cpp
#define IS_DBCSCODEPAGE(j) \
    (((j) == 932)   || \
    ((j) == 936)   || \
    ((j) == 949)   || \
    ((j) == 950))
#define IS_COMPLEXSCRIPT_CODEPAGE(j) \
    (((j) == 874)   || \
    ((j) == 1255)   || \
    ((j) == 1256)   || \
    ((j) == 1258))

// shell\ext\taskui\nusrmgr\pagefact.h
#define PAGE_ENTRY2(clsid,class)    {&clsid, class::_CreatorClass::CreateInstance},
#define END_PAGE_MAP()              {&CLSID_NULL, NULL} };

// shell\ext\taskui\test\pagefact.cpp
#define PAGE_ENTRY2(clsid,class)    {&clsid, class::_CreatorClass::CreateInstance},

// shell\iecontrols\inc\localsrv.h
#define PROPERTYPAGE(name)     { OI_PROPERTYPAGE, (void *)&(name##Page) }

// shell\iecontrols\inc\proppage.h
#define PPM_NEWOBJECTS    (WM_USER + 100)
#define PPM_APPLY         (WM_USER + 101)
#define PPM_EDITPROPERTY  (WM_USER + 102)

// shell\iecontrols\inc\prsht.h
#define PSM_REMOVEPAGE          (WM_USER + 102)
#define PSM_ADDPAGE             (WM_USER + 103)

// shell\inc\deballoc.c
#define CBALLOCEXTRA		(sizeof(LPARAM)+sizeof(UINT))

// shell\inc\desktopp.h
#define DTM_STARTPAGEONOFF          (WM_USER + 96)  // Turn on/off the StartPage.

// shell\inc\evtmon\msoem.h
#define ClearLp(lpv, type) \
            MsoMemset((lpv), '\0', sizeof(type))
#define ClearLprgBlocked(lpv, type, iMax) \
            MsoMemset((lpv), '\0', (sizeof(type) * (iMax) + sizeof(void *)))
#define IMaxRgBlocked(dcl, type) \
            ((sizeof(dcl) / sizeof(type)) - sizeof(void *))
#define MsoPNewEm(type) \
            ((type *) MsoPvAllocEmCb((unsigned int) sizeof(type)))
#define MsoClearPv(pv, type) \
            MsoClearPvCb((pv), sizeof(type))
#define MsoPNewEmRgBlocked(type_blk, type, iMax) \
            ((type_blk *) MsoPvAllocEmCb \
                ((unsigned int) (sizeof(type) * (iMax) + sizeof(void *))))

// shell\inc\win95\configmg.h
#define	SIZEOF_DMA		sizeof(DMA_DES)
#define	SIZEOF_IRQ		sizeof(IRQ_DES)

// shell\inc\win95\vmm.h
#define PAGEOUT_ALL	(PAGEOUT_PRIVATE | PAGEOUT_SHARED | PAGEOUT_SYSTEM)

// shell\lib\varutil.cpp
#define VariantInit(p) memset(p, 0, sizeof(*(p)))

// shell\osshell\accesory\calendar\cal.h
#define CBDRHEAD (sizeof (SINT) + sizeof (DT) + sizeof (SINT) + sizeof (SINT) + sizeof (SINT))
#define CBCDD sizeof (SINT)
#define CBFSOUND sizeof (SINT)
#define CBMDINTERVAL sizeof (SINT)
#define CBFHOUR24 sizeof (SINT)
#define CBTMSTART sizeof (TM)

// shell\osshell\accesory\hypertrm\emu\keydef.h
#define HVK_PAGEUP			(0x11 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_PAGEDOWN		(0x12 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_ADD				(0x3D | VIRTUAL_KEY | HVIRTUAL_KEY)   // Identifies key on Numeric Keypad only.
#define HVK_SUBTRACT		(0x3E | VIRTUAL_KEY | HVIRTUAL_KEY)   // Identifies key on Numeric Keypad only.
#define HVK_NUMPAD0			(0x45 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_NUMPAD1			(0x46 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_NUMPAD2			(0x47 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_NUMPAD3			(0x48 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_NUMPAD4			(0x49 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_NUMPAD5			(0x64 | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_NUMPAD6			(0x4A | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_NUMPAD7			(0x4B | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_NUMPAD8			(0x4C | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_NUMPAD9			(0x4D | VIRTUAL_KEY | HVIRTUAL_KEY)
#define HVK_NUMPADPERIOD	(0x53 | VIRTUAL_KEY | HVIRTUAL_KEY)

// shell\osshell\accesory\hypertrm\tdll\backscrl.hh
#define BACKSCRL_MAXPAGES (INT_MAX / (int)sizeof(HBKPAGE))

// shell\osshell\accesory\hypertrm\tdll\cloopset.c
	#define PutItem(v,i) sfPutSessionItem(hSF, i, sizeof(v), &(v))

// shell\osshell\accesory\hypertrm\tdll\sf.c
#define ROUND_UP(x) 	((x+0xFFFL)&(~0x0FFFL))

// shell\osshell\accesory\newpad\notepad.h
#define ES_STD (WS_CHILD|WS_VSCROLL|WS_VISIBLE|ES_MULTILINE|ES_NOHIDESEL)
#define PWM_CHECK_HKL                   (WM_APP + 1)

// shell\osshell\accesory\newpad\npmlang.c
#define IsISCII(cp)  (((cp) >= CP_ISCII_MIN) && ((cp) <= CP_ISCII_MAC))

// shell\osshell\accesory\notepad\notepad.h
#define ES_STD (WS_CHILD|WS_VSCROLL|WS_VISIBLE|ES_MULTILINE|ES_NOHIDESEL)
#define PWM_CHECK_HKL                   (WM_APP + 1)

// shell\osshell\accessib\accwiz\schemes.cpp
#define APPLY_SCHEME_CURRENT(xxx) if(0 != memcmp(&schemeNew.m_##xxx, &m_##xxx, sizeof(schemeNew.m_##xxx))) SystemParametersInfo(SPI_SET##xxx, sizeof(schemeNew.m_##xxx), (PVOID)&schemeNew.m_##xxx, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)

// shell\osshell\accessib\accwiz\schemes.h
#define TEST_CHANGES(xxx) if(0 != memcmp(&schemeOriginal.m_##xxx, &m_##xxx, sizeof(schemeOriginal.m_##xxx))) AddChangesLine(IDS_CHANGES##xxx, szChanges)

// shell\osshell\control\mmsys\drivers.c
#define nDriversToSKIP ((int)( sizeof(aDriversToSKIP)   \
                             / sizeof(aDriversToSKIP[0]) ))
#define REALLOC(_pData,_cOld,_cNew,_cDelta) \
        ReallocFn (sizeof(*_pData), (void **)&_pData, &_cOld, _cNew, _cDelta)

// shell\osshell\control\mmsys\utils.h
#define GAllocType(type)                (type *)GAlloc(sizeof(type))

// shell\osshell\control\t1instal\metrics.h
#define GetAlignment(t1m)        &(t1m->blues.align)

// shell\osshell\cpls\usb\proppage.h
#define USBWM_NOTIFYREFRESH                (WM_USER + 501)

// shell\osshell\dskquota\ui\adusrdlg.cpp
#define DECLARE_SCOPE(t,f,b,m,n,d)  \
{ sizeof(DSOP_SCOPE_INIT_INFO), (t), (f), { { (b), (m), (n) }, (d) }, NULL, NULL, S_OK }

// shell\osshell\fontfldr\fontext\t1instal\metrics.h
#define GetAlignment(t1m)        &(t1m->blues.align)

// shell\osshell\inc\o2base.hxx
#define DECLARE_ARY(_Cls, _Ty, _pTy) \
    class _Cls : public CAry { public: \
        _Cls(void) : CAry(sizeof(_Ty)) { ; } \
        _Ty& operator[] (int i) { return * (_pTy) Deref(i); } \
        operator _pTy(void) { return (_pTy) _pv; } };
#define DECLARE_ARY(_Cls, _Ty, _pTy) \
    class _Cls : public CAry { public: \
        _Cls(void) : CAry(sizeof(_Ty)) { ; } \
        _Ty& operator[] (int i) { return * (_pTy) Deref(i); } \
        operator _pTy(void) { return (_pTy) _pv; } };

// shell\osshell\lmui\ntshrui\shrpage2.cxx
#define SIZEOF_EVERYONE_ACE     (sizeof(ACCESS_ALLOWED_ACE) - sizeof(ULONG) + sizeof(g_WorldSid))

// shell\osshell\regwiz\phbooklib\suapi.cpp
#define MB_MYERROR (MB_APPLMODAL | MB_ICONERROR | MB_SETFOREGROUND)

// shell\osshell\security\aclui\aceedit.cpp
#define PWM_SELECT_PAGE             (WM_APP - 1)

// shell\osshell\security\aclui\pagebase.cpp
#define DECLARE_SCOPE(t,f,b,m,n,d)  \
{ sizeof(DSOP_SCOPE_INIT_INFO), (t), (f|DSOP_SCOPE_FLAG_DEFAULT_FILTER_GROUPS|DSOP_SCOPE_FLAG_DEFAULT_FILTER_USERS), { { (b), (m), (n) }, (d) }, NULL, NULL, S_OK }

// shell\osshell\snapins\devmgr\snapin\genpage.h
#define idh_devmgr_manage_command_line  102170  // Device Manager: "Allo&w the selected computer to be changed when launching from the command line.  This only applies if you save the console." (Button)
#define idh_devmgr_view_devicetree  102110  // Device Manager: "&Device tree" (Button)
#define idh_devmgr_manage_local 102130  // Device Manager: "&Local computer:  (the computer this console is running on)" (Button)
#define idh_devmgr_manage_remote    102140  // Device Manager: "&Another computer:" (Button)
#define idh_devmgr_view_all 102100  // Device Manager: "&All" (Button)
#define idh_devmgr_manage_remote_browse 102160  // Device Manager: "B&rowse..." (Button)
#define idh_devmgr_view_resources   102120  // Device Manager: "&Resources" (Button)

// shell\osshell\themes\inc\mstask.h
#define IProvideTaskPage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IProvideTaskPage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IProvideTaskPage_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IProvideTaskPage_GetPage(This,tpType,fPersistChanges,phPage)	\
    (This)->lpVtbl -> GetPage(This,tpType,fPersistChanges,phPage)

// shell\osshell\themes\inc\rpcasync.h
#define RPC_ASYNC_VERSION_1_0     sizeof(RPC_ASYNC_STATE)

// shell\published\inc\pif.h
#define LARGEST_GROUP   sizeof(PROPPRG)

// shell\published\inc\schemadef.h
#define END_TM_SCHEMA(name)                };  \
    static const TMSCHEMAINFO *GetSchemaInfo() \
    {  \
        static TMSCHEMAINFO si = {sizeof(si)};  \
        si.iSchemaDefVersion = SCHEMADEF_VERSION; \
        si.iThemeMgrVersion = THEMEMGR_VERSION; \
        si.iPropCount = sizeof(name)/sizeof(name[0]); \
        si.pPropTable = name; \
        \
        return &si; \
    }

// shell\shdocvw\dochostbsc.cpp
#define SEARCHPREFIXSIZE    sizeof(SEARCHPREFIX)

// shell\shdocvw\priv.h
#define VariantInit(p) memset(p, 0, sizeof(*(p)))

// shell\shell32\control1.c
#define UNNATIVE_SIZE   sizeof(NEWCPLINFOA)
#define UNNATIVE_SIZE   sizeof(NEWCPLINFOW)

// shell\shell32\findfldr.cpp
#define cbP (sizeof (PROPVARIANT *))

// shell\shell32\lnkprev.c
#define PCPD_INDEX sizeof(PVOID)

// shell\shell32\pifmgrp.h
#define MAXPATHNAME 260 // (sizeof(OFSTRUCTEX)-9)

// shell\shell32\sdspatch\sdutil.h
#define VariantInit(p) memset(p, 0, sizeof(*(p)))

// shell\shell32\shapi.cpp
#define BUGGY_SHELL16_CBFILEINFO    (sizeof(SHFILEINFO) - 4)

// shell\shell32\shellprv.h
#define VariantInit(p) memset(p, 0, sizeof(*(p)))
#define IsEqualGUID(rguid1, rguid2) (!memcmp(rguid1, rguid2, sizeof(GUID)))
#define DECLARE_CONST_BSTR(name, str) \
 extern const struct BSTR##name { ULONG cb; WCHAR wsz[sizeof(str)/sizeof(WCHAR)]; } name

// shell\shell32\tngen\include\jinclude.h
#define JFREAD(file,buf,sizeofbuf)  \
  ((size_t) fread((void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))
#define JFWRITE(file,buf,sizeofbuf)  \
  ((size_t) fwrite((const void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))

// shell\shell32\util.cpp
#define REGSHELLSTATE_SIZE_WIN95 (sizeof(UINT)+SHELLSTATE_SIZE_WIN95)  // Win95 Gold
#define REGSHELLSTATE_SIZE_NT4   (sizeof(UINT)+SHELLSTATE_SIZE_NT4)    // Win95 OSR / NT 4
#define REGSHELLSTATE_SIZE_IE4   (sizeof(UINT)+SHELLSTATE_SIZE_IE4)    // IE 4, 4.01
#define REGSHELLSTATE_SIZE_WIN2K (sizeof(UINT)+SHELLSTATE_SIZE_WIN2K)  // ie5, win2k, millennium, whistler

// shell\shlwapi\propbag.cpp
#define OLDVS_STREAMHEADERSIG  28  // sizeof(WIN95HEADER)

// shell\themes\themeldr\signing.cpp
#define SIZE_PUBLIC_KEY         148         // sizeof(s_keyPublic1)

// shell\themes\themesel\main.cpp
#define VALIDPAGE(iPage,cPages) (((iPage) >=0) && ((iPage) < (cPages)))

// shell\themes\uxtheme\nctheme.cpp
    #define TEST_NCTRANSPARENCY(part)   IsThemePartDefined(hTheme,part,0) ? \
        IsThemeBackgroundPartiallyTransparent(hTheme,part,FS_ACTIVE) : FALSE;

// termsrv\common\license\inc\wincelic.h
#define WBT_USER_NAME_LEN   (sizeof(WBT_USER_NAME))

// termsrv\inc\adcgmcro.h
#define DC_ROUND_UP_4(x)  ((x + 3) & ~((DCUINT32)0X03))

// termsrv\inc\at128.h
#define TS_INPUTPDU_SIZE (sizeof(TS_INPUT_PDU) - sizeof(TS_INPUT_EVENT))
#define TS_CA_NON_DATA_SIZE (sizeof(TS_SHARECONTROLHEADER) + \
                            sizeof(TS_SHAREID) + 6)
#define TS_SYNC_PDU_SIZE sizeof(TS_SYNCHRONIZE_PDU)
#define TS_CONTROL_PDU_SIZE sizeof(TS_CONTROL_PDU)
#define TS_FLOW_PDU_SIZE sizeof(TS_FLOW_PDU)
#define TS_REFRESH_RECT_PDU_SIZE sizeof(TS_REFRESH_RECT_PDU)
#define TS_SUPPRESS_OUTPUT_PDU_SIZE(n) \
       ((sizeof(TS_SUPPRESS_OUTPUT_PDU)-sizeof(TS_RECTANGLE16)) + \
        (n * sizeof(TS_RECTANGLE16)))
#define TS_SUPPRESS_OUTPUT_UNCOMP_LEN(n) \
                                             (8 + n * sizeof(TS_RECTANGLE16))
#define TS_SHUTDOWN_REQ_PDU_SIZE sizeof(TS_SHUTDOWN_REQ_PDU)
#define TS_SAVE_SESSION_INFO_PDU_SIZE sizeof(TS_SAVE_SESSION_INFO_PDU)
#define TS_SET_ERROR_INFO_PDU_SIZE sizeof(TS_SET_ERROR_INFO_PDU)
#define TS_SET_KEYBOARD_INDICATORS_PDU_SIZE       sizeof(TS_SET_KEYBOARD_INDICATORS_PDU)

// termsrv\inc\ddcgctyp.h
#define SIF_ALL             (SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)

// termsrv\inc\ddcgmcro.h
#define FIELDSIZE(type, field)   (sizeof(((type NEAR*)1)->field))

// termsrv\inc\ndcgmcro.h
#define FIELDSIZE(type, field)   (sizeof(((type *)1)->field))

// termsrv\perfts\datats.c
#define FIELDSIZE(type, field)   (sizeof(((type *)1)->field))

// termsrv\remdsk\rds\as\h\dcg.h
#define FIELD_SIZE(type, field)   (sizeof(((type FAR *)0L)->field))
#define DC_ROUND_UP_4(x)  (((x) + 3L) & ~(3L))

// termsrv\remdsk\rds\as\h\oa.h
#define INT_ORDER_SIZE(pOrder) \
(pOrder->OrderHeader.Common.cbOrderDataLength + sizeof(INT_ORDER_HEADER))

// termsrv\remdsk\rds\as\h\osi.h
#define SHM_SIZE_USED   (sizeof(SHM_SHARED_MEMORY) + 2*sizeof(OA_SHARED_DATA))

// termsrv\remdsk\rds\as\h\t_share.h
#define COM_ORDER_SIZE(pOrder) \
    (pOrder->OrderHeader.cbOrderDataLength + sizeof(COM_ORDER_HEADER))

// termsrv\remdsk\rds\dev\inc16\stdarg.h
#define _INTSIZEOF(n)    ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v) ap = (va_list)&v + _INTSIZEOF(v)

// termsrv\remdsk\rds\dev\inc16\stdio.h
#define  L_tmpnam sizeof(_P_tmpdir)+8

// termsrv\remdsk\rds\dev\inc16\windows.h
#define SIF_ALL             (SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)// ;Internal
#define PSM_PAGEINFO        (WM_USER+100)   /* ;Internal 4.0 */

// termsrv\remdsk\rds\h\confguid.h
#define CB_H221_GUIDKEY    (5 + sizeof(GUID))

// termsrv\remdsk\rds\h\mcspdu.h
#define SIZE_MCSPDU_Module_PDU_0 sizeof(ConnectMCSPDU)
#define SIZE_MCSPDU_Module_PDU_1 sizeof(DomainMCSPDU)

// termsrv\remdsk\rds\t120\h\gccpdu.h
#define SIZE_GCCPDU_Module_PDU_0 sizeof(ConnectData)
#define SIZE_GCCPDU_Module_PDU_1 sizeof(ConnectGCCPDU)
#define SIZE_GCCPDU_Module_PDU_2 sizeof(GCCPDU)

// termsrv\remdsk\rds\t120\h\ms_util.h
#define ROUNDTOBOUNDARY(num)	(((UINT)(num) + 0x03) & 0xfffffffcL)

// termsrv\remdsk\rds\t120\mst120\cnppdu.h
#define SIZE_CNPPDU_Module_PDU_0 sizeof(CNPPDU)

// termsrv\wince\wsasync\wsasync.c
#define ROUND_UP_COUNT(Count,Pow2) \
        ( ((Count)+(Pow2)-1) & (~((Pow2)-1)) )

// tools\wppconfig\rev1\control.tpl
#define WPP_NEXT(Name) ((WPP_REGISTRATION_BLOCK*) \
    (WPP_CTL_ ## Name + 1 == WPP_LAST_CTL ? 0:WPP_CB + WPP_CTL_ ## Name + 1))

// tools\x86\perl\lib\core\cc_runtime.h
#define PP_EVAL(ppaddr, nxt) do {		\
	dJMPENV;				\
	int ret;				\
	PUTBACK;				\
	JMPENV_PUSH(ret);			\
	switch (ret) {				\
	case 0:					\
	    PL_op = ppaddr(ARGS);			\
	    PL_retstack[PL_retstack_ix - 1] = Nullop;	\
	    if (PL_op != nxt) CALLRUNOPS();		\
	    JMPENV_POP;				\
	    break;				\
	case 1: JMPENV_POP; JMPENV_JUMP(1);	\
	case 2: JMPENV_POP; JMPENV_JUMP(2);	\
	case 3:					\
	    JMPENV_POP;				\
	    if (PL_restartop != nxt)		\
		JMPENV_JUMP(3);			\
	}					\
	PL_op = nxt;				\
	SPAGAIN;				\
    } while (0)

// tools\x86\perl\lib\core\handy.h
#define New(x,v,n,t)	(v = (t*)safemalloc((MEM_SIZE)((n)*sizeof(t))))
#define Newc(x,v,n,t,c)	(v = (c*)safemalloc((MEM_SIZE)((n)*sizeof(t))))
#define Renew(v,n,t) \
	  (v = (t*)saferealloc((Malloc_t)(v),(MEM_SIZE)((n)*sizeof(t))))
#define Renewc(v,n,t,c) \
	  (v = (c*)saferealloc((Malloc_t)(v),(MEM_SIZE)((n)*sizeof(t))))
#define New(x,v,n,t)	(v = (t*)safexmalloc((x),(MEM_SIZE)((n)*sizeof(t))))
#define Newc(x,v,n,t,c)	(v = (c*)safexmalloc((x),(MEM_SIZE)((n)*sizeof(t))))
#define Renew(v,n,t) \
	  (v = (t*)safexrealloc((Malloc_t)(v),(MEM_SIZE)((n)*sizeof(t))))
#define Renewc(v,n,t,c) \
	  (v = (c*)safexrealloc((Malloc_t)(v),(MEM_SIZE)((n)*sizeof(t))))

// tools\x86\perl\lib\core\regcomp.h
#define ANY_SKIP ((33 - 1)/sizeof(regnode) + 1)

// tools\x86\perl\lib\core\scope.h
#define SAVETMPS save_int((int*)&PL_tmps_floor), PL_tmps_floor = PL_tmps_ix

// tools\x86\perl\site\lib\xml\parser\expat\xmlparse\xmlparse.c
#define ROUND_UP(n, sz) (((n) + ((sz) - 1)) & ~((sz) - 1))

// tools\x86\perl\site\lib\xml\parser\expat\xmltok\xmltok.c
#define UTF8_GET_NAMING(pages, p, n) \
  ((n) == 2 \
  ? UTF8_GET_NAMING2(pages, (const unsigned char *)(p)) \
  : ((n) == 3 \
     ? UTF8_GET_NAMING3(pages, (const unsigned char *)(p)) \
     : 0))

// windows\advcore\ctf\aimm1.2\inc\imeapp.h
#define	RWM_SHOWIMEPAD			TEXT("MSIMEShowImePad")

// windows\advcore\ctf\inc\msime.h
#define RWM_SHOWIMEPAD          TEXT("MSIMEShowImePad")

// windows\advcore\ctf\uim\marshal.h
#define CPROXY_PARAM_ULONG_IN(ul)                                             \
              {MPARAM_IN_ULONG, NULL, ul, NULL, sizeof(ULONG), 1},
#define CPROXY_PARAM_INTERFACE_IN(p, iid)                                     \
              {MPARAM_IN_INTERFACE, p, 0, &iid, sizeof(void *), 1},
#define CPROXY_PARAM_INTERFACE_OUT(p, iid)                                    \
              {MPARAM_OUT_INTERFACE, p, 0, &iid, sizeof(void *), 1},
#define CPROXY_PARAM_INTERFACE_IN_OUT(p, iid)                                 \
              {MPARAM_IN_OUT_INTERFACE, p, 0, &iid, sizeof(void *), 1},
#define CPROXY_PARAM_TF_LBBALLOONINFO_OUT(p)                                   \
              {MPARAM_OUT_TF_LBBALLOONINFO, (void *)p, 0, NULL, sizeof(*p), 1},
#define CSTUB_PARAM_ULONG_IN(ul)                                             \
              {MPARAM_IN_ULONG, NULL, ul, NULL, 0 /*sizeof(ULONG)*/, 1},
#define CSTUB_PARAM_INTERFACE_IN(p, iid)                                     \
              {MPARAM_IN_INTERFACE, p, 0, &iid, 0 /*sizeof(void *)*/, 1},
#define CSTUB_PARAM_INTERFACE_OUT(p, iid)                                    \
              {MPARAM_OUT_INTERFACE, p, 0, &iid, sizeof(void *), 1},
#define CSTUB_PARAM_TF_LBBALLOONINFO_OUT(p)                                   \
              {MPARAM_OUT_TF_LBBALLOONINFO, (void *)p, 0, NULL, sizeof(*p), 1},

// windows\advcore\duser\duexts\stdext64.h
#define move(dst, src)  moveBlock(&(dst), src, sizeof(dst))
#define tryMove(dst, src)  tryMoveBlock(&(dst), src, sizeof(dst))

// windows\advcore\gdiplus\engine\entry\facerealization.cpp
#define ROUND_TO_PAGE(x)  (((x)+PAGE_SIZE-1)&~(PAGE_SIZE-1))
#define GD_INC  (76 * sizeof(GpGlyphData) * 2)

// windows\advcore\gdiplus\engine\entry\facerealization.hpp
#define ALIGN4(X) (((X) + 3) & ~3)

// windows\advcore\gdiplus\engine\entry\metaplay.cpp
#define PLACEABLE_BUFFER_SIZE     (sizeof(WmfPlaceableFileHeader) + 2)
#define SETPAGETRANSFORMEPR_MINSIZE    (sizeof(REAL))

// windows\advcore\gdiplus\engine\fondrv\tt\scaler\interp.c
		#define UpdateRoundFunctionByProjectionVector(localGS)											\
			{																							\
				fnt_ParameterBlock *par = &(localGS).globalGS->localParBlock;							\
																										\
				(localGS).inSubPixelDirection = RunningSubPixel((localGS).globalGS) && InSubPixelDirection(localGS);							\
				par->RoundValue = itrp_RoundFunction[(localGS).inSubPixelDirection && (Tuned4SubPixel((localGS).globalGS) || (localGS).globalGS->pgmIndex != PREPROGRAM)][par->roundState];	\
			}
		#define UpdateRoundFunctionByProjectionVector(localGS)											\
			{																							\
				fnt_ParameterBlock *par = &(localGS).globalGS->localParBlock;							\
																										\
				(localGS).inSubPixelDirection = RunningSubPixel((localGS).globalGS) && InSubPixelDirection(localGS);							\
				par->RoundValue = itrp_RoundFunction[(localGS).inSubPixelDirection][par->roundState];	\
			}
	#define UpdateRoundFunctionByRoundState(localGS,state)											\
		{																							\
			fnt_ParameterBlock *par = &(localGS).globalGS->localParBlock;							\
																									\
			par->roundState = (state);																\
			par->RoundValue = itrp_RoundFunction[(localGS).inSubPixelDirection][par->roundState];	\
		}
#define CVTCI(parameterBlock,distance,originalDistance,overscale)													\
	{																												\
		F26Dot6 difference = distance - originalDistance;															\
		difference *= overscale;																					\
		if (difference > parameterBlock->wTCI || difference < -parameterBlock->wTCI) /* not within cvt cut-in? */	\
			distance = originalDistance;																			\
	}

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\fd.h
#define ALIGN4(X) (((X) + 3) & ~3)
#define ULONG_SIZE(x)  (((x) + sizeof(ULONG) - 1) / sizeof(ULONG))

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\fd_query.c
        #define ROUND_DOWN(X) ((X) & ~0xf)
        #define ROUND_UP(X)   (((X) + 15) & ~0xf)

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\fontfile.h
#define CJ_0  NATURAL_ALIGN(sizeof(fs_SplineKey) + STAMPEXTRA)
#define CJ_IN      NATURAL_ALIGN(sizeof(fs_GlyphInputType))
#define CJ_OUT     NATURAL_ALIGN(sizeof(fs_GlyphInfoType))

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\tt.h
#define SIZEOF_CMAPTABLE  (3 * sizeof(uint16))
#define KERN_SIZEOF_TABLE_HEADER                2 * sizeof(USHORT)
#define KERN_SIZEOF_SUBTABLE_HEADER             7 * sizeof(USHORT)

// windows\advcore\gdiplus\engine\imaging\api\imgutils.hpp
#define ALIGN4(x)       (((x) + 3) & ~3)
#define ALIGN16(x)      (((x) + 15) & ~15)

// windows\advcore\gdiplus\engine\imaging\jpeg\libjpeg\jinclude.h
#define JFREAD(file,buf,sizeofbuf)  \
  ((size_t) fread((void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))
#define JFWRITE(file,buf,sizeofbuf)  \
  ((size_t) fwrite((const void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))

// windows\advcore\gdiplus\engine\render\aarasterizer.cpp
    #define EDGE_STORE_STACK_NUMBER (1600 / sizeof(EpEdge))
    #define EDGE_STORE_ALLOCATION_NUMBER (4032 / sizeof(EpEdge))

// windows\advcore\gdiplus\engine\render\stretch.inc
#define ClampColors() \
        if(FilterMode == HighQualityBilinear)       \
        {                                           \
            ta = GpFix16Round(ta);                  \
            tr = GpFix16Round(tr);                  \
            tg = GpFix16Round(tg);                  \
            tb = GpFix16Round(tb);                  \
            if(ta>255) ta = 255;                    \
            if(tr>255) tr = 255;                    \
            if(tg>255) tg = 255;                    \
            if(tb>255) tb = 255;                    \
        }                                           \
        if(FilterMode == HighQualityBicubic)        \
        {                                           \
            ta = GpFix16Round(ta);                  \
            tr = GpFix16Round(tr);                  \
            tg = GpFix16Round(tg);                  \
            tb = GpFix16Round(tb);                  \
            if(ta>255) ta = 255;                    \
            if(tr>ta) tr = ta;                      \
            if(tg>ta) tg = ta;                      \
            if(tb>ta) tb = ta;                      \
            if(ta<0) ta = 0;                        \
            if(tr<0) tr = 0;                        \
            if(tg<0) tg = 0;                        \
            if(tb<0) tb = 0;                        \
        }

// windows\advcore\gdiplus\engine\text\imager\digitsubstitution.hpp
#define IsDBCSCodePage(acp)  ((acp) == 932 || \
                              (acp) == 936 || \
                              (acp) == 949 || \
                              (acp) == 950 )

// windows\advcore\gdiplus\test\driverhack\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// windows\advcore\gdiplus\test\fractal\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// windows\advcore\gdiplus\test\functest\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// windows\advcore\gdiplus\test\perftest\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// windows\advcore\gdiplus\test\pseudotest\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// windows\advcore\gdiplus\test\simpsons\dxtransp.h
#define IDXTLabel_GetBackgroundColor(This,pVal)	\
    (This)->lpVtbl -> GetBackgroundColor(This,pVal)
#define IDXTLabel_SetBackgroundColor(This,newVal)	\
    (This)->lpVtbl -> SetBackgroundColor(This,newVal)
#define IDX2D_SetBackgroundBrush(This,pBrush)	\
    (This)->lpVtbl -> SetBackgroundBrush(This,pBrush)
#define IDX2D_GetBackgroundBrush(This,pBrush)	\
    (This)->lpVtbl -> GetBackgroundBrush(This,pBrush)

// windows\appcompat\sdbapi\sdbp.h
#define READ_INDEX_KEY(pIndexRecord, iIndex, pullKey) \
    RtlMoveMemory((pullKey), &pIndexRecord[iIndex].ullKey, sizeof(*(pullKey)))

// windows\appcompat\shims\inc\shimstack.h
#define INIT_STACK(TotalSize, CopySize)                                       \
    InitializeCriticalSection(&g_csStack);                                    \
    g_pStack = VirtualAlloc(NULL, TotalSize * 4, MEM_COMMIT, PAGE_READWRITE); \
    g_dwStackSize = TotalSize;                                                \
    g_dwStackCopy = CopySize;

// windows\appcompat\tools\appsearch\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// windows\appcompat\tools\compatadmin\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// windows\appcompat\tools\smvtest\common\afxres.h
#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM)
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT)
#define CBRS_LEFT           (CBRS_ALIGN_LEFT|CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP|CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT|CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM|CBRS_BORDER_TOP)

// windows\core\dxkernel\dxg\ddagp.cxx
#define NUM_PAGES_FROM_CHUNK(x,y,z)                     \
    (((y) == NUM_CHUNKS(z)) ?                      \
        (PAGE_COUNT(z) - PAGE_FROM_CHUNK(x)) :          \
        (((y) - (x)) * DDLOCAL_AGP_MAPPING_PAGES))

// windows\core\dxkernel\dxg\ddhmgr.hxx
#define DD_TABLESIZE_DELTA ((PAGE_SIZE*4) / sizeof(DD_ENTRY))   // 4 pages of entries each time

// windows\core\ntcon\exts\stdext64.h
#define move(dst, src)  moveBlock(&(dst), src, sizeof(dst))
#define tryMove(dst, src)  tryMoveBlock(&(dst), src, sizeof(dst))

// windows\core\ntcon\inc\conime.h
#define CONIME_NOTIFY_CODEPAGE          (WM_USER+10)

// windows\core\ntcon\inc\output.h
#define VALID_TEXT_ATTRIBUTES (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY)

// windows\core\ntcon\inc\server.h
#define CM_SET_IME_CODEPAGE      (WM_USER+12)

// windows\core\ntcon\server\hard.c
#define KEY_WORK_AREA ((sizeof(KEY_VALUE_FULL_INFORMATION) + \
                        sizeof(ULONG)) + 256)

// windows\core\ntcon\server\output.c
#define GRGNDATASIZE  (sizeof(RGNDATAHEADER) + (6 * sizeof(RECTL)))

// windows\core\ntcon\test\graph\graph.c
#define FOREGROUND_WHITE (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)

// windows\core\ntcon\test\palette\palette.c
#define FOREGROUND_WHITE (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)

// windows\core\ntcon\test\scroll\scroll.c
#define FOREGROUND_WHITE (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)

// windows\core\ntgdi\client\dcquery.c
#define GET_CODE_PAGE(hdc,pDcAttr)                                           \
    ((!(pDcAttr->ulDirty_ & DIRTY_CHARSET) ? pDcAttr->iCS_CP                 \
                                           : NtGdiGetCharSet(hdc)) & 0xffff)

// windows\core\ntgdi\client\font.c
#define PAGE_ROUNDUP(x) (((x) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))

// windows\core\ntgdi\client\local.h
#define CLEAR_COLOR_PAGE(pldc) pldc->fl &= ~LDC_COLOR_PAGE
#define SET_COLOR_PAGE(pldc) pldc->fl |= LDC_COLOR_PAGE;
#define CHECK_COLOR_PAGE(pldc,color)            \
{                                               \
    if (!IS_COLOR_MONO(color))                  \
        pldc->fl |= LDC_COLOR_PAGE;             \
}
#define KHANDLE_ALIGN(size) ((size + sizeof(KHANDLE) - 1) & ~(sizeof(KHANDLE) - 1))
#define BEGIN_BATCH_HDC(hdc,pdca,cType,StrType)                               \
{                                                                             \
    PTEBSHARED ptebShared = NtCurrentTebShared();                             \
    StrType *pBatch;                                                          \
    HDC      hdcBatch = hdc;                                                  \
                                                                              \
    if (!(                                                                    \
         (                                                                    \
           (ptebShared->GdiTebBatch.HDC == 0)          ||                     \
           (ptebShared->GdiTebBatch.HDC == (ULONG_PTR)hdc)                    \
         ) &&                                                                 \
         ((ptebShared->GdiTebBatch.Offset + KHANDLE_ALIGN(sizeof(StrType))) <= GDI_BATCH_SIZE) &&  \
         (pdca != NULL) &&                                                    \
         (!(pdca->ulDirty_ & DC_DIBSECTION))                                  \
       ))                                                                     \
    {                                                                         \
        goto UNBATCHED_COMMAND;                                               \
    }                                                                         \
                                                                              \
    pBatch = (StrType *)(                                                     \
                          ((PBYTE)(&ptebShared->GdiTebBatch.Buffer[0])) +     \
                          ptebShared->GdiTebBatch.Offset                      \
                        );                                                    \
                                                                              \
    pBatch->Type              = cType;                                        \
    pBatch->Length            = KHANDLE_ALIGN(sizeof(StrType));               \
                                                                              \
    if (cType < BatchTypeSetBrushOrg)                                         \
    {                                                                         \
        pdca->ulDirty_ |= BATCHED_DRAWING;                                    \
    }                                                                         \
                                                                              \
    if (cType == BatchTypeTextOut)                                            \
    {                                                                         \
        pdca->ulDirty_ |= BATCHED_TEXT;                                       \
    }
#define BEGIN_BATCH_HDC_SIZE(hdc,pdca,cType,StrType,Size)                 \
{                                                                         \
    PTEBSHARED ptebShared = NtCurrentTebShared();                         \
    StrType *pBatch;                                                      \
    HDC      hdcBatch = hdc;                                              \
                                                                          \
    if (!(                                                                \
         (                                                                \
           (ptebShared->GdiTebBatch.HDC == 0)          ||                 \
           (ptebShared->GdiTebBatch.HDC == (ULONG_PTR)hdc)                \
         ) &&                                                             \
         ((ptebShared->GdiTebBatch.Offset + KHANDLE_ALIGN(Size)) <= GDI_BATCH_SIZE) &&   \
         (pdca != NULL) &&                                                \
         (!(pdca->ulDirty_ & DC_DIBSECTION))                              \
       ))                                                                 \
    {                                                                     \
        goto UNBATCHED_COMMAND;                                           \
    }                                                                     \
                                                                          \
    pBatch = (StrType *)(                                                 \
                          ((PBYTE)(&ptebShared->GdiTebBatch.Buffer[0])) + \
                          ptebShared->GdiTebBatch.Offset                  \
                        );                                                \
                                                                          \
    pBatch->Type              = cType;                                    \
    pBatch->Length            = KHANDLE_ALIGN(Size);                      \
    pBatch->Length            = Size;                                     \
                                                                          \
    if (cType < BatchTypeSetBrushOrg)                                     \
    {                                                                     \
        pdca->ulDirty_ |= BATCHED_DRAWING;                                \
    }                                                                     \
                                                                          \
    if (cType == BatchTypeTextOut)                                        \
    {                                                                     \
        pdca->ulDirty_ |= BATCHED_TEXT;                                   \
    }
#define BEGIN_BATCH(cType,StrType)                                            \
{                                                                             \
    PTEBSHARED ptebShared = NtCurrentTebShared();                             \
    StrType *pBatch;                                                          \
    HDC      hdcBatch = NULL;                                                 \
                                                                              \
    if (ptebShared->Win32ThreadInfo == NULL)                                  \
    {                                                                         \
        goto UNBATCHED_COMMAND;                                               \
    }                                                                         \
                                                                              \
    if (!                                                                     \
         ((ptebShared->GdiTebBatch.Offset + KHANDLE_ALIGN(sizeof(StrType))) <= GDI_BATCH_SIZE) \
       )                                                                      \
    {                                                                         \
        goto UNBATCHED_COMMAND;                                               \
    }                                                                         \
                                                                              \
    pBatch = (StrType *)(                                                     \
                          ((PBYTE)(&ptebShared->GdiTebBatch.Buffer[0])) +     \
                          ptebShared->GdiTebBatch.Offset                      \
                        );                                                    \
                                                                              \
    pBatch->Type              = cType;                                        \
    pBatch->Length            = KHANDLE_ALIGN(sizeof(StrType));               \

// windows\core\ntgdi\client\metadef.h
#define pmetalink16Create(h) ((PMETALINK16)plinkCreate(h,sizeof(METALINK16)))

// windows\core\ntgdi\client\mfrec.hxx
#define SIZEOF_MR       (sizeof(MR))
#define SIZEOF_MRB      (sizeof(MRB))
#define SIZEOF_MRD      (sizeof(MRD))
#define SIZEOF_MRDD     (sizeof(MRDD))
#define SIZEOF_MRDDDD   (sizeof(MRDDDD))
#define SIZEOF_MRX      (sizeof(MRX))
#define SIZEOF_MRXD     (sizeof(MRXD))
#define SIZEOF_MRE      (sizeof(MRE))
#define SIZEOF_MREPP    (sizeof(MREPP))
#define SIZEOF_MRBR(cRgnData)   (sizeof(MRBR) + ((cRgnData) + 3) / 4 * 4)
#define SIZEOF_MRFILLRGN(cRgnData)      \
        (SIZEOF_MRBR(cRgnData) + sizeof(MRFILLRGN) - sizeof(MRBR))
#define SIZEOF_MRFRAMERGN(cRgnData)     \
        (SIZEOF_MRBR(cRgnData) + sizeof(MRFRAMERGN) - sizeof(MRBR))
#define SIZEOF_MREXTSELECTCLIPRGN(cRgnData)     \
        (sizeof(MREXTSELECTCLIPRGN) + ((cRgnData) + 3) / 4 * 4)
#define SIZEOF_MRGRADIENTFILL(nVer,nTri)  (                                                \
                                            sizeof(MRGRADIENTFILL)                         \
                                            - sizeof(TRIVERTEX) + (nVer)*sizeof(TRIVERTEX) \
                                            + ((((sizeof(GRADIENT_TRIANGLE) * nTri) + 3)/4)*4)    \
                                          )
#define SIZEOF_MRMETAFILE(cwszDescription)              \
        (sizeof(MRMETAFILE) + (((cwszDescription) * 2) + 3) / 4 * 4)
#define SIZEOF_MRANGLEARC       (sizeof(MRANGLEARC))
#define SIZEOF_MRROUNDRECT      (sizeof(MRROUNDRECT))
#define SIZEOF_MRCREATEPEN      (sizeof(MRCREATEPEN))
#define SIZEOF_MRCREATECOLORSPACEW(cb)      \
        ((sizeof(MRCREATECOLORSPACEW)-PADCHAR_SIZE+(cb)+3)& ~3)
#define SIZEOF_MRCREATEBRUSHINDIRECT    (sizeof(MRCREATEBRUSHINDIRECT))
#define SIZEOF_MREXTCREATEFONTINDIRECTW (sizeof(MREXTCREATEFONTINDIRECTW))
#define SIZEOF_MREXTFLOODFILL   (sizeof(MREXTFLOODFILL))
#define SIZEOF_MRGDICOMMENT(cb)      \
        ((sizeof(MRGDICOMMENT)-PADCHAR_SIZE+(cb)+3)& ~3)
#define SIZEOF_MRGDICOMMENT_WINDOWS_METAFILE(cb)      \
        ((sizeof(EMRGDICOMMENT_WINDOWS_METAFILE)+(cb)+3) & ~3)
#define SIZEOF_MRGLSRECORD(cb)      \
        ((sizeof(MRGLSRECORD)-PADCHAR_SIZE+(cb)+3)& ~3)
#define SIZEOF_MRGLSBOUNDEDRECORD(cb)      \
        ((sizeof(MRGLSBOUNDEDRECORD)-PADCHAR_SIZE+(cb)+3)& ~3)
#define SIZEOF_MRSETICMPROFILE(cb)      \
        ((sizeof(MRSETICMPROFILE)-PADCHAR_SIZE+(cb)+3)& ~3)
#define SIZEOF_MRCOLORMATCHTOTARGET(cb)      \
        ((sizeof(MRCOLORMATCHTOTARGET)-PADCHAR_SIZE+(cb)+3)& ~3)

// windows\core\ntgdi\client\ufi.c
#define SZDLHEADER    ((sizeof(DOWNLOADFONTHEADER) + 7)&~7)

// windows\core\ntgdi\client\umpd.cxx
#define ALIGN_UMPD_BUFFER(cj)   (((cj) + (sizeof(KERNEL_PVOID) -1)) & ~(sizeof(KERNEL_PVOID)-1))

// windows\core\ntgdi\client\xform.c
#define DCA_PAGE_EXTENTS_CHANGED(pdcattr)               \
{                                                       \
    CLEAR_CACHED_TEXT(pdcattr);                         \
    pdcattr->flXform |= (INVALIDATE_ATTRIBUTES    |     \
                         PAGE_EXTENTS_CHANGED     |     \
                         DEVICE_TO_WORLD_INVALID);      \
}
#define DCA_PAGE_XLATE_CHANGED(pdcattr)                 \
{                                                       \
    pdcattr->flXform |=  (PAGE_XLATE_CHANGED |          \
                          DEVICE_TO_WORLD_INVALID);     \
}

// windows\core\ntgdi\fondrv\tt\mssipotf\fs\interp.c
		#define UpdateRoundFunctionByProjectionVector(localGS)											\
			{																							\
				fnt_ParameterBlock *par = &(localGS).globalGS->localParBlock;							\
																										\
				(localGS).inSubPixelDirection = RunningSubPixel((localGS).globalGS) && InSubPixelDirection(localGS);							\
				par->RoundValue = itrp_RoundFunction[(localGS).inSubPixelDirection && (Tuned4SubPixel((localGS).globalGS) || (localGS).globalGS->pgmIndex != PREPROGRAM)][par->roundState];	\
			}
		#define UpdateRoundFunctionByProjectionVector(localGS)											\
			{																							\
				fnt_ParameterBlock *par = &(localGS).globalGS->localParBlock;							\
																										\
				(localGS).inSubPixelDirection = RunningSubPixel((localGS).globalGS) && InSubPixelDirection(localGS);							\
				par->RoundValue = itrp_RoundFunction[(localGS).inSubPixelDirection][par->roundState];	\
			}
	#define UpdateRoundFunctionByRoundState(localGS,state)											\
		{																							\
			fnt_ParameterBlock *par = &(localGS).globalGS->localParBlock;							\
																									\
			par->roundState = (state);																\
			par->RoundValue = itrp_RoundFunction[(localGS).inSubPixelDirection][par->roundState];	\
		}
#define CVTCI(parameterBlock,distance,originalDistance,overscale)													\
	{																												\
		F26Dot6 difference = distance - originalDistance;															\
		difference *= overscale;																					\
		if (difference > parameterBlock->wTCI || difference < -parameterBlock->wTCI) /* not within cvt cut-in? */	\
			distance = originalDistance;																			\
	}

// windows\core\ntgdi\fondrv\tt\scaler\interp.c
		#define UpdateRoundFunctionByProjectionVector(localGS)											\
			{																							\
				fnt_ParameterBlock *par = &(localGS).globalGS->localParBlock;							\
																										\
				(localGS).inSubPixelDirection = RunningSubPixel((localGS).globalGS) && InSubPixelDirection(localGS);							\
				par->RoundValue = itrp_RoundFunction[(localGS).inSubPixelDirection && (Tuned4SubPixel((localGS).globalGS) || (localGS).globalGS->pgmIndex != PREPROGRAM)][par->roundState];	\
			}
		#define UpdateRoundFunctionByProjectionVector(localGS)											\
			{																							\
				fnt_ParameterBlock *par = &(localGS).globalGS->localParBlock;							\
																										\
				(localGS).inSubPixelDirection = RunningSubPixel((localGS).globalGS) && InSubPixelDirection(localGS);							\
				par->RoundValue = itrp_RoundFunction[(localGS).inSubPixelDirection][par->roundState];	\
			}
	#define UpdateRoundFunctionByRoundState(localGS,state)											\
		{																							\
			fnt_ParameterBlock *par = &(localGS).globalGS->localParBlock;							\
																									\
			par->roundState = (state);																\
			par->RoundValue = itrp_RoundFunction[(localGS).inSubPixelDirection][par->roundState];	\
		}
#define CVTCI(parameterBlock,distance,originalDistance,overscale)													\
	{																												\
		F26Dot6 difference = distance - originalDistance;															\
		difference *= overscale;																					\
		if (difference > parameterBlock->wTCI || difference < -parameterBlock->wTCI) /* not within cvt cut-in? */	\
			distance = originalDistance;																			\
	}

// windows\core\ntgdi\fondrv\tt\ttfd\fd.h
#define ULONG_SIZE(x)  (((x) + sizeof(ULONG) - 1) / sizeof(ULONG))

// windows\core\ntgdi\fondrv\tt\ttfd\fd_query.c
            #define ROUND_DOWN(X) ((X) & ~0xf)
            #define ROUND_UP(X)   (((X) + 15) & ~0xf)

// windows\core\ntgdi\fondrv\tt\ttfd\fdfon.c
#define MICROSS_SHELLFONT_SIZE      sizeof(PSZ_MICROSS_SHELLFONT)
#define TAHOMA_SHELLFONT_SIZE       sizeof(PSZ_TAHOMA_SHELLFONT)
#define TAHOMA_BOLD_SHELLFONT_SIZE  sizeof(PSZ_TAHOMA_BOLD_SHELLFONT)

// windows\core\ntgdi\fondrv\tt\ttfd\fontfile.h
#define CJ_0  NATURAL_ALIGN(sizeof(fs_SplineKey) + STAMPEXTRA)
#define CJ_IN      NATURAL_ALIGN(sizeof(fs_GlyphInputType))
#define CJ_OUT     NATURAL_ALIGN(sizeof(fs_GlyphInfoType))

// windows\core\ntgdi\fondrv\tt\ttfd\tt.h
#define SIZEOF_CMAPTABLE  (3 * sizeof(uint16))
#define KERN_SIZEOF_TABLE_HEADER                2 * sizeof(USHORT)
#define KERN_SIZEOF_SUBTABLE_HEADER             7 * sizeof(USHORT)

// windows\core\ntgdi\gre\cache.cxx
#define ROUND_TO_PAGE(x)  (((x)+PAGE_SIZE-1)&~(PAGE_SIZE-1))

// windows\core\ntgdi\gre\debug.h
    #define GDITRACE_KEY_MASK_BITS_TEST     16  // 8*sizeof(GDITraceKeyMask)
    #define GDITRACE_CLASS_MASK_BITS_TEST   32  // 8*sizeof(GDITraceClassMask)

// windows\core\ntgdi\gre\engine.h
#define ALIGN4(X) (((X) + 3) & ~3)
#define ALIGN8(X) (((X) + 7) & ~7)
#define FIX_FLOOR(x)         ((x) & ~(FIX_ONE - 1L))

// windows\core\ntgdi\gre\floodgdi.cxx
#define FLOOD_REGION_SIZE  (NULL_REGION_SIZE                                 + \
                           (NULL_SCAN_SIZE + (sizeof(INDEX_LONG) * 2)) * 200 + \
                            NULL_SCAN_SIZE)

// windows\core\ntgdi\gre\greold.h
#define IS_ANY_DBCS_CODEPAGE( CodePage ) (((CodePage) == 932) ? TRUE :    \
                                          ((CodePage) == 949) ? TRUE :    \
                                          ((CodePage) == 1361) ? TRUE :    \
                                          ((CodePage) == 950) ? TRUE :    \
                                          ((CodePage) == 936) ? TRUE : FALSE )

// windows\core\ntgdi\gre\hmgrp.hxx
#define HMG_DC_SIZE       sizeof(DC)
#define HMG_BRUSH_SIZE    sizeof(BRUSH)
#define HMG_RFONT_SIZE    sizeof(RFONT)

// windows\core\ntgdi\gre\ntgdi.c
#define ALIGN4(X) (((X) + 3) & ~3)

// windows\core\ntgdi\gre\pfeobj.hxx
#define NATURAL_ALIGN(x)  (((x) + 3L) & ~3L)
#define NATURAL_ALIGN(x)  (((x) + 7L) & ~7L)

// windows\core\ntgdi\gre\region.hxx
#define SINGLE_REGION_SIZE  (NULL_REGION_SIZE                           + \
                             NULL_SCAN_SIZE + (sizeof(INDEX_LONG) * 2)  + \
                             NULL_SCAN_SIZE)
#define QUANTUM_REGION_SIZE (NULL_REGION_SIZE                           + \
                             NULL_SCAN_SIZE + (sizeof(INDEX_LONG) * 2)  + \
                             NULL_SCAN_SIZE + (sizeof(INDEX_LONG) * 4)  + \
                             NULL_SCAN_SIZE + (sizeof(INDEX_LONG) * 2)  + \
                             NULL_SCAN_SIZE)

// windows\core\ntgdi\gre\ttgdi.cxx
#define HEADERSTUFFLEN1     (5 * sizeof(USHORT))
#define MOREHEADERSTUFFLEN  (2 * sizeof(USHORT))

// windows\core\ntgdi\gre\umpd.hxx
#define ALIGN_UMPD_BUFFER(cj)   (((cj) + (sizeof(PVOID) -1)) & ~(sizeof(PVOID)-1))

// windows\core\ntgdi\gre\umpddrv.cxx
#define  UMPD_SIZEINOUTPUT(Input, Output)                                           \
            ALIGN_UMPD_BUFFER(sizeof(Input)) + ALIGN_UMPD_BUFFER(sizeof(Output))
#define  UMPD_SIZEXLATEOBJ(pxlo)                                                    \
            (pxlo ? (ALIGN_UMPD_BUFFER(pxlo->cEntries * sizeof(ULONG)) + ALIGN_UMPD_BUFFER(sizeof(XLATEOBJ))) : 0)
#define  UMPD_SIZESTROBJ(pstro)                                                         \
            pstro ? ALIGN_UMPD_BUFFER(sizeof(WCHAR) * pstro->cGlyphs) +                 \
                    ALIGN_UMPD_BUFFER(sizeof(GLYPHPOS) * pstro->cGlyphs) +              \
                    ALIGN_UMPD_BUFFER(sizeof(STROBJ))                                   \
                  : 0
#define  UMPD_SIZELINEATTRS(plineattrs)                                                     \
            plineattrs ? ALIGN_UMPD_BUFFER(plineattrs->cstyle * sizeof(FLOAT_LONG)) +       \
                         ALIGN_UMPD_BUFFER(sizeof(LINEATTRS))                               \
                       : 0
#define  UMPD_SIZEXFORMOBJ      ALIGN_UMPD_BUFFER(sizeof(XFORMOBJ))
#define  UMPD_SIZERECTL         ALIGN_UMPD_BUFFER(sizeof(RECTL))
#define  UMPD_SIZECLIPOBJ       ALIGN_UMPD_BUFFER(sizeof(CLIPOBJ))
#define  UMPD_SIZEPOINTL        ALIGN_UMPD_BUFFER(sizeof(POINTL))
#define  UMPD_SIZEPERBANDI      ALIGN_UMPD_BUFFER(sizeof(PERBANDINFO))
#define  UMPD_SIZECOLORADJ      ALIGN_UMPD_BUFFER(sizeof(COLORADJUSTMENT))
#define  UMPD_SIZEBRUSHOBJ      ALIGN_UMPD_BUFFER(sizeof(BRUSHOBJ))
#define  UMPD_SIZEFONTOBJ       ALIGN_UMPD_BUFFER(sizeof(FONTOBJ))
#define  UMPD_SIZEBLENDOBJ      ALIGN_UMPD_BUFFER(sizeof(BLENDOBJ))
#define  UMPD_SIZEPATHOBJ       ALIGN_UMPD_BUFFER(sizeof(PATHOBJ))

// windows\core\ntgdi\halftone\ht\htalias.c
#define SIZE_AAINFO     _ALIGN_MEM(sizeof(AAINFO))

// windows\core\ntgdi\halftone\ht\htalias.h
#define MUL_TABLE_SIZE  (DI_MUL_SHIFT * 256 * sizeof(LONG))

// windows\core\ntgdi\halftone\ht\htmapclr.h
#define CRTX_SIZE_255               (sizeof(FD6XYZ) * (256 * 3))

// windows\core\ntgdi\halftone\ht\htmath.h
#define SIZE_FD6        sizeof(FD6)

// windows\core\ntgdi\halftone\ht\htmemory.h
#define _ALIGN_MEM(x)   (((x) + (CB_MEM_ALIGN) - 1) & ~((CB_MEM_ALIGN) - 1))

// windows\core\ntgdi\halftone\ht\htpat.c
#define PAT_DATA(x,y,p)     (x), (y), sizeof(p), (p)

// windows\core\ntgdi\inc\hmgshare.h
#define USER_XFORM_DIRTY(pdcattr) (pdcattr->flXform & (PAGE_XLATE_CHANGED | PAGE_EXTENTS_CHANGED | WORLD_XFORM_CHANGED))

// windows\core\ntgdi\inc\ht.h
#define SIZE_SHORT          sizeof(SHORT)
#define SIZE_LONG           sizeof(LONG)
#define SIZE_UINT           sizeof(UINT)
#define SIZE_INT            sizeof(INT)
#define SIZE_UDECI4         sizeof(UDECI4)
#define SIZE_DECI4          sizeof(DECI4)

// windows\core\ntgdi\inc\mapfile.h
#define IS_ANY_DBCS_CODEPAGE( CodePage ) (((CodePage) == 932) ? TRUE :    \
                                          ((CodePage) == 949) ? TRUE :    \
                                          ((CodePage) == 950) ? TRUE :    \
                                          ((CodePage) == 936) ? TRUE : FALSE )

// windows\core\ntgdi\kdexts2\dcexts.cxx
#define GetDCSubField(field,local)          \
        GetFieldData(offDC, GDIType(DC), field, sizeof(local), &local)
#define GetDCATTRSubField(field,local)      \
        GetFieldData(offDCATTR, GDIType(_DC_ATTR), field, sizeof(local), &local)
#define GetDCLEVELSubField(field,local)     \
        GetFieldData(offDCLEVEL, GDIType(DCLEVEL), field, sizeof(local), &local)
#define GetERECTLvalues {   \
        GetFieldData(percl, "ERECTL", "left", sizeof(left), &left);         \
        GetFieldData(percl, "ERECTL", "top", sizeof(top), &top);            \
        GetFieldData(percl, "ERECTL", "right", sizeof(right), &right);      \
        GetFieldData(percl, "ERECTL", "bottom", sizeof(bottom), &bottom);   \
}

// windows\core\ntgdi\kdexts2\path.cxx
#define GetPATHSubField(field,local) \
        GetFieldData(offPATH, "PATH", field, sizeof(local), &local)
#define GetPATHRECORDSubField(field,local) \
        GetFieldData(offPATHRECORD, "PATHRECORD", field, sizeof(local), &local)

// windows\core\ntgdi\kdexts2\precomp.hxx
#define POOL_BLOCK_SHIFT_OLD ((PageSize == 0x4000)  ? 6 : (((PageSize == 0x2000) || ((BuildNo < 2257) && (PageSize == 0x1000))) ? 5 : 4))
#define PAGE_ALIGN64(Va) ((ULONG64)((Va) & ~((ULONG64) (PageSize - 1))))

// windows\core\ntgdi\test\fonttest.nt\enum.c
#define SIZEOFDESIGNVECTOR(cAxes) (sizeof(DESIGNVECTOR) + ((cAxes) - 1) * sizeof(LONG))
#define SIZEOFAXESLISTA(cAxes) (sizeof(AXESLISTA) + ((cAxes) - 1) * sizeof(AXISINFOA))
#define ALIGN4(X) (((X) + 3) & ~3)

// windows\core\ntgdi\test\ft\ftjnl.c
#define CPAGES	(sizeof(ajf) / sizeof(PFN_FT_TEST))

// windows\core\ntgdi\test\gdibench\gdibench.h
#define START_IO_COUNT pfnNtQuerySystemInformation(SystemPerformanceInformation, &SysInfo, sizeof(SYSTEM_PERFORMANCE_INFORMATION), NULL);	 \
                       InitialPageFaultCount = SysInfo.PageReadIoCount; \
	                   InitialPagesReadCount = SysInfo.PageReadCount
#define STOP_IO_COUNT  pfnNtQuerySystemInformation(SystemPerformanceInformation, &SysInfo, sizeof(SYSTEM_PERFORMANCE_INFORMATION), NULL);	 \
                       PageFaults = SysInfo.PageReadIoCount - InitialPageFaultCount; \
                       PagesRead  = SysInfo.PageReadCount   - InitialPagesReadCount

// windows\core\ntuser\client\client.c
#define NSZKLKEY   (sizeof szKLKey + 16)

// windows\core\ntuser\client\clmsg.c
#define BEGIN_CALLWINPROC(fInsideHook, lRet)                            \
    PCLIENTTHREADINFO pcti = GetClientInfo()->pClientThreadInfo;        \
    BOOL fCallBack = ((pcti!=NULL) &&                                   \
             TEST_BOOL_FLAG(pcti->CTIF_flags, CTIF_INCALLBACKMESSAGE)); \
    RTL_CALLER_ALLOCATED_ACTIVATION_CONTEXT_STACK_FRAME ActivationFrame \
        = {                                                             \
            sizeof(ActivationFrame),                                    \
    RTL_CALLER_ALLOCATED_ACTIVATION_CONTEXT_STACK_FRAME_FORMAT_WHISTLER \
        };                                                              \
    fInsideHook = FALSE;                                                \
                                                                        \
    if (!fCallBack) {                                                   \
        RtlActivateActivationContextUnsafeFast(                         \
            &ActivationFrame,                                           \
            pActCtx);                                                   \
                                                                        \
        fInsideHook = _BeginIfHookedUserApiHook();                      \
    }                                                                   \
                                                                        \
    __try {                                                             \

// windows\core\ntuser\client\ddetrack.c
#define DDEDATA_WITH_HANDLE_SIZE  (sizeof (DDEDATA_WOW6432))
#define DDEDATA_WITH_HANDLE_SIZE  (sizeof (DDE_DATA))

// windows\core\ntuser\inc\user.h
#define IS_DBCS_CODEPAGE(wCodePage) \
            ((wCodePage) == CP_JAPANESE || \
             (wCodePage) == CP_KOREAN || \
             (wCodePage) == CP_CHINESE_TRAD || \
             (wCodePage) == CP_CHINESE_SIMP)
#define GWLP_SHINST         GWL_CONVSTATE + sizeof(LONG)
#define GWLP_CHINST         GWLP_SHINST + sizeof(HANDLE)
#define FIELD_SIZE(type, field)     (sizeof(((type *)0)->field))
#define TestwndFrameOn(pwnd) (TestWF(pwnd, WFFRAMEON) && (GETPTI(pwnd)->pq == gpqForeground))

// windows\core\ntuser\kdexts\stdext64.h
#define move(dst, src)  moveBlock(&(dst), src, sizeof(dst))
#define tryMove(dst, src)  tryMoveBlock(&(dst), src, sizeof(dst))

// windows\core\ntuser\kernel\fekbd.c
#define NLS_CLEAR_VK(Vk)  \
    ((Vk) &= (KBDEXT|KBDMULTIVK|KBDSPECIAL|KBDNUMPAD|KBDBREAK))
#define NLS_CLEAR_VK_AND_ATTR(Vk) \
    ((Vk) &= (KBDEXT|KBDMULTIVK|KBDSPECIAL|KBDNUMPAD))

// windows\core\ntuser\kernel\server.c
#define ROUND_UP_TO_PAGES(SIZE) \
        (((ULONG)(SIZE) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))

// windows\core\ntuser\kernel\userk.h
#define CHARALIGN sizeof(WCHAR)
#define ProbeForReadBuffer(Address, Count, Alignment) {                     \
    if ((ULONG)(Count) > (ULONG)(MAXULONG / sizeof(*(Address)))) {          \
        ExRaiseAccessViolation();                                           \
    }                                                                       \
    ProbeForRead(Address, (ULONG)(Count) * sizeof(*(Address)), Alignment);  \
}
#define ProbeForWriteBuffer(Address, Count, Alignment) {                    \
    if ((ULONG)(Count) > (ULONG)(MAXULONG / sizeof(*(Address)))) {          \
        ExRaiseAccessViolation();                                           \
    }                                                                       \
    ProbeForWrite(Address, (ULONG)(Count) * sizeof(*(Address)), Alignment); \
}

// windows\core\ntuser\rtl\alignrec.c
#define INTERSECTION_AXIS_UNKNOWN(code) (code & 2)

// windows\core\ntuser\rtl\chartran.c
#define IS_ACP(cp) (((cp) == NlsAnsiCodePage) || ((cp) == CP_ACP))

// windows\core\ntuser\rtl\userrtl.h
        #define USERGETCODEPAGE(hdc) (GreGetCharSet(hdc) & 0x0000FFFF)

// windows\core\w32inc\usergdi.h
    #define POOL_HEADER_SIZE   (sizeof(Win32PoolHead) + MM_POOL_HEADER_SIZE)

// windows\core\w32inc\w32wow64.h
    #define COPY_KERNELMSG_TO_MSG(pmsg, pkmsg) RtlCopyMemory(pmsg, pkmsg, sizeof(MSG))
    #define COPY_MSG_TO_KERNELMSG(pkmsg, pmsg) RtlCopyMemory(pkmsg, pmsg, sizeof(MSG))

// windows\core\wow64win\whwin32\whwin32.tpl
#define OUTLINETEXTMETRICWDELTA (ALIGN4(sizeof(OUTLINETEXTMETRICW)) - ALIGN4(sizeof(NT32OUTLINETEXTMETRICW))) @NL

// windows\core\wow64win\whwin32\whwin32p.h
#define ALIGN4(X) (((X) + 3) & ~3)

// windows\feime\chs\ntabc\winabc\abc95def.h
#define CMENU_MENU              (CMENU_HUIWND+sizeof(CMENU_HUIWND))
#define WND_EXTRA_SIZE          (CMENU_MENU+sizeof(CMENU_HUIWND))

// windows\feime\chs\ntgen\upimeres.h
#define CBLONG      (sizeof(LONG))

// windows\feime\chs\ntgen\upimeres\upimeres.h
#define CBLONG      (sizeof(LONG))

// windows\feime\ddk\jpn\fakeime.h
#define FIGWL_SVRWND       (FIGWL_MOUSE+sizeof(LONG))

// windows\feime\fe\chimemig\poolmem.h
#define PoolMemCreateString(h,x)        ((LPTSTR) PoolMemGetAlignedMemory((h),(x)*sizeof(TCHAR)))

// windows\feime\kor\ime2k\imm32\toolbar.h
#define UPDTTB_ALL (UPDTTB_CMODE|UPDTTB_FHMODE|UPDTTB_HJMODE|UPDTTB_PAD|UPDTTB_PROP)

// windows\feime\kor\imeui.c
#define BGR_BACKGROUNDSEL   (RGB(255,000,000))  // blue
#define BGR_BACKGROUND      (RGB(255,000,255))  // magenta

// windows\netdde\src\netdde\wininfo.h
#define WNDEXTRA                sizeof(void far *)       // sizeof void far *

// windows\richedit\inc30\imeapp.h
#define	RWM_SHOWIMEPAD			TEXT("MSIMEShowImePad")

// windows\richedit\inc41\imeapp.h
#define	RWM_SHOWIMEPAD			TEXT("MSIMEShowImePad")

// windows\richedit\inci\lscfmtfl.h
#define FForgetLastTabAlignment(plsc) \
		(plsc)->lsadjustcontext.ForgetLastTabAlignment
#define SetForgetLastTabAlignment(plsc,f) \
		(plsc)->lsadjustcontext.fForgetLastTabAlignment = (f);

// windows\richedit\inci\lsdnode.h
#define FIsDnodeSplat(plsdn) ((plsdn)->fEndOfSection || \
								(plsdn)->fEndOfColumn || (plsdn)->fEndOfPage )

// windows\richedit\lssrc\break.c
#define EndrFromBreakDnode(plsdnBreak)\
	(plsdnBreak == NULL) ? endrStopped : \
		(plsdnBreak->fEndOfPara) ? endrEndPara : \
			(plsdnBreak->fAltEndOfPara) ? endrAltEndPara : \
				(plsdnBreak->fSoftCR) ? endrSoftCR : \
					(plsdnBreak->fEndOfColumn) ? endrEndColumn : \
						(plsdnBreak->fEndOfSection) ? endrEndSection : \
							(plsdnBreak->fEndOfPage) ? endrEndPage : \
								endrStopped

// windows\richedit\lssrc\lsqline.c
#define FIsSplat(endr)	(endr == endrEndColumn 	|| 	\
						endr == endrEndSection 	|| 	\
						endr == endrEndPage)

// windows\richedit\lssrc\warichu.c
#define ZeroObjDim(pobjdim) memset ((pobjdim), 0, sizeof(OBJDIM));

// windows\richedit\re30\_common.h
#define EM_GETCODEPAGE	(WM_USER + 151)

// windows\richedit\re30\aimm.h
#define IActiveIMMApp_GetCodePageA(This,hKL,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage)
#define IActiveIMMIME_GetCodePageA(This,hKL,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage)
#define IActiveIME_GetCodePageA(This,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,uCodePage)

// windows\richedit\re30\urlsup.cpp
#define NUMURLHDR		sizeof(rgcchURL)
#define NUMDOTURLHDR		sizeof(rgcchDOTURL)

// windows\richedit\re30\w32sys.cpp
#define cbPvh (sizeof(PVH))
#define cbPvt (sizeof(PVT))

// windows\richedit\re41\_cfpf.h
#define GetCellVertAlign(x)	((x) & 0x03000000)
#define IsCellVertAlignCenter(x) ((x) & 0x01000000)

// windows\richedit\re41\_common.h
#define EM_GETCODEPAGE	(WM_USER + 151)

// windows\richedit\re41\aimm.h
#define IActiveIMMApp_GetCodePageA(This,hKL,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage)
#define IActiveIMMIME_GetCodePageA(This,hKL,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage)
#define IActiveIME_GetCodePageA(This,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,uCodePage)
#define IActiveIME2_GetCodePageA(This,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,uCodePage)

// windows\richedit\re41\aimmex.h
#define IActiveIMMAppEx_GetCodePageA(This,hKL,uCodePage)	\
    (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage)

// windows\richedit\re41\msctf.h
#define ITfKeystrokeMgr_AdviseKeyEventSink(This,tid,pSink,fForeground)	\
    (This)->lpVtbl -> AdviseKeyEventSink(This,tid,pSink,fForeground)
#define ITfKeystrokeMgr_GetForeground(This,pclsid)	\
    (This)->lpVtbl -> GetForeground(This,pclsid)
#define ITfKeyEventSink_OnSetFocus(This,fForeground)	\
    (This)->lpVtbl -> OnSetFocus(This,fForeground)

// windows\richedit\re41\msctfp.h
#define ITfBackgroundThreadMgr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITfBackgroundThreadMgr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITfBackgroundThreadMgr_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITfBackgroundThreadMgr_AppInitBackgroundThread(This,pfnWakeThread,ppfnCallback,ppvPrivate)	\
    (This)->lpVtbl -> AppInitBackgroundThread(This,pfnWakeThread,ppfnCallback,ppvPrivate)
#define ITfBackgroundThreadMgr_AppUninitBackgroundThread(This)	\
    (This)->lpVtbl -> AppUninitBackgroundThread(This)
#define ITfBackgroundThreadMgr_AdviseBackgroundCallback(This,pfnCallback,pvPrivate,pdwCookie)	\
    (This)->lpVtbl -> AdviseBackgroundCallback(This,pfnCallback,pvPrivate,pdwCookie)
#define ITfBackgroundThreadMgr_UnadviseBackgroundCallback(This,dwCookie)	\
    (This)->lpVtbl -> UnadviseBackgroundCallback(This,dwCookie)
#define ITfBackgroundThreadMgr_WakeBackgroundThread(This)	\
    (This)->lpVtbl -> WakeBackgroundThread(This)

// windows\richedit\re41\urlsup.cpp
#define NUMURLHDR		sizeof(rgcchURL)
#define NUMDOTURLHDR		sizeof(rgcchDOTURL)

// windows\richedit\re41\utilmem.cpp
#define cbPvh (sizeof(PVH))
#define cbPvt (sizeof(PVT))

// windows\richedit\tom41\tom.h
#define ITextDocument_Open(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Open(This,pVar,Flags,CodePage)
#define ITextDocument_Save(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Save(This,pVar,Flags,CodePage)
#define ITextPara_GetAlignment(This,pValue)	\
    (This)->lpVtbl -> GetAlignment(This,pValue)
#define ITextPara_SetAlignment(This,Value)	\
    (This)->lpVtbl -> SetAlignment(This,Value)
#define ITextPara_GetListAlignment(This,pValue)	\
    (This)->lpVtbl -> GetListAlignment(This,pValue)
#define ITextPara_SetListAlignment(This,Value)	\
    (This)->lpVtbl -> SetListAlignment(This,Value)
#define ITextPara_GetPageBreakBefore(This,pValue)	\
    (This)->lpVtbl -> GetPageBreakBefore(This,pValue)
#define ITextPara_SetPageBreakBefore(This,Value)	\
    (This)->lpVtbl -> SetPageBreakBefore(This,Value)
#define ITextPara_AddTab(This,tbPos,tbAlign,tbLeader)	\
    (This)->lpVtbl -> AddTab(This,tbPos,tbAlign,tbLeader)
#define ITextPara_GetTab(This,iTab,ptbPos,ptbAlign,ptbLeader)	\
    (This)->lpVtbl -> GetTab(This,iTab,ptbPos,ptbAlign,ptbLeader)
#define ITextDocument2_Open(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Open(This,pVar,Flags,CodePage)
#define ITextDocument2_Save(This,pVar,Flags,CodePage)	\
    (This)->lpVtbl -> Save(This,pVar,Flags,CodePage)
#define ITextDocument2_GetPreferredFont(This,cp,CodePage,Option,curCodepage,curFontSize,pbstr,pPitchAndFamily,pNewFontSize)	\
    (This)->lpVtbl -> GetPreferredFont(This,cp,CodePage,Option,curCodepage,curFontSize,pbstr,pPitchAndFamily,pNewFontSize)

// windows\winstate\cobra\app\migwiz\migwnprc.cpp
#define BLOCKSIZE       (sizeof (DIRECTSEND_DATA))

// windows\winstate\cobra\utils\inc\poolmem.h
#define PmCreateString(h,x) ((LPTSTR) PmGetAlignedMemory((h),(x)*sizeof(TCHAR)))

// windows\winstate\cobra\utils\memdb\bintree.c
#define BINTREE_SIZE_MAIN    sizeof(UINT)
#define LISTELEM_SIZE_MAIN    (3*sizeof(UINT))
```

