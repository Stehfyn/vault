# String, Character, And Printable Fallback Helpers

[Macros index](<macros.md>)

## Curated Candidates

```c
// windows\core\ntuser\client\usercli.h
#define AWCOMPARECHAR(ped,pbyte,awchar) (ped->fAnsi ? (*(PUCHAR)(pbyte) == (UCHAR)(awchar)) : (*(LPWSTR)(pbyte) == (WCHAR)(awchar)))

// tools\x86\perl\lib\core\handy.h
#define BIT_DIGITS(N)   (((N)*146)/485 + 1)  /* log2(10) =~ 146/485 */
#define TYPE_DIGITS(T)  BIT_DIGITS(sizeof(T) * 8)
#define TYPE_CHARS(T)   (TYPE_DIGITS(T) + 2) /* sign, NUL */

// shell\inc\brfcasep.h
#define BOBriefcasePath(pbo)    ((LPTSTR)((LPBYTE)(pbo) + (pbo)->ibBriefPath))
#define BOFileList(pbo)         ((LPTSTR)((LPBYTE)(pbo) + (pbo)->ibFileList))
#define BOFileCount(pbo)        ((pbo)->cItems)
#define BOFileListSize(pbo)     ((pbo)->cbListSize)

// base\remoteboot\riprep\debug.h
#define BOOLTOSTRING( _fBool ) ( !!(_fBool) ? g_szTrue : g_szFalse )

// com\ole32\com\exts\dcomrem.cxx
#define BTOSTR(x)        ((x) ? "TRUE" : "FALSE")

// base\boot\lib\fatboot.c
#define CharOrSpace(C) ((C) < 0x20 ? 0x20: (C))

// base\win32\client\dllini.c
#define CharToNibble(x) ((x)>='0'&&(x)<='9' ? (x)-'0' : ((10+(x)-'A')&0x000f))

// admin\select\src\macros.hxx
#define CHECK_NULL(pwz)                         (pwz) ? (pwz) : L"NULL"

// enduser\netmeeting\h\stock.h
#define CHECK_STRING(psz)                 ((psz) ? (psz) : "(null)")

// com\rpc\midl\common\cmdutil.cxx
#define CopyIntFromBuffer( buffer, dest ) memcpy( &dest, (UNALIGNED char *) (buffer), sizeof( dest ) ), pBuffer += sizeof( dest )

#define CopyStrFromBuffer( buffer, dest )   { \
                                            char *sz = dest; \
                                            while ( *buffer ) *sz++ = *buffer++;\
                                            *sz++ = 0; \
                                            buffer++; \
                                            }

// base\fs\rdr2\csc\record.mgr\record.h
#define  CSCDbSubdirSecondChar(ULID_INODE) ((char)(((ULID_INODE)>=ULID_FIRST_USER_DIR)?('1'+((ULID_INODE)&0x7)):0))

// tools\x86\perl\lib\core\handy.h
#define Ctl(ch) ((ch) & 037)

// base\subsys\posix\programs\psxses\psxses.h
#define CTRL(c) ((c) & 0x1f)

// com\ole32\stg\utils\stgview\stgview.cxx
#define dfisprint(c) ((c) >= ' ' && (c) < 127)

// inetsrv\iis\svcs\infocomm\info\client\infostub.c
#define EMPTY_IF_NULL(str)      (str ? str : L"")

// shell\tools\starbuck\util.cpp
#define EMPTYSTR_FOR_NULL(str)      ((!str) ? TEXT("") : (str))

// inetsrv\iis\svcs\staxcore\hashmap\src\hashmacr.h
#define fCharInSet(ch, set) (NULL !=strchr(set, ch))
#define	fWhitespace(ch) fCharInSet(ch, szWSChars)
#define	fWhitespaceNull(ch) fCharInSet(ch, szWSNullChars)
#define	fWhitespaceNewLine(ch) fCharInSet(ch, szWSNLChars)
#define	fNewLine(ch) fCharInSet(ch, szNLChars)

// base\ntsetup\legacy\dll\comstf.h
#define FWhiteSpaceChp(chp)  ((BOOL)((chp) == ' '  || (chp) == '\t'))

// ds\security\services\ca\certlib\inf.cpp
#define INFSTRINGSELECT(pwsz)	(NULL != (pwsz)? (pwsz) : L"")

// windows\core\ntcon\server\stream.c
#define IS_CONTROL_CHAR(wch)  ((wch) < L' ')
#define IS_GLYPH_CHAR(wch)   (((wch) < L' ') || ((wch) == 0x007F))

// admin\netui\mprui\mpr\dlg1.cxx
#define IS_EMPTY_STRING(pch) ( !(pch) || !*(pch) )

// shell\ext\docprop\propvar.h
#define IS_PROPVAR_STRING( lppropvar )                        \
        ( ( (lppropvar)->vt & ~VT_VECTOR ) == VT_LPSTR      \
          ||                                                \
          ( (lppropvar)->vt & ~VT_VECTOR ) == VT_LPWSTR )   \

// sdktools\strings\strings.c
#define isascii(c)      ((c) >= ' ' && (c) <= '~')

// shell\comdlg32\fileopen.h
#ifdef UNICODE
  #define ISBACKSLASH(szPath, nOffset) (szPath[nOffset] == CHAR_BSLASH)
  #define ISBACKSLASH_P(szPath, pPos)  (*pPos == CHAR_BSLASH)
#else
  #define ISBACKSLASH(szPath, nOffset) (IsBackSlash(szPath, szPath + nOffset))
  #define ISBACKSLASH_P(szPath, pPos)  (IsBackSlash(szPath, pPos))
#endif

// drivers\tpg\hwx\common\inc\cp1252.h
#define isprint1252(_c)     (_ctype1252[(unsigned char)_c] & (_BLANK | _PUNCT | _UPPER | _LOWER | _DIGIT))
#define isgraph1252(_c)     (_ctype1252[(unsigned char)_c] & (_PUNCT | _UPPER | _LOWER | _DIGIT))
#define iscntrl1252(_c)     (_ctype1252[(unsigned char)_c] & _CONTROL)

// shell\browseui\trsite.h
#define ISSPACE(ch) (((ch) == 32) || ((unsigned)((ch) - 9)) <= 13 - 9)

// windows\core\ntgdi\fondrv\tt\sbit\sbit.cxx
#define ISSPACE(c) (((c) == ' ') || ((c) == '\t') || ((c) == '\r') || ((c) == '\n') || ((c) == '.'))

// base\efiutil\sdk\shell\shellenv\shelle.h
#define IsWhiteSpace(c)     (c == ' ' || c == '\t' || c == '\n' || c == '\r')
#define IsValidChar(c)      (c >= ' ')
#define IsDigit(c)          (c >= '0' && c <= '9')
#define IsAlpha(c)          ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' ))

// com\rpc\midl\inc\ndrtypes.h
#define LOW_NIBBLE(Byte)            (((unsigned char)Byte) & 0x0f)
#define HIGH_NIBBLE(Byte)           (((unsigned char)Byte) >> 4)

// shell\tools\ddespy\ddespy.h
#define MPRT(b)             (isprint(b) ? (b) : '.')

// shell\ext\webcheck\offline.h
#define NAME(pooe)  (LPTSTR)((LPBYTE)(pooe) + (DWORD_PTR)((pooe)->m_Name))
#define URL(pooe)   (LPTSTR)((LPBYTE)(pooe) + (DWORD_PTR)((pooe)->m_URL))
#define UNAME(pooe) (LPTSTR)((LPBYTE)(pooe) + (DWORD_PTR)((pooe)->username))
#define PASSWD(pooe) (LPTSTR)((LPBYTE)(pooe) + (DWORD_PTR)((pooe)->password))
#define STATUS(pooe) (LPTSTR)((LPBYTE)(pooe) + (DWORD_PTR)((pooe)->statusStr))

// shell\tools\starbuck\priv.h
#define NULL_FOR_EMPTYSTR(str)          (((str) && (str)[0]) ? str : NULL)

// ds\netapi\netlib\convwks.c
#define Nullstrlen(psz)  ((psz) ? STRLEN(psz)+1 : 0)

// base\win32\fusion\tools\fuslogvw\fuslogvw.c
#define PAD_DIGITS_FOR_STRING(x) (((x) > 9) ? TEXT("") : TEXT("0"))

// base\tools\kdexts2\pool.c
#define PP(x) isprint(((x)&0xff))?((x)&0xff):('.')

// ds\security\passport\include\pputils.h
#define PPF_CHAR(p)		((((LPCSTR )(p)) == NULL) ? ("<NULL>") : ((LPCSTR )(p)))
#define PPF_WCHAR(p)	((((LPCWSTR )(p)) == NULL) ? (L"<NULL>") : ((LPCWSTR )(p)))

// base\win32\fusion\utils\formatting.cpp
#define PRINTABLE(_ch) (isprint((_ch)) ? (_ch) : '.')

// multimedia\opengl\test\glut\src\capxfont.c
#define PRINTABLE(ch)  (isascii(ch) ? isprint(ch) : 0)

// net\irda\irsir\receive.c
#define PRINTCHAR(ch) (UCHAR)(ISPRINT(ch) ? (ch) : '.')

// admin\pchealth\core\include\mpc_main.h
#define SAFEBSTR( bstr )  (bstr ? bstr : L"")
#define SAFEASTR( str )   (str  ? str  : "")
#define SAFEWSTR( str )   (str  ? str  : L"")

// admin\admt\common\include\ustring.hpp
#define safecopy(trg,src) ((src) ? UStrCpy(trg,src,DIM(trg)) : trg[0] = 0)

// com\oleutest\stgbvt\ctolestg\common\stgutil\dumpcmd.cxx
#define SAFESTRING(a) a ? a : TEXT("")

// inetsrv\msmq\src\qm\strcore.cpp
#define SafeStrlen(lpsz) (((lpsz) == 0) ? 0 : lstrlen(lpsz))

// admin\pchealth\core\include\mpc_main.h
#define SANITIZEASTR( str ) if(str == NULL) str = ""
#define SANITIZEWSTR( str ) if(str == NULL) str = L""

// public\internal\ds\inc\martaexp.h
#define SIZE_PWSTR(wsz) (wsz == NULL ? 0 : (wcslen(wsz) + 1) * sizeof(WCHAR))

// base\ntsetup\textmode\kernel\spcab.h
#define SpBoolToStringA(f)          ((f) ? "true" : "false")
#define SpBooleanToStringA(x) ((x) ? "True" : "False")
#define SpBooleanToStringW(x) ((x) ? L"True" : L"False")

// base\ntsetup\textmode\kernel\spstring.h
#define SpIsSpace(c)    (((c) < CTSIZE) ? (_SpCharTypes[(c)] & _SP_SPACE)  : FALSE)

// ds\security\tools\kerbconf\kerbconf.h
#define STRDEF(s, d) (s && (s)[0] != '\0')?(s):(d)

// drivers\tpg\hwx\common\src\inkio.c
#define STRING_CHECKFORNULL(sz) ((sz) ? (sz) : "")

// ds\adsi\ldapc\pathmgmt.cxx
#define STRING_LENGTH(p) ( p ? wcslen(p) : 0)

// ds\security\protocols\kerberos\utest\ssp\ssptest.c
#define STRING_OR_NULL(_x_) (((_x_) != NULL) ? (_x_) : L"<null>")
#define STRING_OR_NULLA(_x_) (((_x_) != NULL) ? (_x_) : "<null>")

// shell\ext\dsui\inc\common.h
#define StringByteSizeA(sz)         ((sz) ? ((lstrlenA(sz)+1)*SIZEOF(CHAR)):0)
#define StringByteSizeW(sz)         ((sz) ? ((lstrlenW(sz)+1)*SIZEOF(WCHAR)):0)

#define StringByteCopyA(pDest, iOffset, sz)         \
        { CopyMemory(&(((LPBYTE)pDest)[iOffset]), sz, StringByteSizeA(sz)); }

#define StringByteCopyW(pDest, iOffset, sz)         \
        { CopyMemory(&(((LPBYTE)pDest)[iOffset]), sz, StringByteSizeW(sz)); }

// inetcore\wininet\utils\refcount\refcount.cxx
#define STRINGOP(func, param1, param2) 	(func(param1, param2, sizeof(param1)/sizeof(param1[0])))
#define STRINGOPL(func, param1, param2) 	(func(param1, param2, strlen(param1)))

// enduser\windows.com\lib\download\dlhttp.cpp
#define StringOrConstW(wsz, wszConst) (((wsz) != NULL) ? (wsz) : (wszConst))

// multimedia\directx\dplay\dplay\dplay\dplaypr.h
#define STRLEN(ptr) ((NULL==ptr) ? 0 : strlen(ptr) + 1)
#define WSTR_ANSILENGTH(psz) ( (psz == NULL) ? 0 : WideToAnsi(NULL,psz,0) )

// inetsrv\msmq\src\activex\lib\utilx.h
#define SYSALLOCSTRING(s) ((s == NULL) ? SysAllocString(L"") : SysAllocString(s))

// inetcore\outlookexpress\autodiscovery\test\adstress\main.cpp
#define SZ_NULL_TO_UNKNOWN(str)             ((str) ? (str) : L"<Unknown>")

// sdktools\apimon\include\apimon.h
#define T_PDWORD(off) (((off)<<16) + T_DWORDPTR)
#define T_PDLONG(off) (((off)<<16) + T_DLONGPTR)
#define T_PSTR(off)   (((off)<<16) + T_LPSTR)
#define T_PWSTR(off)  (((off)<<16) + T_LPWSTR)

// admin\admt\setdtct\common.hpp
#define  UnNull(ptr)  ( (ptr) ? (ptr) : (UCHAR *) "" )

// inetsrv\iis\iisrearc\ul\win9x\src\listener\httputil.c
#define WIDE_TO_CHAR(c) ((((c)&0xff00)!=0 || IS_HTTP_CTL(c))?'_':(CHAR)(c))

// inetcore\wininet\inc\macros.h
#define SKIPWS(s) while (*(s)==' ' || *(s)=='\t') (s)++;

#define MAKE_LOWER(c) (c | 0x20)

#define MAKE_UPPER(c) (c & 0xdf)

// inetcore\wininet\utils\refcount\refcount.cxx
#define SKIPSPACES(psz)	{for (++psz; *psz == ' ' && *psz != '\0'; ++psz); if (!*psz) psz=NULL;}

// net\layer2svc\zeroconf\cmdtool\wzcutil.h
#define HEX(c)  ((c)<='9'?(c)-'0':(c)<='F'?(c)-'A'+0xA:(c)-'a'+0xA)

// net\layer2svc\zeroconf\server\tracing.h
#define HEX2WCHAR(c)         ((c)<=9 ? L'0'+ (c) : L'A' + (c) - 10)

// inetsrv\iis\svcs\w3\filters\md5filt\authfilt.cxx
#define TOHEX(a) ((a)>=10 ? 'a'+(a)-10 : '0'+(a))

// inetsrv\query\apps\webhits\linkhits.cxx
#define WCHAR_COUNT(x) ( (sizeof(x)/sizeof(WCHAR))-1 )

// inetsrv\iis\svcs\w3\gateways\odbc\odbcreq.cxx
#define NEXT_TOKEN( pchToken )                 SkipWhite( SkipNonWhite( pchToken ) )

// shell\osshell\accesory\calc\unifunc.h
#define CharSizeOf(x)   (sizeof(x) / sizeof(*x))

#define ByteCountOf(x)  ((x) * sizeof(TCHAR))

// shell\osshell\accesory\ucharmap\charmap.h
#define BTOC(bytes)  ((bytes) / sizeof(TCHAR))

#define CTOB(cch)    ((cch) * sizeof(TCHAR))

// shell\tools\starbuck\priv.h
#define IS_VALID_FILE(str)        (!(('.' == str[0]) && (('\0' == str[1]) || (('.' == str[1]) && ('\0' == str[2])))))

// base\wmi\inc\wmiump.h
#define WmipBreakCountedString(CountedString, CountedStringLen) { \
    CountedStringLen = *CountedString++; \
    if (CountedString[(CountedStringLen-sizeof(WCHAR))/sizeof(WCHAR)] == UNICODE_NULL) \
    { \
        CountedStringLen -= sizeof(WCHAR); \
    } \
}

// sdktools\buggy\driver\mmtests.c
#define CONSTANT_UNICODE_STRING(s)   { sizeof( s ) - sizeof( WCHAR ), sizeof( s ), s }

// sdktools\checkrel\checkrel.c
#define CHECKSTRLEN(psz, cbmax)                                         \
        if (strlen(psz) > cbmax) {                                      \
            crerror("String overflow at line %u (%s)", __LINE__, psz);  \
            exit(4);                                                    \
        }
```

## Backlog

```c
// com\mobile\sens\conn\common\common.hxx
#define InitializeBstrVariant(_PVARIANT_, _BSTR_)                           \
                                                                            \
    VariantInit(_PVARIANT_);                                                \
                                                                            \
    (_PVARIANT_)->vt = VT_BSTR;                                             \
    (_PVARIANT_)->bstrVal = _BSTR_;

// com\mobile\sens\conn\senscfg\senscfg.cxx
#define GUID_STR_SIZE       sizeof("{12345678-1234-1234-1234-123456789012}")

// com\mobile\sens\conn\senssvc\event.cxx
#define FIRE_RAS_EVENT(_EVENT_NAME_)                                            \
{                                                                               \
                                                                                \
    PSENSEVENT_RAS pData = (PSENSEVENT_RAS)EventData;                           \
                                                                                \
    SensPrint(SENS_INFO, (SENS_STRING("\t|            RAS Event\n")));          \
    SensPrint(SENS_INFO, (SENS_STRING("\t|\n\t|                 Type  -  %s\n"), _EVENT_NAME_));     \
    SensPrint(SENS_INFO, (SENS_STRING("\t|    Connection Handle  -  0x%x\n"), pData->hConnection));  \
    break;                                                                      \
}

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\comm.h
#define CbFromCch(cch)              ((cch)*sizeof(TCHAR))
#define CCH_NUL                     (sizeof(TCHAR))
#define ZeroInit(pobj, type)        lmemset((CHAR *)pobj, 0, sizeof(type))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\comctrlp.h
#define BL_GETTEXT              (WM_USER+8)
#define BL_GETTEXTLEN           (WM_USER+9)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\shcompui.h
#define SCCA_CONTEXT_INIT(c)  { memset((LPVOID)c, 0, sizeof(SCCA_CONTEXT)); }

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\trayp.h
#define TM_WINDOWDESTROYED	(WM_USER+0x100)
#define TM_CONTEXTMENU          (WM_USER+0x102)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\winuserp.h
#define DC_CAPTION          (DC_ICON | DC_TEXT | DC_BUTTONS)

// com\ole2ui32\common.h
#define OLEUI_CCHCLSIDSTRING_SIZE   OLEUI_CCHCLSIDSTRING*sizeof(TCHAR)

// com\ole2ui32\winres.h
#define LB_ADDSTRING    (WM_USER+1)
#define CB_ADDSTRING    (WM_USER+3)

// com\ole32\actprops\actprops.hxx
#define SERVER_STAGE(stage) ((stage==SERVER_PROCESS_STAGE) || \
                             (stage==SERVER_CONTEXT_STAGE))

// com\ole32\com\dcomrem\context.cxx
#define GetPropListFromHashNode(n)      \
    CObjectContext::HashPropChainToContext((n))->GetPropertyList();

// com\ole32\com\dcomrem\marshal.hxx
#define ENTER_NA_IF_NECESSARY()                          \
    BOOL fEnteredNA_na = FALSE;                          \
    CObjectContext *pSavedCtx_na;                        \
    if (FTMObject() && !IsThreadInNTA())                 \
    {                                                    \
        pSavedCtx_na = EnterNTA(g_pNTAEmptyCtx);         \
        fEnteredNA_na = TRUE;                            \
    }
#define ENTER_NA_IF_NECESSARY_(x)                        \
    BOOL fEnteredNA_na = FALSE;                          \
    CObjectContext *pSavedCtx_na;                        \
    if ((x)->FTMObject() && !IsThreadInNTA())            \
    {                                                    \
        pSavedCtx_na = EnterNTA(g_pNTAEmptyCtx);         \
        fEnteredNA_na = TRUE;                            \
    }

// com\ole32\com\dcomrem\pstable.hxx
#define SERVER_CTXEVENTS                (CONTEXTEVENT_ENTER | \
                                         CONTEXTEVENT_ENTERWITHBUFFER | \
                                         CONTEXTEVENT_LEAVE | \
                                         CONTEXTEVENT_LEAVEFILLBUFFER | \
                                         CONTEXTEVENT_LEAVEEXCEPTION | \
                                         CONTEXTEVENT_LEAVEEXCEPTIONFILLBUFFER)
#define SERVER_ENTER_CTXEVENTS          (CONTEXTEVENT_ENTER | CONTEXTEVENT_ENTERWITHBUFFER)
#define SERVER_LEAVE_CTXEVENTS          (CONTEXTEVENT_LEAVE | CONTEXTEVENT_LEAVEFILLBUFFER)
#define SERVER_EXCEPTION_CTXEVENTS      (CONTEXTEVENT_LEAVEEXCEPTION | \
                                         CONTEXTEVENT_LEAVEEXCEPTIONFILLBUFFER)
#define SERVER_BUFFERCREATION_CTXEVENTS (CONTEXTEVENT_LEAVEFILLBUFFER | \
                                         CONTEXTEVENT_LEAVEEXCEPTIONFILLBUFFER)
#define CLIENT_CALL_CTXEVENTS           (CONTEXTEVENT_CALL | CONTEXTEVENT_CALLFILLBUFFER)

// com\ole32\com\dcomrem\service.hxx
#define SASIZE(size) (sizeof(ULONG) + (size) * sizeof(WCHAR))

// com\ole32\com\txf\callframe\common.h
#define PCHAR_LV_CAST   *(char **)&

// com\ole32\com\txf\inc\probe.h
#define ProbeAndReadChar(Address) \
    (((Address) >= (CHAR * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile CHAR * const)MM_USER_PROBE_ADDRESS) : (*(volatile CHAR *)(Address)))
#define ProbeAndReadUchar(Address) \
    (((Address) >= (UCHAR * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile UCHAR * const)MM_USER_PROBE_ADDRESS) : (*(volatile UCHAR *)(Address)))
#define ProbeAndReadUnicodeString(Source)  \
    (((Source) >= (UNICODE_STRING * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile UNICODE_STRING * const)MM_USER_PROBE_ADDRESS) : (*(volatile UNICODE_STRING *)(Source)))
#define ProbeForWriteChar(Address) {                                         \
    if ((Address) >= (CHAR * const)MM_USER_PROBE_ADDRESS) {                  \
        *(volatile CHAR * const)MM_USER_PROBE_ADDRESS = 0;                   \
    }                                                                        \
                                                                             \
    *(volatile CHAR *)(Address) = *(volatile CHAR *)(Address);               \
}
#define ProbeForWriteUchar(Address) {                                        \
    if ((Address) >= (UCHAR * const)MM_USER_PROBE_ADDRESS) {                 \
        *(volatile UCHAR * const)MM_USER_PROBE_ADDRESS = 0;                  \
    }                                                                        \
                                                                             \
    *(volatile UCHAR *)(Address) = *(volatile UCHAR *)(Address);             \
}
#define ProbeAndWriteChar(Address, Value) {                                  \
    if ((Address) >= (CHAR * const)MM_USER_PROBE_ADDRESS) {                  \
        *(volatile CHAR * const)MM_USER_PROBE_ADDRESS = 0;                   \
    }                                                                        \
                                                                             \
    *(Address) = (Value);                                                    \
}
#define ProbeAndWriteUchar(Address, Value) {                                 \
    if ((Address) >= (UCHAR * const)MM_USER_PROBE_ADDRESS) {                 \
        *(volatile UCHAR * const)MM_USER_PROBE_ADDRESS = 0;                  \
    }                                                                        \
                                                                             \
    *(Address) = (Value);                                                    \
}

// com\ole32\comcat\src\comcat.cpp
#define KEY_STRING_IMPL_CHARS (sizeof("Implemented Categories\\")-1)
#define KEY_STRING_REQ_CHARS (sizeof("Required Categories\\")-1)

// com\ole32\common\output.c
#define find_char_class(c)              \
        ((c) < ' ' || (c) > 'x' ?       \
            CH_OTHER                    \
        :                               \
            lookuptable[(c)-' '] & 0xF)

// com\ole32\dcomss\olescm\registry.hxx
#define APP_PATH_LEN    (sizeof( APP_PATH ) - sizeof( WCHAR )) / sizeof( WCHAR )

// com\ole32\ih\exports.hxx
#define API_CoLockObjectExternal                (API_NAMETABLE|(API_START+9))
#define API_CLSIDFromString                     (API_NAMETABLE|(API_START+15))
#define API_OleLoadFromStream                   (API_NAMETABLE|(API_START+67))
#define API_OleSaveToStream                     (API_NAMETABLE|(API_START+68))
#define API_OleDestroyMenuDescriptor            (API_NAMETABLE|(API_START+80))
#define API_OleConvertIStorageToOLESTREAM       (API_NAMETABLE|(API_START+92))
#define API_OleConvertOLESTREAMToIStorage       (API_NAMETABLE|(API_START+93))
#define API_OleConvertIStorageToOLESTREAMEx     (API_NAMETABLE|(API_START+94))
#define API_OleConvertOLESTREAMToIStorageEx     (API_NAMETABLE|(API_START+95))
#define API_CoMarshalInterThreadInterfaceInStream     (API_NAMETABLE|(API_START+110))
#define API_IIDFromString                       (API_NAMETABLE|(API_START+111))
#define API_StringFromCLSID                     (API_NAMETABLE|(API_START+112))
#define API_StringFromIID                       (API_NAMETABLE|(API_START+113))
#define API_StringFromGUID2                     (API_NAMETABLE|(API_START+114))
#define API_ReadStringStream                    (API_NAMETABLE|(API_START+132))
#define API_WriteStringStream                   (API_NAMETABLE|(API_START+133))
#define API_OpenOrCreateStream                  (API_NAMETABLE|(API_START+134))
#define API_CreateStreamOnHGlobal               (API_NAMETABLE|(API_START+140))
#define API_GetHGlobalFromStream                (API_NAMETABLE|(API_START+141))

// com\ole32\ih\ole2com.h
# define _xisdigit(c)  (IsCharAlphaNumericW(c) && !IsCharAlphaW(c))

// com\ole32\olecnv32\quickdrw.c
#define IsCharDigit(c) (IsCharAlphaNumeric(c) && !IsCharAlpha(c))

// com\ole32\oleprx32\proxy\transmit.h
#define PCHAR_LV_CAST   *(char __RPC_FAR * __RPC_FAR *)&

// com\ole32\olethunk\debnot\output.c
#define find_char_class(c)		\
	((c) < ' ' || (c) > 'x' ?	\
	    CH_OTHER			\
	:				\
	    lookuptable[(c)-' '] & 0xF)

// com\ole32\olethunk\ole16\inc\commdlg.h
#define CF_BOTH 		     (CF_SCREENFONTS | CF_PRINTERFONTS)

// com\ole32\olethunk\ole16\inc\olestd.h
#define OleStdQueryLinkSourceData(lpformatetc)   \
    (((lpformatetc)->tymed & TYMED_ISTREAM) ?    \
            NOERROR : ResultFromScode(DV_E_FORMATETC))
#define LSTRCPYN(lpdst, lpsrc, cch) \
(\
    (lpdst)[(cch)-1] = '\0', \
    (cch>1 ? lstrcpyn(lpdst, lpsrc, (cch)-1) : 0)\
)

// com\ole32\olethunk\ole16\inc\windows.h
#define EM_LIMITTEXT	        (WM_USER+21)
#define EM_LINEFROMCHAR         (WM_USER+25)
#define LB_ADDSTRING	       (WM_USER+1)
#define LB_INSERTSTRING        (WM_USER+2)
#define LB_GETTEXT	       (WM_USER+10)
#define LB_GETTEXTLEN	       (WM_USER+11)
#define LB_SELECTSTRING        (WM_USER+13)
#define LB_FINDSTRING	       (WM_USER+16)
#define LB_FINDSTRINGEXACT     (WM_USER+35)
#define CB_LIMITTEXT	         (WM_USER+1)
#define CB_ADDSTRING	         (WM_USER+3)
#define CB_GETLBTEXT	         (WM_USER+8)
#define CB_GETLBTEXTLEN	         (WM_USER+9)
#define CB_INSERTSTRING          (WM_USER+10)
#define CB_FINDSTRING	         (WM_USER+12)
#define CB_SELECTSTRING	         (WM_USER+13)
#define CB_SETEXTENDEDUI         (WM_USER+21)
#define CB_GETEXTENDEDUI         (WM_USER+22)
#define CB_FINDSTRINGEXACT       (WM_USER+24)

// com\ole32\olethunk\olethk32\thop.hxx
#define CWCSTRINGPREALLOC (CBSTRINGPREALLOC/sizeof(WCHAR))

// com\ole32\stg\common\output.c
#define find_char_class(c)		\
	((c) < ' ' || (c) > 'x' ?	\
	    CH_OTHER			\
	:				\
	    lookuptable[(c)-' '] & 0xF)

// com\ole32\stg\exp\expdf.hxx
#define COPY_ALL (COPY_STORAGES | COPY_STREAMS)

// com\ole32\stg\h\dfmsp.hxx
#define CBSTORAGENAME (CWCSTORAGENAME*sizeof(WCHAR))
#define DESTROY_HANDLE          (DESTROY_FROM_HANDLE | DESTROY_SELF)
#define DfAllocWC(cwc, ppwcs) (*ppwcs = (WCHAR *)\
         TaskMemAlloc((cwc)*sizeof(WCHAR)),\
          (*ppwcs != NULL) ? S_OK: STG_E_INSUFFICIENTMEMORY)

// com\ole32\stg\h\dir.hxx
#define STREAMLIKE(mse) \
    (((mse) & STGTY_REAL) == STGTY_STREAM || (mse) == STGTY_ROOT)

// com\ole32\stg\h\filest.hxx
#define TEMPFILE_PREFIX  TSTR("~DF")

// com\ole32\stg\h\props.hxx
#define VT_NOT_IN_VALUE(vt) \
    (((vt) & VT_VECTOR) || \
     (vt) == VT_BSTR || (vt) == VT_WBSTR || \
     (vt) == VT_LPSTR || (vt) == VT_LPWSTR || \
     (vt) == VT_BLOB_OBJECT || (vt) == VT_BLOB || \
     (vt) == VT_VARIANT || (vt) == VT_CF || (vt) == VT_UUID)
#define VT_NOT_IN_VALUE(vt) \
    (((vt) & VT_VECTOR) || \
     (vt) == VT_BSTR || \
     (vt) == VT_LPSTR || (vt) == VT_LPWSTR || \
     (vt) == VT_BLOB_OBJECT || (vt) == VT_BLOB || \
     (vt) == VT_VARIANT || (vt) == VT_CF || (vt) == VT_UUID)
#define BSTR_LLEN sizeof(UINT)
#define WBSTR_LLEN sizeof(UINT)
#define WBSTR_BLEN(b) (WBSTR_SLEN(b)+sizeof(WCHAR))
#define BSTR_LLEN sizeof(UINT)
#define BSTR_BLEN(b) (BSTR_SLEN(b)+sizeof(WCHAR))

// com\ole32\stg\props\propstm.cxx
#define PID_DOCPARTS	0x0000000d // docparts (VT_VECTOR | VT_LPSTR)

// com\ole32\stg\ref\expdf.hxx
#define COPY_ALL (COPY_STORAGES | COPY_STREAMS | COPY_PROPERTIES)

// com\ole32\stg\ref\h\dfmsp.hxx
#define DfAllocWC(cwc, ppwcs) (*ppwcs = new WCHAR[cwc], \
        (*ppwcs != NULL) ? S_OK: STG_E_INSUFFICIENTMEMORY)
#define CBSTORAGENAME (CWCSTORAGENAME*sizeof(WCHAR))
#define DESTROY_HANDLE          (DESTROY_FROM_HANDLE | DESTROY_SELF)

// com\ole32\stg\ref\h\dir.hxx
#define STREAMLIKE(mse) \
    (((mse) & STGTY_REAL) == STGTY_STREAM || (mse) == STGTY_ROOT)

// com\ole32\stg\ref\h\tchar.h
#define INIT_OLESTR(ocsName, pchContents) \
        _tbstowcs(ocsName, pchContents, sizeof(pchContents)+1)

// com\ole32\stg\ref\props\propstm.cxx
#define PID_DOCPARTS	0x0000000d // docparts (VT_VECTOR | VT_LPSTR)

// com\ole32\stg\utils\df2t\df2t.cxx
#define NS_INCL (STGTY_STORAGE | STGTY_STREAM)

// com\ole32\stg\utils\df2t\w4ctsupp.hxx
#define STGM_STREAM (STGM_READWRITE|STGM_SHARE_EXCLUSIVE)

// com\ole32\stg\wclib\wcsnicmp.c
#define wcUp(wc) (('a' <= (wchar_t) (wc) && (wchar_t) (wc) <= 'z') ? \
                  (wchar_t) (wc) + (wchar_t)('A' - 'a') : (wchar_t) (wc))

// com\oleutest\balls\oleprx32\proxy\transmit.h
#define PCHAR_LV_CAST   *(char __RPC_FAR * __RPC_FAR *)&

// com\oleutest\letest\gizmobar\gizmo.h
#define GIZMOTYPE_WINDOWS           (GIZMOTYPE_TEXT | GIZMOTYPE_EDIT | GIZMOTYPE_LISTBOX | GIZMOTYPE_COMBOBOX | GIZMOTYPE_BUTTONNORMAL)

// com\oleutest\letest\gizmobar\gizmobar.h
#define GBM_GIZMOTEXTGET                (WM_USER+15)
#define GBM_GIZMOTEXTSET                (WM_USER+16)
#define CBGBGETTEXT sizeof(GBGETTEXT);

// com\oleutest\letest\ole2ui\ole2ui.h
      #define iswspace(j) (j==TEXT(' ') || j==TEXT('\t') || j==TEXT('\n'))

// com\oleutest\letest\ole2ui\olestd.h
#define OleStdQueryLinkSourceData(lpformatetc)   \
    (((lpformatetc)->tymed & TYMED_ISTREAM) ?    \
            NOERROR : ResultFromScode(DV_E_FORMATETC))
#define LSTRCPYN(lpdst, lpsrc, cch) \
(\
    (lpdst)[(cch)-1] = '\0', \
    (cch>1 ? lstrcpyn(lpdst, lpsrc, (cch)-1) : 0)\
)

// com\oleutest\letest\ole2ui\wn_dos.h
#define CopySzFilePsffs(psffs,sz)	OemToAnsi((char HUGE *)&((psffs)->szFileName[0]),(char HUGE *)(sz))

// com\oleutest\stgbvt\ctolestg\common\testhelp\utest\cmdutest\cmdutest.cxx
#define TESTPASS(msg)    \
        printf("PASS: %s\n", msg)

// com\rpc\locator\nsserver\src\dsqry.cxx
#define MACEnumChildrenLOOP                                     \
    for (*phr = ADSIGetFirstRow(hDSObject, hSearchHandle);      \
    ((SUCCEEDED(*phr)) && ((*phr) != S_ADS_NOMORE_ROWS));       \
*phr = ADSIGetNextRow(hDSObject, hSearchHandle))

// com\rpc\midl\common\cmdutil.cxx
#define Stream( x ) ( stream->Write( &x, sizeof( x ) ) )
#define StreamIfNecessary( x )                                          \
                    {                                                   \
                        unsigned long zero = 0;                         \
                        x  ? x->StreamOut(stream)                       \
                           : stream->Write( &zero, sizeof( zero ) );    \
                    }

// com\rpc\midl\inc\fldattr.hxx
#define FA_CONFORMANT_STRING    (FA_STRING | FA_CONFORMANT)

// com\rpc\ndr20\asyncndr.h
#define AsyncAlloca( msg, size )           \
    NdrpAlloca( &msg->ProcContext.AllocateContext, size )

// com\rpc\ndr20\asyncu.h
#define AsyncAlloca( msg, size )           \
    NdrpAlloca( &msg->ProcContext.AllocateContext, size )

// com\rpc\ndr20\picklep.hxx
#define PCHAR_CAST      (char *)
#define PPCHAR_CAST     (char * *)
#define PCHAR_LV_CAST   *(char * *)&
#define GET_NEXT_ARG( pArg, ArgL)   PCHAR_LV_CAST pArg += sizeof(void *);

// com\rpc\ndrmem\linklist.hxx
#define ToItem(TYPE, arg) ((TYPE##Item *) ((char *)arg-sizeof(LinkList)))

// drivers\input\kbdclass\kbdclass.h
#define SET_TRUSTED_FILE_FOR_READ(x) ((x)->FsContext2 = &DriverEntry)

// drivers\input\mouclass\mouclass.h
#define SET_TRUSTED_FILE_FOR_READ(x) ((x)->FsContext2 = &DriverEntry)

// drivers\input\pnpi8042\i8042prt.h
#define SET_RECORD_STATE(devExt, state)                                 \
    {                                                                   \
        if (IsrStateHistory) devExt->RecordHistoryState |= (state);     \
        RECORD_ISR_STATE_TRANSITION(devExt, state);                     \
    }

// drivers\input\pnpi8042\moudep.c
#define _TRANSITION_DOWN(previous, current, button) \
           ((!(previous & button)) && (current & button))
#define _TRANSITION_UP(previous, current, button) \
           ((previous & button) && (!(current & button)))

// drivers\ksfilter\inc\portclsp.h
#define IRPSTREAM_END (~ULONGLONG(0))

// drivers\ksfilter\ks\ksp.h
#define KspExtFromIrp(Irp)\
    reinterpret_cast<PKSPX_EXT>(\
        (*reinterpret_cast<PKSIOBJECT_HEADER*>(\
        IoGetCurrentIrpStackLocation(Irp)->\
        FileObject->\
        FsContext))->Object)
#define KspExtFromFileObject(FileObject)\
    reinterpret_cast<PKSPX_EXT>(\
        (*reinterpret_cast<PKSIOBJECT_HEADER*>(\
        FileObject->\
        FsContext))->Object)
#define KspExtFromCreateIrp(Irp)\
    reinterpret_cast<PKSPX_EXT>(\
        (*reinterpret_cast<PKSIOBJECT_HEADER*>(\
        IoGetCurrentIrpStackLocation(Irp)->\
        FileObject->\
        RelatedFileObject->\
        FsContext))->Object)

// drivers\ksfilter\ks\shsplit.cpp
#define FRAME_HEADER_IRP_STORAGE(Irp)\
    *((PKSPPARENTFRAME_HEADER*)&Irp->Tail.Overlay.DriverContext[0])

// drivers\net\ms\e100bex\mp.h
#define MPMemCmp(Destn, Source, Length)   \
    RtlCompareMemory((PUCHAR)(Destn), (PUCHAR)(Source), (ULONG)(Length))

// drivers\net\ms\e100bex\offload.c
#define PHXSUM(s,d,p,l) (UINT)( (UINT)*(USHORT *)&(s) + \
                        (UINT)*(USHORT *)((char *)&(s) + sizeof(USHORT)) + \
                        (UINT)*(USHORT *)&(d) + \
                        (UINT)*(USHORT *)((char *)&(d) + sizeof(USHORT)) + \
                        (UINT)((USHORT)net_short((p))) + \
                        (UINT)((USHORT)net_short((USHORT)(l))) )

// drivers\net\ms\ne2000\ne2000hw.h
#define CardCopyMulticastRegs(Adapter) \
    NdisMSynchronizeWithInterrupt(&(Adapter)->Interrupt, \
                SyncCardCopyMulticastRegs, (PVOID)(Adapter))

// drivers\net\ms\ne2000\ne2000sw.h
#define LSB(Value) ((UCHAR)(((ULONG)Value) & 0xff))

// drivers\sac\driver\event.c
#define RESPONSE_BUFFER_SIZE (80 + sizeof(HEADLESS_RSP_GET_LINE) - sizeof(UCHAR))

// drivers\sac\driver\util.c
#define         MACHINEINFORMATIONBUFFER_SIZE (512 * sizeof(WCHAR))

// drivers\serial\mps\comtrol\rocket\driver\initc.c
#define SEND_CMD_STRING(portex,string) \
  ModemWrite(portex,(char *)string,sizeof(string) - 1)
#define SEND_CMD_DELAY_STRING(portex,string) \
  ModemWriteDelay(portex,(char *)string,sizeof(string) - 1)
#define READ_RESPONSE_STRINGS(portex,s0,s1,retries) \
  ModemReadChoice(portex,(char *)s0,sizeof(s0) - 1,(char *)s1,sizeof(s1) - 1,retries)
#define READ_RESPONSE_STRING(portex,string,retries) \
  ModemRead(portex,(char *)string,sizeof(string) - 1,retries)

// drivers\serial\mps\comtrol\rocket\driver\port.h
#define pEnNullStrip(p) \
  { (p)->control_settings |= SC_NULL_STRIP; }
#define pDisNullStrip(p) \
  { (p)->control_settings &= ~SC_NULL_STRIP; }

// drivers\serial\mps\comtrol\rocket\driver\ssci.h
#define sClrTxXOFF(CHP) \
{ \
   sOutB((PUCHAR)(CHP)->Cmd,(unsigned char)(TXOVERIDE | (CHP)->ChanNum)); \
   sOutB((PUCHAR)(CHP)->Cmd,(unsigned char)(CHP)->ChanNum); \
}
#define sPCIControllerEOI(CTLP) sOutW((CTLP)->PCI1IO, \
                                      (USHORT)((CTLP)->PCI1 | PCI_STROBE))
#define sControllerEOI(CTLP) sOutB((PUCHAR)(CTLP)->MReg2IO,(unsigned char)((CTLP)->MReg2 | INT_STROB))
#define sGetRPlusModemRI(CHP) (unsigned char)(sInB((BIOA_T)(CHP)->ChanStat+8) & (DSR_ACT))
#define sResetUART(CHP) \
{ \
   sOutB((CHP)->Cmd,(UCHAR)(RESETUART | (CHP)->ChanNum)); \
   sOutB((CHP)->Cmd,(unsigned char)(CHP)->ChanNum); \
   sInB((CHP)->IntChan); \
   sInB((CHP)->IntChan); \
}

// drivers\serial\ser101\serial.h
#define WRITE_IO_DELAY(Counter)                                         \
do                                                                      \
{                                                                       \
    ULONG i;                                                            \
                                                                        \
    for (i = 0; (i <= Counter) && (Counter >= 1); i++) {                \
        WRITE_PORT_UCHAR((PUCHAR)IO_DELAY_REGISTER, IO_DELAY_DATA);     \
    }                                                                   \
} while (0)
#define RESET_71051(ModeSet)                                                              \
do                                                                                        \
{                                                                                         \
    WRITE_PORT_UCHAR((PUCHAR)Extension->CommandSetRegisterAddress, (UCHAR)0);             \
    WRITE_IO_DELAY(1);                                                                    \
    WRITE_PORT_UCHAR((PUCHAR)Extension->CommandSetRegisterAddress, (UCHAR)0);             \
    WRITE_IO_DELAY(1);                                                                    \
    WRITE_PORT_UCHAR((PUCHAR)Extension->CommandSetRegisterAddress, (UCHAR)0);             \
    WRITE_IO_DELAY(1);                                                                    \
    WRITE_PORT_UCHAR((PUCHAR)Extension->CommandSetRegisterAddress, COMMAND_ERROR_RESET);  \
    WRITE_IO_DELAY(2);                                                                    \
    WRITE_PORT_UCHAR(                                                                     \
        (PUCHAR)Extension->ModeSetRegisterAddress,                                        \
        (ModeSet)                                                                         \
        );                                                                                \
    WRITE_IO_DELAY(1);                                                                    \
    WRITE_PORT_UCHAR(                                                                     \
        (PUCHAR)Extension->CommandSetRegisterAddress,                                     \
        (UCHAR)Extension->CommandSet71051                                                 \
        );                                                                                \
    WRITE_IO_DELAY(1);                                                                    \
} while (0)

// drivers\serial\ser71051\serial.h
#define WRITE_IO_DELAY(Counter)                   \
do                                                \
{                                                 \
    ULONG i;                                      \
    for (i = 0; i < Counter; i++) {               \
        WRITE_PORT_UCHAR(                         \
            (PUCHAR)IO_DELAY_REGISTER,            \
            IO_DELAY_DATA                         \
            );                                    \
    }                                             \
} while (0)
#define RESET_71051(ModeSet)                                           \
do                                                                     \
{                                                                      \
    WRITE_PORT_UCHAR((PUCHAR)COMMAND_SET, (UCHAR)0);                   \
    WRITE_IO_DELAY(1);                                                \
    WRITE_PORT_UCHAR((PUCHAR)COMMAND_SET, (UCHAR)0);                   \
    WRITE_IO_DELAY(1);                                                \
    WRITE_PORT_UCHAR((PUCHAR)COMMAND_SET, (UCHAR)0);                   \
    WRITE_IO_DELAY(1);                                                \
    WRITE_PORT_UCHAR((PUCHAR)COMMAND_SET, COMMAND_ERROR_RESET);        \
    WRITE_IO_DELAY(2);                                                \
    WRITE_PORT_UCHAR(                                                  \
        (PUCHAR)MODE_SET,                                              \
        (ModeSet)                                                      \
        );                                                             \
    WRITE_IO_DELAY(1);                                                \
    WRITE_PORT_UCHAR(                                                  \
        (PUCHAR)COMMAND_SET,                                           \
        (UCHAR)Extension->CommandSet71051                              \
        );                                                             \
    WRITE_IO_DELAY(1);                                                \
} while (0)

// drivers\smartcrd\gcr410\gioctl09.h
#define UNICODE_SIZE(x) ((x) * sizeof(WCHAR))

// drivers\smartcrd\lit220\l220scr.h
#define UNICODE_SIZE(x) ((x) * sizeof(WCHAR))

// drivers\smartcrd\scmstcs\serialnt.h
#define SR_NOTIFICATION_EVENT				( SERIAL_EV_RXCHAR | SERIAL_EV_DSR )

// drivers\storage\class\filters\storagefilter\filter.h
#define FILTER_DEVICE_PROPOGATE_CHARACTERISTICS (FILE_REMOVABLE_MEDIA |  \
                                                 FILE_READ_ONLY_DEVICE | \
                                                 FILE_FLOPPY_DISKETTE    \
                                                 )

// drivers\storage\diskperf\diskperf.c
#define FILTER_DEVICE_PROPOGATE_CHARACTERISTICS (FILE_REMOVABLE_MEDIA |  \
                                                 FILE_READ_ONLY_DEVICE | \
                                                 FILE_FLOPPY_DISKETTE    \
                                                 )

// drivers\storage\fdc\fdc\fdc_data.h
#define READ_CONTROLLER( Address )                         \
    READ_PORT_UCHAR( ( PUCHAR )Address )
#define WRITE_CONTROLLER( Address, Value )                 \
    WRITE_PORT_UCHAR( ( PUCHAR )Address, ( UCHAR )Value )

// drivers\storage\fdc\fdc\q117_dat.h
#define READ_CONTROLLER( Address )                         \
    READ_PORT_UCHAR( ( PUCHAR )Address )
#define WRITE_CONTROLLER( Address, Value )                 \
    WRITE_PORT_UCHAR( ( PUCHAR )Address, ( UCHAR )Value )

// drivers\storage\fdc\inc\q117_dat.h
#define READ_CONTROLLER( Address )                         \
    READ_PORT_UCHAR( ( PUCHAR )Address )
#define WRITE_CONTROLLER( Address, Value )                 \
    WRITE_PORT_UCHAR( ( PUCHAR )Address, ( UCHAR )Value )

// drivers\storage\fdc\mode3fdc\desk2fdc\fdc_data.h
#define READ_CONTROLLER( Address )                         \
    READ_PORT_UCHAR( ( PUCHAR )Address )
#define WRITE_CONTROLLER( Address, Value )                 \
    WRITE_PORT_UCHAR( ( PUCHAR )Address, ( UCHAR )Value )

// drivers\storage\fdc\mode3fdc\desk2fdc\q117_dat.h
#define READ_CONTROLLER( Address )                         \
    READ_PORT_UCHAR( ( PUCHAR )Address )
#define WRITE_CONTROLLER( Address, Value )                 \
    WRITE_PORT_UCHAR( ( PUCHAR )Address, ( UCHAR )Value )

// drivers\storage\fpfilter\fpfilter.c
#define FILTER_DEVICE_PROPOGATE_CHARACTERISTICS (FILE_REMOVABLE_MEDIA |  \
                                                 FILE_READ_ONLY_DEVICE | \
                                                 FILE_FLOPPY_DISKETTE    \
                                                 )

// drivers\storage\ide\inc\idep.h
#define CURRENT_INTERRUPT_SENCE (PUCHAR)0x430
#define SELECT_IDE_PORT         (PUCHAR)0x432
#define SYSTEM_PORT_A           (PUCHAR)0x31
#define EnhancedIdeSupport() \
    (READ_PORT_UCHAR(CURRENT_INTERRUPT_SENCE)&0x40)?TRUE:FALSE

// drivers\storage\ide\pciidex\ctlrfdo.h
#define ControllerEnableInterrupt(FdoExtension) \
	if (FdoExtension->NativeIdeInterface.InterruptControl) { \
		(FdoExtension->NativeIdeInterface).InterruptControl((FdoExtension->NativeIdeInterface).Context,\
															TRUE);\
	}
#define ControllerDisableInterrupt(FdoExtension) \
	if (FdoExtension->NativeIdeInterface.InterruptControl) { \
		(FdoExtension->NativeIdeInterface).InterruptControl((FdoExtension->NativeIdeInterface).Context,\
															FALSE);\
	}

// drivers\storage\kdext\atapi\pch.h
#define DECLARE_API(extension) CPPMOD HRESULT CALLBACK extension(PDEBUG_CLIENT Client, PCSTR args)

// drivers\storage\kdext\scsikd\pch.h
#define DECLARE_API(extension)     \
CPPMOD HRESULT CALLBACK extension(PDEBUG_CLIENT Client, PCSTR args)

// drivers\storage\kdext\stor\pch.h
#define DECLARE_API(extension)     \
CPPMOD HRESULT CALLBACK extension(PDEBUG_CLIENT Client, PCSTR args)

// drivers\storage\mpath\control\pdowmi.h
    #define SCSI_ADDR_PortNumber_SIZE sizeof(UCHAR)
    #define SCSI_ADDR_ScsiPathId_SIZE sizeof(UCHAR)
    #define SCSI_ADDR_TargetId_SIZE sizeof(UCHAR)
    #define SCSI_ADDR_Lun_SIZE sizeof(UCHAR)

// drivers\storage\mpath\control\wmi.h
    #define MPIO_ADAPTER_INFORMATION_BusNumber_SIZE sizeof(UCHAR)
    #define MPIO_ADAPTER_INFORMATION_DeviceNumber_SIZE sizeof(UCHAR)
    #define MPIO_ADAPTER_INFORMATION_FunctionNumber_SIZE sizeof(UCHAR)

// drivers\storage\port\raid\ext\pch.h
#define DECLARE_API(extension)     \
CPPMOD HRESULT CALLBACK extension(PDEBUG_CLIENT Client, PCSTR args)

// drivers\storage\rsm2\service\dll\guidhash.c
#define HASH_FUNC(lpGuid) (UINT)(UCHAR)(*(PUCHAR)(lpGuid) + *((PUCHAR)(lpGuid)+sizeof(NTMS_GUID)-1))

// drivers\storage\scsiport\port.h
#define GetScatterGatherList(DmaAdapter, DeviceObject, Mdl, CurrentVa,      \
                             Length, ExecutionRoutine, Context,             \
                             WriteToDevice)                                 \
            ((DmaAdapter)->DmaOperations->GetScatterGatherList)(            \
                (DmaAdapter),                                               \
                (DeviceObject),                                             \
                (Mdl),                                                      \
                (CurrentVa),                                                \
                (Length),                                                   \
                (ExecutionRoutine),                                         \
                (Context),                                                  \
                (WriteToDevice))
#define AllocateAdapterChannel(DmaAdapter, DeviceObject,                    \
                               NumberOfMapRegisters, ExecutionRoutine,      \
                               Context)                                     \
            ((DmaAdapter)->DmaOperations->AllocateAdapterChannel)(          \
                (DmaAdapter),                                               \
                (DeviceObject),                                             \
                (NumberOfMapRegisters),                                     \
                (ExecutionRoutine),                                         \
                (Context))

// drivers\storage\tffsport\amdmtd.c
    #define bBuffer ((const UCHAR FAR1 * &) buffer)

// drivers\storage\tffsport\flsystem.h
#define tffsReadBuf(d,s,c)  READ_REGISTER_BUFFER_UCHAR((PUCHAR)s,d,c)
#define tffsWriteBuf(d,s,c) WRITE_REGISTER_BUFFER_UCHAR((PUCHAR)d,s,c)

// drivers\storage\tffsport\i28f008.c
    #define bBuffer ((const UCHAR FAR1 * &) buffer)

// drivers\storage\volsnap\vss\inc\vs_vol.hxx
#define STRING_SIZE(S) (sizeof(S) - sizeof((S)[0]))

// drivers\storage\volsnap\vss\modules\wrtrshim\src\common.h
#define DeclareStaticUnicodeString(_StringName, _StringValue)								\
				static UNICODE_STRING (_StringName) = {sizeof (_StringValue) - sizeof (UNICODE_NULL),	\
								       sizeof (_StringValue),				\
								       _StringValue}

// drivers\storage\volsnap\vss\server\inc\vs_vol.hxx
#define STRING_SIZE(S) (sizeof(S) - sizeof((S)[0]))

// drivers\storage\volsnap\vss\server\modules\wrtrshim\src\common.h
#define DeclareStaticUnicodeString(_StringName, _StringValue)								\
				static UNICODE_STRING (_StringName) = {sizeof (_StringValue) - sizeof (UNICODE_NULL),	\
								       sizeof (_StringValue),				\
								       _StringValue}

// drivers\storage\volsnap\vss\server\vssui\utils.h
#define TWO_WHACKS(p)   ((p) && lstrlen(p) > 1 && *(p) == _T('\\') && *((p)+1) == _T('\\'))

// drivers\tpg\hwx\bear\inc\ams_mg.h
#define  RECM_ALL        (RECM_TEXT|RECM_FORMULA)
#define   LMOD_BORDER_GENERAL (LMOD_BORDER_TEXT|LMOD_BORDER_NUMBER)

// drivers\tpg\hwx\bear\inc\calcmacr.h
#define  ASSIGN_HEIGHT(elem,h)  (elem)->attr = (REF(elem)->attr&(~_umd_)) | (((_UCHAR)(h))&_umd_) /*Should be ";"*/
#define  ASSIGN_CIRCLE_DIR(elem,FB)  (elem)->attr = (REF(elem)->attr&(~_fb_)) | (((_UCHAR)(FB))&_fb_) /*Should be ";"*/

// drivers\tpg\hwx\bear\inc\hwr_file.h
#define HWR_TEXT_EXCL      (HWR_TEXT_EXIST_OPEN|HWR_TEXT_NOTEXIST_ERROR)
#define HWR_TEXT_OPEN      (HWR_TEXT_EXIST_OPEN|HWR_TEXT_NOTEXIST_CREATE)
#define HWR_TEXT_TRUNC     (HWR_TEXT_EXIST_CREATE|HWR_TEXT_NOTEXIST_CREATE)
#define HWR_TEXT_APPEND    (HWR_TEXT_EXIST_APPEND|HWR_TEXT_NOTEXIST_CREATE)

// drivers\tpg\hwx\common\inc\cp1252.h
#define isalpha1252(_c)     (_ctype1252[(unsigned char)_c] & (_UPPER | _LOWER))
#define isupper1252(_c)     (_ctype1252[(unsigned char)_c] & _UPPER)
#define islower1252(_c)     (_ctype1252[(unsigned char)_c] & _LOWER)
#define isdigit1252(_c)     (_ctype1252[(unsigned char)_c] & _DIGIT)
#define isxdigit1252(_c)    (_ctype1252[(unsigned char)_c] & _HEX)
#define isspace1252(_c)     (_ctype1252[(unsigned char)_c] & _SPACE)
#define ispunct1252(_c)     (_ctype1252[(unsigned char)_c] & _PUNCT)
#define isalnum1252(_c)     (_ctype1252[(unsigned char)_c] & (_UPPER | _LOWER | _DIGIT))

// drivers\tpg\hwx\common\inc\frame.h
#define IsVisibleFRAME(frame)		(IsVisibleSTROKE(&(frame)->info))

// drivers\tpg\hwx\commonu\inc\frame.h
#define IsVisibleFRAME(frame)		(IsVisibleSTROKE(&(frame)->info))

// drivers\tpg\hwx\commonu\inc\locale.h
#define	LocRunDense2Unicode(pLocRunInfo,dch)	\
	((pLocRunInfo)->pDense2Unicode[dch])
#define	LocTrainUnicode2Dense(pLocTrainInfo,wch)	\
	((pLocTrainInfo)->pUnicode2Dense[wch])

// drivers\tpg\hwx\commonu\inc\recogp.h
#define SyvCharacterToSymbol(c) ((LONG)(unsigned char)(c) | 0x00010000)

// drivers\tpg\hwx\inferno\src\deu\charmap.h
#define IsSupportedChar(ch) ((BeginChar2Out(ch) < 0xFF) || IsVirtualChar(ch))

// drivers\tpg\hwx\inferno\src\fra\charmap.h
#define IsSupportedChar(ch) ((BeginChar2Out(ch) < 0xFF) || IsVirtualChar(ch))

// drivers\tpg\hwx\tsunami\src\snot\sinfo.h
#define CharsetSINFO(xrc)               (&((xrc)->cs))

// drivers\tpg\hwx\tsunami\src\snot\unicode.c
#define ALC_BOTH (ALC_ALPHA | ALC_NUMERIC)

// drivers\tpg\hwx\tsunami\src\usa\sinfo.h
#define CharsetSINFO(xrc)               (&((xrc)->cs))

// drivers\video\ms\3dlabs\perm2\disp\d3dcntxt.h
#define SET_CURRENT_D3D_CONTEXT(ctxt)        \
    if(ctxt != ppdev->permediaInfo->pCurrentCtxt)   \
    {                                       \
        P2SwitchContext(ppdev,  ctxt);   \
    }

// drivers\video\ms\3dlabs\perm2\disp\d3ddelta.h
#define RENDER_TEXTURE_ENABLE(a) a |= __RENDER_TEXTURE_ENABLE;
#define RENDER_TEXTURE_DISABLE(a) a &= ~__RENDER_TEXTURE_ENABLE;

// drivers\video\ms\3dlabs\perm2\disp\d3dtext.h
#define TEXTURE_HASH_OF(i)  ((i) & 0xff)
#define WRAP(par, wrapit) if(wrapit) {                      \
    float elp;                                              \
    float erp;                                              \
    float emp;                                              \
    elp = (float)fabs(par##1 - par##0);                     \
    erp = (float)fabs(par##2 - par##1);                     \
    emp = (float)fabs(par##0 - par##2);                     \
    if( (elp > (float)0.5) && (erp > (float)0.5) )          \
    {                                                       \
        if (par##1 < par##2) { par##1 += 1.0; }             \
        else { par##2 += 1.0; par##0 += 1.0; }              \
        FLUSH_DUE_TO_WRAP(par);                             \
    }                                                       \
    else if( (erp > (float)0.5) && (emp > (float)0.5) )     \
    {                                                       \
        if (par##2 < par##0) { par##2 += 1.0; }             \
        else { par##0 += 1.0; par##1 += 1.0; }              \
        FLUSH_DUE_TO_WRAP(par);                             \
    }                                                       \
    else if( (emp > (float)0.5) && (elp > (float)0.5) )     \
    {                                                       \
        if(par##0 < par##1) { par##0 += 1.0; }              \
        else { par##1 += 1.0; par##2 += 1.0; }              \
        FLUSH_DUE_TO_WRAP(par);                             \
    }                                                       \
    else                                                    \
    {                                                       \
        DONT_FLUSH_DUE_TO_WRAP(par);                        \
    }                                                       \
} else {                                                    \
    DONT_FLUSH_DUE_TO_WRAP(par);                            \
}
#define WRAP_LINE(par, wrapit) if(wrapit) {                 \
    float elp;                                              \
    elp = (float)fabs(par##1 - par##0);                     \
    if(elp > (float)0.5)                                    \
    {                                                       \
        if (par##1 < par##0) { par##1 += 1.0; }             \
        else { par##0 += 1.0;}                              \
        FLUSH_DUE_TO_WRAP(par);                             \
    }                                                       \
    else                                                    \
    {                                                       \
        DONT_FLUSH_DUE_TO_WRAP(par);                        \
    }                                                       \
} else {                                                    \
    DONT_FLUSH_DUE_TO_WRAP(par);                            \
}

// drivers\video\ms\3dlabs\perm2\disp\directx.h
#define DDCONTEXT  if (ppdev->permediaInfo->pCurrentCtxt != (ppdev->pDDContext)) \
                   {     P2SwitchContext(ppdev, ppdev->pDDContext); }

// drivers\video\ms\3dlabs\perm2\disp\gdi.h
#define __FX_8x8REPEAT_TEXTUREREADMODE      ( __PERMEDIA_ENABLE               \
                                            | __FX_TEXREADMODE_TWRAP_REPEAT   \
                                            | __FX_TEXREADMODE_SWRAP_REPEAT   \
                                            | __FX_TEXREADMODE_8HIGH          \
                                            | __FX_TEXREADMODE_8WIDE)

// drivers\video\ms\3dlabs\perm2\disp\textout.c
#define GLYPH_HASH_FUNC(x)  ((x) & (GLYPH_HASH_SIZE - 1))

// drivers\video\ms\3dlabs\perm3\disp\dx\d3ddp2p3.c
#define P3_RND_PARAMS               \
            pContext,               \
            lpIns->wPrimitiveCount, \
            lpPrim,                 \
            lpVertices,             \
            pdp2d->dwVertexLength, \
            &bParseError

// drivers\video\ms\3dlabs\perm3\disp\dx\d3dprim.c
#define INIT_VERTEX_INDICES(pContext, vtx_a, vtx_b)   \
    vtx_a = 0;                                        \
    vtx_b = 0 ^ 1;                                    \
    pContext->dwProvokingVertex = 1;
#define CYCLE_VERTEX_INDICES(pContext, vtx_a, vtx_b)  \
        vtx_a ^= vtx_b;                               \
        vtx_b ^= CONST_c;                             \
        pContext->dwProvokingVertex = vtx_b;          \
        vtx_b ^= vtx_a;

// drivers\video\ms\3dlabs\perm3\disp\dx\d3dstrct.h
#define HT_HASH_OF(i)    ((i) & 0xFFF)

// drivers\video\ms\3dlabs\perm3\disp\dx\d3dtxt.c
#define TSSTATE(stageno,argno)        \
                        ( pContext->TextureStageState[stageno].m_dwVal[argno] )

// drivers\video\ms\3dlabs\perm3\disp\dx\directx.h
#define DXCONTEXT_IMMEDIATE(pThisDisplay)                           \
    vGlintSwitchContext(pThisDisplay->ppdev,                        \
                        pThisDisplay->ppdev->DDContextID);
#define DXCONTEXT_IMMEDIATE(pThisDisplay)             \
    ChangeContext(pThisDisplay,                       \
                  pThisDisplay->pGLInfo,              \
                  CONTEXT_DIRECTX_HANDLE);
#define SET_REGISTRY_STRING_FROM_ULONG(a, b)                             \
    bGlintSetRegistryValueString(pThisDisplay->ppdev, L##a, b)
#define GET_REGISTRY_STRING(a, b)                                        \
    bGlintQueryRegistryValueString(pThisDisplay->ppdev, L##a, b, c)

// drivers\video\ms\3dlabs\perm3\disp\inc\glintfx.h
#define __FX_8x8REPEAT_TEXTUREREADMODE      ( __PERMEDIA_ENABLE                      \
                                            | __FX_TEXREADMODE_TWRAP_REPEAT       \
                                            | __FX_TEXREADMODE_SWRAP_REPEAT       \
                                            | __FX_TEXREADMODE_8HIGH              \
                                            | __FX_TEXREADMODE_8WIDE)
#define __FX_2048x2048REPEAT_TEXTUREREADMODE ( __PERMEDIA_ENABLE                     \
                                            | __FX_TEXREADMODE_TWRAP_REPEAT       \
                                            | __FX_TEXREADMODE_SWRAP_REPEAT       \
                                            | __FX_TEXREADMODE_2048HIGH           \
                                            | __FX_TEXREADMODE_2048WIDE)
#define __FX_4BPPDOWNLOAD_TEXTUREREADMODE   ( __PERMEDIA_ENABLE                      \
                                            | __FX_TEXREADMODE_2048HIGH           \
                                            | __FX_TEXREADMODE_2048WIDE)

// drivers\video\ms\ati\disp\textout.c
#define expandto3(a,b) \
{   \
    if ((a) & 0x80) *(b) |= 0x07; \
    if ((a) & 0x40) *(b) |= 0x38; \
    if ((a) & 0x20) {*(b) |= 0xC0; *((b)+1) |= 0x01;} \
    if ((a) & 0x10) *((b)+1) |= 0x0E; \
    if ((a) & 0x08) *((b)+1) |= 0x70; \
    if ((a) & 0x04) {*((b)+1) |= 0x80; *((b)+2) |= 0x03;} \
    if ((a) & 0x02) *((b)+2) |= 0x1C; \
    if ((a) & 0x01) *((b)+2) |= 0xE0; \
}

// drivers\video\ms\fsvga\fsconins\oc.h
#define SBUF_SIZE        (S_SIZE * sizeof(TCHAR))

// drivers\video\ms\laguna\disp\include\laguna.h
    #define SYNC_W_3D(ppdev)                                                                                    \
    {                                                                                                           \
        if (ppdev->NumMCDContexts > 0)                                                                          \
        {                                                                                                       \
            ENSURE_3D_IDLE(ppdev);                                                                              \
        }                                                                                                       \
    }

// drivers\video\ms\laguna\disp\include\memmgr.h
#define MCD_TEXTURE_ALLOCATE    (MCD_TEXTURE8_ALLOCATE|MCD_TEXTURE16_ALLOCATE|MCD_TEXTURE32_ALLOCATE)

// drivers\video\ms\port\ddc.c
#define DDC_ADDRESS_PD_READ         (UCHAR)0xA3     // As above for display with P&D connector

// drivers\video\ms\s3\disp\hw.h
#define IO_SHORT_STROKE(ppdev, x)           \
{                                           \
    CP_EIEIO();                             \
    OUT_FIFO_W(ppdev->ioShort_stroke, (x)); \
    CP_EIEIO();                             \
}

// drivers\video\ms\vga\disp\16bpp\driver.h
#define POW2(stride) (!((stride) & ((stride)-1)))   // TRUE if stride is power of 2
#define BROKEN_RASTERS(stride,cy) ((!(POW2(stride))) && ((stride*cy) > 0x10000))

// drivers\video\ms\vga\disp\4bpp\driver.h
#define POW2(stride) (!((stride) & ((stride)-1)))   // TRUE if stride is power of 2
#define BROKEN_RASTERS(stride,cy) ((!(POW2(stride))) && ((stride*cy) > 0x10000))

// drivers\video\ms\vga\disp\4bpp\textout.c
#define SO_RTOL          (SO_LTOR | SO_REVERSED)
#define SO_BTOT          (SO_TTOB | SO_REVERSED)

// drivers\video\ms\vga\disp\8bpp\driver.h
#define POW2(stride) (!((stride) & ((stride)-1)))   // TRUE if stride is power of 2
#define BROKEN_RASTERS(stride,cy) ((!(POW2(stride))) && ((stride*cy) > 0x10000))

// drivers\video\ms\weitek\disp\textout.c
#define GLYPH_HASH_FUNC(x)  ((x) & (GLYPH_HASH_SIZE - 1))

// drivers\wdm\audio\backpln\portcls\main\irpstrm.cpp
#define CAST_LVALUE(type,lvalue) (*((type*)&(lvalue)))
#define FLINK_IRP_STORAGE(Irp)              \
    CAST_LVALUE(PLIST_ENTRY,(Irp)->Tail.Overlay.ListEntry.Flink)
#define BLINK_IRP_STORAGE(Irp)              \
    CAST_LVALUE(PLIST_ENTRY,(Irp)->Tail.Overlay.ListEntry.Blink)
#define FIRST_STREAM_HEADER_IRP_STORAGE(Irp)       \
    CAST_LVALUE(PKSSTREAM_HEADER,(Irp)->AssociatedIrp.SystemBuffer)
#define IRP_CONTEXT_IRP_STORAGE(Irp)       \
    CAST_LVALUE(PIRP_CONTEXT,IoGetCurrentIrpStackLocation(Irp)->    \
                Parameters.Others.Argument4)

// drivers\wdm\audio\backpln\portcls\ports\wavecyc\private.h
#define KSSTATE_TO_STRING(x) \
    (   ((x) == KSSTATE_RUN) ? "KSSTATE_RUN" : \
        ((x) == KSSTATE_PAUSE) ? "KSSTATE_PAUSE" : \
        ((x) == KSSTATE_ACQUIRE) ? "KSSTATE_ACQUIRE" : \
        ((x) == KSSTATE_STOP) ? "KSSTATE_STOP" : "UNDEFINED" )

// drivers\wdm\audio\legacy\wdmaud.sys\mixer.c
#define KsAudioPropertyToString( Property )                 \
    Property == KSPROPERTY_AUDIO_VOLUMELEVEL ? "Volume"   : \
    Property == KSPROPERTY_AUDIO_MUTE        ? "Mute"     : \
    Property == KSPROPERTY_AUDIO_BASS        ? "Bass"     : \
    Property == KSPROPERTY_AUDIO_TREBLE      ? "Treble"   : \
    Property == KSPROPERTY_AUDIO_AGC         ? "AGC"      : \
    Property == KSPROPERTY_AUDIO_LOUDNESS    ? "Loudness" : \
    Property == KSPROPERTY_AUDIO_PEAKMETER   ? "Peakmeter" : \
        "Unknown"

// drivers\wdm\audio\legacy\wdmaud.sys\mixer.h
#define ControlTypeToString( dwType )                                \
    (dwType) == MIXERCONTROL_CONTROLTYPE_BOOLEAN    ? "Boolean"        : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_ONOFF      ? "On Off"         : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_MUTE       ? "Mute"           : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_MONO       ? "Mono"           : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_LOUDNESS   ? "Loudness"       : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_STEREOENH  ? "Stereo Enhance" : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_VOLUME     ? "Volume"         : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_BASS       ? "Bass"           : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_TREBLE     ? "Treble"         : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_BASS_BOOST ? "Bass Boost"     : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_PEAKMETER  ? "Peakmeter"      : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_MUX        ? "Mux"            : \
    (dwType) == MIXERCONTROL_CONTROLTYPE_MIXER      ? "Mixer"          : \
        "Unknown ControlType"
#define TargetTypeToString( dwType )                            \
    (dwType) == MIXERLINE_TARGETTYPE_AUX       ? "Aux"       :  \
    (dwType) == MIXERLINE_TARGETTYPE_MIDIIN    ? "MidiIn"    :  \
    (dwType) == MIXERLINE_TARGETTYPE_MIDIOUT   ? "MidiOut"   :  \
    (dwType) == MIXERLINE_TARGETTYPE_UNDEFINED ? "Undefined" :  \
    (dwType) == MIXERLINE_TARGETTYPE_WAVEIN    ? "WaveIn"    :  \
    (dwType) == MIXERLINE_TARGETTYPE_WAVEOUT   ? "WaveOut"   :  \
        "Unknown TargetType"

// drivers\wdm\bda\samples\casamp\driver\inc\bdatypes.h
#define BDA_STRING_CONST(x)   {sizeof(L##x)-2, sizeof(L##x), L##x}

// drivers\wdm\bda\slip\recv.h
#define IP_STREAM_INDEX(x)    (x & 0x7f)

// drivers\wdm\input\client\hclient\hidtest.h
    #define HIDTest_AllocateDeviceString(nChars) ALLOC(((nChars)+1) * sizeof(TCHAR))

// drivers\wdm\input\client\hidtest\hidtest.c
#define HIDTest_CompareStrings(s1, s1len, s2, s2len) (((s1len) == (s2len)) && \
                                                      (0 == memcmp((s1), (s2), (s1len))))

// drivers\wdm\input\client\hidtest\inc\hidtest.h
    #define HIDTest_AllocateDeviceString(nChars) ALLOC(((nChars)+1) * sizeof(TCHAR))

// drivers\wdm\input\legacy\hidgame\hidjoy.c
#define ARE_WE_RELATED(_x_, _y_)                                \
    (                                                           \
        (_x_)->GameContext     == (_y_)->GameContext      &&    \
        (_x_)->WriteAccessor   == (_y_)->WriteAccessor    &&    \
        (_x_)->ReadAccessor    == (_y_)->ReadAccessor           \
    )

// drivers\wdm\input\legacy\mshgame\gckernel.sys\filter.cpp
#define SKIP_TO_NEXT_COMMAND_DIRECTORY(pCommandDirectory)\
	(reinterpret_cast<PCOMMAND_DIRECTORY>\
		(reinterpret_cast<PUCHAR>(pCommandDirectory) +\
		pCommandDirectory->ulEntireSize)\
	)

// drivers\wdm\input\legacy\mshgame\gckernel.sys\swvbenum.h
#define GCK_SWVB_GetVirtualDeviceExtension(__pDeviceObject__) \
		(\
			(PVOID)\
			(\
				(PCHAR)\
				( (__pDeviceObject__)->DeviceExtension )\
				+ sizeof(SWVB_PDO_EXT)\
			)\
		)

// drivers\wdm\input\samples\monitor\map.h
#define cbCtch(ctch) ((ctch) * sizeof(TCHAR))

// drivers\wdm\input\tools\dt\dt.c
#define KEYBORAD_MESSAGE (Message.message == WM_KEYDOWN || Message.message == WM_CHAR || Message.message == WM_KEYUP)
#define LISTSTYLE (LBS_WANTKEYBOARDINPUT | LBS_HASSTRINGS | LBS_NOTIFY | WS_BORDER | WS_VSCROLL | WS_VISIBLE | WS_CHILD )

// drivers\wdm\usb\driver\hub.pnp\usbhub.h
#define STRCPY( pDst, pSrc )\
    {\
    int nLength, i;\
    STRLEN( nLength, pSrc );\
    nLength /= sizeof( *pSrc );\
    for ( i=0; i < nLength; i++ ) pDst[i] = pSrc[i];\
    pDst[i] = 0;\
    }
#define APPEND( pString, ch )\
    {\
    int nLength;\
    STRLEN( nLength, pString );\
    nLength /= sizeof( *pString );\
    pString[nLength] = ch;\
    pString[nLength+1] = 0;\
    }

// drivers\wdm\usb\driver\wceusbsh\read.c
#define START_ANOTHER_USBREAD( _PDevExt ) \
   ( (IRP_STATE_COMPLETE == _PDevExt->UsbReadState) && \
     (0 == _PDevExt->UsbReadBuffChars) && \
     CanAcceptIoRequests(_PDevExt->DeviceObject, FALSE, TRUE) \
   )

// drivers\wdm\usb\hcd\kdexts\precomp.h
#define DECLARE_API(extension)     \
CPPMOD HRESULT CALLBACK extension(PDEBUG_CLIENT Client, PCSTR args)

// drivers\wdm\usb\hcd\uhcd\uhcd.h
#define SOF_MODIFY_REG(deviceExtension)   \
    ((PUCHAR) (deviceExtension->DeviceRegisters[0] + 0x0C))

// ds\adsi\ldap\cschema.cxx
#define BEGIN_FILTER TEXT("(& (lDAPDisplayName=")

// ds\adsi\ldap\ldapinc\disptmpl.h
#define LDAP_SYN_CASEIGNORESTR	( 1 | LDAP_SYN_TYPE_TEXT )
#define LDAP_SYN_MULTILINESTR	( 2 | LDAP_SYN_TYPE_TEXT )
#define LDAP_SYN_DN		( 3 | LDAP_SYN_TYPE_TEXT )
#define LDAP_SYN_DATE		( 11 | LDAP_SYN_TYPE_TEXT )
#define LDAP_SYN_LABELEDURL	( 12 | LDAP_SYN_TYPE_TEXT )
#define LDAP_SYN_RFC822ADDR	( 17 | LDAP_SYN_TYPE_TEXT )

// ds\adsi\nocairo\output.c
#define find_char_class(c)              \
        ((c) < ' ' || (c) > 'x' ?       \
            CH_OTHER                    \
        :                               \
            lookuptable[(c)-' '] & 0xF)

// ds\adsi\noole\misc.cxx
#define CASE_SCODE(sc)  \
        case sc: lpstr = (LPWSTR)L#sc; break;

// ds\adsi\router\acledit.cxx
#define FirstAce(Acl) ((PVOID)((PUCHAR)(Acl) + sizeof(ACL)))

// ds\adsi\router\crowprov.hxx
#define GET_CLASS_VALUE(a,n)  \
    (_wcsicmp(a[n-1].CaseIgnoreString,L"Top") == 0 ? \
    a[0].CaseIgnoreString : a[n-1].CaseIgnoreString)
#define GET_CLASS_LEN(a,n)  \
    (_wcsicmp(a[n-1].CaseIgnoreString,L"Top") == 0 ? \
    (wcslen(a[0].CaseIgnoreString) + 1) * sizeof(WCHAR) : \
    (wcslen(a[n-1].CaseIgnoreString) + 1) * sizeof(WCHAR))

// ds\dns\dnslib\print.c
#define INDENT_STRING( level )  (IndentString + (sizeof(IndentString) - 1 - (level)))

// ds\dns\dnslib\straddr.c
#define SIZE_IP4REV  (sizeof(".in-addr.arpa")-1)
#define SIZE_IP6REV  (sizeof(".ip6.int")-1)

// ds\dns\server\client\dconvert.c
#define STRING_UTF8_BUF_SIZE( string, fUnicode ) \
        Dns_GetBufferLengthForStringCopy( \
            (string),   \
            0,          \
            ((fUnicode) ? DnsCharSetUnicode : DnsCharSetUtf8), \
            DnsCharSetUtf8 )
#define WRITE_STRING_TO_RPC_BUF(buf, psz, len, funicode) \
        Dns_StringCopy(     \
            (buf),          \
            NULL,           \
            (psz),          \
            (len),          \
            ((funicode) ? DnsCharSetUnicode : DnsCharSetUtf8), \
            DnsCharSetUtf8 )
#define NAME_UTF8_BUF_SIZE( string, fUnicode ) \
        Dns_GetBufferLengthForStringCopy( \
            (string),   \
            0,          \
            ((fUnicode) ? DnsCharSetUnicode : DnsCharSetUtf8), \
            DnsCharSetUtf8 )
#define WRITE_NAME_TO_RPC_BUF(buf, psz, len, funicode) \
        Dns_StringCopy(     \
            (buf),          \
            NULL,           \
            (psz),          \
            (len),          \
            ((funicode) ? DnsCharSetUnicode : DnsCharSetUtf8), \
            DnsCharSetUtf8 )

// ds\dns\server\server\msginfo.h
#define RESET_MESSAGE_TO_ORIGINAL_QUERY( pMsg ) \
    {                                           \
        (pMsg)->pCurrent            = (PCHAR)((pMsg)->pQuestion + 1);   \
        (pMsg)->Head.AnswerCount    = 0;        \
        (pMsg)->Compression.cCount  = 0;        \
    }

// ds\dns\server\server\nameutil.h
#define B_READ_STOP             (B_READ_TOKEN_STOP | B_READ_STRING_STOP)
#define B_PRINT_QUOTED          (B_PRINT_TOKEN_QUOTED | B_PRINT_STRING_QUOTED)
#define B_PRINT_OCTAL           (B_PRINT_TOKEN_OCTAL | B_PRINT_STRING_OCTAL)
#define FC_SPECIAL      (B_READ_TOKEN_STOP | B_PRINT_TOKEN_QUOTED)
#define FC_DOT          (B_DOT | B_PRINT_TOKEN_QUOTED)
#define FC_QUOTE        (B_READ_STRING_STOP | B_PRINT_QUOTED)
#define FC_SLASH        (B_SLASH | B_PRINT_QUOTED)
#define FC_NEWLINE      (B_READ_STOP | B_PRINT_OCTAL)
#define FC_OCTAL        (B_CHAR_NON_RFC | B_PRINT_OCTAL)
#define FC_NULL         (B_DOT | B_CHAR_NON_RFC | B_PRINT_OCTAL)

// ds\dns\server\server\record.h
#define REF_RAW_NAME( pnode )   ( (PCHAR)&(pnode))

// ds\dns\server\server\registry.c
#define DNS_REGISTRY_CLASS_SIZE     sizeof(DNS_REGISTRY_CLASS)
#define DNS_REGKEY_ZONES() \
    ( g_ZonesRegistrySource == DNS_REGSOURCE_SW ? \
        DNS_REGKEY_ZONES_SW : DNS_REGKEY_ZONES_CCS )

// ds\dns\server\server\registry.h
#define DNS_REG_EXPAND_WSZ      (0xf0000000 | REG_EXPAND_SZ)
#define DNS_REG_WSZ             (0xf0000000 | REG_SZ)
#define DNS_REG_UTF8            (0xff000000 | REG_SZ)
#define DNS_REG_TYPE_UNICODE( type )        ( (type) & 0xf0000000 )
#define REG_TYPE_FROM_DNS_REGTYPE( type )   ( (type) & 0x0000ffff )

// ds\dns\server\wmi\source\dconvert.c
#define STRING_UTF8_BUF_SIZE( string, fUnicode ) \
        Dns_GetBufferLengthForStringCopy( \
            (string),   \
            0,          \
            ((fUnicode) ? DnsCharSetUnicode : DnsCharSetUtf8), \
            DnsCharSetUtf8 )
#define WRITE_STRING_TO_RPC_BUF(buf, psz, len, funicode) \
        Dns_StringCopy(     \
            (buf),          \
            NULL,           \
            (psz),          \
            (len),          \
            ((funicode) ? DnsCharSetUnicode : DnsCharSetUtf8), \
            DnsCharSetUtf8 )
#define NAME_UTF8_BUF_SIZE( string, fUnicode ) \
        Dns_GetBufferLengthForStringCopy( \
            (string),   \
            0,          \
            ((fUnicode) ? DnsCharSetUnicode : DnsCharSetUtf8), \
            DnsCharSetUtf8 )
#define WRITE_NAME_TO_RPC_BUF(buf, psz, len, funicode) \
        Dns_StringCopy(     \
            (buf),          \
            NULL,           \
            (psz),          \
            (len),          \
            ((funicode) ? DnsCharSetUnicode : DnsCharSetUtf8), \
            DnsCharSetUtf8 )

// ds\ds\src\inc\_entryid.h
#define EPHEMERAL   (UCHAR)(~(  MAPI_NOTRECIP      \
                              | MAPI_THISSESSION   \
                              | MAPI_NOW           \
                              | MAPI_NOTRESERVED))

// ds\ds\src\inc\dsevent.h
#define szInsertMTX(x) szInsertSz((x) ? (PCHAR)(x)->mtx_name : "[]")

// ds\ds\src\inc\ntdsa.h
#define DSNameSizeFromLen(x) \
    (sizeof(GUID) + 3*sizeof(ULONG) + sizeof(WCHAR) + sizeof(NT4SID) \
     + (x)*sizeof(WCHAR))

// ds\ds\src\kcc\sim\util.h
#define KCCSIM_STRMEMSIZE(x) \
    (sizeof (CHAR) * (strlen (x) + 1))
#define KCCSIM_WCSMEMSIZE(x) \
    (sizeof (WCHAR) * (wcslen (x) + 1))

// ds\ds\src\ldap\client\dnfilter\util.h
#define	SOCKADDR_IN_PRINTF(SocketAddress) \
	ntohl ((SocketAddress) -> sin_addr.s_addr), \
	ntohs ((SocketAddress) -> sin_port)
#define	ANSI_STRING_INIT(Text) { sizeof (Text) - sizeof (CHAR), 0, (Text) } // account for NUL

// ds\ds\src\ldap\netmon_parser\ldap.h
#define DEFINE_LDAP_STRING(x)  {(sizeof(x)-1),(PUCHAR)x}

// ds\ds\src\ntdsa\dblayer\dbconstr.c
#define NAME_TAG_SIZE             (sizeof(NAME_TAG) - sizeof(WCHAR))
#define SYNTAX_TAG_SIZE           (sizeof(SYNTAX_TAG) - sizeof(WCHAR))
#define SINGLE_TAG_SIZE           (sizeof(SINGLE_TAG) - sizeof(WCHAR))
#define NO_MOD_TAG_SIZE           (sizeof(NO_MOD_TAG) - sizeof(WCHAR))
#define MAY_TAG_SIZE              (sizeof(MAY_TAG) - sizeof(WCHAR))
#define ABSTRACT_CLASS_TAG_SIZE   (sizeof(ABSTRACT_CLASS_TAG) - sizeof(WCHAR))
#define AUXILIARY_CLASS_TAG_SIZE  (sizeof(AUXILIARY_CLASS_TAG) - sizeof(WCHAR))
#define MUST_TAG_SIZE             (sizeof(MUST_TAG) - sizeof(WCHAR))
#define SUP_TAG_SIZE              (sizeof(SUP_TAG) - sizeof(WCHAR))
#define AUX_TAG_SIZE              (sizeof(AUX_TAG) - sizeof(WCHAR))
#define INDEXED_TAG_SIZE          (sizeof(INDEXED_TAG) - sizeof(WCHAR))
#define SYSTEM_ONLY_TAG_SIZE      (sizeof(SYSTEM_ONLY_TAG) - sizeof(WCHAR))
#define CLASS_GUID_TAG_SIZE       (sizeof(CLASS_GUID_TAG) - sizeof(WCHAR))
#define PROP_GUID_TAG_SIZE        (sizeof(PROP_GUID_TAG) - sizeof(WCHAR))
#define PROP_SET_GUID_TAG_SIZE    (sizeof(PROP_SET_GUID_TAG) - sizeof(WCHAR))
#define DEFINE_WCHAR_STRING(x) {(sizeof(x)-sizeof(WCHAR)),(WCHAR *)x}

// ds\ds\src\ntdsa\include\drautil.h
#define TransportAddrFromMtxAddrEx(pmtx) \
    UnicodeStringFromString8(CP_UTF8, (pmtx)->mtx_name, -1)

// ds\ds\src\ntdsa\include\mdlocal.h
#define IsDNSepChar(x) (((x) == L',') || ((x) == L';'))

// ds\ds\src\ntdsa\ldap\const.hxx
#define DEFINE_LDAP_STRING(x)  {(sizeof(x)-1),(PUCHAR)x}
#define EQUAL_LDAP_STRINGS(x,y)                                \
           (((x).length == (y).length) &&                      \
            (_memicmp((x).value,(y).value,(x).length) == 0))

// ds\ds\src\ntdsa\src\mdctrl.c
#define STRING_LITERAL_LEN(str) sizeof(str)-1

// ds\ds\src\ntdsa\src\mdname.c
#define CB_GC_PREAMBLE (sizeof(GC_PREAMBLE) - sizeof(WCHAR))
#define CC_GC_PREAMBLE ((CB_GC_PREAMBLE)/sizeof(WCHAR))
#define CB_GC_PORTS    (sizeof(GC_PORT) - sizeof(WCHAR))
#define CC_GC_PORTS    ((CB_GC_PORTS)/sizeof(WCHAR))

// ds\ds\src\ntdsa\src\mdupdate.c
#define CCHVAL (PAVAL.valLen /sizeof(WCHAR))
#define CCHVAL (PAVAL.valLen /sizeof(WCHAR))
#define CCHVAL (PAVAL.valLen /sizeof(WCHAR))
#define CCHVAL (PAVAL.valLen /sizeof(WCHAR))

// ds\ds\src\ntdsa\src\parsedn.c
#define WCCNT(x) ((sizeof(x) - sizeof(WCHAR))/sizeof(WCHAR))

// ds\ds\src\ntdsa\src\refcount.c
#define DSNAME_SAME_STRING_NAME(a,b)                    \
    ((NULL != (a)) && (NULL != (b))                     \
     && !lstrcmpW((a)->StringName, (b)->StringName))
#define DSNAME_IDENTICAL(a,b) \
    (DSNAME_SAME_STRING_NAME(a,b) && DSNAME_SAME_GUID_SID(a,b))

// ds\ds\src\ntdsa\src\servinfo.c
#define CCHVAL (PAVAL.valLen /sizeof(WCHAR))

// ds\ds\src\ntdsapi\dsrsa.c
    #define DsRSAHeapDestroy(heap) \
	(HeapDestroy (heap) == FALSE ? GetLastError () : NO_ERROR)

// ds\ds\src\sam\server\samsrvp.h
#define SampIsContextFromExtendedSidDomain(x) \
      SampDefinedDomains[(x)->DomainIndex].IsExtendedSidDomain

// ds\ds\src\sam\server\upgrade.c
#define RTLP_RXACT_KEY_NAME_SIZE (sizeof(RTLP_RXACT_KEY_NAME) - sizeof(WCHAR))

// ds\ds\src\util\ldifds\ldifldap\lexeru.h
#define STR_ADDCHAR(c)                                                         \
            if ((cCurrent+2) >= cSize) {                                       \
                pszString = MemRealloc_E(pszString,(INC+cSize)*sizeof(WCHAR));   \
                memset(pszString + cSize,                    \
                       0,                                                      \
                       INC*sizeof(WCHAR));                             \
                cSize+=INC;                                                    \
            }                                                                  \
            pszString[cCurrent++] = c;

// ds\ds\src\util\ntdsutil\samclean.cxx
#define CalculateBufferSize( c )                                    \
        (sizeof(GENERIC_TABLE_ELEMENT) + c.Length - sizeof(WCHAR) + \
         sizeof(L'\0'))

// ds\ese98\eximport\exifs.h
#define WIN32_PREFIX_LEN            (sizeof(IOCTL_WIN32_FILENAME)-sizeof(WCHAR))

// ds\netapi\dosprint\dosprtw.c
#define STR_CONV_SIZE(psz)      ( (strlen(psz)+1) * sizeof(WCHAR) )

// ds\netapi\netcmd\common\help.c
#define     CNTRL           (text[0] == DOT || text[0] == COLON || text[0] == POUND|| text[0] == DOLLAR)
#define     FCNTRL          (text[0] == DOT || text[0] == COLON)
#define     HEADER          (text[0] == PERCENT || text[0] == DOT || text[0] == BANG)

// ds\netapi\netcmd\common\mutil.c
#define DESIRED_HAND_STATE  (CHAR_DEV | FULL_SUPPORT | STDOUT_DEVICE)

// ds\netapi\netcmd\inc\netascii.h
#define	AMPERSAND	TEXT('&')
#define	TILDA	TEXT('~')
#define	PIPE	TEXT('|')

// ds\netapi\netcmd\netcmd\config.c
#define YES_OR_NO(x) \
    (x ? valmsg_list[CVMN_YES].msg_text : valmsg_list[CVMN_NO].msg_text)

// ds\netapi\netcmd\netcmd\session.c
#define YES_OR_NO(x) \
    ((TCHAR FAR *) (x ? SessMsgList[MSG_YES].msg_text \
             : SessMsgList[MSG_NO].msg_text) )

// ds\netapi\netlib\joinutl.c
#define clearncb(x)     memset((char *)x,'\0',sizeof(NCB))

// ds\netapi\svcdlls\browser\client\brtsenum.c
#define DO(name)                     \
    if (Type & SV_TYPE_ ## name) {   \
        (void) STRCAT(str, TEXT(#name));  \
        (void) STRCAT(str, TEXT("  "));    \
        Type &= ~(SV_TYPE_ ## name); \
    }

// ds\netapi\svcdlls\lls\server\llssrv.c
#define FIND_DNSNAME_SEPARATOR(pwsz) {   \
    while (*pwsz && *pwsz != TEXT('.')) { \
        pwsz++;                          \
    }                                   \
}
#define CWSTR_SIZE(x)       (sizeof(x) - (sizeof(WCHAR) * 2))
#define DWSTR_SIZE(x)       ((wcslen(x) + 1) * sizeof(WCHAR))

// ds\netapi\svcdlls\msgsvc\server\msrv.h
#define clearncb(x)     memset((char *)x,'\0',sizeof(NCB))
#define clearncbf(x)    memsetf((char far *)x,'\0',sizeof(NCB))
#define MSGFILENAMLEN   PATHLEN*sizeof(TCHAR)

// ds\netapi\svcdlls\srvsvc\server\srvsvcp.h
#define SIZE_WSTR( Str )  \
    ( ( Str ) == NULL ? 0 : ((wcslen( Str ) + 1) * sizeof(WCHAR)) )

// ds\netapi\svcdlls\upssvc\apcsmart\utils.h
#define        FD_ZERO(p)      memset((char *)(p), 0, sizeof (*(p)))

// ds\netapi\svcdlls\wkssvc\client\wstsenum.c
#define DO(name)                     \
    if (Type & SV_TYPE_ ## name) {   \
        (void) STRCAT(str, # name);  \
        (void) STRCAT(str, L"  ");    \
        Type &= ~(SV_TYPE_ ## name); \
    }

// ds\netapi\svcimgs\ntrepl\inc\config.h
#define DEFAULT_FILE_FILTER_LIST   TEXT("*.tmp, *.bak, ~*")

// ds\netapi\svcimgs\ntrepl\inc\frs.h
#define VV_PRINT(_Severity_, _Header_, _VV_)                                \
        DPRINT1(_Severity_, "++ VV_PRINT :%08x\n", _VV_);                   \
        VVPrint(_Severity_, _Header_, _VV_, FALSE)
#define FRS_CO_COMM_PROGRESS(_sev, _cmd, _sn, _partner, _text)               \
DPRINT7(_sev, ":: CoG %08x, CxtG %08x, Sn %5d, vsn %08x %08x, FN: %-15ws, [%s], %ws\n", \
    (_cmd)->ChangeOrderGuid.Data1,                                           \
    (_cmd)->CxtionGuid.Data1,                                                \
    (_sn),                                                                   \
    PRINTQUAD((_cmd)->FrsVsn),                                               \
    (_cmd)->FileName,                                                        \
    (_text),                                                                 \
    (_partner));

// ds\netapi\svcimgs\ntrepl\inc\frserror.h
#define GET_EXCEPTION_CODE(_x_)                                              \
{                                                                            \
    (_x_) = GetExceptionCode();                                              \
    DPRINT1_WS(0, "++ ERROR - EXCEPTION (%08x) :", (_x_),(_x_));             \
}
#define DbsTranslateJetError(_jerr_, _print_)                                \
    (((_jerr_) == JET_errSuccess) ? FrsErrorSuccess :                        \
                                    DbsTranslateJetError0(_jerr_, _print_))

// ds\netapi\svcimgs\ntrepl\inc\info.h
#define ITPRINTGNAME(_GName, _Format)                                          \
{                                                                              \
    if ((_GName) && (_GName)->Guid && (_GName)->Name) {                        \
        GuidToStr(_GName->Guid, Guid);                                         \
        if (Info) {                                                            \
            IPRINT3(Info, _Format, TabW, (_GName)->Name, Guid);                \
        } else {                                                               \
            DebPrintNoLock(Severity, TRUE, _Format, Debsub, uLineNo, TabW, (_GName)->Name, Guid); \
        }                                                                      \
    }                                                                          \
}

// ds\netapi\svcimgs\ntrepl\inc\jet.h
#define PROPERTY_SPECIFIER_NAME(PS,I)    \
    (&PROPERTY_SPECIFIER_COUNTED_STRING( PS, I )->Text[0])

// ds\netapi\svcimgs\ntrepl\inc\replutil.h
#define FrsIsUnicodeCharacterWild(C) (                               \
    (((C) == UNICODE_STAR) || ((C) == UNICODE_QMARK))                \
)

// ds\netapi\svcimgs\ntrepl\util\info.c
#define IPRINTGNAME(_I_, _G_, _F_, _GUID_, _P_) \
{ \
    if (_G_) { \
        GuidToStr(_G_->Guid, _GUID_); \
        IPRINT3(_I_, _F_, _P_, _G_->Name, _GUID_); \
    } \
}

// ds\netapi\xactsrv\xsprocsp.h
#define XsAuxiliaryDescriptor( DataDescriptor, EndOfParameters ) \
    (( strchr(( DataDescriptor ), REM_AUX_NUM ) != NULL ) \
        ? (EndOfParameters) : NULL )
#define XS_MAP_SERVICE_NAME( ServiceName ) \
        (!STRICMP( ServiceName, SERVICE_LM20_SERVER ) ? SERVICE_SERVER :    \
         !STRICMP( ServiceName, SERVICE_LM20_WORKSTATION ) ? SERVICE_WORKSTATION : \
         ServiceName )

// ds\nw\convert\nwconv\columnlb.c
#define LB16_ADDSTRING      (WM_USER+1)
#define LB16_INSERTSTRING   (WM_USER+2)

// ds\nw\convert\nwconv\vlist.h
#define VLB_GETTEXT             (WM_USER+503)
#define VLB_GETTEXTLEN          (WM_USER+504)
#define VLB_SELECTSTRING        (WM_USER+506)
#define VLB_FINDSTRING          (WM_USER+507)
#define VLB_FINDSTRINGEXACT     (WM_USER+513)
#define VLBR_FINDSTRING         (WM_USER+600)
#define VLBR_FINDSTRINGEXACT    (WM_USER+601)
#define VLBR_SELECTSTRING       (WM_USER+602)
#define VLBR_GETTEXT            (WM_USER+604)
#define VLBR_GETTEXTLEN         (WM_USER+605)

// ds\nw\inc\ntddnwfs.h
#define CONNTYPE_ANY       ( CONNTYPE_DISK | CONNTYPE_PRINT )

// ds\nw\install\setupdll\common.h
#define StringToInt(in,out) \
    (((_stscanf ((in), TEXT(" %d"), (out))) == 1) ? TRUE : FALSE)

// ds\nw\nwlib\win95\msnwerr.h
#define NWRE_DRIVE_IN_USE           (REQUESTR_ERR | 0x02)
#define NWRE_CANT_ADD_CDS           (REQUESTR_ERR | 0x03)
#define NWRE_NET_RECV_ERROR         (REQUESTR_ERR | 0x05)
#define NWRE_UNKNOWN_NET_ERROR      (REQUESTR_ERR | 0x06)
#define NWRE_NO_SERVER_SLOTS        (REQUESTR_ERR | 0x08)  //server refused attach
#define NWRE_SERVER_NO_ROUTE        (REQUESTR_ERR | 0x0A)
#define NWRE_BAD_LOCAL_TARGET       (REQUESTR_ERR | 0x0B)
#define NWRE_TOO_MANY_REQ_FRAGS     (REQUESTR_ERR | 0x0C)  //request buffer too long
#define NWRE_CONNECT_LIST_OVERFLOW  (REQUESTR_ERR | 0x0D)
#define NWRE_BUFFER_OVERFLOW        (REQUESTR_ERR | 0x0E) //reply buffer not big enough
#define NWRE_NO_ROUTER_FOUND        (REQUESTR_ERR | 0x10)
#define NWRE_PARAMETER_NOT_FOUND    (REQUESTR_ERR | 0x10)
#define NWRE_BAD_FUNC               (REQUESTR_ERR | 0x11)
#define NWRE_PRIMARY_CONN_NOT_SET   (REQUESTR_ERR | 0x31) //no default connection set
#define NWRE_CONNECTION_TABLE_FULL  (REQUESTR_ERR | 0x3F) // too many local connections
#define NWRE_NO_SERVER              (REQUESTR_ERR | 0x47)
#define NWRE_DEVICE_NOT_REDIRECTED  (REQUESTR_ERR | 0x4C)
#define NWRE_TOO_MANY_REPLY_FRAGS   (REQUESTR_ERR | 0x50) // too many fragments in reply buff
#define NWRE_OUT_OF_MEMORY          (REQUESTR_ERR | 0x53)    // local memory allocation failure
#define NWRE_PREFERRED_NOT_FOUND    (REQUESTR_ERR | 0x55)
#define NWRE_DEVICE_NOT_RECOGNIZED  (REQUESTR_ERR | 0x56)
#define NWRE_BAD_NET_TYPE           (REQUESTR_ERR | 0x57)
#define NWRE_FAILURE                (REQUESTR_ERR | 0xff)   //  internal shell failure

// ds\nw\nwlib\win95\nwapi95.h
#define memcpyW(x,y,z) memcpy(x,y,(z)*sizeof(WCHAR))
#define memmoveW(x,y,z) memmove(x,y,(z)*sizeof(WCHAR))

// ds\nw\nwscript\inc\nwlibs.h
#define PS_JOB_DEFAULT              (NWPS_JOB_PRINT_BANNER | NWPS_JOB_AUTO_END)

// ds\nw\rdr\kdext\nwrdrkd.c
#define  GET_STRING( pDest, string ) \
    (lpExtensionApis->lpReadVirtualMemRoutine)(string.Buffer, pDest, \
        string.Length, NULL); pDest[ string.Length/2 ] = L'\0'
#define getsymaddr( string ) ((lpExtensionApis->lpGetExpressionRoutine))( "&"##string )

// ds\nw\svcdlls\nwwks\client\nwshrc.h
#define NW_HELP_FILE       (USER_SHARED_DATA->NtProductType == NtProductWinNt ? \
                                   TEXT("nwdoc.hlp") : TEXT("nwdocgw.hlp"))

// ds\win32\credui\api.cpp
#define CREDUI_STRING(id, name) {\
    id, CreduiStrings.##name, (sizeof CreduiStrings.##name) / (sizeof WCHAR)\
}

// ds\win32\ntcrypto\autoenrl\csenroll\enroll.c
#define PrintMessage(MsgType, Msg) \
	if (MsgType & dwMsgLevel & MSG_ERROR_S)        _PrintMessage(L"csenroll: error: "); \
	else if (MsgType & dwMsgLevel & MSG_ERROR_C)   _PrintMessage(L"                 "); \
	else if (MsgType & dwMsgLevel & MSG_WARNING_S) _PrintMessage(L"csenroll: warning: "); \
	else if (MsgType & dwMsgLevel & MSG_WARNING_C) _PrintMessage(L"                   "); \
	else if (MsgType & dwMsgLevel & MSG_INFO_S) _PrintMessage(L"csenroll: "); \
	else if (MsgType & dwMsgLevel & MSG_INFO_C) _PrintMessage(L"          "); \
	if (MsgType & dwMsgLevel) _PrintMessage Msg

// ds\win32\ntcrypto\contman\contman.c
#define PRODUCTSTRINGLEN    sizeof(WSZRSAPRODUCTSTRING) - sizeof(WCHAR)

// enduser\mapistub\mapistub\_smerror.h
#define StrFromScode(_sc) \
	((UINT) ((_sc) & (0x00007fffL)))

// enduser\netmeeting\as\h\fh.h
#define FH_SC_APPROX_MATCH (FH_SC_MATCH | FH_SC_ALL_CHARS)
#define FH_SC_EXACT_MATCH (FH_SC_MATCH | FH_SC_ALL_CHARS | FH_SC_EXACT)

// enduser\netmeeting\as\h\t_share.h
#define NF_PRE_R11      (NF_FIXED_PITCH | NF_FIXED_SIZE | \
                         NF_ITALIC | NF_UNDERLINE | NF_STRIKEOUT)
#define NF_LOCAL            (NF_OEM_CHARSET | NF_TRUE_TYPE)

// enduser\netmeeting\av\codecs\dec\dech261\slib.h
#define slibHasAudio(Info) (Info->AudioStreams>0 || Info->Sah)
#define slibHasVideo(Info) (Info->VideoStreams>0 || Info->Svh)

// enduser\netmeeting\av\codecs\dec\dech263\slib.h
#define slibHasAudio(Info) (Info->AudioStreams>0 || Info->Sah)
#define slibHasVideo(Info) (Info->VideoStreams>0 || Info->Svh)

// enduser\netmeeting\av\codecs\intel\g723\g723.h
    #define SIZEOFACMSTR(x) sizeof(x)

// enduser\netmeeting\av\nac\vidstrm.cpp
#define SIZEOF_VIDEOFORMATEX(pwfx)   (sizeof(VIDEOFORMATEX))

// enduser\netmeeting\h\html.h
#define WRITEHTMLREFCRLF(lpBuf,lpszUrl,lpszDisplayName)					\
	wsprintf((LPSTR)(lpBuf), "%c%s\"%s\"%c%s%c%s%c<BR>\r\n", 			\
		HTMLTOKENBEGINCHAR,(LPSTR)HTMLAHREFSTARTSTR,					\
		(LPSTR)lpszUrl,HTMLTOKENENDCHAR,								\
		(LPSTR)lpszDisplayName,HTMLTOKENBEGINCHAR,						\
		(LPSTR)HTMLAHREFENDSTR,HTMLTOKENENDCHAR)

// enduser\netmeeting\h\standrd.h
#define DECLARE_CCOMBSTR_PROPPUT( Prop, PROP_DISPID ) \
    STDMETHOD(put_##Prop)( BSTR newVal )  \
    {\
        HRESULT hr = S_OK;\
        if( S_OK == __ATL_PROP_NOTIFY_EVENT_CLASS::FireOnRequestEdit(GetUnknown(), PROP_DISPID) )\
        {\
            m_bstr##Prop = newVal;\
            hr = __ATL_PROP_NOTIFY_EVENT_CLASS::FireOnChanged(GetUnknown(), PROP_DISPID);\
        }\
        return hr;                \
    }

// enduser\netmeeting\t120\h\memmgr.h
#define GetMemoryObjectFromEncData(p)	((PMemory) ((PUChar) p - sizeof(Memory)))

// enduser\netmeeting\ui\conf\callto.h
#define strlen_literal( l )			((sizeof( (l) ) / sizeof( TCHAR )) - 1)
#define StrCmpNI_literal( str, l )	((bool)(StrCmpNI( (str), (l), ((sizeof( (l) ) / sizeof( TCHAR )) - 1) ) == 0))

// enduser\netmeeting\ui\nmctl1\comboboxex.h
#define CBEIF_ALL (CBEIF_IMAGE | CBEIF_INDENT | CBEIF_LPARAM | CBEIF_OVERLAY | CBEIF_SELECTEDIMAGE | CBEIF_TEXT )

// enduser\netmeeting\ulsldap\spconn.h
#define STR_EMPTY				((TCHAR *) &c_szEmptyString[0])

// enduser\stuff\itircl\fts\common\common.h
#define DLLGMEM_ZEROINIT        (GMEM_MOVEABLE | GMEM_SHARE | GMEM_ZEROINIT | GMEM_PMODELOCKSTRATEGY)

// enduser\stuff\itircl\inc\mem.h
#define	DLLGMEM_ZEROINIT		(GMEM_MOVEABLE | GMEM_SHARE | GMEM_ZEROINIT | GMEM_PMODELOCKSTRATEGY)

// enduser\stuff\itircl\svmgr\cmdint\cmdint.h
#define WSTRCB(wstr) (WSTRLEN (wstr) * 2 + sizeof (WCHAR))

// enduser\stuff\itss\lzx\encoder\optenc.c
#define OUT_CHAR(ch) \
	context->enc_LitData [context->enc_literals++] = ch;

// enduser\troubleshoot\msinfo\stdafx.h
#define OLESTR_FROM_CSTRING(cstr)	\
	(T2OLE(const_cast<LPTSTR>((LPCTSTR)(cstr))))
#define WSTR_FROM_CSTRING(cstr)		\
	(const_cast<LPWSTR>(T2CW(cstr)))

// enduser\troubleshoot\tshoot\apgts.h
#define C_AMPERSAND		_T("&")			// Standard delimiter character.

// enduser\windows.com\inc\memutil.h
#define A2W(lpa) (\
		((_lpa = lpa) == NULL) ? NULL : (\
			_convert = (lstrlenA(_lpa)+1),\
			AtlA2WHelper((LPWSTR)MemAlloc(_convert*2), _lpa, _convert, CP_ACP)))
#define W2A(lpw) (\
		((_lpw = lpw) == NULL) ? NULL : (\
			_convert = (lstrlenW(_lpw)+1)*2,\
			AtlW2AHelper((LPSTR)MemAlloc(_convert), _lpw, _convert, CP_ACP)))

// enduser\windows.com\lib\download\dlutil.h
#define sizeofSTRA(sz)  (sizeof(sz))

// enduser\windows.com\wuau\wuaueng\selfupdate.cpp
#define TCHAR_SCTRUCTURE_DELIMITER  _T('|')

// enduser\windows.com\wuv3\cdmlib\drvinfo.cpp
#define A2W(lpa) (\
		((_lpa = lpa) == NULL) ? NULL : (\
			_convert = (lstrlenA(_lpa)+1),\
			AtlA2WHelper((LPWSTR)_alloca(_convert*2), _lpa, _convert, CP_ACP)))
#define W2A(lpw) (\
		((_lpw = lpw) == NULL) ? NULL : (\
			_convert = (lstrlenW(_lpw)+1)*2,\
			AtlW2AHelper((LPSTR)_alloca(_convert), _lpw, _convert, CP_ACP)))

// enduser\windows.com\wuv3\cdmlib\newtrust.cpp
#define A2W(lpa) (\
		((_lpa = lpa) == NULL) ? NULL : (\
			_convert = (lstrlenA(_lpa)+1),\
			AtlA2WHelper((LPWSTR)_alloca(_convert*2), _lpa, _convert, CP_ACP)))
#define W2A(lpw) (\
		((_lpw = lpw) == NULL) ? NULL : (\
			_convert = (lstrlenW(_lpw)+1)*2,\
			AtlW2AHelper((LPSTR)_alloca(_convert), _lpw, _convert, CP_ACP)))

// enduser\windows.com\wuv3\wuv3is\winres.h
#define LB_ADDSTRING    (WM_USER+1)
#define CB_ADDSTRING    (WM_USER+3)

// inetcore\connectionwizard\icwconn1\icwconn1.h
#define A2W(lpa) (\
        ((LPCSTR)lpa == NULL) ? NULL : (\
                _convert = (lstrlenA(lpa)+1),\
                A2WHELPER((LPWSTR) alloca(_convert*2), lpa, _convert)))
#define W2A(lpw) (\
        ((LPCWSTR)lpw == NULL) ? NULL : (\
                _convert = (lstrlenW(lpw)+1)*2,\
                W2AHELPER((LPTSTR) alloca(_convert), lpw, _convert)))

// inetcore\connectionwizard\icwconn\wizard.h
#define A2W(lpa) (\
        ((LPCSTR)lpa == NULL) ? NULL : (\
                _convert = (lstrlenA(lpa)+1),\
                A2WHELPER((LPWSTR) alloca(_convert*2), lpa, _convert)))
#define W2A(lpw) (\
        ((LPCWSTR)lpw == NULL) ? NULL : (\
                _convert = (lstrlenW(lpw)+1)*2,\
                W2AHELPER((LPTSTR) alloca(_convert), lpw, _convert)))

// inetcore\connectionwizard\icwdl\mydefs.h
#define MyAlloc(n)			((LPTSTR)HeapAlloc(g_hDLLHeap, HEAP_ZERO_MEMORY, sizeof(TCHAR)*(n)))
#define MyRealloc(pv, n)	((LPTSTR)HeapReAlloc(g_hDLLHeap, HEAP_ZERO_MEMORY, (pv), sizeof(TCHAR)*(n)))

// inetcore\connectionwizard\icwutil\icwutil.h
#define A2W(lpa) (\
        ((LPCTSTR)lpa == NULL) ? NULL : (\
                _convert = (lstrlenA((LPTSTR)lpa)+1),\
                A2WHELPER((LPWSTR) alloca(_convert*2), (LPTSTR)lpa, _convert)))
#define W2A(lpw) (\
        ((LPCWSTR)lpw == NULL) ? NULL : (\
                _convert = (lstrlenW(lpw)+1)*2,\
                W2AHELPER((LPTSTR) alloca(_convert), lpw, _convert)))

// inetcore\connectionwizard\inc\ccstock.h
#define CbFromCchW(cch)             ((cch)*sizeof(WCHAR))
#define CbFromCchA(cch)             ((cch)*sizeof(CHAR))

// inetcore\connectionwizard\mapi\inc\mapitags.h
#define FIsTransmittable(ulPropTag) \
    ((PROP_ID (ulPropTag) <  (ULONG)0x0E00) || \
    (PROP_ID (ulPropTag)  >= (ULONG)0x8000) || \
    ((PROP_ID (ulPropTag) >= (ULONG)0x1000) && (PROP_ID (ulPropTag) < (ULONG)0x6000)) || \
    ((PROP_ID (ulPropTag) >= (ULONG)0x6800) && (PROP_ID (ulPropTag) < (ULONG)0x7C00)))

// inetcore\connectionwizard\mapi\inc\mapiwin.h
#define Cbtszsize(_a)   ((lstrlen(_a)+1)*sizeof(TCHAR))
#define CbtszsizeW(_a)  ((lstrlenW(_a) + 1) * sizeof(WCHAR))
#define HexSizeOf(_s)   (HexCchOf(_s)*sizeof(TCHAR))

// inetcore\datacab\tdc\winres.h
#define LB_ADDSTRING    (WM_USER+1)
#define CB_ADDSTRING    (WM_USER+3)

// inetcore\digest\test\stress\monkey.cpp
#define MALLOC( x ) malloc(sizeof(x))

// inetcore\mshtml\external\inc\handler.h
#define kgrfxmlNormal	(fxmlElement|fxmlHasText)
#define kgrfxmlAll		(fxmlElement|fxmlAttribute|fxmlText|fxmlComment| \
							fxmlPI|fxmlXMLDecl)

// inetcore\mshtml\iextag\winres.h
#define LB_ADDSTRING    (WM_USER+1)
#define CB_ADDSTRING    (WM_USER+3)

// inetcore\mshtml\imgfilt\atlcom.h
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
#define DECLARE_STATIC_REGISTRY_RESOURCE(x)\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister)\
	{\
	return _Module.UpdateRegistryFromResourceS(_T(#x), bRegister);\
	}
#define DECLARE_STATIC_REGISTRY_RESOURCEID(x)\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister)\
	{\
	return _Module.UpdateRegistryFromResourceS(x, bRegister);\
	}

// inetcore\mshtml\src\core\include\cdutil.hxx
#define PROP_NOPERSIST(type, size, name)         \
    {                                            \
        WPI_##type | WPI_NOPERSIST,              \
        size, 0, 0,                              \
        (LPCSTR)NULL                             \
    },

// inetcore\mshtml\src\edit\dlghelpr.cxx
#define VERIFY_VARARG_4BSTR(arg, var)           \
    switch(V_VT(&arg))                          \
    {                                           \
    case    VT_BSTR:                            \
        var = &arg;                             \
        break;                                  \
    case    VT_BYREF|VT_BSTR:                   \
        var = V_VARIANTREF(&arg);               \
        break;                                  \
    default:                                    \
        var = NULL;                             \
    }

// inetcore\mshtml\src\edit\winres.h
#define LB_ADDSTRING    (WM_USER+1)
#define CB_ADDSTRING    (WM_USER+3)

// inetcore\mshtml\src\site\display\region2.cxx
#define YSTEP if (p == _aStripe) { if (p->GetSize() != 0) p++; }\
          else               { if (!p->IsEqualToPrevious()) p++; }

// inetcore\mshtml\src\site\download\htm.hxx
#define ISTXTCH(ch) (((ch) > _T('<')) || g_charclass[ch] & CCF_TXTCH)
#define ISNONSP(ch) (((ch) > _T(' ')) || g_charclass[ch] & CCF_NONSP)
#define ISNAMCH(ch) (((ch) > _T('>')) || g_charclass[ch] & CCF_NAMCH)
#define ISATTCH(ch) (((ch) > _T('>')) || g_charclass[ch] & CCF_ATTCH)
#define ISVALCH(ch) (((ch) > _T('>')) || g_charclass[ch] & CCF_VALCH)
#define ISNDASH(ch) (((ch) > _T('-')) || g_charclass[ch] & CCF_NDASH)
#define ISTAGCH(ch) (((ch) > _T('>')) ? ((ch) != _T('`')) : (g_charclass[ch] & CCF_TAGCH))
#define ISMRKCH(ch) (((ch) > _T('>')) || g_charclass[ch] & CCF_MRKCH)

// inetcore\mshtml\src\site\download\htmpost.cxx
#define PRETTY_CHAR(ch) ((ch) < 32 ? _T('~') : (ch) > 127 ? _T('@') : (ch))

// inetcore\mshtml\src\site\download\htmtok.cxx
#define PRETTY_CHAR(ch) ((ch) < 32 ? _T('~') : (ch) > 127 ? _T('@') : (ch))

// inetcore\mshtml\src\site\include\wchdefs.h
#define WCH_NONBREAKSPACE       WCHAR(0x00a0) // &nbsp;
#define WCH_NONREQHYPHEN        WCHAR(0x00ad) // &shy;
#define WCH_ENSPACE             WCHAR(0x2002) // &ensp;
#define WCH_EMSPACE             WCHAR(0x2003) // &emsp;
#define WCH_NARROWSPACE         WCHAR(0x2009) // &thinsp;
#define WCH_ENDASH              WCHAR(0x2013) // &ndash;
#define WCH_EMDASH              WCHAR(0x2014) // &mdash;
#define WCH_ZWSP                WCHAR(0x200b) // &zwsp; Zero width space
#define WCH_ZWNJ                WCHAR(0x200c) // &zwnj; Zero width non-joiner
#define WCH_ZWJ                 WCHAR(0x200d) // &zwj;  Zero width joiner
#define WCH_LRM                 WCHAR(0x200e) // &lrm;  Left-to-right mark
#define WCH_RLM                 WCHAR(0x200f) // &rlm;  Right-to-left mark
#define WCH_LQUOTE              WCHAR(0x2018) // &lsquo;
#define WCH_RQUOTE              WCHAR(0x2019) // &rsquo;
#define WCH_LDBLQUOTE           WCHAR(0x201c) // &ldquo;
#define WCH_RDBLQUOTE           WCHAR(0x201d) // &rdquo;
#define WCH_BULLET              WCHAR(0x2022) // &bull;
#define WCH_LRE                 WCHAR(0x202a) // &lre;  Left-to-right embedding
#define WCH_RLE                 WCHAR(0x202b) // &rle;  Right-to-left embedding
#define WCH_PDF                 WCHAR(0x202c) // &pdf;  Pop direction format
#define WCH_LRO                 WCHAR(0x202d) // &lro;  Left-to-right override
#define WCH_RLO                 WCHAR(0x202e) // &rlo;  Right-to-left override
#define WCH_AAFS                WCHAR(0x206d) // &aafx; Activate Arabic form shaping
#define WCH_NADS                WCHAR(0x206e) // &nads; National digit shapes
#define WCH_EURO                WCHAR(0x20ac) // &euro;

// inetcore\mshtml\src\site\text\_txtsave.h
#define RSF_CFHTML (RSF_CFHTML_HEADER | RSF_FRAGMENT | RSF_SELECTION | RSF_CONTEXT)
#define RSF_HTML   (RSF_FRAGMENT | RSF_SELECTION | RSF_CONTEXT)

// inetcore\mshtml\src\site\text\font.cxx
#define IsZeroWidth(ch) ((ch) >= 0x0300 && IsZeroWidthChar((ch)))

// inetcore\mshtml\src\site\util\optshold.cxx
#define VERIFY_VARARG_4BSTR(arg, var)           \
    switch(V_VT(&arg))                          \
    {                                           \
    case    VT_BSTR:                            \
        var = &arg;                             \
        break;                                  \
    case    VT_BYREF|VT_BSTR:                   \
        var = V_VARIANTREF(&arg);               \
        break;                                  \
    default:                                    \
        var = NULL;                             \
    }

// inetcore\mshtml\tried\inc\winres.h
#define LB_ADDSTRING    (WM_USER+1)
#define CB_ADDSTRING    (WM_USER+3)

// inetcore\mshtml\tried\triedctl\win95wrp.cpp
#define SzWAlloc(cch) ((LPWSTR)_alloca(cch * sizeof(WCHAR)))

// inetcore\mshtml\tried\triedit\token.h
#define INSTRING (inString|inStringA)

// inetcore\mshtml\tried\triedit\tokhtml.h
#define INSTRING (inString|inStringA)

// inetcore\mshtml\tried\triedit\win95wrp.cpp
#define SzWAlloc(cch) ((LPWSTR)_alloca(cch * sizeof(WCHAR)))

// inetcore\outlookexpress\autodiscovery\client\fromshell.h
#define CbFromCchW(cch)             ((cch)*sizeof(WCHAR))
#define CbFromCchA(cch)             ((cch)*sizeof(CHAR))

// inetcore\outlookexpress\inc\athena16.h
#define CBEM_SETEXSTYLE         (WM_USER + 8)  // use  SETEXTENDEDSTYLE instead
#define CBEM_GETEXSTYLE         (WM_USER + 9) // use GETEXTENDEDSTYLE instead
#define CBEM_GETEXTENDEDSTYLE   (WM_USER + 9)

// inetcore\outlookexpress\inc\macdupls.h
#define wcscat(_a, _b)      CopyMemory(&((_a)[lstrlenW(_a)]), (_b), sizeof(WCHAR) * (lstrlenW(_b) + 1))

// inetcore\outlookexpress\inetcomm\ess\ess.h
#define SIZE_ESS_Module_PDU_4 sizeof(MLExpansionHistory)

// inetcore\outlookexpress\inetcomm\inc\htmlstr.h
#define MAKEBSTR(name, count, strdata) \
    extern "C" const char CDECL DATA_##name [] = {(count * sizeof(OLECHAR)), 0x00, strdata}; \
    extern "C" BSTR  CDECL name = (BSTR)& DATA_##name[2];

// inetcore\outlookexpress\inetcomm\mimeedit\bodyutil.cpp
#define WSZ_CB(str)         (lstrlenW(str)*sizeof(WCHAR))
#define WSZ_CBNULL(str)     ((lstrlenW(str)+1)*sizeof(WCHAR))

// inetcore\outlookexpress\inetcomm\mimeedit\plainstm.cpp
#define IsSpecialChar(_ch)  ( _ch == chLessThan || _ch == chSpace || _ch == chCR || _ch == chLF || _ch == chQuoteChar || _ch == chLessThan || _ch == chGreaterThan || _ch == chAmpersand )

// inetcore\outlookexpress\inetcomm\mimeole\inetconv.h
#define ConvBuffAppendW(_wch) \
    { \
        *((WCHAR *)&m_rOut.pb[m_rOut.cb]) = _wch; \
        m_rOut.cb += 2; \
    }

// inetcore\outlookexpress\inetcomm\mimeole\internat.h
#define HCSETMAKE(_index)          (HCHARSET)MAKELPARAM(m_wTag + HCSET_SIGN, _index)

// inetcore\outlookexpress\inetcomm\mimeole\smimetst\encode.cpp
#define APPEND_SEPERATOR(subject) \
    if (lstrlen(subject)) {       \
        lstrcat(subject, " | ");  \
    }

// inetcore\outlookexpress\inetcomm\mimeole\variantx.h
#define PSZSTRINGA(_pVariant) \
    (ISSTRINGA((_pVariant)) ? (_pVariant)->rStringA.pszVal : NULL)
#define PSZDEFSTRINGA(_pVariant, _pszDefault) \
    (ISSTRINGA((_pVariant)) ? (_pVariant)->rStringA.pszVal : _pszDefault)

// inetcore\outlookexpress\mailnews\common\statnery.cpp
#define PSZ_CB(psz)   lstrlen(psz)*sizeof(*psz)
#define PWSZ_CB(pwsz)   lstrlenW(pwsz)*sizeof(*pwsz)

// inetcore\outlookexpress\mailnews\common\tbinfo.h
#define  PARTIALTEXT_BUTTON     (TBSTYLE_BUTTON | BTNS_SHOWTEXT)
#define  PARTIALTEXT_DROPDOWN   (TBSTYLE_DROPDOWN | BTNS_SHOWTEXT)

// inetcore\outlookexpress\mailnews\fechrcnv\fechrcnv.h
#define SJISISKANJI(c) ( ( (UCHAR)(c) >= 0x81 && (UCHAR)(c) <= 0x9f ) || \
                         ( (UCHAR)(c) >= 0xe0 && (UCHAR)(c) <= 0xfc ) )
#define SJISISKANA(c) ( (UCHAR)(c) >= 0xa1 && (UCHAR)(c) <= 0xdf )

// inetcore\outlookexpress\mailnews\inc\htmlstr.h
#define MAKEBSTR(name, count, strdata) \
    extern "C" const char CDECL DATA_##name [] = {(count * sizeof(OLECHAR)), 0x00, strdata}; \
    extern "C" BSTR  CDECL name = (BSTR)& DATA_##name[2];

// inetcore\outlookexpress\mailnews\inc\thormsgs.h
#define TT_ISTEXTVISIBLE    (WM_USER + 1502)

// inetcore\outlookexpress\public\inc\wabtags.h
#define FIsTransmittable(ulPropTag) \
    ((PROP_ID (ulPropTag) <  (ULONG)0x0E00) || \
    (PROP_ID (ulPropTag)  >= (ULONG)0x8000) || \
    ((PROP_ID (ulPropTag) >= (ULONG)0x1000) && (PROP_ID (ulPropTag) < (ULONG)0x6000)) || \
    ((PROP_ID (ulPropTag) >= (ULONG)0x6800) && (PROP_ID (ulPropTag) < (ULONG)0x7C00)))

// inetcore\outlookexpress\wabw\convert\wabmig\_wabmig.h
#define cbAtSign        (2 * sizeof(TCHAR))
#define cbMSNpostfix    (9 * sizeof(TCHAR))
#define cbCOMPUSERVEpostfix     (16 * sizeof(TCHAR))

// inetcore\outlookexpress\wabw\convert\wmnets\wabimp.h
#define cbAtSign        (2 * sizeof(TCHAR))
#define cbMSNpostfix    (9 * sizeof(TCHAR))
#define cbCOMPUSERVEpostfix     (16 * sizeof(TCHAR))

// inetcore\outlookexpress\wabw\test\wabtests\winres.h
#define LB_ADDSTRING    (WM_USER+1)
#define CB_ADDSTRING    (WM_USER+3)

// inetcore\outlookexpress\wabw\wabapi\_errctx.h
#define MAPIX_CONTEXT_MULT			(0x20)

// inetcore\outlookexpress\wabw\wabfind\fnd.h
#define cbCtch(ctch) ((ctch) * sizeof(TCHAR))

// inetcore\published\inc\wabtags.h
#define FIsTransmittable(ulPropTag) \
    ((PROP_ID (ulPropTag) <  (ULONG)0x0E00) || \
    (PROP_ID (ulPropTag)  >= (ULONG)0x8000) || \
    ((PROP_ID (ulPropTag) >= (ULONG)0x1000) && (PROP_ID (ulPropTag) < (ULONG)0x6000)) || \
    ((PROP_ID (ulPropTag) >= (ULONG)0x6800) && (PROP_ID (ulPropTag) < (ULONG)0x7C00)))

// inetcore\setup\active\iernonce\iernonce.cpp
#define SEPERATOR_CHAR          TEXT('|')

// inetcore\setup\active\inc\prsht.h
#define PSM_SETFINISHTEXTA      (WM_USER + 115)
#define PSM_SETFINISHTEXTW      (WM_USER + 121)

// inetcore\setup\ieak5\ieakutil\ieakutil.h
#define StrCbFromCchW(cchSrc)     ((cchSrc) * sizeof(WCHAR))
#define StrCchFromCbW(cbSrc)      (GetUnitsFromCb(cbSrc, sizeof(WCHAR)))

// inetcore\setup\ieak5\ieinst\winres.h
#define LB_ADDSTRING    (WM_USER+1)
#define CB_ADDSTRING    (WM_USER+3)

// inetcore\setup\ieak5\inc\iedkbrnd.h
#define BRAND_ALL           (BRAND_FAVORITES | BRAND_MAIL | BRAND_NEWS | BRAND_RESTRICT | BRAND_CONF | BRAND_TOOLBAR)
#define BRAND_NO_RESTRICT   (BRAND_FAVORITES | BRAND_MAIL | BRAND_NEWS | BRAND_CONF | BRAND_TOOLBAR)
#define IsSpace(c)       ((c) == TEXT(' ')   ||  (c) == TEXT('\t')  ||  (c) == TEXT('\r') || \
    (c) == TEXT('\n')  ||  (c) == TEXT('\v')  ||  (c) == TEXT('\f'))

// inetcore\setup\ieak5\keyocx\winres.h
#define LB_ADDSTRING    (WM_USER+1)
#define CB_ADDSTRING    (WM_USER+3)

// inetcore\setup\ieproj\msinfo\msiectl.cpp
#define SETPROPERTY(prop) \
	if (pData->prop.vt == VT_DATE) \
		ConvertDateToWbemString(pData->prop); \
	pInstance->Put(L#prop, 0, &pData->prop, 0);

// inetcore\urlmon\inc\urlint.h
    #   define DEB_ISTREAM          (DEB_USER3 | DEB_URLMK_LEVEL)

// inetcore\urlmon\utils\cvar.cxx
#define A2CW(lpa) (\
        ((LPCSTR)lpa == NULL) ? NULL : (\
                _convert = (lstrlenA(lpa)+1),\
                (LPCWSTR)AfxA2WHelper((LPWSTR) alloca(_convert*2), lpa, _convert)\
        )\
)
#define A2W(lpa) (\
        ((LPCSTR)lpa == NULL) ? NULL : (\
                _convert = (lstrlenA(lpa)+1),\
                AfxA2WHelper((LPWSTR) alloca(_convert*2), lpa, _convert)\
        )\
)
#define W2CA(lpw) (\
        ((LPCWSTR)lpw == NULL) ? NULL : (\
                _convert = (wcslen(lpw)+1)*2,\
                (LPCSTR)AfxW2AHelper((LPSTR) alloca(_convert), lpw, _convert)\
        )\
)
#define W2A(lpw) (\
        ((LPCWSTR)lpw == NULL) ? NULL : (\
                _convert = (wcslen(lpw)+1)*2,\
                AfxW2AHelper((LPSTR) alloca(_convert), lpw, _convert)\
        )\
)

// inetcore\urlmon\utils\output.c
#define find_char_class(c)              \
        ((c) < ' ' || (c) > 'x' ?       \
            CH_OTHER                    \
        :                               \
            lookuptable[(c)-' '] & 0xF)

// inetcore\winhttp\tools\stress\stressscheduler\src\winhttpstressscheduler.h
#define MYWM_NOTIFYICON	(WM_APP+100)

// inetcore\winhttp\tools\stress\winhttpstressscheduler.h
#define MYWM_NOTIFYICON	(WM_APP+100)

// inetcore\winhttp\v5.1\api\parseurl.cxx
#define NUMBER_TO_HEX_CHAR(n) \
    (((n) <= 9) ? ((char)(n) + '0') : (((char)(n) - 10) + 'A'))

// inetcore\winhttp\v5.1\autoproxy\dhcp.h
#define BOOT_FILE_SIZE_W        ( BOOT_FILE_SIZE * sizeof( WCHAR ))
#define BOOT_SERVER_SIZE_W      ( BOOT_SERVER_SIZE * sizeof( WCHAR ))

// inetcore\winhttp\v5.1\http\headers.h
#define CSTRLEN(str)  (sizeof(str)-1)

// inetcore\winhttp\v5.1\inc\tstr.h
#define STRSIZE(p)      ((STRLEN(p)+1) * sizeof(TCHAR))
#define WCSSIZE(s)      ((MAKE_STR_FUNCTION(wcslen)(s)+1) * sizeof(WCHAR))
#define STRING_SPACE_REQD(n)    ((n) * sizeof(_CHAR_TYPE))
#define DOWN_LEVEL_STRSIZE(n)   ((n) / sizeof(_CHAR_TYPE))

// inetcore\winhttp\v5\api\parseurl.cxx
#define NUMBER_TO_HEX_CHAR(n) \
    (((n) <= 9) ? ((char)(n) + '0') : (((char)(n) - 10) + 'A'))

// inetcore\winhttp\v5\http\headers.h
#define CSTRLEN(str)  (sizeof(str)-1)

// inetcore\winhttp\v5\inc\tstr.h
#define STRSIZE(p)      ((STRLEN(p)+1) * sizeof(TCHAR))
#define WCSSIZE(s)      ((MAKE_STR_FUNCTION(wcslen)(s)+1) * sizeof(WCHAR))
#define STRING_SPACE_REQD(n)    ((n) * sizeof(_CHAR_TYPE))
#define DOWN_LEVEL_STRSIZE(n)   ((n) / sizeof(_CHAR_TYPE))

// inetcore\wininet\apdetect\dhcp.h
#define BOOT_FILE_SIZE_W        ( BOOT_FILE_SIZE * sizeof( WCHAR ))
#define BOOT_SERVER_SIZE_W      ( BOOT_SERVER_SIZE * sizeof( WCHAR ))

// inetcore\wininet\dll\parseurl.cxx
#define NUMBER_TO_HEX_CHAR(n) \
    (((n) <= 9) ? ((char)(n) + '0') : (((char)(n) - 10) + 'A'))

// inetcore\wininet\http\dav.cxx
    #define READ_BUFFER_AVAILABLE  (READ_BUFFER_SIZE - sizeof(LPSTR))

// inetcore\wininet\http\headers.h
#define CSTRLEN(str)  (sizeof(str)-1)

// inetcore\wininet\http\sendreq.cxx
#define ACCEPT_ENCODING_URLMON_STRLEN (sizeof(ACCEPT_ENCODING_URLMON_STRING)-1)

// inetcore\wininet\inc\thrdinfo.h
#define _InternetGetContext(lpThreadInfo) \
    lpThreadInfo->Context

// inetcore\wininet\inc\tstr.h
#define STRSIZE(p)      ((STRLEN(p)+1) * sizeof(TCHAR))
#define WCSSIZE(s)      ((MAKE_STR_FUNCTION(wcslen)(s)+1) * sizeof(WCHAR))
#define STRING_SPACE_REQD(n)    ((n) * sizeof(_CHAR_TYPE))
#define DOWN_LEVEL_STRSIZE(n)   ((n) / sizeof(_CHAR_TYPE))

// inetcore\wininet\p3p\map2policy.cpp
#define different(s, p) !(s&&p&&!strcmp(s,p))

// inetsrv\iis\config\src\appcenter\inc\appsrvadmlib.h
#define DECLARE_ASAI_TRACING(name, w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11)\
const GUID CAppSrvAdmModule::m_ModuleTraceGuid = {w1,w2,w3,{w4,w5,w6,w7,w8,w9,w10,w11}};\
const LPCSTR CAppSrvAdmModule::m_pszModuleName = name;

// inetsrv\iis\config\src\complib\inc\crtwrap.h
#define _ALPHA		(0x0100|_UPPER|_LOWER)	  /* alphabetic character */
#define wcsncpy(s1, s2, slen)	memcpy(s1, s2, (slen) * sizeof(wchar_t))
#define wcsncmp(s1, s2, slen)	memcmp(s1, s2, (slen) * sizeof(wchar_t))
#define _tcsncmp(s1, s2, slen)	memcmp(s1, s2, (slen) * sizeof(wchar_t))
#define _tcsnccmp(s1, s2, slen)   memcmp(s1, s2, (slen) * sizeof(wchar_t))
#define _tcsncpy(s1, s2, slen)	memcpy(s1, s2, (slen) * sizeof(wchar_t))

// inetsrv\iis\config\src\complib\inc\tigger.h
#define I1_COLUMN(Name)		__COLUMN(L"tinyint", sizeof(char), Name, DBTYPE_I1)
#define UI1_COLUMN(Name)	__COLUMN(L"unsigned tinyint", sizeof(unsigned char), Name, DBTYPE_UI1)

// inetsrv\iis\config\src\complib\inc\utilcode.h
#define MAKE_FULLY_QUALIFIED_NAME(pszFullyQualifiedName, pszNameSpace, pszName) \
{ \
	pszFullyQualifiedName = (char*) _alloca((strlen(pszName) + strlen(pszNameSpace) + 2) * sizeof(char)); \
	if (pszFullyQualifiedName) { \
	strcpy(pszFullyQualifiedName,pszNameSpace); \
	strcat(pszFullyQualifiedName,"/"); \
	strcat(pszFullyQualifiedName,pszName); \
	} \
}

// inetsrv\iis\config\src\inc\corhdr.h
#define IsTdAbstract(x)                     ((x) & tdAbstract)
#define IsTdContextful(x)                   ((x) & tdContextful)
#define IsMdAbstract(x)                     ((x) & mdAbstract)
#define IsMdInstanceInitializer(x, str)     (((x) & mdRTSpecialName) && !strcmp((str), COR_CTOR_METHOD_NAME))
#define IsMdInstanceInitializerW(x, str)    (((x) & mdRTSpecialName) && !wcscmp((str), COR_CTOR_METHOD_NAME_W))
#define IsPmCharSetAnsi(x)                  ((x) & pmCharSetAnsi)
#define IsPmCharSetUnicode(x)               ((x) & pmCharSetUnicode)
#define IsPmCharSetAuto(x)                  ((x) & pmCharSetAuto)
#define IsPmCharSetNotSpec(x)               (!IsPmCharSetAnsi(x) && !IsPmCharSetUnicode(x) && !IsPmCharSetAuto(x))

// inetsrv\iis\config\src\wmi\atl30\atlcom.h
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

// inetsrv\iis\config\src\wmi\atl30\atlconv.h
	#define A2W(lpa) (\
		((_lpa = lpa) == NULL) ? NULL : (\
			_convert = (lstrlenA(_lpa)+1),\
			ATLA2WHELPER((LPWSTR) alloca(_convert*2), _lpa, _convert, _acp)))
	#define A2W(lpa) (\
		((_lpa = lpa) == NULL) ? NULL : (\
			_convert = (lstrlenA(_lpa)+1),\
			ATLA2WHELPER((LPWSTR) alloca(_convert*2), _lpa, _convert)))
	#define W2A(lpw) (\
		((_lpw = lpw) == NULL) ? NULL : (\
			_convert = (lstrlenW(_lpw)+1)*2,\
			ATLW2AHELPER((LPSTR) alloca(_convert), _lpw, _convert, _acp)))
	#define W2A(lpw) (\
		((_lpw = lpw) == NULL) ? NULL : (\
			_convert = (lstrlenW(_lpw)+1)*2,\
			ATLW2AHELPER((LPSTR) alloca(_convert), _lpw, _convert)))
#define TEXTMETRICW2A(lptmw)\
	((lptmw == NULL) ? NULL : ATLTEXTMETRICW2A((LPTEXTMETRICA)alloca(sizeof(TEXTMETRICA)), lptmw))
#define TEXTMETRICA2W(lptma)\
	((lptma == NULL) ? NULL : ATLTEXTMETRICA2W((LPTEXTMETRICW)alloca(sizeof(TEXTMETRICW)), lptma))

// inetsrv\iis\iisrearc\core\common\dtext\heap.h
#define HEAP_GRANULARITY            ((LONG) sizeof( HEAP_ENTRY ))

// inetsrv\iis\iisrearc\core\common\dtext\lkrcust.h
 #define LKR_EXTN_DECLARE(_TableStr, _Fn_LKHT_Dump, _Fn_LKLH_Dump, _Fn_Record_Dump) \
        { #_TableStr, sizeof(#_TableStr)-1, _Fn_LKHT_Dump, _Fn_LKLH_Dump, _Fn_Record_Dump },

// inetsrv\iis\iisrearc\core\common\dtext\precomp.hxx
# define DEFINE_CPP_VAR( className, classVar) \
   CHAR  classVar[sizeof(className)]

// inetsrv\iis\iisrearc\core\common\dtext\vm.cxx
#define CCH_ULONG_COMMAS    sizeof("4,294,967,296")

// inetsrv\iis\iisrearc\core\common\ipm\dtumessage.hxx
#define IPM_TEST_DATALEN    ((wcslen(IPM_TEST_DATA) + 1) * sizeof(WCHAR))

// inetsrv\iis\iisrearc\core\common\util\stringa.cxx
#define HEXDIGIT( nDigit )                              \
     (CHAR)((nDigit) > 9 ?                              \
          (nDigit) - 10 + 'A'                           \
        : (nDigit) + '0')

// inetsrv\iis\iisrearc\core\inc\locks.h
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

// inetsrv\iis\iisrearc\core\inc\multisz.hxx
#define STACK_MULTISZ( name, size )     WCHAR __ach##name[size]; \
                                    MULTISZ name( __ach##name, sizeof( __ach##name ))

// inetsrv\iis\iisrearc\core\inc\multisza.hxx
#define STACK_MULTISZA(name, size) CHAR __ach##name[size]; \
                                   MULTISZA name(__ach##name, sizeof(__ach##name))

// inetsrv\iis\iisrearc\core\inc\string.hxx
#define STACK_STRU( name, size )  WCHAR __ach##name[size]; \
                                  STRU name( __ach##name, sizeof( __ach##name ))
#define ISWHITEW( wch )       ((wch) == L' ' || (wch) == L'\t' || (wch) == L'\r')

// inetsrv\iis\iisrearc\core\inc\stringa.hxx
#define ISWHITE( ch )       ((ch) == L'\t' || (ch) == L' ' || (ch) == L'\r')
#define ISWHITEA( ch )      ((ch) == '\t' || (ch) == ' ' || (ch) == '\r')
#define STACK_STRA(name, size)  CHAR __ach##name[size]; \
                                STRA  name( __ach##name, sizeof( __ach##name ))

// inetsrv\iis\iisrearc\core\wp\modules\static\dirlist.cxx
#define HEXDIGIT( nDigit )                              \
    (CHAR)((nDigit) > 9 ?                              \
          (nDigit) - 10 + 'A'                           \
        : (nDigit) + '0')

// inetsrv\iis\iisrearc\core\wp\ulsim\httptypes.h
#define UPCASE_CHAR(c)  ((c) & 0xdf)

// inetsrv\iis\iisrearc\iisplus\odbc\odbcreq.cxx
#define COMP_FIELD( pchName, pchField, cch )  ((toupper(*(pchName)) == \
                                              toupper(*(pchField))) && \
                              !_strnicmp( (pchName), (pchField), (cch)))
#define HEXDIGIT( nDigit )                              \
     (CHAR)((nDigit) > 9 ?                              \
          (nDigit) - 10 + 'A'                           \
        : (nDigit) + '0')
    #define SEND_DATA2( pchData, cbData )  SendData( pfnCallback,  \
                                                    pvContext,     \
                                                    (pchData),     \
                                                    (cbData),      \
                                                    &_pbufOut,     \
                                                    pcbOut )

// inetsrv\iis\iisrearc\iisplus\ulw3\certcontext.hxx
#define HEX_DIGIT( nDigit )                             \
    (WCHAR)((nDigit) > 9 ?                              \
          (nDigit) - 10 + L'a'                          \
        : (nDigit) + L'0')

// inetsrv\iis\iisrearc\iisplus\ulw3\requestheaderhash.h
#define HEADER(x)           x, sizeof(x) - sizeof(CHAR)

// inetsrv\iis\iisrearc\iisplus\ulw3\w3response.hxx
#define REASON(x)        (x),sizeof(x)-sizeof(CHAR)

// inetsrv\iis\iisrearc\ul\drv\httptypes.h
#define UPCASE_CHAR(c)  ((c) & 0xdf)
#define LOCASE_CHAR(c)  ((c) | ~0xdf)

// inetsrv\iis\iisrearc\ul\drv\misc.h
#define GET_CONTROL_CHANNEL( pFileObject )                                  \
    ((PUL_CONTROL_CHANNEL)((pFileObject)->FsContext))
#define GET_PP_CONTROL_CHANNEL( pFileObject )                               \
    ((PUL_CONTROL_CHANNEL *)&((pFileObject)->FsContext))
#define GET_FILTER_PROCESS( pFileObject )                                   \
    ((PUL_FILTER_PROCESS)((pFileObject)->FsContext))
#define GET_PP_FILTER_PROCESS( pFileObject )                                \
    ((PUL_FILTER_PROCESS *)&((pFileObject)->FsContext))
#define GET_APP_POOL_PROCESS( pFileObject )                                 \
    ((PUL_APP_POOL_PROCESS)((pFileObject)->FsContext))
#define GET_PP_APP_POOL_PROCESS( pFileObject )                              \
    ((PUL_APP_POOL_PROCESS *)&((pFileObject)->FsContext))

// inetsrv\iis\iisrearc\ul\drv\thrdpool.h
#define UL_WORK_ITEM_FROM_IRP( _irp )                                  \
        (PUL_WORK_ITEM)&((_irp)->Tail.Overlay.DriverContext[1])
#define UL_WORK_ITEM_FROM_IRP( _irp )                                  \
        (PUL_WORK_ITEM)&((_irp)->Tail.Overlay.DriverContext[0])

// inetsrv\iis\iisrearc\ul\test\dll\precomp.h
#define INIT_HEADER( resp, ndx, str )                                       \
    do                                                                      \
    {                                                                       \
        (resp)->Headers.pKnownHeaders[ndx].pRawValue = (str);               \
        (resp)->Headers.pKnownHeaders[ndx].RawValueLength =                 \
            sizeof(str) - sizeof(CHAR);                                     \
    } while (FALSE)

// inetsrv\iis\iisrearc\ul\win9x\src\listener\listener.h
#define LISTENER_STR_UL_ERROR(x)\
	(\
	x==UlError?"UlError":\
	x==UlErrorVerb?"UlErrorVerb":\
	x==UlErrorUrl?"UlErrorUrl":\
	x==UlErrorHeader?"UlErrorHeader":\
	x==UlErrorHost?"UlErrorHost":\
	x==UlErrorCRLF?"UlErrorCRLF":\
	x==UlErrorNum?"UlErrorNum":\
	x==UlErrorVersion?"UlErrorVersion":\
	x==UlErrorUnavailable?"UlErrorUnavailable":\
	x==UlErrorNotFound?"UlErrorNotFound":\
	x==UlErrorContentLength?"UlErrorContentLength":\
	x==UlErrorEntityTooLarge?"UlErrorEntityTooLarge":\
	x==UlErrorNotImplemented?"UlErrorNotImplemented":\
	"UlErrorUNDEFINED"\
	)

// inetsrv\iis\iisrearc\ulrtl\httptypes.h
#define UPCASE_CHAR(c)  ((c) & 0xdf)

// inetsrv\iis\iisrearc\ulrtl\misc.h
#define GET_CONTROL_CHANNEL( pFileObject )                                  \
    ((PUL_CONTROL_CHANNEL)((pFileObject)->FsContext))
#define GET_PP_CONTROL_CHANNEL( pFileObject )                               \
    ((PUL_CONTROL_CHANNEL *)&((pFileObject)->FsContext))
#define GET_APP_POOL_PROCESS( pFileObject )                                 \
    ((PUL_APP_POOL_PROCESS)((pFileObject)->FsContext))
#define GET_PP_APP_POOL_PROCESS( pFileObject )                              \
    ((PUL_APP_POOL_PROCESS *)&((pFileObject)->FsContext))

// inetsrv\iis\inc\locks.h
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

// inetsrv\iis\inc\multisz.hxx
#define STACK_MULTISZ( name, size )     CHAR __ach##name[size]; \
                                    MULTISZ name( __ach##name, sizeof( __ach##name ))

// inetsrv\iis\inc\string.hxx
#define ISWHITE( ch )       ((ch) == L'\t' || (ch) == L' ' || (ch) == L'\r')
#define ISWHITEA( ch )      ((ch) == '\t' || (ch) == ' ' || (ch) == '\r')
#define STACK_STR( name, size )     \
            CHAR __ach##name[size]; \
            STR name( __ach##name, sizeof( __ach##name ))

// inetsrv\iis\qfetools\spiisupd\spiisupd.cpp
#define MATCHED( BadText )                                              \
                                                                        \
    (( LineLength == strlen( BadText )) &&                            \
     ( strncmp( LineStart, BadText, strlen( BadText )) == 0 ))        \

// inetsrv\iis\setup\osrc\strfn.h
#define AllocMemByType(citems, type)\
    (type *)AllocMem(citems * sizeof(type))
#define AllocTString(cch)\
    (LPTSTR)AllocMem((cch) * sizeof(TCHAR))
#define AllocWString(cch)\
    (LPWSTR)AllocMem((cch) * sizeof(WCHAR))

// inetsrv\iis\staxinc\dns.h
#define QUESTION_NAME_FROM_HEADER( _header_ ) \
            ( (PCHAR)( (PDNS_HEADER)(_header_) + 1 ) )
#define ANSWER_FROM_QUESTION( _question_ ) \
            ( (PCHAR)( (PDNS_QUESTION)(_question_) + 1 ) )

// inetsrv\iis\staxinc\dnsapi.h
#define DNS_RRSET_INIT( rrset )                 \
        {                                       \
            PDNS_RRSET  _prrset = &(rrset);     \
            _prrset->pFirstRR = NULL;           \
            _prrset->pLastRR = (PDNS_RECORD) &_prrset->pFirstRR; \
        }
#define DNS_RRSET_ADD( rrset, pnewRR )          \
        {                                       \
            PDNS_RRSET  _prrset = &(rrset);     \
            PDNS_RECORD _prrnew = (pnewRR);     \
            _prrset->pLastRR->pNext = _prrnew;  \
            _prrset->pLastRR = _prrnew;         \
        }

// inetsrv\iis\svcs\cmp\webdav\_xml\_xml.h
#define CbSizeWsz(_cch)		(((_cch) + 1) * sizeof(WCHAR))

// inetsrv\iis\svcs\cmp\webdav\inc\ex\calcom.h
#define CbSizeWsz(_cch)		(((_cch) + 1) * sizeof(WCHAR))

// inetsrv\iis\svcs\cmp\webdav\inc\ex\sz.h
#define IanaItem(_sz)							\
	DEC_CONST WCHAR gc_wszProp_iana_##_sz[] =	\
		L"DAV:" L#_sz;							\
#define BizItem(_sz)							\
	DEC_CONST WCHAR gc_wszProp_iana_##_sz[] =	\
		L"http://www.bizprop.com/" L#_sz;		\

// inetsrv\iis\svcs\cmp\webdav\inc\exo.h
#define INTERFACE_MAP_EX(_cl, _iid, _intf)			\
	{ (LPIID) & _iid, EXODbCastTo(_cl, EXO, _intf), EXODbCastFrom(_cl, EXO, _intf), TEXT(# _intf) }

// inetsrv\iis\svcs\iisrtl\string.cxx
#define HEXDIGIT( nDigit )                              \
    (TCHAR)((nDigit) > 9 ?                              \
          (nDigit) - 10 + 'A'                           \
        : (nDigit) + '0')

// inetsrv\iis\svcs\infocomm\common\iissvc.cxx
#define LM_PREFIX_CCH           sizeof(LM_PREFIX) - sizeof(CHAR)

// inetsrv\iis\svcs\infocomm\dcomadm\dll\admacl.hxx
#define ISPATHDELIMW(a) ((a)==(WCHAR)'/' || (a)==(WCHAR)'\\')

// inetsrv\iis\svcs\infocomm\festrcnv\fechrcnv.h
#define SJISISKANJI(c) ( ( (UCHAR)(c) >= 0x81 && (UCHAR)(c) <= 0x9f ) || \
                         ( (UCHAR)(c) >= 0xe0 && (UCHAR)(c) <= 0xfc ) )
#define SJISISKANA(c) ( (UCHAR)(c) >= 0xa1 && (UCHAR)(c) <= 0xdf )

// inetsrv\iis\svcs\infocomm\kisfecnv\fechrcnv.h
#define SJISISKANJI(c) ( ( (UCHAR)(c) >= 0x81 && (UCHAR)(c) <= 0x9f ) || \
                         ( (UCHAR)(c) >= 0xe0 && (UCHAR)(c) <= 0xfc ) )
#define SJISISKANA(c) ( (UCHAR)(c) >= 0xa1 && (UCHAR)(c) <= 0xdf )

// inetsrv\iis\svcs\irtl\httphdr\httphdr.cxx
# define HfmHeader( HfmId, HfmString)  { HfmString, (sizeof( HfmString) - 1) },

// inetsrv\iis\svcs\irtl\iiscrypt\lib\icryptp.h
#define UpdateHashDestroyed() InterlockedIncrement( &IcpCounters.HashDestroyed )

// inetsrv\iis\svcs\loadbal\cmdline\iislbc.cxx
#define RC_PRINTF(a,b) if ( LoadStringW( NULL, a, achMsg, sizeof(achMsg) ) ) wprintf b;

// inetsrv\iis\svcs\loadbal\pdh\perfdata.h
#define FirstInstance(pObjectDef) \
    (PERF_INSTANCE_DEFINITION *)((PCHAR) pObjectDef + pObjectDef->DefinitionLength)

// inetsrv\iis\svcs\smtp\aqueue\inc\hshroute.h
#define ROUTE_HASH_CHARS_IN_GUID    (2*sizeof(GUID))

// inetsrv\iis\svcs\smtp\inc\route.h
#define rtxnameDistListAll              ( \
                                        rtxnameDistListNormal | \
                                        rtxnameDistListExtended | \
                                        rtxnameDistListSite | \
                                        rtxnameDistListDomain \
                                        )

// inetsrv\iis\svcs\staxcore\domhash\_domhash.h
#define DOMHASH_TO_UPPER(mychar) \
    ((mychar) < 'a')   ? (mychar) \
                       : (((mychar) <= 'z') \
                       ? ((mychar) - 'a' + 'A') : mychar)

// inetsrv\iis\svcs\staxcore\seo\events.cpp
#define DW2W(x) _itow(x,(LPWSTR) _alloca(11*sizeof(WCHAR)),10)

// inetsrv\iis\svcs\staxcore\seo\seo.cpp
#define DW2W(x) _itow(x,(LPWSTR) _alloca(11*sizeof(WCHAR)),10)

// inetsrv\iis\svcs\staxcore\seo\subdict.cpp
#define _ALLOC_NAME_A(prefix,suffix)	(LPSTR) _alloca((strlen((prefix))+strlen((suffix))+1)*sizeof(CHAR))
#define _ALLOC_NAME_W(prefix,suffix)	(LPWSTR) _alloca((wcslen((prefix))+wcslen((suffix))+1)*sizeof(WCHAR))

// inetsrv\iis\svcs\w3\filters\compress\inc\compfilt.h
#define GET_COMPFILT_CONTEXT( pfc )                                \
    ( ( ( (pfc)->pFilterContext == COMPFILT_SUCCESSFUL_STATIC ) || \
        ( (pfc)->pFilterContext == COMPFILT_NO_COMPRESSION ) || \
        ( (pfc)->pFilterContext == COMPFILT_URLMAP_DONE ) ) ? NULL : \
      (pfc)->pFilterContext )
#define SET_SUCCESSFUL_STATIC( pfc )                               \
    {  (pfc)->pFilterContext = COMPFILT_SUCCESSFUL_STATIC; }
#define SET_URLMAP_DONE( pfc )                               \
      (pfc)->pFilterContext = COMPFILT_URLMAP_DONE;
#define SET_REQUEST_DONE( pfc )                               \
      (pfc)->pFilterContext = NULL;

// inetsrv\iis\svcs\w3\gateways\odbc\odbcreq.cxx
#define COMP_FIELD( pchName, pchField, cch )  ((toupper(*(pchName)) ==     \
                                                toupper(*(pchField))) &&   \
                                               !_strnicmp( (pchName), (pchField), (cch)))
#define HEXDIGIT( nDigit )                              \
    (TCHAR)((nDigit) > 9 ?                              \
          (nDigit) - 10 + 'A'                           \
        : (nDigit) + '0')
    #define SEND_DATA2( pchData, cbData )  SendData( pfnCallback,  \
                                                    pvContext,     \
                                                    (pchData),     \
                                                    (cbData),      \
                                                    &_pbufOut,     \
                                                    pcbOut )

// inetsrv\iis\svcs\w3\gateways\odbc_oop\odbcreq.cxx
#define COMP_FIELD( pchName, pchField, cch )  ((toupper(*(pchName)) ==     \
                                                toupper(*(pchField))) &&   \
                                               !_strnicmp( (pchName), (pchField), (cch)))
#define HEXDIGIT( nDigit )                              \
    (TCHAR)((nDigit) > 9 ?                              \
          (nDigit) - 10 + 'A'                           \
        : (nDigit) + '0')
    #define SEND_DATA2( pchData, cbData )  SendData( pfnCallback,  \
                                                    pvContext,     \
                                                    (pchData),     \
                                                    (cbData),      \
                                                    &_pbufOut,     \
                                                    pcbOut )

// inetsrv\iis\svcs\w3\server\dirlist.cxx
#define HEXDIGIT( nDigit )                              \
    (TCHAR)((nDigit) > 9 ?                              \
          (nDigit) - 10 + 'A'                           \
        : (nDigit) + '0')

// inetsrv\iis\svcs\w3\server\hgetinfo.cxx
# define IsStringMatch( pszConstant, pszVar, cchVar)  \
     ((cchVar == (sizeof( pszConstant) - 1)) && \
      !strcmp( pszConstant, pszVar)             \
      )
# define IsStringPrefixMatch( pszConstantPrefix, pszVar, cchVar)  \
     ((cchVar >= (sizeof( pszConstantPrefix) - 1)) && \
      !memcmp( pszConstantPrefix, pszVar, (sizeof(pszConstantPrefix) - 1))\
      )

// inetsrv\iis\svcs\w3\server\strconst.h
# define ConstantStringsForThisModule()           \
CStrM( ENDING_CRLF, "\r\n")                       \
CStrM( CONTENT_TYPE_END_HEADER, "Content-Type: text/html\r\n\r\n") \
CStrM( HTTP_VERSION_STR, "HTTP/1.0 ")             \
CStrM( HTTP_VERSION_STR11, "HTTP/1.1 ")             \
CStrM( KWD_CONTENT_TYPE, "Content-Type: ")        \
CStrM( KWD_SYSTEM,       "SYSTEM")                \
# define CStrM( FriendlyName, ActualString)   \
       LEN_PSZ_ ## FriendlyName = (sizeof( ActualString) - 1),

// inetsrv\iis\svcs\w3\server\w3cons.hxx
# define STR_CONST( constSTR)   constSTR, (sizeof(constSTR) - 1)
#define APPEND_STRING(a,b)  \
    {memcpy(a,b,sizeof(b));  a += sizeof(b)-sizeof(CHAR);}

// inetsrv\iis\svcs\w3\tests\cmdline\httpcmd.cxx
#define HEXDIGIT( nDigit )                              \
    (TCHAR)((nDigit) > 9 ?                              \
          (nDigit) - 10 + 'A'                           \
          : (nDigit) + '0')

// inetsrv\iis\svcs\wp\inc\clusrtl.h
#define ClRtlInitializeWorkItem(Item, Routine, Ctx)                   \
            ZeroMemory(&((Item)->Overlapped), sizeof(OVERLAPPED));    \
            (Item)->WorkRoutine = (Routine);                          \
            (Item)->Context = (Ctx);

// inetsrv\iis\ui\itools\htmla\ism.hxx
#define HEXDIGIT( nDigit )                              \
    (TCHAR)((nDigit) > 9 ?                              \
          (nDigit) - 10 + 'A'                           \
        : (nDigit) + '0')

// inetsrv\iis\utils\terrain\tools\perms\perms.h
#define FirstAce(Acl) ((PVOID)((PUCHAR)(Acl) + sizeof(ACL)))

// inetsrv\msmq\published\inc\mq.h
#define MQMSG_ACKNOWLEDGMENT_FULL_REACH_QUEUE ((UCHAR)( \
            MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL |  \
            MQMSG_ACKNOWLEDGMENT_POS_ARRIVAL ))
#define MQMSG_ACKNOWLEDGMENT_NACK_RECEIVE ((UCHAR)( \
            MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL |  \
            MQMSG_ACKNOWLEDGMENT_NEG_RECEIVE ))
#define MQMSG_ACKNOWLEDGMENT_FULL_RECEIVE ((UCHAR)( \
            MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL |  \
            MQMSG_ACKNOWLEDGMENT_NEG_RECEIVE |  \
            MQMSG_ACKNOWLEDGMENT_POS_RECEIVE ))

// inetsrv\msmq\sdk\samples\mqtestoa\mqtestoa.cpp
#define PRINTERROR(s, hr) { PrintError(s, hr); goto Cleanup; }

// inetsrv\msmq\src\ac\win95\ntddk95.h
#define READ_REGISTER_BUFFER_UCHAR(x, y, z) {                           \
    PUCHAR registerBuffer = x;                                          \
    PUCHAR readBuffer = y;                                              \
    ULONG readCount;                                                    \
    for (readCount = z; readCount--; readBuffer++, registerBuffer++) {  \
        *readBuffer = *(volatile UCHAR * const)(registerBuffer);        \
    }                                                                   \
}
#define WRITE_REGISTER_BUFFER_UCHAR(x, y, z) {                            \
    PUCHAR registerBuffer = x;                                            \
    PUCHAR writeBuffer = y;                                               \
    ULONG writeCount;                                                     \
    for (writeCount = z; writeCount--; writeBuffer++, registerBuffer++) { \
        *(volatile UCHAR * const)(registerBuffer) = *writeBuffer;         \
    }                                                                     \
    KeFlushWriteBuffer();                                                 \
}
#define READ_PORT_BUFFER_UCHAR(x, y, z) {                             \
    PUCHAR readBuffer = y;                                            \
    ULONG readCount;                                                  \
    for (readCount = 0; readCount < z; readCount++, readBuffer++) {   \
        *readBuffer = *(volatile UCHAR * const)(x);                   \
    }                                                                 \
}
#define WRITE_PORT_BUFFER_UCHAR(x, y, z) {                                \
    PUCHAR writeBuffer = y;                                               \
    ULONG writeCount;                                                     \
    for (writeCount = 0; writeCount < z; writeCount++, writeBuffer++) {   \
        *(volatile UCHAR * const)(x) = *writeBuffer;                      \
        KeFlushWriteBuffer();                                             \
    }                                                                     \
}
#define READ_REGISTER_BUFFER_UCHAR(x, y, z) {                           \
    PUCHAR registerBuffer = x;                                          \
    PUCHAR readBuffer = y;                                              \
    ULONG readCount;                                                    \
    for (readCount = z; readCount--; readBuffer++, registerBuffer++) {  \
        *readBuffer = *(volatile UCHAR * const)(registerBuffer);        \
    }                                                                   \
}
#define WRITE_REGISTER_BUFFER_UCHAR(x, y, z) {                            \
    PUCHAR registerBuffer = x;                                            \
    PUCHAR writeBuffer = y;                                               \
    ULONG writeCount;                                                     \
    for (writeCount = z; writeCount--; writeBuffer++, registerBuffer++) { \
        *(volatile UCHAR * const)(registerBuffer) = *writeBuffer;         \
    }                                                                     \
    KeFlushWriteBuffer();                                                 \
}
#define READ_PORT_BUFFER_UCHAR(x, y, z) {                             \
    PUCHAR readBuffer = y;                                            \
    ULONG readCount;                                                  \
    for (readCount = 0; readCount < z; readCount++, readBuffer++) {   \
        *readBuffer = *(volatile UCHAR * const)(x);                   \
    }                                                                 \
}
#define WRITE_PORT_BUFFER_UCHAR(x, y, z) {                                \
    PUCHAR writeBuffer = y;                                               \
    ULONG writeCount;                                                     \
    for (writeCount = 0; writeCount < z; writeCount++, writeBuffer++) {   \
        *(volatile UCHAR * const)(x) = *writeBuffer;                      \
        KeFlushWriteBuffer();                                             \
    }                                                                     \
}
#define ExInitializeWorkItem(Item, Routine, Context) \
    (Item)->WorkerRoutine = (Routine);               \
    (Item)->Parameter = (Context);                   \
    (Item)->List.Flink = NULL;
#define ExIsObjectInFirstZoneSegment(Zone,Object) ((BOOLEAN)     \
    (((PUCHAR)(Object) >= (PUCHAR)(Zone)->SegmentList.Next) &&   \
     ((PUCHAR)(Object) < (PUCHAR)(Zone)->SegmentList.Next +      \
                         (Zone)->TotalSegmentSize))              \
)
#define IoRequestDpc( DeviceObject, Irp, Context ) ( \
    KeInsertQueueDpc( &(DeviceObject)->Dpc, (Irp), (Context) ) )

// inetsrv\msmq\src\apps\mqdiag\mqping\sim.h
#define Msg_RESP_QUEUE(pMsgDsc)	\
	(WCHAR *)((pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_RESP_QUEUE] ].pwszVal)
#define Msg_SENDER_CERT(pMsgDsc)	\
	(UCHAR *)((pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_SENDER_CERT] ].caub.pElems)
#define Msg_DEST_QUEUE(pMsgDsc)	\
	(WCHAR *)((pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_DEST_QUEUE] ].pwszVal)
#define Msg_DEST_SYMM_KEY(pMsgDsc)	\
	(UCHAR *)((pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_DEST_SYMM_KEY] ].caub.pElems)
#define Msg_SIGNATURE(pMsgDsc)	\
	(UCHAR *)((pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_SIGNATURE] ].caub.pElems)
#define Msg_PROV_NAME(pMsgDsc)	\
	(WCHAR *)((pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_PROV_NAME] ].pwszVal)

// inetsrv\msmq\src\inc\mqprops.h
#define MQMSG_ACKNOWLEDGMENT_FULL_REACH_QUEUE ((UCHAR)( \
            MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL |  \
            MQMSG_ACKNOWLEDGMENT_POS_ARRIVAL ))
#define MQMSG_ACKNOWLEDGMENT_NACK_RECEIVE ((UCHAR)( \
            MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL |  \
            MQMSG_ACKNOWLEDGMENT_NEG_RECEIVE ))
#define MQMSG_ACKNOWLEDGMENT_FULL_RECEIVE ((UCHAR)( \
            MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL |  \
            MQMSG_ACKNOWLEDGMENT_NEG_RECEIVE |  \
            MQMSG_ACKNOWLEDGMENT_POS_RECEIVE ))

// inetsrv\msmq\src\qm\depclient.cpp
#define  _CONTEXT_TO_HANDLE(pContext) \
                    (((RPC_QUEUE_CONTEXT*)pContext)->hQueue)
#define  _CONTEXT_TO_LICENSE(pContext) \
                    (((RPC_QUEUE_CONTEXT*)pContext)->LicGuid)
#define  _CONTEXT_TO_QM_CONTEXT_MAPPED(pContext) \
                    (((RPC_QUEUE_CONTEXT*)pContext)->dwQMContextMapped)

// inetsrv\msmq\src\trigger\include\stdfuncs.hpp
#define REGKEY_STRING_BUFFER_SIZE 128 * sizeof(TCHAR)

// inetsrv\query\filters\html\source\errorlst.rc
#define MAKE_IR_ERROR( err, sev, src, val, str) ((src)|(val))        str        \
                                            (0x8000|(src)|(val))        #err

// inetsrv\query\filters\office\src\findfast\dmifmtdo.c
#define UPCASE(c) ((((c) >= 'a') && ((c) <= 'z')) ? ((char)((c) - 32)) : (c))
#define LCCASE(c) ((((c) >= 'A') && ((c) <= 'Z')) ? ((char)((c) + 32)) : (c))

// inetsrv\query\filters\office\src\findfast\dmippst2.c
#define STREAM_ACCESS  (STGM_SHARE_EXCLUSIVE | STGM_DIRECT | STGM_READ)

// inetsrv\query\filters\office\src\findfast\dmixlp.h
#define IsDataRecord(x) \
   ((x == LABEL)      || (x == RK)         || (x == NUMBER)     || \
    (x == MULRK)      || (x == MULBLANK)   || (x == BLANK)      || \
    (x == BOOLERR)    || (x == RSTRING)    || (x == LABEL_V8)   || \
    (x == FORMULA_V3) || (x == FORMULA_V4) || (x == FORMULA_V5) || \
    (x == STRING)     || (x == ARRAY)      || (x == SHRFMLA))
#define IsCellRecord(x) \
   ((x == BLANK)      || (x == RK)         || (x == NUMBER)     || \
    (x == LABEL)      || (x == RSTRING)    || (x == BOOLERR)    || \
    (x == MULBLANK)   || (x == MULRK)      || (x == LABEL_V8)   || \
    (x == FORMULA_V3) || (x == FORMULA_V4) || (x == FORMULA_V5))

// inetsrv\query\filters\office\src\findfast\dmixlrd.c
#define CanBeContinued(x) \
        ((x == ARRAY)      || (x == NOTE)          || (x == IMDATA) || \
         (x == EXTERNNAME) || (x == EXTERNNAME_V5) || (x == OBJ)    || \
         (x == NAME)       || (x == NAME_V5)       || (x == STRING) || \
         (x == FORMULA_V3) || (x == FORMULA_V4)    || (x == FORMULA_V5) || \
         (x == TXO_V8))

// inetsrv\query\filters\office\src\findfast\dmixlst2.c
#define PUT_OVERHEAD (sizeof(PutSeparator) - sizeof(TCHAR))
#define BufferWillOverflow(cbText) \
       ((pFile->cbBufferSize - pFile->cbBufferUsed) < ((cbText) + PUT_OVERHEAD))
#define BufferWillOverflow2(cbText) \
       ((pFile->cbBufferSize - pFile->cbBufferUsed) < ((cbText) + (PUT_OVERHEAD * 2)))

// inetsrv\query\filters\office\src\findfast\dmubdst2.c
#define STREAM_ACCESS  (STGM_SHARE_EXCLUSIVE | STGM_DIRECT | STGM_READ)
#define PUT_OVERHEAD (sizeof(PutSeparator) - sizeof(TCHAR))

// inetsrv\query\filters\office\src\findfast\dmwinutl.c
   #define CopyToDest(dest, source, cchDestRemain) \
      if (cchDestRemain > 0) {                     \
         *dest++ = *source;                        \
         cchDestRemain--;                          \
      }

// inetsrv\query\h\ciexcpt.hxx
#define CATCH(class, e)                                                  \
        __except( Unwind( GetExceptionInformation(), &_trycontext ) )      \
        {                                                                \
            CExceptionContext& _exceptioncontext = _ExceptionContext();  \
            if (_exceptioncontext._exception.IsKindOf(#class))           \
            {                                                            \
                class & e = (class &)_exceptioncontext._exception;
#define AND_CATCH(class, e)                                                 \
            }                                                               \
            else if (_exceptioncontext._exception.IsKindOf(#class))         \
            {                                                               \
                class & e = ( class &)_exceptioncontext._exception;

// inetsrv\query\h\strres.hxx
#define STRINGRESOURCE( sr ) (WCHAR *)&sr

// inetsrv\query\qutil\h\scanner.hxx
#define PHRASE_STR  L"{}!&|~*@#$()[],=<>\n\"^"
#define CMND_STR    L"{}!&|~*@#()[],=<> \t\n\""
#define REGEX_STR   L"&|~()[], \n"
#define COLUMN_STR    L"{}!&|~*@#()[],=<>+%$^{}:;'./?\\` \t\n\""

// inetsrv\query\qutil\triplish\lex.cxx
#define YY_READ_BUF_SIZE (8192 / sizeof(WCHAR))

// inetsrv\query\restrict\stgvar.cxx
#define VECTOR_SET_BODY( type, vtype )                                    \
                                                                          \
void CStorageVariant::Set##vtype (                                        \
    type val,                                                             \
    unsigned pos )                                                        \
{                                                                         \
    CAllocStorageVariant::Set##vtype( val, pos, CoTaskAllocator );        \
}

// inetsrv\query\sqltext\mssqllex.cpp
#define yy_set_bol(at_bol) \
        { \
        if ( ! yy_current_buffer ) \
                yy_current_buffer = yy_create_buffer( YY_BUF_SIZE ); \
        yy_current_buffer->yy_at_bol = at_bol; \
        }
#define YY_READ_BUF_SIZE (8192 / sizeof(TCHAR))

// inetsrv\query\sqltext\mssqltab.cpp
#define IsLeapYear(yrs) (                       \
    (((yrs) % 400 == 0) ||                      \
     ((yrs) % 100 != 0) && ((yrs) % 4 == 0)) ?  \
        TRUE                                    \
    :                                           \
        FALSE                                   \
    )
#define DaysInMonth(YEAR,MONTH) (   \
    IsLeapYear(YEAR) ?              \
        LeapDays[(MONTH)]  :        \
        Days[(MONTH)]               \
    )

// inetsrv\query\tdbv1\tdbv1.cxx
#define PROP2_cb ( ( sizeof WCHAR ) * ( wcslen(PROP2_VAL) ) )
#define PROP3_cb ( ( sizeof WCHAR ) * ( wcslen(PROP3_VAL) ) )
#define PROP10_cb ( ( sizeof WCHAR ) * (wcslen(PROP10_VAL) ) )
#define PROP13_cb ( sizeof char )
#define DBTYPE_BRWSTR ( DBTYPE_BYREF | DBTYPE_WSTR )

// mergedcomponents\advapi32\sddl.c
#define STRING_GUID_SIZE  ( STRING_GUID_LEN * sizeof( WCHAR ) )
#define SDDL_SIZE_TAG( tagdef )  ( wcslen( tagdef ) * sizeof( WCHAR ) )
#define SDDL_SIZE_SEP( sep ) (sizeof( WCHAR ) )

// net\1394\arp\sys\priv.h
#define ARP_FASTREADLOCK_IF_SEND_LOCK(_pIF) \
        NdisAcquireSpinLock(&(_pIF)->sendinfo.Lock.OsLock)
#define ARP_OUR_CTXT_FROM_RCE(_pRCE) \
                ((ARP_RCE_CONTEXT*)  &(_pRCE)->rce_context)

// net\1394\arp\sys\rm.h
#define RM_PEND_CODE(_pTask)                \
            ((_pTask)->SuspendContext)

// net\atm\arp\atmarpc\arppkt.h
#define AA_PKT_ATM_ADDRESS_TO_TYPE_LEN(pAtmAddress)							\
			((UCHAR)((pAtmAddress)->NumberOfDigits) |						\
				(((pAtmAddress)->AddressType == ATM_E164) ? 				\
						AA_PKT_ATM_ADDRESS_E164 : AA_PKT_ATM_ADDRESS_NSAP))

// net\atm\arp\atmarpc\macros.h
#define AA_MEM_CMP(pString1, pString2, Length)	\
			AtmArpMemCmp((PUCHAR)(pString1), (PUCHAR)(pString2), (ULONG)(Length))

// net\atm\epvc\sys\rm.h
#define RM_PEND_CODE(_pTask)                \
            ((_pTask)->SuspendContext)

// net\atm\samples\atmsmpl\app\atmsmapp.h
#define CharToHex(c, ucRet) {                       \
                                                    \
    if(c >= '0' && c <= '9')                        \
        ucRet = (UCHAR)(c - '0');                   \
    else                                            \
        if(c >= 'A' && c <= 'F')                    \
            ucRet = (UCHAR)(10 + (c - 'A'));        \
        else                                        \
            if(c >= 'a' && c <= 'f')                \
                ucRet = (UCHAR)(10 + (c - 'a'));    \
            else                                    \
                ucRet = (UCHAR)-1;                  \
                                                    \
}

// net\atm\winsock\wshatm.c
#define DIGIT_TO_WCHAR(_Value)          \
                        (((_Value) > 9)? (L'A' + (WCHAR)((_Value) - 10)) :      \
                                                         (L'0' + (WCHAR)((_Value) - 0 )))

// net\config\shell\folder\traymsgs.h
#define MYWM_SHOWBALLOON        (WM_USER+7) // For update tray-icon text

// net\dhcp\inc\dhcp.h
#define BOOT_FILE_SIZE_W        ( BOOT_FILE_SIZE * sizeof( WCHAR ))
#define BOOT_SERVER_SIZE_W      ( BOOT_SERVER_SIZE * sizeof( WCHAR ))

// net\dhcp\netsh\common\common.c
#define WSTRSIZE( wsz ) ( ( wcslen( wsz ) + 1 ) * sizeof( WCHAR ) )

// net\dhcp\server\binl\binldef.h
#define WSTRSIZE( wsz ) (( wcslen( wsz ) + 1 ) * sizeof( WCHAR ))
#define STRSIZE( sz ) (( strlen( sz ) + 1 ) * sizeof( char ))
#define BOOT_FILE_SIZE_W        ( BOOT_FILE_SIZE * sizeof( WCHAR ))
#define BOOT_SERVER_SIZE_W      ( BOOT_SERVER_SIZE * sizeof( WCHAR ))

// net\dhcp\server\binl\network.c
    #define CLIENTOPTIONSIZE (sizeof(CLIENTOPTIONSTRING) - 1)

// net\dhcp\server\client\dhcpcmd.c
#define WSTRSIZE( wsz ) ( ( wcslen( wsz ) + 1 ) * sizeof( WCHAR ) )

// net\dhcp\server\client\opttest.c
#define WSTRSIZE( wsz ) ( ( wcslen( wsz ) + 1 ) * sizeof( WCHAR ) )

// net\dhcp\server\exim\dbfile.c
#define DB_FUNC(F,I,S) \
{#F, TEXT(#F), #F "@" #S, I, (FARPROC *)& p ## F }

// net\dhcp\server\server\callout.c
#define    CALLOUT_MARK_OPTIONS(P,DhcpOptions) \
WRAPPER(HandleOptions, ((P)->ReqContext.ReceiveBuffer,\
    (P)->ReqContext.ReceiveMessageSize,\
    (P), (LPVOID)((P)->CalloutContext), (DhcpOptions)))

// net\dhcp\server\server\callout.h
#define    CALLOUT_MARK_OPTIONS(P,DhcpOptions) \
WRAPPER(HandleOptions, ((P)->ReqContext.ReceiveBuffer,\
    (P)->ReqContext.ReceiveMessageSize,\
    (P), (LPVOID)((P)->CalloutContext), (DhcpOptions)))

// net\dhcp\server\server\dhcpdef.h
#define WSTRSIZE( wsz ) (( wcslen( wsz ) + 1 ) * sizeof( WCHAR ))
#define STRSIZE( sz ) (( strlen( sz ) + 1 ) * sizeof( char ))

// net\dhcp\server\server\oldstub.c
#define WSTRSIZE( wsz ) (( wcslen( wsz ) + 1 ) * sizeof( WCHAR ))

// net\dhcp\server\upgrade\db.c
#define DB_FUNC(F,I,S) \
{#F, TEXT(#F), #F "@" #S, I, (FARPROC *)& p ## F }

// net\diagnostics\netdiag\tfschar.h
#define CbStrLenA(psz)	((StrLenA(psz)+1)*sizeof(char))
#define CbStrLenW(psz)	((StrLenW(psz)+1)*sizeof(WCHAR))
#define AllocaStrDupA(lpa) (\
	((LPCSTR)lpa == NULL) ? NULL : (\
		StrCpyA((LPSTR) alloca(CbStrLenA(lpa)*2), lpa)))
#define AllocaStrDupW(lpw) (\
	((LPCWSTR)lpw == NULL) ? NULL : (\
		StrCpyW((LPWSTR) alloca(CbStrLenW(lpw)), lpw)))
#define A2W(lpa) (\
	((LPCSTR)lpa == NULL) ? NULL : (\
		_convert = (lstrlenA(lpa)+1),\
		AtlA2WHelper((LPWSTR) alloca(_convert*2), lpa, _convert)))
#define W2A(lpw) (\
	((LPCWSTR)lpw == NULL) ? NULL : (\
		_convert = (lstrlenW(lpw)+1)*2,\
		AtlW2AHelper((LPSTR) alloca(_convert), lpw, _convert)))

// net\dlc\driver\dlcdef.h
#define DereferenceFileContext(pFileContext)                \
    (pFileContext)->ReferenceCount--;                       \
    if ((pFileContext)->ReferenceCount <= 0) {              \
        DlcKillFileContext(pFileContext);                   \
    }
#define DereferenceFileContextByTwo(pFileContext)           \
    (pFileContext)->ReferenceCount -= 2;                    \
    if ((pFileContext)->ReferenceCount <= 0) {              \
        DlcKillFileContext(pFileContext);                   \
    }
#define DereferenceBufferPool(pFileContext) {\
        (pFileContext)->BufferPoolReferenceCount--; \
        if ((pFileContext)->BufferPoolReferenceCount == 0) {\
            BufferPoolDereference( \
                pFileContext, \
                (PDLC_BUFFER_POOL*)&(pFileContext)->hBufferPool); \
        } \
    }
#define DereferenceBufferPool(pFileContext) {\
        (pFileContext)->BufferPoolReferenceCount--; \
        if ((pFileContext)->BufferPoolReferenceCount == 0) {\
            BufferPoolDereference((PDLC_BUFFER_POOL*)&(pFileContext)->hBufferPool); \
        } \
    }

// net\dlc\driver\llcmem.h
#define ALLOCATE_STRING_DRIVER(n) \
    AllocateZeroMemory(&DriverStringUsage, (ULONG)(n))
#define ALLOCATE_MEMORY_FILE(n) \
    AllocateMemory(&pFileContext->MemoryUsage, (ULONG)(n))
#define ALLOCATE_ZEROMEMORY_FILE(n) \
    AllocateZeroMemory(&pFileContext->MemoryUsage, (ULONG)(n))
#define UNLINK_STRING_USAGE(p)      UnlinkMemoryUsage(&(p)->StringUsage)

// net\dlc\driver\llcsm.c
#define DLC_REJ_RESPONSE( a ) uchSendId = \
    (UCHAR)(DLC_REJ_TOKEN | DLC_TOKEN_RESPONSE) | (UCHAR)a
#define DLC_REJ_COMMAND( a ) uchSendId = \
	 (UCHAR)(DLC_REJ_TOKEN | DLC_TOKEN_COMMAND) | (UCHAR)a
#define DLC_RNR_RESPONSE( a ) uchSendId = \
    (UCHAR)(DLC_RNR_TOKEN | DLC_TOKEN_RESPONSE) | (UCHAR)a
#define DLC_RNR_COMMAND( a )  uchSendId = \
    (UCHAR)(DLC_RNR_TOKEN | DLC_TOKEN_COMMAND) | (UCHAR)a
#define DLC_RR_RESPONSE( a )  uchSendId = \
    (UCHAR)(DLC_RR_TOKEN | DLC_TOKEN_RESPONSE) | (UCHAR)a
#define DLC_RR_COMMAND( a )   uchSendId = \
    (UCHAR)(DLC_RR_TOKEN | DLC_TOKEN_COMMAND) | (UCHAR)a
#define DLC_DISC(a)             uchSendId = (UCHAR)DLC_DISC_TOKEN | (UCHAR)a
#define DLC_DM(a)               uchSendId = (UCHAR)DLC_DM_TOKEN | (UCHAR)a
#define DLC_FRMR(a)             uchSendId = (UCHAR)DLC_FRMR_TOKEN | (UCHAR)a
#define DLC_SABME(a)            uchSendId = (UCHAR)DLC_SABME_TOKEN | (UCHAR)a
#define DLC_UA(a)               uchSendId = (UCHAR)DLC_UA_TOKEN | (UCHAR)a

// net\ias\mmc\nap\tregkey.h
#define CbStrLenA(psz)	((StrLenA(psz)+1)*sizeof(char))
#define CbStrLenW(psz)	((StrLenW(psz)+1)*sizeof(WCHAR))

// net\ias\services\inc\iastlutl.h
#define IAS_OCT2ANSI_LEN(oct) \
   (((oct).dwLength + 1) * sizeof(CHAR))
#define IAS_OCT2WIDE_LEN(oct) \
   (((oct).dwLength + 1) * sizeof(WCHAR))

// net\inc\dialinusr.h
#define RAS_ET_AUTO        (RAS_ET_BASIC  | RAS_ET_STRONG | RAS_ET_STRONGEST)

// net\inc\ip.h
#define CLASSD_ADDR(a)      (( (*((uchar *)&(a))) & 0xf0) == 0xe0)
#define RCE_CONTEXT_SIZE    (sizeof(void *) * 2) // Right now we use two contexts.

// net\inc\isnipx.h
#define REQUEST_OPEN_CONTEXT(_Request) \
    (((IoGetCurrentIrpStackLocation(_Request))->FileObject)->FsContext)
#define REQUEST_OPEN_TYPE(_Request) \
    (((IoGetCurrentIrpStackLocation(_Request))->FileObject)->FsContext2)
#define REQUEST_OPEN_CONTEXT_AND_PARAMS(_Request,_OpenContext,_Parameters) { \
    PIO_STACK_LOCATION _IrpSp = IoGetCurrentIrpStackLocation(_Request); \
    *(_OpenContext) = _IrpSp->FileObject->FsContext; \
    *(_Parameters) = (PTDI_REQUEST_KERNEL)(&_IrpSp->Parameters); \
}

// net\inc\stropts.h
#define I_NREAD         (STR|1)
#define I_PUSH          (STR|2)
#define I_POP           (STR|3)
#define I_LOOK          (STR|4)
#define I_FLUSH         (STR|5)
#define I_SRDOPT        (STR|6)
#define I_GRDOPT        (STR|7)
#define I_STR           (STR|8)
#define I_SETSIG        (STR|9)
#define I_GETSIG        (STR|10)
#define I_FIND          (STR|11)
#define I_LINK          (STR|12)
#define I_UNLINK        (STR|13)
#define I_PEEK          (STR|15)
#define I_FDINSERT      (STR|16)
#define I_SENDFD        (STR|17)
#define I_RECVFD        (STR|18)
#define I_GETMSG        (STR|19)
#define I_PUTMSG        (STR|20)
#define I_GETID		(STR|21)
#define I_POLL		(STR|22)
#define	I_SWROPT	(STR|23)
#define	I_GWROPT	(STR|24)
#define	I_LIST		(STR|25)
#define	I_ATMARK	(STR|26)
#define	I_PLINK		(STR|29)
#define	I_PUNLINK	(STR|30)
#define FLUSHRW		(FLUSHR | FLUSHW)

// net\irda\irsir\actisys.c
        #define MAKECASE(speed) \
            case speed: SetSpeedString = Act200LSetSpeed##speed; SetSpeedStringLength = sizeof(Act200LSetSpeed##speed); break;

// net\irda\irsir\crystal.c
        #define MAKECASE(speed) \
            case speed: SetSpeedString = CrystalSetSpeed##speed; SetSpeedStringLength = sizeof(CrystalSetSpeed##speed); break;

// net\irda\irutil\decdirda.c
#define isprint(c) (((c) >= TEXT(' ')) && ((c) <= 0x7f))

// net\irda\irxfer\ssdp.cpp
    #define W2A(lpw) (\
            ((_lpw = lpw) == NULL) ? NULL : (\
                        _convert = (lstrlenW(_lpw)+1)*2,\
                                    AtlW2AHelper((LPSTR) alloca(_convert), _lpw, _convert, _acp)))

// net\irda\irxfer\util.h
#define CbWsz( sz )           ( (SzLenW(sz)+1)*sizeof(WCHAR) )

// net\irda\irxfer\xfer.h
#define OBEX_PARAM_NAME               ( 0x01 | OBEX_PARAM_UNICODE )
#define OBEX_PARAM_BODY               ( 0x08 | OBEX_PARAM_STREAM  )
#define OBEX_PARAM_BODY_END           ( 0x09 | OBEX_PARAM_STREAM  )
#define OBEX_PARAM_WHO                ( 0x0A | OBEX_PARAM_STREAM  )

// net\jet500\jet\dae\inc\fmp.h
#define DBIDSetExtendingDB( dbid )	( rgfmp[dbid].ffmp |= ffmpExtendingDB )
#define DBIDResetExtendingDB( dbid) ( rgfmp[dbid].ffmp &= ~(ffmpExtendingDB) )

// net\jet500\jet\dae\src\daeutil.c
#define StringKey( sz ) {sizeof( sz )-1, sz}

// net\jet500\jet\dae\src\ver.c
#define FBucketNew(pbucket)                                                                     \
	( (pbucket)->ibNewestRCE == 0 )

// net\jet500\xjet\inc\fdb.h
#define FRECLongValue( coltyp )		\
	( (coltyp) == JET_coltypLongText  ||  (coltyp) == JET_coltypLongBinary )
#define FRECTextColumn( coltyp )	\
	( (coltyp) == JET_coltypText  ||  (coltyp) == JET_coltypLongText )

// net\jet500\xjet\src\convert\conv200.h
#define JET_PARAM( _Param, _IntVal, _StrVal )   \
    { _Param, _IntVal, _StrVal, (( _IntVal || _StrVal ) ? TRUE : FALSE) }

// net\jet500\xjet\src\fcreate.c
#define StringKey( sz ) {sizeof( sz )-1, sz}

// net\jet500\xjet\src\ver.c
#define FBUNew(pbucket)                                                                     \
	( (pbucket)->ibNewestRCE == 0 )

// net\mcast\pgm\inc\macroes.h
#define CLASSD_ADDR(a)  (( (*((uchar *)&(a))) & 0xf0) == 0xe0)

// net\mmc\common\xstream.h
#define XFER_TYPE_FROM_TAG(x)	( 0x0000FFFF & (x) )

// net\mmc\tfscore\errutil.h
#define AddStringIdErrorMessage2(hr, ids, idsgeek) FillTFSErrorId(0, hr, FILLTFSERR_HIGH | FILLTFSERR_GEEK, ids, 0, idsgeek)
#define AddStringErrorMessage2(hr, psz, pszGeek) FillTFSError(0, hr, FILLTFSERR_HIGH | FILLTFSERR_GEEK, psz, 0, pszGeek)
#define SetDefaultHighLevelErrorStringId(ids) \
     FillTFSErrorId(0, hr, FILLTFSERR_HIGH | FILLTFSERR_NOCLOBBER, ids, 0, 0)

// net\mmc\tfscore\tfschar.h
#define CbStrLenA(psz)	((StrLenA(psz)+1)*sizeof(char))
#define CbStrLenW(psz)	((StrLenW(psz)+1)*sizeof(WCHAR))
#define AllocaStrDupA(lpa) (\
	((LPCSTR)lpa == NULL) ? NULL : (\
		StrCpyA((LPSTR) alloca(CbStrLenA(lpa)*2), lpa)))
#define AllocaStrDupW(lpw) (\
	((LPCWSTR)lpw == NULL) ? NULL : (\
		StrCpyW((LPWSTR) alloca(CbStrLenW(lpw)), lpw)))

// net\mmc\wins\dhcp.h
#define BOOT_FILE_SIZE_W        ( BOOT_FILE_SIZE * sizeof( WCHAR ))
#define BOOT_SERVER_SIZE_W      ( BOOT_SERVER_SIZE * sizeof( WCHAR ))

// net\ndis\lib\ndisapi.c
#define UNICODE_STRING_SIZE(x) \
    ((((x) == NULL) ? 0 : (x)->Length) + sizeof(WCHAR))

// net\ndis\sys\ndisnt.h
#define WAIT_FOR_PROTOCOL(_pProt, _O)                                       \
    {                                                                       \
        WAIT_FOR_OBJECT_MSG(_O,                                             \
                            "NDIS: Waiting for protocol %Z\n",              \
                            &(_pProt)->ProtocolCharacteristics.Name);       \
    }

// net\netbeui\kdext\nbfcom.h
#define PrintJoin() { ppchCurrentEol = &pchBlank; }
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
#define PrintNChar( _field, count )        \
            PrintFieldName(#_field)  \
            dprint_nchar( ( PCHAR )_obj._field, count ); \
            dprintf("%s", EOL)

// net\netbeui\sys\nbfcnfg.c
#define READ_HIDDEN_CONFIG(_Field) \
{ \
    ConfigurationInfo->_Field = \
        NbfReadSingleParameter( \
             ParametersHandle, \
             Str ## _Field, \
             ConfigurationInfo->_Field); \
}
#define WRITE_HIDDEN_CONFIG(_Field) \
{ \
    NbfWriteSingleParameter( \
        ParametersHandle, \
        Str ## _Field, \
        ConfigurationInfo->_Field); \
}

// net\netbeui\sys\nbfmac.h
#define MacCreateGeneralRouteReplySR(_MacInfo, _ExistingSR, _ExistingSRLength, _NewSR)  \
{                                                               \
    if (_ExistingSR) {                                          \
        PUCHAR TmpSR = (PUCHAR)(_ExistingSR);                   \
        switch ((_MacInfo)->MediumType) {                       \
        case NdisMedium802_5:                                   \
            TmpSR[0] = (TmpSR[0] & 0x1f) | 0x80;                \
            TmpSR[1] = (TmpSR[1] ^ 0x80);                       \
            *(_NewSR) = (_ExistingSR);                          \
            break;                                              \
        default:                                                \
            *(_NewSR) = (_ExistingSR);                          \
            break;                                              \
        }                                                       \
    } else {                                                    \
        *(_NewSR) = NULL;                                       \
    }                                                           \
}
#define MacCreateNonBroadcastReplySR(_MacInfo, _ExistingSR, _ExistingSRLength, _NewSR)  \
{                                                               \
    if (_ExistingSR) {                                          \
        PUCHAR TmpSR = (PUCHAR)(_ExistingSR);                   \
        switch ((_MacInfo)->MediumType) {                       \
        case NdisMedium802_5:                                   \
            if ((_ExistingSRLength) == 2) {                     \
                *(_NewSR) = NULL;                               \
            } else {                                            \
                TmpSR[0] = (TmpSR[0] & 0x1f);                   \
                TmpSR[1] = (TmpSR[1] ^ 0x80);                   \
                *(_NewSR) = (_ExistingSR);                      \
            }                                                   \
            break;                                              \
        default:                                                \
            *(_NewSR) = (_ExistingSR);                          \
            break;                                              \
        }                                                       \
    } else {                                                    \
        *(_NewSR) = NULL;                                       \
    }                                                           \
}

// net\netbeui\sys\nbfprocs.h
#define NbfDereferenceReceiveIrpLocked(Reason, IrpSp, Type) { \
    if (--IRP_RECEIVE_REFCOUNT(IrpSp) == 0) { \
        ExInterlockedInsertTailList( \
            &(IRP_DEVICE_CONTEXT(IrpSp)->IrpCompletionQueue), \
            &(IRP_RECEIVE_IRP(IrpSp))->Tail.Overlay.ListEntry, \
            &(IRP_DEVICE_CONTEXT(IrpSp)->Interlock)); \
    } \
}
#define NbfAddUIFrame(DeviceContext) { \
    PTP_UI_FRAME _UIFrame; \
    NbfAllocateUIFrame ((DeviceContext), &_UIFrame); \
    if (_UIFrame != NULL) { \
        ExInterlockedInsertTailList( \
            &(DeviceContext)->UIFramePool, \
            &_UIFrame->Linkage, \
            &(DeviceContext)->Interlock); \
    } \
}
#define NbfAddReceiveBuffer(DeviceContext) { \
    if (!(DeviceContext)->MacInfo.SingleReceive) { \
        PBUFFER_TAG _ReceiveBuffer; \
        NbfAllocateReceiveBuffer ((DeviceContext), &_ReceiveBuffer); \
        if (_ReceiveBuffer != NULL) { \
            ExInterlockedPushEntryList( \
                &(DeviceContext)->ReceiveBufferPool, \
                (PSINGLE_LIST_ENTRY)&_ReceiveBuffer->Linkage, \
                &(DeviceContext)->Interlock); \
        } \
    } \
}

// net\netbeui\sys\nbftypes.h
#define IRP_SEND_CONNECTION(_IrpSp) \
    ((PTP_CONNECTION)((_IrpSp)->FileObject->FsContext))
#define IRP_DEVICE_CONTEXT(_IrpSp) \
    ((PDEVICE_CONTEXT)((_IrpSp)->DeviceObject))
#define IRP_RECEIVE_CONNECTION(_IrpSp) \
    ((PTP_CONNECTION)((_IrpSp)->FileObject->FsContext))

// net\netbt\inc\vxdprocs.h
#define InitRcvContext(  pRcvCont, pRcvLowerConn, pRcvNCB ) \
{                                                        \
    pRcvCont->Signature   = RCVCONT_SIGN ;               \
    pRcvCont->pLowerConnId= pRcvLowerConn ;              \
    pRcvCont->pNCB        = pRcvNCB ;                    \
}

// net\nwlink\fwd\filterif.h
#define FltFilter(hdr,hdrSize,inContext,outContext)	(			\
	((FltBindInput.FilterHandler==NULL)							\
			|| ((inContext==NO_FILTER_CONTEXT)					\
					&&(outContext==NO_FILTER_CONTEXT)))			\
		? FILTER_PERMIT											\
		: DoFilter (hdr,hdrSize,inContext,outContext)			\
)

// net\nwlink\inc\bind.h
#define  ADAPTER_CONTEXT_TO_LOCAL_TARGET(_context, _localtarget)  \
    (_localtarget)->NicHandle.NicId = (_context).NicId;
#define  CONSTANT_ADAPTER_CONTEXT_TO_LOCAL_TARGET(_context, _localtarget)  \
    (_localtarget)->NicHandle.NicId = (USHORT)(_context);

// net\nwlink\inc\isnnb.h
#define REQUEST_OPEN_CONTEXT(_Request) \
    (((IoGetCurrentIrpStackLocation(_Request))->FileObject)->FsContext)
#define REQUEST_OPEN_TYPE(_Request) \
    (((IoGetCurrentIrpStackLocation(_Request))->FileObject)->FsContext2)

// net\nwlink\ipx\ipxprocs.h
#define IpxDereferenceAddressFile(_AddressFile, _Type) \
    if (InterlockedDecrement(&(_AddressFile)->ReferenceCount) == 0) { \
        IpxDestroyAddressFile (_AddressFile); \
    }
#define IpxDereferenceAddressFileSync(_AddressFile, _Type) \
    if (InterlockedDecrement(&(_AddressFile)->ReferenceCount) == 0) { \
        IpxDestroyAddressFile (_AddressFile); \
    }

// net\nwlink\ipx\ipxtypes.h
#define IPX_DEST_SOCKET_HASH(_IpxHeader)   (((PUCHAR)&(_IpxHeader)->DestinationSocket)[1] % IPX_ADDRESS_HASH_COUNT)

// net\nwlink\kdext\isnext.h
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
#define PrintListFieldName(_fieldName) \
        if ( strlen(_fieldName) > 40 ) {                                                \
            dprintf("%s%-.30s...%s Flink = ",IndentBuf,_fieldName, &(_fieldName[strlen(_fieldName)-7]));   \
        }else {                                                                        \
            dprintf("%s%-40.40s Flink = ",IndentBuf,_fieldName );                                        \
        }
#define PrintNChar( _field, count )        \
            PrintFieldName(#_field)  \
            dprint_nchar( ( PCHAR )_obj._field, count ); \
            dprintf("%s", EOL)

// net\nwlink\nb\nbiprocs.h
#define NbiDereferenceAddressFile(_AddressFile, _Type) \
    if ( !InterlockedDecrement(&(_AddressFile)->ReferenceCount )) { \
        NbiDestroyAddressFile (_AddressFile); \
    }
#define NbiReferenceConnection(_Connection, _Type) { \
    (VOID)ExInterlockedAddUlong( \
        &(_Connection)->ReferenceCount, \
        1, \
        &(_Connection)->DeviceLock->Lock); \
    (_Connection)->CanBeDestroyed = FALSE; \
}
#define NbiReferenceConnectionLock(_Connection, _Type) { \
    ++(_Connection)->ReferenceCount; \
    (_Connection)->CanBeDestroyed = FALSE; \
}
#define NbiReferenceConnectionSync(_Connection, _Type) { \
    (VOID)NB_ADD_ULONG( \
        &(_Connection)->ReferenceCount, \
        1, \
        (_Connection)->DeviceLock); \
    (_Connection)->CanBeDestroyed = FALSE; \
}

// net\nwlink\spx\isnspx.h
#define REQUEST_OPEN_CONTEXT(_Request) \
    (((IoGetCurrentIrpStackLocation(_Request))->FileObject)->FsContext)
#define REQUEST_OPEN_TYPE(_Request) \
    (((IoGetCurrentIrpStackLocation(_Request))->FileObject)->FsContext2)

// net\nwlink\spx\spxaddr.h
#define SpxAddrDereference(_Address, _Type) 		\
		{							   				\
			(VOID)SPX_ADD_ULONG ( 			\
				&(_Address)->sa_RefTypes[_Type], 	\
				(ULONG)-1, 							\
				&SpxGlobalInterlock); 				\
			if (SPX_ADD_ULONG( \
					&(_Address)->sa_RefCount, \
					(ULONG)-1, \
					&(_Address)->sa_Lock) == 1) { \
				SpxAddrDestroy (_Address); \
			}\
		}
#define SpxAddrDereference(_Address, _Type) \
			if (SPX_ADD_ULONG( \
					&(_Address)->sa_RefCount, \
					(ULONG)-1, \
					&(_Address)->sa_Lock) == 1) { \
				SpxAddrDestroy (_Address); \
			}
#define SpxAddrFileDereference(_AddressFile, _Type) \
			if (SPX_ADD_ULONG( \
					&(_AddressFile)->saf_RefCount, \
					(ULONG)-1, \
					(_AddressFile)->saf_AddrLock) == 1) { \
				SpxAddrFileDestroy (_AddressFile); \
			}

// net\qos\psched\netshell\diffserv\ipqosrm.h
#define IPQOS_GET_FIRST_FLOWSPEC_IN_CONFIG(Config)                     \
        (PIPQOS_NAMED_FLOWSPEC)((PUCHAR)(Config) +                     \
                                sizeof(IPQOS_GLOBAL_CONFIG))           \
#define IPQOS_GET_FIRST_QOSOBJECT_IN_CONFIG(Config)                    \
        (PIPQOS_NAMED_QOSOBJECT)((PUCHAR)(Config) +                    \
                                 sizeof(IPQOS_GLOBAL_CONFIG) +         \
                                 (Config->NumFlowspecs *               \
                                  sizeof(IPQOS_NAMED_FLOWSPEC)))
#define IPQOS_GET_FIRST_OBJECT_NAME_ON_NAMED_FLOW(FlowDesc) \
        (PWCHAR) ((PUCHAR)(FlowDesc) + sizeof(IPQOS_NAMED_FLOW))
#define IPQOS_GET_FIRST_FLOW_ON_IF(Config) \
        (PIPQOS_IF_FLOW) ((PUCHAR)(Config) + sizeof(IPQOS_IF_CONFIG))
#define IPQOS_GET_NEXT_FLOW_ON_IF(CurrFlow) \
        (PIPQOS_IF_FLOW) ((PUCHAR)(CurrFlow) + (CurrFlow)->FlowSize)

// net\qos\psched\pschdprf\pschdprf.c
#define WRITEBUF(_addr, _len)           memcpy(pdwBuf,(_addr),(_len));      pdwBuf = (PULONG)((PUCHAR)pdwBuf + (_len));

// net\qos\psched\sys\globals.h
#define INSTANCE_ID_SIZE                (sizeof(WCHAR) * 20)

// net\qos\psched\sys\main.c
#define MPNAME_EXTENSION_SIZE   ( 3 * sizeof(WCHAR))

// net\rndis\rndismp\rndismp.h
#define LSB(Value) ((UCHAR)(((ULONG)Value) & 0xff))

// net\rras\cm\cmdial\tooltip.h
#define TTM_SETTITLEA           (WM_USER + 32)  // wParam = TTI_*, lParam = char* szTitle
#define TTM_SETTITLEW           (WM_USER + 33)  // wParam = TTI_*, lParam = wchar* szTitle

// net\rras\ip\btpagnt\defs.h
#define GetAsnOctetString(dst,srcBuf)                                                   \
    (((srcBuf)->asnType)?		                                                        \
     (memcpy(dst,(srcBuf)->asnValue.string.stream,(srcBuf)->asnValue.string.length))    \
     :NULL)

// net\rras\ip\fltrdrvr\match.c
#define OutCacheMatch(uliAddr,uliPort,outCtxt,pOutCache)                    \
                       ((uliAddr).QuadPart is pOutCache->uliSrcDstAddr.QuadPart) and      \
                       ((uliPort).QuadPart is pOutCache->uliProtoSrcDstPort.QuadPart) and \
                       (pOutCache->pOutContext is (outCtxt))
#define InCacheMatch(uliAddr,uliPort,inCtxt,pInCache)                       \
        ((uliAddr).QuadPart is pInCache->uliSrcDstAddr.QuadPart) and       \
        ((uliPort).QuadPart is pInCache->uliProtoSrcDstPort.QuadPart) and  \
        (pInCache->pInContext is (inCtxt))

// net\rras\ip\igmpagnt\defs.h
#define GetAsnOctetString(dst,srcBuf)                                                   \
    (((srcBuf)->asnType)?		                                                        \
     (memcpy(dst,(srcBuf)->asnValue.string.stream,(srcBuf)->asnValue.string.length))    \
     :NULL)

// net\rras\ip\ipinip\ipinip.h
#define CompareUnicodeStrings(S1,S2)                    \
    (((S1)->Length == (S2)->Length) &&                  \
     (RtlCompareMemory((S1)->Buffer,                    \
                       (S2)->Buffer,                    \
                       (S2)->Length) == (S2)->Length))

// net\rras\ip\mcastmib\defs.h
#define GetAsnOctetString(dst,srcBuf) \
    (((srcBuf)->asnType) \
     ? (memcpy(dst,(srcBuf)->asnValue.string.stream,\
                 (srcBuf)->asnValue.string.length)) \
     : NULL)

// net\rras\ip\nat\xlate.h
#define NAT_TRANSLATE_HEADER() \
    Contextp->Header->DestinationAddress = \
        MAPPING_ADDRESS(Mapping->SourceKey[NatReversePath]); \
    ((PUSHORT)Contextp->ProtocolHeader)[1] = \
        MAPPING_PORT(Mapping->SourceKey[NatReversePath]); \
    Contextp->Header->SourceAddress = \
        MAPPING_ADDRESS(Mapping->DestinationKey[NatReversePath]); \
    ((PUSHORT)Contextp->ProtocolHeader)[0] = \
        MAPPING_PORT(Mapping->DestinationKey[NatReversePath])
#define NAT_TRANSLATE_HEADER() \
    Contextp->Header->DestinationAddress = \
        MAPPING_ADDRESS(Mapping->SourceKey[NatForwardPath]); \
    ((PUSHORT)Contextp->ProtocolHeader)[1] = \
        MAPPING_PORT(Mapping->SourceKey[NatForwardPath]); \
    Contextp->Header->SourceAddress = \
        MAPPING_ADDRESS(Mapping->DestinationKey[NatForwardPath]); \
    ((PUSHORT)Contextp->ProtocolHeader)[0] = \
        MAPPING_PORT(Mapping->DestinationKey[NatForwardPath])

// net\rras\ip\nath323\util.h
#define	SOCKADDR_IN_PRINTF(SocketAddress) \
	ntohl ((SocketAddress) -> sin_addr.s_addr), \
	ntohs ((SocketAddress) -> sin_port)
#define	ANSI_STRING_INIT(Text) { sizeof (Text) - sizeof (CHAR), 0, (Text) } // account for NUL

// net\rras\ip\ripagnt\defs.h
#define GetAsnOctetString(dst,srcBuf)                                                   \
    (((srcBuf)->asnType)?		                                                        \
     (memcpy(dst,(srcBuf)->asnValue.string.stream,(srcBuf)->asnValue.string.length))    \
     :NULL)

// net\rras\ip\rtrmgr\defs.h
#define CLASSA_ADDR(a)  (( (*((uchar *)&(a))) & 0x80) == 0)
#define CLASSB_ADDR(a)  (( (*((uchar *)&(a))) & 0xc0) == 0x80)
#define CLASSC_ADDR(a)  (( (*((uchar *)&(a))) & 0xe0) == 0xc0)
#define CLASSE_ADDR(a)  ((( (*((uchar *)&(a))) & 0xf0) == 0xf0) && \
                        ((a) != 0xffffffff))

// net\rras\ip\wanarp2\conn.h
#define InsertConnIndexInAddr(a,i)                  \
    ((PENET_CONTEXT_HALF_HDR)(a))->ulSlot = (i)
#define GetConnIndexFromAddr(a)                     \
    ((PENET_CONTEXT_HALF_HDR)(a))->ulSlot

// net\rras\ip\wanarp2\wanarp.h
#define CompareUnicodeStrings(S1,S2)                    \
    (((S1)->Length == (S2)->Length) &&                  \
     (RtlCompareMemory((S1)->Buffer,                    \
                       (S2)->Buffer,                    \
                       (S2)->Length) == (S2)->Length))

// net\rras\ipx\snmp\rtipxmib.h
#define GetAsnDispString(dst,srcBuf,defVal)					\
	(((srcBuf)->asnType)									\
		? ((dst)[(srcBuf)->asnValue.string.length] = 0,		\
			strncpy (dst,(srcBuf)->asnValue.string.stream,	\
						(srcBuf)->asnValue.string.length))	\
		: (defVal ? strcpy (dst,defVal) : ((dst)[0] = 0, NULL)))

// net\rras\ndis\rasl2tp\l2tpp.h
#define CtrlObjFromUdpContext(_x) \
    (_x)->pCtrlAddr
#define PayloadObjFromUdpContext(_x) \
    (_x)->pPayloadAddr

// net\rras\ndis\raspppoe\tapi.c
#define TAPI_STATION_ID_SIZE            ( 7 * sizeof( CHAR ) )

// net\rras\ndis\raspptp\common\protocol.h
#define GreSequence(g) (*(PULONG)(((PUCHAR)(g)) + sizeof(GRE_HEADER)))
#define GreAckSequence(g)                                                       \
    ((g)->SequenceNumberPresent ?                                               \
        (*(PULONG)(((PUCHAR)(g)) + sizeof(GRE_HEADER) + sizeof(ULONG))) :       \
        GreSequence(g))

// net\rras\ndis\raspptp\common\raspptp.h
#define InitEnumContext(e)                                  \
    {                                                           \
        (e)->ListEntry.Flink = (e)->ListEntry.Blink = NULL;     \
        (e)->Signature = ENUM_SIGNATURE;                        \
    }

// net\rras\ndis\raspptp\nt\ctdi.c
#define GET_CONTEXT(Irp, Context) (Context*)GetContextArea((Irp), sizeof(Context))

// net\rras\ras\ppp\engine\util.c
#define CLASSA_ADDR(a)  (( (*((UCHAR *)&(a))) & 0x80) == 0)
#define CLASSB_ADDR(a)  (( (*((UCHAR *)&(a))) & 0xc0) == 0x80)
#define CLASSC_ADDR(a)  (( (*((UCHAR *)&(a))) & 0xe0) == 0xc0)
#define CLASSE_ADDR(a)  ((( (*((UCHAR *)&(a))) & 0xf0) == 0xf0) && \
                        ((a) != 0xffffffff))

// net\rras\ras\ppp\rasipcp\rasipcp.c
#define CLASSA_ADDR(a)  (( (*((unsigned char *)&(a))) & 0x80) == 0)
#define CLASSB_ADDR(a)  (( (*((unsigned char *)&(a))) & 0xc0) == 0x80)
#define CLASSC_ADDR(a)  (( (*((unsigned char *)&(a))) & 0xe0) == 0xc0)
#define CLASSE_ADDR(a)  ((( (*((uchar *)&(a))) & 0xf0) == 0xf0) && \
                        ((a) != 0xffffffff))

// net\rras\ras\ppp\rasiphlp\rasiphlp_.h
#define CLASSA_NBO_ADDR(a)          (((*((uchar *)&(a))) & 0x80) == 0)
#define CLASSB_NBO_ADDR(a)          (((*((uchar *)&(a))) & 0xc0) == 0x80)
#define CLASSC_NBO_ADDR(a)          (((*((uchar *)&(a))) & 0xe0) == 0xc0)

// net\rras\ras\ui\common\sharing\cstest.c
#define ArgToSharedConnection(prsc) \
if (argc == 4) { \
    RasEntryToSharedConnection((PWCHAR)argv[2],(PWCHAR)argv[3],(prsc)); \
} else if (argc == 3) { \
    GUID _Guid; \
    UNICODE_STRING _us; \
    RtlInitUnicodeString(&_us, (PWCHAR)argv[2]); \
    RtlGUIDFromString(&_us, &_Guid); \
    RasGuidToSharedConnection(&_Guid,(prsc)); \
}

// net\rras\ras\ui\inc\common.h
#define CCH_NUL                     (sizeof(TCHAR))
#define CbFromCch(cch)              ((cch)*sizeof(TCHAR))

// net\rras\ras\ui\rasscrpt\scanner.h
#define Tok_SetLexeme(p, s) lstrcpyn(((PTOK)(p))->szLexeme, s, sizeof(((PTOK)(p))->szLexeme))
#define TokSz_SetSz(p, s)   lstrcpyn(((PTOKSZ)(p))->sz, s, sizeof(((PTOKSZ)(p))->sz))

// net\rras\rtm\rtmp.h
#define NNM(Route) 			(((char *)Route)+sizeof (RTM_XX_ROUTE))

// net\rras\rtmv2\rtmmain.h
#define DEREFERENCE_INSTANCE(Instance, RefType)                             \
            if (DereferenceObject(&Instance->ObjectHeader, RefType) == 0)   \
                DestroyInstance(Instance);
#define DEREFERENCE_ENTITY(Entity, RefType)                                 \
            if (DereferenceObject(&Entity->ObjectHeader, RefType) == 0)     \
                DestroyEntity(Entity);
#define DEREFERENCE_DEST(Dest, RefType)                                     \
            if (DereferenceObject(&(Dest)->ObjectHeader, RefType) == 0)     \
                DestroyDest(Dest);
#define DEREFERENCE_ROUTE(Route, RefType)                                   \
            if (DereferenceObject(&(Route)->ObjectHeader, RefType) == 0)    \
                DestroyRoute(Route);
#define DEREFERENCE_NEXTHOP(NextHop, RefType)                               \
            if (DereferenceObject(&(NextHop)->ObjectHeader, RefType) == 0)  \
                DestroyNextHop(NextHop);

// net\sfm\afp\server\afpconst.h
#define	AFP_MACHINE_TYPE_LEN		sizeof(AFP_MACHINE_TYPE_STR) - 1

// net\sfm\afp\server\afpinfo.h
#define AfpCreateAfpInfo(phDataStream, phAfpInfo,pInformation)	\
	AfpIoCreate(phDataStream,					\
				AFP_STREAM_INFO,				\
				&UNullString,					\
				FILEIO_ACCESS_READWRITE,		\
				FILEIO_DENY_NONE,				\
				FILEIO_OPEN_FILE,				\
				FILEIO_CREATE_INTERNAL,			\
				FILE_ATTRIBUTE_NORMAL,			\
				False,							\
				NULL,							\
				phAfpInfo,						\
				pInformation,					\
				NULL,							\
				NULL,							\
				NULL)

// net\sfm\afp\server\afpmem.h
#define	EQUAL_UNICODE_STRING(pUS1, pUS2, fIgnoreCase)	\
		(((pUS1)->Length == (pUS2)->Length) &&			\
		 RtlEqualUnicodeString(pUS1, pUS2, fIgnoreCase))
#define	EQUAL_STRING(pS1, pS2, fIgnoreCase)				\
		(((pS1)->Length == (pS2)->Length) &&			\
		 RtlEqualString(pS1, pS2, fIgnoreCase))
#define	EQUAL_UNICODE_STRING_CS(pUS1, pUS2)	\
		(((pUS1)->Length == (pUS2)->Length) &&			\
		 (memcmp((pUS1)->Buffer, (pUS2)->Buffer, (pUS1)->Length) == 0))

// net\sfm\afp\server\idindex.h
#define	DFE_SIZE_TINY_U			DFE_SIZE_TINY*sizeof(WCHAR)		// These are lengths for UNICODE names
#define	DFE_SIZE_SMALL_U		DFE_SIZE_SMALL*sizeof(WCHAR)	//		- ditto -
#define	DFE_SIZE_MEDIUM_U		DFE_SIZE_MEDIUM*sizeof(WCHAR)	//		- ditto -
#define	DFE_SIZE_LARGE_U		DFE_SIZE_LARGE*sizeof(WCHAR)	//		- ditto -	corres. to AFP_FILENAME_LEN

// net\sfm\afp\server\server.h
#define	AfpInitializeWorkItem(pWI, Worker, Context)	\
		{											\
			InitializeListHead(&(pWI)->wi_List);	\
			(pWI)->wi_Worker = (WORKER)(Worker);	\
			(pWI)->wi_Context = (Context);			\
		}

// net\sfm\afp\server\volume.h
#define AFP_CHANGE_ACTION(NTAction)	\
	(NTAction == FILE_ACTION_MODIFIED_STREAM ? AFP_CHANGE_ACTION_MODIFIED_STREAM : (NTAction - 1))

// net\sfm\atalk\sys\v42bis.h
#define	N4	256		/* characters in alphabet (2^n3) */

// net\snmp\newagent\inc\globals.h
#define PDUTYPESTRING(nPduType) \
            ((nPduType == SNMP_PDU_GETNEXT) \
                ? "getnext" \
                : (nPduType == SNMP_PDU_GETBULK) \
                    ? "getbulk" \
                    : (nPduType == SNMP_PDU_GET) \
                        ? "get" \
                        : (nPduType == SNMP_PDU_SET) \
                            ? "set" \
                            : "unknown")

// net\snmp\newagent\inc\service.h
#define SERVICE_CONTROL_STRING(x) \
    (((x) == SERVICE_CONTROL_STOP) \
        ? "STOP" \
        : ((x) == SERVICE_CONTROL_PAUSE) \
            ? "PAUSE" \
            : ((x) == SERVICE_CONTROL_CONTINUE) \
                ? "CONTINUE" \
                : ((x) == SERVICE_CONTROL_INTERROGATE) \
                    ? "INTERROGATE" \
                    : ((x) == SERVICE_CONTROL_SHUTDOWN) \
                        ? "SHUTDOWN" \
                        : "CONFIGURE" \
                        )

// net\snmp\newagent\inc\varbinds.h
#define VARBINDSTATESTRING(nState) \
            ((nState == VARBIND_INITIALIZED) \
                ? "initialized" \
                : (nState == VARBIND_PARTIALLY_RESOLVED) \
                    ? "partially resolved" \
                    : (nState == VARBIND_RESOLVED) \
                        ? "resolved" \
                        : (nState == VARBIND_RESOLVING) \
                            ? "resolving" \
                            : (nState == VARBIND_UNINITIALIZED) \
                                ? "uninitialized" \
                                : "aborted")

// net\snmp\subagent\hostmib\gennt.h
#define QUEUE_ENTER( queue_head, entry )             \
{                                                    \
    q_hdr_t *old_chain ;                             \
                                                     \
    old_chain = (q_hdr_t *)(queue_head.lifo_a) ;     \
    entry->chain_q.lifo_a = queue_head.lifo_a ;      \
    queue_head.lifo_a = (char *)entry ;              \
    entry->chain_q.fifo_a = NULL ;                   \
    if ( old_chain == NULL )                         \
        queue_head.fifo_a = (char *)entry ;          \
    else                                             \
        old_chain->fifo_a = (char *)entry ;          \
}
#define QUEUE_REMOVE( queue_head, entry )                  \
{                                                          \
    q_hdr_t *dequeue_chain ;                               \
    q_hdr_t *prev_chain ;                                  \
                                                           \
    dequeue_chain = (q_hdr_t *)(queue_head.fifo_a) ;       \
    entry = (tcb_t *)dequeue_chain ;                       \
    if ( dequeue_chain != NULL )                           \
    {                                                      \
        prev_chain = (q_hdr_t *)(dequeue_chain->fifo_a) ;  \
        queue_head.fifo_a = (char *)prev_chain ;           \
        if ( prev_chain != NULL )                          \
            prev_chain->lifo_a = NULL ;                    \
        else                                               \
            queue_head.lifo_a = NULL ;                     \
    }                                                      \
}

// net\sockets\winsock2\inc\ws2help.h
#define WahReferenceHandleContext(_ctx)  InterlockedIncrement(&(_ctx)->RefCount)
#define WahDereferenceHandleContext(_ctx)  InterlockedDecrement(&(_ctx)->RefCount)

// net\sockets\winsock2\ws2_32\inc\startup.h
#define GET_SOCK_POST_ROUTINE()      \
    (SockPostRoutine ? SockPostRoutine : GetSockPostRoutine())

// net\sockets\winsock2\ws2help\ws2ifsl\ws2ifslp.h
#define GET_SOCKET_PROCESSID(ctx) \
            (((PIFSL_PROCESS_CTX)((ctx)->ProcessRef->FsContext))->UniqueId)

// net\sockets\winsock2\wsp\afdsys\afdp.h
#define AFD_CONTEXT_POOL_TAG            ( (ULONG)'XdfA' | PROTECTED_POOL )
#define AFD_SAN_CONTEXT_POOL_TAG        ( (ULONG)'xdfA' | PROTECTED_POOL )

// net\sockets\winsock2\wsp\afdsys\afdprocs.h
#define AfdRecordPoolQuotaCharged( b )                                      \
            ExInterlockedAddLargeStatistic(                                 \
                &AfdQuotaStats.Charged,                                     \
                (b)                                                         \
                )

// net\sockets\winsock2\wsp\afdsys\afdstr.h
#define AFD_GET_ARL(_s) (_arl ? _arl : AfdFindReferenceLocation((_s),&_arl))
#define AFD_TP_READ_BUSY (AFD_TP_READ_CALL_PENDING|AFD_TP_READ_COMP_PENDING)

// net\tapi\litesabr\filters\amrtpnet\globals.h
#define CMD_STRING(cmd) \
    ((cmd == CMD_INIT) \
        ? TEXT("INIT") \
        : (cmd == CMD_PAUSE) \
            ? TEXT("PAUSE") \
            : (cmd == CMD_RUN) \
                ? TEXT("RUN") \
                : (cmd == CMD_STOP) \
                    ? TEXT("STOP") \
                    : (cmd == CMD_EXIT) \
                        ? TEXT("EXIT") \
                        : TEXT("UNKNOWN"))

// net\tapi\litesabr\filters\codecs\g711\algdefs.h
#define DEC_transform(a,b,c,d,e,f,g,h) \
        { \
          if ((f == MEDIASUBTYPE_MULAWAudio) \
              || ((f == MEDIASUBTYPE_WAVE || f == MEDIASUBTYPE_NULL) \
                  && (g == WAVE_FORMAT_MULAW))) \
            Ulaw2Short((const unsigned char *) a, \
                       (unsigned short *) b, c); \
          else \
            Alaw2Short((const unsigned char *) a, \
                       (unsigned short *) b, c); \
        }

// net\tapi\litesabr\filters\ppm\core.h
#define BEGIN_CLASS_REGISTRY() \
    CClassFactory::Registry NEAR CClassFactory::s_registry[] = {

// net\tapi\rtc\phoenix\src\axctl\rtcaxctl.cpp
#define     SYNC_STREAM(b,op,m,c)                       \
    if(m_pRTCActiveSession &&                           \
        (m_nControlState == RTCAX_STATE_CONNECTED ||    \
         m_nControlState == RTCAX_STATE_CONNECTING ||   \
         m_nControlState == RTCAX_STATE_ANSWERING))     \
    {                                                   \
        if(b)                                           \
        {                                               \
            m_pRTCActiveSession -> op(m, c);            \
        }                                               \
    }

// net\tapi\rtc\phoenix\src\exe\mainfrm.cpp
#define CH_PREFIX TEXT('&')

// net\tapi\rtc\phoenix\src\sip\msgproc.cpp
#define IsCRLF( pstrSignedBuffer )  ((*pstrSignedBuffer == '\r') && (*(pstrSignedBuffer+1) == '\n'))

// net\tapi\rtc\phoenix\src\sip\siputil.h
#define PRINTABLE_STRING_A(Str) \
    (((Str) == NULL) ? "NULL" : (Str))
#define PRINTABLE_STRING_W(WStr) \
    (((WStr) == NULL) ? L"NULL" : (WStr))

// net\tapi\rtc\phoenix\src\sip\ssltest\main.cpp
#define	IF_STRING_PARAMETER(Name,Variable) \
	if (_wcsicmp (Arg, _T(Name)) == 0) { \
		if (Variable) { \
			PrintConsole ("TEST: At most one -" Name " parameter may be specified.\n\n"); \
			Usage(); \
		} \
		if (!*ArgPos) { \
			PrintConsole ("TEST: The -" Name " parameter is incomplete.\n\n"); \
			Usage(); \
		} \
		Variable = *ArgPos++; \
	}

// net\tapi\rtc\phoenix\src\sip\ssltest\util.h
#define	IN_ADDR_PRINTF(InternetAddress) \
	((PUCHAR) (InternetAddress)) [0], \
	((PUCHAR) (InternetAddress)) [1], \
	((PUCHAR) (InternetAddress)) [2], \
	((PUCHAR) (InternetAddress)) [3]
#define	SOCKADDR_IN_PRINTF_DECIMAL(SocketAddress) \
	IN_ADDR_PRINTF(&(SocketAddress) -> sin_addr), \
	ntohs ((SocketAddress) -> sin_port)
#define	SOCKADDR_IN_PRINTF_HEX(SocketAddress)	\
	ntohl ((SocketAddress) -> sin_addr.s_addr),	\
	ntohs ((SocketAddress) -> sin_port)

// net\tapi\rtc\phoenix\src\sip\util.h
#define	IN_ADDR_PRINTF(InternetAddress) \
	((PUCHAR) (InternetAddress)) [0], \
	((PUCHAR) (InternetAddress)) [1], \
	((PUCHAR) (InternetAddress)) [2], \
	((PUCHAR) (InternetAddress)) [3]
#define	SOCKADDR_IN_PRINTF_DECIMAL(SocketAddress) \
	IN_ADDR_PRINTF(&(SocketAddress) -> sin_addr), \
	ntohs ((SocketAddress) -> sin_port)
#define	SOCKADDR_IN_PRINTF_HEX(SocketAddress)	\
	ntohl ((SocketAddress) -> sin_addr.s_addr),	\
	ntohs ((SocketAddress) -> sin_port)

// net\tapi\server\server.c
    #define REGNAMESIZE     ( 10 * sizeof(TCHAR) )

// net\tapi\skywalker\apps\avdialer\avdialer\callwnd.h
#define APPEND_PMENU_STRING( _STR_ )			\
PARSE_MENU_STRING( _STR_ )						\
pMenu->AppendMenu( MF_STRING, _STR_, sText );

// net\tapi\skywalker\apps\avdialer\avtapi\avtapi.cpp
#define FETCH_STRING(_CMS_, _IDS_)                                                    \
{                                                                                    \
    LoadString( _Module.GetResourceInstance(), _IDS_, szText, ARRAYSIZE(szText) );    \
    SysReAllocString( &bstrText, T2COLE(szText) );                                    \
    fire_SetCallState_CMS(lCallID, _CMS_, bstrText);                                \
}
#define FETCH_STRING(_CMS_, _IDS_)                                                    \
    cms = _CMS_;                                                                    \
    LoadString( _Module.GetResourceInstance(), _IDS_, szText, ARRAYSIZE(szText) );    \
    SysReAllocString( &bstrText, T2COLE(szText) );

// net\tapi\skywalker\apps\avdialer\avtapi\cetreeview.cpp
#define FETCH_STRING( _IDS_ )	\
	LoadString( _Module.GetResourceInstance(), _IDS_, szJunk, ARRAYSIZE(szJunk) );	\
	SysReAllocString( &bstrItemText, T2COLE(szJunk) );

// net\tapi\skywalker\apps\avdialer\avtapi\threadans.cpp
#define FETCH_STRING( _CMS_, _IDS_ )		\
	LoadString( _Module.GetResourceInstance(), _IDS_, szText, ARRAYSIZE(szText) );	\
	SysReAllocString( &bstrText, T2COLE(szText) );									\
	pAVTapi->fire_SetCallState_CMS( lCallID, _CMS_, bstrText );

// net\tapi\skywalker\apps\avdialer\avtapi\threaddial.cpp
#define FETCH_STRING( _CMS_, _IDS_ )        \
    if ( bSliders )    {                        \
        if ( LoadString(_Module.GetResourceInstance(), _IDS_, szText, ARRAYSIZE(szText)) > 0 )    { \
            if ( SUCCEEDED(SysReAllocString(&bstrText, T2COLE(szText))) )        \
                pAVTapi->fire_SetCallState_CMS( lCallID, _CMS_, bstrText );        \
        }                                                                        \
    }

// net\tapi\skywalker\cc\inc\core.h
#define BEGIN_CLASS_REGISTRY() \
    CClassFactory::Registry NEAR CClassFactory::s_registry[] = {

// net\tapi\skywalker\filters\rtp\inc\gtypes.h
#define RTPRECVSENDSTR(_RecvSend) (g_psRtpRecvSendStr[_RecvSend & 0x1])
#define RTPSTREAMCLASS(_class)    (g_psRtpStreamClass[_class & 0x3])

// net\tapi\skywalker\filters\rtp\inc\rtperr.h
#define RTPERR_TEXT(_e) (g_psRtpErr[(_e) & 0xffff])

// net\tapi\skywalker\h323\inc\h4503pp.h
#define SIZE_H4503PP_Module_PDU_7 sizeof(SubaddressTransferArg)
#define SIZE_H4503PP_Module_PDU_24 sizeof(CpRequestRes)

// net\tapi\skywalker\h323\tsp\call.h
#define IsTransferredCall( dwCallType )  ( (dwCallType & CALLTYPE_TRANSFEREDSRC) || (dwCallType & CALLTYPE_TRANSFERED_PRIMARY) )

// net\tapi\skywalker\h323\tsp\globals.h
#define H323SizeOfWSZ(wsz) \
    (((wsz) == NULL) ? 0 : ((wcslen(wsz) + 1) * sizeof(WCHAR)))

// net\tapi\skywalker\h323tsp\globals.h
#define H323SizeOfWSZ(wsz) \
    (((wsz) == NULL) ? 0 : ((wcslen(wsz) + 1) * sizeof(WCHAR)))

// net\tapi\skywalker\rcamsp\rcastrm.cpp
#define STREAM_PREFIX(x)  m_Direction == TD_RENDER ? \
                          "CRCAMSPStream(RENDER )::" x : \
                          "CRCAMSPStream(CAPTURE)::" x

// net\tapi\skywalker\wavemsp\wavestrm.cpp
#define STREAM_PREFIX(x)  m_Direction == TD_RENDER ? \
                          "CWaveMSPStream(RENDER)::" x : \
                          "CWaveMSPStream(CAPTURE)::" x

// net\tapi\sp\atsp32\atsp.c
    #define PROVIDER_INFO_SIZE (37 * sizeof (WCHAR))

// net\tapi\thunk\windows.h
#define DC_CAPTION          (DC_ICON | DC_TEXT | DC_BUTTONS)// ;Internal
#define EM_SETLIMITTEXT         (WM_USER+21)
#define EM_LINEFROMCHAR         (WM_USER+25)
#define EM_GETLIMITTEXT         (WM_USER+37)    /* ;Internal 4.0 */
#define EM_POSFROMCHAR          (WM_USER+38)    /* ;Internal 4.0 */
#define EM_CHARFROMPOS          (WM_USER+39)    /* ;Internal 4.0 */
#define LB_ADDSTRING            (WM_USER+1)
#define LB_INSERTSTRING         (WM_USER+2)
#define LB_GETTEXT              (WM_USER+10)
#define LB_GETTEXTLEN           (WM_USER+11)
#define LB_SELECTSTRING         (WM_USER+13)
#define LB_FINDSTRING           (WM_USER+16)
#define LB_FINDSTRINGEXACT      (WM_USER+35)
#define LB_INSERTSTRINGUPPER    (WM_USER+43)    // ;Internal 4.0
#define LB_INSERTSTRINGLOWER    (WM_USER+44)    // ;Internal 4.0
#define LB_ADDSTRINGUPPER       (WM_USER+45)    // ;Internal 4.0
#define LB_ADDSTRINGLOWER       (WM_USER+46)    // ;Internal 4.0
#define CB_LIMITTEXT            (WM_USER+1)
#define CB_ADDSTRING            (WM_USER+3)
#define CB_GETLBTEXT            (WM_USER+8)
#define CB_GETLBTEXTLEN         (WM_USER+9)
#define CB_INSERTSTRING         (WM_USER+10)
#define CB_FINDSTRING           (WM_USER+12)
#define CB_SELECTSTRING         (WM_USER+13)
#define CB_SETEXTENDEDUI        (WM_USER+21)
#define CB_GETEXTENDEDUI        (WM_USER+22)
#define CB_FINDSTRINGEXACT      (WM_USER+24)

// net\tapi\tregupr2\crypt.c
#define IsWDigit(c) (((WCHAR)(c)) >= (WCHAR)'0' && ((WCHAR)(c)) <= (WCHAR)'9')

// net\tcpip\apis\iphlpapi\dll\extapi.c
#define CLASSA_ADDR(a)  (( (*((uchar *)&(a))) & 0x80) == 0)
#define CLASSB_ADDR(a)  (( (*((uchar *)&(a))) & 0xc0) == 0x80)
#define CLASSC_ADDR(a)  (( (*((uchar *)&(a))) & 0xe0) == 0xc0)
#define CLASSD_ADDR(a)  (( (*((uchar *)&(a))) & 0xf0) == 0xe0)
#define CLASSE_ADDR(a)  ((( (*((uchar *)&(a))) & 0xf0) == 0xf0) && \
                        ((a) != 0xffffffff))

// net\tcpip\apis\iphlpapi\dll\str2addt.h
#define ISDIGIT(c)  (_istascii(c) && _istdigit(c))
#define ISLOWER(c)  (_istascii(c) && _istlower(c))
#define ISXDIGIT(c) (_istascii(c) && _istxdigit(c))

// net\tcpip\driver\ipv4\arpdef.h
#define ARP_HASH(x)         ((((uchar *)&(x))[3] + ((uchar *)&(x))[2] + ((uchar *)&(x))[1] + ((uchar *)&(x))[0]) % ARP_TABLE_SIZE)

// net\tcpip\driver\ipv4\igmp.h
#define IGMP_HASH(x)         ((((uchar *)&(x))[3]) % IGMP_TABLE_SIZE)

// net\tcpip\driver\ipv4\ipdef.h
#define CLASSA_ADDR(a)  (( (*((uchar *)&(a))) & 0x80) == 0)
#define CLASSB_ADDR(a)  (( (*((uchar *)&(a))) & 0xc0) == 0x80)
#define CLASSC_ADDR(a)  (( (*((uchar *)&(a))) & 0xe0) == 0xc0)
#define CLASSE_ADDR(a)  ((( (*((uchar *)&(a))) & 0xf0) == 0xf0) && \
                                                ((a) != 0xffffffff))
#define xsum(Buffer, Length) \
    ((ushort) tcpxsum_routine(0, (PUCHAR) (Buffer), (Length)))
#define NET_TABLE_HASH(x) ( ( (((uchar *)&(x))[0]) + (((uchar *)&(x))[1]) + \
                              (((uchar *)&(x))[2]) + (((uchar *)&(x))[3]) ) \
                           & (NET_TABLE_SIZE-1))
#define SET_CANCEL_CONTEXT(irp, DestIF) \
    if (irp) { \
       ((PIRP)irp)->Tail.Overlay.DriverContext[0] = DestIF; \
    }

// net\tcpip\driver\ipv4\ntip.c
#define NTE_CONTEXT_SIZE (sizeof(uint)*2+2)        // 0xAABBCCDD
#define ROUTE_DATA_STRING_SIZE (51 * sizeof(WCHAR))
#define BASIC_INFO_SIZE        (sizeof(KEY_VALUE_BASIC_INFORMATION) - sizeof(WCHAR) + ROUTE_DATA_STRING_SIZE)

// net\tcpip\driver\kdext2\9xkd\tcpipkd.c
#define ELSE_IF_CMD(_cmd)                              \
    else if (mystricmp(argv[0], #_cmd) == 0)        \
        Tcpipkd_##_cmd(&argv[1]);

// net\tcpip\driver\kdext2\9xkd\tcpipkd.h
#define TCPIPDumpCfg_BOOLEAN(_var, _def)                            \
    KDDump_BOOLEAN(_var, #_var);                                    \
    dprintf(TAB "/" TAB "%-10s", _def == TRUE ? "TRUE" : "FALSE");  \
    dprintf(ENDL)

// net\tcpip\driver\kdext2\inc\tcpdump.h
#define Print_uchar(_p, _f) \
    PrintFieldName(#_f); \
    printx("%-10lu" ENDL, (uint) _p->_f);
#define Print_ucharhex(_p, _f) \
    PrintFieldName(#_f); \
    printx("0x%08lx" ENDL, (ULONG) _p->_f)

// net\tcpip\driver\kdext2\ntkd\tcpipkd.h
#define TCPIPDumpCfg_BOOLEAN(_var, _def)                            \
    KDDump_BOOLEAN("tcpip!"#_var, #_var);                           \
    dprintf(TAB "/" TAB "%-10s", _def == TRUE ? "TRUE" : "FALSE");  \
    dprintf(ENDL)

// net\tcpip\driver\kdext\tcpipext.h
#define PrintJoin() { ppchCurrentEol = &pchBlank; }
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
#define PrintNChar( _field, count )        \
            PrintFieldName(#_field)  \
            dprint_nchar( ( PCHAR )_obj._field, count ); \
            dprintf("%s", EOL)

// net\tcpip\driver\tcp\tlcommon.h
#define PHXSUM(s,d,p,l) (uint)( (uint)*(ushort *)&(s) + \
                        (uint)*(ushort *)((char *)&(s) + sizeof(ushort)) + \
                        (uint)*(ushort *)&(d) + \
                        (uint)*(ushort *)((char *)&(d) + sizeof(ushort)) + \
                        (uint)((ushort)net_short((p))) + \
                        (uint)((ushort)net_short((ushort)(l))) )

// net\tcpip\services\lpd\lpd.h
#define WCS_LEN(dwAnsiLen)  ( sizeof( WCHAR ) * ( dwAnsiLen ))

// net\tcpip\services\rip\rip.h
#define CLASSA_ADDR(a)  (( (*((uchar *)&(a))) & 0x80) == 0)
#define CLASSB_ADDR(a)  (( (*((uchar *)&(a))) & 0xc0) == 0x80)
#define CLASSC_ADDR(a)  (( (*((uchar *)&(a))) & 0xe0) == 0xc0)
#define CLASSD_ADDR(a)  (( (*((uchar *)&(a))) & 0xf0) == 0xe0)
#define CLASSE_ADDR(a)  ((( (*((uchar *)&(a))) & 0xf0) == 0xf0) && \
                        ((a) != 0xffffffff))

// net\tcpip\services\telnet\client\wintel.h
#define NN_HOSTRESOLVED (WM_USER+403)  // Usage message box

// net\tcpip\services\telnet\server\tlntsess\scraper.cpp
#define COMPARE_ROWS(currentRow, lastSeenRow, result) \
    for(i = 0; i < wCols; ++i ) \
    { \
        if( pCurrent[ ( currentRow ) * wCols + i].Char.AsciiChar != \
            pLastSeen[ ( lastSeenRow ) * wCols + i].Char.AsciiChar ) \
        {\
            (result) = 0; \
            break;\
        } \
        if( ( wDefaultAttributes != pCurrent[ ( currentRow ) * wCols + i]. \
              Attributes ) && \
              ( pCurrent[ ( currentRow ) * wCols + i].Attributes !=  \
              pLastSeen[ ( lastSeenRow ) * wCols + i].Attributes ) ) \
        { \
           (result) = 0; \
           break; \
        } \
    }

// net\tcpip\services\telnet\server\tlntsess\shell.h
#define UNICODE_STR_SIZE(x)             ((sizeof(x) - sizeof(WCHAR)) / sizeof(WCHAR))

// net\tcpip\snmp\defs.h
#define GetAsnOctetString(dst,srcBuf)                                                   \
    (((srcBuf)->asnType)?                                                               \
     (memcpy(dst,(srcBuf)->asnValue.string.stream,(srcBuf)->asnValue.string.length))    \
     :NULL)
#define IsAsnOctetStringTypeNull(asnObj) (!((asnObj)->asnType && (asnObj)->asnValue.string.length))

// net\tcpip\tpipv6\dplayip6\dpsp.h
#define STREAM_PSOCKADDR(ppd) ((SOCKADDR_IN6 *)&(((LPSPPLAYERDATA)ppd)->saddrStream))

// net\tcpip\tpipv6\tcpip6\algrthms\hmacmd5.h
#define HMACMD5_CONTEXT_SIZE sizeof(MD5_CTX)

// net\tcpip\tpipv6\tcpip6\algrthms\hmacsha1.h
#define HMACSHA1_CONTEXT_SIZE sizeof(SHA1Context)

// net\tcpip\tpipv6\tcpip6\inc\ip6def.h
#define Cksum(Buffer, Length) ((ushort)tcpxsum(0, (PUCHAR)(Buffer), (Length)))

// net\tcpip\tpipv6\tcpip6\inc\tcb.h
#define TCB_HASH(DA,SA,DP,SP) ((uint)(*(uchar *)&(DA) + *((uchar *)&(DA) + 1) \
    + *((uchar *)&(DA) + 2) + *((uchar *)&(DA) + 3)) % TcbTableSize)

// net\tcpip\tpipv6\tcpip6\inc\transprt.h
#define PHXSUM(s,d,p,l) (uint)( (uint)*(ushort *)&(s) + \
                        (uint)*(ushort *)((char *)&(s) + sizeof(ushort)) + \
                        (uint)*(ushort *)&(d) + \
                        (uint)*(ushort *)((char *)&(d) + sizeof(ushort)) + \
                        (uint)((ushort)net_short((p))) + \
                        (uint)((ushort)net_short((ushort)(l))) )

// net\unimodem\inc\rovcomm.h
#define CbFromCchW(cch)             ((cch)*sizeof(WCHAR))
#define CbFromCchA(cch)             ((cch)*sizeof(CHAR))

// net\upnp\ssdp\common\ssdpnetwork\socket.cpp
#define CLASSD_ADDR(a)      (( (*((unsigned char *)&(a))) & 0xf0) == 0xe0)

// net\winnet\mprreg.cxx
#define STACK_ALLOC(str)  ((LPWSTR) _alloca((wcslen(str)+1)*sizeof(WCHAR)))

// net\winnet\tstring.h
#define STRSIZE(p)              ((STRLEN(p)+1) * sizeof(TCHAR))
#define STRING_SPACE_REQD(n)    ((n) * sizeof(_CHAR_TYPE))
#define DOWN_LEVEL_STRSIZE(n)   ((n) / sizeof(_CHAR_TYPE))

// net\wins\netsh\common.c
#define WSTRSIZE( wsz ) ( ( wcslen( wsz ) + 1 ) * sizeof( WCHAR ) )

// net\wins\server\inc\wins.h
#define WINS_PUT_VERS_NO_IN_STREAM_M(pVersNo, pStr)			     \
						{		             \
			LPLONG	_pTmpL = (LPLONG)(pStr);	   	     \
			COMM_HOST_TO_NET_L_M((pVersNo)->HighPart, *_pTmpL);    \
			_pTmpL++;					     \
			COMM_HOST_TO_NET_L_M((pVersNo)->LowPart, *_pTmpL);     \
						}
#define WINS_GET_VERS_NO_FR_STREAM_M(pStr, pVersNo)			     \
							{		     \
			LPLONG	_pTmpL = (LPLONG)(pStr);	   	     \
			COMM_NET_TO_HOST_L_M(*_pTmpL, (pVersNo)->HighPart);    \
			_pTmpL++;					     \
			COMM_NET_TO_HOST_L_M(*_pTmpL, (pVersNo)->LowPart );    \
							}

// net\wlbs\driver\util.h
#define CVY_MAC_ADDR_BCAST(m,a)        (((PUCHAR)(a))[0] == 0xff)
#define CVY_MAC_ADDR_MCAST(m,a)        (((PUCHAR)(a))[0] & 0x1)
#define CVY_MAC_ADDR_GROUP_SET(m,a)    ((((PUCHAR)(a))[0]) |= 0x1)
#define CVY_MAC_ADDR_GROUP_TOGGLE(m,a) ((((PUCHAR)(a))[0]) ^= 0x1)
#define CVY_MAC_ADDR_LAA_SET(m,a)      ((((PUCHAR)(a))[0]) |= 0x2)
#define CVY_MAC_ADDR_LAA_TOGGLE(m,a)   ((((PUCHAR)(a))[0]) ^= 0x2)

// printscan\fax\inc\faxutil.h
#define StringSize(_s)              (( _s ) ? (_tcslen( _s ) + 1) * sizeof(TCHAR) : 0)

// printscan\fax\inc\jobtag.h
#define FAXTAG_WHEN_TO_SEND     TEXT("<$FAXTAG$ WHENTOSEND>")  // string == "cheap" | "at"

// printscan\fax\print\faxmon\faxmon.h
#define SizeOfString(p)     ((_tcslen(p) + 1) * sizeof(TCHAR))

// printscan\fax\print\faxprint\faxui\cwabobj.cpp
#define StrPropOk( strprop )    ((strprop) && (strprop)->Value.lpszA && *(strprop)->Value.lpszA)

// printscan\fax\print\faxprint\inc\faxlib.h
#define SizeOfString(p)     ((_tcslen(p) + 1) * sizeof(TCHAR))
#define AllocString(cch)    MemAlloc(sizeof(TCHAR) * (cch))
#define AllocStringZ(cch)   MemAllocZ(sizeof(TCHAR) * (cch))

// printscan\fax\provider\t30\comm\fcom.c
#define         READLINEEVENTS  (ALWAYSEVENTS | EV_RXCHAR)

// printscan\fax\provider\t30\comm\identify.c
#define ADDSTRING(STRING) \
                BG_CHK(pTG->TmpSettings.STRING); \
                u = _fstrlen(pTG->TmpSettings.STRING)+1; \
                _fmemcpy(pb, pTG->TmpSettings.STRING,u); \
                lpCmdTab->STRING=pb;\
                pb+=u; \
                BG_CHK(pb<=(pTG->bModemCmds+sizeof(pTG->bModemCmds)));

// printscan\fax\provider\t30\headers\awnsfcor.h
#define SetupTextIdHdr(lp, l, n, t)				\
	(((LPBCTEXTID)(lp))->GroupNum = (n)); 		\
	(((LPBCTEXTID)(lp))->GroupLength = (l));	\
	(((LPBCTEXTID)(lp))->TextEncoding = (t));

// printscan\fax\provider\t30\headers\awnsfint.h
#define HasTextId(lpbc)         ((lpbc)->wTextIdLen && (lpbc)->wszTextId)

// printscan\fax\provider\t30\headers\comdevi.h
#   define INTERCALL(sz)                if((t1-t2) > BETWEENCALL_THRESH)\
                 ERRMSG(("!!!Inter API %s delay %ld!!!\r\n", (LPSTR)(sz), (t1-t2)));

// printscan\fax\provider\t30\headers\protdump.h
#define GETFCF(lpfr,lpszBuf)    \
                (wsprintf(lpszBuf,              \
                (LPSTR)(rgszFrName[lpfr->ifr & 0x7F])))

// printscan\fax\provider\t30\headers\root.h
#define IDVARSTRINGSIZE    (sizeof(VARSTRING)+128)

// printscan\fax\provider\t30\main\t30util.c
#define IDVARSTRINGSIZE     (sizeof(VARSTRING)+128)

// printscan\fax\samples\ncfsp\nc.h
#define StringSize(_s)      (( _s ) ? (_tcslen( _s ) + 1) * sizeof(TCHAR) : 0)

// printscan\fax\service\client\rpcutil.c
#define WCSSIZE(s)          ((wcslen(s)+1) * sizeof(WCHAR))

// printscan\fax\setup\ocm\faxocm.h
#define StringSize(_s)              (( _s ) ? (wcslen( _s ) + 1) * sizeof(WCHAR) : 0)

// printscan\fax\setup\wizdll\tapi.c
                #define IDVARSTRINGSIZE    (sizeof(VARSTRING)+128)

// printscan\faxsrv\src\inc\faxutil.h
#define SizeOfString(p)     ((_tcslen(p) + 1) * sizeof(TCHAR))
#define StringSize(_s)              (( _s ) ? (_tcslen( _s ) + 1) * sizeof(TCHAR) : 0)
#define StringSizeW(_s)              (( _s ) ? (wcslen( _s ) + 1) * sizeof(WCHAR) : 0)
#define MultiStringSize(_s)         ( ( _s ) ?  MultiStringLength((_s)) * sizeof(TCHAR) : 0 )

// printscan\faxsrv\src\inc\jobtag.h
#define FAXTAG_WHEN_TO_SEND     TEXT("<$FAXTAG$ WHENTOSEND>")  // string == "cheap" | "at"

// printscan\faxsrv\src\print\faxmon\faxmon.h
#define SizeOfString(p)     ((_tcslen(p) + 1) * sizeof(TCHAR))

// printscan\faxsrv\src\print\faxprint\inc\faxlib.h
#define SizeOfString(p)     ((_tcslen(p) + 1) * sizeof(TCHAR))
#define AllocString(cch)    MemAlloc(sizeof(TCHAR) * (cch))
#define AllocStringZ(cch)   MemAllocZ(sizeof(TCHAR) * (cch))

// printscan\faxsrv\src\print\faxprint\prnwzrd\abobj.cpp
#define StrPropOk( strprop )    ((strprop) && (strprop)->Value.lpszA && *(strprop)->Value.lpszA)

// printscan\faxsrv\src\print\faxprint\prnwzrd\wizard.c
#define FillEditCtrlWithInitialUserInfo(nIDDlgItem,field)   \
    if (pWizardUserMem->lpInitialData->lpSenderInfo->field && \
        !IsEmptyString(pWizardUserMem->lpInitialData->lpSenderInfo->field)) { \
        SetDlgItemText(hDlg, nIDDlgItem, pWizardUserMem->lpInitialData->lpSenderInfo->field); \
    }
#define FillEditCtrlWithSenderWizardUserInfo(nIDDlgItem,field)  \
    if (pWizardUserMem->lpFaxSendWizardData->lpSenderInfo->field && \
        !IsEmptyString(pWizardUserMem->lpFaxSendWizardData->lpSenderInfo->field)) { \
        SetDlgItemText(hDlg, nIDDlgItem, pWizardUserMem->lpFaxSendWizardData->lpSenderInfo->field); \
    }

// printscan\faxsrv\src\provider\t30\comm\fcom.c
#define         READLINEEVENTS  (ALWAYSEVENTS | EV_RXCHAR)

// printscan\faxsrv\src\provider\t30\comm\identify.c
#define ADDSTRING(STRING) \
        BG_CHK(pTG->TmpSettings.STRING); \
        u = _fstrlen(pTG->TmpSettings.STRING)+1; \
        _fmemcpy(pb, pTG->TmpSettings.STRING,u); \
        lpCmdTab->STRING=pb;\
        pb+=u; \
        BG_CHK(pb<=(pTG->bModemCmds+sizeof(pTG->bModemCmds)));

// printscan\faxsrv\src\provider\t30\headers\awnsfcor.h
#define SetupTextIdHdr(lp, l, n, t)				\
	(((LPBCTEXTID)(lp))->GroupNum = (n)); 		\
	(((LPBCTEXTID)(lp))->GroupLength = (l));	\
	(((LPBCTEXTID)(lp))->TextEncoding = (t));

// printscan\faxsrv\src\provider\t30\headers\awnsfint.h
#define HasTextId(lpbc)         ((lpbc)->wTextIdLen && (lpbc)->wszTextId)

// printscan\faxsrv\src\provider\t30\headers\comdevi.h
#   define INTERCALL(sz)                if((t1-t2) > BETWEENCALL_THRESH)\
                 ERRMSG(("!!!Inter API %s delay %ld!!!\r\n", (LPSTR)(sz), (t1-t2)));

// printscan\faxsrv\src\provider\t30\headers\protdump.h
#define GETFCF(lpfr,lpszBuf)    \
                (wsprintf(lpszBuf,              \
                (LPSTR)(rgszFrName[lpfr->ifr & 0x7F])))

// printscan\faxsrv\src\provider\t30\headers\root.h
#define IDVARSTRINGSIZE    (sizeof(VARSTRING)+128)

// printscan\faxsrv\src\provider\t30\main\t30util.c
#define IDVARSTRINGSIZE     (sizeof(VARSTRING)+128)

// printscan\faxsrv\src\sdktools\msvc15\include\olestd.h
#define OleStdQueryLinkSourceData(lpformatetc)   \
	(((lpformatetc)->tymed & TYMED_ISTREAM) ?    \
			NOERROR : ResultFromScode(DV_E_FORMATETC))

// printscan\faxsrv\src\sdktools\msvc15\include\penwin.h
#define SyvCharacterToSymbol(c) ((LONG)(unsigned char)(c) | 0x00010000)
#define AnsiFromSyvAppGesture(syv) ChSyvToAnsi( \
    syv-(FIsUpAppGesture(syv)? SYV_CIRCLEUPA-(SYV)'A': SYV_CIRCLELOA-(SYV)'a'))

// printscan\faxsrv\src\sdktools\msvc15\include\windows.h
#define EM_LIMITTEXT	        (WM_USER+21)
#define EM_LINEFROMCHAR         (WM_USER+25)
#define LB_ADDSTRING	       (WM_USER+1)
#define LB_INSERTSTRING        (WM_USER+2)
#define LB_GETTEXT	       (WM_USER+10)
#define LB_GETTEXTLEN	       (WM_USER+11)
#define LB_SELECTSTRING        (WM_USER+13)
#define LB_FINDSTRING	       (WM_USER+16)
#define LB_FINDSTRINGEXACT     (WM_USER+35)
#define CB_LIMITTEXT	         (WM_USER+1)
#define CB_ADDSTRING	         (WM_USER+3)
#define CB_GETLBTEXT	         (WM_USER+8)
#define CB_GETLBTEXTLEN	         (WM_USER+9)
#define CB_INSERTSTRING          (WM_USER+10)
#define CB_FINDSTRING	         (WM_USER+12)
#define CB_SELECTSTRING	         (WM_USER+13)
#define CB_SETEXTENDEDUI         (WM_USER+21)
#define CB_GETEXTENDEDUI         (WM_USER+22)
#define CB_FINDSTRINGEXACT       (WM_USER+24)

// printscan\faxsrv\src\service\inc\rpcutil.h
#define WCSSIZE(s)          ((wcslen(s)+1) * sizeof(WCHAR))
#define TCSSIZE(s)          ((_tcslen(s)+1) * sizeof(TCHAR))

// printscan\faxsrv\src\test\src\xxxunusedxxx\deviceioctls\efsstruc.h
#define EFS_KEY_SIZE( pKey ) (sizeof( EFS_KEY ) + (pKey)->KeyLength)
#define EFS_KEY_DATA( Key )  (PUCHAR)(((PUCHAR)(Key)) + sizeof( EFS_KEY ))
#define COMMON_FSCTL_HEADER_SIZE (7 * sizeof( ULONG ) + 2 * SESSION_KEY_SIZE)

// printscan\print\drivers\usermode\driverui\driverui.h
#define ILOADSTRING(pci, id, wchbuf, size) \
    ILoadStringW(((pci)->pWinResData), id, wchbuf, size)

// printscan\print\drivers\usermode\driverui\uni\unidrv.c
#define     DEFAULT_FONTSUB_SIZE        (1024 * sizeof(WCHAR))

// printscan\print\drivers\usermode\gpdres\alpsres\alpsres.h
#define TEMP_NAME_PREFIX __TEXT("~AL")

// printscan\print\drivers\usermode\gpdres\cnl4jres\cnl4jres.c
#define bIsControlChar(c) \
    ((c) >= 0x00 && (c) <= 0x1f || (c) >= 0x80 && (c) <= 0x9f)

// printscan\print\drivers\usermode\gpdres\cnrstres\cnrstres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\gpdres\ib87wres\pdev.h
#define TEMP_NAME_PREFIX __TEXT("~IB")

// printscan\print\drivers\usermode\gpdres\nc82jres\nc82jres.h
#define TEMP_NAME_PREFIX __TEXT("~82")

// printscan\print\drivers\usermode\gpdres\riafui\riafui.rc
#define VER_LEGALCOPYRIGHT_STR          "Copyright(C) Microsoft & RICOH " VER_LEGALCOPYRIGHT_YEARS

// printscan\print\drivers\usermode\inc\afm2ntm.h
#define DEFINE_CHAR(gi, cdeftbl) \
    (cdeftbl[CHR_DEF_INDEX(gi)] |= CHR_DEF(gi))

// printscan\print\drivers\usermode\inc\lib.h
#define SIZE_OF_STRING(p)   ((_tcslen(p) + 1) * sizeof(TCHAR))
#define HexDigit(n) gstrDigitString[(n) & 0xf]

// printscan\print\drivers\usermode\inc\regdata.h
#define RESET_FINDFORMTRAY(pFormTrayTable, pFindData) \
        { \
            (pFindData)->pvSignature = (pFindData); \
            (pFindData)->ptstrNextEntry = (pFormTrayTable); \
        }

// printscan\print\drivers\usermode\lib\ufl\source\uflsproc.c
#define HexDigit(n)    DigitString[(n) & 0x0F]

// printscan\print\drivers\usermode\lib\xcf\xcf_priv.h
#define OpCode(op) (0x0FF & (op))		/* strip the escape off an opcode */

// printscan\print\drivers\usermode\msplot\plotter\output.h
#define SETLINETYPESOLID(pPDev)                                 \
{                                                               \
    if ((pPDev)->LastLineType != PLOT_LT_SOLID) {               \
                                                                \
        (pPDev)->LastLineType = PLOT_LT_SOLID;                  \
        OutputString(pPDev, "LT");                              \
    }                                                           \
}

// printscan\print\drivers\usermode\msplot\plotui\help.c
#define cbWSTR(wstr)        ((wcslen(wstr) + 1) * sizeof(WCHAR))

// printscan\print\drivers\usermode\tools\ps\makentf\afm2ntm.c
#define GET_NTMTOTALSIZE(nsi) \
{\
    if ((nsi).nSize == -1 \
        || (nsi).nFontNameSize == -1 \
        || (nsi).nDisplayNameSize == -1 \
        || (nsi).nGlyphSetNameSize == -1 \
        || (nsi).nCharWidthSize == -1 \
        || (nsi).nKernPairSize == -1 \
        || (nsi).nCharDefSize == -1)\
    {\
        ERR(("makentf - afm2ntm: GET_NTMTOTALSIZE\n"));\
    }\
    (nsi).nTotalSize = (nsi).nSize \
                        + (nsi).nFontNameSize \
                        + (nsi).nDisplayNameSize \
                        + (nsi).nGlyphSetNameSize \
                        + (nsi).nCharWidthSize \
                        + (nsi).nKernPairSize \
                        + (nsi).nCharDefSize;\
};
#define GET_IFIMETRICSTOTALSIZE(isi) \
{\
    if ((isi).nSize == -1 \
        || (isi).nIfiExtraSize == -1 \
        || (isi).nFamilyNameSize == -1 \
        || (isi).nStyleNameSize == -1 \
        || (isi).nFaceNameSize == -1 \
        || (isi).nUniqueNameSize == -1 \
        || (isi).nFontSimSize == -1 \
        || (isi).nBoldSize == -1 \
        || (isi).nItalicSize == -1 \
        || (isi).nBoldItalicSize == -1 \
        || (isi).nCharSetSize == -1)\
    {\
        ERR(("makentf - afm2ntm: GET_IFIMETRICSTOTALSIZE\n"));\
    }\
    (isi).nTotalSize = (isi).nSize \
                        + (isi).nIfiExtraSize \
                        + (isi).nFamilyNameSize \
                        + (isi).nStyleNameSize \
                        + (isi).nFaceNameSize \
                        + (isi).nUniqueNameSize \
                        + (isi).nFontSimSize \
                        + (isi).nBoldSize \
                        + (isi).nItalicSize \
                        + (isi).nBoldItalicSize \
                        + (isi).nCharSetSize;\
};

// printscan\print\drivers\usermode\tools\uexts\gdifont.cxx
#define GDISTRO_DumpWStr(field) \
        { \
        WCHAR wstrTmp[256]; \
        move2(wstrTmp, pstro->field, pstro->cGlyphs * 2); \
        Print("  %-16s = 0x%x (%ws)\n", #field, pstro->field, wstrTmp); \
        }

// printscan\print\drivers\usermode\tools\uni\mkgttufm\mkgttufm.c
#define WRITEDATATOFILE(pData) \
    if (!WriteFile(hOutFile, \
                   (pData), \
                   (strlen(pData)), \
                   &dwWrittenSize, \
                   NULL)) \
    { \
        fprintf(stderr, gcstrWriteFileError ); \
        ERR(("WriteFile")); \
    }

// printscan\print\drivers\usermode\unidrv2\render\stretch.c
#define ROP4_FG_ROP(Rop4)       (Rop4 & 0xFF)

// printscan\print\spooler\inetpp2\server\ppinfo.h
#define ENDOFBUFFER(buf, length)  (LPTSTR)((((LPSTR)buf) + (length - sizeof(TCHAR))))

// printscan\print\spooler\inetsrv\globals.h
#define  URLS_JOBINFO           TEXT ("?ShowJobInfo&%d")       // dwJobID
#define  URLS_JOBCONTROL        TEXT ("?JobControl&%d&")       // dwJobID, append P,R,C,S

// printscan\print\spooler\localspl\getprn.c
#define Nulwcslen(psz)  ((psz) ? wcslen(psz)*sizeof(WCHAR)+sizeof(WCHAR) : 0)

// printscan\print\spooler\localspl\init.c
#define AddSize(pStr, dwSize)                                         \
              if (pStr) {                                             \
                  dwSize = dwSize + (wcslen(pStr) + 1)*sizeof(WCHAR); \
              }

// printscan\print\spooler\localspl\spltypes.h
#define FindEnvironment( psz, pIniSpooler )                                 \
    (PINIENVIRONMENT)FindIniKey( (PINIENTRY)pIniSpooler->pIniEnvironment,   \
                                 (LPWSTR)(psz) )
#define FindPort( psz, pIniSpooler )                                        \
    (PINIPORT)FindIniKey( (PINIENTRY)pIniSpooler->pIniPort,                 \
                          (LPWSTR)(psz))
#define FindPrinter( psz,pIniSpooler )                                      \
    (PINIPRINTER)FindIniKey( (PINIENTRY)pIniSpooler->pIniPrinter,           \
                             (LPWSTR)(psz) )
#define FindPrintProc( psz, pEnv )                                          \
    (PINIPRINTPROC)FindIniKey( (PINIENTRY)(pEnv)->pIniPrintProc,            \
                               (LPWSTR)(psz) )
#define FindForm( psz, pIniSpooler )                                        \
    (PINIFORM)FindIniKey( (PINIENTRY)pIniSpooler->pShared->pIniForm,        \
                          (LPWSTR)(psz) )
#define FindMonitor( psz, pIniSpooler )                                     \
    (PINIMONITOR)FindIniKey( (PINIENTRY)pIniSpooler->pIniMonitor,           \
                             (LPWSTR)(psz) )

// printscan\print\spooler\monitors\local\spltypes.h
#define FindPort(pIniLocalMon, psz)                          \
    (PINIPORT)LcmFindIniKey( (PINIENTRY)pIniLocalMon->pIniPort, \
                          (LPWSTR)(psz))

// printscan\print\spooler\monitors\tcpmon\tcpmib\tcpmib.h
#define GET_ASN_OCTETSTRING(pDest, count, varBindList, i) ( GetAsnOctetString(pDest, count, &varBindList, i) )

// printscan\print\spooler\spllib\webutil.cxx
#define SIZEOF_UTF8      (sizeof(WCHAR) + sizeof(CHAR))

// printscan\print\spooler\wpnpinst\wow\inc\penwin.h
#define SyvCharacterToSymbol(c) ((LONG)(unsigned char)(c) | 0x00010000)
#define AnsiFromSyvAppGesture(syv) ChSyvToAnsi( \
    syv-(FIsUpAppGesture(syv)? SYV_CIRCLEUPA-(SYV)'A': SYV_CIRCLELOA-(SYV)'a'))

// printscan\print\spooler\wpnpinst\wow\inc\prsht.h
#define PSM_SETFINISHTEXTA      (WM_USER + 115)
#define PSM_SETFINISHTEXTW      (WM_USER + 121)

// printscan\print\spooler\wpnpinst\wow\inc\wife.h
#define IsSbcsUBChar(uc) ((uc & 0xff00) == 0x2000)
#define IsDbcsUBChar(uc) ((uc & 0xff00) != 0x2000)

// printscan\print\spooler\wpnpinst\wow\inc\windows.h
#define EM_LIMITTEXT            (WM_USER+21)
#define EM_LINEFROMCHAR         (WM_USER+25)
#define LB_ADDSTRING           (WM_USER+1)
#define LB_INSERTSTRING        (WM_USER+2)
#define LB_GETTEXT             (WM_USER+10)
#define LB_GETTEXTLEN          (WM_USER+11)
#define LB_SELECTSTRING        (WM_USER+13)
#define LB_FINDSTRING          (WM_USER+16)
#define LB_FINDSTRINGEXACT     (WM_USER+35)
#define CB_LIMITTEXT             (WM_USER+1)
#define CB_ADDSTRING             (WM_USER+3)
#define CB_GETLBTEXT             (WM_USER+8)
#define CB_GETLBTEXTLEN          (WM_USER+9)
#define CB_INSERTSTRING          (WM_USER+10)
#define CB_FINDSTRING            (WM_USER+12)
#define CB_SELECTSTRING          (WM_USER+13)
#define CB_SETEXTENDEDUI         (WM_USER+21)
#define CB_GETEXTENDEDUI         (WM_USER+22)
#define CB_FINDSTRINGEXACT       (WM_USER+24)

// printscan\ui\camdlg\camdlg.cpp
#define TQ_DESTROY      (WM_USER+1)

// printscan\ui\compstui\resource.h
#define GSBUF_CHGETSTR(c,p)     GSBUF_CHPREADD(c);GetString(&GSBuf,(LPTSTR)(p))
#define GSBUF_ADDC(i, c)        GSBufAddWChar(&GSBuf, i, c)

// printscan\ui\inc\pviewids.h
#define PWM_SETENABLESTRETCH         (WM_USER+632)
#define PWM_GETENABLESTRETCH         (WM_USER+633)

// printscan\ui\shellext\src\util.h
#define DC_DESTROY          (WM_USER+2)

// printscan\ui\wiaacmgr\thrdmsg.h
#define TQ_DESTROY               (WM_USER+1)

// printscan\ui\wiaacmgr\upquery.cpp
#define STR_HELP_DESTINATION TEXT("hcp://services/subsite?node=TopLevelBucket_1/Music__video__games_and_photos&topic=MS-ITS%3A%25HELP_LOCATION%25%5Cfilefold.chm%3A%3A/manage_your_pictures.htm&select=TopLevelBucket_1/Music__video__games_and_photos/photos_and_other_digital_images")

// printscan\ui\wiavidd\videodlg.h
#define TQ_DESTROY      (WM_USER+1)

// printscan\wia\common\stirt\string.cpp
#define HEXDIGIT( nDigit )                              \
    (TCHAR)((nDigit) > 9 ?                              \
          (nDigit) - 10 + 'A'                           \
        : (nDigit) + '0')

// printscan\wia\core\server\globals.h
#define     DEADSPACE(x) (((x)==WHITESPACE_CHAR) || ((x)==DOUBLEQUOTE_CHAR) )

// printscan\wia\core\stimon\globals.h
#define     DEADSPACE(x) (((x)==WHITESPACE_CHAR) || ((x)==DOUBLEQUOTE_CHAR) )

// printscan\wia\inc\stistr.h
#define ISWHITE( ch )       ((ch) == L'\t' || (ch) == L' ' || (ch) == L'\r')
#define ISWHITEA( ch )      ((ch) == '\t' || (ch) == ' ' || (ch) == '\r')

// printscan\wia\inc\wiaconv.h
#define _wcsdupa(pStr)                                                  \
                                                                        \
    (__pAscii, (__pUnicode = pStr) == 0 ? (PWSTR) 0 : (                 \
                                                                        \
    __nLength = wcslen(__pUnicode) + 1,                                 \
                                                                        \
    lstrcpyW((PWSTR) _alloca(__nLength * sizeof(WCHAR)), __pUnicode)))  \
#define _strdupa(pStr)                                                  \
                                                                        \
    (__pUnicode, (__pAscii = pStr) == 0 ? (PSTR) 0 : (                  \
                                                                        \
    __nLength = strlen(__pAscii) + 1,                                   \
                                                                        \
    lstrcpyA((PSTR) _alloca(__nLength * sizeof(CHAR)), __pAscii)))      \

// printscan\wia\inc\wiadef.h
#define WIA_PROP_LIST_VALUE(ppv, index)                              \\
     ((index > ((PROPVARIANT*) ppv)->cal.cElems - WIA_LIST_VALUES) || (index < -WIA_LIST_NOM)) ?\\
     NULL :                                                          \\
     (((PROPVARIANT*) ppv)->vt == VT_UI1) ?                          \\
     ((PROPVARIANT*) ppv)->caub.pElems[WIA_LIST_VALUES + index] :    \\
     (((PROPVARIANT*) ppv)->vt == VT_UI2) ?                          \\
     ((PROPVARIANT*) ppv)->caui.pElems[WIA_LIST_VALUES + index] :    \\
     (((PROPVARIANT*) ppv)->vt == VT_UI4) ?                          \\
     ((PROPVARIANT*) ppv)->caul.pElems[WIA_LIST_VALUES + index] :    \\
     (((PROPVARIANT*) ppv)->vt == VT_I2) ?                           \\
     ((PROPVARIANT*) ppv)->cai.pElems[WIA_LIST_VALUES + index] :     \\
     (((PROPVARIANT*) ppv)->vt == VT_I4) ?                           \\
     ((PROPVARIANT*) ppv)->cal.pElems[WIA_LIST_VALUES + index] :     \\
     (((PROPVARIANT*) ppv)->vt == VT_R4) ?                           \\
     ((PROPVARIANT*) ppv)->caflt.pElems[WIA_LIST_VALUES + index] :   \\
     (((PROPVARIANT*) ppv)->vt == VT_R8) ?                           \\
     ((PROPVARIANT*) ppv)->cadbl.pElems[WIA_LIST_VALUES + index] :   \\
     (((PROPVARIANT*) ppv)->vt == VT_BSTR) ?                         \\
     (LONG)(((PROPVARIANT*) ppv)->cabstr.pElems[WIA_LIST_VALUES + index]) : \\
     NULL

// printscan\wia\kernel\qv2kux\qv2kux.c
#define FILTER_DEVICE_PROPOGATE_CHARACTERISTICS (FILE_REMOVABLE_MEDIA |  \
                                                 FILE_READ_ONLY_DEVICE | \
                                                 FILE_FLOPPY_DISKETTE    \
                                                 )

// printscan\wia\setup\clsinst\sti_ci.h
#define REGSTR_VAL_WIASHEXT             TEXT("Scanners & Cameras")

// printscan\wia\test\wiastress\conv.h
#define _wcsdupa(pStr)                                                  \
                                                                        \
    (__pAscii, (__pUnicode = pStr) == 0 ? (PWSTR) 0 : (                 \
                                                                        \
    __nLength = wcslen(__pUnicode) + 1,                                 \
                                                                        \
    lstrcpyW((PWSTR) _alloca(__nLength * sizeof(WCHAR)), __pUnicode)))  \
#define _strdupa(pStr)                                                  \
                                                                        \
    (__pUnicode, (__pAscii = pStr) == 0 ? (PSTR) 0 : (                  \
                                                                        \
    __nLength = strlen(__pAscii) + 1,                                   \
                                                                        \
    lstrcpyA((PSTR) _alloca(__nLength * sizeof(CHAR)), __pAscii)))      \

// public\ddk\inc\dciddi.h
#define DCI_CAN_STRETCHXY                       (DCI_CAN_STRETCHX | DCI_CAN_STRETCHY)
#define DCI_CAN_STRETCHXYN                      (DCI_CAN_STRETCHXN | DCI_CAN_STRETCHYN)

// public\ddk\inc\hbapiwmi.h
    #define MSFC_HBAPortAttributesResults_NodeWWN_SIZE sizeof(UCHAR[8])
    #define MSFC_HBAPortAttributesResults_PortWWN_SIZE sizeof(UCHAR[8])
    #define MSFC_HBAPortAttributesResults_PortSupportedFc4Types_SIZE sizeof(UCHAR[32])
    #define MSFC_HBAPortAttributesResults_PortActiveFc4Types_SIZE sizeof(UCHAR[32])
    #define MSFC_HBAPortAttributesResults_FabricName_SIZE sizeof(UCHAR[8])
    #define MSFC_FCAdapterHBAAttributes_NodeWWN_SIZE sizeof(UCHAR[8])
    #define HBAFC3MgmtInfo_wwn_SIZE sizeof(UCHAR[8])
    #define GetPortAttributesByWWN_IN_wwn_SIZE sizeof(UCHAR[8])
    #define SendRNID_IN_wwn_SIZE sizeof(UCHAR[8])
    #define HBAFCPID_NodeWWN_SIZE sizeof(UCHAR[8])
    #define HBAFCPID_PortWWN_SIZE sizeof(UCHAR[8])

// public\ddk\inc\ndis.h
#define RTL_CONSTANT_STRING(s) { sizeof( s ) - sizeof( (s)[0] ), sizeof( s ), s }
#define READ_REGISTER_BUFFER_UCHAR(x, y, z) {                           \
    PUCHAR registerBuffer = x;                                          \
    PUCHAR readBuffer = y;                                              \
    ULONG readCount;                                                    \
    __mf();                                                             \
    for (readCount = z; readCount--; readBuffer++, registerBuffer++) {  \
        *readBuffer = *(volatile UCHAR * const)(registerBuffer);        \
    }                                                                   \
}
#define WRITE_REGISTER_BUFFER_UCHAR(x, y, z) {                            \
    PUCHAR registerBuffer = x;                                            \
    PUCHAR writeBuffer = y;                                               \
    ULONG writeCount;                                                     \
    for (writeCount = z; writeCount--; writeBuffer++, registerBuffer++) { \
        *(volatile UCHAR * const)(registerBuffer) = *writeBuffer;         \
    }                                                                     \
    KeFlushWriteBuffer();                                                 \
}
#define NdisMoveMappedMemory(Destination,Source,Length)                     \
{                                                                           \
    PUCHAR _Src = (Source);                                                 \
    PUCHAR _Dest = (Destination);                                           \
    PUCHAR _End = _Dest + (Length);                                         \
    while (_Dest < _End)                                                    \
    {                                                                       \
        *_Dest++ = *_Src++;                                                 \
    }                                                                       \
}
#define NdisZeroMappedMemory(Destination,Length)                            \
{                                                                           \
    PUCHAR _Dest = (Destination);                                           \
    PUCHAR _End = _Dest + (Length);                                         \
    while (_Dest < _End)                                                    \
    {                                                                       \
        *_Dest++ = 0;                                                       \
    }                                                                       \
}
#define NdisInitializeWorkItem(_WI_, _R_, _C_)  \
    {                                           \
        (_WI_)->Context = _C_;                  \
        (_WI_)->Routine = _R_;                  \
    }
#define NdisRawWritePortUchar(Port,Data)                                    \
        WRITE_PORT_UCHAR((PUCHAR)(Port),(UCHAR)(Data))
#define NdisRawWritePortBufferUchar(Port,Buffer,Length) \
        WRITE_PORT_BUFFER_UCHAR((PUCHAR)(Port),(PUCHAR)(Buffer),(Length))
#define NdisRawReadPortUchar(Port, Data) \
        *(Data) = READ_PORT_UCHAR((PUCHAR)(Port))
#define NdisRawReadPortBufferUchar(Port,Buffer,Length)                      \
        READ_PORT_BUFFER_UCHAR((PUCHAR)(Port),(PUCHAR)(Buffer),(Length))
#define NdisReadRegisterUchar(Register,Data)    *(Data) = READ_REGISTER_UCHAR((PUCHAR)(Register))

// public\ddk\inc\ntddk.h
#define CONTEXT_INTEGER         (CONTEXT_i386 | 0x00000002L) // AX, BX, CX, DX, SI, DI
#define CONTEXT_SEGMENTS        (CONTEXT_i386 | 0x00000004L) // DS, ES, FS, GS
#define CONTEXT_EXTENDED_REGISTERS  (CONTEXT_i386 | 0x00000020L) // cpu specific extensions
#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER |\
                      CONTEXT_SEGMENTS)
#define CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#define CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#define CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#define CONTEXT_CONTROL                 (CONTEXT_IA64 | 0x00000001L)
#define CONTEXT_INTEGER                 (CONTEXT_IA64 | 0x00000008L)
#define CONTEXT_IA32_CONTROL            (CONTEXT_IA64 | 0x00000020L)  // Includes StIPSR
#define READ_REGISTER_BUFFER_UCHAR(x, y, z) {                           \
    PUCHAR registerBuffer = x;                                          \
    PUCHAR readBuffer = y;                                              \
    ULONG readCount;                                                    \
    __mf();                                                             \
    for (readCount = z; readCount--; readBuffer++, registerBuffer++) {  \
        *readBuffer = *(volatile UCHAR * const)(registerBuffer);        \
    }                                                                   \
}
#define WRITE_REGISTER_BUFFER_UCHAR(x, y, z) {                            \
    PUCHAR registerBuffer = x;                                            \
    PUCHAR writeBuffer = y;                                               \
    ULONG writeCount;                                                     \
    for (writeCount = z; writeCount--; writeBuffer++, registerBuffer++) { \
        *(volatile UCHAR * const)(registerBuffer) = *writeBuffer;         \
    }                                                                     \
    KeFlushWriteBuffer();                                                 \
}
#define ExInitializeWorkItem(Item, Routine, Context) \
    (Item)->WorkerRoutine = (Routine);               \
    (Item)->Parameter = (Context);                   \
    (Item)->List.Flink = NULL;
#define ExIsObjectInFirstZoneSegment(Zone,Object) ((BOOLEAN)     \
    (((PUCHAR)(Object) >= (PUCHAR)(Zone)->SegmentList.Next) &&   \
     ((PUCHAR)(Object) < (PUCHAR)(Zone)->SegmentList.Next +      \
                         (Zone)->TotalSegmentSize))              \
)
#define IoRequestDpc( DeviceObject, Irp, Context ) ( \
    KeInsertQueueDpc( &(DeviceObject)->Dpc, (Irp), (Context) ) )

// public\ddk\inc\ntddpcm.h
#define PCMRES_GET_AUDIO_ENABLE(desc) ((UCHAR) ((desc)->u.DevicePrivate.Data[0] &  PCMRESF_AUDIO_ENABLE) != 0)

// public\ddk\inc\ntdef.h
#define RTL_CONSTANT_OBJECT_ATTRIBUTES(n, a) \
    { sizeof(OBJECT_ATTRIBUTES), NULL, RTL_CONST_CAST(PUNICODE_STRING)(n), a, NULL, NULL }
#define RTL_CONSTANT_STRING(s) { sizeof( s ) - sizeof( (s)[0] ), sizeof( s ), s }

// public\ddk\inc\ntia64.h
#define CONTEXT_CONTROL                 (CONTEXT_IA64 | 0x00000001L)
#define CONTEXT_INTEGER                 (CONTEXT_IA64 | 0x00000008L)
#define CONTEXT_IA32_CONTROL            (CONTEXT_IA64 | 0x00000020L)  // Includes StIPSR

// public\ddk\inc\srb.h
#define SP_UNTAGGED ((UCHAR) ~0)

// public\ddk\inc\storport.h
#define SP_UNTAGGED ((UCHAR) ~0)

// public\ddk\inc\wdm\acpiioct.h
#define ACPI_METHOD_NEXT_ARGUMENT( Argument )                              \
    (PACPI_METHOD_ARGUMENT) ( (PUCHAR) Argument +                          \
    ACPI_METHOD_ARGUMENT_LENGTH_FROM_ARGUMENT( Argument ) )

// public\ddk\inc\wdm\usbcamdi.h
#define USBCAMD_VIDEO_STILL_STREAM  (USBCAMD_VIDEO_STREAM | USBCAMD_STILL_STREAM)

// public\ddk\inc\wdm\wdm.h
#define READ_REGISTER_BUFFER_UCHAR(x, y, z) {                           \
    PUCHAR registerBuffer = x;                                          \
    PUCHAR readBuffer = y;                                              \
    ULONG readCount;                                                    \
    __mf();                                                             \
    for (readCount = z; readCount--; readBuffer++, registerBuffer++) {  \
        *readBuffer = *(volatile UCHAR * const)(registerBuffer);        \
    }                                                                   \
}
#define WRITE_REGISTER_BUFFER_UCHAR(x, y, z) {                            \
    PUCHAR registerBuffer = x;                                            \
    PUCHAR writeBuffer = y;                                               \
    ULONG writeCount;                                                     \
    for (writeCount = z; writeCount--; writeBuffer++, registerBuffer++) { \
        *(volatile UCHAR * const)(registerBuffer) = *writeBuffer;         \
    }                                                                     \
    KeFlushWriteBuffer();                                                 \
}
#define ExInitializeWorkItem(Item, Routine, Context) \
    (Item)->WorkerRoutine = (Routine);               \
    (Item)->Parameter = (Context);                   \
    (Item)->List.Flink = NULL;
#define IoRequestDpc( DeviceObject, Irp, Context ) ( \
    KeInsertQueueDpc( &(DeviceObject)->Dpc, (Irp), (Context) ) )

// public\ddk\inc\wdm\wmidata.h
    #define MSWmi_Guid_Guid_SIZE sizeof(UCHAR[16])
    #define MSWmi_GuidRegistrationInfo_Operation_SIZE sizeof(ULONG)
    #define MSSmBios_RawSMBiosTables_SmbiosMajorVersion_SIZE sizeof(UCHAR)
    #define MSSmBios_RawSMBiosTables_DmiRevision_SIZE sizeof(UCHAR)
    #define SYSID_UUID_Uuid_SIZE sizeof(UCHAR[16])
    #define SYSID_1394_x1394_SIZE sizeof(UCHAR[8])
    #define MSMCAEvent_Header_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_CPUError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_MemoryError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIBusError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIBusError_PCI_BUS_ID_BusNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIBusError_PCI_BUS_ID_SegmentNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_ClassCodeInterface_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_ClassCodeSubClass_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_FunctionNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_DeviceNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_BusNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PCIComponentError_PCI_COMP_INFO_SegmentNumber_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_RECORD_TYPE_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_EVM_REV_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_SENSOR_TYPE_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_SENSOR_NUM_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_EVENT_DIR_TYPE_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_DATA1_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_DATA2_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SystemEventError_SEL_DATA3_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SMBIOSError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_SMBIOSError_SMBIOS_EVENT_TYPE_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PlatformSpecificError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_PlatformSpecificError_OEM_COMPONENT_ID_SIZE sizeof(UCHAR[16])
    #define STORAGE_FAILURE_PREDICT_DATA_VendorSpecific_SIZE sizeof(UCHAR[512])
    #define ATAPI_FAILURE_PREDICT_DATA_VendorSpecific_SIZE sizeof(UCHAR[362])
    #define ATAPI_FAILURE_PREDICT_DATA_VendorSpecific2_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_OfflineCollectCapability_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_VendorSpecific3_SIZE sizeof(UCHAR)
    #define ATAPI_FAILURE_PREDICT_DATA_Reserved_SIZE sizeof(UCHAR[12])
    #define ATAPI_FAILURE_PREDICT_DATA_VendorSpecific4_SIZE sizeof(UCHAR[125])
    #define STORAGE_FAILURE_PREDICT_THRESHOLDS_VendorSpecific_SIZE sizeof(UCHAR[512])
    #define EXECUTE_SELF_TEST_IN_Subcommand_SIZE sizeof(UCHAR)
    #define STORAGE_SCSI_INFO_EXCEPTIONS_MRIE_SIZE sizeof(UCHAR)
    #define MSIde_PortDeviceInfo_Bus_SIZE sizeof(UCHAR)
    #define MSIde_PortDeviceInfo_Target_SIZE sizeof(UCHAR)
    #define MSIde_PortDeviceInfo_Lun_SIZE sizeof(UCHAR)
    #define SERIAL_WMI_COMM_DATA_XoffCharacter_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_XonCharacter_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwProvCharSize_SIZE sizeof(ULONG)
    #define WMI_TAPE_PROBLEM_WARNING_TapeData_SIZE sizeof(UCHAR[512])
    #define WMI_CHANGER_PROBLEM_WARNING_ChangerData_SIZE sizeof(UCHAR[512])

// public\ddk\inc\wiadef.h
#define WIA_PROP_LIST_VALUE(ppv, index)                              \\
     ((index > ((PROPVARIANT*) ppv)->cal.cElems - WIA_LIST_VALUES) || (index < -WIA_LIST_NOM)) ?\\
     NULL :                                                          \\
     (((PROPVARIANT*) ppv)->vt == VT_UI1) ?                          \\
     ((PROPVARIANT*) ppv)->caub.pElems[WIA_LIST_VALUES + index] :    \\
     (((PROPVARIANT*) ppv)->vt == VT_UI2) ?                          \\
     ((PROPVARIANT*) ppv)->caui.pElems[WIA_LIST_VALUES + index] :    \\
     (((PROPVARIANT*) ppv)->vt == VT_UI4) ?                          \\
     ((PROPVARIANT*) ppv)->caul.pElems[WIA_LIST_VALUES + index] :    \\
     (((PROPVARIANT*) ppv)->vt == VT_I2) ?                           \\
     ((PROPVARIANT*) ppv)->cai.pElems[WIA_LIST_VALUES + index] :     \\
     (((PROPVARIANT*) ppv)->vt == VT_I4) ?                           \\
     ((PROPVARIANT*) ppv)->cal.pElems[WIA_LIST_VALUES + index] :     \\
     (((PROPVARIANT*) ppv)->vt == VT_R4) ?                           \\
     ((PROPVARIANT*) ppv)->caflt.pElems[WIA_LIST_VALUES + index] :   \\
     (((PROPVARIANT*) ppv)->vt == VT_R8) ?                           \\
     ((PROPVARIANT*) ppv)->cadbl.pElems[WIA_LIST_VALUES + index] :   \\
     (((PROPVARIANT*) ppv)->vt == VT_BSTR) ?                         \\
     (LONG)(((PROPVARIANT*) ppv)->cabstr.pElems[WIA_LIST_VALUES + index]) : \\
     NULL

// public\ddk\inc\xfilter.h
#define FDDI_COPY_NETWORK_ADDRESS(D, S, AddressLength)              \
{                                                                   \
    PCHAR _D = (D);                                                 \
    PCHAR _S = (S);                                                 \
    UINT _C = (AddressLength);                                      \
    for ( ; _C > 0 ; _D++, _S++, _C--)                              \
    {                                                               \
        *_D = *_S;                                                  \
    }                                                               \
}

// public\halkit\inc\nthal.h
#define CONTEXT_INTEGER         (CONTEXT_i386 | 0x00000002L) // AX, BX, CX, DX, SI, DI
#define CONTEXT_SEGMENTS        (CONTEXT_i386 | 0x00000004L) // DS, ES, FS, GS
#define CONTEXT_EXTENDED_REGISTERS  (CONTEXT_i386 | 0x00000020L) // cpu specific extensions
#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER |\
                      CONTEXT_SEGMENTS)
#define CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#define CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#define CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#define CONTEXT_CONTROL                 (CONTEXT_IA64 | 0x00000001L)
#define CONTEXT_INTEGER                 (CONTEXT_IA64 | 0x00000008L)
#define CONTEXT_IA32_CONTROL            (CONTEXT_IA64 | 0x00000020L)  // Includes StIPSR
#define READ_REGISTER_BUFFER_UCHAR(x, y, z) {                           \
    PUCHAR registerBuffer = x;                                          \
    PUCHAR readBuffer = y;                                              \
    ULONG readCount;                                                    \
    __mf();                                                             \
    for (readCount = z; readCount--; readBuffer++, registerBuffer++) {  \
        *readBuffer = *(volatile UCHAR * const)(registerBuffer);        \
    }                                                                   \
}
#define WRITE_REGISTER_BUFFER_UCHAR(x, y, z) {                            \
    PUCHAR registerBuffer = x;                                            \
    PUCHAR writeBuffer = y;                                               \
    ULONG writeCount;                                                     \
    for (writeCount = z; writeCount--; writeBuffer++, registerBuffer++) { \
        *(volatile UCHAR * const)(registerBuffer) = *writeBuffer;         \
    }                                                                     \
    KeFlushWriteBuffer();                                                 \
}
#define ExInitializeWorkItem(Item, Routine, Context) \
    (Item)->WorkerRoutine = (Routine);               \
    (Item)->Parameter = (Context);                   \
    (Item)->List.Flink = NULL;
#define ExIsObjectInFirstZoneSegment(Zone,Object) ((BOOLEAN)     \
    (((PUCHAR)(Object) >= (PUCHAR)(Zone)->SegmentList.Next) &&   \
     ((PUCHAR)(Object) < (PUCHAR)(Zone)->SegmentList.Next +      \
                         (Zone)->TotalSegmentSize))              \
)
#define IoRequestDpc( DeviceObject, Irp, Context ) ( \
    KeInsertQueueDpc( &(DeviceObject)->Dpc, (Irp), (Context) ) )

// public\ifskit\inc\ntifs.h
#define CONTEXT_INTEGER         (CONTEXT_i386 | 0x00000002L) // AX, BX, CX, DX, SI, DI
#define CONTEXT_SEGMENTS        (CONTEXT_i386 | 0x00000004L) // DS, ES, FS, GS
#define CONTEXT_EXTENDED_REGISTERS  (CONTEXT_i386 | 0x00000020L) // cpu specific extensions
#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER |\
                      CONTEXT_SEGMENTS)
#define CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#define CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#define CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#define CONTEXT_CONTROL                 (CONTEXT_IA64 | 0x00000001L)
#define CONTEXT_INTEGER                 (CONTEXT_IA64 | 0x00000008L)
#define CONTEXT_IA32_CONTROL            (CONTEXT_IA64 | 0x00000020L)  // Includes StIPSR
#define READ_REGISTER_BUFFER_UCHAR(x, y, z) {                           \
    PUCHAR registerBuffer = x;                                          \
    PUCHAR readBuffer = y;                                              \
    ULONG readCount;                                                    \
    __mf();                                                             \
    for (readCount = z; readCount--; readBuffer++, registerBuffer++) {  \
        *readBuffer = *(volatile UCHAR * const)(registerBuffer);        \
    }                                                                   \
}
#define WRITE_REGISTER_BUFFER_UCHAR(x, y, z) {                            \
    PUCHAR registerBuffer = x;                                            \
    PUCHAR writeBuffer = y;                                               \
    ULONG writeCount;                                                     \
    for (writeCount = z; writeCount--; writeBuffer++, registerBuffer++) { \
        *(volatile UCHAR * const)(registerBuffer) = *writeBuffer;         \
    }                                                                     \
    KeFlushWriteBuffer();                                                 \
}
#define ExInitializeWorkItem(Item, Routine, Context) \
    (Item)->WorkerRoutine = (Routine);               \
    (Item)->Parameter = (Context);                   \
    (Item)->List.Flink = NULL;
#define ExIsObjectInFirstZoneSegment(Zone,Object) ((BOOLEAN)     \
    (((PUCHAR)(Object) >= (PUCHAR)(Zone)->SegmentList.Next) &&   \
     ((PUCHAR)(Object) < (PUCHAR)(Zone)->SegmentList.Next +      \
                         (Zone)->TotalSegmentSize))              \
)
#define IoRequestDpc( DeviceObject, Irp, Context ) ( \
    KeInsertQueueDpc( &(DeviceObject)->Dpc, (Irp), (Context) ) )
#define FSRTL_NTFS_STREAM_LEGAL (FSRTL_NTFS_LEGAL | FSRTL_OLE_LEGAL)

// public\internal\com\inc\corhdr.h
#define IsTdAbstract(x)                     ((x) & tdAbstract)
#define IsMdAbstract(x)                     ((x) & mdAbstract)
#define IsMdInstanceInitializer(x, str)     (((x) & mdRTSpecialName) && !strcmp((str), COR_CTOR_METHOD_NAME))
#define IsMdInstanceInitializerW(x, str)    (((x) & mdRTSpecialName) && !wcscmp((str), COR_CTOR_METHOD_NAME_W))

// public\internal\drivers\inc\efsstruc.h
#define EFS_KEY_SIZE( pKey ) (sizeof( EFS_KEY ) + (pKey)->KeyLength)
#define EFS_KEY_DATA( Key )  (PUCHAR)(((PUCHAR)(Key)) + sizeof( EFS_KEY ))
#define COMMON_FSCTL_HEADER_SIZE (7 * sizeof( ULONG ) + 2 * SESSION_KEY_SIZE)

// public\internal\ds\inc\dnslib.h
#define STR_BUF_SIZE_GIVEN_UTF8_LEN( Utf8Length, CharSet ) \
        ( ((CharSet)==DnsCharSetUnicode) ? ((Utf8Length)+1)*2 : (Utf8Length)+1 )
#define DNS_MESSAGE_END(pMsg) \
                ((PCHAR)&(pMsg)->MessageHead + (pMsg)->MessageLength)
#define Dns_StringCopyAllocate_W( p, c )  \
        ( (PWCHAR) Dns_StringCopyAllocate(  \
                    (PCHAR) (p),            \
                    (c),                    \
                    DnsCharSetUnicode,      \
                    DnsCharSetUnicode ) )
#define Dns_StringCopyAllocate_A( p, c )  \
        ( (PCHAR) Dns_StringCopyAllocate(   \
                    (p),                    \
                    (c),                    \
                    DnsCharSetUtf8,         \
                    DnsCharSetUtf8 ) )
#define pDnsEmptyString         ( (PSTR) &DnsEmptyString )
#define pDnsEmptyWideString     ( (PWSTR) &DnsEmptyString )
#define DNSSTRING_UTF8( fUnicode, String ) \
        ( (fUnicode) ? pDnsEmptyString : (PSTR)(String) )
#define DNSSTRING_ANSI( fUnicode, String ) \
        ( (fUnicode) ? pDnsEmptyString : (PSTR)(String) )
#define DNSSTRING_WIDE( fUnicode, String ) \
        ( (fUnicode) ? (PWSTR)(String) : pDnsEmptyWideString )
#define PRINT_STRING_WIDE_CHARSET( String, CharSet ) \
        ( ((CharSet)==DnsCharSetUnicode) ? (PWSTR)(String) : pDnsEmptyWideString )
#define PRINT_STRING_ANSI_CHARSET( String, CharSet ) \
        ( ((CharSet)==DnsCharSetUnicode) ? pDnsEmptyString : (PSTR)(String) )

// public\internal\ds\inc\dnsrpc.h
#define GET_NEXT_STAT_IN_BUFFER( pStat ) \
            ((PDNSSRV_STAT)( (PCHAR)(pStat) + TOTAL_STAT_LENGTH(pStat) ))
#define DNS_GET_END_OF_RPC_RECORD_DATA(pRecord) \
            ( (PCHAR)&(pRecord)->Data + (pRecord)->wDataLength )

// public\internal\ds\inc\xom.h
#define OM_STRING(string)       \
        { (OM_string_length)(sizeof(string)-1), (string) }

// public\internal\ds\inc\xomi.h
#define om_get(ORIGINAL,EXCLUSIONS,TYPES,LOCAL_STRINGS,INITIAL,LIMIT,COPY,TOTAL_NUMBER) \
((ORIGINAL)->type == OM_PRIVATE_OBJECT ? OMP_FUNCTIONS(ORIGINAL)->get((ORIGINAL),(EXCLUSIONS),(TYPES),(LOCAL_STRINGS),(INITIAL),(LIMIT),(COPY),(TOTAL_NUMBER)) : OM_NOT_PRIVATE)
#define om_get(ORIGINAL,EXCLUSIONS,TYPES,LOCAL_STRINGS,INITIAL,LIMIT,COPY,TOTAL_NUMBER) \
((ORIGINAL)->type == OM_PRIVATE_OBJECT ? OMP_FUNCTIONS(ORIGINAL)->_get((ORIGINAL),(EXCLUSIONS),(TYPES),(LOCAL_STRINGS),(INITIAL),(LIMIT),(COPY),(TOTAL_NUMBER)) : OM_NOT_PRIVATE)

// public\internal\net\inc\icanon.h
#define ITYPE_SYS_PRINT         (ITYPE_SYS|0x500)
#define   ITYPE_PATH_SYS_PRINT  (ITYPE_PATH_SYS|ITYPE_SYS_PRINT)
#define   ITYPE_PATH_SYS_PRINT_M (ITYPE_PATH_SYS|ITYPE_SYS_PRINT|ITYPE_META)

// public\internal\net\inc\isnkrnl.h
#define MSPX_SETDATASTREAM (I_MSPX | 2)   /* Set datastream type          */

// public\internal\net\inc\rasuip.h
#define RasIsEqualSharedConnection( _pConn1, _pConn2 ) \
( \
    ((_pConn1)->fIsLanConnection == (_pConn2)->fIsLanConnection) && \
    ((_pConn1)->fIsLanConnection \
        ? !memcmp(&(_pConn1)->guid, &(_pConn2)->guid, sizeof(GUID)) \
        : (!lstrcmpiW( \
                (_pConn1)->name.szPhonebookPath, \
                (_pConn2)->name.szPhonebookPath) && \
           !lstrcmpiW( \
                (_pConn1)->name.szEntryName, \
                (_pConn2)->name.szEntryName))) \
)

// public\internal\sdktools\inc\ehdata.h
#define REAL_FP(VirtualFP, pFuncInfo)           \
    (((EHContext *)((char *)VirtualFP           \
     + pFuncInfo->EHContextDelta)) -> Rfp)
#define EH_STATE(VirtualFP, pFuncInfo)          \
    (((EHContext *)((char *)VirtualFP           \
     + pFuncInfo->EHContextDelta)) -> State)

// public\internal\shell\inc\comctrlp.h
#define TB_HASACCELERATOR       (WM_USER + 95)  // wParem == char, lParam = &iCount
#define BL_GETTEXT              (WM_USER+8)
#define BL_GETTEXTLEN           (WM_USER+9)

// public\internal\shell\inc\powrprofp.h
#define STRSIZE(psz) ((lstrlen(psz) + 1) * sizeof(TCHAR))
#define SIZE_DEC_DIGITS (10+1+1) * sizeof(TCHAR)

// public\internal\shell\inc\shlobjp.h
#define CWM_CHANGEREGISTRATION          (WM_USER + 17)
#define CWM_TASKBARWAKEUP               (WM_USER + 26) // Used to restore tray thread to normal priority in extremely stressed machines
#define OAIF_ALL                    (OAIF_ALLOW_REGISTRATION | OAIF_REGISTER_EXT | OAIF_EXEC | OAIF_FORCE_REGISTRATION)  //

// public\internal\shell\inc\systrayp.h
#define STWM_NOTIFYPOWER                (WM_USER + 201)
#define STWM_NOTIFYPCMCIA               (WM_USER + 202)
#define STWM_NOTIFYVOLUME               (WM_USER + 203)
#define STWM_NOTIFYMOUSEKEYS            (WM_USER + 205)
#define STWM_NOTIFYFILTERKEYS           (WM_USER + 206)
#define STWM_NOTIFYCSC                  (WM_USER + 207)
#define STWM_NOTIFYUSBUI                (WM_USER + 208)
#define STWM_ENABLESERVICE              (WM_USER + 220)
#define STWM_GETSTATE                   (WM_USER + 221)

// public\internal\termsrv\inc\rdpdr.h
#define DR_NEXTDEVICEANNOUNCE(DeviceAnnounce) \
    (PRDPDR_DEVICE_ANNOUNCE) \
    ((((PUCHAR)(DeviceAnnounce)) + sizeof(RDPDR_DEVICE_ANNOUNCE) + \
    ((DeviceAnnounce)->DeviceDataLength)))
#define DR_NEXTDEVICEREMOVE(DeviceRemove) \
    (PRDPDR_DEVICE_REMOVE) \
    ((((PUCHAR)(DeviceRemove)) + sizeof(RDPDR_DEVICE_REMOVE)))

// public\internal\termsrv\inc\tsappcmp.h
#define TERMSRV_CLASSES_SIZE sizeof(WCHAR)*(sizeof(TERMSRV_INSTALLCLASSES)+1)

// public\internal\windows\inc\duser\dusercore.h
#define IGTM_SEPARATE           (2)     // | MT with single thread per context
#define IGTM_MULTIPLE           (3)     // | MT with multiple threads per context

// public\internal\windows\inc\immp.h
#define SCS_SETSTR                      (GCS_COMPREADSTR|GCS_COMPSTR)
#define GCS_COMP                        (GCS_COMPSTR|GCS_COMPATTR|GCS_COMPCLAUSE)
#define GCS_COMPREAD                    (GCS_COMPREADSTR|GCS_COMPREADATTR |GCS_COMPREADCLAUSE)
#define GCS_RESULT                      (GCS_RESULTSTR|GCS_RESULTCLAUSE)
#define GCS_RESULTREAD                  (GCS_RESULTREADSTR|GCS_RESULTREADCLAUSE)

// public\internal\windows\inc\ntgdistr.h
#define LO_ALTDC_TYPE       (LO_DC_TYPE        | ALTTYPE1)
#define LO_PEN_TYPE         (LO_BRUSH_TYPE     | ALTTYPE1)
#define LO_EXTPEN_TYPE      (LO_BRUSH_TYPE     | ALTTYPE2)
#define LO_METAFILE16_TYPE  (LO_CLIENTOBJ_TYPE | ALTTYPE1)
#define LO_METAFILE_TYPE    (LO_CLIENTOBJ_TYPE | ALTTYPE2)
#define LO_METADC16_TYPE    (LO_CLIENTOBJ_TYPE | ALTTYPE3)
    #define lEfToF(x)          (*(LONG *)(&x))  // Warning: FLOAT typed as LONG!
    #define efDivEFLOAT(x,y,z) (*divff3_c(&x,&y,&z))
    #define vFxToEf(fx,ef)     (fxtoef_c(fx,&ef))
    #define vMulEFLOAT(x,y,z)  {mulff3_c(&x,&y,&z);}
    #define lEfToF(x)          (eftof_c(&x))  // Warning: FLOAT typed as LONG!
    #define bEqualEFLOAT(x,y) ((x.lMant==y.lMant)&&(x.lExp==y.lExp))
    #define bIsOneEFLOAT(x)   ((x.lMant==0x40000000L)&&(x.lExp==2))
    #define bIsOneSixteenthEFLOAT(x)   ((x.lMant==0x40000000L)&&(x.lExp==-2))

// public\internal\windows\inc\shimcstring.h
#define afxEmptyString ((CString &)*(CString*)&CString::_afxPchNil)
#define CSTRING_CATCH               catch( CString::CStringError & cse )

// public\internal\windows\inc\shimdb.h
#define GETTAGTYPE(tag)         ((tag) & TAG_STRIP_TYPE)
#define TAG_NAME                (0x1  | TAG_TYPE_STRINGREF)
#define TAG_DESCRIPTION         (0x2  | TAG_TYPE_STRINGREF)
#define TAG_MODULE              (0x3  | TAG_TYPE_STRINGREF)
#define TAG_API                 (0x4  | TAG_TYPE_STRINGREF)
#define TAG_VENDOR              (0x5  | TAG_TYPE_STRINGREF)
#define TAG_APP_NAME            (0x6  | TAG_TYPE_STRINGREF)
#define TAG_COMMAND_LINE        (0x8  | TAG_TYPE_STRINGREF)
#define TAG_COMPANY_NAME        (0x9  | TAG_TYPE_STRINGREF)
#define TAG_DLLFILE             (0xA  | TAG_TYPE_STRINGREF)
#define TAG_WILDCARD_NAME       (0xB  | TAG_TYPE_STRINGREF)
#define TAG_PRODUCT_NAME        (0x10 | TAG_TYPE_STRINGREF)
#define TAG_PRODUCT_VERSION     (0x11 | TAG_TYPE_STRINGREF)
#define TAG_FILE_DESCRIPTION    (0x12 | TAG_TYPE_STRINGREF)
#define TAG_FILE_VERSION        (0x13 | TAG_TYPE_STRINGREF)
#define TAG_ORIGINAL_FILENAME   (0x14 | TAG_TYPE_STRINGREF)
#define TAG_INTERNAL_NAME       (0x15 | TAG_TYPE_STRINGREF)
#define TAG_LEGAL_COPYRIGHT     (0x16 | TAG_TYPE_STRINGREF)
#define TAG_APPHELP_DETAILS     (0x18 | TAG_TYPE_STRINGREF) // Details in single language
#define TAG_LINK_URL            (0x19 | TAG_TYPE_STRINGREF)
#define TAG_LINK_TEXT           (0x1A | TAG_TYPE_STRINGREF)
#define TAG_APPHELP_TITLE       (0x1B | TAG_TYPE_STRINGREF)
#define TAG_APPHELP_CONTACT     (0x1C | TAG_TYPE_STRINGREF)
#define TAG_SXS_MANIFEST        (0x1D | TAG_TYPE_STRINGREF)
#define TAG_DATA_STRING         (0x1E | TAG_TYPE_STRINGREF)
#define TAG_MSI_TRANSFORM_FILE  (0x1F | TAG_TYPE_STRINGREF)
#define TAG_LAYER_DISPLAYNAME   (0x21 | TAG_TYPE_STRINGREF)
#define TAG_COMPILER_VERSION    (0x22 | TAG_TYPE_STRINGREF)
#define TAG_ACTION_TYPE         (0x23 | TAG_TYPE_STRINGREF)
#define TAG_STRINGTABLE         (0x801 | TAG_TYPE_LIST)
#define TAG_STRINGTABLE_ITEM    (0x801 | TAG_TYPE_STRING)

// public\internal\windows\inc\shimtags.h
#define TAG_NAME              (0x1  | TAG_TYPE_STRINGREF)
#define TAG_DESCRIPTION       (0x2  | TAG_TYPE_STRINGREF)
#define TAG_MODULE            (0x3  | TAG_TYPE_STRINGREF)
#define TAG_API               (0x4  | TAG_TYPE_STRINGREF)
#define TAG_VENDOR            (0x5  | TAG_TYPE_STRINGREF)   // hopefully never used
#define TAG_APP_NAME          (0x6  | TAG_TYPE_STRINGREF)
#define TAG_SHORTNAME         (0x7  | TAG_TYPE_STRINGREF)
#define TAG_COMMAND_LINE      (0x8  | TAG_TYPE_STRINGREF)
#define TAG_COMPANY_NAME      (0x9  | TAG_TYPE_STRINGREF)
#define TAG_WILDCARD_NAME     (0xA  | TAG_TYPE_STRINGREF)
#define TAG_PRODUCT_NAME      (0x10 | TAG_TYPE_STRINGREF)
#define TAG_PRODUCT_VERSION   (0x11 | TAG_TYPE_STRINGREF)
#define TAG_FILE_DESCRIPTION  (0x12 | TAG_TYPE_STRINGREF)
#define TAG_FILE_VERSION      (0x13 | TAG_TYPE_STRINGREF)
#define TAG_ORIGINAL_FILENAME (0x14 | TAG_TYPE_STRINGREF)
#define TAG_INTERNALNAME      (0x15 | TAG_TYPE_STRINGREF)
#define TAG_LEGALCOPYRIGHT    (0x16 | TAG_TYPE_STRINGREF)
#define TAG_APPHELP_DETAILS   (0x18 | TAG_TYPE_STRINGREF) // details in single language
#define TAG_LINK_URL          (0x19 | TAG_TYPE_STRINGREF)
#define TAG_LINK_TEXT         (0x1A | TAG_TYPE_STRINGREF)
#define TAG_APPHELP_TITLE     (0x1B | TAG_TYPE_STRINGREF)
#define TAG_APPHELP_CONTACT   (0x1C | TAG_TYPE_STRINGREF)
#define TAG_SXS_MANIFEST      (0x1D | TAG_TYPE_STRINGREF)
#define TAG_STRINGTABLE       (0x801 | TAG_TYPE_LIST)
#define TAG_STRINGTABLE_ITEM (0x801 | TAG_TYPE_STRING)

// public\internal\windows\inc\winuserp.h
#define DC_CAPTION          (DC_ICON | DC_TEXT | DC_BUTTONS)
#define SWP_NOTIFYALL       (SWP_NOTIFYCREATE | SWP_NOTIFYDESTROY | SWP_NOTIFYACTIVATE | SWP_NOTIFYFS)

// public\oak\inc\immdev.h
#define SCS_SETSTR                      (GCS_COMPREADSTR|GCS_COMPSTR)
#define GCS_COMP                        (GCS_COMPSTR|GCS_COMPATTR|GCS_COMPCLAUSE)
#define GCS_COMPREAD                    (GCS_COMPREADSTR|GCS_COMPREADATTR |GCS_COMPREADCLAUSE)
#define GCS_RESULT                      (GCS_RESULTSTR|GCS_RESULTCLAUSE)
#define GCS_RESULTREAD                  (GCS_RESULTREADSTR|GCS_RESULTREADCLAUSE)

// public\sdk\amovie\inc\winutil.h
#define SHOWSTAGE TEXT("WM_SHOWSTAGE")
#define SHOWSTAGETOP TEXT("WM_SHOWSTAGETOP")

// public\sdk\amovie\inc\wxdebug.h
    #define KASSERT(_x_) if (!(_x_))         \
        DbgKernelAssert(TEXT(#_x_),TEXT(__FILE__),__LINE__)
    #define KDbgBreak(_x_)                   \
        DbgKernelAssert(TEXT(#_x_),TEXT(__FILE__),__LINE__)

// public\sdk\inc16\windows.h
#define EM_LIMITTEXT            (WM_USER+21)
#define EM_LINEFROMCHAR         (WM_USER+25)
#define LB_ADDSTRING           (WM_USER+1)
#define LB_INSERTSTRING        (WM_USER+2)
#define LB_DELETESTRING        (WM_USER+3)
#define LB_GETTEXT             (WM_USER+10)
#define LB_GETTEXTLEN          (WM_USER+11)
#define LB_SELECTSTRING        (WM_USER+13)
#define LB_FINDSTRING          (WM_USER+16)
#define LB_FINDSTRINGEXACT     (WM_USER+35)

// public\sdk\inc16\windowsx.h
#define HANDLE_WM_WININICHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define HANDLE_WM_DEVMODECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_DEVMODECHANGE(hwnd, lpszDeviceName, fn) \
    (void)(fn)((hwnd), WM_DEVMODECHANGE, 0,(LPARAM)(LPCSTR)(lpszDeviceName))
#define HANDLE_WM_DESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROY, 0, 0L)
#define HANDLE_WM_NCDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_NCDESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_NCDESTROY, 0, 0L)
#define HANDLE_WM_SETTEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCSTR)(lParam)), 0L)
#define FORWARD_WM_SETTEXT(hwnd, lpszText, fn) \
    (void)(fn)((hwnd), WM_SETTEXT, 0, (LPARAM)(LPCSTR)(lpszText))
#define FORWARD_WM_CHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_CHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define FORWARD_WM_DEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_DEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat),0))
#define FORWARD_WM_SYSCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define FORWARD_WM_SYSDEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSDEADCHAR, (WPARAM)(UINT)(ch), MAKELPARAM((UINT)(cRepeat), 0))
#define HANDLE_WM_DESTROYCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROYCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROYCLIPBOARD, 0, 0L)
#define HANDLE_WM_MDIDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIDESTROY(hwnd, hwndDestroy, fn) \
    (void)(fn)((hwnd), WM_MDIDESTROY, (WPARAM)(hwndDestroy), 0L)
#define Edit_ReplaceSel(hwndCtl, lpszReplace)   ((void)SendMessage((hwndCtl), EM_REPLACESEL, 0, (LPARAM)(LPCSTR)(lpszReplace)))
#define ComboBox_GetTextLength(hwndCtl)         GetWindowTextLength(hwndCtl)
#define ComboBox_SetText(hwndCtl, lpsz)         SetWindowText((hwndCtl), (lpsz))

// public\sdk\inc\allerror.h
#define DB_E_BADINITSTRING               ((HRESULT)0x80040E73L)

// public\sdk\inc\atl21\atlcom.h
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

// public\sdk\inc\atl21\atlres.h
#define LB_ADDSTRING    (WM_USER+1)

// public\sdk\inc\atl30\atlcom.h
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

// public\sdk\inc\atl30\atldbcli.h
#define DEFINE_COMMAND(x, szCommand) \
	typedef x _CommandClass; \
	static HRESULT GetDefaultCommand(LPCTSTR* ppszCommand) \
	{ \
		*ppszCommand = szCommand; \
		return S_OK; \
	}

// public\sdk\inc\certcli.h
#define	CR_GEMT_HRESULT_STRING	( 0x1 )

// public\sdk\inc\cierror.h
#define WBREAK_E_END_OF_TEXT             ((HRESULT)0x80041780L)

// public\sdk\inc\commctrl.h
#define TB_ADDSTRINGA           (WM_USER + 28)
#define TB_ADDSTRINGW           (WM_USER + 77)
#define TB_GETBUTTONTEXTA       (WM_USER + 45)
#define TB_GETBUTTONTEXTW       (WM_USER + 75)
#define TB_GETTEXTROWS          (WM_USER + 61)
#define TB_SETEXTENDEDSTYLE     (WM_USER + 84)  // For TBSTYLE_EX_*
#define TB_GETEXTENDEDSTYLE     (WM_USER + 85)  // For TBSTYLE_EX_*
#define TB_GETSTRINGW           (WM_USER + 91)
#define TB_GETSTRINGA           (WM_USER + 92)
#define TTM_GETTEXTA            (WM_USER +11)
#define TTM_GETTEXTW            (WM_USER +56)
#define TTM_UPDATETIPTEXTA      (WM_USER +12)
#define TTM_UPDATETIPTEXTW      (WM_USER +57)
#define TTM_SETTITLEA           (WM_USER + 32)  // wParam = TTI_*, lParam = char* szTitle
#define TTM_SETTITLEW           (WM_USER + 33)  // wParam = TTI_*, lParam = wchar* szTitle
#define SB_SETTEXTA             (WM_USER+1)
#define SB_SETTEXTW             (WM_USER+11)
#define SB_GETTEXTA             (WM_USER+2)
#define SB_GETTEXTW             (WM_USER+13)
#define SB_GETTEXTLENGTHA       (WM_USER+3)
#define SB_GETTEXTLENGTHW       (WM_USER+12)
#define SB_SETTIPTEXTA          (WM_USER+16)
#define SB_SETTIPTEXTW          (WM_USER+17)
#define SB_GETTIPTEXTA          (WM_USER+18)
#define SB_GETTIPTEXTW          (WM_USER+19)
#define TreeView_GetISearchString(hwndTV, lpsz) \
        (BOOL)SNDMSG((hwndTV), TVM_GETISEARCHSTRING, 0, (LPARAM)(LPTSTR)(lpsz))
#define TreeView_SetUnicodeFormat(hwnd, fUnicode)  \
    (BOOL)SNDMSG((hwnd), TVM_SETUNICODEFORMAT, (WPARAM)(fUnicode), 0)
#define TreeView_GetUnicodeFormat(hwnd)  \
    (BOOL)SNDMSG((hwnd), TVM_GETUNICODEFORMAT, 0, 0)
#define TabCtrl_SetUnicodeFormat(hwnd, fUnicode)  \
    (BOOL)SNDMSG((hwnd), TCM_SETUNICODEFORMAT, (WPARAM)(fUnicode), 0)
#define TabCtrl_GetUnicodeFormat(hwnd)  \
    (BOOL)SNDMSG((hwnd), TCM_GETUNICODEFORMAT, 0, 0)

// public\sdk\inc\commdlg.h
#define CF_BOTH                    (CF_SCREENFONTS | CF_PRINTERFONTS)

// public\sdk\inc\crt\ctype.h
#define iswprint(_c)    ( iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT) )

// public\sdk\inc\crt\mbctype.h
#define _ismbbkalnum(_c)    ((_mbctype+1)[(unsigned char)(_c)] & _MS)
#define _ismbbkprint(_c)    ((_mbctype+1)[(unsigned char)(_c)] & (_MS|_MP))
#define _ismbbkpunct(_c)    ((_mbctype+1)[(unsigned char)(_c)] & _MP)
#define _ismbbalnum(_c) (((_ctype+1)[(unsigned char)(_c)] & (_ALPHA|_DIGIT))||_ismbbkalnum(_c))
#define _ismbbalpha(_c) (((_ctype+1)[(unsigned char)(_c)] & (_ALPHA))||_ismbbkalnum(_c))
#define _ismbbgraph(_c) (((_ctype+1)[(unsigned char)(_c)] & (_PUNCT|_ALPHA|_DIGIT))||_ismbbkprint(_c))
#define _ismbbprint(_c) (((_ctype+1)[(unsigned char)(_c)] & (_BLANK|_PUNCT|_ALPHA|_DIGIT))||_ismbbkprint(_c))
#define _ismbbpunct(_c) (((_ctype+1)[(unsigned char)(_c)] & _PUNCT)||_ismbbkpunct(_c))
#define _ismbblead(_c)  ((_mbctype+1)[(unsigned char)(_c)] & _M1)
#define _ismbbtrail(_c) ((_mbctype+1)[(unsigned char)(_c)] & _M2)
#define _ismbbkana(_c)  ((_mbctype+1)[(unsigned char)(_c)] & (_MS|_MP))

// public\sdk\inc\crt\wchar.h
#define iswalnum(_c)    ( iswctype(_c,_ALPHA|_DIGIT) )
#define iswprint(_c)    ( iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT) )
#define iswgraph(_c)    ( iswctype(_c,_PUNCT|_ALPHA|_DIGIT) )

// public\sdk\inc\crt\wctype.h
#define iswprint(_c)    ( iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT) )

// public\sdk\inc\ctfutb.h
#define TF_LBI_BTNALL              (TF_LBI_ICON | TF_LBI_TEXT | TF_LBI_TOOLTIP)

// public\sdk\inc\d3d.h
#define D3DERR_EXECUTE_DESTROY_FAILED   MAKE_DDHRESULT(711)
#define D3DERR_TEXTURE_NO_SUPPORT   MAKE_DDHRESULT(720)
#define D3DERR_TEXTURE_CREATE_FAILED    MAKE_DDHRESULT(721)
#define D3DERR_TEXTURE_DESTROY_FAILED   MAKE_DDHRESULT(722)
#define D3DERR_TEXTURE_GETSURF_FAILED   MAKE_DDHRESULT(729)
#define D3DERR_MATRIX_DESTROY_FAILED    MAKE_DDHRESULT(731)
#define D3DERR_TEXTURE_BADSIZE          MAKE_DDHRESULT(738)
#define D3DERR_MATERIAL_DESTROY_FAILED  MAKE_DDHRESULT(741)
#define D3DERR_WRONGTEXTUREFORMAT               MAKE_DDHRESULT(2072)
#define D3DERR_CONFLICTINGTEXTUREFILTER         MAKE_DDHRESULT(2078)
#define D3DERR_UNSUPPORTEDTEXTUREFILTER         MAKE_DDHRESULT(2082)

// public\sdk\inc\d3d8.h
#define D3DERR_WRONGTEXTUREFORMAT               MAKE_D3DHRESULT(2072)
#define D3DERR_CONFLICTINGTEXTUREFILTER         MAKE_D3DHRESULT(2078)
#define D3DERR_UNSUPPORTEDTEXTUREFILTER         MAKE_D3DHRESULT(2082)

// public\sdk\inc\d3d8types.h
#define D3DVSD_STREAM( _StreamNumber ) \
    (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_STREAM) | (_StreamNumber))

// public\sdk\inc\d3drm.h
#define D3DRMERR_TEXTUREFORMATNOTFOUND  MAKE_DDHRESULT(811)

// public\sdk\inc\d3dxerr.h
#define D3DXERR_FAILEDDRAWTEXT    ((HRESULT)0xC8770BC9L)
#define D3DXERR_BADD3DXCONTEXT    ((HRESULT)0xC8770BCAL)
#define D3DXERR_NOTEXTURE    ((HRESULT)0xC8770BD5L)

// public\sdk\inc\dbghelp.h
#define UNDNAME_NO_FUNCTION_RETURNS      (0x0004)  // Disable expansion of return type for primary declaration
#define UNDNAME_NO_RETURN_UDT_MODEL      (0x0400)  // Disable expansion of MS model for UDT returns

// public\sdk\inc\dciddi.h
#define DCI_CAN_STRETCHXY                       (DCI_CAN_STRETCHX | DCI_CAN_STRETCHY)
#define DCI_CAN_STRETCHXYN                      (DCI_CAN_STRETCHXN | DCI_CAN_STRETCHYN)

// public\sdk\inc\ddraw.h
#define DDERR_NOSTRETCHHW                       MAKE_DDHRESULT( 310 )
#define DDERR_NOTEXTUREHW                       MAKE_DDHRESULT( 330 )

// public\sdk\inc\dmerror.h
#define DMUS_S_STRING_TRUNCATED         MAKE_DMHRESULTSUCCESS(0x210)
#define DMUS_E_BADINSTRUMENT            MAKE_DMHRESULTERROR(0x0127)
#define DMUS_E_UNSUPPORTED_STREAM       MAKE_DMHRESULTERROR(0x0150)

// public\sdk\inc\dplay8.h
#define DPNERR_HOSTREJECTEDCONNECTION	MAKE_DPNHRESULT( 0x260 )

// public\sdk\inc\dxfile.h
#define DXFILEERR_BADSTREAMHANDLE           MAKE_DDHRESULT(853)
#define DXFILEERR_NOMORESTREAMHANDLES       MAKE_DDHRESULT(873)

// public\sdk\inc\except.hxx
#define CATCH(class, e)                                                  \
        __except( Unwind( GetExceptionInformation(), &_trycontext ) )      \
        {                                                                \
            CExceptionContext& _exceptioncontext = _ExceptionContext();  \
            if (_exceptioncontext._exception.IsKindOf(#class))           \
            {                                                            \
                class & e = (class &)_exceptioncontext._exception;
#define AND_CATCH(class, e)                                                 \
            }                                                               \
            else if (_exceptioncontext._exception.IsKindOf(#class))         \
            {                                                               \
                class & e = ( class &)_exceptioncontext._exception;
#define CATCH(class, e)                                                 \
                                                                        \
        else                                                            \
        {                                                               \
            CExceptionContext& _exceptioncontext = _ExceptionContext(); \
            if (_exceptioncontext._exception.IsKindOf(#class))          \
            {                                                           \
                class & e = (class &)_exceptioncontext._exception;
#define AND_CATCH(class, e)                                                 \
                                                                            \
            }                                                               \
            else if (_exceptioncontext._exception.IsKindOf(#class))         \
            {                                                               \
                class & e = (class &)_exceptioncontext._exception;

// public\sdk\inc\filterr.h
#define FILTER_E_NO_MORE_TEXT            ((HRESULT)0x80041701L)
#define FILTER_E_NO_TEXT                 ((HRESULT)0x80041705L)
#define FILTER_S_LAST_TEXT               ((HRESULT)0x00041709L)

// public\sdk\inc\getuser.h
#define USRBROWS_INCL_ALL           (USRBROWS_INCL_REMOTE_USERS |\
                                     USRBROWS_INCL_INTERACTIVE  |\
                                     USRBROWS_INCL_EVERYONE     |\
                                     USRBROWS_INCL_CREATOR      |\
                                     USRBROWS_INCL_SYSTEM	|\
                                     USRBROWS_INCL_RESTRICTED)

// public\sdk\inc\imm.h
#define SCS_SETSTR                      (GCS_COMPREADSTR|GCS_COMPSTR)

// public\sdk\inc\ks.h
#define KSPROBE_STREAMWRITEMODIFY (KSPROBE_MODIFY | KSPROBE_STREAMWRITE)
#define KSCREATE_ITEM_IRP_STORAGE(Irp)      (*(PKSOBJECT_CREATE_ITEM*)&(Irp)->Tail.Overlay.DriverContext[0])
#define KSEVENT_ITEM_IRP_STORAGE(Irp)       (*(const KSEVENT_ITEM**)&(Irp)->Tail.Overlay.DriverContext[3])
#define KSMETHOD_ITEM_IRP_STORAGE(Irp)      (*(const KSMETHOD_ITEM**)&(Irp)->Tail.Overlay.DriverContext[3])
#define KSPROPERTY_ITEM_IRP_STORAGE(Irp)    (*(const KSPROPERTY_ITEM**)&(Irp)->Tail.Overlay.DriverContext[3])
#define KsDeleteFilterFactory(FilterFactory) \
    KsFreeObjectCreateItemsByContext(\
        *(KSDEVICE_HEADER *)(\
            KsFilterFactoryGetParentDevice(FilterFactory)->FunctionalDeviceObject->\
                DeviceExtension),\
        FilterFactory)

// public\sdk\inc\ksmedia.h
#define INIT_USBAUDIO_PRODUCT_NAME(guid, vid, pid, strIndex)\
{\
    (guid)->Data1 = 0XFC575048 + (USHORT)(vid);\
    (guid)->Data2 = 0x2E08     + (USHORT)(pid);\
    (guid)->Data3 = 0x463B     + (USHORT)(strIndex);\
    (guid)->Data4[0] = 0xA7;\
    (guid)->Data4[1] = 0x2F;\
    (guid)->Data4[2] = 0xA5;\
    (guid)->Data4[3] = 0xBF;\
    (guid)->Data4[4] = 0x64;\
    (guid)->Data4[5] = 0xC8;\
    (guid)->Data4[6] = 0x6E;\
    (guid)->Data4[7] = 0xBA;\
}

// public\sdk\inc\mfc42\afx.h
#define afxEmptyString ((CString&)*(CString*)&_afxPchNil)

// public\sdk\inc\mfc42\afxctl.h
#define DISP_STOCKPROP_CAPTION() \
	DISP_PROPERTY_STOCK(COleControl, "Caption", DISPID_CAPTION, \
		COleControl::GetText, COleControl::SetText, VT_BSTR)
#define DISP_STOCKPROP_TEXT() \
	DISP_PROPERTY_STOCK(COleControl, "Text", DISPID_TEXT, \
		COleControl::GetText, COleControl::SetText, VT_BSTR)

// public\sdk\inc\mfc42\afxmsg_.h
#define ON_WM_DESTROY() \
	{ WM_DESTROY, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))&OnDestroy },
#define ON_WM_SETTINGCHANGE() \
	{ WM_SETTINGCHANGE, 0, 0, 0, AfxSig_vws, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, LPCTSTR))&OnSettingChange },
#define ON_WM_WININICHANGE() \
	{ WM_WININICHANGE, 0, 0, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(LPCTSTR))&OnWinIniChange },
#define ON_WM_DEVMODECHANGE() \
	{ WM_DEVMODECHANGE, 0, 0, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(LPTSTR))&OnDevModeChange },
#define ON_WM_NCDESTROY() \
	{ WM_NCDESTROY, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))&OnNcDestroy },
#define ON_WM_CHAR() \
	{ WM_CHAR, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))&OnChar },
#define ON_WM_DEADCHAR() \
	{ WM_DEADCHAR, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))&OnDeadChar },
#define ON_WM_SYSCHAR() \
	{ WM_SYSCHAR, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))&OnSysChar },
#define ON_WM_SYSDEADCHAR() \
	{ WM_SYSDEADCHAR, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))&OnSysDeadChar },
#define ON_WM_MENUCHAR() \
	{ WM_MENUCHAR, 0, 0, 0, AfxSig_lwwM, \
		(AFX_PMSG)(AFX_PMSGW)(LRESULT (AFX_MSG_CALL CWnd::*)(UINT, UINT, CMenu*))&OnMenuChar },
#define ON_WM_DESTROYCLIPBOARD() \
	{ WM_DESTROYCLIPBOARD, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))&OnDestroyClipboard },

// public\sdk\inc\mfc42\winres.h
#define LB_ADDSTRING    (WM_USER+1)

// public\sdk\inc\mmstream.h
#define MS_ERROR_CODE(x) MAKE_HRESULT(1, FACILITY_ITF, (x) + 0x400)
#define MS_SUCCESS_CODE(x) MAKE_HRESULT(0, FACILITY_ITF, x)

// public\sdk\inc\mq.h
#define MQMSG_ACKNOWLEDGMENT_NACK_RECEIVE ((UCHAR)( \
            MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL |  \
            MQMSG_ACKNOWLEDGMENT_NEG_RECEIVE ))
#define MQMSG_ACKNOWLEDGMENT_FULL_RECEIVE ((UCHAR)( \
            MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL |  \
            MQMSG_ACKNOWLEDGMENT_NEG_RECEIVE |  \
            MQMSG_ACKNOWLEDGMENT_POS_RECEIVE ))

// public\sdk\inc\msctf.h
#define TF_E_EMPTYCONTEXT    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0509)

// public\sdk\inc\netmon.h
#define DebugBreak()    dprintf("DebugBreak Called at %s:%s", __FILE__, __LINE__);

// public\sdk\inc\ntalpha.h
#define CONTEXT_CONTROL         (CONTEXT_ALPHA | 0x00000001L)
#define CONTEXT_INTEGER         (CONTEXT_ALPHA | 0x00000004L)

// public\sdk\inc\ntamd64.h
#define CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#define CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#define CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#define CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)
#define PROGRAM_COUNTER_TO_CONTEXT(Context, ProgramCounter) \
    ((Context)->Rip = (ProgramCounter))

// public\sdk\inc\ntddpcm.h
#define PCMRES_GET_AUDIO_ENABLE(desc) ((UCHAR) ((desc)->u.DevicePrivate.Data[0] &  PCMRESF_AUDIO_ENABLE) != 0)

// public\sdk\inc\ntdef.h
#define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1]

// public\sdk\inc\ntfsprop.h
#define COUNTED_STRING_LENGTH(c)    \
    ((c)->Length)
#define COUNTED_STRING_TEXT(c)      \
    (&(c)->Text[0])
#define PROPERTY_SPECIFIER_NAME(PS,I)    \
    (&PROPERTY_SPECIFIER_COUNTED_STRING( PS, I )->Text[0])
#define PROPERTY_SPECIFIER_NAME_LENGTH(PS,I) \
    (PROPERTY_SPECIFIER_COUNTED_STRING( PS, I )->Length)

// public\sdk\inc\nti386.h
#define CONTEXT_INTEGER         (CONTEXT_i386 | 0x00000002L) // AX, BX, CX, DX, SI, DI
#define CONTEXT_SEGMENTS        (CONTEXT_i386 | 0x00000004L) // DS, ES, FS, GS
#define CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L) // DB 0-3,6,7
#define CONTEXT_EXTENDED_REGISTERS  (CONTEXT_i386 | 0x00000020L) // cpu specific extensions
#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER |\
                      CONTEXT_SEGMENTS)

// public\sdk\inc\ntia64.h
#define CONTEXT_CONTROL                 (CONTEXT_IA64 | 0x00000001L)
#define CONTEXT_INTEGER                 (CONTEXT_IA64 | 0x00000008L)
#define CONTEXT_DEBUG                   (CONTEXT_IA64 | 0x00000010L)
#define CONTEXT_IA32_CONTROL            (CONTEXT_IA64 | 0x00000020L)  // Includes StIPSR

// public\sdk\inc\ntmips.h
#define CONTEXT_CONTROL          (CONTEXT_R4000 | 0x00000001)
#define CONTEXT_INTEGER          (CONTEXT_R4000 | 0x00000004)
#define CONTEXT_EXTENDED_INTEGER (CONTEXT_INTEGER | 0x00000010)

// public\sdk\inc\ntrtl.h
#define RTL_SOFT_ASSERT(_exp) \
    ((!(_exp)) ? \
        (DbgPrint("%s(%d): Soft assertion failed\n   Expression: %s\n", __FILE__, __LINE__, #_exp),FALSE) : \
        TRUE)
#define RTL_SOFT_ASSERTMSG(_msg, _exp) \
    ((!(_exp)) ? \
        (DbgPrint("%s(%d): Soft assertion failed\n   Expression: %s\n   Message: %s\n", __FILE__, __LINE__, #_exp, (_msg)),FALSE) : \
        TRUE)

// public\sdk\inc\ntstatus.h
#define STATUS_REGISTRY_IO_FAILED        ((NTSTATUS)0xC000014DL)

// public\sdk\inc\oledberr.h
#define DB_E_BADINITSTRING               ((HRESULT)0x80040E73L)
#define DB_E_BADCONSTRAINTTYPE           ((HRESULT)0x80040E77L)
#define DB_E_BADCONSTRAINTFORM           ((HRESULT)0x80040E78L)
#define DB_E_BADCONSTRAINTID             ((HRESULT)0x80040E8BL)
#define DB_E_DROPRESTRICTED              ((HRESULT)0x80040E90L)
#define DB_E_DUPLICATECONSTRAINTID       ((HRESULT)0x80040E99L)
#define DB_E_ALTERRESTRICTED             ((HRESULT)0x80040E9DL)
#define DB_E_NOCONSTRAINT                ((HRESULT)0x80040E9FL)

// public\sdk\inc\penwin.h
#define CWR_SINGLELINEEDIT      (CWR_REPLACECR|CWR_STRIPLF|CWR_REPLACETAB)  // all of the above
#define FIsAnsiGesture(syv) \
   (                            \
   (syv) == SYV_BACKSPACE       \
   || (syv) == SYV_TAB          \
   || (syv) == SYV_RETURN       \
   || (syv) == SYV_SPACE        \
   )

// public\sdk\inc\prsht.h
#define PSM_SETFINISHTEXTA      (WM_USER + 115)
#define PSM_SETFINISHTEXTW      (WM_USER + 121)

// public\sdk\inc\pwin16.h
#define GET_WM_CHARTOITEM_CHAR(wp, lp)              (CHAR)(wp)
#define GET_WM_MENUCHAR_CHAR(wp, lp)                (CHAR)(wp)

// public\sdk\inc\pwin32.h
#define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)(lp)
#define GET_WM_MENUCHAR_HMENU(wp, lp)               (HMENU)(lp)

// public\sdk\inc\regstr.h
#define REGSTR_VAL_BEHAVIOR_ON_FAILED_VERIFY  TEXT("BehaviorOnFailedVerify")
#define REGSTR_VAL_FREESPACERATIO               TEXT("FreeSpaceRatio")
#define REGDF_NOTDETALL         (REGDF_NOTDETIO | REGDF_NOTDETMEM | REGDF_NOTDETIRQ | REGDF_NOTDETDMA)
#define REGDF_CONFLICTALL       (REGDF_CONFLICTIO | REGDF_CONFLICTMEM | REGDF_CONFLICTIRQ | REGDF_CONFLICTDMA)
#define REGSTR_MACHTYPE_ATT_PC          TEXT("AT&T PC")

// public\sdk\inc\richedit.h
#define EM_GETLIMITTEXT			(WM_USER + 37)
#define EM_POSFROMCHAR			(WM_USER + 38)
#define EM_CHARFROMPOS			(WM_USER + 39)
#define EM_EXLIMITTEXT			(WM_USER + 53)
#define EM_EXLINEFROMCHAR		(WM_USER + 54)
#define EM_FINDTEXT				(WM_USER + 56)
#define EM_GETCHARFORMAT		(WM_USER + 58)
#define EM_GETSELTEXT			(WM_USER + 62)
#define EM_REQUESTRESIZE		(WM_USER + 65)
#define EM_SETCHARFORMAT		(WM_USER + 68)
#define EM_STREAMOUT			(WM_USER + 74)
#define EM_FINDTEXTEX			(WM_USER + 79)
#define EM_SETTEXTMODE			(WM_USER + 89)
#define EM_GETTEXTMODE			(WM_USER + 90)
#define EM_GETTEXTEX			(WM_USER + 94)
#define EM_GETTEXTLENGTHEX		(WM_USER + 95)
#define EM_SETTEXTEX			(WM_USER + 97)
#define EM_FINDTEXTW			(WM_USER + 123)
#define EM_FINDTEXTEXW			(WM_USER + 124)
#define GTL_DEFAULT		0	// Do default (return # of chars)

// public\sdk\inc\rpcndr.h
#define NDRSContextValue(hContext) (&(hContext)->userContext)

// public\sdk\inc\rtcerr.h
#define RTC_E_SIP_STREAM_PRESENT         ((HRESULT)0x80EE0001L)
#define RTC_E_SIP_STREAM_NOT_PRESENT     ((HRESULT)0x80EE0002L)
#define RTC_E_SIP_NO_STREAM              ((HRESULT)0x80EE0003L)
#define RTC_E_START_STREAM               ((HRESULT)0x80EE0023L)
#define RTC_E_PROFILE_MULTIPLE_REGISTRARS ((HRESULT)0x80EE003AL)

// public\sdk\inc\schannel.h
#define SSL_FREE_CERTIFICATE_NAME   TEXT("SslFreeCertificate")

// public\sdk\inc\snmp.h
#define ASN_OCTETSTRING             (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x04)
#define SNMP_EXCEPTION_NOSUCHOBJECT     (ASN_CONTEXT | ASN_PRIMITIVE | 0x00)
#define SNMP_EXCEPTION_ENDOFMIBVIEW     (ASN_CONTEXT | ASN_PRIMITIVE | 0x02)

// public\sdk\inc\strmif.h
#define	ADVISE_ALL2	( ADVISE_ALL | ADVISE_DISPLAY_CHANGE )

// public\sdk\inc\subsmgr.h
#define INET_E_SCHEDULED_UPDATES_RESTRICTED  _HRESULT_TYPEDEF_(0x800C0F85L)

// public\sdk\inc\tapi3err.h
#define TAPI_E_NOREQUESTRECIPIENT        ((HRESULT)0x80040032L)
#define TAPI_E_REGISTRY_SETTING_CORRUPT  ((HRESULT)0x8004004DL)

// public\sdk\inc\textstor.h
#define TS_E_NOOBJECT        MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0202)
#define TS_E_NOSERVICE       MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0203)
#define TS_E_NOINTERFACE     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0204)
#define TS_E_NOSELECTION     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0205)
#define TS_E_NOLAYOUT        MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0206)
#define TS_E_SYNCHRONOUS     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0208)
#define TS_E_READONLY        MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0209)
#define TS_E_FORMAT          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x020a)
#define TS_S_ASYNC           MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, 0x0300)
#define	TS_AS_ALL_SINKS	( TS_AS_TEXT_CHANGE | TS_AS_SEL_CHANGE | TS_AS_LAYOUT_CHANGE | TS_AS_ATTR_CHANGE | TS_AS_STATUS_CHANGE )

// public\sdk\inc\usbcamdi.h
#define USBCAMD_VIDEO_STILL_STREAM  (USBCAMD_VIDEO_STREAM | USBCAMD_STILL_STREAM)

// public\sdk\inc\uxtheme.h
#define ETDT_ENABLETAB      (ETDT_ENABLE  | ETDT_USETABTEXTURE)

// public\sdk\inc\vdmdbg.h
#define VDMCONTEXT_INTEGER         (VDMCONTEXT_i386 | 0x00000002L) // AX, BX, CX, DX, SI, DI
#define VDMCONTEXT_SEGMENTS        (VDMCONTEXT_i386 | 0x00000004L) // DS, ES, FS, GS
#define VDMCONTEXT_DEBUG_REGISTERS (VDMCONTEXT_i386 | 0x00000010L) // DB 0-3,6,7
#define VDMCONTEXT_EXTENDED_REGISTERS  (VDMCONTEXT_i386 | 0x00000020L) // cpu specific extensions
#define VDMCONTEXT_FULL (VDMCONTEXT_CONTROL | VDMCONTEXT_INTEGER |\
                      VDMCONTEXT_SEGMENTS)

// public\sdk\inc\vfw.h
#define MCIWNDM_SENDSTRINGA	(WM_USER + 101)
#define MCIWNDM_RETURNSTRINGA	(WM_USER + 138)
#define MCIWNDM_SENDSTRINGW	(WM_USER + 201)
#define MCIWNDM_RETURNSTRINGW	(WM_USER + 238)
#define capDriverGetName(hwnd, szName, wSize)      ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_NAME, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capDriverGetVersion(hwnd, szVer, wSize)    ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_VERSION, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szVer)))
#define capFileGetCaptureFile(hwnd, szName, wSize) ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_GET_CAPTURE_FILE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capFileSaveAs(hwnd, szName)                ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEAS, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capGetMCIDeviceName(hwnd, szName, wSize)   ((BOOL)AVICapSM(hwnd, WM_CAP_GET_MCI_DEVICE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))

// public\sdk\inc\vfwmsgs.h
#define VFW_E_MPEG_NOT_CONSTRAINED       ((HRESULT)0x8004025EL)
#define VFW_E_UNSUPPORTED_STREAM         ((HRESULT)0x80040265L)
#define VFW_S_STREAM_OFF                 ((HRESULT)0x00040267L)
#define VFW_E_DVD_STREAM_DISABLED        ((HRESULT)0x8004028FL)

// public\sdk\inc\wdm.h
#define RTL_SOFT_ASSERT(_exp) \
    ((!(_exp)) ? \
        (DbgPrint("%s(%d): Soft assertion failed\n   Expression: %s\n", __FILE__, __LINE__, #_exp),FALSE) : \
        TRUE)
#define RTL_SOFT_ASSERTMSG(_msg, _exp) \
    ((!(_exp)) ? \
        (DbgPrint("%s(%d): Soft assertion failed\n   Expression: %s\n   Message: %s\n", __FILE__, __LINE__, #_exp, (_msg)),FALSE) : \
        TRUE)

// public\sdk\inc\wincrypt.h
#define CALG_RC4                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_STREAM|ALG_SID_RC4)
#define CALG_SEAL               (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_STREAM|ALG_SID_SEAL)

// public\sdk\inc\windns.h
#define DNS_QUESTION_NAME_FROM_HEADER( _pHeader_ ) \
            ( (PCHAR)( (PDNS_HEADER)(_pHeader_) + 1 ) )
#define DNS_ANSWER_FROM_QUESTION( _pQuestion_ ) \
            ( (PCHAR)( (PDNS_QUESTION)(_pQuestion_) + 1 ) )

// public\sdk\inc\windowsx.h
#define HANDLE_WM_WININICHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCTSTR)(lParam)), 0L)
#define HANDLE_WM_DEVMODECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCTSTR)(lParam)), 0L)
#define FORWARD_WM_DEVMODECHANGE(hwnd, lpszDeviceName, fn) \
    (void)(fn)((hwnd), WM_DEVMODECHANGE, 0L, (LPARAM)(LPCTSTR)(lpszDeviceName))
#define HANDLE_WM_DESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROY, 0L, 0L)
#define HANDLE_WM_NCDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_NCDESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_NCDESTROY, 0L, 0L)
#define HANDLE_WM_SETTEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCTSTR)(lParam)), 0L)
#define FORWARD_WM_SETTEXT(hwnd, lpszText, fn) \
    (void)(fn)((hwnd), WM_SETTEXT, 0L, (LPARAM)(LPCTSTR)(lpszText))
#define FORWARD_WM_CHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_CHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat),0))
#define FORWARD_WM_DEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_DEADCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat),0))
#define FORWARD_WM_SYSCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat), 0))
#define FORWARD_WM_SYSDEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSDEADCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat), 0))
#define HANDLE_WM_DESTROYCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROYCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROYCLIPBOARD, 0L, 0L)
#define HANDLE_WM_MDIDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIDESTROY(hwnd, hwndDestroy, fn) \
    (void)(fn)((hwnd), WM_MDIDESTROY, (WPARAM)(hwndDestroy), 0L)
#define FORWARD_WM_CONTEXTMENU(hwnd, hwndContext, xPos, yPos, fn) \
    (void)(fn)((hwnd), WM_CONTEXTMENU, (WPARAM)(HWND)(hwndContext), MAKELPARAM((UINT)(xPos), (UINT)(yPos)))
#define ComboBox_GetTextLength(hwndCtl)         GetWindowTextLength(hwndCtl)
#define ComboBox_SetText(hwndCtl, lpsz)         SetWindowText((hwndCtl), (lpsz))
#define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)(lp)
#define GET_WM_MENUCHAR_HMENU(wp, lp)               (HMENU)(lp)

// public\sdk\inc\winerror.h
#define CO_E_ATTEMPT_TO_CREATE_OUTSIDE_CLIENT_CONTEXT _HRESULT_TYPEDEF_(0x80004024L)
#define CONVERT10_E_OLESTREAM_GET        _HRESULT_TYPEDEF_(0x800401C0L)
#define CONVERT10_E_OLESTREAM_PUT        _HRESULT_TYPEDEF_(0x800401C1L)
#define CONVERT10_E_OLESTREAM_FMT        _HRESULT_TYPEDEF_(0x800401C2L)
#define CONVERT10_E_STG_NO_STD_STREAM    _HRESULT_TYPEDEF_(0x800401C5L)
#define CO_E_CLASSSTRING                 _HRESULT_TYPEDEF_(0x800401F3L)
#define CO_E_IIDSTRING                   _HRESULT_TYPEDEF_(0x800401F4L)
#define XACT_S_LASTRESOURCEMANAGER       _HRESULT_TYPEDEF_(0x0004D010L)
#define CONTEXT_E_ABORTED                _HRESULT_TYPEDEF_(0x8004E002L)
#define CONTEXT_E_ABORTING               _HRESULT_TYPEDEF_(0x8004E003L)
#define CONTEXT_E_NOCONTEXT              _HRESULT_TYPEDEF_(0x8004E004L)
#define CONTEXT_E_OLDREF                 _HRESULT_TYPEDEF_(0x8004E007L)
#define CONTEXT_E_ROLENOTFOUND           _HRESULT_TYPEDEF_(0x8004E00CL)
#define CONTEXT_E_TMNOTAVAILABLE         _HRESULT_TYPEDEF_(0x8004E00FL)
#define CONTEXT_E_NOJIT                  _HRESULT_TYPEDEF_(0x8004E026L)
#define CONTEXT_E_NOTRANSACTION          _HRESULT_TYPEDEF_(0x8004E027L)
#define TYPE_E_REGISTRYACCESS            _HRESULT_TYPEDEF_(0x8002801CL)
#define RPC_E_NO_CONTEXT                 _HRESULT_TYPEDEF_(0x8001011EL)
#define CO_E_INCOMPATIBLESTREAMVERSION   _HRESULT_TYPEDEF_(0x8001013BL)
#define NTE_SILENT_CONTEXT               _HRESULT_TYPEDEF_(0x80090022L)
#define CRYPT_E_STREAM_MSG_NOT_READY     _HRESULT_TYPEDEF_(0x80091010L)
#define CRYPT_E_STREAM_INSUFFICIENT_DATA _HRESULT_TYPEDEF_(0x80091011L)
#define CRYPT_E_NOT_CHAR_STRING          _HRESULT_TYPEDEF_(0x80092024L)
#define OSS_CONSTRAINT_VIOLATED          _HRESULT_TYPEDEF_(0x80093011L)
#define OSS_CONSTRAINT_DLL_NOT_LINKED    _HRESULT_TYPEDEF_(0x80093023L)
#define CRYPT_E_ASN1_CONSTRAINT          _HRESULT_TYPEDEF_(0x80093105L)
#define CERTSRV_E_RESTRICTEDOFFICER      _HRESULT_TYPEDEF_(0x80094009L)
#define TRUST_E_BASIC_CONSTRAINTS        _HRESULT_TYPEDEF_(0x80096019L)
#define CERT_E_UNTRUSTEDTESTROOT         _HRESULT_TYPEDEF_(0x800B010DL)
#define TRUST_E_EXPLICIT_DISTRUST        _HRESULT_TYPEDEF_(0x800B0111L)
#define COMQC_E_NO_IPERSISTSTREAM        _HRESULT_TYPEDEF_(0x80110603L)

// public\sdk\inc\winnt.h
#define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1]
#define CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#define CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#define CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#define CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)
#define CONTEXT_CONTROL         (CONTEXT_ALPHA | 0x00000001L)
#define CONTEXT_INTEGER         (CONTEXT_ALPHA | 0x00000004L)
#define CONTEXT_INTEGER         (CONTEXT_i386 | 0x00000002L) // AX, BX, CX, DX, SI, DI
#define CONTEXT_SEGMENTS        (CONTEXT_i386 | 0x00000004L) // DS, ES, FS, GS
#define CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L) // DB 0-3,6,7
#define CONTEXT_EXTENDED_REGISTERS  (CONTEXT_i386 | 0x00000020L) // cpu specific extensions
#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER |\
                      CONTEXT_SEGMENTS)
#define CONTEXT_CONTROL          (CONTEXT_R4000 | 0x00000001)
#define CONTEXT_INTEGER          (CONTEXT_R4000 | 0x00000004)
#define CONTEXT_EXTENDED_INTEGER (CONTEXT_INTEGER | 0x00000010)
#define CONTEXT_CONTROL                 (CONTEXT_IA64 | 0x00000001L)
#define CONTEXT_INTEGER                 (CONTEXT_IA64 | 0x00000008L)
#define CONTEXT_DEBUG                   (CONTEXT_IA64 | 0x00000010L)
#define CONTEXT_IA32_CONTROL            (CONTEXT_IA64 | 0x00000020L)  // Includes StIPSR

// public\sdk\inc\winres.h
#define LB_ADDSTRING    (WM_USER+1)

// public\sdk\inc\winsnmp.h
#define SNMP_SYNTAX_NOSUCHOBJECT   (ASN_CONTEXT | ASN_PRIMITIVE | 0x00)
#define SNMP_SYNTAX_ENDOFMIBVIEW   (ASN_CONTEXT | ASN_PRIMITIVE | 0x02)

// public\sdk\inc\winspool.h
#define PRINTER_READ          (STANDARD_RIGHTS_READ         |\
                               PRINTER_ACCESS_USE)
#define PRINTER_WRITE         (STANDARD_RIGHTS_WRITE        |\
                               PRINTER_ACCESS_USE)
#define PRINTER_EXECUTE       (STANDARD_RIGHTS_EXECUTE      |\
                               PRINTER_ACCESS_USE)

// public\sdk\inc\wtl10\atlres.h
#define LB_ADDSTRING    (WM_USER+1)

// published\ddk\inc\wdm\acpiioct.h
#define ACPI_METHOD_NEXT_ARGUMENT( Argument )                              \
    (PACPI_METHOD_ARGUMENT) ( (PUCHAR) Argument +                          \
    ACPI_METHOD_ARGUMENT_LENGTH_FROM_ARGUMENT( Argument ) )

// published\genxddk\usbcamdi.h
#define USBCAMD_VIDEO_STILL_STREAM  (USBCAMD_VIDEO_STREAM | USBCAMD_STILL_STREAM)

// published\sdk\inc\dciddi.h
#define DCI_CAN_STRETCHXY                       (DCI_CAN_STRETCHX | DCI_CAN_STRETCHY)
#define DCI_CAN_STRETCHXYN                      (DCI_CAN_STRETCHXN | DCI_CAN_STRETCHYN)

// published\sdk\inc\except.hxx
#define CATCH(class, e)                                                  \
        __except( Unwind( GetExceptionInformation(), &_trycontext ) )      \
        {                                                                \
            CExceptionContext& _exceptioncontext = _ExceptionContext();  \
            if (_exceptioncontext._exception.IsKindOf(#class))           \
            {                                                            \
                class & e = (class &)_exceptioncontext._exception;
#define AND_CATCH(class, e)                                                 \
            }                                                               \
            else if (_exceptioncontext._exception.IsKindOf(#class))         \
            {                                                               \
                class & e = ( class &)_exceptioncontext._exception;
#define CATCH(class, e)                                                 \
                                                                        \
        else                                                            \
        {                                                               \
            CExceptionContext& _exceptioncontext = _ExceptionContext(); \
            if (_exceptioncontext._exception.IsKindOf(#class))          \
            {                                                           \
                class & e = (class &)_exceptioncontext._exception;
#define AND_CATCH(class, e)                                                 \
                                                                            \
            }                                                               \
            else if (_exceptioncontext._exception.IsKindOf(#class))         \
            {                                                               \
                class & e = (class &)_exceptioncontext._exception;

// published\sdk\inc\getuser.h
#define USRBROWS_INCL_ALL           (USRBROWS_INCL_REMOTE_USERS |\
                                     USRBROWS_INCL_INTERACTIVE  |\
                                     USRBROWS_INCL_EVERYONE     |\
                                     USRBROWS_INCL_CREATOR      |\
                                     USRBROWS_INCL_SYSTEM	|\
                                     USRBROWS_INCL_RESTRICTED)

// published\sdk\inc\ntddpcm.h
#define PCMRES_GET_AUDIO_ENABLE(desc) ((UCHAR) ((desc)->u.DevicePrivate.Data[0] &  PCMRESF_AUDIO_ENABLE) != 0)

// published\sdk\inc\ntfsprop.h
#define COUNTED_STRING_LENGTH(c)    \
    ((c)->Length)
#define COUNTED_STRING_TEXT(c)      \
    (&(c)->Text[0])
#define PROPERTY_SPECIFIER_NAME(PS,I)    \
    (&PROPERTY_SPECIFIER_COUNTED_STRING( PS, I )->Text[0])
#define PROPERTY_SPECIFIER_NAME_LENGTH(PS,I) \
    (PROPERTY_SPECIFIER_COUNTED_STRING( PS, I )->Length)

// published\sdk\inc\penwin.h
#define CWR_SINGLELINEEDIT      (CWR_REPLACECR|CWR_STRIPLF|CWR_REPLACETAB)  // all of the above
#define FIsAnsiGesture(syv) \
   (                            \
   (syv) == SYV_BACKSPACE       \
   || (syv) == SYV_TAB          \
   || (syv) == SYV_RETURN       \
   || (syv) == SYV_SPACE        \
   )

// published\sdk\inc\pwin16.h
#define GET_WM_CHARTOITEM_CHAR(wp, lp)              (CHAR)(wp)
#define GET_WM_MENUCHAR_CHAR(wp, lp)                (CHAR)(wp)

// published\sdk\inc\pwin32.h
#define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)(lp)
#define GET_WM_MENUCHAR_HMENU(wp, lp)               (HMENU)(lp)

// published\sdk\inc\snmp.h
#define ASN_OCTETSTRING             (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x04)
#define SNMP_EXCEPTION_NOSUCHOBJECT     (ASN_CONTEXT | ASN_PRIMITIVE | 0x00)
#define SNMP_EXCEPTION_ENDOFMIBVIEW     (ASN_CONTEXT | ASN_PRIMITIVE | 0x02)

// published\sdk\inc\vdmdbg.h
#define VDMCONTEXT_INTEGER         (VDMCONTEXT_i386 | 0x00000002L) // AX, BX, CX, DX, SI, DI
#define VDMCONTEXT_SEGMENTS        (VDMCONTEXT_i386 | 0x00000004L) // DS, ES, FS, GS
#define VDMCONTEXT_DEBUG_REGISTERS (VDMCONTEXT_i386 | 0x00000010L) // DB 0-3,6,7
#define VDMCONTEXT_EXTENDED_REGISTERS  (VDMCONTEXT_i386 | 0x00000020L) // cpu specific extensions
#define VDMCONTEXT_FULL (VDMCONTEXT_CONTROL | VDMCONTEXT_INTEGER |\
                      VDMCONTEXT_SEGMENTS)

// published\sdk\inc\vfw.h
#define MCIWNDM_SENDSTRINGA	(WM_USER + 101)
#define MCIWNDM_RETURNSTRINGA	(WM_USER + 138)
#define MCIWNDM_SENDSTRINGW	(WM_USER + 201)
#define MCIWNDM_RETURNSTRINGW	(WM_USER + 238)
#define capDriverGetName(hwnd, szName, wSize)      ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_NAME, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capDriverGetVersion(hwnd, szVer, wSize)    ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_VERSION, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szVer)))
#define capFileGetCaptureFile(hwnd, szName, wSize) ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_GET_CAPTURE_FILE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capFileSaveAs(hwnd, szName)                ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEAS, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capGetMCIDeviceName(hwnd, szName, wSize)   ((BOOL)AVICapSM(hwnd, WM_CAP_GET_MCI_DEVICE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))

// published\sdk\inc\windowsx.h
#define HANDLE_WM_WININICHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCTSTR)(lParam)), 0L)
#define HANDLE_WM_DEVMODECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCTSTR)(lParam)), 0L)
#define FORWARD_WM_DEVMODECHANGE(hwnd, lpszDeviceName, fn) \
    (void)(fn)((hwnd), WM_DEVMODECHANGE, 0L, (LPARAM)(LPCTSTR)(lpszDeviceName))
#define HANDLE_WM_DESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROY, 0L, 0L)
#define HANDLE_WM_NCDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_NCDESTROY(hwnd, fn) \
    (void)(fn)((hwnd), WM_NCDESTROY, 0L, 0L)
#define HANDLE_WM_SETTEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCTSTR)(lParam)), 0L)
#define FORWARD_WM_SETTEXT(hwnd, lpszText, fn) \
    (void)(fn)((hwnd), WM_SETTEXT, 0L, (LPARAM)(LPCTSTR)(lpszText))
#define FORWARD_WM_CHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_CHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat),0))
#define FORWARD_WM_DEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_DEADCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat),0))
#define FORWARD_WM_SYSCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat), 0))
#define FORWARD_WM_SYSDEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSDEADCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat), 0))
#define HANDLE_WM_DESTROYCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_DESTROYCLIPBOARD(hwnd, fn) \
    (void)(fn)((hwnd), WM_DESTROYCLIPBOARD, 0L, 0L)
#define HANDLE_WM_MDIDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIDESTROY(hwnd, hwndDestroy, fn) \
    (void)(fn)((hwnd), WM_MDIDESTROY, (WPARAM)(hwndDestroy), 0L)
#define FORWARD_WM_CONTEXTMENU(hwnd, hwndContext, xPos, yPos, fn) \
    (void)(fn)((hwnd), WM_CONTEXTMENU, (WPARAM)(HWND)(hwndContext), MAKELPARAM((UINT)(xPos), (UINT)(yPos)))
#define ComboBox_GetTextLength(hwndCtl)         GetWindowTextLength(hwndCtl)
#define ComboBox_SetText(hwndCtl, lpsz)         SetWindowText((hwndCtl), (lpsz))
#define GET_WM_CHARTOITEM_HWND(wp, lp)          (HWND)(lp)
#define GET_WM_MENUCHAR_HMENU(wp, lp)               (HMENU)(lp)

// published\sdk\inc\winres.h
#define LB_ADDSTRING    (WM_USER+1)

// published\sdk\inc\winsnmp.h
#define SNMP_SYNTAX_NOSUCHOBJECT   (ASN_CONTEXT | ASN_PRIMITIVE | 0x00)
#define SNMP_SYNTAX_ENDOFMIBVIEW   (ASN_CONTEXT | ASN_PRIMITIVE | 0x02)

// sdktools\cntrtext\common\common.h
#define StringToInt(in,out) \
    (((_stscanf ((in), (LPCTSTR)TEXT(" %d"), (out))) == 1) ? TRUE : FALSE)

// sdktools\cntrtext\initodat\fileutl.c
#define upcase(C) (WCHAR )(((C) >= 'a' && (C) <= 'z' ? (C) - ('a' - 'A') : (C)))

// sdktools\cntrtext\showperf\showperf.h
#define MBOK_EXCLAIM            (MB_OK | MB_ICONEXCLAMATION | MB_TASKMODAL)
#define MBOK_INFO               (MB_OK | MB_ICONINFORMATION | MB_TASKMODAL)
#define MBOKCANCEL_EXCLAIM      (MB_OKCANCEL | MB_ICONEXCLAMATION | MB_TASKMODAL)
#define MBOKCANCEL_INFO         (MB_OKCANCEL | MB_ICONINFORMATION | MB_TASKMODAL)
#define MBOKCANCEL_QUESTION     (MB_OKCANCEL | MB_ICONQUESTION | MB_TASKMODAL)
#define MBYESNO_QUESTION        (MB_YESNO | MB_ICONQUESTION | MB_TASKMODAL)
#define MBYESNOCANCEL_QUESTION  (MB_YESNOCANCEL | MB_ICONQUESTION | MB_TASKMODAL)
#define MBYESNOCANCEL_EXCLAIM   (MB_YESNOCANCEL | MB_ICONEXCLAMATION | MB_TASKMODAL)
#define POST_WM_COMMAND(w,c,n,cw)  PostMessage (w, WM_COMMAND, MAKEWPARAM(c,n), (LPARAM)cw)

// sdktools\compdir\compdir.c
#define FIND_FIRST( String, Buff) FindFirstFile( String, &Buff)

// sdktools\debuggers\exts\extdll\precomp.h
#define DECLARE_API(extension)     \
CPPMOD HRESULT CALLBACK extension(PDEBUG_CLIENT Client, PCSTR args)

// sdktools\debuggers\exts\extsdll\precomp.h
#define DECLARE_API(extension)     \
CPPMOD HRESULT CALLBACK extension(PDEBUG_CLIENT Client, PCSTR args)

// sdktools\debuggers\exts\kextdll\precomp.h
#define DECLARE_API(extension)     \
CPPMOD HRESULT CALLBACK extension(PDEBUG_CLIENT Client, PCSTR args)

// sdktools\debuggers\exts\uextdll\precomp.h
#define DECLARE_API(extension)     \
CPPMOD HRESULT CALLBACK extension(PDEBUG_CLIENT Client, PCSTR args)

// sdktools\diff\diff.c
#define  GetChar(x)  ((char)((inputfileleft[x]--) ?     \
                           (*(inputfilep[x])++)  :  \
                           EOF))

// sdktools\gutils\gutils.h
#define SM_SETTEXT      (WM_USER+2)     /* wparam: item id, lparam new label*/

// sdktools\hivepp\p0defs.h
#define	HLN_TO_NAME(S)		((PUCHAR)pstrndup(HLN_IDENTP_NAME(S),HLN_IDENT_LENGTH(S)))

// sdktools\hivepp\p0macros.c
#define	ACTUAL_TEXT(P)	((P) + sizeof(short))
#define	FORMAL_TEXT(P)	((P) + sizeof(UCHAR))

// sdktools\hivepp\symbols.h
#define	SYM_ISABSTRSYM(p)	(SYM_ANYVTAG(p) & SYMV_ABSTRSYM)

// sdktools\m4\m4.h
#define cbCtch(ctch)    ((ctch) * sizeof(TCHAR))
#define ctchCb(cb)      ((cb) / sizeof(TCHAR))

// sdktools\masm\asm86.h
# define TEXTREAD       (O_RDONLY | O_BINARY)

// sdktools\mep\help\inc\help.h
#define     APPCHAR(x)	((x)->fileinfo.hdr.appChar)

// sdktools\mep\inc\mep.h
#define GETARG      (NOARG|TEXTARG|NULLARG|NULLEOL|NULLEOW|LINEARG|STREAMARG|BOXARG)

// sdktools\mtscript\scrhost\automation.cxx
#define USERPROFILESTRING_SZ (256 * sizeof(TCHAR))

// sdktools\mttf\setup\cmnds.h
#define FRenameFile(szSrc, szDst) \
	((rename((char *)(szSrc), (char *)(szDst)) == 0) ? fTrue : fFalse)
#define FWriteProtectFile(szPath) \
	((chmod((char *)(szPath), S_IREAD) == 0) ? fTrue : fFalse)
#define FMkDir(szDir) \
	(((mkdir((char *)(szDir)) == 0) || (errno == EACCES)) ? fTrue : fFalse)
#define FRmDir(szDir) \
	(((rmdir((char *)(szDir)) == 0) || (errno == ENOENT)) ? fTrue : fFalse)

// sdktools\mttf\setup\comstf.h
#define  ofmExistRead      ((OFM)OF_EXIST | OF_READ)
#define  ofmExistReadWrite ((OFM)OF_EXIST | OF_READWRITE)

// sdktools\nmake\inline.cpp
#define NAME_CHAR(c) (c) != '>' && (c) != '<' && \
             (c) != '^' && (c) != ',' && (c) != '\t' && \
             (c) != '\n'

// sdktools\nmake\nmake.h
#define MACRO_CHAR(A)       ((A) == '_' || _istalnum(A) || ((unsigned)(A)) >= 128)

// sdktools\pcmcmd\registry.c
#define VALUE2_BUFFER_SIZE sizeof(CM_PCCARD_DEVICE_DATA) + sizeof(CM_FULL_RESOURCE_DESCRIPTOR)

// sdktools\pdh\inc\perfdata.h
#define FirstInstance(pObjectDef) \
    (PERF_INSTANCE_DEFINITION *)((PCHAR) pObjectDef + pObjectDef->DefinitionLength)

// sdktools\pdh\pdhui\expldlg.h
#define EDM_UPDATE_EXPLAIN_TEXT (WM_USER+0x101)
#define EDM_UPDATE_TITLE_TEXT   (WM_USER+0x102)

// sdktools\pdh\wbemperf\perfhelp.h
#define FirstInstance(pObjectDef) \
    (PERF_INSTANCE_DEFINITION *)((PCHAR) pObjectDef + pObjectDef->DefinitionLength)

// sdktools\pdh\wbemperf\utils.h
#define Macro_CloneLPWSTR(x) \
    (x ? wcscpy(new wchar_t[wcslen(x) + 1], x) : 0)

// sdktools\perfmon\utils.h
#define strempty(lpszString)                          \
   (!(lpszString) || !(lpszString[0]))
#define pstrsame(lpsz1, lpsz2)                        \
   ((!lpsz1 && !lpsz2) || (lpsz1 && lpsz2 && strsame (lpsz1, lpsz2)))
#define pstrsamei(lpsz1, lpsz2)                        \
   ((!lpsz1 && !lpsz2) || (lpsz1 && lpsz2 && strsamei (lpsz1, lpsz2)))

// sdktools\rcdll\p0macros.c
#define ACTUAL_TEXT(P)  ((ptext_t)(((char *)(P)) + sizeof(short)))

// sdktools\rcdll\rcl.c
#define iswhite( c ) ((c != SYMUSESTART) && (c != SYMDEFSTART) &&\
        ((WCHAR)c <= L' ') ? TRUE : FALSE)

// sdktools\rcdll\symbols.h
#define SYM_ISABSTRSYM(p)       (SYM_ANYVTAG(p) & SYMV_ABSTRSYM)

// sdktools\restools\rlt32\rw\win32\restok.hxx
#define STRINGSIZE( x ) ((x) * (sizeof( TCHAR)))
#define STRINGSIZE( x ) ((x) * (sizeof(CHAR)))
#define MEMSIZE( x ) ((x) * (sizeof( TCHAR)))

// sdktools\restools\rltools\common\restok.h
#define STRINGSIZE( x ) ((x) * sizeof( TCHAR))
#define STRINGSIZE( x ) ((x) * sizeof(CHAR))
#define MEMSIZE( x ) ((x) * sizeof( TCHAR))
#define WCHARSIN( x) ((x) / sizeof( WCHAR))

// sdktools\restools\rltools\rledit\rledit.c
#define NOTIMPLEMENTED {TCHAR sz[80];\
                        LoadString( hInst, \
                                    IDS_NOT_IMPLEMENTED, \
                                    sz, TCHARSIN( sizeof(sz)));\
                        MessageBox(hMainWnd, sz, tszAppName, \
                                   MB_ICONEXCLAMATION | MB_OK);}

// sdktools\restools\rltools\rlquiked\rlquiked.c
#define NOTIMPLEMENTED {TCHAR sz[80];\
            LoadString(hInst,IDS_NOT_IMPLEMENTED,sz,TCHARSIN(sizeof(sz)));\
            MessageBox(hMainWnd,sz,tszAppName,MB_ICONEXCLAMATION|MB_OK);}

// sdktools\restools\unicode\nlsxlat.c
#define IsDBCSFirst(w) (((unsigned char)w >= 0x81 && (unsigned char)w <= 0x9f) || (((unsigned char)w >= 0xe0 && (unsigned char)w <= 0xfc)))

// sdktools\sdv\sdview.h
#define LM_GETCONTEXTMENU   (WM_USER + 102) // wParam = iItem

// sdktools\setedit\utils.h
#define strempty(lpszString)                          \
   (!(lpszString) || !(lpszString[0]))
#define pstrsame(lpsz1, lpsz2)                        \
   ((!lpsz1 && !lpsz2) || (lpsz1 && lpsz2 && strsame (lpsz1, lpsz2)))
#define pstrsamei(lpsz1, lpsz2)                        \
   ((!lpsz1 && !lpsz2) || (lpsz1 && lpsz2 && strsamei (lpsz1, lpsz2)))

// sdktools\strings\strings.c
#define isswitch(s)     (((s)[0] == '-') || ((s)[0] == '/'))

// sdktools\tweakui\comdlg32.cpp
#define COMDLG32_KL(nm) \
    KL const c_kl##nm = { &g_hkCUSMWCV, TEXT("Policies\\comdlg32"), TEXT(#nm) }

// sdktools\unicows\godot\unicows.tpl
#define SHCNF_HAS_WSTR_PARAMS(f)   ((f & SHCNF_TYPE) == SHCNF_PATHW     ||    \
                                    (f & SHCNF_TYPE) == SHCNF_PRINTERW  ||    \
                                    (f & SHCNF_TYPE) == SHCNF_PRINTJOBW    )

// sdktools\vi\normal.c
#       define  IDCHAR(c)       (isalpha(c) || isdigit(c) || (c) == '_')

// sdktools\vi\search.c
#define BEGCHAR(c)      (islower(c) || isupper(c) || isdigit(c) || ((c) == '_'))

// sdktools\vmmreg32\pch.h
#define StrCpy(lpd, lps)            (_lstrcpyn((PCHAR)(lpd), (PCHAR)(lps), (ULONG)(-1)))
#define StrCpyN(lpd, lps, cb)       (_lstrcpyn((PCHAR)(lpd), (PCHAR)(lps), (ULONG)(cb)))
#define StrLen(lpstr)               (_lstrlen((PCHAR)(lpstr)))

// sdktools\winobj\fontsel.h
#define MYCF_BOTH		(MYCF_MYCF_SCREENFONTS | MYCF_PRINTERFONTS)

// sdktools\z\src\z.h
#define GETARG      (NOARG|TEXTARG|NULLARG|NULLEOL|NULLEOW|LINEARG|STREAMARG|BOXARG)

// shell\browseui\iaccess.cpp
#define CH_PREFIX TEXT('&')

// shell\browseui\legacy\iaccess.cpp
#define CH_PREFIX TEXT('&')

// shell\browseui\priv.h
#define InitFakeBSTR(pSA_BSTR, guid) SHStringFromGUIDW((guid), (pSA_BSTR)->wsz, ARRAYSIZE((pSA_BSTR)->wsz)), (pSA_BSTR)->cb = (38*sizeof(WCHAR))

// shell\browseui\proxy.cpp
#define ISSEP(c)   ((c) == TEXT('=')  || (c) == TEXT(','))
#define ISWHITE(c) ((c) == TEXT(' ')  || (c) == TEXT('\t') || (c) == TEXT('\n') || (c) == TEXT('\r'))

// shell\browseui\runonnt.c
#define UseUnicodeShell32() (g_fRunningOnNT && !(g_dwPrototype & PF_FORCEANSI))

// shell\comctl32\v5\ctlspriv.h
#define CH_PREFIX TEXT('&')

// shell\comctl32\v5\cutils.c
#define ISDIGIT(c)  ((c) >= TEXT('0') && (c) <= TEXT('9'))

// shell\comctl32\v5\rebar.c
#define RBSHOWTEXT(prbb) (!(prbb->fStyle&RBBS_HIDETITLE) && prbb->lpText && prbb->lpText[0])

// shell\comctl32\v5\toolbar.c
#define BTN_NO_SHOW_TEXT(ptb, ptbb) (!(ptb)->nTextRows || (USE_MIXED_BUTTONS(ptb) && !((ptbb)->fsStyle & BTNS_SHOWTEXT)))
#define TBHasStrings(ptb)  ((ptb)->nStrings || (ptb)->fNoStringPool)

// shell\comctl32\v6\ctlspriv.h
#define CH_PREFIX TEXT('&')

// shell\comctl32\v6\cutils.c
#define ISDIGIT(c)  ((c) >= TEXT('0') && (c) <= TEXT('9'))

// shell\comctl32\v6\toolbar.cpp
#define BTN_NO_SHOW_TEXT(ptb, ptbb) (!(ptb)->nTextRows || (USE_MIXED_BUTTONS(ptb) && !((ptbb)->fsStyle & BTNS_SHOWTEXT)))
#define TBHasStrings(ptb)  ((ptb)->nStrings || (ptb)->fNoStringPool)

// shell\comdlg32\comdlg32.h
#define CHAR_BAR                  TEXT('|')

// shell\comdlg32\dlgs.c
        #define NetworkButtonTextAccel   TEXT("Net&work...")

// shell\comdlg32\filenew.cpp
#define IsServer(psz)        (IsUNC(psz) && !StrChr((psz) + 2, CHAR_BSLASH))

// shell\comdlg32\fileopen.h
#define DBL_BSLASH(sz) \
   (*(TCHAR *)(sz)       == CHAR_BSLASH) && \
   (*(TCHAR *)((sz) + 1) == CHAR_BSLASH)

// shell\comdlg32\prnsetup.h
#define ISDIGIT(c)                ((c) >= TEXT('0') && (c) <= TEXT('9'))

// shell\cpls\system\sysdm.h
#define IsPathSep(ch)       ((ch) == TEXT('\\') || (ch) == TEXT('/'))

// shell\evtmon\inc\emrule.h
#define PociiForPrul(prul) \
            ((MSOOCII *) vlpruls->rgpociiRules[((prul)->ipociiInstrs)])

// shell\evtmon\inc\msolex.h
#define _CacheTkTextNext(plexs) \
            { \
            MSORULTK   *prultk; \
            int         cchPartialTk = (plexs)->cchLookahead; \
             \
            prultk = PrultkFromTokenIrultk((plexs), \
                                           (plexs)->rultkhToken.irultkLim); \
            prultk->pObject = plexs->pObject; \
            prultk->cpFirst = CpLexTokenFirst(plexs); \
            prultk->dcp = DcpLexCurr(plexs) + cchPartialTk; \
            prultk->ich = (plexs)->pxchTkStart - (plexs)->pxchBuffer; \
            prultk->dich = CchTokenLen(plexs) + cchPartialTk; \
            prultk->wInterval = (plexs)->wInterval; \
            prultk->tk = tkNil; \
            }
#define XchLexGetChar(plexs, cpLim) \
            ((plexs)->cchRemain-- > 0\
                ? *(plexs)->pxchNext++ \
                : XchLexGetNextBuffer(cpLim, plexs))
#define LexUngetChar(plexs, cch) \
            ((plexs)->pxchNext -= cch, (plexs)->cchRemain += cch)
#define TkLookupNameLexs(pxchStr, cchLen, plexs) \
            MsoTkLookupName((pxchStr), (cchLen), (plexs)->pkwtb)
#define PkwdLookupNameLexs(pxchStr, cchLen, plexs) \
            MsoPkwdLookupName((pxchStr), (cchLen), (plexs)->pkwtb)
#define PkwdAddTkLookupNameLexs(pxchStr, cchLen, tk, plexs, fCopyStr) \
            MsoPkwdAddTkLookupName((pxchStr), (cchLen), (tk), (plexs)->pkwtb,\
                                   (fCopyStr))
#define FRemoveTkLookupNameLexs(pxchStr, cchLen, plexs, ptk) \
            MsoFRemoveTkLookupName((pxchStr), (cchLen), (plexs)->pkwtb, (ptk))

// shell\explorer\cabinet.h
#define PERFSETMARK(text)   DoSetMark(text, sizeof(text))

// shell\ext\brfcase\filesync\syncui\comm.h
#define CbFromCch(cch)              ((cch)*sizeof(TCHAR))
#define CCH_NUL                     (sizeof(TCHAR))
#define ZeroInit(pobj, type)        lmemset((CHAR *)pobj, 0, sizeof(type))

// shell\ext\docprop\nocrt.h
#define isdigit(c)              (IsCharAlphaNumeric(c) && !IsCharAlpha(c))
#define MsoIsEqualGuid(g1, g2) \
        (!StrCmpNA((const CHAR *)g1, (const CHAR *)g2, sizeof(GUID)))

// shell\ext\docprop\offcapi.h
#define facACStaticTextRepl             (facACTextRepl|facACStatic)

// shell\ext\docprop\offglue.h
#define A2W(lpa) (\
	((LPCSTR)lpa == NULL) ? NULL : ( _convert = (lstrlenA(lpa)+1),\
		A2WHELPER((LPWSTR) alloca(_convert*2), lpa, _convert)))
#define W2A(lpw) (\
	((LPCWSTR)lpw == NULL) ? NULL : ( _convert = (lstrlenW(lpw)+1)*2,\
		W2AHELPER((LPSTR) alloca(_convert), lpw, _convert)))

// shell\ext\docprop\proptype.h
#define CBTSTR(lpstz) ( ( CchTszLen(lpstz) + 1 ) * sizeof(TCHAR) )

// shell\ext\docpropv3\citracker.h
#define DEFINE_INTERFACE( _iid, _name, _count ) { &_iid, TEXT(_name), _count },

// shell\ext\docpropv3\dll.h
#define DEFINE_CLASS( _pfn, _riid, _name, _model ) { _pfn, &_riid, TEXT(_name), TEXT(_model), NULL, &IID_NULL, NULL },
#define DEFINE_CLASS_CATIDREG( _pfn, _riid, _name, _model, _pfnCat ) { _pfn, &_riid, TEXT(_name), TEXT(_model), _pfnCat, &IID_NULL, NULL },
#define DEFINE_CLASS_WITH_APPID( _pfn, _riid, _name, _model, _appid, _surrogate ) { _pfn, &_riid, TEXT(_name), TEXT(_model), NULL, &_appid, TEXT(_surrogate) },
#define DEFINE_CATID( _rcatid, _name ) { &_rcatid, TEXT(_name) },

// shell\ext\ftp\priv.h
#define CbFromCchW(cch)             ((cch)*sizeof(WCHAR))
#define CbFromCchA(cch)             ((cch)*sizeof(CHAR))
#define c_tszNil                ((LPCTSTR)&c_wZero)     /* null string */
#define c_szNil                 ((LPCSTR)&c_wZero)      /* null string */

// shell\ext\hnw\shared\fauxmfc.h
#define afxEmptyString ((CString&)*(CString*)&_afxPchNil)

// shell\ext\hnw\wizard\netras.cpp
#define TAPI_STATION_ID_SIZE            ( 6 * sizeof( CHAR ) )

// shell\ext\hnw\wizard\shlwapiwrap.cpp
#define SHCNF_HAS_WSTR_PARAMS(f)   ((f & SHCNF_TYPE) == SHCNF_PATHW     ||    \
                                    (f & SHCNF_TYPE) == SHCNF_PRINTERW  ||    \
                                    (f & SHCNF_TYPE) == SHCNF_PRINTJOBW    )

// shell\ext\inetfind\fnd.h
#define cbCtch(ctch) ((ctch) * sizeof(TCHAR))

// shell\ext\keyremap\map.h
#define cbCtch(ctch) ((ctch) * sizeof(TCHAR))

// shell\ext\mlang\jislex.cpp
#define TXT		(TST) (grfFinal | (cCsEsc + 1))		// Process Text
#define EXT		(TST) (grfFinal | (cCsEsc + 2))		// Process (Possibly Illegal) Extended Chars
#define UNK		(TST) (grfFinal | (cCsEsc + 5))		// Unknown State (Unexpected Character)

// shell\ext\shscrap\sccreate.cpp
#define isdigit(ch) (ch>=TEXT('0') && ch<=TEXT('9'))
#define isalpha(ch) ((ch&0xdf)>=TEXT('A') && (ch&0xdf)<=TEXT('Z'))

// shell\ext\shtl\tstring.h
            #define A2W(pa) (\
                ((PCSTR)(pa) == NULL) ? NULL : (\
                    _convert = (strlen((pa))+1),\
                    StdA2WHelper((LPWSTR) alloca(_convert*2), (pa), _convert)))
            #define W2A(pw) (\
                ((PCWSTR)(pw) == NULL) ? NULL : (\
                    _convert = (wcslen((pw))+1)*2,\
                    StdW2AHelper((PSTR) alloca(_convert), (pw), _convert)))

// shell\ext\systray\dll\volume.c
#define MYWM_WAKEUP             (WM_APP+100+6)

// shell\ext\url\stock.h
#define CbFromCchW(cch)                   ((cch)*sizeof(WCHAR))
#define CbFromCchA(cch)                   ((cch)*sizeof(CHAR))

// shell\ext\webvw\winres.h
#define LB_ADDSTRING    (WM_USER+1)
#define CB_ADDSTRING    (WM_USER+3)

// shell\iecontrols\inc\prsht.h
#define PSM_SETFINISHTEXTA      (WM_USER + 115)
#define PSM_SETFINISHTEXTW      (WM_USER + 121)

// shell\inc\ccstock.h
#define CbFromCchW(cch)             ((cch)*sizeof(WCHAR))
#define CbFromCchA(cch)             ((cch)*sizeof(CHAR))
#define ISDIGIT(c)  ((c) >= TEXT('0') && (c) <= TEXT('9'))
#define	RWM_MODEBIAS            TEXT("MSIMEModeBias")

// shell\inc\desktopp.h
#define DTM_DESKTOPCONTEXTMENU      (WM_USER + 92)

// shell\inc\dllload.c
#define ENSURE_LOADED(_hmod, _dll, _ext, pszfn)         \
    (_hmod ? (_hmod) : (_DumpLoading(TEXT(#_dll) TEXT(".") TEXT(#_ext), pszfn), \
                        _hmod = LoadLibraryA(#_dll "." #_ext)))

// shell\inc\dpastuff.cpp
#define CB_OISTREAMITEM     (sizeof(OISTREAMITEM))

// shell\inc\dump.c
#define STRING_RIID(val)               { &val, TEXT(#val) }

// shell\inc\evtmon\emrule.h
#define PociiForPrul(prul) \
            ((MSOOCII *) vlpruls->rgpociiRules[((prul)->ipociiInstrs)])

// shell\inc\evtmon\msolex.h
#define _CacheTkTextNext(plexs) \
            { \
            MSORULTK   *prultk; \
            int         cchPartialTk = (plexs)->cchLookahead; \
             \
            prultk = PrultkFromTokenIrultk((plexs), \
                                           (plexs)->rultkhToken.irultkLim); \
            prultk->pObject = plexs->pObject; \
            prultk->cpFirst = CpLexTokenFirst(plexs); \
            prultk->dcp = DcpLexCurr(plexs) + cchPartialTk; \
            prultk->ich = (plexs)->pxchTkStart - (plexs)->pxchBuffer; \
            prultk->dich = CchTokenLen(plexs) + cchPartialTk; \
            prultk->wInterval = (plexs)->wInterval; \
            prultk->tk = tkNil; \
            }
#define XchLexGetChar(plexs, cpLim) \
            ((plexs)->cchRemain-- > 0\
                ? *(plexs)->pxchNext++ \
                : XchLexGetNextBuffer(cpLim, plexs))
#define LexUngetChar(plexs, cch) \
            ((plexs)->pxchNext -= cch, (plexs)->cchRemain += cch)
#define TkLookupNameLexs(pxchStr, cchLen, plexs) \
            MsoTkLookupName((pxchStr), (cchLen), (plexs)->pkwtb)
#define PkwdLookupNameLexs(pxchStr, cchLen, plexs) \
            MsoPkwdLookupName((pxchStr), (cchLen), (plexs)->pkwtb)
#define PkwdAddTkLookupNameLexs(pxchStr, cchLen, tk, plexs, fCopyStr) \
            MsoPkwdAddTkLookupName((pxchStr), (cchLen), (tk), (plexs)->pkwtb,\
                                   (fCopyStr))
#define FRemoveTkLookupNameLexs(pxchStr, cchLen, plexs, ptk) \
            MsoFRemoveTkLookupName((pxchStr), (cchLen), (plexs)->pkwtb, (ptk))

// shell\inc\fsmenu.cpp
#define CB_FMSTREAMITEM     (sizeof(FMSTREAMITEM))

// shell\inc\shconv.h
#define A2W(lpa) (\
        ((LPCSTR)lpa == NULL) ? NULL : (\
            _convert = (lstrlenA(lpa)+1),\
            ATLA2WHELPER((LPWSTR) alloca(_convert*2), (LPCSTR)lpa, _convert)))
#define W2A(lpw) (\
        ((LPCWSTR)lpw == NULL) ? NULL : (\
            _convert = (lstrlenW(lpw)+1)*2,\
            ATLW2AHELPER((LPSTR) alloca(_convert), lpw, _convert)))

// shell\inc\trayp.h
#define TM_CONTEXTMENU              (WM_USER+0x102)

// shell\inc\uemapp.h
#define UEMF_XEVENT     (UEMF_EVENTMON | UEMF_INSTRUMENT)

// shell\lib\shfusion\delaycc.c
#define STUB_COMCTL32_ORD_VOID(_fn, _args, _nargs, _ord)                      \
void __stdcall _fn _args                                                      \
{                                                                             \
    static void (__stdcall *_pfn##_fn) _args = (void (__stdcall *)_args)-1;   \
    if (_pfn##_fn == (void (__stdcall *)_args)-1)                             \
         _GetProcFromComCtl32((FARPROC*)&_pfn##_fn, (LPCSTR)_ord);            \
    STUB_INVOKE_VOID_FN(_pfn ## _fn, _nargs);                                 \
}

// shell\osshell\accesory\calendar\cal.h
#define CBQRHEAD (sizeof (QR) - sizeof (char))

// shell\osshell\accesory\hypertrm\emu\emudec.hh
    #define EMUKEY(K, V, C, A, S, E, SEQ, L) \
        { K | (V ? VIRTUAL_KEY : 0) | (C ? CTRL_KEY : 0) | \
        (A ? ALT_KEY : 0) | (S ? SHIFT_KEY : 0) | (E ? EXTENDED_KEY : 0), \
        { TEXT(SEQ) }, {L}, {#K} }
    #define EMUKEY(K, V, C, A, S, E, SEQ, L) \
        { K | (V ? VIRTUAL_KEY : 0) | (C ? CTRL_KEY : 0) | \
        (A ? ALT_KEY : 0) | (S ? SHIFT_KEY : 0) | (E ? EXTENDED_KEY : 0), \
        { TEXT(SEQ) }, {L} }

// shell\osshell\accesory\hypertrm\emu\keydef.h
#define HVK_PRINTSCRN		(0x19 | VIRTUAL_KEY | HVIRTUAL_KEY)

// shell\osshell\accesory\hypertrm\tdll\chars.h
#define QUERY_NUMLOCK() ((GetKeyState(VK_NUMLOCK) & 0x01) ? TRUE : FALSE)

// shell\osshell\accesory\hypertrm\tdll\com.h
#define mComRcvChar(h,p)	 ((((PCOM)h)->puchRBData < ((PCOM)h)->puchRBDataLimit) ? \
							 (*(p) = *((PCOM)h)->puchRBData++, TRUE) : \
							 ComRcvBufrRefill((h), (p), TRUE))

// shell\osshell\accesory\hypertrm\xfer\foo.h
#define	fooComSendChar(h,pB,c)				\
	{										\
	stFB *xyxz; xyxz = (pB);				\
	xyxz->acSend[xyxz->usSend++]=(c);		\
	if (xyxz->usSend>=FB_SIZE)				\
		{									\
		ComSndBufrSend((h),					\
					(void *)xyxz->acSend,	\
					xyxz->usSend,			\
					100);					\
		xyxz->usSend=0;						\
		}									\
	}										\

// shell\osshell\accesory\mspaint\global.cpp
#define CH_PREFIX TEXT('&')

// shell\osshell\accesory\ratpak\ratpak.h
#define DUPNUM(a,b) destroynum(a);createnum( a, b->cdigit ); \
    memcpy( a, b, (int)( sizeof( NUMBER ) + ( b->cdigit )*(sizeof(MANTTYPE)) ) );
#define DESTROYTAYLOR() destroynum( n2 ); \
    destroyrat( xx );\
    destroyrat( thisterm );\
    destroyrat( *px );\
    trimit(&pret);\
    *px=pret;

// shell\osshell\accesory\winchat\winchat.c
#define IMMMODULENAMELEN    ((sizeof PATHDLM + sizeof IMMMODULENAME) / sizeof(WCHAR))

// shell\osshell\control\mmsys\dmproppg.c
#define GetString(_psz,_id) LoadString(myInstance,(_id),(_psz),sizeof((_psz))/sizeof(TCHAR))

// shell\osshell\control\mmsys\drivers.c
#define GetString(_psz,_id) LoadString(myInstance,(_id),(_psz),sizeof((_psz))/sizeof(TCHAR))

// shell\osshell\control\mmsys\install.h
#define SLASH(c)     ((c) == TEXT('/')|| (c) == TEXT('\\'))

// shell\osshell\control\mmsys\sulib.h
#define SLASH(c)     ((c) == TEXT('/') || (c) == TEXT('\\'))

// shell\osshell\control\mmsys\systrayp.h
#define STWM_NOTIFYPOWER		(WM_USER + 201)
#define STWM_NOTIFYPCMCIA		(WM_USER + 202)
#define STWM_NOTIFYVOLUME		(WM_USER + 203)
#define STWM_ENABLESERVICE		(WM_USER + 220)
#define STWM_GETSTATE			(WM_USER + 221)

// shell\osshell\control\mmsys\utils.h
#define ZeroInit(pobj, type)        lmemset((LPTSTR)pobj, 0, sizeof(type))

// shell\osshell\control\scrnsave\bezier\ssbezier.c
#define SCANSIZE ((8 * XSIZE + 31) & ~31) / 8

// shell\osshell\cpls\powrprof\powrprof.c
#define ISDIGIT(c)  ((c) >= TEXT('0') && (c) <= TEXT('9'))

// shell\osshell\fontfldr\fontext\inc\cpanel.h
#define FCREATE( sz )            MyOpenFile( sz, NULL, OF_READWRITE | OF_CREATE )

// shell\osshell\fontfldr\fontext\src\instfls.cpp
#define RECOVERABLEERROR (VIF_SRCOLD | VIF_DIFFLANG | VIF_DIFFCODEPG | VIF_DIFFTYPE)

// shell\osshell\fontfldr\fontext\src\pfiles.cpp
#define M_INTEGERTYPE( wType )   (wType & 0x8000)
#define M_FONTDIRTYPE( wType )   ((wType & 0x7fff) == 7)

// shell\osshell\fontfldr\fontext\src\pfont.cpp
#define DBL_BSLASH(sz) \
   (*(TCHAR *)(sz)       == CHAR_BSLASH) && \
   (*(TCHAR *)((sz) + 1) == CHAR_BSLASH)

// shell\osshell\fontfldr\fontext\src\pinstall.cpp
#define RECOVERABLEERROR    (VIF_SRCOLD     |  VIF_DIFFLANG |  \
                             VIF_DIFFCODEPG |  VIF_DIFFTYPE)

// shell\osshell\fontfldr\fontext\t1instal\builder.c
#define ROMAN        (USHORT)2      /* Direction = left,right&neutrals.*/

// shell\osshell\fontfldr\fontext\t1instal\fvscodes.h
#define FVS_FILE(c)          ((c) & 0x00FF)        // Get file part

// shell\osshell\fontfldr\fontext\t1instal\metrics.h
#define GetWeight(t1m)           &(t1m->stems)
#define GetBlues(t1m)            &(t1m->blues)
#define SyntheticOblique(t1m)    (t1m->fmatrix && t1m->fmatrix[2])

// shell\osshell\lmui\shareui\shitemid.h
#define NET_IsUnicode(pidnRel)          ((pidnRel)->uUsage & NET_UNICODE)

// shell\osshell\progman\pmdde.c
#define PMPrint(s)  KdPrint(("PROGMAN: ")); \
                         KdPrint(s);            \
                         KdPrint(("\n"));

// shell\osshell\shcompui\shcompui.h
#define SCCA_CONTEXT_INIT(c)  { memset((LPVOID)c, 0, sizeof(SCCA_CONTEXT)); }

// shell\osshell\shole\sccreate.c
#define isdigit(ch) (ch>=TEXT('0') && ch<=TEXT('9'))
#define isalpha(ch) ((ch&0xdf)>=TEXT('A') && (ch&0xdf)<=TEXT('Z'))

// shell\osshell\themes\inc\rpcndr.h
#define NDRSContextValue(hContext) (&(hContext)->userContext)
#define boolean_from_ndr(source, target) \
    { \
    *(target) = *(*(char __RPC_FAR * __RPC_FAR *)&(source)->Buffer)++; \
    }
#define small_from_ndr(source, target) \
    { \
    *(target) = *(*(char __RPC_FAR * __RPC_FAR *)&(source)->Buffer)++; \
    }

// shell\osshell\version\mydiam.h
#define FdiContext          (((GotDmdTlsSlot() && GotDmdContext()) ? ((PDIAMOND_CONTEXT)(TlsGetValue(itlsDiamondContext)))->dcxFdiContext : NULL))

// shell\published\inc\systrayp.h
#define STWM_NOTIFYPOWER                (WM_USER + 201)
#define STWM_NOTIFYPCMCIA               (WM_USER + 202)
#define STWM_NOTIFYVOLUME               (WM_USER + 203)
#define STWM_NOTIFYMOUSEKEYS            (WM_USER + 205)
#define STWM_NOTIFYFILTERKEYS           (WM_USER + 206)
#define STWM_NOTIFYCSC                  (WM_USER + 207)
#define STWM_NOTIFYUSBUI                (WM_USER + 208)
#define STWM_ENABLESERVICE              (WM_USER + 220)
#define STWM_GETSTATE                   (WM_USER + 221)

// shell\published\inc\uxtheme.h
#define ETDT_ENABLETAB      (ETDT_ENABLE  | ETDT_USETABTEXTURE)

// shell\shdocvw\hist\chcommon.cpp
#define DOWNCASE(x) ( (((x) >= TEXT('A')) && ((x) <= TEXT('Z')) ) ? (((x) - TEXT('A')) + TEXT('a')) : (x) )

// shell\shdocvw\history.cpp
#define GEN_EXTION_LEN   (7 * sizeof(TCHAR))    // size == L"000.url" in chars

// shell\shdocvw\htmlstr.h
#define MAKEBSTR(name, count, strdata) \
    extern "C" const char CDECL DATA_##name [] = {(count * sizeof(OLECHAR)), 0x00, strdata}; \
    extern "C" BSTR  CDECL name = (BSTR)& DATA_##name[2];

// shell\shdocvw\iedde.cpp
#define DDETYPESTR(x) (x == XTYP_REQUEST ? TEXT("Request") : \
                       (x == XTYP_POKE ? TEXT("Poke") : \
                       (x == XTYP_EXECUTE ? TEXT("Execute") : \
                       (x == XTYP_CONNECT ? TEXT("Connect") : TEXT("Unknown")))))

// shell\shdocvw\opsprof.cpp
#define EMPTY_STRINGA(s)    ( !s || (s)[0] == '\0'  )
#define EMPTY_STRINGW(s)    ( !s || (s)[0] == L'\0' )

// shell\shdocvw\priv.h
#define InitFakeBSTR(pSA_BSTR, guid) SHStringFromGUIDW((guid), (pSA_BSTR)->wsz, ARRAYSIZE((pSA_BSTR)->wsz)), (pSA_BSTR)->cb = (38*sizeof(WCHAR))

// shell\shdocvw\urlhist.cpp
#define DEFAULT_CEI_BUFFER_SIZE         (500 * sizeof(WCHAR))

// shell\shell32\ascstr.h
#define ASENUM_ASSOC_ALL                (ASENUM_ASSOC_YES | ASENUM_ASSOC_NO)

// shell\shell32\copy.c
#define ISDIGIT(c)  ((c) >= TEXT('0') && (c) <= TEXT('9'))

// shell\shell32\dvtasks.cpp
#define FirstAce(Acl) ((PVOID)((PUCHAR)(Acl) + sizeof(ACL)))

// shell\shell32\fsassoc.cpp
#define WMUSER_DESTROYTYPE          (WM_USER + 2)       // lParam wParam are 0

// shell\shell32\fsdrptgt.cpp
#define TYMED_ALLCONTENT        (TYMED_HGLOBAL | TYMED_ISTREAM | TYMED_ISTORAGE)

// shell\shell32\fstree.cpp
#define FS_EVENTS (SHCNE_DISKEVENTS | SHCNE_ASSOCCHANGED | SHCNE_NETSHARE | SHCNE_NETUNSHARE)
#define WVCONTENT_FOLDER(fh, ft, op) { NULL, NULL, NULL, 0, &(fh), (ft), ARRAYSIZE(ft), (op), ARRAYSIZE(op), NULL }
#define WVCONTENT_SPECIAL(sh, st, op, th) { NULL, &(sh), (st), ARRAYSIZE(st), NULL, NULL, 0, (op), ARRAYSIZE(op), (th) }

// shell\shell32\menuband\iaccess.cpp
#define CH_PREFIX TEXT('&')

// shell\shell32\netview.h
#define NET_IsUnicode(pidnRel)          ((pidnRel)->uUsage & NET_UNICODE)

// shell\shell32\obex.h
#define	OBEX_HEADER_NAME	( 0x1 | OBEX_HEADER_UNICODE )
#define	OBEX_HEADER_TYPE	( 0x2 | OBEX_HEADER_STREAM )
#define	OBEX_HEADER_DESCRIPTION	( 0x5 | OBEX_HEADER_UNICODE )
#define	OBEX_HEADER_TARGET	( 0x6 | OBEX_HEADER_STREAM )
#define	OBEX_HEADER_HTTP	( 0x7 | OBEX_HEADER_STREAM )
#define	OBEX_HEADER_BODY	( 0x8 | OBEX_HEADER_STREAM )
#define	OBEX_HEADER_END_OF_BODY	( 0x9 | OBEX_HEADER_STREAM )
#define	OBEX_HEADER_WHO	( 0xa | OBEX_HEADER_STREAM )
#define	OBEX_HEADER_APP_PARAMS	( 0xc | OBEX_HEADER_STREAM )
#define	OBEX_HEADER_AUTH_CHALLENGE	( 0xd | OBEX_HEADER_STREAM )
#define	OBEX_HEADER_AUTH_RESPONSE	( 0xe | OBEX_HEADER_STREAM )
#define	OBEX_HEADER_OBJECT_CLASS	( 0xf | OBEX_HEADER_STREAM )

// shell\shell32\path.c
#define IsPathSep(ch)  ((ch) == TEXT('\\') || (ch) == TEXT('/'))

// shell\shell32\pifmgrp.h
#define HELP_CASES(rgdwHelp)                                        \
    case WM_HELP:               /* F1 or title-bar help button */   \
        OnWmHelp(lParam, &rgdwHelp[0]);                             \
        break;                                                      \
                                                                    \
    case WM_CONTEXTMENU:        /* right mouse click */             \
        OnWmContextMenu(wParam, &rgdwHelp[0]);                      \
        break;

// shell\shell32\psdocurd.c
#define DBL_BSLASH(sz) \
   (*(WCHAR *)(sz) == CHAR_BSLASH) && \
   (*(WCHAR *)((sz)+1) == CHAR_BSLASH)

// shell\shell32\shapi.cpp
#define ISDIGIT(c)  ((c) >= TEXT('0') && (c) <= TEXT('9'))

// shell\shell32\shellprv.h
#define InitFakeBSTR(pSA_BSTR, guid) SHStringFromGUIDW((guid), (pSA_BSTR)->wsz, ARRAYSIZE((pSA_BSTR)->wsz)), (pSA_BSTR)->cb = (38*sizeof(WCHAR))

// shell\shell32\unicpp\desktop.cpp
#define PERFSETMARK(text)   DoSetMark(text, sizeof(text))

// shell\shell32\util.cpp
#define ISSEP(c)   ((c) == TEXT('=')  || (c) == TEXT(','))
#define ISWHITE(c) ((c) == TEXT(' ')  || (c) == TEXT('\t') || (c) == TEXT('\n') || (c) == TEXT('\r'))

// shell\shlwapi\assocapi.cpp
#define ISQUOTED(s)   (TEXT('"') == *(s) && TEXT('"') == *((s) + lstrlen(s) - 1))

// shell\shlwapi\httpfnc.cpp
#define SETFMTETC(p, a) {(p)->cfFormat = (a); \
                         (p)->dwAspect = DVASPECT_CONTENT; \
                         (p)->lindex = -1; \
                         (p)->tymed = TYMED_ISTREAM; \
                         (p)->ptd = NULL;}

// shell\shlwapi\priv.h
#define InitFakeBSTR(pSA_BSTR, guid) SHStringFromGUIDW((guid), (pSA_BSTR)->wsz, ARRAYSIZE((pSA_BSTR)->wsz)), (pSA_BSTR)->cb = (38*sizeof(WCHAR))
#define CH_PREFIX TEXT('&')

// shell\shlwapi\uniansi.c
#define USUALLY_NULL    (&fLossy)

// shell\shlwapi\unicwrap.cpp
#define SHCNF_HAS_WSTR_PARAMS(f)   ((f & SHCNF_TYPE) == SHCNF_PATHW     ||    \
                                    (f & SHCNF_TYPE) == SHCNF_PRINTERW  ||    \
                                    (f & SHCNF_TYPE) == SHCNF_PRINTJOBW    )

// shell\shlwapi\urlpars.cpp
#define IsSafePathChar(c)       ((c > 0xff) || IsSafe(c, 9))
#define IsLiveSegment(p)    ((p) && (*p) != DEADSEGCHAR)
#define ProbeWriteStringBufferW(a, b) ProbeWriteBuffer((LPVOID)a, (b*sizeof(WCHAR)));

// shell\themes\themeui\screensaverpg.cpp
#define SLASH(c)     ((c) == TEXT('/') || (c) == TEXT('\\'))

// termsrv\admtools\c2config\inc\c2dll.h
#define UM_SHOW_CONTEXT_HELP    (WM_USER+222)

// termsrv\admtools\utilsub\parse_a.c
#define tmFormIsString(x) ((x == TMFORM_S_STRING) || (x == TMFORM_DATE) || (x == TMFORM_PHONE) || (x == TMFORM_STRING) || (x == TMFORM_X_STRING))

// termsrv\common\license\hclient\liclient\cliprot.c
#define LICENSE_STRING_LEN      sizeof(TCHAR) * lstrlen(g_LicenseString)
#define LICENSE_SIZE         ( LICENSE_STRING_LEN * REPEAT_LICENSE_STRING ) + 1 * sizeof(TCHAR)

// termsrv\common\license\inc\wincelic.h
#define HWID_STR_LEN (sizeof(HWID) * 2 + 1)

// termsrv\license\hserver\inc\sysapi.h
#define M2W( _pWchar, _pMchar ) \
    _pWchar = _alloca( ( _mbslen( ( unsigned char * )_pMchar ) + 1 ) * sizeof( WCHAR ) ); \
    if( _pWchar ) \
    {   \
        mbstowcs( _pWchar, ( unsigned char * )_pMchar, _mbslen( ( unsigned char * )_pMchar ) + 1 ); \
    }

// termsrv\license\lrwizapi\global.h
#define szCertEXTENSION_VALUE_FMT		_TEXT("TLS~%s")

// termsrv\license\tlserver\esetup\publish.cpp
#define CWSTR_SIZE(x)       (sizeof(x) - (sizeof(WCHAR) * 2))
#define DWSTR_SIZE(x)       ((wcslen(x) + 1) * sizeof(WCHAR))

// termsrv\license\tlserver\tlsapi\efind.cpp
#define CWSTR_SIZE(x)       (sizeof(x) - (sizeof(WCHAR) * 2))
#define DWSTR_SIZE(x)       ((wcslen(x) + 1) * sizeof(WCHAR))

// termsrv\remdsk\rds\as\h\fh.h
#define FH_SC_APPROX_MATCH (FH_SC_MATCH | FH_SC_ALL_CHARS)
#define FH_SC_EXACT_MATCH (FH_SC_MATCH | FH_SC_ALL_CHARS | FH_SC_EXACT)

// termsrv\remdsk\rds\as\h\t_share.h
#define NF_PRE_R11      (NF_FIXED_PITCH | NF_FIXED_SIZE | \
                         NF_ITALIC | NF_UNDERLINE | NF_STRIKEOUT)
#define NF_LOCAL            (NF_OEM_CHARSET | NF_TRUE_TYPE)

// termsrv\remdsk\rds\dev\inc16\windows.h
#define DC_CAPTION          (DC_ICON | DC_TEXT | DC_BUTTONS)// ;Internal
#define EM_SETLIMITTEXT         (WM_USER+21)
#define EM_LINEFROMCHAR         (WM_USER+25)
#define EM_GETLIMITTEXT         (WM_USER+37)    /* ;Internal 4.0 */
#define EM_POSFROMCHAR          (WM_USER+38)    /* ;Internal 4.0 */
#define EM_CHARFROMPOS          (WM_USER+39)    /* ;Internal 4.0 */
#define LB_ADDSTRING            (WM_USER+1)
#define LB_INSERTSTRING         (WM_USER+2)
#define LB_GETTEXT              (WM_USER+10)
#define LB_GETTEXTLEN           (WM_USER+11)
#define LB_SELECTSTRING         (WM_USER+13)
#define LB_FINDSTRING           (WM_USER+16)
#define LB_FINDSTRINGEXACT      (WM_USER+35)
#define LB_INSERTSTRINGUPPER    (WM_USER+43)    // ;Internal 4.0
#define LB_INSERTSTRINGLOWER    (WM_USER+44)    // ;Internal 4.0
#define LB_ADDSTRINGUPPER       (WM_USER+45)    // ;Internal 4.0
#define LB_ADDSTRINGLOWER       (WM_USER+46)    // ;Internal 4.0
#define CB_LIMITTEXT            (WM_USER+1)
#define CB_ADDSTRING            (WM_USER+3)
#define CB_GETLBTEXT            (WM_USER+8)
#define CB_GETLBTEXTLEN         (WM_USER+9)
#define CB_INSERTSTRING         (WM_USER+10)
#define CB_FINDSTRING           (WM_USER+12)
#define CB_SELECTSTRING         (WM_USER+13)
#define CB_SETEXTENDEDUI        (WM_USER+21)
#define CB_GETEXTENDEDUI        (WM_USER+22)
#define CB_FINDSTRINGEXACT      (WM_USER+24)

// termsrv\remdsk\rds\dev\inc16\windowsx.h
#define GET_WM_CHARTOITEM_CHAR(wp, lp)          ((CHAR)wp)
#define GET_WM_MENUCHAR_CHAR(wp, lp)                (CHAR)(wp)
#define GET_WM_MENUCHAR_MPS(ch, hmenu, f)    \
        (WPARAM)ch, (LPARAM)MAKELONG(f, hmenu)

// termsrv\remdsk\rds\h\standrd.h
#define DECLARE_CCOMBSTR_PROPPUT( Prop, PROP_DISPID ) \
    STDMETHOD(put_##Prop)( BSTR newVal )  \
    {\
        HRESULT hr = S_OK;\
        if( S_OK == __ATL_PROP_NOTIFY_EVENT_CLASS::FireOnRequestEdit(GetUnknown(), PROP_DISPID) )\
        {\
            m_bstr##Prop = newVal;\
            hr = __ATL_PROP_NOTIFY_EVENT_CLASS::FireOnChanged(GetUnknown(), PROP_DISPID);\
        }\
        return hr;                \
    }

// termsrv\remdsk\rds\t120\h\memmgr.h
#define GetMemoryObjectFromEncData(p)	((PMemory) ((PUChar) p - sizeof(Memory)))

// termsrv\setup\dll\conv.h
#define _wcsdupa(pStr)                                                  \
                                                                        \
    (__pAscii, (__pUnicode = pStr) == 0 ? (PWSTR) 0 : (                 \
                                                                        \
    __nLength = wcslen(__pUnicode) + 1,                                 \
                                                                        \
    wcscpy((PWSTR) _alloca(__nLength * sizeof(WCHAR)), __pUnicode)))    \
#define _strdupa(pStr)                                                  \
                                                                        \
    (__pUnicode, (__pAscii = pStr) == 0 ? (PSTR) 0 : (                  \
                                                                        \
    __nLength = strlen(__pAscii) + 1,                                   \
                                                                        \
    strcpy((PSTR) _alloca(__nLength * sizeof(CHAR)), __pAscii)))        \

// termsrv\setup\inc\conv.h
#define _wcsdupa(pStr)                                                  \
                                                                        \
    (__pAscii, (__pUnicode = pStr) == 0 ? (PWSTR) 0 : (                 \
                                                                        \
    __nLength = wcslen(__pUnicode) + 1,                                 \
                                                                        \
    wcscpy((PWSTR) _alloca(__nLength * sizeof(WCHAR)), __pUnicode)))    \
#define _strdupa(pStr)                                                  \
                                                                        \
    (__pUnicode, (__pAscii = pStr) == 0 ? (PSTR) 0 : (                  \
                                                                        \
    __nLength = strlen(__pAscii) + 1,                                   \
                                                                        \
    strcpy((PSTR) _alloca(__nLength * sizeof(CHAR)), __pAscii)))        \

// termsrv\setup\tstst\conv.h
#define _wcsdupa(pStr)                                                  \
                                                                        \
    (__pAscii, (__pUnicode = pStr) == 0 ? (PWSTR) 0 : (                 \
                                                                        \
    __nLength = wcslen(__pUnicode) + 1,                                 \
                                                                        \
    wcscpy((PWSTR) _alloca(__nLength * sizeof(WCHAR)), __pUnicode)))    \
#define _strdupa(pStr)                                                  \
                                                                        \
    (__pUnicode, (__pAscii = pStr) == 0 ? (PSTR) 0 : (                  \
                                                                        \
    __nLength = strlen(__pAscii) + 1,                                   \
                                                                        \
    strcpy((PSTR) _alloca(__nLength * sizeof(CHAR)), __pAscii)))        \

// termsrv\tsappcmp\register.c
#define GLOBALPATHSIZE  7 * sizeof( WCHAR );

// termsrv\winsta\server\winsta.c
#define VALUE_BUFFER_SIZE (sizeof(KEY_VALUE_PARTIAL_INFORMATION) + 256 * sizeof(WCHAR))
#define VALUE_BUFFER_SZ (sizeof(KEY_VALUE_PARTIAL_INFORMATION) + \
                           256 * sizeof( WCHAR))

// termsrv\wmi\tscfgwmi\conv.h
#define _wcsdupa(pStr)                                                  \
                                                                        \
    (__pAscii, (__pUnicode = pStr) == 0 ? (PWSTR) 0 : (                 \
                                                                        \
    __nLength = wcslen(__pUnicode) + 1,                                 \
                                                                        \
    wcscpy((PWSTR) _alloca(__nLength * sizeof(WCHAR)), __pUnicode)))    \
#define _strdupa(pStr)                                                  \
                                                                        \
    (__pUnicode, (__pAscii = pStr) == 0 ? (PSTR) 0 : (                  \
                                                                        \
    __nLength = strlen(__pAscii) + 1,                                   \
                                                                        \
    strcpy((PSTR) _alloca(__nLength * sizeof(CHAR)), __pAscii)))        \

// tools\wppconfig\rev1\control.tpl
#  define WPP_INIT_TRACING(AppName) (WPP_CONTROL_ANNOTATION(),WPP_INIT_STATIC_DATA,\
       WppInitUm(AppName, &WPP_CB[0].Registration))
#  define WPP_INIT_TRACING(DrvObj, RegPath) (WPP_CONTROL_ANNOTATION(),WPP_INIT_STATIC_DATA,\
        WppInitKm(RegPath, &WPP_CB[0].Registration))

// tools\x86\perl\lib\core\cop.h
#define POPSUB1(cx)							\
	cxsub = cx->blk_sub;	/* because DESTROY may clobber *cx */
#define PUSHEVAL(cx,n,fgv)						\
	cx->blk_eval.old_in_eval = PL_in_eval;				\
	cx->blk_eval.old_op_type = PL_op->op_type;				\
	cx->blk_eval.old_name = n;					\
	cx->blk_eval.old_eval_root = PL_eval_root;				\
	cx->blk_eval.cur_text = PL_linestr;

// tools\x86\perl\lib\core\handy.h
#   define isPRINT(c)	(((c) > 32 && (c) < 127) || isSPACE(c))
#  define isALNUM_LC(c) \
	(NXIsAlpha((unsigned int)(c)) || NXIsDigit((unsigned int)(c)) || \
	 (char)(c) == '_')
#  define isIDFIRST_LC(c) \
	(NXIsAlpha((unsigned int)(c)) || (char)(c) == '_')
#    define isALNUM_LC(c) \
	(isalpha((unsigned char)(c)) || \
	 isdigit((unsigned char)(c)) || (char)(c) == '_')
#    define isIDFIRST_LC(c) (isalpha((unsigned char)(c)) || (char)(c) == '_')
#    define isPRINT_LC(c)	(isascii(c) && isprint(c))
#define Newz(x,v,n,t)	(v = (t*)safemalloc((MEM_SIZE)((n)*sizeof(t)))), \
			memzero((char*)(v), (n)*sizeof(t))
#define Newz(x,v,n,t)	(v = (t*)safexmalloc((x),(MEM_SIZE)((n)*sizeof(t)))), \
			 memzero((char*)(v), (n)*sizeof(t))
#define Move(s,d,n,t)	(void)memmove((char*)(d),(char*)(s), (n) * sizeof(t))
#define Copy(s,d,n,t)	(void)memcpy((char*)(d),(char*)(s), (n) * sizeof(t))
#define Zero(d,n,t)	(void)memzero((char*)(d), (n) * sizeof(t))

// tools\x86\perl\lib\core\iperlsys.h
#define PerlLIO_tmpnam(str)						\
	PL_piLIO->Tmpnam((str), ErrorNo())
#define PerlSock_select(n, r, w, e, t)					\
	PL_piSock->Select(n, (char*)r, (char*)w, (char*)e, t, ErrorNo())

// tools\x86\perl\lib\core\perl.h
#           define Strerror(e) \
		((e) < 0 || (e) >= sys_nerr ? "(unknown)" : sys_errlist[e])
#    define MALLOC_TERM MUTEX_DESTROY(&PL_malloc_mutex)

// tools\x86\perl\lib\core\sys\socket.h
#define PERL_FD_ZERO(p) memset((char *)(p),0,sizeof(*(p)))

// tools\x86\perl\lib\core\thread.h
#define MUTEX_DESTROY(m)			\
    STMT_START {				\
	if (pthread_mutex_destroy((m)))		\
	    croak("panic: MUTEX_DESTROY");	\
    } STMT_END
#define COND_DESTROY(c)				\
    STMT_START {				\
	if (pthread_cond_destroy((c)))		\
	    croak("panic: COND_DESTROY");	\
    } STMT_END

// tools\x86\perl\site\lib\xml\parser\expat\xmlparse\xmlparse.c
#define INIT_TAG_BUF_SIZE 32  /* must be a multiple of sizeof(XML_Char) */

// tools\x86\perl\site\lib\xml\parser\expat\xmltok\xmltok.c
#define LITTLE2_CHAR_MATCHES(enc, p, c) ((p)[1] == 0 && (p)[0] == c)
#define BIG2_CHAR_MATCHES(enc, p, c) ((p)[0] == 0 && (p)[1] == c)

// windows\advcore\ctf\aimm1.2\inc\imeapp.h
#define RWM_SERVICE     TEXT("MSIMEService")
#define RWM_UIREADY     TEXT("MSIMEUIReady")
#define RWM_AUTOCOMPLETE 		TEXT("MSIMEAutoComplete")
#define RWM_DOCKDICT 		TEXT("MSIMEDockActiveDict")
#define RWM_MOUSE 		TEXT("MSIMEMouseOperation")
#define	RWM_RECONVERT			TEXT("MSIMEReconvert")
#define	RWM_RECONVERTREQUEST	TEXT("MSIMEReconvertRequest")
#define	RWM_DOCUMENTFEED	TEXT("MSIMEDocumentFeed")
#define	RWM_QUERYHIDECARET	TEXT("MSIMEQueryHideCaret")
#define	RWM_QUERYPOSITION	TEXT("MSIMEQueryPosition")
#define	RWM_MODEBIAS			TEXT("MSIMEModeBias")
#define	RWM_KEYMAP				TEXT("MSIMEKeyMap")
#define	RWM_CHGKEYMAP			TEXT("MSIMEChangeKeyMap")
#define	RWM_NTFYKEYMAP			TEXT("MSIMENotifyKeyMap")
#define RWM_RECONVERTOPTIONS          TEXT("MSIMEReconvertOptions")

// windows\advcore\ctf\inc\ccstock.h
#define CbFromCchW(cch)             ((cch)*sizeof(WCHAR))
#define CbFromCchA(cch)             ((cch)*sizeof(CHAR))
#define ISDIGIT(c)  ((c) >= TEXT('0') && (c) <= TEXT('9'))

// windows\advcore\ctf\inc\cstring.h
#define afxEmptyString ((CString&)*(CString*)&_afxPchNil)

// windows\advcore\ctf\inc\msime.h
#define RWM_SERVICE     TEXT("MSIMEService")
#define RWM_UIREADY     TEXT("MSIMEUIReady")
#define RWM_MOUSE       TEXT("MSIMEMouseOperation")
#define RWM_RECONVERT           TEXT("MSIMEReconvert")
#define RWM_RECONVERTREQUEST    TEXT("MSIMEReconvertRequest")
#define RWM_DOCUMENTFEED    TEXT("MSIMEDocumentFeed")
#define RWM_QUERYPOSITION   TEXT("MSIMEQueryPosition")
#define RWM_MODEBIAS            TEXT("MSIMEModeBias")
#define RWM_KEYMAP              TEXT("MSIMEKeyMap")
#define RWM_CHGKEYMAP           TEXT("MSIMEChangeKeyMap")
#define RWM_NTFYKEYMAP          TEXT("MSIMENotifyKeyMap")
#define RWM_RECONVERTOPTIONS          TEXT("MSIMEReconvertOptions")

// windows\advcore\ctf\uim\marshal.h
#define MPARAM_OUT_BSTR           (MPARAM_OUT | MPARAM_BSTR)

// windows\advcore\duser\duexts\duexts.cpp
#define _InitTypeRead(Addr, lpszType)   GetShortField(Addr, (PUCHAR)lpszType, 1)

// windows\advcore\duser\engine\services\osal.cpp
	#define W2AN(lpw, cch) (\
		((_lpw = lpw) == NULL) ? NULL : (\
			_convert = (cch+1)*2,\
			ATLW2AHELPER((LPSTR) alloca(_convert), _lpw, _convert, _acp)))
	#define W2AN(lpw, cch) (\
		((_lpw = lpw) == NULL) ? NULL : (\
			_convert = (cch+1)*2,\
			ATLW2AHELPER((LPSTR) alloca(_convert), _lpw, _convert)))

// windows\advcore\duser\engine\winapi\apistubs.cpp
#define END_RECV_NOCONTEXT()                    \
    goto ErrorExit;                             \
ErrorExit:                                      \
    return retval;

// windows\advcore\gdiplus\engine\entry\aatext.cpp
#define R_SET(j)   ((j) & 0X30)
#define B_SET(j)   ((j) & 0X03)

// windows\advcore\gdiplus\engine\flat\flatapi.cpp
#define COPYCODECINFOSTR(_f)            \
        dst->_f = (GDIPCONST WCHAR*) buf;   \
        size = SizeofWSTR(cur->_f);     \
        memcpy(buf, cur->_f, size);     \
        buf += size

// windows\advcore\gdiplus\engine\imaging\api\codecmgr.cpp
#define COPYRSRCSTR(_f)                             \
        cur->_f = (const WCHAR*) buf;               \
        memcpy(buf, _f##Str, _f##Len);              \
        buf += _f##Len
#define COPYCODECINFOSTR(_f)            \
        dst->_f = (const WCHAR*) buf;   \
        size = SizeofWSTR(cur->_f);     \
        memcpy(buf, cur->_f, size);     \
        buf += size

// windows\advcore\gdiplus\engine\imaging\api\imgutils.hpp
#define SizeofSTR(s)    (sizeof(CHAR) * (strlen(s) + 1))
#define SizeofWSTR(s)   (sizeof(WCHAR) * (UnicodeStringLength(s) + 1))

// windows\advcore\gdiplus\engine\imaging\png\zlib\trees.c
#define Buf_size (8 * 2*sizeof(char))

// windows\advcore\gdiplus\engine\imaging\png\zlib\zlib.h
#define deflateInit(strm, level) \
        deflateInit_((strm), (level),       ZLIB_VERSION, sizeof(z_stream))
#define inflateInit(strm) \
        inflateInit_((strm),                ZLIB_VERSION, sizeof(z_stream))

// windows\advcore\gdiplus\engine\imaging\png\zlib\zutil.h
#define ZALLOC(strm, items, size) \
           (*((strm)->zalloc))((strm)->opaque, (items), (size))

// windows\advcore\gdiplus\engine\text\imager\bidianalysis.hpp
#define ODD(x) ((x) & 1)

// windows\advcore\gdiplus\engine\text\imager\fulltextimager.cpp
#define IsDelimiter(c)              (BOOL)(c == 0x20 || c == 13 || c == 10)

// windows\advcore\gdiplus\engine\text\imager\lineservicesowner.hpp
#define IsEOP(ch)   (BOOL)((ch) == WCH_CR || (ch) == WCH_LF)

// windows\advcore\gdiplus\test\anitest\anitest.cpp
#define SizeofWSTR(s) (sizeof(WCHAR) * (wcslen(s) + 1))

// windows\advcore\gdiplus\test\frametest\winutil.cpp
#define SizeofWSTR(s) (sizeof(WCHAR) * (wcslen(s) + 1))

// windows\advcore\gdiplus\test\imgtest\imgtest.cpp
#define SizeofWSTR(s) (sizeof(WCHAR) * (wcslen(s) + 1))

// windows\advcore\rcml\rcmlex\cicero\applaunch\cmdline.h
#define CMDLINE_BEGIN(cmdLine, firstarg, rubbish, wantQuotes) \
    {                                                           \
    LPTSTR pszArgs=new TCHAR[lstrlen(cmdLine)*sizeof(TCHAR)+4]; \
    lstrcpy(pszArgs,lpCmdLine);                                 \
    lstrcat(pszArgs,TEXT(" "));                                 \
    LPTSTR pszSwitch=pszArgs;                                   \
    LPTSTR lastArg=pszArgs;                                     \
    LPTSTR * ppszRubbish=rubbish;                   \
    LPTSTR * ppszDest=firstarg;                     \
    BOOL    bInQuotes=FALSE;                        \
    BOOL    bStripQuotes=wantQuotes;                \
    while(*pszSwitch!=0)                            \
    {                                               \
        if( *pszSwitch==TEXT('"') )                 \
        {                                           \
            if( bStripQuotes )                      \
            {                                       \
                if(bInQuotes)                       \
                    *pszSwitch=TEXT(' ');           \
                else                                \
                    lastArg=pszSwitch+1;            \
            }                                       \
            bInQuotes=!bInQuotes;                   \
        }                                           \
                                                    \
        if( (bInQuotes==FALSE) && (*pszSwitch==TEXT(' ')) ) \
        {                                           \
            *pszSwitch=NULL;                        \
            if( *lastArg==TEXT('/') )               \
                *lastArg=TEXT('-');                 \
            if(FALSE)                               \
            {}                                      \

// windows\advcore\rcml\rcmlgen\cmdline.h
#define CMDLINE_BEGIN(cmdLine, firstarg, rubbish, wantQuotes) \
    {                                                           \
    LPTSTR pszArgs=new TCHAR[lstrlen(cmdLine)*sizeof(TCHAR)+4]; \
    lstrcpy(pszArgs,lpCmdLine);                                 \
    lstrcat(pszArgs,TEXT(" "));                                 \
    LPTSTR pszSwitch=pszArgs;                                   \
    LPTSTR lastArg=pszArgs;                                     \
    LPTSTR * ppszRubbish=rubbish;                   \
    LPTSTR * ppszDest=firstarg;                     \
    BOOL    bInQuotes=FALSE;                        \
    BOOL    bStripQuotes=wantQuotes;                \
    while(*pszSwitch!=0)                            \
    {                                               \
        if( *pszSwitch==TEXT('"') )                 \
        {                                           \
            if( bStripQuotes )                      \
            {                                       \
                if(bInQuotes)                       \
                    *pszSwitch=TEXT(' ');           \
                else                                \
                    lastArg=pszSwitch+1;            \
            }                                       \
            bInQuotes=!bInQuotes;                   \
        }                                           \
                                                    \
        if( (bInQuotes==FALSE) && (*pszSwitch==TEXT(' ')) ) \
        {                                           \
            *pszSwitch=NULL;                        \
            if( *lastArg==TEXT('/') )               \
                *lastArg=TEXT('-');                 \
            if(FALSE)                               \
            {}                                      \

// windows\advcore\rcml\rcmlgen\resfile.cpp
#define PROPERTY(p,id, def) if( ((dwRemainingStyles & p)==p) != def ) { wsprintf(szBuffer, TEXT("%s=\"%s\" "), id, (dwRemainingStyles & p)?TEXT("YES"):TEXT("NO") ); m_pWin32->AllocAddAttribute(szBuffer, 0); }

// windows\advcore\rcml\xmllib\xml\xmlstream\xmlstream.cxx
#define DELAYMARK(hr) (hr == S_OK || (hr >= XML_E_TOKEN_ERROR && hr < XML_E_LASTERROR))

// windows\appcompat\sdbapi\lib\apphelp.c
#define SIZE_WSTRING(pwsz) \
    (pwsz == NULL ? 0 : (wcslen((LPCWSTR)(pwsz)) * sizeof(WCHAR) + sizeof(UNICODE_NULL)))

// windows\appcompat\sdbapi\sdbapi.c
#define EXTRA_BUF_SPACE (16 * sizeof(TCHAR))

// windows\appcompat\sdbapi\sdbp.h
#define SDBCONTEXT_GET_PIPE(hSDB) \
        (((PSDBCONTEXT)(hSDB))->hPipe)
#define PREPARE_FORMAT(pszFormat, Format) \
    {                                                                           \
        STACK_ALLOC(pszFormat, (strlen(Format) + 1) * sizeof(*Format));         \
        if (pszFormat != NULL) {                                                \
            PrepareFormatForUnicode(pszFormat, Format);                         \
        }                                                                       \
    }
#define SdbpGetMainLibraryFile(hSDB, szFileName) \
    SdbpGetLibraryFile(((PSDBCONTEXT)(hSDB))->pdbMain, (szFileName))
#define READ_STRING(pdb, tiWhich, pwszBuffer, dwBufferSize) \
    (SdbpReadTagData((pdb), (tiWhich), (pwszBuffer), (dwBufferSize) * sizeof(WCHAR)))
#define COPY_TEMP_STRINGTABLE(pdb, pszTempStringtable) \
    RtlCreateUnicodeString(&pdb->ustrTempStringtable, pszTempStringtable)
#define COPY_TEMP_STRINGTABLE(pdb, pszTempStringtable) \
    ((pdb->pszTempStringtable = SdbpDuplicateString(pszTempStringtable)), \
     (NULL != pdb->pszTempStringtable))

// windows\appcompat\shims\inc\rtlutils.h
#define ShimAssignUnicodeStringBuffer(Buff, Str) \
    (((Buff)->String.Length = 0), (ShimAppendUnicodeStringBuffer((Buff), (Str))))

// windows\appcompat\shims\lib\rtlutils.cpp
#define ENOUGH_CHARS(_cch) (String->Length >= ((_cch) * sizeof(WCHAR)))

// windows\appcompat\shims\lib\win9xpath.cpp
#define IsWhackWhack( lpstr )               (lpstr[0] == WHACK && lpstr[1] == WHACK)
#define IsWhackWhackDotWhack( lpstr )       (lpstr[0] == WHACK && lpstr[1] == WHACK && lpstr[2] == DOT      && lpstr[3] == WHACK)
#define IsWhackWhackQuestionWhack( lpstr )  (lpstr[0] == WHACK && lpstr[1] == WHACK && lpstr[2] == QUESTION && lpstr[3] == WHACK)

// windows\appcompat\slayerui\win2k\stdafx.h
#define DECLARE_REGISTRY_CLSID()                                        \
static HRESULT WINAPI UpdateRegistry(BOOL bRegister)                    \
{                                                                       \
    return _Module.UpdateRegistryCLSID(GetObjectCLSID(), bRegister);    \
}

// windows\core\ntcon\inc\conime.h
#define CONIME_DESTROY                  (WM_USER+1)

// windows\core\ntcon\inc\input.h
#define LoadKeyEvent(PEVENT,KEYDOWN,CHAR,KEYCODE,SCANCODE,KEYSTATE) { \
        (PEVENT)->EventType = KEY_EVENT;                              \
        (PEVENT)->Event.KeyEvent.bKeyDown = KEYDOWN;                  \
        (PEVENT)->Event.KeyEvent.wRepeatCount = 1;                    \
        (PEVENT)->Event.KeyEvent.uChar.UnicodeChar = CHAR;            \
        (PEVENT)->Event.KeyEvent.wVirtualKeyCode = KEYCODE;           \
        (PEVENT)->Event.KeyEvent.wVirtualScanCode = SCANCODE;         \
        (PEVENT)->Event.KeyEvent.dwControlKeyState = KEYSTATE;        \
        }

// windows\core\ntcon\inc\server.h
#define CM_DESTROY_WINDOW        (WM_USER+1)
#define CM_MODE_TRANSITION       (WM_USER+6)

// windows\core\ntcon\server\_output.h
#define CHAR_OF_PCI(p)  (((PCHAR_INFO)(p))->Char.AsciiChar)
#define WCHAR_OF_PCI(p) (((PCHAR_INFO)(p))->Char.UnicodeChar)
#define ATTR_OF_PCI(p)  (((PCHAR_INFO)(p))->Attributes)
#define SIZEOF_CI_CELL  sizeof(CHAR_INFO)

// windows\core\ntcon\server\stream.c
#define LINE_INPUT_BUFFER_SIZE (256 * sizeof(WCHAR))
#define EITHER_CTRL_PRESSED (LEFT_CTRL_PRESSED | RIGHT_CTRL_PRESSED)
#define EITHER_ALT_PRESSED (LEFT_ALT_PRESSED | RIGHT_ALT_PRESSED)
#define MOD_PRESSED (SHIFT_PRESSED | EITHER_CTRL_PRESSED | EITHER_ALT_PRESSED)
#define KEYEVENTSTATE_EQUAL_WINMODS(Event, WinMods)\
    ((Event.Event.KeyEvent.dwControlKeyState & ConsKbdState[WinMods]) && \
    !(Event.Event.KeyEvent.dwControlKeyState & MOD_PRESSED & ~ConsKbdState[WinMods]))

// windows\core\ntgdi\client\mfrec.hxx
#define SIZEOF_MRGDICOMMENT_BEGINGROUP(cb)            \
        ((sizeof(EMRGDICOMMENT_BEGINGROUP)+sizeof(WCHAR)*(cb)+3) & ~3)
#define SIZEOF_MREXTTEXTOUT(cchString, cjCh, bPdy)              \
        ((sizeof(MREXTTEXTOUT)                                  \
         +(cchString)*((cjCh) + sizeof(LONG)*((bPdy) ? 2 : 1))  \
         +3) / 4 * 4)
#define SIZEOF_MRPOLYTEXTOUT(cpt,cjTotal)               \
        (sizeof(MRPOLYTEXTOUT) - sizeof(MTEXT)          \
         + (cpt)*sizeof(MTEXT) + (cjTotal))

// windows\core\ntgdi\fondrv\tt\kdexts\ttexts.cxx
#define N2(a,b) dprintf("[%x] %s", &pRemote->##a, (b))

// windows\core\ntgdi\fondrv\tt\ttfd\tt.h
#define CHAR_CODE(bToMac,wc)                                \
(                                                           \
(bToMac) ? ui16UnicodeToMac((uint16)(wc)) : (uint16)(wc)    \
)

// windows\core\ntgdi\fondrv\vtfd\fontfile.h
#define pfcAlloc()   ((PFONTCONTEXT)EngAllocMem(0, sizeof(FONTCONTEXT), 'dftV'))

// windows\core\ntgdi\gre\aatext.cxx
#define COPY_BUFFER_SIZE (sizeof(double) * COPY_BUFFER_ENTRIES)
#define R_SET(j)   ((j) & 0X30)
#define B_SET(j)   ((j) & 0X03)

// windows\core\ntgdi\gre\engine.h
    #define SIZEOF_STROBJ_BUFFER(cwc)           \
        ((cwc) * sizeof(GLYPHPOS))

// windows\core\ntgdi\gre\fontlink.hxx
#define OEM_ASSOC       1 // equal to (Charset(255) + 2) & 0xf)
#define ANSI_ASSOC      2 // equal to (Charset(  0) + 2) & 0xf)
#define SYMBOL_ASSOC    4 // equal to (Charset(  2) + 2) & 0xf)

// windows\core\ntgdi\gre\rleblt.h
#define RLE8_ClipRight(OverRun, RunLength, OutColumn)                        \
    if ((OutColumn + (LONG) RunLength) > (LONG)ulDstRight)                          \
    {                                                                        \
        OverRun = (OutColumn + RunLength) - ulDstRight;                      \
        RunLength -= OverRun;                                                \
    } else                                                                   \
        OverRun = 0;                                                         \
#define RLE_InVisibleRect(RunLength, OutColumn)                              \
    ((lOutRow < (LONG) ulDstBottom) &&                                       \
     ((OutColumn) < (LONG)ulDstRight)  &&                                    \
     (((OutColumn) + (LONG) (RunLength)) > (LONG) ulDstLeft))                        \
#define RLE_ColVisible(Col) ( ( (Col) >= (LONG) ulDstLeft  )                 \
                           && ( (Col) <  (LONG) ulDstRight ) )

// windows\core\ntgdi\gre\stretch.hxx
#define DDA(d,i)		\
    (d)->lQuo += (i)->dt.lQuo;	\
    (d)->lRem += (i)->dt.lRem;	\
    if ((d)->lRem >= (i)->lDen) \
    {				\
	(d)->lQuo += 1; 	\
	(d)->lRem -= (i)->lDen; \
    }

// windows\core\ntgdi\gre\textddi.cxx
#define SO_RTOL          (SO_LTOR | SO_REVERSED)
#define SO_BTOT          (SO_TTOB | SO_REVERSED)

// windows\core\ntgdi\halftone\ht\htstret.h
#define INC_PIN_BY_1ST_LEFT(p,f)        (p) += ((f) & AAIF_EXP_HAS_1ST_LEFT)
#define SHARPEN_PWGRAY_LR(pSP, bL, bC, bR)                                  \
{                                                                           \
    _SHARPEN_WCLR_LR((pSP)->Gray, (bL), bC, bR, (DI_R_SHIFT - 8));          \
}
#define GET_CONST_ALPHA_BGR(pS, pD, pwBGR)                                  \
{                                                                           \
    pS->b = _GET_CONST_ALPHA(pwBGR[pS->b +   0], pD->b, pwBGR);             \
    pS->g = _GET_CONST_ALPHA(pwBGR[pS->g + 256], pD->g, pwBGR);             \
    pS->r = _GET_CONST_ALPHA(pwBGR[pS->r + 512], pD->r, pwBGR);             \
}
#define GET_CONST_ALPHA_GRAY(pS, pbD, pwBGR)                                \
        ((PGRAYF)pS)->Gray = _GRAY_CONST_ALPHA(pwBGR[pS->g], *pbD, pwBGR)

// windows\core\ntgdi\icm\mscms\ps2.c
#define WriteHex(pBuf, x)            OPSprintf(pBuf, "%x", ((x) & 0x00FF))
#define WriteHex(pBuf, x)            wsprintfA(pBuf, "%2.2x", ((x) & 0x00FF))

// windows\core\ntgdi\inc\hmgshare.h
#define CLEAR_CACHED_TEXT(pdcattr)  (pdcattr->ulDirty_ &= ~(SLOW_WIDTHS))

// windows\core\ntgdi\inc\ht.h
#define SIZE_CHAR           sizeof(CHAR)

// windows\core\ntgdi\kdexts2\dcexts.cxx
    #define M2(aa,bb) \
        dprintf("[%x] %s", &(pdclSrc->##aa), (bb))

// windows\core\ntgdi\kdexts2\fontexts.cxx
#define GetRFONTSubField(field,local)    \
        GetFieldData(foSrc, GDIType(RFONT), field, sizeof(local), &local)
#define GetFONTOBJSubField(field,local)    \
        GetFieldData(foSrc, GDIType(FONTOBJ), field, sizeof(local), &local)
#define GetPFESubField(field,local)    \
        GetFieldData(pfeSrc, GDIType(PFE), field, sizeof(local), &local)
#define GetIFIMETRICSSubField(field,local)    \
        GetFieldData(pifiSrc, GDIType(IFIMETRICS), field, sizeof(local), &local)
#define GetPFFSubField(field,local)    \
        GetFieldData(pffSrc, GDIType(PFF), field, sizeof(local), &local)
#define GetESTROBJSubField(field,local)    \
        GetFieldData(estrobjSrc, GDIType(ESTROBJ), field, sizeof(local), &local)
#define GetGLYPHPOSSubField(field,local)    \
        GetFieldData(glyphposSrc, GDIType(GLYPHPOS), field, sizeof(local), &local)
#define GetGLYPHDEFSubField(field,local)    \
        GetFieldData(glyphdefSrc, GDIType(GLYPHDEF), field, sizeof(local), &local)
#define GetCACHESubField(field,local)    \
        GetFieldData(cacheSrc, GDIType(CACHE), field, sizeof(local), &local)
    #define M3(aa,bb) \
        dprintf("[%x] %s%-#x\n", &(pdcaSrc->##aa), (bb), pdca->##aa)
    #define M2(aa,bb) \
        dprintf("[%x] %s", &(pdcaSrc->##aa), (bb))
    #define N2(a,c)   dprintf("[%x] %s", &p0->##c, (a))
    #define N3(a,b,c) dprintf("[%x] %s", &p0->##c, (a)); dprintf((b),p1->##c)
    #define N2(a,c)   dprintf("[%x] %s", &p0->##c, (a))
    #define N3(a,b,c) dprintf("[%x] %s", &p0->##c, (a)); dprintf((b),p1->##c)
    #define N2(a,c)   dprintf("[%x] %s", &p0->##c, (a))
    #define N3(a,b,c) dprintf("[%x] %s", &p0->##c, (a)); dprintf((b),p1->##c)
    #define N2(a,c)   dprintf("[%x] %s", &p0->##c, (a))
    #define N3(a,b,c) dprintf("[%x] %s", &p0->##c, (a)); dprintf((b),p1->##c)
    #define N3(a,b,c) dprintf("[%x] %s", &ptmRemote->##c, (a)); dprintf((b),ptmLocal->##c)
    #define N3(a,b,c) dprintf("[%x] %s", &ptmdRemote->##c, (a)); dprintf((b),ptmdLocal->##c)
    #define N2(a,c)   dprintf("[%x] %s\n", &pPDEV->##c, (a))
    #define N3(a,b,c) dprintf("[%x] %s", &pPDEV->##c, (a)); dprintf((b),_pdev.##c)
    #define N2(a,c)   dprintf("[%x] %s", &pFdm->##c, (a))
    #define N3(a,b,c) dprintf("[%x] %s", &pFdm->##c, (a)); dprintf((b),Fdm.##c)

// windows\core\ntgdi\kdexts2\precomp.hxx
#define DECLARE_API(extension)                                  \
CPPMOD HRESULT CALLBACK extension(PDEBUG_CLIENT Client, PCSTR args)

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\comdlg32.h
#define CHAR_BAR                  TEXT('|')

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\dlgs.c
        #define NetworkButtonTextAccel   TEXT("Net&work...")

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\filenew.cpp
#define IsServer(psz)        (IsUNC(psz) && !StrChr((psz) + 2, CHAR_BSLASH))

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\fileopen.h
#define DBL_BSLASH(sz) \
   (*(TCHAR *)(sz)       == CHAR_BSLASH) && \
   (*(TCHAR *)((sz) + 1) == CHAR_BSLASH)

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\prnsetup.h
#define ISDIGIT(c)                ((c) >= TEXT('0') && (c) <= TEXT('9'))

// windows\core\ntgdi\test\ft\ftchar.c
#define SIZEOF_CMAPTABLE  (3 * sizeof(uint16))

// windows\core\ntgdi\umpdproxy\umpdproxy.c
#define RtlHandleToChar(a,b,c,d) RtlLargeIntegerToChar((PLARGE_INTEGER)&(a),(b),(c),(d))

// windows\core\ntuser\client\fareast.c
#define IMMMODULENAMELEN    ((sizeof PATHDLM + sizeof IMMMODULENAME) / sizeof(WCHAR))

// windows\core\ntuser\client\ntstubs.c
#define GETCOMPOSITIONSTRING(hImc, index, buf, buflen) \
            (bAnsi ? fpImmGetCompositionStringA : fpImmGetCompositionStringW)((hImc), (index), (buf), (buflen))

// windows\core\ntuser\client\usercli.h
#define IGTM_SEPARATE           (2)     // | MT with single thread per context

// windows\core\ntuser\client\wstrings.c
#define WCTOA(wch)  ((wch) & 0xff)

// windows\core\ntuser\inc\ntsend.h
#define COPYLPWSTR(pinstr, psz) \
    (pinstr)->fAllocated = FALSE;                           \
    (pinstr)->pstr = &(pinstr)->strCapture;                 \
    RtlInitUnicodeString(&(pinstr)->strCapture, (psz));
#define LARGECOPYLPWSTR(pinstr, psz) \
    (pinstr)->fAllocated = FALSE;                           \
    (pinstr)->pstr = &(pinstr)->strCapture;                         \
    RtlInitLargeUnicodeString(&(pinstr)->strCapture, (psz), (UINT)-1);

// windows\core\ntuser\inc\user.h
#define GWL_CONVCONTEXT     GWLP_PCI + sizeof(PVOID)
#define CPD_TRANSITION_TYPES    (CPD_ANSI_TO_UNICODE|CPD_UNICODE_TO_ANSI)
#define CH_PREFIX TEXT('&')

// windows\core\ntuser\kdexts\userexts.c
#define _InitTypeRead(Addr, lpszType)   GetShortField(Addr, (PUCHAR)lpszType, 1)

// windows\core\ntuser\kernel\clipbrd.c
#define IsTextHandle(fmt, hdata)       \
    (((hdata) != DUMMY_TEXT_HANDLE) && \
     (((fmt) == CF_TEXT) || ((fmt) == CF_OEMTEXT) || ((fmt) == CF_UNICODETEXT)))

// windows\core\ntuser\kernel\queue.c
    #define MODULESUFFIXSIZE    (8 * sizeof(WCHAR))

// windows\core\ntuser\kernel\sbctl.c
#define REEVALUATE_PSBTRACK(pSBTrack, pwnd, str)          \
    if ((pSBTrack) != PWNDTOPSBTRACK(pwnd)) {             \
        RIPMSG3(RIP_VERBOSE,                              \
                "%s: pSBTrack changed from %#p to %#p",   \
                (str), (pSBTrack), PWNDTOPSBTRACK(pwnd)); \
    }                                                     \
    (pSBTrack) = PWNDTOPSBTRACK(pwnd)

// windows\core\ntuser\kernel\ssend.c
#define CALC_SIZE_IN(cb, pstr) \
    cb = (pstr)->Length + sizeof(WCHAR);  \
    if ((pstr)->bAnsi && !fAnsiReceiver)  \
        cb *= sizeof(WCHAR);

// windows\core\ntuser\kernel\userk.h
#define ProbeAndReadLargeString(Address)                          \
    (((Address) >= (LARGE_STRING * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile LARGE_STRING * const)MM_USER_PROBE_ADDRESS) : (*(volatile LARGE_STRING *)(Address)))
#define ProbeForReadReconvertString(pReconv) \
    ProbeForRead((pReconv), (pReconv)->dwSize, 1)
#define ProbeForWriteImeCharPosition(Address) { \
    if ((Address) >= (PrivateIMECHARPOSITION* const)MM_USER_PROBE_ADDRESS) {    \
        *(volatile ULONG* const)MM_USER_PROBE_ADDRESS = 0;                      \
    }                                                                           \
                                                                                \
    *(volatile PrivateIMECHARPOSITION*)(Address) = *(volatile PrivateIMECHARPOSITION*)(Address); \
}
#define TestRawInputMode(pti, mode) \
    ((pti) && (pti)->ppi && (pti)->ppi->pHidTable && (pti)->ppi->pHidTable->f##mode)
#define CM_MODE_TRANSITION       (WM_USER+6)

// windows\core\ntuser\rtl\drawtext.c
    #define CALCRECT(wFormat)               (wFormat & DT_CALCRECT)
    #define EDITCONTROL(wFormat)            (wFormat & DT_EDITCONTROL)
    #define EXPANDTABS(wFormat)             (wFormat & DT_EXPANDTABS)
    #define EXTERNALLEADING(wFormat)        (wFormat & DT_EXTERNALLEADING)
    #define MODIFYSTRING(wFormat)           (wFormat & DT_MODIFYSTRING)
    #define NOPREFIX(wFormat)               (wFormat & DT_NOPREFIX)
    #define PATHELLIPSIS(wFormat)           (wFormat & DT_PATH_ELLIPSIS)
    #define SINGLELINE(wFormat)             (wFormat & DT_SINGLELINE)
    #define TABSTOP(wFormat)                (wFormat & DT_TABSTOP)
    #define NOFULLWIDTHCHARBREAK(dwFormat)  (dwFormat & DT_NOFULLWIDTHCHARBREAK)
#define ENDELLIPSIS(wFormat)        (wFormat & DT_END_ELLIPSIS)
#define NOCLIP(wFormat)             (wFormat & DT_NOCLIP)
#define RTLREADING(wFormat)         (wFormat & DT_RTLREADING)
#define HIDEPREFIX(wFormat)         (wFormat & DT_HIDEPREFIX)

// windows\core\w32inc\immstruc.h
#define MOD_MODIFY_KEYS         (MOD_ALT|MOD_CONTROL|MOD_SHIFT|MOD_WIN)
#define MOD_BOTH_SIDES          (MOD_LEFT|MOD_RIGHT)

// windows\feime\chs\ntabc\winabc\abc95def.h
#define ISC_SETCONTEXT_UI               (ISC_SHOWUIALL|ISC_SHOW_SOFTKBD)

// windows\feime\chs\ntgb\imedefs.h
#define ISC_SETCONTEXT_UI       (ISC_SHOWUIALL|ISC_SHOW_SOFTKBD)

// windows\feime\cht\imedefs.h
#define ISC_SETCONTEXT_UI               (ISC_SHOWUIALL|ISC_SHOW_SOFTKBD)

// windows\feime\ddk\jpn\fakeime.h
#define UPDATE_ALL              ( UPDATE_MODE | UPDATE_SYSTEM | UPDATE_TEXT )
#define FIGWL_COMPSTARTNUM (FIGWL_COMPSTARTSTR+sizeof(LONG))
#define GCS_COMPALL ( GCS_COMPSTR | GCS_COMPATTR | GCS_COMPREADSTR | GCS_COMPREADATTR | GCS_COMPCLAUSE | GCS_COMPREADCLAUSE)
#define GCS_RESULTALL ( GCS_RESULTSTR | GCS_RESULTREADSTR | GCS_RESULTCLAUSE | GCS_RESULTREADCLAUSE)

// windows\feime\kor\ime2k\cicerolib\inc\ccstock.h
#define CbFromCchW(cch)             ((cch)*sizeof(WCHAR))
#define CbFromCchA(cch)             ((cch)*sizeof(CHAR))
#define ISDIGIT(c)  ((c) >= TEXT('0') && (c) <= TEXT('9'))

// windows\feime\kor\ime2k\fecommon\lib\ddbtn\ddbtn.h
#define DDBM_SETTEXT			(WM_USER + 105)

// windows\feime\kor\ime2k\fecommon\lib\exbtn\exbtn.h
#define EXBM_SETTEXT			(WM_USER + 103)

// windows\feime\kor\ime2k\imm32\imc.h
#define GCS_COMP_KOR (GCS_COMPSTR|GCS_COMPATTR)

// windows\feime\kor\ime2k\imm32\imedefs.h
#define ISC_SETCONTEXT_UI               (ISC_SHOWUIALL /*|ISC_SHOW_SOFTKBD*/)

// windows\feime\usa\imedefs.h
#define ISC_SETCONTEXT_UI               (ISC_SHOWUIALL|ISC_SHOW_SOFTKBD)

// windows\netdde\src\nddeagnt\nddeagnt.c
#define IMMMODULENAMELEN    ((sizeof PATHDLM + sizeof IMMMODULENAME) / sizeof(WCHAR))

// windows\netdde\src\ntddecmn\pktz.c
#define GetLPSZNegCmdString(lpNegCmd,offs)      \
    (LPSTR)(((lpNegCmd)->nc_strings)+offs)

// windows\oleacc\oleacc\client.cpp
#define CH_PREFIX       ((TCHAR)'&')

// windows\richedit\inc30\imeapp.h
#define	RWM_SERVICE		TEXT("MSIMEService")
#define RWM_AUTOCOMPLETE 		TEXT("MSIMEAutoComplete")
#define RWM_DOCKDICT 		TEXT("MSIMEDockActiveDict")
#define RWM_MOUSE 		TEXT("MSIMEMouseOperation")
#define	RWM_RECONVERT			TEXT("MSIMEReconvert")
#define	RWM_RECONVERTREQUEST	TEXT("MSIMEReconvertRequest")
#define	RWM_DOCUMENTFEED	TEXT("MSIMEDocumentFeed")
#define	RWM_QUERYHIDECARET	TEXT("MSIMEQueryHideCaret")
#define	RWM_QUERYPOSITION	TEXT("MSIMEQueryPosition")
#define	RWM_MODEBIAS			TEXT("MSIMEModeBias")
#define	RWM_KEYMAP				TEXT("MSIMEKeyMap")
#define	RWM_CHGKEYMAP			TEXT("MSIMEChangeKeyMap")
#define	RWM_NTFYKEYMAP			TEXT("MSIMENotifyKeyMap")

// windows\richedit\inc30\imm.h
#define SCS_SETSTR                      (GCS_COMPREADSTR|GCS_COMPSTR)

// windows\richedit\inc30\ourtypes.h
#define MakeOLESTR(_szA)	\
	(CchSzAToSzW((_szA), szWT, sizeof(szWT)) ? szWT : NULL)
#define MakeANSI(_szW)		\
	(CchSzWToSzA((_szW), szAT, sizeof(szAT)) ? szAT : NULL)

// windows\richedit\inc41\imeapp.h
#define	RWM_SERVICE		TEXT("MSIMEService")
#define RWM_AUTOCOMPLETE 		TEXT("MSIMEAutoComplete")
#define RWM_DOCKDICT 		TEXT("MSIMEDockActiveDict")
#define RWM_MOUSE 		TEXT("MSIMEMouseOperation")
#define	RWM_RECONVERT			TEXT("MSIMEReconvert")
#define	RWM_RECONVERTREQUEST	TEXT("MSIMEReconvertRequest")
#define	RWM_DOCUMENTFEED	TEXT("MSIMEDocumentFeed")
#define	RWM_QUERYHIDECARET	TEXT("MSIMEQueryHideCaret")
#define	RWM_QUERYPOSITION	TEXT("MSIMEQueryPosition")
#define	RWM_MODEBIAS			TEXT("MSIMEModeBias")
#define	RWM_KEYMAP				TEXT("MSIMEKeyMap")
#define	RWM_CHGKEYMAP			TEXT("MSIMEChangeKeyMap")
#define	RWM_NTFYKEYMAP			TEXT("MSIMENotifyKeyMap")

// windows\richedit\inc41\imm.h
#define SCS_SETSTR                      (GCS_COMPREADSTR|GCS_COMPSTR)

// windows\richedit\inc41\ourtypes.h
#define MakeOLESTR(_szA)	\
	(CchSzAToSzW((_szA), szWT, sizeof(szWT)) ? szWT : NULL)

// windows\richedit\inci\chnutils.h
#define  InitSublineChunkContext(plschnkcontext, urFirst, vrFirst)		\
					FlushSublineChunkContext(plschnkcontext); \
					(plschnkcontext)->urFirstChunk = (urFirst); \
					(plschnkcontext)->vrFirstChunk = (vrFirst);
#define SetNTIAppliedToLastChunk(plschnkcontext) \
		(plschnkcontext)->fNTIAppliedToLastChunk = fTrue;
#define FlushNTIAppliedToLastChunk(plschnkcontext) \
		(plschnkcontext)->fNTIAppliedToLastChunk = fFalse;
#define FNTIAppliedToLastChunk(plschnkcontext) \
		(plschnkcontext)->fNTIAppliedToLastChunk
#define LastDnodeFromChunk(plschunkcontext) \
		 DnodeFromChunk(plschunkcontext, (plschunkcontext)->locchnkCurrent.clschnk - 1)
#define 	ApplyFFirstSublineToChunk(plschunkcontext, fFirstSubline) \
	(plschunkcontext)->locchnkCurrent.lsfgi.fFirstOnLine = \
		FIsFirstOnLine(plschunkcontext->pplsdnChunk[0]) \
									&& fFirstSubline ;

// windows\richedit\inci\lscfmtfl.h
#define TurnOnAllSimpleText(plsc) \
		(plsc)->plslineCur->fAllSimpleText = fTrue;
#define TurnOffAllSimpleText(plsc) \
		(plsc)->plslineCur->fAllSimpleText = fFalse;
#define FAllSimpleText(plsc) \
		(plsc)->plslineCur->fAllSimpleText
#define TurnOnLineCompressed(plsc) \
		(plsc)->lsadjustcontext.fLineCompressed = fTrue;
#define TurnOffLineCompressed(plsc) \
		(plsc)->lsadjustcontext.fLineCompressed = fFalse;
#define FLineCompressed(plsc) \
		(plsc)->lsadjustcontext.fLineCompressed
#define SetLineCompressed(plsc,f) \
		(plsc)->lsadjustcontext.fLineCompressed = (f);
#define FUnderlineTrailSpacesRM(plsc) \
		(plsc)->lsadjustcontext.fUnderlineTrailSpacesRM
#define SetUnderlineTrailSpacesRM(plsc,f) \
		(plsc)->lsadjustcontext.fUnderlineTrailSpacesRM = (f);
#define TurnOnAutodecimalTabPresent(plsc) \
		(plsc)->lsadjustcontext.fAutodecimalTabPresent = fTrue;
#define TurnOffAutodecimalTabPresent(plsc) \
		(plsc)->lsadjustcontext.fAutodecimalTabPresent = fFalse;
#define FAutodecimalTabPresent(plsc) \
		(plsc)->lsadjustcontext.fAutodecimalTabPresent

// windows\richedit\lssrc\break.c
#define		IsItTextDnode(plsdn, plsc) \
			((plsdn) == NULL) ? fFalse : \
			(IdObjFromDnode(plsdn) == IobjTextFromLsc(&plsc->lsiobjcontext))
#define GetCpFromPosInChunk(plschunkcontext, posichnk) \
		((DnodeFromChunk(plschunkcontext, (posichnk).ichnk))->cpFirst + (posichnk).dcp)

// windows\richedit\lssrc\lsfetch.c
#define CreateLNObjInLsc(plsc, iobj) ((PLsimFromLsc(&((plsc)->lsiobjcontext),iobj))->pfnCreateLNObj\
									 (PilsobjFromLsc(&((plsc)->lsiobjcontext),iobj), \
														   &((plsc)->plslineCur->rgplnobj[iobj])))

// windows\richedit\lssrc\lstxtbrk.c
#define FRegularBreakableBeforeDobj(ptxtobj) \
		((ptxtobj)->txtkind == txtkindRegular || (ptxtobj)->txtkind == txtkindYsrChar || \
		 (ptxtobj)->txtkind == txtkindSpecSpace || (ptxtobj)->txtkind == txtkindHardHyphen)
#define FRegularBreakableAfterDobj(ptxtobj) \
		((ptxtobj)->txtkind == txtkindRegular || (ptxtobj)->txtkind == txtkindYsrChar || \
		 (ptxtobj)->txtkind == txtkindSpecSpace)

// windows\richedit\re30\_edit.h
#define fNEEDCHARBREAK      (fTHAI | fDEVANAGARI | fTAMIL)

// windows\richedit\re30\_uspi.h
#define cli_Itemize                 (cli_string | cli_psi)

// windows\richedit\re30\_w32sys.h
#define IsSymbolOrOEM(x)	(x == SYMBOL_CHARSET || x == OEM_CHARSET)

// windows\richedit\re30\ime.cpp
#define HAVE_COMPOSITION_STRING() ( 0 != (lparam & (GCS_COMPSTR | GCS_COMPATTR)))
#define HAVE_RESULT_STRING() ( 0 != (lparam & GCS_RESULTSTR))

// windows\richedit\re30\rtflex.cpp
#define cbRTFSig    (cchRTFSig * sizeof(char))

// windows\richedit\re30\text.cpp
#define MATCHARABICSPECIALS	(FR_MATCHALEFHAMZA | FR_MATCHKASHIDA | FR_MATCHDIAC)

// windows\richedit\re41\_edit.h
#define FNEEDCHARBREAK	(FTHAI | FINDIC)

// windows\richedit\re41\_msremsg.h
#define GDF_ALL (GDF_READONLY | GDF_OVERTYPE | GDF_SINGLECPG | GDF_RICHTEXT)

// windows\richedit\re41\_uspi.h
#define cli_Itemize                 (cli_string | cli_psi)

// windows\richedit\re41\_w32sys.h
#define IsUnicodeCP(cp)		(((cp) & ~1) == CP_ULE)
#define IsSymbolOrOEMCharRep(x)	(x == SYMBOL_INDEX || x == OEM_INDEX)

// windows\richedit\re41\ime.cpp
#define HAVE_COMPOSITION_STRING() ( 0 != (lparam & (GCS_COMPSTR | GCS_COMPATTR)))
#define HAVE_RESULT_STRING() ( 0 != (lparam & GCS_RESULTSTR))

// windows\richedit\re41\text.cpp
#define MATCHARABICSPECIALS	(FR_MATCHALEFHAMZA | FR_MATCHKASHIDA | FR_MATCHDIAC)

// windows\winstate\cobra\tools\utiltool\dbedit\keyadd.c
#define ISDRIVELETTER(Str) ((Str) && (Str)[1]==':' && ((Str)[2]=='\0' || (Str)[2]=='\\'))
```

