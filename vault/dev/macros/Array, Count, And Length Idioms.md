# Array, Count, And Length Idioms

[Macros index](<macros.md>)

## Curated Candidates

```c
// net\layer2svc\wlsnp\ccomp.h
#define ARRAYLEN(x) (sizeof(x) / sizeof((x)[0]))

// drivers\dot4\dot4usb\dot4usb.h
#define arraysize(p) (sizeof(p)/sizeof((p)[0])) // number of elements in an array

// drivers\wdm\vbi\tests\testnab\testnab.cpp
#define ENTRIES(a)  (sizeof(a)/sizeof(*(a)))

// multimedia\directx\dplay\dnet\sp\serial\dpnmodemlocals.h
#define	LENGTHOF( arg )		( sizeof( arg ) / sizeof( arg[ 0 ] ) )

// multimedia\media\mixerapp\volumei.h
#define SIZEOF(x)   (sizeof((x))/sizeof((x)[0]))

// admin\activec\base\pickicon.cpp
#define cA(a) (sizeof(a)/sizeof(a[0]))

// net\upnp\host\upnphost\inc\servutil.h
#define CONSTSIZEOF(x)      (sizeof(x)-1)

// ds\security\services\ca\include\celib.h
#define WSZARRAYSIZE(a)		((sizeof(a)/sizeof((a)[0])) - 1)

// base\win32\fusion\inc\numberof.h
#define NUMBER_OF(array)									\
		(sizeof(NUMBER_OF_validate((array), &(array))),	\
			(sizeof((array)) / sizeof((array)[0])))

// base\win32\fusion\debugexts\dumpers.cpp
    #define STRING_AND_LENGTH(x) (x), (NUMBER_OF(x) - 1)

// sdktools\bvtsigvf\sigverif.h
#define SIZECHARS(x) (sizeof((x))/sizeof(TCHAR))
```

## Backlog

```c
// admin\activec\designer\vb98ctls\include\datapath.h
#define IProvideClassInfo3_GetGUIDDwordArrays(This,rguidArray,pcaUUID,pcadw)	\
    (This)->lpVtbl -> GetGUIDDwordArrays(This,rguidArray,pcaUUID,pcadw)

// admin\activec\designer\vb98ctls\include\kxalpha.h
#define ALTERNATE_ENTRY(Name)           \
        .globl  Name;                   \
Name:;

// admin\activec\designer\vb98ctls\include\wininet.h
#define INTERNET_MAX_URL_LENGTH         ((sizeof(INTERNET_MAX_PROTOCOL_NAME) - 1) \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// admin\activec\designer\vb98ctls\mssnapr\mssnapr\rtconst.h
#define CCH_RESURL                  ((sizeof(RESURL) / sizeof(WCHAR)) - 1)

// admin\activec\inc\countof.h
    #define countof(x) (sizeof(x) / sizeof((x)[0]))

// admin\activec\locparser\locstudiosdk\inc\locutil\flddefhelp.h
#define STRING_LIST_COLUMN_ENTRY(name, nID, IDSName, IDSHelp, ops, fDisplay, fSort, fReadOnly, pfnValidateFunc, IDSList) \
	{ { name, nID, IDSName, IDSHelp, CColumnVal::cvtStringList, ops, fDisplay, fSort, fReadOnly, pfnValidateFunc }, IDSList}

// admin\activec\locparser\locstudiosdk\inc\mit\mitutil\macros.h
#define COUNTOF(x) (sizeof(x)/sizeof(*x))

// admin\activec\locparser\locstudiosdk\inc\mit\mitutil\uiopthelp.h
#define LOC_UI_OPTIONS_BOOL_ENTRY(name, def, et, id, idHelp, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, def, et}
#define LOC_UI_OPTIONS_PICK_ENTRY(name, def, add, list, id, idHelp, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, def, add, list}
#define LOC_UI_OPTIONS_STR_ENTRY(name, def, et, id, idHelp, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, def, et}
#define LOC_UI_OPTIONS_STRLIST_ENTRY(name, def, id, idHelp, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, def}
#define LOC_UI_OPTIONS_FILENAME_ENTRY(name, def, id, idHelp, idExt, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, idExt, def}

// admin\activec\test\snapins\inc\nodetypes.hxx
#define CSNR(_a)        (sizeof(_a)/sizeof(SNR))
#define CICONID(_a)     (sizeof(_a)/sizeof(LONG))

// admin\admt\command\stdafx.h
#define countof(a) (sizeof(a) / sizeof(a[0]))

// admin\admt\common\commonlib\names.cpp
	#define DC_PREFIX_LENGTH (sizeof(s_szDcPrefix) / sizeof(s_szDcPrefix[0]) - 1)

// admin\admt\common\include\common.hpp
#define DIM(array) (sizeof (array) / sizeof (array[0]))

// admin\admt\common\include\ealen.hpp
#define  EA_AccountGroup                         (EA_AccountGGroup|EA_AccountLGroup)
#define  EA_AccountAll                           (EA_AccountGroup|EA_AccountUser)

// admin\admt\enumtrst\common.hpp
#define DIM(array) (sizeof (array) / sizeof (array[0]))

// admin\admt\enumtrst\ealen.hpp
#define  EA_AccountGroup                         (EA_AccountGGroup|EA_AccountLGroup)
#define  EA_AccountAll                           (EA_AccountGroup|EA_AccountUser)

// admin\admt\enumtrst\trenum.cpp
#define DIM(array) (sizeof(array) / sizeof(array[0]))

// admin\admt\exenum\common.hpp
#define DIM(array) (sizeof (array) / sizeof (array[0]))

// admin\admt\exenum\ealen.hpp
#define  EA_AccountGroup                         (EA_AccountGGroup|EA_AccountLGroup)
#define  EA_AccountAll                           (EA_AccountGroup|EA_AccountUser)

// admin\admt\mapiutil\common.hpp
#define DIM(array) (sizeof (array) / sizeof (array[0]))

// admin\admt\migdrvr\monitor.h
#define DCT_UPDATE_ENTRY   (WM_APP+2)
#define DCT_ERROR_ENTRY    (WM_APP+3)
#define DCT_SERVER_COUNT   (WM_APP+4)
#define DCT_UPDATE_COUNTS  (WM_APP+6)

// admin\admt\mspwdmig\error.cpp
#define COUNT_OF(a) (sizeof(a) / sizeof(a[0]))
#define LENGTH_OF(a) (sizeof(a) / sizeof(a[0]) - sizeof(a[0]))

// admin\admt\profext\common.hpp
#define DIM(array) (sizeof (array) / sizeof (array[0]))

// admin\admt\script\error.cpp
#define COUNT_OF(a) (sizeof(a) / sizeof(a[0]))

// admin\admt\script\stdafx.cpp
#define COUNT_OF(a) (sizeof(a) / sizeof(a[0]))

// admin\admt\setdtct\common.hpp
#define DIM(array) (sizeof (array) / sizeof (array[0]))

// admin\admt\workobj\_entryid.h
#define CBDIR_ENTRYID sizeof(DIR_ENTRYID)
#define CBUSR_ENTRYID sizeof(USR_ENTRYID)

// admin\admt\workobj\dapi.h
#define cchSubstServer        ((sizeof (pszSubstServerA) / sizeof(CHAR)) - 1)

// admin\controls\smonctrl\toolbar.cpp
#define TB_ENTRIES      (sizeof(SysmonToolbarButtons) / sizeof (SysmonToolbarButtons[0]))

// admin\cys\win32\fpcyscom.h
#define ISpCys_SPGetMessageIDs(This,pcArray,pArray)	\
    (This)->lpVtbl -> SPGetMessageIDs(This,pcArray,pArray)

// admin\darwin\src\engine\autoapi.cpp
#define cKillKeys   (sizeof(rgKillKeys)/sizeof(TCHAR *))

// admin\darwin\src\engine\coreactn.cpp
#define cCae	(sizeof(rgcae)/sizeof(CActionEntry))

// admin\darwin\src\engine\imemory.cpp
#define cClasses	(sizeof(rgszClasses)/sizeof(char *))

// admin\darwin\src\engine\record.cpp
#define cparamCacheMax		(sizeof(mpCparamRcci)/sizeof(RCCI))

// admin\darwin\src\inc\module.h
#define cCLSIDs     (sizeof(rgCLSIDLoad)/sizeof(GUID))

// admin\darwin\src\msitools\iceman\msiice15.dll\msiice15.cpp
#define ICE88_SQL_QUERIES_CNT (sizeof(ListSqlInfo)/sizeof(SQLINFO))

// admin\extens\acldiag\accessck.h
#define SID_ARRAY_SIZE  sizeof (ULONG) * 8

// admin\hmonitor\connmgr\source\connmgrex.h
#define IWbemObjectSink_Indicate(This,lObjectCount,apObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,apObjArray)

// admin\netui\acledit\acledit\ntfsacl.cxx
#define COUNT_FILEPERMS_ARRAY   (sizeof(sedappaccessFilePerms)/sizeof(SED_APPLICATION_ACCESS))
#define COUNT_DIRPERMS_ARRAY    (sizeof(sedappaccessDirPerms)/sizeof(SED_APPLICATION_ACCESS))
#define COUNT_FILE_AUDITPERMS_ARRAY   (sizeof(sedappaccessFileAudits)/sizeof(SED_APPLICATION_ACCESS))
#define COUNT_DIR_AUDITPERMS_ARRAY   (sizeof(sedappaccessDirAudits)/sizeof(SED_APPLICATION_ACCESS))

// admin\netui\common\h\array.hxx
#define DECL_ARRAY_LIST_OF(type,dec)                        \
                                                            \
DECL_ARRAY_OF(type,dec);                                    \
                                                            \
class dec ARRAY_LIST_OF( type ) : public ARRAY_OF( type )   \
{                                                           \
public:                                                     \
    ARRAY_LIST_OF( type )( UINT cAlloc = 0 );               \
                                                            \
    BOOL Add( const type & t );                             \
    BOOL AddIdemp( const type & t );                        \
    BOOL Remove( const type & t );                          \
    INT  Find( const type & t ) const;                      \
    VOID Clear();                                           \
                                                            \
    VOID Sort();                                            \
    INT  BinarySearch( const type & t ) const;              \
    static int __cdecl SortFunc (                          \
        const void * p1, const void * p2 ) ;                \
};

// admin\netui\common\h\mbcs.h
#define MxUnicodeBufferSize(size) (sizeof(WCHAR)/sizeof(CHAR)*(size))

// admin\netui\common\h\smx.h
#define SM_GETSELCOUNT                  (WM_USER + 1000)

// admin\netui\common\h\stack.hxx
#define DECLARE_STACK_OF(type)						    \
									    \
class stack_node_of_##type;						    \
class STACK_OF(type);							    \
class ITER_ST_OF(type);							    \
                                                                            \
class stack_node_of_##type						    \
{									    \
    friend class STACK_OF(type) ;					    \
    friend class ITER_ST_OF(type) ;					    \
									    \
protected:								    \
  stack_node_of_##type *next;						    \
  type *item;								    \
};									    \
									    \
									    \
DECLARE_ITER_OF(type)							    \
									    \
class ITER_ST_OF(type) : public ITER_OF(type)	/* Unsafe stack iterator */ \
{									    \
public: 								    \
    ITER_ST_OF(type)( const STACK_OF(type)& st ) ;			    \
    ~ITER_ST_OF(type)() ;						    \
    void  Reset( void ) ;						    \
    type* operator()(void) { return Next(); }				    \
    type* Next( void ) ;						    \
									    \
private:								    \
    stack_node_of_##type *_pstknodeCurrent ;				    \
    const STACK_OF(type) *_pstk ;					    \
									    \
};									    \
									    \
class STACK_OF(type)							    \
{									    \
    friend class ITER_ST_OF(type) ;					    \
									    \
private:								    \
    UINT uNumElem ;							    \
    stack_node_of_##type *StackBase;					    \
public: 								    \
    STACK_OF(type)();							    \
    ~STACK_OF(type)();							    \
    void   Clear( void ) ;						    \
    UINT QueryNumElem( void ) ;						    \
    APIERR Push( type * const Item);					    \
    type *Pop( void );							    \
    type *Peek( void ) ;						    \
};									    \
									    \
/*#define DEFINE_STACK_OF(type)*/					    \
STACK_OF(type)::STACK_OF(type)()					    \
{									    \
    StackBase = (stack_node_of_##type *) NULL ; 			    \
    uNumElem = 0 ;							    \
}									    \
									    \
STACK_OF(type)::~STACK_OF(type)()					    \
{									    \
    Clear() ;								    \
}									    \
									    \
UINT STACK_OF(type)::QueryNumElem( void )				    \
{									    \
    return ( uNumElem ) ;						    \
}									    \
									    \
void STACK_OF(type)::Clear( void )					    \
{									    \
    type *item ;							    \
									    \
    while ( item = Pop() )						    \
	delete item ;							    \
									    \
    StackBase = (stack_node_of_##type *) 0 ;				    \
    uNumElem = 0 ;							    \
}									    \
									    \
APIERR STACK_OF(type)::Push( type * const pItem)			    \
{									    \
    UIASSERT( pItem != NULL ) ; 					    \
									    \
    stack_node_of_##type *node = new stack_node_of_##type;		    \
									    \
    if (node == (stack_node_of_##type *) NULL ) 			    \
	return(ERROR_NOT_ENOUGH_MEMORY);				    \
    else								    \
	node->item = pItem ;						    \
									    \
    node->next = StackBase;						    \
    StackBase = node;							    \
    uNumElem++ ;							    \
    return(NERR_Success);						    \
}									    \
									    \
type *STACK_OF(type)::Pop()						    \
{									    \
    stack_node_of_##type *node; 					    \
    type *pitem;							    \
									    \
    if (StackBase == (stack_node_of_##type *) NULL)			    \
	return((type *) NULL);						    \
									    \
    node = StackBase;							    \
    pitem = StackBase->item;						    \
    StackBase = StackBase->next;					    \
    delete node;							    \
    uNumElem-- ;							    \
    return(pitem);							    \
}									    \
type *STACK_OF(type)::Peek()						    \
{									    \
    if (StackBase == NULL)						    \
	return((type *) NULL);						    \
    else								    \
	return (StackBase->item);					    \
}									    \
									    \
ITER_ST_OF(type) :: ITER_ST_OF(type)( const STACK_OF(type)& stk )	    \
{									    \
    _pstk = &stk ;							    \
    _pstknodeCurrent = stk.StackBase ;					    \
}									    \
									    \
ITER_ST_OF(type) :: ~ITER_ST_OF(type)() 				    \
{									    \
	;								    \
}									    \
									    \
type * ITER_ST_OF(type) :: Next( void ) 				    \
{									    \
    if (_pstknodeCurrent)						    \
    {									    \
	stack_node_of_##type *_pstknodeTmp = _pstknodeCurrent ; 	    \
									    \
	_pstknodeCurrent = _pstknodeCurrent->next ;			    \
	return (_pstknodeTmp->item) ;					    \
    }									    \
    else								    \
    {									    \
	return ((type *) NULL) ;					    \
    }									    \
									    \
}									    \
									    \
									    \
void ITER_ST_OF(type) :: Reset( void )					    \
{									    \
     _pstknodeCurrent = _pstk->StackBase ;				    \
}

// admin\netui\common\h\umx.h
#define UM_GETSELCOUNT                  (WM_USER + 1000)

// admin\netui\common\hack\dos\windows.h
#define EM_GETLINECOUNT         (WM_USER+10)
#define EM_LINELENGTH	        (WM_USER+17)
#define LB_GETCOUNT	       (WM_USER+12)
#define LB_GETSELCOUNT	       (WM_USER+17)
#define CB_GETCOUNT	         (WM_USER+6)

// admin\netui\common\src\applib\pch\usrmle.cxx
#define NUM_SIDS             (sizeof(syssid)/sizeof(syssid[0]))

// admin\netui\common\src\lmobj\lmobj\lmodom.cxx
#define DC_CACHE_ENTRY_EXPIRED(t_cache, t_current) \
    ( (t_cache == 0) || \
      (t_current < t_cache) || \
      ((t_current - t_cache) > DC_CACHE_EXPIRY) )

// admin\netui\ftpmgr\cpl\ftpmcpl.cxx
#define NUM_APPLETS ( sizeof(CplApplets) / sizeof(CplApplets[0]) )

// admin\netui\liccpa\test\licsetup\ctls.c
#define AIL_LINECOUNT   (4*sizeof(LONG))

// admin\netui\macprint\inc\prtdefs.h
#define	LSIZE_FC			((sizeof(LFILTERCONTROL)/sizeof(WCHAR)) - 1)

// admin\netui\macprint\pstodib\ti\pstodib\psti.c
#define PS_NUM_TRAYS_DEFINED ( sizeof(TrayList) / sizeof(TrayList[0]) )

// admin\netui\macprint\pstodib\ti\src\lang\init1pp.h
#define     PRE_CACHE_N    ((sizeof(pre_array) / sizeof(fix16)) / 5)

// admin\netui\nwc\nwc\nwccpl.cxx
#define NUM_APPLETS ( sizeof(CplApplets) / sizeof(CplApplets[0]) )

// admin\netui\shell\test\apptest4.cxx
#define SIZEOF_NEWOBJ_ARRAY	(sizeof(sedappaccessNewObj))
#define SIZEOF_NO_NEWOBJ_ARRAY	(sizeof(sedappaccessNoNewObj))
#define SIZEOF_AUDIT_ARRAY	(sizeof(sedappaccessAuditting))
#define COUNT_NEWOBJ_ARRAY	(sizeof(sedappaccessNewObj)/sizeof(SED_APPLICATION_ACCESS))
#define COUNT_NO_NEWOBJ_ARRAY	(sizeof(sedappaccessNoNewObj)/sizeof(SED_APPLICATION_ACCESS))
#define COUNT_AUDIT_ARRAY	(sizeof(sedappaccessAuditting)/sizeof(SED_APPLICATION_ACCESS))

// admin\netui\shellui\share\shareacl.cxx
#define COUNT_FILEPERMS_ARRAY	(sizeof(sedappaccessSharePerms)/sizeof(SED_APPLICATION_ACCESS))

// admin\pchealth\client\datacoll\wmiprov\pch_drive.cpp
#define   maxMediaTypes         (sizeof(szMediaTypeStrings)/sizeof(*szMediaTypeStrings))

// admin\pchealth\client\datacoll\wmiprovn\pch_drive.cpp
#define   maxMediaTypes         (sizeof(szMediaTypeStrings)/sizeof(*szMediaTypeStrings))

// admin\pchealth\client\include\util.h
#define sizeofSTRW(wsz) sizeof(wsz) / sizeof(WCHAR)

// admin\pchealth\sr\api\precomp.h
#define DIMENSION( array )                                                  \
    ( sizeof(array) / sizeof((array)[0]) )

// admin\pchealth\sr\inc\hashlist.h
#define SR_MAX_EXTENSION_LENGTH   sizeof(UNICODE_STRING) +  \
                                  ((SR_MAX_EXTENSION_CHARS + 1) * sizeof(WCHAR))

// admin\pchealth\sr\inc\ppath.h
#define IFSPathLength(ppath) ((ppath)->pp_totalLength - sizeof(short)*2)

// admin\pchealth\sr\kernel\filelist.h
#define SR_RENAME_BUFFER_LENGTH         ( sizeof(FILE_RENAME_INFORMATION) \
                                            +SR_MAX_FILENAME_LENGTH     \
                                            +sizeof(WCHAR) )
#define SR_FILENAME_BUFFER_LENGTH       ( sizeof(UNICODE_STRING)        \
                                            +SR_MAX_FILENAME_LENGTH     \
                                            +sizeof(WCHAR) )

// admin\pchealth\sr\kernel\hash.c
#define HASH_KEY_LENGTH( pHashKey ) \
    ((pHashKey)->FileName.Length + (pHashKey)->StreamNameLength)

// admin\pchealth\sr\kernel\srpriv.h
#define SR_ALLOCATE_ARRAY(pt,et,c,t)                \
    (et *)(SR_ALLOCATE_POOL(pt,sizeof(et)*(c),t))
#define IS_FILENAME_VALID_LENGTH( pExtension, pFileName, StreamLength ) \
    (((((pFileName)->Length + (StreamLength)) - (pExtension)->pNtVolumeName->Length) < \
        (SR_MAX_FILENAME_PATH * sizeof( WCHAR ))) ?                            \
        TRUE :                                                                   \
        FALSE )
#define SR_GUID_BUFFER_LENGTH        (38 * sizeof(WCHAR))
#define DIMENSION(x) ( sizeof(x) / sizeof(x[0]) )
#define MAX_ULONG_LENGTH    (MAX_ULONG_CHARS*sizeof(WCHAR))
#define MOUNTMGR_VOLUME_NAME_PREFIX_LENGTH (49*sizeof(WCHAR))
#define SR_UNIQUE_TEMP_FILE_LENGTH  (37 * sizeof(WCHAR))

// admin\pchealth\sr\shell\extwrap.cpp
#define COUNT_RPI_ENTRY  (sizeof(s_aryRPIList)/sizeof(SRPIStub))

// admin\services\drizzle\utils\nt4thunks.cpp
#define SDDL_LEN_TAG( tagdef )  ( sizeof( tagdef ) / sizeof( WCHAR ) - 1 )

// admin\services\sched\inc\misc.hxx
#define ARRAY_LEN(a)    (sizeof(a)/sizeof(a[0]))

// admin\services\sched\setup\setup.cxx
#define ARRAY_LEN(a)                (sizeof(a)/sizeof((a)[0]))

// admin\services\sched\svc_core\netsch.cxx
#define BUFFER_LENGTH_MINIMUM (sizeof(AT_ENUM) + (MAXIMUM_COMMAND_LENGTH+1)*sizeof(WCHAR))

// admin\services\sched\test\jt\util.hxx
#define ARRAY_LEN(a)    (sizeof(a)/sizeof(a[0]))

// admin\services\sched\wizard\seltrig.cxx
#define ARRAY_LEN(a)    (sizeof(a)/sizeof(a[0]))

// admin\snapin\chooser\chooser.cpp
	#define LENGTH(x)		(sizeof(x)/sizeof(x[0]))

// admin\snapin\dnsmgr\record.cpp
#define SWITCH_ENTRY(x) \
	case DNS_TYPE_##x : \
		pNode = new CDNS_##x_RecordNode; \
		break;

// admin\snapin\dnsmgr\uiutil.h
#define ARRAYLENGTH(x)  (sizeof(x)/sizeof((x)[0]))

// admin\snapin\dsadmin\util.h
#define LENGTH(x)		(sizeof(x)/sizeof(x[0]))

// admin\snapin\filemgmt\stdafx.h
#define LENGTH(x)	(sizeof(x)/sizeof(x[0]))

// admin\snapin\sendcmsg\util.h
#define LENGTH(x)			(sizeof(x)/sizeof(x[0]))

// admin\snapin\wsecmgr\chklist.h
#define CLM_GETITEMCOUNT    (WM_USER + 3)   // no parameters

// admin\wizards\addusrw\dapi.h
#define cchSubstServer        ((sizeof (pszSubstServerA) / sizeof(CHAR)) - 1)

// admin\wmi\wbem\adapters\oledb\client\wmiclnt.h
# define NUMELEM(p) (sizeof(p)/sizeof(*p))

// admin\wmi\wbem\adapters\oledb\wmiglobal.h
# define NUMELEM(x) (sizeof(x)/sizeof(*x))

// admin\wmi\wbem\adapters\wmireverseperformancemonitor\include\__common_convert.h
#define	SAFEARRAY_TO_LPWSTRARRAY( psa, pppsz, pdwsz )\
__StringConvert::ConvertSafeArrayToLPWSTRArray( psa, pppsz, pdwsz )
#define	LPWSTRARRAY_TO_SAFEARRAY( ppsz, dwsz, ppsa )\
__StringConvert::ConvertLPWSTRArrayToSafeArray( ppsz, dwsz, ppsa )

// admin\wmi\wbem\common\stdlibrary\helper.h
    #define LENGTH_OF(a) (sizeof(a)/sizeof(a[0]))

// admin\wmi\wbem\policman\cse\wmi_cse.h
#define WMIGPO_GETOBJECT_STRLEN (sizeof(WMIGPO_GETOBJECT_TEMPLATE)/sizeof(WCHAR) +MAX_PATH +1)

// admin\wmi\wbem\providers\framework\provmfc\mtex.cpp
#define _countof(array) (sizeof(array)/sizeof(array[0]))

// admin\wmi\wbem\providers\snmpprovider\common\snmpmfc\mtex.cpp
#define _countof(array) (sizeof(array)/sizeof(array[0]))

// admin\wmi\wbem\providers\win32provider\cimwin32a\ntdomain.cpp
#define DOMAIN_PREPEND_SIZE sizeof(DOMAIN_PREPEND)/sizeof(WCHAR) - 1

// admin\wmi\wbem\providers\win32provider\providers\msinfo_cdrom.h
#define NUM_ELEMENTS(arr)       (sizeof(arr)/sizeof(arr[0]))

// admin\wmi\wbem\providers\win32provider\providers\os.cpp
#define CountProductSuiteNames (sizeof(ProductSuiteNames)/sizeof(PWSTR))

// admin\wmi\wbem\providers\win32provider\providers\printer.cpp
#define COUNTOF(x) (sizeof x/sizeof *x)

// admin\wmi\wbem\providers\win32provider\providers\printercfg.cpp
#define MAX_PAPERSIZE_INDEX  sizeof(g_dwSizes)/sizeof(g_dwSizes[0])

// admin\wmi\wbem\sdk\activex\controls\commondlls\hmmvgrid\utils.h
#define CIM_TYPEMASK (~CIM_FLAG_ARRAY)

// admin\wmi\wbem\sdk\locstudioparser\inc\mit\mitutil\macros.h
#define COUNTOF(x) (sizeof(x)/sizeof(*x))

// admin\wmi\wbem\shell\atlui\inc\snapins.inc\rpcndr.h
#define boolean_array_from_ndr(Source, LowerIndex, UpperIndex, Target) \
    { \
    NDRcopy ( \
        (((char __RPC_FAR *)(Target))+(LowerIndex)), \
        (Source)->Buffer, \
        (unsigned int)((UpperIndex)-(LowerIndex))); \
    *(unsigned long __RPC_FAR *)&(Source)->Buffer += ((UpperIndex)-(LowerIndex)); \
    }
#define small_array_from_ndr(Source, LowerIndex, UpperIndex, Target) \
    { \
    NDRcopy ( \
        (((char __RPC_FAR *)(Target))+(LowerIndex)), \
        (Source)->Buffer, \
        (unsigned int)((UpperIndex)-(LowerIndex))); \
    *(unsigned long __RPC_FAR *)&(Source)->Buffer += ((UpperIndex)-(LowerIndex)); \
    }

// admin\wmi\wbem\shell\atlui\wmicntl\chklist.h
#define CLM_GETITEMCOUNT    (WM_USER + 3)   // no parameters

// admin\wmi\wbem\tools\locstudioparser\inc\locutil\flddefhelp.h
#define STRING_LIST_COLUMN_ENTRY(name, nID, IDSName, IDSHelp, ops, fDisplay, fSort, fReadOnly, pfnValidateFunc, IDSList) \
	{ { name, nID, IDSName, IDSHelp, CColumnVal::cvtStringList, ops, fDisplay, fSort, fReadOnly, pfnValidateFunc }, IDSList}

// admin\wmi\wbem\tools\locstudioparser\inc\mit\mitutil\macros.h
#define COUNTOF(x) (sizeof(x)/sizeof(*x))

// admin\wmi\wbem\tools\locstudioparser\inc\mit\mitutil\uiopthelp.h
#define LOC_UI_OPTIONS_BOOL_ENTRY(name, def, et, id, idHelp, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, def, et}
#define LOC_UI_OPTIONS_PICK_ENTRY(name, def, add, list, id, idHelp, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, def, add, list}
#define LOC_UI_OPTIONS_STR_ENTRY(name, def, et, id, idHelp, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, def, et}
#define LOC_UI_OPTIONS_STRLIST_ENTRY(name, def, id, idHelp, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, def}
#define LOC_UI_OPTIONS_FILENAME_ENTRY(name, def, id, idHelp, idExt, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, idExt, def}

// admin\wmi\wbem\winmgmt\esscomp\noncom\ncobjapi\connection.cpp
#define COUNTOF(x)  (sizeof(x)/sizeof(x[0]))

// admin\wmi\wbem\winmgmt\esscomp\noncom\ncprov\eventinfo.cpp
#define COUNTOF(x)  (sizeof(x)/sizeof(x[0]))

// admin\wmi\wbem\winmgmt\esscomp\noncom\ncprov\ncprovider.cpp
#define COUNTOF(x)  (sizeof(x)/sizeof(x[0]))

// admin\wmi\wbem\winmgmt\esscomp\noncom\ncprov\provinfo.cpp
#define COUNTOF(x)  (sizeof(x)/sizeof(x[0]))

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\ncetest\events.cpp
#define COUNTOF(x)  (sizeof(x)/sizeof(x[0]))
#define NUM_PROPS  (sizeof(pTypes)/sizeof(pTypes[0]))

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\noncomtest\include\__safearraywrapper.h
#define	SAFEARRAY_TO_LPWSTRARRAY( psa, pppsz, pdwsz )\
__SafeArray::ConvertSafeArrayToLPWSTRArray( psa, pppsz, pdwsz )
#define	LPWSTRARRAY_TO_SAFEARRAY( ppsz, dwsz, ppsa )\
__SafeArray::ConvertLPWSTRArrayToSafeArray( ppsz, dwsz, ppsa )

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\normal\events.cpp
#define COUNTOF(x)  (sizeof(x)/sizeof(x[0]))
#define NUM_PROPS  (sizeof(pTypes)/sizeof(pTypes[0]))

// admin\wmi\wbem\winmgmt\esscomp\vsa\vsaprov\precomp.h
#define COUNTOF(x)  (sizeof(x)/sizeof(x[0]))

// admin\wmi\wbem\winmgmt\esscomp\vsa\vsaprov\vsaevent.cpp
#define NUM_STANDARD_PARAMS (sizeof(typesStandardParams)/sizeof(typesStandardParams[0]))

// admin\wmi\wbem\winmgmt\mofcomp_dll\moflex.cpp
#define NUM_SINGLE_TOKENS   (sizeof(SingleTokenMap)/sizeof(SingleTok))

// admin\wmi\wbem\winmgmt\winmgmt2\list_entry.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// admin\wmi\wbem\winmgmt\wmitest\toolbarex.cpp
#define _countof(x) (sizeof(x)/sizeof(x[0]))

// admin\wmi\wbem\xmltransport\soap\server\msxml3\inc\msxml2.h
#define IXMLDOMDocument_getElementsByTagName(This,tagName,resultList)	\
    (This)->lpVtbl -> getElementsByTagName(This,tagName,resultList)
#define IXMLDOMDocument2_getElementsByTagName(This,tagName,resultList)	\
    (This)->lpVtbl -> getElementsByTagName(This,tagName,resultList)
#define IXMLDOMElement_getElementsByTagName(This,tagName,resultList)	\
    (This)->lpVtbl -> getElementsByTagName(This,tagName,resultList)

// base\efiutil\sdk\inc\efifs.h
#define EFI_LBAL_ARRAY_SIZE(lbal,offs,blks)  \
        (((blks) - (offs) - (lbal)->Hdr.HeaderSize) / sizeof(EFI_RL))

// base\fs\rdr2\csc\inc\timelog.h
#define BEGIN_TIMING(indx)  {LARGE_INTEGER   llTimeBegin;\
                             KeQuerySystemTime(&llTimeBegin);\
                             rgllTimeArray[TIMELOG_##indx] -= llTimeBegin.QuadPart;}
#define END_TIMING(indx)    {LARGE_INTEGER   llTimeEnd;\
                             KeQuerySystemTime(&llTimeEnd);\
                             rgllTimeArray[TIMELOG_##indx] += llTimeEnd.QuadPart;}

// base\ntsetup\oobe\msobweb\wmp.h
#define IWMPPlaylistArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IWMPPlaylistArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IWMPPlaylistArray_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IWMPPlaylistArray_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IWMPPlaylistArray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IWMPPlaylistArray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IWMPPlaylistArray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IWMPPlaylistArray_get_count(This,plCount)	\
    (This)->lpVtbl -> get_count(This,plCount)
#define IWMPPlaylistArray_item(This,lIndex,ppItem)	\
    (This)->lpVtbl -> item(This,lIndex,ppItem)
#define IWMPPlaylistCollection_getAll(This,ppPlaylistArray)	\
    (This)->lpVtbl -> getAll(This,ppPlaylistArray)
#define IWMPPlaylistCollection_getByName(This,bstrName,ppPlaylistArray)	\
    (This)->lpVtbl -> getByName(This,bstrName,ppPlaylistArray)

// com\mobile\sens\conn\senscfg\sensinfo.hxx
#define SENS_PUBLISHER_EVENTCLASS_COUNT (sizeof(gSensEventClasses)/sizeof(PUBLISHER_EVENTCLASS))
#define SENS_SUBSCRIPTIONS_COUNT    (sizeof(gSensSubscriptions)/sizeof(SENS_SUBSCRIPTION))

// com\mobile\sens\conn\senssink\senssink.hxx
#define TEST_SUBSCRIBERS_COUNT    (sizeof(gTestSubscribers)/sizeof(TEST_SUBSCRIBER))
#define TEST_SUBSCRIPTIONS_COUNT    (sizeof(gTestSubscriptions)/sizeof(TEST_SUBSCRIPTION))

// com\mobile\sens\conn\senssvc\sensutil.hxx
#define END_VALIDATE ; \
    if (ValidateError(_myTempValueToValidate,\
                      sizeof(_myValidateArray)/sizeof(int), \
                      _myValidateArray) == 0) ASSERT(0);}

// com\mobile\syncmgr\h\util.hxx
#define ARRAY_ELEMENT_SIZE(_a) (sizeof(_a[0]))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\core\stock.h
#define ARRAY_ELEMENTS(rg)                (sizeof(rg) / sizeof((rg)[0]))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\comm.h
#define GAllocArray(type, cNum)          (type *)GAlloc(sizeof(type) * (cNum))
#define GReAllocArray(type, pb, cNum)    (type *)GReAlloc(pb, sizeof(type) * (cNum))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\comctrlp.h
#define BL_GETCOUNT             (WM_USER+4)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\trayp.h
#define TM_SYSMENUCOUNT         (WM_USER+0x105)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\mem.h
#define SharedAllocArray(type, cNum)    (type _huge *)SharedAlloc(sizeof(type) * (cNum))
#define SharedReAllocArray(type, pb, cNum) (type _huge *)SharedReAlloc(pb, sizeof(type) * (cNum))

// com\ole32\com\class\compapi.cxx
#define ulClassKeyLen     ((sizeof(wszClassKey)/sizeof(WCHAR))-1)

// com\ole32\com\objact\dllcache.hxx
#define OLE32_CHAR_LEN (sizeof(OLE32_DLL) / sizeof(WCHAR) - 1)
#define STACK_ALLOCATE_LSVRCLASSENTRY_FINISHOBJECT()  new (alloca(sizeof(CClassCache::CLSvrClassEntry::CFinishObject))) CClassCache::CLSvrClassEntry::CFinishObject
#define STACK_ALLOCATE_DLLPATHENTRY_FINISHOBJECT()  new (alloca(sizeof(CClassCache::CDllPathEntry::CFinishObject))) CClassCache::CDllPathEntry::CFinishObject

// com\ole32\com\rot\access.hxx
#define DACE_BUFFER_LENGTH      (100 + sizeof(ACCESS_ALLOWED_ACE))

// com\ole32\com\txf\callframe\oautil.cpp
#define PVTELEM(psa)                (&SAFEARRAY_INTERNAL::From(psa)->vt)
#define PPIRIELEM(psa)              (&SAFEARRAY_INTERNAL::From(psa)->piri)

// com\ole32\common\olescm.cxx
#define OLE32_CHAR_LEN (sizeof(OLE32_DLL) / sizeof(WCHAR) - 1)

// com\ole32\dcomss\dcomtest\umisc.cxx
#define PROTSEQ_IDS (sizeof(Mappings)/sizeof(PROTSEQ_MAPPING) - 1)

// com\ole32\dcomss\objex\shrmem\dcom95\epts.c
#define PROTSEQ_IDS (sizeof(gaProtseqInfo)/sizeof(PROTSEQ_INFO))

// com\ole32\dcomss\wrapper\epts.c
#define PROTSEQ_IDS (sizeof(gaProtseqInfo)/sizeof(PROTSEQ_INFO))

// com\ole32\ih\ole2com.h
#define OLE32_CHAR_LEN (sizeof(OLE32_DLL) / sizeof(WCHAR) - 1)
#define OLE2_CHAR_LEN (sizeof(OLE2_DLL) / sizeof(WCHAR) - 1)
#define CLSIDBACK_CHAR_LEN (sizeof(CLSIDBACK) / sizeof(WCHAR) - 1)

// com\ole32\ih\perfmnce.hxx
#define StartPerfCounter(x) \
    QueryPerformanceCounter(&perfrg.rgPerfData[_Perf_##x].liStart);
#define EndPerfCounter(x)   \
    QueryPerformanceCounter(&perfrg.rgPerfData[_Perf_##x].liEnd);

// com\ole32\olecnfg\treemgmt.c
#define MAX_SPECIAL_SUBTREE (sizeof(SpecialSubtrees)/sizeof(LPTSTR))

// com\ole32\olethunk\ole16\inc\windows.h
#define EM_GETLINECOUNT         (WM_USER+10)
#define EM_LINELENGTH	        (WM_USER+17)
#define LB_GETCOUNT	       (WM_USER+12)
#define LB_GETSELCOUNT	       (WM_USER+17)
#define CB_GETCOUNT	         (WM_USER+6)

// com\ole32\olethunk\olethk32\thoputil.cxx
#define NMAPPINGS (sizeof(hmMappings)/sizeof(hmMappings[0]))

// com\ole32\olethunk\thc\thc\gen.c
#define TO_THOPS (sizeof(to_thops)/sizeof(to_thops[0]))
#define NNOT_THUNKED (sizeof(names_not_thunked)/sizeof(names_not_thunked[0]))
#define ARG_TYPE_CONVS (sizeof(arg_type_conv)/sizeof(arg_type_conv[0]))

// com\ole32\olethunk\thc\thc\special.c
#define SPECIAL_CASES (sizeof(special_cases)/sizeof(special_cases[0]))

// com\ole32\olethunk\thc\thc\type.c
#define EXTENDED_TYPES (sizeof(extended_types)/sizeof(extended_types[0]))

// com\ole32\stg\async\layout\test\tutils.cxx
#define NSCODETEXT (sizeof(scodes)/sizeof(scodes[0]))

// com\ole32\stg\drt\drt.cxx
#define NTESTS (sizeof(tests)/sizeof(tests[0]))

// com\ole32\stg\drt\util.cxx
#define NSCODETEXT (sizeof(scodes)/sizeof(scodes[0]))

// com\ole32\stg\h\dfmsp.hxx
#define DESTROY_ENTRY           (DESTROY_FROM_ENTRY | DESTROY_SELF)

// com\ole32\stg\props\hntfsstg.hxx
#define ELEMENTS(x) (sizeof(x)/sizeof(x[0]))

// com\ole32\stg\props\propstm.cxx
#define CCHUNKSTACK     (sizeof(ascnkStack)/sizeof(ascnkStack[0]))

// com\ole32\stg\props\utest\propdump.cxx
#define CPROPSTATIC      (sizeof(aspsStatic)/sizeof(aspsStatic[0]))

// com\ole32\stg\props\utest\proptest.hxx
#define ELEMENTS(x) (sizeof(x)/sizeof(x[0]))

// com\ole32\stg\ref\h\dfmsp.hxx
#define DESTROY_ENTRY           (DESTROY_FROM_ENTRY | DESTROY_SELF)

// com\ole32\stg\ref\props\propstm.cxx
#define CCHUNKSTACK     (sizeof(ascnkStack)/sizeof(ascnkStack[0]))

// com\ole32\stg\ref\test\proptest\proptest.cxx
#define CPROPSTATIC      (sizeof(aspsStatic)/sizeof(aspsStatic[0]))

// com\ole32\stg\ref\test\stgdrt\drt.cxx
#define NTESTS (sizeof(tests)/sizeof(tests[0]))

// com\ole32\stg\ref\test\stgdrt\util.cxx
#define NSCODETEXT (sizeof(scodes)/sizeof(scodes[0]))

// com\oleutest\balls\common\ctext.hxx
#define SYS_DIR_STR_LEN (sizeof(SYS_DIR_STR) / sizeof(TCHAR) - 1)

// com\oleutest\letest\ole2ui\dballoc.cpp
#define DIM(X) (sizeof(X)/sizeof((X)[0]))

// com\oleutest\letest\outline\message.h
#define NUM_STATS   sizeof(MesgList)/sizeof(MesgList[0])

// com\oleutest\stgdrt\drt.cxx
#define NTESTS (sizeof(tests)/sizeof(tests[0]))

// com\oleutest\stgdrt\util.cxx
#define NSCODETEXT (sizeof(scodes)/sizeof(scodes[0]))

// com\rpc\midl\codegen\arraycls.hxx
#define DECLARE_COMPLEX_ARRAY_CG_CLASS( NEWTYPE, BASETYPE )                       \
class NEWTYPE : public BASETYPE                                                   \
{                                                                                 \
protected:                                                                        \
    NEWTYPE( const NEWTYPE & Node ) :                                             \
        BASETYPE( Node ) {}                                                       \
public:                                                                           \
    NEWTYPE( node_skl *pType,                                                     \
             FIELD_ATTR_INFO * pFA,                                               \
             unsigned short dim,                                                  \
             XLAT_SIZE_INFO & Info ) :                                            \
        BASETYPE( pType,                                                          \
                  pFA,                                                            \
                  dim,                                                            \
                  Info )                                                          \
    {                                                                             \
        ForceComplex();                                                           \
    }                                                                             \
    virtual CG_CLASS* Clone()             { return new NEWTYPE(*this); }          \
    virtual void Visit( CG_VISITOR *pVisitor ) { pVisitor->Visit( this ); }       \
};                                                                                \

// com\rpc\ndrexts\ndrexts\format.cxx
#define PRINT_ARRAY_TYPE(type,ts2,ts4,ne2,ne4,esize,cd,vd)       \
void FORMAT_PRINTER::HANDLE_##type() {                      \
    PrintArray(ts2,ts4,ne2,ne4,esize,cd,vd);                     \
}

// com\rpc\runtime\mtrt\sysinc.h
#define END_VALIDATE ; \
    if (ValidateError(_myTempValueToValidate,\
                      sizeof(_myValidateArray)/sizeof(int), \
                      _myValidateArray) == 0) ASSERT(0);}

// com\svcdlls\trksvcs\common\trklib.hxx
#define ELEMENTS(x) (sizeof(x)/sizeof(x[0]))

// com\svcdlls\trksvcs\trkwks\trkwks.hxx
#define CVOLUME_HEADER_LENGTH       sizeof(VolumePersistentInfo)

// drivers\input\mouser\cseries.c
#define sizeofel(x) (sizeof(x)/sizeof(*x))

// drivers\input\sermouse\cseries.c
#define sizeofel(x) (sizeof(x)/sizeof(*x))

// drivers\input\upgrade\upgrade.c
#define NUM_DRIVER_DATA (sizeof(DriverData) / sizeof(INPUT_DRIVER_DATA))

// drivers\ksfilter\inc\portcls.h
#define PROPERTY_SUBTABLE(SetId,SubTable)       \
    {                                           \
        (SetId),                                \
        NULL,                                   \
        sizeof(SubTable)/sizeof((SubTable)[0]), \
        (SubTable)                              \
    }

// drivers\ksfilter\ks\event.c
#define REMOVE_ENTRY(EventEntryEx)\
    if ((EventEntryEx)->RemoveHandler) {\
        (EventEntryEx)->RemoveHandler((EventEntryEx)->EventEntry.FileObject, &EventEntryEx->EventEntry);\
    } else {\
        RemoveEntryList(&(EventEntryEx)->EventEntry.ListEntry);\
    }

// drivers\ksfilter\ks\shpin.cpp
#define IRPLIST_ENTRY_IRP_STORAGE(Irp) \
    PIRPLIST_ENTRY(&IoGetCurrentIrpStackLocation(Irp)->Parameters)

// drivers\ksfilter\tests\irqperf\sys\private.h
    #define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))

// drivers\net\irda\mknet\sys\winreg.c
#define NUM_REG_PARAM ( sizeof (MK7RegTab) / sizeof (MK7RegTabType) )

// drivers\net\ms\e100bex\mp_def.h
#define NIC_MAP_IOSPACE_LENGTH          sizeof(CSR_STRUC)

// drivers\net\ms\e100bex\mp_init.c
#define NIC_NUM_REG_PARAMS (sizeof (NICRegTable) / sizeof(MP_REG_ENTRY))

// drivers\net\ms\ne2000\ne2000hw.h
#define CardUpdateCounters(Adapter) \
    NdisMSynchronizeWithInterrupt(&(Adapter)->Interrupt, \
                SyncCardUpdateCounters, (PVOID)(Adapter))

// drivers\serial\mps\comtrol\rocket\driver\init.h
#define SERIAL_REFERENCE_COUNT(Irp) \
    ((LONG)((IoGetCurrentIrpStackLocation((Irp))->Parameters.Others.Argument4)))

// drivers\serial\mps\comtrol\rocket\setup\devprop.c
#define NORM_COUNTER(calc,curr,prev,last) \
{ \
  if ((curr) > (prev)) \
    calc = (last) + ((curr) - (prev)); \
  else \
    calc = (last); \
}

// drivers\serial\mps\moxa\intellio\driver\mxport\moxa.h
#define MOXA_REFERENCE_COUNT(Irp) \
    ((LONG)((IoGetCurrentIrpStackLocation((Irp))->Parameters.Others.Argument4)))

// drivers\serial\mps\spx\mps\io8\incl\serialp.h
#define SERIAL_REFERENCE_COUNT(Irp) \
    ((LONG)((IoGetCurrentIrpStackLocation((Irp))->Parameters.Others.Argument4)))

// drivers\serial\mps\spx\mps\io8\io8_nt.c
#define	MAXKNOWNFREQUENCIES	(sizeof(KnownFrequencies)/sizeof(ULONG))

// drivers\serial\mps\spx\mps\io8\spx_wmi.c
#define SpxPort_WmiGuidCount (sizeof(SpxPort_WmiGuidList) / sizeof(WMIGUIDREGINFO))

// drivers\serial\mps\spx\mps\sx\inc\serialp.h
#define SERIAL_REFERENCE_COUNT(Irp) \
    ((LONG)((IoGetCurrentIrpStackLocation((Irp))->Parameters.Others.Argument4)))

// drivers\serial\mps\spx\mps\sx\spx_wmi.c
#define SpxPort_WmiGuidCount (sizeof(SpxPort_WmiGuidList) / sizeof(WMIGUIDREGINFO))

// drivers\serial\mps\spx\speed\driver\inc\serialp.h
#define SERIAL_REFERENCE_COUNT(Irp) \
    ((LONG)((IoGetCurrentIrpStackLocation((Irp))->Parameters.Others.Argument4)))

// drivers\serial\mps\spx\speed\driver\spd_cwmi.c
#define SpeedCard_WmiGuidCount (sizeof(SpeedCard_WmiGuidList) / sizeof(WMIGUIDREGINFO))

// drivers\serial\mps\spx\speed\driver\spd_wmi.c
#define SpeedPort_WmiGuidCount (sizeof(SpeedPort_WmiGuidList) / sizeof(WMIGUIDREGINFO))

// drivers\serial\mps\spx\speed\driver\spx_wmi.c
#define SpxPort_WmiGuidCount (sizeof(SpxPort_WmiGuidList) / sizeof(WMIGUIDREGINFO))

// drivers\smartcrd\gempc430\syswdm.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// drivers\smartcrd\smclib\smcioctl.c
#define DIM(_array_) (sizeof(_array_) / sizeof(_array_[0]))

// drivers\storage\diskperf\diskperf.c
#define DiskperfGuidCount (sizeof(DiskperfGuidList) / sizeof(WMIGUIDREGINFO))

// drivers\storage\fdc\fdc\fdc_data.h
#define FDC_FLOPPY_HARDWARE_IDS_LENGTH       26 * sizeof(WCHAR)
#define FDC_TAPE_HARDWARE_IDS_LENGTH         13 * sizeof(WCHAR)
#define FDC_TAPE_GENERIC_HARDWARE_IDS_LENGTH 15 * sizeof(WCHAR)
#define FDC_CONTROLLER_HARDWARE_IDS_LENGTH   18 * sizeof(WCHAR)
#define FDC_FLOPPY_COMPATIBLE_IDS_LENGTH     15 * sizeof(WCHAR)
#define FDC_TAPE_COMPATIBLE_IDS_LENGTH       8 * sizeof(WCHAR)
#define FDC_CONTROLLER_COMPATIBLE_IDS_LENGTH 10 * sizeof(WCHAR)

// drivers\storage\ide\atapi\atapinit.c
#define NUMBER_OF_SPECIAL_WD_DEVICES (sizeof(SpecialWDDevicesFWVersion) / (sizeof (UCHAR) * 9))

// drivers\storage\ide\atapi\chanfdo.c
#define NUM_PROMISE_TECH_ID     (sizeof(PromiseTechDeviceId)/sizeof(PCWSTR))

// drivers\storage\ide\miniport\pciide\init.c
#define NUMBER_OF_SINGLE_FIFO_CONTROLLER (sizeof(SingleFifoController) / sizeof(VENDOR_ID_DEVICE_ID))

// drivers\storage\iscsiprt\client\port.h
#define countof(x) (sizeof(x) / sizeof((x)[0]))
#define TDI_QUERY_ADDRESS_LENGTH_IP (sizeof(TDI_ADDRESS_INFO) - 1 \
                                     + TDI_ADDRESS_LENGTH_IP)
#define TDI_IP_ADDRESS_LENGTH        (sizeof (TRANSPORT_ADDRESS) - 1 + \
                                      TDI_ADDRESS_LENGTH_IP)

// drivers\storage\iscsiprt\server\port.h
#define countof(x) (sizeof(x) / sizeof((x)[0]))
#define TDI_QUERY_ADDRESS_LENGTH_IP (sizeof(TDI_ADDRESS_INFO) - 1 \
                                     + TDI_ADDRESS_LENGTH_IP)
#define TDI_IP_ADDRESS_LENGTH        (sizeof (TRANSPORT_ADDRESS) - 1 + \
                                      TDI_ADDRESS_LENGTH_IP)

// drivers\storage\mpath\control\mpio.h
#define MPIO_STRING_LENGTH (sizeof(WCHAR)*63)

// drivers\storage\mpath\control\mpiowmi.c
#define MPIO_GUID_COUNT (sizeof(MPIOWmiGuidList) / sizeof(WMIGUIDREGINFO))
#define PdowmiGuidCount (sizeof(PdowmiGuidList) / sizeof(WMIGUIDREGINFO))

// drivers\storage\mpath\control\wmi.c
#define MPathGuidCount (sizeof(MPathWmiGuidList) / sizeof(WMIGUIDREGINFO))

// drivers\storage\mpath\control\wmi.h
    #define MPIO_EventEntry_TimeStamp_SIZE sizeof(ULONGLONG)
    #define MPIO_EventEntry_Severity_SIZE sizeof(ULONG)

// drivers\storage\mpath\dsm\gendsm.c
#define DsmGuidCount (sizeof(DsmGuidList) / sizeof(WMIGUIDREGINFO))

// drivers\storage\port\raid\inc\sldefs.h
#define ARRAY_COUNT(Array) (sizeof(Array)/sizeof(Array[0]))

// drivers\storage\port\raid\port\util.h
#define SCSI_BUS_NAME_LENGTH			(sizeof ("SCSI"))
#define MAX_DEVICE_NAME_LENGTH			(sizeof ("Sequential"))
#define MAX_GENERIC_DEVICE_NAME_LENGTH	(sizeof ("ScsiCardReader"))
#define DEVICE_ID_LENGTH			(HARDWARE_B_D_V_P_R_LENGTH +			\
									 sizeof ("&Ven_") +						\
									 sizeof ("&Prod_") +					\
									 sizeof ("&Rev_"))
#define COMPATIBLE_ID_LENGTH		(SCSI_BUS_NAME_LENGTH +					\
									 MAX_DEVICE_NAME_LENGTH +				\
									 1 +									\
									 sizeof ("SCSI\\RAW") +					\
									 1 +									\
									 1)										\

// drivers\storage\port\scsi\miniport\agilent\afc\mapping.h
#define	DEV_ARRAY_SIZE		(sizeof(DEVICE_ARRAY))

// drivers\storage\port\scsi\miniport\agilent\afc\queue.h
#define fiListInitElement(hdr)                                                \
          {                                                                   \
            ((fiList_t *)(hdr))->flink = fiListInitElementFlinkBlinkSentinel; \
            ((fiList_t *)(hdr))->blink = fiListInitElementFlinkBlinkSentinel; \
          }
#define fiListInitElement(hdr)                             \
          {                                                \
            ((fiList_t *)(hdr))->flink = (fiList_t *)agNULL; \
            ((fiList_t *)(hdr))->blink = (fiList_t *)agNULL; \
          }

// drivers\storage\port\scsi\miniport\aha154x\wmi.c
#define A154xGuidCount (sizeof(A154xGuidList) / sizeof(SCSIWMIGUIDREGINFO))

// drivers\storage\port\scsi\miniport\aha154x\wmitest\aha154dc.c
#define TestCount ( sizeof(TestList) / sizeof(TestList[0]) )

// drivers\storage\port\scsi\miniport\atapi\atapi.c
#define NUMBER_OF_PCI_CONTROLLER (sizeof(PciControllerParameters) / sizeof(CONTROLLER_PARAMETERS))
#define NUMBER_OF_PIO_DEVICES (sizeof(PioDeviceModelNumber) / (sizeof(UCHAR) * 41))
#define NUMBER_OF_SPECIAL_WD_DEVICES (sizeof(SpecialWDDevicesFWVersion) / (sizeof (UCHAR) * 9))

// drivers\storage\port\scsi\miniport\hbaapi_sample\wmi.c
#define HbaapiGuidCount (sizeof(HbaapiGuidList) / sizeof(SCSIWMIGUIDREGINFO))

// drivers\storage\port\scsi\miniport\hipoint\hpt3xx\winnt\devtree.c
#define MAKE_ARRAY_ID(pArray)			(HDISK)(0x80000000|GET_ARRAY_NUM(pArray))
#define MAKE_COMPOSED_ARRAY_ID(pArray)	(HDISK)(0x80000100|GET_ARRAY_NUM(pArray))

// drivers\storage\port\scsi\miniport\hipoint\hpt3xx\winnt\forwin.h
#define ARG_ARRAY_BLK	, (PUSHORT)&ArrayBlk

// drivers\storage\port\scsi\miniport\hipoint\hpt3xx\winnt\hptchip.c
#define MAX_BAD_DISKS (sizeof(bad_disks)/sizeof(BadModeList))

// drivers\storage\port\scsi\miniport\ibm\cbidf\atapi.h
#define BROKEN_ADAPTERS (sizeof(BrokenAdapters) / sizeof(BROKEN_CONTROLLER_INFORMATION))
#define NUM_NATIVE_MODE_ADAPTERS (sizeof(NativeModeAdapters) / sizeof(NATIVE_MODE_CONTROLLER_INFORMATION))

// drivers\storage\port\scsi\miniport\megaide\hyperdisk.h
#define NUM_NATIVE_MODE_ADAPTERS (sizeof(CMDAdapters) / sizeof(CMD_CONTROLLER_INFORMATION))

// drivers\storage\rsm2\service\dll\internal.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// drivers\storage\sfloppy\floppy.c
#define NUMBER_OF_DRIVE_MEDIA_COMBINATIONS sizeof(DriveMediaConstants)/sizeof(DRIVE_MEDIA_CONSTANTS)
#define FLOPPY_CAPACITIES (sizeof(FloppyCapacities)/sizeof(FloppyCapacities[0]))

// drivers\storage\tffsport\dosformt.h
#define DIRECTORY_ENTRY_SIZE	sizeof(DirectoryEntry)

// drivers\storage\tffsport\inftl.c
#define countOf(unitNo)      (vol.physicalUnits[unitNo] & UNIT_COUNT)
#define setUnitCount(unitNo,unitCount) { vol.physicalUnits[unitNo] &= ~UNIT_COUNT; vol.physicalUnits[unitNo] |= (ANANDPhysUnit)unitCount; }

// drivers\storage\tffsport\nftllite.h
#define countOf(unitNo)     (vol.physicalUnits[unitNo] & UNIT_COUNT)
#define setUnitCount(unitNo,unitCount) { vol.physicalUnits[unitNo] &= ~UNIT_COUNT; vol.physicalUnits[unitNo] |= (ANANDPhysUnit)unitCount; }

// drivers\storage\volsnap\vss\inc\vs_vol.hxx
#define ARRAY_LEN(A) (sizeof(A)/sizeof((A)[0]))

// drivers\storage\volsnap\vss\server\inc\vs_vol.hxx
#define ARRAY_LEN(A) (sizeof(A)/sizeof((A)[0]))

// drivers\storage\volsnap\vss\tests\snapcp\snapcp.cpp
#define SIZEOF_ARRAY(_arrayname)		(sizeof (_arrayname) / sizeof ((_arrayname)[0]))

// drivers\tpg\hwx\bear\src\breaks.cpp
#define IsBegEndElement(pEl) (Is_IU_or_ID(pEl) || IsAnyArcWithTail(pEl))

// drivers\tpg\hwx\bear\src\convert.cpp
  #define  NMARKS (sizeof(mark_name)/sizeof(*mark_name))

// drivers\tpg\hwx\bear\src\links.cpp
#define ELEMENT_WITH_DIRECTION(pEl) ((pEl)->code==_GU_  || (pEl)->code==_GD_  || \
                                     (pEl)->code==_UU_  || (pEl)->code==_UD_  || \
                                     (pEl)->code==_UUC_ || (pEl)->code==_UDC_ || \
                                     Is_IU_or_ID(pEl) && (pEl)->mark==CROSS   || \
                                     IsAnyArcWithTail(pEl)                       \
                                    )

// drivers\tpg\hwx\bear\src\lk_next.cpp
#define IsArcCounterClockWise(pEl) (((pEl)->code==_UD_  ||    \
                                     (pEl)->code==_UDC_ ||    \
                                     (pEl)->code==_UDL_ ||    \
                                     (pEl)->code==_UDR_       \
                                    )                     &&  \
                                    COUNTERCLOCKWISE(pEl)     \
                                   )

// drivers\tpg\hwx\commonu\src\bigram.c
#define	cALCGroupings	(sizeof(aALCGroupings) / sizeof(aALCGroupings[0]))

// drivers\tpg\hwx\commonu\src\valid.c
#define VALID_TAB_SIZE (sizeof(aiValid) / sizeof(VALID))
#define NOTSUSP_TAB_SIZE (sizeof(aiNotSusp) / sizeof(VALID))

// drivers\tpg\hwx\twister\grouse\src\grouse_db.c
#define MAX_GROUSE_GESTURES  sizeof(g_awcGrouseGestures) / sizeof(g_awcGrouseGestures[0])

// drivers\tpg\hwx\twister\src\wispapis.c
#define MAX_SUPPORTED_GESTURES  sizeof(g_awcSupportedGestures) / sizeof(g_awcSupportedGestures[0])

// drivers\video\matrox\mga\disp\mcdhw.h
#define MCDCLAMPCOUNT(value) ((ULONG)(value) & 0x00007fff)

// drivers\video\ms\3dlabs\perm2\disp\d3dstate.c
#define ELEMS_IN_ARRAY(a) ((sizeof(a)/sizeof(a[0])))

// drivers\video\ms\3dlabs\perm2\disp\ddsurf.c
#define N_PERMEDIA2PIXELFORMATS \
    (sizeof(Permedia2PixelFormats)/sizeof(DDPIXELFORMAT))

// drivers\video\ms\3dlabs\perm2\disp\p2ctxt.c
#define N_READABLE_TAGSP2 (sizeof(readableRegistersP2) / sizeof(readableRegistersP2[0]))

// drivers\video\ms\3dlabs\perm2\disp\p2rd.h
#define P2RD_READ_CURSOR_ARRAY(data) \
{ \
    data = READ_P2RDREG_ULONG(P2RD_INDEX_DATA) & 0xff; \
}

// drivers\video\ms\3dlabs\perm2\disp\tvp4020.h
#define TVP4020_READ_CURSOR_ARRAY(data) \
{ \
    data = READ_4020REG_ULONG(__TVP4020_CUR_RAM_DATA) & 0xff; \
}

// drivers\video\ms\3dlabs\perm2\mini\p2rd.h
#define P2RD_READ_CURSOR_ARRAY(data) \
{ \
    data = VideoPortReadRegisterUlong(P2RD_INDEX_DATA) & 0xff; \
    P2RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm2\mini\permdata.c
#define P2DepthCnt (sizeof(P2DepthList) / sizeof(P2DepthList[0]))
#define VESA_CNT (sizeof(VESA_LIST) / sizeof(VESA_LIST [0]))
#define VESA_CNT_P2S (sizeof(VESA_LIST_P2S) / sizeof(VESA_LIST_P2S [0]))

// drivers\video\ms\3dlabs\perm2\mini\tvp4020.h
#define TVP4020_READ_CURSOR_ARRAY(data) \
{ \
    data = VideoPortReadRegisterUlong(__TVP4020_CUR_RAM_DATA) & 0xff; \
    TVP4020_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\dx\d3d.c
#define DX8_FORMAT_COUNT (sizeof(DX8FormatTable) / sizeof(DX8FormatTable[0]))

// drivers\video\ms\3dlabs\perm3\disp\dx\d3ddp2p3.c
#define NUM_LOCAL_STATES ( sizeof( localState ) / sizeof( D3DSTATE ))

// drivers\video\ms\3dlabs\perm3\disp\dx\d3dsset.c
#define ELEMS_IN_ARRAY(a) ((sizeof(a)/sizeof(a[0])))

// drivers\video\ms\3dlabs\perm3\disp\gdi\glint.h
#define WAIT_OUTPUT_FIFO_COUNT(n) \
{ \
    int i; \
    do \
    { \
       OUTPUT_FIFO_COUNT(i); \
    } \
    while(i < (int)n); \
}
#define LOCALBUFFER_PIXEL_COUNT     (glintInfo->ZBufferSize)

// drivers\video\ms\3dlabs\perm3\disp\gdi\p3rd.h
#define P3RD_READ_CURSOR_ARRAY(data) \
{ \
    data = READ_P3RDREG_ULONG(P3RD_INDEX_DATA) & 0xff; \
    P3RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\inc\p2rd.h
#define P2RD_READ_CURSOR_ARRAY(data) \
{ \
    data = VideoPortReadRegisterUlong(P2RD_INDEX_DATA) & 0xff; \
    P2RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\inc\p3rd.h
#define P3RD_READ_CURSOR_ARRAY(data) \
{ \
    data = VideoPortReadRegisterUlong(P3RD_INDEX_DATA) & 0xff; \
    P3RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\inc\rgb525.h
#define RGB525_LOAD_CURSOR_ARRAY(data) \
{ \
    VideoPortWriteRegisterUlong(RGB525_INDEX_DATA, (ULONG)(data)); \
    RGB525_DELAY; \
}
#define RGB525_READ_CURSOR_ARRAY(data) \
{ \
    data = VideoPortReadRegisterUlong(RGB525_INDEX_DATA) & 0xff; \
    RGB525_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\inc\rgb640.h
#define RGB640_LOAD_CURSOR_ARRAY(data) \
{ \
    WRITE_640REG_ULONG(RGB640_INDEX_DATA, (ULONG)(data)); \
    RGB640_DELAY; \
}
#define RGB640_READ_CURSOR_ARRAY(data) \
{ \
    data = (UCHAR)(READ_640REG_ULONG (RGB640_INDEX_DATA) & 0xff); \
    RGB640_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\inc\tvp3026.h
#define TVP3026_READ_CURSOR_ARRAY(data) \
{ \
    data = VideoPortReadRegisterUlong(__TVP3026_CUR_RAM_DATA) & 0xff; \
    TVP3026_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\inc\tvp4020.h
#define TVP4020_READ_CURSOR_ARRAY(data) \
{ \
    data = VideoPortReadRegisterUlong(__TVP4020_CUR_RAM_DATA) & 0xff; \
    TVP4020_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\mini\p3rd.h
#define P3RD_READ_CURSOR_ARRAY(data) \
{ \
    data = VideoPortReadRegisterUlong(P3RD_INDEX_DATA) & 0xff; \
    P3RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\mini\perm3dat.c
#define Perm3DepthCnt (sizeof(Perm3DepthList) / sizeof(Perm3DepthList[0]))
#define VESA_COUNT      (sizeof(VESA_LIST) / sizeof(VESA_LIST[0]))
#define SGIDFP_COUNT   (sizeof(SGIDFP_LIST) / sizeof(SGIDFP_LIST[0]))

// drivers\video\ms\laguna\disp\cl5465\mcdhw.h
#define MCDCLAMPCOUNT(value) ((ULONG)(value) & 0x00007fff)

// drivers\video\ms\port\videoprt.c
#define GetIoQueryDeviceInfoLength(DeviceInfo, InfoType)             \
    ((*(DeviceInfo + InfoType))->DataLength)

// drivers\video\ms\weitek\mini\ibm525.h
#define RGB525_CURSOR_ARRAY             (0x100) // Referenced

// drivers\wdm\audio\backpln\portcls\ports\dmus\pin.cpp
#define IRPLIST_ENTRY_IRP_STORAGE(Irp) \
    PIRPLIST_ENTRY(&IoGetCurrentIrpStackLocation(Irp)->Parameters)

// drivers\wdm\audio\backpln\portcls\ports\midi\pin.cpp
#define IRPLIST_ENTRY_IRP_STORAGE(Irp) \
    PIRPLIST_ENTRY(&IoGetCurrentIrpStackLocation(Irp)->Parameters)

// drivers\wdm\audio\backpln\portcls\ports\wavecyc\pin.cpp
#define IRPLIST_ENTRY_IRP_STORAGE(Irp) \
    PIRPLIST_ENTRY(&IoGetCurrentIrpStackLocation(Irp)->Parameters)

// drivers\wdm\audio\backpln\portcls\ports\wavepci\pin.cpp
#define IRPLIST_ENTRY_IRP_STORAGE(Irp) \
    PIRPLIST_ENTRY(&IoGetCurrentIrpStackLocation(Irp)->Parameters)

// drivers\wdm\audio\legacy\wdmaud.drv\mixer.c
#define StoreCallback(Type,Id) {\
                                if (gpCallbacks) {\
                                 gpCallbacks->Callbacks[gpCallbacks->GlobalIndex%CALLBACKARRAYSIZE].dwCallbackType = Type;\
                                 gpCallbacks->Callbacks[gpCallbacks->GlobalIndex%CALLBACKARRAYSIZE].dwID = Id;\
                                 gpCallbacks->GlobalIndex++;\
                                }\
                               };

// drivers\wdm\audio\legacy\wdmaud.sys\mixer.h
#define RemoveFirstEntry( list, Type )                                \
            (Type*) (list);                                           \
            {                                                         \
                PSLIST pRFETemp;                                      \
                pRFETemp = (PSLIST) (list);                           \
                if( (list) ) {                                        \
                    (list) = (Type*) (list)->List.Next;               \
                    if( pRFETemp ) {                                  \
                        ((Type*) pRFETemp)->List.Next = NULL;         \
                    }                                                 \
                }                                                     \
            }

// drivers\wdm\audio\sysaudio\fn.h
#define FILTER_TYPE_CAPTURE     (FILTER_TYPE_AEC | \
                         FILTER_TYPE_MIC_ARRAY_PROCESSOR | \
                     FILTER_TYPE_MIXER | \
                     FILTER_TYPE_SPLITTER)
#define FILTER_TYPE_NOT_SELECT      (FILTER_TYPE_AEC | \
                         FILTER_TYPE_MIC_ARRAY_PROCESSOR)

// drivers\wdm\capture\mini\bt848\capstrm.h
#define NUM_STREAM_0_FORMATS (sizeof (Stream0Formats) / sizeof (PKSDATAFORMAT))
#define NUM_STREAM_1_FORMATS (sizeof (Stream1Formats) / sizeof (PKSDATAFORMAT))
#define NUM_VBI_FORMATS (sizeof (VBIStreamFormats) / sizeof (PKSDATAFORMAT))
#define DRIVER_STREAM_COUNT (sizeof (Streams) / sizeof (ALL_STREAM_INFO))

// drivers\wdm\dvd\mini\dxr2\strminfo.h
#define DRIVER_STREAM_COUNT (sizeof (Streams) / sizeof (ALL_STREAM_INFO))

// drivers\wdm\input\client\hclient\ddksrc\list.h
    #define GetNextEntry(ListNode)                      \
        (((PLIST_NODE_HDR) (ListNode)) -> Flink);
    #define GetPrevEntry(ListNode)                      \
        (((PLIST_NODE_HDR) (ListNode)) -> Blink);

// drivers\wdm\input\client\hclient\list.h
    #define GetNextEntry(ListNode)                      \
        (((PLIST_NODE_HDR) (ListNode)) -> Flink);
    #define GetPrevEntry(ListNode)                      \
        (((PLIST_NODE_HDR) (ListNode)) -> Blink);

// drivers\wdm\input\client\hidtest\list.h
    #define GetNextEntry(ListNode)                      \
        (((PLIST_NODE_HDR) (ListNode)) -> Flink);
    #define GetPrevEntry(ListNode)                      \
        (((PLIST_NODE_HDR) (ListNode)) -> Blink);

// drivers\wdm\input\hidir\hidir.h
#define HIDIR_TABLE_ENTRY_SIZE(rl) (sizeof(ULONG) + (((rl)+0x00000003)&(~0x00000003)))

// drivers\wdm\input\hidparse\hidparse.h
#define HIDP_ISARRAY(x)    ((BOOLEAN) ((!((x) & 0x02)) ? TRUE : FALSE))

// drivers\wdm\input\legacy\gameenum\exe\game.h
#define GAME_HARDWARE_IDS_LENGTH sizeof (GAME_HARDWARE_IDS)

// drivers\wdm\input\tabletpc\cpl\battinfo.c
#define NUM_BATT_CMDS   (sizeof(gBattCmds)/sizeof(SMBCMD_INFO))
            #define NUM_MANU_DATA   (sizeof(ManuData)/sizeof(SMBCMD_INFO))

// drivers\wdm\input\tabletpc\cpl\chgrinfo.c
#define NUM_CHGR_CMDS   (sizeof(gChgrCmds)/sizeof(SMBCMD_INFO))

// drivers\wdm\input\tabletpc\cpl\tmpinfo.c
#define NUM_TMP_CMDS   (sizeof(gTmpCmds)/sizeof(SMBCMD_INFO))

// drivers\wdm\input\tabletpc\tabsrv\tabsrv.h
#define RemoveEntryList(e)      {                                       \
                                    (e)->Blink->Flink = (e)->Flink;     \
                                    (e)->Flink->Blink = (e)->Blink;     \
                                }

// drivers\wdm\input\tools\bingen\dll\datatbl.c
#define ALLOC_ENTRY()          (malloc(sizeof(DATA_TABLE_ENTRY)))

// drivers\wdm\rt\exec\rt.c
#define TurnOnPerformanceCounters() \
__asm { \
	__asm test cs:EnablePerfCounters, 0xffffffff	\
	__asm jz noperf									\
	__asm push eax									\
	__asm push edx									\
	__asm push ecx									\
	__asm xor edx, edx								\
	__asm mov ecx, cs:EVENTSELECT0					\
	__asm mov eax, cs:EnablePerfCounters			\
	__asm _emit 0x0f								\
	__asm _emit 0x30								\
	__asm pop ecx									\
	__asm pop edx									\
	__asm pop eax									\
	__asm noperf:									\
	}

// drivers\wdm\usb\driver\i82930\sys\i82930.h
#define INCREMENT_OPEN_COUNT(deviceExtension) \
    InterlockedIncrement(&(((PDEVICE_EXTENSION)(deviceExtension))->OpenCount))
#define DECREMENT_OPEN_COUNT(deviceExtension) do { \
    if (InterlockedDecrement(&(((PDEVICE_EXTENSION)(deviceExtension))->OpenCount)) == 0) { \
        KeSetEvent(&((deviceExtension)->RemoveEvent), \
                   IO_NO_INCREMENT, \
                   0); \
    } \
} while (0)

// drivers\wdm\usb\driver\isoperf\app\main.h
#define GET_CONFIG_DESCRIPTOR_LENGTH(pv) \
    ((pUsb_Configuration_Descriptor)pv)->wTotalLength

// drivers\wdm\usb\driver\sample\app\main.h
#define GET_CONFIG_DESCRIPTOR_LENGTH(pv) \
    ((pUsb_Configuration_Descriptor)pv)->wTotalLength

// drivers\wdm\usb\driver\usbmass\scsi.c
#define FLOPPY_CAPACITIES (sizeof(FloppyCapacities)/sizeof(FloppyCapacities[0]))

// drivers\wdm\usb\driver\usbmass\usbmass.h
#define INCREMENT_PENDING_IO_COUNT(deviceExtension) \
    InterlockedIncrement(&((deviceExtension)->PendingIoCount))
#define DECREMENT_PENDING_IO_COUNT(deviceExtension) do { \
    if (InterlockedDecrement(&((deviceExtension)->PendingIoCount)) == 0) { \
        KeSetEvent(&((deviceExtension)->RemoveEvent), \
                   IO_NO_INCREMENT, \
                   0); \
    } \
} while (0)

// drivers\wdm\usb\driver\usbtest\dll\devnode.c
#define CalculateNodeVariableLength(nh)                                     \
    (  (nh).NodeInfoExists*sizeof(USB_NODE_INFORMATION) +                   \
       (nh).ConnectionInfoExists*sizeof(USB_NODE_CONNECTION_INFORMATION) +  \
       (nh).SymbolicLinkLength +                                            \
       (nh).DescriptionLength  +                                            \
       (nh).ClassNameLength                                                 \
    )

// drivers\wdm\usb\driver\usbtest\sys\usbtest\local.h
#define APPEND_LIST_ELEMENT(list, e) InsertTailList(&((list) -> List), e); \
                                                   ((list) -> ElementCount)++
#define PREPEND_LIST_ELEMENT(list, e) InsertHeadList(&((list) -> List), e); \
                                                     ((list) -> ElementCount)++
#define REMOVE_FIRST_ELEMENT(list)   RemoveHeadList(&((list) -> List)) \
                                     ((list) -> ElementCount)-- \
#define REMOVE_LAST_ELEMENT(list)    RemoveTailList(&((list) -> List)); \
                                     ((list) -> ElementCount)--

// drivers\wdm\usb\driver\usbverfy\sys\urb.c
#define FUNCTION_TO_URB_LENGTH_MAX (sizeof(FunctionToUrbLength) / sizeof(USHORT))

// drivers\wdm\usb\driver\wceusbsh\perf.h
#define PERF_ENTRY(_INDEX)                  \
      LARGE_INTEGER _INDEX##perfStart;         \
      LARGE_INTEGER _INDEX##perfEnd;           \
      RDTSC(_INDEX##perfStart);                \
      InterlockedIncrement( &PerfCounter[_INDEX].Count )

// drivers\wdm\usb\hcd\uhcd\uhcd.h
#define FRAME_LIST_LENGTH   (FRAME_LIST_SIZE * \
                            sizeof(HW_DESCRIPTOR_PHYSICAL_ADDRESS))

// drivers\wdm\usb\hcd\usbport\usbport.h
#define INITIALIZE_PENDING_REQUEST_COUNTER(de)  \
     KeInitializeSpinLock(&(de)->PendingRequestSpin.sl);\
     (de)->PendingRequestCount = -1; \
     InitializeListHead(&(de)->TrackIrpList);

// ds\adsi\drt\adscmd\dispdef.hxx
#define DEFDISPSIZE(n, t) static int n = sizeof(t) / sizeof(DISPENTRY);

// ds\adsi\include\netolary.hxx
#define DECLARE_ADsDATAARY(_Cls, _Ty, _pTy)                   \
    class _Cls : public CADsAry                               \
    {                                                           \
    public:                                                     \
        _Cls(void) : CADsAry() { ; }                          \
        _Ty& operator[] (int i) { return * (_pTy) Deref(sizeof(_Ty), i); }   \
        operator _pTy(void) { return (_pTy) _pv; }              \
        _Cls(const _Cls &);                                     \
        _Cls& operator=(const _Cls &);                          \
                                                                \
        HRESULT     EnsureSize(int c)                           \
                        { return CADsAry::EnsureSize(sizeof(_Ty), c); }  \
        HRESULT     AppendIndirect(void * pv)                   \
                        { return CADsAry::AppendIndirect(sizeof(_Ty), pv); } \
        HRESULT     InsertIndirect(int i, void * pv)            \
                        { return CADsAry::InsertIndirect(sizeof(_Ty), i, pv); } \
        int         FindIndirect(void ** ppv)                   \
                        { return CADsAry::FindIndirect(sizeof(_Ty), ppv); } \
                                                                \
        void        Delete(int i)                               \
                        { CADsAry::Delete(sizeof(_Ty), i); }      \
        void        BringToFront(int i)                         \
                        { CADsAry::BringToFront(sizeof(_Ty), i); } \
        void        SendToBack(int i)                           \
                        { CADsAry::SendToBack(sizeof(_Ty), i); }  \
                                                                \
        HRESULT     Copy(const CADsAry& ary, BOOL fAddRef)    \
                        { return CADsAry::Copy(sizeof(_Ty), ary, fAddRef); } \
                                                                \
        HRESULT     EnumElements(                               \
                            REFIID iid,                         \
                            void ** ppv,                        \
                            BOOL fAddRef,                       \
                            BOOL fCopy = TRUE,                  \
                            BOOL fDelete = TRUE)                \
                        { return CADsAry::EnumElements(sizeof(_Ty), iid, ppv, fAddRef, fCopy, fDelete); } \
                                                                \
        HRESULT     EnumVARIANT(                                \
                            VARTYPE vt,                         \
                            IEnumVARIANT ** ppenum,             \
                            BOOL fCopy = TRUE,                  \
                            BOOL fDelete = TRUE)                \
                        { return CADsAry::EnumVARIANT(sizeof(_Ty), vt, ppenum, fCopy, fDelete); } \
    };

// ds\adsi\ldap\common.cxx
#define MAX_FILTERS (sizeof(Filters)/sizeof(FILTERS))

// ds\adsi\ldap\cprops.hxx
#define PROPERTY_EMPTY(pProperty) \
    (((pProperty)->ldapObjectArray.pLdapObjects) == NULL)

// ds\adsi\ldap\wmiutils.h
#define IWbemQuery_SetLanguageFeatures(This,lFlags,uArraySize,puFeatures)	\
    (This)->lpVtbl -> SetLanguageFeatures(This,lFlags,uArraySize,puFeatures)
#define IWbemQuery_TestLanguageFeatures(This,uArraySize,puFeatures)	\
    (This)->lpVtbl -> TestLanguageFeatures(This,uArraySize,puFeatures)

// ds\adsi\ldapc\ldaptype.hxx
#define LDAPOBJECTARRAY_INIT(ldapobjectarray) \
    memset(&ldapobjectarray, 0, sizeof(ldapobjectarray))

// ds\adsi\msext\common.cxx
#define MAX_FILTERS (sizeof(Filters)/sizeof(FILTERS))

// ds\adsi\nds\common.cxx
#define MAX_FILTERS  (sizeof(Filters)/sizeof(FILTERS))

// ds\adsi\novellnw\common.cxx
#define MAX_FILTERS  (sizeof(Filters)/sizeof(FILTERS))

// ds\adsi\nw312\common.cxx
#define MAX_FILTERS  (sizeof(Filters)/sizeof(FILTERS))

// ds\adsi\nwnds\common.cxx
#define MAX_FILTERS  (sizeof(Filters)/sizeof(FILTERS))

// ds\adsi\nwutils\encrypt.c
#define XorArray( DEST, SRC ) {                             \
    PULONG D = (PULONG)DEST;                                \
    PULONG S = (PULONG)SRC;                                 \
    int i;                                                  \
    for ( i = 0; i <= 7 ; i++ ) {                           \
        D[i] ^= S[i];                                       \
    }                                                       \
}

// ds\adsi\router\acledit.cxx
#define SeLengthSid( Sid ) \
    (8 + (4 * ((SID *)Sid)->SubAuthorityCount))

// ds\adsi\router\dbid.cxx
#define dimensionof(x) sizeof(x)/sizeof(x[0])

// ds\adsi\router\dbid.h
#define static_wcslen(pwsz) ((sizeof(pwsz) / sizeof(WCHAR)) - 1)

// ds\adsi\router\oledbutl.hxx
    #define NUMELEM(x) (sizeof(x)/sizeof(*x))

// ds\adsi\router\utilprop.hxx
#define NUMELEM(p) (sizeof(p) / sizeof(p[0]))

// ds\adsi\winnt\common.cxx
#define MAX_FILTERS  (sizeof(Filters)/sizeof(FILTERS))

// ds\dns\dnsapi\config.c
#define CONFIG_TABLE_LENGTH     (sizeof(ConfigMappingArray) / sizeof(CONFIG_MAPPING))

// ds\dns\dnsapi\dnsapip.h
#define DNS_MAX_ADDRESS_LENGTH      (sizeof(DNS_MAX_ADDRESS))
#define DNS_MAX_SOCKADDR_LENGTH     (sizeof(SOCKADDR_IP))

// ds\dns\dnsapi\hostfile.c
#define HOST_FILE_PATH_LENGTH  (MAX_PATH + sizeof("\\hosts") + 1)

// ds\dns\dnsapi\rtlstuff.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// ds\dns\dnslib\message.h
#define CURRENT_RR_COUNT_FIELD( pMsg )    \
            (*(pMsg)->pCurrentCountField)
#define SET_CURRENT_RR_COUNT_SECTION( pMsg, section )    \
            (pMsg)->pCurrentCountField = \
                        &(pMsg)->MessageHead.QuestionCount + (section);

// ds\dns\resolver\idl\resrpc.h
#define SIZE_FOR_ADDR_ARRAY(count) \
        (sizeof(DNS_ADDR_ARRAY) + (count * sizeof(DNS_ADDR_INFO)))

// ds\dns\server\server\msginfo.h
#define CURRENT_RR_SECTION_COUNT( pMsg )    \
            RR_SECTION_COUNT( pMsg, (pMsg)->Section )

// ds\dns\server\server\tree.c
#define DB_NODE_LENGTH( _cchLabelLength )                                   \
    ( ( DB_NODE_FIXED_LENGTH ) + ( _cchLabelLength ) +                      \
        ( ( SrvCfg_fCasePreservation ) ? ( _cchLabelLength ) + 1 : 0 ) )

// ds\dns\server\server\tree.h
#define DB_NODE_FIXED_LENGTH    (sizeof(DB_NODE) - STANDARD_NODE_LABEL_LENGTH)

// ds\ds\src\common\atq\auxctrs.h
# define AcCounter( acCounter)   \
 (((acCounter) < NUM_AUX_COUNTERS) ? g_AuxCounters[acCounter] : 0)

// ds\ds\src\common\w32topl\exe\apitest.c
#define NELEMENTS(x)        (sizeof(x)/sizeof(x[0]))

// ds\ds\src\common\w32topl\exe\main.c
#define NELEMENTS(x)        (sizeof(x)/sizeof(x[0]))

// ds\ds\src\common\w32topl\w32toplp.h
#define ToplpIsListElement(Elem)  ((Elem)   ? ( ((PLIST_ELEMENT)(Elem))->ObjectType == eEdge || \
                                                ((PLIST_ELEMENT)(Elem))->ObjectType == eVertex) : 0)

// ds\ds\src\inc\_entryid.h
#define CBDIR_ENTRYID sizeof(DIR_ENTRYID)
#define CBUSR_ENTRYID sizeof(USR_ENTRYID)

// ds\ds\src\inc\attignor.h
#define cIgnorableAttr (sizeof(rIgnorableAttr) / sizeof(rIgnorableAttr[0]))

// ds\ds\src\inc\msrpc.h
#define MAX_NS_ENTRY_NAME_LEN (sizeof(NS_ENTRY_NAME_PREFIX) + MAX_COMPUTERNAME_LENGTH + 1)

// ds\ds\src\ism\include\memory.h
#define NEW_TYPE_ARRAY( count, type ) (type *) malloc( (count) * sizeof( type ) )
#define REALLOC_TYPE_ARRAY( p, count, type ) (type *) realloc( p, (count) * sizeof( type ) )
#define NEW_TYPE_ARRAY_ZERO( count, type ) (type *) calloc( (count), sizeof( type ) )

// ds\ds\src\kcc\kccnctl.cxx
#define g_cAttidNCListType (sizeof(g_rgAttidNCListType) / sizeof(ATTRTYP))

// ds\ds\src\kcc\sim\util.h
#define KCCSIM_NEW_ARRAY(x,y) \
    (x *) KCCSimAlloc ((y) * sizeof (x))

// ds\ds\src\ldap\client\cache.cxx
#define NUM_CACHED_ATTR  ((sizeof(CachedAttributeList)/sizeof(PWCHAR))-1)

// ds\ds\src\ldap\client\dnfilter\util.h
#define MAKE_REFERENCE_HISTORY_ENTRY() {                                           \
		PVOID CallersAddress, CallersCallersAddress;							   \
		RtlGetCallersAddress (&CallersAddress, &CallersCallersAddress);            \
		EnterCriticalSection (&ReferenceHistoryLock);                              \
		REFERENCE_HISTORY * ReferenceHistoryNode = ReferenceHistory.AllocAtEnd (); \
		ReferenceHistoryNode -> CallersAddress = CallersAddress;                   \
		ReferenceHistoryNode -> CurrentReferenceCount = Count;                     \
		LeaveCriticalSection (&ReferenceHistoryLock);                              \
	}

// ds\ds\src\ldap\client\getset.cxx
#define NUM_SUPPORTED_EXTENSIONS  ((sizeof(SupportedExtensionList)/sizeof(PWCHAR))-1)

// ds\ds\src\ldap\client\lmacros.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// ds\ds\src\ntdsa\dblayer\dbintrnl.h
#define SORTED_INDEX(x) ( ((x)==TEMP_TABLE_INDEX_TYPE) || ((x)==TEMP_TABLE_MEMORY_ARRAY_TYPE) )

// ds\ds\src\ntdsa\dra\addsid.c
#define LEGAL_UF_ACCOUNT_CONTROL    (   UF_NORMAL_ACCOUNT               \
                                      | UF_WORKSTATION_TRUST_ACCOUNT    \
                                      | UF_SERVER_TRUST_ACCOUNT )

// ds\ds\src\ntdsa\dra\script.cxx
#define SCRIPT_VALUE_TRUE_LEN ( sizeof(SCRIPT_VALUE_TRUE)/sizeof(WCHAR) -1 )
#define SCRIPT_VALUE_FALSE_LEN ( sizeof(SCRIPT_VALUE_FALSE)/sizeof(WCHAR) -1 )

// ds\ds\src\ntdsa\include\drancrep.h
#define LOST_AND_FOUND_CONFIG_LEN ((sizeof(LOST_AND_FOUND_CONFIG) / sizeof(WCHAR)) - 1)
#define LOST_AND_FOUND_DOMAIN_LEN ((sizeof(LOST_AND_FOUND_DOMAIN) / sizeof(WCHAR)) - 1)

// ds\ds\src\ntdsa\include\mdlocal.h
#define ClassInfoAllocOrResizeElement(p,startSize,allocedSize,newSize) \
        if (!(p)) {                                                             \
            (allocedSize) = (startSize);                                        \
            (p) = THAllocEx (pTHS, sizeof (ATTRTYP) * (allocedSize) );          \
        }                                                                       \
        else if ( (allocedSize) < (newSize) ) {                                 \
            (allocedSize) = (newSize) + (startSize);                            \
            (p) = THReAllocEx (pTHS, (p), sizeof (ATTRTYP) * (allocedSize) );   \
        }
#define ClassInfoAllocOrResizeElement2(p,pCC,startSize,allocedSize,newSize) \
        if (!(p)) {                                                             \
            (allocedSize) = (startSize);                                        \
            (p) = THAllocEx (pTHS, sizeof (ATTRTYP) * (allocedSize) );          \
            (pCC) = THAllocEx (pTHS, sizeof (CLASSCACHE *) * (allocedSize) );   \
        }                                                                       \
        else if ( (allocedSize) < (newSize) ) {                                 \
            (allocedSize) = (newSize) + (startSize);                            \
            (p) = THReAllocEx (pTHS, (p), sizeof (ATTRTYP) * (allocedSize) );   \
            (pCC) = THReAllocEx (pTHS, (pCC), sizeof (CLASSCACHE *) * (allocedSize) ); \
        }

// ds\ds\src\ntdsa\include\scache.h
#define OID_LENGTH(oid_string)  (sizeof(OMP_O_##oid_string)-1)

// ds\ds\src\ntdsa\ldap\ldapconv.cxx
#define NUM_KNOWNCONTROLS (sizeof(KnownControls)/sizeof(LDAPOID))
#define NUM_KNOWNMATCHINGRULES (sizeof(KnownMatchingRules)/sizeof(LDAPOID))
#define NUM_SUPPORTED_CAPS  (sizeof(SupportedCapabilities)/sizeof(LDAPOID))
#define NUM_ROOT_DSE_ATTS (sizeof(RootDSEAtts)/sizeof(AttributeType))

// ds\ds\src\ntdsa\ldap\ldapsvr.hxx
#define BINARY_OPTION_LENGTH  (sizeof(BINARY_OPTION) - 1)
#define RANGE_OPTION_LENGTH  (sizeof(RANGE_OPTION) - 1)
#define XML_OPTION_LENGTH  (sizeof(XML_OPTION) - 1)

// ds\ds\src\ntdsa\ldap\sortlocales.c
#define NUM_LANGLOCALES (sizeof(LangLcidOid)/sizeof(LANG_LCID_OID) - 1)

// ds\ds\src\ntdsa\mkdit\createdb.cxx
#define STRDEFCOUNT (sizeof(StrDef)/sizeof(StrDef[0]))

// ds\ds\src\ntdsa\mkdit\schema.cxx
#define RDNPREFIXCOUNT (sizeof(RDNPrefixTable)/sizeof(RDNPrefixTable[0]))

// ds\ds\src\ntdsa\src\gcverify.c
#define ARRAY_COUNT(x) ((sizeof(x))/(sizeof(x[0])))

// ds\ds\src\ntdsa\src\mdinidsa.c
#define DSA_RDN_LEN ((sizeof(wcDsaRdn)/sizeof(wcDsaRdn[0])) - 1)

// ds\ds\src\ntdsa\src\samcache.c
#define NELEMENTS(x)  (sizeof(x)/sizeof((x)[0]))
#define ENTRY_HAS_EXPIRED(entry, standard) \
    ((-1) == CompareFileTime((FILETIME*)&(entry),(FILETIME*)&(standard)))

// ds\ds\src\ntdsa\src\scache.c
#define NUMATTATT  sizeof(AttributeSelList)/sizeof(ATTR)
#define RECALCSCHNUMATTATT  sizeof(RecalcSchAttributeSelList)/sizeof(ATTR)
#define NUMCLASSATT  sizeof(ClassSelList)/sizeof(ATTR)
#define RECALCSCHNUMCLASSATT  sizeof(RecalcSchClassSelList)/sizeof(ATTR)

// ds\ds\src\ntdsa\src\scchk.c
#define NUMATT sizeof(SelList)/sizeof(ATTR)

// ds\ds\src\ntdsa\src\servinfo.c
#define NUM_OURSERVICES (sizeof(OurServiceClassVals)/sizeof(WCHAR *))
#define NUM_OURSERVICESTOREMOVE (sizeof(OurServiceClassValsToRemove)/sizeof(WCHAR *))
#define NUM_KERBEROSSERVICES (sizeof(KerberosServiceClassVals)/sizeof(WCHAR *))

// ds\ds\src\ntdsapi\spn.c
#define NUMBER_ELEMENTS( A ) ( sizeof( A ) / sizeof( A[0] ) )

// ds\ds\src\ntdsapi\util.h
#define NUMBER_ELEMENTS( A ) ( sizeof( A ) / sizeof( A[0] ) )

// ds\ds\src\sam\server\attr.c
#define SampVariableAttributeCount( c )                                     \
    (SampObjectInformation[(c)->ObjectType].VariableAttributeCount)
#define SampVariableArrayAddress( c )                                       \
    (                                                                       \
        (IsDsObject(c)) ?                                                   \
            SampDsVariableArrayAddress(c) : SampRegVariableArrayAddress(c)  \
    )
#define SampRegFixedBufferLength( c )                                       \
    (                                                                       \
            SampObjectInformation[(c)->ObjectType].FixedLengthSize          \
    )
#define SampDsFixedBufferLength( c )                                        \
    (                                                                       \
            SampObjectInformation[(c)->ObjectType].FixedDsLengthSize        \
    )
#define SampFixedBufferLength( c )                                          \
    (                                                                       \
        (IsDsObject(c)) ?                                                   \
            SampDsFixedBufferLength(c) : SampRegFixedBufferLength(c)        \
    )
#define SampVariableBufferLength( c )                                       \
    (                                                                       \
        (IsDsObject(c)) ?                                                   \
            SampDsVariableBufferLength(c) : SampRegVariableBufferLength(c)  \
    )
#define SampVariableBufferUsedLength( c )                                   \
    (                                                                       \
        (IsDsObject(c)) ?                                                   \
            SampDsVariableBufferUsedLength(c):                              \
            SampRegVariableBufferUsedLength(c)                              \
    )

// ds\ds\src\sam\server\display.c
#define USER_ACCOUNT(AccountControl) ((AccountControl & \
                                       (USER_NORMAL_ACCOUNT | \
                                       USER_TEMP_DUPLICATE_ACCOUNT)) != 0)
#define MACHINE_ACCOUNT(AccountControl) ((AccountControl & \
                                         (USER_WORKSTATION_TRUST_ACCOUNT | \
                                          USER_SERVER_TRUST_ACCOUNT)) != 0)
#define INTERDOMAIN_ACCOUNT(AccountControl) (((AccountControl) & \
                                   (USER_INTERDOMAIN_TRUST_ACCOUNT)) != 0)
#define DISPLAY_ACCOUNT(AccountControl) (USER_ACCOUNT(AccountControl)    || \
                                         MACHINE_ACCOUNT(AccountControl) || \
                                         INTERDOMAIN_ACCOUNT(AccountControl))

// ds\ds\src\sam\server\enum.c
#define AVERAGE_MEMORY_PER_ENTRY    sizeof(SAM_RID_ENUMERATION) + LM20_UNLEN * sizeof(WCHAR) + sizeof(WCHAR)

// ds\ds\src\sam\server\samsrvp.h
#define DomainObjectFromAccountContext(C)\
            SampDefinedDomains[C->DomainIndex].Context->ObjectNameInDs
#define DomainSidFromAccountContext(C)\
            SampDefinedDomains[C->DomainIndex].Sid
#define ARRAY_COUNT(x)  (sizeof(x)/sizeof(x[0]))

// ds\ds\src\sam\server\samss.c
    #define NELEMENTS(x) (sizeof(x)/sizeof((x)[0]))

// ds\ds\src\sam\server\sdconvrt.h
#define ACCOUNT_OPERATOR_SID     (&(SampAccountOperatorsAliasSid))

// ds\ds\src\sam\server\site.c
#define ENTRY_HAS_EXPIRED(entry, standard) \
    ((-1) == CompareFileTime((FILETIME*)&(entry),(FILETIME*)&(standard)))
#define ENTRY_IS_EMPTY(x)  (!memcmp((x), &SampNullSiteAffinity, sizeof(SampNullSiteAffinity)))

// ds\ds\src\sam\server\upgrade.c
#define ADMINISTRATIVE_ALIAS_COUNT (sizeof(AdministrativeRids)/sizeof(ULONG))

// ds\ds\src\sam\test\main.c
#define NUM_COMMANDS (sizeof(Commands) / sizeof(CommandPair))

// ds\ds\src\test\mangle\mangle.c
#define NUMBER_TEST_CASES (sizeof(testCases) / sizeof(testCases[0]))
#define NUMBER_TEST_CASES (sizeof(testCases) / sizeof(testCases[0]))
#define NUMBER_TEST_CASES (sizeof(testCases) / sizeof(testCases[0]))

// ds\ds\src\test\spn\testspn.c
#define NUMBER_ELEMENTS( A ) ( sizeof( A ) / sizeof( A[0] ) )

// ds\ds\src\util\dcdiag\common\print.c
#define DimensionOf(x) (sizeof(x)/sizeof((x)[0]))

// ds\ds\src\util\dsexts\dra.c
#define gcNumAsyncOpCodes (sizeof(gAsyncOpCode)/sizeof(gAsyncOpCode[0]))

// ds\ds\src\util\dsexts\md.c
#define NUM_KNOWN_GUIDS  (sizeof (guidCache) / sizeof (GuidCache) -1 )
#define countDCmd (sizeof(aDCmd)/sizeof(DPRINTCMD))

// ds\ds\src\util\ldp\secmisc.cpp
#define NUM_KNOWN_GUIDS  (sizeof (guidCache) / sizeof (GuidCache) -1 )

// ds\ds\src\util\ntdsetup\setuputl.h
#define ARRAY_COUNT(x) (sizeof(x)/sizeof((x)[0]))

// ds\ds\src\util\rpcspoof\replrpcimpl.cxx
#define RANGE_OPTION_LENGTH  (sizeof(RANGE_OPTION) - sizeof(WCHAR))

// ds\ds\src\util\tapicfg\ilsng.c
#define DimensionOf(x) (sizeof(x)/sizeof((x)[0]))

// ds\ds\src\util\tapicfg\print.c
#define DimensionOf(x) (sizeof(x)/sizeof((x)[0]))

// ds\ese98\src\inc\daedef.hxx
#define CArrayElements( array )		( sizeof( array ) / sizeof( array[0] ) )

// ds\inc\strarray.h
#define NetpIsTStrArrayEmpty( Array )  \
    ( ( (*(Array)) == (TCHAR) '\0') ? TRUE : FALSE )

// ds\netapi\access\user.c
#define USERACCOUNTCONTROL( _f )    ( \
            ( ( (_f) & FILTER_TEMP_DUPLICATE_ACCOUNT ) ? \
                        USER_TEMP_DUPLICATE_ACCOUNT : 0 ) | \
            ( ( (_f) & FILTER_NORMAL_ACCOUNT ) ? \
                        USER_NORMAL_ACCOUNT : 0 ) | \
            ( ( (_f) & FILTER_INTERDOMAIN_TRUST_ACCOUNT ) ? \
                        USER_INTERDOMAIN_TRUST_ACCOUNT : 0 ) | \
            ( ( (_f) & FILTER_WORKSTATION_TRUST_ACCOUNT ) ? \
                        USER_WORKSTATION_TRUST_ACCOUNT : 0 ) | \
            ( ( (_f) & FILTER_SERVER_TRUST_ACCOUNT ) ? \
                        USER_SERVER_TRUST_ACCOUNT : 0 ) \
        )

// ds\netapi\netcmd\common\luidate.c
#define NUM_AMPM_LIST 	(sizeof(ampm_data)/sizeof(ampm_data[0]))
#define NUM_MONTHS_LIST (sizeof(months_data)/sizeof(months_data[0]))

// ds\netapi\netcmd\inc\netascii.h
#define DIMENSION(a) (sizeof(a) / sizeof(a[0]))

// ds\netapi\netcmd\netcmd\accounts.c
#define NUM_ACC_MSGS (sizeof(accMsgList)/sizeof(accMsgList[0]))

// ds\netapi\netcmd\netcmd\config.c
#define NUMVMSG (sizeof(valmsg_list)/sizeof(valmsg_list[0]))
#define NUMWMSG (sizeof(wkstamsg_list) / sizeof(wkstamsg_list[0]))
#define NUMSMSG (sizeof(srvmsg_list)/sizeof(srvmsg_list[0]))
#define NUMSRVMAXVAL (sizeof(srv_max)/sizeof(srv_max[0]))

// ds\netapi\netcmd\netcmd\file.c
#define NUM_FILE_MSGS	            (sizeof(FileMsgList)/sizeof(FileMsgList[0]))

// ds\netapi\netcmd\netcmd\group.c
#define NUM_GRP_MSGS    (sizeof(msglist)/sizeof(msglist[0]))

// ds\netapi\netcmd\netcmd\message.c
#define NUM_NAME_MSGS	(sizeof(NameMsgList)/sizeof(NameMsgList[0]))

// ds\netapi\netcmd\netcmd\ntalias.c
#define NUM_ALIAS_MSGS  (sizeof(msglist)/sizeof(msglist[0]))

// ds\netapi\netcmd\netcmd\print.c
#define NUM_PJS_MSGS    (sizeof(PJSMsgList)/sizeof(PJSMsgList[0]))
#define NUM_PQS_MSGS    (sizeof(PQSMsgList)/sizeof(PQSMsgList[0]))
#define NUM_PFS_MSGS    (sizeof(PFSMsgList)/sizeof(PFSMsgList[0]))
#define NUM_FJS_MSGS     (sizeof(FJSMsgList)/sizeof(FJSMsgList[0]))
#define NUM_PROPT_MSGS  (sizeof(PrOptMsgList)/sizeof(PrOptMsgList[0]))

// ds\netapi\netcmd\netcmd\session.c
#define NUM_SESS_MSGS   (sizeof(SessMsgList)/sizeof(SessMsgList[0]))

// ds\netapi\netcmd\netcmd\share.c
#define NUM_SHARE_MSGS (sizeof(ShareMsgList)/sizeof(ShareMsgList[0]))

// ds\netapi\netcmd\netcmd\stats.c
#define WKSTAMSGSIZE	    (sizeof(WkstaMsgList) / sizeof(WkstaMsgList[0]))
#define SRVMSGSIZE	(sizeof(ServerMsgList) / sizeof(ServerMsgList[0]))

// ds\netapi\netcmd\netcmd\user.c
#define NUMUMSG (sizeof(msglist)/sizeof(msglist[0]))
#define NUMVT (sizeof(valtext)/sizeof(valtext[0]))
#define NUMWKT (sizeof(weekday_text)/sizeof(weekday_text[0]))

// ds\netapi\netcmd\netuse\use.c
#define NUM_USE_MSGS (sizeof(UseMsgList)/sizeof(UseMsgList[0]))

// ds\netapi\netcmd\netuse\view.c
#define NUM_VIEW_MSGS (sizeof(ViewMsgList)/sizeof(ViewMsgList[0]))
#define NEXT_SHARE_ENTRY(p) \
         p= (b501 ? (LPSHARE_INFO_1) (((LPSHARE_INFO_501) p) + 1) : ((LPSHARE_INFO_1) p) + 1)

// ds\netapi\netlib\gettoken.c
#define TEXT_LENGTH(s)  ((sizeof(s)/sizeof(TCHAR)) - 1)
#define NUM_STRING_TOKENS   (sizeof(StringTokenTable) / sizeof(*StringTokenTable))

// ds\netapi\netlib\luidate.c
#define NUM_AMPM_LIST 	(sizeof(ampm_data)/sizeof(ampm_data[0]))
#define NUM_MONTHS_LIST (sizeof(months_data)/sizeof(months_data[0]))

// ds\netapi\svcdlls\lls\server\llsrtl.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// ds\netapi\svcdlls\nwsap\saplpc.h
#define NWSAP_BS_PORT_MAX_MESSAGE_LENGTH                                         \
    ( sizeof(NWSAP_REQUEST_MESSAGE) > sizeof(NWSAP_REPLY_MESSAGE) ?    \
         sizeof(NWSAP_REQUEST_MESSAGE) : sizeof(NWSAP_REPLY_MESSAGE) )

// ds\netapi\svcdlls\upssvc\apcsmart\upsreg.h
#define DIMENSION_OF(array) (sizeof(array)/sizeof(array[0]))

// ds\netapi\svcdlls\upssvc\upsexe\upsreg.h
#define DIMENSION_OF(array) (sizeof(array)/sizeof(array[0]))

// ds\netapi\svcimgs\ntrepl\inc\frsalloc.h
#define  INC_LOCAL_CO_QUEUE_COUNT(_R_)                       \
{                                                            \
    LONG Temp;                                               \
    Temp = InterlockedIncrement(&(_R_)->LocalCoQueueCount);  \
    DPRINT1(5, "++LocalCoQueueCount now %d\n", Temp);        \
}
#define  DEC_LOCAL_CO_QUEUE_COUNT(_R_)                       \
{                                                            \
    LONG Temp;                                               \
    Temp = InterlockedDecrement(&(_R_)->LocalCoQueueCount);  \
    DPRINT1(5, "--LocalCoQueueCount now %d\n", Temp);        \
}
#define  REPLICA_CHANGE_ORDER_ENTRY_KEY_LENGTH  sizeof(ULONGLONG)
#define  REPLICA_CHANGE_ORDER_FILEGUID_KEY_LENGTH  sizeof(GUID)

// ds\netapi\svcimgs\ntrepl\inc\jet.h
#define PROPERTY_SPECIFIER_NAME_LENGTH(PS,I) \
    (PROPERTY_SPECIFIER_COUNTED_STRING( PS, I )->Length)

// ds\netapi\svcimgs\ntrepl\inc\perrepsr.h
#define SIZEOF_REPSET_COUNTER_DATA sizeof(ReplicaSetCounters)
#define SIZEOF_REPCONN_COUNTER_DATA  sizeof(ReplicaConnCounters)

// ds\netapi\svcimgs\ntrepl\inc\replutil.h
#define MAXIMUM_VOLUME_LABEL_LENGTH  (32 * sizeof(WCHAR)) // 32 characters
#define OBJECT_ID_LENGTH  sizeof(GUID)
#define FILE_ID_LENGTH    sizeof(ULONGLONG)
#define FrsRemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    PLIST_ENTRY _EX_Entry;\
    _EX_Entry = (Entry);\
    _EX_Flink = _EX_Entry->Flink;\
    _EX_Blink = _EX_Entry->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    _EX_Entry->Flink = _EX_Entry->Blink = _EX_Entry;\
    }
#define RemoveEntryListB(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    PLIST_ENTRY _EX_Entry;\
    _EX_Entry = (Entry);\
    _EX_Flink = _EX_Entry->Flink;\
    _EX_Blink = _EX_Entry->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    _EX_Entry->Flink = _EX_Entry->Blink = _EX_Entry;\
    }
#define RemoveSingleListEntry( _UNUSED_ )  \
    __PrevEntry->Next = __NextEntry;       \
    __Entry->Next = NULL;                  \
    __Entry = __PrevEntry;
#define FrsRtlCountQueue(_pQueue_) \
            (((_pQueue_)->Control)->ControlCount)
#define FrsRtlCountSubQueue(_pQueue_) \
            ((_pQueue_)->Count)
#define  FrsRtlInsertBeforeEntryListLock( _List, _BeforeEntry, _NewEntry ) \
    InsertTailList((_BeforeEntry), (_NewEntry)); \
    (_List)->Count += 1; \
    ((_List)->Control)->ControlCount += 1; \
#define FrsIncrementRequestCount(_RC_)     \
    EnterCriticalSection(&(_RC_)->Lock);   \
    (_RC_)->Count += 1;                    \
    if ((_RC_)->Count == 1) {              \
        ResetEvent((_RC_)->Event);         \
    }                                      \
    LeaveCriticalSection(&(_RC_)->Lock);
#define ARRAY_SZ(_ar)  (sizeof(_ar)/sizeof((_ar)[0]))
#define ARRAY_SZ2(_ar, _type)  (sizeof(_ar)/sizeof(_type))

// ds\netapi\svcimgs\ntrepl\repl\chgorder.c
#define IdtCoRetryFieldCount  (sizeof(IdtCoRetryFieldList) / sizeof(ULONG))
#define IdtCoReanimateFieldCount  (sizeof(IdtFieldReanimateList) / sizeof(ULONG))
#define ESE_INDEX_LENGTH_LIMIT  (JET_cbKeyMost & 0XFFFFFFFE)

// ds\netapi\svcimgs\ntrepl\repl\createdb.c
#define CnfMarkPointFieldCount  (sizeof(CnfMarkPointFieldList) / sizeof(ULONG))
#define CnfStatFieldCount  (sizeof(CnfStatFieldList) / sizeof(ULONG))

// ds\netapi\xactsrv\xsconst.h
#define XS_PORT_MAX_MESSAGE_LENGTH                                         \
    ( sizeof(XACTSRV_REQUEST_MESSAGE) > sizeof(XACTSRV_REPLY_MESSAGE) ?    \
         sizeof(XACTSRV_REQUEST_MESSAGE) : sizeof(XACTSRV_REPLY_MESSAGE) )

// ds\nw\convert\nwconv\ctlspriv.h
#define COUNTOF(x) (sizeof(x)/sizeof(*x))

// ds\nw\convert\nwconv\encrypt.c
#define XorArray( DEST, SRC ) {                             \
    PULONG D = (PULONG)DEST;                                \
    PULONG S = (PULONG)SRC;                                 \
    int i;                                                  \
    for ( i = 0; i <= 7 ; i++ ) {                           \
        D[i] ^= S[i];                                       \
    }                                                       \
}

// ds\nw\convert\nwconv\vlist.h
#define VLB_GETCOUNT            (WM_USER+505)

// ds\nw\fpnw\client\encrypt.c
#define XorArray( DEST, SRC ) {                             \
    PULONG D = (PULONG)DEST;                                \
    PULONG S = (PULONG)SRC;                                 \
    int i;                                                  \
    for ( i = 0; i <= 7 ; i++ ) {                           \
        D[i] ^= S[i];                                       \
    }                                                       \
}

// ds\nw\nwlib\win95\msnwerr.h
#define NWRE_INVALID_BUFFER_LENGTH  (REQUESTR_ERR | 0x33)

// ds\nw\rdr\convert.c
#define NUM_ERRORS sizeof(Error_Map) / sizeof(Error_Map[0])

// ds\nw\rdr\encrypt.c
#define XorArray( DEST, SRC ) {                             \
    PULONG D = (PULONG)DEST;                                \
    PULONG S = (PULONG)SRC;                                 \
    int i;                                                  \
    for ( i = 0; i <= 7 ; i++ ) {                           \
        D[i] ^= S[i];                                       \
    }                                                       \
}

// ds\nw\svcdlls\nwwks\lib\misc.c
#define NUM_ERRORS(x)  (sizeof(x)/sizeof(x[0]))

// ds\nw\vwipxspx\dll\vwvdm.h
#define ARRAY_ELEMENTS(a)   (sizeof(a)/sizeof((a)[0]))

// ds\security\azroles\sample.cxx
#define ObjectTypeNamesSize (sizeof(ObjectTypeNames)/sizeof(ObjectTypeNames[0]))

// ds\security\cryptoapi\common\pkifmt\pkifmt.cpp
#define CCH_BEGINMATCH  sizeof(szBeginMatch)/sizeof(szBeginMatch[0]) - 1
#define CCH_ENDMATCH    sizeof(szEndMatch)/sizeof(szEndMatch[0]) - 1
#define CCH_MINUS       sizeof(szMinus)/sizeof(szMinus[0]) - 1

// ds\security\cryptoapi\cryptsvc\catdbsvc.cpp
#define CDBPARAM    (sizeof(g_rgJetParams)/sizeof(g_rgJetParams[0]))

// ds\security\cryptoapi\mincrypt\lib\vercert.cpp
#define ROOT_CNT (sizeof(RootTable) / sizeof(RootTable[0]))

// ds\security\cryptoapi\mincrypt\lib\verhash.cpp
#define HASH_ALG_CNT (sizeof(HashAlgTable) / sizeof(HashAlgTable[0]))

// ds\security\cryptoapi\pki\activex\xenroll\xasnx.cpp
#define X509_ENCODE_FUNC_COUNT (sizeof(X509EncodeFuncTable) / \
                                    sizeof(X509EncodeFuncTable[0]))
#define X509_DECODE_FUNC_COUNT (sizeof(X509DecodeFuncTable) / \
                                    sizeof(X509DecodeFuncTable[0]))

// ds\security\cryptoapi\pki\activex\xenroll\xmsasnx.cpp
#define X509_ENCODE_FUNC_COUNT (sizeof(X509EncodeFuncTable) / \
                                    sizeof(X509EncodeFuncTable[0]))
#define X509_DECODE_FUNC_COUNT (sizeof(X509DecodeFuncTable) / \
                                    sizeof(X509DecodeFuncTable[0]))
#define CMC_ENCODE_EX_FUNC_COUNT (sizeof(CmcEncodeExFuncTable) / \
                                    sizeof(CmcEncodeExFuncTable[0]))
#define CMC_DECODE_EX_FUNC_COUNT (sizeof(CmcDecodeExFuncTable) / \
                                    sizeof(CmcDecodeExFuncTable[0]))

// ds\security\cryptoapi\pki\certstor\certhlpr.cpp
#define ENCODE_PUB_KEY_FUNC_COUNT (sizeof(EncodePubKeyFuncTable) / \
                                    sizeof(EncodePubKeyFuncTable[0]))
#define CONVERT_PUB_KEY_FUNC_COUNT (sizeof(ConvertPubKeyFuncTable) / \
                                    sizeof(ConvertPubKeyFuncTable[0]))

// ds\security\cryptoapi\pki\certstor\frmtfunc.h
#define CBBEGINCERT_W               (sizeof(BEGINCERT_W)/sizeof(WCHAR) - 1)
#define CBBEGINCERT_A               (sizeof(BEGINCERT_A)/sizeof(CHAR) - 1)
#define	CBBEGINCRL_W				(sizeof(BEGINCRL_W)/sizeof(WCHAR) - 1)
#define	CBBEGINCRL_A				(sizeof(BEGINCRL_A)/sizeof(CHAR) - 1)
#define CBBEGINREQUEST_W			(sizeof(BEGINREQUEST_W)/sizeof(WCHAR) - 1)
#define CBBEGINREQUEST_A			(sizeof(BEGINREQUEST_A)/sizeof(CHAR) - 1)

// ds\security\cryptoapi\pki\certstor\newstor.cpp
#define OPEN_STORE_PROV_FUNC_COUNT (sizeof(OpenStoreProvFuncTable) / \
                                    sizeof(OpenStoreProvFuncTable[0]))
#define FILE_STORE_PROV_FUNC_COUNT (sizeof(rgpvFileStoreProvFunc) / \
                                    sizeof(rgpvFileStoreProvFunc[0]))

// ds\security\cryptoapi\pki\certstor\oidinfo.cpp
#define HASH_ALG_CNT (sizeof(HashAlgTable) / sizeof(HashAlgTable[0]))
#define ENCRYPT_ALG_CNT (sizeof(EncryptAlgTable) / sizeof(EncryptAlgTable[0]))
#define PUBKEY_ALG_CNT (sizeof(PubKeyAlgTable) / sizeof(PubKeyAlgTable[0]))
#define SIGN_ALG_CNT (sizeof(SignAlgTable) / sizeof(SignAlgTable[0]))
#define RDN_ATTR_CNT (sizeof(RDNAttrTable) / sizeof(RDNAttrTable[0]))
#define EXT_ATTR_CNT (sizeof(ExtAttrTable) / sizeof(ExtAttrTable[0]))
#define ENHKEY_CNT (sizeof(EnhKeyTable) / sizeof(EnhKeyTable[0]))
#define POLICY_CNT (sizeof(PolicyTable) / sizeof(PolicyTable[0]))
#define TEMPLATE_CNT (sizeof(TemplateTable) / sizeof(TemplateTable[0]))

// ds\security\cryptoapi\pki\certstor\scstore.h
#define SMART_CARD_PROV_FUNC_COUNT (sizeof(rgpvSmartCardProvFunc) / \
                                    sizeof(rgpvSmartCardProvFunc[0]))

// ds\security\cryptoapi\pki\certstor\wincert.cpp
#define X509_ENCODE_EX_FUNC_COUNT (sizeof(X509EncodeExFuncTable) / \
                                    sizeof(X509EncodeExFuncTable[0]))
#define X509_DECODE_EX_FUNC_COUNT (sizeof(X509DecodeExFuncTable) / \
                                    sizeof(X509DecodeExFuncTable[0]))

// ds\security\cryptoapi\pki\chain\chain.cpp
#define FIND_MATCH_TYPE_CNT (sizeof(rgdwMatchType) / sizeof(rgdwMatchType[0]))

// ds\security\cryptoapi\pki\crypt32\crypt32.cpp
#define DLL_MAIN_FUNC_COUNT (sizeof(rgpfnDllMain) / sizeof(rgpfnDllMain[0]))

// ds\security\cryptoapi\pki\cryptnet\cryptnet.cpp
#define DLL_MAIN_FUNC_COUNT (sizeof(rgpfnDllMain) / sizeof(rgpfnDllMain[0]))
#define DLL_REGUNREGSERVER_FUNC_COUNT (sizeof(rgpfnDllRegUnregServer) / \
                                       sizeof(rgpfnDllRegUnregServer[0]))

// ds\security\cryptoapi\pki\pfxlib\encdecpk.cpp
#define PRIVATEKEY_ENCODE_FUNC_COUNT (sizeof(PrivateKeyEncodeFuncTable) / \
                                    sizeof(PrivateKeyEncodeFuncTable[0]))
#define PRIVATEKEY_DECODE_FUNC_COUNT (sizeof(PrivateKeyDecodeFuncTable) / \
                                    sizeof(PrivateKeyDecodeFuncTable[0]))

// ds\security\cryptoapi\pki\pfxlib\impexppk.cpp
#define EXPORT_PRIV_KEY_FUNC_COUNT (sizeof(ExportPrivKeyFuncTable) / \
                                    sizeof(ExportPrivKeyFuncTable[0]))
#define IMPORT_PRIV_KEY_FUNC_COUNT (sizeof(ImportPrivKeyFuncTable) / \
                                    sizeof(ImportPrivKeyFuncTable[0]))

// ds\security\cryptoapi\pki\rpor\init.cpp
#define SCHEME_RETRIEVE_FUNC_COUNT (sizeof(SchemeRetrieveFuncTable)/ \
                                    sizeof(SchemeRetrieveFuncTable[0]))
#define CONTEXT_CREATE_FUNC_COUNT (sizeof(ContextCreateFuncTable)/ \
                                   sizeof(ContextCreateFuncTable[0]))
#define GET_OBJECT_URL_FUNC_COUNT (sizeof(GetObjectUrlFuncTable)/ \
                                   sizeof(GetObjectUrlFuncTable[0]))
#define GET_TIME_VALID_OBJECT_FUNC_COUNT (sizeof(GetTimeValidObjectFuncTable)/ \
                                          sizeof(GetTimeValidObjectFuncTable[0]))
#define FLUSH_TIME_VALID_OBJECT_FUNC_COUNT (sizeof(FlushTimeValidObjectFuncTable)/ \
                                            sizeof(FlushTimeValidObjectFuncTable[0]))

// ds\security\cryptoapi\pki\rpor\ldapstor.h
#define LDAP_PROV_FUNC_COUNT (sizeof(rgpvLdapProvFunc) / \
                              sizeof(rgpvLdapProvFunc[0]))

// ds\security\cryptoapi\pki\rpor\msctl.cpp
#define USAGE_FUNC_COUNT (sizeof(UsageFuncTable) / sizeof(UsageFuncTable[0]))

// ds\security\cryptoapi\pki\setx509\setx509.cpp
#define REG_ENCODE_BEFORE_COUNT (sizeof(RegEncodeBeforeTable) / sizeof(RegEncodeBeforeTable[0]))
#define REG_ENCODE_AFTER_COUNT (sizeof(RegEncodeAfterTable) / sizeof(RegEncodeAfterTable[0]))
#define REG_DECODE_COUNT (sizeof(RegDecodeTable) / sizeof(RegDecodeTable[0]))
#define SET_ENCODE_FUNC_COUNT (sizeof(SetEncodeFuncTable) / \
                                    sizeof(SetEncodeFuncTable[0]))
#define SET_DECODE_FUNC_COUNT (sizeof(SetDecodeFuncTable) / \
                                    sizeof(SetDecodeFuncTable[0]))
#define SET_REV_FUNC_COUNT (sizeof(SetRevFuncTable) / \
                                    sizeof(SetRevFuncTable[0]))

// ds\security\cryptoapi\pki\sp3crmsg\sp3crmsg.cpp
#define IMPORT_ENCRYPT_KEY_FUNC_COUNT (sizeof(ImportEncryptKeyFuncTable) / \
                                        sizeof(ImportEncryptKeyFuncTable[0]))
#define IMPORT_ENCRYPT_KEY_REG_COUNT (sizeof(ImportEncryptKeyRegTable) / \
                                        sizeof(ImportEncryptKeyRegTable[0]))
#define GEN_ENCRYPT_KEY_FUNC_COUNT (sizeof(GenEncryptKeyFuncTable) / \
                                        sizeof(GenEncryptKeyFuncTable[0]))
#define GEN_ENCRYPT_KEY_REG_COUNT (sizeof(GenEncryptKeyRegTable) / \
                                        sizeof(GenEncryptKeyRegTable[0]))
#define EXPORT_ENCRYPT_KEY_FUNC_COUNT (sizeof(ExportEncryptKeyFuncTable) / \
                                        sizeof(ExportEncryptKeyFuncTable[0]))
#define EXPORT_ENCRYPT_KEY_REG_COUNT (sizeof(ExportEncryptKeyRegTable) / \
                                        sizeof(ExportEncryptKeyRegTable[0]))

// ds\security\cryptoapi\pki\wincrmsg\wincrmsg.cpp
#define  COUNTOF_aoidMessages  (sizeof(aoidMessages)/sizeof(aoidMessages[0]))
#define GEN_ENCRYPT_KEY_FUNC_COUNT (sizeof(GenEncryptKeyFuncTable) / \
                                        sizeof(GenEncryptKeyFuncTable[0]))
#define EXPORT_ENCRYPT_KEY_FUNC_COUNT (sizeof(ExportEncryptKeyFuncTable) / \
                                        sizeof(ExportEncryptKeyFuncTable[0]))
#define IMPORT_ENCRYPT_KEY_FUNC_COUNT (sizeof(ImportEncryptKeyFuncTable) / \
                                        sizeof(ImportEncryptKeyFuncTable[0]))

// ds\security\cryptoapi\pkitrust\softpub\expapis.cpp
#define NMYSTORES (sizeof(rgpszMyStore)/sizeof(rgpszMyStore[0]))
#define NCASTORES (sizeof(rgCaStoreInfo)/sizeof(rgCaStoreInfo[0]))

// ds\security\cryptoapi\pkitrust\softpub\httpsprv.cpp
#define CLIENT_USAGE_COUNT      (sizeof(rgpszClientUsage) / \
                                     sizeof(rgpszClientUsage[0]))
#define SERVER_USAGE_COUNT      (sizeof(rgpszServerUsage) / \
                                     sizeof(rgpszServerUsage[0]))

// ds\security\cryptoapi\pkitrust\wintrust\dllmain.cpp
#define DLL_MAIN_FUNC_COUNT (sizeof(rgpfnDllMain) / sizeof(rgpfnDllMain[0]))

// ds\security\cryptoapi\pkitrust\wintrust\ossfunc.cpp
#define SPC_REG_ENCODE_COUNT (sizeof(SpcRegEncodeTable) / sizeof(SpcRegEncodeTable[0]))
#define SPC_REG_DECODE_COUNT (sizeof(SpcRegDecodeTable) / sizeof(SpcRegDecodeTable[0]))
#define SPC_ENCODE_FUNC_COUNT (sizeof(SpcEncodeFuncTable) / \
                                    sizeof(SpcEncodeFuncTable[0]))
#define SPC_DECODE_FUNC_COUNT (sizeof(SpcDecodeFuncTable) / \
                                    sizeof(SpcDecodeFuncTable[0]))

// ds\security\cryptoapi\secstor\dpapisvc\keyman.h
#define DEFAULT_MASTERKEY_ITERATION_COUNT (4000)    // 4000 == ~100ms on 400 MHz machine

// ds\security\cryptoapi\secstor\include\pmacros.h
#define ARRAY_COUNT(__z__)     \
    ( (__z__ == NULL) ? 0 : (sizeof( __z__ ) / sizeof( __z__[0] )) )

// ds\security\cryptoapi\test\capi20\pkcs8ex\pkcs8ex.cpp
#define NKEYTYPES (sizeof(KeyTypes)/sizeof(KeyTypes[0]))

// ds\security\cryptoapi\test\capi20\pkcs8im\pkcs8im.cpp
#define NKEYTYPES (sizeof(KeyTypes)/sizeof(KeyTypes[0]))

// ds\security\cryptoapi\test\capi20\tcert\tcert.cpp
#define NTESTS (sizeof(Tests)/sizeof(Tests[0]))

// ds\security\cryptoapi\test\capi20\tcertper\tcertper.cpp
#define NTESTS (sizeof(Tests)/sizeof(Tests[0]))

// ds\security\cryptoapi\test\capi20\tcrmsg\tcrmsg.cpp
#define NTESTS (sizeof(Tests)/sizeof(Tests[0]))

// ds\security\cryptoapi\test\capi20\textstor\textstor.cpp
#define EXT_STORE_PROV_FUNC_COUNT (sizeof(rgpvExtStoreProvFunc) / \
                                    sizeof(rgpvExtStoreProvFunc[0]))

// ds\security\cryptoapi\test\capi20\tfindclt\tfindclt.cpp
#define NKEYTYPES (sizeof(KeyTypes)/sizeof(KeyTypes[0]))

// ds\security\cryptoapi\test\capi20\tpvkload\tpvkload.cpp
#define NKEYTYPES (sizeof(KeyTypes)/sizeof(KeyTypes[0]))

// ds\security\cryptoapi\test\capi20\tpvksave\tpvksave.cpp
#define NKEYTYPES (sizeof(KeyTypes)/sizeof(KeyTypes[0]))

// ds\security\cryptoapi\test\capi20\tsca\tsca.cpp
#define NTESTS (sizeof(Tests)/sizeof(Tests[0]))

// ds\security\cryptoapi\test\capi20\tstgdir\tstgdir.cpp
#define NSCODETEXT (sizeof(scodes)/sizeof(scodes[0]))

// ds\security\cryptoapi\test\capi20\tstore2\tstore2.cpp
#define UPDATE_CTL_CNT  (sizeof(UpdateCtlPara)/sizeof(UpdateCtlPara[0]))

// ds\security\cryptoapi\test\capi20\ttrust\ttrust.cpp
#define NUM_MULTI_OID_PARA (sizeof(rgMultiOIDPara) / sizeof(rgMultiOIDPara[0]))

// ds\security\cryptoapi\test\capi20\turlread\turlread.cpp
#define NQUERYINFO  (sizeof(rgQueryInfo)/sizeof(rgQueryInfo[0]))

// ds\security\cryptoapi\test\capi20\tx500str\tx500str.cpp
#define NX500NAMES (sizeof(rgX500Names) / sizeof(rgX500Names[0]))

// ds\security\cryptoapi\test\capi20\txenrol\txenrol.cpp
#define COUNT_TEST   sizeof(arPfnTest)/sizeof(arPfnTest[0])

// ds\security\dsrole\inc\dssetp.h
#define NELEMENTS(x)  (sizeof(x)/sizeof((x)[0]))

// ds\security\gina\gpext\appmgmt\server\applist.hxx
#define MAXLEN_RSOPREMOVAL_QUERY_CRITERIA ( sizeof( RSOP_REMOVAL_QUERY_CRITERIA ) / sizeof( WCHAR ) )

// ds\security\gina\msgina\domain.h
#define DCacheReferenceEntry( x )   InterlockedIncrement( &(x)->RefCount );

// ds\security\gina\userenv\profile\hive.cpp
#define LENGTH(x)                  (sizeof(x) - sizeof(WCHAR))
#define NUM_SPECIAL_SUBTREES    (sizeof(SpecialSubtrees)/sizeof(*SpecialSubtrees))
#define CCH_TARGETHIVE      MAX_PATH - (sizeof(USER_KEY_PREFIX) / sizeof(TCHAR)) + 1

// ds\security\gina\userenv\profile\hkcr.c
#define LENGTH(x)                  (sizeof(x) - sizeof(WCHAR))
#define NUM_SPECIAL_SUBTREES    (sizeof(SpecialSubtrees)/sizeof(*SpecialSubtrees))

// ds\security\ntmarta\newsrc\filctx.cpp
#define WINDFS_DEVICE_LEN   (sizeof(WINDFS_DEVICE) / sizeof(WCHAR) - 1)
#define WINDFS_PREFIX_LEN   (sizeof(WINDFS_PREFIX) / sizeof(WCHAR) - 1)

// ds\security\ntmarta\newsrc\idcache.cxx
#define ACTRL_OBJ_NAME_LEN  sizeof(ACTRL_OBJ_NAME) / sizeof(WCHAR) - 1
#define ACTRL_OBJ_GUID_LEN  sizeof(ACTRL_OBJ_GUID) / sizeof(WCHAR) - 1
#define ACTRL_OBJ_CLASS_LEN  sizeof(ACTRL_OBJ_CLASS) / sizeof(WCHAR) - 1

// ds\security\ntmarta\newsrc\regctx.cpp
#define REG_OBJ_TAG_LEN (sizeof(REG_OBJ_TAG) / sizeof(WCHAR) - 1)

// ds\security\ntmarta\utest\ntmartat.c
#define SLEN(x)  ((sizeof(x) / sizeof(CHAR)) - 1)

// ds\security\passport\atlmfc\atlcom.h
#define PROP_ENTRY(szDesc, dispid, clsid) \
		{OLESTR(szDesc), dispid, &clsid, &__uuidof(IDispatch), 0, 0, 0},
#define PROP_ENTRY_EX(szDesc, dispid, clsid, iidDispatch) \
		{OLESTR(szDesc), dispid, &clsid, &iidDispatch, 0, 0, 0},

// ds\security\passport\atlmfc\atlisapi.h
#define HANDLER_ENTRY_SDL(handlerString, handlerClass, sdlClassName)\
__declspec(selectany) LPCSTR s_szClassName##handlerClass=handlerString;\
typedef CSDLGenerator<handlerClass, s_szClassName##handlerClass> sdlClassName; \
HANDLER_ENTRY(handlerString, handlerClass)\
HANDLER_ENTRY(#sdlClassName, sdlClassName)

// ds\security\passport\atlmfc\atlperf.h
#define PERFREG_ENTRY(className) \
	className __perf_##className; \
	extern "C" __declspec(allocate("ATLP$C")) CPerfMon * __pperf_##className = \
		static_cast<CPerfMon*>(&__perf_##className); \
	PERF_ENTRY_PRAGMA(className)

// ds\security\passport\atlmfc\atlstencil.h
#define REPLACEMENT_METHOD_ENTRY(methodName, methodFunc)\
    { 0, methodName,  {  ATL::CTagReplacerMethodsEx<__className, void>::CheckRepl(methodFunc), NULL }   },
#define REPLACEMENT_METHOD_ENTRY_EX(methodName, methodFunc, paramType, parseFunc)\
    { 1, methodName,  { ATL::CTagReplacerMethodsEx<__className, paramType>::CheckReplEx(methodFunc), ATL::CTagReplacerMethodsEx<__className, paramType>::CheckParse(parseFunc) } },
#define REPLACEMENT_METHOD_ENTRY_EX_STR(methodName, methodFunc) \
    { 1, methodName,  { ATL::CTagReplacerMethodsEx<__className, char>::CheckReplEx(methodFunc), ATL::CTagReplacerMethodsEx<__className, char>::CheckParse(DefaultParseString) } },

// ds\security\passport\atlmfc\atlutil.h
#define ATL_URL_MAX_URL_LENGTH         (ATL_URL_MAX_SCHEME_LENGTH \
                                       + sizeof("://") \
                                       + ATL_URL_MAX_PATH_LENGTH)

// ds\security\passport\atlmfc\bmio.h
#define IEnumBMExporterInfo_Next(This,nElements,ppElements,pnFetched)	\
    (This)->lpVtbl -> Next(This,nElements,ppElements,pnFetched)
#define IEnumBMExporterInfo_Skip(This,nElements)	\
    (This)->lpVtbl -> Skip(This,nElements)
#define IEnumBMImporterInfo_Next(This,nElements,ppElements,pnFetched)	\
    (This)->lpVtbl -> Next(This,nElements,ppElements,pnFetched)
#define IEnumBMImporterInfo_Skip(This,nElements)	\
    (This)->lpVtbl -> Skip(This,nElements)
#define IEnumBMFileTypeInfo_Next(This,nElements,ppElements,pnFetched)	\
    (This)->lpVtbl -> Next(This,nElements,ppElements,pnFetched)
#define IEnumBMFileTypeInfo_Skip(This,nElements)	\
    (This)->lpVtbl -> Skip(This,nElements)

// ds\security\passport\atlmfc\msxml2.h
#define IXMLDOMDocument_getElementsByTagName(This,tagName,resultList)	\
    (This)->lpVtbl -> getElementsByTagName(This,tagName,resultList)
#define IXMLDOMDocument2_getElementsByTagName(This,tagName,resultList)	\
    (This)->lpVtbl -> getElementsByTagName(This,tagName,resultList)
#define IXMLDOMElement_getElementsByTagName(This,tagName,resultList)	\
    (This)->lpVtbl -> getElementsByTagName(This,tagName,resultList)

// ds\security\passport\common\perflibrary\pmcounters\passportperfobjects.h
#define NUM_PERFMON_OBJECTS (sizeof(g_PObject) / sizeof(g_PObject[0]))

// ds\security\passport\include\listmacr.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// ds\security\passport\include\stock.h
#define ARRAY_ELEMENTS(rg)                (sizeof(rg) / sizeof((rg)[0]))

// ds\security\protocols\kerberos\client2\spncache.cxx
#define KerbWriteLockSpnCacheEntry(_x_)                 RtlAcquireResourceExclusive( &_x_->ResultLock, TRUE)
#define KerbReadLockSpnCacheEntry(_x_)                  RtlAcquireResourceShared( &_x_->ResultLock, TRUE)
#define KerbConvertSpnCacheEntryReadToWriteLock(_x_)    RtlConvertSharedToExclusive( &_x_->ResultLock )

// ds\security\protocols\kerberos\inc\utils.hxx
#define COUNTOF(s) ( sizeof( (s) ) / sizeof( *(s) ) )

// ds\security\protocols\kerberos\server\refer.cxx
#define KdcReferenceReferralCacheEntry(_x_) \
    InterlockedIncrement(&(_x_)->References)

// ds\security\protocols\xtcb\server.h
#define XtcbMessageLength( x )   ( sizeof( XTCB_SERVER_MESSAGE ) - 1 + \
                                  ((PXTCB_SERVER_MESSAGE) x)->DataLength )

// ds\security\services\ca\celib\celib.cpp
#define CUNITSTABLEMAX	(sizeof(g_aut)/sizeof(g_aut[0]))

// ds\security\services\ca\certdb\db.cpp
#define CDBPARM	(sizeof(g_aParm)/sizeof(g_aParm[0]))

// ds\security\services\ca\certlib\certlib.cpp
#define CUNITSTABLEMAX	(sizeof(g_aut)/sizeof(g_aut[0]))

// ds\security\services\ca\certlib\config.cpp
#define CSTRING (sizeof(s_apwszFieldNames)/sizeof(s_apwszFieldNames[0]))

// ds\security\services\ca\certmmc\chooser.cpp
#define LENGTH(x)		(sizeof(x)/sizeof(x[0]))

// ds\security\services\ca\certsrv\pkcs.cpp
#define CSUBJECTTABLE (sizeof(pkcs_subject) / sizeof(pkcs_subject[0]))

// ds\security\services\ca\include\cs.h
#define _TSZARRAYSIZE(a)	((sizeof(a)/sizeof((a)[0])) - 1)
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// ds\security\services\ca\ocmsetup\config.cpp
#define CSTRING (sizeof(apwszFieldNames)/sizeof(apwszFieldNames[0]))

// ds\security\services\ca\ocmsetup\cryptfix.cpp
#define REG_ENCODE_COUNT (sizeof(RegEncodeTable) / sizeof(RegEncodeTable[0]))
#define REG_DECODE_COUNT (sizeof(RegDecodeTable) / sizeof(RegDecodeTable[0]))
#define X509_ENCODE_FUNC_COUNT (sizeof(X509EncodeFuncTable) / \
                                    sizeof(X509EncodeFuncTable[0]))
#define X509_DECODE_FUNC_COUNT (sizeof(X509DecodeFuncTable) / \
                                    sizeof(X509DecodeFuncTable[0]))

// ds\security\services\ca\tools\certut\dump.cpp
#define CSTRING (sizeof(g_apwszFieldNames)/sizeof(g_apwszFieldNames[0]))
#define CASNFORMATS (sizeof(g_aasn)/sizeof(g_aasn[0]))

// ds\security\services\ca\tools\certut\odbc.h
#define CDNTRTABLE (sizeof(db_dntr) / sizeof(db_dntr[0]))

// ds\security\services\scerpc\client\setupcln.cpp
#define REG_OBJ_TAG_LEN (sizeof(REG_OBJ_TAG) / sizeof(WCHAR) - 1)

// ds\security\services\scerpc\escprov\requestobject.h
#define SCEPROV_SIZEOF_ARRAY(x) (sizeof(x)/sizeof(*x))

// ds\security\services\scerpc\server\analyze.cpp
#define MAX_ACCESS_ITEMS        sizeof(AccessItems)/sizeof(PWSTR)

// ds\security\services\smartcrd\tools\tclcrypt\tcldllutil.h
#define NEED_TMP_ARRAY(sz) \
    if (0 != TclEx_tmpArraySize) { \
        (void)fprintf(stderr, "TMP_ARRAY locked.\n"); \
        exit(1); } \
    else { \
        TclEx_tmpArray = (char **)ckalloc((sz) * sizeof(void *)); \
        TclEx_tmpArraySize = (sz); }
#define NEED_MORE_TMP_ARRAY(sz) \
    if (0 == TclEx_tmpArraySize) { \
        (void)fprintf(stderr, "TMP_ARRAY not locked.\n"); \
        exit(1); } \
    else { if (TclEx_tmpArraySize < (sz)) { \
            TclEx_tmpArray = (char **)ckrealloc((char *)TclEx_tmpArray, (sz) * sizeof(void *)); \
            TclEx_tmpArraySize = (sz); } }
#define NEED_MORE_TMP_ARRAY(sz) \
    if (TclEx_tmpArraySize < (sz)) { \
        TclEx_tmpArray = (char **)ckrealloc(TclEx_tmpArray, (sz) * sizeof(void *)); \
        TclEx_tmpArraySize = (sz); }

// ds\security\tools\kerbtray\kerbtray.c
#define TSIZE(b) (sizeof(b)/sizeof(TCHAR))

// ds\security\tools\trustdom2\trustdom.c
#define NELEMS(a)  (sizeof(a)/sizeof(a[0]))

// ds\win32\credui\creduit\creduit.cxx
#define PARAMETER_COUNT (sizeof(ParameterDefinitions)/sizeof(ParameterDefinitions[0]))

// ds\win32\ntcrypto\rsaaes\locpolicy.c
#define AlgNm(alg) (sizeof(alg) / sizeof(TCHAR)), TEXT(alg)

// enduser\mapistub\mapistub\msvalidp.h
#define MAKE_PERM_ENTRY(Method, Interface)	 { Interface##_##Method##_Validate, sizeof(Interface##_##Method##_Params) }
#define MAKE_PERM_ENTRY(Method, Interface)	 { DoNothing_Validate, sizeof(Interface##_##Method##_Params), Interface##_##Method##_Thunk }
#define MAKE_TEMP_ENTRY(Method, Interface)	 { Interface##_##Method##_Validate, sizeof(Interface##_##Method##_Params) }

// enduser\netmeeting\as\cpi32\bcd.cpp
#define EXTRACT_LENGTH(buffer, length)                                       \
        length = *buffer++ & MAX_LENGTH_ORDER;                               \
        if (length == 0)                                                     \
        {                                                                    \
            length = *buffer++ + MAX_LENGTH_ORDER + 1;                       \
        }
#define EXTRACT_LENGTH_LITE(buffer, length)                                  \
        length = *buffer++ & MAX_LENGTH_ORDER_LITE;                          \
        if (length == 0)                                                     \
        {                                                                    \
            length = *buffer++ + MAX_LENGTH_ORDER_LITE + 1;                  \
        }

// enduser\netmeeting\as\cpi32\od2.cpp
#define CONVERT_ARRAY(DESTARRAY, SRCARRAY, DESTTYPE, NUMELEMENTS)     \
{                                                           \
    UINT index;                                           \
    for (index=0 ; index<(NUMELEMENTS) ; index++)           \
    {                                                       \
        (DESTARRAY)[index] = (DESTTYPE)(SRCARRAY)[index];   \
    }                                                       \
}
#define CONVERT_ARRAY_INT16_UA(DESTARRAY, SRCARRAY, DESTTYPE, NUMELEMENTS)   \
{                                                           \
    UINT index;                                           \
    TSHR_INT16 value;                                          \
    for (index=0 ; index<(NUMELEMENTS) ; index++)           \
    {                                                       \
        value = EXTRACT_TSHR_INT16_UA((SRCARRAY)+index);      \
        (DESTARRAY)[index] = (DESTTYPE)value;               \
    }                                                       \
}
#define CONVERT_ARRAY_UINT16_UA(DESTARRAY, SRCARRAY, DESTTYPE, NUMELEMENTS)  \
{                                                                            \
    UINT index;                                                            \
    TSHR_UINT16 value;                                                          \
    for (index=0 ; index<(NUMELEMENTS) ; index++)                            \
    {                                                                        \
        value = EXTRACT_TSHR_UINT16_UA((SRCARRAY)+index);                      \
        (DESTARRAY)[index] = (DESTTYPE)((TSHR_INT16)value);                    \
    }                                                                        \
}
#define COPY_DELTA_ARRAY(srcArray, srcArrayType, deltaArray, numElements)  \
{                                                            \
    UINT index;                                            \
    for (index = 0; index < (numElements); index++)          \
    {                                                        \
        (srcArray)[index] = (srcArrayType)                   \
           ((srcArray)[index] + (deltaArray)[index]);        \
    }                                                        \
}

// enduser\netmeeting\as\cpi32\oe2.cpp
#define CHECK_DELTA_ARRAY(ARRAY1, ARRAY2, NUMELEMENTS, DELTASPOSSIBLE)  \
{                                                                       \
    UINT  index;                                                      \
    int   delta;                                                      \
    (DELTASPOSSIBLE) = TRUE;                                            \
    for (index=0 ; index<(NUMELEMENTS) ; index++)                       \
    {                                                                   \
        delta = (ARRAY1)[index] - (ARRAY2)[index];                      \
        if (delta != (int)(TSHR_INT8)delta)                             \
        {                                                               \
            (DELTASPOSSIBLE) = FALSE;                                   \
            break;                                                      \
        }                                                               \
    }                                                                   \
}
#define COPY_TO_DELTA_ARRAY(DESTARRAY, ARRAY1, ARRAY2, NUMELEMENTS)         \
{                                                                           \
    UINT index;                                                           \
    for (index=0 ; index<(NUMELEMENTS) ; index++)                           \
    {                                                                       \
        (DESTARRAY)[index] = (TSHR_INT8)((ARRAY1)[index] - (ARRAY2)[index]);   \
    }                                                                       \
}
#define CONVERT_ARRAY(DESTARRAY, SRCARRAY, DESTTYPE, NUMELEMENTS)     \
{                                                           \
    UINT index;                                           \
    for (index=0 ; index<(NUMELEMENTS) ; index++)           \
    {                                                       \
        (DESTARRAY)[index] = (DESTTYPE)(SRCARRAY)[index];   \
    }                                                       \
}

// enduser\netmeeting\as\h\ch.h
#define IsCacheEntryInTree(pEntry) \
    (((pEntry)->lHeight != 0xFFFF) && ((pEntry)->rHeight != 0xFFFF))

// enduser\netmeeting\av\codecs\intel\g723\g723.h
    #define SIZEOFACMSTR(x)	(sizeof(x)/sizeof(WCHAR))
#define SIZEOF_ARRAY(ar)            (sizeof(ar)/sizeof((ar)[0]))

// enduser\netmeeting\av\codecs\intel\g723\opt.h
#define DECLARE_CHAR(array,size)  \
  char array##_raw[size+8/sizeof(char)]; \
  char *array
#define DECLARE_SHORT(array,size)  \
  short array##_raw[size+8/sizeof(short)]; \
  short *array
#define DECLARE_INT(array,size)  \
  int array##_raw[size+8/sizeof(int)]; \
  int *array

// enduser\netmeeting\av\codecs\lh\lhacm.h
#define SIZEOFACMSTR(x)  (sizeof(x)/sizeof(WCHAR))
#define SIZEOF_ARRAY(ar)                (sizeof(ar)/sizeof((ar)[0]))

// enduser\netmeeting\h\standrd.h
    #define CchMax(pcsz)        (sizeof(pcsz) / sizeof((pcsz)[0]))
#define DECLARE_SAFEARRAY_UNK_PROPPUT( Prop, PROP_DISPID ) \
    STDMETHOD(put_##Prop)( SAFEARRAY newVal )  \
    {\
        HRESULT hr = S_OK;\
        if( S_OK == __ATL_PROP_NOTIFY_EVENT_CLASS::FireOnRequestEdit(GetUnknown(), PROP_DISPID) )\
        {\
            lst<IUnknown*>::iterator I = m_ary##Prop.begin();\
            while( I != m_ary##Prop.end() )\
            {\
                (*I)->Release();\
                ++I;\
            }\
            m_ary##Prop.erase(m_ary##Prop.begin(), m_ary##Prop.end());\
            IUnknown** ppUnkArray;\
            SafeArrayAccessData( &newVal, reinterpret_cast<void**>(&ppUnkArray) );\
            for (UINT x = 0; x < newVal.rgsabound->cElements; x++)\
	        {\
                IUnknown* pUnk = ppUnkArray[x];\
                pUnk->AddRef();\
                m_ary##Prop.push_back( pUnk );\
	        }\
            SafeArrayUnaccessData(&newVal);\
            hr = __ATL_PROP_NOTIFY_EVENT_CLASS::FireOnChanged(GetUnknown(), PROP_DISPID);\
        }\
        return hr;                \
    }
#define DECLARE_SAFEARRAY_UNK_PROPGET( Prop ) \
    STDMETHOD(get_##Prop)( SAFEARRAY *pVal )  \
    {\
        if( pVal )\
        {\
            int nItems = m_ary##Prop.size();\
            SAFEARRAYBOUND bounds = { nItems, 0 };\
            pVal = SafeArrayCreate( VT_UNKNOWN, 1, &bounds );\
            IUnknown** ppUnkArray;\
            SafeArrayAccessData( pVal, reinterpret_cast<void**>(&ppUnkArray) );\
            lst<IUnknown*>::iterator I = m_ary##Prop.begin();\
            for( int i = 0; I != m_ary##Prop.end(); ++I, ++i )\
            {\
                ppUnkArray[i] = (*I);\
            }\
            SafeArrayUnaccessData(pVal);\
        }\
        else\
        {\
            return E_POINTER;\
        }\
        return S_OK;\
    }

// enduser\netmeeting\h\stock.h
#define ARRAY_ELEMENTS(rg)                (sizeof(rg) / sizeof((rg)[0]))

// enduser\netmeeting\t120\mst120\appldr.cpp
#define count_of(array)		(sizeof(array) / sizeof(array[0]))

// enduser\netmeeting\ui\conf\mapiinit.h
#define PROC_MAP_ENTRY( FnName )    { (LPVOID * ) &lpfn##FnName, #FnName },
#define PROC_MAP_ENTRY_EXPLICIT_NAME( pFnName, FnName )    { (LPVOID * ) &lpfn##pFnName, #FnName },

// enduser\netmeeting\ui\conf\nmldap.cpp
#define LDAP_MOD_ENTRY( x ) &LDAPMod_##x
#define LDAP_MOD_ADD_ENTRY( x ) &LDAPMod_add_##x

// enduser\netmeeting\ui\conf\pfndrawd.cpp
#define DRAWDIB_APIFCN_ENTRY(pfn)  {(PVOID *) &DRAWDIB::##pfn, #pfn}

// enduser\netmeeting\ui\conf\pfnsetupapi.cpp
#define SETUPAPI_APIFCN_ENTRYA(pfn)  {(PVOID *) &SETUPAPI::##pfn, #pfn ## "A"}
#define SETUPAPI_APIFCN_ENTRYW(pfn)  {(PVOID *) &SETUPAPI::##pfn, #pfn ## "A"}
#define SETUPAPI_APIFCN_ENTRYNONE(pfn)  {(PVOID *) &SETUPAPI::##pfn, #pfn }

// enduser\netmeeting\ui\conf\pfnver.cpp
#define DLLVER_APIFCN_ENTRY(pfn)  {(PVOID *) &DLLVER::##pfn, #pfn}

// enduser\netmeeting\ui\conf\pfnwininet.cpp
#define WININET_APIFCN_ENTRYA(pfn)  {(PVOID *) &WININET::##pfn, #pfn ## "A"}
#define WININET_APIFCN_ENTRYW(pfn)  {(PVOID *) &WININET::##pfn, #pfn ## "A"}
#define WININET_APIFCN_ENTRYNONE(pfn)  {(PVOID *) &WININET::##pfn, #pfn }

// enduser\netmeeting\ui\conf\pfnwldap.cpp
#define WLDAP_APIFCN_ENTRY(pfn)  {(PVOID *) &WLDAP::##pfn, #pfn}

// enduser\netmeeting\ui\conf\rtoolbar.cpp
#define ZeroArray(_a) ZeroMemory(_a, sizeof(_a))

// enduser\netmeeting\ui\conf\ulswizrd.h
#define MAX_USER_NAME_LENGTH	(MAX_FIRST_NAME_LENGTH + MAX_LAST_NAME_LENGTH + sizeof (TCHAR))

// enduser\netmeeting\ui\msconf\siglobal.h
#define ARRAY_ELEMENTS(rg)   (sizeof(rg) / sizeof((rg)[0]))

// enduser\netmeeting\ui\msconfft\ftui.cpp
#define count_of(array)    (sizeof(array) / sizeof(array[0]))

// enduser\netmeeting\ulsldap\spanyatt.cpp
#define SIZE_ANY_ATTR_PREFIX	(sizeof (c_szAnyAttrPrefix) / sizeof (TCHAR))

// enduser\netmeeting\ulsldap\spils.cpp
#define SIZE_ANY_ATTR_PREFIX	(sizeof (c_szAnyAttrPrefix) / sizeof (TCHAR))

// enduser\speech\build\webupdate\webupdate.cpp
#define DIM(a) (sizeof(a)/sizeof(a[0]))

// enduser\speech\external\include\tapi3.h
#define IEnumAgent_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumAgentSession_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumQueue_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumACDGroup_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumAgentHandler_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

// enduser\speech\external\include\tapi3if.h
#define IEnumTerminal_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumTerminalClass_Next(This,celt,pElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,pElements,pceltFetched)
#define IEnumCall_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumAddress_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumCallHub_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumLocation_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumCallingCard_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumStream_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumSubStream_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

// enduser\speech\sapi\include\spddkhlp.h
#define sp_countof(x) ((sizeof(x) / sizeof(*(x))))

// enduser\speech\sapi\include\speventq.h
#define DECLARE_SPEVENTSOURCE_METHODS(T) \
DECLARE_SPNOTIFYSOURCE_METHODS(T) \
STDMETHODIMP SetInterest(ULONGLONG ullEventInterest, ULONGLONG ullQueuedInterest) \
{ return T._SetInterest(ullEventInterest, ullQueuedInterest); } \
STDMETHODIMP GetEvents(ULONG ulCount, SPEVENT* pEventArray, ULONG * pulFetched) \
{ return T._GetEvents(ulCount, pEventArray, pulFetched); } \
STDMETHODIMP GetInfo(SPEVENTSOURCEINFO *pInfo) \
{ return T._GetInfo(pInfo); }

// enduser\speech\sapi\include\sphelper.h
#define sp_countof(x) ((sizeof(x) / sizeof(*(x))))

// enduser\speech\tts\ms_entropic\perf\ttsperf.cpp
#define DIM(array) (sizeof(array)/sizeof((array)[0]))

// enduser\stuff\hhctrl\funcs.h
#define ELEMENTS(array) (sizeof(array) / sizeof(array[0]))

// enduser\stuff\hhctrl\objcnt.h
#define AUTO_CLASS_COUNT_CHECK(x) \
    CAutoClassCountCheck<x> _dumpclass_##x(#x)
#define CHECK_CLASS_COUNT(x) \
    CClassObjectCount<x>::Check(#x)
#define DUMP_CLASS_COUNT(x)\
    CClassObjectCount<x>::Dump(#x)

// enduser\stuff\hhsetup\funcs.h
#define ELEMENTS(array) (sizeof(array) / sizeof(array[0]))

// enduser\stuff\hhsetup\objcnt.h
#define AUTO_CLASS_COUNT_CHECK(x) \
    CAutoClassCountCheck<x> _dumpclass_##x(#x)
#define CHECK_CLASS_COUNT(x) \
    CClassObjectCount<x>::Check(#x)
#define DUMP_CLASS_COUNT(x)\
    CClassObjectCount<x>::Dump(#x)

// enduser\troubleshoot\control\apgtsinf.cpp
#define CelemArray(rgtype)		(sizeof(rgtype) / sizeof(rgtype[0]))

// enduser\troubleshoot\msinfo\chooser.cpp
	#define LENGTH(x)		(sizeof(x)/sizeof(x[0]))

// enduser\troubleshoot\msinfo\wbemcli.h
#define IWbemObjectSink_Indicate(This,lObjectCount,ppObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,ppObjArray)

// enduser\troubleshoot\msinfo\wbemsvc.h
#define IWbemObjectSink_Indicate(This,lObjectCount,ppObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,ppObjArray)

// enduser\troubleshoot\tshoot\apgtsstr.h
#define _countof(array) (sizeof(array)/sizeof(array[0]))

// enduser\troubleshoot\tshoot\cstd.h
#define CelemArray(rgtype)		(sizeof(rgtype) / sizeof(rgtype[0]))

// enduser\windows.com\lib\detect\osdet.cpp
#define grsize(langid) (sizeof(gr##langid) / sizeof(USER_LANGID))
#define cLangids (sizeof(grLangids) / sizeof(MACH_LANGID))

// enduser\windows.com\lib\download\dlutil.h
#define sizeofSTRW(wsz) (sizeof(wsz) / sizeof(WCHAR))
#define sizeofSTRT(sz)  (sizeof(sz) / sizeof(TCHAR))

// enduser\windows.com\wuv3\cdminc\wustl.h
	#define sizeOfArray(a)  (sizeof(a) / sizeof(a[0]))

// enduser\windows.com\wuv3\wsdu\wsdu\wsdu.h
#define sizeOfArray(a)  (sizeof(a) / sizeof(a[0]))

// enduser\windows.com\wuv3\wsdu\wsdueng\wsdueng.h
#define sizeOfArray(a)  (sizeof(a) / sizeof(a[0]))

// inetcore\connectionwizard\icwdial\globals.h
#define SIZEOF_TCHAR_BUFFER(buf)    ((sizeof(buf) / sizeof(TCHAR)))

// inetcore\connectionwizard\icwutil\dllentry.cpp
#define NUM_CLASS_OBJECTS   sizeof(aClassObjects) / sizeof(aClassObjects[0])

// inetcore\connectionwizard\icwutil\ispdata.cpp
#define ISPDATAELEMENTS_LEN sizeof(aryISPDataElements) / sizeof(ISPDATAELEMENT)

// inetcore\connectionwizard\inetcfg\mailui.cpp
#define INTERNET_MAX_PORT_LENGTH    sizeof(TEXT("123456789"))

// inetcore\connectionwizard\inetcfg\wizdef.h
#define MAX_SCHEME_NAME_LENGTH	sizeof("gopher")

// inetcore\connectionwizard\isign32\extfunc.cpp
#define cRasProc (sizeof(RasProcList) / sizeof(RasProcList[0]))
#define cRasProcNT (sizeof(RasProcListNT) / sizeof(RasProcListNT[0]))
#define cRnaPhProc (sizeof(RnaPhProcList) / sizeof(RnaPhProcList[0]))
#define cInetProc (sizeof(InetProcList) / sizeof(InetProcList[0]))
#define cBrandingProc (sizeof(BrandingProcList) / sizeof(BrandingProcList[0]))

// inetcore\connectionwizard\isign32\isignup.h
#define SIZEOF_TCHAR_BUFFER(buf)    ((sizeof(buf) / sizeof(TCHAR)))

// inetcore\mshtml\btools\tldiff\tldiff.cxx
#define BUFFER_SIZE(buf) (sizeof(buf)/sizeof(buf[0]))

// inetcore\mshtml\btools\tlviewer\cmallspy.h
#define DIM(X) (sizeof(X)/sizeof((X)[0]))

// inetcore\mshtml\iextag\userdata.cxx
#define CACHE_ENTRY_BUFFER_SIZE (sizeof(INTERNET_CACHE_ENTRY_INFO) \
                                 + MAX_PATH * sizeof(TCHAR)\
                                 + INTERNET_MAX_URL_LENGTH * sizeof(TCHAR))

// inetcore\mshtml\src\dxt\proctexe\src\urlarchv.cpp
  #define ARRAYDIM(a)   (sizeof(a) / sizeof(a[0]))

// inetcore\mshtml\src\site\base\element2.cxx
#define IMPLEMENT_PUT_PROP_EX(prop)                 \
    HRESULT hr;                                     \
    if (    (   Tag()==ETAG_BODY                    \
            ||  Tag()==ETAG_FRAMESET)               \
        &&  IsInMarkup()                            \
        &&  GetMarkup()->HasWindow())               \
    {                                               \
        hr = THR(GetMarkup()->Window()->put_##prop(v)); \
        if (hr)                                     \
            goto Cleanup;                           \
    }                                               \
    else                                            \
    {                                               \
        hr = THR(s_propdescCElement##prop.a.HandleCodeProperty( \
                    HANDLEPROP_SET | HANDLEPROP_AUTOMATION |    \
                    (PROPTYPE_VARIANT << 16),                   \
                    &v,                                         \
                    this,                                       \
                    CVOID_CAST(GetAttrArray())));               \
    }                                                           \
Cleanup:                                            \
    RRETURN( SetErrorInfo( hr ));                   \
#define IMPLEMENT_PUT_PROP_EX2(prop)                \
    HRESULT hr;                                     \
    if (    IsInMarkup()                            \
        &&  (   (   (   Tag()==ETAG_BODY                    \
                    ||  Tag()==ETAG_FRAMESET)               \
                &&  !GetMarkup()->IsHtmlLayout())   \
            ||  (   Tag() == ETAG_HTML              \
                &&  GetMarkup()->IsHtmlLayout()))   \
        &&  GetMarkup()->HasWindow())               \
    {                                               \
        hr = THR(GetMarkup()->Window()->put_##prop(v)); \
        if (hr)                                     \
            goto Cleanup;                           \
    }                                               \
    else                                            \
    {                                               \
        hr = THR(s_propdescCElement##prop.a.HandleCodeProperty( \
                    HANDLEPROP_SET | HANDLEPROP_AUTOMATION |    \
                    (PROPTYPE_VARIANT << 16),                   \
                    &v,                                         \
                    this,                                       \
                    CVOID_CAST(GetAttrArray())));               \
    }                                                           \
Cleanup:                                            \
    RRETURN( SetErrorInfo( hr ));                   \
#define IMPLEMENT_GET_PROP_EX(prop)                 \
    HRESULT hr = S_OK;                              \
    if ((Tag() == ETAG_BODY) || Tag() == ETAG_FRAMESET) \
    {                                               \
        if (IsInMarkup())                           \
        {                                           \
            CMarkup *pMarkup = GetMarkup();         \
            if (pMarkup->HasWindow())               \
            {                                       \
                hr = THR(pMarkup->Window()->get_##prop(v));\
                goto Cleanup;                       \
            }                                       \
        }                                           \
        V_VT(v) = VT_EMPTY;                         \
    }                                               \
    else                                            \
    {                                               \
        hr = THR(s_propdescCElement##prop.a.HandleCodeProperty(     \
                HANDLEPROP_AUTOMATION | (PROPTYPE_VARIANT << 16),   \
                v,                                                  \
                this,                                               \
                CVOID_CAST(GetAttrArray())));                       \
    }                                               \
Cleanup:                                            \
    RRETURN( SetErrorInfo( hr ));                   \
#define IMPLEMENT_GET_PROP_EX2(prop)                \
    HRESULT hr = S_OK;                              \
    if  (   (   Tag() == ETAG_HTML                  \
            &&  IsInMarkup()                        \
            &&  GetMarkup()->IsHtmlLayout())\
        ||  (   (   Tag() == ETAG_BODY              \
                ||  Tag() == ETAG_FRAMESET)         \
            && !(   IsInMarkup()                    \
                &&  GetMarkup()->IsHtmlLayout())))  \
    {                                               \
        if (IsInMarkup())                           \
        {                                           \
            CMarkup *pMarkup = GetMarkup();         \
            if (pMarkup->HasWindow())               \
            {                                       \
                hr = THR(pMarkup->Window()->get_##prop(v));\
                goto Cleanup;                       \
            }                                       \
        }                                           \
        V_VT(v) = VT_EMPTY;                         \
    }                                               \
    else                                            \
    {                                               \
        hr = THR(s_propdescCElement##prop.a.HandleCodeProperty(     \
                HANDLEPROP_AUTOMATION | (PROPTYPE_VARIANT << 16),   \
                v,                                                  \
                this,                                               \
                CVOID_CAST(GetAttrArray())));                       \
    }                                               \
Cleanup:                                            \
    RRETURN( SetErrorInfo( hr ));                   \

// inetcore\mshtml\src\site\builtin\table.cxx
#define PRINTLN(f) WriteHelp(pF, _T("<0s>")_T(##f)_T("\n"), &g_achTabs[ARRAY_SIZE(g_achTabs) - iTabs]

// inetcore\mshtml\src\site\display\pubprint.hxx
#define cwSDIB                          (sizeof(SDIB) / sizeof(short))

// inetcore\mshtml\src\site\table\ltable.cxx
#define PRINTLN(f) WriteHelp(pF, _T("<0s>")_T(##f)_T("\n"), &g_achTabs[ARRAY_SIZE(g_achTabs) - iTabs]

// inetcore\mshtml\src\time\anim\animutil.h
#define SIZE_OF_VALUE_TABLE (sizeof(rgPropOr) / sizeof(VALUE_PAIR))
#define SIZE_OF_CONVERSION_TABLE (sizeof(rgPixelConv) / sizeof(CONVERSION_PAIR))

// inetcore\mshtml\src\time\anim\colorutil.cpp
#define RGB_STRING_LENGTH           (7)
#define RGB_STRING_LENGTH2          (4)
#define SIZE_OF_COLOR_TABLE (sizeof(rgColorNames) / sizeof(COLORVALUE_PAIR))

// inetcore\mshtml\src\time\media\mediaelm.cpp
#define SIZE_OF_VALUE_TABLE (sizeof(rgPropOr) / sizeof(VALUE_PAIR))
#define SIZE_OF_CONVERSION_TABLE (sizeof(rgPixelConv) / sizeof(CONVERSION_PAIR))

// inetcore\mshtml\src\time\util\loader.cpp
#define AUDIOVBSCRIPT_LEN (sizeof(AUDIOVBSCRIPT_TEXT)/sizeof(wchar_t))

// inetcore\mshtml\test\reflectr\pch.h
#define ARRAYOF( _a )  ( sizeof( _a ) / sizeof( _a[0] ) )

// inetcore\mshtml\tools\make_altfont.cxx
#define NUM sizeof(anpTable) / sizeof(WCHAR *)

// inetcore\mshtml\tried\triedctl\atlctl.h
#define PROP_ENTRY(szDesc, dispid, clsid) \
		{OLESTR(szDesc), dispid, &clsid, &IID_IDispatch},
#define PROP_ENTRY_EX(szDesc, dispid, clsid, iidDispatch) \
		{OLESTR(szDesc), dispid, &clsid, &iidDispatch},

// inetcore\mshtml\tried\triedctl\plgprot.h
#define dimensionof(a)  (sizeof(a)/sizeof(*(a)))

// inetcore\mshtml\tried\triedit\table.cpp
#define RW_Entry(string, attribute) \
	_T( #string ), sizeof( #string ) - 1, attribute

// inetcore\mshtml\tried\triedit\table.h
#define CELEM_ARRAY(a)  (sizeof(a) / sizeof(a[0]))

// inetcore\outlookexpress\cryptdlg\select.cpp
#define SPC_FORMAT_FUNC_COUNT (sizeof(SpcFormatFuncTable) / sizeof(SpcFormatFuncTable[0]))

// inetcore\outlookexpress\iecont\hotlinks.cpp
#define CharSizeOf_A(x)	(sizeof(x) / sizeof(CHAR))
#define CharSizeOf_W(x)	(sizeof(x) / sizeof(WCHAR))

// inetcore\outlookexpress\inetcomm\mimeedit\fmtbar.cpp
#define ctbbutton           (sizeof(rgtbbutton) / sizeof(TBBUTTON))

// inetcore\outlookexpress\mailnews\common\about.cpp
#define NUM_DLLS (sizeof(rgszDll)/sizeof(char *))

// inetcore\outlookexpress\mailnews\common\seclabel.h
#define DimensionOf(_array)        (sizeof(_array) / sizeof((_array)[0]))

// inetcore\outlookexpress\mailnews\common\util.h
#define BUTTONCOUNT(tb) (sizeof(tb) / sizeof(TBBUTTON))

// inetcore\outlookexpress\mailnews\mail\adbar.h
#define CCH_ADPANE_OFF               (sizeof(c_szAdPaneOff) / sizeof(*c_szAdPaneOff))
#define CCH_ADPANE_ON                (sizeof(c_szAdPaneOn) / sizeof(*c_szAdPaneOn))
#define CCH_REDIRECT_ADURL           (sizeof(c_szRedirectAdUrl) / sizeof(*c_szRedirectAdUrl))
#define CCH_ADSVR_TOKEN_FORMAT       (sizeof(c_szAdSvrFormat) / sizeof(*c_szAdSvrFormat))
#define CCH_OTHER_FORMAT             (sizeof(c_szAdOther) / sizeof(*c_szAdOther))
#define CCH_AD_OTHER_FORMAT          (sizeof(c_szAdOtherFormat) / sizeof(*c_szAdOtherFormat))

// inetcore\outlookexpress\mailnews\mail\options.cpp
#define CSIGFILTER  (sizeof(c_rgidsFilter) / sizeof(int))

// inetcore\outlookexpress\msoert\oertutil.cpp
    #define NUM_DEFAULT_MAPS (sizeof(SysColorMap)/sizeof(COLORMAP))

// inetcore\outlookexpress\wabw\wabapi\_iprop.h
#define	dimensionof(rg)			(sizeof(rg)/sizeof(*(rg)))
#define	dimensionof(rg)			(sizeof(rg)/sizeof(*(rg)))

// inetcore\outlookexpress\wabw\wabapi\_mapiprv.h
#define CharSizeOf_A(x)	(sizeof(x) / sizeof(CHAR))
#define CharSizeOf_W(x)	(sizeof(x) / sizeof(WCHAR))

// inetcore\outlookexpress\wabw\wabapi\mpswab.h
#define SIZEOF_WAB_ENTRYID sizeof(WAB_ENTRYID)

// inetcore\outlookexpress\wabw\wabapi\msvalid.c
#define MAKE_PERM_ENTRY(Method, Interface)	 { Interface##_##Method##_Validate, sizeof(Interface##_##Method##_Params) }
#define MAKE_TEMP_ENTRY(Method, Interface)	 { Interface##_##Method##_Validate, sizeof(Interface##_##Method##_Params) }
#define MAX_VAL			sizeof(hrResultTable) / sizeof(hrResultTable[0])

// inetcore\outlookexpress\wabw\wabapi\runt.c
#define cbMinEntryID	(CbNewENTRYID(sizeof(MAPIUID)))

// inetcore\passport\ppdefs.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// inetcore\published\inc\dxclrhlp.h
#define SIZE_OF_COLOR_TABLE (sizeof(rgColorNames) / sizeof(COLORVALUE_PAIR))
#define SIZE_OF_SYSTEM_COLOR_TABLE (sizeof(rgSystemColorNames) / sizeof(COLORVALUE_PAIR))

// inetcore\published\inc\platform.h
#define PALETTE_ENTRY( r, g, b, f )  { f, b, g, r }
#define PALETTE_ENTRY( r, g, b, f )  { r, g, b, f }

// inetcore\setup\ieak5\cd\autorun\autorun.c
#define AUTORUN_NUM_BUTTONS (sizeof(g_ButtonInfo)/sizeof(g_ButtonInfo[0]))

// inetcore\setup\ieak5\ieakfont\ieakfont.cpp
#define countof(a)     (sizeof(a)/sizeof((a)[0]))

// inetcore\urlmon\compress\gzip\inftree.c
#define NUM_CODE_LENGTH_ORDER_CODES (sizeof(g_CodeOrder)/sizeof(g_CodeOrder[0]))

// inetcore\urlmon\download\cdl.h
#define ARRAY_ELEMENTS(array) \
	(sizeof(array)/sizeof(array[0]))

// inetcore\urlmon\download\webjit.cpp
#define ARRAY_ELEMENTS(array) \
    (sizeof(array)/sizeof(array[0]))

// inetcore\urlmon\utils\registry.cxx
#define ARRAY_ELEMENTS(array) \
    (sizeof(array)/sizeof(array[0]))

// inetcore\urlmon\zones\secmgr.cxx
#define ARRAY_ELEMENTS(array) \
    (sizeof(array)/sizeof((array)[0]))

// inetcore\urlmon\zones\zoneutil.h
#define CSTRLENW(str)       (sizeof(str)/sizeof(TCHAR) - 1)

// inetcore\winhttp\v5.1\http\headers.cxx
#define MAKE_VERSION_ENTRY(string)  string, sizeof(string) - 1

// inetcore\winhttp\v5.1\inc\caddrlst.hxx
#define CSADDR_BUFFER_LENGTH    (sizeof(CSADDR_INFO) + 128)

// inetcore\winhttp\v5.1\inc\macros.h
#define ARRAY_ELEMENTS(array) \
    (sizeof(array)/sizeof(array[0]))

// inetcore\winhttp\v5.1\inc\private.h
#define INTERNET_MAX_URL_LENGTH         (INTERNET_MAX_SCHEME_LENGTH \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// inetcore\winhttp\v5.1\inc\serialst.h
#define ElementsOnSerializedList(list) \
    (list)->ElementCount

// inetcore\winhttp\v5.1\inc\splugin.hxx
#define ARRAY_ELEMENTS(rg)                (sizeof(rg) / sizeof((rg)[0]))

// inetcore\winhttp\v5.1\inc\thrdinfo.h
#define _InternetIncNestingCount() \
    lpThreadInfo->NestedRequests++;
#define _InternetDecNestingCount(dwNestingLevel) \
    lpThreadInfo->NestedRequests -= dwNestingLevel;

// inetcore\winhttp\v5.1\inc\util.h
#define DLL_ENTRY_POINT_ELEMENT(name) \
    # name, (FARPROC *)&_I_ ## name

// inetcore\winhttp\v5\http\headers.cxx
#define MAKE_VERSION_ENTRY(string)  string, sizeof(string) - 1

// inetcore\winhttp\v5\inc\caddrlst.hxx
#define CSADDR_BUFFER_LENGTH    (sizeof(CSADDR_INFO) + 128)

// inetcore\winhttp\v5\inc\macros.h
#define ARRAY_ELEMENTS(array) \
    (sizeof(array)/sizeof(array[0]))

// inetcore\winhttp\v5\inc\private.h
#define INTERNET_MAX_URL_LENGTH         (INTERNET_MAX_SCHEME_LENGTH \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// inetcore\winhttp\v5\inc\serialst.h
#define ElementsOnSerializedList(list) \
    (list)->ElementCount

// inetcore\winhttp\v5\inc\splugin.hxx
#define ARRAY_ELEMENTS(rg)                (sizeof(rg) / sizeof((rg)[0]))

// inetcore\winhttp\v5\inc\thrdinfo.h
#define _InternetIncNestingCount() \
    lpThreadInfo->NestedRequests++;
#define _InternetDecNestingCount(dwNestingLevel) \
    lpThreadInfo->NestedRequests -= dwNestingLevel;

// inetcore\winhttp\v5\inc\util.h
#define DLL_ENTRY_POINT_ELEMENT(name) \
    # name, (FARPROC *)&_I_ ## name

// inetcore\winhttp\v5\urlcache\cachedef.h
#define MAX_SIG_SIZE                     (sizeof(CACHE_SIGNATURE) / sizeof(TCHAR))

// inetcore\wininet\dll\cookimp.cxx
#define LENGTHOFTSTR( x ) (sizeof(x) / sizeof(TCHAR))

// inetcore\wininet\dll\iedial.cxx
#define NUM_DIALPROPS (sizeof(g_PropertyMap) / sizeof(PROPMAP))
#define NUM_IDS      (sizeof(uIDs) / sizeof(UINT))
#define NUM_CDH_IDS  (sizeof(uCDHIDs) / sizeof(UINT))

// inetcore\wininet\dll\readhtml.cxx
#define FTP_WELCOME_INTRO_LENGTH    (sizeof(FTP_WELCOME_INTRO) - 1)

// inetcore\wininet\dll\test\cernprox\cernprox.c
#define NUMBER_OF_DEFAULT_URLS  (sizeof(default_urls)/sizeof(default_urls[0]))

// inetcore\wininet\dll\test\openurl\openurl.c
#define NUMBER_OF_DEFAULT_URLS  (sizeof(default_urls)/sizeof(default_urls[0]))

// inetcore\wininet\gopher\buffer.h
#define LOOK_AHEAD_LENGTH   sizeof("+4294967296\r\n")   // 12

// inetcore\wininet\gopher\gfrapip.h
#define GOPHER_REQUEST_TERMINATOR_LENGTH        (sizeof(GOPHER_REQUEST_TERMINATOR) - 1)
#define GOPHER_DOT_TERMINATOR_LENGTH            (sizeof(GOPHER_DOT_TERMINATOR) - 1)
#define GOPHER_PLUS_INDICATOR_LENGTH            (sizeof(GOPHER_PLUS_INDICATOR) - 1)
#define GOPHER_PLUS_ITEM_INFO_LENGTH            (sizeof(GOPHER_PLUS_ITEM_INFO) - 1)
#define GOPHER_PLUS_INFO_REQUEST_LENGTH         (sizeof(GOPHER_PLUS_INFO_REQUEST) - 1)
#define GOPHER_PLUS_DIRECTORY_REQUEST_LENGTH    (sizeof(GOPHER_PLUS_DIRECTORY_REQUEST) - 1)
#define GOPHER_PLUS_INFO_TOKEN_LENGTH           (sizeof(GOPHER_PLUS_INFO_TOKEN) - 1)
#define GOPHER_PLUS_ADMIN_TOKEN_LENGTH          (sizeof(GOPHER_PLUS_ADMIN_TOKEN) - 1)
#define GOPHER_PLUS_VIEWS_TOKEN_LENGTH          (sizeof(GOPHER_PLUS_VIEWS_TOKEN) - 1)

// inetcore\wininet\http\hashgen\hashgen.cpp
#define DIM(x)	(sizeof(x) / sizeof(x[0]))

// inetcore\wininet\http\headers.cxx
#define MAKE_VERSION_ENTRY(string)  string, sizeof(string) - 1

// inetcore\wininet\inc\caddrlst.hxx
#define CSADDR_BUFFER_LENGTH    (sizeof(CSADDR_INFO) + 128)

// inetcore\wininet\inc\macros.h
#define ARRAY_ELEMENTS(array) \
    (sizeof(array)/sizeof(array[0]))

// inetcore\wininet\inc\serialst.h
#define ElementsOnSerializedList(list) \
    (list)->ElementCount

// inetcore\wininet\inc\splugin.hxx
#define ARRAY_ELEMENTS(rg)                (sizeof(rg) / sizeof((rg)[0]))

// inetcore\wininet\inc\thrdinfo.h
#define _InternetIncNestingCount() \
    lpThreadInfo->NestedRequests++;
#define _InternetDecNestingCount(dwNestingLevel) \
    lpThreadInfo->NestedRequests -= dwNestingLevel;

// inetcore\wininet\inc\util.h
#define DLL_ENTRY_POINT_ELEMENT(name) \
    # name, (FARPROC *)&_I_ ## name

// inetcore\wininet\urlcache\cachedef.h
#define MAX_SIG_SIZE                     (sizeof(CACHE_SIGNATURE) / sizeof(TCHAR))

// inetsrv\iis\admin\adsi\adsiis\common.cxx
#define MAX_FILTERS  (sizeof(Filters)/sizeof(FILTERS))

// inetsrv\iis\admin\adsi\helper\include\netolary.hxx
#define DECLARE_ADsDATAARY(_Cls, _Ty, _pTy)                   \
    class _Cls : public CADsAry                               \
    {                                                           \
    public:                                                     \
        _Cls(void) : CADsAry() { ; }                          \
        _Ty& operator[] (int i) { return * (_pTy) Deref(sizeof(_Ty), i); }   \
        operator _pTy(void) { return (_pTy) _pv; }              \
        _Cls(const _Cls &);                                     \
        _Cls& operator=(const _Cls &);                          \
                                                                \
        HRESULT     EnsureSize(int c)                           \
                        { return CADsAry::EnsureSize(sizeof(_Ty), c); }  \
        HRESULT     AppendIndirect(void * pv)                   \
                        { return CADsAry::AppendIndirect(sizeof(_Ty), pv); } \
        HRESULT     InsertIndirect(int i, void * pv)            \
                        { return CADsAry::InsertIndirect(sizeof(_Ty), i, pv); } \
        int         FindIndirect(void ** ppv)                   \
                        { return CADsAry::FindIndirect(sizeof(_Ty), ppv); } \
                                                                \
        void        Delete(int i)                               \
                        { CADsAry::Delete(sizeof(_Ty), i); }      \
        void        BringToFront(int i)                         \
                        { CADsAry::BringToFront(sizeof(_Ty), i); } \
        void        SendToBack(int i)                           \
                        { CADsAry::SendToBack(sizeof(_Ty), i); }  \
                                                                \
        HRESULT     Copy(const CADsAry& ary, BOOL fAddRef)    \
                        { return CADsAry::Copy(sizeof(_Ty), ary, fAddRef); } \
                                                                \
        HRESULT     EnumElements(                               \
                            REFIID iid,                         \
                            void ** ppv,                        \
                            BOOL fAddRef,                       \
                            BOOL fCopy = TRUE,                  \
                            BOOL fDelete = TRUE)                \
                        { return CADsAry::EnumElements(sizeof(_Ty), iid, ppv, fAddRef, fCopy, fDelete); } \
                                                                \
        HRESULT     EnumVARIANT(                                \
                            VARTYPE vt,                         \
                            IEnumVARIANT ** ppenum,             \
                            BOOL fCopy = TRUE,                  \
                            BOOL fDelete = TRUE)                \
                        { return CADsAry::EnumVARIANT(sizeof(_Ty), vt, ppenum, fCopy, fDelete); } \
    };

// inetsrv\iis\admin\adsi\oleds2.0\include\netolary.hxx
#define DECLARE_ADsDATAARY(_Cls, _Ty, _pTy)                   \
    class _Cls : public CADsAry                               \
    {                                                           \
    public:                                                     \
        _Cls(void) : CADsAry() { ; }                          \
        _Ty& operator[] (int i) { return * (_pTy) Deref(sizeof(_Ty), i); }   \
        operator _pTy(void) { return (_pTy) _pv; }              \
        _Cls(const _Cls &);                                     \
        _Cls& operator=(const _Cls &);                          \
                                                                \
        HRESULT     EnsureSize(int c)                           \
                        { return CADsAry::EnsureSize(sizeof(_Ty), c); }  \
        HRESULT     AppendIndirect(void * pv)                   \
                        { return CADsAry::AppendIndirect(sizeof(_Ty), pv); } \
        HRESULT     InsertIndirect(int i, void * pv)            \
                        { return CADsAry::InsertIndirect(sizeof(_Ty), i, pv); } \
        int         FindIndirect(void ** ppv)                   \
                        { return CADsAry::FindIndirect(sizeof(_Ty), ppv); } \
                                                                \
        void        Delete(int i)                               \
                        { CADsAry::Delete(sizeof(_Ty), i); }      \
        void        BringToFront(int i)                         \
                        { CADsAry::BringToFront(sizeof(_Ty), i); } \
        void        SendToBack(int i)                           \
                        { CADsAry::SendToBack(sizeof(_Ty), i); }  \
                                                                \
        HRESULT     Copy(const CADsAry& ary, BOOL fAddRef)    \
                        { return CADsAry::Copy(sizeof(_Ty), ary, fAddRef); } \
                                                                \
        HRESULT     EnumElements(                               \
                            REFIID iid,                         \
                            void ** ppv,                        \
                            BOOL fAddRef,                       \
                            BOOL fCopy = TRUE,                  \
                            BOOL fDelete = TRUE)                \
                        { return CADsAry::EnumElements(sizeof(_Ty), iid, ppv, fAddRef, fCopy, fDelete); } \
                                                                \
        HRESULT     EnumVARIANT(                                \
                            VARTYPE vt,                         \
                            IEnumVARIANT ** ppenum,             \
                            BOOL fCopy = TRUE,                  \
                            BOOL fDelete = TRUE)                \
                        { return CADsAry::EnumVARIANT(sizeof(_Ty), vt, ppenum, fCopy, fDelete); } \
    };

// inetsrv\iis\admin\common2\mdkeys.cpp
#define NUM_ENTRIES (sizeof(CMetaKey::s_rgMetaTable) / sizeof(CMetaKey::s_rgMetaTable[0]))

// inetsrv\iis\admin\common\mdkeys.cpp
#define NUM_ENTRIES (sizeof(CMetaKey::s_rgMetaTable) / sizeof(CMetaKey::s_rgMetaTable[0]))

// inetsrv\iis\admin\snapin\mmmdlg.cpp
#define NUM_COLUMNS(cols) (sizeof(cols) / sizeof(cols[0]))

// inetsrv\iis\admin\snapin\supdlgs.cpp
#define NUM_COLUMNS (sizeof(g_aColumns) / sizeof(g_aColumns[0]))

// inetsrv\iis\admin\snapin\usersess.cpp
#define NUM_COLUMNS (sizeof(g_aColumns) / sizeof(g_aColumns[0]))

// inetsrv\iis\config\src\appcenter\inc\acsmacro.h
#define ARRAYELEMENTS(array) (sizeof(array)/sizeof(array[0]))
#define sizeofw(param)                  (sizeof(param) / sizeof(WCHAR))
#define lengthofw(param)                (sizeofw(param) - 1)
#define lengthof(param)                 (sizeof(param) - 1)

// inetsrv\iis\config\src\complib\inc\tigger.h
		#define NumItems(x) (sizeof(x)/sizeof(x[0]))

// inetsrv\iis\config\src\complib\inc\utilcode.h
#define NumItems(s) (sizeof(s) / sizeof(s[0]))
#define _tsizeof(str) (sizeof(str) / sizeof(TCHAR))

// inetsrv\iis\config\src\inc\appcntadm.h
#define IAppCenterCol_Next(This,celt,pElements)	\
    (This)->lpVtbl -> Next(This,celt,pElements)
#define IAppCenterCol_get_Xml(This,celt,varNames,pXmlElements)	\
    (This)->lpVtbl -> get_Xml(This,celt,varNames,pXmlElements)

// inetsrv\iis\config\src\inc\iiscrypt.h
#define IISCryptoGetBlobLength(p) (((p)->BlobDataLength) + sizeof(*(p)))

// inetsrv\iis\config\src\stores\regdb\regdbshared.h
#define NumItems(s) (sizeof(s) / sizeof(s[0]))

// inetsrv\iis\config\src\test\tuxtests\globals.h
#define countof(x)  (sizeof(x)/sizeof(*(x)))

// inetsrv\iis\config\src\wmi\atl30\atlcom.h
#define PROP_ENTRY(szDesc, dispid, clsid) \
		{OLESTR(szDesc), dispid, &clsid, &IID_IDispatch, 0, 0, 0},
#define PROP_ENTRY_EX(szDesc, dispid, clsid, iidDispatch) \
		{OLESTR(szDesc), dispid, &clsid, &iidDispatch, 0, 0, 0},

// inetsrv\iis\config\src\wmi\psdk_inc\wbemcli.h
#define IWbemObjectSink_Indicate(This,lObjectCount,apObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,apObjArray)
#define IWbemSecureObjectSink_Indicate(This,lObjectCount,apObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,apObjArray)
#define IWbemEventSink_Indicate(This,lObjectCount,apObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,apObjArray)

// inetsrv\iis\config\src\wmi\psdk_inc\wbemdisp.h
#define ISWbemObject_get_Derivation_(This,strClassNameArray)	\
    (This)->lpVtbl -> get_Derivation_(This,strClassNameArray)
#define ISWbemProperty_get_IsArray(This,bIsArray)	\
    (This)->lpVtbl -> get_IsArray(This,bIsArray)
#define ISWbemPropertySet_Add(This,strName,iCIMType,bIsArray,iFlags,objWbemProperty)	\
    (This)->lpVtbl -> Add(This,strName,iCIMType,bIsArray,iFlags,objWbemProperty)
#define ISWbemLastError_get_Derivation_(This,strClassNameArray)	\
    (This)->lpVtbl -> get_Derivation_(This,strClassNameArray)
#define ISWbemObjectEx_get_Derivation_(This,strClassNameArray)	\
    (This)->lpVtbl -> get_Derivation_(This,strClassNameArray)

// inetsrv\iis\config\src\wmi\utils\wmisec\wbemcli.h
#define IWbemObjectSink_Indicate(This,lObjectCount,apObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,apObjArray)
#define IWbemSecureObjectSink_Indicate(This,lObjectCount,apObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,apObjArray)
#define IWbemEventSink_Indicate(This,lObjectCount,apObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,apObjArray)
#define IWbemObjectSinkEx_Indicate(This,lObjectCount,apObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,apObjArray)
#define IWbemComBinding_GetCLSIDArrayForIID(This,pSvcEx,pObject,riid,lFlags,pCtx,pArray)	\
    (This)->lpVtbl -> GetCLSIDArrayForIID(This,pSvcEx,pObject,riid,lFlags,pCtx,pArray)
#define IWbemComBinding_GetCLSIDArrayForNames(This,pSvcEx,pObject,rgszNames,cNames,lcid,pCtx,lFlags,pArray)	\
    (This)->lpVtbl -> GetCLSIDArrayForNames(This,pSvcEx,pObject,rgszNames,cNames,lcid,pCtx,lFlags,pArray)

// inetsrv\iis\iisrearc\core\ap\was\dll\virtual_site.h
#define CCH_IN_VIRTUAL_SITE_DIRECTORY_NAME_PREFIX (sizeof(VIRTUAL_SITE_DIRECTORY_NAME_PREFIX) / sizeof(WCHAR)) - 1

// inetsrv\iis\iisrearc\core\common\dtext\help.cxx
#define NUM_HELP_MAPS ( sizeof(HelpMaps) / sizeof(HelpMaps[0]) )

// inetsrv\iis\iisrearc\core\common\dtext\ver.cxx
#define NUM_LABELS ( sizeof(VersionLabels) / sizeof(VersionLabels[0]) )

// inetsrv\iis\iisrearc\core\common\util\datetime.cxx
# define CdtCountAccesses()  InterlockedIncrement( &m_nAccesses)
# define CdtCountMisses()    InterlockedIncrement( &m_nMisses)

// inetsrv\iis\iisrearc\core\iiswp\davpropbag.cxx
#define CchConstString(_s)  ((sizeof(_s)/sizeof(_s[0])) - 1)

// inetsrv\iis\iisrearc\core\snmp\dll\mib.h
#define OID_SIZEOF( uiArray )      ( sizeof( uiArray) / sizeof(UINT) )

// inetsrv\iis\iisrearc\core\staticfiles\dav\davpropbag.cxx
#define CchConstString(_s)  ((sizeof(_s)/sizeof(_s[0])) - 1)

// inetsrv\iis\iisrearc\core\w3ctrs\w3data.h
#define NUMBER_OF_W3_COUNTERS ((sizeof(W3_DATA_DEFINITION) -        \
                                  sizeof(PERF_OBJECT_TYPE)) /           \
                                  sizeof(PERF_COUNTER_DEFINITION))
#define NUMBER_OF_W3_GLOBAL_COUNTERS ((sizeof(W3_GLOBAL_DATA_DEFINITION) -        \
                                        sizeof(PERF_OBJECT_TYPE)) /           \
                                         sizeof(PERF_COUNTER_DEFINITION))

// inetsrv\iis\iisrearc\core\wp\modules\static\ulutil.cxx
#define SetStringAndLength( result, cbLen, cString)     \
    {                                                   \
        (result) = (cString);                           \
        (cbLen) = sizeof(cString)-1;                    \
    }

// inetsrv\iis\iisrearc\core\wp\ulsim\parse.c
#define NUMBER_FAST_VERB_ENTRIES    (sizeof(FastVerbTable)/sizeof(FAST_VERB_ENTRY))
#define NUMBER_LONG_VERB_ENTRIES    (sizeof(LongVerbTable)/sizeof(LONG_VERB_ENTRY))
#define NUMBER_HEADER_MAP_ENTRIES   (sizeof(HeaderMapTable)/sizeof(HEADER_MAP_ENTRY))

// inetsrv\iis\iisrearc\core\wp\ulsim\parsep.h
#define MAX_VERB_LENGTH     (sizeof("PROPPATCH"))
#define MAX_HEADER_LENGTH       (MAX_HEADER_LONG_COUNT * sizeof(ULONGLONG))
#define CREATE_HEADER_MAP_ENTRY(header, ID, handler) { \
    \
    sizeof(#header) - 1, \
    ((sizeof(#header) - 1) / 8) + \
        (((sizeof(#header) - 1) % 8) == 0 ? 0 : 1), \
    (((sizeof(#header) - 1) / 8) + \
        (((sizeof(#header) - 1) % 8) == 0 ? 0 : 1)) * 8, \
    { #header }, \
    { 0, 0, 0}, \
    ID, \
    handler, \
    }
#define CREATE_LONG_VERB_ENTRY(verb)    { sizeof(#verb) - 1, \
                                             #verb,\
                                             UlHttpVerb##verb }

// inetsrv\iis\iisrearc\core\wp\ulsim\ulchannel.cxx
# define TEST_REQUEST_LENGTH  (sizeof(UL_HTTP_REQUEST) + sizeof( TEST_URL))

// inetsrv\iis\iisrearc\ul\api\precomp.h
#define DIMENSION( array )                                      \
    ( sizeof(array) / sizeof((array)[0]) )

// inetsrv\iis\iisrearc\ul\drv\cache.h
#define IS_VALID_URI_CACHE_ENTRY(pEntry) \
    ((pEntry) != NULL  &&  UL_URI_CACHE_ENTRY_POOL_TAG == (pEntry)->Signature)

// inetsrv\iis\iisrearc\ul\drv\cgroupp.h
#define IS_VALID_TREE_ENTRY(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_CG_TREE_ENTRY_POOL_TAG))
#define HTTPS_WILD_PREFIX_LENGTH    (sizeof(HTTPS_WILD_PREFIX)-sizeof(WCHAR))
#define HTTP_WILD_PREFIX_LENGTH     (sizeof(HTTP_WILD_PREFIX)-sizeof(WCHAR))
#define HTTP_IP_PREFIX_LENGTH       (sizeof(HTTP_IP_PREFIX)-sizeof(WCHAR))
#define HTTPS_IP_PREFIX_LENGTH      (sizeof(HTTPS_IP_PREFIX)-sizeof(WCHAR))

// inetsrv\iis\iisrearc\ul\drv\counters.h
#define IS_VALID_SITE_COUNTER_ENTRY( entry )                                  \
    ( (entry != NULL) && ((entry)->Signature == UL_SITE_COUNTER_ENTRY_POOL_TAG) )

// inetsrv\iis\iisrearc\ul\drv\fastio.h
#define IS_LENGTH_SPECIFIED( pKnownHeaders )                                \
    (pKnownHeaders[HttpHeaderContentLength].RawValueLength > 0)

// inetsrv\iis\iisrearc\ul\drv\filecache.h
#define IS_VALID_FILE_CACHE_ENTRY( entry )                                  \
    ( (entry)->Signature == UL_FILE_CACHE_ENTRY_SIGNATURE )

// inetsrv\iis\iisrearc\ul\drv\httpconn.h
#define IS_VALID_CONNECTION_COUNT_ENTRY( entry )                            \
    ( (entry != NULL) && ((entry)->Signature == UL_CONNECTION_COUNT_ENTRY_POOL_TAG) )

// inetsrv\iis\iisrearc\ul\drv\misc.h
#define DIMENSION(x) ( sizeof(x) / sizeof(x[0]) )
#define MAX_IPV4_STRING_LENGTH  sizeof("255.255.255.255")

// inetsrv\iis\iisrearc\ul\drv\parse.cxx
#define NUMBER_FAST_VERB_ENTRIES    (sizeof(FastVerbTable)/sizeof(FAST_VERB_ENTRY))
#define NUMBER_LONG_VERB_ENTRIES    (sizeof(LongVerbTable)/sizeof(LONG_VERB_ENTRY))

// inetsrv\iis\iisrearc\ul\drv\parse.h
#define DATE_HDR_LENGTH (sizeof("Mon, 05 May 1975 00:05:00 GMT") - sizeof(CHAR))

// inetsrv\iis\iisrearc\ul\drv\parsep.h
#define MAX_VERB_LENGTH     (sizeof("PROPPATCH"))
#define MAX_HEADER_LENGTH               (MAX_HEADER_LONG_COUNT * sizeof(ULONGLONG))
#define DEFAULT_SERVER_HDR_LENGTH   (sizeof(DEFAULT_SERVER_HDR) - sizeof(CHAR))
#define CONN_KEEPALIVE_HDR_LENGTH   (sizeof(CONN_KEEPALIVE_HDR) - sizeof(CHAR))
#define CREATE_HEADER_MAP_ENTRY(header, ID, auto, serverhandler, clienthandler, HintIndex)\
{                                                        \
                                                         \
    sizeof(#header) - 1,                                 \
    ((sizeof(#header) - 1) / 8) +                        \
        (((sizeof(#header) - 1) % 8) == 0 ? 0 : 1),      \
    (((sizeof(#header) - 1) / 8) +                       \
        (((sizeof(#header) - 1) % 8) == 0 ? 0 : 1)) * 8, \
    { #header },                                         \
    { 0, 0, 0},                                          \
    { #header },                                         \
    ID,                                                  \
    auto,                                                \
    serverhandler,                                       \
    clienthandler,                                       \
    HintIndex                                            \
    }
#define CREATE_LONG_VERB_ENTRY(verb)    { sizeof(#verb) - 1, \
                                             #verb,\
                                             HttpVerb##verb }

// inetsrv\iis\iisrearc\ul\drv\pipelinep.h
#define PIPELINE_LENGTH( queues, threads )                                  \
    ( sizeof(UL_PIPELINE)                                                  \
        - sizeof(UL_PIPELINE_QUEUE)                                        \
        + sizeof(UL_PIPELINE_RARE)                                         \
        + ( (ULONG)(queues) * sizeof(UL_PIPELINE_QUEUE) )                  \
        + ( (ULONG)(threads) * sizeof(UL_PIPELINE_THREAD_DATA) ) )

// inetsrv\iis\iisrearc\ul\test\dll\precomp.h
#define FILENAME_BUFFER_LENGTH  (MAX_PATH + sizeof("\\??\\"))

// inetsrv\iis\iisrearc\ul\test\dll\ulutil.c
#define NUM_HEADER_PAIRS (sizeof(g_HeaderPairs) / sizeof(g_HeaderPairs[0]))

// inetsrv\iis\iisrearc\ul\ulkd\cons.h
#define DIM(x)  (sizeof(x) / sizeof(x[0]))

// inetsrv\iis\iisrearc\ul\util\dtsetup.c
#define NUM_COMMAND_ENTRIES (sizeof(CommandTable) / sizeof(CommandTable[0]))

// inetsrv\iis\iisrearc\ul\util\tul.c
#define NUM_PERF_COUNTERS (sizeof(UlPerfCounters) / sizeof(UlPerfCounters[0]))
#define NUM_CONFIG_ENTRIES (sizeof(ConfigTable) / sizeof(ConfigTable[0]))
#define NUM_COMMAND_ENTRIES (sizeof(CommandTable) / sizeof(CommandTable[0]))

// inetsrv\iis\iisrearc\ul\win9x\src\test\vxd\vxd.c
#define URL_LENGTH sizeof(URL)/sizeof(WCHAR)

// inetsrv\iis\iisrearc\ulrtl\misc.h
#define DIMENSION(x) ( sizeof(x) / sizeof(x[0]) )

// inetsrv\iis\iisrearc\ulrtl\parse.c
#define NUMBER_FAST_VERB_ENTRIES    (sizeof(FastVerbTable)/sizeof(FAST_VERB_ENTRY))
#define NUMBER_LONG_VERB_ENTRIES    (sizeof(LongVerbTable)/sizeof(LONG_VERB_ENTRY))
#define NUMBER_HEADER_MAP_ENTRIES   (sizeof(HeaderMapTable)/sizeof(HEADER_MAP_ENTRY))

// inetsrv\iis\iisrearc\ulrtl\parsep.h
#define MAX_VERB_LENGTH     (sizeof("PROPPATCH"))
#define MAX_HEADER_LENGTH       (MAX_HEADER_LONG_COUNT * sizeof(ULONGLONG))
#define DEFAULT_SERVER_HDR_LENGTH   (sizeof(DEFAULT_SERVER_HDR) - sizeof(CHAR))
#define DATE_HDR_LENGTH (sizeof("Thu, 26 Aug 1999 17:14:02 GMT") - sizeof(CHAR))
#define CONN_KEEPALIVE_HDR_LENGTH   (sizeof(CONN_KEEPALIVE_HDR) - sizeof(CHAR))
#define CREATE_HEADER_MAP_ENTRY(header, ID, handler) { \
    \
    sizeof(#header) - 1, \
    ((sizeof(#header) - 1) / 8) + \
        (((sizeof(#header) - 1) % 8) == 0 ? 0 : 1), \
    (((sizeof(#header) - 1) / 8) + \
        (((sizeof(#header) - 1) % 8) == 0 ? 0 : 1)) * 8, \
    { #header }, \
    { 0, 0, 0}, \
    { #header }, \
    ID, \
    handler, \
    }
#define CREATE_LONG_VERB_ENTRY(verb)    { sizeof(#verb) - 1, \
                                             #verb,\
                                             HttpVerb##verb }

// inetsrv\iis\img\psdksamp\isapi\extensions\io\asynctrans\openf.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
                            }

// inetsrv\iis\img\psdksamp\isapi\extensions\io\asyncwrite\openf.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
                            }

// inetsrv\iis\img\psdksamp\isapi\extensions\io\syncwrite\openf.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
                            }

// inetsrv\iis\inc\iiscrypt.h
#define IISCryptoGetBlobLength(p) (((p)->BlobDataLength) + sizeof(*(p)))

// inetsrv\iis\inc\iperfctr.hxx
# define IP_INCREMENT_COUNTER( name) \
   InterlockedIncrement( (LPLONG ) &name)
# define IP_DECREMENT_COUNTER( name) \
   InterlockedDecrement( (LPLONG ) &name)
# define IP_SET_COUNTER( name, val) \
   InterlockedExchange( (LPLONG ) &name, val)

// inetsrv\iis\lkrhash\inc\locks.h
# define LOCK_INSTRUMENTATION_INIT(ptszName)        \
    m_nContentionSpins = 0;                         \
    m_nContentions = 0;                             \
    m_nSleeps = 0;                                  \
    m_nReadLocks = 0;                               \
    m_nWriteLocks = 0;                              \
    ++sm_cTotalLocks;                               \
    if (ptszName == NULL)                           \
        m_tszName[0] = _TEXT('\0');                 \
    else                                            \
        _tcsncpy(m_tszName, ptszName, sizeof(m_tszName)/sizeof(TCHAR))

// inetsrv\iis\qfetools\spiisupd\spiisupd.cpp
#define countof( a )    ( sizeof( (a) ) / sizeof( (a)[ 0 ] ) )

// inetsrv\iis\staxinc\actlapi.h
#define INC_ACCESS_COUNTER(counter)		if (g_pCntrs) \
											InterlockedIncrement((LPLONG)&g_pCntrs->##counter)
#define DEC_ACCESS_COUNTER(counter)		if (g_pCntrs) \
											InterlockedDecrement((LPLONG)&g_pCntrs->##counter)

// inetsrv\iis\staxinc\actlcach.h
#define INC_ACCESS_COUNTER(counter)		(InterlockedIncrement((LPLONG)&g_statAccess.##counter))
#define DEC_ACCESS_COUNTER(counter)		(InterlockedDecrement((LPLONG)&g_statAccess.##counter))

// inetsrv\iis\staxinc\actldb.h
#define INC_SECURITY_COUNTER(counter)		(InterlockedIncrement((LPLONG)&g_statSecurity.##counter))
#define DEC_SECURITY_COUNTER(counter)		(InterlockedDecrement((LPLONG)&g_statSecurity.##counter))

// inetsrv\iis\staxinc\dnsapi.h
#define DNS_WINS_RECORD_LENGTH(IpCount) \
            (sizeof(DNS_WINS_DATA) + ((IpCount-1) * sizeof(IP_ADDRESS)))
#define DNS_WINS_RECORD_LENGTH(IpCount) \
            (sizeof(DNS_WINS_DATA) + ((IpCount-1) * sizeof(IP_ADDRESS)))

// inetsrv\iis\staxinc\exchmole.h
#define IMimeAllocator_FreeParamInfoArray(This,cParams,prgParam,fFreeArray)	\
    (This)->lpVtbl -> FreeParamInfoArray(This,cParams,prgParam,fFreeArray)
#define IMimeAllocator_ReleaseObjects(This,cObjects,prgpUnknown,fFreeArray)	\
    (This)->lpVtbl -> ReleaseObjects(This,cObjects,prgpUnknown,fFreeArray)
#define IMimeAllocator_FreeEnumHeaderRowArray(This,cRows,prgRow,fFreeArray)	\
    (This)->lpVtbl -> FreeEnumHeaderRowArray(This,cRows,prgRow,fFreeArray)
#define IMimeAllocator_FreeEnumPropertyArray(This,cProps,prgProp,fFreeArray)	\
    (This)->lpVtbl -> FreeEnumPropertyArray(This,cProps,prgProp,fFreeArray)

// inetsrv\iis\staxinc\export\listmacr.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// inetsrv\iis\svcs\afsvcloc\aftest\svcdisc.c
#define NUM_SERVICES    ( sizeof(g_Services)/ sizeof( SERVICE_INFO))

// inetsrv\iis\svcs\afsvcloc\test\svcdisc.c
# define NUM_SERVICES    ( sizeof(g_Services)/ sizeof( SERVICE_INFO))

// inetsrv\iis\svcs\cmp\misc\vectest.cxx
#define ELEMENTS(s)  (sizeof(s) / sizeof(s[0]))

// inetsrv\iis\svcs\cmp\tools\src\ismoke\wininet.h
#define INTERNET_MAX_URL_LENGTH         ((sizeof(INTERNET_MAX_PROTOCOL_NAME) - 1) \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// inetsrv\iis\svcs\cmp\webdav\_vroot\_vroot.h
#define CElems(_rg)		(sizeof(_rg)/sizeof(_rg[0]))

// inetsrv\iis\svcs\cmp\webdav\_xml\_xml.h
#define CElems(_rg)			(sizeof(_rg)/sizeof(_rg[0]))

// inetsrv\iis\svcs\cmp\webdav\httpext\_fsimpl.h
#define CElems(_rg)		(sizeof(_rg)/sizeof(_rg[0]))

// inetsrv\iis\svcs\cmp\webdav\inc\ex\calcom.h
#define CElems(_rg)			(sizeof(_rg)/sizeof(_rg[0]))
#define CchConstString(_s)  ((sizeof(_s)/sizeof(_s[0])) - 1)

// inetsrv\iis\svcs\cmp\webdav\inc\ex\sz.h
#define CchConstString(_s)	((sizeof(_s)/sizeof(_s[0])) - 1)

// inetsrv\iis\svcs\cmp\webdav\inc\exo.h
#define EXOCElems(_rg)							(sizeof(_rg)/sizeof(_rg[0]))

// inetsrv\iis\svcs\cmp\webdav\inc\instobj.h
#define CElems(_rg)							(sizeof(_rg)/sizeof(_rg[0]))

// inetsrv\iis\svcs\ftp\mib\mib.c
#define NUM_MIB_ENTRIES ( sizeof(Mib) / sizeof(MIB_ENTRY) )

// inetsrv\iis\svcs\ftp\perfmon\ftpdata.h
#define NUMBER_OF_FTPD_COUNTERS ((sizeof(FTPD_DATA_DEFINITION) -        \
                                  sizeof(PERF_OBJECT_TYPE)) /           \
                                  sizeof(PERF_COUNTER_DEFINITION))

// inetsrv\iis\svcs\ftp\server51\auxctrs.h
# define FacCounter( facCounter)   \
 (((facCounter) < FacMaxCounters) ? g_AuxCounters[facCounter] : 0)

// inetsrv\iis\svcs\ftp\server51\cons.hxx
#define INCREMENT_COUNTER(name)                                        \
            InterlockedIncrement((LPLONG)&name)
#define DECREMENT_COUNTER(name)                                        \
            InterlockedDecrement((LPLONG) &name)
#define UPDATE_LARGE_COUNTER(name,increment)                           \
            if( 1 ) {                                                  \
                EnterCriticalSection( &g_StatisticsLock );             \
                g_FtpStatistics.name.QuadPart += (LONGLONG)(increment);\
                LeaveCriticalSection( &g_StatisticsLock );             \
            } else

// inetsrv\iis\svcs\ftp\server51\ftpcmd.cxx
#define NUM_MAIN_COMMANDS ( sizeof(MainCommands) / sizeof(MainCommands[0]) )
#define NUM_SITE_COMMANDS ( sizeof(SiteCommands) / sizeof(SiteCommands[0]) )

// inetsrv\iis\svcs\ftp\server\auxctrs.h
# define FacCounter( facCounter)   \
 (((facCounter) < FacMaxCounters) ? g_AuxCounters[facCounter] : 0)

// inetsrv\iis\svcs\ftp\server\cons.hxx
#define INCREMENT_COUNTER(name)                                        \
            InterlockedIncrement((LPLONG)&name)
#define DECREMENT_COUNTER(name)                                        \
            InterlockedDecrement((LPLONG) &name)
#define UPDATE_LARGE_COUNTER(name,increment)                           \
            if( 1 ) {                                                  \
                EnterCriticalSection( &g_StatisticsLock );             \
                g_FtpStatistics.name.QuadPart += (LONGLONG)(increment);\
                LeaveCriticalSection( &g_StatisticsLock );             \
            } else

// inetsrv\iis\svcs\ftp\server\ftpcmd.cxx
#define NUM_MAIN_COMMANDS ( sizeof(MainCommands) / sizeof(MainCommands[0]) )
#define NUM_SITE_COMMANDS ( sizeof(SiteCommands) / sizeof(SiteCommands[0]) )

// inetsrv\iis\svcs\gopher\mib\mib.h
#define OID_SIZEOF( uiArray )      ( sizeof( uiArray) / sizeof(UINT) )

// inetsrv\iis\svcs\iisrtl\auxctrs.h
# define AcCounter( acCounter)   \
 (((acCounter) < NUM_AUX_COUNTERS) ? g_SBAuxCounters[acCounter] : 0)

// inetsrv\iis\svcs\iisrtl\datetime.cxx
# define CdtCountAccesses()  InterlockedIncrement( &m_nAccesses)
# define CdtCountMisses()    InterlockedIncrement( &m_nMisses)

// inetsrv\iis\svcs\infocomm\atq\auxctrs.h
# define AcCounter( acCounter)   \
 (((acCounter) < NUM_AUX_COUNTERS) ? g_AuxCounters[acCounter] : 0)

// inetsrv\iis\svcs\infocomm\cache2\dirlistp.cxx
# define LEN_PSZ_DIR_STAR_STAR  ( sizeof(PSZ_DIR_STAR_STAR)/sizeof(CHAR))

// inetsrv\iis\svcs\infocomm\cache\auxctrs.h
# define AcCounter( acCounter)   \
 (((acCounter) < NUM_AUX_COUNTERS) ? (VAR_AUX_COUNTER)[acCounter] : 0)

// inetsrv\iis\svcs\infocomm\cache\dirlistp.cxx
# define LEN_PSZ_DIR_STAR_STAR  ( sizeof(PSZ_DIR_STAR_STAR)/sizeof(CHAR))

// inetsrv\iis\svcs\infocomm\common\htab\htab.cxx
# define NUM_IDS_IN_LIST  ( sizeof( g_rgchIdList) / sizeof( g_rgchIdList[0]))

// inetsrv\iis\svcs\infocomm\common\security.cxx
#define NUM_ACES (sizeof(aces) / sizeof(RTL_ACE_DATA))

// inetsrv\iis\svcs\infocomm\info\perfmon\infodata.h
#define NUMBER_OF_INFO_COUNTERS ((sizeof(INFO_DATA_DEFINITION) -        \
                                  sizeof(PERF_OBJECT_TYPE)) /           \
                                  sizeof(PERF_COUNTER_DEFINITION))

// inetsrv\iis\svcs\infocomm\metadata\inc\metasub.hxx
#define WSZSCHEMA_KEY_LENGTH1 (sizeof(WSZSCHEMA_KEY_NAME1)/sizeof(WCHAR))-1
#define WSZSCHEMA_KEY_LENGTH2 (sizeof(WSZSCHEMA_KEY_NAME2)/sizeof(WCHAR))-1
#define WSZSCHEMA_KEY_LENGTH3 (sizeof(WSZSCHEMA_KEY_NAME3)/sizeof(WCHAR))-1
#define SZSCHEMA_KEY_LENGTH1 (sizeof(SZSCHEMA_KEY_NAME1)/sizeof(CHAR))-1
#define SZSCHEMA_KEY_LENGTH2 (sizeof(SZSCHEMA_KEY_NAME2)/sizeof(CHAR))-1
#define SZSCHEMA_KEY_LENGTH3 (sizeof(SZSCHEMA_KEY_NAME3)/sizeof(CHAR))-1

// inetsrv\iis\svcs\infocomm\spuddrv\spudp.h
#define BumpCount(c) InterlockedIncrement( &SpudCounters.c )

// inetsrv\iis\svcs\irtl\httphdr\httphdr.cxx
# define NUM_HTTP_HEADERS (sizeof( g_HttpHeaders)/sizeof( g_HttpHeaders[0]) - 1)

// inetsrv\iis\svcs\irtl\httphdr\tdict.cxx
# define MAX_TEST_HEADERS   ( sizeof( g_ppHeaders) / sizeof( g_ppHeaders[0]))

// inetsrv\iis\svcs\irtl\icrypt\test\keyexch\client\exchcli2.cxx
#define DIM(x)          (sizeof(x) / sizeof(x[0]))

// inetsrv\iis\svcs\loadbal\pdh\perfdata.h
#define FirstCounter(pObjectDef) \
    (PERF_COUNTER_DEFINITION *)((PCHAR)(pObjectDef) + (pObjectDef)->HeaderLength)

// inetsrv\iis\svcs\nntp\nntpctrs\nntpdata.h
#define NUMBER_OF_NNTP_COUNTERS_OBJECT1 ((sizeof(NNTP_DATA_DEFINITION_OBJECT1) -        \
										sizeof(PERF_OBJECT_TYPE)) /           \
										sizeof(PERF_COUNTER_DEFINITION))
#define NUMBER_OF_NNTP_COUNTERS_OBJECT2 ((sizeof(NNTP_DATA_DEFINITION_OBJECT2) -        \
										sizeof(PERF_OBJECT_TYPE)) /           \
										sizeof(PERF_COUNTER_DEFINITION))

// inetsrv\iis\svcs\nntp\nntpmib\mib.h
#define OID_SIZEOF( uiArray )      ( sizeof( uiArray) / sizeof(UINT) )

// inetsrv\iis\svcs\nntp\server\article\src\datetime.cxx
# define CdtCountAccesses()  InterlockedIncrement( &g_pCachedDft->m_nAccesses)
# define CdtCountMisses()    InterlockedIncrement( &g_pCachedDft->m_nMisses)

// inetsrv\iis\svcs\nntp\server\article\src\timeconv.cpp
#define	NUM_TZ	(sizeof( _TZ_NAME ) / sizeof( _TZ_NAME[ 0 ] ))

// inetsrv\iis\svcs\nntp\server\search\src\parse.cpp
#define NUM_SEARCH_KEYS (sizeof(m_rgSearchKeys) / sizeof(SKEY_INFO)) - 1

// inetsrv\iis\svcs\nntp\server\server\cservic.cpp
#define NUM_TAGS    (sizeof( Tags ) / sizeof( VERTAG ))

// inetsrv\iis\svcs\smtp\inc\smtpdata.h
#define NUMBER_OF_SMTP_COUNTERS ((sizeof(SMTP_DATA_DEFINITION) -        \
                                sizeof(PERF_OBJECT_TYPE)) /     \
                                sizeof(PERF_COUNTER_DEFINITION))

// inetsrv\iis\svcs\smtp\server\globals.cxx
#define NUM_TAGS    (sizeof( Tags ) / sizeof( VERTAG ))

// inetsrv\iis\svcs\smtp\server\smtpdata.h
#define	BUMP_COUNTER(counter) \
						InterlockedIncrement((LPLONG) &(g_SmtpStat. counter))
#define	DROP_COUNTER(counter) \
						InterlockedDecrement((LPLONG) &(g_SmtpStat. counter))
#define	ADD_COUNTER(counter, value)	\
		INTERLOCKED_ADD_CHEAP(&(g_SmtpStat. counter), value)
#define	ADD_BIGCOUNTER(counter, value) \
		INTERLOCKED_BIGADD_CHEAP(&(g_SmtpStat. counter), value)

// inetsrv\iis\svcs\smtp\server\stats.hxx
#define INCREMENT_COUNTER(name, SmtpStats)                                \
            InterlockedIncrement((LPLONG)&(SmtpStats->name))
#define DECREMENT_COUNTER(name, SmtpStats)                                \
            InterlockedDecrement((LPLONG)&(SmtpStats->name))

// inetsrv\iis\svcs\smtp\server\timeconv.cxx
#define	NUM_TZ	(sizeof( _TZ_NAME ) / sizeof( _TZ_NAME[ 0 ] ))

// inetsrv\iis\svcs\smtp\smtpmib\mib.h
#define OID_SIZEOF( uiArray )      ( sizeof( uiArray) / sizeof(UINT) )

// inetsrv\iis\svcs\staxcore\mailmsg\dumpmsg\main.cpp
#define ARGUMENT_LIST_SIZE	(sizeof(rgArguments) / sizeof(ARGUMENT_DESCRIPTOR))

// inetsrv\iis\svcs\staxcore\perfapi\src\perfapii.h
#define COUNTER_DEF_MM_SIZE             (MAX_COUNTERS * (sizeof(PERF_COUNTER_DEFINITION) + (MAX_TITLE_CHARS + 1) * sizeof(WCHAR)))
#define MAX_COUNTER_SIZE                (sizeof(LARGE_INTEGER))

// inetsrv\iis\svcs\svcloc\test\svcdisc.c
# define NUM_SERVICES    ( sizeof(g_Services)/ sizeof( SERVICE_INFO))

// inetsrv\iis\svcs\w3\filters\compress\gzip\inftree.c
#define NUM_CODE_LENGTH_ORDER_CODES (sizeof(g_CodeOrder)/sizeof(g_CodeOrder[0]))

// inetsrv\iis\svcs\w3\gateways\binsrv\binsrv.cxx
# define NUM_PROC_TYPES ( sizeof(g_rgchProcTypes) / sizeof( g_rgchProcTypes[0]))

// inetsrv\iis\svcs\w3\gateways\ftrans\openf.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
                            }

// inetsrv\iis\svcs\w3\gateways\probe\worker.cxx
# define MAX_SIZE_INFO   (sizeof(sg_rgSizeInfo) /sizeof(sg_rgSizeInfo[0]))

// inetsrv\iis\svcs\w3\mib\mib.h
#define OID_SIZEOF( uiArray )      ( sizeof( uiArray) / sizeof(UINT) )

// inetsrv\iis\svcs\w3\perfmon\w3data.h
#define NUMBER_OF_W3_COUNTERS ((sizeof(W3_DATA_DEFINITION) -        \
                                  sizeof(PERF_OBJECT_TYPE)) /           \
                                  sizeof(PERF_COUNTER_DEFINITION))

// inetsrv\iis\svcs\w3\server\w3cons.hxx
#define MAX_W3_ADVERTISE_NAME_LENGTH          (MAX_W3_COMPUTER_NAME_LENGTH + sizeof(W3_ADVERTISE_NAME_SUFFIX))
#define MAX_W3_ADVERTISE_SECURE_NAME_LENGTH   (MAX_W3_COMPUTER_NAME_LENGTH + sizeof(W3_ADVERTISE_SECURE_NAME_SUFFIX))

// inetsrv\iis\svcs\wam\tests\isagen\dofunc.cxx
# define MAX_NUM_VARIABLES (sizeof(sg_rgVarInfo) /sizeof(sg_rgVarInfo[0]))

// inetsrv\iis\svcs\wp\inc\clusrtl.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// inetsrv\iis\svcs\wp\inc\clustdi.h
#define TDI_ADDRESS_LENGTH_CLUSTER  sizeof(TDI_ADDRESS_CLUSTER)

// inetsrv\iis\ui\admin\common2\mdkeys.cpp
#define NUM_ENTRIES (sizeof(CMetaKey::s_rgMetaTable) / sizeof(CMetaKey::s_rgMetaTable[0]))

// inetsrv\iis\ui\admin\comprop\mdkeys.cpp
#define NUM_ENTRIES (sizeof(CMetaKey::s_rgMetaTable) / sizeof(CMetaKey::s_rgMetaTable[0]))

// inetsrv\iis\ui\admin\comprop\sitesecu.cpp
#define NUM_COLUMNS (sizeof(g_aColumns) / sizeof(g_aColumns[0]))

// inetsrv\iis\ui\admin\fscfg\usersess.cpp
#define NUM_COLUMNS (sizeof(g_aColumns) / sizeof(g_aColumns[0]))

// inetsrv\iis\ui\admin\pwsext\w3ext.cpp
#define NUM_ENTRIES (sizeof(g_aValues) / sizeof(g_aValues[0]))

// inetsrv\iis\ui\admin\w3scfg\mmmdlg.cpp
#define NUM_COLUMNS(cols) (sizeof(cols) / sizeof(cols[0]))

// inetsrv\iis\ui\itools\htmla\ism.hxx
#define NUM_ERROR_CODE_DLLS (sizeof(g_apszErrorCodeDlls)/sizeof(g_apszErrorCodeDlls[0]))

// inetsrv\iis\ui\itools\isadmin\afximpl.h
#define _countof(array) (sizeof(array)/sizeof(array[0]))

// inetsrv\iis\utils\cfgmnt\iadmw.h
#define IMSAdminBaseSinkW_SinkNotify(This,dwMDNumElements,pcoChangeList)	\
    (This)->lpVtbl -> SinkNotify(This,dwMDNumElements,pcoChangeList)

// inetsrv\iis\utils\mdtools\iisnet\main.cxx
#define NUM_COMMANDS ( sizeof(CommandTable) / sizeof(CommandTable[0]) )

// inetsrv\iis\utils\thttp\thttp.c
#define NUM_LEVELS (sizeof(QueryLevels) / sizeof(QueryLevels[0]))

// inetsrv\msmq\src\ac\win95\ntddk95.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)
#define KeQueryTickCount(CurrentCount ) { \
    PKSYSTEM_TIME _TickCount = *((PKSYSTEM_TIME *)(&KeTickCount)); \
    do {                                                          \
        (CurrentCount)->HighPart = _TickCount->High1Time;          \
        (CurrentCount)->LowPart = _TickCount->LowPart;             \
    } while ((CurrentCount)->HighPart != _TickCount->High2Time);   \
}
#define KiQueryTickCount(CurrentCount) \
    do {                                                        \
        (CurrentCount)->HighPart = KeTickCount.High1Time;       \
        (CurrentCount)->LowPart = KeTickCount.LowPart;          \
    } while ((CurrentCount)->HighPart != KeTickCount.High2Time)
#define KeQueryTickCount(CurrentCount ) { \
    PKSYSTEM_TIME _TickCount = *((PKSYSTEM_TIME *)(&KeTickCount)); \
    do {                                                          \
        (CurrentCount)->HighPart = _TickCount->High1Time;          \
        (CurrentCount)->LowPart = _TickCount->LowPart;             \
    } while ((CurrentCount)->HighPart != _TickCount->High2Time);   \
}
#define KiQueryTickCount(CurrentCount) \
    do {                                                        \
        (CurrentCount)->HighPart = KeTickCount.High1Time;       \
        (CurrentCount)->LowPart = KeTickCount.LowPart;          \
    } while ((CurrentCount)->HighPart != KeTickCount.High2Time)
#define KeQueryTickCount(CurrentCount ) \
    *(PULONGLONG)(CurrentCount) = **((volatile ULONGLONG **)(&KeTickCount));
#define KeQueryTickCount(CurrentCount) { \
    PKSYSTEM_TIME _TickCount = *((PKSYSTEM_TIME *)(&KeTickCount)); \
    do {                                                           \
        (CurrentCount)->HighPart = _TickCount->High1Time;          \
        (CurrentCount)->LowPart = _TickCount->LowPart;             \
    } while ((CurrentCount)->HighPart != _TickCount->High2Time);    \
}
#define KiQueryTickCount(CurrentCount) \
    do {                                                        \
        (CurrentCount)->HighPart = KeTickCount.High1Time;       \
        (CurrentCount)->LowPart = KeTickCount.LowPart;          \
    } while ((CurrentCount)->HighPart != KeTickCount.High2Time)
#define MAXIMUM_VOLUME_LABEL_LENGTH  (32 * sizeof(WCHAR)) // 32 characters

// inetsrv\msmq\src\activex\lib\utilx.h
#define JOURNAL_QUEUE_INDICATOR_LENGTH (sizeof(JOURNAL_QUEUE_INDICATOR)/sizeof(WCHAR)-1)
#define DEADLETTER_QUEUE_INDICATOR_LENGTH (sizeof(DEADLETTER_QUEUE_INDICATOR)/sizeof(WCHAR)-1)
#define MACHINE_QUEUE_INDICATOR_LENGTH (sizeof(MACHINE_QUEUE_INDICATOR)/sizeof(WCHAR)-1)
#define CONNECTOR_QUEUE_INDICATOR_LENGTH (sizeof(CONNECTOR_QUEUE_INDICATOR)/sizeof(WCHAR)-1)
#define PRIVATE_QUEUE_INDICATOR_LENGTH (sizeof(PRIVATE_QUEUE_INDICATOR)/sizeof(WCHAR)-1)
#define PUBLIC_QUEUE_INDICATOR_LENGTH  (sizeof(PUBLIC_QUEUE_INDICATOR )/sizeof(WCHAR)-1)
#define DIRECT_QUEUE_INDICATOR_LENGTH  (sizeof(DIRECT_QUEUE_INDICATOR )/sizeof(WCHAR)-1)
#define DIRECT_ANY_QUEUE_INDICATOR_LENGTH  (sizeof(DIRECT_ANY_QUEUE_INDICATOR )/sizeof(WCHAR)-1)
#define DIRECT_TCP_QUEUE_INDICATOR_LENGTH  (sizeof(DIRECT_TCP_QUEUE_INDICATOR )/sizeof(WCHAR)-1)
#define DIRECT_SPX_QUEUE_INDICATOR_LENGTH  (sizeof(DIRECT_SPX_QUEUE_INDICATOR )/sizeof(WCHAR)-1)

// inetsrv\msmq\src\admin\mqsnap\message.h
#define SET_LAST_CHAR_AS_ZERO(wsz)     (wsz)[ sizeof(wsz)/sizeof((wsz)[0]) - 1 ] = _T('\0')

// inetsrv\msmq\src\apps\mqdiag\mqping\sim.h
#define LEN_OF(var) ( sizeof(var) / sizeof(*(var)) )

// inetsrv\msmq\src\apps\mqdiag\mqstate\perfstuff.cpp
#define FirstCounter(pObjectDef)       \
   ((PERF_COUNTER_DEFINITION *) ((PCHAR)pObjectDef + pObjectDef->HeaderLength))

// inetsrv\msmq\src\ds\mqdscore\ipsite.cpp
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// inetsrv\msmq\src\inc\mqprops.h
#define DEFAULT_COM_ACCOUNT_CONTROL   (UF_PASSWD_NOTREQD | UF_WORKSTATION_TRUST_ACCOUNT)

// inetsrv\msmq\src\lib\inc\dloaddef.h
#define celems(_x)          (sizeof(_x) / sizeof(_x[0]))

// inetsrv\msmq\src\lib\inc\fntoken.h
#define GUID_ELEMENTS(p) \
    (p)->Data1, (p)->Data2, (p)->Data3,\
    (p)->Data4[0], (p)->Data4[1], (p)->Data4[2], (p)->Data4[3],\
    (p)->Data4[4], (p)->Data4[5], (p)->Data4[6], (p)->Data4[7]

// inetsrv\msmq\src\qm\cqpriv.cpp
#define NPROPS (sizeof(g_propidQueue)/sizeof(PROPID))

// inetsrv\msmq\src\qm\qmsecutl.cpp
#define LengthSid95( Sid ) \
    (8 + (4 * ((SID *)Sid)->SubAuthorityCount))

// inetsrv\msmq\src\replserv\mq1repl\migrepl.h
#define CN_USERS_LEN           (sizeof(CN_USERS) / sizeof(TCHAR))
#define MQUSER_ROOT_LEN        (sizeof(MQUSER_ROOT) / sizeof(TCHAR))
#define  SITE_LINK_ROOT_LEN    (sizeof(SITE_LINK_ROOT) / sizeof(TCHAR))
#define  SERVER_DN_PREFIX_LEN  (sizeof(SERVER_DN_PREFIX) / sizeof(TCHAR))
#define  MACHINE_PATH_PREFIX_LEN    (sizeof(MACHINE_PATH_PREFIX) / sizeof(TCHAR))
#define  SERVERS_PREFIX_LEN    (sizeof(SERVERS_PREFIX) / sizeof(TCHAR))
#define  CN_PREFIX_LEN         (sizeof(CN_PREFIX) / sizeof(TCHAR))
#define  OU_PREFIX_LEN         (sizeof(OU_PREFIX) / sizeof(TCHAR))

// inetsrv\msmq\src\replserv\mqrpperf\mqrepst.h
#define COUNTER_DEFINITION_SIZE sizeof(PERF_COUNTER_DEFINITION)

// inetsrv\msmq\src\rt\property.cpp
#define _SENDSIZE  (sizeof(MessageSendValidation) / sizeof(propValidity))
#define _RCVSIZE   (sizeof(MessageReceiveValidation) / sizeof(propValidity))
#define _VARSIZE   (sizeof(MessageVarTypes) / sizeof(VARTYPE))

// inetsrv\msmq\src\rtdep\property.cpp
#define _SENDSIZE  (sizeof(MessageSendValidation) / sizeof(propValidity))
#define _RCVSIZE   (sizeof(MessageReceiveValidation) / sizeof(propValidity))
#define _VARSIZE   (sizeof(MessageVarTypes) / sizeof(VARTYPE))

// inetsrv\msmq\src\setup\msmqocm\list_mac.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// inetsrv\query\apps\srch\minici.hxx
#define DECL_DYNARRAY_INPLACE( CMyDynArrayInPlace, CItem )\
typedef CDynArrayInPlace<CItem> CMyDynArrayInPlace;

// inetsrv\query\filters\html\source\anchor.hxx
#define ITEMCOUNT(rg) ( sizeof(rg) / sizeof(rg[0]) )

// inetsrv\query\filters\office\src\findfast\convtype.h
#define cElements(ary)		(sizeof(ary) / sizeof(ary[0]))

// inetsrv\query\filters\office\src\findfast\dmifmtv5.c
#define EXCEL5_MAX_BUILTIN_FORMATS ((sizeof(V5BuiltinFormatTypes) / sizeof(FMTType)) - 1)

// inetsrv\query\h\ci.h
# define NUMELEM(x) (sizeof(x)/sizeof(*x))

// inetsrv\query\h\dynarray.hxx
#define DECL_DYNARRAY( CMyDynArray, CItem )\
    typedef CDynArray<CItem> CMyDynArray;
#define DECL_DYNARRAY_INPLACE( CMyDynArrayInPlace, CItem )\
typedef CDynArrayInPlace<CItem> CMyDynArrayInPlace;

// inetsrv\query\h\idqperf.hxx
#define CI_ISAPI_TOTAL_NUM_COUNTERS  (sizeof(CI_ISAPI_DATA_DEFINITION)-sizeof(PERF_OBJECT_TYPE)) / \
                                      sizeof(PERF_COUNTER_DEFINITION)

// inetsrv\query\h\perfci.hxx
#define FILTER_TOTAL_NUM_COUNTERS ((sizeof(FILTER_DATA_DEFINITION)-sizeof(PERF_OBJECT_TYPE)) / \
                                   sizeof(PERF_COUNTER_DEFINITION))

// inetsrv\query\setupqry\setupqry.hxx
# define NUMELEM(x) (sizeof(x)/sizeof(*x))

// inetsrv\query\sqltext\msidxtr.h
#define NUMELEM(p1) (sizeof(p1) / sizeof(*(p1)))

// inetsrv\query\sqltext\mssqltab.cpp
#define VAL_AND_CCH_MINUS_NULL(p1) (p1), ((sizeof(p1) / sizeof(*(p1))) - 1)

// inetsrv\query\sqltext\ptprops.cpp
#define CALC_CCH_MINUS_NULL(p1) (sizeof(p1) / sizeof(*(p1))) - 1

// inetsrv\query\sqltext\treeutil.cpp
#define VAL_AND_CCH_MINUS_NULL(p1) (p1), ((sizeof(p1) / sizeof(*(p1))) - 1)

// mergedcomponents\advapi32\sddl.c
#define SDDL_LEN_TAG( tagdef )  ( sizeof( tagdef ) / sizeof( WCHAR ) - 1 )

// mergedcomponents\advapi32\security.c
#define NELEMENTS(x)  sizeof(x)/sizeof((x)[0])

// multimedia\danim\extinc\dxtrans.h
#define IDXARGBReadWritePtr_OverArrayAndMove(This,pScratchBuffer,pSrc,cSamples)	\
    (This)->lpVtbl -> OverArrayAndMove(This,pScratchBuffer,pSrc,cSamples)

// multimedia\danim\src\daxctl\controls\mmctl\inc\ocmisc.h
#define COUNT_ELEMENTS(array) \
    sizeof(array) / sizeof((array)[0])

// multimedia\danim\src\daxctl\controls\sgrfx\parser.cpp
  #define ARRAYDIM(a)  (sizeof(a) / sizeof(a[0]))

// multimedia\danim\src\daxctl\util\urlarchv.cpp
  #define ARRAYDIM(a)   (sizeof(a) / sizeof(a[0]))

// multimedia\danim\src\lm\chrome\src\effect.cpp
#define SIZE_OF_EFFECT_TABLE (sizeof(rgEffectNames) / sizeof(EFFECTVALUE_PAIR))

// multimedia\danim\src\lm\chrome\src\util.cpp
#define SIZE_OF_COLOR_TABLE (sizeof(rgColorNames) / sizeof(COLORVALUE_PAIR))

// multimedia\danim\tools\x86\java15\include\javadbg.h
#define IRemoteArrayField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteArrayField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteArrayField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteArrayField_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)
#define IRemoteArrayField_GetKind(This,pfk)	\
    (This)->lpVtbl -> GetKind(This,pfk)
#define IRemoteArrayField_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteArrayField_GetContainer(This,ppContainer)	\
    (This)->lpVtbl -> GetContainer(This,ppContainer)
#define IRemoteArrayField_GetModifiers(This,pulModifiers)	\
    (This)->lpVtbl -> GetModifiers(This,pulModifiers)
#define IRemoteArrayField_GetSize(This,pcElements)	\
    (This)->lpVtbl -> GetSize(This,pcElements)
#define IRemoteArrayObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteArrayObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteArrayObject_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteArrayObject_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteArrayObject_SetBreakpoint(This)	\
    (This)->lpVtbl -> SetBreakpoint(This)
#define IRemoteArrayObject_ClearBreakpoint(This)	\
    (This)->lpVtbl -> ClearBreakpoint(This)
#define IRemoteArrayObject_GetElementObjects(This,ppEnum)	\
    (This)->lpVtbl -> GetElementObjects(This,ppEnum)
#define IRemoteArrayObject_GetSize(This,pcElements)	\
    (This)->lpVtbl -> GetSize(This,pcElements)
#define IRemoteArrayObject_GetElementValues(This,ppEnum)	\
    (This)->lpVtbl -> GetElementValues(This,ppEnum)

// multimedia\danim\tools\x86\java20\include\javadbg.h
#define IRemoteArrayField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteArrayField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteArrayField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteArrayField_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)
#define IRemoteArrayField_GetKind(This,pfk)	\
    (This)->lpVtbl -> GetKind(This,pfk)
#define IRemoteArrayField_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteArrayField_GetContainer(This,ppContainer)	\
    (This)->lpVtbl -> GetContainer(This,ppContainer)
#define IRemoteArrayField_GetModifiers(This,pulModifiers)	\
    (This)->lpVtbl -> GetModifiers(This,pulModifiers)
#define IRemoteArrayField_GetSize(This,pcElements)	\
    (This)->lpVtbl -> GetSize(This,pcElements)
#define IRemoteArrayObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteArrayObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteArrayObject_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteArrayObject_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteArrayObject_SetBreakpoint(This)	\
    (This)->lpVtbl -> SetBreakpoint(This)
#define IRemoteArrayObject_ClearBreakpoint(This)	\
    (This)->lpVtbl -> ClearBreakpoint(This)
#define IRemoteArrayObject_GetElementObjects(This,ppEnum)	\
    (This)->lpVtbl -> GetElementObjects(This,ppEnum)
#define IRemoteArrayObject_GetSize(This,pcElements)	\
    (This)->lpVtbl -> GetSize(This,pcElements)
#define IRemoteArrayObject_GetElementValues(This,ppEnum)	\
    (This)->lpVtbl -> GetElementValues(This,ppEnum)

// multimedia\directx\ddrawex\surface.cpp
#define NUM_SUPPORTED_TEX_PFS (sizeof(ddpfSupportedTexPFs) / sizeof(ddpfSupportedTexPFs[0]))
#define NUM_SUPPORTED_OFFSCRN_PFS (sizeof(ddpfSupportedOffScrnPFs) / sizeof(ddpfSupportedOffScrnPFs[0]))

// multimedia\directx\dinput\dimapcfg\dimaptst.h
#define COUNT_ARRAY_ELEMENTS(a) (sizeof(a) / sizeof(a[0]))
#define COUNT_ARRAY_ELEMENTS (sizeof(a)/sizeof(a[0])

// multimedia\directx\dinput\dx8\tdonuts\diutil.cpp
#define NUMBER_OF_SEMANTICS ( sizeof(g_rgGameAction) / sizeof(DIACTION) )

// multimedia\directx\dmusic\dmcompos\sjpers.h
#define CHORDENTRY_SIZE (sizeof(ChordExt)-sizeof(LPCHORDEXT)+sizeof(unsigned long)+sizeof(short))

// multimedia\directx\dmusic\dmusic32\mmdevldr.h
#define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))

// multimedia\directx\dmusic\dmusic\dmeport.cpp
#define MAXCCH(x) (sizeof(x) / sizeof(x[0]))

// multimedia\directx\dmusic\dmusic\dmusicp.h
#define ELES(x)          (sizeof(x) / sizeof((x)[0]))
#define TILE_COUNT(x) ((x) & 0x0000ffff)

// multimedia\directx\dplay\dnet\core\enum_sp.h
#define	GUID_STRING_LENGTH	((sizeof(GUID) * 2) + 2 + 4)

// multimedia\directx\dsound\dsound\grace.h
#define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\directx\dsound\dsound\misc.h
#define NUMELMS(a) \
            (sizeof(a) / sizeof((a)[0]))

// multimedia\directx\dsound\dsvxd\dev.cpp
#define NUMGUIDS (sizeof(guidList) / sizeof(guidList[0]))

// multimedia\directx\dxg\d3d8\fw\ddgdi32.c
#define NUM_KNOWN_DEVICES      (sizeof(gKnownDeviceList)/sizeof(KNOWNENTRY))

// multimedia\directx\dxg\d3d\dx6\rast\rampmat\palette.h
#define INDEX_TO_ENTRY(pal, index)      (&(pal)->entries[index])

// multimedia\directx\dxg\dd\ddraw\ddraw16\modex.c
#define NUM_CRT_Tweak (sizeof(wCRT_Tweak)/sizeof(wCRT_Tweak[0]))
#define NUM_CRT_Set360Columns (sizeof(wCRT_Set360Columns)/sizeof(wCRT_Set360Columns[0]))
#define NUM_CRT_Set175Lines (sizeof(wCRT_Set175Lines)/sizeof(wCRT_Set175Lines[0]))
#define NUM_CRT_Set240Lines (sizeof(wCRT_Set240Lines)/sizeof(wCRT_Set240Lines[0]))

// multimedia\directx\dxg\dd\ddraw\main\ddgdi32.c
#define NUM_KNOWN_DEVICES      (sizeof(gKnownDeviceList)/sizeof(KNOWNENTRY))

// multimedia\directx\dxg\dd\ddraw\main\ddithunk.h
#define INDEX_ENTRY(x)                                          \
    ((x) & ~INDEX_IN_USE)
#define GET_CACHED_ENTRY(x)                                     \
    (&((x)->pDevice->pCachedSurfaceTable[INDEX_ENTRY((x)->Surface.pLight->CachedIndex)]))

// multimedia\directx\dxg\dd\ddraw\main\ddmode.c
#define NUM_MODEX_MODES (sizeof( ddmiModeXModes ) / sizeof( ddmiModeXModes[0] ) )

// multimedia\directx\inc\mmdevldr.h
#define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))

// multimedia\dshow\filters.ks\pinprop\ksprxmtd.cpp
#define SIZE_AR(a) sizeof(a) / sizeof(a[0])
#define MakeSetEntry(s, f) { (LPCLSID) &s, #s, f, SIZE_AR(f) }
#define MakeGuidEntry(s, f) { (LPCLSID) &s, #s, f }

// multimedia\dshow\filters.ks\tests\iphone\common.h
#define ZARR(A) {for (i=sizeof(A)/sizeof(A[0])-1; i>=0 ; i--) A[i] = 0.0;}
#define UPDATE(NAME) {int _i;if(NAME ## _obsolete_p) \
		       for(_i=sizeof(NAME)/sizeof(NAME[0])-1;_i>=0;_i--)\
		       NAME[_i]=NAME ## _next[_i]; NAME ## _obsolete_p=0;}

// multimedia\dshow\filters.ks\tvtuner\ctvtuner.h
#define NUM_TVTUNER_FORMATS (sizeof (TVTunerFormatCaps) / sizeof (TVFORMATINFO))

// multimedia\dshow\filters\asf\wmsdk\inc\wmsdkidl.h
#define IWMStreamList_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMMutualExclusion_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMReaderNetworkConfig_GetUDPPortRanges(This,pRangeArray,pcRanges)	\
    (This)->lpVtbl -> GetUDPPortRanges(This,pRangeArray,pcRanges)
#define IWMReaderNetworkConfig_SetUDPPortRanges(This,pRangeArray,cRanges)	\
    (This)->lpVtbl -> SetUDPPortRanges(This,pRangeArray,cRanges)

// multimedia\dshow\filters\core\builder2\ks.h
    #define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))

// multimedia\dshow\filters\image2\inc\vmrp.h
#define ISBADREADWRITEARRAY(p,c) (ISBADREADARRAY(p,c)||ISBADWRITEARRAY(p,c))

// multimedia\dshow\filters\lin21dec2\l21dfilt.h
#define GETGOPUD_ELEMENT(pGOPUDPkt, i)  (pGOPUDPkt + GOPUD_HEADERLENGTH + sizeof(AM_L21_GOPUD_ELEMENT) * i)

// multimedia\dshow\filters\lin21dec\l21dfilt.h
#define GETGOPUD_ELEMENT(pGOPUDPkt, i)  (pGOPUDPkt + GOPUD_HEADERLENGTH + sizeof(AM_L21_GOPUD_ELEMENT) * i)

// multimedia\dshow\filters\sbe\wmsdk\inc\wmsdkidl.h
#define IWMStreamList_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMMutualExclusion_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMMutualExclusion2_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMMutualExclusion2_GetStreamsForRecord(This,wRecordNumber,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreamsForRecord(This,wRecordNumber,pwStreamNumArray,pcStreams)
#define IWMBandwidthSharing_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMStreamPrioritization_GetPriorityRecords(This,pRecordArray,pcRecords)	\
    (This)->lpVtbl -> GetPriorityRecords(This,pRecordArray,pcRecords)
#define IWMStreamPrioritization_SetPriorityRecords(This,pRecordArray,cRecords)	\
    (This)->lpVtbl -> SetPriorityRecords(This,pRecordArray,cRecords)
#define IWMReaderNetworkConfig_GetUDPPortRanges(This,pRangeArray,pcRanges)	\
    (This)->lpVtbl -> GetUDPPortRanges(This,pRangeArray,pcRanges)
#define IWMReaderNetworkConfig_SetUDPPortRanges(This,pRangeArray,cRanges)	\
    (This)->lpVtbl -> SetUDPPortRanges(This,pRangeArray,cRanges)

// multimedia\dshow\filters\sbe\wmsdk\inc\wmsdkidl2.h
#define IWMReaderNetworkConfig2_GetUDPPortRanges(This,pRangeArray,pcRanges)	\
    (This)->lpVtbl -> GetUDPPortRanges(This,pRangeArray,pcRanges)
#define IWMReaderNetworkConfig2_SetUDPPortRanges(This,pRangeArray,cRanges)	\
    (This)->lpVtbl -> SetUDPPortRanges(This,pRangeArray,cRanges)

// multimedia\dshow\filters\tsdvr\tools\dsnet\include\le.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define InsertListEntry(ListEntry,Entry) {\
    PLIST_ENTRY _EX_Flink;\
    PLIST_ENTRY _EX_ListEntry;\
    _EX_ListEntry = (ListEntry);\
    _EX_Flink = _EX_ListEntry->Flink;\
    (Entry)->Flink = _EX_Flink;\
    (Entry)->Blink = _EX_ListEntry;\
    _EX_Flink->Blink = (Entry);\
    _EX_ListEntry->Flink = (Entry);\
    }
#define MoveEntryList(FromListHead,ToListHead) {\
    PLIST_ENTRY _EX_FromListHead;\
    PLIST_ENTRY _EX_ToListHead;\
    _EX_FromListHead = (FromListHead);\
    _EX_ToListHead = (ToListHead);\
    _EX_ToListHead->Flink = _EX_FromListHead->Flink;\
    _EX_ToListHead->Blink = _EX_FromListHead->Blink;\
    _EX_ToListHead->Flink->Blink = _EX_ToListHead;\
    _EX_ToListHead->Blink->Flink = _EX_ToListHead;\
    (FromListHead)->Flink = (FromListHead)->Blink = (FromListHead);\
    }

// multimedia\dshow\filters\tsdvr\wmsdk\inc\wmsdkidl.h
#define IWMStreamList_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMMutualExclusion_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMMutualExclusion2_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMMutualExclusion2_GetStreamsForRecord(This,wRecordNumber,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreamsForRecord(This,wRecordNumber,pwStreamNumArray,pcStreams)
#define IWMBandwidthSharing_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMStreamPrioritization_GetPriorityRecords(This,pRecordArray,pcRecords)	\
    (This)->lpVtbl -> GetPriorityRecords(This,pRecordArray,pcRecords)
#define IWMStreamPrioritization_SetPriorityRecords(This,pRecordArray,cRecords)	\
    (This)->lpVtbl -> SetPriorityRecords(This,pRecordArray,cRecords)
#define IWMReaderNetworkConfig_GetUDPPortRanges(This,pRangeArray,pcRanges)	\
    (This)->lpVtbl -> GetUDPPortRanges(This,pRangeArray,pcRanges)
#define IWMReaderNetworkConfig_SetUDPPortRanges(This,pRangeArray,cRanges)	\
    (This)->lpVtbl -> SetUDPPortRanges(This,pRangeArray,cRanges)
#define IWMReaderNetworkConfig2_GetUDPPortRanges(This,pRangeArray,pcRanges)	\
    (This)->lpVtbl -> GetUDPPortRanges(This,pRangeArray,pcRanges)
#define IWMReaderNetworkConfig2_SetUDPPortRanges(This,pRangeArray,cRanges)	\
    (This)->lpVtbl -> SetUDPPortRanges(This,pRangeArray,cRanges)

// multimedia\dshow\filters\tve\atvefsend\msbdnapi.h
#define IBdnAddressReserve_EnumLeases(This,count,array)	\
    (This)->lpVtbl -> EnumLeases(This,count,array)
#define IBdnRouter_EnumVif(This,array_count,array)	\
    (This)->lpVtbl -> EnumVif(This,array_count,array)
#define IBdnRouter_EnumRoute(This,flags,ip_address,vif_id,resv_id,array_count,array)	\
    (This)->lpVtbl -> EnumRoute(This,flags,ip_address,vif_id,resv_id,array_count,array)

// multimedia\dshow\filters\wav\audio\qksaud\ksaudtop.h
#define RemoveFirstEntry( list, Type )                                \
            (Type*) (list);                                           \
            {                                                         \
                SINGLE_LIST_ENTRY * pRFETemp;                       \
                pRFETemp = (SINGLE_LIST_ENTRY *) (list);              \
                if( (list) ) {                                        \
                    (list) = (Type*) (list)->List.Next;               \
                    if( pRFETemp ) {                                  \
                        ((Type*) pRFETemp)->List.Next = NULL;         \
                    }                                                 \
                }                                                     \
            }

// multimedia\dshow\guidestore\stdafx.h
#define sizeofarray(a) (sizeof(a)/sizeof((a)[0]))

// multimedia\dshow\makesdk\dshow.h
   #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\dshow\mfvideo\tvplayer\msmfcnt\msmfcnt.h
#define IMSMFBar_ResetFocusArray(This)	\
    (This)->lpVtbl -> ResetFocusArray(This)

// multimedia\dshow\tools\dmotest\dshowmediaobj\dvenc\dvenc.cpp
    #define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))

// multimedia\dshow\tools\dmotest\dshowmediaobj\simple\simple.cpp
    #define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))

// multimedia\dshow\tools\graphedt\graphedt\mainfrm.cpp
#define NUM_BUTTONS  (sizeof(buttons) / sizeof(buttons[0]))

// multimedia\media\avi\avicap.io\avicapi.h
  #define NUMELMS(aa)           (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\avicap.io\capavi.c
    #define DAYLENGTH (sizeof(szDay)/7)
    #define MONTHLENGTH (sizeof(szMonth)/12)

// multimedia\media\avi\avicap\avicapi.h
  #define NUMELMS(aa)           (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\avifile.16\afclip.c
#define N_FORMATS   (sizeof(FormatList) / sizeof(FormatList[0]))

// multimedia\media\avi\avifile\afclip.c
#define N_FORMATS   (sizeof(FormatList) / sizeof(FormatList[0]))

// multimedia\media\avi\avifile\avifile.cpp
 #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\avifile\avilib.cpp
 #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\avifile\aviopts.c
 #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\avifile\editstrm.cpp
 #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\compman\compmani.h
  #define NUMELMS(aa)           (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\compman\icm.c
    #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\inc.16\commctrl.h
#define TB_BUTTONCOUNT		(WM_USER + 24)
#define TTM_GETTOOLCOUNT        (WM_USER +13)
#define SB_GETTEXTLENGTH	(WM_USER+3)

// multimedia\media\avi\inc.16\mciwnd.h
#define MCIWNDM_GETLENGTH	(WM_USER + 104)

// multimedia\media\avi\inc.16\variant.h
#define V_ISARRAY(X)     (V_VT(X)&VT_ARRAY)

// multimedia\media\avi\inc.16\wfext.h
#define FM_GETSELCOUNT		(WM_USER + 0x0202)
#define FM_GETSELCOUNTLFN	(WM_USER + 0x0203)	/* LFN versions are odd */

// multimedia\media\avi\inc.16\win32.h
#define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\inc.16\windows.h
#define EM_GETLINECOUNT         (WM_USER+10)
#define EM_LINELENGTH           (WM_USER+17)
#define LB_GETCOUNT             (WM_USER+12)
#define LB_GETSELCOUNT          (WM_USER+17)
#define CB_GETCOUNT             (WM_USER+6)

// multimedia\media\avi\inc\meddibs.h
#define DIBS_GETLENGTH		(MED_USER+6)

// multimedia\media\avi\inc\wincom.h
#define CM_GETCOUNT		(WM_USER + 6)

// multimedia\media\avi\mciavi32\graphic.h
 #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\mciwnd.16\bmpload.c
  #define NUM_DEFAULT_MAPS (sizeof(SysColorMap)/sizeof(COLORMAP))

// multimedia\media\avi\mciwnd.16\commctrl.h
#define TB_BUTTONCOUNT		(WM_USER + 24)
#define SB_GETTEXTLENGTH	(WM_USER+3)
#define BL_GETCOUNT         (WM_USER+4)

// multimedia\media\avi\mciwnd.16\mciwnd.h
#define MCIWNDM_GETLENGTH	(WM_USER + 104)

// multimedia\media\avi\mciwnd\bmpload.c
  #define NUM_DEFAULT_MAPS (sizeof(SysColorMap)/sizeof(COLORMAP))

// multimedia\media\avi\mciwnd\mciwnd.c
    #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\mciwnd\mciwnd.h
#define MCIWNDM_GETLENGTH	(WM_USER + 104)

// multimedia\media\avi\mciwnd\mciwndi.h
    #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\msrle\msrle.c
 #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\msvidc\msvidc.c
 #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\avi\video\profile.h
 #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\dplay\serial\tapicode.cpp
#define g_sizeofNonDialable (sizeof(g_sNonDialable)/sizeof(g_sNonDialable[0]))

// multimedia\media\dplay\serial\tapiinfo.cpp
#define sizeofArray(pArray) (sizeof(pArray) / sizeof((pArray)[0]))

// multimedia\media\inc\mmcntrls.h
#define TB_BUTTONCOUNT		(WM_USER + 24)

// multimedia\media\inc\win32.h
#define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\media\mcicda\mcicda.h
#define cchLENGTH(_sz) (sizeof(_sz)/sizeof(_sz[0]))

// multimedia\media\mciseq\mciseq.h
#define cchLENGTH(_sz) (sizeof(_sz)/sizeof(_sz[0]))

// multimedia\media\mplayer2\mplayer.h
#define CHAR_COUNT( buf )   (sizeof(buf) / sizeof(TCHAR))

// multimedia\media\msacm\g711\codec.h
    #define SIZEOFACMSTR(x)	(sizeof(x)/sizeof(WCHAR))
#define SIZEOF_ARRAY(ar)            (sizeof(ar)/sizeof((ar)[0]))

// multimedia\media\msacm\gsm610\codec.h
    #define SIZEOFACMSTR(x)	(sizeof(x)/sizeof(WCHAR))
#define SIZEOF_ARRAY(ar)            (sizeof(ar)/sizeof((ar)[0]))

// multimedia\media\msacm\imaadpcm\codec.h
    #define SIZEOFACMSTR(x)	(sizeof(x)/sizeof(WCHAR))
#define SIZEOF_ARRAY(ar)            (sizeof(ar)/sizeof((ar)[0]))

// multimedia\media\msacm\msacm\acmfmt.c
#define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))

// multimedia\media\msacm\msacm\acmi.h
    #define SIZEOFW(x) (sizeof(x)/sizeof(WCHAR))

// multimedia\media\msacm\msacm\pcm.c
#define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))

// multimedia\media\msacm\msadpcm\codec.c
#define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))

// multimedia\media\msacm\msadpcm\codec.h
    #define SIZEOFACMSTR(x)	(sizeof(x)/sizeof(WCHAR))

// multimedia\media\msacm\msfilter\codec.h
    #define SIZEOFACMSTR(x)	(sizeof(x)/sizeof(WCHAR))
#define SIZEOF_ARRAY(ar)            (sizeof(ar)/sizeof((ar)[0]))

// multimedia\media\samples\midimon\monitor\midimon.c
#define NUMKEYS (sizeof (keyToScroll) / sizeof (keyToScroll[0]))

// multimedia\media\sndrec32\soundrec\wave.c
#define NUM_FORMATS (sizeof(wFormats)/sizeof(wFormats[0]))

// multimedia\media\test\playsnd\sound.c
#define NUMSYSTEMSOUNDS (sizeof(SNA)/sizeof(SOUNDNAMEALIAS))

// multimedia\media\test\sbtest\wincom.h
#define CM_GETCOUNT		(WM_USER + 6)

// multimedia\media\winmm\joy.c
#define cchLENGTH(_sz)  (sizeof(_sz)/sizeof(_sz[0]))

// multimedia\media\winmm\playsnd.c
#define cchLENGTH(_sz)  (sizeof(_sz)/sizeof(_sz[0]))

// multimedia\media\winmm\winmm.c
#define cchLENGTH(_sz) (sizeof(_sz) / sizeof(_sz[0]))
#define nEVENTLABELS  (sizeof(gaEventLabels)/sizeof(gaEventLabels[0]))

// multimedia\opengl\client\ddtex.c
#define NDDTF (sizeof(ddtfFormats)/sizeof(ddtfFormats[0]))

// multimedia\opengl\client\local.h
#define COMMIT_COUNT  (4096/sizeof(LHE))

// multimedia\opengl\client\metasup.c
#define GL_DEVICE_PROCS (sizeof(GLDEVICEPROCS)/sizeof(PROC))
#define GLS_ENTRY_POINT_STRINGS (sizeof(pszGlsEntryPoints)/sizeof(char *))
#define GLS_ENTRY_POINTS (sizeof(GLSENTRYPOINTS)/sizeof(void *))
#define RECIRCULATE_OPS (sizeof(opRecirculate)/sizeof(opRecirculate[0]))

// multimedia\opengl\client\wcreate.c
#define DRIVER_ENTRY_POINTS (sizeof(pszDriverEntryPoints)/sizeof(char *))

// multimedia\opengl\glexts\hacklocl.h
#define COMMIT_COUNT  (4096/sizeof(LHE))

// multimedia\opengl\gls\lib\platform.c
#define GL11_PROCS (sizeof(opGl11Procs)/sizeof(opGl11Procs[0]))
#define EXT_PROCS (sizeof(opExtProcs)/sizeof(opExtProcs[0]))

// multimedia\opengl\glu\libnurbs\errinit.c
#define NERRORS ( sizeof(auiNurbsErrors)/sizeof(auiNurbsErrors[0]) )

// multimedia\opengl\glu\libtess\errorstr.c
#define NERRORS ( sizeof(auiTessErrors)/sizeof(auiTessErrors[0]) )

// multimedia\opengl\glu\libtri\errorstr.c
#define NERRORS ( sizeof(auiTessErrors)/sizeof(auiTessErrors[0]) )

// multimedia\opengl\glu\libutil\error.c
#define NERRORS (sizeof(errorStrings)/sizeof(errorStrings[0]))

// multimedia\opengl\glu\nurbs\core\quilt.cxx
#define fsizeof(x)		(sizeof(x)/sizeof(REAL))

// multimedia\opengl\glu\nurbs\nt\errinit.c
#define NERRORS ( sizeof(auiNurbsErrors)/sizeof(auiNurbsErrors[0]) )

// multimedia\opengl\inc\glteb.h
#define GL_EXT_PROC_TABLE_SIZE      (sizeof(GLEXTDISPATCHTABLE)/sizeof(PROC))

// multimedia\opengl\inc\parray.h
#define POLYMATERIAL_ARRAY_SIZE       (4096 / sizeof(__GLmatChange))

// multimedia\opengl\pmesh\array.h
#define ForPArray(A,T,V) ForIndex(zzz,(A).num()) T const& V=(A)[zzz];

// multimedia\opengl\scrsave\flwbox\ssflwbox.h
#define DIMA(a) (sizeof(a)/sizeof(a[0]))

// multimedia\opengl\server\generic\mcdcx.c
#define NUM_MCD_ENTRY_POINTS    (sizeof(pszMcdEntryPoints)/sizeof(char *))

// multimedia\opengl\test\auxprogs\rgb\wfperf.c
#define DRAW_COUNT (sizeof(draw_names)/sizeof(draw_names[0]))

// multimedia\opengl\test\demos\puzzle\puzzle.c
#define NBOXFACES (sizeof(boxfaces)/sizeof(boxfaces[0]))

// multimedia\opengl\test\glut\test\test10.c
#define NUM_FONTS (sizeof(fonts)/sizeof(void *))

// multimedia\opengl\test\simple\rgb\mfgls\mfgls.c
#define OGLMOD_COUNT (sizeof(ogl_modules)/sizeof(ogl_modules[0]))

// multimedia\published\dxmdev\dshowdev\include\aviriff.h
  #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// multimedia\published\wmsdk\inc\wmsdkidl.h
#define IWMStreamList_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMMutualExclusion_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMReaderNetworkConfig_GetUDPPortRanges(This,pRangeArray,pcRanges)	\
    (This)->lpVtbl -> GetUDPPortRanges(This,pRangeArray,pcRanges)
#define IWMReaderNetworkConfig_SetUDPPortRanges(This,pRangeArray,cRanges)	\
    (This)->lpVtbl -> SetUDPPortRanges(This,pRangeArray,cRanges)

// net\1394\arp\kdext\rmtest.h
#define ExInterlockedPopEntrySList(_l, _spinlock)	\
				(_l)->pList; {if ((_l)->pList) {(_l)->pList = (_l)->pList->Next;}}

// net\1394\arp\sys\priv.h
#define ARRAY_LENGTH(_array) (sizeof(_array)/sizeof((_array)[0]))

// net\1394\nic\sys\priv.h
#define nicSetCountInHistogram(_PktsInQueue, _Stats)    NdisInterlockedIncrement (&(_Stats.Bucket [ (_PktsInQueue/10) ] ) );
#define nicIncrementRcvTimerCount()                     NdisInterlockedIncrement(&RcvTimerCount);
#define nicIncrementSendTimerCount()                    NdisInterlockedIncrement(&SendTimerCount);
#define nicQueryTickCount()                     \
    LARGE_INTEGER   TickStart;                  \
    KeQueryTickCount(&TickStart);
#define nicIncrementRcvVcPktCount(_Vc, _Pkt)        \
{                                                   \
    if ((_Vc)->Hdr.VcType == NIC1394_RecvFIFO)      \
    {                                               \
        nicIncrementFifoRcvPktCount(_Vc, _Pkt);     \
    }                                               \
    else                                            \
    {                                               \
        nicIncrementChannelRcvPktCount(_Vc, _Pkt);  \
    }                                               \
}
#define nicIncrementVcSendPktCount(_Vc, _Pkt)       \
{                                                   \
    if ((_Vc)->Hdr.VcType == NIC1394_SendFIFO)      \
    {                                               \
        nicIncrementFifoSendPktCount(_Vc, _Pkt);    \
    }                                               \
    else                                            \
    {                                               \
        nicIncrementChannelSendPktCount(_Vc, _Pkt); \
    }                                               \
}

// net\1394\nic\sys\receive.h
#define ISOCH_PREFIX_LENGTH (sizeof(LONG) + sizeof (ISOCH_HEADER))

// net\atm\arp\atmarpc\arppkt.h
#define AA_PKT_LLC_SNAP_HEADER_LENGTH		(sizeof(AA_PKT_LLC_SNAP_HEADER))
#define AA_ARP_PKT_HEADER_LENGTH			(sizeof(AA_ARP_PKT_HEADER)-1)

// net\atm\arp\atmarpc\cmddk.h
#define KeInitializeEvent(_Event, _Type, _State)            \
    (_Event)->Header.Type = (UCHAR)_Type;                   \
    (_Event)->Header.Size =  sizeof(KEVENT) / sizeof(LONG); \
    (_Event)->Header.SignalState = _State;                  \
    InitializeListHead(&(_Event)->Header.WaitListHead)

// net\atm\arp\atmarpc\marspkt.h
#define AAMC_GET_TLV_TOTAL_LENGTH(_TlvLength)	\
			(sizeof(AA_MARS_TLV_HDR) +			\
			 (_TlvLength) +						\
			 ((4 - ((_TlvLength) & 3)) % 4))

// net\atm\epvc\notify\macros.h
#define celems(_x)          (sizeof(_x) / sizeof(_x[0]))

// net\atm\epvc\notify\typedefs.h
#define GUID_LENGTH sizeof(GUID) + 1

// net\atm\epvc\sys\macros.h
#define ARRAY_LENGTH(_array) (sizeof(_array)/sizeof((_array)[0]))

// net\atm\epvc\sys\priv.h
#define NIC_NUM_REG_PARAMS (sizeof (NICRegTable) / sizeof(MP_REG_ENTRY))

// net\atm\lane\exe\atmlane.c
#define NUMBER_OF_ELAN_STATES	(sizeof(ElanState)/sizeof(ElanState[0]))
#define NUMBER_OF_LAN_TYPES	(sizeof(LanType)/sizeof(LanType[0]))
#define NUMBER_OF_VC_TYPES	(sizeof(VcType)/sizeof(VcType[0]))
#define NUMBER_OF_MCAST_VC_TYPES	(sizeof(McastSendVcType)/sizeof(McastSendVcType[0]))
#define NUMBER_OF_MISC 	(sizeof(Misc)/sizeof(Misc[0]))
#define NUMBER_OF_CONN_TYPES 	(sizeof(ConnType)/sizeof(ConnType[0]))

// net\atm\lane\sys\macros.h
#define INIT_ATM_ENTRY_LOCK(pAe)		\
				INIT_LOCK(&((pAe)->AeLock), "atmentry")
#define INIT_ATM_ENTRY_LOCK(pAe)		\
				INIT_LOCK(&((pAe)->AeLock))
#define ACQUIRE_ATM_ENTRY_LOCK(pAe)		\
				ACQUIRE_LOCK(&((pAe)->AeLock), "atmentry")
#define ACQUIRE_ATM_ENTRY_LOCK(pAe)		\
				ACQUIRE_LOCK(&((pAe)->AeLock))
#define ACQUIRE_ATM_ENTRY_LOCK_DPC(pAe)		\
				ACQUIRE_LOCK_DPC(&((pAe)->AeLock), "atmentry")
#define ACQUIRE_ATM_ENTRY_LOCK_DPC(pAe)		\
				ACQUIRE_LOCK_DPC(&((pAe)->AeLock))
#define INIT_MAC_ENTRY_LOCK(pMe)		\
				INIT_LOCK(&((pMe)->MeLock), "macentry")
#define INIT_MAC_ENTRY_LOCK(pMe)		\
				INIT_LOCK(&((pMe)->MeLock))
#define ACQUIRE_MAC_ENTRY_LOCK(pMe)		\
				ACQUIRE_LOCK(&((pMe)->MeLock), "macentry")
#define ACQUIRE_MAC_ENTRY_LOCK(pMe)		\
				ACQUIRE_LOCK(&((pMe)->MeLock))
#define ACQUIRE_MAC_ENTRY_LOCK_DPC(pMe)		\
				ACQUIRE_LOCK_DPC(&((pMe)->MeLock), "macentry")
#define ACQUIRE_MAC_ENTRY_LOCK_DPC(pMe)		\
				ACQUIRE_LOCK_DPC(&((pMe)->MeLock))

// net\atm\rawwan\tdi\atmsp.h
#define TA_ATM_ADDRESS_LENGTH	(sizeof(ATMSP_SOCKADDR_ATM) + sizeof(USHORT))

// net\config\inc\ncdefine.h
#define celems(_x)          (sizeof(_x) / sizeof(_x[0]))

// net\config\shell\folder\webview.cpp
#define NCWVIEW_ENTRY_FILE(t, mt, i, cmd) \
    {&GUID_NULL, L"netshell.dll", (0), (t), (0), (mt), (IDS_##cmd), (i), (CNCWebView::CanShow##cmd), (CNCWebView::On##cmd) }

// net\config\shell\folder\webview.h
#define DECLARE_WEBVIEW_INVOKE_HANDLER(cmd) \
    static HRESULT cmd (IUnknown* pv, IShellItemArray *psiItemArray, IBindCtx *pbc);
#define DECLARE_CANSHOW_HANDLER(cmd) \
    static HRESULT cmd (IUnknown* pv, IShellItemArray *psiItemArray, BOOL fOkToBeSlow, UISTATE* puisState);
#define IMPLEMENT_WEBVIEW_INVOKE_HANDLER(clsname, cmd, verb)  \
HRESULT clsname##::##cmd (IUnknown* pv, IShellItemArray *psiItemArray, IBindCtx *pbc) \
{                                            \
    return WebviewVerbInvoke(verb, pv, psiItemArray); \
}
#define IMPLEMENT_CANSHOW_HANDLER(level, clsname, cmd, verb)  \
HRESULT clsname##::##cmd (IUnknown* pv, IShellItemArray *psiItemArray, BOOL fOkToBeSlow, UISTATE* puisState) \
{                                            \
    return WebviewVerbCanInvoke(verb, pv, psiItemArray, fOkToBeSlow, puisState, level); \
}

// net\dhcp\client\nt\dhcp.c
#define NUM_CRITICAL_SECTION    (sizeof(DhcpGlobalCriticalSections)/sizeof(DhcpGlobalCriticalSections[0]))

// net\dhcp\dhcpmib\dhcpmib.c
#define NUM_TABLES                sizeof(Tables)/sizeof(TAB_INFO_T)

// net\dhcp\dhcpprov\inc\lsscal.h
#define NUM_LEASE_PROPERTIES       (sizeof(DHCP_Lease_Property)/sizeof(CDHCP_Property))

// net\dhcp\dhcpprov\inc\resscal.h
#define NUM_RESERVATION_PROPERTIES       (sizeof(DHCP_Reservation_Property)/sizeof(CDHCP_Property))

// net\dhcp\dhcpprov\inc\snetscal.h
#define NUM_SUBNET_PROPERTIES       (sizeof(DHCP_Subnet_Property)/sizeof(CDHCP_Property))

// net\dhcp\dhcpprov\inc\srvscal.h
#define NUM_SERVER_PROPERTIES       (sizeof(DHCP_Server_Property)/sizeof(CDHCP_Property))

// net\dhcp\server\binl\client.c
#define OSC_VARIABLE_MAXIMUM_COUNT (sizeof(OscMaximums) / sizeof(OSC_VARIABLE_MAXIMUM))

// net\dhcp\server\binl\main.c
#define SCPDATACOUNT (sizeof(ScpDataKeys) / sizeof(PWSTR))

// net\dhcp\server\dhcpds\test\engine.c
#define  VarTableSz                (sizeof(VarTable)/sizeof(VarTable[0]))

// net\dhcp\server\server\dhcpdef.h
#define  DEFAULT_BOOTP_CLASSID_LENGTH (sizeof(DEFAULT_BOOTP_CLASSID)-1)

// net\diagnostics\netdiag\ipcfg.c
#define dim(X) (sizeof(X)/sizeof((X)[0]))

// net\diagnostics\netdiag\netdiag.h
#define DimensionOf(rg)	(sizeof(rg) / sizeof(*rg))

// net\dlc\driver\dlcreg.c
#define NUMBER_OF_DLC_PARAMETERS (sizeof(AdapterParameterTable)/sizeof(AdapterParameterTable[0]))

// net\dlc\driver\llcapi.h
#define LlcRemoveEntryList(Entry)               \
    {                                           \
        RemoveEntryList((PLIST_ENTRY)Entry);    \
        ((PLIST_ENTRY)(Entry))->Flink = NULL;   \
    }

// net\homenet\alg\alg_ftp\list.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// net\homenet\alg\alg_icq\list.h
#define RemoveEntryList(Entry)                                  \
{                                                               \
    PLIST_ENTRY _EX_Blink;                                      \
    PLIST_ENTRY _EX_Flink;                                      \
    _EX_Flink = (Entry)->Flink;                                 \
    _EX_Blink = (Entry)->Blink;                                 \
    _EX_Blink->Flink = _EX_Flink;                               \
    _EX_Flink->Blink = _EX_Blink;                               \
}

// net\ias\iasjet\setup\utils.cpp
    #define celems(_x)          (sizeof(_x) / sizeof(_x[0]))

// net\ias\providers\ntuser\lsa\iasparms.c
#define USER_PARMS_LEN (sizeof(USER_PARMS)/sizeof(WCHAR))

// net\ias\system\perfmon\schema.cpp
#define ARRAY_ELEMENTS(a) (sizeof(a)/sizeof((a)[0]))

// net\inc\isnipx.h
#define OPEN_REQUEST_EA_LENGTH(_Request) \
    (((IoGetCurrentIrpStackLocation(_Request))->Parameters.DeviceIoControl.InputBufferLength))

// net\inc\nbfhdrs.h
#define HEADER_LENGTH(_Hdr)      (*TempUShortCast( &(_Hdr)->Length ))

// net\inc\snmpexts.h
#define ELIST_SIZEOF(x)     (sizeof(x)/sizeof(SnmpMibEntry))
#define TLIST_SIZEOF(x)     (sizeof(x)/sizeof(SnmpMibTable))

// net\ipsec\polstore\dllsvr.c
#define COUNTOF(x) (sizeof x/sizeof *x)

// net\irda\irclass\irclass.c
#define NUM_BAUD_RATES (sizeof(BaudTable)/sizeof(TCHAR*))

// net\irda\samples\nscirda\settings.h
#define RCV_BUF_TO_LIST_ENTRY(b) ((PLIST_ENTRY)((PUCHAR)(b)-sizeof(LIST_ENTRY)))
#define LIST_ENTRY_TO_RCV_BUF(e) ((PVOID)((PUCHAR)(e)+sizeof(LIST_ENTRY)))

// net\irda\samples\nscirda\sync.h
#define NDISSynchronizedRemoveEntryList(entry, interrupt)                                           \
{                                                                                                   \
    SynchronizeList ListData;                                                                       \
                                                                                                    \
    ListData.Entry = (entry);                                                                       \
    ListData.Command = SyncRemove;                                                                  \
    (void)NdisMSynchronizeWithInterrupt((interrupt), SynchronizedListFunc, &ListData);    \
}

// net\jet500\jet\dae\inc\sysqry.c
#define cqryrowMax (sizeof(rgqryrow) / sizeof (QRYROW))

// net\jet500\jet\dae\src\info.c
#define ccolumndefGetIndexMax ( sizeof( rgcolumndefGetIndex ) / sizeof( JET_COLUMNDEF ) )

// net\jet500\jet\dae\src\sysdb.c
#define cCollate (sizeof(rgszConnect) / sizeof(CODECONST(char *)))
#define idcdMax (sizeof(rgdcd)/sizeof(DCD))
#define iaceMax (sizeof(rgace) / sizeof(ACE))

// net\jet500\jet\dae\src\systab.c
#define csystabs ( sizeof(rgsystabdef) / sizeof(SYSTABLEDEF) )

// net\jet500\jet\jet\src\compact.c
#define ccolumndefLIDMap ( sizeof( columndefLIDMap ) / sizeof( JET_COLUMNDEF ) )
#define ccolumndefTaggedMax ( sizeof( columndefTagged ) / sizeof( JET_COLUMNDEF ) )

// net\jet500\xjet\src\_cat.c
#define csystabs ( sizeof(rgsystabdef) / sizeof(SYSTABLEDEF) )

// net\jet500\xjet\src\dbutil.c
#define	ccolumndefSpaceInfoTable	( sizeof(rgcolumndefSpaceInfoTable) / sizeof(JET_COLUMNDEF) )

// net\jet500\xjet\src\info.c
#define ccolumndefGetIndexInfoMax ( sizeof( rgcolumndefGetIndexInfo ) / sizeof( JET_COLUMNDEF ) )

// net\jet500\xjet\src\sortapi.c
#define ccolumndefLIDMap ( sizeof( columndefLIDMap ) / sizeof( JET_COLUMNDEF ) )

// net\layer2svc\wlsnp\snpdata.h
#define END_SNAPINTOOLBARID_MAP(theClass) \
{ NULL, NULL, NULL, 0, 0, NULL } \
}; \
    int nElemCount = sizeof(m_tbInfo_##theClass)/sizeof(CSnapInToolbarInfo); \
    if (nElemCount > 1) \
{ \
    m_aToolbarInfo = new CSnapInToolbarInfo[nElemCount]; \
    if (NULL != m_aToolbarInfo) \
{ \
    CopyMemory( m_aToolbarInfo, m_tbInfo_##theClass, sizeof( CSnapInToolbarInfo ) * nElemCount ); \
} \
} \
    else { \
    ASSERT( 1 == nElemCount ); /* the NULL entry marking end-of-array */ \
    ASSERT( 0 == m_tbInfo_##theClass[0].m_idToolbar ); \
} \
} \
    return m_aToolbarInfo; \
}

// net\layer2svc\wlsnp\spolitem.cpp
#define celems(_x)          (sizeof(_x) / sizeof(_x[0]))

// net\layer2svc\wlstore\dllsvr.c
#define COUNTOF(x) (sizeof x/sizeof *x)

// net\mmc\common\xstream.h
#define XFER_COLUMNDATA_ARRAY   (XFER_COLUMNDATA | XFER_ARRAY)
#define XFER_STRING_ARRAY       (XFER_STRING | XFER_ARRAY)

// net\mmc\remrras\server\ncutil.h
#define celems(rgx)		(sizeof(rgx) / sizeof(*rgx))

// net\ndis\samples\coisdn\request.c
#define NUM_OID_ENTRIES (sizeof(g_SupportedOidArray) / sizeof(g_SupportedOidArray[0]))

// net\ndis\samples\isdnwan\request.c
#define NUM_OID_ENTRIES (sizeof(g_SupportedOidArray) / sizeof(g_SupportedOidArray[0]))

// net\ndis\samples\isdnwan\tspi.c
#define NUM_OID_ENTRIES (sizeof(TspiSupportedOidTable) / sizeof(TspiSupportedOidTable[0]))

// net\netbeui\sys\nbfprocs.h
#define INCREMENT_COUNTER(_DeviceContext,_Field) \
    ++(_DeviceContext)->Statistics._Field
#define DECREMENT_COUNTER(_DeviceContext,_Field) \
    --(_DeviceContext)->Statistics._Field

// net\netbeui\sys\nbftypes.h
#define IRP_SEND_LENGTH(_IrpSp) \
    (((PTP_SEND_IRP_PARAMETERS)&(_IrpSp)->Parameters)->Request.SendLength)
#define IRP_SEND_REFCOUNT(_IrpSp) \
    (((PTP_SEND_IRP_PARAMETERS)&(_IrpSp)->Parameters)->ReferenceCount)
#define IRP_RECEIVE_LENGTH(_IrpSp) \
    (((PTP_RECEIVE_IRP_PARAMETERS)&(_IrpSp)->Parameters)->Request.ReceiveLength)
#define IRP_RECEIVE_REFCOUNT(_IrpSp) \
    (((PTP_RECEIVE_IRP_PARAMETERS)&(_IrpSp)->Parameters)->ReferenceCount)

// net\netbios\sys\error.c
#define NUM_NB_ERRORS sizeof(Nb_Error_Map) / sizeof(Nb_Error_Map[0])

// net\netbt\inc\ctemacro.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// net\netbt\nbtstat\nbtstat.c
#define dim(X) (sizeof(X)/sizeof((X)[0]))

// net\nwlink\inc\isnnb.h
#define REQUEST_REFCOUNT(_Request) \
    (*((PULONG)&((_Request)->Tail.Overlay.ListEntry.Blink)))
#define NB_POP_ENTRY_LIST(_Queue, _Lock)           ExInterlockedPopEntryList(_Queue, &(_Lock)->Lock)
#define NB_PUSH_ENTRY_LIST(_Queue, _Entry, _Lock)  ExInterlockedPushEntryList(_Queue, _Entry, &(_Lock)->Lock)

// net\nwlink\ipx\ipxtypes.h
#define	NIC_ID_TO_BINDING(_device, _nicid) \
	((PBINDING)GET_VALUE( ((PBIND_ARRAY_ELEM) GET_VALUE( (_device)->Bindings) )[(SHORT)_nicid].Binding ))

// net\qos\inc\pktsched.h
#define InsertEntryList( Entry, EntryToInsert ) {           \
    (EntryToInsert)->Flink = (Entry)->Flink;                \
    (Entry)->Flink = (EntryToInsert);                       \
    (EntryToInsert)->Blink = (EntryToInsert)->Flink->Blink; \
    (EntryToInsert)->Flink->Blink = (EntryToInsert);        \
    }

// net\qos\pclass\gpc\handfact.c
#define NEW_HFEntry_array(_a,array_size) \
	GpcAllocMem(&_a,array_size * sizeof(HFEntry), HandleFactoryTag)
#define NEW_int_array(_a,array_size) \
	GpcAllocMem(&_a,array_size * sizeof(int), HandleFactoryTag)

// net\qos\psched\netshell\diffserv\qos-netsh\qosp.h
#define MAX_WSTR_LENGTH             (MAX_STRING_LENGTH * sizeof(WCHAR))

// net\qos\tc\dll\handfact.c
#define NEW_HFEntry_array(array_size) \
	((HFEntry *)malloc(array_size * sizeof(HFEntry)))
#define NEW_int_array(array_size) \
	((int *)malloc(array_size * sizeof(int)))

// net\qos\tc\dll\tcmacro.h
#define IS_LENGTH( _Length )                                   \
    (_Length + 3)/sizeof(ULONG)

// net\rras\cps\pbsmon\loaddata.h
#define NUM_OF_INFO_COUNTERS	((	sizeof(CPSMON_DATA_DEFINITION) -  \
									sizeof(PERF_OBJECT_TYPE)) /		\
									sizeof(PERF_COUNTER_DEFINITION) )

// net\rras\inc\rasman.h
#define MAX_PHONEENTRY_SIZE         (MAX_PHONENUMBER_SIZE < MAX_ENTRYNAME_SIZE \
                                    ? MAX_ENTRYNAME_SIZE                       \
                                    : MAX_PHONENUMBER_SIZE)

// net\rras\ip\btpagnt\defs.h
#define GetAsnCounter(srcBuf,defVal)                        \
    (((srcBuf)->asnType)? ((srcBuf)->asnValue.counter):(defVal))

// net\rras\ip\igmp\table.h
#define GET_IF_ENTRY_FOR_SOURCE(pSourceEntry) \
    pSourceEntry->pGIEntry->pIfTableEntry

// net\rras\ip\igmpagnt\defs.h
#define GetAsnCounter(srcBuf,defVal)                        \
    (((srcBuf)->asnType)? ((srcBuf)->asnValue.counter):(defVal))

// net\rras\ip\ipinip\ipinip.h
#define InitRefCount(pTunnel)                               \
    (pTunnel)->lRefCount = 2

// net\rras\ip\mcastmib\defs.h
#define GetAsnCounter(srcBuf,defVal)                        \
    (((srcBuf)->asnType)? ((srcBuf)->asnValue.counter):(defVal))

// net\rras\ip\nat\natwmi.c
#define NatWmiGuidCount (sizeof(NatWmiGuidList) / sizeof(WMIGUIDREGINFO))

// net\rras\ip\nath323\h323asn1.cpp
#define OID_ELEMENT(Index,Value) { (ASN1objectidentifier_s *) &_OID_Q931ProtocolIdentifierV2 [Index], Value },

// net\rras\ip\nath323\util.h
#define MAKE_REFERENCE_HISTORY_ENTRY() {                                           \
		PVOID CallersAddress, CallersCallersAddress;							   \
		RtlGetCallersAddress (&CallersAddress, &CallersCallersAddress);            \
		EnterCriticalSection (&ReferenceHistoryLock);                              \
		REFERENCE_HISTORY * ReferenceHistoryNode = ReferenceHistory.AllocAtEnd (); \
		ReferenceHistoryNode -> CallersAddress = CallersAddress;                   \
		ReferenceHistoryNode -> CurrentReferenceCount = Count;                     \
		LeaveCriticalSection (&ReferenceHistoryLock);                              \
	}

// net\rras\ip\rip\riptest.h
#define PREFIX_LENGTH8(a)   \
    (((a) & 0x01) ? 8 : \
    (((a) & 0x02) ? 7 : \
    (((a) & 0x04) ? 6 : \
    (((a) & 0x08) ? 5 : \
    (((a) & 0x10) ? 4 : \
    (((a) & 0x20) ? 3 : \
    (((a) & 0x40) ? 2 : \
    (((a) & 0x80) ? 1 : 0))))))))

// net\rras\ip\ripagnt\defs.h
#define GetAsnCounter(srcBuf,defVal)                        \
    (((srcBuf)->asnType)? ((srcBuf)->asnValue.counter):(defVal))

// net\rras\ip\sample\hashtable.h
#define HT_RemoveEntry(phtHashTable, pleEntry)          \
(                                                       \
    RemoveEntryList(pleEntry)                           \
    phtHashTable->ulNumEntries--;                       \
)

// net\rras\ip\sample\list.h
#define RemoveEntryList(Entry)                                  \
{                                                               \
    PLIST_ENTRY _EX_Blink;                                      \
    PLIST_ENTRY _EX_Flink;                                      \
    _EX_Flink = (Entry)->Flink;                                 \
    _EX_Blink = (Entry)->Blink;                                 \
    _EX_Blink->Flink = _EX_Flink;                               \
    _EX_Flink->Blink = _EX_Blink;                               \
}

// net\rras\ipx\rip\ripmain.c
#define MAX_IF_WORK_ITEM_HANDLERS	 sizeof(IfWorkItemHandler)/sizeof(IF_WORK_ITEM_HANDLER)

// net\rras\ipx\rtrmgr\ifmgr.c
#define MAX_IF_TRANSLATION_TYPES    sizeof(IfTypeTranslation)/sizeof(IF_TYPE_TRANSLATION)

// net\rras\ipx\rtrmgr\test\config.c
#define MAX_IF_TYPES	    sizeof(IfTypeTranslation)/sizeof(IF_TYPE_TRANSLATION)

// net\rras\ipx\rtrmgr\test\testmib.c
#define MAX_IPX_PROTOCOLS  sizeof(ProtName)/sizeof(RPNAM)

// net\rras\ipx\sap\saplpc.h
#define NWSAP_BS_PORT_MAX_MESSAGE_LENGTH                                         \
    ( sizeof(NWSAP_REQUEST_MESSAGE) > sizeof(NWSAP_REPLY_MESSAGE) ?    \
         sizeof(NWSAP_REQUEST_MESSAGE) : sizeof(NWSAP_REPLY_MESSAGE) )

// net\rras\ipx\snmp\rtipxmib.c
#define NUM_VIEWS (sizeof(v_rtipx)/sizeof(SnmpMibView))

// net\rras\ipx\snmp\rtipxmib.h
#define GetAsnCounter(srcBuf,defVal)\
    (((srcBuf)->asnType)			\
		? (srcBuf)->asnValue.counter\
		: defVal)
#define ForceAsnCounter(dstBuf,val) {				\
	(dstBuf)->asnType = ASN_RFC1155_COUNTER;		\
	(dstBuf)->asnValue.counter = (AsnCounter)(val);	\
	}

// net\rras\mprmsg\evttbl.h
#define CreateCompEntry(w,t)        \
    {w, sizeof(t)/sizeof(SUBCOMP_ENTRY), t}

// net\rras\ndis\ndiswan\io.c
#define MAX_FUNC_CODES  sizeof(IoDispatchTable)/sizeof(IO_DISPATCH_TABLE)

// net\rras\ndis\ndproxy\kdext\kdexts.c
#define cArchitecture (sizeof(szProcessorArchitecture) / sizeof(PSZ))

// net\rras\ndis\ndproxy\pxntinit.c
#define MAX_TAPI_SUPPORTED_OIDS     (sizeof(TapiOids)/sizeof(OID_DISPATCH))

// net\rras\ndis\ndproxy\pxutils.c
#define PX_TCP_NUM_ENTRIES  (sizeof(PxTapiCallParamList) / sizeof(PXTAPI_CALL_PARAM_ENTRY))
#define PX_TCI_NUM_ENTRIES  (sizeof(PxTapiCallInfoList) / sizeof(PXTAPI_CALL_INFO_ENTRY))

// net\rras\ndis\rasl2tp\kdext\kdexts.c
#define cArchitecture (sizeof(szProcessorArchitecture) / sizeof(PSZ))

// net\rras\netsh\aaaa\iasmdbtool.cpp
#define celems(_x)          (sizeof(_x) / sizeof(_x[0]))

// net\rras\netsh\ip\preview\msdpmib.c
#define MAX_MSDP_MIB_OBJECTS (sizeof(MsdpMIBObjectMap)/sizeof(MIB_OBJECT_PARSER))

// net\rras\netsh\ras\rasaaaa.c
#define g_dwArgsAuthCount (sizeof(g_pArgsAuth) / sizeof(*g_pArgsAuth))
#define g_dwArgsAcctCount (sizeof(g_pArgsAcct) / sizeof(*g_pArgsAcct))

// net\rras\ras\ppp\engine\bltincps.h
#define NUM_BUILT_IN_CPS (sizeof(BuiltInCps)/sizeof(BUILT_IN_CP))

// net\rras\ras\rassfm\usrparms.c
#define NUM_UPLEVEL_PARMS (sizeof(UPLEVEL_PARMS)/sizeof(UPLEVEL_PARMS[0]))

// net\rras\ras\ui\common\nouiutil\noui.c
    #define celems(_x) (sizeof(_x) / sizeof(_x[0]))

// net\rras\ras\ui\common\sharing\sainfo.c
#define LSTRLEN(s) ((sizeof(s) / sizeof(TCHAR)) - 1)

// net\rras\ras\ui\common\sharing\sharing.h
#define Dimension(x)        (sizeof(x) / sizeof(x[0]))

// net\rras\ras\ui\inc\common.h
#define ARRAY_ELEMENTS(rg)          (sizeof(rg) / sizeof((rg)[0]))

// net\rras\ras\ui\inc\list.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// net\rras\ras\ui\inc\mem.h
#define GAllocArray(type, cNum)          (type *)GAlloc(sizeof(type) * (cNum))
#define GReAllocArray(type, pb, cNum)    (type *)GReAlloc(pb, sizeof(type) * (cNum))
#define SharedAllocArray(type, cNum)    (type *)SharedAlloc(sizeof(type) * (cNum))
#define SharedReAllocArray(type, pb, cNum) (type *)SharedReAlloc(pb, sizeof(type) * (cNum))
#define SharedAllocArray(type, cNum)    (type *)SharedAlloc(sizeof(type) * (cNum))
#define SharedReAllocArray(type, pb, cNum) (type *)SharedReAlloc(pb, sizeof(type) * (cNum))

// net\rras\ras\ui\nt4\inc\list.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// net\rras\rtm\rtmdlg.h
#define GetTickCount() (GetTickCount()&MaxTicks)

// net\rras\rtmv2\rtmchng.h
#define EnqueueItem(Q, I, S)                                         \
{                                                                    \
    UINT _R_;                                                        \
                                                                     \
    _R_ = ((Q)->Rear + 1) % (Q)->Size;                               \
                                                                     \
    if ((Q)->Front == (_R_))                                         \
    {                                                                \
        (S) = TRUE;                                                  \
    }                                                                \
    else                                                             \
    {                                                                \
        (Q)->Rear = (_R_);                                           \
                                                                     \
        (Q)->Array[(Q)->Rear] = I;                                   \
                                                                     \
        (S) = FALSE;                                                 \
    }                                                                \
}                                                                    \
#define DequeueItem(Q, I)                                            \
                                                                     \
    if ((Q)->Front == (Q)->Rear)                                     \
    {                                                                \
        (*(I)) = NULL;                                               \
    }                                                                \
    else                                                             \
    {                                                                \
        ((Q)->Front)++;                                              \
                                                                     \
        ((Q)->Front) %= (Q)->Size;                                   \
                                                                     \
        (*(I)) = (Q)->Array[(Q)->Front];                             \
    }                                                                \

// net\sfm\afp\server\afpconst.h
#define	AFP_MAX_STREAMNAME			sizeof(AFP_RESC_STREAM)/sizeof(WCHAR)

// net\sfm\afp\server\forks.h
#define	VALID_OPENFORKENTRY(pOpenForkEntry)	\
						(((pOpenForkEntry) != NULL) && \
						 ((pOpenForkEntry)->Signature == OPENFORKENTRY_SIGNATURE))

// net\sfm\atalk\sys\atkinit.c
#define					prefixLength	(sizeof(L"\\Device\\") - sizeof(WCHAR))

// net\sfm\inc\atalktdi.h
#define OPTIONS_LENGTH	sizeof(OPTIONS_CONNINF)

// net\sockets\winsock2\ws2help\inc\ws2ifsl.h
#define WS2IFSL_SOCKET_EA_NAME_LENGTH   (sizeof(WS2IFSL_SOCKET_EA_NAME)-1)
#define WS2IFSL_SOCKET_EA_VALUE_LENGTH  (sizeof(WS2IFSL_SOCKET_CTX))
#define WS2IFSL_PROCESS_EA_NAME_LENGTH  (sizeof(WS2IFSL_PROCESS_EA_NAME)-1)
#define WS2IFSL_PROCESS_EA_VALUE_LENGTH (sizeof(WS2IFSL_PROCESS_CTX))

// net\sockets\winsock2\wsp\afdsys\afddata.h
#define AFD_DEFAULT_STD_ADDRESS_LENGTH sizeof(TA_IP_ADDRESS)

// net\sockets\winsock2\wsp\afdsys\init.c
#define AFD_CONFIG_VAR_COUNT (sizeof(AfdConfigInfo) / sizeof(AfdConfigInfo[0]))
#define AFD_VOLATILE_CONFIG_VAR_COUNT (sizeof(AfdVolatileConfigInfo) / sizeof(AfdVolatileConfigInfo[0]))

// net\tapi\inc\tlnklist.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// net\tapi\litesabr\filters\amrtpnet\globals.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// net\tapi\litesabr\filters\ppm\main.cpp
#define NUM_CLSIDS (sizeof(clsid_array)/sizeof(clsid_array[0]))

// net\tapi\rtc\phoenix\src\sip\md5digest.cpp
#define COUNTED_STRING_PRINTF(CountedString) \
    (CountedString) -> Length / sizeof (*(CountedString) -> Buffer), \
    (CountedString) -> Buffer
#define INITIALIZE_CONST_COUNTED_STRING(Text) \
    { sizeof (Text) - sizeof (*Text), sizeof (Text) - sizeof (*Text), (Text) }

// net\tapi\rtc\phoenix\src\sip\msgtest\main.cpp
#define	COUNTED_STRING_PRINTF(pCountedString) \
	(pCountedString)->Length, (pCountedString)->Buffer

// net\tapi\rtc\phoenix\src\sip\register.cpp
#define COUNTSTR_ENTRY(String) String, sizeof(String) - 1

// net\tapi\rtc\phoenix\src\sip\siphdr.cpp
#define METHOD_ENTRY(String) String, sizeof(String) - 1
#define HEADER_ENTRY(String) String, sizeof(String) - 1
#define HEADER_PARAM_ENTRY(String) String, sizeof(String) - 1
#define SIP_URL_PARAM_ENTRY(String) String, sizeof(String) - 1

// net\tapi\rtc\phoenix\src\sip\ssltest\rtcstring.h
#define	INITIALIZE_CONST_COUNTED_STRING(Text) \
	{ sizeof (Text) - sizeof (*Text), sizeof (Text) - sizeof (*Text), (Text) }
#define	COUNTED_STRING_PRINTF(CountedString) \
	(CountedString) -> Length / sizeof (*(CountedString) -> Buffer), \
	(CountedString) -> Buffer

// net\tapi\rtc\phoenix\src\sip\util.h
#define	COUNTED_STRING_PRINTF(CountedString) \
	(CountedString) -> Length / sizeof (*(CountedString) -> Buffer), \
	(CountedString) -> Buffer

// net\tapi\skywalker\apps\avdialer\avlib\array.c
#define ElemCompare(lpi, lpj) \
	(lpfnCompare == NULL ? MemCmp(lpi, lpj, sizeof(ARRAYELEM)) : lpfnCompare(lpi, lpj))

// net\tapi\skywalker\apps\avdialer\avlib\winlocal.h
#define SIZEOFARRAY(a) (sizeof(a) / sizeof(a[0]))

// net\tapi\skywalker\filters\rtp\msrtp\funcs\rtpqos.c
#define QOS_NAMES (sizeof(g_QosInfo)/sizeof(g_QosInfo[0]))

// net\tapi\skywalker\h323\tsp\q931obj.h
#define	ACCEPT_BUFFER_LENGTH		((sizeof(SOCKADDR_IN) + 0x10) * 2)

// net\tapi\skywalker\h323\tsp\ras.cpp
#define OID_ELEMENT(Index,Value) { (ASN1objectidentifier_s *) &_OID_H225ProtocolIdentifierV1 [Index], Value },
#define OID_ELEMENT(Index,Value) { (ASN1objectidentifier_s *) &_OID_H225ProtocolIdentifierV2 [Index], Value },

// net\tapi\skywalker\h323tsp\globals.h
#define H323GetNumStrings(_apsz_) \
    (sizeof(_apsz_)/sizeof(PSTR))

// net\tapi\skywalker\h323tsp\termcaps.h
#define SIZEOF_TERMCAPLIST(_TermCapArray_) \
    (sizeof(_TermCapArray_)/sizeof(PPCC_TERMCAP))

// net\tapi\skywalker\parser\sdpstran.h
#define STATE_TRANSITION_ENTRY(State, TransitionsArray)   \
{State,  sizeof(TransitionsArray)/sizeof(STATE_TRANSITION), TransitionsArray }

// net\tapi\thunk\windows.h
#define EM_GETLINECOUNT         (WM_USER+10)
#define EM_LINELENGTH           (WM_USER+17)
#define LB_GETCOUNT             (WM_USER+12)
#define LB_GETSELCOUNT          (WM_USER+17)
#define LB_SETCOUNT             (WM_USER+40)    // ;Internal NT
#define CB_GETCOUNT             (WM_USER+6)

// net\tapi\tregupr2\tregupr2.c
#define US_COUNTRY_CODE(x)	((x) == 1 || \
		(x >= 100 && x < 200))

// net\tcpip\apis\iphlpapi\lib\ipconfig.c
#define NUMBER_OF_NODE_TYPES (sizeof(NodeTypes)/sizeof(NodeTypes[0]))
#define NUMBER_OF_ADAPTER_TYPES (sizeof(AdapterTypes)/sizeof(AdapterTypes[0]))
#define NUMBER_OF_MISC_MESSAGES (sizeof(MiscMessages)/sizeof(MiscMessages[0]))

// net\tcpip\commands\ipconfig\display.c
#define Dimension(X) (sizeof(X)/sizeof(X[0]))

// net\tcpip\driver\ipsec\kdext\kdexts.c
#define cArchitecture (sizeof(szProcessorArchitecture) / sizeof(PSZ))

// net\tcpip\driver\ipsec\sys\ah.h
#define NUM_AUTH_ALGOS (sizeof(auth_algorithms)/sizeof(AUTH_ALGO)-1)

// net\tcpip\driver\ipsec\sys\esp.h
#define NUM_CONF_ALGOS (sizeof(conf_algorithms)/sizeof(CONFID_ALGO)-1)

// net\tcpip\driver\ipsec\sys\macros.h
#define INVALIDATE_CACHE_ENTRY(_entry)              \
{                                                   \
    ((PFILTER_CACHE)(_entry))->pSAEntry = NULL;     \
    ((PFILTER_CACHE)(_entry))->pNextSAEntry = NULL; \
}                                                   \

// net\tcpip\driver\ipv4\ipdef.h
#define MAX_DATA_LENGTH         (MAX_TOTAL_LENGTH - sizeof(IPHeader))

// net\tcpip\driver\ipv4\ipmcast.h
#define RemoveEntryFwq(Entry)                       \
{                                                   \
    FWQ     *_EX_Blink;                             \
    FWQ     *_EX_Flink;                             \
    _EX_Flink = (Entry)->fq_next;                   \
    _EX_Blink = (Entry)->fq_prev;                   \
    _EX_Blink->fq_next = _EX_Flink;                 \
    _EX_Flink->fq_prev = _EX_Blink;                 \
}
#define InitRefCount(pSource)                               \
    (pSource)->lRefCount = 2

// net\tcpip\services\lpd\sockets.c
#define NUM_FAMILIES (sizeof(family) / sizeof(FAMILY))

// net\tcpip\services\simple\simptcp.c
#define NUM_FAMILIES (sizeof(family) / sizeof(FAMILY))

// net\tcpip\services\telnet\server\tlntsess\fsm.cpp
#define NUM_TRANSITIONS (sizeof(telnetTransTable)/sizeof(telnetTransTable[0]))

// net\tcpip\snmp\defs.h
#define GetAsnCounter(srcBuf,defVal)                        \
    (((srcBuf)->asnType)? ((srcBuf)->asnValue.counter):(defVal))

// net\tcpip\tools\ipfw\ipfw.h
#define IPFW_CREATE_NAME_LENGTH (sizeof(IPFW_CREATE_NAME) - 1)

// net\tcpip\tpipv6\ipv6\ipv6.c
#define MAX_PREFIX_CONF (sizeof(PrefixConfStr) / sizeof(char *))
#define MAX_IID_CONF (sizeof(InterfaceIdConfStr) / sizeof(char *))

// net\tcpip\tpipv6\samples\testai\testai.c
#define NUMBER_GAI_TESTS (sizeof(GAITestArray) / sizeof(GAITestEntry))

// net\unimodem\src\atmini\command.c
#define  NONE_COMMAND_LENGTH         (sizeof(NONE_COMMAND)-1)
#define  NORESPONSE_COMMAND_LENGTH   (sizeof(NORESPONSE_COMMAND)-1)

// net\unimodem\src\mdminst\ci.c
#define NUM_PROTOCOLS sizeof(PriorityProtocols)/sizeof(PriorityProtocols[0])

// net\unimodem\src\modemui\cpldiag.c
#define NUM_UIBAUD (sizeof(g_rguiBaud)/sizeof(g_rguiBaud[0]))

// net\unimodem\src\tsp\cdevcall.cpp
                #define CONNECT_TAG_SUFFIX_LENGTH (sizeof(CONNECT_TAG_SUFFIX)-sizeof(CHAR))

// net\upnp\host\upnphost\inc\servutil.h
#define ARRAYSIZEOF(x)  (sizeof(x) / sizeof((x)[0]))

// net\upnp\host\upnphost\inc\svsutil.hxx
#define SVSUTIL_ARRLEN(array)           (sizeof(array)/sizeof(array[0]))
#define SVSUTIL_PGUID_ELEMENTS(p) \
    p->Data1,                 p->Data2,    p->Data3,\
    p->Data4[0], p->Data4[1], p->Data4[2], p->Data4[3],\
    p->Data4[4], p->Data4[5], p->Data4[6], p->Data4[7]

// net\upnp\host\upnphost\udhhttp\parser.cpp
#define TABLEENTRY(csz, id, pfn)    { csz, sizeof(csz)-1, id, PFNPARSE(pfn) }

// net\upnp\inc\list.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// net\upnp\inc\ncdefine.h
#define celems(_x)          (sizeof(_x) / sizeof(_x[0]))

// net\upnp\ssdp\inc\list.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// net\winnet\mprdata.h
#define LENGTH(array)   (sizeof(array)/sizeof((array)[0]))

// net\wins\mib\winsmib.c
#define NUM_TABLES                sizeof(Tables)/sizeof(TAB_INFO_T)

// net\wins\perfctrs\winsdata.h
#define NUMBER_OF_WINSDATA_COUNTERS ((sizeof(WINSDATA_DATA_DEFINITION) -      \
                                  sizeof(PERF_OBJECT_TYPE)) /           \
                                  sizeof(PERF_COUNTER_DEFINITION))

// net\wins\server\inc\nmsdb.h
#define NMSDB_ENTRY_GRP_M(EntTyp)      ((EntTyp) == NMSDB_NORM_GRP_ENTRY || \
                                         (EntTyp) == NMSDB_SPEC_GRP_ENTRY)
#define NMSDB_ENTRY_USER_SPEC_GRP_M(pName, EntTyp)  ((NMSDB_ENTRY_SPEC_GRP_M((EntTyp))) && !(NMSDB_IS_IT_SPEC_GRP_NM_M((pName))))
#define NMSDB_SIZEOFJETFTBL  sizeof(NmsDbJetFTbl)/sizeof(NMSDB_JETFTBL_T)

// net\wins\server\inc\rpl.h
#define  RPL_REC_ENTRY_SIZE        (sizeof(RPL_REC_ENTRY_T) + \
                                   (8 - sizeof(RPL_REC_ENTRY_T)%8))
#define  RPL_REC_ENTRY2_SIZE        (sizeof(RPL_REC_ENTRY2_T) + \
                                   (8 - sizeof(RPL_REC_ENTRY2_T)%8))

// net\wins\server\msc\winscnf.c
         #define      FUNC_TBL_ENTRY( _Dll, _Name ) { _Dll, &(#_Name)[1], NULL }

// net\wlbs\nlbmgr\provider\myntrtl.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// printscan\fax\admin\faxadmin\faxstrt.cpp
#define CountStringTable ( sizeof(StringTable) / sizeof(STRING_TABLE) )

// printscan\fax\exchange\ab\abeid.h
#define CBDIR_ENTRYID sizeof(DIR_ENTRYID)
#define CBUSR_ENTRYID sizeof(USR_ENTRYID)
#define CBOOUSER_ENTRYID sizeof(OOUSER_ENTRYID)
#define CBTEMPLATEID_ENTRYID sizeof(TEMPLATEID_ENTRYID)

// printscan\fax\exchange\ab\abuser.h
#define CBOPTIONS_ENTRYID sizeof(OPTIONS_ENTRYID)

// printscan\fax\faxcover\src\awcpe.h
#define _countof(array) (sizeof(array)/sizeof(array[0]))

// printscan\fax\faxview\faxview.c
#define MAX_TOOLBAR_STATES (sizeof(ToolbarState)/sizeof(TOOLBAR_STATE))
#define MAX_ZOOMS (sizeof(Zooms)/sizeof(double))

// printscan\fax\inc\dapi.h
#define cchSubstServer        ((sizeof (pszSubstServerA) / sizeof(CHAR)) - 1)

// printscan\fax\print\faxprint\test\decode\decode.c
#define MMR_TABLE_SIZE  (sizeof(MMRCodes) / sizeof(CODETABLE))
#define RUN_TABLE_SIZE  (sizeof(BlackRunCodes) / sizeof(CODETABLE))

// printscan\fax\provider\t30\headers\ifaxos.h
#define COUNTER_VALUESET     (COUNTER_CLEARSET | COUNTER_UPDATE_TIMESTAMP)

// printscan\fax\samples\ncfsp\util.cpp
#define CountStringTable (sizeof(StringTable)/sizeof(STRING_TABLE))

// printscan\fax\service\faxmapi\util.cpp
#define CountStringTable (sizeof(StringTable)/sizeof(STRING_TABLE))

// printscan\fax\service\faxroute\util.cpp
#define CountStringTable (sizeof(StringTable)/sizeof(STRING_TABLE))

// printscan\fax\service\server\security.c
#define FaxSecurityCount (sizeof(FaxSecurity)/sizeof(FAX_SECURITY))

// printscan\fax\service\server\server.c
#define PROTOCOL_COUNT (sizeof(Protocols)/sizeof(Protocols[0]))

// printscan\fax\service\server\util.c
#define CountStringTable (sizeof(StringTable)/sizeof(STRING_TABLE))

// printscan\fax\service\stattest\stattest.c
#define NumEventStrings ((sizeof(EventStrings)/sizeof(EVENT_STRINGS))-1)

// printscan\fax\setup\ocm\faxocm.cpp
#define CountUnattendAnswers  (sizeof(UnattendAnswer)/sizeof(UNATTEND_ANSWER))

// printscan\fax\setup\ocm\fileq.cpp
#define CountMinimalServerFileQueue (sizeof(MinimalServerFileQueue)/sizeof(FILE_QUEUE_INFO))
#define CountServerFileQueue (sizeof(ServerFileQueue)/sizeof(FILE_QUEUE_INFO))
#define CountClientFileQueue (sizeof(ClientFileQueue)/sizeof(FILE_QUEUE_INFO))

// printscan\fax\setup\ocm\groups.cpp
#define MAX_GROUP_ITEMS  (sizeof(GroupItems)/sizeof(GroupItems[0]))

// printscan\fax\setup\ocm\util.cpp
#define CountStringTable (sizeof(StringTable)/sizeof(STRING_TABLE))

// printscan\fax\setup\setup\faxsetup.c
#define CountStringTable (sizeof(StringTable)/sizeof(STRING_TABLE))

// printscan\fax\setup\win9xupg\inc\ifaxos.h
#define COUNTER_VALUESET     (COUNTER_CLEARSET | COUNTER_UPDATE_TIMESTAMP)

// printscan\fax\setup\wizdll\client.c
#define CountClientFileQueue (sizeof(ClientFileQueue)/sizeof(FILE_QUEUE_INFO))
#define CountPointPrintFileQueue (sizeof(PointPrintFileQueue)/sizeof(FILE_QUEUE_INFO))

// printscan\fax\setup\wizdll\groups.c
#define MAX_REMOTE_ADMIN_GROUP_ITEMS  (sizeof(RemoteAdminGroupItems)/sizeof(RemoteAdminGroupItems[0]))
#define MAX_GROUP_ITEMS  (sizeof(GroupItems)/sizeof(GroupItems[0]))
#define MAX_USER_GROUP_ITEMS  (sizeof(UserGroupItems)/sizeof(UserGroupItems[0]))

// printscan\fax\setup\wizdll\ra.c
#define CountRemoteAdminFileQueue (sizeof(RemoteAdminFileQueue)/sizeof(FILE_QUEUE_INFO))

// printscan\fax\setup\wizdll\server.c
#define CountServerFileQueue (sizeof(ServerFileQueue)/sizeof(FILE_QUEUE_INFO))
#define CountWorkstationFileQueue (sizeof(WorkstationFileQueue)/sizeof(FILE_QUEUE_INFO))
#define CountDriverClientFileQueue (sizeof(DriverClientFileQueue)/sizeof(FILE_QUEUE_INFO))

// printscan\fax\setup\wizdll\unattend.c
#define NumAnswers (sizeof(UnattendAnswerTable)/sizeof(UNATTEND_ANSWER))

// printscan\fax\setup\wizdll\uninstal.c
#define CountUninstallFileQueue (sizeof(UninstallFileQueue)/sizeof(FILE_QUEUE_INFO))

// printscan\fax\setup\wizdll\util.c
#define CountStringTable (sizeof(StringTable)/sizeof(STRING_TABLE))

// printscan\fax\shellext\faxshell.h
#define ColumnTableCount  (sizeof(ColumnTable) / sizeof(COLUMN_TABLE))

// printscan\fax\tiff\dump\tiffdump.c
#define NWIDTHS (sizeof (datawidth) / sizeof (datawidth[0]))
#define NTAGS   (sizeof (tagnames) / sizeof (tagnames[0]))
#define NTYPES  (sizeof (typenames) / sizeof (typenames[0]))

// printscan\fax\tiff\src\tifftabl.h
#define WhiteRunCodeEntries  (sizeof(WhiteRunCodes)/sizeof(CODETABLE))
#define BlackRunCodeEntries  (sizeof(BlackRunCodes)/sizeof(CODETABLE))
#define WhiteDecodeEntries  (sizeof(WhiteDecodeTree)/sizeof(DECODE_TREE))
#define BlackDecodeEntries  (sizeof(BlackDecodeTree)/sizeof(DECODE_TREE))

// printscan\faxsrv\src\faxcover\src\awcpe.h
#define _countof(array) (sizeof(array)/sizeof(array[0]))

// printscan\faxsrv\src\inc\dapi.h
#define cchSubstServer        ((sizeof (pszSubstServerA) / sizeof(CHAR)) - 1)

// printscan\faxsrv\src\inc\faxmmc.h
#define FAXSRV_MAX_GUID_LEN              sizeof(FAXSRV_DEVICE_NODETYPE_GUID_STR)/sizeof(WCHAR)

// printscan\faxsrv\src\inc\faxutil.h
#define ARR_SIZE(x) (sizeof(x)/sizeof((x)[0]))

// printscan\faxsrv\src\print\faxprint\faxui\devinfo.c
#define ColumnHeaderCount sizeof(ColumnHeader)/sizeof(COLUMN_HEADER)

// printscan\faxsrv\src\print\faxprint\faxui\docevent.c
#define SZ_CONT_SIZE                        (sizeof(SZ_CONT) / sizeof(TCHAR))

// printscan\faxsrv\src\print\faxprint\faxui\util.c
#define CountStringTable (sizeof(StringTable)/sizeof(STRING_TABLE))

// printscan\faxsrv\src\provider\t30\headers\ifaxos.h
#define COUNTER_VALUESET     (COUNTER_CLEARSET | COUNTER_UPDATE_TIMESTAMP)

// printscan\faxsrv\src\sdktools\msvc15\include\variant.h
#define V_ISARRAY(X)     (V_VT(X)&VT_ARRAY)

// printscan\faxsrv\src\sdktools\msvc15\include\wfext.h
#define FM_GETSELCOUNT		(WM_USER + 0x0202)
#define FM_GETSELCOUNTLFN	(WM_USER + 0x0203)	/* LFN versions are odd */

// printscan\faxsrv\src\sdktools\msvc15\include\windows.h
#define EM_GETLINECOUNT         (WM_USER+10)
#define EM_LINELENGTH	        (WM_USER+17)
#define LB_GETCOUNT	       (WM_USER+12)
#define LB_GETSELCOUNT	       (WM_USER+17)
#define CB_GETCOUNT	         (WM_USER+6)

// printscan\faxsrv\src\sdktools\msvc15\include\winsock.h
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
        ((fd_set FAR *)(set))->fd_array[((fd_set FAR *)(set))->fd_count++]=(fd);\
} while(0)

// printscan\faxsrv\src\service\faxmapi\util.cpp
#define CountStringTable (sizeof(StringTable)/sizeof(STRING_TABLE))

// printscan\faxsrv\src\service\faxroute\util.cpp
#define CountStringTable (sizeof(StringTable)/sizeof(STRING_TABLE))

// printscan\faxsrv\src\service\server\archive.c
#define FAX_MESSAGE_PROPERTIES (sizeof(pspecFaxMessage)/sizeof(pspecFaxMessage[0]))
#define FAX_RECIP_PROPERTIES (sizeof(pspecFaxRecipient)/sizeof(pspecFaxRecipient[0]))
#define FAX_SENDER_PROPERTIES (sizeof(pspecFaxSender)/sizeof(pspecFaxSender[0]))

// printscan\faxsrv\src\service\server\server.c
#define PROTOCOL_COUNT (sizeof(gc_Protocols)/sizeof(gc_Protocols[0]))

// printscan\faxsrv\src\setup\ocm\fxunatnd.cpp
#define prv_NUM_UNATTENDED_RULES sizeof(prv_UnattendedRules) / sizeof(prv_UnattendedRules[0])

// printscan\faxsrv\src\setup\win9xupg\inc\ifaxos.h
#define COUNTER_VALUESET     (COUNTER_CLEARSET | COUNTER_UPDATE_TIMESTAMP)

// printscan\faxsrv\src\test\src\queuefunctionality\jobmngr\cjobtypes.h
#define SendJobTypeStrTableSize ( sizeof(SendJobTypeStrTable) / sizeof(JOB_TYPE_STR))

// printscan\faxsrv\src\test\src\queuefunctionality\jobmngr\testcases\inifilesettings.h
#define SectionEntriesArraySize ( sizeof(SectionEntriesArray) / sizeof(tstring))

// printscan\faxsrv\src\test\src\util\fax\faxclasses\stringtable.h
#define FaxTableSize ( sizeof(FaxEventTable) / sizeof(FAX_EVENT_STR))
#define JobStateTableSize ( sizeof(JobStatetTable) / sizeof(JOB_STATE_STR))

// printscan\faxsrv\src\test\src\xxxunusedxxx\deviceioctls\device.h
#define ARRSIZE(a) (sizeof(a)/sizeof(a[0]))

// printscan\faxsrv\src\test\src\xxxunusedxxx\deviceioctls\ipioctl.cpp
#define NUM_OF_INTERFACE_NAMES (sizeof(s_wszIterfaceName)/sizeof(*s_wszIterfaceName))

// printscan\faxsrv\src\tiff\src\tifftabl.h
#define WhiteRunCodeEntries  (sizeof(WhiteRunCodes)/sizeof(CODETABLE))
#define BlackRunCodeEntries  (sizeof(BlackRunCodes)/sizeof(CODETABLE))
#define WhiteDecodeEntries  (sizeof(WhiteDecodeTree)/sizeof(DECODE_TREE))
#define BlackDecodeEntries  (sizeof(BlackDecodeTree)/sizeof(DECODE_TREE))

// printscan\inc\psutil\coredefs.h
#define COUNTOF(x) (sizeof(x)/sizeof(x[0]))

// printscan\print\drivers\usermode\ddk\samples\oemdll\oemps\precomp.h
#define COUNTOF(p)  (sizeof(p)/sizeof(*(p)))

// printscan\print\drivers\usermode\ddk\samples\oemdll\oemui\precomp.h
#define COUNTOF(p)  (sizeof(p)/sizeof(*(p)))

// printscan\print\drivers\usermode\ddk\samples\oemdll\oemuni\precomp.h
#define COUNTOF(p)  (sizeof(p)/sizeof(*(p)))

// printscan\print\drivers\usermode\ddk\samples\oemdll\psuirep\precomp.h
#define COUNTOF(p)  (sizeof(p)/sizeof(*(p)))

// printscan\print\drivers\usermode\ddk\samples\oemdll\themeui\precomp.h
#define COUNTOF(p)  (sizeof(p)/sizeof(*(p)))

// printscan\print\drivers\usermode\ddk\samples\oemdll\watermark\wmarkps\precomp.h
#define COUNTOF(p)  (sizeof(p)/sizeof(*(p)))

// printscan\print\drivers\usermode\ddk\samples\oemdll\watermark\wmarkui\precomp.h
#define COUNTOF(p)  (sizeof(p)/sizeof(*(p)))

// printscan\print\drivers\usermode\driverui\driverui.h
#define PGetDevmodeOptionsArray(pdm) \
        (((PDRIVEREXTRA) GET_DRIVER_PRIVATE_DEVMODE(pdm))->aOptions)

// printscan\print\drivers\usermode\driverui\uni\softfont.c
#define NUM_CTTMAP      (sizeof( CttMap ) / sizeof( CttMap[ 0 ] ))
#define MAX_CLASS_MAP   (sizeof( dwClassMap ) / sizeof( dwClassMap[ 0 ] ))
#define NUM_TYPEFACE    (sizeof( pwcName ) / sizeof( pwcName[ 0 ] ))

// printscan\print\drivers\usermode\gpdres\alpsres\alpsres.c
#define PAPER_SIZE_MAX      (sizeof(gPapeSize)/sizeof(gPaperSize[0]) - 1)

// printscan\print\drivers\usermode\lib\xcf\xcf_priv.h
#define ARRAY_LEN(t) (sizeof(t)/sizeof((t)[0]))

// printscan\print\drivers\usermode\msplot\plotter\enable.c
#define TOTAL_DRVFUNC   (sizeof(DrvFuncTable)/sizeof(DrvFuncTable[0]))

// printscan\print\drivers\usermode\msplot\plotter\output.c
#define SAME_PPALENTRY(p1,p2)   (((p1)->R == (p2)->R) &&        \
                                 ((p1)->G == (p2)->G) &&        \
                                 ((p1)->B == (p2)->B))

// printscan\print\drivers\usermode\msplot\plotter\plotters.h
#define COUNT_ARRAY(x)      (sizeof((x)) / sizeof((x)[0]))

// printscan\print\drivers\usermode\msplot\plotter\ropblt.c
#define GET_MIX2F_COUNT(f)      (((f)&0x3)+1)

// printscan\print\drivers\usermode\msplot\tools\ntres\plotgpc.c
#define SIZE_ARRAY(a)           (sizeof((a)) / sizeof((a)[0]))
#define SIZE_COLORINFO          (sizeof(COLORINFO) / sizeof(LDECI4))

// printscan\print\drivers\usermode\unidrv2\font\sfttpcl.h
#define TABLE_DIR_ENTRY_SIZE    (16/sizeof(int))

// printscan\print\spooler\inetsrv\globals.h
#define ARRAY_COUNT(x) (sizeof(x) / sizeof(x[0]))

// printscan\print\spooler\monitors\local\localmon.h
#define COUNTOF(x)                (sizeof(x)/sizeof *(x))

// printscan\print\spooler\monitors\localui\local.h
#define COUNTOF(x) (sizeof(x)/sizeof *(x))

// printscan\print\spooler\monitors\tcpmon\common\tcpmon.h
#define SIZEOF_IN_CHAR(buf)             (sizeof(buf)/sizeof(buf[0]))

// printscan\print\spooler\monitors\tcpmon\tcpmib\stdoids.h
#define MIB_NUMITEMS(mib)		( sizeof(mib)/sizeof(AsnObjectIdentifier) )

// printscan\print\spooler\spllib\common.hxx
#define COUNTOF(x) (sizeof(x)/sizeof(*x))

// printscan\print\spooler\spoolss\perf\lspldata.hxx
#define NUMBER_OF_LSPL_COUNTERS ((sizeof(LSPL_DATA_DEFINITION) -        \
                                  sizeof(PERF_OBJECT_TYPE)) /           \
                                  sizeof(PERF_COUNTER_DEFINITION))

// printscan\print\spooler\spoolss\perf\sharemem.cxx
#define COUNTOF(x) (sizeof(x)/sizeof(*x))

// printscan\print\spooler\wpnpinst\wow\inc\windows.h
#define EM_GETLINECOUNT         (WM_USER+10)
#define EM_LINELENGTH           (WM_USER+17)
#define LB_GETCOUNT            (WM_USER+12)
#define LB_GETSELCOUNT         (WM_USER+17)
#define CB_GETCOUNT              (WM_USER+6)

// printscan\ui\compstui\sample\cpsuidat.h
#define COUNT_ARRAY(a)                  (sizeof(a) / sizeof((a)[0]))

// printscan\ui\compstui\treeview.h
#define COUNT_ARRAY(a)      (sizeof(a) / sizeof(a[0]))

// printscan\ui\inc\pviewids.h
#define PWM_GETSELCOUNT           (WM_USER+615)

// printscan\ui\photowiz\cfdefs.h
#define CF_TABLE_ENTRY(p1, p2, p3) { (void *)&c_CFVtbl, p1, p2, p3 }
#define CF_TABLE_ENTRY_ALL(p1, p2, p3, p4, p5, p6, p7) { (void *)&c_CFVtbl, p1, p2, p3, p4 , p5, p6, p7}

// printscan\ui\photowiz\photosel.h
#define PSP_MSG_UPDATE_ITEM_COUNT   (WM_USER+50)    // wParam = current item, lParam = total items

// printscan\ui\printui\spcompat.hxx
#define COUNTOF(x) (sizeof(x)/sizeof(*x))

// printscan\ui\wiadefui\ppscan.cpp
#define AVAILABLE_COLOR_DEPTH_COUNT (sizeof(g_AvailableColorDepths)/sizeof(g_AvailableColorDepths[0]))

// printscan\wia\core\server\helpers.cpp
#define MAP_SIZE (sizeof(g_wiaPropIdToName) / sizeof(WIA_PROPID_TO_NAME))

// printscan\wia\core\server\security.cpp
#define NUM_SIDS (sizeof(SidData) / sizeof(SidData[0]))
#define NUM_DOMAIN_SIDS (sizeof(psidBuiltinDomainData) / sizeof(psidBuiltinDomainData[0]))
#define NUM_ACES (sizeof(AcesData) / sizeof(AcesData[0]))

// printscan\wia\core\upnp\msprjctr\server\filelist.cpp
#define NUM_SUPPORTED_IMAGES (sizeof(SupportedImagesTable) / sizeof(ImageFileExt_Type))

// printscan\wia\core\upnp\prjctr\server\filelist.cpp
#define NUM_SUPPORTED_IMAGES (sizeof(SupportedImagesTable) / sizeof(ImageFileExt_Type))

// printscan\wia\drivers\camera\ircamera\irtranp\io.h
   #define RemoveEntryList(Entry) {\
       PLIST_ENTRY _EX_Blink;\
       PLIST_ENTRY _EX_Flink;\
       _EX_Flink = (Entry)->Flink;\
       _EX_Blink = (Entry)->Blink;\
       _EX_Blink->Flink = _EX_Flink;\
       _EX_Flink->Blink = _EX_Blink;\
       }
   #define PopEntryList(ListHead) \
       (ListHead)->Next;\
       {\
           PSINGLE_LIST_ENTRY FirstEntry;\
           FirstEntry = (ListHead)->Next;\
           if (FirstEntry != NULL) {     \
               (ListHead)->Next = FirstEntry->Next;\
           }                             \
       }
   #define PushEntryList(ListHead,Entry) \
       (Entry)->Next = (ListHead)->Next; \
       (ListHead)->Next = (Entry)

// printscan\wia\inc\linklist.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// printscan\wia\setup\redist\wiasetup.c
#define ARRAY_LENGTH(x) (sizeof(x)/sizeof((x)[0]))

// printscan\wia\test\remote\connect\connect.cpp
#define NREGVALS (sizeof(regVals) / sizeof(regVals[0]))

// printscan\wia\test\wiastress\wrappers.h
#define COUNTOF(array)  ( sizeof(array) / sizeof(array[0]) )

// public\ddk\inc\hbapiwmi.h
    #define MSFC_FibrePortHBAStatistics_LIPCount_SIZE sizeof(LONGLONG)
    #define MSFC_FibrePortHBAStatistics_NOSCount_SIZE sizeof(LONGLONG)
    #define MSFC_FibrePortHBAStatistics_LinkFailureCount_SIZE sizeof(LONGLONG)
    #define MSFC_FibrePortHBAStatistics_LossOfSyncCount_SIZE sizeof(LONGLONG)
    #define MSFC_FibrePortHBAStatistics_LossOfSignalCount_SIZE sizeof(LONGLONG)
    #define MSFC_FibrePortHBAStatistics_PrimitiveSeqProtocolErrCount_SIZE sizeof(LONGLONG)
    #define MSFC_FibrePortHBAStatistics_InvalidCRCCount_SIZE sizeof(LONGLONG)
    #define SendCTPassThru_IN_RequestBufferCount_SIZE sizeof(ULONG)
    #define SendCTPassThru_OUT_ResponseBufferCount_SIZE sizeof(ULONG)
    #define SendRNID_OUT_ResponseBufferCount_SIZE sizeof(ULONG)
    #define HBAFCPScsiEntry_ScsiId_SIZE sizeof(HBAScsiID)
    #define HBAFCPScsiEntry_FCPId_SIZE sizeof(HBAFCPID)
    #define HBAFCPBindingEntry_Type_SIZE sizeof(ULONG)
    #define HBAFCPBindingEntry_ScsiId_SIZE sizeof(HBAScsiID)
    #define HBAFCPBindingEntry_FCPId_SIZE sizeof(HBAFCPID)
    #define GetFcpTargetMapping_OUT_EntryCount_SIZE sizeof(ULONG)
    #define GetFcpPersistentBinding_OUT_EntryCount_SIZE sizeof(ULONG)

// public\ddk\inc\ndis.h
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)
#define NdisInterlockedPushEntryList(ListHead, ListEntry, Lock) \
    ExInterlockedPushEntryList(ListHead, ListEntry, &(Lock)->SpinLock)
#define NdisInterlockedPopEntryList(ListHead, Lock) \
    ExInterlockedPopEntryList(ListHead, &(Lock)->SpinLock)
#define NdisInterlockedPushEntrySList(SListHead, SListEntry, Lock) \
    ExInterlockedPushEntrySList(SListHead, SListEntry, &(Lock)->SpinLock)
#define NdisInterlockedPopEntrySList(SListHead, Lock) \
    ExInterlockedPopEntrySList(SListHead, &(Lock)->SpinLock)

// public\ddk\inc\ntddcdvd.h
#define DVD_CHALLENGE_KEY_LENGTH    (12 + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_BUS_KEY_LENGTH          (8 + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_TITLE_KEY_LENGTH        (8 + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_DISK_KEY_LENGTH         (2048 + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_RPC_KEY_LENGTH          (sizeof(DVD_RPC_KEY) + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_SET_RPC_KEY_LENGTH      (sizeof(DVD_SET_RPC_KEY) + sizeof(DVD_COPY_PROTECT_KEY))
#define DVD_ASF_LENGTH              (sizeof(DVD_ASF) + sizeof(DVD_COPY_PROTECT_KEY))

// public\ddk\inc\ntddk.h
#define LEGACY_SAVE_AREA_LENGTH  ((sizeof(LEGACY_SAVE_AREA) + 15) & ~15)
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)
#define KeQueryTickCount(CurrentCount ) { \
    volatile PKSYSTEM_TIME _TickCount = *((PKSYSTEM_TIME *)(&KeTickCount)); \
    while (TRUE) {                                                          \
        (CurrentCount)->HighPart = _TickCount->High1Time;                   \
        (CurrentCount)->LowPart = _TickCount->LowPart;                      \
        if ((CurrentCount)->HighPart == _TickCount->High2Time) break;       \
        _asm { rep nop }                                                    \
    }                                                                       \
}
#define KeQueryTickCount(CurrentCount ) \
    *(PULONG64)(CurrentCount) = **((volatile ULONG64 **)(&KeTickCount));
#define KeQueryTickCount(CurrentCount ) \
    *(PULONGLONG)(CurrentCount) = **((volatile ULONGLONG **)(&KeTickCount));
#define MAXIMUM_VOLUME_LABEL_LENGTH  (32 * sizeof(WCHAR)) // 32 characters

// public\ddk\inc\ntddvdeo.h
#define BITMAP_ARRAY_BYTE  3       // BYTE array is 8 bit  (shift count = 3)

// public\ddk\inc\ntia64.h
#define CONTEXT_LENGTH (sizeof(CONTEXT))

// public\ddk\inc\portcls.h
#define DEFINE_PCAUTOMATION_TABLE_PROP(AutomationTable,PropertyTable)\
const PCAUTOMATION_TABLE AutomationTable =\
{\
    sizeof(PropertyTable[0]),\
    SIZEOF_ARRAY(PropertyTable),\
    (const PCPROPERTY_ITEM *) PropertyTable,\
    0,0,NULL,\
    0,0,NULL,\
    0\
}
#define DEFINE_PCAUTOMATION_TABLE_PROP_EVENT(AutomationTable,PropertyTable,EventTable)\
const PCAUTOMATION_TABLE AutomationTable =\
{\
    sizeof(PropertyTable[0]),\
    SIZEOF_ARRAY(PropertyTable),\
    (const PCPROPERTY_ITEM *) PropertyTable,\
    0,0,NULL,\
    sizeof(EventTable[0]),\
    SIZEOF_ARRAY(EventTable),\
    (const PCEVENT_ITEM *) EventTable,\
    0\
}

// public\ddk\inc\tdi.h
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

// public\ddk\inc\wdm\acpiioct.h
#define ACPI_METHOD_ARGUMENT_LENGTH_FROM_ARGUMENT( Argument )              \
    ( ( (PACPI_METHOD_ARGUMENT) Argument)->DataLength > sizeof(ULONG) ?    \
      ( (PACPI_METHOD_ARGUMENT) Argument)->DataLength + 2 * sizeof(USHORT):\
      2 * sizeof(USHORT) + sizeof(ULONG) )
#define ACPI_METHOD_ARGUMENT_LENGTH( DataLength )                          \
    ( (DataLength > sizeof(ULONG)) ? DataLength + (2 * sizeof(USHORT)) :   \
        2 * sizeof(USHORT) + sizeof(ULONG) )

// public\ddk\inc\wdm\wdm.h
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)
#define KeQueryTickCount(CurrentCount ) { \
    volatile PKSYSTEM_TIME _TickCount = *((PKSYSTEM_TIME *)(&KeTickCount)); \
    while (TRUE) {                                                          \
        (CurrentCount)->HighPart = _TickCount->High1Time;                   \
        (CurrentCount)->LowPart = _TickCount->LowPart;                      \
        if ((CurrentCount)->HighPart == _TickCount->High2Time) break;       \
        _asm { rep nop }                                                    \
    }                                                                       \
}
#define KeQueryTickCount(CurrentCount ) \
    *(PULONG64)(CurrentCount) = **((volatile ULONG64 **)(&KeTickCount));
#define KeQueryTickCount(CurrentCount ) \
    *(PULONGLONG)(CurrentCount) = **((volatile ULONGLONG **)(&KeTickCount));

// public\ddk\inc\wdm\wmidata.h
    #define MSWmi_PnPInstanceNames_Count_SIZE sizeof(ULONG)
    #define MSWmi_GuidRegistrationInfo_GuidCount_SIZE sizeof(ULONG)
    #define MSSmBios_SysidUUIDList_Count_SIZE sizeof(ULONG)
    #define MSSmBios_Sysid1394List_Count_SIZE sizeof(ULONG)
    #define MSMCAInfo_Entry_Length_SIZE sizeof(ULONG)
    #define MSMCAInfo_RawMCAData_Count_SIZE sizeof(ULONG)
    #define MSMCAInfo_RawCMCEvent_Count_SIZE sizeof(ULONG)
    #define MSMCAInfo_RawMCAEvent_Count_SIZE sizeof(ULONG)
    #define MSMCAInfo_RawCorrectedPlatformEvent_Count_SIZE sizeof(ULONG)
    #define MSNdis_MediaSupported_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_MediaInUse_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_CoMediaSupported_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_CoMediaInUse_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_EthernetMulticastList_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_FddiLongMulticastList_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_FddiShortMulticastList_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationFH_FHLength_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationInfo_ConfigLength_SIZE sizeof(ULONG)
    #define MSNdis_80211_WLanBssId_Ndis80211WLanBssIdLength_SIZE sizeof(ULONG)
    #define MSNdis_80211_WLanBssId_Ndis80211SsIdLength_SIZE sizeof(ULONG)
    #define MSNdis_80211_Statistics_StatisticsLength_SIZE sizeof(ULONG)
    #define MSNdis_80211_Statistics_TransmittedFragmentCount_SIZE sizeof(ULONGLONG)
    #define MSNdis_80211_Statistics_MulticastTransmittedFrameCount_SIZE sizeof(ULONGLONG)
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
    #define MSNdis_80211_AddWEP_KeyLength_SIZE sizeof(ULONG)
    #define KEYBOARD_PORT_WMI_STD_DATA_ErrorCount_SIZE sizeof(ULONG)
    #define MSAcpi_ThermalZoneTemperature_ActiveTripPointCount_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_ReadCount_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_WriteCount_SIZE sizeof(ULONG)
    #define WMI_DISK_PERFORMANCE_SplitCount_SIZE sizeof(ULONG)
    #define STORAGE_FAILURE_PREDICT_DATA_Length_SIZE sizeof(ULONG)
    #define ATAPI_FAILURE_PREDICT_DATA_Length_SIZE sizeof(ULONG)
    #define STORAGE_FAILURE_PREDICT_EVENT_Length_SIZE sizeof(ULONG)
    #define STORAGE_SCSI_INFO_EXCEPTIONS_ReportCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_PERF_DATA_ReceivedCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_PERF_DATA_TransmittedCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_PERF_DATA_FrameErrorCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_PERF_DATA_SerialOverrunErrorCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_PERF_DATA_BufferOverrunErrorCount_SIZE sizeof(ULONG)
    #define SERIAL_WMI_PERF_DATA_ParityErrorCount_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_NUMBER_OF_BUFFERS_SIZE sizeof(ULONG)
    #define REDBOOK_WMI_PERF_STREAM_PAUSED_COUNT_SIZE sizeof(ULONG)
    #define WMI_TAPE_DRIVE_PARAMETERS_MaximumPartitionCount_SIZE sizeof(ULONG)
    #define WMI_TAPE_MEDIA_PARAMETERS_PartitionCount_SIZE sizeof(ULONG)

// public\halkit\inc\nthal.h
#define LEGACY_SAVE_AREA_LENGTH  ((sizeof(LEGACY_SAVE_AREA) + 15) & ~15)
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)
#define KeQueryTickCount(CurrentCount ) { \
    volatile PKSYSTEM_TIME _TickCount = *((PKSYSTEM_TIME *)(&KeTickCount)); \
    while (TRUE) {                                                          \
        (CurrentCount)->HighPart = _TickCount->High1Time;                   \
        (CurrentCount)->LowPart = _TickCount->LowPart;                      \
        if ((CurrentCount)->HighPart == _TickCount->High2Time) break;       \
        _asm { rep nop }                                                    \
    }                                                                       \
}
#define KTRAP_FRAME_LENGTH  (sizeof(KTRAP_FRAME))
#define KeQueryTickCount(CurrentCount ) \
    *(PULONG64)(CurrentCount) = **((volatile ULONG64 **)(&KeTickCount));
#define KEXCEPTION_FRAME_LENGTH sizeof(KEXCEPTION_FRAME)
#define MACHINE_FRAME_LENGTH sizeof(MACHINE_FRAME)
#define KSWITCH_FRAME_LENGTH sizeof(KSWITCH_FRAME)
#define KTRAP_FRAME_LENGTH sizeof(KTRAP_FRAME)
#define KeQueryTickCount(CurrentCount ) \
    *(PULONGLONG)(CurrentCount) = **((volatile ULONGLONG **)(&KeTickCount));
#define KTRAP_FRAME_LENGTH ((sizeof(KTRAP_FRAME) + 15) & (~15))
#define MAXIMUM_VOLUME_LABEL_LENGTH  (32 * sizeof(WCHAR)) // 32 characters

// public\ifskit\inc\ntifs.h
#define SECURITY_DESCRIPTOR_MIN_LENGTH   (sizeof(SECURITY_DESCRIPTOR))
#define LEGACY_SAVE_AREA_LENGTH  ((sizeof(LEGACY_SAVE_AREA) + 15) & ~15)
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)
#define RtlOemStringToCountedUnicodeSize(STRING) (                    \
    (ULONG)(RtlOemStringToUnicodeSize(STRING) - sizeof(UNICODE_NULL)) \
    )
#define MSV1_0_NTLM3_INPUT_LENGTH (sizeof(MSV1_0_NTLM3_RESPONSE) - MSV1_0_NTLM3_RESPONSE_LENGTH)
#define KeQueryTickCount(CurrentCount ) { \
    volatile PKSYSTEM_TIME _TickCount = *((PKSYSTEM_TIME *)(&KeTickCount)); \
    while (TRUE) {                                                          \
        (CurrentCount)->HighPart = _TickCount->High1Time;                   \
        (CurrentCount)->LowPart = _TickCount->LowPart;                      \
        if ((CurrentCount)->HighPart == _TickCount->High2Time) break;       \
        _asm { rep nop }                                                    \
    }                                                                       \
}
#define KeQueryTickCount(CurrentCount ) \
    *(PULONG64)(CurrentCount) = **((volatile ULONG64 **)(&KeTickCount));
#define KeQueryTickCount(CurrentCount ) \
    *(PULONGLONG)(CurrentCount) = **((volatile ULONGLONG **)(&KeTickCount));
#define SeLengthSid( Sid ) \
    (8 + (4 * ((SID *)Sid)->SubAuthorityCount))
#define MAXIMUM_VOLUME_LABEL_LENGTH  (32 * sizeof(WCHAR)) // 32 characters

// public\internal\admin\inc\cmdline.h
#define SIZE_OF_ARRAY( array )			( sizeof( array ) / sizeof( array[ 0 ] ) )

// public\internal\admin\inc\qmgr.h
#define IBackgroundCopyCallback1_OnProgressEx(This,ProgressType,pGroup,pJob,dwFileIndex,dwProgressValue,dwByteArraySize,pByte)	\
    (This)->lpVtbl -> OnProgressEx(This,ProgressType,pGroup,pJob,dwFileIndex,dwProgressValue,dwByteArraySize,pByte)

// public\internal\drivers\inc\vscoordint.h
#define IVssShim_SimulateSnapshotFreeze(This,guidSnapshotSetId,ulOptionFlags,ulVolumeCount,ppwszVolumeNamesArray,ppAsync)	\
    (This)->lpVtbl -> SimulateSnapshotFreeze(This,guidSnapshotSetId,ulOptionFlags,ulVolumeCount,ppwszVolumeNamesArray,ppAsync)

// public\internal\ds\inc\dnsrpc.h
#define TOTAL_STAT_LENGTH( pStat ) \
            ( (pStat)->Header.wLength + sizeof(DNSSRV_STAT_HEADER) )

// public\internal\ds\inc\passport.h
#define IDomainMap_get_Domains(This,pArrayVal)	\
    (This)->lpVtbl -> get_Domains(This,pArrayVal)
#define IPassportManager_OnStartPageManual(This,queryStringT,queryStringP,MSPAuthCookie,MSPProfCookie,MSPConsentCookie,vMSPSecCookie,pSetCookieArray)	\
    (This)->lpVtbl -> OnStartPageManual(This,queryStringT,queryStringP,MSPAuthCookie,MSPProfCookie,MSPConsentCookie,vMSPSecCookie,pSetCookieArray)
#define IPassportManager_get_Domains(This,pArrayVal)	\
    (This)->lpVtbl -> get_Domains(This,pArrayVal)
#define IPassportManager2_OnStartPageManual(This,queryStringT,queryStringP,MSPAuthCookie,MSPProfCookie,MSPConsentCookie,vMSPSecCookie,pSetCookieArray)	\
    (This)->lpVtbl -> OnStartPageManual(This,queryStringT,queryStringP,MSPAuthCookie,MSPProfCookie,MSPConsentCookie,vMSPSecCookie,pSetCookieArray)
#define IPassportManager2_get_Domains(This,pArrayVal)	\
    (This)->lpVtbl -> get_Domains(This,pArrayVal)
#define IPassportManager3_OnStartPageManual(This,queryStringT,queryStringP,MSPAuthCookie,MSPProfCookie,MSPConsentCookie,vMSPSecCookie,pSetCookieArray)	\
    (This)->lpVtbl -> OnStartPageManual(This,queryStringT,queryStringP,MSPAuthCookie,MSPProfCookie,MSPConsentCookie,vMSPSecCookie,pSetCookieArray)
#define IPassportManager3_get_Domains(This,pArrayVal)	\
    (This)->lpVtbl -> get_Domains(This,pArrayVal)

// public\internal\ds\inc\xom.h
#define OMP_LENGTH(oid_string)  (sizeof(OMP_O_##oid_string)-1)

// public\internal\inetcore\inc\interned.h
#define IHTMLEditingServices_IsElementSiteSelectable(This,pIHTMLElement,ppIElement)	\
    (This)->lpVtbl -> IsElementSiteSelectable(This,pIHTMLElement,ppIElement)

// public\internal\net\inc\isnkrnl.h
#define ROUTER_INTERFACE_LENGTH  (sizeof("RouterInterface") - 1)

// public\internal\net\inc\netshp.h
#define NUM_VALUES_IN_TABLE(TokenArray) sizeof(TokenArray)/sizeof(VALUE_STRING)

// public\internal\net\inc\ntddip6.h
#define TDI_ADDRESS_LENGTH_IP6 sizeof (TDI_ADDRESS_IP6)

// public\internal\net\inc\rap.h
#define RapDescArrayLength( Descriptor ) \
   ( ( DESC_CHAR_IS_DIGIT( *(Descriptor) )) ? RapAsciiToDecimal( &(Descriptor) ) : 1 )
#define RapDescStringLength( Descriptor ) \
   ( ( DESC_CHAR_IS_DIGIT( *(Descriptor) )) ? RapAsciiToDecimal( &(Descriptor) ) : 0 )

// public\internal\shell\inc\comctrlp.h
#define TB_GETIMAGELISTCOUNT    (WM_USER + 98)
#define BL_GETCOUNT             (WM_USER+4)

// public\internal\shell\inc\shlobjp.h
#define WVTI_ENTRY(g, d, t, p, i, s, k) {&(g), (d), (0), (t), (t), (t), (p), (i), (s), (k)}
#define WVTI_ENTRY_NOSELECTION(g, d, t, p, i, s, k) {&(g), (d), (t), 0, 0, 0, (p), (i), (s), (k)}
#define WVTI_ENTRY_FILE(g, d, t, p, i, s, k) {&(g), (d), (0), (t), (0), (0), (p), (i), (s), (k)}
#define WVTI_ENTRY_TITLE(g, d, t2, t3, t4, p, i, s, k) {&(g), (d), (0), (t2), (t3), (t4), (p), (i), (s), (k)}
#define WVTI_ENTRY_ALL(g, d, t, p, i, s, k) {&(g), (d), (t), (t), (t), (t), (p), (i), (s), (k)}
#define WVTI_ENTRY_ALL_TITLE(g, d, t1, t2, t3, t4, p, i, s, k) {&(g), (d), (t1), (t2), (t3), (t4), (p), (i), (s), (k)}
#define WVTI_HEADER_ENTRY(d, t1, t2, t3, t4, p) {&(CLSID_NULL), (d), (t1), (t2), (t3), (t4), (p), 0, NULL, NULL}
#define LW_MAX_URL_LENGTH   (2048 + 32 + sizeof("://"))

// public\internal\shell\inc\shpriv.h
#define IShellItemArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IShellItemArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IShellItemArray_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IShellItemArray_BindToHandler(This,pbc,rbhid,riid,ppvOut)	\
    (This)->lpVtbl -> BindToHandler(This,pbc,rbhid,riid,ppvOut)
#define IShellItemArray_GetAttributes(This,dwAttribFlags,sfgaoMask,psfgaoAttribs)	\
    (This)->lpVtbl -> GetAttributes(This,dwAttribFlags,sfgaoMask,psfgaoAttribs)
#define IShellItemArray_GetCount(This,pdwNumItems)	\
    (This)->lpVtbl -> GetCount(This,pdwNumItems)
#define IShellItemArray_GetItemAt(This,dwIndex,ppsi)	\
    (This)->lpVtbl -> GetItemAt(This,dwIndex,ppsi)
#define IShellItemArray_EnumItems(This,ppenumShellItems)	\
    (This)->lpVtbl -> EnumItems(This,ppenumShellItems)
#define IUIElement_get_Name(This,psiItemArray,ppszName)	\
    (This)->lpVtbl -> get_Name(This,psiItemArray,ppszName)
#define IUIElement_get_Icon(This,psiItemArray,ppszIcon)	\
    (This)->lpVtbl -> get_Icon(This,psiItemArray,ppszIcon)
#define IUIElement_get_Tooltip(This,psiItemArray,ppszInfotip)	\
    (This)->lpVtbl -> get_Tooltip(This,psiItemArray,ppszInfotip)
#define IUICommand_get_Name(This,psiItemArray,ppszName)	\
    (This)->lpVtbl -> get_Name(This,psiItemArray,ppszName)
#define IUICommand_get_Icon(This,psiItemArray,ppszIcon)	\
    (This)->lpVtbl -> get_Icon(This,psiItemArray,ppszIcon)
#define IUICommand_get_Tooltip(This,psiItemArray,ppszInfotip)	\
    (This)->lpVtbl -> get_Tooltip(This,psiItemArray,ppszInfotip)
#define IUICommand_get_State(This,psiItemArray,fOkToBeSlow,puisState)	\
    (This)->lpVtbl -> get_State(This,psiItemArray,fOkToBeSlow,puisState)
#define IUICommand_Invoke(This,psiItemArray,pbc)	\
    (This)->lpVtbl -> Invoke(This,psiItemArray,pbc)
#define IUICommandTarget_get_Name(This,guidCanonicalName,psiItemArray,ppszName)	\
    (This)->lpVtbl -> get_Name(This,guidCanonicalName,psiItemArray,ppszName)
#define IUICommandTarget_get_Icon(This,guidCanonicalName,psiItemArray,ppszIcon)	\
    (This)->lpVtbl -> get_Icon(This,guidCanonicalName,psiItemArray,ppszIcon)
#define IUICommandTarget_get_Tooltip(This,guidCanonicalName,psiItemArray,ppszInfotip)	\
    (This)->lpVtbl -> get_Tooltip(This,guidCanonicalName,psiItemArray,ppszInfotip)
#define IUICommandTarget_get_State(This,guidCanonicalName,psiItemArray,puisState)	\
    (This)->lpVtbl -> get_State(This,guidCanonicalName,psiItemArray,puisState)
#define IUICommandTarget_Invoke(This,guidCanonicalName,psiItemArray,pbc)	\
    (This)->lpVtbl -> Invoke(This,guidCanonicalName,psiItemArray,pbc)
#define IEnumAssociationElements_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumAssociationElements_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumAssociationElements_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumAssociationElements_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)
#define IEnumAssociationElements_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IEnumAssociationElements_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumAssociationElements_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)
#define IAssociationArrayInitialize_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IAssociationArrayInitialize_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IAssociationArrayInitialize_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IAssociationArrayInitialize_InitClassElements(This,maskBase,pszClass)	\
    (This)->lpVtbl -> InitClassElements(This,maskBase,pszClass)
#define IAssociationArrayInitialize_InsertElements(This,mask,peae)	\
    (This)->lpVtbl -> InsertElements(This,mask,peae)
#define IAssociationArrayInitialize_FilterElements(This,maskInclude)	\
    (This)->lpVtbl -> FilterElements(This,maskInclude)
#define IAssociationArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IAssociationArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IAssociationArray_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IAssociationArray_EnumElements(This,mask,ppeae)	\
    (This)->lpVtbl -> EnumElements(This,mask,ppeae)
#define IAssociationArray_QueryString(This,mask,query,pszCue,ppsz)	\
    (This)->lpVtbl -> QueryString(This,mask,query,pszCue,ppsz)
#define IAssociationArray_QueryDword(This,mask,query,pszCue,pdw)	\
    (This)->lpVtbl -> QueryDword(This,mask,query,pszCue,pdw)
#define IAssociationArray_QueryExists(This,mask,query,pszCue)	\
    (This)->lpVtbl -> QueryExists(This,mask,query,pszCue)
#define IAssociationArray_QueryDirect(This,mask,query,pszCue,ppblob)	\
    (This)->lpVtbl -> QueryDirect(This,mask,query,pszCue,ppblob)
#define IAssociationArray_QueryObject(This,mask,query,pszCue,riid,ppv)	\
    (This)->lpVtbl -> QueryObject(This,mask,query,pszCue,riid,ppv)

// public\internal\termsrv\inc\pchannel.h
#define CHANNEL_PDU_LENGTH (CHANNEL_CHUNK_LENGTH + sizeof(CHANNEL_PDU_HEADER))

// public\internal\termsrv\inc\rdpdr.h
#define RDPDRDVMGR_DEVICE_PATH_A_LENGTH sizeof(RDPDRDVMGR_DEVICE_PATH_A)
#define RDPDRDVMGR_DEVICE_PATH_U_LENGTH sizeof(RDPDRDVMGR_DEVICE_PATH_U)
#define RDPDRDVMGR_W32DEVICE_PATH_A_LENGTH sizeof(RDPDRDVMGR_W32DEVICE_PATH_A)
#define RDPDRDVMGR_W32DEVICE_PATH_U_LENGTH sizeof(RDPDRDVMGR_W32DEVICE_PATH_U)
#define RDPDR_PROVIDER_NAME_U_LENGTH (sizeof(RDPDR_PROVIDER_NAME_U))
#define RDPDR_PROVIDER_NAME_A_LENGTH (sizeof(RDPDR_PROVIDER_NAME_A))
#define RDPDR_DEVICE_NAME_A_LENGTH sizeof(RDPDR_DEVICE_NAME_A)
#define RDPDR_DEVICE_NAME_U_LENGTH sizeof(RDPDR_DEVICE_NAME_U)
#define RDPDR_PORT_DEVICE_NAME_A_LENGTH sizeof(RDPDR_PORT_DEVICE_NAME_A)
#define RDPDR_PORT_DEVICE_NAME_U_LENGTH sizeof(RDPDR_PORT_DEVICE_NAME_U)

// public\internal\windows\inc\duser\duiconvert.h
#define DUIARRAYSIZE(a)    (sizeof(a) / sizeof(a[0]))

// public\internal\windows\inc\duser\duierror.h
#define _countof(x) (sizeof(x) / sizeof(x[0]))

// public\internal\windows\inc\shimdb.h
#define CHARCOUNT(sz) (sizeof(sz) / sizeof(sz[0]))

// public\internal\windows\inc\shimhookmacro.h
#define MULTISHIM_ENTRY(shim)                                                                         \
    if ((fdwReason == DLL_PROCESS_ATTACH && pwszShim != NULL && 0 == _wcsicmp( pwszShim, L#shim )) || \
        (fdwReason == DLL_PROCESS_DETACH && NS_##shim::g_bSubshimUsed) ||                             \
        (fdwReason == SHIM_PROCESS_DYING && NS_##shim::g_bSubshimUsed) ||                             \
        (fdwReason == SHIM_DLL_LOADING && NS_##shim::g_bSubshimUsed) ||                               \
        (fdwReason == SHIM_STATIC_DLLS_INITIALIZED && NS_##shim::g_bSubshimUsed)) {                   \
        NS_##shim::g_bSubshimUsed = TRUE;                                                             \
        pAPIHooks = NS_##shim::InitializeHooksMulti( fdwReason, pszCmdLine, pdwHookCount );           \
    }

// public\sdk\inc\1394wmi.h
    #define BUS1394_WMI_DEVICE_ENUMERATION_CONTROL_DATA_NumberOfElements_SIZE sizeof(ULONG)

// public\sdk\inc\activdbg.h
#define IDebugFormatter_GetStringForVarType(This,vt,ptdescArrayType,pbstr)	\
    (This)->lpVtbl -> GetStringForVarType(This,vt,ptdescArrayType,pbstr)

// public\sdk\inc\atl30\atldb.h
#define CLEARBITARRAY( rgdwFlags ) memset( rgdwFlags, 0, sizeof(rgdwFlags) )

// public\sdk\inc\atl30\atldbcli.h
#define _COLUMN_ENTRY_CODE(nOrdinal, wType, nLength, nPrecision, nScale, dataOffset, lengthOffset, statusOffset) \
	if (pBuffer != NULL) \
	{ \
		CAccessorBase::FreeType(wType, pBuffer + dataOffset); \
	} \
	else if (pBinding != NULL) \
	{ \
		CAccessorBase::Bind(pBinding, nOrdinal, wType, nLength, nPrecision, nScale, eParamIO, \
			dataOffset, lengthOffset, statusOffset); \
		pBinding++; \
	} \
	nColumns++;

// public\sdk\inc\certenc.h
#define ICertEncodeStringArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICertEncodeStringArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICertEncodeStringArray_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICertEncodeStringArray_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ICertEncodeStringArray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ICertEncodeStringArray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ICertEncodeStringArray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ICertEncodeStringArray_Decode(This,strBinary)	\
    (This)->lpVtbl -> Decode(This,strBinary)
#define ICertEncodeStringArray_GetStringType(This,pStringType)	\
    (This)->lpVtbl -> GetStringType(This,pStringType)
#define ICertEncodeStringArray_GetCount(This,pCount)	\
    (This)->lpVtbl -> GetCount(This,pCount)
#define ICertEncodeStringArray_GetValue(This,Index,pstr)	\
    (This)->lpVtbl -> GetValue(This,Index,pstr)
#define ICertEncodeStringArray_Reset(This,Count,StringType)	\
    (This)->lpVtbl -> Reset(This,Count,StringType)
#define ICertEncodeStringArray_SetValue(This,Index,str)	\
    (This)->lpVtbl -> SetValue(This,Index,str)
#define ICertEncodeStringArray_Encode(This,pstrBinary)	\
    (This)->lpVtbl -> Encode(This,pstrBinary)
#define ICertEncodeLongArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICertEncodeLongArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICertEncodeLongArray_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICertEncodeLongArray_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ICertEncodeLongArray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ICertEncodeLongArray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ICertEncodeLongArray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ICertEncodeLongArray_Decode(This,strBinary)	\
    (This)->lpVtbl -> Decode(This,strBinary)
#define ICertEncodeLongArray_GetCount(This,pCount)	\
    (This)->lpVtbl -> GetCount(This,pCount)
#define ICertEncodeLongArray_GetValue(This,Index,pValue)	\
    (This)->lpVtbl -> GetValue(This,Index,pValue)
#define ICertEncodeLongArray_Reset(This,Count)	\
    (This)->lpVtbl -> Reset(This,Count)
#define ICertEncodeLongArray_SetValue(This,Index,Value)	\
    (This)->lpVtbl -> SetValue(This,Index,Value)
#define ICertEncodeLongArray_Encode(This,pstrBinary)	\
    (This)->lpVtbl -> Encode(This,pstrBinary)
#define ICertEncodeDateArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICertEncodeDateArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICertEncodeDateArray_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICertEncodeDateArray_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ICertEncodeDateArray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ICertEncodeDateArray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ICertEncodeDateArray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ICertEncodeDateArray_Decode(This,strBinary)	\
    (This)->lpVtbl -> Decode(This,strBinary)
#define ICertEncodeDateArray_GetCount(This,pCount)	\
    (This)->lpVtbl -> GetCount(This,pCount)
#define ICertEncodeDateArray_GetValue(This,Index,pValue)	\
    (This)->lpVtbl -> GetValue(This,Index,pValue)
#define ICertEncodeDateArray_Reset(This,Count)	\
    (This)->lpVtbl -> Reset(This,Count)
#define ICertEncodeDateArray_SetValue(This,Index,Value)	\
    (This)->lpVtbl -> SetValue(This,Index,Value)
#define ICertEncodeDateArray_Encode(This,pstrBinary)	\
    (This)->lpVtbl -> Encode(This,pstrBinary)

// public\sdk\inc\commctrl.h
#define ListView_SetColumnOrderArray(hwnd, iCount, pi) \
        (BOOL)SNDMSG((hwnd), LVM_SETCOLUMNORDERARRAY, (WPARAM)(iCount), (LPARAM)(LPINT)(pi))
#define ListView_GetColumnOrderArray(hwnd, iCount, pi) \
        (BOOL)SNDMSG((hwnd), LVM_GETCOLUMNORDERARRAY, (WPARAM)(iCount), (LPARAM)(LPINT)(pi))

// public\sdk\inc\confpriv.h
#define IEnumParticipant_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

// public\sdk\inc\ctffunc.h
#define IEnumTfLatticeElements_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumTfLatticeElements_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumTfLatticeElements_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumTfLatticeElements_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)
#define IEnumTfLatticeElements_Next(This,ulCount,rgsElements,pcFetched)	\
    (This)->lpVtbl -> Next(This,ulCount,rgsElements,pcFetched)
#define IEnumTfLatticeElements_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumTfLatticeElements_Skip(This,ulCount)	\
    (This)->lpVtbl -> Skip(This,ulCount)
#define ITfLMLattice_EnumLatticeElements(This,dwFrameStart,rguidType,ppEnum)	\
    (This)->lpVtbl -> EnumLatticeElements(This,dwFrameStart,rguidType,ppEnum)

// public\sdk\inc\danim.h
#define IDAArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IDAArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IDAArray_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IDAArray_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IDAArray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDAArray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDAArray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IDAArray_GetClassName(This,pClassName)	\
    (This)->lpVtbl -> GetClassName(This,pClassName)
#define IDAArray_Init(This,toBvr)	\
    (This)->lpVtbl -> Init(This,toBvr)
#define IDAArray_Importance(This,relativeImportance,ppBvr)	\
    (This)->lpVtbl -> Importance(This,relativeImportance,ppBvr)
#define IDAArray_RunOnce(This,bvr)	\
    (This)->lpVtbl -> RunOnce(This,bvr)
#define IDAArray_SubstituteTime(This,xform,bvr)	\
    (This)->lpVtbl -> SubstituteTime(This,xform,bvr)
#define IDAArray_SwitchTo(This,switchTo)	\
    (This)->lpVtbl -> SwitchTo(This,switchTo)
#define IDAArray_SwitchToNumber(This,numToSwitchTo)	\
    (This)->lpVtbl -> SwitchToNumber(This,numToSwitchTo)
#define IDAArray_SwitchToString(This,strToSwitchTo)	\
    (This)->lpVtbl -> SwitchToString(This,strToSwitchTo)
#define IDAArray_Hook(This,notifier,pBvr)	\
    (This)->lpVtbl -> Hook(This,notifier,pBvr)
#define IDAArray_Duration(This,duration,bvr)	\
    (This)->lpVtbl -> Duration(This,duration,bvr)
#define IDAArray_DurationAnim(This,duration,bvr)	\
    (This)->lpVtbl -> DurationAnim(This,duration,bvr)
#define IDAArray_Repeat(This,count,bvr)	\
    (This)->lpVtbl -> Repeat(This,count,bvr)
#define IDAArray_RepeatForever(This,bvr)	\
    (This)->lpVtbl -> RepeatForever(This,bvr)
#define IDAArray_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDAArray_NthAnim(This,index_0,ret_1)	\
    (This)->lpVtbl -> NthAnim(This,index_0,ret_1)
#define IDAArray_Length(This,ret_0)	\
    (This)->lpVtbl -> Length(This,ret_0)
#define IDA2Array_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IDA2Array_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IDA2Array_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IDA2Array_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IDA2Array_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDA2Array_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDA2Array_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IDA2Array_GetClassName(This,pClassName)	\
    (This)->lpVtbl -> GetClassName(This,pClassName)
#define IDA2Array_Init(This,toBvr)	\
    (This)->lpVtbl -> Init(This,toBvr)
#define IDA2Array_Importance(This,relativeImportance,ppBvr)	\
    (This)->lpVtbl -> Importance(This,relativeImportance,ppBvr)
#define IDA2Array_RunOnce(This,bvr)	\
    (This)->lpVtbl -> RunOnce(This,bvr)
#define IDA2Array_SubstituteTime(This,xform,bvr)	\
    (This)->lpVtbl -> SubstituteTime(This,xform,bvr)
#define IDA2Array_SwitchTo(This,switchTo)	\
    (This)->lpVtbl -> SwitchTo(This,switchTo)
#define IDA2Array_SwitchToNumber(This,numToSwitchTo)	\
    (This)->lpVtbl -> SwitchToNumber(This,numToSwitchTo)
#define IDA2Array_SwitchToString(This,strToSwitchTo)	\
    (This)->lpVtbl -> SwitchToString(This,strToSwitchTo)
#define IDA2Array_Hook(This,notifier,pBvr)	\
    (This)->lpVtbl -> Hook(This,notifier,pBvr)
#define IDA2Array_Duration(This,duration,bvr)	\
    (This)->lpVtbl -> Duration(This,duration,bvr)
#define IDA2Array_DurationAnim(This,duration,bvr)	\
    (This)->lpVtbl -> DurationAnim(This,duration,bvr)
#define IDA2Array_Repeat(This,count,bvr)	\
    (This)->lpVtbl -> Repeat(This,count,bvr)
#define IDA2Array_RepeatForever(This,bvr)	\
    (This)->lpVtbl -> RepeatForever(This,bvr)
#define IDA2Array_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDA2Array_NthAnim(This,index_0,ret_1)	\
    (This)->lpVtbl -> NthAnim(This,index_0,ret_1)
#define IDA2Array_Length(This,ret_0)	\
    (This)->lpVtbl -> Length(This,ret_0)
#define IDA2Array_AddElement(This,b_0,flag_1,ret_2)	\
    (This)->lpVtbl -> AddElement(This,b_0,flag_1,ret_2)
#define IDA2Array_RemoveElement(This,i_0)	\
    (This)->lpVtbl -> RemoveElement(This,i_0)
#define IDA3Array_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IDA3Array_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IDA3Array_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IDA3Array_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IDA3Array_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDA3Array_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDA3Array_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IDA3Array_GetClassName(This,pClassName)	\
    (This)->lpVtbl -> GetClassName(This,pClassName)
#define IDA3Array_Init(This,toBvr)	\
    (This)->lpVtbl -> Init(This,toBvr)
#define IDA3Array_Importance(This,relativeImportance,ppBvr)	\
    (This)->lpVtbl -> Importance(This,relativeImportance,ppBvr)
#define IDA3Array_RunOnce(This,bvr)	\
    (This)->lpVtbl -> RunOnce(This,bvr)
#define IDA3Array_SubstituteTime(This,xform,bvr)	\
    (This)->lpVtbl -> SubstituteTime(This,xform,bvr)
#define IDA3Array_SwitchTo(This,switchTo)	\
    (This)->lpVtbl -> SwitchTo(This,switchTo)
#define IDA3Array_SwitchToNumber(This,numToSwitchTo)	\
    (This)->lpVtbl -> SwitchToNumber(This,numToSwitchTo)
#define IDA3Array_SwitchToString(This,strToSwitchTo)	\
    (This)->lpVtbl -> SwitchToString(This,strToSwitchTo)
#define IDA3Array_Hook(This,notifier,pBvr)	\
    (This)->lpVtbl -> Hook(This,notifier,pBvr)
#define IDA3Array_Duration(This,duration,bvr)	\
    (This)->lpVtbl -> Duration(This,duration,bvr)
#define IDA3Array_DurationAnim(This,duration,bvr)	\
    (This)->lpVtbl -> DurationAnim(This,duration,bvr)
#define IDA3Array_Repeat(This,count,bvr)	\
    (This)->lpVtbl -> Repeat(This,count,bvr)
#define IDA3Array_RepeatForever(This,bvr)	\
    (This)->lpVtbl -> RepeatForever(This,bvr)
#define IDA3Array_IsReady(This,bBlock,b)	\
    (This)->lpVtbl -> IsReady(This,bBlock,b)
#define IDA3Array_NthAnim(This,index_0,ret_1)	\
    (This)->lpVtbl -> NthAnim(This,index_0,ret_1)
#define IDA3Array_Length(This,ret_0)	\
    (This)->lpVtbl -> Length(This,ret_0)
#define IDA3Array_AddElement(This,b_0,flag_1,ret_2)	\
    (This)->lpVtbl -> AddElement(This,b_0,flag_1,ret_2)
#define IDA3Array_RemoveElement(This,i_0)	\
    (This)->lpVtbl -> RemoveElement(This,i_0)
#define IDA3Array_SetElement(This,index,b,flag)	\
    (This)->lpVtbl -> SetElement(This,index,b,flag)
#define IDA3Array_GetElement(This,index,ret)	\
    (This)->lpVtbl -> GetElement(This,index,ret)
#define IDAStatics_DAArrayEx(This,s,pBvrs,bvr)	\
    (This)->lpVtbl -> DAArrayEx(This,s,pBvrs,bvr)
#define IDAStatics_DAArray(This,bvrs,bvr)	\
    (This)->lpVtbl -> DAArray(This,bvrs,bvr)
#define IDAStatics_UninitializedArray(This,typeTmp,bvr)	\
    (This)->lpVtbl -> UninitializedArray(This,typeTmp,bvr)
#define IDAStatics_UnionGeometryArrayEx(This,imgs_0size,imgs_0,ret_1)	\
    (This)->lpVtbl -> UnionGeometryArrayEx(This,imgs_0size,imgs_0,ret_1)
#define IDAStatics_UnionGeometryArray(This,imgs_0,ret_1)	\
    (This)->lpVtbl -> UnionGeometryArray(This,imgs_0,ret_1)
#define IDAStatics_OverlayArrayEx(This,imgs_0size,imgs_0,ret_1)	\
    (This)->lpVtbl -> OverlayArrayEx(This,imgs_0size,imgs_0,ret_1)
#define IDAStatics_OverlayArray(This,imgs_0,ret_1)	\
    (This)->lpVtbl -> OverlayArray(This,imgs_0,ret_1)
#define IDAStatics_ConcatArrayEx(This,paths_0size,paths_0,ret_1)	\
    (This)->lpVtbl -> ConcatArrayEx(This,paths_0size,paths_0,ret_1)
#define IDAStatics_ConcatArray(This,paths_0,ret_1)	\
    (This)->lpVtbl -> ConcatArray(This,paths_0,ret_1)
#define IDAStatics_MixArrayEx(This,snds_0size,snds_0,ret_1)	\
    (This)->lpVtbl -> MixArrayEx(This,snds_0size,snds_0,ret_1)
#define IDAStatics_MixArray(This,snds_0,ret_1)	\
    (This)->lpVtbl -> MixArray(This,snds_0,ret_1)
#define IDAStatics_Compose3ArrayEx(This,xfs_0size,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose3ArrayEx(This,xfs_0size,xfs_0,ret_1)
#define IDAStatics_Compose3Array(This,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose3Array(This,xfs_0,ret_1)
#define IDAStatics_Compose2ArrayEx(This,xfs_0size,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose2ArrayEx(This,xfs_0size,xfs_0,ret_1)
#define IDAStatics_Compose2Array(This,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose2Array(This,xfs_0,ret_1)
#define IDAStatics_Array(This,obsolete1,obsolete2)	\
    (This)->lpVtbl -> Array(This,obsolete1,obsolete2)
#define IDA2Statics_DAArrayEx(This,s,pBvrs,bvr)	\
    (This)->lpVtbl -> DAArrayEx(This,s,pBvrs,bvr)
#define IDA2Statics_DAArray(This,bvrs,bvr)	\
    (This)->lpVtbl -> DAArray(This,bvrs,bvr)
#define IDA2Statics_UninitializedArray(This,typeTmp,bvr)	\
    (This)->lpVtbl -> UninitializedArray(This,typeTmp,bvr)
#define IDA2Statics_UnionGeometryArrayEx(This,imgs_0size,imgs_0,ret_1)	\
    (This)->lpVtbl -> UnionGeometryArrayEx(This,imgs_0size,imgs_0,ret_1)
#define IDA2Statics_UnionGeometryArray(This,imgs_0,ret_1)	\
    (This)->lpVtbl -> UnionGeometryArray(This,imgs_0,ret_1)
#define IDA2Statics_OverlayArrayEx(This,imgs_0size,imgs_0,ret_1)	\
    (This)->lpVtbl -> OverlayArrayEx(This,imgs_0size,imgs_0,ret_1)
#define IDA2Statics_OverlayArray(This,imgs_0,ret_1)	\
    (This)->lpVtbl -> OverlayArray(This,imgs_0,ret_1)
#define IDA2Statics_ConcatArrayEx(This,paths_0size,paths_0,ret_1)	\
    (This)->lpVtbl -> ConcatArrayEx(This,paths_0size,paths_0,ret_1)
#define IDA2Statics_ConcatArray(This,paths_0,ret_1)	\
    (This)->lpVtbl -> ConcatArray(This,paths_0,ret_1)
#define IDA2Statics_MixArrayEx(This,snds_0size,snds_0,ret_1)	\
    (This)->lpVtbl -> MixArrayEx(This,snds_0size,snds_0,ret_1)
#define IDA2Statics_MixArray(This,snds_0,ret_1)	\
    (This)->lpVtbl -> MixArray(This,snds_0,ret_1)
#define IDA2Statics_Compose3ArrayEx(This,xfs_0size,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose3ArrayEx(This,xfs_0size,xfs_0,ret_1)
#define IDA2Statics_Compose3Array(This,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose3Array(This,xfs_0,ret_1)
#define IDA2Statics_Compose2ArrayEx(This,xfs_0size,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose2ArrayEx(This,xfs_0size,xfs_0,ret_1)
#define IDA2Statics_Compose2Array(This,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose2Array(This,xfs_0,ret_1)
#define IDA2Statics_Array(This,obsolete1,obsolete2)	\
    (This)->lpVtbl -> Array(This,obsolete1,obsolete2)
#define IDA2Statics_DAArrayEx2(This,s,pBvrs,dwFlags,bvr)	\
    (This)->lpVtbl -> DAArrayEx2(This,s,pBvrs,dwFlags,bvr)
#define IDA2Statics_DAArray2(This,bvrs,dwFlags,bvr)	\
    (This)->lpVtbl -> DAArray2(This,bvrs,dwFlags,bvr)
#define IDA2Statics_UnionMontageArrayEx(This,mtgs_0size,mtgs_0,ret_1)	\
    (This)->lpVtbl -> UnionMontageArrayEx(This,mtgs_0size,mtgs_0,ret_1)
#define IDA2Statics_UnionMontageArray(This,mtgs_0,ret_1)	\
    (This)->lpVtbl -> UnionMontageArray(This,mtgs_0,ret_1)
#define IDA3Statics_DAArrayEx(This,s,pBvrs,bvr)	\
    (This)->lpVtbl -> DAArrayEx(This,s,pBvrs,bvr)
#define IDA3Statics_DAArray(This,bvrs,bvr)	\
    (This)->lpVtbl -> DAArray(This,bvrs,bvr)
#define IDA3Statics_UninitializedArray(This,typeTmp,bvr)	\
    (This)->lpVtbl -> UninitializedArray(This,typeTmp,bvr)
#define IDA3Statics_UnionGeometryArrayEx(This,imgs_0size,imgs_0,ret_1)	\
    (This)->lpVtbl -> UnionGeometryArrayEx(This,imgs_0size,imgs_0,ret_1)
#define IDA3Statics_UnionGeometryArray(This,imgs_0,ret_1)	\
    (This)->lpVtbl -> UnionGeometryArray(This,imgs_0,ret_1)
#define IDA3Statics_OverlayArrayEx(This,imgs_0size,imgs_0,ret_1)	\
    (This)->lpVtbl -> OverlayArrayEx(This,imgs_0size,imgs_0,ret_1)
#define IDA3Statics_OverlayArray(This,imgs_0,ret_1)	\
    (This)->lpVtbl -> OverlayArray(This,imgs_0,ret_1)
#define IDA3Statics_ConcatArrayEx(This,paths_0size,paths_0,ret_1)	\
    (This)->lpVtbl -> ConcatArrayEx(This,paths_0size,paths_0,ret_1)
#define IDA3Statics_ConcatArray(This,paths_0,ret_1)	\
    (This)->lpVtbl -> ConcatArray(This,paths_0,ret_1)
#define IDA3Statics_MixArrayEx(This,snds_0size,snds_0,ret_1)	\
    (This)->lpVtbl -> MixArrayEx(This,snds_0size,snds_0,ret_1)
#define IDA3Statics_MixArray(This,snds_0,ret_1)	\
    (This)->lpVtbl -> MixArray(This,snds_0,ret_1)
#define IDA3Statics_Compose3ArrayEx(This,xfs_0size,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose3ArrayEx(This,xfs_0size,xfs_0,ret_1)
#define IDA3Statics_Compose3Array(This,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose3Array(This,xfs_0,ret_1)
#define IDA3Statics_Compose2ArrayEx(This,xfs_0size,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose2ArrayEx(This,xfs_0size,xfs_0,ret_1)
#define IDA3Statics_Compose2Array(This,xfs_0,ret_1)	\
    (This)->lpVtbl -> Compose2Array(This,xfs_0,ret_1)
#define IDA3Statics_Array(This,obsolete1,obsolete2)	\
    (This)->lpVtbl -> Array(This,obsolete1,obsolete2)
#define IDA3Statics_DAArrayEx2(This,s,pBvrs,dwFlags,bvr)	\
    (This)->lpVtbl -> DAArrayEx2(This,s,pBvrs,dwFlags,bvr)
#define IDA3Statics_DAArray2(This,bvrs,dwFlags,bvr)	\
    (This)->lpVtbl -> DAArray2(This,bvrs,dwFlags,bvr)
#define IDA3Statics_UnionMontageArrayEx(This,mtgs_0size,mtgs_0,ret_1)	\
    (This)->lpVtbl -> UnionMontageArrayEx(This,mtgs_0size,mtgs_0,ret_1)
#define IDA3Statics_UnionMontageArray(This,mtgs_0,ret_1)	\
    (This)->lpVtbl -> UnionMontageArray(This,mtgs_0,ret_1)
#define IDA3Statics_SequenceArrayEx(This,sz,bvrs_0,ret_1)	\
    (This)->lpVtbl -> SequenceArrayEx(This,sz,bvrs_0,ret_1)
#define IDA3Statics_SequenceArray(This,bvrs_0,ret_1)	\
    (This)->lpVtbl -> SequenceArray(This,bvrs_0,ret_1)

// public\sdk\inc\dao360\_dbdao.h
#define ATV(psa, var)								\
	do												\
		{											\
		if (!psa)									\
			{										\
			var.vt		= VT_ERROR;					\
			var.scode	= DISP_E_PARAMNOTFOUND;		\
			}										\
		else										\
			{										\
			var.vt		= VT_ARRAY|VT_UI1;			\
			SafeArrayCopy(psa, &var.parray);	\
			}										\
		}											\
	while (0)

// public\sdk\inc\datime.h
#define ITIMEElement_get_allTIMEElements(This,ppDisp)	\
    (This)->lpVtbl -> get_allTIMEElements(This,ppDisp)
#define ITIMEElement_get_childrenTIMEElements(This,ppDisp)	\
    (This)->lpVtbl -> get_childrenTIMEElements(This,ppDisp)
#define ITIMEBodyElement_get_allTIMEElements(This,ppDisp)	\
    (This)->lpVtbl -> get_allTIMEElements(This,ppDisp)
#define ITIMEBodyElement_get_childrenTIMEElements(This,ppDisp)	\
    (This)->lpVtbl -> get_childrenTIMEElements(This,ppDisp)
#define ITIMEMediaElement_get_allTIMEElements(This,ppDisp)	\
    (This)->lpVtbl -> get_allTIMEElements(This,ppDisp)
#define ITIMEMediaElement_get_childrenTIMEElements(This,ppDisp)	\
    (This)->lpVtbl -> get_childrenTIMEElements(This,ppDisp)

// public\sdk\inc\dxfile.h
#define DXFILEERR_BADARRAYSIZE              MAKE_DDHRESULT(868)

// public\sdk\inc\dxtrans.h
#define IDXARGBReadWritePtr_OverArrayAndMove(This,pScratchBuffer,pSrc,cSamples)	\
    (This)->lpVtbl -> OverArrayAndMove(This,pScratchBuffer,pSrc,cSamples)

// public\sdk\inc\iadmw.h
#define IMSAdminBaseSinkW_SinkNotify(This,dwMDNumElements,pcoChangeList)	\
    (This)->lpVtbl -> SinkNotify(This,dwMDNumElements,pcoChangeList)
#define AsyncIMSAdminBaseSinkW_Begin_SinkNotify(This,dwMDNumElements,pcoChangeList)	\
    (This)->lpVtbl -> Begin_SinkNotify(This,dwMDNumElements,pcoChangeList)

// public\sdk\inc\iads.h
#define IADsPropertyList_Skip(This,cElements)	\
    (This)->lpVtbl -> Skip(This,cElements)
#define IADsPathname_GetNumElements(This,plnNumPathElements)	\
    (This)->lpVtbl -> GetNumElements(This,plnNumPathElements)

// public\sdk\inc\imessage.h
#define CbNewSPropAttrArray(_cattr) \
	(offsetof(SPropAttrArray,aPropAttr) + (_cattr)*sizeof(ULONG))
#define CbSPropAttrArray(_lparray) \
	(offsetof(SPropAttrArray,aPropAttr) + \
	(UINT)((_lparray)->cValues)*sizeof(ULONG))

// public\sdk\inc\imnxport.h
#define IRangeList_RangeToIMAPString(This,ppszDestination,pdwLengthOfDestination)	\
    (This)->lpVtbl -> RangeToIMAPString(This,ppszDestination,pdwLengthOfDestination)
#define IIMAPTransport_GetMsgSeqNumToUIDArray(This,ppdwMsgSeqNumToUIDArray,pdwNumberOfElements)	\
    (This)->lpVtbl -> GetMsgSeqNumToUIDArray(This,ppdwMsgSeqNumToUIDArray,pdwNumberOfElements)
#define IIMAPTransport2_GetMsgSeqNumToUIDArray(This,ppdwMsgSeqNumToUIDArray,pdwNumberOfElements)	\
    (This)->lpVtbl -> GetMsgSeqNumToUIDArray(This,ppdwMsgSeqNumToUIDArray,pdwNumberOfElements)

// public\sdk\inc\ks.h
    #define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))
#define DEFINE_KSAUTOMATION_PROPERTIES(table)\
    SIZEOF_ARRAY(table),\
    sizeof(KSPROPERTY_ITEM),\
    table
#define DEFINE_KSAUTOMATION_METHODS(table)\
    SIZEOF_ARRAY(table),\
    sizeof(KSMETHOD_ITEM),\
    table
#define DEFINE_KSAUTOMATION_EVENTS(table)\
    SIZEOF_ARRAY(table),\
    sizeof(KSEVENT_ITEM),\
    table
#define DEFINE_KSFILTER_PIN_DESCRIPTORS(table)\
    SIZEOF_ARRAY(table),\
    sizeof(table[0]),\
    table
#define DEFINE_KSFILTER_NODE_DESCRIPTORS(table)\
    SIZEOF_ARRAY(table),\
    sizeof(table[0]),\
    table

// public\sdk\inc\mapidefs.h
#define CbNewSPropTagArray(_ctag) \
	(offsetof(SPropTagArray,aulPropTag) + (_ctag)*sizeof(ULONG))
#define CbSPropTagArray(_lparray) \
	(offsetof(SPropTagArray,aulPropTag) + \
	(UINT)((_lparray)->cValues)*sizeof(ULONG))
#define CbNewSPropProblemArray(_cprob) \
	(offsetof(SPropProblemArray,aProblem) + (_cprob)*sizeof(SPropProblem))
#define CbSPropProblemArray(_lparray) \
	(offsetof(SPropProblemArray,aProblem) + \
	(UINT) ((_lparray)->cProblem*sizeof(SPropProblem)))
#define MAPI_IMAPITABLE_METHODS(IPURE)									\
	MAPIMETHOD(GetLastError)											\
		(THIS_	HRESULT						hResult,					\
				ULONG						ulFlags,					\
				LPMAPIERROR FAR *			lppMAPIError) IPURE;		\
	MAPIMETHOD(Advise)													\
		(THIS_	ULONG						ulEventMask,				\
				LPMAPIADVISESINK			lpAdviseSink,				\
				ULONG FAR *					lpulConnection) IPURE;		\
	MAPIMETHOD(Unadvise)												\
		(THIS_	ULONG						ulConnection) IPURE;		\
	MAPIMETHOD(GetStatus)												\
		(THIS_	ULONG FAR *					lpulTableStatus,			\
				ULONG FAR *					lpulTableType) IPURE;		\
	MAPIMETHOD(SetColumns)												\
		(THIS_	LPSPropTagArray				lpPropTagArray,				\
				ULONG						ulFlags) IPURE;				\
	MAPIMETHOD(QueryColumns)											\
		(THIS_	ULONG						ulFlags,					\
				LPSPropTagArray FAR *		lpPropTagArray) IPURE;		\
	MAPIMETHOD(GetRowCount)												\
		(THIS_	ULONG						ulFlags,					\
				ULONG FAR *					lpulCount) IPURE;			\
	MAPIMETHOD(SeekRow)													\
		(THIS_	BOOKMARK					bkOrigin,					\
				LONG						lRowCount,					\
				LONG FAR *					lplRowsSought) IPURE;		\
	MAPIMETHOD(SeekRowApprox)											\
		(THIS_	ULONG						ulNumerator,				\
				ULONG						ulDenominator) IPURE;		\
	MAPIMETHOD(QueryPosition)											\
		(THIS_	ULONG FAR *					lpulRow,					\
				ULONG FAR *					lpulNumerator,				\
				ULONG FAR *					lpulDenominator) IPURE;		\
	MAPIMETHOD(FindRow)													\
		(THIS_	LPSRestriction				lpRestriction,				\
				BOOKMARK					bkOrigin,					\
				ULONG						ulFlags) IPURE;				\
	MAPIMETHOD(Restrict)												\
		(THIS_	LPSRestriction				lpRestriction,				\
				ULONG						ulFlags) IPURE;				\
	MAPIMETHOD(CreateBookmark)											\
		(THIS_	BOOKMARK FAR *				lpbkPosition) IPURE;		\
	MAPIMETHOD(FreeBookmark)											\
		(THIS_	BOOKMARK					bkPosition) IPURE;			\
	MAPIMETHOD(SortTable)												\
		(THIS_	LPSSortOrderSet				lpSortCriteria,				\
				ULONG						ulFlags) IPURE;				\
	MAPIMETHOD(QuerySortOrder)											\
		(THIS_	LPSSortOrderSet FAR *		lppSortCriteria) IPURE;		\
	MAPIMETHOD(QueryRows)												\
		(THIS_	LONG						lRowCount,					\
				ULONG						ulFlags,					\
				LPSRowSet FAR *				lppRows) IPURE;				\
	MAPIMETHOD(Abort) (THIS) IPURE;										\
	MAPIMETHOD(ExpandRow)												\
		(THIS_	ULONG						cbInstanceKey,				\
				LPBYTE						pbInstanceKey,				\
				ULONG						ulRowCount,					\
				ULONG						ulFlags,					\
				LPSRowSet FAR *				lppRows,					\
				ULONG FAR *					lpulMoreRows) IPURE;		\
	MAPIMETHOD(CollapseRow)												\
		(THIS_	ULONG						cbInstanceKey,				\
				LPBYTE						pbInstanceKey,				\
				ULONG						ulFlags,					\
				ULONG FAR *					lpulRowCount) IPURE;		\
	MAPIMETHOD(WaitForCompletion)										\
		(THIS_	ULONG						ulFlags,					\
				ULONG						ulTimeout,					\
				ULONG FAR *					lpulTableStatus) IPURE;		\
	MAPIMETHOD(GetCollapseState)										\
		(THIS_	ULONG						ulFlags,					\
				ULONG						cbInstanceKey,				\
				LPBYTE						lpbInstanceKey,				\
				ULONG FAR *					lpcbCollapseState,			\
				LPBYTE FAR *				lppbCollapseState) IPURE;	\
	MAPIMETHOD(SetCollapseState)										\
		(THIS_	ULONG						ulFlags,					\
				ULONG						cbCollapseState,			\
				LPBYTE						pbCollapseState,			\
				BOOKMARK FAR *				lpbkLocation) IPURE;		\

// public\sdk\inc\mapiform.h
#define CbMAPIFormPropArray(_c) \
         (offsetof(SMAPIFormPropArray, aFormProp) + \
         (_c)*sizeof(SMAPIFormProp))
#define CbMAPIVerbArray(_c) \
         (offsetof(SMAPIVerbArray, aMAPIVerb) + \
         (_c)*sizeof(SMAPIVerb))
#define CbMessageClassArray(_c) \
        (offsetof(SMessageClassArray, aMessageClass) + (_c)*sizeof(LPCSTR))
#define CbMAPIFormInfoArray(_c) \
         (offsetof(SMAPIFormInfoArray, aFormInfo) + \
         (_c)*sizeof(LPMAPIFORMINFO))

// public\sdk\inc\mapival.h
#define FBadGetProps( lpObj, lpPTagA, lpcValues, lppPropArray) \
	(   (   lpPTagA \
		 && (   IsBadReadPtr( lpPTagA, sizeof(ULONG)) \
			 || IsBadReadPtr( lpPTagA, (UINT)(  (lpPTagA->cValues + 1) \
									          * sizeof(ULONG))))) \
	 || IsBadWritePtr( lpcValues, sizeof(ULONG)) \
	 || IsBadWritePtr( lppPropArray, sizeof(LPSPropValue)))
#define FBadGetPropList( lpObj, lppPTagA) \
	(IsBadWritePtr( lppPTagA, sizeof(LPSPropTagArray FAR *)))
#define FBadSetProps( lpObj, cValues, lpPropArray, lppProblems) \
	(   FBadRgPropVal( lpPropArray, (UINT) cValues) \
	 || (   lppProblems \
		 && IsBadWritePtr( lppProblems, sizeof(LPSPropProblemArray))))
#define FBadDeleteProps( lpObj, lpPTagA, lppProblems) \
	(   (   !lpPTagA \
		 || (   IsBadReadPtr( lpPTagA, sizeof(ULONG)) \
			 || IsBadReadPtr( lpPTagA, (UINT)(  (lpPTagA->cValues + 1) \
									          * sizeof(ULONG))))) \
	 || (   lppProblems \
		 && IsBadWritePtr( lppProblems, sizeof(LPSPropProblemArray))))
#define FBadCopyTo( lpIPDAT, ciidExclude, rgiidExclude, lpExcludeProps \
				  , ulUIParam, lpProgress, lpInterface, lpDestObj \
				  , ulFlags, lppProblems) \
	(	(	ciidExclude \
		 && (  IsBadReadPtr( rgiidExclude, (UINT)(ciidExclude * sizeof(IID))))) \
	 || (   lpExcludeProps \
		 && (   IsBadReadPtr( lpExcludeProps, sizeof(ULONG)) \
			 || IsBadReadPtr( lpExcludeProps \
							, (UINT)(  (lpExcludeProps->cValues + 1) \
							         * sizeof(ULONG))))) \
	 || (lpProgress && FBadUnknown( lpProgress )) \
     || (lpInterface && IsBadReadPtr( lpInterface, sizeof(IID))) \
	 || IsBadReadPtr( lpDestObj, sizeof(LPVOID)) \
	 || (   lppProblems \
		 && IsBadWritePtr( lppProblems, sizeof(LPSPropProblemArray))))
#define FBadCopyProps( lpIPDAT, lpPropTagArray \
					 , ulUIParam, lpProgress, lpInterface, lpDestObj \
					 , ulFlags, lppProblems) \
	(   (   lpPropTagArray \
		 && (   IsBadReadPtr( lpPropTagArray, sizeof(ULONG)) \
			 || IsBadReadPtr( lpPropTagArray \
							, (UINT)(  (lpPropTagArray->cValues + 1) \
							         * sizeof(ULONG))))) \
	 || (lpProgress && FBadUnknown( lpProgress )) \
     || (lpInterface && IsBadReadPtr( lpInterface, sizeof(IID))) \
	 || IsBadReadPtr( lpDestObj, sizeof(LPVOID)) \
	 || (   lppProblems \
		 && IsBadWritePtr( lppProblems, sizeof(LPSPropProblemArray))))
#define FBadGetNamesFromIDs( lpIPDAT, lppPropTags, lpPropSetGuid, ulFlags, \
							 lpcPropNames, lpppPropNames) \
	(   IsBadReadPtr( lppPropTags, sizeof(LPSPropTagArray)) \
	 || ( lpPropSetGuid && IsBadReadPtr( lpPropSetGuid, sizeof(GUID))) \
	 || (   *lppPropTags \
		 && (   IsBadReadPtr( *lppPropTags, sizeof(ULONG)) \
			 || IsBadReadPtr( *lppPropTags \
							, (UINT)( ( ( *lppPropTags)->cValues + 1) \
							         * sizeof(ULONG))))) \
	 || IsBadWritePtr( lpcPropNames, sizeof (ULONG)) \
	 || IsBadWritePtr( lpppPropNames, sizeof (LPVOID FAR *)))

// public\sdk\inc\mfc42\datapath.h
#define IProvideClassInfo3_GetGUIDDwordArrays(This,rguidArray,pcaUUID,pcadw)	\
    (This)->lpVtbl -> GetGUIDDwordArrays(This,rguidArray,pcaUUID,pcadw)

// public\sdk\inc\mimeole.h
#define IMimeAllocator_FreeParamInfoArray(This,cParams,prgParam,fFreeArray)	\
    (This)->lpVtbl -> FreeParamInfoArray(This,cParams,prgParam,fFreeArray)
#define IMimeAllocator_ReleaseObjects(This,cObjects,prgpUnknown,fFreeArray)	\
    (This)->lpVtbl -> ReleaseObjects(This,cObjects,prgpUnknown,fFreeArray)
#define IMimeAllocator_FreeEnumHeaderRowArray(This,cRows,prgRow,fFreeArray)	\
    (This)->lpVtbl -> FreeEnumHeaderRowArray(This,cRows,prgRow,fFreeArray)
#define IMimeAllocator_FreeEnumPropertyArray(This,cProps,prgProp,fFreeArray)	\
    (This)->lpVtbl -> FreeEnumPropertyArray(This,cProps,prgProp,fFreeArray)

// public\sdk\inc\mscoree.h
#define ICorRuntimeHost_CreateDomain(This,pwzFriendlyName,pIdentityArray,pAppDomain)	\
    (This)->lpVtbl -> CreateDomain(This,pwzFriendlyName,pIdentityArray,pAppDomain)

// public\sdk\inc\mshtmlc.h
#define IHTMLElement2_getElementsByTagName(This,v,pelColl)	\
    (This)->lpVtbl -> getElementsByTagName(This,v,pelColl)
#define IHTMLFormElement_get_elements(This,p)	\
    (This)->lpVtbl -> get_elements(This,p)
#define IHTMLEventObj2_putref_boundElements(This,v)	\
    (This)->lpVtbl -> putref_boundElements(This,v)
#define IHTMLEventObj2_get_boundElements(This,p)	\
    (This)->lpVtbl -> get_boundElements(This,p)
#define IHTMLDocument2_write(This,psarray)	\
    (This)->lpVtbl -> write(This,psarray)
#define IHTMLDocument2_writeln(This,psarray)	\
    (This)->lpVtbl -> writeln(This,psarray)
#define IHTMLDocument3_getElementsByName(This,v,pelColl)	\
    (This)->lpVtbl -> getElementsByName(This,v,pelColl)
#define IHTMLDocument3_getElementsByTagName(This,v,pelColl)	\
    (This)->lpVtbl -> getElementsByTagName(This,v,pelColl)
#define IElementSegment_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IElementSegment_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IElementSegment_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IElementSegment_GetPointers(This,pIStart,pIEnd)	\
    (This)->lpVtbl -> GetPointers(This,pIStart,pIEnd)
#define IElementSegment_GetElement(This,ppIElement)	\
    (This)->lpVtbl -> GetElement(This,ppIElement)
#define IElementSegment_SetPrimary(This,fPrimary)	\
    (This)->lpVtbl -> SetPrimary(This,fPrimary)
#define IElementSegment_IsPrimary(This,pfPrimary)	\
    (This)->lpVtbl -> IsPrimary(This,pfPrimary)
#define IMarkupServices2_ValidateElements(This,pPointerStart,pPointerFinish,pPointerTarget,pPointerStatus,ppElemFailBottom,ppElemFailTop)	\
    (This)->lpVtbl -> ValidateElements(This,pPointerStart,pPointerFinish,pPointerTarget,pPointerStatus,ppElemFailBottom,ppElemFailTop)
#define ISelectionServicesListener_OnSelectedElementExit(This,pIElementStart,pIElementEnd,pIElementContentStart,pIElementContentEnd)	\
    (This)->lpVtbl -> OnSelectedElementExit(This,pIElementStart,pIElementEnd,pIElementContentStart,pIElementContentEnd)
#define ISelectionServices_AddElementSegment(This,pIElement,ppISegmentAdded)	\
    (This)->lpVtbl -> AddElementSegment(This,pIElement,ppISegmentAdded)

// public\sdk\inc\msnotify.h
#define IScheduleGroup_GetAttributes(This,pTaskTrigger,pTaskData,pGroupCookie,pGroupInfo,pgrfGroupMode,pElements)	\
    (This)->lpVtbl -> GetAttributes(This,pTaskTrigger,pTaskData,pGroupCookie,pGroupInfo,pgrfGroupMode,pElements)

// public\sdk\inc\mstime.h
#define ITIMEElement_get_activeElements(This,activeColl)	\
    (This)->lpVtbl -> get_activeElements(This,activeColl)
#define ITIMEBodyElement_get_activeElements(This,activeColl)	\
    (This)->lpVtbl -> get_activeElements(This,activeColl)
#define ITIMEMediaElement_get_activeElements(This,activeColl)	\
    (This)->lpVtbl -> get_activeElements(This,activeColl)
#define ITIMEMediaElement2_get_activeElements(This,activeColl)	\
    (This)->lpVtbl -> get_activeElements(This,activeColl)
#define ITIMEAnimationElement_get_activeElements(This,activeColl)	\
    (This)->lpVtbl -> get_activeElements(This,activeColl)
#define ITIMEAnimationElement2_get_activeElements(This,activeColl)	\
    (This)->lpVtbl -> get_activeElements(This,activeColl)

// public\sdk\inc\msxml.h
#define IXMLDOMDocument_getElementsByTagName(This,tagName,resultList)	\
    (This)->lpVtbl -> getElementsByTagName(This,tagName,resultList)
#define IXMLDOMElement_getElementsByTagName(This,tagName,resultList)	\
    (This)->lpVtbl -> getElementsByTagName(This,tagName,resultList)

// public\sdk\inc\msxml2.h
#define IXMLDOMDocument_getElementsByTagName(This,tagName,resultList)	\
    (This)->lpVtbl -> getElementsByTagName(This,tagName,resultList)
#define IXMLDOMDocument2_getElementsByTagName(This,tagName,resultList)	\
    (This)->lpVtbl -> getElementsByTagName(This,tagName,resultList)
#define IXMLDOMElement_getElementsByTagName(This,tagName,resultList)	\
    (This)->lpVtbl -> getElementsByTagName(This,tagName,resultList)

// public\sdk\inc\netsh.h
#define NUM_TOKENS_IN_TABLE(TokenArray) sizeof(TokenArray)/sizeof(TOKEN_VALUE)
#define NUM_TAGS_IN_TABLE(TagsArray)    sizeof(TagsArray)/sizeof(TAG_TYPE)

// public\sdk\inc\ntddvdeo.h
#define BITMAP_ARRAY_BYTE  3       // BYTE array is 8 bit  (shift count = 3)

// public\sdk\inc\ntimage.h
#define ISARY(x) (((x) & N_TMASK) == (IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))

// public\sdk\inc\oaidl.h
#define IRecordInfo_GetFieldNoCopy(This,pvData,szFieldName,pvarField,ppvDataCArray)	\
    (This)->lpVtbl -> GetFieldNoCopy(This,pvData,szFieldName,pvarField,ppvDataCArray)

// public\sdk\inc\objidl.h
#define IStorage_EnumElements(This,reserved1,reserved2,reserved3,ppenum)	\
    (This)->lpVtbl -> EnumElements(This,reserved1,reserved2,reserved3,ppenum)

// public\sdk\inc\oleauto.h
#define V_ISARRAY(X)     (V_VT(X)&VT_ARRAY)

// public\sdk\inc\omscript.h
#define IHTMLElement2_getElementsByTagName(This,v,pelColl)	\
    (This)->lpVtbl -> getElementsByTagName(This,v,pelColl)
#define IHTMLFormElement_get_elements(This,p)	\
    (This)->lpVtbl -> get_elements(This,p)
#define IHTMLEventObj2_putref_boundElements(This,v)	\
    (This)->lpVtbl -> putref_boundElements(This,v)
#define IHTMLEventObj2_get_boundElements(This,p)	\
    (This)->lpVtbl -> get_boundElements(This,p)
#define IHTMLDocument2_write(This,psarray)	\
    (This)->lpVtbl -> write(This,psarray)
#define IHTMLDocument2_writeln(This,psarray)	\
    (This)->lpVtbl -> writeln(This,psarray)
#define IHTMLDocument3_getElementsByName(This,v,pelColl)	\
    (This)->lpVtbl -> getElementsByName(This,v,pelColl)
#define IHTMLDocument3_getElementsByTagName(This,v,pelColl)	\
    (This)->lpVtbl -> getElementsByTagName(This,v,pelColl)
#define IElementSegment_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IElementSegment_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IElementSegment_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IElementSegment_GetPointers(This,pIStart,pIEnd)	\
    (This)->lpVtbl -> GetPointers(This,pIStart,pIEnd)
#define IElementSegment_GetElement(This,ppIElement)	\
    (This)->lpVtbl -> GetElement(This,ppIElement)
#define IElementSegment_SetPrimary(This,fPrimary)	\
    (This)->lpVtbl -> SetPrimary(This,fPrimary)
#define IElementSegment_IsPrimary(This,pfPrimary)	\
    (This)->lpVtbl -> IsPrimary(This,pfPrimary)
#define IMarkupServices2_ValidateElements(This,pPointerStart,pPointerFinish,pPointerTarget,pPointerStatus,ppElemFailBottom,ppElemFailTop)	\
    (This)->lpVtbl -> ValidateElements(This,pPointerStart,pPointerFinish,pPointerTarget,pPointerStatus,ppElemFailBottom,ppElemFailTop)
#define ISelectionServicesListener_OnSelectedElementExit(This,pIElementStart,pIElementEnd,pIElementContentStart,pIElementContentEnd)	\
    (This)->lpVtbl -> OnSelectedElementExit(This,pIElementStart,pIElementEnd,pIElementContentStart,pIElementContentEnd)
#define ISelectionServices_AddElementSegment(This,pIElement,ppISegmentAdded)	\
    (This)->lpVtbl -> AddElementSegment(This,pIElement,ppISegmentAdded)

// public\sdk\inc\optary.h
#define IOptionArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IOptionArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IOptionArray_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IOptionArray_QueryOption(This,dwOption,pBuffer,pcbBuf)	\
    (This)->lpVtbl -> QueryOption(This,dwOption,pBuffer,pcbBuf)
#define IOptionArray_SetOption(This,dwOption,pBuffer,cbBuf)	\
    (This)->lpVtbl -> SetOption(This,dwOption,pBuffer,cbBuf)

// public\sdk\inc\qedit.h
#define IAMTimelineComp_GetCountOfType(This,pVal,pValWithComps,MajorType)	\
    (This)->lpVtbl -> GetCountOfType(This,pVal,pValWithComps,MajorType)
#define IAMTimeline_GetCountOfType(This,Group,pVal,pValWithComps,MajorType)	\
    (This)->lpVtbl -> GetCountOfType(This,Group,pVal,pValWithComps,MajorType)

// public\sdk\inc\rend.h
#define IEnumDialableAddrs_Next(This,celt,ppElements,pcFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pcFetched)
#define IEnumDirectory_Next(This,celt,ppElements,pcFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pcFetched)

// public\sdk\inc\rpcndr.h
#define byte_array_from_ndr(Source, LowerIndex, UpperIndex, Target) \
    { \
    NDRcopy ( \
        (((char  *)(Target))+(LowerIndex)), \
        (Source)->Buffer, \
        (unsigned int)((UpperIndex)-(LowerIndex))); \
    *(unsigned long  *)&(Source)->Buffer += ((UpperIndex)-(LowerIndex)); \
    }
#define boolean_array_from_ndr(Source, LowerIndex, UpperIndex, Target) \
    { \
    NDRcopy ( \
        (((char  *)(Target))+(LowerIndex)), \
        (Source)->Buffer, \
        (unsigned int)((UpperIndex)-(LowerIndex))); \
    *(unsigned long  *)&(Source)->Buffer += ((UpperIndex)-(LowerIndex)); \
    }
#define small_array_from_ndr(Source, LowerIndex, UpperIndex, Target) \
    { \
    NDRcopy ( \
        (((char  *)(Target))+(LowerIndex)), \
        (Source)->Buffer, \
        (unsigned int)((UpperIndex)-(LowerIndex))); \
    *(unsigned long  *)&(Source)->Buffer += ((UpperIndex)-(LowerIndex)); \
    }

// public\sdk\inc\rtccore.h
#define IRTCEnumParticipants_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IRTCEnumProfiles_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IRTCEnumBuddies_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IRTCEnumWatchers_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

// public\sdk\inc\sapi.h
#define ISpEventSource_GetEvents(This,ulCount,pEventArray,pulFetched)	\
    (This)->lpVtbl -> GetEvents(This,ulCount,pEventArray,pulFetched)
#define ISpEventSink_AddEvents(This,pEventArray,ulCount)	\
    (This)->lpVtbl -> AddEvents(This,pEventArray,ulCount)
#define ISpVoice_GetEvents(This,ulCount,pEventArray,pulFetched)	\
    (This)->lpVtbl -> GetEvents(This,ulCount,pEventArray,pulFetched)
#define ISpPhraseAlt_GetAltInfo(This,ppParent,pulStartElementInParent,pcElementsInParent,pcElementsInAlt)	\
    (This)->lpVtbl -> GetAltInfo(This,ppParent,pulStartElementInParent,pcElementsInParent,pcElementsInAlt)
#define ISpRecoResult_GetAlternates(This,ulStartElement,cElements,ulRequestCount,ppPhrases,pcPhrasesReturned)	\
    (This)->lpVtbl -> GetAlternates(This,ulStartElement,cElements,ulRequestCount,ppPhrases,pcPhrasesReturned)
#define ISpRecoResult_GetAudio(This,ulStartElement,cElements,ppStream)	\
    (This)->lpVtbl -> GetAudio(This,ulStartElement,cElements,ppStream)
#define ISpRecoResult_SpeakAudio(This,ulStartElement,cElements,dwFlags,pulStreamNumber)	\
    (This)->lpVtbl -> SpeakAudio(This,ulStartElement,cElements,dwFlags,pulStreamNumber)
#define ISpRecoContext_GetEvents(This,ulCount,pEventArray,pulFetched)	\
    (This)->lpVtbl -> GetEvents(This,ulCount,pEventArray,pulFetched)
#define ISpeechRecognizer_EmulateRecognition(This,TextElements,ElementDisplayAttributes,LanguageId)	\
    (This)->lpVtbl -> EmulateRecognition(This,TextElements,ElementDisplayAttributes,LanguageId)
#define ISpeechRecoResult_Alternates(This,RequestCount,StartElement,Elements,Alternates)	\
    (This)->lpVtbl -> Alternates(This,RequestCount,StartElement,Elements,Alternates)
#define ISpeechRecoResult_Audio(This,StartElement,Elements,Stream)	\
    (This)->lpVtbl -> Audio(This,StartElement,Elements,Stream)
#define ISpeechRecoResult_SpeakAudio(This,StartElement,Elements,Flags,StreamNumber)	\
    (This)->lpVtbl -> SpeakAudio(This,StartElement,Elements,Flags,StreamNumber)
#define ISpeechPhraseAlternate_get_NumberOfElementsInResult(This,NumberOfElements)	\
    (This)->lpVtbl -> get_NumberOfElementsInResult(This,NumberOfElements)
#define ISpeechPhraseInfo_get_Elements(This,Elements)	\
    (This)->lpVtbl -> get_Elements(This,Elements)
#define ISpeechPhraseInfo_GetText(This,StartElement,Elements,UseReplacements,Text)	\
    (This)->lpVtbl -> GetText(This,StartElement,Elements,UseReplacements,Text)
#define ISpeechPhraseInfo_GetDisplayAttributes(This,StartElement,Elements,UseReplacements,DisplayAttributes)	\
    (This)->lpVtbl -> GetDisplayAttributes(This,StartElement,Elements,UseReplacements,DisplayAttributes)
#define ISpeechPhraseElements_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISpeechPhraseElements_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISpeechPhraseElements_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISpeechPhraseElements_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ISpeechPhraseElements_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ISpeechPhraseElements_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ISpeechPhraseElements_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ISpeechPhraseElements_get_Count(This,Count)	\
    (This)->lpVtbl -> get_Count(This,Count)
#define ISpeechPhraseElements_Item(This,Index,Element)	\
    (This)->lpVtbl -> Item(This,Index,Element)
#define ISpeechPhraseElements_get__NewEnum(This,EnumVARIANT)	\
    (This)->lpVtbl -> get__NewEnum(This,EnumVARIANT)
#define ISpeechPhraseReplacement_get_NumberOfElements(This,NumberOfElements)	\
    (This)->lpVtbl -> get_NumberOfElements(This,NumberOfElements)
#define ISpeechPhraseProperty_get_NumberOfElements(This,NumberOfElements)	\
    (This)->lpVtbl -> get_NumberOfElements(This,NumberOfElements)
#define ISpeechPhraseRule_get_NumberOfElements(This,NumberOfElements)	\
    (This)->lpVtbl -> get_NumberOfElements(This,NumberOfElements)
#define ISpeechPhoneConverter_PhoneToId(This,Phonemes,IdArray)	\
    (This)->lpVtbl -> PhoneToId(This,Phonemes,IdArray)
#define ISpeechPhoneConverter_IdToPhone(This,IdArray,Phonemes)	\
    (This)->lpVtbl -> IdToPhone(This,IdArray,Phonemes)

// public\sdk\inc\sapiddk.h
#define ISpPhraseBuilder_AddElements(This,cElements,pElement)	\
    (This)->lpVtbl -> AddElements(This,cElements,pElement)
#define ISpTTSEngineSite_AddEvents(This,pEventArray,ulCount)	\
    (This)->lpVtbl -> AddEvents(This,pEventArray,ulCount)
#define ISpCFGInterpreter_Interpret(This,pPhrase,ulFirstElement,ulCountOfElements,pSite)	\
    (This)->lpVtbl -> Interpret(This,pPhrase,ulFirstElement,ulCountOfElements,pSite)

// public\sdk\inc\shobjidl.h
#define INamespaceWalk_GetIDArrayResult(This,pcItems,pppidl)	\
    (This)->lpVtbl -> GetIDArrayResult(This,pcItems,pppidl)

// public\sdk\inc\snmp.h
#define DEFINE_SIZEOF(Array)        (sizeof(Array)/sizeof((Array)[0]))

// public\sdk\inc\spddkhlp.h
#define sp_countof(x) ((sizeof(x) / sizeof(*(x))))

// public\sdk\inc\speventq.h
#define DECLARE_SPEVENTSOURCE_METHODS(T) \
DECLARE_SPNOTIFYSOURCE_METHODS(T) \
STDMETHODIMP SetInterest(ULONGLONG ullEventInterest, ULONGLONG ullQueuedInterest) \
{ return T._SetInterest(ullEventInterest, ullQueuedInterest); } \
STDMETHODIMP GetEvents(ULONG ulCount, SPEVENT* pEventArray, ULONG * pulFetched) \
{ return T._GetEvents(ulCount, pEventArray, pulFetched); } \
STDMETHODIMP GetInfo(SPEVENTSOURCEINFO *pInfo) \
{ return T._GetInfo(pInfo); }

// public\sdk\inc\sphelper.h
#define sp_countof(x) ((sizeof(x) / sizeof(*(x))))

// public\sdk\inc\strmif.h
#define IAMDroppedFrames_GetDroppedInfo(This,lSize,plArray,plNumCopied)	\
    (This)->lpVtbl -> GetDroppedInfo(This,lSize,plArray,plNumCopied)
#define IDvdInfo_GetAllSPRMs(This,pRegisterArray)	\
    (This)->lpVtbl -> GetAllSPRMs(This,pRegisterArray)
#define IDvdInfo_GetAllGPRMs(This,pRegisterArray)	\
    (This)->lpVtbl -> GetAllGPRMs(This,pRegisterArray)
#define IDvdInfo2_GetAllSPRMs(This,pRegisterArray)	\
    (This)->lpVtbl -> GetAllSPRMs(This,pRegisterArray)
#define IDvdInfo2_GetAllGPRMs(This,pRegisterArray)	\
    (This)->lpVtbl -> GetAllGPRMs(This,pRegisterArray)
#define IVMRMonitorConfig_GetAvailableMonitors(This,pInfo,dwMaxInfoArraySize,pdwNumDevices)	\
    (This)->lpVtbl -> GetAvailableMonitors(This,pInfo,dwMaxInfoArraySize,pdwNumDevices)

// public\sdk\inc\tapi3.h
#define IEnumAgent_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumAgentSession_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumQueue_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumACDGroup_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumAgentHandler_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

// public\sdk\inc\tapi3cc.h
#define IEnumAgent_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumAgentSession_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumQueue_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumACDGroup_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumAgentHandler_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

// public\sdk\inc\tapi3if.h
#define ITAddress2_DeviceSpecificVariant(This,pCall,varDevSpecificByteArray)	\
    (This)->lpVtbl -> DeviceSpecificVariant(This,pCall,varDevSpecificByteArray)
#define ITPhone_DeviceSpecificVariant(This,varDevSpecificByteArray)	\
    (This)->lpVtbl -> DeviceSpecificVariant(This,varDevSpecificByteArray)
#define IEnumPhone_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumTerminal_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumTerminalClass_Next(This,celt,pElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,pElements,pceltFetched)
#define IEnumCall_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumAddress_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumCallHub_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumPluggableTerminalClassInfo_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumPluggableSuperclassInfo_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumLocation_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumCallingCard_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumStream_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)
#define IEnumSubStream_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

// public\sdk\inc\tnef.h
#define CbNewSTnefProblemArray(_cprob) \
	(offsetof(STnefProblemArray,aProblem) + (_cprob)*sizeof(STnefProblem))
#define CbSTnefProblemArray(_lparray) \
	(offsetof(STnefProblemArray,aProblem) + \
	(UINT) ((_lparray)->cProblem*sizeof(STnefProblem)))

// public\sdk\inc\wabdefs.h
#define CbNewSPropTagArray(_ctag) \
    (offsetof(SPropTagArray,aulPropTag) + (_ctag)*sizeof(ULONG))
#define CbSPropTagArray(_lparray) \
    (offsetof(SPropTagArray,aulPropTag) + \
    (UINT)((_lparray)->cValues)*sizeof(ULONG))
#define CbNewSPropProblemArray(_cprob) \
    (offsetof(SPropProblemArray,aProblem) + (_cprob)*sizeof(SPropProblem))
#define CbSPropProblemArray(_lparray) \
    (offsetof(SPropProblemArray,aProblem) + \
    (UINT) ((_lparray)->cProblem*sizeof(SPropProblem)))
#define MAPI_IMAPITABLE_METHODS(IPURE)                                  \
    MAPIMETHOD(GetLastError)                                            \
        (THIS_  HRESULT                     hResult,                    \
                ULONG                       ulFlags,                    \
                LPMAPIERROR FAR *           lppMAPIError) IPURE;        \
    MAPIMETHOD(Advise)                                                  \
        (THIS_  ULONG                       ulEventMask,                \
                LPMAPIADVISESINK            lpAdviseSink,               \
                ULONG FAR *                 lpulConnection) IPURE;      \
    MAPIMETHOD(Unadvise)                                                \
        (THIS_  ULONG                       ulConnection) IPURE;        \
    MAPIMETHOD(GetStatus)                                               \
        (THIS_  ULONG FAR *                 lpulTableStatus,            \
                ULONG FAR *                 lpulTableType) IPURE;       \
    MAPIMETHOD(SetColumns)                                              \
        (THIS_  LPSPropTagArray             lpPropTagArray,             \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(QueryColumns)                                            \
        (THIS_  ULONG                       ulFlags,                    \
                LPSPropTagArray FAR *       lpPropTagArray) IPURE;      \
    MAPIMETHOD(GetRowCount)                                             \
        (THIS_  ULONG                       ulFlags,                    \
                ULONG FAR *                 lpulCount) IPURE;           \
    MAPIMETHOD(SeekRow)                                                 \
        (THIS_  BOOKMARK                    bkOrigin,                   \
                LONG                        lRowCount,                  \
                LONG FAR *                  lplRowsSought) IPURE;       \
    MAPIMETHOD(SeekRowApprox)                                           \
        (THIS_  ULONG                       ulNumerator,                \
                ULONG                       ulDenominator) IPURE;       \
    MAPIMETHOD(QueryPosition)                                           \
        (THIS_  ULONG FAR *                 lpulRow,                    \
                ULONG FAR *                 lpulNumerator,              \
                ULONG FAR *                 lpulDenominator) IPURE;     \
    MAPIMETHOD(FindRow)                                                 \
        (THIS_  LPSRestriction              lpRestriction,              \
                BOOKMARK                    bkOrigin,                   \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(Restrict)                                                \
        (THIS_  LPSRestriction              lpRestriction,              \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(CreateBookmark)                                          \
        (THIS_  BOOKMARK FAR *              lpbkPosition) IPURE;        \
    MAPIMETHOD(FreeBookmark)                                            \
        (THIS_  BOOKMARK                    bkPosition) IPURE;          \
    MAPIMETHOD(SortTable)                                               \
        (THIS_  LPSSortOrderSet             lpSortCriteria,             \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(QuerySortOrder)                                          \
        (THIS_  LPSSortOrderSet FAR *       lppSortCriteria) IPURE;     \
    MAPIMETHOD(QueryRows)                                               \
        (THIS_  LONG                        lRowCount,                  \
                ULONG                       ulFlags,                    \
                LPSRowSet FAR *             lppRows) IPURE;             \
    MAPIMETHOD(Abort) (THIS) IPURE;                                     \
    MAPIMETHOD(ExpandRow)                                               \
        (THIS_  ULONG                       cbInstanceKey,              \
                LPBYTE                      pbInstanceKey,              \
                ULONG                       ulRowCount,                 \
                ULONG                       ulFlags,                    \
                LPSRowSet FAR *             lppRows,                    \
                ULONG FAR *                 lpulMoreRows) IPURE;        \
    MAPIMETHOD(CollapseRow)                                             \
        (THIS_  ULONG                       cbInstanceKey,              \
                LPBYTE                      pbInstanceKey,              \
                ULONG                       ulFlags,                    \
                ULONG FAR *                 lpulRowCount) IPURE;        \
    MAPIMETHOD(WaitForCompletion)                                       \
        (THIS_  ULONG                       ulFlags,                    \
                ULONG                       ulTimeout,                  \
                ULONG FAR *                 lpulTableStatus) IPURE;     \
    MAPIMETHOD(GetCollapseState)                                        \
        (THIS_  ULONG                       ulFlags,                    \
                ULONG                       cbInstanceKey,              \
                LPBYTE                      lpbInstanceKey,             \
                ULONG FAR *                 lpcbCollapseState,          \
                LPBYTE FAR *                lppbCollapseState) IPURE;   \
    MAPIMETHOD(SetCollapseState)                                        \
        (THIS_  ULONG                       ulFlags,                    \
                ULONG                       cbCollapseState,            \
                LPBYTE                      pbCollapseState,            \
                BOOKMARK FAR *              lpbkLocation) IPURE;        \

// public\sdk\inc\wbemcli.h
#define IWbemObjectSink_Indicate(This,lObjectCount,apObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,apObjArray)

// public\sdk\inc\wbemdisp.h
#define ISWbemObject_get_Derivation_(This,strClassNameArray)	\
    (This)->lpVtbl -> get_Derivation_(This,strClassNameArray)
#define ISWbemProperty_get_IsArray(This,bIsArray)	\
    (This)->lpVtbl -> get_IsArray(This,bIsArray)
#define ISWbemPropertySet_Add(This,strName,iCIMType,bIsArray,iFlags,objWbemProperty)	\
    (This)->lpVtbl -> Add(This,strName,iCIMType,bIsArray,iFlags,objWbemProperty)
#define ISWbemLastError_get_Derivation_(This,strClassNameArray)	\
    (This)->lpVtbl -> get_Derivation_(This,strClassNameArray)
#define ISWbemObjectEx_get_Derivation_(This,strClassNameArray)	\
    (This)->lpVtbl -> get_Derivation_(This,strClassNameArray)

// public\sdk\inc\wbemprov.h
#define IWbemEventSink_Indicate(This,lObjectCount,apObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,apObjArray)

// public\sdk\inc\windns.h
#define DNS_TEXT_RECORD_LENGTH(StringCount) \
            (FIELD_OFFSET(DNS_TXT_DATA, pStringArray) + ((StringCount) * sizeof(PCHAR)))

// public\sdk\inc\winerror.h
#define DISP_E_ARRAYISLOCKED             _HRESULT_TYPEDEF_(0x8002000DL)

// public\sdk\inc\winnt.h
#define ISARY(x) (((x) & N_TMASK) == (IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))

// public\sdk\inc\winsock.h
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
        ((fd_set FAR *)(set))->fd_array[((fd_set FAR *)(set))->fd_count++]=(fd);\
} while(0)

// public\sdk\inc\winsock2.h
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
    u_int __i; \
    for (__i = 0; __i < ((fd_set FAR *)(set))->fd_count; __i++) { \
        if (((fd_set FAR *)(set))->fd_array[__i] == (fd)) { \
            break; \
        } \
    } \
    if (__i == ((fd_set FAR *)(set))->fd_count) { \
        if (((fd_set FAR *)(set))->fd_count < FD_SETSIZE) { \
            ((fd_set FAR *)(set))->fd_array[__i] = (fd); \
            ((fd_set FAR *)(set))->fd_count++; \
        } \
    } \
} while(0)

// public\sdk\inc\wmidata.h
    #define MSNdis_MediaSupported_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_MediaInUse_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_CoMediaSupported_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_CoMediaInUse_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_EthernetMulticastList_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_FddiLongMulticastList_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_FddiShortMulticastList_NumberElements_SIZE sizeof(ULONG)
    #define MSNdis_StatusMediaSpecificIndication_NumberElements_SIZE sizeof(ULONG)

// public\sdk\inc\wmiutils.h
#define IWbemQuery_SetLanguageFeatures(This,uFlags,uArraySize,puFeatures)	\
    (This)->lpVtbl -> SetLanguageFeatures(This,uFlags,uArraySize,puFeatures)
#define IWbemQuery_TestLanguageFeatures(This,uFlags,uArraySize,puFeatures)	\
    (This)->lpVtbl -> TestLanguageFeatures(This,uFlags,uArraySize,puFeatures)

// public\sdk\inc\wmsdkidl.h
#define IWMStreamList_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMMutualExclusion_GetStreams(This,pwStreamNumArray,pcStreams)	\
    (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams)
#define IWMReaderNetworkConfig_GetUDPPortRanges(This,pRangeArray,pcRanges)	\
    (This)->lpVtbl -> GetUDPPortRanges(This,pRangeArray,pcRanges)
#define IWMReaderNetworkConfig_SetUDPPortRanges(This,pRangeArray,cRanges)	\
    (This)->lpVtbl -> SetUDPPortRanges(This,pRangeArray,cRanges)

// published\ddk\inc\wdm\acpiioct.h
#define ACPI_METHOD_ARGUMENT_LENGTH_FROM_ARGUMENT( Argument )              \
    ( ( (PACPI_METHOD_ARGUMENT) Argument)->DataLength > sizeof(ULONG) ?    \
      ( (PACPI_METHOD_ARGUMENT) Argument)->DataLength + 2 * sizeof(USHORT):\
      2 * sizeof(USHORT) + sizeof(ULONG) )
#define ACPI_METHOD_ARGUMENT_LENGTH( DataLength )                          \
    ( (DataLength > sizeof(ULONG)) ? DataLength + (2 * sizeof(USHORT)) :   \
        2 * sizeof(USHORT) + sizeof(ULONG) )

// published\sdk\inc\dao360\_dbdao.h
#define ATV(psa, var)								\
	do												\
		{											\
		if (!psa)									\
			{										\
			var.vt		= VT_ERROR;					\
			var.scode	= DISP_E_PARAMNOTFOUND;		\
			}										\
		else										\
			{										\
			var.vt		= VT_ARRAY|VT_UI1;			\
			SafeArrayCopy(psa, &var.parray);	\
			}										\
		}											\
	while (0)

// published\sdk\inc\imessage.h
#define CbNewSPropAttrArray(_cattr) \
	(offsetof(SPropAttrArray,aPropAttr) + (_cattr)*sizeof(ULONG))
#define CbSPropAttrArray(_lparray) \
	(offsetof(SPropAttrArray,aPropAttr) + \
	(UINT)((_lparray)->cValues)*sizeof(ULONG))

// published\sdk\inc\mapiform.h
#define CbMAPIFormPropArray(_c) \
         (offsetof(SMAPIFormPropArray, aFormProp) + \
         (_c)*sizeof(SMAPIFormProp))
#define CbMAPIVerbArray(_c) \
         (offsetof(SMAPIVerbArray, aMAPIVerb) + \
         (_c)*sizeof(SMAPIVerb))
#define CbMessageClassArray(_c) \
        (offsetof(SMessageClassArray, aMessageClass) + (_c)*sizeof(LPCSTR))
#define CbMAPIFormInfoArray(_c) \
         (offsetof(SMAPIFormInfoArray, aFormInfo) + \
         (_c)*sizeof(LPMAPIFORMINFO))

// published\sdk\inc\mapival.h
#define FBadGetProps( lpObj, lpPTagA, lpcValues, lppPropArray) \
	(   (   lpPTagA \
		 && (   IsBadReadPtr( lpPTagA, sizeof(ULONG)) \
			 || IsBadReadPtr( lpPTagA, (UINT)(  (lpPTagA->cValues + 1) \
									          * sizeof(ULONG))))) \
	 || IsBadWritePtr( lpcValues, sizeof(ULONG)) \
	 || IsBadWritePtr( lppPropArray, sizeof(LPSPropValue)))
#define FBadGetPropList( lpObj, lppPTagA) \
	(IsBadWritePtr( lppPTagA, sizeof(LPSPropTagArray FAR *)))
#define FBadSetProps( lpObj, cValues, lpPropArray, lppProblems) \
	(   FBadRgPropVal( lpPropArray, (UINT) cValues) \
	 || (   lppProblems \
		 && IsBadWritePtr( lppProblems, sizeof(LPSPropProblemArray))))
#define FBadDeleteProps( lpObj, lpPTagA, lppProblems) \
	(   (   !lpPTagA \
		 || (   IsBadReadPtr( lpPTagA, sizeof(ULONG)) \
			 || IsBadReadPtr( lpPTagA, (UINT)(  (lpPTagA->cValues + 1) \
									          * sizeof(ULONG))))) \
	 || (   lppProblems \
		 && IsBadWritePtr( lppProblems, sizeof(LPSPropProblemArray))))
#define FBadCopyTo( lpIPDAT, ciidExclude, rgiidExclude, lpExcludeProps \
				  , ulUIParam, lpProgress, lpInterface, lpDestObj \
				  , ulFlags, lppProblems) \
	(	(	ciidExclude \
		 && (  IsBadReadPtr( rgiidExclude, (UINT)(ciidExclude * sizeof(IID))))) \
	 || (   lpExcludeProps \
		 && (   IsBadReadPtr( lpExcludeProps, sizeof(ULONG)) \
			 || IsBadReadPtr( lpExcludeProps \
							, (UINT)(  (lpExcludeProps->cValues + 1) \
							         * sizeof(ULONG))))) \
	 || (lpProgress && FBadUnknown( lpProgress )) \
     || (lpInterface && IsBadReadPtr( lpInterface, sizeof(IID))) \
	 || IsBadReadPtr( lpDestObj, sizeof(LPVOID)) \
	 || (   lppProblems \
		 && IsBadWritePtr( lppProblems, sizeof(LPSPropProblemArray))))
#define FBadCopyProps( lpIPDAT, lpPropTagArray \
					 , ulUIParam, lpProgress, lpInterface, lpDestObj \
					 , ulFlags, lppProblems) \
	(   (   lpPropTagArray \
		 && (   IsBadReadPtr( lpPropTagArray, sizeof(ULONG)) \
			 || IsBadReadPtr( lpPropTagArray \
							, (UINT)(  (lpPropTagArray->cValues + 1) \
							         * sizeof(ULONG))))) \
	 || (lpProgress && FBadUnknown( lpProgress )) \
     || (lpInterface && IsBadReadPtr( lpInterface, sizeof(IID))) \
	 || IsBadReadPtr( lpDestObj, sizeof(LPVOID)) \
	 || (   lppProblems \
		 && IsBadWritePtr( lppProblems, sizeof(LPSPropProblemArray))))
#define FBadGetNamesFromIDs( lpIPDAT, lppPropTags, lpPropSetGuid, ulFlags, \
							 lpcPropNames, lpppPropNames) \
	(   IsBadReadPtr( lppPropTags, sizeof(LPSPropTagArray)) \
	 || ( lpPropSetGuid && IsBadReadPtr( lpPropSetGuid, sizeof(GUID))) \
	 || (   *lppPropTags \
		 && (   IsBadReadPtr( *lppPropTags, sizeof(ULONG)) \
			 || IsBadReadPtr( *lppPropTags \
							, (UINT)( ( ( *lppPropTags)->cValues + 1) \
							         * sizeof(ULONG))))) \
	 || IsBadWritePtr( lpcPropNames, sizeof (ULONG)) \
	 || IsBadWritePtr( lpppPropNames, sizeof (LPVOID FAR *)))

// published\sdk\inc\snmp.h
#define DEFINE_SIZEOF(Array)        (sizeof(Array)/sizeof((Array)[0]))

// published\sdk\inc\tnef.h
#define CbNewSTnefProblemArray(_cprob) \
	(offsetof(STnefProblemArray,aProblem) + (_cprob)*sizeof(STnefProblem))
#define CbSTnefProblemArray(_lparray) \
	(offsetof(STnefProblemArray,aProblem) + \
	(UINT) ((_lparray)->cProblem*sizeof(STnefProblem)))

// sdktools\addsect\addsect.cpp
#define arrayof(a)      (sizeof(a)/sizeof(a[0]))

// sdktools\apimon\apimon\help.cpp
#define MAX_HELP_IDS (sizeof(HelpTable)/sizeof(HELP_IDS))

// sdktools\apimon\apimon\i386\machine.cpp
#define REGNAMESIZE (sizeof(regname) / sizeof(REG))

// sdktools\apimon\apimon\registry.cpp
#define MAX_SYSTEM_DLLS (sizeof(SystemDlls)/sizeof(LPSTR))

// sdktools\apimon\apimon\ui.cpp
#define MAX_TOOLBAR_STATES (sizeof(ToolbarState)/sizeof(TOOLBAR_STATE))

// sdktools\appcompat\appcompat.c
#define MAXVERNUM   ( sizeof(pVersionVal)/sizeof(TCHAR*) ) - 1

// sdktools\appverif\avutil.h
#define ARRAY_LENGTH( array )   ( sizeof( array ) / sizeof( array[ 0 ] ) )

// sdktools\buggy\driver\tdriver.h
#define ARRAY_LENGTH( array ) ( sizeof( array ) / sizeof( array[ 0 ] ) )

// sdktools\build\buildscn.c
#define BUILD_TLIB_INCLUDE_STMT_LENGTH (sizeof( BUILD_TLIB_INCLUDE_STMT )-1)
#define BUILD_MIDL_INCLUDE_STMT_LENGTH (sizeof( BUILD_MIDL_INCLUDE_STMT )-1)
#define BUILD_RC_INCLUDE_STMT_LENGTH (sizeof( BUILD_RC_INCLUDE_STMT )-1)
#define BUILD_ASN_INCLUDE_STMT_LENGTH (sizeof( BUILD_ASN_INCLUDE_STMT )-1)
#define BUILD_INCLUDE_STMT_LENGTH (sizeof( BUILD_INCLUDE_STMT )-1)
#define BUILD_VER_COMMENT_LENGTH (sizeof( BUILD_VER_COMMENT )-1)
#define BUILD_MASM_VER_COMMENT_LENGTH (sizeof( BUILD_MASM_VER_COMMENT )-1)

// sdktools\build\buildutl.c
#define MT_MAX  (sizeof(MemTab)/sizeof(MemTab[0]))

// sdktools\crash\driver\crashdrv.c
#define MaxTests  (sizeof(tests)/sizeof(PTESTFUNC))

// sdktools\ctlcode\ctlcode.h
#define MAX_IOCTL_METHOD ((sizeof(TableIoctlMethod)/sizeof(IOCTL_METHOD)-1))
#define MAX_IOCTL_ACCESS ((sizeof(TableIoctlAccess)/sizeof(IOCTL_ACCESS)-1))
#define MAX_IOCTL_DEVICE_TYPE ((sizeof(TableIoctlDeviceType)/sizeof(IOCTL_DEVICE_TYPE)-1))

// sdktools\custcon\stdafx.h
#define array_size(x)   (sizeof(x) / sizeof(x[0]))

// sdktools\debuggers\imagehlp\vc\dia2.h
#define IDiaSymbol_get_arrayIndexType(This,pRetVal)	\
    (This)->lpVtbl -> get_arrayIndexType(This,pRetVal)
#define IDiaSymbol_get_arrayIndexTypeId(This,pRetVal)	\
    (This)->lpVtbl -> get_arrayIndexTypeId(This,pRetVal)

// sdktools\gutils\gutils.h
#define DimensionOf(x) (sizeof(x) / sizeof(x[0]))

// sdktools\hextract\hextract.c
#define BUILD_VER_COMMENT_LENGTH (sizeof( BUILD_VER_COMMENT )-1)

// sdktools\hivepp\p1types.h
#define	IN_ADDRESS			(IN_ARRAY | IN_PDATA | IN_PFUNC)
#define	IN_DATA_ADDRESS		(IN_ARRAY & IN_PDATA)	/* yes, i meant '&' */

// sdktools\ioverify\resutil.hxx
#define ARRAY_LEN( array )  ( sizeof(array) / sizeof( array[0] ) )

// sdktools\kbdtool\kbdtxt2c.c
#define NUMVKNAME ( sizeof(VKName) / sizeof(VKEYNAME) )
#define NUMSCVK ( sizeof(ScVk) / sizeof(SC_VK) )
#define NUMATTR (sizeof(Attribute) / sizeof(Attribute[0]))

// sdktools\kverify\genutil.hxx
#define ARRAY_LEN( array )  ( sizeof(array) / sizeof( array[0] ) )

// sdktools\munger\inc\locale.h
#define NUM_LOCALE              (sizeof(Locale)/sizeof(Locale[0]))

// sdktools\pdh\inc\pdhidef.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)

// sdktools\pdh\inc\perfdata.h
#define FirstCounter(pObjectDef) \
    (PERF_COUNTER_DEFINITION *)((PCHAR)(pObjectDef) + (pObjectDef)->HeaderLength)

// sdktools\pdh\perfmon5\perfmon5.h
#define  sizeofCodeName sizeof(LOCAL_SYS_CODE_NAME) / sizeof(WCHAR) - 1

// sdktools\pdh\tests\bvt\perfval.h
#define FirstCounter(pObjectDef)       \
   ((PERF_COUNTER_DEFINITION *) ((PCHAR)pObjectDef + pObjectDef->HeaderLength))

// sdktools\pdh\tests\ctrtest\ctrtest.h
#define FirstCounter(pObjectDef)       \
   ((PERF_COUNTER_DEFINITION *) ((PCHAR)pObjectDef + pObjectDef->HeaderLength))

// sdktools\perfmon\addline.c
#define NUMBER_OF_SCALE sizeof(apszScaleFmt)/sizeof(apszScaleFmt[0])
#define NumColorIndexes()     \
   (sizeof (argbColors) / sizeof (argbColors[0]))

// sdktools\perfmon\line.c
#define  sizeofCodeName sizeof(LOCAL_SYS_CODE_NAME) / sizeof(TCHAR) - 1
#define NumPrinterLineStyles()   \
   (sizeof (aiPrinterLineStyles) / sizeof (aiPrinterLineStyles [0]))
#define NumPrinterLineColors()   \
   (sizeof (acrPrinterLineColors) / sizeof (acrPrinterLineColors [0]))

// sdktools\perfmon\perfdata.h
#define FirstCounter(pObjectDef)       \
   ((PPERFCOUNTERDEF ) ((PCHAR)pObjectDef + pObjectDef->HeaderLength))

// sdktools\perfmon\toolbar.c
#define TB_ENTRIES sizeof(tbButtons)/sizeof(tbButtons[0])

// sdktools\perfmon\utils.h
#define StringLoad(wID, szText)                       \
   (LoadString (hInstance, wID,                       \
    szText, (sizeof (szText) / sizeof(TCHAR)) - 1))

// sdktools\pfmon\pfmonp.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// sdktools\proccon\clitool\clitool.cpp
#define ENTRY_COUNT(x) (int)((sizeof(x) / sizeof(x[0])))

// sdktools\proccon\library\procconlib.cpp
#define ENTRY_COUNT(x) (sizeof(x) / sizeof(x[0]))

// sdktools\proccon\service\procconsvc.h
#define ENTRY_COUNT(x) (sizeof(x) / sizeof(x[0]))

// sdktools\ramdiskctrl\ramdiskctrl.c
#define arrayof(a)      (sizeof(a)/sizeof(a[0]))

// sdktools\rasdiag\private\ncdefine.h
#define celems(_x)          (sizeof(_x) / sizeof(_x[0]))

// sdktools\rcdll\p0defs.h
#define LIMIT(a)        &(a)[sizeof(a) / sizeof(*a)]

// sdktools\rcdll\p1types.h
#define IN_ADDRESS                      (IN_ARRAY | IN_PDATA | IN_PFUNC)
#define IN_DATA_ADDRESS                 (IN_ARRAY & IN_PDATA)   /* yes, i meant '&' */

// sdktools\rcdll\rctp.c
#define C_CTRLTYPES (sizeof(ctrlTypes) / sizeof(CTRLTYPE))
#define C_CTRLNAMES (sizeof(ctrlNames) / sizeof(CTRLNAME))

// sdktools\remote\srvlist.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// sdktools\setedit\addline.c
#define NUMBER_OF_SCALE sizeof(apszScaleFmt)/sizeof(apszScaleFmt[0])
#define NumColorIndexes()     \
   (sizeof (argbColors) / sizeof (argbColors[0]))

// sdktools\setedit\line.c
#define  sizeofCodeName sizeof(LOCAL_SYS_CODE_NAME) / sizeof(TCHAR) - 1
    #define NumPrinterLineStyles()   \
   (sizeof (aiPrinterLineStyles) / sizeof (aiPrinterLineStyles [0]))
    #define NumPrinterLineColors()   \
   (sizeof (acrPrinterLineColors) / sizeof (acrPrinterLineColors [0]))

// sdktools\setedit\perfdata.h
#define FirstCounter(pObjectDef)       \
   ((PERF_COUNTER_DEFINITION *) ((PCHAR)pObjectDef + pObjectDef->HeaderLength))

// sdktools\setedit\toolbar.c
#define TB_ENTRIES sizeof(tbButtons)/sizeof(tbButtons[0])

// sdktools\setedit\utils.h
#define StringLoad(wID, szText)                       \
   (LoadString (hInstance, wID,                       \
    szText, (sizeof (szText) / sizeof(TCHAR)) - 1))

// sdktools\spt\cdburn\burn.c
#define AllowedBurnSenseEntries (sizeof(AllowedBurnSense)/sizeof(SENSE_STUFF))
#define AllowedReadDiscInfoEntries (sizeof(AllowedReadDiscInfo)/sizeof(SENSE_STUFF))

// sdktools\spt\dvdburn\burn.c
#define AllowedBurnSenseEntries (sizeof(AllowedBurnSense)/sizeof(SENSE_STUFF))
#define AllowedReadDiscInfoEntries (sizeof(AllowedReadDiscInfo)/sizeof(SENSE_STUFF))

// sdktools\tlist\tlist.c
    #define MAX_THREADSTATE    (sizeof(szThreadState) / sizeof(TCHAR *))

// sdktools\verifier\vrfutil.h
#define ARRAY_LENGTH( array )   ( sizeof( array ) / sizeof( array[ 0 ] ) )

// sdktools\verifier\win2k\verify.hxx
#define ARRAY_LENGTH( array ) ( sizeof( array ) / sizeof( array[ 0 ] ) )

// sdktools\vmmreg32\regkylst.c
#define NUMBER_PREDEF_KEYS      (sizeof(g_RgPredefinedKeys) / sizeof(HKEY))

// sdktools\windiff\windiff\profile.h
 #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// sdktools\winobj\wfext.h
#define FM_GETSELCOUNT      (WM_USER + 0x0202)
#define FM_GETSELCOUNTLFN   (WM_USER + 0x0203)  // LFN versions are odd

// shell\comctl32\v5\cutils.c
  #define NUM_DEFAULT_MAPS (sizeof(SysColorMap)/sizeof(COLORMAP))

// shell\comctl32\v6\listbox_ctl3.c
#define AWCHLEN(a) ((sizeof(a)/sizeof(a[0])) - 1)

// shell\comctl32\v6\markup.cpp
#define POINTSPERRECT       (sizeof(RECT)/sizeof(POINT))

// shell\cpls\inetcpl\connectn.cpp
#define NUM_HIDE (sizeof(iHideIDs) / sizeof(int))
#define NUM_MOVE (sizeof(iMoveIDs) / sizeof(int))

// shell\cpls\inetcpl\proxysup.cpp
#define ARRAY_ELEMENTS(array)   (sizeof(array)/sizeof(array[0]))
#define INTERNET_MAX_PORT_LENGTH    sizeof("123456789")
#define MAX_SCHEME_NAME_LENGTH  sizeof("gopher")

// shell\cpls\main\main.c
#define NUM_APPLETS (sizeof(Applets) / sizeof(Applets[0]))

// shell\cpls\poscpl\internal.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

// shell\cpls\system\pfrscpl.cpp
#define sizeofSTRT(sz)  sizeof(sz)  / sizeof(TCHAR)
#define sizeofSTRW(wsz) sizeof(wsz) / sizeof(WCHAR)

// shell\evtmon\inc\msoem.h
#define IMaxRg(dcl, type) \
            (sizeof(dcl) / sizeof(type))
#define MsoIMaxRg(rg) \
            (sizeof(rg) / sizeof(rg[0]))

// shell\ext\brfcase\filesync\core\stock.h
#define ARRAY_ELEMENTS(rg)                (sizeof(rg) / sizeof((rg)[0]))

// shell\ext\brfcase\filesync\syncui\comm.h
#define GAllocArray(type, cNum)          (type *)GAlloc(sizeof(type) * (cNum))
#define GReAllocArray(type, pb, cNum)    (type *)GReAlloc(pb, sizeof(type) * (cNum))

// shell\ext\brfcase\filesync\syncui\mem.h
#define SharedAllocArray(type, cNum)    (type _huge *)SharedAlloc(sizeof(type) * (cNum))
#define SharedReAllocArray(type, pb, cNum) (type _huge *)SharedReAlloc(pb, sizeof(type) * (cNum))

// shell\ext\cdfview\view.cpp
    #define     COLUMNS  (sizeof(aColumnInfo) / sizeof(aColumnInfo[0]))

// shell\ext\docprop\offglue.h
#define NUM_ELEMENTS( vector ) ( sizeof(vector) / sizeof( (vector)[0] ) )

// shell\ext\docpropv3\defprop.cpp
#define DEFPROP_ENTRY( name, fmtid, propid, type, srctype, pfid, access, addmissing, ctlID ) \
    { name, &fmtid, propid, type, srctype, &pfid, access, addmissing, FALSE, &ctlID, 0, 0 },
#define DEFPROP_ENUM_ENTRY( name, fmtid, propid, type, srctype, pfid, access, addmissing, ctlID, cVals, vals ) \
    { name, &fmtid, propid, type, srctype, &pfid, access, addmissing, TRUE, &ctlID, cVals, vals },

// shell\ext\hnw\nconn16\theapp.cpp
#define _countof(ar) (sizeof(ar) / sizeof((ar)[0]))

// shell\ext\hnw\shared\registry.cpp
#define _countof(ar) (sizeof(ar) / sizeof((ar)[0]))

// shell\ext\hnw\shared\util.h
#define _countof(ar) (sizeof(ar) / sizeof((ar)[0]))

// shell\ext\hnw\wizard\stdafx.h
#define _countof(ar) (sizeof(ar) / sizeof((ar)[0]))

// shell\ext\mlang\fechauto.cpp
#define CchCountThreshold(icet)	(((icet) == icetHz || (icet) == icetUtf7) ? 5 : 10)

// shell\ext\mlang\validate.cpp
#define FTstCounting(tst)                   (((tst) & 0x40) != 0)   // If the state is counting (including ACC)
#define TstNotCountingFromTst(tst)          ((tst) & 0x3f)          // Obtain the real state from the counting

// shell\ext\neptune\aidanl\davtrans\ifaces\idavstore.h
#define IDavStorage_EnumElements(This,reserved1,reserved2,reserved3,ppenum)	\
    (This)->lpVtbl -> EnumElements(This,reserved1,reserved2,reserved3,ppenum)

// shell\ext\neptune\aidanl\davtrans\ifaces\ishellstg.h
#define IShellStorage_EnumElements(This,reserved1,reserved2,reserved3,ppenum)	\
    (This)->lpVtbl -> EnumElements(This,reserved1,reserved2,reserved3,ppenum)

// shell\ext\netplwiz\mnddlg.cpp
#define DRIVE_NAME_LENGTH   ((sizeof(DRIVE_NAME_STRING) - 1) / sizeof(TCHAR))

// shell\ext\shimgvw\seltrack.cpp
#define _countof(array) (sizeof(array)/sizeof(array[0]))

// shell\ext\url\cfmacros.h
#define CF_TABLE_ENTRY(pClsid, pfnCreate )   { &c_CFVtbl, pClsid, pfnCreate },

// shell\ext\url\stock.h
#define ARRAY_ELEMENTS(rg)                (sizeof(rg) / sizeof((rg)[0]))

// shell\ext\webcheck\admin.cpp
#define ACTIONTABLECOUNT (sizeof(rgActionTable) / sizeof(ACTIONTABLE))

// shell\ext\webcheck\test\autosub\autosub.cpp
#define DIM(x)              (sizeof(x) / sizeof(x[0]))

// shell\ext\webcheck\test\dhcmpmrg\dhcmpmrg.cpp
#define DIM(x)              (sizeof(x) / sizeof(x[0]))

// shell\ext\webcheck\test\ripsubs\ripsubs.cpp
#define DIM(x)              (sizeof(x) / sizeof(x[0]))

// shell\ext\webcheck\test\upnow\upnow.cpp
#define DIM(x)              (sizeof(x) / sizeof(x[0]))

// shell\ext\webvw\util.h
#define MAKE_CONST_BSTR(name, str) \
    STATIC_BSTR<sizeof(str)/sizeof(WCHAR)> \
                       name = { sizeof(str) - sizeof(WCHAR), str }
#define DECL_CONST_BSTR(name, str) \
    extern STATIC_BSTR<sizeof(str)/sizeof(WCHAR)> name;

// shell\inc\cfdefs.h
#define CF_TABLE_ENTRY(p1, p2, p3) { (void *)&c_CFVtbl, p1, p2, p3 }
#define CF_TABLE_ENTRY_ALL(p1, p2, p3, p4, p5, p6, p7) { (void *)&c_CFVtbl, p1, p2, p3, p4 , p5, p6, p7}

// shell\inc\evtmon\msoem.h
#define IMaxRg(dcl, type) \
            (sizeof(dcl) / sizeof(type))
#define MsoIMaxRg(rg) \
            (sizeof(rg) / sizeof(rg[0]))

// shell\inc\trayp.h
#define TBC_SYSMENUCOUNT            (WM_USER + 57)

// shell\osshell\accesory\hypertrm\tdll\stdtyp.h
#define DIM(a) (sizeof(a) / sizeof(a[0]))

// shell\osshell\accesory\mspaint\imgsuprt.cpp
        #define DIM( X ) (sizeof(X) / sizeof(X[0]))

// shell\osshell\accesory\mspaint\toolbox.cpp
#define iidmMac ( sizeof (rgidm) / sizeof (rgidm[0]) )

// shell\osshell\accesory\netclip\netclip\util.cpp
#define _countof(array)	(sizeof(array)/sizeof(array[0]))

// shell\osshell\accesory\winchat\wcinit.c
#define cTbButtons sizeof(tbButtons)/sizeof(TBBUTTON)

// shell\osshell\accessib\accwiz\curschme.cpp
#define CCURSORS   (sizeof(g_rgszCursorNames) / sizeof(g_rgszCursorNames[0]))

// shell\osshell\accessib\narrator\narrhook\keys.cpp
#define CKEYS_HOT (sizeof(rgHotKeys)/sizeof(HOTK))

// shell\osshell\accessib\osk\inc\sendkeys.h
#define ARRAY_LEN(Array)			(sizeof(Array) / sizeof(Array[0]))

// shell\osshell\control\console\console.h
#define NELEM(array) (sizeof(array)/sizeof(array[0]))

// shell\osshell\control\joy\joycpl.c
#define cchLENGTH(_sz)       (sizeof(_sz)/sizeof(_sz[0]))

// shell\osshell\control\mmsys\dmproppg.c
#define SUBTYPE_INFO_SIZE (sizeof(SubtypeInfo)/sizeof(SUBTYPE_INFO))

// shell\osshell\control\mmsys\drivers.c
#define cchLENGTH(_sz)  (sizeof(_sz) / sizeof((_sz)[0]))
#define nDriverROOTS ((int)(sizeof(aDriverRoot) / sizeof(aDriverRoot[0])))

// shell\osshell\control\mmsys\legcyinf.c
#define tsizeof(s)  (sizeof(s)/sizeof(TCHAR))

// shell\osshell\control\mmsys\midi.h
 #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))

// shell\osshell\control\mmsys\mmcpl.c
#define GetString(_str,_id,_hi)  LoadString (_hi, _id, _str, sizeof(_str)/sizeof(TCHAR))

// shell\osshell\control\mmsys\mmdevldr.h
#define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))

// shell\osshell\control\mmsys\utils.h
#define GAllocArray(type, cNum)          (type *)GAlloc(sizeof(type) * (cNum))
#define GReAllocArray(type, pb, cNum)    (type *)GReAlloc(pb, sizeof(type) * (cNum))

// shell\osshell\control\scrnsave\flyingobjects\flyingobjects.h
#define DIMA(a) (sizeof(a)/sizeof(a[0]))

// shell\osshell\control\ups\cpl.c
#define NUM_APPLETS (sizeof(applets)/sizeof(applets[0]))

// shell\osshell\cpls\main\main.c
#define NUM_APPLETS (sizeof(Applets) / sizeof(Applets[0]))

// shell\osshell\cpls\main\mousebut.c
#define JACK_NUM_STATES     (sizeof(JackFSA) / sizeof(JACKSTATE))

// shell\osshell\cpls\ports\ports.c
#define SERIAL_PNP_IDS_COUNT (sizeof(m_pszSerialPnPIds) / sizeof(m_pszSerialPnPIds[0]))

// shell\osshell\cpls\powercfg\ups\upsreg.h
#define DIMENSION_OF(array) (sizeof(array)/sizeof(array[0]))

// shell\osshell\ep\idlewild\idlewild\idlewild.c
#define icteMax (sizeof (rgcte) / sizeof (CTE))

// shell\osshell\ep\oldtp\taipei.c
#define MAXCONFUCIUSSAY	(sizeof(confucius_say) / sizeof (char *))
#define MAXBANNERSTRINGS (sizeof(banner_strings) / sizeof (char *))

// shell\osshell\fontfldr\fontext\src\fontview.cpp
#define PAN_COL_COUNT  (sizeof( PanoseColumns ) / sizeof( COLUMN_ENTRY ) )
#define FILE_COL_COUNT  (sizeof( FileColumns ) / sizeof( COLUMN_ENTRY ) )
#define BUTTONCOUNT (sizeof( tbButtons ) / sizeof( TBBUTTON ) )

// shell\osshell\fontfldr\fontview\fontview.c
#define C_POINTS_LIST  (sizeof(apts) / sizeof(apts[0]))

// shell\osshell\security\aclui\chklist.h
#define CLM_GETITEMCOUNT    (WM_USER + 3)   // no parameters

// shell\osshell\security\dssec\schema.cpp
#define ACCESS_LENGTH_0 (sizeof(SI_ACCESS) + MAX_TYPENAME_LENGTH * sizeof(WCHAR))
#define ACCESS_LENGTH_1 (sizeof(SI_ACCESS) + MAX_TYPENAME_LENGTH * sizeof(WCHAR))
#define ACCESS_LENGTH_2 (3 * sizeof(SI_ACCESS) + 3 * MAX_TYPENAME_LENGTH * sizeof(WCHAR))

// shell\osshell\themes\inc\rpcndr.h
#define boolean_array_from_ndr(Source, LowerIndex, UpperIndex, Target) \
    { \
    NDRcopy ( \
        (((char __RPC_FAR *)(Target))+(LowerIndex)), \
        (Source)->Buffer, \
        (unsigned int)((UpperIndex)-(LowerIndex))); \
    *(unsigned long __RPC_FAR *)&(Source)->Buffer += ((UpperIndex)-(LowerIndex)); \
    }
#define small_array_from_ndr(Source, LowerIndex, UpperIndex, Target) \
    { \
    NDRcopy ( \
        (((char __RPC_FAR *)(Target))+(LowerIndex)), \
        (Source)->Buffer, \
        (unsigned int)((UpperIndex)-(LowerIndex))); \
    *(unsigned long __RPC_FAR *)&(Source)->Buffer += ((UpperIndex)-(LowerIndex)); \
    }

// shell\osshell\themes\inc\wininet.h
#define INTERNET_MAX_URL_LENGTH         (INTERNET_MAX_SCHEME_LENGTH \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// shell\osshell\themes\themesw\etcdlg.c
#define MAX_ETC_ITEMS   (sizeof(stkSounds)/sizeof(STR_TO_KEY))

// shell\shdocvw\dochost.cpp
#define CCMD_MAX        (sizeof(s_aicmd)/sizeof(s_aicmd[0]))

// shell\shell32\assocarray.cpp
#define AEINFOPROGID(m, s)  { m, &CLSID_AssocProgidElement, s, AssocElemCreateForClass, NULL}

// shell\shell32\category.h
#define CATEGORY_ENTRY_GUID(guid)  {(const GUID*)&guid, (const SHCOLUMNID*)NULL},
#define CATEGORY_ENTRY_SCIDMAP(scid, guid)  {(const GUID*)&guid, (const SHCOLUMNID*)&scid},

// shell\shell32\finddlg.cpp
    #define SUBDLG_ENTRY(idx, idCheck, dlg)  \
        { _subdlgs[idx].nIDCheck = idCheck; _subdlgs[idx].pDlg = &dlg; }

// shell\shell32\finddlg.h
#define POINTSPERRECT   (sizeof(RECT)/sizeof(POINT))

// shell\shell32\linkwnd.cpp
#define POINTSPERRECT       (sizeof(RECT)/sizeof(POINT))

// shell\shell32\lnkcon.h
#define NELEM(array) (sizeof(array)/sizeof(array[0]))

// shell\shell32\obex.h
#define IHeaderCollection_AddByteArray(This,Id,ulSize,pData)	\
    (This)->lpVtbl -> AddByteArray(This,Id,ulSize,pData)

// shell\shell32\prop.cpp
#define PROPUI_ENTRY_NORES(name, scid)                           {L ## name, &scid, 0, 0, 0},
#define PROPUI_ENTRY(name, scid, idDisplayName, idMnemonicName, idHelp)  {L ## name, &scid, idDisplayName, idMnemonicName, idHelp},

// shell\shell32\prop.h
#define DEFINE_COL_ENTRY(scid, vt, fmt, cChars, shcs, ids) \
    { &scid, vt, fmt, cChars, shcs, ids, 0 }
#define DEFINE_COL_STR_ENTRY(scid, cChars, ids) \
    { &scid, VT_LPWSTR, LVCFMT_LEFT, cChars, SHCOLSTATE_TYPE_STR | SHCOLSTATE_ONBYDEFAULT, ids, 0 }
#define DEFINE_COL_STR_MENU_ENTRY(scid, cChars, ids) \
    { &scid, VT_LPWSTR, LVCFMT_LEFT, cChars, SHCOLSTATE_TYPE_STR, ids, 0 }
#define DEFINE_COL_STR_DLG_ENTRY(scid, cChars, ids) \
    { &scid, VT_LPWSTR, LVCFMT_LEFT, cChars, SHCOLSTATE_TYPE_STR | SHCOLSTATE_SECONDARYUI, ids, 0 }
#define DEFINE_COL_STR_HIDDEN_ENTRY(scid) \
    { &scid, VT_LPWSTR, LVCFMT_LEFT, 20, SHCOLSTATE_TYPE_STR | SHCOLSTATE_HIDDEN, 0, 0 }
#define DEFINE_COL_DATE_ENTRY(scid, ids) \
    { &scid, VT_DATE, LVCFMT_LEFT, 20, SHCOLSTATE_TYPE_DATE | SHCOLSTATE_ONBYDEFAULT, ids, 0 }
#define DEFINE_COL_DATE_HIDDEN_ENTRY(scid) \
    { &scid, VT_DATE, LVCFMT_LEFT, 20, SHCOLSTATE_TYPE_DATE | SHCOLSTATE_HIDDEN, 0, 0 }
#define DEFINE_COL_INT_ENTRY(scid, cChars, ids) \
    { &scid, VT_I4, LVCFMT_LEFT, cChars, SHCOLSTATE_TYPE_INT | SHCOLSTATE_ONBYDEFAULT, ids, 0 }
#define DEFINE_COL_INT_DLG_ENTRY(scid, cChars, ids) \
    { &scid, VT_I4, LVCFMT_LEFT, cChars, SHCOLSTATE_TYPE_INT | SHCOLSTATE_SECONDARYUI, ids, 0 }
#define DEFINE_COL_INT_HIDDEN_ENTRY(scid) \
    { &scid, VT_I4, LVCFMT_LEFT, 5, SHCOLSTATE_TYPE_STR | SHCOLSTATE_HIDDEN, 0, 0 }
#define DEFINE_COL_SIZE_ENTRY(scid, ids) \
    DEFINE_COL_ENTRY(scid, VT_UI8, LVCFMT_RIGHT, 16, SHCOLSTATE_TYPE_INT | SHCOLSTATE_ONBYDEFAULT, ids)

// shell\shlwapi\tpsclass.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define ARRAY_ELEMENTS(array)   (sizeof(array)/sizeof(array[0]))

// shell\themes\inc\utils.h
#define COMBOENTRY(combo, color, size) \
    (combo->sFileNums[size*combo->cColorSchemes + color])

// shell\themes\test\ctlperf\stdafx.h
    #define _countof(array)    (sizeof(array)/sizeof(array[0]))

// shell\themes\test\drawedge\drawedge.c
#define countof(x) (sizeof(x) / sizeof(x[0]))

// termsrv\admtools\appsec\appsec\appsec.cpp
#define MAX_INIT_APPS (sizeof(g_aszInitApps)/sizeof(g_aszInitApps[0]))

// termsrv\admtools\doskbd\options.h
#define  ARG_COUNT   (int)(sizeof(options) / sizeof(OPTION))

// termsrv\admtools\inc\ansiuni.h
#define lengthof(x)    (sizeof(x) / sizeof(TCHAR))

// termsrv\admtools\tscc\snapin\stdafx.h
#define SIZE_OF_BUFFER( x ) sizeof( x ) / sizeof( TCHAR )

// termsrv\admtools\winutils\tsadmin\allsrvpg.cpp
#define NUM_AS_SERVER_COLUMNS sizeof(ServerColumns)/sizeof(ColumnDef)
#define NUM_AS_USER_COLUMNS sizeof(UserColumns)/sizeof(ColumnDef)
#define NUM_AS_WINS_COLUMNS sizeof(WinsColumns)/sizeof(ColumnDef)
#define NUM_AS_PROC_COLUMNS sizeof(ProcColumns)/sizeof(ColumnDef)
#define NUM_AS_LICENSE_COLUMNS sizeof(LicenseColumns)/sizeof(ColumnDef)

// termsrv\admtools\winutils\tsadmin\apppgs.cpp
#define NUM_SERVER_COLUMNS sizeof(ServerColumns)/sizeof(ColumnDef)
#define NUM_USER_COLUMNS sizeof(UserColumns)/sizeof(ColumnDef)
#define NUM_SECURITY_COLUMNS sizeof(SecurityColumns)/sizeof(ColumnDef)

// termsrv\admtools\winutils\tsadmin\domainpg.cpp
#define NUM_DOMAIN_SERVER_COLUMNS sizeof(ServerColumns)/sizeof(ColumnDef)
#define NUM_DOMAIN_USER_COLUMNS sizeof(UserColumns)/sizeof(ColumnDef)
#define NUM_DOMAIN_WINS_COLUMNS sizeof(WinsColumns)/sizeof(ColumnDef)
#define NUM_DOMAIN_PROC_COLUMNS sizeof(ProcColumns)/sizeof(ColumnDef)
#define NUM_DOMAIN_LICENSE_COLUMNS sizeof(LicenseColumns)/sizeof(ColumnDef)

// termsrv\admtools\winutils\tsadmin\servpgs.cpp
#define NUM_USER_COLUMNS sizeof(UserColumns)/sizeof(ColumnDef)
#define NUM_WINS_COLUMNS sizeof(WinsColumns)/sizeof(ColumnDef)
#define NUM_PROC_COLUMNS sizeof(ProcColumns)/sizeof(ColumnDef)
#define NUM_LICENSE_COLUMNS sizeof(LicenseColumns)/sizeof(ColumnDef)
#define NUM_HOTFIX_COLUMNS sizeof(HotfixColumns)/sizeof(ColumnDef)

// termsrv\admtools\winutils\tsadmin\winspgs.cpp
#define NUM_MODULE_COLUMNS sizeof(ModuleColumns)/sizeof(ColumnDef)
#define NUM_PROC_COLUMNS sizeof(ProcColumns)/sizeof(ColumnDef)

// termsrv\clcreator\copyfile.c
#define MAX_DOS_FILENAME_LENGTH (8 * sizeof(TCHAR))
#define MAX_DOS_FILE_EXT_LENGTH (3 * sizeof(TCHAR))

// termsrv\inc\acpudefs.h
#define UPDATECOUNTER(fn)                                       \
            callCount[fn]++;                                    \
                                                                \
            if (endLo < startLo)                                \
            {                                                   \
                timeLo = 0xFFFFFFFF - (startLo - endLo - 1);    \
                endHi--;                                        \
            }                                                   \
            else                                                \
            {                                                   \
                timeLo = endLo - startLo;                       \
            }                                                   \
                                                                \
            timeHi = endHi - startHi;                           \
                                                                \
            cycleCountLo[fn] = (unsigned long)(cycleCountLo[fn] + timeLo);\
                                                                \
            if (cycleCountLo[fn] < timeLo)                      \
            {                                                   \
                timeHi++;                                       \
            }                                                   \
                                                                \
            cycleCountHi[fn] += timeHi;                         \
        }

// termsrv\license\tlserver\include\locks.h
#define ARRAY_COUNT(a) sizeof(a) / sizeof(a[0])

// termsrv\license\tlserver\server\srvdef.h
    #define SAFESTRCPY(dest, source) \
        _tcsncpy(dest, source, min(_tcslen(source), sizeof(dest)/sizeof(TCHAR))); \
        dest[min(_tcslen(source), (sizeof(dest)/sizeof(TCHAR) -1))] = _TEXT('\0');

// termsrv\license\tlserver\tls236\tls236.h
#define SAFESTRCPY(dest, source) \
    {                               \
        _tcsncpy(dest, source, min(_tcslen(source), sizeof(dest)/sizeof(TCHAR))); \
        dest[min(_tcslen(source), (sizeof(dest)/sizeof(TCHAR) - 1))] = _TEXT('\0'); \
    }
#define STRBUFSIZE(x)   (sizeof(x) / sizeof(x[0]))

// termsrv\license\tlserver\upg4to5\upg.h
#define SAFESTRCPY(dest, source) \
    _tcsncpy(dest, source, min(_tcslen(source), sizeof(dest)/sizeof(TCHAR))); \
    dest[min(_tcslen(source), (sizeof(dest)/sizeof(TCHAR) -1))] = _TEXT('\0');

// termsrv\perfts\datats.h
#define MAX_PROCESS_NAME_LENGTH    (MAX_PATH * sizeof(WCHAR))

// termsrv\perfts\perfutil.h
#define MAX_VALUE_NAME_LENGTH 256*sizeof(WCHAR)
#define MAX_VALUE_DATA_LENGTH 256*sizeof(WCHAR)

// termsrv\remdsk\rds\as\cpi32\bcd.cpp
#define EXTRACT_LENGTH(buffer, length)                                       \
        length = *buffer++ & MAX_LENGTH_ORDER;                               \
        if (length == 0)                                                     \
        {                                                                    \
            length = *buffer++ + MAX_LENGTH_ORDER + 1;                       \
        }
#define EXTRACT_LENGTH_LITE(buffer, length)                                  \
        length = *buffer++ & MAX_LENGTH_ORDER_LITE;                          \
        if (length == 0)                                                     \
        {                                                                    \
            length = *buffer++ + MAX_LENGTH_ORDER_LITE + 1;                  \
        }

// termsrv\remdsk\rds\as\cpi32\od2.cpp
#define CONVERT_ARRAY(DESTARRAY, SRCARRAY, DESTTYPE, NUMELEMENTS)     \
{                                                           \
    UINT index;                                           \
    for (index=0 ; index<(NUMELEMENTS) ; index++)           \
    {                                                       \
        (DESTARRAY)[index] = (DESTTYPE)(SRCARRAY)[index];   \
    }                                                       \
}
#define CONVERT_ARRAY_INT16_UA(DESTARRAY, SRCARRAY, DESTTYPE, NUMELEMENTS)   \
{                                                           \
    UINT index;                                           \
    TSHR_INT16 value;                                          \
    for (index=0 ; index<(NUMELEMENTS) ; index++)           \
    {                                                       \
        value = EXTRACT_TSHR_INT16_UA((SRCARRAY)+index);      \
        (DESTARRAY)[index] = (DESTTYPE)value;               \
    }                                                       \
}
#define CONVERT_ARRAY_UINT16_UA(DESTARRAY, SRCARRAY, DESTTYPE, NUMELEMENTS)  \
{                                                                            \
    UINT index;                                                            \
    TSHR_UINT16 value;                                                          \
    for (index=0 ; index<(NUMELEMENTS) ; index++)                            \
    {                                                                        \
        value = EXTRACT_TSHR_UINT16_UA((SRCARRAY)+index);                      \
        (DESTARRAY)[index] = (DESTTYPE)((TSHR_INT16)value);                    \
    }                                                                        \
}
#define COPY_DELTA_ARRAY(srcArray, srcArrayType, deltaArray, numElements)  \
{                                                            \
    UINT index;                                            \
    for (index = 0; index < (numElements); index++)          \
    {                                                        \
        (srcArray)[index] = (srcArrayType)                   \
           ((srcArray)[index] + (deltaArray)[index]);        \
    }                                                        \
}

// termsrv\remdsk\rds\as\cpi32\oe2.cpp
#define CHECK_DELTA_ARRAY(ARRAY1, ARRAY2, NUMELEMENTS, DELTASPOSSIBLE)  \
{                                                                       \
    UINT  index;                                                      \
    int   delta;                                                      \
    (DELTASPOSSIBLE) = TRUE;                                            \
    for (index=0 ; index<(NUMELEMENTS) ; index++)                       \
    {                                                                   \
        delta = (ARRAY1)[index] - (ARRAY2)[index];                      \
        if (delta != (int)(TSHR_INT8)delta)                             \
        {                                                               \
            (DELTASPOSSIBLE) = FALSE;                                   \
            break;                                                      \
        }                                                               \
    }                                                                   \
}
#define COPY_TO_DELTA_ARRAY(DESTARRAY, ARRAY1, ARRAY2, NUMELEMENTS)         \
{                                                                           \
    UINT index;                                                           \
    for (index=0 ; index<(NUMELEMENTS) ; index++)                           \
    {                                                                       \
        (DESTARRAY)[index] = (TSHR_INT8)((ARRAY1)[index] - (ARRAY2)[index]);   \
    }                                                                       \
}
#define CONVERT_ARRAY(DESTARRAY, SRCARRAY, DESTTYPE, NUMELEMENTS)     \
{                                                           \
    UINT index;                                           \
    for (index=0 ; index<(NUMELEMENTS) ; index++)           \
    {                                                       \
        (DESTARRAY)[index] = (DESTTYPE)(SRCARRAY)[index];   \
    }                                                       \
}

// termsrv\remdsk\rds\as\h\ch.h
#define IsCacheEntryInTree(pEntry) \
    (((pEntry)->lHeight != 0xFFFF) && ((pEntry)->rHeight != 0xFFFF))

// termsrv\remdsk\rds\dev\inc16\windows.h
#define EM_GETLINECOUNT         (WM_USER+10)
#define EM_LINELENGTH           (WM_USER+17)
#define LB_GETCOUNT             (WM_USER+12)
#define LB_GETSELCOUNT          (WM_USER+17)
#define LB_SETCOUNT             (WM_USER+40)    // ;Internal NT
#define CB_GETCOUNT             (WM_USER+6)

// termsrv\remdsk\rds\h\standrd.h
    #define CchMax(pcsz)        (sizeof(pcsz) / sizeof((pcsz)[0]))
#define DECLARE_SAFEARRAY_UNK_PROPPUT( Prop, PROP_DISPID ) \
    STDMETHOD(put_##Prop)( SAFEARRAY newVal )  \
    {\
        HRESULT hr = S_OK;\
        if( S_OK == __ATL_PROP_NOTIFY_EVENT_CLASS::FireOnRequestEdit(GetUnknown(), PROP_DISPID) )\
        {\
            lst<IUnknown*>::iterator I = m_ary##Prop.begin();\
            while( I != m_ary##Prop.end() )\
            {\
                (*I)->Release();\
                ++I;\
            }\
            m_ary##Prop.erase(m_ary##Prop.begin(), m_ary##Prop.end());\
            IUnknown** ppUnkArray;\
            SafeArrayAccessData( &newVal, reinterpret_cast<void**>(&ppUnkArray) );\
            for (UINT x = 0; x < newVal.rgsabound->cElements; x++)\
	        {\
                IUnknown* pUnk = ppUnkArray[x];\
                pUnk->AddRef();\
                m_ary##Prop.push_back( pUnk );\
	        }\
            SafeArrayUnaccessData(&newVal);\
            hr = __ATL_PROP_NOTIFY_EVENT_CLASS::FireOnChanged(GetUnknown(), PROP_DISPID);\
        }\
        return hr;                \
    }
#define DECLARE_SAFEARRAY_UNK_PROPGET( Prop ) \
    STDMETHOD(get_##Prop)( SAFEARRAY *pVal )  \
    {\
        if( pVal )\
        {\
            int nItems = m_ary##Prop.size();\
            SAFEARRAYBOUND bounds = { nItems, 0 };\
            pVal = SafeArrayCreate( VT_UNKNOWN, 1, &bounds );\
            IUnknown** ppUnkArray;\
            SafeArrayAccessData( pVal, reinterpret_cast<void**>(&ppUnkArray) );\
            lst<IUnknown*>::iterator I = m_ary##Prop.begin();\
            for( int i = 0; I != m_ary##Prop.end(); ++I, ++i )\
            {\
                ppUnkArray[i] = (*I);\
            }\
            SafeArrayUnaccessData(pVal);\
        }\
        else\
        {\
            return E_POINTER;\
        }\
        return S_OK;\
    }

// termsrv\remdsk\rds\h\stock.h
#define ARRAY_ELEMENTS(rg)                (sizeof(rg) / sizeof((rg)[0]))

// termsrv\remdsk\server\sessmgr\locks.h
#define ARRAY_COUNT(a) sizeof(a) / sizeof(a[0])

// termsrv\reskit\tsreg\tsreg.h
#define DIMOF(Array) (sizeof(Array) / sizeof(Array[0]))

// termsrv\wmi\tscfgwmi\terminal.h
#define SIZE_OF_BUFFER( x ) sizeof( x ) / sizeof( TCHAR )

// termsrv\wmi\tscfgwmi\winstation.h
#define SIZE_OF_BUFFER( x ) sizeof( x ) / sizeof( TCHAR )

// tools\wppconfig\rev1\um-init.tpl
#define WPP_GUID_ELEMENTS(p) \
    p->Data1,                 p->Data2,    p->Data3,\
    p->Data4[0], p->Data4[1], p->Data4[2], p->Data4[3],\
    p->Data4[4], p->Data4[5], p->Data4[6], p->Data4[7]

// tools\x86\perl\lib\core\regcomp.h
#define NODE_STEP_REGNODE	1	/* sizeof(regnode)/sizeof(regnode) */

// windows\advcore\ctf\inc\sapi.h
#define ISpEventSource_GetEvents(This,ulCount,pEventArray,pulFetched)	\
    (This)->lpVtbl -> GetEvents(This,ulCount,pEventArray,pulFetched)
#define ISpEventSink_AddEvents(This,pEventArray,ulCount)	\
    (This)->lpVtbl -> AddEvents(This,pEventArray,ulCount)
#define ISpVoice_GetEvents(This,ulCount,pEventArray,pulFetched)	\
    (This)->lpVtbl -> GetEvents(This,ulCount,pEventArray,pulFetched)
#define ISpPhraseAlt_GetAltInfo(This,ppParent,pulStartElementInParent,pcElementsInParent,pcElementsInAlt)	\
    (This)->lpVtbl -> GetAltInfo(This,ppParent,pulStartElementInParent,pcElementsInParent,pcElementsInAlt)
#define ISpRecoResult_GetAlternates(This,ulStartElement,cElements,ulRequestCount,ppPhrases,pcPhrasesReturned)	\
    (This)->lpVtbl -> GetAlternates(This,ulStartElement,cElements,ulRequestCount,ppPhrases,pcPhrasesReturned)
#define ISpRecoResult_GetAudio(This,ulStartElement,cElements,ppStream)	\
    (This)->lpVtbl -> GetAudio(This,ulStartElement,cElements,ppStream)
#define ISpRecoResult_SpeakAudio(This,ulStartElement,cElements,dwFlags,pulStreamNumber)	\
    (This)->lpVtbl -> SpeakAudio(This,ulStartElement,cElements,dwFlags,pulStreamNumber)
#define ISpRecoContext_GetEvents(This,ulCount,pEventArray,pulFetched)	\
    (This)->lpVtbl -> GetEvents(This,ulCount,pEventArray,pulFetched)

// windows\advcore\ctf\inputdll\inputdlg.h
#define DSWITCH_HOTKEY_SIZE sizeof(g_aDirectSwitchHotKey) / sizeof(HOTKEYINFO)

// windows\advcore\ctf\msctfime\context.h
#define ArrayZeroInit(x) memset(&(x), 0, sizeof(x));

// windows\advcore\ctf\uim\internat.cpp
#define NSYMBOLS ((sizeof(symInatSymbols) / sizeof(INATSYMBOL))-1)

// windows\advcore\ctf\uim\marshal.h
#define CPROXY_PARAM_INTERFACE_ARRAY_IN(p, iid, nCnt)                         \
              {MPARAM_IN_INTERFACE, p, 0, &iid, sizeof(void *), nCnt},
#define CPROXY_PARAM_INTERFACE_ARRAY_OUT(p, iid, nCnt)                        \
              {MPARAM_OUT_INTERFACE, p, 0, &iid, sizeof(void *), nCnt},
#define CPROXY_PARAM_INTERFACE_ARRAY_IN_OUT(p, iid, nCnt)                     \
              {MPARAM_IN_OUT_INTERFACE, p, 0, &iid, sizeof(void *), nCnt},
#define CSTUB_PARAM_INTERFACE_ARRAY_IN(p, iid, cnt)                          \
              {MPARAM_IN_INTERFACE, p, 0, &iid, 0 /*sizeof(void *)*/, cnt},
#define CSTUB_PARAM_INTERFACE_ARRAY_OUT(p, iid, cnt)                         \
              {MPARAM_OUT_INTERFACE, p, 0, &iid, sizeof(void *), cnt},
#define CSTUB_PARAM_CALL(pMsg, hrRet, psb)                                 \
              stub_OutParam(_this, pMsg, pMsg->ulMethodId, ARRAYSIZE(param), param, psb); \
              pMsg->hrRet = hrRet;

// windows\advcore\duser\duexts\duexts.cpp
#define COUNTOF(x) (sizeof(x) / sizeof(x[0]))
#define NELEM(array) (sizeof(array)/sizeof(array[0]))

// windows\advcore\duser\inc\autoutil.h
#define _countof(x) (sizeof(x) / sizeof(x[0]))

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\fdfon.c
#define MAXPMWEIGHT ( sizeof(ausIFIMetrics2WinWeight) / sizeof(ausIFIMetrics2WinWeight[0]) )

// windows\advcore\gdiplus\engine\imaging\api\colorpal.cpp
#define MAKEPALENTRY(r, g, b) MAKEARGB(255, r, g, b)

// windows\advcore\gdiplus\test\samples\shapes\shapes.h
#define numberof(x) (sizeof(x)/sizeof(x[0]))

// windows\advcore\gdiplus\test\simpsons\mdmutils.h
#define INARRAY(x, xmax) 		(((x) >= 0) && ((x) < (xmax)))

// windows\advcore\rcml\rcml\xmlstyle.h
#define NUMELEMENTS(a) (sizeof(a)/sizeof(a[0]))

// windows\advcore\rcml\rcmlex\appsvcs\wbemcli.h
#define IWbemObjectSink_Indicate(This,lObjectCount,apObjArray)	\
    (This)->lpVtbl -> Indicate(This,lObjectCount,apObjArray)

// windows\advcore\rcml\rcmlex\cicero\sphelper.h
#define sp_countof(x) ((sizeof(x) / sizeof(*(x))))

// windows\advcore\rcml\xmllib\xml\tokenizer\encoder\charencoder.cxx
#define LENGTH(x) (sizeof(x)/sizeof(x[0]))

// windows\appcompat\appverifier\precomp.h
#define ARRAY_LENGTH( array )   ( sizeof( array ) / sizeof( array[ 0 ] ) )

// windows\appcompat\shims\general\recopyexefromcd.cpp
#define N_RECOPY_EXE    (sizeof(g_rgszExes) / sizeof(g_rgszExes[0]))

// windows\appcompat\shims\layer\ignoreexception.cpp
#define ELISTSIZE sizeof(g_eList) / sizeof(g_eList[0])

// windows\appcompat\shims\lua\trackfs.cpp
#define APPPATCH_DIR_LEN (sizeof(APPPATCH_DIR) / sizeof(WCHAR) - 1)

// windows\appcompat\shims\lua\utils.cpp
#define CLASSES_HIVE_SUFFIX_LEN (sizeof(CLASSES_HIVE_SUFFIX) / sizeof(WCHAR) - 1)
#define USER_HIVE_NAME_LEN (sizeof(USER_HIVE_NAME) / sizeof(WCHAR) - 1)
#define USER_CLASSES_HIVE_NAME_LEN (sizeof(USER_CLASSES_HIVE_NAME) / sizeof(WCHAR) - 1)

// windows\appcompat\shims\lua\utils.h
#define FILE_NAME_PREFIX_LEN (sizeof(FILE_NAME_PREFIX) / sizeof(WCHAR) - 1)
#define LUA_REG_REDIRECT_KEY_LEN (sizeof("Software\\Redirected") / sizeof(CHAR) - 1)
#define LUA_SOFTWARE_CLASSES_LEN (sizeof("Software\\Classes") / sizeof(CHAR) - 1)

// windows\appcompat\slayerui\whistler\shellextensions.cpp
#define NUM_LAYERS (sizeof(g_LayerInfo)/sizeof(g_LayerInfo[0]))

// windows\core\dxkernel\dxg\d3d.cxx
#define INIT_D3DSURFACE(SurfaceArray, Count) \
    for (int i = 0 ; i < (Count) ; i++) { \
        (SurfaceArray)[i].peSurf = NULL; \
    }

// windows\core\ntcon\inc\conmsg.h
#define MAX_TITLE_LENGTH ((MAX_PATH+1)*sizeof(WCHAR))

// windows\core\ntcon\inc\foncache.h
#define BITMAP_ARRAY_BYTE  3                         // BYTE array is 8 bit  (shift count = 3)

// windows\core\ntcon\server\cmdline.c
#define CHAR_COUNT(cch) ((cch)/sizeof(WCHAR))

// windows\core\ntcon\server\consrv.h
#define NELEM(array) (sizeof(array)/sizeof(array[0]))

// windows\core\ntcon\server\srvinit.c
#define SYSTEM_ROOT_LENGTH  (sizeof(SYSTEM_ROOT) - sizeof(WCHAR))

// windows\core\ntgdi\client\glsup.c
#define GL_MF_CALLBACKS (sizeof(GLMFCALLBACKS)/sizeof(PROC))
#define GL_MF_ENTRYPOINTS (sizeof(pszGlmfEntryPoints)/sizeof(char *))

// windows\core\ntgdi\fondrv\tt\ttfd\fdfon.c
#define MAXPMWEIGHT ( sizeof(ausIFIMetrics2WinWeight) / sizeof(ausIFIMetrics2WinWeight[0]) )

// windows\core\ntgdi\fondrv\tt\ttfd\vertical.c
#define NUM_VERTICAL_UNICODES  (sizeof(VerticalUnicodes)/sizeof(VerticalUnicodes[0]))

// windows\core\ntgdi\gre\fntcache.cxx
#define BUFF_LENGTH  (sizeof(KEY_VALUE_PARTIAL_INFORMATION) + EXTRA_BUFFER)

// windows\core\ntgdi\gre\hmgr.h
#define PENTRY_FROM_POBJ(pObj)                                          \
    (&gpentHmgr[(UINT)HmgIfromH(((POBJ)(pObj))->hHmgr)])

// windows\core\ntgdi\gre\surfobj.hxx
#define lengthof(array) ((sizeof(array)) / (sizeof(array[0])))

// windows\core\ntgdi\halftone\ht\htmapclr.h
#define HT_RGB_CUBE_COUNT       CUBE_ENTRIES(HT_RGB_MAX_COUNT)
#define VGA256_PALETTE_COUNT    (VGA256_CUBE_SIZE + VGA256_MONO_SIZE)

// windows\core\ntgdi\inc\ht.h
#define COUNT_ARRAY(array)  (sizeof(array) / sizeof(array[0]))

// windows\core\ntgdi\kdexts2\precomp.hxx
#define lengthof(a)  (sizeof(a)/sizeof(a[0]))

// windows\core\ntgdi\kdexts2\verifier.cxx
#define NUM_VER_FUNCS   (sizeof(gpszVerifierFuncs)/sizeof(gpszVerifierFuncs[0]))

// windows\core\ntgdi\test\imgtest\disp.h
#define NUM_TESTS sizeof(gTestEntry)/sizeof(TEST_ENTRY)

// windows\core\ntuser\client\lboxctl3.c
#define AWCHLEN(a) ((sizeof(a)/sizeof(a[0])) - 1)

// windows\core\ntuser\client\usercli.h
#define CalcUnicodeStringLengthW(_unicodestring,_ansiLength,_unicodeLength)                     \
        /*                                                                                      \
         * Get UnicodeLength from UnicodeString,AnsiLength                                      \
         */                                                                                     \
        {                                                                                       \
            LPWSTR _string = (_unicodestring);                                                  \
            LONG   _length = (LONG)(_ansiLength);                                               \
            LONG   _charlength;                                                                 \
            (*(_unicodeLength)) = 0;                                                            \
            while(*_string && (_length > 0)) {                                                  \
                CalcAnsiStringLengthW(_string,1,&_charlength);                                  \
                _length -= _charlength;                                                         \
                if(_length >= 0) {                                                              \
                    (*(_unicodeLength))++;                                                      \
                }                                                                               \
                _string++;                                                                      \
            }                                                                                   \
        }

// windows\core\ntuser\kdexts\userexts.c
#define FOREACHHANDLEENTRY(phe, i)                                   \
    {                                                                \
        ULONG64 pshi, psi, cHandleEntries;                           \
        ULONG dwHESize = GetTypeSize(SYM(HANDLEENTRY));              \
                                                                     \
        GETSHAREDINFO(pshi);                                         \
        if (GetFieldValue(pshi, SYM(SHAREDINFO), "psi", psi)) {      \
            Print("FOREACHHANDLEENTRY:Could not get SERVERINFO from SHAREDINFO %p\n", pshi); \
        }                                                            \
        GetFieldValue(pshi, SYM(SHAREDINFO), "aheList", phe);        \
        GetFieldValue(psi, SYM(SERVERINFO), "cHandleEntries", cHandleEntries); \
        for (i = 0; cHandleEntries; cHandleEntries--, i++, phe += dwHESize) {  \
            if (IsCtrlCHit()) {                                      \
                break;                                               \
            }

// windows\core\ntuser\kernel\userk.h
#define NEXTPOINTCOUNT(c)           \
    {                               \
        if (c < MAX_MOUSEPOINTS)    \
            c++;                    \
    }
#define N_ELEM(a)     (sizeof(a)/sizeof(a[0]))

// windows\core\ntuser\tools\perf\userdata.h
#define NUM_USER_COUNTERS    (sizeof(USER_DATA_DEFINITION)-sizeof(PERF_OBJECT_TYPE))/sizeof(PERF_COUNTER_DEFINITION)
#define NUM_CS_COUNTERS    (sizeof(CS_DATA_DEFINITION)-sizeof(PERF_OBJECT_TYPE))/sizeof(PERF_COUNTER_DEFINITION)

// windows\feime\chs\ntgen\conv.h
#define ID_LENGTH	sizeof(MAINID)

// windows\feime\kor\ime2k\fecommon\common\cfont.cpp
#define ArrayCount(a)	sizeof(a)/sizeof(a[0])

// windows\feime\kor\ime2k\fecommon\imembx\cfont.cpp
#define ArrayCount(a)    sizeof(a)/sizeof(a[0])

// windows\feime\kor\ime2k\fecommon\imembx\cmnhdr.h
#define ArrayCount(a)	((sizeof(a))/(sizeof((a)[0])))

// windows\feime\kor\ime2k\fecommon\lib\ddbtn\testmain.cpp
#define ArrayCount(a)	(sizeof(a)/sizeof(a[0]))

// windows\feime\kor\ime2k\fecommon\lib\exbtn\testmain.cpp
#define ArrayCount(a)	(sizeof(a)/sizeof(a[0]))

// windows\feime\kor\ime2k\fecommon\lib\plv\plv_.h
#define ArrayCount(a)		(sizeof(a)/sizeof(a[0]))

// windows\feime\kor\ime2k\tip\tipcand.cpp
#define irgCandKeyDefMax    (sizeof(rgCandKeyDef) / sizeof(rgCandKeyDef[0]))

// windows\feime\kor\imeui.c
    #define NUM_MAPS (sizeof(ColorMap)/sizeof(COLORMAP))

// windows\richedit\inci\lscfmtfl.h
#define TurnOnNonRealDnodeEncounted(plsc) \
		(plsc)->plslineCur->fNonRealDnodeEncounted = fTrue;
#define TurnOffNonRealDnodeEncounted(plsc) \
		(plsc)->plslineCur->fNonRealDnodeEncounted = fFalse;
#define FNonRealDnodeEncounted(plsc) \
		(plsc)->plslineCur->fNonRealDnodeEncounted
#define TurnOnNonZeroDvpPosEncounted(plsc) \
		(plsc)->plslineCur->fNonZeroDvpPosEncounted = fTrue;
#define TurnOffNonZeroDvpPosEncounted(plsc) \
		(plsc)->plslineCur->fNonZeroDvpPosEncounted = fFalse;
#define FNonZeroDvpPosEncounted(plsc) \
		(plsc)->plslineCur->fNonZeroDvpPosEncounted
#define TurnOnNominalToIdealEncounted(plsc) \
		(plsc)->lsadjustcontext.fNominalToIdealEncounted = fTrue;
#define TurnOffNominalToIdealEncounted(plsc) \
		(plsc)->lsadjustcontext.fNominalToIdealEncounted = fFalse;
#define FNominalToIdealEncounted(plsc) \
		(plsc)->lsadjustcontext.fNominalToIdealEncounted
#define TurnOnForeignObjectEncounted(plsc) \
		(plsc)->lsadjustcontext.fForeignObjectEncounted = fTrue;
#define TurnOffForeignObjectEncounted(plsc) \
		(plsc)->lsadjustcontext.fForeignObjectEncounted = fFalse;
#define FForeignObjectEncounted(plsc) \
		(plsc)->lsadjustcontext.fForeignObjectEncounted
#define TurnOnTabEncounted(plsc) \
		(plsc)->lsadjustcontext.fTabEncounted = fTrue;
#define TurnOffTabEncounted(plsc) \
		(plsc)->lsadjustcontext.fTabEncounted = fFalse;
#define FTabEncounted(plsc) \
		(plsc)->lsadjustcontext.fTabEncounted
#define TurnOnNonLeftTabEncounted(plsc) \
		(plsc)->lsadjustcontext.fNonLeftTabEncounted = fTrue;
#define TurnOffNonLeftTabEncounted(plsc) \
		(plsc)->lsadjustcontext.fNonLeftTabEncounted = fFalse;
#define FNonLeftTabEncounted(plsc) \
		(plsc)->lsadjustcontext.fNonLeftTabEncounted
#define TurnOnSubmittedSublineEncounted(plsc) \
		(plsc)->lsadjustcontext.fSubmittedSublineEncounted = fTrue;
#define TurnOffSubmittedSublineEncounted(plsc) \
		(plsc)->lsadjustcontext.fSubmittedSublineEncounted = fFalse;
#define FSubmittedSublineEncounted(plsc) \
		(plsc)->lsadjustcontext.fSubmittedSublineEncounted

// windows\richedit\lssrc\lscrline.c
#define LimRg(rg)	(sizeof(rg)/sizeof((rg)[0]))

// windows\richedit\lssrc\lsfetch.c
#define LimRg(rg)	(sizeof(rg)/sizeof((rg)[0]))

// windows\richedit\re30\cfpf.cpp
#define PWD_FONTSIZEMAXFIXUPS   (sizeof(fsFixups)/sizeof(fsFixups[0]))

// windows\richedit\re41\_cfpf.h
#define CELL_EXTRA	(sizeof(CELLPARMS)/sizeof(LONG) - 1)

// windows\richedit\re41\cfpf.cpp
#define PWD_FONTSIZEMAXFIXUPS   (sizeof(fsFixups)/sizeof(fsFixups[0]))

// windows\richedit\re41\ctffunc.h
#define IEnumTfLatticeElements_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumTfLatticeElements_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumTfLatticeElements_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumTfLatticeElements_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)
#define IEnumTfLatticeElements_Next(This,ulCount,rgsElements,pcFetched)	\
    (This)->lpVtbl -> Next(This,ulCount,rgsElements,pcFetched)
#define IEnumTfLatticeElements_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumTfLatticeElements_Skip(This,ulCount)	\
    (This)->lpVtbl -> Skip(This,ulCount)
#define ITfLMLattice_EnumLatticeElements(This,dwFrameStart,rguidType,ppEnum)	\
    (This)->lpVtbl -> EnumLatticeElements(This,dwFrameStart,rguidType,ppEnum)

// windows\winstate\cobra\inc\ism.h
#define IsmCopyEnvironmentString(p,g,n,v) IsmGetEnvironmentString(p,g,n,v,sizeof(v)/sizeof((v)[0]),NULL)

// windows\winstate\v1\imported\net\rras\ras\inc\rasman.h
#define MAX_PHONEENTRY_SIZE         (MAX_PHONENUMBER_SIZE < MAX_ENTRYNAME_SIZE \
                                    ? MAX_ENTRYNAME_SIZE                       \
                                    : MAX_PHONENUMBER_SIZE)

// windows\winstate\v1\imported\net\rras\ras\ui\inc\list.h
#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }
#define PopEntryList(ListHead) \
    (ListHead)->Next;\
    {\
        PSINGLE_LIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Next;\
        if (FirstEntry != NULL) {     \
            (ListHead)->Next = FirstEntry->Next;\
        }                             \
    }
#define PushEntryList(ListHead,Entry) \
    (Entry)->Next = (ListHead)->Next; \
    (ListHead)->Next = (Entry)
```

