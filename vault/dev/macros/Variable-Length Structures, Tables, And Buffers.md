# Variable-Length Structures, Tables, And Buffers

[Macros index](<macros.md>)

## Curated Candidates

```c
// ds\ds\src\util\base64\base64.c
#define NA (255)
#define DECODE(x) (((int)(x) < sizeof(rgbDecodeTable)) ? rgbDecodeTable[x] : NA)

// shell\browseui\legacy\augm.cpp
#define DPA_DESTROY( hdpa, pfn )        { if( NULL != hdpa ) \
                                            { DPA_DestroyCallback( hdpa, pfn, NULL ) ; \
                                              hdpa = NULL ; }}

// shell\comctl32\v6\da.c
#define DSA_PITEM(pdsa, index)    ((void*)(((BYTE*)(pdsa)->aItem) + ((index) * (pdsa)->cbItem)))

// shell\comdlg32\comdlg32.h
#define IS_NEW_OFN(pOFN)  (pOFN->lStructSize >= sizeof(OPENFILENAME))

// ds\netapi\dosprint\dosprtw.c
#define NULL_STR_CONV_SIZE(psz) ( (psz) ? STR_CONV_SIZE(psz) : sizeof(WCHAR) )

// shell\comdlg32\prnsetup.h
#define SetField(_pdm, _fld, _val)     \
        ((_pdm)->dmSpecVersion >= 0x0400 ? (((_pdm)->_fld = (_val)), TRUE) : FALSE)

// windows\oleacc\oleacc\oleacc_p.h
#define SIZEOF_STRUCT(structname, member)  (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))

// enduser\windows.com\iuengine\wubios\inc\configmg.h
#define	SIZEOF_MEM(x)		(sizeof(MEM_DES)+(x)*sizeof(MEM_RANGE))

// printscan\faxsrv\src\inc\prtcovpg.h
#define  NUM_INSERTION_TAGS   ((sizeof(COVERPAGEFIELDS) - sizeof(DWORD)) / sizeof(LPTSTR))

// termsrv\remdsk\rds\as\h\host.h
#define HET_WINDOW_COUNT        ((0x1000 - sizeof(BASEDLIST)) / sizeof(HET_WINDOW_STRUCT))

// drivers\wdm\usb\hcd\usbport\usbport.h
#define USBPORT_ADDRESS_AND_SIZE_TO_SPAN_PAGES_4K(Va,Size) \
   (((((Size) - 1) >> USB_PAGE_SHIFT) + \
   (((((ULONG)(Size-1)&(USB_PAGE_SIZE-1)) + (PtrToUlong(Va) & (USB_PAGE_SIZE -1)))) >> USB_PAGE_SHIFT)) + 1L)

// inetcore\wininet\urlcache\hashutil.cxx
#define BYTES_PER_TABLE (sizeof(HASH_FILEMAP_ENTRY) \
    + SLOT_COUNT * ITEMS_PER_BUCKET * sizeof(HASH_ITEM))

// multimedia\media\winmm\playwav.c
#define BLOCKBYTES (sizeof(SOUNDFILE) + (wNameLen * sizeof(WCHAR)))

// multimedia\danim\src\filters\strmbase\amvideo.h
#define TRUECOLOR(pbmi)  ((TRUECOLORINFO *)(((LPBYTE)&((pbmi)->bmiHeader)) \
					+ (pbmi)->bmiHeader.biSize))

#define COLORS(pbmi)	((RGBQUAD *)(((LPBYTE)&((pbmi)->bmiHeader)) 	\
					+ (pbmi)->bmiHeader.biSize))

#define BITMASKS(pbmi)	((DWORD *)(((LPBYTE)&((pbmi)->bmiHeader)) 	\
					+ (pbmi)->bmiHeader.biSize))

// base\hals\bushnd.c
#define ARRAY_SIZE_IN_BYTES(a)  ( (a + 1) * sizeof(PARRAY) +        \
                                  FIELD_OFFSET(ARRAY, Element) )

// base\ntdll\propset.h
#define CB_PROPERTYSECTIONHEADER FIELD_OFFSET(PROPERTYSECTIONHEADER, rgprop)

#define CB_SERIALIZEDPROPERTYVALUE  FIELD_OFFSET(SERIALIZEDPROPERTYVALUE, rgb)

#define CB_ENTRY		FIELD_OFFSET(ENTRY, sz)

#define CB_DICTIONARY		FIELD_OFFSET(DICTIONARY, rgEntry)

// base\fs\fltsamples\filespy\filter\filespy.c
#define VALID_FAST_IO_DISPATCH_HANDLER(FastIoDispatchPtr, FieldName) \
    (((FastIoDispatchPtr) != NULL) && \
     (((FastIoDispatchPtr)->SizeOfFastIoDispatch) >= \
      (FIELD_OFFSET(FAST_IO_DISPATCH, FieldName) + sizeof(VOID *))) && \
     ((FastIoDispatchPtr)->FieldName != NULL))

// base\fs\ntfs\restrsup.c
#define NtfsLogRecordHeaderLength( IC, LR )                     \
    (sizeof( NTFS_LOG_RECORD_HEADER )                           \
     + (((PNTFS_LOG_RECORD_HEADER) (LR))->LcnsToFollow > 1      \
        ? (((PNTFS_LOG_RECORD_HEADER) (LR))->LcnsToFollow - 1)  \
          * sizeof( LCN )                                       \
        : 0 ))
```

## Backlog

```c
// admin\activec\conui\strtable.h
#define DECLARE_DIAGNOSITICS()  \
public: void Dump() const;
#define DECLARE_DIAGNOSITICS()  \
public: void Dump() const {}

// admin\activec\designer\vb98ctls\include\asp.h
#define IResponse_get_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> get_Buffer(This,fIsBuffering)
#define IResponse_put_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> put_Buffer(This,fIsBuffering)
#define IResponse_AppendToLog(This,bstrLogEntry)	\
    (This)->lpVtbl -> AppendToLog(This,bstrLogEntry)
#define IResponse_BinaryWrite(This,rgbBuffer)	\
    (This)->lpVtbl -> BinaryWrite(This,rgbBuffer)

// admin\activec\designer\vb98ctls\include\ocx96.h
#define IViewObjectEx_Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)	\
    (This)->lpVtbl -> Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)

// admin\darwin\tools\inc\fusion.h
#define IAssemblyName_SetProperty(This,PropertyId,pvProperty,cbProperty)	\
    (This)->lpVtbl -> SetProperty(This,PropertyId,pvProperty,cbProperty)
#define IAssemblyName_GetProperty(This,PropertyId,pvProperty,pcbProperty)	\
    (This)->lpVtbl -> GetProperty(This,PropertyId,pvProperty,pcbProperty)
#define IAssemblyName_GetName(This,lpcwBuffer,pwzName)	\
    (This)->lpVtbl -> GetName(This,lpcwBuffer,pwzName)
#define IApplicationContext_Set(This,szName,pvValue,cbValue,dwFlags)	\
    (This)->lpVtbl -> Set(This,szName,pvValue,cbValue,dwFlags)
#define IApplicationContext_Get(This,szName,pvValue,pcbValue,dwFlags)	\
    (This)->lpVtbl -> Get(This,szName,pvValue,pcbValue,dwFlags)
#define IAssembly_GetAssemblyPath(This,pStr,lpcwBuffer)	\
    (This)->lpVtbl -> GetAssemblyPath(This,pStr,lpcwBuffer)
#define IFusionBindLog_GetBindLog(This,dwDetailLevel,pszDebugLog,pcbDebugLog)	\
    (This)->lpVtbl -> GetBindLog(This,dwDetailLevel,pszDebugLog,pcbDebugLog)
#define IAssemblyModuleImport_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define IAssemblyModuleImport_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define IAssemblyModuleImport_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define IAssemblyModuleImport_GetHashValue(This,pbHashValue,pcbHashValue)	\
    (This)->lpVtbl -> GetHashValue(This,pbHashValue,pcbHashValue)

// admin\hmonitor\connmgr\source\connmgrex.h
#define IWbemObjectAccess_ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData)	\
    (This)->lpVtbl -> ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData)

// admin\pchealth\core\include\mpc_config.h
#define DECLARE_CONFIG_MAP(x) \
    typedef x _ConfigMapClass; \
    static const MPC::Config::DefinitionOfTag       _cfg_tag;\
    static const MPC::Config::DefinitionOfTag*      _cfg_table_tags[];\
    static const MPC::Config::DefinitionOfAttribute _cfg_table_attributes[];

// admin\pchealth\helpctr\rc\bdychannel\im_inc\mdisp.h
#define IMsgrService_put_ProfileField(This,mpflField,vFieldValue)	\
    (This)->lpVtbl -> put_ProfileField(This,mpflField,vFieldValue)
#define IMsgrService_get_ProfileField(This,mpflField,pvFieldValue)	\
    (This)->lpVtbl -> get_ProfileField(This,mpflField,pvFieldValue)
#define IMsgrSP_put_ProfileField(This,mpflField,vFieldValue)	\
    (This)->lpVtbl -> put_ProfileField(This,mpflField,vFieldValue)
#define IMsgrSP_get_ProfileField(This,mpflField,pvFieldValue)	\
    (This)->lpVtbl -> get_ProfileField(This,mpflField,pvFieldValue)
#define IMsgrSP2_put_ProfileField(This,mpflField,vFieldValue)	\
    (This)->lpVtbl -> put_ProfileField(This,mpflField,vFieldValue)
#define IMsgrSP2_get_ProfileField(This,mpflField,pvFieldValue)	\
    (This)->lpVtbl -> get_ProfileField(This,mpflField,pvFieldValue)

// admin\pchealth\pchmars\inc\xmlparser.h
#define IXMLNodeSource_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLNodeSource_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLParser_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_PushData(This,pData,ulChars,fLastBuffer)	\
    (This)->lpVtbl -> PushData(This,pData,ulChars,fLastBuffer)

// admin\snapin\corecopy\ndmgr.h
#define IResultData_SetDescBarText(This,DescText)	\
    (This)->lpVtbl -> SetDescBarText(This,DescText)
#define IResultDataPrivate_SetDescBarText(This,DescText)	\
    (This)->lpVtbl -> SetDescBarText(This,DescText)

// admin\snapin\dnsmgr\record.h
#define BEGIN_CLASS_DNS_RECORD(recClass) \
class recClass : public CDNSRecord \
{ \
public: \
	recClass(); \
public: \
	virtual	WORD GetRPCDataLength();\
	virtual void ReadRPCData(DNS_RPC_RECORD* pDnsRecord); \
	virtual void ReadDnsQueryData(DNS_RECORD* pDnsQueryRecord);\
protected: \
	virtual void WriteRPCData(BYTE* pMem, DNS_RPC_RECORD** ppDnsRecord); \
	virtual void UpdateDisplayData(CString& szDisplayData); \
public:

// admin\snapin\dsadmin\profile.h
	#define IMPLEMENT_PROFILING_CONDITIONAL( enabler ) \
		__MAX_MINIPROFILER_IMPLEMENTATION \
		CMaxProfilingObject::MPOProfiler CMaxProfilingObject::s_oProfiler( enabler ); \
		CMaxProfilingObject::__CBiasApproximation CMaxProfilingObject::s_oBiasApproximation;

// admin\wmi\wbem\adapters\wmireverseperformancemonitor\include\wmi_helper_regtable.h
#define BEGIN_CLASS_REGISTRY_TABLE(ClassName) \
    static HRESULT STDAPICALLTYPE __UpdateRegistry(BOOL bInstalling) \
    {\
        BEGIN_REGISTRY_TABLE(entries)
#define END_CLASS_REGISTRY_TABLE() \
        END_REGISTRY_TABLE()\
        return RegistryTableUpdateRegistry(entries, bInstalling);\
    }
#define BEGIN_CLASS_REGISTRY_TABLE_SZ(ClassName) \
    static HRESULT STDAPICALLTYPE __UpdateRegistrySZ(BOOL bInstalling) \
    {\
        BEGIN_REGISTRY_TABLE_SZ(entries)
#define END_CLASS_REGISTRY_TABLE_SZ() \
        END_REGISTRY_TABLE_SZ()\
        return RegistryTableUpdateRegistrySZ(entries, bInstalling);\
    }

// admin\wmi\wbem\providers\dmi\source\dual.h
#define IDualGroup_put_IsTable(This,GroupId)	\
    (This)->lpVtbl -> put_IsTable(This,GroupId)
#define IDualGroup_get_IsTable(This,retval)	\
    (This)->lpVtbl -> get_IsTable(This,retval)

// admin\wmi\wbem\sdk\activex\controls\logindlg\globalinterfacetable.h
#define IGlobalInterfaceTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IGlobalInterfaceTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IGlobalInterfaceTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IGlobalInterfaceTable_RegisterInterfaceInGlobal(This,pUnk,riid,pdwCookie)	\
    (This)->lpVtbl -> RegisterInterfaceInGlobal(This,pUnk,riid,pdwCookie)
#define IGlobalInterfaceTable_RevokeInterfaceFromGlobal(This,dwCookie)	\
    (This)->lpVtbl -> RevokeInterfaceFromGlobal(This,dwCookie)
#define IGlobalInterfaceTable_GetInterfaceFromGlobal(This,dwCookie,riid,ppv)	\
    (This)->lpVtbl -> GetInterfaceFromGlobal(This,dwCookie,riid,ppv)

// admin\wmi\wbem\sdk\activex\controls\nsentry\machineeditinput.cpp
#define COLOR_DIRTY_CELL_TEXT  RGB(0, 0, 255) // Dirty text color = BLUE
#define COLOR_CLEAN_CELL_TEXT RGB(0, 0, 0)    // Clean text color = BLACK

// admin\wmi\wbem\sdk\activex\controls\nsentry\machineeditinput.h
#define COLOR_DIRTY_CELL_TEXT  RGB(0, 0, 255) // Dirty text color = BLUE
#define COLOR_CLEAN_CELL_TEXT RGB(0, 0, 0)    // Clean text color = BLACK

// admin\wmi\wbem\sdk\activex\controls\nsentry\nsentryctl.h
#define COLOR_DIRTY_CELL_TEXT  RGB(0, 0, 255) // Dirty text color = BLUE
#define COLOR_CLEAN_CELL_TEXT RGB(0, 0, 0)    // Clean text color = BLACK

// admin\wmi\wbem\sdk\activex\controls\singleview\quals.cpp
#define FIELD_FLAGS		(FIELD_IFLAG | FIELD_CFLAG | FIELD_OFLAG | FIELD_AFLAG)

// admin\wmi\wbem\sdk\locstudioparser\inc\mit\mitutil\uiopthelp.h
#define LOC_UI_OPTIONS_BOOL_ENTRY(name, def, et, id, idHelp, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, def, et}
#define LOC_UI_OPTIONS_DWORD_ENTRY(name, def, et, id, idHelp, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault},def, et}
#define LOC_UI_OPTIONS_STR_ENTRY(name, def, et, id, idHelp, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, def, et}
#define LOC_UI_OPTIONS_FILENAME_ENTRY(name, def, id, idHelp, idExt, pfnval, st) \
	{ {name, id, idHelp, pfnval, st, CLocUIOptionDef::ctDefault,  CLocUIOptionDef::ctDefault}, idExt, def}

// admin\wmi\wbem\shell\atlui\inc\snapins.inc\mmc.h
#define IResultData_SetDescBarText(This,DescText)	\
    (This)->lpVtbl -> SetDescBarText(This,DescText)
#define IStringTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IStringTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IStringTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IStringTable_AddString(This,pszAdd,pStringID)	\
    (This)->lpVtbl -> AddString(This,pszAdd,pStringID)
#define IStringTable_GetString(This,StringID,cchBuffer,lpBuffer,pcchOut)	\
    (This)->lpVtbl -> GetString(This,StringID,cchBuffer,lpBuffer,pcchOut)
#define IStringTable_GetStringLength(This,StringID,pcchString)	\
    (This)->lpVtbl -> GetStringLength(This,StringID,pcchString)
#define IStringTable_DeleteString(This,StringID)	\
    (This)->lpVtbl -> DeleteString(This,StringID)
#define IStringTable_DeleteAllStrings(This)	\
    (This)->lpVtbl -> DeleteAllStrings(This)
#define IStringTable_FindString(This,pszFind,pStringID)	\
    (This)->lpVtbl -> FindString(This,pszFind,pStringID)
#define IStringTable_Enumerate(This,ppEnum)	\
    (This)->lpVtbl -> Enumerate(This,ppEnum)

// admin\wmi\wbem\winmgmt\esscomp\stdcons\wbemcons\cdonts.h
#define AddressEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define AddressEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define AddressEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define AddressEntry_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define AddressEntry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define AddressEntry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define AddressEntry_get_Application(This,varApplication)	\
    (This)->lpVtbl -> get_Application(This,varApplication)
#define AddressEntry_get_Parent(This,varParent)	\
    (This)->lpVtbl -> get_Parent(This,varParent)
#define AddressEntry_get_Session(This,varSession)	\
    (This)->lpVtbl -> get_Session(This,varSession)
#define AddressEntry_get_Class(This,varClass)	\
    (This)->lpVtbl -> get_Class(This,varClass)
#define AddressEntry_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)
#define AddressEntry_get_Address(This,varAddress)	\
    (This)->lpVtbl -> get_Address(This,varAddress)
#define AddressEntry_get_Type(This,varType)	\
    (This)->lpVtbl -> get_Type(This,varType)

// admin\wmi\wbem\xmltransport\soap\server\msxml3\inc\msxml2.h
#define IXMLDOMDocument_createProcessingInstruction(This,target,data,pi)	\
    (This)->lpVtbl -> createProcessingInstruction(This,target,data,pi)
#define IXMLDOMDocument2_createProcessingInstruction(This,target,data,pi)	\
    (This)->lpVtbl -> createProcessingInstruction(This,target,data,pi)
#define IXMLDOMProcessingInstruction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IXMLDOMProcessingInstruction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IXMLDOMProcessingInstruction_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IXMLDOMProcessingInstruction_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IXMLDOMProcessingInstruction_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IXMLDOMProcessingInstruction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IXMLDOMProcessingInstruction_get_nodeName(This,name)	\
    (This)->lpVtbl -> get_nodeName(This,name)
#define IXMLDOMProcessingInstruction_get_nodeValue(This,value)	\
    (This)->lpVtbl -> get_nodeValue(This,value)
#define IXMLDOMProcessingInstruction_put_nodeValue(This,value)	\
    (This)->lpVtbl -> put_nodeValue(This,value)
#define IXMLDOMProcessingInstruction_get_nodeType(This,type)	\
    (This)->lpVtbl -> get_nodeType(This,type)
#define IXMLDOMProcessingInstruction_get_parentNode(This,parent)	\
    (This)->lpVtbl -> get_parentNode(This,parent)
#define IXMLDOMProcessingInstruction_get_firstChild(This,firstChild)	\
    (This)->lpVtbl -> get_firstChild(This,firstChild)
#define IXMLDOMProcessingInstruction_get_lastChild(This,lastChild)	\
    (This)->lpVtbl -> get_lastChild(This,lastChild)
#define IXMLDOMProcessingInstruction_get_attributes(This,attributeMap)	\
    (This)->lpVtbl -> get_attributes(This,attributeMap)
#define IXMLDOMProcessingInstruction_insertBefore(This,newChild,refChild,outNewChild)	\
    (This)->lpVtbl -> insertBefore(This,newChild,refChild,outNewChild)
#define IXMLDOMProcessingInstruction_replaceChild(This,newChild,oldChild,outOldChild)	\
    (This)->lpVtbl -> replaceChild(This,newChild,oldChild,outOldChild)
#define IXMLDOMProcessingInstruction_removeChild(This,childNode,oldChild)	\
    (This)->lpVtbl -> removeChild(This,childNode,oldChild)
#define IXMLDOMProcessingInstruction_appendChild(This,newChild,outNewChild)	\
    (This)->lpVtbl -> appendChild(This,newChild,outNewChild)
#define IXMLDOMProcessingInstruction_hasChildNodes(This,hasChild)	\
    (This)->lpVtbl -> hasChildNodes(This,hasChild)
#define IXMLDOMProcessingInstruction_get_ownerDocument(This,DOMDocument)	\
    (This)->lpVtbl -> get_ownerDocument(This,DOMDocument)
#define IXMLDOMProcessingInstruction_cloneNode(This,deep,cloneRoot)	\
    (This)->lpVtbl -> cloneNode(This,deep,cloneRoot)
#define IXMLDOMProcessingInstruction_get_nodeTypeString(This,nodeType)	\
    (This)->lpVtbl -> get_nodeTypeString(This,nodeType)
#define IXMLDOMProcessingInstruction_get_text(This,text)	\
    (This)->lpVtbl -> get_text(This,text)
#define IXMLDOMProcessingInstruction_put_text(This,text)	\
    (This)->lpVtbl -> put_text(This,text)
#define IXMLDOMProcessingInstruction_get_specified(This,isSpecified)	\
    (This)->lpVtbl -> get_specified(This,isSpecified)
#define IXMLDOMProcessingInstruction_get_definition(This,definitionNode)	\
    (This)->lpVtbl -> get_definition(This,definitionNode)
#define IXMLDOMProcessingInstruction_get_nodeTypedValue(This,typedValue)	\
    (This)->lpVtbl -> get_nodeTypedValue(This,typedValue)
#define IXMLDOMProcessingInstruction_put_nodeTypedValue(This,typedValue)	\
    (This)->lpVtbl -> put_nodeTypedValue(This,typedValue)
#define IXMLDOMProcessingInstruction_get_dataType(This,dataTypeName)	\
    (This)->lpVtbl -> get_dataType(This,dataTypeName)
#define IXMLDOMProcessingInstruction_put_dataType(This,dataTypeName)	\
    (This)->lpVtbl -> put_dataType(This,dataTypeName)
#define IXMLDOMProcessingInstruction_get_xml(This,xmlString)	\
    (This)->lpVtbl -> get_xml(This,xmlString)
#define IXMLDOMProcessingInstruction_transformNode(This,stylesheet,xmlString)	\
    (This)->lpVtbl -> transformNode(This,stylesheet,xmlString)
#define IXMLDOMProcessingInstruction_selectSingleNode(This,queryString,resultNode)	\
    (This)->lpVtbl -> selectSingleNode(This,queryString,resultNode)
#define IXMLDOMProcessingInstruction_get_parsed(This,isParsed)	\
    (This)->lpVtbl -> get_parsed(This,isParsed)
#define IXMLDOMProcessingInstruction_get_namespaceURI(This,namespaceURI)	\
    (This)->lpVtbl -> get_namespaceURI(This,namespaceURI)
#define IXMLDOMProcessingInstruction_get_prefix(This,prefixString)	\
    (This)->lpVtbl -> get_prefix(This,prefixString)
#define IXMLDOMProcessingInstruction_transformNodeToObject(This,stylesheet,outputObject)	\
    (This)->lpVtbl -> transformNodeToObject(This,stylesheet,outputObject)
#define IXMLDOMProcessingInstruction_get_target(This,name)	\
    (This)->lpVtbl -> get_target(This,name)
#define IXMLDOMProcessingInstruction_get_data(This,value)	\
    (This)->lpVtbl -> get_data(This,value)
#define IXMLDOMProcessingInstruction_put_data(This,value)	\
    (This)->lpVtbl -> put_data(This,value)
#define ISAXContentHandler_processingInstruction(This,pwchTarget,cchTarget,pwchData,cchData)	\
    (This)->lpVtbl -> processingInstruction(This,pwchTarget,cchTarget,pwchData,cchData)
#define IVBSAXContentHandler_processingInstruction(This,strTarget,strData)	\
    (This)->lpVtbl -> processingInstruction(This,strTarget,strData)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\cache.h
#define CBS_Init()                      Cache_Init(&g_cacheCBS)
#define CBS_InitCS()                    Cache_InitCS(&g_cacheCBS)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\comm.h
#define GReAlloc(pv, cbNewSize) GlobalReAlloc(pv, cbNewSize, GMEM_MOVEABLE | GMEM_ZEROINIT)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\heapaloc.h
#define Alloc(cb)                             HeapLocalAlloc(LMEM_ZEROINIT | LMEM_FIXED, cb)
#define ReAlloc(pb, cb)                       HeapLocalReAlloc(pb, cb, LMEM_ZEROINIT | LMEM_FIXED)

// com\ole32\com\txf\inc\vtableimpl.h
    #define rmeth(i) (PFN_VTABLE_ENTRY)(&methname(i)),
#define defineVtable(name, qi, ar, rel)                             \
                                                                    \
    extern "C" const PFN_VTABLE_ENTRY name[] =                      \
        {                                                           \
        (PFN_VTABLE_ENTRY)(&qi),                                    \
        (PFN_VTABLE_ENTRY)(&ar),                                    \
        (PFN_VTABLE_ENTRY)(&rel),                                   \
	    rmeth(3)            \
	    rmeth(4)            \
	    rmeth(5)            \
	    rmeth(6)            \
	    rmeth(7)            \
	    rmeth(8)            \
	    rmeth(9)            \
	    rmeth10(1)          \
	    rmeth10(2)          \
	    rmeth10(3)          \
	    rmeth10(4)          \
	    rmeth10(5)          \
	    rmeth10(6)          \
	    rmeth10(7)          \
	    rmeth10(8)          \
	    rmeth10(9)          \
	    rmeth100(1)         \
	    rmeth100(2)         \
	    rmeth100(3)         \
	    rmeth100(4)         \
	    rmeth100(5)         \
	    rmeth100(6)         \
	    rmeth100(7)         \
	    rmeth100(8)         \
	    rmeth100(9)         \
	    rmeth10(100)        \
	    rmeth10(101)        \
	    rmeth(1020)         \
	    rmeth(1021)         \
	    rmeth(1022)         \
	    rmeth(1023)         \
        };
#define defineVtable(name, qi, ar, rel) \
    .extern qi;                         \
    .extern ar;                         \
    .extern rel;                        \
                                        \
    .globl name;                        \
                                        \
    name:                               \
        .long qi;           \
        .long ar;           \
        .long rel;          \
	    rmeth(3)            \
	    rmeth(4)            \
	    rmeth(5)            \
	    rmeth(6)            \
	    rmeth(7)            \
	    rmeth(8)            \
	    rmeth(9)            \
	    rmeth10(1)          \
	    rmeth10(2)          \
	    rmeth10(3)          \
	    rmeth10(4)          \
	    rmeth10(5)          \
	    rmeth10(6)          \
	    rmeth10(7)          \
	    rmeth10(8)          \
	    rmeth10(9)          \
	    rmeth100(1)         \
	    rmeth100(2)         \
	    rmeth100(3)         \
	    rmeth100(4)         \
	    rmeth100(5)         \
	    rmeth100(6)         \
	    rmeth100(7)         \
	    rmeth100(8)         \
	    rmeth100(9)         \
	    rmeth10(100)        \
	    rmeth10(101)        \
	    rmeth(1020)         \
	    rmeth(1021)         \
	    rmeth(1022)         \
	    rmeth(1023)         \
#define defineVtable(name, qi, ar, rel) \
    .extern qi;                         \
    .extern ar;                         \
    .extern rel;                        \
                                        \
    .globl name;                        \
                                        \
    name:                               \
        .quad qi;           \
        .quad ar;           \
        .quad rel;          \
	    rmeth(3)            \
	    rmeth(4)            \
	    rmeth(5)            \
	    rmeth(6)            \
	    rmeth(7)            \
	    rmeth(8)            \
	    rmeth(9)            \
	    rmeth10(1)          \
	    rmeth10(2)          \
	    rmeth10(3)          \
	    rmeth10(4)          \
	    rmeth10(5)          \
	    rmeth10(6)          \
	    rmeth10(7)          \
	    rmeth10(8)          \
	    rmeth10(9)          \
	    rmeth100(1)         \
	    rmeth100(2)         \
	    rmeth100(3)         \
	    rmeth100(4)         \
	    rmeth100(5)         \
	    rmeth100(6)         \
	    rmeth100(7)         \
	    rmeth100(8)         \
	    rmeth100(9)         \
	    rmeth10(100)        \
	    rmeth10(101)        \
	    rmeth(1020)         \
	    rmeth(1021)         \
	    rmeth(1022)         \
	    rmeth(1023)         \

// com\ole32\dcomss\objex\shrmem\dcom95\gentable.hxx
#define DEFINE_TABLE(DATA)                                          \
    typedef TCSafeResolverHashTable<DATA> DATA##Table;              \
    typedef TCSafeResolverHashTableIterator<DATA> DATA##TableIterator;

// com\ole32\ih\exports.hxx
#define API_CoInitialize                        (API_NAMETABLE|API_START)
#define API_CoUninitialize                      (API_NAMETABLE|(API_START+1))
#define API_CoGetClassObject                    (API_NAMETABLE|(API_START+2))
#define API_CoRegisterClassObject               (API_NAMETABLE|(API_START+3))
#define API_CoRevokeClassObject                 (API_NAMETABLE|(API_START+4))
#define API_CoMarshalInterface                  (API_NAMETABLE|(API_START+5))
#define API_CoUnmarshalInterface                (API_NAMETABLE|(API_START+6))
#define API_CoDisconnectObject                  (API_NAMETABLE|(API_START+8))
#define API_CoGetStandardMarshal                (API_NAMETABLE|(API_START+10))
#define API_CoIsHandlerConnected                (API_NAMETABLE|(API_START+11))
#define API_CoCreateInstance                    (API_NAMETABLE|(API_START+14))
#define API_CoIsOle1Class                       (API_NAMETABLE|(API_START+16))
#define API_ProgIDFromCLSID                     (API_NAMETABLE|(API_START+17))
#define API_CLSIDFromProgID                     (API_NAMETABLE|(API_START+18))
#define API_CoCreateGuid                        (API_NAMETABLE|(API_START+19))
#define API_CoRegisterMessageFilter             (API_NAMETABLE|(API_START+23))
#define API_CoGetTreatAsClass                   (API_NAMETABLE|(API_START+24))
#define API_CoTreatAsClass                      (API_NAMETABLE|(API_START+25))
#define API_DllGetClassObject                   (API_NAMETABLE|(API_START+26))
#define API_StgCreateDocfile                    (API_NAMETABLE|(API_START+27))
#define API_StgOpenStorage                      (API_NAMETABLE|(API_START+29))
#define API_StgIsStorageFile                    (API_NAMETABLE|(API_START+31))
#define API_CreateDataAdviseHolder              (API_NAMETABLE|(API_START+34))
#define API_CreateDataCache                     (API_NAMETABLE|(API_START+35))
#define API_BindMoniker                         (API_NAMETABLE|(API_START+36))
#define API_MkParseDisplayName                  (API_NAMETABLE|(API_START+37))
#define API_MonikerRelativePathTo               (API_NAMETABLE|(API_START+38))
#define API_MonikerCommonPrefixWith             (API_NAMETABLE|(API_START+39))
#define API_CreateBindCtx                       (API_NAMETABLE|(API_START+40))
#define API_CreateGenericComposite              (API_NAMETABLE|(API_START+41))
#define API_GetClassFile                        (API_NAMETABLE|(API_START+42))
#define API_CreateFileMoniker                   (API_NAMETABLE|(API_START+43))
#define API_CreateItemMoniker                   (API_NAMETABLE|(API_START+44))
#define API_CreateAntiMoniker                   (API_NAMETABLE|(API_START+45))
#define API_GetRunningObjectTable               (API_NAMETABLE|(API_START+47))
#define API_ReadClassStg                        (API_NAMETABLE|(API_START+48))
#define API_WriteClassStg                       (API_NAMETABLE|(API_START+49))
#define API_ReadClassStm                        (API_NAMETABLE|(API_START+50))
#define API_WriteClassStm                       (API_NAMETABLE|(API_START+51))
#define API_WriteFmtUserTypeStg                 (API_NAMETABLE|(API_START+52))
#define API_ReadFmtUserTypeStg                  (API_NAMETABLE|(API_START+53))
#define API_OleInitialize                       (API_NAMETABLE|(API_START+54))
#define API_OleUninitialize                     (API_NAMETABLE|(API_START+55))
#define API_OleQueryLinkFromData                (API_NAMETABLE|(API_START+56))
#define API_OleQueryCreateFromData              (API_NAMETABLE|(API_START+57))
#define API_OleCreate                           (API_NAMETABLE|(API_START+58))
#define API_OleCreateFromData                   (API_NAMETABLE|(API_START+59))
#define API_OleCreateLinkFromData               (API_NAMETABLE|(API_START+60))
#define API_OleCreateStaticFromData             (API_NAMETABLE|(API_START+61))
#define API_OleCreateLink                       (API_NAMETABLE|(API_START+62))
#define API_OleCreateLinkToFile                 (API_NAMETABLE|(API_START+63))
#define API_OleCreateFromFile                   (API_NAMETABLE|(API_START+64))
#define API_OleLoad                             (API_NAMETABLE|(API_START+65))
#define API_OleSave                             (API_NAMETABLE|(API_START+66))
#define API_OleNoteObjectVisible                (API_NAMETABLE|(API_START+70))
#define API_RegisterDragDrop                    (API_NAMETABLE|(API_START+71))
#define API_RevokeDragDrop                      (API_NAMETABLE|(API_START+72))
#define API_DoDragDrop                          (API_NAMETABLE|(API_START+73))
#define API_OleSetClipboard                     (API_NAMETABLE|(API_START+74))
#define API_OleGetClipboard                     (API_NAMETABLE|(API_START+75))
#define API_OleFlushClipboard                   (API_NAMETABLE|(API_START+76))
#define API_OleIsCurrentClipboard               (API_NAMETABLE|(API_START+77))
#define API_OleCreateMenuDescriptor             (API_NAMETABLE|(API_START+78))
#define API_OleSetMenuDescriptor                (API_NAMETABLE|(API_START+79))
#define API_OleDraw                             (API_NAMETABLE|(API_START+81))
#define API_OleRun                              (API_NAMETABLE|(API_START+82))
#define API_OleIsRunning                        (API_NAMETABLE|(API_START+83))
#define API_OleLockRunning                      (API_NAMETABLE|(API_START+84))
#define API_CreateOleAdviseHolder               (API_NAMETABLE|(API_START+85))
#define API_OleCreateDefaultHandler             (API_NAMETABLE|(API_START+86))
#define API_OleCreateEmbeddingHelper            (API_NAMETABLE|(API_START+87))
#define API_OleRegGetUserType                   (API_NAMETABLE|(API_START+88))
#define API_OleRegEnumFormatEtc                 (API_NAMETABLE|(API_START+90))
#define API_OleRegEnumVerbs                     (API_NAMETABLE|(API_START+91))
#define API_OleDoAutoConvert                    (API_NAMETABLE|(API_START+96))
#define API_OleGetAutoConvert                   (API_NAMETABLE|(API_START+97))
#define API_OleSetAutoConvert                   (API_NAMETABLE|(API_START+98))
#define API_GetConvertStg                       (API_NAMETABLE|(API_START+99))
#define API_SetConvertStg                       (API_NAMETABLE|(API_START+100))
#define API_ReadOleStg                          (API_NAMETABLE|(API_START+101))
#define API_WriteOleStg                         (API_NAMETABLE|(API_START+102))
#define API_CoGetCallerTID                      (API_NAMETABLE|(API_START+103))
#define API_CoGetState                          (API_NAMETABLE|(API_START+104))
#define API_CoSetState                          (API_NAMETABLE|(API_START+105))
#define API_CoGetPSClsid                        (API_NAMETABLE|(API_START+109))
#define API_CoBuildVersion                      (API_NAMETABLE|(API_START+115))
#define API_CoGetMalloc                         (API_NAMETABLE|(API_START+116))
#define API_CoInitializeWOW                     (API_NAMETABLE|(API_START+117))
#define API_CoUnloadingWOW                      (API_NAMETABLE|(API_START+118))
#define API_CoTaskMemAlloc                      (API_NAMETABLE|(API_START+119))
#define API_CoTaskMemRealloc                    (API_NAMETABLE|(API_START+121))
#define API_CoLoadLibrary                       (API_NAMETABLE|(API_START+123))
#define API_OleInitializeWOW                    (API_NAMETABLE|(API_START+125))
#define API_OleDuplicateData                    (API_NAMETABLE|(API_START+126))
#define API_OleGetIconOfFile                    (API_NAMETABLE|(API_START+127))
#define API_OleGetIconOfClass                   (API_NAMETABLE|(API_START+128))
#define API_OleMetafilePictFromIconAndLabel     (API_NAMETABLE|(API_START+129))
#define API_OleTranslateAccelerator             (API_NAMETABLE|(API_START+130))
#define API_IsAccelerator                       (API_NAMETABLE|(API_START+135))
#define API_CoGetCurrentProcess                 (API_NAMETABLE|(API_START+143))
#define API_CoRegisterMallocSpy                 (API_NAMETABLE|(API_START+145))
#define API_CoRevokeMallocSpy                   (API_NAMETABLE|(API_START+146))
#define API_CoGetObject                         (API_NAMETABLE|(API_START+148))
#define API_CreateClassMoniker                  (API_NAMETABLE|(API_START+149))
#define API_OleCreateEx                         (API_NAMETABLE|(API_START+150))
#define API_OleCreateFromDataEx                 (API_NAMETABLE|(API_START+151))
#define API_OleCreateLinkFromDataEx             (API_NAMETABLE|(API_START+152))
#define API_OleCreateLinkEx                     (API_NAMETABLE|(API_START+153))
#define API_OleCreateLinkToFileEx               (API_NAMETABLE|(API_START+154))
#define API_OleCreateFromFileEx                 (API_NAMETABLE|(API_START+155))
#define API_CoRegisterSurrogate                 (API_NAMETABLE|(API_START+156))
#define API_CoCreateInstanceExAsync             (API_NAMETABLE|(API_START+157))
#define API_CoGetClassObjectAsync               (API_NAMETABLE|(API_START+158))

// com\ole32\ih\memapi.hxx
#define PrivMemAlloc8(ulcb) PrivMemAlloc(((ulcb)+7)&~7)

// com\ole32\oleprx32\proxy\transmit.h
#define WdtpAllocate(p,size)    \
    ((USER_MARSHAL_CB *)p)->pStubMsg->pfnAllocate( size )

// com\ole32\olethunk\ole16\inc\windows.h
#define DCB_SET 	(DCB_RESET | DCB_ACCUMULATE)
#define EM_EMPTYUNDOBUFFER      (WM_USER+29)
#define CB_GETEDITSEL	         (WM_USER+0)
#define CB_SETEDITSEL	         (WM_USER+2)
#define CB_DIR                   (WM_USER+5)
#define CB_GETCURSEL	         (WM_USER+7)
#define CB_RESETCONTENT	         (WM_USER+11)
#define CB_SETCURSEL	         (WM_USER+14)
#define CB_SHOWDROPDOWN          (WM_USER+15)
#define CB_GETITEMDATA           (WM_USER+16)
#define CB_SETITEMDATA           (WM_USER+17)
#define CB_GETDROPPEDCONTROLRECT (WM_USER+18)
#define CB_SETITEMHEIGHT         (WM_USER+19)
#define CB_GETITEMHEIGHT         (WM_USER+20)
#define CB_GETDROPPEDSTATE       (WM_USER+23)

// com\ole32\olethunk\olethk32\thop.hxx
#define SKIP_STACK16(s16, cb) \
    (s16)->pbCurrent = (s16)->iDir < 0 ? \
            (s16)->pbCurrent-(cb) : \
            (s16)->pbCurrent+(cb)
#define SKIP_STACK32(s32, cb) \
    (s32)->pbCurrent += (cb)

// com\ole32\olethunk\olethk32\thoputil.hxx
#define StackAlloc16(cb) \
    ((VPVOID)TlsThkGetStack16()->Alloc(cb))
#define StackAlloc32(cb) \
    ((LPVOID)TlsThkGetStack32()->Alloc(cb))

// com\oleutest\balls\common\bscbnd.hxx
#define STGM_DFRALL (STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_DENY_WRITE)

// com\oleutest\balls\myproxy\myproxy.cxx
#define DECLARE_INTERNAL_PROXY()			       \
    class CInternalUnk : public IRpcProxyBuffer		       \
    {							       \
    public:						       \
	STDMETHOD(QueryInterface)(REFIID riid, void **ppvObj); \
	STDMETHOD_(ULONG,AddRef)(void) ;		       \
	STDMETHOD_(ULONG,Release)(void);		       \
	STDMETHOD(Connect)(IRpcChannelBuffer *pChnl);	       \
	STDMETHOD_(void, Disconnect)(void);		       \
    };							       \
    friend CInternalUnk;				       \
    CInternalUnk _InternalUnk;

// com\oleutest\balls\oleprx32\proxy\transmit.h
#define WdtpAllocate(p,size)    \
    ((USER_MARSHAL_CB *)p)->pStubMsg->pfnAllocate( size )

// com\rpc\ndrexts\ndrexts\bufout.cxx
#define PRINT_REDIRECT_TYPE(type,func)      \
void BUFFER_PRINTER::HANDLE_##type() {      \
   func();                                  \
}
#define PRINT_SIMPLE_TYPE(type)             \
void BUFFER_PRINTER::HANDLE_##type() {      \
   OutputSimpleType( FALSE, 0 );            \
}

// com\rpc\ndrexts\ndrexts\ndrexts.cxx
#define DECLARE_SIMPLE_STRUCT_PRINTER(apiname,structtype)              \
VOID Print##apiname##Usage(VOID)                                       \
    {                                                                  \
    dout <<                                                            \
    "Syntax:                                            \n"            \
    "!ndrexts." #apiname "<address>                     \n"            \
    "                                                   \n"            \
    "Prints a " #structtype " at address.               \n"            \
    "                                                   \n"            \
    "Parameters:                                        \n"            \
    "    Address: address of " #structtype " to print.  \n"            \
    "\n";                                                              \
    }                                                                  \
                                                                       \
VOID                                                                   \
do2##apiname(UINT64 Address)                                           \
{                                                                      \
    dout << "Printing " #structtype " at " << HexOut(Address) << '\n'; \
    structtype structdata;                                             \
    ReadMemory(Address, &structdata);                                  \
    IndentLevel l(dout);                                               \
    Print(dout, structdata, VerbosityLevel);                           \
    dout << '\n';                                                      \
}                                                                      \
                                                                       \
VOID                                                                   \
do##apiname(VOID)                                                      \
{                                                                      \
    ProcessSimpleExtapiOneNumParam(do2##apiname,Print##apiname##Usage);\
}                                                                      \
                                                                       \
#define END_C_ENTRY                                   \
    }                                                 \
    catch ( exception & e )                           \
        {                                             \
        conout << '\n';                               \
        conout << "An unexpected error occurred.\n";   \
        conout << e.what() << '\n';                   \
        }                                             \

// drivers\input\hidport\kbdhid\kbdhid.c
#define NewTypematic ((PKEYBOARD_TYPEMATIC_PARAMETERS) \
                      Irp->AssociatedIrp.SystemBuffer)

// drivers\input\pnpi8042\kbddep.c
#define BUFFER_FULL   (OUTPUT_BUFFER_FULL|MOUSE_OUTPUT_BUFFER_FULL)

// drivers\input\pnpi8042\moudep.c
#define BUFFER_FULL   (OUTPUT_BUFFER_FULL | MOUSE_OUTPUT_BUFFER_FULL)

// drivers\ksfilter\ks\ksp.h
#define IMPLEMENT_GETSTRUCT(CKsXxx,PKSXXX)\
    PKSXXX\
    CKsXxx::\
    GetStruct(\
        void\
        )\
    {\
        return &m_Ext.Public;\
    }

// drivers\serial\mps\cyclades\y\cyycoins\pp.h
#define IDH_DEVMGR_PORTSET_ADV_USEFIFO  16885   // "&Use FIFO buffers (requires 16550 compatible UART)" (Button)

// drivers\serial\mps\cyclades\y\cyyports\advandlg.h
#define IDH_DEVMGR_PORTSET_ADV_USEFIFO  16885   // "&Use FIFO buffers (requires 16550 compatible UART)" (Button)

// drivers\serial\mps\cyclades\z\cyzcoins\pp.h
#define IDH_DEVMGR_PORTSET_ADV_USEFIFO  16885   // "&Use FIFO buffers (requires 16550 compatible UART)" (Button)

// drivers\serial\mps\cyclades\z\cyzports\advandlg.h
#define IDH_DEVMGR_PORTSET_ADV_USEFIFO  16885   // "&Use FIFO buffers (requires 16550 compatible UART)" (Button)

// drivers\serial\mps\spx\mps\sx\inc\sx_defs.h
#define SX_PCI_HWID		L"PCI\\VEN_11CB&DEV_2000&SUBSYS_020011CB"	// SX PCI (T225) card
#define SXPLUS_PCI_HWID	L"PCI\\VEN_11CB&DEV_2000&SUBSYS_030011CB"	// SX+ PCI (MCF5206e) card
#define SIXIO_PCI_HWID	L"PCI\\VEN_11CB&DEV_4000&SUBSYS_040011CB"	// SIXIO PCI (Z280) card

// drivers\serial\mps\spx\speed\driver\inc\spd_defs.h
#define SPD2AND4_PCI_NO_F1_HWID			L"PCI\\VEN_1415&DEV_9510&SUBSYS_000011CB"	// (F1: Unusable).
#define SPD4_PCI_PCI954_HWID			L"PCI\\VEN_1415&DEV_9501&SUBSYS_A00411CB"	// (F0: Quad 950 UART).
#define SPD4P_PCI_PCI954_HWID			L"PCI\\VEN_11CB&DEV_9501&SUBSYS_A00411CB"	// (F0: Quad 950 UART).
#define SPD2_PCI_PCI954_HWID			L"PCI\\VEN_1415&DEV_9501&SUBSYS_A00211CB"	// (F0: 2 950 UARTs).
#define SPD2P_PCI_PCI954_HWID			L"PCI\\VEN_11CB&DEV_9501&SUBSYS_A00211CB"	// (F0: 2 950 UARTs).
#define DELAY_INTERRUPT_OPTION		0x00000001		// Settable on PCI-Fast 16 & PCI-Fast 16 FMC (Interrupt delayed 1.1 ms)

// drivers\smartcrd\gempc430\kernel.h
#define IMPLEMENT_CALLBACK_ISR(fname)	\
			BOOL fname(struct _KINTERRUPT *Interrupt,PDEVICE_OBJECT pDO)\
				{if(CDEVICE(pDO)) return CDEVICE(pDO)->fname();}

// drivers\storage\mpath\include\dsm.h
#define IOCTL_MPDSM_REGISTER CTL_CODE (MPIO_DSM, 0x01, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// drivers\storage\tffsport\amdmtd.c
    #define wBuffer ((const USHORT FAR1 * &) buffer)
    #define dBuffer ((const ULONG FAR1 * &) buffer)

// drivers\storage\tffsport\diskonc.c
#define flReadBackBufferOf(a) &(globalReadBack[a][0])

// drivers\storage\tffsport\i28f008.c
    #define wBuffer ((const USHORT FAR1 * &) buffer)
    #define dBuffer ((const ULONG FAR1 * &) buffer)

// drivers\storage\tffsport\mdocplus.c
#define flReadBackBufferOf(a) &(globalReadBack[a][0])

// drivers\storage\volsnap\vss\modules\sqllib\inc\vdi.h
#define IClientVirtualDeviceSet_GetBufferHandle(This,pBuffer,pBufferHandle)	\
    (This)->lpVtbl -> GetBufferHandle(This,pBuffer,pBufferHandle)
#define IClientVirtualDeviceSet_MapBufferHandle(This,dwBuffer,ppBuffer)	\
    (This)->lpVtbl -> MapBufferHandle(This,dwBuffer,ppBuffer)
#define IClientVirtualDeviceSet2_GetBufferHandle(This,pBuffer,pBufferHandle)	\
    (This)->lpVtbl -> GetBufferHandle(This,pBuffer,pBufferHandle)
#define IClientVirtualDeviceSet2_MapBufferHandle(This,dwBuffer,ppBuffer)	\
    (This)->lpVtbl -> MapBufferHandle(This,dwBuffer,ppBuffer)
#define IServerVirtualDeviceSet_FreeBuffer(This,pBuffer,dwSize)	\
    (This)->lpVtbl -> FreeBuffer(This,pBuffer,dwSize)
#define IServerVirtualDeviceSet_IsSharedBuffer(This,pBuffer)	\
    (This)->lpVtbl -> IsSharedBuffer(This,pBuffer)
#define IServerVirtualDeviceSet2_FreeBuffer(This,pBuffer,dwSize)	\
    (This)->lpVtbl -> FreeBuffer(This,pBuffer,dwSize)
#define IServerVirtualDeviceSet2_IsSharedBuffer(This,pBuffer)	\
    (This)->lpVtbl -> IsSharedBuffer(This,pBuffer)

// drivers\storage\volsnap\vss\server\modules\sqllib\inc\vdi.h
#define IClientVirtualDeviceSet_GetBufferHandle(This,pBuffer,pBufferHandle)	\
    (This)->lpVtbl -> GetBufferHandle(This,pBuffer,pBufferHandle)
#define IClientVirtualDeviceSet_MapBufferHandle(This,dwBuffer,ppBuffer)	\
    (This)->lpVtbl -> MapBufferHandle(This,dwBuffer,ppBuffer)
#define IClientVirtualDeviceSet2_GetBufferHandle(This,pBuffer,pBufferHandle)	\
    (This)->lpVtbl -> GetBufferHandle(This,pBuffer,pBufferHandle)
#define IClientVirtualDeviceSet2_MapBufferHandle(This,dwBuffer,ppBuffer)	\
    (This)->lpVtbl -> MapBufferHandle(This,dwBuffer,ppBuffer)
#define IServerVirtualDeviceSet_FreeBuffer(This,pBuffer,dwSize)	\
    (This)->lpVtbl -> FreeBuffer(This,pBuffer,dwSize)
#define IServerVirtualDeviceSet_IsSharedBuffer(This,pBuffer)	\
    (This)->lpVtbl -> IsSharedBuffer(This,pBuffer)
#define IServerVirtualDeviceSet2_FreeBuffer(This,pBuffer,dwSize)	\
    (This)->lpVtbl -> FreeBuffer(This,pBuffer,dwSize)
#define IServerVirtualDeviceSet2_IsSharedBuffer(This,pBuffer)	\
    (This)->lpVtbl -> IsSharedBuffer(This,pBuffer)

// drivers\storage\volsnap\vss\server\tests\multilayer\ml.h
#define VSS_ERROR_CASE(wszBuffer, dwBufferLen, X) 	\
    case X:  ::wcsncpy(wszBuffer, VSS_MAKE_W(VSS_EVAL(#X)), dwBufferLen); break;

// drivers\storage\volsnap\vss\tests\harness\inc\bsfixalloc.hxx
#define DECLARE_FIXED_ALLOC(class_name) \
public: \
	void* operator new(size_t size) \
	{ \
		ASSERT(size == s_alloc.GetAllocSize()); \
		UNUSED(size); \
		return s_alloc.Alloc(); \
	} \
	void* operator new(size_t, void* p) \
		{ return p; } \
	void operator delete(void* p) { s_alloc.Free(p); } \
	void* operator new(size_t size, LPCSTR, int) \
	{ \
		ASSERT(size == s_alloc.GetAllocSize()); \
		UNUSED(size); \
		return s_alloc.Alloc(); \
	} \
protected: \
	static CBsFixedAlloc s_alloc \

// drivers\video\ms\3dlabs\perm3\disp\inc\driver.h
#define WRITE_DD_DMA_ULONG(ul) \
    *ppdev->DMABuffer.pulCurrent++ = ul

// drivers\video\ms\ati\mini\amach1.h
#define QUERY_GET_SIZE   0       // return query structure size   (varying modes)

// drivers\video\ms\laguna\disp\include\laguna.h
#define HISTORYBUFFERADDR (ul)&history           /* 34020 address of recording    */

// drivers\wdm\audio\legacy\wdmaud.sys\mixer.h
#define kmxlRemoveFirstChildNode( pNode )                             \
            RemoveFirstEntry( (pNode)->Children, PEERNODE )
#define kmxlRemoveFirstParentNode( pNode )                            \
            RemoveFirstEntry( (pNode)->Parents, PEERNODE )

// drivers\wdm\input\hidusb\hidusb.h
#define HumBuildGetDescriptorRequest(urb, \
                                     function, \
                                     length, \
                                     descriptorType, \
                                     index, \
                                     languageId, \
                                     transferBuffer, \
                                     transferBufferMDL, \
                                     transferBufferLength, \
                                     link) { \
            (urb)->UrbHeader.Function =  (function); \
            (urb)->UrbHeader.Length = (length); \
            (urb)->UrbControlDescriptorRequest.TransferBufferLength = (transferBufferLength); \
            (urb)->UrbControlDescriptorRequest.TransferBufferMDL = (transferBufferMDL); \
            (urb)->UrbControlDescriptorRequest.TransferBuffer = (transferBuffer); \
            (urb)->UrbControlDescriptorRequest.DescriptorType = (descriptorType); \
            (urb)->UrbControlDescriptorRequest.Index = (index); \
            (urb)->UrbControlDescriptorRequest.LanguageId = (languageId); \
            (urb)->UrbControlDescriptorRequest.UrbLink = (link); }
#define HumBuildOsFeatureDescriptorRequest(urb, \
                              length, \
                              interface, \
                              index, \
                              transferBuffer, \
                              transferBufferMDL, \
                              transferBufferLength, \
                              link) { \
            (urb)->UrbHeader.Function = URB_FUNCTION_GET_MS_FEATURE_DESCRIPTOR; \
            (urb)->UrbHeader.Length = (length); \
            (urb)->UrbOSFeatureDescriptorRequest.TransferBufferLength = (transferBufferLength); \
            (urb)->UrbOSFeatureDescriptorRequest.TransferBufferMDL = (transferBufferMDL); \
            (urb)->UrbOSFeatureDescriptorRequest.TransferBuffer = (transferBuffer); \
            (urb)->UrbOSFeatureDescriptorRequest.InterfaceNumber = (interface); \
            (urb)->UrbOSFeatureDescriptorRequest.MS_FeatureDescriptorIndex = (index); \
            (urb)->UrbOSFeatureDescriptorRequest.UrbLink = (link); }

// drivers\wdm\input\legacy\mshgame\gckernel.sys\gckextrn.h
#define GCK_IOCTL_CODE(_x_) CTL_CODE(                         \
					        FILE_DEVICE_UNKNOWN,              \
						    (0x0800 | _x_),                   \
                            METHOD_BUFFERED,                  \
                            FILE_ANY_ACCESS                   \
                            )

// drivers\wdm\input\tabletpc\cpl\mutohpen.c
#define CHANGED_FEATURES                (CHANGED_SAMPLINGRATE |     \
                                         CHANGED_DIGITAL_FILTER |   \
                                         CHANGED_GLITCH_FILTER)

// drivers\wdm\input\tabletpc\mutohpen\hidpen.h
#define GET_PDO(DO) \
    (((PHID_DEVICE_EXTENSION)(DO)->DeviceExtension)->PhysicalDeviceObject)

// drivers\wdm\input\tabletpc\tabsrv\supertip_obj.h
#define ISuperTip_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISuperTip_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISuperTip_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISuperTip_Activate(This)	\
    (This)->lpVtbl -> Activate(This)
#define ISuperTip_Deactivate(This)	\
    (This)->lpVtbl -> Deactivate(This)
#define ISuperTip_Show(This,show,pt)	\
    (This)->lpVtbl -> Show(This,show,pt)
#define ISuperTip_IsVisible(This,pfIsVisible)	\
    (This)->lpVtbl -> IsVisible(This,pfIsVisible)
#define ISuperTip_ShowMIP(This,show,pt)	\
    (This)->lpVtbl -> ShowMIP(This,show,pt)
#define ISuperTip_HitTest(This,pt,phtResult)	\
    (This)->lpVtbl -> HitTest(This,pt,phtResult)
#define ISuperTip_SetNotifyHWND(This,hWndNotify,uMsgNotify,lParam)	\
    (This)->lpVtbl -> SetNotifyHWND(This,hWndNotify,uMsgNotify,lParam)

// drivers\wdm\input\tabletpc\tabsrv\tabsrv.h
#define TSF_ALLTHREAD                   (TSF_RPCTHREAD |        \
                                         TSF_SUPERTIPTHREAD |   \
                                         TSF_DIGITHREAD |       \
                                         TSF_MOUSETHREAD |      \
                                         TSF_BUTTONTHREAD)
#define BUTTONSTATE_DEFHOTKEY   (BUTTONSTATE_BUTTON_1 | BUTTONSTATE_BUTTON_5)

// drivers\wdm\usb\driver\usbdiag\_m_usb.h
#define _m_UsbBuildSetDescriptorRequest(urb, \
                                     length, \
                                     descriptorType, \
                                     index, \
                                     languageId, \
                                     transferBuffer, \
                                     transferBufferMDL, \
                                     transferBufferLength, \
                                     link) { \
            (urb)->UrbHeader.Function =  URB_FUNCTION_SET_DESCRIPTOR_TO_DEVICE; \
            (urb)->UrbHeader.Length = (length); \
            (urb)->UrbControlDescriptorRequest.TransferBufferLength = (transferBufferLength); \
            (urb)->UrbControlDescriptorRequest.TransferBufferMDL = (transferBufferMDL); \
            (urb)->UrbControlDescriptorRequest.TransferBuffer = (transferBuffer); \
            (urb)->UrbControlDescriptorRequest.DescriptorType = (descriptorType); \
            (urb)->UrbControlDescriptorRequest.Index = (index); \
            (urb)->UrbControlDescriptorRequest.LanguageId = (languageId); \
            (urb)->UrbControlDescriptorRequest.UrbLink = (link); }

// drivers\wdm\usb\driver\valueadd\valueadd.h
#define STIM_CODE(_x_) CTL_CODE(                             \
                           FILE_DEVICE_UNKNOWN,              \
                           (0x800 | _x_),                    \
                           METHOD_BUFFERED,                  \
                           FILE_ANY_ACCESS                   \
                           )

// ds\adsi\include\umi.h
#define IUmiObject_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiObject_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiConnection_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiConnection_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiCursor_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiCursor_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiQuery_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiQuery_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)

// ds\dns\dnslib\dnslibp.h
#define pFamilyInfoIp4  (&AddrFamilyTable[0])
#define pFamilyInfoIp6  (&AddrFamilyTable[1])
#define pFamilyInfoAtm  (&AddrFamilyTable[2])

// ds\dns\dnslib\message.h
#define SET_TO_WRITE_QUESTION_RECORDS(pMsg) \
            (pMsg)->pCurrentCountField = &(pMsg)->MessageHead.QuestionCount;
#define SET_TO_WRITE_ANSWER_RECORDS(pMsg) \
            (pMsg)->pCurrentCountField = &(pMsg)->MessageHead.AnswerCount;
#define SET_TO_WRITE_NAME_SERVER_RECORDS(pMsg) \
            (pMsg)->pCurrentCountField = &(pMsg)->MessageHead.NameServerCount;
#define SET_TO_WRITE_ADDITIONAL_RECORDS(pMsg) \
            (pMsg)->pCurrentCountField = &(pMsg)->MessageHead.AdditionalCount;

// ds\dns\server\server\msginfo.h
#define SAVE_FORWARDING_FIELDS(pMsg)    \
{                                       \
    PDNS_MSGINFO  pmsg = (pMsg);        \
    pmsg->U.Forward.OriginalSocket = pmsg->Socket;                        \
    pmsg->U.Forward.ipOriginal     = pmsg->RemoteAddress.sin_addr.s_addr; \
    pmsg->U.Forward.wOriginalPort  = pmsg->RemoteAddress.sin_port;        \
    pmsg->U.Forward.wOriginalXid   = pmsg->Head.Xid;                      \
}
#define RESTORE_FORWARDING_FIELDS(pMsg) \
{                                       \
    PDNS_MSGINFO  pmsg = (pMsg);        \
    pmsg->Socket                        = pmsg->U.Forward.OriginalSocket; \
    pmsg->RemoteAddress.sin_addr.s_addr = pmsg->U.Forward.ipOriginal;     \
    pmsg->RemoteAddress.sin_port        = pmsg->U.Forward.wOriginalPort;  \
    pmsg->Head.Xid                      = pmsg->U.Forward.wOriginalXid;   \
}
#define COPY_FORWARDING_FIELDS(pMsgTarget, pMsgOriginal) \
{                                                                                     \
    pMsgTarget->Socket                        = pMsgOriginal->U.Forward.OriginalSocket; \
    pMsgTarget->RemoteAddress.sin_addr.s_addr = pMsgOriginal->U.Forward.ipOriginal;     \
    pMsgTarget->RemoteAddress.sin_port        = pMsgOriginal->U.Forward.wOriginalPort;  \
    pMsgTarget->Head.Xid                      = pMsgOriginal->U.Forward.wOriginalXid;   \
}

// ds\dns\server\server\tree.h
#define DB_REVERSE_ZONE_DATA    ( &((PDB_NODE)REVERSE_DATA_TABLE)->pZone )

// ds\dns\server\server\zone.c
#define ZONE_LOCK_SET_HISTORY( pzone, file, line ) \
        Lock_SetLockHistory(                    \
            (pzone)->pLockTable,                \
            file,                               \
            line,                               \
            (pzone)->fLocked,                   \
            GetCurrentThreadId() );

// ds\dns\server\wmi\source\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// ds\ds\src\inc\mapiperf.h
#define MAPISetBufferNameFn(pv) \
	(!(pv) || !(*((ULONG *)(pv) - 2) & 0x40000000)) ? 0 : \
		(**((int (__cdecl ***)(void *, ...))((ULONG *)(pv) - 3))) \
			((void *)*((ULONG *)pv - 3), (ULONG *)pv - 4,

// ds\ds\src\ldap\client\dnfilter\h323asn1.h
#define	DECLARE_CODER_FUNCS(MODULE,STRUCTURE) \
/* static */ __inline DWORD MODULE ## EncodePdu_ ## STRUCTURE	\
	(STRUCTURE * PduStructure, OUT PUCHAR * ReturnBuffer, OUT PDWORD ReturnBufferLength)	\
	{ return MODULE ## EncodePdu (STRUCTURE ## _PDU, PduStructure, ReturnBuffer, ReturnBufferLength); }	\
/* static */ __inline DWORD MODULE ## DecodePdu_ ## STRUCTURE	\
	(IN PUCHAR Buffer, IN DWORD BufferLength, OUT STRUCTURE ** ReturnPduStructure)	\
	{ return MODULE ## DecodePdu (Buffer, BufferLength, STRUCTURE ## _PDU, (PVOID *) ReturnPduStructure); }	\
/* static */ __inline DWORD MODULE ## FreePdu_ ## STRUCTURE	\
	(IN STRUCTURE * PduStructure)	\
	{ return MODULE ## FreePdu (STRUCTURE ## _PDU, PduStructure); }

// ds\ds\src\sam\server\attr.c
#define SampFixedBufferAddress( c )                                         \
    (                                                                       \
        (IsDsObject(c)) ?                                                   \
            SampDsFixedBufferAddress(c): SampRegFixedBufferAddress(c)       \
    )
#define SampVariableBufferAddress( c )                                      \
    (                                                                       \
        (IsDsObject(c)) ?                                                   \
            SampDsVariableBufferAddress(c) : SampRegVariableBufferAddress(c)\
    )

// ds\ds\src\util\ldifds\ldifldap\lexer.c
#define yy_set_bol(at_bol) \
	{ \
	if ( ! yy_current_buffer ) \
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
	yy_current_buffer->yy_at_bol = at_bol; \
	}

// ds\ese98\export\jet.h
#define JET_tableidNil				(~(JET_TABLEID)0)

// ds\ese98\src\ese\db.cxx
#define IbCbFromPtag( ibP, cbP, ptagP )							\
			{	TAG *_ptagT = ptagP;					 		\
			(ibP) = _ptagT->ib;							 		\
			(cbP) = _ptagT->cb;							 		\
			}

// ds\netapi\svcimgs\ntrepl\inc\frs.h
#define UNLOCK_GEN_TABLE(_vv_)                              \
    DPRINT1(5, "UNLOCK_GEN_TABLE: "#_vv_":%08x\n", _vv_);   \
    GTabUnLockTable(_vv_);
#define DBS_GET_RECORD_ADDRESS(_DbsRequest) \
    ((_DbsRequest)->TableCtx->pDataRecord)
#define DBS_GET_TABLECTX(_DbsRequest) \
    ((_DbsRequest)->TableCtx)
#define DBS_GET_FIELD_SIZE(_TableCtx, _Field)  \
                          ((_TableCtx)->pJetRetCol[_Field].cbActual)
#define DBS_GET_FIELD_ADDRESS( _TableCtx, _Field)  \
                             ((_TableCtx)->pJetRetCol[_Field].pvData)
#define DBS_SET_FIELD_SIZE(_TableCtx, _Field, _NewSize)                        \
                          (_TableCtx)->pJetRetCol[_Field].cbActual = _NewSize; \
                          (_TableCtx)->pJetSetCol[_Field].cbData = _NewSize;
#define DBS_SET_FIELD_ADDRESS( _TableCtx, _Field, _NewAddr)  \
                             (_TableCtx)->pJetRetCol[_Field].pvData = _NewAddr; \
                             (_TableCtx)->pJetSetCol[_Field].pvData = _NewAddr;

// ds\netapi\svcimgs\ntrepl\inc\frsalloc.h
#define INIT_LOCALCO_CXTION_GUID(_Replica_, _Coe_)                            \
{                                                                             \
    PCXTION TCxtion;                                                          \
    LOCK_CXTION_TABLE(_Replica_);                                             \
    (_Coe_)->Cmd.CxtionGuid = (_Replica_)->JrnlCxtionGuid;                    \
    TCxtion = GTabLookupNoLock((_Replica_)->Cxtions,                          \
                               &(_Coe_)->Cmd.CxtionGuid,                      \
                               NULL);                                         \
    if (TCxtion != NULL) {                                                    \
        (_Coe_)->JoinGuid = TCxtion->JoinGuid;                                \
    }                                                                         \
    UNLOCK_CXTION_TABLE(_Replica_);                                           \
}
#define REPLICA_REPLAY_MODE(_Replica_, _pVme_)  \
    ((_Replica_)->LastUsnRecordProcessed > (_pVme_)->CurrentUsnRecord)
#define RsCoe(Cmd)          ((PCHANGE_ORDER_ENTRY) \
                                Cmd->Parameters.UnionRs.ChangeOrderEntry)
#define RsPartnerCocExt(Cmd) ((PCHANGE_ORDER_RECORD_EXTENSION) \
                                Cmd->Parameters.UnionRs.PartnerChangeOrderCommandExt)

// ds\netapi\svcimgs\ntrepl\inc\global.h
#define HASH_GUID(_pUL_, _TABLE_SIZE_) \
((_pUL_[0] ^ _pUL_[1] ^ _pUL_[2] ^ _pUL_[3]) & ((_TABLE_SIZE_)-1))

// ds\netapi\svcimgs\ntrepl\inc\jet.h
#define DBS_OPEN_TABLE(_ThreadCtx, _TableCtx, _ReplicaNumber, _TableName, _Tid) \
    (FrsOpenTableSaveTid = (_TableCtx)->Tid ,                  \
    DbsOpenTable0((_ThreadCtx), (_TableCtx), (_ReplicaNumber), (_TableName), (_Tid))); \
                                                               \
    if (FrsOpenTableSaveTid == JET_tableidNil) {               \
        DPRINT3(3,"FrsOpenTable  (%20s) Tid, Sesid = %08x, %08x\n",   \
                _TableName,                                    \
                _TableCtx->Tid,                                \
                _TableCtx->Sesid);                             \
    }

// ds\netapi\svcimgs\ntrepl\inc\replutil.h
#define FILTER_TABLE_CHILD_INDEX(_x_) \
((ULONG)((_x_)->ReplicaNumber) & (NUMBER_FILTER_TABLE_CHILD_LOCKS - 1))

// ds\netapi\svcimgs\ntrepl\inc\schema.h
#define IsFixedSzBufferField(_x_)   (((_x_) & DT_FIXED_SIZE_BUFFER) != 0)
#define CNF_RECORD(_Replica_) \
    ((PCONFIG_TABLE_RECORD) ((_Replica_)->ConfigTable.pDataRecord))

// ds\netapi\svcimgs\ntrepl\mkdso\mkdso.h
#define CLASS_DELETABLE             L"(|(objectClass=nTFRSSiteSettings)"  \
                                    L"(objectClass=nTFRSSettings)"        \
                                    L"(objectClass=nTFRSReplicaSet)"      \
                                    L"(objectClass=nTDSConnection))"

// ds\netapi\svcimgs\ntrepl\mkdsx\mkdsx.h
#define CLASS_DELETABLE             L"(|(objectClass=nTFRSSiteSettings)"  \
                                    L"(objectClass=nTFRSSettings)"        \
                                    L"(objectClass=nTFRSReplicaSet)"      \
                                    L"(objectClass=nTDSConnection))"

// ds\netapi\svcimgs\ntrepl\repl\createdb.c
#define FRS_INFO_PRINT(_Format, _d1)                       \
    InfoPrint(InfoTable->Info, "%-28s : " _Format,         \
              JColDesc[i].szColumnName, _d1)
#define FRS_INFO_PRINT2(_Format, _d1, _d2)                 \
    InfoPrint(InfoTable->Info, "%-28s : " _Format,         \
              JColDesc[i].szColumnName, _d1, _d2)
#define FRS_INFO_PRINT3(_Format, _d1, _d2, _d3)            \
    InfoPrint(InfoTable->Info, "%-28s : " _Format,         \
              JColDesc[i].szColumnName, _d1, _d2, _d3)
#define FRS_INFO_PRINT4(_Format, _d1, _d2, _d3, _d4)       \
    InfoPrint(InfoTable->Info, "%-28s : " _Format,         \
              JColDesc[i].szColumnName, _d1, _d2, _d3, _d4)

// ds\nw\rdr\ipx.c
    #define ATTACHPROCESS(_X) KeAttachProcess(&(_X)->Pcb);

// ds\nw\rdr\procs.h
#define NwReferenceScb( pNpScb ) \
        InterlockedIncrement( &(pNpScb)->Reference )
#define NwQuietReferenceScb( pNpScb ) \
        InterlockedIncrement( &(pNpScb)->Reference )
#define NwDereferenceScb( pNpScb ) \
        InterlockedDecrement( &(pNpScb)->Reference )
#define NwQuietDereferenceScb( pNpScb ) \
        InterlockedDecrement( &(pNpScb)->Reference )
#define NwAcquireExclusiveRcb( Rcb, Wait )  \
    ExAcquireResourceExclusiveLite( &((Rcb)->Resource), Wait )
#define NwAcquireSharedRcb( Rcb, Wait )  \
    ExAcquireResourceSharedLite( &((Rcb)->Resource), Wait )
#define NwAcquireExclusiveFcb( pFcb, Wait )  \
    ExAcquireResourceExclusiveLite( &((pFcb)->Resource), Wait )
#define NwAcquireSharedFcb( pFcb, Wait )  \
    ExAcquireResourceSharedLite( &((pFcb)->Resource), Wait )

// ds\nw\vwipxspx\dll\vwipxspx.h
#define IPX_ECB_BUFFER32(p) (ULPVOID)*(ULPVOID*)&(((LPIPX_ECB)(p))->DriverWorkspace[0])

// ds\security\passport\atlmfc\asptlb.h
#define IRequest_get_TotalBytes(This,pcbTotal)	\
    (This)->lpVtbl -> get_TotalBytes(This,pcbTotal)
#define IResponse_get_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> get_Buffer(This,fIsBuffering)
#define IResponse_put_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> put_Buffer(This,fIsBuffering)
#define IResponse_AppendToLog(This,bstrLogEntry)	\
    (This)->lpVtbl -> AppendToLog(This,bstrLogEntry)

// ds\security\passport\atlmfc\atlcom.h
#define BEGIN_PROP_VAL_MAP(theClass) \
	static ATL::ATL_PROPVALMAP_ENTRY* GetPropValMap(int *cnt)\
	{\
		static ATL::ATL_PROPVALMAP_ENTRY pPropMap[] = \
		{
#define DECLARE_EMPTY_PROP_VAL_MAP() \
public: \
	static ATL::ATL_PROPVALMAP_ENTRY* GetPropValMap(int *cnt)\
	{ \
		if (cnt)	\
			*cnt = 0;	\
		return NULL; \
	}
#define BEGIN_PROP_MAP(theClass) \
	__if_not_exists(__ATL_PROP_NOTIFY_EVENT_CLASS) \
	{ \
		typedef ATL::_ATL_PROP_NOTIFY_EVENT_CLASS __ATL_PROP_NOTIFY_EVENT_CLASS; \
	} \
	typedef theClass _PropMapClass; \
	static ATL::ATL_PROPMAP_ENTRY* GetPropertyMap()\
	{\
		static ATL::ATL_PROPMAP_ENTRY pPropMap[] = \
		{
#define DECLARE_PROTECT_FINAL_CONSTRUCT()\
	void InternalFinalConstructAddRef() {InternalAddRef();}\
	void InternalFinalConstructRelease() {InternalRelease();}
#define DECLARE_NOT_AGGREGATABLE(x) public:\
	typedef ATL::CComCreator2< ATL::CComCreator< ATL::CComObject< x > >, ATL::CComFailCreator<CLASS_E_NOAGGREGATION> > _CreatorClass;
#define DECLARE_AGGREGATABLE(x) public:\
	typedef ATL::CComCreator2< ATL::CComCreator< ATL::CComObject< x > >, ATL::CComCreator< ATL::CComAggObject< x > > > _CreatorClass;
#define DECLARE_ONLY_AGGREGATABLE(x) public:\
	typedef ATL::CComCreator2< ATL::CComFailCreator<E_FAIL>, ATL::CComCreator< ATL::CComAggObject< x > > > _CreatorClass;
#define DECLARE_POLY_AGGREGATABLE(x) public:\
	typedef ATL::CComCreator< ATL::CComPolyObject< x > > _CreatorClass;
#define BEGIN_ATTRCOM_MAP(x) public: \
	typedef x _AttrComMapClass; \
	const static ATL::_ATL_INTMAP_ENTRY* WINAPI _GetAttrEntries() throw() { \
	static const ATL::_ATL_INTMAP_ENTRY _entries[] = {
#define COM_INTERFACE_ENTRY_BREAK(x)\
	{&_ATL_IIDOF(x), \
	NULL, \
	_Break},
#define COM_INTERFACE_ENTRY_NOINTERFACE(x)\
	{&_ATL_IIDOF(x), \
	NULL, \
	_NoInterface},
#define COM_INTERFACE_ENTRY_IMPL(x)\
	COM_INTERFACE_ENTRY_IID(_ATL_IIDOF(x), x##Impl<_ComMapClass>)
#define COM_INTERFACE_ENTRY_IMPL_IID(iid, x)\
	COM_INTERFACE_ENTRY_IID(iid, x##Impl<_ComMapClass>)
#define COM_INTERFACE_ENTRY_FUNC(iid, dw, func)\
	{&iid, \
	dw, \
	func},
#define BEGIN_CATEGORY_MAP(x)\
	static const struct ATL::_ATL_CATMAP_ENTRY* GetCategoryMap() throw() {\
	static const struct ATL::_ATL_CATMAP_ENTRY pMap[] = {
#define END_CATEGORY_MAP()\
   { _ATL_CATMAP_ENTRY_END, NULL } };\
   return( pMap ); }
#define OBJECT_ENTRY(clsid, class) {&clsid, class::UpdateRegistry, class::_ClassFactoryCreatorClass::CreateInstance, class::_CreatorClass::CreateInstance, NULL, 0, class::GetObjectDescription, class::GetCategoryMap, class::ObjectMain },
#define OBJECT_ENTRY_NON_CREATEABLE(class) {&CLSID_NULL, class::UpdateRegistry, NULL, NULL, NULL, 0, NULL, class::GetCategoryMap, class::ObjectMain },
#define OBJECT_ENTRY_NON_CREATEABLE_EX(clsid, class) {&clsid, class::UpdateRegistry, NULL, NULL, NULL, 0, NULL, class::GetCategoryMap, class::ObjectMain },
#define OBJECT_ENTRY_AUTO(clsid, class) \
	__declspec(selectany) ATL::_ATL_OBJMAP_ENTRY __objMap_##class = \
                        {&clsid, class::UpdateRegistry, class::_ClassFactoryCreatorClass::CreateInstance, class::_CreatorClass::CreateInstance, NULL, 0, class::GetObjectDescription, class::GetCategoryMap, class::ObjectMain }; \
	extern "C" __declspec(allocate("ATL$__m")) __declspec(selectany) ATL::_ATL_OBJMAP_ENTRY* const __pobjMap_##class = &__objMap_##class; \
	OBJECT_ENTRY_PRAGMA(class)
#define OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO(clsid, class) \
	__declspec(selectany) ATL::_ATL_OBJMAP_ENTRY __objMap_##class =  {&clsid, class::UpdateRegistry, NULL, NULL, NULL, 0, NULL, class::GetCategoryMap, class::ObjectMain }; \
	extern "C" __declspec(allocate("ATL$__m")) __declspec(selectany) ATL::_ATL_OBJMAP_ENTRY* const __pobjMap_##class = &__objMap_##class; \
	OBJECT_ENTRY_PRAGMA(class)
#define BEGIN_SINK_MAP(_class)\
	typedef _class _GetSinkMapFinder;\
	static const ATL::_ATL_EVENT_ENTRY<_class>* _GetSinkMap()\
	{\
		typedef _class _atl_event_classtype;\
		static const ATL::_ATL_EVENT_ENTRY<_class> map[] = {
#define BEGIN_CONNECTION_POINT_MAP(x)\
	__if_not_exists(_atl_conn_classtype) \
	{ \
		typedef x _atl_conn_classtype;\
	} \
	static const ATL::_ATL_CONNMAP_ENTRY* GetConnMap(int* pnEntries) {\
	static const ATL::_ATL_CONNMAP_ENTRY _entries[] = {
#define BEGIN_ATTRCONNECTION_POINT_MAP(x)\
	__if_not_exists(_atl_conn_classtype) \
	{ \
		typedef x _atl_conn_classtype;\
	} \
	static const ATL::_ATL_CONNMAP_ENTRY* GetAttrConnMap(int* pnEntries) {\
	static const ATL::_ATL_CONNMAP_ENTRY _entries[] = {

// ds\security\passport\atlmfc\atldbcli.h
#define BEGIN_PARAM_MAP(x) \
	public: \
	typedef x _classtype; \
	typedef x _ParamClass; \
	static bool HasParameters() throw () { return true; } \
	static HRESULT _GetParamEntries(LPOLESTR* pColumnNames, \
									DBORDINAL* pColumns, \
									DBBINDING *pBinding, \
									BYTE* pBuffer = NULL, \
									bool bClearOnly = false) throw () \
	{ \
		ATLASSERT(pColumns != NULL); \
		DBPARAMIO eParamIO = DBPARAMIO_INPUT; \
		int nColumns = 0; \
		pBuffer;

// ds\security\passport\atlmfc\atlperf.h
#define DECLARE_PERF_OBJECT_EX(dwObjectId, namestring, helpstring, detail, instanceless, structsize, maxinstnamelen, defcounter) \
		/* NOTE: put a semicolon after your call to DECLARE_PERF_OBJECT*(...) */ \
		/* this is needed for the code wizards to parse things properly */ \
		static const DWORD kObjectId = dwObjectId

// ds\security\passport\atlmfc\atlstencil.h
#define BEGIN_REPLACEMENT_METHOD_MAP(className)\
public:\
    void GetReplacementMethodMap(const ATL::CTagReplacerMethodEntry<className> ** ppOut) const throw()\
    {\
        typedef className __className;\
        static const ATL::CTagReplacerMethodEntry<className> methods[] = {
#define BEGIN_ATTR_REPLACEMENT_METHOD_MAP(className)\
public:\
    void GetAttrReplacementMethodMap(const CTagReplacerMethodEntry<className> ** ppOut) const throw()\
    {\
        typedef className __className;\
        static const ATL::CTagReplacerMethodEntry<className> methods[] = {

// ds\security\passport\atlmfc\bmio.h
#define IIRGBTarget_GetPaletteUsage(This,piFirstAvailableColor,pnAvailableColors,piFirstWritableColor,pnWritableColors,__MIDL_0011)	\
    (This)->lpVtbl -> GetPaletteUsage(This,piFirstAvailableColor,pnAvailableColors,piFirstWritableColor,pnWritableColors,__MIDL_0011)
#define IBitmapTarget_OnProgress(This,pBits,nPitch,prcBounds,bComplete)	\
    (This)->lpVtbl -> OnProgress(This,pBits,nPitch,prcBounds,bComplete)
#define IAnimatedBitmapTarget_OnProgress(This,pBits,nPitch,prcBounds,bComplete)	\
    (This)->lpVtbl -> OnProgress(This,pBits,nPitch,prcBounds,bComplete)
#define IColorQuantizer_SetCustomPalette(This,ppePalette,iFirstEntry,nEntries)	\
    (This)->lpVtbl -> SetCustomPalette(This,ppePalette,iFirstEntry,nEntries)

// ds\security\passport\atlmfc\msxml2.h
#define IXMLDOMDocument_createProcessingInstruction(This,target,data,pi)	\
    (This)->lpVtbl -> createProcessingInstruction(This,target,data,pi)
#define IXMLDOMDocument2_createProcessingInstruction(This,target,data,pi)	\
    (This)->lpVtbl -> createProcessingInstruction(This,target,data,pi)
#define IXMLDOMProcessingInstruction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IXMLDOMProcessingInstruction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IXMLDOMProcessingInstruction_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IXMLDOMProcessingInstruction_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IXMLDOMProcessingInstruction_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IXMLDOMProcessingInstruction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IXMLDOMProcessingInstruction_get_nodeName(This,name)	\
    (This)->lpVtbl -> get_nodeName(This,name)
#define IXMLDOMProcessingInstruction_get_nodeValue(This,value)	\
    (This)->lpVtbl -> get_nodeValue(This,value)
#define IXMLDOMProcessingInstruction_put_nodeValue(This,value)	\
    (This)->lpVtbl -> put_nodeValue(This,value)
#define IXMLDOMProcessingInstruction_get_nodeType(This,type)	\
    (This)->lpVtbl -> get_nodeType(This,type)
#define IXMLDOMProcessingInstruction_get_parentNode(This,parent)	\
    (This)->lpVtbl -> get_parentNode(This,parent)
#define IXMLDOMProcessingInstruction_get_firstChild(This,firstChild)	\
    (This)->lpVtbl -> get_firstChild(This,firstChild)
#define IXMLDOMProcessingInstruction_get_lastChild(This,lastChild)	\
    (This)->lpVtbl -> get_lastChild(This,lastChild)
#define IXMLDOMProcessingInstruction_get_attributes(This,attributeMap)	\
    (This)->lpVtbl -> get_attributes(This,attributeMap)
#define IXMLDOMProcessingInstruction_insertBefore(This,newChild,refChild,outNewChild)	\
    (This)->lpVtbl -> insertBefore(This,newChild,refChild,outNewChild)
#define IXMLDOMProcessingInstruction_replaceChild(This,newChild,oldChild,outOldChild)	\
    (This)->lpVtbl -> replaceChild(This,newChild,oldChild,outOldChild)
#define IXMLDOMProcessingInstruction_removeChild(This,childNode,oldChild)	\
    (This)->lpVtbl -> removeChild(This,childNode,oldChild)
#define IXMLDOMProcessingInstruction_appendChild(This,newChild,outNewChild)	\
    (This)->lpVtbl -> appendChild(This,newChild,outNewChild)
#define IXMLDOMProcessingInstruction_hasChildNodes(This,hasChild)	\
    (This)->lpVtbl -> hasChildNodes(This,hasChild)
#define IXMLDOMProcessingInstruction_get_ownerDocument(This,DOMDocument)	\
    (This)->lpVtbl -> get_ownerDocument(This,DOMDocument)
#define IXMLDOMProcessingInstruction_cloneNode(This,deep,cloneRoot)	\
    (This)->lpVtbl -> cloneNode(This,deep,cloneRoot)
#define IXMLDOMProcessingInstruction_get_nodeTypeString(This,nodeType)	\
    (This)->lpVtbl -> get_nodeTypeString(This,nodeType)
#define IXMLDOMProcessingInstruction_get_text(This,text)	\
    (This)->lpVtbl -> get_text(This,text)
#define IXMLDOMProcessingInstruction_put_text(This,text)	\
    (This)->lpVtbl -> put_text(This,text)
#define IXMLDOMProcessingInstruction_get_specified(This,isSpecified)	\
    (This)->lpVtbl -> get_specified(This,isSpecified)
#define IXMLDOMProcessingInstruction_get_definition(This,definitionNode)	\
    (This)->lpVtbl -> get_definition(This,definitionNode)
#define IXMLDOMProcessingInstruction_get_nodeTypedValue(This,typedValue)	\
    (This)->lpVtbl -> get_nodeTypedValue(This,typedValue)
#define IXMLDOMProcessingInstruction_put_nodeTypedValue(This,typedValue)	\
    (This)->lpVtbl -> put_nodeTypedValue(This,typedValue)
#define IXMLDOMProcessingInstruction_get_dataType(This,dataTypeName)	\
    (This)->lpVtbl -> get_dataType(This,dataTypeName)
#define IXMLDOMProcessingInstruction_put_dataType(This,dataTypeName)	\
    (This)->lpVtbl -> put_dataType(This,dataTypeName)
#define IXMLDOMProcessingInstruction_get_xml(This,xmlString)	\
    (This)->lpVtbl -> get_xml(This,xmlString)
#define IXMLDOMProcessingInstruction_transformNode(This,stylesheet,xmlString)	\
    (This)->lpVtbl -> transformNode(This,stylesheet,xmlString)
#define IXMLDOMProcessingInstruction_selectSingleNode(This,queryString,resultNode)	\
    (This)->lpVtbl -> selectSingleNode(This,queryString,resultNode)
#define IXMLDOMProcessingInstruction_get_parsed(This,isParsed)	\
    (This)->lpVtbl -> get_parsed(This,isParsed)
#define IXMLDOMProcessingInstruction_get_namespaceURI(This,namespaceURI)	\
    (This)->lpVtbl -> get_namespaceURI(This,namespaceURI)
#define IXMLDOMProcessingInstruction_get_prefix(This,prefixString)	\
    (This)->lpVtbl -> get_prefix(This,prefixString)
#define IXMLDOMProcessingInstruction_transformNodeToObject(This,stylesheet,outputObject)	\
    (This)->lpVtbl -> transformNodeToObject(This,stylesheet,outputObject)
#define IXMLDOMProcessingInstruction_get_target(This,name)	\
    (This)->lpVtbl -> get_target(This,name)
#define IXMLDOMProcessingInstruction_get_data(This,value)	\
    (This)->lpVtbl -> get_data(This,value)
#define IXMLDOMProcessingInstruction_put_data(This,value)	\
    (This)->lpVtbl -> put_data(This,value)
#define ISAXContentHandler_processingInstruction(This,pwchTarget,cchTarget,pwchData,cchData)	\
    (This)->lpVtbl -> processingInstruction(This,pwchTarget,cchTarget,pwchData,cchData)
#define IVBSAXContentHandler_processingInstruction(This,strTarget,strData)	\
    (This)->lpVtbl -> processingInstruction(This,strTarget,strData)

// ds\security\passport\common\lkrhash\lkhash.cpp
# define DECLARE_ALLOCATOR_LHTSUBCLASS(CLASS)            \
  CAllocator* CLKLinearHashTable::CLASS::sm_palloc = NULL; \

// ds\security\passport\common\lkrhash\lkrhash.cpp
# define DECLARE_ALLOCATOR_LHTSUBCLASS(CLASS)            \
  CLKRhashAllocator* CLKRLinearHashTable::CLASS::sm_palloc = NULL; \

// ds\security\passport\include\vc6\msdasql.h
#define ISQLRequestDiagFields_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISQLRequestDiagFields_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISQLRequestDiagFields_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISQLRequestDiagFields_RequestDiagFields(This,cDiagFields,rgDiagFields)	\
    (This)->lpVtbl -> RequestDiagFields(This,cDiagFields,rgDiagFields)
#define ISQLGetDiagField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISQLGetDiagField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISQLGetDiagField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISQLGetDiagField_GetDiagField(This,pDiagInfo)	\
    (This)->lpVtbl -> GetDiagField(This,pDiagInfo)

// enduser\mapistub\mapistub\mapiperf.h
#define MAPISetBufferNameFn(pv) \
	(!(pv) || !(*((ULONG *)(pv) - 2) & 0x40000000)) ? 0 : \
		(**((int (__cdecl ***)(void *, ...))((ULONG *)(pv) - 3))) \
			((void *)*((ULONG *)pv - 3), (ULONG *)pv - 4,

// enduser\netmeeting\as\h\ba.h
#define BA_FST_START_READING    &g_asSharedMemory->baFast[\
            1 - g_asSharedMemory->fastPath.newBuffer]
#define BA_FST_START_WRITING    &g_asSharedMemory->baFast[\
            1 - g_asSharedMemory->fastPath.newBuffer]

// enduser\netmeeting\as\h\cm.h
#define CM_SHM_START_READING  &g_asSharedMemory->cmFast[\
                   1 - g_asSharedMemory->fastPath.newBuffer]

// enduser\netmeeting\as\h\oa.h
#define OA_FST_START_READING    &g_asSharedMemory->oaFast[\
        1 - g_asSharedMemory->fastPath.newBuffer]
#define OA_FST_START_WRITING    &g_asSharedMemory->oaFast[\
        1 - g_asSharedMemory->fastPath.newBuffer]

// enduser\netmeeting\av\codecs\dec\dech261\slib.h
#define slibInSyncMode(Info) (Info->Fd<0 && Info->SlibCB==NULL)

// enduser\netmeeting\av\codecs\dec\dech263\slib.h
#define slibInSyncMode(Info) (Info->Fd<0 && Info->SlibCB==NULL)

// enduser\netmeeting\h\icounter.h
#define IReport_CreateEntry(This,szName,dwIndex)	\
    (This)->lpVtbl -> CreateEntry(This,szName,dwIndex)

// enduser\netmeeting\h\memtrack.h
#define MemReAlloc(pObj, cbSize)    LocalReAlloc((pObj), (cbSize), LMEM_MOVEABLE | LMEM_ZEROINIT)

// enduser\netmeeting\h\nmappletimpl.h
#define DECLARE_NMAPPLET_FILE_OPEN_FILTER(idStringResourceFilter, idStringResourceExt) \
    static HRESULT _GetNmAppletFileOpenFilter( LPTSTR szFilter, int cchMaxFilter, LPTSTR szExtension, int cchMaxExtension )\
    {	HRESULT hr = S_OK;\
		DBGENTRY(_GetNmAppletFileOpenFilter);\
		if( SUCCEEDED( hr = NmCtlLoadString( idStringResourceFilter, szFilter, cchMaxFilter ) ) )\
		{\
			hr = NmCtlLoadString( idStringResourceExt, szExtension, cchMaxExtension );\
		}\
		DBGEXIT_HR(_GetNmAppletFileOpenFilter,hr);\
        return hr;\
    }

// enduser\netmeeting\ui\conf\wizard.cpp
	#define ULSCONF_F_IDFIELDS (ULSCONF_F_FIRST_NAME|ULSCONF_F_LAST_NAME|\
					ULSCONF_F_EMAIL_NAME)

// enduser\netmeeting\ui\nmctl1\nmchatctl.h
#define DECLARE_NMAPPLET_FILE_OPEN_FILTER(idStringResourceFilter, idStringResourceExt) \
static HRESULT _GetNmAppletFileOpenFilter( LPTSTR szFilter, int cchMaxFilter, LPTSTR szExtension, int cchMaxExtension )\
{	HRESULT hr = S_OK;\
	DBGENTRY(_GetNmAppletFileOpenFilter);\
	if( SUCCEEDED( hr = NmCtlLoadString( idStringResourceFilter, szFilter, cchMaxFilter ) ) )\
	{\
		hr = NmCtlLoadString( idStringResourceExt, szExtension, cchMaxExtension );\
	}\
	DBGEXIT_HR(_GetNmAppletFileOpenFilter,hr);\
    return hr;\
}

// enduser\speech\external\include\tapi3.h
#define ITAllocatorProperties_SetAllocateBuffers(This,bAllocBuffers)	\
    (This)->lpVtbl -> SetAllocateBuffers(This,bAllocBuffers)
#define ITAllocatorProperties_GetAllocateBuffers(This,pbAllocBuffers)	\
    (This)->lpVtbl -> GetAllocateBuffers(This,pbAllocBuffers)
#define ITAllocatorProperties_SetBufferSize(This,BufferSize)	\
    (This)->lpVtbl -> SetBufferSize(This,BufferSize)
#define ITAllocatorProperties_GetBufferSize(This,pBufferSize)	\
    (This)->lpVtbl -> GetBufferSize(This,pBufferSize)
#define ITMSPAddress_ReceiveTSPData(This,pMSPCall,pBuffer,dwSize)	\
    (This)->lpVtbl -> ReceiveTSPData(This,pMSPCall,pBuffer,dwSize)
#define ITMSPAddress_GetEvent(This,pdwSize,pEventBuffer)	\
    (This)->lpVtbl -> GetEvent(This,pdwSize,pEventBuffer)

// enduser\speech\external\include\tapi3if.h
#define ITCallInfo_get_CallInfoBuffer(This,CallInfoBuffer,ppCallInfoBuffer)	\
    (This)->lpVtbl -> get_CallInfoBuffer(This,CallInfoBuffer,ppCallInfoBuffer)
#define ITCallInfo_put_CallInfoBuffer(This,CallInfoBuffer,pCallInfoBuffer)	\
    (This)->lpVtbl -> put_CallInfoBuffer(This,CallInfoBuffer,pCallInfoBuffer)
#define ITCallInfo_GetCallInfoBuffer(This,CallInfoBuffer,pdwSize,ppCallInfoBuffer)	\
    (This)->lpVtbl -> GetCallInfoBuffer(This,CallInfoBuffer,pdwSize,ppCallInfoBuffer)
#define ITCallInfo_SetCallInfoBuffer(This,CallInfoBuffer,dwSize,pCallInfoBuffer)	\
    (This)->lpVtbl -> SetCallInfoBuffer(This,CallInfoBuffer,dwSize,pCallInfoBuffer)
#define ITPrivateData_SendPrivateData(This,pObject,ObjectType,pBuffer,dwSize)	\
    (This)->lpVtbl -> SendPrivateData(This,pObject,ObjectType,pBuffer,dwSize)
#define ITPrivateReceiveData_ReceivePrivateData(This,pPrivateObject,ObjectType,pBuffer,dwSize)	\
    (This)->lpVtbl -> ReceivePrivateData(This,pPrivateObject,ObjectType,pBuffer,dwSize)

// enduser\speech\sapi\sapi\xmlparser.h
#define IXMLNodeSource_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLNodeSource_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLParser_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_PushData(This,pData,ulChars,fLastBuffer)	\
    (This)->lpVtbl -> PushData(This,pData,ulChars,fLastBuffer)

// enduser\speech\src\lexicon\lexapi\lexapi.h
#define ILxSynchWithLexicon_GetAppLexicon(This,Lcid,AppId,pWordSynchBuffer)	\
    (This)->lpVtbl -> GetAppLexicon(This,Lcid,AppId,pWordSynchBuffer)
#define ILxSynchWithLexicon_GetChangedUserWords(This,Lcid,dwAddGenerationId,dwDelGenerationId,dwNewAddGenerationId,dwNewDelGenerationId,pWordSynchBuffer)	\
    (This)->lpVtbl -> GetChangedUserWords(This,Lcid,dwAddGenerationId,dwDelGenerationId,dwNewAddGenerationId,dwNewDelGenerationId,pWordSynchBuffer)

// enduser\speech\tts\tools\usearch\usearch.cpp
#define SYNTAX fprintf(stderr,\
 "Usage:\nusearch [-f f0wght] [-d durwght] [-r rmswght] [-l lklwght] [-c contwght]\n\
 \t[-m SameSegWght] [-s (dynsearch)] [-b (blend)] [-g (gain)] \n\
 \t[-t (targetF0)] [-x cros_ref] [-S script_file] table_file \n\
 \t[ifile] [ofile]\n")

// enduser\stuff\hhctrl\mshtmhst.h
#define IDocHostUIHandler_ResizeBorder(This,prcBorder,pUIWindow,fRameWindow)	\
    (This)->lpVtbl -> ResizeBorder(This,prcBorder,pUIWindow,fRameWindow)

// enduser\stuff\itss\lzx\decoder\ring16.h
#define     BUFFER_SIZE     (512)  /* must be 2^Nth */

// enduser\stuff\itss\urlmki.h
#define IWinInetInfo_QueryOption(This,dwOption,pBuffer,pcbBuf)	\
    (This)->lpVtbl -> QueryOption(This,dwOption,pBuffer,pcbBuf)
#define IWinInetHttpInfo_QueryOption(This,dwOption,pBuffer,pcbBuf)	\
    (This)->lpVtbl -> QueryOption(This,dwOption,pBuffer,pcbBuf)
#define IWinInetHttpInfo_QueryInfo(This,dwOption,pBuffer,pcbBuf,pdwFlags,pdwReserved)	\
    (This)->lpVtbl -> QueryInfo(This,dwOption,pBuffer,pcbBuf,pdwFlags,pdwReserved)
#define IOInetBindClient_GetClassFileOrMime(This,pBC,szFilename,pBuffer,cbSize,szMime,dwReserved,pclsid)	\
    (This)->lpVtbl -> GetClassFileOrMime(This,pBC,szFilename,pBuffer,cbSize,szMime,dwReserved,pclsid)
#define IOInetBindClient_FindMimeFromData(This,pBC,szFilename,pBuffer,cbSize,szMime,dwReserved,pwzNewMime)	\
    (This)->lpVtbl -> FindMimeFromData(This,pBC,szFilename,pBuffer,cbSize,szMime,dwReserved,pwzNewMime)
#define IOInetProtocol_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define IOInetSession_SetSessionOption(This,dwOption,pBuffer,dwBufferLength,dwReserved)	\
    (This)->lpVtbl -> SetSessionOption(This,dwOption,pBuffer,dwBufferLength,dwReserved)
#define IOInetSession_GetSessionOption(This,dwOption,pBuffer,pdwBufferLength,dwReserved)	\
    (This)->lpVtbl -> GetSessionOption(This,dwOption,pBuffer,pdwBufferLength,dwReserved)
#define IOInetParse_CanonicalizeUrl(This,pwzUrl,ppwzBuffer,dwFlags)	\
    (This)->lpVtbl -> CanonicalizeUrl(This,pwzUrl,ppwzBuffer,dwFlags)

// enduser\troubleshoot\msinfo\wbemcli.h
#define IWbemObjectAccess_ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,pData)	\
    (This)->lpVtbl -> ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,pData)

// enduser\windows.com\inc\asptlb.h
#define IRequest_get_TotalBytes(This,pcbTotal)	\
    (This)->lpVtbl -> get_TotalBytes(This,pcbTotal)
#define IResponse_get_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> get_Buffer(This,fIsBuffering)
#define IResponse_put_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> put_Buffer(This,fIsBuffering)
#define IResponse_AppendToLog(This,bstrLogEntry)	\
    (This)->lpVtbl -> AppendToLog(This,bstrLogEntry)

// inetcore\connectionwizard\inc\icwhelp.h
#define IWebGate_get_Buffer(This,pVal)	\
    (This)->lpVtbl -> get_Buffer(This,pVal)
#define IWebGate_DumpBufferToFile(This,pFileName,pbRetVal)	\
    (This)->lpVtbl -> DumpBufferToFile(This,pFileName,pbRetVal)

// inetcore\connectionwizard\inc\ocdb.h
#define ICursor_SetBindings(pI, cCol, rgBoundColumns, cbRowLength, dwFlags) \
    (*(pI)->lpVtbl->SetBindings)((pI), cCol, rgBoundColumns, cbRowLength, dwFlags)
#define ICursor_GetBindings(pI, pcCol, prgBoundColumns, pcbRowLength) \
    (*(pI)->lpVtbl->GetBindings)((pI), pcCol, prgBoundColumns, pcbRowLength)
#define ICursorMove_SetBindings(pI, cCol, rgBoundColumns, cbRowLength, dwFlags) \
    (*(pI)->lpVtbl->SetBindings)((pI), cCol, rgBoundColumns, cbRowLength, dwFlags)
#define ICursorMove_GetBindings(pI, pcCol, prgBoundColumns, pcbRowLength) \
    (*(pI)->lpVtbl->GetBindings)((pI), pcCol, prgBoundColumns, pcbRowLength)
#define ICursorMove_GetBookmark(pI, pBookmarkType, cbMaxSize, pcbBookmark, pBookmark) \
    (*(pI)->lpVtbl->GetBookmark)((pI), pBookmarkType, cbMaxSize, pcbBookmark, pBookmark)
#define ICursorScroll_SetBindings(pI, cCol, rgBoundColumns, cbRowLength, dwFlags) \
    (*(pI)->lpVtbl->SetBindings)((pI), cCol, rgBoundColumns, cbRowLength, dwFlags)
#define ICursorScroll_GetBindings(pI, pcCol, prgBoundColumns, pcbRowLength) \
    (*(pI)->lpVtbl->GetBindings)((pI), pcCol, prgBoundColumns, pcbRowLength)
#define ICursorScroll_GetBookmark(pI, pBookmarkType, cbMaxSize, pcbBookmark, pBookmark) \
    (*(pI)->lpVtbl->GetBookmark)((pI), pBookmarkType, cbMaxSize, pcbBookmark, pBookmark)
#define ICursorScroll_GetApproximatePosition(pI, cbBookmark, pBookmark, pulNumerator, pulDenominator) \
    (*(pI)->lpVtbl->GetApproximatePosition)((pI), cbBookmark, pBookmark, pulNumerator, pulDenominator)
#define ICursorUpdateARow_Update(pI, pBookmarkType, pcbBookmark, ppBookmark) \
    (*(pI)->lpVtbl->Update)((pI), pBookmarkType, pcbBookmark, ppBookmark)
#define ICursorFind_FindByValues(pI, cbB, pB, dwFF, cV, rgC, rgV, rgSF, pF) \
    (*(pI)->lpVtbl->FindByValues)((pI), cbB, pB, dwFF, cB, rgC, rgV, rgSF, pF)
#define IEntryID_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define IEntryID_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define IEntryID_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define IEntryID_GetInterface(pI, cbEntryID, pEntryID, riid, ppvObj) \
    (*(pI)->lpVtbl->GetInterface)((pI), cbEntryID, pEntryID, riid, ppvObj)
#define INotifyDBEvents_SyncBefore(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->SyncBefore)((pI), dwEventWhat, cReasons, rgReasons)

// inetcore\connectionwizard\inetcfg\imnact.h
#define IImnAccount_GetProp(This,dwPropTag,pb,pcb)	\
    (This)->lpVtbl -> GetProp(This,dwPropTag,pb,pcb)
#define IImnAccount_SetProp(This,dwPropTag,pb,cb)	\
    (This)->lpVtbl -> SetProp(This,dwPropTag,pb,cb)
#define IImnAccount_ValidateProperty(This,dwPropTag,pb,cb)	\
    (This)->lpVtbl -> ValidateProperty(This,dwPropTag,pb,cb)

// inetcore\datacab\viaduct\msr2c\msdadc.h
#define IDataConvert_DataConvert(This,wSrcType,wDstType,cbSrcLength,pcbDstLength,pSrc,pDst,cbDstMaxLength,dbsSrcStatus,pdbsStatus,bPrecision,bScale,dwFlags)	\
    (This)->lpVtbl -> DataConvert(This,wSrcType,wDstType,cbSrcLength,pcbDstLength,pSrc,pDst,cbDstMaxLength,dbsSrcStatus,pdbsStatus,bPrecision,bScale,dwFlags)
#define IDataConvert_GetConversionSize(This,wSrcType,wDstType,pcbSrcLength,pcbDstLength,pSrc)	\
    (This)->lpVtbl -> GetConversionSize(This,wSrcType,wDstType,pcbSrcLength,pcbDstLength,pSrc)

// inetcore\datacab\viaduct\msr2c\ocdb.h
#define ICursor_SetBindings(pI, cCol, rgBoundColumns, cbRowLength, dwFlags) \
    (*(pI)->lpVtbl->SetBindings)((pI), cCol, rgBoundColumns, cbRowLength, dwFlags)
#define ICursor_GetBindings(pI, pcCol, prgBoundColumns, pcbRowLength) \
    (*(pI)->lpVtbl->GetBindings)((pI), pcCol, prgBoundColumns, pcbRowLength)
#define ICursorMove_SetBindings(pI, cCol, rgBoundColumns, cbRowLength, dwFlags) \
    (*(pI)->lpVtbl->SetBindings)((pI), cCol, rgBoundColumns, cbRowLength, dwFlags)
#define ICursorMove_GetBindings(pI, pcCol, prgBoundColumns, pcbRowLength) \
    (*(pI)->lpVtbl->GetBindings)((pI), pcCol, prgBoundColumns, pcbRowLength)
#define ICursorMove_GetBookmark(pI, pBookmarkType, cbMaxSize, pcbBookmark, pBookmark) \
    (*(pI)->lpVtbl->GetBookmark)((pI), pBookmarkType, cbMaxSize, pcbBookmark, pBookmark)
#define ICursorScroll_SetBindings(pI, cCol, rgBoundColumns, cbRowLength, dwFlags) \
    (*(pI)->lpVtbl->SetBindings)((pI), cCol, rgBoundColumns, cbRowLength, dwFlags)
#define ICursorScroll_GetBindings(pI, pcCol, prgBoundColumns, pcbRowLength) \
    (*(pI)->lpVtbl->GetBindings)((pI), pcCol, prgBoundColumns, pcbRowLength)
#define ICursorScroll_GetBookmark(pI, pBookmarkType, cbMaxSize, pcbBookmark, pBookmark) \
    (*(pI)->lpVtbl->GetBookmark)((pI), pBookmarkType, cbMaxSize, pcbBookmark, pBookmark)
#define ICursorScroll_GetApproximatePosition(pI, cbBookmark, pBookmark, pulNumerator, pulDenominator) \
    (*(pI)->lpVtbl->GetApproximatePosition)((pI), cbBookmark, pBookmark, pulNumerator, pulDenominator)
#define ICursorUpdateARow_Update(pI, pBookmarkType, pcbBookmark, ppBookmark) \
    (*(pI)->lpVtbl->Update)((pI), pBookmarkType, pcbBookmark, ppBookmark)
#define ICursorFind_FindByValues(pI, cbB, pB, dwFF, cV, rgC, rgV, rgSF, pF) \
    (*(pI)->lpVtbl->FindByValues)((pI), cbB, pB, dwFF, cB, rgC, rgV, rgSF, pF)
#define IEntryID_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define IEntryID_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define IEntryID_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define IEntryID_GetInterface(pI, cbEntryID, pEntryID, riid, ppvObj) \
    (*(pI)->lpVtbl->GetInterface)((pI), cbEntryID, pEntryID, riid, ppvObj)
#define INotifyDBEvents_SyncBefore(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->SyncBefore)((pI), dwEventWhat, cReasons, rgReasons)

// inetcore\digest\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// inetcore\mshtml\btools\tlviewer\cmallspy.cpp
#define MALLOC(CB)		GlobalLock(GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, CB))

// inetcore\mshtml\external\inc\vbcursor\ocdb.h
#define ICursor_SetBindings(pI, cCol, rgBoundColumns, cbRowLength, dwFlags) \
    (*(pI)->lpVtbl->SetBindings)((pI), cCol, rgBoundColumns, cbRowLength, dwFlags)
#define ICursor_GetBindings(pI, pcCol, prgBoundColumns, pcbRowLength) \
    (*(pI)->lpVtbl->GetBindings)((pI), pcCol, prgBoundColumns, pcbRowLength)
#define ICursorMove_SetBindings(pI, cCol, rgBoundColumns, cbRowLength, dwFlags) \
    (*(pI)->lpVtbl->SetBindings)((pI), cCol, rgBoundColumns, cbRowLength, dwFlags)
#define ICursorMove_GetBindings(pI, pcCol, prgBoundColumns, pcbRowLength) \
    (*(pI)->lpVtbl->GetBindings)((pI), pcCol, prgBoundColumns, pcbRowLength)
#define ICursorMove_GetBookmark(pI, pBookmarkType, cbMaxSize, pcbBookmark, pBookmark) \
    (*(pI)->lpVtbl->GetBookmark)((pI), pBookmarkType, cbMaxSize, pcbBookmark, pBookmark)
#define ICursorScroll_SetBindings(pI, cCol, rgBoundColumns, cbRowLength, dwFlags) \
    (*(pI)->lpVtbl->SetBindings)((pI), cCol, rgBoundColumns, cbRowLength, dwFlags)
#define ICursorScroll_GetBindings(pI, pcCol, prgBoundColumns, pcbRowLength) \
    (*(pI)->lpVtbl->GetBindings)((pI), pcCol, prgBoundColumns, pcbRowLength)
#define ICursorScroll_GetBookmark(pI, pBookmarkType, cbMaxSize, pcbBookmark, pBookmark) \
    (*(pI)->lpVtbl->GetBookmark)((pI), pBookmarkType, cbMaxSize, pcbBookmark, pBookmark)
#define ICursorScroll_GetApproximatePosition(pI, cbBookmark, pBookmark, pulNumerator, pulDenominator) \
    (*(pI)->lpVtbl->GetApproximatePosition)((pI), cbBookmark, pBookmark, pulNumerator, pulDenominator)
#define ICursorUpdateARow_Update(pI, pBookmarkType, pcbBookmark, ppBookmark) \
    (*(pI)->lpVtbl->Update)((pI), pBookmarkType, pcbBookmark, ppBookmark)
#define ICursorFind_FindByValues(pI, cbB, pB, dwFF, cV, rgC, rgV, rgSF, pF) \
    (*(pI)->lpVtbl->FindByValues)((pI), cbB, pB, dwFF, cB, rgC, rgV, rgSF, pF)
#define IEntryID_QueryInterface(pI, riid, ppvObject) \
    (*(pI)->lpVtbl->QueryInterface)((pI), riid, ppvObject)
#define IEntryID_AddRef(pI) \
    (*(pI)->lpVtbl->AddRef)((pI))
#define IEntryID_Release(pI) \
    (*(pI)->lpVtbl->Release)((pI))
#define IEntryID_GetInterface(pI, cbEntryID, pEntryID, riid, ppvObj) \
    (*(pI)->lpVtbl->GetInterface)((pI), cbEntryID, pEntryID, riid, ppvObj)
#define INotifyDBEvents_SyncBefore(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->SyncBefore)((pI), dwEventWhat, cReasons, rgReasons)

// inetcore\mshtml\imgfilt\atlcom.h
#define DECLARE_PROTECT_FINAL_CONSTRUCT()\
	void InternalFinalConstructAddRef() {InternalAddRef();}\
	void InternalFinalConstructRelease() {InternalRelease();}
#define DECLARE_NOT_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComCreator< CComObject<x> >, CComFailCreator<CLASS_E_NOAGGREGATION> > _CreatorClass;
#define DECLARE_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComCreator< CComObject<x> >, CComCreator< CComAggObject<x> > > _CreatorClass;
#define DECLARE_ONLY_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComFailCreator<E_FAIL>, CComCreator< CComAggObject<x> > > _CreatorClass;
#define COM_INTERFACE_ENTRY2(x, x2)\
	{&IID_##x,\
	(DWORD)((x*)(x2*)((_ComMapClass*)8))-8,\
	(_ATL_CREATORARGFUNC*)1},
#define COM_INTERFACE_ENTRY2_IID(iid, x, x2)\
	{&iid,\
	(DWORD)((x*)(x2*)((_ComMapClass*)8))-8,\
	(_ATL_CREATORARGFUNC*)1},
#define COM_INTERFACE_ENTRY_FUNC(iid, dw, func)\
	{&iid, \
	dw, \
	func},
#define COM_INTERFACE_ENTRY_TEAR_OFF(iid, x)\
	{&iid,\
	(DWORD)&_CComCreatorData<\
		CComCreator<CComTearOffObject<x, _ComMapClass> >\
		>::data,\
	_Creator},
#define COM_INTERFACE_ENTRY_CHAIN(classname)\
	{NULL,\
	(DWORD)&_CComChainData<classname, _ComMapClass>::data,\
	_Chain},
#define OBJECT_ENTRY(clsid, class) {&clsid, &class::UpdateRegistry, &class::_ClassFactoryCreatorClass::CreateInstance, &class::_CreatorClass::CreateInstance, NULL, 0},
#define BEGIN_CONNECTION_POINT_MAP(x)\
	typedef x _atl_conn_classtype;\
	virtual const _ATL_CONNMAP_ENTRY* GetConnMap()\
		{ return _StaticGetConnMap(); }\
	static const _ATL_CONNMAP_ENTRY* _StaticGetConnMap() {\
	static const _ATL_CONNMAP_ENTRY _entries[] = {

// inetcore\mshtml\src\core\include\cdutil.hxx
#define DECLARE_FORMS_STANDARD_IUNKNOWN(cls)                        \
    STDMETHOD(QueryInterface) (REFIID riid, LPVOID * ppv);          \
    ULONG _ulRefs;                                                  \
    STDMETHOD_(ULONG, AddRef) (void)                                \
        {                                                           \
            return ++_ulRefs;                                       \
        }                                                           \
    STDMETHOD_(ULONG, Release) (void)                               \
        {                                                           \
            if (--_ulRefs == 0)                                     \
            {                                                       \
                _ulRefs = ULREF_IN_DESTRUCTOR;                      \
                delete this;                                        \
                return 0;                                           \
            }                                                       \
            return _ulRefs;                                         \
        }                                                           \
    ULONG GetRefs(void)                                             \
        { return _ulRefs; }

// inetcore\mshtml\src\core\include\unixtoff.hxx
#define BEGIN_TEAROFF_TABLE(klass, itf)                                                 \
    klass::PFNTEAROFF const klass::s_apfn##itf[] = {                                    \
            TEAROFF_METHOD_NULL                                                         \
            TEAROFF_METHOD(klass, PrivateQueryInterface, win16, (REFIID, void **))      \
            TEAROFF_METHOD_(klass, PrivateAddRef, win16, ULONG, ())                     \
            TEAROFF_METHOD_(klass, PrivateRelease, win16, ULONG, ())
#define BEGIN_TEAROFF_TABLE_PROPDESC(klass, itf)\
    klass::PFNTEAROFF const klass::s_apfnpd##itf[] = {\
            TEAROFF_METHOD_NULL\
            TEAROFF_METHOD(klass, PrivateQueryInterface, win16, (REFIID, void **))\
            TEAROFF_METHOD_(klass, PrivateAddRef, win16, ULONG, ())\
            TEAROFF_METHOD_(klass, PrivateRelease, win16, ULONG, ())\
#define BEGIN_TEAROFF_TABLE_(klass, itf)                                        \
    klass::PFNTEAROFF const klass::s_apfn##itf[] = {                            \
            TEAROFF_METHOD_NULL                                                 \
            TEAROFF_METHOD(klass, QueryInterface, win16, (REFIID, void **))     \
            TEAROFF_METHOD_(klass, AddRef, win16, ULONG, ())                    \
            TEAROFF_METHOD_(klass, Release, win16, ULONG, ())
#define BEGIN_TEAROFF_TABLE_SUB_(klass, subklass, itf)                                        \
    klass::subklass::PFNTEAROFF const klass::subklass::s_apfn##itf[] = {                            \
            TEAROFF_METHOD_NULL                                                 \
            TEAROFF_METHOD(klass::subklass, klass::subklass::QueryInterface, win16, (REFIID, void **))     \
            TEAROFF_METHOD_(klass::subklass, klass::subklass::AddRef, win16, ULONG, ())                    \
            TEAROFF_METHOD_(klass::subklass, klass::subklass::Release, win16, ULONG, ())
#define BEGIN_TEAROFF_TABLE_NAMED(klass, name)                  \
    klass::PFNTEAROFF const klass::name[] = {                   \
            TEAROFF_METHOD_NULL

// inetcore\mshtml\src\core\include\wintoff.hxx
#define DECLARE_TEAROFF_TABLE(itf)\
    static HRESULT (STDMETHODCALLTYPE CVoid::*const s_apfn##itf[])(void);
#define DECLARE_TEAROFF_TABLE_PROPDESC(itf)\
    static HRESULT (STDMETHODCALLTYPE CVoid::*const s_apfnpd##itf[])(void);
#define DECLARE_TEAROFF_TABLE_NAMED(apfname)\
    static HRESULT (STDMETHODCALLTYPE CVoid::*const apfname[])(void);
#define BEGIN_TEAROFF_TABLE(klass, itf)\
    HRESULT (STDMETHODCALLTYPE  CVoid::*const klass::s_apfn##itf[])(void) = {\
    TEAROFF_METHOD(klass, PrivateQueryInterface, privatequeryinterface, (REFIID, void **))\
    TEAROFF_METHOD_(klass, PrivateAddRef, privateaddref, ULONG, ())\
    TEAROFF_METHOD_(klass, PrivateRelease, privaterelease, ULONG, ())\
#define BEGIN_TEAROFF_TABLE_PROPDESC(klass, itf)\
    HRESULT (STDMETHODCALLTYPE  CVoid::*const klass::s_apfnpd##itf[])(void) = {\
    TEAROFF_METHOD(klass, PrivateQueryInterface, privatequeryinterface, (REFIID, void **))\
    TEAROFF_METHOD_(klass, PrivateAddRef, privateaddref, ULONG, ())\
    TEAROFF_METHOD_(klass, PrivateRelease, privaterelease, ULONG, ())\
#define BEGIN_TEAROFF_TABLE_(klass, itf)\
    HRESULT (STDMETHODCALLTYPE  CVoid::*const klass::s_apfn##itf[])(void) = {\
    TEAROFF_METHOD(klass, QueryInterface, queryinterface, (REFIID, void **))\
    TEAROFF_METHOD_(klass, AddRef, addref, ULONG, ())\
    TEAROFF_METHOD_(klass, Release, release, ULONG, ())\
#define BEGIN_TEAROFF_TABLE_SUB_(klass, subklass, itf)\
    HRESULT (STDMETHODCALLTYPE  CVoid::*const klass::subklass::s_apfn##itf[])(void) = {\
    TEAROFF_METHOD (klass::subklass, klass::subklass::QueryInterface, klass::subklass::queryinterface, (REFIID, void **))\
    TEAROFF_METHOD_(klass::subklass, klass::subklass::AddRef, klass::subklass::addref, ULONG, ())\
    TEAROFF_METHOD_(klass::subklass, klass::subklass::Release, klass::subklass::release, ULONG, ())\
#define BEGIN_TEAROFF_TABLE_NAMED(klass, name)\
    HRESULT (STDMETHODCALLTYPE  CVoid::*const klass::name[])(void) = {\
#define DECLARE_TEAROFF_TABLE(itf)\
    static DEBUG_TEAROFF_METHOD<thisclass> s_apfn##itf[];\
    static int s_iDebugCheck##itf;\
    static DEBUG_TEAROFF_NOTE s_noteDebugCheck##itf;\
#define DECLARE_TEAROFF_TABLE_NAMED(name)\
    static DEBUG_TEAROFF_METHOD<thisclass> name[];\
    static int s_iDebugCheck##name;\
    static DEBUG_TEAROFF_NOTE s_noteDebugCheck##name;\
#define BEGIN_TEAROFF_TABLE(klass, itf)\
    DEBUG_TEAROFF_NOTE klass::s_noteDebugCheck##itf = { 0 };\
    int klass::s_iDebugCheck##itf = DeferDebugCheckTearoffTable(\
        &klass::s_noteDebugCheck##itf, klass::s_apfn##itf, "Multiple inheritance problem with tearoff " #itf " in " #klass);\
    DEBUG_TEAROFF_METHOD<klass> klass::s_apfn##itf[] = {\
    TEAROFF_METHOD(PrivateQueryInterface, (REFIID, void **))\
    TEAROFF_METHOD_(PrivateAddRef, ULONG, ())\
    TEAROFF_METHOD_(PrivateRelease, ULONG, ())\
#define BEGIN_TEAROFF_TABLE_(klass, itf)\
    DEBUG_TEAROFF_NOTE klass::s_noteDebugCheck##itf = { 0 };\
    int klass::s_iDebugCheck##itf = DeferDebugCheckTearoffTable(\
        &klass::s_noteDebugCheck##itf, klass::s_apfn##itf, "Multiple inheritance problem with tearoff " #itf " in " #klass);\
    DEBUG_TEAROFF_METHOD<klass> klass::s_apfn##itf[] = {\
    TEAROFF_METHOD(QueryInterface, (REFIID, void **))\
    TEAROFF_METHOD_(AddRef, ULONG, ())\
    TEAROFF_METHOD_(Release, ULONG, ())\
#define BEGIN_TEAROFF_TABLE_NAMED(klass, name)\
    DEBUG_TEAROFF_NOTE klass::s_noteDebugCheck##name = { 0 };\
    int klass::s_iDebugCheck##name = DeferDebugCheckTearoffTable(\
        &klass::s_noteDebugCheck##name, klass::name, "Multiple inheritance problem with tearoff " #name " in " #klass);\
    DEBUG_TEAROFF_METHOD<klass> klass::name[] = {\

// inetcore\mshtml\src\edit\iscsa.h
#define IInputSequenceChecker_CheckInputSequence(This,pCharBuffer,ichPosition,chEval,pfValue)	\
    (This)->lpVtbl -> CheckInputSequence(This,pCharBuffer,ichPosition,chEval,pfValue)
#define IInputSequenceChecker_CheckAndReplaceInputSequence(This,pCharBuffer,cchCharBuffer,ichPosition,chEval,cchBuffer,pOutBuffer,pchOutBuffer)	\
    (This)->lpVtbl -> CheckAndReplaceInputSequence(This,pCharBuffer,cchCharBuffer,ichPosition,chEval,cchBuffer,pOutBuffer,pchOutBuffer)

// inetcore\mshtml\src\f3\include\trirt.h
#define DECLARE_MEMALLOC_NEW_DELETE(mt) \
    inline void * __cdecl operator new(size_t cb) { return(MemAlloc(mt, cb)); } \
    inline void * __cdecl operator new[](size_t cb) { return(MemAlloc(mt, cb)); } \
    inline void __cdecl operator delete(void * pv) { MemFree(pv); }
#define DECLARE_MEMALLOC_NEW(mt) \
    inline void * __cdecl operator new(size_t cb) { return(MemAlloc(mt, cb)); } \
    inline void * __cdecl operator new[](size_t cb) { return(MemAlloc(mt, cb)); }
#define DECLARE_MEMCLEAR_NEW_DELETE(mt) \
    inline void * __cdecl operator new(size_t cb) { return(MemAllocClear(mt, cb)); } \
    inline void * __cdecl operator new[](size_t cb) { return(MemAllocClear(mt, cb)); } \
    inline void __cdecl operator delete(void * pv) { MemFree(pv); }
#define DECLARE_MEMALLOC_NEW_DELETE(mt) \
    void * __cdecl operator new(size_t cb) { return(MemAlloc(mt, cb)); } \
    void __cdecl operator delete(void * pv) { MemFree(pv); }
#define DECLARE_MEMALLOC_NEW(mt) \
    void * __cdecl operator new(size_t cb) { return(MemAlloc(mt, cb)); }
#define DECLARE_MEMCLEAR_NEW_DELETE(mt) \
    void * __cdecl operator new(size_t cb) { return(MemAllocClear(mt, cb)); } \
    void __cdecl operator delete(void * pv) { MemFree(pv); }

// inetcore\mshtml\src\intl\intlcore\unipart.hxx
#define WCB_ 10     //   9 - Close brackets for inline-note (JIS 2 or 20)

// inetcore\mshtml\src\site\display\pubprint.hxx
#define GhAllocLcbGrf(lcb, grf)         GlobalAlloc((grf) | GMEM_FIXED, lcb)

// inetcore\mshtml\src\site\include\cfpf.hxx
#define DECLARE_SPECIAL_OBJECT_FLAGS()                     \
    union                                                  \
    {                                                      \
        WORD _wSpecialObjectFlagsVar;                      \
        struct                                             \
        {                                                  \
            unsigned short _fIsRuby                 : 1;   \
            unsigned short _fIsRubyText             : 1;   \
            unsigned short _fBidiEmbed              : 1;   \
            unsigned short _fBidiOverride           : 1;   \
            unsigned short _fNoBreak                : 1;   \
            unsigned short _fNoBreakInner           : 1;   \
            unsigned short _uLayoutGridModeInner    : 3;   \
            unsigned short _uLayoutGridMode         : 3;   \
        /* Someone above me has borders or padding set. */ \
            unsigned short _fPadBord                : 1;   \
            unsigned short _fHasInlineMargins       : 1;   \
            unsigned short _fHasLetterOrWordSpacing : 1;   \
            unsigned short _fHasInlineBg            : 1;   \
        };                                                 \
    };                                                     \
    WORD _wSpecialObjectFlags() const { return _wSpecialObjectFlagsVar; }

// inetcore\mshtml\src\site\table\ltcell.cxx
    #define BorderOrientation(border) ((border == SIDE_LEFT || border == SIDE_TOP)?1:-1)
    #define TopLeft(border) (border == SIDE_LEFT || border == SIDE_TOP)
    #define TopRight(border) (border == SIDE_RIGHT || border == SIDE_TOP)

// inetcore\mshtml\src\site\table\ltdraw.cxx
#define TopLeft(border) (border == SIDE_LEFT || border == SIDE_TOP)
#define TopBottom(border) (border == SIDE_TOP || border == SIDE_BOTTOM)
#define LeftRight(border) (border == SIDE_LEFT || border == SIDE_RIGHT)
#define TopRight(border) (border == SIDE_TOP || border == SIDE_RIGHT)
#define LeftBottom(border) (border == SIDE_LEFT || border == SIDE_BOTTOM)
#define RightBottom(border) (border == SIDE_RIGHT || border == SIDE_BOTTOM)

// inetcore\mshtml\src\time\media\wmpcd.h
#define IWMPCDDevice_CreateReader(This,iTrack,rt,fl,iPriority,cmsBuffer,pCallback,ppReader)	\
    (This)->lpVtbl -> CreateReader(This,iTrack,rt,fl,iPriority,cmsBuffer,pCallback,ppReader)
#define IWMPCDMixer_GetRecordLevel(This,pdwLevel)	\
    (This)->lpVtbl -> GetRecordLevel(This,pdwLevel)
#define IWMPCDMixer_SetRecordLevel(This,dwLevel)	\
    (This)->lpVtbl -> SetRecordLevel(This,dwLevel)
#define IWMPCDMixer_SoloRecord(This,fSolo)	\
    (This)->lpVtbl -> SoloRecord(This,fSolo)
#define IWMPCDRecorder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IWMPCDRecorder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IWMPCDRecorder_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IWMPCDRecorder_StartRecording(This)	\
    (This)->lpVtbl -> StartRecording(This)
#define IWMPCDRecorder_PauseRecording(This)	\
    (This)->lpVtbl -> PauseRecording(This)
#define IWMPCDRecorder_ResumeRecording(This)	\
    (This)->lpVtbl -> ResumeRecording(This)
#define IWMPCDRecorder_StopRecording(This)	\
    (This)->lpVtbl -> StopRecording(This)
#define IWMPCDReaderCallback_OnReadSample(This,iTick,cTick,pBuffer)	\
    (This)->lpVtbl -> OnReadSample(This,iTick,cTick,pBuffer)
#define IWMPCDRecorderCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IWMPCDRecorderCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IWMPCDRecorderCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IWMPCDRecorderCallback_OnRecordStart(This,cTick)	\
    (This)->lpVtbl -> OnRecordStart(This,cTick)
#define IWMPCDRecorderCallback_OnRecordPause(This)	\
    (This)->lpVtbl -> OnRecordPause(This)
#define IWMPCDRecorderCallback_OnRecordResume(This)	\
    (This)->lpVtbl -> OnRecordResume(This)
#define IWMPCDRecorderCallback_OnRecordStop(This,hr)	\
    (This)->lpVtbl -> OnRecordStop(This,hr)
#define IWMPCDRecorderCallback_OnRecordProgress(This,iTick)	\
    (This)->lpVtbl -> OnRecordProgress(This,iTick)

// inetcore\mshtml\src\time\media\wmsbuffer.h
#define INSSBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer2_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer2_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer2_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer2_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer2_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_GetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> GetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer2_SetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> SetSampleProperties(This,cbProperties,pbProperties)
#define IWMSBufferAllocator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IWMSBufferAllocator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IWMSBufferAllocator_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IWMSBufferAllocator_AllocateBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocateBuffer(This,dwMaxBufferSize,ppBuffer)

// inetcore\outlookexpress\directdb\engine\types.h
#define DBTypeCompareRecords(_pColumn, _pKey, _pTag1, _pTag2, _pMap1, _pMap2) \
    (*(g_rgpfnDBTypeCompareRecords[(_pColumn)->type])) \
    ((_pColumn), _pKey, _pTag1, _pTag2, _pMap1, _pMap2)

// inetcore\outlookexpress\inc\athena16.h
#define CBEM_INSERTITEMA        (WM_USER + 1)
#define CBEM_GETITEMA           (WM_USER + 4)
#define CBEM_SETITEMA           (WM_USER + 5)
#define CBEM_GETCOMBOCONTROL    (WM_USER + 6)
#define CBEM_GETEDITCONTROL     (WM_USER + 7)
#define CBEM_SETEXSTYLE         (WM_USER + 8)
#define CBEM_GETEXSTYLE         (WM_USER + 9)
#define CBEM_HASEDITCHANGED     (WM_USER + 10)
#define CBEM_INSERTITEMW        (WM_USER + 11)
#define CBEM_SETITEMW           (WM_USER + 12)
#define CBEM_GETITEMW           (WM_USER + 13)

// inetcore\outlookexpress\inetcomm\mimeole\inetconv.h
#define FConvBuffCanRead(_rCon) \
    (_rCon.i < _rCon.cb)

// inetcore\outlookexpress\mailnews\shell\browser.cpp
#define CBM_POSTCREATE  (WM_USER + 4000)

// inetcore\outlookexpress\mailnews\shell\rundll.cpp
#define DAD_SERVERCB    (WM_USER + 100)

// inetcore\outlookexpress\mailnews\spooler\pop3task.cpp
#define ITEMFROMPOPID(_dwPopId) \
    (&m_rTable.prgItem[_dwPopId - 1])

// inetcore\outlookexpress\mailnews\spooler\smtptask.cpp
#define CURRENTSMTPEVENT(_rTable) (&_rTable.prgEvent[_rTable.iEvent])

// inetcore\outlookexpress\mailnews\store\msgtable.cpp
#define IsInitialized(_pThis) \
    (_pThis->m_pFolder && _pThis->m_pDB)

// inetcore\outlookexpress\wabw\test\wabtests\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// inetcore\outlookexpress\wabw\wabapi\_runt.h
#define CB_MDB_EID_HEADER(cb)	((CbNewMAPIMDB_ENTRYID(cb) + 3) & ~3)

// inetcore\outlookexpress\wabw\wabapi\entry.c
#define	PvGetInstanceGlobals()		PvGetInstanceGlobalsMac(kInstMAPIX)

// inetcore\outlookexpress\wabw\wabapi\mapiperf.h
#define MAPISetBufferNameFn(pv) \
	(!(pv) || !(*((ULONG *)(pv) - 2) & 0x40000000)) ? 0 : \
		(**((int (__cdecl ***)(void *, ...))((ULONG *)(pv) - 3))) \
			((void *)*((ULONG *)pv - 3), (ULONG *)pv - 4,

// inetcore\outlookexpress\wabw\wabapi\ntfy.c
#define FIsKeyOlaf(pkey) \
	(pkey->cb == ((LPNOTIFKEY) &notifkeyOlaf)->cb && \
	memcmp(pkey->ab, ((LPNOTIFKEY) &notifkeyOlaf)->ab, \
		(UINT) ((LPNOTIFKEY) &notifkeyOlaf)->cb) == 0)

// inetcore\published\inc\dxatlpb.h
#define COM_INTERFACE_ENTRY_DXIMPL(x)\
	COM_INTERFACE_ENTRY_IID(IID_##x, x##DXImpl<_ComMapClass>)

// inetcore\published\inc\iimgctx.h
#define IImgCtx_Draw(This, hdc, prcBounds)              \
        (This)->lpVtbl -> Draw(This, hdc, prcBounds)

// inetcore\published\inc\pkgmgr.h
#define IEnumCodeStoreDBEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumCodeStoreDBEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumCodeStoreDBEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumCodeStoreDBEntry_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IEnumCodeStoreDBEntry_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumCodeStoreDBEntry_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)
#define ICodeStoreDBEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICodeStoreDBEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICodeStoreDBEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICodeStoreDBEntry_GetName(This,dwFlags,pbstrName)	\
    (This)->lpVtbl -> GetName(This,dwFlags,pbstrName)
#define ICodeStoreDBEntry_CreateChild(This,pszName,ppEntry)	\
    (This)->lpVtbl -> CreateChild(This,pszName,ppEntry)
#define ICodeStoreDBEntry_RemoveChild(This,pszName,dwFlags)	\
    (This)->lpVtbl -> RemoveChild(This,pszName,dwFlags)
#define ICodeStoreDBEntry_GetChild(This,pszName,ppEntry)	\
    (This)->lpVtbl -> GetChild(This,pszName,ppEntry)
#define ICodeStoreDBEntry_EnumChildren(This,ppEntry)	\
    (This)->lpVtbl -> EnumChildren(This,ppEntry)
#define ICodeStoreDBEntry_GetParent(This,ppParent)	\
    (This)->lpVtbl -> GetParent(This,ppParent)
#define ICodeStoreDBEntry_GetProperty(This,pszName,pvarProperty)	\
    (This)->lpVtbl -> GetProperty(This,pszName,pvarProperty)
#define ICodeStoreDBEntry_SetProperty(This,pszName,pvarProperty)	\
    (This)->lpVtbl -> SetProperty(This,pszName,pvarProperty)
#define ICodeStoreDBEntry_DeleteProperty(This,pszName)	\
    (This)->lpVtbl -> DeleteProperty(This,pszName)
#define ICodeStoreDBEntry_GetDWORDPropertyA(This,pszName,pVal)	\
    (This)->lpVtbl -> GetDWORDPropertyA(This,pszName,pVal)
#define ICodeStoreDBEntry_SetDWORDPropertyA(This,pszName,dwVal)	\
    (This)->lpVtbl -> SetDWORDPropertyA(This,pszName,dwVal)
#define ICodeStoreDBEntry_GetStringPropertyA(This,pszName,pszVal,cbVal)	\
    (This)->lpVtbl -> GetStringPropertyA(This,pszName,pszVal,cbVal)
#define ICodeStoreDBEntry_SetStringPropertyA(This,pszName,pszVal)	\
    (This)->lpVtbl -> SetStringPropertyA(This,pszName,pszVal)
#define ICodeStoreDB_CreateEntry(This,pszName,ppEntry)	\
    (This)->lpVtbl -> CreateEntry(This,pszName,ppEntry)
#define ICodeStoreDB_RemoveEntry(This,pszName,dwFlags)	\
    (This)->lpVtbl -> RemoveEntry(This,pszName,dwFlags)
#define ICodeStoreDB_GetEntry(This,pszName,ppEntry)	\
    (This)->lpVtbl -> GetEntry(This,pszName,ppEntry)
#define ICodeStoreDB_EnumRootEntries(This,ppEntry)	\
    (This)->lpVtbl -> EnumRootEntries(This,ppEntry)
#define IJavaPackage_GetCapabilities(This,ppCapabilities,pcbCapabilities)	\
    (This)->lpVtbl -> GetCapabilities(This,ppCapabilities,pcbCapabilities)
#define IJavaPackage_GetSigner(This,ppSigner,pcbSigner)	\
    (This)->lpVtbl -> GetSigner(This,ppSigner,pcbSigner)
#define IJavaPackage_GetFilePathA(This,pszPath,cbPath)	\
    (This)->lpVtbl -> GetFilePathA(This,pszPath,cbPath)
#define IJavaFile_GetPENativePathA(This,pszPath,cbPath)	\
    (This)->lpVtbl -> GetPENativePathA(This,pszPath,cbPath)

// inetcore\urlmon\zones\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// inetcore\winhttp\v5.1\http\chunkflt.cxx
#define GET_CHUNK_TOKEN(ch)  ((ch) & 0x80 ? CHUNK_TOKEN_DATA : g_bChunkTokenTable[ch])

// inetcore\winhttp\v5.1\inc\inethttp.h
#define HttpSendRequestEx(h,pbi,pbo,dw,c)\
    WinHttpSendRequest(h,   \
        (pbi)->lpcszHeader,     \
        (pbi)->dwHeadersLength, \
        (pbi)->lpvBuffer,       \
        (pbi)->dwBufferLength,  \
        (pbi)->dwBufferTotal,   \
        0)

// inetcore\winhttp\v5\http\chunkflt.cxx
#define GET_CHUNK_TOKEN(ch)  ((ch) & 0x80 ? CHUNK_TOKEN_DATA : g_bChunkTokenTable[ch])

// inetcore\winhttp\v5\inc\inethttp.h
#define HttpSendRequestEx(h,pbi,pbo,dw,c)\
    WinHttpSendRequest(h,   \
        (pbi)->lpcszHeader,     \
        (pbi)->dwHeadersLength, \
        (pbi)->lpvBuffer,       \
        (pbi)->dwBufferLength,  \
        (pbi)->dwBufferTotal,   \
        0)

// inetcore\wininet\inc\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// inetsrv\iis\admin\adsi\helper\include\umi.h
#define IUmiObject_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiObject_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiConnection_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiConnection_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiCursor_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiCursor_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiQuery_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiQuery_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)

// inetsrv\iis\admin\snapin\inetprop.h
#define BEGIN_PARSE_META_RECORDS(dwNumEntries, pbMDData)\
{                                                       \
    METADATA_GETALL_RECORD * pAllRecords =              \
        (METADATA_GETALL_RECORD *)pbMDData;             \
    ASSERT(pAllRecords != NULL);                        \
                                                        \
    for (DWORD i = 0; i < dwNumEntries; ++i)            \
    {                                                   \
        METADATA_GETALL_RECORD * pRec = &pAllRecords[i];\
        switch(pRec->dwMDIdentifier)                    \
        {

// inetsrv\iis\config\src\inc\xmlparser.h
#define IXMLNodeSource_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLNodeSource_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLParser_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_PushData(This,pData,ulChars,fLastBuffer)	\
    (This)->lpVtbl -> PushData(This,pData,ulChars,fLastBuffer)

// inetsrv\iis\config\src\stores\xmltable\xmlparser.h
#define IXMLNodeSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IXMLNodeSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IXMLNodeSource_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IXMLNodeSource_SetFactory(This,pNodeFactory)	\
    (This)->lpVtbl -> SetFactory(This,pNodeFactory)
#define IXMLNodeSource_GetFactory(This,ppNodeFactory)	\
    (This)->lpVtbl -> GetFactory(This,ppNodeFactory)
#define IXMLNodeSource_Abort(This,bstrErrorInfo)	\
    (This)->lpVtbl -> Abort(This,bstrErrorInfo)
#define IXMLNodeSource_GetLineNumber(This)	\
    (This)->lpVtbl -> GetLineNumber(This)
#define IXMLNodeSource_GetLinePosition(This)	\
    (This)->lpVtbl -> GetLinePosition(This)
#define IXMLNodeSource_GetAbsolutePosition(This)	\
    (This)->lpVtbl -> GetAbsolutePosition(This)
#define IXMLNodeSource_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLNodeSource_GetLastError(This)	\
    (This)->lpVtbl -> GetLastError(This)
#define IXMLNodeSource_GetErrorInfo(This,pbstrErrorInfo)	\
    (This)->lpVtbl -> GetErrorInfo(This,pbstrErrorInfo)
#define IXMLNodeSource_GetFlags(This)	\
    (This)->lpVtbl -> GetFlags(This)
#define IXMLNodeSource_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IXMLParser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IXMLParser_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IXMLParser_SetFactory(This,pNodeFactory)	\
    (This)->lpVtbl -> SetFactory(This,pNodeFactory)
#define IXMLParser_GetFactory(This,ppNodeFactory)	\
    (This)->lpVtbl -> GetFactory(This,ppNodeFactory)
#define IXMLParser_Abort(This,bstrErrorInfo)	\
    (This)->lpVtbl -> Abort(This,bstrErrorInfo)
#define IXMLParser_GetLineNumber(This)	\
    (This)->lpVtbl -> GetLineNumber(This)
#define IXMLParser_GetLinePosition(This)	\
    (This)->lpVtbl -> GetLinePosition(This)
#define IXMLParser_GetAbsolutePosition(This)	\
    (This)->lpVtbl -> GetAbsolutePosition(This)
#define IXMLParser_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLParser_GetLastError(This)	\
    (This)->lpVtbl -> GetLastError(This)
#define IXMLParser_GetErrorInfo(This,pbstrErrorInfo)	\
    (This)->lpVtbl -> GetErrorInfo(This,pbstrErrorInfo)
#define IXMLParser_GetFlags(This)	\
    (This)->lpVtbl -> GetFlags(This)
#define IXMLParser_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_Load(This,fFullyAvailable,pimkName,pibc,grfMode)	\
    (This)->lpVtbl -> Load(This,fFullyAvailable,pimkName,pibc,grfMode)
#define IXMLParser_SetInput(This,pStm)	\
    (This)->lpVtbl -> SetInput(This,pStm)
#define IXMLParser_PushData(This,pData,ulChars,fLastBuffer)	\
    (This)->lpVtbl -> PushData(This,pData,ulChars,fLastBuffer)
#define IXMLParser_ParseEntity(This,pwcText,ulLen,fpe)	\
    (This)->lpVtbl -> ParseEntity(This,pwcText,ulLen,fpe)
#define IXMLParser_ExpandEntity(This,pwcText,ulLen)	\
    (This)->lpVtbl -> ExpandEntity(This,pwcText,ulLen)
#define IXMLParser_SetRoot(This,pRoot)	\
    (This)->lpVtbl -> SetRoot(This,pRoot)
#define IXMLParser_GetRoot(This,ppRoot)	\
    (This)->lpVtbl -> GetRoot(This,ppRoot)
#define IXMLParser_Run(This,lChars)	\
    (This)->lpVtbl -> Run(This,lChars)
#define IXMLParser_GetParserState(This)	\
    (This)->lpVtbl -> GetParserState(This)
#define IXMLParser_Suspend(This)	\
    (This)->lpVtbl -> Suspend(This)
#define IXMLParser_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IXMLParser_SetFlags(This,iFlags)	\
    (This)->lpVtbl -> SetFlags(This,iFlags)
#define IXMLNodeFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IXMLNodeFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IXMLNodeFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IXMLNodeFactory_NotifyEvent(This,pSource,iEvt)	\
    (This)->lpVtbl -> NotifyEvent(This,pSource,iEvt)
#define IXMLNodeFactory_BeginChildren(This,pSource,pNodeInfo)	\
    (This)->lpVtbl -> BeginChildren(This,pSource,pNodeInfo)
#define IXMLNodeFactory_EndChildren(This,pSource,fEmpty,pNodeInfo)	\
    (This)->lpVtbl -> EndChildren(This,pSource,fEmpty,pNodeInfo)
#define IXMLNodeFactory_Error(This,pSource,hrErrorCode,cNumRecs,apNodeInfo)	\
    (This)->lpVtbl -> Error(This,pSource,hrErrorCode,cNumRecs,apNodeInfo)
#define IXMLNodeFactory_CreateNode(This,pSource,pNodeParent,cNumRecs,apNodeInfo)	\
    (This)->lpVtbl -> CreateNode(This,pSource,pNodeParent,cNumRecs,apNodeInfo)

// inetsrv\iis\config\src\wmi\atl30\atlcom.h
#define DECLARE_PROTECT_FINAL_CONSTRUCT()\
	void InternalFinalConstructAddRef() {InternalAddRef();}\
	void InternalFinalConstructRelease() {InternalRelease();}
#define DECLARE_NOT_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComCreator< CComObject< x > >, CComFailCreator<CLASS_E_NOAGGREGATION> > _CreatorClass;
#define DECLARE_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComCreator< CComObject< x > >, CComCreator< CComAggObject< x > > > _CreatorClass;
#define DECLARE_ONLY_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComFailCreator<E_FAIL>, CComCreator< CComAggObject< x > > > _CreatorClass;
#define DECLARE_POLY_AGGREGATABLE(x) public:\
	typedef CComCreator< CComPolyObject< x > > _CreatorClass;
#define COM_INTERFACE_ENTRY_BREAK(x)\
	{&_ATL_IIDOF(x), \
	NULL, \
	_Break},
#define COM_INTERFACE_ENTRY_NOINTERFACE(x)\
	{&_ATL_IIDOF(x), \
	NULL, \
	_NoInterface},
#define COM_INTERFACE_ENTRY_IMPL(x)\
	COM_INTERFACE_ENTRY_IID(_ATL_IIDOF(x), x##Impl<_ComMapClass>)
#define COM_INTERFACE_ENTRY_IMPL_IID(iid, x)\
	COM_INTERFACE_ENTRY_IID(iid, x##Impl<_ComMapClass>)
#define COM_INTERFACE_ENTRY_FUNC(iid, dw, func)\
	{&iid, \
	dw, \
	func},
#define IMPLEMENTED_CATEGORY( catid ) { _ATL_CATMAP_ENTRY_IMPLEMENTED, &catid },
#define REQUIRED_CATEGORY( catid ) { _ATL_CATMAP_ENTRY_REQUIRED, &catid },
#define END_CATEGORY_MAP()\
   { _ATL_CATMAP_ENTRY_END, NULL } };\
   return( pMap ); }
#define OBJECT_ENTRY(clsid, class) {&clsid, class::UpdateRegistry, class::_ClassFactoryCreatorClass::CreateInstance, class::_CreatorClass::CreateInstance, NULL, 0, class::GetObjectDescription, class::GetCategoryMap, class::ObjectMain },
#define OBJECT_ENTRY_NON_CREATEABLE(class) {&CLSID_NULL, class::UpdateRegistry, NULL, NULL, NULL, 0, NULL, class::GetCategoryMap, class::ObjectMain },
#define BEGIN_SINK_MAP(_class)\
	static const _ATL_EVENT_ENTRY<_class>* _GetSinkMap()\
	{\
		typedef _class _atl_event_classtype;\
		static const _ATL_EVENT_ENTRY<_class> map[] = {

// inetsrv\iis\config\src\wmi\atl30\atldbcli.h
#define BEGIN_PARAM_MAP(x) \
	public: \
	typedef x _classtype; \
	typedef x _ParamClass; \
	static bool HasParameters() { return true; } \
	static HRESULT _GetParamEntries(ULONG* pColumns, DBBINDING *pBinding, BYTE* pBuffer = NULL) \
	{ \
		ATLASSERT(pColumns != NULL); \
		DBPARAMIO eParamIO = DBPARAMIO_INPUT; \
		int nColumns = 0; \
		pBuffer;

// inetsrv\iis\config\src\wmi\psdk_inc\wbemcli.h
#define IWbemObjectAccess_ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData)	\
    (This)->lpVtbl -> ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData)
#define IWbemEventSink_SetBatchingParameters(This,lFlags,dwMaxBufferSize,dwMaxSendLatency)	\
    (This)->lpVtbl -> SetBatchingParameters(This,lFlags,dwMaxBufferSize,dwMaxSendLatency)
#define IMofCompiler_CompileBuffer(This,BuffSize,pBuffer,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo)	\
    (This)->lpVtbl -> CompileBuffer(This,BuffSize,pBuffer,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo)

// inetsrv\iis\config\src\wmi\psdk_inc\wbemtran.h
#define IWbemConstructClassObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IWbemConstructClassObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IWbemConstructClassObject_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IWbemConstructClassObject_SetInheritanceChain(This,lNumAntecedents,awszAntecedents)	\
    (This)->lpVtbl -> SetInheritanceChain(This,lNumAntecedents,awszAntecedents)
#define IWbemConstructClassObject_SetPropertyOrigin(This,wszPropertyName,lOriginIndex)	\
    (This)->lpVtbl -> SetPropertyOrigin(This,wszPropertyName,lOriginIndex)
#define IWbemConstructClassObject_SetMethodOrigin(This,wszMethodName,lOriginIndex)	\
    (This)->lpVtbl -> SetMethodOrigin(This,wszMethodName,lOriginIndex)
#define IWbemConstructClassObject_SetServerNamespace(This,wszServer,wszNamespace)	\
    (This)->lpVtbl -> SetServerNamespace(This,wszServer,wszNamespace)

// inetsrv\iis\config\src\wmi\utils\wmisec\wbemcli.h
#define IWbemObjectAccess_ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData)	\
    (This)->lpVtbl -> ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData)
#define IWbemEventSink_SetBatchingParameters(This,lFlags,dwMaxBufferSize,dwMaxSendLatency)	\
    (This)->lpVtbl -> SetBatchingParameters(This,lFlags,dwMaxBufferSize,dwMaxSendLatency)
#define IMofCompiler_CompileBuffer(This,BuffSize,pBuffer,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo)	\
    (This)->lpVtbl -> CompileBuffer(This,BuffSize,pBuffer,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo)

// inetsrv\iis\iisrearc\core\common\util\lkrhash.cpp
# define DECLARE_ALLOCATOR_LHTSUBCLASS(CLASS)            \
  CLKRhashAllocator* LKRHASH_NS::CLKRLinearHashTable::CLASS::sm_palloc = NULL; \
#define INIT_ALLOCATOR_LHTSUBCLASS(CLASS, N)                    \
    LKRHASH_ALLOCATOR_INIT(LKRHASH_NS::CLKRLinearHashTable::CLASS, N, f);     \
#define UNINIT_ALLOCATOR_LHTSUBCLASS(CLASS)            \
    LKRHASH_ALLOCATOR_UNINIT(LKRHASH_NS::CLKRLinearHashTable::CLASS);\

// inetsrv\iis\iisrearc\import\inc\catalog.h
#define ISimpleTableDispenser2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableDispenser2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableDispenser2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableRead2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableRead2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableRead2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableRead2_GetRowIndexByIdentity(This,i_acbSizes,i_apvValues,o_piRow)	\
    (This)->lpVtbl -> GetRowIndexByIdentity(This,i_acbSizes,i_apvValues,o_piRow)
#define ISimpleTableRead2_GetColumnValues(This,i_iRow,i_cColumns,i_aiColumns,o_acbSizes,o_apvValues)	\
    (This)->lpVtbl -> GetColumnValues(This,i_iRow,i_cColumns,i_aiColumns,o_acbSizes,o_apvValues)
#define ISimpleTableRead2_GetTableMeta(This,o_pcVersion,o_pfTable,o_pcRows,o_pcColumns)	\
    (This)->lpVtbl -> GetTableMeta(This,o_pcVersion,o_pfTable,o_pcRows,o_pcColumns)
#define ISimpleTableRead2_GetColumnMetas(This,i_cColumns,i_aiColumns,o_aColumnMetas)	\
    (This)->lpVtbl -> GetColumnMetas(This,i_cColumns,i_aiColumns,o_aColumnMetas)
#define ISimpleTableRead2_GetRowIndexBySearch(This,i_iStartingRow,i_cColumns,i_aiColumns,i_acbSizes,i_apvValues,o_piRow)	\
    (This)->lpVtbl -> GetRowIndexBySearch(This,i_iStartingRow,i_cColumns,i_aiColumns,i_acbSizes,i_apvValues,o_piRow)
#define ISimpleTableWrite2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableWrite2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableWrite2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableWrite2_GetRowIndexByIdentity(This,i_acbSizes,i_apvValues,o_piRow)	\
    (This)->lpVtbl -> GetRowIndexByIdentity(This,i_acbSizes,i_apvValues,o_piRow)
#define ISimpleTableWrite2_GetColumnValues(This,i_iRow,i_cColumns,i_aiColumns,o_acbSizes,o_apvValues)	\
    (This)->lpVtbl -> GetColumnValues(This,i_iRow,i_cColumns,i_aiColumns,o_acbSizes,o_apvValues)
#define ISimpleTableWrite2_GetTableMeta(This,o_pcVersion,o_pfTable,o_pcRows,o_pcColumns)	\
    (This)->lpVtbl -> GetTableMeta(This,o_pcVersion,o_pfTable,o_pcRows,o_pcColumns)
#define ISimpleTableWrite2_GetColumnMetas(This,i_cColumns,i_aiColumns,o_aColumnMetas)	\
    (This)->lpVtbl -> GetColumnMetas(This,i_cColumns,i_aiColumns,o_aColumnMetas)
#define ISimpleTableWrite2_GetRowIndexBySearch(This,i_iStartingRow,i_cColumns,i_aiColumns,i_acbSizes,i_apvValues,o_piRow)	\
    (This)->lpVtbl -> GetRowIndexBySearch(This,i_iStartingRow,i_cColumns,i_aiColumns,i_acbSizes,i_apvValues,o_piRow)
#define ISimpleTableWrite2_AddRowForDelete(This,i_iReadRow)	\
    (This)->lpVtbl -> AddRowForDelete(This,i_iReadRow)
#define ISimpleTableWrite2_AddRowForInsert(This,o_piWriteRow)	\
    (This)->lpVtbl -> AddRowForInsert(This,o_piWriteRow)
#define ISimpleTableWrite2_AddRowForUpdate(This,i_iReadRow,o_piWriteRow)	\
    (This)->lpVtbl -> AddRowForUpdate(This,i_iReadRow,o_piWriteRow)
#define ISimpleTableWrite2_SetWriteColumnValues(This,i_iRow,i_cColumns,i_aiColumns,i_acbSizes,i_apvValues)	\
    (This)->lpVtbl -> SetWriteColumnValues(This,i_iRow,i_cColumns,i_aiColumns,i_acbSizes,i_apvValues)
#define ISimpleTableWrite2_GetWriteColumnValues(This,i_iRow,i_cColumns,i_aiColumns,o_afStatus,o_acbSizes,o_apvValues)	\
    (This)->lpVtbl -> GetWriteColumnValues(This,i_iRow,i_cColumns,i_aiColumns,o_afStatus,o_acbSizes,o_apvValues)
#define ISimpleTableWrite2_GetWriteRowIndexByIdentity(This,i_acbSizes,i_apvValues,o_piRow)	\
    (This)->lpVtbl -> GetWriteRowIndexByIdentity(This,i_acbSizes,i_apvValues,o_piRow)
#define ISimpleTableWrite2_UpdateStore(This)	\
    (This)->lpVtbl -> UpdateStore(This)
#define ISimpleTableWrite2_GetWriteRowIndexBySearch(This,i_iStartingRow,i_cColumns,i_aiColumns,i_acbSizes,i_apvValues,o_piRow)	\
    (This)->lpVtbl -> GetWriteRowIndexBySearch(This,i_iStartingRow,i_cColumns,i_aiColumns,i_acbSizes,i_apvValues,o_piRow)
#define ISimpleTableWrite2_GetErrorTable(This,i_fServiceRequests,o_ppvSimpleTable)	\
    (This)->lpVtbl -> GetErrorTable(This,i_fServiceRequests,o_ppvSimpleTable)
#define ISimpleTableAdvanced_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableAdvanced_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableAdvanced_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableAdvanced_PopulateCache(This)	\
    (This)->lpVtbl -> PopulateCache(This)
#define ISimpleTableAdvanced_GetDetailedErrorCount(This,o_pcErrs)	\
    (This)->lpVtbl -> GetDetailedErrorCount(This,o_pcErrs)
#define ISimpleTableAdvanced_GetDetailedError(This,i_iErr,o_pSTErr)	\
    (This)->lpVtbl -> GetDetailedError(This,i_iErr,o_pSTErr)
#define ISimpleTableController_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableController_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableController_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableController_PopulateCache(This)	\
    (This)->lpVtbl -> PopulateCache(This)
#define ISimpleTableController_GetDetailedErrorCount(This,o_pcErrs)	\
    (This)->lpVtbl -> GetDetailedErrorCount(This,o_pcErrs)
#define ISimpleTableController_GetDetailedError(This,i_iErr,o_pSTErr)	\
    (This)->lpVtbl -> GetDetailedError(This,i_iErr,o_pSTErr)
#define ISimpleTableController_ShapeCache(This,i_fTable,i_cColumns,i_acolmetas,i_apvDefaults,i_acbSizes)	\
    (This)->lpVtbl -> ShapeCache(This,i_fTable,i_cColumns,i_acolmetas,i_apvDefaults,i_acbSizes)
#define ISimpleTableController_PrePopulateCache(This,i_fControl)	\
    (This)->lpVtbl -> PrePopulateCache(This,i_fControl)
#define ISimpleTableController_PostPopulateCache(This)	\
    (This)->lpVtbl -> PostPopulateCache(This)
#define ISimpleTableController_DiscardPendingWrites(This)	\
    (This)->lpVtbl -> DiscardPendingWrites(This)
#define ISimpleTableController_GetWriteRowAction(This,i_iRow,o_peAction)	\
    (This)->lpVtbl -> GetWriteRowAction(This,i_iRow,o_peAction)
#define ISimpleTableController_SetWriteRowAction(This,i_iRow,i_eAction)	\
    (This)->lpVtbl -> SetWriteRowAction(This,i_iRow,i_eAction)
#define ISimpleTableController_ChangeWriteColumnStatus(This,i_iRow,i_iColumn,i_fStatus)	\
    (This)->lpVtbl -> ChangeWriteColumnStatus(This,i_iRow,i_iColumn,i_fStatus)
#define ISimpleTableController_AddDetailedError(This,o_pSTErr)	\
    (This)->lpVtbl -> AddDetailedError(This,o_pSTErr)
#define ISimpleTableController_GetMarshallingInterface(This,o_piid,o_ppItf)	\
    (This)->lpVtbl -> GetMarshallingInterface(This,o_piid,o_ppItf)
#define IAdvancedTableDispenser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IAdvancedTableDispenser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IAdvancedTableDispenser_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IAdvancedTableDispenser_GetProductID(This,o_wszProductID,io_pcchProductID)	\
    (This)->lpVtbl -> GetProductID(This,o_wszProductID,io_pcchProductID)
#define IAdvancedTableDispenser_GetCatalogErrorLogger(This,o_ppErrorLogger)	\
    (This)->lpVtbl -> GetCatalogErrorLogger(This,o_ppErrorLogger)
#define IAdvancedTableDispenser_SetCatalogErrorLogger(This,i_pErrorLogger)	\
    (This)->lpVtbl -> SetCatalogErrorLogger(This,i_pErrorLogger)
#define ISimpleTableInterceptor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableInterceptor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableInterceptor_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableEvent_OnChange(This,i_ppISTWrite,i_cTables,i_dwCookie)	\
    (This)->lpVtbl -> OnChange(This,i_ppISTWrite,i_cTables,i_dwCookie)
#define ISimpleTableAdvise_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableAdvise_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableAdvise_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableAdvise_SimpleTableAdvise(This,i_pISTEvent,i_snid,i_ams,i_cms,o_pdwCookie)	\
    (This)->lpVtbl -> SimpleTableAdvise(This,i_pISTEvent,i_snid,i_ams,i_cms,o_pdwCookie)
#define ISimpleTableAdvise_SimpleTableUnadvise(This,i_dwCookie)	\
    (This)->lpVtbl -> SimpleTableUnadvise(This,i_dwCookie)
#define ISimpleTableEventMgr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableEventMgr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableEventMgr_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableEventMgr_AddUpdateStoreDelta(This,i_wszTableName,i_pWriteCache,i_cbWriteCache,i_cbWriteVarData)	\
    (This)->lpVtbl -> AddUpdateStoreDelta(This,i_wszTableName,i_pWriteCache,i_cbWriteCache,i_cbWriteVarData)
#define ISimpleTableEventMgr_FireEvents(This,i_snid)	\
    (This)->lpVtbl -> FireEvents(This,i_snid)
#define ISimpleTableEventMgr_CancelEvents(This)	\
    (This)->lpVtbl -> CancelEvents(This)
#define ISimpleTableEventMgr_RehookNotifications(This)	\
    (This)->lpVtbl -> RehookNotifications(This)
#define ISimpleTableFileChange_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableFileChange_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableFileChange_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableFileChange_OnFileCreate(This,i_wszFileName)	\
    (This)->lpVtbl -> OnFileCreate(This,i_wszFileName)
#define ISimpleTableFileChange_OnFileModify(This,i_wszFileName)	\
    (This)->lpVtbl -> OnFileModify(This,i_wszFileName)
#define ISimpleTableFileChange_OnFileDelete(This,i_wszFileName)	\
    (This)->lpVtbl -> OnFileDelete(This,i_wszFileName)
#define ISimpleTableFileAdvise_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableFileAdvise_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableFileAdvise_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableFileAdvise_SimpleTableFileAdvise(This,i_pISTFile,i_wszDirectory,i_wszFile,i_fFlags,o_pdwCookie)	\
    (This)->lpVtbl -> SimpleTableFileAdvise(This,i_pISTFile,i_wszDirectory,i_wszFile,i_fFlags,o_pdwCookie)
#define ISimpleTableFileAdvise_SimpleTableFileUnadvise(This,i_dwCookie)	\
    (This)->lpVtbl -> SimpleTableFileUnadvise(This,i_dwCookie)
#define ISimpleTableDispenserWiring_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableDispenserWiring_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableDispenserWiring_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableDispenserWiring_GetMarshallingConnection(This,i_QueryData,i_QueryMeta,i_eQueryFormat,i_riid,o_ppv)	\
    (This)->lpVtbl -> GetMarshallingConnection(This,i_QueryData,i_QueryMeta,i_eQueryFormat,i_riid,o_ppv)
#define ISimpleClientTableOptimizer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleClientTableOptimizer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleClientTableOptimizer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleClientTableOptimizer_SetMarshallingConnection(This,i_pUnk)	\
    (This)->lpVtbl -> SetMarshallingConnection(This,i_pUnk)
#define ISimpleTableMarshall_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableMarshall_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableMarshall_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableMarshall_SupplyMarshallable(This,i_fCaches,o_ppv1,o_pcb1,o_ppv2,o_pcb2,o_ppv3,o_pcb3,o_ppv4,o_pcb4,o_ppv5,o_pcb5)	\
    (This)->lpVtbl -> SupplyMarshallable(This,i_fCaches,o_ppv1,o_pcb1,o_ppv2,o_pcb2,o_ppv3,o_pcb3,o_ppv4,o_pcb4,o_ppv5,o_pcb5)
#define ISimpleTableMarshall_ConsumeMarshallable(This,i_fCaches,i_pv1,i_cb1,i_pv2,i_cb2,i_pv3,i_cb3,i_pv4,i_cb4,i_pv5,i_cb5)	\
    (This)->lpVtbl -> ConsumeMarshallable(This,i_fCaches,i_pv1,i_cb1,i_pv2,i_cb2,i_pv3,i_cb3,i_pv4,i_cb4,i_pv5,i_cb5)
#define ISimpleTableTransform_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableTransform_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableTransform_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableTransform_Initialize(This,i_pDispenser,i_wszProtocol,i_wszSelector,o_pcRealConfigStores,o_pcPossibleConfigStores)	\
    (This)->lpVtbl -> Initialize(This,i_pDispenser,i_wszProtocol,i_wszSelector,o_pcRealConfigStores,o_pcPossibleConfigStores)
#define ISimpleTableTransform_GetRealConfigStores(This,i_cConfigStores,io_paConfigStores)	\
    (This)->lpVtbl -> GetRealConfigStores(This,i_cConfigStores,io_paConfigStores)
#define ISimpleTableTransform_GetPossibleConfigStores(This,i_cPossibleConfigStores,io_paConfigStores)	\
    (This)->lpVtbl -> GetPossibleConfigStores(This,i_cPossibleConfigStores,io_paConfigStores)
#define ISimpleTableMerge_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISimpleTableMerge_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISimpleTableMerge_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISimpleTableMerge_Initialize(This,i_cNrColumns,i_cNrPKColumns,i_aPKColumns)	\
    (This)->lpVtbl -> Initialize(This,i_cNrColumns,i_cNrPKColumns,i_aPKColumns)
#define ISimpleTableMerge_Merge(This,i_pSTRead,io_pCache,i_pContext)	\
    (This)->lpVtbl -> Merge(This,i_pSTRead,io_pCache,i_pContext)

// inetsrv\iis\iisrearc\ul\drv\httpconn.h
#define UL_REFERENCE_REQUEST_BUFFER( pbuf )                                 \
    InterlockedIncrement( &( pbuf )->RefCount )

// inetsrv\iis\img\psdksamp\components\cpp\mtxsample\source\bankvc.h
#define ICreateTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICreateTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICreateTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICreateTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ICreateTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ICreateTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ICreateTable_CreateAccount(This)	\
    (This)->lpVtbl -> CreateAccount(This)

// inetsrv\iis\lkrhash\src\lkrhash.cpp
# define DECLARE_ALLOCATOR_LHTSUBCLASS(CLASS)            \
  CLKRhashAllocator* LKRHASH_NS::CLKRLinearHashTable::CLASS::sm_palloc = NULL
#define INIT_ALLOCATOR_LHTSUBCLASS(CLASS, N, Tag)                    \
    LKRHASH_ALLOCATOR_INIT(LKRHASH_NS::CLKRLinearHashTable::CLASS, N, Tag, f)
#define UNINIT_ALLOCATOR_LHTSUBCLASS(CLASS)            \
    LKRHASH_ALLOCATOR_UNINIT(LKRHASH_NS::CLKRLinearHashTable::CLASS)

// inetsrv\iis\staxinc\exchmole.h
#define IMimeInternational_ConvertBuffer(This,cpiSource,cpiDest,pIn,pOut,pcbRead)	\
    (This)->lpVtbl -> ConvertBuffer(This,cpiSource,cpiDest,pIn,pOut,pcbRead)
#define IMimeHeaderTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMimeHeaderTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMimeHeaderTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMimeHeaderTable_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)
#define IMimeHeaderTable_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)
#define IMimeHeaderTable_Load(This,pStm)	\
    (This)->lpVtbl -> Load(This,pStm)
#define IMimeHeaderTable_Save(This,pStm,fClearDirty)	\
    (This)->lpVtbl -> Save(This,pStm,fClearDirty)
#define IMimeHeaderTable_GetSizeMax(This,pcbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pcbSize)
#define IMimeHeaderTable_FindFirstRow(This,pFindHeader,phRow)	\
    (This)->lpVtbl -> FindFirstRow(This,pFindHeader,phRow)
#define IMimeHeaderTable_CountRows(This,pszHeader,pcRows)	\
    (This)->lpVtbl -> CountRows(This,pszHeader,pcRows)
#define IMimeHeaderTable_AppendRow(This,pszHeader,dwFlags,pszData,cchData,phRow)	\
    (This)->lpVtbl -> AppendRow(This,pszHeader,dwFlags,pszData,cchData,phRow)
#define IMimeHeaderTable_DeleteRow(This,hRow)	\
    (This)->lpVtbl -> DeleteRow(This,hRow)
#define IMimeHeaderTable_GetRowData(This,hRow,dwFlags,ppszData,pcchData)	\
    (This)->lpVtbl -> GetRowData(This,hRow,dwFlags,ppszData,pcchData)
#define IMimeHeaderTable_SetRowData(This,hRow,dwFlags,pszData,cchData)	\
    (This)->lpVtbl -> SetRowData(This,hRow,dwFlags,pszData,cchData)
#define IMimeHeaderTable_GetRowInfo(This,hRow,pInfo)	\
    (This)->lpVtbl -> GetRowInfo(This,hRow,pInfo)
#define IMimeHeaderTable_SetRowNumber(This,hRow,dwRowNumber)	\
    (This)->lpVtbl -> SetRowNumber(This,hRow,dwRowNumber)
#define IMimeHeaderTable_EnumRows(This,pszHeader,dwFlags,ppEnum)	\
    (This)->lpVtbl -> EnumRows(This,pszHeader,dwFlags,ppEnum)
#define IMimeHeaderTable_Clone(This,ppTable)	\
    (This)->lpVtbl -> Clone(This,ppTable)
#define IMimeHeaderTable_BindToObject(This,riid,ppvObject)	\
    (This)->lpVtbl -> BindToObject(This,riid,ppvObject)
#define IMimePropertySet_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)
#define IMimeAddressTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMimeAddressTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMimeAddressTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMimeAddressTable_GetSender(This,ppAddress)	\
    (This)->lpVtbl -> GetSender(This,ppAddress)
#define IMimeAddressTable_CountTypes(This,dwAdrTypes,pcAddresses)	\
    (This)->lpVtbl -> CountTypes(This,dwAdrTypes,pcAddresses)
#define IMimeAddressTable_EnumTypes(This,dwAdrTypes,ppEnum)	\
    (This)->lpVtbl -> EnumTypes(This,dwAdrTypes,ppEnum)
#define IMimeAddressTable_DeleteTypes(This,dwAdrTypes)	\
    (This)->lpVtbl -> DeleteTypes(This,dwAdrTypes)
#define IMimeAddressTable_DeleteAll(This)	\
    (This)->lpVtbl -> DeleteAll(This)
#define IMimeAddressTable_AppendBasic(This,dwAdrType,ietEncoding,pszFriendly,pszEmail)	\
    (This)->lpVtbl -> AppendBasic(This,dwAdrType,ietEncoding,pszFriendly,pszEmail)
#define IMimeAddressTable_AppendNew(This,dwAdrType,ppAddress)	\
    (This)->lpVtbl -> AppendNew(This,dwAdrType,ppAddress)
#define IMimeAddressTable_AppendAs(This,dwAdrType,pAddress)	\
    (This)->lpVtbl -> AppendAs(This,dwAdrType,pAddress)
#define IMimeAddressTable_AppendRfc822(This,dwAdrType,ietEncoding,pszRfc822Adr)	\
    (This)->lpVtbl -> AppendRfc822(This,dwAdrType,ietEncoding,pszRfc822Adr)
#define IMimeAddressTable_GetFormat(This,dwAdrType,format,ppszAddress)	\
    (This)->lpVtbl -> GetFormat(This,dwAdrType,format,ppszAddress)
#define IMimeAddressTable_Clone(This,ppTable)	\
    (This)->lpVtbl -> Clone(This,ppTable)
#define IMimeAddressTable_BindToObject(This,riid,ppvObject)	\
    (This)->lpVtbl -> BindToObject(This,riid,ppvObject)
#define IMimeBody_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)
#define IMimeBody_GetEstimatedSize(This,ietEncoding,pcbSize)	\
    (This)->lpVtbl -> GetEstimatedSize(This,ietEncoding,pcbSize)
#define IMimeMessageTree_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)
#define IMimeMessageTree_GetMessageSize(This,pcbSize,fCommitIfDirty)	\
    (This)->lpVtbl -> GetMessageSize(This,pcbSize,fCommitIfDirty)
#define IMimeMessageTree_CountBodies(This,hParent,fRecurse,pcBodies)	\
    (This)->lpVtbl -> CountBodies(This,hParent,fRecurse,pcBodies)
#define IMimeMessage_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)
#define IMimeMessage_GetMessageSize(This,pcbSize,fCommitIfDirty)	\
    (This)->lpVtbl -> GetMessageSize(This,pcbSize,fCommitIfDirty)
#define IMimeMessage_CountBodies(This,hParent,fRecurse,pcBodies)	\
    (This)->lpVtbl -> CountBodies(This,hParent,fRecurse,pcBodies)
#define IMimeMessage_GetAddressTable(This,ppTable)	\
    (This)->lpVtbl -> GetAddressTable(This,ppTable)
#define IMimeMessage_SplitMessage(This,cbMaxPart,ppParts)	\
    (This)->lpVtbl -> SplitMessage(This,cbMaxPart,ppParts)
#define IMimeAllocator_Alloc(This,cb)	\
    (This)->lpVtbl -> Alloc(This,cb)
#define IMimeAllocator_Realloc(This,pv,cb)	\
    (This)->lpVtbl -> Realloc(This,pv,cb)

// inetsrv\iis\svcs\cmp\asp51\dbgprop.h
#define IDebugProperty_GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)	\
    (This)->lpVtbl -> GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)
#define IDebugExtendedProperty_GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)	\
    (This)->lpVtbl -> GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)
#define IDebugExtendedProperty_GetExtendedPropertyInfo(This,dwFieldSpec,nRadix,pExtendedPropertyInfo)	\
    (This)->lpVtbl -> GetExtendedPropertyInfo(This,dwFieldSpec,nRadix,pExtendedPropertyInfo)

// inetsrv\iis\svcs\cmp\asp\dbgprop.h
#define IDebugProperty_GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)	\
    (This)->lpVtbl -> GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)
#define IDebugExtendedProperty_GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)	\
    (This)->lpVtbl -> GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)
#define IDebugExtendedProperty_GetExtendedPropertyInfo(This,dwFieldSpec,nRadix,pExtendedPropertyInfo)	\
    (This)->lpVtbl -> GetExtendedPropertyInfo(This,dwFieldSpec,nRadix,pExtendedPropertyInfo)

// inetsrv\iis\svcs\cmp\webdav\inc\exo.h
#define BEGIN_INTERFACE_TABLE(_cl)					\
const IIDINFO INTERFACE_TABLE(_cl)[] =				\
{													\
	{ (LPIID) & IID_IUnknown, 0, 0, TEXT("IUnknown") },
#define BEGIN_INTERFACE_TABLE(_cl)					\
const IIDINFO INTERFACE_TABLE(_cl)[] =				\
{													\
	{ (LPIID) & IID_IUnknown, 0, 0 },

// inetsrv\iis\svcs\iisrtl\lkrhash.cpp
# define DECLARE_ALLOCATOR_LHTSUBCLASS(CLASS)            \
  CLKRhashAllocator* CLKRLinearHashTable::CLASS::sm_palloc = NULL; \
#define INIT_ALLOCATOR_LHTSUBCLASS(CLASS, N)                    \
    LKRHASH_ALLOCATOR_INIT(CLKRLinearHashTable::CLASS, N, f);     \
#define UNINIT_ALLOCATOR_LHTSUBCLASS(CLASS)            \
    LKRHASH_ALLOCATOR_UNINIT(CLKRLinearHashTable::CLASS);\

// inetsrv\iis\svcs\infocomm\dcomadm\comtest\beta2\main.cxx
#define MD_SET_DATA_RECORD(PMDR, ID, ATTR, UTYPE, DTYPE, DLEN, PD) \
            { \
            (PMDR)->dwMDIdentifier=ID; \
            (PMDR)->dwMDAttributes=ATTR; \
            (PMDR)->dwMDUserType=UTYPE; \
            (PMDR)->dwMDDataType=DTYPE; \
            (PMDR)->dwMDDataLen=DLEN; \
            (PMDR)->pbMDData=PD; \
            }

// inetsrv\iis\svcs\infocomm\dcomadm\comtest\main.cxx
#define MD_SET_DATA_RECORD(PMDR, ID, ATTR, UTYPE, DTYPE, DLEN, PD) \
            { \
            (PMDR)->dwMDIdentifier=ID; \
            (PMDR)->dwMDAttributes=ATTR; \
            (PMDR)->dwMDUserType=UTYPE; \
            (PMDR)->dwMDDataType=DTYPE; \
            (PMDR)->dwMDDataLen=DLEN; \
            (PMDR)->pbMDData=PD; \
            }

// inetsrv\iis\svcs\infocomm\dcomadm\unitest\main.cxx
#define MD_SET_DATA_RECORD(PMDR, ID, ATTR, UTYPE, DTYPE, DLEN, PD) \
            { \
            (PMDR)->dwMDIdentifier=ID; \
            (PMDR)->dwMDAttributes=ATTR; \
            (PMDR)->dwMDUserType=UTYPE; \
            (PMDR)->dwMDDataType=DTYPE; \
            (PMDR)->dwMDDataLen=DLEN; \
            (PMDR)->pbMDData=PD; \
            }

// inetsrv\iis\svcs\infocomm\metadata\dlltest\main.c
#define MD_SET_DATA_RECORD(PMDR, ID, ATTR, UTYPE, DTYPE, DLEN, PD) \
            { \
            (PMDR)->dwMDIdentifier=ID; \
            (PMDR)->dwMDAttributes=ATTR; \
            (PMDR)->dwMDUserType=UTYPE; \
            (PMDR)->dwMDDataType=DTYPE; \
            (PMDR)->dwMDDataLen=DLEN; \
            (PMDR)->pbMDData=PD; \
            }

// inetsrv\iis\svcs\nntp\driver\nntpfs\src\stdafx.h
#define DECLARE_REGISTRY_RESOURCEID_EX(x,desc,progid,viprogid)			\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {				\
		HRESULT hrRes;													\
		_ATL_REGMAP_ENTRY *parme;										\
																		\
		hrRes = AtlAllocRegMapEx(&parme,								\
								 &GetObjectCLSID(),						\
								 &_Module,								\
								 NULL,									\
								 L"DESCRIPTION",						\
								 desc,									\
								 L"PROGID",								\
								 progid,								\
								 L"VIPROGID",							\
								 viprogid,								\
								 L"THREADINGMODEL",						\
								 ATL_THREADING_MODEL_VALUE,				\
								 NULL,									\
								 NULL);									\
		if (!SUCCEEDED(hrRes)) {										\
			return (hrRes);												\
		}																\
		hrRes = _Module.UpdateRegistryFromResource(x,bRegister,parme);	\
		CoTaskMemFree(parme);											\
		return (hrRes);													\
	}
#define DECLARE_REGISTRY_RESOURCE_EX(x,desc,progid,viprogid)				\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {					\
		HRESULT hrRes;														\
		_ATL_REGMAP_ENTRY *parme;											\
																			\
		hrRes = AtlAllocRegMapEx(&parme,									\
								 &GetObjectCLSID(),							\
								 &_Module,									\
								 NULL,										\
								 L"DESCRIPTION",							\
								 desc,										\
								 L"PROGID",									\
								 progid,									\
								 L"VIPROGID",								\
								 viprogid,									\
								 L"THREADINGMODEL",							\
								 ATL_THREADING_MODEL_VALUE,					\
								 NULL,										\
								 NULL);										\
		if (!SUCCEEDED(hrRes)) {											\
			return (hrRes);													\
		}																	\
		hrRes = _Module.UpdateRegistryFromResource(_T(#x),bRegister,parme);	\
		CoTaskMemFree(parme);												\
		return (hrRes);														\
	}

// inetsrv\iis\svcs\nntp\search\qrydb\asptlb5.h
#define IRequest_get_TotalBytes(This,pcbTotal)	\
    (This)->lpVtbl -> get_TotalBytes(This,pcbTotal)
#define IResponse_get_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> get_Buffer(This,fIsBuffering)
#define IResponse_put_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> put_Buffer(This,fIsBuffering)
#define IResponse_AppendToLog(This,bstrLogEntry)	\
    (This)->lpVtbl -> AppendToLog(This,bstrLogEntry)

// inetsrv\iis\svcs\nntp\search\qryobj\asptlb5.h
#define IRequest_get_TotalBytes(This,pcbTotal)	\
    (This)->lpVtbl -> get_TotalBytes(This,pcbTotal)
#define IResponse_get_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> get_Buffer(This,fIsBuffering)
#define IResponse_put_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> put_Buffer(This,fIsBuffering)
#define IResponse_AppendToLog(This,bstrLogEntry)	\
    (This)->lpVtbl -> AppendToLog(This,bstrLogEntry)

// inetsrv\iis\svcs\nntp\server\seo\ddrop\stdafx.h
#define DECLARE_REGISTRY_RESOURCEID_EX(x,desc,progid,viprogid)			\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {				\
		HRESULT hrRes;													\
		_ATL_REGMAP_ENTRY *parme;										\
																		\
		hrRes = AtlAllocRegMapEx(&parme,								\
								 &GetObjectCLSID(),						\
								 &_Module,								\
								 NULL,									\
								 L"DESCRIPTION",						\
								 desc,									\
								 L"PROGID",								\
								 progid,								\
								 L"VIPROGID",							\
								 viprogid,								\
								 L"THREADINGMODEL",						\
								 ATL_THREADING_MODEL_VALUE,				\
								 NULL,									\
								 NULL);									\
		if (!SUCCEEDED(hrRes)) {										\
			return (hrRes);												\
		}																\
		hrRes = _Module.UpdateRegistryFromResource(x,bRegister,parme);	\
		CoTaskMemFree(parme);											\
		return (hrRes);													\
	}
#define DECLARE_REGISTRY_RESOURCE_EX(x,desc,progid,viprogid)				\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {					\
		HRESULT hrRes;														\
		_ATL_REGMAP_ENTRY *parme;											\
																			\
		hrRes = AtlAllocRegMapEx(&parme,									\
								 &GetObjectCLSID(),							\
								 &_Module,									\
								 NULL,										\
								 L"DESCRIPTION",							\
								 desc,										\
								 L"PROGID",									\
								 progid,									\
								 L"VIPROGID",								\
								 viprogid,									\
								 L"THREADINGMODEL",							\
								 ATL_THREADING_MODEL_VALUE,					\
								 NULL,										\
								 NULL);										\
		if (!SUCCEEDED(hrRes)) {											\
			return (hrRes);													\
		}																	\
		hrRes = _Module.UpdateRegistryFromResource(_T(#x),bRegister,parme);	\
		CoTaskMemFree(parme);												\
		return (hrRes);														\
	}

// inetsrv\iis\svcs\nntp\server\seo\utest\stdafx.h
#define DECLARE_REGISTRY_RESOURCEID_EX(x,desc,progid,viprogid)			\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {				\
		HRESULT hrRes;													\
		_ATL_REGMAP_ENTRY *parme;										\
																		\
		hrRes = AtlAllocRegMapEx(&parme,								\
								 &GetObjectCLSID(),						\
								 &_Module,								\
								 NULL,									\
								 L"DESCRIPTION",						\
								 desc,									\
								 L"PROGID",								\
								 progid,								\
								 L"VIPROGID",							\
								 viprogid,								\
								 L"THREADINGMODEL",						\
								 ATL_THREADING_MODEL_VALUE,				\
								 NULL,									\
								 NULL);									\
		if (!SUCCEEDED(hrRes)) {										\
			return (hrRes);												\
		}																\
		hrRes = _Module.UpdateRegistryFromResource(x,bRegister,parme);	\
		CoTaskMemFree(parme);											\
		return (hrRes);													\
	}
#define DECLARE_REGISTRY_RESOURCE_EX(x,desc,progid,viprogid)				\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {					\
		HRESULT hrRes;														\
		_ATL_REGMAP_ENTRY *parme;											\
																			\
		hrRes = AtlAllocRegMapEx(&parme,									\
								 &GetObjectCLSID(),							\
								 &_Module,									\
								 NULL,										\
								 L"DESCRIPTION",							\
								 desc,										\
								 L"PROGID",									\
								 progid,									\
								 L"VIPROGID",								\
								 viprogid,									\
								 L"THREADINGMODEL",							\
								 ATL_THREADING_MODEL_VALUE,					\
								 NULL,										\
								 NULL);										\
		if (!SUCCEEDED(hrRes)) {											\
			return (hrRes);													\
		}																	\
		hrRes = _Module.UpdateRegistryFromResource(_T(#x),bRegister,parme);	\
		CoTaskMemFree(parme);												\
		return (hrRes);														\
	}

// inetsrv\iis\svcs\staxcore\seo\lib\stdafx.h
#define DECLARE_REGISTRY_RESOURCEID_EX(x,desc,progid,viprogid)			\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {				\
		HRESULT hrRes;													\
		_ATL_REGMAP_ENTRY *parme;										\
																		\
		hrRes = AtlAllocRegMapEx(&parme,								\
								 &GetObjectCLSID(),						\
								 &_Module,								\
								 NULL,									\
								 L"DESCRIPTION",						\
								 desc,									\
								 L"PROGID",								\
								 progid,								\
								 L"VIPROGID",							\
								 viprogid,								\
								 L"THREADINGMODEL",						\
								 ATL_THREADING_MODEL_VALUE,				\
								 NULL,									\
								 NULL);									\
		if (!SUCCEEDED(hrRes)) {										\
			return (hrRes);												\
		}																\
		hrRes = _Module.UpdateRegistryFromResource(x,bRegister,parme);	\
		CoTaskMemFree(parme);											\
		return (hrRes);													\
	}
#define DECLARE_REGISTRY_RESOURCE_EX(x,desc,progid,viprogid)				\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {					\
		HRESULT hrRes;														\
		_ATL_REGMAP_ENTRY *parme;											\
																			\
		hrRes = AtlAllocRegMapEx(&parme,									\
								 &GetObjectCLSID(),							\
								 &_Module,									\
								 NULL,										\
								 L"DESCRIPTION",							\
								 desc,										\
								 L"PROGID",									\
								 progid,									\
								 L"VIPROGID",								\
								 viprogid,									\
								 L"THREADINGMODEL",							\
								 ATL_THREADING_MODEL_VALUE,					\
								 NULL,										\
								 NULL);										\
		if (!SUCCEEDED(hrRes)) {											\
			return (hrRes);													\
		}																	\
		hrRes = _Module.UpdateRegistryFromResource(_T(#x),bRegister,parme);	\
		CoTaskMemFree(parme);												\
		return (hrRes);														\
	}

// inetsrv\iis\svcs\staxcore\seo\stdafx.h
#define DECLARE_REGISTRY_RESOURCEID_EX(x,desc,progid,viprogid)			\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {				\
		HRESULT hrRes;													\
		_ATL_REGMAP_ENTRY *parme;										\
																		\
		hrRes = AtlAllocRegMapEx(&parme,								\
								 &GetObjectCLSID(),						\
								 &_Module,								\
								 NULL,									\
								 L"DESCRIPTION",						\
								 desc,									\
								 L"PROGID",								\
								 progid,								\
								 L"VIPROGID",							\
								 viprogid,								\
								 L"THREADINGMODEL",						\
								 ATL_THREADING_MODEL_VALUE,				\
								 NULL,									\
								 NULL);									\
		if (!SUCCEEDED(hrRes)) {										\
			return (hrRes);												\
		}																\
		hrRes = _Module.UpdateRegistryFromResource(x,bRegister,parme);	\
		CoTaskMemFree(parme);											\
		return (hrRes);													\
	}
#define DECLARE_REGISTRY_RESOURCE_EX(x,desc,progid,viprogid)				\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {					\
		HRESULT hrRes;														\
		_ATL_REGMAP_ENTRY *parme;											\
																			\
		hrRes = AtlAllocRegMapEx(&parme,									\
								 &GetObjectCLSID(),							\
								 &_Module,									\
								 NULL,										\
								 L"DESCRIPTION",							\
								 desc,										\
								 L"PROGID",									\
								 progid,									\
								 L"VIPROGID",								\
								 viprogid,									\
								 L"THREADINGMODEL",							\
								 ATL_THREADING_MODEL_VALUE,					\
								 NULL,										\
								 NULL);										\
		if (!SUCCEEDED(hrRes)) {											\
			return (hrRes);													\
		}																	\
		hrRes = _Module.UpdateRegistryFromResource(_T(#x),bRegister,parme);	\
		CoTaskMemFree(parme);												\
		return (hrRes);														\
	}

// inetsrv\iis\svcs\staxcore\seo\test\ddrop2\stdafx.h
#define DECLARE_REGISTRY_RESOURCEID_EX(x,desc,progid,viprogid)			\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {				\
		HRESULT hrRes;													\
		_ATL_REGMAP_ENTRY *parme;										\
																		\
		hrRes = AtlAllocRegMapEx(&parme,								\
								 &GetObjectCLSID(),						\
								 &_Module,								\
								 NULL,									\
								 L"DESCRIPTION",						\
								 desc,									\
								 L"PROGID",								\
								 progid,								\
								 L"VIPROGID",							\
								 viprogid,								\
								 L"THREADINGMODEL",						\
								 ATL_THREADING_MODEL_VALUE,				\
								 NULL,									\
								 NULL);									\
		if (!SUCCEEDED(hrRes)) {										\
			return (hrRes);												\
		}																\
		hrRes = _Module.UpdateRegistryFromResource(x,bRegister,parme);	\
		CoTaskMemFree(parme);											\
		return (hrRes);													\
	}
#define DECLARE_REGISTRY_RESOURCE_EX(x,desc,progid,viprogid)				\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {					\
		HRESULT hrRes;														\
		_ATL_REGMAP_ENTRY *parme;											\
																			\
		hrRes = AtlAllocRegMapEx(&parme,									\
								 &GetObjectCLSID(),							\
								 &_Module,									\
								 NULL,										\
								 L"DESCRIPTION",							\
								 desc,										\
								 L"PROGID",									\
								 progid,									\
								 L"VIPROGID",								\
								 viprogid,									\
								 L"THREADINGMODEL",							\
								 ATL_THREADING_MODEL_VALUE,					\
								 NULL,										\
								 NULL);										\
		if (!SUCCEEDED(hrRes)) {											\
			return (hrRes);													\
		}																	\
		hrRes = _Module.UpdateRegistryFromResource(_T(#x),bRegister,parme);	\
		CoTaskMemFree(parme);												\
		return (hrRes);														\
	}

// inetsrv\iis\svcs\staxcore\seo\test\ddrop\dll\stdafx.h
#define DECLARE_REGISTRY_RESOURCEID_EX(x,desc,progid,viprogid)			\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {				\
		HRESULT hrRes;													\
		_ATL_REGMAP_ENTRY *parme;										\
																		\
		hrRes = AtlAllocRegMapEx(&parme,								\
								 &GetObjectCLSID(),						\
								 &_Module,								\
								 NULL,									\
								 L"DESCRIPTION",						\
								 desc,									\
								 L"PROGID",								\
								 progid,								\
								 L"VIPROGID",							\
								 viprogid,								\
								 L"THREADINGMODEL",						\
								 ATL_THREADING_MODEL_VALUE,				\
								 NULL,									\
								 NULL);									\
		if (!SUCCEEDED(hrRes)) {										\
			return (hrRes);												\
		}																\
		hrRes = _Module.UpdateRegistryFromResource(x,bRegister,parme);	\
		CoTaskMemFree(parme);											\
		return (hrRes);													\
	}
#define DECLARE_REGISTRY_RESOURCE_EX(x,desc,progid,viprogid)				\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {					\
		HRESULT hrRes;														\
		_ATL_REGMAP_ENTRY *parme;											\
																			\
		hrRes = AtlAllocRegMapEx(&parme,									\
								 &GetObjectCLSID(),							\
								 &_Module,									\
								 NULL,										\
								 L"DESCRIPTION",							\
								 desc,										\
								 L"PROGID",									\
								 progid,									\
								 L"VIPROGID",								\
								 viprogid,									\
								 L"THREADINGMODEL",							\
								 ATL_THREADING_MODEL_VALUE,					\
								 NULL,										\
								 NULL);										\
		if (!SUCCEEDED(hrRes)) {											\
			return (hrRes);													\
		}																	\
		hrRes = _Module.UpdateRegistryFromResource(_T(#x),bRegister,parme);	\
		CoTaskMemFree(parme);												\
		return (hrRes);														\
	}

// inetsrv\iis\svcs\staxcore\seo\test\ddrop\exe\stdafx.h
#define DECLARE_REGISTRY_RESOURCEID_EX(x,desc,progid,viprogid)			\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {				\
		HRESULT hrRes;													\
		_ATL_REGMAP_ENTRY *parme;										\
																		\
		hrRes = AtlAllocRegMapEx(&parme,								\
								 &GetObjectCLSID(),						\
								 &_Module,								\
								 NULL,									\
								 L"DESCRIPTION",						\
								 desc,									\
								 L"PROGID",								\
								 progid,								\
								 L"VIPROGID",							\
								 viprogid,								\
								 L"THREADINGMODEL",						\
								 ATL_THREADING_MODEL_VALUE,				\
								 NULL,									\
								 NULL);									\
		if (!SUCCEEDED(hrRes)) {										\
			return (hrRes);												\
		}																\
		hrRes = _Module.UpdateRegistryFromResource(x,bRegister,parme);	\
		CoTaskMemFree(parme);											\
		return (hrRes);													\
	}
#define DECLARE_REGISTRY_RESOURCE_EX(x,desc,progid,viprogid)				\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {					\
		HRESULT hrRes;														\
		_ATL_REGMAP_ENTRY *parme;											\
																			\
		hrRes = AtlAllocRegMapEx(&parme,									\
								 &GetObjectCLSID(),							\
								 &_Module,									\
								 NULL,										\
								 L"DESCRIPTION",							\
								 desc,										\
								 L"PROGID",									\
								 progid,									\
								 L"VIPROGID",								\
								 viprogid,									\
								 L"THREADINGMODEL",							\
								 ATL_THREADING_MODEL_VALUE,					\
								 NULL,										\
								 NULL);										\
		if (!SUCCEEDED(hrRes)) {											\
			return (hrRes);													\
		}																	\
		hrRes = _Module.UpdateRegistryFromResource(_T(#x),bRegister,parme);	\
		CoTaskMemFree(parme);												\
		return (hrRes);														\
	}

// inetsrv\iis\svcs\staxcore\seo\test\seotlib\stdafx.h
#define DECLARE_REGISTRY_RESOURCEID_EX(x,desc,progid,viprogid)			\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {				\
		HRESULT hrRes;													\
		_ATL_REGMAP_ENTRY *parme;										\
																		\
		hrRes = AtlAllocRegMapEx(&parme,								\
								 &GetObjectCLSID(),						\
								 &_Module,								\
								 NULL,									\
								 L"DESCRIPTION",						\
								 desc,									\
								 L"PROGID",								\
								 progid,								\
								 L"VIPROGID",							\
								 viprogid,								\
								 L"THREADINGMODEL",						\
								 ATL_THREADING_MODEL_VALUE,				\
								 NULL,									\
								 NULL);									\
		if (!SUCCEEDED(hrRes)) {										\
			return (hrRes);												\
		}																\
		hrRes = _Module.UpdateRegistryFromResource(x,bRegister,parme);	\
		CoTaskMemFree(parme);											\
		return (hrRes);													\
	}
#define DECLARE_REGISTRY_RESOURCE_EX(x,desc,progid,viprogid)				\
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {					\
		HRESULT hrRes;														\
		_ATL_REGMAP_ENTRY *parme;											\
																			\
		hrRes = AtlAllocRegMapEx(&parme,									\
								 &GetObjectCLSID(),							\
								 &_Module,									\
								 NULL,										\
								 L"DESCRIPTION",							\
								 desc,										\
								 L"PROGID",									\
								 progid,									\
								 L"VIPROGID",								\
								 viprogid,									\
								 L"THREADINGMODEL",							\
								 ATL_THREADING_MODEL_VALUE,					\
								 NULL,										\
								 NULL);										\
		if (!SUCCEEDED(hrRes)) {											\
			return (hrRes);													\
		}																	\
		hrRes = _Module.UpdateRegistryFromResource(_T(#x),bRegister,parme);	\
		CoTaskMemFree(parme);												\
		return (hrRes);														\
	}

// inetsrv\iis\svcs\staxcore\setup\ndmgr.h
#define IResultData_SetDescBarText(This,DescText)	\
    (This)->lpVtbl -> SetDescBarText(This,DescText)
#define IResultDataPrivate_SetDescBarText(This,DescText)	\
    (This)->lpVtbl -> SetDescBarText(This,DescText)

// inetsrv\iis\svcs\w3\cisa\atl\atlcom.h
#define DECLARE_NOT_AGGREGATABLE(x) public:\
	typedef CComNoAggCreator< CComObject<x> > _CreatorClass;
#define DECLARE_AGGREGATABLE(x) public:\
	typedef CComAggCreator< CComObject<x>, CComAggObject<x> > _CreatorClass;
#define BEGIN_COM_MAP(x) public:\
	typedef x _atl_classtype;\
	HRESULT _InternalQueryInterface(REFIID iid, void** ppvObject)\
	{return InternalQueryInterface(this, _GetEntries(), iid, ppvObject);}\
	const _ATL_INTMAP_ENTRY* _GetEntries() {\
	static const _ATL_INTMAP_ENTRY _entries[] = {
#define COM_INTERFACE_ENTRY_TEAR_OFF(iid, x) {&iid, (DWORD)(_ATL_CREATORFUNC)CComSimpleCreator< CComTearOffObject<x, _atl_classtype> >::CreateInstance, _ATL_INTMAP_ENTRY::creator},
#define RAWOBJECT_ENTRY(iid, pf, p1, p2, id, dw) {&iid, pf, _T(p1), _T(p2), id, dw, NULL, (DWORD)0},
#define OBJECT_ENTRY(iid, class, p1, p2, id, dw) {&iid, (_ATL_CREATORFUNC)&(CComNoAggCreator< CComObject< CComClassFactory<class> > >::CreateInstance), _T(p1), _T(p2), id, dw, NULL, (DWORD)0},
#define FACTORYOBJECT_ENTRY(iid, factory, p1, p2, id, dw) {&iid, (_ATL_CREATORFUNC)&(CComNoAggCreator< CComObject< factory > >::CreateInstance), _T(p1), _T(p2), id, dw, NULL, (DWORD)0},
#define OBJECT_ENTRY(iid, class, p1, p2, id, dw) {&iid, (_ATL_CREATORFUNC)&(CComNoAggCreator< CComObjectNoLock< CComClassFactory<class> > >::CreateInstance), _T(p1), _T(p2), id, dw, NULL, (DWORD)0},
#define FACTORYOBJECT_ENTRY(iid, factory, p1, p2, id, dw) {&iid, (_ATL_CREATORFUNC)&(CComNoAggCreator< CComObjectNoLock< factory > >::CreateInstance), _T(p1), _T(p2), id, dw, NULL, (DWORD)0},
#define CONNECTION_POINT_ENTRY(x) &IID_##x,

// inetsrv\iis\svcs\w3\server\gip.h
#define IGlobalInterfaceTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IGlobalInterfaceTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IGlobalInterfaceTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IGlobalInterfaceTable_RevokeInterfaceFromGlobal(This,dwCookie)	\
    (This)->lpVtbl -> RevokeInterfaceFromGlobal(This,dwCookie)
#define IGlobalInterfaceTable_GetInterfaceFromGlobal(This,dwCookie,riid,ppv)	\
    (This)->lpVtbl -> GetInterfaceFromGlobal(This,dwCookie,riid,ppv)

// inetsrv\iis\svcs\wam\object\gip.h
#define IGlobalInterfaceTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IGlobalInterfaceTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IGlobalInterfaceTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IGlobalInterfaceTable_RevokeInterfaceFromGlobal(This,dwCookie)	\
    (This)->lpVtbl -> RevokeInterfaceFromGlobal(This,dwCookie)
#define IGlobalInterfaceTable_GetInterfaceFromGlobal(This,dwCookie,riid,ppv)	\
    (This)->lpVtbl -> GetInterfaceFromGlobal(This,dwCookie,riid,ppv)

// inetsrv\iis\ui\admin\comprop\inetprop.h
#define BEGIN_PARSE_META_RECORDS(dwNumEntries, pbMDData)\
{                                                       \
    METADATA_GETALL_RECORD * pAllRecords =              \
        (METADATA_GETALL_RECORD *)pbMDData;             \
    ASSERT(pAllRecords != NULL);                        \
                                                        \
    for (DWORD i = 0; i < dwNumEntries; ++i)            \
    {                                                   \
        METADATA_GETALL_RECORD * pRec = &pAllRecords[i];\
        switch(pRec->dwMDIdentifier)                    \
        {

// inetsrv\iis\ui\admin\mmc\ndmgr.h
#define IResultDataPrivate_SetDescBarText(This,DescText)    \
    (This)->lpVtbl -> SetDescBarText(This,DescText)
#define IScopeTree_GetIDFromPath(This,idStatic,pbPath,cbPath,pID)   \
    (This)->lpVtbl -> GetIDFromPath(This,idStatic,pbPath,cbPath,pID)
#define INodeCallback_GetPath(This,hNode,pnID,pbPath,pcbPath)   \
    (This)->lpVtbl -> GetPath(This,hNode,pnID,pbPath,pcbPath)

// inetsrv\iis\ui\itools\keyring\certcli.h
#define ICertConfig_GetField(This,strFieldName,pstrOut)	\
    (This)->lpVtbl -> GetField(This,strFieldName,pstrOut)

// inetsrv\msmq\published\inc\mqoai.h
#define IMSMQMessage_get_BodyLength(This,pcbBody)	\
    (This)->lpVtbl -> get_BodyLength(This,pcbBody)
#define IMSMQMessage2_get_BodyLength(This,pcbBody)	\
    (This)->lpVtbl -> get_BodyLength(This,pcbBody)
#define IMSMQMessage3_get_BodyLength(This,pcbBody)	\
    (This)->lpVtbl -> get_BodyLength(This,pcbBody)

// inetsrv\msmq\src\ac\win95\ntddk95.h
#define READ_PORT_BUFFER_USHORT(x, y, z) {                            \
    PUSHORT readBuffer = y;                                            \
    ULONG readCount;                                                  \
    for (readCount = 0; readCount < z; readCount++, readBuffer++) {   \
        *readBuffer = *(volatile USHORT * const)(x);                  \
    }                                                                 \
}
#define READ_PORT_BUFFER_ULONG(x, y, z) {                             \
    PULONG readBuffer = y;                                            \
    ULONG readCount;                                                  \
    for (readCount = 0; readCount < z; readCount++, readBuffer++) {   \
        *readBuffer = *(volatile ULONG * const)(x);                   \
    }                                                                 \
}
#define WRITE_PORT_BUFFER_USHORT(x, y, z) {                               \
    PUSHORT writeBuffer = y;                                              \
    ULONG writeCount;                                                     \
    for (writeCount = 0; writeCount < z; writeCount++, writeBuffer++) {   \
        *(volatile USHORT * const)(x) = *writeBuffer;                     \
        KeFlushWriteBuffer();                                             \
    }                                                                     \
}
#define WRITE_PORT_BUFFER_ULONG(x, y, z) {                                \
    PULONG writeBuffer = y;                                               \
    ULONG writeCount;                                                     \
    for (writeCount = 0; writeCount < z; writeCount++, writeBuffer++) {   \
        *(volatile ULONG * const)(x) = *writeBuffer;                      \
        KeFlushWriteBuffer();                                             \
    }                                                                     \
}
#define READ_PORT_BUFFER_USHORT(x, y, z) {                            \
    PUSHORT readBuffer = y;                                            \
    ULONG readCount;                                                  \
    for (readCount = 0; readCount < z; readCount++, readBuffer++) {   \
        *readBuffer = *(volatile USHORT * const)(x);                  \
    }                                                                 \
}
#define READ_PORT_BUFFER_ULONG(x, y, z) {                             \
    PULONG readBuffer = y;                                            \
    ULONG readCount;                                                  \
    for (readCount = 0; readCount < z; readCount++, readBuffer++) {   \
        *readBuffer = *(volatile ULONG * const)(x);                   \
    }                                                                 \
}
#define WRITE_PORT_BUFFER_USHORT(x, y, z) {                               \
    PUSHORT writeBuffer = y;                                              \
    ULONG writeCount;                                                     \
    for (writeCount = 0; writeCount < z; writeCount++, writeBuffer++) {   \
        *(volatile USHORT * const)(x) = *writeBuffer;                     \
        KeFlushWriteBuffer();                                             \
    }                                                                     \
}
#define WRITE_PORT_BUFFER_ULONG(x, y, z) {                                \
    PULONG writeBuffer = y;                                               \
    ULONG writeCount;                                                     \
    for (writeCount = 0; writeCount < z; writeCount++, writeBuffer++) {   \
        *(volatile ULONG * const)(x) = *writeBuffer;                      \
        KeFlushWriteBuffer();                                             \
    }                                                                     \
}
#define KeInitializeCallbackRecord(CallbackRecord) \
    (CallbackRecord)->State = BufferEmpty
#define HALDISPATCH     (&HalDispatchTable)

// inetsrv\msmq\src\activex\lib\utilx.h
#define GLOBALALLOC_MOVEABLE_NONDISCARD(cbBody) GlobalAlloc( \
                       GMEM_MOVEABLE | GMEM_NODISCARD, \
                       cbBody)

// inetsrv\query\filters\office\src\findfast\dmscp.h
#define FDbcsCpMac(cp) ((cp) == cpidMacSJIS || (cp) == cpidMacKSC || (cp) == cpidMacBIG5 || (cp) == cpidMacPRC)

// inetsrv\query\h\ciexcpt.hxx
# define IMPLEMENT_UNWIND(class)                                            \
                                                                            \
        void APINOT class::_ObjectUnwind(void * pthis)                      \
        {                                                                   \
            ((class *)pthis)->class::~class();                              \
        }                                                                   \
                                                                            \
        struct __Check##class                                               \
        {                                                                   \
            __Check##class()                                                \
            {                                                               \
                if ( (CUnwindable *)((class *)10) != (CUnwindable *)10 ||   \
                     (CVirtualUnwindable *)                                 \
                         ((class *)10) != (CVirtualUnwindable *)10 )        \
                {                                                           \
                    exDebugOut(( DEB_ERROR,                                 \
                                 "INVALID UNWINDABLE CLASS: %s.\n",         \
                                 #class ));                                 \
                }                                                           \
            }                                                               \
        };                                                                  \
                                                                            \
        __Check##class __check_except_##class;

// inetsrv\query\qutil\triplish\lex.cxx
#define yy_set_bol(at_bol) \
        { \
        if ( ! yy_current_buffer ) \
                yy_current_buffer = yy_create_buffer( YY_BUF_SIZE ); \
        yy_current_buffer->yy_at_bol = at_bol; \
        }

// inetsrv\query\web\ixsso\asp\asptlb.h
#define IRequest_get_TotalBytes(This,pcbTotal)	\
    (This)->lpVtbl -> get_TotalBytes(This,pcbTotal)
#define IResponse_get_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> get_Buffer(This,fIsBuffering)
#define IResponse_put_Buffer(This,fIsBuffering)	\
    (This)->lpVtbl -> put_Buffer(This,fIsBuffering)
#define IResponse_AppendToLog(This,bstrLogEntry)	\
    (This)->lpVtbl -> AppendToLog(This,bstrLogEntry)

// multimedia\danim\extinc\dxtmsft3.h
#define IHeightField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHeightField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHeightField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHeightField_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHeightField_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHeightField_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHeightField_get_Capabilities(This,pVal)	\
    (This)->lpVtbl -> get_Capabilities(This,pVal)
#define IHeightField_get_Progress(This,pVal)	\
    (This)->lpVtbl -> get_Progress(This,pVal)
#define IHeightField_put_Progress(This,newVal)	\
    (This)->lpVtbl -> put_Progress(This,newVal)
#define IHeightField_get_StepResolution(This,pVal)	\
    (This)->lpVtbl -> get_StepResolution(This,pVal)
#define IHeightField_get_Duration(This,pVal)	\
    (This)->lpVtbl -> get_Duration(This,pVal)
#define IHeightField_put_Duration(This,newVal)	\
    (This)->lpVtbl -> put_Duration(This,newVal)
#define IHeightField_get_Width(This,pVal)	\
    (This)->lpVtbl -> get_Width(This,pVal)
#define IHeightField_put_Width(This,newVal)	\
    (This)->lpVtbl -> put_Width(This,newVal)
#define IHeightField_get_Height(This,pVal)	\
    (This)->lpVtbl -> get_Height(This,pVal)
#define IHeightField_put_Height(This,newVal)	\
    (This)->lpVtbl -> put_Height(This,newVal)
#define IHeightField_get_Depth(This,pVal)	\
    (This)->lpVtbl -> get_Depth(This,pVal)
#define IHeightField_put_Depth(This,newVal)	\
    (This)->lpVtbl -> put_Depth(This,newVal)
#define IHeightField_get_Samples(This,pVal)	\
    (This)->lpVtbl -> get_Samples(This,pVal)
#define IHeightField_put_Samples(This,newVal)	\
    (This)->lpVtbl -> put_Samples(This,newVal)

// multimedia\danim\extinc\dxtrans.h
#define IDXTransform_GetObjectSize(This,pcbSize)	\
    (This)->lpVtbl -> GetObjectSize(This,pcbSize)
#define IDXSurfaceModifier_SetLookup(This,pLookupTable)	\
    (This)->lpVtbl -> SetLookup(This,pLookupTable)
#define IDXSurfaceModifier_GetLookup(This,ppLookupTable)	\
    (This)->lpVtbl -> GetLookup(This,ppLookupTable)
#define IDXSurface_GetObjectSize(This,pcbSize)	\
    (This)->lpVtbl -> GetObjectSize(This,pcbSize)
#define IDXLookupTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IDXLookupTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IDXLookupTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IDXLookupTable_GetGenerationId(This,pID)	\
    (This)->lpVtbl -> GetGenerationId(This,pID)
#define IDXLookupTable_IncrementGenerationId(This,bRefresh)	\
    (This)->lpVtbl -> IncrementGenerationId(This,bRefresh)
#define IDXLookupTable_GetObjectSize(This,pcbSize)	\
    (This)->lpVtbl -> GetObjectSize(This,pcbSize)
#define IDXLookupTable_GetTables(This,RedLUT,GreenLUT,BlueLUT,AlphaLUT)	\
    (This)->lpVtbl -> GetTables(This,RedLUT,GreenLUT,BlueLUT,AlphaLUT)
#define IDXLookupTable_IsChannelIdentity(This,pSampleBools)	\
    (This)->lpVtbl -> IsChannelIdentity(This,pSampleBools)
#define IDXLookupTable_GetIndexValues(This,Index,pSample)	\
    (This)->lpVtbl -> GetIndexValues(This,Index,pSample)
#define IDXLookupTable_ApplyTables(This,pSamples,cSamples)	\
    (This)->lpVtbl -> ApplyTables(This,pSamples,cSamples)

// multimedia\danim\src\daxctl\inc\webdc.h
#define IPersistTextStream_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)

// multimedia\danim\tools\x86\aactive\inc\msimusic.h
#define IAAEngine_AllocBand(This,ppBand)	\
    (This)->lpVtbl -> AllocBand(This,ppBand)

// multimedia\danim\tools\x86\java15\include\javadbg.h
#define IRemoteField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteField_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)
#define IRemoteField_GetKind(This,pfk)	\
    (This)->lpVtbl -> GetKind(This,pfk)
#define IRemoteField_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteField_GetModifiers(This,pulModifiers)	\
    (This)->lpVtbl -> GetModifiers(This,pulModifiers)
#define IEnumRemoteField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumRemoteField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumRemoteField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumRemoteField_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IEnumRemoteField_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumRemoteField_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)
#define IEnumRemoteField_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)
#define IJavaEnumRemoteField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IJavaEnumRemoteField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IJavaEnumRemoteField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IJavaEnumRemoteField_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IJavaEnumRemoteField_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IJavaEnumRemoteField_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)
#define IJavaEnumRemoteField_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)
#define IRemoteDataField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteDataField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteDataField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteDataField_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)
#define IRemoteDataField_GetKind(This,pfk)	\
    (This)->lpVtbl -> GetKind(This,pfk)
#define IRemoteDataField_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteDataField_GetModifiers(This,pulModifiers)	\
    (This)->lpVtbl -> GetModifiers(This,pulModifiers)
#define IRemoteMethodField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteMethodField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteMethodField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteMethodField_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)
#define IRemoteMethodField_GetKind(This,pfk)	\
    (This)->lpVtbl -> GetKind(This,pfk)
#define IRemoteMethodField_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteMethodField_GetModifiers(This,pulModifiers)	\
    (This)->lpVtbl -> GetModifiers(This,pulModifiers)
#define IRemoteMethodField_GetFields(This,ppEnum,ulKind,ulModifiers,lpcszName)	\
    (This)->lpVtbl -> GetFields(This,ppEnum,ulKind,ulModifiers,lpcszName)
#define IRemoteMethodField_SetBreakpoint(This,offPC)	\
    (This)->lpVtbl -> SetBreakpoint(This,offPC)
#define IRemoteMethodField_ClearBreakpoint(This,offPC)	\
    (This)->lpVtbl -> ClearBreakpoint(This,offPC)
#define IRemoteMethodField_GetLineInfo(This,ppEnum)	\
    (This)->lpVtbl -> GetLineInfo(This,ppEnum)
#define IRemoteMethodField_GetBytes(This,ppLockBytes)	\
    (This)->lpVtbl -> GetBytes(This,ppLockBytes)
#define IRemoteMethodField_GetScope(This,pField,poffStart,pcbScope)	\
    (This)->lpVtbl -> GetScope(This,pField,poffStart,pcbScope)
#define IRemoteMethodField_GetIndexedField(This,slot,offPC,ppField)	\
    (This)->lpVtbl -> GetIndexedField(This,slot,offPC,ppField)
#define IRemoteClassField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteClassField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteClassField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteClassField_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)
#define IRemoteClassField_GetKind(This,pfk)	\
    (This)->lpVtbl -> GetKind(This,pfk)
#define IRemoteClassField_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteClassField_GetModifiers(This,pulModifiers)	\
    (This)->lpVtbl -> GetModifiers(This,pulModifiers)
#define IRemoteClassField_GetFields(This,ppEnum,ulKind,ulModifiers,lpcszName)	\
    (This)->lpVtbl -> GetFields(This,ppEnum,ulKind,ulModifiers,lpcszName)
#define IRemoteClassField_GetFileName(This,ppszFileName)	\
    (This)->lpVtbl -> GetFileName(This,ppszFileName)
#define IRemoteClassField_GetSourceFileName(This,ppszSourceFileName)	\
    (This)->lpVtbl -> GetSourceFileName(This,ppszSourceFileName)
#define IRemoteClassField_GetSuperclass(This,ppSuperclass)	\
    (This)->lpVtbl -> GetSuperclass(This,ppSuperclass)
#define IRemoteClassField_GetInterfaces(This,ppEnum)	\
    (This)->lpVtbl -> GetInterfaces(This,ppEnum)
#define IRemoteClassField_GetConstantPoolItem(This,indexCP,ppCPBytes,plength)	\
    (This)->lpVtbl -> GetConstantPoolItem(This,indexCP,ppCPBytes,plength)
#define IRemoteClassObject_GetFieldObject(This,pField,ppFieldObject)	\
    (This)->lpVtbl -> GetFieldObject(This,pField,ppFieldObject)
#define IRemoteClassObject_GetDerivedMostType(This,ppDerivedMostField)	\
    (This)->lpVtbl -> GetDerivedMostType(This,ppDerivedMostField)

// multimedia\danim\tools\x86\java20\include\javadbg.h
#define IRemoteField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteField_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)
#define IRemoteField_GetKind(This,pfk)	\
    (This)->lpVtbl -> GetKind(This,pfk)
#define IRemoteField_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteField_GetModifiers(This,pulModifiers)	\
    (This)->lpVtbl -> GetModifiers(This,pulModifiers)
#define IEnumRemoteField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumRemoteField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumRemoteField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumRemoteField_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IEnumRemoteField_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumRemoteField_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)
#define IEnumRemoteField_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)
#define IJavaEnumRemoteField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IJavaEnumRemoteField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IJavaEnumRemoteField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IJavaEnumRemoteField_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IJavaEnumRemoteField_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IJavaEnumRemoteField_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)
#define IJavaEnumRemoteField_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)
#define IRemoteDataField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteDataField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteDataField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteDataField_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)
#define IRemoteDataField_GetKind(This,pfk)	\
    (This)->lpVtbl -> GetKind(This,pfk)
#define IRemoteDataField_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteDataField_GetModifiers(This,pulModifiers)	\
    (This)->lpVtbl -> GetModifiers(This,pulModifiers)
#define IRemoteMethodField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteMethodField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteMethodField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteMethodField_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)
#define IRemoteMethodField_GetKind(This,pfk)	\
    (This)->lpVtbl -> GetKind(This,pfk)
#define IRemoteMethodField_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteMethodField_GetModifiers(This,pulModifiers)	\
    (This)->lpVtbl -> GetModifiers(This,pulModifiers)
#define IRemoteMethodField_GetFields(This,ppEnum,ulKind,ulModifiers,lpcszName)	\
    (This)->lpVtbl -> GetFields(This,ppEnum,ulKind,ulModifiers,lpcszName)
#define IRemoteMethodField_SetBreakpoint(This,offPC)	\
    (This)->lpVtbl -> SetBreakpoint(This,offPC)
#define IRemoteMethodField_ClearBreakpoint(This,offPC)	\
    (This)->lpVtbl -> ClearBreakpoint(This,offPC)
#define IRemoteMethodField_GetLineInfo(This,ppEnum)	\
    (This)->lpVtbl -> GetLineInfo(This,ppEnum)
#define IRemoteMethodField_GetBytes(This,ppLockBytes)	\
    (This)->lpVtbl -> GetBytes(This,ppLockBytes)
#define IRemoteMethodField_GetScope(This,pField,poffStart,pcbScope)	\
    (This)->lpVtbl -> GetScope(This,pField,poffStart,pcbScope)
#define IRemoteMethodField_GetIndexedField(This,slot,offPC,ppField)	\
    (This)->lpVtbl -> GetIndexedField(This,slot,offPC,ppField)
#define IRemoteClassField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRemoteClassField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRemoteClassField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRemoteClassField_GetName(This,ppszName)	\
    (This)->lpVtbl -> GetName(This,ppszName)
#define IRemoteClassField_GetKind(This,pfk)	\
    (This)->lpVtbl -> GetKind(This,pfk)
#define IRemoteClassField_GetType(This,ppType)	\
    (This)->lpVtbl -> GetType(This,ppType)
#define IRemoteClassField_GetModifiers(This,pulModifiers)	\
    (This)->lpVtbl -> GetModifiers(This,pulModifiers)
#define IRemoteClassField_GetFields(This,ppEnum,ulKind,ulModifiers,lpcszName)	\
    (This)->lpVtbl -> GetFields(This,ppEnum,ulKind,ulModifiers,lpcszName)
#define IRemoteClassField_GetFileName(This,ppszFileName)	\
    (This)->lpVtbl -> GetFileName(This,ppszFileName)
#define IRemoteClassField_GetSourceFileName(This,ppszSourceFileName)	\
    (This)->lpVtbl -> GetSourceFileName(This,ppszSourceFileName)
#define IRemoteClassField_GetSuperclass(This,ppSuperclass)	\
    (This)->lpVtbl -> GetSuperclass(This,ppSuperclass)
#define IRemoteClassField_GetInterfaces(This,ppEnum)	\
    (This)->lpVtbl -> GetInterfaces(This,ppEnum)
#define IRemoteClassField_GetConstantPoolItem(This,indexCP,ppCPBytes,plength)	\
    (This)->lpVtbl -> GetConstantPoolItem(This,indexCP,ppCPBytes,plength)
#define IRemoteClassObject_GetFieldObject(This,pField,ppFieldObject)	\
    (This)->lpVtbl -> GetFieldObject(This,pField,ppFieldObject)
#define IRemoteClassObject_GetDerivedMostType(This,ppDerivedMostField)	\
    (This)->lpVtbl -> GetDerivedMostType(This,ppDerivedMostField)

// multimedia\directx\applicationmanager\scriptinterface\appmandispatch.h
#define IAppEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IAppEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IAppEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IAppEntry_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IAppEntry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IAppEntry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IAppEntry_get_Guid(This,pVal)	\
    (This)->lpVtbl -> get_Guid(This,pVal)
#define IAppEntry_put_Guid(This,newVal)	\
    (This)->lpVtbl -> put_Guid(This,newVal)
#define IAppEntry_get_CompanyName(This,pVal)	\
    (This)->lpVtbl -> get_CompanyName(This,pVal)
#define IAppEntry_put_CompanyName(This,newVal)	\
    (This)->lpVtbl -> put_CompanyName(This,newVal)
#define IAppEntry_get_Signature(This,pVal)	\
    (This)->lpVtbl -> get_Signature(This,pVal)
#define IAppEntry_put_Signature(This,newVal)	\
    (This)->lpVtbl -> put_Signature(This,newVal)
#define IAppEntry_get_VersionString(This,pVal)	\
    (This)->lpVtbl -> get_VersionString(This,pVal)
#define IAppEntry_put_VersionString(This,newVal)	\
    (This)->lpVtbl -> put_VersionString(This,newVal)
#define IAppEntry_get_LastUsedDate(This,pVal)	\
    (This)->lpVtbl -> get_LastUsedDate(This,pVal)
#define IAppEntry_get_InstallDate(This,pVal)	\
    (This)->lpVtbl -> get_InstallDate(This,pVal)
#define IAppEntry_get_Category(This,pVal)	\
    (This)->lpVtbl -> get_Category(This,pVal)
#define IAppEntry_put_Category(This,newVal)	\
    (This)->lpVtbl -> put_Category(This,newVal)
#define IAppEntry_get_State(This,pVal)	\
    (This)->lpVtbl -> get_State(This,pVal)
#define IAppEntry_put_State(This,newVal)	\
    (This)->lpVtbl -> put_State(This,newVal)
#define IAppEntry_get_SetupRootPath(This,pVal)	\
    (This)->lpVtbl -> get_SetupRootPath(This,pVal)
#define IAppEntry_get_ApplicationRootPath(This,pVal)	\
    (This)->lpVtbl -> get_ApplicationRootPath(This,pVal)
#define IAppEntry_put_ApplicationRootPath(This,newVal)	\
    (This)->lpVtbl -> put_ApplicationRootPath(This,newVal)
#define IAppEntry_get_EstimatedInstallKilobytes(This,pVal)	\
    (This)->lpVtbl -> get_EstimatedInstallKilobytes(This,pVal)
#define IAppEntry_put_EstimatedInstallKilobytes(This,newVal)	\
    (This)->lpVtbl -> put_EstimatedInstallKilobytes(This,newVal)
#define IAppEntry_get_ExecuteCmdLine(This,pVal)	\
    (This)->lpVtbl -> get_ExecuteCmdLine(This,pVal)
#define IAppEntry_put_ExecuteCmdLine(This,newVal)	\
    (This)->lpVtbl -> put_ExecuteCmdLine(This,newVal)
#define IAppEntry_get_DefaultSetupExeCmdLine(This,pVal)	\
    (This)->lpVtbl -> get_DefaultSetupExeCmdLine(This,pVal)
#define IAppEntry_put_DefaultSetupExeCmdLine(This,newVal)	\
    (This)->lpVtbl -> put_DefaultSetupExeCmdLine(This,newVal)
#define IAppEntry_get_DownsizeCmdLine(This,pVal)	\
    (This)->lpVtbl -> get_DownsizeCmdLine(This,pVal)
#define IAppEntry_put_DownsizeCmdLine(This,newVal)	\
    (This)->lpVtbl -> put_DownsizeCmdLine(This,newVal)
#define IAppEntry_get_ReInstallCmdLine(This,pVal)	\
    (This)->lpVtbl -> get_ReInstallCmdLine(This,pVal)
#define IAppEntry_put_ReInstallCmdLine(This,newVal)	\
    (This)->lpVtbl -> put_ReInstallCmdLine(This,newVal)
#define IAppEntry_get_UnInstallCmdLine(This,pVal)	\
    (This)->lpVtbl -> get_UnInstallCmdLine(This,pVal)
#define IAppEntry_put_UnInstallCmdLine(This,newVal)	\
    (This)->lpVtbl -> put_UnInstallCmdLine(This,newVal)
#define IAppEntry_get_SelfTestCmdLine(This,pVal)	\
    (This)->lpVtbl -> get_SelfTestCmdLine(This,pVal)
#define IAppEntry_put_SelfTestCmdLine(This,newVal)	\
    (This)->lpVtbl -> put_SelfTestCmdLine(This,newVal)
#define IAppEntry_get_TitleURL(This,pVal)	\
    (This)->lpVtbl -> get_TitleURL(This,pVal)
#define IAppEntry_put_TitleURL(This,newVal)	\
    (This)->lpVtbl -> put_TitleURL(This,newVal)
#define IAppEntry_get_DeveloperURL(This,pVal)	\
    (This)->lpVtbl -> get_DeveloperURL(This,pVal)
#define IAppEntry_put_DeveloperURL(This,newVal)	\
    (This)->lpVtbl -> put_DeveloperURL(This,newVal)
#define IAppEntry_get_PublisherURL(This,pVal)	\
    (This)->lpVtbl -> get_PublisherURL(This,pVal)
#define IAppEntry_put_PublisherURL(This,newVal)	\
    (This)->lpVtbl -> put_PublisherURL(This,newVal)
#define IAppEntry_get_XMLInfoFile(This,pVal)	\
    (This)->lpVtbl -> get_XMLInfoFile(This,pVal)
#define IAppEntry_put_XMLInfoFile(This,newVal)	\
    (This)->lpVtbl -> put_XMLInfoFile(This,newVal)
#define IAppEntry_Clear(This)	\
    (This)->lpVtbl -> Clear(This)
#define IAppEntry_InitializeInstall(This)	\
    (This)->lpVtbl -> InitializeInstall(This)
#define IAppEntry_FinalizeInstall(This)	\
    (This)->lpVtbl -> FinalizeInstall(This)
#define IAppEntry_InitializeDownsize(This)	\
    (This)->lpVtbl -> InitializeDownsize(This)
#define IAppEntry_FinalizeDownsize(This)	\
    (This)->lpVtbl -> FinalizeDownsize(This)
#define IAppEntry_InitializeReInstall(This)	\
    (This)->lpVtbl -> InitializeReInstall(This)
#define IAppEntry_FinalizeReInstall(This)	\
    (This)->lpVtbl -> FinalizeReInstall(This)
#define IAppEntry_InitializeUnInstall(This)	\
    (This)->lpVtbl -> InitializeUnInstall(This)
#define IAppEntry_FinalizeUnInstall(This)	\
    (This)->lpVtbl -> FinalizeUnInstall(This)
#define IAppEntry_InitializeSelfTest(This)	\
    (This)->lpVtbl -> InitializeSelfTest(This)
#define IAppEntry_FinalizeSelfTest(This)	\
    (This)->lpVtbl -> FinalizeSelfTest(This)
#define IAppEntry_Abort(This)	\
    (This)->lpVtbl -> Abort(This)
#define IAppEntry_Run(This,lRunFlags,newVal)	\
    (This)->lpVtbl -> Run(This,lRunFlags,newVal)
#define IAppEntry_AddAssociation(This,AssociationType,lpAppEntry)	\
    (This)->lpVtbl -> AddAssociation(This,AssociationType,lpAppEntry)
#define IAppEntry_RemoveAssociation(This,lAssociationType,lpAppEntry)	\
    (This)->lpVtbl -> RemoveAssociation(This,lAssociationType,lpAppEntry)
#define IAppEntry_EnumAssociationTypes(This,lAssociationIndex,lpAssociationType)	\
    (This)->lpVtbl -> EnumAssociationTypes(This,lAssociationIndex,lpAssociationType)
#define IAppEntry_EnumAssociationObjects(This,lAssociationIndex,lpAppEntry)	\
    (This)->lpVtbl -> EnumAssociationObjects(This,lAssociationIndex,lpAppEntry)
#define IAppEntry_GetTemporarySpace(This,lKilobytesRequired,strRootPath)	\
    (This)->lpVtbl -> GetTemporarySpace(This,lKilobytesRequired,strRootPath)
#define IAppEntry_RemoveTemporarySpace(This,strRootPath)	\
    (This)->lpVtbl -> RemoveTemporarySpace(This,strRootPath)
#define IAppEntry_EnumTemporarySpacePaths(This,lTempSpaceIndex,strRootPath)	\
    (This)->lpVtbl -> EnumTemporarySpacePaths(This,lTempSpaceIndex,strRootPath)
#define IAppEntry_EnumTemporarySpaceAllocations(This,lTempSpaceIndex,lTempSpaceKilobytes)	\
    (This)->lpVtbl -> EnumTemporarySpaceAllocations(This,lTempSpaceIndex,lTempSpaceKilobytes)
#define IAppEntry_get_RemovableKilobytes(This,pVal)	\
    (This)->lpVtbl -> get_RemovableKilobytes(This,pVal)
#define IAppEntry_put_RemovableKilobytes(This,newVal)	\
    (This)->lpVtbl -> put_RemovableKilobytes(This,newVal)
#define IAppEntry_get_NonRemovableKilobytes(This,pVal)	\
    (This)->lpVtbl -> get_NonRemovableKilobytes(This,pVal)
#define IAppEntry_put_NonRemovableKilobytes(This,newVal)	\
    (This)->lpVtbl -> put_NonRemovableKilobytes(This,newVal)
#define IAppManager_CreateApplicationEntry(This,lppAppEntry)	\
    (This)->lpVtbl -> CreateApplicationEntry(This,lppAppEntry)
#define IAppManager_GetApplicationInfo(This,lpAppEntry)	\
    (This)->lpVtbl -> GetApplicationInfo(This,lpAppEntry)
#define IAppManager_EnumApplications(This,lApplicationIndex,lpAppEntry)	\
    (This)->lpVtbl -> EnumApplications(This,lApplicationIndex,lpAppEntry)

// multimedia\directx\ddrawex\dx3inc\d3d.h
#define IDirect3DExecuteBuffer_Release(p)              (p)->lpVtbl->Release(p)

// multimedia\directx\ddrawex\dx6\d3d.h
#define IDirect3DExecuteBuffer_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DVertexBuffer_Release(p) (p)->lpVtbl->Release(p)

// multimedia\directx\ddrawex\dx6\dsound.h
#define IDirectSoundBuffer_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectSound3DBuffer_Release(p)                 (p)->lpVtbl->Release(p)
#define IDirectSoundCaptureBuffer_Release(p)                   (p)->lpVtbl->Release(p)

// multimedia\directx\ddrawex\vtable.cpp
#define FORWARD0(Interface, Name) \
STDMETHODIMP Interface##Name(Interface *pIntStruc) \
{	Interface * pReal = ((INTSTRUC_##Interface *)pIntStruc)->m_pRealInterface; \
	return pReal->lpVtbl->Name(pReal); }
#define FORWARD1(Interface, Name, p1) \
STDMETHODIMP Interface##Name(Interface *pIntStruc, p1 a) \
{	Interface * pReal = ((INTSTRUC_##Interface *)pIntStruc)->m_pRealInterface; \
	return pReal->lpVtbl->Name(pReal, a); }
#define FORWARD2(Interface, Name, p1, p2) \
STDMETHODIMP Interface##Name(Interface *pIntStruc, p1 a, p2 b) \
{	Interface * pReal = ((INTSTRUC_##Interface *)pIntStruc)->m_pRealInterface; \
	return pReal->lpVtbl->Name(pReal, a, b); }
#define FORWARD3(Interface, Name, p1, p2, p3) \
STDMETHODIMP Interface##Name(Interface *pIntStruc, p1 a, p2 b, p3 c) \
{	Interface * pReal = ((INTSTRUC_##Interface *)pIntStruc)->m_pRealInterface; \
	return pReal->lpVtbl->Name(pReal, a, b, c); }
#define FORWARD4(Interface, Name, p1, p2, p3, p4) \
STDMETHODIMP Interface##Name(Interface *pIntStruc, p1 a, p2 b, p3 c, p4 d) \
{	Interface * pReal = ((INTSTRUC_##Interface *)pIntStruc)->m_pRealInterface; \
	return pReal->lpVtbl->Name(pReal, a, b, c, d); }
#define FORWARD5(Interface, Name, p1, p2, p3, p4, p5) \
STDMETHODIMP Interface##Name(Interface *pIntStruc, p1 a, p2 b, p3 c, p4 d, p5 e) \
{	Interface * pReal = ((INTSTRUC_##Interface *)pIntStruc)->m_pRealInterface; \
	return pReal->lpVtbl->Name(pReal, a, b, c, d, e); }

// multimedia\directx\dplay\dnet\lobby\dplconset.cpp
#define DPF_MODNAME "CConnectionSettings::CopyToBuffer( BYTE *pbBuffer, DWORD *pdwBufferSize )"

// multimedia\directx\dxdiag\showinfo.cpp
#define IAMFilterData_ParseFilterData(This,rgbFilterData,cb,prgbRegFilter2) \
    (This)->lpVtbl -> ParseFilterData(This,rgbFilterData,cb,prgbRegFilter2)
#define IAMFilterData_CreateFilterData(This,prf2,prgbFilterData,pcb)    \
    (This)->lpVtbl -> CreateFilterData(This,prf2,prgbFilterData,pcb)

// multimedia\dshow\filters.ks\volctrl\setdev.h
#define IDeviceIoControl_KsControl(This,dwIoControlCode,lpInBuffer,nInBufferSize,lpOutBuffer,nOutBufferSize,lpBytesReturned)    \
    (This)->lpVtbl -> KsControl(This,dwIoControlCode,lpInBuffer,nInBufferSize,lpOutBuffer,nOutBufferSize,lpBytesReturned)

// multimedia\dshow\filters\asf\wmsdk\inc\wmsbuffer.h
#define INSSBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer2_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer2_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer2_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer2_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer2_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_GetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> GetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer2_SetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> SetSampleProperties(This,cbProperties,pbProperties)
#define IWMSBufferAllocator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IWMSBufferAllocator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IWMSBufferAllocator_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IWMSBufferAllocator_AllocateBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocateBuffer(This,dwMaxBufferSize,ppBuffer)

// multimedia\dshow\filters\asf\wmsdk\inc\wmsdkidl.h
#define IWMMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMVideoMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMInputMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMOutputMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMHeaderInfo_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMHeaderInfo_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)
#define IWMHeaderInfo_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMHeaderInfo2_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMHeaderInfo2_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)
#define IWMHeaderInfo2_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMHeaderInfo2_GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)	\
    (This)->lpVtbl -> GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)
#define IWMStreamConfig_GetBufferWindow(This,pmsBufferWindow)	\
    (This)->lpVtbl -> GetBufferWindow(This,pmsBufferWindow)
#define IWMStreamConfig_SetBufferWindow(This,msBufferWindow)	\
    (This)->lpVtbl -> SetBufferWindow(This,msBufferWindow)
#define IWMWriterAdvanced2_GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)
#define IWMWriterAdvanced2_SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)
#define IWMWriterPostViewCallback_AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext)
#define IWMWriterSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink2_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink2_GetFileSize(This,pcbFile)	\
    (This)->lpVtbl -> GetFileSize(This,pcbFile)
#define IWMWriterNetworkSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMReaderAdvanced_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced2_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced2_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced2_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering)
#define IWMReaderAdvanced2_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)
#define IWMReaderAdvanced2_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)
#define IWMReaderAdvanced2_StopBuffering(This)	\
    (This)->lpVtbl -> StopBuffering(This)
#define IWMReaderAllocatorEx_AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    (This)->lpVtbl -> AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)
#define IWMReaderAllocatorEx_AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    (This)->lpVtbl -> AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)
#define IWMReaderCallbackAdvanced_AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext)
#define IWMReaderCallbackAdvanced_AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext)
#define IWMDRMReader_SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)	\
    (This)->lpVtbl -> SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)
#define IWMDRMReader_GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)
#define IWMReaderNetworkConfig_GetBufferingTime(This,pcnsBufferingTime)	\
    (This)->lpVtbl -> GetBufferingTime(This,pcnsBufferingTime)
#define IWMReaderNetworkConfig_SetBufferingTime(This,cnsBufferingTime)	\
    (This)->lpVtbl -> SetBufferingTime(This,cnsBufferingTime)
#define IWMBackupRestoreProps_GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMBackupRestoreProps_GetPropByName(This,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetPropByName(This,pszName,pType,pValue,pcbLength)
#define IWMBackupRestoreProps_SetProp(This,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetProp(This,pszName,Type,pValue,cbLength)

// multimedia\dshow\filters\asf\wmsdk\inc\wmsecure.h
#define IWMSecureChannel_WMSC_AddSignature(This,pbCertSig,cbCertSig)	\
    (This)->lpVtbl -> WMSC_AddSignature(This,pbCertSig,cbCertSig)
#define IWMSecureChannel_WMSC_Encrypt(This,pbData,cbData)	\
    (This)->lpVtbl -> WMSC_Encrypt(This,pbData,cbData)
#define IWMSecureChannel_WMSC_Decrypt(This,pbData,cbData)	\
    (This)->lpVtbl -> WMSC_Decrypt(This,pbData,cbData)

// multimedia\dshow\filters\mixer\testmc2\videoacc.h
#define IAMVideoAcceleratorNotify_GetUncompSurfacesInfo(This,pGuid,pUncompBufferInfo)	\
    (This)->lpVtbl -> GetUncompSurfacesInfo(This,pGuid,pUncompBufferInfo)
#define IAMVideoAccelerator_GetCompBufferInfo(This,pGuid,pamvaUncompDataInfo,pdwNumTypesCompBuffers,pamvaCompBufferInfo)	\
    (This)->lpVtbl -> GetCompBufferInfo(This,pGuid,pamvaUncompDataInfo,pdwNumTypesCompBuffers,pamvaCompBufferInfo)
#define IAMVideoAccelerator_GetInternalCompBufferInfo(This,pdwNumTypesCompBuffers,pamvaCompBufferInfo)	\
    (This)->lpVtbl -> GetInternalCompBufferInfo(This,pdwNumTypesCompBuffers,pamvaCompBufferInfo)
#define IAMVideoAccelerator_GetBuffer(This,dwTypeIndex,dwBufferIndex,bReadOnly,ppBuffer,lpStride)	\
    (This)->lpVtbl -> GetBuffer(This,dwTypeIndex,dwBufferIndex,bReadOnly,ppBuffer,lpStride)
#define IAMVideoAccelerator_ReleaseBuffer(This,dwTypeIndex,dwBufferIndex)	\
    (This)->lpVtbl -> ReleaseBuffer(This,dwTypeIndex,dwBufferIndex)
#define IAMVideoAccelerator_Execute(This,dwFunction,lpPrivateInputData,cbPrivateInputData,lpPrivateOutputDat,cbPrivateOutputData,dwNumBuffers,pamvaBufferInfo)	\
    (This)->lpVtbl -> Execute(This,dwFunction,lpPrivateInputData,cbPrivateInputData,lpPrivateOutputDat,cbPrivateOutputData,dwNumBuffers,pamvaBufferInfo)
#define IAMVideoAccelerator_QueryRenderStatus(This,dwTypeIndex,dwBufferIndex,dwFlags)	\
    (This)->lpVtbl -> QueryRenderStatus(This,dwTypeIndex,dwBufferIndex,dwFlags)

// multimedia\dshow\filters\sbe\wmsdk\inc\wmsbuffer.h
#define INSSBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer2_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer2_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer2_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer2_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer2_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_GetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> GetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer2_SetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> SetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer3_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer3_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer3_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer3_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer3_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer3_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer3_GetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> GetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer3_SetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> SetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer3_SetProperty(This,guidBufferProperty,pvBufferProperty,dwBufferPropertySize)	\
    (This)->lpVtbl -> SetProperty(This,guidBufferProperty,pvBufferProperty,dwBufferPropertySize)
#define INSSBuffer3_GetProperty(This,guidBufferProperty,pvBufferProperty,pdwBufferPropertySize)	\
    (This)->lpVtbl -> GetProperty(This,guidBufferProperty,pvBufferProperty,pdwBufferPropertySize)
#define IWMSBufferAllocator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IWMSBufferAllocator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IWMSBufferAllocator_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IWMSBufferAllocator_AllocateBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocateBuffer(This,dwMaxBufferSize,ppBuffer)

// multimedia\dshow\filters\sbe\wmsdk\inc\wmsdkidl.h
#define IWMMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMVideoMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMInputMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMSyncReader_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)
#define IWMSyncReader_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)
#define IWMSyncReader_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMSyncReader_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMOutputMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMHeaderInfo_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMHeaderInfo_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)
#define IWMHeaderInfo_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMHeaderInfo2_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMHeaderInfo2_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)
#define IWMHeaderInfo2_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMHeaderInfo2_GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)	\
    (This)->lpVtbl -> GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)
#define IWMProfile3_GetBandwidthSharingCount(This,pcBS)	\
    (This)->lpVtbl -> GetBandwidthSharingCount(This,pcBS)
#define IWMStreamConfig_GetBufferWindow(This,pmsBufferWindow)	\
    (This)->lpVtbl -> GetBufferWindow(This,pmsBufferWindow)
#define IWMStreamConfig_SetBufferWindow(This,msBufferWindow)	\
    (This)->lpVtbl -> SetBufferWindow(This,msBufferWindow)
#define IWMStreamConfig2_GetBufferWindow(This,pmsBufferWindow)	\
    (This)->lpVtbl -> GetBufferWindow(This,pmsBufferWindow)
#define IWMStreamConfig2_SetBufferWindow(This,msBufferWindow)	\
    (This)->lpVtbl -> SetBufferWindow(This,msBufferWindow)
#define IWMStreamConfig2_AddDataUnitExtension(This,guidExtensionSystemID,cbExtensionDataSize,pbExtensionSystemInfo,cbExtensionSystemInfo)	\
    (This)->lpVtbl -> AddDataUnitExtension(This,guidExtensionSystemID,cbExtensionDataSize,pbExtensionSystemInfo,cbExtensionSystemInfo)
#define IWMStreamConfig2_GetDataUnitExtension(This,wDataUnitExtensionNumber,pguidExtensionSystemID,pcbExtensionDataSize,pbExtensionSystemInfo,pcbExtensionSystemInfo)	\
    (This)->lpVtbl -> GetDataUnitExtension(This,wDataUnitExtensionNumber,pguidExtensionSystemID,pcbExtensionDataSize,pbExtensionSystemInfo,pcbExtensionSystemInfo)
#define IWMMutualExclusion2_GetRecordCount(This,pwRecordCount)	\
    (This)->lpVtbl -> GetRecordCount(This,pwRecordCount)
#define IWMMutualExclusion2_AddRecord(This)	\
    (This)->lpVtbl -> AddRecord(This)
#define IWMMutualExclusion2_RemoveRecord(This,wRecordNumber)	\
    (This)->lpVtbl -> RemoveRecord(This,wRecordNumber)
#define IWMMutualExclusion2_GetRecordName(This,wRecordNumber,pwszRecordName,pcchRecordName)	\
    (This)->lpVtbl -> GetRecordName(This,wRecordNumber,pwszRecordName,pcchRecordName)
#define IWMMutualExclusion2_SetRecordName(This,wRecordNumber,pwszRecordName)	\
    (This)->lpVtbl -> SetRecordName(This,wRecordNumber,pwszRecordName)
#define IWMMutualExclusion2_AddStreamForRecord(This,wRecordNumber,wStreamNumber)	\
    (This)->lpVtbl -> AddStreamForRecord(This,wRecordNumber,wStreamNumber)
#define IWMMutualExclusion2_RemoveStreamForRecord(This,wRecordNumber,wStreamNumber)	\
    (This)->lpVtbl -> RemoveStreamForRecord(This,wRecordNumber,wStreamNumber)
#define IWMBandwidthSharing_GetBandwidth(This,pdwBitrate,pmsBufferWindow)	\
    (This)->lpVtbl -> GetBandwidth(This,pdwBitrate,pmsBufferWindow)
#define IWMBandwidthSharing_SetBandwidth(This,dwBitrate,msBufferWindow)	\
    (This)->lpVtbl -> SetBandwidth(This,dwBitrate,msBufferWindow)
#define IWMWriterAdvanced2_GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)
#define IWMWriterAdvanced2_SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)
#define IWMWriterAdvanced3_GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)
#define IWMWriterAdvanced3_SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)
#define IWMWriterPostViewCallback_AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext)
#define IWMWriterSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink2_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink2_GetFileSize(This,pcbFile)	\
    (This)->lpVtbl -> GetFileSize(This,pcbFile)
#define IWMWriterFileSinkDataUnit_GetPacketHeader(This,ppbPacketHeader,pcbLength)	\
    (This)->lpVtbl -> GetPacketHeader(This,ppbPacketHeader,pcbLength)
#define IWMWriterFileSinkDataUnit_GetPayloadHeader(This,dwPayloadNumber,ppbPayloadHeader,pcbLength)	\
    (This)->lpVtbl -> GetPayloadHeader(This,dwPayloadNumber,ppbPayloadHeader,pcbLength)
#define IWMWriterFileSinkDataUnit_GetPayloadData(This,dwPayloadNumber,ppbPayloadHeader,pcbPayloadHeader)	\
    (This)->lpVtbl -> GetPayloadData(This,dwPayloadNumber,ppbPayloadHeader,pcbPayloadHeader)
#define IWMWriterFileSink3_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink3_GetFileSize(This,pcbFile)	\
    (This)->lpVtbl -> GetFileSize(This,pcbFile)
#define IWMWriterFileSink3_SetUnbufferedIO(This,fUnbufferedIO,fRestrictMemUsage)	\
    (This)->lpVtbl -> SetUnbufferedIO(This,fUnbufferedIO,fRestrictMemUsage)
#define IWMWriterFileSink3_GetUnbufferedIO(This,pfUnbufferedIO)	\
    (This)->lpVtbl -> GetUnbufferedIO(This,pfUnbufferedIO)
#define IWMWriterNetworkSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMReaderAdvanced_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced2_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced2_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced2_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering)
#define IWMReaderAdvanced2_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)
#define IWMReaderAdvanced2_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)
#define IWMReaderAdvanced2_StopBuffering(This)	\
    (This)->lpVtbl -> StopBuffering(This)
#define IWMReaderAdvanced3_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced3_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced3_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering)
#define IWMReaderAdvanced3_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)
#define IWMReaderAdvanced3_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)
#define IWMReaderAdvanced3_StopBuffering(This)	\
    (This)->lpVtbl -> StopBuffering(This)
#define IWMReaderAllocatorEx_AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    (This)->lpVtbl -> AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)
#define IWMReaderAllocatorEx_AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    (This)->lpVtbl -> AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)
#define IWMReaderCallbackAdvanced_AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext)
#define IWMReaderCallbackAdvanced_AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext)
#define IWMDRMReader_SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)	\
    (This)->lpVtbl -> SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)
#define IWMDRMReader_GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)
#define IWMReaderNetworkConfig_GetBufferingTime(This,pcnsBufferingTime)	\
    (This)->lpVtbl -> GetBufferingTime(This,pcnsBufferingTime)
#define IWMReaderNetworkConfig_SetBufferingTime(This,cnsBufferingTime)	\
    (This)->lpVtbl -> SetBufferingTime(This,cnsBufferingTime)
#define IWMBackupRestoreProps_GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMBackupRestoreProps_GetPropByName(This,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetPropByName(This,pszName,pType,pValue,pcbLength)
#define IWMBackupRestoreProps_SetProp(This,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetProp(This,pszName,Type,pValue,cbLength)

// multimedia\dshow\filters\sbe\wmsdk\inc\wmsdkidl2.h
#define IWMDRMWriter_SetDRMAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetDRMAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMWriterPushSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMReaderNetworkConfig2_GetBufferingTime(This,pcnsBufferingTime)	\
    (This)->lpVtbl -> GetBufferingTime(This,pcnsBufferingTime)
#define IWMReaderNetworkConfig2_SetBufferingTime(This,cnsBufferingTime)	\
    (This)->lpVtbl -> SetBufferingTime(This,cnsBufferingTime)

// multimedia\dshow\filters\tsdvr\wmsdk\inc\mswmdm.h
#define IWMDMDeviceControl_Record(This,pFormat)	\
    (This)->lpVtbl -> Record(This,pFormat)
#define IWMDMRevoked_GetRevocationURL(This,ppwszRevocationURL,pdwBufferLen,pdwRevokedBitFlag)	\
    (This)->lpVtbl -> GetRevocationURL(This,ppwszRevocationURL,pdwBufferLen,pdwRevokedBitFlag)
#define IMDSPDeviceControl_Record(This,pFormat)	\
    (This)->lpVtbl -> Record(This,pFormat)

// multimedia\dshow\filters\tsdvr\wmsdk\inc\wmsbuffer.h
#define INSSBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer2_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer2_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer2_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer2_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer2_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_GetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> GetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer2_SetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> SetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer3_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer3_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer3_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer3_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer3_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer3_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer3_GetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> GetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer3_SetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> SetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer3_SetProperty(This,guidBufferProperty,pvBufferProperty,dwBufferPropertySize)	\
    (This)->lpVtbl -> SetProperty(This,guidBufferProperty,pvBufferProperty,dwBufferPropertySize)
#define INSSBuffer3_GetProperty(This,guidBufferProperty,pvBufferProperty,pdwBufferPropertySize)	\
    (This)->lpVtbl -> GetProperty(This,guidBufferProperty,pvBufferProperty,pdwBufferPropertySize)
#define IWMSBufferAllocator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IWMSBufferAllocator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IWMSBufferAllocator_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IWMSBufferAllocator_AllocateBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocateBuffer(This,dwMaxBufferSize,ppBuffer)

// multimedia\dshow\filters\tsdvr\wmsdk\inc\wmsdkidl.h
#define IWMMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMVideoMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMInputMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMSyncReader_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)
#define IWMSyncReader_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)
#define IWMOutputMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMHeaderInfo_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMHeaderInfo_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)
#define IWMHeaderInfo_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMHeaderInfo2_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMHeaderInfo2_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)
#define IWMHeaderInfo2_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMHeaderInfo2_GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)	\
    (This)->lpVtbl -> GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)
#define IWMProfile3_GetBandwidthSharingCount(This,pcBS)	\
    (This)->lpVtbl -> GetBandwidthSharingCount(This,pcBS)
#define IWMStreamConfig_GetBufferWindow(This,pmsBufferWindow)	\
    (This)->lpVtbl -> GetBufferWindow(This,pmsBufferWindow)
#define IWMStreamConfig_SetBufferWindow(This,msBufferWindow)	\
    (This)->lpVtbl -> SetBufferWindow(This,msBufferWindow)
#define IWMStreamConfig2_GetBufferWindow(This,pmsBufferWindow)	\
    (This)->lpVtbl -> GetBufferWindow(This,pmsBufferWindow)
#define IWMStreamConfig2_SetBufferWindow(This,msBufferWindow)	\
    (This)->lpVtbl -> SetBufferWindow(This,msBufferWindow)
#define IWMStreamConfig2_AddDataUnitExtension(This,guidExtensionSystemID,cbExtensionDataSize,pbExtensionSystemInfo,cbExtensionSystemInfo)	\
    (This)->lpVtbl -> AddDataUnitExtension(This,guidExtensionSystemID,cbExtensionDataSize,pbExtensionSystemInfo,cbExtensionSystemInfo)
#define IWMStreamConfig2_GetDataUnitExtension(This,wDataUnitExtensionNumber,pguidExtensionSystemID,pcbExtensionDataSize,pbExtensionSystemInfo,pcbExtensionSystemInfo)	\
    (This)->lpVtbl -> GetDataUnitExtension(This,wDataUnitExtensionNumber,pguidExtensionSystemID,pcbExtensionDataSize,pbExtensionSystemInfo,pcbExtensionSystemInfo)
#define IWMMutualExclusion2_GetRecordCount(This,pwRecordCount)	\
    (This)->lpVtbl -> GetRecordCount(This,pwRecordCount)
#define IWMMutualExclusion2_AddRecord(This)	\
    (This)->lpVtbl -> AddRecord(This)
#define IWMMutualExclusion2_RemoveRecord(This,wRecordNumber)	\
    (This)->lpVtbl -> RemoveRecord(This,wRecordNumber)
#define IWMMutualExclusion2_GetRecordName(This,wRecordNumber,pwszRecordName,pcchRecordName)	\
    (This)->lpVtbl -> GetRecordName(This,wRecordNumber,pwszRecordName,pcchRecordName)
#define IWMMutualExclusion2_SetRecordName(This,wRecordNumber,pwszRecordName)	\
    (This)->lpVtbl -> SetRecordName(This,wRecordNumber,pwszRecordName)
#define IWMMutualExclusion2_AddStreamForRecord(This,wRecordNumber,wStreamNumber)	\
    (This)->lpVtbl -> AddStreamForRecord(This,wRecordNumber,wStreamNumber)
#define IWMMutualExclusion2_RemoveStreamForRecord(This,wRecordNumber,wStreamNumber)	\
    (This)->lpVtbl -> RemoveStreamForRecord(This,wRecordNumber,wStreamNumber)
#define IWMBandwidthSharing_GetBandwidth(This,pdwBitrate,pmsBufferWindow)	\
    (This)->lpVtbl -> GetBandwidth(This,pdwBitrate,pmsBufferWindow)
#define IWMBandwidthSharing_SetBandwidth(This,dwBitrate,msBufferWindow)	\
    (This)->lpVtbl -> SetBandwidth(This,dwBitrate,msBufferWindow)
#define IWMWriterAdvanced2_GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)
#define IWMWriterAdvanced2_SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)
#define IWMWriterAdvanced3_GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)
#define IWMWriterAdvanced3_SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)
#define IWMDRMWriter_SetDRMAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetDRMAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMWriterPostViewCallback_AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext)
#define IWMWriterSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink2_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink2_GetFileSize(This,pcbFile)	\
    (This)->lpVtbl -> GetFileSize(This,pcbFile)
#define IWMWriterFileSink3_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink3_GetFileSize(This,pcbFile)	\
    (This)->lpVtbl -> GetFileSize(This,pcbFile)
#define IWMWriterNetworkSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterPushSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMReaderAdvanced_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced2_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced2_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced2_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering)
#define IWMReaderAdvanced2_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)
#define IWMReaderAdvanced2_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)
#define IWMReaderAdvanced2_StopBuffering(This)	\
    (This)->lpVtbl -> StopBuffering(This)
#define IWMReaderAdvanced3_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced3_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced3_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering)
#define IWMReaderAdvanced3_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)
#define IWMReaderAdvanced3_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)
#define IWMReaderAdvanced3_StopBuffering(This)	\
    (This)->lpVtbl -> StopBuffering(This)
#define IWMReaderAllocatorEx_AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    (This)->lpVtbl -> AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)
#define IWMReaderAllocatorEx_AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    (This)->lpVtbl -> AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)
#define IWMReaderCallbackAdvanced_AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext)
#define IWMReaderCallbackAdvanced_AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext)
#define IWMDRMReader_SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)	\
    (This)->lpVtbl -> SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)
#define IWMDRMReader_GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)
#define IWMReaderNetworkConfig_GetBufferingTime(This,pcnsBufferingTime)	\
    (This)->lpVtbl -> GetBufferingTime(This,pcnsBufferingTime)
#define IWMReaderNetworkConfig_SetBufferingTime(This,cnsBufferingTime)	\
    (This)->lpVtbl -> SetBufferingTime(This,cnsBufferingTime)
#define IWMReaderNetworkConfig2_GetBufferingTime(This,pcnsBufferingTime)	\
    (This)->lpVtbl -> GetBufferingTime(This,pcnsBufferingTime)
#define IWMReaderNetworkConfig2_SetBufferingTime(This,cnsBufferingTime)	\
    (This)->lpVtbl -> SetBufferingTime(This,cnsBufferingTime)
#define IWMBackupRestoreProps_GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMBackupRestoreProps_GetPropByName(This,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetPropByName(This,pszName,pType,pValue,pcbLength)
#define IWMBackupRestoreProps_SetProp(This,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetProp(This,pszName,Type,pValue,cbLength)

// multimedia\dshow\h\fil_data.h
#define IAMFilterData_ParseFilterData(This,rgbFilterData,cb,prgbRegFilter2)	\
    (This)->lpVtbl -> ParseFilterData(This,rgbFilterData,cb,prgbRegFilter2)
#define IAMFilterData_CreateFilterData(This,prf2,prgbFilterData,pcb)	\
    (This)->lpVtbl -> CreateFilterData(This,prf2,prgbFilterData,pcb)

// multimedia\dshow\vidctl\atl\atlcom.h
#define PROP_ENTRY(szDesc, dispid, clsid) \
		{OLESTR(szDesc), dispid, &clsid, &IID_IDispatch, 0, 0, 0, &IID_NULL},
#define PROP_ENTRY_EX(szDesc, dispid, clsid, iidDispatch) \
		{OLESTR(szDesc), dispid, &clsid, &iidDispatch, 0, 0, 0, &IID_NULL},
#define DECLARE_PROTECT_FINAL_CONSTRUCT()\
	void InternalFinalConstructAddRef() {InternalAddRef();}\
	void InternalFinalConstructRelease() {InternalRelease();}
#define DECLARE_NOT_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComCreator< CComObject< x > >, CComFailCreator<CLASS_E_NOAGGREGATION> > _CreatorClass;
#define DECLARE_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComCreator< CComObject< x > >, CComCreator< CComAggObject< x > > > _CreatorClass;
#define DECLARE_ONLY_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComFailCreator<E_FAIL>, CComCreator< CComAggObject< x > > > _CreatorClass;
#define DECLARE_POLY_AGGREGATABLE(x) public:\
	typedef CComCreator< CComPolyObject< x > > _CreatorClass;
#define COM_INTERFACE_ENTRY_BREAK(x)\
	{&_ATL_IIDOF(x), \
	NULL, \
	_Break},
#define COM_INTERFACE_ENTRY_NOINTERFACE(x)\
	{&_ATL_IIDOF(x), \
	NULL, \
	_NoInterface},
#define COM_INTERFACE_ENTRY_IMPL(x)\
	COM_INTERFACE_ENTRY_IID(_ATL_IIDOF(x), x##Impl<_ComMapClass>)
#define COM_INTERFACE_ENTRY_IMPL_IID(iid, x)\
	COM_INTERFACE_ENTRY_IID(iid, x##Impl<_ComMapClass>)
#define COM_INTERFACE_ENTRY_FUNC(iid, dw, func)\
	{&iid, \
	dw, \
	func},
#define IMPLEMENTED_CATEGORY( catid ) { _ATL_CATMAP_ENTRY_IMPLEMENTED, &catid },
#define REQUIRED_CATEGORY( catid ) { _ATL_CATMAP_ENTRY_REQUIRED, &catid },
#define END_CATEGORY_MAP()\
   { _ATL_CATMAP_ENTRY_END, NULL } };\
   return( pMap ); }
#define OBJECT_ENTRY(clsid, class) {&clsid, class::UpdateRegistry, class::_ClassFactoryCreatorClass::CreateInstance, class::_CreatorClass::CreateInstance, NULL, 0, class::GetObjectDescription, class::GetCategoryMap, class::ObjectMain },
#define OBJECT_ENTRY_NON_CREATEABLE(class) {&CLSID_NULL, class::UpdateRegistry, NULL, NULL, NULL, 0, NULL, class::GetCategoryMap, class::ObjectMain },
#define END_EXTERN_OBJECT_MAP()   &NULL_OBJECT_ENTRY };
#define EXTERN_OBJECT_ENTRY(classname) &##classname##OBJMAP_ENTRY,
#define DEFINE_EXTERN_OBJECT_ENTRY(clsid, classname) \
   _ATL_OBJMAP_ENTRY classname##OBJMAP_ENTRY =    \
    {&clsid, classname::UpdateRegistry, classname::_ClassFactoryCreatorClass::CreateInstance, classname::_CreatorClass::CreateInstance, NULL, 0, classname::GetObjectDescription, classname::GetCategoryMap, classname::ObjectMain };
#define SERVICE_ENTRY(x) \
		if (InlineIsEqualGUID(guidService, x)) \
			return QueryInterface(riid, ppvObject);
#define BEGIN_SINK_MAP(_class)\
	static const _ATL_EVENT_ENTRY<_class>* _GetSinkMap()\
	{\
		typedef _class _atl_event_classtype;\
		static const _ATL_EVENT_ENTRY<_class> map[] = {

// multimedia\media\deluxe2\main\img.h
#define IImgCtx_Draw(This, hdc, prcBounds)		\
	(This)->lpVtbl -> Draw(This, hdc, prcBounds)

// multimedia\media\deluxecd\main\img.h
#define IImgCtx_Draw(This, hdc, prcBounds)		\
	(This)->lpVtbl -> Draw(This, hdc, prcBounds)

// multimedia\media\tools\extract\tags.h
#define T2_FLAGNAMERTN	14	// flag (for return) "name" field
#define T2_FLAGDESCRTN	15	// flag (for return) "desc" field
#define T2_REGNAMERTN	16	// register (for return) "name" field
#define T2_REGDESCRTN	17	// register (for return) "desc" field
#define T2_FLAGNAMEREGRTN 18	// flag (for register return) "name" field
#define T2_FLAGDESCREGRTN 19	// flag (for register return) "desc" field

// multimedia\media\winmm\mmiocf.h
#define MMIO_FINDDELETED        0x0080  // mmioCFFindEntry(): find deleted entry

// multimedia\published\wmsdk\inc\mswmdm.h
#define IWMDMDeviceControl_Record(This,pFormat)	\
    (This)->lpVtbl -> Record(This,pFormat)
#define IWMDMRevoked_GetRevocationURL(This,ppwszRevocationURL,pdwBufferLen,pdwRevokedBitFlag)	\
    (This)->lpVtbl -> GetRevocationURL(This,ppwszRevocationURL,pdwBufferLen,pdwRevokedBitFlag)
#define IMDSPDeviceControl_Record(This,pFormat)	\
    (This)->lpVtbl -> Record(This,pFormat)

// multimedia\published\wmsdk\inc\wmsbuffer.h
#define INSSBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer2_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer2_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer2_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer2_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer2_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_GetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> GetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer2_SetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> SetSampleProperties(This,cbProperties,pbProperties)
#define IWMSBufferAllocator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IWMSBufferAllocator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IWMSBufferAllocator_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IWMSBufferAllocator_AllocateBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocateBuffer(This,dwMaxBufferSize,ppBuffer)

// multimedia\published\wmsdk\inc\wmsdkidl.h
#define IWMMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMVideoMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMInputMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMOutputMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMHeaderInfo_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMHeaderInfo_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)
#define IWMHeaderInfo_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMHeaderInfo2_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMHeaderInfo2_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)
#define IWMHeaderInfo2_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMHeaderInfo2_GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)	\
    (This)->lpVtbl -> GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)
#define IWMStreamConfig_GetBufferWindow(This,pmsBufferWindow)	\
    (This)->lpVtbl -> GetBufferWindow(This,pmsBufferWindow)
#define IWMStreamConfig_SetBufferWindow(This,msBufferWindow)	\
    (This)->lpVtbl -> SetBufferWindow(This,msBufferWindow)
#define IWMWriterAdvanced2_GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)
#define IWMWriterAdvanced2_SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)
#define IWMWriterPostViewCallback_AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext)
#define IWMWriterSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink2_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink2_GetFileSize(This,pcbFile)	\
    (This)->lpVtbl -> GetFileSize(This,pcbFile)
#define IWMWriterNetworkSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMReaderAdvanced_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced2_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced2_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced2_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering)
#define IWMReaderAdvanced2_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)
#define IWMReaderAdvanced2_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)
#define IWMReaderAdvanced2_StopBuffering(This)	\
    (This)->lpVtbl -> StopBuffering(This)
#define IWMReaderAdvanced3_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced3_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced3_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering)
#define IWMReaderAdvanced3_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)
#define IWMReaderAdvanced3_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)
#define IWMReaderAdvanced3_StopBuffering(This)	\
    (This)->lpVtbl -> StopBuffering(This)
#define IWMReaderAllocatorEx_AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    (This)->lpVtbl -> AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)
#define IWMReaderAllocatorEx_AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    (This)->lpVtbl -> AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)
#define IWMReaderCallbackAdvanced_AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext)
#define IWMReaderCallbackAdvanced_AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext)
#define IWMDRMReader_SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)	\
    (This)->lpVtbl -> SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)
#define IWMDRMReader_GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)
#define IWMReaderNetworkConfig_GetBufferingTime(This,pcnsBufferingTime)	\
    (This)->lpVtbl -> GetBufferingTime(This,pcnsBufferingTime)
#define IWMReaderNetworkConfig_SetBufferingTime(This,cnsBufferingTime)	\
    (This)->lpVtbl -> SetBufferingTime(This,cnsBufferingTime)
#define IWMBackupRestoreProps_GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMBackupRestoreProps_GetPropByName(This,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetPropByName(This,pszName,pType,pValue,pcbLength)
#define IWMBackupRestoreProps_SetProp(This,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetProp(This,pszName,Type,pValue,cbLength)

// net\1394\arp\sys\rm.h
#define RM_NUM_ITEMS_IN_GROUP(_pGroup) \
            ((_pGroup)->HashTable.NumItems)

// net\1394\nic\sys\priv.h
#define nicIncChannelRecvBuffer()     NdisInterlockedIncrement(&NdisBufferAllocated[ChannelCodePath]);
#define nicIncFifoRecvBuffer()         NdisInterlockedIncrement(&NdisBufferAllocated[FifoCodePath]);
#define nicIncrementVcBusSendFailures(_Vc, _Pkt)        \
{                                                       \
    if ((_Vc)->Hdr.VcType == NIC1394_SendFIFO)          \
    {                                                   \
        nicIncrementFifoBusSendFailures(_Vc, _Pkt);     \
    }                                                   \
    else                                                \
    {                                                   \
        nicIncrementChannelBusSendFailures(_Vc, _Pkt);  \
    }                                                   \
}
#define nicIncrementVcBusSendSucess(_Vc, _Pkt)          \
{                                                       \
    if ((_Vc)->Hdr.VcType == NIC1394_SendFIFO)          \
    {                                                   \
        nicIncrementFifoBusSendSucess(_Vc, _Pkt);       \
    }                                                   \
    else                                                \
    {                                                   \
        nicIncrementChannelBusSendSucess(_Vc, _Pkt);    \
    }                                                   \
}

// net\atm\arp\atmarpc\macros.h
#define AA_INIT_IF_TABLE_LOCK(pIf)		\
				AA_INIT_LOCK(&((pIf)->ArpTableLock))
#define AA_ACQUIRE_IF_TABLE_LOCK(pIf)		\
				AA_ACQUIRE_LOCK(&((pIf)->ArpTableLock))
#define AA_ACQUIRE_IF_TABLE_LOCK_DPC(pIf)		\
				AA_ACQUIRE_LOCK_DPC(&((pIf)->ArpTableLock))
#define AA_INIT_AE_LOCK(pAtmEntry)		\
				AA_INIT_LOCK(&((pAtmEntry)->Lock))
#define AA_ACQUIRE_AE_LOCK(pAtmEntry)		\
				AA_ACQUIRE_LOCK(&((pAtmEntry)->Lock))
#define AA_ACQUIRE_AE_LOCK_DPC(pAtmEntry)		\
				AA_ACQUIRE_LOCK_DPC(&((pAtmEntry)->Lock))
#define AA_INIT_IE_LOCK(pIpEntry)		\
				AA_INIT_LOCK(&((pIpEntry)->Lock))
#define AA_ACQUIRE_IE_LOCK(pIpEntry)		\
				AA_ACQUIRE_LOCK(&((pIpEntry)->Lock))
#define AA_ACQUIRE_IE_LOCK_DPC(pIpEntry)		\
				AA_ACQUIRE_LOCK_DPC(&((pIpEntry)->Lock))

// net\atm\epvc\sys\rm.h
#define RM_NUM_ITEMS_IN_GROUP(_pGroup) \
            ((_pGroup)->HashTable.NumItems)

// net\atm\lane\sys\macros.h
#define INIT_HEADER_LOCK(pElan)		\
				INIT_LOCK(&((pElan)->HeaderBufferLock), "header")
#define INIT_HEADER_LOCK(pElan)		\
				INIT_LOCK(&((pElan)->HeaderBufferLock))
#define ACQUIRE_HEADER_LOCK(pElan)		\
				ACQUIRE_LOCK(&((pElan)->HeaderBufferLock), "header")
#define ACQUIRE_HEADER_LOCK(pElan)		\
				ACQUIRE_LOCK(&((pElan)->HeaderBufferLock))
#define ACQUIRE_HEADER_LOCK_DPC(pElan)		\
				ACQUIRE_LOCK_DPC(&((pElan)->HeaderBufferLock), "header")
#define ACQUIRE_HEADER_LOCK_DPC(pElan)		\
				ACQUIRE_LOCK_DPC(&((pElan)->HeaderBufferLock))
#define INIT_ELAN_MAC_TABLE_LOCK(pElan)		\
				INIT_LOCK(&((pElan)->MacTableLock), "mactable")
#define INIT_ELAN_MAC_TABLE_LOCK(pElan)		\
				INIT_LOCK(&((pElan)->MacTableLock))
#define ACQUIRE_ELAN_MAC_TABLE_LOCK(pElan)		\
				ACQUIRE_LOCK(&((pElan)->MacTableLock), "mactable")
#define ACQUIRE_ELAN_MAC_TABLE_LOCK(pElan)		\
				ACQUIRE_LOCK(&((pElan)->MacTableLock))
#define ACQUIRE_ELAN_MAC_TABLE_LOCK_DPC(pElan)		\
				ACQUIRE_LOCK_DPC(&((pElan)->MacTableLock), "mactable")
#define ACQUIRE_ELAN_MAC_TABLE_LOCK_DPC(pElan)		\
				ACQUIRE_LOCK_DPC(&((pElan)->MacTableLock))

// net\atm\rawwan\sys\macros.h
#define RWAN_INIT_CONN_TABLE_LOCK()		\
				RWAN_INIT_LOCK(&((pRWanGlobal)->ConnTableLock))
#define RWAN_ACQUIRE_CONN_TABLE_LOCK()		\
				RWAN_ACQUIRE_LOCK(&((pRWanGlobal)->ConnTableLock))

// net\atm\rawwan\tdi\macros.h
#define ATMSP_BLLI_PRESENT(_pBlli)		\
			( (((_pBlli)->Layer2Protocol != SAP_FIELD_ABSENT) &&	\
			   ((_pBlli)->Layer2Protocol != SAP_FIELD_ANY))			\
					 ||												\
			  (((_pBlli)->Layer3Protocol != SAP_FIELD_ABSENT) && 	\
			   ((_pBlli)->Layer3Protocol != SAP_FIELD_ANY))		\
			)
#define ATMSP_BHLI_PRESENT(_pBhli)		\
			(((_pBhli)->HighLayerInfoType != SAP_FIELD_ABSENT) &&	\
			 ((_pBhli)->HighLayerInfoType != SAP_FIELD_ANY))

// net\config\tools\ncbrowse\regexpr.h
#define STATIC_RPATTERN( var, params ) \
    STATIC_RPATTERN_EX( regex::rpattern, var, params )

// net\dlc\driver\dlcbuf.c
#define LOCK_BUFFER_POOL()      KeAcquireSpinLock(&pBufferPool->SpinLock, &irql)

// net\dlc\driver\dlcdef.h
#define BufGetUncommittedSpace(handle) \
    ((PDLC_BUFFER_POOL)(handle))->UncommittedSpace
#define BufCommitBuffers(handle, BufferSize) \
    ExInterlockedAddUlong( \
        (PULONG)&((PDLC_BUFFER_POOL)(handle))->UncommittedSpace, \
        (ULONG)(-((LONG)BufferSize)), \
        &(((PDLC_BUFFER_POOL)(handle))->SpinLock))
#define BufUncommitBuffers(handle, BufferSize) \
    ExInterlockedAddUlong(\
        (PULONG)&((PDLC_BUFFER_POOL)(handle))->UncommittedSpace,\
        (ULONG)(BufferSize),\
        &(((PDLC_BUFFER_POOL)(handle))->SpinLock))

// net\dlc\driver\llcapi.h
#define LlcGetCommittedSpace(hLink) \
    (((PDATA_LINK)(hLink))->BufferCommitment)

// net\inc\cxport.h
#define CTEClearSignal(Event)       KeResetEvent(&((Event)->cbs_event))

// net\inc\ipxfwtbl.h
#define AcquireInterfaceReference(ifCB) \
		InterlockedIncrement(&ifCB->ICB_ReferenceCount)

// net\inc\isnipx.h
#define OPEN_REQUEST_EA_INFORMATION(_Request) \
    ((PFILE_FULL_EA_INFORMATION)((_Request)->AssociatedIrp.SystemBuffer))
#define OPEN_REQUEST_RCV_LEN(_Request) \
    (((IoGetCurrentIrpStackLocation(_Request))->Parameters.DeviceIoControl.OutputBufferLength))

// net\inc\nic1394.h
    #define NIC1394_BUFFER_SIZE_FROM_LFBUFSZ(_lfbufsz) \
                            ((_lfbufz) & 0xfff)

// net\irda\irlap\irlapp.h
#define LINE_CAPACITY(icb)     (icb->RemoteWinSize * \
                               (icb->RemoteDataSize + \
                                6+icb->RemoteNumBOFS))

// net\jet500\jet\dae\inc\daedef.h
#define FLineNull(pline) \
	((pline) == NULL || (pline)->cb == 0 || (pline)->pb == NULL)
#define LineCopy(plineTo, plineFrom)								\
	{																\
	(plineTo)->cb = (plineFrom)->cb;								\
	memcpy((plineTo)->pb, (plineFrom)->pb, (plineFrom)->cb);		\
	}

// net\jet500\jet\dae\inc\dirapi.h
#define	DIRGetBookmark( pfucb, psrid )									\
	( *((SRID *)psrid) = PcsrCurrent( pfucb )->bm )
#define FDIRDataRootRoot( pfucb, pcsr )							\
	(	(pcsr)->pgno == PgnoRootOfPfucb( pfucb ) &&				\
		(pcsr)->itag == ItagRootOfPfucb( pfucb ) )
#define DIRDeferMoveFirst( pfucb )								\
	{															\
	PcsrCurrent( pfucb )->csrstat = csrstatDeferMoveFirst;		\
	DIRSetRefresh( pfucb );										\
	}

// net\jet500\jet\dae\inc\fcb.h
#define FFCBDenyDDL( pfcb, ppib )			( (pfcb)->crefDenyDDL > 0 && (ppib) != (pfcb)->ppibDDL )
#define FFCBDenyDDLByUs( pfcb, ppib )		( (pfcb)->crefDenyDDL > 0 && (ppib) == (pfcb)->ppibDDL )
#define	FFCBAvail( pfcb, ppib )							\
	(	pfcb->wRefCnt == 0 && 							\
		pfcb->pgnoFDP != 1 &&							\
		!FFCBSentinel( pfcb ) &&						\
		!FFCBDenyRead( pfcb, ppib ) &&					\
		!FFCBWait( pfcb ) &&							\
		( pfcb->dbid == dbidTemp || FFCBINoVersion( pfcb ) ) )

// net\jet500\jet\dae\inc\fucb.h
#define fFUCBNotReuse						( fFUCBDenyRead | fFUCBDenyWrite )
#define	PrepareInsert( pfucb )								\
	( (pfucb)->cbstat = fCBSTATInsert,						\
	  (pfucb)->levelPrep = (pfucb)->ppib->level )
#define	PrepareReplaceNoLock( pfucb )		  				\
	( (pfucb)->cbstat = fCBSTATReplace,						\
	  (pfucb)->levelPrep = (pfucb)->ppib->level )
#define	PrepareReplace( pfucb )		  						\
	( (pfucb)->cbstat = fCBSTATReplace | fCBSTATLock, 		\
	  (pfucb)->levelPrep = (pfucb)->ppib->level )
#define	PrepareSet( pfucb )									\
	( (pfucb)->cbstat = fCBSTATSet,							\
	  (pfucb)->levelPrep = (pfucb)->ppib->level )
#define	PrepareAppendItem( pfucb )							\
	( (pfucb)->cbstat = fCBSTATAppendItem )
#define FFUCBReplacePrepared( pfucb )								\
	( (pfucb)->cbstat & fCBSTATReplace )
#define FFUCBReplaceNoLockPrepared( pfucb )							\
	( !( (pfucb)->cbstat & fCBSTATLock ) &&							\
	FFUCBReplacePrepared( pfucb ) )
#define FFUCBInsertPrepared( pfucb )								\
	( (pfucb)->cbstat & fCBSTATInsert )
#define FFUCBSetPrepared( pfucb )									\
	( (pfucb)->cbstat != fCBSTATNull &&								\
	(pfucb)->levelPrep == (pfucb)->ppib->level )
#define FFUCBRetPrepared( pfucb )									\
	( (pfucb)->cbstat != fCBSTATNull )
#define	KSSetPrepare( pfucb )		( (pfucb)->ks |= ksPrepared )
#define KSSetTooBig( pfucb ) 		( (pfucb)->ks |= ksTooBig )
#define	FKSPrepared( pfucb ) 		( (pfucb)->ks & ksPrepared )
#define	FKSTooBig( pfucb )	  		( (pfucb)->ks & ksTooBig )
#define FUCBStore( pfucb )												\
	{																	\
	(pfucb)->csrstatStore = PcsrCurrent( pfucb )->csrstat;				\
	(pfucb)->bmStore = PcsrCurrent( pfucb )->bm;			 			\
	(pfucb)->itemStore = PcsrCurrent( pfucb )->item; 		 			\
	}
#define FUCBResetStore( pfucb )										\
	{																\
	(pfucb)->bmStore = 0;										 	\
	}

// net\jet500\jet\dae\inc\node.h
#define CbNDSon(pbNode) \
	( FNDNullSon(*(pbNode)) ? 0 : *PbNDSonTable(pbNode) )
#define FNDNonIntrinsicSons(pbNode)	( !FNDNullSon(*pbNode) && ( FNDVisibleSons(*pbNode) || CbNDSon(pbNode) > 1 ) )
#define FNDIntrinsicSons(pbNode)	( !FNDNullSon(*pbNode) && ( !FNDVisibleSons(*pbNode) || CbNDSon(pbNode) == 1 ) )
#define NDGet( pfucb, itagT )		PMGet( &(pfucb)->ssib, itagT )

// net\jet500\jet\dae\src\mcm.c
#define	FMCMRequired( pfucb, pfucbT )							\
	( FFUCBFull( pfucbT ) && pfucbT->dbid == pfucb->dbid && !( FFUCBSort( pfucbT ) ) )

// net\jet500\jet\jet\compact\comp.c
#define JETFUNC_TABLE_ITEM( _Func, _FuncI )    \
    {   (_Func), &(#_Func)[1], (_FuncI), NULL }

// net\jet500\jet\jet\inc\_jet.h
#define MarkTableidExported(err,tableid)		\
		if (err >= 0)							\
			MarkTableidExportedR(tableid)

// net\jet500\xjet\inc\_jet.h
#define MarkTableidExported(err,tableid)		\
		if (err >= 0)							\
			MarkTableidExportedR(tableid)

// net\jet500\xjet\inc\dirapi.h
#define	DIRGetBookmark( pfucb, psrid )									\
	( *((SRID *)psrid) = PcsrCurrent( pfucb )->bm )
#define FDIRDataRootRoot( pfucb, pcsr )								\
	(	(pcsr)->pgno == PgnoFDPOfPfucb( pfucb ) &&					\
		(pcsr)->itag == ItagRootOfPfucb( pfucb ) )
#define DIRDeferMoveFirst( pfucb )									\
	{																\
	PcsrCurrent( pfucb )->csrstat = csrstatDeferMoveFirst;			\
	DIRSetRefresh( pfucb );											\
	}
#define FFUCBRecordCursor( pfucb ) (						\
		( pfucb )->u.pfcb != pfcbNil ?						\
		FFCBClusteredIndex( ( pfucb )->u.pfcb ) : fFalse )

// net\jet500\xjet\inc\fcb.h
#define FFCBSystemTable( pfcb )									\
	( UtilCmpName( (pfcb)->szFileName, szScTable ) == 0    ||	\
		UtilCmpName( (pfcb)->szFileName, szSiTable ) == 0  ||	\
		UtilCmpName( (pfcb)->szFileName, szSoTable ) == 0 )
#define FFCBDomainDenyRead( pfcb, ppib )			( (pfcb)->fFCBDomainDenyRead && (ppib) != (pfcb)->ppibDomainDenyRead )
#define FFCBDomainDenyReadByUs( pfcb, ppib )	 	( (pfcb)->fFCBDomainDenyRead && (ppib) == (pfcb)->ppibDomainDenyRead )
#define FFCBWriteLatch( pfcb, ppib )		( (pfcb)->crefWriteLatch > 0 && (ppib) != (pfcb)->ppibWriteLatch )
#define FFCBWriteLatchByUs( pfcb, ppib )	( (pfcb)->crefWriteLatch > 0 && (ppib) == (pfcb)->ppibWriteLatch )
#define	FFCBAvail( pfcb, ppib )							\
	(	pfcb->wRefCnt == 0 && 							\
		pfcb->pgnoFDP != 1 &&							\
		!FFCBReadLatch( pfcb ) &&						\
		!FFCBSentinel( pfcb ) &&						\
		!FFCBDomainDenyRead( pfcb, ppib ) &&	 		\
		!FFCBWait( pfcb ) &&							\
		FFCBINoVersion( pfcb ) )

// net\jet500\xjet\inc\fdb.h
#define FIELDSetNotNull( field )		((field) |= ffieldNotNull)
#define FIELDResetNotNull( field )		((field) &= ~ffieldNotNull)
#define FFIELDNotNull( field )			((field) & ffieldNotNull)
#define FIELDSetVersion( field )		((field) |= ffieldVersion)
#define FIELDResetVersion( field )		((field) &= ~ffieldVersion)
#define FFIELDVersion( field )			((field) & ffieldVersion)
#define FIELDSetAutoInc( field )		((field) |= ffieldAutoInc)
#define FIELDResetAutoInc( field )		((field) &= ~ffieldAutoInc)
#define FFIELDAutoInc( field )			((field) & ffieldAutoInc)
#define FIELDSetMultivalue( field )		((field) |= ffieldMultivalue)
#define FIELDResetMultivalue( field ) 	((field) &= ~ffieldMultivalue)
#define FFIELDMultivalue( field )	  	((field) & ffieldMultivalue)
#define FIELDSetDefault( field )		((field) |= ffieldDefault)
#define FIELDResetDefault( field )		((field) &= ~ffieldDefault)
#define FFIELDDefault( field )			((field) & ffieldDefault)
#define FRECBinaryColumn( coltyp )	\
	( (coltyp) == JET_coltypBinary  ||  (coltyp) == JET_coltypLongBinary )
#define PfieldFDBVarFromFixed( pfdb, pfieldFixed )				\
	( pfieldFixed + (pfdb)->fidFixedLast + 1 - fidFixedLeast )
#define PfieldFDBTaggedFromVar( pfdb, pfieldVar )				\
	( pfieldVar + (pfdb)->fidVarLast + 1 - fidVarLeast )

// net\jet500\xjet\inc\fucb.h
#define FFUCBNotReuse( pfucb )				( (pfucb)->fDenyRead || (pfucb)->fDenyWrite )
#define	FFUCBGetBookmark( pfucb )						\
	( (pfucb)->fGetBookmark )
#define	FUCBSetGetBookmark( pfucb )						\
	( (pfucb)->fGetBookmark = 1 )
#define	FUCBResetGetBookmark( pfucb )					\
	( (pfucb)->fGetBookmark = 0 )
#define	PrepareInsert( pfucb )								\
	( (pfucb)->cbstat = fCBSTATInsert,						\
	  (pfucb)->levelPrep = (pfucb)->ppib->level )
#define	PrepareReplaceNoLock( pfucb )		  				\
	( (pfucb)->cbstat = fCBSTATReplace,						\
	  (pfucb)->levelPrep = (pfucb)->ppib->level )
#define	PrepareReplace( pfucb )		  						\
	( (pfucb)->cbstat = fCBSTATReplace | fCBSTATLock, 		\
	  (pfucb)->levelPrep = (pfucb)->ppib->level )
#define	PrepareAppendItem( pfucb )							\
	( (pfucb)->cbstat = fCBSTATAppendItem )
#define FFUCBReplacePrepared( pfucb )								\
	( (pfucb)->cbstat & fCBSTATReplace )
#define FFUCBReplaceNoLockPrepared( pfucb )							\
	( !( (pfucb)->cbstat & fCBSTATLock ) &&							\
	FFUCBReplacePrepared( pfucb ) )
#define FFUCBInsertPrepared( pfucb )								\
	( (pfucb)->cbstat & fCBSTATInsert )
#define FFUCBSetPrepared( pfucb )									\
	( ( (pfucb)->cbstat & (fCBSTATInsert|fCBSTATReplace) ) && 		\
	( (pfucb)->levelPrep <= (pfucb)->ppib->level ) )
#define FFUCBRetPrepared( pfucb )									\
	( (pfucb)->cbstat & (fCBSTATInsert|fCBSTATReplace) )
#define FFUCBUpdatePreparedLevel( pfucb, levelT ) 					\
	( ( (pfucb)->cbstat & (fCBSTATInsert|fCBSTATReplace) ) &&		\
		(pfucb)->levelPrep > (levelT) )
#define FFUCBUpdatePrepared( pfucb )								\
	( (pfucb)->cbstat & (fCBSTATInsert|fCBSTATReplace) )
#define	FUCBResetCbstat( pfucb )  									\
	( (pfucb)->cbstat = fCBSTATNull )
#define FFUCBAtPrepareLevel( pfucb )		   						\
	( (pfucb)->levelPrep == (pfucb)->ppib->level )
#define FFUCBDeferredUpdate( pfucb )								\
	( (pfucb)->cbstat == fCBSTATDeferredUpdate )
#define	KSSetPrepare( pfucb )		( (pfucb)->ks |= ksPrepared )
#define KSSetTooBig( pfucb ) 		( (pfucb)->ks |= ksTooBig )
#define	FKSPrepared( pfucb ) 		( (pfucb)->ks & ksPrepared )
#define	FKSTooBig( pfucb )	  		( (pfucb)->ks & ksTooBig )
#define FUCBStore( pfucb )											\
	{																\
	(pfucb)->csrstatStore = PcsrCurrent( pfucb )->csrstat;			\
	(pfucb)->bmStore = PcsrCurrent( pfucb )->bm;			 		\
	(pfucb)->itemStore = PcsrCurrent( pfucb )->item; 		 		\
	}
#define FUCBResetStore( pfucb )										\
	{																\
	(pfucb)->bmStore = 0;										 	\
	}

// net\jet500\xjet\inc\node.h
#define CbNDSon(pbNode) \
	( FNDNullSon(*(pbNode)) ? 0 : *PbNDSonTable(pbNode) )
#define FNDNonIntrinsicSons(pbNode)	( !FNDNullSon(*pbNode) && ( FNDVisibleSons(*pbNode) || CbNDSon(pbNode) > 1 ) )
#define FNDIntrinsicSons(pbNode)	( !FNDNullSon(*pbNode) && !FNDVisibleSons(*pbNode) && CbNDSon(pbNode) == 1 )
#define NDGet( pfucb, itagT )		PMGet( &(pfucb)->ssib, itagT )

// net\jet500\xjet\inc\recint.h
#define ErrRECIRetrieveDefaultValue( pfdb, pfid, plineField )	\
	ErrRECIRetrieveColumn( pfdb, &(pfdb)->lineDefaultRecord, pfid, NULL, 1, plineField, 0 )

// net\jet500\xjet\src\btsplit.c
#define	FMCMRequired( pfucb, pfucbT )							\
	( FFUCBFull( pfucbT ) && pfucbT->dbid == pfucb->dbid && !( FFUCBSort( pfucbT ) ) )

// net\mmc\dhcp\classed.h
#define HEM_SETBUFFER                   (WM_USER + 1)

// net\netbeui\kdext\nbfcom.h
#define PrintBool(_field) \
            PrintFieldName(#_field)  \
            dprintf("%-10s%s", (_obj._field) ? "True" : "False", EOL)
#define PrintLock(_field) \
            PrintFieldName(#_field)  \
            dprintf("( 0x%08lx ) %-10s%s", (_obj._field), (_obj._field) ? "Locked" : "UnLocked", EOL)

// net\netbt\kdext\kdextlib.c
#define NewLineForFields(FieldNo) \
        ((((FieldNo) % s_NoOfColumns) == 0) ? NewLine : FieldSeparator)

// net\nwlink\inc\isnnb.h
#define OPEN_REQUEST_EA_INFORMATION(_Request) \
    ((PFILE_FULL_EA_INFORMATION)((_Request)->AssociatedIrp.SystemBuffer))

// net\nwlink\spx\isnspx.h
#define REQUEST_TDI_BUFFER(_Request) \
    ((PVOID)((_Request)->MdlAddress))
#define OPEN_REQUEST_EA_INFORMATION(_Request) \
    ((PFILE_FULL_EA_INFORMATION)((_Request)->AssociatedIrp.SystemBuffer))

// net\nwlink\spx\spxconn.h
#define	END_PROCESS_PACKET(pSpxConnFile, fBuffered, fSuccess)					\
		{																		\
			SPX_CONN_RESETFLAG2(pSpxConnFile,									\
								(SPX_CONNFILE2_PKT |SPX_CONNFILE2_RENEGRECD));	\
			if (fSuccess)														\
			{																	\
				SPX_CONN_RESETFLAG2(pSpxConnFile, SPX_CONNFILE2_PKT_NOIND);		\
				SPX_SET_RECVNUM(pSpxConnFile, fBuffered);						\
			}																	\
		}
#define	SPX_SET_RECVNUM(pSpxConnFile, fBuffered)								\
		{																		\
			(pSpxConnFile)->scf_RecvSeqNum++;									\
			if (!fBuffered)														\
				(pSpxConnFile)->scf_SentAllocNum++;								\
		}

// net\qos\psched\netshell\diffserv\qos-netsh\qosp.h
#define GET_ENUM_TAG_VALUE()                                            \
        dwErr = MatchEnumTag(g_hModule,                                 \
                             pptcArguments[i + dwCurrentIndex],         \
                             NUM_TOKENS_IN_TABLE(rgEnums),              \
                             rgEnums,                                   \
                             &dwRes);                                   \
                                                                        \
        if (dwErr != NO_ERROR)                                          \
        {                                                               \
            DispTokenErrMsg(g_hModule,                                  \
                            EMSG_BAD_OPTION_VALUE,                      \
                            pttTags[pdwTagType[i]].pwszTag,             \
                            pptcArguments[i + dwCurrentIndex]);         \
                                                                        \
            DisplayMessage(g_hModule,                                   \
                           EMSG_BAD_OPTION_ENUMERATION,                 \
                           pttTags[pdwTagType[i]].pwszTag);             \
                                                                        \
            for ( j = 0; j < NUM_TOKENS_IN_TABLE(rgEnums); j++ )        \
            {                                                           \
                DisplayMessageT( L" %1!s!\n", rgEnums[j].pwszToken );   \
            }                                                           \
                                                                        \
            i = dwNumArg;                                               \
            dwErr = ERROR_SUPPRESS_OUTPUT;                              \
            break;                                                      \
        }                                                               \

// net\rras\cm\cmdial\ary.hxx
#define DECLARE_FORMS_STANDARD_IUNKNOWN(cls)                        \
    STDMETHOD(QueryInterface) (REFIID riid, LPVOID * ppv);          \
    ULONG _ulRefs;                                                  \
    STDMETHOD_(ULONG, AddRef) (void)                                \
        {                                                           \
            return ++_ulRefs;                                       \
        }                                                           \
    STDMETHOD_(ULONG, Release) (void)                               \
        {                                                           \
            if (--_ulRefs == 0)                                     \
            {                                                       \
                _ulRefs = ULREF_IN_DESTRUCTOR;                      \
                delete this;                                        \
                return 0;                                           \
            }                                                       \
            return _ulRefs;                                         \
        }                                                           \
    ULONG GetRefs(void)                                             \
        { return _ulRefs; }

// net\rras\inc\ipriprm.h
#define IPRIP_IF_ANNOUNCE_FILTER_TABLE(cfg) \
        ((PIPRIP_ROUTE_FILTER)( \
            IPRIP_IF_ACCEPT_FILTER_TABLE(cfg) + (cfg)->IC_AcceptFilterCount ))

// net\rras\ip\btpagnt\defs.h
#define GetAsnInteger(srcBuf,defVal)                        \
    (((srcBuf)->asnType)? ((srcBuf)->asnValue.number):(defVal))

// net\rras\ip\dvmrp\main.h
#define GET_IF_HASH_BUCKET(Index) \
    &G_pIfTable->IfHashTable[IF_HASH_VALUE(IfIndex)];
#define ACQUIRE_IF_LOCK_EXCLUSIVE(_IfIndex, _proc) \
        AcquireDynamicRWLock( \
            &G_pIfTable->aIfDRWL[IF_HASH_VALUE(_IfIndex)], \
            LOCK_MODE_WRITE, &Globals.DynamicRWLStore)
#define ACQUIRE_IF_LOCK_SHARED(_IfIndex, _proc) \
        AcquireDynamicRWLock( \
            &G_pIfTable->aIfDRWL[IF_HASH_VALUE(_IfIndex)],\
            LOCK_MODE_READ, &Globals.DynamicRWLStore)

// net\rras\ip\dvmrp\peer.h
#define ACQUIRE_PEER_LOCK_EXCLUSIVE(PeerEntry, _proc) \
        ACQUIRE_DYNAMIC_WRITE_LOCK( \
            &PeerEntry->DRWL, &Globals.DynamicRWLStore)
#define ACQUIRE_PEER_LOCK_SHARED(PeerEntry, _proc) \
        ACQUIRE_DYNAMIC_READ_LOCK( \
            &PeerEntry->DRWL, &Globals.DynamicRWLStore)

// net\rras\ip\igmp\macros.h
#define ACQUIRE_IF_LOCK_EXCLUSIVE(_IfIndex, _proc) \
        AcquireDynamicRWLock(&g_pIfTable->aIfBucketDRWL[IF_HASH_VALUE(_IfIndex)],\
                                LOCK_MODE_WRITE, \
                                &g_DynamicRWLStore)
#define ACQUIRE_IF_LOCK_SHARED(_IfIndex, _proc) \
        AcquireDynamicRWLock(&g_pIfTable->aIfBucketDRWL[IF_HASH_VALUE(_IfIndex)], \
                                LOCK_MODE_READ, \
                                &g_DynamicRWLStore)
#define PROXY_HASH_VALUE(_group) \
        (( ((_group)&0xFF000000)+((_group)&0xFF)) % (PROXY_HASH_TABLE_SZ))
#define GROUP_HASH_VALUE(_group) \
        (((_group) & 0xFF)%GROUP_HASH_TABLE_SZ)
#define RAS_HASH_VALUE(ClientAddr) \
    (((ClientAddr) & 0xFF)%(RAS_HASH_TABLE_SZ))

// net\rras\ip\igmp\table.h
#define GET_IF_CONFIG_FOR_SOURCE(pSourceEntry) \
    pSourceEntry->pGIEntry->pIfTableEntry->Config

// net\rras\ip\igmpagnt\defs.h
#define GET_ASN_INTEGER(srcBuf,defVal)                        \
    (((srcBuf)->asnType)? ((srcBuf)->asnValue.number):(defVal))

// net\rras\ip\ipinip\ipinip.h
#define GetIpHeader(X)  (PIP_HEADER)GetBufferFromPool(&((X)->HdrBufferPool))

// net\rras\ip\nat\entry.h
#define REFERENCE_NAT() \
    REFERENCE_COMPONENT(&ComponentReference)
#define DEREFERENCE_NAT() \
    DEREFERENCE_COMPONENT(&ComponentReference)

// net\rras\ip\nath323\h323asn1.h
#define	DECLARE_CODER_FUNCS(MODULE,STRUCTURE) \
/* static */ __inline DWORD MODULE ## EncodePdu_ ## STRUCTURE	\
	(STRUCTURE * PduStructure, OUT PUCHAR * ReturnBuffer, OUT PDWORD ReturnBufferLength)	\
	{ return MODULE ## EncodePdu (STRUCTURE ## _PDU, PduStructure, ReturnBuffer, ReturnBufferLength); }	\
/* static */ __inline DWORD MODULE ## DecodePdu_ ## STRUCTURE	\
	(IN PUCHAR Buffer, IN DWORD BufferLength, OUT STRUCTURE ** ReturnPduStructure)	\
	{ return MODULE ## DecodePdu (Buffer, BufferLength, STRUCTURE ## _PDU, (PVOID *) ReturnPduStructure); }	\
/* static */ __inline DWORD MODULE ## FreePdu_ ## STRUCTURE	\
	(IN STRUCTURE * PduStructure)	\
	{ return MODULE ## FreePdu (STRUCTURE ## _PDU, PduStructure); }

// net\rras\ip\rip\iprip.h
#define ACQUIRE_IF_LOCK_EXCLUSIVE() \
        AcquireWriteLock(&ig.IG_IfTable->IT_RWL)
#define ACQUIRE_IF_LOCK_SHARED() \
        AcquireReadLock(&ig.IG_IfTable->IT_RWL)
#define ACQUIRE_PEER_LOCK_EXCLUSIVE() \
        AcquireWriteLock(&ig.IG_PeerTable->PT_RWL)
#define ACQUIRE_PEER_LOCK_SHARED() \
        AcquireReadLock(&ig.IG_PeerTable->PT_RWL)
#define ACQUIRE_BINDING_LOCK_EXCLUSIVE() \
        AcquireWriteLock(&ig.IG_BindingTable->BT_RWL)
#define ACQUIRE_BINDING_LOCK_SHARED() \
        AcquireReadLock(&ig.IG_BindingTable->BT_RWL)

// net\rras\ip\rip\table.h
#define SETROUTEMETRIC(route, metric)   \
        (route)->RR_FamilySpecificData.FSD_Metric1 = (metric)
#define GETROUTEMETRIC(route)   \
        (route)->RR_FamilySpecificData.FSD_Metric1
#define COMPUTE_ROUTE_METRIC(route) \
        (route)->RR_FamilySpecificData.FSD_Metric = \
        (route)->RR_FamilySpecificData.FSD_Metric1

// net\rras\ip\ripagnt\defs.h
#define GetAsnInteger(srcBuf,defVal)                        \
    (((srcBuf)->asnType)? ((srcBuf)->asnValue.number):(defVal))

// net\rras\ip\rtrmgr\defs.h
#define READER_TO_WRITER(id)    RtlConvertSharedToExclusive(&(g_LockTable[(id)]))
#define ENTER_READER(id)        RtlAcquireResourceShared(&(g_LockTable[(id)]),TRUE)
#define ENTER_WRITER(id)        RtlAcquireResourceExclusive(&(g_LockTable[(id)]),TRUE)
#define WRITER_TO_READER(id)    RtlConvertExclusiveToShared(&(g_LockTable[(id)]))

// net\rras\ip\sample\hashtable.h
#define HT_Display(phtHashTable)                                    \
{                                                                   \
    if (phtHashTable)                                               \
        HT_MapCar(phtHashTable, phtHashTable->pfnDisplay);          \
}
#define HT_Size(phtHashTable)                           \
(                                                       \
    phtHashTable->ulNumEntries                          \
)

// net\rras\ipx\snmp\rtipxmib.h
#define GetAsnInteger(srcBuf,defVal)\
    (((srcBuf)->asnType)			\
		? (srcBuf)->asnValue.number	\
		: defVal)

// net\rras\mgm\ipmgm.h
#define ROUTE_TABLE_HASH( p )     \
        ( ( (p)-> RR_Network.N_NetNumber ) % ROUTE_TABLE_SIZE )
#define IF_BUCKET_HEAD( i )         &ig.pmllIfHashTable[ (i) ].leHead
#define ROUTE_BUCKET_HEAD( i )      &ig.pmllRouteHashTable[ (i) ].leHead
#define GROUP_BUCKET_HEAD( i )      &ig.pmllGrpHashTable[ (i) ].leHead
#define SOURCE_BUCKET_HEAD( a, b )  &(a)-> pleSrcHashTable[ (b) ]

// net\rras\ndis\ndiswan\wandefs.h
#define AcquireBundleLock(_pbcb)            \
    NdisAcquireSpinLock(&(_pbcb)->Lock)
#define REF_NDISWANCB()\
    InterlockedIncrement(&NdisWanCB.RefCount)
#define DEREF_NDISWANCB()   \
    NdisWanInterlockedDec(&NdisWanCB.RefCount)
#define REF_BUNDLECB(_pbcb)                                     \
{                                                               \
    (_pbcb)->RefCount++;                                        \
}
#define REF_OPENCB(_pocb)                                       \
    InterlockedIncrement(&(_pocb)->RefCount)
#define REF_CMVCCB(_pvccb)                                      \
    InterlockedIncrement(&(_pvccb)->RefCount)
#define DEREF_CMVCCB(_pvccb)                                    \
{                                                               \
    if (InterlockedDecrement(&(_pvccb)->RefCount) == 0) {       \
        DoDerefCmVcCBWork(_pvccb);                              \
    }                                                           \
}
#define REF_CLAFSAPCB(_pclaf)                                   \
    (_pclaf)->RefCount++;
#define BUNDLECB_FROM_LINKCB(_ppbcb, _plcb)                     \
{                                                               \
    *(_ppbcb) = (PBUNDLECB)_plcb->BundleCB;                     \
}
#define IsLinkSendWindowOpen(_plcb) \
    ((_plcb)->SendWindow > (_plcb)->OutstandingFrames)

// net\rras\ras\inc\srvauth.h
#define AUTH_STACK_NAME_TABLE_FULL     (FATAL_ERROR | 0x00000003)

// net\rras\ras\ui\inc\mem.h
#define GReAlloc(pv, cbNewSize) GlobalReAlloc(pv, cbNewSize, GMEM_MOVEABLE | GMEM_ZEROINIT)

// net\rras\rtm\rtmp.h
#define NetNumCmp(Table,Route1,Route2)	\
			(*Table->RT_Config.RPFC_NNcmp)(NNM(Route1),NNM(Route2))
#define FSDCmp(Table,Route1,Route2)	\
			(*Table->RT_Config.RPFC_FSDcmp)(Route1,Route2)
#define MetricCmp(Table,Route1,Route2) \
			(*Table->RT_Config.RPFC_RMcmp)(Route1,Route2)
#define EnterTableAPI(Table)										\
	((InterlockedIncrement(&(Table)->RT_APIclientCount)>0)			\
		? TRUE														\
		: (InterlockedDecrement (&(Table)->RT_APIclientCount), FALSE))
#define ExitTableAPI(Table)	\
	InterlockedDecrement(&(Table)->RT_APIclientCount)
#define HashFunction(Table,Net)	\
			(*Table->RT_Config.RPFC_Hash)(Net)

// net\rras\rtmv2\rtmregn.h
#define ACQUIRE_ROUTE_TABLE_READ_LOCK(AF)                    \
    ACQUIRE_READ_LOCK(&AF->RouteTableLock)
#define ACQUIRE_ROUTE_TABLE_WRITE_LOCK(AF)                   \
    ACQUIRE_WRITE_LOCK(&AF->RouteTableLock)

// net\sfm\afp\server\fileio.h
#define	FILEIO_OPEN_FILE_SEQ				(FILE_NON_DIRECTORY_FILE		|\
											 FILE_SEQUENTIAL_ONLY			|\
											 FILE_NO_INTERMEDIATE_BUFFERING	|\
											 FILE_SYNCHRONOUS_IO_NONALERT)

// net\sfm\afp\server\idindex.h
#define	HASH_DIR_ID(Id, _pVolDesc)		((Id) & ((_pVolDesc)->vds_DirHashTableSize-1))
#define	HASH_FILE_ID(Id, _pVolDesc)		((Id) & ((_pVolDesc)->vds_FileHashTableSize-1))

// net\sfm\atalk\sys\adsp.h
#define WRITECTX_TDI_BUFFER(_Request) \
    ((PVOID)(((PIRP)(_Request))->MdlAddress))

// net\snmp\subagent\lmmib2\mib.h
#define MIB_AGGREGATE          (MIB_TABLE | 0x0f)
#define MIB_ACTION_GETFIRST    (MIB_TABLE | 0x00)

// net\sockets\winsock2\ws2help\ws2help\nt\newctx.c
#define AcquireTableReaderLock(tbl,idx)                                 \
            idx = (InterlockedExchangeAdd ((LPLONG)&(tbl)->EnterCounter,2) & 1)

// net\sockets\winsock2\ws2help\ws2help\precomp.h
#define REALLOC_MEM(p,cb)   (LPVOID)GlobalReAlloc(                  \
                                (HGLOBAL)(p),                       \
                                (cb),                               \
                                (GMEM_MOVEABLE | GMEM_ZEROINIT)     \
                                )

// net\sockets\winsock2\wsp\afdsys\afdp.h
#define AFD_DATA_BUFFER_POOL_TAG        ( (ULONG)'BdfA' | PROTECTED_POOL )
#define AfdRecordOutstandingIrp(a,b,c) \
    (InterlockedIncrement(&((a)->OutstandingIrpCount)), TRUE)

// net\sockets\winsock2\wsp\afdsys\afdprocs.h
#define AfdRecordAddrOpened() InterlockedIncrement( &AfdHandleStats.AddrOpened )
#define AfdRecordAddrRef()    InterlockedIncrement( &AfdHandleStats.AddrRef )
#define AfdRecordAddrDeref()  InterlockedIncrement( &AfdHandleStats.AddrDeref )
#define AfdRecordConnOpened() InterlockedIncrement( &AfdHandleStats.ConnOpened )
#define AfdRecordConnRef()    InterlockedIncrement( &AfdHandleStats.ConnRef )
#define AfdRecordConnDeref()  InterlockedIncrement( &AfdHandleStats.ConnDeref )
#define AfdRecordFileRef()    InterlockedIncrement( &AfdHandleStats.FileRef )
#define AfdRecordFileDeref()  InterlockedIncrement( &AfdHandleStats.FileDeref )
#define AfdRecordConnectedReferencesAdded()      InterlockedIncrement( &AfdConnectionStats.ConnectedReferencesAdded )
#define AfdRecordGracefulDisconnectsInitiated()  InterlockedIncrement( &AfdConnectionStats.GracefulDisconnectsInitiated )
#define AfdRecordGracefulDisconnectsCompleted()  InterlockedIncrement( &AfdConnectionStats.GracefulDisconnectsCompleted )
#define AfdRecordGracefulDisconnectIndications() InterlockedIncrement( &AfdConnectionStats.GracefulDisconnectIndications )
#define AfdRecordAbortiveDisconnectsInitiated()  InterlockedIncrement( &AfdConnectionStats.AbortiveDisconnectsInitiated )
#define AfdRecordAbortiveDisconnectsCompleted()  InterlockedIncrement( &AfdConnectionStats.AbortiveDisconnectsCompleted )
#define AfdRecordAbortiveDisconnectIndications() InterlockedIncrement( &AfdConnectionStats.AbortiveDisconnectIndications )
#define AfdRecordConnectionIndications()         InterlockedIncrement( &AfdConnectionStats.ConnectionIndications )
#define AfdRecordConnectionsDropped()            InterlockedIncrement( &AfdConnectionStats.ConnectionsDropped )
#define AfdRecordConnectionsAccepted()           InterlockedIncrement( &AfdConnectionStats.ConnectionsAccepted )
#define AfdRecordConnectionsPreaccepted()        InterlockedIncrement( &AfdConnectionStats.ConnectionsPreaccepted )
#define AfdRecordConnectionsReused()             InterlockedIncrement( &AfdConnectionStats.ConnectionsReused )

// net\tapi\client\location.cpp
#define     SUITABLE_RULE(x)     \
    ( (pCard && pCardRuleSet->x && *(pCardRuleSet->x) ) ? \
       pCardRuleSet->x : pCountryRuleSet->x )

// net\tapi\skywalker\apps\avdialer\avwav\wav.h
#define WAV_FORMATALL		(WAV_FORMATFILE | WAV_FORMATPLAY | WAV_FORMATRECORD)

// net\tapi\skywalker\filters\video\tapivcap\thunk.c
#define poteExp(pinth) (&(pinth)->OptionalHeader. \
                          DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT])

// net\tapi\skywalker\h323\inc\icounter.h
#define IReport_CreateEntry(This,szName,dwIndex)	\
    (This)->lpVtbl -> CreateEntry(This,szName,dwIndex)

// net\tapi\thunk\windows.h
#define DCB_SET         (DCB_RESET | DCB_ACCUMULATE)
#define EM_EMPTYUNDOBUFFER      (WM_USER+29)
#define LBCB_CARETON            (WM_USER+36)    // ;Internal
#define LBCB_CARETOFF           (WM_USER+37)    // ;Internal
#define CB_FIRST_16             (WM_USER+0) // ;Internal
#define CB_GETEDITSEL           (WM_USER+0)
#define CB_SETEDITSEL           (WM_USER+2)
#define CB_DIR                  (WM_USER+5)
#define CB_GETCURSEL            (WM_USER+7)
#define CB_RESETCONTENT         (WM_USER+11)
#define CB_SETCURSEL            (WM_USER+14)
#define CB_SHOWDROPDOWN         (WM_USER+15)
#define CB_GETITEMDATA          (WM_USER+16)
#define CB_SETITEMDATA          (WM_USER+17)
#define CB_GETDROPPEDCONTROLRECT (WM_USER+18)
#define CB_SETITEMHEIGHT        (WM_USER+19)
#define CB_GETITEMHEIGHT        (WM_USER+20)
#define CB_GETDROPPEDSTATE      (WM_USER+23)
#define CB_SETLOCALE            (WM_USER+25)    /* ;Internal NT */
#define CB_GETLOCALE            (WM_USER+26)    /* ;Internal NT */
#define CB_FIRST_40             (WM_USER+27)    // ;Internal 4.0
#define CB_GETTOPINDEX          (WM_USER+27)    /* ;Internal 4.0 */
#define CB_SETTOPINDEX          (WM_USER+28)    /* ;Internal 4.0 */
#define CB_GETHORIZONTALEXTENT  (WM_USER+29)    /* ;Internal 4.0 */
#define CB_SETHORIZONTALEXTENT  (WM_USER+30)    /* ;Internal 4.0 */
#define CB_GETDROPPEDWIDTH      (WM_USER+31)    /* ;Internal 4.0 */
#define CB_SETDROPPEDWIDTH      (WM_USER+32)    /* ;Internal 4.0 */
#define CB_INITSTORAGE          (WM_USER+33)    /* ;Internal 4.0 */

// net\tcpip\apis\iphlpapi\dll\lanmap.h
#define LAN_GUID_HASH(pg)   \
    (((ULONG)((pg)->Data1 + *((ULONG *)(&((pg)->Data2))))) % LAN_HASH_TABLE_SIZE)

// net\tcpip\apis\iphlpapi\dll\rasmap.h
#define RAS_GUID_HASH(pg)   \
    (((ULONG)((pg)->Data1 + *((ULONG *)(&((pg)->Data2))))) % RAS_HASH_TABLE_SIZE)

// net\tcpip\driver\inc\tcp.h
#define DATA_RCV_STATE(s)   ((s) >= TCB_ESTAB && (s) <= TCB_FIN_WAIT2)
#define PENDING_ACTION(t)   ((t)->tcb_pending & DEL_PENDING)
#define CLOSING(t)  ((t)->tcb_pending & DEL_PENDING)

// net\tcpip\driver\ipv4\igmp.c
#define RECORD_MTU(NTE)  \
    (4 * (((NTE)->nte_if->if_mtu - TOTAL_HEADER_LENGTH) / 4))

// net\tcpip\driver\ipv4\ipdef.h
#define DEREFERENCE_IF(_a) \
    CTEInterlockedAddUlong(&(_a)->if_refcount, (ULONG) -1, &RouteTableLock.Lock);

// net\tcpip\driver\ipv4\lookup.h
#define GetDefaultGWs(_ppDefRoute_) \
            ((SearchRouteInTrie(RouteTable, 0, 0, 0, NULL, MATCH_NONE, \
                                _ppDefRoute_) == TRIE_SUCCESS) ? *(_ppDefRoute_) : NULL)

// net\tcpip\driver\kdext2\inc\tcpdump.h
#define Print_BOOLEAN(_p, _f) \
    PrintFieldName(#_f); \
    printx("%-10s" ENDL, _p->_f == TRUE ? "TRUE" : "FALSE")
#define Print_uint(_p, _f) \
    PrintFieldName(#_f); \
    printx("%-10lu" ENDL, _p->_f);
#define Print_uinthex(_p, _f) \
    PrintFieldName(#_f); \
    printx("0x%08lx" ENDL, _p->_f)
#define Print_int(_p, _f) \
    PrintFieldName(#_f); \
    printx("%-10d" ENDL, _p->_f);
#define Print_ulonghton(_p, _f) \
    PrintFieldName(#_f); \
    printx("%-10lu" ENDL, net_long(_p->_f));
#define Print_short(_p, _f) \
    PrintFieldName(#_f); \
    printx("%-10hd" ENDL, _p->_f);
#define Print_ushort(_p, _f) \
    PrintFieldName(#_f); \
    printx("%-10hu" ENDL, _p->_f);
#define Print_ushorthex(_p, _f) \
    PrintFieldName(#_f); \
    printx("0x%04lx" ENDL, _p->_f)
#define Print_ushorthton(_p, _f) \
    PrintFieldName(#_f); \
    printx("%-10hu" ENDL, net_short(_p->_f));
#define Print_Lock(_p, _f) \
    PrintFieldName(#_f); \
    printx("( 0x%08lx ) %-10s" ENDL, _p->_f, (_p->_f != 0) ? "Locked" : "UnLocked")
#define Print_LL(_p, _f) \
    PrintFieldName(#_f); \
    printx("Flink = %-10lx", _p->_f.Flink); \
    printx("Blink = %-10lx", _p->_f.Blink); \
    printx("%s", (_p->_f.Flink == &_p->_f) ? "[Empty]" : ""); \
    printx(ENDL)
#define Print_enum(_p, _f, _pes)        \
    PrintFieldName(#_f);                \
    printx("0x%08lx (",(ULONG) _p->_f); \
    DumpEnum((ULONG)_p->_f, _pes);      \
    printx(")" ENDL)
#define Print_sig(_p, _f)               \
    PrintFieldName(#_f);                \
    printx("%c%c%c%c" ENDL,             \
        EXPAND_TAG(_p->_f))
#define Print_CTEEvent(_p, _f)          \
    PrintFieldName(#_f);                \
    DumpCTEEvent(&_p->_f)
#define Print_KEVENT(_p, _f)            \
    PrintFieldName(#_f);                \
    DumpKEVENT(&_p->_f)
#define Print_SHARE_ACCESS(_p, _f)      \
    PrintFieldName(#_f);                \
    DumpSHARE_ACCESS(&_p->_f)
#define Print_hwaddr(_p, _f)            \
    PrintFieldName(#_f);                \
    printx("%2.2x-%2.2x-%2.2x-%2.2x-%2.2x-%2.2x" ENDL,    \
        EXPAND_HWADDR(_p->_f))

// net\tcpip\driver\kdext\tcpipext.h
#define PrintBool(_field) \
            PrintFieldName(#_field)  \
            dprintf("%-10s%s", (_obj._field) ? "True" : "False", EOL)
#define PrintLock(_field) \
            PrintFieldName(#_field)  \
            dprintf("( 0x%08lx ) %-10s%s", (_obj._field), (_obj._field) ? "Locked" : "UnLocked", EOL)

// net\tcpip\driver\tcp\tcb.h
#define TCB_HASH(DA,SA,DP,SP) (uint)(  ((uint)(ROR8( ROR8 (ROR8( *(ushort*)&(DP)+ \
*(ushort *)&(SP) ) + *(ushort *)&(DA)  )+ \
*((ushort *)&(DA)+1) ) ) ) & (TCB_TABLE_SIZE-1))

// net\tcpip\services\telnet\client\wintel.h
#define NN_OVERRUN      (WM_USER+402)  // internal buffer overrun

// net\tcpip\snmp\defs.h
#define GetAsnInteger(srcBuf,defVal)                        \
    (((srcBuf)->asnType)? ((srcBuf)->asnValue.number):(defVal))
#define EnterReader(id)       RtlAcquireResourceShared(&(g_LockTable[(id)]),TRUE)
#define EnterWriter(id)       RtlAcquireResourceExclusive(&(g_LockTable[(id)]),TRUE)

// net\tcpip\tpipv6\inc\ip6.h
#define OPT6_ISMUTABLE(t)  ((t) & OPT6_MUTABLE)

// net\tcpip\tpipv6\tcpip6\inc\route.h
#define SentinelRCE     ((RouteCacheEntry *)&RouteCache.First)
#define SentinelBCE     ((BindingCacheEntry *)&BindingCache.First)

// net\tcpip\tpipv6\tcpip6\inc\tcb.h
#define TCB_HASH(DA,SA,DP,SP) \
    (uint)(((uint)(ROR8(ROR8(ROR8(*(ushort *)&(DP) + \
                                  *(ushort *)&(SP)) + \
                             *(ushort *)&(DA)) + \
                        *((ushort *)&(DA) + 1)))) & \
           (TcbTableSize - 1))

// net\tcpip\tpipv6\tcpip6\inc\tcp.h
#define DATA_RCV_STATE(s) ((s) >= TCB_ESTAB && (s) <= TCB_FIN_WAIT2)
#define PENDING_ACTION(t) ((t)->tcb_pending & DEL_PENDING)
#define CLOSING(t) ((t)->tcb_pending & DEL_PENDING)

// net\unimodem\serialui\port.c
#define IDH_DEVMGR_PORTSET_ADV_USEFIFO  16885   // "&Use FIFO buffers (requires 16550 compatible UART)" (Button)

// net\unimodem\src\modemui\cpl.c
#define BUFFERQUERY_SUCCEEDED(f)    \
            ((f) || GetLastError() == ERROR_INSUFFICIENT_BUFFER)

// net\unimodem\src\sys\modem\mdm.h
#define UNI_ORIG_SYSTEM_BUFFER(Irp) \
    ((PVOID)((IoGetCurrentIrpStackLocation((Irp)))->Parameters.Others.Argument3))
#define UNI_SETUP_NEW_BUFFER(Irp) \
    do { \
        PIRP _irp = (Irp); \
        PIO_STACK_LOCATION _irpSp = IoGetCurrentIrpStackLocation(_irp); \
        _irpSp->Parameters.Others.Argument3 = _irp->AssociatedIrp.SystemBuffer; \
        _irp->AssociatedIrp.SystemBuffer = &_irpSp->Parameters.DeviceIoControl.Type3InputBuffer; \
    } while (0)

// printscan\fax\faxcover\src\dialogs.h
#define IDH_CB_DRAWBORDER       1144   // Line, Fill and Color: "&Draw border/line" (Button)

// printscan\fax\provider\t30\headers\buffers.h
#define ISVIEWATT(e)  (((e) == MMR_DATA) || ((e) == RAMBO_DATA))
#define ISOLEATT(e)   (((e) == OLE_DATA) || ((e) == OLE_PICTURE))

// printscan\fax\provider\t30\headers\glbproto.h
#define FComDirectSyncWriteFast(pTG, lpb,cb)  ((FComDirectWrite(pTG, lpb, cb)==cb) && FComDrain(pTG, FALSE,TRUE))

// printscan\fax\provider\t30\headers\mon.h
#       define INMON(pTG, lpb, cb) \
        (pTG->gMonInfo.fInited && MonPutComm(pTG, fMON_COMM_IN, lpb,cb))
#       define OUTMON(pTG, lpb, cb) \
        (pTG->gMonInfo.fInited && MonPutComm(pTG, fMON_COMM_OUT, lpb,cb))

// printscan\fax\setup\win9xupg\inc\buffers.h
#define ISVIEWATT(e)  (((e) == MMR_DATA) || ((e) == RAMBO_DATA))
#define ISOLEATT(e)   (((e) == OLE_DATA) || ((e) == OLE_PICTURE))

// printscan\faxsrv\src\faxbvt\faxsender\sendinfo.h
#define MyFaxEnumJobs(hServer, pBuffer, pCount) 	FaxEnumJobsEx((hServer), JT_UNKNOWN | JT_SEND | JT_RECEIVE, (pBuffer), (pCount))

// printscan\faxsrv\src\provider\t30\headers\buffers.h
#define ISVIEWATT(e)  (((e) == MMR_DATA) || ((e) == RAMBO_DATA))
#define ISOLEATT(e)   (((e) == OLE_DATA) || ((e) == OLE_PICTURE))

// printscan\faxsrv\src\provider\t30\headers\glbproto.h
#define FComDirectSyncWriteFast(pTG, lpb,cb)  ((FComDirectWrite(pTG, lpb, cb)==cb) && FComDrain(pTG, FALSE,TRUE))

// printscan\faxsrv\src\provider\t30\headers\mon.h
#       define INMON(pTG, lpb, cb) \
        (pTG->gMonInfo.fInited && MonPutComm(pTG, fMON_COMM_IN, lpb,cb))
#       define OUTMON(pTG, lpb, cb) \
        (pTG->gMonInfo.fInited && MonPutComm(pTG, fMON_COMM_OUT, lpb,cb))

// printscan\faxsrv\src\sdktools\msvc15\include\windows.h
#define DCB_SET 	(DCB_RESET | DCB_ACCUMULATE)
#define EM_EMPTYUNDOBUFFER      (WM_USER+29)
#define CB_GETEDITSEL	         (WM_USER+0)
#define CB_SETEDITSEL	         (WM_USER+2)
#define CB_DIR                   (WM_USER+5)
#define CB_GETCURSEL	         (WM_USER+7)
#define CB_RESETCONTENT	         (WM_USER+11)
#define CB_SETCURSEL	         (WM_USER+14)
#define CB_SHOWDROPDOWN          (WM_USER+15)
#define CB_GETITEMDATA           (WM_USER+16)
#define CB_SETITEMDATA           (WM_USER+17)
#define CB_GETDROPPEDCONTROLRECT (WM_USER+18)
#define CB_SETITEMHEIGHT         (WM_USER+19)
#define CB_GETITEMHEIGHT         (WM_USER+20)
#define CB_GETDROPPEDSTATE       (WM_USER+23)

// printscan\faxsrv\src\sdktools\msvc15\mfc\include\afxmsg_.h
#define ON_WM_CREATE() \
	{ WM_CREATE, 0, AfxSig_is, \
		(AFX_PMSG)(AFX_PMSGW)(int (AFX_MSG_CALL CWnd::*)(LPCREATESTRUCT))OnCreate },
#define ON_WM_DRAWITEM() \
	{ WM_DRAWITEM, 0, AfxSig_vOWNER, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(int, LPDRAWITEMSTRUCT))OnDrawItem },
#define ON_WM_MEASUREITEM() \
	{ WM_MEASUREITEM, 0, AfxSig_vOWNER, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(int, LPMEASUREITEMSTRUCT))OnMeasureItem },
#define ON_WM_DELETEITEM() \
	{ WM_DELETEITEM, 0, AfxSig_vOWNER, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(int, LPDELETEITEMSTRUCT))OnDeleteItem },
#define ON_WM_COMPAREITEM() \
	{ WM_COMPAREITEM, 0, AfxSig_iis, \
		(AFX_PMSG)(AFX_PMSGW)(int (AFX_MSG_CALL CWnd::*)(int, LPCOMPAREITEMSTRUCT))OnCompareItem },
#define ON_WM_NCCREATE() \
	{ WM_NCCREATE, 0, AfxSig_is, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(LPCREATESTRUCT))OnNcCreate },
#define ON_WM_ASKCBFORMATNAME() \
	{ WM_ASKCBFORMATNAME, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, LPSTR))OnAskCbFormatName },
#define ON_WM_CHANGECBCHAIN() \
	{ WM_CHANGECBCHAIN, 0, AfxSig_vhh, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(HWND, HWND))OnChangeCbChain },

// printscan\faxsrv\src\sdktools\msvc15\mfc\include\winres.h
#define CB_ADDSTRING    (WM_USER+3)

// printscan\faxsrv\src\setup\win9xupg\inc\buffers.h
#define ISVIEWATT(e)  (((e) == MMR_DATA) || ((e) == RAMBO_DATA))
#define ISOLEATT(e)   (((e) == OLE_DATA) || ((e) == OLE_PICTURE))

// printscan\faxsrv\src\test\inc\sendinfo.h
#define MyFaxEnumJobs(hServer, pBuffer, pCount) 	FaxEnumJobsEx((hServer), JT_UNKNOWN | JT_SEND | JT_RECEIVE, (pBuffer), (pCount))

// printscan\faxsrv\src\test\src\xxxunusedxxx\deviceioctls\fileioctl.h
#define FSCTL_SET_COMPRESSION           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 16, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_HSM_MSG                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 66, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)

// printscan\inc\psutil\comutils.h
#define QITABLE_DECLARE(className)  \
    class className##_QITable       \
    {                               \
    public:                         \
        static const QITAB qit[];   \
    };                              \
#define QITABLE_GET(className)      \
    className##_QITable::qit        \
#define QITABLE_BEGIN(className)                    \
    const QITAB className##_QITable::qit[] =        \
    {                                               \

// printscan\print\drivers\usermode\gpdres\epagcres\epagcres.c
#define    DEFINE_PALETTE_ENTRY        43                // (PaletteIndexToProgram,RedValue,GreenValue,BlueValue)
#define    SELECT_PALETTE_ENTRY        44                // (CurrentPaletteIndex)

// printscan\print\drivers\usermode\gpdres\ncb2jres\ncb2jres.c
#define WriteSpoolBuf(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\inc\oemutil.h
#define HAS_COM_INTERFACE(pOemEntry) \
        ((pOemEntry)->pIntfOem != NULL)

// printscan\print\drivers\usermode\msplot\lib\plotlib.h
#define DM_PAPER_FIELDS (DM_PAPERWIDTH | DM_PAPERLENGTH |   \
                         DM_PAPERSIZE  | DM_FORMNAME)

// printscan\print\drivers\usermode\msplot\plotter\transpos.h
#define _RL_TPI(pTPInfo, cScan)                                         \
{                                                                       \
    pTPInfo->pDest      += (pTPInfo->cbDestScan * cScan)                \
    pTPInfo->cbDestScan  = -pTBInfo->cbDestScan;                        \
    pTPInfo->pSrc       += (pTPInfo->cbSrcScan * (pTPInfo->cySrc - 1)); \
    pTPInfo->cbSrcScan   = -pTBInfo->cbSrcScan;                         \
}

// printscan\print\drivers\usermode\parsers\gpd\gpdparse.h
#define   KWF_DEDICATED_FIELD   (KWF_COMMAND | KWF_FONTCART | \
            KWF_OEM | KWF_TTFONTSUBS)

// printscan\print\drivers\usermode\parsers\ppd\ppdentry.c
#define HexDigitValue(c) \
        (((c) >= '0' && (c) <= '9') ? ((c) - '0') : \
         ((c) >= 'A' && (c) <= 'F') ? ((c) - 'A' + 10) : ((c) - 'a' + 10))

// printscan\print\drivers\usermode\tools\uexts\psdev.cxx
#define PDEV_DumpInt(field) \
        Print("  %-16s = %d\n", #field, pdev->field)
#define PDEV_DumpHex(field) \
        Print("  %-16s = 0x%x\n", #field, pdev->field)

// printscan\print\drivers\usermode\tools\uexts\psdm.cxx
#define PSDM_DumpInt(field) \
        dprintf("  %-16s = %d\n", #field, psdm->field)
#define PSDM_DumpHex(field) \
        dprintf("  %-16s = 0x%x\n", #field, psdm->field)

// printscan\print\drivers\usermode\tools\uexts\unidev.cxx
#define PDEV_DumpInt(field) \
        Print("  %-16s = %d\n", #field, pPDev->field)
#define PDEV_DumpHex(field) \
        Print("  %-16s = 0x%x\n", #field, pPDev->field)

// printscan\print\drivers\usermode\tools\uexts\unidm.cxx
#define UNIDM_DumpInt(field) \
        Print("  %-16s = %d\n", #field, pUMExtra->field)
#define UNIDM_DumpHex(field) \
        Print("  %-16s = 0x%x\n", #field, pUMExtra->field)
#define UNIDEVBRUSH_DumpInt(field) \
        Print("  %-16s = %d\n", #field, pDevBrush->field)
#define UNIDEVBRUSH_DumpHex(field) \
        Print("  %-16s = 0x%x\n", #field, pDevBrush->field)

// printscan\print\drivers\usermode\unidrv2\inc\oemkm.h
#define FIX_DEVOBJ(pPDev, ep) \
    { \
        (pPDev)->devobj.pdevOEM = (pPDev)->pOemHookInfo[ep].pOemEntry->pParam; \
        (pPDev)->devobj.pOEMDM = (pPDev)->pOemHookInfo[ep].pOemEntry->pOEMDM; \
        (pPDev)->pOemEntry = (PVOID)((pPDev)->pOemHookInfo[ep].pOemEntry); \
    } \

// printscan\print\spooler\wpnpinst\wow\inc\windows.h
#define DCB_SET         (DCB_RESET | DCB_ACCUMULATE)
#define EM_EMPTYUNDOBUFFER      (WM_USER+29)
#define LBCB_CARETON           (WM_USER+36)     /* ;Internal */
#define LBCB_CARETOFF          (WM_USER+37)     /* ;Internal */
#define CB_GETEDITSEL            (WM_USER+0)
#define CB_SETEDITSEL            (WM_USER+2)
#define CB_DIR                   (WM_USER+5)
#define CB_GETCURSEL             (WM_USER+7)
#define CB_RESETCONTENT          (WM_USER+11)
#define CB_SETCURSEL             (WM_USER+14)
#define CB_SHOWDROPDOWN          (WM_USER+15)
#define CB_GETITEMDATA           (WM_USER+16)
#define CB_SETITEMDATA           (WM_USER+17)
#define CB_GETDROPPEDCONTROLRECT (WM_USER+18)
#define CB_SETITEMHEIGHT         (WM_USER+19)
#define CB_GETITEMHEIGHT         (WM_USER+20)
#define CB_GETDROPPEDSTATE       (WM_USER+23)

// printscan\ui\photowiz\cfdefs.h
#define DECLARE_CLASS_FACTORY(cf)                                \
   class cf                                                      \
   {                                                             \
     public:                                                     \
       IClassFactory *vtable;                                    \
       STDMETHODX (QueryInterface)(REFIID, void **);             \
       STDMETHODX_(ULONG, AddRef)();                             \
       STDMETHODX_(ULONG, Release)();                            \
                                                                 \
       STDMETHODX (CreateInstance)(IUnknown *, REFIID, void **); \
       STDMETHODX (LockServer)(BOOL);                            \
   }                                                             \

// printscan\wia\core\wiascr\wiautil.cpp
#define SETVAR( vti, in, out, field ) \
	(out)->vt = vti; \
	(out)->field = (in)->field; \
	break

// printscan\wia\inc\stipriv.h
#define ZeroX(x) ZeroBuf(&(x), cbX(x))

// public\ddk\inc\mountmgr.h
#define IOCTL_MOUNTMGR_AUTO_DL_ASSIGNMENTS          CTL_CODE(MOUNTMGRCONTROLTYPE, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_KEEP_LINKS_WHEN_OFFLINE      CTL_CODE(MOUNTMGRCONTROLTYPE, 9, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\ddk\inc\netcfgx.h
#define INetCfgComponentBindings_MoveBefore(This,pncbItemSrc,pncbItemDest)	\
    (This)->lpVtbl -> MoveBefore(This,pncbItemSrc,pncbItemDest)
#define INetCfgComponentBindings_MoveAfter(This,pncbItemSrc,pncbItemDest)	\
    (This)->lpVtbl -> MoveAfter(This,pncbItemSrc,pncbItemDest)
#define INetCfgSysPrep_HrSetupSetFirstMultiSzField(This,pwszSection,pwszKey,pmszValue)	\
    (This)->lpVtbl -> HrSetupSetFirstMultiSzField(This,pwszSection,pwszKey,pmszValue)

// public\ddk\inc\ntddft2.h
#define FT_STOP_SYNC_OPERATIONS                     CTL_CODE(FTCONTROLTYPE, 14, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\ddk\inc\ntddk.h
#define KeInitializeCallbackRecord(CallbackRecord) \
    (CallbackRecord)->State = BufferEmpty
#define HALDISPATCH     (&HalDispatchTable)

// public\ddk\inc\wdm\acpiioct.h
#define IOCTL_ACPI_ASYNC_EVAL_METHOD            CTL_CODE(FILE_DEVICE_ACPI, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ACPI_EVAL_METHOD                  CTL_CODE(FILE_DEVICE_ACPI, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ACPI_ACQUIRE_GLOBAL_LOCK          CTL_CODE(FILE_DEVICE_ACPI, 4, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\ddk\inc\wdm\usbdlib.h
#define UsbBuildGetDescriptorRequest(urb, \
                                     length, \
                                     descriptorType, \
                                     descriptorIndex, \
                                     languageId, \
                                     transferBuffer, \
                                     transferBufferMDL, \
                                     transferBufferLength, \
                                     link) { \
            (urb)->UrbHeader.Function =  URB_FUNCTION_GET_DESCRIPTOR_FROM_DEVICE; \
            (urb)->UrbHeader.Length = (length); \
            (urb)->UrbControlDescriptorRequest.TransferBufferLength = (transferBufferLength); \
            (urb)->UrbControlDescriptorRequest.TransferBufferMDL = (transferBufferMDL); \
            (urb)->UrbControlDescriptorRequest.TransferBuffer = (transferBuffer); \
            (urb)->UrbControlDescriptorRequest.DescriptorType = (descriptorType); \
            (urb)->UrbControlDescriptorRequest.Index = (descriptorIndex); \
            (urb)->UrbControlDescriptorRequest.LanguageId = (languageId); \
            (urb)->UrbControlDescriptorRequest.UrbLink = (link); }
#define UsbBuildOsFeatureDescriptorRequest(urb, \
                              length, \
                              interface, \
                              index, \
                              transferBuffer, \
                              transferBufferMDL, \
                              transferBufferLength, \
                              link) { \
            (urb)->UrbHeader.Function = URB_FUNCTION_GET_MS_FEATURE_DESCRIPTOR; \
            (urb)->UrbHeader.Length = (length); \
            (urb)->UrbOSFeatureDescriptorRequest.TransferBufferLength = (transferBufferLength); \
            (urb)->UrbOSFeatureDescriptorRequest.TransferBufferMDL = (transferBufferMDL); \
            (urb)->UrbOSFeatureDescriptorRequest.TransferBuffer = (transferBuffer); \
            (urb)->UrbOSFeatureDescriptorRequest.InterfaceNumber = (interface); \
            (urb)->UrbOSFeatureDescriptorRequest.MS_FeatureDescriptorIndex = (index); \
            (urb)->UrbOSFeatureDescriptorRequest.UrbLink = (link); }

// public\ddk\inc\wdm\wdm.h
#define KeInitializeCallbackRecord(CallbackRecord) \
    (CallbackRecord)->State = BufferEmpty

// public\ddk\inc\wia.h
#define IWiaItem_Diagnostic(This,ulSize,pBuffer)	\
    (This)->lpVtbl -> Diagnostic(This,ulSize,pBuffer)
#define IWiaItemExtras_Escape(This,dwEscapeCode,lpInData,cbInDataSize,pOutData,dwOutDataSize,pdwActualDataSize)	\
    (This)->lpVtbl -> Escape(This,dwEscapeCode,lpInData,cbInDataSize,pOutData,dwOutDataSize,pdwActualDataSize)

// public\halkit\inc\apic.inc
#define LU_STARTUP_IPI   ( DELIVER_STARTUP | ICR_USE_DEST_FIELD | \
                           PHYSICAL_DESTINATION)

// public\halkit\inc\nthal.h
#define KeInitializeCallbackRecord(CallbackRecord) \
    (CallbackRecord)->State = BufferEmpty
#define HALDISPATCH     (&HalDispatchTable)
#define HALPDISPATCH                    (&HalPrivateDispatchTable)

// public\ifskit\inc\ntifs.h
#define FSCTL_SET_COMPRESSION           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 16, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_HSM_MSG                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 66, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
#define KeInitializeCallbackRecord(CallbackRecord) \
    (CallbackRecord)->State = BufferEmpty
#define IOCTL_VOLSNAP_FLUSH_AND_HOLD_WRITES         CTL_CODE(VOLSNAPCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\internal\admin\inc\umi.h
#define IUmiObject_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiObject_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiConnection_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiConnection_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiCursor_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiCursor_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiQuery_GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> GetAt(This,pszName,uFlags,uBufferLength,pExistingMem)
#define IUmiQuery_PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)	\
    (This)->lpVtbl -> PutFrom(This,pszName,uFlags,uBufferLength,pExistingMem)

// public\internal\com\inc\activate.h
#define IInitActivationPropertiesIn_SetConstructFromStorage(This,pStorage)	\
    (This)->lpVtbl -> SetConstructFromStorage(This,pStorage)
#define IInitActivationPropertiesIn_SetConstructFromFile(This,wszFileName,dwMode)	\
    (This)->lpVtbl -> SetConstructFromFile(This,wszFileName,dwMode)

// public\internal\com\inc\contxt.h
#define IPolicy_CallGetSize(This,pCall,pcb)	\
    (This)->lpVtbl -> CallGetSize(This,pCall,pcb)
#define IPolicy_CallFillBuffer(This,pCall,pvBuf,pcb)	\
    (This)->lpVtbl -> CallFillBuffer(This,pCall,pvBuf,pcb)
#define IPolicy_EnterWithBuffer(This,pCall,pvBuf,cb)	\
    (This)->lpVtbl -> EnterWithBuffer(This,pCall,pvBuf,cb)
#define IPolicy_LeaveGetSize(This,pCall,pcb)	\
    (This)->lpVtbl -> LeaveGetSize(This,pCall,pcb)
#define IPolicy_LeaveFillBuffer(This,pCall,pvBuf,pcb)	\
    (This)->lpVtbl -> LeaveFillBuffer(This,pCall,pvBuf,pcb)
#define IPolicy_ReturnWithBuffer(This,pCall,pvBuf,cb)	\
    (This)->lpVtbl -> ReturnWithBuffer(This,pCall,pvBuf,cb)
#define IPolicyAsync_BeginCallGetSize(This,pCall,pcb)	\
    (This)->lpVtbl -> BeginCallGetSize(This,pCall,pcb)
#define IPolicyAsync_BeginCallFillBuffer(This,pCall,pvBuf,pcb)	\
    (This)->lpVtbl -> BeginCallFillBuffer(This,pCall,pvBuf,pcb)
#define IPolicyAsync_BeginEnterWithBuffer(This,pCall,pvBuf,cb)	\
    (This)->lpVtbl -> BeginEnterWithBuffer(This,pCall,pvBuf,cb)
#define IPolicyAsync_FinishLeaveGetSize(This,pCall,pcb)	\
    (This)->lpVtbl -> FinishLeaveGetSize(This,pCall,pcb)
#define IPolicyAsync_FinishLeaveFillBuffer(This,pCall,pvBuf,pcb)	\
    (This)->lpVtbl -> FinishLeaveFillBuffer(This,pCall,pvBuf,pcb)
#define IPolicyAsync_FinishReturnWithBuffer(This,pCall,pvBuf,cb)	\
    (This)->lpVtbl -> FinishReturnWithBuffer(This,pCall,pvBuf,cb)
#define IMarshalEnvoy_GetEnvoySizeMax(This,dwDestContext,pcb)	\
    (This)->lpVtbl -> GetEnvoySizeMax(This,dwDestContext,pcb)

// public\internal\com\inc\corhdr.h
#define IsFdHasFieldRVA(x)                  ((x) & fdHasFieldRVA)
#define IsFdHasFieldMarshal(x)              ((x) & fdHasFieldMarshal)
#define IsFdHasFieldRVA(x)                  ((x) & fdHasFieldRVA)
#define IsPdHasFieldMarshal(x)              ((x) & pdHasFieldMarshal)

// public\internal\com\inc\partitions.h
#define IUserToken_GetUserSid(This,ppSid,pcbSid)	\
    (This)->lpVtbl -> GetUserSid(This,ppSid,pcbSid)

// public\internal\drivers\inc\ntddsnap.h
#define IOCTL_VOLSNAP_FLUSH_AND_HOLD_WRITES         CTL_CODE(VOLSNAPCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS) // ntifs
#define IOCTL_VOLSNAP_PREPARE_FOR_SNAPSHOT          CTL_CODE(VOLSNAPCONTROLTYPE, 2, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_VOLSNAP_ABORT_PREPARED_SNAPSHOT       CTL_CODE(VOLSNAPCONTROLTYPE, 3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_VOLSNAP_COMMIT_SNAPSHOT               CTL_CODE(VOLSNAPCONTROLTYPE, 4, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_VOLSNAP_END_COMMIT_SNAPSHOT           CTL_CODE(VOLSNAPCONTROLTYPE, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_VOLSNAP_CLEAR_DIFF_AREA               CTL_CODE(VOLSNAPCONTROLTYPE, 7, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_VOLSNAP_ADD_VOLUME_TO_DIFF_AREA       CTL_CODE(VOLSNAPCONTROLTYPE, 8, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_VOLSNAP_SET_APPLICATION_INFO          CTL_CODE(VOLSNAPCONTROLTYPE, 102, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\internal\drivers\inc\partmgrp.h
#define IOCTL_PARTMGR_EJECT_VOLUME_MANAGERS         CTL_CODE('p', 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\internal\ds\inc\dirsync.h
#define IDirsyncSessionCallback_AddObjectIdMapping(This,pSourceId,cbSourceId,pTargetId,cbTargetId,syncDirection)	\
    (This)->lpVtbl -> AddObjectIdMapping(This,pSourceId,cbSourceId,pTargetId,cbTargetId,syncDirection)
#define IDirsyncSessionCallback_DeleteObjectIdMapping(This,pTargetId,cbTargetId,Provider)	\
    (This)->lpVtbl -> DeleteObjectIdMapping(This,pTargetId,cbTargetId,Provider)
#define IDirsyncSessionCallback_SetCheckSum(This,pId,cbId,Provider,dwCheckSum)	\
    (This)->lpVtbl -> SetCheckSum(This,pId,cbId,Provider,dwCheckSum)
#define IDirsyncSessionCallback_GetCheckSum(This,pId,cbId,Provider,dwCheckSum)	\
    (This)->lpVtbl -> GetCheckSum(This,pId,cbId,Provider,dwCheckSum)
#define IDirsyncSessionCallback_SetDampeningInfo(This,pObjectId,cbObjectId,Provider,pByte,dwSize,highestUSN)	\
    (This)->lpVtbl -> SetDampeningInfo(This,pObjectId,cbObjectId,Provider,pByte,dwSize,highestUSN)
#define IDirsyncSessionCallback_GetDampeningInfo(This,pObjectId,cbObjectId,Provider,ppByte,pdwSize,pHighestUSN)	\
    (This)->lpVtbl -> GetDampeningInfo(This,pObjectId,cbObjectId,Provider,ppByte,pdwSize,pHighestUSN)
#define IDirsyncSessionCallback_MarkEntry(This,pId,cbId,Provider)	\
    (This)->lpVtbl -> MarkEntry(This,pId,cbId,Provider)
#define IDirsyncReadProvider_UpdateWatermark(This,pWatermark,cbWatermark)	\
    (This)->lpVtbl -> UpdateWatermark(This,pWatermark,cbWatermark)

// public\internal\ds\inc\iadsp.h
#define IADsPathnameProvider_ConstructPath(This,pObjectInfo,dwType,dwFlag,dwEscapedMode,pbstrPath)	\
    (This)->lpVtbl -> ConstructPath(This,pObjectInfo,dwType,dwFlag,dwEscapedMode,pbstrPath)

// public\internal\ds\inc\passport.h
#define IPassportFastAuth_GetTicketAndProfileECB(This,pbECB,pbstrTicket,pbstrProfile,pbstrSecure,pbstrSiteName)	\
    (This)->lpVtbl -> GetTicketAndProfileECB(This,pbECB,pbstrTicket,pbstrProfile,pbstrSecure,pbstrSiteName)
#define IPassportFastAuth2_GetTicketAndProfileECB(This,pbECB,pbstrTicket,pbstrProfile,pbstrSecure,pbstrSiteName)	\
    (This)->lpVtbl -> GetTicketAndProfileECB(This,pbECB,pbstrTicket,pbstrProfile,pbstrSecure,pbstrSiteName)

// public\internal\ds\inc\userenvp.h
#define CPD_SYNCHRONIZE          0x00000020  // Make dest directory structure indentical to src directory structure (delete extra files and directories)

// public\internal\inetcore\inc\interned.h
#define IHTMLEditingServices_IsElementUIActivatable(This,pIHTMLElement)	\
    (This)->lpVtbl -> IsElementUIActivatable(This,pIHTMLElement)
#define IEditDebugServices_IsUsingTableIncRecalc(This,pfUsingTableIncRecalc)	\
    (This)->lpVtbl -> IsUsingTableIncRecalc(This,pfUsingTableIncRecalc)
#define IHTMLFilterPaintSite_DrawUnfiltered(This,hdc,punkDrawObject,rcBounds,rcUpdate,lDrawLayers)	\
    (This)->lpVtbl -> DrawUnfiltered(This,hdc,punkDrawObject,rcBounds,rcUpdate,lDrawLayers)

// public\internal\multimedia\inc\ehui\duser.h
#define BEGIN_ENUM(name)                \
    struct name                         \
    {                                   \
        enum E;                         \
                                        \
        inline name()                   \
        {                               \
        }                               \
                                        \
        inline name(E src)              \
        {                               \
            value = src;                \
        }                               \
                                        \
        inline void operator=(E e)      \
        {                               \
            value = e;                  \
        }                               \
                                        \
        inline bool operator==(E e)     \
        {                               \
            return value == e;          \
        }                               \
                                        \
        inline bool operator!=(E e)     \
        {                               \
            return value != e;          \
        }                               \
                                        \
        inline bool operator<(E e)      \
        {                               \
            return value < e;           \
        }                               \
                                        \
        inline bool operator<=(E e)     \
        {                               \
            return value <= e;          \
        }                               \
                                        \
        inline bool operator>(E e)      \
        {                               \
            return value > e;           \
        }                               \
                                        \
        inline bool operator>=(E e)     \
        {                               \
            return value >= e;          \
        }                               \
                                        \
        inline operator E() const       \
        {                               \
            return value;               \
        }                               \
                                        \
        enum E                          \
        {                               \

// public\internal\net\inc\hnetcfg.h
#define IHNetBridgeSettings_DestroyAllBridges(This,pcBridges,pnetcfgExisting)	\
    (This)->lpVtbl -> DestroyAllBridges(This,pcBridges,pnetcfgExisting)
#define IHNetConnection_DeleteRasConnectionEntry(This)	\
    (This)->lpVtbl -> DeleteRasConnectionEntry(This)

// public\internal\net\inc\isnkrnl.h
#define MIPX_SETSAP        (I_MIPX | 5)   /* Set the sap/type field */
#define MIPX_SRCLEAR       (I_MIPX | 200) /* Clear the source routing table*/
#define MIPX_SRREMOVE      (I_MIPX | 204) /* Remove a node from the table */

// public\internal\net\inc\nbtioctl.h
#define IOCTL_NETBT_ADD_INTERFACE   _NETBT_CTRL_CODE( 45, METHOD_BUFFERED,\
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_NETBT_QUERY_INTERFACE_INSTANCE _NETBT_CTRL_CODE( 47, METHOD_BUFFERED,\
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_NETBT_SET_WINS_ADDRESS _NETBT_CTRL_CODE( 48, METHOD_BUFFERED,\
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_NETBT_SET_TCP_CONNECTION_INFO _NETBT_CTRL_CODE( 54, METHOD_BUFFERED, \
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_NETBT_SET_SMBDEVICE_BIND_INFO _NETBT_CTRL_CODE( 55, METHOD_BUFFERED, \
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_NETBT_WINS_SET_INFO _NETBT_CTRL_CODE( 57, METHOD_BUFFERED, \
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\internal\net\inc\netconp.h
#define IPersistNetConnection_GetSizeMax(This,pcbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pcbSize)
#define IPersistNetConnection_Load(This,pbBuf,cbSize)	\
    (This)->lpVtbl -> Load(This,pbBuf,cbSize)
#define IPersistNetConnection_Save(This,pbBuf,cbSize)	\
    (This)->lpVtbl -> Save(This,pbBuf,cbSize)

// public\internal\shell\inc\iepriv.h
#define IACLCustomMRU_AddMRUString(This,pwszEntry)	\
    (This)->lpVtbl -> AddMRUString(This,pwszEntry)

// public\internal\shell\inc\imapi\imapipub.h
#define IOCTL_IMAPIDRV_INFO ((ULONG)CTL_CODE(FILE_DEVICE_IMAPI,0x810,METHOD_BUFFERED,FILE_READ_ACCESS | FILE_WRITE_ACCESS))
#define IOCTL_IMAPIDRV_SENDCOMMAND ((ULONG)CTL_CODE(FILE_DEVICE_IMAPI,0x830,METHOD_BUFFERED,FILE_READ_ACCESS | FILE_WRITE_ACCESS))

// public\internal\shell\inc\shappmgrp.h
#define IADCCtl_Exec(This,bstrQualifier,bstrCmd,nRecord)	\
    (This)->lpVtbl -> Exec(This,bstrQualifier,bstrCmd,nRecord)

// public\internal\shell\inc\shimgdata.h
#define IShellImageData_IsEditable(This)	\
    (This)->lpVtbl -> IsEditable(This)
#define IShellImageData_IsPrintable(This)	\
    (This)->lpVtbl -> IsPrintable(This)

// public\internal\shell\inc\shlobjp.h
#define ILIsEmpty(pidl)     ((pidl) == NULL || (pidl)->mkid.cb==0)
#define IntDitherer_DitherTo8bpp(This, pDestBits, nDestPitch, \
                    pSrcBits, nSrcPitch, bfidSrc, \
                    prgbDestColors, prgbSrcColors, \
                    pbDestInvMap, x, y, cx, cy, \
                    lDestTrans, lSrcTrans)  \
    (This)->lpVtbl -> DitherTo8bpp(This, pDestBits, nDestPitch, pSrcBits, nSrcPitch, bfidSrc, \
                    prgbDestColors, prgbSrcColors, pbDestInvMap, x, y, cx, cy, lDestTrans, lSrcTrans)

// public\internal\shell\inc\shpriv.h
#define INotificationCB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INotificationCB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INotificationCB_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INotificationCB_Notify(This,dwMessage,pNotifyItem)	\
    (This)->lpVtbl -> Notify(This,dwMessage,pNotifyItem)
#define ITrayNotify_RegisterCallback(This,pNotifyCB)	\
    (This)->lpVtbl -> RegisterCallback(This,pNotifyCB)
#define IResourceMap_LoadString(This,pdnScope,pszID,pszBuffer,cch)	\
    (This)->lpVtbl -> LoadString(This,pdnScope,pszID,pszBuffer,cch)
#define IShellTreeWalker_WalkTree(This,dwFlags,pwszWalkRoot,pwszWalkSpec,iMaxPath,pstwcb)	\
    (This)->lpVtbl -> WalkTree(This,dwFlags,pwszWalkRoot,pwszWalkSpec,iMaxPath,pstwcb)
#define IDriveFolderExt_GetSpace(This,pcbTotal,pcbFree)	\
    (This)->lpVtbl -> GetSpace(This,pcbTotal,pcbFree)
#define IQuerySource_SetValueDirect(This,pszSubSource,pszValue,qvt,cbData,pbData)	\
    (This)->lpVtbl -> SetValueDirect(This,pszSubSource,pszValue,qvt,cbData,pbData)

// public\internal\shell\inc\tlog.h
#define ITravelEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITravelEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITravelEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITravelEntry_Invoke(This,punk)	\
    (This)->lpVtbl -> Invoke(This,punk)
#define ITravelEntry_Update(This,punk,fIsLocalAnchor)	\
    (This)->lpVtbl -> Update(This,punk,fIsLocalAnchor)
#define ITravelEntry_GetPidl(This,ppidl)	\
    (This)->lpVtbl -> GetPidl(This,ppidl)
#define ITravelLog_AddEntry(This,punk,fIsLocalAnchor)	\
    (This)->lpVtbl -> AddEntry(This,punk,fIsLocalAnchor)
#define ITravelLog_UpdateEntry(This,punk,fIsLocalAnchor)	\
    (This)->lpVtbl -> UpdateEntry(This,punk,fIsLocalAnchor)
#define ITravelLog_FindTravelEntry(This,punk,pidl,ppte)	\
    (This)->lpVtbl -> FindTravelEntry(This,punk,pidl,ppte)
#define ITravelLogEx_FindTravelEntryWithUrl(This,punk,uiCP,pszUrl,ppte)	\
    (This)->lpVtbl -> FindTravelEntryWithUrl(This,punk,uiCP,pszUrl,ppte)
#define ITravelLogEx_DeleteIndexEntry(This,punk,index)	\
    (This)->lpVtbl -> DeleteIndexEntry(This,punk,index)
#define ITravelLogEx_DeleteUrlEntry(This,punk,uiCP,pszUrl)	\
    (This)->lpVtbl -> DeleteUrlEntry(This,punk,uiCP,pszUrl)
#define ITravelLogEx_CountEntryNodes(This,punk,dwFlags,pdwCount)	\
    (This)->lpVtbl -> CountEntryNodes(This,punk,dwFlags,pdwCount)
#define ITravelLogEx_CreateEnumEntry(This,punk,ppEnum,dwFlags)	\
    (This)->lpVtbl -> CreateEnumEntry(This,punk,ppEnum,dwFlags)
#define ITravelLogEx_DeleteEntry(This,punk,pte)	\
    (This)->lpVtbl -> DeleteEntry(This,punk,pte)
#define ITravelLogEx_InsertEntry(This,punkBrowser,pteRelativeTo,fPrepend,punkTLClient,ppEntry)	\
    (This)->lpVtbl -> InsertEntry(This,punkBrowser,pteRelativeTo,fPrepend,punkTLClient,ppEntry)
#define ITravelLogEx_TravelToEntry(This,punkBrowser,pteDestination)	\
    (This)->lpVtbl -> TravelToEntry(This,punkBrowser,pteDestination)

// public\internal\shell\inc\tlogstg.h
#define ITravelLogEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITravelLogEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITravelLogEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITravelLogEntry_GetTitle(This,ppszTitle)	\
    (This)->lpVtbl -> GetTitle(This,ppszTitle)
#define ITravelLogEntry_GetURL(This,ppszURL)	\
    (This)->lpVtbl -> GetURL(This,ppszURL)
#define IEnumTravelLogEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumTravelLogEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumTravelLogEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumTravelLogEntry_Skip(This,cElt)	\
    (This)->lpVtbl -> Skip(This,cElt)
#define IEnumTravelLogEntry_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumTravelLogEntry_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)
#define ITravelLogStg_CreateEntry(This,pszUrl,pszTitle,ptleRelativeTo,fPrepend,pptle)	\
    (This)->lpVtbl -> CreateEntry(This,pszUrl,pszTitle,ptleRelativeTo,fPrepend,pptle)
#define ITravelLogStg_RemoveEntry(This,ptle)	\
    (This)->lpVtbl -> RemoveEntry(This,ptle)

// public\internal\windows\inc\aimmex.h
#define IAImmFnDocFeed_ClearDocFeedBuffer(This)	\
    (This)->lpVtbl -> ClearDocFeedBuffer(This)

// public\internal\windows\inc\duser\duserctrl.h
#define BEGIN_INTERPOLATION_INTERFACE(i, guid) \
    struct __declspec(uuid(guid)) i;    \
    struct i : public IInterpolation    \
    {
#define BEGIN_ANIMATION_INTERFACE(i, guid) \
    struct __declspec(uuid(guid)) i;    \
    struct i : public IAnimation        \
    {

// public\internal\windows\inc\winuserp.h
#define GACF2_NOTIMERCBPROTECTION 0x01000000  // don't protect from unregistered WM_TIMER with lParam (callback pfn).

// public\processorkit\inc\apic.inc
#define LU_STARTUP_IPI   ( DELIVER_STARTUP | ICR_USE_DEST_FIELD | \
                           PHYSICAL_DESTINATION)

// public\sdk\amovie\inc\aviriff.h
#define Valid_SUPERINDEX(pi) (*(DWORD *)(&((pi)->wLongsPerEntry)) == (4 | (AVI_INDEX_OF_INDEXES << 24)))

// public\sdk\inc16\windows.h
#define DCB_SET         (DCB_RESET | DCB_ACCUMULATE)
#define EM_EMPTYUNDOBUFFER      (WM_USER+29)
#define LBCB_CARETON           (WM_USER+36)     /* ;Internal */
#define LBCB_CARETOFF          (WM_USER+37)     /* ;Internal */
#define CB_GETEDITSEL            (WM_USER+0)
#define CB_LIMITTEXT             (WM_USER+1)
#define CB_SETEDITSEL            (WM_USER+2)
#define CB_ADDSTRING             (WM_USER+3)
#define CB_DELETESTRING          (WM_USER+4)
#define CB_DIR                   (WM_USER+5)
#define CB_GETCOUNT              (WM_USER+6)
#define CB_GETCURSEL             (WM_USER+7)
#define CB_GETLBTEXT             (WM_USER+8)
#define CB_GETLBTEXTLEN          (WM_USER+9)
#define CB_INSERTSTRING          (WM_USER+10)
#define CB_RESETCONTENT          (WM_USER+11)
#define CB_FINDSTRING            (WM_USER+12)
#define CB_SELECTSTRING          (WM_USER+13)
#define CB_SETCURSEL             (WM_USER+14)
#define CB_SHOWDROPDOWN          (WM_USER+15)
#define CB_GETITEMDATA           (WM_USER+16)
#define CB_SETITEMDATA           (WM_USER+17)
#define CB_GETDROPPEDCONTROLRECT (WM_USER+18)
#define CB_SETITEMHEIGHT         (WM_USER+19)
#define CB_GETITEMHEIGHT         (WM_USER+20)
#define CB_SETEXTENDEDUI         (WM_USER+21)
#define CB_GETEXTENDEDUI         (WM_USER+22)
#define CB_GETDROPPEDSTATE       (WM_USER+23)
#define CB_FINDSTRINGEXACT       (WM_USER+24)
#define CB_MSGMAX                (WM_USER+25)       /* ;Internal */

// public\sdk\inc16\windowsx.h
#define HANDLE_WM_CREATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (CREATESTRUCT FAR*)(lParam)) ? 0L : (LRESULT)-1L)
#define FORWARD_WM_CREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_CREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_NCCREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (CREATESTRUCT FAR*)(lParam))
#define FORWARD_WM_NCCREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCCREATE, 0, (LPARAM)(CREATESTRUCT FAR*)(lpCreateStruct))
#define HANDLE_WM_PAINTCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const PAINTSTRUCT FAR*)GlobalLock((HGLOBAL)LOWORD(lParam))), GlobalUnlock((HGLOBAL)LOWORD(lParam)), 0L)
#define FORWARD_WM_PAINTCLIPBOARD(hwnd, hwndCBViewer, lpPaintStruct, fn) \
    (void)(fn)((hwnd), WM_PAINTCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(lpPaintStruct))
#define FORWARD_WM_SIZECLIPBOARD(hwnd, hwndCBViewer, lprc, fn) \
    (void)(fn)((hwnd), WM_SIZECLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(lprc))
#define FORWARD_WM_VSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define FORWARD_WM_HSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_ASKCBFORMATNAME(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (LPSTR)(lParam)), 0L)
#define FORWARD_WM_ASKCBFORMATNAME(hwnd, cchMax, rgchName, fn) \
    (void)(fn)((hwnd), WM_ASKCBFORMATNAME, (WPARAM)(int)(cchMax), (LPARAM)(rgchName))
#define HANDLE_WM_CHANGECBCHAIN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (HWND)LOWORD(lParam)), 0L)
#define HANDLE_WM_MDICREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (MDICREATESTRUCT FAR*)(lParam))
#define HANDLE_WM_DRAWITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DRAWITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_DRAWITEM(hwnd, lpDrawItem, fn) \
    (void)(fn)((hwnd), WM_DRAWITEM, 0, (LPARAM)(const DRAWITEMSTRUCT FAR*)(lpDrawItem))
#define HANDLE_WM_MEASUREITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MEASUREITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_MEASUREITEM(hwnd, lpMeasureItem, fn) \
    (void)(fn)((hwnd), WM_MEASUREITEM, 0, (LPARAM)(MEASUREITEMSTRUCT FAR*)(lpMeasureItem))
#define HANDLE_WM_DELETEITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DELETEITEMSTRUCT FAR*)(lParam)), 0L)
#define FORWARD_WM_DELETEITEM(hwnd, lpDeleteItem, fn) \
    (void)(fn)((hwnd), WM_DELETEITEM, 0, (LPARAM)(const DELETEITEMSTRUCT FAR*)(lpDeleteItem))
#define HANDLE_WM_COMPAREITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (const COMPAREITEMSTRUCT FAR*)(lParam))
#define FORWARD_WM_COMPAREITEM(hwnd, lpCompareItem, fn) \
    (int)(DWORD)(fn)((hwnd), WM_COMPAREITEM, 0, (LPARAM)(const COMPAREITEMSTRUCT FAR*)(lpCompareItem))
#define Edit_EmptyUndoBuffer(hwndCtl)           ((void)SendMessage((hwndCtl), EM_EMPTYUNDOBUFFER, 0, 0L))
#define ComboBox_LimitText(hwndCtl, cchLimit)   ((int)(DWORD)SendMessage((hwndCtl), CB_LIMITTEXT, (WPARAM)(int)(cchLimit), 0L))
#define ComboBox_GetEditSel(hwndCtl)            ((DWORD)SendMessage((hwndCtl), CB_GETEDITSEL, 0, 0L))
#define ComboBox_SetEditSel(hwndCtl, ichStart, ichEnd) ((int)(DWORD)SendMessage((hwndCtl), CB_SETEDITSEL, 0, MAKELPARAM((ichStart), (ichEnd))))
#define ComboBox_GetCount(hwndCtl)              ((int)(DWORD)SendMessage((hwndCtl), CB_GETCOUNT, 0, 0L))
#define ComboBox_ResetContent(hwndCtl)          ((int)(DWORD)SendMessage((hwndCtl), CB_RESETCONTENT, 0, 0L))
#define ComboBox_AddString(hwndCtl, lpsz)       ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_InsertString(hwndCtl, index, lpsz) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCSTR)(lpsz)))
#define ComboBox_AddItemData(hwndCtl, data)     ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0, (LPARAM)(data)))
#define ComboBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_DeleteString(hwndCtl, index)   ((int)(DWORD)SendMessage((hwndCtl), CB_DELETESTRING, (WPARAM)(int)(index), 0L))
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

// public\sdk\inc\aclui.h
#define PSPCB_SI_INITDIALOG	(WM_USER + 1)

// public\sdk\inc\activaut.h
#define IScriptNode_CreateChildEntry(This,isn,dwCookie,pszDelimiter,ppse)	\
    (This)->lpVtbl -> CreateChildEntry(This,isn,dwCookie,pszDelimiter,ppse)
#define IScriptEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IScriptEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IScriptEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IScriptEntry_Alive(This)	\
    (This)->lpVtbl -> Alive(This)
#define IScriptEntry_Delete(This)	\
    (This)->lpVtbl -> Delete(This)
#define IScriptEntry_GetParent(This,ppsnParent)	\
    (This)->lpVtbl -> GetParent(This,ppsnParent)
#define IScriptEntry_GetIndexInParent(This,pisn)	\
    (This)->lpVtbl -> GetIndexInParent(This,pisn)
#define IScriptEntry_GetCookie(This,pdwCookie)	\
    (This)->lpVtbl -> GetCookie(This,pdwCookie)
#define IScriptEntry_GetNumberOfChildren(This,pcsn)	\
    (This)->lpVtbl -> GetNumberOfChildren(This,pcsn)
#define IScriptEntry_GetChild(This,isn,ppsn)	\
    (This)->lpVtbl -> GetChild(This,isn,ppsn)
#define IScriptEntry_GetLanguage(This,pbstr)	\
    (This)->lpVtbl -> GetLanguage(This,pbstr)
#define IScriptEntry_CreateChildEntry(This,isn,dwCookie,pszDelimiter,ppse)	\
    (This)->lpVtbl -> CreateChildEntry(This,isn,dwCookie,pszDelimiter,ppse)
#define IScriptEntry_CreateChildHandler(This,pszDefaultName,prgpszNames,cpszNames,pszEvent,pszDelimiter,ptiSignature,iMethodSignature,isn,dwCookie,ppse)	\
    (This)->lpVtbl -> CreateChildHandler(This,pszDefaultName,prgpszNames,cpszNames,pszEvent,pszDelimiter,ptiSignature,iMethodSignature,isn,dwCookie,ppse)
#define IScriptEntry_GetText(This,pbstr)	\
    (This)->lpVtbl -> GetText(This,pbstr)
#define IScriptEntry_SetText(This,psz)	\
    (This)->lpVtbl -> SetText(This,psz)
#define IScriptEntry_GetBody(This,pbstr)	\
    (This)->lpVtbl -> GetBody(This,pbstr)
#define IScriptEntry_SetBody(This,psz)	\
    (This)->lpVtbl -> SetBody(This,psz)
#define IScriptEntry_GetName(This,pbstr)	\
    (This)->lpVtbl -> GetName(This,pbstr)
#define IScriptEntry_SetName(This,psz)	\
    (This)->lpVtbl -> SetName(This,psz)
#define IScriptEntry_GetItemName(This,pbstr)	\
    (This)->lpVtbl -> GetItemName(This,pbstr)
#define IScriptEntry_SetItemName(This,psz)	\
    (This)->lpVtbl -> SetItemName(This,psz)
#define IScriptEntry_GetSignature(This,ppti,piMethod)	\
    (This)->lpVtbl -> GetSignature(This,ppti,piMethod)
#define IScriptEntry_SetSignature(This,pti,iMethod)	\
    (This)->lpVtbl -> SetSignature(This,pti,iMethod)
#define IScriptEntry_GetRange(This,pichMin,pcch)	\
    (This)->lpVtbl -> GetRange(This,pichMin,pcch)
#define IScriptScriptlet_CreateChildEntry(This,isn,dwCookie,pszDelimiter,ppse)	\
    (This)->lpVtbl -> CreateChildEntry(This,isn,dwCookie,pszDelimiter,ppse)

// public\sdk\inc\activdbg.h
#define IDebugExpression_Start(This,pdecb)	\
    (This)->lpVtbl -> Start(This,pdecb)
#define IDebugAsyncOperation_Start(This,padocb)	\
    (This)->lpVtbl -> Start(This,padocb)
#define IDebugApplicationThread_SynchronousCallIntoThread32(This,pstcb,dwParam1,dwParam2,dwParam3)	\
    (This)->lpVtbl -> SynchronousCallIntoThread32(This,pstcb,dwParam1,dwParam2,dwParam3)
#define IDebugApplicationThread64_SynchronousCallIntoThread32(This,pstcb,dwParam1,dwParam2,dwParam3)	\
    (This)->lpVtbl -> SynchronousCallIntoThread32(This,pstcb,dwParam1,dwParam2,dwParam3)
#define IDebugApplicationThread64_SynchronousCallIntoThread64(This,pstcb,dwParam1,dwParam2,dwParam3)	\
    (This)->lpVtbl -> SynchronousCallIntoThread64(This,pstcb,dwParam1,dwParam2,dwParam3)

// public\sdk\inc\admex.h
#define IMSAdminReplication_GetSignature(This,dwBufferSize,pbBuffer,pdwMDRequiredBufferSize)	\
    (This)->lpVtbl -> GetSignature(This,dwBufferSize,pbBuffer,pdwMDRequiredBufferSize)
#define IMSAdminReplication_Propagate(This,dwBufferSize,pszBuffer)	\
    (This)->lpVtbl -> Propagate(This,dwBufferSize,pszBuffer)
#define IMSAdminReplication_Propagate2(This,dwBufferSize,pszBuffer,dwSignatureMismatch)	\
    (This)->lpVtbl -> Propagate2(This,dwBufferSize,pszBuffer,dwSignatureMismatch)
#define IMSAdminReplication_Serialize(This,dwBufferSize,pbBuffer,pdwMDRequiredBufferSize)	\
    (This)->lpVtbl -> Serialize(This,dwBufferSize,pbBuffer,pdwMDRequiredBufferSize)
#define IMSAdminReplication_DeSerialize(This,dwBufferSize,pbBuffer)	\
    (This)->lpVtbl -> DeSerialize(This,dwBufferSize,pbBuffer)
#define IMSAdminCryptoCapabilities_GetProtocols(This,dwBufferSize,pbBuffer,pdwMDRequiredBufferSize)	\
    (This)->lpVtbl -> GetProtocols(This,dwBufferSize,pbBuffer,pdwMDRequiredBufferSize)
#define IMSAdminCryptoCapabilities_GetRootCertificates(This,dwBufferSize,pbBuffer,pdwMDRequiredBufferSize)	\
    (This)->lpVtbl -> GetRootCertificates(This,dwBufferSize,pbBuffer,pdwMDRequiredBufferSize)
#define IMSAdminCryptoCapabilities_GetSupportedAlgs(This,dwBufferSize,pbBuffer,pdwMDRequiredBufferSize)	\
    (This)->lpVtbl -> GetSupportedAlgs(This,dwBufferSize,pbBuffer,pdwMDRequiredBufferSize)

// public\sdk\inc\adoctint.h
#define _Catalog_get_Tables(This,ppvObject)	\
    (This)->lpVtbl -> get_Tables(This,ppvObject)
#define _Table_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _Table_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define _Table_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define _Table_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _Table_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Table_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Table_get_Columns(This,ppvObject)	\
    (This)->lpVtbl -> get_Columns(This,ppvObject)
#define _Table_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)
#define _Table_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)
#define _Table_get_Type(This,pVal)	\
    (This)->lpVtbl -> get_Type(This,pVal)
#define _Table_get_Indexes(This,ppvObject)	\
    (This)->lpVtbl -> get_Indexes(This,ppvObject)
#define _Table_get_Keys(This,ppvObject)	\
    (This)->lpVtbl -> get_Keys(This,ppvObject)
#define _Table_get_Properties(This,ppvObject)	\
    (This)->lpVtbl -> get_Properties(This,ppvObject)
#define _Table_get_DateCreated(This,pVal)	\
    (This)->lpVtbl -> get_DateCreated(This,pVal)
#define _Table_get_DateModified(This,pVal)	\
    (This)->lpVtbl -> get_DateModified(This,pVal)
#define _Table_get_ParentCatalog(This,ppvObject)	\
    (This)->lpVtbl -> get_ParentCatalog(This,ppvObject)
#define _Table_put_ParentCatalog(This,ppvObject)	\
    (This)->lpVtbl -> put_ParentCatalog(This,ppvObject)
#define _Table_putref_ParentCatalog(This,ppvObject)	\
    (This)->lpVtbl -> putref_ParentCatalog(This,ppvObject)
#define _Key_get_RelatedTable(This,pVal)	\
    (This)->lpVtbl -> get_RelatedTable(This,pVal)
#define _Key_put_RelatedTable(This,newVal)	\
    (This)->lpVtbl -> put_RelatedTable(This,newVal)
#define Tables_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Tables_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define Tables_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define Tables_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Tables_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Tables_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Tables_get_Count(This,c)	\
    (This)->lpVtbl -> get_Count(This,c)
#define Tables__NewEnum(This,ppvObject)	\
    (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define Tables_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)
#define Tables_get_Item(This,Item,ppvObject)	\
    (This)->lpVtbl -> get_Item(This,Item,ppvObject)
#define Tables_Append(This,Item)	\
    (This)->lpVtbl -> Append(This,Item)
#define Tables_Delete(This,Item)	\
    (This)->lpVtbl -> Delete(This,Item)
#define Keys_Append(This,Item,Type,Column,RelatedTable,RelatedColumn)	\
    (This)->lpVtbl -> Append(This,Item,Type,Column,RelatedTable,RelatedColumn)

// public\sdk\inc\adoint.h
#define Command15_Execute(This,RecordsAffected,Parameters,Options,ppirs)	\
    (This)->lpVtbl -> Execute(This,RecordsAffected,Parameters,Options,ppirs)
#define Command25_Execute(This,RecordsAffected,Parameters,Options,ppirs)	\
    (This)->lpVtbl -> Execute(This,RecordsAffected,Parameters,Options,ppirs)
#define _Command_Execute(This,RecordsAffected,Parameters,Options,ppirs)	\
    (This)->lpVtbl -> Execute(This,RecordsAffected,Parameters,Options,ppirs)
#define ConnectionEventsVt_WillExecute(This,Source,CursorType,LockType,Options,adStatus,pCommand,pRecordset,pConnection)	\
    (This)->lpVtbl -> WillExecute(This,Source,CursorType,LockType,Options,adStatus,pCommand,pRecordset,pConnection)
#define ConnectionEventsVt_ExecuteComplete(This,RecordsAffected,pError,adStatus,pCommand,pRecordset,pConnection)	\
    (This)->lpVtbl -> ExecuteComplete(This,RecordsAffected,pError,adStatus,pCommand,pRecordset,pConnection)
#define RecordsetEventsVt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define RecordsetEventsVt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define RecordsetEventsVt_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define RecordsetEventsVt_WillChangeField(This,cFields,Fields,adStatus,pRecordset)	\
    (This)->lpVtbl -> WillChangeField(This,cFields,Fields,adStatus,pRecordset)
#define RecordsetEventsVt_FieldChangeComplete(This,cFields,Fields,pError,adStatus,pRecordset)	\
    (This)->lpVtbl -> FieldChangeComplete(This,cFields,Fields,pError,adStatus,pRecordset)
#define RecordsetEventsVt_WillChangeRecord(This,adReason,cRecords,adStatus,pRecordset)	\
    (This)->lpVtbl -> WillChangeRecord(This,adReason,cRecords,adStatus,pRecordset)
#define RecordsetEventsVt_RecordChangeComplete(This,adReason,cRecords,pError,adStatus,pRecordset)	\
    (This)->lpVtbl -> RecordChangeComplete(This,adReason,cRecords,pError,adStatus,pRecordset)
#define RecordsetEventsVt_WillChangeRecordset(This,adReason,adStatus,pRecordset)	\
    (This)->lpVtbl -> WillChangeRecordset(This,adReason,adStatus,pRecordset)
#define RecordsetEventsVt_RecordsetChangeComplete(This,adReason,pError,adStatus,pRecordset)	\
    (This)->lpVtbl -> RecordsetChangeComplete(This,adReason,pError,adStatus,pRecordset)
#define RecordsetEventsVt_WillMove(This,adReason,adStatus,pRecordset)	\
    (This)->lpVtbl -> WillMove(This,adReason,adStatus,pRecordset)
#define RecordsetEventsVt_MoveComplete(This,adReason,pError,adStatus,pRecordset)	\
    (This)->lpVtbl -> MoveComplete(This,adReason,pError,adStatus,pRecordset)
#define RecordsetEventsVt_EndOfRecordset(This,fMoreData,adStatus,pRecordset)	\
    (This)->lpVtbl -> EndOfRecordset(This,fMoreData,adStatus,pRecordset)
#define RecordsetEventsVt_FetchProgress(This,Progress,MaxProgress,adStatus,pRecordset)	\
    (This)->lpVtbl -> FetchProgress(This,Progress,MaxProgress,adStatus,pRecordset)
#define RecordsetEventsVt_FetchComplete(This,pError,adStatus,pRecordset)	\
    (This)->lpVtbl -> FetchComplete(This,pError,adStatus,pRecordset)
#define RecordsetEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define RecordsetEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define RecordsetEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define RecordsetEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define RecordsetEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define RecordsetEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Connection15_Execute(This,CommandText,RecordsAffected,Options,ppiRset)	\
    (This)->lpVtbl -> Execute(This,CommandText,RecordsAffected,Options,ppiRset)
#define _Connection_Execute(This,CommandText,RecordsAffected,Options,ppiRset)	\
    (This)->lpVtbl -> Execute(This,CommandText,RecordsAffected,Options,ppiRset)
#define ADOConnectionConstruction15_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADOConnectionConstruction15_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ADOConnectionConstruction15_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ADOConnectionConstruction15_get_DSO(This,ppDSO)	\
    (This)->lpVtbl -> get_DSO(This,ppDSO)
#define ADOConnectionConstruction15_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)
#define ADOConnectionConstruction15_WrapDSOandSession(This,pDSO,pSession)	\
    (This)->lpVtbl -> WrapDSOandSession(This,pDSO,pSession)
#define ADOConnectionConstruction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADOConnectionConstruction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ADOConnectionConstruction_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ADOConnectionConstruction_get_DSO(This,ppDSO)	\
    (This)->lpVtbl -> get_DSO(This,ppDSO)
#define ADOConnectionConstruction_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)
#define ADOConnectionConstruction_WrapDSOandSession(This,pDSO,pSession)	\
    (This)->lpVtbl -> WrapDSOandSession(This,pDSO,pSession)
#define _Record_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _Record_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define _Record_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define _Record_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _Record_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Record_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Record_get_Properties(This,ppvObject)	\
    (This)->lpVtbl -> get_Properties(This,ppvObject)
#define _Record_get_ActiveConnection(This,pvar)	\
    (This)->lpVtbl -> get_ActiveConnection(This,pvar)
#define _Record_put_ActiveConnection(This,bstrConn)	\
    (This)->lpVtbl -> put_ActiveConnection(This,bstrConn)
#define _Record_putref_ActiveConnection(This,Con)	\
    (This)->lpVtbl -> putref_ActiveConnection(This,Con)
#define _Record_get_State(This,pState)	\
    (This)->lpVtbl -> get_State(This,pState)
#define _Record_get_Source(This,pvar)	\
    (This)->lpVtbl -> get_Source(This,pvar)
#define _Record_put_Source(This,Source)	\
    (This)->lpVtbl -> put_Source(This,Source)
#define _Record_putref_Source(This,Source)	\
    (This)->lpVtbl -> putref_Source(This,Source)
#define _Record_get_Mode(This,pMode)	\
    (This)->lpVtbl -> get_Mode(This,pMode)
#define _Record_put_Mode(This,Mode)	\
    (This)->lpVtbl -> put_Mode(This,Mode)
#define _Record_get_ParentURL(This,pbstrParentURL)	\
    (This)->lpVtbl -> get_ParentURL(This,pbstrParentURL)
#define _Record_MoveRecord(This,Source,Destination,UserName,Password,Options,Async,pbstrNewURL)	\
    (This)->lpVtbl -> MoveRecord(This,Source,Destination,UserName,Password,Options,Async,pbstrNewURL)
#define _Record_CopyRecord(This,Source,Destination,UserName,Password,Options,Async,pbstrNewURL)	\
    (This)->lpVtbl -> CopyRecord(This,Source,Destination,UserName,Password,Options,Async,pbstrNewURL)
#define _Record_DeleteRecord(This,Source,Async)	\
    (This)->lpVtbl -> DeleteRecord(This,Source,Async)
#define _Record_Open(This,Source,ActiveConnection,Mode,CreateOptions,Options,UserName,Password)	\
    (This)->lpVtbl -> Open(This,Source,ActiveConnection,Mode,CreateOptions,Options,UserName,Password)
#define _Record_Close(This)	\
    (This)->lpVtbl -> Close(This)
#define _Record_get_Fields(This,ppFlds)	\
    (This)->lpVtbl -> get_Fields(This,ppFlds)
#define _Record_get_RecordType(This,pType)	\
    (This)->lpVtbl -> get_RecordType(This,pType)
#define _Record_GetChildren(This,ppRSet)	\
    (This)->lpVtbl -> GetChildren(This,ppRSet)
#define _Record_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)
#define _Stream_Write(This,Buffer)	\
    (This)->lpVtbl -> Write(This,Buffer)
#define ADORecordConstruction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADORecordConstruction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ADORecordConstruction_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ADORecordConstruction_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ADORecordConstruction_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ADORecordConstruction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ADORecordConstruction_get_Row(This,ppRow)	\
    (This)->lpVtbl -> get_Row(This,ppRow)
#define ADORecordConstruction_put_Row(This,pRow)	\
    (This)->lpVtbl -> put_Row(This,pRow)
#define ADORecordConstruction_put_ParentRow(This,pRow)	\
    (This)->lpVtbl -> put_ParentRow(This,pRow)
#define ADOStreamConstruction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADOStreamConstruction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ADOStreamConstruction_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ADOStreamConstruction_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ADOStreamConstruction_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ADOStreamConstruction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ADOStreamConstruction_get_Stream(This,ppStm)	\
    (This)->lpVtbl -> get_Stream(This,ppStm)
#define ADOStreamConstruction_put_Stream(This,pStm)	\
    (This)->lpVtbl -> put_Stream(This,pStm)
#define ADOCommandConstruction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADOCommandConstruction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ADOCommandConstruction_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ADOCommandConstruction_get_OLEDBCommand(This,ppOLEDBCommand)	\
    (This)->lpVtbl -> get_OLEDBCommand(This,ppOLEDBCommand)
#define ADOCommandConstruction_put_OLEDBCommand(This,pOLEDBCommand)	\
    (This)->lpVtbl -> put_OLEDBCommand(This,pOLEDBCommand)
#define Recordset15_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Recordset15_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define Recordset15_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define Recordset15_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Recordset15_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Recordset15_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Recordset15_get_Properties(This,ppvObject)	\
    (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Recordset15_get_AbsolutePosition(This,pl)	\
    (This)->lpVtbl -> get_AbsolutePosition(This,pl)
#define Recordset15_put_AbsolutePosition(This,Position)	\
    (This)->lpVtbl -> put_AbsolutePosition(This,Position)
#define Recordset15_putref_ActiveConnection(This,pconn)	\
    (This)->lpVtbl -> putref_ActiveConnection(This,pconn)
#define Recordset15_put_ActiveConnection(This,vConn)	\
    (This)->lpVtbl -> put_ActiveConnection(This,vConn)
#define Recordset15_get_ActiveConnection(This,pvar)	\
    (This)->lpVtbl -> get_ActiveConnection(This,pvar)
#define Recordset15_get_BOF(This,pb)	\
    (This)->lpVtbl -> get_BOF(This,pb)
#define Recordset15_get_Bookmark(This,pvBookmark)	\
    (This)->lpVtbl -> get_Bookmark(This,pvBookmark)
#define Recordset15_put_Bookmark(This,vBookmark)	\
    (This)->lpVtbl -> put_Bookmark(This,vBookmark)
#define Recordset15_get_CacheSize(This,pl)	\
    (This)->lpVtbl -> get_CacheSize(This,pl)
#define Recordset15_put_CacheSize(This,CacheSize)	\
    (This)->lpVtbl -> put_CacheSize(This,CacheSize)
#define Recordset15_get_CursorType(This,plCursorType)	\
    (This)->lpVtbl -> get_CursorType(This,plCursorType)
#define Recordset15_put_CursorType(This,lCursorType)	\
    (This)->lpVtbl -> put_CursorType(This,lCursorType)
#define Recordset15_get_EOF(This,pb)	\
    (This)->lpVtbl -> get_EOF(This,pb)
#define Recordset15_get_Fields(This,ppvObject)	\
    (This)->lpVtbl -> get_Fields(This,ppvObject)
#define Recordset15_get_LockType(This,plLockType)	\
    (This)->lpVtbl -> get_LockType(This,plLockType)
#define Recordset15_put_LockType(This,lLockType)	\
    (This)->lpVtbl -> put_LockType(This,lLockType)
#define Recordset15_get_MaxRecords(This,plMaxRecords)	\
    (This)->lpVtbl -> get_MaxRecords(This,plMaxRecords)
#define Recordset15_put_MaxRecords(This,lMaxRecords)	\
    (This)->lpVtbl -> put_MaxRecords(This,lMaxRecords)
#define Recordset15_get_RecordCount(This,pl)	\
    (This)->lpVtbl -> get_RecordCount(This,pl)
#define Recordset15_putref_Source(This,pcmd)	\
    (This)->lpVtbl -> putref_Source(This,pcmd)
#define Recordset15_put_Source(This,bstrConn)	\
    (This)->lpVtbl -> put_Source(This,bstrConn)
#define Recordset15_get_Source(This,pvSource)	\
    (This)->lpVtbl -> get_Source(This,pvSource)
#define Recordset15_CancelUpdate(This)	\
    (This)->lpVtbl -> CancelUpdate(This)
#define Recordset15_Close(This)	\
    (This)->lpVtbl -> Close(This)
#define Recordset15_Delete(This,AffectRecords)	\
    (This)->lpVtbl -> Delete(This,AffectRecords)
#define Recordset15_GetRows(This,Rows,Start,Fields,pvar)	\
    (This)->lpVtbl -> GetRows(This,Rows,Start,Fields,pvar)
#define Recordset15_Move(This,NumRecords,Start)	\
    (This)->lpVtbl -> Move(This,NumRecords,Start)
#define Recordset15_MoveFirst(This)	\
    (This)->lpVtbl -> MoveFirst(This)
#define Recordset15_MoveLast(This)	\
    (This)->lpVtbl -> MoveLast(This)
#define Recordset15_Open(This,Source,ActiveConnection,CursorType,LockType,Options)	\
    (This)->lpVtbl -> Open(This,Source,ActiveConnection,CursorType,LockType,Options)
#define Recordset15_Requery(This,Options)	\
    (This)->lpVtbl -> Requery(This,Options)
#define Recordset15__xResync(This,AffectRecords)	\
    (This)->lpVtbl -> _xResync(This,AffectRecords)
#define Recordset15_Update(This,Fields,Values)	\
    (This)->lpVtbl -> Update(This,Fields,Values)
#define Recordset15_get_EditMode(This,pl)	\
    (This)->lpVtbl -> get_EditMode(This,pl)
#define Recordset15_get_Filter(This,Criteria)	\
    (This)->lpVtbl -> get_Filter(This,Criteria)
#define Recordset15_put_Filter(This,Criteria)	\
    (This)->lpVtbl -> put_Filter(This,Criteria)
#define Recordset15_get_Sort(This,Criteria)	\
    (This)->lpVtbl -> get_Sort(This,Criteria)
#define Recordset15_put_Sort(This,Criteria)	\
    (This)->lpVtbl -> put_Sort(This,Criteria)
#define Recordset15_get_Status(This,pl)	\
    (This)->lpVtbl -> get_Status(This,pl)
#define Recordset15_get_State(This,plObjState)	\
    (This)->lpVtbl -> get_State(This,plObjState)
#define Recordset15__xClone(This,ppvObject)	\
    (This)->lpVtbl -> _xClone(This,ppvObject)
#define Recordset15_UpdateBatch(This,AffectRecords)	\
    (This)->lpVtbl -> UpdateBatch(This,AffectRecords)
#define Recordset15_CancelBatch(This,AffectRecords)	\
    (This)->lpVtbl -> CancelBatch(This,AffectRecords)
#define Recordset15_get_CursorLocation(This,plCursorLoc)	\
    (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)
#define Recordset15_put_CursorLocation(This,lCursorLoc)	\
    (This)->lpVtbl -> put_CursorLocation(This,lCursorLoc)
#define Recordset15_Supports(This,CursorOptions,pb)	\
    (This)->lpVtbl -> Supports(This,CursorOptions,pb)
#define Recordset15_get_Collect(This,Index,pvar)	\
    (This)->lpVtbl -> get_Collect(This,Index,pvar)
#define Recordset15_put_Collect(This,Index,value)	\
    (This)->lpVtbl -> put_Collect(This,Index,value)
#define Recordset15_get_MarshalOptions(This,peMarshal)	\
    (This)->lpVtbl -> get_MarshalOptions(This,peMarshal)
#define Recordset15_put_MarshalOptions(This,eMarshal)	\
    (This)->lpVtbl -> put_MarshalOptions(This,eMarshal)
#define Recordset15_Find(This,Criteria,SkipRecords,SearchDirection,Start)	\
    (This)->lpVtbl -> Find(This,Criteria,SkipRecords,SearchDirection,Start)
#define Recordset20_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Recordset20_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define Recordset20_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define Recordset20_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Recordset20_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Recordset20_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Recordset20_get_Properties(This,ppvObject)	\
    (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Recordset20_get_AbsolutePosition(This,pl)	\
    (This)->lpVtbl -> get_AbsolutePosition(This,pl)
#define Recordset20_put_AbsolutePosition(This,Position)	\
    (This)->lpVtbl -> put_AbsolutePosition(This,Position)
#define Recordset20_putref_ActiveConnection(This,pconn)	\
    (This)->lpVtbl -> putref_ActiveConnection(This,pconn)
#define Recordset20_put_ActiveConnection(This,vConn)	\
    (This)->lpVtbl -> put_ActiveConnection(This,vConn)
#define Recordset20_get_ActiveConnection(This,pvar)	\
    (This)->lpVtbl -> get_ActiveConnection(This,pvar)
#define Recordset20_get_BOF(This,pb)	\
    (This)->lpVtbl -> get_BOF(This,pb)
#define Recordset20_get_Bookmark(This,pvBookmark)	\
    (This)->lpVtbl -> get_Bookmark(This,pvBookmark)
#define Recordset20_put_Bookmark(This,vBookmark)	\
    (This)->lpVtbl -> put_Bookmark(This,vBookmark)
#define Recordset20_get_CacheSize(This,pl)	\
    (This)->lpVtbl -> get_CacheSize(This,pl)
#define Recordset20_put_CacheSize(This,CacheSize)	\
    (This)->lpVtbl -> put_CacheSize(This,CacheSize)
#define Recordset20_get_CursorType(This,plCursorType)	\
    (This)->lpVtbl -> get_CursorType(This,plCursorType)
#define Recordset20_put_CursorType(This,lCursorType)	\
    (This)->lpVtbl -> put_CursorType(This,lCursorType)
#define Recordset20_get_EOF(This,pb)	\
    (This)->lpVtbl -> get_EOF(This,pb)
#define Recordset20_get_Fields(This,ppvObject)	\
    (This)->lpVtbl -> get_Fields(This,ppvObject)
#define Recordset20_get_LockType(This,plLockType)	\
    (This)->lpVtbl -> get_LockType(This,plLockType)
#define Recordset20_put_LockType(This,lLockType)	\
    (This)->lpVtbl -> put_LockType(This,lLockType)
#define Recordset20_get_MaxRecords(This,plMaxRecords)	\
    (This)->lpVtbl -> get_MaxRecords(This,plMaxRecords)
#define Recordset20_put_MaxRecords(This,lMaxRecords)	\
    (This)->lpVtbl -> put_MaxRecords(This,lMaxRecords)
#define Recordset20_get_RecordCount(This,pl)	\
    (This)->lpVtbl -> get_RecordCount(This,pl)
#define Recordset20_putref_Source(This,pcmd)	\
    (This)->lpVtbl -> putref_Source(This,pcmd)
#define Recordset20_put_Source(This,bstrConn)	\
    (This)->lpVtbl -> put_Source(This,bstrConn)
#define Recordset20_get_Source(This,pvSource)	\
    (This)->lpVtbl -> get_Source(This,pvSource)
#define Recordset20_CancelUpdate(This)	\
    (This)->lpVtbl -> CancelUpdate(This)
#define Recordset20_Close(This)	\
    (This)->lpVtbl -> Close(This)
#define Recordset20_Delete(This,AffectRecords)	\
    (This)->lpVtbl -> Delete(This,AffectRecords)
#define Recordset20_GetRows(This,Rows,Start,Fields,pvar)	\
    (This)->lpVtbl -> GetRows(This,Rows,Start,Fields,pvar)
#define Recordset20_Move(This,NumRecords,Start)	\
    (This)->lpVtbl -> Move(This,NumRecords,Start)
#define Recordset20_MoveFirst(This)	\
    (This)->lpVtbl -> MoveFirst(This)
#define Recordset20_MoveLast(This)	\
    (This)->lpVtbl -> MoveLast(This)
#define Recordset20_Open(This,Source,ActiveConnection,CursorType,LockType,Options)	\
    (This)->lpVtbl -> Open(This,Source,ActiveConnection,CursorType,LockType,Options)
#define Recordset20_Requery(This,Options)	\
    (This)->lpVtbl -> Requery(This,Options)
#define Recordset20__xResync(This,AffectRecords)	\
    (This)->lpVtbl -> _xResync(This,AffectRecords)
#define Recordset20_Update(This,Fields,Values)	\
    (This)->lpVtbl -> Update(This,Fields,Values)
#define Recordset20_get_EditMode(This,pl)	\
    (This)->lpVtbl -> get_EditMode(This,pl)
#define Recordset20_get_Filter(This,Criteria)	\
    (This)->lpVtbl -> get_Filter(This,Criteria)
#define Recordset20_put_Filter(This,Criteria)	\
    (This)->lpVtbl -> put_Filter(This,Criteria)
#define Recordset20_get_Sort(This,Criteria)	\
    (This)->lpVtbl -> get_Sort(This,Criteria)
#define Recordset20_put_Sort(This,Criteria)	\
    (This)->lpVtbl -> put_Sort(This,Criteria)
#define Recordset20_get_Status(This,pl)	\
    (This)->lpVtbl -> get_Status(This,pl)
#define Recordset20_get_State(This,plObjState)	\
    (This)->lpVtbl -> get_State(This,plObjState)
#define Recordset20__xClone(This,ppvObject)	\
    (This)->lpVtbl -> _xClone(This,ppvObject)
#define Recordset20_UpdateBatch(This,AffectRecords)	\
    (This)->lpVtbl -> UpdateBatch(This,AffectRecords)
#define Recordset20_CancelBatch(This,AffectRecords)	\
    (This)->lpVtbl -> CancelBatch(This,AffectRecords)
#define Recordset20_get_CursorLocation(This,plCursorLoc)	\
    (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)
#define Recordset20_put_CursorLocation(This,lCursorLoc)	\
    (This)->lpVtbl -> put_CursorLocation(This,lCursorLoc)
#define Recordset20_Supports(This,CursorOptions,pb)	\
    (This)->lpVtbl -> Supports(This,CursorOptions,pb)
#define Recordset20_get_Collect(This,Index,pvar)	\
    (This)->lpVtbl -> get_Collect(This,Index,pvar)
#define Recordset20_put_Collect(This,Index,value)	\
    (This)->lpVtbl -> put_Collect(This,Index,value)
#define Recordset20_get_MarshalOptions(This,peMarshal)	\
    (This)->lpVtbl -> get_MarshalOptions(This,peMarshal)
#define Recordset20_put_MarshalOptions(This,eMarshal)	\
    (This)->lpVtbl -> put_MarshalOptions(This,eMarshal)
#define Recordset20_Find(This,Criteria,SkipRecords,SearchDirection,Start)	\
    (This)->lpVtbl -> Find(This,Criteria,SkipRecords,SearchDirection,Start)
#define Recordset20_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)
#define Recordset20_get_DataSource(This,ppunkDataSource)	\
    (This)->lpVtbl -> get_DataSource(This,ppunkDataSource)
#define Recordset20_putref_DataSource(This,punkDataSource)	\
    (This)->lpVtbl -> putref_DataSource(This,punkDataSource)
#define Recordset20__xSave(This,FileName,PersistFormat)	\
    (This)->lpVtbl -> _xSave(This,FileName,PersistFormat)
#define Recordset20_get_ActiveCommand(This,ppCmd)	\
    (This)->lpVtbl -> get_ActiveCommand(This,ppCmd)
#define Recordset20_put_StayInSync(This,bStayInSync)	\
    (This)->lpVtbl -> put_StayInSync(This,bStayInSync)
#define Recordset20_get_StayInSync(This,pbStayInSync)	\
    (This)->lpVtbl -> get_StayInSync(This,pbStayInSync)
#define Recordset20_GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString)	\
    (This)->lpVtbl -> GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString)
#define Recordset20_CompareBookmarks(This,Bookmark1,Bookmark2,pCompare)	\
    (This)->lpVtbl -> CompareBookmarks(This,Bookmark1,Bookmark2,pCompare)
#define Recordset20_Clone(This,LockType,ppvObject)	\
    (This)->lpVtbl -> Clone(This,LockType,ppvObject)
#define Recordset20_Resync(This,AffectRecords,ResyncValues)	\
    (This)->lpVtbl -> Resync(This,AffectRecords,ResyncValues)
#define Recordset21_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Recordset21_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define Recordset21_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define Recordset21_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Recordset21_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Recordset21_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Recordset21_get_Properties(This,ppvObject)	\
    (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Recordset21_get_AbsolutePosition(This,pl)	\
    (This)->lpVtbl -> get_AbsolutePosition(This,pl)
#define Recordset21_put_AbsolutePosition(This,Position)	\
    (This)->lpVtbl -> put_AbsolutePosition(This,Position)
#define Recordset21_putref_ActiveConnection(This,pconn)	\
    (This)->lpVtbl -> putref_ActiveConnection(This,pconn)
#define Recordset21_put_ActiveConnection(This,vConn)	\
    (This)->lpVtbl -> put_ActiveConnection(This,vConn)
#define Recordset21_get_ActiveConnection(This,pvar)	\
    (This)->lpVtbl -> get_ActiveConnection(This,pvar)
#define Recordset21_get_BOF(This,pb)	\
    (This)->lpVtbl -> get_BOF(This,pb)
#define Recordset21_get_Bookmark(This,pvBookmark)	\
    (This)->lpVtbl -> get_Bookmark(This,pvBookmark)
#define Recordset21_put_Bookmark(This,vBookmark)	\
    (This)->lpVtbl -> put_Bookmark(This,vBookmark)
#define Recordset21_get_CacheSize(This,pl)	\
    (This)->lpVtbl -> get_CacheSize(This,pl)
#define Recordset21_put_CacheSize(This,CacheSize)	\
    (This)->lpVtbl -> put_CacheSize(This,CacheSize)
#define Recordset21_get_CursorType(This,plCursorType)	\
    (This)->lpVtbl -> get_CursorType(This,plCursorType)
#define Recordset21_put_CursorType(This,lCursorType)	\
    (This)->lpVtbl -> put_CursorType(This,lCursorType)
#define Recordset21_get_EOF(This,pb)	\
    (This)->lpVtbl -> get_EOF(This,pb)
#define Recordset21_get_Fields(This,ppvObject)	\
    (This)->lpVtbl -> get_Fields(This,ppvObject)
#define Recordset21_get_LockType(This,plLockType)	\
    (This)->lpVtbl -> get_LockType(This,plLockType)
#define Recordset21_put_LockType(This,lLockType)	\
    (This)->lpVtbl -> put_LockType(This,lLockType)
#define Recordset21_get_MaxRecords(This,plMaxRecords)	\
    (This)->lpVtbl -> get_MaxRecords(This,plMaxRecords)
#define Recordset21_put_MaxRecords(This,lMaxRecords)	\
    (This)->lpVtbl -> put_MaxRecords(This,lMaxRecords)
#define Recordset21_get_RecordCount(This,pl)	\
    (This)->lpVtbl -> get_RecordCount(This,pl)
#define Recordset21_putref_Source(This,pcmd)	\
    (This)->lpVtbl -> putref_Source(This,pcmd)
#define Recordset21_put_Source(This,bstrConn)	\
    (This)->lpVtbl -> put_Source(This,bstrConn)
#define Recordset21_get_Source(This,pvSource)	\
    (This)->lpVtbl -> get_Source(This,pvSource)
#define Recordset21_CancelUpdate(This)	\
    (This)->lpVtbl -> CancelUpdate(This)
#define Recordset21_Close(This)	\
    (This)->lpVtbl -> Close(This)
#define Recordset21_Delete(This,AffectRecords)	\
    (This)->lpVtbl -> Delete(This,AffectRecords)
#define Recordset21_GetRows(This,Rows,Start,Fields,pvar)	\
    (This)->lpVtbl -> GetRows(This,Rows,Start,Fields,pvar)
#define Recordset21_Move(This,NumRecords,Start)	\
    (This)->lpVtbl -> Move(This,NumRecords,Start)
#define Recordset21_MoveFirst(This)	\
    (This)->lpVtbl -> MoveFirst(This)
#define Recordset21_MoveLast(This)	\
    (This)->lpVtbl -> MoveLast(This)
#define Recordset21_Open(This,Source,ActiveConnection,CursorType,LockType,Options)	\
    (This)->lpVtbl -> Open(This,Source,ActiveConnection,CursorType,LockType,Options)
#define Recordset21_Requery(This,Options)	\
    (This)->lpVtbl -> Requery(This,Options)
#define Recordset21__xResync(This,AffectRecords)	\
    (This)->lpVtbl -> _xResync(This,AffectRecords)
#define Recordset21_Update(This,Fields,Values)	\
    (This)->lpVtbl -> Update(This,Fields,Values)
#define Recordset21_get_EditMode(This,pl)	\
    (This)->lpVtbl -> get_EditMode(This,pl)
#define Recordset21_get_Filter(This,Criteria)	\
    (This)->lpVtbl -> get_Filter(This,Criteria)
#define Recordset21_put_Filter(This,Criteria)	\
    (This)->lpVtbl -> put_Filter(This,Criteria)
#define Recordset21_get_Sort(This,Criteria)	\
    (This)->lpVtbl -> get_Sort(This,Criteria)
#define Recordset21_put_Sort(This,Criteria)	\
    (This)->lpVtbl -> put_Sort(This,Criteria)
#define Recordset21_get_Status(This,pl)	\
    (This)->lpVtbl -> get_Status(This,pl)
#define Recordset21_get_State(This,plObjState)	\
    (This)->lpVtbl -> get_State(This,plObjState)
#define Recordset21__xClone(This,ppvObject)	\
    (This)->lpVtbl -> _xClone(This,ppvObject)
#define Recordset21_UpdateBatch(This,AffectRecords)	\
    (This)->lpVtbl -> UpdateBatch(This,AffectRecords)
#define Recordset21_CancelBatch(This,AffectRecords)	\
    (This)->lpVtbl -> CancelBatch(This,AffectRecords)
#define Recordset21_get_CursorLocation(This,plCursorLoc)	\
    (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)
#define Recordset21_put_CursorLocation(This,lCursorLoc)	\
    (This)->lpVtbl -> put_CursorLocation(This,lCursorLoc)
#define Recordset21_Supports(This,CursorOptions,pb)	\
    (This)->lpVtbl -> Supports(This,CursorOptions,pb)
#define Recordset21_get_Collect(This,Index,pvar)	\
    (This)->lpVtbl -> get_Collect(This,Index,pvar)
#define Recordset21_put_Collect(This,Index,value)	\
    (This)->lpVtbl -> put_Collect(This,Index,value)
#define Recordset21_get_MarshalOptions(This,peMarshal)	\
    (This)->lpVtbl -> get_MarshalOptions(This,peMarshal)
#define Recordset21_put_MarshalOptions(This,eMarshal)	\
    (This)->lpVtbl -> put_MarshalOptions(This,eMarshal)
#define Recordset21_Find(This,Criteria,SkipRecords,SearchDirection,Start)	\
    (This)->lpVtbl -> Find(This,Criteria,SkipRecords,SearchDirection,Start)
#define Recordset21_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)
#define Recordset21_get_DataSource(This,ppunkDataSource)	\
    (This)->lpVtbl -> get_DataSource(This,ppunkDataSource)
#define Recordset21_putref_DataSource(This,punkDataSource)	\
    (This)->lpVtbl -> putref_DataSource(This,punkDataSource)
#define Recordset21__xSave(This,FileName,PersistFormat)	\
    (This)->lpVtbl -> _xSave(This,FileName,PersistFormat)
#define Recordset21_get_ActiveCommand(This,ppCmd)	\
    (This)->lpVtbl -> get_ActiveCommand(This,ppCmd)
#define Recordset21_put_StayInSync(This,bStayInSync)	\
    (This)->lpVtbl -> put_StayInSync(This,bStayInSync)
#define Recordset21_get_StayInSync(This,pbStayInSync)	\
    (This)->lpVtbl -> get_StayInSync(This,pbStayInSync)
#define Recordset21_GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString)	\
    (This)->lpVtbl -> GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString)
#define Recordset21_CompareBookmarks(This,Bookmark1,Bookmark2,pCompare)	\
    (This)->lpVtbl -> CompareBookmarks(This,Bookmark1,Bookmark2,pCompare)
#define Recordset21_Clone(This,LockType,ppvObject)	\
    (This)->lpVtbl -> Clone(This,LockType,ppvObject)
#define Recordset21_Resync(This,AffectRecords,ResyncValues)	\
    (This)->lpVtbl -> Resync(This,AffectRecords,ResyncValues)
#define Recordset21_Seek(This,KeyValues,SeekOption)	\
    (This)->lpVtbl -> Seek(This,KeyValues,SeekOption)
#define Recordset21_put_Index(This,Index)	\
    (This)->lpVtbl -> put_Index(This,Index)
#define Recordset21_get_Index(This,pbstrIndex)	\
    (This)->lpVtbl -> get_Index(This,pbstrIndex)
#define _Recordset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _Recordset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define _Recordset_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define _Recordset_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _Recordset_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Recordset_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Recordset_get_Properties(This,ppvObject)	\
    (This)->lpVtbl -> get_Properties(This,ppvObject)
#define _Recordset_get_AbsolutePosition(This,pl)	\
    (This)->lpVtbl -> get_AbsolutePosition(This,pl)
#define _Recordset_put_AbsolutePosition(This,Position)	\
    (This)->lpVtbl -> put_AbsolutePosition(This,Position)
#define _Recordset_putref_ActiveConnection(This,pconn)	\
    (This)->lpVtbl -> putref_ActiveConnection(This,pconn)
#define _Recordset_put_ActiveConnection(This,vConn)	\
    (This)->lpVtbl -> put_ActiveConnection(This,vConn)
#define _Recordset_get_ActiveConnection(This,pvar)	\
    (This)->lpVtbl -> get_ActiveConnection(This,pvar)
#define _Recordset_get_BOF(This,pb)	\
    (This)->lpVtbl -> get_BOF(This,pb)
#define _Recordset_get_Bookmark(This,pvBookmark)	\
    (This)->lpVtbl -> get_Bookmark(This,pvBookmark)
#define _Recordset_put_Bookmark(This,vBookmark)	\
    (This)->lpVtbl -> put_Bookmark(This,vBookmark)
#define _Recordset_get_CacheSize(This,pl)	\
    (This)->lpVtbl -> get_CacheSize(This,pl)
#define _Recordset_put_CacheSize(This,CacheSize)	\
    (This)->lpVtbl -> put_CacheSize(This,CacheSize)
#define _Recordset_get_CursorType(This,plCursorType)	\
    (This)->lpVtbl -> get_CursorType(This,plCursorType)
#define _Recordset_put_CursorType(This,lCursorType)	\
    (This)->lpVtbl -> put_CursorType(This,lCursorType)
#define _Recordset_get_EOF(This,pb)	\
    (This)->lpVtbl -> get_EOF(This,pb)
#define _Recordset_get_Fields(This,ppvObject)	\
    (This)->lpVtbl -> get_Fields(This,ppvObject)
#define _Recordset_get_LockType(This,plLockType)	\
    (This)->lpVtbl -> get_LockType(This,plLockType)
#define _Recordset_put_LockType(This,lLockType)	\
    (This)->lpVtbl -> put_LockType(This,lLockType)
#define _Recordset_get_MaxRecords(This,plMaxRecords)	\
    (This)->lpVtbl -> get_MaxRecords(This,plMaxRecords)
#define _Recordset_put_MaxRecords(This,lMaxRecords)	\
    (This)->lpVtbl -> put_MaxRecords(This,lMaxRecords)
#define _Recordset_get_RecordCount(This,pl)	\
    (This)->lpVtbl -> get_RecordCount(This,pl)
#define _Recordset_putref_Source(This,pcmd)	\
    (This)->lpVtbl -> putref_Source(This,pcmd)
#define _Recordset_put_Source(This,bstrConn)	\
    (This)->lpVtbl -> put_Source(This,bstrConn)
#define _Recordset_get_Source(This,pvSource)	\
    (This)->lpVtbl -> get_Source(This,pvSource)
#define _Recordset_CancelUpdate(This)	\
    (This)->lpVtbl -> CancelUpdate(This)
#define _Recordset_Close(This)	\
    (This)->lpVtbl -> Close(This)
#define _Recordset_Delete(This,AffectRecords)	\
    (This)->lpVtbl -> Delete(This,AffectRecords)
#define _Recordset_GetRows(This,Rows,Start,Fields,pvar)	\
    (This)->lpVtbl -> GetRows(This,Rows,Start,Fields,pvar)
#define _Recordset_Move(This,NumRecords,Start)	\
    (This)->lpVtbl -> Move(This,NumRecords,Start)
#define _Recordset_MoveFirst(This)	\
    (This)->lpVtbl -> MoveFirst(This)
#define _Recordset_MoveLast(This)	\
    (This)->lpVtbl -> MoveLast(This)
#define _Recordset_Open(This,Source,ActiveConnection,CursorType,LockType,Options)	\
    (This)->lpVtbl -> Open(This,Source,ActiveConnection,CursorType,LockType,Options)
#define _Recordset_Requery(This,Options)	\
    (This)->lpVtbl -> Requery(This,Options)
#define _Recordset__xResync(This,AffectRecords)	\
    (This)->lpVtbl -> _xResync(This,AffectRecords)
#define _Recordset_Update(This,Fields,Values)	\
    (This)->lpVtbl -> Update(This,Fields,Values)
#define _Recordset_get_EditMode(This,pl)	\
    (This)->lpVtbl -> get_EditMode(This,pl)
#define _Recordset_get_Filter(This,Criteria)	\
    (This)->lpVtbl -> get_Filter(This,Criteria)
#define _Recordset_put_Filter(This,Criteria)	\
    (This)->lpVtbl -> put_Filter(This,Criteria)
#define _Recordset_get_Sort(This,Criteria)	\
    (This)->lpVtbl -> get_Sort(This,Criteria)
#define _Recordset_put_Sort(This,Criteria)	\
    (This)->lpVtbl -> put_Sort(This,Criteria)
#define _Recordset_get_Status(This,pl)	\
    (This)->lpVtbl -> get_Status(This,pl)
#define _Recordset_get_State(This,plObjState)	\
    (This)->lpVtbl -> get_State(This,plObjState)
#define _Recordset__xClone(This,ppvObject)	\
    (This)->lpVtbl -> _xClone(This,ppvObject)
#define _Recordset_UpdateBatch(This,AffectRecords)	\
    (This)->lpVtbl -> UpdateBatch(This,AffectRecords)
#define _Recordset_CancelBatch(This,AffectRecords)	\
    (This)->lpVtbl -> CancelBatch(This,AffectRecords)
#define _Recordset_get_CursorLocation(This,plCursorLoc)	\
    (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)
#define _Recordset_put_CursorLocation(This,lCursorLoc)	\
    (This)->lpVtbl -> put_CursorLocation(This,lCursorLoc)
#define _Recordset_Supports(This,CursorOptions,pb)	\
    (This)->lpVtbl -> Supports(This,CursorOptions,pb)
#define _Recordset_get_Collect(This,Index,pvar)	\
    (This)->lpVtbl -> get_Collect(This,Index,pvar)
#define _Recordset_put_Collect(This,Index,value)	\
    (This)->lpVtbl -> put_Collect(This,Index,value)
#define _Recordset_get_MarshalOptions(This,peMarshal)	\
    (This)->lpVtbl -> get_MarshalOptions(This,peMarshal)
#define _Recordset_put_MarshalOptions(This,eMarshal)	\
    (This)->lpVtbl -> put_MarshalOptions(This,eMarshal)
#define _Recordset_Find(This,Criteria,SkipRecords,SearchDirection,Start)	\
    (This)->lpVtbl -> Find(This,Criteria,SkipRecords,SearchDirection,Start)
#define _Recordset_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)
#define _Recordset_get_DataSource(This,ppunkDataSource)	\
    (This)->lpVtbl -> get_DataSource(This,ppunkDataSource)
#define _Recordset_putref_DataSource(This,punkDataSource)	\
    (This)->lpVtbl -> putref_DataSource(This,punkDataSource)
#define _Recordset__xSave(This,FileName,PersistFormat)	\
    (This)->lpVtbl -> _xSave(This,FileName,PersistFormat)
#define _Recordset_get_ActiveCommand(This,ppCmd)	\
    (This)->lpVtbl -> get_ActiveCommand(This,ppCmd)
#define _Recordset_put_StayInSync(This,bStayInSync)	\
    (This)->lpVtbl -> put_StayInSync(This,bStayInSync)
#define _Recordset_get_StayInSync(This,pbStayInSync)	\
    (This)->lpVtbl -> get_StayInSync(This,pbStayInSync)
#define _Recordset_GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString)	\
    (This)->lpVtbl -> GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString)
#define _Recordset_CompareBookmarks(This,Bookmark1,Bookmark2,pCompare)	\
    (This)->lpVtbl -> CompareBookmarks(This,Bookmark1,Bookmark2,pCompare)
#define _Recordset_Clone(This,LockType,ppvObject)	\
    (This)->lpVtbl -> Clone(This,LockType,ppvObject)
#define _Recordset_Resync(This,AffectRecords,ResyncValues)	\
    (This)->lpVtbl -> Resync(This,AffectRecords,ResyncValues)
#define _Recordset_Seek(This,KeyValues,SeekOption)	\
    (This)->lpVtbl -> Seek(This,KeyValues,SeekOption)
#define _Recordset_put_Index(This,Index)	\
    (This)->lpVtbl -> put_Index(This,Index)
#define _Recordset_get_Index(This,pbstrIndex)	\
    (This)->lpVtbl -> get_Index(This,pbstrIndex)
#define _Recordset_Save(This,Destination,PersistFormat)	\
    (This)->lpVtbl -> Save(This,Destination,PersistFormat)
#define ADORecordsetConstruction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADORecordsetConstruction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ADORecordsetConstruction_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ADORecordsetConstruction_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ADORecordsetConstruction_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ADORecordsetConstruction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ADORecordsetConstruction_get_Rowset(This,ppRowset)	\
    (This)->lpVtbl -> get_Rowset(This,ppRowset)
#define ADORecordsetConstruction_put_Rowset(This,pRowset)	\
    (This)->lpVtbl -> put_Rowset(This,pRowset)
#define ADORecordsetConstruction_get_Chapter(This,plChapter)	\
    (This)->lpVtbl -> get_Chapter(This,plChapter)
#define ADORecordsetConstruction_put_Chapter(This,lChapter)	\
    (This)->lpVtbl -> put_Chapter(This,lChapter)
#define ADORecordsetConstruction_get_RowPosition(This,ppRowPos)	\
    (This)->lpVtbl -> get_RowPosition(This,ppRowPos)
#define ADORecordsetConstruction_put_RowPosition(This,pRowPos)	\
    (This)->lpVtbl -> put_RowPosition(This,pRowPos)
#define Field15_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Field15_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define Field15_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define Field15_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Field15_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Field15_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Field15_get_Properties(This,ppvObject)	\
    (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Field15_get_ActualSize(This,pl)	\
    (This)->lpVtbl -> get_ActualSize(This,pl)
#define Field15_get_Attributes(This,pl)	\
    (This)->lpVtbl -> get_Attributes(This,pl)
#define Field15_get_DefinedSize(This,pl)	\
    (This)->lpVtbl -> get_DefinedSize(This,pl)
#define Field15_get_Name(This,pbstr)	\
    (This)->lpVtbl -> get_Name(This,pbstr)
#define Field15_get_Type(This,pDataType)	\
    (This)->lpVtbl -> get_Type(This,pDataType)
#define Field15_get_Value(This,pvar)	\
    (This)->lpVtbl -> get_Value(This,pvar)
#define Field15_put_Value(This,Val)	\
    (This)->lpVtbl -> put_Value(This,Val)
#define Field15_get_Precision(This,pbPrecision)	\
    (This)->lpVtbl -> get_Precision(This,pbPrecision)
#define Field15_get_NumericScale(This,pbNumericScale)	\
    (This)->lpVtbl -> get_NumericScale(This,pbNumericScale)
#define Field15_AppendChunk(This,Data)	\
    (This)->lpVtbl -> AppendChunk(This,Data)
#define Field15_GetChunk(This,Length,pvar)	\
    (This)->lpVtbl -> GetChunk(This,Length,pvar)
#define Field15_get_OriginalValue(This,pvar)	\
    (This)->lpVtbl -> get_OriginalValue(This,pvar)
#define Field15_get_UnderlyingValue(This,pvar)	\
    (This)->lpVtbl -> get_UnderlyingValue(This,pvar)
#define Field20_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Field20_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define Field20_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define Field20_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Field20_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Field20_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Field20_get_Properties(This,ppvObject)	\
    (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Field20_get_ActualSize(This,pl)	\
    (This)->lpVtbl -> get_ActualSize(This,pl)
#define Field20_get_Attributes(This,pl)	\
    (This)->lpVtbl -> get_Attributes(This,pl)
#define Field20_get_DefinedSize(This,pl)	\
    (This)->lpVtbl -> get_DefinedSize(This,pl)
#define Field20_get_Name(This,pbstr)	\
    (This)->lpVtbl -> get_Name(This,pbstr)
#define Field20_get_Type(This,pDataType)	\
    (This)->lpVtbl -> get_Type(This,pDataType)
#define Field20_get_Value(This,pvar)	\
    (This)->lpVtbl -> get_Value(This,pvar)
#define Field20_put_Value(This,Val)	\
    (This)->lpVtbl -> put_Value(This,Val)
#define Field20_get_Precision(This,pbPrecision)	\
    (This)->lpVtbl -> get_Precision(This,pbPrecision)
#define Field20_get_NumericScale(This,pbNumericScale)	\
    (This)->lpVtbl -> get_NumericScale(This,pbNumericScale)
#define Field20_AppendChunk(This,Data)	\
    (This)->lpVtbl -> AppendChunk(This,Data)
#define Field20_GetChunk(This,Length,pvar)	\
    (This)->lpVtbl -> GetChunk(This,Length,pvar)
#define Field20_get_OriginalValue(This,pvar)	\
    (This)->lpVtbl -> get_OriginalValue(This,pvar)
#define Field20_get_UnderlyingValue(This,pvar)	\
    (This)->lpVtbl -> get_UnderlyingValue(This,pvar)
#define Field20_get_DataFormat(This,ppiDF)	\
    (This)->lpVtbl -> get_DataFormat(This,ppiDF)
#define Field20_putref_DataFormat(This,piDF)	\
    (This)->lpVtbl -> putref_DataFormat(This,piDF)
#define Field20_put_Precision(This,bPrecision)	\
    (This)->lpVtbl -> put_Precision(This,bPrecision)
#define Field20_put_NumericScale(This,bScale)	\
    (This)->lpVtbl -> put_NumericScale(This,bScale)
#define Field20_put_Type(This,DataType)	\
    (This)->lpVtbl -> put_Type(This,DataType)
#define Field20_put_DefinedSize(This,lSize)	\
    (This)->lpVtbl -> put_DefinedSize(This,lSize)
#define Field20_put_Attributes(This,lAttributes)	\
    (This)->lpVtbl -> put_Attributes(This,lAttributes)
#define Field_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Field_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define Field_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define Field_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Field_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Field_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Field_get_Properties(This,ppvObject)	\
    (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Field_get_ActualSize(This,pl)	\
    (This)->lpVtbl -> get_ActualSize(This,pl)
#define Field_get_Attributes(This,pl)	\
    (This)->lpVtbl -> get_Attributes(This,pl)
#define Field_get_DefinedSize(This,pl)	\
    (This)->lpVtbl -> get_DefinedSize(This,pl)
#define Field_get_Name(This,pbstr)	\
    (This)->lpVtbl -> get_Name(This,pbstr)
#define Field_get_Type(This,pDataType)	\
    (This)->lpVtbl -> get_Type(This,pDataType)
#define Field_get_Value(This,pvar)	\
    (This)->lpVtbl -> get_Value(This,pvar)
#define Field_put_Value(This,Val)	\
    (This)->lpVtbl -> put_Value(This,Val)
#define Field_get_Precision(This,pbPrecision)	\
    (This)->lpVtbl -> get_Precision(This,pbPrecision)
#define Field_get_NumericScale(This,pbNumericScale)	\
    (This)->lpVtbl -> get_NumericScale(This,pbNumericScale)
#define Field_AppendChunk(This,Data)	\
    (This)->lpVtbl -> AppendChunk(This,Data)
#define Field_GetChunk(This,Length,pvar)	\
    (This)->lpVtbl -> GetChunk(This,Length,pvar)
#define Field_get_OriginalValue(This,pvar)	\
    (This)->lpVtbl -> get_OriginalValue(This,pvar)
#define Field_get_UnderlyingValue(This,pvar)	\
    (This)->lpVtbl -> get_UnderlyingValue(This,pvar)
#define Field_get_DataFormat(This,ppiDF)	\
    (This)->lpVtbl -> get_DataFormat(This,ppiDF)
#define Field_putref_DataFormat(This,piDF)	\
    (This)->lpVtbl -> putref_DataFormat(This,piDF)
#define Field_put_Precision(This,bPrecision)	\
    (This)->lpVtbl -> put_Precision(This,bPrecision)
#define Field_put_NumericScale(This,bScale)	\
    (This)->lpVtbl -> put_NumericScale(This,bScale)
#define Field_put_Type(This,DataType)	\
    (This)->lpVtbl -> put_Type(This,DataType)
#define Field_put_DefinedSize(This,lSize)	\
    (This)->lpVtbl -> put_DefinedSize(This,lSize)
#define Field_put_Attributes(This,lAttributes)	\
    (This)->lpVtbl -> put_Attributes(This,lAttributes)
#define Field_get_Status(This,pFStatus)	\
    (This)->lpVtbl -> get_Status(This,pFStatus)
#define Fields15_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Fields15_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define Fields15_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define Fields15_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Fields15_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Fields15_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Fields15_get_Count(This,c)	\
    (This)->lpVtbl -> get_Count(This,c)
#define Fields15__NewEnum(This,ppvObject)	\
    (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define Fields15_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)
#define Fields15_get_Item(This,Index,ppvObject)	\
    (This)->lpVtbl -> get_Item(This,Index,ppvObject)
#define Fields20_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Fields20_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define Fields20_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define Fields20_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Fields20_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Fields20_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Fields20_get_Count(This,c)	\
    (This)->lpVtbl -> get_Count(This,c)
#define Fields20__NewEnum(This,ppvObject)	\
    (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define Fields20_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)
#define Fields20_get_Item(This,Index,ppvObject)	\
    (This)->lpVtbl -> get_Item(This,Index,ppvObject)
#define Fields20__Append(This,Name,Type,DefinedSize,Attrib)	\
    (This)->lpVtbl -> _Append(This,Name,Type,DefinedSize,Attrib)
#define Fields20_Delete(This,Index)	\
    (This)->lpVtbl -> Delete(This,Index)
#define Fields_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Fields_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define Fields_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define Fields_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Fields_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Fields_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Fields_get_Count(This,c)	\
    (This)->lpVtbl -> get_Count(This,c)
#define Fields__NewEnum(This,ppvObject)	\
    (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define Fields_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)
#define Fields_get_Item(This,Index,ppvObject)	\
    (This)->lpVtbl -> get_Item(This,Index,ppvObject)
#define Fields__Append(This,Name,Type,DefinedSize,Attrib)	\
    (This)->lpVtbl -> _Append(This,Name,Type,DefinedSize,Attrib)
#define Fields_Delete(This,Index)	\
    (This)->lpVtbl -> Delete(This,Index)
#define Fields_Append(This,Name,Type,DefinedSize,Attrib,FieldValue)	\
    (This)->lpVtbl -> Append(This,Name,Type,DefinedSize,Attrib,FieldValue)
#define Fields_Update(This)	\
    (This)->lpVtbl -> Update(This)
#define Fields_Resync(This,ResyncValues)	\
    (This)->lpVtbl -> Resync(This,ResyncValues)
#define Fields_CancelUpdate(This)	\
    (This)->lpVtbl -> CancelUpdate(This)

// public\sdk\inc\adojet.h
#define IReplica_get_ConflictTables(This,pprset)	\
    (This)->lpVtbl -> get_ConflictTables(This,pprset)
#define Filter_get_TableName(This,pbstr)	\
    (This)->lpVtbl -> get_TableName(This,pbstr)
#define Filters_Append(This,tableName,filterType,filterCriteria)	\
    (This)->lpVtbl -> Append(This,tableName,filterType,filterCriteria)

// public\sdk\inc\allerror.h
#define DB_E_NOTABLE                     ((HRESULT)0x80040E37L)
#define DB_E_BADTABLEID                  ((HRESULT)0x80040E3CL)
#define DB_E_DUPLICATETABLEID            ((HRESULT)0x80040E3FL)
#define DB_E_TABLEINUSE                  ((HRESULT)0x80040E40L)
#define DB_E_BADRECORDNUM                ((HRESULT)0x80040E42L)
#define SEC_E_INVALIDACCESSENTRY         ((HRESULT)0x80040E71L)
#define DB_S_BUFFERFULL                  ((HRESULT)0x00040EC8L)
#define DB_S_GOALCHANGED                 ((HRESULT)0x00040ECBL)

// public\sdk\inc\alphaops.h
#define IS_RETURN_0001_INSTRUCTION(Instruction) \
    (((Instruction) & 0xFFE0FFFF) == 0x6BE08001)
#define WRENTRY_FUNC    (PRIV_PAL_FUNC | 0x05)

// public\sdk\inc\amstream.h
#define IAMMediaTypeStream_CreateSample(This,lSampleSize,pbBuffer,dwFlags,pUnkOuter,ppAMMediaTypeSample)	\
    (This)->lpVtbl -> CreateSample(This,lSampleSize,pbBuffer,dwFlags,pUnkOuter,ppAMMediaTypeSample)

// public\sdk\inc\atl21\atlcom.h
#define DECLARE_PROTECT_FINAL_CONSTRUCT()\
	void InternalFinalConstructAddRef() {InternalAddRef();}\
	void InternalFinalConstructRelease() {InternalRelease();}
#define DECLARE_NOT_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComCreator< CComObject< x > >, CComFailCreator<CLASS_E_NOAGGREGATION> > _CreatorClass;
#define DECLARE_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComCreator< CComObject< x > >, CComCreator< CComAggObject< x > > > _CreatorClass;
#define DECLARE_ONLY_AGGREGATABLE(x) public:\
	typedef CComCreator2< CComFailCreator<E_FAIL>, CComCreator< CComAggObject< x > > > _CreatorClass;
#define DECLARE_POLY_AGGREGATABLE(x) public:\
	typedef CComCreator< CComPolyObject< x > > _CreatorClass;
#define COM_INTERFACE_ENTRY_BREAK(x)\
	{&IID_##x, \
	NULL, \
	_Break},
#define COM_INTERFACE_ENTRY_NOINTERFACE(x)\
	{&IID_##x, \
	NULL, \
	_NoInterface},
#define COM_INTERFACE_ENTRY_IMPL(x)\
	COM_INTERFACE_ENTRY_IID(IID_##x, x##Impl<_ComMapClass>)
#define COM_INTERFACE_ENTRY_IMPL_IID(iid, x)\
	COM_INTERFACE_ENTRY_IID(iid, x##Impl<_ComMapClass>)
#define COM_INTERFACE_ENTRY_FUNC(iid, dw, func)\
	{&iid, \
	dw, \
	func},
#define OBJECT_ENTRY(clsid, class) {&clsid, &class::UpdateRegistry, &class::_ClassFactoryCreatorClass::CreateInstance, &class::_CreatorClass::CreateInstance, NULL, 0, &class::GetObjectDescription },

// public\sdk\inc\atl21\atlctl.h
#define PROP_ENTRY(szDesc, dispid, clsid) \
		{OLESTR(szDesc), dispid, &clsid, &IID_IDispatch},
#define PROP_ENTRY_EX(szDesc, dispid, clsid, iidDispatch) \
		{OLESTR(szDesc), dispid, &clsid, &iidDispatch},

// public\sdk\inc\atl21\atlres.h
#define CB_ADDSTRING    (WM_USER+3)

// public\sdk\inc\atl30\atlcom.h
#define PROP_ENTRY(szDesc, dispid, clsid) \
                {OLESTR(szDesc), dispid, &clsid, &IID_IDispatch, 0, 0, 0},
#define PROP_ENTRY_EX(szDesc, dispid, clsid, iidDispatch) \
                {OLESTR(szDesc), dispid, &clsid, &iidDispatch, 0, 0, 0},
#define DECLARE_PROTECT_FINAL_CONSTRUCT()\
        void InternalFinalConstructAddRef() {InternalAddRef();}\
        void InternalFinalConstructRelease() {InternalRelease();}
#define DECLARE_NOT_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< CComObject< x > >, CComFailCreator<CLASS_E_NOAGGREGATION> > _CreatorClass;
#define DECLARE_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComCreator< CComObject< x > >, CComCreator< CComAggObject< x > > > _CreatorClass;
#define DECLARE_ONLY_AGGREGATABLE(x) public:\
        typedef CComCreator2< CComFailCreator<E_FAIL>, CComCreator< CComAggObject< x > > > _CreatorClass;
#define DECLARE_POLY_AGGREGATABLE(x) public:\
        typedef CComCreator< CComPolyObject< x > > _CreatorClass;
#define COM_INTERFACE_ENTRY_BREAK(x)\
        {&_ATL_IIDOF(x), \
        NULL, \
        _Break},
#define COM_INTERFACE_ENTRY_NOINTERFACE(x)\
        {&_ATL_IIDOF(x), \
        NULL, \
        _NoInterface},
#define COM_INTERFACE_ENTRY_IMPL(x)\
        COM_INTERFACE_ENTRY_IID(_ATL_IIDOF(x), x##Impl<_ComMapClass>)
#define COM_INTERFACE_ENTRY_IMPL_IID(iid, x)\
        COM_INTERFACE_ENTRY_IID(iid, x##Impl<_ComMapClass>)
#define COM_INTERFACE_ENTRY_FUNC(iid, dw, func)\
        {&iid, \
        dw, \
        func},
#define IMPLEMENTED_CATEGORY( catid ) { _ATL_CATMAP_ENTRY_IMPLEMENTED, &catid },
#define REQUIRED_CATEGORY( catid ) { _ATL_CATMAP_ENTRY_REQUIRED, &catid },
#define END_CATEGORY_MAP()\
   { _ATL_CATMAP_ENTRY_END, NULL } };\
   return( pMap ); }
#define OBJECT_ENTRY(clsid, class) {&clsid, class::UpdateRegistry, class::_ClassFactoryCreatorClass::CreateInstance, class::_CreatorClass::CreateInstance, NULL, 0, class::GetObjectDescription, class::GetCategoryMap, class::ObjectMain },
#define OBJECT_ENTRY_NON_CREATEABLE(class) {&CLSID_NULL, class::UpdateRegistry, NULL, NULL, NULL, 0, NULL, class::GetCategoryMap, class::ObjectMain },
#define SERVICE_ENTRY(x) \
                if (InlineIsEqualGUID(guidService, x)) \
                        return QueryInterface(riid, ppvObject);
#define BEGIN_SINK_MAP(_class)\
        static const _ATL_EVENT_ENTRY<_class>* _GetSinkMap()\
        {\
                typedef _class _atl_event_classtype;\
                static const _ATL_EVENT_ENTRY<_class> map[] = {

// public\sdk\inc\atl30\atldb.h
#define HETEROGENEOUSTABLES_Flags ( DBPROPFLAGS_DATASOURCEINFO | DBPROPFLAGS_READ )
#define MAXTABLESINSELECT_Flags ( DBPROPFLAGS_DATASOURCEINFO | DBPROPFLAGS_READ )
#define MULTITABLEUPDATE_Flags ( DBPROPFLAGS_DATASOURCEINFO | DBPROPFLAGS_READ )
#define STRUCTUREDSTORAGE_Flags ( DBPROPFLAGS_DATASOURCEINFO | DBPROPFLAGS_READ )
#define TABLETERM_Flags ( DBPROPFLAGS_DATASOURCEINFO | DBPROPFLAGS_READ )
#define TBL_TEMPTABLE_Flags ( DBPROPFLAGS_TABLE | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE )

// public\sdk\inc\atl30\atldbcli.h
#define BEGIN_PARAM_MAP(x) \
	public: \
	typedef x _classtype; \
	typedef x _ParamClass; \
	static bool HasParameters() { return true; } \
	static HRESULT _GetParamEntries(ULONG* pColumns, DBBINDING *pBinding, BYTE* pBuffer = NULL) \
	{ \
		ATLASSERT(pColumns != NULL); \
		DBPARAMIO eParamIO = DBPARAMIO_INPUT; \
		int nColumns = 0; \
		pBuffer;

// public\sdk\inc\atl30\atlsnap.h
#define EXTENSION_SNAPIN_NODEINFO_ENTRY(dataClass) \
		if (IsEqualGUID(guid, *(GUID*)m_##dataClass.GetNodeType())) \
		{ \
			*ppItem = m_##dataClass.GetExtNodeObject(pDataObject, &m_##dataClass); \
			_ASSERTE(*ppItem != NULL); \
			(*ppItem)->InitDataClass(pDataObject, &m_##dataClass); \
			return hr; \
		}
#define SNAPINCOMMAND_ENTRY(id, func) \
		if (id == nID) \
		{ \
			hr = func(bHandled, pObj); \
			if (bHandled) \
				return hr; \
		}
#define SNAPINCOMMAND_RANGE_ENTRY(id1, id2, func) \
		if (id1 >= nID && nID <= id2) \
		{ \
			hr = func(nID, bHandled, pObj); \
			if (bHandled) \
				return hr; \
		}

// public\sdk\inc\austream.h
#define IMemoryData_SetBuffer(This,cbSize,pbData,dwFlags)	\
    (This)->lpVtbl -> SetBuffer(This,cbSize,pbData,dwFlags)
#define IMemoryData_GetInfo(This,pdwLength,ppbData,pcbActualData)	\
    (This)->lpVtbl -> GetInfo(This,pdwLength,ppbData,pcbActualData)
#define IMemoryData_SetActual(This,cbDataValid)	\
    (This)->lpVtbl -> SetActual(This,cbDataValid)
#define IAudioData_SetBuffer(This,cbSize,pbData,dwFlags)	\
    (This)->lpVtbl -> SetBuffer(This,cbSize,pbData,dwFlags)
#define IAudioData_GetInfo(This,pdwLength,ppbData,pcbActualData)	\
    (This)->lpVtbl -> GetInfo(This,pdwLength,ppbData,pcbActualData)
#define IAudioData_SetActual(This,cbDataValid)	\
    (This)->lpVtbl -> SetActual(This,cbDataValid)

// public\sdk\inc\autodiscovery.h
#define IMailProtocolADEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMailProtocolADEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMailProtocolADEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMailProtocolADEntry_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IMailProtocolADEntry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IMailProtocolADEntry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IMailProtocolADEntry_get_Protocol(This,pbstr)	\
    (This)->lpVtbl -> get_Protocol(This,pbstr)
#define IMailProtocolADEntry_get_ServerName(This,pbstr)	\
    (This)->lpVtbl -> get_ServerName(This,pbstr)
#define IMailProtocolADEntry_get_ServerPort(This,pbstr)	\
    (This)->lpVtbl -> get_ServerPort(This,pbstr)
#define IMailProtocolADEntry_get_LoginName(This,pbstr)	\
    (This)->lpVtbl -> get_LoginName(This,pbstr)
#define IMailProtocolADEntry_get_PostHTML(This,pbstr)	\
    (This)->lpVtbl -> get_PostHTML(This,pbstr)
#define IMailProtocolADEntry_get_UseSSL(This,pfUseSSL)	\
    (This)->lpVtbl -> get_UseSSL(This,pfUseSSL)
#define IMailProtocolADEntry_get_IsAuthRequired(This,pfIsAuthRequired)	\
    (This)->lpVtbl -> get_IsAuthRequired(This,pfIsAuthRequired)
#define IMailProtocolADEntry_get_UseSPA(This,pfUseSPA)	\
    (This)->lpVtbl -> get_UseSPA(This,pfUseSPA)
#define IMailProtocolADEntry_get_SMTPUsesPOP3Auth(This,pfUsePOP3Auth)	\
    (This)->lpVtbl -> get_SMTPUsesPOP3Auth(This,pfUsePOP3Auth)

// public\sdk\inc\bdaiface.h
#define IBDA_IPSinkControl_GetAdapterIPAddress(This,pulcbSize,pbBuffer)	\
    (This)->lpVtbl -> GetAdapterIPAddress(This,pulcbSize,pbBuffer)
#define IBDA_IPSinkInfo_get_AdapterIPAddress(This,pbstrBuffer)	\
    (This)->lpVtbl -> get_AdapterIPAddress(This,pbstrBuffer)
#define IBDA_IPSinkInfo_get_AdapterDescription(This,pbstrBuffer)	\
    (This)->lpVtbl -> get_AdapterDescription(This,pbstrBuffer)
#define IEnumPIDMap_Skip(This,cRecords)	\
    (This)->lpVtbl -> Skip(This,cRecords)

// public\sdk\inc\bdatif.h
#define IGuideDataEvent_ScheduleEntryChanged(This,varScheduleEntryDescriptionID)	\
    (This)->lpVtbl -> ScheduleEntryChanged(This,varScheduleEntryDescriptionID)
#define IGuideDataEvent_ScheduleDeleted(This,varScheduleEntryDescriptionID)	\
    (This)->lpVtbl -> ScheduleDeleted(This,varScheduleEntryDescriptionID)
#define IGuideData_GetScheduleEntryIDs(This,pEnumScheduleEntries)	\
    (This)->lpVtbl -> GetScheduleEntryIDs(This,pEnumScheduleEntries)
#define IGuideData_GetScheduleEntryProperties(This,varScheduleEntryDescriptionID,ppEnumProperties)	\
    (This)->lpVtbl -> GetScheduleEntryProperties(This,varScheduleEntryDescriptionID,ppEnumProperties)

// public\sdk\inc\callobj.h
#define ICallFrame_GetMarshalSizeMax(This,pmshlContext,mshlflags,pcbBufferNeeded)	\
    (This)->lpVtbl -> GetMarshalSizeMax(This,pmshlContext,mshlflags,pcbBufferNeeded)
#define ICallFrame_Marshal(This,pmshlContext,mshlflags,pBuffer,cbBuffer,pcbBufferUsed,pdataRep,prpcFlags)	\
    (This)->lpVtbl -> Marshal(This,pmshlContext,mshlflags,pBuffer,cbBuffer,pcbBufferUsed,pdataRep,prpcFlags)
#define ICallFrame_Unmarshal(This,pBuffer,cbBuffer,dataRep,pcontext,pcbUnmarshalled)	\
    (This)->lpVtbl -> Unmarshal(This,pBuffer,cbBuffer,dataRep,pcontext,pcbUnmarshalled)
#define ICallFrame_ReleaseMarshalData(This,pBuffer,cbBuffer,ibFirstRelease,dataRep,pcontext)	\
    (This)->lpVtbl -> ReleaseMarshalData(This,pBuffer,cbBuffer,ibFirstRelease,dataRep,pcontext)
#define ICallIndirect_CallIndirect(This,phrReturn,iMethod,pvArgs,cbArgs)	\
    (This)->lpVtbl -> CallIndirect(This,phrReturn,iMethod,pvArgs,cbArgs)
#define ICallIndirect_GetStackSize(This,iMethod,cbArgs)	\
    (This)->lpVtbl -> GetStackSize(This,iMethod,cbArgs)
#define ICallInterceptor_CallIndirect(This,phrReturn,iMethod,pvArgs,cbArgs)	\
    (This)->lpVtbl -> CallIndirect(This,phrReturn,iMethod,pvArgs,cbArgs)
#define ICallInterceptor_GetStackSize(This,iMethod,cbArgs)	\
    (This)->lpVtbl -> GetStackSize(This,iMethod,cbArgs)
#define ICallUnmarshal_Unmarshal(This,iMethod,pBuffer,cbBuffer,fForceBufferCopy,dataRep,pcontext,pcbUnmarshalled,ppFrame)	\
    (This)->lpVtbl -> Unmarshal(This,iMethod,pBuffer,cbBuffer,fForceBufferCopy,dataRep,pcontext,pcbUnmarshalled,ppFrame)
#define ICallUnmarshal_ReleaseMarshalData(This,iMethod,pBuffer,cbBuffer,ibFirstRelease,dataRep,pcontext)	\
    (This)->lpVtbl -> ReleaseMarshalData(This,iMethod,pBuffer,cbBuffer,ibFirstRelease,dataRep,pcontext)

// public\sdk\inc\cdosys.h
#define IMessage_get_EnvelopeFields(This,varEnvelopeFields)	\
    (This)->lpVtbl -> get_EnvelopeFields(This,varEnvelopeFields)
#define IMessage_get_Fields(This,varFields)	\
    (This)->lpVtbl -> get_Fields(This,varFields)
#define IBodyPart_get_Fields(This,varFields)	\
    (This)->lpVtbl -> get_Fields(This,varFields)
#define IBodyPart_GetFieldParameter(This,FieldName,Parameter,pbstrValue)	\
    (This)->lpVtbl -> GetFieldParameter(This,FieldName,Parameter,pbstrValue)
#define IConfiguration_get_Fields(This,varFields)	\
    (This)->lpVtbl -> get_Fields(This,varFields)

// public\sdk\inc\certadm.h
#define ICertAdmin2_GetConfigEntry(This,strConfig,strNodePath,strEntryName,pvarEntry)	\
    (This)->lpVtbl -> GetConfigEntry(This,strConfig,strNodePath,strEntryName,pvarEntry)
#define ICertAdmin2_SetConfigEntry(This,strConfig,strNodePath,strEntryName,pvarEntry)	\
    (This)->lpVtbl -> SetConfigEntry(This,strConfig,strNodePath,strEntryName,pvarEntry)
#define ICertAdmin2_DeleteRow(This,strConfig,Flags,Date,Table,RowId,pcDeleted)	\
    (This)->lpVtbl -> DeleteRow(This,strConfig,Flags,Date,Table,RowId,pcDeleted)

// public\sdk\inc\certcli.h
#define ICertConfig_GetField(This,strFieldName,pstrOut)	\
    (This)->lpVtbl -> GetField(This,strFieldName,pstrOut)
#define ICertConfig2_GetField(This,strFieldName,pstrOut)	\
    (This)->lpVtbl -> GetField(This,strFieldName,pstrOut)

// public\sdk\inc\certdb.h
#define ICertDBRow_SetProperty(This,pwszPropName,dwFlags,cbProp,pbProp)	\
    (This)->lpVtbl -> SetProperty(This,pwszPropName,dwFlags,cbProp,pbProp)
#define ICertDBRow_GetProperty(This,pwszPropName,dwFlags,pcbProp,pbProp)	\
    (This)->lpVtbl -> GetProperty(This,pwszPropName,dwFlags,pcbProp,pbProp)
#define ICertDBRow_SetExtension(This,pwszExtensionName,dwExtFlags,cbValue,pbValue)	\
    (This)->lpVtbl -> SetExtension(This,pwszExtensionName,dwExtFlags,cbValue,pbValue)
#define ICertDBRow_GetExtension(This,pwszExtensionName,pdwExtFlags,pcbValue,pbValue)	\
    (This)->lpVtbl -> GetExtension(This,pwszExtensionName,pdwExtFlags,pcbValue,pbValue)
#define ICertDBBackup_ReadFile(This,pcb,pb)	\
    (This)->lpVtbl -> ReadFile(This,pcb,pb)
#define ICertDB_EnumCertDBColumn(This,dwTable,ppenum)	\
    (This)->lpVtbl -> EnumCertDBColumn(This,dwTable,ppenum)

// public\sdk\inc\certenc.h
#define ICertEncodeCRLDistInfo_SetNameEntry(This,DistPointIndex,NameIndex,NameChoice,strName)	\
    (This)->lpVtbl -> SetNameEntry(This,DistPointIndex,NameIndex,NameChoice,strName)
#define ICertEncodeAltName_SetNameEntry(This,NameIndex,NameChoice,strName)	\
    (This)->lpVtbl -> SetNameEntry(This,NameIndex,NameChoice,strName)

// public\sdk\inc\certview.h
#define ICertView2_SetTable(This,Table)	\
    (This)->lpVtbl -> SetTable(This,Table)

// public\sdk\inc\cfg.h
#define CM_PROB_FAILED_DRIVER_ENTRY        (0x00000025)   // DriverEntry() failed.

// public\sdk\inc\cierror.h
#define WBREAK_E_BUFFER_TOO_SMALL        ((HRESULT)0x80041783L)
#define CI_CORRUPT_FILTER_BUFFER         ((HRESULT)0xC0041807L)
#define CI_E_BUFFERTOOSMALL              ((HRESULT)0x8004180CL)

// public\sdk\inc\ciintf.h
#define ICiCDocName_Init(This,pbName,cbName)	\
    (This)->lpVtbl -> Init(This,pbName,cbName)
#define ICiCDocName_Get(This,pbName,pcbName)	\
    (This)->lpVtbl -> Get(This,pbName,pcbName)
#define ICiCDocName_GetNameBuffer(This,ppName,pcbName)	\
    (This)->lpVtbl -> GetNameBuffer(This,ppName,pcbName)
#define ICiCDocName_GetBufSizeNeeded(This,pcbName)	\
    (This)->lpVtbl -> GetBufSizeNeeded(This,pcbName)
#define ICiCOpenedDoc_Open(This,pbDocName,cbDocName)	\
    (This)->lpVtbl -> Open(This,pbDocName,cbDocName)
#define ICiCOpenedDoc_GetSecurity(This,pbData,pcbData)	\
    (This)->lpVtbl -> GetSecurity(This,pbData,pcbData)
#define ICiCAdviseStatus_NotifyEvent(This,fType,eventId,nParams,aParams,cbData,data)	\
    (This)->lpVtbl -> NotifyEvent(This,fType,eventId,nParams,aParams,cbData,data)
#define ICiCFilterClient_Init(This,pbData,cbData,pICiAdminParams)	\
    (This)->lpVtbl -> Init(This,pbData,cbData,pICiAdminParams)
#define ICiCDocStore_StoreSecurity(This,wid,pbSecurity,cbSecurity)	\
    (This)->lpVtbl -> StoreSecurity(This,wid,pbSecurity,cbSecurity)
#define ICiCDocStoreEx_StoreSecurity(This,wid,pbSecurity,cbSecurity)	\
    (This)->lpVtbl -> StoreSecurity(This,wid,pbSecurity,cbSecurity)
#define ICiCPropertyStorage_FetchValueByPid(This,workId,pid,pbData,pcb)	\
    (This)->lpVtbl -> FetchValueByPid(This,workId,pid,pbData,pcb)
#define ICiCPropertyStorage_FetchValueByPropSpec(This,workId,pPropSpec,pbData,pcb)	\
    (This)->lpVtbl -> FetchValueByPropSpec(This,workId,pPropSpec,pbData,pcb)
#define ICiCPropRetriever_RetrieveValueByPid(This,pid,pbData,pcb)	\
    (This)->lpVtbl -> RetrieveValueByPid(This,pid,pbData,pcb)
#define ICiCPropRetriever_RetrieveValueByPropSpec(This,pPropSpec,pbData,pcb)	\
    (This)->lpVtbl -> RetrieveValueByPropSpec(This,pPropSpec,pbData,pcb)
#define ICiManager_StartFiltering(This,cbData,pbData)	\
    (This)->lpVtbl -> StartFiltering(This,cbData,pbData)
#define ICiIndexNotification_AddNotification(This,wid,pIndexNotifStatus,ppIndexNotifEntry)	\
    (This)->lpVtbl -> AddNotification(This,wid,pIndexNotifStatus,ppIndexNotifEntry)
#define ICiIndexNotification_ModifyNotification(This,wid,pIndexNotifStatus,ppIndexNotifEntry)	\
    (This)->lpVtbl -> ModifyNotification(This,wid,pIndexNotifStatus,ppIndexNotifEntry)
#define ICiIndexNotificationEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICiIndexNotificationEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICiIndexNotificationEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICiIndexNotificationEntry_AddText(This,pStatChunk,pwszText)	\
    (This)->lpVtbl -> AddText(This,pStatChunk,pwszText)
#define ICiIndexNotificationEntry_AddProperty(This,pStatChunk,pPropVariant)	\
    (This)->lpVtbl -> AddProperty(This,pStatChunk,pPropVariant)
#define ICiIndexNotificationEntry_AddCompleted(This,fAbort)	\
    (This)->lpVtbl -> AddCompleted(This,fAbort)
#define ICiCScope_Init(This,cbData,pbData)	\
    (This)->lpVtbl -> Init(This,cbData,pbData)
#define ICiCScope_GetScope(This,pbScope,pcbData)	\
    (This)->lpVtbl -> GetScope(This,pbScope,pcbData)
#define ICiCUserSecurity_Init(This,cbData,pbData)	\
    (This)->lpVtbl -> Init(This,cbData,pbData)
#define ICiCUserSecurity_GetSecurityInfo(This,pbData,pcbData)	\
    (This)->lpVtbl -> GetSecurityInfo(This,pbData,pcbData)
#define ICiCEventLogItem_AddData(This,cbData,pbData)	\
    (This)->lpVtbl -> AddData(This,cbData,pbData)
#define ICiCFilterStatus_PreFilter(This,pbName,cbName)	\
    (This)->lpVtbl -> PreFilter(This,pbName,cbName)
#define ICiCFilterStatus_PostFilter(This,pbName,cbName,scFilterStatus)	\
    (This)->lpVtbl -> PostFilter(This,pbName,cbName,scFilterStatus)

// public\sdk\inc\clusapi.h
#define CLUSPROP_BINARY_DECLARE( name, cb ) \
    struct {                                \
        CLUSPROP_SYNTAX Syntax;             \
        DWORD           cbLength;           \
        BYTE            rgb[(cb + 3) & ~3]; \
    } name
#define CLUSPROP_SZ_DECLARE( name, cch )    \
    struct {                                \
        CLUSPROP_SYNTAX Syntax;             \
        DWORD           cbLength;           \
        WCHAR           sz[(cch + 1) & ~1]; \
    } name

// public\sdk\inc\cluscfgserver.h
#define IClusCfgResourceCreate_SetPropertyBinary(This,pcszNameIn,cbSizeIn,pbyteIn)	\
    (This)->lpVtbl -> SetPropertyBinary(This,pcszNameIn,cbSizeIn,pbyteIn)
#define IClusCfgResourceCreate_SetPropertyMultiString(This,pcszNameIn,cbMultiStringIn,pcszMultiStringIn)	\
    (This)->lpVtbl -> SetPropertyMultiString(This,pcszNameIn,cbMultiStringIn,pcszMultiStringIn)
#define IClusCfgResourceCreate_SendResourceControl(This,dwControlCodeIn,lpBufferIn,cbBufferSizeIn)	\
    (This)->lpVtbl -> SendResourceControl(This,dwControlCodeIn,lpBufferIn,cbBufferSizeIn)
#define IClusCfgResourcePostCreate_SendResourceControl(This,dwControlCodeIn,lpBufferIn,cbBufferSizeIn,lBufferInout,cbOutBufferSizeIn,lpcbBytesReturnedOut)	\
    (This)->lpVtbl -> SendResourceControl(This,dwControlCodeIn,lpBufferIn,cbBufferSizeIn,lBufferInout,cbOutBufferSizeIn,lpcbBytesReturnedOut)

// public\sdk\inc\commctrl.h
#define TB_BUTTONSTRUCTSIZE     (WM_USER + 30)
#define TreeView_InsertItem(hwnd, lpis) \
    (HTREEITEM)SNDMSG((hwnd), TVM_INSERTITEM, 0, (LPARAM)(LPTV_INSERTSTRUCT)(lpis))
#define TreeView_SortChildrenCB(hwnd, psort, recurse) \
    (BOOL)SNDMSG((hwnd), TVM_SORTCHILDRENCB, (WPARAM)(recurse), \
    (LPARAM)(LPTV_SORTCB)(psort))
#define CBEM_INSERTITEMA        (WM_USER + 1)
#define CBEM_GETITEMA           (WM_USER + 4)
#define CBEM_SETITEMA           (WM_USER + 5)
#define CBEM_GETCOMBOCONTROL    (WM_USER + 6)
#define CBEM_GETEDITCONTROL     (WM_USER + 7)
#define CBEM_SETEXSTYLE         (WM_USER + 8)  // use  SETEXTENDEDSTYLE instead
#define CBEM_SETEXTENDEDSTYLE   (WM_USER + 14)   // lparam == new style, wParam (optional) == mask
#define CBEM_GETEXSTYLE         (WM_USER + 9) // use GETEXTENDEDSTYLE instead
#define CBEM_GETEXTENDEDSTYLE   (WM_USER + 9)
#define CBEM_SETEXSTYLE         (WM_USER + 8)
#define CBEM_GETEXSTYLE         (WM_USER + 9)
#define CBEM_HASEDITCHANGED     (WM_USER + 10)
#define CBEM_INSERTITEMW        (WM_USER + 11)
#define CBEM_SETITEMW           (WM_USER + 12)
#define CBEM_GETITEMW           (WM_USER + 13)
#define TabCtrl_SetItemExtra(hwndTC, cb) \
    (BOOL)SNDMSG((hwndTC), TCM_SETITEMEXTRA, (WPARAM)(cb), 0L)
#define IPM_GETADDRESS   (WM_USER+102) // lresult = # of non black fields.  lparam = LPDWORD for TCP/IP address
#define IPM_SETRANGE (WM_USER+103) // wparam = field, lparam = range
#define IPM_SETFOCUS (WM_USER+104) // wparam = field
#define ComboBox_SetMinVisible(hwnd, iMinVisible) \
            (BOOL)SNDMSG((hwnd), CB_SETMINVISIBLE, (WPARAM)iMinVisible, 0)
#define ComboBox_GetMinVisible(hwnd) \
            (int)SNDMSG((hwnd), CB_GETMINVISIBLE, 0, 0)

// public\sdk\inc\comsvcs.h
#define IComSecurityEvents_OnAuthenticate(This,pInfo,guidActivity,ObjectID,guidIID,iMeth,cbByteOrig,pSidOriginalUser,cbByteCur,pSidCurrentUser,bCurrentUserInpersonatingInProc)	\
    (This)->lpVtbl -> OnAuthenticate(This,pInfo,guidActivity,ObjectID,guidIID,iMeth,cbByteOrig,pSidOriginalUser,cbByteCur,pSidCurrentUser,bCurrentUserInpersonatingInProc)
#define IComSecurityEvents_OnAuthenticateFail(This,pInfo,guidActivity,ObjectID,guidIID,iMeth,cbByteOrig,pSidOriginalUser,cbByteCur,pSidCurrentUser,bCurrentUserInpersonatingInProc)	\
    (This)->lpVtbl -> OnAuthenticateFail(This,pInfo,guidActivity,ObjectID,guidIID,iMeth,cbByteOrig,pSidOriginalUser,cbByteCur,pSidCurrentUser,bCurrentUserInpersonatingInProc)
#define IComObjectConstructionEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IComObjectConstructionEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IComObjectConstructionEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IComObjectConstructionEvents_OnObjectConstruct(This,pInfo,guidObject,sConstructString,oid)	\
    (This)->lpVtbl -> OnObjectConstruct(This,pInfo,guidObject,sConstructString,oid)
#define IComCRMEvents_OnCRMAnalyze(This,pInfo,guidClerkCLSID,dwCrmRecordType,dwRecordSize)	\
    (This)->lpVtbl -> OnCRMAnalyze(This,pInfo,guidClerkCLSID,dwCrmRecordType,dwRecordSize)
#define IComCRMEvents_OnCRMWrite(This,pInfo,guidClerkCLSID,fVariants,dwRecordSize)	\
    (This)->lpVtbl -> OnCRMWrite(This,pInfo,guidClerkCLSID,fVariants,dwRecordSize)
#define IComCRMEvents_OnCRMDeliver(This,pInfo,guidClerkCLSID,fVariants,dwRecordSize)	\
    (This)->lpVtbl -> OnCRMDeliver(This,pInfo,guidClerkCLSID,fVariants,dwRecordSize)
#define IComObjectConstruction2Events_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IComObjectConstruction2Events_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IComObjectConstruction2Events_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IComObjectConstruction2Events_OnObjectConstruct2(This,pInfo,guidObject,sConstructString,oid,guidPartition)	\
    (This)->lpVtbl -> OnObjectConstruct2(This,pInfo,guidObject,sConstructString,oid,guidPartition)
#define IObjectConstruct_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IObjectConstruct_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IObjectConstruct_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IObjectConstruct_Construct(This,pCtorObj)	\
    (This)->lpVtbl -> Construct(This,pCtorObj)
#define IObjectConstructString_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IObjectConstructString_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IObjectConstructString_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IObjectConstructString_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IObjectConstructString_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IObjectConstructString_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IObjectConstructString_get_ConstructString(This,pVal)	\
    (This)->lpVtbl -> get_ConstructString(This,pVal)
#define ICrmLogControl_WriteLogRecordVariants(This,pLogRecord)	\
    (This)->lpVtbl -> WriteLogRecordVariants(This,pLogRecord)
#define ICrmLogControl_ForgetLogRecord(This)	\
    (This)->lpVtbl -> ForgetLogRecord(This)
#define ICrmLogControl_WriteLogRecord(This,rgBlob,cBlob)	\
    (This)->lpVtbl -> WriteLogRecord(This,rgBlob,cBlob)
#define ICrmCompensatorVariants_PrepareRecordVariants(This,pLogRecord,pbForget)	\
    (This)->lpVtbl -> PrepareRecordVariants(This,pLogRecord,pbForget)
#define ICrmCompensatorVariants_CommitRecordVariants(This,pLogRecord,pbForget)	\
    (This)->lpVtbl -> CommitRecordVariants(This,pLogRecord,pbForget)
#define ICrmCompensatorVariants_AbortRecordVariants(This,pLogRecord,pbForget)	\
    (This)->lpVtbl -> AbortRecordVariants(This,pLogRecord,pbForget)
#define ICrmCompensator_PrepareRecord(This,crmLogRec,pfForget)	\
    (This)->lpVtbl -> PrepareRecord(This,crmLogRec,pfForget)
#define ICrmCompensator_CommitRecord(This,crmLogRec,pfForget)	\
    (This)->lpVtbl -> CommitRecord(This,crmLogRec,pfForget)
#define ICrmCompensator_AbortRecord(This,crmLogRec,pfForget)	\
    (This)->lpVtbl -> AbortRecord(This,crmLogRec,pfForget)
#define ICrmMonitorLogRecords_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICrmMonitorLogRecords_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICrmMonitorLogRecords_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICrmMonitorLogRecords_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)
#define ICrmMonitorLogRecords_get_TransactionState(This,pVal)	\
    (This)->lpVtbl -> get_TransactionState(This,pVal)
#define ICrmMonitorLogRecords_get_StructuredRecords(This,pVal)	\
    (This)->lpVtbl -> get_StructuredRecords(This,pVal)
#define ICrmMonitorLogRecords_GetLogRecord(This,dwIndex,pCrmLogRec)	\
    (This)->lpVtbl -> GetLogRecord(This,dwIndex,pCrmLogRec)
#define ICrmMonitorLogRecords_GetLogRecordVariants(This,IndexNumber,pLogRecord)	\
    (This)->lpVtbl -> GetLogRecordVariants(This,IndexNumber,pLogRecord)
#define ICrmFormatLogRecords_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICrmFormatLogRecords_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICrmFormatLogRecords_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICrmFormatLogRecords_GetColumnCount(This,plColumnCount)	\
    (This)->lpVtbl -> GetColumnCount(This,plColumnCount)
#define ICrmFormatLogRecords_GetColumnHeaders(This,pHeaders)	\
    (This)->lpVtbl -> GetColumnHeaders(This,pHeaders)
#define ICrmFormatLogRecords_GetColumn(This,CrmLogRec,pFormattedLogRecord)	\
    (This)->lpVtbl -> GetColumn(This,CrmLogRec,pFormattedLogRecord)
#define ICrmFormatLogRecords_GetColumnVariants(This,LogRecord,pFormattedLogRecord)	\
    (This)->lpVtbl -> GetColumnVariants(This,LogRecord,pFormattedLogRecord)

// public\sdk\inc\control.h
#define IBasicVideo_GetCurrentImage(This,pBufferSize,pDIBImage)	\
    (This)->lpVtbl -> GetCurrentImage(This,pBufferSize,pDIBImage)
#define IBasicVideo2_GetCurrentImage(This,pBufferSize,pDIBImage)	\
    (This)->lpVtbl -> GetCurrentImage(This,pBufferSize,pDIBImage)

// public\sdk\inc\crmcompensator.h
#define ICrmCompensatorVariants_PrepareRecordVariants(This,pLogRecord,pbForget)	\
    (This)->lpVtbl -> PrepareRecordVariants(This,pLogRecord,pbForget)
#define ICrmCompensatorVariants_CommitRecordVariants(This,pLogRecord,pbForget)	\
    (This)->lpVtbl -> CommitRecordVariants(This,pLogRecord,pbForget)
#define ICrmCompensatorVariants_AbortRecordVariants(This,pLogRecord,pbForget)	\
    (This)->lpVtbl -> AbortRecordVariants(This,pLogRecord,pbForget)
#define ICrmCompensator_PrepareRecord(This,crmLogRec,pfForget)	\
    (This)->lpVtbl -> PrepareRecord(This,crmLogRec,pfForget)
#define ICrmCompensator_CommitRecord(This,crmLogRec,pfForget)	\
    (This)->lpVtbl -> CommitRecord(This,crmLogRec,pfForget)
#define ICrmCompensator_AbortRecord(This,crmLogRec,pfForget)	\
    (This)->lpVtbl -> AbortRecord(This,crmLogRec,pfForget)

// public\sdk\inc\crmformat.h
#define ICrmFormatLogRecords_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICrmFormatLogRecords_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICrmFormatLogRecords_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICrmFormatLogRecords_GetColumnCount(This,plColumnCount)	\
    (This)->lpVtbl -> GetColumnCount(This,plColumnCount)
#define ICrmFormatLogRecords_GetColumnHeaders(This,pHeaders)	\
    (This)->lpVtbl -> GetColumnHeaders(This,pHeaders)
#define ICrmFormatLogRecords_GetColumn(This,CrmLogRec,pFormattedLogRecord)	\
    (This)->lpVtbl -> GetColumn(This,CrmLogRec,pFormattedLogRecord)
#define ICrmFormatLogRecords_GetColumnVariants(This,LogRecord,pFormattedLogRecord)	\
    (This)->lpVtbl -> GetColumnVariants(This,LogRecord,pFormattedLogRecord)

// public\sdk\inc\crmlogcontrol.h
#define ICrmLogControl_WriteLogRecordVariants(This,pLogRecord)	\
    (This)->lpVtbl -> WriteLogRecordVariants(This,pLogRecord)
#define ICrmLogControl_ForgetLogRecord(This)	\
    (This)->lpVtbl -> ForgetLogRecord(This)
#define ICrmLogControl_WriteLogRecord(This,rgBlob,cBlob)	\
    (This)->lpVtbl -> WriteLogRecord(This,rgBlob,cBlob)

// public\sdk\inc\crmmonitor.h
#define ICrmMonitorLogRecords_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICrmMonitorLogRecords_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICrmMonitorLogRecords_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICrmMonitorLogRecords_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)
#define ICrmMonitorLogRecords_get_TransactionState(This,pVal)	\
    (This)->lpVtbl -> get_TransactionState(This,pVal)
#define ICrmMonitorLogRecords_get_StructuredRecords(This,pVal)	\
    (This)->lpVtbl -> get_StructuredRecords(This,pVal)
#define ICrmMonitorLogRecords_GetLogRecord(This,dwIndex,pCrmLogRec)	\
    (This)->lpVtbl -> GetLogRecord(This,dwIndex,pCrmLogRec)
#define ICrmMonitorLogRecords_GetLogRecordVariants(This,IndexNumber,pLogRecord)	\
    (This)->lpVtbl -> GetLogRecordVariants(This,IndexNumber,pLogRecord)

// public\sdk\inc\ctffunc.h
#define ITfFnReconversion_QueryRange(This,pRange,ppNewRange,pfConvertable)	\
    (This)->lpVtbl -> QueryRange(This,pRange,ppNewRange,pfConvertable)

// public\sdk\inc\d3d.h
#define IDirect3DExecuteBuffer_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DExecuteBuffer_Release(p) (p)->Release()
#define IDirect3DVertexBuffer_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DVertexBuffer_Release(p) (p)->Release()
#define IDirect3DVertexBuffer7_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DVertexBuffer7_Release(p) (p)->Release()
#define D3DERR_VERTEXBUFFEROPTIMIZED            MAKE_DDHRESULT(2060)
#define D3DERR_VERTEXBUFFERLOCKED               MAKE_DDHRESULT(2062)
#define D3DERR_VERTEXBUFFERUNLOCKFAILED         MAKE_DDHRESULT(2063)
#define D3DERR_ZBUFFER_NOTPRESENT               MAKE_DDHRESULT(2070)
#define D3DERR_STENCILBUFFER_NOTPRESENT         MAKE_DDHRESULT(2071)

// public\sdk\inc\d3d8.h
#define IDirect3DVertexBuffer8_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DVertexBuffer8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
#define IDirect3DVertexBuffer8_Release(p) (p)->Release()
#define IDirect3DVertexBuffer8_FreePrivateData(p,a) (p)->FreePrivateData(a)
#define IDirect3DIndexBuffer8_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DIndexBuffer8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
#define IDirect3DIndexBuffer8_Release(p) (p)->Release()
#define IDirect3DIndexBuffer8_FreePrivateData(p,a) (p)->FreePrivateData(a)

// public\sdk\inc\d3drm.h
#define D3DRMERR_INCOMPATABLEKEY        MAKE_DDHRESULT(809)

// public\sdk\inc\d3drmdef.h
#define D3DRMCLEAR_ALL                  (D3DRMCLEAR_TARGET | \
					 D3DRMCLEAR_ZBUFFER | \
					 D3DRMCLEAR_DIRTYRECTS)

// public\sdk\inc\d3dxerr.h
#define D3DXERR_NOZBUFFERAVAILABLE    ((HRESULT)0xC8770BBFL)
#define D3DXERR_NOBACKBUFFERAVAILABLE    ((HRESULT)0xC8770BC0L)
#define D3DXERR_NOZBUFFER    ((HRESULT)0xC8770BC2L)
#define D3DXERR_CAPSNOTSUPPORTED    ((HRESULT)0xC8770BCBL)
#define D3DXERR_FRONTBUFFERALREADYEXISTS    ((HRESULT)0xC8770BD1L)

// public\sdk\inc\danim.h
#define IDAView_QueryHitPoint(This,dwAspect,prcBounds,ptLoc,lCloseHint,pHitResult)	\
    (This)->lpVtbl -> QueryHitPoint(This,dwAspect,prcBounds,ptLoc,lCloseHint,pHitResult)
#define IDAGeometry_Undetectable(This,ret_0)	\
    (This)->lpVtbl -> Undetectable(This,ret_0)
#define IDAImage_Undetectable(This,ret_0)	\
    (This)->lpVtbl -> Undetectable(This,ret_0)
#define IDA2Geometry_Undetectable(This,ret_0)	\
    (This)->lpVtbl -> Undetectable(This,ret_0)
#define IDA2Image_Undetectable(This,ret_0)	\
    (This)->lpVtbl -> Undetectable(This,ret_0)
#define IDA3Geometry_Undetectable(This,ret_0)	\
    (This)->lpVtbl -> Undetectable(This,ret_0)
#define IDA3Image_Undetectable(This,ret_0)	\
    (This)->lpVtbl -> Undetectable(This,ret_0)
#define IDA2View_QueryHitPoint(This,dwAspect,prcBounds,ptLoc,lCloseHint,pHitResult)	\
    (This)->lpVtbl -> QueryHitPoint(This,dwAspect,prcBounds,ptLoc,lCloseHint,pHitResult)
#define IDA2View_QueryHitPointEx(This,s,cookies,points,prcBounds,ptLoc,hits)	\
    (This)->lpVtbl -> QueryHitPointEx(This,s,cookies,points,prcBounds,ptLoc,hits)
#define IDA3View_QueryHitPoint(This,dwAspect,prcBounds,ptLoc,lCloseHint,pHitResult)	\
    (This)->lpVtbl -> QueryHitPoint(This,dwAspect,prcBounds,ptLoc,lCloseHint,pHitResult)
#define IDA3View_QueryHitPointEx(This,s,cookies,points,prcBounds,ptLoc,hits)	\
    (This)->lpVtbl -> QueryHitPointEx(This,s,cookies,points,prcBounds,ptLoc,hits)
#define IDAStatics_put_PixelConstructionMode(This,bMode)	\
    (This)->lpVtbl -> put_PixelConstructionMode(This,bMode)
#define IDAStatics_get_PixelConstructionMode(This,bMode)	\
    (This)->lpVtbl -> get_PixelConstructionMode(This,bMode)
#define IDAStatics_get_DetectableEmptyImage(This,ret_0)	\
    (This)->lpVtbl -> get_DetectableEmptyImage(This,ret_0)
#define IDAStatics_CubicBSplinePathEx(This,points_0size,points_0,knots_1size,knots_1,ret_2)	\
    (This)->lpVtbl -> CubicBSplinePathEx(This,points_0size,points_0,knots_1size,knots_1,ret_2)
#define IDAStatics_CubicBSplinePath(This,points_0,knots_1,ret_2)	\
    (This)->lpVtbl -> CubicBSplinePath(This,points_0,knots_1,ret_2)
#define IDA2Statics_put_PixelConstructionMode(This,bMode)	\
    (This)->lpVtbl -> put_PixelConstructionMode(This,bMode)
#define IDA2Statics_get_PixelConstructionMode(This,bMode)	\
    (This)->lpVtbl -> get_PixelConstructionMode(This,bMode)
#define IDA2Statics_get_DetectableEmptyImage(This,ret_0)	\
    (This)->lpVtbl -> get_DetectableEmptyImage(This,ret_0)
#define IDA2Statics_CubicBSplinePathEx(This,points_0size,points_0,knots_1size,knots_1,ret_2)	\
    (This)->lpVtbl -> CubicBSplinePathEx(This,points_0size,points_0,knots_1size,knots_1,ret_2)
#define IDA2Statics_CubicBSplinePath(This,points_0,knots_1,ret_2)	\
    (This)->lpVtbl -> CubicBSplinePath(This,points_0,knots_1,ret_2)
#define IDA3Statics_put_PixelConstructionMode(This,bMode)	\
    (This)->lpVtbl -> put_PixelConstructionMode(This,bMode)
#define IDA3Statics_get_PixelConstructionMode(This,bMode)	\
    (This)->lpVtbl -> get_PixelConstructionMode(This,bMode)
#define IDA3Statics_get_DetectableEmptyImage(This,ret_0)	\
    (This)->lpVtbl -> get_DetectableEmptyImage(This,ret_0)
#define IDA3Statics_CubicBSplinePathEx(This,points_0size,points_0,knots_1size,knots_1,ret_2)	\
    (This)->lpVtbl -> CubicBSplinePathEx(This,points_0size,points_0,knots_1size,knots_1,ret_2)
#define IDA3Statics_CubicBSplinePath(This,points_0,knots_1,ret_2)	\
    (This)->lpVtbl -> CubicBSplinePath(This,points_0,knots_1,ret_2)

// public\sdk\inc\datime.h
#define ITIMEElement_get_syncBehavior(This,sync)	\
    (This)->lpVtbl -> get_syncBehavior(This,sync)
#define ITIMEElement_put_syncBehavior(This,sync)	\
    (This)->lpVtbl -> put_syncBehavior(This,sync)
#define ITIMEBodyElement_get_syncBehavior(This,sync)	\
    (This)->lpVtbl -> get_syncBehavior(This,sync)
#define ITIMEBodyElement_put_syncBehavior(This,sync)	\
    (This)->lpVtbl -> put_syncBehavior(This,sync)
#define ITIMEMediaElement_get_syncBehavior(This,sync)	\
    (This)->lpVtbl -> get_syncBehavior(This,sync)
#define ITIMEMediaElement_put_syncBehavior(This,sync)	\
    (This)->lpVtbl -> put_syncBehavior(This,sync)

// public\sdk\inc\dbgprop.h
#define IDebugProperty_GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)	\
    (This)->lpVtbl -> GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)
#define IDebugExtendedProperty_GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)	\
    (This)->lpVtbl -> GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)
#define IDebugExtendedProperty_GetExtendedPropertyInfo(This,dwFieldSpec,nRadix,pExtendedPropertyInfo)	\
    (This)->lpVtbl -> GetExtendedPropertyInfo(This,dwFieldSpec,nRadix,pExtendedPropertyInfo)

// public\sdk\inc\ddraw.h
#define DDERR_NOZBUFFERHW                       MAKE_DDHRESULT( 340 )

// public\sdk\inc\digitalv.h
#define SEND_DGVSIGNAL(dwFlags, dwCallback, hDriver, wDeviceID, dwUser, dwPos ) \
  DriverCallback( (dwCallback), DCB_WINDOW, (HANDLE)(wDeviceID), MM_MCISIGNAL,\
  hDriver, ((dwFlags) & MCI_DGV_SIGNAL_POSITION) ? (dwPos):(dwUser),\
  ((dwFlags) & MCI_DGV_SIGNAL_POSITION) ? (dwUser):(dwPos))

// public\sdk\inc\dmerror.h
#define DMUS_S_NOBUFFERCONTROL          MAKE_DMHRESULTSUCCESS(0x215)
#define DMUS_E_INSUFFICIENTBUFFER       MAKE_DMHRESULTERROR(0x0104)
#define DMUS_E_BUFFERNOTSET             MAKE_DMHRESULTERROR(0x0105)
#define DMUS_E_BUFFERNOTAVAILABLE       MAKE_DMHRESULTERROR(0x0106)
#define DMUS_E_BUFFER_EMPTY             MAKE_DMHRESULTERROR(0x0135)
#define DMUS_E_BUFFER_FULL              MAKE_DMHRESULTERROR(0x0136)
#define DMUS_E_INVALIDBUFFER            MAKE_DMHRESULTERROR(0x013B)
#define DMUS_E_AUDIOPATH_NOBUFFER     MAKE_DMHRESULTERROR(0x022A)
#define DMUS_E_AUDIOPATH_NOGLOBALFXBUFFER     MAKE_DMHRESULTERROR(0x022E)

// public\sdk\inc\dplay.h
#define DPERR_BUFFERTOOSMALL            MAKE_DPHRESULT(  30 )
#define DPERR_BUFFERTOOLARGE            MAKE_DPHRESULT( 1000 )

// public\sdk\inc\dplay8.h
#define DPNERR_BUFFERTOOSMALL			MAKE_DPNHRESULT( 0x100 )
#define DPNERR_TABLEFULL				MAKE_DPNHRESULT( 0x620 )

// public\sdk\inc\dsound.h
#define IDirectSoundBuffer_Release(p)                   IUnknown_Release(p)
#define IDirectSoundBuffer8_Release(p)                      IUnknown_Release(p)
#define IDirectSound3DBuffer_Release(p)                     IUnknown_Release(p)
#define IDirectSoundCaptureBuffer_Release(p)                    IUnknown_Release(p)
#define IDirectSoundCaptureBuffer8_Release(p)                       IUnknown_Release(p)
#define DSERR_BUFFERLOST                MAKE_DSHRESULT(150)
#define DSERR_BUFFERTOOSMALL            MAKE_DSHRESULT(180)
#define DSERR_BADSENDBUFFERGUID         MAKE_DSHRESULT(210)

// public\sdk\inc\dtccrm.h
#define ICrmLogControl_WriteLogRecordVariants(This,pLogRecord)	\
    (This)->lpVtbl -> WriteLogRecordVariants(This,pLogRecord)
#define ICrmLogControl_ForgetLogRecord(This)	\
    (This)->lpVtbl -> ForgetLogRecord(This)
#define ICrmLogControl_WriteLogRecord(This,rgBlob,cBlob)	\
    (This)->lpVtbl -> WriteLogRecord(This,rgBlob,cBlob)
#define ICrmCompensatorVariants_PrepareRecordVariants(This,pLogRecord,pbForget)	\
    (This)->lpVtbl -> PrepareRecordVariants(This,pLogRecord,pbForget)
#define ICrmCompensatorVariants_CommitRecordVariants(This,pLogRecord,pbForget)	\
    (This)->lpVtbl -> CommitRecordVariants(This,pLogRecord,pbForget)
#define ICrmCompensatorVariants_AbortRecordVariants(This,pLogRecord,pbForget)	\
    (This)->lpVtbl -> AbortRecordVariants(This,pLogRecord,pbForget)
#define ICrmCompensator_PrepareRecord(This,crmLogRec,pfForget)	\
    (This)->lpVtbl -> PrepareRecord(This,crmLogRec,pfForget)
#define ICrmCompensator_CommitRecord(This,crmLogRec,pfForget)	\
    (This)->lpVtbl -> CommitRecord(This,crmLogRec,pfForget)
#define ICrmCompensator_AbortRecord(This,crmLogRec,pfForget)	\
    (This)->lpVtbl -> AbortRecord(This,crmLogRec,pfForget)
#define ICrmMonitorLogRecords_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICrmMonitorLogRecords_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICrmMonitorLogRecords_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICrmMonitorLogRecords_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)
#define ICrmMonitorLogRecords_get_TransactionState(This,pVal)	\
    (This)->lpVtbl -> get_TransactionState(This,pVal)
#define ICrmMonitorLogRecords_get_StructuredRecords(This,pVal)	\
    (This)->lpVtbl -> get_StructuredRecords(This,pVal)
#define ICrmMonitorLogRecords_GetLogRecord(This,dwIndex,pCrmLogRec)	\
    (This)->lpVtbl -> GetLogRecord(This,dwIndex,pCrmLogRec)
#define ICrmMonitorLogRecords_GetLogRecordVariants(This,IndexNumber,pLogRecord)	\
    (This)->lpVtbl -> GetLogRecordVariants(This,IndexNumber,pLogRecord)
#define ICrmFormatLogRecords_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICrmFormatLogRecords_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICrmFormatLogRecords_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICrmFormatLogRecords_GetColumnCount(This,plColumnCount)	\
    (This)->lpVtbl -> GetColumnCount(This,plColumnCount)
#define ICrmFormatLogRecords_GetColumnHeaders(This,pHeaders)	\
    (This)->lpVtbl -> GetColumnHeaders(This,pHeaders)
#define ICrmFormatLogRecords_GetColumn(This,CrmLogRec,pFormattedLogRecord)	\
    (This)->lpVtbl -> GetColumn(This,CrmLogRec,pFormattedLogRecord)
#define ICrmFormatLogRecords_GetColumnVariants(This,LogRecord,pFormattedLogRecord)	\
    (This)->lpVtbl -> GetColumnVariants(This,LogRecord,pFormattedLogRecord)
#define ICRMRecoveryClerk_CheckCompensator(This,i_pclsidCompensator,o_pfUnstructured,o_pfStructured)	\
    (This)->lpVtbl -> CheckCompensator(This,i_pclsidCompensator,o_pfUnstructured,o_pfStructured)
#define IClerksCollection_LoadEntry(This,i_pclsidClerkInstance,i_pclsidCompensator,i_pDescription,i_pguidActivityId,i_pguidTransactionUOW)	\
    (This)->lpVtbl -> LoadEntry(This,i_pclsidClerkInstance,i_pclsidCompensator,i_pDescription,i_pguidActivityId,i_pguidTransactionUOW)

// public\sdk\inc\dvoice.h
#define DVERR_BUFFERTOOSMALL            MAKE_DVHRESULT(  0x001E )
#define DVERR_ALREADYBUFFERED	        MAKE_DVHRESULT( 0x0178 )
#define DVERR_NOTBUFFERED               MAKE_DVHRESULT( 0x0179 )
#define DVERR_RECORDSYSTEMERROR         MAKE_DVHRESULT( 0x017D )
#define DVERR_INVALIDBUFFER				MAKE_DVHRESULT( 0x018F )
#define DVERR_LOCKEDBUFFER				MAKE_DVHRESULT( 0x0190 )

// public\sdk\inc\dxatlpb.h
#define COM_INTERFACE_ENTRY_DXIMPL(x)\
	COM_INTERFACE_ENTRY_IID(IID_##x, x##DXImpl<_ComMapClass>)

// public\sdk\inc\dxtmsft3.h
#define IHeightField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHeightField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHeightField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHeightField_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHeightField_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHeightField_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHeightField_get_Capabilities(This,pVal)	\
    (This)->lpVtbl -> get_Capabilities(This,pVal)
#define IHeightField_get_Progress(This,pVal)	\
    (This)->lpVtbl -> get_Progress(This,pVal)
#define IHeightField_put_Progress(This,newVal)	\
    (This)->lpVtbl -> put_Progress(This,newVal)
#define IHeightField_get_StepResolution(This,pVal)	\
    (This)->lpVtbl -> get_StepResolution(This,pVal)
#define IHeightField_get_Duration(This,pVal)	\
    (This)->lpVtbl -> get_Duration(This,pVal)
#define IHeightField_put_Duration(This,newVal)	\
    (This)->lpVtbl -> put_Duration(This,newVal)
#define IHeightField_get_Width(This,pVal)	\
    (This)->lpVtbl -> get_Width(This,pVal)
#define IHeightField_put_Width(This,newVal)	\
    (This)->lpVtbl -> put_Width(This,newVal)
#define IHeightField_get_Height(This,pVal)	\
    (This)->lpVtbl -> get_Height(This,pVal)
#define IHeightField_put_Height(This,newVal)	\
    (This)->lpVtbl -> put_Height(This,newVal)
#define IHeightField_get_Depth(This,pVal)	\
    (This)->lpVtbl -> get_Depth(This,pVal)
#define IHeightField_put_Depth(This,newVal)	\
    (This)->lpVtbl -> put_Depth(This,newVal)
#define IHeightField_get_Samples(This,pVal)	\
    (This)->lpVtbl -> get_Samples(This,pVal)
#define IHeightField_put_Samples(This,newVal)	\
    (This)->lpVtbl -> put_Samples(This,newVal)

// public\sdk\inc\dxtrans.h
#define IDXTransform_GetObjectSize(This,pcbSize)	\
    (This)->lpVtbl -> GetObjectSize(This,pcbSize)
#define IDXSurfaceModifier_SetLookup(This,pLookupTable)	\
    (This)->lpVtbl -> SetLookup(This,pLookupTable)
#define IDXSurfaceModifier_GetLookup(This,ppLookupTable)	\
    (This)->lpVtbl -> GetLookup(This,ppLookupTable)
#define IDXSurface_GetObjectSize(This,pcbSize)	\
    (This)->lpVtbl -> GetObjectSize(This,pcbSize)
#define IDXLookupTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IDXLookupTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IDXLookupTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IDXLookupTable_GetGenerationId(This,pID)	\
    (This)->lpVtbl -> GetGenerationId(This,pID)
#define IDXLookupTable_IncrementGenerationId(This,bRefresh)	\
    (This)->lpVtbl -> IncrementGenerationId(This,bRefresh)
#define IDXLookupTable_GetObjectSize(This,pcbSize)	\
    (This)->lpVtbl -> GetObjectSize(This,pcbSize)
#define IDXLookupTable_GetTables(This,RedLUT,GreenLUT,BlueLUT,AlphaLUT)	\
    (This)->lpVtbl -> GetTables(This,RedLUT,GreenLUT,BlueLUT,AlphaLUT)
#define IDXLookupTable_IsChannelIdentity(This,pSampleBools)	\
    (This)->lpVtbl -> IsChannelIdentity(This,pSampleBools)
#define IDXLookupTable_GetIndexValues(This,Index,pSample)	\
    (This)->lpVtbl -> GetIndexValues(This,Index,pSample)
#define IDXLookupTable_ApplyTables(This,pSamples,cSamples)	\
    (This)->lpVtbl -> ApplyTables(This,pSamples,cSamples)

// public\sdk\inc\emptyvc.h
#define IEmptyVolumeCache_GetSpaceUsed(This,pdwlSpaceUsed,picb)	\
    (This)->lpVtbl -> GetSpaceUsed(This,pdwlSpaceUsed,picb)
#define IEmptyVolumeCache_Purge(This,dwlSpaceToFree,picb)	\
    (This)->lpVtbl -> Purge(This,dwlSpaceToFree,picb)
#define IEmptyVolumeCache2_GetSpaceUsed(This,pdwlSpaceUsed,picb)	\
    (This)->lpVtbl -> GetSpaceUsed(This,pdwlSpaceUsed,picb)
#define IEmptyVolumeCache2_Purge(This,dwlSpaceToFree,picb)	\
    (This)->lpVtbl -> Purge(This,dwlSpaceToFree,picb)

// public\sdk\inc\esebkmsg.h
#define hrCBRestorePathNotProvided       ((HRESULT)0xC7FE1F44L)
#define hrCBInstanceNotFound             ((HRESULT)0xC7FE1F45L)
#define hrErrorNoCallbackFunction        ((HRESULT)0xC7FF0BCBL)
#define hrLogBufferTooSmall              ((HRESULT)0xC8000205L)
#define hrBufferTruncated                ((HRESULT)0x880003EEL)
#define hrOutOfBuffers                   ((HRESULT)0xC80003F6L)
#define hrRecordDeleted                  ((HRESULT)0xC80003F9L)
#define hrRecordTooBig                   ((HRESULT)0xC8000402L)
#define hrBufferTooSmall                 ((HRESULT)0xC800040EL)
#define hrInvalidBufferSize              ((HRESULT)0xC8000417L)
#define hrColumnNotUpdatable             ((HRESULT)0xC8000418L)
#define hrTableEmpty                     ((HRESULT)0x88000515L)
#define hrTableLocked                    ((HRESULT)0xC8000516L)
#define hrTableDuplicate                 ((HRESULT)0xC8000517L)
#define hrTableInUse                     ((HRESULT)0xC8000518L)
#define hrTableNotEmpty                  ((HRESULT)0xC800051CL)
#define hrInvalidTableId                 ((HRESULT)0xC800051EL)
#define hrTooManyOpenTables              ((HRESULT)0xC800051FL)
#define hrRecordNotFound                 ((HRESULT)0xC8000641L)
#define hrNoCurrentRecord                ((HRESULT)0xC8000643L)
#define hrRecordClusteredChanged         ((HRESULT)0xC8000644L)

// public\sdk\inc\esent.h
#define JET_tableidNil				(~(JET_TABLEID)0)
#define JET_wrnColumnNotLocal				1532 /* Column value(s) not returned because they could not be reconstructed from the data at hand */

// public\sdk\inc\esent97.h
#define JET_tableidNil				(~(JET_TABLEID)0)

// public\sdk\inc\esent98.h
#define JET_tableidNil				(~(JET_TABLEID)0)

// public\sdk\inc\except.hxx
# define IMPLEMENT_UNWIND(class)                                            \
                                                                            \
        void APINOT class::_ObjectUnwind(void * pthis)                      \
        {                                                                   \
            ((class *)pthis)->class::~class();                              \
        }                                                                   \
                                                                            \
        struct __Check##class                                               \
        {                                                                   \
            __Check##class()                                                \
            {                                                               \
                if ( (CUnwindable *)((class *)10) != (CUnwindable *)10 ||   \
                     (CVirtualUnwindable *)                                 \
                         ((class *)10) != (CVirtualUnwindable *)10 )        \
                {                                                           \
                    exDebugOut(( DEB_ERROR,                                 \
                                 "INVALID UNWINDABLE CLASS: %s.\n",         \
                                 #class ));                                 \
                }                                                           \
            }                                                               \
        };                                                                  \
                                                                            \
        __Check##class __check_except_##class;

// public\sdk\inc\filter.h
#define IFilter_GetText(This,pcwcBuffer,awcBuffer)	\
    (This)->lpVtbl -> GetText(This,pcwcBuffer,awcBuffer)

// public\sdk\inc\fsciclnt.h
#define IFsCiAdmin_SetupCache(This,ps,vt,cbMaxLen,ulToken,fCanBeModified,dwStoreLevel)	\
    (This)->lpVtbl -> SetupCache(This,ps,vt,cbMaxLen,ulToken,fCanBeModified,dwStoreLevel)

// public\sdk\inc\helpcenterinterfaces.h
#define IPCHHelpCenterExternal_CreateObject_Cabinet(This,ppCB)	\
    (This)->lpVtbl -> CreateObject_Cabinet(This,ppCB)
#define IPCHScriptableStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IPCHScriptableStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IPCHScriptableStream_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IPCHScriptableStream_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IPCHScriptableStream_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IPCHScriptableStream_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IPCHScriptableStream_get_Size(This,plSize)	\
    (This)->lpVtbl -> get_Size(This,plSize)
#define IPCHScriptableStream_Read(This,lCount,pvData)	\
    (This)->lpVtbl -> Read(This,lCount,pvData)
#define IPCHScriptableStream_ReadHex(This,lCount,pbstrData)	\
    (This)->lpVtbl -> ReadHex(This,lCount,pbstrData)
#define IPCHScriptableStream_Write(This,lCount,vData,plWritten)	\
    (This)->lpVtbl -> Write(This,lCount,vData,plWritten)
#define IPCHScriptableStream_WriteHex(This,lCount,bstrData,plWritten)	\
    (This)->lpVtbl -> WriteHex(This,lCount,bstrData,plWritten)
#define IPCHScriptableStream_Close(This)	\
    (This)->lpVtbl -> Close(This)
#define IPCHConnectivity_CreateObject_ConnectionCheck(This,ppCB)	\
    (This)->lpVtbl -> CreateObject_ConnectionCheck(This,ppCB)

// public\sdk\inc\helpserviceinterfaces.h
#define ISAFChannel_RecordIncident(This,bstrDisplay,bstrURL,vProgress,vXMLDataFile,vXMLBlob,pVal)	\
    (This)->lpVtbl -> RecordIncident(This,bstrDisplay,bstrURL,vProgress,vXMLDataFile,vXMLBlob,pVal)
#define IPCHCollection_get_Item(This,vIndex,ppEntry)	\
    (This)->lpVtbl -> get_Item(This,vIndex,ppEntry)
#define IPCHUtility_CreateObject_Cabinet(This,ppCB)	\
    (This)->lpVtbl -> CreateObject_Cabinet(This,ppCB)
#define IPCHQueryResult_get_Entry(This,pVal)	\
    (This)->lpVtbl -> get_Entry(This,pVal)
#define IPCHSecurity_CreateObject_AccessControlEntry(This,pACE)	\
    (This)->lpVtbl -> CreateObject_AccessControlEntry(This,pACE)
#define IPCHAccessControlEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IPCHAccessControlEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IPCHAccessControlEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IPCHAccessControlEntry_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IPCHAccessControlEntry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IPCHAccessControlEntry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IPCHAccessControlEntry_get_AccessMask(This,pVal)	\
    (This)->lpVtbl -> get_AccessMask(This,pVal)
#define IPCHAccessControlEntry_put_AccessMask(This,newVal)	\
    (This)->lpVtbl -> put_AccessMask(This,newVal)
#define IPCHAccessControlEntry_get_AceType(This,pVal)	\
    (This)->lpVtbl -> get_AceType(This,pVal)
#define IPCHAccessControlEntry_put_AceType(This,newVal)	\
    (This)->lpVtbl -> put_AceType(This,newVal)
#define IPCHAccessControlEntry_get_AceFlags(This,pVal)	\
    (This)->lpVtbl -> get_AceFlags(This,pVal)
#define IPCHAccessControlEntry_put_AceFlags(This,newVal)	\
    (This)->lpVtbl -> put_AceFlags(This,newVal)
#define IPCHAccessControlEntry_get_Flags(This,pVal)	\
    (This)->lpVtbl -> get_Flags(This,pVal)
#define IPCHAccessControlEntry_put_Flags(This,newVal)	\
    (This)->lpVtbl -> put_Flags(This,newVal)
#define IPCHAccessControlEntry_get_ObjectType(This,pVal)	\
    (This)->lpVtbl -> get_ObjectType(This,pVal)
#define IPCHAccessControlEntry_put_ObjectType(This,newVal)	\
    (This)->lpVtbl -> put_ObjectType(This,newVal)
#define IPCHAccessControlEntry_get_InheritedObjectType(This,pVal)	\
    (This)->lpVtbl -> get_InheritedObjectType(This,pVal)
#define IPCHAccessControlEntry_put_InheritedObjectType(This,newVal)	\
    (This)->lpVtbl -> put_InheritedObjectType(This,newVal)
#define IPCHAccessControlEntry_get_Trustee(This,pVal)	\
    (This)->lpVtbl -> get_Trustee(This,pVal)
#define IPCHAccessControlEntry_put_Trustee(This,newVal)	\
    (This)->lpVtbl -> put_Trustee(This,newVal)
#define IPCHAccessControlEntry_IsEquivalent(This,pAce,pVal)	\
    (This)->lpVtbl -> IsEquivalent(This,pAce,pVal)
#define IPCHAccessControlEntry_Clone(This,pVal)	\
    (This)->lpVtbl -> Clone(This,pVal)
#define IPCHAccessControlEntry_LoadXML(This,xdnNode)	\
    (This)->lpVtbl -> LoadXML(This,xdnNode)
#define IPCHAccessControlEntry_LoadXMLAsString(This,bstrVal)	\
    (This)->lpVtbl -> LoadXMLAsString(This,bstrVal)
#define IPCHAccessControlEntry_LoadXMLAsStream(This,pStream)	\
    (This)->lpVtbl -> LoadXMLAsStream(This,pStream)
#define IPCHAccessControlEntry_SaveXML(This,xdnRoot,pxdnNode)	\
    (This)->lpVtbl -> SaveXML(This,xdnRoot,pxdnNode)
#define IPCHAccessControlEntry_SaveXMLAsString(This,bstrVal)	\
    (This)->lpVtbl -> SaveXMLAsString(This,bstrVal)
#define IPCHAccessControlEntry_SaveXMLAsStream(This,pStream)	\
    (This)->lpVtbl -> SaveXMLAsStream(This,pStream)
#define IPCHSEManagerInternal_LogRecord(This,bstrRecord)	\
    (This)->lpVtbl -> LogRecord(This,bstrRecord)

// public\sdk\inc\htiframe.h
#define ITargetNotify_OnCreate(This,pUnkDestination,cbCookie)	\
    (This)->lpVtbl -> OnCreate(This,pUnkDestination,cbCookie)
#define ITargetNotify2_OnCreate(This,pUnkDestination,cbCookie)	\
    (This)->lpVtbl -> OnCreate(This,pUnkDestination,cbCookie)

// public\sdk\inc\htmlfilter.h
#define IHTMLViewFilter_Draw(This,hdc,prcBounds)	\
    (This)->lpVtbl -> Draw(This,hdc,prcBounds)

// public\sdk\inc\iads.h
#define IADsPropertyEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IADsPropertyEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IADsPropertyEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IADsPropertyEntry_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IADsPropertyEntry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IADsPropertyEntry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IADsPropertyEntry_Clear(This)	\
    (This)->lpVtbl -> Clear(This)
#define IADsPropertyEntry_get_Name(This,retval)	\
    (This)->lpVtbl -> get_Name(This,retval)
#define IADsPropertyEntry_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)
#define IADsPropertyEntry_get_ADsType(This,retval)	\
    (This)->lpVtbl -> get_ADsType(This,retval)
#define IADsPropertyEntry_put_ADsType(This,lnADsType)	\
    (This)->lpVtbl -> put_ADsType(This,lnADsType)
#define IADsPropertyEntry_get_ControlCode(This,retval)	\
    (This)->lpVtbl -> get_ControlCode(This,retval)
#define IADsPropertyEntry_put_ControlCode(This,lnControlCode)	\
    (This)->lpVtbl -> put_ControlCode(This,lnControlCode)
#define IADsPropertyEntry_get_Values(This,retval)	\
    (This)->lpVtbl -> get_Values(This,retval)
#define IADsPropertyEntry_put_Values(This,vValues)	\
    (This)->lpVtbl -> put_Values(This,vValues)
#define IADsPropertyValue_get_PrintableString(This,retval)	\
    (This)->lpVtbl -> get_PrintableString(This,retval)
#define IADsPropertyValue_put_PrintableString(This,bstrPrintableString)	\
    (This)->lpVtbl -> put_PrintableString(This,bstrPrintableString)
#define IADsAccessControlEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IADsAccessControlEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IADsAccessControlEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IADsAccessControlEntry_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IADsAccessControlEntry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IADsAccessControlEntry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IADsAccessControlEntry_get_AccessMask(This,retval)	\
    (This)->lpVtbl -> get_AccessMask(This,retval)
#define IADsAccessControlEntry_put_AccessMask(This,lnAccessMask)	\
    (This)->lpVtbl -> put_AccessMask(This,lnAccessMask)
#define IADsAccessControlEntry_get_AceType(This,retval)	\
    (This)->lpVtbl -> get_AceType(This,retval)
#define IADsAccessControlEntry_put_AceType(This,lnAceType)	\
    (This)->lpVtbl -> put_AceType(This,lnAceType)
#define IADsAccessControlEntry_get_AceFlags(This,retval)	\
    (This)->lpVtbl -> get_AceFlags(This,retval)
#define IADsAccessControlEntry_put_AceFlags(This,lnAceFlags)	\
    (This)->lpVtbl -> put_AceFlags(This,lnAceFlags)
#define IADsAccessControlEntry_get_Flags(This,retval)	\
    (This)->lpVtbl -> get_Flags(This,retval)
#define IADsAccessControlEntry_put_Flags(This,lnFlags)	\
    (This)->lpVtbl -> put_Flags(This,lnFlags)
#define IADsAccessControlEntry_get_ObjectType(This,retval)	\
    (This)->lpVtbl -> get_ObjectType(This,retval)
#define IADsAccessControlEntry_put_ObjectType(This,bstrObjectType)	\
    (This)->lpVtbl -> put_ObjectType(This,bstrObjectType)
#define IADsAccessControlEntry_get_InheritedObjectType(This,retval)	\
    (This)->lpVtbl -> get_InheritedObjectType(This,retval)
#define IADsAccessControlEntry_put_InheritedObjectType(This,bstrInheritedObjectType)	\
    (This)->lpVtbl -> put_InheritedObjectType(This,bstrInheritedObjectType)
#define IADsAccessControlEntry_get_Trustee(This,retval)	\
    (This)->lpVtbl -> get_Trustee(This,retval)
#define IADsAccessControlEntry_put_Trustee(This,bstrTrustee)	\
    (This)->lpVtbl -> put_Trustee(This,bstrTrustee)

// public\sdk\inc\icrsint.h
#define BEGIN_ADO_BINDING(cls) public: \
	typedef cls ADORowClass; \
	const ADO_BINDING_ENTRY* STDMETHODCALLTYPE GetADOBindingEntries() { \
	static const ADO_BINDING_ENTRY rgADOBindingEntries[] = {

// public\sdk\inc\iextag.h
#define IClientCaps_get_bufferDepth(This,p)	\
    (This)->lpVtbl -> get_bufferDepth(This,p)
#define ITemplatePrinter_put_tableOfLinks(This,v)	\
    (This)->lpVtbl -> put_tableOfLinks(This,v)
#define ITemplatePrinter_get_tableOfLinks(This,p)	\
    (This)->lpVtbl -> get_tableOfLinks(This,p)
#define ITemplatePrinter_get_unprintableLeft(This,p)	\
    (This)->lpVtbl -> get_unprintableLeft(This,p)
#define ITemplatePrinter_get_unprintableTop(This,p)	\
    (This)->lpVtbl -> get_unprintableTop(This,p)
#define ITemplatePrinter_get_unprintableRight(This,p)	\
    (This)->lpVtbl -> get_unprintableRight(This,p)
#define ITemplatePrinter_get_unprintableBottom(This,p)	\
    (This)->lpVtbl -> get_unprintableBottom(This,p)
#define ITemplatePrinter2_put_tableOfLinks(This,v)	\
    (This)->lpVtbl -> put_tableOfLinks(This,v)
#define ITemplatePrinter2_get_tableOfLinks(This,p)	\
    (This)->lpVtbl -> get_tableOfLinks(This,p)
#define ITemplatePrinter2_get_unprintableLeft(This,p)	\
    (This)->lpVtbl -> get_unprintableLeft(This,p)
#define ITemplatePrinter2_get_unprintableTop(This,p)	\
    (This)->lpVtbl -> get_unprintableTop(This,p)
#define ITemplatePrinter2_get_unprintableRight(This,p)	\
    (This)->lpVtbl -> get_unprintableRight(This,p)
#define ITemplatePrinter2_get_unprintableBottom(This,p)	\
    (This)->lpVtbl -> get_unprintableBottom(This,p)

// public\sdk\inc\ih26xcd.h
#define IH26XSnapshot_getSnapshot(This,lpBmi,pvBuffer,dwTimeout)	\
    (This)->lpVtbl -> getSnapshot(This,lpBmi,pvBuffer,dwTimeout)

// public\sdk\inc\iimgctx.h
#define IImgCtx_Draw(This, hdc, prcBounds)              \
        (This)->lpVtbl -> Draw(This, hdc, prcBounds)

// public\sdk\inc\iiscnfg.h
#define MD_DEFAULT_EXTLOG_FIELDS        (MD_EXTLOG_CLIENT_IP | \
                                         MD_EXTLOG_TIME      | \
                                         MD_EXTLOG_METHOD    | \
                                         MD_EXTLOG_URI_STEM  | \
                                         MD_EXTLOG_HTTP_STATUS)
#define MD_SET_DATA_RECORD(_pMDR, _id, _attr, _utype, _dtype, _dlen, _pData) \
            { \
            (_pMDR)->dwMDIdentifier=(_id);      \
            (_pMDR)->dwMDAttributes=(_attr);    \
            (_pMDR)->dwMDUserType=(_utype);     \
            (_pMDR)->dwMDDataType=(_dtype);     \
            (_pMDR)->dwMDDataLen=(_dlen);       \
            (_pMDR)->pbMDData=(LPBYTE)(_pData); \
            }

// public\sdk\inc\imapi.h
#define IDiscRecorder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IDiscRecorder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IDiscRecorder_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IDiscRecorder_Init(This,pbyUniqueID,nulIDSize,nulDriveNumber)	\
    (This)->lpVtbl -> Init(This,pbyUniqueID,nulIDSize,nulDriveNumber)
#define IDiscRecorder_GetRecorderGUID(This,pbyUniqueID,ulBufferSize,pulReturnSizeRequired)	\
    (This)->lpVtbl -> GetRecorderGUID(This,pbyUniqueID,ulBufferSize,pulReturnSizeRequired)
#define IDiscRecorder_GetRecorderType(This,fTypeCode)	\
    (This)->lpVtbl -> GetRecorderType(This,fTypeCode)
#define IDiscRecorder_GetDisplayNames(This,pbstrVendorID,pbstrProductID,pbstrRevision)	\
    (This)->lpVtbl -> GetDisplayNames(This,pbstrVendorID,pbstrProductID,pbstrRevision)
#define IDiscRecorder_GetPath(This,pbstrPath)	\
    (This)->lpVtbl -> GetPath(This,pbstrPath)
#define IDiscRecorder_GetRecorderProperties(This,ppPropStg)	\
    (This)->lpVtbl -> GetRecorderProperties(This,ppPropStg)
#define IDiscRecorder_SetRecorderProperties(This,pPropStg)	\
    (This)->lpVtbl -> SetRecorderProperties(This,pPropStg)
#define IDiscRecorder_GetRecorderState(This,pulDevStateFlags)	\
    (This)->lpVtbl -> GetRecorderState(This,pulDevStateFlags)
#define IDiscRecorder_OpenExclusive(This)	\
    (This)->lpVtbl -> OpenExclusive(This)
#define IDiscRecorder_QueryMediaType(This,fMediaType,fMediaFlags)	\
    (This)->lpVtbl -> QueryMediaType(This,fMediaType,fMediaFlags)
#define IDiscRecorder_Eject(This)	\
    (This)->lpVtbl -> Eject(This)
#define IDiscRecorder_Erase(This,bFullErase)	\
    (This)->lpVtbl -> Erase(This,bFullErase)
#define IDiscRecorder_Close(This)	\
    (This)->lpVtbl -> Close(This)
#define IEnumDiscRecorders_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumDiscRecorders_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumDiscRecorders_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumDiscRecorders_Skip(This,cRecorders)	\
    (This)->lpVtbl -> Skip(This,cRecorders)
#define IEnumDiscRecorders_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumDiscRecorders_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)
#define IDiscMaster_EnumDiscRecorders(This,ppEnum)	\
    (This)->lpVtbl -> EnumDiscRecorders(This,ppEnum)
#define IDiscMaster_GetActiveDiscRecorder(This,ppRecorder)	\
    (This)->lpVtbl -> GetActiveDiscRecorder(This,ppRecorder)
#define IDiscMaster_SetActiveDiscRecorder(This,pRecorder)	\
    (This)->lpVtbl -> SetActiveDiscRecorder(This,pRecorder)
#define IDiscMaster_RecordDisc(This,bSimulate,bEjectAfterBurn)	\
    (This)->lpVtbl -> RecordDisc(This,bSimulate,bEjectAfterBurn)
#define IDiscStash_Read(This,vCookie,pby,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,vCookie,pby,cb,pcbRead)
#define IDiscStash_Write(This,vCookie,pby,cb)	\
    (This)->lpVtbl -> Write(This,vCookie,pby,cb)
#define IBurnEngine_EnumDiscRecorders(This,ppEnum)	\
    (This)->lpVtbl -> EnumDiscRecorders(This,ppEnum)
#define IBurnEngine_GetActiveDiscRecorder(This,ppRecorder)	\
    (This)->lpVtbl -> GetActiveDiscRecorder(This,ppRecorder)
#define IBurnEngine_SetActiveDiscRecorder(This,pRecorder)	\
    (This)->lpVtbl -> SetActiveDiscRecorder(This,pRecorder)

// public\sdk\inc\imgutil.h
#define ISniffStream_Peek(This,pBuffer,nBytes,pnBytesRead)	\
    (This)->lpVtbl -> Peek(This,pBuffer,nBytes,pnBytesRead)
#define IDithererImpl_SetDestColorTable(This,nColors,prgbColors)	\
    (This)->lpVtbl -> SetDestColorTable(This,nColors,prgbColors)

// public\sdk\inc\imnact.h
#define IImnAccount_GetProp(This,dwPropTag,pb,pcb)	\
    (This)->lpVtbl -> GetProp(This,dwPropTag,pb,pcb)
#define IImnAccount_SetProp(This,dwPropTag,pb,cb)	\
    (This)->lpVtbl -> SetProp(This,dwPropTag,pb,cb)
#define IImnAccount_ValidateProperty(This,dwPropTag,pb,cb)	\
    (This)->lpVtbl -> ValidateProperty(This,dwPropTag,pb,cb)

// public\sdk\inc\imnxport.h
#define IHTTPMailTransport_CommandPUT(This,pszPath,lpvData,cbSize,dwContext)	\
    (This)->lpVtbl -> CommandPUT(This,pszPath,lpvData,cbSize,dwContext)

// public\sdk\inc\iprtrmib.h
#define DEFINE_MIB_BUFFER(X,Y,Z)                                        \
    DWORD        __rgdwBuff[MIB_INFO_SIZE_IN_DWORDS(Y)]; \
    PMIB_OPAQUE_INFO    X = (PMIB_OPAQUE_INFO)__rgdwBuff;               \
    Y *                 Z = (Y *)(X->rgbyData)

// public\sdk\inc\irtprph.h
#define IRTPRPHFilter_SetMediaBufferSize(This,dwMaxMediaBufferSize)	\
    (This)->lpVtbl -> SetMediaBufferSize(This,dwMaxMediaBufferSize)
#define IRTPRPHFilter_GetMediaBufferSize(This,lpdwMaxMediaBufferSize)	\
    (This)->lpVtbl -> GetMediaBufferSize(This,lpdwMaxMediaBufferSize)

// public\sdk\inc\iwamreg.h
#define IIISApplicationAdmin_EnumerateApplicationsInPool(This,szPool,bstrBuffer)	\
    (This)->lpVtbl -> EnumerateApplicationsInPool(This,szPool,bstrBuffer)

// public\sdk\inc\ks.h
#define DEFINE_KSMETHOD_ALLOCATORSET(AllocatorSet, MethodAlloc, MethodFree)\
DEFINE_KSMETHOD_TABLE(AllocatorSet) {\
    DEFINE_KSMETHOD_ITEM_STREAMALLOCATOR_ALLOC(MethodAlloc),\
    DEFINE_KSMETHOD_ITEM_STREAMALLOCATOR_FREE(MethodFree)\
}
#define DEFINE_KSDISPATCH_TABLE( tablename, DeviceIoControl, Read, Write,\
                                 Flush, Close, QuerySecurity, SetSecurity,\
                                 FastDeviceIoControl, FastRead, FastWrite  )\
    const KSDISPATCH_TABLE tablename = \
    {\
        DeviceIoControl,        \
        Read,                   \
        Write,                  \
        Flush,                  \
        Close,                  \
        QuerySecurity,          \
        SetSecurity,            \
        FastDeviceIoControl,    \
        FastRead,               \
        FastWrite,              \
    }
#define KSEVENT_ENTRY_IRP_STORAGE(Irp)      (*(PKSEVENT_ENTRY*)&(Irp)->Tail.Overlay.DriverContext[0])

// public\sdk\inc\kxalpha.h
#define ALTERNATE_ENTRY(Name)           \
        .globl  Name;                   \
Name:;

// public\sdk\inc\kxia64.h
#define ALTERNATE_ENTRY(Name)                    \
         .##global Name;                         \
         .##type   Name, @function;              \
Name::
#define CPUBLIC_LEAF_ENTRY(Name,i)               \
         .##text;                                \
         .##proc   Name##@##i;                   \
Name##@##i::
#define LEAF_ENTRY(Name)                         \
         .##text;                                \
         .##global Name;                         \
         .##proc   Name;                         \
Name::
#define CPUBLIC_NESTED_ENTRY(Name,i)             \
         .##text;                                \
         .##proc   Name##@##i;                   \
         .##unwentry;                            \
Name##@##i::
#define NESTED_ENTRY_EX(Name, Handler)           \
         .##text;                                \
         .##global Name;                         \
         .##proc   Name;                         \
         .##personality Handler;                 \
Name::
#define NESTED_ENTRY(Name)                       \
         .##text;                                \
         .##global Name;                         \
         .##proc   Name;                         \
Name::

// public\sdk\inc\lmaccess.h
#define UF_SETTABLE_BITS        ( \
                    UF_SCRIPT | \
                    UF_ACCOUNTDISABLE | \
                    UF_LOCKOUT | \
                    UF_HOMEDIR_REQUIRED  | \
                    UF_PASSWD_NOTREQD | \
                    UF_PASSWD_CANT_CHANGE | \
                    UF_ACCOUNT_TYPE_MASK | \
                    UF_DONT_EXPIRE_PASSWD | \
                    UF_MNS_LOGON_ACCOUNT |\
                    UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED |\
                    UF_SMARTCARD_REQUIRED | \
                    UF_TRUSTED_FOR_DELEGATION | \
                    UF_NOT_DELEGATED | \
                    UF_USE_DES_KEY_ONLY  | \
                    UF_DONT_REQUIRE_PREAUTH |\
                    UF_PASSWORD_EXPIRED \
                )
#define AF_SETTABLE_BITS        (AF_OP_PRINT | AF_OP_COMM | \
                                AF_OP_SERVER | AF_OP_ACCOUNTS)

// public\sdk\inc\mapidefs.h
#define MAPI_IPROVIDERADMIN_METHODS(IPURE)								\
	MAPIMETHOD(GetLastError)											\
		(THIS_	HRESULT						hResult,					\
				ULONG						ulFlags,					\
				LPMAPIERROR FAR *			lppMAPIError) IPURE;		\
	MAPIMETHOD(GetProviderTable)										\
		(THIS_	ULONG						ulFlags,					\
				LPMAPITABLE FAR *			lppTable) IPURE;			\
	MAPIMETHOD(CreateProvider)											\
		(THIS_	LPTSTR						lpszProvider,				\
				ULONG						cValues,					\
				LPSPropValue				lpProps,					\
				ULONG						ulUIParam,					\
				ULONG						ulFlags,					\
				MAPIUID FAR *				lpUID) IPURE;				\
	MAPIMETHOD(DeleteProvider)											\
		(THIS_	LPMAPIUID					lpUID) IPURE;				\
	MAPIMETHOD(OpenProfileSection)										\
		(THIS_	LPMAPIUID					lpUID,						\
				LPCIID						lpInterface,				\
				ULONG						ulFlags,					\
				LPPROFSECT FAR *			lppProfSect) IPURE;			\

// public\sdk\inc\mapispi.h
#define MAPI_IMAPISUPPORT_METHODS1(IPURE)								\
	MAPIMETHOD(GetLastError)											\
		(THIS_	HRESULT						hResult,					\
				ULONG						ulFlags,					\
				LPMAPIERROR FAR *			lppMAPIError) IPURE;		\
	MAPIMETHOD(GetMemAllocRoutines)										\
		(THIS_	LPALLOCATEBUFFER FAR *		lpAllocateBuffer,			\
				LPALLOCATEMORE FAR *		lpAllocateMore,				\
				LPFREEBUFFER FAR *			lpFreeBuffer) IPURE;		\
	MAPIMETHOD(Subscribe)												\
		(THIS_	LPNOTIFKEY					lpKey,						\
				ULONG						ulEventMask,				\
				ULONG						ulFlags,					\
				LPMAPIADVISESINK			lpAdviseSink,				\
				ULONG FAR *					lpulConnection) IPURE;		\
	MAPIMETHOD(Unsubscribe)												\
		(THIS_	ULONG						ulConnection) IPURE;		\
	MAPIMETHOD(Notify)													\
		(THIS_	LPNOTIFKEY					lpKey,						\
				ULONG						cNotification,				\
				LPNOTIFICATION				lpNotifications,			\
				ULONG FAR *					lpulFlags) IPURE;			\
	MAPIMETHOD(ModifyStatusRow)											\
		(THIS_	ULONG						cValues,					\
				LPSPropValue				lpColumnVals,				\
				ULONG						ulFlags) IPURE;				\
	MAPIMETHOD(OpenProfileSection)										\
		(THIS_	LPMAPIUID					lpUid,						\
				ULONG						ulFlags,					\
				LPPROFSECT FAR *			lppProfileObj) IPURE;		\
	MAPIMETHOD(RegisterPreprocessor)									\
		(THIS_	LPMAPIUID					lpMuid,						\
				LPTSTR						lpszAdrType,				\
				LPTSTR						lpszDLLName,				\
				LPSTR	/* String8! */		lpszPreprocess,				\
				LPSTR	/* String8! */		lpszRemovePreprocessInfo,	\
				ULONG						ulFlags) IPURE;				\
	MAPIMETHOD(NewUID)													\
		(THIS_	LPMAPIUID					lpMuid) IPURE;				\
	MAPIMETHOD(MakeInvalid)												\
		(THIS_	ULONG						ulFlags,					\
				LPVOID						lpObject,					\
				ULONG						ulRefCount,					\
				ULONG						cMethods) IPURE;			\
#define MAPI_IABPROVIDER_METHODS(IPURE)                                 \
	MAPIMETHOD(Shutdown)												\
		(THIS_	ULONG FAR *					lpulFlags) IPURE;			\
    MAPIMETHOD(Logon)                                                   \
        (THIS_  LPMAPISUP                   lpMAPISup,                  \
                ULONG                       ulUIParam,                  \
                LPTSTR                      lpszProfileName,            \
                ULONG                       ulFlags,                    \
				ULONG FAR *					lpulpcbSecurity,			\
				LPBYTE FAR *				lppbSecurity,				\
                LPMAPIERROR FAR *			lppMAPIError,				\
                LPABLOGON FAR *             lppABLogon) IPURE;          \
#define MAPI_IMSPROVIDER_METHODS(IPURE)									\
	MAPIMETHOD(Shutdown)												\
		(THIS_	ULONG FAR *					lpulFlags) IPURE;			\
	MAPIMETHOD(Logon)													\
		(THIS_	LPMAPISUP					lpMAPISup,					\
				ULONG						ulUIParam,					\
				LPTSTR						lpszProfileName,			\
				ULONG						cbEntryID,					\
				LPENTRYID					lpEntryID,					\
				ULONG						ulFlags,					\
				LPCIID						lpInterface,				\
				ULONG FAR *					lpcbSpoolSecurity,			\
				LPBYTE FAR *				lppbSpoolSecurity,			\
                LPMAPIERROR FAR *			lppMAPIError,				\
				LPMSLOGON FAR *				lppMSLogon,					\
				LPMDB FAR *					lppMDB) IPURE;				\
	MAPIMETHOD(SpoolerLogon)											\
		(THIS_	LPMAPISUP					lpMAPISup,					\
				ULONG						ulUIParam,					\
				LPTSTR						lpszProfileName,			\
				ULONG						cbEntryID,					\
				LPENTRYID					lpEntryID,					\
				ULONG						ulFlags,					\
				LPCIID						lpInterface,				\
				ULONG						cbSpoolSecurity,			\
				LPBYTE						lpbSpoolSecurity,			\
                LPMAPIERROR FAR *			lppMAPIError,				\
				LPMSLOGON FAR *				lppMSLogon,					\
				LPMDB FAR *					lppMDB) IPURE;				\
	MAPIMETHOD(CompareStoreIDs)											\
		(THIS_	ULONG						cbEntryID1,					\
				LPENTRYID					lpEntryID1,					\
				ULONG						cbEntryID2,					\
				LPENTRYID					lpEntryID2,					\
				ULONG						ulFlags,					\
				ULONG FAR *					lpulResult) IPURE;			\
#define MAPI_IMSLOGON_METHODS(IPURE)									\
	MAPIMETHOD(GetLastError)											\
		(THIS_	HRESULT						hResult,					\
				ULONG						ulFlags,					\
				LPMAPIERROR FAR *			lppMAPIError) IPURE;		\
	MAPIMETHOD(Logoff)													\
		(THIS_	ULONG FAR *					lpulFlags) IPURE;			\
	MAPIMETHOD(OpenEntry)												\
		(THIS_	ULONG						cbEntryID,					\
				LPENTRYID					lpEntryID,					\
				LPCIID						lpInterface,				\
				ULONG						ulFlags,					\
				ULONG FAR *					lpulObjType,				\
				LPUNKNOWN FAR *				lppUnk) IPURE;				\
	MAPIMETHOD(CompareEntryIDs)											\
		(THIS_	ULONG						cbEntryID1,					\
				LPENTRYID					lpEntryID1,					\
				ULONG						cbEntryID2,					\
				LPENTRYID					lpEntryID2,					\
				ULONG						ulFlags,					\
				ULONG FAR *					lpulResult) IPURE;			\
	MAPIMETHOD(Advise)													\
		(THIS_	ULONG						cbEntryID,					\
				LPENTRYID					lpEntryID,					\
				ULONG						ulEventMask,				\
				LPMAPIADVISESINK			lpAdviseSink,				\
				ULONG FAR *					lpulConnection) IPURE;		\
	MAPIMETHOD(Unadvise)												\
		(THIS_	ULONG						ulConnection) IPURE;		\
	MAPIMETHOD(OpenStatusEntry)											\
		(THIS_	LPCIID						lpInterface,				\
				ULONG						ulFlags,					\
				ULONG FAR *					lpulObjType,				\
				LPVOID FAR *				lppEntry) IPURE;			\

// public\sdk\inc\mapitags.h
#define FIsTransmittable(ulPropTag) \
	((PROP_ID (ulPropTag) <  (ULONG)0x0E00) || \
	(PROP_ID (ulPropTag)  >= (ULONG)0x8000) || \
	((PROP_ID (ulPropTag) >= (ULONG)0x1000) && (PROP_ID (ulPropTag) < (ULONG)0x6000)) || \
	((PROP_ID (ulPropTag) >= (ULONG)0x6800) && (PROP_ID (ulPropTag) < (ULONG)0x7C00)))

// public\sdk\inc\mapiutil.h
#define MAPI_ITABLEDATA_METHODS(IPURE)									\
	MAPIMETHOD(HrGetView)												\
		(THIS_	LPSSortOrderSet				lpSSortOrderSet,			\
				CALLERRELEASE FAR *			lpfCallerRelease,			\
				ULONG						ulCallerData,				\
				LPMAPITABLE FAR *			lppMAPITable) IPURE;		\
	MAPIMETHOD(HrModifyRow)												\
		(THIS_	LPSRow) IPURE;											\
	MAPIMETHOD(HrDeleteRow)												\
		(THIS_	LPSPropValue				lpSPropValue) IPURE;		\
	MAPIMETHOD(HrQueryRow)												\
		(THIS_	LPSPropValue				lpsPropValue,				\
				LPSRow FAR *				lppSRow,					\
				ULONG FAR *					lpuliRow) IPURE;			\
	MAPIMETHOD(HrEnumRow)												\
		(THIS_	ULONG						ulRowNumber,				\
				LPSRow FAR *				lppSRow) IPURE;				\
	MAPIMETHOD(HrNotify)												\
		(THIS_	ULONG						ulFlags,					\
				ULONG						cValues,					\
				LPSPropValue				lpSPropValue) IPURE;		\
	MAPIMETHOD(HrInsertRow)												\
		(THIS_	ULONG						uliRow,						\
				LPSRow						lpSRow) IPURE;				\
	MAPIMETHOD(HrModifyRows)											\
		(THIS_	ULONG						ulFlags,					\
				LPSRowSet					lpSRowSet) IPURE;			\
	MAPIMETHOD(HrDeleteRows)											\
		(THIS_	ULONG						ulFlags,					\
				LPSRowSet					lprowsetToDelete,			\
				ULONG FAR *					cRowsDeleted) IPURE;		\

// public\sdk\inc\mapival.h
#define Validate_IMAPITable_FreeBookmark( a1, a2 ) \
			 ValidateParameters2( IMAPITable_FreeBookmark, a1, a2 )
#define UlValidate_IMAPITable_FreeBookmark( a1, a2 ) \
			 UlValidateParameters2( IMAPITable_FreeBookmark, a1, a2 )
#define CheckParameters_IMAPITable_FreeBookmark( a1, a2 ) \
			 CheckParameters2( IMAPITable_FreeBookmark, a1, a2 )

// public\sdk\inc\mediaobj.h
#define IMediaBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMediaBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMediaBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMediaBuffer_SetLength(This,cbLength)	\
    (This)->lpVtbl -> SetLength(This,cbLength)
#define IMediaBuffer_GetMaxLength(This,pcbMaxLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pcbMaxLength)
#define IMediaBuffer_GetBufferAndLength(This,ppBuffer,pcbLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppBuffer,pcbLength)
#define IMediaObject_ProcessInput(This,dwInputStreamIndex,pBuffer,dwFlags,rtTimestamp,rtTimelength)	\
    (This)->lpVtbl -> ProcessInput(This,dwInputStreamIndex,pBuffer,dwFlags,rtTimestamp,rtTimelength)
#define IMediaObject_ProcessOutput(This,dwFlags,cOutputBufferCount,pOutputBuffers,pdwStatus)	\
    (This)->lpVtbl -> ProcessOutput(This,dwFlags,cOutputBufferCount,pOutputBuffers,pdwStatus)

// public\sdk\inc\mfc42\afxctl.h
#define DECLARE_EVENT_MAP() \
private: \
	static const AFX_DATA AFX_EVENTMAP_ENTRY _eventEntries[]; \
	static DWORD _dwStockEventMask; \
protected: \
	static const AFX_DATA AFX_EVENTMAP eventMap; \
	virtual const AFX_EVENTMAP* GetEventMap() const;

// public\sdk\inc\mfc42\afxisapi.h
#define DECLARE_PARSE_MAP() \
private: \
	static AFX_PARSEMAP_ENTRY _parseEntries[]; \
public: \
	static const AFX_PARSEMAP parseMap; \
	static UINT PASCAL GetNumMapEntries(); \
	virtual const AFX_PARSEMAP* GetParseMap() const; \

// public\sdk\inc\mfc42\afxmsg_.h
#define ON_WM_CREATE() \
	{ WM_CREATE, 0, 0, 0, AfxSig_is, \
		(AFX_PMSG)(AFX_PMSGW)(int (AFX_MSG_CALL CWnd::*)(LPCREATESTRUCT))&OnCreate },
#define ON_WM_COPYDATA() \
	{ WM_COPYDATA, 0, 0, 0, AfxSig_bWCDS, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(CWnd*, COPYDATASTRUCT*))&OnCopyData },
#define ON_WM_DRAWITEM() \
	{ WM_DRAWITEM, 0, 0, 0, AfxSig_vOWNER, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(int, LPDRAWITEMSTRUCT))&OnDrawItem },
#define ON_WM_MEASUREITEM() \
	{ WM_MEASUREITEM, 0, 0, 0, AfxSig_vOWNER, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(int, LPMEASUREITEMSTRUCT))&OnMeasureItem },
#define ON_WM_DELETEITEM() \
	{ WM_DELETEITEM, 0, 0, 0, AfxSig_vOWNER, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(int, LPDELETEITEMSTRUCT))&OnDeleteItem },
#define ON_WM_COMPAREITEM() \
	{ WM_COMPAREITEM, 0, 0, 0, AfxSig_iis, \
		(AFX_PMSG)(AFX_PMSGW)(int (AFX_MSG_CALL CWnd::*)(int, LPCOMPAREITEMSTRUCT))&OnCompareItem },
#define ON_WM_NCCREATE() \
	{ WM_NCCREATE, 0, 0, 0, AfxSig_is, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(LPCREATESTRUCT))&OnNcCreate },
#define ON_WM_ASKCBFORMATNAME() \
	{ WM_ASKCBFORMATNAME, 0, 0, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, LPTSTR))&OnAskCbFormatName },
#define ON_WM_CHANGECBCHAIN() \
	{ WM_CHANGECBCHAIN, 0, 0, 0, AfxSig_vhh, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(HWND, HWND))&OnChangeCbChain },
#define ON_WM_STYLECHANGED() \
	{ WM_STYLECHANGED, 0, 0, 0, AfxSig_viSS, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(int, LPSTYLESTRUCT))&OnStyleChanged },
#define ON_WM_STYLECHANGING() \
	{ WM_STYLECHANGING, 0, 0, 0, AfxSig_viSS, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(int, LPSTYLESTRUCT))&OnStyleChanging },

// public\sdk\inc\mfc42\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// public\sdk\inc\mfc42\afxwin.h
#define DECLARE_MESSAGE_MAP() \
private: \
    static const AFX_MSGMAP_ENTRY _messageEntries[]; \
protected: \
    static AFX_DATA const AFX_MSGMAP messageMap; \
    virtual const AFX_MSGMAP* GetMessageMap() const; \
#define DECLARE_INTERFACE_MAP() \
private: \
    static const AFX_INTERFACEMAP_ENTRY _interfaceEntries[]; \
protected: \
    static AFX_DATA const AFX_INTERFACEMAP interfaceMap; \
    virtual const AFX_INTERFACEMAP* GetInterfaceMap() const; \
#define DECLARE_DISPATCH_MAP() \
private: \
    static const AFX_DISPMAP_ENTRY _dispatchEntries[]; \
    static UINT _dispatchEntryCount; \
    static DWORD _dwStockPropMask; \
protected: \
    static AFX_DATA const AFX_DISPMAP dispatchMap; \
    virtual const AFX_DISPMAP* GetDispatchMap() const; \
#define DECLARE_OLECMD_MAP() \
private: \
    static const AFX_OLECMDMAP_ENTRY _commandEntries[]; \
protected: \
    static AFX_DATA const AFX_OLECMDMAP commandMap; \
    virtual const AFX_OLECMDMAP* GetCommandMap() const; \
#define DECLARE_EVENTSINK_MAP() \
private: \
    static const AFX_EVENTSINKMAP_ENTRY _eventsinkEntries[]; \
    static UINT _eventsinkEntryCount; \
protected: \
    static AFX_DATA const AFX_EVENTSINKMAP eventsinkMap; \
    virtual const AFX_EVENTSINKMAP* GetEventSinkMap() const; \
#define DECLARE_CONNECTION_MAP() \
private: \
    static const AFX_CONNECTIONMAP_ENTRY _connectionEntries[]; \
protected: \
    static AFX_DATA const AFX_CONNECTIONMAP connectionMap; \
    virtual const AFX_CONNECTIONMAP* GetConnectionMap() const; \

// public\sdk\inc\mfc42\winres.h
#define CB_ADDSTRING    (WM_USER+3)

// public\sdk\inc\mimeole.h
#define IMimeInternational_ConvertBuffer(This,cpiSource,cpiDest,pIn,pOut,pcbRead)	\
    (This)->lpVtbl -> ConvertBuffer(This,cpiSource,cpiDest,pIn,pOut,pcbRead)
#define IMimeHeaderTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMimeHeaderTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMimeHeaderTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMimeHeaderTable_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)
#define IMimeHeaderTable_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)
#define IMimeHeaderTable_Load(This,pStm)	\
    (This)->lpVtbl -> Load(This,pStm)
#define IMimeHeaderTable_Save(This,pStm,fClearDirty)	\
    (This)->lpVtbl -> Save(This,pStm,fClearDirty)
#define IMimeHeaderTable_GetSizeMax(This,pcbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pcbSize)
#define IMimeHeaderTable_FindFirstRow(This,pFindHeader,phRow)	\
    (This)->lpVtbl -> FindFirstRow(This,pFindHeader,phRow)
#define IMimeHeaderTable_CountRows(This,pszHeader,pcRows)	\
    (This)->lpVtbl -> CountRows(This,pszHeader,pcRows)
#define IMimeHeaderTable_AppendRow(This,pszHeader,dwFlags,pszData,cchData,phRow)	\
    (This)->lpVtbl -> AppendRow(This,pszHeader,dwFlags,pszData,cchData,phRow)
#define IMimeHeaderTable_DeleteRow(This,hRow)	\
    (This)->lpVtbl -> DeleteRow(This,hRow)
#define IMimeHeaderTable_GetRowData(This,hRow,dwFlags,ppszData,pcchData)	\
    (This)->lpVtbl -> GetRowData(This,hRow,dwFlags,ppszData,pcchData)
#define IMimeHeaderTable_SetRowData(This,hRow,dwFlags,pszData,cchData)	\
    (This)->lpVtbl -> SetRowData(This,hRow,dwFlags,pszData,cchData)
#define IMimeHeaderTable_GetRowInfo(This,hRow,pInfo)	\
    (This)->lpVtbl -> GetRowInfo(This,hRow,pInfo)
#define IMimeHeaderTable_SetRowNumber(This,hRow,dwRowNumber)	\
    (This)->lpVtbl -> SetRowNumber(This,hRow,dwRowNumber)
#define IMimeHeaderTable_EnumRows(This,pszHeader,dwFlags,ppEnum)	\
    (This)->lpVtbl -> EnumRows(This,pszHeader,dwFlags,ppEnum)
#define IMimeHeaderTable_Clone(This,ppTable)	\
    (This)->lpVtbl -> Clone(This,ppTable)
#define IMimeHeaderTable_BindToObject(This,riid,ppvObject)	\
    (This)->lpVtbl -> BindToObject(This,riid,ppvObject)
#define IMimePropertySet_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)
#define IMimeAddressTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMimeAddressTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMimeAddressTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMimeAddressTable_Append(This,dwAdrType,ietFriendly,pszFriendly,pszEmail,phAddress)	\
    (This)->lpVtbl -> Append(This,dwAdrType,ietFriendly,pszFriendly,pszEmail,phAddress)
#define IMimeAddressTable_Insert(This,pAddress,phAddress)	\
    (This)->lpVtbl -> Insert(This,pAddress,phAddress)
#define IMimeAddressTable_SetProps(This,hAddress,pAddress)	\
    (This)->lpVtbl -> SetProps(This,hAddress,pAddress)
#define IMimeAddressTable_GetProps(This,hAddress,pAddress)	\
    (This)->lpVtbl -> GetProps(This,hAddress,pAddress)
#define IMimeAddressTable_GetSender(This,pAddress)	\
    (This)->lpVtbl -> GetSender(This,pAddress)
#define IMimeAddressTable_CountTypes(This,dwAdrTypes,pcAdrs)	\
    (This)->lpVtbl -> CountTypes(This,dwAdrTypes,pcAdrs)
#define IMimeAddressTable_EnumTypes(This,dwAdrTypes,dwProps,ppEnum)	\
    (This)->lpVtbl -> EnumTypes(This,dwAdrTypes,dwProps,ppEnum)
#define IMimeAddressTable_Delete(This,hAddress)	\
    (This)->lpVtbl -> Delete(This,hAddress)
#define IMimeAddressTable_DeleteTypes(This,dwAdrTypes)	\
    (This)->lpVtbl -> DeleteTypes(This,dwAdrTypes)
#define IMimeAddressTable_GetFormat(This,dwAdrType,format,ppszFormat)	\
    (This)->lpVtbl -> GetFormat(This,dwAdrType,format,ppszFormat)
#define IMimeAddressTable_AppendRfc822(This,dwAdrType,ietEncoding,pszRfc822Adr)	\
    (This)->lpVtbl -> AppendRfc822(This,dwAdrType,ietEncoding,pszRfc822Adr)
#define IMimeAddressTable_Clone(This,ppTable)	\
    (This)->lpVtbl -> Clone(This,ppTable)
#define IMimeAddressTable_BindToObject(This,riid,ppvObject)	\
    (This)->lpVtbl -> BindToObject(This,riid,ppvObject)
#define IMimeBody_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)
#define IMimeBody_GetEstimatedSize(This,ietEncoding,pcbSize)	\
    (This)->lpVtbl -> GetEstimatedSize(This,ietEncoding,pcbSize)
#define IMimeMessageTree_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)
#define IMimeMessageTree_GetMessageSize(This,pcbSize,dwFlags)	\
    (This)->lpVtbl -> GetMessageSize(This,pcbSize,dwFlags)
#define IMimeMessageTree_CountBodies(This,hParent,fRecurse,pcBodies)	\
    (This)->lpVtbl -> CountBodies(This,hParent,fRecurse,pcBodies)
#define IMimeMessage_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)
#define IMimeMessage_GetMessageSize(This,pcbSize,dwFlags)	\
    (This)->lpVtbl -> GetMessageSize(This,pcbSize,dwFlags)
#define IMimeMessage_CountBodies(This,hParent,fRecurse,pcBodies)	\
    (This)->lpVtbl -> CountBodies(This,hParent,fRecurse,pcBodies)
#define IMimeMessage_GetAddressTable(This,ppTable)	\
    (This)->lpVtbl -> GetAddressTable(This,ppTable)
#define IMimeMessage_SplitMessage(This,cbMaxPart,ppParts)	\
    (This)->lpVtbl -> SplitMessage(This,cbMaxPart,ppParts)
#define IHashTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHashTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHashTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHashTable_Init(This,dwSize,fDupeKeys)	\
    (This)->lpVtbl -> Init(This,dwSize,fDupeKeys)
#define IHashTable_Insert(This,psz,pv,dwFlags)	\
    (This)->lpVtbl -> Insert(This,psz,pv,dwFlags)
#define IHashTable_Replace(This,psz,pv)	\
    (This)->lpVtbl -> Replace(This,psz,pv)
#define IHashTable_Find(This,psz,fRemove,ppv)	\
    (This)->lpVtbl -> Find(This,psz,fRemove,ppv)
#define IHashTable_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IMimeAllocator_Alloc(This,cb)	\
    (This)->lpVtbl -> Alloc(This,cb)
#define IMimeAllocator_Realloc(This,pv,cb)	\
    (This)->lpVtbl -> Realloc(This,pv,cb)

// public\sdk\inc\mlang.h
#define IMLangStringWStr_SetStrBufW(This,lDestPos,lDestLen,pSrcBuf,pcchActual,plActualLen)	\
    (This)->lpVtbl -> SetStrBufW(This,lDestPos,lDestLen,pSrcBuf,pcchActual,plActualLen)

// public\sdk\inc\mmc.h
#define IResultData_SetDescBarText(This,DescText)	\
    (This)->lpVtbl -> SetDescBarText(This,DescText)
#define IStringTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IStringTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IStringTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IStringTable_AddString(This,pszAdd,pStringID)	\
    (This)->lpVtbl -> AddString(This,pszAdd,pStringID)
#define IStringTable_GetString(This,StringID,cchBuffer,lpBuffer,pcchOut)	\
    (This)->lpVtbl -> GetString(This,StringID,cchBuffer,lpBuffer,pcchOut)
#define IStringTable_GetStringLength(This,StringID,pcchString)	\
    (This)->lpVtbl -> GetStringLength(This,StringID,pcchString)
#define IStringTable_DeleteString(This,StringID)	\
    (This)->lpVtbl -> DeleteString(This,StringID)
#define IStringTable_DeleteAllStrings(This)	\
    (This)->lpVtbl -> DeleteAllStrings(This)
#define IStringTable_FindString(This,pszFind,pStringID)	\
    (This)->lpVtbl -> FindString(This,pszFind,pStringID)
#define IStringTable_Enumerate(This,ppEnum)	\
    (This)->lpVtbl -> Enumerate(This,ppEnum)
#define IResultData2_SetDescBarText(This,DescText)	\
    (This)->lpVtbl -> SetDescBarText(This,DescText)

// public\sdk\inc\mobsync.h
#define ISyncMgrSynchronize_Initialize(This,dwReserved,dwSyncMgrFlags,cbCookie,lpCookie)	\
    (This)->lpVtbl -> Initialize(This,dwReserved,dwSyncMgrFlags,cbCookie,lpCookie)
#define ISyncMgrSynchronize_PrepareForSync(This,cbNumItems,pItemIDs,hWndParent,dwReserved)	\
    (This)->lpVtbl -> PrepareForSync(This,cbNumItems,pItemIDs,hWndParent,dwReserved)
#define ISyncMgrSynchronizeCallback_ShowErrorCompleted(This,hr,cbNumItems,pItemIDs)	\
    (This)->lpVtbl -> ShowErrorCompleted(This,hr,cbNumItems,pItemIDs)
#define ISyncMgrSynchronizeInvoke_UpdateItems(This,dwInvokeFlags,rclsid,cbCookie,lpCookie)	\
    (This)->lpVtbl -> UpdateItems(This,dwInvokeFlags,rclsid,cbCookie,lpCookie)

// public\sdk\inc\mobsyncp.h
#define IPrivSyncMgrSynchronizeInvoke_UpdateItems(This,dwInvokeFlags,rclsid,cbCookie,lpCookie)	\
    (This)->lpVtbl -> UpdateItems(This,dwInvokeFlags,rclsid,cbCookie,lpCookie)
#define IPrivSyncMgrSynchronizeInvoke_RasPendingDisconnect(This,cbConnectionName,lpConnectionName)	\
    (This)->lpVtbl -> RasPendingDisconnect(This,cbConnectionName,lpConnectionName)
#define ISyncSchedule_GetConnection(This,pcbSize,pwszConnectionName,pdwConnType)	\
    (This)->lpVtbl -> GetConnection(This,pcbSize,pwszConnectionName,pdwConnType)
#define ISyncSchedule_GetScheduleName(This,pcbSize,pwszScheduleName)	\
    (This)->lpVtbl -> GetScheduleName(This,pcbSize,pwszScheduleName)
#define ISyncSchedule_GetAccountInformation(This,pcbSize,pwszAccountName)	\
    (This)->lpVtbl -> GetAccountInformation(This,pcbSize,pwszAccountName)
#define ISyncSchedulep_GetConnection(This,pcbSize,pwszConnectionName,pdwConnType)	\
    (This)->lpVtbl -> GetConnection(This,pcbSize,pwszConnectionName,pdwConnType)
#define ISyncSchedulep_GetScheduleName(This,pcbSize,pwszScheduleName)	\
    (This)->lpVtbl -> GetScheduleName(This,pcbSize,pwszScheduleName)
#define ISyncSchedulep_GetAccountInformation(This,pcbSize,pwszAccountName)	\
    (This)->lpVtbl -> GetAccountInformation(This,pcbSize,pwszAccountName)
#define IOldSyncMgrSynchronize_Initialize(This,dwReserved,dwSyncMgrFlags,cbCookie,lpCookie)	\
    (This)->lpVtbl -> Initialize(This,dwReserved,dwSyncMgrFlags,cbCookie,lpCookie)
#define IOldSyncMgrSynchronize_PrepareForSync(This,cbNumItems,pItemIDs,hWndParent,dwReserved)	\
    (This)->lpVtbl -> PrepareForSync(This,cbNumItems,pItemIDs,hWndParent,dwReserved)
#define IOldSyncMgrSynchronize_ShowError(This,hWndParent,ErrorID,pcbNumItems,ppItemIDs)	\
    (This)->lpVtbl -> ShowError(This,hWndParent,ErrorID,pcbNumItems,ppItemIDs)

// public\sdk\inc\mountmgr.h
#define IOCTL_MOUNTMGR_CREATE_POINT                 CTL_CODE(MOUNTMGRCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_DELETE_POINTS                CTL_CODE(MOUNTMGRCONTROLTYPE, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_DELETE_POINTS_DBONLY         CTL_CODE(MOUNTMGRCONTROLTYPE, 3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_AUTO_DL_ASSIGNMENTS          CTL_CODE(MOUNTMGRCONTROLTYPE, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_CREATED   CTL_CODE(MOUNTMGRCONTROLTYPE, 6, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_DELETED   CTL_CODE(MOUNTMGRCONTROLTYPE, 7, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_KEEP_LINKS_WHEN_OFFLINE      CTL_CODE(MOUNTMGRCONTROLTYPE, 9, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
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

// public\sdk\inc\mqoai.h
#define IMSMQMessage_get_BodyLength(This,pcbBody)	\
    (This)->lpVtbl -> get_BodyLength(This,pcbBody)
#define IMSMQMessage2_get_BodyLength(This,pcbBody)	\
    (This)->lpVtbl -> get_BodyLength(This,pcbBody)
#define IMSMQMessage3_get_BodyLength(This,pcbBody)	\
    (This)->lpVtbl -> get_BodyLength(This,pcbBody)

// public\sdk\inc\mscoree.h
#define IManagedObject_GetSerializedBuffer(This,pBSTR)	\
    (This)->lpVtbl -> GetSerializedBuffer(This,pBSTR)

// public\sdk\inc\msctf.h
#define ITfQueryEmbedded_QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)	\
    (This)->lpVtbl -> QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)
#define ITfEditRecord_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITfEditRecord_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITfEditRecord_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITfEditRecord_GetSelectionStatus(This,pfChanged)	\
    (This)->lpVtbl -> GetSelectionStatus(This,pfChanged)
#define ITfEditRecord_GetTextAndPropertyUpdates(This,dwFlags,prgProperties,cProperties,ppEnum)	\
    (This)->lpVtbl -> GetTextAndPropertyUpdates(This,dwFlags,prgProperties,cProperties,ppEnum)
#define ITfTextEditSink_OnEndEdit(This,pic,ecReadOnly,pEditRecord)	\
    (This)->lpVtbl -> OnEndEdit(This,pic,ecReadOnly,pEditRecord)
#define ITfPropertyStore_Serialize(This,pStream,pcb)	\
    (This)->lpVtbl -> Serialize(This,pStream,pcb)
#define ITfCreatePropertyStore_CreatePropertyStore(This,guidProp,pRange,cb,pStream,ppStore)	\
    (This)->lpVtbl -> CreatePropertyStore(This,guidProp,pRange,cb,pStream,ppStore)

// public\sdk\inc\msdadc.h
#define IDataConvert_DataConvert(This,wSrcType,wDstType,cbSrcLength,pcbDstLength,pSrc,pDst,cbDstMaxLength,dbsSrcStatus,pdbsStatus,bPrecision,bScale,dwFlags)	\
    (This)->lpVtbl -> DataConvert(This,wSrcType,wDstType,cbSrcLength,pcbDstLength,pSrc,pDst,cbDstMaxLength,dbsSrcStatus,pdbsStatus,bPrecision,bScale,dwFlags)
#define IDataConvert_GetConversionSize(This,wSrcType,wDstType,pcbSrcLength,pcbDstLength,pSrc)	\
    (This)->lpVtbl -> GetConversionSize(This,wSrcType,wDstType,pcbSrcLength,pcbDstLength,pSrc)

// public\sdk\inc\msdasql.h
#define ISQLRequestDiagFields_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISQLRequestDiagFields_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISQLRequestDiagFields_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISQLRequestDiagFields_RequestDiagFields(This,cDiagFields,rgDiagFields)	\
    (This)->lpVtbl -> RequestDiagFields(This,cDiagFields,rgDiagFields)
#define ISQLGetDiagField_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISQLGetDiagField_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISQLGetDiagField_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISQLGetDiagField_GetDiagField(This,pDiagInfo)	\
    (This)->lpVtbl -> GetDiagField(This,pDiagInfo)

// public\sdk\inc\mshtmhst.h
#define IDocHostUIHandler_ResizeBorder(This,prcBorder,pUIWindow,fRameWindow)	\
    (This)->lpVtbl -> ResizeBorder(This,prcBorder,pUIWindow,fRameWindow)
#define IDocHostUIHandler2_ResizeBorder(This,prcBorder,pUIWindow,fRameWindow)	\
    (This)->lpVtbl -> ResizeBorder(This,prcBorder,pUIWindow,fRameWindow)

// public\sdk\inc\mshtmlc.h
#define IHTMLStyle2_put_tableLayout(This,v)	\
    (This)->lpVtbl -> put_tableLayout(This,v)
#define IHTMLStyle2_get_tableLayout(This,p)	\
    (This)->lpVtbl -> get_tableLayout(This,p)
#define IHTMLRuleStyle2_put_tableLayout(This,v)	\
    (This)->lpVtbl -> put_tableLayout(This,v)
#define IHTMLRuleStyle2_get_tableLayout(This,p)	\
    (This)->lpVtbl -> get_tableLayout(This,p)
#define IHTMLCurrentStyle_get_tableLayout(This,p)	\
    (This)->lpVtbl -> get_tableLayout(This,p)
#define IHTMLElement_get_recordNumber(This,p)	\
    (This)->lpVtbl -> get_recordNumber(This,p)
#define IHTMLElement3_put_contentEditable(This,v)	\
    (This)->lpVtbl -> put_contentEditable(This,v)
#define IHTMLElement3_get_contentEditable(This,p)	\
    (This)->lpVtbl -> get_contentEditable(This,p)
#define IHTMLElement3_get_isContentEditable(This,p)	\
    (This)->lpVtbl -> get_isContentEditable(This,p)
#define IHTMLElementDefaults_put_contentEditable(This,v)	\
    (This)->lpVtbl -> put_contentEditable(This,v)
#define IHTMLElementDefaults_get_contentEditable(This,p)	\
    (This)->lpVtbl -> get_contentEditable(This,p)
#define IHTCDescBehavior_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTCDescBehavior_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTCDescBehavior_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTCDescBehavior_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTCDescBehavior_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTCDescBehavior_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTCDescBehavior_get_urn(This,p)	\
    (This)->lpVtbl -> get_urn(This,p)
#define IHTCDescBehavior_get_name(This,p)	\
    (This)->lpVtbl -> get_name(This,p)
#define DispHTCDescBehavior_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTCDescBehavior_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTCDescBehavior_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTCDescBehavior_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTCDescBehavior_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTCDescBehavior_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLGenericElement_get_recordset(This,p)	\
    (This)->lpVtbl -> get_recordset(This,p)
#define IHTMLEventObj2_putref_recordset(This,v)	\
    (This)->lpVtbl -> putref_recordset(This,v)
#define IHTMLEventObj2_get_recordset(This,p)	\
    (This)->lpVtbl -> get_recordset(This,p)
#define IHTMLWindow2_put_offscreenBuffering(This,v)	\
    (This)->lpVtbl -> put_offscreenBuffering(This,v)
#define IHTMLWindow2_get_offscreenBuffering(This,p)	\
    (This)->lpVtbl -> get_offscreenBuffering(This,p)
#define IHTMLScreen_put_bufferDepth(This,v)	\
    (This)->lpVtbl -> put_bufferDepth(This,v)
#define IHTMLScreen_get_bufferDepth(This,p)	\
    (This)->lpVtbl -> get_bufferDepth(This,p)
#define IWBScriptControl_put_selectableContent(This,v)	\
    (This)->lpVtbl -> put_selectableContent(This,v)
#define IWBScriptControl_get_selectableContent(This,p)	\
    (This)->lpVtbl -> get_selectableContent(This,p)
#define IHTMLTableCaption_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableCaption_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableCaption_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableCaption_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableCaption_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableCaption_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLTableCaption_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTableCaption_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTableCaption_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTableCaption_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTableCaption_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTableCaption_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define HTMLTableEvents2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define HTMLTableEvents2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define HTMLTableEvents2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define HTMLTableEvents2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define HTMLTableEvents2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define HTMLTableEvents2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define HTMLTableEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define HTMLTableEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define HTMLTableEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define HTMLTableEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define HTMLTableEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define HTMLTableEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableSection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableSection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableSection_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableSection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableSection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableSection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableSection_put_bgColor(This,v)	\
    (This)->lpVtbl -> put_bgColor(This,v)
#define IHTMLTableSection_get_bgColor(This,p)	\
    (This)->lpVtbl -> get_bgColor(This,p)
#define IHTMLTableSection_get_rows(This,p)	\
    (This)->lpVtbl -> get_rows(This,p)
#define IHTMLTableSection_insertRow(This,index,row)	\
    (This)->lpVtbl -> insertRow(This,index,row)
#define IHTMLTableSection_deleteRow(This,index)	\
    (This)->lpVtbl -> deleteRow(This,index)
#define IHTMLTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTable_put_cols(This,v)	\
    (This)->lpVtbl -> put_cols(This,v)
#define IHTMLTable_get_cols(This,p)	\
    (This)->lpVtbl -> get_cols(This,p)
#define IHTMLTable_put_border(This,v)	\
    (This)->lpVtbl -> put_border(This,v)
#define IHTMLTable_get_border(This,p)	\
    (This)->lpVtbl -> get_border(This,p)
#define IHTMLTable_put_frame(This,v)	\
    (This)->lpVtbl -> put_frame(This,v)
#define IHTMLTable_get_frame(This,p)	\
    (This)->lpVtbl -> get_frame(This,p)
#define IHTMLTable_put_rules(This,v)	\
    (This)->lpVtbl -> put_rules(This,v)
#define IHTMLTable_get_rules(This,p)	\
    (This)->lpVtbl -> get_rules(This,p)
#define IHTMLTable_put_cellSpacing(This,v)	\
    (This)->lpVtbl -> put_cellSpacing(This,v)
#define IHTMLTable_get_cellSpacing(This,p)	\
    (This)->lpVtbl -> get_cellSpacing(This,p)
#define IHTMLTable_put_cellPadding(This,v)	\
    (This)->lpVtbl -> put_cellPadding(This,v)
#define IHTMLTable_get_cellPadding(This,p)	\
    (This)->lpVtbl -> get_cellPadding(This,p)
#define IHTMLTable_put_bgColor(This,v)	\
    (This)->lpVtbl -> put_bgColor(This,v)
#define IHTMLTable_get_bgColor(This,p)	\
    (This)->lpVtbl -> get_bgColor(This,p)
#define IHTMLTable_put_borderColor(This,v)	\
    (This)->lpVtbl -> put_borderColor(This,v)
#define IHTMLTable_get_borderColor(This,p)	\
    (This)->lpVtbl -> get_borderColor(This,p)
#define IHTMLTable_put_borderColorLight(This,v)	\
    (This)->lpVtbl -> put_borderColorLight(This,v)
#define IHTMLTable_get_borderColorLight(This,p)	\
    (This)->lpVtbl -> get_borderColorLight(This,p)
#define IHTMLTable_put_borderColorDark(This,v)	\
    (This)->lpVtbl -> put_borderColorDark(This,v)
#define IHTMLTable_get_borderColorDark(This,p)	\
    (This)->lpVtbl -> get_borderColorDark(This,p)
#define IHTMLTable_refresh(This)	\
    (This)->lpVtbl -> refresh(This)
#define IHTMLTable_get_rows(This,p)	\
    (This)->lpVtbl -> get_rows(This,p)
#define IHTMLTable_put_width(This,v)	\
    (This)->lpVtbl -> put_width(This,v)
#define IHTMLTable_get_width(This,p)	\
    (This)->lpVtbl -> get_width(This,p)
#define IHTMLTable_put_height(This,v)	\
    (This)->lpVtbl -> put_height(This,v)
#define IHTMLTable_get_height(This,p)	\
    (This)->lpVtbl -> get_height(This,p)
#define IHTMLTable_get_tHead(This,p)	\
    (This)->lpVtbl -> get_tHead(This,p)
#define IHTMLTable_get_tFoot(This,p)	\
    (This)->lpVtbl -> get_tFoot(This,p)
#define IHTMLTable_get_tBodies(This,p)	\
    (This)->lpVtbl -> get_tBodies(This,p)
#define IHTMLTable_get_caption(This,p)	\
    (This)->lpVtbl -> get_caption(This,p)
#define IHTMLTable_createTHead(This,head)	\
    (This)->lpVtbl -> createTHead(This,head)
#define IHTMLTable_deleteTHead(This)	\
    (This)->lpVtbl -> deleteTHead(This)
#define IHTMLTable_createTFoot(This,foot)	\
    (This)->lpVtbl -> createTFoot(This,foot)
#define IHTMLTable_deleteTFoot(This)	\
    (This)->lpVtbl -> deleteTFoot(This)
#define IHTMLTable_createCaption(This,caption)	\
    (This)->lpVtbl -> createCaption(This,caption)
#define IHTMLTable_deleteCaption(This)	\
    (This)->lpVtbl -> deleteCaption(This)
#define IHTMLTable_insertRow(This,index,row)	\
    (This)->lpVtbl -> insertRow(This,index,row)
#define IHTMLTable_deleteRow(This,index)	\
    (This)->lpVtbl -> deleteRow(This,index)
#define IHTMLTable_get_readyState(This,p)	\
    (This)->lpVtbl -> get_readyState(This,p)
#define IHTMLTable_put_onreadystatechange(This,v)	\
    (This)->lpVtbl -> put_onreadystatechange(This,v)
#define IHTMLTable_get_onreadystatechange(This,p)	\
    (This)->lpVtbl -> get_onreadystatechange(This,p)
#define IHTMLTable2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTable2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTable2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTable2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTable2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTable2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTable2_get_cells(This,p)	\
    (This)->lpVtbl -> get_cells(This,p)
#define IHTMLTable2_moveRow(This,indexFrom,indexTo,row)	\
    (This)->lpVtbl -> moveRow(This,indexFrom,indexTo,row)
#define IHTMLTable3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTable3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTable3_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTable3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTable3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTable3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTable3_put_summary(This,v)	\
    (This)->lpVtbl -> put_summary(This,v)
#define IHTMLTable3_get_summary(This,p)	\
    (This)->lpVtbl -> get_summary(This,p)
#define IHTMLTableCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableCol_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableCol_put_span(This,v)	\
    (This)->lpVtbl -> put_span(This,v)
#define IHTMLTableCol_get_span(This,p)	\
    (This)->lpVtbl -> get_span(This,p)
#define IHTMLTableCol_put_width(This,v)	\
    (This)->lpVtbl -> put_width(This,v)
#define IHTMLTableCol_get_width(This,p)	\
    (This)->lpVtbl -> get_width(This,p)
#define IHTMLTableCol2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableCol2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableCol2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableCol2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableCol2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableCol2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableCol2_put_ch(This,v)	\
    (This)->lpVtbl -> put_ch(This,v)
#define IHTMLTableCol2_get_ch(This,p)	\
    (This)->lpVtbl -> get_ch(This,p)
#define IHTMLTableCol2_put_chOff(This,v)	\
    (This)->lpVtbl -> put_chOff(This,v)
#define IHTMLTableCol2_get_chOff(This,p)	\
    (This)->lpVtbl -> get_chOff(This,p)
#define IHTMLTableSection2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableSection2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableSection2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableSection2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableSection2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableSection2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableSection2_moveRow(This,indexFrom,indexTo,row)	\
    (This)->lpVtbl -> moveRow(This,indexFrom,indexTo,row)
#define IHTMLTableSection3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableSection3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableSection3_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableSection3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableSection3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableSection3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableSection3_put_ch(This,v)	\
    (This)->lpVtbl -> put_ch(This,v)
#define IHTMLTableSection3_get_ch(This,p)	\
    (This)->lpVtbl -> get_ch(This,p)
#define IHTMLTableSection3_put_chOff(This,v)	\
    (This)->lpVtbl -> put_chOff(This,v)
#define IHTMLTableSection3_get_chOff(This,p)	\
    (This)->lpVtbl -> get_chOff(This,p)
#define IHTMLTableRow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableRow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableRow_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableRow_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableRow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableRow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableRow_put_bgColor(This,v)	\
    (This)->lpVtbl -> put_bgColor(This,v)
#define IHTMLTableRow_get_bgColor(This,p)	\
    (This)->lpVtbl -> get_bgColor(This,p)
#define IHTMLTableRow_put_borderColor(This,v)	\
    (This)->lpVtbl -> put_borderColor(This,v)
#define IHTMLTableRow_get_borderColor(This,p)	\
    (This)->lpVtbl -> get_borderColor(This,p)
#define IHTMLTableRow_put_borderColorLight(This,v)	\
    (This)->lpVtbl -> put_borderColorLight(This,v)
#define IHTMLTableRow_get_borderColorLight(This,p)	\
    (This)->lpVtbl -> get_borderColorLight(This,p)
#define IHTMLTableRow_put_borderColorDark(This,v)	\
    (This)->lpVtbl -> put_borderColorDark(This,v)
#define IHTMLTableRow_get_borderColorDark(This,p)	\
    (This)->lpVtbl -> get_borderColorDark(This,p)
#define IHTMLTableRow_get_rowIndex(This,p)	\
    (This)->lpVtbl -> get_rowIndex(This,p)
#define IHTMLTableRow_get_sectionRowIndex(This,p)	\
    (This)->lpVtbl -> get_sectionRowIndex(This,p)
#define IHTMLTableRow_get_cells(This,p)	\
    (This)->lpVtbl -> get_cells(This,p)
#define IHTMLTableRow_insertCell(This,index,row)	\
    (This)->lpVtbl -> insertCell(This,index,row)
#define IHTMLTableRow_deleteCell(This,index)	\
    (This)->lpVtbl -> deleteCell(This,index)
#define IHTMLTableRow2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableRow2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableRow2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableRow2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableRow2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableRow2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableRow2_put_height(This,v)	\
    (This)->lpVtbl -> put_height(This,v)
#define IHTMLTableRow2_get_height(This,p)	\
    (This)->lpVtbl -> get_height(This,p)
#define IHTMLTableRow3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableRow3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableRow3_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableRow3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableRow3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableRow3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableRow3_put_ch(This,v)	\
    (This)->lpVtbl -> put_ch(This,v)
#define IHTMLTableRow3_get_ch(This,p)	\
    (This)->lpVtbl -> get_ch(This,p)
#define IHTMLTableRow3_put_chOff(This,v)	\
    (This)->lpVtbl -> put_chOff(This,v)
#define IHTMLTableRow3_get_chOff(This,p)	\
    (This)->lpVtbl -> get_chOff(This,p)
#define IHTMLTableRowMetrics_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableRowMetrics_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableRowMetrics_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableRowMetrics_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableRowMetrics_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableRowMetrics_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableRowMetrics_get_clientHeight(This,p)	\
    (This)->lpVtbl -> get_clientHeight(This,p)
#define IHTMLTableRowMetrics_get_clientWidth(This,p)	\
    (This)->lpVtbl -> get_clientWidth(This,p)
#define IHTMLTableRowMetrics_get_clientTop(This,p)	\
    (This)->lpVtbl -> get_clientTop(This,p)
#define IHTMLTableRowMetrics_get_clientLeft(This,p)	\
    (This)->lpVtbl -> get_clientLeft(This,p)
#define IHTMLTableCell_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableCell_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableCell_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableCell_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableCell_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableCell_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableCell_put_rowSpan(This,v)	\
    (This)->lpVtbl -> put_rowSpan(This,v)
#define IHTMLTableCell_get_rowSpan(This,p)	\
    (This)->lpVtbl -> get_rowSpan(This,p)
#define IHTMLTableCell_put_colSpan(This,v)	\
    (This)->lpVtbl -> put_colSpan(This,v)
#define IHTMLTableCell_get_colSpan(This,p)	\
    (This)->lpVtbl -> get_colSpan(This,p)
#define IHTMLTableCell_put_bgColor(This,v)	\
    (This)->lpVtbl -> put_bgColor(This,v)
#define IHTMLTableCell_get_bgColor(This,p)	\
    (This)->lpVtbl -> get_bgColor(This,p)
#define IHTMLTableCell_put_noWrap(This,v)	\
    (This)->lpVtbl -> put_noWrap(This,v)
#define IHTMLTableCell_get_noWrap(This,p)	\
    (This)->lpVtbl -> get_noWrap(This,p)
#define IHTMLTableCell_put_borderColor(This,v)	\
    (This)->lpVtbl -> put_borderColor(This,v)
#define IHTMLTableCell_get_borderColor(This,p)	\
    (This)->lpVtbl -> get_borderColor(This,p)
#define IHTMLTableCell_put_borderColorLight(This,v)	\
    (This)->lpVtbl -> put_borderColorLight(This,v)
#define IHTMLTableCell_get_borderColorLight(This,p)	\
    (This)->lpVtbl -> get_borderColorLight(This,p)
#define IHTMLTableCell_put_borderColorDark(This,v)	\
    (This)->lpVtbl -> put_borderColorDark(This,v)
#define IHTMLTableCell_get_borderColorDark(This,p)	\
    (This)->lpVtbl -> get_borderColorDark(This,p)
#define IHTMLTableCell_put_width(This,v)	\
    (This)->lpVtbl -> put_width(This,v)
#define IHTMLTableCell_get_width(This,p)	\
    (This)->lpVtbl -> get_width(This,p)
#define IHTMLTableCell_put_height(This,v)	\
    (This)->lpVtbl -> put_height(This,v)
#define IHTMLTableCell_get_height(This,p)	\
    (This)->lpVtbl -> get_height(This,p)
#define IHTMLTableCell_get_cellIndex(This,p)	\
    (This)->lpVtbl -> get_cellIndex(This,p)
#define IHTMLTableCell2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableCell2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableCell2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableCell2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableCell2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableCell2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableCell2_put_abbr(This,v)	\
    (This)->lpVtbl -> put_abbr(This,v)
#define IHTMLTableCell2_get_abbr(This,p)	\
    (This)->lpVtbl -> get_abbr(This,p)
#define IHTMLTableCell2_put_axis(This,v)	\
    (This)->lpVtbl -> put_axis(This,v)
#define IHTMLTableCell2_get_axis(This,p)	\
    (This)->lpVtbl -> get_axis(This,p)
#define IHTMLTableCell2_put_ch(This,v)	\
    (This)->lpVtbl -> put_ch(This,v)
#define IHTMLTableCell2_get_ch(This,p)	\
    (This)->lpVtbl -> get_ch(This,p)
#define IHTMLTableCell2_put_chOff(This,v)	\
    (This)->lpVtbl -> put_chOff(This,v)
#define IHTMLTableCell2_get_chOff(This,p)	\
    (This)->lpVtbl -> get_chOff(This,p)
#define IHTMLTableCell2_put_headers(This,v)	\
    (This)->lpVtbl -> put_headers(This,v)
#define IHTMLTableCell2_get_headers(This,p)	\
    (This)->lpVtbl -> get_headers(This,p)
#define IHTMLTableCell2_put_scope(This,v)	\
    (This)->lpVtbl -> put_scope(This,v)
#define IHTMLTableCell2_get_scope(This,p)	\
    (This)->lpVtbl -> get_scope(This,p)
#define DispHTMLTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLTableCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTableCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTableCol_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTableCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTableCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTableCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLTableSection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTableSection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTableSection_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTableSection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTableSection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTableSection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLTableRow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTableRow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTableRow_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTableRow_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTableRow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTableRow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLTableCell_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTableCell_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTableCell_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTableCell_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTableCell_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTableCell_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLObjectElement_putref_recordset(This,v)	\
    (This)->lpVtbl -> putref_recordset(This,v)
#define IHTMLObjectElement_get_recordset(This,p)	\
    (This)->lpVtbl -> get_recordset(This,p)
#define IHTMLFieldSetElement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLFieldSetElement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLFieldSetElement_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLFieldSetElement_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLFieldSetElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLFieldSetElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLFieldSetElement2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLFieldSetElement2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLFieldSetElement2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLFieldSetElement2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLFieldSetElement2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLFieldSetElement2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLFieldSetElement2_get_form(This,p)	\
    (This)->lpVtbl -> get_form(This,p)
#define DispHTMLFieldSetElement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLFieldSetElement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLFieldSetElement_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLFieldSetElement_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLFieldSetElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLFieldSetElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLChangePlayback_ExecChange(This,pbRecord,fForward)	\
    (This)->lpVtbl -> ExecChange(This,pbRecord,fForward)
#define IHTMLPainter_Draw(This,rcBounds,rcUpdate,lDrawFlags,hdc,pvDrawObject)	\
    (This)->lpVtbl -> Draw(This,rcBounds,rcUpdate,lDrawFlags,hdc,pvDrawObject)
#define IEnumPrivacyRecords_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumPrivacyRecords_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumPrivacyRecords_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumPrivacyRecords_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumPrivacyRecords_GetSize(This,pSize)	\
    (This)->lpVtbl -> GetSize(This,pSize)
#define IEnumPrivacyRecords_GetPrivacyImpacted(This,pState)	\
    (This)->lpVtbl -> GetPrivacyImpacted(This,pState)
#define IElementNamespaceTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IElementNamespaceTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IElementNamespaceTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IElementNamespaceTable_AddNamespace(This,bstrNamespace,bstrUrn,lFlags,pvarFactory)	\
    (This)->lpVtbl -> AddNamespace(This,bstrNamespace,bstrUrn,lFlags,pvarFactory)
#define IHostBehaviorInit_PopulateNamespaceTable(This)	\
    (This)->lpVtbl -> PopulateNamespaceTable(This)

// public\sdk\inc\msp.h
#define ITMSPAddress_ReceiveTSPData(This,pMSPCall,pBuffer,dwSize)	\
    (This)->lpVtbl -> ReceiveTSPData(This,pMSPCall,pBuffer,dwSize)
#define ITMSPAddress_GetEvent(This,pdwSize,pEventBuffer)	\
    (This)->lpVtbl -> GetEvent(This,pdwSize,pEventBuffer)

// public\sdk\inc\mstask.h
#define IScheduledWorkItem_SetWorkItemData(This,cbData,rgbData)	\
    (This)->lpVtbl -> SetWorkItemData(This,cbData,rgbData)
#define IScheduledWorkItem_GetWorkItemData(This,pcbData,prgbData)	\
    (This)->lpVtbl -> GetWorkItemData(This,pcbData,prgbData)
#define ITask_SetWorkItemData(This,cbData,rgbData)	\
    (This)->lpVtbl -> SetWorkItemData(This,cbData,rgbData)
#define ITask_GetWorkItemData(This,pcbData,prgbData)	\
    (This)->lpVtbl -> GetWorkItemData(This,pcbData,prgbData)

// public\sdk\inc\mstime.h
#define ITIMEElement_get_syncBehavior(This,sync)	\
    (This)->lpVtbl -> get_syncBehavior(This,sync)
#define ITIMEElement_put_syncBehavior(This,sync)	\
    (This)->lpVtbl -> put_syncBehavior(This,sync)
#define ITIMEBodyElement_get_syncBehavior(This,sync)	\
    (This)->lpVtbl -> get_syncBehavior(This,sync)
#define ITIMEBodyElement_put_syncBehavior(This,sync)	\
    (This)->lpVtbl -> put_syncBehavior(This,sync)
#define ITIMEMediaElement_get_syncBehavior(This,sync)	\
    (This)->lpVtbl -> get_syncBehavior(This,sync)
#define ITIMEMediaElement_put_syncBehavior(This,sync)	\
    (This)->lpVtbl -> put_syncBehavior(This,sync)
#define ITIMEMediaElement2_get_syncBehavior(This,sync)	\
    (This)->lpVtbl -> get_syncBehavior(This,sync)
#define ITIMEMediaElement2_put_syncBehavior(This,sync)	\
    (This)->lpVtbl -> put_syncBehavior(This,sync)
#define ITIMEMediaElement2_get_minBufferedMediaDur(This,minBufferedMediaDur)	\
    (This)->lpVtbl -> get_minBufferedMediaDur(This,minBufferedMediaDur)
#define ITIMEMediaElement2_put_minBufferedMediaDur(This,minBufferedMediaDur)	\
    (This)->lpVtbl -> put_minBufferedMediaDur(This,minBufferedMediaDur)
#define ITIMEMediaElement2_get_bufferingProgress(This,bufferingProgress)	\
    (This)->lpVtbl -> get_bufferingProgress(This,bufferingProgress)
#define ITIMEAnimationElement_get_syncBehavior(This,sync)	\
    (This)->lpVtbl -> get_syncBehavior(This,sync)
#define ITIMEAnimationElement_put_syncBehavior(This,sync)	\
    (This)->lpVtbl -> put_syncBehavior(This,sync)
#define ITIMEAnimationElement2_get_syncBehavior(This,sync)	\
    (This)->lpVtbl -> get_syncBehavior(This,sync)
#define ITIMEAnimationElement2_put_syncBehavior(This,sync)	\
    (This)->lpVtbl -> put_syncBehavior(This,sync)
#define ITIMEMediaPlayerNetwork_get_isBuffered(This,b)	\
    (This)->lpVtbl -> get_isBuffered(This,b)
#define ITIMEMediaPlayerNetwork_get_bufferingProgress(This,l)	\
    (This)->lpVtbl -> get_bufferingProgress(This,l)

// public\sdk\inc\mstvca.h
#define ICARequest_get_ScheduleEntry(This,ppUnkScheduleEntry)	\
    (This)->lpVtbl -> get_ScheduleEntry(This,ppUnkScheduleEntry)
#define ICAResDenialTree_get_DisplayFields(This,penFields)	\
    (This)->lpVtbl -> get_DisplayFields(This,penFields)
#define ICAResDenialTree_put_DisplayFields(This,enFields)	\
    (This)->lpVtbl -> put_DisplayFields(This,enFields)

// public\sdk\inc\mstve.h
#define ITVEVariation_Helper_ParseCBTrigger(This,bstrTrig)	\
    (This)->lpVtbl -> ParseCBTrigger(This,bstrTrig)
#define ITVEService_Helper_ParseCBAnnouncement(This,bstrFileTrigAdapter,pbstrBuff)	\
    (This)->lpVtbl -> ParseCBAnnouncement(This,bstrFileTrigAdapter,pbstrBuff)
#define ITVEFeature_NotifyTVEPackage(This,engPkgMode,pVariation,bstrUUID,cBytesTotal,cBytesReceived)	\
    (This)->lpVtbl -> NotifyTVEPackage(This,engPkgMode,pVariation,bstrUUID,cBytesTotal,cBytesReceived)
#define ITVESupervisor_Helper_UnpackBuffer(This,pTVEVariation,m_rgbData,cBytes)	\
    (This)->lpVtbl -> UnpackBuffer(This,pTVEVariation,m_rgbData,cBytes)
#define ITVESupervisor_Helper_NotifyPackage(This,pkgMode,pVariation,bstrPackageUUID,cBytesTotal,cBytesReceived)	\
    (This)->lpVtbl -> NotifyPackage(This,pkgMode,pVariation,bstrPackageUUID,cBytesTotal,cBytesReceived)
#define ITVESupervisor_Helper_NotifyPackage_XProxy(This,pkgMode,pVariation,bstrPackageUUID,cBytesTotal,cBytesReceived)	\
    (This)->lpVtbl -> NotifyPackage_XProxy(This,pkgMode,pVariation,bstrPackageUUID,cBytesTotal,cBytesReceived)
#define ITVECBAnnc_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITVECBAnnc_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITVECBAnnc_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITVECBAnnc_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ITVECBAnnc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ITVECBAnnc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ITVECBAnnc_Init(This,bstrFileTrigAdapter,pService)	\
    (This)->lpVtbl -> Init(This,bstrFileTrigAdapter,pService)
#define ITVECBTrig_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITVECBTrig_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITVECBTrig_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITVECBTrig_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ITVECBTrig_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ITVECBTrig_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ITVECBTrig_Init(This,pIVariation)	\
    (This)->lpVtbl -> Init(This,pIVariation)
#define ITVECBFile_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITVECBFile_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITVECBFile_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITVECBFile_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ITVECBFile_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ITVECBFile_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ITVECBFile_Init(This,pIVariation,pIService)	\
    (This)->lpVtbl -> Init(This,pIVariation,pIService)
#define ITVECBDummy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITVECBDummy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITVECBDummy_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITVECBDummy_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ITVECBDummy_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ITVECBDummy_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ITVECBDummy_Init(This,i)	\
    (This)->lpVtbl -> Init(This,i)
#define ITVENavAid_NotifyTVEPackage(This,engPkgMode,pVariation,bstrUUID,cBytesTotal,cBytesReceived)	\
    (This)->lpVtbl -> NotifyTVEPackage(This,engPkgMode,pVariation,bstrUUID,cBytesTotal,cBytesReceived)
#define ITVEFilter_ParseCCBytePair(This,lByteType,byte1,byte2)	\
    (This)->lpVtbl -> ParseCCBytePair(This,lByteType,byte1,byte2)

// public\sdk\inc\mswmdm.h
#define IWMDMDeviceControl_Record(This,pFormat)	\
    (This)->lpVtbl -> Record(This,pFormat)
#define IWMDMRevoked_GetRevocationURL(This,ppwszRevocationURL,pdwBufferLen,pdwRevokedBitFlag)	\
    (This)->lpVtbl -> GetRevocationURL(This,ppwszRevocationURL,pdwBufferLen,pdwRevokedBitFlag)
#define IMDSPDeviceControl_Record(This,pFormat)	\
    (This)->lpVtbl -> Record(This,pFormat)

// public\sdk\inc\msxml.h
#define IXMLDOMDocument_createProcessingInstruction(This,target,data,pi)	\
    (This)->lpVtbl -> createProcessingInstruction(This,target,data,pi)
#define IXMLDOMProcessingInstruction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IXMLDOMProcessingInstruction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IXMLDOMProcessingInstruction_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IXMLDOMProcessingInstruction_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IXMLDOMProcessingInstruction_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IXMLDOMProcessingInstruction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IXMLDOMProcessingInstruction_get_nodeName(This,name)	\
    (This)->lpVtbl -> get_nodeName(This,name)
#define IXMLDOMProcessingInstruction_get_nodeValue(This,value)	\
    (This)->lpVtbl -> get_nodeValue(This,value)
#define IXMLDOMProcessingInstruction_put_nodeValue(This,value)	\
    (This)->lpVtbl -> put_nodeValue(This,value)
#define IXMLDOMProcessingInstruction_get_nodeType(This,type)	\
    (This)->lpVtbl -> get_nodeType(This,type)
#define IXMLDOMProcessingInstruction_get_parentNode(This,parent)	\
    (This)->lpVtbl -> get_parentNode(This,parent)
#define IXMLDOMProcessingInstruction_get_firstChild(This,firstChild)	\
    (This)->lpVtbl -> get_firstChild(This,firstChild)
#define IXMLDOMProcessingInstruction_get_lastChild(This,lastChild)	\
    (This)->lpVtbl -> get_lastChild(This,lastChild)
#define IXMLDOMProcessingInstruction_get_attributes(This,attributeMap)	\
    (This)->lpVtbl -> get_attributes(This,attributeMap)
#define IXMLDOMProcessingInstruction_insertBefore(This,newChild,refChild,outNewChild)	\
    (This)->lpVtbl -> insertBefore(This,newChild,refChild,outNewChild)
#define IXMLDOMProcessingInstruction_replaceChild(This,newChild,oldChild,outOldChild)	\
    (This)->lpVtbl -> replaceChild(This,newChild,oldChild,outOldChild)
#define IXMLDOMProcessingInstruction_removeChild(This,childNode,oldChild)	\
    (This)->lpVtbl -> removeChild(This,childNode,oldChild)
#define IXMLDOMProcessingInstruction_appendChild(This,newChild,outNewChild)	\
    (This)->lpVtbl -> appendChild(This,newChild,outNewChild)
#define IXMLDOMProcessingInstruction_hasChildNodes(This,hasChild)	\
    (This)->lpVtbl -> hasChildNodes(This,hasChild)
#define IXMLDOMProcessingInstruction_get_ownerDocument(This,DOMDocument)	\
    (This)->lpVtbl -> get_ownerDocument(This,DOMDocument)
#define IXMLDOMProcessingInstruction_cloneNode(This,deep,cloneRoot)	\
    (This)->lpVtbl -> cloneNode(This,deep,cloneRoot)
#define IXMLDOMProcessingInstruction_get_nodeTypeString(This,nodeType)	\
    (This)->lpVtbl -> get_nodeTypeString(This,nodeType)
#define IXMLDOMProcessingInstruction_get_text(This,text)	\
    (This)->lpVtbl -> get_text(This,text)
#define IXMLDOMProcessingInstruction_put_text(This,text)	\
    (This)->lpVtbl -> put_text(This,text)
#define IXMLDOMProcessingInstruction_get_specified(This,isSpecified)	\
    (This)->lpVtbl -> get_specified(This,isSpecified)
#define IXMLDOMProcessingInstruction_get_definition(This,definitionNode)	\
    (This)->lpVtbl -> get_definition(This,definitionNode)
#define IXMLDOMProcessingInstruction_get_nodeTypedValue(This,typedValue)	\
    (This)->lpVtbl -> get_nodeTypedValue(This,typedValue)
#define IXMLDOMProcessingInstruction_put_nodeTypedValue(This,typedValue)	\
    (This)->lpVtbl -> put_nodeTypedValue(This,typedValue)
#define IXMLDOMProcessingInstruction_get_dataType(This,dataTypeName)	\
    (This)->lpVtbl -> get_dataType(This,dataTypeName)
#define IXMLDOMProcessingInstruction_put_dataType(This,dataTypeName)	\
    (This)->lpVtbl -> put_dataType(This,dataTypeName)
#define IXMLDOMProcessingInstruction_get_xml(This,xmlString)	\
    (This)->lpVtbl -> get_xml(This,xmlString)
#define IXMLDOMProcessingInstruction_transformNode(This,stylesheet,xmlString)	\
    (This)->lpVtbl -> transformNode(This,stylesheet,xmlString)
#define IXMLDOMProcessingInstruction_selectSingleNode(This,queryString,resultNode)	\
    (This)->lpVtbl -> selectSingleNode(This,queryString,resultNode)
#define IXMLDOMProcessingInstruction_get_parsed(This,isParsed)	\
    (This)->lpVtbl -> get_parsed(This,isParsed)
#define IXMLDOMProcessingInstruction_get_namespaceURI(This,namespaceURI)	\
    (This)->lpVtbl -> get_namespaceURI(This,namespaceURI)
#define IXMLDOMProcessingInstruction_get_prefix(This,prefixString)	\
    (This)->lpVtbl -> get_prefix(This,prefixString)
#define IXMLDOMProcessingInstruction_transformNodeToObject(This,stylesheet,outputObject)	\
    (This)->lpVtbl -> transformNodeToObject(This,stylesheet,outputObject)
#define IXMLDOMProcessingInstruction_get_target(This,name)	\
    (This)->lpVtbl -> get_target(This,name)
#define IXMLDOMProcessingInstruction_get_data(This,value)	\
    (This)->lpVtbl -> get_data(This,value)
#define IXMLDOMProcessingInstruction_put_data(This,value)	\
    (This)->lpVtbl -> put_data(This,value)

// public\sdk\inc\msxml2.h
#define IXMLDOMDocument_createProcessingInstruction(This,target,data,pi)	\
    (This)->lpVtbl -> createProcessingInstruction(This,target,data,pi)
#define IXMLDOMDocument2_createProcessingInstruction(This,target,data,pi)	\
    (This)->lpVtbl -> createProcessingInstruction(This,target,data,pi)
#define IXMLDOMProcessingInstruction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IXMLDOMProcessingInstruction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IXMLDOMProcessingInstruction_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IXMLDOMProcessingInstruction_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IXMLDOMProcessingInstruction_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IXMLDOMProcessingInstruction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IXMLDOMProcessingInstruction_get_nodeName(This,name)	\
    (This)->lpVtbl -> get_nodeName(This,name)
#define IXMLDOMProcessingInstruction_get_nodeValue(This,value)	\
    (This)->lpVtbl -> get_nodeValue(This,value)
#define IXMLDOMProcessingInstruction_put_nodeValue(This,value)	\
    (This)->lpVtbl -> put_nodeValue(This,value)
#define IXMLDOMProcessingInstruction_get_nodeType(This,type)	\
    (This)->lpVtbl -> get_nodeType(This,type)
#define IXMLDOMProcessingInstruction_get_parentNode(This,parent)	\
    (This)->lpVtbl -> get_parentNode(This,parent)
#define IXMLDOMProcessingInstruction_get_firstChild(This,firstChild)	\
    (This)->lpVtbl -> get_firstChild(This,firstChild)
#define IXMLDOMProcessingInstruction_get_lastChild(This,lastChild)	\
    (This)->lpVtbl -> get_lastChild(This,lastChild)
#define IXMLDOMProcessingInstruction_get_attributes(This,attributeMap)	\
    (This)->lpVtbl -> get_attributes(This,attributeMap)
#define IXMLDOMProcessingInstruction_insertBefore(This,newChild,refChild,outNewChild)	\
    (This)->lpVtbl -> insertBefore(This,newChild,refChild,outNewChild)
#define IXMLDOMProcessingInstruction_replaceChild(This,newChild,oldChild,outOldChild)	\
    (This)->lpVtbl -> replaceChild(This,newChild,oldChild,outOldChild)
#define IXMLDOMProcessingInstruction_removeChild(This,childNode,oldChild)	\
    (This)->lpVtbl -> removeChild(This,childNode,oldChild)
#define IXMLDOMProcessingInstruction_appendChild(This,newChild,outNewChild)	\
    (This)->lpVtbl -> appendChild(This,newChild,outNewChild)
#define IXMLDOMProcessingInstruction_hasChildNodes(This,hasChild)	\
    (This)->lpVtbl -> hasChildNodes(This,hasChild)
#define IXMLDOMProcessingInstruction_get_ownerDocument(This,DOMDocument)	\
    (This)->lpVtbl -> get_ownerDocument(This,DOMDocument)
#define IXMLDOMProcessingInstruction_cloneNode(This,deep,cloneRoot)	\
    (This)->lpVtbl -> cloneNode(This,deep,cloneRoot)
#define IXMLDOMProcessingInstruction_get_nodeTypeString(This,nodeType)	\
    (This)->lpVtbl -> get_nodeTypeString(This,nodeType)
#define IXMLDOMProcessingInstruction_get_text(This,text)	\
    (This)->lpVtbl -> get_text(This,text)
#define IXMLDOMProcessingInstruction_put_text(This,text)	\
    (This)->lpVtbl -> put_text(This,text)
#define IXMLDOMProcessingInstruction_get_specified(This,isSpecified)	\
    (This)->lpVtbl -> get_specified(This,isSpecified)
#define IXMLDOMProcessingInstruction_get_definition(This,definitionNode)	\
    (This)->lpVtbl -> get_definition(This,definitionNode)
#define IXMLDOMProcessingInstruction_get_nodeTypedValue(This,typedValue)	\
    (This)->lpVtbl -> get_nodeTypedValue(This,typedValue)
#define IXMLDOMProcessingInstruction_put_nodeTypedValue(This,typedValue)	\
    (This)->lpVtbl -> put_nodeTypedValue(This,typedValue)
#define IXMLDOMProcessingInstruction_get_dataType(This,dataTypeName)	\
    (This)->lpVtbl -> get_dataType(This,dataTypeName)
#define IXMLDOMProcessingInstruction_put_dataType(This,dataTypeName)	\
    (This)->lpVtbl -> put_dataType(This,dataTypeName)
#define IXMLDOMProcessingInstruction_get_xml(This,xmlString)	\
    (This)->lpVtbl -> get_xml(This,xmlString)
#define IXMLDOMProcessingInstruction_transformNode(This,stylesheet,xmlString)	\
    (This)->lpVtbl -> transformNode(This,stylesheet,xmlString)
#define IXMLDOMProcessingInstruction_selectSingleNode(This,queryString,resultNode)	\
    (This)->lpVtbl -> selectSingleNode(This,queryString,resultNode)
#define IXMLDOMProcessingInstruction_get_parsed(This,isParsed)	\
    (This)->lpVtbl -> get_parsed(This,isParsed)
#define IXMLDOMProcessingInstruction_get_namespaceURI(This,namespaceURI)	\
    (This)->lpVtbl -> get_namespaceURI(This,namespaceURI)
#define IXMLDOMProcessingInstruction_get_prefix(This,prefixString)	\
    (This)->lpVtbl -> get_prefix(This,prefixString)
#define IXMLDOMProcessingInstruction_transformNodeToObject(This,stylesheet,outputObject)	\
    (This)->lpVtbl -> transformNodeToObject(This,stylesheet,outputObject)
#define IXMLDOMProcessingInstruction_get_target(This,name)	\
    (This)->lpVtbl -> get_target(This,name)
#define IXMLDOMProcessingInstruction_get_data(This,value)	\
    (This)->lpVtbl -> get_data(This,value)
#define IXMLDOMProcessingInstruction_put_data(This,value)	\
    (This)->lpVtbl -> put_data(This,value)
#define ISAXContentHandler_processingInstruction(This,pwchTarget,cchTarget,pwchData,cchData)	\
    (This)->lpVtbl -> processingInstruction(This,pwchTarget,cchTarget,pwchData,cchData)
#define IVBSAXContentHandler_processingInstruction(This,strTarget,strData)	\
    (This)->lpVtbl -> processingInstruction(This,strTarget,strData)

// public\sdk\inc\netcfgx.h
#define INetCfgComponentBindings_MoveBefore(This,pncbItemSrc,pncbItemDest)	\
    (This)->lpVtbl -> MoveBefore(This,pncbItemSrc,pncbItemDest)
#define INetCfgComponentBindings_MoveAfter(This,pncbItemSrc,pncbItemDest)	\
    (This)->lpVtbl -> MoveAfter(This,pncbItemSrc,pncbItemDest)
#define INetCfgSysPrep_HrSetupSetFirstMultiSzField(This,pwszSection,pwszKey,pmszValue)	\
    (This)->lpVtbl -> HrSetupSetFirstMultiSzField(This,pwszSection,pwszKey,pmszValue)

// public\sdk\inc\netmon.h
#define IDelaydC_QueryStations(This,lpQueryTable)	\
    (This)->lpVtbl -> QueryStations(This,lpQueryTable)
#define IESP_QueryStations(This,lpQueryTable)	\
    (This)->lpVtbl -> QueryStations(This,lpQueryTable)
#define IRTC_QueryStations(This,lpQueryTable)	\
    (This)->lpVtbl -> QueryStations(This,lpQueryTable)
#define IStats_QueryStations(This,lpQueryTable)	\
    (This)->lpVtbl -> QueryStations(This,lpQueryTable)

// public\sdk\inc\ntddft2.h
#define FT_CREATE_LOGICAL_DISK                      CTL_CODE(FTCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FT_BREAK_LOGICAL_DISK                       CTL_CODE(FTCONTROLTYPE, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FT_INITIALIZE_LOGICAL_DISK                  CTL_CODE(FTCONTROLTYPE, 7, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FT_SET_DRIVE_LETTER_FOR_LOGICAL_DISK        CTL_CODE(FTCONTROLTYPE, 10, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FT_STOP_SYNC_OPERATIONS                     CTL_CODE(FTCONTROLTYPE, 14, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FT_CREATE_PARTITION_LOGICAL_DISK            CTL_CODE(FTCONTROLTYPE, 101, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\sdk\inc\ntdsbmsg.h
#define hrLogBufferTooSmall              ((HRESULT)0xC8000205L)
#define hrBufferTruncated                ((HRESULT)0x880003EEL)
#define hrOutOfBuffers                   ((HRESULT)0xC80003F6L)
#define hrRecordDeleted                  ((HRESULT)0xC80003F9L)
#define hrRecordTooBig                   ((HRESULT)0xC8000402L)
#define hrBufferTooSmall                 ((HRESULT)0xC800040EL)
#define hrInvalidBufferSize              ((HRESULT)0xC8000417L)
#define hrColumnNotUpdatable             ((HRESULT)0xC8000418L)
#define hrTableEmpty                     ((HRESULT)0x88000515L)
#define hrTableLocked                    ((HRESULT)0xC8000516L)
#define hrTableDuplicate                 ((HRESULT)0xC8000517L)
#define hrTableInUse                     ((HRESULT)0xC8000518L)
#define hrTableNotEmpty                  ((HRESULT)0xC800051CL)
#define hrInvalidTableId                 ((HRESULT)0xC800051EL)
#define hrTooManyOpenTables              ((HRESULT)0xC800051FL)
#define hrRecordNotFound                 ((HRESULT)0xC8000641L)
#define hrNoCurrentRecord                ((HRESULT)0xC8000643L)
#define hrRecordClusteredChanged         ((HRESULT)0xC8000644L)

// public\sdk\inc\ntexapi.h
#define BOOT_ENTRY_ATTRIBUTE_VALID_BITS (  \
            BOOT_ENTRY_ATTRIBUTE_ACTIVE  | \
            BOOT_ENTRY_ATTRIBUTE_DEFAULT   \
            )

// public\sdk\inc\ntimage.h
#define ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_TAG || (x)==IMAGE_SYM_CLASS_UNION_TAG || (x)==IMAGE_SYM_CLASS_ENUM_TAG)

// public\sdk\inc\ntioapi.h
#define FSCTL_SET_COMPRESSION           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 16, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_GET_VOLUME_BITMAP         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 27,  METHOD_NEITHER, FILE_ANY_ACCESS) // STARTING_LCN_INPUT_BUFFER, VOLUME_BITMAP_BUFFER
#define FSCTL_WRITE_USN_CLOSE_RECORD    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 59,  METHOD_NEITHER, FILE_ANY_ACCESS) // Generate Close Usn Record
#define FSCTL_SIS_LINK_FILES            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 65, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_HSM_MSG                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 66, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)

// public\sdk\inc\ntrtl.h
#define RtlInitEmptyUnicodeString(_ucStr,_buf,_bufSize) \
    ((_ucStr)->Buffer = (_buf), \
     (_ucStr)->Length = 0, \
     (_ucStr)->MaximumLength = (USHORT)(_bufSize))
#define RtlCheckBit(BMH,BP) ((((BMH)->Buffer[(BP) / 32]) >> ((BP) % 32)) & 0x1)

// public\sdk\inc\ntrtlstringandbuffer.h
#define RTL_STRING_IS_NUL_TERMINATED(s)    (RTL_STRING_IS_PUT_AT_SAFE(s, RTL_STRING_GET_LENGTH_CHARS(s), 0) \
                                           && RTL_STRING_GET_AT_UNSAFE(s, RTL_STRING_GET_LENGTH_CHARS(s)) == 0)
#define RTL_STRING_NUL_TERMINATE(s)        ((VOID)(ASSERT(RTL_STRING_IS_PUT_AT_SAFE(s, RTL_STRING_GET_LENGTH_CHARS(s), 0)), \
                                           ((s)->Buffer[RTL_STRING_GET_LENGTH_CHARS(s)] = 0)))
#define RTL_STRING_GET_AT(s,n)         (ASSERT(RTL_STRING_IS_GET_AT_SAFE(s,n)), \
                                       RTL_STRING_GET_AT_UNSAFE(s,n))
#define RTL_STRING_PUT_AT(s,n,c)       (ASSERT(RTL_STRING_IS_PUT_AT_SAFE(s,n,c)), \
                                       RTL_STRING_PUT_AT_UNSAFE(s,n,c))
#define RtlInitBuffer(Buff, StatBuff, StatSize) \
    STATUS_SUCCESS;                             \
    do {                                        \
        (Buff)->Buffer       = (StatBuff);      \
        (Buff)->Size         = (StatSize);      \
        (Buff)->StaticBuffer = (StatBuff);      \
        (Buff)->StaticSize   = (StatSize);      \
    } while (0)
#define RtlEnsureBufferSize(Flags, Buff, NewSizeBytes) \
    (   ((Buff) != NULL && (NewSizeBytes) <= (Buff)->Size) \
        ? STATUS_SUCCESS \
        : RtlpEnsureBufferSize((Flags), (Buff), (NewSizeBytes)) \
    )
#define RtlFreeBuffer(Buff)                              \
    do {                                                 \
        if ((Buff) != NULL && (Buff)->Buffer != NULL) {  \
            if (RTLP_BUFFER_IS_HEAP_ALLOCATED(Buff)) {   \
                UNICODE_STRING UnicodeString;            \
                UnicodeString.Buffer = (PWSTR)(PVOID)(Buff)->Buffer; \
                RtlFreeUnicodeString(&UnicodeString);    \
            }                                            \
            (Buff)->Buffer = (Buff)->StaticBuffer;       \
            (Buff)->Size = (Buff)->StaticSize;           \
        }                                                \
    } while (0)
#define RtlSyncStringToBuffer(x)                                            \
    (                                                                       \
      ( ASSERT((x)->String.Length < (x)->ByteBuffer.Size)                ), \
      ( ASSERT((x)->String.MaximumLength >= (x)->String.Length)          ), \
      ( ASSERT((x)->String.MaximumLength <= (x)->ByteBuffer.Size)        ), \
      ( (x)->String.Buffer        = (PWSTR)(x)->ByteBuffer.Buffer        ), \
      ( (x)->String.MaximumLength = (RTL_STRING_LENGTH_TYPE)((x)->ByteBuffer.Size) ), \
      ( ASSERT(RTL_STRING_IS_NUL_TERMINATED(&(x)->String))               ), \
      ( STATUS_SUCCESS                                                   )  \
    )
#define RtlSyncBufferToString(Buff_)                                         \
    (                                                                        \
      ( (Buff_)->ByteBuffer.Buffer        = (Buff_)->String.Buffer        ), \
      ( (Buff_)->ByteBuffer.Buffer.Size   = (Buff_)->String.MaximumLength ), \
      ( STATUS_SUCCESS )                                                     \
    )
#define RtlFreeUnicodeStringBuffer(Buff)      \
    do {                                      \
        if ((Buff) != NULL) {                 \
            RtlFreeBuffer(&(Buff)->ByteBuffer);   \
            (Buff)->String.Buffer = (PWSTR)(Buff)->ByteBuffer.StaticBuffer; \
            if ((Buff)->String.Buffer != NULL) \
                (Buff)->String.Buffer[0] = 0;  \
            (Buff)->String.Length = 0;         \
            (Buff)->String.MaximumLength = (RTL_STRING_LENGTH_TYPE)(Buff)->ByteBuffer.StaticSize; \
        } \
    } while (0)
#define RtlAssignUnicodeStringBuffer(Buff, Str) \
    (((Buff)->String.Length = 0), (RtlAppendUnicodeStringBuffer((Buff), (Str))))
#define RtlTakeRemainingStaticBuffer(Buff, OutBuff, OutSize)  \
    (((Buff)->Buffer != (Buff)->StaticBuffer)                 \
    ? ( /* take the whole thing */                            \
        ( *(OutBuff) = (Buff)->StaticBuffer ),                \
        ( *(OutSize) = (Buff)->StaticSize   ),                \
        /* leave the buffer with nothing */                   \
        ( (Buff)->StaticBuffer = NULL       ),                \
        ( (Buff)->StaticSize = 0            ),                \
        ( STATUS_SUCCESS                    )                 \
      )                                                       \
    : ( /* only take what isn't being used */                 \
        ( *(OutBuff) = &(Buff)->StaticBuffer[(Buff)->Size] ), \
        ( *(OutSize) = ((Buff)->StaticSize - (Buff)->Size) ), \
        /* leave the buffer with just what it is using */     \
        ( (Buff)->StaticSize = (Buff)->Size                ), \
        ( STATUS_SUCCESS                                   )  \
      ))
#define RtlUnicodeStringBufferTakeValue(Status, Flags, DestinationBuffer, SourceBuffer) \
    ( \
      ((Flags) != 0) \
    ? (*(Status) = STATUS_INVALID_PARAMETER) \
    : (!NT_SUCCESS(*(Status) = RtlBufferTakeValue(0, &(DestinationBuffer)->ByteBuffer, &(SourceBuffer)->ByteBuffer))) \
    ? (*(Status)) \
    : (*(Status) = RtlSyncStringToBuffer(DestinationBuffer), RtlSyncStringToBuffer(SourceBuffer)) \
    )

// public\sdk\inc\ntstatus.h
#define STATUS_FAILED_DRIVER_ENTRY       ((NTSTATUS)0xC0000365L)

// public\sdk\inc\nturtl.h
#define PRTL_READ_STREAM2(T, Name)           HRESULT (STDMETHODCALLTYPE* Name)(T* This, VOID* pv, ULONG cb, ULONG* pcbRead)
#define PRTL_WRITE_STREAM2(T, Name)          HRESULT (STDMETHODCALLTYPE* Name)(T* This, const VOID* pv, ULONG cb, ULONG* pcbWritten)
#define PRTL_COPY_STREAM_TO2(T, Name)        HRESULT (STDMETHODCALLTYPE* Name)(T* This, IStream* pstm, ULARGE_INTEGER cb, ULARGE_INTEGER* pcbRead, ULARGE_INTEGER* pcbWritten)
#define RTL_STREAM_VTABLE_TEMPLATE(T)               \
struct                                              \
{                                                   \
    PRTL_QUERYINTERFACE_STREAM2(T, QueryInterface); \
    PRTL_ADDREF_STREAM2(T,         AddRef);         \
    PRTL_RELEASE_STREAM2(T,        Release);        \
    PRTL_READ_STREAM2(T,           Read);           \
    PRTL_WRITE_STREAM2(T,          Write);          \
    PRTL_SEEK_STREAM2(T,           Seek);           \
    PRTL_SET_STREAM_SIZE2(T,       SetSize);        \
    PRTL_COPY_STREAM_TO2(T,        CopyTo);         \
    PRTL_COMMIT_STREAM2(T,         Commit);         \
    PRTL_REVERT_STREAM2(T,         Revert);         \
    PRTL_LOCK_STREAM_REGION2(T,    LockRegion);     \
    PRTL_UNLOCK_STREAM_REGION2(T,  UnlockRegion);   \
    PRTL_STAT_STREAM2(T,           Stat);           \
    PRTL_CLONE_STREAM2(T,          Clone);          \
}

// public\sdk\inc\oaidl.h
#define ICreateTypeInfo_DefineFuncAsDllEntry(This,index,szDllName,szProcName)	\
    (This)->lpVtbl -> DefineFuncAsDllEntry(This,index,szDllName,szProcName)
#define ICreateTypeInfo2_DefineFuncAsDllEntry(This,index,szDllName,szProcName)	\
    (This)->lpVtbl -> DefineFuncAsDllEntry(This,index,szDllName,szProcName)
#define ICreateTypeInfo2_DeleteFuncDescByMemId(This,memid,invKind)	\
    (This)->lpVtbl -> DeleteFuncDescByMemId(This,memid,invKind)
#define ICreateTypeInfo2_DeleteVarDescByMemId(This,memid)	\
    (This)->lpVtbl -> DeleteVarDescByMemId(This,memid)
#define ITypeInfo_GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal)	\
    (This)->lpVtbl -> GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal)
#define ITypeInfo2_GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal)	\
    (This)->lpVtbl -> GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal)
#define ITypeMarshal_Marshal(This,pvType,dwDestContext,pvDestContext,cbBufferLength,pBuffer,pcbWritten)	\
    (This)->lpVtbl -> Marshal(This,pvType,dwDestContext,pvDestContext,cbBufferLength,pBuffer,pcbWritten)
#define ITypeMarshal_Unmarshal(This,pvType,dwFlags,cbBufferLength,pBuffer,pcbRead)	\
    (This)->lpVtbl -> Unmarshal(This,pvType,dwFlags,cbBufferLength,pBuffer,pcbRead)
#define IRecordInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRecordInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRecordInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRecordInfo_RecordInit(This,pvNew)	\
    (This)->lpVtbl -> RecordInit(This,pvNew)
#define IRecordInfo_RecordClear(This,pvExisting)	\
    (This)->lpVtbl -> RecordClear(This,pvExisting)
#define IRecordInfo_RecordCopy(This,pvExisting,pvNew)	\
    (This)->lpVtbl -> RecordCopy(This,pvExisting,pvNew)
#define IRecordInfo_GetGuid(This,pguid)	\
    (This)->lpVtbl -> GetGuid(This,pguid)
#define IRecordInfo_GetName(This,pbstrName)	\
    (This)->lpVtbl -> GetName(This,pbstrName)
#define IRecordInfo_GetSize(This,pcbSize)	\
    (This)->lpVtbl -> GetSize(This,pcbSize)
#define IRecordInfo_GetTypeInfo(This,ppTypeInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,ppTypeInfo)
#define IRecordInfo_GetField(This,pvData,szFieldName,pvarField)	\
    (This)->lpVtbl -> GetField(This,pvData,szFieldName,pvarField)
#define IRecordInfo_PutField(This,wFlags,pvData,szFieldName,pvarField)	\
    (This)->lpVtbl -> PutField(This,wFlags,pvData,szFieldName,pvarField)
#define IRecordInfo_PutFieldNoCopy(This,wFlags,pvData,szFieldName,pvarField)	\
    (This)->lpVtbl -> PutFieldNoCopy(This,wFlags,pvData,szFieldName,pvarField)
#define IRecordInfo_GetFieldNames(This,pcNames,rgBstrNames)	\
    (This)->lpVtbl -> GetFieldNames(This,pcNames,rgBstrNames)
#define IRecordInfo_IsMatchingType(This,pRecordInfo)	\
    (This)->lpVtbl -> IsMatchingType(This,pRecordInfo)
#define IRecordInfo_RecordCreate(This)	\
    (This)->lpVtbl -> RecordCreate(This)
#define IRecordInfo_RecordCreateCopy(This,pvSource,ppvDest)	\
    (This)->lpVtbl -> RecordCreateCopy(This,pvSource,ppvDest)
#define IRecordInfo_RecordDestroy(This,pvRecord)	\
    (This)->lpVtbl -> RecordDestroy(This,pvRecord)

// public\sdk\inc\objidl.h
#define IMalloc_Alloc(This,cb)	\
    (This)->lpVtbl -> Alloc(This,cb)
#define IMalloc_Realloc(This,pv,cb)	\
    (This)->lpVtbl -> Realloc(This,pv,cb)
#define IMallocSpy_PreAlloc(This,cbRequest)	\
    (This)->lpVtbl -> PreAlloc(This,cbRequest)
#define IMallocSpy_PreRealloc(This,pRequest,cbRequest,ppNewRequest,fSpyed)	\
    (This)->lpVtbl -> PreRealloc(This,pRequest,cbRequest,ppNewRequest,fSpyed)
#define IMallocSpy_PostGetSize(This,cbActual,fSpyed)	\
    (This)->lpVtbl -> PostGetSize(This,cbActual,fSpyed)
#define IBindCtx_GetRunningObjectTable(This,pprot)	\
    (This)->lpVtbl -> GetRunningObjectTable(This,pprot)
#define IRunningObjectTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRunningObjectTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRunningObjectTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRunningObjectTable_Register(This,grfFlags,punkObject,pmkObjectName,pdwRegister)	\
    (This)->lpVtbl -> Register(This,grfFlags,punkObject,pmkObjectName,pdwRegister)
#define IRunningObjectTable_Revoke(This,dwRegister)	\
    (This)->lpVtbl -> Revoke(This,dwRegister)
#define IRunningObjectTable_IsRunning(This,pmkObjectName)	\
    (This)->lpVtbl -> IsRunning(This,pmkObjectName)
#define IRunningObjectTable_GetObject(This,pmkObjectName,ppunkObject)	\
    (This)->lpVtbl -> GetObject(This,pmkObjectName,ppunkObject)
#define IRunningObjectTable_NoteChangeTime(This,dwRegister,pfiletime)	\
    (This)->lpVtbl -> NoteChangeTime(This,dwRegister,pfiletime)
#define IRunningObjectTable_GetTimeOfLastChange(This,pmkObjectName,pfiletime)	\
    (This)->lpVtbl -> GetTimeOfLastChange(This,pmkObjectName,pfiletime)
#define IRunningObjectTable_EnumRunning(This,ppenumMoniker)	\
    (This)->lpVtbl -> EnumRunning(This,ppenumMoniker)
#define IPersistStream_GetSizeMax(This,pcbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pcbSize)
#define IMoniker_GetSizeMax(This,pcbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pcbSize)
#define IROTData_GetComparisonData(This,pbData,cbMax,pcbData)	\
    (This)->lpVtbl -> GetComparisonData(This,pbData,cbMax,pcbData)
#define ISequentialStream_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISequentialStream_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define IStream_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define IStream_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define IStream_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define ILockBytes_SetSize(This,cb)	\
    (This)->lpVtbl -> SetSize(This,cb)
#define IRpcChannelBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRpcChannelBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRpcChannelBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRpcChannelBuffer_GetBuffer(This,pMessage,riid)	\
    (This)->lpVtbl -> GetBuffer(This,pMessage,riid)
#define IRpcChannelBuffer_SendReceive(This,pMessage,pStatus)	\
    (This)->lpVtbl -> SendReceive(This,pMessage,pStatus)
#define IRpcChannelBuffer_FreeBuffer(This,pMessage)	\
    (This)->lpVtbl -> FreeBuffer(This,pMessage)
#define IRpcChannelBuffer_GetDestCtx(This,pdwDestContext,ppvDestContext)	\
    (This)->lpVtbl -> GetDestCtx(This,pdwDestContext,ppvDestContext)
#define IRpcChannelBuffer_IsConnected(This)	\
    (This)->lpVtbl -> IsConnected(This)
#define IRpcChannelBuffer2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRpcChannelBuffer2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRpcChannelBuffer2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRpcChannelBuffer2_GetBuffer(This,pMessage,riid)	\
    (This)->lpVtbl -> GetBuffer(This,pMessage,riid)
#define IRpcChannelBuffer2_SendReceive(This,pMessage,pStatus)	\
    (This)->lpVtbl -> SendReceive(This,pMessage,pStatus)
#define IRpcChannelBuffer2_FreeBuffer(This,pMessage)	\
    (This)->lpVtbl -> FreeBuffer(This,pMessage)
#define IRpcChannelBuffer2_GetDestCtx(This,pdwDestContext,ppvDestContext)	\
    (This)->lpVtbl -> GetDestCtx(This,pdwDestContext,ppvDestContext)
#define IRpcChannelBuffer2_IsConnected(This)	\
    (This)->lpVtbl -> IsConnected(This)
#define IRpcChannelBuffer2_GetProtocolVersion(This,pdwVersion)	\
    (This)->lpVtbl -> GetProtocolVersion(This,pdwVersion)
#define IAsyncRpcChannelBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IAsyncRpcChannelBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IAsyncRpcChannelBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IAsyncRpcChannelBuffer_GetBuffer(This,pMessage,riid)	\
    (This)->lpVtbl -> GetBuffer(This,pMessage,riid)
#define IAsyncRpcChannelBuffer_SendReceive(This,pMessage,pStatus)	\
    (This)->lpVtbl -> SendReceive(This,pMessage,pStatus)
#define IAsyncRpcChannelBuffer_FreeBuffer(This,pMessage)	\
    (This)->lpVtbl -> FreeBuffer(This,pMessage)
#define IAsyncRpcChannelBuffer_GetDestCtx(This,pdwDestContext,ppvDestContext)	\
    (This)->lpVtbl -> GetDestCtx(This,pdwDestContext,ppvDestContext)
#define IAsyncRpcChannelBuffer_IsConnected(This)	\
    (This)->lpVtbl -> IsConnected(This)
#define IAsyncRpcChannelBuffer_GetProtocolVersion(This,pdwVersion)	\
    (This)->lpVtbl -> GetProtocolVersion(This,pdwVersion)
#define IAsyncRpcChannelBuffer_Send(This,pMsg,pSync,pulStatus)	\
    (This)->lpVtbl -> Send(This,pMsg,pSync,pulStatus)
#define IAsyncRpcChannelBuffer_Receive(This,pMsg,pulStatus)	\
    (This)->lpVtbl -> Receive(This,pMsg,pulStatus)
#define IAsyncRpcChannelBuffer_GetDestCtxEx(This,pMsg,pdwDestContext,ppvDestContext)	\
    (This)->lpVtbl -> GetDestCtxEx(This,pMsg,pdwDestContext,ppvDestContext)
#define IRpcChannelBuffer3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRpcChannelBuffer3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRpcChannelBuffer3_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRpcChannelBuffer3_GetBuffer(This,pMessage,riid)	\
    (This)->lpVtbl -> GetBuffer(This,pMessage,riid)
#define IRpcChannelBuffer3_SendReceive(This,pMessage,pStatus)	\
    (This)->lpVtbl -> SendReceive(This,pMessage,pStatus)
#define IRpcChannelBuffer3_FreeBuffer(This,pMessage)	\
    (This)->lpVtbl -> FreeBuffer(This,pMessage)
#define IRpcChannelBuffer3_GetDestCtx(This,pdwDestContext,ppvDestContext)	\
    (This)->lpVtbl -> GetDestCtx(This,pdwDestContext,ppvDestContext)
#define IRpcChannelBuffer3_IsConnected(This)	\
    (This)->lpVtbl -> IsConnected(This)
#define IRpcChannelBuffer3_GetProtocolVersion(This,pdwVersion)	\
    (This)->lpVtbl -> GetProtocolVersion(This,pdwVersion)
#define IRpcChannelBuffer3_Send(This,pMsg,pulStatus)	\
    (This)->lpVtbl -> Send(This,pMsg,pulStatus)
#define IRpcChannelBuffer3_Receive(This,pMsg,ulSize,pulStatus)	\
    (This)->lpVtbl -> Receive(This,pMsg,ulSize,pulStatus)
#define IRpcChannelBuffer3_Cancel(This,pMsg)	\
    (This)->lpVtbl -> Cancel(This,pMsg)
#define IRpcChannelBuffer3_GetCallContext(This,pMsg,riid,pInterface)	\
    (This)->lpVtbl -> GetCallContext(This,pMsg,riid,pInterface)
#define IRpcChannelBuffer3_GetDestCtxEx(This,pMsg,pdwDestContext,ppvDestContext)	\
    (This)->lpVtbl -> GetDestCtxEx(This,pMsg,pdwDestContext,ppvDestContext)
#define IRpcChannelBuffer3_GetState(This,pMsg,pState)	\
    (This)->lpVtbl -> GetState(This,pMsg,pState)
#define IRpcChannelBuffer3_RegisterAsync(This,pMsg,pAsyncMgr)	\
    (This)->lpVtbl -> RegisterAsync(This,pMsg,pAsyncMgr)
#define IRpcProxyBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRpcProxyBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRpcProxyBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRpcProxyBuffer_Connect(This,pRpcChannelBuffer)	\
    (This)->lpVtbl -> Connect(This,pRpcChannelBuffer)
#define IRpcProxyBuffer_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)
#define IRpcStubBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRpcStubBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRpcStubBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRpcStubBuffer_Connect(This,pUnkServer)	\
    (This)->lpVtbl -> Connect(This,pUnkServer)
#define IRpcStubBuffer_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)
#define IRpcStubBuffer_Invoke(This,_prpcmsg,_pRpcChannelBuffer)	\
    (This)->lpVtbl -> Invoke(This,_prpcmsg,_pRpcChannelBuffer)
#define IRpcStubBuffer_IsIIDSupported(This,riid)	\
    (This)->lpVtbl -> IsIIDSupported(This,riid)
#define IRpcStubBuffer_CountRefs(This)	\
    (This)->lpVtbl -> CountRefs(This)
#define IRpcStubBuffer_DebugServerQueryInterface(This,ppv)	\
    (This)->lpVtbl -> DebugServerQueryInterface(This,ppv)
#define IRpcStubBuffer_DebugServerRelease(This,pv)	\
    (This)->lpVtbl -> DebugServerRelease(This,pv)
#define IPSFactoryBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IPSFactoryBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IPSFactoryBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IPSFactoryBuffer_CreateProxy(This,pUnkOuter,riid,ppProxy,ppv)	\
    (This)->lpVtbl -> CreateProxy(This,pUnkOuter,riid,ppProxy,ppv)
#define IPSFactoryBuffer_CreateStub(This,riid,pUnkServer,ppStub)	\
    (This)->lpVtbl -> CreateStub(This,riid,pUnkServer,ppStub)
#define IChannelHook_ClientFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer)	\
    (This)->lpVtbl -> ClientFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer)
#define IChannelHook_ClientNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep,hrFault)	\
    (This)->lpVtbl -> ClientNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep,hrFault)
#define IChannelHook_ServerNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep)	\
    (This)->lpVtbl -> ServerNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep)
#define IChannelHook_ServerFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer,hrFault)	\
    (This)->lpVtbl -> ServerFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer,hrFault)
#define IFillLockBytes_FillAppend(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> FillAppend(This,pv,cb,pcbWritten)
#define IGlobalInterfaceTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IGlobalInterfaceTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IGlobalInterfaceTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IGlobalInterfaceTable_RegisterInterfaceInGlobal(This,pUnk,riid,pdwCookie)	\
    (This)->lpVtbl -> RegisterInterfaceInGlobal(This,pUnk,riid,pdwCookie)
#define IGlobalInterfaceTable_RevokeInterfaceFromGlobal(This,dwCookie)	\
    (This)->lpVtbl -> RevokeInterfaceFromGlobal(This,dwCookie)
#define IGlobalInterfaceTable_GetInterfaceFromGlobal(This,dwCookie,riid,ppv)	\
    (This)->lpVtbl -> GetInterfaceFromGlobal(This,dwCookie,riid,ppv)
#define IReleaseMarshalBuffers_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IReleaseMarshalBuffers_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IReleaseMarshalBuffers_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IReleaseMarshalBuffers_ReleaseMarshalBuffer(This,pMsg,dwFlags,pChnl)	\
    (This)->lpVtbl -> ReleaseMarshalBuffer(This,pMsg,dwFlags,pChnl)

// public\sdk\inc\ocidl.h
#define IPersistMemory_Load(This,pMem,cbSize)	\
    (This)->lpVtbl -> Load(This,pMem,cbSize)
#define IPersistMemory_Save(This,pMem,fClearDirty,cbSize)	\
    (This)->lpVtbl -> Save(This,pMem,fClearDirty,cbSize)
#define IPersistMemory_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)
#define IPersistStreamInit_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)
#define IPicture_SaveAsFile(This,pStream,fSaveMemCopy,pCbSize)	\
    (This)->lpVtbl -> SaveAsFile(This,pStream,fSaveMemCopy,pCbSize)
#define IViewObjectEx_Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)	\
    (This)->lpVtbl -> Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)

// public\sdk\inc\oledb.h
#define PMDAXISINFO_GETAT(rgAxisInfo, iAxis) ((MDAXISINFO *)(((BYTE *)(rgAxisInfo)) +((iAxis) * (rgAxisInfo)[0].cbSize)))
#define IAccessor_CreateAccessor(This,dwAccessorFlags,cBindings,rgBindings,cbRowSize,phAccessor,rgStatus)	\
    (This)->lpVtbl -> CreateAccessor(This,dwAccessorFlags,cBindings,rgBindings,cbRowSize,phAccessor,rgStatus)
#define IAccessor_GetBindings(This,hAccessor,pdwAccessorFlags,pcBindings,prgBindings)	\
    (This)->lpVtbl -> GetBindings(This,hAccessor,pdwAccessorFlags,pcBindings,prgBindings)
#define IRowsetLocate_Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)	\
    (This)->lpVtbl -> Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)
#define IRowsetLocate_GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)	\
    (This)->lpVtbl -> GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)
#define IRowsetLocate_Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)	\
    (This)->lpVtbl -> Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)
#define IRowsetScroll_Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)	\
    (This)->lpVtbl -> Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)
#define IRowsetScroll_GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)	\
    (This)->lpVtbl -> GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)
#define IRowsetScroll_Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)	\
    (This)->lpVtbl -> Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)
#define IRowsetScroll_GetApproximatePosition(This,hReserved,cbBookmark,pBookmark,pulPosition,pcRows)	\
    (This)->lpVtbl -> GetApproximatePosition(This,hReserved,cbBookmark,pBookmark,pulPosition,pcRows)
#define IViewFilter_GetFilterBindings(This,pcBindings,prgBindings)	\
    (This)->lpVtbl -> GetFilterBindings(This,pcBindings,prgBindings)
#define IRowsetExactScroll_Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)	\
    (This)->lpVtbl -> Compare(This,hReserved,cbBookmark1,pBookmark1,cbBookmark2,pBookmark2,pComparison)
#define IRowsetExactScroll_GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)	\
    (This)->lpVtbl -> GetRowsByBookmark(This,hReserved,cRows,rgcbBookmarks,rgpBookmarks,rghRows,rgRowStatus)
#define IRowsetExactScroll_Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)	\
    (This)->lpVtbl -> Hash(This,hReserved,cBookmarks,rgcbBookmarks,rgpBookmarks,rgHashedValues,rgBookmarkStatus)
#define IRowsetExactScroll_GetApproximatePosition(This,hReserved,cbBookmark,pBookmark,pulPosition,pcRows)	\
    (This)->lpVtbl -> GetApproximatePosition(This,hReserved,cbBookmark,pBookmark,pulPosition,pcRows)
#define IRowsetExactScroll_GetExactPosition(This,hChapter,cbBookmark,pBookmark,pulPosition,pcRows)	\
    (This)->lpVtbl -> GetExactPosition(This,hChapter,cbBookmark,pBookmark,pulPosition,pcRows)
#define IRowsetNotify_OnFieldChange(This,pRowset,hRow,cColumns,rgColumns,eReason,ePhase,fCantDeny)	\
    (This)->lpVtbl -> OnFieldChange(This,pRowset,hRow,cColumns,rgColumns,eReason,ePhase,fCantDeny)
#define ICommandWithParameters_GetParameterInfo(This,pcParams,prgParamInfo,ppNamesBuffer)	\
    (This)->lpVtbl -> GetParameterInfo(This,pcParams,prgParamInfo,ppNamesBuffer)
#define IColumnsInfo_GetColumnInfo(This,pcColumns,prgInfo,ppStringsBuffer)	\
    (This)->lpVtbl -> GetColumnInfo(This,pcColumns,prgInfo,ppStringsBuffer)
#define IDBProperties_GetPropertyInfo(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)	\
    (This)->lpVtbl -> GetPropertyInfo(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)
#define IDBInfo_GetLiteralInfo(This,cLiterals,rgLiterals,pcLiteralInfo,prgLiteralInfo,ppCharBuffer)	\
    (This)->lpVtbl -> GetLiteralInfo(This,cLiterals,rgLiterals,pcLiteralInfo,prgLiteralInfo,ppCharBuffer)
#define IDBDataSourceAdmin_GetCreationProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)	\
    (This)->lpVtbl -> GetCreationProperties(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)
#define IIndexDefinition_CreateIndex(This,pTableID,pIndexID,cIndexColumnDescs,rgIndexColumnDescs,cPropertySets,rgPropertySets,ppIndexID)	\
    (This)->lpVtbl -> CreateIndex(This,pTableID,pIndexID,cIndexColumnDescs,rgIndexColumnDescs,cPropertySets,rgPropertySets,ppIndexID)
#define IIndexDefinition_DropIndex(This,pTableID,pIndexID)	\
    (This)->lpVtbl -> DropIndex(This,pTableID,pIndexID)
#define ITableDefinition_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITableDefinition_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITableDefinition_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITableDefinition_CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)	\
    (This)->lpVtbl -> CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)
#define ITableDefinition_DropTable(This,pTableID)	\
    (This)->lpVtbl -> DropTable(This,pTableID)
#define ITableDefinition_AddColumn(This,pTableID,pColumnDesc,ppColumnID)	\
    (This)->lpVtbl -> AddColumn(This,pTableID,pColumnDesc,ppColumnID)
#define ITableDefinition_DropColumn(This,pTableID,pColumnID)	\
    (This)->lpVtbl -> DropColumn(This,pTableID,pColumnID)
#define IOpenRowset_OpenRowset(This,pUnkOuter,pTableID,pIndexID,riid,cPropertySets,rgPropertySets,ppRowset)	\
    (This)->lpVtbl -> OpenRowset(This,pUnkOuter,pTableID,pIndexID,riid,cPropertySets,rgPropertySets,ppRowset)
#define IAlterTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IAlterTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IAlterTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IAlterTable_AlterColumn(This,pTableId,pColumnId,dwColumnDescFlags,pColumnDesc)	\
    (This)->lpVtbl -> AlterColumn(This,pTableId,pColumnId,dwColumnDescFlags,pColumnDesc)
#define IAlterTable_AlterTable(This,pTableId,pNewTableId,cPropertySets,rgPropertySets)	\
    (This)->lpVtbl -> AlterTable(This,pTableId,pNewTableId,cPropertySets,rgPropertySets)
#define IAlterIndex_AlterIndex(This,pTableId,pIndexId,pNewIndexId,cPropertySets,rgPropertySets)	\
    (This)->lpVtbl -> AlterIndex(This,pTableId,pIndexId,pNewIndexId,cPropertySets,rgPropertySets)
#define IErrorRecords_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IErrorRecords_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IErrorRecords_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IErrorRecords_AddErrorRecord(This,pErrorInfo,dwLookupID,pdispparams,punkCustomError,dwDynamicErrorID)	\
    (This)->lpVtbl -> AddErrorRecord(This,pErrorInfo,dwLookupID,pdispparams,punkCustomError,dwDynamicErrorID)
#define IErrorRecords_GetBasicErrorInfo(This,ulRecordNum,pErrorInfo)	\
    (This)->lpVtbl -> GetBasicErrorInfo(This,ulRecordNum,pErrorInfo)
#define IErrorRecords_GetCustomErrorObject(This,ulRecordNum,riid,ppObject)	\
    (This)->lpVtbl -> GetCustomErrorObject(This,ulRecordNum,riid,ppObject)
#define IErrorRecords_GetErrorInfo(This,ulRecordNum,lcid,ppErrorInfo)	\
    (This)->lpVtbl -> GetErrorInfo(This,ulRecordNum,lcid,ppErrorInfo)
#define IErrorRecords_GetErrorParameters(This,ulRecordNum,pdispparams)	\
    (This)->lpVtbl -> GetErrorParameters(This,ulRecordNum,pdispparams)
#define IErrorRecords_GetRecordCount(This,pcRecords)	\
    (This)->lpVtbl -> GetRecordCount(This,pcRecords)
#define IObjectAccessControl_IsObjectAccessAllowed(This,pObject,pAccessEntry,pfResult)	\
    (This)->lpVtbl -> IsObjectAccessAllowed(This,pObject,pAccessEntry,pfResult)
#define ITableCreation_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITableCreation_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITableCreation_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITableCreation_CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)	\
    (This)->lpVtbl -> CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)
#define ITableCreation_DropTable(This,pTableID)	\
    (This)->lpVtbl -> DropTable(This,pTableID)
#define ITableCreation_AddColumn(This,pTableID,pColumnDesc,ppColumnID)	\
    (This)->lpVtbl -> AddColumn(This,pTableID,pColumnDesc,ppColumnID)
#define ITableCreation_DropColumn(This,pTableID,pColumnID)	\
    (This)->lpVtbl -> DropColumn(This,pTableID,pColumnID)
#define ITableCreation_GetTableDefinition(This,pTableID,pcColumnDescs,prgColumnDescs,pcPropertySets,prgPropertySets,pcConstraintDescs,prgConstraintDescs,ppwszStringBuffer)	\
    (This)->lpVtbl -> GetTableDefinition(This,pTableID,pcColumnDescs,prgColumnDescs,pcPropertySets,prgPropertySets,pcConstraintDescs,prgConstraintDescs,ppwszStringBuffer)
#define ITableDefinitionWithConstraints_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITableDefinitionWithConstraints_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITableDefinitionWithConstraints_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITableDefinitionWithConstraints_CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)	\
    (This)->lpVtbl -> CreateTable(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)
#define ITableDefinitionWithConstraints_DropTable(This,pTableID)	\
    (This)->lpVtbl -> DropTable(This,pTableID)
#define ITableDefinitionWithConstraints_AddColumn(This,pTableID,pColumnDesc,ppColumnID)	\
    (This)->lpVtbl -> AddColumn(This,pTableID,pColumnDesc,ppColumnID)
#define ITableDefinitionWithConstraints_DropColumn(This,pTableID,pColumnID)	\
    (This)->lpVtbl -> DropColumn(This,pTableID,pColumnID)
#define ITableDefinitionWithConstraints_GetTableDefinition(This,pTableID,pcColumnDescs,prgColumnDescs,pcPropertySets,prgPropertySets,pcConstraintDescs,prgConstraintDescs,ppwszStringBuffer)	\
    (This)->lpVtbl -> GetTableDefinition(This,pTableID,pcColumnDescs,prgColumnDescs,pcPropertySets,prgPropertySets,pcConstraintDescs,prgConstraintDescs,ppwszStringBuffer)
#define ITableDefinitionWithConstraints_AddConstraint(This,pTableID,pConstraintDesc)	\
    (This)->lpVtbl -> AddConstraint(This,pTableID,pConstraintDesc)
#define ITableDefinitionWithConstraints_CreateTableWithConstraints(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,cConstraintDescs,rgConstraintDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)	\
    (This)->lpVtbl -> CreateTableWithConstraints(This,pUnkOuter,pTableID,cColumnDescs,rgColumnDescs,cConstraintDescs,rgConstraintDescs,riid,cPropertySets,rgPropertySets,ppTableID,ppRowset)
#define ITableDefinitionWithConstraints_DropConstraint(This,pTableID,pConstraintID)	\
    (This)->lpVtbl -> DropConstraint(This,pTableID,pConstraintID)
#define IScopedOperations_Copy(This,cRows,rgpwszSourceURLs,rgpwszDestURLs,dwCopyFlags,pAuthenticate,rgdwStatus,rgpwszNewURLs,ppStringsBuffer)	\
    (This)->lpVtbl -> Copy(This,cRows,rgpwszSourceURLs,rgpwszDestURLs,dwCopyFlags,pAuthenticate,rgdwStatus,rgpwszNewURLs,ppStringsBuffer)
#define IScopedOperations_Move(This,cRows,rgpwszSourceURLs,rgpwszDestURLs,dwMoveFlags,pAuthenticate,rgdwStatus,rgpwszNewURLs,ppStringsBuffer)	\
    (This)->lpVtbl -> Move(This,cRows,rgpwszSourceURLs,rgpwszDestURLs,dwMoveFlags,pAuthenticate,rgdwStatus,rgpwszNewURLs,ppStringsBuffer)
#define IScopedOperations_OpenRowset(This,pUnkOuter,pTableID,pIndexID,riid,cPropertySets,rgPropertySets,ppRowset)	\
    (This)->lpVtbl -> OpenRowset(This,pUnkOuter,pTableID,pIndexID,riid,cPropertySets,rgPropertySets,ppRowset)
#define IDBBinderProperties_GetPropertyInfo(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)	\
    (This)->lpVtbl -> GetPropertyInfo(This,cPropertyIDSets,rgPropertyIDSets,pcPropertyInfoSets,prgPropertyInfoSets,ppDescBuffer)
#define IColumnsInfo2_GetColumnInfo(This,pcColumns,prgInfo,ppStringsBuffer)	\
    (This)->lpVtbl -> GetColumnInfo(This,pcColumns,prgInfo,ppStringsBuffer)
#define IColumnsInfo2_GetRestrictedColumnInfo(This,cColumnIDMasks,rgColumnIDMasks,dwFlags,pcColumns,prgColumnIDs,prgColumnInfo,ppStringsBuffer)	\
    (This)->lpVtbl -> GetRestrictedColumnInfo(This,cColumnIDMasks,rgColumnIDMasks,dwFlags,pcColumns,prgColumnIDs,prgColumnInfo,ppStringsBuffer)
#define IRowsetBookmark_PositionOnBookmark(This,hChapter,cbBookmark,pBookmark)	\
    (This)->lpVtbl -> PositionOnBookmark(This,hChapter,cbBookmark,pBookmark)

// public\sdk\inc\oledbdep.h
#define IRowsetWithParameters_GetParameterInfo(This,pcParams,prgParamInfo,ppNamesBuffer)	\
    (This)->lpVtbl -> GetParameterInfo(This,pcParams,prgParamInfo,ppNamesBuffer)
#define IRowsetWatchRegion_GetWatchRegionInfo(This,hRegion,pdwWatchMode,phChapter,pcbBookmark,ppBookmark,pcRows)	\
    (This)->lpVtbl -> GetWatchRegionInfo(This,hRegion,pdwWatchMode,phChapter,pcbBookmark,ppBookmark,pcRows)
#define IRowsetWatchRegion_ShrinkWatchRegion(This,hRegion,hChapter,cbBookmark,pBookmark,cRows)	\
    (This)->lpVtbl -> ShrinkWatchRegion(This,hRegion,hChapter,cbBookmark,pBookmark,cRows)
#define ITableRename_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITableRename_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITableRename_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITableRename_RenameColumn(This,pTableId,pOldColumnId,pNewColumnId)	\
    (This)->lpVtbl -> RenameColumn(This,pTableId,pOldColumnId,pNewColumnId)
#define ITableRename_RenameTable(This,pOldTableId,pOldIndexId,pNewTableId,pNewIndexId)	\
    (This)->lpVtbl -> RenameTable(This,pOldTableId,pOldIndexId,pNewTableId,pNewIndexId)

// public\sdk\inc\oledberr.h
#define DB_E_NOTABLE                     ((HRESULT)0x80040E37L)
#define DB_E_BADTABLEID                  ((HRESULT)0x80040E3CL)
#define DB_E_DUPLICATETABLEID            ((HRESULT)0x80040E3FL)
#define DB_E_TABLEINUSE                  ((HRESULT)0x80040E40L)
#define DB_E_BADRECORDNUM                ((HRESULT)0x80040E42L)
#define SEC_E_INVALIDACCESSENTRY         ((HRESULT)0x80040E71L)
#define DB_S_BUFFERFULL                  ((HRESULT)0x00040EC8L)
#define DB_S_GOALCHANGED                 ((HRESULT)0x00040ECBL)

// public\sdk\inc\oleidl.h
#define IOleInPlaceActiveObject_ResizeBorder(This,prcBorder,pUIWindow,fFrameWindow)	\
    (This)->lpVtbl -> ResizeBorder(This,prcBorder,pUIWindow,fFrameWindow)
#define IViewObject_Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)	\
    (This)->lpVtbl -> Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)
#define IViewObject2_Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)	\
    (This)->lpVtbl -> Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)

// public\sdk\inc\omscript.h
#define IHTMLStyle2_put_tableLayout(This,v)	\
    (This)->lpVtbl -> put_tableLayout(This,v)
#define IHTMLStyle2_get_tableLayout(This,p)	\
    (This)->lpVtbl -> get_tableLayout(This,p)
#define IHTMLRuleStyle2_put_tableLayout(This,v)	\
    (This)->lpVtbl -> put_tableLayout(This,v)
#define IHTMLRuleStyle2_get_tableLayout(This,p)	\
    (This)->lpVtbl -> get_tableLayout(This,p)
#define IHTMLCurrentStyle_get_tableLayout(This,p)	\
    (This)->lpVtbl -> get_tableLayout(This,p)
#define IHTMLElement_get_recordNumber(This,p)	\
    (This)->lpVtbl -> get_recordNumber(This,p)
#define IHTMLElement3_put_contentEditable(This,v)	\
    (This)->lpVtbl -> put_contentEditable(This,v)
#define IHTMLElement3_get_contentEditable(This,p)	\
    (This)->lpVtbl -> get_contentEditable(This,p)
#define IHTMLElement3_get_isContentEditable(This,p)	\
    (This)->lpVtbl -> get_isContentEditable(This,p)
#define IHTMLElementDefaults_put_contentEditable(This,v)	\
    (This)->lpVtbl -> put_contentEditable(This,v)
#define IHTMLElementDefaults_get_contentEditable(This,p)	\
    (This)->lpVtbl -> get_contentEditable(This,p)
#define IHTCDescBehavior_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTCDescBehavior_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTCDescBehavior_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTCDescBehavior_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTCDescBehavior_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTCDescBehavior_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTCDescBehavior_get_urn(This,p)	\
    (This)->lpVtbl -> get_urn(This,p)
#define IHTCDescBehavior_get_name(This,p)	\
    (This)->lpVtbl -> get_name(This,p)
#define DispHTCDescBehavior_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTCDescBehavior_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTCDescBehavior_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTCDescBehavior_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTCDescBehavior_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTCDescBehavior_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLGenericElement_get_recordset(This,p)	\
    (This)->lpVtbl -> get_recordset(This,p)
#define IHTMLEventObj2_putref_recordset(This,v)	\
    (This)->lpVtbl -> putref_recordset(This,v)
#define IHTMLEventObj2_get_recordset(This,p)	\
    (This)->lpVtbl -> get_recordset(This,p)
#define IHTMLWindow2_put_offscreenBuffering(This,v)	\
    (This)->lpVtbl -> put_offscreenBuffering(This,v)
#define IHTMLWindow2_get_offscreenBuffering(This,p)	\
    (This)->lpVtbl -> get_offscreenBuffering(This,p)
#define IHTMLScreen_put_bufferDepth(This,v)	\
    (This)->lpVtbl -> put_bufferDepth(This,v)
#define IHTMLScreen_get_bufferDepth(This,p)	\
    (This)->lpVtbl -> get_bufferDepth(This,p)
#define IWBScriptControl_put_selectableContent(This,v)	\
    (This)->lpVtbl -> put_selectableContent(This,v)
#define IWBScriptControl_get_selectableContent(This,p)	\
    (This)->lpVtbl -> get_selectableContent(This,p)
#define IHTMLTableCaption_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableCaption_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableCaption_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableCaption_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableCaption_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableCaption_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLTableCaption_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTableCaption_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTableCaption_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTableCaption_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTableCaption_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTableCaption_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define HTMLTableEvents2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define HTMLTableEvents2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define HTMLTableEvents2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define HTMLTableEvents2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define HTMLTableEvents2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define HTMLTableEvents2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define HTMLTableEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define HTMLTableEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define HTMLTableEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define HTMLTableEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define HTMLTableEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define HTMLTableEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableSection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableSection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableSection_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableSection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableSection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableSection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableSection_put_bgColor(This,v)	\
    (This)->lpVtbl -> put_bgColor(This,v)
#define IHTMLTableSection_get_bgColor(This,p)	\
    (This)->lpVtbl -> get_bgColor(This,p)
#define IHTMLTableSection_get_rows(This,p)	\
    (This)->lpVtbl -> get_rows(This,p)
#define IHTMLTableSection_insertRow(This,index,row)	\
    (This)->lpVtbl -> insertRow(This,index,row)
#define IHTMLTableSection_deleteRow(This,index)	\
    (This)->lpVtbl -> deleteRow(This,index)
#define IHTMLTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTable_put_cols(This,v)	\
    (This)->lpVtbl -> put_cols(This,v)
#define IHTMLTable_get_cols(This,p)	\
    (This)->lpVtbl -> get_cols(This,p)
#define IHTMLTable_put_border(This,v)	\
    (This)->lpVtbl -> put_border(This,v)
#define IHTMLTable_get_border(This,p)	\
    (This)->lpVtbl -> get_border(This,p)
#define IHTMLTable_put_frame(This,v)	\
    (This)->lpVtbl -> put_frame(This,v)
#define IHTMLTable_get_frame(This,p)	\
    (This)->lpVtbl -> get_frame(This,p)
#define IHTMLTable_put_rules(This,v)	\
    (This)->lpVtbl -> put_rules(This,v)
#define IHTMLTable_get_rules(This,p)	\
    (This)->lpVtbl -> get_rules(This,p)
#define IHTMLTable_put_cellSpacing(This,v)	\
    (This)->lpVtbl -> put_cellSpacing(This,v)
#define IHTMLTable_get_cellSpacing(This,p)	\
    (This)->lpVtbl -> get_cellSpacing(This,p)
#define IHTMLTable_put_cellPadding(This,v)	\
    (This)->lpVtbl -> put_cellPadding(This,v)
#define IHTMLTable_get_cellPadding(This,p)	\
    (This)->lpVtbl -> get_cellPadding(This,p)
#define IHTMLTable_put_bgColor(This,v)	\
    (This)->lpVtbl -> put_bgColor(This,v)
#define IHTMLTable_get_bgColor(This,p)	\
    (This)->lpVtbl -> get_bgColor(This,p)
#define IHTMLTable_put_borderColor(This,v)	\
    (This)->lpVtbl -> put_borderColor(This,v)
#define IHTMLTable_get_borderColor(This,p)	\
    (This)->lpVtbl -> get_borderColor(This,p)
#define IHTMLTable_put_borderColorLight(This,v)	\
    (This)->lpVtbl -> put_borderColorLight(This,v)
#define IHTMLTable_get_borderColorLight(This,p)	\
    (This)->lpVtbl -> get_borderColorLight(This,p)
#define IHTMLTable_put_borderColorDark(This,v)	\
    (This)->lpVtbl -> put_borderColorDark(This,v)
#define IHTMLTable_get_borderColorDark(This,p)	\
    (This)->lpVtbl -> get_borderColorDark(This,p)
#define IHTMLTable_refresh(This)	\
    (This)->lpVtbl -> refresh(This)
#define IHTMLTable_get_rows(This,p)	\
    (This)->lpVtbl -> get_rows(This,p)
#define IHTMLTable_put_width(This,v)	\
    (This)->lpVtbl -> put_width(This,v)
#define IHTMLTable_get_width(This,p)	\
    (This)->lpVtbl -> get_width(This,p)
#define IHTMLTable_put_height(This,v)	\
    (This)->lpVtbl -> put_height(This,v)
#define IHTMLTable_get_height(This,p)	\
    (This)->lpVtbl -> get_height(This,p)
#define IHTMLTable_get_tHead(This,p)	\
    (This)->lpVtbl -> get_tHead(This,p)
#define IHTMLTable_get_tFoot(This,p)	\
    (This)->lpVtbl -> get_tFoot(This,p)
#define IHTMLTable_get_tBodies(This,p)	\
    (This)->lpVtbl -> get_tBodies(This,p)
#define IHTMLTable_get_caption(This,p)	\
    (This)->lpVtbl -> get_caption(This,p)
#define IHTMLTable_createTHead(This,head)	\
    (This)->lpVtbl -> createTHead(This,head)
#define IHTMLTable_deleteTHead(This)	\
    (This)->lpVtbl -> deleteTHead(This)
#define IHTMLTable_createTFoot(This,foot)	\
    (This)->lpVtbl -> createTFoot(This,foot)
#define IHTMLTable_deleteTFoot(This)	\
    (This)->lpVtbl -> deleteTFoot(This)
#define IHTMLTable_createCaption(This,caption)	\
    (This)->lpVtbl -> createCaption(This,caption)
#define IHTMLTable_deleteCaption(This)	\
    (This)->lpVtbl -> deleteCaption(This)
#define IHTMLTable_insertRow(This,index,row)	\
    (This)->lpVtbl -> insertRow(This,index,row)
#define IHTMLTable_deleteRow(This,index)	\
    (This)->lpVtbl -> deleteRow(This,index)
#define IHTMLTable_get_readyState(This,p)	\
    (This)->lpVtbl -> get_readyState(This,p)
#define IHTMLTable_put_onreadystatechange(This,v)	\
    (This)->lpVtbl -> put_onreadystatechange(This,v)
#define IHTMLTable_get_onreadystatechange(This,p)	\
    (This)->lpVtbl -> get_onreadystatechange(This,p)
#define IHTMLTable2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTable2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTable2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTable2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTable2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTable2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTable2_get_cells(This,p)	\
    (This)->lpVtbl -> get_cells(This,p)
#define IHTMLTable2_moveRow(This,indexFrom,indexTo,row)	\
    (This)->lpVtbl -> moveRow(This,indexFrom,indexTo,row)
#define IHTMLTable3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTable3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTable3_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTable3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTable3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTable3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTable3_put_summary(This,v)	\
    (This)->lpVtbl -> put_summary(This,v)
#define IHTMLTable3_get_summary(This,p)	\
    (This)->lpVtbl -> get_summary(This,p)
#define IHTMLTableCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableCol_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableCol_put_span(This,v)	\
    (This)->lpVtbl -> put_span(This,v)
#define IHTMLTableCol_get_span(This,p)	\
    (This)->lpVtbl -> get_span(This,p)
#define IHTMLTableCol_put_width(This,v)	\
    (This)->lpVtbl -> put_width(This,v)
#define IHTMLTableCol_get_width(This,p)	\
    (This)->lpVtbl -> get_width(This,p)
#define IHTMLTableCol2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableCol2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableCol2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableCol2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableCol2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableCol2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableCol2_put_ch(This,v)	\
    (This)->lpVtbl -> put_ch(This,v)
#define IHTMLTableCol2_get_ch(This,p)	\
    (This)->lpVtbl -> get_ch(This,p)
#define IHTMLTableCol2_put_chOff(This,v)	\
    (This)->lpVtbl -> put_chOff(This,v)
#define IHTMLTableCol2_get_chOff(This,p)	\
    (This)->lpVtbl -> get_chOff(This,p)
#define IHTMLTableSection2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableSection2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableSection2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableSection2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableSection2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableSection2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableSection2_moveRow(This,indexFrom,indexTo,row)	\
    (This)->lpVtbl -> moveRow(This,indexFrom,indexTo,row)
#define IHTMLTableSection3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableSection3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableSection3_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableSection3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableSection3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableSection3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableSection3_put_ch(This,v)	\
    (This)->lpVtbl -> put_ch(This,v)
#define IHTMLTableSection3_get_ch(This,p)	\
    (This)->lpVtbl -> get_ch(This,p)
#define IHTMLTableSection3_put_chOff(This,v)	\
    (This)->lpVtbl -> put_chOff(This,v)
#define IHTMLTableSection3_get_chOff(This,p)	\
    (This)->lpVtbl -> get_chOff(This,p)
#define IHTMLTableRow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableRow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableRow_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableRow_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableRow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableRow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableRow_put_bgColor(This,v)	\
    (This)->lpVtbl -> put_bgColor(This,v)
#define IHTMLTableRow_get_bgColor(This,p)	\
    (This)->lpVtbl -> get_bgColor(This,p)
#define IHTMLTableRow_put_borderColor(This,v)	\
    (This)->lpVtbl -> put_borderColor(This,v)
#define IHTMLTableRow_get_borderColor(This,p)	\
    (This)->lpVtbl -> get_borderColor(This,p)
#define IHTMLTableRow_put_borderColorLight(This,v)	\
    (This)->lpVtbl -> put_borderColorLight(This,v)
#define IHTMLTableRow_get_borderColorLight(This,p)	\
    (This)->lpVtbl -> get_borderColorLight(This,p)
#define IHTMLTableRow_put_borderColorDark(This,v)	\
    (This)->lpVtbl -> put_borderColorDark(This,v)
#define IHTMLTableRow_get_borderColorDark(This,p)	\
    (This)->lpVtbl -> get_borderColorDark(This,p)
#define IHTMLTableRow_get_rowIndex(This,p)	\
    (This)->lpVtbl -> get_rowIndex(This,p)
#define IHTMLTableRow_get_sectionRowIndex(This,p)	\
    (This)->lpVtbl -> get_sectionRowIndex(This,p)
#define IHTMLTableRow_get_cells(This,p)	\
    (This)->lpVtbl -> get_cells(This,p)
#define IHTMLTableRow_insertCell(This,index,row)	\
    (This)->lpVtbl -> insertCell(This,index,row)
#define IHTMLTableRow_deleteCell(This,index)	\
    (This)->lpVtbl -> deleteCell(This,index)
#define IHTMLTableRow2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableRow2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableRow2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableRow2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableRow2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableRow2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableRow2_put_height(This,v)	\
    (This)->lpVtbl -> put_height(This,v)
#define IHTMLTableRow2_get_height(This,p)	\
    (This)->lpVtbl -> get_height(This,p)
#define IHTMLTableRow3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableRow3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableRow3_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableRow3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableRow3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableRow3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableRow3_put_ch(This,v)	\
    (This)->lpVtbl -> put_ch(This,v)
#define IHTMLTableRow3_get_ch(This,p)	\
    (This)->lpVtbl -> get_ch(This,p)
#define IHTMLTableRow3_put_chOff(This,v)	\
    (This)->lpVtbl -> put_chOff(This,v)
#define IHTMLTableRow3_get_chOff(This,p)	\
    (This)->lpVtbl -> get_chOff(This,p)
#define IHTMLTableRowMetrics_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableRowMetrics_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableRowMetrics_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableRowMetrics_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableRowMetrics_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableRowMetrics_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableRowMetrics_get_clientHeight(This,p)	\
    (This)->lpVtbl -> get_clientHeight(This,p)
#define IHTMLTableRowMetrics_get_clientWidth(This,p)	\
    (This)->lpVtbl -> get_clientWidth(This,p)
#define IHTMLTableRowMetrics_get_clientTop(This,p)	\
    (This)->lpVtbl -> get_clientTop(This,p)
#define IHTMLTableRowMetrics_get_clientLeft(This,p)	\
    (This)->lpVtbl -> get_clientLeft(This,p)
#define IHTMLTableCell_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableCell_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableCell_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableCell_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableCell_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableCell_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableCell_put_rowSpan(This,v)	\
    (This)->lpVtbl -> put_rowSpan(This,v)
#define IHTMLTableCell_get_rowSpan(This,p)	\
    (This)->lpVtbl -> get_rowSpan(This,p)
#define IHTMLTableCell_put_colSpan(This,v)	\
    (This)->lpVtbl -> put_colSpan(This,v)
#define IHTMLTableCell_get_colSpan(This,p)	\
    (This)->lpVtbl -> get_colSpan(This,p)
#define IHTMLTableCell_put_bgColor(This,v)	\
    (This)->lpVtbl -> put_bgColor(This,v)
#define IHTMLTableCell_get_bgColor(This,p)	\
    (This)->lpVtbl -> get_bgColor(This,p)
#define IHTMLTableCell_put_noWrap(This,v)	\
    (This)->lpVtbl -> put_noWrap(This,v)
#define IHTMLTableCell_get_noWrap(This,p)	\
    (This)->lpVtbl -> get_noWrap(This,p)
#define IHTMLTableCell_put_borderColor(This,v)	\
    (This)->lpVtbl -> put_borderColor(This,v)
#define IHTMLTableCell_get_borderColor(This,p)	\
    (This)->lpVtbl -> get_borderColor(This,p)
#define IHTMLTableCell_put_borderColorLight(This,v)	\
    (This)->lpVtbl -> put_borderColorLight(This,v)
#define IHTMLTableCell_get_borderColorLight(This,p)	\
    (This)->lpVtbl -> get_borderColorLight(This,p)
#define IHTMLTableCell_put_borderColorDark(This,v)	\
    (This)->lpVtbl -> put_borderColorDark(This,v)
#define IHTMLTableCell_get_borderColorDark(This,p)	\
    (This)->lpVtbl -> get_borderColorDark(This,p)
#define IHTMLTableCell_put_width(This,v)	\
    (This)->lpVtbl -> put_width(This,v)
#define IHTMLTableCell_get_width(This,p)	\
    (This)->lpVtbl -> get_width(This,p)
#define IHTMLTableCell_put_height(This,v)	\
    (This)->lpVtbl -> put_height(This,v)
#define IHTMLTableCell_get_height(This,p)	\
    (This)->lpVtbl -> get_height(This,p)
#define IHTMLTableCell_get_cellIndex(This,p)	\
    (This)->lpVtbl -> get_cellIndex(This,p)
#define IHTMLTableCell2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLTableCell2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLTableCell2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLTableCell2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLTableCell2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLTableCell2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLTableCell2_put_abbr(This,v)	\
    (This)->lpVtbl -> put_abbr(This,v)
#define IHTMLTableCell2_get_abbr(This,p)	\
    (This)->lpVtbl -> get_abbr(This,p)
#define IHTMLTableCell2_put_axis(This,v)	\
    (This)->lpVtbl -> put_axis(This,v)
#define IHTMLTableCell2_get_axis(This,p)	\
    (This)->lpVtbl -> get_axis(This,p)
#define IHTMLTableCell2_put_ch(This,v)	\
    (This)->lpVtbl -> put_ch(This,v)
#define IHTMLTableCell2_get_ch(This,p)	\
    (This)->lpVtbl -> get_ch(This,p)
#define IHTMLTableCell2_put_chOff(This,v)	\
    (This)->lpVtbl -> put_chOff(This,v)
#define IHTMLTableCell2_get_chOff(This,p)	\
    (This)->lpVtbl -> get_chOff(This,p)
#define IHTMLTableCell2_put_headers(This,v)	\
    (This)->lpVtbl -> put_headers(This,v)
#define IHTMLTableCell2_get_headers(This,p)	\
    (This)->lpVtbl -> get_headers(This,p)
#define IHTMLTableCell2_put_scope(This,v)	\
    (This)->lpVtbl -> put_scope(This,v)
#define IHTMLTableCell2_get_scope(This,p)	\
    (This)->lpVtbl -> get_scope(This,p)
#define DispHTMLTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLTableCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTableCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTableCol_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTableCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTableCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTableCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLTableSection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTableSection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTableSection_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTableSection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTableSection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTableSection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLTableRow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTableRow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTableRow_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTableRow_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTableRow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTableRow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DispHTMLTableCell_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLTableCell_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLTableCell_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLTableCell_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLTableCell_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLTableCell_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLObjectElement_putref_recordset(This,v)	\
    (This)->lpVtbl -> putref_recordset(This,v)
#define IHTMLObjectElement_get_recordset(This,p)	\
    (This)->lpVtbl -> get_recordset(This,p)
#define IHTMLFieldSetElement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLFieldSetElement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLFieldSetElement_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLFieldSetElement_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLFieldSetElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLFieldSetElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLFieldSetElement2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IHTMLFieldSetElement2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IHTMLFieldSetElement2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IHTMLFieldSetElement2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IHTMLFieldSetElement2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IHTMLFieldSetElement2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLFieldSetElement2_get_form(This,p)	\
    (This)->lpVtbl -> get_form(This,p)
#define DispHTMLFieldSetElement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define DispHTMLFieldSetElement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define DispHTMLFieldSetElement_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define DispHTMLFieldSetElement_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define DispHTMLFieldSetElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DispHTMLFieldSetElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IHTMLChangePlayback_ExecChange(This,pbRecord,fForward)	\
    (This)->lpVtbl -> ExecChange(This,pbRecord,fForward)
#define IHTMLPainter_Draw(This,rcBounds,rcUpdate,lDrawFlags,hdc,pvDrawObject)	\
    (This)->lpVtbl -> Draw(This,rcBounds,rcUpdate,lDrawFlags,hdc,pvDrawObject)
#define IEnumPrivacyRecords_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumPrivacyRecords_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumPrivacyRecords_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumPrivacyRecords_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumPrivacyRecords_GetSize(This,pSize)	\
    (This)->lpVtbl -> GetSize(This,pSize)
#define IEnumPrivacyRecords_GetPrivacyImpacted(This,pState)	\
    (This)->lpVtbl -> GetPrivacyImpacted(This,pState)
#define IElementNamespaceTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IElementNamespaceTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IElementNamespaceTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IElementNamespaceTable_AddNamespace(This,bstrNamespace,bstrUrn,lFlags,pvarFactory)	\
    (This)->lpVtbl -> AddNamespace(This,bstrNamespace,bstrUrn,lFlags,pvarFactory)
#define IHostBehaviorInit_PopulateNamespaceTable(This)	\
    (This)->lpVtbl -> PopulateNamespaceTable(This)

// public\sdk\inc\optary.h
#define IHtmlLoadOptions_QueryOption(This,dwOption,pBuffer,pcbBuf)	\
    (This)->lpVtbl -> QueryOption(This,dwOption,pBuffer,pcbBuf)
#define IHtmlLoadOptions_SetOption(This,dwOption,pBuffer,cbBuf)	\
    (This)->lpVtbl -> SetOption(This,dwOption,pBuffer,cbBuf)

// public\sdk\inc\penwin.h
#define MpAlcB(lprc,i)          ((lprc)->rgbfAlc[((i) & 0xff) >> 3])
#define SetAlcBitAnsi(lprc,i)   do {MpAlcB(lprc,i) |= MpIbf(i);} while (0)
#define ResetAlcBitAnsi(lprc,i) do {MpAlcB(lprc,i) &= ~MpIbf(i);} while (0)
#define IsAlcBitAnsi(lprc, i)   ((MpAlcB(lprc,i) & MpIbf(i)) != 0)

// public\sdk\inc\perfsnap.hxx
# define IMPLEMENT_PERFSNAP() \
    unsigned char CPerfInfo::_ProcPerfXfer[CPerfInfo::_cbProcPerfXfer];

// public\sdk\inc\pkgmgr.h
#define IEnumCodeStoreDBEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumCodeStoreDBEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumCodeStoreDBEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumCodeStoreDBEntry_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IEnumCodeStoreDBEntry_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumCodeStoreDBEntry_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)
#define ICodeStoreDBEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ICodeStoreDBEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ICodeStoreDBEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ICodeStoreDBEntry_GetName(This,dwFlags,pbstrName)	\
    (This)->lpVtbl -> GetName(This,dwFlags,pbstrName)
#define ICodeStoreDBEntry_CreateChild(This,pszName,ppEntry)	\
    (This)->lpVtbl -> CreateChild(This,pszName,ppEntry)
#define ICodeStoreDBEntry_RemoveChild(This,pszName,dwFlags)	\
    (This)->lpVtbl -> RemoveChild(This,pszName,dwFlags)
#define ICodeStoreDBEntry_GetChild(This,pszName,ppEntry)	\
    (This)->lpVtbl -> GetChild(This,pszName,ppEntry)
#define ICodeStoreDBEntry_EnumChildren(This,ppEntry)	\
    (This)->lpVtbl -> EnumChildren(This,ppEntry)
#define ICodeStoreDBEntry_GetParent(This,ppParent)	\
    (This)->lpVtbl -> GetParent(This,ppParent)
#define ICodeStoreDBEntry_GetProperty(This,pszName,pvarProperty)	\
    (This)->lpVtbl -> GetProperty(This,pszName,pvarProperty)
#define ICodeStoreDBEntry_SetProperty(This,pszName,pvarProperty)	\
    (This)->lpVtbl -> SetProperty(This,pszName,pvarProperty)
#define ICodeStoreDBEntry_DeleteProperty(This,pszName)	\
    (This)->lpVtbl -> DeleteProperty(This,pszName)
#define ICodeStoreDBEntry_GetDWORDPropertyA(This,pszName,pVal)	\
    (This)->lpVtbl -> GetDWORDPropertyA(This,pszName,pVal)
#define ICodeStoreDBEntry_SetDWORDPropertyA(This,pszName,dwVal)	\
    (This)->lpVtbl -> SetDWORDPropertyA(This,pszName,dwVal)
#define ICodeStoreDBEntry_GetStringPropertyA(This,pszName,pszVal,cbVal)	\
    (This)->lpVtbl -> GetStringPropertyA(This,pszName,pszVal,cbVal)
#define ICodeStoreDBEntry_SetStringPropertyA(This,pszName,pszVal)	\
    (This)->lpVtbl -> SetStringPropertyA(This,pszName,pszVal)
#define ICodeStoreDB_CreateEntry(This,pszName,ppEntry)	\
    (This)->lpVtbl -> CreateEntry(This,pszName,ppEntry)
#define ICodeStoreDB_RemoveEntry(This,pszName,dwFlags)	\
    (This)->lpVtbl -> RemoveEntry(This,pszName,dwFlags)
#define ICodeStoreDB_GetEntry(This,pszName,ppEntry)	\
    (This)->lpVtbl -> GetEntry(This,pszName,ppEntry)
#define ICodeStoreDB_EnumRootEntries(This,ppEntry)	\
    (This)->lpVtbl -> EnumRootEntries(This,ppEntry)
#define IJavaPackage_GetCapabilities(This,ppCapabilities,pcbCapabilities)	\
    (This)->lpVtbl -> GetCapabilities(This,ppCapabilities,pcbCapabilities)
#define IJavaPackage_GetSigner(This,ppSigner,pcbSigner)	\
    (This)->lpVtbl -> GetSigner(This,ppSigner,pcbSigner)
#define IJavaPackage_GetFilePathA(This,pszPath,cbPath)	\
    (This)->lpVtbl -> GetFilePathA(This,pszPath,cbPath)
#define IJavaFile_GetPENativePathA(This,pszPath,cbPath)	\
    (This)->lpVtbl -> GetPENativePathA(This,pszPath,cbPath)

// public\sdk\inc\platform.h
#define PALETTE_ENTRY( r, g, b, f )  { f, b, g, r }
#define PALETTE_ENTRY( r, g, b, f )  { r, g, b, f }

// public\sdk\inc\pstore.h
#define IPStore_GetProvParam(This,dwParam,pcbData,ppbData,dwFlags)  \
    (This)->lpVtbl -> GetProvParam(This,dwParam,pcbData,ppbData,dwFlags)
#define IPStore_SetProvParam(This,dwParam,cbData,pbData,dwFlags)    \
    (This)->lpVtbl -> SetProvParam(This,dwParam,cbData,pbData,dwFlags)
#define IPStore_ReadItem(This,Key,pItemType,pItemSubtype,szItemName,pcbData,ppbData,pPromptInfo,dwFlags)    \
    (This)->lpVtbl -> ReadItem(This,Key,pItemType,pItemSubtype,szItemName,pcbData,ppbData,pPromptInfo,dwFlags)
#define IPStore_WriteItem(This,Key,pItemType,pItemSubtype,szItemName,cbData,pbData,pPromptInfo,dwDefaultConfirmationStyle,dwFlags)  \
    (This)->lpVtbl -> WriteItem(This,Key,pItemType,pItemSubtype,szItemName,cbData,pbData,pPromptInfo,dwDefaultConfirmationStyle,dwFlags)

// public\sdk\inc\qedit.h
#define IPropertySetter_PrintXML(This,pszXML,cbXML,pcbPrinted,indent)	\
    (This)->lpVtbl -> PrintXML(This,pszXML,cbXML,pcbPrinted,indent)
#define IMediaDet_GetBitmapBits(This,StreamTime,pBufferSize,pBuffer,Width,Height)	\
    (This)->lpVtbl -> GetBitmapBits(This,StreamTime,pBufferSize,pBuffer,Width,Height)
#define IFindCompressorCB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IFindCompressorCB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IFindCompressorCB_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IFindCompressorCB_GetCompressor(This,pType,pCompType,ppFilter)	\
    (This)->lpVtbl -> GetCompressor(This,pType,pCompType,ppFilter)
#define ISmartRenderEngine_SetFindCompressorCB(This,pCallback)	\
    (This)->lpVtbl -> SetFindCompressorCB(This,pCallback)
#define IAMTimelineEffectable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IAMTimelineEffectable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IAMTimelineEffectable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IAMTimelineEffectable_EffectInsBefore(This,pFX,priority)	\
    (This)->lpVtbl -> EffectInsBefore(This,pFX,priority)
#define IAMTimelineEffectable_EffectSwapPriorities(This,PriorityA,PriorityB)	\
    (This)->lpVtbl -> EffectSwapPriorities(This,PriorityA,PriorityB)
#define IAMTimelineEffectable_EffectGetCount(This,pCount)	\
    (This)->lpVtbl -> EffectGetCount(This,pCount)
#define IAMTimelineEffectable_GetEffect(This,ppFx,Which)	\
    (This)->lpVtbl -> GetEffect(This,ppFx,Which)
#define IAMTimelineSplittable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IAMTimelineSplittable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IAMTimelineSplittable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IAMTimelineSplittable_SplitAt(This,Time)	\
    (This)->lpVtbl -> SplitAt(This,Time)
#define IAMTimelineSplittable_SplitAt2(This,Time)	\
    (This)->lpVtbl -> SplitAt2(This,Time)
#define IAMTimelineGroup_GetOutputBuffering(This,pnBuffer)	\
    (This)->lpVtbl -> GetOutputBuffering(This,pnBuffer)
#define IAMTimelineGroup_SetOutputBuffering(This,nBuffer)	\
    (This)->lpVtbl -> SetOutputBuffering(This,nBuffer)
#define ISampleGrabberCB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISampleGrabberCB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISampleGrabberCB_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISampleGrabberCB_SampleCB(This,SampleTime,pSample)	\
    (This)->lpVtbl -> SampleCB(This,SampleTime,pSample)
#define ISampleGrabberCB_BufferCB(This,SampleTime,pBuffer,BufferLen)	\
    (This)->lpVtbl -> BufferCB(This,SampleTime,pBuffer,BufferLen)
#define ISampleGrabber_SetBufferSamples(This,BufferThem)	\
    (This)->lpVtbl -> SetBufferSamples(This,BufferThem)
#define ISampleGrabber_GetCurrentBuffer(This,pBufferSize,pBuffer)	\
    (This)->lpVtbl -> GetCurrentBuffer(This,pBufferSize,pBuffer)

// public\sdk\inc\query.h
#define IRowsetQueryStatus_GetStatusEx(This,pdwStatus,pcFilteredDocuments,pcDocumentsToFilter,pdwRatioFinishedDenominator,pdwRatioFinishedNumerator,cbBmk,pBmk,piRowBmk,pcRowsTotal)	\
    (This)->lpVtbl -> GetStatusEx(This,pdwStatus,pcFilteredDocuments,pcDocumentsToFilter,pdwRatioFinishedDenominator,pdwRatioFinishedNumerator,cbBmk,pBmk,piRowBmk,pcRowsTotal)
#define IColumnMapper_EnumPropInfo(This,iEntry,pwcsName,ppPropId,pPropType,puiWidth)	\
    (This)->lpVtbl -> EnumPropInfo(This,iEntry,pwcsName,ppPropId,pPropType,puiWidth)

// public\sdk\inc\resapi.h
#define CLRES_V1_FUNCTION_TABLE( _Name,                     \
                                 _Version,                  \
                                 _Prefix,                   \
                                 _Arbitrate,                \
                                 _Release,                  \
                                 _ResControl,               \
                                 _ResTypeControl            \
                                 )                          \
CLRES_FUNCTION_TABLE _Name = { CLRES_V1_FUNCTION_SIZE,      \
                               _Version,                    \
                               _Prefix##Open,               \
                               _Prefix##Close,              \
                               _Prefix##Online,             \
                               _Prefix##Offline,            \
                               _Prefix##Terminate,          \
                               _Prefix##LooksAlive,         \
                               _Prefix##IsAlive,            \
                               _Arbitrate,                  \
                               _Release,                    \
                               _ResControl,                 \
                               _ResTypeControl }

// public\sdk\inc\richedit.h
#define PFE_TABLE				(PFM_TABLE			 >> 16)	// Inside table row. RE 3.0
#define PFE_TABLEROWDELIMITER	(PFM_TABLEROWDELIMITER>>16)	// Table row start. RE 4.0

// public\sdk\inc\rpcndr.h
#define byte_from_ndr(source, target) \
    { \
    *(target) = *(*(char  *  *)&(source)->Buffer)++; \
    }
#define boolean_from_ndr(source, target) \
    { \
    *(target) = *(*(char  *  *)&(source)->Buffer)++; \
    }
#define small_from_ndr(source, target) \
    { \
    *(target) = *(*(char  *  *)&(source)->Buffer)++; \
    }

// public\sdk\inc\rpcproxy.h
#define DLLCANUNLOADNOW(pFactory)   \
 HRESULT STDAPICALLTYPE DLLCANUNLOADNOW_ENTRY()    \
    {   \
    return NdrDllCanUnloadNow( pFactory );    \
    }
#define CSTDSTUBBUFFERRELEASE(pFactory)   \
ULONG STDMETHODCALLTYPE CStdStubBuffer_Release(IRpcStubBuffer *This) \
    {   \
    return NdrCStdStubBuffer_Release(This,(IPSFactoryBuffer *)pFactory);   \
    }   \
#define CSTDSTUBBUFFER2RELEASE(pFactory)   \
ULONG STDMETHODCALLTYPE CStdStubBuffer2_Release(IRpcStubBuffer *This) \
    {   \
    return NdrCStdStubBuffer2_Release(This,(IPSFactoryBuffer *)pFactory);   \
    }

// public\sdk\inc\rtccore.h
#define IRTCBuddyEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRTCBuddyEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRTCBuddyEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRTCBuddyEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IRTCBuddyEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IRTCBuddyEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IRTCBuddyEvent_get_Buddy(This,ppBuddy)	\
    (This)->lpVtbl -> get_Buddy(This,ppBuddy)
#define IRTCBuddy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IRTCBuddy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IRTCBuddy_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IRTCBuddy_get_PresentityURI(This,pbstrPresentityURI)	\
    (This)->lpVtbl -> get_PresentityURI(This,pbstrPresentityURI)
#define IRTCBuddy_put_PresentityURI(This,bstrPresentityURI)	\
    (This)->lpVtbl -> put_PresentityURI(This,bstrPresentityURI)
#define IRTCBuddy_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)
#define IRTCBuddy_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)
#define IRTCBuddy_get_Data(This,pbstrData)	\
    (This)->lpVtbl -> get_Data(This,pbstrData)
#define IRTCBuddy_put_Data(This,bstrData)	\
    (This)->lpVtbl -> put_Data(This,bstrData)
#define IRTCBuddy_get_Persistent(This,pfPersistent)	\
    (This)->lpVtbl -> get_Persistent(This,pfPersistent)
#define IRTCBuddy_put_Persistent(This,fPersistent)	\
    (This)->lpVtbl -> put_Persistent(This,fPersistent)
#define IRTCBuddy_get_Status(This,penStatus)	\
    (This)->lpVtbl -> get_Status(This,penStatus)
#define IRTCBuddy_get_Notes(This,pbstrNotes)	\
    (This)->lpVtbl -> get_Notes(This,pbstrNotes)

// public\sdk\inc\rtcerr.h
#define RTC_E_STATUS_CLIENT_NOT_ACCEPTABLE ((HRESULT)0x80EF0196L)
#define RTC_E_STATUS_NOT_ACCEPTABLE_HERE ((HRESULT)0x80EF01E8L)
#define RTC_E_STATUS_GLOBAL_NOT_ACCEPTABLE ((HRESULT)0x80EF025EL)

// public\sdk\inc\safepnt.hxx
#define SAFE_WIN32_HANDLE(ShName)                                          \
                                                                           \
class ShName INHERIT_UNWIND_IF_CAIRO                                       \
{                                                                          \
     INLINE_UNWIND(ShName)                                                 \
public:                                                                    \
                                                                           \
inline ShName (HANDLE handle = NULL)                                       \
       : _handle(handle)                                                   \
       {                                                                   \
            END_CONSTRUCTION(ShName)                                       \
       }                                                                   \
                                                                           \
inline ~##ShName ()                                                        \
       {                                                                   \
            if ((_handle != INVALID_HANDLE_VALUE) && (_handle != NULL))    \
            {                                                              \
                 CloseHandle(_handle);                                     \
            }                                                              \
       }                                                                   \
                                                                           \
inline void Transfer(HANDLE *phandle)                                      \
    {                                                                      \
        *phandle = _handle;                                                \
        _handle = NULL;                                                    \
    }                                                                      \
inline void Set(HANDLE h)                                                  \
    {                                                                      \
        if (_handle != INVALID_HANDLE_VALUE && _handle != NULL)            \
        {                                                                  \
             CloseHandle(_handle);                                         \
        }                                                                  \
        _handle = h;                                                       \
    }                                                                      \
inline void Attach(HANDLE h)                                               \
    {                                                                      \
        Win4Assert(_handle == NULL);                                       \
        _handle = h;                                                       \
    }                                                                      \
inline void Detach(void)                                                   \
    {                                                                      \
        _handle = NULL;                                                    \
    }                                                                      \
                                                                           \
inline operator HANDLE ()                                                  \
       {                                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline HANDLE operator= (HANDLE handle)                                    \
       {                                                                   \
            Set(handle);                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline BOOL operator==(HANDLE handle)                                      \
       {                                                                   \
            if (_handle == handle)                                         \
            {                                                              \
                 return(TRUE);                                             \
            }                                                              \
            return(FALSE);                                                 \
       }                                                                   \
                                                                           \
inline HANDLE *operator&()                                                 \
       {                                                                   \
            Win4Assert((_handle==NULL) || (_handle==INVALID_HANDLE_VALUE));\
            return(&_handle);                                              \
       }                                                                   \
                                                                           \
private:                                                                   \
                                                                           \
       HANDLE _handle;                                                     \
                                                                           \
inline VOID operator= (const ShName &) {;}                                 \
inline ShName (const ShName &) {;}                                         \
                                                                           \
};
#define SAFE_WIN32FIND_HANDLE(ShName)                                      \
                                                                           \
class ShName INHERIT_UNWIND_IF_CAIRO                                       \
{                                                                          \
     INLINE_UNWIND(ShName)                                                 \
public:                                                                    \
                                                                           \
inline ShName (HANDLE handle = NULL)                                       \
       : _handle(handle)                                                   \
       {                                                                   \
            END_CONSTRUCTION(ShName)                                       \
       }                                                                   \
                                                                           \
inline ~##ShName ()                                                        \
       {                                                                   \
            if ((_handle != INVALID_HANDLE_VALUE) && (_handle != NULL))    \
            {                                                              \
                 FindClose(_handle);                                       \
            }                                                              \
       }                                                                   \
                                                                           \
inline void Transfer(HANDLE *phandle)                                      \
    {                                                                      \
        *phandle = _handle;                                                \
        _handle = NULL;                                                    \
    }                                                                      \
inline void Set(HANDLE h)                                                  \
    {                                                                      \
        if (_handle != INVALID_HANDLE_VALUE && _handle != NULL)            \
        {                                                                  \
             FindClose(_handle);                                           \
        }                                                                  \
        _handle = h;                                                       \
    }                                                                      \
inline void Attach(HANDLE h)                                               \
    {                                                                      \
        Win4Assert(_handle == NULL);                                       \
        _handle = h;                                                       \
    }                                                                      \
inline void Detach(void)                                                   \
    {                                                                      \
        _handle = NULL;                                                    \
    }                                                                      \
                                                                           \
inline operator HANDLE ()                                                  \
       {                                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline HANDLE operator= (HANDLE handle)                                    \
       {                                                                   \
            Set(handle);                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline BOOL operator==(HANDLE handle)                                      \
       {                                                                   \
            if (_handle == handle)                                         \
            {                                                              \
                 return(TRUE);                                             \
            }                                                              \
            return(FALSE);                                                 \
       }                                                                   \
                                                                           \
inline HANDLE *operator&()                                                 \
       {                                                                   \
            Win4Assert((_handle==NULL) || (_handle==INVALID_HANDLE_VALUE));\
            return(&_handle);                                              \
       }                                                                   \
                                                                           \
private:                                                                   \
                                                                           \
       HANDLE _handle;                                                     \
                                                                           \
inline VOID operator= (const ShName &) {;}                                 \
inline ShName (const ShName &) {;}                                         \
                                                                           \
};
#define SAFE_NT_HANDLE(ShName)                                             \
                                                                           \
class ShName INHERIT_UNWIND_IF_CAIRO                                       \
{                                                                          \
     INLINE_UNWIND(ShName)                                                 \
public:                                                                    \
                                                                           \
inline ShName (HANDLE handle = NULL)                                       \
       : _handle(handle)                                                   \
       {                                                                   \
            END_CONSTRUCTION(ShName)                                       \
       }                                                                   \
                                                                           \
inline ~##ShName ()                                                        \
       {                                                                   \
            if ((_handle != INVALID_HANDLE_VALUE) && (_handle != NULL))    \
            {                                                              \
                 NtClose(_handle);                                         \
            }                                                              \
       }                                                                   \
                                                                           \
inline void Transfer(HANDLE *phandle)                                      \
    {                                                                      \
        *phandle = _handle;                                                \
        _handle = NULL;                                                    \
    }                                                                      \
inline void Set(HANDLE h)                                                  \
    {                                                                      \
        if (_handle != INVALID_HANDLE_VALUE && _handle != NULL)            \
        {                                                                  \
             NtClose(_handle);                                             \
        }                                                                  \
        _handle = h;                                                       \
    }                                                                      \
inline void Attach(HANDLE h)                                               \
    {                                                                      \
        Win4Assert(_handle == NULL);                                       \
        _handle = h;                                                       \
    }                                                                      \
inline void Detach(void)                                                   \
    {                                                                      \
        _handle = NULL;                                                    \
    }                                                                      \
                                                                           \
inline operator HANDLE ()                                                  \
       {                                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline HANDLE operator= (HANDLE handle)                                    \
       {                                                                   \
            Set(handle);                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline BOOL operator==(HANDLE handle)                                      \
       {                                                                   \
            if (_handle == handle)                                         \
            {                                                              \
                 return(TRUE);                                             \
            }                                                              \
            return(FALSE);                                                 \
       }                                                                   \
                                                                           \
inline HANDLE *operator&()                                                 \
       {                                                                   \
            Win4Assert((_handle==NULL) || (_handle==INVALID_HANDLE_VALUE));\
            return(&_handle);                                              \
       }                                                                   \
                                                                           \
private:                                                                   \
                                                                           \
       HANDLE _handle;                                                     \
                                                                           \
inline VOID operator= (const ShName &) {;}                                 \
inline ShName (const ShName &) {;}                                         \
                                                                           \
};
#define UNWINDABLE_WRAPPER(UwName, Class)                       \
class UwName : INHERIT_UNWIND, public Class                     \
{                                                               \
    INLINE_UNWIND(UwName)                                       \
public:                                                         \
    inline UwName(void)                                         \
    {                                                           \
        END_CONSTRUCTION(UwName);                               \
    }                                                           \
    inline ~##UwName(void)                                      \
    {                                                           \
    }                                                           \
}
#define UNWINDABLE_WRAPPER_ARGS(UwName, Class, CtorDecl, CtorArgs)      \
class UwName : INHERIT_UNWIND, public Class                             \
{                                                                       \
    INLINE_UNWIND(UwName)                                               \
public:                                                                 \
    inline UwName CtorDecl : Class CtorArgs                             \
    {                                                                   \
        END_CONSTRUCTION(UwName);                                       \
    }                                                                   \
    inline ~##UwName(void)                                              \
    {                                                                   \
    }                                                                   \
}

// public\sdk\inc\sapi.h
#define ISpDataKey_SetData(This,pszValueName,cbData,pData)	\
    (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData)
#define ISpDataKey_GetData(This,pszValueName,pcbData,pData)	\
    (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData)
#define ISpRegDataKey_SetData(This,pszValueName,cbData,pData)	\
    (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData)
#define ISpRegDataKey_GetData(This,pszValueName,pcbData,pData)	\
    (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData)
#define ISpObjectTokenCategory_SetData(This,pszValueName,cbData,pData)	\
    (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData)
#define ISpObjectTokenCategory_GetData(This,pszValueName,pcbData,pData)	\
    (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData)
#define ISpObjectToken_SetData(This,pszValueName,cbData,pData)	\
    (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData)
#define ISpObjectToken_GetData(This,pszValueName,pcbData,pData)	\
    (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData)
#define ISpObjectToken_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)	\
    (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)
#define ISpObjectToken_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject)	\
    (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject)
#define ISpObjectTokenInit_SetData(This,pszValueName,cbData,pData)	\
    (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData)
#define ISpObjectTokenInit_GetData(This,pszValueName,pcbData,pData)	\
    (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData)
#define ISpObjectTokenInit_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)	\
    (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)
#define ISpObjectTokenInit_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject)	\
    (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject)
#define ISpStreamFormat_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISpStreamFormat_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define ISpStreamFormat_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define ISpStream_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISpStream_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define ISpStream_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define ISpStreamFormatConverter_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISpStreamFormatConverter_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define ISpStreamFormatConverter_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define ISpAudio_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISpAudio_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define ISpAudio_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define ISpAudio_SetBufferInfo(This,pBuffInfo)	\
    (This)->lpVtbl -> SetBufferInfo(This,pBuffInfo)
#define ISpAudio_GetBufferInfo(This,pBuffInfo)	\
    (This)->lpVtbl -> GetBufferInfo(This,pBuffInfo)
#define ISpAudio_GetBufferNotifySize(This,pcbSize)	\
    (This)->lpVtbl -> GetBufferNotifySize(This,pcbSize)
#define ISpAudio_SetBufferNotifySize(This,cbSize)	\
    (This)->lpVtbl -> SetBufferNotifySize(This,cbSize)
#define ISpMMSysAudio_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISpMMSysAudio_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define ISpMMSysAudio_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define ISpMMSysAudio_SetBufferInfo(This,pBuffInfo)	\
    (This)->lpVtbl -> SetBufferInfo(This,pBuffInfo)
#define ISpMMSysAudio_GetBufferInfo(This,pBuffInfo)	\
    (This)->lpVtbl -> GetBufferInfo(This,pBuffInfo)
#define ISpMMSysAudio_GetBufferNotifySize(This,pcbSize)	\
    (This)->lpVtbl -> GetBufferNotifySize(This,pcbSize)
#define ISpMMSysAudio_SetBufferNotifySize(This,cbSize)	\
    (This)->lpVtbl -> SetBufferNotifySize(This,cbSize)
#define ISpVoice_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported)	\
    (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported)
#define ISpVoice_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData)	\
    (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData)
#define ISpRecoGrammar_LoadCmdFromProprietaryGrammar(This,rguidParam,pszStringParam,pvDataPrarm,cbDataSize,Options)	\
    (This)->lpVtbl -> LoadCmdFromProprietaryGrammar(This,rguidParam,pszStringParam,pvDataPrarm,cbDataSize,Options)
#define ISpRecognizer_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported)	\
    (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported)
#define ISpRecognizer_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData)	\
    (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData)
#define ISpeechAudioBufferInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ISpeechAudioBufferInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ISpeechAudioBufferInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ISpeechAudioBufferInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ISpeechAudioBufferInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ISpeechAudioBufferInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ISpeechAudioBufferInfo_get_MinNotification(This,MinNotification)	\
    (This)->lpVtbl -> get_MinNotification(This,MinNotification)
#define ISpeechAudioBufferInfo_put_MinNotification(This,MinNotification)	\
    (This)->lpVtbl -> put_MinNotification(This,MinNotification)
#define ISpeechAudioBufferInfo_get_BufferSize(This,BufferSize)	\
    (This)->lpVtbl -> get_BufferSize(This,BufferSize)
#define ISpeechAudioBufferInfo_put_BufferSize(This,BufferSize)	\
    (This)->lpVtbl -> put_BufferSize(This,BufferSize)
#define ISpeechAudioBufferInfo_get_EventBias(This,EventBias)	\
    (This)->lpVtbl -> get_EventBias(This,EventBias)
#define ISpeechAudioBufferInfo_put_EventBias(This,EventBias)	\
    (This)->lpVtbl -> put_EventBias(This,EventBias)
#define ISpeechAudioStatus_get_FreeBufferSpace(This,FreeBufferSpace)	\
    (This)->lpVtbl -> get_FreeBufferSpace(This,FreeBufferSpace)
#define ISpeechFileStream_Read(This,Buffer,NumberOfBytes,BytesRead)	\
    (This)->lpVtbl -> Read(This,Buffer,NumberOfBytes,BytesRead)
#define ISpeechFileStream_Write(This,Buffer,BytesWritten)	\
    (This)->lpVtbl -> Write(This,Buffer,BytesWritten)
#define ISpeechMemoryStream_Read(This,Buffer,NumberOfBytes,BytesRead)	\
    (This)->lpVtbl -> Read(This,Buffer,NumberOfBytes,BytesRead)
#define ISpeechMemoryStream_Write(This,Buffer,BytesWritten)	\
    (This)->lpVtbl -> Write(This,Buffer,BytesWritten)
#define ISpeechCustomStream_Read(This,Buffer,NumberOfBytes,BytesRead)	\
    (This)->lpVtbl -> Read(This,Buffer,NumberOfBytes,BytesRead)
#define ISpeechCustomStream_Write(This,Buffer,BytesWritten)	\
    (This)->lpVtbl -> Write(This,Buffer,BytesWritten)
#define ISpeechAudio_Read(This,Buffer,NumberOfBytes,BytesRead)	\
    (This)->lpVtbl -> Read(This,Buffer,NumberOfBytes,BytesRead)
#define ISpeechAudio_Write(This,Buffer,BytesWritten)	\
    (This)->lpVtbl -> Write(This,Buffer,BytesWritten)
#define ISpeechAudio_get_BufferInfo(This,BufferInfo)	\
    (This)->lpVtbl -> get_BufferInfo(This,BufferInfo)
#define ISpeechAudio_get_BufferNotifySize(This,BufferNotifySize)	\
    (This)->lpVtbl -> get_BufferNotifySize(This,BufferNotifySize)
#define ISpeechAudio_put_BufferNotifySize(This,BufferNotifySize)	\
    (This)->lpVtbl -> put_BufferNotifySize(This,BufferNotifySize)
#define ISpeechMMSysAudio_Read(This,Buffer,NumberOfBytes,BytesRead)	\
    (This)->lpVtbl -> Read(This,Buffer,NumberOfBytes,BytesRead)
#define ISpeechMMSysAudio_Write(This,Buffer,BytesWritten)	\
    (This)->lpVtbl -> Write(This,Buffer,BytesWritten)
#define ISpeechMMSysAudio_get_BufferInfo(This,BufferInfo)	\
    (This)->lpVtbl -> get_BufferInfo(This,BufferInfo)
#define ISpeechMMSysAudio_get_BufferNotifySize(This,BufferNotifySize)	\
    (This)->lpVtbl -> get_BufferNotifySize(This,BufferNotifySize)
#define ISpeechMMSysAudio_put_BufferNotifySize(This,BufferNotifySize)	\
    (This)->lpVtbl -> put_BufferNotifySize(This,BufferNotifySize)

// public\sdk\inc\sapiddk.h
#define ISpTokenUI_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)	\
    (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)
#define ISpTokenUI_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,pToken,punkObject)	\
    (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,pToken,punkObject)
#define ISpTTSEngineSite_Write(This,pBuff,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pBuff,cb,pcbWritten)
#define ISpSREngineSite_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISpSREngineSite_DataAvailable(This,pcb)	\
    (This)->lpVtbl -> DataAvailable(This,pcb)
#define ISpSREngineSite_SetBufferNotifySize(This,cbSize)	\
    (This)->lpVtbl -> SetBufferNotifySize(This,cbSize)
#define ISpSREngineSite_GetWordInfo(This,pWordEntry,Options)	\
    (This)->lpVtbl -> GetWordInfo(This,pWordEntry,Options)
#define ISpSREngineSite_GetRuleInfo(This,pRuleEntry,Options)	\
    (This)->lpVtbl -> GetRuleInfo(This,pRuleEntry,Options)
#define ISpSRAlternates_Commit(This,pAltRequest,pAlt,ppvResultExtra,pcbResultExtra)	\
    (This)->lpVtbl -> Commit(This,pAltRequest,pAlt,ppvResultExtra,pcbResultExtra)

// public\sdk\inc\sbe.h
#define IStreamBufferInitialize_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IStreamBufferInitialize_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IStreamBufferInitialize_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IStreamBufferInitialize_SetHKEY(This,hkeyRoot)	\
    (This)->lpVtbl -> SetHKEY(This,hkeyRoot)
#define IStreamBufferInitialize_SetSIDs(This,cSIDs,ppSID)	\
    (This)->lpVtbl -> SetSIDs(This,cSIDs,ppSID)
#define IStreamBufferSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IStreamBufferSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IStreamBufferSink_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IStreamBufferSink_LockProfile(This,pszStreamBufferFilename)	\
    (This)->lpVtbl -> LockProfile(This,pszStreamBufferFilename)
#define IStreamBufferSink_CreateRecorder(This,pszFilename,dwRecordType,pRecordingIUnknown)	\
    (This)->lpVtbl -> CreateRecorder(This,pszFilename,dwRecordType,pRecordingIUnknown)
#define IStreamBufferSink_IsProfileLocked(This)	\
    (This)->lpVtbl -> IsProfileLocked(This)
#define IStreamBufferSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IStreamBufferSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IStreamBufferSource_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IStreamBufferSource_SetStreamSink(This,pIStreamBufferSink)	\
    (This)->lpVtbl -> SetStreamSink(This,pIStreamBufferSink)
#define IStreamBufferRecordControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IStreamBufferRecordControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IStreamBufferRecordControl_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IStreamBufferRecordControl_Start(This,prtStart)	\
    (This)->lpVtbl -> Start(This,prtStart)
#define IStreamBufferRecordControl_Stop(This,rtStop)	\
    (This)->lpVtbl -> Stop(This,rtStop)
#define IStreamBufferRecordControl_GetRecordingStatus(This,phResult,pbStarted,pbStopped)	\
    (This)->lpVtbl -> GetRecordingStatus(This,phResult,pbStarted,pbStopped)
#define IStreamBufferRecComp_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IStreamBufferRecComp_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IStreamBufferRecComp_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IStreamBufferRecComp_Initialize(This,pszTargetFilename,pszSBRecProfileRef)	\
    (This)->lpVtbl -> Initialize(This,pszTargetFilename,pszSBRecProfileRef)
#define IStreamBufferRecComp_Append(This,pszSBRecording)	\
    (This)->lpVtbl -> Append(This,pszSBRecording)
#define IStreamBufferRecComp_AppendEx(This,pszSBRecording,rtStart,rtStop)	\
    (This)->lpVtbl -> AppendEx(This,pszSBRecording,rtStart,rtStop)
#define IStreamBufferRecComp_GetCurrentLength(This,pcSeconds)	\
    (This)->lpVtbl -> GetCurrentLength(This,pcSeconds)
#define IStreamBufferRecComp_Close(This)	\
    (This)->lpVtbl -> Close(This)
#define IStreamBufferRecComp_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)
#define IStreamBufferRecordingAttribute_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IStreamBufferRecordingAttribute_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IStreamBufferRecordingAttribute_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IStreamBufferRecordingAttribute_SetAttribute(This,ulReserved,pszAttributeName,StreamBufferAttributeType,pbAttribute,cbAttributeLength)	\
    (This)->lpVtbl -> SetAttribute(This,ulReserved,pszAttributeName,StreamBufferAttributeType,pbAttribute,cbAttributeLength)
#define IStreamBufferRecordingAttribute_GetAttributeCount(This,ulReserved,pcAttributes)	\
    (This)->lpVtbl -> GetAttributeCount(This,ulReserved,pcAttributes)
#define IStreamBufferRecordingAttribute_GetAttributeByName(This,pszAttributeName,pulReserved,pStreamBufferAttributeType,pbAttribute,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByName(This,pszAttributeName,pulReserved,pStreamBufferAttributeType,pbAttribute,pcbLength)
#define IStreamBufferRecordingAttribute_GetAttributeByIndex(This,wIndex,pulReserved,pszAttributeName,pcchNameLength,pStreamBufferAttributeType,pbAttribute,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pulReserved,pszAttributeName,pcchNameLength,pStreamBufferAttributeType,pbAttribute,pcbLength)
#define IStreamBufferRecordingAttribute_EnumAttributes(This,ppIEnumStreamBufferAttrib)	\
    (This)->lpVtbl -> EnumAttributes(This,ppIEnumStreamBufferAttrib)
#define IEnumStreamBufferRecordingAttrib_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IEnumStreamBufferRecordingAttrib_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IEnumStreamBufferRecordingAttrib_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IEnumStreamBufferRecordingAttrib_Skip(This,cRecords)	\
    (This)->lpVtbl -> Skip(This,cRecords)
#define IEnumStreamBufferRecordingAttrib_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IEnumStreamBufferRecordingAttrib_Clone(This,ppIEnumStreamBufferAttrib)	\
    (This)->lpVtbl -> Clone(This,ppIEnumStreamBufferAttrib)
#define IStreamBufferConfigure_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IStreamBufferConfigure_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IStreamBufferConfigure_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IStreamBufferConfigure_SetDirectory(This,pszDirectoryName)	\
    (This)->lpVtbl -> SetDirectory(This,pszDirectoryName)
#define IStreamBufferConfigure_GetDirectory(This,ppszDirectoryName)	\
    (This)->lpVtbl -> GetDirectory(This,ppszDirectoryName)
#define IStreamBufferConfigure_SetBackingFileCount(This,dwMin,dwMax)	\
    (This)->lpVtbl -> SetBackingFileCount(This,dwMin,dwMax)
#define IStreamBufferConfigure_GetBackingFileCount(This,pdwMin,pdwMax)	\
    (This)->lpVtbl -> GetBackingFileCount(This,pdwMin,pdwMax)
#define IStreamBufferConfigure_SetBackingFileDuration(This,dwSeconds)	\
    (This)->lpVtbl -> SetBackingFileDuration(This,dwSeconds)
#define IStreamBufferConfigure_GetBackingFileDuration(This,pdwSeconds)	\
    (This)->lpVtbl -> GetBackingFileDuration(This,pdwSeconds)
#define IStreamBufferMediaSeeking_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IStreamBufferMediaSeeking_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IStreamBufferMediaSeeking_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IStreamBufferMediaSeeking_GetCapabilities(This,pCapabilities)	\
    (This)->lpVtbl -> GetCapabilities(This,pCapabilities)
#define IStreamBufferMediaSeeking_CheckCapabilities(This,pCapabilities)	\
    (This)->lpVtbl -> CheckCapabilities(This,pCapabilities)
#define IStreamBufferMediaSeeking_IsFormatSupported(This,pFormat)	\
    (This)->lpVtbl -> IsFormatSupported(This,pFormat)
#define IStreamBufferMediaSeeking_QueryPreferredFormat(This,pFormat)	\
    (This)->lpVtbl -> QueryPreferredFormat(This,pFormat)
#define IStreamBufferMediaSeeking_GetTimeFormat(This,pFormat)	\
    (This)->lpVtbl -> GetTimeFormat(This,pFormat)
#define IStreamBufferMediaSeeking_IsUsingTimeFormat(This,pFormat)	\
    (This)->lpVtbl -> IsUsingTimeFormat(This,pFormat)
#define IStreamBufferMediaSeeking_SetTimeFormat(This,pFormat)	\
    (This)->lpVtbl -> SetTimeFormat(This,pFormat)
#define IStreamBufferMediaSeeking_GetDuration(This,pDuration)	\
    (This)->lpVtbl -> GetDuration(This,pDuration)
#define IStreamBufferMediaSeeking_GetStopPosition(This,pStop)	\
    (This)->lpVtbl -> GetStopPosition(This,pStop)
#define IStreamBufferMediaSeeking_GetCurrentPosition(This,pCurrent)	\
    (This)->lpVtbl -> GetCurrentPosition(This,pCurrent)
#define IStreamBufferMediaSeeking_ConvertTimeFormat(This,pTarget,pTargetFormat,Source,pSourceFormat)	\
    (This)->lpVtbl -> ConvertTimeFormat(This,pTarget,pTargetFormat,Source,pSourceFormat)
#define IStreamBufferMediaSeeking_SetPositions(This,pCurrent,dwCurrentFlags,pStop,dwStopFlags)	\
    (This)->lpVtbl -> SetPositions(This,pCurrent,dwCurrentFlags,pStop,dwStopFlags)
#define IStreamBufferMediaSeeking_GetPositions(This,pCurrent,pStop)	\
    (This)->lpVtbl -> GetPositions(This,pCurrent,pStop)
#define IStreamBufferMediaSeeking_GetAvailable(This,pEarliest,pLatest)	\
    (This)->lpVtbl -> GetAvailable(This,pEarliest,pLatest)
#define IStreamBufferMediaSeeking_SetRate(This,dRate)	\
    (This)->lpVtbl -> SetRate(This,dRate)
#define IStreamBufferMediaSeeking_GetRate(This,pdRate)	\
    (This)->lpVtbl -> GetRate(This,pdRate)
#define IStreamBufferMediaSeeking_GetPreroll(This,pllPreroll)	\
    (This)->lpVtbl -> GetPreroll(This,pllPreroll)

// public\sdk\inc\scesvc.h
#define ISceSvcAttachmentPersistInfo_FreeBuffer(This,pvData)    \
    (This)->lpVtbl -> FreeBuffer(pvData)
#define ISceSvcAttachmentData_FreeBuffer(This,pvData)   \
    (This)->lpVtbl -> FreeBuffer(pvData)

// public\sdk\inc\segment.h
#define IMSVidStreamBufferRecordingControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMSVidStreamBufferRecordingControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMSVidStreamBufferRecordingControl_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMSVidStreamBufferRecordingControl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IMSVidStreamBufferRecordingControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IMSVidStreamBufferRecordingControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IMSVidStreamBufferRecordingControl_get_StartTime(This,rtStart)	\
    (This)->lpVtbl -> get_StartTime(This,rtStart)
#define IMSVidStreamBufferRecordingControl_put_StartTime(This,rtStart)	\
    (This)->lpVtbl -> put_StartTime(This,rtStart)
#define IMSVidStreamBufferRecordingControl_get_StopTime(This,rtStop)	\
    (This)->lpVtbl -> get_StopTime(This,rtStop)
#define IMSVidStreamBufferRecordingControl_put_StopTime(This,rtStop)	\
    (This)->lpVtbl -> put_StopTime(This,rtStop)
#define IMSVidStreamBufferRecordingControl_get_RecordingStopped(This,phResult)	\
    (This)->lpVtbl -> get_RecordingStopped(This,phResult)
#define IMSVidStreamBufferRecordingControl_get_RecordingStarted(This,phResult)	\
    (This)->lpVtbl -> get_RecordingStarted(This,phResult)
#define IMSVidStreamBufferRecordingControl_get_RecordingType(This,dwType)	\
    (This)->lpVtbl -> get_RecordingType(This,dwType)
#define IMSVidStreamBufferRecordingControl_get_RecordingAttribute(This,pRecordingAttribute)	\
    (This)->lpVtbl -> get_RecordingAttribute(This,pRecordingAttribute)
#define IMSVidStreamBufferSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMSVidStreamBufferSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMSVidStreamBufferSink_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMSVidStreamBufferSink_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IMSVidStreamBufferSink_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IMSVidStreamBufferSink_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IMSVidStreamBufferSink_get_Name(This,Name)	\
    (This)->lpVtbl -> get_Name(This,Name)
#define IMSVidStreamBufferSink_get_Status(This,Status)	\
    (This)->lpVtbl -> get_Status(This,Status)
#define IMSVidStreamBufferSink_put_Power(This,Power)	\
    (This)->lpVtbl -> put_Power(This,Power)
#define IMSVidStreamBufferSink_get_Power(This,Power)	\
    (This)->lpVtbl -> get_Power(This,Power)
#define IMSVidStreamBufferSink_get_Category(This,Guid)	\
    (This)->lpVtbl -> get_Category(This,Guid)
#define IMSVidStreamBufferSink_get_ClassID(This,Clsid)	\
    (This)->lpVtbl -> get_ClassID(This,Clsid)
#define IMSVidStreamBufferSink_get__Category(This,Guid)	\
    (This)->lpVtbl -> get__Category(This,Guid)
#define IMSVidStreamBufferSink_get__ClassID(This,Clsid)	\
    (This)->lpVtbl -> get__ClassID(This,Clsid)
#define IMSVidStreamBufferSink_IsEqualDevice(This,Device,IsEqual)	\
    (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual)
#define IMSVidStreamBufferSink_get_ContentRecorder(This,pszFilename,pRecordingIUnknown)	\
    (This)->lpVtbl -> get_ContentRecorder(This,pszFilename,pRecordingIUnknown)
#define IMSVidStreamBufferSink_get_ReferenceRecorder(This,pszFilename,pRecordingIUnknown)	\
    (This)->lpVtbl -> get_ReferenceRecorder(This,pszFilename,pRecordingIUnknown)
#define IMSVidStreamBufferSink_get_SinkName(This,pName)	\
    (This)->lpVtbl -> get_SinkName(This,pName)
#define IMSVidStreamBufferSink_put_SinkName(This,Name)	\
    (This)->lpVtbl -> put_SinkName(This,Name)
#define IMSVidStreamBufferSink_NameSetLock(This)	\
    (This)->lpVtbl -> NameSetLock(This)
#define IMSVidStreamBufferSink_get_SBESink(This,sbeConfig)	\
    (This)->lpVtbl -> get_SBESink(This,sbeConfig)
#define IMSVidStreamBufferSinkEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMSVidStreamBufferSinkEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMSVidStreamBufferSinkEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMSVidStreamBufferSinkEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IMSVidStreamBufferSinkEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IMSVidStreamBufferSinkEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IMSVidStreamBufferSinkEvent_StateChange(This,lpd,oldState,newState)	\
    (This)->lpVtbl -> StateChange(This,lpd,oldState,newState)
#define IMSVidStreamBufferSinkEvent_CertificateFailure(This)	\
    (This)->lpVtbl -> CertificateFailure(This)
#define IMSVidStreamBufferSinkEvent_CertificateSuccess(This)	\
    (This)->lpVtbl -> CertificateSuccess(This)
#define IMSVidStreamBufferSinkEvent_WriteFailure(This)	\
    (This)->lpVtbl -> WriteFailure(This)
#define IMSVidStreamBufferSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMSVidStreamBufferSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMSVidStreamBufferSource_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMSVidStreamBufferSource_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IMSVidStreamBufferSource_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IMSVidStreamBufferSource_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IMSVidStreamBufferSource_get_Name(This,Name)	\
    (This)->lpVtbl -> get_Name(This,Name)
#define IMSVidStreamBufferSource_get_Status(This,Status)	\
    (This)->lpVtbl -> get_Status(This,Status)
#define IMSVidStreamBufferSource_put_Power(This,Power)	\
    (This)->lpVtbl -> put_Power(This,Power)
#define IMSVidStreamBufferSource_get_Power(This,Power)	\
    (This)->lpVtbl -> get_Power(This,Power)
#define IMSVidStreamBufferSource_get_Category(This,Guid)	\
    (This)->lpVtbl -> get_Category(This,Guid)
#define IMSVidStreamBufferSource_get_ClassID(This,Clsid)	\
    (This)->lpVtbl -> get_ClassID(This,Clsid)
#define IMSVidStreamBufferSource_get__Category(This,Guid)	\
    (This)->lpVtbl -> get__Category(This,Guid)
#define IMSVidStreamBufferSource_get__ClassID(This,Clsid)	\
    (This)->lpVtbl -> get__ClassID(This,Clsid)
#define IMSVidStreamBufferSource_IsEqualDevice(This,Device,IsEqual)	\
    (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual)
#define IMSVidStreamBufferSource_IsViewable(This,v,pfViewable)	\
    (This)->lpVtbl -> IsViewable(This,v,pfViewable)
#define IMSVidStreamBufferSource_View(This,v)	\
    (This)->lpVtbl -> View(This,v)
#define IMSVidStreamBufferSource_get_EnableResetOnStop(This,pVal)	\
    (This)->lpVtbl -> get_EnableResetOnStop(This,pVal)
#define IMSVidStreamBufferSource_put_EnableResetOnStop(This,newVal)	\
    (This)->lpVtbl -> put_EnableResetOnStop(This,newVal)
#define IMSVidStreamBufferSource_Run(This)	\
    (This)->lpVtbl -> Run(This)
#define IMSVidStreamBufferSource_Pause(This)	\
    (This)->lpVtbl -> Pause(This)
#define IMSVidStreamBufferSource_Stop(This)	\
    (This)->lpVtbl -> Stop(This)
#define IMSVidStreamBufferSource_get_CanStep(This,fBackwards,pfCan)	\
    (This)->lpVtbl -> get_CanStep(This,fBackwards,pfCan)
#define IMSVidStreamBufferSource_Step(This,lStep)	\
    (This)->lpVtbl -> Step(This,lStep)
#define IMSVidStreamBufferSource_put_Rate(This,plRate)	\
    (This)->lpVtbl -> put_Rate(This,plRate)
#define IMSVidStreamBufferSource_get_Rate(This,plRate)	\
    (This)->lpVtbl -> get_Rate(This,plRate)
#define IMSVidStreamBufferSource_put_CurrentPosition(This,lPosition)	\
    (This)->lpVtbl -> put_CurrentPosition(This,lPosition)
#define IMSVidStreamBufferSource_get_CurrentPosition(This,lPosition)	\
    (This)->lpVtbl -> get_CurrentPosition(This,lPosition)
#define IMSVidStreamBufferSource_put_PositionMode(This,lPositionMode)	\
    (This)->lpVtbl -> put_PositionMode(This,lPositionMode)
#define IMSVidStreamBufferSource_get_PositionMode(This,lPositionMode)	\
    (This)->lpVtbl -> get_PositionMode(This,lPositionMode)
#define IMSVidStreamBufferSource_get_Length(This,lLength)	\
    (This)->lpVtbl -> get_Length(This,lLength)
#define IMSVidStreamBufferSource_get_FileName(This,FileName)	\
    (This)->lpVtbl -> get_FileName(This,FileName)
#define IMSVidStreamBufferSource_put_FileName(This,FileName)	\
    (This)->lpVtbl -> put_FileName(This,FileName)
#define IMSVidStreamBufferSource_get_Start(This,lStart)	\
    (This)->lpVtbl -> get_Start(This,lStart)
#define IMSVidStreamBufferSource_get_RecordingAttribute(This,pRecordingAttribute)	\
    (This)->lpVtbl -> get_RecordingAttribute(This,pRecordingAttribute)
#define IMSVidStreamBufferSource_CurrentRatings(This,pEnSystem,pEnRating,pBfEnAttr)	\
    (This)->lpVtbl -> CurrentRatings(This,pEnSystem,pEnRating,pBfEnAttr)
#define IMSVidStreamBufferSource_MaxRatingsLevel(This,enSystem,enRating,lbfEnAttr)	\
    (This)->lpVtbl -> MaxRatingsLevel(This,enSystem,enRating,lbfEnAttr)
#define IMSVidStreamBufferSource_put_UnratedDelay(This,dwDelay)	\
    (This)->lpVtbl -> put_UnratedDelay(This,dwDelay)
#define IMSVidStreamBufferSource_get_SBESource(This,sbeFilter)	\
    (This)->lpVtbl -> get_SBESource(This,sbeFilter)
#define IMSVidStreamBufferSourceEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IMSVidStreamBufferSourceEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IMSVidStreamBufferSourceEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IMSVidStreamBufferSourceEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define IMSVidStreamBufferSourceEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IMSVidStreamBufferSourceEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IMSVidStreamBufferSourceEvent_EndOfMedia(This,lpd)	\
    (This)->lpVtbl -> EndOfMedia(This,lpd)
#define IMSVidStreamBufferSourceEvent_CertificateFailure(This)	\
    (This)->lpVtbl -> CertificateFailure(This)
#define IMSVidStreamBufferSourceEvent_CertificateSuccess(This)	\
    (This)->lpVtbl -> CertificateSuccess(This)
#define IMSVidStreamBufferSourceEvent_RatingsChanged(This)	\
    (This)->lpVtbl -> RatingsChanged(This)
#define IMSVidStreamBufferSourceEvent_StaleDataRead(This)	\
    (This)->lpVtbl -> StaleDataRead(This)
#define IMSVidStreamBufferSourceEvent_ContentBecomingStale(This)	\
    (This)->lpVtbl -> ContentBecomingStale(This)
#define IMSVidStreamBufferSourceEvent_StaleFileDeleted(This)	\
    (This)->lpVtbl -> StaleFileDeleted(This)

// public\sdk\inc\setupxrc.h
#define     STF_SET_INSTRUCTION_TEXT_RC         (WM_USER + 0x8104)

// public\sdk\inc\shldisp.h
#define ISearchCommandExt_Execute(This,RecordsAffected,Parameters,Options)	\
    (This)->lpVtbl -> Execute(This,RecordsAffected,Parameters,Options)

// public\sdk\inc\shobjidl.h
#define IExtractImage_GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags)	\
    (This)->lpVtbl -> GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags)
#define IExtractImage2_GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags)	\
    (This)->lpVtbl -> GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags)
#define IDockingWindow_ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved)	\
    (This)->lpVtbl -> ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved)
#define IDeskBand_ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved)	\
    (This)->lpVtbl -> ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved)
#define ICDBurn_GetRecorderDriveLetter(This,pszDrive,cch)	\
    (This)->lpVtbl -> GetRecorderDriveLetter(This,pszDrive,cch)
#define ICDBurn_HasRecordableDrive(This,pfHasRecorder)	\
    (This)->lpVtbl -> HasRecordableDrive(This,pfHasRecorder)
#define INamespaceWalkCB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INamespaceWalkCB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INamespaceWalkCB_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INamespaceWalkCB_FoundItem(This,psf,pidl)	\
    (This)->lpVtbl -> FoundItem(This,psf,pidl)
#define INamespaceWalkCB_EnterFolder(This,psf,pidl)	\
    (This)->lpVtbl -> EnterFolder(This,psf,pidl)
#define INamespaceWalkCB_LeaveFolder(This,psf,pidl)	\
    (This)->lpVtbl -> LeaveFolder(This,psf,pidl)
#define INamespaceWalkCB_InitializeProgressDialog(This,ppszTitle,ppszCancel)	\
    (This)->lpVtbl -> InitializeProgressDialog(This,ppszTitle,ppszCancel)
#define INamespaceWalk_Walk(This,punkToWalk,dwFlags,cDepth,pnswcb)	\
    (This)->lpVtbl -> Walk(This,punkToWalk,dwFlags,cDepth,pnswcb)

// public\sdk\inc\snmp.h
#define SNMP_PDU_GET                (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x0)
#define SNMP_PDU_RESPONSE           (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x2)
#define SNMP_PDU_SET                (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x3)
#define SNMP_PDU_V1TRAP             (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x4)
#define SNMP_PDU_GETBULK            (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x5)
#define SNMP_PDU_INFORM             (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x6)
#define SNMP_PDU_TRAP               (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x7)
#define ASN_SEQUENCE                (ASN_UNIVERSAL | ASN_CONSTRUCTOR | 0x10)
#define SNMP_EXTENSION_SET_TEST     (ASN_PRIVATE | ASN_CONSTRUCTOR | 0x0)
#define SNMP_EXTENSION_SET_UNDO     (ASN_PRIVATE | ASN_CONSTRUCTOR | 0x1)
#define SNMP_EXTENSION_SET_CLEANUP  (ASN_PRIVATE | ASN_CONSTRUCTOR | 0x2)

// public\sdk\inc\sqloledb.h
#define ISQLServerErrorInfo_GetErrorInfo(This,ppErrorInfo,ppStringsBuffer)	\
    (This)->lpVtbl -> GetErrorInfo(This,ppErrorInfo,ppStringsBuffer)
#define ISchemaLock_GetSchemaLock(This,pTableID,lmMode,phLockHandle,pTableVersion)	\
    (This)->lpVtbl -> GetSchemaLock(This,pTableID,lmMode,phLockHandle,pTableVersion)

// public\sdk\inc\storext.h
#define IOverlappedCompletion_OnComplete(This,hr,pcbTransferred,lpOverlapped)	\
    (This)->lpVtbl -> OnComplete(This,hr,pcbTransferred,lpOverlapped)
#define IOverlappedStream_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define IOverlappedStream_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define IOverlappedStream_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define IOverlappedStream_ReadOverlapped(This,pv,cb,pcbRead,lpOverlapped)	\
    (This)->lpVtbl -> ReadOverlapped(This,pv,cb,pcbRead,lpOverlapped)
#define IOverlappedStream_WriteOverlapped(This,pv,cb,pcbWritten,lpOverlapped)	\
    (This)->lpVtbl -> WriteOverlapped(This,pv,cb,pcbWritten,lpOverlapped)
#define IOverlappedStream_GetOverlappedResult(This,lpOverlapped,plcbTransfer,fWait)	\
    (This)->lpVtbl -> GetOverlappedResult(This,lpOverlapped,plcbTransfer,fWait)

// public\sdk\inc\strmif.h
#define IMediaSample2_GetProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> GetProperties(This,cbProperties,pbProperties)
#define IMediaSample2_SetProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> SetProperties(This,cbProperties,pbProperties)
#define IMemAllocator_GetBuffer(This,ppBuffer,pStartTime,pEndTime,dwFlags)	\
    (This)->lpVtbl -> GetBuffer(This,ppBuffer,pStartTime,pEndTime,dwFlags)
#define IMemAllocator_ReleaseBuffer(This,pBuffer)	\
    (This)->lpVtbl -> ReleaseBuffer(This,pBuffer)
#define IMemAllocatorCallbackTemp_GetBuffer(This,ppBuffer,pStartTime,pEndTime,dwFlags)	\
    (This)->lpVtbl -> GetBuffer(This,ppBuffer,pStartTime,pEndTime,dwFlags)
#define IMemAllocatorCallbackTemp_ReleaseBuffer(This,pBuffer)	\
    (This)->lpVtbl -> ReleaseBuffer(This,pBuffer)
#define IMemAllocatorCallbackTemp_GetFreeCount(This,plBuffersFree)	\
    (This)->lpVtbl -> GetFreeCount(This,plBuffersFree)
#define IAsyncReader_SyncRead(This,llPosition,lLength,pBuffer)	\
    (This)->lpVtbl -> SyncRead(This,llPosition,lLength,pBuffer)
#define IAMVideoCompression_GetInfo(This,pszVersion,pcbVersion,pszDescription,pcbDescription,pDefaultKeyFrameRate,pDefaultPFramesPerKey,pDefaultQuality,pCapabilities)	\
    (This)->lpVtbl -> GetInfo(This,pszVersion,pcbVersion,pszDescription,pcbDescription,pDefaultKeyFrameRate,pDefaultPFramesPerKey,pDefaultQuality,pCapabilities)
#define IAMVfwCompressDialogs_GetState(This,pState,pcbState)	\
    (This)->lpVtbl -> GetState(This,pState,pcbState)
#define IAMVfwCompressDialogs_SetState(This,pState,cbState)	\
    (This)->lpVtbl -> SetState(This,pState,cbState)
#define IAMBufferNegotiation_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IAMBufferNegotiation_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IAMBufferNegotiation_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IAMBufferNegotiation_SuggestAllocatorProperties(This,pprop)	\
    (This)->lpVtbl -> SuggestAllocatorProperties(This,pprop)
#define IAMBufferNegotiation_GetAllocatorProperties(This,pprop)	\
    (This)->lpVtbl -> GetAllocatorProperties(This,pprop)
#define IKsPropertySet_Set(This,guidPropSet,dwPropID,pInstanceData,cbInstanceData,pPropData,cbPropData)	\
    (This)->lpVtbl -> Set(This,guidPropSet,dwPropID,pInstanceData,cbInstanceData,pPropData,cbPropData)
#define IKsPropertySet_Get(This,guidPropSet,dwPropID,pInstanceData,cbInstanceData,pPropData,cbPropData,pcbReturned)	\
    (This)->lpVtbl -> Get(This,guidPropSet,dwPropID,pInstanceData,cbInstanceData,pPropData,cbPropData,pcbReturned)
#define IAMDevMemoryAllocator_GetInfo(This,pdwcbTotalFree,pdwcbLargestFree,pdwcbTotalMemory,pdwcbMinimumChunk)	\
    (This)->lpVtbl -> GetInfo(This,pdwcbTotalFree,pdwcbLargestFree,pdwcbTotalMemory,pdwcbMinimumChunk)
#define IAMDevMemoryAllocator_CheckMemory(This,pBuffer)	\
    (This)->lpVtbl -> CheckMemory(This,pBuffer)
#define IAMDevMemoryAllocator_Alloc(This,ppBuffer,pdwcbBuffer)	\
    (This)->lpVtbl -> Alloc(This,ppBuffer,pdwcbBuffer)
#define IAMDevMemoryAllocator_Free(This,pBuffer)	\
    (This)->lpVtbl -> Free(This,pBuffer)
#define IEnumStreamIdMap_Skip(This,cRecords)	\
    (This)->lpVtbl -> Skip(This,cRecords)
#define IDvdInfo2_GetDVDTextStringAsNative(This,ulLangIndex,ulStringIndex,pbBuffer,ulMaxBufferSize,pulActualSize,pType)	\
    (This)->lpVtbl -> GetDVDTextStringAsNative(This,ulLangIndex,ulStringIndex,pbBuffer,ulMaxBufferSize,pulActualSize,pType)
#define IDvdInfo2_GetDVDTextStringAsUnicode(This,ulLangIndex,ulStringIndex,pchwBuffer,ulMaxBufferSize,pulActualSize,pType)	\
    (This)->lpVtbl -> GetDVDTextStringAsUnicode(This,ulLangIndex,ulStringIndex,pchwBuffer,ulMaxBufferSize,pulActualSize,pType)
#define IVMRSurfaceAllocator_AllocateSurface(This,dwUserID,lpAllocInfo,lpdwActualBuffers,lplpSurface)	\
    (This)->lpVtbl -> AllocateSurface(This,dwUserID,lpAllocInfo,lpdwActualBuffers,lplpSurface)

// public\sdk\inc\strsafe.h
#define STRSAFE_E_INSUFFICIENT_BUFFER       ((HRESULT)0x8007007AL)  // 0x7A = 122L = ERROR_INSUFFICIENT_BUFFER

// public\sdk\inc\syncmgr.h
#define ISyncMgrSynchronize_Initialize(This,dwReserved,dwSyncMgrFlags,cbCookie,lpCookie)	\
    (This)->lpVtbl -> Initialize(This,dwReserved,dwSyncMgrFlags,cbCookie,lpCookie)
#define ISyncMgrSynchronize_PrepareForSync(This,cbNumItems,pItemIDs,hWndParent,dwReserved)	\
    (This)->lpVtbl -> PrepareForSync(This,cbNumItems,pItemIDs,hWndParent,dwReserved)
#define ISyncMgrSynchronize_ShowError(This,hWndParent,ErrorID,pcbNumItems,ppItemIDs)	\
    (This)->lpVtbl -> ShowError(This,hWndParent,ErrorID,pcbNumItems,ppItemIDs)
#define ISyncMgrSynchronizeInvoke_UpdateItems(This,dwInvokeFlags,rclsid,cbCookie,lpCookie)	\
    (This)->lpVtbl -> UpdateItems(This,dwInvokeFlags,rclsid,cbCookie,lpCookie)
#define ISyncSchedule_GetConnection(This,pcbSize,pwszConnectionName,pdwConnType)	\
    (This)->lpVtbl -> GetConnection(This,pcbSize,pwszConnectionName,pdwConnType)
#define ISyncSchedule_GetScheduleName(This,pcbSize,pwszScheduleName)	\
    (This)->lpVtbl -> GetScheduleName(This,pcbSize,pwszScheduleName)
#define ISyncSchedule_GetAccountInformation(This,pcbSize,pwszAccountName)	\
    (This)->lpVtbl -> GetAccountInformation(This,pcbSize,pwszAccountName)

// public\sdk\inc\sysmgmt.h
#define IAlertTarget_Report(This,cbReportSize,pbReport)	\
    (This)->lpVtbl -> Report(This,cbReportSize,pbReport)

// public\sdk\inc\tapi3.h
#define ITAllocatorProperties_SetAllocateBuffers(This,bAllocBuffers)	\
    (This)->lpVtbl -> SetAllocateBuffers(This,bAllocBuffers)
#define ITAllocatorProperties_GetAllocateBuffers(This,pbAllocBuffers)	\
    (This)->lpVtbl -> GetAllocateBuffers(This,pbAllocBuffers)
#define ITAllocatorProperties_SetBufferSize(This,BufferSize)	\
    (This)->lpVtbl -> SetBufferSize(This,BufferSize)
#define ITAllocatorProperties_GetBufferSize(This,pBufferSize)	\
    (This)->lpVtbl -> GetBufferSize(This,pBufferSize)
#define ITMSPAddress_ReceiveTSPData(This,pMSPCall,pBuffer,dwSize)	\
    (This)->lpVtbl -> ReceiveTSPData(This,pMSPCall,pBuffer,dwSize)
#define ITMSPAddress_GetEvent(This,pdwSize,pEventBuffer)	\
    (This)->lpVtbl -> GetEvent(This,pdwSize,pEventBuffer)

// public\sdk\inc\tapi3ds.h
#define ITAllocatorProperties_SetAllocateBuffers(This,bAllocBuffers)	\
    (This)->lpVtbl -> SetAllocateBuffers(This,bAllocBuffers)
#define ITAllocatorProperties_GetAllocateBuffers(This,pbAllocBuffers)	\
    (This)->lpVtbl -> GetAllocateBuffers(This,pbAllocBuffers)
#define ITAllocatorProperties_SetBufferSize(This,BufferSize)	\
    (This)->lpVtbl -> SetBufferSize(This,BufferSize)
#define ITAllocatorProperties_GetBufferSize(This,pBufferSize)	\
    (This)->lpVtbl -> GetBufferSize(This,pBufferSize)

// public\sdk\inc\tapi3if.h
#define ITPhone_GetPhoneCapsBuffer(This,pcbCaps,pdwSize,ppPhoneCapsBuffer)	\
    (This)->lpVtbl -> GetPhoneCapsBuffer(This,pcbCaps,pdwSize,ppPhoneCapsBuffer)
#define ITPhone_get_PhoneCapsBuffer(This,pcbCaps,pVarBuffer)	\
    (This)->lpVtbl -> get_PhoneCapsBuffer(This,pcbCaps,pVarBuffer)
#define ITCallInfo_get_CallInfoBuffer(This,CallInfoBuffer,ppCallInfoBuffer)	\
    (This)->lpVtbl -> get_CallInfoBuffer(This,CallInfoBuffer,ppCallInfoBuffer)
#define ITCallInfo_put_CallInfoBuffer(This,CallInfoBuffer,pCallInfoBuffer)	\
    (This)->lpVtbl -> put_CallInfoBuffer(This,CallInfoBuffer,pCallInfoBuffer)
#define ITCallInfo_GetCallInfoBuffer(This,CallInfoBuffer,pdwSize,ppCallInfoBuffer)	\
    (This)->lpVtbl -> GetCallInfoBuffer(This,CallInfoBuffer,pdwSize,ppCallInfoBuffer)
#define ITCallInfo_SetCallInfoBuffer(This,CallInfoBuffer,dwSize,pCallInfoBuffer)	\
    (This)->lpVtbl -> SetCallInfoBuffer(This,CallInfoBuffer,dwSize,pCallInfoBuffer)
#define ITCallInfo2_get_CallInfoBuffer(This,CallInfoBuffer,ppCallInfoBuffer)	\
    (This)->lpVtbl -> get_CallInfoBuffer(This,CallInfoBuffer,ppCallInfoBuffer)
#define ITCallInfo2_put_CallInfoBuffer(This,CallInfoBuffer,pCallInfoBuffer)	\
    (This)->lpVtbl -> put_CallInfoBuffer(This,CallInfoBuffer,pCallInfoBuffer)
#define ITCallInfo2_GetCallInfoBuffer(This,CallInfoBuffer,pdwSize,ppCallInfoBuffer)	\
    (This)->lpVtbl -> GetCallInfoBuffer(This,CallInfoBuffer,pdwSize,ppCallInfoBuffer)
#define ITCallInfo2_SetCallInfoBuffer(This,CallInfoBuffer,dwSize,pCallInfoBuffer)	\
    (This)->lpVtbl -> SetCallInfoBuffer(This,CallInfoBuffer,dwSize,pCallInfoBuffer)
#define ITMediaRecord_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITMediaRecord_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITMediaRecord_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITMediaRecord_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ITMediaRecord_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ITMediaRecord_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ITMediaRecord_put_FileName(This,bstrFileName)	\
    (This)->lpVtbl -> put_FileName(This,bstrFileName)
#define ITMediaRecord_get_FileName(This,pbstrFileName)	\
    (This)->lpVtbl -> get_FileName(This,pbstrFileName)
#define ITScriptableAudioFormat_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITScriptableAudioFormat_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITScriptableAudioFormat_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITScriptableAudioFormat_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ITScriptableAudioFormat_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ITScriptableAudioFormat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ITScriptableAudioFormat_get_Channels(This,pVal)	\
    (This)->lpVtbl -> get_Channels(This,pVal)
#define ITScriptableAudioFormat_put_Channels(This,nNewVal)	\
    (This)->lpVtbl -> put_Channels(This,nNewVal)
#define ITScriptableAudioFormat_get_SamplesPerSec(This,pVal)	\
    (This)->lpVtbl -> get_SamplesPerSec(This,pVal)
#define ITScriptableAudioFormat_put_SamplesPerSec(This,nNewVal)	\
    (This)->lpVtbl -> put_SamplesPerSec(This,nNewVal)
#define ITScriptableAudioFormat_get_BitsPerSample(This,pVal)	\
    (This)->lpVtbl -> get_BitsPerSample(This,pVal)
#define ITScriptableAudioFormat_put_BitsPerSample(This,nNewVal)	\
    (This)->lpVtbl -> put_BitsPerSample(This,nNewVal)
#define ITScriptableAudioFormat_get_FormatTag(This,pVal)	\
    (This)->lpVtbl -> get_FormatTag(This,pVal)
#define ITScriptableAudioFormat_put_FormatTag(This,nNewVal)	\
    (This)->lpVtbl -> put_FormatTag(This,nNewVal)

// public\sdk\inc\textstor.h
#define ITextStoreACP_QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)	\
    (This)->lpVtbl -> QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)
#define ITextStoreAnchor_QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)	\
    (This)->lpVtbl -> QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)

// public\sdk\inc\tuple.h
#define DeviceSpeedField(X)  (X & DSPEED_MASK)
#define ConfigEntryNumber(X) (X & 0x3f)

// public\sdk\inc\txcoord.h
#define ITransactionExportFactory_Create(This,cbWhereabouts,rgbWhereabouts,ppExport)	\
    (This)->lpVtbl -> Create(This,cbWhereabouts,rgbWhereabouts,ppExport)
#define ITransactionImportWhereabouts_GetWhereaboutsSize(This,pcbWhereabouts)	\
    (This)->lpVtbl -> GetWhereaboutsSize(This,pcbWhereabouts)
#define ITransactionImportWhereabouts_GetWhereabouts(This,cbWhereabouts,rgbWhereabouts,pcbUsed)	\
    (This)->lpVtbl -> GetWhereabouts(This,cbWhereabouts,rgbWhereabouts,pcbUsed)
#define ITransactionExport_Export(This,punkTransaction,pcbTransactionCookie)	\
    (This)->lpVtbl -> Export(This,punkTransaction,pcbTransactionCookie)
#define ITransactionExport_GetTransactionCookie(This,punkTransaction,cbTransactionCookie,rgbTransactionCookie,pcbUsed)	\
    (This)->lpVtbl -> GetTransactionCookie(This,punkTransaction,cbTransactionCookie,rgbTransactionCookie,pcbUsed)
#define ITransactionImport_Import(This,cbTransactionCookie,rgbTransactionCookie,piid,ppvTransaction)	\
    (This)->lpVtbl -> Import(This,cbTransactionCookie,rgbTransactionCookie,piid,ppvTransaction)

// public\sdk\inc\txdtc.h
#define ILastResourceManager_TransactionCommitted(This,pPrepInfo,cbPrepInfo)	\
    (This)->lpVtbl -> TransactionCommitted(This,pPrepInfo,cbPrepInfo)
#define IPrepareInfo_GetPrepareInfoSize(This,pcbPrepInfo)	\
    (This)->lpVtbl -> GetPrepareInfoSize(This,pcbPrepInfo)
#define IPrepareInfo2_GetPrepareInfoSize(This,pcbPrepInfo)	\
    (This)->lpVtbl -> GetPrepareInfoSize(This,pcbPrepInfo)
#define IPrepareInfo2_GetPrepareInfo(This,cbPrepareInfo,pPrepInfo)	\
    (This)->lpVtbl -> GetPrepareInfo(This,cbPrepareInfo,pPrepInfo)
#define ITransactionTransmitter_GetPropagationTokenSize(This,pcbToken)	\
    (This)->lpVtbl -> GetPropagationTokenSize(This,pcbToken)
#define ITransactionTransmitter_MarshalPropagationToken(This,cbToken,rgbToken,pcbUsed)	\
    (This)->lpVtbl -> MarshalPropagationToken(This,cbToken,rgbToken,pcbUsed)
#define ITransactionTransmitter_UnmarshalReturnToken(This,cbReturnToken,rgbReturnToken)	\
    (This)->lpVtbl -> UnmarshalReturnToken(This,cbReturnToken,rgbReturnToken)
#define ITransactionReceiver_GetReturnTokenSize(This,pcbReturnToken)	\
    (This)->lpVtbl -> GetReturnTokenSize(This,pcbReturnToken)
#define ITransactionReceiver_MarshalReturnToken(This,cbReturnToken,rgbReturnToken,pcbUsed)	\
    (This)->lpVtbl -> MarshalReturnToken(This,cbReturnToken,rgbReturnToken,pcbUsed)
#define IDtcLuConfigure_Add(This,pucLuPair,cbLuPair)	\
    (This)->lpVtbl -> Add(This,pucLuPair,cbLuPair)
#define IDtcLuConfigure_Delete(This,pucLuPair,cbLuPair)	\
    (This)->lpVtbl -> Delete(This,pucLuPair,cbLuPair)
#define IDtcLuRecoveryFactory_Create(This,pucLuPair,cbLuPair,ppRecovery)	\
    (This)->lpVtbl -> Create(This,pucLuPair,cbLuPair,ppRecovery)
#define IDtcLuRecoveryInitiatedByDtcTransWork_GetLogNameSizes(This,pcbOurLogName,pcbRemoteLogName)	\
    (This)->lpVtbl -> GetLogNameSizes(This,pcbOurLogName,pcbRemoteLogName)
#define IDtcLuRecoveryInitiatedByDtcTransWork_HandleTheirXlnResponse(This,Xln,pRemoteLogName,cbRemoteLogName,dwProtocol,pConfirmation)	\
    (This)->lpVtbl -> HandleTheirXlnResponse(This,Xln,pRemoteLogName,cbRemoteLogName,dwProtocol,pConfirmation)
#define IDtcLuRecoveryInitiatedByDtcTransWork_GetOurTransIdSize(This,pcbOurTransId)	\
    (This)->lpVtbl -> GetOurTransIdSize(This,pcbOurTransId)
#define IDtcLuRecoveryInitiatedByLuWork_HandleTheirXln(This,lRecoverySeqNum,Xln,pRemoteLogName,cbRemoteLogName,pOurLogName,cbOurLogName,dwProtocol,pResponse)	\
    (This)->lpVtbl -> HandleTheirXln(This,lRecoverySeqNum,Xln,pRemoteLogName,cbRemoteLogName,pOurLogName,cbOurLogName,dwProtocol,pResponse)
#define IDtcLuRecoveryInitiatedByLuWork_GetOurLogNameSize(This,pcbOurLogName)	\
    (This)->lpVtbl -> GetOurLogNameSize(This,pcbOurLogName)
#define IDtcLuRecoveryInitiatedByLuWork_HandleTheirCompareStates(This,pRemoteTransId,cbRemoteTransId,CompareState,pResponse,pCompareState)	\
    (This)->lpVtbl -> HandleTheirCompareStates(This,pRemoteTransId,cbRemoteTransId,CompareState,pResponse,pCompareState)

// public\sdk\inc\urlmki.h
#define IHttpNegotiate2_GetRootSecurityId(This,pbSecurityId,pcbSecurityId,dwReserved)	\
    (This)->lpVtbl -> GetRootSecurityId(This,pbSecurityId,pcbSecurityId,dwReserved)
#define IWinInetInfo_QueryOption(This,dwOption,pBuffer,pcbBuf)	\
    (This)->lpVtbl -> QueryOption(This,dwOption,pBuffer,pcbBuf)
#define IWinInetHttpInfo_QueryOption(This,dwOption,pBuffer,pcbBuf)	\
    (This)->lpVtbl -> QueryOption(This,dwOption,pBuffer,pcbBuf)
#define IWinInetHttpInfo_QueryInfo(This,dwOption,pBuffer,pcbBuf,pdwFlags,pdwReserved)	\
    (This)->lpVtbl -> QueryInfo(This,dwOption,pBuffer,pcbBuf,pdwFlags,pdwReserved)
#define IInternetProtocol_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define IInternetSession_SetSessionOption(This,dwOption,pBuffer,dwBufferLength,dwReserved)	\
    (This)->lpVtbl -> SetSessionOption(This,dwOption,pBuffer,dwBufferLength,dwReserved)
#define IInternetSession_GetSessionOption(This,dwOption,pBuffer,pdwBufferLength,dwReserved)	\
    (This)->lpVtbl -> GetSessionOption(This,dwOption,pBuffer,pdwBufferLength,dwReserved)
#define IInternetProtocolInfo_QueryInfo(This,pwzUrl,OueryOption,dwQueryFlags,pBuffer,cbBuffer,pcbBuf,dwReserved)	\
    (This)->lpVtbl -> QueryInfo(This,pwzUrl,OueryOption,dwQueryFlags,pBuffer,cbBuffer,pcbBuf,dwReserved)
#define IInternetSecurityManager_GetSecurityId(This,pwszUrl,pbSecurityId,pcbSecurityId,dwReserved)	\
    (This)->lpVtbl -> GetSecurityId(This,pwszUrl,pbSecurityId,pcbSecurityId,dwReserved)
#define IInternetSecurityManager_ProcessUrlAction(This,pwszUrl,dwAction,pPolicy,cbPolicy,pContext,cbContext,dwFlags,dwReserved)	\
    (This)->lpVtbl -> ProcessUrlAction(This,pwszUrl,dwAction,pPolicy,cbPolicy,pContext,cbContext,dwFlags,dwReserved)
#define IInternetSecurityManager_QueryCustomPolicy(This,pwszUrl,guidKey,ppPolicy,pcbPolicy,pContext,cbContext,dwReserved)	\
    (This)->lpVtbl -> QueryCustomPolicy(This,pwszUrl,guidKey,ppPolicy,pcbPolicy,pContext,cbContext,dwReserved)
#define IInternetHostSecurityManager_GetSecurityId(This,pbSecurityId,pcbSecurityId,dwReserved)	\
    (This)->lpVtbl -> GetSecurityId(This,pbSecurityId,pcbSecurityId,dwReserved)
#define IInternetHostSecurityManager_ProcessUrlAction(This,dwAction,pPolicy,cbPolicy,pContext,cbContext,dwFlags,dwReserved)	\
    (This)->lpVtbl -> ProcessUrlAction(This,dwAction,pPolicy,cbPolicy,pContext,cbContext,dwFlags,dwReserved)
#define IInternetHostSecurityManager_QueryCustomPolicy(This,guidKey,ppPolicy,pcbPolicy,pContext,cbContext,dwReserved)	\
    (This)->lpVtbl -> QueryCustomPolicy(This,guidKey,ppPolicy,pcbPolicy,pContext,cbContext,dwReserved)
#define IInternetZoneManager_GetZoneCustomPolicy(This,dwZone,guidKey,ppPolicy,pcbPolicy,urlZoneReg)	\
    (This)->lpVtbl -> GetZoneCustomPolicy(This,dwZone,guidKey,ppPolicy,pcbPolicy,urlZoneReg)
#define IInternetZoneManager_SetZoneCustomPolicy(This,dwZone,guidKey,pPolicy,cbPolicy,urlZoneReg)	\
    (This)->lpVtbl -> SetZoneCustomPolicy(This,dwZone,guidKey,pPolicy,cbPolicy,urlZoneReg)
#define IInternetZoneManager_GetZoneActionPolicy(This,dwZone,dwAction,pPolicy,cbPolicy,urlZoneReg)	\
    (This)->lpVtbl -> GetZoneActionPolicy(This,dwZone,dwAction,pPolicy,cbPolicy,urlZoneReg)
#define IInternetZoneManager_SetZoneActionPolicy(This,dwZone,dwAction,pPolicy,cbPolicy,urlZoneReg)	\
    (This)->lpVtbl -> SetZoneActionPolicy(This,dwZone,dwAction,pPolicy,cbPolicy,urlZoneReg)
#define ISoftDistExt_AsyncInstallDistributionUnit(This,pbc,pvReserved,flags,lpcbh)	\
    (This)->lpVtbl -> AsyncInstallDistributionUnit(This,pbc,pvReserved,flags,lpcbh)
#define IDataFilter_DoEncode(This,dwFlags,lInBufferSize,pbInBuffer,lOutBufferSize,pbOutBuffer,lInBytesAvailable,plInBytesRead,plOutBytesWritten,dwReserved)	\
    (This)->lpVtbl -> DoEncode(This,dwFlags,lInBufferSize,pbInBuffer,lOutBufferSize,pbOutBuffer,lInBytesAvailable,plInBytesRead,plOutBytesWritten,dwReserved)
#define IDataFilter_DoDecode(This,dwFlags,lInBufferSize,pbInBuffer,lOutBufferSize,pbOutBuffer,lInBytesAvailable,plInBytesRead,plOutBytesWritten,dwReserved)	\
    (This)->lpVtbl -> DoDecode(This,dwFlags,lInBufferSize,pbInBuffer,lOutBufferSize,pbOutBuffer,lInBytesAvailable,plInBytesRead,plOutBytesWritten,dwReserved)
#define IInternetBindClient_GetClassFileOrMime(This,pBC,szFilename,pBuffer,cbSize,szMime,dwReserved,pclsid)	\
    (This)->lpVtbl -> GetClassFileOrMime(This,pBC,szFilename,pBuffer,cbSize,szMime,dwReserved,pclsid)
#define IInternetBindClient_FindMimeFromData(This,pBC,szFilename,pBuffer,cbSize,szMime,pwzResult,cchResult,pcchResult,dwReserved)	\
    (This)->lpVtbl -> FindMimeFromData(This,pBC,szFilename,pBuffer,cbSize,szMime,pwzResult,cchResult,pcchResult,dwReserved)

// public\sdk\inc\urlmon.h
#define IHttpNegotiate2_GetRootSecurityId(This,pbSecurityId,pcbSecurityId,dwReserved)	\
    (This)->lpVtbl -> GetRootSecurityId(This,pbSecurityId,pcbSecurityId,dwReserved)
#define IWinInetInfo_QueryOption(This,dwOption,pBuffer,pcbBuf)	\
    (This)->lpVtbl -> QueryOption(This,dwOption,pBuffer,pcbBuf)
#define IWinInetHttpInfo_QueryOption(This,dwOption,pBuffer,pcbBuf)	\
    (This)->lpVtbl -> QueryOption(This,dwOption,pBuffer,pcbBuf)
#define IWinInetHttpInfo_QueryInfo(This,dwOption,pBuffer,pcbBuf,pdwFlags,pdwReserved)	\
    (This)->lpVtbl -> QueryInfo(This,dwOption,pBuffer,pcbBuf,pdwFlags,pdwReserved)
#define IInternetProtocol_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define IInternetSession_SetSessionOption(This,dwOption,pBuffer,dwBufferLength,dwReserved)	\
    (This)->lpVtbl -> SetSessionOption(This,dwOption,pBuffer,dwBufferLength,dwReserved)
#define IInternetSession_GetSessionOption(This,dwOption,pBuffer,pdwBufferLength,dwReserved)	\
    (This)->lpVtbl -> GetSessionOption(This,dwOption,pBuffer,pdwBufferLength,dwReserved)
#define IInternetProtocolInfo_QueryInfo(This,pwzUrl,OueryOption,dwQueryFlags,pBuffer,cbBuffer,pcbBuf,dwReserved)	\
    (This)->lpVtbl -> QueryInfo(This,pwzUrl,OueryOption,dwQueryFlags,pBuffer,cbBuffer,pcbBuf,dwReserved)
#define IInternetSecurityManager_GetSecurityId(This,pwszUrl,pbSecurityId,pcbSecurityId,dwReserved)	\
    (This)->lpVtbl -> GetSecurityId(This,pwszUrl,pbSecurityId,pcbSecurityId,dwReserved)
#define IInternetSecurityManager_ProcessUrlAction(This,pwszUrl,dwAction,pPolicy,cbPolicy,pContext,cbContext,dwFlags,dwReserved)	\
    (This)->lpVtbl -> ProcessUrlAction(This,pwszUrl,dwAction,pPolicy,cbPolicy,pContext,cbContext,dwFlags,dwReserved)
#define IInternetSecurityManager_QueryCustomPolicy(This,pwszUrl,guidKey,ppPolicy,pcbPolicy,pContext,cbContext,dwReserved)	\
    (This)->lpVtbl -> QueryCustomPolicy(This,pwszUrl,guidKey,ppPolicy,pcbPolicy,pContext,cbContext,dwReserved)
#define IInternetHostSecurityManager_GetSecurityId(This,pbSecurityId,pcbSecurityId,dwReserved)	\
    (This)->lpVtbl -> GetSecurityId(This,pbSecurityId,pcbSecurityId,dwReserved)
#define IInternetHostSecurityManager_ProcessUrlAction(This,dwAction,pPolicy,cbPolicy,pContext,cbContext,dwFlags,dwReserved)	\
    (This)->lpVtbl -> ProcessUrlAction(This,dwAction,pPolicy,cbPolicy,pContext,cbContext,dwFlags,dwReserved)
#define IInternetHostSecurityManager_QueryCustomPolicy(This,guidKey,ppPolicy,pcbPolicy,pContext,cbContext,dwReserved)	\
    (This)->lpVtbl -> QueryCustomPolicy(This,guidKey,ppPolicy,pcbPolicy,pContext,cbContext,dwReserved)
#define IInternetZoneManager_GetZoneCustomPolicy(This,dwZone,guidKey,ppPolicy,pcbPolicy,urlZoneReg)	\
    (This)->lpVtbl -> GetZoneCustomPolicy(This,dwZone,guidKey,ppPolicy,pcbPolicy,urlZoneReg)
#define IInternetZoneManager_SetZoneCustomPolicy(This,dwZone,guidKey,pPolicy,cbPolicy,urlZoneReg)	\
    (This)->lpVtbl -> SetZoneCustomPolicy(This,dwZone,guidKey,pPolicy,cbPolicy,urlZoneReg)
#define IInternetZoneManager_GetZoneActionPolicy(This,dwZone,dwAction,pPolicy,cbPolicy,urlZoneReg)	\
    (This)->lpVtbl -> GetZoneActionPolicy(This,dwZone,dwAction,pPolicy,cbPolicy,urlZoneReg)
#define IInternetZoneManager_SetZoneActionPolicy(This,dwZone,dwAction,pPolicy,cbPolicy,urlZoneReg)	\
    (This)->lpVtbl -> SetZoneActionPolicy(This,dwZone,dwAction,pPolicy,cbPolicy,urlZoneReg)
#define ISoftDistExt_AsyncInstallDistributionUnit(This,pbc,pvReserved,flags,lpcbh)	\
    (This)->lpVtbl -> AsyncInstallDistributionUnit(This,pbc,pvReserved,flags,lpcbh)
#define IDataFilter_DoEncode(This,dwFlags,lInBufferSize,pbInBuffer,lOutBufferSize,pbOutBuffer,lInBytesAvailable,plInBytesRead,plOutBytesWritten,dwReserved)	\
    (This)->lpVtbl -> DoEncode(This,dwFlags,lInBufferSize,pbInBuffer,lOutBufferSize,pbOutBuffer,lInBytesAvailable,plInBytesRead,plOutBytesWritten,dwReserved)
#define IDataFilter_DoDecode(This,dwFlags,lInBufferSize,pbInBuffer,lOutBufferSize,pbOutBuffer,lInBytesAvailable,plInBytesRead,plOutBytesWritten,dwReserved)	\
    (This)->lpVtbl -> DoDecode(This,dwFlags,lInBufferSize,pbInBuffer,lOutBufferSize,pbOutBuffer,lInBytesAvailable,plInBytesRead,plOutBytesWritten,dwReserved)

// public\sdk\inc\usbdi.h
#define USBD_PF_VALID_MASK    (USBD_PF_CHANGE_MAX_PACKET | \
                               USBD_PF_DOUBLE_BUFFER | \
                               USBD_PF_ENABLE_RT_THREAD_ACCESS | \
                               USBD_PF_MAP_ADD_TRANSFERS)

// public\sdk\inc\vfw.h
#define ICM_DECOMPRESS_SET_PALETTE  (ICM_USER+29)   // fill in the DIB color table
#define ICM_DECOMPRESS_GET_PALETTE  (ICM_USER+30)   // fill in the DIB color table
#define ICDrawRenderBuffer(hic) \
    ICSendMessage(hic, ICM_DRAW_RENDERBUFFER, 0, 0)
#define MCIWNDM_CAN_RECORD      (WM_USER + 146)

// public\sdk\inc\vfwmsgs.h
#define VFW_E_NO_ACCEPTABLE_TYPES        ((HRESULT)0x80040207L)
#define VFW_E_BUFFER_NOTSET              ((HRESULT)0x8004020CL)
#define VFW_E_BUFFER_OVERFLOW            ((HRESULT)0x8004020DL)
#define VFW_E_BUFFERS_OUTSTANDING        ((HRESULT)0x80040210L)
#define VFW_E_PROCESSOR_NOT_SUITABLE     ((HRESULT)0x8004025BL)
#define VFW_E_BUFFER_UNDERFLOW           ((HRESULT)0x80040264L)
#define VFW_E_DDRAW_CAPS_NOT_SUITABLE    ((HRESULT)0x80040273L)
#define VFW_E_DDRAW_VERSION_NOT_SUITABLE ((HRESULT)0x8004027CL)

// public\sdk\inc\videoacc.h
#define IAMVideoAcceleratorNotify_GetUncompSurfacesInfo(This,pGuid,pUncompBufferInfo)	\
    (This)->lpVtbl -> GetUncompSurfacesInfo(This,pGuid,pUncompBufferInfo)
#define IAMVideoAccelerator_GetCompBufferInfo(This,pGuid,pamvaUncompDataInfo,pdwNumTypesCompBuffers,pamvaCompBufferInfo)	\
    (This)->lpVtbl -> GetCompBufferInfo(This,pGuid,pamvaUncompDataInfo,pdwNumTypesCompBuffers,pamvaCompBufferInfo)
#define IAMVideoAccelerator_GetInternalCompBufferInfo(This,pdwNumTypesCompBuffers,pamvaCompBufferInfo)	\
    (This)->lpVtbl -> GetInternalCompBufferInfo(This,pdwNumTypesCompBuffers,pamvaCompBufferInfo)
#define IAMVideoAccelerator_GetBuffer(This,dwTypeIndex,dwBufferIndex,bReadOnly,ppBuffer,lpStride)	\
    (This)->lpVtbl -> GetBuffer(This,dwTypeIndex,dwBufferIndex,bReadOnly,ppBuffer,lpStride)
#define IAMVideoAccelerator_ReleaseBuffer(This,dwTypeIndex,dwBufferIndex)	\
    (This)->lpVtbl -> ReleaseBuffer(This,dwTypeIndex,dwBufferIndex)
#define IAMVideoAccelerator_Execute(This,dwFunction,lpPrivateInputData,cbPrivateInputData,lpPrivateOutputDat,cbPrivateOutputData,dwNumBuffers,pamvaBufferInfo)	\
    (This)->lpVtbl -> Execute(This,dwFunction,lpPrivateInputData,cbPrivateInputData,lpPrivateOutputDat,cbPrivateOutputData,dwNumBuffers,pamvaBufferInfo)
#define IAMVideoAccelerator_QueryRenderStatus(This,dwTypeIndex,dwBufferIndex,dwFlags)	\
    (This)->lpVtbl -> QueryRenderStatus(This,dwTypeIndex,dwBufferIndex,dwFlags)

// public\sdk\inc\vsbackup.h
#define VSS_SW_BOOTABLE_STATE	(1 << 0)

// public\sdk\inc\wabdefs.h
#define MAPI_IPROVIDERADMIN_METHODS(IPURE)                              \
    MAPIMETHOD(GetLastError)                                            \
        (THIS_  HRESULT                     hResult,                    \
                ULONG                       ulFlags,                    \
                LPMAPIERROR FAR *           lppMAPIError) IPURE;        \
    MAPIMETHOD(GetProviderTable)                                        \
        (THIS_  ULONG                       ulFlags,                    \
                LPMAPITABLE FAR *           lppTable) IPURE;            \
    MAPIMETHOD(CreateProvider)                                          \
        (THIS_  LPTSTR                      lpszProvider,               \
                ULONG                       cValues,                    \
                LPSPropValue                lpProps,                    \
                ULONG                       ulUIParam,                  \
                ULONG                       ulFlags,                    \
                MAPIUID FAR *               lpUID) IPURE;               \
    MAPIMETHOD(DeleteProvider)                                          \
        (THIS_  LPMAPIUID                   lpUID) IPURE;               \
    MAPIMETHOD(OpenProfileSection)                                      \
        (THIS_  LPMAPIUID                   lpUID,                      \
                LPCIID                      lpInterface,                \
                ULONG                       ulFlags,                    \
                LPPROFSECT FAR *            lppProfSect) IPURE;         \

// public\sdk\inc\wabtags.h
#define FIsTransmittable(ulPropTag) \
    ((PROP_ID (ulPropTag) <  (ULONG)0x0E00) || \
    (PROP_ID (ulPropTag)  >= (ULONG)0x8000) || \
    ((PROP_ID (ulPropTag) >= (ULONG)0x1000) && (PROP_ID (ulPropTag) < (ULONG)0x6000)) || \
    ((PROP_ID (ulPropTag) >= (ULONG)0x6800) && (PROP_ID (ulPropTag) < (ULONG)0x7C00)))

// public\sdk\inc\wabutil.h
#define MAPI_ITABLEDATA_METHODS(IPURE)									\
	MAPIMETHOD(HrGetView)												\
		(THIS_	LPSSortOrderSet				lpSSortOrderSet,			\
				CALLERRELEASE FAR *			lpfCallerRelease,			\
				ULONG						ulCallerData,				\
				LPMAPITABLE FAR *			lppMAPITable) IPURE;		\
	MAPIMETHOD(HrModifyRow)												\
		(THIS_	LPSRow) IPURE;											\
	MAPIMETHOD(HrDeleteRow)												\
		(THIS_	LPSPropValue				lpSPropValue) IPURE;		\
	MAPIMETHOD(HrQueryRow)												\
		(THIS_	LPSPropValue				lpsPropValue,				\
				LPSRow FAR *				lppSRow,					\
				ULONG FAR *					lpuliRow) IPURE;			\
	MAPIMETHOD(HrEnumRow)												\
		(THIS_	ULONG						ulRowNumber,				\
				LPSRow FAR *				lppSRow) IPURE;				\
	MAPIMETHOD(HrNotify)												\
		(THIS_	ULONG						ulFlags,					\
				ULONG						cValues,					\
				LPSPropValue				lpSPropValue) IPURE;		\
	MAPIMETHOD(HrInsertRow)												\
		(THIS_	ULONG						uliRow,						\
				LPSRow						lpSRow) IPURE;				\
	MAPIMETHOD(HrModifyRows)											\
		(THIS_	ULONG						ulFlags,					\
				LPSRowSet					lpSRowSet) IPURE;			\
	MAPIMETHOD(HrDeleteRows)											\
		(THIS_	ULONG						ulFlags,					\
				LPSRowSet					lprowsetToDelete,			\
				ULONG FAR *					cRowsDeleted) IPURE;		\

// public\sdk\inc\wbemcli.h
#define IWbemObjectAccess_ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData)	\
    (This)->lpVtbl -> ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData)
#define IMofCompiler_CompileBuffer(This,BuffSize,pBuffer,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo)	\
    (This)->lpVtbl -> CompileBuffer(This,BuffSize,pBuffer,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo)

// public\sdk\inc\wbemint.h
#define IWbemSmartMultiTarget_DeliverEvent(This,dwNumEvents,dwBuffSize,pBuffer,pTargets)	\
    (This)->lpVtbl -> DeliverEvent(This,dwNumEvents,dwBuffSize,pBuffer,pTargets)
#define IWinmgmtMofCompiler_WinmgmtCompileBuffer(This,BuffSize,pBuffer,lOptionFlags,lClassFlags,lInstanceFlags,pOverride,pCtx,pInfo)	\
    (This)->lpVtbl -> WinmgmtCompileBuffer(This,BuffSize,pBuffer,lOptionFlags,lClassFlags,lInstanceFlags,pOverride,pCtx,pInfo)

// public\sdk\inc\wbemprov.h
#define IWbemEventSink_SetBatchingParameters(This,lFlags,dwMaxBufferSize,dwMaxSendLatency)	\
    (This)->lpVtbl -> SetBatchingParameters(This,lFlags,dwMaxBufferSize,dwMaxSendLatency)

// public\sdk\inc\wbemtran.h
#define IWbemConstructClassObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IWbemConstructClassObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IWbemConstructClassObject_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IWbemConstructClassObject_SetInheritanceChain(This,lNumAntecedents,awszAntecedents)	\
    (This)->lpVtbl -> SetInheritanceChain(This,lNumAntecedents,awszAntecedents)
#define IWbemConstructClassObject_SetPropertyOrigin(This,wszPropertyName,lOriginIndex)	\
    (This)->lpVtbl -> SetPropertyOrigin(This,wszPropertyName,lOriginIndex)
#define IWbemConstructClassObject_SetMethodOrigin(This,wszMethodName,lOriginIndex)	\
    (This)->lpVtbl -> SetMethodOrigin(This,wszMethodName,lOriginIndex)
#define IWbemConstructClassObject_SetServerNamespace(This,wszServer,wszNamespace)	\
    (This)->lpVtbl -> SetServerNamespace(This,wszServer,wszNamespace)

// public\sdk\inc\wdm.h
#define RtlInitEmptyUnicodeString(_ucStr,_buf,_bufSize) \
    ((_ucStr)->Buffer = (_buf), \
     (_ucStr)->Length = 0, \
     (_ucStr)->MaximumLength = (USHORT)(_bufSize))
#define RtlCheckBit(BMH,BP) ((((BMH)->Buffer[(BP) / 32]) >> ((BP) % 32)) & 0x1)
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
#define KeInitializeCallbackRecord(CallbackRecord) \
    (CallbackRecord)->State = BufferEmpty

// public\sdk\inc\wia.h
#define IWiaItem_Diagnostic(This,ulSize,pBuffer)	\
    (This)->lpVtbl -> Diagnostic(This,ulSize,pBuffer)
#define IWiaItemExtras_Escape(This,dwEscapeCode,lpInData,cbInDataSize,pOutData,dwOutDataSize,pdwActualDataSize)	\
    (This)->lpVtbl -> Escape(This,dwEscapeCode,lpInData,cbInDataSize,pOutData,dwOutDataSize,pdwActualDataSize)

// public\sdk\inc\wincrypt.h
#define GET_CERT_ALT_NAME_ENTRY_ERR_INDEX(X)   \
    ((X >> CERT_ALT_NAME_ENTRY_ERR_INDEX_SHIFT) & \
    CERT_ALT_NAME_ENTRY_ERR_INDEX_MASK)

// public\sdk\inc\windns.h
#define DNS_RRSET_INIT( rrset )                 \
        {                                       \
            PDNS_RRSET  _prrset = &(rrset);     \
            _prrset->pFirstRR = NULL;           \
            _prrset->pLastRR = (PDNS_RECORD) &_prrset->pFirstRR; \
        }

// public\sdk\inc\windowsx.h
#define HANDLE_WM_CREATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCREATESTRUCT)(lParam)) ? 0L : (LRESULT)-1L)
#define FORWARD_WM_CREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_CREATE, 0L, (LPARAM)(LPCREATESTRUCT)(lpCreateStruct))
#define HANDLE_WM_NCCREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (LPCREATESTRUCT)(lParam))
#define FORWARD_WM_NCCREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCCREATE, 0L, (LPARAM)(LPCREATESTRUCT)(lpCreateStruct))
#define HANDLE_WM_PAINTCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const LPPAINTSTRUCT)GlobalLock((HGLOBAL)(lParam))), GlobalUnlock((HGLOBAL)(lParam)), 0L)
#define FORWARD_WM_PAINTCLIPBOARD(hwnd, hwndCBViewer, lpPaintStruct, fn) \
    (void)(fn)((hwnd), WM_PAINTCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(LPPAINTSTRUCT)(lpPaintStruct))
#define FORWARD_WM_SIZECLIPBOARD(hwnd, hwndCBViewer, lprc, fn) \
    (void)(fn)((hwnd), WM_SIZECLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(LPRECT)(lprc))
#define FORWARD_WM_VSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define FORWARD_WM_HSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_ASKCBFORMATNAME(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (LPTSTR)(lParam)), 0L)
#define FORWARD_WM_ASKCBFORMATNAME(hwnd, cchMax, rgchName, fn) \
    (void)(fn)((hwnd), WM_ASKCBFORMATNAME, (WPARAM)(int)(cchMax), (LPARAM)(rgchName))
#define HANDLE_WM_CHANGECBCHAIN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (HWND)(lParam)), 0L)
#define HANDLE_WM_MDICREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (LPMDICREATESTRUCT)(lParam))
#define FORWARD_WM_MDICREATE(hwnd, lpmcs, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDICREATE, 0L, (LPARAM)(LPMDICREATESTRUCT)(lpmcs))
#define HANDLE_WM_DRAWITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DRAWITEMSTRUCT *)(lParam)), 0L)
#define FORWARD_WM_DRAWITEM(hwnd, lpDrawItem, fn) \
    (void)(fn)((hwnd), WM_DRAWITEM, (WPARAM)(((const DRAWITEMSTRUCT *)lpDrawItem)->CtlID), (LPARAM)(const DRAWITEMSTRUCT *)(lpDrawItem))
#define HANDLE_WM_MEASUREITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MEASUREITEMSTRUCT *)(lParam)), 0L)
#define FORWARD_WM_MEASUREITEM(hwnd, lpMeasureItem, fn) \
    (void)(fn)((hwnd), WM_MEASUREITEM, (WPARAM)(((MEASUREITEMSTRUCT *)lpMeasureItem)->CtlID), (LPARAM)(MEASUREITEMSTRUCT *)(lpMeasureItem))
#define HANDLE_WM_DELETEITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DELETEITEMSTRUCT *)(lParam)), 0L)
#define FORWARD_WM_DELETEITEM(hwnd, lpDeleteItem, fn) \
    (void)(fn)((hwnd), WM_DELETEITEM, (WPARAM)(((const DELETEITEMSTRUCT *)(lpDeleteItem))->CtlID), (LPARAM)(const DELETEITEMSTRUCT *)(lpDeleteItem))
#define HANDLE_WM_COMPAREITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (const COMPAREITEMSTRUCT *)(lParam))
#define FORWARD_WM_COMPAREITEM(hwnd, lpCompareItem, fn) \
    (int)(DWORD)(fn)((hwnd), WM_COMPAREITEM, (WPARAM)(((const COMPAREITEMSTRUCT *)(lpCompareItem))->CtlID), (LPARAM)(const COMPAREITEMSTRUCT *)(lpCompareItem))
#define HANDLE_WM_COPYDATA(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (PCOPYDATASTRUCT)lParam), 0L)
#define ComboBox_LimitText(hwndCtl, cchLimit)   ((int)(DWORD)SNDMSG((hwndCtl), CB_LIMITTEXT, (WPARAM)(int)(cchLimit), 0L))
#define ComboBox_GetEditSel(hwndCtl)            ((DWORD)SNDMSG((hwndCtl), CB_GETEDITSEL, 0L, 0L))
#define ComboBox_SetEditSel(hwndCtl, ichStart, ichEnd) ((int)(DWORD)SNDMSG((hwndCtl), CB_SETEDITSEL, 0L, MAKELPARAM((ichStart), (ichEnd))))
#define ComboBox_GetCount(hwndCtl)              ((int)(DWORD)SNDMSG((hwndCtl), CB_GETCOUNT, 0L, 0L))
#define ComboBox_ResetContent(hwndCtl)          ((int)(DWORD)SNDMSG((hwndCtl), CB_RESETCONTENT, 0L, 0L))
#define ComboBox_AddString(hwndCtl, lpsz)       ((int)(DWORD)SNDMSG((hwndCtl), CB_ADDSTRING, 0L, (LPARAM)(LPCTSTR)(lpsz)))
#define ComboBox_InsertString(hwndCtl, index, lpsz) ((int)(DWORD)SNDMSG((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCTSTR)(lpsz)))
#define ComboBox_AddItemData(hwndCtl, data)     ((int)(DWORD)SNDMSG((hwndCtl), CB_ADDSTRING, 0L, (LPARAM)(data)))
#define ComboBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SNDMSG((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_DeleteString(hwndCtl, index)   ((int)(DWORD)SNDMSG((hwndCtl), CB_DELETESTRING, (WPARAM)(int)(index), 0L))
#define ComboBox_GetLBTextLen(hwndCtl, index)           ((int)(DWORD)SNDMSG((hwndCtl), CB_GETLBTEXTLEN, (WPARAM)(int)(index), 0L))
#define ComboBox_GetLBText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SNDMSG((hwndCtl), CB_GETLBTEXT, (WPARAM)(int)(index), (LPARAM)(LPCTSTR)(lpszBuffer)))
#define ComboBox_SetItemData(hwndCtl, index, data)  ((int)(DWORD)SNDMSG((hwndCtl), CB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_FindString(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SNDMSG((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ComboBox_FindItemData(hwndCtl, indexStart, data)    ((int)(DWORD)SNDMSG((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_GetCurSel(hwndCtl)                 ((int)(DWORD)SNDMSG((hwndCtl), CB_GETCURSEL, 0L, 0L))
#define ComboBox_SetCurSel(hwndCtl, index)          ((int)(DWORD)SNDMSG((hwndCtl), CB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ComboBox_SelectString(hwndCtl, indexStart, lpszSelect)  ((int)(DWORD)SNDMSG((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszSelect)))
#define ComboBox_SelectItemData(hwndCtl, indexStart, data)      ((int)(DWORD)SNDMSG((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_Dir(hwndCtl, attrs, lpszFileSpec)  ((int)(DWORD)SNDMSG((hwndCtl), CB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCTSTR)(lpszFileSpec)))
#define ComboBox_ShowDropdown(hwndCtl, fShow)       ((BOOL)(DWORD)SNDMSG((hwndCtl), CB_SHOWDROPDOWN, (WPARAM)(BOOL)(fShow), 0L))
#define ComboBox_FindStringExact(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SNDMSG((hwndCtl), CB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ComboBox_GetDroppedState(hwndCtl)           ((BOOL)(DWORD)SNDMSG((hwndCtl), CB_GETDROPPEDSTATE, 0L, 0L))
#define ComboBox_GetDroppedControlRect(hwndCtl, lprc) ((void)SNDMSG((hwndCtl), CB_GETDROPPEDCONTROLRECT, 0L, (LPARAM)(RECT *)(lprc)))
#define ComboBox_GetItemHeight(hwndCtl)             ((int)(DWORD)SNDMSG((hwndCtl), CB_GETITEMHEIGHT, 0L, 0L))
#define ComboBox_SetItemHeight(hwndCtl, index, cyItem) ((int)(DWORD)SNDMSG((hwndCtl), CB_SETITEMHEIGHT, (WPARAM)(int)(index), (LPARAM)(int)cyItem))
#define ComboBox_GetExtendedUI(hwndCtl)             ((UINT)(DWORD)SNDMSG((hwndCtl), CB_GETEXTENDEDUI, 0L, 0L))
#define ComboBox_SetExtendedUI(hwndCtl, flags)      ((int)(DWORD)SNDMSG((hwndCtl), CB_SETEXTENDEDUI, (WPARAM)(UINT)(flags), 0L))

// public\sdk\inc\winerror.h
#define EVENT_E_QUERYFIELD               _HRESULT_TYPEDEF_(0x80040204L)
#define CO_E_NOTCONSTRUCTED              _HRESULT_TYPEDEF_(0x8004E02DL)
#define DISP_E_BUFFERTOOSMALL            _HRESULT_TYPEDEF_(0x80020013L)
#define TYPE_E_BUFFERTOOSMALL            _HRESULT_TYPEDEF_(0x80028016L)
#define TYPE_E_FIELDNOTFOUND             _HRESULT_TYPEDEF_(0x80028017L)
#define NTE_PROV_TYPE_ENTRY_BAD          _HRESULT_TYPEDEF_(0x80090018L)
#define NTE_KEYSET_ENTRY_BAD             _HRESULT_TYPEDEF_(0x8009001AL)
#define SEC_E_BUFFER_TOO_SMALL           _HRESULT_TYPEDEF_(0x80090321L)
#define CRYPT_E_INVALID_PRINTABLE_STRING _HRESULT_TYPEDEF_(0x80092021L)
#define OSS_BAD_TABLE                    _HRESULT_TYPEDEF_(0x8009300FL)
#define OSS_TABLE_MISMATCH               _HRESULT_TYPEDEF_(0x8009301DL)
#define XENROLL_E_KEY_NOT_EXPORTABLE     _HRESULT_TYPEDEF_(0x80095000L)
#define MSSIPOTF_E_NOHEADTABLE           _HRESULT_TYPEDEF_(0x80097003L)
#define MSSIPOTF_E_TABLE_TAGORDER        _HRESULT_TYPEDEF_(0x80097006L)
#define MSSIPOTF_E_TABLE_LONGWORD        _HRESULT_TYPEDEF_(0x80097007L)
#define MSSIPOTF_E_BAD_FIRST_TABLE_PLACEMENT _HRESULT_TYPEDEF_(0x80097008L)
#define MSSIPOTF_E_TABLES_OVERLAP        _HRESULT_TYPEDEF_(0x80097009L)
#define MSSIPOTF_E_TABLE_PADBYTES        _HRESULT_TYPEDEF_(0x8009700AL)
#define MSSIPOTF_E_TABLE_CHECKSUM        _HRESULT_TYPEDEF_(0x8009700CL)
#define MSSIPOTF_E_DSIG_STRUCTURE        _HRESULT_TYPEDEF_(0x80097016L)
#define MSSIPOTF_E_STRUCTURE             _HRESULT_TYPEDEF_(0x80097018L)
#define SCARD_E_INSUFFICIENT_BUFFER      _HRESULT_TYPEDEF_(0x80100008L)
#define COMADMIN_E_CAT_UNACCEPTABLEBITNESS _HRESULT_TYPEDEF_(0x80110483L)

// public\sdk\inc\wingdi.h
#define DCB_SET         (DCB_RESET | DCB_ACCUMULATE)

// public\sdk\inc\winioctl.h
#define FSCTL_SET_COMPRESSION           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 16, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_GET_VOLUME_BITMAP         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 27,  METHOD_NEITHER, FILE_ANY_ACCESS) // STARTING_LCN_INPUT_BUFFER, VOLUME_BITMAP_BUFFER
#define FSCTL_WRITE_USN_CLOSE_RECORD    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 59,  METHOD_NEITHER, FILE_ANY_ACCESS) // Generate Close Usn Record
#define FSCTL_SIS_LINK_FILES            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 65, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_HSM_MSG                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 66, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)

// public\sdk\inc\winnt.h
#define ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_TAG || (x)==IMAGE_SYM_CLASS_UNION_TAG || (x)==IMAGE_SYM_CLASS_ENUM_TAG)

// public\sdk\inc\winres.h
#define CB_ADDSTRING    (WM_USER+3)

// public\sdk\inc\winsnmp.h
#define SNMP_SYNTAX_SEQUENCE  (ASN_UNIVERSAL | ASN_CONSTRUCTOR | 0x10)
#define SNMP_PDU_GET          (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x0)
#define SNMP_PDU_RESPONSE     (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x2)
#define SNMP_PDU_SET          (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x3)
#define SNMP_PDU_V1TRAP       (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x4)
#define SNMP_PDU_GETBULK      (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x5)
#define SNMP_PDU_INFORM       (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x6)
#define SNMP_PDU_TRAP         (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x7)

// public\sdk\inc\wmsbuffer.h
#define INSSBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define INSSBuffer2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define INSSBuffer2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define INSSBuffer2_GetLength(This,pdwLength)	\
    (This)->lpVtbl -> GetLength(This,pdwLength)
#define INSSBuffer2_SetLength(This,dwLength)	\
    (This)->lpVtbl -> SetLength(This,dwLength)
#define INSSBuffer2_GetMaxLength(This,pdwLength)	\
    (This)->lpVtbl -> GetMaxLength(This,pdwLength)
#define INSSBuffer2_GetBuffer(This,ppdwBuffer)	\
    (This)->lpVtbl -> GetBuffer(This,ppdwBuffer)
#define INSSBuffer2_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength)
#define INSSBuffer2_GetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> GetSampleProperties(This,cbProperties,pbProperties)
#define INSSBuffer2_SetSampleProperties(This,cbProperties,pbProperties)	\
    (This)->lpVtbl -> SetSampleProperties(This,cbProperties,pbProperties)
#define IWMSBufferAllocator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IWMSBufferAllocator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IWMSBufferAllocator_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IWMSBufferAllocator_AllocateBuffer(This,dwMaxBufferSize,ppBuffer)	\
    (This)->lpVtbl -> AllocateBuffer(This,dwMaxBufferSize,ppBuffer)

// public\sdk\inc\wmsdkidl.h
#define IWMMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMVideoMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMInputMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMOutputMediaProps_GetMediaType(This,pType,pcbType)	\
    (This)->lpVtbl -> GetMediaType(This,pType,pcbType)
#define IWMHeaderInfo_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMHeaderInfo_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)
#define IWMHeaderInfo_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMHeaderInfo2_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMHeaderInfo2_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)
#define IWMHeaderInfo2_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)
#define IWMHeaderInfo2_GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)	\
    (This)->lpVtbl -> GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)
#define IWMStreamConfig_GetBufferWindow(This,pmsBufferWindow)	\
    (This)->lpVtbl -> GetBufferWindow(This,pmsBufferWindow)
#define IWMStreamConfig_SetBufferWindow(This,msBufferWindow)	\
    (This)->lpVtbl -> SetBufferWindow(This,msBufferWindow)
#define IWMWriterAdvanced2_GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)
#define IWMWriterAdvanced2_SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)
#define IWMWriterPostViewCallback_AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext)
#define IWMWriterSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink2_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMWriterFileSink2_GetFileSize(This,pcbFile)	\
    (This)->lpVtbl -> GetFileSize(This,pcbFile)
#define IWMWriterNetworkSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit)
#define IWMReaderAdvanced_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced2_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced2_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced2_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering)
#define IWMReaderAdvanced2_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)
#define IWMReaderAdvanced2_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)
#define IWMReaderAdvanced2_StopBuffering(This)	\
    (This)->lpVtbl -> StopBuffering(This)
#define IWMReaderAdvanced3_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax)
#define IWMReaderAdvanced3_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax)
#define IWMReaderAdvanced3_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering)
#define IWMReaderAdvanced3_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)
#define IWMReaderAdvanced3_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)
#define IWMReaderAdvanced3_StopBuffering(This)	\
    (This)->lpVtbl -> StopBuffering(This)
#define IWMReaderAllocatorEx_AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    (This)->lpVtbl -> AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)
#define IWMReaderAllocatorEx_AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    (This)->lpVtbl -> AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)
#define IWMReaderCallbackAdvanced_AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext)
#define IWMReaderCallbackAdvanced_AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext)	\
    (This)->lpVtbl -> AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext)
#define IWMDRMReader_SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)	\
    (This)->lpVtbl -> SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)
#define IWMDRMReader_GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)
#define IWMReaderNetworkConfig_GetBufferingTime(This,pcnsBufferingTime)	\
    (This)->lpVtbl -> GetBufferingTime(This,pcnsBufferingTime)
#define IWMReaderNetworkConfig_SetBufferingTime(This,cnsBufferingTime)	\
    (This)->lpVtbl -> SetBufferingTime(This,cnsBufferingTime)
#define IWMBackupRestoreProps_GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength)
#define IWMBackupRestoreProps_GetPropByName(This,pszName,pType,pValue,pcbLength)	\
    (This)->lpVtbl -> GetPropByName(This,pszName,pType,pValue,pcbLength)
#define IWMBackupRestoreProps_SetProp(This,pszName,Type,pValue,cbLength)	\
    (This)->lpVtbl -> SetProp(This,pszName,Type,pValue,cbLength)

// public\sdk\inc\wtl10\atlctrlw.h
#define CBRM_GETCMDBAR			(WM_USER + 301) // return command bar HWND
#define CBRM_GETMENU			(WM_USER + 302)	// returns loaded or attached menu
#define CBRM_TRACKPOPUPMENU		(WM_USER + 303)	// displays a popup menu

// public\sdk\inc\wtl10\atlframe.h
#define CBRM_GETCMDBAR			(WM_USER + 301) // return command bar HWND
#define CBRM_GETMENU			(WM_USER + 302)	// returns loaded or attached menu
#define CBRM_TRACKPOPUPMENU		(WM_USER + 303)	// displays a popup menu

// public\sdk\inc\wtl10\atlres.h
#define CB_ADDSTRING    (WM_USER+3)

// public\sdk\inc\xmlparser.h
#define IXMLNodeSource_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLNodeSource_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLParser_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_PushData(This,pData,ulChars,fLastBuffer)	\
    (This)->lpVtbl -> PushData(This,pData,ulChars,fLastBuffer)

// published\ddk\inc\wdm\acpiioct.h
#define IOCTL_ACPI_ASYNC_EVAL_METHOD            CTL_CODE(FILE_DEVICE_ACPI, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ACPI_EVAL_METHOD                  CTL_CODE(FILE_DEVICE_ACPI, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ACPI_ACQUIRE_GLOBAL_LOCK          CTL_CODE(FILE_DEVICE_ACPI, 4, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// published\sdk\inc\alphaops.h
#define IS_RETURN_0001_INSTRUCTION(Instruction) \
    (((Instruction) & 0xFFE0FFFF) == 0x6BE08001)
#define WRENTRY_FUNC    (PRIV_PAL_FUNC | 0x05)

// published\sdk\inc\except.hxx
# define IMPLEMENT_UNWIND(class)                                            \
                                                                            \
        void APINOT class::_ObjectUnwind(void * pthis)                      \
        {                                                                   \
            ((class *)pthis)->class::~class();                              \
        }                                                                   \
                                                                            \
        struct __Check##class                                               \
        {                                                                   \
            __Check##class()                                                \
            {                                                               \
                if ( (CUnwindable *)((class *)10) != (CUnwindable *)10 ||   \
                     (CVirtualUnwindable *)                                 \
                         ((class *)10) != (CVirtualUnwindable *)10 )        \
                {                                                           \
                    exDebugOut(( DEB_ERROR,                                 \
                                 "INVALID UNWINDABLE CLASS: %s.\n",         \
                                 #class ));                                 \
                }                                                           \
            }                                                               \
        };                                                                  \
                                                                            \
        __Check##class __check_except_##class;

// published\sdk\inc\mapispi.h
#define MAPI_IMAPISUPPORT_METHODS1(IPURE)								\
	MAPIMETHOD(GetLastError)											\
		(THIS_	HRESULT						hResult,					\
				ULONG						ulFlags,					\
				LPMAPIERROR FAR *			lppMAPIError) IPURE;		\
	MAPIMETHOD(GetMemAllocRoutines)										\
		(THIS_	LPALLOCATEBUFFER FAR *		lpAllocateBuffer,			\
				LPALLOCATEMORE FAR *		lpAllocateMore,				\
				LPFREEBUFFER FAR *			lpFreeBuffer) IPURE;		\
	MAPIMETHOD(Subscribe)												\
		(THIS_	LPNOTIFKEY					lpKey,						\
				ULONG						ulEventMask,				\
				ULONG						ulFlags,					\
				LPMAPIADVISESINK			lpAdviseSink,				\
				ULONG FAR *					lpulConnection) IPURE;		\
	MAPIMETHOD(Unsubscribe)												\
		(THIS_	ULONG						ulConnection) IPURE;		\
	MAPIMETHOD(Notify)													\
		(THIS_	LPNOTIFKEY					lpKey,						\
				ULONG						cNotification,				\
				LPNOTIFICATION				lpNotifications,			\
				ULONG FAR *					lpulFlags) IPURE;			\
	MAPIMETHOD(ModifyStatusRow)											\
		(THIS_	ULONG						cValues,					\
				LPSPropValue				lpColumnVals,				\
				ULONG						ulFlags) IPURE;				\
	MAPIMETHOD(OpenProfileSection)										\
		(THIS_	LPMAPIUID					lpUid,						\
				ULONG						ulFlags,					\
				LPPROFSECT FAR *			lppProfileObj) IPURE;		\
	MAPIMETHOD(RegisterPreprocessor)									\
		(THIS_	LPMAPIUID					lpMuid,						\
				LPTSTR						lpszAdrType,				\
				LPTSTR						lpszDLLName,				\
				LPSTR	/* String8! */		lpszPreprocess,				\
				LPSTR	/* String8! */		lpszRemovePreprocessInfo,	\
				ULONG						ulFlags) IPURE;				\
	MAPIMETHOD(NewUID)													\
		(THIS_	LPMAPIUID					lpMuid) IPURE;				\
	MAPIMETHOD(MakeInvalid)												\
		(THIS_	ULONG						ulFlags,					\
				LPVOID						lpObject,					\
				ULONG						ulRefCount,					\
				ULONG						cMethods) IPURE;			\
#define MAPI_IABPROVIDER_METHODS(IPURE)                                 \
	MAPIMETHOD(Shutdown)												\
		(THIS_	ULONG FAR *					lpulFlags) IPURE;			\
    MAPIMETHOD(Logon)                                                   \
        (THIS_  LPMAPISUP                   lpMAPISup,                  \
                ULONG                       ulUIParam,                  \
                LPTSTR                      lpszProfileName,            \
                ULONG                       ulFlags,                    \
				ULONG FAR *					lpulpcbSecurity,			\
				LPBYTE FAR *				lppbSecurity,				\
                LPMAPIERROR FAR *			lppMAPIError,				\
                LPABLOGON FAR *             lppABLogon) IPURE;          \
#define MAPI_IMSPROVIDER_METHODS(IPURE)									\
	MAPIMETHOD(Shutdown)												\
		(THIS_	ULONG FAR *					lpulFlags) IPURE;			\
	MAPIMETHOD(Logon)													\
		(THIS_	LPMAPISUP					lpMAPISup,					\
				ULONG						ulUIParam,					\
				LPTSTR						lpszProfileName,			\
				ULONG						cbEntryID,					\
				LPENTRYID					lpEntryID,					\
				ULONG						ulFlags,					\
				LPCIID						lpInterface,				\
				ULONG FAR *					lpcbSpoolSecurity,			\
				LPBYTE FAR *				lppbSpoolSecurity,			\
                LPMAPIERROR FAR *			lppMAPIError,				\
				LPMSLOGON FAR *				lppMSLogon,					\
				LPMDB FAR *					lppMDB) IPURE;				\
	MAPIMETHOD(SpoolerLogon)											\
		(THIS_	LPMAPISUP					lpMAPISup,					\
				ULONG						ulUIParam,					\
				LPTSTR						lpszProfileName,			\
				ULONG						cbEntryID,					\
				LPENTRYID					lpEntryID,					\
				ULONG						ulFlags,					\
				LPCIID						lpInterface,				\
				ULONG						cbSpoolSecurity,			\
				LPBYTE						lpbSpoolSecurity,			\
                LPMAPIERROR FAR *			lppMAPIError,				\
				LPMSLOGON FAR *				lppMSLogon,					\
				LPMDB FAR *					lppMDB) IPURE;				\
	MAPIMETHOD(CompareStoreIDs)											\
		(THIS_	ULONG						cbEntryID1,					\
				LPENTRYID					lpEntryID1,					\
				ULONG						cbEntryID2,					\
				LPENTRYID					lpEntryID2,					\
				ULONG						ulFlags,					\
				ULONG FAR *					lpulResult) IPURE;			\
#define MAPI_IMSLOGON_METHODS(IPURE)									\
	MAPIMETHOD(GetLastError)											\
		(THIS_	HRESULT						hResult,					\
				ULONG						ulFlags,					\
				LPMAPIERROR FAR *			lppMAPIError) IPURE;		\
	MAPIMETHOD(Logoff)													\
		(THIS_	ULONG FAR *					lpulFlags) IPURE;			\
	MAPIMETHOD(OpenEntry)												\
		(THIS_	ULONG						cbEntryID,					\
				LPENTRYID					lpEntryID,					\
				LPCIID						lpInterface,				\
				ULONG						ulFlags,					\
				ULONG FAR *					lpulObjType,				\
				LPUNKNOWN FAR *				lppUnk) IPURE;				\
	MAPIMETHOD(CompareEntryIDs)											\
		(THIS_	ULONG						cbEntryID1,					\
				LPENTRYID					lpEntryID1,					\
				ULONG						cbEntryID2,					\
				LPENTRYID					lpEntryID2,					\
				ULONG						ulFlags,					\
				ULONG FAR *					lpulResult) IPURE;			\
	MAPIMETHOD(Advise)													\
		(THIS_	ULONG						cbEntryID,					\
				LPENTRYID					lpEntryID,					\
				ULONG						ulEventMask,				\
				LPMAPIADVISESINK			lpAdviseSink,				\
				ULONG FAR *					lpulConnection) IPURE;		\
	MAPIMETHOD(Unadvise)												\
		(THIS_	ULONG						ulConnection) IPURE;		\
	MAPIMETHOD(OpenStatusEntry)											\
		(THIS_	LPCIID						lpInterface,				\
				ULONG						ulFlags,					\
				ULONG FAR *					lpulObjType,				\
				LPVOID FAR *				lppEntry) IPURE;			\

// published\sdk\inc\mapitags.h
#define FIsTransmittable(ulPropTag) \
	((PROP_ID (ulPropTag) <  (ULONG)0x0E00) || \
	(PROP_ID (ulPropTag)  >= (ULONG)0x8000) || \
	((PROP_ID (ulPropTag) >= (ULONG)0x1000) && (PROP_ID (ulPropTag) < (ULONG)0x6000)) || \
	((PROP_ID (ulPropTag) >= (ULONG)0x6800) && (PROP_ID (ulPropTag) < (ULONG)0x7C00)))

// published\sdk\inc\mapiutil.h
#define MAPI_ITABLEDATA_METHODS(IPURE)									\
	MAPIMETHOD(HrGetView)												\
		(THIS_	LPSSortOrderSet				lpSSortOrderSet,			\
				CALLERRELEASE FAR *			lpfCallerRelease,			\
				ULONG						ulCallerData,				\
				LPMAPITABLE FAR *			lppMAPITable) IPURE;		\
	MAPIMETHOD(HrModifyRow)												\
		(THIS_	LPSRow) IPURE;											\
	MAPIMETHOD(HrDeleteRow)												\
		(THIS_	LPSPropValue				lpSPropValue) IPURE;		\
	MAPIMETHOD(HrQueryRow)												\
		(THIS_	LPSPropValue				lpsPropValue,				\
				LPSRow FAR *				lppSRow,					\
				ULONG FAR *					lpuliRow) IPURE;			\
	MAPIMETHOD(HrEnumRow)												\
		(THIS_	ULONG						ulRowNumber,				\
				LPSRow FAR *				lppSRow) IPURE;				\
	MAPIMETHOD(HrNotify)												\
		(THIS_	ULONG						ulFlags,					\
				ULONG						cValues,					\
				LPSPropValue				lpSPropValue) IPURE;		\
	MAPIMETHOD(HrInsertRow)												\
		(THIS_	ULONG						uliRow,						\
				LPSRow						lpSRow) IPURE;				\
	MAPIMETHOD(HrModifyRows)											\
		(THIS_	ULONG						ulFlags,					\
				LPSRowSet					lpSRowSet) IPURE;			\
	MAPIMETHOD(HrDeleteRows)											\
		(THIS_	ULONG						ulFlags,					\
				LPSRowSet					lprowsetToDelete,			\
				ULONG FAR *					cRowsDeleted) IPURE;		\

// published\sdk\inc\mapival.h
#define Validate_IMAPITable_FreeBookmark( a1, a2 ) \
			 ValidateParameters2( IMAPITable_FreeBookmark, a1, a2 )
#define UlValidate_IMAPITable_FreeBookmark( a1, a2 ) \
			 UlValidateParameters2( IMAPITable_FreeBookmark, a1, a2 )
#define CheckParameters_IMAPITable_FreeBookmark( a1, a2 ) \
			 CheckParameters2( IMAPITable_FreeBookmark, a1, a2 )

// published\sdk\inc\mountmgr.h
#define IOCTL_MOUNTMGR_CREATE_POINT                 CTL_CODE(MOUNTMGRCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_DELETE_POINTS                CTL_CODE(MOUNTMGRCONTROLTYPE, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_DELETE_POINTS_DBONLY         CTL_CODE(MOUNTMGRCONTROLTYPE, 3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_AUTO_DL_ASSIGNMENTS          CTL_CODE(MOUNTMGRCONTROLTYPE, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_CREATED   CTL_CODE(MOUNTMGRCONTROLTYPE, 6, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_DELETED   CTL_CODE(MOUNTMGRCONTROLTYPE, 7, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_KEEP_LINKS_WHEN_OFFLINE      CTL_CODE(MOUNTMGRCONTROLTYPE, 9, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
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

// published\sdk\inc\penwin.h
#define MpAlcB(lprc,i)          ((lprc)->rgbfAlc[((i) & 0xff) >> 3])
#define SetAlcBitAnsi(lprc,i)   do {MpAlcB(lprc,i) |= MpIbf(i);} while (0)
#define ResetAlcBitAnsi(lprc,i) do {MpAlcB(lprc,i) &= ~MpIbf(i);} while (0)
#define IsAlcBitAnsi(lprc, i)   ((MpAlcB(lprc,i) & MpIbf(i)) != 0)

// published\sdk\inc\perfsnap.hxx
# define IMPLEMENT_PERFSNAP() \
    unsigned char CPerfInfo::_ProcPerfXfer[CPerfInfo::_cbProcPerfXfer];

// published\sdk\inc\pstore.h
#define IPStore_GetProvParam(This,dwParam,pcbData,ppbData,dwFlags)  \
    (This)->lpVtbl -> GetProvParam(This,dwParam,pcbData,ppbData,dwFlags)
#define IPStore_SetProvParam(This,dwParam,cbData,pbData,dwFlags)    \
    (This)->lpVtbl -> SetProvParam(This,dwParam,cbData,pbData,dwFlags)
#define IPStore_ReadItem(This,Key,pItemType,pItemSubtype,szItemName,pcbData,ppbData,pPromptInfo,dwFlags)    \
    (This)->lpVtbl -> ReadItem(This,Key,pItemType,pItemSubtype,szItemName,pcbData,ppbData,pPromptInfo,dwFlags)
#define IPStore_WriteItem(This,Key,pItemType,pItemSubtype,szItemName,cbData,pbData,pPromptInfo,dwDefaultConfirmationStyle,dwFlags)  \
    (This)->lpVtbl -> WriteItem(This,Key,pItemType,pItemSubtype,szItemName,cbData,pbData,pPromptInfo,dwDefaultConfirmationStyle,dwFlags)

// published\sdk\inc\safepnt.hxx
#define SAFE_WIN32_HANDLE(ShName)                                          \
                                                                           \
class ShName INHERIT_UNWIND_IF_CAIRO                                       \
{                                                                          \
     INLINE_UNWIND(ShName)                                                 \
public:                                                                    \
                                                                           \
inline ShName (HANDLE handle = NULL)                                       \
       : _handle(handle)                                                   \
       {                                                                   \
            END_CONSTRUCTION(ShName)                                       \
       }                                                                   \
                                                                           \
inline ~##ShName ()                                                        \
       {                                                                   \
            if ((_handle != INVALID_HANDLE_VALUE) && (_handle != NULL))    \
            {                                                              \
                 CloseHandle(_handle);                                     \
            }                                                              \
       }                                                                   \
                                                                           \
inline void Transfer(HANDLE *phandle)                                      \
    {                                                                      \
        *phandle = _handle;                                                \
        _handle = NULL;                                                    \
    }                                                                      \
inline void Set(HANDLE h)                                                  \
    {                                                                      \
        if (_handle != INVALID_HANDLE_VALUE && _handle != NULL)            \
        {                                                                  \
             CloseHandle(_handle);                                         \
        }                                                                  \
        _handle = h;                                                       \
    }                                                                      \
inline void Attach(HANDLE h)                                               \
    {                                                                      \
        Win4Assert(_handle == NULL);                                       \
        _handle = h;                                                       \
    }                                                                      \
inline void Detach(void)                                                   \
    {                                                                      \
        _handle = NULL;                                                    \
    }                                                                      \
                                                                           \
inline operator HANDLE ()                                                  \
       {                                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline HANDLE operator= (HANDLE handle)                                    \
       {                                                                   \
            Set(handle);                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline BOOL operator==(HANDLE handle)                                      \
       {                                                                   \
            if (_handle == handle)                                         \
            {                                                              \
                 return(TRUE);                                             \
            }                                                              \
            return(FALSE);                                                 \
       }                                                                   \
                                                                           \
inline HANDLE *operator&()                                                 \
       {                                                                   \
            Win4Assert((_handle==NULL) || (_handle==INVALID_HANDLE_VALUE));\
            return(&_handle);                                              \
       }                                                                   \
                                                                           \
private:                                                                   \
                                                                           \
       HANDLE _handle;                                                     \
                                                                           \
inline VOID operator= (const ShName &) {;}                                 \
inline ShName (const ShName &) {;}                                         \
                                                                           \
};
#define SAFE_WIN32FIND_HANDLE(ShName)                                      \
                                                                           \
class ShName INHERIT_UNWIND_IF_CAIRO                                       \
{                                                                          \
     INLINE_UNWIND(ShName)                                                 \
public:                                                                    \
                                                                           \
inline ShName (HANDLE handle = NULL)                                       \
       : _handle(handle)                                                   \
       {                                                                   \
            END_CONSTRUCTION(ShName)                                       \
       }                                                                   \
                                                                           \
inline ~##ShName ()                                                        \
       {                                                                   \
            if ((_handle != INVALID_HANDLE_VALUE) && (_handle != NULL))    \
            {                                                              \
                 FindClose(_handle);                                       \
            }                                                              \
       }                                                                   \
                                                                           \
inline void Transfer(HANDLE *phandle)                                      \
    {                                                                      \
        *phandle = _handle;                                                \
        _handle = NULL;                                                    \
    }                                                                      \
inline void Set(HANDLE h)                                                  \
    {                                                                      \
        if (_handle != INVALID_HANDLE_VALUE && _handle != NULL)            \
        {                                                                  \
             FindClose(_handle);                                           \
        }                                                                  \
        _handle = h;                                                       \
    }                                                                      \
inline void Attach(HANDLE h)                                               \
    {                                                                      \
        Win4Assert(_handle == NULL);                                       \
        _handle = h;                                                       \
    }                                                                      \
inline void Detach(void)                                                   \
    {                                                                      \
        _handle = NULL;                                                    \
    }                                                                      \
                                                                           \
inline operator HANDLE ()                                                  \
       {                                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline HANDLE operator= (HANDLE handle)                                    \
       {                                                                   \
            Set(handle);                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline BOOL operator==(HANDLE handle)                                      \
       {                                                                   \
            if (_handle == handle)                                         \
            {                                                              \
                 return(TRUE);                                             \
            }                                                              \
            return(FALSE);                                                 \
       }                                                                   \
                                                                           \
inline HANDLE *operator&()                                                 \
       {                                                                   \
            Win4Assert((_handle==NULL) || (_handle==INVALID_HANDLE_VALUE));\
            return(&_handle);                                              \
       }                                                                   \
                                                                           \
private:                                                                   \
                                                                           \
       HANDLE _handle;                                                     \
                                                                           \
inline VOID operator= (const ShName &) {;}                                 \
inline ShName (const ShName &) {;}                                         \
                                                                           \
};
#define SAFE_NT_HANDLE(ShName)                                             \
                                                                           \
class ShName INHERIT_UNWIND_IF_CAIRO                                       \
{                                                                          \
     INLINE_UNWIND(ShName)                                                 \
public:                                                                    \
                                                                           \
inline ShName (HANDLE handle = NULL)                                       \
       : _handle(handle)                                                   \
       {                                                                   \
            END_CONSTRUCTION(ShName)                                       \
       }                                                                   \
                                                                           \
inline ~##ShName ()                                                        \
       {                                                                   \
            if ((_handle != INVALID_HANDLE_VALUE) && (_handle != NULL))    \
            {                                                              \
                 NtClose(_handle);                                         \
            }                                                              \
       }                                                                   \
                                                                           \
inline void Transfer(HANDLE *phandle)                                      \
    {                                                                      \
        *phandle = _handle;                                                \
        _handle = NULL;                                                    \
    }                                                                      \
inline void Set(HANDLE h)                                                  \
    {                                                                      \
        if (_handle != INVALID_HANDLE_VALUE && _handle != NULL)            \
        {                                                                  \
             NtClose(_handle);                                             \
        }                                                                  \
        _handle = h;                                                       \
    }                                                                      \
inline void Attach(HANDLE h)                                               \
    {                                                                      \
        Win4Assert(_handle == NULL);                                       \
        _handle = h;                                                       \
    }                                                                      \
inline void Detach(void)                                                   \
    {                                                                      \
        _handle = NULL;                                                    \
    }                                                                      \
                                                                           \
inline operator HANDLE ()                                                  \
       {                                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline HANDLE operator= (HANDLE handle)                                    \
       {                                                                   \
            Set(handle);                                                   \
            return(_handle);                                               \
       }                                                                   \
                                                                           \
inline BOOL operator==(HANDLE handle)                                      \
       {                                                                   \
            if (_handle == handle)                                         \
            {                                                              \
                 return(TRUE);                                             \
            }                                                              \
            return(FALSE);                                                 \
       }                                                                   \
                                                                           \
inline HANDLE *operator&()                                                 \
       {                                                                   \
            Win4Assert((_handle==NULL) || (_handle==INVALID_HANDLE_VALUE));\
            return(&_handle);                                              \
       }                                                                   \
                                                                           \
private:                                                                   \
                                                                           \
       HANDLE _handle;                                                     \
                                                                           \
inline VOID operator= (const ShName &) {;}                                 \
inline ShName (const ShName &) {;}                                         \
                                                                           \
};
#define UNWINDABLE_WRAPPER(UwName, Class)                       \
class UwName : INHERIT_UNWIND, public Class                     \
{                                                               \
    INLINE_UNWIND(UwName)                                       \
public:                                                         \
    inline UwName(void)                                         \
    {                                                           \
        END_CONSTRUCTION(UwName);                               \
    }                                                           \
    inline ~##UwName(void)                                      \
    {                                                           \
    }                                                           \
}
#define UNWINDABLE_WRAPPER_ARGS(UwName, Class, CtorDecl, CtorArgs)      \
class UwName : INHERIT_UNWIND, public Class                             \
{                                                                       \
    INLINE_UNWIND(UwName)                                               \
public:                                                                 \
    inline UwName CtorDecl : Class CtorArgs                             \
    {                                                                   \
        END_CONSTRUCTION(UwName);                                       \
    }                                                                   \
    inline ~##UwName(void)                                              \
    {                                                                   \
    }                                                                   \
}

// published\sdk\inc\setupxrc.h
#define     STF_SET_INSTRUCTION_TEXT_RC         (WM_USER + 0x8104)

// published\sdk\inc\snmp.h
#define SNMP_PDU_GET                (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x0)
#define SNMP_PDU_RESPONSE           (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x2)
#define SNMP_PDU_SET                (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x3)
#define SNMP_PDU_V1TRAP             (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x4)
#define SNMP_PDU_GETBULK            (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x5)
#define SNMP_PDU_INFORM             (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x6)
#define SNMP_PDU_TRAP               (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x7)
#define ASN_SEQUENCE                (ASN_UNIVERSAL | ASN_CONSTRUCTOR | 0x10)
#define SNMP_EXTENSION_SET_TEST     (ASN_PRIVATE | ASN_CONSTRUCTOR | 0x0)
#define SNMP_EXTENSION_SET_UNDO     (ASN_PRIVATE | ASN_CONSTRUCTOR | 0x1)
#define SNMP_EXTENSION_SET_CLEANUP  (ASN_PRIVATE | ASN_CONSTRUCTOR | 0x2)

// published\sdk\inc\tuple.h
#define DeviceSpeedField(X)  (X & DSPEED_MASK)
#define ConfigEntryNumber(X) (X & 0x3f)

// published\sdk\inc\txcoord.h
#define ITransactionExportFactory_Create(This,cbWhereabouts,rgbWhereabouts,ppExport)	\
    (This)->lpVtbl -> Create(This,cbWhereabouts,rgbWhereabouts,ppExport)
#define ITransactionImportWhereabouts_GetWhereaboutsSize(This,pcbWhereabouts)	\
    (This)->lpVtbl -> GetWhereaboutsSize(This,pcbWhereabouts)
#define ITransactionImportWhereabouts_GetWhereabouts(This,cbWhereabouts,rgbWhereabouts,pcbUsed)	\
    (This)->lpVtbl -> GetWhereabouts(This,cbWhereabouts,rgbWhereabouts,pcbUsed)
#define ITransactionExport_Export(This,punkTransaction,pcbTransactionCookie)	\
    (This)->lpVtbl -> Export(This,punkTransaction,pcbTransactionCookie)
#define ITransactionExport_GetTransactionCookie(This,punkTransaction,cbTransactionCookie,rgbTransactionCookie,pcbUsed)	\
    (This)->lpVtbl -> GetTransactionCookie(This,punkTransaction,cbTransactionCookie,rgbTransactionCookie,pcbUsed)
#define ITransactionImport_Import(This,cbTransactionCookie,rgbTransactionCookie,piid,ppvTransaction)	\
    (This)->lpVtbl -> Import(This,cbTransactionCookie,rgbTransactionCookie,piid,ppvTransaction)

// published\sdk\inc\vfw.h
#define ICM_DECOMPRESS_SET_PALETTE  (ICM_USER+29)   // fill in the DIB color table
#define ICM_DECOMPRESS_GET_PALETTE  (ICM_USER+30)   // fill in the DIB color table
#define ICDrawRenderBuffer(hic) \
    ICSendMessage(hic, ICM_DRAW_RENDERBUFFER, 0, 0)
#define MCIWNDM_CAN_RECORD      (WM_USER + 146)

// published\sdk\inc\windowsx.h
#define HANDLE_WM_CREATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCREATESTRUCT)(lParam)) ? 0L : (LRESULT)-1L)
#define FORWARD_WM_CREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_CREATE, 0L, (LPARAM)(LPCREATESTRUCT)(lpCreateStruct))
#define HANDLE_WM_NCCREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (LPCREATESTRUCT)(lParam))
#define FORWARD_WM_NCCREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCCREATE, 0L, (LPARAM)(LPCREATESTRUCT)(lpCreateStruct))
#define HANDLE_WM_PAINTCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const LPPAINTSTRUCT)GlobalLock((HGLOBAL)(lParam))), GlobalUnlock((HGLOBAL)(lParam)), 0L)
#define FORWARD_WM_PAINTCLIPBOARD(hwnd, hwndCBViewer, lpPaintStruct, fn) \
    (void)(fn)((hwnd), WM_PAINTCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(LPPAINTSTRUCT)(lpPaintStruct))
#define FORWARD_WM_SIZECLIPBOARD(hwnd, hwndCBViewer, lprc, fn) \
    (void)(fn)((hwnd), WM_SIZECLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(LPRECT)(lprc))
#define FORWARD_WM_VSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define FORWARD_WM_HSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define HANDLE_WM_ASKCBFORMATNAME(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (LPTSTR)(lParam)), 0L)
#define FORWARD_WM_ASKCBFORMATNAME(hwnd, cchMax, rgchName, fn) \
    (void)(fn)((hwnd), WM_ASKCBFORMATNAME, (WPARAM)(int)(cchMax), (LPARAM)(rgchName))
#define HANDLE_WM_CHANGECBCHAIN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (HWND)(lParam)), 0L)
#define HANDLE_WM_MDICREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (LPMDICREATESTRUCT)(lParam))
#define FORWARD_WM_MDICREATE(hwnd, lpmcs, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDICREATE, 0L, (LPARAM)(LPMDICREATESTRUCT)(lpmcs))
#define HANDLE_WM_DRAWITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DRAWITEMSTRUCT *)(lParam)), 0L)
#define FORWARD_WM_DRAWITEM(hwnd, lpDrawItem, fn) \
    (void)(fn)((hwnd), WM_DRAWITEM, (WPARAM)(((const DRAWITEMSTRUCT *)lpDrawItem)->CtlID), (LPARAM)(const DRAWITEMSTRUCT *)(lpDrawItem))
#define HANDLE_WM_MEASUREITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MEASUREITEMSTRUCT *)(lParam)), 0L)
#define FORWARD_WM_MEASUREITEM(hwnd, lpMeasureItem, fn) \
    (void)(fn)((hwnd), WM_MEASUREITEM, (WPARAM)(((MEASUREITEMSTRUCT *)lpMeasureItem)->CtlID), (LPARAM)(MEASUREITEMSTRUCT *)(lpMeasureItem))
#define HANDLE_WM_DELETEITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DELETEITEMSTRUCT *)(lParam)), 0L)
#define FORWARD_WM_DELETEITEM(hwnd, lpDeleteItem, fn) \
    (void)(fn)((hwnd), WM_DELETEITEM, (WPARAM)(((const DELETEITEMSTRUCT *)(lpDeleteItem))->CtlID), (LPARAM)(const DELETEITEMSTRUCT *)(lpDeleteItem))
#define HANDLE_WM_COMPAREITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (const COMPAREITEMSTRUCT *)(lParam))
#define FORWARD_WM_COMPAREITEM(hwnd, lpCompareItem, fn) \
    (int)(DWORD)(fn)((hwnd), WM_COMPAREITEM, (WPARAM)(((const COMPAREITEMSTRUCT *)(lpCompareItem))->CtlID), (LPARAM)(const COMPAREITEMSTRUCT *)(lpCompareItem))
#define HANDLE_WM_COPYDATA(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (PCOPYDATASTRUCT)lParam), 0L)
#define ComboBox_LimitText(hwndCtl, cchLimit)   ((int)(DWORD)SNDMSG((hwndCtl), CB_LIMITTEXT, (WPARAM)(int)(cchLimit), 0L))
#define ComboBox_GetEditSel(hwndCtl)            ((DWORD)SNDMSG((hwndCtl), CB_GETEDITSEL, 0L, 0L))
#define ComboBox_SetEditSel(hwndCtl, ichStart, ichEnd) ((int)(DWORD)SNDMSG((hwndCtl), CB_SETEDITSEL, 0L, MAKELPARAM((ichStart), (ichEnd))))
#define ComboBox_GetCount(hwndCtl)              ((int)(DWORD)SNDMSG((hwndCtl), CB_GETCOUNT, 0L, 0L))
#define ComboBox_ResetContent(hwndCtl)          ((int)(DWORD)SNDMSG((hwndCtl), CB_RESETCONTENT, 0L, 0L))
#define ComboBox_AddString(hwndCtl, lpsz)       ((int)(DWORD)SNDMSG((hwndCtl), CB_ADDSTRING, 0L, (LPARAM)(LPCTSTR)(lpsz)))
#define ComboBox_InsertString(hwndCtl, index, lpsz) ((int)(DWORD)SNDMSG((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCTSTR)(lpsz)))
#define ComboBox_AddItemData(hwndCtl, data)     ((int)(DWORD)SNDMSG((hwndCtl), CB_ADDSTRING, 0L, (LPARAM)(data)))
#define ComboBox_InsertItemData(hwndCtl, index, data) ((int)(DWORD)SNDMSG((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_DeleteString(hwndCtl, index)   ((int)(DWORD)SNDMSG((hwndCtl), CB_DELETESTRING, (WPARAM)(int)(index), 0L))
#define ComboBox_GetLBTextLen(hwndCtl, index)           ((int)(DWORD)SNDMSG((hwndCtl), CB_GETLBTEXTLEN, (WPARAM)(int)(index), 0L))
#define ComboBox_GetLBText(hwndCtl, index, lpszBuffer)  ((int)(DWORD)SNDMSG((hwndCtl), CB_GETLBTEXT, (WPARAM)(int)(index), (LPARAM)(LPCTSTR)(lpszBuffer)))
#define ComboBox_SetItemData(hwndCtl, index, data)  ((int)(DWORD)SNDMSG((hwndCtl), CB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_FindString(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SNDMSG((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ComboBox_FindItemData(hwndCtl, indexStart, data)    ((int)(DWORD)SNDMSG((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_GetCurSel(hwndCtl)                 ((int)(DWORD)SNDMSG((hwndCtl), CB_GETCURSEL, 0L, 0L))
#define ComboBox_SetCurSel(hwndCtl, index)          ((int)(DWORD)SNDMSG((hwndCtl), CB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ComboBox_SelectString(hwndCtl, indexStart, lpszSelect)  ((int)(DWORD)SNDMSG((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszSelect)))
#define ComboBox_SelectItemData(hwndCtl, indexStart, data)      ((int)(DWORD)SNDMSG((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_Dir(hwndCtl, attrs, lpszFileSpec)  ((int)(DWORD)SNDMSG((hwndCtl), CB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCTSTR)(lpszFileSpec)))
#define ComboBox_ShowDropdown(hwndCtl, fShow)       ((BOOL)(DWORD)SNDMSG((hwndCtl), CB_SHOWDROPDOWN, (WPARAM)(BOOL)(fShow), 0L))
#define ComboBox_FindStringExact(hwndCtl, indexStart, lpszFind)  ((int)(DWORD)SNDMSG((hwndCtl), CB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ComboBox_GetDroppedState(hwndCtl)           ((BOOL)(DWORD)SNDMSG((hwndCtl), CB_GETDROPPEDSTATE, 0L, 0L))
#define ComboBox_GetDroppedControlRect(hwndCtl, lprc) ((void)SNDMSG((hwndCtl), CB_GETDROPPEDCONTROLRECT, 0L, (LPARAM)(RECT *)(lprc)))
#define ComboBox_GetItemHeight(hwndCtl)             ((int)(DWORD)SNDMSG((hwndCtl), CB_GETITEMHEIGHT, 0L, 0L))
#define ComboBox_SetItemHeight(hwndCtl, index, cyItem) ((int)(DWORD)SNDMSG((hwndCtl), CB_SETITEMHEIGHT, (WPARAM)(int)(index), (LPARAM)(int)cyItem))
#define ComboBox_GetExtendedUI(hwndCtl)             ((UINT)(DWORD)SNDMSG((hwndCtl), CB_GETEXTENDEDUI, 0L, 0L))
#define ComboBox_SetExtendedUI(hwndCtl, flags)      ((int)(DWORD)SNDMSG((hwndCtl), CB_SETEXTENDEDUI, (WPARAM)(UINT)(flags), 0L))

// published\sdk\inc\winres.h
#define CB_ADDSTRING    (WM_USER+3)

// published\sdk\inc\winsnmp.h
#define SNMP_SYNTAX_SEQUENCE  (ASN_UNIVERSAL | ASN_CONSTRUCTOR | 0x10)
#define SNMP_PDU_GET          (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x0)
#define SNMP_PDU_RESPONSE     (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x2)
#define SNMP_PDU_SET          (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x3)
#define SNMP_PDU_V1TRAP       (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x4)
#define SNMP_PDU_GETBULK      (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x5)
#define SNMP_PDU_INFORM       (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x6)
#define SNMP_PDU_TRAP         (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x7)

// sdktools\asn1\asn1c\scanner.c
#define yy_set_bol(at_bol) \
    { \
    if ( ! yy_current_buffer ) \
        yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
    yy_current_buffer->yy_at_bol = at_bol; \
    }

// sdktools\build\scrproc.h
#define IGlobalMTScript_MessageBoxTimeout(This,bstrMessage,cButtons,bstrButtonText,lTimeout,lEventInterval,fCanCancel,fConfirm,plSelected)	\
    (This)->lpVtbl -> MessageBoxTimeout(This,bstrMessage,cButtons,bstrButtonText,lTimeout,lEventInterval,fCanCancel,fConfirm,plSelected)

// sdktools\debuggers\exdi\exdi.h
#define IeXdiServer_SetDebugMode(This,dwModeBitField)	\
    (This)->lpVtbl -> SetDebugMode(This,dwModeBitField)
#define IeXdiServer_DoMultipleStep(This,dwNbInstructions)	\
    (This)->lpVtbl -> DoMultipleStep(This,dwNbInstructions)
#define IeXdiServer_AddCodeBreakpoint(This,Address,cbpk,mt,dwExecMode,dwTotalBypassCount,ppieXdiCodeBreakpoint)	\
    (This)->lpVtbl -> AddCodeBreakpoint(This,Address,cbpk,mt,dwExecMode,dwTotalBypassCount,ppieXdiCodeBreakpoint)
#define IeXdiServer_ReadVirtualMemory(This,Address,dwNbElemToRead,bAccessWidth,pbReadBuffer,pdwNbElementEffectRead)	\
    (This)->lpVtbl -> ReadVirtualMemory(This,Address,dwNbElemToRead,bAccessWidth,pbReadBuffer,pdwNbElementEffectRead)
#define IeXdiServer_WriteVirtualMemory(This,Address,dwNbElemToWrite,bAccessWidth,pbWriteBuffer,pdwNbElementEffectWritten)	\
    (This)->lpVtbl -> WriteVirtualMemory(This,Address,dwNbElemToWrite,bAccessWidth,pbWriteBuffer,pdwNbElementEffectWritten)
#define IeXdiServer_ReadPhysicalMemoryOrPeriphIO(This,Address,bAddressSpace,dwNbElemToRead,bAccessWidth,pbReadBuffer)	\
    (This)->lpVtbl -> ReadPhysicalMemoryOrPeriphIO(This,Address,bAddressSpace,dwNbElemToRead,bAccessWidth,pbReadBuffer)
#define IeXdiServer_WritePhysicalMemoryOrPeriphIO(This,Address,bAddressSpace,dwNbElemToWrite,bAccessWidth,pbWriteBuffer)	\
    (This)->lpVtbl -> WritePhysicalMemoryOrPeriphIO(This,Address,bAddressSpace,dwNbElemToWrite,bAccessWidth,pbWriteBuffer)
#define IeXdiServer_Ioctl(This,dwBuffInSize,pbBufferIn,dwBuffOutSize,pdwEffectBuffOutSize,pbBufferOut)	\
    (This)->lpVtbl -> Ioctl(This,dwBuffInSize,pbBufferIn,dwBuffOutSize,pdwEffectBuffOutSize,pbBufferOut)
#define IeXdiCodeBreakpoint_GetAttributes(This,pAddress,pcbpk,pmt,pdwExecMode,pdwTotalBypassCount,pdwBypassedOccurences,pfEnabled)	\
    (This)->lpVtbl -> GetAttributes(This,pAddress,pcbpk,pmt,pdwExecMode,pdwTotalBypassCount,pdwBypassedOccurences,pfEnabled)

// sdktools\debuggers\imagehlp\vc\dia2.h
#define IDiaLoadCallback_NotifyDebugDir(This,fExecutable,cbData,data)	\
    (This)->lpVtbl -> NotifyDebugDir(This,fExecutable,cbData,data)
#define IDiaReadExeAtRVACallback_ReadExecutableAtRVA(This,relativeVirtualAddress,cbData,pcbData,data)	\
    (This)->lpVtbl -> ReadExecutableAtRVA(This,relativeVirtualAddress,cbData,pcbData,data)
#define IDiaDataSource_loadDataForExe(This,executable,searchPath,pCallback)	\
    (This)->lpVtbl -> loadDataForExe(This,executable,searchPath,pCallback)
#define IDiaEnumDebugStreamData_Item(This,index,cbData,pcbData,data)	\
    (This)->lpVtbl -> Item(This,index,cbData,pcbData,data)
#define IDiaAddressMap_set_imageHeaders(This,cbData,data,originalHeaders)	\
    (This)->lpVtbl -> set_imageHeaders(This,cbData,data,originalHeaders)
#define IDiaSession_getEnumTables(This,ppEnumTables)	\
    (This)->lpVtbl -> getEnumTables(This,ppEnumTables)
#define IDiaSymbol_get_constructor(This,pRetVal)	\
    (This)->lpVtbl -> get_constructor(This,pRetVal)
#define IDiaSymbol_get_virtualTableShape(This,pRetVal)	\
    (This)->lpVtbl -> get_virtualTableShape(This,pRetVal)
#define IDiaSymbol_get_virtualTableShapeId(This,pRetVal)	\
    (This)->lpVtbl -> get_virtualTableShapeId(This,pRetVal)
#define IDiaSymbol_get_dataBytes(This,cbData,pcbData,data)	\
    (This)->lpVtbl -> get_dataBytes(This,cbData,pcbData,data)
#define IDiaSourceFile_get_checksum(This,cbData,pcbData,data)	\
    (This)->lpVtbl -> get_checksum(This,cbData,pcbData,data)
#define IDiaInjectedSource_get_source(This,cbData,pcbData,data)	\
    (This)->lpVtbl -> get_source(This,cbData,pcbData,data)
#define IDiaStackWalkFrame_readMemory(This,va,cbData,pcbData,data)	\
    (This)->lpVtbl -> readMemory(This,va,cbData,pcbData,data)
#define IDiaTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IDiaTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IDiaTable_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IDiaTable_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IDiaTable_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IDiaTable_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)
#define IDiaTable_get__NewEnum(This,pRetVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pRetVal)
#define IDiaTable_get_name(This,pRetVal)	\
    (This)->lpVtbl -> get_name(This,pRetVal)
#define IDiaTable_get_Count(This,pRetVal)	\
    (This)->lpVtbl -> get_Count(This,pRetVal)
#define IDiaTable_Item(This,index,element)	\
    (This)->lpVtbl -> Item(This,index,element)
#define IDiaEnumTables_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IDiaEnumTables_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define IDiaEnumTables_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IDiaEnumTables_get__NewEnum(This,pRetVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pRetVal)
#define IDiaEnumTables_get_Count(This,pRetVal)	\
    (This)->lpVtbl -> get_Count(This,pRetVal)
#define IDiaEnumTables_Item(This,index,table)	\
    (This)->lpVtbl -> Item(This,index,table)
#define IDiaEnumTables_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)
#define IDiaEnumTables_Reset(This)	\
    (This)->lpVtbl -> Reset(This)
#define IDiaEnumTables_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

// sdktools\fsdump\inc\bsfixalloc.h
#define DECLARE_FIXED_ALLOC(class_name) \
public: \
	void* operator new(size_t size) \
	{ \
		ASSERT(size == s_alloc.GetAllocSize()); \
		UNUSED(size); \
		return s_alloc.Alloc(); \
	} \
	void* operator new(size_t, void* p) \
		{ return p; } \
	void operator delete(void* p) { s_alloc.Free(p); } \
	void* operator new(size_t size, LPCSTR, int) \
	{ \
		ASSERT(size == s_alloc.GetAllocSize()); \
		UNUSED(size); \
		return s_alloc.Alloc(); \
	} \
protected: \
	static CBsFixedAlloc s_alloc \

// sdktools\gutils\table.h
#define TM_REFRESH	(WM_USER)
#define TM_NEWLAYOUT	(WM_USER+1)
#define TM_NEWID	(WM_USER+2)
#define TM_SELECT	(WM_USER+3)
#define TM_PRINT	(WM_USER+4)
#define TM_TOPROW	(WM_USER+5)
#define TM_ENDROW	(WM_USER+6)
#define TM_APPEND	(WM_USER+7)
#define TM_GETSELECTION (WM_USER+8)
#define TM_SETTABWIDTH (WM_USER+9)

// sdktools\hivepp\symbols.h
#define	SYM_ISFIELD(p)		(SYM_ANYVTAG(p) & SYMV_FIELD)
#define	ST_BUCKET(ptab,hash)	(((ptab)->st_table[hash & ST_MOD(ptab)]))

// sdktools\link16\undname.hxx
#define TE_isvftable(t)                 (TE_isdata(t)&&(((t)&0x7800)==0x6800))
#define TE_setisvftable(t)              ((t)=(((t)&~0x7800)|0x6800))
#define TE_isvbtable(t)                 (TE_isdata(t)&&(((t)&0x7800)==0x7000))
#define TE_setisvbtable(t)              ((t)=(((t)&~0x7800)|0x7000))

// sdktools\mep\help\htest\cons.c
#define     PWINDOW_EVT(p)  (&(EVENT_DATA(p).WindowBufferSizeEvent))

// sdktools\mep\inc\cmds.h
#define CMD_doarg           (PCMD)&cmdTable[0]

// sdktools\mep\src\console.c
#define     PWINDOW_EVT(p)  (&(EVENT_DATA(p).WindowBufferSizeEvent))

// sdktools\mtscript\inc\mem.h
#define DECLARE_MEMALLOC_NEW_DELETE() \
    inline void * __cdecl operator new(size_t cb) { return(MemAlloc(cb)); } \
    inline void * __cdecl operator new[](size_t cb) { return(MemAlloc(cb)); } \
    inline void __cdecl operator delete(void * pv) { MemFree(pv); }
#define DECLARE_MEMCLEAR_NEW_DELETE() \
    inline void * __cdecl operator new(size_t cb) { return(MemAllocClear(cb)); } \
    inline void * __cdecl operator new[](size_t cb) { return(MemAllocClear(cb)); } \
    inline void __cdecl operator delete(void * pv) { MemFree(pv); }

// sdktools\mtscript\inc\types.h
#define DECLARE_STANDARD_IUNKNOWN(cls)                              \
    STDMETHOD(QueryInterface) (REFIID riid, LPVOID * ppv);          \
    ULONG _ulRefs;                                                  \
    STDMETHOD_(ULONG, AddRef) (void)                                \
        {                                                           \
            return InterlockedIncrement((long*)&_ulRefs);           \
        }                                                           \
    STDMETHOD_(ULONG, Release) (void)                               \
        {                                                           \
            if (InterlockedDecrement((long*)&_ulRefs) == 0)         \
            {                                                       \
                _ulRefs = ULREF_IN_DESTRUCTOR;                      \
                delete this;                                        \
                return 0;                                           \
            }                                                       \
            return _ulRefs;                                         \
        }                                                           \
    ULONG GetRefs(void)                                             \
        { return _ulRefs; }

// sdktools\rcdll\symbols.h
#define SYM_ISFIELD(p)          (SYM_ANYVTAG(p) & SYMV_FIELD)
#define ST_BUCKET(ptab,hash)            (((ptab)->st_table[hash & ST_MOD(ptab)]))

// sdktools\trace\tracewpp\fieldtable.h
#define BEGIN_FIELD_TABLE(__ObjectName__, __Output__) \
    DWORD PrintField(int __FieldId__, FILE* __Output__, const Enumerator** __pEnum__) const \
    { \
        DWORD __status__ = ERROR_SUCCESS; \
        static char* __Object__ = #__ObjectName__; \
        FILE* __f__ = __Output__; \
        UNREFERENCED_PARAMETER(__pEnum__); \
        switch(__FieldId__) { case -1:;
#define BEGIN_FIELD_TABLE_NONAME(__Output__) \
    DWORD PrintField(int __FieldId__, FILE* __Output__, const Enumerator** __pEnum__) const \
    { \
        DWORD __status__ = ERROR_SUCCESS; \
        FILE* __f__ = __Output__; \
        UNREFERENCED_PARAMETER(__pEnum__); \
        switch(__FieldId__) { case -1:;

// sdktools\tweakui\mouse.cpp
#define poteExp(pinth) (&(pinth)->OptionalHeader. \
			  DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT])

// sdktools\tweakui\tweakui.h
#define lAlloc(cb)      (void *)LocalAlloc(LMEM_FIXED | LMEM_ZEROINIT, cb)
#define lReAlloc(p, cb) (void *)LocalReAlloc((HLOCAL)(p), (cb), \
                                             LMEM_MOVEABLE | LMEM_ZEROINIT)

// sdktools\tztool\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// sdktools\z\inc\cmds.h
#define CMD_doarg           (PCMD)&cmdTable[0]

// sdktools\z\src\console.c
#define     PWINDOW_EVT(p)  (&(EVENT_DATA(p).WindowBufferSizeEvent))

// shell\comctl32\v5\mem.h
#define NearReAlloc(pb, cb) ((void NEAR*)LocalReAlloc((HLOCAL)(pb), (cb), LMEM_MOVEABLE | LMEM_ZEROINIT))

// shell\comctl32\v5\rebar.c
#define RBGETBARHEIGHT(prb) (((prb)->cBands && !(prb)->cy) ? RBRecalc(prb) : (prb)->cy)

// shell\comctl32\v6\combo.h
#define SDROPDOWN       (SDROPPABLE | SEDITABLE)

// shell\comctl32\v6\mem.h
#define NearReAlloc(pb, cb) ((void*)LocalReAlloc((HLOCAL)(pb), (cb), LMEM_MOVEABLE | LMEM_ZEROINIT))

// shell\comdlg32\font.h
#define CBN_MYEDITUPDATE     (WM_USER + 501)

// shell\evtmon\inc\emkwd.h
#define MsoRgpkwdHashFromKwtb(pkwtb) \
            ((MSOKWD **) (pkwtb)->pvTable)
#define MsoPkwdlFromKwtb(pkwtb) \
            ((MSOKWDL *) (pkwtb)->pvTable)
#define MsoRgpkwdlhFromKwtb(pkwtb) \
            ((MSOKWDLH **) (pkwtb)->pvTable)

// shell\evtmon\inc\emoci.h
#define PcbArgFromOcad(ocad, pocis) \
            (&(pocis)->rgcbImmedArg[ocad])

// shell\evtmon\inc\msolex.h
#define IchLexTkFirst(plexs) \
            ((plexs)->pxchTkStart - (plexs)->pxchBuffer)

// shell\ext\brfcase\filesync\syncui\cache.h
#define CBS_Init()                      Cache_Init(&g_cacheCBS)
#define CBS_InitCS()                    Cache_InitCS(&g_cacheCBS)

// shell\ext\brfcase\filesync\syncui\comm.h
#define GReAlloc(pv, cbNewSize) GlobalReAlloc(pv, cbNewSize, GMEM_MOVEABLE | GMEM_ZEROINIT)

// shell\ext\docprop\plex.h
#define cbPL ((int)&((PL *)0)->rg)

// shell\ext\dsui\dsquery\query.h
#define RVTM_SETCOLUMNTABLE         (WM_USER+2)         // wParam = 0, lParam = HDSA columns

// shell\ext\neptune\aidanl\davtrans\ifaces\iasyncwnt.h
#define IAsyncWntCallback_Respond(This,pwszVerb,pwszPath,cchHeaders,pwszHeaders,dwStatusCode,pwszStatusCode,pwszContentType,cbSent,pbResponse,cbResponse)	\
    (This)->lpVtbl -> Respond(This,pwszVerb,pwszPath,cchHeaders,pwszHeaders,dwStatusCode,pwszStatusCode,pwszContentType,cbSent,pbResponse,cbResponse)
#define IAsyncWnt_RequestWithBuffer(This,pwszURL,pWszVerb,pwszHeaders,nAcceptTypes,rgwszAcceptTypes,pbBuffer,cbBuffer,pcallback,dwContext)	\
    (This)->lpVtbl -> RequestWithBuffer(This,pwszURL,pWszVerb,pwszHeaders,nAcceptTypes,rgwszAcceptTypes,pbBuffer,cbBuffer,pcallback,dwContext)

// shell\ext\neptune\aidanl\davtrans\ifaces\idavinet.h
#define IDavTransport_CommandREPLSEARCH(This,pwszUrl,cbCollblob,pbCollblob,pCallback,dwCallbackParam)	\
    (This)->lpVtbl -> CommandREPLSEARCH(This,pwszUrl,cbCollblob,pbCollblob,pCallback,dwCallbackParam)

// shell\ext\neptune\aidanl\davtrans\ifaces\ihttpstrm.h
#define IHttpStrm_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define IHttpStrm_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define IHttpStrm_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)

// shell\ext\pstore\inc\pstore.h
#define IPStore_GetProvParam(This,dwParam,pcbData,ppbData,dwFlags)	\
    (This)->lpVtbl -> GetProvParam(This,dwParam,pcbData,ppbData,dwFlags)
#define IPStore_SetProvParam(This,dwParam,cbData,pbData,dwFlags)	\
    (This)->lpVtbl -> SetProvParam(This,dwParam,cbData,pbData,dwFlags)
#define IPStore_ReadItem(This,Key,pItemType,pItemSubtype,szItemName,pcbData,ppbData,pPromptInfo,dwFlags)	\
    (This)->lpVtbl -> ReadItem(This,Key,pItemType,pItemSubtype,szItemName,pcbData,ppbData,pPromptInfo,dwFlags)
#define IPStore_WriteItem(This,Key,pItemType,pItemSubtype,szItemName,cbData,pbData,pPromptInfo,dwDefaultConfirmationStyle,dwFlags)	\
    (This)->lpVtbl -> WriteItem(This,Key,pItemType,pItemSubtype,szItemName,cbData,pbData,pPromptInfo,dwDefaultConfirmationStyle,dwFlags)

// shell\ext\url\cfmacros.h
#define DECLARE_CLASS_FACTORY(cf)                                \
   class cf                                                      \
   {                                                             \
     public:                                                     \
       void *vtable;                                             \
       STDMETHODX (QueryInterface)(REFIID, void **);             \
       STDMETHODX_(ULONG, AddRef)();                             \
       STDMETHODX_(ULONG, Release)();                            \
                                                                 \
       STDMETHODX (CreateInstance)(IUnknown *, REFIID, void **); \
       STDMETHODX (LockServer)(BOOL);                            \
   }                                                             \

// shell\ext\webcheck\imnact.h
#define IImnAccount_GetProp(This,dwPropTag,pb,pcb)	\
    (This)->lpVtbl -> GetProp(This,dwPropTag,pb,pcb)
#define IImnAccount_SetProp(This,dwPropTag,pb,cb)	\
    (This)->lpVtbl -> SetProp(This,dwPropTag,pb,cb)
#define IImnAccount_ValidateProperty(This,dwPropTag,pb,cb)	\
    (This)->lpVtbl -> ValidateProperty(This,dwPropTag,pb,cb)

// shell\ext\webvw\dxmplay.h
#define IMediaPlayer_get_BufferingCount(This,pBufferingCount)	\
    (This)->lpVtbl -> get_BufferingCount(This,pBufferingCount)
#define IMediaPlayer_get_BufferingProgress(This,pBufferingProgress)	\
    (This)->lpVtbl -> get_BufferingProgress(This,pBufferingProgress)
#define IMediaPlayer_get_BufferingTime(This,pBufferingTime)	\
    (This)->lpVtbl -> get_BufferingTime(This,pBufferingTime)
#define IMediaPlayer_put_BufferingTime(This,BufferingTime)	\
    (This)->lpVtbl -> put_BufferingTime(This,BufferingTime)

// shell\inc\cfdefs.h
#define DECLARE_CLASS_FACTORY(cf)                                \
   class cf                                                      \
   {                                                             \
     public:                                                     \
       IClassFactory *vtable;                                    \
       STDMETHODX (QueryInterface)(REFIID, void **);             \
       STDMETHODX_(ULONG, AddRef)();                             \
       STDMETHODX_(ULONG, Release)();                            \
                                                                 \
       STDMETHODX (CreateInstance)(IUnknown *, REFIID, void **); \
       STDMETHODX (LockServer)(BOOL);                            \
   }                                                             \

// shell\inc\evtmon\emkwd.h
#define MsoRgpkwdHashFromKwtb(pkwtb) \
            ((MSOKWD **) (pkwtb)->pvTable)
#define MsoPkwdlFromKwtb(pkwtb) \
            ((MSOKWDL *) (pkwtb)->pvTable)
#define MsoRgpkwdlhFromKwtb(pkwtb) \
            ((MSOKWDLH **) (pkwtb)->pvTable)

// shell\inc\evtmon\emoci.h
#define PcbArgFromOcad(ocad, pocis) \
            (&(pocis)->rgcbImmedArg[ocad])

// shell\inc\evtmon\msolex.h
#define IchLexTkFirst(plexs) \
            ((plexs)->pxchTkStart - (plexs)->pxchBuffer)

// shell\inc\heapaloc.h
#define Alloc(cb)                             HeapLocalAlloc(LMEM_ZEROINIT | LMEM_FIXED, cb)
#define ReAlloc(pb, cb)                       HeapLocalReAlloc(pb, cb, LMEM_ZEROINIT | LMEM_FIXED)

// shell\osshell\control\mmsys\utils.h
#define GReAlloc(pv, cbNewSize) GlobalReAlloc(pv, GMEM_MOVEABLE | GMEM_ZEROINIT, cbNewSize)

// shell\osshell\cpls\ports\pp.h
#define IDH_DEVMGR_PORTSET_ADV_USEFIFO  16885   // "&Use FIFO buffers (requires 16550 compatible UART)" (Button)

// shell\osshell\lmui\shareui\shares.h
#define Share_GetComment(pidl)      (&(pidl->cBuf[pidl->oComment]))
#define Share_GetPath(pidl)         (&(pidl->cBuf[pidl->oPath]))

// shell\osshell\progman\progman.h
#define MYCBN_SELCHANGE     (WM_USER+5)

// shell\osshell\snapins\devmgr\snapin\hwtab.cpp
#define BUFFERQUERY_SUCCEEDED(f)    \
            ((f) || GetLastError() == ERROR_INSUFFICIENT_BUFFER)

// shell\osshell\themes\inc\mstask.h
#define IScheduledWorkItem_SetWorkItemData(This,cbData,rgbData)	\
    (This)->lpVtbl -> SetWorkItemData(This,cbData,rgbData)
#define IScheduledWorkItem_GetWorkItemData(This,pcbData,prgbData)	\
    (This)->lpVtbl -> GetWorkItemData(This,pcbData,prgbData)
#define ITask_SetWorkItemData(This,cbData,rgbData)	\
    (This)->lpVtbl -> SetWorkItemData(This,cbData,rgbData)
#define ITask_GetWorkItemData(This,pcbData,prgbData)	\
    (This)->lpVtbl -> GetWorkItemData(This,pcbData,prgbData)

// shell\shell32\filefldr.cpp
#define FVCBFT_MUSICFOLDER(ft)  (FVCBFT_MUSIC == ft || FVCBFT_MYMUSIC == ft || FVCBFT_MUSICARTIST == ft || FVCBFT_MUSICALBUM == ft)

// shell\shell32\hwcmmn.h
#define CT_BLANKCDWRITABLE             (   CT_BLANKCDR | \
                                                        CT_BLANKCDRW )
#define CT_BLANKDVDWRITABLE            (   CT_BLANKDVDR | \
                                                        CT_BLANKDVDRW )

// shell\shell32\mtpt.h
#define DT_ANYWRITABLECDDRIVES           (   DT_CDR | \
                                                        DT_CDRW )
#define DT_ANYWRITABLEDVDDRIVES          (   DT_DVDR | \
                                                        DT_DVDRW )

// shell\themes\uxtheme\handlers.h
#define END_SPIHANDLER_TABLE()                    }return FALSE;}

// termsrv\remdsk\common\imsconf2.h
#define INmSysInfo_GetUserData(This,rguid,ppb,pcb)	\
    (This)->lpVtbl -> GetUserData(This,rguid,ppb,pcb)
#define INmSysInfo_SetUserData(This,rguid,pb,cb)	\
    (This)->lpVtbl -> SetUserData(This,rguid,pb,cb)
#define INmCall_GetUserData(This,rguid,ppb,pcb)	\
    (This)->lpVtbl -> GetUserData(This,rguid,ppb,pcb)

// termsrv\remdsk\rds\as\h\ba.h
#define BA_FST_START_READING    &g_asSharedMemory->baFast[\
            1 - g_asSharedMemory->fastPath.newBuffer]
#define BA_FST_START_WRITING    &g_asSharedMemory->baFast[\
            1 - g_asSharedMemory->fastPath.newBuffer]

// termsrv\remdsk\rds\as\h\cm.h
#define CM_SHM_START_READING  &g_asSharedMemory->cmFast[\
                   1 - g_asSharedMemory->fastPath.newBuffer]

// termsrv\remdsk\rds\as\h\oa.h
#define OA_FST_START_READING    &g_asSharedMemory->oaFast[\
        1 - g_asSharedMemory->fastPath.newBuffer]
#define OA_FST_START_WRITING    &g_asSharedMemory->oaFast[\
        1 - g_asSharedMemory->fastPath.newBuffer]

// termsrv\remdsk\rds\dev\inc16\windows.h
#define DCB_SET         (DCB_RESET | DCB_ACCUMULATE)
#define EM_EMPTYUNDOBUFFER      (WM_USER+29)
#define LBCB_CARETON            (WM_USER+36)    // ;Internal
#define LBCB_CARETOFF           (WM_USER+37)    // ;Internal
#define CB_FIRST_16             (WM_USER+0) // ;Internal
#define CB_GETEDITSEL           (WM_USER+0)
#define CB_SETEDITSEL           (WM_USER+2)
#define CB_DIR                  (WM_USER+5)
#define CB_GETCURSEL            (WM_USER+7)
#define CB_RESETCONTENT         (WM_USER+11)
#define CB_SETCURSEL            (WM_USER+14)
#define CB_SHOWDROPDOWN         (WM_USER+15)
#define CB_GETITEMDATA          (WM_USER+16)
#define CB_SETITEMDATA          (WM_USER+17)
#define CB_GETDROPPEDCONTROLRECT (WM_USER+18)
#define CB_SETITEMHEIGHT        (WM_USER+19)
#define CB_GETITEMHEIGHT        (WM_USER+20)
#define CB_GETDROPPEDSTATE      (WM_USER+23)
#define CB_SETLOCALE            (WM_USER+25)    /* ;Internal NT */
#define CB_GETLOCALE            (WM_USER+26)    /* ;Internal NT */
#define CB_FIRST_40             (WM_USER+27)    // ;Internal 4.0
#define CB_GETTOPINDEX          (WM_USER+27)    /* ;Internal 4.0 */
#define CB_SETTOPINDEX          (WM_USER+28)    /* ;Internal 4.0 */
#define CB_GETHORIZONTALEXTENT  (WM_USER+29)    /* ;Internal 4.0 */
#define CB_SETHORIZONTALEXTENT  (WM_USER+30)    /* ;Internal 4.0 */
#define CB_GETDROPPEDWIDTH      (WM_USER+31)    /* ;Internal 4.0 */
#define CB_SETDROPPEDWIDTH      (WM_USER+32)    /* ;Internal 4.0 */
#define CB_INITSTORAGE          (WM_USER+33)    /* ;Internal 4.0 */

// termsrv\remdsk\rds\h\memtrack.h
#define MemReAlloc(pObj, cbSize)    LocalReAlloc((pObj), (cbSize), LMEM_MOVEABLE | LMEM_ZEROINIT)

// tools\x86\perl\lib\core\perl.h
#define RsRECORD(sv)  (SvROK(sv) && (SvIV(SvRV(sv)) > 0))

// tools\x86\perl\lib\core\sv.h
#define Gv_AMG(stash) \
        (HV_AMAGICmb(stash) && \
         ((!HV_AMAGICbad(stash) && HV_AMAGIC(stash)) || Gv_AMupdate(stash)))

// windows\advcore\ctf\inc\sapi.h
#define ISpDataKey_SetData(This,pszValueName,cbData,pData)	\
    (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData)
#define ISpDataKey_GetData(This,pszValueName,pcbData,pData)	\
    (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData)
#define ISpRegDataKey_SetData(This,pszValueName,cbData,pData)	\
    (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData)
#define ISpRegDataKey_GetData(This,pszValueName,pcbData,pData)	\
    (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData)
#define ISpObjectTokenCategory_SetData(This,pszValueName,cbData,pData)	\
    (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData)
#define ISpObjectTokenCategory_GetData(This,pszValueName,pcbData,pData)	\
    (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData)
#define ISpObjectToken_SetData(This,pszValueName,cbData,pData)	\
    (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData)
#define ISpObjectToken_GetData(This,pszValueName,pcbData,pData)	\
    (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData)
#define ISpObjectToken_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)	\
    (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)
#define ISpObjectToken_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject)	\
    (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject)
#define ISpObjectTokenInit_SetData(This,pszValueName,cbData,pData)	\
    (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData)
#define ISpObjectTokenInit_GetData(This,pszValueName,pcbData,pData)	\
    (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData)
#define ISpObjectTokenInit_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)	\
    (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)
#define ISpObjectTokenInit_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject)	\
    (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject)
#define ISpStreamFormat_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISpStreamFormat_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define ISpStreamFormat_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define ISpStream_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISpStream_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define ISpStream_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define ISpStreamFormatConverter_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISpStreamFormatConverter_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define ISpStreamFormatConverter_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define ISpAudio_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISpAudio_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define ISpAudio_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define ISpAudio_SetBufferInfo(This,pBuffInfo)	\
    (This)->lpVtbl -> SetBufferInfo(This,pBuffInfo)
#define ISpAudio_GetBufferInfo(This,pBuffInfo)	\
    (This)->lpVtbl -> GetBufferInfo(This,pBuffInfo)
#define ISpAudio_GetBufferNotifySize(This,pcbSize)	\
    (This)->lpVtbl -> GetBufferNotifySize(This,pcbSize)
#define ISpAudio_SetBufferNotifySize(This,cbSize)	\
    (This)->lpVtbl -> SetBufferNotifySize(This,cbSize)
#define ISpMMSysAudio_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)
#define ISpMMSysAudio_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)
#define ISpMMSysAudio_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)
#define ISpMMSysAudio_SetBufferInfo(This,pBuffInfo)	\
    (This)->lpVtbl -> SetBufferInfo(This,pBuffInfo)
#define ISpMMSysAudio_GetBufferInfo(This,pBuffInfo)	\
    (This)->lpVtbl -> GetBufferInfo(This,pBuffInfo)
#define ISpMMSysAudio_GetBufferNotifySize(This,pcbSize)	\
    (This)->lpVtbl -> GetBufferNotifySize(This,pcbSize)
#define ISpMMSysAudio_SetBufferNotifySize(This,cbSize)	\
    (This)->lpVtbl -> SetBufferNotifySize(This,cbSize)
#define ISpVoice_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported)	\
    (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported)
#define ISpVoice_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData)	\
    (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData)
#define ISpRecoGrammar_LoadCmdFromProprietaryGrammar(This,rguidParam,pszStringParam,pvDataPrarm,cbDataSize,Options)	\
    (This)->lpVtbl -> LoadCmdFromProprietaryGrammar(This,rguidParam,pszStringParam,pvDataPrarm,cbDataSize,Options)
#define ISpRecognizer_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported)	\
    (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported)
#define ISpRecognizer_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData)	\
    (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData)

// windows\advcore\ctf\sapilayr\hwxink.h
#define IThorFnConversion_QueryRange(This,pRange,ppNewRange,pfConvertable)	\
    (This)->lpVtbl -> QueryRange(This,pRange,ppNewRange,pfConvertable)

// windows\advcore\duser\directui\engine\parser\scan.cpp
#define yy_set_bol(at_bol) \
    { \
    if ( ! yy_current_buffer ) \
        yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
    yy_current_buffer->yy_at_bol = at_bol; \
    }

// windows\advcore\duser\directui\test\app\arp\shappmgrp.h
#define IADCCtl_Exec(This,bstrQualifier,bstrCmd,nRecord)	\
    (This)->lpVtbl -> Exec(This,bstrQualifier,bstrCmd,nRecord)

// windows\advcore\gdiplus\engine\entry\metaplay.cpp
#define EMFPLUS_MAJORVERSION(v)             ((v) & 0xFFFF0000)

// windows\advcore\gdiplus\engine\text\inc\unipart.hxx
#define WCB_ 10     //   9 - Close brackets for inline-note (JIS 2 or 20)

// windows\advcore\gdiplus\test\driverhack\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// windows\advcore\gdiplus\test\fractal\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// windows\advcore\gdiplus\test\functest\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// windows\advcore\gdiplus\test\perftest\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// windows\advcore\gdiplus\test\pseudotest\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// windows\advcore\rcml\rcml\xmlparser.h
#define IXMLNodeSource_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLNodeSource_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLParser_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_PushData(This,pData,ulChars,fLastBuffer)	\
    (This)->lpVtbl -> PushData(This,pData,ulChars,fLastBuffer)

// windows\advcore\rcml\rcmlex\appsvcs\wbemcli.h
#define IWbemObjectAccess_ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData)	\
    (This)->lpVtbl -> ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData)
#define IMofCompiler_CompileBuffer(This,BuffSize,pBuffer,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo)	\
    (This)->lpVtbl -> CompileBuffer(This,BuffSize,pBuffer,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo)

// windows\advcore\rcml\xmllib\xml\tokenizer\parser\xmlparser.h
#define IXMLNodeSource_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLNodeSource_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLParser_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_PushData(This,pData,ulChars,fLastBuffer)	\
    (This)->lpVtbl -> PushData(This,pData,ulChars,fLastBuffer)

// windows\advcore\rcml\xmllib\xml\tokenizer\xmlparser.h
#define IXMLNodeSource_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLNodeSource_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)	\
    (This)->lpVtbl -> GetLineBuffer(This,ppwcBuf,pulLen,pulStartPos)
#define IXMLParser_GetURL(This,ppwcBuf)	\
    (This)->lpVtbl -> GetURL(This,ppwcBuf)
#define IXMLParser_PushData(This,pData,ulChars,fLastBuffer)	\
    (This)->lpVtbl -> PushData(This,pData,ulChars,fLastBuffer)

// windows\appcompat\shims\inc\heap.h
#define hpSetSize2(ph, cb) *(unsigned long *)(ph) &= ~HP_SIZE; \
               *(unsigned long *)(ph) |= (cb);
#define hpSetBusySize(ph, cb)   ((ph)->bh_size = ((cb) | HP_SIGNATURE))

// windows\appcompat\shims\layer\emulateheap_heap.h
#define hpSetSize2(ph, cb) *(unsigned long *)(ph) &= ~HP_SIZE; \
			   *(unsigned long *)(ph) |= (cb);
#define hpSetBusySize(ph, cb)	((ph)->bh_size = ((cb) | HP_SIGNATURE))

// windows\appcompat\tools\appsearch\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// windows\appcompat\tools\smvtest\common\afxres.h
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT)

// windows\core\cslpk\lpk\lpk_edit.c
    #define EDWCBLANK(ich) ((BOOL) (EDWCH(ich) == SP || EDWCH(ich) == TAB))

// windows\core\ntcon\inc\conime.h
#define CONIME_NOTIFY_SCREENBUFFERSIZE  (WM_USER+7)

// windows\core\ntgdi\client\local.h
#define GET_PMFRECORDER16(pmf,hdc)          \
{                                           \
    pmf = (PMFRECORDER16)plinkGet(hdc);     \
    if (pmf)                                \
        pmf = ((PLINK)pmf)->pv;             \
}

// windows\core\ntgdi\test\fonttest.nt\comdlg32mm\font.h
#define CBN_MYEDITUPDATE     (WM_USER + 501)

// windows\core\ntuser\client\usercli.h
#define SDROPDOWN       (SDROPPABLE | SEDITABLE)
#define IsComboVisible(pcbox) (!pcbox->fNoRedraw && IsVisible(pcbox->spwnd))
#define GetCallBackDbcsInfo()          (&(GetClientInfo()->msgDbcsCB))

// windows\core\ntuser\inc\user.h
#define TESTSYNCONLYMESSAGE(msg, wParam) (((msg) < WM_USER) ?       \
        (   (MessageTable[msg].bSyncOnlyMessage) ||                 \
            (((msg) == WM_DEVICECHANGE) && ((wParam) & 0x8000))) :  \
        0)

// windows\core\ntuser\kernel\desktop.c
#define DESKTOP_ALL (DESKTOP_READOBJECTS     | DESKTOP_CREATEWINDOW     | \
                     DESKTOP_CREATEMENU      | DESKTOP_HOOKCONTROL      | \
                     DESKTOP_JOURNALRECORD   | DESKTOP_JOURNALPLAYBACK  | \
                     DESKTOP_ENUMERATE       | DESKTOP_WRITEOBJECTS     | \
                     DESKTOP_SWITCHDESKTOP   | DESKTOP_QUERY_INFORMATION | \
                     DESKTOP_REDIRECT        | STANDARD_RIGHTS_REQUIRED)
#define DESKTOP_ALL (DESKTOP_READOBJECTS     | DESKTOP_CREATEWINDOW     | \
                     DESKTOP_CREATEMENU      | DESKTOP_HOOKCONTROL      | \
                     DESKTOP_JOURNALRECORD   | DESKTOP_JOURNALPLAYBACK  | \
                     DESKTOP_ENUMERATE       | DESKTOP_WRITEOBJECTS     | \
                     DESKTOP_SWITCHDESKTOP   | STANDARD_RIGHTS_REQUIRED)

// windows\core\ntuser\kernel\kbdlyout.c
#define GET_HEADER_FIELD(x) \
    ((fWin64Header) ? (NtHeader64->x) : (NtHeader32->x))

// windows\core\ntuser\kernel\ssend.c
#define BEGINSEND(api) \
    mp = &m; \
    Buffer;  \
    {
#define UNLOCKPWND() \
    pci->CallbackWnd = cbwin;       \
    ThreadUnlock(&tlpwnd);

// windows\richedit\inci\lstxtbrs.h
#define FCanBreak(pilsobj,b1, b2) \
	((pilsobj)->plsbrk[(pilsobj)->pilsbrk[(pilsobj)->cBreakingClasses * (b1) + (b2)]].fBreak)
#define FCanBreakAcrossSpaces(pilsobj, b1, b2) \
	((pilsobj)->plsbrk[(pilsobj)->pilsbrk[pilsobj->cBreakingClasses * (b1) + (b2)]].fBreakAcrossSpaces)

// windows\richedit\lssrc\lstxtscl.c
#define FAdjustable(ptxtobj) (!((ptxtobj)->txtf & txtfSkipAtWysi)  && \
						((ptxtobj)->iwchLim - (ptxtobj)->iwchFirst > 0))

// windows\richedit\re41\_common.h
#define EM_INSERTTABLE			(WM_USER + 232)

// windows\richedit\re41\aimmex.h
#define IAImmFnDocFeed_ClearDocFeedBuffer(This)	\
    (This)->lpVtbl -> ClearDocFeedBuffer(This)

// windows\richedit\re41\cfpf.cpp
#define PFM_IGNORE	(PFM_OUTLINELEVEL | PFM_COLLAPSED | PFM_BOX | PFM_TABLE | PFM_TABLEROWDELIMITER)

// windows\richedit\re41\ctffunc.h
#define ITfFnReconversion_QueryRange(This,pRange,ppNewRange,pfConvertable)	\
    (This)->lpVtbl -> QueryRange(This,pRange,ppNewRange,pfConvertable)

// windows\richedit\re41\hwxink.h
#define IThorFnConversion_QueryRange(This,pRange,ppNewRange,pfConvertable)	\
    (This)->lpVtbl -> QueryRange(This,pRange,ppNewRange,pfConvertable)

// windows\richedit\re41\msctf.h
#define ITfQueryEmbedded_QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)	\
    (This)->lpVtbl -> QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)
#define ITfEditRecord_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ITfEditRecord_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)
#define ITfEditRecord_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define ITfEditRecord_GetSelectionStatus(This,pfChanged)	\
    (This)->lpVtbl -> GetSelectionStatus(This,pfChanged)
#define ITfEditRecord_GetTextAndPropertyUpdates(This,dwFlags,prgProperties,cProperties,ppEnum)	\
    (This)->lpVtbl -> GetTextAndPropertyUpdates(This,dwFlags,prgProperties,cProperties,ppEnum)
#define ITfTextEditSink_OnEndEdit(This,pic,ecReadOnly,pEditRecord)	\
    (This)->lpVtbl -> OnEndEdit(This,pic,ecReadOnly,pEditRecord)
#define ITfPropertyStore_Serialize(This,pStream,pcb)	\
    (This)->lpVtbl -> Serialize(This,pStream,pcb)
#define ITfCreatePropertyStore_CreatePropertyStore(This,guidProp,pRange,cb,pStream,ppStore)	\
    (This)->lpVtbl -> CreatePropertyStore(This,guidProp,pRange,cb,pStream,ppStore)

// windows\richedit\re41\textstor.h
#define ITextStoreACP_QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)	\
    (This)->lpVtbl -> QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)
#define ITextStoreAnchor_QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)	\
    (This)->lpVtbl -> QueryInsertEmbedded(This,pguidService,pFormatEtc,pfInsertable)
```

