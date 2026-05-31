# Range, Bounds, And Predicate Helpers

[Macros index](<macros.md>)

## Curated Candidates

```c
// shell\themes\uxtheme\rgn.cpp
#define _ABS( val1, val2 )   ((val1)>(val2) ? (val1)-(val2) : (val2)-(val1))

// printscan\wia\common\jpeglib\jdcolor.cpp
#define clip(x)         (((long)(x) & ~0xff) ? (((long)(x) < 0) ? 0 : 255) : (long)(x))

// shell\osshell\themes\themesw\loadimag.c
#define DIVIDE_SAFE(nNumber)            ((0 == (nNumber)) ? 1 : (nNumber))

// net\atm\arp\atmarpc\qos.c
		#define EXCEEDSMAX(_value,_max) \
					((_value) != QOS_NOT_SPECIFIED && (_value) > (_max))

// drivers\tpg\hwx\bear\inc\mlp.h
 #define FINT_C_LD(x) (((x) > -MLP_MAX_INT_C && (x) < MLP_MAX_INT_C) ? (fint_c)(x) : (((x) > 0) ? MLP_MAX_INT_C : -MLP_MAX_INT_C))

// drivers\wdm\input\hidparse\hidparse.h
#define HIDP_HASNULL(x)    ((BOOLEAN) ((  (x) & 0x40)  ? TRUE : FALSE))

// net\qos\tools\qtcp\qtcp.c
#define InRange(val, low, high) ((val >= low) && (val < high)) ? TRUE:FALSE

// shell\inc\ccstock.h
#define InRange(id, idFirst, idLast)      ((UINT)((id)-(idFirst)) <= (UINT)((idLast)-(idFirst)))

// net\winnet\mpransi.cxx
#define IS_DWORD_ALIGNED(x)     (((ULONG_PTR)(x) & (sizeof(DWORD) - 1)) == 0)

// inetsrv\iis\iisrearc\ulrtl\parsep.h
#define IS_UTF8_TRAILBYTE(ch)      (((ch) & 0xc0) == 0x80)

// inetcore\wininet\urlcache\cachedef.h
#define ISPOWEROF2(val) (!((val) & ((val)-1)))

// inetcore\mshtml\src\core\include\cdutil.hxx
#define POSITIVE_MOD(lValue, lDiv) ((lValue >= 0) ? (lValue % lDiv) : (lDiv - (-lValue) % lDiv))

// shell\osshell\control\scrnsave\marquee\ssmarque.c
#define RAND(x)   ((rand() % ((x == 0) ? 1 : x)) + 1)
#define ZRAND(x)  (rand() % ((x == 0) ? 1 : x))

// printscan\faxsrv\src\provider\t30\main\pssframe.c
#define GET_BOUNDED_ARRAY_ELEMENT(_array_, _val_, _maxval_, _default_)  \
    (((_val_)>=0 && (_val_)<(_maxval_)) ? _array_[(_val_)] : (_default_))

// inetcore\wininet\inc\icsocket.hxx
#define IS_VALID_NON_LOOPBACK_IP_ADDRESS(address) \
    (((address) != HOST_INADDR_ANY) \
    && ((address) != HOST_INADDR_NONE) \
    && ((address) != HOST_INADDR_LOOPBACK))

// ds\security\protocols\kerberos\client2\userapi.h
#define KERB_IS_DES_ENCRYPTION(_x_) ((((_x_) >= KERB_ETYPE_DES_CBC_CRC) && \
                                      ((_x_) <= KERB_ETYPE_DES_CBC_MD5)) || \
                                     ((_x_) == KERB_ETYPE_DES_PLAIN))

// ds\adsi\include\formcnst.hxx
#define ISBOOL(_x_)         ((_x_) == TRUE || (_x_) == FALSE)

// printscan\faxsrv\src\provider\t30\main\t30util.c
#define BAD_HANDLE(h)       (!(h) || (h)==INVALID_HANDLE_VALUE)

// multimedia\opengl\toolkits\libmtk\mtk.h
#define SS_ROUND_UP( fval ) \
    ( (((fval) - (FLOAT)(int)(fval)) > 0.0f) ? (int) ((fval)+1.0f) : (int) (fval) )

#define SS_CLAMP_TO_RANGE( a, lo, hi ) ( (a < lo) ? lo : ((a > hi) ? hi : a) )

#define SS_CLAMP_TO_RANGE2( a, lo, hi ) \
    ( a = (a < lo) ? lo : ((a > hi) ? hi : a) )

// multimedia\directx\dsound\dsound\misc.h
#define BETWEEN(value, minimum, maximum) \
            min(maximum, max(minimum, value))

// base\ntos\se\sep.h
#define IsValidElementCount( Count, STRUCTURE ) \
    ( Count < ( (ULONG_PTR) ( (PUCHAR) ( (PUCHAR) (LONG_PTR)(LONG)0xFFFFFFFF - (PUCHAR) MM_SYSTEM_RANGE_START ) + 1 ) \
        / sizeof( STRUCTURE ) ) )

// base\ntdll\sxsctxsrch.c
#define ARRAY_FITS(_base, _count, _elemtype, _limit) ((((ULONG) (_base)) < (_limit)) && ((((ULONG) ((_base) + ((_count) * (sizeof(_elemtype)))))) <= (_limit)))

// base\subsys\posix\inc\psxsrv.h
#define ISPOINTERVALID_CLIENT(pprocess, p, length)		\
    (((ULONG_PTR)(p) >= (ULONG_PTR)(pprocess)->ClientViewBase) &&	\
    ((char *)(p) + (length)) < (pprocess)->ClientViewBounds)
```

## Backlog

```c
// admin\activec\conui\helparr.h
#define ON_MMC_CONTEXT_HELP()                                                   \
        ON_MESSAGE(WM_HELP,          OnWmHelp)                                  \
        ON_MESSAGE(WM_CONTEXTMENU,   OnWmContextMenu)                           \

// admin\activec\conui\scriptevents.h
#define  DISPATCH_CALL_MAP_BEGIN(_dispinterface)        \
    template<> class CEventProxy<_dispinterface> : public CEventDispatcher<_##_dispinterface> {
#define ScHasSinks(_p_com_object, _dispinterface)                                    \
    ((_p_com_object) == NULL) ? SC(S_FALSE) : \
                                CScriptEvent<_dispinterface>(_p_com_object).ScHaveSinksRegistered();

// admin\activec\conui\stdafx.h
#define ON_WM_SETTEXT() \
    { WM_SETTEXT, 0, 0, 0, AfxSig_vs, \
        (AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(LPTSTR))&OnSetText },

// admin\activec\core\stgio.cpp
#define DefineScalarVectorStreamFunctions(scalar_type)                  \
    void extract_vector (IStream* pstm, std::vector<scalar_type>& v)    \
        { ReadScalarVector (pstm, v); }                                 \
    void insert_collection (IStream* pstm, const std::vector<scalar_type>& v)\
        { WriteScalarVector (pstm, v); }

// admin\activec\core\zlib.h
#define deflateInit(strm, level) \
        deflateInit_((strm), (level),       ZLIB_VERSION, sizeof(z_stream))
#define inflateInit(strm) \
        inflateInit_((strm),                ZLIB_VERSION, sizeof(z_stream))

// admin\activec\designer\vb98ctls\include\autoobj.h
#define PPTYPEINFOOFOBJECT(index)      &((((AUTOMATIONOBJECTINFO *)(g_ObjectInfo[(index)]).pInfo)->pTypeInfo))
#define DECLARE_STANDARD_SUPPORTERRORINFO() \
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) { \
        return CAutomationObject::InterfaceSupportsErrorInfo(riid); \
    } \

// admin\activec\designer\vb98ctls\include\csf.h
#define EVENT_URL_PARAM_NAME_LEN                 sizeof(EVENT_URL_PARAM_NAME)
#define EVENT_URL_PARAM_NAME_WIDE_LEN            sizeof(EVENT_URL_PARAM_NAME_WIDE)
#define EVENT_INTERNAL_URL_PARAM_NAME_LEN        sizeof(EVENT_INTERNAL_URL_PARAM_NAME)
#define EVENT_INTERNAL_URL_PARAM_NAME_WIDE_LEN   sizeof(EVENT_INTERNAL_URL_PARAM_NAME_WIDE)
#define ASP_EXT_LEN		sizeof(ASP_EXT)
#define ASP_EXT_WIDE_LEN    sizeof(ASP_EXT_WIDE_LEN)
#define URL_DATA_PARAM_NAME_LEN 	sizeof("WCU") - 1

// admin\activec\designer\vb98ctls\include\depfile.inc
#define INTERNET_VB5(a) \
	CABFileName=a ## .cab					      {NEWL} \
	CABDefaultURL=http:{DOUBLESLASH}activex.microsoft.com/controls/vb5  {NEWL} \
	CABINFFile=a ## .inf
#define INTERNET(a) \
	CABFileName=a ## .cab					      {NEWL} \
	CABDefaultURL=http:{DOUBLESLASH}activex.microsoft.com/controls/vb6  {NEWL} \
	CABINFFile=a ## .inf

// admin\activec\designer\vb98ctls\include\ipserver.h
#define DO_GUIDS_MATCH(riid1, riid2) ((riid1.Data1 == riid2.Data1) && (riid1 == riid2))
#define QI_INHERITS(pObj, itf)              \
    case Data1_##itf:                       \
      if(DO_GUIDS_MATCH(riid, IID_##itf))   \
      {                                     \
        itf *pITF = pObj;                   \
        *ppvObjOut = (void *)(itf *)pObj;   \
      }                                     \
      break;

// admin\activec\designer\vb98ctls\include\kxalpha.h
#define START_REGION(Name)              \
        .globl  Name;                   \
Name:;

// admin\activec\designer\vb98ctls\include\localsrv.h
#define UNKNOWNOBJECT(name)    { OI_UNKNOWN,      (void *)&(name##Object) }
#define AUTOMATIONOBJECT(name) { OI_AUTOMATION,   (void *)&(name##Object) }
#define CONTROLOBJECT(name)    { OI_CONTROL,      (void *)&(name##Control) }

// admin\activec\designer\vb98ctls\include\macros.h
#define ADDREF(PUNK) \
  {if (PUNK) (PUNK)->AddRef();}

// admin\activec\designer\vb98ctls\include\wininet.h
#define IS_GOPHER_DIRECTORY(type)       (BOOL)(((type) & GOPHER_TYPE_DIRECTORY) ? TRUE : FALSE)
#define IS_GOPHER_PHONE_SERVER(type)    (BOOL)(((type) & GOPHER_TYPE_CSO) ? TRUE : FALSE)
#define IS_GOPHER_ERROR(type)           (BOOL)(((type) & GOPHER_TYPE_ERROR) ? TRUE : FALSE)
#define IS_GOPHER_INDEX_SERVER(type)    (BOOL)(((type) & GOPHER_TYPE_INDEX_SERVER) ? TRUE : FALSE)
#define IS_GOPHER_TELNET_SESSION(type)  (BOOL)(((type) & GOPHER_TYPE_TELNET) ? TRUE : FALSE)
#define IS_GOPHER_BACKUP_SERVER(type)   (BOOL)(((type) & GOPHER_TYPE_REDUNDANT) ? TRUE : FALSE)
#define IS_GOPHER_TN3270_SESSION(type)  (BOOL)(((type) & GOPHER_TYPE_TN3270) ? TRUE : FALSE)
#define IS_GOPHER_ASK(type)             (BOOL)(((type) & GOPHER_TYPE_ASK) ? TRUE : FALSE)
#define IS_GOPHER_PLUS(type)            (BOOL)(((type) & GOPHER_TYPE_GOPHER_PLUS) ? TRUE : FALSE)
#define IS_GOPHER_TYPE_KNOWN(type)      (BOOL)(((type) & GOPHER_TYPE_UNKNOWN) ? FALSE : TRUE)

// admin\activec\designer\vb98ctls\mmcproxy\proxy.c
#define PULONG_LV_CAST   *(unsigned long __RPC_FAR * __RPC_FAR *)&

// admin\activec\designer\vb98ctls\mssnapr\mssnapr\clipbord.h
#define IsForeign(Type) ( (siSingleForeign     == Type) || \
                          (siMultiMixed        == Type) || \
                          (siMultiForeign      == Type) || \
                          (siMultiMixedForeign == Type) )
#define IsSingle(Type) ( (siSingleForeign   == Type) || \
                         (siSingleScopeItem == Type) || \
                         (siSingleListItem  == Type) )

// admin\activec\designer\vb98ctls\mssnapr\mssnapr\collect.h
#define IS_VALID_INDEX_TYPE(v) ( (VT_UI1  == (v).vt) || \
                                 (VT_I2   == (v).vt) || \
                                 (VT_I4   == (v).vt) || \
                                 (VT_BSTR == (v).vt) )

// admin\activec\designer\vb98ctls\mssnapr\mssnapr\rtconst.h
#define MMCKEY_SNAPINS_LEN          (sizeof(MMCKEY_SNAPINS) - 1)
#define MMCKEY_NODETYPES_LEN        (sizeof(MMCKEY_NODETYPES) - 1)
#define MMCKEY_SNAPIN_NODETYPES_LEN (sizeof(MMCKEY_SNAPIN_NODETYPES) - 1)
#define MMCKEY_EXTENSIONS_LEN       (sizeof(MMCKEY_EXTENSIONS_LEN) - 1)
#define MMCKEY_NAMESPACE_LEN        (sizeof(MMCKEY_NAMESPACE) - 1)
#define MMCKEY_CONTEXTMENU_LEN      (sizeof(MMCKEY_CONTEXTMENU) - 1)
#define MMCKEY_TOOLBAR_LEN          (sizeof(MMCKEY_TOOLBAR) - 1)
#define MMCKEY_PROPERTYSHEET_LEN    (sizeof(MMCKEY_PROPERTYSHEET) - 1)
#define MMCKEY_TASK_LEN             (sizeof(MMCKEY_TASK) - 1)
#define MMCKEY_DYNAMIC_EXTENSIONS_LEN (sizeof(MMCKEY_DYNAMIC_EXTENSIONS) - 1)
#define MMCKEY_S_EXTENSIONS_LEN       (sizeof(MMCKEY_S_EXTENSIONS) - 1)
#define MMCKEY_S_NAMESPACE_LEN        (sizeof(MMCKEY_S_NAMESPACE) - 1)
#define MMCKEY_S_CONTEXTMENU_LEN      (sizeof(MMCKEY_S_CONTEXTMENU) - 1)
#define MMCKEY_S_TOOLBAR_LEN          (sizeof(MMCKEY_S_TOOLBAR) - 1)
#define MMCKEY_S_PROPERTYSHEET_LEN    (sizeof(MMCKEY_S_PROPERTYSHEET) - 1)
#define MMCKEY_S_TASK_LEN             (sizeof(MMCKEY_S_TASK) - 1)
#define MMCKEY_S_DYNAMIC_EXTENSIONS_LEN (sizeof(MMCKEY_S_DYNAMIC_EXTENSIONS) - 1)
#define KEY_SNAPIN_CLSID_LEN        (sizeof(KEY_SNAPIN_CLSID) - 1)

// admin\activec\designer\vb98ctls\mssnapr\mssnapr\siautobj.h
#define ISPRESENT(var) \
    ( !((VT_ERROR == (var).vt) && (DISP_E_PARAMNOTFOUND == (var).scode)) )
#define UNSPECIFIED_PARAM(var) { ::VariantInit(&var); \
                                 var.vt = VT_ERROR; \
                                 var.scode = DISP_E_PARAMNOTFOUND; }

// admin\activec\inc\classreg.h
#define DECLARE_MMC_OBJECT_REGISTRATION(                            \
	szModule,														\
    clsid,                                                          \
    szClassName,                                                    \
    szProgID,                                                       \
    szVersionIndependentProgID)                                     \
static HRESULT WINAPI UpdateRegistry(BOOL bRegister)                \
{                                                                   \
    CObjectRegParams op (											\
		clsid,														\
		szModule,													\
		szClassName,												\
		szProgID,													\
		szVersionIndependentProgID);								\
                                                                    \
    return (MMCUpdateRegistry (bRegister, &op, NULL));              \
}

// admin\activec\inc\comerror.h
#define MMC_METHOD_CALL(_fn)                                        \
    sc = pTiedObj->Sc##_fn

// admin\activec\inc\cpputil.h
#define DECLARE_NOT_COPIABLE(  ClassName)    private: ClassName           (const ClassName&);    // not implemented
#define DECLARE_NOT_ASSIGNABLE(ClassName)    private: ClassName& operator=(const ClassName&);    // not implemented

// admin\activec\inc\eventlock.h
#define LockComEventInterface(_dispinterface) \
    CEventLock<_dispinterface> _LocalEventInterfaceLock;

// admin\activec\inc\mmcdebug.h
#define END_TRACETAG(_class, _Category, _Name)   \
    } _tag##_class(_Category, _Name);

// admin\activec\inc\mmcutil.h
#define MMC_CLSCTX_INPROC (CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER)

// admin\activec\inc\ndmgrpriv.h
#define WINDOW_DATA_SIZE       (sizeof (DataWindowData *))
#define IS_SPECIAL_LVDATA(d) (((d) >= SPECIAL_LVDATA_MIN) && ((d) <= SPECIAL_LVDATA_MAX))

// admin\activec\inc\observer.h
#define FOR_EACH_OBSERVER(ObserverClass, ObserverIter) \
for ( \
    std::list<ObserverClass*>::iterator ObserverIter = EventSourceImpl<ObserverClass>::m_Observers.begin(); \
    ObserverIter != EventSourceImpl<ObserverClass>::m_Observers.end(); \
    ++ObserverIter \
    )

// admin\activec\inc\stgio.inl
#define DeclareScalarVectorStreamFunctions(scalar_type)                        \
    void extract_vector    (IStream* pstm,       std::vector<scalar_type>& v); \
    void insert_collection (IStream* pstm, const std::vector<scalar_type>& v);

// admin\activec\inc\strconv.h
#define WCS2STR(ws) \
	(ws ? (_strconv_length = lstrlenW(ws)+1,\
	wcs2str(reinterpret_cast<char*>(alloca(_strconv_length)),\
	ws, _strconv_length)) : NULL)

// admin\activec\nodemgr\helparr.h
#define CONTEXT_HELP_HANDLER()                                                  \
        MESSAGE_HANDLER   (WM_HELP,         OnWmHelp)                           \
        MESSAGE_HANDLER(WM_CONTEXTMENU,     OnWmContextMenu)                    \

// admin\activec\nodemgr\msgview.h
#define MESSAGE_HANDLER_FUNC(func)  LRESULT (func)(UINT msg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)

// admin\activec\nodemgr\oncmenu.cpp
        #define STYLECHECK(Mode) ((Mode == nViewMode) ? MF_CHECKED|MFT_RADIOCHECK : 0)

// admin\activec\nodemgr\taskui.cpp
#define TVIF_REQUIRED   (TVIF_PARAM | TVIF_HANDLE | TVIF_STATE)

// admin\activec\samples\sdksamples\about\globals.h
	#define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
	#define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\activex\globals.h
        #define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
        #define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\atl_samp\evtvwr\dataobj.h
#define ADD_TYPE(Data, Type, pPos)    *((Type*)pPos) = (Type)(Data); \
	                                    pPos += sizeof(Type)
#define ADD_STRING(str, strLength, pPos)                                         \
	                             strLength = wcslen((LPWSTR)(str)) + 1;            \
	                             ADD_USHORT(strLength, pPos);                      \
	                             wcsncpy((LPWSTR)pPos, (LPWSTR)(str), strLength);  \
	                             pPos += (strLength * sizeof(WCHAR))

// admin\activec\samples\sdksamples\cmenu\globals.h
	#define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
	#define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\cmenuext\globals.h
	#define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
	#define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\complete\globals.h
        #define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
        #define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\cutcopy\globals.h
        #define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
        #define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\extens\globals.h
	#define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
	#define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\help\globals.h
	#define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
	#define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\menubtn\globals.h
	#define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
	#define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\multisel\globals.h
        #define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
        #define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\nameext\globals.h
	#define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
	#define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\nodes\globals.h
	#define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
	#define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\openserv\globals.h
        #define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
        #define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\ppgeext\globals.h
        #define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
        #define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\simple\globals.h
	#define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
	#define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\tbarext\globals.h
	#define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
	#define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\toolbar\globals.h
        #define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
        #define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\samples\sdksamples\wmi\globals.h
        #define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
        #define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\activec\test\snapins\inc\constdecl.hxx
    #define SNAPININFO_DECLARE(_a, _b, _c, _d, _e)    extern CSnapinInfo    _a = CSnapinInfo(_b, &_c, _d, _e);
#define CONST_NODETYPE_DECLARE2(_a, _b)               CONST_SZ_DECLARE2(  szNodeType##_a, _T("{") _T(#_b) _T("-122F-4d2e-8994-8B90F51E4B00}") ) \
                                                      DEFINE_GUID(clsidNodeType##_a, 0x##_b, 0x122f, 0x4d2e, 0x89, 0x94, 0x8b, 0x90, 0xf5, 0x1e, 0x4b, 0x0);  \
                                                      CONST_NODETYPE_DECLARE( nodetype##_a, &clsidNodeType##_a, szNodeType##_a, CONST_SZ_NAME(_a) );

// admin\activec\test\snapins\inc\registrar.hxx
#define DEFINE_COCREATEINSTANCEREF(_a, _b)      \
template CCoCreateInstanceRef<I##_a, &_b, &IID_I##_a>; \
typedef CCoCreateInstanceRef<I##_a, &_b, &IID_I##_a> C##_a;

// admin\activec\test\snapins\inc\targetdll.cxx
#define  DECLARE_SNAPIN(_snapin)                                                                                                                                                                \
template CComponentDataTemplate<_snapin, CComponent, &CLSID_ComponentData_##_snapin>;                                                   \
typedef  CComponentDataTemplate<_snapin, CComponent, &CLSID_ComponentData_##_snapin> t_ComponentData_##_snapin; \
typedef  CSnapinAboutTemplate<_snapin, &CLSID_SnapinAbout_##_snapin> t_SnapinAbout_##_snapin;

// admin\activec\test\snapins\sample\extension.h
#define DECLARE_EXTENSION_REGISTRATION(                           	\
	eType,															\
    clsid,                                                          \
    szClassName,                                                    \
    szProgID,                                                       \
    szVersionIndependentProgID,                                     \
    szExtendedNodeType)                                             \
public: static HRESULT WINAPI UpdateRegistry(BOOL bRegister)        \
{                                                                   \
    return (CExtension::UpdateRegistry (                            \
				bRegister,                                          \
				eType,                                              \
				clsid,                                              \
				OLESTR(szClassName),                                \
				OLESTR(szProgID),                                   \
				OLESTR(szVersionIndependentProgID),                 \
				OLESTR(szExtendedNodeType)));                       \
}

// admin\admt\common\include\tnode.hpp
#define TNodeCompare(name)                                                     \
   int                                    /* ret-0(v1==v2) >0(v1>v2) <0(v1<v2)*/\
      name(                                                                    \
         TNode       const * v1          ,/* in -value1 to compare           */\
         TNode       const * v2           /* in -value2 to compare           */\
      )
#define TNodeCompareValue(name)                                               \
   int                                    /* ret-0(v1==v2) >0(v1>v2) <0(v1<v2)*/\
      name(                                                                   \
         TNode       const * tnode       ,/* in -value1 to compare           */\
         void        const * value        /* in -value2 to compare           */\
      )

// admin\admt\migdrvr\monitor.h
#define DCT_DETAIL_REFRESH (WM_APP+5)
#define DCT_UPDATE_TOTALS  (WM_APP+7)

// admin\admt\profext\tnode.hpp
#define TNodeCompare(name)                                                     \
   int                                    /* ret-0(v1==v2) >0(v1>v2) <0(v1<v2)*/\
      name(                                                                    \
         TNode       const * v1          ,/* in -value1 to compare           */\
         TNode       const * v2           /* in -value2 to compare           */\
      )
#define TNodeCompareValue(name)                                               \
   int                                    /* ret-0(v1==v2) >0(v1>v2) <0(v1<v2)*/\
      name(                                                                   \
         TNode       const * tnode       ,/* in -value1 to compare           */\
         void        const * value        /* in -value2 to compare           */\
      )

// admin\admt\pwdsvc\lsaparammacros.h
#define LsapSetParmTypeString( AuditParameters, Index, String )                \
    {                                                                          \
        (AuditParameters).Parameters[(Index)].Type = SeAdtParmTypeString;      \
        (AuditParameters).Parameters[(Index)].Length =                         \
                sizeof(UNICODE_STRING)+(String)->Length;                       \
        (AuditParameters).Parameters[(Index)].Address = (String);              \
    }
#define LsapSetParmTypeUlong( AuditParameters, Index, Ulong )                  \
    {                                                                          \
        (AuditParameters).Parameters[(Index)].Type = SeAdtParmTypeUlong;       \
        (AuditParameters).Parameters[(Index)].Length =  sizeof( (Ulong) );     \
        (AuditParameters).Parameters[(Index)].Data[0] = (ULONG)(Ulong);        \
    }
#define LsapSetParmTypeHexUlong( AuditParameters, Index, Ulong )                  \
    {                                                                          \
        (AuditParameters).Parameters[(Index)].Type = SeAdtParmTypeHexUlong;       \
        (AuditParameters).Parameters[(Index)].Length =  sizeof( (Ulong) );     \
        (AuditParameters).Parameters[(Index)].Data[0] = (ULONG)(Ulong);        \
    }

// admin\admt\setdtct\tnode.hpp
#define TNodeCompare(name)                                                     \
   int                                    /* ret-0(v1==v2) >0(v1>v2) <0(v1<v2)*/\
      name(                                                                    \
         TNode       const * v1          ,/* in -value1 to compare           */\
         TNode       const * v2           /* in -value2 to compare           */\
      )
#define TNodeCompareValue(name)                                               \
   int                                    /* ret-0(v1==v2) >0(v1>v2) <0(v1<v2)*/\
      name(                                                                   \
         TNode       const * tnode       ,/* in -value1 to compare           */\
         void        const * value        /* in -value2 to compare           */\
      )

// admin\admt\workobj\_entryid.h
#define CBUSR_PERMID sizeof(USR_PERMID)
#define EPHEMERAL   (UCHAR)(~(  MAPI_NOTRECIP      \
                              | MAPI_THISSESSION   \
                              | MAPI_NOW           \
                              | MAPI_NOTRESERVED))

// admin\admt\workobj\dapi.h
#define DAPI_EXPORT_RECIPIENTS       (DAPI_EXPORT_MAILBOX | DAPI_EXPORT_CUSTOM | DAPI_EXPORT_DIST_LIST)

// admin\admt\workobj\edk2.cpp
#define cbStrLenA(sz)   ((lstrlenA((sz)) + 1) * sizeof(CHAR))
#define cbStrLenW(sz)   ((lstrlenW((sz)) + 1) * sizeof(WCHAR))
#define CREATEKEY(hkParent, pszName, hkOut, dwDisposition) \
    RegCreateKeyEx(hkParent, pszName, 0, "", REG_OPTION_NON_VOLATILE, \
	KEY_ALL_ACCESS, NULL, &hkOut, &dwDisposition)
#define SETMULTISZVALUE(hk, pszName, pszValue) \
    RegSetValueEx(hk, pszName, 0, REG_MULTI_SZ, pszValue, \
	CbMultiSz(pszValue)+sizeof(CHAR))

// admin\admt\workobj\wtsinfo.h
#define  FM_WtsUserCitrixOnly ( WtsDeviceClientDrives          | \
                                WtsModemCallbackSettings       | \
                                WtsModemCallbackPhoneNumber )
#define  FM_WtsUserRDP5AndCitrix ( WtsDeviceClientPrinters        | \
                                   WtsDeviceClientDefaultPrinter  | \
                                   WtsShadowingSettings           )

// admin\burnslib\inc\comstuff.hpp
#define QI_PARAMS(Interface, ppvExpression)  \
   IID_##Interface, reinterpret_cast<void**>(static_cast<Interface**>(ppvExpression))

// admin\cmdline\bootini\bootcfg.h
#define ON_OFF								_T("ON|OFF")
#define CMDOPTION_USAGE						_T( "?|h" )
#define BAUD_RATE_VALUES_EMS		  _T("9600|19200|57600|115200")
#define COM_PORT_RANGE			  _T("COM1|COM2|COM3|COM4")
#define EMS_PORT_VALUES			  _T("COM1|COM2|COM3|COM4|BIOSSET")
#define CMDOPTION_EMS_VALUES    _T("ON|OFF|EDIT")
#define CMDOPTION_EMS_VALUES_IA64    _T("ON|OFF")
#define ON_OFF_EDIT _T("ON|OFF|EDIT")

// admin\cmdline\eventcreate\eventcreate.h
#define OPTION_HELP			_T( "?|h" )						// 1

// admin\cmdline\gpresult\gpresult.h
#define TEXT_SCOPE_VALUES       _T( "USER|COMPUTER" )

// admin\cmdline\lib\filterresults.c
#define OPERATOR_DELIMITER		_T( "|" )
#define OPERATOR_EQ			_T( "=| eq " )
#define OPERATOR_NE			_T( "!=| ne " )
#define OPERATOR_GT			_T( ">| gt " )
#define OPERATOR_LT			_T( "<| lt " )
#define OPERATOR_GE			_T( ">=| ge " )
#define OPERATOR_LE			_T( "<=| le " )

// admin\cmdline\power\powercfg.h
#define CMDOPTION_LIST           _T( "l|list" )
#define CMDOPTION_QUERY          _T( "q|query" )
#define CMDOPTION_CREATE         _T( "c|create" )
#define CMDOPTION_SETACTIVE      _T( "s|setactive" )
#define CMDOPTION_CHANGE         _T( "x|change" )
#define CMDOPTION_HIBERNATE      _T( "h|hibernate" )
#define CMDOPTION_EXPORT         _T( "e|export" )
#define CMDOPTION_IMPORT         _T( "i|import" )
#define CMDOPTION_USAGE          _T( "?|help" )
#define CMDOPTION_FILE           _T( "f|file" )

// admin\cmdline\scheduledtasks\scheduledtasks.h
#define CMDOPTION_USAGE						_T( "?|help|h" )
#define CMDOTHEROPTIONS  _T( "s|ru|rp|f|sc|mo|d|m|i|tn|tr|st|sd|ed|fo|v|nh|u|p")

// admin\controls\smonctrl\intrvbar.cpp
#define dwILineClassStyle     (CS_HREDRAW | CS_VREDRAW)
#define dwILineWindowStyle    (WS_CHILD | WS_VISIBLE)
#define PRectDrawable(lpRect)           \
   ((lpRect->right - lpRect->left) >= ILGrabMinimumWidth()) &&  \
    (lpRect->bottom - lpRect->top)
#define RectDrawable(Rect)           \
   ((Rect.right - Rect.left) >= ILGrabMinimumWidth()) &&  \
    (Rect.bottom - Rect.top)
#define dwIntervalBarClassStyle     (CS_HREDRAW | CS_VREDRAW)
#define dwIntervalBarStyle          (WS_CHILD | WS_VISIBLE)

// admin\controls\smonctrl\intrvbar.h
#define ILN_SELCHANGED        (WM_USER + 0x200)

// admin\controls\smonctrl\legend.cpp
#define dwGraphLegendClassStyle     (CS_HREDRAW | CS_VREDRAW)
#define iGraphLegendWindowExtra     (sizeof (PLEGEND))
#define dwGraphLegendWindowStyle    (WS_CHILD | WS_VISIBLE)

// admin\controls\smonctrl\owndraw.h
#define DIIndex(lpDI)               \
   (lpDI->itemID)
#define DIEntire(lpDI)              \
   (lpDI->itemAction & ODA_DRAWENTIRE)
#define DIFocusChanged(lpDI)        \
   (lpDI->itemAction & ODA_FOCUS)
#define DISelectionChanged(lpDI)    \
   (lpDI->itemAction & ODA_SELECT)
#define DISelected(lpDI)            \
   (lpDI->itemState & ODS_SELECTED)
#define DIDisabled(lpDI)            \
   (lpDI->itemState & ODS_DISABLED)
#define DIFocus(lpDI)               \
   (lpDI->itemState & ODS_FOCUS)

// admin\controls\smonctrl\report.cpp
#define dwReportClassStyle     (CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS)
#define iReportWindowExtra     (sizeof (PREPORT))
#define dwReportWindowStyle    (WS_CHILD | WS_HSCROLL | WS_VSCROLL)

// admin\darwin\src\engine\_execute.h
#define MSIXO(op,type,args) iesEnum ixf##op(IMsiRecord& riParams);

// admin\darwin\src\engine\callback.cpp
#define ErrorCase(x,y) \
case x: { \
	g_pFDIs->fdir = y; \
	break; \
}

// admin\darwin\src\engine\imemory.cpp
#define cbMBH	(sizeof(MBH))

// admin\darwin\src\engine\kjalloc.cpp
#define CbEven(cb) ((cb) + 1 & ~1)
#define CbEven(cb) ((cb) + 7 & ~7)

// admin\darwin\src\engine\path.cpp
#define NTSIGNATURE(a) ((void* )((char* )a		     +	\
			((PIMAGE_DOS_HEADER)a)->e_lfanew))

// admin\darwin\src\handler\jpeginc\jinclude.h
#define JFREAD(file,buf,sizeofbuf)  \
  ((size_t) fread((void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))
#define JFWRITE(file,buf,sizeofbuf)  \
  ((size_t) fwrite((const void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))

// admin\darwin\src\handler\jpeginc\jmorecfg.h
#define GETJSAMPLE(value)  ((int) (value) & 0xFF)
#define GETJOCTET(value)  ((value) & 0xFF)

// admin\darwin\src\inc\common.h
#define GetCallingAddr(plAddr, param1) unsigned long *plAddr; \
                                                                plAddr = ((unsigned long *)(&plAddr) + 2);
#define GetCallingAddr2(plAddr, param1) unsigned long *plAddr; \
                                                                plAddr = ((unsigned long *)(&param1) - 1);
#define GetCallingAddr(plAddr, param1) unsigned long *plAddr;  \
                                                                plAddr = (((unsigned long *)(&param1)) - 4);
#define GetCallingAddr2(plAddr, param1) unsigned long *plAddr; \
                                                                plAddr = ((unsigned long *)(&param1) - 1);
#define GetCallingAddr(plAddr, param1) unsigned long plZero = 0; unsigned long *plAddr = &plZero;
#define GetCallingAddr2(plAddr, param1) unsigned long plZero = 0; unsigned long *plAddr = &plZero;
#define MinimumPlatform(fWin9X, minMajor, minMinor) ((g_fWin9X == fWin9X) && ((minMajor < g_iMajorVersion) || ((minMajor == g_iMajorVersion) && (minMinor <= g_iMinorVersion))))
#define MSI_TOKEN_ALL_ACCESS ((g_fWin9X || g_iMajorVersion >= 5) ? TOKEN_ALL_ACCESS : TOKEN_ALL_ACCESS_P)

// admin\darwin\src\inc\latebind.h
#define IMPBIND(l,f,d,a,r,e)   {(void**)&f, (void*)F_##f},
#define IMPFAIL(l,f,d,a,r,e) {(void**)&f, (void*)F_##f},
#define IMPFAIW(l,f,d,a,r,e) {(void**)&f, (void*)F_##f},
#define OPTBIND(l,f,d,a,r)   {(void**)&f, (void*)F_##f},
#define IMPAORW(l,f,d,a,r,e) {(void**)&f, (void*)F_##f},
#define IMPNORW(l,f,d,a,r,e) {(void**)&f, (void*)F_##f},
#define IMPFAOW(l,f,d,a,r,e) {(void**)&f, (void*)F_##f},
#define OPTAORW(l,f,d,a,r)   {(void**)&f, (void*)F_##f},
#define IMPVOID(l,f,d,a)     {(void**)&f, (void*)F_##f},
#define OPTVOID(l,f,d,a)     {(void**)&f, (void*)F_##f},
#define IMPORDI(l,f,d,a,r,e,o) {(void**)&f, (void*)F_##f},
#define IMPORDV(l,f,d,a,o)   {(void**)&f, (void*)F_##f},
#define IMPVOID(l,f,d,a)  void WINAPI l##::F_##f##d {if    (Bind_##l (#f, (FARPROC*)&f))  (*f)a;}
#define OPTVOID(l,f,d,a)  void WINAPI l##::F_##f##d {(*(T_##f)BindOpt_##l (#f,(FARPROC*)&f,(FARPROC)E_##f))a;}
#define IMPORDV(l,f,d,a,o)   void WINAPI l##::F_##f##d {if    (BindFail_##l ((const char*) o, (FARPROC*)&f)) (*f)a;}

// admin\darwin\src\inc\msoalloc.h
#define FORPX(p, pMac, ppl, T) \
		for ((pMac) = ((p) = (T*)((MSOPX*)(ppl))->rg) + ((MSOPX*)(ppl))->iMac; \
			 (p) < (pMac); (p)++)
#define FORPX2(p, pMac, ppl, T) \
		for ((p) = ((pMac) = (T*)((MSOPX*)(ppl))->rg) + ((MSOPX*)(ppl))->iMac - 1; \
			 (p) >= (pMac); (p)--)

// admin\darwin\src\inc\msomem.h
#define cbExtraMkb (sizeof(CHAR *) + sizeof(int))

// admin\darwin\src\inc\msostd.h
#define MSOMACAPIX_(t) t
#define MSOAPIX_(t) MSOEXTERN_C MSOPUBX t MSOAPICALLTYPE
#define MSOSTDAPIX_(t) MSOEXTERN_C MSOPUBX t MSOSTDAPICALLTYPE
#define MSOAPIMX_(t) MSOAPIX_(t)
#define MSOAPIXX_(t) MSOAPI_(t)

// admin\darwin\src\inc\path.h
#define NET_ERROR(i) (i == ERROR_UNEXP_NET_ERR || i == ERROR_BAD_NETPATH || i == ERROR_NETWORK_BUSY || i == ERROR_BAD_NET_NAME || i == ERROR_VC_DISCONNECTED)

// admin\darwin\src\msitools\common\msiice.h
#define CTSS(_A_) { TEXT(_A_), (sizeof(TEXT(_A_))/sizeof(TCHAR))-1 }

// admin\darwin\src\msitools\msiinst\msiinst.cpp
#define CCHSmallBuffer 8 * sizeof(TCHAR)

// admin\darwin\src\msitools\patchwiz\fileptch.cpp
#define iSuppressedErrors   (MSITRANSFORM_ERROR_ADDEXISTINGROW | MSITRANSFORM_ERROR_DELMISSINGROW | MSITRANSFORM_ERROR_UPDATEMISSINGROW | MSITRANSFORM_ERROR_ADDEXISTINGTABLE)

// admin\darwin\src\msitools\patchwiz\patchdll.h
#define FEmptySz(sz) ((BOOL)(((_sz=(sz))==szNull)||(*_sz==TEXT('\0'))))

// admin\dscmd\parser\varg.cpp
#define FILL_ERROR(pError,source,error_code,rec_index,argv_index) \
pError->ErrorSource = source;         \
pError->Error = error_code;           \
pError->ArgRecIndex = rec_index;      \
pError->ArgvIndex = argv_index;

// admin\dscmd\util.cpp
#define A2W_OEM(lpa) (\
	((_lpaMine = lpa) == NULL) ? NULL : (\
		_convert = (lstrlenA(_lpaMine)+1),\
		MyA2WHelper((LPWSTR) alloca(_convert*2), _lpaMine, _convert, CP_OEMCP)))

// admin\dsutils\displayspecifierupgrade\global.cpp
#define H(X) (\
                  (X>='a')?\
                  (\
                     (X-'a'+10)\
                  ):\
                  (\
                     (X>='A')?(X-'A'+10):(X-'0') \
                  )\
             )\

// admin\extens\acldiag\adutils.h
#define IsObjectAceType(Ace) (                                              \
    (((PACE_HEADER)(Ace))->AceType >= ACCESS_MIN_MS_OBJECT_ACE_TYPE) && \
        (((PACE_HEADER)(Ace))->AceType <= ACCESS_MAX_MS_OBJECT_ACE_TYPE)    \
            )

// admin\hmonitor\snapin\connectionmanager.cpp
#define CASE_FACILITY(f)  \
        case f: \
            _tcscpy((LPTSTR)szFacility, (LPTSTR)#f); \
            break;
#define CASE_CODE(c) \
        case c: \
            _tcscpy((LPTSTR)szErrorName, (LPTSTR)#c); \
            FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, hr, \
                MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), \
                szErrorDesc, sizeof(TCHAR)*_ERRORDESCLEN, NULL);\
            break;

// admin\netui\acledit\acledit\permprg.cxx
#define ACCESS_GEN_SEE_USE       (ACCESS_READ|ACCESS_EXEC)
#define ACCESS_GEN_FULL_FILE     (ACCESS_GEN_CHANGES_FILE|ACCESS_PERM)
#define ACCESS_GEN_FULL_DIR      (ACCESS_GEN_CHANGES_DIR|ACCESS_PERM)

// admin\netui\admin\server\server\hwprof.cxx
#define DEVINSTPROP_INITIAL_SIZE (1024*sizeof(TCHAR))

// admin\netui\admin\server\server\srvmain.cxx
#define IS_NT(x) (((x) == ActiveNtServerType) || ((x) == InactiveNtServerType))
#define IS_LM(x) (((x) == ActiveLmServerType) || ((x) == InactiveLmServerType))

// admin\netui\admin\user\user\ctxhlprs.cxx
#define MAX_DOMAINANDNAME     ((DOMAIN_LENGTH+1+USERNAME_LENGTH+1)*sizeof(WCHAR))

// admin\netui\admin\user\user\grpprop.cxx
#define GROUP_DESIRED_ACCESS_ALL ( GROUP_DESIRED_ACCESS_READ | GROUP_DESIRED_ACCESS_WRITE )

// admin\netui\admin\user\user\userprop.cxx
#define USER3_DESIRED_ACCESS_ALL ( USER3_DESIRED_ACCESS_READ | USER3_DESIRED_ACCESS_WRITE )

// admin\netui\common\h\bltfunc.hxx
#define SPECIAL_CHARACTER   TCH('&')

// admin\netui\common\h\bltmsgp.hxx
#define MP_OKCANCEL     ( MP_OK | MP_CANCEL )
#define MP_YESNO        ( MP_YES | MP_NO )
#define MP_YESNOCANCEL  ( MP_YES | MP_NO | MP_CANCEL )
#define HC_NO_HELP          (~0L)

// admin\netui\common\h\domenum.h
#define BROWSE_LOCAL_DOMAINS        ( BROWSE_LM2X_DOMAINS       | \
                                      BROWSE_TRUSTING_DOMAINS )
#define BROWSE_ALL_DOMAINS          ( BROWSE_LOCAL_DOMAINS      | \
                                      BROWSE_WORKGROUP_DOMAINS )
#define BROWSE_RESERVED             ( ~BROWSE_ALL_DOMAINS )

// admin\netui\common\h\heapones.hxx
#define DEFINE_ONE_SHOT_OF(type)                \
ONE_SHOT_HEAP * ONE_SHOT_OF(type)::_poshCurrent = NULL;

// admin\netui\common\h\iter.hxx
#define DECL_ITER_OF(type,dec) \
class dec ITER_OF(type) \
{ \
public: \
    virtual void  Reset( void ) = 0 ; \
    virtual type* Next( void ) = 0 ; \
\
}; \

// admin\netui\common\h\lmoenum.hxx
#define DECLARE_LM_ENUM_ITER_OF( enum_name, type )                            \
                                                                              \
class enum_name##_ENUM_ITER : public LM_ENUM_ITER                             \
{                                                                             \
private:                                                                      \
    enum_name##_ENUM_OBJ _enumobj;                                            \
    type * _p;                                                                \
    UINT _i;                                                                  \
                                                                              \
public:                                                                       \
    enum_name##_ENUM_ITER( enum_name##_ENUM & e );                            \
                                                                              \
    const enum_name##_ENUM_OBJ * operator()( VOID );                          \
    BOOL Backup( VOID );                                                      \
                                                                              \
};  /* class enum_name##_ENUM_ITER */

// admin\netui\common\h\lmuitype.h
#define SELECTOROF(p)   (((PUSHORT)&(p))[1])

// admin\netui\common\h\prefix.hxx
#define	LEN_COMM_PREFIX	    ( sizeof(COMM_PREFIX)  - sizeof(TCHAR) )
#define	LEN_PIPE_PREFIX	    ( sizeof(PIPE_PREFIX)  - sizeof(TCHAR) )
#define	LEN_PRINT_PREFIX    ( sizeof(PRINT_PREFIX) - sizeof(TCHAR) )

// admin\netui\common\h\smx.h
#define SM_GETSERVERSELA                (WM_USER + 1001)
#define SM_GETSERVERSELW                (WM_USER + 1002)
#define SM_GETCURFOCUSA                 (WM_USER + 1003)
#define SM_GETCURFOCUSW                 (WM_USER + 1004)
#define SM_GETOPTIONS                   (WM_USER + 1005)
#define SM_GETSERVERSEL2A               (WM_USER + 1006)
#define SM_GETSERVERSEL2W               (WM_USER + 1007)
#define SM_GETCURFOCUS2A                (WM_USER + 1008)
#define SM_GETCURFOCUS2W                (WM_USER + 1009)

// admin\netui\common\h\string.hxx
#define STACK_NLS_STR( name, len )                      \
    TCHAR _tmp##name[ len+1 ] ;                         \
    ALLOC_STR name( _tmp##name, sizeof(_tmp##name) );
#define ISTACK_NLS_STR( name, len, pszInit )                    \
    TCHAR _tmp##name[ len+1 ] ;                                 \
    ALLOC_STR name( _tmp##name, sizeof(_tmp##name), pszInit );  \
#define CT_NLS_STR( name )                              \
    name( __sz_##name, sizeof( __sz_##name ) )
#define CT_INIT_NLS_STR( name, pszInit )                \
    name( __sz_##name, sizeof( __sz_##name ), pszInit )

// admin\netui\common\h\umx.h
#define UM_GETUSERSELA                  (WM_USER + 1001)
#define UM_GETUSERSELW                  (WM_USER + 1002)
#define UM_GETGROUPSELA                 (WM_USER + 1003)
#define UM_GETGROUPSELW                 (WM_USER + 1004)
#define UM_GETCURFOCUSA                 (WM_USER + 1005)
#define UM_GETCURFOCUSW                 (WM_USER + 1006)
#define UM_GETOPTIONS                   (WM_USER + 1007)
#define UM_GETOPTIONS2                  (WM_USER + 1008)
#define UM_GETCURFOCUS2A                (WM_USER + 1009)
#define UM_GETCURFOCUS2W                (WM_USER + 1010)

// admin\netui\common\h\usrbrows.hxx
        #define USRBROWS_INCL_ALL       (USRBROWS_INCL_REMOTE_USERS|\
                                         USRBROWS_INCL_INTERACTIVE|\
                                         USRBROWS_INCL_EVERYONE|\
                                         USRBROWS_INCL_CREATOR|\
                                         USRBROWS_INCL_SYSTEM|\
					 USRBROWS_INCL_RESTRICTED)

// admin\netui\common\hack\dos\dos.h
#define FP_SEG(fp) (*((unsigned _far *)&(fp)+1))
#define FP_OFF(fp) (*((unsigned _far *)&(fp)))

// admin\netui\common\hack\dos\pwin16.h
#define GET_WM_ACTIVATE_STATE(wp, lp)               (wp)
#define GET_WM_CHARTOITEM_CHAR(wp, lp)              (TCHAR)(wp)
#define GET_WM_COMMAND_ID(wp, lp)                   (wp)
#define GET_WM_MENUSELECT_CMD(wp, lp)               (wp)
#define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)  \
        (WPARAM)(cmd), MAKELONG(f, hmenu)
#define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW) 0, MAKELONG(hmenuF, hmenuW)
#define GET_WM_MENUCHAR_CHAR(wp, lp)                (TCHAR)(wp)
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

// admin\netui\common\hack\dos\windows.h
#define MAKELPARAM(low, high)	((LPARAM)MAKELONG(low, high))
#define GHND		    (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define LHND		    (LMEM_MOVEABLE | LMEM_ZEROINIT)
#define DCB_SET 	(DCB_RESET | DCB_ACCUMULATE)
#define QS_MOUSE	(QS_MOUSEMOVE | QS_MOUSEBUTTON)
#define WVR_REDRAW	    (WVR_HREDRAW | WVR_VREDRAW)
#define DM_GETDEFID	    (WM_USER+0)
#define DM_SETDEFID	    (WM_USER+1)
#define STM_SETICON	    (WM_USER+0)
#define STM_GETICON	    (WM_USER+1)
#define BM_GETCHECK	    (WM_USER+0)
#define BM_SETCHECK	    (WM_USER+1)
#define BM_GETSTATE	    (WM_USER+2)
#define BM_SETSTATE	    (WM_USER+3)
#define BM_SETSTYLE	    (WM_USER+4)
#define EM_GETSEL	        (WM_USER+0)
#define EM_SETSEL	        (WM_USER+1)
#define EM_GETRECT	        (WM_USER+2)
#define EM_SETRECT	        (WM_USER+3)
#define EM_SETRECTNP	        (WM_USER+4)
#define EM_LINESCROLL	        (WM_USER+6)
#define EM_GETMODIFY	        (WM_USER+8)
#define EM_SETMODIFY	        (WM_USER+9)
#define EM_LINEINDEX	        (WM_USER+11)
#define EM_SETHANDLE	        (WM_USER+12)
#define EM_GETHANDLE	        (WM_USER+13)
#define EM_GETTHUMB	        (WM_USER+14)
#define EM_REPLACESEL	        (WM_USER+18)
#define EM_SETFONT	        (WM_USER+19)
#define EM_GETLINE	        (WM_USER+20)
#define EM_LIMITTEXT	        (WM_USER+21)
#define EM_CANUNDO	        (WM_USER+22)
#define EM_UNDO 	        (WM_USER+23)
#define EM_FMTLINES	        (WM_USER+24)
#define EM_LINEFROMCHAR         (WM_USER+25)
#define EM_SETTABSTOPS	        (WM_USER+27)
#define EM_EMPTYUNDOBUFFER      (WM_USER+29)
#define EM_GETFIRSTVISIBLELINE	(WM_USER+30)
#define EM_SETREADONLY	        (WM_USER+31)
#define LBS_STANDARD	      (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)
#define LB_ADDSTRING	       (WM_USER+1)
#define LB_INSERTSTRING        (WM_USER+2)
#define LB_RESETCONTENT        (WM_USER+5)
#define LB_SETSEL	       (WM_USER+6)
#define LB_SETCURSEL	       (WM_USER+7)
#define LB_GETSEL	       (WM_USER+8)
#define LB_GETCURSEL	       (WM_USER+9)
#define LB_GETTEXT	       (WM_USER+10)
#define LB_GETTEXTLEN	       (WM_USER+11)
#define LB_SELECTSTRING        (WM_USER+13)
#define LB_DIR		       (WM_USER+14)
#define LB_GETTOPINDEX	       (WM_USER+15)
#define LB_FINDSTRING	       (WM_USER+16)
#define LB_GETSELITEMS	       (WM_USER+18)
#define LB_SETTABSTOPS         (WM_USER+19)
#define LB_GETHORIZONTALEXTENT (WM_USER+20)
#define LB_SETHORIZONTALEXTENT (WM_USER+21)
#define LB_SETCOLUMNWIDTH      (WM_USER+22)
#define LB_SETTOPINDEX	       (WM_USER+24)
#define LB_GETITEMRECT	       (WM_USER+25)
#define LB_GETITEMDATA         (WM_USER+26)
#define LB_SETITEMDATA         (WM_USER+27)
#define LB_SELITEMRANGE        (WM_USER+28)
#define LB_SETCARETINDEX       (WM_USER+31)
#define LB_GETCARETINDEX       (WM_USER+32)
#define LB_SETITEMHEIGHT       (WM_USER+33)
#define LB_GETITEMHEIGHT       (WM_USER+34)
#define CB_GETEDITSEL	         (WM_USER+0)
#define CB_LIMITTEXT	         (WM_USER+1)
#define CB_SETEDITSEL	         (WM_USER+2)
#define CB_ADDSTRING	         (WM_USER+3)
#define CB_DIR                   (WM_USER+5)
#define CB_GETCURSEL	         (WM_USER+7)
#define CB_GETLBTEXT	         (WM_USER+8)
#define CB_GETLBTEXTLEN	         (WM_USER+9)
#define CB_INSERTSTRING          (WM_USER+10)
#define CB_RESETCONTENT	         (WM_USER+11)
#define CB_FINDSTRING	         (WM_USER+12)
#define CB_SELECTSTRING	         (WM_USER+13)
#define CB_SETCURSEL	         (WM_USER+14)
#define CB_SHOWDROPDOWN          (WM_USER+15)
#define CB_GETITEMDATA           (WM_USER+16)
#define CB_SETITEMDATA           (WM_USER+17)
#define CB_GETDROPPEDCONTROLRECT (WM_USER+18)
#define CB_SETITEMHEIGHT         (WM_USER+19)
#define CB_GETITEMHEIGHT         (WM_USER+20)
#define CB_SETEXTENDEDUI         (WM_USER+21)
#define CB_GETEXTENDEDUI         (WM_USER+22)
#define CB_GETDROPPEDSTATE       (WM_USER+23)

// admin\netui\common\hack\os2def.h
#define SELECTOROF(p)		(((PUSHORT)&(p))[1])
#define MAKETYPE(v, type)	(*((type far *)&v))

// admin\netui\common\src\collect\collect\uatom.cxx
#define HUATOMSIZE     (sizeof (VOID *))

// admin\netui\common\src\lmobj\lmobj\lsaaccnt.cxx
#define STANDARD_PRIVILEGE_SET_SIZE  ( sizeof( PRIVILEGE_SET ) +  \
                                       (DEFAULT_NUM_PRIVILEGE - 1 ) * \
                                       sizeof( LUID_AND_ATTRIBUTES ) )

// admin\netui\common\src\lmobj\lmobj\ossid.cxx
#define STANDARD_SID_SIZE  (sizeof(SID) + 7*sizeof(ULONG))

// admin\netui\common\src\lmobj\lmoenum\domenum.cxx
#define DOES_INCLUDE(a,b)       (NOT_EMPTY((a) & (b)))

// admin\netui\common\src\lmobj\lmoenum\lmoesrv3.cxx
#define IS_WKSTA_TRUST(x)  (((x) & USER_WORKSTATION_TRUST_ACCOUNT) != 0)
#define IS_SERVER_TRUST(x) (((x) & USER_SERVER_TRUST_ACCOUNT) != 0)
#define IS_NT_SERVER(x)    (((x) & SV_TYPE_NT) != 0)
#define IS_WFW_SERVER(x)   (((x) & SV_TYPE_WFW) != 0)
#define IS_LM_SERVER(x)    (((x) & (SV_TYPE_NT | SV_TYPE_WFW)) == 0)
#define IS_WIN95_SERVER(x) (((x) & SV_TYPE_WINDOWS) != 0)

// admin\netui\common\src\lmobj\lmoenum\lmoesvc.cxx
#define SIZEOF_CANNED_NAME_LIST (332 * sizeof(TCHAR))   // must be accurate!!

// admin\netui\common\src\mnet32\mnet32\machinep.h
#define MACHINEID_MS_PCAT     (NT_MICROSOFT|PC_AT_COMPATIBLE)
#define MACHINEID_MS_PC98     (NT_MICROSOFT|PC_9800_COMPATIBLE)
#define MACHINEID_NEC_PC98    (NT_NEC      |PC_9800_COMPATIBLE)
#define MACHINEID_FUJITSU_FMR (NT_FUJITSU  |FMR_COMPATIBLE)

// admin\netui\common\src\mnet32\mnet32\pcanon.cxx
#define IS_LM2X_COMPATIBLE(nametype) ( (nametype==NAMETYPE_SERVICE || nametype==NAMETYPE_MESSAGE) ? 0 : LM2X_COMPATIBLE )

// admin\netui\common\src\profile\profile\general.cxx
#define LEN_szLocalFile (sizeof(::szLocalFile)-1)

// admin\netui\common\src\string\string\format.cxx
#define STACK_FMT_STR( name, len )                      \
    TCHAR _tmp##name[ len+1 ] ;                         \
    SPRINTF_ALLOC_STR name( _tmp##name, sizeof(_tmp##name) );

// admin\netui\liccpa\test\licsetup\ctls.c
#define AIL_BOLDFONT    (sizeof(LONG))
#define AIL_BOLDITEM    (2*sizeof(LONG))
#define AIL_TEXT        (3*sizeof(LONG))

// admin\netui\llsmgr\llsimp.h
#define V_ISVOID(va)                                              \
(                                                                 \
    (V_VT(va) == VT_EMPTY) ||                                     \
    (V_VT(va) == VT_ERROR && V_ERROR(va) == DISP_E_PARAMNOTFOUND) \
)
#define LLS_DESIRED_ACCESS    (STANDARD_RIGHTS_REQUIRED         |\
                               POLICY_VIEW_LOCAL_INFORMATION    |\
                               POLICY_LOOKUP_NAMES )

// admin\netui\llsmgr\llsmgr.h
#define V_ISVOID(va)                                              \
(                                                                 \
    (V_VT(va) == VT_EMPTY) ||                                     \
    (V_VT(va) == VT_ERROR && V_ERROR(va) == DISP_E_PARAMNOTFOUND) \
)
#define LLS_DESIRED_ACCESS    (STANDARD_RIGHTS_REQUIRED         |\
                               POLICY_VIEW_LOCAL_INFORMATION    |\
                               POLICY_LOOKUP_NAMES )

// admin\netui\llsmgr\prdobj.h
#define IsProductAtLimit(prd)       (((prd)->m_lLimit == (prd)->m_lInUse) && (prd)->m_lLimit)

// admin\netui\llsmgr\utils.h
#define UPDATE_INFO_CLIENTS         (UPDATE_INFO_USERS | UPDATE_INFO_GROUPS)
#define UPDATE_MAIN_TABS            (UPDATE_INFO_CLIENTS | UPDATE_INFO_PRODUCTS | UPDATE_INFO_LICENSES)
#define UPDATE_LICENSE_ADDED        (UPDATE_INFO_CLIENTS | UPDATE_INFO_PRODUCTS | UPDATE_INFO_LICENSES)
#define UPDATE_LICENSE_REVOKED      (UPDATE_INFO_CLIENTS | UPDATE_INFO_PRODUCTS)
#define UPDATE_LICENSE_UPGRADED     (UPDATE_INFO_CLIENTS | UPDATE_INFO_PRODUCTS)
#define UPDATE_LICENSE_MODE         (UPDATE_INFO_SERVICES| UPDATE_INFO_PRODUCTS)
#define UPDATE_GROUP_ADDED          (UPDATE_INFO_CLIENTS | UPDATE_INFO_PRODUCTS)
#define UPDATE_GROUP_ALTERED        (UPDATE_INFO_CLIENTS | UPDATE_INFO_PRODUCTS)

// admin\netui\macprint\inc\prtdefs.h
#define	SIZE_FC				sizeof(FILTERCONTROL) - 1
#define	SIZE_FCOLD			sizeof(FILTERCONTROL_OLD) - 1

// admin\netui\macprint\monitor\atalkmon.h
#define	SIZE_PS_HEADER	(sizeof(PS_HEADER) - 1)
#define PJL_ENDING_COMMAND_LEN  (sizeof(PJL_ENDING_COMMAND) - 1)

// admin\netui\macprint\spooler\macps.c
#define	IsRemote(pPrinter)	(((pPrinter)->Attributes & PRINTER_ATTRIBUTE_NETWORK) ? TRUE : FALSE)

// admin\netui\macprint\spooler\macps.h
#define	PushJSState(Job, NewState)	\
		{	\
			Job->SavedJSState = Job->JSState; \
			Job->JSState = NewState;		  \
		}

// admin\netui\nwc\h\nwc.hxx
#define FILE_PERM_GEN_READ		 (GENERIC_READ	  |\
					  GENERIC_EXECUTE)

// admin\netui\shell\h\winlocal.h
#define PROFILE_BUFFER_SIZE     (max( sizeof(PROFILE_YES_STRING), \
                                      sizeof(PROFILE_NO_STRING)) +1)

// admin\netui\shell\shell\wnetconn.cxx
#define IS_NON_DFS_SHARE_ERROR(x)       \
            ((x) == WN_BAD_NETNAME   || \
             (x) == WN_BAD_VALUE     || \
             (x) == WN_BAD_LOCALNAME || \
             (x) == WN_BAD_USER)

// admin\netui\shell\shell\wnres.cxx
#define COPYSTRINGFIELD(field)                  \
    if (field)                                  \
    {                                           \
        pNetResource->field = pNextString;      \
        wcscpy(pNextString, field);             \
        pNextString += wcslen(pNextString) + 1; \
    }                                           \
    else                                        \
    {                                           \
        pNetResource->field = NULL;             \
    }

// admin\netui\shell\test\apptest4.cxx
#define TEST_RESOURCE_PERM12  (TEST_SPECIAL_PERM1|TEST_SPECIAL_PERM2)
#define TEST_RESOURCE_PERM34  (TEST_SPECIAL_PERM3|TEST_SPECIAL_PERM4)
#define TEST_RESOURCE_PERM135 (TEST_SPECIAL_PERM1|TEST_SPECIAL_PERM3|TEST_SPECIAL_PERM5)
#define TEST_NEW_OBJ_SPECIAL_PERM12    (TEST_NEW_OBJ_SPECIAL_PERM1|TEST_NEW_OBJ_SPECIAL_PERM2)
#define TEST_NEW_OBJ_SPECIAL_PERM34    (TEST_NEW_OBJ_SPECIAL_PERM3|TEST_NEW_OBJ_SPECIAL_PERM4)

// admin\netui\shellui\h\shareacl.hxx
#define FILE_PERM_GEN_READ		 (GENERIC_READ	  |\
					  GENERIC_EXECUTE)

// admin\netui\shellui\share\sharestp.hxx
#define STYPE_ALL_SHARE   (STYPE_DISK_SHARE | STYPE_PRINT_SHARE | STYPE_IPC_SHARE)

// admin\pchealth\client\datacoll\wmiprov\drvdefs.h
#define PUN(T, v)       OBJAT(T, &(v))

// admin\pchealth\client\datacoll\wmiprov\pch_systemhook.h
#define cbX(X) sizeof(X)
#define ZeroX(x) ZeroBuf(&(x), cbX(x))

// admin\pchealth\client\datacoll\wmiprov\version.cpp
#define cbX(X) sizeof(X)

// admin\pchealth\client\datacoll\wmiprovn\drvdefs.h
#define PUN(T, v)       OBJAT(T, &(v))

// admin\pchealth\client\datacoll\wmiprovn\version.cpp
#define cbX(X) sizeof(X)

// admin\pchealth\client\faultrep\msodw.h
#define MSODWRECOVERQUIT (msoctdsRecover | msoctdsQuit)
#define MSODWRESTARTQUIT (msoctdsRestart | msoctdsQuit)
#define MSODWRESPONSES (msoctdsQuit | msoctdsRestart | msoctdsRecover)

// admin\pchealth\client\include\ntevents.h
#define Str08x(dw)          (__szLgEvTmp__=(LPWSTR)_alloca(12  * sizeof(WCHAR)), wsprintfW(__szLgEvTmp__, L"0x%08x", dw), __szLgEvTmp__)
#define Str04x(dw)          (__szLgEvTmp__=(LPWSTR)_alloca(12  * sizeof(WCHAR)), wsprintfW(__szLgEvTmp__, L"0x%04x", dw), __szLgEvTmp__)
#define Strx(dw)            (__szLgEvTmp__=(LPWSTR)_alloca(12  * sizeof(WCHAR)), wsprintfW(__szLgEvTmp__, L"0x%x", dw)  , __szLgEvTmp__)
#define Strd(dw)            (__szLgEvTmp__=(LPWSTR)_alloca(12  * sizeof(WCHAR)), wsprintfW(__szLgEvTmp__, L"%d", dw)    , __szLgEvTmp__)
#define StrFromErr(dwErr)   (__szErrStr__ =(LPWSTR)_alloca(256 * sizeof(WCHAR)), FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | 80, NULL, dwErr, MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), __szErrStr__, 256, NULL), __szErrStr__)

// admin\pchealth\client\include\util.h
    #define VALIDATEPARM(hr, expr)                                          \
            hr = ((expr) ? E_INVALIDARG : NOERROR);
    #define VALIDATEEXPR(hr, expr, hrErr)                                   \
            hr = ((expr) ? (hrErr) : NOERROR);

// admin\pchealth\client\lamebtn\simplexml.cpp
#define W2UTF8(lpw) (\
	((_lpw = lpw) == NULL) ? NULL : (\
		_convert = (lstrlenW(_lpw)+1)*2,\
		W2Helper((LPSTR) alloca(_convert), _lpw, _convert, CP_UTF8)))

// admin\pchealth\client\test\faultsvc\faultsvc.cpp
#define sizeofSTRW(wsz) (sizeof((wsz)) / sizeof(WCHAR))

// admin\pchealth\client\test\rexec\srv\faultsvc.cpp
#define sizeofSTRW(wsz) (sizeof((wsz)) / sizeof(WCHAR))

// admin\pchealth\core\include\moscl.h
#define MOSERROR_INVALID_CONNECTION_TYPE    (25)    // InitMOS() & OpenMOSConnection mismatch

// admin\pchealth\core\include\mpc_com.h
#define MPC_SCRIPTHELPER_FAIL_IF_NOT_AN_OBJECT(var)                                                                      \
    if(((var).vt != VT_UNKNOWN  && (var).vt != VT_DISPATCH) ||                                                           \
       ((var).vt == VT_UNKNOWN  && (var).punkVal  == NULL ) ||                                                           \
       ((var).vt == VT_DISPATCH && (var).pdispVal == NULL )  ) __MPC_SET_ERROR_AND_EXIT(hr, E_INVALIDARG)
#define MPC_SCRIPTHELPER_GET__DIRECT(dst,obj,prop)                                                                       \
{                                                                                                                        \
    __MPC_EXIT_IF_METHOD_FAILS(hr, obj->get_##prop( &(dst) ));                                                           \
}
#define MPC_SCRIPTHELPER_GET_OBJECT__VARIANT(dst,obj,prop)                                                               \
{                                                                                                                        \
    CComVariant __v;                                                                                                     \
                                                                                                                         \
    MPC_SCRIPTHELPER_GET__DIRECT(__v,obj,prop);                                                                          \
                                                                                                                         \
    __MPC_EXIT_IF_METHOD_FAILS(hr, MPC::COMUtil::VarToInterface( __v, __uuidof(dst), (IUnknown **)&(dst) ));             \
}
#define MPC_SCRIPTHELPER_GET_STRING__VARIANT(dst,obj,prop)                                                               \
{                                                                                                                        \
    CComVariant __v;                                                                                                     \
                                                                                                                         \
    MPC_SCRIPTHELPER_GET__DIRECT(__v,obj,prop);                                                                          \
                                                                                                                         \
    __MPC_EXIT_IF_METHOD_FAILS(hr, MPC::COMUtil::VarToBSTR( __v, dst ));                                                 \
}
#define MPC_SCRIPTHELPER_GET_PROPERTY(dst,obj,prop)                                                                      \
{                                                                                                                        \
    __MPC_EXIT_IF_METHOD_FAILS(hr, MPC::COMUtil::GetPropertyByName( obj, L#prop, dst ));                                 \
}
#define MPC_SCRIPTHELPER_GET_PROPERTY__BSTR(dst,obj,prop)                                                                \
{                                                                                                                        \
    CComVariant __v;                                                                                                     \
                                                                                                                         \
    MPC_SCRIPTHELPER_GET_PROPERTY(__v,obj,prop);                                                                         \
                                                                                                                         \
    __MPC_EXIT_IF_METHOD_FAILS(hr, MPC::COMUtil::VarToBSTR( __v, dst ));                                                 \
}
#define MPC_SCRIPTHELPER_GET_COLLECTIONITEM(dst,obj,item)                                                                \
{                                                                                                                        \
    CComVariant __v;                                                                                                     \
                                                                                                                         \
    __MPC_EXIT_IF_METHOD_FAILS(hr, obj->get_Item( item, &__v ));                                                         \
                                                                                                                         \
    __MPC_EXIT_IF_METHOD_FAILS(hr, MPC::COMUtil::VarToInterface( __v, __uuidof(dst), (IUnknown **)&(dst) ));             \
    if((dst) == NULL) __MPC_SET_ERROR_AND_EXIT(hr, E_NOINTERFACE);                                                       \
}
#define MPC_SCRIPTHELPER_PUT__DIRECT(obj,prop,val)                                                                       \
{                                                                                                                        \
    __MPC_EXIT_IF_METHOD_FAILS(hr, obj->put_##prop( val ));                                                              \
}

// admin\pchealth\core\include\mpc_main.h
#define STRINGISPRESENT( str ) (str && str[0])

// admin\pchealth\helpctr\service\include\jetbluelib.h
#define __MPC_JET__MTSAFE(sesid,err,x)              \
{                                                   \
    err = ::JetSetSessionContext( sesid, 0xDEAD );  \
                                                    \
    if(err == JET_errSuccess) err = (x);            \
                                                    \
    ::JetResetSessionContext( sesid );              \
}
#define JET_SET_FIELD(rs,field,value) \
    rs->field = value                 \
#define JET_SET_FIELD_TRISTATE(rs,field,validfield,value,isvalid) \
    if(isvalid)                                                   \
    {                                                             \
        rs->field      = value;                                   \
        rs->validfield = true;                                    \
    }                                                             \
    else                                                          \
    {                                                             \
        rs->validfield = false;                                   \
    }

// admin\pchealth\helpctr\service\searchenginelib\wrapper_fts\ftsobj.cpp
#define TOPIC_NUM(exp)  (0x003fffff & exp)

// admin\pchealth\helpctr\shell\binarybehaviors\factories.h
#define INCREASESIZE(x) x.reserve( (x.size() + 4097) & ~4095 )

// admin\pchealth\helpctr\shell\misc\helpcenterexternal_state.cpp
#define CTXFLG_EXPAND_AND_REGISTER    (CTXFLG_EXPAND             | CTXFLG_REGISTER_CONTEXT)
#define CTXFLG_EXPAND_AND_NAVIGATE    (CTXFLG_EXPAND             | CTXFLG_URL_FROM_CONTEXT)
#define CTXFLG_COLLAPSE_AND_NAVIGATE  (CTXFLG_COLLAPSE           | CTXFLG_URL_FROM_CONTEXT)
#define CTXFLG_FULL                   (CTXFLG_EXPAND_CONDITIONAL | CTXFLG_REGISTER_CONTEXT | CTXFLG_URL_FROM_CONTEXT)

// admin\pchealth\pchmars\inc\marsdev.h
#define IsValidOptionalBstr(bstr) \
    ((!bstr) || IsValidBstr(bstr))
#define IsValidVariantBoolVal(vb) \
    (VARIANT_FALSE == vb || VARIANT_TRUE == vb)
#define IsValidVariantBstr(var) \
    (VT_BSTR == (var).vt && IsValidBstr((var).bstrVal))
#define IsValidVariantMissingOptional(var) \
    (VT_ERROR == (var).vt && DISP_E_PARAMNOTFOUND == (var).scode)

// admin\pchealth\sr\inc\blob.h
#define INIT_BLOB_HEADER( pBlob, MaxSize, Version, BlbType, Entries ) \
    ((BlobHeader *)pBlob)->m_dwMaxSize  = MaxSize; \
    ((BlobHeader *)pBlob)->m_dwVersion  = Version; \
    ((BlobHeader *)pBlob)->m_dwBlbType  = BlbType; \
    ((BlobHeader *)pBlob)->m_dwEntries  = Entries; \
    ((BlobHeader *)pBlob)->m_dwMagicNum = BLOB_MAGIC_NUM;

// admin\pchealth\sr\inc\ppath.h
#define CALC_PPATH_SIZE( a )    ( ( a + 3 ) * sizeof( WCHAR ) )
#define IFSPathSize(ppath)	((ppath)->pp_totalLength + sizeof(short))
#define IFSPathElemChars(pel) ( (((PathElement*)pel)->pe_length/sizeof(USHORT)) - 1 )

// admin\pchealth\sr\inc\srapi.h
#define IS_VALID_NOTIFICATION_RECORD(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == SR_NOTIFICATION_RECORD_TAG))

// admin\pchealth\sr\inc\utils.h
#define UnicodeStringToWchar(US, pwsz) CopyMemory(pwsz, US.Buffer, US.Length); \
                                        pwsz[US.Length/sizeof(WCHAR)]=L'\0'

// admin\pchealth\sr\kernel\control.h
#define IS_VALID_CONTROL_OBJECT(pObject) \
    (((pObject) != NULL) && ((pObject)->RefCount > 0) && ((pObject)->Signature == SR_CONTROL_OBJECT_TAG))

// admin\pchealth\sr\kernel\copyfile.c
#define IS_VALID_HANDLE_FILE_CHANGE_CONTEXT(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == SR_BACKUP_FILE_CONTEXT_TAG))

// admin\pchealth\sr\kernel\event.c
#define IS_VALID_TRIGGER_ITEM(pObject)   \
    (((pObject) != NULL) && ((pObject)->Signature == SR_TRIGGER_ITEM_TAG))
#define IS_VALID_BACKUP_DIRECTORY_CONTEXT(pObject)   \
    (((pObject) != NULL) && ((pObject)->Signature == SR_BACKUP_DIRECTORY_CONTEXT_TAG))

// admin\pchealth\sr\kernel\event.h
#define IS_VALID_OVERWRITE_INFO(pObject)   \
    (((pObject) != NULL) && ((pObject)->Signature == SR_OVERWRITE_INFO_TAG))

// admin\pchealth\sr\kernel\filenames.c
#       define FILE_BOTH_DIR_SIZE (sizeof( FILE_BOTH_DIR_INFORMATION ) + (256 * sizeof( WCHAR )))

// admin\pchealth\sr\kernel\hash.h
#define IS_VALID_HASH_BUCKET(pObject)   \
    (((pObject) != NULL) && ((pObject)->Signature == HASH_BUCKET_TAG))
#define IS_VALID_HASH_HEADER(pObject)   \
    (((pObject) != NULL) && ((pObject)->Signature == HASH_HEADER_TAG))

// admin\pchealth\sr\kernel\srpriv.h
#define SR_ALLOCATE_POOL( type, len, tag )          \
    ExAllocatePoolWithTag(                          \
        (type),                                     \
        (len),                                      \
        (tag)|PROTECTED_POOL )
#define IS_VALID_TAG(Tag)   (((Tag) & 0x0000ffff) == 'rS' )
#define IS_VALID_SR_STREAM_STRING( pFileName, StreamLength ) \
    ((((pFileName)->Length + (StreamLength)) <= (pFileName)->MaximumLength) && \
     (((StreamLength) > 0) ?                                                   \
        (((pFileName)->Length < (pFileName)->MaximumLength) &&                 \
         ((pFileName)->Buffer[(pFileName)->Length/sizeof(WCHAR)] == ':')) :    \
        TRUE ))
#define IS_VALID_GLOBALS(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == SR_GLOBALS_TAG))
#define SrAcquireContextLockShared(pExt) \
            SrAcquireResourceShared( &(pExt)->ContextCtrl.Lock, TRUE )
#define SrAcquireContextLockExclusive(pExt) \
            SrAcquireResourceExclusive( &(pExt)->ContextCtrl.Lock, TRUE )
#define IS_VALID_SR_DEVICE_EXTENSION( _ext )                 \
    (((_ext) != NULL) &&                                     \
     ((_ext)->Signature == SR_DEVICE_EXTENSION_TAG))
#define IS_SR_DEVICE_OBJECT( _devObj )                           \
    (((_devObj) != NULL) &&                                      \
     ((_devObj)->DriverObject == _globals.pDriverObject) &&       \
     (IS_VALID_SR_DEVICE_EXTENSION(((PSR_DEVICE_EXTENSION)(_devObj)->DeviceExtension))))
#define IS_RESOURCE_INITIALIZED( resource )                                 \
    ((resource)->SystemResourcesList.Flink != NULL)
#define IS_LOOKASIDE_INITIALIZED( lookaside )                               \
    ((lookaside)->L.ListEntry.Flink != NULL)
#define IS_VALID_DEVICE_OBJECT( pDeviceObject )                             \
    ( ((pDeviceObject) != NULL) &&                                          \
      ((pDeviceObject)->Type == IO_TYPE_DEVICE) )
#define IS_VALID_FILE_OBJECT( pFileObject )                                 \
    ( ((pFileObject) != NULL) &&                                            \
      ((pFileObject)->Type == IO_TYPE_FILE) )
#define IS_VALID_IRP( pIrp )                                                \
    ( ((pIrp) != NULL) &&                                                   \
      ((pIrp)->Type == IO_TYPE_IRP) &&                                      \
      ((pIrp)->Size >= IoSizeOfIrp((pIrp)->StackCount)) )
#define SR_IS_SUPPORTED_DEVICE(_do)                             \
    ((_do)->DeviceType == FILE_DEVICE_DISK_FILE_SYSTEM)
#define SR_IS_SUPPORTED_REAL_DEVICE(_rd)                            \
    (((_rd)->Characteristics & FILE_REMOVABLE_MEDIA) == 0)
#define SR_IS_SUPPORTED_VOLUME(_vpb)                            \
    (((_vpb)->DeviceObject->DeviceType == FILE_DEVICE_DISK_FILE_SYSTEM) &&     \
     ((_vpb)->RealDevice->Characteristics & FILE_REMOVABLE_MEDIA) == 0)
#define IS_VALID_WORK_ITEM(pObject)   \
    (((pObject) != NULL) && ((pObject)->Signature == SR_WORK_ITEM_TAG))
#define MOUNTMGR_IS_VOLUME_NAME_PREFIX(s) (                                 \
     (s)->Length >= MOUNTMGR_VOLUME_NAME_PREFIX_LENGTH &&                   \
     (s)->Buffer[0] == '\\' &&                                              \
     (s)->Buffer[1] == '?' &&                                               \
     (s)->Buffer[2] == '?' &&                                               \
     (s)->Buffer[3] == '\\' &&                                              \
     (s)->Buffer[4] == 'V' &&                                               \
     (s)->Buffer[5] == 'o' &&                                               \
     (s)->Buffer[6] == 'l' &&                                               \
     (s)->Buffer[7] == 'u' &&                                               \
     (s)->Buffer[8] == 'm' &&                                               \
     (s)->Buffer[9] == 'e' &&                                               \
     (s)->Buffer[10] == '{' &&                                              \
     (s)->Buffer[19] == '-' &&                                              \
     (s)->Buffer[24] == '-' &&                                              \
     (s)->Buffer[29] == '-' &&                                              \
     (s)->Buffer[34] == '-' &&                                              \
     (s)->Buffer[47] == '}' &&                                              \
     (s)->Buffer[48] == '\\' )
#define SrAcquireActivityLockShared(pExtension)   \
{                                                                           \
    KeEnterCriticalRegion();                                                \
    ExAcquireSharedStarveExclusive(&(pExtension)->ActivityLock, TRUE);      \
}
#define SrAcquireActivityLockExclusive(pExtension)                  \
    SrAcquireResourceExclusive(&(pExtension)->ActivityLock, TRUE)
#define IS_ACTIVITY_LOCK_ACQUIRED_EXCLUSIVE( pExtension )                   \
    ExIsResourceAcquiredExclusiveLite( &(pExtension)->ActivityLock )
#define IS_ACTIVITY_LOCK_ACQUIRED_SHARED( pExtension )                      \
    ExIsResourceAcquiredSharedLite( &(pExtension)->ActivityLock )
#define IS_GLOBAL_LOCK_ACQUIRED()                                   \
    (ExIsResourceAcquiredExclusiveLite(&(global->GlobalLock)) ||    \
     ExIsResourceAcquiredSharedLite( &(global->GlobalLock) ))
#define SrAcquireGlobalLockExclusive()                                  \
    SrAcquireResourceExclusive( &(global->GlobalLock), TRUE )
#define IS_DEVICE_EXTENSION_LIST_LOCK_ACQUIRED()                              \
    (ExIsResourceAcquiredExclusiveLite(&(global->DeviceExtensionListLock)) || \
     ExIsResourceAcquiredSharedLite( &(global->DeviceExtensionListLock) ))
#define SrAcquireDeviceExtensionListLockExclusive()                        \
    SrAcquireResourceExclusive( &(global->DeviceExtensionListLock), TRUE )
#define SrAcquireDeviceExtensionListLockShared()                        \
    SrAcquireResourceShared( &(global->DeviceExtensionListLock), TRUE )
#define SrAcquireBackupHistoryLockShared( pExtension ) \
    SrAcquireResourceShared( &((pExtension)->pBackupHistory->Lock), TRUE )
#define SrAcquireBackupHistoryLockExclusive( pExtension ) \
    SrAcquireResourceExclusive( &((pExtension)->pBackupHistory->Lock), TRUE )
#define FILE_OBJECT_DOES_NOT_HAVE_VPB(FileObject)       \
     (FileObject)->Vpb == NULL

// admin\pchealth\sr\kernel\stats.h
#define INC_STATS(field)    InterlockedIncrement( &SrStats.field );

// admin\pchealth\sr\nttest\srdiag2\tstparam.hxx
#define GETPARAM(param,var)         \
    g_TestParams.GetParam(param,&var)
#define GETPARAM_ABORTONERROR(param,var)        \
    hr=g_TestParams.GetParam(param,&var);       \
    if (S_FALSE!=hr)                            \
    {                                           \
        DH_HRCHECK_ABORT(hr,TEXT(param));       \
    }                                           \
    hr=S_OK;
#define GETPARAM_DEFINE(type,var,param,defaultval)  \
    type var=defaultval;                            \
    g_TestParams.GetParam(param,&var)
#define GETPARAM_REQUIRED(param,var)        \
    hr=g_TestParams.GetParam(param,&var);   \
    DH_HRCHECK_ABORT(hr,TEXT(param));
#define GETPARAM_RANGE(param,min,max) \
    g_TestParams.GetRange(param,&min,&max);
#define ESCAPE_NOTNEEDED(x)\
     ((' '<=x)&&('~'>=x))

// admin\pchealth\sr\restmap\reslist.h
#define HEAP_ALLOC( size ) \
    HeapAlloc( GetProcessHeap(), HEAP_GENERATE_EXCEPTIONS | HEAP_ZERO_MEMORY, size )
#define HEAP_REALLOC( p, size ) \
    HeapReAlloc( GetProcessHeap(), HEAP_GENERATE_EXCEPTIONS | HEAP_ZERO_MEMORY, p, size )
#define STRSIZE(pa) (lstrlen(pa) + 1) * sizeof(WCHAR)

// admin\pchealth\sr\restmap\restmap.h
#define IsRename(a) (a == OPR_FILE_RENAME || a == OPR_DIR_RENAME)

// admin\pchealth\sr\rstrcore\mapentry.cpp
#define PDF_BOTH  (PDF_LOC|PDF_OBJ)

// admin\pchealth\sr\tools\fldump\blob.c
#define PRINT_BLOB_HEADER( pBlob ) \
    printf( "\nBlob: %s, Size: %ld, Version: %ld, Entries: %ld \n",\
    blobTypArr[((BlobHeader *)pBlob)->m_dwBlbType], \
    ((BlobHeader *)pBlob)->m_dwMaxSize, \
    ((BlobHeader *)pBlob)->m_dwVersion, \
    ((BlobHeader *)pBlob)->m_dwEntries)

// admin\pchealth\sysinfo\control\devnode.h
#define BADHANDLE(x) ((x == 0 ) || ((HANDLE)x == INVALID_HANDLE_VALUE))

// admin\pchealth\sysinfo\control\whqlobj.h
#define     cbX(X)      sizeof(X)

// admin\pchealth\sysinfo\msconfig\exe\version.cpp
#define cbX(X) sizeof(X)

// admin\published\msi\msidefs.h
#define IPROPNAME_CHECKCRCS        TEXT("MSICHECKCRCS")      // requests Darwin to check CRCs after copying, moving, patching & duplicating files.

// admin\select\src\globals.hxx
#define OPM_NEW_QUERY_RESULTS   (WM_APP + 1)
#define OPM_QUERY_COMPLETE      (WM_APP + 2)
#define OPM_PROMPT_FOR_CREDS    (WM_APP + 3)
#define OPM_POPUP_CRED_ERROR    (WM_APP + 4)
#define OPM_HIT_QUERY_LIMIT     (WM_APP + 5)

// admin\select\src\richedithelper.hxx
#define RICH_EDIT_WINDOW_STYLE  (ES_MULTILINE   |   \
                                 WS_CHILDWINDOW |   \
                                 WS_TABSTOP     |   \
                                 WS_VISIBLE)

// admin\services\drizzle\newjob\cjob.h
#define BG_JOB_ALL_ACCESS   ( BG_JOB_QUERY_PROP |\
                              BG_JOB_SET_PROP   |\
                              BG_JOB_NOTIFY     |\
                              BG_JOB_MANAGE )
#define BG_JOB_READ         ( STANDARD_RIGHTS_READ |\
                              BG_JOB_QUERY_PROP )
#define BG_JOB_WRITE        ( STANDARD_RIGHTS_WRITE |\
                              BG_JOB_SET_PROP       |\
                              BG_JOB_NOTIFY         |\
                              BG_JOB_MANAGE )

// admin\services\drizzle\newjob\init.cpp
#define EH_EXCEPTION_NUMBER ('msc' | 0xE0000000)

// admin\services\drizzle\server\mmcexts\globals.h
        #define OBJECT_CREATED InterlockedIncrement((long *)&g_uObjects);
        #define OBJECT_DESTROYED InterlockedDecrement((long *)&g_uObjects);

// admin\services\drizzle\utils\nt4thunks.cpp
#define STRING_GUID_SIZE  ( STRING_GUID_LEN * sizeof( WCHAR ) )
#define SDDL_SIZE_TAG( tagdef )  ( wcslen( tagdef ) * sizeof( WCHAR ) )
#define SDDL_SIZE_SEP( sep ) (sizeof( WCHAR ) )

// admin\services\sched\common\globals.cxx
#define FS_NAME_BUFFER_SIZE (sizeof(FS_NTFS) * 2)

// admin\services\sched\folderui\jobidl.hxx
#define JOBID_MIN_SIZE  (sizeof(CJobID) - IDJOB_BUFFER_SIZE * sizeof(TCHAR))

// admin\services\sched\folderui\sfolder.cxx
#define JF_FSNOTIFY     (WM_USER + 0xA1)
#define STUBM_SETDATA   (WM_USER + 0xb1)
#define STUBM_GETDATA   (WM_USER + 0xb2)
#define DONT_PROCESS_MSG(M) \
    case M: break;

// admin\services\sched\inc\common.hxx
#define SCHED_WIN9X_GETSVCSTATE     (WM_USER + 200)
#define SCHED_WIN9X_STOPSVC         (WM_USER + 201)
#define SCHED_WIN9X_PAUSESVC        (WM_USER + 202)
#define SCHED_WIN9X_CONTINUESVC     (WM_USER + 203)

// admin\services\sched\inc\defines.hxx
#define ALL_MONTHS                  (TASK_JANUARY   | \
                                     TASK_FEBRUARY  | \
                                     TASK_MARCH     | \
                                     TASK_APRIL     | \
                                     TASK_MAY       | \
                                     TASK_JUNE      | \
                                     TASK_JULY      | \
                                     TASK_AUGUST    | \
                                     TASK_SEPTEMBER | \
                                     TASK_OCTOBER   | \
                                     TASK_NOVEMBER  | \
                                     TASK_DECEMBER)

// admin\services\sched\inc\misc.hxx
#define s_isDriveLetter(c)  ((c >= TEXT('a') && c <= TEXT('z')) || \
                             (c >= TEXT('A') && c <= TEXT('Z')))

// admin\services\sched\service\tasks.hxx
#define SCHEDM_TRAY_NOTIFY  (WM_APP+100)

// admin\services\sched\svc_core\desktop.cxx
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
#define WINSTA_ATOMS    (WINSTA_ACCESSGLOBALATOMS | \
                         WINSTA_ACCESSCLIPBOARD )

// admin\services\sched\test\st\st.cxx
#define SAGE_ADDTASK            (WM_USER + 9)
#define SAGE_REMOVETASK         (WM_USER + 10)
#define SAGE_GETTASK            (WM_USER + 11)

// admin\services\sched\wizard\daily.cxx
#define TASK_WEEKDAYS       (TASK_MONDAY    | \
                             TASK_TUESDAY   | \
                             TASK_WEDNESDAY | \
                             TASK_THURSDAY  | \
                             TASK_FRIDAY)

// admin\services\sched\wizard\monthly.cxx
#define MONTHS_WITHOUT_DAY_31       (TASK_FEBRUARY  | \
                                     TASK_APRIL     | \
                                     TASK_JUNE      | \
                                     TASK_SEPTEMBER | \
                                     TASK_NOVEMBER)

// admin\services\sched\wizard\seltrig.cxx
#define ILLEGAL_FILENAME_CHARS      TEXT("<>:/\\|")

// admin\snapin\adsiedit\pch.h
#define DECLARE_REGISTRY_CLSID() \
static HRESULT WINAPI UpdateRegistry(BOOL bRegister) \
{ \
		return _Module.UpdateRegistryCLSID(GetObjectCLSID(), bRegister); \
}

// admin\snapin\certmgr\certifct.h
#define MY_ENCODING_TYPE (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)

// admin\snapin\corecopy\mmcutil.h
#define MMC_CLSCTX_INPROC (CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER)

// admin\snapin\corecopy\ndmgr.h
#define WINDOW_DATA_SIZE (sizeof(long) * 4)

// admin\snapin\corecopy\strconv.h
#define WCS2STR(ws) \
	(ws ? (_strconv_length = lstrlenW(ws)+1,\
	wcs2str(reinterpret_cast<char*>(alloca(_strconv_length)),\
	ws, _strconv_length)) : NULL)

// admin\snapin\dfsadmin\common\dfsenums.h
#define DEFAULT_FILEFILTER                  _T("*.bak,*.tmp,~*")

// admin\snapin\dnsmgr\dnsutil.h
#define DNS_SIZE_OF_DNS_RPC_RR(pDnsRecord)\
		(SIZEOF_DNS_RPC_RECORD_HEADER + pDnsRecord->wDataLength)
#define UTF8_TO_W(lpa) (\
	((LPCSTR)lpa == NULL) ? NULL : (\
		_convert = (lstrlenA(lpa)+1),\
		DnsUtf8ToWHelper((LPWSTR) alloca(_convert*2), lpa, _convert)))
#define W_TO_UTF8(lpw) (\
	((LPCWSTR)lpw == NULL) ? NULL : (\
		_convert = (lstrlenW(lpw)+1)*4,\
		DnsWToUtf8Helper((LPSTR) alloca(_convert), lpw, _convert)))

// admin\snapin\dnsmgr\prednssn.h
#define DECLARE_REGISTRY_CLSID() \
static HRESULT WINAPI UpdateRegistry(BOOL bRegister) \
{ \
		return _Module.UpdateRegistryCLSID(GetObjectCLSID(), bRegister); \
}
#define FIX_THREAD_STATE_MFC_BUG() \
	AFX_MODULE_THREAD_STATE* pState = AfxGetModuleThreadState(); \
  CWinThread _dummyWinThread; \
	if (pState->m_pCurrentWinThread == NULL) \
  { \
    pState->m_pCurrentWinThread = &_dummyWinThread; \
  }

// admin\snapin\dnsmgr\record.cpp
#define SIZEOF_DNS_RPC_A_RECORD_DATA_HEADER			(sizeof(IP_ADDRESS))
#define SIZEOF_DNS_RPC_ATMA_RECORD_DATA_HEADER			(sizeof(UCHAR))
#define SIZEOF_DNS_RPC_AAAA_RECORD_DATA_HEADER			(sizeof(IPV6_ADDRESS))
#define SIZEOF_DNS_RPC_WKS_RECORD_DATA_HEADER		(sizeof(IP_ADDRESS)+sizeof(UCHAR))

// admin\snapin\dnsmgr\server.cpp
#define ADD_STRING(str) \
  strLength = wcslen((LPCWSTR)(str)) + 1;           \
  ADD_USHORT(strLength);                            \
  wcsncpy((LPWSTR)pPos, (LPCWSTR)(str), strLength); \
  pPos += strLength * sizeof(WCHAR);

// admin\snapin\domain\stdafx.h
#define DECLARE_REGISTRY_CLSID() \
static HRESULT WINAPI UpdateRegistry(BOOL bRegister) \
{ \
		return _Module.UpdateRegistryCLSID(GetObjectCLSID(), bRegister); \
}

// admin\snapin\dsadmin\dlgcreat.cpp
#define A2W_OEM(lpa) (\
	((_lpaMine = lpa) == NULL) ? NULL : (\
		_convert = (lstrlenA(_lpaMine)+1),\
		MyA2WHelper((LPWSTR) alloca(_convert*2), _lpaMine, _convert, CP_OEMCP)))
#define FILTER_ONE (UGOP_USERS | \
                    UGOP_ACCOUNT_GROUPS_SE | \
                    UGOP_RESOURCE_GROUPS_SE | \
                    UGOP_UNIVERSAL_GROUPS_SE | \
                    UGOP_BUILTIN_GROUPS | \
                    UGOP_WELL_KNOWN_PRINCIPALS_USERS \
                    )
#define FILTER_TWO (UGOP_USERS | \
                    UGOP_ACCOUNT_GROUPS_SE | \
                    UGOP_UNIVERSAL_GROUPS_SE | \
                    UGOP_WELL_KNOWN_PRINCIPALS_USERS | \
                    UGOP_USERS | \
                    UGOP_GLOBAL_GROUPS | \
                    UGOP_ALL_NT4_WELLKNOWN_SIDS \
                    )

// admin\snapin\dsadmin\dssnap.cpp
#define STRING_LEN (32 * sizeof(OLECHAR))

// admin\snapin\dsadmin\dsthread.h
#define DISPATCH_THREAD_RUN_MSG   (WM_USER + 100)
#define DISPATCH_THREAD_DONE_MSG  (WM_USER + 101)
#define WORKER_THREAD_START_MSG   (WM_USER + 102)
#define THREAD_SHUTDOWN_MSG   (WM_USER + 103)
#define THREAD_SHUTDOWN_ACK_MSG   (WM_USER + 104)

// admin\snapin\dsadmin\newobjcr.cpp
#define HeadersSizeNum(NumberOfSchedules) \
    (sizeof(SCHEDULE) + ((NumberOfSchedules)-1)*sizeof(SCHEDULE_HEADER))

// admin\snapin\dsadmin\stdafx.h
#define DECLARE_REGISTRY_CLSID() \
static HRESULT WINAPI UpdateRegistry(BOOL bRegister) \
{ \
		return _Module.UpdateRegistryCLSID(GetObjectCLSID(), bRegister); \
}

// admin\snapin\filemgmt\svchelp.h
#define IDH_101_973	973	// File Service Management: "&Another computer:" (Button)
#define IDH_101_975	975	// File Service Management: "B&rowse..." (Button)
#define IDH_211_305	305	// General: "&Description:" (Static)
#define IDH_211_285	285	// General: "Typ&e:" (Static)
#define IDH_211_263	263	// General: "Start para&meters:" (Static)
#define IDH_211_217	217	// General: "&Start" (Button)
#define IDH_211_264	264	// General: "Display &name:" (Static)
#define IDH_211_218	218	// General: "S&top" (Button)
#define IDH_211_219	219	// General: "&Pause" (Button)
#define IDH_211_220	220	// General: "&Resume" (Button)
#define IDH_213_253	253	// Recovery: "&Command line parameters:" (Static)
#define IDH_213_239	239	// Recovery: "Bro&wse..." (Button)
#define IDH_213_290	290	// Recovery: "&First attempt:" (Static)
#define IDH_213_292	292	// Recovery: "S&ubsequent attempts:" (Static)
#define IDH_213_246	246	// Recovery: "Re&boot Computer Information..." (Button)
#define IDH_213_293	293	// Recovery: "Reset 'Fail Count' to &zero after:" (Static)
#define IDH_223_294	294	// General: "Share &Name:" (Static)

// admin\snapin\mtfrmwk\treedata.h
#define DECLARE_NODE_GUID() \
	static const GUID NodeTypeGUID; \
	virtual const GUID* GetNodeType() { return &NodeTypeGUID;}

// admin\wizards\addusrw\dapi.h
#define DAPI_EXPORT_RECIPIENTS       (DAPI_EXPORT_MAILBOX | DAPI_EXPORT_CUSTOM | DAPI_EXPORT_DIST_LIST)

// admin\wizards\addusrw\fpnwcomm.h
#define NCP_USER_IS_CONNECTED_BUT_REMOTE(connid)    (0xD0000000 | (connid))
#define NCP_WELL_KNOWN_RID(rid)                     (0xD1000000 | (rid))

// admin\wmi\wbem\adapters\odbc\drdbdr.h
#define GET_WM_COMMAND_ID(wp, lp)               (wp)
#define lstrcmpi(left, right) (CompareString(LOCALE_SYSTEM_DEFAULT,     \
                                     NORM_IGNORECASE | SORT_STRINGSORT, \
                                     left, -1, right, -1) - 2)

// admin\wmi\wbem\adapters\odbc\parse.h
#define ToNode(lpSql, idx)      (&((lpSql)[idx]))
#define ToString(lpSql, idx)    (&((lpSql)->node.root.lpStringArea[idx]))

// admin\wmi\wbem\adapters\odbc\util.cpp
#define UPPER(c)	((((c) < 'a') || ((c) > 'z')) ? (c) : (((c) - 'a') + 'A'))

// admin\wmi\wbem\adapters\oledb\util.cpp
#define wbem_towlower(C) \
    (((C) >= 0 && (C) <= 127)?          \
        (((C) >= 'A' && (C) <= 'Z')?          \
            ((C) + ('a' - 'A')):          \
            (C)          \
        ):          \
        towlower(C)          \
    )

// admin\wmi\wbem\adapters\wmireverseperformancemonitor\include\__macro_loadstring.h
#define	___LOADSTRING( hInst, nID ) \
( \
	( \
		( ! hInst ) ? NULL : \
		( \
			psz  = LoadStringSystem ( hInst, nID ), \
			size = ( \
						( ( ! psz ) ? NULL : ( ( lstrlenW ( psz ) + 1 ) ) * sizeof ( WCHAR ) ) \
				   ), \
\
			LoadStringHelper ( ( LPWSTR ) alloca ( size ), psz ) \
		) \
	) \
)

// admin\wmi\wbem\adapters\wmireverseperformancemonitor\include\__macro_nocopy.h
#define DECLARE_NO_COPY( T ) \
private:\
	T(const T&);\
	T& operator=(const T&);

// admin\wmi\wbem\adapters\xml\wmixmlt\wmi2xml.h
#define WRITEBSTR(X)	m_pStream->Write ((OLECHAR *)X, wcslen (X) * sizeof (OLECHAR), NULL);
#define WRITEWSTR(X)	m_pStream->Write (           X, wcslen (X) * sizeof (OLECHAR), NULL);
#define WRITEWSTRL(X,L) m_pStream->Write (           X, L * sizeof (OLECHAR), NULL);

// admin\wmi\wbem\common\wdmlib\crc32.h
#define FINALIZE_CRC32(x)    (x=~x)

// admin\wmi\wbem\cppunit\framework\guards.h
#define REFERENCEOBJECT(className) \
private: \
               className (const className& other); \
    className& operator= (const className& other);

// admin\wmi\wbem\providers\ping\inc\pingprov.h
#define MAX_BUFFER_SIZE       (sizeof(ICMP_ECHO_REPLY) + 0xfff7 + MAX_OPT_SIZE)

// admin\wmi\wbem\providers\ping\inc\pingtask.h
#define PING_MAX_IPS ( MAX_OPT_SIZE / 4 /*sizeof(ULONG)*/ )

// admin\wmi\wbem\providers\snmpprovider\common\sclcomm\include\op.h
#define SEND_ERROR_EVENT (WM_USER+4)
#define OPERATION_COMPLETED_EVENT (WM_USER+5)

// admin\wmi\wbem\providers\snmpprovider\common\sclcomm\include\trapsess.h
#define TRAP_EVENT		(WM_USER+1)

// admin\wmi\wbem\providers\snmpprovider\common\sclcomm\include\window.h
#define NULL_EVENT_ID			(WM_USER+1)
#define MESSAGE_ARRIVAL_EVENT	(WM_USER+2)
#define SENT_FRAME_EVENT		(WM_USER+3)
#define SEND_ERROR_EVENT		(WM_USER+4)
#define OPERATION_COMPLETED_EVENT (WM_USER+5)

// admin\wmi\wbem\providers\win32provider\common\chwres.h
#define InitializeKey( k, h, n )                                            \
    {                                                                       \
        ( k )->ParentHandle             = h->hRegKey;                       \
        ( k )->Name                     = n;                                \
        ( k )->CountOfValues            = 0;                                \
        ( k )->Values                   = NULL;                             \
        ( k )->hKey                     = NULL;                             \
        ( k )->Data                     = NULL;                             \
        ( k )->Size                     = 0;                                \
        ( k )->ValueName                = NULL;                             \
        ( k )->ValueNameLength          = 0;                                \
        ( k )->Subkey                   = NULL;                             \
        ( k )->SubkeyLength             = 0;                                \
        ( k )->Subkeys                  = 0;                                \
        ( k )->Type                     = REG_NONE;                         \
        ( k )->CurrentSize              = 0;                                \
        ( k )->CurrentValueNameLength   = 0;                                \
        ( k )->CurrentValue             = 0;                                \
        ( k )->CurrentSubkeyLength      = 0;                                \
        ( k )->CurrentSubkey            = 0;                                \
    }

// admin\wmi\wbem\providers\win32provider\common\poormansresource.h
#define	SIZEOF_RESDESC_HDR		sizeof(POORMAN_RESDESC_HDR)

// admin\wmi\wbem\providers\win32provider\providers\1394.h
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_CAP_NAME			( SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )

// admin\wmi\wbem\providers\win32provider\providers\cdrom.h
#define SPECIAL_ALL					( SPECIAL_CONFIGMANAGER | \
									SPECIAL_MEDIA )
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_CAP_NAME			( SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_SCSIINFO			( SPECIAL_PROPS_SCSITARGETID | \
									SPECIAL_PROPS_SCSIBUS | \
									SPECIAL_PROPS_SCSILUN | \
									SPECIAL_PROPS_SCSIPORT )
#define SPECIAL_ALL					( SPECIAL_CONFIGMANAGER | \
									SPECIAL_MEDIA )

// admin\wmi\wbem\providers\win32provider\providers\configmg.h
#define	SIZEOF_DMA		sizeof(DMA_DES)
#define	SIZEOF_IRQ		sizeof(IRQ_DES)

// admin\wmi\wbem\providers\win32provider\providers\floppy.h
#define SPECIAL_ALL					( SPECIAL_CONFIGMANAGER | \
									SPECIAL_MEDIA )
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_CAP_NAME			( SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_ALL					( SPECIAL_CONFIGMANAGER | \
									SPECIAL_MEDIA )

// admin\wmi\wbem\providers\win32provider\providers\floppycontroller.h
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_CAP_NAME			( SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )

// admin\wmi\wbem\providers\win32provider\providers\infrared.h
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_CAP_NAME			( SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )

// admin\wmi\wbem\providers\win32provider\providers\os.cpp
#define NT5_WIN32_SHUTDOWNOPTIONS ( WIN32_SHUTDOWNOPTIONS | EWX_FORCEIFHUNG )

// admin\wmi\wbem\providers\win32provider\providers\scsi.h
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_DESC_CAP_NAME		( SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_CAP_NAME			( SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_NAME )
#define SPECIAL_ALL					( SPECIAL_CONFIGMANAGER | \
									SPECIAL_SCSI )

// admin\wmi\wbem\providers\win32provider\providers\smbios.h
#define V_VOLTAGE					0x7f	// voltage = ( value & V_VOLTAGE ) / 10;

// admin\wmi\wbem\providers\win32provider\providers\tapedrive.h
#define SPECIAL_CONFIGMANAGER		( SPECIAL_CONFIGPROPERTIES | \
									SPECIAL_PROPS_DEVICEID | \
									SPECIAL_PROPS_CREATIONNAME | \
									SPECIAL_PROPS_SYSTEMNAME | \
									SPECIAL_PROPS_DESCRIPTION | \
									SPECIAL_PROPS_CAPTION | \
									SPECIAL_PROPS_ID | \
									SPECIAL_PROPS_NAME | \
									SPECIAL_PROPS_MANUFACTURER | \
									SPECIAL_PROPS_PROTOCOLSSUPPORTED | \
									SPECIAL_PROPS_CREATIONCLASSNAME )
#define SPECIAL_MEDIA				( SPECIAL_PROPS_CAPABILITY | \
									SPECIAL_PROPS_MEDIATYPE )
#define SPECIAL_ALL					( SPECIAL_CONFIGMANAGER | \
									SPECIAL_MEDIA | \
									SPECIAL_TAPEINFO )

// admin\wmi\wbem\providers\win32provider\thunk\win\configmg.h
#define	SIZEOF_DMA		sizeof(DMA_DES)
#define	SIZEOF_IRQ		sizeof(IRQ_DES)

// admin\wmi\wbem\providers\win32provider\thunk\win\netcons.h
#define MAXDEVENTRIES	(sizeof (int)*8)    /* Max number of device entries   */

// admin\wmi\wbem\providers\win32provider\thunk\win\vmm.h
#define VMM_TRUE    (~FALSE)    // The opposite of False!
#define CONFIGMG_DEVICE_ID  0x00033 /* Configuration manager (Plug&Play) */
#define P_AVAIL     (P_PRES+P_WRITE+P_USER) /* avail to user & present */

// admin\wmi\wbem\providers\win32provider\tools\ntdevicetest\poormansresource.h
#define	SIZEOF_RESDESC_HDR		sizeof(POORMAN_RESDESC_HDR)

// admin\wmi\wbem\scripting\parsedn.cpp
#define SKIPWHITESPACE \
	while (*CURRENTSTR && _istspace( *CURRENTSTR ) ) \
			(*pchEaten)++;

// admin\wmi\wbem\sdk\activex\controls\commondlls\hmmvgrid\utils.cpp
#define MIN_SINT8 (~MAX_SINT8 & -1)
#define MIN_SINT16 (~MAX_SINT16  & -1)
#define MIN_SINT32 (~MAX_SINT32 & -1)

// admin\wmi\wbem\sdk\activex\controls\cppwiz\cppgensheet.cpp
#define AfxDeferRegisterClass(fClass) \
	((afxRegisteredClasses & fClass) ? TRUE : AfxEndDeferRegisterClass(fClass))

// admin\wmi\wbem\sdk\activex\controls\msgdlg\htmtopics.h
#define idh_usinggotonamespace _T("hh/wmisdk/toolsguide_1h66.htm")           //  Using the Go to Namespace Function

// admin\wmi\wbem\sdk\activex\controls\singleview\parmgrid.cpp
#define RELEASE(x) if(x){x->Release();x=NULL;}

// admin\wmi\wbem\sdk\activex\controls\singleview\ppgmethodparms.cpp
#define RELEASE(x) if(x){x->Release();x=NULL;}

// admin\wmi\wbem\sdk\activex\controls\singleview\psmethparms.cpp
#define AfxDeferRegisterClass(fClass) \
	((afxRegisteredClasses & fClass) ? TRUE : AfxEndDeferRegisterClass(fClass))
#define RELEASE(x) if(x){x->Release();x=NULL;}

// admin\wmi\wbem\sdk\activex\controls\singleview\psqualifiers.cpp
#define AfxDeferRegisterClass(fClass) \
	((afxRegisteredClasses & fClass) ? TRUE : AfxEndDeferRegisterClass(fClass))

// admin\wmi\wbem\sdk\psstools\utillib\utillib.h
#define RELEASE(a) if (a) { (a)->Release(); (a)=NULL;}

// admin\wmi\wbem\shell\atlui\cmprops\sysdm.h
#define IsPathSep(ch)       ((ch) == TEXT('\\') || (ch) == TEXT('/'))

// admin\wmi\wbem\shell\atlui\cmprops\virtualmemdlg.cpp
#define RET_VIRT_AND_RECOVER (RET_VIRTUAL_CHANGE | RET_RECOVER_CHANGE)

// admin\wmi\wbem\shell\atlui\inc\snapins.inc\mmc.h
#define IS_SPECIAL_COOKIE(c)     (((c)          >= SPECIAL_COOKIE_MIN) && ((c)          <= SPECIAL_COOKIE_MAX))
#define ILSI_LARGE_ICON(nLoc)   (nLoc | ILSIF_LEAVE_SMALL_ICON)
#define ILSI_SMALL_ICON(nLoc)   (nLoc | ILSIF_LEAVE_LARGE_ICON)

// admin\wmi\wbem\shell\atlui\inc\snapins.inc\rpcasync.h
#define RPC_ASYNC_VERSION_1_0     sizeof(RPC_ASYNC_STATE)

// admin\wmi\wbem\shell\atlui\inc\snapins.inc\rpcndr.h
#define NDRSContextValue(hContext) (&(hContext)->userContext)
#define boolean_from_ndr(source, target) \
    { \
    *(target) = *(*(char __RPC_FAR * __RPC_FAR *)&(source)->Buffer)++; \
    }
#define small_from_ndr(source, target) \
    { \
    *(target) = *(*(char __RPC_FAR * __RPC_FAR *)&(source)->Buffer)++; \
    }
#define _midl_ma1( p, cast )    *(*( cast **)&p)++
#define _midl_ma2( p, cast )    *(*( cast **)&p)++
#define _midl_ma4( p, cast )    *(*( cast **)&p)++
#define _midl_ma8( p, cast )    *(*( cast **)&p)++
#define _midl_marsh_lhs( p, cast )  *(*( cast **)&p)++
#define _midl_marsh_up( mp, p )     *(*(unsigned long **)&mp)++ = (unsigned long)p
#define _midl_advmp( mp )           *(*(unsigned long **)&mp)++
#define _midl_unmarsh_up( p )       (*(*(unsigned long **)&p)++)

// admin\wmi\wbem\shell\atlui\wmicntl\chklist.h
#define CLST_CHECKDISABLED  (CLST_CHECKED | CLST_DISABLED)
#define CLM_SETCOLUMNWIDTH  (WM_USER + 1)   // lParam = width (dlg units) of a check column (default=32)
#define CLM_SETSTATE        (WM_USER + 4)   // wParam = row/column, lParam = state
#define CLM_SETITEMDATA     (WM_USER + 6)   // wParam = row, lParam = item data
#define CLM_RESETCONTENT    (WM_USER + 8)   // no parameters
#define CLM_SETTOPINDEX     (WM_USER + 11)  // wParam = index of new top row
#define CLM_ENSUREVISIBLE   (WM_USER + 12)  // wParam = index of item to make fully visible

// admin\wmi\wbem\shell\atlui\wmicntl\principal.h
#define VALID_NSMETHOD_STYLE (ACL_ENABLE | ACL_METHOD_EXECUTE | ACL_FULL_WRITE | \
								ACL_PARTIAL_WRITE | ACL_PROVIDER_WRITE | ACL_READ_CONTROL | \
								ACL_WRITE_DAC)

// admin\wmi\wbem\shell\atlui\wmicntl\si.cpp
#define WBEM_GENERAL_WRITE     (WBEM_FULL_WRITE_REP|WBEM_PARTIAL_WRITE_REP|WBEM_WRITE_PROVIDER)
#define WBEM_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED  |\
							SYNCHRONIZE            |\
							WBEM_ENABLE            |\
							WBEM_METHOD_EXECUTE    |\
							WBEM_FULL_WRITE_REP    |\
							WBEM_PARTIAL_WRITE_REP |\
							WBEM_WRITE_PROVIDER)
#define WBEM_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
                                   WBEM_ENABLE)
#define WBEM_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
                                   WBEM_FULL_WRITE_REP      |\
                                   WBEM_PARTIAL_WRITE_REP   |\
                                   WBEM_WRITE_PROVIDER)
#define WBEM_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
                                   WBEM_METHOD_EXECUTE)
#define FirstAce(Acl) ((PVOID)((PUCHAR)(Acl) + sizeof(ACL)))
#define FirstAce(Acl) ((PVOID)((PUCHAR)(Acl) + sizeof(ACL)))

// admin\wmi\wbem\tools\wmic\precomp.h
#define VARIANTCLEAR(v)	\
		VariantClear(&v); \

// admin\wmi\wbem\winmgmt\coredll\wmitask.h
#define CORE_TASK_TYPE(x)   (x & 0xFF)

// admin\wmi\wbem\winmgmt\coretest\evilperf\perfutil.cpp
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// admin\wmi\wbem\winmgmt\esscomp\noncom\ncobjapi\event.cpp
#define wbem_towlower(C) \
    (((C) >= 0 && (C) <= 127)?          \
        (((C) >= 'A' && (C) <= 'Z')?          \
            ((C) + ('a' - 'A')):          \
            (C)          \
        ):          \
        towlower(C)          \
    )

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\noncomtest\include\__macro_loadstring.h
#define	___LOADSTRING( hInst, nID ) \
( \
	( \
		( ! hInst ) ? NULL : \
		( \
			psz  = LoadStringSystem ( hInst, nID ), \
			size = ( \
						( ( ! psz ) ? NULL : ( ( lstrlenW ( psz ) + 1 ) ) * sizeof ( WCHAR ) ) \
				   ), \
\
			LoadStringHelper ( ( LPWSTR ) alloca ( size ), psz ) \
		) \
	) \
)

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\noncomtest\include\__macro_nocopy.h
#define DECLARE_NO_COPY( T ) \
private:\
	T(const T&);\
	T& operator=(const T&);

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\noncomtest\include\atlctrlw.h
#define CBRM_TRACKPOPUPMENU		(WM_USER + 303)	// displays a popup menu

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\noncomtest\include\atlddx.h
#define DDX_CONTROL(nID, obj) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
			DDX_Control(nID, obj, bSaveAndValidate);
#define DDX_CHECK(nID, var) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
			DDX_Check(nID, var, bSaveAndValidate);
#define DDX_RADIO(nID, var) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
			DDX_Radio(nID, var, bSaveAndValidate);

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\noncomtest\include\atlframe.h
#define CBRM_TRACKPOPUPMENU		(WM_USER + 303)	// displays a popup menu

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\noncomtest\include\atlres.h
#define LB_ADDSTRING    (WM_USER+1)
#define CB_ADDSTRING    (WM_USER+3)

// admin\wmi\wbem\winmgmt\esscomp\vsa\vsaprov\vsaevent.cpp
#define GUID_STR_LEN    39 * sizeof(WCHAR)

// admin\wmi\wbem\winmgmt\marshalers\addrrslv\ipx\addreslv.cpp
#define IsSlash(x)			(x == L'\\' || x== L'/')

// admin\wmi\wbem\winmgmt\marshalers\coreprox\fastprop.h
#define WBEM_OBJACCESS_HANDLE_ISRESERVED(handle)	(BOOL)	( WBEM_OBJACCESS_HANDLE_ISOBJECT(handle) &&\
															WBEM_OBJACCESS_HANDLE_ISSTRING(handle) &&\
															WBEM_OBJACCESS_HANDLE_ISARRAY(handle) )

// admin\wmi\wbem\winmgmt\marshalers\shared\utils.h
#define A2W(lpa) (\
	((LPCSTR)lpa == NULL) ? NULL : (\
		_convert = (strlen(lpa)+1),\
		A2WHelper((LPWSTR) alloca(_convert*2), lpa, _convert)\
	)\
)
#define W2A(lpw) (\
	((LPCWSTR)lpw == NULL) ? NULL : (\
		_convert = (wcslen(lpw)+1)*2,\
		W2AHelper((LPSTR) alloca(_convert), lpw, _convert)\
	)\
)
#define IsSlash(x) (x == L'\\' || x== L'/')

// admin\wmi\wbem\winmgmt\marshalers\wbemprox\cprovloc.cpp
#define IsSlash(x) (x == L'\\' || x== L'/')

// admin\wmi\wbem\winmgmt\mofcomp_dll\moflex.cpp
#define isuorl(x) (towupper(x) == L'U' || towupper(x) == L'L')

// admin\wmi\wbem\winmgmt\mofcomp_dll\mofprop.h
#define VT_EX_EMBEDDED (VT_RESERVED | VT_EMBEDDED_OBJECT)

// admin\wmi\wbem\winmgmt\mofcompiler\mrcicode.c
#define hash(w)         ((w) & (CHASH - 1))

// admin\wmi\wbem\winmgmt\mofcompiler\test\mrcicode.c
#define hash(w)         ((w) & (CHASH - 1))

// admin\wmi\wbem\winmgmt\stdprov\crc32.h
#define FINALIZE_CRC32(x)    (x=~x)

// admin\wmi\wbem\winmgmt\wbemcomn\csspi.cpp
#define Macro_CloneLPWSTR(x) \
    (x ? _wcsdup(x) : 0)
#define Macro_CloneLPSTR(x) \
    (x ? _strdup(x) : 0)

// admin\wmi\wbem\winmgmt\wbemcomn\genutils.cpp
#define IsSlash(x) (x == L'\\' || x== L'/')

// admin\wmi\wbem\winmgmt\wbemcomn\mrcicode.cpp
#define hash(w)         ((w) & (CHASH - 1))

// admin\wmi\wbem\winmgmt\wbemcomn\strutils.h
#define wbem_towlower(C) \
    (((C) >= 0 && (C) <= 127)?          \
        (((C) >= 'A' && (C) <= 'Z')?          \
            ((C) + ('a' - 'A')):          \
            (C)          \
        ):          \
        towlower(C)          \
    )

// admin\wmi\wbem\winmgmt\wbemcomn\var.h
#define VT_EX_CVAR           (VT_USERDEFINED | 0x80010000)
#define VT_EX_CVARVECTOR     (VT_USERDEFINED | 0x80010002)

// admin\wmi\wbem\winmgmt\wbemcomn\wbemutil.h
#define BlobInit(p) \
    ((p)->cbSize = 0, (p)->pBlobData = 0)

// admin\wmi\wbem\winmgmt\wbemtest\wt_strutils.h
#define wbem_towlower(C) \
    (((C) >= 0 && (C) <= 127)?          \
        (((C) >= 'A' && (C) <= 'Z')?          \
            ((C) + ('a' - 'A')):          \
            (C)          \
        ):          \
        towlower(C)          \
    )

// admin\wmi\wbem\winmgmt\wbemtest\wt_var.h
#define VT_EX_CVAR           (VT_USERDEFINED | 0x80010000)
#define VT_EX_CVARVECTOR     (VT_USERDEFINED | 0x80010002)

// admin\wmi\wbem\winmgmt\winmgmt2\list_entry.h
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
#define InitializeListHead(ListHead) (\
    (ListHead)->Flink = (ListHead)->Blink = (ListHead))

// admin\wmi\wbem\winmgmt\winmgmt2\wbemdelta.cpp
#define FIXED_SIZE (sizeof(_T("System\\CurrentControlSet\\Services\\%s\\Performance")))

// admin\wmi\wbem\winmgmt\wmiexts\heap.h
#define HEAP_GRANULARITY            ((LONG) sizeof( HEAP_ENTRY ))

// admin\wmi\wbem\winmgmt\wmiexts\wmiexts.h
# define DEFINE_CPP_VAR( className, classVar) \
   CHAR  classVar[sizeof(className)]

// admin\wmi\wbem\winmgmt\wmiperf\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// admin\wmi\wbem\winmgmt\xfiles\varobjheap.h
	#define FINALIZE_CRC32(x)    (x=~x)

// admin\wmi\wbem\xmltransport\client\includes\utils.h
#define WRITETOSTREAM(X,S) (X)->Write(S, wcslen(S)*sizeof(WCHAR), NULL);
#define WRITEBSTRTOSTREAM(X,S) (X)->Write(S, SysStringLen(S)*sizeof(WCHAR), NULL);

// admin\wmi\wbem\xmltransport\compiler\xmlcomp\ui.cpp
#define SkipSpacesTillNull(X)				while ( (!IsNull(X)) && (iswspace(*X))) X++;
#define SkipTillNextSpaceOrEnd(X)			while ( (!IsNull(X)) && (!iswspace(*X))) X++;
#define SkipTillNextSpaceOrEndOrColon(X)	while ( (!IsNull(X)) && (!iswspace(*X)) && (*X != L':')) X++;

// admin\wmi\wbem\xmltransport\server\wmi2xml\wmi2xml.h
#define WRITEBSTR(X)	pOutputStream->Write ((void const *)X, wcslen (X) * sizeof (OLECHAR), NULL);
#define WRITEWSTR(X)	pOutputStream->Write ((void const *)X, wcslen (X) * sizeof (OLECHAR), NULL);
#define WRITEWSTRL(X,L) pOutputStream->Write ((void const *)X, L * sizeof (OLECHAR), NULL);

// admin\wmi\wbem\xmltransport\server\wmixmlop\xmlhelp.h
#define WRITEBSTR(theStream, X)	theStream->Write ((void const *)X, wcslen (X) * sizeof (OLECHAR), NULL);
#define WRITEWSTR(theStream, X)	theStream->Write ((void const *)X, wcslen (X) * sizeof (OLECHAR), NULL);
#define WRITEWSTRL(theStream, X,L) theStream->Write ((void const *)X, L * sizeof (OLECHAR), NULL);

// admin\wmiscmgr\defines.h
#define NOTEMPTY_BSTR_VARIANT(pvValue) (V_VT(pvValue)==VT_BSTR && V_BSTR(pvValue) && wcslen(V_BSTR(pvValue)))

// com\inc\ndrshared\ndrmisc.h
#define IS_HANDLE_IN( FC )          ((FC) & HANDLE_PARAM_IS_IN)
#define IS_HANDLE_OUT( FC )         ((FC) & HANDLE_PARAM_IS_OUT)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\core\expandft.c
#define IS_COMPONENT_TERMINATOR(ch)       (! (ch) || (ch) == PERIOD || (ch) == ASTERISK)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\core\reclist.h
#define RECNODE_IS_AVAILABLE(prn)     (RECNODE_EXISTS(prn) || RECNODE_DOES_NOT_EXIST(prn))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\core\stock.h
#define IS_SLASH(ch)                      ((ch) == SLASH || (ch) == BACKSLASH)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\atoms.h
#define Atom_IsValid(atom)      (ATOM_ERR != (atom) && 0 != (atom))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\comctrlp.h
#define RBS_VALID       (RBS_TOOLTIPS | RBS_VARHEIGHT | RBS_BANDBORDERS)
#define BL_MSGMAX               (WM_USER+17)
#define TME_VALID (TME_HOVER | TME_LEAVE | TME_QUERY | TME_CANCEL) //

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\winuserp.h
#define TME_VALID (TME_HOVER | TME_LEAVE | TME_QUERY | TME_CANCEL)
#define BF_VALID       (BF_MIDDLE |  \
                        BF_SOFT   |  \
                        BF_ADJUST |  \
                        BF_FLAT   |  \
                        BF_MONO   |  \
                        BF_LEFT   |  \
                        BF_TOP    |  \
                        BF_RIGHT  |  \
                        BF_BOTTOM |  \
                        BF_DIAGONAL)
#define WPF_VALID              (WPF_SETMINPOSITION     | \
                                WPF_RESTORETOMAXIMIZED)
#define PM_VALID           (PM_NOREMOVE | \
                            PM_REMOVE   | \
                            PM_NOYIELD)
#define MOD_VALID           (MOD_ALT|MOD_CONTROL|MOD_SHIFT|MOD_WIN)
#define SWP_VALID1          (SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOREDRAW | SWP_NOACTIVATE | SWP_FRAMECHANGED)
#define SWP_VALID           (SWP_VALID1 | SWP_VALID2)
#define MF_VALID          (MF_CHANGE_VALID    | \
                           MF_HELP            | \
                           MF_MOUSESELECT)
#define DDL_VALID          (DDL_READWRITE  | \
                            DDL_READONLY   | \
                            DDL_HIDDEN     | \
                            DDL_SYSTEM     | \
                            DDL_DIRECTORY  | \
                            DDL_ARCHIVE    | \
                            DDL_POSTMSGS   | \
                            DDL_DRIVES     | \
                            DDL_EXCLUSIVE)
#define SPIF_VALID            (SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE)

// com\ole2ui32\common.h
#define OLEUI_CCHKEYMAX_SIZE        OLEUI_CCHKEYMAX*sizeof(TCHAR)
#define MAX_PATH_SIZE               (MAX_PATH*sizeof(TCHAR))
#define OLEUI_CCHLABELMAX_SIZE      OLEUI_CCHLABELMAX*sizeof(TCHAR)

// com\ole2ui32\geticon.cpp
#define IS_SEPARATOR(c)         ( (c) == ' ' || (c) == '\\' \
                                                                  || (c) == '/' || (c) == '\t' \
                                                                  || (c) == '!' || (c) == ':')
#define IS_FILENAME_DELIM(c)    ( (c) == '\\' || (c) == '/' || (c) == ':' )
#define IS_SPACE(c)                     ( (c) == ' ' || (c) == '\t' || (c) == '\n' )

// com\ole2ui32\icon.cpp
#define IS_PATH_SEPARATOR(wch) \
    ((wch) == '\\' || (wch) == '/')

// com\ole2ui32\insobj.cpp
#define IS_FILENAME_DELIM(c)    ( (c) == '\\' || (c) == '/' || (c) == ':')

// com\ole32\com\class\chicago\longname.c
#define IS_PATH_SEPARATOR(wch) \
    ((wch) == L'\\' || (wch) == L'/')

// com\ole32\com\class\longpath.cxx
#define IS_PATH_SEPARATOR(wch) \
    ((wch) == L'\\' || (wch) == L'/')

// com\ole32\com\moniker2\cmonimp.cxx
#define UNIVERSAL_NAME_BUFFER_SIZE (sizeof(UNIVERSAL_NAME_INFOW) +         \
                                    MAX_PATH * sizeof(WCHAR) )
#define REMOTE_NAME_BUFFER_SIZE (sizeof(REMOTE_NAME_INFO) +         \
                                 MAX_PATH * sizeof(WCHAR) +         \
                                 (MAX_PATH + 1) * sizeof(WCHAR))

// com\ole32\com\moniker\cmonimp.h
#define IS_PATH_SEPARATOR_OLE(ch) ((ch == WCHAR_BACKSLASH) || (ch == WCHAR_FWDSLASH) || (ch == UNICODE_NULL))
#define IS_PATH_SEPARATOR_STRICT(ch) ((ch == WCHAR_BACKSLASH) || (ch == WCHAR_FWDSLASH))

// com\ole32\cs\admin\ui\csnapin.h
#define OLESAFE_COPYSTRING(szO, szI) {if (szI) {int i = wcslen(szI); szO=(OLECHAR *)OLEALLOC(sizeof(OLECHAR) * (i+1)); wcscpy(szO, szI);} else szO=NULL;}

// com\ole32\ih\exports.hxx
#define API_CoGetMarshalSizeMax                 (API_NAMETABLE|(API_START+147))

// com\ole32\ih\osift.hxx
#define SIMULATE_FAILURE( dwRes )                               \
            ((NULL != g_psftSiftObject) &&                      \
                    (g_psftSiftObject->SimFail( ( dwRes ) )))   \

// com\ole32\ole232\stdimpl\icon.cpp
#define IS_SEPARATOR(c)         ( (c) == OLESTR(' ') || (c) == OLESTR('\\') || (c) == OLESTR('/') || (c) == OLESTR('\t') || (c) == OLESTR('!') || (c) == OLESTR(':') )
#define IS_FILENAME_DELIM(c)    ( (c) == OLESTR('\\') || (c) == OLESTR('/') || (c) == OLESTR(':') )

// com\ole32\oleprx32\proxy\transmit.h
#define CHECK_BUFFER_SIZE( b, s )                                \
    if ( (b) < (s) )                                             \
        {                                                        \
        RAISE_RPC_EXCEPTION( RPC_X_BAD_STUB_DATA );              \
        }

// com\ole32\olethunk\ole16\inc\windows.h
#define BM_GETCHECK	    (WM_USER+0)
#define BM_SETCHECK	    (WM_USER+1)
#define LB_SELITEMRANGE        (WM_USER+28)

// com\ole32\olethunk\ole16\ole2\icon.cxx
#define IS_SEPARATOR(c)         ( (c) == ' ' || (c) == '\\' || (c) == '/' || (c) == '\t' || (c) == '!' || (c) == ':' )
#define IS_FILENAME_DELIM(c)    ( (c) == '\\' || (c) == '/' || (c) == ':' )

// com\ole32\olethunk\olethk32\thop.hxx
#define IS_THOP_IN(pti)     ((*((pti)->pThop) & THOP_IN) == THOP_IN)
#define IS_THOP_OUT(pti)    ((*((pti)->pThop) & THOP_OUT) == THOP_OUT)

// com\ole32\olethunk\olethk32\thoputil.cxx
#define IS_LDT_SELECTOR(sel) (((sel) & SEL_TI) == SEL_TI)

// com\ole32\olethunk\thc\thc\gen.c
#define is_id_char(c) (isalnum(c) || (c) == '_')

// com\ole32\stg\h\dfmsp.hxx
#define P_INVALID(f)    ((f) & DF_INVALID)

// com\ole32\stg\h\docfilep.hxx
#define CBMAXPATHCOMPLEN (CWCMAXPATHCOMPLEN*sizeof(WCHAR))

// com\ole32\stg\h\lock.hxx
#define IsInRangeLocks(iBegin, cbBuffer)             \
        ((iBegin + cbBuffer > OLOCKREGIONBEGIN) &&   \
         (iBegin <= OLOCKREGIONEND) )

// com\ole32\stg\h\props.hxx
#define ValidatePropSpecKind(psk) \
    (((psk) == PRSPEC_LPWSTR || (psk) == PRSPEC_DISPID || \
      (psk) == PRSPEC_PROPID) ? S_OK : STG_E_INVALIDPARAMETER)

// com\ole32\stg\props\propstm.cxx
    #define RtlEqualString(String1,String2,fCaseInSensitive)    \
        fCaseInSensitive                                        \
            ? ( !_strnicmp( (String1)->Buffer,                  \
                            (String2)->Buffer,                  \
                            (String1)->MaximumLength) )         \
            : ( !strncmp(   (String1)->Buffer,                  \
                            (String2)->Buffer,                  \
                            (String1)->MaximumLength) )
    #define RtlEqualUnicodeString(String1,String2,fCaseInSensitive)         \
        fCaseInSensitive                                                    \
            ? ( !_wcsnicmp( (String1)->Buffer,                              \
                            (String2)->Buffer,                              \
                            (String1)->MaximumLength / sizeof(WCHAR) ))     \
            : ( !wcsncmp(   (String1)->Buffer,                              \
                            (String2)->Buffer,                              \
                            (String1)->MaximumLength / sizeof(WCHAR) ))

// com\ole32\stg\props\utest\proptest.hxx
#   define PropTest_CreateFile(name)   CreateFileA( name, \
                                       GENERIC_READ|GENERIC_WRITE, \
                                       0, NULL, CREATE_ALWAYS,  \
                                       FILE_ATTRIBUTE_NORMAL, \
                                       NULL )

// com\ole32\stg\ref\h\dfmsp.hxx
#define ValidateNameW(pwcs, cchMax) \
    ((pwcs)?(S_OK):(STG_E_INVALIDNAME))
#define ValidateNameA(psz, cchMax) \
    ((psz)?(S_OK):(STG_E_INVALIDNAME))
#define P_INVALID(f)    ((f) & DF_INVALID)

// com\ole32\stg\ref\h\docfilep.hxx
#define CBMAXPATHCOMPLEN (CWCMAXPATHCOMPLEN*sizeof(WCHAR))
#define VALID_IFTHERE(it) \
    ((it) == STG_FAILIFTHERE || (it) == STG_CREATEIFTHERE || \
     (it) == STG_CONVERTIFTHERE)
#define VALID_COMMIT(cf) \
    (((cf) & ~(STGC_OVERWRITE | STGC_ONLYIFCURRENT | \
            STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE)) == 0)
#define VALID_LOCKTYPE(lt) \
    ((lt) == LOCK_WRITE || (lt) == LOCK_EXCLUSIVE || \
     (lt) == LOCK_ONLYONCE)

// com\ole32\stg\ref\h\ole.hxx
#define SAFE_DREF(x) \
       ((x)? (*x) : NULL)

// com\oleutest\cfmex\cfmex.hxx
#define MAX_UNICODE_PATH    ( MAX_PATH * sizeof( WCHAR ))

// com\oleutest\letest\bttncur\bttncur.h
#define ATTRIBUTEBUTTON_INDETERMINATE   (BUTTONGROUP_ACTIVE | BUTTONGROUP_LIGHTFACE)
#define BLANKBUTTON_INDETERMINATE       (BUTTONGROUP_ACTIVE | BUTTONGROUP_BLANK | BUTTONGROUP_LIGHTFACE)

// com\oleutest\letest\gizmobar\gizmobar.h
#define GBM_GIZMOCHECK                  (WM_USER+7)

// com\oleutest\letest\ole2ui\geticon.c
#define IS_SEPARATOR(c)         ( (c) == TEXT(' ') || (c) == TEXT('\\') \
                                  || (c) == TEXT('/') || (c) == TEXT('\t') \
                                  || (c) == TEXT('!') || (c) == TEXT(':') )
#define IS_FILENAME_DELIM(c)    ( (c) == TEXT('\\') || (c) == TEXT('/') \
                                  || (c) == TEXT(':') )

// com\oleutest\letest\ole2ui\insobj.c
#define IS_FILENAME_DELIM(c)    ( (c) == TEXT('\\') || (c) == TEXT('/') || (c) == TEXT(':') )

// com\oleutest\letest\ole2ui\msgfiltr.c
#define IS_SIGNIFICANT_MSG(lpmsg)   \
    (   \
        (PeekMessage((lpmsg), NULL, WM_LBUTTONDOWN, WM_LBUTTONDOWN, \
                 PM_NOREMOVE | PM_NOYIELD)) \
     || (PeekMessage((lpmsg), NULL, WM_LBUTTONDBLCLK, WM_LBUTTONDBLCLK, \
                 PM_NOREMOVE | PM_NOYIELD)) \
     || (PeekMessage((lpmsg), NULL, WM_NCLBUTTONDOWN, WM_NCLBUTTONDOWN, \
                 PM_NOREMOVE | PM_NOYIELD)) \
     || (PeekMessage((lpmsg), NULL, WM_NCLBUTTONDBLCLK, WM_NCLBUTTONDBLCLK, \
                 PM_NOREMOVE | PM_NOYIELD)) \
     || (PeekMessage((lpmsg), NULL, WM_KEYDOWN, WM_KEYDOWN, \
                 PM_NOREMOVE | PM_NOYIELD)) \
     || (PeekMessage((lpmsg), NULL, WM_SYSKEYDOWN, WM_SYSKEYDOWN, \
                 PM_NOREMOVE | PM_NOYIELD)) \
    )

// com\oleutest\letest\ole2ui\suminfo.h
#define SetSumInfFMTID(fmtId) {(fmtId)->Data1=0XF29F85E0; *(long FAR *)&(fmtId)->Data2=0X10684FF9;\
                                *(long FAR *)&(fmtId)->Data4[0]=0X000891AB; *(long FAR *)&(fmtId)->Data4[4]=0XD9B3272B;}
#define FEqSumInfFMTID(fmtId) ((fmtId)->Data1==0XF29F85E0&&*((long FAR *)&(fmtId)->Data2)==0X10684FF9&&\
                                *((long FAR *)&(fmtId)->Data4[0])==0X000891AB&&*((long FAR *)&(fmtId)->Data4[4])==0XD9B3272B)

// com\oleutest\letest\outline\outline.h
#define IS_FILENAME_DELIM(c)    ( (c) == '\\' || (c) == '/' || (c) == ':' )

// com\oleutest\perform\cairole\ui\bm_link.hxx
#define INIT_LINKRESULTS(array) {\
        for (int xx = 0; xx < TEST_MAX_ITERATIONS; xx++)\
        {\
        array[xx].ulBindToSourceNull    = NOTAVAIL;\
        array[xx].ulBindToSourceBindCtx = NOTAVAIL;\
        array[xx].ulBindIfRunning       = NOTAVAIL;\
        array[xx].ulBindIfRunning2      = NOTAVAIL;\
        array[xx].ulUnbindSource        = NOTAVAIL;\
        array[xx].ulUnbindSource2       = NOTAVAIL;\
        array[xx].ulUnbindSource3       = NOTAVAIL;\
        array[xx].ulUpdateNull          = NOTAVAIL;\
        array[xx].ulUpdateBindCtx       = NOTAVAIL;\
        }\
    }

// com\oleutest\perform\common\bmcomm.hxx
#define INIT_RESULTS(array) \
	{ for (int xx=0; xx<TEST_MAX_ITERATIONS; xx++) { array[xx]=NOTAVAIL; }; }
#define ZERO_RESULTS(array) \
	{ for (int xx=0; xx<TEST_MAX_ITERATIONS; xx++) { array[xx]=0; }; }

// com\oleutest\stgbvt\comtools\h\pathgen.hxx
#define MAXFSLEN sizeof(L"HPFS")
#define MIN_BIND_NAME_LEN (sizeof("z.ext") - 1)

// com\oleutest\stgbvt\comtools\memory\ctmem.cxx
#define SIMULATE_FAILURE( dwRes )                               \
            ((NULL != g_psftSiftObject) &&                      \
                    (g_psftSiftObject->SimFail( ( dwRes ) )))

// com\oleutest\stgbvt\ctolestg\common\inc\tdmacros.hxx
#define TD_DECLARETEST(name, ptest, ptestparam, description)\
        hr = g_TestDrv.AddTest(name,                        \
                               ptest,                       \
                               ptestparam,                  \
                               description);                \
        DH_HRCHECK_ABORT(hr, TEXT("CTDTestDrv::AddTest"))
#define TD_DECLAREGROUP(paramlist)                          \
        hr = g_TestDrv.AddGroup paramlist;                  \
        DH_HRCHECK_ABORT(hr, TEXT("CTDTestDrv::AddGroup"))
#define TD_DECLARESWITCH(type, name, defval, description)   \
        hr = g_TestDrv.AddSwitch(type,                      \
                                 name,                      \
                                 defval,                    \
                                 description);              \
        DH_HRCHECK_ABORT(hr, TEXT("CTDTestDrv::AddSwitch"))

// com\rpc\midl\codegen\cgcommon.hxx
#define IS_STANDARD_LOCAL_RESOURCE( ResID )	\
	((ResID >= ST_LOCAL_RESOURCE_START) && (ResID < ST_LOCAL_RESOURCE_END))
#define IS_STANDARD_PARAM_RESOURCE( ResID )	\
	((ResID >= ST_PARAM_RESOURCE_START) && (ResID < ST_PARAM_RESOURCE_END))
#define IS_STANDARD_GLOBAL_RESOURCE( ResID )	\
	((ResID >= ST_GLOBAL_RESOURCE_START) && (ResID < ST_GLOBAL_RESOURCE_END))

// com\rpc\midl\common\cmdana.hxx
#define ERROR_ALL                    (ERROR_BOUNDS_CHECK        |   \
                                     ERROR_ENUM                 |   \
                                     ERROR_ALLOCATION           |   \
                                     ERROR_REF                  |   \
                                     ERROR_STUB_DATA                \
                                     )

// com\rpc\midl\common\stream.cxx
#define MAX_INDENT (sizeof(SpaceBuffer) - 1)
#define MAX_NEWLINES (sizeof(NewLineBuffer) - 1)

// com\rpc\midl\driver\cmdana.cxx
#define IS_NUMERIC_1( pThisArg ) ((strlen( pThisArg) == 1 )  &&  \
                                  (isdigit( *pThisArg )) )

// com\rpc\midl\front\semantic.cxx
#define IS_OLD_INTERPRETER( x ) ( ((x) & OPTIMIZE_INTERPRETER) && !((x) & OPTIMIZE_INTERPRETER_V2) )

// com\rpc\midl\inc\acfattr.hxx
#define IS_ALLOCATE( AllocateType, CheckType )    ( AllocateType & CheckType )

// com\rpc\ndr20\cvtpvt.h
#define U_R_UNUSUAL (U_R_ZERO | U_R_INFINITY | U_R_INVALID)

// com\rpc\ndr20\interp.h
#define MAX_STACK_SIZE              ARGUMENT_COUNT_THRESHOLD * sizeof(double)

// com\rpc\ndr20\ndrp.h
#define CHECK_EOB_RAISE_BSD( p )                                      \
    {                                                                 \
       if( (uchar *)(p) > pStubMsg->BufferEnd )                       \
           {                                                          \
           RpcRaiseException( RPC_X_BAD_STUB_DATA );                  \
           }                                                          \
    }
#define CHECK_EOB_RAISE_IB( p )                                       \
    {                                                                 \
        if( (uchar *)(p) > pStubMsg->BufferEnd )                      \
            {                                                         \
            RpcRaiseException( RPC_X_INVALID_BOUND );                 \
            }                                                         \
    }
#define CHECK_EOB_WITH_WRAP_RAISE_BSD( p, incsize )                   \
    {                                                                 \
        unsigned char *NewBuffer = ((uchar *)(p)) + (SIZE_T)(incsize);\
        if( (NewBuffer > pStubMsg->BufferEnd) || (NewBuffer < (p)) )  \
             {                                                        \
             RpcRaiseException( RPC_X_BAD_STUB_DATA );                \
             }                                                        \
    }
#define CHECK_EOB_WITH_WRAP_RAISE_IB( p, incsize )                    \
    {                                                                 \
        unsigned char *NewBuffer = ((uchar *)(p)) + (SIZE_T)(incsize);\
        if(  (NewBuffer > pStubMsg->BufferEnd) || (NewBuffer < (p)) ) \
             {                                                        \
             RpcRaiseException( RPC_X_INVALID_BOUND );                \
             }                                                        \
    }
#define CHECK_ULONG_BOUND( v )   if ( 0x80000000 & (unsigned long)(v) ) \
                                        RpcRaiseException( RPC_X_INVALID_BOUND );
#define CHECK_SEND_EOB_RAISE_BSD( p )  \
        if ( pStubMsg->RpcMsg->Buffer + pStubMsg->RpcMsg->BufferLength < p ) \
            RpcRaiseException( RPC_X_BAD_STUB_DATA )

// com\rpc\ndr64\ndrp.h
#define CHECK_EOB_RAISE_BSD( p )                                      \
    {                                                                 \
       if( (char *)(p) > (char*)pStubMsg->BufferEnd )                 \
           {                                                          \
           RpcRaiseException( RPC_X_BAD_STUB_DATA );                  \
           }                                                          \
    }
#define CHECK_EOB_RAISE_IB( p )                                       \
    {                                                                 \
        if( (char *)(p) > (char*)pStubMsg->BufferEnd )                \
            {                                                         \
            RpcRaiseException( RPC_X_INVALID_BOUND );                 \
            }                                                         \
    }
#define CHECK_EOB_WITH_WRAP_RAISE_BSD( p, incsize )                          \
    {                                                                        \
        char *NewBuffer = ((char *)(p)) + (SIZE_T)(incsize);                 \
        if( (NewBuffer > (char*)(pStubMsg->BufferEnd)) || (NewBuffer < (char*)(p)) )  \
             {                                                               \
             RpcRaiseException( RPC_X_BAD_STUB_DATA );                       \
             }                                                               \
    }
#define CHECK_EOB_WITH_WRAP_RAISE_IB( p, incsize )                           \
    {                                                                        \
        char *NewBuffer = ((char *)(p)) + (SIZE_T)(incsize);                 \
        if(  (NewBuffer > (char*)(pStubMsg->BufferEnd)) || (NewBuffer < (char*)(p)) ) \
             {                                                               \
             RpcRaiseException( RPC_X_INVALID_BOUND );                       \
             }                                                               \
    }
#define CHECK_SEND_EOB_RAISE_BSD( p )  \
        if ( (char*)(pStubMsg->RpcMsg->Buffer + pStubMsg->RpcMsg->BufferLength) < (char*)( p ) ) \
            RpcRaiseException( RPC_X_BAD_STUB_DATA )
#define NDR64_IS_HANDLE_IN( FC )          ((FC) & HANDLE_PARAM_IS_IN)
#define NDR64_IS_HANDLE_OUT( FC )         ((FC) & HANDLE_PARAM_IS_OUT)

// com\winole\client\dll.h
#define IS_SVRCLOSING(lpobj)\
        ((lpobj->bUnlaunchLater || lpobj->bSvrClosing) ? TRUE : FALSE)

// drivers\ddk\wdmaudio\dmusuart\miniport.cpp
#define CONST_PCNODE_DESCRIPTOR(n)          { 0, NULL, &n, NULL }
#define CONST_PCNODE_DESCRIPTOR_AUTO(n,a)   { 0, &a, &n, NULL }

// drivers\input\kbdclass\kbdclass.h
#define IS_TRUSTED_FILE_FOR_READ(x) (&DriverEntry == (x)->FsContext2)
#define WAITWAKE_SUPPORTED(port) ((port)->MinDeviceWakeState > PowerDeviceD0 && \
                                  (port)->MinSystemWakeState > PowerSystemWorking)
#define SHOULD_SEND_WAITWAKE(port) (WAITWAKE_SUPPORTED(port) && \
                                    !WAITWAKE_ON(port)       && \
                                    KeyboardClassCheckWaitWakeEnabled(port))

// drivers\input\mouclass\mouclass.h
#define IS_TRUSTED_FILE_FOR_READ(x) (&DriverEntry == (x)->FsContext2)
#define WAITWAKE_SUPPORTED(port) ((port)->MinDeviceWakeState > PowerDeviceD0 && \
                                  (port)->MinSystemWakeState > PowerSystemWorking)

// drivers\ksfilter\ks\ksp.h
#define IRP_FRAMING_IRP_STORAGE(Irp) \
    ((PKSPIRP_FRAMING)(&IoGetCurrentIrpStackLocation(Irp)->Parameters))

// drivers\ksfilter\miniport\soundprt\private.h
#define HARDWAREF_FULLDUPLEX_ACTIVE     (HARDWAREF_CAPTURE_ACTIVE | HARDWAREF_PLAYBACK_ACTIVE)

// drivers\net\irda\mknet\sys\wincomm.h
#define ALL_SLOW_IRDA_SPEEDS (							\
	NDIS_IRDA_SPEED_9600  |								\
	NDIS_IRDA_SPEED_19200 | NDIS_IRDA_SPEED_38400 |		\
	NDIS_IRDA_SPEED_57600 | NDIS_IRDA_SPEED_115200)
#define ALL_IRDA_SPEEDS (													\
	ALL_SLOW_IRDA_SPEEDS | NDIS_IRDA_SPEED_576K | NDIS_IRDA_SPEED_1152K |		\
	NDIS_IRDA_SPEED_4M   | NDIS_IRDA_SPEED_16M)

// drivers\net\irda\mknet\sys\winpci.c
    #define RESOURCE_LIST_BUF_SIZE (sizeof(NDIS_RESOURCE_LIST) + (10*sizeof(CM_PARTIAL_RESOURCE_DESCRIPTOR)))

// drivers\net\ms\e100bex\mp_def.h
#define NIC_RESOURCE_BUF_SIZE           (sizeof(NDIS_RESOURCE_LIST) + \
                                        (10*sizeof(CM_PARTIAL_RESOURCE_DESCRIPTOR)))

// drivers\sac\driver\cmd.c
#define IS_WHITESPACE(_ch) ((_ch == ' ') || (_ch == '\t'))
#define IS_NUMBER(_ch) ((_ch >= '0') && (_ch <= '9'))
#define SKIP_WHITESPACE(_pch) \
     while (IS_WHITESPACE(*_pch) && (*_pch != '\0')) { \
        _pch++; \
     }
#define SKIP_NUMBERS(_pch) \
     while (IS_NUMBER(*_pch) && (*_pch != '\0')) { \
        _pch++; \
     }

// drivers\sac\uterm\uterm\terminal.cxx
#define SHIFT_KEY_PRESSED(KeyEvent) \
    (((KeyEvent).dwControlKeyState & (SHIFT_PRESSED))!=0)
#define CTRL_KEY_PRESSED(KeyEvent) \
    (((KeyEvent).dwControlKeyState & (LEFT_CTRL_PRESSED | RIGHT_CTRL_PRESSED))!=0)
#define ALT_KEY_PRESSED(KeyEvent) \
    (((KeyEvent).dwControlKeyState & (LEFT_ALT_PRESSED | RIGHT_ALT_PRESSED))!=0)
#define SHIFT_ACTIVE(KeyEvent)              \
    (SHIFT_KEY_PRESSED(KeyEvent) &&         \
    (!CTRL_KEY_PRESSED(KeyEvent)) &&        \
    (!ALT_KEY_PRESSED(KeyEvent)))
#define CTRL_ACTIVE(KeyEvent)               \
    ((!SHIFT_KEY_PRESSED(KeyEvent)) &&      \
    CTRL_KEY_PRESSED(KeyEvent) &&           \
    (!ALT_KEY_PRESSED(KeyEvent)))
#define ALT_ACTIVE(KeyEvent)                \
    ((!SHIFT_KEY_PRESSED(KeyEvent)) &&      \
    (!CTRL_KEY_PRESSED(KeyEvent)) &&        \
    ALT_KEY_PRESSED(KeyEvent))
#define NONE_ACTIVE(KeyEvent)               \
    ((!SHIFT_KEY_PRESSED(KeyEvent)) &&      \
    (!CTRL_KEY_PRESSED(KeyEvent)) &&        \
    (!ALT_KEY_PRESSED(KeyEvent)))
#define IS_A_SHIFTKEY( KeyEvent ) \
    (((KeyEvent).wVirtualKeyCode == VK_SCROLL) ||

// drivers\serial\mps\comtrol\rocket\driver\opstr.c
#define _IS_STR_DIGIT(c) ((c >= '0') && (c <= '9'))
#define _IS_STR_LET_D(c) ((c == 'D') || (c == 'd'))

// drivers\serial\mps\comtrol\rocket\setup\opstr.c
#define _IS_STR_DIGIT(c) ((c >= '0') && (c <= '9'))
#define _IS_STR_LET_D(c) ((c == 'D') || (c == 'd'))

// drivers\serial\mps\moxa\intellio\admin\inc\mxdef.h
#define I_CPU_MSK   (I_MOXA_DUMB | I_MOXA_INTE)
#define I_BUS_MSK   (I_MOXA_ISA | I_MOXA_PCI)
#define I_IS_EXT    (I_MOXA_CAB | I_MOXA_EXT)
#define I_PORT_MSK   (I_8PORT | I_16PORT | I_24PORT | I_32PORT | I_64PORT)
#define I_MX_C102       (I_MOXA_C102 | I_MOXA_DUMB | I_MOXA_ISA)
#define I_MX_C104       (I_MOXA_C104 | I_MOXA_DUMB | I_MOXA_ISA)
#define I_MX_C168       (I_MOXA_C168 | I_MOXA_DUMB | I_MOXA_ISA)
#define I_MX_CI104J     (I_MOXA_C104J | I_MOXA_DUMB | I_MOXA_ISA)
#define I_MX_C114HI     (I_MOXA_C114HI | I_MOXA_DUMB | I_MOXA_ISA)
#define I_MX_C102PCI    (I_MOXA_C102 | I_MOXA_DUMB | I_MOXA_PCI)
#define I_MX_C104PCI    (I_MOXA_C104 | I_MOXA_DUMB | I_MOXA_PCI)
#define I_MX_C168PCI    (I_MOXA_C168 | I_MOXA_DUMB | I_MOXA_PCI)
#define I_MX_CP104J     (I_MOXA_C104J | I_MOXA_DUMB | I_MOXA_PCI)
#define I_MX_CI132      (I_MOXA_C132 | I_MOXA_DUMB | I_MOXA_ISA)
#define I_MX_CI134      (I_MOXA_C134 | I_MOXA_DUMB | I_MOXA_ISA)
#define I_MX_CP132      (I_MOXA_C132 | I_MOXA_DUMB | I_MOXA_PCI)
#define I_MX_CP114      (I_MOXA_C114 | I_MOXA_DUMB | I_MOXA_PCI)
#define I_MX_CT114      (I_MOXA_CT114 | I_MOXA_DUMB | I_MOXA_PCI)
#define I_MX_CP204     (I_MOXA_C204 | I_MOXA_INTE | I_MOXA_PCI)
#define I_MX_C218       (I_MOXA_C218 | I_MOXA_INTE | I_MOXA_ISA)
#define I_MX_C218T      (I_MOXA_C218T | I_MOXA_INTE | I_MOXA_ISA)
#define I_MX_C218TPCI   (I_MOXA_C218T | I_MOXA_INTE | I_MOXA_PCI)
#define I_MX_C320       (I_MOXA_C320 | I_MOXA_INTE | I_MOXA_ISA | I_MOXA_EXT)
#define I_MX_C320T      (I_MOXA_C320T | I_MOXA_INTE | I_MOXA_ISA | I_MOXA_EXT)
#define I_MX_C320TPCI   (I_MOXA_C320T | I_MOXA_INTE | I_MOXA_PCI | I_MOXA_EXT)
#define I_MX_C3208      (I_MOXA_C320 | I_MOXA_INTE | I_MOXA_ISA | I_8PORT | I_MOXA_EXT)
#define I_MX_C32016     (I_MOXA_C320 | I_MOXA_INTE | I_MOXA_ISA | I_16PORT | I_MOXA_EXT)
#define I_MX_C32024     (I_MOXA_C320 | I_MOXA_INTE | I_MOXA_ISA | I_24PORT | I_MOXA_EXT)
#define I_MX_C32032     (I_MOXA_C320 | I_MOXA_INTE | I_MOXA_ISA | I_32PORT | I_MOXA_EXT)
#define I_MX_C320T8     (I_MOXA_C320T | I_MOXA_INTE | I_MOXA_ISA | I_8PORT | I_MOXA_EXT)
#define I_MX_C320T16    (I_MOXA_C320T | I_MOXA_INTE | I_MOXA_ISA | I_16PORT | I_MOXA_EXT)
#define I_MX_C320T24    (I_MOXA_C320T | I_MOXA_INTE | I_MOXA_ISA | I_24PORT | I_MOXA_EXT)
#define I_MX_C320T32    (I_MOXA_C320T | I_MOXA_INTE | I_MOXA_ISA | I_32PORT | I_MOXA_EXT)
#define I_MX_C320TPCI8  (I_MOXA_C320T | I_MOXA_INTE | I_MOXA_PCI | I_8PORT | I_MOXA_EXT)
#define I_MX_C320TPCI16 (I_MOXA_C320T | I_MOXA_INTE | I_MOXA_PCI | I_16PORT | I_MOXA_EXT)
#define I_MX_C320TPCI24 (I_MOXA_C320T | I_MOXA_INTE | I_MOXA_PCI | I_24PORT | I_MOXA_EXT)
#define I_MX_C320TPCI32 (I_MOXA_C320T | I_MOXA_INTE | I_MOXA_PCI | I_32PORT | I_MOXA_EXT)

// drivers\serial\mps\spx\speed\driver\inc\speedwmi.h
    #define SPX_SPEED_WMI_FIFO_PROP_MaxTxFiFoSize_SIZE sizeof(ULONG)
    #define SPX_SPEED_WMI_FIFO_PROP_MaxRxFiFoSize_SIZE sizeof(ULONG)

// drivers\smartcrd\gempc430\device.h
#define IS_DEVICE_PNP_STATE(_state_)   \
        (this->m_DevicePnPState == _state_)

// drivers\smartcrd\gempc430\syswdm.h
#define DISPOSE_OBJECT(obj) \
		{if((obj!=(VOID *)0))	obj->dispose(); obj = NULL;}

// drivers\smartcrd\gpr400\gprnt.h
#define IS_HANDLE_VALID(h) \
                    ((BOOLEAN) ((h == NULL) ? FALSE : TRUE))

// drivers\storage\cdrom\cdrom.c
#define IS_WRITE_REQUEST(irpStack)                                             \
 (irpStack->MajorFunction == IRP_MJ_WRITE)
#define IS_READ_WRITE_REQUEST(irpStack)                                        \
((irpStack->MajorFunction == IRP_MJ_READ)  ||                                  \
 (irpStack->MajorFunction == IRP_MJ_WRITE) ||                                  \
 ((irpStack->MajorFunction == IRP_MJ_DEVICE_CONTROL) &&                        \
  (irpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_CDROM_RAW_READ)))

// drivers\storage\disk\disk.h
#define DiskIsValidSmartSelfTest(Subcommand) \
    ( ((Subcommand) == SMART_OFFLINE_ROUTINE_OFFLINE) || \
      ((Subcommand) == SMART_SHORT_SELFTEST_OFFLINE) || \
      ((Subcommand) == SMART_EXTENDED_SELFTEST_OFFLINE) )

// drivers\storage\ide\inc\ideuser.h
#define IS_DEFAULT(mode)    (!(mode & 0x80000000))

// drivers\storage\ide\miniport\intel\intel.h
#define IS_ICH0(deviceId)                 (deviceId == ICH0_DEVICE_ID || deviceId == IA64_IDE_CONTROLLER_DEVICE_ID)
#define IS_ICH2(deviceId)                 (IS_ICH2_LOW(deviceId) || IS_ICH2_MOBILE(deviceId) || IS_ICH2_HIGH(deviceId))
#define IS_ICH4(deviceId)                 ((deviceId == ICH4_DEVICE_ID_1) || (deviceId == ICH4_DEVICE_ID_2) || (deviceId == ICH4_DEVICE_ID_3))
#define IS_UDMA33_CONTROLLER(deviceId)    (IS_PIIX4(deviceId) || IS_ICH0(deviceId) || IS_ICH_(deviceId) || IS_SINGLE_IDE(deviceId) || IS_ICH2(deviceId) || IS_ICH3(deviceId) || IS_ICH4(deviceId))
#define IS_UDMA66_CONTROLLER(deviceId)    (IS_ICH_(deviceId) || IS_ICH2(deviceId) || IS_ICH3(deviceId) || IS_ICH4(deviceId))
#define IS_UDMA100_CONTROLLER(deviceId)   (IS_ICH2_MOBILE(deviceId) || IS_ICH2_HIGH(deviceId) || IS_ICH3(deviceId) || IS_ICH4(deviceId))
#define IS_UDMA_CONTROLLER(deviceId)      (IS_UDMA33_CONTROLLER(deviceId) || IS_UDMA66_CONTROLLER(deviceId) || IS_UDMA100_CONTROLLER(deviceId))

// drivers\storage\kdext\minipkd\minipkd.c
#define DumpUcharField(name, value, depth) \
    xdprintfEx((depth), ("%s: 0x%02X\n", (name), (value)))
#define DumpUshortField(name, value, depth) \
    xdprintfEx((depth), ("%s: 0x%04X\n", (name), (value)))
#define DumpUlongField(name, value, depth) \
    xdprintfEx((depth), ("%s: 0x%08X\n", (name), (value)))
#define DumpBooleanField(name, value, depth) \
    xdprintfEx((depth), ("%s: %s\n", (name), (value) ? "YES" : "NO"))

// drivers\storage\kdext\minipkd\pch.h
#define DECLARE_API(extension)     \
CPPMOD HRESULT CALLBACK extension(PDEBUG_CLIENT Client, PCSTR args)

// drivers\storage\port\raid\inc\sldefs.h
#define IN_RANGE(a,b,c) ((a) <= (b) && (b) < (c))

// drivers\storage\port\scsi\miniport\advansys\asc3550\a_advlib.h
#define ASC_PCI_ID2BUS(id)    ((id) & 0xFF)

// drivers\storage\port\scsi\miniport\advansys\asc3550\a_scsi.h
#define SCSI_TYPE_NO_DVC   (SCSI_QUAL_NODVC | SCSI_TYPE_UNKNOWN)
#define ASC_SRB_TID( x )   ( ( uchar )( ( uchar )( x ) & ( uchar )0x0F ) )

// drivers\storage\port\scsi\miniport\advansys\asc\asc.h
#define SEGMENT_LIST_SIZE         MAX_SG_DESCRIPTORS * sizeof(SGD)

// drivers\storage\port\scsi\miniport\advansys\asc\asc1000.h
#define IFC_INIT_DEFAULT  ( IFC_ACT_NEG | IFC_REG_UNLOCK )
#define ASC_GET_EISA_SLOT( iop )  ( PortAddr )( (iop) & 0xF000 ) /* get EISA slot number */

// drivers\storage\port\scsi\miniport\advansys\asc\ascdef.h
#define ASC_PCI_ID2BUS( id )    ((id) & 0xFF)

// drivers\storage\port\scsi\miniport\advansys\asc\ascdep.h
#define ASC_CHIP_VER_PCI_ULTRA_3150  (ASC_CHIP_VER_PCI | 0x02)
#define ASC_CHIP_VER_PCI_ULTRA_3050  (ASC_CHIP_VER_PCI | 0x03)

// drivers\storage\port\scsi\miniport\advansys\asc\ascsidef.h
#define ASC_SRB_TID( x )   ( ( uchar )( ( uchar )( x ) & ( uchar )0x0F ) )

// drivers\storage\port\scsi\miniport\advansys\asc\aspiq.h
#define ASC_TIX_TO_TID( tix )         ( (tix) & ASC_MAX_TID )
#define ASC_TID_TO_TIX( tid )         ( (tid) & ASC_MAX_TID )

// drivers\storage\port\scsi\miniport\agilent\afc\cstate.h
#define ROLL(index, end)    index=((index+1) & (end-1))
#define NEXT_INDEX(index, end)    ((index+1) & (end-1))

// drivers\storage\port\scsi\miniport\agilent\afc\fccint.h
#define FCCI_DRIVER_INFO_DEFAULT_SIZE (sizeof(FCCI_DRIVER_INFO) + (sizeof(WCHAR) * 32) * 4)
#define FCCI_ADAPTER_INFO_DEFAULT_SIZE (sizeof(FCCI_ADAPTER_INFO) + (sizeof(WCHAR) * 32) * 4)

// drivers\storage\port\scsi\miniport\agilent\afc\fcmain.h
#define NEXT_INDEX(index, end)    ((index+1) & (end-1))
#define ERQ_FULL(prodIndex, conIndex, ERQ_LEN) \
                (NEXT_INDEX(prodIndex, ERQ_LEN) == conIndex) ? agTRUE : agFALSE

// drivers\storage\port\scsi\miniport\agilent\afc\fwstub.h
#define FWStub_Global_NonDMA(agR) \
            ((FWStub_Global_NonDMA_t *)(((agRoot_t *)agR)->fcData))
#define FWStub_IO_NonDMA_from_agIORequest(agR) \
            ((FWStub_IO_NonDMA_t *)(((agIORequest_t *)agR)->fcData))
#define FWStub_IO_NonDMA(Glob,ReqID) \
            ((FWStub_IO_NonDMA_t *)(&(((FWStub_Global_NonDMA_t *)(Glob))->IOs[(((ReqID) & ~agRpcReqIDFast) - 1)])))
#define FWStub_IO_DMA(Glob,ReqID) \
            ((FWStub_IO_DMA_t *)(&(((FWStub_Global_DMA_t *)(Glob))->IOs[(((ReqID) & ~agRpcReqIDFast) - 1)])))
#define FWStub_IO_DMA_FCP_CMND(IO) \
            ((FC_FCP_CMND_Payload_t *)(&(((FWStub_IO_DMA_t *)(IO))->ReqDoSCSI.FCP_CMND)))
#define FWStub_IO_DMA_SGL(IO) \
            ((agRpcSGL_t *)(&(((FWStub_IO_DMA_t *)(IO))->ReqDoSCSI.SGL[0])))

// drivers\storage\port\scsi\miniport\agilent\afc\globals.h
#define agBIOS_Config_Size                  sizeof(agBiosConfig_s)

// drivers\storage\port\scsi\miniport\agilent\afc\hppif3p.h
#define LCS_HPP_POWER_UP (LCS_HBA_INIT               |    \
               LCS_HBA_READY_ACTIVE)

// drivers\storage\port\scsi\miniport\agilent\afc\ip.h
#define fiComputeBroadcast_D_ID(CThread)            \
    (   CThread->ChanInfo.CurrentAddress.Domain     \
     || CThread->ChanInfo.CurrentAddress.Area   ?   \
       FC_Well_Known_Port_ID_Broadcast_Alias_ID :   \
       FC_Broadcast_Replicate_AL_PA               )

// drivers\storage\port\scsi\miniport\agilent\afc\mapping.h
#define OSDATA_SIZE			(sizeof(CARD_EXTENSION))
#define SET_PA_LUN(plun, pathId, targetId, lun) \
             plun->lun_pd[0].Address_mode = PERIPHERAL_ADDRESS; \
             plun->lun_pd[0].Bus_number = 0;    \
             plun->lun_pd[0].Lun = (UCHAR)lun;
#define SET_VS_LUN(plun, pathId, targetId, lun) \
             plun->lun_vs[0].Address_mode = VOLUME_SET_ADDRESS; \
             plun->lun_vs[0].Lun_hi = 0; \
             plun->lun_vs[0].Lun = (UCHAR)lun;

// drivers\storage\port\scsi\miniport\agilent\afc\memmap.h
#define MemMap_NumLOOPDeviceMAP_MIN          sizeof(FC_ELS_LoopInit_AL_PA_Position_Map_Payload_t)
#define MemMap_NumLOOPDeviceMAP_MAX          sizeof(FC_ELS_LoopInit_AL_PA_Position_Map_Payload_t)
#define MemMap_NumLOOPDeviceMAP_DEFAULT      sizeof(FC_ELS_LoopInit_AL_PA_Position_Map_Payload_t)

// drivers\storage\port\scsi\miniport\agilent\afc\ntdebug.h
#define EXTERNAL_DEBUG_LEVEL   0 // (DBG_MODERATE_DETAIL | CS_DURING_ANY)

// drivers\storage\port\scsi\miniport\agilent\afc\queue.h
#define fiListInitHdr(hdr)                                  \
          {                                                 \
            ((fiList_t *)(hdr))->flink = (fiList_t *)(hdr); \
            ((fiList_t *)(hdr))->blink = (fiList_t *)(hdr); \
          }
#define fiListEnqueueAtHead(toAddHdr,listHdr)                                       \
          {                                                                         \
            ((fiList_t *)(toAddHdr))->flink       = ((fiList_t *)(listHdr))->flink; \
            ((fiList_t *)(toAddHdr))->blink       =  (fiList_t *)(listHdr);         \
            ((fiList_t *)(listHdr))->flink->blink =  (fiList_t *)(toAddHdr);        \
            ((fiList_t *)(listHdr))->flink        =  (fiList_t *)(toAddHdr);        \
          }
#define fiListEnqueueAtTail(toAddHdr,listHdr)                                       \
          {                                                                         \
            ((fiList_t *)(toAddHdr))->flink       =  (fiList_t *)(listHdr);         \
            ((fiList_t *)(toAddHdr))->blink       = ((fiList_t *)(listHdr))->blink; \
            ((fiList_t *)(listHdr))->blink->flink =  (fiList_t *)(toAddHdr);        \
            ((fiList_t *)(listHdr))->blink        =  (fiList_t *)(toAddHdr);        \
          }
#define fiListEmpty(hdr) \
          (((fiList_t *)(hdr))->flink == ((fiList_t *)(hdr)))
#define fiListNotEmpty(hdr) \
          (((fiList_t *)(hdr))->flink != ((fiList_t *)(hdr)))
#define fiListEnqueueListAtHeadFast(toAddListHdr,listHdr)                                     \
          {                                                                                   \
            ((fiList_t *)(toAddListHdr))->blink->flink = ((fiList_t *)(listHdr))->flink;      \
            ((fiList_t *)(toAddListHdr))->flink->blink =  (fiList_t *)(listHdr);              \
            ((fiList_t *)(listHdr))->flink->blink      = ((fiList_t *)(toAddListHdr))->blink; \
            ((fiList_t *)(listHdr))->flink             = ((fiList_t *)(toAddListHdr))->flink; \
            fiListInitHdr(toAddListHdr);                                                      \
          }
#define fiListEnqueueListAtTailFast(toAddListHdr,listHdr)                                     \
          {                                                                                   \
            ((fiList_t *)(toAddListHdr))->blink->flink =  (fiList_t *)(listHdr);              \
            ((fiList_t *)(toAddListHdr))->flink->blink = ((fiList_t *)(listHdr))->blink;      \
            ((fiList_t *)(listHdr))->blink->flink      = ((fiList_t *)(toAddListHdr))->flink; \
            ((fiList_t *)(listHdr))->blink             = ((fiList_t *)(toAddListHdr))->blink; \
            fiListInitHdr(toAddListHdr);                                                      \
          }
#define fiListDequeueThis(hdr) \
          {                                                                 \
            ((fiList_t *)(hdr))->blink->flink = ((fiList_t *)(hdr))->flink; \
            ((fiList_t *)(hdr))->flink->blink = ((fiList_t *)(hdr))->blink; \
            fiListInitElement(hdr);                                         \
          }
#define fiListDequeueThis(hdr) \
          {                                                                 \
            ((fiList_t *)(hdr))->blink->flink = ((fiList_t *)(hdr))->flink; \
            ((fiList_t *)(hdr))->flink->blink = ((fiList_t *)(hdr))->blink; \
          }
#define fiListDequeueFromHeadFast(atHeadHdr,listHdr)                                         \
          {                                                                                  \
              *((fiList_t **)atHeadHdr)                =   ((fiList_t *)listHdr)->flink;     \
             (*((fiList_t **)atHeadHdr))->flink->blink =    (fiList_t *)listHdr;             \
               ((fiList_t  *)listHdr)->flink           = (*((fiList_t **)atHeadHdr))->flink; \
            fiListInitElement(*atHeadHdr);                                                   \
          }
#define fiListDequeueFromHeadFast(atHeadHdr,listHdr)                                         \
          {                                                                                  \
              *((fiList_t **)atHeadHdr)                =   ((fiList_t *)listHdr)->flink;     \
             (*((fiList_t **)atHeadHdr))->flink->blink =    (fiList_t *)listHdr;             \
               ((fiList_t  *)listHdr)->flink           = (*((fiList_t **)atHeadHdr))->flink; \
          }
#define fiListDequeueFromTailFast(atTailHdr,listHdr)                                        \
          {                                                                                 \
             *((fiList_t **)atTailHdr)                =   ((fiList_t *)listHdr)->blink;     \
            (*((fiList_t **)atTailHdr))->blink->flink =    (fiList_t *)listHdr;             \
              ((fiList_t  *)listHdr)->blink           = (*((fiList_t **)atTailHdr))->blink; \
            fiListInitElement(*atTailHdr);                                                   \
          }
#define fiListDequeueFromTailFast(atTailHdr,listHdr)                                        \
          {                                                                                 \
             *((fiList_t **)atTailHdr)                =   ((fiList_t *)listHdr)->blink;     \
            (*((fiList_t **)atTailHdr))->blink->flink =    (fiList_t *)listHdr;             \
              ((fiList_t  *)listHdr)->blink           = (*((fiList_t **)atTailHdr))->blink; \
          }

// drivers\storage\port\scsi\miniport\agilent\afc\state.h
#define fiSetEventRecordNull(eventRecord) \
    ((eventRecord_t *)(eventRecord))->thread = (fi_thread__t *)agNULL

// drivers\storage\port\scsi\miniport\aha154x\aha154x.h
#define SEGMENT_LIST_SIZE         MAX_SG_DESCRIPTORS * sizeof(SGD)
#define CCB_SIZE sizeof(CCB)

// drivers\storage\port\scsi\miniport\atapi\atapi.h
#define IDENTIFY_DATA_SIZE sizeof(IDENTIFY_DATA)
#define IS_RDP(OperationCode)\
    ((OperationCode == SCSIOP_ERASE)||\
    (OperationCode == SCSIOP_LOAD_UNLOAD)||\
    (OperationCode == SCSIOP_LOCATE)||\
    (OperationCode == SCSIOP_REWIND) ||\
    (OperationCode == SCSIOP_SPACE)||\
    (OperationCode == SCSIOP_SEEK)||\
    (OperationCode == SCSIOP_WRITE_FILEMARKS))

// drivers\storage\port\scsi\miniport\hbaapi_sample\wmi.c
#define CopyString(field, string, length) \
{ \
    PWCHAR p = field; \
    *p++ = length*sizeof(WCHAR); \
    ScsiPortMoveMemory(p, string, length*sizeof(WCHAR)); \
}

// drivers\storage\port\scsi\miniport\ibm\cbidf\atapi.h
#define IDENTIFY_DATA_SIZE sizeof(IDENTIFY_DATA)
#define IS_RDP(OperationCode)\
    ((OperationCode == SCSIOP_ERASE)||\
    (OperationCode == SCSIOP_LOAD_UNLOAD)||\
    (OperationCode == SCSIOP_LOCATE)||\
    (OperationCode == SCSIOP_REWIND) ||\
    (OperationCode == SCSIOP_SPACE)||\
    (OperationCode == SCSIOP_SEEK)||\
    (OperationCode == SCSIOP_WRITE_FILEMARKS))

// drivers\storage\port\scsi\miniport\megaide\hyperdisk.h
#define IDENTIFY_DATA_SIZE sizeof(IDENTIFY_DATA)
#define IS_RDP(OperationCode)\
    ((OperationCode == SCSIOP_ERASE)||\
    (OperationCode == SCSIOP_LOAD_UNLOAD)||\
    (OperationCode == SCSIOP_LOCATE)||\
    (OperationCode == SCSIOP_REWIND) ||\
    (OperationCode == SCSIOP_SPACE)||\
    (OperationCode == SCSIOP_SEEK)||\
    (OperationCode == SCSIOP_WRITE_FILEMARKS))
#define TARGET_ID_WITHOUT_CONTROLLER_ID(ulDrvInd)   (ulDrvInd & 0x03)
#define DRIVE_HAS_COMMANDS(PhysicalDrive)   \
        (PhysicalDrive->ucHead != PhysicalDrive->ucTail)
#define FEED_ALL_CHANNELS(DeviceExtension)                              \
            {                                                           \
                ULONG ulChannel;                                        \
                for(ulChannel=0;ulChannel<MAX_CHANNELS_PER_CONTROLLER;ulChannel++)     \
                    StartChannelIo(DeviceExtension, ulChannel);         \
            }

// drivers\storage\port\scsi\miniport\megaraid\bios.h
#define  PCI_LOCATION_FUNC_NUMBER(pciLocation) (pciLocation & 0x07)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\io\mdacdrv.c
#define mdac_ttbuftblend (&mdac_ttbuftbl[MDAC_MAXTTBUFS])
#define rdcmdp    (&rqp->rq_DacCmd)
#define mdac_newctlfound() \
{ \
	if (mda_Controllers < MDAC_MAXCONTROLLERS) \
	{ \
		ctp++; \
		mda_Controllers++; \
		mdac_lastctp = &mdac_ctldevtbl[mda_Controllers]; \
	} \
	else \
		mda_TooManyControllers++; \
}
#define qreq(ctp,rqp) \
{ \
	MLXSTATS(ctp->cd_CmdsWaited++;) \
	ctp->cd_CmdsWaiting++; \
	if (ctp->cd_FirstWaitingReq) ctp->cd_LastWaitingReq->rq_Next = rqp; \
	else ctp->cd_FirstWaitingReq = rqp; \
	ctp->cd_LastWaitingReq = rqp; \
	rqp->rq_Next = NULL; \
}
#define dqreq(ctp,rqp) \
	if (rqp=ctp->cd_FirstWaitingReq) \
	{       /* remove the request from chain */ \
		ctp->cd_FirstWaitingReq = rqp->rq_Next; \
		ctp->cd_CmdsWaiting--; \
	}
#define pdqreq(ctp,rqp,pdp) \
{ \
	MLXSTATS(ctp->cd_SCDBWaited++;) \
	ctp->cd_SCDBWaiting++; \
	if (pdp->pd_FirstWaitingReq) pdp->pd_LastWaitingReq->rq_Next = rqp; \
	else pdp->pd_FirstWaitingReq = rqp; \
	pdp->pd_LastWaitingReq = rqp; \
	rqp->rq_Next = NULL; \
}
#define mdac_setcmd_v2x(ctp) \
{ \
	ctp->cd_InquiryCmd = DACMD_INQUIRY_V2x; \
	ctp->cd_ReadCmd = DACMD_READ_V2x; \
	ctp->cd_WriteCmd = DACMD_WRITE_V2x; \
	ctp->cd_SendRWCmd = mdac_send_rwcmd_v2x; \
	ctp->cd_SendRWCmdBig = mdac_send_rwcmd_v2x_big; \
}
#define mdac_setcmd_v3x(ctp) \
{ \
	ctp->cd_InquiryCmd = DACMD_INQUIRY_V3x; \
	ctp->cd_ReadCmd = DACMD_READ_OLD_V3x; \
	ctp->cd_WriteCmd = DACMD_WRITE_OLD_V3x; \
	ctp->cd_SendRWCmd = mdac_send_rwcmd_v3x; \
	ctp->cd_SendRWCmdBig = mdac_send_rwcmd_v3x_big; \
}
#define mdac_setcmd_new(ctp) \
{ \
	ctp->cd_InquiryCmd = MDACIOCTL_GETCONTROLLERINFO; \
	ctp->cd_ReadCmd = UCSCMD_EREAD; \
	ctp->cd_WriteCmd = UCSCMD_EWRITE; \
	ctp->cd_SendRWCmd = NULL; \
	ctp->cd_SendRWCmdBig = mdac_send_newcmd_big; \
}
#define mdac_ck64mb(x,y)        (((x) & 0xFC000000) != ((y) & 0xFC000000))
#define dsmdcmdp        (&dsmrqp->rq_DacCmd)
#define dsmdcdbp        (&dsmrqp->rq_scdb)
#define dsmncmdp        ((mdac_commandnew_t MLXFAR *)&dsmrqp->rq_DacCmdNew)
#define mdac_datarel_blkno(iosp) ((iosp->drlios_randlimit) ? \
	mdac_datarel_rand(iosp)*iosp->drlios_maxblksperio : iosp->drlios_nextblkno)
#define rwp     (&rwsp->drlrwst_rwtest)
#define CCSETIOSIZE(rqp,dcp) \
	if ((dcp->drlcp_opsizeblks - rqp->rq_BlkNo) < dcp->drlcp_blksperio)\
		rqp->rq_DataSize=drl_dbtob(dcp->drlcp_opsizeblks-rqp->rq_BlkNo);
#define CCSETDEV(rqp,dev) \
{       /* setup the device information */ \
	rqp->rq_Dev = dev; \
	rqp->rq_ctp = mdac_datarel_dev2ctp(dev); \
	rqp->rq_ControllerNo=drl_ctl(dev);rqp->rq_ChannelNo=drl_ch(dev); \
	rqp->rq_TargetID=drl_tgt(dev); rqp->rq_SysDevNo=drl_sysdev(dev); \
}

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\io\mlxprint.c
#define spr_fieldlen(type) \
	((sizeof(type) + sizeof(spr_va_type) - 1) & ~(sizeof(spr_va_type) - 1))

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\dac960if.h
#define	mdac_sglist64b_s	sizeof(mdac_sglist64b_t)
#define	dac_faultsignature_s	sizeof(dac_faultsignature_t)
#define	dac_phys_dead_drive_s	sizeof(dac_phys_dead_drive_t)
#define	dac_flash_image_record_s	sizeof(dac_flash_image_record_t)
#define	dac_flash_record_s	sizeof(dac_flash_record_t)
#define	dac_file_imghdr_s	sizeof(dac_file_imghdr_t)
#define	file_img_node_s		sizeof(file_img_node_t)
#define	ctlr_info_node_s	sizeof(ctlr_info_node_t)
#define	dac_inquiryrest_s	sizeof(dac_inquiryrest_t)
#define	dac_inquiry2x_s	sizeof(dac_inquiry2x_t)
#define	dac_inquiry3x_s	sizeof(dac_inquiry3x_t)
#define	dac_inquiry2_s	sizeof(dac_inquiry2_t)
#define	DAC_AEMI_ALL_FAULT		(DAC_AEMI_POWER_FAULT|DAC_AEMI_FAN_FAULT|DAC_AEMI_TEMPERATURE_FAULT)	/* DAC_AEMI_POWER_FAN_TEMPERATURE_FAULT */
#define	DAC_STWK_FAULT			(DAC_STWK_FAULT_CH0|DAC_STWK_FAULT_CH1|DAC_STWK_FAULT_CH2)
#define	dac_command_s	sizeof(dac_command_t)
#define	mdac_commandnew_s	sizeof(mdac_commandnew_t)
#define	mdac_newcmdsglist_s	sizeof(mdac_newcmdsglist_t)
#define	dac_scdb_s	sizeof(dac_scdb_t)
#define	dac_sd_info_s	sizeof(dac_sd_info_t)
#define	dac_phys_dev_state_s	sizeof(dac_phys_dev_state_t)
#define	dac_phys_dev_statistics_s	sizeof(dac_phys_dev_statistics_t)
#define	dac_sys_dev_statistics_s	sizeof(dac_sys_dev_statistics_t)
#define	dac_ctl_error_s	sizeof(dac_ctl_error_t)
#define	dac_config2_s	sizeof(dac_config2_t)
#define	DACF2_SPEED_10MHZNEW	(DACF2_SPEED_10MHZ|DACF2_F20_DISABLE)
#define	dac_addcap_s	sizeof(dac_addcap_t)
#define	dac_getibbuinfo_s	sizeof(dac_getibbuinfo_t)
#define dac_getaasinfo_s   sizeof(dac_getaasinfo_t)
#define	dacfg_spandev_v2x_s	sizeof(dacfg_spandev_v2x_t)
#define	dacfg_spandev_v3x_s	sizeof(dacfg_spandev_v3x_t)
#define	dacfg_arm_v2x_s	sizeof(dacfg_arm_v2x_t)
#define	dacfg_sysdevinfo_v2x_s	sizeof(dacfg_sysdevinfo_v2x_t)
#define	dacfg_sysdevinfo_v3x_s	sizeof(dacfg_sysdevinfo_v3x_t)
#define	dacfg_physdevinfo_v2x_s	sizeof(dacfg_physdevinfo_v2x_t)
#define	dac_config_v2x_s	sizeof(dac_config_v2x_t)
#define	dac_config_v3x_s	sizeof(dac_config_v3x_t)
#define	dac_diskconfig_v3x_s	sizeof(dac_diskconfig_v3x_t)
#define	dac_sysphysdev_s	sizeof(dac_sysphysdev_t)
#define	dactype_ishba(dactype)	((dactype) & DACTYPE_HBA) /* is HBA adater */
#define	dactype_isdacscsi(dt)	(((dt)>=DACTYPE_EXPRO_LO) && ((dt)<=DACTYPE_EXPRO_HI))
#define	IsExProFibreHost(dt)    ( (dt)==DACTYPE_DAC960SF  || (dt)==DACTYPE_DAC960FL  ||\
                                  (dt)==DACTYPE_DAC960FF  || (dt)==DACTYPE_DAC960HP  ||\
                                  (dt)==DACTYPE_DAC960MFL || (dt)==DACTYPE_DAC960MFF ||\
                                  (dt)==DACTYPE_DAC960FFX   )
#define	IsExProFibreDev(dt)     ( (dt)==DACTYPE_DAC960FF || (dt)==DACTYPE_DAC960FFX )
#define	IsExProLvdDev(dt)       ( (dt)==DACTYPE_DAC960FL || (dt)==DACTYPE_DAC960LL ||\
                                  (dt)==DACTYPE_DAC960HP || (dt)==DACTYPE_DAC960MFL     )
#define	dac_biosinfo_s	sizeof(dac_biosinfo_t)
#define	dac_hwfwclock_s	sizeof(dac_hwfwclock_t)
#define	dac_altmap_s	sizeof(dac_altmap_t)
#define	dac_bdt_sd_s	sizeof(dac_bdt_sd_t)
#define dac_config_label_s sizeof(dac_config_label_t)
#define	dac_brconfig_v3x_s	sizeof(dac_brconfig_v3x_t)
#define dac_clustercontrol_s    sizeof(dac_clustercontrol_t)
#define	mdacfsi_ctldev_info_s	sizeof(mdacfsi_ctldev_info_t)
#define	mdacfsi_physdev_info_s	sizeof(mdacfsi_physdev_info_t)
#define	mdacfsi_physdev_stats_s	sizeof(mdacfsi_physdev_stats_t)
#define	mdacfsi_ctldev_stats_s	sizeof(mdacfsi_ctldev_stats_t)
#define	mdacfsi_physdev_definition_s	sizeof(mdacfsi_physdev_definition_t)
#define	mdacfsi_raiddevuse_definition_s	sizeof(mdacfsi_raiddevuse_definition_t)
#define	mdacfsi_raiddev_definition_s	(sizeof(mdacfsi_raiddev_definition_t) - mdacfsi_raiddevuse_definition_s)
#define	mdacfsi_reqsense_info_s	sizeof(mdacfsi_reqsense_info_t)
#define	mdacfsi_event_info_s	sizeof(mdacfsi_event_info_t)
#define	mdacfsi_physdev_parameters_s	sizeof(mdacfsi_physdev_parameters_t)
#define mdacfsi_ctldev_parameter_s sizeof(mdacfsi_ctldev_parameter_t)
#define mdacfsi_NVRAM_event_info_s sizeof(mdacfsi_NVRAM_event_info_t)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\drlapi.h
#define	drl_lun(dev)	(((dev)    )&0xFF)
#define	drl_sysdev(dev)	(((dev)    )&0xFF)
#define	drl_isscsidev(dev) ((dev) & 0x00800000)	/* check channel no */
#define	drl_isosinterface(dev) ((dev) & 0x00400000)	/* if OS interface */
#define	DRLIOC_INOUT	(DRLIOC_IN|DRLIOC_OUT)
#define	_DRLIOR(x,y,t)	_DRLIOC(DRLIOC_OUT,x,y,sizeof(t))
#define	_DRLIOW(x,y,t)	_DRLIOC(DRLIOC_IN,x,y,sizeof(t))
#define	_DRLIOWR(x,y,t)	_DRLIOC(DRLIOC_INOUT,x,y,sizeof(t))
#define	drlrwtest_s	sizeof(drlrwtest_t)
#define	drlcpustart_s	sizeof(drlcpustart_t)
#define	drlcpustat_s	sizeof(drlcpustat_t)
#define	drlcsw_s	sizeof(drlcsw_t)
#define	drldocsw_s	sizeof(drldocsw_t)
#define	drlcopy_s	sizeof(drlcopy_t)
#define	drldevsize_s	sizeof(drldevsize_t)
#define	drl_version_s	sizeof(drl_version_t)
#define	DRLOPS_ANYSTOP	(DRLOPS_STOP|DRLOPS_SIGSTOP|DRLOPS_ERR|DRLOPS_USERSTOP)
#define	uxblktodevno(iosp,uxblk) \
	(((uxblk) / iosp->drlios_maxblksperio) % iosp->drlios_devcnt)
#define	pduxblk(iosp,uxblk) \
	((iosp->drlios_devcnt == 1)? uxblk : \
	(((uxblk)/iosp->drlios_maxcylszuxblk)*iosp->drlios_maxblksperio))

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\hppif3p.h
#define LCS_HPP_POWER_UP (LCS_HBA_INIT			|	\
			  LCS_HBA_READY_ACTIVE)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mbvdef.h
#define hex2dec(x)	(((x) >= '0' && (x) <= '9') ? (x) - 0x30 : (x) - 0x37)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mdacapi.h
#define	mda_controller_info_s	sizeof(mda_controller_info_t)
#define	mda_controller_info_s	sizeof(mda_controller_info_t)
#define	mda_physdev_stat_s	sizeof(mda_physdev_stat_t)
#define	mda_sysinfo_s		sizeof(mda_sysinfo_t)
#define	mda_user_cmd_s	sizeof(mda_user_cmd_t)
#define	mda_user_ncmd_s	sizeof(mda_user_ncmd_t)
#define	mda_user_cdb_s	sizeof(mda_user_cdb_t)
#define	mda_gamfuncs_s	sizeof(mda_gamfuncs_t)
#define	mda_gamfuncs_s	sizeof(mda_gamfuncs_t)
#define	mda_setgamfuncs_s	sizeof(mda_setgamfuncs_t)
#define	mda_ctlsysperfdata_s	sizeof(mda_ctlsysperfdata_t)
#define	mda_biosinfo_s	sizeof(mda_biosinfo_t)
#define	mda_activecmd_info_s	sizeof(mda_activecmd_info_t)
#define	mda_pcislot_info_s	sizeof(mda_pcislot_info_t)
#define	mda_sizelimit_info_s	sizeof(mda_sizelimit_info_t)
#define	mda_macdiskfunc_s	sizeof(mda_macdiskfunc_t)
#define	mda_setmacdiskfunc_s	sizeof(mda_setmacdiskfunc_t)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mdacdrv.h
#define ndevtolun(devno)        (((devno)&0xFF)
#define mdac_cmdid(st)  (((st)) & 0xFFFF)       /* get command id part */
#define mdac_pcicfg_s   sizeof(mdac_pcicfg_t)
#define mlxpci_cfg2vid(cfgp)            ((cfgp)->pcfg_DevVid & 0xFFFF)
#define mlxpci_cfg2subvid(cfgp)         ((cfgp)->pcfg_SubSysVid & 0xFFFF)
#define mlxpci_cfg2cmd(cfgp)            ((cfgp)->pcfg_CmdStat & 0xFFFF)
#define mlxpci_cfg2revid(cfgp)          ((cfgp)->pcfg_CCRevID & 0xFF)
#define mlxpci_cfg2cachelinesize(cfgp)  ((cfgp)->pcfg_BHdrLCache&0xFF)
#define mlxpci_cfg2interruptline(cfgp)  ((cfgp)->pcfg_BCIPIL&0xFF)
#define mdac_cmdid_s    sizeof(mdac_cmdid_t)
#define mdac_sglist_s   sizeof(mdac_sglist_t)
#define mdac_req_s      sizeof(mdac_req_t)
#define mdac_req_s      sizeof(mdac_req_t)
#define rq_sglist_s ((sizeof(mdac_sglist_t)) * MDAC_MAXSGLISTSIZE)
#define mdac_physdev_s  sizeof(mdac_physdev_t)
#define mdac_ctldev_s   sizeof(mdac_ctldev_t)
#define mdac_ctldev_s   sizeof(mdac_ctldev_t)
#define mdac_pldev_s    sizeof(mdac_pldev_t)
#define mda_sizelimit_s sizeof(mda_sizelimit_t)
#define mdac_ttbuf_s    sizeof(mdac_ttbuf_t)
#define mdac_reqsense_s sizeof(mdac_reqsense_t)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mdacntd.h
#define memfrag_s       sizeof(memfrag_t)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mdrvos.h
		#define	mlx_kvtophyset(dest,ctp,dp) *((SCSI_PHYSICAL_ADDRESS *)&(dest))=mlx_kvtophys3(ctp,dp)
		#define	mlx_kvtophyset(dest,ctp,dp) *((PHYSICAL_ADDRESS *)&(dest))=MmGetPhysicalAddress((PVOID)(dp))
#define	mlx_kvtophyset2(dest,ctp,dp,srb,len)  *((SCSI_PHYSICAL_ADDRESS *)&(dest))=mdacnt_kvtophys2(ctp,dp,srb,len)
#define MLXSPL()                                                        \
        if ((oldIrqLevel = KeGetCurrentIrql()) < mdac_irqlevel)       \
        {                                                               \
                KeRaiseIrql(mdac_irqlevel, &oldIrqLevel);             \
                irqRaised = TRUE;                                       \
        }
#define mdacnw_device_s sizeof(mdacnw_device_t)
#define mdac_dosreq_s   sizeof(mdac_dosreq_t)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mlxperf.h
#define	mlxperf_minorversion(x)	((x)&0x0F)
#define	mlxperf_header_s	sizeof(mlxperf_header_t)
#define	mlxperf_hd_s	sizeof(mlxperf_hd_t)
#define	mlxperf_getctl(hp)	((hp)->MlxPerfCtlChan&0x1F) /* get controller */
#define	mlxperf_signature_s	sizeof(mlxperf_signature_t)
#define	mlxperf_version_s	sizeof(mlxperf_version_t)
#define	mlxperf_creationday_s	sizeof(mlxperf_creationday_t)
#define	mlxperf_reserved_s	sizeof(mlxperf_reserved_t)
#define	mlxperf_pause_s	sizeof(mlxperf_pause_t)
#define	mlxperf_systemip_s	sizeof(mlxperf_systemip_t)
#define	mlxperf_systeminfo_s		sizeof(mlxperf_systeminfo_t)
#define	mlxperf_ctldevinfo_s		sizeof(mlxperf_ctldevinfo_t)
#define	mlxperf_physdevinfo_s		sizeof(mlxperf_physdevinfo_t)
#define	mlxperf_sysdevinfo_s		sizeof(mlxperf_sysdevinfo_t)
#define	mlxperf_driver_s	sizeof(mlxperf_driver_t)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mlxscsi.h
#define	UCSGETCMD(cdbp)		((cdbp)->ucs_cmd & 0x1F)
#define	UCSGETG0TAG(cdbp)	((cdbp)->g0_addr2 & 0x1F)
#define	UCSGETG1TAG(cdbp)	((cdbp)->g1_reladdr & 0x1F)
#define	UCSGETG5TAG(cdbp)	((cdbp)->g5_reladdr & 0x1F)
#define	UCSMAKECOM_DACMD(cdbp, cmd, count) \
		(UCSMAKECOM_G1(cdbp, UCSCSI_DCMD, 0, 0, count), \
		(cdbp)->g1_addr3 = cmd)
#define	ucscsi_inquiry_s	sizeof(ucscsi_inquiry_t)
#define	ucsdrv_capacity_s	sizeof(ucsdrv_capacity_t)
#define	ucscsi_sense_s	sizeof(ucscsi_sense_t)
#define	ucscsi_exsense_s	sizeof(ucscsi_exsense_t)
#define	UCSKS_VALID(sep)	((sep)->es_skey_specific[0] & 0x80)
#define	UCST_INTERMEDIATE_MET		(UCST_INTERMEDIATE|UCST_MET)
#define	UCST_RESERVATION_CONFLICT	(UCST_INTERMEDIATE|UCST_BUSY)
#define	UCST_TERMINATED			(UCST_SCSI2|UCST_CHECK)
#define	UCST_QFULL			(UCST_SCSI2|UCST_BUSY)
#define	ucscsi_scrconf_s	sizeof(ucscsi_scrconf_t)
#define	ucs_modeheader_s	sizeof(ucs_modeheader_t)
#define	ucsreasnbadblk_s	sizeof(ucsreasnbadblk_t)
#define	ucscsi_modeparamg0_s	sizeof(ucscsi_modeparamg0_t)
#define	ucstmode_s	sizeof(ucstmode_t)
#define ucs_mode_format_s	sizeof(ucs_mode_format_t)
#define ucs_mode_geometry_s	sizeof(ucs_mode_geometry_t)

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mlxtypes.h
#define	mlx_space(c)	(((c) == ' ') || ((c) == 0x09))
#define	mlx_numeric(c)	((c) >= '0' && (c) <= '9')
#define	mlx_hex(c)	(mlx_numeric(c) || mlx_lohex(c) || mlx_uphex(c))
#define	mlx_lohex(c)	((c) >= 'a' && (c) <= 'f')
#define	mlx_uphex(c)	((c) >= 'A' && (c) <= 'F')
#define mlx_alnum(c)	(mlx_numeric(c) || ((c)>='a' && (c)<='z') || ((c)>='A' && (c)<='Z'))
#define	MLXIOC_INOUT	(MLXIOC_IN|MLXIOC_OUT)
#define	_MLXIOR(x,y,t)	_MLXIOC(MLXIOC_OUT,x,y,sizeof(t))
#define	_MLXIOW(x,y,t)	_MLXIOC(MLXIOC_IN,x,y,sizeof(t))
#define	_MLXIOWR(x,y,t)	_MLXIOC(MLXIOC_INOUT,x,y,sizeof(t))
#define	dga_driver_version_s	sizeof(dga_driver_version_t)

// drivers\storage\port\scsi\miniport\mylex\dac960\raidapi.h
#define DAC_DIODCDB      	(DACDIO|2)	/* DAC960 direct cdb   */
#define DAC_DIODCMD      	(DACDIO|3)	/* DAC960 direct cmd   */

// drivers\storage\sbp2port\sbp2port.h
#define SBP2_MAX_SUFFIX_SIZE                         5*sizeof(WCHAR)

// drivers\storage\scsiport\port.h
#define IS_MAPPED_SRB(Srb)                                  \
        ((Srb->Function == SRB_FUNCTION_IO_CONTROL) ||      \
         ((Srb->Function == SRB_FUNCTION_EXECUTE_SCSI) &&   \
          ((Srb->Cdb[0] == SCSIOP_INQUIRY) ||               \
           (Srb->Cdb[0] == SCSIOP_REQUEST_SENSE))))
#define SpSrbRequiresPower(srb)                                             \
    ((BOOLEAN) ((srb->Function == SRB_FUNCTION_EXECUTE_SCSI) ||             \
                 (srb->Function == SRB_FUNCTION_IO_CONTROL) ||              \
                 (srb->Function == SRB_FUNCTION_SHUTDOWN) ||                \
                 (srb->Function == SRB_FUNCTION_FLUSH) ||                   \
                 (srb->Function == SRB_FUNCTION_ABORT_COMMAND) ||           \
                 (srb->Function == SRB_FUNCTION_RESET_BUS) ||               \
                 (srb->Function == SRB_FUNCTION_RESET_DEVICE) ||            \
                 (srb->Function == SRB_FUNCTION_TERMINATE_IO) ||            \
                 (srb->Function == SRB_FUNCTION_REMOVE_DEVICE) ||           \
                 (srb->Function == SRB_FUNCTION_WMI)))

// drivers\storage\scsiport\verify.c
#define VRFY_DO_CHECK(adapter, chk)\
(((adapter)->VerifierExtension != NULL) &&\
(((adapter)->VerifierExtension->VrfyLevel & (chk)) == 0))

// drivers\storage\volsnap\vss\modules\wrtrshim\src\common.cpp
#define VALID_PATH( path ) ( ( ( pwszPathName[0] == DIR_SEP_CHAR )  && ( pwszPathName[1] == DIR_SEP_CHAR ) ) || \
                             ( isalpha( pwszPathName[0] ) && ( pwszPathName[1] == L':' ) && ( pwszPathName[2] == DIR_SEP_CHAR ) ) )

// drivers\storage\volsnap\vss\modules\wrtrshim\src\common.h
#define MAX_VOLUMENAME_SIZE	(MAX_VOLUMENAME_LENGTH * sizeof (WCHAR))
#define HandleInvalid(_Handle)			((NULL == (_Handle)) || (INVALID_HANDLE_VALUE == (_Handle)))

// drivers\storage\volsnap\vss\server\modules\vssadmin\vssadmin.cpp
#define SKU_A   ( SKU_C | SKU_S | SKU_N )
#define SKU_SN  ( SKU_S | SKU_N )

// drivers\storage\volsnap\vss\server\modules\wrtrshim\src\common.cpp
#define VALID_PATH( path ) ( ( ( pwszPathName[0] == DIR_SEP_CHAR )  && ( pwszPathName[1] == DIR_SEP_CHAR ) ) || \
                             ( isalpha( pwszPathName[0] ) && ( pwszPathName[1] == L':' ) && ( pwszPathName[2] == DIR_SEP_CHAR ) ) )

// drivers\storage\volsnap\vss\server\modules\wrtrshim\src\common.h
#define MAX_VOLUMENAME_SIZE	(MAX_VOLUMENAME_LENGTH * sizeof (WCHAR))
#define HandleInvalid(_Handle)			((NULL == (_Handle)) || (INVALID_HANDLE_VALUE == (_Handle)))

// drivers\storage\volsnap\vss\tests\snapcp\snapcp.cpp
#define HandleInvalid(_Handle)			((NULL == (_Handle)) || (INVALID_HANDLE_VALUE == (_Handle)))

// drivers\tpg\hwx\avalanche\src\geofeats.c
#define ONE_D_DISJOINT(min1, max1, min2, max2) (((min2) > (max1)) || ((min1) > (max2)))

// drivers\tpg\hwx\bear\inc\dti.h
#define DTI_SIZEOFVEXT (DTI_NUMSYMBOLS*DTI_MAXVARSPERLET*sizeof(_UCHAR))  // Size of learn vex table

// drivers\tpg\hwx\bear\inc\xr_names.h
#define IS_XR_LINK(xr)      ((xr) == XR_LINK || (xr) == XR_XR_LINK || (xr) == XR_XL_LINK || (xr) == XR_SMALL_LINK || (xr) == XR_NOBR_LINK)
#define IS_CLEAR_LINK(xr)   ((xr) == XR_LINK || (xr) == XR_SMALL_LINK)
#define IS_CROSSED_LINK(xr) ((xr) == XR_XR_LINK || (xr) == XR_XL_LINK)

// drivers\tpg\hwx\bear\inc\xrwdict.h
#define XRWD_IS_VOC_ONLY(x) (((x) & XRWD_SRCID_VOC) == (x))

// drivers\tpg\hwx\bear\src\check.cpp
  #define   V(i)         (  (  ((wx==0)? 0:((wx>0)? x[(i)]:(-x[(i)])))      \
                          + ((wy==0)? 0:((wy>0)? y[(i)]:(-y[(i)]))) ) / wxy \
                         )

// drivers\tpg\hwx\bear\src\cross.cpp
   #define   GET_LIMIT     if  ( IS_PREV_STROKE || IS_LAST_STROKE )                                 \
                               {                                                                    \
                                 Limit = S_CUT_P ;                                                  \
                               }                                                                    \
                           else  if  ( IS_BREAK_BETWEEN )                                           \
                               {                                                                    \
                                 Limit = FIVE_FOURTH( eps2[ (dij < LENTH_E) ? dij : LENTH_E-1 ] ) ; \
                               }                                                                    \
                           else                                                                     \
                               {                                                                    \
                                 Limit = eps1[ (dij < LENTH_E) ? dij : LENTH_E-1 ] ;                \
                               }

// drivers\tpg\hwx\bear\src\lk_begin.cpp
#define IsAnyExtremum(pEl)  (   REF(pEl)->mark==MINW     \
                             || REF(pEl)->mark==MINN     \
                             || REF(pEl)->mark==MAXW     \
                             || REF(pEl)->mark==MAXN     \
                             || REF(pEl)->mark==_MINX    \
                             || REF(pEl)->mark==_MAXX    \
                             || REF(pEl)->mark==MINXY    \
                             || REF(pEl)->mark==MAXXY    \
                             || REF(pEl)->mark==MINYX    \
                             || REF(pEl)->mark==MAXYX    \
                            )

// drivers\tpg\hwx\bear\src\sketch.cpp
  #define    F_CONJUN( b , e )            ( ( ( b + e ) > F_MAX_MARK ) ?  \
                                          ( b + e - F_MAX_MARK )   : 0  )

// drivers\tpg\hwx\bear\src\xrlv.cpp
#define IS_LINKLIKE1_XR(xr) ((xr) == X_UD_F || (xr) == X_DD_L || (xr) == X_BGD || \
                             (xr) == X_SGD || (xr) == X_CU_L || (xr) == X_GL ||   \
                             (xr) == X_DU_L || (xr) == X_AN_UL || (xr) == X_ST || \
                             (xr) == X_UDC_B || (xr) == X_XT_ST)
#define IS_LINKLIKE2_XR(xr) ((xr) == X_ID_F || (xr) == X_ID_STK)
#define IS_LINKLIKE3_XR(xr) ((xr) == X_DU_R || (xr) == X_CU_R || (xr) == X_GR || \
                             (xr) == X_BGU || (xr) == X_SGU || (xr) == X_ST ||   \
                             (xr) == X_DF || (xr) == X_XT || (xr) == X_XT_ST  || \
                             (xr) == X_AN_UR)

// drivers\tpg\hwx\commonu\inc\recog.h
#define ALC_SYS_MINIMUM		(ALC_ALPHANUMERIC | ALC_PUNC | ALC_WHITE)
#define ALC_SYS_DEFAULT		(ALC_SYS_MINIMUM | ALC_COMMON_SYMBOLS)

// drivers\tpg\hwx\crane\src\algo.h
#define	LineSmall(dx, dy)		\
	((dx) >= -MAX_DELTA && (dx) <= MAX_DELTA && (dy) >= -MAX_DELTA && (dy) <= MAX_DELTA)
#define	LineInSplash(dx, dy)		\
	((dx) >= -MAX_SPLASH && (dx) <= MAX_SPLASH && (dy) >= -MAX_SPLASH && (dy) <= MAX_SPLASH)

// drivers\tpg\hwx\factoid\inc\regexp.h
#define IsOperator(x) (((x) >= MIN_OPERATOR) && ((x) <= MAX_OPERATOR))
#define IsNonterminal(x) (((x) >= MIN_NONTERMINAL) && ((x) <= MAX_NONTERMINAL))
#define IsTerminal(x) (((x) >= MIN_TERMINAL) && ((x) <= MAX_TERMINAL))

// drivers\tpg\hwx\holycow\src\nfeature.c
#define ONE_D_DISJOINT(min1, max1, min2, max2) (((min2) > (max1)) || ((min1) > (max2)))

// drivers\tpg\hwx\tsunami\inc\testtune.h
#define	SIZE_HWXRESULTS		(sizeof(HWXRESULTS) + (ALT_MAX - 1) * sizeof(WCHAR))
#define	SIZE_BOXRESULTS		(sizeof(BOXRESULTS) + (ALT_MAX - 1) * sizeof(SYV))

// drivers\tpg\hwx\tsunami\src\snot\global.h
#define AddValidHRC(hrc)      AddValidHANDLE((GHANDLE)hrc, &RgHandleValidGlobal(), &CHandleValidGlobal(), &CHandleValidMaxGlobal())
#define RemoveValidHRC(hrc)   RemoveValidHANDLE((GHANDLE)hrc, RgHandleValidGlobal(), &CHandleValidGlobal())
#define AddValidHRCRESULT(hrcres)      AddValidHANDLE((GHANDLE)hrcres, &RgHandleValidGlobal(), &CHandleValidGlobal(), &CHandleValidMaxGlobal())
#define RemoveValidHRCRESULT(hrcres)   RemoveValidHANDLE((GHANDLE)hrcres, RgHandleValidGlobal(), &CHandleValidGlobal())

// drivers\tpg\hwx\tsunami\src\usa\global.h
#define AddValidHRC(hrc)      AddValidHANDLE((GHANDLE)hrc, &RgHandleValidGlobal(), &CHandleValidGlobal(), &CHandleValidMaxGlobal())
#define RemoveValidHRC(hrc)   RemoveValidHANDLE((GHANDLE)hrc, RgHandleValidGlobal(), &CHandleValidGlobal())
#define AddValidHRCRESULT(hrcres)      AddValidHANDLE((GHANDLE)hrcres, &RgHandleValidGlobal(), &CHandleValidGlobal(), &CHandleValidMaxGlobal())
#define RemoveValidHRCRESULT(hrcres)   RemoveValidHANDLE((GHANDLE)hrcres, RgHandleValidGlobal(), &CHandleValidGlobal())

// drivers\video\matrox\mga\disp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\matrox\mga\mini\bind.h
    #define _inp(a)     VideoPortReadPortUchar((PUCHAR)(a))
    #define _outp(a, d) VideoPortWritePortUchar((PUCHAR)(a), (d))

// drivers\video\matrox\mga\mini\clock.c
#define NBRE_I_POSSIBLE     ( (sizeof(limites_i)) / (sizeof(long)) )

// drivers\video\matrox\mga\mini\mga.c
    #define CONVERT_BOARD_NUMBER(n) n = ((pCurMulti->MulArrayHeight - 1) *  \
                                            pCurMulti->MulArrayWidth) - n + \
                                            2*(n % pCurMulti->MulArrayWidth)

// drivers\video\matrox\mga\mini\mga_nt.h
#define     DISPTYPE_UNUSABLE       (DISPTYPE_TV           |  \
                                     DISPTYPE_MON_LIMITED  |  \
                                     DISPTYPE_HW_LIMITED   |  \
                                     DISPTYPE_UNDISPLAYABLE)

// drivers\video\matrox\mga\mini\mtxvga.h
  #define   ADDR_EQUIP_LO       (PUCHAR) ((((PMGA_DEVICE_EXTENSION)pMgaDeviceExtension)->MappedAddress[6]))
  #define   ADDR_CRT_MODE       (PUCHAR) ((((PMGA_DEVICE_EXTENSION)pMgaDeviceExtension)->MappedAddress[7]))
  #define   ADDR_MAX_ROW        (PUCHAR) ((((PMGA_DEVICE_EXTENSION)pMgaDeviceExtension)->MappedAddress[8]))
  #define   VGA_RAM             (PUCHAR) ((((PMGA_DEVICE_EXTENSION)pMgaDeviceExtension)->MappedAddress[10]))
  #define   VGA_MEM             (PUCHAR) ((((PMGA_DEVICE_EXTENSION)pMgaDeviceExtension)->MappedAddress[11]))

// drivers\video\matrox\mga\mini\mtxvpro.h
#define NOT_ENCODER  (enc.board.id_reg.all & 0xf7)   != ENC_ID_REV0

// drivers\video\ms\3dlabs\perm2\disp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\3dlabs\perm2\disp\hw.h
#define P2_TAG_MINOR(x)              ((x) & 0x00f)

// drivers\video\ms\3dlabs\perm2\mini\p2rd.h
#define P2RD_INDEX_ADDR_LO            ((PULONG)&(pP2RDRegs->RDIndexLow.reg))
#define P2RD_INDEX_ADDR_HI            ((PULONG)&(pP2RDRegs->RDIndexHigh.reg))
#define P2RD_INDEX_DATA               ((PULONG)&(pP2RDRegs->RDIndexedData.reg))
#define P2RD_INDEX_CONTROL            ((PULONG)&(pP2RDRegs->RDIndexControl.reg))
#define P2RD_LOAD_DATA(data) \
{ \
    VideoPortWriteRegisterUlong(P2RD_INDEX_DATA, (ULONG)((data) & 0xff)); \
    P2RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm2\mini\permedia.h
#define DEVICE_FAMILY_ID(id)    ((id) & 0xff)
#define RAMDAC_DECL \
    P2_REG *pRAMDAC = &(pCtrlRegs->ExternalVideo)
#define CTRL_REG_ADDR(reg)      ((PULONG)&(pCtrlRegs->reg))
#define PERMEDIA_MMVGA_INDEX_REG    ((PVOID)(&(pCtrlRegs->PermediaVgaCtrl[0x3C4])))
#define PERMEDIA_MMVGA_DATA_REG     (&(pCtrlRegs->PermediaVgaCtrl[0x3C5]))
#define PERMEDIA_MMVGA_STAT_REG     (&(pCtrlRegs->PermediaVgaCtrl[0x3DA]))
#define DISCONNECT_INOUT_ENABLE         (DISCONNECT_INPUT_FIFO_ENABLE | \
                                         DISCONNECT_OUTPUT_FIFO_ENABLE)
#define LUT_CACHE_INIT()        {VideoPortZeroMemory (&(hwDeviceExtension->LUTCache), sizeof (hwDeviceExtension->LUTCache));}

// drivers\video\ms\3dlabs\perm2\mini\tvp4020.h
#define __TVP4020_PAL_WR_ADDR       ((PULONG)&(pTVP4020Regs->pciAddrWr.reg))
#define __TVP4020_PAL_RD_ADDR       ((PULONG)&(pTVP4020Regs->pciAddrRd.reg))
#define __TVP4020_PAL_DATA          ((PULONG)&(pTVP4020Regs->palData.reg))
#define __TVP4020_INDEX_ADDR        ((PULONG)&(pTVP4020Regs->pciAddrWr.reg))
#define __TVP4020_INDEX_DATA        ((PULONG)&(pTVP4020Regs->indexData.reg))
#define __TVP4020_CUR_RAM_WR_ADDR   ((PULONG)&(pTVP4020Regs->pciAddrWr.reg))
#define __TVP4020_CUR_RAM_RD_ADDR   ((PULONG)&(pTVP4020Regs->palAddrRd.reg))
#define __TVP4020_CUR_RAM_DATA      ((PULONG)&(pTVP4020Regs->curRAMData.reg))
#define __TVP4020_CUR_COL_ADDR      ((PULONG)&(pTVP4020Regs->curColAddr.reg))
#define __TVP4020_CUR_COL_DATA      ((PULONG)&(pTVP4020Regs->curColData.reg))
#define __TVP4020_CURSOR_X_LSB      ((PULONG)&(pTVP4020Regs->cursorXLow.reg))
#define __TVP4020_CURSOR_X_MSB      ((PULONG)&(pTVP4020Regs->cursorXHigh.reg))
#define __TVP4020_CURSOR_Y_LSB      ((PULONG)&(pTVP4020Regs->cursorYLow.reg))
#define __TVP4020_CURSOR_Y_MSB      ((PULONG)&(pTVP4020Regs->cursorYHigh.reg))
#define TVP4020_LOAD_CURSOR_CTRL(data) \
{ \
    volatile LONG   __temp;                                    \
    TVP4020_READ_INDEX_REG(__TVP4020_CURSOR_CONTROL, __temp);  \
    __temp &= ~(0x03) ;                                        \
    __temp |= ((data) & 0x03) ;                                \
    TVP4020_WRITE_INDEX_REG(__TVP4020_CURSOR_CONTROL, __temp); \
}

// drivers\video\ms\3dlabs\perm3\disp\dx\ddover.c
#define VALID_WIDTH(w)      ((w & 3) == 0)
#define MAKE_VALID_WIDTH(w) ((w) & ~0x3)

// drivers\video\ms\3dlabs\perm3\disp\dx\directx.h
#define IS_DXCONTEXT_CURRENT(pThisDisplay)                          \
        (((pThisDisplay->ppdev->currentCtxt) !=                     \
          (pThisDisplay->ppdev->DDContextID)) ? FALSE : TRUE)
#define IS_DXCONTEXT_CURRENT(pThisDisplay)                                   \
    ((pThisDisplay->pGLInfo->dwCurrentContext != CONTEXT_DIRECTX_HANDLE) ?   \
                                                                FALSE : TRUE)
#define DDSurf_FromInt(pSurfInt)                                             \
    ((LPDDRAWI_DDRAWSURFACE_LCL)((LPDDRAWI_DDRAWSURFACE_INT)pSurfInt)->lpLcl)
#define VALIDATE_MODE_AND_STATE(pThisDisplay)     \
    if ((pThisDisplay->bResetMode != 0) ||        \
        (pThisDisplay->bStartOfDay))              \
            ChangeDDHAL32Mode(pThisDisplay);

// drivers\video\ms\3dlabs\perm3\disp\dx\dma.h
#define WAIT_FIFO(a)                                          \
do { if(pThisDisplay->pGLInfo->InterfaceType != GLINT_DMA)    \
        __WAIT_GLINT_FIFO_SPACE(a);                           \
        __SET_FIFO_ENTRIES_LEFT(a);                           \
        __RESET_FIFO_ERROR_CHECK;                             \
    } while (0)

// drivers\video\ms\3dlabs\perm3\disp\gdi\glint.h
#define WAIT_GLINT_FIFO(n)            /* Do the wait */ \
{ \
    if (glintInfo->CheckFIFO)    \
    {    \
        while ((GET_INPUT_FIFO_SPACE(_temp_volatile_ul)) < (ULONG)(n)); \
    }    \
}
#define IS_FIFO_EMPTY(c) ((glintInfo->CheckFIFO) ? TRUE :    \
            (GET_INPUT_FIFO_SPACE(c) == glintInfo->MaxInFifoEntries))
#define GLINT_VALIDATE_CONTEXT(id) \
    if (((ppdev)->currentCtxt) != (id)) \
        vGlintSwitchContext(ppdev, (id))
#define GLINT_VALIDATE_CONTEXT_AND_SYNC(id) { \
    if (((ppdev)->currentCtxt) != (id)) \
        vGlintSwitchContext(ppdev, (id)); \
    else \
        SYNC_WITH_GLINT; \
}
#define GLINT_TAG_MINOR(x)        ((x) & 0x00f)

// drivers\video\ms\3dlabs\perm3\disp\inc\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\3dlabs\perm3\disp\inc\tvp3026.h
#define TVP3026_IS_FOUND(bFound)        \
{\
    volatile LONG   __revLevel;        \
    volatile LONG   __productID;    \
    volatile LONG   __oldValue;     \
    __oldValue = VideoPortReadRegisterUlong(__TVP3026_INDEX_ADDR);\
    TVP3026_DELAY; \
    TVP3026_READ_INDEX_REG (__TVP3026_SILICON_REVISION, __revLevel);\
    TVP3026_READ_INDEX_REG (__TVP3026_CHIP_ID,              __productID);    \
    bFound = (    (__revLevel >= TVP3026_REVISION_LEVEL) &&              \
                (__productID == TVP3026_ID_CODE)) ? TRUE : FALSE ;    \
    VideoPortWriteRegisterUlong(__TVP3026_INDEX_ADDR, __oldValue );    \
    TVP3026_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\mini\p3rd.h
#define P3RD_INDEX_ADDR_LO ((PULONG)&(pP3RDRegs->RDIndexLow.reg))
#define P3RD_INDEX_ADDR_HI ((PULONG)&(pP3RDRegs->RDIndexHigh.reg))
#define P3RD_INDEX_DATA    ((PULONG)&(pP3RDRegs->RDIndexedData.reg))
#define P3RD_INDEX_CONTROL ((PULONG)&(pP3RDRegs->RDIndexControl.reg))
#define P3RD_LOAD_DATA(data) \
{ \
    VideoPortWriteRegisterUlong(P3RD_INDEX_DATA, (ULONG)((data) & 0xff)); \
    P3RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\mini\perm3.h
#define CTRL_REG_ADDR(reg)       ((PULONG)&(pCtrlRegs->reg))
#define PERMEDIA_MMVGA_INDEX_REG    ((PVOID)(&(pCtrlRegs->PermediaVgaCtrl[0x3C4])))
#define PERMEDIA_MMVGA_DATA_REG     (&(pCtrlRegs->PermediaVgaCtrl[0x3C5]))
#define PERMEDIA_MMVGA_STAT_REG     (&(pCtrlRegs->PermediaVgaCtrl[0x3DA]))
#define VC_DPMS_STANDBY    (VC_HSYNC(VC_FORCED_LOW)  | VC_VSYNC(VC_ACTIVE_HIGH) | VC_OFF)
#define VC_DPMS_SUSPEND    (VC_HSYNC(VC_ACTIVE_HIGH) | VC_VSYNC(VC_FORCED_LOW)  | VC_OFF)
#define VC_DPMS_OFF        (VC_HSYNC(VC_FORCED_LOW)  | VC_VSYNC(VC_FORCED_LOW)  | VC_OFF)
#define DISCONNECT_INOUT_ENABLE         (DISCONNECT_INPUT_FIFO_ENABLE | \
                                         DISCONNECT_OUTPUT_FIFO_ENABLE)
#define LUT_CACHE_INIT()        {VideoPortZeroMemory (&(hwDeviceExtension->LUTCache), sizeof (hwDeviceExtension->LUTCache));}

// drivers\video\ms\8514a\disp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\8514a\disp\hw.h
#define IO_MIN_AXIS_PCNT(ppdev, x)          \
{                                           \
    OUT_ACCEL(MIN_AXIS_PCNT, (x) | RECT_HEIGHT);      \
}

// drivers\video\ms\ati\disp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\ati\mini\cvtvdif.h
#define PREADJ_TIMING(limits) \
        ((VDIFTimingRec *)((char *)(limits) + (limits)->Header.ScnLength))
#define NEXT_PREADJ_TIMING(timing) \
        ((VDIFTimingRec *)((char *)(timing) + (timing)->Header.ScnLength))

// drivers\video\ms\ati\mini\dynainit.h
#define MONITOR_GENERIC_SIZE        sizeof(MONITOR_GENERIC)

// drivers\video\ms\ati\mini\stdtyp.h
#define MAKETYPE(v, type)   (*((type *)&v))

// drivers\video\ms\cirrus\disp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\cirrus\mini\cirrus.h
#define  CL754x       (CL7541 | CL7542 | CL7543 | CL7548)
#define  CL755x       (CL7555 | CL7556)
#define EXT_NUM_GRAPH_CONT_PORTS    ((CL64xx_NUM_GRAPH_EXT_PORTS >   \
                                     CL542x_NUM_GRAPH_EXT_PORTS) ?   \
                                     CL64xx_NUM_GRAPH_EXT_PORTS :    \
                                     CL542x_NUM_GRAPH_EXT_PORTS)
#define VGA_HARDWARE_STATE_SIZE sizeof(VIDEO_HARDWARE_STATE_HEADER)
#define VGA_VALIDATOR_AREA_SIZE  sizeof (ULONG) + (VGA_MAX_VALIDATOR_DATA * \
                                 sizeof (VGA_VALIDATOR_DATA)) +             \
                                 sizeof (ULONG) +                           \
                                 sizeof (ULONG) +                           \
                                 sizeof (PVIDEO_ACCESS_RANGE)

// drivers\video\ms\cirrus\mini\clpanel.c
#define DSTN       (Dual_LCD | STN_LCD)
#define DSTN10     (DSTN | panel10x7)
#define DSTN8      (DSTN | panel8x6)
#define DSTN6      (DSTN | panel)
#define PanelType  (panel | panel8x6 | panel10x7)
#define ScreenType (DSTN | PanelType)

// drivers\video\ms\cirrus\mini\modeset.c
#define DSTN       (Dual_LCD | STN_LCD)
#define DSTN10     (DSTN | panel10x7)
#define DSTN8      (DSTN | panel8x6)
#define DSTN6      (DSTN | panel)
#define PanelType  (panel | panel8x6 | panel10x7)
#define ScreenType (DSTN | PanelType)

// drivers\video\ms\compaq.qv\disp\driver.h
#define MAX_GLYPH_SIZE      ((((GLYPH_CACHE_CX + GLYPH_GRANULARITY) & ~GLYPH_GRANULARITY) \
                             * GLYPH_CACHE_CY + 7) / 8)
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\compaq.qv\mini\qvision.h
#define VGA_HARDWARE_STATE_SIZE sizeof(VIDEO_HARDWARE_STATE_HEADER)
#define VGA_VALIDATOR_AREA_SIZE  sizeof (ULONG) + (VGA_MAX_VALIDATOR_DATA * \
                                 sizeof (VGA_VALIDATOR_DATA)) +             \
                                 sizeof (ULONG) +                           \
                                 sizeof (ULONG) +                           \
                                 sizeof (PVIDEO_ACCESS_RANGE)

// drivers\video\ms\framebuf\disp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\laguna\disp\cl5465\init.c
#define CLEAR_RANGE( StartReg, EndReg ) \
    memset( (void *)(ppdev->LL_State.pRegs + (StartReg)), 0, ((EndReg) - (StartReg)+1)*4 )

// drivers\video\ms\laguna\disp\include\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\laguna\disp\include\l3system.h
#define CLEAR_RANGE( StartReg, EndReg ) \
    memset( (void *)(ppdev->LL_State.pRegs + (StartReg)), 0, ((EndReg) - (StartReg)+1)*4 )

// drivers\video\ms\laguna\disp\include\laguna.h
	#define ENDREQUIRE()													\
	{																		\
		ppdev->dwDataStreaming |= 1;										\
	}

// drivers\video\ms\laguna\disp\include\mmcore.h
	#define MM_MOVEABLE(pdm)	( (pdm->client != NULL) && \
								  (pdm->client->mem_moved != NULL) )

// drivers\video\ms\laguna\mini\cl546x\cirrus.c
#define CheckBiosID(BiosAddress) \
         (   ( *(BiosAddress+0x1E) == 'I') \
          && ( *(BiosAddress+0x1F) == 'B') \
          && ( *(BiosAddress+0x20) == 'M') \
          && ( *(BiosAddress+0x21) == ' ') \
          && ( *(BiosAddress+0x22) == 'V') \
          && ( *(BiosAddress+0x23) == 'G') \
          && ( *(BiosAddress+0x24) == 'A') \
          && ( *(BiosAddress+0x25) == ' ') \
          && ( *(BiosAddress+0x26) == 'C') \
          && ( *(BiosAddress+0x27) == 'o') \
          && ( *(BiosAddress+0x28) == 'm') \
          && ( *(BiosAddress+0x29) == 'p') \
          && ( *(BiosAddress+0x2A) == 'a') \
          && ( *(BiosAddress+0x2B) == 't') \
          && ( *(BiosAddress+0x2C) == 'i') \
          && ( *(BiosAddress+0x2D) == 'b') \
          && ( *(BiosAddress+0x2E) == 'l') \
          && ( *(BiosAddress+0x2F) == 'e') \
         ) \

// drivers\video\ms\laguna\mini\include\driver.h
#define SET_DRVSEM_YUV()    (pDriverData->DrvSemaphore |=  DRVSEM_YUV_ON)
#define CLR_DRVSEM_YUV()    (pDriverData->DrvSemaphore &= ~DRVSEM_YUV_ON)
#define IN_VBLANK         (_inp(0x3da) & 8)
#define IN_DISPLAYENABLE  (_inp(0x3da) & 1)
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\laguna\mini\include\l3d.h
#define X_EXTENT(Extent)    ((Extent) & 0xFFFF)

// drivers\video\ms\laguna\mini\include\l3system.h
#define write_register( reg, count ) \
( WRITE_REGISTER | mk_reg(reg) | count )
#define write_dev_register( device, reg, count ) \
( WRITE_DEV_REGS | device | mk_dev_reg(reg) | count )
#define SETREG_NC(reg, value)     \
    (*(ppdev->LL_State.pRegs + reg) = value); /*inp(0x80); inp(0x80)*/
#define CLEAR_RANGE( StartReg, EndReg ) \
    memset( (void *)(ppdev->LL_State.pRegs + (StartReg)), 0, ((EndReg) - (StartReg)+1)*4 )

// drivers\video\ms\laguna\mini\include\laguna.h
#define HISTORYBUFFERADDR (ul)&history           /* 34020 address of recording    */
	#define ENDREQUIRE()													\
	{																		\
		ppdev->dwDataStreaming |= 1;										\
	}
    #define SYNC_3D_CONDITIONS (ST_POLY_ENG_BUSY|ST_EXEC_ENG_3D_BUSY|ST_XY_ENG_BUSY|/*ST_BLT_ENG_BUSY|*/ST_BLT_WF_EMPTY)
    #define SYNC_W_3D(ppdev)                                                                                    \
    {                                                                                                           \
        if (ppdev->NumMCDContexts > 0)                                                                          \
        {                                                                                                       \
            ENSURE_3D_IDLE(ppdev);                                                                              \
        }                                                                                                       \
    }

// drivers\video\ms\laguna\mini\include\lines.h
#define FL_CLIP                (FL_SIMPLE_CLIP | FL_COMPLEX_CLIP)

// drivers\video\ms\laguna\mini\include\memmgr.h
#define MCD_TEXTURE_ALLOCATE    (MCD_TEXTURE8_ALLOCATE|MCD_TEXTURE16_ALLOCATE|MCD_TEXTURE32_ALLOCATE)

// drivers\video\ms\laguna\mini\include\mmcore.h
	#define MM_MOVEABLE(pdm)	( (pdm->client != NULL) && \
								  (pdm->client->mem_moved != NULL) )

// drivers\video\ms\mirror\disp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\modex\disp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\port\pedid.h
#define GET_EDID_STANDARD_TIMING_ID(pEdid, x)   \
    pEdid->US_StandardTimingIdentifications[x]
#define GET_MONITOR_RANGE_LIMITS(pMonitorDesc) \
    pMonitorDesc->MonitorSNorData
#define GET_RANGE_LIMIT_PGTF(pMonitorSNorData)    \
    &pMonitorSNorData[10]

// drivers\video\ms\port\videoprt.h
#define IS_HW_DEVICE_EXTENSION(p) (((p) != NULL) && (GET_FDO_EXT(p)->HwDeviceExtension == (p)))
#define IS_PDO(p) (((p) != NULL) && \
                  (((PCHILD_PDO_EXTENSION)(p))->Signature == VP_TAG) && \
                  (((PCHILD_PDO_EXTENSION)(p))->ExtensionType == TypePdoExtension))
#define IS_FDO(p) (((p) != NULL) && \
                  (((PFDO_EXTENSION)(p))->Signature == VP_TAG) && \
                  (((PFDO_EXTENSION)(p))->ExtensionType == TypeFdoExtension))

// drivers\video\ms\s3\disp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\s3\disp\hw.h
#define IO_MAJ_AXIS_PCNT(ppdev, x)          \
    OUT_FIFO_W(ppdev->ioMaj_axis_pcnt, (x))
#define IO_MIN_AXIS_PCNT(ppdev, x)          \
{                                           \
    CP_MEMORY_BARRIER();                    \
    OUT_FIFO_W(ppdev->ioMulti_function, (x) | RECT_HEIGHT);      \
}

// drivers\video\ms\s3\mini\nnclk.c
#define CLOCK(x) VideoPortWritePortUchar(CRT_DATA_REG, (UCHAR)(iotemp | (x)))

// drivers\video\ms\s3\mini\s3.h
#define BT485_ADDR_CMD_REG0    (PVOID)((PUCHAR)((PHW_DEVICE_EXTENSION)HwDeviceExtension)->MappedAddress[2] + (0x03C6 - 0x03C0))
#define TI025_INDEX_REG        (PVOID)((PUCHAR)((PHW_DEVICE_EXTENSION)HwDeviceExtension)->MappedAddress[2] + (0x03C6 - 0x03C0))
#define TI025_DATA_REG         (PVOID)((PUCHAR)((PHW_DEVICE_EXTENSION)HwDeviceExtension)->MappedAddress[2] + (0x03C7 - 0x03C0))
#define CRT_DATA_REG           (PVOID)((PUCHAR)((PHW_DEVICE_EXTENSION)HwDeviceExtension)->MappedAddress[3] + (0x03D5 - 0x03D4))
#define SYSTEM_CONTROL_REG     (PVOID)((PUCHAR)((PHW_DEVICE_EXTENSION)HwDeviceExtension)->MappedAddress[3] + (0x03DA - 0x03D4))
#define DAC_ADDRESS_WRITE_PORT (PVOID)((PUCHAR)HwDeviceExtension->MappedAddress[2] + (0x03C8 - 0x03C0))
#define DAC_DATA_REG_PORT      (PVOID)((PUCHAR)HwDeviceExtension->MappedAddress[2] + (0x03C9 - 0x03C0))
#define MISC_OUTPUT_REG_WRITE  (PVOID)((PUCHAR)HwDeviceExtension->MappedAddress[2] + (0x03C2 - 0x03C0))
#define MISC_OUTPUT_REG_READ   (PVOID)((PUCHAR)HwDeviceExtension->MappedAddress[2] + (0x03CC - 0x03C0))
#define SEQ_ADDRESS_REG        (PVOID)((PUCHAR)HwDeviceExtension->MappedAddress[2] + (0x03C4 - 0x03C0))
#define SEQ_DATA_REG           (PVOID)((PUCHAR)HwDeviceExtension->MappedAddress[2] + (0x03C5 - 0x03C0))

// drivers\video\ms\tseng\mini\et4000.h
#define VGA_HARDWARE_STATE_SIZE sizeof(VIDEO_HARDWARE_STATE_HEADER)
#define VGA_VALIDATOR_AREA_SIZE  sizeof (ULONG) + (VGA_MAX_VALIDATOR_DATA * \
                                 sizeof (VGA_VALIDATOR_DATA)) +             \
                                 sizeof (ULONG) +                           \
                                 sizeof (ULONG) +                           \
                                 sizeof (PVIDEO_ACCESS_RANGE)

// drivers\video\ms\vga\disp\4bpp\textout.h
#define BINVALIDRECT(rcl)   ((rcl.right <= rcl.left) || (rcl.bottom <= rcl.top))

// drivers\video\ms\vga\disp\8bpp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\vga\mini\vesa.h
#define OFF(x) ((x) & 0xffff)

// drivers\video\ms\vga\mini\vga.h
#define VGA_HARDWARE_STATE_SIZE sizeof(VIDEO_HARDWARE_STATE_HEADER)
#define VGA_VALIDATOR_AREA_SIZE  sizeof (ULONG) + (VGA_MAX_VALIDATOR_DATA * \
                                 sizeof (VGA_VALIDATOR_DATA)) +             \
                                 sizeof (ULONG) +                           \
                                 sizeof (ULONG) +                           \
                                 sizeof (PVIDEO_ACCESS_RANGE)

// drivers\video\ms\w32\disp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\wd\mini\pvgaequ.h
#define  pr1b_unlock        (pr1b_unlock_shadow | pr1b_unlock_pr)

// drivers\video\ms\wd\mini\wdvga.h
#define ALL (WD90C00 | WD90C30 | SPEEDSTAR30 | WD90C31 | SPEEDSTAR31 | WD90C24A)
#define NOT_WD90C24A (ALL & ~WD90C24A)
#define VGA_HARDWARE_STATE_SIZE sizeof(VIDEO_HARDWARE_STATE_HEADER)
#define VGA_VALIDATOR_AREA_SIZE  sizeof (ULONG) + (VGA_MAX_VALIDATOR_DATA * \
                                 sizeof (VGA_VALIDATOR_DATA)) +             \
                                 sizeof (ULONG) +                           \
                                 sizeof (ULONG) +                           \
                                 sizeof (PVIDEO_ACCESS_RANGE)

// drivers\video\ms\weitek\disp\driver.h
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * 256))

// drivers\video\ms\weitek\mini\bt485.h
#define WR_CMD_REG_3(data) \
    WR_DAC(CMD_REG_0, RD_DAC(CMD_REG_0) | ENB_CMD_REG_3); \
    PAL_WR_ADDR(CMD_REG_3_ENB); \
    WR_DAC(CMD_REG_3, (data)); \
    PAL_WR_ADDR(CMD_REG_3_DIS)
#define RD_CMD_REG_3(data) \
    WR_DAC(CMD_REG_0, RD_DAC(CMD_REG_0) | ENB_CMD_REG_3); \
    PAL_WR_ADDR(CMD_REG_3_ENB); \
    data = RD_DAC(CMD_REG_3); \
    PAL_WR_ADDR(CMD_REG_3_DIS)
#define WR_CMD_REG_4(data) \
    WR_DAC(CMD_REG_0, RD_DAC(CMD_REG_0) | ENB_CMD_REG_3); \
    PAL_WR_ADDR(CMD_REG_4_ENB); \
    WR_DAC(CMD_REG_3, (data)); \
    PAL_WR_ADDR(CMD_REG_4_DIS)
#define RD_CMD_REG_4(data) \
    WR_DAC(CMD_REG_0, RD_DAC(CMD_REG_0) | ENB_CMD_REG_3); \
    PAL_WR_ADDR(CMD_REG_4_ENB); \
    data = RD_DAC(CMD_REG_3); \
    PAL_WR_ADDR(CMD_REG_4_DIS)
#define CURS_IS_ON() \
    (RD_DAC(CMD_REG_2) & CURS_ACTIVE)
#define CURS_ON() \
    WR_DAC(CMD_REG_2, RD_DAC(CMD_REG_2) | ENB_CURS)
#define CURS_OFF() \
    WR_DAC(CMD_REG_2, RD_DAC(CMD_REG_2) & DIS_CURS)

// drivers\video\ms\weitek\mini\p9.h
#define VideoPortIsCpu(typeCpu)                                             \
        (NO_ERROR == VideoPortGetDeviceData(HwDeviceExtension,VpMachineData,\
                                            &GetCPUIdCallback, typeCpu))
#define if_SIEMENS_Box() \
              if (HwDeviceExtension->MachineType == SIEMENS \
              ||  HwDeviceExtension->MachineType == SIEMENS_P9100_VLB \
              ||  HwDeviceExtension->MachineType == SIEMENS_P9100_PCi)
#define if_SIEMENS_P9100_VLB() \
              if (HwDeviceExtension->MachineType == SIEMENS_P9100_VLB)
#define if_SIEMENS_P9100() \
              if (HwDeviceExtension->MachineType == SIEMENS_P9100_VLB \
              ||  HwDeviceExtension->MachineType == SIEMENS_P9100_PCi)
#define if_Not_SIEMENS_P9100_VLB() \
              if (HwDeviceExtension->MachineType != SIEMENS_P9100_VLB)
#define if_SIEMENS_VLB() \
              if (HwDeviceExtension->MachineType == SIEMENS \
              ||  HwDeviceExtension->MachineType == SIEMENS_P9100_VLB)
#define VGA_WR_REG(index, data) \
    VideoPortWritePortUchar((PUCHAR) HwDeviceExtension->Vga + index, (UCHAR) (data))
#define VGA_RD_REG(index) \
    VideoPortReadPortUchar((PUCHAR) HwDeviceExtension->Vga + index)
#define P9_WR_REG(index, data) \
   VideoPortWriteRegisterUlong((PULONG)((PUCHAR) HwDeviceExtension->Coproc + index), (ULONG) (data))
#define P9_RD_REG(index) \
   VideoPortReadRegisterUlong((PULONG) ((PUCHAR) HwDeviceExtension->Coproc + index))

// drivers\video\ms\weitek\mini\p91dac.h
#define IBM525_WR_DAC(index, data)      \
{                                       \
    ULONG   ulIndex;                    \
    UWB     uwb;                        \
                                        \
    uwb.aj[0] = (UCHAR) data;           \
    uwb.aj[1] = uwb.aj[0];              \
    uwb.aw[1] = uwb.aw[0];              \
                                        \
    ulIndex = index & ~0x3;             \
                                        \
    P9_WR_REG(ulIndex, uwb.ul);         \
}
#define IBM525_RD_DAC(index, val)       \
{                                       \
    ULONG   ulIndex;                    \
    UWB     uwb;                        \
                                        \
    ulIndex = index & ~0x3;             \
                                        \
    uwb.ul = P9_RD_REG(ulIndex);        \
                                        \
    uwb.aj[3] = uwb.aj[2];              \
    uwb.aw[0] = uwb.aw[1];              \
                                        \
    val = uwb.aj[0];                    \
}

// drivers\video\ms\weitek\mini\p91regs.h
#define P91_CONFIG_CFBGA            (64)    // RO-Config: BUS, CFBGA & EEDAIN
#define P91_CONFIG_CKSEL            (66)    // RW-CKSEl & VCEN

// drivers\wdm\audio\backpln\portcls\miniport\dmusuart\miniport.cpp
#define CONST_PCNODE_DESCRIPTOR(n)          { 0, NULL, &n, NULL }
#define CONST_PCNODE_DESCRIPTOR_AUTO(n,a)   { 0, &a, &n, NULL }

// drivers\wdm\audio\backpln\portcls\ports\dmus\parse.h
#define IS_SYSTEM_COMMON(x) (((x) & 0xF8) == 0xF0)

// drivers\wdm\audio\drivers\avcaudio\avccmd.h
#define IS_AVC_EXTERNAL_PLUG(a)  ((((UCHAR)a >  0x7f) && ((UCHAR)a < 0x9f)) || ((UCHAR)a == 0xff))
#define IS_AVC_SERIALBUS_PLUG(a) ((((UCHAR)a >= 0x00) && ((UCHAR)a < 0x1f)) || ((UCHAR)a == 0x7f))

// drivers\wdm\audio\inc\midi.h
#define IS_SYSTEM(b)                    (((b) & 0xF0) == 0xF0)
#define IS_CHANNEL(b)                   ((b) & 0x80)

// drivers\wdm\audio\legacy\wdmaud.sys\kmxluser.c
#define NOT16( di ) if( di->dwFormat == ANSI_TAG ) DPF(DL_WARNING|FA_USER,("Invalid dwFormat.") );

// drivers\wdm\audio\legacy\wdmaud.sys\mixer.h
#define Is_Valid_Line( pLine ) ( ( pLine->SourceId != INVALID_ID ) && \
                                 ( pLine->DestId   != INVALID_ID ) )

// drivers\wdm\bda\samples\casamp\driver\inc\bdamedia.h
#define DEFINE_KSMETHOD_ITEM_BDA_CHECK_CHANGES(MethodHandler, SupportHandler)\
    DEFINE_KSMETHOD_ITEM(\
        KSMETHOD_BDA_CHECK_CHANGES,\
        KSMETHOD_TYPE_NONE,\
        (MethodHandler),\
        sizeof(KSMETHOD),\
        0,\
        SupportHandler)
#define DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_RANGE(GetHandler, SetHandler)\
    DEFINE_KSPROPERTY_ITEM(\
        KSPROPERTY_BDA_RF_TUNER_RANGE,\
        (GetHandler),\
        sizeof(KSP_NODE),\
        sizeof(ULONG),\
        (SetHandler),\
        NULL, 0, NULL, NULL, 0)

// drivers\wdm\capture\mini\atiwdm\atishare\tda9851.h
#define AUDIO_TDA9851_DefaultValue		( TDA9851_AVL_ATTACK_730	|	\
										  TDA9851_STEREO)

// drivers\wdm\capture\mini\bt848\riscprog.cpp
#define ClearMem( a ) memset( &##a, '\0', sizeof( a ) )

// drivers\wdm\capture\mini\inc\winme\61883.h
#define INIT_61883_HEADER( Av61883, Request )             \
        (Av61883)->Function = Request;                    \
        (Av61883)->Version = CURRENT_61883_DDI_VERSION;

// drivers\wdm\capture\mini\msdv\msdvfmt.h
#define FMT_DVCR_CANON       0x20  // 10:FMT(00:0000); but Canon return 00:FMT(10:0000)

// drivers\wdm\capture\mini\mstape\mstpfmt.h
#define FMT_DVCR_CANON       0x20  // 10:FMT(00:0000); but Canon return 00:FMT(10:0000)

// drivers\wdm\capture\mini\mstape\mstputil.c
#define DEVICE_NAME_MAX_CHARS   100*sizeof(WCHAR)

// drivers\wdm\capture\mini\tecra750\bert.h
#define RPS_COMMAND_DEFAULT   (RPS_COMMAND_STOP | RPS_COMMAND_WRITE |      \
                               RPS_COMMAND_RISE_EDGE | RPS_COMMAND_FWAIT | \
                               RPS_COMMAND_NOINT)
#define CAPTURE_EVEN    (ERPS | EBMV)   // DEL EREO ZGO0 97-04-07(Mon) BUN
#define CAPTURE_ODD     (ERPS | EBMV)   // mode 97-03-29(Sat) BUN
#define ACTIVE_CAPTURE_IRQS (RIE | SLIE | FOIE | LTIE | ROIE | RUIE | RLIE | PEIE)

// drivers\wdm\capture\mini\usbcamd\usbcamd\usbcamd.h
#define USBCAMD_GET_FRAME_CONTEXT(se)      (&se->MinDriverExtension[0])
#define USBCAMD_GET_DEVICE_CONTEXT(de)     ((PVOID)(&(de)->CameraDeviceContext[0]))
#define USBCAMD_GET_DEVICE_EXTENSION(dc)    (PUSBCAMD_DEVICE_EXTENSION) (((PUCHAR)(dc)) - \
                                            sizeof(USBCAMD_DEVICE_EXTENSION))

// drivers\wdm\dvd\mini\dvdts\driver\dvdcmd.h
#define IsEqualGUID2(guid1, guid2) \
	(!memcmp((guid1), (guid2), sizeof(GUID)))

// drivers\wdm\dvd\mini\dxr2\avksprop.h
#define _ADD_AV_PROPITEM_RANGE( name, property, type, read, write )\
DEFINE_KSPROPERTY_ITEM\
(\
	property,\
	read,									/* GetSupported or Handler */\
	sizeof( type ),							/* MinProperty */\
	sizeof( type ),							/* MinData */\
	write,									/* SetSupported or Handler */\
	&val##name,								/* Values */\
	0,										/* RelationsCount */\
	NULL,									/* Relations */\
	NULL,									/* SupportHandler */\
	sizeof( ULONG )							/* SerializedSize */\
)
#define _ADD_AV_PROPITEM_TYPE( property, type, read, write )\
DEFINE_KSPROPERTY_ITEM\
(\
	property,\
	read,									/* GetSupported or Handler */\
	sizeof( type ),							/* MinProperty */\
	sizeof( type ),							/* MinData */\
	write,									/* SetSupported or Handler */\
	NULL,									/* Values */\
	0,										/* RelationsCount */\
	NULL,									/* Relations */\
	NULL,									/* SupportHandler */\
	sizeof( ULONG )							/* SerializedSize */\
)
#define _ADD_AV_PROPITEM( property, read, write )\
DEFINE_KSPROPERTY_ITEM\
(\
	property,\
	read,									/* GetSupported or Handler */\
	sizeof( ULONG ),						/* MinProperty */\
	sizeof( ULONG ),						/* MinData */\
	write,									/* SetSupported or Handler */\
	NULL,									/* Values */\
	0,										/* RelationsCount */\
	NULL,									/* Relations */\
	NULL,									/* SupportHandler */\
	sizeof( ULONG )							/* SerializedSize */\
)
#define DEFINE_AV_KSPROPERTY_SET( guid, propertyname )\
	DEFINE_KSPROPERTY_SET\
	(\
		&guid,								/* Property set GUID */\
		SIZEOF_ARRAY( propertyname ),		/* Size of array of supported properties */\
		propertyname,						/* Array of supported properties */\
		0,\
		NULL\
	)

// drivers\wdm\dvd\mini\dxr2\zivaguid.h
#define IsEqualGUID2(guid1, guid2) \
	(!memcmp((guid1), (guid2), sizeof(GUID)))

// drivers\wdm\dvd\mini\sgsorig\board.h
#define Read8(Address)                     BoardRead8((PUCHAR)(Address))
#define Write8(Address,  Value)            BoardWrite8((PUCHAR)(Address),   Value)

// drivers\wdm\dvd\mini\tecra\classlib.h
#define ISMIXSTREAM(type) ((type == Dvd || type == VideoCD) ? TRUE : FALSE)

// drivers\wdm\dvd\mini\tecra\dvdwdm.h
#define IsEqualGUID2(guid1, guid2)  (!memcmp((guid1), (guid2), sizeof(GUID)))

// drivers\wdm\dvd\mini\toshiba\dvdcmd.h
#define IsEqualGUID2(guid1, guid2) \
	(!memcmp((guid1), (guid2), sizeof(GUID)))

// drivers\wdm\input\client\hclient\ddksrc\ecdisp.c
#define IS_HIDD_FUNCTION(func)        (((func) >= HIDD_GET_HID_GUID) && \
                                       ((func) <= HIDD_GET_SERIAL_NUMBER_STRING))
#define IS_HIDP_FUNCTION(func)        (((func) >= HIDP_GET_BUTTON_CAPS) && \
                                       ((func) <= HIDP_USAGE_LIST_DIFFERENCE))
#define IS_HID_FUNCTION(func)         (((func) >= HID_READ_REPORT) && \
                                       ((func) <= HID_WRITE_REPORT))
#define IS_NOT_IMPLEMENTED(func)      (((func) == HIDD_GET_CONFIGURATION) || \
                                       ((func) == HIDD_SET_CONFIGURATION) || \
                                       ((func) == HIDP_TRANSLATE_USAGES))

// drivers\wdm\input\client\hclient\ecdisp.c
#define IS_HIDD_FUNCTION(func)        (((func) >= HIDD_GET_HID_GUID) && \
                                       ((func) <= HIDD_GET_MS_GENRE_DESCRIPTOR))
#define IS_HIDP_FUNCTION(func)        (((func) >= HIDP_GET_BUTTON_CAPS) && \
                                       ((func) <= HIDP_USAGE_LIST_DIFFERENCE))
#define IS_HID_FUNCTION(func)         (((func) >= HID_READ_REPORT) && \
                                       ((func) <= HID_WRITE_REPORT))
#define IS_NOT_IMPLEMENTED(func)      (((func) == HIDD_GET_CONFIGURATION) || \
                                      ((func) == HIDD_SET_CONFIGURATION) || \
                                      ((func) == HIDP_TRANSLATE_USAGES) || \
                                      (((func) == HIDP_INITIALIZE_REPORT_FOR_ID) && \
                                       (NULL == pfnHidP_InitializeReportForID)) || \
                                      (((func) == HIDP_GET_EXTENDED_ATTRIBUTES) && \
                                       (NULL == pfnHidP_GetExtendedAttributes)))

// drivers\wdm\input\client\hidtest\handle.h
#define IS_VALID_DEVICE_HANDLE(handle)       ((INVALID_HANDLE_VALUE != (handle)) && \
                                               (NULL != (handle)))

// drivers\wdm\input\hidclass\local.h
#define SHOULD_SEND_WAITWAKE(pdoExt) (!(pdoExt)->MouseOrKeyboard && \
                                    WAITWAKE_SUPPORTED(&(pdoExt)->deviceFdoExt->fdoExt) && \
                                    !REMOTEWAKE_ON(pdoExt)       && \
                                    HidpCheckRemoteWakeEnabled(pdoExt))

// drivers\wdm\input\inc\hidtoken.h
#define HIDP_IS_MAIN_ITEM(item)  (((item) & 0xC) == 0x0)
#define HIDP_IS_GLOBAL_ITEM(item) (((item) & 0xC) == 0x4)
#define HIDP_IS_LOCAL_ITEM(item)  (((item) & 0xC) == 0x8)
#define HIDP_IS_RESERVED_ITEM(item) (((item) & 0xC) == 0xC)

// drivers\wdm\input\legacy\hidgame\hidgame.h
    #define GET_MINIDRIVER_DEVICE_EXTENSION(DO)  \
    ((PDEVICE_EXTENSION) (((PHID_DEVICE_EXTENSION)(DO)->DeviceExtension)->MiniDeviceExtension))

// drivers\wdm\input\legacy\mshgame\msgame\msgame.h
#define GET_MINIDRIVER_DEVICE_EXTENSION(DO) \
    ((PDEVICE_EXTENSION)(((PHID_DEVICE_EXTENSION)(DO)->DeviceExtension)->MiniDeviceExtension))

// drivers\wdm\input\opos\posusb\comport.c
            #define MAX_COMPORT_NAME_LEN (sizeof("COMxxxx")-1)

// drivers\wdm\input\samples\monitor\map.h
#define pvMaxA(a) (&a[cA(a)])

// drivers\wdm\input\tabletpc\buttons\buttons.h
#define GET_MINIDRIVER_DEVICE_EXTENSION(DO) \
    ((PDEVICE_EXTENSION)(((PHID_DEVICE_EXTENSION)(DO)->DeviceExtension)->MiniDeviceExtension))

// drivers\wdm\input\tabletpc\mutohpen\hidpen.h
#define GET_MINIDRIVER_DEVICE_EXTENSION(DO) \
    ((PDEVICE_EXTENSION)(((PHID_DEVICE_EXTENSION)(DO)->DeviceExtension)->MiniDeviceExtension))

// drivers\wdm\input\tools\bingen\dll\bingen.c
#define IN_USAGE_RANGE(u, umin, umax)   (((umin) <= (u)) && ((u) <= (umax)))
#define IS_VALUE_ITEM(it)               ((MI_DATA == ((it) -> miType)) && \
                                         ((FD_DATA == ((it) -> fType)) || \
                                          (FD_BUFFER == ((it) -> fType))  \
                                         )                                \
                                        )
#define IS_BUTTON_ITEM(it)             ((MI_DATA == ((it) -> miType)) &&  \
                                        ((FD_ARRAY == ((it) -> fType)) || \
                                         (FD_BUTTONS == ((it) -> fType))  \
                                        )                                 \
                                       )

// drivers\wdm\input\tools\bingen\dll\settings.c
#define OUTERROR(msg) \
{ \
    MessageBox(NULL, \
               (msg), \
               "Settings error", \
               MB_ICONEXCLAMATION | MB_OK \
              ); \
}

// drivers\wdm\usb\driver\hub.pnp\usbhub.h
#define HUB_IS_NOT_POWER_SWITCHED(hc) \
    (((hc) & HUB_CHARS_POWER_SWITCH_NONE) ==  HUB_CHARS_POWER_SWITCH_NONE)

// drivers\wdm\usb\driver\usbdiag\usbdiag.h
#define USBD_WaitForUsbDeviceMutex(de)  { USBD_KdPrint(3, ("'***WAIT dev mutex %x\n", &(de)->UsbDeviceMutex)); \
                                          KeWaitForSingleObject(&(de)->UsbDeviceMutex, \
                                                                Executive,\
                                                                KernelMode, \
                                                                FALSE, \
                                                                NULL); \
                                            }

// drivers\wdm\usb\driver\usbtest\exe\viewer\viewer.c
#define isUSBDevice(node)                                                   \
    ( (Hub == (node) -> NodeType && NULL != (node) -> ConnectionInformation) ||   \
       (MIParent == (node) -> NodeType) || (Device == (node) -> NodeType))

// drivers\wdm\usb\driver\usbtest\inc\usbtest.h
#define IsExternalHub(node)  ( (Hub == (node) -> NodeType) &&               \
                                (NULL != (node) -> ConnectionInformation) )
#define IsRootHub(node)      ( (Hub == (node) -> NodeType) &&               \
                                (NULL == (node) -> ConnectionInformation) )

// drivers\wdm\usb\driver\wceusbsh\comport.c
            #define MAX_COMPORT_NAME_LEN (sizeof("COMxxxx")-1)

// drivers\wdm\usb\hcd\miniport\usbehci\usbehci.h
#define AGERE(dd) ((dd)->Vid == 0x11c1 && (dd)->Dev == 0x5805) ? TRUE : FALSE

// drivers\wdm\usb\hcd\miniport\usbuhci\uhci.h
#define GetPID(ad)  ((ad & 0x80) == 0x80) ? InPID : OutPID

// drivers\wdm\usb\hcd\miniport\usbuhci\usbuhci.h
#define ACTUAL_FRAME(f)         ((f)&0x000003FF)
#define DecPendingTransfers(dd, ed) \
    InterlockedDecrement(&(ed)->PendingTransfers);\
    if ((ed)->Parameters.TransferType == Isochronous)\
        InterlockedDecrement(&(dd)->IsoPendingTransfers);
#define ActivateRolloverTd(dd) \
    *( ((PULONG) ((dd)->FrameListVA)) ) = (dd)->RollOverTd->PhysicalAddress;

// drivers\wdm\usb\hcd\uhcd\urb.c
#define UHCD_IS_TRANSFER(urb)    (((urb)->UrbHeader.Function == URB_FUNCTION_CONTROL_TRANSFER || \
                                   (urb)->UrbHeader.Function == URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER ||\
                                   (urb)->UrbHeader.Function == URB_FUNCTION_ISOCH_TRANSFER) \
                                         ? TRUE : FALSE)

// drivers\wdm\usb\hcd\usbport\core.c
#define IS_ON_BUSY_LIST(ep) \
    (BOOLEAN) ((ep)->BusyLink.Flink != NULL \
    && (ep)->BusyLink.Blink != NULL)

// drivers\wdm\usb\hcd\usbport\usbport.h
#define IS_ON_ATTEND_LIST(ep) \
    (BOOLEAN) ((ep)->AttendLink.Flink != NULL \
    && (ep)->AttendLink.Blink != NULL)

// drivers\wdm\usb\usbd\usbd.h
#define USBD_WaitForUsbDeviceMutex(de)  { USBD_KdPrint(3, ("'***WAIT dev mutex %x\n", &(de)->UsbDeviceMutex)); \
                                          KeWaitForSingleObject(&(de)->UsbDeviceMutex, \
                                                                Executive,\
                                                                KernelMode, \
                                                                FALSE, \
                                                                NULL); \
                                            }

// ds\adsi\ldap\ldapinc\disptmpl.h
#define LDAP_IS_TMPLITEM_OPTION_SET( ti, option )	\
	(((ti)->ti_options & option ) != 0 )
#define LDAP_IS_DISPTMPL_OPTION_SET( dt, option )	\
	(((dt)->dt_options & option ) != 0 )

// ds\adsi\ldap\ldapinc\srchpref.h
#define LDAP_IS_SEARCHOBJ_OPTION_SET( so, option )	\
	(((so)->so_options & option ) != 0 )

// ds\adsi\ldapc\pathmgmt.hxx
#define IS_EXPLICIT_PORT(dwPort) \
            ((dwPort) != USE_DEFAULT_GC_PORT) && \
            ((dwPort) != USE_DEFAULT_LDAP_PORT)

// ds\adsi\router\dbid.h
#define inrange(z,zmin,zmax) ( (zmin) <= (z) && (z) <= (zmax) )
#define DBID_IS_BOOKMARK(dbid) \
	(  DBID_USE_GUID(dbid.eKind)  &&  dbid.uGuid.guid  == DBCOL_SPECIALCOL \
	|| DBID_USE_PGUID(dbid.eKind) && *dbid.uGuid.pguid == DBCOL_SPECIALCOL )

// ds\adsi\winnt\cprops.hxx
#define DISPATCH_INDEX_VALID(dwDispid) \
            ( (((LONG)(dwDispid)) >=0 && (dwDispid) <_dwDispMaxProperties) ? TRUE : FALSE)

// ds\dns\dnsapi\dnsapip.h
#define IP6_IS_ADDR_UNSPECIFIED(a) \
        IN6_ADDR_EQUAL( (PIN6_ADDR)(a), &in6addr_any )
#define IP6_IS_ADDR_LOOPBACK(a)  \
        IN6_ADDR_EQUAL( (PIN6_ADDR)(a), &in6addr_loopback )

// ds\dns\dnslib\hostent.c
#define MIN_ADDR_BUF_SIZE   (sizeof(ATM_ADDRESS))

// ds\dns\dnslib\message.h
#define IS_SET_TO_WRITE_ANSWER_RECORDS(pMsg) \
            ((pMsg)->pCurrentCountField == &(pMsg)->MessageHead.AnswerCount)
#define IS_SET_TO_WRITE_AUTHORITY_RECORDS(pMsg) \
            ((pMsg)->pCurrentCountField == &(pMsg)->MessageHead.NameServerCount)
#define IS_SET_TO_WRITE_ADDITIONAL_RECORDS(pMsg) \
            ((pMsg)->pCurrentCountField == &(pMsg)->MessageHead.AdditionalCount)

// ds\dns\dnslib\record.c
    #define IS_LEAP_YEAR(x) \
                    (( ((x)%4)==0 && ((x)%100)!=0 ) || ((x)%400)==0 )

// ds\dns\resolver\server\ncache.c
#define IS_STATIC_RR(prr)   (IS_HOSTS_FILE_RR(prr) || IS_CLUSTER_RR(prr))

// ds\dns\server\dnsperf\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// ds\dns\server\server\dnssrv.h
#define DNS_ALL_ACCESS          ( STANDARD_RIGHTS_REQUIRED | \
                                    DNS_VIEW_ACCESS |        \
                                    DNS_ADMIN_ACCESS )
#define IS_LOCKED( pLock )  \
            ( (pLock)->LockCount > 0 )
#define IS_UNLOCKED( pLock )  \
            ( (pLock)->LockCount == 0 )

// ds\dns\server\server\ds.c
#define INIT_SINGLE_MOD_LEN(pMod)   \
        {                           \
            (pMod)->pBerval[0] = &(pMod)->Berval;       \
            (pMod)->pBerval[1] = NULL;                  \
            (pMod)->Mod.mod_bvalues = (pMod)->pBerval;  \
        }
#define INIT_SINGLE_MOD(pMod)   \
        {                       \
            (pMod)->rg_szVals[1] = NULL;                \
            (pMod)->Mod.mod_values = (pMod)->rg_szVals; \
        }

// ds\dns\server\server\msginfo.h
#define IS_WINS_XID( xid )          ( (xid) & 0x8000 )
#define IS_RECURSION_XID( xid )     ( ! ((xid) & 0xc000) )
#define MAKE_SOA_CHECK_XID( xid )   ( ((xid) & 0x1fff) | 0x6000 )
#define IS_SOA_CHECK_XID( xid )     ( ((xid) & 0xe000) == 0x6000 )
#define IS_IXFR_XID( xid )          ( ((xid) & 0xe000) == 0x4000 )

// ds\dns\server\server\nameutil.h
#define IS_ASCII_UPPER(ch)      (ch <= 'Z' && ch >= 'A')

// ds\dns\server\server\record.h
#define INDEX_FOR_TYPE(type)    \
        ( (type <= DNSSRV_MAX_SELF_INDEXED_TYPE)   \
            ? type                          \
            : RR_IndexForType(type) )
#define INDEX_FOR_QUERY_TYPE(type)    \
        ( (type <= DNSSRV_MAX_SELF_INDEXED_TYPE)   \
            ? type                          \
            : QueryIndexForType(type) )
#define IS_SPECIAL_UPDATE_TYPE(wType)   \
        (   (wType) == DNS_TYPE_NS      ||  \
            (wType) == DNS_TYPE_CNAME   ||  \
            (wType) == DNS_TYPE_SOA     )
#define IS_ALLOWED_AT_CNAME_NODE_TYPE(wType)    \
            ( (wType) == DNS_TYPE_CNAME   ||    \
            RecordTypePropertyTable             \
                [ INDEX_FOR_QUERY_TYPE(wType) ][ RECORD_PROP_WITH_CNAME ] )
#define IS_CNAME_REPLACEABLE_TYPE(wType) \
            ( (wType) == DNS_TYPE_A     ||      \
            RecordTypePropertyTable             \
                [ INDEX_FOR_QUERY_TYPE(wType) ][ RECORD_PROP_CNAME_QUERY ] )
#define IS_GLUE_TYPE(wType)  \
        (   (wType) == DNS_TYPE_A   ||  \
            (wType) == DNS_TYPE_NS  ||  \
            (wType) == DNS_TYPE_AAAA    )
#define IS_GLUE_ADDRESS_TYPE(wType)  \
        (   (wType) == DNS_TYPE_A   ||  \
            (wType) == DNS_TYPE_AAAA  )
#define IS_SUBZONE_TYPE(wType) \
        (   (wType) == DNS_TYPE_A       ||  \
            (wType) == DNS_TYPE_AAAA    ||  \
            (wType) == DNS_TYPE_KEY     ||  \
            (wType) == DNS_TYPE_SIG     )
#define IS_SUBZONE_OR_DELEGATION_TYPE(wType) \
        (   (wType) == DNS_TYPE_NS      ||  \
            (wType) == DNS_TYPE_A       ||  \
            (wType) == DNS_TYPE_AAAA    ||  \
            (wType) == DNS_TYPE_KEY     ||  \
            (wType) == DNS_TYPE_SIG     )
#define IS_NON_SCAVENGE_TYPE(wType) \
        (   (wType) != DNS_TYPE_A       &&  \
          ( (wType) == DNS_TYPE_NS      ||  \
            (wType) == DNS_TYPE_SOA     ||  \
            IS_WINS_TYPE(wType) ) )
#define IS_COMPOUND_TYPE(wType) \
        ( (wType) >= DNS_TYPE_TKEY && (wType) <= DNS_TYPE_ALL )
#define IS_COMPOUND_TYPE_EXCEPT_ANY(wType) \
        ( (wType) >= DNS_TYPE_TKEY && (wType) <= DNS_TYPE_MAILA )
#define IS_WINS_RR_AND_LOCAL(pRR)   (IS_WINS_RR(pRR) && IS_WINS_RR_LOCAL(pRR))

// ds\dns\server\server\recurse.h
#define RECURSING_ORIGINAL_QUESTION(pQuery)     \
        ( (pQuery)->Head.AnswerCount == 0 && IS_SET_TO_WRITE_ANSWER_RECORDS(pQuery) )
#define IS_CACHE_UPDATE_QUERY( pQuery ) \
                    ( (pQuery)->Socket == DNS_CACHE_UPDATE_QUERY_SOCKET )
#define IS_VALID_EDNS_VERSION(_ver)     ( _ver >= 0 && _ver < 6 )

// ds\dns\server\server\update.c
#define checkForEmptyUpdate( pUpdateList, pZone ) \
            ( !(pUpdateList->pListHead) )

// ds\dns\server\server\update.h
#define IS_UPDATE_DUPLICATE_ADD(pup)   \
        ( (pup)->wAddType == UPDATE_OP_DUPLICATE_ADD )

// ds\dns\server\server\zone.h
#define IS_ZONE_CACHE(pZone)            \
                ((pZone)->fZoneType == DNS_ZONE_TYPE_CACHE)
#define IS_ZONE_PRIMARY(pZone)          \
                ((pZone)->fZoneType == DNS_ZONE_TYPE_PRIMARY)
#define IS_ZONE_STUB(pZone)             \
                ((pZone)->fZoneType == DNS_ZONE_TYPE_STUB)
#define IS_ZONE_FORWARDER(pZone)        \
                ((pZone)->fZoneType == DNS_ZONE_TYPE_FORWARDER)
#define IS_ZONE_AUTHORITATIVE(pZone)    \
                ((pZone)->fZoneType != DNS_ZONE_TYPE_CACHE              \
                    && (pZone)->fZoneType != DNS_ZONE_TYPE_FORWARDER    \
                    && (pZone)->fZoneType != DNS_ZONE_TYPE_STUB)
#define IS_ZONE_NOTAUTH(pZone)                                      \
                ( (pZone)->fZoneType == DNS_ZONE_TYPE_FORWARDER     \
                    || (pZone)->fZoneType == DNS_ZONE_TYPE_STUB )
#define ZONE_MASTERS(pZone)                                                 \
                ( ( IS_ZONE_STUB(pZone) && (pZone)->aipLocalMasters ) ?     \
                    (pZone)->aipLocalMasters :                              \
                    (pZone)->aipMasters )
#define IS_ZONE_WINS(pZone)         ( !(pZone)->fReverse && (pZone)->pWinsRR )
#define IS_ZONE_NBSTAT(pZone)       ( (pZone)->fReverse && (pZone)->pWinsRR )
#define IS_ZONE_INACTIVE(pZone)         ( (pZone)->fPaused || (pZone)->fShutdown )
#define IS_ZONE_LOCKED_FOR_UPDATE(pZone)    \
            ( IS_ZONE_LOCKED_FOR_WRITE(pZone) && (pZone)->fUpdateLock )
#define IS_ZONE_LOCKED_FOR_WRITE_BY_THREAD(pZone)   \
            ( IS_ZONE_LOCKED_FOR_WRITE(pZone) &&    \
              (pZone)->dwLockingThreadId == GetCurrentThreadId() )
#define HAS_ZONE_VERSION_BEEN_XFRD(pZone) \
            ( (pZone)->dwLastXfrSerialNo == (pZone)->dwSerialNo )

// ds\ds\src\common\atq\atqtypes.hxx
# define IsValidAtqOp(atqOp)  \
         (((atqOp) >= AtqIoRead) && ((atqOp) <= AtqIoSendRecv))

// ds\ds\src\common\atq\pudebug.h
# define DECLARE_DEBUG_PRINTS_OBJECT()          \
         DEBUG_PRINTS  *  g_pDebug = NULL;

// ds\ds\src\inc\draatt.h
#define REPUPDREF_OPTIONS (  DRS_ASYNC_OP              \
                             | DRS_GETCHG_CHECK        \
                             | DRS_WRIT_REP            \
                             | DRS_DEL_REF             \
                             | DRS_ADD_REF)

// ds\ds\src\inc\mdglobal.h
#define VALID_CREATENCINFO(x)         ((x) && \
                                       ((x->iKind & CREATE_DOMAIN_NC) || \
                                        (x->iKind & CREATE_SCHEMA_NC) || \
                                        (x->iKind & CREATE_CONFIGURATION_NC) || \
                                        (x->iKind & CREATE_NONDOMAIN_NC)))

// ds\ds\src\inc\ntdsa.h
#define IS_VALID_UPTODATE_VECTOR(x) \
    ((1 == (x)->dwVersion) || (2 == (x)->dwVersion))
#define IS_NULL_OR_VALID_UPTODATE_VECTOR(x) \
    ((NULL == (x)) || IS_VALID_UPTODATE_VECTOR(x))
#define IS_VALID_NATIVE_UPTODATE_VECTOR(x) \
    (UPTODATE_VECTOR_NATIVE_VERSION == (x)->dwVersion)
#define IS_NULL_OR_VALID_NATIVE_UPTODATE_VECTOR(x) \
    ((NULL == (x)) || IS_VALID_NATIVE_UPTODATE_VECTOR(x))
#define IS_REMOTE_DSA_IN_SITE(pext, pSiteDN)        \
    ((NULL == (pSiteDN))                            \
     || fNullUuid(&(pSiteDN)->Guid)                 \
     || fNullUuid(SITE_GUID_FROM_DRS_EXT(pext))     \
     || (0 == memcmp(&(pSiteDN)->Guid,              \
                     SITE_GUID_FROM_DRS_EXT(pext),  \
                     sizeof(GUID))))
#define IsCallerTypeValid( x )  ( ( ( x ) >= CALLERTYPE_SAM ) && ( ( x ) <= CALLERTYPE_NTDSAPI ) )

// ds\ds\src\inc\objids.h
#define NC_MASTER_COMING              ((SYNTAX_INTEGER) (IT_WRITE | IT_NC_HEAD | IT_NC_COMING))
#define NC_FULL_REPLICA_COMING        ((SYNTAX_INTEGER) (IT_NC_HEAD | IT_NC_COMING))
#define NC_MASTER_SUBREF_COMING       ((SYNTAX_INTEGER) (IT_WRITE | IT_NC_HEAD | IT_NC_ABOVE | IT_NC_COMING))
#define NC_FULL_REPLICA_SUBREF_COMING ((SYNTAX_INTEGER) (IT_NC_HEAD | IT_NC_ABOVE | IT_NC_COMING))
#define ISVALIDINSTANCETYPE(it) \
    ((BOOL) (((it) == INT_MASTER)                    || \
             ((it) == NC_MASTER)                     || \
             ((it) == NC_MASTER_COMING)              || \
             ((it) == NC_MASTER_GOING)               || \
             ((it) == NC_MASTER_SUBREF)              || \
             ((it) == NC_MASTER_SUBREF_COMING)       || \
             ((it) == NC_MASTER_SUBREF_GOING)        || \
             ((it) == INT_FULL_REPLICA)              || \
             ((it) == NC_FULL_REPLICA)               || \
             ((it) == NC_FULL_REPLICA_COMING)        || \
             ((it) == NC_FULL_REPLICA_GOING)         || \
             ((it) == NC_FULL_REPLICA_SUBREF)        || \
             ((it) == NC_FULL_REPLICA_SUBREF_COMING) || \
             ((it) == NC_FULL_REPLICA_SUBREF_GOING)  || \
             ((it) == SUBREF)                        ))

// ds\ds\src\inc\w32toplspantree.h
#define TOPL_EX_INVALID_EDGE_TYPE         (TOPL_EX_PREFIX | 202)
#define TOPL_EX_INVALID_EDGE_SET          (TOPL_EX_PREFIX | 203)

// ds\ds\src\ldap\client\dnfilter\ovioctx.h
#define ACCEPT_BUFFER_MAX       (sizeof (SOCKADDR_IN) * 2 + 0x20)

// ds\ds\src\ldap\client\lmacros.h
#define get_socket( _conn ) (( (_conn)->UdpHandle != INVALID_SOCKET ) ? \
                               (_conn)->UdpHandle : (_conn)->TcpHandle )
#define GET_NEXT_MESSAGE_NUMBER( _msg ) {                               \
    _msg = 0;                                                           \
    if ((GlobalMessageNumber + 1) & 0xFE000000) {                       \
        GlobalMessageNumber = 0;                                        \
        MessageNumberHasWrapped = TRUE;                                 \
    }                                                                   \
    if (GlobalWin9x) {                                                  \
        while ((_msg == 0) || (_msg == (ULONG) -1)) {                   \
            LONG _prev = GlobalMessageNumber;                           \
            _msg = ++GlobalMessageNumber;                               \
            if (_prev + 1 != _msg ) {                                   \
                _msg = 0;                                               \
            }                                                           \
        }                                                               \
    } else {                                                            \
        while ((_msg == 0) || (_msg == (ULONG) -1)) {                   \
            if ( MessageNumberHasWrapped ) {                            \
                do {                                                    \
                    _msg = InterlockedIncrement( &GlobalMessageNumber );\
                        if ((_msg)&(0xFE000000)) {                      \
                            GlobalMessageNumber = 0;                    \
                        }                                               \
                } while (!IsMessageIdValid ((_msg)));                   \
            } else {                                                    \
                _msg = InterlockedIncrement( &GlobalMessageNumber );    \
            }                                                           \
        }                                                               \
    }                                                                   \
}

// ds\ds\src\ntdsa\dblayer\dbconstr.c
#define RANGE_LOWER_TAG_SIZE      (sizeof(RANGE_LOWER_TAG) - sizeof(WCHAR))
#define RANGE_UPPER_TAG_SIZE      (sizeof(RANGE_UPPER_TAG) - sizeof(WCHAR))

// ds\ds\src\ntdsa\dblayer\dbfilter.c
#define DB_UNICODE_TUPLES_LEN_MIN  (sizeof(WCHAR) * DB_TUPLES_LEN_MIN)

// ds\ds\src\ntdsa\dra\draasync.c
#define SAME_DN(a,b)                        \
    ((NULL == (a))                          \
     ? (NULL == (b))                        \
     : ((NULL != (b)) && NameMatched(a,b)))
#define SAME_MTX(a,b)                       \
    ((NULL == (a))                          \
     ? (NULL == (b))                        \
     : ((NULL != (b)) && MtxSame(a,b)))
#define SAME_DNSNAME(a,b)                      \
    ((NULL == (a))                          \
     ? (NULL == (b))                        \
     : ((NULL != (b)) && DnsNameCompare_W (a,b)))

// ds\ds\src\ntdsa\dra\drauptod.c
#define IS_VALID_USN(x) (!gfCheckForInvalidUSNs || ((x) < 1024*1024*1024))

// ds\ds\src\ntdsa\dra\drautil.c
#define NEW_SCHEMA_IS_BETTER(_newver, _curver, _newinfo, _curinfo) \
    (   (_newver > _curver) \
     || ((_newver == _curver) && (memcmp(_curinfo, _newinfo, SCHEMA_INFO_LENGTH) > 0)) )

// ds\ds\src\ntdsa\include\drautil.h
#define VALIDATE_RAISE_FQ_DOT_DNS_NAME_W( pwszName )             \
{                                                                \
    if ( pwszName &&                                             \
         ( ERROR_INVALID_NAME ==                                 \
          DnsValidateName_W( pwszName, DnsNameHostnameFull ) ||  \
          NULL == wcschr( pwszName, L'.' ) )) {                  \
        DRA_EXCEPT(DNS_ERROR_INVALID_NAME, 0);                  \
    }                                                            \
}
#define VALIDATE_RAISE_FQ_DOT_DNS_NAME_UTF8( pszName )           \
{                                                                \
    if ( pszName &&                                              \
         ( ERROR_INVALID_NAME ==                                 \
            DnsValidateName_UTF8( pszName, DnsNameHostnameFull ) || \
            NULL == strchr( pszName, '.') )) {                   \
        DRA_EXCEPT(DNS_ERROR_INVALID_NAME, 0);                  \
    }                                                            \
}

// ds\ds\src\ntdsa\include\dsatools.h
#define IS_DN_EQUAL(pDN1, pDN2)                          \
  (   ((pDN1)->AVACount        == (pDN2)->AVACount)      \
   && (NameMatched(pDN1, pDN2) == (pDN1)->AVACount)      \
  )
#define SZUUID_LEN ((2*sizeof(UUID)) + MAX_SERVER_NAME_LEN +2)

// ds\ds\src\ntdsa\include\hiertab.h
#define HT_MAX_NAME	(257 * sizeof(wchar_t))

// ds\ds\src\ntdsa\include\scache.h
#define IS_DN_VALUED_ATTR(pAC)                          \
    ((SYNTAX_DISTNAME_TYPE == (pAC)->syntax)            \
     || (SYNTAX_DISTNAME_BINARY_TYPE == (pAC)->syntax)  \
     || (SYNTAX_DISTNAME_STRING_TYPE == (pAC)->syntax))

// ds\ds\src\ntdsa\include\schgen.hxx
#define CHECKVALIDNODE(node)                         \
if ((node) == NULL || !((node)->IsInitialized()))    \
{                                                    \
    XINVALIDINIFILE();                               \
}

// ds\ds\src\ntdsa\ldap\ldapsvr.hxx
#define ATT_OPT_ALL      (ATT_OPT_BINARY | ATT_OPT_RANGE | ATT_OPT_XML)

// ds\ds\src\ntdsa\nspis\abserv.h
#define CBMAX_DISPNAME (MAX_DISPNAME * sizeof(wchar_t))

// ds\ds\src\ntdsa\src\mddit.c
#define IS_INSTALL_DSA_DSNAME(x) \
    ((((x)->NameLen * sizeof(WCHAR)) \
      == sizeof(L"CN=BootMachine,O=Boot") - sizeof(WCHAR)) \
     && (0 == memcmp(L"CN=BootMachine,O=Boot", \
                     (x)->StringName, \
                     (x)->NameLen * sizeof(WCHAR))))

// ds\ds\src\ntdsapi\dsrsa.c
    #define DsRSAHeapCreate(pHeap) \
	((*(pHeap) = HeapCreate (0L, 0L, 0L)) == NULL ? GetLastError () : NO_ERROR)

// ds\ds\src\ntdsapi\replica.c
#define SZUUID_LEN ((2*sizeof(UUID)) + MAX_PATH +2)

// ds\ds\src\sam\server\display.c
#define SampRidTableValid(DI)  (  \
    (SampDefinedDomains[DI].DisplayInformation.UserAndMachineTablesValid) &&   \
    (SampDefinedDomains[DI].DisplayInformation.GroupTableValid)                \
    )

// ds\ds\src\sam\server\samsrvp.h
#define UnicodeTerminate(p) ((PUNICODE_STRING)(p))->Buffer[(((PUNICODE_STRING)(p))->Length + 1)/sizeof(WCHAR)] = UNICODE_NULL

// ds\ds\src\sam\server\utility.c
#define IS_DELIMITER(c,_BlankOk) \
    (((c) == L' ' && (_BlankOk)) || \
    ((c) == L'\t') || ((c) == L',') || ((c) == L';'))

// ds\ds\src\util\dcdiag\repl\initial.c
#define MAX_ICMP_BUF_SIZE      ( sizeof(ICMP_ECHO_REPLY) + 0xfff7 + MAX_OPT_SIZE )

// ds\ds\src\util\ldifds\ldifldap\lexer.c
#define yy_set_interactive(is_interactive) \
	{ \
	if ( ! yy_current_buffer ) \
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
	yy_current_buffer->yy_is_interactive = is_interactive; \
	}

// ds\ds\src\util\ntdsutil\confset.cxx
#define APPEND_VALUE(_i, _p, _v)    {\
    if ( gConfSets[(_i)].ValueType == CONFSET_BOOLEAN ) {   \
                                                        \
        wcscat((_p),                                    \
               ((_v) != 0) ? L"True" : L"False");       \
    } else {                                        \
        WCHAR buf[MAX_PATH];                        \
        _itow((_v),buf,10 );                        \
        wcscat((_p), buf);                          \
    }                                               \
}

// ds\ds\src\util\ntdsutil\connect.hxx
#define CHECK_IF_NOT_CONNECTED                                          \
                                                                        \
    ( ((!ghDS || !gldapDS)                                              \
          ? NotConnectedPrintError()                                    \
          : NULL),                                                      \
      (!ghDS || !gldapDS) )

// ds\ds\src\util\ntdsutil\ldapparm.cxx
#define APPEND_VALUE(_i, _p, _v)    {\
    if ( gPolicy[(_i)].ValueType == LIMIT_BOOLEAN ) {   \
                                                        \
        wcscat((_p),                                    \
               ((_v) != 0) ? L"True" : L"False");       \
    } else {                                        \
        WCHAR buf[MAX_PATH];                        \
        _itow((_v),buf,10 );                        \
        wcscat((_p), buf);                          \
    }                                               \
}

// ds\ds\src\util\perfdsa\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// ds\ese98\eximport\exifs.h
#define DD_EXIFS_MINIRDR_PREFIX_LEN             (sizeof(DD_EXIFS_MINIRDR_PREFIX)-2)

// ds\ese98\src\ese\db.cxx
#define	FNDNullSon(b)	 		( !( (b) & fNDSon ) )

// ds\ese98\src\inc\_os\error.hxx
#define AllocJ( func, label )								\
	{														\
	if ( !static_cast< void* >( func ) )					\
		{													\
		Error( ErrERRCheck( JET_errOutOfMemory ), label );	\
		}													\
	else													\
		{													\
		err = JET_errSuccess;								\
		}													\
	}

// ds\netapi\api\getstats.c
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// ds\netapi\inc\dlwksta.h
#define MAX_WKSTA_502_TOTAL_SIZE    (sizeof(WKSTA_INFO_502))

// ds\netapi\inc\dosprtp.h
#define NetpIsPrintDestLevelValid(Level,SetInfo) \
    /*lint -save -e506 */  /* don't complain about constant values here */ \
    ( ( (SetInfo) && ((Level)==3) ) \
      || ( (Level) <= 3 ) ) \
    /*lint -restore */
#define NetpIsPrintJobLevelValid(Level,SetInfo) \
    /*lint -save -e506 */  /* don't complain about constant values here */ \
    ( ( (SetInfo) && (((Level)==1) || ((Level)==3)) ) \
      || ( (Level) <= 3 ) ) \
    /*lint -restore */
#define NetpIsPrintQLevelValid(Level,SetInfo) \
    /*lint -save -e506 */  /* don't complain about constant values here */ \
    ( ( (SetInfo) && (((Level)==1) || ((Level)==3)) ) \
      || ( (Level) <= 5 ) || ( (Level) == 52 ) ) \
    /*lint -restore */

// ds\netapi\inc\netsetup.h
#define IS_CLIENT_JOINED(plsapdinfo)                                        \
((plsapdinfo)->Sid != NULL && (plsapdinfo)->Name.Length != 0 ? TRUE : FALSE)

// ds\netapi\inc\rxsess.h
#define RxpSessionMissingErrorCode( ClientName, UserName ) \
        ( ((UserName) != NULL) \
            ? NERR_UserNotFound \
            : ( ((ClientName) != NULL)  \
                ? NERR_ClientNameNotFound \
                : NERR_Success ) )

// ds\netapi\netcmd\common\lui.c
#define LUIM_ErrMsgExit(E)		LUI_PrintMsgIns(NULL, 0, E, NULL, \
					    LUI_PMODE_ERREXT | LUI_PMODE_DEF | \
                                            LUI_PMODE_EXIT,  g_hStdErr)

// ds\netapi\netcmd\common\luidate.c
#define IS_LEAP(y)         ((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0))

// ds\netapi\netcmd\netcmd\netcmds.h
#define       MSGLST_MAXLEN   (128*sizeof(TCHAR))

// ds\netapi\netlib\luidate.c
#define IS_LEAP(y)         ((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0))

// ds\netapi\netlib\netsetp.h
#define IS_CLIENT_JOINED(plsapdinfo)                                        \
((plsapdinfo)->Sid != NULL && (plsapdinfo)->Name.Length != 0 ? TRUE : FALSE)

// ds\netapi\netlib\pathcmp.c
#define CANON_PATH_SIZE     (MAX_PATH * sizeof(TCHAR))

// ds\netapi\netlib\replinfo.c
#define MAX_DIR_NAME_SIZE       ( (PATHLEN+1) * sizeof( TCHAR ) )
#define MAX_MASTER_NAME_SIZE    ( (MAX_PATH+1)* sizeof( TCHAR ) )
#define MAX_PATH_SIZE           ( (PATHLEN+1) * sizeof( TCHAR ) )
#define MAX_USER_NAME_SIZE      ( (UNLEN+1)   * sizeof( TCHAR ) )

// ds\netapi\rpcxlate\rxapi\downlevl.h
#define NULL_REFERENCE(p)   (!(p) || !*(p))
#define VALID_STRING(s)     ((s) && *(s))   // same as !NULL_REFERENCE(s)

// ds\netapi\svcdlls\dfs\client\dfsstub.c
#define IS_UNC_PATH(wsz, cw)                                    \
    ((cw) > 2 && (wsz)[0] == L'\\' && (wsz)[1] == L'\\')
#define IS_VALID_PREFIX(wsz, cw)                                \
    ((cw) > 1 && (wsz)[0] == L'\\' && (wsz)[1] != L'\\')
#define IS_VALID_DFS_PATH(wsz, cw)                              \
    ((cw) > 0 && (wsz)[0] != L'\\')
#define IS_VALID_STRING(wsz)                                    \
    ((wsz) != NULL && (wsz)[0] != UNICODE_NULL)

// ds\netapi\svcdlls\srvsvc\server\share.c
#define IS_SLASH_SLASH_NAME( _x )   \
    ( IS_PATH_SEPARATOR( _x[0] ) && \
      IS_PATH_SEPARATOR( _x[1] ) && \
      _x[2] == L'.'              && \
      IS_PATH_SEPARATOR( _x[3] ) )
#define IS_NTPATH_NAME( _x )   \
    ( _x && \
      IS_PATH_SEPARATOR( _x[0] ) && \
      IS_PATH_SEPARATOR( _x[1] ) && \
      _x[2] == L'?'              && \
      IS_PATH_SEPARATOR( _x[3] ) )

// ds\netapi\svcdlls\upssvc\apcsmart\sysstate.h
#define IS_STATE(state)          (theUpsState & (state) ? 1 : 0)

// ds\netapi\svcimgs\ntrepl\frs\replica.c
#define CHECK_CMD_CXTION_OK     (CHECK_CMD_REPLICA |  \
                                 CHECK_CMD_CXTION)
#define CHECK_CMD_CXTION_AND_COGUID_OK  (CHECK_CMD_CXTION_OK | \
                                         CHECK_CMD_COGUID)
#define CHECK_CMD_CXTION_AND_JOINGUID_OK  (CHECK_CMD_CXTION_OK | \
                                           CHECK_CMD_JOINGUID)
#define CHECK_CXTION_JOIN_OK (CHECK_CXTION_EXISTS   |      \
                              CHECK_CXTION_JOINED   |      \
                              CHECK_CXTION_JOINGUID )

// ds\netapi\svcimgs\ntrepl\inc\frs.h
#define FRS_TRIM_LEADING_2SLASH(_Name_)                                       \
        if (((_Name_) != NULL)           &&                                   \
            (wcslen(_Name_) > 1)         &&                                   \
            ((_Name_)[0] == L'\\' )      &&                                   \
            ((_Name_)[1] == L'\\')) {                                         \
            (_Name_) += 2;                                                    \
        }
#define VV_PRINT_OUTBOUND(_Severity_, _Header_, _VV_)                       \
        DPRINT1(_Severity_, "++ VV_PRINT_OUTBOUND :%08x\n", _VV_);          \
        VVPrint(_Severity_, _Header_, _VV_, TRUE)
#define DBS_GET_FIELD_SIZE_MAX( _TableCtx, _Field)  \
                              ((_TableCtx)->pJetRetCol[_Field].cbData)
#define DBS_SET_FIELD_SIZE_MAX(_TableCtx, _Field, _NewSize)  \
                              (_TableCtx)->pJetRetCol[_Field].cbData = _NewSize;

// ds\netapi\svcimgs\ntrepl\inc\frsalloc.h
#define CHECK_CXTION_UNJOINING(_replica_, _cxtion_) \
    if (!(_cxtion_)->ChangeOrderCount && \
        CxtionStateIs(_cxtion_, CxtionStateUnjoining)) { \
        RcsSubmitReplicaCxtion(_replica_, _cxtion_, CMD_UNJOIN); \
    }
#define DOES_QHASH_LARGE_KEY_MATCH(_h_, _a_, _b_)                              \
    (!IS_QHASH_LARGE_KEY(_h_) || ((_h_)->KeyMatch)((PVOID)(_a_), (PVOID)(_b_)))
#define JOURNAL_REPLAY_MODE(_pVme_)  \
    ((_pVme_)->MonitorMaxProgressUsn > (_pVme_)->CurrentUsnRecord)
#define CAPTURE_MAX_JOURNAL_PROGRESS(_pVme_, _pp_)    \
    if (!JOURNAL_REPLAY_MODE(_pVme_)) {               \
        (_pVme_)->MonitorMaxProgressUsn = (_pp_);     \
    }
#define RSS_NAME(_state_) (((_state_) <= JRNL_STATE_MAX) ?                     \
                               ReplicaServiceState[_state_].Name :             \
                               ReplicaServiceState[JRNL_STATE_ALLOCATED].Name)
#define QHASH_EXTENSION_MAX                sizeof(QHASH_ENTRY)*50

// ds\netapi\svcimgs\ntrepl\inc\perrepsr.h
#define PM_INC_CTR_REPSET(_Replica_, _Ctr_, _Value_)                           \
{                                                                              \
    if (((_Replica_) != NULL) &&                                               \
         ((_Replica_)->PerfRepSetData != NULL) &&                              \
         ((_Replica_)->PerfRepSetData->oid != NULL)) {                         \
                                                                               \
        (_Replica_)->PerfRepSetData->FRSCounter._Ctr_ += (_Value_);            \
    }                                                                          \
}
#define PM_READ_CTR_REPSET(_Replica_, _Ctr_)                                   \
(                                                                              \
    (((_Replica_) != NULL) &&                                                  \
     ((_Replica_)->PerfRepSetData != NULL) &&                                  \
     ((_Replica_)->PerfRepSetData->oid != NULL)) ?                             \
         ((_Replica_)->PerfRepSetData->FRSCounter._Ctr_) : 0                   \
)
#define PM_INC_CTR_CXTION(_Cxtion_, _Ctr_, _Value_)                            \
{                                                                              \
    if (((_Cxtion_) != NULL) &&                                                \
        ((_Cxtion_)->PerfRepConnData != NULL) &&                               \
        ((_Cxtion_)->PerfRepConnData->oid != NULL)) {                          \
        (_Cxtion_)->PerfRepConnData->FRCCounter._Ctr_ += (_Value_);            \
    }                                                                          \
}
#define PM_READ_CTR_CXTION(_Cxtion_, _Ctr_)                                    \
(                                                                              \
    (((_Cxtion_) != NULL) &&                                                   \
     ((_Cxtion_)->PerfRepConnData != NULL) &&                                  \
     ((_Cxtion_)->PerfRepConnData->oid != NULL)) ?                             \
         ((_Cxtion_)->PerfRepConnData->FRCCounter._Ctr_) : 0                   \
)
#define PM_INC_CTR_SERVICE(_Total_, _Ctr_, _Value_)                            \
{                                                                              \
    if (((_Total_) != NULL) && ((_Total_)->oid != NULL)) {                     \
        (_Total_)->FRSCounter._Ctr_ += (_Value_);                              \
    }                                                                          \
}
#define PM_READ_CTR_SERVICE(_Total_, _Ctr_)                                    \
(                                                                              \
    (((_Total_) != NULL) && ((_Total_)->oid != NULL)) ?                        \
         ((_Total_)->FRSCounter._Ctr_) : 0                                     \
)

// ds\netapi\svcimgs\ntrepl\inc\replutil.h
#define IS_GUID_ZERO(_g_) ((*((PULONG)(_g_)+0) |                     \
                            *((PULONG)(_g_)+1) |                     \
                            *((PULONG)(_g_)+2) |                     \
                            *((PULONG)(_g_)+3) ) == 0)
#define IS_MD5_CHKSUM_ZERO(_x_)                                              \
    (((*(((PULONG) (_x_))+0)) | (*(((PULONG) (_x_))+1)) |                    \
      (*(((PULONG) (_x_))+2)) | (*(((PULONG) (_x_))+3)) ) == (ULONG) 0)
#define HANDLE_IS_VALID(_Handle)  ((_Handle) && ((_Handle) != INVALID_HANDLE_VALUE))

// ds\netapi\svcimgs\ntrepl\inc\schema.h
#define ReplicaAddrToId(_ra_)  (((_ra_) != NULL) ? \
    (_ra_)->ReplicaNumber : FRS_UNDEFINED_REPLICA_NUMBER)
#define FIELD_DT_IS_BINARY(_t_)     \
    (((_t_) == DT_BINARY)        || \
     ((_t_) == DT_IDT_EXTENSION) || \
     ((_t_) == DT_COCMD_EXTENSION))
#define CO_STATE_IS_REMOTE_RETRY(_co_)                                      \
    (CO_STATE_IS(_co_, IBCO_FETCH_RETRY) ||                                 \
     CO_STATE_IS_INSTALL_RETRY(_co_))
#define FRS_RSTYPE_IS_SYSVOL(_T_) \
        ((_T_) == FRS_RSTYPE_ENTERPRISE_SYSVOL || \
         (_T_) == FRS_RSTYPE_DOMAIN_SYSVOL)
#define FRS_RSTYPE_IS_SYSVOLW(_TW_) \
        (_TW_ && \
         (WSTR_EQ(_TW_, FRS_RSTYPE_ENTERPRISE_SYSVOLW) || \
          WSTR_EQ(_TW_, FRS_RSTYPE_DOMAIN_SYSVOLW)))
#define SET_SERVICE_STATE(_Replica_, _state_)                                 \
{                                                                             \
    DPRINT3(4, ":S: Service State change from %s to %s for %ws\n",            \
            (CNF_RECORD(_Replica_)->ServiceState < CNF_SERVICE_STATE_MAX ) ?  \
                ServiceStateNames[CNF_RECORD(_Replica_)->ServiceState]     :  \
                ServiceStateNames[CNF_SERVICE_STATE_CREATING],                \
            ServiceStateNames[(_state_)],                                     \
                                                                              \
            ((_Replica_)->ReplicaName != NULL) ?                              \
                (_Replica_)->ReplicaName->Name : L"<null>");                  \
                                                                              \
    CNF_RECORD(_Replica_)->ServiceState = (_state_);                          \
}
#define SET_SERVICE_STATE2(_Cr_, _state_)                                  \
{                                                                          \
    DPRINT3(4, ":S: Service State change from %s to %s for %ws\n",         \
            ((_Cr_)->ServiceState < CNF_SERVICE_STATE_MAX ) ?              \
                ServiceStateNames[(_Cr_)->ServiceState]     :              \
                ServiceStateNames[CNF_SERVICE_STATE_CREATING],             \
                                                                           \
            ServiceStateNames[(_state_)],                                  \
            ((_Cr_)->ReplicaSetName != NULL) ?                             \
                (_Cr_)->ReplicaSetName : L"<null>");                       \
                                                                           \
    (_Cr_)->ServiceState = (_state_);                                      \
}

// ds\netapi\svcimgs\ntrepl\mkdso\mkdso.h
#define HANDLE_IS_VALID(_Handle)  ((_Handle) && ((_Handle) != INVALID_HANDLE_VALUE))

// ds\netapi\svcimgs\ntrepl\mkdsx\mkdsx.h
#define HANDLE_IS_VALID(_Handle)  ((_Handle) && ((_Handle) != INVALID_HANDLE_VALUE))

// ds\netapi\svcimgs\ntrepl\perfdll\perfutil.c
#define EvalThisChar(c,d) ( \
      (c == d) ? DELIMITER : \
      (c == 0) ? DELIMITER : \
      (c < (WCHAR) '0') ? INVALID : \
      (c > (WCHAR) '9') ? INVALID : \
       DIGIT)

// ds\netapi\svcimgs\ntrepl\test\privs\privs.c
#define HANDLE_IS_VALID(_Handle)    ((_Handle) && \
                                     ((_Handle) != INVALID_HANDLE_VALUE))

// ds\netapi\xactsrv\apiprint.c
#define GET_LOCAL_SERVER_NAME()                                                 \
    WCHAR LocalServerName[ MAX_PATH ];                                          \
    PUCHAR p = &Header->ServerName[ NETBIOS_NAME_LEN-2 ];                       \
    for( ; p > Header->ServerName && *p == ' '; p-- );                          \
    p++;                                                                        \
    LocalServerName[0] = LocalServerName[1] = L'\\';                            \
    mbstowcs( LocalServerName+2, Header->ServerName,                            \
                                 (size_t)(p-Header->ServerName) );              \
    LocalServerName[2+p-Header->ServerName] = L'\0';

// ds\nw\convert\nwconv\nwnetapi.c
#define IS_LEAP(y)          ((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0))

// ds\nw\convert\nwconv\vlist.h
#define VLB_RANGE               (WM_USER+611)

// ds\nw\nw16\dll\procs.h
#define IS_PROTECT_MODE()   (UCHAR)((getMSW() & MSW_PE)? TRUE : FALSE)

// ds\nw\nw16\inc\nwdos.h
#define IS_ASCII_PATH_SEPARATOR(ch)     (((ch) == '/') || ((ch) == '\\'))

// ds\nw\nwlib\win95\msnwerr.h
#define NWRE_INVALID_CONNECTION     (REQUESTR_ERR | 0x01)  //connection handle is invalid
#define NWRE_SERVER_INVALID_SLOT    (REQUESTR_ERR | 0x07)
#define NWRE_INVALID_PARAMETER      (REQUESTR_ERR | 0x36)
#define NWRE_TDS_INVALID_TAG        (REQUESTR_ERR | 0x44)
#define NWRE_INVALID_SERVER_NAME    (REQUESTR_ERR | 0x59)

// ds\nw\perf\prfutil.h
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// ds\nw\rdr\const.h
#define NW_MAX_FILENAME_SIZE    ( NW_MAX_FILENAME_LENGTH * sizeof(WCHAR) )

// ds\nw\rdr\ndsprocs.h
#define MAX_CREDENTIAL_LEN      ( sizeof( NDS_CREDENTIAL ) + MAX_NDS_NAME_SIZE )

// ds\nw\rdr\procs.h
#define IS_ANONYMOUS_SCB( pScb ) \
        ( (pScb->UidServerName).Length == 0 )
#define UP_LEVEL_SERVER( Scb )  \
    ( ( Scb->MajorVersion >= 4 ) ||   \
      ( Scb->MajorVersion == 3 && Scb->MinorVersion >= 12 ) )
#define LFN_SUPPORTED( Scb )  \
    ( ( Scb->MajorVersion >= 4 ) ||   \
      ( Scb->MajorVersion == 3 && Scb->MinorVersion >= 11 ) )

// enduser\mapistub\mapistub\_glheap.h
#define _GH_Open(fCreate, ghname, dwMaxHeap) \
			HP_Open(HP_SHARED | !!(fCreate), ghname, dwMaxHeap)

// enduser\mapistub\mapistub\msvalidp.h
#define FSPECIALMETHOD(m)	(  m == IStream_Seek \
							|| m == IStream_SetSize \
							|| m == IStream_CopyTo \
							|| m == IStream_LockRegion \
							|| m == IStream_UnlockRegion \
							)

// enduser\netmeeting\as\as16\winddi.h
#define CRECTS_MAX          ((0x4000 - sizeof(RDH)) / sizeof(RECTL))

// enduser\netmeeting\as\cpi32\bcd.cpp
#define CHECK_BEST_RUN(run_type, run_length, bestrun_length, bestrun_type)   \
        if (run_length > bestrun_length)                                     \
        {                                                                    \
            bestrun_length = run_length;                                     \
            bestrun_type = run_type;                                         \
            if (bestrun_length >= 32)                                        \
            {                                                                \
                break;                                                       \
            }                                                                \
        }

// enduser\netmeeting\as\h\ast120.h
#define MG_VALID_PRIORITY(p)                                                 \
    ((((p)&~NET_SEND_ALL_PRIORITIES)<MG_HIGH_PRIORITY)?                      \
      (MG_HIGH_PRIORITY|((p)&NET_SEND_ALL_PRIORITIES)):                      \
      (((p)&~NET_SEND_ALL_PRIORITIES)>MG_LOW_PRIORITY)?                      \
        (MG_LOW_PRIORITY|((p)&NET_SEND_ALL_PRIORITIES)):                     \
        (p))

// enduser\netmeeting\as\h\awc.h
#define AWC_IS_INDICATION(msg) \
    ((msg == AWC_MSG_ACTIVE_CHANGE_LOCAL) ||      \
     (msg == AWC_MSG_ACTIVE_CHANGE_INVISIBLE) ||  \
     (msg == AWC_MSG_ACTIVE_CHANGE_CAPTURED) ||   \
     (msg == AWC_MSG_ACTIVE_CHANGE_SHARED))
#define AWC_IS_REQUEST(msg) \
    ((msg == AWC_MSG_ACTIVATE_WINDOW) ||        \
     (msg == AWC_MSG_RESTORE_WINDOW))

// enduser\netmeeting\as\h\ch.h
#define IsValidCacheIndex(pCache, iEntry) \
    ((iEntry >= 0) && (iEntry < (pCache)->cEntries))

// enduser\netmeeting\as\h\gdc.h
#define GDC_WORKBUF_SIZE    max(sizeof(GDC_IMPLODE), sizeof(GDC_EXPLODE))

// enduser\netmeeting\as\h\im.h
#define IM_KEY_IS_TOGGLE(A) \
(((A)==VK_CAPITAL)||((A)==VK_SCROLL)||((A)==VK_NUMLOCK))
#define IM_KEY_IS_MODIFIER(A) \
(((A)==VK_SHIFT)||((A)==VK_CONTROL)||((A)==VK_MENU))

// enduser\netmeeting\as\h\oa.h
#define MAX_ORDER_SIZE(pOrder) \
(INT_ORDER_SIZE(pOrder) + (pOrder->OrderHeader.cbAdditionalOrderDataLength))

// enduser\netmeeting\as\h\om.h
#define STAMP_IS_LOWER(stamp1, stamp2)                                      \
                                                                            \
   (((stamp1).genNumber  <  (stamp2).genNumber) ?                           \
    TRUE :                                                                  \
    (((stamp1).genNumber == (stamp2).genNumber)                             \
     &&                                                                     \
     ((stamp1).userID    <  (stamp2).userID)))
#define SEQ_STAMP_IS_NULL(stamp)                                            \
                                                                            \
   ((stamp.userID == 0) && (stamp.genNumber == 0))
#define CHECK_WORKSET_NOT_EXHAUSTED(pWorkset)                               \
                                                                            \
   if (pWorkset->genNumber == OM_MAX_GENERATION_NUMBER)                     \
   {                                                                        \
      WARNING_OUT(("Workset %hx exhausted", pWorkset->worksetID));          \
      rc = OM_RC_WORKSET_EXHAUSTED;                                         \
      DC_QUIT;                                                              \
   }
#define CHECK_WORKSET_NOT_LOCKED(pWorkset)                                  \
                                                                            \
   if (pWorkset->lockState == LOCK_GRANTED)                                 \
   {                                                                        \
      rc = OM_RC_WORKSET_LOCKED;                                            \
      WARNING_OUT(("Workset %hx locked - can't proceed", worksetID));       \
      DC_QUIT;                                                              \
   }
#define OBJECT_ID_IS_NULL(objectID)                                         \
                                                                            \
   (((objectID).creator  == 0) && ((objectID).sequence == 0))

// enduser\netmeeting\av\codecs\intel\g723\isrg.h
#define kMaxModules			((UINT) (kModuleBufSize/sizeof(tISRModule)))
#define kMaxISRItems		((UINT) (kISRBufSize/sizeof(tISRItem)))

// enduser\netmeeting\av\codecs\intel\h261\exutil.h
#define CLAMP_N_TO(n,low,high)	\
{						\
	if (n < low)		\
		n = low;		\
	else if (n > high)	\
		n = high; 		\
}

// enduser\netmeeting\av\rrcm\rrcminc\isrg.h
#define kMaxModules			((UINT) (kModuleBufSize/sizeof(tISRModule)))
#define kMaxISRItems		((UINT) (kISRBufSize/sizeof(tISRItem)))

// enduser\netmeeting\h\debspew.h
#define IS_VALID_HANDLE(hnd, type) \
   (IsValidH##type(hnd) ? \
    TRUE : \
    (ERROR_OUT(("invalid H" #type " - %#08lx", (hnd))), FALSE))

// enduser\netmeeting\h\isrg.h
#define kMaxModules			((UINT) (kModuleBufSize/sizeof(tISRModule)))
#define kMaxISRItems		((UINT) (kISRBufSize/sizeof(tISRItem)))

// enduser\netmeeting\h\mediacap.h
#define IsDynamicPayload(p) ((p >= RTP_DYNAMIC_MIN) && (p <= RTP_DYNAMIC_MAX))

// enduser\netmeeting\h\stock.h
#define IS_SLASH(ch)                      ((ch) == SLASH || (ch) == BACKSLASH)

// enduser\netmeeting\setup\nmmigrat\setupx.h
#define MAX_FILENAME_LEN    20      // Max. filename length. ( > sizeof( "x:\\12345678.123" )

// enduser\netmeeting\t120\h\mcattprt.h
#define IS_VALID_TRANSPORT_CONNECTION_TYPE(x) (IS_SOCKET(x) || IS_PLUGGABLE_X224(x) || IS_PLUGGABLE_PSTN(x))

// enduser\netmeeting\t120\h\memmgr.h
#define GetMemoryObject(p)				((PMemory) ((PUChar) p - (sizeof(Memory) + MAXIMUM_PROTOCOL_OVERHEAD)))

// enduser\netmeeting\ui\msconf\ulp.h
#define SIZEOF_MIME_TYPE            (MAX_MIME_TYPE_LENGTH * sizeof (TCHAR))

// enduser\speech\ce\mmio\winmmi.h
#define V_DCALLBACK(d, w, r)    { if ((d) && !ValidateCallbackType((d), (w)))

// enduser\speech\tts\ms_entropic\perfmon.cpp
#define EvalThisChar(c,d) ( \
                           (c == d) ? DELIMITER : \
                           (c == 0) ? DELIMITER : \
                           (c < (WCHAR)'0') ? INVALID : \
                           (c > (WCHAR)'9') ? INVALID : \
                           DIGIT)

// enduser\stuff\hhctrl\unicode.h
#define IN_RANGE(v, r1, r2) ((r1) <= (v) && (v) <= (r2))

// enduser\stuff\hhsetup\unicode.h
#define IN_RANGE(v, r1, r2) ((r1) <= (v) && (v) <= (r2))

// enduser\stuff\itircl\fts\breakers\convert.c
#define IS_DIGIT(p) (p >= '0' && p <= '9')

// enduser\stuff\itircl\fts\search\combine.c
#define	MAX_HEAP_ENTRIES	0xffff/sizeof(LPV)	// Maximum entries for heap sort

// enduser\stuff\itircl\fts\search\similar.c
#define IS_DIGIT(p) ((p) >= '0' && (p) <= '9')

// enduser\stuff\itircl\inc\imvfs.h
#define     FValidPos(qbtpos) \
  ((qbtpos) == NULL ? FALSE : (qbtpos)->bk != bkNil)

// enduser\stuff\itircl\inc\objects.h
#define IS_VISIBLE_MBOX(x) ((x).fBorderAtAll || (x).fHasShading || (x).fHasPattern)

// enduser\stuff\itircl\inc\wrapstor.h
#define     FValidPos(qbtpos) \
  ((qbtpos) == NULL ? FALSE : (qbtpos)->bk != bkNil)

// enduser\stuff\itircl\inc\wwheel.h
#define PWHEEL_OK(p)    ((p)!=NULL&&(p)->magic==WHEEL_MAGIC)

// enduser\stuff\itss\lzx\encoder\optenc.c
#define TREE_CREATE_CHECK()						\
if (context->enc_literals >= context->enc_next_tree_create)			\
{												\
	update_tree_estimates(context);\
	context->enc_next_tree_create += TREE_CREATE_INTERVAL;	\
}

// enduser\troubleshoot\bn\basics.h
  #define UBOUND(rg)  (sizeof rg/sizeof rg[0])

// enduser\windows.com\inc\iucommon.h
#define MAX_SETUP_MULTI_SZ_SIZE		(MAX_INF_STRING_LEN * 100 * sizeof(TCHAR))
#define MAX_SETUP_MULTI_SZ_SIZE_W	(MAX_INF_STRING_LEN * 100 * sizeof(WCHAR))	// For explicit WCHAR version

// inetcore\connectionwizard\icwdial\dialdlg.cpp
#define VALID_INIT (m_pcRNA && m_pcDLAPI)

// inetcore\connectionwizard\icwdial\dialerr.cpp
#define VALID_INIT (m_pcRNA && m_hLineApp && m_pszPhoneNumber)

// inetcore\connectionwizard\icwdl\download.h
#define BOUNDARY_LEN            (sizeof(BOUNDARY)-1)

// inetcore\connectionwizard\inc\ocdb.h
#define ICursorScroll_Scroll(pI, ulNumerator, ulDenominator, pFetchParams) \
    (*(pI)->lpVtbl->Scroll)((pI), ulNumerator, ulDenominator, pFetchParams)

// inetcore\connectionwizard\inetcfg\export.cpp
#define MIN_HTTP_ADDRESS (sizeof(SMART_HTTP) + 1)

// inetcore\connectionwizard\inetcfg\rnacall.h
#define FValidIaOrZero(pia) ((((PIADDR) (pia))->dw == 0) || FValidIa(pia))

// inetcore\connectionwizard\inetcfg\wizdef.h
#define MAX_URL_STRING (1024 + MAX_SCHEME_NAME_LENGTH + sizeof("://"))	// max length of URL

// inetcore\datacab\viaduct\msr2c\ocdb.h
#define ICursorScroll_Scroll(pI, ulNumerator, ulDenominator, pFetchParams) \
    (*(pI)->lpVtbl->Scroll)((pI), ulNumerator, ulDenominator, pFetchParams)

// inetcore\datacab\viaduct\msr2c\transact.h
#define BOID_NULL (*((BOID*)(&IID_NULL)))

// inetcore\mshtml\external\inc\vbcursor\ocdb.h
#define ICursorScroll_Scroll(pI, ulNumerator, ulDenominator, pFetchParams) \
    (*(pI)->lpVtbl->Scroll)((pI), ulNumerator, ulDenominator, pFetchParams)

// inetcore\mshtml\iextag\checkbox.hxx
#define CHECKBOX_RENDERINFO (BEHAVIORRENDERINFO_DISABLECONTENT | BEHAVIORRENDERINFO_AFTERCONTENT)

// inetcore\mshtml\src\core\include\matrix.hxx
#define FRangesOverlap(a, b, c, d)  (((a) < (d)) && ((b) > (c)))

// inetcore\mshtml\src\core\wrappers\msls.cxx
#define LSWRAP(fn,a1,a2) DYNPROC g_dynproc##fn = { NULL, &g_dynlibMSLS, #fn };

// inetcore\mshtml\src\dxt\core\mscanner\mlinescan.cpp
#define REGION(reg, xc, yc)	\
    {	                        \
    reg = 0;                    \
    if (xc > clipMaxX)		\
        reg |= RIGHT;           \
    else if (xc < clipMinX)	\
        reg |= LEFT;            \
    if (yc > clipMaxY)		\
        reg |= BELOW;           \
    else if (yc < clipMinY)	\
        reg |= ABOVE;           \
    }

// inetcore\mshtml\src\dxt\msft\src\checkerboard.cpp
#define VERTICAL_MOVEMENT ((UP == m_eDirection) || (DOWN == m_eDirection))
#define REVERSE_MOVEMENT  ((UP == m_eDirection) || (LEFT == m_eDirection))

// inetcore\mshtml\src\site\include\cfpf.hxx
#define IS_PGBRK_BEFORE_OF_STYLE(a,b)   (((a)&0x0f)==b)

// inetcore\mshtml\src\site\include\wchdefs.h
#define WCH_NODS                WCHAR(0x206f) // &nods; Nominal digit shapes

// inetcore\mshtml\src\site\view\view.cxx
#define IsRangeCrossRange(a1, a2, b1, b2) (((a2) >= (b1)) && ((a1) <= (b2)))

// inetcore\outlookexpress\autodiscovery\client\priv.h
#define MAX_URL_STRING                  (INTERNET_MAX_SCHEME_LENGTH \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// inetcore\outlookexpress\autodiscovery\test\adstress\priv.h
#define MAX_URL_STRING                  (INTERNET_MAX_SCHEME_LENGTH \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// inetcore\outlookexpress\directdb\engine\types.h
#define DBTypeValidate(_pColumn, _pTag, _pMap) \
    (*(g_rgpfnDBTypeValidate[(_pColumn)->type])) \
    ((_pColumn), _pTag, _pMap)

// inetcore\outlookexpress\inc\mirror.h
#define IS_DC_RTL_MIRRORED(hdc)          (g_bMirroredOS && Mirror_IsDCMirroredRTL(hdc))
#define IS_PROCESS_RTL_MIRRORED()        (g_bMirroredOS && Mirror_IsProcessRTL())

// inetcore\outlookexpress\inc\msoert.h
#define IS_EXTENDED(ch) \
    ((ch > 126 || ch < 32) && ch != '\t' && ch != '\n' && ch != '\r')

// inetcore\outlookexpress\inetcomm\imnxport\ixphttpm.h
#define XPFC_PROPFINDPROP   (XPCF_PFREQUEST | XPCF_MSVALIDPROP)

// inetcore\outlookexpress\inetcomm\mimeole\rfc1522.cpp
#define ISQPESCAPE(_ch) \
    (IS_EXTENDED(_ch) || _ch == '?' || _ch == '=' || \
                        _ch == '_' || _ch == '"' || \
                        _ch == '<' || _ch == '>' || \
                        _ch == '(' || _ch == ')' || \
                        _ch == '[' || _ch == ']' || \
                        _ch == ',')
#define IS_EXTENDED_W(wch) \
    ((wch > 126 || wch < 32) && wch != L'\t' && wch != L'\n' && wch != L'\r')

// inetcore\outlookexpress\inetcomm\mimeole\smime.cpp
#define MST_THIS_SIGN_ENCRYPT           (MST_THIS_SIGN | MST_THIS_ENCRYPT)

// inetcore\outlookexpress\inetcomm\mimeole\variantx.h
#define ISVALIDVARTYPE(_vartype) \
    (_vartype > MVT_EMPTY && _vartype < MVT_LAST)
#define ISVALIDSTRINGA(_pStringA) \
    (NULL != (_pStringA) && NULL != (_pStringA)->pszVal && '\0' == (_pStringA)->pszVal[(_pStringA)->cchVal])
#define ISVALIDSTRINGW(_pStringW) \
    (NULL != (_pStringW) && NULL != (_pStringW)->pszVal && L'\0' == (_pStringW)->pszVal[(_pStringW)->cchVal])
#define ISSTRINGA(_pVariant) \
    (NULL != (_pVariant) && MVT_STRINGA == (_pVariant)->type && ISVALIDSTRINGA(&((_pVariant)->rStringA)))
#define ISSTRINGW(_pVariant) \
    (NULL != (_pVariant) && MVT_STRINGW == (_pVariant)->type && ISVALIDSTRINGW(&((_pVariant)->rStringW)))

// inetcore\outlookexpress\mailnews\common\util.cpp
#define IS_EXTENDED(ch)     ((ch > 126 || ch < 32) && ch != '\t' && ch != '\n' && ch != '\r')
#define IS_BINARY(ch)       ((ch < 32) && ch != '\t' && ch != '\n' && ch != '\r')

// inetcore\outlookexpress\mailnews\common\xpcomm.h
#define IS_EXTENDED(ch)                 ((ch > 126 || ch < 32) && ch != '\t' && ch != '\n' && ch != '\r')

// inetcore\outlookexpress\mailnews\inc\thormsgs.h
#define IMAIL_SETPROGRESSRANGE  (WM_USER + 1706)

// inetcore\outlookexpress\mailnews\shell\instance.h
#define BL_DISABLE      (BL_CHECK | BL_NOTINST)
#define ITM_CREATEREMINDWINDOW      (WM_USER+5)
#define ITM_CHECKCONFIG             (WM_USER+12)

// inetcore\outlookexpress\mailnews\spooler\pop3task.cpp
#define ISVALIDPOPID(_dwPopId) \
    (_dwPopId - 1 < m_rTable.cItems)

// inetcore\outlookexpress\mapitest\sample.cli\pvalloc.h
#define cbPvMax (65520L-sizeof(PVINFO))
#define cbPvMin (1024L-sizeof(PVINFO))

// inetcore\outlookexpress\msoeacct\acctman.h
#define IS_VALID_INDEX(indx)            (((indx)>=0)&&((indx)<=MAX_INDEX))

// inetcore\outlookexpress\msoert\strutil.cpp
#define IS_DIGITA(ch)    (ch >= '0' && ch <= '9')
#define IS_DIGITW(ch)    (ch >= L'0' && ch <= L'9')

// inetcore\outlookexpress\staticrt\wstrpar.cpp
#define FGROWNEEDED(_cchWrite) (m_cchDest + _cchWrite + sizeof(WCHAR) > m_cchDestMax)

// inetcore\outlookexpress\wabw\wabapi\_itable.h
#define	UlDenominator(ul)	((ul) | !(ul))

// inetcore\outlookexpress\wabw\wabapi\glheap.h
#define _GH_Open(fCreate, ghname, dwMaxHeap) \
			HP_Open(HP_SHARED | !!(fCreate), ghname, dwMaxHeap)

// inetcore\outlookexpress\wabw\wabapi\msvalid.c
#define FSPECIALMETHOD(m)	(  m == IStream_Seek \
							|| m == IStream_SetSize \
							|| m == IStream_CopyTo \
							|| m == IStream_LockRegion \
							|| m == IStream_UnlockRegion \
							)

// inetcore\outlookexpress\wabw\wabapi\wabval.h
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

// inetcore\outlookexpress\wabw\wabfind\fnd.h
#define pvMaxA(a) (&a[cA(a)])

// inetcore\setup\ieak5\cd\autorun\autorun.c
#define dbMSG(msg,title)    (MessageBox(NULL,msg,title,MB_OK | MB_ICONINFORMATION))

// inetcore\setup\ieak5\cd\autorun\helpers.c
#define dbMSG(msg,title)    (MessageBox(NULL,msg,title,MB_OK | MB_ICONINFORMATION))

// inetcore\setup\ieak5\ieakutil\ieakutil.h
#define PIVP_EXCHAR_INVALID (PIVP_DBCS_INVALID | 0x00000080)

// inetcore\urlmon\download\wvt.cxx
#define CHECKNT5API(_fn) \
        *(FARPROC*)&(_pfn##_fn) = GetProcAddress(m_hMod, #_fn);

// inetcore\urlmon\inc\oautdll.hxx
#define CHECKOAUTAPI(_fn) \
            *(FARPROC*)&(_pfn##_fn) = GetProcAddress(_hMod, #_fn); \
            if( !(_pfn##_fn)) hr = E_UNEXPECTED;

// inetcore\urlmon\trans\bindctx.cxx
#define OBJECTPARAMKEYCHECK1 (_pbcRem &&  !wcscmp(pszKey, SZ_TRANSACTIONDATA))
#define OBJECTPARAMKEYCHECK2 (_pbcRem && wcscmp(pszKey, SZ_BINDING)         \
                                        && wcscmp(pszKey, REG_BSCB_HOLDER)  \
                                        && wcscmp(pszKey, REG_ENUMFORMATETC)\
                                        && wcscmp(pszKey, REG_MEDIA_HOLDER) \
                                        && wcscmp(pszKey, SZ_TRANSACTIONDATA))

// inetcore\urlmon\urlhlink\sdll.hxx
#define CHECKAPI(_fn) \
            *(FARPROC*)&(_pfn##_fn) = GetProcAddress(_hMod, #_fn); \
            if( !(_pfn##_fn)) hr = E_UNEXPECTED;

// inetcore\winhttp\v5.1\api\options.cxx
#define IS_PER_THREAD_OPTION(option) ((                     \
       ((option) == WINHTTP_OPTION_EXTENDED_ERROR)         \
    ) ? TRUE : FALSE)
#define IS_VALID_OPTION(option)             \
    (((((option) >= WINHTTP_FIRST_OPTION)  \
    && ((option) <= WINHTTP_LAST_OPTION_INTERNAL))  \
    ) ? TRUE : FALSE)

// inetcore\winhttp\v5.1\api\parseurl.cxx
#define IS_UNSAFE_URL_CHARACTER(Char, Scheme) \
    (((UCHAR)(Char) <= 0x20) || ((UCHAR)(Char) >= 0x7f) \
    || (SafetyList[(Char) - 0x21] & (UNSAFE | Scheme)))
#define IS_UNSAFE_URL_WIDECHARACTER(wChar, Scheme) \
    (((WCHAR)(wChar) <= 0x0020) || ((WCHAR)(wChar) >= 0x007f) \
    || (SafetyList[(wChar) - 0x0021] & (UNSAFE | Scheme)))

// inetcore\winhttp\v5.1\http\headers.h
#define MUST_REVALIDATE_LEN             (sizeof(MUST_REVALIDATE_SZ) -1)
#define MAX_AGE_LEN                     (sizeof(MAX_AGE_SZ) -1)
#define POSTCHECK_LEN                   (sizeof(POSTCHECK_SZ) -1)
#define PRECHECK_LEN                    (sizeof(PRECHECK_SZ) -1)

// inetcore\winhttp\v5.1\http\read.cxx
#define IIS_LEN     (sizeof(IIS) - 1)

// inetcore\winhttp\v5.1\http\response.cxx
#define MICROSOFT_IIS_SERVER_LEN (sizeof(MICROSOFT_IIS_SERVER_SZ) - 1)

// inetcore\winhttp\v5.1\inc\http.hxx
#define IS_VALID_HTTP_STATE(p, api, ref) \
    (p)->CheckState(HTTPREQ_STATE_ ## api ## _OK)

// inetcore\winhttp\v5.1\inc\inetsspi.h
#define IS_CRED_INVALID(s) (((s)->dwUpper == 0xFFFFFFFF) && ((s)->dwLower == 0xFFFFFFFF))

// inetcore\winhttp\v5.1\inc\tstr.h
#define IS_PATH_SEPARATOR(ch) ((ch == TCHAR_BACKSLASH) || (ch == TCHAR_FWDSLASH))
#define IS_NON_ZERO_DIGIT(c)    (((c) >= MAKE_TCHAR('1')) && ((c) <= MAKE_TCHAR('9')))

// inetcore\winhttp\v5\api\options.cxx
#define IS_PER_THREAD_OPTION(option) ((                     \
       ((option) == WINHTTP_OPTION_EXTENDED_ERROR)         \
    || ((option) == WINHTTP_OPTION_PER_CONNECTION_OPTION)  \
    ) ? TRUE : FALSE)
#define IS_VALID_OPTION(option)             \
    (((((option) >= WINHTTP_FIRST_OPTION)  \
    && ((option) <= WINHTTP_LAST_OPTION_INTERNAL))  \
    ) ? TRUE : FALSE)

// inetcore\winhttp\v5\api\parseurl.cxx
#define IS_UNSAFE_URL_CHARACTER(Char, Scheme) \
    (((UCHAR)(Char) <= 0x20) || ((UCHAR)(Char) >= 0x7f) \
    || (SafetyList[(Char) - 0x21] & (UNSAFE | Scheme)))
#define IS_UNSAFE_URL_WIDECHARACTER(wChar, Scheme) \
    (((WCHAR)(wChar) <= 0x0020) || ((WCHAR)(wChar) >= 0x007f) \
    || (SafetyList[(wChar) - 0x0021] & (UNSAFE | Scheme)))

// inetcore\winhttp\v5\http\headers.h
#define MUST_REVALIDATE_LEN             (sizeof(MUST_REVALIDATE_SZ) -1)
#define MAX_AGE_LEN                     (sizeof(MAX_AGE_SZ) -1)
#define POSTCHECK_LEN                   (sizeof(POSTCHECK_SZ) -1)
#define PRECHECK_LEN                    (sizeof(PRECHECK_SZ) -1)

// inetcore\winhttp\v5\http\read.cxx
#define IIS_LEN     (sizeof(IIS) - 1)

// inetcore\winhttp\v5\http\response.cxx
#define MICROSOFT_IIS_SERVER_LEN (sizeof(MICROSOFT_IIS_SERVER_SZ) - 1)

// inetcore\winhttp\v5\inc\http.hxx
#define IS_VALID_HTTP_STATE(p, api, ref) \
    (p)->CheckState(HTTPREQ_STATE_ ## api ## _OK)

// inetcore\winhttp\v5\inc\inetsspi.h
#define IS_CRED_INVALID(s) (((s)->dwUpper == 0xFFFFFFFF) && ((s)->dwLower == 0xFFFFFFFF))

// inetcore\winhttp\v5\inc\tstr.h
#define IS_PATH_SEPARATOR(ch) ((ch == TCHAR_BACKSLASH) || (ch == TCHAR_FWDSLASH))
#define IS_NON_ZERO_DIGIT(c)    (((c) >= MAKE_TCHAR('1')) && ((c) <= MAKE_TCHAR('9')))

// inetcore\winhttp\v5\urlcache\cachedef.h
#define IsInvalidGroup(gid) (gid & 0xE000000000000000)

// inetcore\wininet\dll\options.cxx
#define IS_PER_THREAD_OPTION(option)                        \
    (( ((option) == INTERNET_OPTION_ASYNC_ID)               \
    || ((option) == INTERNET_OPTION_EXTENDED_ERROR)         \
    || ((option) == INTERNET_OPTION_PER_CONNECTION_OPTION)  \
    ) ? TRUE : FALSE)
#define IS_VALID_OPTION(option)             \
    (((((option) >= INTERNET_FIRST_OPTION)  \
    && ((option) <= INTERNET_LAST_OPTION_INTERNAL))  \
    ) ? TRUE : FALSE)
#define IS_CONNECT_HANDLE_TYPE(handleType)          \
    ((handleType == TypeHttpRequestHandle)          \
     || (handleType == TypeHttpConnectHandle)       \
     || (handleType == TypeFtpConnectHandle)        \
     || (handleType == TypeFtpFileHandle)           \
     || (handleType == TypeFtpFindHandle)           \
     || (handleType == TypeFtpFileHandleHtml)       \
     || (handleType == TypeFtpFindHandleHtml)       \
     || (handleType == TypeGopherConnectHandle)     \
     || (handleType == TypeGopherFileHandle)        \
     || (handleType == TypeGopherFindHandle)        \
     || (handleType == TypeGopherFileHandleHtml)    \
     || (handleType == TypeGopherFindHandleHtml))

// inetcore\wininet\dll\parseurl.cxx
#define IS_UNSAFE_URL_CHARACTER(Char, Scheme) \
    (((UCHAR)(Char) <= 0x20) || ((UCHAR)(Char) >= 0x7f) \
    || (SafetyList[(Char) - 0x21] & (UNSAFE | Scheme)))

// inetcore\wininet\dll\test\asyncdl\asyncdl.c
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetcore\wininet\dll\test\cernprox\cernprox.c
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetcore\wininet\dll\test\contype\contype.c
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetcore\wininet\dll\test\openurl\openurl.c
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetcore\wininet\dll\test\ou\ou.c
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetcore\wininet\dll\test\thh\thh.c
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetcore\wininet\dll\test\tproxy\tproxy.c
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetcore\wininet\ftp\protocol.cxx
#define MAX_IPV6_ADDR_LIT_LEN (sizeof("1111:2222:3333:4444:5555:6666:255.255.255.255%4294967295"))

// inetcore\wininet\ftp\session.h
#define FtpSessionTerminate() \
    TerminateSerializedList(&FtpSessionList)

// inetcore\wininet\ftp\test\ftpcat\ftpcat.c
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetcore\wininet\ftp\test\ftpszcls\ftpszcls.cxx
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetcore\wininet\ftp\test\multfind\multfind.c
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetcore\wininet\gopher\gfrapip.h
#define GOPHER_DOT_TERMINATED_TYPES     (GOPHER_TYPE_TEXT_FILE          \
                                        | GOPHER_TYPE_DIRECTORY         \
                                        | GOPHER_TYPE_MAC_BINHEX        \
                                        | GOPHER_TYPE_UNIX_UUENCODED    \
                                        | GOPHER_TYPE_INDEX_SERVER      \
                                        )
#define IS_DOT_TERMINATED_REQUEST(request) \
    ((request & GOPHER_DOT_TERMINATED_TYPES) ? TRUE : FALSE)

// inetcore\wininet\gopher\gfrapir.h
#define IS_GOPHER_SEARCH_SERVER(type) \
    (BOOL)(((type) & (GOPHER_TYPE_CSO | GOPHER_TYPE_INDEX_SERVER)))

// inetcore\wininet\gopher\test\gc\gc.c
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetcore\wininet\http\headers.h
#define MUST_REVALIDATE_LEN             (sizeof(MUST_REVALIDATE_SZ) -1)
#define MAX_AGE_LEN                     (sizeof(MAX_AGE_SZ) -1)
#define POSTCHECK_LEN                   (sizeof(POSTCHECK_SZ) -1)
#define PRECHECK_LEN                    (sizeof(PRECHECK_SZ) -1)

// inetcore\wininet\http\read.cxx
#define IIS_LEN     (sizeof(IIS) - 1)

// inetcore\wininet\http\response.cxx
#define MICROSOFT_IIS_SERVER_LEN (sizeof(MICROSOFT_IIS_SERVER_SZ) - 1)

// inetcore\wininet\inc\http.hxx
#define IS_VALID_HTTP_STATE(p, api, ref) \
    (p)->CheckState(HTTPREQ_STATE_ ## api ## _OK)

// inetcore\wininet\inc\inetsspi.h
#define IS_CRED_INVALID(s) (((s)->dwUpper == 0xFFFFFFFF) && ((s)->dwLower == 0xFFFFFFFF))

// inetcore\wininet\inc\resolver.h
#define IS_DGRAM_SOCK(type)  (((type) == SOCK_DGRAM) || ((type) == SOCK_RAW))

// inetcore\wininet\inc\tstr.h
#define IS_PATH_SEPARATOR(ch) ((ch == TCHAR_BACKSLASH) || (ch == TCHAR_FWDSLASH))
#define IS_NON_ZERO_DIGIT(c)    (((c) >= MAKE_TCHAR('1')) && ((c) <= MAKE_TCHAR('9')))

// inetcore\wininet\socks\wsock32.c
#define INVALID_SOCKET  (int)(~0)

// inetcore\wininet\urlcache\cachedef.h
#define IsInvalidGroup(gid) (gid & 0xE000000000000000)

// inetcore\wininet\urlcache\test\creatcon\creatcon.cxx
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// inetsrv\iis\admin\adsi\adsiis\cprops.hxx
#define DISPATCH_NAME(pDispProperty)    \
            ( (pDispProperty)->szPropertyName)
#define DISPATCH_PROPERTY_NAME(dwDispid) \
            ( (_pDispProperties+(dwDispid))->szPropertyName )
#define DISPATCH_INDEX_VALID(dwDispid) \
            ( ((dwDispid) <_dwDispMaxProperties) ? TRUE : FALSE)

// inetsrv\iis\admin\adsi\adsiis\cschema.hxx
#define SIZEOF_WEBDIR_CLASS_W  (wcslen(WEBDIR_CLASS_W)+1)*sizeof(WCHAR)
#define SIZEOF_FTPVDIR_CLASS_W (wcslen(FTPVDIR_CLASS_W)+1)*sizeof(WCHAR)
#define SIZEOF_DEFAULT_CLASS_W (wcslen(DEFAULT_SCHEMA_CLASS_W)+1)*sizeof(WCHAR)

// inetsrv\iis\admin\adsi\adsiis\extension.hxx
#define REMOVE_EXTENSION_ID(dispid)   ( (dispid) & 0x00ffffff )

// inetsrv\iis\admin\adsi\helper\include\formcnst.hxx
#define EQUAL_BOOL(_x_,_y_) (((_x_) && (_y_)) || (!(_x_) && !(_y_)))

// inetsrv\iis\admin\adsi\helper\include\formdeb.h
#  define DEF_INFOLEVEL (DEB_ERROR | DEB_WARN)

// inetsrv\iis\admin\adsi\helper\include\formtrck.hxx
#  define TRACK_CLASS(fTrack, cls) \
                      ObjectTracker::TrackClass( fTrack, cls )

// inetsrv\iis\admin\adsi\helper\include\noutil.hxx
#define ADsIncrement(__ul) InterlockedIncrement((long *) &__ul)
#define ADsDecrement(__ul) InterlockedDecrement((long *) &__ul)
#define NO_COPY(cls)    \
    cls(const cls&);    \
    cls& operator=(const cls&);

// inetsrv\iis\admin\adsi\helper\include\oledserr.h
#define FIND_END_OF_LIST(record)    while(record->Next != NULL) {   \
                                        record=record->Next;        \
                                    }
#define REMOVE_FROM_LIST(record)    record->Prev->Next = record->Next;      \
                                    if (record->Next != NULL) {             \
                                        record->Next->Prev = record->Prev;  \
                                    }
#define ADD_TO_LIST(record, newRec) FIND_END_OF_LIST(record)    \
                                    record->Next = newRec;      \
                                    newRec->Prev = record;      \
                                    newRec->Next = NULL;

// inetsrv\iis\admin\adsi\helper\nocairo\output.c
#define find_char_class(c)              \
        ((c) < ' ' || (c) > 'x' ?       \
            CH_OTHER                    \
        :                               \
            lookuptable[(c)-' '] & 0xF)

// inetsrv\iis\admin\adsi\helper\noole\misc.cxx
#define CASE_SCODE(sc)  \
        case sc: lpstr = (LPWSTR)L#sc; break;

// inetsrv\iis\admin\adsi\oleds2.0\include\formcnst.hxx
#define EQUAL_BOOL(_x_,_y_) (((_x_) && (_y_)) || (!(_x_) && !(_y_)))

// inetsrv\iis\admin\adsi\oleds2.0\include\formdeb.h
#  define DEF_INFOLEVEL (DEB_ERROR | DEB_WARN)

// inetsrv\iis\admin\adsi\oleds2.0\include\formtrck.hxx
#  define TRACK_CLASS(fTrack, cls) \
                      ObjectTracker::TrackClass( fTrack, cls )

// inetsrv\iis\admin\adsi\oleds2.0\include\noutil.hxx
#define ADsIncrement(__ul) InterlockedIncrement((long *) &__ul)
#define ADsDecrement(__ul) InterlockedDecrement((long *) &__ul)
#define NO_COPY(cls)    \
    cls(const cls&);    \
    cls& operator=(const cls&);

// inetsrv\iis\admin\adsi\oleds2.0\include\oledserr.h
#define FIND_END_OF_LIST(record)    while(record->Next != NULL) {   \
                                        record=record->Next;        \
                                    }
#define REMOVE_FROM_LIST(record)    record->Prev->Next = record->Next;      \
                                    if (record->Next != NULL) {             \
                                        record->Next->Prev = record->Prev;  \
                                    }
#define ADD_TO_LIST(record, newRec) FIND_END_OF_LIST(record)    \
                                    record->Next = newRec;      \
                                    newRec->Prev = record;      \
                                    newRec->Next = NULL;

// inetsrv\iis\admin\adsi\oleds2.0\win95\win95reg.c
#define IsRegString(x) \
              ((x == REG_SZ) || (x == REG_EXPAND_SZ) || (x == REG_MULTI_SZ))

// inetsrv\iis\admin\appconfig\propsheet.h
#define SET_MODIFIED(x)\
   m_pData->m_Dirty = (x);\
   SetModified(m_pData->m_Dirty)

// inetsrv\iis\admin\certwiz\certutil.cpp
#define ISNUM(cChar)				((cChar >= _T('0')) && (cChar <= _T('9'))) ? (TRUE) : (FALSE)

// inetsrv\iis\admin\common2\error.h
#define REGISTER_FACILITY(dwCode, lpSource)\
    CError::RegisterFacility(dwCode, lpSource)

// inetsrv\iis\admin\common\common.h
#define AllocMemByType(citems, type)\
    (type *)AllocMem(citems * sizeof(type))

// inetsrv\iis\admin\common\ipa.h
  #define GETIP_FOURTH(x)            ((x)     & 0xff)

// inetsrv\iis\admin\common\msg.h
#define REGISTER_FACILITY(dwCode, lpSource)\
    CError::RegisterFacility(dwCode, lpSource)

// inetsrv\iis\admin\common\odlbox.h
#define HLS_DEFAULT         (HLS_STRETCH | HLS_BUTTONS)

// inetsrv\iis\admin\common\strfn.h
#define AllocTString(cch)\
    (LPTSTR)AllocMem((cch) * sizeof(TCHAR))

// inetsrv\iis\admin\snapin\inetprop.h
#define IS_VROOT(dwAttributes) ((dwAttributes & FILE_ATTRIBUTE_VIRTUAL_DIRECTORY) != 0)
#define IS_DIR(dwAttributes) ((dwAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
#define IS_FILE(dwAttributes) ((dwAttributes & (FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_VIRTUAL_DIRECTORY)) == 0)
#define BEGIN_META_WRITE()\
{                                               \
    HRESULT hr = S_OK;                          \
    do                                          \
    {                                           \
        m_dwaDirtyProps.RemoveAll();            \
#define HANDLE_META_RECORD(id, value)\
        case id:                                        \
            FetchMetaValue(pAllRecords, i, MP_V(value));\
            break;
#define HANDLE_INHERITED_META_RECORD(id, value, fIsInherited)\
        case id:                                                               \
            FetchInheritedMetaValue(pAllRecords, i, MP_V(value), fIsInherited);\
            break;
#define BEGIN_META_INST_READ(sheet)\
{                                                                        \
    sheet * pSheet = (sheet *)GetSheet();                                \
    do                                                                   \
    {                                                                    \
        if (FAILED(pSheet->QueryInstanceResult()))                       \
        {                                                                \
            break;                                                       \
        }
#define STORE_INST_DATA_ON_SHEET(value)\
        pSheet->GetInstanceProperties().value = value;
#define STORE_DIR_DATA_ON_SHEET(value)\
        pSheet->GetDirectoryProperties().value = value;

// inetsrv\iis\admin\snapin\machsht.h
#define STORE_MACHINE_DATA_ON_SHEET(value)\
        pSheet->GetMachineProperties().value = value;

// inetsrv\iis\admin\snapin\shts.h
#define BEGIN_META_INST_READ(sheet)\
{                                                                        \
    sheet * pSheet = (sheet *)GetSheet();                                \
    do                                                                   \
    {                                                                    \
        if (FAILED(pSheet->QueryInstanceResult()))                       \
        {                                                                \
            break;                                                       \
        }
#define STORE_INST_DATA_ON_SHEET(value)\
        pSheet->GetInstanceProperties().value = value;
#define STORE_DIR_DATA_ON_SHEET(value)\
        pSheet->GetDirectoryProperties().value = value;

// inetsrv\iis\config\src\appcenter\inc\acsmacro.h
#define ACS_SERVER_NAME_SIZE            MAX(sizeof(ACS_A_IP_STRING), (UNCLEN+1))

// inetsrv\iis\config\src\core\schemagen\tcomcatmetaxmlfile.cpp
#define     IIS_SYNTAX_ID_STRING        2   //  STRING                               EXTENDEDTYPE1                 (| EXTENDEDTYPE1")
#define     IIS_SYNTAX_ID_EXPANDSZ      3   //  EXPANDSZ                             EXTENDEDTYPE1 EXTENDEDTYPE0   (| EXTENDEDTYPE0 | EXTENDEDTYPE1")
#define     IIS_SYNTAX_ID_MULTISZ       4   //  MULTISZ                EXTENDEDTYPE2                               (| EXTENDEDTYPE2")
#define     IIS_SYNTAX_ID_BINARY        5   //  BINARY                 EXTENDEDTYPE2               EXTENDEDTYPE0   (| EXTENDEDTYPE0 | EXTENDEDTYPE2")
#define     IIS_SYNTAX_ID_NTACL        10   //  BINARY   EXTENDEDTYPE3               EXTENDEDTYPE1                 (| EXTENDEDTYPE1 | EXTENDEDTYPE3")
#define     IIS_SYNTAX_ID_HTTPERRORS   11   //  MULTISZ  EXTENDEDTYPE3               EXTENDEDTYPE1 EXTENDEDTYPE0   (| EXTENDEDTYPE0 | EXTENDEDTYPE1 | EXTENDEDTYPE3")
#define     IIS_SYNTAX_ID_HTTPHEADERS  12   //  MULTISZ  EXTENDEDTYPE3 EXTENDEDTYPE2                               (| EXTENDEDTYPE2 | EXTENDEDTYPE3")

// inetsrv\iis\config\src\inc\transact.h
#define BOID_NULL (*((BOID*)(&IID_NULL)))

// inetsrv\iis\config\src\inc\winwrap.h
#define GetStdHandle(x) \
    ((HANDLE*)_fileno( \
        ((x==STD_INPUT_HANDLE) ? stdin : \
        ((x==STD_OUTPUT_HANDLE) ? stdout : \
        ((x==STD_ERROR_HANDLE) ? stderr : NULL))) ))

// inetsrv\iis\config\src\shared\util\writer.cpp
#define g_cchMaxBuffer			g_cbMaxBuffer/sizeof(WCHAR)

// inetsrv\iis\config\src\wmi\atl30\atldb.h
#define DBID_IS_BOOKMARK(dbid) \
	(  DBID_USE_GUID(dbid.eKind)  &&  dbid.uGuid.guid  == DBCOL_SPECIALCOL \
	|| DBID_USE_PGUID(dbid.eKind) && *dbid.uGuid.pguid == DBCOL_SPECIALCOL )

// inetsrv\iis\iisrearc\core\ap\was\dll\virtual_site.h
#define MAX_SIZE_OF_SITE_DIRECTORY_NAME sizeof(VIRTUAL_SITE_DIRECTORY_NAME_PREFIX) + MAX_SIZE_BUFFER_FOR_ITOW

// inetsrv\iis\iisrearc\core\common\dtext\cvinfo.h
#define CV_TYP_IS_SIGNED(typ)   (((CV_TYPE(typ) == CV_SIGNED) && CV_TYP_IS_DIRECT(typ)) || \
                                 (typ == T_INT1)  || \
                                 (typ == T_INT2)  || \
                                 (typ == T_INT4)  || \
                                 (typ == T_INT8)  || \
                                 (typ == T_INT16) || \
                                 (typ == T_RCHAR))
#define CV_TYP_IS_UNSIGNED(typ) (((CV_TYPE(typ) == CV_UNSIGNED) && CV_TYP_IS_DIRECT(typ)) || \
                                 (typ == T_UINT1) || \
                                 (typ == T_UINT2) || \
                                 (typ == T_UINT4) || \
                                 (typ == T_UINT8) || \
                                 (typ == T_UINT16))
#define CV_TYP_IS_REAL(typ)     ((CV_TYPE(typ) == CV_REAL)  && CV_TYP_IS_DIRECT(typ))
#define CV_TYP_IS_COMPLEX(typ)  ((CV_TYPE(typ) == CV_COMPLEX)   && CV_TYP_IS_DIRECT(typ))

// inetsrv\iis\iisrearc\core\common\dtext\global.cxx
#define SHUTDOWN_TO_STRING( reason )                            \
    ((((reason) >= SHUTDOWN_REASON_ADMIN)                       \
    && ((reason) <= SHUTDOWN_REASON_FATAL_ERROR)) ?             \
    g_achShutdownReason[ (reason) ] : "<Invalid>")

// inetsrv\iis\iisrearc\core\common\dtext\vm.cxx
#define IS_MEDIUM(c)        (((c) > SMALL_REGION) && ((c) <= MEDIUM_REGION))

// inetsrv\iis\iisrearc\core\inc\pudebug.h
# define DECLARE_DEBUG_PRINTS_OBJECT()          \
         DEBUG_PRINTS  *  g_pDebug = NULL;

// inetsrv\iis\iisrearc\core\perfctrs\inc\counters.h
#define END_COUNTER_BINDING(cperfclass)                                 \
        CCounterInfo ( L"" , 0, UNKNOWN_TYPE )                          \
    };                                                                  \
    m_CounterDef.m_aCounterInfo = &_s_aBoundCounterDef[0];                           \
}                                                                       \

// inetsrv\iis\iisrearc\core\w3ctrs\perfutil.cxx
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// inetsrv\iis\iisrearc\core\wp\ulsim\httputil.h
#define IS_HTTP_UPCASE(c)       (HttpChars[(UCHAR)(c)] & HTTP_UPCASE)
#define IS_HTTP_LOCASE(c)       (HttpChars[(UCHAR)(c)] & HTTP_UPCASE)
#define IS_HTTP_ALPHA(c)        (HttpChars[(UCHAR)(c)] & HTTP_ALPHA)
#define IS_HTTP_DIGIT(c)        (HttpChars[(UCHAR)(c)] & HTTP_DIGIT)
#define IS_HTTP_CTL(c)          (HttpChars[(UCHAR)(c)] & HTTP_CTL)
#define IS_HTTP_LWS(c)          (HttpChars[(UCHAR)(c)] & HTTP_LWS)
#define IS_HTTP_SEPERATOR(c)    (HttpChars[(UCHAR)(c)] & HTTP_SEPERATOR)
#define IS_HTTP_TOKEN(c)        (HttpChars[(UCHAR)(c)] & HTTP_TOKEN)

// inetsrv\iis\iisrearc\core\wp\ulsim\parsep.h
#define MIN_VERSION_SIZE    (sizeof("HTTP/1.1\r\n") - 1)

// inetsrv\iis\iisrearc\inc\httpdef.h
#define HTTP_EQUAL_VERSION(version, major, minor)           \
    ((version).MajorVersion == (major) &&                   \
     (version).MinorVersion == (minor))
#define HTTP_GREATER_VERSION(version, major, minor)         \
    ((version).MajorVersion > (major) ||                    \
     ((version).MajorVersion == (major) &&                  \
      (version).MinorVersion > (minor)))
#define HTTP_LESS_VERSION(version, major, minor)            \
    ((version).MajorVersion < (major) ||                    \
     ((version).MajorVersion == (major) &&                  \
      (version).MinorVersion < (minor)))

// inetsrv\iis\iisrearc\ul\drv\apool.h
#define IS_VALID_AP_OBJECT(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_APP_POOL_OBJECT_POOL_TAG) && ((pObject)->RefCount > 0))
#define IS_VALID_AP_PROCESS(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_APP_POOL_PROCESS_POOL_TAG))

// inetsrv\iis\iisrearc\ul\drv\apoolp.h
#define IS_VALID_DISCONNECT_OBJECT(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_DISCONNECT_OBJECT_POOL_TAG))

// inetsrv\iis\iisrearc\ul\drv\cgroup.h
#define IS_VALID_CONFIG_GROUP(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_CG_OBJECT_POOL_TAG))
#define IS_VALID_URL_CONFIG_GROUP_INFO(pInfo) \
    (((pInfo) != NULL) && ((pInfo)->Signature == UL_CG_URL_INFO_POOL_TAG))

// inetsrv\iis\iisrearc\ul\drv\cgroupp.h
#define IS_VALID_TREE_HEADER(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_CG_TREE_HEADER_POOL_TAG))

// inetsrv\iis\iisrearc\ul\drv\config.h
#define IS_VALID_TAG(Tag)   (((Tag) & 0x0000ffff) == 'lU' )

// inetsrv\iis\iisrearc\ul\drv\control.h
#define IS_VALID_CONTROL_CHANNEL(pControlChannel) \
    (((pControlChannel) != NULL) && ((pControlChannel)->Signature == UL_CONTROL_CHANNEL_POOL_TAG))

// inetsrv\iis\iisrearc\ul\drv\fastio.h
#define IS_CHUNK_SPECIFIED( pKnownHeaders )                                 \
    (pKnownHeaders[HttpHeaderTransferEncoding].RawValueLength > 0 &&        \
     0 == _strnicmp(                                                        \
                pKnownHeaders[HttpHeaderTransferEncoding].pRawValue,        \
                "chunked",                                                  \
                strlen("chunked")                                           \
                ))                                                          \

// inetsrv\iis\iisrearc\ul\drv\filterp.h
#define IS_VALID_FILTER_CHANNEL(pFilterChannel) \
    (((pFilterChannel) != NULL) && ((pFilterChannel)->Signature == UL_FILTER_CHANNEL_POOL_TAG))
#define IS_VALID_FILTER_PROCESS(pFilterProcess) \
    (((pFilterProcess) != NULL) && ((pFilterProcess)->Signature == UL_FILTER_PROCESS_POOL_TAG))
#define IS_VALID_FILTER_CONNECTION(pConnection)                             \
    ( ((pConnection) != NULL) &&                                            \
      ((pConnection)->Signature == UX_FILTER_CONNECTION_SIGNATURE) )

// inetsrv\iis\iisrearc\ul\drv\hash.h
#define IS_VALID_HASHTABLE(pHashTable)                      \
    (NULL != (pHashTable)                                   \
     &&  NULL != (pHashTable)->pAllocMem                    \
     &&  UL_HASH_TABLE_POOL_TAG == (pHashTable)->Signature)

// inetsrv\iis\iisrearc\ul\drv\httpconnp.h
#define IS_VALID_PROC_BINDING(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_APOOL_PROC_BINDING_POOL_TAG))

// inetsrv\iis\iisrearc\ul\drv\httptdi.h
#define IS_VALID_TDI_OBJECT( pobj )                                         \
    ( ( (pobj)->Handle != NULL ) &&                                         \
      ( (pobj)->pFileObject != NULL ) &&                                    \
      ( (pobj)->pDeviceObject != NULL ) )

// inetsrv\iis\iisrearc\ul\drv\httptypes.h
#define UL_IS_VALID_REQUEST_BUFFER(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_REQUEST_BUFFER_POOL_TAG))
#define UL_IS_VALID_HTTP_CONNECTION(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_HTTP_CONNECTION_POOL_TAG) && ((pObject)->RefCount > 0))
#define UL_IS_VALID_INTERNAL_REQUEST(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_INTERNAL_REQUEST_POOL_TAG) && ((pObject)->RefCount > 0))

// inetsrv\iis\iisrearc\ul\drv\misc.h
#define IS_HTTP_UPCASE(c)       (HttpChars[(UCHAR)(c)] & HTTP_UPCASE)
#define IS_HTTP_LOCASE(c)       (HttpChars[(UCHAR)(c)] & HTTP_UPCASE)
#define IS_HTTP_ALPHA(c)        (HttpChars[(UCHAR)(c)] & HTTP_ALPHA)
#define IS_HTTP_DIGIT(c)        (HttpChars[(UCHAR)(c)] & HTTP_DIGIT)
#define IS_HTTP_HEX(c)          (HttpChars[(UCHAR)(c)] & HTTP_HEX)
#define IS_HTTP_CTL(c)          (HttpChars[(UCHAR)(c)] & HTTP_CTL)
#define IS_HTTP_LWS(c)          (HttpChars[(UCHAR)(c)] & HTTP_LWS)
#define IS_HTTP_SEPERATOR(c)    (HttpChars[(UCHAR)(c)] & HTTP_SEPERATOR)
#define IS_HTTP_TOKEN(c)        (HttpChars[(UCHAR)(c)] & HTTP_TOKEN)
#define IS_URL_TOKEN(c)         (HttpChars[(UCHAR)(c)] & URL_TOKEN)
#define IS_CONTROL_CHANNEL( pFileObject )                                   \
    ( (pFileObject)->FsContext2 == UL_CONTROL_CHANNEL_CONTEXT )
#define MARK_VALID_CONTROL_CHANNEL( pFileObject )                           \
    ( (pFileObject)->FsContext2 = UL_CONTROL_CHANNEL_CONTEXT )
#define MARK_INVALID_CONTROL_CHANNEL( pFileObject )                         \
    ( (pFileObject)->FsContext2 = UL_CONTROL_CHANNEL_CONTEXT_X )
#define IS_FILTER_PROCESS( pFileObject )                                    \
    ( (pFileObject)->FsContext2 == UL_FILTER_CHANNEL_CONTEXT )
#define IS_EX_FILTER_PROCESS( pFileObject )                                 \
    ( (pFileObject)->FsContext2 == UL_FILTER_CHANNEL_CONTEXT_X )
#define MARK_VALID_FILTER_CHANNEL( pFileObject )                            \
    ( (pFileObject)->FsContext2 = UL_FILTER_CHANNEL_CONTEXT )
#define MARK_INVALID_FILTER_CHANNEL( pFileObject )                          \
    ( (pFileObject)->FsContext2 = UL_FILTER_CHANNEL_CONTEXT_X )
#define IS_APP_POOL( pFileObject )                                          \
    ( (pFileObject)->FsContext2 == UL_APP_POOL_CONTEXT )
#define IS_EX_APP_POOL( pFileObject )                                       \
    ( (pFileObject)->FsContext2 == UL_APP_POOL_CONTEXT_X )
#define MARK_VALID_APP_POOL( pFileObject )                                  \
    ( (pFileObject)->FsContext2 = UL_APP_POOL_CONTEXT )
#define MARK_INVALID_APP_POOL( pFileObject )                                \
    ( (pFileObject)->FsContext2 = UL_APP_POOL_CONTEXT_X )
#define IS_VALID_DEVICE_OBJECT( pDeviceObject )                             \
    ( ((pDeviceObject) != NULL) &&                                          \
      ((pDeviceObject)->Type == IO_TYPE_DEVICE) &&                          \
      ((pDeviceObject)->Size == sizeof(DEVICE_OBJECT)) )
#define IS_VALID_FILE_OBJECT( pFileObject )                                 \
    ( ((pFileObject) != NULL) &&                                            \
      ((pFileObject)->Type == IO_TYPE_FILE) &&                              \
      ((pFileObject)->Size == sizeof(FILE_OBJECT)) )
#define IS_VALID_IRP( pIrp )                                                \
    ( ((pIrp) != NULL) &&                                                   \
      ((pIrp)->Type == IO_TYPE_IRP) &&                                      \
      ((pIrp)->Size >= IoSizeOfIrp((pIrp)->StackCount)) )
#define MAX_ULONG_STR sizeof("4294967295")
#define MAX_ULONGLONG_STR sizeof("18446744073709551615")

// inetsrv\iis\iisrearc\ul\drv\parsep.h
#define MIN_VERSION_SIZE    (sizeof("HTTP/1.1") - 1)

// inetsrv\iis\iisrearc\ul\drv\sendresponse.h
#define IS_FROM_MEMORY( pchunk )                                            \
    ( (pchunk)->ChunkType == HttpDataChunkFromMemory )
#define IS_FROM_FILE( pchunk )                                              \
    ( (pchunk)->ChunkType == HttpDataChunkFromFileName  ||                  \
      (pchunk)->ChunkType == HttpDataChunkFromFileHandle )
#define IS_FROM_FILE_NAME( pchunk )                                         \
    ( (pchunk)->ChunkType == HttpDataChunkFromFileName )
#define IS_FROM_FILE_HANDLE( pchunk )                                       \
    ( (pchunk)->ChunkType == HttpDataChunkFromFileHandle )
#define UL_IS_VALID_INTERNAL_RESPONSE(x)                                    \
    ( (x) != NULL && (x)->Signature == UL_INTERNAL_RESPONSE_POOL_TAG )
#define IS_VALID_CHUNK_TRACKER( tracker )                                   \
    ( ((tracker)->Signature == UL_CHUNK_TRACKER_POOL_TAG)                   \
      && ((tracker)->Type < UlTrackerTypeMaximum) )
#define IS_REQUEST_COMPLETE( tracker )                                      \
    ( (tracker)->pCurrentChunk == (tracker)->pLastChunk )
#define IS_VALID_FULL_TRACKER( tracker )                                    \
    ((tracker)->Signature == UL_FULL_TRACKER_POOL_TAG)                      \

// inetsrv\iis\iisrearc\ul\drv\ultci.h
#define IS_VALID_TCI_INTERFACE( entry )     \
    ( (entry != NULL) && ((entry)->Signature == UL_TCI_INTERFACE_POOL_TAG) )
#define IS_VALID_TCI_FLOW( entry )      \
    ( (entry != NULL) && ((entry)->Signature == UL_TCI_FLOW_POOL_TAG) )
#define IS_VALID_TCI_FILTER( entry )    \
    ( (entry != NULL) && ((entry)->Signature == UL_TCI_FILTER_POOL_TAG) )

// inetsrv\iis\iisrearc\ul\drv\ultdip.h
#define IS_VALID_IRP_CONTEXT(pIrpContext)                                   \
    ( ((pIrpContext) != NULL) &&                                            \
      ((pIrpContext)->Signature == UL_IRP_CONTEXT_SIGNATURE) )
#define IS_VALID_CONNECTION(pConnection)                                    \
    ( ((pConnection) != NULL) &&                                            \
      ((pConnection)->Signature == UL_CONNECTION_SIGNATURE) )
#define IS_VALID_RECEIVE_BUFFER(pBuffer)                                    \
    ( ((pBuffer) != NULL) &&                                                \
      ((pBuffer)->Signature == UL_RECEIVE_BUFFER_SIGNATURE) )

// inetsrv\iis\iisrearc\ul\test\dll\ulutil.c
#define READ_STRING( localaddr, locallen, remoteaddr, remotelen )           \
    do                                                                      \
    {                                                                       \
        ULONG _len;                                                         \
        RtlZeroMemory( (localaddr), (locallen) );                           \
        _len = min( (locallen), (remotelen) + sizeof(WCHAR) );              \
        RtlCopyMemory(                                                      \
            (PVOID)(localaddr),                                             \
            (PVOID)(remoteaddr),                                            \
            _len                                                            \
            );                                                              \
    } while (FALSE)

// inetsrv\iis\iisrearc\ulrtl\extcrap.h
#define IS_VALID_TAG(Tag)   (((Tag) & 0x0000ffff) == 'lU' )

// inetsrv\iis\iisrearc\ulrtl\httptypes.h
#define IS_VALID_REQUEST_BUFFER(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_REQUEST_BUFFER_POOL_TAG))
#define IS_VALID_HTTP_CONNECTION(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == HTTP_CONNECTION_POOL_TAG) && ((pObject)->RefCount > 0))
#define IS_VALID_HTTP_REQUEST(pObject) \
    (((pObject) != NULL) && ((pObject)->Signature == UL_INTERNAL_REQUEST_POOL_TAG) && ((pObject)->RefCount > 0))

// inetsrv\iis\iisrearc\ulrtl\misc.h
#define IS_HTTP_UPCASE(c)       (HttpChars[(UCHAR)(c)] & HTTP_UPCASE)
#define IS_HTTP_LOCASE(c)       (HttpChars[(UCHAR)(c)] & HTTP_UPCASE)
#define IS_HTTP_ALPHA(c)        (HttpChars[(UCHAR)(c)] & HTTP_ALPHA)
#define IS_HTTP_DIGIT(c)        (HttpChars[(UCHAR)(c)] & HTTP_DIGIT)
#define IS_HTTP_HEX(c)          (HttpChars[(UCHAR)(c)] & HTTP_HEX)
#define IS_HTTP_CTL(c)          (HttpChars[(UCHAR)(c)] & HTTP_CTL)
#define IS_HTTP_LWS(c)          (HttpChars[(UCHAR)(c)] & HTTP_LWS)
#define IS_HTTP_SEPERATOR(c)    (HttpChars[(UCHAR)(c)] & HTTP_SEPERATOR)
#define IS_HTTP_TOKEN(c)        (HttpChars[(UCHAR)(c)] & HTTP_TOKEN)
#define IS_URL_TOKEN(c)         (HttpChars[(UCHAR)(c)] & URL_TOKEN)
#define IS_CONTROL_CHANNEL( pFileObject )                                   \
    ( (pFileObject)->FsContext2 == UL_CONTROL_CHANNEL_CONTEXT )
#define MARK_VALID_CONTROL_CHANNEL( pFileObject )                           \
    ( (pFileObject)->FsContext2 = UL_CONTROL_CHANNEL_CONTEXT )
#define MARK_INVALID_CONTROL_CHANNEL( pFileObject )                         \
    ( (pFileObject)->FsContext2 = UL_CONTROL_CHANNEL_CONTEXT_X )
#define IS_APP_POOL( pFileObject )                                          \
    ( (pFileObject)->FsContext2 == UL_APP_POOL_CONTEXT )
#define IS_EX_APP_POOL( pFileObject )                                          \
    ( (pFileObject)->FsContext2 == UL_APP_POOL_CONTEXT_X )
#define MARK_VALID_APP_POOL( pFileObject )                                  \
    ( (pFileObject)->FsContext2 = UL_APP_POOL_CONTEXT )
#define MARK_INVALID_APP_POOL( pFileObject )                                \
    ( (pFileObject)->FsContext2 = UL_APP_POOL_CONTEXT_X )
#define IS_VALID_DEVICE_OBJECT( pDeviceObject )                             \
    ( ((pDeviceObject) != NULL) &&                                          \
      ((pDeviceObject)->Type == IO_TYPE_DEVICE) &&                          \
      ((pDeviceObject)->Size == sizeof(DEVICE_OBJECT)) )
#define IS_VALID_FILE_OBJECT( pFileObject )                                 \
    ( ((pFileObject) != NULL) &&                                            \
      ((pFileObject)->Type == IO_TYPE_FILE) &&                              \
      ((pFileObject)->Size == sizeof(FILE_OBJECT)) )
#define IS_VALID_IRP( pIrp )                                                \
    ( ((pIrp) != NULL) &&                                                   \
      ((pIrp)->Type == IO_TYPE_IRP) &&                                      \
      ((pIrp)->Size == IoSizeOfIrp((pIrp)->StackCount)) )

// inetsrv\iis\iisrearc\ulrtl\parsep.h
#define MIN_VERSION_SIZE    (sizeof("HTTP/1.1") - 1)

// inetsrv\iis\img\psdksamp\isapi\extensions\chunk\cte_enc.c
#define CTE_ENCODER_SIZE(dwChunkSize) \
    (sizeof(CTE_ENCODER) + dwChunkSize + CTE_MAX_ENCODING_OVERHEAD)

// inetsrv\iis\inc\tcpproc.h
#define InitUnicodeString( pUnicode, pwch )                                \
            {                                                              \
                (pUnicode)->Buffer    = pwch;                              \
                (pUnicode)->Length    = wcslen( pwch ) * sizeof(WCHAR);    \
                (pUnicode)->MaximumLength = (pUnicode)->Length + sizeof(WCHAR);\
            }

// inetsrv\iis\setup\osrc\itemlist.hxx
#define ITEMLIST_TERMINATIONCHARACTER       _T("|")

// inetsrv\iis\setup\osrc\setpass.cpp
#define InitUnicodeString( pUnicode, pwch )                                \
            {                                                              \
                (pUnicode)->Buffer    = (PWCH)pwch;                      \
                (pUnicode)->Length    = (pwch == NULL )? 0: (wcslen( pwch ) * sizeof(WCHAR));    \
                (pUnicode)->MaximumLength = (pUnicode)->Length + sizeof(WCHAR);\
            }

// inetsrv\iis\staxinc\crsapi.h
#define CRS_ADMIN_ACCESS  ( KEY_ALL_ACCESS | READ_CONTROL )

// inetsrv\iis\staxinc\crstypes.h
#define CRS_ADMIN_ACCESS  ( KEY_ALL_ACCESS | READ_CONTROL )

// inetsrv\iis\staxinc\export\artcore.h
#define MAX_ARTCORE_SIZE    sizeof( CArticleCore )

// inetsrv\iis\staxinc\export\domhash.h
#define INIT_DOMAIN_STRING_AT_COMPILE(String) \
        { \
            (sizeof(String)-sizeof(TCHAR)), /*Length*/ \
            (sizeof(String)-sizeof(TCHAR)), /*Maximum*/ \
            String                          /*String buffer*/ \
        }

// inetsrv\iis\staxinc\export\nntptype.h
#define FEED_IS_SSL( _x )           (((_x) & FEED_TYPE_SSL) != 0)
#define FEED_IS_SLAVE( _x )         (((_x) & FEED_TYPE_SLAVE) != 0)
#define FEED_IS_MASTER( _x )        (((_x) & FEED_TYPE_MASTER) != 0)
#define FEED_IS_PEER( _x )          (((_x) & 0x000000f0) == 0)
#define FEED_IS_PULL( _x )          (((_x) & 0x0000000f) == 0)
#define FEED_IS_PUSH( _x )          (((_x) & FEED_TYPE_PUSH) != 0)
#define FEED_IS_PASSIVE( _x )       (((_x) & FEED_TYPE_PASSIVE) != 0)

// inetsrv\iis\staxinc\export\rwinst.h
#define SHARE_LOCK_INST_TRACK_MINIMALS ( \
    SHARE_LOCK_INST_TRACK_EXCLUSIVE_THREADS | \
    SHARE_LOCK_INST_TRACK_SHARED_THREADS | \
    SHARE_LOCK_INST_TRACK_IN_GLOBAL_LIST )

// inetsrv\iis\staxinc\moscl.h
#define MOSERROR_INVALID_CONNECTION_TYPE    (25)    // InitMOS() & OpenMOSConnection mismatch

// inetsrv\iis\staxinc\ntlmsspi.h
#define SIC_MIN_STR_SIZE            sizeof(ULONG)
#define MSAP_EXTRA_STR_SIZE(nn)     \
                        ((nn > SIC_MIN_STR_SIZE) ? nn - SIC_MIN_STR_SIZE : 0)
#define NTLMSSP_MAX_MESSAGE_SIZE (sizeof(AUTHENTICATE_MESSAGE) + \
                                  LM_RESPONSE_LENGTH +           \
                                  NT_RESPONSE_LENGTH +           \
                                  (DNLEN_SICILY + 1) * sizeof(WCHAR) +  \
                                  (MAX_PATH + 1) * sizeof(WCHAR) +  \
                                  (MAX_PATH + 1) * sizeof(WCHAR))

// inetsrv\iis\svcs\cmp\perfmon\axperf.cpp
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// inetsrv\iis\svcs\cmp\tools\src\ismoke\wininet.h
#define IS_GOPHER_DIRECTORY(type)       (BOOL)(((type) & GOPHER_TYPE_DIRECTORY) ? TRUE : FALSE)
#define IS_GOPHER_PHONE_SERVER(type)    (BOOL)(((type) & GOPHER_TYPE_CSO) ? TRUE : FALSE)
#define IS_GOPHER_ERROR(type)           (BOOL)(((type) & GOPHER_TYPE_ERROR) ? TRUE : FALSE)
#define IS_GOPHER_INDEX_SERVER(type)    (BOOL)(((type) & GOPHER_TYPE_INDEX_SERVER) ? TRUE : FALSE)
#define IS_GOPHER_TELNET_SESSION(type)  (BOOL)(((type) & GOPHER_TYPE_TELNET) ? TRUE : FALSE)
#define IS_GOPHER_BACKUP_SERVER(type)   (BOOL)(((type) & GOPHER_TYPE_REDUNDANT) ? TRUE : FALSE)
#define IS_GOPHER_TN3270_SESSION(type)  (BOOL)(((type) & GOPHER_TYPE_TN3270) ? TRUE : FALSE)
#define IS_GOPHER_ASK(type)             (BOOL)(((type) & GOPHER_TYPE_ASK) ? TRUE : FALSE)
#define IS_GOPHER_PLUS(type)            (BOOL)(((type) & GOPHER_TYPE_GOPHER_PLUS) ? TRUE : FALSE)
#define IS_GOPHER_TYPE_KNOWN(type)      (BOOL)(((type) & GOPHER_TYPE_UNKNOWN) ? FALSE : TRUE)

// inetsrv\iis\svcs\cmp\webdav\_pclib\perfutil.cpp
#define EvalThisChar(c,d) ( \
	 (c == d) ? DELIMITER : \
	 (c == 0) ? DELIMITER : \
	 (c < (WCHAR)'0') ? INVALID : \
	 (c > (WCHAR)'9') ? INVALID : \
	 DIGIT)

// inetsrv\iis\svcs\cmp\webdav\inc\exo.h
#define EXOCLSINFO_CONTENT(_cls, _clsparent)					\
	EXOCLSINFO_CONTENT_EX( _cls, &EXOCLSINFO_NAME(_clsparent),	\
        exotypNonserver, &CLSID_NULL, NULL )

// inetsrv\iis\svcs\ftp\server51\aap.cxx
#define IS_VALID_AAP_STATE(x)   (((x) > AapStateFirst) && ((x) < AapStateLast))
#define IS_VALID_AAP_CONTEXT(p) (((p) != NULL) && ((p)->Signature == AAP_SIGNATURE))

// inetsrv\iis\svcs\ftp\server51\auxctrs.h
# define FacIncrement( facCounter)   \
 (((facCounter) < FacMaxCounters) ?  \
  InterlockedIncrement( g_AuxCounters+(facCounter)) : \
  0)
# define FacDecrement( facCounter)   \
 (((facCounter) < FacMaxCounters) ?  \
  InterlockedDecrement( g_AuxCounters+(facCounter)) : \
  0)

// inetsrv\iis\svcs\ftp\server51\ftpcmd.hxx
#define IS_VALID_ARG_TYPE(x)    (((x) > ArgTypeFirst) && ((x) < ArgTypeLast))

// inetsrv\iis\svcs\ftp\server51\lsaux.hxx
#define IS_HIDDEN(dwAttrib)   \
           ((((dwAttrib) & FILE_ATTRIBUTE_HIDDEN) == 0)? FALSE: TRUE)
#define IS_SYSTEM(dwAttrib)   \
           ((((dwAttrib) & FILE_ATTRIBUTE_SYSTEM) == 0)? FALSE: TRUE)
#define IS_DIR(dwAttrib)      \
           ((((dwAttrib) & FILE_ATTRIBUTE_DIRECTORY) == 0)? FALSE: TRUE)
#define IS_EMPTY_PATH(pszPath)   ((pszPath == NULL ) || ( *pszPath == '\0'))

// inetsrv\iis\svcs\ftp\server51\newls.cxx
#define SORT_INDEX(method, dirn)   ((INT)(method) + \
                                    ((dirn) ? (INT)MaxLsSort : 0))

// inetsrv\iis\svcs\ftp\server51\proc.hxx
#define IS_PATH_SEP(x) (((x) == '\\') || ((x) == '/'))

// inetsrv\iis\svcs\ftp\server51\type.hxx
#define IS_VALID_ACCESS_TYPE(x) \
    (((x) > AccessTypeFirst) && ((x) < AccessTypeLast))
#define IS_VALID_XFER_TYPE(x)   (((x) > XferTypeFirst) && ((x) < XferTypeLast))
#define IS_VALID_XFER_MODE(x)   (((x) > XferModeFirst) && ((x) < XferModeLast))
#define IS_VALID_USER_STATE(x) (((x) >UserStateFirst) && ((x) <UserStateLast))
#define IS_VALID_USER_DATA(p)   (((p) != NULL) && ((p)->Signature == USER_SIGNATURE))

// inetsrv\iis\svcs\ftp\server\aap.cxx
#define IS_VALID_AAP_STATE(x)   (((x) > AapStateFirst) && ((x) < AapStateLast))
#define IS_VALID_AAP_CONTEXT(p) (((p) != NULL) && ((p)->Signature == AAP_SIGNATURE))

// inetsrv\iis\svcs\ftp\server\auxctrs.h
# define FacIncrement( facCounter)   \
 (((facCounter) < FacMaxCounters) ?  \
  InterlockedIncrement( g_AuxCounters+(facCounter)) : \
  0)
# define FacDecrement( facCounter)   \
 (((facCounter) < FacMaxCounters) ?  \
  InterlockedDecrement( g_AuxCounters+(facCounter)) : \
  0)

// inetsrv\iis\svcs\ftp\server\ftpcmd.hxx
#define IS_VALID_ARG_TYPE(x)    (((x) > ArgTypeFirst) && ((x) < ArgTypeLast))

// inetsrv\iis\svcs\ftp\server\lsaux.hxx
#define IS_HIDDEN(dwAttrib)   \
           ((((dwAttrib) & FILE_ATTRIBUTE_HIDDEN) == 0)? FALSE: TRUE)
#define IS_SYSTEM(dwAttrib)   \
           ((((dwAttrib) & FILE_ATTRIBUTE_SYSTEM) == 0)? FALSE: TRUE)
#define IS_DIR(dwAttrib)      \
           ((((dwAttrib) & FILE_ATTRIBUTE_DIRECTORY) == 0)? FALSE: TRUE)
#define IS_EMPTY_PATH(pszPath)   ((pszPath == NULL ) || ( *pszPath == '\0'))

// inetsrv\iis\svcs\ftp\server\newls.cxx
#define SORT_INDEX(method, dirn)   ((INT)(method) + \
                                    ((dirn) ? (INT)MaxLsSort : 0))

// inetsrv\iis\svcs\ftp\server\proc.hxx
#define IS_PATH_SEP(x) (((x) == '\\') || ((x) == '/'))

// inetsrv\iis\svcs\ftp\server\type.hxx
#define IS_VALID_ACCESS_TYPE(x) \
    (((x) > AccessTypeFirst) && ((x) < AccessTypeLast))
#define IS_VALID_XFER_TYPE(x)   (((x) > XferTypeFirst) && ((x) < XferTypeLast))
#define IS_VALID_XFER_MODE(x)   (((x) > XferModeFirst) && ((x) < XferModeLast))
#define IS_VALID_USER_STATE(x) (((x) >UserStateFirst) && ((x) <UserStateLast))
#define IS_VALID_USER_DATA(p)   (((p) != NULL) && ((p)->Signature == USER_SIGNATURE))

// inetsrv\iis\svcs\iisrtl\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// inetsrv\iis\svcs\infocomm\atq\atqtypes.hxx
# define IsValidAtqOp(atqOp)  \
         (((atqOp) >= AtqIoRead) && ((atqOp) <= AtqIoSendRecv))

// inetsrv\iis\svcs\infocomm\cache\oplock\tsunamip.hxx
#define BLOB_IS_OR_WAS_CACHED( pvBlob )   \
                 ( (((PBLOB_HEADER)pvBlob)-1)->IsCached )
#define BLOB_IS_EJECTATE( pvBlob )        \
                ( IsListEmpty(&(((PBLOB_HEADER)pvBlob)-1)->pCache->BinList) )
#define BLOB_IS_OR_WAS_CACHED( pvBlob )   \
                ( (((PBLOB_HEADER)pvBlob)-1)->IsCached )
#define BLOB_IS_EJECTATE( pvBlob )        \
                ( IsListEmpty(&(((PBLOB_HEADER)pvBlob)-1)->pCache->BinList) )
#define BLOB_IS_UNC( pvBlob ) \
                ( (((PBLOB_HEADER)pvBlob)-1)->pCache->szPath[1] == '\\' )

// inetsrv\iis\svcs\infocomm\cache\tsunamip.hxx
#define BLOB_IS_OR_WAS_CACHED( pvBlob )   \
                 ( (((PBLOB_HEADER)pvBlob)-1)->IsCached )
#define BLOB_IS_EJECTATE( pvBlob )        \
                ( IsListEmpty(&(((PBLOB_HEADER)pvBlob)-1)->pCache->BinList) )
#define BLOB_IS_OR_WAS_CACHED( pvBlob )   \
                ( (((PBLOB_HEADER)pvBlob)-1)->IsCached )
#define BLOB_IS_EJECTATE( pvBlob )        \
                ( IsListEmpty(&(((PBLOB_HEADER)pvBlob)-1)->pCache->BinList) )
#define BLOB_IS_UNC( pvBlob ) \
                ( (((PBLOB_HEADER)pvBlob)-1)->pCache->szPath[1] == '\\' )

// inetsrv\iis\svcs\infocomm\dcomadm\comtest\beta2\main.cxx
#define MAX_BUFFER_LEN     MY_GREATEROF((MD_TEST_MAX_STRING_LEN * sizeof(TCHAR)), MD_TEST_MAX_BINARY_LEN)

// inetsrv\iis\svcs\infocomm\dcomadm\comtest\main.cxx
#define MAX_BUFFER_LEN     MY_GREATEROF((MD_TEST_MAX_STRING_LEN * sizeof(TCHAR)), MD_TEST_MAX_BINARY_LEN)

// inetsrv\iis\svcs\infocomm\dcomadm\dll\coiadm.hxx
#define IS_MD_PATH_DELIM(a) ((a)==L'/' || (a)==L'\\')

// inetsrv\iis\svcs\infocomm\dcomadm\unitest\main.cxx
#define MAX_BUFFER_LEN     MY_GREATEROF((MD_TEST_MAX_STRING_LEN * sizeof(WCHAR)), MD_TEST_MAX_BINARY_LEN)

// inetsrv\iis\svcs\infocomm\info\client\infostub.c
#define _InitUnicodeString( pUnicode, pwch )                       \
   {                                                               \
        (pUnicode)->Buffer    = pwch;                              \
        (pUnicode)->Length    = wcslen( pwch ) * sizeof(WCHAR);    \
        (pUnicode)->MaximumLength = (pUnicode)->Length + sizeof(WCHAR); \
   }

// inetsrv\iis\svcs\infocomm\metadata\comtest\main.cxx
#define MAX_BUFFER_LEN     MY_GREATEROF((MD_TEST_MAX_STRING_LEN * sizeof(TCHAR)), MD_TEST_MAX_BINARY_LEN)

// inetsrv\iis\svcs\infocomm\metadata\dlltest\main.c
#define MAX_BUFFER_LEN     MY_GREATEROF((METADATA_MAX_STRING_LEN * sizeof(TCHAR)), METADATA_MAX_BINARY_LEN)

// inetsrv\iis\svcs\infocomm\metadata\inc\writer.h
#define g_cchMaxBuffer			g_cbMaxBuffer/sizeof(WCHAR)

// inetsrv\iis\svcs\infocomm\metadata\unitest\main.cxx
#define MAX_BUFFER_LEN     MY_GREATEROF((MD_TEST_MAX_STRING_LEN * sizeof(TCHAR)), MD_TEST_MAX_BINARY_LEN)

// inetsrv\iis\svcs\infocomm\setup\dbgutil.h
# define DECLARE_DEBUG_PRINTS_OBJECT()          \
         DEBUG_PRINTS  *  g_pDebug = NULL;

// inetsrv\iis\svcs\loadbal\pdh\perftype.h
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// inetsrv\iis\svcs\nntp\adminsso\ipaccess.cpp
#define GETIP_FOURTH(x)            ((x)     & 0xff)

// inetsrv\iis\svcs\nntp\core\include\nntpret.h
#define NNTPRET_IS_ERROR(__dwErrorCode__) (__dwErrorCode__ >= 400 && __dwErrorCode__ < 600)

// inetsrv\iis\svcs\nntp\core\include\nntptype.h
#define FEED_IS_SSL( _x )           (((_x) & FEED_TYPE_SSL) != 0)
#define FEED_IS_SLAVE( _x )         (((_x) & FEED_TYPE_SLAVE) != 0)
#define FEED_IS_MASTER( _x )        (((_x) & FEED_TYPE_MASTER) != 0)
#define FEED_IS_PEER( _x )          (((_x) & 0x000000f0) == 0)
#define FEED_IS_PULL( _x )          (((_x) & 0x0000000f) == 0)
#define FEED_IS_PUSH( _x )          (((_x) & FEED_TYPE_PUSH) != 0)
#define FEED_IS_PASSIVE( _x )       (((_x) & FEED_TYPE_PASSIVE) != 0)

// inetsrv\iis\svcs\nntp\core\include\tigtypes.h
#define	INVALID_ARTICLEID	((ARTICLEID)(~0))
#define INVALID_GROUPID     ((GROUPID)(~0))

// inetsrv\iis\svcs\nntp\nntpctrs\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// inetsrv\iis\svcs\nntp\server\article\src\frmstore.cpp
#define MAX_ARTICLE_SIZE    sizeof( CFromStoreArticle )

// inetsrv\iis\svcs\nntp\server\hash\src\nntphash.h
#define	INVALID_ARTICLEID	((ARTICLEID)(~0))

// inetsrv\iis\svcs\nntp\server\post\utest\artsupp.cpp
#define MAX_ARTICLE_SIZE    max(    sizeof( CArticle ), \
                            max(    sizeof( CFromPeerArticle ), \
                            max(    sizeof( CFromClientArticle ),   \
                            sizeof( CFromMasterArticle )   	\
                             ) ) )

// inetsrv\iis\svcs\nntp\server\post\utest\cfeed.cpp
#define MAX_FEED_SIZE   max(    sizeof( CFeed ),    \
                            max(    sizeof( COutFeed ), \
                            max(    sizeof( CInFeed ),  \
                            max(    sizeof( CFromPeerFeed ),    \
                            max(    sizeof( CFromMasterFeed ),  \
                                    sizeof( CFromClientFeed )   \
                             ) ) ) ) )

// inetsrv\iis\svcs\nntp\server\server\artsupp.cpp
#define MAX_ARTICLE_SIZE    max(    sizeof( CArticle ), \
                            max(    sizeof( CFromPeerArticle ), \
                            max(    sizeof( CFromClientArticle ),   \
                            max(    sizeof( CFromMasterArticle ),   \
                                    sizeof( CToClientArticle )  \
                             ) ) ) )

// inetsrv\iis\svcs\nntp\server\server\cfeed.cpp
#define MAX_FEED_SIZE   max(    sizeof( CFeed ),    \
                            max(    sizeof( COutFeed ), \
                            max(    sizeof( CInFeed ),  \
                            max(    sizeof( CFromPeerFeed ),    \
                            max(    sizeof( CFromMasterFeed ),  \
                                    sizeof( CFromClientFeed )   \
                             ) ) ) ) )

// inetsrv\iis\svcs\nntp\server\server\cio.h
#define	MAX_IO_SIZE		max(	sizeof( CIO ),	\
								max( max( sizeof( CIOReadArticle ), sizeof( CIOGetArticle)),	\
									max( sizeof( CIOWriteLine ),	\
										max( sizeof( CIOTransmit ) ,	\
											max( sizeof( CIOPassThru ),		\
												max( sizeof( CIOServerSSL ), sizeof( CIOReadLine ) ) ) ) ) ) )

// inetsrv\iis\svcs\nntp\server\server\commands.h
#define	MAX_CEXECUTE_SIZE max(sizeof(CErrorCmd),\
max(sizeof(CAuthinfoCmd),\
max(sizeof(CListCmd),\
max(sizeof(CModeCmd),\
max(sizeof(CNewgroupsCmd),\
max(sizeof(CNextCmd),\
max(sizeof(CXOverCmd),\
sizeof( CUnimpCmd )))))))))
#define	MAX_CEXECUTE_SIZE max(max(max(sizeof(CErrorCmd),\
max(sizeof(CSlaveCmd),sizeof(CAuthinfoCmd))),\
max(max(sizeof(CStatCmd),max(sizeof(CDateCmd),sizeof(CListCmd))),\
max(max(max(sizeof(CModeCmd),sizeof(CXPatCmd)),\
max(max(sizeof(CGroupCmd),sizeof(CLastCmd)),sizeof(CNewgroupsCmd))),\
max(max(sizeof(CNextCmd),sizeof(CNewnewsCmd)),\
max(max(sizeof(CHelpCmd),sizeof(CXHdrCmd)),sizeof(CXOverCmd)))))),\
max(max(sizeof(CQuitCmd),sizeof(CSearchCmd)),sizeof( CUnimpCmd )))
#define	MAX_CIOEXECUTE_SIZE	max(sizeof(	CIOExecute),\
max(sizeof(CArticleCmd),max(\
max(sizeof(CBodyCmd),\
sizeof(CHeadCmd)),max(\
max(sizeof(CReceiveArticle),\
sizeof(CPostCmd)),\
max(sizeof(CIHaveCmd),\
sizeof(CXReplicCmd))))))

// inetsrv\iis\svcs\nntp\server\server\io.h
#define	MAX_CHANNEL_SIZE	max(	sizeof( CChannel ),				\
							max(	sizeof( CHandleChannel ),		\
							max(	sizeof(	CSocketChannel ),		\
							max(	sizeof(	CFileChannel ),			\
							max(	sizeof(	CIOFileChannel ),		\
							max(	sizeof(	CIODriver ),			\
							max(	sizeof( CIODriverSource ),		\
									sizeof(	CIODriverSink ) ) ) ) ) ) ) )

// inetsrv\iis\svcs\smtp\adminsso\ipaccess.cpp
#define GETIP_FOURTH(x)            ((x)     & 0xff)

// inetsrv\iis\svcs\smtp\adminsso\smtpprop.h
#define DEFAULT_AUTHENTICATION          (MD_AUTH_ANONYMOUS | MD_AUTH_BASIC | MD_AUTH_NT)

// inetsrv\iis\svcs\smtp\aqueue\cat\inc\catdefs.h
#define MAX_SEARCH_FILTER_SIZE  (CAT_MAX_INTERNAL_FULL_EMAIL + sizeof("(mail=)"))

// inetsrv\iis\svcs\smtp\aqueue\cat\utest\perfshar\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// inetsrv\iis\svcs\smtp\aqueue\retrsink\hashentr.h
#define INVALID_CALLBACK ((CALLBACKFN)(~0))

// inetsrv\iis\svcs\smtp\server\dirnot.cxx
#define IS_SPACE_OR_TAB(ch)                (((ch) == ' ') || ((ch) == '\t'))
#define IS_WHITESPACE_OR_CRLF(ch)        (((ch) == ' ') || ((ch) == '\t') || ((ch) == '\n') || ((ch) == '\r'))

// inetsrv\iis\svcs\smtp\server\dropdir.hxx
#define MAX_HEADER_SIZE             (sizeof(X_RECEIVER_HEADER))

// inetsrv\iis\svcs\smtp\server\remoteq.cxx
    #define MAX_HEADER_SIZE     (sizeof(X_RECEIVER_HEADER))

// inetsrv\iis\svcs\smtp\server\smtpcli.hxx
#define MAX_REWRITTEN_MSGID \
    (REWRITTEN_GEN_MSGID_BUFFER+1) + \
    sizeof("Message-ID:   <123456789@>\r\n") + \
    (MAX_INTERNET_NAME+1)

// inetsrv\iis\svcs\smtp\server\smtpdata.h
#define ISNULLADDRESS(Address) ((Address[0] == '<') && (Address[1] == '>'))

// inetsrv\iis\svcs\smtp\smtpctrs\perfutil.c
#define EvalThisChar(c,d) (\
	(c == d) ? DELIMITER : \
	(c == 0) ? DELIMITER : \
	(c < (WCHAR)'0') ? INVALID : \
	(c > (WCHAR)'9') ? INVALID : \
	DIGIT)

// inetsrv\iis\svcs\staxcore\admin\admcmn\adsimpl.h
#define DECLARE_GET_IADS_PROPERTY(cls,m_IADsImpl,prop)		\
	STDMETHODIMP cls :: get_##prop ( BSTR * pstr##prop )	\
	{														\
		return m_IADsImpl . get_##prop( pstr##prop );		\
	}

// inetsrv\iis\svcs\staxcore\evntwrap\src\evntwrap.cpp
#define MAX_STAX_EVENT_SOURCE_PATH_PREFIX \
    ((sizeof(STAX_EVENT_SOURCE_SYSTEM_PATH_PREFIX) > \
      sizeof(STAX_EVENT_SOURCE_APPLICATION_PATH_PREFIX)) ? \
      sizeof(STAX_EVENT_SOURCE_SYSTEM_PATH_PREFIX) : \
      sizeof(STAX_EVENT_SOURCE_APPLICATION_PATH_PREFIX))

// inetsrv\iis\svcs\staxcore\perfapi\src\perfapii.h
#define INSTANCE_DEF_MM_SIZE            (MAX_INSTANCES_PER_OBJECT * (sizeof(PERF_INSTANCE_DEFINITION) + (MAX_TITLE_CHARS + 1) * sizeof(WCHAR)))
#define GetInstance(poi,num)   ((PPERF_INSTANCE_DEFINITION) (pommfs[poi->index].gpbInstanceDefinitions + (num) * (sizeof(PERF_INSTANCE_DEFINITION) + (MAX_TITLE_CHARS + 1) * sizeof(WCHAR))));

// inetsrv\iis\svcs\staxcore\perfapi\src\perfreg.c
#define  MAX_REGISTRY_NAME_SPACE	(MAX_COUNTER_ENTRIES * (MAX_TITLE_CHARS + 6) * sizeof (WCHAR))
#define  MAX_REGISTRY_HELP_SPACE	(MAX_HELP_ENTRIES * (MAX_HELP_CHARS + 6) * sizeof (WCHAR))

// inetsrv\iis\svcs\staxcore\perfapi\src\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// inetsrv\iis\svcs\staxcore\staxmem\exchmem.c
#define ExchmemSafeAppend(szBuf, cbMaxBuf, szAppend, cbAppend) {					\
			int iWritten;															\
																					\
			if(NULL != lstrcpyn(szBuf, szAppend, cbMaxBuf)) {						\
				iWritten = ((int)cbMaxBuf < (int)cbAppend) ? cbMaxBuf : cbAppend;	\
				szBuf += iWritten;													\
				cbMaxBuf -= iWritten;												\
			}																		\
		}

// inetsrv\iis\svcs\w3\cisa\vipinc\transact.h
#define BOID_NULL (*((BOID*)(&IID_NULL)))

// inetsrv\iis\svcs\w3\filters\compress\inc\compfilt.h
#define IS_SUCCESSFUL_STATIC( pfc )                                \
    ( (pfc)->pFilterContext == COMPFILT_SUCCESSFUL_STATIC )
#define IS_URLMAP_DONE( pfc )                                \
    ( (pfc)->pFilterContext == COMPFILT_URLMAP_DONE )

// inetsrv\iis\svcs\w3\gateways\binsrv\dbgutil.h
# define DECLARE_DEBUG_PRINTS_OBJECT()          \
         DEBUG_PRINTS  *  g_pDebug = NULL;

// inetsrv\iis\svcs\w3\server\doget.cxx
#define MIN_ADDL_BUF_HDR_SIZE_CACHED    (sizeof("Date: ") - 1 + \
                                   sizeof("Mon, 00 Jan 0000 00:00:00 GMT\r\n") - 1 +\
                                   MAX_SIZE_HTTP_INFO)

// inetsrv\iis\svcs\w3\server\httpreq.cxx
#define EXTRA_ETAG_PRECOND_SIZE (sizeof("ETag: W/\r\n") - 1 + \
                            MAX_ETAG_BUFFER_LENGTH + \
                            sizeof("Date: \r\n") - 1+ \
                            sizeof("Mon, 00 Jan 1997: 00:00:00 GMT") - 1 +\
                            sizeof("Last-Modified: \r\n") - 1+ \
                            sizeof("Mon, 00 Jan 1997 00:00:00 GMT") - 1)

// inetsrv\iis\svcs\w3\server\w3meta.cxx
#define SET_WIN32_ERR(p,x)  {       (p)->IsValid = TRUE; \
                                    (p)->ErrorReason = METADATA_ERROR_WIN32;\
                                    (p)->Win32Error = (x); \
                            }
#define SET_VALUE_ERR(x)    {       (x)->IsValid = TRUE; \
                                    (x)->ErrorReason = METADATA_ERROR_VALUE;\
                            }
#define SIZEOF_CACHE_CONTROL            (sizeof("Cache-Control: max-age=4294967295\r\n") - 1)

// inetsrv\iis\ui\admin\appconfig\propsheet.h
#define SET_MODIFIED(x)\
   m_pData->m_Dirty = (x);\
   SetModified(m_pData->m_Dirty)

// inetsrv\iis\ui\admin\common2\error.h
#define REGISTER_FACILITY(dwCode, lpSource)\
    CError::RegisterFacility(dwCode, lpSource)

// inetsrv\iis\ui\admin\comprop\comprop.h
#define AllocMemByType(citems, type)\
    (type *)AllocMem(citems * sizeof(type))

// inetsrv\iis\ui\admin\comprop\inetprop.h
#define IS_VROOT(dwAttributes) ((dwAttributes & FILE_ATTRIBUTE_VIRTUAL_DIRECTORY) != 0)
#define IS_DIR(dwAttributes) ((dwAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
#define IS_FILE(dwAttributes) ((dwAttributes & (FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_VIRTUAL_DIRECTORY)) == 0)
#define BEGIN_META_WRITE()\
{                                               \
    HRESULT hr = S_OK;                          \
    do                                          \
    {                                           \
        m_dwaDirtyProps.RemoveAll();            \
#define HANDLE_META_RECORD(id, value)\
        case id:                                        \
            FetchMetaValue(pAllRecords, i, MP_V(value));\
            break;
#define HANDLE_INHERITED_META_RECORD(id, value, fIsInherited)\
        case id:                                                               \
            FetchInheritedMetaValue(pAllRecords, i, MP_V(value), fIsInherited);\
            break;
#define BEGIN_META_INST_READ(sheet)\
{                                                                        \
    sheet * pSheet = (sheet *)GetSheet();                                \
    do                                                                   \
    {                                                                    \
        if (FAILED(pSheet->QueryInstanceResult()))                       \
        {                                                                \
            break;                                                       \
        }
#define STORE_INST_DATA_ON_SHEET(value)\
        pSheet->GetInstanceProperties().value = value;
#define STORE_DIR_DATA_ON_SHEET(value)\
        pSheet->GetDirectoryProperties().value = value;

// inetsrv\iis\ui\admin\comprop\ipa.h
  #define GETIP_FOURTH(x)            ((x)     & 0xff)

// inetsrv\iis\ui\admin\comprop\ipctl.h
#define IPM_CLEARADDRESS (WM_USER+100)
#define IPM_SETADDRESS   (WM_USER+101)
#define IPM_GETADDRESS   (WM_USER+102)
#define IPM_SETRANGE     (WM_USER+103)
#define IPM_SETFOCUS     (WM_USER+104)
#define IPM_ISBLANK      (WM_USER+105)

// inetsrv\iis\ui\admin\comprop\msg.h
#define REGISTER_FACILITY(dwCode, lpSource)\
    CError::RegisterFacility(dwCode, lpSource)

// inetsrv\iis\ui\admin\comprop\odlbox.h
#define HLS_DEFAULT         (HLS_STRETCH | HLS_BUTTONS)

// inetsrv\iis\ui\admin\comprop\strfn.h
#define AllocTString(cch)\
    (LPTSTR)AllocMem((cch) * sizeof(TCHAR))

// inetsrv\iis\ui\admin\inc\svrinfo.h
#define ISMAllocMemByType(citems, type)\
    (type *)AllocMem(citems * sizeof(type))
#define ISMSERVERINFO_SIZE      sizeof(ISMSERVERINFO)
#define ISMSERVICEINFO1_SIZE     sizeof(ISMSERVICEINFO1)
#define ISMSERVICEINFO_SIZE     sizeof(ISMSERVICEINFO)
#define ISMINSTANCEINFO_SIZE    sizeof(ISMINSTANCEINFO)
#define ISMCHILDINFO_SIZE       sizeof(ISMCHILDINFO)

// inetsrv\iis\ui\admin\mmc\ndmgr.h
#define WINDOW_DATA_SIZE       (sizeof (DataWindowData *))
#define IS_SPECIAL_LVDATA(d) (((d) >= SPECIAL_LVDATA_MIN) && ((d) <= SPECIAL_LVDATA_MAX))

// inetsrv\iis\ui\admin\pws\formadv.cpp
#define WIDE_MAX_PATH                           ( MAX_PATH * sizeof(WCHAR) )

// inetsrv\iis\ui\admin\pwsext\priv.h
#define     WIDE_MAX_PATH               (MAX_PATH * sizeof(WCHAR) )

// inetsrv\iis\ui\itools\w3key\mdkey.cpp
#define MAX_LEN                 (METADATA_MAX_NAME_LEN * sizeof(WCHAR))

// inetsrv\iis\ui\itools\w3key\mdserv.cpp
#define MAX_LEN                 (METADATA_MAX_NAME_LEN * sizeof(WCHAR))

// inetsrv\iis\utils\certutil\fortezza\fortutil\fortutil.cxx
#define USAGE "Usage : %s -o:delete|create|check -i:<instance number #1> -n:PIN -s:<serial #> -p:<personality> [-?]"

// inetsrv\iis\utils\setkey\setkey.c
#define IS_ARG(c)   ((c) == L'-' || (c) == L'/')

// inetsrv\msmq\sdk\samples\mqtestoa\mqtestoa.cpp
#define RELEASE(punk) if (punk) { (punk)->Release(); (punk) = NULL; }

// inetsrv\msmq\src\admin\mqsnap\globals.cpp
#define _COMPAREVARFIELD(field) (propvar1->field == propvar2->field ?  0 : \
                                    propvar1->field > propvar2->field ? 1 : -1)

// inetsrv\msmq\src\admin\mqsnap\globals.h
#define IF_NOTFOUND_REPORT_ERROR(rc) \
        if ((rc == MQDS_OBJECT_NOT_FOUND \
            || rc == MQ_ERROR_QUEUE_NOT_FOUND \
            || rc == MQ_ERROR_MACHINE_NOT_FOUND) && \
            (  ADProviderType() == eMqdscli)) \
        { \
            AFX_MANAGE_STATE(AfxGetStaticModuleState()); \
            AfxMessageBox(IDS_REPLICATION_PROBLEMS); \
        }

// inetsrv\msmq\src\apps\mqdiag\mqping\sim.h
#define Msg_ADMIN_QUEUE(pMsgDsc)	\
	(WCHAR *)((pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_ADMIN_QUEUE] ].pwszVal)
#define Msg_ADMIN_QUEUE_LEN(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_ADMIN_QUEUE_LEN] ].ulVal
#define Msg_AdminQ(pMsgDsc)	\
	(pMsgDsc)->hAdminQ
#define Msg_AdminQ_FormatName(pMsgDsc)	\
	(pMsgDsc->pwcsAdminQ)

// inetsrv\msmq\src\apps\mqdiag\ping.cpp
#define MAX_BUFFER_SIZE       (sizeof(ICMP_ECHO_REPLY) + 0xfff7 + MAX_OPT_SIZE)

// inetsrv\msmq\src\ds\h\mqiscol.h
#define Q_LABEL_CLEN        ((MQ_MAX_Q_LABEL_LEN+1) * sizeof(TCHAR))

// inetsrv\msmq\src\inc\mfc\afx.h
#define ASSERT_VALID(pOb)  ((pOb)->AssertValid())

// inetsrv\msmq\src\mqperf\perfutil.cpp
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// inetsrv\msmq\src\rt\queue.cpp
#define MQ_VALID_ACCESS (MQ_RECEIVE_ACCESS | MQ_PEEK_ACCESS | MQ_SEND_ACCESS | MQ_ADMIN_ACCESS)

// inetsrv\msmq\src\rtdep\queue.cpp
#define MQ_VALID_ACCESS (MQ_RECEIVE_ACCESS | MQ_PEEK_ACCESS | MQ_SEND_ACCESS | MQ_ADMIN_ACCESS)

// inetsrv\query\apps\cxxflt\minici.hxx
#define CATCH( class, e ) catch( class & e )

// inetsrv\query\apps\enumprop\minici.hxx
#define CATCH( class, e ) catch( class & e )

// inetsrv\query\apps\slickdll\h\vsapi.h
#define VSHELP_ARG       "h:37" /* (TERMINATE_MATCH|ONE_ARG_MATCH|NO_SORT_MATCH) */
#define VSTAG_ARG        "tag:37" /* (REMOVE_DUPS_MATCH|NO_SORT_MATCH|TERMINATE_MATCH) */

// inetsrv\query\apps\srch\minici.hxx
#define CATCH( class, e ) catch( class & e )

// inetsrv\query\common\printf.h
#   define MAXSTR       ((MAX_PATH + 1) * sizeof(WCHAR))

// inetsrv\query\filters\office\src\findfast\dmifmtps.c
#define IS_CONDITIONAL(c) ((c == '<') || (c == '>') || (c == '='))

// inetsrv\query\filters\office\src\findfast\dmixlp.h
#define IS_BOF(x) \
   (((x) == BOF_V2) || ((x) == BOF_V3) || ((x) == BOF_V4) || ((x) == BOF_V5))
#define NOTPASSBOOLERR(dispatch) \
   ((dispatch->pfnBooleanCell == NULL) && (dispatch->pfnErrorCell == NULL))
#define PASSBOOLERR(dispatch) \
   ((dispatch->pfnBooleanCell != NULL) || (dispatch->pfnErrorCell != NULL))

// inetsrv\query\filters\office\src\findfast\dmixltyp.h
#define RANGES_SAME(x,y) \
       ((x.firstRow == y.firstRow) && (x.firstCol == y.firstCol) && \
        (x.lastRow == y.lastRow)   && (x.lastCol == y.lastCol))
#define IS_WHOLE_ROW(x) \
       ((x.firstCol == EXCEL_FIRST_COL) && (x.lastCol == EXCEL_LAST_COL) && \
        (x.firstRow == x.lastRow))
#define IS_WHOLE_COL(x) \
       ((x.firstRow == EXCEL_FIRST_ROW) && (x.lastRow == EXCEL_LAST_ROW) && \
        (x.firstCol == x.lastCol))
#define CELL_IN_RANGE(r,c) \
       ((c.col >= r.firstCol) && (c.col <= r.lastCol) && \
        (c.row >= r.firstRow) && (c.row <= r.lastRow))
#define EMPTY_RANGE(r) \
       ((r.firstRow == 0) && (r.lastRow == 0) && (r.firstCol == 0) && (r.lastCol == 0))

// inetsrv\query\h\ci.h
#define IS_CIQUERYPROPID(propid) ( (propid) >= CSTORAGEPROPERTY + 1 && \
                                   (propid) <  CSTORAGEPROPERTY + CQUERYPROPERTY )

// inetsrv\query\kbyacc\defs.h
#define IS_IDENT(c)     (isalnum(c) || (c) == '_' || (c) == '.' || (c) == '$')
#define IS_OCTAL(c)     ((c) >= '0' && (c) <= '7')

// inetsrv\query\qperf\prfutil.hxx
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// inetsrv\query\qutil\triplish\lex.cxx
#define yy_set_interactive(is_interactive) \
        { \
        if ( ! yy_current_buffer ) \
                yy_current_buffer = yy_create_buffer( YY_BUF_SIZE ); \
        yy_current_buffer->yy_is_interactive = is_interactive; \
        }

// inetsrv\query\sqltext\mssqllex.cpp
#define yy_set_interactive(is_interactive) \
        { \
        if ( ! yy_current_buffer ) \
                yy_current_buffer = yy_create_buffer( YY_BUF_SIZE ); \
        yy_current_buffer->yy_is_interactive = is_interactive; \
        }

// inetsrv\query\tdbv1\tdbv1.cxx
    #define NUMPROP(name)                                                   \
            if (CheckNumericProperty( DBPROPSET_ROWSET, DBPROP_ ## name, cProps, pProps, n) ) \
                    printf ("\t" #name ":\t%d\n", n);                       \
            else                                                            \
                    printf ("\t" #name ":\t--\n");
    #define SAPROP(name)                                               \
            printf ( "\t" #name ": ");                                       \
            CheckSafeArrayProperty( guidFsCiFrmwrkExt, DBPROP_ ## name, cProps, pProps); \
            printf ( "\n" );
    #define SAPROP(name)                                               \
            printf ( "\t" #name ": ");                                       \
            CheckSafeArrayProperty( guidCiFrmwrkExt, DBPROP_ ## name, cProps, pProps); \
            printf ( "\n" );
    #define SAPROP(name)                                               \
            printf ( "\t" #name ": ");                                       \
            CheckSafeArrayProperty( guidMsidxsExt, MSIDXSPROP_ ## name, cProps, pProps); \
            printf ( "\n" );

// net\1394\arp\sys\eth.c
#define ETH_IS_MULTICAST(Address) \
        (BOOLEAN)(((PUCHAR)(Address))[0] & ((UCHAR)0x01))
#define ETH_IS_BROADCAST(Address)               \
    ((((PUCHAR)(Address))[0] == ((UCHAR)0xff)) && (((PUCHAR)(Address))[1] == ((UCHAR)0xff)))

// net\1394\arp\sys\ip.c
#define ETH_IS_MULTICAST(Address) \
    (BOOLEAN)(((PUCHAR)(Address))[0] & ((UCHAR)0x01))
#define ETH_IS_BROADCAST(Address)               \
    ((((PUCHAR)(Address))[0] == ((UCHAR)0xff)) && (((PUCHAR)(Address))[1] == ((UCHAR)0xff)))

// net\1394\arp\sys\md5.c
#define ETH_IS_MULTICAST(Address) \
        (BOOLEAN)(((PUCHAR)(Address))[0] & ((UCHAR)0x01))

// net\1394\arp\sys\rm.c
    #define RM_OBJECT_IS_ALLOCATED(_pobj) \
                    ((_pobj)->Sig == RM_TEST_SIG)

// net\1394\inc\rfc2734.h
    #define IP1394_IS_VALID_MAXREC(_max_rec) ((_max_rec)>0 && (_max_rec)<0xE)

// net\1394\nic\sys\md5.c
#define ETH_IS_MULTICAST(Address) \
        (BOOLEAN)(((PUCHAR)(Address))[0] & ((UCHAR)0x01))

// net\1394\nic\sys\priv.h
#define BCR_IS_VALID(_B)                    ((_B)->NC_One == 1 && (_B)->NC_Valid ==1)
#define nicInitQueueStats()                                     \
        NdisZeroMemory (&SendStats, sizeof(SendStats) );        \
        NdisZeroMemory (&RcvStats, sizeof(RcvStats) );          \
        nicMaxRcv = 0;                                          \
        nicMaxSend = 0;
#define CLEAR_DESCRIPTOR_OF_NDIS_TAG(_pI)                                           \
    (_pI)->DeviceReserved[IsochTag] = 0;

// net\atm\arp\atmarpc\macros.h
#define AA_IS_BCAST_IP_ADDRESS(Destn, pIf)	\
		(IP_ADDR_EQUAL((pIf)->BroadcastAddress, Destn))
#define AA_FILTER_SPEC_MATCH(pIf, pSrc, pDst)	\
			( ((pIf)->pFilterMatchFunc == NULL_PAA_FILTER_SPEC_MATCH_FUNC) ?	\
					TRUE:													\
					(*((pIf)->pFilterMatchFunc))((PVOID)pIf, pSrc, pDst))
#define AA_IS_BEST_EFFORT_FLOW(pFlowSpec)	\
			(((pFlowSpec)->SendServiceType == SERVICETYPE_BESTEFFORT) &&			\
			 ((pFlowSpec)->SendPeakBandwidth > 0))

// net\atm\arp\atmarpc\marspkt.h
#define AAMC_PKT_IS_TYPE1_DATA(pH)	\
			(((pH)->LLC[0] == MC_LLC_SNAP_LLC0) && \
			 ((pH)->LLC[1] == MC_LLC_SNAP_LLC1) && \
			 ((pH)->LLC[2] == MC_LLC_SNAP_LLC2) && \
			 ((pH)->OUI[0] == MC_LLC_SNAP_OUI0) && \
			 ((pH)->OUI[1] == MC_LLC_SNAP_OUI1) && \
			 ((pH)->OUI[2] == MC_LLC_SNAP_OUI2) && \
			 ((pH)->PID == NET_SHORT(AA_PKT_ETHERTYPE_MC_TYPE1)) && \
			 ((pH)->pro == NET_SHORT(AA_PKT_ETHERTYPE_IP)))
#define AAMC_PKT_IS_TYPE2_DATA(pH)	\
			(((pH)->LLC[0] == MC_LLC_SNAP_LLC0) && \
			 ((pH)->LLC[1] == MC_LLC_SNAP_LLC1) && \
			 ((pH)->LLC[2] == MC_LLC_SNAP_LLC2) && \
			 ((pH)->OUI[0] == MC_LLC_SNAP_OUI0) && \
			 ((pH)->OUI[1] == MC_LLC_SNAP_OUI1) && \
			 ((pH)->OUI[2] == MC_LLC_SNAP_OUI2) && \
			 ((pH)->PID == NET_SHORT(AA_PKT_ETHERTYPE_MC_TYPE2)) && \
			 ((pH)->pro == NET_SHORT(AA_PKT_ETHERTYPE_IP)))
#define AAMC_PKT_IS_CONTROL(pH)	\
			(((pH)->LLC[0] == MC_LLC_SNAP_LLC0) && \
			 ((pH)->LLC[1] == MC_LLC_SNAP_LLC1) && \
			 ((pH)->LLC[2] == MC_LLC_SNAP_LLC2) && \
			 ((pH)->OUI[0] == MC_LLC_SNAP_OUI0) && \
			 ((pH)->OUI[1] == MC_LLC_SNAP_OUI1) && \
			 ((pH)->OUI[2] == MC_LLC_SNAP_OUI2) && \
			 ((pH)->PID == NET_SHORT(AA_PKT_ETHERTYPE_MARS_CONTROL)))
#define AAMC_IS_NULL_TLV(_pTlv)					\
			(((_pTlv)->Type == 0x0000) && ((_pTlv)->Length == 0x0000))

// net\atm\arp\atmarps\intf.h
#define	COMP_HW_ADDR(_a1_, _a2_)	(((_a1_)->Address.AddressType == (_a2_)->Address.AddressType) &&		\
									 ((_a1_)->Address.NumberOfDigits == (_a2_)->Address.NumberOfDigits) &&	\
									 COMP_MEM((_a1_)->Address.Address,										\
											  (_a2_)->Address.Address,										\
											  (_a1_)->Address.NumberOfDigits) && 							\
									 ((((_a1_)->SubAddress == NULL) && ((_a2_)->SubAddress == NULL)) ||		\
									  ((((_a1_)->SubAddress != NULL) && ((_a2_)->SubAddress != NULL)) &&	\
									   ((_a1_)->SubAddress->AddressType == (_a2_)->SubAddress->AddressType) &&\
									   ((_a1_)->SubAddress->NumberOfDigits == (_a2_)->SubAddress->NumberOfDigits) &&\
									   COMP_MEM((_a1_)->SubAddress->Address,								\
											    (_a2_)->SubAddress->Address,								\
											    (_a1_)->SubAddress->NumberOfDigits))))						\
#define	COPY_HW_ADDR(_d_, _s_)																				\
	{																										\
		(_d_)->Address.AddressType = (_s_)->Address.AddressType;											\
		(_d_)->Address.NumberOfDigits = (_s_)->Address.NumberOfDigits;										\
		COPY_MEM((_d_)->Address.Address, (_s_)->Address.Address, (_s_)->Address.NumberOfDigits);			\
		if ((_s_)->SubAddress != NULL)																		\
		{																									\
			(_d_)->SubAddress->AddressType = (_s_)->SubAddress->AddressType;								\
			(_d_)->SubAddress->NumberOfDigits = (_s_)->SubAddress->NumberOfDigits;							\
			COPY_MEM((_d_)->SubAddress->Address, (_s_)->SubAddress->Address, (_s_)->SubAddress->NumberOfDigits);\
		}																									\
	}

// net\atm\arp\atmarps\mars.h
#define	PKT_SPACE	MAX(sizeof(ARPS_HEADER) + sizeof(ARPS_VAR_HDR), \
						sizeof(MARS_REQUEST) + sizeof(ARPS_VAR_HDR))

// net\atm\epvc\sys\ccdefs.h
#define MAX_IPv4_FRAME              MAX_ETHERNET_FRAME - sizeof(EPVC_ETH_HEADER)
#define MIN_ETHERNET_SIZE           sizeof (IPHeader) + sizeof (EPVC_ETH_HEADER)

// net\atm\epvc\sys\macros.h
#define MP_SIZE(field) sizeof(((PEPVC_I_MINIPORT)0)->field)

// net\atm\epvc\sys\rm.c
    #define RM_OBJECT_IS_ALLOCATED(_pobj) \
                    ((_pobj)->Sig == RM_TEST_SIG)

// net\atm\lane\exe\atmlane.c
#define ADAPTER_LIST_BUFFER_SIZE	(sizeof(ATMLANE_ADAPTER_LIST) + \
									(MAX_ATMLANE_ADAPTERS * \
			 (sizeof(UNICODE_STRING) + (MAX_ATMLANE_NAME_LEN * sizeof(WCHAR)))))
#define ELAN_LIST_BUFFER_SIZE		(sizeof(ATMLANE_ELAN_LIST) + \
									(MAX_ATMLANE_ELANS * \
			(sizeof(UNICODE_STRING) + (MAX_ATMLANE_NAME_LEN * sizeof(WCHAR)))))
#define ELAN_INFO_BUFFER_SIZE		(sizeof(ATMLANE_ELANINFO) + \
			((sizeof(UNICODE_STRING) + (MAX_ATMLANE_NAME_LEN * sizeof(WCHAR))) * 2))
#define ARP_TABLE_BUFFER_SIZE		(sizeof(ATMLANE_ARPTABLE) + \
			((sizeof(ATMLANE_ARPENTRY) * MAX_ATMLANE_ARP_ENTRIES)))
#define CONN_TABLE_BUFFER_SIZE		(sizeof(ATMLANE_CONNECTTABLE) + \
			((sizeof(ATMLANE_CONNECTENTRY) * MAX_ATMLANE_CONNECTIONS)))

// net\atm\rawwan\sys\macros.h
#define RWAN_UNLINK_CONNECTION_AND_VC(_pConn, _pVc)					\
			{														\
				(_pConn)->NdisConnection.pNdisVc = NULL_PRWAN_NDIS_VC;\
				(_pVc)->pConnObject = NULL_PRWAN_TDI_CONNECTION;	\
			}

// net\dhcp\dhcpprov\dll\srvfn.cpp
#define ADJUST_SERVER_PARAMS(pParams, pServerParams, fRefresh)   \
    if (pParams == NULL)                                         \
    {                                                            \
        pServerParams = &backupParameters;                       \
        fRefresh = TRUE;                                         \
    }                                                            \
    else                                                         \
    {                                                            \
        pServerParams = (CDHCP_Server_Parameters *)pParams;      \
        fRefresh = FALSE;                                        \
    }

// net\dhcp\server\mm\address.c
#define     IS_SWITCHED(X)         (((X) & 0x00000002)?TRUE:FALSE)
#define     IS_DISABLED(X)         (((X) & 0x00000001)?TRUE:FALSE)

// net\dhcp\server\mm\address.h
#define     IS_SWITCHED(X)         (((X) & 0x00000002)?TRUE:FALSE)
#define     IS_DISABLED(X)         (((X) & 0x00000001)?TRUE:FALSE)

// net\dhcp\server\mmreg\regutil.c
#define     DEF_RANGE_MAX_ALLOC                   (~(ULONG)0)

// net\dhcp\server\mmreg\regutil.h
#define     DEF_RANGE_MAX_ALLOC                   (~(ULONG)0)

// net\dhcp\server\server\dhcpacc.h
#define DHCP_ALL_ACCESS  (FILE_ALL_ACCESS | STANDARD_RIGHTS_REQUIRED |\
                            DHCP_VIEW_ACCESS       |\
                            DHCP_ADMIN_ACCESS )

// net\dhcp\server\server\dnsdb.c
#define MINIMUM_UNIT_SIZE          (sizeof(DHCP_DNS_CONTEXT) + 60*sizeof(WCHAR))

// net\diagnostics\netdiag\tfschar.h
#define MinTCharNeededForCch(ch)	((ch) * (2/sizeof(TCHAR)))
#define MinCbNeededForCch(ch)		(sizeof(TCHAR)*MinTCharNeededForCch(ch))
#define MaxCchFromCb(cb)		((cb) / sizeof(TCHAR))
	#define MinCchFromCb(cb)	((cb) / sizeof(WCHAR))
	#define MinCchFromCb(cb)	((cb) / (2*sizeof(char)))

// net\diagnostics\netdiag\xportst.h
#define MAX_ICMP_BUF_SIZE ( sizeof(ICMP_ECHO_REPLY) + 0xfff7 + MAX_OPT_SIZE )

// net\dlc\api\acslan.c
#define IS_TRANSMIT(command)    (((command) == LLC_TRANSMIT_DIR_FRAME) \
                                || ((command) == LLC_TRANSMIT_I_FRAME) \
                                || ((command) == LLC_TRANSMIT_UI_FRAME) \
                                || ((command) == LLC_TRANSMIT_XID_CMD) \
                                || ((command) == LLC_TRANSMIT_XID_RESP_FINAL) \
                                || ((command) == LLC_TRANSMIT_XID_RESP_NOT_FINAL) \
                                || ((command) == LLC_TRANSMIT_TEST_CMD))

// net\dlc\driver\llcapi.h
#define IS_AUTO_BINDING(p) \
    (((PBINDING_CONTEXT)(p))->EthernetType == LLC_ETHERNET_TYPE_AUTO)

// net\homenet\alg\alg_icq\util.h
#define ALG_IFC_BOUNDARY(_Type) \
    ((_Type) & eALG_BOUNDARY)

// net\ias\mmc\nap\tregkey.h
#define MaxCchFromCb(cb)		((cb) / sizeof(TCHAR))
#define MinTCharNeededForCch(ch)	((ch) * (2/sizeof(TCHAR)))
#define MinCbNeededForCch(ch)		(sizeof(TCHAR)*MinTCharNeededForCch(ch))

// net\inc\ip.h
#define RCE_ALL_VALID       (RCE_VALID | RCE_CONNECTED | RCE_REFERENCED)

// net\inc\iprtinfo.h
#define AreAllFieldsUnchanged(pFilter)      \
    ((pFilter)->fLateBound == 0x00000000)

// net\inc\isnipx.h
#define MAC_HEADER_SIZE  ((IPX_MAXIMUM_MAC + 3) & ~3)
#define REQUEST_MINOR_FUNCTION(_Request) \
    ((IoGetCurrentIrpStackLocation(_Request))->MinorFunction)
#define REQUEST_NDIS_BUFFER(_Request) \
    ((PNDIS_BUFFER)((_Request)->MdlAddress))

// net\inc\wzcsapi.h
#define WZCDLG_IS_WZC(x)         (((x) & 0x00010000) == 0x00010000)
#define IS_EAPOL_ENABLED(x) \
    ((x & EAPOL_ENABLED)?1:0)
#define IS_MACHINE_AUTH_ENABLED(x) \
    ((x & EAPOL_MACHINE_AUTH_ENABLED)?1:0)
#define IS_GUEST_AUTH_ENABLED(x) \
    ((x & EAPOL_GUEST_AUTH_ENABLED)?1:0)

// net\irda\irsir\actisys.c
#define ACT200L_IRDA_SPEEDS         ( \
                                    NDIS_IRDA_SPEED_2400        |       \
                                    NDIS_IRDA_SPEED_9600        |       \
                                    NDIS_IRDA_SPEED_19200       |       \
                                    NDIS_IRDA_SPEED_38400       |       \
                                    NDIS_IRDA_SPEED_57600       |       \
                                    NDIS_IRDA_SPEED_115200              \
                                )
#define ACT220L_IRDA_SPEEDS (NDIS_IRDA_SPEED_9600    |       \
                             NDIS_IRDA_SPEED_19200   |       \
                             NDIS_IRDA_SPEED_57600   |       \
                             NDIS_IRDA_SPEED_115200)
#define ACT220LPLUS_IRDA_SPEEDS (ACT220L_IRDA_SPEEDS | NDIS_IRDA_SPEED_38400)

// net\irda\irsir\esi.c
#define ESI_9680_IRDA_SPEEDS    (   NDIS_IRDA_SPEED_9600     |    \
                                    NDIS_IRDA_SPEED_19200    |    \
                                    NDIS_IRDA_SPEED_115200        \
                                )

// net\irda\irsir\girbil.c
#define GIRBIL_IRDA_SPEEDS	( \
                                    NDIS_IRDA_SPEED_2400	|	\
                                    NDIS_IRDA_SPEED_9600	|	\
                                    NDIS_IRDA_SPEED_19200	|	\
                                    NDIS_IRDA_SPEED_38400	|	\
                                    NDIS_IRDA_SPEED_57600	|	\
                                    NDIS_IRDA_SPEED_115200		\
                                )

// net\irda\irsir\parallax.c
#define PARALLAX_IRDA_SPEEDS	( \
                                    NDIS_IRDA_SPEED_2400	|	\
                                    NDIS_IRDA_SPEED_9600	|	\
                                    NDIS_IRDA_SPEED_19200	|	\
                                    NDIS_IRDA_SPEED_38400	|	\
                                    NDIS_IRDA_SPEED_57600	|	\
                                    NDIS_IRDA_SPEED_115200		\
                                )

// net\irda\irsir\settings.h
#define ALL_SLOW_IRDA_SPEEDS (  NDIS_IRDA_SPEED_2400     |    \
                                NDIS_IRDA_SPEED_9600     |    \
                                NDIS_IRDA_SPEED_19200    |    \
                                NDIS_IRDA_SPEED_38400    |    \
                                NDIS_IRDA_SPEED_57600    |    \
                                NDIS_IRDA_SPEED_115200        \
                             )
    #define MAX_RCV_DATA_SIZE (MAX_NDIS_DATA_SIZE+SLOW_IR_FCS_SIZE+sizeof(USHORT))

// net\irda\irsir\tekram.c
#define TEKRAM_IRDA_SPEEDS	( \
                                    NDIS_IRDA_SPEED_2400	|	\
                                    NDIS_IRDA_SPEED_9600	|	\
                                    NDIS_IRDA_SPEED_19200	|	\
                                    NDIS_IRDA_SPEED_38400	|	\
                                    NDIS_IRDA_SPEED_57600	|	\
                                    NDIS_IRDA_SPEED_115200		\
                                )

// net\irda\irsir\temic.c
#define TEMIC_IRDA_SPEEDS	( \
                                    NDIS_IRDA_SPEED_2400	|	\
                                    NDIS_IRDA_SPEED_9600	|	\
                                    NDIS_IRDA_SPEED_19200	|	\
                                    NDIS_IRDA_SPEED_38400	|	\
                                    NDIS_IRDA_SPEED_57600	|	\
                                    NDIS_IRDA_SPEED_115200		\
                                )

// net\irda\samples\nscirda\init.c
    #define NSC_DEMO_IRDA_SPEEDS ( NDIS_IRDA_SPEED_2400    |	   \
				   NDIS_IRDA_SPEED_2400    |	   \
				   NDIS_IRDA_SPEED_9600    |	   \
				   NDIS_IRDA_SPEED_19200   |	   \
				   NDIS_IRDA_SPEED_38400   |	   \
				   NDIS_IRDA_SPEED_57600   |	   \
				   NDIS_IRDA_SPEED_115200  |	   \
				   NDIS_IRDA_SPEED_1152K   |	   \
				   NDIS_IRDA_SPEED_4M )

// net\irda\samples\nscirda\nsc.c
    #define RESOURCE_LIST_BUF_SIZE (sizeof(NDIS_RESOURCE_LIST) + (10*sizeof(CM_PARTIAL_RESOURCE_DESCRIPTOR)))

// net\irda\samples\nscirda\settings.h
#define ALL_SLOW_IRDA_SPEEDS (						\
	NDIS_IRDA_SPEED_2400 | NDIS_IRDA_SPEED_9600 |			\
	NDIS_IRDA_SPEED_19200 | NDIS_IRDA_SPEED_38400 |			\
	NDIS_IRDA_SPEED_57600 | NDIS_IRDA_SPEED_115200)
#define ALL_IRDA_SPEEDS (						\
	ALL_SLOW_IRDA_SPEEDS | NDIS_IRDA_SPEED_1152K | NDIS_IRDA_SPEED_4M)
#define RCV_BUFFER_SIZE (MAX_RCV_DATA_SIZE +4+sizeof(LIST_ENTRY))

// net\irda\sys\irdap.h
#define IS_VALID_ADDR(p)    (((p) != NULL) && ((p)->Sig == ADDR_OBJ_SIG))
#define IS_VALID_CONN(p)    (((p) != NULL) && ((p)->Sig == CONN_OBJ_SIG))

// net\irda\winsock\wshirda.c
#define MAX_SOCKADDR_LEN    sizeof(SOCKADDR_IRDA)

// net\jet500\jet\dae\inc\dbapi.h
#define VDbidCheckUpdatable( vdbid ) 	\
	( FVDbidReadOnly( vdbid ) ? JET_errPermissionDenied : JET_errSuccess )																			\

// net\jet500\jet\dae\inc\fucb.h
#define StoreChecksum( pfucb )								\
	( (pfucb)->ulChecksum = 								\
		UlChecksum( (pfucb)->lineData.pb, (pfucb)->lineData.cb ) )
#define FChecksum( pfucb )											\
	( (pfucb)->ulChecksum == UlChecksum( (pfucb)->lineData.pb,		\
	(pfucb)->lineData.cb ) )
#define FUCBCheckUpdatable( pfucb )		\
	( FFUCBUpdatable( pfucb ) ? JET_errSuccess : JET_errPermissionDenied )

// net\jet500\jet\dae\inc\idb.h
#define IDBSetNoNullSeg( pidb )				( (pidb)->fidb |= fidbNoNullSeg )
#define IDBResetNoNullSeg( pidb )			( (pidb)->fidb &= ~fidbNoNullSeg )
#define FIDBNoNullSeg( pidb )					( (pidb)->fidb & fidbNoNullSeg )

// net\jet500\jet\dae\inc\node.h
#define	cbHalfItemNodeMost 		( 1 + 1 + JET_cbKeyMost + 0 + 0 + sizeof(SRID) + ((((citemMax + 1) / 2) + 1 ) * sizeof(SRID)) )
#define	FNDNullSon(b)	 		( !( (b) & fNDSon ) )

// net\jet500\jet\dae\src\buf.c
#define FBFInBFWriteHeap(pbf) \
	((pbf)->ipbfHeap < ipbfHeapMax && (pbf)->ipbfHeap > ipbfBFWriteHeapMac)

// net\jet500\jet\dae\src\dir.c
#define DIRICheckFirstSetItemListAndWarn( pfucb, wrn )			\
		{                                         				\
		if FNDFirstItem( *pfucb->ssib.line.pb )      			\
			{                                         			\
			wrn = JET_wrnKeyChanged;							\
			DIRISetItemListFromFirst( pfucb );        			\
			}                                        	 		\
		}
#define DIRICheckFirstSetItemList( pfucb )         				\
		{                                            			\
		if FNDFirstItem( *pfucb->ssib.line.pb )      			\
			{                                         			\
			DIRISetItemListFromFirst( pfucb );        			\
			}                                         			\
		}

// net\jet500\jet\dae\src\mcm.c
#define	FPMValidItag( itag )	( itag >= itagFOP && itag < ctagMax )

// net\jet500\jet\dae\src\sysdb.c
#define cbsidAdmins sizeof(sidAdmins)
#define cbsidAdminUser sizeof(sidAdminUser)

// net\jet500\xjet\inc\dbapi.h
#define	FUserDbid( dbid )											\
	(dbid > dbidTemp && dbid < dbidMax)
#define VDbidCheckUpdatable( vdbid ) 	\
	( FVDbidReadOnly( vdbid ) ? ErrERRCheck( JET_errPermissionDenied ) : JET_errSuccess )

// net\jet500\xjet\inc\fucb.h
#define CSRInvalidate( pcsr )			\
	{									\
	(pcsr)->itag = itagNil;				\
	(pcsr)->itagFather = itagNil;		\
	(pcsr)->pgno = pgnoNull;			\
	}
#define StoreChecksum( pfucb )								\
	( (pfucb)->ulChecksum = 								\
		UlChecksum( (pfucb)->lineData.pb, (pfucb)->lineData.cb ) )
#define FFUCBCheckChecksum( pfucbT )  								\
	( (pfucbT)->ulChecksum == UlChecksum( (pfucbT)->lineData.pb, 	\
		(pfucbT)->lineData.cb ) )
#define FUCBCheckUpdatable( pfucb )					\
	( FFUCBUpdatable( pfucb ) ? JET_errSuccess : 	\
		ErrERRCheck( JET_errPermissionDenied ) )

// net\jet500\xjet\inc\idb.h
#define IDBSetNoNullSeg( pidb )				( (pidb)->fidb |= fidbNoNullSeg )
#define IDBResetNoNullSeg( pidb )			( (pidb)->fidb &= ~fidbNoNullSeg )
#define FIDBNoNullSeg( pidb )				( (pidb)->fidb & fidbNoNullSeg )

// net\jet500\xjet\inc\node.h
#define	cbHalfItemNodeMost 		( 1 + 1 + JET_cbKeyMost + 0 + 0 + sizeof(SRID) + ((((citemMax + 1) / 2) + 1 ) * sizeof(SRID)) )
#define	FNDNullSon(b)	 		( !( (b) & fNDSon ) )

// net\jet500\xjet\inc\scb.h
#define cspairSortMax					( cbSortMemFast / sizeof( SPAIR ) - 1 )
#define cbSortMemFastUsed				( ( cspairSortMax + 1 ) * sizeof( SPAIR ) )

// net\jet500\xjet\inc\utilw32.h
#define UtilStringCompare( pb1, cb1, pb2, cb2, sort, plResult )		\
	{																\
	*plResult = strncmp( pb1, pb2, min( cb1, cb2 ) );				\
	if ( !*plResult )												\
		*plResult = cb1 > cb2;										\
	}

// net\jet500\xjet\src\btsplit.c
#define	FPMValidItag( itag )	( itag >= itagFOP && itag < ctagMax )

// net\jet500\xjet\src\dir.c
#define ErrDIRINextItem( pfucb )								\
	( pfucb->lineData.cb == sizeof(SRID) ?                      \
		ErrERRCheck( errNDNoItem ) : ErrNDNextItem( pfucb ) )
#define ErrDIRIPrevItem( pfucb )                                \
	( PcsrCurrent(pfucb)->isrid == 0 ?                          \
		ErrERRCheck( errNDNoItem ) : ErrNDPrevItem( pfucb ) )
#define DIRICheckFirstSetItemListAndWarn( pfucb, wrn )			\
		{                                         				\
		if FNDFirstItem( *pfucb->ssib.line.pb )      			\
			{                                         			\
			wrn = ErrERRCheck( JET_wrnKeyChanged );		\
			DIRISetItemListFromFirst( pfucb );        			\
			}                                        	 		\
		}
#define DIRICheckFirstSetItemList( pfucb )         				\
		{                                            			\
		if FNDFirstItem( *pfucb->ssib.line.pb )      			\
			{                                         			\
			DIRISetItemListFromFirst( pfucb );        			\
			}                                         			\
		}

// net\mcast\pgm\dll\wshrm.c
#define IS_DGRAM_SOCK(type)  (((type) == SOCK_DGRAM) || ((type) == SOCK_RAW))

// net\mmc\acssnap\acsdata.h
#define	IS_LARGE_UNLIMIT(large)		((large).LowPart == 0xffffffff && (large).HighPart == 0xffffffff)

// net\mmc\ipxsnap\ipxadmin.h
#define GET_IPXADMIN_NODEDATA(pNode) \
		(IPXConnection *) pNode->GetData(TFS_DATA_USER)

// net\mmc\mprsnap\ifadmin.h
#define GET_IFADMINNODEDATA(pNode) \
						((IfAdminNodeData *) pNode->GetData(TFS_DATA_USER))

// net\mmc\tfscore\tfschar.h
#define MinTCharNeededForCch(ch)	((ch) * (2/sizeof(TCHAR)))
#define MinCbNeededForCch(ch)		(sizeof(TCHAR)*MinTCharNeededForCch(ch))
#define MaxCchFromCb(cb)		((cb) / sizeof(TCHAR))
	#define MinCchFromCb(cb)	((cb) / sizeof(WCHAR))
	#define MinCchFromCb(cb)	((cb) / (2*sizeof(char)))

// net\mmc\wins\memmngr.h
#define IS_DBREC_LONGNAME(wdbRecord) ((wdbRecord)->szRecordName[17] & WINSDB_INTERNAL_LONG_NAME)

// net\ndis\samples\coisdn\tpimem.h
#define ALLOCATE_OBJECT(pObject, MiniportAdapterHandle)\
            ALLOCATE_MEMORY(pObject, sizeof(*(pObject)), MiniportAdapterHandle)

// net\ndis\samples\isdnwan\tpimem.h
#define ALLOCATE_OBJECT(pObject, MiniportAdapterHandle)\
            ALLOCATE_MEMORY(pObject, sizeof(*(pObject)), MiniportAdapterHandle)

// net\ndis\samples\muxim\mux.h
#define MUX_IS_LOW_POWER_STATE(_PwrState)                       \
            ((_PwrState) > NdisDeviceStateD0)

// net\ndis\sys\mini.h
#define NDISWAN_OPTIONS                     (NDIS_MAC_OPTION_RESERVED | NDIS_MAC_OPTION_NDISWAN)
#define MINIPORT_LOCK_ACQUIRED(_Miniport)       ((_Miniport)->LockAcquired & 0x01)
#define MINIPORT_ENABLE_INTERRUPT(_M_)                                              \
{                                                                                   \
    if ((_M_)->EnableInterruptHandler != NULL)                                      \
    {                                                                               \
        ((_M_)->EnableInterruptHandler)((_M_)->MiniportAdapterContext);             \
    }                                                                               \
}
#define MINIPORT_SYNC_ENABLE_INTERRUPT(_M_)                                         \
{                                                                                   \
    if (((_M_)->Interrupt != NULL) &&                                               \
        ((_M_)->EnableInterruptHandler != NULL))                                    \
    {                                                                               \
        SYNC_WITH_ISR(((_M_))->Interrupt->InterruptObject,                          \
                      ((_M_)->EnableInterruptHandler),                              \
                      (_M_)->MiniportAdapterContext);                               \
    }                                                                               \
}
#define MINIPORT_SYNC_DISABLE_INTERRUPT(_M_)                                        \
{                                                                                   \
    if (((_M_)->Interrupt != NULL) &&                                               \
        ((_M_)->DisableInterruptHandler != NULL))                                   \
    {                                                                               \
        SYNC_WITH_ISR(((_M_))->Interrupt->InterruptObject,                          \
                      ((_M_)->DisableInterruptHandler),                             \
                      (_M_)->MiniportAdapterContext);                               \
    }                                                                               \
}
#define MINIPORT_ENABLE_INTERRUPT_EX(_M_, _I_)                                      \
{                                                                                   \
    if ((_M_)->EnableInterruptHandler != NULL)                                      \
    {                                                                               \
        ((_M_)->EnableInterruptHandler)((_I_)->Reserved);                           \
    }                                                                               \
}
#define MINIPORT_SYNC_ENABLE_INTERRUPT_EX(_M_, _I_)                                 \
{                                                                                   \
    if (((_M_)->Interrupt != NULL) &&                                               \
        ((_M_)->EnableInterruptHandler != NULL))                                    \
    {                                                                               \
        SYNC_WITH_ISR(((_I_))->InterruptObject,                                     \
                      ((_M_)->EnableInterruptHandler),                              \
                      (_I_)->Reserved);                                             \
    }                                                                               \
}
#define MINIPORT_SYNC_DISABLE_INTERRUPT_EX(_M_, _I_)                                \
{                                                                                   \
    if (((_M_)->Interrupt != NULL) &&                                               \
        ((_M_)->DisableInterruptHandler != NULL))                                   \
    {                                                                               \
        SYNC_WITH_ISR(((_I_))->InterruptObject,                                     \
                      ((_M_)->DisableInterruptHandler),                             \
                      (_I_)->Reserved);                                             \
    }                                                                               \
}
#define VC_INSTANCE_ID_SIZE             (sizeof(WCHAR) * 24)    // "XXXX:YYYYYYYYYYYYYYYY "
#define NDISM_DEFER_PROCESS_DEFERRED(_M)    QUEUE_DPC(&(_M)->DeferredDpc)
    #define READ_LOCK_FILTER(_Miniport, _Filter, _pLockState)   NDIS_READ_LOCK(&(_Filter)->BindListLock, _pLockState);
#define WRITE_LOCK_FILTER(_Miniport, _Filter, _pLockState)  \
    {                                                       \
        LOCK_HANDLER LockHandler =                          \
                (LOCK_HANDLER)((_Miniport)->LockHandler);   \
                                                            \
        (_pLockState)->LockState = WRITE_LOCK_STATE_UNKNOWN;\
        (*LockHandler)(_Filter, _pLockState);               \
    }
#define UNLOCK_FILTER(_Miniport, _Filter, _pLockState)      \
    {                                                       \
        LOCK_HANDLER LockHandler =                          \
                (LOCK_HANDLER)((_Miniport)->LockHandler);   \
                                                            \
        (*LockHandler)(_Filter, _pLockState);               \
    }

// net\ndis\sys\ndisnt.h
#define NDIS_ACQUIRE_SPIN_LOCK(_SpinLock, _pOldIrql) ExAcquireSpinLock(&(_SpinLock)->SpinLock, _pOldIrql)
#define NDIS_ACQUIRE_MINIPORT_SPIN_LOCK(_M, _pIrql)                         \
    NDIS_ACQUIRE_COMMON_SPIN_LOCK((_M), &(_M)->Lock, (_pIrql), (_M)->MiniportThread)
#define NDIS_ACQUIRE_MINIPORT_SPIN_LOCK_DPC(_M)                             \
    NDIS_ACQUIRE_COMMON_SPIN_LOCK_DPC((_M), &(_M)->Lock, (_M)->MiniportThread)
#define NDIS_INTERNAL_STALL(_N_)                                            \
    {                                                                       \
        volatile UINT   _cnt;                                               \
        for (_cnt = 0; _cnt < _N_; _cnt++)                                  \
            NOTHING;                                                        \
    }
#define NDIS_EQUAL_UNICODE_STRING(s1, s2)   (((s1)->Length == (s2)->Length) &&  \
                                             RtlEqualMemory((s1)->Buffer, (s2)->Buffer, (s1)->Length))
#define NDIS_PARTIAL_MATCH_UNICODE_STRING(s1, s2) \
                                            (((s1)->Length != (s2)->Length) &&  \
                                             RtlEqualMemory((s1)->Buffer, (s2)->Buffer, min((s1)->Length, (s2)->Length)))

// net\ndis\sys\protos.h
#define ndisReferenceMiniport(Miniport) ndisReferenceULongRef(&(Miniport)->Ref)

// net\netbeui\sys\info.c
#define STORE_RESOURCE_STATS_1(_ResourceNum,_ResourceId,_ResourceName) \
{ \
    PTDI_PROVIDER_RESOURCE_STATS RStats = &ProviderStatistics->ResourceStats[_ResourceNum]; \
    RStats->ResourceId = (_ResourceId); \
    RStats->MaximumResourceUsed = DeviceContext->_ResourceName ## MaxInUse; \
    if (DeviceContext->_ResourceName ## Samples > 0) { \
        RStats->AverageResourceUsed = DeviceContext->_ResourceName ## Total / DeviceContext->_ResourceName ## Samples; \
    } else { \
        RStats->AverageResourceUsed = 0; \
    } \
    RStats->ResourceExhausted = DeviceContext->_ResourceName ## Exhausted; \
}
#define STORE_RESOURCE_STATS_2(_ResourceNum,_ResourceId,_ResourceName) \
{ \
    PTDI_PROVIDER_RESOURCE_STATS RStats = &ProviderStatistics->ResourceStats[_ResourceNum]; \
    RStats->ResourceId = (_ResourceId); \
    RStats->MaximumResourceUsed = DeviceContext->_ResourceName ## Allocated; \
    RStats->AverageResourceUsed = DeviceContext->_ResourceName ## Allocated; \
    RStats->ResourceExhausted = DeviceContext->_ResourceName ## Exhausted; \
}

// net\netbt\inc\vxdprocs.h
#define IPINFO_BUFF_SIZE  (sizeof(IPInfo) + MAX_IP_NETS * sizeof(NetInfo))

// net\netbt\sys\parse.c
#define IsValidDnsNameTag(_c)       \
    ((_c != 0x01) &&                \
     ((_c < 0x1B) || (_c > 0x1E)))

// net\nwlink\inc\isnnb.h
#define REQUEST_MINOR_FUNCTION(_Request) \
    ((IoGetCurrentIrpStackLocation(_Request))->MinorFunction)
#define REQUEST_NDIS_BUFFER(_Request) \
    ((PNDIS_BUFFER)((_Request)->MdlAddress))

// net\nwlink\ipx\ipxtypes.h
#define	NIC_HANDLE_TO_BINDING(_device, _nichandle) \
	(((_nichandle)->Signature == IPX_BINDING_SIGNATURE) && \
		((_nichandle)->Version == (_device)->Bindings[(_nichandle)->NicId].Version)) ? \
			(_device)->Bindings[(_nichandle)->NicId].Binding : NULL;

// net\nwlink\spx\isnspx.h
#define REQUEST_MINOR_FUNCTION(_Request) \
    ((IoGetCurrentIrpStackLocation(_Request))->MinorFunction)
#define REQUEST_NDIS_BUFFER(_Request) \
    ((PNDIS_BUFFER)((_Request)->MdlAddress))

// net\nwlink\spx\spxpkt.h
#define		MIN_IPXSPX_HDRSIZE	(sizeof(IPXSPX_HDR) - sizeof(USHORT))
#define		MIN_IPXSPX2_HDRSIZE	sizeof(IPXSPX_HDR)

// net\nwlink\spx\spxutils.h
#define	IN_RANGE(_S, _RangeStart, _RangeEnd)		\
		((_S >= _RangeStart) && (_S <= _RangeEnd))

// net\qos\pclass\gpc\gpcdef.h
#define MAX_PATTERN_SIZE	    sizeof(GPC_IP_PATTERN)
#define NDIS_INIT_LOCK(_sl)      NdisAllocateSpinLock(&(_sl)->Lock)
#define NDIS_LOCK(_sl)           NdisAcquireSpinLock(&(_sl)->Lock)
#define NDIS_DPR_LOCK(_sl)       NdisDprAcquireSpinLock(&(_sl)->Lock)

// net\qos\psched\netshell\diffserv\qos-netsh\qosp.h
#define DIRECTION_BIDIRECTIONAL     (DIRECTION_INBOUND | DIRECTION_OUTBOUND)

// net\qos\psched\pschdprf\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// net\qos\psched\sys\globals.h
#define NDIS_MEDIA_LAN( _adpt ) (( _adpt )->MediaType == NdisMedium802_3 || \
                                 ( _adpt )->MediaType == NdisMedium802_5 || \
                                 ( _adpt )->MediaType == NdisMediumFddi || \
                                 ( _adpt )->MediaType == NdisMediumDix)

// net\qos\tc\dll\tctypes.h
#define IS_FLOW_READY(_f)   (!IS_INSTALLING(_f) && \
                             !IS_MODIFYING(_f) && \
                             !IS_DELETING(_f) && \
                             !IS_REMOVED(_f))

// net\rndis\rndismp\rndismp.h
#define RNDIS_DRIVER_MAC_OPTIONS        (NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA  | \
                                         NDIS_MAC_OPTION_TRANSFERS_NOT_PEND |   \
                                         NDIS_MAC_OPTION_NO_LOOPBACK)
#define RNDIS_COMPLETION(_Type) ((_Type) | 0x80000000)

// net\rras\cm\cmdial\icm.h
#define BAD_SCARD_PIN(x) ((SCARD_W_WRONG_CHV == (x)) || (SCARD_E_INVALID_CHV == (x)))

// net\rras\cps\pbsmon\perfutil.cpp
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// net\rras\dim\admindll\adsi.cpp
#define DSR_ADS_RIGHT_GENERIC_READ (ADS_RIGHT_READ_CONTROL    | \
                                    ADS_RIGHT_DS_LIST_OBJECT  | \
                                    ADS_RIGHT_DS_READ_PROP    | \
                                    ADS_RIGHT_ACTRL_DS_LIST   )

// net\rras\dim\admindll\rtcfg.c
#define MprConfigServerValidateCb(_x) \
    (((_x) && ((_x)->dwSigniture == SERVERCB_SIG)) ? NO_ERROR : ERROR_INVALID_PARAMETER)

// net\rras\inc\igmprm.h
#define IS_IFTYPE_PROXY(IfType)             ((IfType) & IGMP_IF_PROXY)
#define IS_CONFIG_IGMPRTR(pConfig) \
    (((pConfig)->IgmpProtocolType==IGMP_ROUTER_V1) \
    ||((pConfig)->IgmpProtocolType==IGMP_ROUTER_V2) \
    ||((pConfig)->IgmpProtocolType==IGMP_ROUTER_V3) )
#define IS_CONFIG_IGMPPROXY(pConfig) \
    ((pConfig)->IgmpProtocolType==IGMP_PROXY \
    ||(pConfig)->IgmpProtocolType==IGMP_PROXY_V3)
#define IS_CONFIG_IGMPPROXY_V3(pConfig) \
                                    ((pConfig)->IgmpProtocolType==IGMP_PROXY_V3)

// net\rras\ip\bootp\table.h
#define IF_IS_ACTIVE(i)     \
        (IF_IS_BOUND(i) && IF_IS_ENABLED(i))

// net\rras\ip\dvmrp\main.h
#define IS_IF_ENABLED(pite) \
        ( IS_IF_ENABLED_BY_RTRMGR(pite) && IS_IF_ENABLED_IN_CONFIG(pite) )
#define IS_IF_ENABLED_BOUND(pite) \
        (IS_IF_ENABLED(pite)&&IS_IF_BOUND(pite))

// net\rras\ip\fltrdrvr\defs.h
#define SIZEOF_FILTERS1(X) (((((X)->dwNumInFilters + (X)->dwNumOutFilters) is 0)?0:((X)->dwNumInFilters + (X)->dwNumOutFilters - 1) * sizeof(FILTER_STATS)))

// net\rras\ip\igmp\macros.h
#define IS_PROTOCOL_TYPE_PROXY(_pite) \
                ((_pite)->Config.IgmpProtocolType==IGMP_PROXY \
                ||(_pite)->Config.IgmpProtocolType==IGMP_PROXY_V3)
#define IS_PROTOCOL_TYPE_PROXY_V2(_pite) \
                ((_pite)->Config.IgmpProtocolType==IGMP_PROXY)
#define IS_PROTOCOL_TYPE_PROXY_V3(_pite) \
                ((_pite)->Config.IgmpProtocolType==IGMP_PROXY_V3)
#define IS_PROTOCOL_TYPE_IGMPV1(_pite) \
                ((_pite)->Config.IgmpProtocolType==IGMP_ROUTER_V1)
#define IS_PROTOCOL_TYPE_IGMPV2(_pite) \
                ((_pite)->Config.IgmpProtocolType==IGMP_ROUTER_V2)
#define IS_PROTOCOL_TYPE_IGMPV3(_pite) \
                ((_pite)->Config.IgmpProtocolType==IGMP_ROUTER_V3)
#define GET_EXTERNAL_IF_TYPE(_pite)  \
    IS_PROTOCOL_TYPE_PROXY(_pite) ? ((_pite->IfType)|IGMP_IF_PROXY) \
                                : (_pite)->IfType
#define IS_IF_ENABLED(pite) \
        ( IS_IF_ENABLED_BY_RTRMGR(pite) && IS_IF_ENABLED_IN_CONFIG(pite) )
#define IS_IF_ENABLED_BOUND(pite) \
        (IS_IF_ENABLED(pite)&&IS_IF_BOUND(pite))
#define IS_QUERIER(pite)        ((pite)->Info.QuerierState & QUERIER)
#define IF_PROCESS_GRPQUERY(pite) \
    ( (IS_IF_VER2(pite)||IS_IF_VER3(pite)) && !IS_RAS_SERVER_IF(pite->IfType) )
#define IF_PROCESS_LEAVES(pite)  \
    ( IS_IF_VER2(pite) && (IS_QUERIER(pite)) && !IS_RAS_SERVER_IF(pite->IfType))
#define CAN_ADD_GROUPS_TO_MGM(pite)         \
        ( (IS_IGMPRTR_ENABLED_BY_MGM(pite)) \
        && (IS_MPROTOCOL_PRESENT_ON_IGMPRTR(pite) || (IS_QUERIER(pite))) \
        )
#define GET_EXTERNAL_IF_STATE(pite, State) {\
    State = 0;\
    if (IS_IF_ENABLED_BY_RTRMGR(pite)) \
        State |= IGMP_STATE_ENABLED_BY_RTRMGR; \
    if (IS_IF_ENABLED_IN_CONFIG(pite))\
        State |= IGMP_STATE_ENABLED_IN_CONFIG; \
    if (IS_PROTOCOL_TYPE_ROUTER(pite)) {\
        if (IS_IGMPRTR_ENABLED_BY_MGM(pite)) \
            State |= IGMP_STATE_ENABLED_BY_MGM; \
        if (CAN_ADD_GROUPS_TO_MGM(pite)) \
            State |= IGMP_STATE_MGM_JOINS_ENABLED; \
    } \
    else \
        State |= IGMP_STATE_ENABLED_BY_MGM; \
    \
    if (IS_IF_BOUND(pite)) \
        State |= IGMP_STATE_BOUND;\
}
#define IS_NOT_EQ_ANY2(a, A,B) ((a!=A)&&(a!=B))
#define IS_EQ_ANY(a,A,B) ((a==A)||(a==B))

// net\rras\ip\ipinip\ipinip.h
#define MarkTunnelMapped(p)         (p)->dwAdminState |= TS_MAPPED;
#define MarkTunnelUnmapped(p)       (p)->dwAdminState &= ~TS_MAPPED;
#define IsTunnelMapped(p)           ((p)->dwAdminState & TS_MAPPED)
#define GetAdminState(p)            ((p)->dwAdminState & 0x0000FFFF)

// net\rras\ip\nat\prot.h
#define MAX_MSSOPTION(m) ((m)>0 ? (m) - sizeof(TCP_HEADER) - sizeof(IP_HEADER):0)

// net\rras\ip\nat\xlate.h
#define CHECKSUM_XFER(dst,src) \
    (dst) = (USHORT)~(src)

// net\rras\ip\nath323\ovioctx.h
#define ACCEPT_BUFFER_MAX       (sizeof (SOCKADDR_IN) * 2 + 0x20)

// net\rras\ip\rip\defs.h
#define IS_LOOPBACK_ADDR(a) (((a) & 0xff) == 0x7f)

// net\rras\ip\rip\table.h
#define IF_IS_ACTIVE(i)     \
            (IF_IS_BOUND(i) && IF_IS_ENABLED(i))

// net\rras\ip\rip\work.c
#define IS_ROUTE_IN_FILTER(route,ret)                       \
    (ret) = 0;                                              \
    for ( ; _pfilt < _pfiltend; _pfilt++) {                 \
        _filt = _pfilt->RF_LoAddress;                       \
        if (INET_CMP(route, _filt, _cmp) == 0) { (ret) = 1; break; }    \
        else if (_cmp > 0) {                                \
            _filt = _pfilt->RF_HiAddress;                   \
            if (INET_CMP(route, _filt, _cmp) <= 0) { (ret) = 1; break; }\
        }                                                   \
    }

// net\rras\ip\rtrmgr\defs.h
#define IP_SETTABLE_ROUTE   (IP_VALID_ROUTE | IP_STACK_ROUTE)
#define MAX_ROUTES_IN_BUFFER(X) ((X) / sizeof (MIB_IPFORWARDROW))

// net\rras\ip\rtrmgr\mbound.h
#define   SNCHARSIZE sizeof(SN_CHAR)

// net\rras\ipx\rip\changebc.c
#define 	IsStartShutdown() \
		wip->WorkItemSpecific.WIS_ShutdownInterfaces.ShutdownState == SHUTDOWN_START

// net\rras\ipx\rip\ifmgr.c
#define IsInterfaceBound(icbp)\
    ((icbp)->AdapterBindingInfo.AdapterIndex != INVALID_ADAPTER_INDEX)
#define IsInterfaceEnabled(icbp)\
    (((icbp)->IfConfigInfo.AdminState == ADMIN_STATE_ENABLED) &&\
     ((icbp)->IpxIfAdminState == ADMIN_STATE_ENABLED))

// net\rras\ipx\rtrmgr\rtrmgr.h
#define     IPX_MAX_ROUTING_TABLE_SIZE		100000 * sizeof(RTM_IPX_ROUTE)

// net\rras\ipx\rtrmgr\test\testmib.c
#define REPORT_RIP_CONFIG_STATE(report, config)    \
	switch((config)) {\
	case ADMIN_STATE_ENABLED:\
	    (report) = "ENABLED";\
	    break;\
	case ADMIN_STATE_DISABLED:\
	    (report) = "DISABLED";\
	    break;\
	default:\
	    (report) = "UNKNOWN";\
	    break;\
	}

// net\rras\ipx\sap\intfdb.c
#define IsInterfaceValid(node) IsListEntry(&node->IN_IntfLink)
#define InvalidateInterface(node) InitializeListEntry(&node->IN_IntfLink)

// net\rras\ipx\snmp\rtipxmib.h
#define GetAsnOctetString(dst,srcBuf,maxlen,defVal)			\
	(((srcBuf)->asnType)									\
		? (memset (&(dst)[(srcBuf)->asnValue.string.length],\
				0, maxlen-(srcBuf)->asnValue.string.length),\
			memcpy (dst,(srcBuf)->asnValue.string.stream,	\
				(srcBuf)->asnValue.string.length))			\
		: (defVal ? memcpy (dst, defVal, maxlen) : NULL))

// net\rras\mgm\defs.h
#define IS_VALID_PROTOCOL( a, b ) \
        (a) != INVALID_PROTOCOL_ID && (b) != INVALID_COMPONENT_ID
#define IS_PROTOCOL_IGMP( p )  \
        ( (p)-> dwProtocolId == PROTO_IP_IGMP )

// net\rras\mgm\ipmgm.h
#define IS_JOIN_ALERT( p ) \
        (p)-> rpcProtocolConfig.pfnJoinAlertCallback != NULL
#define IS_PRUNE_ALERT( p ) \
        (p)-> rpcProtocolConfig.pfnPruneAlertCallback != NULL
#define IS_LOCAL_JOIN_ALERT( p ) \
        (p)-> rpcProtocolConfig.pfnLocalJoinCallback != NULL
#define IS_LOCAL_LEAVE_ALERT( p ) \
        (p)-> rpcProtocolConfig.pfnLocalLeaveCallback != NULL
#define IS_RPF_CALLBACK( p ) \
        (p)-> rpcProtocolConfig.pfnRpfCallback != NULL
#define IS_CREATION_ALERT( p ) \
        (p)-> rpcProtocolConfig.pfnCreationAlertCallback != NULL

// net\rras\ndis\asyncmac\asyncall.h
#define PPP_ALL     (PPP_FRAMING | \
                     PPP_COMPRESS_ADDRESS_CONTROL | \
                     PPP_COMPRESS_PROTOCOL_FIELD | \
                     PPP_ACCM_SUPPORTED)
#define SLIP_ALL    (SLIP_FRAMING | \
                     SLIP_VJ_COMPRESSION | \
                     SLIP_VJ_AUTODETECT)

// net\rras\ndis\asyncmac\asyncsft.h
#define PASYNC_PEND_DATA_FROM_PNDIS_REQUEST(Request) \
   ((PASYNC_PEND_DATA)((PVOID)((Request)->MacReserved)))

// net\rras\ndis\ndiswan\adapter.h
#define MINIPORTCB_SIZE sizeof(MINIPORTCB)

// net\rras\ndis\ndiswan\wandefs.h
#define REF_MINIPORTCB(_pmcb)                                   \
    InterlockedIncrement(&(_pmcb)->RefCount)
#define PROTOCOLCB_FROM_PROTOCOLH(_pBCB, _pPCB, _hP)    \
{                                                       \
    if (_hP < MAX_PROTOCOLS) {                          \
        _pPCB = _pBCB->ProtocolCBTable[_hP];            \
    } else {                                            \
        _pPCB = NULL;                                   \
    }                                                   \
}

// net\rras\ndis\ndproxy\pxtapi.h
#define ALL_ADDRESS_FEATURES       (LINEADDRFEATURE_FORWARD          | \
                                    LINEADDRFEATURE_MAKECALL         | \
                                    LINEADDRFEATURE_PICKUP           | \
                                    LINEADDRFEATURE_SETMEDIACONTROL  | \
                                    LINEADDRFEATURE_SETTERMINAL      | \
                                    LINEADDRFEATURE_SETUPCONF        | \
                                    LINEADDRFEATURE_UNCOMPLETECALL   | \
                                    LINEADDRFEATURE_UNPARK)
#define ALL_ADDRESS_STATES         (LINEADDRESSSTATE_OTHER           | \
                                    LINEADDRESSSTATE_DEVSPECIFIC     | \
                                    LINEADDRESSSTATE_INUSEZERO       | \
                                    LINEADDRESSSTATE_INUSEONE        | \
                                    LINEADDRESSSTATE_INUSEMANY       | \
                                    LINEADDRESSSTATE_NUMCALLS        | \
                                    LINEADDRESSSTATE_FORWARD         | \
                                    LINEADDRESSSTATE_TERMINALS       | \
                                    LINEADDRESSSTATE_CAPSCHANGE)
#define ALL_CALL_INFO_STATES       (LINECALLINFOSTATE_OTHER          | \
                                    LINECALLINFOSTATE_DEVSPECIFIC    | \
                                    LINECALLINFOSTATE_BEARERMODE     | \
                                    LINECALLINFOSTATE_RATE           | \
                                    LINECALLINFOSTATE_MEDIAMODE      | \
                                    LINECALLINFOSTATE_APPSPECIFIC    | \
                                    LINECALLINFOSTATE_CALLID         | \
                                    LINECALLINFOSTATE_RELATEDCALLID  | \
                                    LINECALLINFOSTATE_ORIGIN         | \
                                    LINECALLINFOSTATE_REASON         | \
                                    LINECALLINFOSTATE_COMPLETIONID   | \
                                    LINECALLINFOSTATE_TRUNK          | \
                                    LINECALLINFOSTATE_CALLERID       | \
                                    LINECALLINFOSTATE_CALLEDID       | \
                                    LINECALLINFOSTATE_CONNECTEDID    | \
                                    LINECALLINFOSTATE_REDIRECTIONID  | \
                                    LINECALLINFOSTATE_REDIRECTINGID  | \
                                    LINECALLINFOSTATE_DISPLAY        | \
                                    LINECALLINFOSTATE_USERUSERINFO   | \
                                    LINECALLINFOSTATE_HIGHLEVELCOMP  | \
                                    LINECALLINFOSTATE_LOWLEVELCOMP   | \
                                    LINECALLINFOSTATE_CHARGINGINFO   | \
                                    LINECALLINFOSTATE_TERMINAL       | \
                                    LINECALLINFOSTATE_DIALPARAMS     | \
                                    LINECALLINFOSTATE_MONITORMODES)
#define ALL_LINE_FEATURES          (LINEFEATURE_DEVSPECIFIC          | \
                                    LINEFEATURE_DEVSPECIFICFEAT      | \
                                    LINEFEATURE_FORWARD              | \
                                    LINEFEATURE_MAKECALL             | \
                                    LINEFEATURE_SETMEDIACONTROL      | \
                                    LINEFEATURE_SETTERMINAL)

// net\rras\ndis\raspppoe\miniport.h
        #define TAPI_LINECALLSTATES_SUPPORTED   ( LINECALLSTATE_IDLE        | \
                                                  LINECALLSTATE_OFFERING    | \
                                                  LINECALLSTATE_DIALING     | \
                                                  LINECALLSTATE_PROCEEDING  | \
                                                  LINECALLSTATE_CONNECTED   | \
                                                  LINECALLSTATE_DISCONNECTED )
#define ALLOC_ADAPTER( ppA ) NdisAllocateMemoryWithTag( (PVOID*) ppA, sizeof( ADAPTER ), MTAG_ADAPTER )
#define VALIDATE_ADAPTER( pA ) ( (pA) && (pA->tagAdapter == MTAG_ADAPTER) )
#define InsertBefore( pNewL, pL )    \
{                                    \
    (pNewL)->Flink = (pL);           \
    (pNewL)->Blink = (pL)->Blink;    \
    (pNewL)->Flink->Blink = (pNewL); \
    (pNewL)->Blink->Flink = (pNewL); \
}
#define InsertAfter( pNewL, pL )     \
{                                    \
    (pNewL)->Flink = (pL)->Flink;    \
    (pNewL)->Blink = (pL);           \
    (pNewL)->Flink->Blink = (pNewL); \
    (pNewL)->Blink->Flink = (pNewL); \
}

// net\rras\ndis\raspppoe\protocol.h
#define VALIDATE_BINDING( pB )  ( ( pB ) && ( pB->tagBinding == MTAG_BINDING ) )

// net\rras\ndis\raspppoe\tapi.h
#define VALIDATE_LINE( pL ) ( (pL) && (pL->tagLine == MTAG_LINE) )
#define VALIDATE_CALL( pC ) ( (pC) && (pC->tagCall == MTAG_CALL) )

// net\rras\ndis\raspptp\common\raspptp.h
#define IS_CALL(call) ((call) && (call)->Signature==TAG_PPTP_CALL)
#define IS_CTL(ctl)  ((ctl) && (ctl)->Signature==TAG_PPTP_TUNNEL)

// net\rras\ndis\raspptp\nt\ctdi.c
#define IS_CTDI(c) ((c) && (c)->Signature==CTDI_SIGNATURE)

// net\rras\ndis\raspptp\nt\osinc.h
#define TAPI_DEV_CAPS_SIZE          (sizeof(TAPI_PROVIDER_STRING)+ \
                                     TapiLineName.Length + sizeof(UCHAR) * 6 +\
                                     sizeof(NDIS_TAPI_GET_DEV_CAPS))
#define OS_RANGE_CHECK_MAX_TRANSMIT(mt) \
    if ((unsigned)(mt)<1) (mt) = 1;     \
    if ((unsigned)(mt)>1024) (mt) = 1024;

// net\rras\netsh\aaaa\aaaamontr.h
#define AAAAMON_CMD_ARG_GetPsz(pArg)     \
    (((pArg)->rgTag.bPresent) ? (pArg)->Val.pszValue : NULL)

// net\rras\netsh\if\utils.h
#define IFMON_CMD_ARG_GetPsz(pArg)     \
    (((pArg)->rgTag.bPresent) ? (pArg)->Val.pszValue : NULL)

// net\rras\netsh\ip\ipmon\filter.c
#define __PF_ACT(x) \
    ((((x) is NULL) || ((x)->faDefaultAction is PF_ACTION_FORWARD)) ? \
     pwszForward : pwszDrop)

// net\rras\netsh\ip\preview\ipprodefs.h
#define IS_MCAST_ADDR(Group) \
    ( (0x000000E0!=(Group))  \
      && (0x000000E0 <= ((Group)&0x000000FF) ) \
      && (0x000000F0 >  ((Group)&0x000000FF) ) )

// net\rras\netsh\ip\preview\ipprvwdefs.h
#define IS_MCAST_ADDR(Group) \
    ( (0x000000E0!=(Group))  \
      && (0x000000E0 <= ((Group)&0x000000FF) ) \
      && (0x000000F0 >  ((Group)&0x000000FF) ) )

// net\rras\netsh\ras\rasmontr.h
#define RASMON_CMD_ARG_GetPsz(pArg)     \
    (((pArg)->rgTag.bPresent) ? (pArg)->Val.pszValue : NULL)

// net\rras\ras\autodial\rasauto\reg.c
#define TOKEN_INFORMATION_SIZE  (sizeof (TOKEN_USER) + sizeof (SID) + (sizeof (ULONG) * SID_MAX_SUB_AUTHORITIES))

// net\rras\ras\ui\extapi\src\extapi.h
#define IS_HPORT(h) ((NULL != h) && (HandleToUlong(h) & 0xffff0000) ? FALSE : TRUE)

// net\rras\ras\ui\perf\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// net\rras\ras\ui\rasdlg\pbook.c
#define RAS_SC_IS_BAD_PIN(_err) \
    (((_err) == SCARD_W_WRONG_CHV) || ((_err) == SCARD_E_INVALID_CHV))

// net\rras\ras\ui\rasscrpt\ast.c
#define Astexec_Validate(this)      ((this)->hpaPcode && (this)->psci)

// net\rras\ras\ui\rasscrpt\eval.c
            #define IS_CARET(ch)            ('^' == (ch))

// net\rras\ras\ui\rasscrpt\scanner.c
#define IS_WHITESPACE(ch)       (' ' == (ch) || '\t' == (ch) || '\n' == (ch) || '\r' == (ch))

// net\rras\ras\ui\rasscrpt\util.c
    #define IS_CARET(ch)            ('^' == (ch))

// net\rras\rtm\rtmp.h
#define ValidateRoute(Table,Route) \
			(*Table->RT_Config.RPFC_Validate)(Route)

// net\rras\rtmv2\rtm1to2.h
#define ALLOC_ROUTE_INFO(NumNextHops, NumInfos)                             \
        (PRTM_ROUTE_INFO) _alloca((sizeof(RTM_ROUTE_INFO) +                 \
                                  (NumNextHops - 1) *                       \
                                   sizeof(RTM_NEXTHOP_HANDLE)) * NumInfos)  \

// net\rras\rtmv2\rtmmain.h
#define DEREFERENCE_ADDR_FAMILY(AddrFamInfo, RefType)                       \
            if (DereferenceObject(&AddrFamInfo->ObjectHeader,RefType) == 0) \
                DestroyAddressFamily(AddrFamInfo);

// net\sfm\afp\inc\admin.h
#define	AFP_CC_METHOD(ControlCode)	((ControlCode) & 0x03)
#define	DIR_ACCESS_ALL				(DIR_ACCESS_READ	| \
									 DIR_ACCESS_SEARCH	| \
									 DIR_ACCESS_WRITE)
#define	AFP_READ_ACCESS		(READ_CONTROL		 |	\
							FILE_READ_ATTRIBUTES |	\
							FILE_TRAVERSE		 |	\
							FILE_LIST_DIRECTORY	 |	\
							FILE_READ_EA)
#define	AFP_OWNER_ACCESS	(WRITE_DAC			  | \
							 WRITE_OWNER)
#define	AFP_MIN_ACCESS		(FILE_READ_ATTRIBUTES | \
							 READ_CONTROL)

// net\sfm\afp\server\access.h
#define	AFP_MIN_ACCESS		(FILE_READ_ATTRIBUTES | \
							 READ_CONTROL)

// net\sfm\afp\server\admin.c
#define	afpIsValidExtension(ext)	(((ext)[AFP_EXTENSION_LEN] == '\0') && \
									 ((ext)[0] != '\0') )
#define afpCopyEtcMap(pdst,psrc)	(RtlCopyMemory(pdst,psrc,sizeof(ETCMAPINFO)))

// net\sfm\afp\server\afpconst.h
#define	VALIDPATHTYPE(PathType)	\
			(PathType == AFP_LONGNAME || PathType == AFP_SHORTNAME)

// net\sfm\afp\server\afpmem.h
#define AfpSetEmptyUnicodeString(pstring,buflen,pbuf)		\
{															\
  (pstring)->Length = 0;									\
  (pstring)->MaximumLength = (USHORT)buflen;				\
  (pstring)->Buffer = (PWSTR)(pbuf);						\
}
#define AfpSetEmptyAnsiString(pstring,buflen,pbuf)			\
{															\
  (pstring)->Length = 0;									\
  (pstring)->MaximumLength = (USHORT)buflen;				\
  (pstring)->Buffer = (PCHAR)(pbuf);						\
}
#define AfpInitUnicodeStringWithNonNullTerm(pstring,buflen,pbuf) \
{															\
	(pstring)->Buffer = pbuf;								\
	(pstring)->Length = (USHORT)buflen; 					\
	(pstring)->MaximumLength = (USHORT)buflen;				\
}
#define AfpInitAnsiStringWithNonNullTerm(pstring,buflen,pbuf) \
{															\
	(pstring)->Buffer = pbuf;								\
	(pstring)->Length = (USHORT)buflen; 					\
	(pstring)->MaximumLength = (USHORT)buflen;				\
}

// net\sfm\afp\server\fdparm.h
#define	AfpInitializeFDParms(pFDParms)	\
			(pFDParms)->_fdp_LongName.MaximumLength = AFP_LONGNAME_LEN+1;	\
			(pFDParms)->_fdp_LongName.Length = 0;							\
			(pFDParms)->_fdp_LongName.Buffer = (pFDParms)->_fdp_LongNameBuf;\
			(pFDParms)->_fdp_ShortName.MaximumLength = AFP_SHORTNAME_LEN+1;	\
			(pFDParms)->_fdp_ShortName.Length = 0;							\
			(pFDParms)->_fdp_ShortName.Buffer = (pFDParms)->_fdp_ShortNameBuf;

// net\sfm\afp\server\fileio.h
#define IS_DATA_STREAM(pUnicodeStreamName) \
		EQUAL_UNICODE_STRING(pUnicodeStreamName, &DataStreamName, False)
#define IS_COMMENT_STREAM(pUnicodeStreamName) \
		EQUAL_UNICODE_STRING(pUnicodeStreamName, &FullCommentStreamName, False)
#define IS_RESOURCE_STREAM(pUnicodeStreamName) \
		EQUAL_UNICODE_STRING(pUnicodeStreamName, &FullResourceStreamName, True)
#define IS_INFO_STREAM(pUnicodeStreamName) \
		EQUAL_UNICODE_STRING(pUnicodeStreamName, &FullInfoStreamName, True)
#define	VALID_FSH(pFSH)		(((pFSH) != NULL) && \
							 ((pFSH)->fsh_FileHandle != NULL) && \
							 ((pFSH)->fsh_FileObject != NULL) && \
							 ((pFSH)->Signature == FSH_SIGNATURE))
#define	VALID_FSH(pFSH)		(((pFSH)->fsh_FileHandle != NULL) && \
							 ((pFSH)->fsh_FileObject != NULL))

// net\sfm\afp\server\forkio.h
#define	VALID_CTX(pCmplCtxt)	(((pCmplCtxt) != NULL) && \
								 ((pCmplCtxt)->Signature == CTX_SIGNATURE))

// net\sfm\afp\server\forks.h
#define	VALID_FORKLOCK				(((pForkLock) != NULL) && \
									 ((pForkLock)->Signature == FORKLOCK_SIGNATURE))
#define	VALID_OPENFORKDESC(pOpenForkDesc)	(((pOpenForkDesc) != NULL) && \
						((pOpenForkDesc)->Signature == OPENFORKDESC_SIGNATURE))

// net\sfm\afp\server\idindex.h
#define	afpMarkAllChildrenUnseen(_pDFETree)								\
	{																	\
		LONG		i = -1;												\
		PDFENTRY	pDFE;												\
																		\
		/*																\
		 * Even if this dir has not had its file children cached in		\
		 * yet, we still want to prune out any dead directory children	\
		 */																\
		for (pDFE = (_pDFETree)->dfe_pDirEntry->de_ChildDir;			\
			 True;														\
			 pDFE = (_pDFETree)->dfe_pDirEntry->de_ChildFile[i])		\
		{																\
			for (NOTHING;												\
				 pDFE != NULL;											\
				 pDFE = pDFE->dfe_NextSibling)							\
			{															\
				DFE_MARK_UNSEEN(pDFE);									\
			}															\
			if (++i == MAX_CHILD_HASH_BUCKETS)							\
				break;													\
		}																\
	}

// net\sfm\afp\server\iopool.h
#define	VALID_PLH(pPoolHdr)			(((pPoolHdr) != NULL) && \
									 ((pPoolHdr)->Signature == POOLHDR_SIGNATURE))
#define	VALID_IOP(pPool)			(((pPool) != NULL) && \
									 ((pPool)->Signature == IOPOOL_SIGNATURE))

// net\sfm\afp\server\pathmap.h
#define	AfpInitializePME(pPME, FullPathLen, FullPathBuffer)			\
				(pPME)->pme_FullPath.Buffer = FullPathBuffer;		\
                (pPME)->pme_FullPath.MaximumLength = FullPathLen;	\
                (pPME)->pme_Handle.fsh_FileHandle = NULL
#define	afpGetNextComponent(_pPath, _Length, _PathType, _Component, _pIndex)	\
	do																			\
	{                                                                           \
		int			Length = _Length;                                           \
		PCHAR		pPath = _pPath;                                             \
		int			maxlen;                                                     \
		CHAR		ch;                                                         \
	                                                                            \
		maxlen = (_PathType == AFP_LONGNAME) ?                                  \
						AFP_LONGNAME_LEN :                                      \
						AFP_SHORTNAME_LEN;                                      \
		*(_pIndex) = 0;                                                         \
                                                                                \
		while ((Length > 0) && ((ch = *pPath) != '\0'))                         \
		{                                                                       \
			if ((*(_pIndex) == maxlen) || (ch == ':'))                          \
			{                                                                   \
	            /* component too long or invalid char */                        \
				*(_pIndex) = -1;                                                \
				break;                                                          \
			}                                                                   \
	                                                                            \
			(_Component)[(*(_pIndex))++] = ch;                                  \
	                                                                            \
			pPath++;                                                            \
			Length--;                                                           \
		}                                                                       \
                                                                                \
		if (*(_pIndex) == -1)                                                   \
			break;                                                              \
	                                                                            \
		/* null terminate the component */                                      \
		(_Component)[*(_pIndex)] = (CHAR)0;                                     \
	                                                                            \
		if ((PathType == AFP_SHORTNAME) && ((_Component)[0] != AFP_PATHSEP))    \
		{                                                                       \
			ANSI_STRING	as;                                                     \
	                                                                            \
			AfpInitUnicodeStringWithNonNullTerm(&as, *(_pIndex), _Component);   \
			if (!AfpIsLegalShortname(&as))                                      \
			{                                                                   \
				*(_pIndex) = -1;                                                \
				break;                                                          \
			}                                                                   \
		}                                                                       \
	                                                                            \
		/* if we stopped due to null, move past it */                           \
		if (Length > 0)                                                         \
		{                                                                       \
			(*(_pIndex))++;                                                     \
		}																		\
	} while (FALSE);

// net\sfm\afp\server\sda.h
#define	VALID_SDA(pSda)		(((pSda) != NULL) && \
							 ((pSda)->Signature == SDA_SIGNATURE))

// net\sfm\afp\server\swmr.h
#define	VALID_SWMR(pSwmr)	(((pSwmr) != NULL) && \
							 ((pSwmr)->Signature == SWMR_SIGNATURE))

// net\sfm\afp\server\tcp.h
#define VALID_TCPCONN(_pTcpConn)                                       \
    ((_pTcpConn->con_Signature == DSI_CONN_SIGNATURE) &&               \
     (_pTcpConn->con_RefCount > 0 && _pTcpConn->con_RefCount < 5000))   \

// net\sfm\afp\server\volume.h
#define	VALID_VOLDESC(pVolDesc)	(((pVolDesc) != NULL) && \
								 ((pVolDesc)->Signature == VOLDESC_SIGNATURE))
#define	VALID_CONNDESC(pConnDesc)	\
								(((pConnDesc) != NULL) && \
								 ((pConnDesc)->Signature == CONNDESC_SIGNATURE))

// net\sfm\afp\sfmctrs\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// net\sfm\atalk\perfctrs\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// net\sfm\atalk\sys\adsp.h
#define	ADSP_MIN_ATTEN_PKT_SIZE			sizeof(USHORT)

// net\sfm\atalk\sys\asp.h
#define	VALID_ASPCO(pAspConn)	(((pAspConn) != NULL) && \
								 ((pAspConn)->aspco_Signature == ASPCO_SIGNATURE))
#define	VALID_ASPRQ(pAspReq)	(((pAspReq) != NULL) && \
								 ((pAspReq)->asprq_Signature == ASPRQ_SIGNATURE))

// net\sfm\atalk\sys\aspc.h
#define	VALID_ASPCRQ(pAspCReq)	(((pAspCReq) != NULL) && \
								 ((pAspCReq)->aspcrq_Signature == ASPRQ_SIGNATURE))

// net\sfm\atalk\sys\atkmem.h
#define	VALID_BUFFDESC(pBuffDesc)	\
				(((pBuffDesc) != NULL) && ((pBuffDesc)->bd_Signature == BD_SIGNATURE))

// net\sfm\atalk\sys\atkndis.h
#define	ATALK_RECV_INDICATION_COPY(_pPortDesc, _pDest, _pSrc, _Len)		\
	{																	\
		TdiCopyLookaheadData(_pDest,									\
							 _pSrc,										\
							 _Len,										\
							 ((_pPortDesc)->pd_MacOptions & NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA) ? \
									TDI_RECEIVE_COPY_LOOKAHEAD : 0);	\
	}

// net\sfm\atalk\sys\atktdi.h
#define	VALID_ACTREQ(pActReq)	(((pActReq) != NULL) &&	\
								 ((pActReq)->ar_Signature == ACTREQ_SIGNATURE))

// net\sfm\atalk\sys\atkutils.h
#define	IN_NETWORK_RANGE(NetworkNumber, pRte)									\
			(((pRte)->rte_NwRange.anr_FirstNetwork == NetworkNumber)   ||		\
			  ((NetworkNumber >= (pRte)->rte_NwRange.anr_FirstNetwork) &&		\
			   (NetworkNumber <= (pRte)->rte_NwRange.anr_LastNetwork)))
#define	WITHIN_NETWORK_RANGE(NetworkNumber, pRange)								\
			 (((pRange)->anr_FirstNetwork == NetworkNumber) ||					\
			  ((NetworkNumber >= (pRange)->anr_FirstNetwork) &&					\
			   (NetworkNumber <= (pRange)->anr_LastNetwork)))
#define	AtalkRangesOverlap(pRange1, pRange2)									\
		(((pRange1)->anr_LastNetwork >= (pRange2)->anr_FirstNetwork) &&			\
		 ((pRange1)->anr_FirstNetwork <= (pRange2)->anr_LastNetwork))

// net\sfm\atalk\sys\atp.h
#define	VALID_ATPRQ(pAtpReq)		(((pAtpReq) != NULL) &&						\
									 ((pAtpReq)->req_Signature == ATP_REQ_SIGNATURE))
#define	VALID_ATPRS(pAtpResp)			(((pAtpResp) != NULL) &&				\
										 ((pAtpResp)->resp_Signature == ATP_RESP_SIGNATURE))

// net\sfm\atalk\sys\blkpool.h
#define	VALID_BC(pChunk)	(((pChunk) != NULL) && \
							 ((pChunk)->bc_Signature == BC_SIGNATURE))
#define	VALID_BH(pBlkHdr)	(((pBlkHdr) != NULL) && \
							 ((pBlkHdr)->bh_Signature == BH_SIGNATURE))

// net\sfm\atalk\sys\ddp.h
#define	IS_VALID_SOCKET(Socket)								\
			((Socket == DYNAMIC_SOCKET)			||			\
			 (Socket == LAST_DYNAMIC_SOCKET)	||			\
			 ((Socket >= FIRST_STATIC_SOCKET) &&			\
				(Socket <= LAST_STATIC_SOCKET)))

// net\sfm\atalk\sys\nbp.h
#define	VALID_REGDNAME(pRegdName)	(((pRegdName) != NULL) && \
									 ((pRegdName)->rdn_Signature == RDN_SIGNATURE))
#define	VALID_PENDNAME(pPendName)	(((pPendName) != NULL) && \
									 ((pPendName)->pdn_Signature == PDN_SIGNATURE))

// net\sfm\atalk\sys\node.h
#define	VALID_ATALK_NODE(pNode)	(((pNode) != NULL) &&	\
								 ((pNode)->an_Signature == AN_SIGNATURE))

// net\sfm\atalk\sys\ports.h
#define	VALID_AMT(pAmt)		(((pAmt) != NULL) &&	\
							 ((pAmt)->amt_Signature == AMT_SIGNATURE))
#define	VALID_PORT(pPortDesc)	(((pPortDesc) != NULL) &&	\
								 ((pPortDesc)->pd_Signature == PD_SIGNATURE))

// net\sfm\atalk\sys\rtmp.h
#define	VALID_RTE(pRte)		((pRte != NULL) && (pRte->rte_Signature == RTE_SIGNATURE))

// net\sfm\atalk\sys\zip.h
#define	VALID_ZCI(pZci)	(((pZci) != NULL) &&	\
						 ((pZci)->zci_Signature == ZCI_SIGNATURE))

// net\sfm\setup\util\access.c
#define	AFP_MIN_ACCESS		(FILE_READ_ATTRIBUTES | \
							 READ_CONTROL)

// net\snmp\subagent\snmpevnt\evntwin\evntprop.cpp
#define IsWithinRange(value, lower, upper) (((value) >= (lower)) && ((value) <= (upper)))

// net\sockets\samples\wshsmple\wshsmple.c
#define IS_DGRAM_SOCK(type)  (((type) == SOCK_DGRAM) || ((type) == SOCK_RAW))
#define MAX_FAST_ENTITY_BUFFER ( sizeof(TDIEntityID) * 10 )

// net\sockets\winsock2\wsp\afdsys\afdprocs.h
#define IS_DATA_ON_CONNECTION_NB(conn)                                        \
            ( (conn)->VcBufferredReceiveCount != 0 )
#define IS_EXPEDITED_DATA_ON_CONNECTION_NB(conn)                              \
            ( (conn)->VcBufferredExpeditedCount != 0 )

// net\sockets\winsock2\wsp\afdsys\afdstr.h
#define IS_VALID_AFD_BUFFER(b) (                                                                                                    \
    ((b)->Placement==AFD_PLACEMENT_HDR)                                                                                             \
        ? ((PUCHAR)b<(PUCHAR)(b)->Buffer && (PUCHAR)b<(PUCHAR)(b)->Mdl && (PUCHAR)b<(PUCHAR)(b)->Irp)                               \
        : (((b)->Placement==AFD_PLACEMENT_MDL)                                                                                      \
            ? ((PUCHAR)(b)->Mdl<(PUCHAR)(b)->Buffer && (PUCHAR)(b)->Mdl<(PUCHAR)b && (PUCHAR)(b)->Mdl<(PUCHAR)(b)->Irp)             \
            : ((b->Placement==AFD_PLACEMENT_IRP)                                                                                    \
                ? ((PUCHAR)(b)->Irp<(PUCHAR)(b)->Buffer && (PUCHAR)(b)->Irp<(PUCHAR)b && (PUCHAR)(b)->Irp<(PUCHAR)(b)->Mdl)         \
                : ((PUCHAR)(b)->Buffer<(PUCHAR)(b)->Irp && (PUCHAR)(b)->Buffer<(PUCHAR)b && (PUCHAR)(b)->Buffer<(PUCHAR)(b)->Mdl))  \
            )                                                                                                                       \
        )                                                                                                                           \

// net\tapi\inc\server.h
#define IS_REMOTE_CN_CLIENT(ptClient) \
            (ptClient->hProcess == (HANDLE) CN_CLIENT)
#define IS_REMOTE_DG_CLIENT(ptClient) \
            (ptClient->hProcess == (HANDLE) DG_CLIENT)
#define IS_REMOTE_MMC_CLIENT(ptClient) \
            (ptClient->hProcess == (HANDLE) MMC_CLIENT)

// net\tapi\litesabr\filters\amrtpdmx\template.h
#define CFT_AMRTPDMX_DMX_FILTER \
{ \
	  RTP_DEMUX_FILTER, \
      &CLSID_IntelRTPDemux, \
      CRTPDemux::CreateInstance, \
      NULL, \
      &g_RTPDemuxFilter \
	  }

// net\tapi\litesabr\filters\amrtpnet\globals.h
#define IS_CLASSD(i)            (((long)(i) & 0x000000f0) == 0x000000e0)

// net\tapi\litesabr\filters\amrtpnet\template.h
#define CFT_AMRTPNET_RTP_RENDER_FILTER \
{ \
	  RTP_RENDER_FILTER, \
	  &CLSID_RTPRenderFilter, \
	  CRtpRenderFilter::CreateInstance, \
	  NULL, \
	  &g_RtpRenderFilter \
	  }
#define CFT_AMRTPNET_RTP_SOURCE_FILTER \
{ \
	  RTP_SOURCE_FILTER, \
	  &CLSID_RTPSourceFilter, \
	  CRtpSourceFilter::CreateInstance, \
	  NULL, \
	  &g_RtpSourceFilter \
	  }

// net\tapi\litesabr\filters\amrtpss\template.h
#define CFT_AMRTPSS_SILENCE_SUPRESSOR \
{ \
	  AMRTP_SILENCE_SUPRESSOR, \
	  &CLSID_SilenceSuppressionFilter, \
	  CSilenceSuppressor::CreateInstance, \
	  NULL, \
	  &sudSilence \
	  }

// net\tapi\litesabr\filters\codecs\g711\template.h
#define CFT_G711_FILTER \
{ \
	  CODECG711LNAME, \
	  &CLSID_G711Codec, \
	  CG711Codec::CreateInstance, \
	  NULL, \
	  &sudG711Codec \
	  }

// net\tapi\litesabr\filters\inc\ph\isrg.h
#define kMaxModules			((UINT) (kModuleBufSize/sizeof(tISRModule)))
#define kMaxISRItems		((UINT) (kISRBufSize/sizeof(tISRItem)))

// net\tapi\litesabr\filters\mixer\template.h
#define CFT_MIXER_FILTER \
{ \
	  LMIXER_FILTER_NAME, \
	  &CLSID_AudioMixFilter, \
	  CMixer::CreateInstance, \
	  NULL, \
	  &sudMixer \
	  }

// net\tapi\litesabr\filters\ppm\core.h
#define REGISTER_CLASS( clsid, class_name, regCls ) \
        { &clsid, class_name::_CreateObject, regCls, NULL, 0, NULL, 0 },
#define END_CLASS_REGISTRY() \
        { &CLSID_NULL, NULL, REGCLS_SINGLEUSE, NULL, 0, NULL, 0 } \
    };

// net\tapi\litesabr\filters\rph\rphaud\template.h
#define CFT_RPHAUD_FILTER \
{ \
	  RPH_FOR_AUD, \
	  &CLSID_INTEL_RPHAUD, \
	  CRPHAUD::CreateInstance, \
	  NULL, \
	  &sudRPHAUD \
	  }

// net\tapi\litesabr\filters\rph\rphgena\template.h
#define CFT_RPH_GENA_FILTER \
{ \
	  RPH_FOR_GENA, \
	  &CLSID_INTEL_RPHGENA, \
	  CRPHGENA::CreateInstance, \
	  NULL, \
	  &sudRPHGENA \
	  }

// net\tapi\litesabr\filters\rph\rphgenv\template.h
#define CFT_RPHGENV_FILTER \
{ \
	  RPH_FOR_GENV, \
	  &CLSID_INTEL_RPHGENV, \
	  CRPHGENV::CreateInstance, \
	  NULL, \
	  &sudRPHGENV \
	  }

// net\tapi\litesabr\filters\rph\rphh26x\template.h
#define CFT_RPHH26X_FILTER \
{ \
	  RPH_FOR_H26X, \
	  &CLSID_INTEL_RPHH26X, \
	  CRPHH26X::CreateInstance, \
	  NULL, \
	  &sudRPHH26X \
	  }

// net\tapi\litesabr\filters\sph\sphaud\template.h
#define CFT_SPHAUD_FILTER \
{ \
	  L"Intel RTP SPH for G.711/G.723.1", \
	  &CLSID_INTEL_SPHAUD, \
	  CSPHAUD::CreateInstance, \
	  NULL, \
	  &sudSPHAUD \
	  }

// net\tapi\litesabr\filters\sph\sphgena\template.h
#define CFT_SPHGENA_FILTER \
{ \
	  L"Intel RTP SPH for Generic Audio", \
	  &CLSID_INTEL_SPHGENA, \
	  CSPHGENA::CreateInstance, \
	  NULL, \
	  &sudSPHGENA \
	  }

// net\tapi\litesabr\filters\sph\sphgenv\template.h
#define CFT_SPHGENV_FILTER \
{ \
	  L"Intel RTP SPH for Generic Video", \
	  &CLSID_INTEL_SPHGENV, \
	  CSPHGENV::CreateInstance, \
	  NULL, \
	  &sudSPHGENV \
	  }

// net\tapi\litesabr\filters\sph\sphh26x\template.h
#define CFT_SPHH26X_FILTER \
{ \
	  L"Intel RTP SPH for H.263/H.261", \
	  &CLSID_INTEL_SPHH26X, \
	  CSPHH26X::CreateInstance, \
	  NULL, \
	  &sudSPHH26X \
	  }

// net\tapi\perfdll\tapiperf.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// net\tapi\rtc\phoenix\src\sip\sipstack.cpp
#define IS_MULTICAST_ADDRESS(i) (((long)(i) & 0xf0000000) == 0xe0000000)
#define IS_LOOPBACK_ADDRESS(i) (((long)(i) & 0xff000000) == 0x7f000000)

// net\tapi\server\line.c
#define IS_LRESULT_NOTERROR( foo )                            \
            ( ! ( 0x80000000 & foo )  &&                                        \
            (  (foo <= LINEERR_LASTERRORVALUE)  ||                                     \
                (foo > 0x90000000 && foo <= PHONEERR_LASTERRORVALUE) ) )

// net\tapi\skywalker\apps\avdialer\avdialer\avlist.h
#define LOAD_COLUMN(_IDS_, _DEF_ )												\
strTemp.LoadString( _IDS_ );													\
if ( bSave )																	\
{																				\
	nColumnWidth[i] = GetColumnWidth(i);										\
	AfxGetApp()->WriteProfileInt( strSubKey, strTemp, nColumnWidth[i++] );		\
}																				\
else																			\
	nColumnWidth[i++] = max( MIN_COL_WIDTH, AfxGetApp()->GetProfileInt( strSubKey, strTemp, _DEF_ ) );\

// net\tapi\skywalker\apps\avdialer\avdialer\dialreg.cpp
#define MAXKEY	(256 * sizeof(TCHAR))

// net\tapi\skywalker\apps\avdialer\avlib\mem.c
#define SIZE_T_MAX (~((size_t) 0))

// net\tapi\skywalker\apps\avdialer\avlib\sort.c
#define ElemCompare(lpi, lpj) \
	(compare == NULL ? MemCmp(lpi, lpj, width) : compare(lpi, lpj))

// net\tapi\skywalker\apps\avdialer\avlib\sys.h
#define SysGetTaskInstance(hTask) \
	(hTask == NULL ? GetModuleHandle(NULL) : NULL)

// net\tapi\skywalker\apps\avdialer\avtapi\avtapi.cpp
#define IF_ADD_ACTION(_LC_, _CMA_)                                \
    if ( (lCaps & (_LC_)) != 0 )                                \
        fire_AddCurrentAction( lCallID, (_CMA_), NULL );

// net\tapi\skywalker\cc\inc\core.h
#define REGISTER_CLASS( clsid, class_name, regCls ) \
        { &clsid, class_name::_CreateObject, regCls, NULL, 0, NULL, 0 },
#define END_CLASS_REGISTRY() \
        { &CLSID_NULL, NULL, REGCLS_SINGLEUSE, NULL, 0, NULL, 0 } \
    };

// net\tapi\skywalker\cc\inc\isrg.h
#define kMaxModules			((UINT) (kModuleBufSize/sizeof(tISRModule)))
#define kMaxISRItems		((UINT) (kISRBufSize/sizeof(tISRItem)))

// net\tapi\skywalker\cc\inc\isrg_org.h
#define kMaxModules			((UINT) (kModuleBufSize/sizeof(tISRModule)))
#define kMaxISRItems		((UINT) (kISRBufSize/sizeof(tISRItem)))

// net\tapi\skywalker\confmsp\confaddr.cpp
#define IsValidInterface(_dwAddr_) \
    (((_dwAddr_) != 0) && \
     ((_dwAddr_) != htonl(INADDR_LOOPBACK)))

// net\tapi\skywalker\filters\inc\rtphdr.h
#define RTP_PLUS_RED_HDR_SIZE (sizeof(RtpHdr_t) + \
                               sizeof(RtpRedHdr_t) * (RTP_RED_MAXRED+1))

// net\tapi\skywalker\filters\rtp\inc\gtypes.h
#define IS_MULTICAST(addr) (((long)(addr) & 0x000000f0) == 0x000000e0)
#define IS_UNICAST(addr)   (((long)(addr) & 0x000000f0) != 0x000000e0)

// net\tapi\skywalker\filters\rtp\inc\rtptags.h
#define INVALIDATE_OBJECTID(oi) (oi &= ~0xff)

// net\tapi\skywalker\filters\rtp\tools\inc\common.h
#define IS_MULTICAST(addr) (((long)(addr) & 0x000000f0) == 0x000000e0)
#define IS_UNICAST(addr)   (((long)(addr) & 0x000000f0) != 0x000000e0)

// net\tapi\skywalker\h323\inc\h4503pp.h
#define SIZE_H4503PP_Module_PDU_11 sizeof(CheckRestrictionArgument)

// net\tapi\skywalker\h323\tsp\call.h
#define IsValidDTMFDigit(wDigit)   (                                            \
                                    ((wDigit >= L'0') && (wDigit <= L'9')) ||   \
                                    ((wDigit >= L'A') && (wDigit <= L'D')) ||   \
                                    (wDigit == L'*') ||                         \
                                    (wDigit == L'#') ||                         \
                                    (wDigit == L'!') ||                         \
                                    (wDigit == L',')                            \
                                   )
#define H323_CALL_INBOUNDSTATES        (LINECALLSTATE_ACCEPTED      | \
                                        LINECALLSTATE_CONNECTED     | \
                                        LINECALLSTATE_DISCONNECTED  | \
                                        LINECALLSTATE_IDLE          | \
                                        LINECALLSTATE_OFFERING      | \
                                        LINECALLSTATE_RINGBACK      | \
                                        LINECALLSTATE_ONHOLD )
#define H323_CALL_OUTBOUNDSTATES       (LINECALLSTATE_CONNECTED     | \
                                        LINECALLSTATE_DIALING       | \
                                        LINECALLSTATE_DISCONNECTED  | \
                                        LINECALLSTATE_IDLE          | \
                                        LINECALLSTATE_RINGBACK      | \
                                        LINECALLSTATE_ONHOLD )

// net\tapi\skywalker\h323\tsp\line.h
#define H323_ADDR_CALLSTATES       (H323_CALL_INBOUNDSTATES | \
                                    H323_CALL_OUTBOUNDSTATES)

// net\tapi\skywalker\h323tsp\call.h
#define H323_CALL_INBOUNDSTATES        (LINECALLSTATE_ACCEPTED | \
                                        LINECALLSTATE_CONNECTED | \
                                        LINECALLSTATE_DISCONNECTED | \
                                        LINECALLSTATE_IDLE | \
                                        LINECALLSTATE_OFFERING)
#define H323_CALL_OUTBOUNDSTATES       (LINECALLSTATE_CONNECTED | \
                                        LINECALLSTATE_DIALING | \
                                        LINECALLSTATE_DISCONNECTED | \
                                        LINECALLSTATE_IDLE | \
                                        LINECALLSTATE_RINGBACK)
#define H323IsCallInbound(_pCall_) \
    ((_pCall_)->dwOrigin == LINECALLORIGIN_INBOUND)

// net\tapi\skywalker\h323tsp\callback.h
#define H323_MSG_TERMINATION    (WM_USER+15)
#define H323IsTerminationMessage(_msg_) \
    ((_msg_)->message == H323_MSG_TERMINATION)
#define H323IsValidU2U(_pNS_) \
    (((_pNS_)->bCountryCode      == H221_COUNTRY_CODE_USA) && \
     ((_pNS_)->bExtension        == H221_COUNTRY_EXT_USA) && \
     ((_pNS_)->wManufacturerCode == H221_MFG_CODE_MICROSOFT))

// net\tapi\skywalker\h323tsp\channel.h
#define H323IsChannelInbound(_pChannel_) \
    ((_pChannel_)->fInbound == TRUE)

// net\tapi\skywalker\h323tsp\line.h
#define H323_ADDR_CALLSTATES       (H323_CALL_INBOUNDSTATES | \
                                    H323_CALL_OUTBOUNDSTATES)
#define H323IsLineAvailable(_pLine_) \
    ((_pLine_)->pCallTable->dwNumInUse < H323_MAXCALLSPERLINE)
#define H323IsValidInterface(_dwAddr_) \
    (((_dwAddr_) != 0) && \
     ((_dwAddr_) != htonl(INADDR_LOOPBACK)))

// net\tapi\skywalker\h323tsp\termcaps.h
#define H323IsValidDataType(_type_) \
    (((_type_) == H245_DATA_VIDEO) || \
     ((_type_) == H245_DATA_AUDIO))
#define H323IsValidAudioClientType(_type_) \
    (((_type_) == H245_CLIENT_AUD_G711_ULAW64) || \
     ((_type_) == H245_CLIENT_AUD_G711_ALAW64) || \
     ((_type_) == H245_CLIENT_AUD_G723))
#define H323IsValidVideoClientType(_type_) \
    (((_type_) == H245_CLIENT_VID_H261) || \
     ((_type_) == H245_CLIENT_VID_H263))
#define H323IsValidClientType(_type_) \
    (H323IsValidAudioClientType(_type_) || \
     H323IsValidVideoClientType(_type_))

// net\tapi\skywalker\ipconf\msp\confaddr.cpp
#define IsValidInterface(_dwAddr_) \
    (((_dwAddr_) != 0) && \
     ((_dwAddr_) != htonl(INADDR_LOOPBACK)))

// net\tapi\skywalker\rend\rndcommc.h
#define ValidMeetingAttribute(a) \
    (((a) > MEETING_ATTRIBUTES_BEGIN) && ((a) < MEETING_ATTRIBUTES_END))
#define ValidUserAttribute(a) \
    (((a) > USER_ATTRIBUTES_BEGIN) && ((a) < USER_ATTRIBUTES_END))

// net\tapi\skywalker\tapi3\address.h
#define ALL_LINEADDRESSSTATE_MESSAGES   (LINEADDRESSSTATE_OTHER         | \
                                        LINEADDRESSSTATE_DEVSPECIFIC    | \
                                        LINEADDRESSSTATE_INUSEZERO      | \
                                        LINEADDRESSSTATE_INUSEONE       | \
                                        LINEADDRESSSTATE_INUSEMANY      | \
                                        LINEADDRESSSTATE_NUMCALLS       | \
                                        LINEADDRESSSTATE_FORWARD        | \
                                        LINEADDRESSSTATE_TERMINALS      | \
                                        LINEADDRESSSTATE_CAPSCHANGE)

// net\tapi\thunk\windows.h
#define AW_VALID                    (AW_HOR_POSITIVE |\
                                     AW_HOR_NEGATIVE |\
                                     AW_VER_POSITIVE |\
                                     AW_VER_NEGATIVE |\
                                     AW_CENTER       |\
                                     AW_HIDE         |\
                                     AW_ACTIVATE     |\
                                     AW_SLIDE        |\
                                     AW_BLEND)              // ;Internal
#define TME_VALID (TME_HOVER | TME_LEAVE | TME_NONCLIENT | TME_QUERY | TME_CANCEL) // ;Internal
#define SBM_SETRANGE        (WM_USER+2)                     // ;Internal
#define SBM_GETRANGE        (WM_USER+3)                     // ;Internal
#define SBM_SETRANGEREDRAW  (WM_USER+6)                     // ;Internal 4.0
#define SBM_MSGMAX          (WM_USER+11)                    // ;Internal 4.0
#define STM_MSGMAX         (WM_USER+4)      // ;Internal 4.0
#define BM_GETCHECK         (WM_USER+0)
#define BM_SETCHECK         (WM_USER+1)
#define BM_MSGMAX           (WM_USER+8)     // ;Internal 4.0
#define EM_MSGMAX               (WM_USER+42)    // ;Internal 4.0
#define LB_SELITEMRANGEEX       (WM_USER+4)     // ;Internal 4.0 NT
#define LB_SELITEMRANGE         (WM_USER+28)
#define LB_MSGMAX               (WM_USER+47)    // ;Internal
#define CB_MSGMAX               (WM_USER+34)    // ;Internal 4.0

// net\tcpip\apis\iphlpapi\lib\ipconfig.c
#define IN_IS_ADDR_LINKLOCAL(x) ((*(x) & 0x0000ffff) == 0x0000fea9)

// net\tcpip\commands\ping\ping.c
#define MAX_BUFFER_SIZE       (sizeof(ICMP_ECHO_REPLY) + 0xfff7 + MAX_OPT_SIZE)

// net\tcpip\driver\ipv4\arp.c
#define BUFSIZE_AUX_HEADER_POOL ARP_MAX_MEDIA_TR + (2 * sizeof(ARPHeader))

// net\tcpip\driver\ipv4\arpdef.h
#define ARP_MAX_MEDIA_ENET  sizeof(ENetHeader)
#define ARP_MAX_MEDIA_TR    (sizeof(TRHeader)+sizeof(RC)+(ARP_MAX_RD*sizeof(ushort))+sizeof(SNAPHeader))
#define ARP_MAX_MEDIA_FDDI  (sizeof(FDDIHeader)+sizeof(SNAPHeader))
#define ARP_MAX_MEDIA_ARC   sizeof(ARCNetHeader)

// net\tcpip\driver\ipv4\icmp.c
#define BUFSIZE_ICMP_HEADER_POOL    sizeof(IPHeader) + sizeof(ICMPHeader) + \
                                    sizeof(IPHeader) +  MAX_OPT_SIZE + 8

// net\tcpip\driver\ipv4\igmp.c
#define IS_SOURCE_ALLOWED(Grp, Src) \
     (((Src)->isa_xrefcnt != (Grp)->iga_grefcnt) || ((Src)->isa_irefcnt != 0))
#define IS_GROUP_ALLOWED(Grp) \
    (((Grp)->iga_grefcnt != 0) || ((Grp)->iga_srclist != NULL))
#define IS_SOURCE_DELETABLE(Src) \
    (((Src)->isa_irefcnt == 0) && ((Src)->isa_xrefcnt == 0) \
     && ((Src)->isa_xmitleft==0) && ((Src)->isa_csmarked == 0))

// net\tcpip\driver\ipv4\ipdef.h
#define MAX_HDR_SIZE            (sizeof(IPHeader) + MAX_OPT_SIZE)

// net\tcpip\driver\ipv4\strie.h
#define  NewDestInSTrie(_pSTrie_, _pRoute_, _pDest_)                            \
                                {                                               \
                                    AllocMemory1(_pDest_,                       \
                                                 (sizeof(Dest) - sizeof(Route *)\
                                                  + MaxEqualCostRoutes *        \
                                                     sizeof(Route *)),          \
                                                 (_pSTrie_)->availMemory);      \
                                                                                \
                                    _pDest_->maxBestRoutes = MaxEqualCostRoutes;\
                                    _pDest_->numBestRoutes = 0;                 \
                                                                                \
                                    _pDest_->firstRoute = _pRoute_;             \
                                                                                \
                                    (_pSTrie_)->numDests++;                     \
                                }

// net\tcpip\driver\kdext2\inc\tcpdump.h
#define Print_NDIS_STRING(_p, _f)       \
    PrintFieldName(#_f);                \
    DumpNDIS_STRING(&_p->_f)

// net\tcpip\driver\tcp\addr.h
#define IS_PROMIS_AO(A)           ((A)->ao_rcvall || (A)->ao_rcvall_mcast || (A)->ao_absorb_rtralert)

// net\tcpip\driver\tcp\tcpconn.h
#define CONN_INVALID    (CONN_CLOSING | CONN_DISACC)

// net\tcpip\services\lpd\lpd.h
#define  IS_WHITE_SPACE( ch )   ( (ch == ' ') || (ch == '\t') || (ch == '\r') )

// net\tcpip\services\telnet\admin\tnadminl.c
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

// net\tcpip\services\telnet\client\wintel.h
#define IS_ANY_DBCS_CHARSET( CharSet ) ( ((CharSet) == SHIFTJIS_CHARSET)    ? TRUE :    \
                                         ((CharSet) == HANGEUL_CHARSET)     ? TRUE :    \
                                         ((CharSet) == CHINESEBIG5_CHARSET) ? TRUE :    \
                                         ((CharSet) == GB2312_CHARSET)      ? TRUE : FALSE )

// net\tcpip\services\tftp\tftp_lib.c
#define IS_SEPARATOR(c) (((c) == '\\') || ((c) == '/'))

// net\tcpip\tools\checkv4\recurse.c
#define FA_ALL      (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN | \
                     FILE_ATTRIBUTE_SYSTEM)

// net\tcpip\tpipv6\dplayip6\dpsp.h
#define VALID_DPWS_MESSAGE(pMsg) (  VALID_SP_MESSAGE(pMsg) || VALID_HELPER_MESSAGE(pMsg) || \
                                                                        VALID_SERVER_MESSAGE(pMsg) || VALID_REUSE_MESSAGE(pMsg) )
#define VALID_DPLAYSVR_MESSAGE(pMsg) (  VALID_SP_MESSAGE(pMsg) || VALID_SERVER_MESSAGE(pMsg) || \
                                                                                VALID_REUSE_MESSAGE(pMsg) )
#define VERSIONNUMBER           (DPSP_MAJORVERSION | SPMINORVERSION) // version number for service provider

// net\tcpip\tpipv6\ping6\ping6.c
#define MAX_BUFFER_SIZE         (sizeof(ICMPV6_ECHO_REPLY) + 0xfff7)

// net\tcpip\tpipv6\tcpip6\inc\tcp.h
#define DEFAULT_MSS (IPv6_MINIMUM_MTU - sizeof(IPv6Header) - sizeof(TCPHeader))

// net\tcpip\tpipv6\tcpip6\inc\tcpconn.h
#define CONN_INVALID (CONN_CLOSING | CONN_DISACC)

// net\tcpip\tpipv6\tcpip6\ip6\lan.h
#define MAX_MEDIA_ETHER sizeof(EtherHeader)
#define MAX_MEDIA_TR (sizeof(TRHeader)+sizeof(RC)+(MAX_RD*sizeof(ushort))+sizeof(SNAPHeader))
#define MAX_MEDIA_FDDI (sizeof(FDDIHeader)+sizeof(SNAPHeader))

// net\tcpip\tpipv6\tcpip6\ip6\tunnel.h
#define TUNNEL_MAX_MTU          (64 * 1024 - sizeof(IPHeader) - 1)

// net\tcpip\tpipv6\wship6\wship6.c
#define IS_DGRAM_SOCK(type)  (((type) == SOCK_DGRAM) || ((type) == SOCK_RAW))

// net\tcpip\winsock\wshtcpip.c
#define IS_DGRAM_SOCK(type)  (((type) == SOCK_DGRAM) || ((type) == SOCK_RAW))
#define MAX_FAST_ENTITY_BUFFER ( sizeof(TDIEntityID) * 10 )

// net\unimodem\common\rovdi.c
#define CB_MAX_REG_KEY_LEN      (MAX_REG_KEY_LEN * sizeof(TCHAR))

// net\unimodem\src\atmini\util.c
#define CB_MAX_REG_KEY_LEN      (MAX_REG_KEY_LEN * sizeof(TCHAR))
#define CbFromCchW(cch)             ((cch)*sizeof(WCHAR))
#define CbFromCchA(cch)             ((cch)*sizeof(CHAR))

// net\unimodem\src\mdminst\detect.c
#define ishex(ch)   ((ToUpper(ch) >= 'A' && ToUpper(ch) <= 'F') ? TRUE : FALSE)
#define isnum(num)  ((num >= '0' && num <= '9') ? TRUE : FALSE)

// net\unimodem\src\mdminst\modem.h
#define mDF_CLEAR_DEVICE_CHANGE ~(fDF_DEVICE_ADDED | fDF_DEVICE_REMOVED)
#define DEVICE_ADDED(_flg) (_flg&fDF_DEVICE_ADDED)
#define DEVICE_REMOVED(_flg) (_flg&fDF_DEVICE_REMOVED)
#define DEVICE_CHANGED(_flg) (_flg&(fDF_DEVICE_REMOVED|fDF_DEVICE_ADDED))
#define CplInitClassInstallHeader(p, dif)    \
                    ((p)->cbSize = sizeof(SP_CLASSINSTALL_HEADER), \
                     (p)->InstallFunction = (dif))

// net\unimodem\src\tsp\umrtl.cpp
#define VALIDATED_PBLOB(_pblob) \
        (((_pblob) && (((PROPERTYBLOB*)(_pblob))->dwSig == dwPROPERTYBLOBSIG)) \
         ? (PROPERTYBLOB*)(_pblob) \
         : NULL)

// net\upnp\host\upnphost\inc\svsutil.hxx
#define SVSUTIL_HANDLE_TONUM(h) ((h) & SVSUTIL_HANDLE_MAXNUM)

// net\winnet\mprdata.h
#define MPR_IS_INITIALIZED(level)       (GlobalInitLevel & level ## _LEVEL)

// net\winnet\tstring.h
#define IS_PATH_SEPARATOR(ch) ((ch == TCHAR_BACKSLASH) || (ch == TCHAR_FWDSLASH))
#define IS_NON_ZERO_DIGIT(c)    (((c) >= MAKE_TCHAR('1')) && ((c) <= MAKE_TCHAR('9')))

// net\wins\perfctrs\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// net\wins\server\inc\comm.h
#define  COMM_IS_PNR_BETA1_WINS_M(pDlgHdl, fBeta1)	{	  	  \
	PCOMMASSOC_DLG_CTX_T	_pEnt = (pDlgHdl)->pEnt;                  \
        PCOMMASSOC_ASSOC_CTX_T  _pAssocEnt = _pEnt->AssocHdl.pEnt;       \
        fBeta1 = (_pAssocEnt->MajVersNo == WINS_BETA1_MAJOR_VERS_NO) ? TRUE : \
          FALSE;                                                            \
					}
#define  COMM_GET_WINS_VERS_NO_M(pDlgHdl, MajVers, MinVers)	{	  	  \
	PCOMMASSOC_DLG_CTX_T	_pEnt = (pDlgHdl)->pEnt;                  \
        PCOMMASSOC_ASSOC_CTX_T  _pAssocEnt = _pEnt->AssocHdl.pEnt;       \
        MajVers = _pAssocEnt->MajVersNo; \
        MinVers = _pAssocEnt->MinVersNo; \
					}
#define  COMM_IS_IT_LOCAL_M(pDlgHdl)  \
        (((PCOMMASSOC_DLG_CTX_T)(pDlgHdl->pEnt))->FromAdd.sin_family == NBT_UNIX)

// net\wins\server\inc\nmsdb.h
#define NMSDB_STORE_NAME_M(pTls, pRec, pLclName, NameLen)                \
        {                                                                \
                pRec->pName = WinsMscHeapAlloc(pTls->HeapHdl, NameLen < WINS_MAX_NS_NETBIOS_NAME_LEN ? WINS_MAX_NS_NETBIOS_NAME_LEN : NameLen);\
                WINSMSC_MOVE_MEMORY_M(pRec->pName, pLclName, NameLen); \
        }

// net\wlbs\driver\params.c
#define PARAMS_INFO_BUF_SIZE    ((CVY_MAX_PARAM_STR + 1) * sizeof (WCHAR) + \
                                  CVY_MAX_RULES * sizeof (CVY_RULE) + \
                                  sizeof (KEY_VALUE_PARTIAL_INFORMATION) + 4)

// printscan\fax\admin\faxclient\cfg\faxcfg.h
#define AllocStringZ(cch)   MemAllocZ(sizeof(TCHAR) * (cch))
#define AllocStringZ(cch)   MemAllocZ(sizeof(TCHAR) * (cch))
#define SizeOfString(p)     ((_tcslen(p) + 1) * sizeof(TCHAR))

// printscan\fax\admin\faxclient\cfg\userinfo.c
#define  IsPrinterFaxPrinter(__PrinterInfo) \
        ((lstrcmp(__PrinterInfo.pDriverName,FAX_DRIVER_NAME) == 0) ? TRUE : FALSE )

// printscan\fax\admin\routeext\route.h
#define MAPIENABLED (m_MapiProfiles && *m_MapiProfiles)

// printscan\fax\config\dll\faxcpl.h
#define ValidConfigData(pData) \
        ((pData) && (pData) == (pData)->startSign && (pData) == (pData)->endSign)

// printscan\fax\inc\faxutil.h
#define IsSmallBiz()        (ValidateProductSuite( VER_SUITE_SMALLBUSINESS | VER_SUITE_SMALLBUSINESS_RESTRICTED))
#define IsProductSuite()    (ValidateProductSuite( VER_SUITE_SMALLBUSINESS | VER_SUITE_SMALLBUSINESS_RESTRICTED | VER_SUITE_COMMUNICATIONS ))

// printscan\fax\perfmon\faxperf.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// printscan\fax\print\faxmon\faxmon.h
#define ValidFaxPort(pFaxPort) \
        ((pFaxPort) && (pFaxPort) == (pFaxPort)->startSig && (pFaxPort) == (pFaxPort)->endSig)

// printscan\fax\print\faxprint\faxdrv\faxdrv.h
#define ValidDevData(pdev)  \
        ((pdev) && (pdev)->startDevData == (pdev) && (pdev)->endDevData == (pdev))

// printscan\fax\print\faxprint\faxui\faxui.h
#define ValidUiData(p) ((p) && (p) == (p)->startSign && (p) == (p)->endSign)
#define ValidPDEVUserMem(p) \
        ((p) && (p) == (p)->signature && (p) == (p)->devmode.dmPrivate.pUserMem)

// printscan\fax\provider\t30\comm\fcomint.h
#define FComGetError(pTG)                                                                                                          \
        { GetCommErrorNT ( pTG, (HANDLE) pTG->Comm.nCid, &pTG->Comm.CommErr, &(pTG->Comm.comstat));                    \
          if(pTG->Comm.CommErr) D_GotError(pTG, pTG->Comm.nCid, pTG->Comm.CommErr, &(pTG->Comm.comstat));\
                iModemSetError(pTG, MODEMERR_COMPORT, 0, 0); }
#       define MySleep(x)                                                                                                       \
                {BG_CHK(x);                                                                                                             \
                { BEFORESLEEP; Sleep(pTG->Comm.bDontYield?0:(x)); AFTERSLEEP(x); }}

// printscan\fax\provider\t30\headers\awnsfint.h
#define PutTextId(lpbc, uMax, lpbIn, uLen, enc)                                                          \
        if(uLen) { AppendToBCLen(lpbc, uMax, lpbIn, uLen, wszTextId, wTextIdLen);\
                (lpbc)->wTextEncoding = (enc); }
#define CopyBC(lpbcOut, wMaxOut, lpbcIn)                \
        ( (wMaxOut < lpbcIn->wTotalSize) ? FALSE :      \
                        (_fmemcpy(lpbcOut, lpbcIn, lpbcIn->wTotalSize), TRUE) )

// printscan\fax\provider\t30\headers\lmi.h
#define MAXFORMATSIZE   (sizeof(LMIFORMAT))
#define MAXRECIPIENTSIZE    (sizeof(LMIRECIPIENT) + MAX_ADDRESS_LENGTH)

// printscan\fax\provider\t30\headers\pollenc.h
#define ArulsPollPassToChallResp(lpbCh, wCh, lpbPas, wPas, lpbOut, wMaxOut)	\
	((!(lpbCh) || !(lpbPas) || !(lpbOut) || !(wCh) || !(wPas) || (wMaxOut)<(wCh)) ? \
		(BG_CHK(FALSE), 0) : 										 	\
		PollEnc((lpbCh), (wCh), (lpbPas), (wPas), (lpbOut), (wMaxOut)))

// printscan\fax\provider\t30\headers\rgndlg.h
#define MAKE_RGNDLG_VALID(f) ((f) & (RGNDLG_NOAUTOSIZE | RGNDLG_NOMOVE))

// printscan\faxsrv\src\inc\faxreg.h
#define FAX_ADDERSS_VALID_CHARACTERS                    TEXT("0123456789 -|^!#$*,?@ABCbcdDPTWdptw")

// printscan\faxsrv\src\inc\faxutil.h
#define IsSmallBiz()        (ValidateProductSuite( VER_SUITE_SMALLBUSINESS | VER_SUITE_SMALLBUSINESS_RESTRICTED))
#define IsProductSuite()    (ValidateProductSuite( VER_SUITE_SMALLBUSINESS | VER_SUITE_SMALLBUSINESS_RESTRICTED | VER_SUITE_COMMUNICATIONS ))

// printscan\faxsrv\src\perfmon\faxperf.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// printscan\faxsrv\src\print\faxmon\faxmon.h
#define ValidFaxPort(pFaxPort) \
        ((pFaxPort) && (pFaxPort) == (pFaxPort)->startSig && (pFaxPort) == (pFaxPort)->endSig)

// printscan\faxsrv\src\print\faxprint\faxdrv\faxdrv.h
#define ValidDevData(pdev)  \
        ((pdev) && (pdev)->startDevData == (pdev) && (pdev)->endDevData == (pdev))

// printscan\faxsrv\src\print\faxprint\faxui\faxui.h
#define ValidUiData(p) ((p) && (p) == (p)->startSign && (p) == (p)->endSign)
#define ValidPDEVUserMem(p) \
        ((p) && (p) == (p)->signature)

// printscan\faxsrv\src\print\faxprint\prnwzrd\faxui.h
#define ValidPDEVWizardUserMem(p) \
        ((p) && (p) == (p)->signature)

// printscan\faxsrv\src\provider\t30\comm\fcomint.h
#define FComGetError(pTG)                                                                                                          \
        { GetCommErrorNT ( pTG, (HANDLE) pTG->Comm.nCid, &pTG->Comm.CommErr, &(pTG->Comm.comstat));                    \
          if(pTG->Comm.CommErr) D_GotError(pTG, pTG->Comm.nCid, pTG->Comm.CommErr, &(pTG->Comm.comstat));\
                iModemSetError(pTG, MODEMERR_COMPORT, 0, 0); }
#       define MySleep(x)                                                                                                       \
                {BG_CHK(x);                                                                                                             \
                { BEFORESLEEP; Sleep(pTG->Comm.bDontYield?0:(x)); AFTERSLEEP(x); }}

// printscan\faxsrv\src\provider\t30\headers\awnsfint.h
#define PutTextId(lpbc, uMax, lpbIn, uLen, enc)                                                          \
        if(uLen) { AppendToBCLen(lpbc, uMax, lpbIn, uLen, wszTextId, wTextIdLen);\
                (lpbc)->wTextEncoding = (enc); }
#define CopyBC(lpbcOut, wMaxOut, lpbcIn)                \
        ( (wMaxOut < lpbcIn->wTotalSize) ? FALSE :      \
                        (_fmemcpy(lpbcOut, lpbcIn, lpbcIn->wTotalSize), TRUE) )

// printscan\faxsrv\src\sdktools\msvc15\include\penwin.h
#define ALC_SYSMINIMUM (ALC_ALPHANUMERIC | ALC_PUNC | ALC_WHITE | ALC_GESTURE)

// printscan\faxsrv\src\sdktools\msvc15\include\windows.h
#define BM_GETCHECK	    (WM_USER+0)
#define BM_SETCHECK	    (WM_USER+1)
#define LB_SELITEMRANGE        (WM_USER+28)

// printscan\faxsrv\src\sdktools\msvc15\include\winsock.h
#define INVALID_SOCKET  (SOCKET)(~0)

// printscan\faxsrv\src\test\src\xxxunusedxxx\deviceioctls\fileioctl.h
#define FSCTL_SIS_LINK_FILES            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 65, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)

// printscan\inc\psutil\simstr.h
#define IS_CHAR(x)     (sizeof(x)==sizeof(char))
#define IS_WCHAR(x)    (sizeof(x)==sizeof(wchar_t))

// printscan\print\drivers\usermode\ddk\samples\oemdll\nt4\inc\minidrv.h
#define IS_DBCSCHARSET(j) \
    (((j) == SHIFTJIS_CHARSET)    || \
    ((j) == HANGEUL_CHARSET)     || \
    ((j) == JOHAB_CHARSET)       || \
    ((j) == GB2312_CHARSET)      || \
    ((j) == CHINESEBIG5_CHARSET))

// printscan\print\drivers\usermode\driverui\driverui.h
#define LOAD_STRING_OPTION_NAME(pci, pOption, pwch, maxsize) \
        BLoadDisplayNameString(pci, ((POPTION) (pOption))->loDisplayName, pwch, maxsize)
#define VALIDUIDATA(pUiData)    ((pUiData) && \
                                 (pUiData) == (pUiData)->ci.pvStartSign && \
                                 (pUiData) == (pUiData)->pvEndSign)

// printscan\print\drivers\usermode\glyphset\mkgly\mkgly.c
#define IS_COMMENT(c) \
    ((c) == ';' || (c) == '#' || (c) == '%' || (c) == '\n')
#define IS_EUDC_W(wc) \
    ((wc) >= 0xe000 && (wc) <= 0xf8ff)

// printscan\print\drivers\usermode\glyphset\mkgtt\mkgtt.c
#define IS_COMMENT(c) \
    ((c) == ';' || (c) == '#' || (c) == '%' || (c) == '\n')
#define IS_EUDC_W(wc) \
    ((wc) >= 0xe000 && (wc) <= 0xf8ff)

// printscan\print\drivers\usermode\gpdres\alpsres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )
#define MINIDEV_DATA(p) \
    (((MINIDEV *)(p)->pdevOEM)->pData)
#define MINIDEV_INTF(p) \
    (((MINIDEV *)(p)->pdevOEM)->pIntf)

// printscan\print\drivers\usermode\gpdres\apdlres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )
#define ISVERTICALFONT(n) \
    ( (n == MINCHO_VERT || n == GOTHIC_VERT) ? TRUE : FALSE )

// printscan\print\drivers\usermode\gpdres\capplres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\casn4res\casn4res.c
#define IsValidDLFontID(x) \
    ((x) >= FONT_MIN_ID && (x) <= FONT_MAX_ID)

// printscan\print\drivers\usermode\gpdres\casn4res\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\citohres\oemud.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\cnl4jres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\cnrstres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\csn46res\colmatch.c
#define MAX_DIZNUM (sizeof DizNumTbl / sizeof DizNumTbl[0])

// printscan\print\drivers\usermode\gpdres\csn46res\csn46res.c
#define IsValidDLFontID(x) \
    ((x) >= FONT_MIN_ID && (x) <= FONT_MAX_ID)

// printscan\print\drivers\usermode\gpdres\csn46res\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\csn5res\csn5res.c
#define IsValidDLFontID(x) \
    ((x) >= FONT_MIN_ID && (x) <= FONT_MAX_ID)

// printscan\print\drivers\usermode\gpdres\csn5res\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\cswinres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\dclsres\oemud.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\epagcres\epagcres.c
#define SYMBOLSET_LEN (sizeof(DLI_SYMBOLSET) - 1)    // adjust for terminating NULL

// printscan\print\drivers\usermode\gpdres\epagcres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs && \
         (pdevobj)->pdevOEM )

// printscan\print\drivers\usermode\gpdres\fmlbpres\fmlbp.h
#define	IS_VALID_FUFMPDEV(p) \
	((p) != NULL && (p)->dwSignature == FUFM_OEM_SIGNATURE)

// printscan\print\drivers\usermode\gpdres\fuprjres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )
#define MINIDEV_DATA(p) \
    (((MINIDEV *)(p)->pdevOEM)->pData)
#define MINIDEV_INTF(p) \
    (((MINIDEV *)(p)->pdevOEM)->pIntf)

// printscan\print\drivers\usermode\gpdres\fuxlres\fuxl.h
#define	IS_VALID_FUXLPDEV(p) \
	((p) != NULL && (p)->dwSignature == FUXL_OEM_SIGNATURE)

// printscan\print\drivers\usermode\gpdres\fxartres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\fxmejres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\ib87wres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\kpdlres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )
#define MINIDEV_DATA(p) \
    ((p)->pdevOEM)

// printscan\print\drivers\usermode\gpdres\kyp5jres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\lggdires\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\lggs6res\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\nc62jres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\nc82jres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\ncb2jres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\ncdljres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\ncmwjres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\nt4lib\minidrv.h
#define IS_DBCSCHARSET(j) \
    (((j) == SHIFTJIS_CHARSET)    || \
    ((j) == HANGEUL_CHARSET)     || \
    ((j) == JOHAB_CHARSET)       || \
    ((j) == GB2312_CHARSET)      || \
    ((j) == CHINESEBIG5_CHARSET))

// printscan\print\drivers\usermode\gpdres\riafres\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\rpdlres\nt4\pdev.h
#define MINIDEV_DATA(p) \
    ((POEMPDEV)((p)->pdevOEM))          // device data during job
#define MINIPRIVATE_DM(p) \
    ((POEMUD_EXTRADATA)((p)->pOEMDM))   // private devmode
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\gpdres\rpdlres\pdev.h
#define MINIDEV_DATA(p) \
    ((POEMPDEV)((p)->pdevOEM))          // device data during job
#define MINIPRIVATE_DM(p) \
    ((POEMUD_EXTRADATA)((p)->pOEMDM))   // private devmode
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\inc\afm2ntm.h
#define IS_WHTSPACE(a) \
    (*(a) <= ' ')
#define IS_ALPHA(a) \
    ((*a > 'A' && *a < 'Z') || (*a > 'a' && *a < 'z'))
#define IS_NUM(a) \
    (*(a) >= '0' && *(a) <= '9')
#define IS_HEX_ALPHA(a) \
    ((*(a) >= 'a' && *(a) <= 'f') || (*(a) >= 'A' && *(a) <= 'F'))
#define IS_HEX_DIGIT(a) \
    (IS_NUM(a) || IS_HEX_ALPHA(a))
#define IS_CHAR_DEFINED(gi, cdeftbl) \
    (cdeftbl[CHR_DEF_INDEX(gi)] & CHR_DEF(gi))

// printscan\print\drivers\usermode\inc\lib.h
#define IS_DBCSCHARSET(j) \
    (((j) == SHIFTJIS_CHARSET)    || \
     ((j) == HANGEUL_CHARSET)     || \
     ((j) == JOHAB_CHARSET)       || \
     ((j) == GB2312_CHARSET)      || \
     ((j) == CHINESEBIG5_CHARSET))

// printscan\print\drivers\usermode\inc\ppd.h
#define MINCUSTOMPARAM(pPpdData, csindex) \
        ((pPpdData)->CustomSizeParams[csindex].lMinVal)
#define MAXCUSTOMPARAM(pPpdData, csindex) \
        ((pPpdData)->CustomSizeParams[csindex].lMaxVal)
#define SKIP_LEADINGEDGE_CHECK(pUIInfo, pPpdData) \
        ((GET_PREDEFINED_FEATURE((pUIInfo), GID_LEADINGEDGE) == NULL) || \
         ((pPpdData)->dwLeadingEdgeLong == OPTION_INDEX_ANY && \
          (pPpdData)->dwLeadingEdgeShort == OPTION_INDEX_ANY))
#define LONGEDGEFIRST_SUPPORTED(pUIInfo, pPpdData) \
        (SKIP_LEADINGEDGE_CHECK(pUIInfo, pPpdData) || \
        ((pPpdData)->dwLeadingEdgeLong != OPTION_INDEX_ANY))
#define SHORTEDGEFIRST_SUPPORTED(pUIInfo, pPpdData) \
        (SKIP_LEADINGEDGE_CHECK(pUIInfo, pPpdData) || \
        ((pPpdData)->dwLeadingEdgeShort != OPTION_INDEX_ANY))

// printscan\print\drivers\usermode\lib\ufl\api\goodname.h
#define TTcmap_IS_UNICODE(cf)  \
    ((cf) == DTT_Win_UNICODE_cmap2 || (cf) == DTT_Win_UNICODE_cmap4)
#define TTcmap_IS_FORMAT2(cf)  \
    (((cf) >= DTT_Win_UNICODE_cmap2 && (cf) <= DTT_Win_K_cmap2) )
#define TTcmap_IS_J_CMAP(cf) \
    ((cf) == DTT_Win_J_cmap2 || (cf) == DTT_Win_J_cmap4)
#define TTcmap_IS_CS_CMAP(cf) \
    ((cf) == DTT_Win_CS_cmap2 || (cf) == DTT_Win_CS_cmap4)
#define TTcmap_IS_CT_CMAP(cf) \
    ((cf) == DTT_Win_CT_cmap2 || (cf) == DTT_Win_CT_cmap4)
#define TTcmap_IS_K_CMAP(cf) \
    ((cf) == DTT_Win_K_cmap2 || (cf) == DTT_Win_K_cmap4)

// printscan\print\drivers\usermode\lib\ufl\api\ufltypes.h
#define IS_TYPE42CID(lFormat) \
            (  (lFormat) == kTTType42CID_H          \
            || (lFormat) == kTTType42CID_V          \
            || (lFormat) == kTTType42CID_Resource_H \
            || (lFormat) == kTTType42CID_Resource_V )
#define IS_TYPE42CID_H(lFormat) \
            (  (lFormat) == kTTType42CID_H          \
            || (lFormat) == kTTType42CID_Resource_H )
#define IS_TYPE42CID_V(lFormat) \
            (  (lFormat) == kTTType42CID_V          \
            || (lFormat) == kTTType42CID_Resource_V )
#define IS_CFFCID(lFormat) \
            (  (lFormat) == kCFFCID_H \
            || (lFormat) == kCFFCID_V )
#define IS_TYPE42CID_KEYEDFONT(lFormat) \
            (  (lFormat) == kTTType42CID_H \
            || (lFormat) == kTTType42CID_V )
#define IS_TYPE42CIDFONT_RESOURCE(lFormat)  \
            (  (lFormat) == kTTType42CID_Resource_H \
            || (lFormat) == kTTType42CID_Resource_V )

// printscan\print\drivers\usermode\lib\ufl\api\ufo.h
#define HOSTFONT_ISALLOWED(pUFO, pName) \
    (UFLBool)(pUFO)->pUFL->fontProcs.pfHostFontUFLHandler(HOSTFONT_UFLREQUEST_IS_ALLOWED, \
                                                            (pUFO)->hHostFontData, \
                                                            (pName), NULL, \
                                                            NULL, 0)

// printscan\print\drivers\usermode\lib\ufl\source\ufocff.c
#define KNOWN_OS(o, on, s, max)  (!UFLstrcmp((o), (on)) && ((0 <= (s)) && ((s) < (max))))

// printscan\print\drivers\usermode\lib\uni\fiutils.c
#define IsValidFontInfo(pfi)         ((pfi) && (pfi)->dwSignature == FONT_INFO_SIGNATURE)

// printscan\print\drivers\usermode\msplot\tools\ntres\plotgpc.c
#define PKF_FORMINFO            (PKF_MUL_OK     |           \
                                 PKF_VARSIZE    |           \
                                 PKF_REQ        |           \
                                 PKF_FS_VARLEN)

// printscan\print\drivers\usermode\oemdll\com\rendps\oemud.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\oemdll\com\renduni\oemud.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\oemdll\com\renduni\pdev.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\drivers\usermode\parsers\ppd\custsize.c
#define FIXUP_FEEDDIRECTION(iMainOrient, iAltOrient, wAltFeedDirection) \
        { \
            if (! ORIENTATION_AVAILABLE(iMainOrient)) \
            { \
                pCSData->wFeedDirection = \
                    ORIENTATION_AVAILABLE(iAltOrient) ? \
                        (wAltFeedDirection) : \
                        MAX_FEEDDIRECTION; \
            } \
        }

// printscan\print\drivers\usermode\parsers\ppd\ppdparse.h
#define IS_SPACE(c)     ((c) == SPACE || (c) == TAB)
#define IS_NEWLINE(c)   ((c) == CR || (c) == LF)
#define IS_SYMBOL_INVOC(pInvoc)    ((pInvoc)->dwLength & SYMBOL_INVOCATION_LENGTH)

// printscan\print\drivers\usermode\tools\uni\gpc2gpd\utils.h
#define IS_CHAR_READABLE(ch) ((ch) >= 0x20 && (ch) <= 0x7E)

// printscan\print\drivers\usermode\tools\uni\minidev.new\projrec.h
#define	MDWVERSIONSIZE	sizeof(MDWVERSION)

// printscan\print\drivers\usermode\tools\uni\pfm2ufm\pfmconv.c
#define DO_FONTSIM(pFInData) \
    (((pFInData)->DI.sVersion == DRIVERINFO_VERSION_WIN31)    || \
     ((pFInData)->DI.sVersion == DRIVERINFO_VERSION_SIMULATE) || \
     IS_DBCSCHARSET((pFInData)->PFMH.dfCharSet) )
#define IS_DBCSCTTTYPE(sCTT)     \
    (  ((sCTT) == CTT_JIS78)     \
    || ((sCTT) == CTT_JIS78_ANK) \
    || ((sCTT) == CTT_JIS83)     \
    || ((sCTT) == CTT_JIS83_ANK) \
    || ((sCTT) == CTT_NS86)      \
    || ((sCTT) == CTT_TCA)       \
    || ((sCTT) == CTT_BIG5)      \
    || ((sCTT) == CTT_ISC))
#define CTT_TYPE_TO_CHARSET(sCTT) \
    (((sCTT) == CTT_JIS78)     ? SHIFTJIS_CHARSET : \
    (((sCTT) == CTT_JIS78_ANK) ? SHIFTJIS_CHARSET : \
    (((sCTT) == CTT_JIS83)     ? SHIFTJIS_CHARSET : \
    (((sCTT) == CTT_JIS83_ANK) ? SHIFTJIS_CHARSET : \
    (((sCTT) == CTT_NS86)      ? CHINESEBIG5_CHARSET : \
    (((sCTT) == CTT_TCA)       ? CHINESEBIG5_CHARSET : \
    (((sCTT) == CTT_BIG5)      ? CHINESEBIG5_CHARSET : \
    (((sCTT) == CTT_ISC)       ? HANGEUL_CHARSET : 1))))))))

// printscan\print\drivers\usermode\unidrv2\font\fmmacro.h
#define VALID_FONTPDEV(pfontpdev) \
        ( (pfontpdev) && ((pfontpdev)->dwSignature == FONTPDEV_ID) )

// printscan\print\drivers\usermode\unidrv2\font\truetype.c
#define VALID_FONTMAP_TTO(pPrivateFM)                                       \
    ((pPrivateFM) &&                                                        \
     /*(pPrivateFM)->pTTFile && */                                          \
     (pPrivateFM)->pvGlyphData &&                                           \
     /* (pPrivateFM)->pvDLData */ TRUE )
#define VALID_FONTMAP(pFM)  ((pFM) && VALID_FONTMAP_TTO(GETPRIVATEFM(pFM)))
#define IS_TYPE1(pIFI) ((pIFI) && ((pIFI)->flInfo & FM_INFO_TECH_TYPE1))
#define IS_TRUETYPE(pIFI) ((pIFI) && ((pIFI)->flInfo & FM_INFO_TECH_TRUETYPE))
#define IS_BIDICHARSET(j) \
    (((j) == HEBREW_CHARSET)      || \
     ((j) == ARABIC_CHARSET)      || \
     ((j) == EASTEUROPE_CHARSET))

// printscan\print\drivers\usermode\unidrv2\inc\pdev.h
#define VALID_PDEV(pdev) \
        ((pdev) && ((pdev) == (pdev)->pvStartSig) && \
        ((pdev) == (pdev)->pvEndSig) && \
        ((pdev)->ulID == PDEV_ID))

// printscan\print\drivers\usermode\unidrv2\inc\uni16gpc.h
#define VERSION_CHECK(x)     (((x) & 0xff00) <= GPC_VERSION)

// printscan\print\drivers\usermode\unidrv2\oemtest\oemud.h
#define VALID_PDEVOBJ(pdevobj) \
        ((pdevobj) && (pdevobj)->dwSize >= sizeof(DEVOBJ) && \
         (pdevobj)->hEngine && (pdevobj)->hPrinter && \
         (pdevobj)->pPublicDM && (pdevobj)->pDrvProcs )

// printscan\print\spooler\inc\splcom.h
#define MAX_PRINTER_INFO1   ( (MAX_PRINTER_BROWSE_NAME + MAX_UNC_PRINTER_NAME + MAX_PATH) *sizeof(WCHAR) + sizeof( PRINTER_INFO_1) )
#define MAX_DRIVER_INFO_2   ( 5*MAX_PATH*sizeof(WCHAR) + sizeof( DRIVER_INFO_2 ) )
#define MAX_DRIVER_INFO_3   ( 8*MAX_PATH*sizeof(WCHAR) + sizeof( DRIVER_INFO_3 ) )
#define MAX_DRIVER_INFO_6   ( NUMBER_OF_DRV_INFO_6_STRINGS*MAX_PATH*sizeof(WCHAR) + sizeof( DRIVER_INFO_6 ) )
#define MAX_DRIVER_INFO_VERSION  ( NUMBER_OF_DRV_INFO_6_STRINGS*MAX_PATH*sizeof(DRIVER_FILE_INFO)*sizeof(WCHAR) + sizeof( DRIVER_INFO_VERSION ) )

// printscan\print\spooler\inetpp2\server\ping.cxx
#define MAX_BUFFER_SIZE       (sizeof(ICMP_ECHO_REPLY) + 0xfff7 + MAX_OPT_SIZE)

// printscan\print\spooler\monitors\local\localmon.h
#define WITHINRANGE( val, lo, hi ) \
    ( ( val <= hi ) && ( val >= lo ) )

// printscan\print\spooler\monitors\localui\localui.h
#define WITHINRANGE( val, lo, hi ) \
    ( ( val <= hi ) && ( val >= lo ) )

// printscan\print\spooler\spllib\webipp.h
#define IPP_RET_VALIDATEJOB     (IPP_RESPONSE | IPP_REQ_VALIDATEJOB)
#define SUCCESS_RANGE(wRsp) ((BOOL)((wRsp >= 0x0000) && (wRsp <= 0x00FF)))
#define ERROR_RANGE(wReq)                                          \
    (((wReq >= IPPRSP_ERROR_400) && (wReq <= IPPRSP_ERROR_40E)) || \
     ((wReq >= IPPRSP_ERROR_500) && (wReq <= IPPRSP_ERROR_506)) || \
     ((wReq == IPPRSP_ERROR_540)))
#define IS_TAG_DELIMITER(bTag)   ((BOOL)((bTag >= 0x00) && (bTag <= 0x0F)))
#define IS_TAG_ATTRIBUTE(bTag)   ((BOOL)((bTag >= 0x10) && (bTag <= 0xFF)))
#define IS_TAG_OUTBOUND(bTag)    ((BOOL)((bTag >= 0x10) && (bTag <= 0x1F)))
#define IS_TAG_INTEGER(bTag)     ((BOOL)((bTag >= 0x20) && (bTag <= 0x2F)))
#define IS_TAG_OCTSTR(bTag)      ((BOOL)((bTag >= 0x30) && (bTag <= 0x3F)))
#define IS_TAG_CHRSTR(bTag)      ((BOOL)((bTag >= 0x40) && (bTag <= 0x5F)))
#define IS_TAG_CHARSETSTR(bTag)  ((BOOL)((bTag == 0x41) || (bTag == 0x42)))
#define IS_RANGE_DELIMITER(bTag) ((BOOL)((bTag >= 0x00) && (bTag <= 0x05)))
#define IS_TAG_COMPOUND(bTag)    ((BOOL)((bTag == 0x35) || (bTag == 0x36)))

// printscan\print\spooler\spoolss\bidispl\clients\bidiutil\bidiutil.cpp
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// printscan\print\spooler\spoolss\bidispl\clients\stress\biditest.cpp
#define IS_ARG(c)   (((c) == '-') || ((c) == '/'))

// printscan\print\spooler\spoolss\win32\local.h
#define MAX_PRINTER_INFO0   2*MAX_PATH*sizeof(WCHAR) + sizeof( PRINTER_INFO_STRESSW)
#define VALIDATE_NAME(pName) \
    ((pName) && *(pName) == L'\\' && *((pName)+1) == L'\\')

// printscan\print\spooler\wpnpinst\wow\inc\mmsystem.h
#define	MIDI_CACHE_VALID    (MIDI_CACHE_ALL | MIDI_CACHE_BESTFIT | MIDI_CACHE_QUERY | MIDI_UNCACHE)	/* ;Internal */
#define	MMIO_DESCEND_VALID (MMIO_FINDCHUNK | MMIO_FINDRIFF | MMIO_FINDLIST) /* ;Internal */
#define	MMIO_CREATE_VALID (MMIO_CREATERIFF | MMIO_CREATELIST)	/* ;Internal */

// printscan\print\spooler\wpnpinst\wow\inc\penwin.h
#define ALC_SYSMINIMUM (ALC_ALPHANUMERIC | ALC_PUNC | ALC_WHITE | ALC_GESTURE)

// printscan\print\spooler\wpnpinst\wow\inc\setupx.h
#define MAX_FILENAME_LEN    20      // Max. filename length. ( > sizeof( "x:\\12345678.123" )

// printscan\print\spooler\wpnpinst\wow\inc\windows.h
#define STM_MSGMAX          (WM_USER+2)    /* ;Internal */
#define BM_GETCHECK         (WM_USER+0)
#define BM_SETCHECK         (WM_USER+1)
#define EM_MSGMAX               (WM_USER+35)    /* ;Internal */
#define LB_SELITEMRANGE        (WM_USER+28)
#define LB_MSGMAX              (WM_USER+38)     /* ;Internal */
#define CB_MSGMAX                (WM_USER+25)       /* ;Internal */

// printscan\publish\minidrv.h
#define IS_DBCSCHARSET(j) \
    (((j) == SHIFTJIS_CHARSET)    || \
    ((j) == HANGEUL_CHARSET)     || \
    ((j) == JOHAB_CHARSET)       || \
    ((j) == GB2312_CHARSET)      || \
    ((j) == CHINESEBIG5_CHARSET))

// printscan\ui\compstui\treeview.h
#define IS_HDR_PUSH(po)         (BOOL)((po) == &OptTypeHdrPush)

// printscan\ui\photowiz\photosel.h
#define PSP_MSG_INVALIDATE_LISTVIEW (WM_USER+57)    // no params

// printscan\ui\printui\forms.cxx
#define FORMSDIFFER( pFormInfoA, pFormInfoB )      \
    ( memcmp( &(pFormInfoA)->Size, &(pFormInfoB)->Size, sizeof (pFormInfoA)->Size )  \
    ||memcmp( &(pFormInfoA)->ImageableArea, &(pFormInfoB)->ImageableArea,            \
              sizeof (pFormInfoA)->ImageableArea ) )

// printscan\ui\unittest\clvtest\chklistv.h
#define NM_GETCHECKSTATE (WM_USER+1)
#define NM_SETCHECKSTATE (WM_USER+2)

// printscan\wia\common\stirt\stiobj.c
#define DEVICE_INFO_SIZE    (sizeof(STI_DEVICE_INFORMATION)+(MAX_PATH * sizeof(WCHAR) * 5))
#define WIA_DEVICE_INFO_SIZE (sizeof(STI_WIA_DEVICE_INFORMATION)+(MAX_PATH * sizeof(WCHAR) * 6))

// printscan\wia\core\server\wiaservc.cpp
#define RANGE_CHECK(x, name) {                              \
    if (valid->name.pElems[WIA_RANGE_STEP] == 0)            \
    {                                                       \
        REP_RANGE_ERROR(x, name);                           \
    }                                                       \
    if ((cur->x < valid->name.pElems[WIA_RANGE_MIN]) ||     \
        (cur->x > valid->name.pElems[WIA_RANGE_MAX]) ||     \
        ((cur->x - valid->name.pElems[WIA_RANGE_MIN]) %     \
         valid->name.pElems[WIA_RANGE_STEP])) {             \
             REP_RANGE_ERROR(x, name);                      \
    };                                                      \
};

// printscan\wia\inc\stipriv.h
#define ecValidation (ERROR_SEVERITY_ERROR | hresLe(ERROR_INVALID_PARAMETER))

// printscan\wia\inc\validate.h
#define IS_VALID_SIZE(cb, cbExpected) \
   ((cb) != (cbExpected) ? \
    (DPRINTF(DM_ERROR, TEXT("invalid size - is %#08lx, expected %#08lx"), (cb), (cbExpected)), FALSE) : \
    TRUE)
#define IS_VALID_HANDLET(hnd, type) \
   (IsValidH##type(hnd) ? \
    TRUE : \
    (DPRINTF(DM_ERROR, TEXT("invalid H") #type TEXT(" - %#08lx"), (hnd)), FALSE))

// printscan\wia\setup\clsinst\sti_ci.h
#define MAX_DESCRIPTION         64*sizeof(TCHAR)
#define IS_VALID_HANDLE(h)  (((h) != NULL) && ((h) != INVALID_HANDLE_VALUE))

// public\ddk\inc\afilter.h
#define ARC_FILTER_MAX_OPENS (sizeof(ULONG) * 8)

// public\ddk\inc\classpnp.h
#define DO_MCD(fdoExtension)                                        \
    (((fdoExtension)->MediaChangeDetectionInfo != NULL) &&          \
     ((fdoExtension)->MediaChangeDetectionInfo->MediaChangeDetectionDisableCount == 0))

// public\ddk\inc\d3dhalex.h
#define D3DGDI_IS_GDI2(pData) \
    ((((DD_GETDRIVERINFO2DATA*)(pData->lpvData))->dwMagic)  == D3DGDI2_MAGIC)
#define D3DGDI_IS_STEREOMODE(pData) \
    ((((DD_STEREOMODE*)        (pData->lpvData))->dwHeight) != D3DGDI2_MAGIC)
#define D3DGDI_GET_GDI2_DATA(pData) \
    (D3DGDI_IS_GDI2(pData) ? (((DD_GETDRIVERINFO2DATA*)(pData->lpvData))) : NULL)
#define D3DGDI_GET_STEREOMODE_DATA(pData) \
    (D3DGDI_IS_STEREOMODE(pData) ? (((DD_STEREOMODE*)(pData->lpvData)))   : NULL)

// public\ddk\inc\hbapiwmi.h
    #define MSFC_HBAPortAttributesResults_PortMaxFrameSize_SIZE sizeof(ULONG)

// public\ddk\inc\miniport.h
#define RTL_FIELD_SIZE(type, field) (sizeof(((type *)0)->field))
#define RTL_CONSTANT_STRING(s) { sizeof( s ) - sizeof( (s)[0] ), sizeof( s ), s }
#define PCI_CONFIGURATION_TYPE(PciData) \
    (((PPCI_COMMON_CONFIG)(PciData))->HeaderType & ~PCI_MULTIFUNCTION)
#define PCI_MULTIFUNCTION_DEVICE(PciData) \
    ((((PPCI_COMMON_CONFIG)(PciData))->HeaderType & PCI_MULTIFUNCTION) != 0)

// public\ddk\inc\mountmgr.h
#define MOUNTMGR_IS_DRIVE_LETTER(s) (   \
    (s)->Length == 28 &&                \
    (s)->Buffer[0] == '\\' &&           \
    (s)->Buffer[1] == 'D' &&            \
    (s)->Buffer[2] == 'o' &&            \
    (s)->Buffer[3] == 's' &&            \
    (s)->Buffer[4] == 'D' &&            \
    (s)->Buffer[5] == 'e' &&            \
    (s)->Buffer[6] == 'v' &&            \
    (s)->Buffer[7] == 'i' &&            \
    (s)->Buffer[8] == 'c' &&            \
    (s)->Buffer[9] == 'e' &&            \
    (s)->Buffer[10] == 's' &&           \
    (s)->Buffer[11] == '\\' &&          \
    (s)->Buffer[12] >= 'A' &&           \
    (s)->Buffer[12] <= 'Z' &&           \
    (s)->Buffer[13] == ':')
#define MOUNTMGR_IS_VOLUME_NAME(s) (                                          \
     ((s)->Length == 96 || ((s)->Length == 98 && (s)->Buffer[48] == '\\')) && \
     (s)->Buffer[0] == '\\' &&                                                \
     ((s)->Buffer[1] == '?' || (s)->Buffer[1] == '\\') &&                     \
     (s)->Buffer[2] == '?' &&                                                 \
     (s)->Buffer[3] == '\\' &&                                                \
     (s)->Buffer[4] == 'V' &&                                                 \
     (s)->Buffer[5] == 'o' &&                                                 \
     (s)->Buffer[6] == 'l' &&                                                 \
     (s)->Buffer[7] == 'u' &&                                                 \
     (s)->Buffer[8] == 'm' &&                                                 \
     (s)->Buffer[9] == 'e' &&                                                 \
     (s)->Buffer[10] == '{' &&                                                \
     (s)->Buffer[19] == '-' &&                                                \
     (s)->Buffer[24] == '-' &&                                                \
     (s)->Buffer[29] == '-' &&                                                \
     (s)->Buffer[34] == '-' &&                                                \
     (s)->Buffer[47] == '}'                                                   \
    )
#define MOUNTMGR_IS_DOS_VOLUME_NAME(s) (    \
     MOUNTMGR_IS_VOLUME_NAME(s) &&          \
     (s)->Length == 96 &&                   \
     (s)->Buffer[1] == '\\'                 \
    )
#define MOUNTMGR_IS_DOS_VOLUME_NAME_WB(s) ( \
     MOUNTMGR_IS_VOLUME_NAME(s) &&          \
     (s)->Length == 98 &&                   \
     (s)->Buffer[1] == '\\'                 \
    )
#define MOUNTMGR_IS_NT_VOLUME_NAME(s) (     \
     MOUNTMGR_IS_VOLUME_NAME(s) &&          \
     (s)->Length == 96 &&                   \
     (s)->Buffer[1] == '?'                  \
    )
#define MOUNTMGR_IS_NT_VOLUME_NAME_WB(s) (  \
     MOUNTMGR_IS_VOLUME_NAME(s) &&          \
     (s)->Length == 98 &&                   \
     (s)->Buffer[1] == '?'                  \
    )

// public\ddk\inc\ndis.h
#define NDIS_STRING_CONST(x)    {sizeof(L##x)-2, sizeof(L##x), L##x}
#define NdisCopyLookaheadData(_Destination, _Source, _Length, _MacOptions)  \
    {                                                                       \
        if ((_MacOptions) & NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA)            \
        {                                                                   \
            RtlCopyMemory(_Destination, _Source, _Length);                  \
        }                                                                   \
        else                                                                \
        {                                                                   \
            PUCHAR _Src = (PUCHAR)(_Source);                                \
            PUCHAR _Dest = (PUCHAR)(_Destination);                          \
            PUCHAR _End = _Dest + (_Length);                                \
            while (_Dest < _End)                                            \
            {                                                               \
                *_Dest++ = *_Src++;                                         \
            }                                                               \
        }                                                                   \
    }
#define NdisWritePortUchar(Handle,Port,Data)                                \
        WRITE_PORT_UCHAR((PUCHAR)(NDIS_PORT_TO_PORT(Handle,Port)),(UCHAR)(Data))
#define NdisMSetAttributes(_H_, _C_, _M_, _T_)                                      \
                        NdisMSetAttributesEx(_H_,                                   \
                                             _C_,                                   \
                                             0,                                     \
                                             (_M_) ? NDIS_ATTRIBUTE_BUS_MASTER : 0, \
                                             _T_)                                   \

// public\ddk\inc\ndiswan.h
#define ARAP_FRAMING                    (ARAP_V1_FRAMING | ARAP_V2_FRAMING)

// public\ddk\inc\ntddk.h
#define RtlInitEmptyUnicodeString(_ucStr,_buf,_bufSize) \
    ((_ucStr)->Buffer = (_buf), \
     (_ucStr)->Length = 0, \
     (_ucStr)->MaximumLength = (USHORT)(_bufSize))
#define FOR_ALL_RANGES(RangeList, Iterator, Current)            \
    for (RtlGetFirstRange((RangeList), (Iterator), &(Current)); \
         (Current) != NULL;                                     \
         RtlGetNextRange((Iterator), &(Current), TRUE)          \
         )
#define FOR_ALL_RANGES_BACKWARDS(RangeList, Iterator, Current)  \
    for (RtlGetLastRange((RangeList), (Iterator), &(Current));  \
         (Current) != NULL;                                     \
         RtlGetNextRange((Iterator), &(Current), FALSE)         \
         )
#define ExInitializeFastMutex(_FastMutex)                            \
    (_FastMutex)->Count = 1;                                         \
    (_FastMutex)->Owner = NULL;                                      \
    (_FastMutex)->Contention = 0;                                    \
    KeInitializeEvent(&(_FastMutex)->Event,                          \
                      SynchronizationEvent,                          \
                      FALSE);
#define IoInitializeRemoveLock(Lock, Tag, Maxmin, HighWater) \
        IoInitializeRemoveLockEx (Lock, Tag, Maxmin, HighWater, sizeof (IO_REMOVE_LOCK))

// public\ddk\inc\ntia64.h
#define IS_DBR_RDWR(DBR)        (((DBR) & DBR_RDWR) == DBR_RDWR)
#define IS_DBR_WR(DBR)          (((DBR) & DBR_WR)   == DBR_WR)
#define IS_IBR_EX(IBR)          (((IBR) & IBR_EX)   == IBR_EX)
#define DBR_ACTIVE(DBR)         (IS_DBR_RDWR(DBR) || IS_DBR_WR(DBR))

// public\ddk\inc\wdm\1394.h
#define MAX_SUFFIX_SIZE                         4*sizeof(WCHAR)

// public\ddk\inc\wdm\strmini.h
#define MP_UNINITIALIZED_VALUE ((ULONG) ~0)

// public\ddk\inc\wdm\wdm.h
#define RtlInitEmptyUnicodeString(_ucStr,_buf,_bufSize) \
    ((_ucStr)->Buffer = (_buf), \
     (_ucStr)->Length = 0, \
     (_ucStr)->MaximumLength = (USHORT)(_bufSize))
#define ExInitializeFastMutex(_FastMutex)                            \
    (_FastMutex)->Count = 1;                                         \
    (_FastMutex)->Owner = NULL;                                      \
    (_FastMutex)->Contention = 0;                                    \
    KeInitializeEvent(&(_FastMutex)->Event,                          \
                      SynchronizationEvent,                          \
                      FALSE);
#define IoInitializeRemoveLock(Lock, Tag, Maxmin, HighWater) \
        IoInitializeRemoveLockEx (Lock, Tag, Maxmin, HighWater, sizeof (IO_REMOVE_LOCK))

// public\ddk\inc\wdm\wmidata.h
    #define MSSmBios_RawSMBiosTables_SmbiosMinorVersion_SIZE sizeof(UCHAR)
    #define MSMCAEvent_InvalidError_RecordId_SIZE sizeof(ULONGLONG)
    #define MSMCAEvent_InvalidError_ErrorSeverity_SIZE sizeof(UCHAR)
    #define MSMCAEvent_InvalidError_Type_SIZE sizeof(ULONG)
    #define MSMCAEvent_InvalidError_Cpu_SIZE sizeof(ULONG)
    #define MSMCAEvent_InvalidError_AdditionalErrors_SIZE sizeof(ULONG)
    #define MSMCAEvent_InvalidError_Size_SIZE sizeof(ULONG)
    #define MSNdis_NetworkAddress_Address_SIZE sizeof(UCHAR[6])
    #define MSNdis_NetworkShortAddress_Address_SIZE sizeof(UCHAR[2])
    #define MSNdis_NetworkLinkSpeed_Outbound_SIZE sizeof(ULONG)
    #define MSNdis_NetworkLinkSpeed_Inbound_SIZE sizeof(ULONG)
    #define MSNdis_MaximumLookahead_NdisMaximumLookahead_SIZE sizeof(ULONG)
    #define MSNdis_MaximumFrameSize_NdisMaximumFrameSize_SIZE sizeof(ULONG)
    #define MSNdis_LinkSpeed_NdisLinkSpeed_SIZE sizeof(ULONG)
    #define MSNdis_TransmitBufferSpace_NdisTransmitBufferSpace_SIZE sizeof(ULONG)
    #define MSNdis_ReceiveBufferSpace_NdisReceiveBufferSpace_SIZE sizeof(ULONG)
    #define MSNdis_VendorID_NdisVendorID_SIZE sizeof(ULONG)
    #define MSNdis_CurrentLookahead_NdisCurrentLookahead_SIZE sizeof(ULONG)
    #define MSNdis_DriverVersion_NdisDriverVersion_SIZE sizeof(USHORT)
    #define MSNdis_MaximumTotalSize_NdisMaximumTotalSize_SIZE sizeof(ULONG)
    #define MSNdis_MacOptions_NdisMacOptions_SIZE sizeof(ULONG)
    #define MSNdis_VendorDriverVersion_NdisVendorDriverVersion_SIZE sizeof(ULONG)
    #define MSNdis_VlanIdentifier_NdisVlanId_SIZE sizeof(ULONG)
    #define MSNdis_PhysicalMediumType_NdisPhysicalMediumType_SIZE sizeof(ULONG)
    #define MSNdis_TransmitsOk_NdisTransmitsOk_SIZE sizeof(ULONGLONG)
    #define MSNdis_ReceivesOk_NdisReceivesOk_SIZE sizeof(ULONGLONG)
    #define MSNdis_TransmitsError_NdisTransmitsError_SIZE sizeof(ULONG)
    #define MSNdis_ReceiveError_NdisReceiveError_SIZE sizeof(ULONG)
    #define MSNdis_ReceiveNoBuffer_NdisReceiveNoBuffer_SIZE sizeof(ULONG)
    #define MSNdis_CoLinkSpeed_NdisCoLinkSpeed_SIZE sizeof(MSNdis_NetworkLinkSpeed)
    #define MSNdis_CoVendorId_NdisCoVendorID_SIZE sizeof(ULONG)
    #define MSNdis_CoDriverVersion_NdisCoDriverVersion_SIZE sizeof(USHORT)
    #define MSNdis_CoMacOptions_NdisCoMacOptions_SIZE sizeof(ULONG)
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
    #define MSNdis_AtmReceiveCellsOk_NdisAtmReceiveCellsOk_SIZE sizeof(ULONGLONG)
    #define MSNdis_AtmTransmitCellsOk_NdisAtmTransmitCellsOk_SIZE sizeof(ULONGLONG)
    #define MSNdis_AtmReceiveCellsDropped_NdisAtmReceiveCellsDropped_SIZE sizeof(ULONGLONG)
    #define MSNdis_EthernetPermanentAddress_NdisPermanentAddress_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_EthernetCurrentAddress_NdisCurrentAddress_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_EthernetMaximumMulticastListSize_NdisEthernetMaximumMulticastListSize_SIZE sizeof(ULONG)
    #define MSNdis_EthernetMacOptions_NdisEthernetMacOptions_SIZE sizeof(ULONG)
    #define MSNdis_EthernetOneTransmitCollision_NdisEthernetOneTransmitCollision_SIZE sizeof(ULONG)
    #define MSNdis_EthernetMoreTransmitCollisions_NdisEthernetMoreTransmitCollisions_SIZE sizeof(ULONG)
    #define MSNdis_TokenRingPermanentAddress_NdisPermanentAddress_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_TokenRingCurrentAddress_NdisCurrentAddress_SIZE sizeof(MSNdis_NetworkAddress)
    #define MSNdis_TokenRingCurrentFunctional_NdisTokenRingCurrentFunctional_SIZE sizeof(ULONG)
    #define MSNdis_TokenRingCurrentGroup_NdisTokenRingCurrentGroup_SIZE sizeof(ULONG)
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
    #define MSNdis_80211_ServiceSetIdentifier_Ndis80211SsId_SIZE sizeof(UCHAR[33])
    #define MSNdis_80211_NetworkType_Ndis80211NetworkType_SIZE sizeof(ULONG)
    #define MSNdis_80211_NetworkTypesSupported_NumberOfItems_SIZE sizeof(ULONG)
    #define MSNdis_80211_NetworkTypeInUse_Ndis80211NetworkTypeInUse_SIZE sizeof(MSNdis_80211_NetworkType)
    #define MSNdis_80211_PowerMode_Ndis80211PowerMode_SIZE sizeof(ULONG)
    #define MSNdis_80211_TransmitPowerLevel_Ndis80211TransmitPowerLevel_SIZE sizeof(ULONG)
    #define MSNdis_80211_ReceivedSignalStrength_Ndis80211ReceivedSignalStrength_SIZE sizeof(LONG)
    #define MSNdis_80211_ReceivedSignalStrengthEventTrigger_Ndis80211ReceivedSignalStrengthTrigger_SIZE sizeof(LONG)
    #define MSNdis_80211_ConfigurationFH_HopPattern_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationFH_HopSet_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationInfo_BeaconPeriod_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationInfo_ATIMWindow_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationInfo_DSConfig_SIZE sizeof(ULONG)
    #define MSNdis_80211_ConfigurationInfo_FHConfig_SIZE sizeof(MSNdis_80211_ConfigurationFH)
    #define MSNdis_80211_WLanBssId_Ndis80211MacAddress_SIZE sizeof(UCHAR[6])
    #define MSNdis_80211_WLanBssId_Reserved_SIZE sizeof(USHORT)
    #define MSNdis_80211_WLanBssId_Ndis80211SsId_SIZE sizeof(UCHAR[32])
    #define MSNdis_80211_WLanBssId_Ndis80211Privacy_SIZE sizeof(ULONG)
    #define MSNdis_80211_WLanBssId_Ndis80211Rssi_SIZE sizeof(ULONG)
    #define MSNdis_80211_WLanBssId_Ndis80211NetworkTypeInUse_SIZE sizeof(MSNdis_80211_NetworkType)
    #define MSNdis_80211_WLanBssId_Ndis80211Configuration_SIZE sizeof(MSNdis_80211_ConfigurationInfo)
    #define MSNdis_80211_WLanBssId_Ndis80211SupportedRate_SIZE sizeof(UCHAR[8])
    #define MSNdis_80211_BSSIList_NumberOfItems_SIZE sizeof(ULONG)
    #define MSNdis_80211_FragmentationThreshold_Ndis80211FragmentationThreshold_SIZE sizeof(ULONG)
    #define MSNdis_80211_RTSThreshold_Ndis80211RTSThreshold_SIZE sizeof(ULONG)
    #define MSNdis_80211_NumberOfAntennas_Ndis80211NumberOfAntennas_SIZE sizeof(ULONG)
    #define MSNdis_80211_ReceiveAntennaSelected_Ndis80211ReceiveAntennaSelected_SIZE sizeof(ULONG)
    #define MSNdis_80211_TransmitAntennaSelected_Ndis80211TransmitAntennaSelected_SIZE sizeof(ULONG)
    #define MSNdis_80211_DataRates_Ndis80211DataRate_SIZE sizeof(UCHAR[8])
    #define MSNdis_80211_DesiredDataRates_Ndis80211DesiredRate_SIZE sizeof(UCHAR[8])
    #define MSNdis_80211_Configuration_Ndis80211Config_SIZE sizeof(MSNdis_80211_ConfigurationInfo)
    #define MSNdis_80211_AddWEP_KeyIndex_SIZE sizeof(ULONG)
    #define MSNdis_80211_RemoveWEP_Ndis80211KeyIndex_SIZE sizeof(ULONG)
    #define MSNdis_80211_Disassociate_UnusedParameter_SIZE sizeof(ULONG)
    #define MSNdis_80211_BssIdListScan_UnusedParameter_SIZE sizeof(ULONG)
    #define MSNdis_80211_AuthenticationMode_Ndis80211AuthenticationMode_SIZE sizeof(ULONG)
    #define MSNdis_80211_PrivacyFilter_Ndis80211PrivacyFilter_SIZE sizeof(ULONG)
    #define MSNdis_80211_ReloadDefaults_Ndis80211ReloadDefaults_SIZE sizeof(ULONG)
    #define ATAPI_FAILURE_PREDICT_DATA_Checksum_SIZE sizeof(UCHAR)
    #define SERIAL_WMI_COMM_DATA_ParityCheckEnable_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_MaximumBaudRate_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_MaximumOutputBufferSize_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_MaximumInputBufferSize_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMM_DATA_SupportParityCheck_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMM_DATA_SettableParityCheck_SIZE sizeof(BOOLEAN)
    #define SERIAL_WMI_COMMPROP_dwMaxTxQueue_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwMaxRxQueue_SIZE sizeof(ULONG)
    #define SERIAL_WMI_COMMPROP_dwMaxBaud_SIZE sizeof(ULONG)
    #define WMI_TAPE_MEDIA_PARAMETERS_MaximumCapacity_SIZE sizeof(ULONGLONG)

// public\ddk\inc\xfilter.h
#define ETH_IS_MULTICAST(Address) \
    (BOOLEAN)(((PUCHAR)(Address))[0] & ((UCHAR)0x01))
#define ETH_IS_BROADCAST(Address)               \
    ((((PUCHAR)(Address))[0] == ((UCHAR)0xff)) && (((PUCHAR)(Address))[1] == ((UCHAR)0xff)))
#define FDDI_IS_MULTICAST(Address, AddressLength, Result) \
    *Result = (BOOLEAN)(*(UCHAR *)(Address) & (UCHAR)0x01)
#define FDDI_IS_BROADCAST(Address, AddressLength, Result)   \
    *Result = ((*(PUCHAR)(Address) == (UCHAR)0xFF) && (*((PUCHAR)(Address)+1) == (UCHAR)0xFF))
#define TR_IS_NOT_DIRECTED(_Address, _Result)                               \
{                                                                           \
    *(_Result) = (BOOLEAN)((_Address)[0] & 0x80);                           \
}
#define TR_IS_FUNCTIONAL(_Address, _Result)                                 \
{                                                                           \
    *(_Result) = (BOOLEAN)(((_Address)[0] & 0x80) &&                        \
                          !((_Address)[2] & 0x80));                         \
}
#define TR_IS_GROUP(_Address, _Result)                                      \
{                                                                           \
    *(_Result) = (BOOLEAN)((_Address)[0] & (_Address)[2] & 0x80);           \
}
#define TR_IS_SOURCE_ROUTING(_Address, _Result)                             \
{                                                                           \
    *(_Result) = (BOOLEAN)((_Address)[0] & 0x80);                           \
}

// public\halkit\inc\nthal.h
#define IS_DBR_RDWR(DBR)        (((DBR) & DBR_RDWR) == DBR_RDWR)
#define IS_DBR_WR(DBR)          (((DBR) & DBR_WR)   == DBR_WR)
#define IS_IBR_EX(IBR)          (((IBR) & IBR_EX)   == IBR_EX)
#define DBR_ACTIVE(DBR)         (IS_DBR_RDWR(DBR) || IS_DBR_WR(DBR))
#define RtlInitEmptyUnicodeString(_ucStr,_buf,_bufSize) \
    ((_ucStr)->Buffer = (_buf), \
     (_ucStr)->Length = 0, \
     (_ucStr)->MaximumLength = (USHORT)(_bufSize))
#define FOR_ALL_RANGES(RangeList, Iterator, Current)            \
    for (RtlGetFirstRange((RangeList), (Iterator), &(Current)); \
         (Current) != NULL;                                     \
         RtlGetNextRange((Iterator), &(Current), TRUE)          \
         )
#define FOR_ALL_RANGES_BACKWARDS(RangeList, Iterator, Current)  \
    for (RtlGetLastRange((RangeList), (Iterator), &(Current));  \
         (Current) != NULL;                                     \
         RtlGetNextRange((Iterator), &(Current), FALSE)         \
         )
#define ExInitializeFastMutex(_FastMutex)                            \
    (_FastMutex)->Count = 1;                                         \
    (_FastMutex)->Owner = NULL;                                      \
    (_FastMutex)->Contention = 0;                                    \
    KeInitializeEvent(&(_FastMutex)->Event,                          \
                      SynchronizationEvent,                          \
                      FALSE);

// public\ifskit\inc\ntifs.h
#define RtlInitEmptyUnicodeString(_ucStr,_buf,_bufSize) \
    ((_ucStr)->Buffer = (_buf), \
     (_ucStr)->Length = 0, \
     (_ucStr)->MaximumLength = (USHORT)(_bufSize))
#define FSCTL_SIS_LINK_FILES            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 65, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
#define IsReparseTagValid(_tag) (                               \
                  !((_tag) & ~IO_REPARSE_TAG_VALID_VALUES) &&   \
                  ((_tag) > IO_REPARSE_TAG_RESERVED_RANGE)      \
                 )
#define ExInitializeFastMutex(_FastMutex)                            \
    (_FastMutex)->Count = 1;                                         \
    (_FastMutex)->Owner = NULL;                                      \
    (_FastMutex)->Contention = 0;                                    \
    KeInitializeEvent(&(_FastMutex)->Event,                          \
                      SynchronizationEvent,                          \
                      FALSE);

// public\internal\admin\inc\cmdline.h
#define SHOW_RESULT_MESSAGE( server, tag, message )	\
	if ( IsLocalSystem( server ) == TRUE )	\
	{	\
		DISPLAY_MESSAGE2( stderr, szBuffer, _T( "%s %s" ), tag, message );	\
	}	\
	else	\
	{	\
		DISPLAY_MESSAGE3( stderr, szBuffer, _T( "%s %s: %s" ), tag, server, message );	\
	}	\
	1

// public\internal\admin\inc\msodw.h
#define MSODWRECOVERQUIT (msoctdsRecover | msoctdsQuit)
#define MSODWRESTARTQUIT (msoctdsRestart | msoctdsQuit)
#define MSODWRESPONSES (msoctdsQuit | msoctdsRestart | msoctdsRecover)

// public\internal\admin\inc\pfrcfg.h
#define ISCHECKED(x) ((x & epfaaSetCheck) != 0 || (x & (epfaaChecked | epfaaRemCheck)) == epfaaChecked)
#define SETCHECK(x)  x = ((x & ~epfaaRemCheck) | epfaaSetCheck);
#define REMCHECK(x)  x = ((x & ~epfaaSetCheck) | epfaaRemCheck);

// public\internal\com\inc\corhdr.h
#define IsMiNoInlining(x)                   ((x) & miNoInlining)

// public\internal\drivers\inc\ntddsnap.h
#define IOCTL_VOLSNAP_SET_MAX_DIFF_AREA_SIZE        CTL_CODE(VOLSNAPCONTROLTYPE, 10, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\internal\ds\inc\crypto\bignum.h
#define IS_EVEN(n) (~(n) & 1)
#define IS_ODD(n) ((n) & 1)

// public\internal\ds\inc\dnslib.h
#define IS_DNS_LIST_EMPTY( pList )          \
            ( (pList)->pFirst == NULL )
#define IS_WINS_TYPE(type)      (((type) & 0xfffc) == 0xff00)

// public\internal\ds\inc\dnsrpc.h
#define DNS_IS_NAME_IN_RECORD(pRecord, pname) \
            ( DNS_GET_END_OF_RPC_RECORD_DATA(pRecord) >= \
                (PCHAR)DNS_GET_NEXT_NAME(pname) )

// public\internal\ds\inc\fpnwcomm.h
#define NCP_USER_IS_CONNECTED_BUT_REMOTE(connid)    (0xD0000000 | (connid))

// public\internal\ds\inc\netlib.h
#define IN_RANGE(SomeValue, SomeMin, SomeMax) \
    ( ((SomeValue) >= (SomeMin)) && ((SomeValue) <= (SomeMax)) )
#define NetpIsServiceLevelValid( Level ) \
     ( ((Level)==0) || ((Level)==1) || ((Level)==2) )

// public\internal\ds\inc\nlmon.h
#define INIT_OBJ_ATTR(Obj) \
    InitializeObjectAttributes( &(Obj), NULL, 0, NULL, NULL )

// public\internal\ds\inc\permit.h
#define UAS_MAX_ACL_SIZE        (sizeof(UAS_ACCESREC) + LM20_PATHLEN \
                                    + sizeof(UAS_VPERM) \
                                    + (LM20_MAXPERMENTRIES - 1) * sizeof(PERM))

// public\internal\net\inc\apiworke.h
#define RANGE_F(x,y,z)          (((unsigned long)x >= (unsigned long)y) && \
                                 ((unsigned long)x < ((unsigned long)y + z)))

// public\internal\net\inc\ipfltdrv.h
#define AreAllFieldsUnchanged(pFilter)      \
    ((pFilter)->fLateBound == 0x00000000)

// public\internal\net\inc\isnkrnl.h
#define MIPX_CHECKSUM      (I_MIPX | 104) /* Enable/Disable checksum      */
#define MIPX_GETMAXADAPTERS (I_MIPX | 142)
#define MIPX_ADAPTERNUM    (I_MIPX | 302) /* Get maximum adapter number */
#define MIPX_ADAPTERNUM2   (I_MIPX | 312) /* Max. number including duplicates */

// public\internal\net\inc\nbtioctl.h
#define IOCTL_NETBT_CHECK_IP_ADDR    _NETBT_CTRL_CODE( 44, METHOD_OUT_DIRECT, \
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\internal\net\inc\netlib.h
#define IN_RANGE(SomeValue, SomeMin, SomeMax) \
    ( ((SomeValue) >= (SomeMin)) && ((SomeValue) <= (SomeMax)) )
#define NetpIsServiceLevelValid( Level ) \
     ( ((Level)==0) || ((Level)==1) || ((Level)==2) )

// public\internal\printscan\inc\faxreg.h
#define FAX_ADDERSS_VALID_CHARACTERS                    TEXT("0123456789 -|^!#$*,?@ABCbcdDPTWdptw")

// public\internal\sdktools\inc\ehdata.h
#define TD_IS_TYPE_ELLIPSIS(td) ((td == NULL) || (TD_NAME(*td)[0] == '\0'))
#define PER_IS_MSVC_EH(per)	((PER_CODE(per) == EH_EXCEPTION_NUMBER) && 			\
							 (PER_NPARAMS(per) == EH_EXCEPTION_PARAMETERS) &&	\
							 (PER_MAGICNUM(per) == EH_MAGIC_NUMBER1))

// public\internal\shell\inc\comctrlp.h
#define TB_SETBOUNDINGSIZE      (WM_USER + 93)
#define RBS_VALID       (RBS_AUTOSIZE | RBS_TOOLTIPS | RBS_VARHEIGHT | RBS_BANDBORDERS | RBS_REGISTERDROP)
#define BL_MSGMAX               (WM_USER+17)
#define TME_VALID (TME_HOVER | TME_LEAVE | TME_NONCLIENT | TME_QUERY | TME_CANCEL)
#define TME_VALID (TME_HOVER | TME_LEAVE | TME_QUERY | TME_CANCEL)

// public\internal\shell\inc\powrprofp.h
#define MAX_NAME_SIZE (MAX_NAME_LEN +1) * sizeof(TCHAR)
#define MAX_DESC_SIZE (MAX_DESC_LEN +1) * sizeof(TCHAR)

// public\internal\shell\inc\shlobjp.h
#define IS_SPECIAL_ZONE(a) (((a) == ZONE_UNKNOWN) || ((a) == ZONE_MIXED))
#define VBF_VALID               (VBF_TOOLS | VBF_ADDRESS | VBF_LINKS | VBF_BRAND | VBF_MENU | VBF_EXTERNALBANDS)

// public\internal\shell\inc\shpriv.h
#define MAX_VOLUMEINFO2 (sizeof(VOLUMEINFO2) + (4 * MAX_ICONLOCATION + 1 * MAX_LABEL) * sizeof(WCHAR))

// public\internal\termsrv\inc\rdpdr.h
#define DR_CHECK_DEVICEDATALEN(DeviceAnnounce, DeviceSub) \
    (DeviceAnnounce->DeviceDataLength <= (sizeof(DeviceSub) - sizeof(*DeviceAnnounce)))

// public\internal\windows\inc\conapi.h
#define CONSOLE_READ_VALID      (CONSOLE_READ_NOREMOVE | CONSOLE_READ_NOWAIT)

// public\internal\windows\inc\duser\dusercore.h
#define IGPM_SIZE               (2)     // | Optimize for minimum working set
#define GMFI_VALID         (GMFI_PAINT |                                                 \
                            GMFI_INPUTKEYBOARD | GMFI_INPUTMOUSE | GMFI_INPUTMOUSEMOVE | \
                            GMFI_CHANGESTATE | GMFI_CHANGERECT | GMFI_CHANGESTYLE)
#define SGM_VALID          (SGM_FULL | SGM_RECEIVECONTEXT)
#define GENUM_VALID         (GENUM_CURRENT | GENUM_SIBLINGS | GENUM_TYPE | GENUM_MODIFYTREE)
#define GS_VALID           (GS_RELATIVE | GS_VISIBLE | GS_ENABLED | GS_BUFFERED |       \
                            GS_ALLOWSUBCLASS | GS_KEYBOARDFOCUS | GS_MOUSEFOCUS |       \
                            GS_CLIPINSIDE | GS_CLIPSIBLINGS | GS_HREDRAW | GS_VREDRAW | \
                            GS_OPAQUE | GS_ZEROORIGIN | GS_CUSTOMHITTEST |              \
                            GS_ADAPTOR | GS_CACHED | GS_DEEPPAINTSTATE)
#define GBIM_VALID         (GBIM_STYLE | GBIM_ALPHA | GBIM_FILL)

// public\internal\windows\inc\duser\dusermotion.h
#define GTX_EXEC_VALID          (GTX_EXEC_DIR | GTX_EXEC_CACHE)

// public\internal\windows\inc\ntgdistr.h
#define UFI_HASH_VALUE(pufi) (((pufi)->CheckSum==TYPE1_FONT_TYPE) ?                   \
                              (pufi)->Index : (pufi)->CheckSum )
#define UFI_SAME_FACE(pufi1,pufi2)                                                    \
    (((pufi1)->CheckSum == (pufi2)->CheckSum) && ((pufi1)->Index == (pufi2)->Index))
#define UFI_SAME_FILE(pufi1,pufi2) ((((pufi1)->CheckSum==TYPE1_FONT_TYPE)  && ((pufi2)->CheckSum==TYPE1_FONT_TYPE)) ?  \
                                    ((pufi1)->Index == (pufi2)->Index)  :             \
                                    ((pufi1)->CheckSum == (pufi2)->CheckSum))
#define UFI_SAME_RASTERIZER_VERSION(pufiClient,pufiServer)                            \
    (((pufiClient)->CheckSum == (pufiServer)->CheckSum) &&                            \
     ((pufiClient)->Index <= (pufiServer)->Index))

// public\internal\windows\inc\winconp.h
#define CONSOLE_SELECTION_VALID         (CONSOLE_SELECTION_IN_PROGRESS | \
                                         CONSOLE_SELECTION_NOT_EMPTY | \
                                         CONSOLE_MOUSE_SELECTION | \
                                         CONSOLE_MOUSE_DOWN)

// public\internal\windows\inc\wingdip.h
#define IS_ANY_DBCS_CHARSET( CharSet )                              \
                   ( ((CharSet) == SHIFTJIS_CHARSET)    ? TRUE :    \
                     ((CharSet) == HANGEUL_CHARSET)     ? TRUE :    \
                     ((CharSet) == CHINESEBIG5_CHARSET) ? TRUE :    \
                     ((CharSet) == GB2312_CHARSET)      ? TRUE : FALSE )

// public\internal\windows\inc\winuserp.h
#define AW_VALID                    (AW_HOR_POSITIVE |\
                                     AW_HOR_NEGATIVE |\
                                     AW_VER_POSITIVE |\
                                     AW_VER_NEGATIVE |\
                                     AW_CENTER       |\
                                     AW_HIDE         |\
                                     AW_ACTIVATE     |\
                                     AW_BLEND        |\
                                     AW_SLIDE)
#define UISF_VALID                     (UISF_HIDEFOCUS | \
                                        UISF_HIDEACCEL | \
                                        UISF_ACTIVE)
#define TME_VALID (TME_HOVER | TME_LEAVE | TME_NONCLIENT | TME_QUERY | TME_CANCEL)
#define TME_VALID (TME_HOVER | TME_LEAVE | TME_QUERY | TME_CANCEL)
#define BF_VALID       (BF_MIDDLE |  \
                        BF_SOFT   |  \
                        BF_ADJUST |  \
                        BF_FLAT   |  \
                        BF_MONO   |  \
                        BF_LEFT   |  \
                        BF_TOP    |  \
                        BF_RIGHT  |  \
                        BF_BOTTOM |  \
                        BF_DIAGONAL)
#define WPF_VALID              (WPF_SETMINPOSITION     | \
                                WPF_RESTORETOMAXIMIZED)
#define MOD_VALID           (MOD_ALT|MOD_CONTROL|MOD_SHIFT|MOD_WIN|MOD_SAS)
#define SWP_VALID1          (SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOREDRAW | SWP_NOACTIVATE | SWP_FRAMECHANGED)
#define SWP_VALID           (SWP_VALID1 | SWP_VALID2)
#define MF_VALID          (MF_CHANGE_VALID    | \
                           MF_HELP            | \
                           MF_MOUSESELECT)
#define ISSSTEXTOROD(bType) (((bType) <= SS_TEXTMAX0) \
                                || (((bType) >= SS_TEXTMIN1) && ((bType) <= SS_TEXTMAX1)))
#define DDL_VALID          (DDL_READWRITE  | \
                            DDL_READONLY   | \
                            DDL_HIDDEN     | \
                            DDL_SYSTEM     | \
                            DDL_DIRECTORY  | \
                            DDL_ARCHIVE    | \
                            DDL_POSTMSGS   | \
                            DDL_DRIVES     | \
                            DDL_EXCLUSIVE)
#define FE_FONTSMOOTHINGTYPE_VALID          (FE_FONTSMOOTHINGSTANDARD | FE_FONTSMOOTHINGCLEARTYPE | FE_FONTSMOOTHINGDOCKING)
#define SPIF_VALID            (SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE)
#define ET_VALID           (ET_ALLOWFORWAIT | ET_TRYTOKILLNICELY | ET_NOUI | ET_NOWAIT)

// public\oak\inc\minidrv.h
#define IS_DBCSCHARSET(j) \
    (((j) == SHIFTJIS_CHARSET)    || \
    ((j) == HANGEUL_CHARSET)     || \
    ((j) == JOHAB_CHARSET)       || \
    ((j) == GB2312_CHARSET)      || \
    ((j) == CHINESEBIG5_CHARSET))

// public\sdk\amovie\inc\wxdebug.h
    #define REMIND(str) __FILE__ "(" QQUOTE(__LINE__) ") :  " str

// public\sdk\inc16\windows.h
#define STM_MSGMAX          (WM_USER+2)    /* ;Internal */
#define BM_GETCHECK         (WM_USER+0)
#define BM_SETCHECK         (WM_USER+1)
#define EM_MSGMAX               (WM_USER+35)    /* ;Internal */
#define LB_SELITEMRANGE        (WM_USER+28)
#define LB_MSGMAX              (WM_USER+38)     /* ;Internal */

// public\sdk\inc16\windowsx.h
#define     IsRestored(hwnd)    ((GetWindowStyle(hwnd) & (WS_MINIMIZE | WS_MAXIMIZE)) == 0L)
#define     CheckDefDlgRecursion(pfRecursion) \
    if (*(pfRecursion)) { *(pfRecursion) = FALSE; return FALSE; }
#define HANDLE_WM_GETMINMAXINFO(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MINMAXINFO FAR*)(lParam)), 0L)
#define FORWARD_WM_GETMINMAXINFO(hwnd, lpMinMaxInfo, fn) \
    (void)(fn)((hwnd), WM_GETMINMAXINFO, 0, (LPARAM)(MINMAXINFO FAR*)(lpMinMaxInfo))
#define HANDLE_WM_MDIMAXIMIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIMAXIMIZE(hwnd, hwndMaximize, fn) \
    (void)(fn)((hwnd), WM_MDIMAXIMIZE, (WPARAM)(hwndMaximize), 0L)
#define HANDLE_WM_MDIICONARRANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_MDIICONARRANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_MDIICONARRANGE, 0, 0L)
#define Button_SetCheck(hwndCtl, check)     ((void)SendMessage((hwndCtl), BM_SETCHECK, (WPARAM)(int)(check), 0L))
#define Edit_LimitText(hwndCtl, cchMax)         ((void)SendMessage((hwndCtl), EM_LIMITTEXT, (WPARAM)(cchMax), 0L))
#define ComboBox_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))

// public\sdk\inc\allerror.h
#define SWM_E_INVALIDPDF                 ((HRESULT)0x80081300L)
#define SWM_E_INVALIDPDFVERSION          ((HRESULT)0x80081301L)
#define DB_E_NONCONTIGUOUSRANGE          ((HRESULT)0x80040E2BL)
#define DB_E_INVALIDTRANSITION           ((HRESULT)0x80040E2CL)
#define DB_E_INVALID                     ((HRESULT)0x80040E45L)
#define DB_E_NULLACCESSORNOTSUPPORTED    ((HRESULT)0x80040E49L)
#define DB_E_MAXPENDCHANGESEXCEEDED      ((HRESULT)0x80040E54L)
#define MD_E_INVALIDAXIS                 ((HRESULT)0x80040E63L)
#define MD_E_INVALIDCELLRANGE            ((HRESULT)0x80040E64L)

// public\sdk\inc\alphaops.h
#define TBIS_FUNC       (PRIV_PAL_FUNC | 0x15)
#define DTBIS_FUNC      (PRIV_PAL_FUNC | 0x16)

// public\sdk\inc\atl21\atlframe.h
#define DECLARE_FRAME_WND_CLASS_EX(WndClassName, uCommonResourceID, style, bkgnd) \
static CFrameWndClassInfo& GetWndClassInfo() \
{ \
	static CFrameWndClassInfo wc = \
	{ \
		{ style, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, (HBRUSH)(bkgnd + 1), NULL, WndClassName }, \
		NULL, NULL, 0, _T(""), uCommonResourceID \
	}; \
	return wc; \
}
#define DECLARE_FRAME_WND_SUPERCLASS(WndClassName, OrigWndClassName, uCommonResourceID) \
static CFrameWndClassInfo& GetWndClassInfo() \
{ \
	static CFrameWndClassInfo wc = \
	{ \
		{ NULL, StartWindowProc, \
		  0, 0, NULL, NULL, NULL, NULL, NULL, WndClassName }, \
		OrigWndClassName, NULL, 0, _T(""), uCommonResourceID \
	}; \
	return wc; \
}

// public\sdk\inc\atl21\atlwin.h
#define MESSAGE_RANGE_HANDLER(msgFirst, msgLast, func) \
        if(uMsg >= msgFirst && uMsg <= msgLast) \
        { \
                bHandled = TRUE; \
                lResult = func(uMsg, wParam, lParam, bHandled); \
                if(bHandled) \
                        return TRUE; \
        }

// public\sdk\inc\atl30\atldb.h
#define DBID_IS_BOOKMARK(dbid) \
	(  DBID_USE_GUID(dbid.eKind)  &&  dbid.uGuid.guid  == DBCOL_SPECIALCOL \
	|| DBID_USE_PGUID(dbid.eKind) && *dbid.uGuid.pguid == DBCOL_SPECIALCOL )

// public\sdk\inc\atl30\atlwin.h
#define MESSAGE_RANGE_HANDLER(msgFirst, msgLast, func) \
	if(uMsg >= msgFirst && uMsg <= msgLast) \
	{ \
		bHandled = TRUE; \
		lResult = func(uMsg, wParam, lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}

// public\sdk\inc\cierror.h
#define QUERY_E_INVALIDQUERY             ((HRESULT)0x80041601L)
#define QUERY_E_INVALIDRESTRICTION       ((HRESULT)0x80041602L)
#define QUERY_E_INVALIDSORT              ((HRESULT)0x80041603L)
#define QUERY_E_INVALIDCATEGORIZE        ((HRESULT)0x80041604L)
#define QUERY_E_INVALID_OUTPUT_COLUMN    ((HRESULT)0x80041609L)
#define QPARSE_E_INVALID_LITERAL         ((HRESULT)0x8004166EL)
#define QPARSE_E_WEIGHT_OUT_OF_RANGE     ((HRESULT)0x80041673L)
#define QPARSE_E_INVALID_SORT_ORDER      ((HRESULT)0x80041675L)
#define QPARSE_E_INVALID_GROUPING        ((HRESULT)0x80041677L)
#define QPARSE_E_INVALID_QUERY           ((HRESULT)0x8004167AL)
#define QPARSE_E_INVALID_RANKMETHOD      ((HRESULT)0x8004167BL)
#define CI_INVALID_PARTITION             ((HRESULT)0xC0041802L)
#define CI_INVALID_PRIORITY              ((HRESULT)0xC0041803L)
#define CI_INVALID_INDEX                 ((HRESULT)0xC0041808L)
#define CI_E_WORKID_NOTVALID             ((HRESULT)0x80041813L)

// public\sdk\inc\clusapi.h
#define CLUSTER_GET_MINOR_VERSION( _ver ) (( _ver ) & 0xFFFF )

// public\sdk\inc\commctrl.h
#define TBSTYLE_CHECKGROUP      (TBSTYLE_GROUP | TBSTYLE_CHECK)     // obsolete; use BTNS_CHECKGROUP instead
#define BTNS_CHECKGROUP TBSTYLE_CHECKGROUP  // (TBSTYLE_GROUP | TBSTYLE_CHECK)
#define TB_CHECKBUTTON          (WM_USER + 2)
#define TB_INDETERMINATE        (WM_USER + 5)
#define TB_ISBUTTONCHECKED      (WM_USER + 10)
#define TB_ISBUTTONINDETERMINATE (WM_USER + 13)
#define TB_SETMAXTEXTROWS       (WM_USER + 60)
#define TB_GETMAXSIZE           (WM_USER + 83)  // lParam == LPSIZE
#define RB_MINIMIZEBAND (WM_USER + 30)
#define RB_MAXIMIZEBAND (WM_USER + 31)
#define TTM_SETMAXTIPWIDTH      (WM_USER + 24)
#define TTM_GETMAXTIPWIDTH      (WM_USER + 25)
#define SB_SETMINHEIGHT         (WM_USER+8)
#define TBM_GETRANGEMIN         (WM_USER+1)
#define TBM_GETRANGEMAX         (WM_USER+2)
#define TBM_SETRANGE            (WM_USER+6)
#define TBM_SETRANGEMIN         (WM_USER+7)
#define TBM_SETRANGEMAX         (WM_USER+8)
#define UDM_SETRANGE            (WM_USER+101)
#define UDM_GETRANGE            (WM_USER+102)
#define UDM_SETRANGE32          (WM_USER+111)
#define UDM_GETRANGE32          (WM_USER+112) // wParam & lParam are LPINT
#define PBM_SETRANGE            (WM_USER+1)
#define TabCtrl_SetMinTabWidth(hwnd, x) \
        (int)SNDMSG((hwnd), TCM_SETMINTABWIDTH, 0, x)

// public\sdk\inc\crt\ctype.h
#define __chvalidchk(a,b)       (_pctype[a] & (b))
#define __chvalidchk(a,b)       (_pctype[a] & (b))
#define isalnum(_c)     (MB_CUR_MAX > 1 ? _isctype(_c,_ALPHA|_DIGIT) : __chvalidchk(_c, (_ALPHA|_DIGIT)))
#define isprint(_c)     (MB_CUR_MAX > 1 ? _isctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT) : __chvalidchk(_c, (_BLANK|_PUNCT|_ALPHA|_DIGIT)))
#define isgraph(_c)     (MB_CUR_MAX > 1 ? _isctype(_c,_PUNCT|_ALPHA|_DIGIT) : __chvalidchk(_c, (_PUNCT|_ALPHA|_DIGIT)))

// public\sdk\inc\d3d.h
#define D3DERR_BADMINORVERSION      MAKE_DDHRESULT(701)
#define D3DERR_INVALID_DEVICE   MAKE_DDHRESULT(705)
#define D3DERR_INVALIDCURRENTVIEWPORT   MAKE_DDHRESULT(735)
#define D3DERR_INVALIDPRIMITIVETYPE     MAKE_DDHRESULT(736)
#define D3DERR_INVALIDVERTEXTYPE        MAKE_DDHRESULT(737)
#define D3DERR_INVALIDRAMPTEXTURE       MAKE_DDHRESULT(739)
#define D3DERR_INVALIDVERTEXFORMAT              MAKE_DDHRESULT(2048)
#define D3DERR_INVALIDMATRIX                    MAKE_DDHRESULT(2084)

// public\sdk\inc\d3d8.h
#define D3DERR_INVALIDDEVICE                    MAKE_D3DHRESULT(2155)
#define D3DERR_INVALIDCALL                      MAKE_D3DHRESULT(2156)
#define D3DERR_DRIVERINVALIDCALL                MAKE_D3DHRESULT(2157)

// public\sdk\inc\d3drm.h
#define D3DRMERR_BADMINORVERSION	MAKE_DDHRESULT(792)
#define D3DRMERR_INVALIDLIBRARY         MAKE_DDHRESULT(795)

// public\sdk\inc\d3dxerr.h
#define D3DXERR_INVALIDD3DXDEVICEINDEX    ((HRESULT)0xC8770BBAL)
#define D3DXERR_INVALIDMODE    ((HRESULT)0xC8770BC3L)
#define D3DXERR_INVALIDPARAMETER    ((HRESULT)0xC8770BC4L)
#define D3DXERR_INVALIDFILEFORMAT    ((HRESULT)0xC8770BDAL)

// public\sdk\inc\ddraw.h
#define DDERR_INVALIDCAPS                       MAKE_DDHRESULT( 100 )
#define DDERR_INVALIDMODE                       MAKE_DDHRESULT( 120 )
#define DDERR_INVALIDOBJECT                     MAKE_DDHRESULT( 130 )
#define DDERR_INVALIDSTREAM                     MAKE_DDHRESULT( 521 )
#define DDERR_INVALIDPOSITION                   MAKE_DDHRESULT( 579 )
#define DDERR_INVALIDSURFACETYPE                MAKE_DDHRESULT( 592 )

// public\sdk\inc\dmerror.h
#define DMUS_E_INVALIDPOS               MAKE_DMHRESULTERROR(0x0113)
#define DMUS_E_INVALIDPATCH             MAKE_DMHRESULTERROR(0x0114)
#define DMUS_E_INVALID_EVENT            MAKE_DMHRESULTERROR(0x013F)
#define DMUS_E_INVALID_BAND             MAKE_DMHRESULTERROR(0x0152)
#define DMUS_E_INVALID_TRACK_HDR        MAKE_DMHRESULTERROR(0x0157)
#define DMUS_E_INVALID_TOOL_HDR         MAKE_DMHRESULTERROR(0x0158)
#define DMUS_E_INVALIDFILE              MAKE_DMHRESULTERROR(0x0200)
#define DMUS_E_OUT_OF_RANGE             MAKE_DMHRESULTERROR(0x0202)
#define DMUS_E_SCRIPT_INVALID_FILE           MAKE_DMHRESULTERROR(0x0218)
#define DMUS_E_INVALID_SCRIPTTRACK           MAKE_DMHRESULTERROR(0x0219)
#define DMUS_E_INVALID_SEGMENTTRIGGERTRACK   MAKE_DMHRESULTERROR(0x0220)
#define DMUS_E_INVALID_LYRICSTRACK           MAKE_DMHRESULTERROR(0x0221)
#define DMUS_E_INVALID_PARAMCONTROLTRACK     MAKE_DMHRESULTERROR(0x0222)
#define DMUS_E_AUDIOPATHS_NOT_VALID     MAKE_DMHRESULTERROR(0x0226)
#define DMUS_E_INVALIDCHUNK     MAKE_DMHRESULTERROR(0x022D)

// public\sdk\inc\dplay.h
#define DPERR_INVALIDOBJECT             MAKE_DPHRESULT( 130 )
#define DPERR_INVALIDPLAYER             MAKE_DPHRESULT( 150 )
#define DPERR_INVALIDGROUP             	MAKE_DPHRESULT( 155 )
#define DPERR_INVALIDPRIORITY           MAKE_DPHRESULT( 390 )
#define DPERR_INVALIDINTERFACE          MAKE_DPHRESULT( 1030 )

// public\sdk\inc\dplay8.h
#define DPNERR_HOSTTERMINATEDSESSION	MAKE_DPNHRESULT( 0x270 )
#define DPNERR_INVALIDADDRESSFORMAT		MAKE_DPNHRESULT( 0x290 )
#define DPNERR_INVALIDAPPLICATION		MAKE_DPNHRESULT( 0x300 )
#define DPNERR_INVALIDCOMMAND			MAKE_DPNHRESULT( 0x310 )
#define DPNERR_INVALIDDEVICEADDRESS		MAKE_DPNHRESULT( 0x320 )
#define DPNERR_INVALIDGROUP			 	MAKE_DPNHRESULT( 0x350 )
#define DPNERR_INVALIDHANDLE			MAKE_DPNHRESULT( 0x360 )
#define DPNERR_INVALIDHOSTADDRESS		MAKE_DPNHRESULT( 0x370 )
#define DPNERR_INVALIDINSTANCE			MAKE_DPNHRESULT( 0x380 )
#define DPNERR_INVALIDINTERFACE			MAKE_DPNHRESULT( 0x390 )
#define DPNERR_INVALIDOBJECT			MAKE_DPNHRESULT( 0x400 )
#define DPNERR_INVALIDPLAYER			MAKE_DPNHRESULT( 0x420 )
#define DPNERR_INVALIDPRIORITY			MAKE_DPNHRESULT( 0x430 )
#define DPNERR_INVALIDSTRING			MAKE_DPNHRESULT( 0x440 )
#define DPNERR_INVALIDURL				MAKE_DPNHRESULT( 0x450 )
#define	DPNERR_INVALIDVERSION			MAKE_DPNHRESULT( 0x460 )

// public\sdk\inc\dsadmin.h
#define DSA_NOTIFY_ALL      (DSA_NOTIFY_DEL|DSA_NOTIFY_REN|DSA_NOTIFY_MOV|DSA_NOTIFY_PROP)

// public\sdk\inc\dsdmobse.h
#define RELEASE(x) { if (x) (x)->Release(); x = NULL; }

// public\sdk\inc\dsound.h
#define DSERR_INVALIDCALL               MAKE_DSHRESULT(50)

// public\sdk\inc\dvoice.h
#define DVERR_INVALIDOBJECT             MAKE_DVHRESULT( 0x0082 )
#define DVERR_INVALIDPLAYER             MAKE_DVHRESULT( 0x0087 )
#define DVERR_INVALIDGROUP              MAKE_DVHRESULT( 0x0091 )
#define DVERR_INVALIDHANDLE             MAKE_DVHRESULT( 0x0096 )
#define DVERR_INVALIDTARGET             MAKE_DVHRESULT( 0x0170 )
#define DVERR_INVALIDDEVICE             MAKE_DVHRESULT( 0x017C )

// public\sdk\inc\dxterror.h
#define DXTERR_COPYRIGHT_IS_INVALID   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_DXTRANS, 4)
#define DXTERR_INVALID_BOUNDS   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_DXTRANS, 5)

// public\sdk\inc\esebkmsg.h
#define hrInvalidParam                   ((HRESULT)0xC7FF07D1L)
#define hrInvalidHandle                  ((HRESULT)0xC7FF07D3L)
#define hrInvalidRecips                  ((HRESULT)0xC7FF07D6L)
#define hrInvalidDestinationNameReturnedByServer ((HRESULT)0xC7FF0BC7L)
#define hrInvalidCallSequence            ((HRESULT)0xC7FF0FA4L)
#define hrFLDNullKey                     ((HRESULT)0x88000192L)
#define hrInvalidBackupSequence          ((HRESULT)0xC8000209L)
#define hrInvalidBackup                  ((HRESULT)0xC800020EL)
#define hrTermInProgress                 ((HRESULT)0xC80003E8L)
#define hrInvalidName                    ((HRESULT)0xC80003EAL)
#define hrInvalidParameter               ((HRESULT)0xC80003EBL)
#define hrColumnNull                     ((HRESULT)0x880003ECL)
#define hrInvalidPath                    ((HRESULT)0xC80003FFL)
#define hrInvalidFilename                ((HRESULT)0xC8000414L)
#define hrInvalidBookmark                ((HRESULT)0xC8000415L)
#define hrInvalidCountry                 ((HRESULT)0xC8000425L)
#define hrInvalidLanguageId              ((HRESULT)0xC8000426L)
#define hrColumnSetNull                  ((HRESULT)0x8800042CL)
#define hrInvalidSesid                   ((HRESULT)0xC8000450L)
#define hrDensityInvalid                 ((HRESULT)0xC800051BL)
#define hrInvalidObject                  ((HRESULT)0xC8000524L)
#define hrIndexInvalidDef                ((HRESULT)0xC800057EL)
#define hrNullInvalid                    ((HRESULT)0xC80005E0L)
#define hrInvalidColumnType              ((HRESULT)0xC80005E7L)
#define hrColumnMaxTruncated             ((HRESULT)0x880005E8L)
#define hrTaggedNotNULL                  ((HRESULT)0xC80005EAL)
#define hrInvalidOnSort                  ((HRESULT)0xC80006A6L)
#define hrInvalidOperation               ((HRESULT)0xC8000772L)

// public\sdk\inc\esent.h
#define JET_wrnColumnSkipped				1531 /* Column value(s) not returned because the corresponding column id or itagSequence requested for enumeration was null */

// public\sdk\inc\gl\glaux.h
#define AUX_WIND_IS_INDEX(x)    (((x) & AUX_INDEX) != 0)
#define AUX_WIND_IS_SINGLE(x)   (((x) & AUX_DOUBLE) == 0)
#define AUX_WIND_IS_DOUBLE(x)   (((x) & AUX_DOUBLE) != 0)
#define AUX_WIND_HAS_ACCUM(x)   (((x) & AUX_ACCUM) != 0)
#define AUX_WIND_HAS_ALPHA(x)   (((x) & AUX_ALPHA) != 0)
#define AUX_WIND_HAS_DEPTH(x)   (((x) & (AUX_DEPTH24 | AUX_DEPTH16)) != 0)
#define AUX_WIND_HAS_STENCIL(x) (((x) & AUX_STENCIL) != 0)

// public\sdk\inc\intshcut.h
#define IS_E_EXEC_FAILED            MAKE_SCODE(SEVERITY_ERROR, FACILITY_ITF, 0x2002)

// public\sdk\inc\kerbcon.h
#define KERB_IS_MS_PRINCIPAL(_x_) (((_x_) <= KRB_NT_MS_PRINCIPAL) || ((_x_) >= KRB_NT_ENTERPRISE_PRINCIPAL))

// public\sdk\inc\ks.h
#define DENY_USERMODE_ACCESS( pIrp, CompleteRequest ) \
if ( pIrp->RequestorMode != KernelMode ) { \
    pIrp->IoStatus.Information = 0; \
    pIrp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST; \
    if ( CompleteRequest ) IoCompleteRequest ( pIrp, IO_NO_INCREMENT ); \
    return STATUS_INVALID_DEVICE_REQUEST; \
}

// public\sdk\inc\ksdebug.h
#define REMIND(str) __FILE__ "(" QQUOTE(__LINE__) ") : " str

// public\sdk\inc\ksmedia.h
#define IS_COMPATIBLE_USBAUDIO_MID(guid)\
    (((guid)->Data1 >= 0x4e1cecd2) &&\
    ((guid)->Data1 < 0x4e1cecd2 + 0xffff) &&\
    ((guid)->Data2 == 0x1679) &&\
    ((guid)->Data3 == 0x463b) &&\
    ((guid)->Data4[0] == 0xa7) &&\
    ((guid)->Data4[1] == 0x2f) &&\
    ((guid)->Data4[2] == 0xa5) &&\
    ((guid)->Data4[3] == 0xbf) &&\
    ((guid)->Data4[4] == 0x64) &&\
    ((guid)->Data4[5] == 0xc8) &&\
    ((guid)->Data4[6] == 0x6e) &&\
    ((guid)->Data4[7] == 0xba))
#define IS_COMPATIBLE_USBAUDIO_PID(guid)\
    (((guid)->Data1 >= 0xabcc5a5e) &&\
    ((guid)->Data1 < 0xabcc5a5e + 0xffff) &&\
    ((guid)->Data2 == 0xc263) &&\
    ((guid)->Data3 == 0x463b) &&\
    ((guid)->Data4[0] == 0xa7) &&\
    ((guid)->Data4[1] == 0x2f) &&\
    ((guid)->Data4[2] == 0xa5) &&\
    ((guid)->Data4[3] == 0xbf) &&\
    ((guid)->Data4[4] == 0x64) &&\
    ((guid)->Data4[5] == 0xc8) &&\
    ((guid)->Data4[6] == 0x6e) &&\
    ((guid)->Data4[7] == 0xba))
#define INIT_USB_TERMINAL(guid, id)\
{\
    (guid)->Data1 = 0xDFF219E0 + (USHORT)(id);\
    (guid)->Data2 = 0xF70F;\
    (guid)->Data3 = 0x11D0;\
    (guid)->Data4[0] = 0xb9;\
    (guid)->Data4[1] = 0x17;\
    (guid)->Data4[2] = 0x00;\
    (guid)->Data4[3] = 0xa0;\
    (guid)->Data4[4] = 0xc9;\
    (guid)->Data4[5] = 0x22;\
    (guid)->Data4[6] = 0x31;\
    (guid)->Data4[7] = 0x96;\
}
#define EXTRACT_USB_TERMINAL(guid)\
    (USHORT)((guid)->Data1 - 0xDFF219E0)
#define IS_COMPATIBLE_MMREG_MID(guid)\
    (((guid)->Data1 >= 0xd5a47fa7) &&\
    ((guid)->Data1 < 0xd5a47fa7 + 0xffff) &&\
    ((guid)->Data2 == 0x6d98) &&\
    ((guid)->Data3 == 0x11d1) &&\
    ((guid)->Data4[0] == 0xa2) &&\
    ((guid)->Data4[1] == 0x1a) &&\
    ((guid)->Data4[2] == 0x00) &&\
    ((guid)->Data4[3] == 0xa0) &&\
    ((guid)->Data4[4] == 0xc9) &&\
    ((guid)->Data4[5] == 0x22) &&\
    ((guid)->Data4[6] == 0x31) &&\
    ((guid)->Data4[7] == 0x96))
#define IS_COMPATIBLE_MMREG_PID(guid)\
    (((guid)->Data1 >= 0xe36dc2ac) &&\
    ((guid)->Data1 < 0xe36dc2ac + 0xffff) &&\
    ((guid)->Data2 == 0x6d9a) &&\
    ((guid)->Data3 == 0x11d1) &&\
    ((guid)->Data4[0] == 0xa2) &&\
    ((guid)->Data4[1] == 0x1a) &&\
    ((guid)->Data4[2] == 0x00) &&\
    ((guid)->Data4[3] == 0xa0) &&\
    ((guid)->Data4[4] == 0xc9) &&\
    ((guid)->Data4[5] == 0x22) &&\
    ((guid)->Data4[6] == 0x31) &&\
    ((guid)->Data4[7] == 0x96))

// public\sdk\inc\mfc42\afxctl.h
#define DISP_PROPERTY_STOCK(theClass, szExternalName, dispid, pfnGet, pfnSet, vtPropType) \
	{ _T(szExternalName), dispid, NULL, vtPropType, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnGet, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnSet, 0, afxDispStock }, \

// public\sdk\inc\mfc42\afxdisp.h
#define DISP_PROPERTY_EX(theClass, szExternalName, pfnGet, pfnSet, vtPropType) \
	{ _T(szExternalName), DISPID_UNKNOWN, NULL, vtPropType, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnGet, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnSet, 0, afxDispCustom }, \
#define DISP_PROPERTY_EX_ID(theClass, szExternalName, dispid, pfnGet, pfnSet, vtPropType) \
	{ _T(szExternalName), dispid, NULL, vtPropType, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnGet, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnSet, 0, afxDispCustom }, \
#define ON_EVENT_RANGE(theClass, idFirst, idLast, dispid, pfnHandler, vtsParams) \
	{ _T(""), dispid, vtsParams, VT_BOOL, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnHandler, (AFX_PMSG)0, 0, \
		afxDispCustom, idFirst, idLast }, \
#define ON_PROPNOTIFY_RANGE(theClass, idFirst, idLast, dispid, pfnRequest, pfnChanged) \
	{ _T(""), dispid, VTS_NONE, VT_VOID, \
		(AFX_PMSG)(BOOL (CCmdTarget::*)(UINT, BOOL*))&pfnRequest, \
		(AFX_PMSG)(BOOL (CCmdTarget::*)(UINT))&pfnChanged, \
		1, afxDispCustom, idFirst, idLast }, \

// public\sdk\inc\mfc42\afxext.h
#define TBBS_CHECKGROUP (TBBS_GROUP|TBBS_CHECKBOX)  // normal use of TBBS_GROUP

// public\sdk\inc\mfc42\afxmsg_.h
#define ON_WM_GETMINMAXINFO() \
	{ WM_GETMINMAXINFO, 0, 0, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(MINMAXINFO*))&OnGetMinMaxInfo },

// public\sdk\inc\mfc42\afxpriv.h
#define IS_COMMAND_ID(nID)  ((nID) & 0x8000)
#define ASSERT_VALID_IDR(nIDR) ASSERT((nIDR) != 0 && (nIDR) < 0x8000)

// public\sdk\inc\mmc.h
#define IS_SPECIAL_COOKIE(c)     (((c)          >= SPECIAL_COOKIE_MIN) && ((c)          <= SPECIAL_COOKIE_MAX))

// public\sdk\inc\mmreg.h
#define IS_COMPATIBLE_MMREG_MID(guid)\
    (((guid)->Data1 >= 0xd5a47fa7) &&\
    ((guid)->Data1 < 0xd5a47fa7 + 0xffff) &&\
    ((guid)->Data2 == 0x6d98) &&\
    ((guid)->Data3 == 0x11d1) &&\
    ((guid)->Data4[0] == 0xa2) &&\
    ((guid)->Data4[1] == 0x1a) &&\
    ((guid)->Data4[2] == 0x00) &&\
    ((guid)->Data4[3] == 0xa0) &&\
    ((guid)->Data4[4] == 0xc9) &&\
    ((guid)->Data4[5] == 0x22) &&\
    ((guid)->Data4[6] == 0x31) &&\
    ((guid)->Data4[7] == 0x96))
#define IS_COMPATIBLE_MMREG_PID(guid)\
    (((guid)->Data1 >= 0xe36dc2ac) &&\
    ((guid)->Data1 < 0xe36dc2ac + 0xffff) &&\
    ((guid)->Data2 == 0x6d9a) &&\
    ((guid)->Data3 == 0x11d1) &&\
    ((guid)->Data4[0] == 0xa2) &&\
    ((guid)->Data4[1] == 0x1a) &&\
    ((guid)->Data4[2] == 0x00) &&\
    ((guid)->Data4[3] == 0xa0) &&\
    ((guid)->Data4[4] == 0xc9) &&\
    ((guid)->Data4[5] == 0x22) &&\
    ((guid)->Data4[6] == 0x31) &&\
    ((guid)->Data4[7] == 0x96))

// public\sdk\inc\mprapi.h
#define RASPRIV_CallbackType (RASPRIV_AdminSetCallback \
                              | RASPRIV_CallerSetCallback \
                              | RASPRIV_NoCallback)

// public\sdk\inc\msctf.h
#define TF_E_NOTOWNEDRANGE   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0502)
#define TF_E_INVALIDVIEW     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0505)
#define TF_E_RANGE_NOT_COVERED MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0507)
#define TF_E_INVALIDPOS      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0200)

// public\sdk\inc\npapi.h
#define WNNC_CF_MAXIMUM (WNNC_CF_DEFAULT | CONNECT_DEFERRED | CONNECT_COMMANDLINE | CONNECT_CMD_SAVECRED)

// public\sdk\inc\ntdsbmsg.h
#define hrInvalidParam                   ((HRESULT)0xC7FF0001L)
#define hrInvalidHandle                  ((HRESULT)0xC7FF0003L)
#define hrInvalidRecips                  ((HRESULT)0xC7FF0006L)
#define hrFLDNullKey                     ((HRESULT)0x88000192L)
#define hrInvalidBackupSequence          ((HRESULT)0xC8000209L)
#define hrInvalidBackup                  ((HRESULT)0xC800020EL)
#define hrTermInProgress                 ((HRESULT)0xC80003E8L)
#define hrInvalidName                    ((HRESULT)0xC80003EAL)
#define hrInvalidParameter               ((HRESULT)0xC80003EBL)
#define hrColumnNull                     ((HRESULT)0x880003ECL)
#define hrInvalidPath                    ((HRESULT)0xC80003FFL)
#define hrInvalidFilename                ((HRESULT)0xC8000414L)
#define hrInvalidBookmark                ((HRESULT)0xC8000415L)
#define hrInvalidCountry                 ((HRESULT)0xC8000425L)
#define hrInvalidLanguageId              ((HRESULT)0xC8000426L)
#define hrColumnSetNull                  ((HRESULT)0x8800042CL)
#define hrInvalidSesid                   ((HRESULT)0xC8000450L)
#define hrDensityInvalid                 ((HRESULT)0xC800051BL)
#define hrInvalidObject                  ((HRESULT)0xC8000524L)
#define hrIndexInvalidDef                ((HRESULT)0xC800057EL)
#define hrNullInvalid                    ((HRESULT)0xC80005E0L)
#define hrInvalidColumnType              ((HRESULT)0xC80005E7L)
#define hrColumnMaxTruncated             ((HRESULT)0x880005E8L)
#define hrTaggedNotNULL                  ((HRESULT)0xC80005EAL)
#define hrInvalidOnSort                  ((HRESULT)0xC80006A6L)
#define hrInvalidOperation               ((HRESULT)0xC8000772L)

// public\sdk\inc\ntia64.h
#define IS_DBR_RDWR(DBR)        (((DBR) & DBR_RDWR) == DBR_RDWR)
#define IS_DBR_WR(DBR)          (((DBR) & DBR_WR)   == DBR_WR)
#define IS_IBR_EX(IBR)          (((IBR) & IBR_EX)   == IBR_EX)
#define DBR_ACTIVE(DBR)         (IS_DBR_RDWR(DBR) || IS_DBR_WR(DBR))

// public\sdk\inc\ntioapi.h
#define IsReparseTagValid(_tag) (                               \
                  !((_tag) & ~IO_REPARSE_TAG_VALID_VALUES) &&   \
                  ((_tag) > IO_REPARSE_TAG_RESERVED_RANGE)      \
                 )

// public\sdk\inc\ntmsapi.h
#define NTMS_IS_NULLGUID(id) ((id.Data1==0)&&(id.Data2==0)&&(id.Data3==0)&&\
                                                          (id.Data4[0]==0)&&(id.Data4[1]==0)&&(id.Data4[2]==0)&&\
                                                          (id.Data4[3]==0)&&(id.Data4[4]==0)&&(id.Data4[5]==0)&&\
                                                          (id.Data4[6]==0)&&(id.Data4[7]==0))

// public\sdk\inc\ntrtlpath.h
#define RTL_IS_DOS_PATH_SEPARATOR(ch_) ((ch_) == '\\' || ((ch_) == '/'))

// public\sdk\inc\nturtl.h
#define RtlDisAssociatePerThreadCurdir() \
        NtCurrentTeb()->NtTib.SubSystemTib = NULL;
#define RtlAnyActivationContextDataAvailable() \
    ((NtCurrentTeb()->ActivationContextStack != NULL) || \
     (NtCurrentPeb()->ActivationContextData != NULL) || \
     (NtCurrentPeb()->SystemDefaultActivationContextData != NULL))
#define RtlIsProcessDefaultActivationContextActive() ((NtCurrentTeb()->ActivationContextStack == NULL) || RtlIsActivationContextActive(NULL))

// public\sdk\inc\oledberr.h
#define DB_E_NONCONTIGUOUSRANGE          ((HRESULT)0x80040E2BL)
#define DB_E_INVALIDTRANSITION           ((HRESULT)0x80040E2CL)
#define DB_E_INVALID                     ((HRESULT)0x80040E45L)
#define DB_E_NULLACCESSORNOTSUPPORTED    ((HRESULT)0x80040E49L)
#define DB_E_MAXPENDCHANGESEXCEEDED      ((HRESULT)0x80040E54L)
#define MD_E_INVALIDAXIS                 ((HRESULT)0x80040E63L)
#define MD_E_INVALIDCELLRANGE            ((HRESULT)0x80040E64L)
#define STG_E_INVALIDHEADER              ((HRESULT)0x800300FBL)
#define STG_E_INVALIDNAME                ((HRESULT)0x800300FCL)

// public\sdk\inc\oledlg.h
#define OLEUI_PSERR_GETCLIPBOARDFAILED      (OLEUI_ERR_STANDARDMAX+4)

// public\sdk\inc\pstore.h
#define PST_E_INVALID_HANDLE            _HRESULT_TYPEDEF_(0x800C0003L)
#define PST_E_INVALID_RULESET           _HRESULT_TYPEDEF_(0x800C0006L)
#define PST_E_INVALID_STRING            _HRESULT_TYPEDEF_(0x800C0013L)

// public\sdk\inc\pwin16.h
#define MPostWM_DDE_TERMINATE(hTo, hFrom) \
        PostMessage(hTo, WM_DDE_TERMINATE, (WPARAM)hFrom, 0)

// public\sdk\inc\pwin32.h
#define MPostWM_DDE_TERMINATE(hTo, hFrom) \
        PostMessage(hTo, WM_DDE_TERMINATE, (WPARAM)hFrom, 0L)

// public\sdk\inc\rassapi.h
#define RASPRIV_CallbackType (RASPRIV_AdminSetCallback \
                              | RASPRIV_CallerSetCallback \
                              | RASPRIV_NoCallback)

// public\sdk\inc\richedit.h
#define EM_FORMATRANGE			(WM_USER + 57)
#define EM_STREAMIN				(WM_USER + 73)
#define EM_GETTEXTRANGE			(WM_USER + 75)

// public\sdk\inc\rtcerr.h
#define RTC_E_INVALID_SIP_URL            ((HRESULT)0x80EE0012L)
#define RTC_E_INVALID_PROXY_ADDRESS      ((HRESULT)0x80EE0016L)
#define RTC_E_MEDIA_NEED_TERMINAL        ((HRESULT)0x80EE0020L)
#define RTC_E_INVALID_SESSION_TYPE       ((HRESULT)0x80EE0029L)
#define RTC_E_INVALID_PROFILE            ((HRESULT)0x80EE002EL)
#define RTC_E_PROFILE_INVALID_SERVER_PROTOCOL ((HRESULT)0x80EE0037L)
#define RTC_E_PROFILE_INVALID_SERVER_AUTHMETHOD ((HRESULT)0x80EE0038L)
#define RTC_E_PROFILE_INVALID_SERVER_ROLE ((HRESULT)0x80EE0039L)
#define RTC_E_PROFILE_INVALID_SESSION    ((HRESULT)0x80EE003BL)
#define RTC_E_PROFILE_INVALID_SESSION_PARTY ((HRESULT)0x80EE003CL)
#define RTC_E_PROFILE_INVALID_SESSION_TYPE ((HRESULT)0x80EE003DL)
#define RTC_E_PROFILE_INVALID_ACCESSCONTROL_SIGNATURE ((HRESULT)0x80EE0041L)
#define RTC_E_STATUS_REQUEST_TERMINATED  ((HRESULT)0x80EF01E7L)

// public\sdk\inc\rtutils.h
#define RTASSERT(exp) \
        if (!(exp)) \
            RouterAssert(#exp, __FILE__, __LINE__, NULL)

// public\sdk\inc\snmp.h
#define ASN_NULL                    (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x05)

// public\sdk\inc\spdebug.h
#define SPDBG_DEBUG_SERVER_ON_START()           \
    {                                           \
        if (PSpDebug()->DebugServerOnStart())   \
        {                                       \
            if (MessageBox(                     \
                    GetDesktopWindow(),         \
                    _T("Attach Debugger to the SAPI Server process?"),   \
                    _T("SAPI"),                 \
                    MB_YESNO) == IDYES)         \
            {                                   \
                USES_CONVERSION;                \
                TCHAR szCommand[MAX_PATH + 1];  \
                wsprintf(                       \
                    szCommand,                  \
                    _T("msdev -p %d"),          \
                    GetCurrentProcessId());     \
                system(T2A(szCommand));         \
            }                                   \
        }                                       \
    }
#define SPDBG_DEBUG_CLIENT_ON_START()           \
    {                                           \
        if (PSpDebug()->DebugClientOnStart())   \
        {                                       \
            TCHAR szModule[MAX_PATH + 1];       \
            szModule[0] = '\0';                 \
            TCHAR * pszSapiServer =             \
                _T("sapisvr.exe");              \
            GetModuleFileName(                  \
                NULL,                           \
                szModule,                       \
                MAX_PATH);                      \
            if ((_tcslen(szModule) <=           \
                    _tcslen(pszSapiServer) ||   \
                 _tcsicmp(                      \
                    szModule +                  \
                        _tcslen(szModule) -     \
                        _tcslen(pszSapiServer), \
                    pszSapiServer) != 0) &&     \
                MessageBox(                     \
                    GetDesktopWindow(),         \
                    _T("Attach Debugger to the SAPI Client process?"),   \
                    _T("SAPI"),                 \
                    MB_YESNO) == IDYES)         \
            {                                   \
                USES_CONVERSION;                \
                TCHAR szCommand[MAX_PATH + 1];  \
                wsprintf(                       \
                    szCommand,                  \
                    _T("msdev -p %d"),          \
                    GetCurrentProcessId());     \
                system(T2A(szCommand));         \
            }                                   \
        }                                       \
    }

// public\sdk\inc\stdclass.hxx
#define IMPLEMENT_CLASSFACTORY(cls,ctrargs)                     \
                                                                \
STDMETHODIMP cls##CF::_CreateInstance(                          \
                            IUnknown* punkOuter,                \
                            REFIID riid,                    	\
                            void** ppv)                         \
{                                                               \
    cls* pInstance;                                             \
    HRESULT hr;                                             	\
                                                                \
    pInstance = new cls ctrargs;                    		\
    if (pInstance == NULL)                                      \
    {                                                           \
        hr = ResultFromScode(E_OUTOFMEMORY);            	\
    }                                                           \
    else                            				\
    {                               				\
	__try                       				\
	{                           				\
            hr = pInstance->InitInstance (          		\
                    punkOuter,          			\
		    riid,               			\
                    ppv );              			\
            if ( FAILED(hr) )                			\
            {                           			\
	delete pInstance;               		\
            }                           			\
	}                           				\
	__except(EXCEPTION_EXECUTE_HANDLER)     		\
	{                           				\
            delete pInstance;					\
            hr = HRESULT_FROM_NT(GetExceptionCode());		\
	}                           				\
    }                                                           \
    return hr;                                      		\
}

// public\sdk\inc\strsafe.h
#define SUCCEEDED(hr)  ((HRESULT)(hr) >= 0)
#define FAILED(hr)  ((HRESULT)(hr) < 0)
#define STRSAFE_E_INVALID_PARAMETER         ((HRESULT)0x80070057L)  // 0x57 =  87L = ERROR_INVALID_PARAMETER
#define STRSAFE_E_END_OF_FILE               ((HRESULT)0x80070026L)  // 0x26 =  38L = ERROR_HANDLE_EOF

// public\sdk\inc\subsmgr.h
#define INET_E_AGENT_MAX_SIZE_EXCEEDED       _HRESULT_TYPEDEF_(0x800C0F80L)
#define INET_E_SCHEDULED_EXCLUDE_RANGE       _HRESULT_TYPEDEF_(0x800C0F87L)

// public\sdk\inc\svcguid.h
#define IS_SVCID_DNS(_g) \
             ( (((_g)->Data1) == 0x00090035) && \
               (((_g)->Data2) == 0) &&          \
               (((_g)->Data4[0]) == 0xC0) &&    \
               (((_g)->Data4[1]) == 0) &&       \
               (((_g)->Data4[2]) == 0) &&       \
               (((_g)->Data4[3]) == 0) &&       \
               (((_g)->Data4[4]) == 0) &&       \
               (((_g)->Data4[5]) == 0) &&       \
               (((_g)->Data4[6]) == 0) &&       \
               (((_g)->Data4[7]) == 0x46) )
#define IS_SVCID_TCP(_g) \
             ( ((((_g)->Data1) & 0xFFFF0000) == 0x00090000) && \
               (((_g)->Data2) == 0) &&                       \
               (((_g)->Data4[0]) == 0xC0) &&                 \
               (((_g)->Data4[1]) == 0) &&                    \
               (((_g)->Data4[2]) == 0) &&                    \
               (((_g)->Data4[3]) == 0) &&                    \
               (((_g)->Data4[4]) == 0) &&                    \
               (((_g)->Data4[5]) == 0) &&                    \
               (((_g)->Data4[6]) == 0) &&                    \
               (((_g)->Data4[7]) == 0x46) )
#define IS_SVCID_UDP(_g) \
             ( ((((_g)->Data1) & 0xFFFF0000) == 0x000A0000) && \
               (((_g)->Data2) == 0) &&                       \
               (((_g)->Data4[0]) == 0xC0) &&                 \
               (((_g)->Data4[1]) == 0) &&                    \
               (((_g)->Data4[2]) == 0) &&                    \
               (((_g)->Data4[3]) == 0) &&                    \
               (((_g)->Data4[4]) == 0) &&                    \
               (((_g)->Data4[5]) == 0) &&                    \
               (((_g)->Data4[6]) == 0) &&                    \
               (((_g)->Data4[7]) == 0x46) )
#define IS_SVCID_NETWARE(_g) \
             ( ((((_g)->Data1) & 0xFFFF0000) == 0x000B0000) && \
               (((_g)->Data2) == 0) &&                       \
               (((_g)->Data3) == 0) &&                       \
               (((_g)->Data4[0]) == 0xC0) &&                 \
               (((_g)->Data4[1]) == 0) &&                    \
               (((_g)->Data4[2]) == 0) &&                    \
               (((_g)->Data4[3]) == 0) &&                    \
               (((_g)->Data4[4]) == 0) &&                    \
               (((_g)->Data4[5]) == 0) &&                    \
               (((_g)->Data4[6]) == 0) &&                    \
               (((_g)->Data4[7]) == 0x46) )

// public\sdk\inc\tapi3err.h
#define TAPI_E_INVALIDMEDIATYPE          ((HRESULT)0x80040004L)
#define TAPI_E_INVALIDTERMINAL           ((HRESULT)0x8004003BL)
#define TAPI_E_INVALIDTERMINALCLASS      ((HRESULT)0x8004003CL)
#define TAPI_E_MAXSTREAMS                ((HRESULT)0x8004003EL)
#define TAPI_E_NOTERMINALSELECTED        ((HRESULT)0x8004003FL)
#define TAPI_E_TERMINALINUSE             ((HRESULT)0x80040040L)
#define TAPI_E_MAXTERMINALS              ((HRESULT)0x80040042L)
#define TAPI_E_INVALIDSTREAM             ((HRESULT)0x80040043L)
#define TAPI_E_TERMINAL_PEER             ((HRESULT)0x8004004EL)

// public\sdk\inc\textstor.h
#define TS_E_INVALIDPOS      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0200)

// public\sdk\inc\transact.h
#define BOID_NULL (*((BOID*)(&IID_NULL)))

// public\sdk\inc\tstr.h
#define IS_PATH_SEPARATOR(ch) ((ch == TCHAR_BACKSLASH) || (ch == TCHAR_FWDSLASH))
#define IS_NON_ZERO_DIGIT(c)    (((c) >= MAKE_TCHAR('1')) && ((c) <= MAKE_TCHAR('9')))

// public\sdk\inc\unimodem.h
    #define IS_VALID_RAWDIAGNOSTICS_HDR(_praw_diagnostics_hdr)              \
            ((_praw_diagnostics_hdr)->dwSig==LDSIG_RAWDIAGNOSTICS)
    #define IS_VALID_PARSEDDIAGNOSTICS_HDR(_pparsed_diagnostics_hdr)        \
            ((_pparsed_diagnostics_hdr)->dwSig==LDSIG_PARSEDDIAGNOSTICS)

// public\sdk\inc\upnp.h
#define UPNP_E_INVALID_ACTION            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0207)
#define UPNP_E_INVALID_ARGUMENTS         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0208)
#define UPNP_E_INVALID_VARIABLE          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0213)
#define UPNP_E_INVALID_DOCUMENT          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0500)

// public\sdk\inc\upnphost.h
#define UPNP_E_INVALID_DESCRIPTION           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xA023)
#define UPNP_E_INVALID_SERVICE               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xA024)
#define UPNP_E_INVALID_ICON                  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xA025)
#define UPNP_E_INVALID_XML                   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xA026)
#define UPNP_E_INVALID_ROOT_NAMESPACE        MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xA027)

// public\sdk\inc\urlmki.h
#define INET_E_INVALID_URL               _HRESULT_TYPEDEF_(0x800C0002L)
#define INET_E_NO_VALID_MEDIA            _HRESULT_TYPEDEF_(0x800C000AL)
#define INET_E_INVALID_REQUEST           _HRESULT_TYPEDEF_(0x800C000CL)
#define INET_E_TERMINATED_BIND           _HRESULT_TYPEDEF_(0x800C0018L)

// public\sdk\inc\urlmon.h
#define INET_E_INVALID_URL               _HRESULT_TYPEDEF_(0x800C0002L)
#define INET_E_NO_VALID_MEDIA            _HRESULT_TYPEDEF_(0x800C000AL)
#define INET_E_INVALID_REQUEST           _HRESULT_TYPEDEF_(0x800C000CL)
#define INET_E_TERMINATED_BIND           _HRESULT_TYPEDEF_(0x800C0018L)

// public\sdk\inc\vfw.h
#define MCIWNDM_VALIDATEMEDIA   (WM_USER + 121)

// public\sdk\inc\vfwmsgs.h
#define VFW_E_INVALIDMEDIATYPE           ((HRESULT)0x80040200L)
#define VFW_E_INVALIDSUBTYPE             ((HRESULT)0x80040201L)
#define VFW_E_INVALID_FILE_FORMAT        ((HRESULT)0x8004022FL)
#define VFW_E_ENUM_OUT_OF_RANGE          ((HRESULT)0x80040230L)
#define VFW_E_INVALID_FILE_VERSION       ((HRESULT)0x80040244L)
#define VFW_E_INVALID_CLSID              ((HRESULT)0x80040247L)
#define VFW_E_INVALID_MEDIA_TYPE         ((HRESULT)0x80040248L)
#define VFW_E_DVD_INVALIDDOMAIN          ((HRESULT)0x80040277L)
#define VFW_E_DVD_INVALID_DISC           ((HRESULT)0x80040291L)

// public\sdk\inc\wdm.h
#define ExInitializeFastMutex(_FastMutex)                            \
    (_FastMutex)->Count = 1;                                         \
    (_FastMutex)->Owner = NULL;                                      \
    (_FastMutex)->Contention = 0;                                    \
    KeInitializeEvent(&(_FastMutex)->Event,                          \
                      SynchronizationEvent,                          \
                      FALSE);

// public\sdk\inc\wincred.h
#define CREDUIP_IS_DOWNGRADE_ERROR( _Status ) ( \
        (_Status) == ERROR_DOWNGRADE_DETECTED || \
        (_Status) == HRESULT_FROM_WIN32( ERROR_DOWNGRADE_DETECTED ) || \
        (_Status) == STATUS_DOWNGRADE_DETECTED || \
        (_Status) == HRESULT_FROM_NT( STATUS_DOWNGRADE_DETECTED ) \
)

// public\sdk\inc\wincrui.h
#define Credential_SetUserNameMaxChars(hwnd, maxChars)\
    (BOOL) SendMessage(hwnd, CRM_SETUSERNAMEMAX, (WPARAM)(maxChars), 0)
#define Credential_GetUserName(hwnd, pszUserName, maxChars)\
    (BOOL) SendMessage(hwnd, CRM_GETUSERNAME, WPARAM(maxChars),\
                       (LPARAM)(pszUserName))
#define Credential_CheckSave(hwnd, enabled)\
    (BOOL) SendMessage(hwnd, CRM_SETCHECK, CREDUI_CONTROL_SAVE, enabled)
#define Credential_IsSaveChecked(hwnd)\
    (BOOL) SendMessage(hwnd, CRM_GETCHECK, CREDUI_CONTROL_SAVE, 0)

// public\sdk\inc\wincrypt.h
#define IS_CERT_HASH_PROP_ID(X)     (CERT_SHA1_HASH_PROP_ID == (X) || \
                                        CERT_MD5_HASH_PROP_ID == (X) || \
                                        CERT_SIGNATURE_HASH_PROP_ID == (X))
#define IS_PUBKEY_HASH_PROP_ID(X)     (CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) || \
                                        CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID == (X))
#define IS_CHAIN_HASH_PROP_ID(X)     (CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) || \
                                        CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) || \
                                        CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID == (X) || \
                                        CERT_SUBJECT_NAME_MD5_HASH_PROP_ID == (X))

// public\sdk\inc\windowsx.h
#define     IsRestored(hwnd)    ((GetWindowStyle(hwnd) & (WS_MINIMIZE | WS_MAXIMIZE)) == 0L)
#define     CheckDefDlgRecursion(pfRecursion) \
    if (*(pfRecursion)) { *(pfRecursion) = FALSE; return FALSE; }
#define HANDLE_WM_GETMINMAXINFO(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPMINMAXINFO)(lParam)), 0L)
#define FORWARD_WM_GETMINMAXINFO(hwnd, lpMinMaxInfo, fn) \
    (void)(fn)((hwnd), WM_GETMINMAXINFO, 0L, (LPARAM)(LPMINMAXINFO)(lpMinMaxInfo))
#define HANDLE_WM_MDIMAXIMIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIMAXIMIZE(hwnd, hwndMaximize, fn) \
    (void)(fn)((hwnd), WM_MDIMAXIMIZE, (WPARAM)(hwndMaximize), 0L)
#define HANDLE_WM_MDIICONARRANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_MDIICONARRANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_MDIICONARRANGE, 0L, 0L)
#define ComboBox_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))

// public\sdk\inc\winerror.h
#define OLE_E_INVALIDHWND                _HRESULT_TYPEDEF_(0x8004000FL)
#define DRAGDROP_E_INVALIDHWND           _HRESULT_TYPEDEF_(0x80040102L)
#define REGDB_E_INVALIDVALUE             _HRESULT_TYPEDEF_(0x80040153L)
#define OLEOBJ_E_INVALIDVERB             _HRESULT_TYPEDEF_(0x80040181L)
#define MK_E_INVALIDEXTENSION            _HRESULT_TYPEDEF_(0x800401E6L)
#define MK_E_NOTBOUND                    _HRESULT_TYPEDEF_(0x800401E9L)
#define CO_E_CANTDETERMINECLASS          _HRESULT_TYPEDEF_(0x800401F2L)
#define EVENT_E_INVALID_PER_USER_SID     _HRESULT_TYPEDEF_(0x80040207L)
#define EVENT_E_INVALID_EVENT_CLASS_PARTITION _HRESULT_TYPEDEF_(0x8004020FL)
#define XACT_E_INVALIDCOOKIE             _HRESULT_TYPEDEF_(0x8004D015L)
#define XACT_E_INVALIDLSN                _HRESULT_TYPEDEF_(0x8004D084L)
#define OLEOBJ_S_INVALIDVERB             _HRESULT_TYPEDEF_(0x00040180L)
#define OLEOBJ_S_INVALIDHWND             _HRESULT_TYPEDEF_(0x00040182L)
#define SCHED_S_TASK_HAS_NOT_RUN         _HRESULT_TYPEDEF_(0x00041303L)
#define SCHED_S_TASK_TERMINATED          _HRESULT_TYPEDEF_(0x00041306L)
#define SCHED_S_TASK_NO_VALID_TRIGGERS   _HRESULT_TYPEDEF_(0x00041307L)
#define SCHED_E_INVALID_TASK             _HRESULT_TYPEDEF_(0x8004130EL)
#define MEM_E_INVALID_ROOT               _HRESULT_TYPEDEF_(0x80080009L)
#define MEM_E_INVALID_LINK               _HRESULT_TYPEDEF_(0x80080010L)
#define MEM_E_INVALID_SIZE               _HRESULT_TYPEDEF_(0x80080011L)
#define TYPE_E_INVALIDID                 _HRESULT_TYPEDEF_(0x800288CFL)
#define TYPE_E_OUTOFBOUNDS               _HRESULT_TYPEDEF_(0x80028CA1L)
#define STG_E_INVALIDFUNCTION            _HRESULT_TYPEDEF_(0x80030001L)
#define STG_E_INVALIDHANDLE              _HRESULT_TYPEDEF_(0x80030006L)
#define STG_E_INVALIDPARAMETER           _HRESULT_TYPEDEF_(0x80030057L)
#define STG_E_INVALIDHEADER              _HRESULT_TYPEDEF_(0x800300FBL)
#define STG_E_INVALIDNAME                _HRESULT_TYPEDEF_(0x800300FCL)
#define STG_E_TERMINATED                 _HRESULT_TYPEDEF_(0x80030202L)
#define RPC_E_CONNECTION_TERMINATED      _HRESULT_TYPEDEF_(0x80010006L)
#define RPC_E_INVALID_DATA               _HRESULT_TYPEDEF_(0x8001000FL)
#define RPC_E_INVALID_PARAMETER          _HRESULT_TYPEDEF_(0x80010010L)
#define RPC_E_INVALIDMETHOD              _HRESULT_TYPEDEF_(0x80010107L)
#define RPC_E_INVALID_CALLDATA           _HRESULT_TYPEDEF_(0x8001010CL)
#define RPC_E_INVALID_HEADER             _HRESULT_TYPEDEF_(0x80010111L)
#define RPC_E_INVALID_EXTENSION          _HRESULT_TYPEDEF_(0x80010112L)
#define RPC_E_INVALID_IPID               _HRESULT_TYPEDEF_(0x80010113L)
#define RPC_E_INVALID_OBJECT             _HRESULT_TYPEDEF_(0x80010114L)
#define RPC_E_INVALID_OBJREF             _HRESULT_TYPEDEF_(0x8001011DL)
#define RPC_E_INVALID_STD_NAME           _HRESULT_TYPEDEF_(0x80010122L)
#define CO_E_ACCESSCHECKFAILED           _HRESULT_TYPEDEF_(0x8001012AL)
#define CO_E_INVALIDSID                  _HRESULT_TYPEDEF_(0x8001012DL)
#define CRYPT_E_INVALID_MSG_TYPE         _HRESULT_TYPEDEF_(0x80091004L)
#define CRYPT_E_INVALID_INDEX            _HRESULT_TYPEDEF_(0x80091008L)
#define CRYPT_E_NO_REVOCATION_CHECK      _HRESULT_TYPEDEF_(0x80092012L)
#define CRYPT_E_INVALID_NUMERIC_STRING   _HRESULT_TYPEDEF_(0x80092020L)
#define CRYPT_E_INVALID_IA5_STRING       _HRESULT_TYPEDEF_(0x80092022L)
#define CRYPT_E_INVALID_X500_STRING      _HRESULT_TYPEDEF_(0x80092023L)
#define CRYPT_E_NO_VERIFY_USAGE_CHECK    _HRESULT_TYPEDEF_(0x80092028L)
#define OSS_PDU_RANGE                    _HRESULT_TYPEDEF_(0x80093003L)
#define OSS_NULL_TBL                     _HRESULT_TYPEDEF_(0x80093014L)
#define OSS_NULL_FCN                     _HRESULT_TYPEDEF_(0x80093015L)
#define OSS_OUT_OF_RANGE                 _HRESULT_TYPEDEF_(0x80093021L)
#define CERTSRV_E_INVALID_CA_CERTIFICATE _HRESULT_TYPEDEF_(0x80094005L)
#define CERTSRV_E_NO_VALID_KRA           _HRESULT_TYPEDEF_(0x8009400BL)
#define CERTSRV_E_NO_CAADMIN_DEFINED     _HRESULT_TYPEDEF_(0x8009400DL)
#define MSSIPOTF_E_OUTOFMEMRANGE         _HRESULT_TYPEDEF_(0x80097001L)
#define MSSIPOTF_E_FILE_CHECKSUM         _HRESULT_TYPEDEF_(0x8009700DL)
#define MSSIPOTF_E_PCONST_CHECK          _HRESULT_TYPEDEF_(0x80097017L)
#define CERT_E_VALIDITYPERIODNESTING     _HRESULT_TYPEDEF_(0x800B0102L)
#define CERT_E_INVALID_POLICY            _HRESULT_TYPEDEF_(0x800B0113L)
#define CERT_E_INVALID_NAME              _HRESULT_TYPEDEF_(0x800B0114L)
#define SPAPI_E_INVALID_DEVINST_NAME     _HRESULT_TYPEDEF_(0x800F0205L)
#define SPAPI_E_INVALID_CLASS            _HRESULT_TYPEDEF_(0x800F0206L)
#define SPAPI_E_INVALID_REG_PROPERTY     _HRESULT_TYPEDEF_(0x800F0209L)
#define SPAPI_E_INVALID_CLASS_INSTALLER  _HRESULT_TYPEDEF_(0x800F020DL)
#define SPAPI_E_INVALID_HWPROFILE        _HRESULT_TYPEDEF_(0x800F0210L)
#define SPAPI_E_INVALID_REFERENCE_STRING _HRESULT_TYPEDEF_(0x800F021FL)
#define SPAPI_E_INVALID_COINSTALLER      _HRESULT_TYPEDEF_(0x800F0227L)
#define SPAPI_E_INVALID_FILTER_DRIVER    _HRESULT_TYPEDEF_(0x800F022CL)
#define SPAPI_E_INVALID_TARGET           _HRESULT_TYPEDEF_(0x800F0233L)
#define SCARD_E_INVALID_HANDLE           _HRESULT_TYPEDEF_(0x80100003L)
#define SCARD_E_INVALID_PARAMETER        _HRESULT_TYPEDEF_(0x80100004L)
#define SCARD_E_INVALID_TARGET           _HRESULT_TYPEDEF_(0x80100005L)
#define SCARD_E_INVALID_VALUE            _HRESULT_TYPEDEF_(0x80100011L)
#define SCARD_E_INVALID_ATR              _HRESULT_TYPEDEF_(0x80100015L)
#define SCARD_E_INVALID_CHV              _HRESULT_TYPEDEF_(0x8010002AL)
#define COMADMIN_E_OBJECTERRORS          _HRESULT_TYPEDEF_(0x80110401L)
#define COMADMIN_E_OBJECTINVALID         _HRESULT_TYPEDEF_(0x80110402L)
#define COMADMIN_E_KEYMISSING            _HRESULT_TYPEDEF_(0x80110403L)
#define COMADMIN_E_ALREADYINSTALLED      _HRESULT_TYPEDEF_(0x80110404L)
#define COMADMIN_E_APP_FILE_WRITEFAIL    _HRESULT_TYPEDEF_(0x80110407L)
#define COMADMIN_E_APP_FILE_READFAIL     _HRESULT_TYPEDEF_(0x80110408L)
#define COMADMIN_E_APP_FILE_VERSION      _HRESULT_TYPEDEF_(0x80110409L)
#define COMADMIN_E_BADPATH               _HRESULT_TYPEDEF_(0x8011040AL)
#define COMADMIN_E_APPLICATIONEXISTS     _HRESULT_TYPEDEF_(0x8011040BL)
#define COMADMIN_E_ROLEEXISTS            _HRESULT_TYPEDEF_(0x8011040CL)
#define COMADMIN_E_CANTCOPYFILE          _HRESULT_TYPEDEF_(0x8011040DL)
#define COMADMIN_E_NOUSER                _HRESULT_TYPEDEF_(0x8011040FL)
#define COMADMIN_E_INVALIDUSERIDS        _HRESULT_TYPEDEF_(0x80110410L)
#define COMADMIN_E_NOREGISTRYCLSID       _HRESULT_TYPEDEF_(0x80110411L)
#define COMADMIN_E_BADREGISTRYPROGID     _HRESULT_TYPEDEF_(0x80110412L)
#define COMADMIN_E_AUTHENTICATIONLEVEL   _HRESULT_TYPEDEF_(0x80110413L)
#define COMADMIN_E_USERPASSWDNOTVALID    _HRESULT_TYPEDEF_(0x80110414L)
#define COMADMIN_E_CLSIDORIIDMISMATCH    _HRESULT_TYPEDEF_(0x80110418L)
#define COMADMIN_E_REMOTEINTERFACE       _HRESULT_TYPEDEF_(0x80110419L)
#define COMADMIN_E_DLLREGISTERSERVER     _HRESULT_TYPEDEF_(0x8011041AL)
#define COMADMIN_E_NOSERVERSHARE         _HRESULT_TYPEDEF_(0x8011041BL)
#define COMADMIN_E_BADREGISTRYLIBID      _HRESULT_TYPEDEF_(0x8011041EL)
#define COMADMIN_E_APPDIRNOTFOUND        _HRESULT_TYPEDEF_(0x8011041FL)
#define COMADMIN_E_REGISTRARFAILED       _HRESULT_TYPEDEF_(0x80110423L)
#define COMADMIN_E_COMPFILE_DOESNOTEXIST _HRESULT_TYPEDEF_(0x80110424L)
#define COMADMIN_E_COMPFILE_GETCLASSOBJ  _HRESULT_TYPEDEF_(0x80110426L)
#define COMADMIN_E_COMPFILE_CLASSNOTAVAIL _HRESULT_TYPEDEF_(0x80110427L)
#define COMADMIN_E_COMPFILE_BADTLB       _HRESULT_TYPEDEF_(0x80110428L)
#define COMADMIN_E_COMPFILE_NOTINSTALLABLE _HRESULT_TYPEDEF_(0x80110429L)
#define COMADMIN_E_NOTCHANGEABLE         _HRESULT_TYPEDEF_(0x8011042AL)
#define COMADMIN_E_NOTDELETEABLE         _HRESULT_TYPEDEF_(0x8011042BL)
#define COMADMIN_E_SESSION               _HRESULT_TYPEDEF_(0x8011042CL)
#define COMADMIN_E_COMP_MOVE_BAD_DEST    _HRESULT_TYPEDEF_(0x8011042EL)
#define COMADMIN_E_REGISTERTLB           _HRESULT_TYPEDEF_(0x80110430L)
#define COMADMIN_E_COMPFILE_NOREGISTRAR  _HRESULT_TYPEDEF_(0x80110434L)
#define COMADMIN_E_COREQCOMPINSTALLED    _HRESULT_TYPEDEF_(0x80110435L)
#define COMADMIN_E_SERVICENOTINSTALLED   _HRESULT_TYPEDEF_(0x80110436L)
#define COMADMIN_E_PROPERTYSAVEFAILED    _HRESULT_TYPEDEF_(0x80110437L)
#define COMADMIN_E_OBJECTEXISTS          _HRESULT_TYPEDEF_(0x80110438L)
#define COMADMIN_E_COMPONENTEXISTS       _HRESULT_TYPEDEF_(0x80110439L)
#define COMADMIN_E_REGFILE_CORRUPT       _HRESULT_TYPEDEF_(0x8011043BL)
#define COMADMIN_E_NOTINREGISTRY         _HRESULT_TYPEDEF_(0x8011043EL)
#define COMADMIN_E_OBJECTNOTPOOLABLE     _HRESULT_TYPEDEF_(0x8011043FL)
#define COMADMIN_E_APPLID_MATCHES_CLSID  _HRESULT_TYPEDEF_(0x80110446L)
#define COMADMIN_E_ROLE_DOES_NOT_EXIST   _HRESULT_TYPEDEF_(0x80110447L)
#define COMADMIN_E_START_APP_NEEDS_COMPONENTS _HRESULT_TYPEDEF_(0x80110448L)
#define COMADMIN_E_REQUIRES_DIFFERENT_PLATFORM _HRESULT_TYPEDEF_(0x80110449L)
#define COMADMIN_E_CAN_NOT_EXPORT_APP_PROXY _HRESULT_TYPEDEF_(0x8011044AL)
#define COMADMIN_E_CAN_NOT_START_APP     _HRESULT_TYPEDEF_(0x8011044BL)
#define COMADMIN_E_CAN_NOT_EXPORT_SYS_APP _HRESULT_TYPEDEF_(0x8011044CL)
#define COMADMIN_E_CANT_SUBSCRIBE_TO_COMPONENT _HRESULT_TYPEDEF_(0x8011044DL)
#define COMADMIN_E_EVENTCLASS_CANT_BE_SUBSCRIBER _HRESULT_TYPEDEF_(0x8011044EL)
#define COMADMIN_E_LIB_APP_PROXY_INCOMPATIBLE _HRESULT_TYPEDEF_(0x8011044FL)
#define COMADMIN_E_START_APP_DISABLED    _HRESULT_TYPEDEF_(0x80110451L)
#define COMADMIN_E_CAT_DUPLICATE_PARTITION_NAME _HRESULT_TYPEDEF_(0x80110457L)
#define COMADMIN_E_CAT_INVALID_PARTITION_NAME _HRESULT_TYPEDEF_(0x80110458L)
#define COMADMIN_E_CAT_PARTITION_IN_USE  _HRESULT_TYPEDEF_(0x80110459L)
#define COMADMIN_E_FILE_PARTITION_DUPLICATE_FILES _HRESULT_TYPEDEF_(0x8011045AL)
#define COMADMIN_E_AMBIGUOUS_APPLICATION_NAME _HRESULT_TYPEDEF_(0x8011045CL)
#define COMADMIN_E_AMBIGUOUS_PARTITION_NAME _HRESULT_TYPEDEF_(0x8011045DL)
#define COMADMIN_E_REGDB_NOTINITIALIZED  _HRESULT_TYPEDEF_(0x80110472L)
#define COMADMIN_E_REGDB_NOTOPEN         _HRESULT_TYPEDEF_(0x80110473L)
#define COMADMIN_E_REGDB_SYSTEMERR       _HRESULT_TYPEDEF_(0x80110474L)
#define COMADMIN_E_REGDB_ALREADYRUNNING  _HRESULT_TYPEDEF_(0x80110475L)
#define COMADMIN_E_MIG_VERSIONNOTSUPPORTED _HRESULT_TYPEDEF_(0x80110480L)
#define COMADMIN_E_MIG_SCHEMANOTFOUND    _HRESULT_TYPEDEF_(0x80110481L)
#define COMADMIN_E_CAT_PAUSE_RESUME_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80110485L)
#define COMADMIN_E_CAT_SERVERFAULT       _HRESULT_TYPEDEF_(0x80110486L)
#define COMADMIN_E_OBJECT_PARENT_MISSING _HRESULT_TYPEDEF_(0x80110808L)
#define COMADMIN_E_OBJECT_DOES_NOT_EXIST _HRESULT_TYPEDEF_(0x80110809L)
#define COMADMIN_E_APP_NOT_RUNNING       _HRESULT_TYPEDEF_(0x8011080AL)
#define COMADMIN_E_INVALID_PARTITION     _HRESULT_TYPEDEF_(0x8011080BL)
#define COMADMIN_E_SVCAPP_NOT_POOLABLE_OR_RECYCLABLE _HRESULT_TYPEDEF_(0x8011080DL)
#define COMADMIN_E_USER_IN_SET           _HRESULT_TYPEDEF_(0x8011080EL)
#define COMADMIN_E_CANTRECYCLELIBRARYAPPS _HRESULT_TYPEDEF_(0x8011080FL)
#define COMADMIN_E_CANTRECYCLESERVICEAPPS _HRESULT_TYPEDEF_(0x80110811L)
#define COMADMIN_E_PROCESSALREADYRECYCLED _HRESULT_TYPEDEF_(0x80110812L)
#define COMADMIN_E_PAUSEDPROCESSMAYNOTBERECYCLED _HRESULT_TYPEDEF_(0x80110813L)
#define COMADMIN_E_CANTMAKEINPROCSERVICE _HRESULT_TYPEDEF_(0x80110814L)
#define COMADMIN_E_PROGIDINUSEBYCLSID    _HRESULT_TYPEDEF_(0x80110815L)
#define COMADMIN_E_DEFAULT_PARTITION_NOT_IN_SET _HRESULT_TYPEDEF_(0x80110816L)
#define COMADMIN_E_RECYCLEDPROCESSMAYNOTBEPAUSED _HRESULT_TYPEDEF_(0x80110817L)
#define COMADMIN_E_PARTITION_ACCESSDENIED _HRESULT_TYPEDEF_(0x80110818L)
#define COMADMIN_E_PARTITION_MSI_ONLY    _HRESULT_TYPEDEF_(0x80110819L)
#define COMADMIN_E_COMP_MOVE_SOURCE      _HRESULT_TYPEDEF_(0x8011081CL)
#define COMADMIN_E_COMP_MOVE_DEST        _HRESULT_TYPEDEF_(0x8011081DL)
#define COMADMIN_E_COMP_MOVE_PRIVATE     _HRESULT_TYPEDEF_(0x8011081EL)
#define COMADMIN_E_CANNOT_ALIAS_EVENTCLASS _HRESULT_TYPEDEF_(0x80110820L)
#define COMADMIN_E_PRIVATE_ACCESSDENIED  _HRESULT_TYPEDEF_(0x80110821L)
#define COMADMIN_E_SAFERINVALID          _HRESULT_TYPEDEF_(0x80110822L)
#define COMADMIN_E_REGISTRY_ACCESSDENIED _HRESULT_TYPEDEF_(0x80110823L)

// public\sdk\inc\wininet.h
#define IS_GOPHER_PHONE_SERVER(type)    (BOOL)(((type) & GOPHER_TYPE_CSO) ? TRUE : FALSE)
#define IS_GOPHER_ERROR(type)           (BOOL)(((type) & GOPHER_TYPE_ERROR) ? TRUE : FALSE)
#define IS_GOPHER_INDEX_SERVER(type)    (BOOL)(((type) & GOPHER_TYPE_INDEX_SERVER) ? TRUE : FALSE)
#define IS_GOPHER_TELNET_SESSION(type)  (BOOL)(((type) & GOPHER_TYPE_TELNET) ? TRUE : FALSE)
#define IS_GOPHER_BACKUP_SERVER(type)   (BOOL)(((type) & GOPHER_TYPE_REDUNDANT) ? TRUE : FALSE)
#define IS_GOPHER_TN3270_SESSION(type)  (BOOL)(((type) & GOPHER_TYPE_TN3270) ? TRUE : FALSE)
#define IS_GOPHER_ASK(type)             (BOOL)(((type) & GOPHER_TYPE_ASK) ? TRUE : FALSE)
#define IS_GOPHER_PLUS(type)            (BOOL)(((type) & GOPHER_TYPE_GOPHER_PLUS) ? TRUE : FALSE)
#define IS_GOPHER_TYPE_KNOWN(type)      (BOOL)(((type) & GOPHER_TYPE_UNKNOWN) ? FALSE : TRUE)

// public\sdk\inc\winsnmp.h
#define SNMP_SYNTAX_NULL      (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x05)

// public\sdk\inc\winsock.h
#define INVALID_SOCKET  (SOCKET)(~0)

// public\sdk\inc\winsock2.h
#define INVALID_SOCKET  (SOCKET)(~0)

// public\sdk\inc\winspool.h
#define SERVER_ALL_ACCESS    (STANDARD_RIGHTS_REQUIRED      |\
                              SERVER_ACCESS_ADMINISTER      |\
                              SERVER_ACCESS_ENUMERATE)
#define SERVER_WRITE         (STANDARD_RIGHTS_WRITE         |\
                              SERVER_ACCESS_ADMINISTER      |\
                              SERVER_ACCESS_ENUMERATE)
#define PRINTER_ALL_ACCESS    (STANDARD_RIGHTS_REQUIRED     |\
                               PRINTER_ACCESS_ADMINISTER    |\
                               PRINTER_ACCESS_USE)
#define JOB_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED    |\
                                JOB_ACCESS_ADMINISTER       |\
                                JOB_ACCESS_READ)
#define JOB_WRITE              (STANDARD_RIGHTS_WRITE       |\
                                JOB_ACCESS_ADMINISTER)
#define JOB_EXECUTE            (STANDARD_RIGHTS_EXECUTE     |\
                                JOB_ACCESS_ADMINISTER)

// public\sdk\inc\wtl10\atlapp.h
#define REFLECTED_NOTIFY_RANGE_HANDLER(idFirst, idLast, func) \
	if(uMsg == OCM_NOTIFY && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define REFLECTED_NOTIFY_RANGE_CODE_HANDLER(idFirst, idLast, cd, func) \
	if(uMsg == OCM_NOTIFY && cd == ((LPNMHDR)lParam)->code && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}

// public\sdk\inc\wtl10\atlcrack.h
#define MESSAGE_RANGE_HANDLER_EX(msgFirst, msgLast, func) \
	if(uMsg >= msgFirst && uMsg <= msgLast) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func(uMsg, wParam, lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define REFLECTED_NOTIFY_RANGE_HANDLER_EX(idFirst, idLast, func) \
	if(uMsg == OCM_NOTIFY && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define REFLECTED_NOTIFY_RANGE_CODE_HANDLER_EX(idFirst, idLast, cd, func) \
	if(uMsg == OCM_NOTIFY && cd == ((LPNMHDR)lParam)->code && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}

// public\sdk\inc\wtl10\atlddx.h
#define DDX_INT(nID, var) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
		{ \
			if(!DDX_Int(nID, var, TRUE, bSaveAndValidate)) \
				return FALSE; \
		}
#define DDX_INT_RANGE(nID, var, min, max) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
		{ \
			if(!DDX_Int(nID, var, TRUE, bSaveAndValidate, TRUE, min, max)) \
				return FALSE; \
		}
#define DDX_UINT(nID, var) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
		{ \
			if(!DDX_Int(nID, var, FALSE, bSaveAndValidate)) \
				return FALSE; \
		}
#define DDX_UINT_RANGE(nID, var, min, max) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
		{ \
			if(!DDX_Int(nID, var, FALSE, bSaveAndValidate, TRUE, min, max)) \
				return FALSE; \
		}
#define DDX_CONTROL(nID, obj) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
			DDX_Control(nID, obj, bSaveAndValidate);
#define DDX_CHECK(nID, var) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
			DDX_Check(nID, var, bSaveAndValidate);
#define DDX_RADIO(nID, var) \
		if(nCtlID == (UINT)-1 || nCtlID == nID) \
			DDX_Radio(nID, var, bSaveAndValidate);

// published\ddk\inc\wdm\strmini.h
#define MP_UNINITIALIZED_VALUE ((ULONG) ~0)

// published\sdk\inc\alphaops.h
#define TBIS_FUNC       (PRIV_PAL_FUNC | 0x15)
#define DTBIS_FUNC      (PRIV_PAL_FUNC | 0x16)

// published\sdk\inc\gl\glaux.h
#define AUX_WIND_IS_INDEX(x)    (((x) & AUX_INDEX) != 0)
#define AUX_WIND_IS_SINGLE(x)   (((x) & AUX_DOUBLE) == 0)
#define AUX_WIND_IS_DOUBLE(x)   (((x) & AUX_DOUBLE) != 0)
#define AUX_WIND_HAS_ACCUM(x)   (((x) & AUX_ACCUM) != 0)
#define AUX_WIND_HAS_ALPHA(x)   (((x) & AUX_ALPHA) != 0)
#define AUX_WIND_HAS_DEPTH(x)   (((x) & (AUX_DEPTH24 | AUX_DEPTH16)) != 0)
#define AUX_WIND_HAS_STENCIL(x) (((x) & AUX_STENCIL) != 0)

// published\sdk\inc\mmreg.h
#define IS_COMPATIBLE_MMREG_MID(guid)\
    (((guid)->Data1 >= 0xd5a47fa7) &&\
    ((guid)->Data1 < 0xd5a47fa7 + 0xffff) &&\
    ((guid)->Data2 == 0x6d98) &&\
    ((guid)->Data3 == 0x11d1) &&\
    ((guid)->Data4[0] == 0xa2) &&\
    ((guid)->Data4[1] == 0x1a) &&\
    ((guid)->Data4[2] == 0x00) &&\
    ((guid)->Data4[3] == 0xa0) &&\
    ((guid)->Data4[4] == 0xc9) &&\
    ((guid)->Data4[5] == 0x22) &&\
    ((guid)->Data4[6] == 0x31) &&\
    ((guid)->Data4[7] == 0x96))
#define IS_COMPATIBLE_MMREG_PID(guid)\
    (((guid)->Data1 >= 0xe36dc2ac) &&\
    ((guid)->Data1 < 0xe36dc2ac + 0xffff) &&\
    ((guid)->Data2 == 0x6d9a) &&\
    ((guid)->Data3 == 0x11d1) &&\
    ((guid)->Data4[0] == 0xa2) &&\
    ((guid)->Data4[1] == 0x1a) &&\
    ((guid)->Data4[2] == 0x00) &&\
    ((guid)->Data4[3] == 0xa0) &&\
    ((guid)->Data4[4] == 0xc9) &&\
    ((guid)->Data4[5] == 0x22) &&\
    ((guid)->Data4[6] == 0x31) &&\
    ((guid)->Data4[7] == 0x96))

// published\sdk\inc\pstore.h
#define PST_E_INVALID_HANDLE            _HRESULT_TYPEDEF_(0x800C0003L)
#define PST_E_INVALID_RULESET           _HRESULT_TYPEDEF_(0x800C0006L)
#define PST_E_INVALID_STRING            _HRESULT_TYPEDEF_(0x800C0013L)

// published\sdk\inc\pwin16.h
#define MPostWM_DDE_TERMINATE(hTo, hFrom) \
        PostMessage(hTo, WM_DDE_TERMINATE, (WPARAM)hFrom, 0)

// published\sdk\inc\pwin32.h
#define MPostWM_DDE_TERMINATE(hTo, hFrom) \
        PostMessage(hTo, WM_DDE_TERMINATE, (WPARAM)hFrom, 0L)

// published\sdk\inc\snmp.h
#define ASN_NULL                    (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x05)

// published\sdk\inc\unimodem.h
    #define IS_VALID_RAWDIAGNOSTICS_HDR(_praw_diagnostics_hdr)              \
            ((_praw_diagnostics_hdr)->dwSig==LDSIG_RAWDIAGNOSTICS)
    #define IS_VALID_PARSEDDIAGNOSTICS_HDR(_pparsed_diagnostics_hdr)        \
            ((_pparsed_diagnostics_hdr)->dwSig==LDSIG_PARSEDDIAGNOSTICS)

// published\sdk\inc\vfw.h
#define MCIWNDM_VALIDATEMEDIA   (WM_USER + 121)

// published\sdk\inc\windowsx.h
#define     IsRestored(hwnd)    ((GetWindowStyle(hwnd) & (WS_MINIMIZE | WS_MAXIMIZE)) == 0L)
#define     CheckDefDlgRecursion(pfRecursion) \
    if (*(pfRecursion)) { *(pfRecursion) = FALSE; return FALSE; }
#define HANDLE_WM_GETMINMAXINFO(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPMINMAXINFO)(lParam)), 0L)
#define FORWARD_WM_GETMINMAXINFO(hwnd, lpMinMaxInfo, fn) \
    (void)(fn)((hwnd), WM_GETMINMAXINFO, 0L, (LPARAM)(LPMINMAXINFO)(lpMinMaxInfo))
#define HANDLE_WM_MDIMAXIMIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_MDIMAXIMIZE(hwnd, hwndMaximize, fn) \
    (void)(fn)((hwnd), WM_MDIMAXIMIZE, (WPARAM)(hwndMaximize), 0L)
#define HANDLE_WM_MDIICONARRANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), 0L)
#define FORWARD_WM_MDIICONARRANGE(hwnd, fn) \
    (void)(fn)((hwnd), WM_MDIICONARRANGE, 0L, 0L)
#define ComboBox_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))

// published\sdk\inc\winsnmp.h
#define SNMP_SYNTAX_NULL      (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x05)

// sdktools\apimon\include\apimon.h
#define MAX_APIS                        ((MAX_MEM_ALLOC/2)/sizeof(API_INFO))

// sdktools\asn1\asn1all\scanner.c
#define IS_IDENT(c) (isalpha(c) || c == '_' || c == '\'' || c == '\"')

// sdktools\asn1\asn1c\scanner.c
#define yy_set_interactive(is_interactive) \
    { \
    if ( ! yy_current_buffer ) \
        yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
    yy_current_buffer->yy_is_interactive = is_interactive; \
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

// sdktools\checkrel\checkrel.c
#define ATTRMATCH(fnormal, attr) \
    (!fNormal ^ ((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0))

// sdktools\compdir\comtoolz.c
#define CALCULATE_HEIGHT( Node)                                                    \
                                                                                  \
    if ( (*Node).Left == NULL)                                                     \
        if ( (*Node).Right == NULL)                                                \
             (*Node).Height = 1;                                                   \
        else                                                                      \
             (*Node).Height = (*(*Node).Right).Height + 1;                         \
    else                                                                          \
        if ( (*Node).Right == NULL)                                                \
             (*Node).Height = (*(*Node).Left).Height + 1;                          \
        else                                                                      \
            (*Node).Height = ( (*(*Node).Right).Height > (*(*Node).Left).Height) ? \
                (*(*Node).Right).Height + 1 : (*(*Node).Left).Height + 1;

// sdktools\diff\diff.c
    #define _HEAP_MAXREQ ((~(unsigned int) 0) - (unsigned) 32)

// sdktools\efinvram\efinvram.h
#define MBE_IS_ACTIVE(_be) (((_be)->Attributes & BOOT_ENTRY_ATTRIBUTE_ACTIVE) != 0)
#define IS_SEPARATE_ALLOCATION(_be,_p)                                  \
        ((_be->_p != NULL) &&                                           \
         (((PUCHAR)_be->_p < (PUCHAR)_be) ||                            \
          ((PUCHAR)_be->_p > (PUCHAR)_be->AllocationEnd)))

// sdktools\hivepp\charmap.h
#define	LXC_IS_BDIGIT(c)	(CONTMAP(c) & LXC_BDIGIT)
#define	LXC_IS_ODIGIT(c)	(CONTMAP(c) & LXC_ODIGIT)
#define	LXC_IS_DIGIT(c)		(CONTMAP(c) & LXC_DIGIT)
#define	LXC_IS_XDIGIT(c)	(CONTMAP(c) & LXC_XDIGIT)
#define	LXC_IS_IDENT(c)		(CONTMAP(c) & LXC_ID)
#define LXC_IS_RADIX(c)		(CONTMAP(c) & LXC_RADIX)
#define LXC_IS_WHITE(c)		(CONTMAP(c) & LXC_WHITE)
#define IS_SPECIAL(c)		(CONTMAP(c) & LXC_SPECIAL)

// sdktools\hivepp\p0defs.h
#define	IS_SIGN(c)	((c == '+') || (c =='-'))

// sdktools\hivepp\p1types.h
#define	IS_BTFLOAT(P)		((BTfloat <= (P)) && ((P) <= BTldouble))
#define	IS_UNSIGNED(P)	((P) & BT_UNSIGNED)
#define	IS_SIGNED(P)	((P) & BT_SIGNED)
#define	IS_DATA_ADDRESS(I)	((I) & IN_DATA_ADDRESS)
#define	IS_ADDRESS(I)		((I) & IN_ADDRESS)
#define	IS_VOIDLIST(I)		((I) & IN_VOIDLIST)
#define	IS_VARARGS(I)		((I) & IN_VARARGS)
#define	IS_INTERRUPT(I)		((I) & BT_INTERRUPT)
#define	IS_SAVEREGS(I)		((I) & BT_SAVEREGS)
#define	IS_EXPORT(I)		((I) & BT_EXPORT)
#define	IS_LOADDS(I)		((I) & BT_LOADDS)
#define	IS_CONST(I)			((I) & BT_CONST)
#define	IS_VOLATILE(I)		((I) & BT_VOLATILE)

// sdktools\link16\bndtrn.h
#define GSNMAX          (0xffdf/sizeof(RATYPE))
#define GSNMAX          (0xffdf/sizeof(RATYPE))
#define IsConforming(x) (((x) & NSCONFORM) != 0)
#define NonConfIOPL(x)  (!IsConforming(x) && IsIOPL(x))

// sdktools\link16\minlit.h
#define B2L(x)          ((long)(x) & 0377)

// sdktools\link16\undname.hxx
#define isValidLetter(n)        (((n)=='_')||((n)=='$')||(((n)>='a')&&((n)<='z'))||(((n)>='A')&&((n)<='Z')))
#define isValidNumber(n)        (((n)>='0')&&((n)<='9'))
#define isValidIdentChar(n)     (isValidLetter(n)||isValidNumber(n))

// sdktools\m4\m4.h
#define ctchMax         ((CTCH)~0)

// sdktools\masm\asminptb.c
#define ID   (_AT | _A1 | _AF)
#define IDO  (_AT | _A1)
#define DIG  (_AT | _AF)
#define TERM (_AL | _AZ)
#define SIGN (_AS | _AF | _AO)
#define DOT  (_A1 | _AF | _AO)

// sdktools\masm\asmopc.c
#define M_ERRIMMED (M_PSHIFT | M_PARITH | M_PINCDEC | M_PCALL | M_PJUMP |    \
		    M_PMOV | M_PSTR | M_PRELJMP | M_PGENARG | M_PXCHG |      \
		    M_PBOUND | M_PCLTS | M_PDESCRTBL | M_PDTTRSW | M_PARSL | \
		    M_PARPL | M_PVER)

// sdktools\mep\extens\mhelp\mh.h
#define ISERROR(x)      (((x).mh == 0L) && ((x).cn <= HELPERR_MAX))

// sdktools\mep\help\enginlib\help.c
#define ISERROR(x)      (((x).mh == 0L) && ((x).cn <= HELPERR_MAX))

// sdktools\mep\help\htest\cons.c
#define ResetLineInfo(pli)		    \
	{   pli->Dirty = 0;		    \
	    pli->colMinChanged = 1000;	    \
	    pli->colMaxChanged = -1;	    \
	}

// sdktools\mep\help\htest\htest.c
#define ISERROR(x)      (((x).mh == 0L) && ((x).cn <= HELPERR_MAX))

// sdktools\mep\help\mshelp\help.c
#define ISERROR(x)      (((x).mh == 0L) && ((x).cn <= HELPERR_MAX))

// sdktools\mep\src\console.c
#define ResetLineInfo(pli)               \
    {   pli->Dirty          = FALSE;     \
        pli->Garbage        = TRUE;      \
        pli->colMinChanged  = 10000;     \
        pli->colMaxChanged  = -1;        \
	}

// sdktools\nmake\charmap.h
#define IS_OPERATORCHAR(c) ((Charmap[(UCHAR)(c)] & OPERATORMSK) != 0)
#define IS_MACROCHAR(c) ((Charmap[(UCHAR)(c)] & MACROMSK) != 0)

// sdktools\nmake\nmake.h
#define MACRO_CHAR(A)       (IS_MACROCHAR(A) || ((unsigned)(A)) >= 128)

// sdktools\pdh\inc\perftype.h
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// sdktools\pdh\wbemperf\utils.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < '0') ? INVALID : \
     (c > '9') ? INVALID : \
     DIGIT)

// sdktools\perfmon\fileutil.h
#define FileHandleOpen(lpszFilePath)         \
   (HANDLE) CreateFile (lpszFilePath,        \
      GENERIC_READ | GENERIC_WRITE,          \
      FILE_SHARE_READ,                       \
      NULL, OPEN_EXISTING,                   \
      FILE_ATTRIBUTE_NORMAL, NULL)
#define FileHandleReadOnly(lpszFilePath)     \
   (HANDLE) CreateFile (lpszFilePath,        \
      GENERIC_READ ,                         \
      FILE_SHARE_READ | FILE_SHARE_WRITE,    \
      NULL, OPEN_EXISTING,                   \
      FILE_ATTRIBUTE_NORMAL, NULL)
#define FileHandleCreate(lpszFilePath)       \
   (HANDLE) CreateFile (lpszFilePath,        \
      GENERIC_READ | GENERIC_WRITE,          \
      FILE_SHARE_READ,                       \
      NULL, CREATE_ALWAYS,                   \
      FILE_ATTRIBUTE_NORMAL, NULL)

// sdktools\perfmon\legend.c
#define ColCanGrow(pCol)                     \
   (pCol->xMaxWidth > pCol->xWidth)

// sdktools\perfmon\perfmops.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// sdktools\perfmon\report.h
#define ValueMargin(pReport)       \
   (4 * xScrollWidth + pReport->xMaxCounterWidth)

// sdktools\perfmon\utils.h
#define MenuCheck(hMenu, wID, bCheck)                 \
   (CheckMenuItem (hMenu, wID, (bCheck) ?             \
     (MF_BYCOMMAND | MF_CHECKED) : (MF_BYCOMMAND | MF_UNCHECKED)))

// sdktools\proccon\snapin\about.cpp
#define MAX_STR_RESOURCE_SIZE  (sizeof(TCHAR) * MAX_STR_RESOURCE_LEN)

// sdktools\qfecheck\spapip.h
#define CSTRLEN(x)      ((sizeof((x))/sizeof(TCHAR)) - 1)

// sdktools\rcdll\charmap.h
#define LXC_IS_BDIGIT(c)        (CONTMAP(c) & LXC_BDIGIT)
#define LXC_IS_ODIGIT(c)        (CONTMAP(c) & LXC_ODIGIT)
#define LXC_IS_DIGIT(c)         (CONTMAP(c) & LXC_DIGIT)
#define LXC_IS_XDIGIT(c)        (CONTMAP(c) & LXC_XDIGIT)
#define LXC_IS_IDENT(c)         (CONTMAP(c) & LXC_ID)
#define LXC_IS_RADIX(c)         (CONTMAP(c) & LXC_RADIX)
#define LXC_IS_WHITE(c)         (CONTMAP(c) & LXC_WHITE)
#define IS_SPECIAL(c)           (CONTMAP(c) & LXC_SPECIAL)

// sdktools\rcdll\p0defs.h
#define IS_SIGN(c)      ((c == L'+') || (c ==L'-'))

// sdktools\rcdll\p1types.h
#define IS_BTFLOAT(P)           ((BTfloat <= (P)) && ((P) <= BTldouble))
#define IS_UNSIGNED(P)  ((P) & BT_UNSIGNED)
#define IS_SIGNED(P)    ((P) & BT_SIGNED)
#define IS_DATA_ADDRESS(I)              ((I) & IN_DATA_ADDRESS)
#define IS_ADDRESS(I)                   ((I) & IN_ADDRESS)
#define IS_VOIDLIST(I)                  ((I) & IN_VOIDLIST)
#define IS_VARARGS(I)                   ((I) & IN_VARARGS)
#define IS_INTERRUPT(I)         ((I) & BT_INTERRUPT)
#define IS_SAVEREGS(I)          ((I) & BT_SAVEREGS)
#define IS_EXPORT(I)            ((I) & BT_EXPORT)
#define IS_LOADDS(I)            ((I) & BT_LOADDS)
#define IS_CONST(I)             ((I) & BT_CONST)
#define IS_VOLATILE(I)          ((I) & BT_VOLATILE)

// sdktools\remote\srvad.c
#define  INITIAL_AD_RATE      (10 * 60 * 1000)     // 10 minutes between 1 & 2,

// sdktools\sdv\sdview.h
#define LM_COPYTOCLIPBOARD  (WM_USER + 103) // wParam = iMin, lParam = iMax (exclusive)

// sdktools\setedit\fileutil.h
#define FileHandleOpen(lpszFilePath)         \
   (HANDLE) CreateFile (lpszFilePath,        \
      GENERIC_READ | GENERIC_WRITE,          \
      FILE_SHARE_READ,                       \
      NULL, OPEN_EXISTING,                   \
      FILE_ATTRIBUTE_NORMAL, NULL)
#define FileHandleCreate(lpszFilePath)       \
   (HANDLE) CreateFile (lpszFilePath,        \
      GENERIC_READ | GENERIC_WRITE,          \
      FILE_SHARE_READ,                       \
      NULL, CREATE_ALWAYS,                   \
      FILE_ATTRIBUTE_NORMAL, NULL)

// sdktools\setedit\legend.c
#define ColCanGrow(pCol)                     \
   (pCol->xMaxWidth > pCol->xWidth)

// sdktools\setedit\perfmops.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// sdktools\setedit\utils.h
#define MenuCheck(hMenu, wID, bCheck)                 \
   (CheckMenuItem (hMenu, wID, (bCheck) ?             \
     (MF_BYCOMMAND | MF_CHECKED) : (MF_BYCOMMAND | MF_UNCHECKED)))

// sdktools\tweakui\boot.cpp
#define pmsioMax (&rgmsio[cA(rgmsio)])

// sdktools\unicows\godot\convert.h
#define _STACKALLOC_SAFE(siz, mem) \
        if(StackAllocCheck(siz)) \
            mem = (void *)((siz)?(_alloca(siz)):NULL); \
        else \
            mem = NULL;

// sdktools\unicows\godot\subclass.h
#define INSIDE_GODOT_RANGE(x) (((UINT)x > LASTGODOTWND) && ((UINT)x < ZEORETHGODOTWND))

// sdktools\unicows\godot\unicows.tpl
#define VERINFO_BUFFER (MAX_PATH * sizeof(WCHAR))

// sdktools\windiff\windiff\windiff.c
#define CHECKMENU(id, fChecked)  \
          CheckMenuItem(hMenu, (id), (fChecked) ? MF_CHECKED:MF_UNCHECKED)

// sdktools\winobj\wfdirsrc.c
#define IS_DOTEND(ch)   ((ch) == '.' || (ch) == 0)

// sdktools\z\src\console.c
#define ResetLineInfo(pli)               \
    {   pli->Dirty          = FALSE;     \
        pli->Garbage        = TRUE;      \
        pli->colMinChanged  = 10000;     \
        pli->colMaxChanged  = -1;        \
	}

// shell\browseui\dockbar.h
#define WBM_IS_TOPMOST() (_eMode & WBM_TOPMOST)

// shell\browseui\emclient\uareg.h
#define IND_NONINSTR(iGrp) \
    (!IND_ISINSTR(iGrp) ? (iGrp) : ((iGrp) - UEMIND_NINSTR))
#define IND_ISINSTR(iGrp)   (UEMIND_NINSTR && iSvr >= UEMIND_NINSTR)

// shell\browseui\itbar.cpp
#define VBF_VALIDv2               (VBF_TOOLS | VBF_ADDRESS | VBF_LINKS)

// shell\browseui\legacy\augm.cpp
#define CB_IDLIST_TERMINATOR    sizeof(USHORT)

// shell\browseui\priv.h
#define DLL_IS_UNICODE         (sizeof(TCHAR) == sizeof(WCHAR))

// shell\browseui\shellurl.cpp
#define IS_SHELL_SEPARATOR(ch) ((CH_SEPARATOR == ch) || (CH_FILESEPARATOR == ch))

// shell\comctl32\v5\commctrl.c
#define DECLARE_DELAYED_FUNC(_ret, _fn, _args, _nargs) \
_ret (__stdcall * g_pfn##_fn) _args = NULL; \
_ret __stdcall _fn _args                \
{                                       \
     if (!g_pfn##_fn) {                  \
        AssertMsg(g_pfn##_fn != NULL, TEXT("GetProcAddress failed")); \
        return 0; \
     }     \
     return g_pfn##_fn _nargs; \
}

// shell\comctl32\v5\fontlink.cpp
#define _MAX_MB_BUFFER_SIZE         _MAX_WCHAR_BUFFER_SIZE * sizeof(WCHAR)

// shell\comctl32\v5\monthcal.h
#define DatePick_ShowCheck(pdp)     ((pdp)->ci.style & DTS_SHOWNONE)

// shell\comctl32\v5\prshti.h
#define IsValidPROPSHEETHEADERSIZE(dwSize) \
       ((dwSize) == PROPSHEETHEADERSIZE_BETA || \
        (dwSize) == PROPSHEETHEADERSIZE_V1   || \
        (dwSize) == PROPSHEETHEADERSIZE_V2)

// shell\comctl32\v5\tbcust.c
#define SendCmdNotify(ptb, code)   CCSendNotify(&ptb->ci, code, NULL)

// shell\comctl32\v5\toolbar.c
#define BTN_IS_AUTOSIZE(ptb, ptbb) (((ptbb)->fsStyle & BTNS_AUTOSIZE) || (USE_MIXED_BUTTONS(ptb) && !((ptbb)->fsStyle & BTNS_SEP)))

// shell\comctl32\v6\commctrl.c
#define DECLARE_DELAYED_FUNC(_ret, _fn, _args, _nargs) \
_ret (__stdcall * g_pfn##_fn) _args = NULL; \
_ret __stdcall _fn _args                \
{                                       \
     if (!g_pfn##_fn) {                  \
        return 0; \
     }     \
     return g_pfn##_fn _nargs; \
}

// shell\comctl32\v6\edit.c
#define umin(a, b)      \
            ((unsigned)(a) < (unsigned)(b) ? (unsigned)(a) : (unsigned)(b))
#define umax(a, b)      \
            ((unsigned)(a) > (unsigned)(b) ? (unsigned)(a) : (unsigned)(b))

// shell\comctl32\v6\markup.cpp
#define MARKUPSTATE_VALID (MARKUPSTATE_ENABLED | MARKUPSTATE_VISITED | MARKUPSTATE_FOCUSED)

// shell\comctl32\v6\monthcal.h
#define DatePick_ShowCheck(pdp)     ((pdp)->ci.style & DTS_SHOWNONE)

// shell\comctl32\v6\prshti.h
#define IsValidPROPSHEETHEADERSIZE(dwSize) \
       ((dwSize) == PROPSHEETHEADERSIZE_BETA || \
        (dwSize) == PROPSHEETHEADERSIZE_V1   || \
        (dwSize) == PROPSHEETHEADERSIZE_V2)

// shell\comctl32\v6\scroll.cpp
#define CheckMsgFilter(wMsg, wMsgFilterMin, wMsgFilterMax)                 \
    (   ((wMsgFilterMin) == 0 && (wMsgFilterMax) == 0xFFFFFFFF)            \
     || (  ((wMsgFilterMin) > (wMsgFilterMax))                             \
         ? (((wMsg) <  (wMsgFilterMax)) || ((wMsg) >  (wMsgFilterMin)))    \
         : (((wMsg) >= (wMsgFilterMin)) && ((wMsg) <= (wMsgFilterMax)))))

// shell\comctl32\v6\static.c
#define ISSSTEXTOROD(bType)                 \
            (((bType) <= SS_TEXTMAX0)       \
            || (((bType) >= SS_TEXTMIN1)    \
            && ((bType) <= SS_TEXTMAX1)))

// shell\comctl32\v6\tbcust.c
#define SendCmdNotify(ptb, code)   CCSendNotify(&ptb->ci, code, NULL)

// shell\comctl32\v6\toolbar.cpp
#define BTN_IS_AUTOSIZE(ptb, ptbb) (((ptbb)->fsStyle & BTNS_AUTOSIZE) || (USE_MIXED_BUTTONS(ptb) && !((ptbb)->fsStyle & BTNS_SEP)))

// shell\comdlg32\comdlg32.h
#define IS_DOTEND(ch)   ((ch) == CHAR_DOT || (ch) == 0 || ((ch) != CHAR_STAR))

// shell\comdlg32\font.c
#define IS_DIGITW(x)   (((x) >= L'0') && ((x) <= L'9'))
#define IS_DIGITA(x)   (((x) >= '0') && ((x) <= '9'))

// shell\comdlg32\printnew.cpp
#define Print_IsInRange(id, idFirst, idLast) \
    ((UINT)((id) - idFirst) <= (UINT)(idLast - idFirst))

// shell\comdlg32\prnsetup.h
#define IS_KEY_PRESSED(key)       ( GetKeyState(key) & 0x8000 )

// shell\cpls\appwzdui\uninstal.c
#define UNM_WAKEUP     ( WM_APP + 1 )   // from terminated worker thread

// shell\cpls\system\general.cpp
#define MAX_URL_STRING                  (INTERNET_MAX_SCHEME_LENGTH \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// shell\cpls\utc\calendar.c
#define IS_FE_LANGUAGE(p)    (((p) == LANG_CHINESE)  ||         \
                              ((p) == LANG_JAPANESE) ||         \
                              ((p) == LANG_KOREAN))

// shell\evtmon\inc\emrule.h
#define FValidIrul(irul) \
            ((irul) > 0)
#define RulevtMaxPruls(pruls) \
            ((pruls)->rullims.rulevtMax)
#define RulevlMaxPruls(pruls) \
            ((pruls)->rullims.rulevlMax)
#define PszNameDynLprul(prul) \
            (vlpruls->rgpchDynNames[(prul)->irul - IrulCompiledMax()])
#define RulevlMinOfRulevt(rulevt) \
            (vlpruls->rgrulevlRulevt[(rulevt)])
#define RulevlMaxOfRulevt(rulevt) \
            (vlpruls->rgrulevlRulevt[(rulevt) + 1])
#define FIsDelayFactor(lprulDepend) \
            ((unsigned long) (lprulDepend) < wDelayMax)
#define FIntervalsSeqCheckedPrul(prul) \
            ((prul)->ipfnrulscSeqCheck)
#define WIntervalsSeqCheckedPrul(prul) \
            ((*vlpruls->rgpfnrulscSeqCheck[(prul)->ipfnrulscSeqCheck])())
#define FRulesInited(lpruls)    (lpruls != NULL  &&  lpruls->fInited)

// shell\evtmon\inc\emrultk.h
#define IncrPrultk(pprultk, pirultk, prultkHist, irultkMax) \
            if (++(*pirultk) >= (irultkMax)) \
                { \
                (*pirultk) = 0; \
                (*pprultk) = PrultkFromIrultk(0, prultkHist); \
                } \
            else \
                (*pprultk)++;
#define DecrPrultk(pprultk, pirultk, prultkHist, irultkMax) \
            if (--(*pirultk) < 0) \
                { \
                (*pirultk) += (irultkMax); \
                (*pprultk) += (irultkMax) - 1; \
                } \
            else \
                (*pprultk)--;
#define IncrPirultk(pirultk, dirultk, irultkMax) \
            if (((*pirultk) += dirultk) >= (irultkMax)) \
                (*pirultk) -= (irultkMax);
#define DecrPirultk(pirultk, dirultk, irultkMax) \
            if (((*pirultk) -= dirultk) < 0) \
                (*pirultk) += (irultkMax);

// shell\evtmon\inc\msoem.h
#define ClearLprg(lpv, type, iMax) \
            MsoMemset((lpv), '\0', sizeof(type) * (iMax))
#define MsoPNewEmRg(type, iMax) \
            ((type *) MsoPvAllocEmCb((unsigned int)(sizeof(type) * (iMax))))
#define MsoClearRg(pv, type, iMax) \
            MsoMemset((pv), '\0', sizeof(type) * (iMax))
#define MsoCopyRg(rgFrom, rgTo, type, iMax) \
            MsoMemmove((rgTo), (rgFrom), sizeof(type) * (iMax))
#define MsoCopyRgNo(rgFrom, rgTo, type, iMax) \
            MsoMemcpy((rgTo), (rgFrom), sizeof(type) * (iMax))
#define MsoPReallocEmRg(pv, type, iMax) \
            ((type *) \
                MsoPvReallocEmPvCb \
                    ((pv), (unsigned int) (sizeof(type) * (iMax))))

// shell\evtmon\inc\msolex.h
#define FValidTk(tk) \
            ((tk) > 0)
#define XchLexPeekChar(plexs) \
            ((plexs)->cchRemain > 0 \
                ? *(plexs)->pxchNext \
                : (XchLexGetNextBuffer(msocpMax, plexs), (plexs)->cchRemain++,\
                        *(--(plexs)->pxchNext)))

// shell\explorer\desktop2\sfthost.h
#define _GetUEMPidlInfo(psf, pidl, pueiOut)                 \
        _GetUEMInfo(&UEMIID_SHELL, UEME_RUNPIDL,            \
                reinterpret_cast<WPARAM>(psf),              \
                reinterpret_cast<LPARAM>(pidl), pueiOut)
#define _GetUEMPathInfo(pszPath, pueiOut)                   \
    _GetUEMInfo(&UEMIID_SHELL, UEME_RUNPATH, (WPARAM)-1,    \
                reinterpret_cast<LPARAM>(pszPath), pueiOut)

// shell\explorer\tray.h
#define IS_CURRENT_TVSD(t)  ((t.dwSize >= sizeof(TVSD)) && (t.lSignature < 0))

// shell\ext\brfcase\filesync\core\expandft.c
#define IS_COMPONENT_TERMINATOR(ch)       (! (ch) || (ch) == PERIOD || (ch) == ASTERISK)

// shell\ext\brfcase\filesync\core\reclist.h
#define RECNODE_IS_AVAILABLE(prn)     (RECNODE_EXISTS(prn) || RECNODE_DOES_NOT_EXIST(prn))

// shell\ext\brfcase\filesync\core\stock.h
#define IS_SLASH(ch)                      ((ch) == SLASH || (ch) == BACKSLASH)

// shell\ext\brfcase\filesync\syncui\atoms.h
#define Atom_IsValid(atom)      (ATOM_ERR != (atom) && 0 != (atom))

// shell\ext\docprop\offglue.h
#define RELEASEINTERFACE( punk )            \
        if( punk != NULL )                  \
        {                                   \
            (punk)->lpVtbl->Release(punk);  \
            punk = NULL;                    \
        }

// shell\ext\docpropv3\pch.h
#define TYPESAFEPARAMS( _pinterface ) __uuidof(_pinterface), (void**)&_pinterface

// shell\ext\dsui\dsquery\query.h
#define DSQVM_FINISHED              (WM_USER+1)         // lParam = fMaxResult

// shell\ext\ftp\ftppidl.cpp
#define IDTYPE_SERVER            (0x00000002 | IDTYPE_ISVALID)    // Server
#define IDTYPE_DIR               (0x00000004 | IDTYPE_ISVALID)    // Folder/Dir
#define IDTYPE_FILE              (0x00000008 | IDTYPE_ISVALID)    // File
#define IDTYPE_FILEORDIR         (0x00000010 | IDTYPE_ISVALID)    // File or Dir.  Wasn't specified.
#define IS_FRAGMENT(pFtpIDList)       (IDTYPE_ISVALID != (IDTYPE_FRAGMENT & pFtpIDList->dwIDType))

// shell\ext\ftp\priv.h
#define MAX_URL_STRING                  (INTERNET_MAX_SCHEME_LENGTH \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// shell\ext\hnw\win95\setupx.h
#define MAX_FILENAME_LEN    20      // Max. filename length. ( > sizeof( "x:\\12345678.123" )

// shell\ext\hnw\win95\setupx1.h
#define MAX_FILENAME_LEN    20      // Max. filename length. ( > sizeof( "x:\\12345678.123" )

// shell\ext\hnw\win95\setupx2.h
#define MAX_FILENAME_LEN    20      // Max. filename length. ( > sizeof( "x:\\12345678.123" )

// shell\ext\hnw\win95\setupx3.h
#define MAX_FILENAME_LEN    20      // Max. filename length. ( > sizeof( "x:\\12345678.123" )

// shell\ext\hnw\win95\setupx4.h
#define MAX_FILENAME_LEN    20      // Max. filename length. ( > sizeof( "x:\\12345678.123" )

// shell\ext\hnw\wizard\ntwiz.cpp
#define INVALID_COMPUTERNAME_CHARS L" {|}~[\\]^':;<=>?@!\"#$%^`()+/*&"
#define INVALID_WORKGROUP_CHARS    L"{|}~[\\]^':;<=>?!\"#$%^`()+/*&"

// shell\ext\inetfind\fnd.h
#define pvMaxA(a) (&a[cA(a)])

// shell\ext\keyremap\map.h
#define pvMaxA(a) (&a[cA(a)])

// shell\ext\mlang\cpdetect.h
#define IS_ENCODED_ENCODING(cp) ((cp) == CP_ISO_2022_JP || (cp) == CP_CHN_HZ || (cp) == CP_UTF_7 || (cp) == CP_UTF_8 || (cp) == CP_ISO_2022_KR)

// shell\ext\mlang\private.h
#define IS_CHARA(ch)     (InRange(ch, 'a', 'z') && InRange(ch, 'A', 'Z'))
#define IS_NLS_DLL_CP(x) (InRange(x, 57002, 57011) || ((x) == CP_18030))
#define IS_HINDI_CHAR(x) (InRange(x, 0x0900, 0x0DFF) || InRange(x, 0x0F00, 0x10FF))
#define IS_CJK_CHAR(x)   (InRange(x, 0x3000, 0x9FFF) || InRange(x, 0xAC00, 0xD7A3) || InRange(x, 0xF900, 0xFAFF) || InRange(x, 0xFF00, 0xFFEF))

// shell\ext\mlang\validate.cpp
#define x007c       17		// 0x7c ("|")
#define x007e       19		// 0x7e ("~")

// shell\ext\nsc\nsc.h
#define NSM_GETITEMINFO	(WM_USER + 3)

// shell\ext\occache\utils.h
#define OLEUI_CCHKEYMAX_SIZE    (OLEUI_CCHKEYMAX*sizeof(TCHAR))

// shell\ext\sendmail\sendto.cpp
#define IS_FORCE_LINK(grfKeyState)   ((grfKeyState == (MK_LBUTTON | MK_CONTROL | MK_SHIFT)) || \
                                      (grfKeyState == (MK_LBUTTON | MK_ALT)))
#define IS_FORCE_COPY(grfKeyState)   (grfKeyState == (MK_LBUTTON | MK_CONTROL))

// shell\ext\shtl\cidl.h
#define CB_IDLIST_TERMINATOR (sizeof(USHORT))

// shell\ext\sshow\simstr.h
#define IS_CHAR(x)     (sizeof(x)==sizeof(char))
#define IS_WCHAR(x)    (sizeof(x)==sizeof(wchar_t))

// shell\ext\url\debspew.h
#define IS_VALID_HANDLE(hnd, type) \
   (IsValidH##type(hnd) ? \
    TRUE : \
    (ERROR_OUT(("invalid H" #type " - %#08lx", (hnd))), FALSE))

// shell\ext\url\stock.h
#define IS_SLASH(ch)                      ((ch) == SLASH || (ch) == BACKSLASH)

// shell\ext\webcheck\imnact.h
#define HR_CODE(hr) (INT)(hr & 0xffff)

// shell\ext\webcheck\private.h
#define IsNativeAgent(CLSIDAGENT)       (((CLSIDAGENT) == CLSID_WebCrawlerAgent) || ((CLSIDAGENT) == CLSID_ChannelAgent))
#define IS_VALID_SUBSCRIPTIONTYPE(st)   ((st == SUBSTYPE_URL) || (st == SUBSTYPE_CHANNEL) || (st == SUBSTYPE_DESKTOPCHANNEL) || (st == SUBSTYPE_DESKTOPURL))

// shell\ext\webcheck\schedui.cpp
#define TASK_ALLDAYS                    (TASK_SUNDAY | TASK_MONDAY | TASK_TUESDAY | TASK_WEDNESDAY | TASK_THURSDAY | TASK_FRIDAY | TASK_SATURDAY)
#define TASK_WEEKDAYS                   (TASK_MONDAY | TASK_TUESDAY | TASK_WEDNESDAY | TASK_THURSDAY | TASK_FRIDAY)
#define TASK_WEEKENDDAYS                (TASK_SUNDAY | TASK_SATURDAY)
#define TASK_ALLMONTHS                  (TASK_JANUARY | TASK_FEBRUARY | TASK_MARCH | TASK_APRIL | TASK_MAY | TASK_JUNE | TASK_JULY | TASK_AUGUST | TASK_SEPTEMBER | TASK_OCTOBER | TASK_NOVEMBER | TASK_DECEMBER)

// shell\ext\webcheck\schedui.h
#define SSUI_SCHEDULELISTUPDATED    (SSUI_SCHEDULECREATED | SSUI_SCHEDULECHANGED | SSUI_SCHEDULEREMOVED)

// shell\ext\webcheck\updateui.h
#define IS_PENDING(l)  (((l)==UPDATEALL_PENDING) || ((l)==MULTIPLE_PENDING))

// shell\inc\ccstock.h
#define IS_DC_RTL_MIRRORED(hdc)         (g_bMirroredOS && Mirror_IsDCMirroredRTL(hdc))
#define IS_PROCESS_RTL_MIRRORED()       (g_bMirroredOS && Mirror_IsProcessRTL())
#define IS_SYSTEM_HIDDEN(dw) ((dw & FILE_ATTRIBUTE_SUPERHIDDEN) == FILE_ATTRIBUTE_SUPERHIDDEN)

// shell\inc\desktopp.h
#define DTM_GETVIEWAREAS            (WM_USER + 91)  // View area is WorkArea minus toolbar areas.

// shell\inc\evtmon\emrule.h
#define FValidIrul(irul) \
            ((irul) > 0)
#define RulevtMaxPruls(pruls) \
            ((pruls)->rullims.rulevtMax)
#define RulevlMaxPruls(pruls) \
            ((pruls)->rullims.rulevlMax)
#define PszNameDynLprul(prul) \
            (vlpruls->rgpchDynNames[(prul)->irul - IrulCompiledMax()])
#define RulevlMinOfRulevt(rulevt) \
            (vlpruls->rgrulevlRulevt[(rulevt)])
#define RulevlMaxOfRulevt(rulevt) \
            (vlpruls->rgrulevlRulevt[(rulevt) + 1])
#define FIsDelayFactor(lprulDepend) \
            ((unsigned long) (lprulDepend) < wDelayMax)
#define FIntervalsSeqCheckedPrul(prul) \
            ((prul)->ipfnrulscSeqCheck)
#define WIntervalsSeqCheckedPrul(prul) \
            ((*vlpruls->rgpfnrulscSeqCheck[(prul)->ipfnrulscSeqCheck])())
#define FRulesInited(lpruls)    (lpruls != NULL  &&  lpruls->fInited)

// shell\inc\evtmon\emrultk.h
#define IncrPrultk(pprultk, pirultk, prultkHist, irultkMax) \
            if (++(*pirultk) >= (irultkMax)) \
                { \
                (*pirultk) = 0; \
                (*pprultk) = PrultkFromIrultk(0, prultkHist); \
                } \
            else \
                (*pprultk)++;
#define DecrPrultk(pprultk, pirultk, prultkHist, irultkMax) \
            if (--(*pirultk) < 0) \
                { \
                (*pirultk) += (irultkMax); \
                (*pprultk) += (irultkMax) - 1; \
                } \
            else \
                (*pprultk)--;
#define IncrPirultk(pirultk, dirultk, irultkMax) \
            if (((*pirultk) += dirultk) >= (irultkMax)) \
                (*pirultk) -= (irultkMax);
#define DecrPirultk(pirultk, dirultk, irultkMax) \
            if (((*pirultk) -= dirultk) < 0) \
                (*pirultk) += (irultkMax);

// shell\inc\evtmon\msoem.h
#define ClearLprg(lpv, type, iMax) \
            MsoMemset((lpv), '\0', sizeof(type) * (iMax))
#define MsoPNewEmRg(type, iMax) \
            ((type *) MsoPvAllocEmCb((unsigned int)(sizeof(type) * (iMax))))
#define MsoClearRg(pv, type, iMax) \
            MsoMemset((pv), '\0', sizeof(type) * (iMax))
#define MsoCopyRg(rgFrom, rgTo, type, iMax) \
            MsoMemmove((rgTo), (rgFrom), sizeof(type) * (iMax))
#define MsoCopyRgNo(rgFrom, rgTo, type, iMax) \
            MsoMemcpy((rgTo), (rgFrom), sizeof(type) * (iMax))
#define MsoPReallocEmRg(pv, type, iMax) \
            ((type *) \
                MsoPvReallocEmPvCb \
                    ((pv), (unsigned int) (sizeof(type) * (iMax))))

// shell\inc\evtmon\msolex.h
#define FValidTk(tk) \
            ((tk) > 0)
#define XchLexPeekChar(plexs) \
            ((plexs)->cchRemain > 0 \
                ? *(plexs)->pxchNext \
                : (XchLexGetNextBuffer(msocpMax, plexs), (plexs)->cchRemain++,\
                        *(--(plexs)->pxchNext)))

// shell\inc\trayp.h
#define TBC_CANMINIMIZEALL          (WM_USER + 52)
#define TBC_MINIMIZEALL             (WM_USER + 53)

// shell\osshell\accesory\calendar\cal.h
#define CBMINEARLYRING sizeof (SINT)
#define CBMININTERVAL sizeof (SINT)

// shell\osshell\accesory\hypertrm\tdll\bv_text.hh
#define STEXT_OK(x) 	((x!=NULL)&&(x->ulCheck==STEXT_VALID))

// shell\osshell\accesory\hypertrm\tdll\stdtyp.h
#define IN_RANGE(n, lo, hi) ((lo) <= (n) && (n) <= (hi))

// shell\osshell\accesory\hypertrm\tdll\vu_meter.hh
#define VUMETER_OK(x)	((x!=NULL)&&(x->ulCheck==VUMETER_VALID))

// shell\osshell\accesory\mspaint\tedit.h
#define IS_DBCS_CHARSET( charset )         ( (charset == GB2312_CHARSET) || \
                                             (charset == SHIFTJIS_CHARSET) || \
                                             (charset == HANGEUL_CHARSET) || \
                                             (charset == CHINESEBIG5_CHARSET) )

// shell\osshell\accesory\quickres\quickres.h
#define fGoodMode(x)  ((x)->uValidMode & 0x1)

// shell\osshell\accesory\ratpak\ratpak.h
#define TRIMNUM(x) if ( !ftrueinfinite ) { \
		long trim = (x)->cdigit - maxout-ratio;\
            if ( trim > 1 ) \
                { \
memmove( MANT(x), &(MANT(x)[trim]), sizeof(MANTTYPE)*((x)->cdigit-trim) ); \
                (x)->cdigit -= trim; \
                (x)->exp += trim; \
                } \
            }
#define TRIMTOP(x) if ( !ftrueinfinite ) { \
		long trim = (x)->pp->cdigit - (maxout/ratio) - 2;\
            if ( trim > 1 ) \
                { \
memmove( MANT((x)->pp), &(MANT((x)->pp)[trim]), sizeof(MANTTYPE)*((x)->pp->cdigit-trim) ); \
                (x)->pp->cdigit -= trim; \
                (x)->pp->exp += trim; \
                } \
            trim = min((x)->pp->exp,(x)->pq->exp);\
            (x)->pp->exp -= trim;\
            (x)->pq->exp -= trim;\
            }
#define SMALL_ENOUGH_RAT(a) (zernum(a->pp) || ( ( ( a->pq->cdigit + a->pq->exp ) - ( a->pp->cdigit + a->pp->exp ) - 1 ) * ratio > maxout ) || fhalt )

// shell\osshell\accesory\terminal\dynacomm.h
#define ctl(ch)     ((ch) ^ 64 )
#define unpar(ch)   ((ch) & 127)
#define invalRect(rectangle)     InvalidateRect(hTermWnd, (LPRECT) &rectangle)
#define validRect(rectangle)     ValidateRect(hTermWnd, (LPRECT) &rectangle)
#define stringToNum(str,num)     sscanf(&str[1], "%ld", num)

// shell\osshell\accesory\terminal\fsemacro.h
#define GET_WM_MENUSELECT_HMENU(w, l)           ((HMENU) l)

// shell\osshell\accessib\accwiz\schemes.cpp
#define SYSPARAMINFO(xxx) m_##xxx.cbSize = sizeof(m_##xxx);SystemParametersInfo(SPI_GET##xxx, sizeof(m_##xxx), &m_##xxx, 0)

// shell\osshell\accessib\osk\inc\sendkeys.h
#define INRANGE(low, val, high) ((low <= val) && (val <= high))

// shell\osshell\control\console\font.h
#define TM_IS_TT_FONT(x)     (((x) & TMPF_TRUETYPE) == TMPF_TRUETYPE)

// shell\osshell\control\joy\joycal.c
#define NEWMINMAX( a ) \
    if( pji->dw##a##pos > pcv->jr.jpMax.dw##a ) { \
	pcv->jr.jpMax.dw##a = pji->dw##a##pos; \
    } \
    if( pji->dw##a##pos < pcv->jr.jpMin.dw##a ) { \
	pcv->jr.jpMin.dw##a = pji->dw##a##pos; \
    } \
#define SIMULATECALIBRATION(_pcv,_pji,_AXIS_) \
    { \
        NEWMINMAX(_AXIS_); \
        _pji->dw##_AXIS_##pos -= _pcv->jr.jpMin.dw##_AXIS_; \
        if (_pcv->jr.jpMax.dw##_AXIS_ - _pcv->jr.jpMin.dw##_AXIS_ < CAL_MIN) { \
            _pji->dw##_AXIS_##pos = (RANGE_MAX -RANGE_MIN)/2; \
        } else if ( RANGE_MAX == RANGE_MIN ) { \
            _pji->dw##_AXIS_##pos = (RANGE_MAX -RANGE_MIN)/2; \
        } else { \
            _pji->dw##_AXIS_##pos *= (RANGE_MAX-RANGE_MIN); \
            _pji->dw##_AXIS_##pos /= ( _pcv->jr.jpMax.dw##_AXIS_ - \
                                       _pcv->jr.jpMin.dw##_AXIS_ ); \
        } \
        _pji->dw##_AXIS_##pos += RANGE_MIN; \
    }

// shell\osshell\control\joy\joymisc.c
#define ADJ_VAL( a, pos, range ) (((pos-(pgv->joyRange.jpMin.dw##a))*range)/ \
			(pgv->joyRange.jpMax.dw##a-pgv->joyRange.jpMin.dw##a+1))

// shell\osshell\control\scrnsave\flyingobjects\flyingobjects.h
#define SS_MAX( a, b ) \
    ( a > b ? a : b )
#define SS_MIN( a, b ) \
    ( a < b ? a : b )

// shell\osshell\control\scrnsave\swoosh\swoosh.cpp
#define	DEFAULT_AND_BOUND_FLOAT(v,d,l,h) if (rc!=ERROR_SUCCESS||!_finite(v)){v=d;}else if(v<l){v=l;}else if(v>h){v=h;};

// shell\osshell\cpls\ports\ports.c
#define IN_RANGE(value, minval, maxval) ((minval) <= (value) && (value) <= (maxval))

// shell\osshell\ep\winmine\main.h
#define FMenuOn()          ((Preferences.fMenu &  0x01) == 0)

// shell\osshell\ep\winmine\rtns.c
#define fValidStep(x,y)  (! (fVISIT(x,y) || fGUESSBOMB(x,y)) )

// shell\osshell\ep\winmine\rtns.h
#define fInRange(x,y)   (((x)>0) && ((y)>0) && ((x)<=xBoxMac) && ((y)<=yBoxMac))

// shell\osshell\fontfldr\fontext\inc\oeminf.h
#define IS_PATH_SEPARATOR(c)  ((c) == TEXT( '\\' ) || (c) == TEXT( '/' ) || (c) == TEXT( ':' ))
#define IS_SLASH(c)           ((c) == TEXT( '\\' ) || (c) == TEXT( '/' ))

// shell\osshell\lmui\shareui\shitemid.h
#define SHID_NET_SHAREADMIN     (SHID_NET | RESOURCEDISPLAYTYPE_SHAREADMIN)

// shell\osshell\themes\inc\shlobj.h
#define COMP_ELEM_ALL   (COMP_ELEM_TYPE | COMP_ELEM_CHECKED | COMP_ELEM_DIRTY |          \
                         COMP_ELEM_NOSCROLL | COMP_ELEM_POS_LEFT | COMP_ELEM_SIZE_WIDTH  \
                         COMP_ELEM_SIZE_HEIGHT | COMP_ELEM_POS_ZINDEX | COMP_ELEM_SOURCE \
                         COMP_ELEM_FRIENDLYNAME )

// shell\osshell\themes\inc\wininet.h
#define IS_GOPHER_DIRECTORY(type)       (BOOL)(((type) & GOPHER_TYPE_DIRECTORY) ? TRUE : FALSE)
#define IS_GOPHER_PHONE_SERVER(type)    (BOOL)(((type) & GOPHER_TYPE_CSO) ? TRUE : FALSE)
#define IS_GOPHER_ERROR(type)           (BOOL)(((type) & GOPHER_TYPE_ERROR) ? TRUE : FALSE)
#define IS_GOPHER_INDEX_SERVER(type)    (BOOL)(((type) & GOPHER_TYPE_INDEX_SERVER) ? TRUE : FALSE)
#define IS_GOPHER_TELNET_SESSION(type)  (BOOL)(((type) & GOPHER_TYPE_TELNET) ? TRUE : FALSE)
#define IS_GOPHER_BACKUP_SERVER(type)   (BOOL)(((type) & GOPHER_TYPE_REDUNDANT) ? TRUE : FALSE)
#define IS_GOPHER_TN3270_SESSION(type)  (BOOL)(((type) & GOPHER_TYPE_TN3270) ? TRUE : FALSE)
#define IS_GOPHER_ASK(type)             (BOOL)(((type) & GOPHER_TYPE_ASK) ? TRUE : FALSE)
#define IS_GOPHER_PLUS(type)            (BOOL)(((type) & GOPHER_TYPE_GOPHER_PLUS) ? TRUE : FALSE)
#define IS_GOPHER_TYPE_KNOWN(type)      (BOOL)(((type) & GOPHER_TYPE_UNKNOWN) ? FALSE : TRUE)

// shell\shdocvw\hist\cafolder.h
#define IS_VALID_CEIPIDL(pidl)      ((pidl)                                     && \
                                     (((LPCEIPIDL)pidl)->cb >= sizeof(CEIPIDL)) && \
                                     (((LPCEIPIDL)pidl)->usSign == (USHORT)CEIPIDL_SIGN))

// shell\shdocvw\hist\hsfolder.cpp
#define IS_DIGIT_CHAR(x) (((x) >= '0') && ((x) <= '9'))

// shell\shdocvw\hist\local.h
#define IS_EQUAL_VIEWPIDL(pidl1,pidl2)  ((IS_VALID_VIEWPIDL(pidl1)) && (IS_VALID_VIEWPIDL(pidl2)) && \
                                         (((LPVIEWPIDL)pidl1)->usViewType == ((LPVIEWPIDL)pidl2)->usViewType) && \
                                         (((LPVIEWPIDL)pidl1)->usExtra    == ((LPVIEWPIDL)pidl2)->usExtra))

// shell\shdocvw\priv.h
#define DLL_IS_UNICODE         (sizeof(TCHAR) == sizeof(WCHAR))

// shell\shell32\copy.c
#define DTNIsConnectOrigin(pdtn) ((!pdtn->fConnectedElement) && (pdtn->pdtnConnected != NULL))

// shell\shell32\filefldr.cpp
#define SHCF_IS_BROWSABLE           (SHCF_IS_SHELLEXT | SHCF_IS_DOCOBJECT)

// shell\shell32\finddlg.h
#define WMU_BANDINFOUPDATE              (WM_USER+0x204) // (wParam: NULL).
#define WMU_BANDFINISHEDDISPLAYING      (WM_USER+0x306) // (wParam: NULL).

// shell\shell32\findfldr.cpp
#define MAX_LISTVIEWITEMS  (100000000 & ~0xFFFF)
#define MAX_LISTVIEWITEMS  (100000000 & ~0xFFFF)

// shell\shell32\fsdrptgt.cpp
#define  FSDH(pfn, cf, dva, tymed) { {              0, NULL, dva, -1, tymed }, pfn, &cf  }

// shell\shell32\init.c
#define ValidateORD(_name) _ValidateExport((FARPROC)_name, (LPSTR)MAKEINTRESOURCE(DEREFMACRO(_name##ORD)), &mbi)

// shell\shell32\limitinput.cpp
#define CHAR_IN_RANGE(ch,l,h)   ((ch >= l) && (ch <= h))

// shell\shell32\lnkcon.h
#define IS_ANY_DBCS_CHARSET( CharSet )                              \
                   ( ((CharSet) == SHIFTJIS_CHARSET)    ? TRUE :    \
                     ((CharSet) == HANGEUL_CHARSET)     ? TRUE :    \
                     ((CharSet) == CHINESEBIG5_CHARSET) ? TRUE :    \
                     ((CharSet) == GB2312_CHARSET)      ? TRUE : FALSE )
#define TM_IS_TT_FONT(x)     (((x) & TMPF_TRUETYPE) == TMPF_TRUETYPE)

// shell\shell32\menuband\common.h
#define DLL_IS_UNICODE         (sizeof(TCHAR) == sizeof(WCHAR))

// shell\shell32\mergfldr.cpp
#define CB_IDLIST_TERMINATOR    sizeof(USHORT)

// shell\shell32\obexerr.h
#define IS_OBEX_ERR(x)          ( (x & 0x00000F00) == 0x0300 )

// shell\shell32\piffnt.c
#define OEMCharsetFromCP(cp) \
    ((cp)==CP_JPN? SHIFTJIS_CHARSET : ((cp)==CP_WANSUNG? HANGEUL_CHARSET : OEM_CHARSET))

// shell\shell32\pifsub.c
#define achFmt (&achBuf[MAX_STRING_SIZE])

// shell\shell32\prop.cpp
#define MAX_UTF8_CHAR_SIZE        (sizeof(CHAR) * 3)

// shell\shell32\shitemid.h
#define SHID_NET_SHAREADMIN     (SHID_NET | RESOURCEDISPLAYTYPE_SHAREADMIN)     // 0x48

// shell\shell32\treewalk.cpp
#define IS_FILE_DIRECTORY(pwfd)     ((pwfd)->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)

// shell\shell32\unicpp\deskmovr.cpp
#define CAPTION_ONLY (m_ItemState & (IS_FULLSCREEN | IS_SPLIT))
#define ISNORMAL (m_ItemState & IS_NORMAL)
#define ISFULLSCREEN (m_ItemState & IS_FULLSCREEN)
#define ISSPLIT (m_ItemState & IS_SPLIT)

// shell\shell32\unicpp\dutil.h
#define ISZOOMED(x)                 (((x)->dwCurItemState & IS_SPLIT) || ((x)->dwCurItemState & IS_FULLSCREEN))
#define IsZoomedState(itemState)    ((((itemState) & IS_SPLIT) != 0) || (((itemState) & IS_FULLSCREEN) != 0))

// shell\shell32\util.cpp
#define IS_ALPHA(ch)    (IS_LOWER(ch) || IS_UPPER(ch))

// shell\shell32\ynlist.c
#define YNLIST_ALLOC    (2 * MAX_PATH * sizeof(TCHAR))

// shell\shlwapi\mlui.cpp
#define MAX_REG_WINMSG      0xFFFF      // max value returned from RegisterWindowMessageA()
#define MIN_REG_WINMSG      0xC000      // min value returned from RegisterWindowMessageA()

// shell\shlwapi\unicwrap.cpp
#define MENUITEMINFOSIZE_WIN95  sizeof(MENUITEMINFOW)

// shell\themes\inc\scanner.h
#define IS_NAME_CHAR(p) ((isalnum(*p)) || (*p == '_') || (*p == '-'))

// shell\themes\themeldr\signing.cpp
#define IS_DIGITW(x)   (((x) >= L'0') && ((x) <= L'9'))

// shell\themes\themeui\exe.cpp
#define FOPEN(sz)                CreateFile(sz, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL )
#define FREAD(fh,buf,len)        (ReadFile(fh,buf,len, &dwDummy, NULL) ? dwDummy : HFILE_ERROR)

// shell\themes\themeui\priv.h
#define MAX_URL_STRING                  (INTERNET_MAX_SCHEME_LENGTH \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// shell\themes\uxtheme\nctheme.cpp
#define HAS_CAPTIONBAR( dwStyle )        (WS_CAPTION == ((dwStyle) & WS_CAPTION))

// shell\themes\uxtheme\scroll.cpp
#define CheckMsgFilter(wMsg, wMsgFilterMin, wMsgFilterMax)                 \
    (   ((wMsgFilterMin) == 0 && (wMsgFilterMax) == 0xFFFFFFFF)            \
     || (  ((wMsgFilterMin) > (wMsgFilterMax))                             \
         ? (((wMsg) <  (wMsgFilterMax)) || ((wMsg) >  (wMsgFilterMin)))    \
         : (((wMsg) >= (wMsgFilterMin)) && ((wMsg) <= (wMsgFilterMax)))))

// shell\themes\uxtheme\scrollp.h
#define CheckMsgFilter(wMsg, wMsgFilterMin, wMsgFilterMax)                 \
    (   ((wMsgFilterMin) == 0 && (wMsgFilterMax) == 0xFFFFFFFF)            \
     || (  ((wMsgFilterMin) > (wMsgFilterMax))                             \
         ? (((wMsg) <  (wMsgFilterMax)) || ((wMsg) >  (wMsgFilterMin)))    \
         : (((wMsg) >= (wMsgFilterMin)) && ((wMsg) <= (wMsgFilterMax)))))

// shell\themes\uxtheme\sethook.h
#define IS_THEME_CHANGE_TARGET(lParam) \
    ((! g_pAppInfo->CustomAppTheme()) || (lParam & WTC_CUSTOMTHEME))

// shell\tools\cleaninf\parse.cpp
#define IS_WHITESPACE(ch)   (' ' == ch || '\t' == ch)

// shell\tools\starbuck\priv.h
#define MAX_URL_STRING                  (INTERNET_MAX_SCHEME_LENGTH \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

// termsrv\admtools\c2config\c2config\listwnd.h
#define  LB_SET_MIN_WIDTH  (WM_USER + 205)

// termsrv\admtools\c2config\c2config\splash.c
#define SWM_CHECK_COMPLETE    (WM_USER + 201)

// termsrv\admtools\utildll\utildll.c
#define MAX_DOMAINANDNAME     ((DOMAIN_LENGTH+1+USERNAME_LENGTH+1)*sizeof(WCHAR))

// termsrv\clcreator\netutils.c
#define NCDU_VALIDATE_AND_END       (WM_USER    +103)

// termsrv\clcreator\otnboot.h
#define NCDU_SHOW_COPY_ADMIN_UTILS  (WM_USER+19)

// termsrv\clcreator\sharenet.c
#define NCDU_VALIDATE_AND_END       (WM_USER    +103)

// termsrv\inc\at120ex.h
#define _RNS_MINOR_VERSION(x)   (x & 0x0000ffff)
#define RNS_UD_MINOR_VERSION    (RNS_UD_VERSION & 0x0000ffff)

// termsrv\inc\license.h
#define IS_LICENSE_ISSUER_ENFORCE(dwVersion) \
    (((dwVersion) & LICENSE_ISSUER_ENFORCE_TYPE) > 0)
#define IS_LICENSE_ISSUER_RTM(dwVersion) \
    (((dwVersion) & LICENSED_VERSION_RTM) > 0)
#define IS_TEMP_CERTIFICATE( x )        ( 0xF0000000 & x )

// termsrv\license\tlserver\include\lscommon.h
#define IS_ENFORCE_VERSION(x) (x & 0x80000000)

// termsrv\license\tlserver\include\tlsapip.h
#define IS_ENFORCE_LSSERVER(version) \
    ((version & 0x40000000) > 0)

// termsrv\license\tlserver\server\srvdef.h
#define IS_ENFORCE_SERVER(version) \
    ((version & 0x40000000) > 0)

// termsrv\perfts\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? DELIMITER : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// termsrv\regapi\regup.c
#define CTX_USER_PARAM_MAX_SIZE (3 * sizeof(USERCONFIG))

// termsrv\remdsk\rds\as\as16\winddi.h
#define CRECTS_MAX          ((0x4000 - sizeof(RDH)) / sizeof(RECTL))

// termsrv\remdsk\rds\as\cpi32\bcd.cpp
#define CHECK_BEST_RUN(run_type, run_length, bestrun_length, bestrun_type)   \
        if (run_length > bestrun_length)                                     \
        {                                                                    \
            bestrun_length = run_length;                                     \
            bestrun_type = run_type;                                         \
            if (bestrun_length >= 32)                                        \
            {                                                                \
                break;                                                       \
            }                                                                \
        }

// termsrv\remdsk\rds\as\h\ast120.h
#define MG_VALID_PRIORITY(p)                                                 \
    ((((p)&~NET_SEND_ALL_PRIORITIES)<MG_HIGH_PRIORITY)?                      \
      (MG_HIGH_PRIORITY|((p)&NET_SEND_ALL_PRIORITIES)):                      \
      (((p)&~NET_SEND_ALL_PRIORITIES)>MG_LOW_PRIORITY)?                      \
        (MG_LOW_PRIORITY|((p)&NET_SEND_ALL_PRIORITIES)):                     \
        (p))

// termsrv\remdsk\rds\as\h\ch.h
#define IsValidCacheIndex(pCache, iEntry) \
    ((iEntry >= 0) && (iEntry < (pCache)->cEntries))

// termsrv\remdsk\rds\as\h\gdc.h
#define GDC_WORKBUF_SIZE    max(sizeof(GDC_IMPLODE), sizeof(GDC_EXPLODE))

// termsrv\remdsk\rds\as\h\im.h
#define IM_KEY_IS_TOGGLE(A) \
(((A)==VK_CAPITAL)||((A)==VK_SCROLL)||((A)==VK_NUMLOCK))
#define IM_KEY_IS_MODIFIER(A) \
(((A)==VK_SHIFT)||((A)==VK_CONTROL)||((A)==VK_MENU))

// termsrv\remdsk\rds\as\h\oa.h
#define MAX_ORDER_SIZE(pOrder) \
(INT_ORDER_SIZE(pOrder) + (pOrder->OrderHeader.cbAdditionalOrderDataLength))

// termsrv\remdsk\rds\dev\inc16\mmsystem.h
#define MIDI_CACHE_VALID    (MIDI_CACHE_ALL | MIDI_CACHE_BESTFIT | MIDI_CACHE_QUERY | MIDI_UNCACHE)     // ;internal
#define MMIO_DESCEND_VALID (MMIO_FINDCHUNK | MMIO_FINDRIFF | MMIO_FINDLIST) // ;internal
#define MMIO_CREATE_VALID (MMIO_CREATERIFF | MMIO_CREATELIST)   // ;internal

// termsrv\remdsk\rds\dev\inc16\windows.h
#define TME_VALID (TME_HOVER | TME_LEAVE | TME_NONCLIENT | TME_QUERY | TME_CANCEL) // ;Internal
#define SBM_SETRANGE        (WM_USER+2)                     // ;Internal
#define SBM_GETRANGE        (WM_USER+3)                     // ;Internal
#define SBM_SETRANGEREDRAW  (WM_USER+6)                     // ;Internal 4.0
#define SBM_MSGMAX          (WM_USER+11)                    // ;Internal 4.0
#define STM_MSGMAX         (WM_USER+4)      // ;Internal 4.0
#define BM_GETCHECK         (WM_USER+0)
#define BM_SETCHECK         (WM_USER+1)
#define BM_MSGMAX           (WM_USER+8)     // ;Internal 4.0
#define EM_MSGMAX               (WM_USER+42)    // ;Internal 4.0
#define LB_SELITEMRANGEEX       (WM_USER+4)     // ;Internal 4.0 NT
#define LB_SELITEMRANGE         (WM_USER+28)
#define LB_MSGMAX               (WM_USER+47)    // ;Internal
#define CB_MSGMAX               (WM_USER+34)    // ;Internal 4.0

// termsrv\remdsk\rds\h\debspew.h
#define IS_VALID_HANDLE(hnd, type) \
   (IsValidH##type(hnd) ? \
    TRUE : \
    (ERROR_OUT(("invalid H" #type " - %#08lx", (hnd))), FALSE))

// termsrv\remdsk\rds\h\stock.h
#define IS_SLASH(ch)                      ((ch) == SLASH || (ch) == BACKSLASH)

// termsrv\remdsk\rds\t120\h\mcattprt.h
#define IS_VALID_TRANSPORT_CONNECTION_TYPE(x) (IS_SOCKET(x) || IS_PLUGGABLE_X224(x) || IS_PLUGGABLE_PSTN(x))

// termsrv\remdsk\rds\t120\h\memmgr.h
#define GetMemoryObject(p)				((PMemory) ((PUChar) p - (sizeof(Memory) + MAXIMUM_PROTOCOL_OVERHEAD)))

// termsrv\tsappcmp\inimap.c
#define IS_NEWLINE_CHAR( c )  ((c == 0x0D) || (c == 0x0A))

// termsrv\tsappcmp\regmap.h
#define IS_NEWLINE_CHAR( c )  ((c == 0x0D) || (c == 0x0A))

// termsrv\wtsapi\virtual.c
#define ValidVCHandle(hVC) ((hVC) && ((hVC)->Signature == VCHANDLE_SIGNATURE))

// tools\x86\perl\lib\core\hv.h
#define HePV(he,lp)		((HeKLEN(he) == HEf_SVKEY) ?		\
				 SvPV(HeKEY_sv(he),lp) :		\
				 (((lp = HeKLEN(he)) >= 0) ?		\
				  HeKEY(he) : Nullch))
#define HeSVKEY(he)		((HeKEY(he) && 				\
				  HeKLEN(he) == HEf_SVKEY) ?		\
				 HeKEY_sv(he) : Nullsv)

// tools\x86\perl\lib\core\mg.h
#define SvTIED_mg(sv,how) \
    (SvRMAGICAL(sv) ? mg_find((sv),(how)) : Null(MAGIC*))

// tools\x86\perl\lib\core\perl.h
#    define PERL_UCHAR_MAX       ((unsigned char)~(unsigned)0)
#      define PERL_USHORT_MAX       ((unsigned short)~(unsigned)0)
#      define PERL_SHORT_MIN        (-PERL_SHORT_MAX - ((3 & -1) == 3))
#    define PERL_UINT_MAX       (~(unsigned int)0)
#    define PERL_INT_MIN        (-PERL_INT_MAX - ((3 & -1) == 3))
#    define PERL_ULONG_MAX       (~(unsigned long)0)
#    define PERL_LONG_MIN        (-PERL_LONG_MAX - ((3 & -1) == 3))
#    define PERL_UQUAD_MAX	(~(UV)0)
#    define PERL_QUAD_MIN 	(-PERL_QUAD_MAX - ((3 & -1) == 3))

// tools\x86\perl\lib\core\pp.h
#define EXTEND(p,n)	STMT_START { if (PL_stack_max - p < (n)) {		\
			    sp = stack_grow(sp,p, (int) (n));		\
			} } STMT_END
#define EXTEND_MORTAL(n) \
	STMT_START { \
	    if (PL_tmps_ix + (n) >= PL_tmps_max) \
		Renew(PL_tmps_stack, PL_tmps_max = PL_tmps_ix + (n) + 1, SV*); \
	} STMT_END

// tools\x86\perl\lib\core\scope.h
#define SAVEHINTS() \
    STMT_START {				\
	if (PL_hints & HINT_LOCALIZE_HH)	\
	    save_hints();			\
	else {					\
	    SSCHECK(2);				\
	    SSPUSHINT(PL_hints);		\
	    SSPUSHINT(SAVEt_HINTS);		\
	}					\
    } STMT_END

// tools\x86\perl\lib\core\win32thread.h
#define MUTEX_INIT(m) \
    STMT_START {						\
	if ((*(m) = CreateMutex(NULL,FALSE,NULL)) == NULL)	\
	    croak("panic: MUTEX_INIT");				\
    } STMT_END
#define COND_INIT(c) \
    STMT_START {						\
	(c)->waiters = 0;					\
	(c)->sem = CreateSemaphore(NULL,0,LONG_MAX,NULL);	\
	if ((c)->sem == NULL)					\
	    croak("panic: COND_INIT (%ld)",GetLastError());	\
    } STMT_END

// tools\x86\perl\lib\core\xsub.h
# define XS_VERSION_BOOTCHECK \
    STMT_START {							\
	SV *tmpsv; STRLEN n_a;						\
	char *vn = Nullch, *module = SvPV(ST(0),n_a);			\
	if (items >= 2)	 /* version supplied as bootstrap arg */	\
	    tmpsv = ST(1);						\
	else {								\
	    /* XXX GV_ADDWARN */					\
	    tmpsv = perl_get_sv(form("%s::%s", module,			\
				  vn = "XS_VERSION"), FALSE);		\
	    if (!tmpsv || !SvOK(tmpsv))					\
		tmpsv = perl_get_sv(form("%s::%s", module,		\
				      vn = "VERSION"), FALSE);		\
	}								\
	if (tmpsv && (!SvOK(tmpsv) || strNE(XS_VERSION, SvPV(tmpsv, n_a))))	\
	    croak("%s object version %s does not match %s%s%s%s %_",	\
		  module, XS_VERSION,					\
		  vn ? "$" : "", vn ? module : "", vn ? "::" : "",	\
		  vn ? vn : "bootstrap parameter", tmpsv);		\
    } STMT_END

// tools\x86\perl\site\lib\xml\parser\expat\xmltok\xmltok.c
#define UTF8_INVALID3(p) \
  ((*p) == 0xED \
  ? (((p)[1] & 0x20) != 0) \
  : ((*p) == 0xEF \
     ? ((p)[1] == 0xBF && ((p)[2] == 0xBF || (p)[2] == 0xBE)) \
     : 0))
#define UTF8_INVALID4(p) ((*p) == 0xF4 && ((p)[1] & 0x30) != 0)

// windows\advcore\ctf\inc\ccstock.h
#define IS_DC_RTL_MIRRORED(hdc)         (g_bMirroredOS && Mirror_IsDCMirroredRTL(hdc))
#define IS_PROCESS_RTL_MIRRORED()       (g_bMirroredOS && Mirror_IsProcessRTL())

// windows\advcore\ctf\inputdll\inputdlg.h
#define IS_DIRECT_SWITCH_HOTKEY(p)                                   \
                             (((p) >= IME_HOTKEY_DSWITCH_FIRST) &&   \
                              ((p) <= IME_HOTKEY_DSWITCH_LAST))

// windows\advcore\ctf\uim\memcache.h
#define DECLARE_CACHED_NEW_STATIC(the_class)   \
    MEMCACHE *the_class::_s_pMemCache = NULL;

// windows\advcore\duser\directui\engine\parser\scan.cpp
#define yy_set_interactive(is_interactive) \
    { \
    if ( ! yy_current_buffer ) \
        yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
    yy_current_buffer->yy_is_interactive = is_interactive; \
    }

// windows\advcore\duser\engine\objectapi\validate.h
#define BEGIN_API_NOCONTEXT()                   \
    HRESULT retval = DU_E_GENERIC;              \
#define END_API_NOCONTEXT()                     \
    goto ErrorExit;                             \
ErrorExit:                                      \
    return retval;

// windows\advcore\gdiplus\engine\common\rasterizer.hpp
#define QUOTIENT_REMAINDER_64_32(ullNumerator, ulDenominator, ulQuotient, ulRemainder)\
{                                                                            \
    ULONG ulNumeratorLow = *((ULONG*) &ullNumerator);                        \
    ULONG ulNumeratorHigh = *((ULONG*) &ullNumerator + 1);                   \
    __asm mov eax, ulNumeratorLow                                            \
    __asm mov edx, ulNumeratorHigh                                           \
    __asm div ulDenominator                                                  \
    __asm mov ulQuotient, eax                                                \
    __asm mov ulRemainder, edx                                               \
}

// windows\advcore\gdiplus\engine\entry\metaplay.cpp
#define EMFPLUS_MINORVERSION(v)             ((v) & 0x0000FFFF)
#define MULTIFORMATSTARTEPR_MINSIZE    (sizeof(UINT32) + sizeof(UINT32))
#define SAVEEPR_MINSIZE    (sizeof(UINT32))
#define RESTOREEPR_MINSIZE    (sizeof(UINT32))
#define TRANSLATEWORLDTRANSFORMEPR_MINSIZE    (sizeof(REAL) + sizeof(REAL))
#define ROTATEWORLDTRANSFORMEPR_MINSIZE    (sizeof(REAL))
#define SETCLIPRECTEPR_MINSIZE    (sizeof(GpRectF))
#define OBJECTEPR_MINSIZE    (sizeof(UINT32))
#define CLEAREPR_MINSIZE    (sizeof(UINT32))
#define FILLRECTSEPR_MINSIZE    (sizeof(UINT32) + sizeof(UINT32))
#define DRAWRECTSEPR_MINSIZE    (sizeof(UINT32))
#define FILLPOLYGONEPR_MINSIZE    (sizeof(UINT32) + sizeof(UINT32))
#define DRAWLINESEPR_MINSIZE    (sizeof(UINT32))
#define FILLELLIPSEEPR_MINSIZE    (sizeof(UINT32))
#define FILLPIEEPR_MINSIZE    (sizeof(UINT32) + sizeof(REAL) + sizeof(REAL))
#define DRAWPIEEPR_MINSIZE    (sizeof(REAL) + sizeof(REAL))
#define DRAWARCEPR_MINSIZE    (sizeof(REAL) + sizeof(REAL))
#define FILLREGIONEPR_MINSIZE    (sizeof(UINT32))
#define FILLPATHEPR_MINSIZE    (sizeof(UINT32))
#define DRAWPATHEPR_MINSIZE    (sizeof(UINT32))
#define DRAWCURVEEPR_MINSIZE    (sizeof(REAL) + sizeof(INT32) + sizeof(UINT32) + sizeof(UINT32))
#define DRAWBEZIERSEPR_MINSIZE    (sizeof(UINT32))
#define DRAWIMAGEEPR_MINSIZE    (sizeof(INT32) + sizeof(GpRectF))
#define DRAWSTRINGEPR_MINSIZE    (sizeof(UINT32) + sizeof(UINT32) + sizeof(UINT32) + sizeof(GpRectF))
#define DRAWDRIVERSTRINGEPR_MINSIZE    (sizeof(UINT32) + sizeof(INT) + sizeof(UINT32) + sizeof(UINT32))

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\fontfile.h
#define IS_CLEARTYPE_NATURAL(pfc)       ((pfc->flFontType & FO_CLEARTYPE_GRID) && !(pfc->flFontType & FO_COMPATIBLE_WIDTH))
#define IS_CLEARTYPE(pfc)       ((pfc->flFontType & FO_CLEARTYPE_GRID) || (pfc->flFontType & FO_CLEARTYPE))

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\tt.h
#define B_INT8(x)    (((x) <= MAX_INT8) && ((x) >= MIN_INT8))
#define B_INT16(x)   (((x) <= MAX_INT16) && ((x) >= MIN_INT16))
#define B_INT32(x)   (((x) <= MAX_INT32) && ((x) >= MIN_INT32))

// windows\advcore\gdiplus\engine\imaging\api\codecmgr.cpp
    #define LOADRSRCSTR(_f)                             \
            WCHAR _f##Str[MAX_PATH];                    \
            INT _f##Len;                                \
            _f##Len = _LoadString(                      \
                        DllInstance,                    \
                        BuiltinCodecs[index]._f##Id,    \
                        _f##Str,                        \
                        MAX_PATH);                      \
            if (_f##Len <= 0) continue;                 \
            _f##Len = (_f##Len + 1) * sizeof(WCHAR)
    #define LOADRSRCSTR(_f)                                         \
            WCHAR _f##Str[MAX_PATH];                                \
            INT _f##Len;                                            \
            _f##Len = UnicodeStringLength(BuiltinCodecs[index]._f##Str);         \
            if (_f##Len <= 0) continue;                             \
            _f##Len = (_f##Len + 1) * sizeof(WCHAR);                \
            memcpy(_f##Str, BuiltinCodecs[index]._f##Str, _f##Len)

// windows\advcore\gdiplus\engine\imaging\png\libpng\spngconf.h
#define FPNGSAFETOCOPY(c) (((c) & PNGCHUNK(0,0,0,0x20)) != 0)

// windows\advcore\gdiplus\engine\imaging\png\zlib\deflate.c
#define INSERT_STRING(s, str, match_head) \
   (UPDATE_HASH(s, s->ins_h, s->window[(str) + (MIN_MATCH-1)]), \
    match_head = (IPos)s->head[s->ins_h], \
    s->head[s->ins_h] = (Pos)(str))

// windows\advcore\gdiplus\test\simpsons\mdmutils.h
#define INRANGE(x, xmin, xmax) 	(((x) >= (xmin)) && ((x) <= (xmax)))
#define CLAMP(x, xmin, xmax) MACSTART \
	if ((x) > (xmax)) (x) = (xmax); \
	else if ((x) < (xmin)) (x) = (xmin); \
MACEND

// windows\appcompat\sdbapi\sdbp.h
#define SDBCONTEXT_IS_INSTRUMENTED(hSDB) \
        (((PSDBCONTEXT)(hSDB))->hPipe != INVALID_HANDLE_VALUE)

// windows\appcompat\shims\inc\heap.h
#define maximum(a,b)    \
        ( (a) > (b) ) ? (a) : (b)

// windows\appcompat\shims\lib\rtlutils.cpp
#define IS_PATH_SEPARATOR_U(ch) (((ch) == L'\\') || ((ch) == L'/'))

// windows\appcompat\shims\lua\utils.cpp
#define IS_END_OF_COMPONENT(x) (*x == L'\\' || *x == L'\0')

// windows\appcompat\shims\verifier\registrychecks.h
#define NUM_OF_CHAR(x) sizeof(x) / 2 - 1

// windows\appcompat\tools\compatadmin\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)
#define AFX_WS_DEFAULT_VIEW             (WS_CHILD | WS_VISIBLE | WS_BORDER)

// windows\appcompat\tools\compatadmin\compatadmin.h
#define LVN_SELCHANGED  (WM_USER+1024)

// windows\appcompat\tools\compatadmin\dbviewer.h
#define DBCMD_PROPERTIES    (WM_USER+1024)

// windows\core\dxkernel\dxg\ddkcomp.h
#define BALLOC_OVERFLOW1(c,st)      (c > (MAXIMUM_POOL_ALLOC/sizeof(st)))
#define BALLOC_OVERFLOW2(c,st1,st2) (c > (MAXIMUM_POOL_ALLOC/(sizeof(st1)+sizeof(st2))))

// windows\core\ntcon\client\condll.h
#define VALID_ACCESSES (GENERIC_READ | GENERIC_WRITE)
#define VALID_SHARE_ACCESSES (FILE_SHARE_READ | FILE_SHARE_WRITE)

// windows\core\ntcon\inc\font.h
#define TM_IS_TT_FONT(x)     (((x) & TMPF_TRUETYPE) == TMPF_TRUETYPE)

// windows\core\ntgdi\client\cliumpd.h
#define VALID_UMPD(p)   ((p) != NULL && (p)->dwSignature == UMPD_SIGNATURE)

// windows\core\ntgdi\client\csxobj.hxx
#define MIN_METAFILE_XFORM  1/(1024*1024*1024*1024*8)     // 2^(-43)

// windows\core\ntgdi\client\d3d.c
#define DDS_HANDLE_OR_NULL(pdds) \
    ((pdds) != NULL ? DDS_HANDLE(pdds) : NULL)

// windows\core\ntgdi\client\local.h
#define VALID_SCR(X)    (!((X) & 0xF8000000) || (((X) & 0xF8000000) == 0xF8000000))
#define VALID_SCRPT(P)  ((VALID_SCR((P).x)) && (VALID_SCR((P).y)))
#define VALID_SCRPPT(P) ((VALID_SCR((P)->x)) && (VALID_SCR((P)->y)))
#define VALID_SCRRC(R)  ((VALID_SCR((R).left)) && (VALID_SCR((R).bottom)) && \
                         (VALID_SCR((R).right)) && (VALID_SCR((R).top)))
#define VALID_SCRPRC(R) ((VALID_SCR((R)->left)) && (VALID_SCR((R)->bottom)) && \
                         (VALID_SCR((R)->right)) && (VALID_SCR((R)->top)))

// windows\core\ntgdi\client\metadef.h
#define META_HDR_SIZE_MAX               sizeof(ENHMETAHEADER)

// windows\core\ntgdi\client\mf16.h
#define INT32FROMINT16(lp32, lp16, c)                           \
{                                                               \
    UINT    ii;                                                 \
                                                                \
    for(ii=0; ii<(c); ii++)                                     \
        ((LPINT)(lp32))[ii] = ((PSHORT)(lp16))[ii];             \
}
#define IS_META_ESCAPE_ENHANCED_METAFILE(pmfeEnhMF)			      \
	((pmfeEnhMF)->rdFunction == META_ESCAPE				      \
      && (pmfeEnhMF)->rdSize     >  sizeof(META_ESCAPE_ENHANCED_METAFILE) / 2 \
      && (pmfeEnhMF)->wEscape    == MFCOMMENT				      \
      && (pmfeEnhMF)->ident      == MFCOMMENT_IDENTIFIER		      \
      && (pmfeEnhMF)->iComment   == MFCOMMENT_ENHANCED_METAFILE)

// windows\core\ntgdi\client\mfrec.cxx
#define VALID_IMHE(imhe,cht)                                    \
        (                                                       \
            (((UINT) (imhe)) < ((UINT) (cht))) &&               \
            ((imhe) != 0)                                       \
        )

// windows\core\ntgdi\client\output.c
#define MAX_BATCH_CCHAR  ((GDI_BATCH_SIZE - sizeof(BATCHTEXTOUT)) & 0xfffffff0)

// windows\core\ntgdi\fondrv\tt\mssipotf\fs\fontmath.c
  #define mth_Max45Trick(x,y)     (x == y || x == -y)

// windows\core\ntgdi\fondrv\tt\ttfd\cvt.h
#define IS_GRAY(p) ((p)->flFontType & FO_GRAY16)

// windows\core\ntgdi\fondrv\tt\ttfd\tt.h
#define B_INT8(x)    (((x) <= MAX_INT8) && ((x) >= MIN_INT8))
#define B_INT16(x)   (((x) <= MAX_INT16) && ((x) >= MIN_INT16))
#define B_INT32(x)   (((x) <= MAX_INT32) && ((x) >= MIN_INT32))

// windows\core\ntgdi\gre\engine.h
#define BALLOC_OVERFLOW1(c,st)      (c > (MAXIMUM_POOL_ALLOC/sizeof(st)))
#define BALLOC_OVERFLOW2(c,st1,st2) (c > (MAXIMUM_POOL_ALLOC/(sizeof(st1)+sizeof(st2))))
#define IS_USER_ADDRESS(x) (MM_LOWEST_USER_ADDRESS <= (x) && (x) <= MM_HIGHEST_USER_ADDRESS)

// windows\core\ntgdi\gre\equad.hxx
#define DIV(u64,u32)                                             \
    (((u64) < ULONG_MAX) ? (((ULONG) (u64)) / (u32)) :           \
    RtlEnlargedUnsignedDivide(*(ULARGE_INTEGER*) &(u64),(u32),0))

// windows\core\ntgdi\gre\fontlink.hxx
#define IS_SYSTEM_EUDC_PRESENT()    \
 (((gappfeSysEUDC[PFE_NORMAL] != NULL) || (gappfeSysEUDC[PFE_VERTICAL] != NULL)) ? \
   TRUE : FALSE)
#define IS_FACENAME_EUDC_PRESENT(apfe) \
 (((apfe[PFE_NORMAL] != NULL) || (apfe[PFE_VERTICAL] != NULL)) ? TRUE : FALSE)

// windows\core\ntgdi\gre\fontmap.cxx
#define IS_DIGIT(x)   (((x) >= L'0') && ((x) <= L'9'))

// windows\core\ntgdi\gre\greold.h
#define IS_ANY_DBCS_CHARSET( CharSet ) ( ((CharSet) == SHIFTJIS_CHARSET)    ? TRUE :    \
                                         ((CharSet) == HANGEUL_CHARSET)     ? TRUE :    \
                                         ((CharSet) == JOHAB_CHARSET)       ? TRUE :    \
                                         ((CharSet) == CHINESEBIG5_CHARSET) ? TRUE :    \
                                         ((CharSet) == GB2312_CHARSET)      ? TRUE : FALSE )

// windows\core\ntgdi\gre\hmgrp.hxx
#define HMG_BRUSH_MAX     (sizeof(BRUSH) + 32)

// windows\core\ntgdi\gre\misceudc.cxx
#define IS_PRIVATE_EUDC_AREA(wc) \
        (((wc) >= 0xE000) && ((wc) <= 0xF8FF))

// windows\core\ntgdi\gre\region.hxx
#define VALID_SCR(X)    (!((X) & 0xF8000000) || (((X) & 0xF8000000) == 0xF8000000))
#define VALID_SCRPT(P)  ((VALID_SCR((P).x)) && (VALID_SCR((P).y)))
#define VALID_SCRPPT(P) ((VALID_SCR((P)->x)) && (VALID_SCR((P)->y)))
#define VALID_SCRRC(R)  ((VALID_SCR((R).left)) && (VALID_SCR((R).bottom)) && \
                         (VALID_SCR((R).right)) && (VALID_SCR((R).top)))
#define VALID_SCRPRC(R) ((VALID_SCR((R)->left)) && (VALID_SCR((R)->bottom)) && \
                         (VALID_SCR((R)->right)) && (VALID_SCR((R)->top)))

// windows\core\ntgdi\gre\rgnobj.cxx
#define VALIDATE(ro)    {gprgn = &ro; (ro).bValidateFramedRegion(); }

// windows\core\ntgdi\gre\rleblt.h
#define BoundsCheck(a, b, x) ( ((x) >= (a)) ? ( ((x) <= (b)) ? (x) : (b) )   \
                                            : (a) )

// windows\core\ntgdi\gre\wndobj.hxx
#define CHECKDEVLOCKIN2(pSurface)       \
    {                                   \
        PDEVOBJ po((pSurface)->hdev()); \
        CHECKCRITIN(po.hsemDevLock());     \
    }
#define CHECKDEVLOCKOUT2(pSurface)      \
    {                                   \
        PDEVOBJ po((pSurface)->hdev()); \
        CHECKCRITOUT(po.hsemDevLock());    \
    }

// windows\core\ntgdi\gre\xformobj.hxx
#define MIN_METAFILE_XFORM  1/(1024*1024*1024*1024*8)     // 2^(-43)

// windows\core\ntgdi\halftone\ht\htmapclr.c
#define ADJ_CA(a,min,max)           if (a < min) { a = min; } else  \
                                    if (a > max) { a = max; }

// windows\core\ntgdi\halftone\ht\htmapclr.h
#define RANGE_CIE_xy(x,y)   if ((x) < CIE_x_MIN) (x) = CIE_x_MIN; else  \
                            if ((x) > CIE_x_MAX) (x) = CIE_x_MAX;       \
                            if ((y) < CIE_y_MIN) (y) = CIE_y_MIN; else  \
                            if ((y) > CIE_y_MAX) (y) = CIE_y_MAX        \

// windows\core\ntgdi\halftone\htui\htuimain.c
#define ADJ_CA(a,min,max)           if (a < min) { a = min; } else  \
                                    if (a > max) { a = max; }
#define IS_BMP_AT_TOP(f)    ((f & (HT_BMP_AT_TOP | HT_BMP_ZOOM)) == \
                                            (HT_BMP_AT_TOP | HT_BMP_ZOOM))

// windows\core\ntgdi\inc\hmgshare.h
#define IS_ICM_DEVICE(x)    ((x) & DC_ICM_DEVICE)
#define IS_ICM_HOST(x)      ((x) & DC_ICM_HOST)
#define IS_ICM_INSIDEDC(x)  ((x) & (DC_ICM_DEVICE|DC_ICM_HOST))
#define IS_ICM_OUTSIDEDC(x) ((x) & DC_ICM_OUTSIDEDC)
#define IS_ICM_ON(x)        ((x) & (DC_ICM_DEVICE|DC_ICM_HOST|DC_ICM_OUTSIDEDC))
#define IS_ICM_METAFILING_ON(x)    ((x) & DC_ICM_METAFILING_ON)
#define IS_ICM_LAZY_CORRECTION(x)  ((x) & DC_ICM_LAZY_CORRECTION)
#define IS_ICM_DEVICE_CALIBRATE(x) ((x) & DC_ICM_DEVICE_CALIBRATE)
#define IS_ICM_DEVICE_REQUESTED(x)  ((x) & REQ_ICM_DEVICE)
#define IS_DEVICE_ICM_DEVMODE(x)    ((x) & CTX_ICM_DEVICE)
#define IS_ICM_PROOFING(x)          ((x) & CTX_ICM_PROOFING)

// windows\core\ntgdi\inc\mapfile.h
#define IS_ANY_DBCS_CHARSET( CharSet )                              \
                   ( ((CharSet) == SHIFTJIS_CHARSET)    ? TRUE :    \
                     ((CharSet) == HANGEUL_CHARSET)     ? TRUE :    \
                     ((CharSet) == CHINESEBIG5_CHARSET) ? TRUE :    \
                     ((CharSet) == GB2312_CHARSET)      ? TRUE : FALSE )

// windows\core\ntgdi\kdexts2\dumpers.hxx
#define SCAN_VALID_INCLUSIVE        (SCAN_VALID_AT_START | SCAN_VALID_AT_END)

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\comdlg32.h
#define IS_DOTEND(ch)   ((ch) == CHAR_DOT || (ch) == 0 || ((ch) != CHAR_STAR))

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\font.c
#define IS_DIGITW(x)   (((x) >= L'0') && ((x) <= L'9'))
#define IS_DIGITA(x)   (((x) >= '0') && ((x) <= '9'))

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\font.h
#define IS_SIMPLIFIED_CHINESE(lang)                                         \
    (((lang) == (MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED))) ||  \
     ((lang) == (MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_HONGKONG)))   ||  \
     ((lang) == (MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SINGAPORE)))  ||  \
     ((lang) == (MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_MACAU))))

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\printnew.cpp
#define Print_IsInRange(id, idFirst, idLast) \
    ((UINT)((id) - idFirst) <= (UINT)(idLast - idFirst))

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\prnsetup.h
#define IS_KEY_PRESSED(key)       ( GetKeyState(key) & 0x8000 )

// windows\core\ntgdi\test\fonttest.nt\fonttest.h
#define IS_ANY_DBCS_CHARSET( CharSet )                 \
        (((CharSet) == SHIFTJIS_CHARSET)   ? TRUE :    \
        ((CharSet) == HANGEUL_CHARSET)     ? TRUE :    \
        ((CharSet) == CHINESEBIG5_CHARSET) ? TRUE :    \
        ((CharSet) == GB2312_CHARSET)      ? TRUE : FALSE )

// windows\core\ntgdi\test\icmview\icmview.h
#define IS_NT      (0 != (IS_WIN32 && ((BOOL)(GetVersion() < 0x80000000))) )
#define IS_WIN95   (0 != ((BOOL)(!(IS_NT) && !(IS_WIN32S)) && IS_WIN32))

// windows\core\ntgdi\test\imgtest\tessel.cxx
#define RandPos()   ((rand() & (MAX_RAND_POS-1)) - MAX_RAND_POS/2)

// windows\core\ntuser\client\clmsg.c
#define END_CALLWINPROC(fInsideHook)                                    \
    } __finally {                                                       \
        if (!fCallBack) {                                               \
            if (fInsideHook) {                                          \
                _EndUserApiHook();                                      \
            }                                                           \
            RtlDeactivateActivationContextUnsafeFast(                   \
                &ActivationFrame);                                      \
        }                                                               \
    }

// windows\core\ntuser\client\clres.c
#define GETINITDC() \
    (gfSystemInitialized ? NtUserGetDC(NULL) : CreateDCW(L"DISPLAY", L"", NULL, NULL))
#define FACCEL_VALID (FALT | FCONTROL | FNOINVERT | FSHIFT | FVIRTKEY | FLASTKEY)

// windows\core\ntuser\client\crecv.c
#define PCALLDATAOPT(x) (pmsg->p ## x ? (PVOID)&(pmsg->x) : NULL)

// windows\core\ntuser\client\editml.c
#define CHECK_LINE_NUMBER(iLine, ped)                                                       \
    if (((int)iLine < 0) || ((ICH)iLine >= ped->cLines)) {                                       \
        FRE_RIPMSG0(RIP_ERROR, "Line # is < 0 or >= ped->cLines, Please check this out!");  \
    }

// windows\core\ntuser\client\msgbox.c
#define MessageBoxIndirectInit(MsgBoxParams, lpmbp)                             \
    do {                                                                        \
        if (lpmbp->cbSize != sizeof(MSGBOXPARAMS)) {                            \
            RIPMSG1(RIP_WARNING,                                                \
                    "MessageBoxIndirect: Invalid cbSize 0x%x",                  \
                    lpmbp->cbSize);                                             \
        }                                                                       \
                                                                                \
        RtlZeroMemory(&MsgBoxParams, sizeof(MSGBOXDATA));                       \
        RtlCopyMemory(&MsgBoxParams, lpmbp, sizeof(MSGBOXPARAMS));              \
    } while (FALSE);

// windows\core\ntuser\imm\immcli.h
#define ValidateHimc(himc)   (((himc) == (HIMC)NULL || !bUser32Initialized) \
        ? (PIMC)NULL : HMValidateHandle((HANDLE)himc, TYPE_INPUTCONTEXT))
#define RevalidateHimc(himc) (((himc) == (HIMC)NULL || !bUser32Initialized) \
        ? (PIMC)NULL : HMValidateHandleNoRip((HANDLE)himc, TYPE_INPUTCONTEXT))

// windows\core\ntuser\inc\user.h
    #define IS_IME_ENABLED()   (gpsi && _IS_IME_ENABLED())
    #define IS_CICERO_ENABLED() (gpsi && _IS_CICERO_ENABLED())
#define IS_DBCS_INPUT()     (IS_DBCS_ENABLED() || IS_DBCS_HKL())
#define IS_DBCS_CHARSET(charset) \
            ((charset) == SHIFTJIS_CHARSET || \
             (charset) == HANGEUL_CHARSET || \
             (charset) == CHINESEBIG5_CHARSET || \
             (charset) == GB2312_CHARSET)
#define _HMPheFromObject(p)      (&gSharedInfo.aheList[HMIndexFromHandle((((PHEAD)p)->h))])
#define MAKE_CPDHANDLE(h)       (HMIndexFromHandle(h) | CPDHANDLE_HI)
#define CSF_VALID               (CSF_ANSIPROC | CSF_WIN40COMPAT | CSF_VERSIONCLASS)
#define NEEDSPAINT(pwnd)    (pwnd->hrgnUpdate != NULL || TestWF(pwnd, WFINTERNALPAINT))
#define CheckMsgFilter(wMsg, wMsgFilterMin, wMsgFilterMax)                 \
    (   ((wMsgFilterMin) == 0 && (wMsgFilterMax) == 0xFFFFFFFF)            \
     || (  ((wMsgFilterMin) > (wMsgFilterMax))                             \
         ? (((wMsg) <  (wMsgFilterMax)) || ((wMsg) >  (wMsgFilterMin)))    \
         : (((wMsg) >= (wMsgFilterMin)) && ((wMsg) <= (wMsgFilterMax)))))
#define InMsgRange(msg, start, end) (((msg) >= (start)) && ((msg) <= (end)))

// windows\core\ntuser\inc\wow.h
#define EndAliveValidateHandleMacro() \
            } else {                                \
                RIPMSG2(RIP_WARNING, "ValidateAliveHandle: Object phe %#p is destroyed. Handle: %#p", \
                    phe, h);   \
            }   \

// windows\core\ntuser\kernel\caption.c
#define NOSIZE  (NOMIN | NOMAX)

// windows\core\ntuser\kernel\fekbd.c
#define IS_KANA_AWARE()   (fNlsKbdConfiguration & GEN_KANA_AWARE)
#define IS_SEND_VK_END()  (fNlsKbdConfiguration & GEN_VK_END)
#define IS_SEND_VK_HOME() (fNlsKbdConfiguration & GEN_VK_HOME)

// windows\core\ntuser\kernel\hooks.c
#define IS_CHAR_MSG(msg)    ((msg) & 0x02)

// windows\core\ntuser\kernel\ntstubs.c
#define ISXPFNPROCINRANGE(range)                        \
   ((xpfnProc >= SFI_BEGINTRANSLATE ## range) &&        \
    (xpfnProc < SFI_ENDTRANSLATE ## range))
#define LIMITVALUE(value, limit, szText) \
    if ((UINT)(value) > (UINT)(limit)) {     \
        RIPERR3(ERROR_INVALID_PARAMETER, RIP_WARNING, "Invalid parameter, %d > %d in %s", \
             value, limit, szText); \
        MSGERROR(0);     \
    }
#define ValidateHMENUMODIFY(p,h) \
    if ((p = ValidateHmenu(h)) == NULL)  {          \
        MSGERROR(0);                                \
    } else if (TestMF(p, MFDESKTOP)) { \
        RIPMSG1(RIP_WARNING, "ValidateHMENUMODIFY: Attempt to modify desktop menu:%#p", p); \
        MSGERROR(0);                                \
    }
#define ValidateHMENUMODIFYCHECKLOCK(p,h) \
    if ((p = ValidateHmenu(h)) == NULL)  {          \
        MSGERROR(0);                                \
    } else if (TestMF(p, MFDESKTOP)) { \
        RIPMSG1(RIP_WARNING, "ValidateHMENUMODIFYCHECKLOCK: Attempt to modify desktop menu:%#p", p); \
        MSGERROR(0);                                \
    } else if (TestMF(p, MFREADONLY)) { \
        RIPMSG1(RIP_WARNING, "ValidateHMENUMODIFYCHECKLOCK: Attempt to modify RO menu: %#p", p); \
        MSGERROR(0);                                \
    }

// windows\core\ntuser\kernel\queue.c
    #define MAXMODULENAMELEN    (sizeof(szKey) - MODULESUFFIXSIZE)

// windows\core\ntuser\kernel\sendmsg.c
#define FORCE_CAPTURE(Addr) (!IS_SYSTEM_ADDRESS(Addr) || (ptiSender == NULL))

// windows\core\ntuser\kernel\ssend.c
#define CALC_SIZE_OUT(cb, pstr) \
    cb = (pstr)->MaximumLength + sizeof(WCHAR); \
    if ((pstr)->bAnsi && !fAnsiReceiver)        \
        cb *= sizeof(WCHAR);

// windows\core\ntuser\kernel\userk.h
#define ProbeAndReadMenuItem(Address)                             \
    (((Address) >= (MENUITEMINFO * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile MENUITEMINFO * const)MM_USER_PROBE_ADDRESS) : (*(volatile MENUITEMINFO *)(Address)))
#define TestRawInputModeNoCheck(pti, mode) \
    ((pti)->ppi->pHidTable->f##mode)
#define xxxRedrawScreen() \
        xxxInternalInvalidate(PtiCurrent()->rpdesk->pDeskInfo->spwnd, \
        HRGN_FULL, RDW_INVALIDATE | RDW_ERASE | RDW_FRAME | RDW_ALLCHILDREN)
#define POBJECT_NAME(pobj) (OBJECT_HEADER_TO_NAME_INFO(OBJECT_TO_OBJECT_HEADER(pobj)) ? \
    &(OBJECT_HEADER_TO_NAME_INFO(OBJECT_TO_OBJECT_HEADER(pobj))->Name) : NULL)
#define UPIsBOOLRange(uSetting) \
    ((uSetting) >= SPI_STARTBOOLRANGE && (uSetting) < SPI_MAXBOOLRANGE)
#define IsMultimon()  ((gpDispInfo != NULL)  && (gpDispInfo->cMonitors > 1))
#define GETTOPMOSTINSERTAFTER(pwnd) \
    (gHardErrorHandler.pti == NULL ? NULL : GetTopMostInsertAfter(pwnd))
#define FDoTray()   (SYSMET(ARRANGE) & ARW_HIDE)
#define FHas31TrayStyles(pwnd)    (TestWF(pwnd, WFFULLSCREEN) || \
                                  (TestWF(pwnd, WFSYSMENU | WFMINBOX) && \
                                  (TestWF(pwnd, WFCAPTION) || TestWF(pwnd, WFMINIMIZED))))
#define IsWinEventNotifyDeferredOK() (!IsWinEventNotifyDeferred() || ISATOMICCHECK())
#define POLICY_VALID    (POLICY_ALL | POLICY_ONLY | POLICY_REMOTE)

// windows\core\ntuser\kernel\validate.c
#define ClientSharedInfo()  (&gSharedInfo)

// windows\core\ntuser\rtl\input.c
#define CheckMsgRange(wMsgRangeMin, wMsgRangeMax, wMsgFilterMin, wMsgFilterMax) \
    (  ((wMsgFilterMin) > (wMsgFilterMax))      \
     ? (  ((wMsgRangeMax) >  (wMsgFilterMax))   \
        &&((wMsgRangeMin) <  (wMsgFilterMin)))  \
     : (  ((wMsgRangeMax) >= (wMsgFilterMin))   \
        &&((wMsgRangeMin) <= (wMsgFilterMax)))  \
    )

// windows\core\ntuser\rtl\wow.c
    #define GET_CURRENT_CLIENTINFO()                            \
        {                                                       \
            PW32THREAD pW32Thread;                              \
                                                                \
            pW32Thread = W32GetCurrentThread();                 \
                                                                \
            if (pW32Thread) {                                   \
                pci = ((PTHREADINFO)pW32Thread)->pClientInfo;   \
            } else {                                            \
                pci = NULL;                                     \
            }                                                   \
        }

// windows\core\ntuser\tools\perf\perfutil.c
#define EvalThisChar(c,d) ( \
     (c == d) ? DELIMITER : \
     (c == 0) ? ENDOFSTRING : \
     (c < (WCHAR)'0') ? INVALID : \
     (c > (WCHAR)'9') ? INVALID : \
     DIGIT)

// windows\core\rtl\heap.c
    #define EnterHeapCrit()                             \
        KeEnterCriticalRegion();                        \
        ExAcquireFastMutexUnsafe(pheap->pFastMutex);

// windows\core\w32inc\w32err.h
#define VALIDATIONOBSOLETE(o, u) \
    RIPMSG1(RIP_WARNING, "%s: " #o " obsolete; use " #u, szFnName)
#define ZERO(t)     (ValidateZero(), (*(t *)(void *)&gZero))
#define PZERO(t)    (ValidateZero(), ((t *)(void *)&gZero))

// windows\core\wow64win\cgen\cgenhdr.h
#define PCALLDATAOPT(x) (pmsg->p ## x ? (PVOID)&(pmsg->x) : NULL)

// windows\core\wow64win\whwin32\whwin32.tpl
#define USER_PROFILE_SIMPLE(apinum)              \
if (apinum < ulMaxSimpleCall) {                  \
   SimpleCallProfileElements[apinum].HitCount++; \
}                                                \

// windows\feime\kor\ime2k\cicerolib\inc\ccstock.h
#define IS_DC_RTL_MIRRORED(hdc)         (g_bMirroredOS && Mirror_IsDCMirroredRTL(hdc))
#define IS_PROCESS_RTL_MIRRORED()       (g_bMirroredOS && Mirror_IsProcessRTL())

// windows\feime\kor\ime2k\fecommon\imembx\recog.h
#define ALC_SYS_MINIMUM		(ALC_ALPHANUMERIC | ALC_PUNC | ALC_WHITE)
#define ALC_SYS_DEFAULT		(ALC_SYS_MINIMUM | ALC_COMMON_SYMBOLS)

// windows\feime\kor\ime2k\fecommon\lib\exbtn\exbtn.h
#define EXBM_GETCHECK			(WM_USER + 100)
#define EXBM_SETCHECK			(WM_USER + 101)

// windows\netdde\src\netdde\netcons.h
#define MAXDEVENTRIES	(sizeof (int)*8)    /* Max number of device entries   */

// windows\oleacc\oleacc\accutil.h
#define ValidateRange(lValue, lMin, lMax)   (((lValue) > (lMin)) && ((lValue) < (lMax)))

// windows\oleacc\oleacc\oleacc_p.h
#define SIZEOF_MENUITEMINFO sizeof( MENUITEMINFO )

// windows\richedit\inci\chnutils.h
#define  FlushSublineChunkContext(plschnkcontext)		\
					(plschnkcontext)->FLocationValid = fFalse;\
					(plschnkcontext)->FChunkValid = fFalse;\
					(plschnkcontext)->FGroupChunk = fFalse;\
					(plschnkcontext)->FBorderInside = fFalse;\
					(plschnkcontext)->grpfTnti = 0;\
					(plschnkcontext)->fNTIAppliedToLastChunk = fFalse;\
					(plschnkcontext)->locchnkCurrent.clschnk = 0;\
#define InvalidateChunk(plschnkcontext) \
	(plschnkcontext)->FChunkValid = fFalse;
#define InvalidateChunkLocation(plschnkcontext) \
	(plschnkcontext)->FLocationValid = fFalse;
#define SetUrColumnMaxForChunks(plschnkcontext, Ur)   \
	(plschnkcontext)->locchnkCurrent.lsfgi.urColumnMax = Ur;
#define GetUrColumnMaxForChunks(plschnkcontext)   \
		(plschnkcontext)->locchnkCurrent.lsfgi.urColumnMax
#define 		FlushNominalToIdealState(plschnkcontext)  \
				(plschnkcontext)->grpfTnti = 0;

// windows\richedit\inci\dninfo.h
#define FIsOutOfBoundary(plsdn, cpLim) \
		(((plsdn) == NULL) || \
		 ((plsdn)->cpLimOriginal > (cpLim)) || \
		 (FIsDnodeOpenBorder(plsdn) && ((plsdn)->cpLimOriginal == (cpLim))) \
		)
#define FDnodeAfterCpFirst(plsdn, cpF) \
		( \
		((plsdn) != NULL) \
		&&	( \
		    ((plsdn)->cpFirst > (cpF)) \
		    ||	( \
				((plsdn)->cpFirst == (cpF)) \
				&& (FIsDnodeReal(plsdn) || FIsDnodeOpenBorder(plsdn)) \
				) \
			) \
		)

// windows\richedit\inci\lsidefs.h
#define FHasTag(p,t)	((p) != NULL && (p)->tag == (t))

// windows\richedit\inci\lsline.h
#define FLineValid(plsline, plsc)	((FIsLSLINE(plsline)) && (plsline->lssubl.plsc == plsc))

// windows\richedit\inci\ntiman.h
#define			FNominalToIdealBecauseOfParagraphProperties(grpf, lskjust) \
				 ((grpf) & fFmiPunctStartLine) || \
				 ((grpf) & fFmiHangingPunct) || \
				 ((lskjust) == lskjSnapGrid)

// windows\richedit\inci\setfmtst.h
#define SetCurrentDnodeSubl(plssubl, plsdn)	((plssubl)->plsdnLast = (plsdn)); \
											if ((plsdn) == NULL) ((plssubl)->plsdnFirst = NULL);
#define SetBreakthroughLine(plsc, urRightMargin)    \
				(plsc)->plslineCur->lslinfo.fTabInMarginExLine = fTrue; \
				(plsc)->lsadjustcontext.urRightMarginJustify = \
				(plsc)->urRightMarginBreak == 0 ?  \
						(plsc)->lsadjustcontext.urRightMarginJustify + (urRightMargin) \
						: \
							((plsc)->lsadjustcontext.urRightMarginJustify / \
									(plsc)->urRightMarginBreak )\
							* (urRightMargin); \
				(plsc)->urRightMarginBreak = (urRightMargin); \
				(plsc)->plslineCur->lssubl.urColumnMax = (urRightMargin); \
#define IncreaseFormatDepth(plsc)  ((plsc)->lslistcontext.nDepthFormatLineCurrent++, \
									(plsc)->plslineCur->lslinfo.nDepthFormatLineMax = \
										Max((plsc)->lslistcontext.nDepthFormatLineCurrent, \
											(plsc)->plslineCur->lslinfo.nDepthFormatLineMax))

// windows\richedit\lssrc\chnutils.c
#define FIsGrchnkExtValid(plschunkcontext, pgrchunkext)  \
		(((plschunkcontext) == (pgrchunkext)->plschunkcontext)  &&\
		 ((pgrchunkext)->lsgrchnk.plschnk == (plschunkcontext)->locchnkCurrent.plschnk) &&\
		 ((pgrchunkext)->lsgrchnk.pcont == (plschunkcontext)->pcont) &&\
		 ((pgrchunkext)->pplsdnNonText == (plschunkcontext)->pplsdnNonText) &&\
		 ((pgrchunkext)->pfNonTextExpandAfter == (plschunkcontext)->pfNonTextExpandAfter) \
        )

// windows\richedit\lssrc\dispmisc.c
#define FIsSubmittingDnode(pdn) 	(FIsDnodeReal(pdn) && (pdn)->u.real.pinfosubl != NULL && 	\
									(pdn)->u.real.pinfosubl->fUseForDisplay)
#define FIsAcceptingDnode(pdn) 	(FIsDnodeReal(pdn) && (pdn)->u.real.pinfosubl != NULL && 	\
									((pdn)->u.real.pinfosubl->rgpsubl)[0]->fAcceptedForDisplay)

// windows\richedit\lssrc\dnutils.c
#define FIsOutOfLine(plsc, plsdn)  \
		(((plsdn) == NULL) ||   \
		  (((plsc)->plslineCur->lslinfo.cpLim != 0) && ((plsc)->plslineCur->lslinfo.cpLim <= (plsdn)->cpFirst)))

// windows\richedit\lssrc\lscrline.c
#define FAdvancedTypographyEnabled(plsc, cbreakrec)  \
						(FNominalToIdealBecauseOfParagraphProperties(plsc->grpfManager, \
								plsc->lsadjustcontext.lskj) || \
						 !FBreakJustSimple((plsc)->lsadjustcontext.lsbrj) ||\
						 cbreakrec != 0 \
						 )

// windows\richedit\lssrc\lsfetch.c
#define SetHeightToMax(plslinfo,pobjdim) \
{\
	if ((pobjdim)->heightsRef.dvMultiLineHeight != dvHeightIgnore)\
		{\
		SetToMax((plslinfo)->dvrAscent, (pobjdim)->heightsRef.dvAscent);\
		SetToMax((plslinfo)->dvpAscent, (pobjdim)->heightsPres.dvAscent);\
		SetToMax((plslinfo)->dvrDescent, (pobjdim)->heightsRef.dvDescent);\
		SetToMax((plslinfo)->dvpDescent, (pobjdim)->heightsPres.dvDescent);\
		SetToMax((plslinfo)->dvpMultiLineHeight, (pobjdim)->heightsPres.dvMultiLineHeight);\
		SetToMax((plslinfo)->dvrMultiLineHeight, (pobjdim)->heightsRef.dvMultiLineHeight);\
		}\
}
#define FRunIsNotSimple(plschp, fHidden)   \
									(((plschp)->idObj != idObjTextChp) ||  \
									 ((fHidden)) ||  \
									  ((plschp)->fBorder) || \
									  FApplyNominalToIdeal(plschp))
#define FillRealPart(plsdnNew, plsfrunOfDnode)\
		/* we don't initialize  here variables that will be set in FiniSimpleRegular  */ \
		(plsdnNew)->u.real.pinfosubl = NULL;\
		/* next two assignement we do to use DestroyDnodeList in the case of error */ \
		(plsdnNew)->u.real.plsrun = (plsfrunOfDnode)->plsrun;\
		(plsdnNew)->u.real.pdobj = NULL;\
		/* we put amount of characters to dcp to check it in LsdnFinishSimpleByOneChar */ \
		(plsdnNew)->dcp = (plsfrunOfDnode)->cwchRun; \
		(plsdnNew)->cpLimOriginal = (plsdnNew)->cpFirst + (plsdnNew)->dcp;
#define FNeedToCutPossibleContextViolation(plsc, plsdn) \
	(FIsDnodeReal(plsdn) && \
	 ((plsdn)->u.real.lschp.dcpMaxContext > 1) && \
	 (IdObjFromDnode(plsdn) == IobjTextFromLsc(&((plsc)->lsiobjcontext)))  \
    )

// windows\richedit\lssrc\lstxtscl.c
#define SetMagicConstant() (lstflow & fUVertical) ? \
	(MagicConstant = pilsobj->MagicConstantY, durRightMax = pilsobj->durRightMaxY) : \
	(MagicConstant = pilsobj->MagicConstantX, durRightMax = pilsobj->durRightMaxX)

// windows\richedit\lssrc\ntiman.c
#define     	FNominalToIdealNeeded(plschnkcontext, grpf, lskjust)    \
				((plschnkcontext)->grpfTnti != 0) || \
				 FNominalToIdealBecauseOfParagraphProperties(grpf, lskjust)

// windows\richedit\re30\_edit.h
#define fNEEDCSSEQCHECK     (fTHAI | fDEVANAGARI | fTAMIL)

// windows\winstate\cobra\engine\ism\ismp.h
#define JOURNAL_USER_DATA_SIZE      (4 * MAX_TCHAR_PATH + sizeof (BOOL))

// windows\winstate\cobra\inc\allutils.h
#define ISMEMPHIS()         (ISWIN9X() && g_OsInfo.dwMajorVersion==4 && g_OsInfo.dwMinorVersion==10)

// windows\winstate\cobra\modules\guitrans\homenetp.h
#define MAX_SOCKADDR                (max(sizeof(SOCKADDR_IN),max(sizeof(SOCKADDR_IPX),sizeof(SOCKADDR_NB))))

// windows\winstate\cobra\modules\script\v1p.h
#define PFF_NO_LEAF_AT_ALL                  (PFF_NO_LEAF_PATTERN|PFF_PATTERN_IS_DIR)

// windows\winstate\cobra\tools\utiltool\homenet\main.c
#define MAX_SOCKADDR                (max(sizeof(SOCKADDR_IN),max(sizeof(SOCKADDR_IPX),sizeof(SOCKADDR_NB))))

// windows\winstate\cobra\utils\inc\fileenum.h
#define DRIVEENUM_ALLVALID  (DRIVEENUM_REMOVABLE|DRIVEENUM_FIXED|DRIVEENUM_REMOTE|DRIVEENUM_CDROM|DRIVEENUM_RAMDISK)
```

