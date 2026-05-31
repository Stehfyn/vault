# Miscellaneous Local Idioms

[Macros index](<macros.md>)

## Curated Candidates

```c
// shell\browseui\dockbar.h
#define _PM(p, m)       ((p) ? (p)->m : (-1))

#define _PX(p, x)       ((p) ? (x) : (-1))

// sdktools\vi\normal.c
#define DEFAULT1(x)     (((x) == 0) ? 1 : (x))

// admin\cmdline\gpresult\gpresult.h
#define DESTROY_ARRAY( array )  \
    if ( (array) != NULL )  \
    {   \
        DestroyDynamicArray( &(array) );    \
        (array) = NULL; \
    }   \
    1

// shell\comctl32\v5\flat_sb.h
#define DMultDiv(A, B, C)   (((C) == 0)? (A):(MulDiv((A), (B), (C))))

// windows\winstate\cobra\modules\script\oeutils.c
#define IF_NULLEND(x) if (NULL==x) { goto end; }

// shell\ext\webvw\wvmacros.h
#define IfFalseRet(val, hr) {if ((val) == 0) return (hr);}

// shell\osshell\accesory\hypertrm\xfer\xfer.hh
#define PART_HUNKS(n, s) ((long)(n) == 0L ? 0L : ((long)(n) - 1L) / (long)(s) + 1L)

// shell\tools\starbuck\dllreg.cpp
#define QuietInstallNoOp(hr)   ((E_UNEXPECTED == hr) ? S_OK : hr)

// ds\ds\src\util\repadmin\repldap.c
#define SAFE_LDAP_FIRST_ENTRY(h, r) (r ? ldap_first_entry( h, r ) : NULL)

// admin\cmdline\gpresult\gpresult.h
#define SAFEDELETE( pObj ) \
    if (pObj) \
    {   \
        delete[] pObj; \
        pObj = NULL; \
    }\
    1

// base\busdrv\acpi\driver\amlinew\amlipriv.h
#define SHIFTLEFT(d,c)          (((c) >= 32)? 0: (d) << (c))

#define SHIFTRIGHT(d,c)         (((c) >= 32)? 0: (d) >> (c))

// shell\browseui\legacy\track.cpp
#define SMFORWARD(x) if (!_psm) { return E_FAIL; } else return _psm->x

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\mlxscsi.h
#define	UCSGETG0COUNT(cdbp)     (((cdbp)->g0_count0 == 0) ? 0x100 : (cdbp)->g0_count0)

// shell\shell32\unicpp\colorctrl.cpp
#define ZERO_DIV_PROTECT(number)            (((number) == 0) ? 1 : (number))
```

## Backlog

```c
// drivers\input\neckbadd\neckbadd.h
#define CLASSSERVICE_CALLBACK(_X_, _Y_) \
    (*(PSERVICE_CALLBACK_ROUTINE) devExt->UpperConnectData.ClassService)( \
        devExt->UpperConnectData.ClassDeviceObject, \
        _X_, \
        _Y_, \
        InputDataConsumed);
#define CLASSSERVICE_CALLBACK(_X_, _Y_) \
    (*(PSERVICE_CALLBACK_ROUTINE) devExt->UpperConnectData.ClassService)( \
        devExt->UpperConnectData.ClassDeviceObject, \
        _X_, \
        _Y_, \
        InputDataConsumed);

// drivers\input\pnpi8042\i8042prt.h
#define IBM02_KEYBOARD(Id)     (((Id).Type == 0x7) && ((Id).Subtype == FE_SUBTYPE(3,MSFT)))
#define AX_KEYBOARD(Id)        (((Id).Type == 0x7) && ((Id).Subtype == FE_SUBTYPE(1,MSFT)))
#define OYAYUBI_KEYBOARD(Id)   (((Id).Type == 0x7) && ((Id).Subtype == FE_SUBTYPE(2,FJ)))
#define DEC_KANJI_KEYBOARD(Id) (((Id).Type == 0x7) && (((Id).Subtype == FE_SUBTYPE(1,DECJ)) || \
                                                       ((Id).Subtype == FE_SUBTYPE(2,DECJ))))

// drivers\input\pnpi8042\kbddep.c
#define GET_MAKE_CODE(_sc_)  (_sc_ & 0x7F)

// drivers\input\pnpi8042\moudep.c
#define RML_BUTTONS    (RIGHT_BUTTON | MIDDLE_BUTTON | LEFT_BUTTON)
#define BUTTONS_4_5    (BUTTON_4 | BUTTON_5)

// drivers\input\sermouse\uart.h
#define   ACE_LERR  (ACE_OR | ACE_PE | ACE_FE | ACE_BI)

// drivers\ksfilter\ks\ksp.h
#define KspFastMutexIsAcquired(m)\
    ((m)->Count != 1)

// drivers\ksfilter\ksdsp\inc\epd.h
#define EPD_CODE(_function_,_method_)  CTL_CODE(FILE_DEVICE_EPD, 0x800 | (_function_), (_method_), FILE_ANY_ACCESS)

// drivers\ksfilter\tests\irpperf\sys\irp.h
#define IOCTL_BUILD_EACH	CTL_CODE(FILE_DEVICE_SOUND, 0x000, METHOD_NEITHER, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_BUILD_ONE		CTL_CODE(FILE_DEVICE_SOUND, 0x001, METHOD_NEITHER, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// drivers\ksfilter\tests\irqperf\sys\stat.h
#define IOCTL_STAT_RUN              CTL_CODE( FILE_DEVICE_UNKNOWN, 0x001, METHOD_NEITHER, FILE_WRITE_ACCESS | FILE_READ_ACCESS)
#define IOCTL_STAT_STOP             CTL_CODE( FILE_DEVICE_UNKNOWN, 0x002, METHOD_NEITHER, FILE_WRITE_ACCESS | FILE_READ_ACCESS)

// drivers\net\irda\mknet\sys\mk7.h
#define MK7DisableIr(adapter)	(MK7Reg_Write(adapter, R_ENAB, ~B_ENAB_IRENABLE))
#define	MK7RXInterrupt(x)	( (x & B_RX_INTS) || (x & B_TEST_INTS) )
#define	MK7TXInterrupt(x)	( (x & B_TX_INTS) || (x & B_TEST_INTS) )
#define	MK7RXInterrupt(x)	(x & B_RX_INTS)
#define	MK7TXInterrupt(x)	(x & B_TX_INTS)

// drivers\parallel\parclass\parclass.h
#define DCR_NEUTRAL (DCR_RESERVED | DCR_SELECT_IN | DCR_NOT_INIT)

// drivers\parallel\parport2\parport.h
#define DCR_NEUTRAL (DCR_RESERVED | DCR_SELECT_IN | DCR_NOT_INIT)

// drivers\serial\mps\spx\mps\io8\incl\io8_nt.h
#define GET_CHANNEL(x) ((x) & 0x7)

// drivers\serial\mps\spx\mps\sx\inc\sxboards.h
#define		CARD_PHASE(type)	(type&0xF)

// drivers\serial\mps\spx\speed\uartlib\inc\private\16c65x.h
#define READ_INTERRUPT_ENABLE_65X(pUart)		\
	((PUART_DATA_16C65X)((pUart)->pUartData))->CurrentIER

// drivers\serial\mps\spx\speed\uartlib\inc\private\16c95x.h
#define READ_INTERRUPT_ENABLE(pUart)		\
	((PUART_DATA_16C95X)((pUart)->pUartData))->CurrentIER

// drivers\serial\mps\spx\speed\uartlib\inc\public\uartlib.h
#define UL_MC_INPUT_SIGNALS_CHANGED	(UL_MC_DELTA_DCD | UL_MC_TRAILING_RI_EDGE | UL_MC_DELTA_DSR | UL_MC_DELTA_CTS)

// drivers\smartcrd\gempc430\kernel.h
#define IMPLEMENT_CALLBACK_VOID0(f)	\
			VOID f(PDEVICE_OBJECT pDO)\
				{if(CDEVICE(pDO)) CDEVICE(pDO)->f();}
#define IMPLEMENT_CALLBACK_BOOL0(f)	\
			BOOL f(PDEVICE_OBJECT pDO) \
				{if(!CDEVICE(pDO)) return FALSE; return CDEVICE(pDO)->f();}
#define IMPLEMENT_CALLBACK_VOID1(f,type)\
		VOID f(PDEVICE_OBJECT pDO,type arg)\
				{if(CDEVICE(pDO)) CDEVICE(pDO)->f(arg);}
#define IMPLEMENT_CALLBACK_DPCR(fname,type1,type2)	\
			VOID fname(PKDPC Dpc, PDEVICE_OBJECT pDO,type1 arg1, type2 arg2)\
				{if(CDEVICE(pDO)) CDEVICE(pDO)->DpcForIsr(Dpc, arg1,arg2);}

// drivers\smartcrd\rnb3531\rnbo3531.rc
#define VER_PRODUCTVERSION_DW       (0x01000000 | 26)

// drivers\smartcrd\scmstcs\serialnt.h
#define SR_PURGE							( SERIAL_PURGE_RXCLEAR | SERIAL_PURGE_TXCLEAR )

// drivers\storage\fdc\fdc\q117_dat.h
#define NUM_TTRK_40         20      // number of tape tracks (QIC-40 205ft & 310ft)
#define NUM_TTRK_80         28      // number of tape tracks (QIC-40 205ft & 310ft)

// drivers\storage\fdc\inc\q117_dat.h
#define NUM_TTRK_40         20      // number of tape tracks (QIC-40 205ft & 310ft)
#define NUM_TTRK_80         28      // number of tape tracks (QIC-40 205ft & 310ft)

// drivers\storage\fdc\mode3fdc\desk2fdc\q117_dat.h
#define NUM_TTRK_40         20      // number of tape tracks (QIC-40 205ft & 310ft)
#define NUM_TTRK_80         28      // number of tape tracks (QIC-40 205ft & 310ft)

// drivers\storage\ide\inc\ideuser.h
#define PIO_SUPPORT         (PIO_MODE0      | PIO_MODE1     | PIO_MODE2    | PIO_MODE3     | PIO_MODE4)
#define SWDMA_SUPPORT       (SWDMA_MODE0    | SWDMA_MODE1   | SWDMA_MODE2)
#define MWDMA_SUPPORT       (MWDMA_MODE0    | MWDMA_MODE1   | MWDMA_MODE2)
#define UDMA33_SUPPORT      (UDMA_MODE0     | UDMA_MODE1    | UDMA_MODE2)
#define UDMA66_SUPPORT      (UDMA_MODE3     | UDMA_MODE4)
#define UDMA_SUPPORT        (UNINITIALIZED_TRANSFER_MODE & (~(PIO_SUPPORT | SWDMA_SUPPORT | MWDMA_SUPPORT)))
#define DMA_SUPPORT         (SWDMA_SUPPORT  | MWDMA_SUPPORT | UDMA_SUPPORT)
#define ALL_MODE_SUPPORT    (PIO_SUPPORT | DMA_SUPPORT)

// drivers\storage\ide\pciidex\ctlrfdo.h
#define IsNativeMode(d) ((d)->NativeMode[0] && (d)->NativeMode[1])

// drivers\storage\redbook\redbook.h
#define TAG_GET_DESC   'edBR' // storage descriptor (returned to caller)

// drivers\storage\scsiport\port.h
#define TAG(x)  (x | 0x80000000)
#define SCSIPORT_TAG_ENABLE             TAG('pPcS')  // device & adapter enable
#define PutDmaAdapter(DmaAdapter)                                           \
            ((DmaAdapter)->DmaOperations->PutDmaAdapter)((DmaAdapter))

// drivers\storage\tffsport\diskonc.h
#define ECC_EN    (0x08 | ECC_RESERVED) /* 1 - enable ECC */
#define ECC_RW    (0x20 | ECC_RESERVED) /* 1 - write mode, 0 - read mode */

// drivers\storage\tffsport\fatfilt.c
#define  H2S(handle)     (((int)(handle)) & 0xf)

// drivers\storage\tffsport\ftllite.c
#define cannotWriteOver(newContents, oldContents)		\
		((newContents) & ~(oldContents))
#define flashWrite(v,address,from,length,overwrite)	\
		(v)->flash.write(&(v)->flash,address,from,length,overwrite)

// drivers\storage\tffsport\inftl.c
#define isLegalUnit(unitNo)  ((unitNo < vol.noOfUnits) || (unitNo == ANAND_NO_UNIT))

// drivers\storage\tffsport\nftllite.h
#define setUnavail(unitNo)  {vol.physicalUnits[unitNo] &= ~UNIT_COUNT; vol.physicalUnits[unitNo] |= UNIT_UNAVAIL; }
#define isReplaced(unitNo)  (vol.physicalUnits[unitNo] & UNIT_REPLACED)
#define isLegalUnit(unitNo)  ((unitNo < vol.noOfUnits) || (unitNo == ANAND_NO_UNIT))

// drivers\storage\volsnap\vss\modules\sqllib\inc\odbcss.h
#define SQL_CO_FFO_AF	(SQL_CO_FFO|SQL_CO_AF)	//	Fast-forward cursor with autofetch

// drivers\storage\volsnap\vss\server\modules\sqllib\inc\odbcss.h
#define SQL_CO_FFO_AF	(SQL_CO_FFO|SQL_CO_AF)	//	Fast-forward cursor with autofetch

// drivers\tpg\hwx\bear\inc\calcmacr.h
#define  wODD(w)   ((w)&1)
#define  HEIGHT_OF(elem)        (REF(elem)->attr & _umd_)
#define  CIRCLE_DIR(elem)            (REF(elem)->attr & _fb_)

// drivers\tpg\hwx\bear\inc\hwr_file.h
#define HWR_FILE_OPEN      (HWR_FILE_EXIST_OPEN|HWR_FILE_NOTEXIST_CREATE)
#define HWR_FILE_TRUNC     (HWR_FILE_EXIST_CREATE|HWR_FILE_NOTEXIST_CREATE)
#define HWR_FILE_APPEND    (HWR_FILE_EXIST_APPEND|HWR_FILE_NOTEXIST_CREATE)

// drivers\tpg\hwx\bear\inc\hwr_sys.h
#define HWRMathSqrt(d) (HWRMathSystemSqrt(d,&dTmpResult),dTmpResult)
#define HWRMathExp(d) (HWRMathSystemExp(d,&dTmpResult),dTmpResult)
#define HWRMathSin(d) (HWRMathSystemSin(d,&dTmpResult),dTmpResult)
#define HWRMathCos(d) (HWRMathSystemCos(d,&dTmpResult),dTmpResult)
#define HWRMathAtan2(d1,d2) (HWRMathSystemAtan2(d1,d2,&dTmpResult),dTmpResult)
#define HWRMathLSqrt(d) (HWRMathSystemLSqrt(d,&dTmpResult),dTmpResult)

// drivers\tpg\hwx\bear\inc\lk_code.h
#define _fUS2_  (_f_|_US2_)
#define _fUE2_  (_f_|_UE2_)
#define _fUI2_  (_f_|_UI2_)
#define _fDI1_  (_f_|_DI1_)
#define _fDE1_  (_f_|_DE1_)
#define _fDS1_  (_f_|_DS1_)
#define _fDS2_  (_f_|_DS2_)           /*                                   */
#define _bUS2_  (_b_|_US2_)
#define _bUE2_  (_b_|_UE2_)
#define _bUI2_  (_b_|_UI2_)
#define _bDI1_  (_b_|_DI1_)
#define _bDE1_  (_b_|_DE1_)
#define _bDS1_  (_b_|_DS1_)

// drivers\tpg\hwx\bear\inc\xr_attr.h
#define XRM_UW  (XRM_UPPER | XRM_WILD)
#define XRM_ANY (XRM_LW | XRM_UW)

// drivers\tpg\hwx\bear\inc\xr_names.h
#define  XASSIGN_HEIGHT(xrd,value)   \
            { (xrd)->xr.height = value; }

// drivers\tpg\hwx\bear\src\breaks.cpp
      #define SIDE_GAMMA(el) ((el)->code==_Gl_ || (el)->code==_Gr_)

// drivers\tpg\hwx\bear\src\div_let.cpp
#define  X_IsLikeXTST(pxrd)  (   (pxrd)->xr.type==X_ST        \
                              || (pxrd)->xr.type==X_XT        \
                              || (pxrd)->xr.type==X_XT_ST     \
                              || (pxrd)->xr.type==X_UMLAUT  )
#define  X_IsLikeXTST(pxrd)  (   (pxrd)->xr.type==X_ST        \
                              || (pxrd)->xr.type==X_XT        \
                              || (pxrd)->xr.type==X_XT_ST     \
                              || (pxrd)->xr.type==X_CEDILLA   \
                              || (pxrd)->xr.type==X_UMLAUT  )
#define  X_IsLikeXTST(pxrd)  (   (pxrd)->xr.type==X_ST        \
                              || (pxrd)->xr.type==X_XT        \
                              || (pxrd)->xr.type==X_XT_ST     \
                              || (pxrd)->xr.type==X_CEDILLA   \
                              || (pxrd)->xr.type==X_UMLAUT  )
#define  X_IsLikeXTST(pxrd)  (   (pxrd)->xr.type==X_ST        \
                              || (pxrd)->xr.type==X_XT        \
                              || (pxrd)->xr.type==X_XT_ST  )

// drivers\tpg\hwx\bear\src\zctype.cpp
#define _2UC(n) (unsigned int)((n)&0x00ff)

// drivers\tpg\hwx\crane\src\algo.h
#define ProtoheaderFromMpcfeatproto(cprim)	&(mpcfeatproto[cprim])
#define SetCprotoRomPROTOHEADER(pprotohdr, cproto)			\
			((pprotohdr)->cprotoRom = (cproto))
#define GetCprotoRomPROTOHEADER(pprotohdr)					\
			((pprotohdr)->cprotoRom)
#define GetCprotoPROTOHEADER(pprotohdr)						\
			((pprotohdr)->cprotoRom)

// drivers\tpg\hwx\factoid\inc\regexp.h
#define IsUnaryOperator(x) (((x)==OPERATOR_ZERO)||((x)==OPERATOR_ONE)||((x)==OPERATOR_OPTIONAL))
#define IsBinaryOperator(x) (((x)==OPERATOR_CAT)||((x)==OPERATOR_OR))

// drivers\tpg\hwx\inferno\src\langmod.c
#define		IsUpper(wch)	(L'A' <= (wch) && (wch) <= L'Z')

// drivers\tpg\hwx\otter\src\arcs.c
#define angldiff(a,b,c)  c=b-a; if (c > 180) c -= 360; \
                    else if (c < -180) c += 360;

// drivers\tpg\hwx\otter\src\proto.h
#define IsSmallXPROTO(self)		((self)->size.x < XPROTO_SMALLX && (self)->size.y < XPROTO_SMALLY)

// drivers\tpg\hwx\sole\src\solefeat.c
#define Neighbor(a, b) ((a)-(b) < 2 && (b)-(a) < 2)

// drivers\tpg\hwx\tsunami\inc\path.h
#define	IsDigitSYM(s)	((s) >= 0x824f && (s) <= 0x8258)
#define	IsUpperSYM(s)	((s) >= 0x8260 && (s) <= 0x8279)

// drivers\tpg\hwx\tsunami\src\snot\glyphsym.h
#define	PathnodeAtGLYPHSYM(gs, i)	((PATHNODE *)&((gs)->rgPathnode[i]))

// drivers\tpg\hwx\tsunami\src\snot\path.h
#define	IsDigitSYM(s)	((s) >= 0x824f && (s) <= 0x8258)
#define	IsUpperSYM(s)	((s) >= 0x8260 && (s) <= 0x8279)

// drivers\tpg\hwx\tsunami\src\snot\xrcparam.h
#define	LpguideXRCPARAM(xrc)			(&((xrc)->guide))

// drivers\tpg\hwx\tsunami\src\usa\glyphsym.h
#define	PathnodeAtGLYPHSYM(gs, i)	((PATHNODE *)&((gs)->rgPathnode[i]))

// drivers\tpg\hwx\tsunami\src\usa\path.h
#define	IsDigitSYM(s)	((s) >= 0x824f && (s) <= 0x8258)
#define	IsUpperSYM(s)	((s) >= 0x8260 && (s) <= 0x8279)

// drivers\tpg\hwx\tsunami\src\usa\xrcparam.h
#define	LpguideXRCPARAM(xrc)			(&((xrc)->guide))

// drivers\tpg\hwx\volcano\dll\eafactoid.c
#define ALL_LANG (JPN_LANG | CHS_LANG | CHT_LANG | KOR_LANG)

// drivers\tpg\hwx\volcano\dll\sole.c
#define Neighbor(a, b) ((a)-(b) < 2 && (b)-(a) < 2)

// drivers\tpg\hwx\zilla\inc\zillatool.h
#define ProtoheaderFromMpcfeatproto(cprim)  &(mpcfeatproto[cprim])
#define GetCprotoDynamicPROTOHEADER(pprotohdr)				\
			((pprotohdr)->cprotoDynamic)
#define SetCprotoDynamicPROTOHEADER(pprotohdr, cproto)		\
			((pprotohdr)->cprotoDynamic = (cproto))

// drivers\tpg\hwx\zilla\src\zillap.h
#define GetRgprimDynamicPROTOHEADER(pprotohdr)				\
			((pprotohdr)->rgprimDynamic)
#define SetRgprimDynamicPROTOHEADER(pprotohdr, rgprim)		\
			((pprotohdr)->rgprimDynamic = (rgprim))
#define GetRgdbcDynamicPROTOHEADER(pprotohdr)				\
			((pprotohdr)->rgdbcDynamic)
#define SetRgdbcDynamicPROTOHEADER(pprotohdr, rgdbc)		\
			((pprotohdr)->rgdbcDynamic = (rgdbc))
#define SetDbcDynamicPROTOHEADER(pprotohdr, iproto, wDbc)	\
			((pprotohdr)->rgdbcDynamic[iproto] = (wDbc))
#define GetPprimDynamicPROTOHEADER(pprotohdr, cprim, iproto)	\
			(&((pprotohdr)->rgprimDynamic[(iproto) * (cprim)]))
#define ProtoheaderFromMpcfeatproto(cprim)  &(mpcfeatproto[cprim])

// drivers\video\matrox\mga\disp\driver.h
#define GLYPH_HASH_FUNC(x)  ((x) & (GLYPH_HASH_SIZE - 1))
#define OVERLAP(prcl, pptl)                                             \
    (((prcl)->right  > (pptl)->x)                                   &&  \
     ((prcl)->bottom > (pptl)->y)                                   &&  \
     ((prcl)->left   < ((pptl)->x + (prcl)->right - (prcl)->left))  &&  \
     ((prcl)->top    < ((pptl)->y + (prcl)->bottom - (prcl)->top)))

// drivers\video\matrox\mga\disp\hw.h
#define     bop_NOTMERGEPEN         0x00010000  // DPon      ~(D | S)
#define     bop_NOTXORPEN           0x00090000  // DPxn       ~(D ^ S)
#define     bop_MERGEPENNOT         0x000d0000  // PDno      (~D)| S
#define     MGA_NOTMERGEPEN         0x0001      // DPon      ~(D | S)
#define     MGA_NOTXORPEN           0x0009      // DPxn       ~(D ^ S)
#define     MGA_MERGEPENNOT         0x000d      // PDno      (~D)| S

// drivers\video\matrox\mga\disp\mcdclip.c
#define __MCD_CLIP_FOG(v, a, b, t) \
    v->fog = t * (a->fog - b->fog) + b->fog;

// drivers\video\ms\3dlabs\perm2\disp\d3ddelta.h
#define RENDER_AREA_STIPPLE_ENABLE(a) a |= __RENDER_AREA_STIPPLE_ENABLE;
#define RENDER_AREA_STIPPLE_DISABLE(a) a &= ~__RENDER_AREA_STIPPLE_ENABLE;
#define RENDER_LINE(a) a &= ~(0xC0);
#define RENDER_TRAPEZOID(a) {a &= ~(0xC0); a |= (0x40);}

// drivers\video\ms\3dlabs\perm2\disp\d3dhw.h
#define CULL_TRI(pCtxt,p0,p1,p2)                                         \
    ((pCtxt->CullMode != D3DCULL_NONE) &&                                \
     (((p1->sx - p0->sx)*(p2->sy - p0->sy) <=                            \
       (p2->sx - p0->sx)*(p1->sy - p0->sy)) ?                            \
      (pCtxt->CullMode == D3DCULL_CCW)     :                             \
      (pCtxt->CullMode == D3DCULL_CW) ) )

// drivers\video\ms\3dlabs\perm2\disp\hw.h
#define P2_TAG_MAJOR(x)              ((x) & 0xff0)

// drivers\video\ms\3dlabs\perm2\disp\permedia.h
#define DISCONNECT_INOUT_ENABLE         (DISCONNECT_INPUT_FIFO_ENABLE | \
                                         DISCONNECT_OUTPUT_FIFO_ENABLE)

// drivers\video\ms\3dlabs\perm3\disp\dx\chroma.h
#define GET_RED_332(a)    (((a) & 0xE0))
#define GET_ALPHA_2321(a) (((a) & 0x80))
#define GET_GREEN_4444(a) (((a) & 0x00F0))
#define GET_BLUE_8888(a)  (((a) & 0x000000FF))
#define GEN_332_SKEY(a)  (P3REG_PLACE_RED  (GET_RED_332  (a)) |  \
                          P3REG_PLACE_GREEN(GET_GREEN_332(a)) |  \
                          P3REG_PLACE_BLUE (GET_BLUE_332 (a)))
#define GEN_2321_SKEY(a) (P3REG_PLACE_ALPHA(GET_ALPHA_2321(a)) | \
                          P3REG_PLACE_RED  (GET_RED_2321  (a)) | \
                          P3REG_PLACE_GREEN(GET_GREEN_2321(a)) | \
                          P3REG_PLACE_BLUE (GET_BLUE_2321 (a)))
#define GEN_5551_SKEY(a) (P3REG_PLACE_ALPHA(GET_ALPHA_5551(a)) | \
                          P3REG_PLACE_RED  (GET_RED_5551  (a)) | \
                          P3REG_PLACE_GREEN(GET_GREEN_5551(a)) | \
                          P3REG_PLACE_BLUE (GET_BLUE_5551 (a)))
#define GEN_565_SKEY(a)  (P3REG_PLACE_RED  (GET_RED_565  (a)) |  \
                          P3REG_PLACE_GREEN(GET_GREEN_565(a)) |  \
                          P3REG_PLACE_BLUE (GET_BLUE_565 (a)))
#define GEN_4444_SKEY(a) (P3REG_PLACE_ALPHA(GET_ALPHA_4444(a)) | \
                          P3REG_PLACE_RED  (GET_RED_4444  (a)) | \
                          P3REG_PLACE_GREEN(GET_GREEN_4444(a)) | \
                          P3REG_PLACE_BLUE (GET_BLUE_4444 (a)))
#define GEN_L8_KEY(a)    (P3REG_PLACE_ALPHA(0xFF) | \
                          P3REG_PLACE_RED  (GET_BLUE_8888 (a)) | \
                          P3REG_PLACE_GREEN(GET_BLUE_8888 (a)) | \
                          P3REG_PLACE_BLUE (GET_BLUE_8888 (a)))
#define GEN_A8L8_KEY(a)  (P3REG_PLACE_ALPHA(GET_GREEN_8888 (a)) | \
                          P3REG_PLACE_RED  (GET_BLUE_8888 (a)) | \
                          P3REG_PLACE_GREEN(GET_BLUE_8888 (a)) | \
                          P3REG_PLACE_BLUE (GET_BLUE_8888 (a)))

// drivers\video\ms\3dlabs\perm3\disp\dx\d3ddp2op.c
#define RDVSD_ISLEGACY(ShaderHandle) !(ShaderHandle & D3DFVF_RESERVED0)

// drivers\video\ms\3dlabs\perm3\disp\dx\d3dprim.c
#define GET_FOG(x)  ((x) & 0xff000000 )
#define GET_SPEC(x) ((x) & 0x00ffffff )
#define ALL_SIDES   ( SIDE_0 | SIDE_1 | SIDE_2 )
#define CONST_c (0 ^ 1 ^ 2)

// drivers\video\ms\3dlabs\perm3\disp\dx\d3dtxt.c
    #define SWITCH_ARG(prefix,opname) \
            case prefix##_##opname##: pszTemp = #opname; break

// drivers\video\ms\3dlabs\perm3\disp\dx\ddover.h
    #define FORCED_IN_ORDER_WRITE(target,value) vpdwTemp = &(target); *vpdwTemp = (value)

// drivers\video\ms\3dlabs\perm3\disp\dx\dltamacr.h
#define RENDER_AREA_STIPPLE_ENABLE(a) a |= 1;
#define RENDER_AREA_STIPPLE_DISABLE(a) a &= ~1;

// drivers\video\ms\3dlabs\perm3\disp\gdi\glint.h
#define DEVICE_FAMILY_ID(id)    ((id) & 0xff)
#define INT16(i)                    ((i) & 0xFFFF)
#define GLINT_TAG_MAJOR(x)        ((x) & 0xff0)
#define DISCONNECT_INOUT_ENABLE         (DISCONNECT_INPUT_FIFO_ENABLE | \
                                         DISCONNECT_OUTPUT_FIFO_ENABLE)

// drivers\video\ms\3dlabs\perm3\disp\gdi\p3rd.h
#define P3RD_CALCULATE_LUT_INDEX(x) \
    (glintInfo->deviceInfo.DeviceId == PERMEDIA4_ID ? (x) : (14-(x)))

// drivers\video\ms\3dlabs\perm3\disp\inc\driver.h
#define ENABLE_DXMANAGED_LINEAR_HEAP (_WIN32_WINNT >= 0x500 && WNT_DDRAW)
#define OVERLAP(prcl, pptl)                                             \
    (((prcl)->right  > (pptl)->x)                                   &&  \
     ((prcl)->bottom > (pptl)->y)                                   &&  \
     ((prcl)->left   < ((pptl)->x + (prcl)->right - (prcl)->left))  &&  \
     ((prcl)->top    < ((pptl)->y + (prcl)->bottom - (prcl)->top)))

// drivers\video\ms\3dlabs\perm3\disp\inc\gtag.h
#define IsAreaStipplePattern(t)        (((t)&0x1e0)==0x040)

// drivers\video\ms\3dlabs\perm3\disp\inc\p2rd.h
#define P2RD_DECL \
    P2RDRAMDAC   *pP2RDRegs = (P2RDRAMDAC *)&(pDev->pRegisters->Glint.ExtVCReg)
#define P2RD_DECL \
    P2RDRAMDAC   *pP2RDRegs = (P2RDRAMDAC *)&(pRegisters->Glint.ExtVCReg)

// drivers\video\ms\3dlabs\perm3\disp\inc\p3rd.h
#define P3RD_DECL \
    P3RDRAMDAC   *pP3RDRegs = (P3RDRAMDAC *)&(pDev->pRegisters->Glint.ExtVCReg)
#define P3RD_DECL \
    P3RDRAMDAC   *pP3RDRegs = (P3RDRAMDAC *)&(pRegisters->Glint.ExtVCReg)

// drivers\video\ms\3dlabs\perm3\disp\inc\tvp3026.h
#define TVP3026_DECL \
    pTVP3026RAMDAC   pTVP3026Regs = (pTVP3026RAMDAC)&(pDev->pRegisters->Glint.ExtVCReg)
#define TVP3026_DECL \
    pTVP3026RAMDAC   pTVP3026Regs = (pTVP3026RAMDAC)&(pRegisters->Glint.ExtVCReg)

// drivers\video\ms\3dlabs\perm3\disp\inc\tvp4020.h
#define TVP4020_DECL \
    pTVP4020RAMDAC   pTVP4020Regs = (pTVP4020RAMDAC)&(pDev->pRegisters->Glint.ExtVCReg)
#define TVP4020_DECL \
    pTVP4020RAMDAC   pTVP4020Regs = (pTVP4020RAMDAC)&(pRegisters->Glint.ExtVCReg)

// drivers\video\ms\8514a\disp\driver.h
#define OVERLAP(prcl, pptl)                                             \
    (((prcl)->right  > (pptl)->x)                                   &&  \
     ((prcl)->bottom > (pptl)->y)                                   &&  \
     ((prcl)->left   < ((pptl)->x + (prcl)->right - (prcl)->left))  &&  \
     ((prcl)->top    < ((pptl)->y + (prcl)->bottom - (prcl)->top)))

// drivers\video\ms\8514a\disp\hw.h
#define IO_ABS_SCISSORS_T(ppdev, y)         \
{                                           \
    OUT_ACCEL(SCISSORS_T, (y) | CLIP_TOP);  \
}
#define IO_ABS_SCISSORS_L(ppdev, x)         \
{                                           \
    OUT_ACCEL(SCISSORS_L, (x) | CLIP_LEFT); \
}
#define IO_ABS_SCISSORS_B(ppdev, y)         \
{                                           \
    OUT_ACCEL(SCISSORS_B, (y) | CLIP_BOTTOM);  \
}
#define IO_ABS_SCISSORS_R(ppdev, x)         \
{                                           \
    OUT_ACCEL(SCISSORS_R, (x) | CLIP_RIGHT);\
}
#define IO_PIX_CNTL(ppdev, x)               \
{                                           \
    OUT_ACCEL(PIX_CNTL, (x) | DATA_EXTENSION);   \
}

// drivers\video\ms\8514a\disp\lines.c
#define DIVREM(u64,u32,pul) \
    RtlEnlargedUnsignedDivide(*(ULARGE_INTEGER*) &(u64), (u32), (pul))

// drivers\video\ms\ati\disp\driver.h
#define GLYPH_HASH_FUNC(x)  ((x) & (GLYPH_HASH_SIZE - 1))
#define OVERLAP(prcl, pptl)                                             \
    (((prcl)->right  > (pptl)->x)                                   &&  \
     ((prcl)->bottom > (pptl)->y)                                   &&  \
     ((prcl)->left   < ((pptl)->x + (prcl)->right - (prcl)->left))  &&  \
     ((prcl)->top    < ((pptl)->y + (prcl)->bottom - (prcl)->top)))

// drivers\video\ms\cirrus\disp\driver.h
#define OVERLAP(prcl, pptl)                                             \
    (((prcl)->right  > (pptl)->x)                                   &&  \
     ((prcl)->bottom > (pptl)->y)                                   &&  \
     ((prcl)->left   < ((pptl)->x + (prcl)->right - (prcl)->left))  &&  \
     ((prcl)->top    < ((pptl)->y + (prcl)->bottom - (prcl)->top)))
#define  CL754x       (CL7541 | CL7542 | CL7543 | CL7548)
#define  CL755x       (CL7555 | CL7556)

// drivers\video\ms\cirrus\disp\overlay.c
#define IN_VBLANK            (_inp(0x3da) & 8)
#define PAKJR_GET_V(x) (x & 0x0000003F)

// drivers\video\ms\laguna\disp\cl5465\5465over.c
#define lpDDHALData       ((DRIVERDATA *)(&(ppdev->DriverData)))

// drivers\video\ms\laguna\disp\cl5465\mcdclip.c
#define __MCD_CLIP_FOG(v, a, b, t) \
    v->fog = t * (a->fog - b->fog) + b->fog;

// drivers\video\ms\laguna\disp\cl5465\overlay.c
#define lpDDHALData     ((DRIVERDATA *)(&(ppdev->DriverData)))

// drivers\video\ms\laguna\disp\cl5465\texparm.c
#define F_NEG(var)   (*(unsigned *)&var ^= 0x80000000)

// drivers\video\ms\laguna\disp\cl546x\5465over.c
#define lpDDHALData       ((DRIVERDATA *)(&(ppdev->DriverData)))

// drivers\video\ms\laguna\disp\cl546x\overlay.c
#define lpDDHALData     ((DRIVERDATA *)(&(ppdev->DriverData)))

// drivers\video\ms\laguna\disp\include\driver.h
#define IN_VBLANK         (_inp(0x3da) & 8)
#define IN_DISPLAYENABLE  (_inp(0x3da) & 1)

// drivers\video\ms\laguna\disp\include\l3d.h
#define X_EXTENT(Extent)    ((Extent) & 0xFFFF)

// drivers\video\ms\laguna\disp\include\l3system.h
#define write_register( reg, count ) \
( WRITE_REGISTER | mk_reg(reg) | count )
#define write_dev_register( device, reg, count ) \
( WRITE_DEV_REGS | device | mk_dev_reg(reg) | count )

// drivers\video\ms\laguna\disp\include\laguna.h
    #define SYNC_3D_CONDITIONS (ST_POLY_ENG_BUSY|ST_EXEC_ENG_3D_BUSY|ST_XY_ENG_BUSY|/*ST_BLT_ENG_BUSY|*/ST_BLT_WF_EMPTY)

// drivers\video\ms\port\pedid.h
#define GET_HZ_REFRESH_RATE(ushort)         \
    ((ushort & 0x3f) + 60)
#define GET_EDID_PDETAIL1(pEdid)     &(pEdid->UC_Detail1)
#define GET_EDID_PDETAIL2(pEdid)     &(pEdid->UC_Detail2)
#define GET_EDID_PDETAIL3(pEdid)     &(pEdid->UC_Detail3)
#define GET_EDID_PDETAIL4(pEdid)     &(pEdid->UC_Detail4)

// drivers\video\ms\s3\disp\driver.h
#define GLYPH_HASH_FUNC(x)  ((x) & (GLYPH_HASH_SIZE - 1))
    #define DENSE(ppdev)        (!(ppdev->flCaps & CAPS_SPARSE_SPACE))
#define OVERLAP(prcl, pptl)                                             \
    (((prcl)->right  > (pptl)->x)                                   &&  \
     ((prcl)->bottom > (pptl)->y)                                   &&  \
     ((prcl)->left   < ((pptl)->x + (prcl)->right - (prcl)->left))  &&  \
     ((prcl)->top    < ((pptl)->y + (prcl)->bottom - (prcl)->top)))

// drivers\video\ms\s3\disp\hw.h
#define BT485_CURSOR_DISABLE            (~0x03)
#define HK1K2(w0,w1) (HK1(w0) | HK2(w0, w1))
#define IO_GP_BUSY(ppdev)   (IO_GP_STAT(ppdev) & HARDWARE_BUSY)
#define IO_ABS_CUR_Y(ppdev, y)              \
    OUT_FIFO_W(ppdev->ioCur_y, (y))
#define IO_ABS_CUR_X(ppdev, x)              \
    OUT_FIFO_W(ppdev->ioCur_x, (x))
#define IO_ABS_DEST_Y(ppdev, y)             \
    OUT_FIFO_W(ppdev->ioDesty_axstp, (y))
#define IO_ABS_DEST_X(ppdev, x)             \
    OUT_FIFO_W(ppdev->ioDestx_diastp, (x))
#define IO_ABS_SCISSORS_T(ppdev, y)         \
{                                           \
    CP_MEMORY_BARRIER();                    \
    OUT_FIFO_W(ppdev->ioMulti_function, (y) | CLIP_TOP);     \
}
#define IO_ABS_SCISSORS_L(ppdev, x)         \
{                                           \
    CP_MEMORY_BARRIER();                    \
    OUT_FIFO_W(ppdev->ioMulti_function, (x) | CLIP_LEFT);    \
}
#define IO_ABS_SCISSORS_B(ppdev, y)         \
{                                           \
    CP_MEMORY_BARRIER();                    \
    OUT_FIFO_W(ppdev->ioMulti_function, (y) | CLIP_BOTTOM);  \
}
#define IO_ABS_SCISSORS_R(ppdev, x)         \
{                                           \
    CP_MEMORY_BARRIER();                    \
    OUT_FIFO_W(ppdev->ioMulti_function, (x) | CLIP_RIGHT);   \
}
#define IO_AXSTP(ppdev, x)                  \
    OUT_FIFO_W(ppdev->ioDesty_axstp, (x))
#define IO_DIASTP(ppdev, x)                 \
    OUT_FIFO_W(ppdev->ioDestx_diastp, (x))
#define IO_ERR_TERM(ppdev, x)               \
    OUT_FIFO_W(ppdev->ioErr_term, (x))
#define IO_CMD(ppdev, x)                    \
{                                           \
    CP_EIEIO();                             \
    OUT_FIFO_W(ppdev->ioGp_stat_cmd, (x));  \
    CP_EIEIO();                             \
}
#define IO_BKGD_MIX(ppdev, x)               \
    OUT_FIFO_W(ppdev->ioBkgd_mix, (x))
#define IO_FRGD_MIX(ppdev, x)               \
    OUT_FIFO_W(ppdev->ioFrgd_mix, (x))
#define IO_MULTIFUNC_CNTL(ppdev, x)         \
{                                           \
    CP_MEMORY_BARRIER();                    \
    OUT_FIFO_W(ppdev->ioMulti_function, (x) | MULT_MISC_INDEX);   \
}
#define IO_PIX_CNTL(ppdev, x)               \
{                                           \
    CP_MEMORY_BARRIER();                    \
    OUT_FIFO_W(ppdev->ioMulti_function, (x) | DATA_EXTENSION);   \
}
#define IO_READ_SEL(ppdev, x)               \
{                                           \
    CP_MEMORY_BARRIER();                    \
    OUT_FIFO_W(ppdev->ioMulti_function, (x) | READ_SEL_INDEX);   \
}
#define IO_MULT_MISC(ppdev, x)              \
{                                           \
    CP_MEMORY_BARRIER();                    \
    OUT_FIFO_W(ppdev->ioMulti_function, (x) | MULT_MISC_INDEX);  \
}
#define IO_RD_REG_DT(ppdev, x)              \
{                                           \
    CP_EIEIO();                             \
    x = READ_PORT_USHORT(ppdev->ioMulti_function);  \
    CP_EIEIO();                             \
}
#define IO_PIX_TRANS(ppdev, x)              \
{                                           \
    CP_MEMORY_BARRIER();                    \
    /* Can't use OUT_FIFO_W: */             \
    WRITE_PORT_USHORT(ppdev->ioPix_trans, (x)); \
}

// drivers\video\ms\vga\disp\16bpp\driver.h
#define BANK_BROKEN_RASTERS    (BANK_BROKEN_RASTER1 | BANK_BROKEN_RASTER2)

// drivers\video\ms\vga\disp\8bpp\driver.h
#define BANK_BROKEN_RASTERS    (BANK_BROKEN_RASTER1 | BANK_BROKEN_RASTER2)

// drivers\video\ms\w32\disp\driver.h
#define OVERLAP(prcl, pptl)                                             \
    (((prcl)->right  > (pptl)->x)                                   &&  \
     ((prcl)->bottom > (pptl)->y)                                   &&  \
     ((prcl)->left   < ((pptl)->x + (prcl)->right - (prcl)->left))  &&  \
     ((prcl)->top    < ((pptl)->y + (prcl)->bottom - (prcl)->top)))

// drivers\video\ms\w32\disp\hw.h
#define ET6K_HORZ_PRESET(ppdev, x);                             \
{                                                               \
    OUTP(ppdev->PCIConfigSpaceAddr + ET6K_SPRITE_HORZ_PRESET, (x));\
}
#define ET6K_VERT_PRESET(ppdev, y)                              \
{                                                               \
    OUTP(ppdev->PCIConfigSpaceAddr + ET6K_SPRITE_VERT_PRESET, (y));\
}

// drivers\video\ms\weitek\disp\blt.c
#define P9000_P       ((P9000_S & P9000_F) | (~P9000_S & P9000_B))
#define P9000_DSo     (P9000_S | P9000_D)
#define P9000_DSna    (~P9000_S & P9000_D)

// drivers\video\ms\weitek\disp\driver.h
#define P9000(ppdev) (ppdev->flStat & STAT_P9000)
#define OVERLAP(prcl, pptl)                                             \
    (((prcl)->right  > (pptl)->x)                                   &&  \
     ((prcl)->bottom > (pptl)->y)                                   &&  \
     ((prcl)->left   < ((pptl)->x + (prcl)->right - (prcl)->left))  &&  \
     ((prcl)->top    < ((pptl)->y + (prcl)->bottom - (prcl)->top)))

// drivers\wdm\audio\backpln\portcls\main\porthelp.cpp
#define UPTOQUAD(x) (((x)+7)&~7)

// drivers\wdm\audio\backpln\portcls\portclsd\portclsd.cpp
#define TranslateDevicePower( x ) \
    ( x == PowerDeviceD0 ? "PowerDeviceD0" :    \
      x == PowerDeviceD1 ? "PowerDeviceD1" :    \
      x == PowerDeviceD2 ? "PowerDeviceD2" :    \
      x == PowerDeviceD3 ? "PowerDeviceD3" : "Unknown" )

// drivers\wdm\audio\inc\midi.h
#define MIDI_CHANNEL(b)                 ((b) & 0x0F)

// drivers\wdm\audio\inc\wdmaud.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// drivers\wdm\input\legacy\mshgame\gckernel.sys\ctrl_ioctl.c
#define UPPERCASE(_x_) (((L'a'<=_x_) && (L'z'>=_x_)) ? ((_x_) - (L'a'-L'A')) : _x_)

// drivers\wdm\input\legacy\mshgame\inc\profile.h
#define	ATLAS_SETTINGS_EMULATE_GROUP	(ATLAS_SETTINGS_EMULATE_CHPRO|ATLAS_SETTINGS_EMULATE_THRUSTMASTER)

// drivers\wdm\input\legacy\mshgame\msgame\device.h
#define	INSTANCE_DEVICE(x)			&x##Info

// drivers\wdm\input\legacy\mshgame\msgame\msgame.h
#define EXCHANGE(x,y)       ((x)^=(y)^=(x)^=(y))
#define TOUPPER(x)          ((x>='a'&&x<='z')?x-'a'+'A':x)

// drivers\wdm\input\opos\inc\opos.h
#define MSR_TR_1_2            (MSR_TR_1 | MSR_TR_2)
#define MSR_TR_1_3            (MSR_TR_1 | MSR_TR_3)
#define MSR_TR_2_3            (MSR_TR_2 | MSR_TR_3)
#define MSR_TR_1_2_3          (MSR_TR_1 | MSR_TR_2 | MSR_TR_3)

// drivers\wdm\input\tools\dt\dt.h
#define ITEM(x, y) (x | y)

// drivers\wdm\usb\driver\usbtest\inc\usbtest.h
#define IsNonHubDevice(node) ( (MIParent == (node) -> NodeType) ||          \
                                (Device == (node) -> NodeType) )
#define IsUSBDevice(node)    ( (IsNonHubDevice(node)) || (IsExtenalHub(node)) )

// drivers\wdm\usb\driver\wceusbsh\wceusbsh.rc
#define VER_PRODUCTVERSION_DW       (0x01000000 | VER_PRODUCTBUILD)

// drivers\wdm\usb\hcd\uhcd\uhcd.h
#define PORT1_REG(deviceExtension)                      \
    ((PUSHORT) (deviceExtension->DeviceRegisters[0] + 0x10))
#define PORT2_REG(deviceExtension)                      \
    ((PUSHORT) (deviceExtension->DeviceRegisters[0] + 0x12))

// drivers\wdm\vbi\cc\kskludge.h
#define KS_VBIDATARATE_CC       		( 503493)    // ~= 1/1.986125e-6

// ds\adsi\include\formcnst.hxx
#define EQUAL_BOOL(_x_,_y_) (((_x_) && (_y_)) || (!(_x_) && !(_y_)))

// ds\adsi\include\formtrck.hxx
#  define TRACK_CLASS(fTrack, cls) \
                      ObjectTracker::TrackClass( fTrack, cls )

// ds\adsi\include\noutil.hxx
#define NO_COPY(cls)    \
    cls(const cls&);    \
    cls& operator=(const cls&);

// ds\adsi\ldap\extension.hxx
#define REMOVE_EXTENSION_ID(dispid)   ( (dispid) & 0x00ffffff )

// ds\adsi\ldap\ldapinc\disptmpl.h
#define LDAP_SYN_BOOLEAN	( 4 | LDAP_SYN_TYPE_BOOLEAN )
#define LDAP_SYN_JPEGBUTTON	( 6 | LDAP_SYN_TYPE_BUTTON | LDAP_SYN_OPT_DEFER )
#define LDAP_SYN_FAXBUTTON	( 8 | LDAP_SYN_TYPE_BUTTON | LDAP_SYN_OPT_DEFER )
#define LDAP_SYN_AUDIOBUTTON	( 9 | LDAP_SYN_TYPE_BUTTON | LDAP_SYN_OPT_DEFER )
#define LDAP_SYN_SEARCHACTION	( 13 | LDAP_SYN_TYPE_ACTION )
#define LDAP_SYN_LINKACTION	( 14 | LDAP_SYN_TYPE_ACTION )
#define LDAP_SYN_ADDDNACTION	( 15 | LDAP_SYN_TYPE_ACTION )
#define LDAP_GET_SYN_TYPE( syid )	((syid) & 0xFF000000L )
#define LDAP_GET_SYN_OPTIONS( syid )	((syid) & 0x00FF0000L )
#define LDAP_GET_TMPLITEM_APPDATA( ti, type )	\
	(type)((ti)->ti_appdata)
#define LDAP_GET_DISPTMPL_APPDATA( dt, type )	\
	(type)((dt)->dt_appdata)

// ds\adsi\nw312\extension.hxx
#define REMOVE_EXTENSION_ID(dispid)   ( (dispid) & 0x00ffffff )

// ds\adsi\oledsvw\csyntax.cpp
#define  NDS_SEPARATOR     _T('&')
#define  NDS_SEPARATOR_S     _T(" & ")

// ds\adsi\winnt\cprops.hxx
#define DISPATCH_NAME(pDispProperty)    \
            ( (pDispProperty)->szPropertyName)
#define DISPATCH_PROPERTY_NAME(dwDispid) \
            ( (_pDispProperties+(dwDispid))->szPropertyName )

// ds\adsi\winnt\extension.hxx
#define REMOVE_EXTENSION_ID(dispid)   ( (dispid) & 0x00ffffff )

// ds\dns\dnslib\dnslibp.h
#define FamilyInfo_GetForSockaddr(pSA)  \
        FamilyInfo_GetForFamily( (pSA)->sa_family )

// ds\dns\dnslib\name.c
#define DC_UPPER        (B_UPPER | B_RFC)
#define DC_NUMBER       (B_NUMBER | B_RFC)
#define DC_DOT          (B_SPECIAL | B_DOT)
#define DC_ASTERISK     (B_SPECIAL | B_LEADING_ONLY)
#define DC_UNDERSCORE   (B_SPECIAL | B_LEADING_ONLY)

// ds\dns\server\server\dfile.h
#define MAKE_TOKEN( ptoken, pch, cch ) \
            ((ptoken)->pchToken = (pch), (ptoken)->cchLength = (cch) )

// ds\dns\server\server\msginfo.h
#define MAKE_WINS_XID( xid )        ( (xid) | 0x8000 )
#define MAKE_RECURSION_XID( xid )   ( (xid) & 0x3fff )
#define MAKE_IXFR_XID( xid )        ( ((xid) & 0x1fff) | 0x4000 )

// ds\dns\server\server\recurse.h
#define MISSING_GLUE_DELEGATION(pvisit) \
        ( *(PDB_NODE *)(&(pvisit)->Priority) )

// ds\dns\server\server\zone.h
#define REFRESH_ZONE(pZone) \
        {                   \
            (pZone)->fEmpty     = FALSE; \
            (pZone)->fShutdown  = FALSE; \
            (pZone)->fStale     = FALSE; \
            (pZone)->fNotified  = FALSE; \
            (pZone)->ipNotifier = 0;     \
            (pZone)->cIxfrAttempts = 0;  \
        }

// ds\ds\src\inc\ntdsa.h
#define UpToDateVecSize(putodvec) \
    ((2 == (putodvec)->dwVersion) \
     ? UpToDateVecV2Size(putodvec) \
     : UpToDateVecV1Size(putodvec))
#define DSCNL_NCS_ALL_NCS         (DSCNL_NCS_DOMAINS | DSCNL_NCS_CONFIG | DSCNL_NCS_SCHEMA | DSCNL_NCS_NDNCS)

// ds\ds\src\inc\objids.h
#define SUBREF                        ((SYNTAX_INTEGER) (IT_UNINSTANT | IT_NC_HEAD | IT_NC_ABOVE))
#define NC_MASTER                     ((SYNTAX_INTEGER) (IT_WRITE | IT_NC_HEAD))
#define NC_MASTER_GOING               ((SYNTAX_INTEGER) (IT_WRITE | IT_NC_HEAD | IT_NC_GOING))
#define NC_FULL_REPLICA_GOING         ((SYNTAX_INTEGER) (IT_NC_HEAD | IT_NC_GOING))
#define NC_MASTER_SUBREF              ((SYNTAX_INTEGER) (IT_WRITE | IT_NC_HEAD | IT_NC_ABOVE))
#define NC_MASTER_SUBREF_GOING        ((SYNTAX_INTEGER) (IT_WRITE | IT_NC_HEAD | IT_NC_ABOVE | IT_NC_GOING))
#define NC_FULL_REPLICA_SUBREF        ((SYNTAX_INTEGER) (IT_NC_HEAD | IT_NC_ABOVE))
#define NC_FULL_REPLICA_SUBREF_GOING  ((SYNTAX_INTEGER) (IT_NC_HEAD | IT_NC_ABOVE | IT_NC_GOING))
#define FExitIt(it) ((BOOL) ((it) & IT_NC_HEAD))
#define FPrefixIt(it) ((BOOL) (((it) & IT_NC_HEAD) && !((it) & IT_UNINSTANT)))
#define FPartialReplicaIt(it) (FPrefixIt(it) && !((it) & IT_WRITE))
#define FMasterIt(it) ((BOOL) ((it) & IT_WRITE))

// ds\ds\src\inc\w32toplsched.h
#define TOPL_EX_NEVER_SCHEDULE            (TOPL_EX_PREFIX | 104)

// ds\ds\src\inc\w32toplspantree.h
#define TOPL_EX_ADD_EDGE_AFTER_SET        (TOPL_EX_PREFIX | 205)
#define TOPL_EX_TOO_FEW_VTX               (TOPL_EX_PREFIX | 206)
#define TOPL_EX_TOO_FEW_EDGES             (TOPL_EX_PREFIX | 207)

// ds\ds\src\kcc\sim\user.c
#define INF      (~((int)0))

// ds\ds\src\ldap\client\lmacros.h
#define ISHEX(x)         ( x >= '0' && x <= '9' ? (TRUE) :     \
                           x >= 'A' && x <= 'F' ? (TRUE) :     \
                           x >= 'a' && x <= 'f' ? (TRUE) : FALSE )
#define IsLdapInteger( x ) ( (x >= 0 ) && (x <= 2147483647) ? TRUE : FALSE )

// ds\ds\src\ntdsa\dblayer\dbintrnl.h
#define TRACKING_VALUE_METADATA( pDB ) \
( (pDB->pTHS->fLinkedValueReplication) && (!(pDB->fScopeLegacyLinks)) )

// ds\ds\src\ntdsa\dblayer\dbsearch.c
#define NormalizeIndexPosition(BeginNum, EndNum) \
            (  ((EndNum) <= (BeginNum)) ?  1  : ( (EndNum) - (BeginNum) )  )

// ds\ds\src\ntdsa\dra\dracrypt.c
#define MY_ENCODING_TYPE (PKCS_7_ASN_ENCODING | CRYPT_ASN_ENCODING)

// ds\ds\src\ntdsa\dra\drameta.c
#define ReplIsReqAttr(attrtyp) (    (ATT_INSTANCE_TYPE == (attrtyp)) \
                                 || (ATT_PROXIED_OBJECT_NAME == (attrtyp)) )

// ds\ds\src\ntdsa\ldap\ber.hxx
#define MakeBerId(class,form,tag) ((class)|(form)|(tag))

// ds\ds\src\ntdsa\src\oidconv.c
#define iswdigit(x) ((x) >= L'0' && (x) <= L'9')

// ds\ds\src\ntdsa\src\parsedn.c
#define ISSPECIAL(cc) (((cc) & 0xff80) ? FALSE : ___isspecial[(cc)])

// ds\ds\src\sam\client\wrappers.c
#define SAMP_EXTENDED_SID_DOMAIN(x)                               \
   ((x)->ServerInfo.SupportedFeatures & (SAM_EXTENDED_SID_DOMAIN))

// ds\ds\src\sam\lib\enckey.h
#define MAGIC_CONST_2   "!@#$%^&*()qwertyUIOPAzxcvbnmQQQQQQQQQQQQ)(*@&%"

// ds\ds\src\sam\lib\wxcli.c
#define ToHex( f ) (HexKey[f & 0xF])
#define FromHex( c )    ( ( ( c >= '0' ) && ( c <= '9') ) ? c - '0' :      \
                          ( ( c >= 'a' ) && ( c <= 'f') ) ? c - 'a' + 10:      \
                          ( ( c >= 'A' ) && ( c <= 'F' ) ) ? c - 'A' + 10: -1 )

// ds\ds\src\sam\server\attr.c
#define SampVariableQualifier( c, i )                                       \
    (                                                                       \
        (IsDsObject(c)) ?                                                   \
            SampDsVariableQualifier(c, i) : SampRegVariableQualifier(c, i)  \
    )

// ds\ds\src\sam\server\enckey.h
#define MAGIC_CONST_2   "!@#$%^&*()qwertyUIOPAzxcvbnmQQQQQQQQQQQQ)(*@&%"

// ds\ds\src\sam\server\samsrvp.h
#define SampSetAuditingInformation( PolicyAuditEventsInfo ) {       \
                                                                    \
    if (PolicyAuditEventsInfo->AuditingMode &&                      \
           (PolicyAuditEventsInfo->EventAuditingOptions[ AuditCategoryAccountManagement ] & \
                POLICY_AUDIT_EVENT_SUCCESS)                         \
       ) {                                                          \
                                                                    \
        SampSuccessAccountAuditingEnabled = TRUE;                   \
                                                                    \
    } else {                                                        \
                                                                    \
        SampSuccessAccountAuditingEnabled = FALSE;                  \
    }                                                               \
  if (PolicyAuditEventsInfo->AuditingMode &&                      \
           (PolicyAuditEventsInfo->EventAuditingOptions[ AuditCategoryAccountManagement ] & \
                POLICY_AUDIT_EVENT_FAILURE)                         \
       ) {                                                          \
                                                                    \
        SampFailureAccountAuditingEnabled = TRUE;                   \
                                                                    \
    } else {                                                        \
                                                                    \
        SampFailureAccountAuditingEnabled = FALSE;                  \
    }                                                               \
}
#define SAMP_UNKNOWN_REVISION( Revision )                  \
    ( ((Revision & 0xFFFF0000) > SAMP_MAJOR_REVISION)  ||  \
        (Revision > SAMP_SERVER_REVISION) )                \
#define SAMP_DEFAULT_GROUP_ATTRIBUTES ( SE_GROUP_MANDATORY | \
                                        SE_GROUP_ENABLED | \
                                        SE_GROUP_ENABLED_BY_DEFAULT )

// ds\ds\src\sam\server\sdconvrt.h
#define WORLD_SID                (&(SampWorldSid))
#define PRINCIPAL_SELF_SID        (&(SampPrincipalSelfSid))
#define AUTHENTICATED_USERS_SID  (&(SampAuthenticatedUsersSid))
#define BUILTIN_DOMAIN_SID       (&(SampBuiltinDomainSid))

// ds\ds\src\util\oid\oid.c
#define iswdigit(x) ((x) >= '0' && (x) <= '9')

// ds\ds\src\util\perfdsa\datadsa.h
#define SIZE_OF_DSA_PERFORMANCE_DATA ((SIZE_OF_DSA_PERFORMANCE_DATA_IN_USE + 0x07) & ~0x07)

// ds\ds\src\util\schemard\schematools.c
#define iswdigit(x) ((x) >= '0' && (x) <= '9')

// ds\ese98\export\jet.h
#define	JET_sesidNil				(~(JET_SESID)0)
#define	JET_instanceNil				(~(JET_INSTANCE)0)
#define JET_LSNil					(~(JET_LS)0)

// ds\ese98\src\ese\_osu\fileu.cxx
#define	HEADER_BAD 	( PRIMARY_BAD | SHADOW_BAD )

// ds\ese98\src\ese\db.cxx
#define	FNDVisibleSons(b)		( (b) & fNDVisibleSon )
#define	FNDInvisibleSons(b) 	( !( (b) & fNDVisibleSon ) )
#define	FNDBackLink(b)	 		( (b) & fNDBackLink )

// ds\ese98\src\inc\_os\perfmon.hxx
#define PerfSize( _x )			( ( _x ) & 0x300 )
#define CntrSize( _a, _b )		( PerfSize( _a ) == 0x000 ? 4					\
								: ( PerfSize( _a ) == 0x100 ? 8					\
								: ( PerfSize( _a ) == 0x200 ? 0					\
								: ( _b ) ) ) )

// ds\ese98\src\inc\slv.hxx
#define SLV_CREATESLV_ALL	 ( SLV_CREATESLV_CREATE | SLV_CREATESLV_ATTACH | SLV_CREATESLV_OPEN )

// ds\ese98\src\inc\space.hxx
#define FSPOwnedExtent( fSPExtents )		( (fSPExtents) & fSPOwnedExtent )
#define FSPAvailExtent( fSPExtents )		( (fSPExtents) & fSPAvailExtent )

// ds\netapi\access\uastest2.c
#define DEFAULT_GROUP_ATTR  ( SE_GROUP_MANDATORY |  \
                              SE_GROUP_ENABLED_BY_DEFAULT )

// ds\netapi\inc\dlserver.h
#define NetpIsOldServerInfoLevel(L) \
        ( ((L)==0) || ((L)==1) || ((L)==2) || ((L)==3) )
#define NetpIsNewServerInfoLevel(L) \
        ( ((L)==100) || ((L)==101) || ((L)==102) \
        || ((L)==402) || ((L)==403) \
        || ((L)==502) || ((L)==503) || ((L)==599) )

// ds\netapi\inc\dlwksta.h
#define NetpIsOldWkstaInfoLevel(L) \
        ( ((L)==0) || ((L)==1) || ((L)==10) )
#define NetpIsNewWkstaInfoLevel(L) \
        ( ((L)==100) || ((L)==101) || ((L)==102) \
        || ((L)==302) || ((L)==402) || ((L)==502) )

// ds\netapi\inc\token.h
#define GTF_RESERVED    (~(GTF_8_DOT_3))

// ds\netapi\netlib\pathtype.c
#define PPF_RESERVED            (~(PPF_MATCH_OPTIONAL | PPF_8_DOT_3))

// ds\netapi\svcdlls\upssvc\apcsmart\_defs.h
#  define _REFDEF(name) typedef name _FAR & R##name;
#  define _REFCONSTDEF(name) typedef const name _FAR & RC##name;

// ds\netapi\svcdlls\upssvc\apcsmart\cdefine.h
#define C_OS (C_NT | C_WIN95)
#define C_UNIX      (C_AIX | C_HPUX | C_SUNOS4 | C_SOLARIS2 |\
		     C_UWARE | C_SCO | C_OLIV | C_IRIX | C_NCR |\
                     C_INTERACTIVE | C_USYS | C_ALPHAOSF | C_SINIX)

// ds\netapi\svcdlls\wkssvc\client\csc.c
#define WCSCPY( d, s ) (((s) && (d)) ? wcscpy( d, s ) : 0)

// ds\netapi\svcimgs\ntrepl\inc\jet.h
#define PROPERTY_SPECIFIER_ID(PS,I)      \
    ((PS)->Specifiers[(I)].Id)

// ds\netapi\svcimgs\ntrepl\inc\replutil.h
#define READ_ATTRIB_ACCESS  (FILE_READ_ATTRIBUTES | SYNCHRONIZE)
#define WRITE_ATTRIB_ACCESS  (FILE_WRITE_ATTRIBUTES | SYNCHRONIZE)
#define READ_ACCESS         (GENERIC_READ | GENERIC_EXECUTE | SYNCHRONIZE)
#define ATTR_ACCESS         (READ_ACCESS  | FILE_WRITE_ATTRIBUTES)
#define WRITE_ACCESS        (GENERIC_WRITE | GENERIC_EXECUTE | SYNCHRONIZE)
#define RESTORE_ACCESS      (READ_ACCESS        | \
                             WRITE_ACCESS       | \
                             WRITE_DAC          | \
                             WRITE_OWNER)
#define ID_OPTIONS          (OPEN_OPTIONS | FILE_OPEN_BY_FILE_ID)

// ds\netapi\svcimgs\ntrepl\mkdso\mkdso.h
#define CLASS_SITE_SETTINGS         L"(|(objectClass=nTDSSiteSettings)"\
                                    L"(objectClass=nTFRSSiteSettings))"

// ds\netapi\svcimgs\ntrepl\mkdsx\mkdsx.h
#define CLASS_SITE_SETTINGS         L"(|(objectClass=nTDSSiteSettings)"\
                                    L"(objectClass=nTFRSSiteSettings))"

// ds\netapi\svcimgs\ntrepl\util\config.c
#define REG_DT_NAME(_code_)                                                \
    (((_code_) < NUMBER_OF_REG_DATATYPES) ?                                \
         RegDataTypeNames[(_code_)] : RegDataTypeNames[0])

// ds\netapi\xactsrv\xsprocsp.h
#define XsDigitToBool(b) \
    (BOOL)((( b ) == '0' ) ? FALSE : TRUE )

// ds\nw\svcdlls\nwwks\client\nwshprop.cxx
#define ISDIGIT(c)  ((c) >= '0' && (c) <= '9')

// ds\win32\ntcrypto\dssinc\key.h
#define UnsupportedSymKey(pKey) ((CALG_RC4 != pKey->algId) && \
                                 (CALG_RC2 != pKey->algId) && \
                                 (CALG_DES != pKey->algId) && \
                                 (CALG_CYLINK_MEK != pKey->algId) && \
                                 (CALG_3DES != pKey->algId) && \
                                 (CALG_3DES_112 != pKey->algId))

// ds\win32\ntcrypto\keylimit\limittest1.cpp
#define PCT_SGC (PCT | SGC)

// ds\win32\ntcrypto\keylimit\limittest2.cpp
#define PCT_SGC (PCT | SGC)

// ds\win32\ntcrypto\rsaaes\nt_key.c
#define UnsupportedSymKey(pKey) ((CALG_RC4 != pKey->Algid) && \
                                 (CALG_RC2 != pKey->Algid) && \
                                 (CALG_DES != pKey->Algid) && \
                                 (CALG_3DES != pKey->Algid) && \
                                 (CALG_3DES_112 != pKey->Algid))
#define UnsupportedSymKey(pKey) ((CALG_RC4 != pKey->Algid) && \
                                 (CALG_RC2 != pKey->Algid) && \
                                 (CALG_DES != pKey->Algid) && \
                                 (CALG_3DES != pKey->Algid) && \
                                 (CALG_3DES_112 != pKey->Algid) && \
                                 (CALG_AES_128 != pKey->Algid) && \
                                 (CALG_AES_192 != pKey->Algid) && \
                                 (CALG_AES_256 != pKey->Algid))

// enduser\netmeeting\as\as16\as16.h
#define PATCH_ENABLE        (ENABLE_ON | ENABLE_FORCALL)
#define PATCH_DISABLE       (ENABLE_OFF | ENABLE_FORCALL)

// enduser\netmeeting\as\h\fh.h
#define FH_SC_EXACT_ASCII_MATCH (FH_SC_MATCH | FH_SC_EXACT)

// enduser\netmeeting\as\h\gdc.h
#define GCT_DEFAULT          (GCT_PKZIP | GCT_PERSIST_PKZIP)

// enduser\netmeeting\as\h\om.h
#define GET_CURR_SEQ_STAMP(stamp, pDomain, pWorkset)                     \
                                                                            \
   (stamp).userID     = pDomain->userID;                                 \
   (stamp).genNumber  = pWorkset->genNumber

// enduser\netmeeting\as\h\s20.h
#define S20_GET_CREATOR(A) ((TSHR_UINT16)(A & 0xFFFF))

// enduser\netmeeting\as\h\sbc.h
#define SBC_TILE_TYPE(TILEID)  \
    (((TILEID) & 0x8000) ? SBC_LARGE_TILE_INDEX : SBC_MEDIUM_TILE_INDEX)

// enduser\netmeeting\as\h\swl.h
#define SWL_GET_INCREMENT(token)        ((token) & 0x000F)

// enduser\netmeeting\as\h\t_share.h
#define S20_ALL_VERSIONS        (S20_2X_VERSION | S20_30_VERSION)

// enduser\netmeeting\av\callcont\ccmain.h
#define ALL_CHANNELS		(TX_CHANNEL | RX_CHANNEL | TXRX_CHANNEL | PROXY_CHANNEL)

// enduser\netmeeting\av\callcont\confman.h
#define ALL_CALLS			(REAL_CALLS | VIRTUAL_CALL)

// enduser\netmeeting\av\callcont\gkiman.h
#define GKIExists() (fGKConfigured && fGKEnabled)

// enduser\netmeeting\av\callcont\h245ws.cpp
#define WINSOCK_EVENT_MSG (WM_USER+1)

// enduser\netmeeting\av\callcont\linkapi.h
#define DATALINK_TRANSMIT_ALL (DATALINK_TRANSMIT | DATALINK_TX_ACTIVES)

// enduser\netmeeting\av\codecs\dec\dech261\huffman.c
#define Numberp(value) ((value & 0x8000) ? 1 : 0)
#define MakeHVal(value) (value | 0x8000)
#define GetHVal(value) (value & 0x7fff)

// enduser\netmeeting\av\codecs\dec\dech261\sc.h
#define IsYUVSep(s)       ((IsYUV422Sep(s))             || \
                           (IsYUV411Sep(s))             || \
                           (IsYUV1611Sep(s)))

// enduser\netmeeting\av\codecs\dec\dech261\slib.h
#define SlibTypeIsMPEG(stype) (stype>=SLIB_TYPE_MPEG1_VIDEO && \
                               stype<=SLIB_TYPE_MPEG_PROGRAM)
#define SlibTypeIsMPEGVideo(stype) (stype<=SLIB_TYPE_MPEG_PROGRAM && \
                                    (stype&0x705))
#define SlibTypeIsMPEGAudio(stype) (stype<=SLIB_TYPE_MPEG_PROGRAM && \
                                    (stype&0x70A))
#define SlibTypeIsMPEGMux(stype) (stype>=SLIB_TYPE_MPEG_SYSTEMS && \
                                  stype<=SLIB_TYPE_MPEG_PROGRAM)
#define SlibTypeIsMPEG2(stype) (stype==SLIB_TYPE_MPEG2_VIDEO || \
                                stype==SLIB_TYPE_MPEG_PROGRAM || \
                                stype==SLIB_TYPE_MPEG_TRANSPORT || \
                                stype==SLIB_TYPE_MPEG2_AUDIO)
#define SlibTypeIsMPEG1(stype) (stype==SLIB_TYPE_MPEG1_VIDEO || \
                                stype==SLIB_TYPE_MPEG1_AUDIO || \
                                stype==SLIB_TYPE_MPEG_SYSTEMS)
#define SlibTypeIsH26X(stype)  ((stype&0xFF00)==0x0800)
#define SlibTypeIsAVI(stype)   (stype>=SLIB_TYPE_AVI && \
                                stype<=SLIB_TYPE_YUV_AVI)
#define SlibTypeIsAudioOnly(stype) (stype==SLIB_TYPE_MPEG1_AUDIO || \
                                    stype==SLIB_TYPE_AC3_AUDIO || \
                                    stype==SLIB_TYPE_G723 || \
                                    stype==SLIB_TYPE_PCM || \
                                    stype==SLIB_TYPE_PCM_WAVE)
#define SlibTypeIsMux(stype)     (SlibTypeIsMPEGMux(stype) || \
                                  SlibTypeIsAVI(stype))

// enduser\netmeeting\av\codecs\dec\dech263\sc.h
#define IsYUVSep(s)       ((IsYUV422Sep(s))             || \
                           (IsYUV411Sep(s))             || \
                           (IsYUV1611Sep(s)))

// enduser\netmeeting\av\codecs\dec\dech263\slib.h
#define SlibTypeIsMPEG(stype) (stype>=SLIB_TYPE_MPEG1_VIDEO && \
                               stype<=SLIB_TYPE_MPEG_PROGRAM)
#define SlibTypeIsMPEGVideo(stype) (stype<=SLIB_TYPE_MPEG_PROGRAM && \
                                    (stype&0x705))
#define SlibTypeIsMPEGAudio(stype) (stype<=SLIB_TYPE_MPEG_PROGRAM && \
                                    (stype&0x70A))
#define SlibTypeIsMPEGMux(stype) (stype>=SLIB_TYPE_MPEG_SYSTEMS && \
                                  stype<=SLIB_TYPE_MPEG_PROGRAM)
#define SlibTypeIsMPEG2(stype) (stype==SLIB_TYPE_MPEG2_VIDEO || \
                                stype==SLIB_TYPE_MPEG_PROGRAM || \
                                stype==SLIB_TYPE_MPEG_TRANSPORT || \
                                stype==SLIB_TYPE_MPEG2_AUDIO)
#define SlibTypeIsMPEG1(stype) (stype==SLIB_TYPE_MPEG1_VIDEO || \
                                stype==SLIB_TYPE_MPEG1_AUDIO || \
                                stype==SLIB_TYPE_MPEG_SYSTEMS)
#define SlibTypeIsH26X(stype)  ((stype&0xFF00)==0x0800)
#define SlibTypeIsAVI(stype)   (stype>=SLIB_TYPE_AVI && \
                                stype<=SLIB_TYPE_YUV_AVI)
#define SlibTypeIsAudioOnly(stype) (stype==SLIB_TYPE_MPEG1_AUDIO || \
                                    stype==SLIB_TYPE_AC3_AUDIO || \
                                    stype==SLIB_TYPE_G723 || \
                                    stype==SLIB_TYPE_PCM || \
                                    stype==SLIB_TYPE_PCM_WAVE)
#define SlibTypeIsMux(stype)     (SlibTypeIsMPEGMux(stype) || \
                                  SlibTypeIsAVI(stype))

// enduser\netmeeting\av\codecs\dec\dech263\sv_h263.h
#define H263_limit(x) \
{ \
    if (x > 255) x = 255; \
    if (x <   0)   x = 0; \
}

// enduser\netmeeting\av\codecs\intel\g723\opt.h
#define SC_DEF (SC_LAG1 | SC_GAIN | SC_FINDB | SC_THRES)  // use all shortcuts

// enduser\netmeeting\av\codecs\intel\g723\util_lbc.c
#define STUFF(x, lp, n_in, k_in) stuff(x, &(lp), n_in, k_in)

// enduser\netmeeting\av\dcap\16\dcap16.c
#define FP_SEG(fp) (*((unsigned *)&(fp) + 1))
#define FP_OFF(fp) (*((unsigned *)&(fp)))

// enduser\netmeeting\av\h323\ctrlh323.h
#define IsCtlChanOpen(f) (f & CTRLF_OPEN)
#define IsOriginating(f) (f & CTRLF_ORIGINATING)

// enduser\netmeeting\av\intelcc\include\linkapi.h
#define DATALINK_TRANSMIT_ALL (DATALINK_TRANSMIT | DATALINK_TX_ACTIVES)

// enduser\netmeeting\av\nac\vcmcaps.h
#define get_format(w,h) ((w == 128 && h == 96 ) ? SQCIF : ((w == 176 && h == 144 )? QCIF: ((w == 352 && h == 288 ) ? CIF :UNKNOWN)))

// enduser\netmeeting\av\rrcm\md5\md5c.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// enduser\netmeeting\av\rrcm\md5\md5c_opt.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// enduser\netmeeting\h\confreg.h
#define	FT_OPTIONS_DEFAULT                   (FT_SHOW_MSG_SENT | FT_SHOW_MSG_REC)
#define DWVERSION_NM_1    (0x04000000 | 1133)  // 1.0 Final
#define DWVERSION_NM_2b2  (0x04000000 | 1266)  // 2.0 Beta 2
#define DWVERSION_NM_2b4  (0x04000000 | 1333)  // 2.0 Beta 4
#define DWVERSION_NM_2b5  (0x04000000 | 1349)  // 2.0 RC 1
#define DWVERSION_NM_2rc2 (0x04000000 | 1366)  // 2.0 RC 2
#define DWVERSION_NM_2    (0x04000000 | 1368)  // 2.0 Final
#define DWVERSION_NM_2q1  (0x04000000 | 1372)  // 2.0 QFE
#define DWVERSION_NM_3a1  (0x04030000 | 2000)  // 2.1 Alpha 1
#define DWVERSION_NM_3b1  (0x04030000 | 2064)  // 2.1 Beta 1
#define DWVERSION_NM_3b2  (0x04030000 | 2099)  // 2.1 Beta 2
#define DWVERSION_NM_3rc  (0x04030000 | 2135)  // 2.1 Final
#define DWVERSION_NM_3o9b1 (0x04030000 | 2408) // 2.11 Office Beta 1 and IE5 Beta 1
#define DWVERSION_NM_3ntb2 (0x04030000 | 2412) // 2.11 NT Beta 2
#define DWVERSION_NM_4a1  (0x04040000 | 2200)  // 3.0 Alpha 1

// enduser\netmeeting\h\iprop.h
#define PROP_VIDEO_POSTPROCESSING_SUPPORTED		29	// (bool) used to query the datapump: TRUE is returned if codec supports post-processing

// enduser\netmeeting\h\version.h
#define VER_PRODUCTVERSION_DW       (0x04040000 | 3400)

// enduser\netmeeting\setup\nmmigrat\setupx.h
#define DriveAtoI( chDrv )      ((int)(chDrv & 31))
#define VCPFL_BACKUPANDCOPY     (VCPFL_BACKUP | VCPFL_COPY)
#define FLG_ADDREG_TYPE_BINARY          ( 0x00000000 | FLG_ADDREG_BINVALUETYPE )
#define GENINSTALL_DO_INIREG    (GENINSTALL_DO_INI | \
                                 GENINSTALL_DO_REG | \
                                 GENINSTALL_DO_INI2REG)

// enduser\netmeeting\ui\conf\audiowiz.h
#define		ISSOUNDCARDPRESENT(SoundCap)	(SoundCap & SOUNDCARD_PRESENT)
#define 	ISSOUNDCARDFULLDUPLEX(SoundCap)	(SoundCap & SOUNDCARD_FULLDUPLEX)
#define		DOESSOUNDCARDHAVEAGC(SoundCap)	(SoundCap & SOUNDCARD_HAVEAGC)
#define 	DOESSOUNDCARDHAVERECVOLCNTRL(SoundCap) (SoundCap & SOUNDCARD_HAVERECVOLCNTRL)

// enduser\netmeeting\ui\conf\nmldap.cpp
#define RESOLVE_USER_SEARCH_FILTER	_T("(&(objectClass=RTPerson)(cn=%s))")
#define LDAP_REFRESH_FILTER			_T("(&(objectClass=RTPerson)(cn=%s)(sttl=10))")

// enduser\stuff\hh\verdef.h
#define VER_PRODUCTVERSION_DW		(0x04740000 | 9120)

// enduser\stuff\hhctrl\autocont.h
#define PPTYPEINFOOFOBJECT(index)      &((((AUTOMATIONOBJECTINFO *)(g_ObjectInfo[(index)]).pInfo)->pTypeInfo))
#define DO_GUIDS_MATCH(riid1, riid2) ((riid1.Data1 == riid2.Data1) && (riid1 == riid2))

// enduser\stuff\hhctrl\autoobj.h
#define PPTYPEINFOOFOBJECT(index)	   &((((AUTOMATIONOBJECTINFO *)(g_ObjectInfo[(index)]).pInfo)->pTypeInfo))

// enduser\stuff\hhctrl\fts.h
#define TOPIC_NUM(exp)  (0x003fffff & exp)

// enduser\stuff\hhctrl\hhamsgs.h
#define DEFAULT_TOC_STYLES (UINT) (WS_BORDER | TVS_DISABLEDRAGDROP | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS )

// enduser\stuff\hhctrl\ipserver.h
#define DO_GUIDS_MATCH(riid1, riid2) ((riid1.Data1 == riid2.Data1) && (riid1 == riid2))
#define QI_INHERITS(pObj, itf)				\
	case Data1_##itf:						\
	  if(DO_GUIDS_MATCH(riid, IID_##itf))	 \
	  { 									\
		*ppvObjOut = (void *)(itf *)pObj;	\
	  } 									\
	  break;

// enduser\stuff\hhctrl\itssini.cpp
#define upper(x) ( ((x) >= 'a' && (x) <= 'z') ? (x)-'a'+'A' : (x) )

// enduser\stuff\hhctrl\verdef.h
#define VER_PRODUCTVERSION_DW		(0x04740000 | 9140)

// enduser\stuff\hhsetup\ipserver.h
#define DO_GUIDS_MATCH(riid1, riid2) ((riid1.Data1 == riid2.Data1) && (riid1 == riid2))
#define QI_INHERITS(pObj, itf)				\
	case Data1_##itf:						\
	  if(DO_GUIDS_MATCH(riid, IID_##itf))	 \
	  { 									\
		*ppvObjOut = (void *)(itf *)pObj;	\
	  } 									\
	  break;

// enduser\stuff\hhsetup\verdef.h
#define VER_PRODUCTVERSION_DW		(0x04740000 | 9120)

// enduser\stuff\itircl\inc\address.h
#define MVAddrSame(mva1, mva2)  (((mva1).tpo == (mva2).tpo) && ((mva1).tpid == (mva2).tpid))

// enduser\stuff\itircl\inc\imvfs.h
#define wReadWrite  (wRead | wWrite)
#define wShareAll   (wShareRead | wShareWrite)

// enduser\stuff\itircl\inc\mem.h
#define	DLLGMEM_ZEROINIT		(GMEM_MOVEABLE | GMEM_ZEROINIT)

// enduser\stuff\itircl\inc\objects.h
#define GetSmallFormat(b) ((b) & 0x0f)
#define IsSmallFormat(b) ((b) & 0x0f) == bSmallFormat0)
#define bShortUidPopup     (fHS|fHSNorm                               )
#define bShortUidJump      (fHS|fHSNorm                       |fHSJump)
#define bShortHashPopup    (fHS|fHSNorm               |fHSHash        )
#define bShortHashJump     (fHS|fHSNorm               |fHSHash|fHSJump)
#define bShortInvHashJump  (fHS|fHSNorm        |fHSInv|fHSHash|fHSJump)
#define bShortInvHashPopup (fHS|fHSNorm        |fHSInv|fHSHash        )

// enduser\stuff\itircl\inc\wrapstor.h
#define wReadWrite  (wRead | wWrite)
#define wShareAll   (wShareRead | wShareWrite)

// enduser\stuff\itss\ieverp.h
#define VER_PRODUCTVERSION_DW		(0x05000000 | VER_PRODUCTBUILD)

// enduser\stuff\odbc32\sql.cpp
#define SQL_SUCCEEDED(rc) (((rc)&(~1))==0)

// enduser\stuff\odbc32\sqlext.cpp
#define SQL_IK_ALL							(SQL_IK_ASC | SQL_IK_DESC)

// enduser\troubleshoot\bn\basics.h
#define DECLARE_ORDERING_OPERATORS(T)				\
	bool operator <  ( const T & ) const;			\
	bool operator >  ( const T & ) const;			\
	bool operator == ( const T & ) const;			\
	bool operator != ( const T & ) const;

// enduser\troubleshoot\tshoot\propnames.h
#define H_NET_RESNIFF_POLICY		_T("HNetResniffPolicy") // {"No"| "Explicit"| "Implicit"| "Yes"}

// inetcore\connectionwizard\icwconn\wizard.h
#define PVAREMPTY ((VARIANT*)&c_vaEmpty)

// inetcore\connectionwizard\icwdial\dialdlg.cpp
#define PBM_SETPOS              (WM_USER+2)

// inetcore\connectionwizard\icwhelp\inshandler.cpp
#define myisdigit(ch) (((ch) >= '0') && ((ch) <= '9'))

// inetcore\connectionwizard\icwutil\icwutil.h
#define PVAREMPTY ((VARIANT*)&c_vaEmpty)

// inetcore\connectionwizard\inc\icwcmn.h
#define WUM_SETTITLE        (WM_USER + 100)

// inetcore\connectionwizard\inc\ocdb.h
#define ICursor_GetColumnsCursor(pI, riid, ppvColumnsCursor, pcRows) \
    (*(pI)->lpVtbl->GetColumnsCursor)((pI), riid, ppvColumnsCursor, pcRows)
#define ICursor_Requery(pI) \
    (*(pI)->lpVtbl->Requery)((pI))
#define ICursorMove_GetColumnsCursor(pI, riid, ppvColumnsCursor, pcRows) \
    (*(pI)->lpVtbl->GetColumnsCursor)((pI), riid, ppvColumnsCursor, pcRows)
#define ICursorMove_Requery(pI) \
    (*(pI)->lpVtbl->Requery)((pI))
#define ICursorScroll_GetColumnsCursor(pI, riid, ppvColumnsCursor, pcRows) \
    (*(pI)->lpVtbl->GetColumnsCursor)((pI), riid, ppvColumnsCursor, pcRows)
#define ICursorScroll_Requery(pI) \
    (*(pI)->lpVtbl->Requery)((pI))
#define ICursorScroll_GetApproximateCount(pI, pudlApproxCount, pdwFullyPopulated) \
    (*(pI)->lpVtbl->GetApproximateCount)((pI), pudlApproxCount, pdwFullyPopulated)
#define ICursorUpdateARow_SetColumn(pI, pcid, pBindParams) \
    (*(pI)->lpVtbl->SetColumn)((pI), pcid, pBindParams)
#define ICursorUpdateARow_Cancel(pI) \
    (*(pI)->lpVtbl->Cancel)((pI))
#define INotifyDBEvents_OKToDo(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->OKToDo)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_Cancelled(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->Cancelled)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_AboutToDo(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->AboutToDo)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_SyncAfter(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->SyncAfter)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_DidEvent(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->DidEvent)((pI), dwEventWhat, cReasons, rgReasons)

// inetcore\connectionwizard\inetcfg\imnact.h
#define HR_CODE(hr) (INT)(hr & 0xffff)

// inetcore\connectionwizard\isign32\import.cpp
#define myisdigit(ch) (((ch) >= '0') && ((ch) <= '9'))

// inetcore\datacab\viaduct\msr2c\fastguid.h
#define BOOL_PROP_SUPPORTED(itf, value) \
    case itf: \
		var.boolVal     = (VARIANT_BOOL)value; \
		fPropSupported	= TRUE; \
		break;
#define I4_PROP_SUPPORTED(itf, value)    \
    case itf:  \
		var.vt			= VT_I4; \
		var.lVal	    = value; \
		fPropSupported	= TRUE;	\
		break;

// inetcore\datacab\viaduct\msr2c\ipserver.h
#define DO_GUIDS_MATCH(riid1, riid2) ((riid1.Data1 == riid2.Data1) && (riid1 == riid2))

// inetcore\datacab\viaduct\msr2c\ocdb.h
#define ICursor_GetColumnsCursor(pI, riid, ppvColumnsCursor, pcRows) \
    (*(pI)->lpVtbl->GetColumnsCursor)((pI), riid, ppvColumnsCursor, pcRows)
#define ICursor_Requery(pI) \
    (*(pI)->lpVtbl->Requery)((pI))
#define ICursorMove_GetColumnsCursor(pI, riid, ppvColumnsCursor, pcRows) \
    (*(pI)->lpVtbl->GetColumnsCursor)((pI), riid, ppvColumnsCursor, pcRows)
#define ICursorMove_Requery(pI) \
    (*(pI)->lpVtbl->Requery)((pI))
#define ICursorScroll_GetColumnsCursor(pI, riid, ppvColumnsCursor, pcRows) \
    (*(pI)->lpVtbl->GetColumnsCursor)((pI), riid, ppvColumnsCursor, pcRows)
#define ICursorScroll_Requery(pI) \
    (*(pI)->lpVtbl->Requery)((pI))
#define ICursorScroll_GetApproximateCount(pI, pudlApproxCount, pdwFullyPopulated) \
    (*(pI)->lpVtbl->GetApproximateCount)((pI), pudlApproxCount, pdwFullyPopulated)
#define ICursorUpdateARow_SetColumn(pI, pcid, pBindParams) \
    (*(pI)->lpVtbl->SetColumn)((pI), pcid, pBindParams)
#define ICursorUpdateARow_Cancel(pI) \
    (*(pI)->lpVtbl->Cancel)((pI))
#define INotifyDBEvents_OKToDo(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->OKToDo)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_Cancelled(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->Cancelled)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_AboutToDo(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->AboutToDo)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_SyncAfter(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->SyncAfter)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_DidEvent(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->DidEvent)((pI), dwEventWhat, cReasons, rgReasons)

// inetcore\digest\md5c.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// inetcore\mshtml\btools\tlviewer\hostenv.h
#define UNUSED(X) ((void)(void*)&(X))

// inetcore\mshtml\external\inc\msls\zqfromza.h
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

// inetcore\mshtml\external\inc\vbcursor\ocdb.h
#define ICursor_GetColumnsCursor(pI, riid, ppvColumnsCursor, pcRows) \
    (*(pI)->lpVtbl->GetColumnsCursor)((pI), riid, ppvColumnsCursor, pcRows)
#define ICursor_Requery(pI) \
    (*(pI)->lpVtbl->Requery)((pI))
#define ICursorMove_GetColumnsCursor(pI, riid, ppvColumnsCursor, pcRows) \
    (*(pI)->lpVtbl->GetColumnsCursor)((pI), riid, ppvColumnsCursor, pcRows)
#define ICursorMove_Requery(pI) \
    (*(pI)->lpVtbl->Requery)((pI))
#define ICursorScroll_GetColumnsCursor(pI, riid, ppvColumnsCursor, pcRows) \
    (*(pI)->lpVtbl->GetColumnsCursor)((pI), riid, ppvColumnsCursor, pcRows)
#define ICursorScroll_Requery(pI) \
    (*(pI)->lpVtbl->Requery)((pI))
#define ICursorScroll_GetApproximateCount(pI, pudlApproxCount, pdwFullyPopulated) \
    (*(pI)->lpVtbl->GetApproximateCount)((pI), pudlApproxCount, pdwFullyPopulated)
#define ICursorUpdateARow_SetColumn(pI, pcid, pBindParams) \
    (*(pI)->lpVtbl->SetColumn)((pI), pcid, pBindParams)
#define ICursorUpdateARow_Cancel(pI) \
    (*(pI)->lpVtbl->Cancel)((pI))
#define INotifyDBEvents_OKToDo(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->OKToDo)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_Cancelled(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->Cancelled)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_AboutToDo(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->AboutToDo)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_SyncAfter(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->SyncAfter)((pI), dwEventWhat, cReasons, rgReasons)
#define INotifyDBEvents_DidEvent(pI, dwEventWhat, cReasons, rgReasons) \
    (*(pI)->lpVtbl->DidEvent)((pI), dwEventWhat, cReasons, rgReasons)

// inetcore\mshtml\src\core\cdutil\tearoff.cxx
#define THUNK_ADDRESS(n) & TearoffThunk##n,

// inetcore\mshtml\src\core\cdutil\unixtearoff.cxx
#define THUNK_PLAIN_ADDRESS(n) ((PLAINPFNTEAROFF)&TearoffThunk##n),

// inetcore\mshtml\src\core\include\cdutil.hxx
#define NO_COPY(cls)    \
    cls(const cls&);    \
    cls& operator=(const cls&)
#define STGM_DFRALL (STGM_READWRITE|STGM_TRANSACTED|STGM_SHARE_DENY_WRITE)
#define STGM_DFALL (STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_EXCLUSIVE)
#define STGM_SALL  (STGM_READWRITE | STGM_SHARE_EXCLUSIVE)
#define STGM_SRO  (STGM_READ | STGM_SHARE_EXCLUSIVE)
#define CALL_METHOD(pObj,pfnMethod,args) \
    (pObj->*pfnMethod) args
#define ONCALL_METHOD(klass, fn, FN)    (PFN_VOID_ONCALL)&klass::fn
#define ONMESSAGE_METHOD(klass, fn, FN)\
            (PFN_VOID_ONMESSAGE)&klass::fn

// inetcore\mshtml\src\core\include\qi_impl.h
#define QI_INHERITS(pObj, itf)              \
    case Data1_##itf:                       \
        if (iid == IID_##itf)               \
        {                                   \
        *ppv = (itf *)pObj;                 \
        }                                   \
        break;                              \
#define QI_INHERITS2(pObj, itf, itfDerived) \
    case Data1_##itf:                       \
        if (iid == IID_##itf)               \
        {                                   \
        *ppv = (itfDerived *)pObj;          \
        }                                   \
        break;                              \

// inetcore\mshtml\src\core\include\unixtoff.hxx
#define TEAROFF_METHOD_SUB(klass, subklass, fn, FN, args)\
    TEAROFF_METHOD(klass::subklass, klass::subklass::fn, klass::subklass::FN, args)

// inetcore\mshtml\src\core\include\wintoff.hxx
#define _TEAROFF_METHOD_(fn, FN, ret, args)\
    (PFNTEAROFF)(ret (STDMETHODCALLTYPE CVoid::*const)args)fn,
#define TEAROFF_METHOD_(klass, fn, FN, ret, args)\
    (PFNTEAROFF)(ret (STDMETHODCALLTYPE CVoid::*const)args)fn,
#define TEAROFF_METHOD_SUB(klass, subklass, fn, FN, args)\
    TEAROFF_METHOD(klass::subklass, klass::subklass::fn, klass::subklass::FN, args)

// inetcore\mshtml\src\edit\pastecmd.cxx
#define COPY_STYLE_VARIANT(style)                                                   \
                    VariantClear( &vStyleValue );                                   \
                    IFC( spCurrentStyle->get_ ## style( &vStyleValue ) );           \
                    IFC( spStyle->put_ ## style( vStyleValue ) );

// inetcore\mshtml\src\f3\include\hook.hxx
#define HOOKCTOR0(hkcl) \
     hkcl##Hook()      HOOKMETH( _impl = ::new hkcl; )
#define HOOKCTOR1(hkcl, t1, a1) \
     hkcl##Hook(t1 a1) HOOKMETH( _impl = ::new hkcl(a1); )

// inetcore\mshtml\src\site\dbind\convert.cxx
#define PROCESS_NOCALL  ((void *)~0)

// inetcore\mshtml\src\site\include\cfpf.hxx
#define GET_PGBRK_BEFORE(a)     (a&0x0e)

// inetcore\mshtml\src\site\style\curstyle.cxx
#define GetUnitValueWithEnumDef(p, Uv, pDesc, enumname, nDefEnumValue) \
    GetUnitValueHelper(p, Uv, pDesc, &s_enumdesc##enumname, nDefEnumValue)
#define GetUnitValueWithEnum(p, Uv, pDesc, enumname) \
    GetUnitValueHelper(p, Uv, pDesc, &s_enumdesc##enumname)

// inetcore\mshtml\src\site\style\tokenz.cxx
#define ISHEXAL(ch) (((unsigned)((ch) & ~(_T('a') ^ _T('A'))) - _T('A')) <= _T('F')-_T('A'))
#define ISHEX(ch)   (ISDIGIT(ch) || ISHEXAL(ch))

// inetcore\mshtml\src\site\util\collect.hxx
#define ENSURE_METHOD(klass, fn, FN)\
        (PFN_CVOID_ENSURE)&klass::fn
#define CREATECOL_METHOD(klass, fn, FN)\
        (PFN_CVOID_CREATECOL)&klass::fn
#define REMOVEOBJECT_METHOD(klass, fn, FN)\
        (PFN_CVOID_REMOVEOBJECT)&klass::fn
#define ADDNEWOBJECT_METHOD(klass, fn, FN)\
        (PFN_CVOID_ADDNEWOBJECT)&klass::fn

// inetcore\mshtml\test\reflectr\response.cxx
#define FROMHEX( _v ) \
    ( ( _v >= 48 ) && ( _v <= 57 ) ? _v - 48 : \
    ( ( _v >= 65 ) && ( _v <= 70 ) ? _v + 10 - 65 : 0 ) )

// inetcore\mshtml\tried\triedctl\win95wrp.cpp
#define Convert(szFrom) ConvertWithLen(szFrom, -1, &_lJunk)

// inetcore\mshtml\tried\triedit\lex.h
#define P_IN(x)     const x &
#define P_OUT(x)    x &
#define P_IO(x)     x &

// inetcore\mshtml\tried\triedit\token.h
#define INTAG (inTag|inBangTag|inPITag|inHTXTag|inEndTag)

// inetcore\mshtml\tried\triedit\tokhtml.h
#define INTAG (inTag|inBangTag|inPITag|inHTXTag|inEndTag)

// inetcore\mshtml\tried\triedit\win95wrp.cpp
#define Convert(szFrom) ConvertWithLen(szFrom, -1, &_lJunk)

// inetcore\published\inc\ieverp.h
#define VER_PRODUCTVERSION_DW		(0x06000000 | VER_PRODUCTBUILD)

// inetcore\setup\active\ie4uinit\utils.h
#define IsSpace(c)  ((c) == ' '  ||  (c) == '\t'  ||  (c) == '\r'  ||  (c) == '\n'  ||  (c) == '\v'  ||  (c) == '\f')

// inetcore\setup\active\iernonce\iernonce.h
#define IsSpace(c)              ((c) == ' '  ||  (c) == '\t'  ||  (c) == '\r'  ||  (c) == '\n'  ||  (c) == '\v'  ||  (c) == '\f')

// inetcore\setup\active\inc\autoobj.h
#define PPTYPEINFOOFOBJECT(index)      &((((AUTOMATIONOBJECTINFO *)(g_ObjectInfo[(index)]).pInfo)->pTypeInfo))

// inetcore\setup\active\inc\ipserver.h
#define DO_GUIDS_MATCH(riid1, riid2) ((riid1.Data1 == riid2.Data1) && (riid1 == riid2))
#define QI_INHERITS(pObj, itf)              \
    case Data1_##itf:                       \
      if(DO_GUIDS_MATCH(riid, IID_##itf))    \
      {                                     \
        *ppvObjOut = (void *)(itf *)pObj;   \
      }                                     \
      break;

// inetcore\setup\active\inc\prsht.h
#define PSM_SETCURSEL           (WM_USER + 101)
#define PSM_CHANGED             (WM_USER + 104)
#define PSM_REBOOTSYSTEM        (WM_USER + 106)
#define PSM_QUERYSIBLINGS       (WM_USER + 108)
#define PSM_UNCHANGED           (WM_USER + 109)
#define PSM_APPLY               (WM_USER + 110)
#define PSM_SETTITLEA           (WM_USER + 111)
#define PSM_SETTITLEW           (WM_USER + 120)
#define PSM_SETWIZBUTTONS       (WM_USER + 112)
#define PSM_PRESSBUTTON         (WM_USER + 113)
#define PSM_SETCURSELID         (WM_USER + 114)

// inetcore\setup\ieak5\brandll\brand.h
#define FSWP_DEFAULT   (FSWP_KEY | FSWP_VALUE | FSWP_VALUELDID)

// inetcore\setup\ieak5\cd\autorun\autorun.c
#define ARM_MOUSEOVER       (WM_APP)

// inetcore\setup\ieak5\cd\iecd\iecd.c
#define IsSpace(c)              ((c) == ' '  ||  (c) == '\t'  ||  (c) == '\r'  ||  (c) == '\n'  ||  (c) == '\v'  ||  (c) == '\f')

// inetcore\setup\ieak5\cd\setup\version.h
#define VER_PRODUCTVERSION_DW       (0x01000000 | 6)

// inetcore\setup\ieak5\cdinst\cdinst.h
#define IsSpace(c)              ((c) == ' '  ||  (c) == '\t'  ||  (c) == '\r'  ||  (c) == '\n'  ||  (c) == '\v'  ||  (c) == '\f')

// inetcore\setup\ieak5\ieakeng\exports.h
#define FC_FILE         (FC_PATH | 0x00000100)
#define FC_DIR          (FC_PATH | 0x00000200)

// inetcore\setup\ieak5\ieakutil\ieakutil.h
#define PIVP_FILE_ONLY      (PIVP_MUST_EXIST   | 0x00000020)
#define PIVP_FOLDER_ONLY    (PIVP_MUST_EXIST   | 0x00000040)

// inetcore\setup\ieak5\inc\iedkbrnd.h
#define BRAND_QUICKLINKS    (BRAND_QL1 | BRAND_QL2 | BRAND_QL3 | BRAND_QL4 | BRAND_QL5)
#define BRAND_NO_MAIL       (BRAND_FAVORITES | BRAND_CONF | BRAND_TOOLBAR)
#define KEY_DEFAULT_ACCESS (KEY_READ | KEY_WRITE)

// inetcore\setup\ieak5\inc\version.h
#define VER_PRODUCTVERSION_DW       (0x01000000 | 509)

// inetcore\setup\iexpress\advpext\redblack.h
#define RBNIL ((PNAME_NODE)&NameRbEmptyNode)

// inetcore\setup\sdslib\sdsutils.h
#define IsSpace(c)  ((c) == ' '  ||  (c) == '\t'  ||  (c) == '\r'  ||  (c) == '\n'  ||  (c) == '\v'  ||  (c) == '\f')

// inetcore\urlmon\inc\urlint.h
    #   define DEB_ASYNCAPIS        (DEB_USER1 | DEB_URLMK_LEVEL)
    #   define DEB_URLMON           (DEB_USER2 | DEB_URLMK_LEVEL)
    #   define DEB_DLL              (DEB_USER4 | DEB_URLMK_LEVEL)
    #   define DEB_FORMAT           (DEB_USER5 | DEB_URLMK_LEVEL)
    #   define DEB_CODEDL           (DEB_USER6 | DEB_URLMK_LEVEL)
    #   define DEB_BINDING          (DEB_USER1 | DEB_TRANS_LEVEL)
    #   define DEB_TRANS            (DEB_USER2 | DEB_TRANS_LEVEL)
    #   define DEB_DATA             (DEB_USER4 | DEB_TRANS_LEVEL)
    #   define DEB_TRANSMGR         (DEB_USER5 | DEB_TRANS_LEVEL)
    #   define DEB_SESSION          (DEB_USER6 | DEB_TRANS_LEVEL)
    #   define DEB_PROT             (DEB_USER1 | DEB_PROT_LEVEL)
    #   define DEB_PROTHTTP         (DEB_USER2 | DEB_PROT_LEVEL)
    #   define DEB_PROTFTP          (DEB_USER3 | DEB_PROT_LEVEL)
    #   define DEB_PROTGOPHER       (DEB_USER4 | DEB_PROT_LEVEL)
    #   define DEB_PROTSIMP         (DEB_USER5 | DEB_PROT_LEVEL)
    #   define DEB_NOTF_1             (DEB_USER1  | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_2             (DEB_USER2  | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_3             (DEB_USER3  | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_4             (DEB_USER4  | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_5             (DEB_USER5  | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_6             (DEB_USER6  | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_7             (DEB_USER7  | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_8             (DEB_USER8  | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_9             (DEB_USER9  | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_10            (DEB_USER10 | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_11            (DEB_USER11 | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_12            (DEB_USER12 | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_13            (DEB_USER13 | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_14            (DEB_USER14 | DEB_NOTF_LEVEL)
    #   define DEB_NOTF_15            (DEB_USER15 | DEB_NOTF_LEVEL)
    #   define DEB_PLUGPROT         (DEB_USER1  | DEB_EPROT_LEVEL)
    #   define DEB_TNOTF_1            (DEB_USER1  | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_2            (DEB_USER2  | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_3            (DEB_USER3  | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_4            (DEB_USER4  | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_5            (DEB_USER5  | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_6            (DEB_USER6  | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_7            (DEB_USER7  | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_8            (DEB_USER8  | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_9            (DEB_USER9  | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_10           (DEB_USER10 | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_11           (DEB_USER11 | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_12           (DEB_USER12 | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_13           (DEB_USER13 | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_14           (DEB_USER14 | DEB_TNOTF_LEVEL)
    #   define DEB_TNOTF_15           (DEB_USER15 | DEB_TNOTF_LEVEL)

// inetcore\winhttp\tools\w3spoof\inc\resources.h
#define NEWVARIANT(x) VARIANT x; VariantInit(&x);

// inetcore\winhttp\tools\whttptst\inc\resources.h
#define NEWVARIANT(x) VARIANT x; VariantInit(&x);

// inetcore\winhttp\v5.1\autoproxy\dhcp.h
#define CLASSD_NET_ADDR(a)  ( (a & 0xf0) == 0xe0)
#define CLASSD_HOST_ADDR(a)  ((a & 0xf0000000) == 0xe0000000)

// inetcore\winhttp\v5.1\http\chunkflt.cxx
#define GET_VALUE_FROM_ASCII_HEX(ch)  ((ch) - ((ch) & 0xf0) + (((ch) & 0x40) ? 9 : 0))

// inetcore\winhttp\v5.1\ihttprequest\httprequest.hxx
#define WHREM_MSG_ON_RESPONSE_START             (WM_USER + 1)
#define WHREM_MSG_ON_RESPONSE_DATA_AVAILABLE    (WM_USER + 2)
#define WHREM_MSG_ON_RESPONSE_FINISHED          (WM_USER + 3)

// inetcore\winhttp\v5.1\inc\parseurl.h
#define SCHEME_ANY          (SCHEME_FTP | SCHEME_GOPHER | SCHEME_HTTP)

// inetcore\winhttp\v5.1\inc\thrdinfo.h
#define _InternetGetObjectHandle(lpThreadInfo) \
    lpThreadInfo->hObject
#define _InternetGetAsync(lpThreadInfo) \
    lpThreadInfo->IsAsyncWorkerThread
#define _InternetSetAsync(lpThreadInfo, Val) \
    lpThreadInfo->IsAsyncWorkerThread = Val
#define _InternetGetInCallback(lpThreadInfo) \
    lpThreadInfo->InCallback
#define _InternetSetInCallback(lpThreadInfo) \
    lpThreadInfo->InCallback = TRUE
#define _InternetResetInCallback(lpThreadInfo) \
    lpThreadInfo->InCallback = FALSE

// inetcore\winhttp\v5\http\chunkflt.cxx
#define GET_VALUE_FROM_ASCII_HEX(ch)  ((ch) - ((ch) & 0xf0) + (((ch) & 0x40) ? 9 : 0))

// inetcore\winhttp\v5\ihttprequest\httprequest.hxx
#define WHREM_MSG_ON_RESPONSE_START             (WM_USER + 1)
#define WHREM_MSG_ON_RESPONSE_DATA_AVAILABLE    (WM_USER + 2)
#define WHREM_MSG_ON_RESPONSE_FINISHED          (WM_USER + 3)

// inetcore\winhttp\v5\inc\parseurl.h
#define SCHEME_ANY          (SCHEME_FTP | SCHEME_GOPHER | SCHEME_HTTP)

// inetcore\winhttp\v5\inc\thrdinfo.h
#define _InternetGetObjectHandle(lpThreadInfo) \
    lpThreadInfo->hObject
#define _InternetGetAsync(lpThreadInfo) \
    lpThreadInfo->IsAsyncWorkerThread
#define _InternetSetAsync(lpThreadInfo, Val) \
    lpThreadInfo->IsAsyncWorkerThread = Val
#define _InternetGetInCallback(lpThreadInfo) \
    lpThreadInfo->InCallback
#define _InternetSetInCallback(lpThreadInfo) \
    lpThreadInfo->InCallback = TRUE
#define _InternetResetInCallback(lpThreadInfo) \
    lpThreadInfo->InCallback = FALSE

// inetcore\winhttp\v5\urlcache\reg.hxx
#define BASIC_ACCESS  ( KEY_QUERY_VALUE | \
                               KEY_ENUMERATE_SUB_KEYS )

// inetcore\wininet\apdetect\dhcp.h
#define CLASSD_NET_ADDR(a)  ( (a & 0xf0) == 0xe0)
#define CLASSD_HOST_ADDR(a)  ((a & 0xf0000000) == 0xe0000000)

// inetcore\wininet\auth\md5c.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// inetcore\wininet\ftp\session.h
#define SetSessionSignature(lpSessionInfo)  \
    (lpSessionInfo)->Signature = FTP_SESSION_SIGNATURE

// inetcore\wininet\inc\parseurl.h
#define SCHEME_ANY          (SCHEME_FTP | SCHEME_GOPHER | SCHEME_HTTP)

// inetcore\wininet\inc\private\resolv.h
#define RES_DEFAULT (RES_RECURSE | RES_DEFNAMES | RES_DNSRCH)

// inetcore\wininet\inc\thrdinfo.h
#define _InternetGetObjectHandle(lpThreadInfo) \
    lpThreadInfo->hObject
#define _InternetGetAsync(lpThreadInfo) \
    lpThreadInfo->IsAsyncWorkerThread
#define _InternetSetAsync(lpThreadInfo, Val) \
    lpThreadInfo->IsAsyncWorkerThread = Val
#define _InternetGetInCallback(lpThreadInfo) \
    lpThreadInfo->InCallback
#define _InternetSetInCallback(lpThreadInfo) \
    lpThreadInfo->InCallback = TRUE
#define _InternetResetInCallback(lpThreadInfo) \
    lpThreadInfo->InCallback = FALSE
#define _InternetSetAutoProxy(lpThreadInfo) \
    lpThreadInfo->IsAutoProxyProxyThread = TRUE

// inetcore\wininet\socks\wsock32.c
#define IOC_INOUT       (IOC_IN|IOC_OUT)

// inetcore\wininet\urlcache\reg.hxx
#define BASIC_ACCESS  ( KEY_QUERY_VALUE | \
                               KEY_ENUMERATE_SUB_KEYS )

// inetsrv\iis\config\src\inc\corhdr.h
#define IsTdPublic(x)                       ((x) & tdPublic)
#define IsTdSerializable(x)					((x) & tdSerializable)
#define IsTdSealed(x)                       ((x) & tdSealed)
#define IsTdImport(x)                       ((x) & tdImport)
#define IsTdEnum(x)                         ((x) & tdEnum)
#define IsTdLazyInit(x)                     ((x) & tdLazyInit)
#define IsTdMarshalByRef(x)                 ((x) & tdMarshalByRef)
#define IsItImplements(x)                   ((x) & itImplements)
#define IsItEvents(x)                       ((x) & itEvents)
#define IsItRequires(x)                     ((x) & itRequires)
#define IsItInherits(x)                     ((x) & itInherits)
#define IsCaaDeferCreate(x)                 ((x) & caaDeferCreate)
#define IsCaaAppObject(x)                   ((x) & caaAppObject)
#define IsCaaFixedIfaceSet(x)               ((x) & caaFixedIfaceSet)
#define IsCaaIndependentlyCreateable(x)     ((x) & caaIndependentlyCreateable)
#define IsCaaPredefined(x)                  ((x) & caaPredefined)
#define IsCaaOPNotSupported(x)              (((x) & caaObjectPooling) == caaOPNotSupported)
#define IsCaaOPSupported(x)                 (((x) & caaObjectPooling) == caaOPSupported)
#define IsCaaOPNotSpecified(x)              (((x) & caaObjectPooling) == caaOPNotSpecified)
#define IsCaaJANotSupported(x)              (((x) & caaJITActivation) == caaJANotSupported)
#define IsCaaJASupported(x)                 (((x) & caaJITActivation) == caaJASupported)
#define IsCaaJANotSpecified(x)              (((x) & caaJANotSpecified) == caaJANotSpecified)
#define IsMdStatic(x)                       ((x) & mdStatic)
#define IsMdFinal(x)                        ((x) & mdFinal)
#define IsMdVirtual(x)                      ((x) & mdVirtual)
#define IsMdSynchronized(x)                 ((x) & mdSynchronized)
#define IsMdSpecialName(x)                  ((x) & mdSpecialName)
#define IsMdRTSpecialName(x)                ((x) & mdRTSpecialName)
#define IsFdStatic(x)                       ((x) & fdStatic)
#define IsFdInitOnly(x)                     ((x) & fdInitOnly)
#define IsFdLiteral(x)                      ((x) & fdLiteral)
#define IsFdNotSerialized(x)                ((x) & fdNotSerialized)
#define IsFdVolatile(x)                     ((x) & fdVolatile)
#define IsFdSpecialName(x)                  ((x) & fdSpecialName)
#define IsFdRTSpecialName(x)                ((x) & fdRTSpecialName)
#define IsPdIn(x)                           ((x) & pdIn)
#define IsPdOut(x)                          ((x) & pdOut)
#define IsPdLcid(x)                         ((x) & pdLcid)
#define IsPdRetval(x)                       ((x) & pdRetval)
#define IsPdOptional(x)                     ((x) & pdOptional)
#define IsPrDefaultProperty(x)				((x) & prDefaultProperty)
#define IsPrReadOnly(x)						((x) & prReadOnly)
#define IsPrSpecialName(x)				    ((x) & prSpecialName)
#define IsPrRTSpecialName(x)				((x) & prRTSpecialName)
#define IsPrNotSerialized(x)				((x) & prNotSerialized)
#define IsEvPublic(x)                       ((x) & evPublic)
#define IsEvPrivate(x)                      ((x) & evPrivate)
#define IsEvProtected(x)                    ((x) & evProtected)
#define IsEvSpecialName(x)                  ((x) & evSpecialName)
#define IsEvRTSpecialName(x)                ((x) & evRTSpecialName)
#define IsMsSetter(x)                       ((x) & msSetter)
#define IsMsGetter(x)                       ((x) & msGetter)
#define IsMsReset(x)                        ((x) & msReset)
#define IsMsTestDefault(x)                  ((x) & msTestDefault)
#define IsMsOther(x)                        ((x) & msOther)
#define IsMsAddOn(x)                        ((x) & msAddOn)
#define IsMsRemoveOn(x)                     ((x) & msRemoveOn)
#define IsMsFire(x)                         ((x) & msFire)
#define IsMiImplemented(x)                  ((x) & miImplemented)
#define IsMiOLE(x)                          ((x) & miOLE)
#define IsMiInternalCall(x)                 ((x) & miInternalCall)
#define IsPmNoMangle(x)                     ((x) & pmNoMangle)
#define IsPmPinvokeOLE(x)                   ((x) & pmPinvokeOLE)
#define IsPmCallConvWinapi(x)               ((x) & pmCallConvWinapi)
#define IsPmCallConvCdecl(x)                ((x) & pmCallConvCdecl)
#define IsPmCallConvFastcall(x)             ((x) & pmCallConvFastcall)
#define IsAfImplicitResources(x)            ((x) & afImplicitResources)
#define IsFfWriteable(x)                    ((x) & ffWriteable)
#define RidToToken(rid,tktype) ((rid) |= (tktype))
#define TokenFromRid(rid,tktype) ((rid) | (tktype))
#define RidFromToken(tk) ((RID) ((tk) & 0x00ffffff))
#define TypeFromToken(tk) ((tk) & 0xff000000)

// inetsrv\iis\config\src\inc\correg.h
#define RidToToken(rid,tktype) ((rid) |= (tktype))
#define TokenFromRid(rid,tktype) ((rid) | (tktype))
#define RidFromToken(tk) ((RID) ((tk) & 0x00ffffff))
#define TypeFromToken(tk) ((tk) & 0xff000000)

// inetsrv\iis\config\src\shared\util\md5.cpp
    #define G(x, y, z) ((((x) ^ (y)) & (z)) ^ (y))          // an alternate encoding
    #define H(x, y, z) ((x) ^ (y) ^ (z))
    #define I(x, y, z) ((y) ^ ((x) | (~z)))

// inetsrv\iis\iisrearc\core\perfctrs\inc\counters.h
#define BEGIN_CPP_PERFORMACE_CLASS(cperfclass)                          \
class cperfclass :                                                      \
    public CCounterDef_IISCtrs                                          \
{                                                                       \
public: cperfclass();                                                   \

// inetsrv\iis\iisrearc\iisplus\ulw3\cgi_handler.h
#define ISUNC(a) ((a)[0]=='\\' && (a)[1]=='\\')

// inetsrv\iis\iisrearc\ul\drv\misc.h
#define URL_TOKEN           (HTTP_ALPHA | HTTP_DIGIT | URL_LEGAL)

// inetsrv\iis\iisrearc\ul\drv\sendresponse.h
#define CONNECTION_FROM_TRACKER( tracker )                                  \
    ( (tracker)->pConnection )

// inetsrv\iis\iisrearc\ul\drv\thrdpool.cxx
#define CURRENT_THREAD_POOL()   \
    &g_UlThreadPool[KeGetCurrentProcessorNumber()].ThreadPool
#define WAIT_THREAD_POOL()      \
    &g_UlThreadPool[g_UlNumberOfProcessors].ThreadPool

// inetsrv\iis\iisrearc\ul\ulkd\cons.h
#define UC(x)       ((UINT)((x) & 0xFF))

// inetsrv\iis\iisrearc\ulrtl\misc.h
#define URL_TOKEN           (HTTP_ALPHA | HTTP_DIGIT | URL_LEGAL)

// inetsrv\iis\inc\_ntverp.h
#define VER_PRODUCTVERSION_DW       (0x04460000 | VER_PRODUCTBUILD)
#define VER_PRODUCTVERSION_DW       (0x05000000 | VER_PRODUCTBUILD)

// inetsrv\iis\inc\rdns.hxx
#define MAKEREF(a)      ((a)|0x80000000)

// inetsrv\iis\setup\osrc\svc.cpp
# define SetServiceTypeValues( pSvcTypeValue, dwNS, dwType, dwSize, lpValName, lpVal)   \
       ( pSvcTypeValue)->dwNameSpace = ( dwNS);          \
       ( pSvcTypeValue)->dwValueType = ( dwType);        \
       ( pSvcTypeValue)->dwValueSize = ( dwSize);        \
       ( pSvcTypeValue)->lpValueName = ( lpValName);     \
       ( pSvcTypeValue)->lpValue     = (PVOID ) ( lpVal); \

// inetsrv\iis\setup\util\migrate\helper.cpp
#define FLG_ADDREG_TYPE_BINARY      ( 0x00000000 | FLG_ADDREG_BINVALUETYPE )
#define FLG_ADDREG_TYPE_NONE        ( 0x00020000 | FLG_ADDREG_BINVALUETYPE )

// inetsrv\iis\staxinc\exchmole.h
#define HR_CODE(hr) (INT)(hr & 0xffff)

// inetsrv\iis\staxinc\export\cpoolmac.h
    #define DECLARE_CPOOL_STATIC(CMyClass) \
                CPool CMyClass::m_MyClassPool;

// inetsrv\iis\staxinc\export\dt_ctrl.h
#define TCM_GET_MODE		( WM_USER + 1803 )
#define DCM_GET_DATE		( WM_USER + 1900 )

// inetsrv\iis\staxinc\export\nntpapi.h
#define NEWS_EXPIRE_SIZE_OLDEST         (NEWS_EXPIRE_SIZE | NEWS_EXPIRE_OLDEST)
#define NEWS_EXPIRE_SIZE_BIGGEST        (NEWS_EXPIRE_SIZE | NEWS_EXPIRE_BIGGEST)
#define NEWS_EXPIRE_BOTH_OLDEST         (NEWS_EXPIRE_BOTH | NEWS_EXPIRE_OLDEST)
#define NEWS_EXPIRE_BOTH_BIGGEST        (NEWS_EXPIRE_BOTH | NEWS_EXPIRE_BIGGEST)

// inetsrv\iis\svcs\cmp\webdav\_exo\exo.cpp
#define IID_PAIR(_iid)  { (IID *) & IID_ ## _iid, #_iid }

// inetsrv\iis\svcs\cmp\webdav\inc\exo.h
#define DECLARE_GETCLSINFO(_cls)				\
		const EXOCLSINFO * GetEXOClassInfo() { return &c_exoclsinfo; }

// inetsrv\iis\svcs\ftp\server51\ftpcmd.cxx
# define UsUPL         ( UsL | UsUP)

// inetsrv\iis\svcs\ftp\server\ftpcmd.cxx
# define UsUPL         ( UsL | UsUP)

// inetsrv\iis\svcs\iissuba\md5c.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// inetsrv\iis\svcs\nntp\core\include\fixprop.h
#define ALL_BUT_NAME_AND_LEN ( 	ALL_FIX_PROPERTIES & 	\
								(~FIX_PROP_NAME) &	\
								(~FIX_PROP_NAMELEN ) )

// inetsrv\iis\svcs\nntp\server\hash\src\nntphash.h
#define     UPDATE_HEADER_STATS( ) { \
            if ( (m_nInsertions + m_nDeletions) >= STAT_FLUSH_THRESHOLD ) { \
                FlushHeaderStats( ); \
            } \
}

// inetsrv\iis\svcs\nntp\server\utest\install\main.c
# define SetServiceTypeValues( pSvcTypeValue, dwNS, dwType, dwSize, lpValName, lpVal)   \
       ( pSvcTypeValue)->dwNameSpace = ( dwNS);           \
       ( pSvcTypeValue)->dwValueType = ( dwType);         \
       ( pSvcTypeValue)->dwValueSize = ( dwSize);         \
       ( pSvcTypeValue)->lpValueName = ( lpValName);      \
       ( pSvcTypeValue)->lpValue     = (PVOID ) ( lpVal); \

// inetsrv\iis\svcs\smtp\inc\ims.h
#define I64_LI(cli) (*((__int64*)&cli))
#define LI_I64(i) (*((LARGE_INTEGER*)&i))
#define I64_FT(ft) (*((__int64*)&ft))

// inetsrv\iis\svcs\smtp\server\smtpout.cxx
#define SMTP_DUMMY_FAILURE  (0x1000 | SMTP_ACTION_ABORTED_CODE)

// inetsrv\iis\svcs\staxcore\perfapi\src\perfapii.h
#define InstanceID(iID)			(iID & 0xFFFF)

// inetsrv\iis\svcs\staxcore\setup\svc.cpp
# define SetServiceTypeValues( pSvcTypeValue, dwNS, dwType, dwSize, lpValName, lpVal)   \
       ( pSvcTypeValue)->dwNameSpace = ( dwNS);          \
       ( pSvcTypeValue)->dwValueType = ( dwType);        \
       ( pSvcTypeValue)->dwValueSize = ( dwSize);        \
       ( pSvcTypeValue)->lpValueName = ( lpValName);     \
       ( pSvcTypeValue)->lpValue     = (PVOID ) ( lpVal); \

// inetsrv\iis\svcs\w3\server\cgi.cxx
#define ISUNC(a) ((a)[0]=='\\' && (a)[1]=='\\')

// inetsrv\iis\svcs\w3\tests\httpauth\md5c.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// inetsrv\iis\svcs\wp\inc\clusapi.h
#define CLUSAPI_ALL_ACCESS (CLUSAPI_READ_ACCESS | CLUSAPI_CHANGE_ACCESS)

// inetsrv\iis\svcs\wp\inc\clusverp.h
#define VER_PRODUCTVERSION_DW       (0x01000000 | VER_PRODUCTBUILD)

// inetsrv\iis\svcs\wp\inc\wsclus.h
#define WSCLUS_IOCTL(_code)    (_WSAIO(IOC_VENDOR, (_code)) | WSVENDOR_MSFT)

// inetsrv\iis\ui\itools\keyring\algid.h
#define GET_ALG_SID(x)                  (x & (511))

// inetsrv\iis\utils\terrain\tools\ipperm\uiutils.h
#define MAKEREF(a)      ((a)|0x80000000)

// inetsrv\msmq\published\inc\mq.h
#define MQCLASS_NACK(c)     ((c) & 0x8000)
#define MQCLASS_RECEIVE(c)  ((c) & 0x4000)
#define MQCLASS_NACK_HTTP(c) (((c) & 0xA000) == 0xA000)

// inetsrv\msmq\src\ac\win95\ntddk95.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe
#define KEY_READ                ((STANDARD_RIGHTS_READ       |\
                                  KEY_QUERY_VALUE            |\
                                  KEY_ENUMERATE_SUB_KEYS     |\
                                  KEY_NOTIFY)                 \
                                  &                           \
                                 (~SYNCHRONIZE))
#define KEY_EXECUTE             ((KEY_READ)                   \
                                  &                           \
                                 (~SYNCHRONIZE))
#define OBJECT_TYPE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define SYMBOLIC_LINK_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define PROCESS_ALL_ACCESS        (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0xFFF)
#define THREAD_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0x3FF)
#define ExInitializeFastMutex(_FastMutex)                            \
    (_FastMutex)->Count = 1;                                         \
    (_FastMutex)->Contention = 0;                                    \
    KeInitializeEvent(&(_FastMutex)->Event,                          \
                      SynchronizationEvent,                          \
                      FALSE);
#define IRP_MN_MDL_DPC                  (IRP_MN_MDL | IRP_MN_DPC)
#define IoInitializeDpcRequest( DeviceObject, DpcRoutine ) (\
    KeInitializeDpc( &(DeviceObject)->Dpc,                  \
                     (PKDEFERRED_ROUTINE) (DpcRoutine),     \
                     (DeviceObject) ) )
#define IoSetCancelRoutine( Irp, NewCancelRoutine ) (  \
    (Irp)->CancelRoutine = (NewCancelRoutine) )

// inetsrv\msmq\src\apps\mqdiag\mqping\sim.h
#define Msg_PROPS(pMsgDsc)	\
	(pMsgDsc)->Props
#define Msg_CLASS(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_CLASS] ].uiVal
#define Msg_MSGID(pMsgDsc)	\
	&( (pMsgDsc)->obidMsgId )
#define Msg_CORRELATIONID(pMsgDsc)	\
	(OBJECTID *)( (pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_CORRELATIONID] ].caub.pElems )
#define Msg_PRIORITY(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_PRIORITY] ].bVal
#define Msg_DELIVERY(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_DELIVERY] ].bVal
#define Msg_ACKNOWLEDGE(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_ACKNOWLEDGE] ].bVal
#define Msg_JOURNAL(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_JOURNAL] ].bVal
#define Msg_APPSPECIFIC(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_APPSPECIFIC] ].ulVal
#define Msg_BODY(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_BODY] ].caub.pElems
#define Msg_BODY_SIZE(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_BODY_SIZE] ].ulVal
#define Msg_LABEL(pMsgDsc)	\
	(pMsgDsc)->pwcsLabel
#define Msg_LABEL_LEN(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_LABEL_LEN] ].ulVal
#define Msg_VERSION(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_VERSION] ].ulVal
#define Msg_SENDERID(pMsgDsc)	\
	(SID *)((pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_SENDERID] ].caub.pElems)
#define Msg_SENDERID_LEN(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_SENDERID_LEN] ].ulVal
#define Msg_SENDERID_TYPE(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_SENDERID_TYPE] ].ulVal
#define Msg_PRIV_LEVEL(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_PRIV_LEVEL] ].ulVal
#define Msg_AUTH_LEVEL(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_AUTH_LEVEL] ].ulVal
#define Msg_AUTHENTICATED(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_AUTHENTICATED] ].bVal
#define Msg_HASH_ALG(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_HASH_ALG] ].ulVal
#define Msg_CRYPT_ALG(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_ENCRYPTION_ALG] ].ulVal
#define Msg_SENDER_CERT_LEN(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_SENDER_CERT_LEN] ].ulVal
#define Msg_EXTENSION(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_EXTENSION] ].caub.pElems
#define Msg_EXTENSION_LEN(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_EXTENSION_LEN] ].ulVal
#define Msg_CONNECTOR_TYPE(pMsgDsc)	\
	&( (pMsgDsc)->guidProxyType )
#define Msg_BODY_TYPE(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_BODY_TYPE] ].ulVal
#define Msg_DEST_SYMM_KEY_LEN(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_DEST_SYMM_KEY_LEN] ].ulVal
#define Msg_SIGNATURE_LEN(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_SIGNATURE_LEN] ].ulVal
#define Msg_PROV_TYPE(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_PROV_TYPE] ].ulVal
#define Msg_PROV_NAME_LEN(pMsgDsc)	\
	(pMsgDsc)->PropVar[ (pMsgDsc)->iPropIndex[PROPID_M_PROV_NAME_LEN] ].ulVal
#define Msg_hEvent(pMsgDsc)	\
	(pMsgDsc)->hEvent
#define Msg_Async_hStat(pMsgDsc)	\
	(pMsgDsc)->Overlapped.Internal
#define Msg_RespQ_FormatName(pMsgDsc)	\
	(pMsgDsc->pwcsRespQ)

// inetsrv\msmq\src\apps\mqdiag\mqsock\qmutil.h
#define OS_SERVER(os)	(os == MSMQ_OS_NTS || os == MSMQ_OS_NTE)

// inetsrv\msmq\src\ds\h\dsinc.h
#define EXECUTE_EXCEPTION(type)				\
		(GetExceptionCode() == type) ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH	\

// inetsrv\msmq\src\inc\mqprops.h
#define MQCLASS_NACK(c)     ((c) & 0x8000)
#define MQCLASS_RECEIVE(c)  ((c) & 0x4000)
#define MQCLASS_NACK_HTTP(c) (((c) & 0xA000) == 0xA000)
#define MQCLASS_POS_ARRIVAL(c)  (((c) & 0xC000) == 0x0000)
#define MQCLASS_POS_RECEIVE(c)  (((c) & 0xC000) == 0x4000)
#define MQCLASS_NEG_ARRIVAL(c)  (((c) & 0xC000) == 0x8000)
#define MQCLASS_NEG_RECEIVE(c)  (((c) & 0xC000) == 0xC000)
#define MQCLASS_MATCH_ACKNOWLEDGMENT(c, a) ( \
            (((a) & MQMSG_ACKNOWLEDGMENT_POS_ARRIVAL) && MQCLASS_POS_ARRIVAL(c)) || \
            (((a) & MQMSG_ACKNOWLEDGMENT_POS_RECEIVE) && MQCLASS_POS_RECEIVE(c)) || \
            (((a) & MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL) && MQCLASS_NEG_ARRIVAL(c)) || \
            (((a) & MQMSG_ACKNOWLEDGMENT_NEG_RECEIVE) && MQCLASS_NEG_RECEIVE(c)) )

// inetsrv\msmq\src\qm\cqmgr.cpp
#define MQ_GET_ACCESS  (MQ_RECEIVE_ACCESS | MQ_PEEK_ACCESS)

// inetsrv\msmq\src\qm\qmutil.h
#define OS_SERVER(os)	(os == MSMQ_OS_NTS || os == MSMQ_OS_NTE)

// inetsrv\query\filters\html\source\htmlfilt.cxx
#define IsNoise(c) ((unsigned)(c) <= 0x20 && (c) != 0)

// inetsrv\query\filters\office\src\findfast\dmiexcel.h
#define ONE_SHEET_PER_FILE(v) (((v)==versionExcel3) || ((v)==versionExcel4))

// inetsrv\query\filters\office\src\findfast\dmifmtps.c
#define DIGIT_PLACEHOLDER(code) ((code == DIGIT0) || (code == DIGIT_NUM) || (code == DIGIT_QM))

// inetsrv\query\filters\office\src\findfast\dmixfmcp.c
	#define isalpha(x)	((x>='a' && x<='z') && !(x>='A' && x<='Z'))

// inetsrv\query\filters\office\src\findfast\dmixltyp.h
#define CELLS_SAME(x,y) \
       ((x.col == y.col) && (x.row == y.row))

// inetsrv\query\filters\office\src\findfast\dmscp.h
#define FMacCp(cp) ((cp) >= cpidMac && (cp) <= cpidMacLast)
#define FDbcsCpWin(cp) ((cp) == cpidSJIS || (cp) == cpidKSC || (cp) == cpidBIG5 || (cp) == cpidPRC)
#define FDbcsCp(cp) (FDbcsCpWin(cp) || FDbcsCpMac(cp))

// inetsrv\query\filters\office\src\findfast\dmwindos.h
#define DOS_NOT_RDONLY  (DOS_WRONLY | DOS_RDWR)

// inetsrv\query\h\ciexcpt.hxx
#define CATCH(class,e) catch( class & e )
#define AND_CATCH(class,e) catch( class & e )

// inetsrv\query\h\dynstack.hxx
#define DECL_DYNSTACK( CMyDynStack, CItem ) \
typedef CDynStack<CItem> CMyDynStack;

// inetsrv\query\h\key.hxx
#define _IsADigit(x) (((x) >= 0x30   && (x) <= 0x39)   || \
                      ((x) >= 0xb2   && (x) <= 0xb3)   || \
                      ((x) == 0xb9)                    || \
                      ((x) >= 0x660  && (x) <= 0x669)  || \
                      ((x) >= 0x6f0  && (x) <= 0x6f9)  || \
                      ((x) >= 0x966  && (x) <= 0x96f)  || \
                      ((x) >= 0x9e6  && (x) <= 0x9ef)  || \
                      ((x) >= 0xa66  && (x) <= 0xa6f)  || \
                      ((x) >= 0xae6  && (x) <= 0xaef)  || \
                      ((x) >= 0xb66  && (x) <= 0xb6f)  || \
                      ((x) >= 0xbe7  && (x) <= 0xbef)  || \
                      ((x) >= 0xbf0  && (x) <= 0xbf2)  || \
                      ((x) >= 0xc66  && (x) <= 0xc6f)  || \
                      ((x) >= 0xce6  && (x) <= 0xcef)  || \
                      ((x) >= 0xd66  && (x) <= 0xd6f)  || \
                      ((x) >= 0xe50  && (x) <= 0xe59)  || \
                      ((x) >= 0xed0  && (x) <= 0xed9)  || \
                      ((x) >= 0x1040 && (x) <= 0x1049) || \
                      ((x) == 0x2070)                  || \
                      ((x) >= 0x2074 && (x) <= 0x2079) || \
                      ((x) >= 0x2080 && (x) <= 0x2089) || \
                      ((x) >= 0xff10 && (x) <= 0xff19))

// inetsrv\query\h\proxymsg.hxx
#define IsCi64(x) ((x) & 0x10000)
#define pmCiVersion(x) ((x) & ~0x10000)

// inetsrv\query\setupqry\setupqry.hxx
#define CATCH(class,e) catch( class & e )

// net\1394\arp\sys\cfg.c
#define ASCII_TO_INT(val)       \
            ( ( ((val) >= '0') && ('9' >= (val)) ) ? ((val) - '0') :    \
              ( ((val) >= 'a') && ('z' >= (val)) ) ? ((val) - 'a' + 10) :   \
              ( ((val) >= 'A') && ('Z' >= (val)) ) ? ((val) - 'A' + 10) :   \
              0 )

// net\1394\arp\sys\md5.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// net\1394\arp\sys\priv.h
    #define ARP_IF_STAT_ADD(_pIF, StatsCounter, IncrValue)  \
                ((_pIF)->stats.StatsCounter += (IncrValue))
#define REMOTE_DEST_ETH_ADDRESS(_R) ((&(_R)->ENetAddress))

// net\1394\arp\sys\rm.h
#define RM_PARENT_OBJECT(_pObj)             \
            ((_pObj)->Hdr.pParentObject)

// net\1394\nic\sys\md5.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// net\1394\nic\sys\priv.h
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
#define nicInitializeCallRef(_pV)           nicInitializeRef (&(_pV)->Hdr.CallRef);
#define nicIncrementVcSendFailures(_Vc, _Pkt)       \
{                                                   \
    if ((_Vc)->Hdr.VcType == NIC1394_SendFIFO)      \
    {                                               \
        nicIncrementFifoSendFailures(_Vc, _Pkt);    \
    }                                               \
    else                                            \
    {                                               \
        nicIncrementChannelSendFailures(_Vc, _Pkt); \
    }                                               \
}

// net\atm\arp\atmarpc\arpcfg.c
#define ASCII_TO_INT(val)		\
			( ( ((val) >= '0') && ('9' >= (val)) ) ? ((val) - '0') :	\
			  ( ((val) >= 'a') && ('z' >= (val)) ) ? ((val) - 'a' + 10) :	\
			  ( ((val) >= 'A') && ('Z' >= (val)) ) ? ((val) - 'A' + 10) :	\
			  0 )

// net\atm\arp\atmarpc\arppkt.h
#define AA_PKT_LLC_SNAP_HEADER_OK(pH)			\
			(((pH)->LLC[0] == LLC_SNAP_LLC0) &&	\
			 ((pH)->LLC[1] == LLC_SNAP_LLC1) && \
			 ((pH)->LLC[2] == LLC_SNAP_LLC2) && \
			 ((pH)->OUI[0] == LLC_SNAP_OUI0) && \
			 ((pH)->OUI[1] == LLC_SNAP_OUI1) && \
			 ((pH)->OUI[2] == LLC_SNAP_OUI2))

// net\atm\arp\atmarps\file.h
#define	SIZE_4N(_x_)	(((_x_) + 3) & ~3)

// net\atm\arp\atmarps\intf.h
#define	COPY_ATM_ADDR(_d_, _s_)																				\
	{																										\
		(_d_)->AddressType = (_s_)->AddressType;															\
		(_d_)->NumberOfDigits = (_s_)->NumberOfDigits;														\
		COPY_MEM((_d_)->Address, (_s_)->Address, (_s_)->NumberOfDigits);									\
	}

// net\atm\epvc\sys\rm.h
#define RM_PARENT_OBJECT(_pObj)             \
            ((_pObj)->Hdr.pParentObject)

// net\atm\rawwan\sys\macros.h
#define RWAN_LINK_CONNECTION_TO_VC(_pConn, _pVc)					\
			{														\
				(_pConn)->NdisConnection.pNdisVc = _pVc;			\
				(_pConn)->pNdisVcSave = _pVc;						\
				(_pVc)->pConnObject = (_pConn);						\
			}
#define RWAN_LINK_CONNECTION_TO_VC(_pConn, _pVc)					\
			{														\
				(_pConn)->NdisConnection.pNdisVc = _pVc;			\
				(_pConn)->pNdisVcSave = _pVc;						\
				(_pVc)->pConnObject = (_pConn);						\
			}

// net\atm\rawwan\sys\rwannt.h
#define RWAN_INCR_EP_REF_CNT(_pEp, _Type)	\
		{									\
			(_pEp)->RefCount++;				\
			(_pEp)->_Type##Refs++;			\
		}
#define RWAN_DECR_EP_REF_CNT(_pEp, _Type)	\
		{									\
			(_pEp)->RefCount--;				\
			(_pEp)->_Type##Refs--;			\
		}
#define RWAN_INCR_EP_REF_CNT(_pEp, _Type)	\
			(_pEp)->RefCount++;
#define RWAN_DECR_EP_REF_CNT(_pEp, _Type)	\
			(_pEp)->RefCount--;

// net\atm\samples\atmsmpl\driver\atmsmdrv.h
#define GET_PROTO_RSVD(pPkt)    \
                    ((PPROTO_RSVD)(pPkt->ProtocolReserved))

// net\config\inc\stlxmem.h
#define _REFERENCE_X(T, A) T _FARQ &

// net\config\tools\lanacfg\lanacfg.cpp
#define NthArgIs(_i, _sz)   ((_i < argc) && (0 == _wcsicmp(argv[_i], _sz)))

// net\config\tools\ncdiag\ncdiag.cpp
#define NthArgIs(_i, _sz)   ((_i < argc) && (0 == _wcsicmp(argv[_i], _sz)))

// net\dhcp\inc\dhcp.h
#define CLASSD_NET_ADDR(a)   ((a & 0xf0) == 0xe0)
#define CLASSD_HOST_ADDR(a)  ((a & 0xf0000000) == 0xe0000000)
#define CLASSE_HOST_ADDR(a)  ((a & 0xf0000000) == 0xf0000000)
#define CLASSE_NET_ADDR(a)   ((a & 0xf0) == 0xf0)

// net\dhcp\server\dhcpds\rpcstubs.c
#define STUB_NOT_INITIALIZED(Err)  ( !StubInitialized && ((Err) = StubInitialize()))

// net\dhcp\server\exim\dbfile.c
#define CLIENT_TYPE_BOTH    ( CLIENT_TYPE_DHCP | CLIENT_TYPE_BOOTP )

// net\dhcp\server\mm\address.c
#define     SWITCHED(X)            ((X) |= 0x00000002 )
#define     DISABLED(X)            ((X) |= 0x00000001 )

// net\dhcp\server\mm\address.h
#define     SWITCHED(X)            ((X) |= 0x00000002 )
#define     DISABLED(X)            ((X) |= 0x00000001 )

// net\dhcp\server\server\dhcpdef.h
#define  DHCP_KEY_ACCESS_KEY                           (KEY_CREATE_SUB_KEY|KEY_ENUMERATE_SUB_KEYS)
#define  DHCP_KEY_ACCESS                               (DHCP_KEY_ACCESS_KEY|DHCP_KEY_ACCESS_VALUE)

// net\dhcp\server\server\dhcpreg.h
#define DHCP_IP_OVERLAP(_s_, _e_, _ips_, _ipe_ ) \
    ((((_s_ >= _ips_) && (_s_ <= _ipe_)) || \
            ((_e_ >= _ips_) && (_e_ <= _ipe_)))) || \
    ((((_ips_ >= _s_) && (_ips_ <= _e_)) || \
            ((_ipe_ >= _s_) && (_ipe_ <= _e_))))

// net\dhcp\server\server\mdhcpdb.h
#define INIT_DB_CTX( _ctx, _sessid, _tblid ) {    \
    (_ctx)->SessId = _sessid;                       \
    (_ctx)->TblId = _tblid;                       \
}

// net\dhcp\server\upgrade\db.c
#define CLIENT_TYPE_BOTH    ( CLIENT_TYPE_DHCP | CLIENT_TYPE_BOOTP )

// net\dlc\driver\llcdef.h
#define LLC_SSAP_RESPONSE       0x0001  // if (ssap & LLC_SSAP_RESP),it's a response.
#define LLC_U_INDICATOR         0x03  // (cmd & LLC_U_IND) == LLC_U_IND --> U-frame.
#define LLC_U_POLL_FINAL        0x10  // (cmd & LLC_U_PF) -> poll/final set.

// net\dlc\driver\llcmem.h
#define LINK_MEMORY_USAGE(p)        LinkMemoryUsage(&(p)->MemoryUsage)
#define UNLINK_MEMORY_USAGE(p)      UnlinkMemoryUsage(&(p)->MemoryUsage)

// net\homenet\alg\alg_icq\util.h
#define ALG_IFC_PRIVATE(_Type)  \
    ((_Type) & eALG_PRIVATE)
#define ALG_IFC_FW(_Type)       \
    ((_Type) & eALG_FIREWALLED)

// net\ias\mmc\nap\iashelper.cpp
#define HexValue(h)	\
		( ((h) >= _T('a') && (h) <= _T('f')) ? ((h) - _T('a') + 0xa) : \
		( ((h) >= _T('A') && (h) <= _T('F')) ? ((h) - _T('A') + 0xa) : \
		( ((h) >= _T('0') && (h) <= _T('9')) ? ((h) - _T('0')) : 0)))

// net\ias\mmc\nap\rapwiz.h
#define	DIALUP_PORT_CONDITION	L"MATCH(\"NAS-Port-Type=^0$|^2$|^3$|^4$\")"
#define	VPN_PORT_CONDITION	L"MATCH(\"NAS-Port-Type=^5$\")"
#define	WIRELESS_PORT_CONDITION	L"MATCH(\"NAS-Port-Type=^18$|^19$\")"
#define	SWITCH_PORT_CONDITION	L"MATCH(\"NAS-Port-Type=^15$\")"

// net\inc\icmp6.h
#define ICMPv6_INFORMATION_TYPE(type)   ((type) & 0x80)

// net\inc\nbfhdrs.h
#define DLC_SSAP_RESPONSE       0x0001  // if (ssap & DLC_SSAP_RESP), it's a response.
#define DLC_U_INDICATOR 0x03    // (cmd & DLC_U_IND) == DLC_U_IND --> U-frame.
#define DLC_U_PF        0x10    // (cmd & DLC_U_PF) -> poll/final set.
#define DLC_S_PF        0x01    // (rcvseq & DLC_S_PF) means poll/final set.
#define DLC_I_PF        0x01    // (rcvseq & DLC_I_PF) means poll/final set.
#define DLC_I_INDICATOR 0x01    // !(sndseq & DLC_I_INDICATOR) indicates I-frame.

// net\inc\pnpuverp.h
#define VER_PRODUCTVERSION_DW       (0x07020000 | VER_PRODUCTBUILD)

// net\inc\rasapip.h
#define RAS_DEVICE_TYPE(_x)     ((_x) & 0x0000FFFF)
#define RAS_DEVICE_CLASS(_x)    ((_x) & 0xFFFF0000)

// net\inc\snmpexts.h
#define ASN_PRIVATE_EOM     (ASN_PRIVATE|ASN_PRIMATIVE|0x00)
#define ASN_PRIVATE_NODE    (ASN_PRIVATE|ASN_PRIMATIVE|0x01)
#define MIB_ADDR(x)         (&(x))

// net\irda\inc\decdirda.h
#define IRLAP_GET_UCNTL(cntl)      (cntl & 0xEF)
#define IRLAP_GET_SCNTL(cntl)      (cntl & 0x0F)
#define IRLAP_FRAME_TYPE(cntl)     (cntl & 0x01 ? (cntl & 3) : 0)

// net\irda\irlap\irlapp.h
#define IRLAP_DEFAULT_DATASIZE          (DATA_SIZE_64  | DATA_SIZE_128 | \
                                         DATA_SIZE_256 | DATA_SIZE_512 | \
                                         DATA_SIZE_1024| DATA_SIZE_2048)
#define IRLAP_GET_UCNTL(cntl)       (cntl & 0xEF)
#define IRLAP_GET_SCNTL(cntl)       (cntl & 0x0F)
#define IRLAP_FRAME_TYPE(cntl)      (cntl & 0x01 ? (cntl & 3) : 0)

// net\irda\irsir\settings.h
#define GOOD_FCS ((USHORT)~0xf0b8)

// net\irda\irtranp\bftp.h
#define  Match4( pName1, pName2 )    \
             (  ((pName1)[0] == (pName2)[0]) \
             && ((pName1)[1] == (pName2)[1]) \
             && ((pName1)[2] == (pName2)[2]) \
             && ((pName1)[3] == (pName2)[3]) )

// net\irda\samples\nscirda\settings.h
#define GOOD_FCS ((USHORT) ~0xf0b8)

// net\jet500\jet\dae\inc\dbapi.h
#define FLastOpen( ppib, dbid )										\
	((ppib)->rgcdbOpen[dbid] == 1)

// net\jet500\jet\dae\inc\fmp.h
#define FDBIDWait( dbid )	 		( rgfmp[dbid].ffmp & ffmpWait )
#define DBIDSetWait( dbid )	  		( rgfmp[dbid].ffmp |= ffmpWait )
#define DBIDResetWait( dbid ) 		( rgfmp[dbid].ffmp &= ~(ffmpWait) )
#define FDBIDExclusive( dbid ) 		( rgfmp[dbid].ffmp & ffmpExclusive )
#define FDBIDExclusiveByAnotherSession( dbid, ppib )		\
				( (	FDBIDExclusive( dbid ) )				\
				&&	( rgfmp[dbid].ppib != ppib ) )
#define FDBIDExclusiveBySession( dbid, ppib )				\
				( (	FDBIDExclusive( dbid ) )				\
				&&	( rgfmp[dbid].ppib == ppib ) )
#define DBIDSetExclusive( dbid, ppib )						\
				rgfmp[dbid].ffmp |= ffmpExclusive;			\
				rgfmp[dbid].ppib = ppib;
#define DBIDResetExclusive( dbid )	( rgfmp[dbid].ffmp &= ~(ffmpExclusive) )
#define FDBIDReadOnly( dbid )		( rgfmp[dbid].ffmp & ffmpReadOnly )
#define DBIDSetReadOnly( dbid )		( rgfmp[dbid].ffmp |= ffmpReadOnly )
#define DBIDResetReadOnly( dbid )	( rgfmp[dbid].ffmp &= ~(ffmpReadOnly) )
#define FDBIDAttached( dbid )		( rgfmp[dbid].ffmp & ffmpAttached )
#define DBIDSetAttached( dbid )		( rgfmp[dbid].ffmp |= ffmpAttached )
#define DBIDResetAttached( dbid )	( rgfmp[dbid].ffmp &= ~(ffmpAttached) )
#define FDBIDExtendingDB( dbid )	( rgfmp[dbid].ffmp & ffmpExtendingDB )
#define FDBIDFlush( dbid )			( rgfmp[dbid].ffmp & ffmpFlush )
#define DBIDSetFlush( dbid )		( rgfmp[dbid].ffmp |= ffmpFlush )
#define DBIDResetFlush( dbid )		( rgfmp[dbid].ffmp &= ~(ffmpFlush) )

// net\jet500\jet\dae\inc\idb.h
#define IDBSetUnique( pidb )					( (pidb)->fidb |= fidbUnique )
#define IDBResetUnique( pidb )				( (pidb)->fidb &= ~fidbUnique )
#define FIDBUnique( pidb )						( (pidb)->fidb & fidbUnique )
#define IDBSetHasTagged( pidb )				( (pidb)->fidb |= fidbHasTagged )
#define IDBResetHasTagged( pidb )			( (pidb)->fidb &= ~fidbHasTagged )
#define FIDBHasTagged( pidb )					( (pidb)->fidb & fidbHasTagged )
#define IDBSetPrimary( pidb )					( (pidb)->fidb |= fidbPrimary )
#define IDBResetPrimary( pidb )				( (pidb)->fidb &= ~fidbPrimary )
#define FIDBPrimary( pidb )					( (pidb)->fidb & fidbPrimary )
#define IDBSetLangid( pidb )					( (pidb)->fidb |= fidbLangid )
#define IDBResetLangid( pidb )				( (pidb)->fidb &= ~fidbLangid )
#define FIDBLangid( pidb )						( (pidb)->fidb & fidbLangid )
#define IDBSetMultivalued( pidb )		  	( (pidb)->fidb |= fidbMultivalued )
#define IDBResetMultivalued( pidb )		  	( (pidb)->fidb &= ~fidbMultivalued )
#define FIDBMultivalued( pidb )			  	( (pidb)->fidb & fidbMultivalued )

// net\jet500\jet\dae\inc\node.h
#define	FNDVersion(b)	 		( (b) & fNDVersion )
#define	FNDBackLink(b)	 		( (b) & fNDBackLink )
#define	FNDSon(b)	 			( (b) & fNDSon )
#define	FNDVisibleSons(b)		( (b) & fNDVisibleSon )
#define	FNDInvisibleSons(b) 	( !( (b) & fNDVisibleSon ) )
#define	FNDFirstItem(b)		   	( (b) & fNDFirstItem )
#define	FNDLastItem(b)		   	( (b) & fNDLastItem )
#define	NDSetVersion(b) 	   	( (b) |= fNDVersion )
#define	NDResetVersion(b)	   	( (b) &= ~fNDVersion )
#define	NDSetSon(b)			   	( (b) |= fNDSon )
#define	NDResetSon(b)		   	( (b) &= ~fNDSon )
#define	NDSetVisibleSons(b)	   	( (b) |= fNDVisibleSon )
#define	NDSetInvisibleSons(b)  	( (b) &= ~fNDVisibleSon )
#define	NDSetBackLink(b)   	   	( (b) |= fNDBackLink )
#define	NDResetBackLink(b) 	   	( (b) &= ~fNDBackLink )
#define	NDSetFirstItem(b)	   	( (b) |= fNDFirstItem )
#define	NDResetFirstItem(b)	   	( (b) &= ~fNDFirstItem )
#define	NDSetLastItem(b)	   	( (b) |= fNDLastItem )
#define	NDResetLastItem(b)	   	( (b) &= ~fNDLastItem )
#define FNDItemVersion( item )		( (item) & fNDItemVersion )
#define ITEMSetVersion( item )		( (item) |= fNDItemVersion )
#define ITEMResetVersion( item )		( (item) &= ~(fNDItemVersion) )

// net\jet500\jet\dae\inc\recint.h
#define FFixedFid(fid)			((fid)<=fidFixedMost && (fid)>=fidFixedLeast)
#define FVarFid(fid)			((fid)<=fidVarMost && (fid)>=fidVarLeast)
#define FTaggedFid(fid)			((fid)<=fidTaggedMost && (fid)>=fidTaggedLeast)

// net\jet500\jet\dae\inc\stapi.h
#define FBFReadLatchConflict( ppibT, pbf )	 			\
	( (pbf)->cWriteLatch > 0 &&							\
		(pbf)->ppibWriteLatch != (ppibT) )
#define FBFWriteLatch( ppibT, pbf )						\
	((pbf)->cPin > 0 &&									\
		(pbf)->cWriteLatch > 0 &&	   					\
		(pbf)->ppibWriteLatch == (ppibT))
#define FBFWriteLatchConflict( ppibT, pbf )	 			\
	( (pbf)->cReadLatch > 0 ||							\
		( (pbf)->cWriteLatch > 0 &&						\
		(pbf)->ppibWriteLatch != (ppibT) ) )
#define PgnoOfPn( pn )						( (pn) & 0x00ffffff )

// net\jet500\jet\dae\src\buf.c
#define FBFInLRUKHeap(pbf) \
	((pbf)->ipbfHeap >= 0 && (pbf)->ipbfHeap < ipbfLRUKHeapMac)
#define FBFNotAccessible( ppib, pbf )					\
			((pbf)->fPreread ||							\
			 (pbf)->fRead ||							\
			 (pbf)->fWrite ||							\
			 (pbf)->fHold ||							\
			 (pbf)->cWaitLatch != 0 && (ppib) != (pbf)->ppibWaitLatch )
#define FBFNotAvail( pbf )								\
			((pbf)->fPreread ||							\
			 (pbf)->fRead ||							\
			 (pbf)->fWrite ||							\
			 (pbf)->fHold ||							\
			 (pbf)->cPin != 0)
#define FBFInUse(ppib, pbf)								\
			((ppib != ppibNil) ? FBFNotAccessible(ppib,pbf) : FBFNotAvail(pbf))
#define FBFInUseByOthers(ppib, pbf)											\
			((pbf)->fPreread ||												\
			 (pbf)->fRead ||												\
			 (pbf)->fWrite ||												\
			 (pbf)->fHold ||												\
			 (pbf)->cPin > 1 ||												\
			 (pbf)->cWaitLatch != 0 && (ppib) != (pbf)->ppibWaitLatch ||	\
			 (pbf)->cWriteLatch != 0 && (ppib) != (pbf)->ppibWriteLatch )

// net\jet500\jet\dae\src\ver.c
#define FNoVersionExists( prce )									\
	( PrceRCEGet( prce->dbid, prce->bm ) == prceNil )

// net\jet500\jet\jet\inc\vdbmgr.h
#define FJetDbid(dbid) (PvdbfndefOfDbid(dbid) == &vdbfndefIsam)
#define FRemoteDbid(dbid) (PvdbfndefOfDbid(dbid) == &vdbfndefRdb)

// net\jet500\xjet\inc\daedef.h
#define FFixedFid(fid)			((fid)<=fidFixedMost && (fid)>=fidFixedLeast)
#define FVarFid(fid)			((fid)<=fidVarMost && (fid)>=fidVarLeast)
#define FTaggedFid(fid)			((fid)<=fidTaggedMost && (fid)>=fidTaggedLeast)

// net\jet500\xjet\inc\dbapi.h
#define FLastOpen( ppib, dbid )										\
	((ppib)->rgcdbOpen[dbid] == 1)

// net\jet500\xjet\inc\fmp.h
#define FDBIDExclusiveByAnotherSession( dbid, ppib )		\
				( (	FDBIDExclusive( dbid ) )				\
				&&	( rgfmp[dbid].ppib != ppib ) )
#define FDBIDExclusiveBySession( dbid, ppib )				\
				( (	FDBIDExclusive( dbid ) )				\
				&&	( rgfmp[dbid].ppib == ppib ) )

// net\jet500\xjet\inc\idb.h
#define IDBSetUnique( pidb )				( (pidb)->fidb |= fidbUnique )
#define IDBResetUnique( pidb )				( (pidb)->fidb &= ~fidbUnique )
#define FIDBUnique( pidb )					( (pidb)->fidb & fidbUnique )
#define IDBSetPrimary( pidb )				( (pidb)->fidb |= fidbPrimary )
#define IDBResetPrimary( pidb )				( (pidb)->fidb &= ~fidbPrimary )
#define FIDBPrimary( pidb )					( (pidb)->fidb & fidbPrimary )
#define IDBSetLangid( pidb )				( (pidb)->fidb |= fidbLangid )
#define IDBResetLangid( pidb )				( (pidb)->fidb &= ~fidbLangid )
#define FIDBLangid( pidb )					( (pidb)->fidb & fidbLangid )
#define IDBSetMultivalued( pidb )		  	( (pidb)->fidb |= fidbMultivalued )
#define IDBResetMultivalued( pidb )		  	( (pidb)->fidb &= ~fidbMultivalued )
#define FIDBMultivalued( pidb )			  	( (pidb)->fidb & fidbMultivalued )
#define IDBSetClustered( pidb )	   			( (pidb)->fidb |= fidbClustered )
#define IDBResetClustered( pidb )			( (pidb)->fidb &= ~fidbClustered )
#define FIDBClustered( pidb )			  	( (pidb)->fidb & fidbClustered )

// net\jet500\xjet\inc\node.h
#define	FNDVersion(b)	 		( (b) & fNDVersion )
#define	FNDBackLink(b)	 		( (b) & fNDBackLink )
#define	FNDSon(b)	 			( (b) & fNDSon )
#define FNDReserved(b)			( (b) & fNDReserved )
#define	FNDVisibleSons(b)		( (b) & fNDVisibleSon )
#define	FNDInvisibleSons(b) 	( !( (b) & fNDVisibleSon ) )
#define	FNDFirstItem(b)		   	( (b) & fNDFirstItem )
#define	FNDLastItem(b)		   	( (b) & fNDLastItem )
#define	NDSetVersion(b) 	   	( (b) |= fNDVersion )
#define	NDResetVersion(b)	   	( (b) &= ~fNDVersion )
#define	NDSetSon(b)			   	( (b) |= fNDSon )
#define	NDResetSon(b)		   	( (b) &= ~fNDSon )
#define	NDSetVisibleSons(b)	   	( (b) |= fNDVisibleSon )
#define	NDSetInvisibleSons(b)  	( (b) &= ~fNDVisibleSon )
#define	NDSetBackLink(b)   	   	( (b) |= fNDBackLink )
#define	NDResetBackLink(b) 	   	( (b) &= ~fNDBackLink )
#define	NDSetFirstItem(b)	   	( (b) |= fNDFirstItem )
#define	NDResetFirstItem(b)	   	( (b) &= ~fNDFirstItem )
#define	NDSetLastItem(b)	   	( (b) |= fNDLastItem )
#define	NDResetLastItem(b)	   	( (b) &= ~fNDLastItem )
#define FNDItemVersion( item )		( (item) & fNDItemVersion )
#define ITEMSetVersion( item )		( (item) |= fNDItemVersion )
#define ITEMResetVersion( item )		( (item) &= ~(fNDItemVersion) )

// net\jet500\xjet\inc\perfdata.h
#define PerfSize( _x )			( ( _x ) &0x300 )

// net\jet500\xjet\inc\pib.h
#define PIBSetPrceNewest( ppib, prce )					\
	{													\
	(ppib)->prceNewest = (prce);						\
	}

// net\jet500\xjet\inc\spaceapi.h
#define FSPOwnedExtent( fSPExtents )	( (fSPExtents) & fSPOwnedExtent )
#define FSPAvailExtent( fSPExtents )	( (fSPExtents) & fSPAvailExtent )

// net\jet500\xjet\inc\ssib.h
#define SetupSSIB( pssibT, ppibUser )  	 	\
	{								  	 	\
	(pssibT)->pbf = pbfNil; 			 	\
	(pssibT)->ppib = ppibUser;		   	 	\
	}

// net\jet500\xjet\inc\stapi.h
#define IcritHash( ibf )	((ibf) & critBFHashConst )

// net\jet500\xjet\src\ver.c
#define FRCENoVersion( prce )										\
	( PrceRCEGet( prce->dbid, prce->bm ) == prceNil )

// net\layer2svc\zeroconf\server\rpcsrv.h
#define WZC_READ        (STANDARD_RIGHTS_READ    | WZC_ACCESS_QUERY)
#define WZC_WRITE       (STANDARD_RIGHTS_WRITE   | WZC_ACCESS_QUERY | WZC_ACCESS_SET)
#define WZC_EXECUTE     (STANDARD_RIGHTS_EXECUTE | WZC_ACCESS_QUERY)
#define WZC_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED| WZC_ACCESS_QUERY | WZC_ACCESS_SET)

// net\mmc\acssnap\gtusrdlg.h
#define USRBROWS_INCL_ALL           (USRBROWS_INCL_REMOTE_USERS |\
                                     USRBROWS_INCL_INTERACTIVE  |\
                                     USRBROWS_INCL_EVERYONE     |\
                                     USRBROWS_INCL_CREATOR      |\
                                     USRBROWS_INCL_SYSTEM)
#define USRBROWS_SHOW_ALL	    (USRBROWS_SHOW_ALIASES |\
				     USRBROWS_SHOW_GROUPS  |\
				     USRBROWS_SHOW_USERS)

// net\mmc\dialinusr\rasdial.h
#define		IF_KEY_SUPPORT_ENCRYPTION(k)	((k) != EAPTYPE_KEY_EMPTY && (k) != 0)

// net\mmc\ipxsnap\nbview.h
#define GET_IPXNB_NODEDATA(pNode) \
		(IPXConnection *) pNode->GetData(TFS_DATA_USER)

// net\mmc\ipxsnap\ripview.h
#define GET_RIP_NODEDATA(pNode) \
		(IPXConnection *) pNode->GetData(TFS_DATA_USER)

// net\mmc\ipxsnap\sapview.h
#define GET_SAP_NODEDATA(pNode) \
		(IPXConnection *) pNode->GetData(TFS_DATA_USER)

// net\mmc\ipxsnap\snview.h
#define GET_IPX_SN_NODEDATA(pNode) \
		(IPXConnection *) pNode->GetData(TFS_DATA_USER)

// net\mmc\ipxsnap\srview.h
#define GET_IPX_SR_NODEDATA(pNode) \
		(IPXConnection *) pNode->GetData(TFS_DATA_USER)

// net\mmc\ipxsnap\ssview.h
#define GET_IPX_SS_NODEDATA(pNode) \
		(IPXConnection *) pNode->GetData(TFS_DATA_USER)

// net\mmc\ipxsnap\summary.h
#define GET_IPXSUMMARY_NODEDATA(pNode) \
		(IPXConnection *) pNode->GetData(TFS_DATA_USER)

// net\mmc\mprsnap\dialin.h
#define GET_DIALINNODEDATA(pNode) \
						((DialInNodeData *) pNode->GetData(TFS_DATA_USER))

// net\mmc\mprsnap\dvsview.h
#define GET_DMVNODEDATA(pNode) \
                  ((DMVNodeData *) pNode->GetData(TFS_DATA_USER))

// net\mmc\mprsnap\ports.h
#define GET_PORTSNODEDATA(pNode) \
                        ((PortsNodeData *) pNode->GetData(TFS_DATA_USER))

// net\mmc\rtrlib\rtrui.h
#define PROTO_FROM_PROTOCOL_ID(pid)	((pid) & 0xF000FFFF )

// net\mmc\snmp\snmp_cn.h
#define IDH_5001_5112	335025033	// Customize Columns: "Move &up" (Button)
#define IDH_11705_245	16068025	// SNMP Service Configuration: "&Host name, IP or IPX Address:" (Static)
#define IDH_5001_5113	335090569	// Customize Columns: "Move &down" (Button)
#define IDH_11701_224	14691765	// Agent: "&Contact:" (Static)
#define IDH_11701_227	14888373	// Agent: "&Physical" (Button)
#define IDH_11701_228	14953909	// Agent: "Applica&tions" (Button)
#define IDH_11701_229	15019445	// Agent: "&Datalink / Subnetwork" (Button)
#define IDH_210_246	16122066	// SNMP Service Configuration: "&Host name, IP or IPX Address:" (Static)
#define IDH_11701_230	15084981	// Agent: "&Internet" (Button)
#define IDH_210_247	16187602	// SNMP Service Configuration: "&Add" (Button)
#define IDH_11701_231	15150517	// Agent: "&End-to-End" (Button)
#define IDH_11703_232	15216055	// Traps: "A&dd..." (Button)
#define IDH_30721_57670	3779491841	// New: "&Help" (Button)
#define IDH_11703_233	15281591	// Traps: "&Edit..." (Button)
#define IDH_5002_5101	334304138	// Untitled: "&Refresh" (Button)
#define IDH_5000_5101	334304136	// Untitled: "&Refresh" (Button)
#define IDH_11703_234	15347127	// Traps: "Re&move" (Button)
#define IDH_5002_5102	334369674	// Untitled: "&Columns" (Button)
#define IDH_5000_5102	334369672	// Untitled: "&Select Columns" (Button)
#define IDH_5002_5103	334435210	// Untitled: "C&lear" (Button)
#define IDH_5000_5103	334435208	// Untitled: "C&lear" (Button)

// net\mmc\tapi\gtusrdlg.h
#define USRBROWS_INCL_ALL           (USRBROWS_INCL_REMOTE_USERS |\
                                     USRBROWS_INCL_INTERACTIVE  |\
                                     USRBROWS_INCL_EVERYONE     |\
                                     USRBROWS_INCL_CREATOR      |\
                                     USRBROWS_INCL_SYSTEM)
#define USRBROWS_SHOW_ALL	    (USRBROWS_SHOW_ALIASES |\
				     USRBROWS_SHOW_GROUPS  |\
				     USRBROWS_SHOW_USERS)

// net\mmc\tfscore\tfsnode.h
#define RESULT_PANE_CHANGE_ITEM			( RESULT_PANE_CHANGE_ITEM_DATA | RESULT_PANE_CHANGE_ITEM_ICON )
#define SCOPE_PANE_CHANGE_ITEM			( SCOPE_PANE_CHANGE_ITEM_DATA | \
                                          SCOPE_PANE_CHANGE_ITEM_ICON )

// net\mmc\wins\winssnap.h
#define GETIP_FOURTH(x)            ((x)     & 0xff)

// net\ndis\samples\muxim\mux.h
#define INITIALIZE_TAG_HEADER_TO_ZERO(_pTagHeader) \
{                                                  \
     _pTagHeader->TagInfo[0] = 0;                  \
     _pTagHeader->TagInfo[1] = 0;                  \
}
#define MUX_INIT_MUTEX(_pMutex)                                 \
{                                                               \
    (_pMutex)->Counter = 0;                                     \
    (_pMutex)->ModuleAndLine = 0;                               \
}

// net\ndis\sys\protos.h
#define ndisReferenceProtocol(ProtP)    ndisReferenceRef(&(ProtP)->Ref)
#define ndisReferenceDriver(DriverP)    ndisReferenceRef(&(DriverP)->Ref)

// net\ndis\sys\sendm.h
#define MAGIC_OPEN_I(x) (PVOID)((MAGIC_OPEN & 0xFFFFFF00) + 0x00000030 + x)

// net\netbeui\sys\nbfprocs.h
#define StopTi(_Link) \
    (_Link)->Ti = 0;

// net\netbeui\sys\nbftypes.h
#define IRP_SEND_IRP(_IrpSp) \
    (((PTP_SEND_IRP_PARAMETERS)&(_IrpSp)->Parameters)->Irp)
#define IRP_RECEIVE_IRP(_IrpSp) \
    (((PTP_RECEIVE_IRP_PARAMETERS)&(_IrpSp)->Parameters)->Irp)

// net\netbt\inc\types.h
#define IF_PROXY(Node)    if ((Node) & PROXY)

// net\netbt\inc\vxdprocs.h
#define NT_SUCCESS(err)   ((err==TDI_SUCCESS)||(err==TDI_PENDING))

// net\netbt\kdext\kdextlib.c
#define    SETCALLBACKS() \
    lpOutputRoutine = lpExtensionApis->lpOutputRoutine; \
    lpGetExpressionRoutine = lpExtensionApis->lpGetExpressionRoutine; \
    lpGetSymbolRoutine = lpExtensionApis->lpGetSymbolRoutine; \
    lpReadMemoryRoutine = lpExtensionApis->lpReadVirtualMemRoutine;

// net\netbt\nbtstat\vxdonly.h
#define NT_SUCCESS(err)                 ((err==TDI_SUCCESS)||(err==TDI_PENDING))

// net\nwlink\inc\bind.h
#define NIC_HANDLE_FROM_NIC(_nichandle, _nic) \
	_nichandle.NicId = _nic; \
	_nichandle.Signature = IPX_BINDING_SIGNATURE; \
	if (_nic == 0) { \
		_nichandle.Version = 0; \
	} else { \
		_nichandle.Version = IpxDevice->Bindings[_nic].Version; \
	}

// net\nwlink\inc\ioctls.h
#define MIPX_SENTTYPE      I_MIPX | 3   /* (X) Set the xport type */
#define MIPX_SENDOPTS      I_MIPX | 6   /* (X) Send options on recv */
#define MIPX_NOSENDOPTS    I_MIPX | 7   /* (X) Don't send options on recv */
#define MIPX_SENDSRC       I_MIPX | 8   /* (X) Send source address up */
#define MIPX_NOSENDSRC     I_MIPX | 9   /* (X) Don't Send source address up */
#define MIPX_SENDDEST      I_MIPX | 15  /* (X) Send dest. address up */
#define MIPX_NOSENDDEST    I_MIPX | 16  /* (X) Don't send dest. address up */
#define MIPX_SENDFDEST     I_MIPX | 17  /* (X) Send final dest. address up */
#define MIPX_NOSENDFDEST   I_MIPX | 18  /* (X) Don't send final dest. up */
#define MIPX_SENDADDROPT   I_MIPX | 102 /* (X) Send ptype w/addr on recv */
#define MIPX_NOSENDADDROPT I_MIPX | 103 /* (X) Stop sending ptype on recv */

// net\nwlink\ipx\driver.c
#define OutputFrameType(_Binding) \
    (((_Binding)->Adapter->MacInfo.MediumType == NdisMediumArcnet878_2) ? \
         FrameTypeNames[4] : \
         FrameTypeNames[(_Binding)->FrameType])

// net\nwlink\ipx\ipxtypes.h
#define	NIC_HANDLE_TO_BINDING(_device, _nichandle) \
		NIC_ID_TO_BINDING(_device, (_nichandle)->NicId);

// net\nwlink\nb\nbiprocs.h
#define NbiStopRetransmit(_Connection) \
    (_Connection)->Retransmit = 0;
#define NbiStopWatchdog(_Connection) \
    (_Connection)->Watchdog = 0;

// net\nwlink\spx\spxpkt.h
#define		SPX_CC_CR		(SPX_CC_ACK | SPX_CC_SYS)

// net\qos\pclass\gpc\gpcdef.h
#define IPPROTO_GGP             3               /* gateway^2 (deprecated) */

// net\qos\psched\pschdprf\pschdprf.c
#define MULTIPLE_OF_EIGHT(_x)  (((_x)+7) & ~7)

// net\qos\tc\dll\tcmacro.h
#define MULTIPLE_OF_EIGHT(_x)  (((_x)+7) & ~7)

// net\rndis\rndismp\rndismp.h
#define RNDISMP_GET_MSG_FROM_FRAME(_pMsgFrame)                  \
    RNDISMP_GET_MDL_ADDRESS(_pMsgFrame->pMessageMdl)

// net\rras\ip\bootp\api.h
#define INET_NTOA(addr) inet_ntoa( *(PIN_ADDR)&(addr) )

// net\rras\ip\bootp\defs.h
#define INET_CMP(a,b,c)                                                     \
            (((c) = (((a) & 0x000000ff) - ((b) & 0x000000ff))) ? (c) :      \
            (((c) = (((a) & 0x0000ff00) - ((b) & 0x0000ff00))) ? (c) :      \
            (((c) = (((a) & 0x00ff0000) - ((b) & 0x00ff0000))) ? (c) :      \
            (((c) = (((a) & 0xff000000) - ((b) & 0xff000000))) ? (c) : (c)))))

// net\rras\ip\btpagnt\defs.h
#define ForceSetAsnInteger(dstBuf,val){                     \
    (dstBuf)->asnType = ASN_INTEGER;                        \
    (dstBuf)->asnValue.number = (AsnInteger)(val);          \
}

// net\rras\ip\fltrdrvr\match.c
#define GenericFilterMatch(uliAddr,uliPort, pFilter)                          \
        ((uliAddr).QuadPart is pFilter->uliSrcDstAddr.QuadPart) and   \
        ((uliPort).QuadPart is pFilter->uliProtoSrcDstPort.QuadPart)
#define InFilterMatch(uliAddr,uliPort, pInFilter)                          \
        ((uliAddr).QuadPart is pInFilter->uliSrcDstAddr.QuadPart) and   \
        ((uliPort).QuadPart is pInFilter->uliProtoSrcDstPort.QuadPart)
#define OutFilterMatch(uliAddr,uliPort,pOutFilter)                          \
        ((uliAddr).QuadPart is pOutFilter->uliSrcDstAddr.QuadPart) and  \
        ((uliPort).QuadPart is pOutFilter->uliProtoSrcDstPort.QuadPart)

// net\rras\ip\igmp\macros.h
#define GI_PROCESS_GRPQUERY(pite, pgie) \
    ( IF_PROCESS_GRPQUERY(pite)&& ((pgie->Version==2)||(pgie->Version==3)) )

// net\rras\ip\ipinip\ipinip.h
#define IsClassDAddr(X)     (((X) & 0x000000F0) == 0x000000E0)
#define IsClassEAddr(X)     (((X) & 0x000000F8) == 0x000000F0)

// net\rras\ip\nat\editor.h
#define EDITOR_KEY_PORT(Key)        ((USHORT)((Key) & 0x0000FFFF))

// net\rras\ip\nat\pool.h
#define PLACEHOLDER_TO_ADDRESS(a) \
    ((a) = NAT_POOL_PLACEHOLDER(a) ? (a)->SharedAddress : (a))

// net\rras\ip\nathlp\alg\algmsg.cpp
#define TOUPPER(c)      ((c) > 'z' ? (c) : ((c) < 'a' ? (c) : (c) ^ 0x20))

// net\rras\ip\nathlp\dns\dnsif.h
#define DNS_PROXY_TYPE_TO_PORT(t) \
    (USHORT)(((t) == DnsProxyDns) ? DNS_PORT_SERVER : WINS_PORT_SERVER)
#define DNS_PROXY_PORT_TO_TYPE(p) \
    (DNS_PROXY_TYPE)(((p) == DNS_PORT_SERVER) ? DnsProxyDns : DnsProxyWins)

// net\rras\ip\nathlp\ftp\ftpmsg.cpp
#define TOUPPER(c)      ((c) > 'z' ? (c) : ((c) < 'a' ? (c) : (c) ^ 0x20))

// net\rras\ip\rip\iprip.h
#define INET_NTOA(dw) inet_ntoa( *(PIN_ADDR)&(dw) )

// net\rras\ip\rip\riptest.h
#define INET_NTOA(addr) inet_ntoa( *(PIN_ADDR)&(addr) )

// net\rras\ip\ripagnt\defs.h
#define ForceSetAsnInteger(dstBuf,val){                     \
    (dstBuf)->asnType = ASN_INTEGER;                        \
    (dstBuf)->asnValue.number = (AsnInteger)(val);          \
}

// net\rras\ip\rtrmgr\defs.h
#define EXACT_MATCH(X)              ((X) & 0x00000001)

// net\rras\ip\rtrmgr\iprtrmgr.h
#define ALL_NOTIFICATIONS_RECEIVED      (NDISWAN_NOTIFICATION_RECEIVED | DDM_NOTIFICATION_RECEIVED)

// net\rras\ip\wanarp2\wanarp.h
#define IsClassDAddr(X)     (((X) & 0x000000F0) == 0x000000E0)

// net\rras\ipx\adptif\adptif.c
#define ea ((PFILE_FULL_EA_INFORMATION)&spec)
#define TaAddress ((PTA_ADDRESS)&TrAddress->Address[0])
#define IpxAddress ((PTDI_ADDRESS_IPX)&TaAddress->Address[0])

// net\rras\ipx\sap\intfdb.c
#define IntfHashFunction(intf) ((intf)&(IDB_NUM_OF_INTF_HASH_BUCKETS-1))
#define AdptHashFunction(adpt) ((adpt)&(IDB_NUM_OF_ADPT_HASH_BUCKETS-1))

// net\rras\ipx\sap\sapdefs.h
#define IpxAddrCpy(dst,src) {						\
		IpxNetCpy((dst)->Network,(src)->Network);	\
		IpxNodeCpy((dst)->Node,(src)->Node);		\
		IpxSockCpy((dst)->Socket,(src)->Socket);	\
	}
#define IpxServerCpy(dst,src) {						\
		(dst)->Type = (src)->Type;					\
		IpxNameCpy((dst)->Name,(src)->Name);		\
		IpxNetCpy((dst)->Network,(src)->Network);	\
		IpxNodeCpy((dst)->Node,(src)->Node);		\
		IpxSockCpy((dst)->Socket,(src)->Socket);	\
		(dst)->HopCount = (src)->HopCount;			\
	}

// net\rras\ipx\snmp\rtipxmib.h
#define ForceAsnInteger(dstBuf,val) {				\
	(dstBuf)->asnType = ASN_INTEGER;				\
	(dstBuf)->asnValue.number = (AsnInteger)(val);	\
	}

// net\rras\mgm\defs.h
#define INET_NTOA(dw) inet_ntoa( *(PIN_ADDR)&(dw) )

// net\rras\mgm\ipmgm.h
#define RPF_CALLBACK( p ) \
    ( *( (p)-> rpcProtocolConfig.pfnRpfCallback ) )
#define JOIN_ALERT( p ) \
        ( *( (p)-> rpcProtocolConfig.pfnJoinAlertCallback ) )
#define PRUNE_ALERT( p ) \
    ( *( (p)-> rpcProtocolConfig.pfnPruneAlertCallback ) )
#define CREATION_ALERT( p ) \
        ( *( (p)-> rpcProtocolConfig.pfnCreationAlertCallback ) )
#define IGMP_DISABLE_CALLBACK( p ) \
        ( *( (p)-> rpcProtocolConfig.pfnDisableIgmpCallback ) )
#define IGMP_ENABLE_CALLBACK( p ) \
        ( *( (p)-> rpcProtocolConfig.pfnEnableIgmpCallback ) )

// net\rras\ndis\ndiswan\vjslip.h
#define SPECIAL_I (NEW_S|NEW_W|NEW_U)        /* echoed interactive traffic */

// net\rras\ndis\ndiswan\wandefs.h
#define SEQ_LT(_a, _b, _t)  (!SEQ_EQ(_a, _b) && ((int)((_a) - (_b)) & _t))
#define SEQ_LTE(_a, _b, _t) (SEQ_EQ(_a, _b) || ((int)((_a) - (_b)) & _t))
#define SEQ_GT(_a, _b, _t)  (!SEQ_EQ(_a, _b) && !((int)((_a) - (_b)) & _t))
#define SEQ_GTE(_a, _b, _t) (SEQ_EQ(_a, _b) || !((int)((_a) - (_b)) & _t))

// net\rras\ndis\ndproxy\pxdefs.h
#define REF_ADAPTER(_pa)    \
    (_pa)->RefCount++
#define REF_VC(_pvc)    \
    (_pvc)->RefCount++
#define REF_TAPILINE(_ptl)    \
    (_ptl)->RefCount++

// net\rras\ndis\ndproxy\pxtapi.h
#define ALL_ADDRESS_MODES          (LINEADDRESSMODE_ADDRESSID        | \
                                    LINEADDRESSMODE_DIALABLEADDR)
#define ALL_BEARER_MODES           (LINEBEARERMODE_VOICE             | \
                                    LINEBEARERMODE_SPEECH            | \
                                    LINEBEARERMODE_MULTIUSE          | \
                                    LINEBEARERMODE_DATA              | \
                                    LINEBEARERMODE_ALTSPEECHDATA     | \
                                    LINEBEARERMODE_NONCALLSIGNALING  | \
                                    LINEBEARERMODE_PASSTHROUGH)
#define ALL_BUSY_MODES             (LINEBUSYMODE_STATION             | \
                                    LINEBUSYMODE_TRUNK               | \
                                    LINEBUSYMODE_UNKNOWN             | \
                                    LINEBUSYMODE_UNAVAIL)
#define ALL_DIAL_TONE_MODES        (LINEDIALTONEMODE_NORMAL          | \
                                    LINEDIALTONEMODE_SPECIAL         | \
                                    LINEDIALTONEMODE_INTERNAL        | \
                                    LINEDIALTONEMODE_EXTERNAL        | \
                                    LINEDIALTONEMODE_UNKNOWN         | \
                                    LINEDIALTONEMODE_UNAVAIL)
#define ALL_MEDIA_MODES            (LINEMEDIAMODE_UNKNOWN            | \
                                    LINEMEDIAMODE_INTERACTIVEVOICE   | \
                                    LINEMEDIAMODE_AUTOMATEDVOICE     | \
                                    LINEMEDIAMODE_DATAMODEM          | \
                                    LINEMEDIAMODE_G3FAX              | \
                                    LINEMEDIAMODE_TDD                | \
                                    LINEMEDIAMODE_G4FAX              | \
                                    LINEMEDIAMODE_DIGITALDATA        | \
                                    LINEMEDIAMODE_TELETEX            | \
                                    LINEMEDIAMODE_VIDEOTEX           | \
                                    LINEMEDIAMODE_TELEX              | \
                                    LINEMEDIAMODE_MIXED              | \
                                    LINEMEDIAMODE_ADSI               | \
                                    LINEMEDIAMODE_VOICEVIEW)
#define ALL_SPECIAL_INFO           (LINESPECIALINFO_NOCIRCUIT        | \
                                    LINESPECIALINFO_CUSTIRREG        | \
                                    LINESPECIALINFO_REORDER          | \
                                    LINESPECIALINFO_UNKNOWN          | \
                                    LINESPECIALINFO_UNAVAIL)

// net\rras\ndis\rasl2tp\l2tpp.h
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

// net\rras\ndis\rasl2tp\md5c.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// net\rras\ndis\raspti\ptiwan.h
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

// net\rras\netsh\ras\rasmontr.h
#define RASMON_CMD_ARG_Present(pArg)    \
    ((pArg)->rgTag.bPresent)
#define RASMON_CMD_ARG_GetEnum(pArg)     \
    (((pArg)->rgTag.bPresent) ? (pArg)->Val.dwValue : 0)

// net\rras\ras\ppp\auth\radius\md5.c
#define F1(x, y, z) (z ^ (x & (y ^ z)))
#define F3(x, y, z) (x ^ y ^ z)
#define F4(x, y, z) (y ^ (x | ~z))

// net\rras\ras\ppp\rasiphlp\rasiphlp_.h
#define CLASSA_HBO_ADDR(a)          (((a) & 0x80000000) == 0)
#define CLASSB_HBO_ADDR(a)          (((a) & 0xc0000000) == 0x80000000)
#define CLASSC_HBO_ADDR(a)          (((a) & 0xe0000000) == 0xc0000000)

// net\rras\ras\rasman\mxs32\mxspriv.h
#define  ATTRIBCPY(DEST,SRC)  (((ATTRIB_ENABLED)&(SRC))?\
                               ((DEST)|=(ATTRIB_ENABLED)):\
                               ((DEST)&=(~ATTRIB_ENABLED)))
#define  XOR(A,B)  (((A)||(B))&&!((A)&&(B)))
#define  ISUNARYMACRO(P) (!((ATTRIB_VARIABLE|ATTRIB_BINARYMACRO)&(P)))

// net\rras\ras\ui\inc\bpopup.h
#define BPM_FIRST           (WM_USER + 1)

// net\rras\ras\ui\inc\pbk.h
#define AR_F_AuthAnyMSCHAP (AR_F_AuthMSCHAP | AR_F_AuthW95MSCHAP | AR_F_AuthMSCHAP2)
#define AR_F_AuthNoMPPE    (AR_F_AuthPAP | AR_F_AuthSPAP | AR_F_AuthMD5CHAP)

// net\rras\ras\ui\nt4\inc\bpopup.h
#define BPM_FIRST           (WM_USER + 1)

// net\rras\ras\ui\rasscrpt\ast.h
#define Expr_GetRes(p)              (&((PEXPR)(p))->er)

// net\rras\ras\ui\rasscrpt\mem.c
#define IsSA(psa) ((psa) && (psa)->magic == SA_MAGIC)
#define IsPA(ppa) ((ppa) && (ppa)->magic == PA_MAGIC)

// net\rras\ras\ui\rassrvui\ipxui.c
#define isBetween(b,a,c) ((b >= a) && (b <= c))

// net\rras\ras\ui\rassrvui\userdb.c
#define usrDirtyRasProps(pUser) ((pUser)->bDirty |= USR_RASPROPS_DIRTY)
#define usrDirtyFullname(pUser) ((pUser)->bDirty |= USR_FULLNAME_DIRTY)
#define usrDirtyAdd(pUser) ((pUser)->bDirty |= USR_ADD_DIRTY)
#define usrIsRasPropsDirty(pUser) ((pUser)->bDirty & USR_RASPROPS_DIRTY)
#define usrIsFullNameDirty(pUser) ((pUser)->bDirty & USR_FULLNAME_DIRTY)
#define usrIsAddDirty(pUser) ((pUser)->bDirty & USR_ADD_DIRTY)
#define usrClearRasPropsDirty(pUser) ((pUser)->bDirty &= ~USR_CALLBACK_DIRTY)
#define usrClearFullNameDirty(pUser) ((pUser)->bDirty &= ~USR_FULLNAME_DIRTY)
#define usrClearAddDirty(pUser) ((pUser)->bDirty &= ~USR_ADD_DIRTY)

// net\rras\rtm\rtmdlg.h
#define RT_ADDROUTE		(WM_USER+10)
#define RT_UPDATEROUTE	(WM_USER+11)

// net\rras\rtmv2\apitest.h
#define BHalf(B)        (B) & 0xF
#define    STARTPROF    QueryPerformanceCounter(&PCStart);
#define    STOPPROF     QueryPerformanceCounter(&PCStop);

// net\rras\rtmv2\lkuptst.h
#define BHalf(B)        (B) & 0xF
#define    STARTPROF    QueryPerformanceCounter(&PCStart);
#define    STOPPROF     QueryPerformanceCounter(&PCStop);

// net\rras\rtmv2\rtm1to2.h
#define V1GetRouteNetwork(Route, ProtocolFamily, Network)                   \
        if (ProtocolFamily == RTM_PROTOCOL_FAMILY_IP)                       \
        {                                                                   \
            (*Network) = (PVOID) &((PRTM_IP_ROUTE)  Route)->RR_Network;     \
        }                                                                   \
        else                                                                \
        {                                                                   \
            (*Network) = (PVOID) &((PRTM_IPX_ROUTE) Route)->RR_Network;     \
        }                                                                   \

// net\rras\rtmv2\rtmenum.h
#define GET_ENUM_TYPE(EnumHandle, Enum)                                      \
  (                                                                          \
      *Enum = (POPEN_HEADER) GetObjectFromHandle(EnumHandle, GENERIC_TYPE),  \
      (*Enum)->HandleType                                                    \
  )

// net\rras\rtmv2\rtmmain.h
#define INITIALIZE_INSTANCE_REFERENCE(Instance, RefType)                    \
            InitializeObjectReference(&Instance->ObjectHeader, RefType);
#define REFERENCE_INSTANCE(Instance, RefType)                               \
            ReferenceObject(&Instance->ObjectHeader, RefType);
#define INITIALIZE_ADDR_FAMILY_REFERENCE(Instance, RefType)                 \
            InitializeObjectReference(&Instance->ObjectHeader, RefType);
#define REFERENCE_ADDR_FAMILY(AddrFamilyInfo, RefType)                      \
            ReferenceObject(&AddrFamilyInfo->ObjectHeader, RefType);
#define INITIALIZE_ENTITY_REFERENCE(Entity, RefType)                        \
            InitializeObjectReference(&Entity->ObjectHeader, RefType);
#define REFERENCE_ENTITY(Entity, RefType)                                   \
            ReferenceObject(&Entity->ObjectHeader, RefType);
#define INITIALIZE_DEST_REFERENCE(Dest, RefType)                            \
            InitializeObjectReference(&(Dest)->ObjectHeader, RefType);
#define REFERENCE_DEST(Dest, RefType)                                       \
            ReferenceObject(&(Dest)->ObjectHeader, RefType);
#define INITIALIZE_ROUTE_REFERENCE(Route, RefType)                          \
            InitializeObjectReference(&(Route)->ObjectHeader, RefType);
#define REFERENCE_ROUTE(Route, RefType)                                     \
            ReferenceObject(&(Route)->ObjectHeader, RefType);

// net\sfm\afp\server\access.h
#define	AFP_OWNER_ACCESS	(WRITE_DAC			  | \
							 WRITE_OWNER)

// net\sfm\afp\server\atalkio.h
#define	afpInitializeActionHdr(p, Code)	\
		(p)->ActionHeader.TransportId = MATK;	\
		(p)->ActionHeader.ActionCode = (Code)

// net\sfm\afp\server\fdparm.h
#define	DIR_ACCESS_ALL				(DIR_ACCESS_READ	| \
									 DIR_ACCESS_SEARCH	| \
									 DIR_ACCESS_WRITE)

// net\sfm\afp\server\fileio.h
#define FILEIO_ACCESS_NONE					(FILE_READ_ATTRIBUTES			|\
											 SYNCHRONIZE)
#define FILEIO_ACCESS_READ					(GENERIC_READ					|\
											 SYNCHRONIZE)
#define FILEIO_ACCESS_WRITE					(GENERIC_WRITE					|\
											 SYNCHRONIZE)
#define FILEIO_ACCESS_READWRITE				(FILEIO_ACCESS_READ				|\
											 FILEIO_ACCESS_WRITE)

// net\sfm\afp\server\idindex.h
#define	HASH_CACHE_ID(Id)				((Id) & (IDINDEX_CACHE_ENTRIES-1))
#define	ASIZE_TO_INDEX(_Size)												\
		(((_Size) <= DFE_SIZE_TINY) ? DFE_INDEX_TINY :						\
						(((_Size) <= DFE_SIZE_SMALL) ? DFE_INDEX_SMALL :	\
						 (((_Size) <= DFE_SIZE_MEDIUM) ? DFE_INDEX_MEDIUM : DFE_INDEX_LARGE)))
#define	USIZE_TO_INDEX(_Size)												\
		(((_Size) <= DFE_SIZE_TINY_U) ? DFE_INDEX_TINY :					\
						(((_Size) <= DFE_SIZE_SMALL_U) ? DFE_INDEX_SMALL :	\
						 (((_Size) <= DFE_SIZE_MEDIUM_U) ? DFE_INDEX_MEDIUM : DFE_INDEX_LARGE)))

// net\sfm\afp\server\sda.h
#define	SDA_SIZE				(((768 - POOL_OVERHEAD)+7) & 0xfffffff8)
#define	SDA_SIZE				(((450 - POOL_OVERHEAD)+7) & 0xfffffff8)

// net\sfm\afp\server\swmr.h
#define SWMR_SOMEONE_WAITING( _pSwmr ) ((_pSwmr)->swmr_cExclWaiting || \
                                        (_pSwmr)->swmr_cSharedWaiting)

// net\sfm\afp\server\volume.h
#define	AfpDtHdrToVolDesc(_pDtHdr, _pVolDesc)							\
	{																	\
		(_pVolDesc)->vds_cApplEnts = (_pDtHdr)->dtp_cApplEnts;			\
		(_pVolDesc)->vds_cIconEnts = (_pDtHdr)->dtp_cIconEnts;			\
	}
#define	AfpVolDescToDtHdr(_pVolDesc, _pDtHdr)							\
	{																	\
		(_pDtHdr)->dtp_Signature = AFP_SERVER_SIGNATURE;				\
		(_pDtHdr)->dtp_Version = AFP_DESKTOP_VERSION;					\
		(_pDtHdr)->dtp_cApplEnts = (_pVolDesc)->vds_cApplEnts;			\
		(_pDtHdr)->dtp_cIconEnts = (_pVolDesc)->vds_cIconEnts;			\
	}

// net\sfm\atalk\sys\arap.h
#define LT_GREATER_THAN(_a,_b,_result)                  \
{                                                       \
    if ( (_a) >= 248 && (_b) >= 0 && (_b) < 8 )         \
    {                                                   \
        _result = FALSE;                                \
    }                                                   \
    else if ( (_a) >= 0  && (_a) < 8 && (_b) >= 248 )   \
    {                                                   \
        _result = TRUE;                                 \
    }                                                   \
    else                                                \
    {                                                   \
        _result = ((_a) > (_b));                        \
    }                                                   \
}

// net\sfm\atalk\sys\atkndis.h
#define AtalkNdisBuildARAPHdr(_pLnkHdr, _pConn)             \
    RtlCopyMemory(_pLnkHdr, _pConn->NdiswanHeader, WAN_LINKHDR_LEN)
#define AtalkNdisBuildPPPPHdr(_pLnkHdr, _pConn)             \
    RtlCopyMemory(_pLnkHdr, _pConn->NdiswanHeader, WAN_LINKHDR_LEN)

// net\sfm\atalk\sys\atktypes.h
#define	NODEADDR_EQUAL(NodeAddr1, NodeAddr2)	\
				(((NodeAddr1)->atn_Network == (NodeAddr2)->atn_Network) &&	\
				 ((NodeAddr1)->atn_Node == (NodeAddr2)->atn_Node))

// net\sfm\atalk\sys\atkutils.h
#define	ATALK_NODES_EQUAL(N1, N2)												\
				((((N1)->atn_Network == (N2)->atn_Network) ||					\
				  ((N1)->atn_Network == 0) ||									\
				  ((N2)->atn_Network == 0)) &&									\
				 ((N1)->atn_Node == (N2)->atn_Node))
#define	ATALK_ADDRS_EQUAL(A1, A2)												\
				((((A1)->ata_Network == (A2)->ata_Network) ||					\
				  ((A1)->ata_Network == 0) ||									\
				  ((A2)->ata_Network == 0)) &&									\
				 ((A1)->ata_Node == (A2)->ata_Node) &&							\
				 ((A1)->ata_Socket == (A2)->ata_Socket))

// net\sfm\atalk\winsock\wshatalk.h
#define	TDI_TO_SOCK_ATALKADDR(sockAddr, tdiAddr)				\
		{																		\
			(sockAddr)->sat_family	= AF_APPLETALK;								\
			(sockAddr)->sat_net		= (tdiAddr)->Address[0].Address[0].Network;	\
			(sockAddr)->sat_node	= (tdiAddr)->Address[0].Address[0].Node;	\
			(sockAddr)->sat_socket	= (tdiAddr)->Address[0].Address[0].Socket;	\
		}

// net\sfm\setup\util\access.c
#define	AFP_OWNER_ACCESS	(WRITE_DAC			  | \
							 WRITE_OWNER)

// net\snmp\subagent\snmpevnt\evntwin\settings.cpp
#define BOOLS_ARE_DIFFERENT(b1, b2) ((b1 & !b2) || (!b1 & b2))

// net\sockets\winsock2\inc\resolve.h
#define RES_DEFAULT (RES_RECURSE | RES_DEFNAMES | RES_DNSRCH)

// net\sockets\winsock2\util\sporder\dll\dllmain.c
#define GUIDEQUAL(Guid1, Guid2)                     \
       ( (Guid1)->Data1 == (Guid2)->Data1 &&        \
         (Guid1)->Data2 == (Guid2)->Data2 &&        \
         (Guid1)->Data3 == (Guid2)->Data3 &&        \
         (Guid1)->Data4[0] == (Guid2)->Data4[0] &&  \
         (Guid1)->Data4[1] == (Guid2)->Data4[1] &&  \
         (Guid1)->Data4[2] == (Guid2)->Data4[2] &&  \
         (Guid1)->Data4[3] == (Guid2)->Data4[3] &&  \
         (Guid1)->Data4[4] == (Guid2)->Data4[4] &&  \
         (Guid1)->Data4[5] == (Guid2)->Data4[5] &&  \
         (Guid1)->Data4[6] == (Guid2)->Data4[6] &&  \
         (Guid1)->Data4[7] == (Guid2)->Data4[7] )

// net\sockets\winsock2\ws2_32\inc\dthook.h
#define PREAPINOTIFY(x) \
    ( GetPreApiNotifyFP()  ? ( (*(GetPreApiNotifyFP())) x ) : FALSE)

// net\sockets\winsock2\wsp\afdsys\afdp.h
#define TDI_RECEIVE_EITHER ( TDI_RECEIVE_NORMAL | TDI_RECEIVE_EXPEDITED )

// net\sockets\winsock2\wsp\afdsys\afdprocs.h
#define AfdIndicatePollEvent(_e,_m,_s)  \
    ((_e)->PollCalled ? (AfdIndicatePollEventReal((_e),(_m),(_s)), TRUE) : FALSE)

// net\sockets\winsock2\wsp\afdsys\kdext\cons.h
#define UC(x)               ((UINT)((x) & 0xFF))

// net\tapi\inc\msrtp.h
#define RTPTTL_RTPRTCP           (RTPTTL_RTP | RTPTTL_RTCP)

// net\tapi\litesabr\filters\amrtpnet\session.cpp
#define SOCKET_ISRXTX (SOCKET_ISRX | SOCKET_ISTX)

// net\tapi\litesabr\filters\amrtpnet\socket.cpp
#define SOCKET_ISRXTX (SOCKET_ISRX | SOCKET_ISTX)

// net\tapi\litesabr\filters\amrtpnet\template.h
#define CFT_AMRTPNET_RTP_RENDER_FILT_PROP \
{ \
	  RTP_RENDER_FILTER, \
	  &CLSID_RTPRenderFilterProperties, \
	  CRtpRenderFilterProperties::CreateInstance, \
	  }

// net\tapi\litesabr\filters\amrtpss\template.h
#define CFT_AMRTPSS_SILENCE_SUPRESSOR_PROP \
{ \
	  AMRTP_SILENCE_SUPRESSOR_PROP, \
	  &CLSID_SilenceSuppressionProperties, \
	  CSilenceProperties::CreateInstance \
	  }

// net\tapi\litesabr\filters\rrcm\md5\md5c.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// net\tapi\litesabr\filters\rrcm\md5\md5c_opt.c
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// net\tapi\rtc\phoenix\src\media\test\join.cpp
#define PRIV_EVENTID (WM_USER+123)

// net\tapi\rtc\phoenix\src\sip\siputil.cpp
#define IsReserved( x )         (   ((x) == '@') || \
                                    ((x) == '$') || \
                                    ((x) == '%') || \
                                    ((x) == '&') || \
                                    ((x) == '=') || \
                                    ((x) == ',') || \
                                    ((x) == '?') || \
                                    ((x) == '/') || \
                                    ((x) == '@') || \
                                    ((x) == '^')    \
                                )

// net\tapi\server\line.c
        #define AllGatherDigitsModes (LINEDIGITMODE_PULSE | LINEDIGITMODE_DTMF)

// net\tapi\skywalker\apps\avdialer\avdialer\pergrplst.h
#define PERSONGROUPVIEWMSG_LBUTTONDBLCLK  (WM_USER + 1020)

// net\tapi\skywalker\apps\avdialer\avmeter\tmeter.h
#define TMM_GETLEVEL			(WM_USER + 100)
#define TMM_SETLEVEL			(WM_USER + 101)

// net\tapi\skywalker\apps\avdialer\avtapi\avtapi.h
#define LINEADDRESSTYPE_NETCALLS ~(LINEADDRESSTYPE_SDP | LINEADDRESSTYPE_PHONENUMBER)

// net\tapi\skywalker\cc\callcont\ccmain.h
#define ALL_CHANNELS		(TX_CHANNEL | RX_CHANNEL | TXRX_CHANNEL | PROXY_CHANNEL)

// net\tapi\skywalker\cc\callcont\confman.h
#define ALL_CALLS			(REAL_CALLS | VIRTUAL_CALL)

// net\tapi\skywalker\cc\h245ws\h245ws.cpp
#define WINSOCK_EVENT_MSG (WM_USER+1)

// net\tapi\skywalker\cc\inc\linkapi.h
#define DATALINK_TRANSMIT_ALL (DATALINK_TRANSMIT | DATALINK_TX_ACTIVES)

// net\tapi\skywalker\conftsp\conftsp.h
#define IPCONF_MEDIAMODES (LINEMEDIAMODE_INTERACTIVEVOICE | \
                          LINEMEDIAMODE_AUTOMATEDVOICE | \
                          LINEMEDIAMODE_VIDEO | \
                          LINEMEDIAMODE_UNKNOWN)
#define IPCONF_BEARERMODES (LINEBEARERMODE_DATA | LINEBEARERMODE_VOICE)

// net\tapi\skywalker\filters\rtp\inc\rtppinfo.h
#define RTPUSER_GET_OFF(_ctrl)    ((_ctrl) & 0x3ff)

// net\tapi\skywalker\filters\rtp\msrtp\funcs\rtpqos.c
#define QOS_EXTRA1(_pQosInfo)   \
        (((_pQosInfo)->dwQosExtraInfo) & 0x1f)

// net\tapi\skywalker\filters\video\tapivcap\video.c
#define DATAFROMHANDLE(h) &g_tv

// net\tapi\skywalker\h323\tsp\line.h
#define H323_LINE_BEARERMODES      (LINEBEARERMODE_DATA | \
                                    LINEBEARERMODE_VOICE)
#define H323_LINE_MEDIAMODES       (H323_LINE_DEFMEDIAMODES | \
                                    LINEMEDIAMODE_INTERACTIVEVOICE | \
                                    LINEMEDIAMODE_VIDEO)
#define H323_LINE_LINEFEATURES     (LINEFEATURE_MAKECALL    | \
                                    LINEFEATURE_FORWARD     | \
                                    LINEFEATURE_FORWARDFWD )
#define H323_ADDR_ADDRFEATURES      (LINEADDRFEATURE_MAKECALL | LINEADDRFEATURE_FORWARD)
#define H323_ADDR_DISCONNECTMODES  (LINEDISCONNECTMODE_BADADDRESS | \
                                    LINEDISCONNECTMODE_BUSY | \
                                    LINEDISCONNECTMODE_NOANSWER | \
                                    LINEDISCONNECTMODE_NORMAL | \
                                    LINEDISCONNECTMODE_REJECT | \
                                    LINEDISCONNECTMODE_UNAVAIL)
#define	g_pH323Line		(&g_H323Line)

// net\tapi\skywalker\h323tsp\call.h
#define H323IsCallEqual(_pCall_,_hdCall_) \
    (H323IsCallInUse(_pCall_) && \
     ((_pCall_)->hdCall == (_hdCall_)))
#define H323IsVideoRequested(_pCall_) \
    ((_pCall_)->dwRequestedModes & LINEMEDIAMODE_VIDEO)
#define H323IsAutomatedVoiceRequested(_pCall_) \
     ((_pCall_)->dwRequestedModes & LINEMEDIAMODE_AUTOMATEDVOICE)
#define H323IsInteractiveVoiceRequested(_pCall_) \
     ((_pCall_)->dwRequestedModes & LINEMEDIAMODE_INTERACTIVEVOICE)
#define H323IsMediaUnresolved(_pCall_) \
    ((_pCall_)->dwOutgoingModes & LINEMEDIAMODE_UNKNOWN)
#define H323IsAudioRequested(_pCall_) \
    (H323IsAutomatedVoiceRequested(_pCall_) || \
     H323IsInteractiveVoiceRequested(_pCall_))

// net\tapi\skywalker\h323tsp\callback.h
#define H323_MSG_PLACE_CALL     (WM_USER+10)
#define H323_MSG_ACCEPT_CALL    (WM_USER+11)
#define H323_MSG_DROP_CALL      (WM_USER+13)
#define H323IsPlaceCallMessage(_msg_) \
    ((_msg_)->message == H323_MSG_PLACE_CALL)
#define H323IsAcceptCallMessage(_msg_) \
    ((_msg_)->message == H323_MSG_ACCEPT_CALL)
#define H323IsDropCallMessage(_msg_) \
    ((_msg_)->message == H323_MSG_DROP_CALL)

// net\tapi\skywalker\h323tsp\channel.h
#define H323IsChannelEqual(_pChannel_,_hccChannel_) \
    (H323IsChannelInUse(_pChannel_) && \
     ((_hccChannel_) == ((_pChannel_)->hccChannel)))
#define H323IsSessionIDEqual(_pChannel_,_bSessionID_) \
    (H323IsChannelInUse(_pChannel_) && \
     ((_bSessionID_) == ((_pChannel_)->bSessionID)))

// net\tapi\skywalker\h323tsp\line.h
#define H323_LINE_BEARERMODES      (LINEBEARERMODE_DATA | \
                                    LINEBEARERMODE_VOICE)
#define H323_LINE_MEDIAMODES       (H323_LINE_DEFMEDIAMODES | \
                                    LINEMEDIAMODE_INTERACTIVEVOICE | \
                                    LINEMEDIAMODE_VIDEO)
#define H323_ADDR_DISCONNECTMODES  (LINEDISCONNECTMODE_BADADDRESS | \
                                    LINEDISCONNECTMODE_BUSY | \
                                    LINEDISCONNECTMODE_NOANSWER | \
                                    LINEDISCONNECTMODE_NORMAL | \
                                    LINEDISCONNECTMODE_REJECT | \
                                    LINEDISCONNECTMODE_UNAVAIL)
#define H323IsLineEqual(_pLine_,_hdLine_) \
    (H323IsLineInUse(_pLine_) && \
     ((_pLine_)->hdLine == (_hdLine_)))
#define H323IsMediaDetectionEnabled(_pLine_) \
    (((_pLine_)->dwMediaModes != 0) && \
     ((_pLine_)->dwMediaModes != LINEMEDIAMODE_UNKNOWN))
#define H323IsVideoDetectionEnabled(_pLine_) \
    ((_pLine_)->dwMediaModes & LINEMEDIAMODE_VIDEO)
#define H323IsAudioDetectionEnabled(_pLine_) \
    (H323IsVideoDetectionEnabled(_pLine_) || \
     ((_pLine_)->dwMediaModes & LINEMEDIAMODE_AUTOMATEDVOICE) || \
     ((_pLine_)->dwMediaModes & LINEMEDIAMODE_INTERACTIVEVOICE))

// net\tapi\skywalker\h323tsp\termcaps.h
#define H323IsReceiveCapability(_dir_) \
    (((_dir_) == H245_CAPDIR_LCLRXTX) || \
     ((_dir_) == H245_CAPDIR_RMTRXTX) || \
     ((_dir_) == H245_CAPDIR_LCLRX) || \
     ((_dir_) == H245_CAPDIR_RMTRX))
#define DEFINE_VENDORINFO(_ID_,_VERSION_) \
    { \
        H221_COUNTRY_CODE_USA, \
        H221_COUNTRY_EXT_USA, \
        H221_MFG_CODE_MICROSOFT, \
        &(_ID_), \
        &(_VERSION_) \
    }

// net\tapi\skywalker\ipconf\tsp\conftsp.h
#define IPCONF_MEDIAMODES (LINEMEDIAMODE_INTERACTIVEVOICE | \
                          LINEMEDIAMODE_AUTOMATEDVOICE | \
                          LINEMEDIAMODE_VIDEO | \
                          LINEMEDIAMODE_UNKNOWN)
#define IPCONF_BEARERMODES (LINEBEARERMODE_DATA | LINEBEARERMODE_VOICE)

// net\tapi\skywalker\rend\rndcnf.cpp
#define ACCESS_MODIFY   (ACCESS_WRITE | WRITE_DAC)

// net\tapi\skywalker\rend\rnduser.cpp
#define ACCESS_MODIFY   (ACCESS_WRITE | WRITE_DAC)

// net\tapi\skywalker\tapi3\address.h
#define FORWARDMODENEEDSCALLER(__dwMode__) \
( ( LINEFORWARDMODE_UNCONDSPECIFIC | LINEFORWARDMODE_BUSYSPECIFIC | \
    LINEFORWARDMODE_NOANSWSPECIFIC | LINEFORWARDMODE_BUSYNASPECIFIC ) & \
    (__dwMode__) )

// net\tcpip\driver\ipv4\trie.h
#define    MATCH_FULL                 (MATCH_NHOP|MATCH_INTF)

// net\tcpip\driver\kdext\tcpipext.h
#define EOL (( ppchTempEol = ppchCurrentEol ), ( ppchCurrentEol = &pchEol ), ( *ppchTempEol ))

// net\tcpip\driver\tcp\tcpconn.h
#define CONN_INDEX(c)       ((c) & 0xff)

// net\tcpip\services\rip\route.h
#define RTHASHMOD(h)	((h) & (RTHASHSIZ - 1))

// net\tcpip\services\telnet\client\wintel.h
#define SV_PROGRESS                     (WM_USER+350)
#define SV_END                          (WM_USER+351)
#define ALT_PRESSED (LEFT_ALT_PRESSED | RIGHT_ALT_PRESSED)
#define CTRL_PRESSED (LEFT_CTRL_PRESSED | RIGHT_CTRL_PRESSED)

// net\tcpip\services\telnet\server\tlntsess\rfcproto.cpp
#define INCREMENT_COLS( cols, inc ) \
        { \
            cols += inc;\
            if( cols >= m_pSession->CSession::m_wCols ) \
            {\
                cols = 0;\
            }\
        }

// net\tcpip\services\telnet\server\tlntsvr\telnetd.h
#define DO_AUTH_SUB_NE_NTLM(p)  {\
            p[0] = TC_IAC;\
            p[1] = TC_SB;\
            p[2] = TO_AUTH;\
            p[3] = AU_SEND;\
            p[4] = AUTH_TYPE_NTLM;\
            p[5] = AUTH_CLIENT_TO_SERVER | AUTH_HOW_ONE_WAY; \
            p[6] = TC_IAC;\
            p[7] = TC_SE; }

// net\tcpip\snmp\defs.h
#define ForceSetAsnInteger(dstBuf,val){                     \
    (dstBuf)->asnType = ASN_INTEGER;                        \
    (dstBuf)->asnValue.number = (AsnInteger)(val);          \
}

// net\tcpip\tpipv6\dplayip6\dpsp.h
#define DGRAM_PSOCKADDR(ppd) ((SOCKADDR_IN6 *)&(((LPSPPLAYERDATA)ppd)->saddrDatagram))

// net\tcpip\tpipv6\tcpip6\inc\tcpconn.h
#define CONN_INDEX(c)       ((c) & 0xff)

// net\unimodem\lights\lights.h
#define MMWM_NOTIFYICON                 (WM_USER + 101)

// net\upnp\host\upnphost\inc\servutil.h
#define MyOpenAppendFile(path)     CreateFile(path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0)

// net\upnp\host\upnphost\inc\winioctl.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// net\upnp\host\upnphost\udhhttp\parser.cpp
#define PFNPARSE(x) &(CHttpRequest::Parse##x)

// net\upnp\upnpui\inc\stlxmem.h
#define _REFERENCE_X(T, A) T _FARQ &

// net\winnet\mprdata.h
#define CREDENTIAL_TYPE     (WN_CREDENTIAL_CLASS | WN_PRIMARY_AUTHENT_CLASS)

// net\wins\mib\winsmib.c
#define PARAMETERS_VAL_M(pMib)                (  \
                ((pMib)->Oid.ids[0] == 1)  \
                        &&                   \
                ((pMib)->Oid.ids[1] >= 19) \
                        &&                   \
                ((pMib)->Oid.ids[1] <= 31) \
                                )

// net\wins\server\msc\winsevt.c
#define get_month_m(month_int)		\
       (((month_int) == 0)  ? "JAN" :	\
	((month_int) == 1)  ? "FEB" :	\
	((month_int) == 2)  ? "MAR" :	\
	((month_int) == 3)  ? "APR" :	\
	((month_int) == 4)  ? "MAY" :	\
	((month_int) == 5)  ? "JUN" :	\
	((month_int) == 6)  ? "JUL" :	\
	((month_int) == 7)  ? "AUG" :	\
	((month_int) == 8)  ? "SEP" :	\
	((month_int) == 9)  ? "OCT" :	\
	((month_int) == 10) ? "NOV" : "DEC" \
	)

// public\ddk\inc\d4drvif.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// public\ddk\inc\devioctl.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// public\ddk\inc\nt_vdd.h
#define getMODE() ((getMSW() & MSW_PE) ? VDM_PM : VDM_V86)

// public\ddk\inc\ntdd8042.h
#define I8042_SYS_BUTTONS  (I8042_POWER_SYS_BUTTON | \
                            I8042_SLEEP_SYS_BUTTON | \
                            I8042_WAKE_SYS_BUTTON)

// public\ddk\inc\ntdddisk.h
#define IsRecognizedPartition( PartitionType ) (    \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT_12)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_IFS)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_HUGE)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT32)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT32_XINT13)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_XINT13)) ||  \
     ((PartitionType) == PARTITION_FAT_12)          ||  \
     ((PartitionType) == PARTITION_FAT_16)          ||  \
     ((PartitionType) == PARTITION_IFS)             ||  \
     ((PartitionType) == PARTITION_HUGE)            ||  \
     ((PartitionType) == PARTITION_FAT32)           ||  \
     ((PartitionType) == PARTITION_FAT32_XINT13)    ||  \
     ((PartitionType) == PARTITION_XINT13) )
#define IsFTPartition( PartitionType ) \
    (((PartitionType)&PARTITION_NTFT) && IsRecognizedPartition(PartitionType))

// public\ddk\inc\ntddk.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe
#define FILE_READ_DATA            ( 0x0001 )    // file & pipe
#define FILE_WRITE_DATA           ( 0x0002 )    // file & pipe
#define FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
                                   FILE_READ_DATA           |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_READ_EA             |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
                                   FILE_WRITE_DATA          |\
                                   FILE_WRITE_ATTRIBUTES    |\
                                   FILE_WRITE_EA            |\
                                   FILE_APPEND_DATA         |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_EXECUTE             |\
                                   SYNCHRONIZE)
#define KEY_READ                ((STANDARD_RIGHTS_READ       |\
                                  KEY_QUERY_VALUE            |\
                                  KEY_ENUMERATE_SUB_KEYS     |\
                                  KEY_NOTIFY)                 \
                                  &                           \
                                 (~SYNCHRONIZE))
#define KEY_EXECUTE             ((KEY_READ)                   \
                                  &                           \
                                 (~SYNCHRONIZE))
#define OBJECT_TYPE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define SYMBOLIC_LINK_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define PROCESS_ALL_ACCESS        (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0xFFF)
#define THREAD_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0x3FF)
#define EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3) // winnt
#define SERVICE_DRIVER                 (SERVICE_KERNEL_DRIVER | \
                                        SERVICE_FILE_SYSTEM_DRIVER | \
                                        SERVICE_RECOGNIZER_DRIVER)
#define SERVICE_WIN32                  (SERVICE_WIN32_OWN_PROCESS | \
                                        SERVICE_WIN32_SHARE_PROCESS)
#define SERVICE_TYPE_ALL               (SERVICE_WIN32  | \
                                        SERVICE_ADAPTER | \
                                        SERVICE_DRIVER  | \
                                        SERVICE_INTERACTIVE_PROCESS)
#define IRP_MN_MDL_DPC                  (IRP_MN_MDL | IRP_MN_DPC)
#define IoInitializeDpcRequest( DeviceObject, DpcRoutine ) (\
    KeInitializeDpc( &(DeviceObject)->Dpc,                  \
                     (PKDEFERRED_ROUTINE) (DpcRoutine),     \
                     (DeviceObject) ) )

// public\ddk\inc\ntddkbd.h
#define ENHANCED_KEYBOARD(Id) ((Id).Type == 2 || (Id).Type == 4 || FAREAST_KEYBOARD(Id))
#define FAREAST_KEYBOARD(Id)  ((Id).Type == 7 || (Id).Type == 8)

// public\ddk\inc\ntddvdeo.h
#define DISPLAYPOLICY_BOTH              (DISPLAYPOLICY_AC | DISPLAYPOLICY_DC)

// public\ddk\inc\ntdef.h
#define PRIMARYLANGID(lgid)    ((USHORT)(lgid) & 0x3ff)

// public\ddk\inc\ntia64.h
#define RES_FTR(FTR) ((FTR) & 0x000000005555FFC0ULL)

// public\ddk\inc\parallel.h
#define ECR_ECP_PIO_MODE           (ECR_ECP_MODE | ECR_ERRINT_DISABLED | ECR_SVC_INT_DISABLED)
#define ECR_EPP_PIO_MODE           (ECR_EPP_MODE | ECR_ERRINT_DISABLED | ECR_SVC_INT_DISABLED)

// public\ddk\inc\tdikrnl.h
#define TDI_INIT_CMSGHDR(cmsg, level, type, length) { \
        ((TDI_CMSGHDR *) cmsg)->cmsg_level = level; \
        ((TDI_CMSGHDR *) cmsg)->cmsg_type = type;  \
        ((TDI_CMSGHDR *) cmsg)->cmsg_len = TDI_CMSG_LEN(length); \
        }

// public\ddk\inc\wdm\61883.h
#define INIT_61883_HEADER( Av61883, Request )             \
        (Av61883)->Function = Request;                    \
        (Av61883)->Version = CURRENT_61883_DDI_VERSION;

// public\ddk\inc\wdm\usbdlib.h
#define UsbBuildSelectConfigurationRequest(urb, \
                                         length, \
                                         configurationDescriptor) { \
            (urb)->UrbHeader.Function =  URB_FUNCTION_SELECT_CONFIGURATION; \
            (urb)->UrbHeader.Length = (length); \
            (urb)->UrbSelectConfiguration.ConfigurationDescriptor = (configurationDescriptor);    }

// public\ddk\inc\wdm\wdm.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe
#define FILE_READ_DATA            ( 0x0001 )    // file & pipe
#define FILE_WRITE_DATA           ( 0x0002 )    // file & pipe
#define FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
                                   FILE_READ_DATA           |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_READ_EA             |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
                                   FILE_WRITE_DATA          |\
                                   FILE_WRITE_ATTRIBUTES    |\
                                   FILE_WRITE_EA            |\
                                   FILE_APPEND_DATA         |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_EXECUTE             |\
                                   SYNCHRONIZE)
#define KEY_READ                ((STANDARD_RIGHTS_READ       |\
                                  KEY_QUERY_VALUE            |\
                                  KEY_ENUMERATE_SUB_KEYS     |\
                                  KEY_NOTIFY)                 \
                                  &                           \
                                 (~SYNCHRONIZE))
#define KEY_EXECUTE             ((KEY_READ)                   \
                                  &                           \
                                 (~SYNCHRONIZE))
#define OBJECT_TYPE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define SYMBOLIC_LINK_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define PROCESS_ALL_ACCESS        (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0xFFF)
#define THREAD_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0x3FF)
#define EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#define SERVICE_DRIVER                 (SERVICE_KERNEL_DRIVER | \
                                        SERVICE_FILE_SYSTEM_DRIVER | \
                                        SERVICE_RECOGNIZER_DRIVER)
#define SERVICE_WIN32                  (SERVICE_WIN32_OWN_PROCESS | \
                                        SERVICE_WIN32_SHARE_PROCESS)
#define SERVICE_TYPE_ALL               (SERVICE_WIN32  | \
                                        SERVICE_ADAPTER | \
                                        SERVICE_DRIVER  | \
                                        SERVICE_INTERACTIVE_PROCESS)
#define IoInitializeDpcRequest( DeviceObject, DpcRoutine ) (\
    KeInitializeDpc( &(DeviceObject)->Dpc,                  \
                     (PKDEFERRED_ROUTINE) (DpcRoutine),     \
                     (DeviceObject) ) )

// public\ddk\inc\wiadef.h
#define WIA_PROP_RW              (WIA_PROP_READ | WIA_PROP_WRITE)

// public\halkit\inc\nthal.h
#define RES_FTR(FTR) ((FTR) & 0x000000005555FFC0ULL)
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe
#define KEY_READ                ((STANDARD_RIGHTS_READ       |\
                                  KEY_QUERY_VALUE            |\
                                  KEY_ENUMERATE_SUB_KEYS     |\
                                  KEY_NOTIFY)                 \
                                  &                           \
                                 (~SYNCHRONIZE))
#define KEY_EXECUTE             ((KEY_READ)                   \
                                  &                           \
                                 (~SYNCHRONIZE))
#define FILE_READ_DATA            ( 0x0001 )    // file & pipe
#define FILE_WRITE_DATA           ( 0x0002 )    // file & pipe
#define FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
                                   FILE_READ_DATA           |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_READ_EA             |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
                                   FILE_WRITE_DATA          |\
                                   FILE_WRITE_ATTRIBUTES    |\
                                   FILE_WRITE_EA            |\
                                   FILE_APPEND_DATA         |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_EXECUTE             |\
                                   SYNCHRONIZE)
#define OBJECT_TYPE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define SYMBOLIC_LINK_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define SERVICE_DRIVER                 (SERVICE_KERNEL_DRIVER | \
                                        SERVICE_FILE_SYSTEM_DRIVER | \
                                        SERVICE_RECOGNIZER_DRIVER)
#define SERVICE_WIN32                  (SERVICE_WIN32_OWN_PROCESS | \
                                        SERVICE_WIN32_SHARE_PROCESS)
#define SERVICE_TYPE_ALL               (SERVICE_WIN32  | \
                                        SERVICE_ADAPTER | \
                                        SERVICE_DRIVER  | \
                                        SERVICE_INTERACTIVE_PROCESS)
#define TRAP_FRAME_TYPE(tf)  (tf->EOFMarker & 0xf)
#define IRP_MN_MDL_DPC                  (IRP_MN_MDL | IRP_MN_DPC)
#define IoInitializeDpcRequest( DeviceObject, DpcRoutine ) (\
    KeInitializeDpc( &(DeviceObject)->Dpc,                  \
                     (PKDEFERRED_ROUTINE) (DpcRoutine),     \
                     (DeviceObject) ) )

// public\ifskit\inc\ntifs.h
#define TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED  |\
                          TOKEN_ASSIGN_PRIMARY      |\
                          TOKEN_DUPLICATE           |\
                          TOKEN_IMPERSONATE         |\
                          TOKEN_QUERY               |\
                          TOKEN_QUERY_SOURCE        |\
                          TOKEN_ADJUST_PRIVILEGES   |\
                          TOKEN_ADJUST_GROUPS       |\
                          TOKEN_ADJUST_DEFAULT )
#define TOKEN_ALL_ACCESS  (TOKEN_ALL_ACCESS_P |\
                          TOKEN_ADJUST_SESSIONID )
#define TOKEN_READ       (STANDARD_RIGHTS_READ      |\
                          TOKEN_QUERY)
#define TOKEN_WRITE      (STANDARD_RIGHTS_WRITE     |\
                          TOKEN_ADJUST_PRIVILEGES   |\
                          TOKEN_ADJUST_GROUPS       |\
                          TOKEN_ADJUST_DEFAULT)
#define RtlParent(Links) (           \
    (PRTL_SPLAY_LINKS)(Links)->Parent \
    )
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe
#define PROCESS_ALL_ACCESS        (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0xFFF)
#define THREAD_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0x3FF)
#define FILE_READ_DATA            ( 0x0001 )    // file & pipe
#define FILE_WRITE_DATA           ( 0x0002 )    // file & pipe
#define FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
                                   FILE_READ_DATA           |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_READ_EA             |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
                                   FILE_WRITE_DATA          |\
                                   FILE_WRITE_ATTRIBUTES    |\
                                   FILE_WRITE_EA            |\
                                   FILE_APPEND_DATA         |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_EXECUTE             |\
                                   SYNCHRONIZE)
#define FSCTL_HSM_DATA                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 68, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IsReparseTagMicrosoft(_tag) (              \
                           ((_tag) & 0x80000000)   \
                           )
#define IsReparseTagNameSurrogate(_tag) (          \
                           ((_tag) & 0x20000000)   \
                           )
#define FSCTL_PIPE_TRANSCEIVE           CTL_CODE(FILE_DEVICE_NAMED_PIPE, 5, METHOD_NEITHER,  FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_PIPE_INTERNAL_TRANSCEIVE  CTL_CODE(FILE_DEVICE_NAMED_PIPE, 2047, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define OBJECT_TYPE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define SYMBOLIC_LINK_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define SERVICE_DRIVER                 (SERVICE_KERNEL_DRIVER | \
                                        SERVICE_FILE_SYSTEM_DRIVER | \
                                        SERVICE_RECOGNIZER_DRIVER)
#define SERVICE_WIN32                  (SERVICE_WIN32_OWN_PROCESS | \
                                        SERVICE_WIN32_SHARE_PROCESS)
#define SERVICE_TYPE_ALL               (SERVICE_WIN32  | \
                                        SERVICE_ADAPTER | \
                                        SERVICE_DRIVER  | \
                                        SERVICE_INTERACTIVE_PROCESS)
#define KEY_READ                ((STANDARD_RIGHTS_READ       |\
                                  KEY_QUERY_VALUE            |\
                                  KEY_ENUMERATE_SUB_KEYS     |\
                                  KEY_NOTIFY)                 \
                                  &                           \
                                 (~SYNCHRONIZE))
#define KEY_EXECUTE             ((KEY_READ)                   \
                                  &                           \
                                 (~SYNCHRONIZE))
#define EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3) // winnt
#define IRP_MN_MDL_DPC                  (IRP_MN_MDL | IRP_MN_DPC)
#define IoInitializeDpcRequest( DeviceObject, DpcRoutine ) (\
    KeInitializeDpc( &(DeviceObject)->Dpc,                  \
                     (PKDEFERRED_ROUTINE) (DpcRoutine),     \
                     (DeviceObject) ) )
#define CcReadAhead(FO,FOFF,LEN) {                       \
    if ((LEN) >= 256) {                                  \
        CcScheduleReadAhead((FO),(FOFF),(LEN));          \
    }                                                    \
}

// public\internal\ds\inc\crypto\bignum.h
#define USEASM_AMD64    (USEASM && TARGET == TARGET_AMD64)
#define USEASM_IX86     (USEASM && TARGET == TARGET_IX86)
#define USEASM_MIPS     (USEASM && TARGET == TARGET_MIPS)
#define USEASM_PPC      (USEASM && TARGET == TARGET_PPC)
#define USEASM_SPARC    (USEASM && TARGET == TARGET_SPARC)
#define USEASM_IA64     (USEASM && TARGET == TARGET_IA64)
#define USEASM_ARM      (USEASM && TARGET == TARGET_ARM)
#define USEASM_SHX      (USEASM && TARGET == TARGET_SHX)
#define POWER3CON(i) (   ((i) & 1 ?  3 : 1)  *  ((i) & 2 ?    9 : 1) \
                       * ((i) & 4 ? 81 : 1)  *  ((i) & 8 ? 6561 : 1) )

// public\internal\ds\inc\xomi.h
#define om_copy_value(SOURCE, SOURCE_TYPE, SOURCE_POSITION, DEST, DEST_TYPE, DEST_POSITION) \
((((SOURCE)->type == OM_PRIVATE_OBJECT) && ((DEST)->type == OM_PRIVATE_OBJECT)) ? OMP_FUNCTIONS(DEST)->copy_value((SOURCE), (SOURCE_TYPE), (SOURCE_POSITION), (DEST), (DEST_TYPE), (DEST_POSITION)) : OM_NOT_PRIVATE)
#define om_instance(SUBJECT,CLASS,INSTANCE) (((SUBJECT)->syntax & OM_S_SERVICE_GENERATED) ? OMP_FUNCTIONS(SUBJECT)->instance((SUBJECT),*(CLASS),(INSTANCE)) : OM_NOT_THE_SERVICES)
#define om_instance(SUBJECT,CLASS,INSTANCE) (((SUBJECT)->syntax & OM_S_SERVICE_GENERATED) ? OMP_FUNCTIONS(SUBJECT)->instance((SUBJECT),(CLASS),(INSTANCE)) : OM_NOT_THE_SERVICES)
#define om_copy_value(SOURCE, SOURCE_TYPE, SOURCE_POSITION, DEST, DEST_TYPE, DEST_POSITION) \
((((SOURCE)->type == OM_PRIVATE_OBJECT) && ((DEST)->type == OM_PRIVATE_OBJECT)) ? OMP_FUNCTIONS(DEST)->_copy_value((SOURCE), (SOURCE_TYPE), (SOURCE_POSITION), (DEST), (DEST_TYPE), (DEST_POSITION)) : OM_NOT_PRIVATE)
#define om_instance(SUBJECT,CLASS,INSTANCE) (((SUBJECT)->syntax & OM_S_SERVICE_GENERATED) ? OMP_FUNCTIONS(SUBJECT)->_instance((SUBJECT),(CLASS),(INSTANCE)) : OM_NOT_THE_SERVICES)

// public\internal\net\inc\dhcpapi.h
#define DHCP_SERVER_USE_RPC_OVER_ALL (\
            DHCP_SERVER_USE_RPC_OVER_TCPIP | \
            DHCP_SERVER_USE_RPC_OVER_NP    | \
            DHCP_SERVER_USE_RPC_OVER_LPC)
#define CLIENT_TYPE_BOTH    ( CLIENT_TYPE_DHCP | CLIENT_TYPE_BOOTP )

// public\internal\net\inc\icanon.h
#define ITYPE_SYS_SEM           (ITYPE_SYS|0x100)
#define ITYPE_SYS_SHMEM         (ITYPE_SYS|0x200)
#define ITYPE_SYS_PIPE          (ITYPE_SYS|0x300)
#define   ITYPE_PATH_SYS        (ITYPE_PATH_ABSND|ITYPE_SYS)
#define   ITYPE_UNC_SYS         (ITYPE_UNC|ITYPE_SYS)
#define   ITYPE_UNC_SYS_SEM     (ITYPE_UNC_SYS|ITYPE_SYS_SEM)
#define   ITYPE_UNC_SYS_SHMEM   (ITYPE_UNC_SYS|ITYPE_SYS_SHMEM)
#define   ITYPE_UNC_SYS_PIPE    (ITYPE_UNC_SYS|ITYPE_SYS_PIPE)
#define   ITYPE_PATH_ABSND      (ITYPE_PATH|ITYPE_ABSOLUTE|ITYPE_NDPATH)
#define   ITYPE_PATH_ABSD       (ITYPE_PATH|ITYPE_ABSOLUTE|ITYPE_DPATH)
#define   ITYPE_PATH_RELND      (ITYPE_PATH|ITYPE_RELATIVE|ITYPE_NDPATH)
#define   ITYPE_PATH_RELD       (ITYPE_PATH|ITYPE_RELATIVE|ITYPE_DPATH)
#define   ITYPE_PATH_ABSND_WC   (ITYPE_PATH_ABSND|ITYPE_WILD)
#define   ITYPE_PATH_ABSD_WC    (ITYPE_PATH_ABSD|ITYPE_WILD)
#define   ITYPE_PATH_RELND_WC   (ITYPE_PATH_RELND|ITYPE_WILD)
#define   ITYPE_PATH_RELD_WC    (ITYPE_PATH_RELD|ITYPE_WILD)
#define   ITYPE_PATH_SYS_SEM    (ITYPE_PATH_SYS|ITYPE_SYS_SEM)
#define   ITYPE_PATH_SYS_SHMEM  (ITYPE_PATH_SYS|ITYPE_SYS_SHMEM)
#define   ITYPE_PATH_SYS_PIPE   (ITYPE_PATH_SYS|ITYPE_SYS_PIPE)
#define   ITYPE_PATH_SYS_SEM_M  (ITYPE_PATH_SYS|ITYPE_SYS_SEM|ITYPE_META)
#define   ITYPE_PATH_SYS_SHMEM_M (ITYPE_PATH_SYS|ITYPE_SYS_SHMEM|ITYPE_META)
#define   ITYPE_PATH_SYS_PIPE_M (ITYPE_PATH_SYS|ITYPE_SYS_PIPE|ITYPE_META)
#define   ITYPE_DEVICE_DISK     (ITYPE_DEVICE|ITYPE_DISK)
#define   ITYPE_DEVICE_LPT      (ITYPE_DEVICE|ITYPE_LPT)
#define   ITYPE_DEVICE_CON      (ITYPE_DEVICE|ITYPE_CON)
#define   ITYPE_DEVICE_NUL      (ITYPE_DEVICE|ITYPE_NUL)

// public\internal\net\inc\isnkrnl.h
#define MIPX_SETNODEADDR   (I_MIPX | 0)   /* Set the node address */
#define MIPX_SETNETNUM     (I_MIPX | 1)   /* Set the network number */
#define MIPX_SENTTYPE      (I_MIPX | 3)   /* (X) Set the xport type */
#define MIPX_SENDOPTS      (I_MIPX | 6)   /* (X) Send options on recv */
#define MIPX_NOSENDOPTS    (I_MIPX | 7)   /* (X) Don't send options on recv */
#define MIPX_SENDSRC       (I_MIPX | 8)   /* (X) Send source address up */
#define MIPX_NOSENDSRC     (I_MIPX | 9)   /* (X) Don't Send source address up */
#define MIPX_SETCARDTYPE   (I_MIPX | 12)  /* Set 802.3 or ETH type */
#define MIPX_SENDDEST      (I_MIPX | 15)  /* (X) Send dest. address up */
#define MIPX_NOSENDDEST    (I_MIPX | 16)  /* (X) Don't send dest. address up */
#define MIPX_SENDFDEST     (I_MIPX | 17)  /* (X) Send final dest. address up */
#define MIPX_NOSENDFDEST   (I_MIPX | 18)  /* (X) Don't send final dest. up */
#define MIPX_SETVERSION    (I_MIPX | 100) /* Set card version */
#define MIPX_SENDADDROPT   (I_MIPX | 102) /* (X) Send ptype w/addr on recv */
#define MIPX_NOSENDADDROPT (I_MIPX | 103) /* (X) Stop sending ptype on recv */
#define MIPX_SENDHEADER    (I_MIPX | 106) /* Send header with data        */
#define MIPX_NOSENDHEADER  (I_MIPX | 107) /* Don't send header with data  */
#define MIPX_SETCURCARD    (I_MIPX | 108) /* Set current card for IOCTLs  */
#define MIPX_SETMACTYPE    (I_MIPX | 109) /* Set the Cards MAC type       */
#define MIPX_NOSROUTE      (I_MIPX | 111) /* Don't source routine the card*/
#define MIPX_SETRIPRETRY   (I_MIPX | 112) /* Set RIP retry count          */
#define MIPX_SETTKRSAP     (I_MIPX | 114) /* Set the token ring SAP       */
#define MIPX_8023LEN       (I_MIPX | 117) /* 1=make even, 0=dont make even*/
#define MIPX_SENDPTYPE     (I_MIPX | 118) /* Send ptype in options on recv*/
#define MIPX_NOSENDPTYPE   (I_MIPX | 119) /* Don't send ptype in options  */
#define MIPX_FILTERPTYPE   (I_MIPX | 120) /* Filter on recv ptype         */
#define MIPX_NOFILTERPTYPE (I_MIPX | 121) /* Don't Filter on recv ptype   */
#define MIPX_SETSENDPTYPE  (I_MIPX | 122) /* Set pkt type to send with    */
#define MIPX_GETCARDINFO   (I_MIPX | 123) /* Get info on a card           */
#define MIPX_SENDCARDNUM   (I_MIPX | 124) /* Send card num up in options  */
#define MIPX_NOSENDCARDNUM (I_MIPX | 125) /* Dont send card num in options*/
#define MIPX_SETINTNET     (I_MIPX | 130) /* Set internal network number  */
#define MIPX_NOVIRTADDR    (I_MIPX | 131) /* Turn off virtual net num     */
#define MIPX_VIRTADDR      (I_MIPX | 132) /* Turn on  virtual net num     */
#define MIPX_GETNETINFO    (I_MIPX | 135) /* Get info on a network num    */
#define MIPX_SETSOCKETS    (I_MIPX | 138) /* Set default sockets          */
#define MIPX_SETLINKSPEED  (I_MIPX | 139) /* Set the link speed for a card*/
#define MIPX_GETCARDCHANGES (I_MIPX | 141) /* Wait for card changes	*/
#define MIPX_REUSEADDRESS   (I_MIPX | 143)
#define MIPX_RERIPNETNUM    (I_MIPX | 144) /* ReRip a network         */
#define MIPX_GETNETINFO_NR  (I_MIPX | 145) /* Get info on a net num - NO RIP */
#define MIPX_SETNIC         (I_MIPX | 146)
#define MIPX_NOSETNIC       (I_MIPX | 147)
#define MIPX_SRDEF         (I_MIPX | 201) /* 0=Single Rte, 1=All Routes   */
#define MIPX_SRMULTI       (I_MIPX | 203) /* 0=Single Rte, 1=All Routes   */
#define MIPX_SRGETPARMS    (I_MIPX | 206) /* Get source routing parms     */
#define MIPX_SETSHOULDPUT  (I_MIPX | 210) /* Turn on should put call      */
#define MIPX_DELSHOULDPUT  (I_MIPX | 211) /* Turn off should put call     */
#define MIPX_NOTIFYCARDINFO (I_MIPX | 303) /* Pend until card info changes */
#define MIPX_ZEROSOCKET    (I_MIPX | 306) /* Use 0 as source socket on sends */
#define MIPX_CONFIG        (I_MIPX | 309) /* used by IPXROUTE for config info */
#define MIPX_GETNEWNICINFO  (I_MIPX | 313) /*Get any new NIC info that might
#define MIPX_RT_CREATE      (I_MIPX | 316)
#define MIPX_IPXWAN_CONFIG_DONE   (I_MIPX | 317)
#define MIPX_QUERY_WAN_INACTIVITY (I_MIPX | 318)
#define MSPX_SETADDR       (I_MSPX | 0)   /* Set the network address      */
#define MSPX_SETDATAACK    (I_MSPX | 103) /* Set DATA ACK option          */
#define MSPX_NODATAACK     (I_MSPX | 104) /* Turn off DATA ACK option     */
#define MSPX_SENDHEADER    (I_MSPX | 108) /* Send header with data        */
#define MSPX_NOSENDHEADER  (I_MSPX | 109) /* Don't send header with data  */
#define MSPX_SETCONNCNT    (I_MSPX | 111) /* Set the conn req count       */
#define MSPX_SETALIVECNT   (I_MSPX | 113) /* Set the keepalive count      */
#define MSPX_GETSTATS      (I_MSPX | 119) /* Get connection stats         */
#define MSPX_NOACKWAIT     (I_MSPX | 120) /* Disable piggyback wait       */
#define MSPX_ACKWAIT       (I_MSPX | 121) /* Enable pback wait (default)  */

// public\internal\net\inc\mpr.h
#define SHOW_CONNECTION     (WM_USER+200)

// public\internal\sdktools\inc\ehdata.h
#define EH_EXCEPTION_NUMBER	('msc' | 0xE0000000)	// The NT Exception # that we use
#define CT_ISSIMPLETYPE(ct)			(CT_PROPERTIES(ct) & CT_IsSimpleType)		// Is it a simple type?
#define CT_BYREFONLY(ct)			(CT_PROPERTIES(ct) & CT_ByReferenceOnly)	// Must it be caught by reference?
#define THROW_ISCONST(t)		(THROW_ATTRS(t) & TI_IsConst)
#define THROW_ISVOLATILE(t)		(THROW_ATTRS(t) & TI_IsVolatile)
#define HT_ISCONST(ht)			(HT_ADJECTIVES(ht) & HT_IsConst)		// Is the type referenced 'const' qualified
#define HT_ISVOLATILE(ht)		(HT_ADJECTIVES(ht) & HT_IsVolatile)		// Is the type referenced 'volatile' qualified
#define HT_ISREFERENCE(ht)		(HT_ADJECTIVES(ht) & HT_IsReference)	// Is the catch type by reference
#define HT_ISRESUMABLE(ht)		(HT_ADJECTIVES(ht) & HT_IsResumable)	// Might the catch choose to resume (Reserved)
#define FUNC_PUNWIND(fi, st)	(&FUNC_UNWIND(fi, st))
#define FUNC_PUNWIND(fi, st)	(&FUNC_UNWIND(fi, st))
#define EXCEPTION_UNWIND (EXCEPTION_UNWINDING | EXCEPTION_EXIT_UNWIND | \
                          EXCEPTION_TARGET_UNWIND | EXCEPTION_COLLIDED_UNWIND)

// public\internal\termsrv\inc\winsta.h
#define WINSTATION_USER_ACCESS (WINSTATION_GUEST_ACCESS |                      \
                                WINSTATION_QUERY | WINSTATION_MSG |            \
                                WINSTATION_CONNECT )

// public\oak\inc\ddrawi.h
#define SURFACE_PHYSICALVIDMEM( psurf_gbl ) \
    ( GET_LPDDRAWSURFACE_GBL_MORE( psurf_gbl )->fpPhysicalVidMem )
#define BUMP_SURFACE_STAMP(surf_gbl)                                                \
if ( GET_LPDDRAWSURFACE_GBL_MORE(surf_gbl)->dwContentsStamp )                      \
{                                                                                   \
    GET_LPDDRAWSURFACE_GBL_MORE(surf_gbl)->dwContentsStamp++;                      \
    if ( 0 ==GET_LPDDRAWSURFACE_GBL_MORE(surf_gbl)->dwContentsStamp)               \
        GET_LPDDRAWSURFACE_GBL_MORE(surf_gbl)->dwContentsStamp++;                  \
}
#define DDRAWISURFGBL_HARDWAREOPSTARTED (DDRAWISURFGBL_HARDWAREOPSOURCE|DDRAWISURFGBL_HARDWAREOPDEST)

// public\oak\inc\kbd.h
#define KLL_LAYOUT_ATTR_FROM_KLF(x)  (KLL_ATTR_FROM_KLF(x) & KLLF_LAYOUT_ATTRS)
#define FUJITSU_KBD_REMOTE(Id)   (JAPANESE_KEYBOARD(Id) && \
                                  (Id).SubType == 0x00020002)
#define T0D _NE( OEM_7,      OEM_PLUS     ) // "^"/"="

// public\sdk\amovie\inc\amvideo.h
#define AMDDS_YUV (AMDDS_YUVOFF | AMDDS_YUVOVR | AMDDS_YUVFLP)
#define AMDDS_PRIMARY (AMDDS_DCIPS | AMDDS_PS)
#define HEADER(pVideoInfo) (&(((VIDEOINFOHEADER *) (pVideoInfo))->bmiHeader))

// public\sdk\inc\accctrl.h
#define TRUSTEE_ACCESS_READ_WRITE   (TRUSTEE_ACCESS_READ |                  \
                                     TRUSTEE_ACCESS_WRITE)
#define ACTRL_STD_RIGHT_REQUIRED    ( ACTRL_STD_RIGHTS_ALL & ~ACTRL_SYNCHRONIZE )

// public\sdk\inc\aclui.h
#define SI_EDIT_ALL     (SI_EDIT_PERMS | SI_EDIT_OWNER | SI_EDIT_AUDITS)

// public\sdk\inc\alphaops.h
#define BPT_FUNC       (UNPRIV_PAL_FUNC | 0x00)
#define CALLSYS_FUNC   (UNPRIV_PAL_FUNC | 0x03)
#define IMB_FUNC       (UNPRIV_PAL_FUNC | 0x06)
#define GENTRAP_FUNC   (UNPRIV_PAL_FUNC | 0xAA)
#define RDTEB_FUNC     (UNPRIV_PAL_FUNC | 0xAB)
#define KBPT_FUNC      (UNPRIV_PAL_FUNC | 0xAC)
#define CALLKD_FUNC    (UNPRIV_PAL_FUNC | 0xAD)
#define RDTEB64_FUNC   (UNPRIV_PAL_FUNC | 0xAE)
#define HALT_FUNC       (PRIV_PAL_FUNC | 0x00)
#define RESTART_FUNC    (PRIV_PAL_FUNC | 0x01)
#define DRAINA_FUNC     (PRIV_PAL_FUNC | 0x02)
#define REBOOT_FUNC     (PRIV_PAL_FUNC | 0x03)
#define INITPAL_FUNC    (PRIV_PAL_FUNC | 0x04)
#define SWPIRQL_FUNC    (PRIV_PAL_FUNC | 0x06)
#define RDIRQL_FUNC     (PRIV_PAL_FUNC | 0x07)
#define DI_FUNC         (PRIV_PAL_FUNC | 0X08)
#define EI_FUNC         (PRIV_PAL_FUNC | 0x09)
#define SWPPAL_FUNC     (PRIV_PAL_FUNC | 0x0A)
#define SSIR_FUNC       (PRIV_PAL_FUNC | 0x0C)
#define CSIR_FUNC       (PRIV_PAL_FUNC | 0x0D)
#define RFE_FUNC        (PRIV_PAL_FUNC | 0x0E)
#define RETSYS_FUNC     (PRIV_PAL_FUNC | 0x0F)
#define SWPCTX_FUNC     (PRIV_PAL_FUNC | 0x10)
#define SWPPROCESS_FUNC (PRIV_PAL_FUNC | 0x11)
#define RDMCES_FUNC     (PRIV_PAL_FUNC | 0x12)
#define WRMCES_FUNC     (PRIV_PAL_FUNC | 0x13)
#define TBIA_FUNC       (PRIV_PAL_FUNC | 0x14)
#define TBISASN_FUNC    (PRIV_PAL_FUNC | 0x17)
#define RDKSP_FUNC      (PRIV_PAL_FUNC | 0x18)
#define SWPKSP_FUNC     (PRIV_PAL_FUNC | 0x19)
#define RDPSR_FUNC      (PRIV_PAL_FUNC | 0x1A)
#define RDPCR_FUNC      (PRIV_PAL_FUNC | 0x1C)
#define RDTHREAD_FUNC   (PRIV_PAL_FUNC | 0x1E)
#define TBIM_FUNC       (PRIV_PAL_FUNC | 0x20)
#define TBIMASN_FUNC    (PRIV_PAL_FUNC | 0x21)
#define TBIM64_FUNC     (PRIV_PAL_FUNC | 0x22)
#define TBIS64_FUNC     (PRIV_PAL_FUNC | 0x23)
#define EALNFIX_FUNC    (PRIV_PAL_FUNC | 0x24)
#define DALNFIX_FUNC    (PRIV_PAL_FUNC | 0x25)
#define RDCOUNTERS_FUNC (PRIV_PAL_FUNC | 0x30)
#define WRPERFMON_FUNC  (PRIV_PAL_FUNC | 0x32)
#define CP_SLEEP_FUNC   (PRIV_PAL_FUNC | 0x39)
#define INITPCR_FUNC    (PRIV_PAL_FUNC | 0x38)

// public\sdk\inc\atl21\atlwin.h
#define MESSAGE_HANDLER(msg, func) \
        if(uMsg == msg) \
        { \
                bHandled = TRUE; \
                lResult = func(uMsg, wParam, lParam, bHandled); \
                if(bHandled) \
                        return TRUE; \
        }

// public\sdk\inc\atl21\atlwin21.h
#define REFLECT_NOTIFICATIONS() \
    { \
        bHandled = TRUE; \
        lResult = ReflectNotifications(uMsg, wParam, lParam, bHandled); \
        if(bHandled) \
            return TRUE; \
    }

// public\sdk\inc\atl30\atldbcli.h
#define DEFINE_OLEDB_TYPE_FUNCTION(ctype, oledbtype) \
	inline DBTYPE _GetOleDBType(ctype&) \
	{ \
		return oledbtype; \
	}

// public\sdk\inc\atl30\atlsnap.h
#define SNAPINMENUID(id) \
public: \
	static const UINT GetMenuID() \
	{ \
		static const UINT IDMENU = id; \
		return id; \
	}
#define EXT_SNAPINMENUID(id) \
public: \
	static const UINT GetMenuID() \
	{ \
		static const UINT IDMENU = id; \
		return id; \
	}

// public\sdk\inc\atl30\atlwin.h
#define MESSAGE_HANDLER(msg, func) \
	if(uMsg == msg) \
	{ \
		bHandled = TRUE; \
		lResult = func(uMsg, wParam, lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define REFLECT_NOTIFICATIONS() \
	{ \
		bHandled = TRUE; \
		lResult = ReflectNotifications(uMsg, wParam, lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}

// public\sdk\inc\chanmgr.h
#define CHANENUM_ALLFOLDERS (CHANENUM_CHANNELFOLDER    |    \
                             CHANENUM_SOFTUPDATEFOLDER |    \
                             CHANENUM_DESKTOPFOLDER          )

// public\sdk\inc\clusapi.h
#define CLUSAPI_ALL_ACCESS (CLUSAPI_READ_ACCESS | CLUSAPI_CHANGE_ACCESS)

// public\sdk\inc\correg.h
#define RidToToken(rid,tktype) ((rid) |= (tktype))
#define TokenFromRid(rid,tktype) ((rid) | (tktype))
#define RidFromToken(tk) ((RID) ((tk) & 0x00ffffff))
#define TypeFromToken(tk) ((tk) & 0xff000000)

// public\sdk\inc\crt\ctype.h
#define __toascii(_c)   ( (_c) & 0x7f )
#define iswalnum(_c)    ( iswctype(_c,_ALPHA|_DIGIT) )
#define iswgraph(_c)    ( iswctype(_c,_PUNCT|_ALPHA|_DIGIT) )
#define __iscsymf(_c)   (isalpha(_c) || ((_c) == '_'))
#define __iscsym(_c)    (isalnum(_c) || ((_c) == '_'))

// public\sdk\inc\crt\stdarg.h
#define _ADDRESSOF(v)   ( &(v) )
#define va_end(ap)      ( __va_end(&ap) )
#define va_start(ap, x) ( __va_start(&ap, x) )

// public\sdk\inc\crt\stdio.h
#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

// public\sdk\inc\crt\varargs.h
#define va_start(ap, x) ( __va_start(&ap, x) )

// public\sdk\inc\crt\wctype.h
#define iswalnum(_c)    ( iswctype(_c,_ALPHA|_DIGIT) )
#define iswgraph(_c)    ( iswctype(_c,_PUNCT|_ALPHA|_DIGIT) )

// public\sdk\inc\crt\xmath.h
#define DSIGN(x)	(((unsigned short *)&(x))[_D0] & _DSIGN)
#define FSIGN(x)	(((unsigned short *)&(x))[_F0] & _FSIGN)
#define LSIGN(x)	(((unsigned short *)&(x))[_L0] & _LSIGN)

// public\sdk\inc\d3d8types.h
#define D3DCS_ALL (D3DCS_LEFT   | \
                   D3DCS_RIGHT  | \
                   D3DCS_TOP    | \
                   D3DCS_BOTTOM | \
                   D3DCS_FRONT  | \
                   D3DCS_BACK   | \
                   D3DCS_PLANE0 | \
                   D3DCS_PLANE1 | \
                   D3DCS_PLANE2 | \
                   D3DCS_PLANE3 | \
                   D3DCS_PLANE4 | \
                   D3DCS_PLANE5)
#define D3DVS_NOSWIZZLE (D3DVS_X_X | D3DVS_Y_Y | D3DVS_Z_Z | D3DVS_W_W)

// public\sdk\inc\d3dcaps.h
#define D3DDEBCAPS_MEM (D3DDEBCAPS_SYSTEMMEMORY|D3DDEBCAPS_VIDEOMEMORY)

// public\sdk\inc\d3dtypes.h
#define CI_GETFRACTION(ci) ((ci) & 0xff)
#define D3DLIGHT_ALL (D3DLIGHT_ACTIVE | D3DLIGHT_NO_SPECULAR)
#define D3DFVF_VERTEX ( D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 )
#define D3DFVF_LVERTEX ( D3DFVF_XYZ | D3DFVF_RESERVED1 | D3DFVF_DIFFUSE | \
                         D3DFVF_SPECULAR | D3DFVF_TEX1 )
#define D3DFVF_TLVERTEX ( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | \
                          D3DFVF_TEX1 )

// public\sdk\inc\d4drvif.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// public\sdk\inc\ddeml.h
#define DDE_FADVRESERVED        (~(DDE_FACKREQ | DDE_FDEFERUPD))
#define     XTYP_ADVSTART           (0x0030 | XCLASS_BOOL          )
#define     XTYP_ADVSTOP            (0x0040 | XCLASS_NOTIFICATION)
#define     XTYP_REQUEST            (0x00B0 | XCLASS_DATA          )

// public\sdk\inc\ddraw.h
#define GET_WHQL_MONTH( dwWHQLLevel ) \
    ( ( (dwWHQLLevel) / 0x100 ) & 0x00ff )
#define GET_WHQL_DAY( dwWHQLLevel ) \
    ( (dwWHQLLevel) & 0xff )

// public\sdk\inc\ddrawex.h
#define	DDSCAPS_DATAEXCHANGE	(DDSCAPS_SYSTEMMEMORY|DDSCAPS_VIDEOMEMORY)

// public\sdk\inc\devioctl.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// public\sdk\inc\dinput.h
#define DIK_OEM_102         0x56    /* <> or \| on RT 102-key keyboard (Non-U.S.) */
#define DIKEYBOARD_OEM_102                      0x81000456    /* <> or \| on RT 102-key keyboard (Non-U.S.) */
#define DIMOUSE_XAXIS                           (0x82000300 |DIMOFS_X ) /* X Axis */
#define DIMOUSE_YAXIS                           (0x82000300 |DIMOFS_Y ) /* Y Axis */
#define DIMOUSE_WHEEL                           (0x82000300 |DIMOFS_Z ) /* Z Axis */
#define DIMOUSE_BUTTON0                         (0x82000400 |DIMOFS_BUTTON0) /* Button 0 */
#define DIMOUSE_BUTTON1                         (0x82000400 |DIMOFS_BUTTON1) /* Button 1 */
#define DIMOUSE_BUTTON2                         (0x82000400 |DIMOFS_BUTTON2) /* Button 2 */
#define DIMOUSE_BUTTON3                         (0x82000400 |DIMOFS_BUTTON3) /* Button 3 */
#define DIMOUSE_BUTTON4                         (0x82000400 |DIMOFS_BUTTON4) /* Button 4 */
#define DIMOUSE_BUTTON5                         (0x82000400 |DIMOFS_BUTTON5) /* Button 5 */
#define DIMOUSE_BUTTON6                         (0x82000400 |DIMOFS_BUTTON6) /* Button 6 */
#define DIMOUSE_BUTTON7                         (0x82000400 |DIMOFS_BUTTON7) /* Button 7 */

// public\sdk\inc\dmusicf.h
#define DMUS_VARIATIONF_MODES_EX     (0x20000000 | 0x80000000)
#define DMUS_SIGNPOSTF_LETTER   (DMUS_SIGNPOSTF_A | DMUS_SIGNPOSTF_B | DMUS_SIGNPOSTF_C | DMUS_SIGNPOSTF_D | DMUS_SIGNPOSTF_E | DMUS_SIGNPOSTF_F)
#define DMUS_SIGNPOSTF_ROOT     (DMUS_SIGNPOSTF_1 | DMUS_SIGNPOSTF_2 | DMUS_SIGNPOSTF_3 | DMUS_SIGNPOSTF_4 | DMUS_SIGNPOSTF_5 | DMUS_SIGNPOSTF_6 | DMUS_SIGNPOSTF_7)

// public\sdk\inc\dmusici.h
#define DMUS_PLAYMODE_NORMALCHORD       (DMUS_PLAYMODE_CHORD_ROOT | DMUS_PLAYMODE_CHORD_INTERVALS)

// public\sdk\inc\esent.h
#define	JET_sesidNil				(~(JET_SESID)0)
#define	JET_instanceNil				(~(JET_INSTANCE)0)
#define JET_LSNil					(~(JET_LS)0)

// public\sdk\inc\esent97.h
#define	JET_sesidNil				(~(JET_SESID)0)
#define	JET_instanceNil				(~(JET_INSTANCE)0)
#define JET_LSNil					(~(JET_LS)0)

// public\sdk\inc\esent98.h
#define	JET_sesidNil				(~(JET_SESID)0)
#define	JET_instanceNil				(~(JET_INSTANCE)0)
#define JET_LSNil					(~(JET_LS)0)

// public\sdk\inc\exchext.h
#define DEFINE_EXCHEXTGUID(name, b) \
    DEFINE_GUID(name, 0x00020D00 | (b), 0, 0, 0xC0,0,0,0,0,0,0,0x46)

// public\sdk\inc\getuser.h
#define USRBROWS_SHOW_ALL	    (USRBROWS_SHOW_ALIASES |\
				     USRBROWS_SHOW_GROUPS  |\
				     USRBROWS_SHOW_USERS)

// public\sdk\inc\gl\glaux.h
#define AUX_WIND_USES_FIXED_332_PAL(x)  (((x) & AUX_FIXED_332_PAL) != 0)

// public\sdk\inc\icm.h
#define CMS_DISABLEINTENT       0x400 // Disable intent selection (render & proofing) always

// public\sdk\inc\icrsint.h
#define END_ADO_BINDING()   {0, adEmpty, 0, 0, 0, 0, 0, 0, 0, FALSE}};\
	return rgADOBindingEntries;}

// public\sdk\inc\ieverp.h
#define VER_PRODUCTVERSION_DW		(0x06000000 | VER_PRODUCTBUILD)

// public\sdk\inc\imnact.h
#define HR_CODE(hr) (INT)(hr & 0xffff)

// public\sdk\inc\imnxport.h
#define HR_CODE(hr) (INT)(hr & 0xffff)

// public\sdk\inc\indicml.h
#define INDICM_REMOVEDEFAULTMENUITEMS     (WM_USER+102)

// public\sdk\inc\ks.h
#define DEFINE_KSFILTER_CATEGORY(category)\
    1,\
    &(category)

// public\sdk\inc\ksmedia.h
#define INIT_USBAUDIO_MID(guid, id)\
{\
    (guid)->Data1 = 0x4e1cecd2 + (USHORT)(id);\
    (guid)->Data2 = 0x1679;\
    (guid)->Data3 = 0x463b;\
    (guid)->Data4[0] = 0xa7;\
    (guid)->Data4[1] = 0x2f;\
    (guid)->Data4[2] = 0xa5;\
    (guid)->Data4[3] = 0xbf;\
    (guid)->Data4[4] = 0x64;\
    (guid)->Data4[5] = 0xc8;\
    (guid)->Data4[6] = 0x6e;\
    (guid)->Data4[7] = 0xba;\
}
#define EXTRACT_USBAUDIO_MID(guid)\
    (USHORT)((guid)->Data1 - 0x4e1cecd2)
#define INIT_USBAUDIO_PID(guid, id)\
{\
    (guid)->Data1 = 0xabcc5a5e + (USHORT)(id);\
    (guid)->Data2 = 0xc263;\
    (guid)->Data3 = 0x463b;\
    (guid)->Data4[0] = 0xa7;\
    (guid)->Data4[1] = 0x2f;\
    (guid)->Data4[2] = 0xa5;\
    (guid)->Data4[3] = 0xbf;\
    (guid)->Data4[4] = 0x64;\
    (guid)->Data4[5] = 0xc8;\
    (guid)->Data4[6] = 0x6e;\
    (guid)->Data4[7] = 0xba;\
}
#define EXTRACT_USBAUDIO_PID(guid)\
    (USHORT)((guid)->Data1 - 0xabcc5a5e)
#define INIT_WAVEFORMATEX_GUID(Guid, x)\
{\
    *(Guid) = KSDATAFORMAT_SUBTYPE_WAVEFORMATEX;\
    (Guid)->Data1 = (USHORT)(x);\
}
#define EXTRACT_WAVEFORMATEX_ID(Guid)\
    (USHORT)((Guid)->Data1)
#define INIT_MMREG_MID(guid, id)\
{\
    (guid)->Data1 = 0xd5a47fa7 + (USHORT)(id);\
    (guid)->Data2 = 0x6d98;\
    (guid)->Data3 = 0x11d1;\
    (guid)->Data4[0] = 0xa2;\
    (guid)->Data4[1] = 0x1a;\
    (guid)->Data4[2] = 0x00;\
    (guid)->Data4[3] = 0xa0;\
    (guid)->Data4[4] = 0xc9;\
    (guid)->Data4[5] = 0x22;\
    (guid)->Data4[6] = 0x31;\
    (guid)->Data4[7] = 0x96;\
}
#define EXTRACT_MMREG_MID(guid)\
    (USHORT)((guid)->Data1 - 0xd5a47fa7)
#define INIT_MMREG_PID(guid, id)\
{\
    (guid)->Data1 = 0xe36dc2ac + (USHORT)(id);\
    (guid)->Data2 = 0x6d9a;\
    (guid)->Data3 = 0x11d1;\
    (guid)->Data4[0] = 0xa2;\
    (guid)->Data4[1] = 0x1a;\
    (guid)->Data4[2] = 0x00;\
    (guid)->Data4[3] = 0xa0;\
    (guid)->Data4[4] = 0xc9;\
    (guid)->Data4[5] = 0x22;\
    (guid)->Data4[6] = 0x31;\
    (guid)->Data4[7] = 0x96;\
}
#define EXTRACT_MMREG_PID(guid)\
    (USHORT)((guid)->Data1 - 0xe36dc2ac)
#define KSAUDIO_SPEAKER_STEREO          (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT)
#define KSAUDIO_SPEAKER_QUAD            (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | \
                                         SPEAKER_BACK_LEFT  | SPEAKER_BACK_RIGHT)
#define KS_VBIDATARATE_CC               ( 503493L)    // ~= 1/1.986125e-6

// public\sdk\inc\lmaudit.h
#define SVAUD_USE               (SVAUD_GOODUSE | SVAUD_BADUSE)

// public\sdk\inc\macfile.h
#define AFP_VOLUME_ALL_DOWNLEVEL	    (AFP_VOLUME_READONLY 	 	|	\
									    AFP_VOLUME_GUESTACCESS)
#define AFP_DIR_PARMNUM_ALL				( AFP_DIR_PARMNUM_PERMS \
										| AFP_DIR_PARMNUM_OWNER	\
										| AFP_DIR_PARMNUM_GROUP	)
#define AFP_FD_PARMNUM_ALL				( AFP_FD_PARMNUM_TYPE \
										| AFP_FD_PARMNUM_CREATOR)

// public\sdk\inc\mfc42\afxdisp.h
#define DISP_PROPERTY_PARAM(theClass, szExternalName, pfnGet, pfnSet, vtPropType, vtsParams) \
	{ _T(szExternalName), DISPID_UNKNOWN, vtsParams, vtPropType, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnGet, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnSet, 0, afxDispCustom }, \
#define DISP_PROPERTY_PARAM_ID(theClass, szExternalName, dispid, pfnGet, pfnSet, vtPropType, vtsParams) \
	{ _T(szExternalName), dispid, vtsParams, vtPropType, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnGet, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnSet, 0, afxDispCustom }, \
#define DECLARE_OLECREATE(class_name) \
public: \
	static AFX_DATA COleObjectFactory factory; \
	static AFX_DATA const GUID guid; \
#define CONNECTION_IID(iid) \
		REFIID GetIID() { return iid; }
#define ON_EVENT(theClass, id, dispid, pfnHandler, vtsParams) \
	{ _T(""), dispid, vtsParams, VT_BOOL, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnHandler, (AFX_PMSG)0, 0, \
		afxDispCustom, id, (UINT)-1 }, \
#define ON_PROPNOTIFY(theClass, id, dispid, pfnRequest, pfnChanged) \
	{ _T(""), dispid, VTS_NONE, VT_VOID, \
		(AFX_PMSG)(BOOL (CCmdTarget::*)(BOOL*))&pfnRequest, \
		(AFX_PMSG)(BOOL (CCmdTarget::*)(void))&pfnChanged, \
		1, afxDispCustom, id, (UINT)-1 }, \
#define ON_EVENT_REFLECT(theClass, dispid, pfnHandler, vtsParams) \
	{ _T(""), dispid, vtsParams, VT_BOOL, \
		(AFX_PMSG)(void (theClass::*)(void))&pfnHandler, (AFX_PMSG)0, 0, \
		afxDispCustom, (UINT)-1, (UINT)-1 }, \
#define ON_PROPNOTIFY_REFLECT(theClass, dispid, pfnRequest, pfnChanged) \
	{ _T(""), dispid, VTS_NONE, VT_VOID, \
		(AFX_PMSG)(BOOL (CCmdTarget::*)(BOOL*))&pfnRequest, \
		(AFX_PMSG)(BOOL (CCmdTarget::*)(void))&pfnChanged, \
		1, afxDispCustom, (UINT)-1, (UINT)-1 }, \

// public\sdk\inc\mfc42\afxmsg_.h
#define ON_WM_MOVE() \
	{ WM_MOVE, 0, 0, 0, AfxSig_vvii, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(int, int))&OnMove },
#define ON_WM_SIZE() \
	{ WM_SIZE, 0, 0, 0, AfxSig_vwii, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, int, int))&OnSize },
#define ON_WM_ACTIVATE() \
	{ WM_ACTIVATE, 0, 0, 0, AfxSig_vwWb, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CWnd*, BOOL))&OnActivate },
#define ON_WM_SETFOCUS() \
	{ WM_SETFOCUS, 0, 0, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*))&OnSetFocus },
#define ON_WM_KILLFOCUS() \
	{ WM_KILLFOCUS, 0, 0, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*))&OnKillFocus },
#define ON_WM_ENABLE() \
	{ WM_ENABLE, 0, 0, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL))&OnEnable },
#define ON_WM_HELPINFO() \
	{ WM_HELP, 0, 0, 0, AfxSig_bHELPINFO, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(HELPINFO*))&OnHelpInfo },
#define ON_WM_PAINT() \
	{ WM_PAINT, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))&OnPaint },
#define ON_WM_QUERYENDSESSION() \
	{ WM_QUERYENDSESSION, 0, 0, 0, AfxSig_bv, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(void))&OnQueryEndSession },
#define ON_WM_QUERYOPEN() \
	{ WM_QUERYOPEN, 0, 0, 0, AfxSig_bv, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(void))&OnQueryOpen },
#define ON_WM_ERASEBKGND() \
	{ WM_ERASEBKGND, 0, 0, 0, AfxSig_bD, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(CDC*))&OnEraseBkgnd },
#define ON_WM_ENDSESSION() \
	{ WM_ENDSESSION, 0, 0, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL))&OnEndSession },
#define ON_WM_ACTIVATEAPP() \
	{ WM_ACTIVATEAPP, 0, 0, 0, AfxSig_vbh, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL, HTASK))&OnActivateApp },
#define ON_WM_FONTCHANGE() \
	{ WM_FONTCHANGE, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))&OnFontChange },
#define ON_WM_CANCELMODE() \
	{ WM_CANCELMODE, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))&OnCancelMode },
#define ON_WM_SETCURSOR() \
	{ WM_SETCURSOR, 0, 0, 0, AfxSig_bWww, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT))&OnSetCursor },
#define ON_WM_MOUSEACTIVATE() \
	{ WM_MOUSEACTIVATE, 0, 0, 0, AfxSig_iWww, \
		(AFX_PMSG)(AFX_PMSGW)(int (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT))&OnMouseActivate },
#define ON_WM_ICONERASEBKGND() \
	{ WM_ICONERASEBKGND, 0, 0, 0, AfxSig_vD, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CDC*))&OnIconEraseBkgnd },
#define ON_WM_QUERYDRAGICON() \
	{ WM_QUERYDRAGICON, 0, 0, 0, AfxSig_hv, \
		(AFX_PMSG)(AFX_PMSGW)(HCURSOR (AFX_MSG_CALL CWnd::*)())&OnQueryDragIcon },
#define ON_WM_NCCALCSIZE() \
	{ WM_NCCALCSIZE, 0, 0, 0, AfxSig_vCALC, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL, NCCALCSIZE_PARAMS*))&OnNcCalcSize },
#define ON_WM_NCPAINT() \
	{ WM_NCPAINT, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))&OnNcPaint },
#define ON_WM_NCACTIVATE() \
	{ WM_NCACTIVATE, 0, 0, 0, AfxSig_bb, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(BOOL))&OnNcActivate },
#define ON_WM_GETDLGCODE() \
	{ WM_GETDLGCODE, 0, 0, 0, AfxSig_wv, \
		(AFX_PMSG)(AFX_PMSGW)(UINT (AFX_MSG_CALL CWnd::*)(void))&OnGetDlgCode },
#define ON_WM_KEYDOWN() \
	{ WM_KEYDOWN, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))&OnKeyDown },
#define ON_WM_KEYUP() \
	{ WM_KEYUP, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))&OnKeyUp },
#define ON_WM_SYSKEYDOWN() \
	{ WM_SYSKEYDOWN, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))&OnSysKeyDown },
#define ON_WM_SYSKEYUP() \
	{ WM_SYSKEYUP, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))&OnSysKeyUp },
#define ON_WM_HSCROLL() \
	{ WM_HSCROLL, 0, 0, 0, AfxSig_vwwW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CScrollBar*))&OnHScroll },
#define ON_WM_VSCROLL() \
	{ WM_VSCROLL, 0, 0, 0, AfxSig_vwwW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CScrollBar*))&OnVScroll },
#define ON_WM_INITMENU() \
	{ WM_INITMENU, 0, 0, 0, AfxSig_vM, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CMenu*))&OnInitMenu },
#define ON_WM_INITMENUPOPUP() \
	{ WM_INITMENUPOPUP, 0, 0, 0, AfxSig_vMwb, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CMenu*, UINT, BOOL))&OnInitMenuPopup },
#define ON_WM_MENUSELECT() \
	{ WM_MENUSELECT, 0, 0, 0, AfxSig_vwwh, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, HMENU))&OnMenuSelect },
#define ON_WM_ENTERIDLE() \
	{ WM_ENTERIDLE, 0, 0, 0, AfxSig_vwW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CWnd*))&OnEnterIdle },
#define ON_WM_PARENTNOTIFY() \
	{ WM_PARENTNOTIFY, 0, 0, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, LPARAM))&OnParentNotify },
#define ON_WM_MDIACTIVATE() \
	{ WM_MDIACTIVATE, 0, 0, 0, AfxSig_vbWW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL, CWnd*, CWnd*))&OnMDIActivate },
#define ON_WM_RENDERFORMAT() \
	{ WM_RENDERFORMAT, 0, 0, 0, AfxSig_vw, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT))&OnRenderFormat },
#define ON_WM_RENDERALLFORMATS() \
	{ WM_RENDERALLFORMATS, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))&OnRenderAllFormats },
#define ON_WM_DRAWCLIPBOARD() \
	{ WM_DRAWCLIPBOARD, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))&OnDrawClipboard },
#define ON_WM_VSCROLLCLIPBOARD() \
	{ WM_VSCROLLCLIPBOARD, 0, 0, 0, AfxSig_vWww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT))&OnVScrollClipboard },
#define ON_WM_HSCROLLCLIPBOARD() \
	{ WM_HSCROLLCLIPBOARD, 0, 0, 0, AfxSig_vWww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT))&OnHScrollClipboard },
#define ON_WM_DROPFILES() \
	{ WM_DROPFILES, 0, 0, 0, AfxSig_vh, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(HDROP))&OnDropFiles },
#define ON_WM_CAPTURECHANGED() \
	{ WM_CAPTURECHANGED, 0, 0, 0, AfxSig_vW2, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*))&OnCaptureChanged },

// public\sdk\inc\mimeole.h
#define HR_CODE(hr) (INT)(hr & 0xffff)
#define PDF_HEADERFORMAT         (0x00000004 | PDF_ENCODED)
#define IAT_KNOWN                (IAT_FROM | IAT_TO | IAT_CC | IAT_BCC | IAT_REPLYTO | IAT_SENDER)
#define IAT_RECIPS               (IAT_TO | IAT_CC | IAT_BCC)

// public\sdk\inc\mmreg.h
#define INIT_MMREG_MID(guid, id)\
{\
    (guid)->Data1 = 0xd5a47fa7 + (USHORT)(id);\
    (guid)->Data2 = 0x6d98;\
    (guid)->Data3 = 0x11d1;\
    (guid)->Data4[0] = 0xa2;\
    (guid)->Data4[1] = 0x1a;\
    (guid)->Data4[2] = 0x00;\
    (guid)->Data4[3] = 0xa0;\
    (guid)->Data4[4] = 0xc9;\
    (guid)->Data4[5] = 0x22;\
    (guid)->Data4[6] = 0x31;\
    (guid)->Data4[7] = 0x96;\
}
#define EXTRACT_MMREG_MID(guid)\
    (USHORT)((guid)->Data1 - 0xd5a47fa7)
#define INIT_MMREG_PID(guid, id)\
{\
    (guid)->Data1 = 0xe36dc2ac + (USHORT)(id);\
    (guid)->Data2 = 0x6d9a;\
    (guid)->Data3 = 0x11d1;\
    (guid)->Data4[0] = 0xa2;\
    (guid)->Data4[1] = 0x1a;\
    (guid)->Data4[2] = 0x00;\
    (guid)->Data4[3] = 0xa0;\
    (guid)->Data4[4] = 0xc9;\
    (guid)->Data4[5] = 0x22;\
    (guid)->Data4[6] = 0x31;\
    (guid)->Data4[7] = 0x96;\
}
#define EXTRACT_MMREG_PID(guid)\
    (USHORT)((guid)->Data1 - 0xe36dc2ac)

// public\sdk\inc\mmsystem.h
#define MIXER_OBJECTF_HMIXER    (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIXER)
#define MIXER_OBJECTF_HWAVEOUT  (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEOUT)
#define MIXER_OBJECTF_HWAVEIN   (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEIN)
#define MIXER_OBJECTF_HMIDIOUT  (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIOUT)
#define MIXER_OBJECTF_HMIDIIN   (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIIN)
#define JOY_RETURNALL           (JOY_RETURNX | JOY_RETURNY | JOY_RETURNZ | \
                                 JOY_RETURNR | JOY_RETURNU | JOY_RETURNV | \
                                 JOY_RETURNPOV | JOY_RETURNBUTTONS)

// public\sdk\inc\mq.h
#define MQCLASS_NACK(c)     ((c) & 0x8000)
#define MQCLASS_RECEIVE(c)  ((c) & 0x4000)
#define MQCLASS_NACK_HTTP(c) (((c) & 0xA000) == 0xA000)

// public\sdk\inc\msoeapi.h
#define HR_CODE(hr) (INT)(hr & 0xffff)

// public\sdk\inc\netmon.h
#define IsRoutingInfoPresent(f) ((((ULPTOKENRING) (f))->SrcAddr[0] & TOKENRING_SA_ROUTING_INFO) ? TRUE : FALSE)

// public\sdk\inc\npapi.h
#define WNNC_CF_DEFAULT ( CONNECT_TEMPORARY | CONNECT_INTERACTIVE | CONNECT_PROMPT )

// public\sdk\inc\nt_vdd.h
#define getMODE() ((getMSW() & MSW_PE) ? VDM_PM : VDM_V86)

// public\sdk\inc\ntalpha.h
#define RF_BEGIN_ADDRESS(RF)      ((RF)->BeginAddress & (~3))
#define RF_END_ADDRESS(RF)        ((RF)->EndAddress & (~3))

// public\sdk\inc\ntconfig.h
#define SERVICE_DRIVER                 (SERVICE_KERNEL_DRIVER | \
                                        SERVICE_FILE_SYSTEM_DRIVER | \
                                        SERVICE_RECOGNIZER_DRIVER)
#define SERVICE_WIN32                  (SERVICE_WIN32_OWN_PROCESS | \
                                        SERVICE_WIN32_SHARE_PROCESS)
#define SERVICE_TYPE_ALL               (SERVICE_WIN32  | \
                                        SERVICE_ADAPTER | \
                                        SERVICE_DRIVER  | \
                                        SERVICE_INTERACTIVE_PROCESS)

// public\sdk\inc\ntcsrsrv.h
#define CSR_SERVER_QUERYCLIENTTHREAD() \
    ((PCSR_THREAD)(NtCurrentTeb()->CsrClientThread))

// public\sdk\inc\ntdd8042.h
#define I8042_SYS_BUTTONS  (I8042_POWER_SYS_BUTTON | \
                            I8042_SLEEP_SYS_BUTTON | \
                            I8042_WAKE_SYS_BUTTON)

// public\sdk\inc\ntdddisk.h
#define IsRecognizedPartition( PartitionType ) (    \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT_12)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_IFS)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_HUGE)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT32)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT32_XINT13)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_XINT13)) ||  \
     ((PartitionType) == PARTITION_FAT_12)          ||  \
     ((PartitionType) == PARTITION_FAT_16)          ||  \
     ((PartitionType) == PARTITION_IFS)             ||  \
     ((PartitionType) == PARTITION_HUGE)            ||  \
     ((PartitionType) == PARTITION_FAT32)           ||  \
     ((PartitionType) == PARTITION_FAT32_XINT13)    ||  \
     ((PartitionType) == PARTITION_XINT13) )
#define IsFTPartition( PartitionType ) \
    (((PartitionType)&PARTITION_NTFT) && IsRecognizedPartition(PartitionType))

// public\sdk\inc\ntddkbd.h
#define ENHANCED_KEYBOARD(Id) ((Id).Type == 2 || (Id).Type == 4 || FAREAST_KEYBOARD(Id))
#define FAREAST_KEYBOARD(Id)  ((Id).Type == 7 || (Id).Type == 8)

// public\sdk\inc\ntddppdt.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// public\sdk\inc\ntddvdeo.h
#define DISPLAYPOLICY_BOTH              (DISPLAYPOLICY_AC | DISPLAYPOLICY_DC)

// public\sdk\inc\ntdef.h
#define DECLSPEC_NORETURN   __declspec(noreturn)
#define PRIMARYLANGID(lgid)    ((USHORT)(lgid) & 0x3ff)

// public\sdk\inc\ntexapi.h
#define EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3) // winnt
#define EVENT_PAIR_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE)
#define KEYEDEVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | KEYEDEVENT_WAIT | KEYEDEVENT_WAKE)

// public\sdk\inc\ntfsprop.h
#define PROPERTY_SPECIFIER_ID(PS,I)      \
    ((PS)->Specifiers[(I)].Id)
#define PROPERTY_ID(p,i)        \
    ((p)->PropertyIds[i])

// public\sdk\inc\ntia64.h
#define RES_FTR(FTR) ((FTR) & 0x000000005555FFC0ULL)

// public\sdk\inc\ntioapi.h
#define FILE_READ_DATA            ( 0x0001 )    // file & pipe
#define FILE_WRITE_DATA           ( 0x0002 )    // file & pipe
#define FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
                                   FILE_READ_DATA           |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_READ_EA             |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
                                   FILE_WRITE_DATA          |\
                                   FILE_WRITE_ATTRIBUTES    |\
                                   FILE_WRITE_EA            |\
                                   FILE_APPEND_DATA         |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_EXECUTE             |\
                                   SYNCHRONIZE)
#define FSCTL_HSM_DATA                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 68, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IsReparseTagMicrosoft(_tag) (              \
                           ((_tag) & 0x80000000)   \
                           )
#define IsReparseTagNameSurrogate(_tag) (          \
                           ((_tag) & 0x20000000)   \
                           )
#define FSCTL_PIPE_TRANSCEIVE           CTL_CODE(FILE_DEVICE_NAMED_PIPE, 5, METHOD_NEITHER,  FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_PIPE_INTERNAL_TRANSCEIVE  CTL_CODE(FILE_DEVICE_NAMED_PIPE, 2047, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)

// public\sdk\inc\ntlpcapi.h
#define PORT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | \
                         SYNCHRONIZE | 0x1)

// public\sdk\inc\ntlsa.h
#define POLICY_READ           (STANDARD_RIGHTS_READ             |\
                               POLICY_VIEW_AUDIT_INFORMATION    |\
                               POLICY_GET_PRIVATE_INFORMATION)
#define POLICY_MODE_ALL_NT4                 (POLICY_MODE_INTERACTIVE | \
                                             POLICY_MODE_NETWORK     | \
                                             POLICY_MODE_BATCH       | \
                                             POLICY_MODE_SERVICE     | \
                                             POLICY_MODE_PROXY )
#define ACCOUNT_ALL_ACCESS    (STANDARD_RIGHTS_REQUIRED         |\
                               ACCOUNT_VIEW                     |\
                               ACCOUNT_ADJUST_PRIVILEGES        |\
                               ACCOUNT_ADJUST_QUOTAS            |\
                               ACCOUNT_ADJUST_SYSTEM_ACCESS)
#define ACCOUNT_READ          (STANDARD_RIGHTS_READ             |\
                               ACCOUNT_VIEW)
#define ACCOUNT_WRITE         (STANDARD_RIGHTS_WRITE            |\
                               ACCOUNT_ADJUST_PRIVILEGES        |\
                               ACCOUNT_ADJUST_QUOTAS            |\
                               ACCOUNT_ADJUST_SYSTEM_ACCESS)
#define TRUSTED_READ           (STANDARD_RIGHTS_READ         |\
                                TRUSTED_QUERY_DOMAIN_NAME)

// public\sdk\inc\ntobapi.h
#define OBJECT_TYPE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define SYMBOLIC_LINK_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)

// public\sdk\inc\ntpsapi.h
#define PROCESS_ALL_ACCESS        (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0xFFF)
#define THREAD_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0x3FF)
#define JOB_OBJECT_ALL_ACCESS       (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                        0x1F )

// public\sdk\inc\ntregapi.h
#define KEY_READ                ((STANDARD_RIGHTS_READ       |\
                                  KEY_QUERY_VALUE            |\
                                  KEY_ENUMERATE_SUB_KEYS     |\
                                  KEY_NOTIFY)                 \
                                  &                           \
                                 (~SYNCHRONIZE))
#define KEY_EXECUTE             ((KEY_READ)                   \
                                  &                           \
                                 (~SYNCHRONIZE))

// public\sdk\inc\ntrtl.h
#define RtlParent(Links) (           \
    (PRTL_SPLAY_LINKS)(Links)->Parent \
    )

// public\sdk\inc\ntsam.h
#define SAM_SERVER_READ       (STANDARD_RIGHTS_READ         |\
                               SAM_SERVER_ENUMERATE_DOMAINS)
#define SAM_SERVER_WRITE      (STANDARD_RIGHTS_WRITE        |\
                               SAM_SERVER_INITIALIZE        |\
                               SAM_SERVER_CREATE_DOMAIN     |\
                               SAM_SERVER_SHUTDOWN)
#define GROUP_EXECUTE    (STANDARD_RIGHTS_EXECUTE   |\
                          GROUP_READ_INFORMATION)
#define ALIAS_EXECUTE    (STANDARD_RIGHTS_EXECUTE   |\
                          ALIAS_READ_INFORMATION)

// public\sdk\inc\ntseapi.h
#define TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED  |\
                          TOKEN_ASSIGN_PRIMARY      |\
                          TOKEN_DUPLICATE           |\
                          TOKEN_IMPERSONATE         |\
                          TOKEN_QUERY               |\
                          TOKEN_QUERY_SOURCE        |\
                          TOKEN_ADJUST_PRIVILEGES   |\
                          TOKEN_ADJUST_GROUPS       |\
                          TOKEN_ADJUST_DEFAULT )
#define TOKEN_ALL_ACCESS  (TOKEN_ALL_ACCESS_P |\
                          TOKEN_ADJUST_SESSIONID )
#define TOKEN_READ       (STANDARD_RIGHTS_READ      |\
                          TOKEN_QUERY)
#define TOKEN_WRITE      (STANDARD_RIGHTS_WRITE     |\
                          TOKEN_ADJUST_PRIVILEGES   |\
                          TOKEN_ADJUST_GROUPS       |\
                          TOKEN_ADJUST_DEFAULT)

// public\sdk\inc\nturtl.h
#define RtlGetPerThreadCurdir() \
    ((PRTL_PERTHREAD_CURDIR)(NtCurrentTeb()->NtTib.SubSystemTib))

// public\sdk\inc\ntverp.h
#define VER_PRODUCTVERSION_DW       (0x05010000 | VER_PRODUCTBUILD)

// public\sdk\inc\ntxcapi.h
#define EXCEPTION_UNWIND (EXCEPTION_UNWINDING | EXCEPTION_EXIT_UNWIND | \
                          EXCEPTION_TARGET_UNWIND | EXCEPTION_COLLIDED_UNWIND)

// public\sdk\inc\odbcss.h
#define SQL_CO_FFO_AF	(SQL_CO_FFO|SQL_CO_AF)	//	Fast-forward cursor with autofetch

// public\sdk\inc\oleauto.h
#define V_ISBYREF(X)     (V_VT(X)&VT_BYREF)
#define V_ISVECTOR(X)    (V_VT(X)&VT_VECTOR)

// public\sdk\inc\oleidl.h
#define	UPDFCACHE_IFBLANKORONSAVECACHE	( UPDFCACHE_IFBLANK | UPDFCACHE_ONSAVECACHE )

// public\sdk\inc\otrack.hxx
#  define TRACK_CLASS(fTrack, cls) \
                      CRefcountedObject::TrackClass( fTrack, cls )

// public\sdk\inc\penwin.h
#define ALC_PUNC             0x00000008L // !-;`"?()&.,; and backslash
#define ALC_MATH             0x00000010L // %^*()-+={}<>,/.
#define TRAIN_BOTH              (TRAIN_DEFAULT | TRAIN_CUSTOM)
#define PCMR_SELECT             (-12)   // ret because of tap & hold
#define IE_MSGFIRST           (WM_USER+150)     // 0x496 == 1174
#define FIsSelectGesture(syv)   \
   ((syv) >= SYVSELECTFIRST && (syv) <= SYVSELECTLAST)

// public\sdk\inc\posix\sys\wait.h
#define WIFEXITED(stat_val)	\
	(((stat_val) & 0xff) == 0)
#define WIFSIGNALED(stat_val)	\
	(!WIFSTOPPED(stat_val) && !WIFEXITED(stat_val))
#define WTERMSIG(stat_val)	\
	((stat_val) & 0xff)
#define WIFSTOPPED(stat_val)	\
	(((stat_val) & 0xff) == 0177)

// public\sdk\inc\prsht.h
#define PSM_SETCURSEL           (WM_USER + 101)
#define PSM_CHANGED             (WM_USER + 104)
#define PSM_REBOOTSYSTEM        (WM_USER + 106)
#define PSM_QUERYSIBLINGS       (WM_USER + 108)
#define PSM_UNCHANGED           (WM_USER + 109)
#define PSM_APPLY               (WM_USER + 110)
#define PSM_SETTITLEA           (WM_USER + 111)
#define PSM_SETTITLEW           (WM_USER + 120)
#define PSM_SETWIZBUTTONS       (WM_USER + 112)
#define PSM_PRESSBUTTON         (WM_USER + 113)
#define PSM_SETCURSELID         (WM_USER + 114)
#define PSM_SETHEADERTITLEA     (WM_USER + 125)
#define PSM_SETHEADERTITLEW     (WM_USER + 126)
#define PSM_SETHEADERSUBTITLEA     (WM_USER + 127)
#define PSM_SETHEADERSUBTITLEW     (WM_USER + 128)
#define PSM_IDTOINDEX              (WM_USER + 133)
#define PSM_INDEXTOID              (WM_USER + 134)
#define PSM_GETRESULT              (WM_USER + 135)

// public\sdk\inc\pwin16.h
#define GET_WM_MENUSELECT_CMD(wp, lp)               (wp)
#define GET_WM_PARENTNOTIFY_MSG(wp, lp)             (wp)
#define GET_WM_VKEYTOITEM_CODE(wp, lp)              (wp)
#define GET_WM_HSCROLL_CODE(wp, lp)                 (wp)
#define GET_WM_VSCROLL_CODE(wp, lp)                 (wp)

// public\sdk\inc\pwin32.h
#define GET_WM_MENUSELECT_HMENU(wp, lp)             (HMENU)(lp)
#define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW) (WPARAM)hmenuF, (LPARAM)hmenuW
#define GET_WM_DDE_EXECUTE_HDATA(wp, lp)            ((HANDLE)lp)
#define MPostWM_DDE_EXECUTE(hTo, hFrom, hDataExec) \
        PostMessage(hTo, WM_DDE_EXECUTE, (WPARAM)hFrom, (LPARAM)hDataExec)
#define GETMAJORVERSION(x)                  ((x)&0xff)

// public\sdk\inc\richedit.h
#define EM_SCROLLCARET			(WM_USER + 49)
#define EM_CANPASTE				(WM_USER + 50)
#define EM_DISPLAYBAND			(WM_USER + 51)
#define EM_EXGETSEL				(WM_USER + 52)
#define EM_EXSETSEL				(WM_USER + 55)
#define EM_GETPARAFORMAT		(WM_USER + 61)
#define EM_PASTESPECIAL			(WM_USER + 64)
#define EM_SELECTIONTYPE		(WM_USER + 66)
#define EM_SETOLECALLBACK		(WM_USER + 70)
#define EM_SETPARAFORMAT		(WM_USER + 71)
#define EM_SETTARGETDEVICE		(WM_USER + 72)
#define EM_SETOPTIONS			(WM_USER + 77)
#define EM_GETOPTIONS			(WM_USER + 78)
#define	EM_SETUNDOLIMIT			(WM_USER + 82)
#define EM_REDO					(WM_USER + 84)
#define EM_CANREDO				(WM_USER + 85)
#define EM_GETUNDONAME			(WM_USER + 86)
#define EM_GETREDONAME			(WM_USER + 87)
#define EM_STOPGROUPTYPING		(WM_USER + 88)
#define EM_AUTOURLDETECT		(WM_USER + 91)
#define EM_GETAUTOURLDETECT		(WM_USER + 92)
#define EM_SHOWSCROLLBAR		(WM_USER + 96)
#define EM_SETPUNCTUATION		(WM_USER + 100)
#define EM_GETPUNCTUATION		(WM_USER + 101)
#define EM_CONVPOSITION 		(WM_USER + 108)
#define EM_SETLANGOPTIONS		(WM_USER + 120)
#define EM_GETLANGOPTIONS		(WM_USER + 121)
#define EM_RECONVERSION			(WM_USER + 125)
#define EM_SETBIDIOPTIONS		(WM_USER + 200)
#define EM_GETBIDIOPTIONS		(WM_USER + 201)
#define EM_SETTYPOGRAPHYOPTIONS	(WM_USER + 202)
#define EM_GETTYPOGRAPHYOPTIONS	(WM_USER + 203)
#define EM_SETEDITSTYLE			(WM_USER + 204)
#define EM_GETEDITSTYLE			(WM_USER + 205)
#define EM_OUTLINE              (WM_USER + 220)
#define EM_GETSCROLLPOS         (WM_USER + 221)
#define EM_SETSCROLLPOS         (WM_USER + 222)
#define EM_SETFONTSIZE          (WM_USER + 223)
#define EM_GETZOOM				(WM_USER + 224)
#define EM_SETZOOM				(WM_USER + 225)
#define EM_GETVIEWKIND			(WM_USER + 226)
#define EM_SETVIEWKIND			(WM_USER + 227)
#define EM_GETHYPHENATEINFO		(WM_USER + 230)
#define EM_SETHYPHENATEINFO		(WM_USER + 231)
#define EM_GETCTFMODEBIAS		(WM_USER + 237)
#define EM_SETCTFMODEBIAS		(WM_USER + 238)
#define EM_ISIME				(WM_USER + 243)
#define PFM_ALL2	(PFM_ALL | PFM_EFFECTS | PFM_SPACEBEFORE | PFM_SPACEAFTER \
					| PFM_LINESPACING | PFM_STYLE | PFM_SHADING | PFM_BORDER \
					| PFM_NUMBERINGTAB | PFM_NUMBERINGSTART | PFM_NUMBERINGSTYLE)

// public\sdk\inc\routprot.h
#define PROTO_FROM_PROTO_ID(X)      ((X) & 0xFFFF)

// public\sdk\inc\rpcdce.h
#define DECLSPEC_NORETURN   __declspec(noreturn)

// public\sdk\inc\rpcproxy.h
#define REFERENCE_PROXY_FILE(name)  \
    & name##_ProxyFileInfo

// public\sdk\inc\rtccore.h
#define RTCMT_ALL_RTP   (       \
         RTCMT_AUDIO_SEND    |  \
         RTCMT_AUDIO_RECEIVE  | \
         RTCMT_VIDEO_SEND  |    \
         RTCMT_VIDEO_RECEIVE )
#define RTCMT_ALL       (       \
         RTCMT_ALL_RTP    |     \
         RTCMT_T120_SENDRECV  )

// public\sdk\inc\schannel.h
#define SP_PROT_PCT1                    (SP_PROT_PCT1_SERVER | SP_PROT_PCT1_CLIENT)
#define SP_PROT_SSL2                    (SP_PROT_SSL2_SERVER | SP_PROT_SSL2_CLIENT)
#define SP_PROT_SSL3                    (SP_PROT_SSL3_SERVER | SP_PROT_SSL3_CLIENT)
#define SP_PROT_TLS1                    (SP_PROT_TLS1_SERVER | SP_PROT_TLS1_CLIENT)
#define SP_PROT_SSL3TLS1_CLIENTS        (SP_PROT_TLS1_CLIENT | SP_PROT_SSL3_CLIENT)
#define SP_PROT_SSL3TLS1_SERVERS        (SP_PROT_TLS1_SERVER | SP_PROT_SSL3_SERVER)
#define SP_PROT_SSL3TLS1                (SP_PROT_SSL3 | SP_PROT_TLS1)
#define SP_PROT_UNI                     (SP_PROT_UNI_SERVER | SP_PROT_UNI_CLIENT)
#define SP_PROT_CLIENTS                 (SP_PROT_PCT1_CLIENT | SP_PROT_SSL2_CLIENT | SP_PROT_SSL3_CLIENT | SP_PROT_UNI_CLIENT | SP_PROT_TLS1_CLIENT)
#define SP_PROT_SERVERS                 (SP_PROT_PCT1_SERVER | SP_PROT_SSL2_SERVER | SP_PROT_SSL3_SERVER | SP_PROT_UNI_SERVER | SP_PROT_TLS1_SERVER)

// public\sdk\inc\setupapi.h
#define FLG_ADDREG_TYPE_BINARY      ( 0x00000000 | FLG_ADDREG_BINVALUETYPE )
#define FLG_ADDREG_TYPE_NONE        ( 0x00020000 | FLG_ADDREG_BINVALUETYPE )

// public\sdk\inc\shlwapi.h
#define UrlEscapeSpaces(pszUrl, pszEscaped, pcchEscaped)        UrlCanonicalize(pszUrl, pszEscaped, pcchEscaped, URL_ESCAPE_SPACES_ONLY |URL_DONT_ESCAPE_EXTRA_INFO )
#define SHGVSPB_FOLDER              (SHGVSPB_PERUSER | SHGVSPB_PERFOLDER)
#define SHGVSPB_FOLDERNODEFAULTS    (SHGVSPB_PERUSER | SHGVSPB_PERFOLDER | SHGVSPB_NOAUTODEFAULTS)
#define SHGVSPB_USERDEFAULTS        (SHGVSPB_PERUSER | SHGVSPB_ALLFOLDERS)
#define SHACF_DEFAULT                   0x00000000  // Currently (SHACF_FILESYSTEM | SHACF_URLALL)

// public\sdk\inc\simpdata.h
#define OSP_IndexAll        (~0)
#define OSP_IndexUnknown    (~0)

// public\sdk\inc\snmp.h
#define ASN_INTEGER                 (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x02)
#define ASN_OBJECTIDENTIFIER        (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x06)
#define ASN_IPADDRESS               (ASN_APPLICATION | ASN_PRIMITIVE | 0x00)
#define ASN_COUNTER32               (ASN_APPLICATION | ASN_PRIMITIVE | 0x01)
#define ASN_GAUGE32                 (ASN_APPLICATION | ASN_PRIMITIVE | 0x02)
#define ASN_OPAQUE                  (ASN_APPLICATION | ASN_PRIMITIVE | 0x04)
#define ASN_COUNTER64               (ASN_APPLICATION | ASN_PRIMITIVE | 0x06)
#define ASN_UNSIGNED32              (ASN_APPLICATION | ASN_PRIMITIVE | 0x07)

// public\sdk\inc\sql.h
#define SQL_SUCCEEDED(rc) (((rc)&(~1))==0)

// public\sdk\inc\sqlext.h
#define SQL_IK_ALL							(SQL_IK_ASC | SQL_IK_DESC)

// public\sdk\inc\stdobj.hxx
#define NOTDELEGATED(ulDelta)	((ulDelta & ITF_SUPPORTED)!=0)
#define QIREQUIRED(ulDelta)	((ulDelta & ITF_NO_QI)==0)
#define GETDELTA(ulDelta)	(ulDelta & 0x3FFFFFFFL)
#define BEGIN_CLASS(cls)				\
	cls##CF CLASSFACTORY_NAME(cls);			\
							\
	CLASSDESCRIPTOR CLASSDESCRIPTOR_NAME(cls) = {	\
		&CLSID_##cls,				\
		#cls,    				\
		(IClassFactory*)&gcf##cls##Factory,	\
		{

// public\sdk\inc\syssetup.h
#define ISDC(x) ((x) & 1)

// public\sdk\inc\tuple.h
#define PowerInformation(X)    (X & 0x03)

// public\sdk\inc\unimodem.h
    #define RAWDIAGNOSTICS_DATA_SIZE(_praw_diagnostics_hdr)                 \
            ((_praw_diagnostics_hdr)->dwParam)
    #define PARSEDDIAGNOSTICS_NUM_ITEMS(_pparsed_diagnostics_hdr)           \
            ((_pparsed_diagnostics_hdr)->dwParam)

// public\sdk\inc\uxtheme.h
#define HTTB_RESIZINGBORDER         (HTTB_RESIZINGBORDER_LEFT|HTTB_RESIZINGBORDER_TOP|\
                                     HTTB_RESIZINGBORDER_RIGHT|HTTB_RESIZINGBORDER_BOTTOM)

// public\sdk\inc\vfw.h
#define AVIIF_MIDPART       (AVIIF_LASTPART|AVIIF_FIRSTPART)
#define MCIWNDM_GETDEVICEID	(WM_USER + 100)
#define MCIWNDM_GETSTART	(WM_USER + 103)
#define MCIWNDM_GETLENGTH	(WM_USER + 104)
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
#define MCIWNDM_PLAYFROM	(WM_USER + 122)
#define MCIWNDM_PLAYTO          (WM_USER + 123)
#define MCIWNDM_CHANGESTYLES	(WM_USER + 135)
#define MCIWNDM_GETSTYLES	(WM_USER + 136)
#define MCIWNDM_GETALIAS	(WM_USER + 137)
#define MCIWNDM_PLAYREVERSE	(WM_USER + 139)
#define MCIWNDM_GET_SOURCE      (WM_USER + 140)
#define MCIWNDM_PUT_SOURCE      (WM_USER + 141)
#define MCIWNDM_GET_DEST        (WM_USER + 142)
#define MCIWNDM_PUT_DEST        (WM_USER + 143)
#define MCIWNDM_CAN_PLAY        (WM_USER + 144)
#define MCIWNDM_CAN_SAVE        (WM_USER + 147)
#define MCIWNDM_CAN_EJECT       (WM_USER + 148)
#define MCIWNDM_CAN_CONFIG      (WM_USER + 149)
#define MCIWNDM_SETOWNER	(WM_USER + 152)
#define MCIWNDM_GETPOSITIONA	(WM_USER + 102)
#define MCIWNDM_GETMODEA	(WM_USER + 106)
#define MCIWNDM_GETFILENAMEA    (WM_USER + 124)
#define MCIWNDM_GETDEVICEA      (WM_USER + 125)
#define MCIWNDM_NEWA		(WM_USER + 134)
#define MCIWNDM_OPENA		(WM_USER + 153)
#define MCIWNDM_GETPOSITIONW	(WM_USER + 202)
#define MCIWNDM_GETMODEW	(WM_USER + 206)
#define MCIWNDM_GETFILENAMEW    (WM_USER + 224)
#define MCIWNDM_GETDEVICEW      (WM_USER + 225)
#define MCIWNDM_NEWW		(WM_USER + 234)
#define MCIWNDM_OPENW		(WM_USER + 252)

// public\sdk\inc\wdm.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe
#define FILE_READ_DATA            ( 0x0001 )    // file & pipe
#define FILE_WRITE_DATA           ( 0x0002 )    // file & pipe
#define FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
                                   FILE_READ_DATA           |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_READ_EA             |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
                                   FILE_WRITE_DATA          |\
                                   FILE_WRITE_ATTRIBUTES    |\
                                   FILE_WRITE_EA            |\
                                   FILE_APPEND_DATA         |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_EXECUTE             |\
                                   SYNCHRONIZE)
#define KEY_READ                ((STANDARD_RIGHTS_READ       |\
                                  KEY_QUERY_VALUE            |\
                                  KEY_ENUMERATE_SUB_KEYS     |\
                                  KEY_NOTIFY)                 \
                                  &                           \
                                 (~SYNCHRONIZE))
#define KEY_EXECUTE             ((KEY_READ)                   \
                                  &                           \
                                 (~SYNCHRONIZE))
#define OBJECT_TYPE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define SYMBOLIC_LINK_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define PROCESS_ALL_ACCESS        (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0xFFF)
#define THREAD_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0x3FF)
#define EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#define SERVICE_DRIVER                 (SERVICE_KERNEL_DRIVER | \
                                        SERVICE_FILE_SYSTEM_DRIVER | \
                                        SERVICE_RECOGNIZER_DRIVER)
#define SERVICE_WIN32                  (SERVICE_WIN32_OWN_PROCESS | \
                                        SERVICE_WIN32_SHARE_PROCESS)
#define SERVICE_TYPE_ALL               (SERVICE_WIN32  | \
                                        SERVICE_ADAPTER | \
                                        SERVICE_DRIVER  | \
                                        SERVICE_INTERACTIVE_PROCESS)
#define IoInitializeDpcRequest( DeviceObject, DpcRoutine ) (\
    KeInitializeDpc( &(DeviceObject)->Dpc,                  \
                     (PKDEFERRED_ROUTINE) (DpcRoutine),     \
                     (DeviceObject) ) )

// public\sdk\inc\wfext.h
#define FM_GETFOCUS           (WM_USER + 0x0200)
#define FM_GETSELCOUNT        (WM_USER + 0x0202)
#define FM_GETSELCOUNTLFN     (WM_USER + 0x0203)  /* LFN versions are odd */
#define FM_GETDRIVEINFOA      (WM_USER + 0x0201)
#define FM_GETFILESELA        (WM_USER + 0x0204)
#define FM_GETFILESELLFNA     (WM_USER + 0x0205)  /* LFN versions are odd */
#define FM_GETDRIVEINFOW      (WM_USER + 0x0211)
#define FM_GETFILESELW        (WM_USER + 0x0214)
#define FM_GETFILESELLFNW     (WM_USER + 0x0215)  /* LFN versions are odd */

// public\sdk\inc\wiadef.h
#define WIA_PROP_RW              (WIA_PROP_READ | WIA_PROP_WRITE)

// public\sdk\inc\wincrypt.h
#define GET_ALG_SID(x)                  (x & (511))
#define CALG_MD2                (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD2)
#define CALG_MD4                (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD4)
#define CALG_MD5                (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD5)
#define CALG_SHA                (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA)
#define CALG_SHA1               (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA1)
#define CALG_MAC                (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MAC)
#define CALG_RSA_SIGN           (ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA_ANY)
#define CALG_DSS_SIGN           (ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_DSS_ANY)
#define CALG_NO_SIGN            (ALG_CLASS_SIGNATURE | ALG_TYPE_ANY | ALG_SID_ANY)
#define CALG_RSA_KEYX           (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_RSA|ALG_SID_RSA_ANY)
#define CALG_DH_SF              (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_DH_SANDF)
#define CALG_DH_EPHEM           (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_DH_EPHEM)
#define CALG_AGREEDKEY_ANY      (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_AGREED_KEY_ANY)
#define CALG_KEA_KEYX           (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_KEA)
#define CALG_HUGHES_MD5         (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_ANY|ALG_SID_MD5)
#define CALG_SSL3_SHAMD5        (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SSL3SHAMD5)
#define CALG_HMAC               (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_HMAC)
#define CALG_TLS1PRF            (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_TLS1PRF)
#define CALG_HASH_REPLACE_OWF   (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_HASH_REPLACE_OWF)

// public\sdk\inc\winfax.h
#define FAX_READ                (STANDARD_RIGHTS_READ        |\
                                 FAX_JOB_QUERY               |\
                                 FAX_CONFIG_QUERY            |\
                                 FAX_PORT_QUERY)
#define FAX_WRITE               (STANDARD_RIGHTS_WRITE       |\
                                 FAX_JOB_SUBMIT )
#define FAX_ALL_ACCESS          (STANDARD_RIGHTS_ALL         |\
                                 FAX_JOB_SUBMIT              |\
                                 FAX_JOB_QUERY               |\
                                 FAX_CONFIG_QUERY            |\
                                 FAX_CONFIG_SET              |\
                                 FAX_PORT_QUERY              |\
                                 FAX_PORT_SET                |\
                                 FAX_JOB_MANAGE)

// public\sdk\inc\winioctl.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe
#define IsRecognizedPartition( PartitionType ) (    \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT_12)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_IFS)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_HUGE)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT32)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT32_XINT13)) ||  \
     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_XINT13)) ||  \
     ((PartitionType) == PARTITION_FAT_12)          ||  \
     ((PartitionType) == PARTITION_FAT_16)          ||  \
     ((PartitionType) == PARTITION_IFS)             ||  \
     ((PartitionType) == PARTITION_HUGE)            ||  \
     ((PartitionType) == PARTITION_FAT32)           ||  \
     ((PartitionType) == PARTITION_FAT32_XINT13)    ||  \
     ((PartitionType) == PARTITION_XINT13) )
#define IsFTPartition( PartitionType ) \
    (((PartitionType)&PARTITION_NTFT) && IsRecognizedPartition(PartitionType))
#define FSCTL_HSM_DATA                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 68, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)

// public\sdk\inc\winldap.h
#define LDAP_AUTH_SICILY                (LDAP_AUTH_OTHERKIND | 0x0200)
#define LDAP_AUTH_MSN                   (LDAP_AUTH_OTHERKIND | 0x0800)
#define LDAP_AUTH_NTLM                  (LDAP_AUTH_OTHERKIND | 0x1000)
#define LDAP_AUTH_DPA                   (LDAP_AUTH_OTHERKIND | 0x2000)
#define LDAP_AUTH_NEGOTIATE             (LDAP_AUTH_OTHERKIND | 0x0400)
#define LDAP_AUTH_DIGEST                (LDAP_AUTH_OTHERKIND | 0x4000)
#define LDAP_AUTH_EXTERNAL              (LDAP_AUTH_OTHERKIND | 0x0020)

// public\sdk\inc\winnt.h
#define DECLSPEC_NORETURN   __declspec(noreturn)
#define TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED  |\
                          TOKEN_ASSIGN_PRIMARY      |\
                          TOKEN_DUPLICATE           |\
                          TOKEN_IMPERSONATE         |\
                          TOKEN_QUERY               |\
                          TOKEN_QUERY_SOURCE        |\
                          TOKEN_ADJUST_PRIVILEGES   |\
                          TOKEN_ADJUST_GROUPS       |\
                          TOKEN_ADJUST_DEFAULT )
#define TOKEN_ALL_ACCESS  (TOKEN_ALL_ACCESS_P |\
                          TOKEN_ADJUST_SESSIONID )
#define TOKEN_READ       (STANDARD_RIGHTS_READ      |\
                          TOKEN_QUERY)
#define TOKEN_WRITE      (STANDARD_RIGHTS_WRITE     |\
                          TOKEN_ADJUST_PRIVILEGES   |\
                          TOKEN_ADJUST_GROUPS       |\
                          TOKEN_ADJUST_DEFAULT)
#define PROCESS_ALL_ACCESS        (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0xFFF)
#define THREAD_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                   0x3FF)
#define JOB_OBJECT_ALL_ACCESS       (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | \
                                        0x1F )
#define EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#define FILE_READ_DATA            ( 0x0001 )    // file & pipe
#define FILE_WRITE_DATA           ( 0x0002 )    // file & pipe
#define FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
                                   FILE_READ_DATA           |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_READ_EA             |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
                                   FILE_WRITE_DATA          |\
                                   FILE_WRITE_ATTRIBUTES    |\
                                   FILE_WRITE_EA            |\
                                   FILE_APPEND_DATA         |\
                                   SYNCHRONIZE)
#define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_EXECUTE             |\
                                   SYNCHRONIZE)
#define IsReparseTagMicrosoft(_tag) (              \
                           ((_tag) & 0x80000000)   \
                           )
#define IsReparseTagNameSurrogate(_tag) (          \
                           ((_tag) & 0x20000000)   \
                           )
#define KEY_READ                ((STANDARD_RIGHTS_READ       |\
                                  KEY_QUERY_VALUE            |\
                                  KEY_ENUMERATE_SUB_KEYS     |\
                                  KEY_NOTIFY)                 \
                                  &                           \
                                 (~SYNCHRONIZE))
#define KEY_EXECUTE             ((KEY_READ)                   \
                                  &                           \
                                 (~SYNCHRONIZE))
#define SERVICE_DRIVER                 (SERVICE_KERNEL_DRIVER | \
                                        SERVICE_FILE_SYSTEM_DRIVER | \
                                        SERVICE_RECOGNIZER_DRIVER)
#define SERVICE_WIN32                  (SERVICE_WIN32_OWN_PROCESS | \
                                        SERVICE_WIN32_SHARE_PROCESS)
#define SERVICE_TYPE_ALL               (SERVICE_WIN32  | \
                                        SERVICE_ADAPTER | \
                                        SERVICE_DRIVER  | \
                                        SERVICE_INTERACTIVE_PROCESS)

// public\sdk\inc\winscard.h
#define SCARD_PCI_T0  (&g_rgSCardT0Pci)
#define SCARD_PCI_T1  (&g_rgSCardT1Pci)
#define SCARD_PCI_RAW (&g_rgSCardRawPci)

// public\sdk\inc\winsmcrd.h
#define SCARD_PROTOCOL_Tx           (SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1)

// public\sdk\inc\winsnmp.h
#define SNMP_SYNTAX_INT       (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x02)
#define SNMP_SYNTAX_OCTETS    (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x04)
#define SNMP_SYNTAX_OID       (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x06)
#define SNMP_SYNTAX_IPADDR    (ASN_APPLICATION | ASN_PRIMITIVE | 0x00)
#define SNMP_SYNTAX_CNTR32    (ASN_APPLICATION | ASN_PRIMITIVE | 0x01)
#define SNMP_SYNTAX_GAUGE32   (ASN_APPLICATION | ASN_PRIMITIVE | 0x02)
#define SNMP_SYNTAX_OPAQUE    (ASN_APPLICATION | ASN_PRIMITIVE | 0x04)
#define SNMP_SYNTAX_NSAPADDR  (ASN_APPLICATION | ASN_PRIMITIVE | 0x05)
#define SNMP_SYNTAX_CNTR64    (ASN_APPLICATION | ASN_PRIMITIVE | 0x06)
#define SNMP_SYNTAX_UINT32    (ASN_APPLICATION | ASN_PRIMITIVE | 0x07)

// public\sdk\inc\winsock.h
#define IOC_INOUT       (IOC_IN|IOC_OUT)
#define IPPROTO_GGP             3               /* gateway^2 (deprecated) */
#define SO_DONTLINGER   (u_int)(~SO_LINGER)

// public\sdk\inc\winsock2.h
#define IOC_INOUT       (IOC_IN|IOC_OUT)
#define IPPROTO_GGP             3               /* gateway^2 (deprecated) */
#define SO_DONTLINGER   (int)(~SO_LINGER)
#define _WSAIO(x,y)                   (IOC_VOID|(x)|(y))
#define _WSAIOR(x,y)                  (IOC_OUT|(x)|(y))
#define _WSAIOW(x,y)                  (IOC_IN|(x)|(y))
#define _WSAIORW(x,y)                 (IOC_INOUT|(x)|(y))

// public\sdk\inc\winspool.h
#define SERVER_READ          (STANDARD_RIGHTS_READ          |\
                              SERVER_ACCESS_ENUMERATE)
#define SERVER_EXECUTE       (STANDARD_RIGHTS_EXECUTE       |\
                              SERVER_ACCESS_ENUMERATE)
#define JOB_READ               (STANDARD_RIGHTS_READ        |\
                                JOB_ACCESS_READ)

// public\sdk\inc\winuser.h
#define WVR_REDRAW         (WVR_HREDRAW | \
                            WVR_VREDRAW)
#define BDR_OUTER       (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#define BDR_INNER       (BDR_RAISEDINNER | BDR_SUNKENINNER)
#define BDR_RAISED      (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#define BDR_SUNKEN      (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#define EDGE_RAISED     (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#define EDGE_SUNKEN     (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#define EDGE_ETCHED     (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#define EDGE_BUMP       (BDR_RAISEDOUTER | BDR_SUNKENINNER)
#define BF_TOPLEFT      (BF_TOP | BF_LEFT)
#define BF_TOPRIGHT     (BF_TOP | BF_RIGHT)
#define BF_BOTTOMLEFT   (BF_BOTTOM | BF_LEFT)
#define BF_BOTTOMRIGHT  (BF_BOTTOM | BF_RIGHT)
#define BF_DIAGONAL_ENDTOPRIGHT     (BF_DIAGONAL | BF_TOP | BF_RIGHT)
#define BF_DIAGONAL_ENDTOPLEFT      (BF_DIAGONAL | BF_TOP | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMLEFT   (BF_DIAGONAL | BF_BOTTOM | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMRIGHT  (BF_DIAGONAL | BF_BOTTOM | BF_RIGHT)
#define FLASHW_ALL          (FLASHW_CAPTION | FLASHW_TRAY)
#define QS_MOUSE           (QS_MOUSEMOVE     | \
                            QS_MOUSEBUTTON)
#define QS_INPUT           (QS_MOUSE         | \
                            QS_KEY           | \
                            QS_RAWINPUT)
#define QS_INPUT           (QS_MOUSE         | \
                            QS_KEY)
#define DM_GETDEFID         (WM_USER+0)
#define DM_SETDEFID         (WM_USER+1)
#define DM_REPOSITION       (WM_USER+2)
#define LBS_STANDARD          (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)
#define GET_RAWINPUT_CODE_WPARAM(wParam)    ((wParam) & 0xff)

// public\sdk\inc\winuser.rh
#define WVR_REDRAW         (WVR_HREDRAW | \
                            WVR_VREDRAW)
#define LBS_STANDARD          (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

// public\sdk\inc\winwlx.h
#define WLX_WM_SAS                  (WM_USER + 601)

// public\sdk\inc\wtl10\atlapp.h
#define REFLECTED_NOTIFY_HANDLER(id, cd, func) \
	if(uMsg == OCM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom && cd == ((LPNMHDR)lParam)->code) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define REFLECTED_NOTIFY_ID_HANDLER(id, func) \
	if(uMsg == OCM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define REFLECTED_NOTIFY_CODE_HANDLER(cd, func) \
	if(uMsg == OCM_NOTIFY && cd == ((LPNMHDR)lParam)->code) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}

// public\sdk\inc\wtl10\atlcrack.h
#define MESSAGE_HANDLER_EX(msg, func) \
	if(uMsg == msg) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func(uMsg, wParam, lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define REFLECTED_NOTIFY_HANDLER_EX(id, cd, func) \
	if (uMsg == OCM_NOTIFY && cd == ((LPNMHDR)lParam)->code && id == ((LPNMHDR)lParam)->idFrom) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define REFLECTED_NOTIFY_ID_HANDLER_EX(id, func) \
	if (uMsg == OCM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define REFLECTED_NOTIFY_CODE_HANDLER_EX(cd, func) \
	if (uMsg == OCM_NOTIFY && cd == ((LPNMHDR)lParam)->code) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}

// published\sdk\inc\alphaops.h
#define BPT_FUNC       (UNPRIV_PAL_FUNC | 0x00)
#define CALLSYS_FUNC   (UNPRIV_PAL_FUNC | 0x03)
#define IMB_FUNC       (UNPRIV_PAL_FUNC | 0x06)
#define GENTRAP_FUNC   (UNPRIV_PAL_FUNC | 0xAA)
#define RDTEB_FUNC     (UNPRIV_PAL_FUNC | 0xAB)
#define KBPT_FUNC      (UNPRIV_PAL_FUNC | 0xAC)
#define CALLKD_FUNC    (UNPRIV_PAL_FUNC | 0xAD)
#define RDTEB64_FUNC   (UNPRIV_PAL_FUNC | 0xAE)
#define HALT_FUNC       (PRIV_PAL_FUNC | 0x00)
#define RESTART_FUNC    (PRIV_PAL_FUNC | 0x01)
#define DRAINA_FUNC     (PRIV_PAL_FUNC | 0x02)
#define REBOOT_FUNC     (PRIV_PAL_FUNC | 0x03)
#define INITPAL_FUNC    (PRIV_PAL_FUNC | 0x04)
#define SWPIRQL_FUNC    (PRIV_PAL_FUNC | 0x06)
#define RDIRQL_FUNC     (PRIV_PAL_FUNC | 0x07)
#define DI_FUNC         (PRIV_PAL_FUNC | 0X08)
#define EI_FUNC         (PRIV_PAL_FUNC | 0x09)
#define SWPPAL_FUNC     (PRIV_PAL_FUNC | 0x0A)
#define SSIR_FUNC       (PRIV_PAL_FUNC | 0x0C)
#define CSIR_FUNC       (PRIV_PAL_FUNC | 0x0D)
#define RFE_FUNC        (PRIV_PAL_FUNC | 0x0E)
#define RETSYS_FUNC     (PRIV_PAL_FUNC | 0x0F)
#define SWPCTX_FUNC     (PRIV_PAL_FUNC | 0x10)
#define SWPPROCESS_FUNC (PRIV_PAL_FUNC | 0x11)
#define RDMCES_FUNC     (PRIV_PAL_FUNC | 0x12)
#define WRMCES_FUNC     (PRIV_PAL_FUNC | 0x13)
#define TBIA_FUNC       (PRIV_PAL_FUNC | 0x14)
#define TBISASN_FUNC    (PRIV_PAL_FUNC | 0x17)
#define RDKSP_FUNC      (PRIV_PAL_FUNC | 0x18)
#define SWPKSP_FUNC     (PRIV_PAL_FUNC | 0x19)
#define RDPSR_FUNC      (PRIV_PAL_FUNC | 0x1A)
#define RDPCR_FUNC      (PRIV_PAL_FUNC | 0x1C)
#define RDTHREAD_FUNC   (PRIV_PAL_FUNC | 0x1E)
#define TBIM_FUNC       (PRIV_PAL_FUNC | 0x20)
#define TBIMASN_FUNC    (PRIV_PAL_FUNC | 0x21)
#define TBIM64_FUNC     (PRIV_PAL_FUNC | 0x22)
#define TBIS64_FUNC     (PRIV_PAL_FUNC | 0x23)
#define EALNFIX_FUNC    (PRIV_PAL_FUNC | 0x24)
#define DALNFIX_FUNC    (PRIV_PAL_FUNC | 0x25)
#define RDCOUNTERS_FUNC (PRIV_PAL_FUNC | 0x30)
#define WRPERFMON_FUNC  (PRIV_PAL_FUNC | 0x32)
#define CP_SLEEP_FUNC   (PRIV_PAL_FUNC | 0x39)
#define INITPCR_FUNC    (PRIV_PAL_FUNC | 0x38)

// published\sdk\inc\correg.h
#define RidToToken(rid,tktype) ((rid) |= (tktype))
#define TokenFromRid(rid,tktype) ((rid) | (tktype))
#define RidFromToken(tk) ((RID) ((tk) & 0x00ffffff))
#define TypeFromToken(tk) ((tk) & 0xff000000)

// published\sdk\inc\devioctl.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// published\sdk\inc\exchext.h
#define DEFINE_EXCHEXTGUID(name, b) \
    DEFINE_GUID(name, 0x00020D00 | (b), 0, 0, 0xC0,0,0,0,0,0,0,0x46)

// published\sdk\inc\getuser.h
#define USRBROWS_SHOW_ALL	    (USRBROWS_SHOW_ALIASES |\
				     USRBROWS_SHOW_GROUPS  |\
				     USRBROWS_SHOW_USERS)

// published\sdk\inc\gl\glaux.h
#define AUX_WIND_USES_FIXED_332_PAL(x)  (((x) & AUX_FIXED_332_PAL) != 0)

// published\sdk\inc\mmreg.h
#define INIT_MMREG_MID(guid, id)\
{\
    (guid)->Data1 = 0xd5a47fa7 + (USHORT)(id);\
    (guid)->Data2 = 0x6d98;\
    (guid)->Data3 = 0x11d1;\
    (guid)->Data4[0] = 0xa2;\
    (guid)->Data4[1] = 0x1a;\
    (guid)->Data4[2] = 0x00;\
    (guid)->Data4[3] = 0xa0;\
    (guid)->Data4[4] = 0xc9;\
    (guid)->Data4[5] = 0x22;\
    (guid)->Data4[6] = 0x31;\
    (guid)->Data4[7] = 0x96;\
}
#define EXTRACT_MMREG_MID(guid)\
    (USHORT)((guid)->Data1 - 0xd5a47fa7)
#define INIT_MMREG_PID(guid, id)\
{\
    (guid)->Data1 = 0xe36dc2ac + (USHORT)(id);\
    (guid)->Data2 = 0x6d9a;\
    (guid)->Data3 = 0x11d1;\
    (guid)->Data4[0] = 0xa2;\
    (guid)->Data4[1] = 0x1a;\
    (guid)->Data4[2] = 0x00;\
    (guid)->Data4[3] = 0xa0;\
    (guid)->Data4[4] = 0xc9;\
    (guid)->Data4[5] = 0x22;\
    (guid)->Data4[6] = 0x31;\
    (guid)->Data4[7] = 0x96;\
}
#define EXTRACT_MMREG_PID(guid)\
    (USHORT)((guid)->Data1 - 0xe36dc2ac)

// published\sdk\inc\nt_vdd.h
#define getMODE() ((getMSW() & MSW_PE) ? VDM_PM : VDM_V86)

// published\sdk\inc\ntconfig.h
#define SERVICE_DRIVER                 (SERVICE_KERNEL_DRIVER | \
                                        SERVICE_FILE_SYSTEM_DRIVER | \
                                        SERVICE_RECOGNIZER_DRIVER)
#define SERVICE_WIN32                  (SERVICE_WIN32_OWN_PROCESS | \
                                        SERVICE_WIN32_SHARE_PROCESS)
#define SERVICE_TYPE_ALL               (SERVICE_WIN32  | \
                                        SERVICE_ADAPTER | \
                                        SERVICE_DRIVER  | \
                                        SERVICE_INTERACTIVE_PROCESS)

// published\sdk\inc\ntfsprop.h
#define PROPERTY_SPECIFIER_ID(PS,I)      \
    ((PS)->Specifiers[(I)].Id)
#define PROPERTY_ID(p,i)        \
    ((p)->PropertyIds[i])

// published\sdk\inc\ntlpcapi.h
#define PORT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | \
                         SYNCHRONIZE | 0x1)

// published\sdk\inc\ntverp.h
#define VER_PRODUCTVERSION_DW       (0x05010000 | VER_PRODUCTBUILD)

// published\sdk\inc\penwin.h
#define ALC_PUNC             0x00000008L // !-;`"?()&.,; and backslash
#define ALC_MATH             0x00000010L // %^*()-+={}<>,/.
#define TRAIN_BOTH              (TRAIN_DEFAULT | TRAIN_CUSTOM)
#define PCMR_SELECT             (-12)   // ret because of tap & hold
#define IE_MSGFIRST           (WM_USER+150)     // 0x496 == 1174
#define FIsSelectGesture(syv)   \
   ((syv) >= SYVSELECTFIRST && (syv) <= SYVSELECTLAST)

// published\sdk\inc\pwin16.h
#define GET_WM_MENUSELECT_CMD(wp, lp)               (wp)
#define GET_WM_PARENTNOTIFY_MSG(wp, lp)             (wp)
#define GET_WM_VKEYTOITEM_CODE(wp, lp)              (wp)
#define GET_WM_HSCROLL_CODE(wp, lp)                 (wp)
#define GET_WM_VSCROLL_CODE(wp, lp)                 (wp)

// published\sdk\inc\pwin32.h
#define GET_WM_MENUSELECT_HMENU(wp, lp)             (HMENU)(lp)
#define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW) (WPARAM)hmenuF, (LPARAM)hmenuW
#define GET_WM_DDE_EXECUTE_HDATA(wp, lp)            ((HANDLE)lp)
#define MPostWM_DDE_EXECUTE(hTo, hFrom, hDataExec) \
        PostMessage(hTo, WM_DDE_EXECUTE, (WPARAM)hFrom, (LPARAM)hDataExec)
#define GETMAJORVERSION(x)                  ((x)&0xff)

// published\sdk\inc\snmp.h
#define ASN_INTEGER                 (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x02)
#define ASN_OBJECTIDENTIFIER        (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x06)
#define ASN_IPADDRESS               (ASN_APPLICATION | ASN_PRIMITIVE | 0x00)
#define ASN_COUNTER32               (ASN_APPLICATION | ASN_PRIMITIVE | 0x01)
#define ASN_GAUGE32                 (ASN_APPLICATION | ASN_PRIMITIVE | 0x02)
#define ASN_OPAQUE                  (ASN_APPLICATION | ASN_PRIMITIVE | 0x04)
#define ASN_COUNTER64               (ASN_APPLICATION | ASN_PRIMITIVE | 0x06)
#define ASN_UNSIGNED32              (ASN_APPLICATION | ASN_PRIMITIVE | 0x07)

// published\sdk\inc\tuple.h
#define PowerInformation(X)    (X & 0x03)

// published\sdk\inc\unimodem.h
    #define RAWDIAGNOSTICS_DATA_SIZE(_praw_diagnostics_hdr)                 \
            ((_praw_diagnostics_hdr)->dwParam)
    #define PARSEDDIAGNOSTICS_NUM_ITEMS(_pparsed_diagnostics_hdr)           \
            ((_pparsed_diagnostics_hdr)->dwParam)

// published\sdk\inc\vfw.h
#define AVIIF_MIDPART       (AVIIF_LASTPART|AVIIF_FIRSTPART)
#define MCIWNDM_GETDEVICEID	(WM_USER + 100)
#define MCIWNDM_GETSTART	(WM_USER + 103)
#define MCIWNDM_GETLENGTH	(WM_USER + 104)
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
#define MCIWNDM_PLAYFROM	(WM_USER + 122)
#define MCIWNDM_PLAYTO          (WM_USER + 123)
#define MCIWNDM_CHANGESTYLES	(WM_USER + 135)
#define MCIWNDM_GETSTYLES	(WM_USER + 136)
#define MCIWNDM_GETALIAS	(WM_USER + 137)
#define MCIWNDM_PLAYREVERSE	(WM_USER + 139)
#define MCIWNDM_GET_SOURCE      (WM_USER + 140)
#define MCIWNDM_PUT_SOURCE      (WM_USER + 141)
#define MCIWNDM_GET_DEST        (WM_USER + 142)
#define MCIWNDM_PUT_DEST        (WM_USER + 143)
#define MCIWNDM_CAN_PLAY        (WM_USER + 144)
#define MCIWNDM_CAN_SAVE        (WM_USER + 147)
#define MCIWNDM_CAN_EJECT       (WM_USER + 148)
#define MCIWNDM_CAN_CONFIG      (WM_USER + 149)
#define MCIWNDM_SETOWNER	(WM_USER + 152)
#define MCIWNDM_GETPOSITIONA	(WM_USER + 102)
#define MCIWNDM_GETMODEA	(WM_USER + 106)
#define MCIWNDM_GETFILENAMEA    (WM_USER + 124)
#define MCIWNDM_GETDEVICEA      (WM_USER + 125)
#define MCIWNDM_NEWA		(WM_USER + 134)
#define MCIWNDM_OPENA		(WM_USER + 153)
#define MCIWNDM_GETPOSITIONW	(WM_USER + 202)
#define MCIWNDM_GETMODEW	(WM_USER + 206)
#define MCIWNDM_GETFILENAMEW    (WM_USER + 224)
#define MCIWNDM_GETDEVICEW      (WM_USER + 225)
#define MCIWNDM_NEWW		(WM_USER + 234)
#define MCIWNDM_OPENW		(WM_USER + 252)

// published\sdk\inc\wfext.h
#define FM_GETFOCUS           (WM_USER + 0x0200)
#define FM_GETSELCOUNT        (WM_USER + 0x0202)
#define FM_GETSELCOUNTLFN     (WM_USER + 0x0203)  /* LFN versions are odd */
#define FM_GETDRIVEINFOA      (WM_USER + 0x0201)
#define FM_GETFILESELA        (WM_USER + 0x0204)
#define FM_GETFILESELLFNA     (WM_USER + 0x0205)  /* LFN versions are odd */
#define FM_GETDRIVEINFOW      (WM_USER + 0x0211)
#define FM_GETFILESELW        (WM_USER + 0x0214)
#define FM_GETFILESELLFNW     (WM_USER + 0x0215)  /* LFN versions are odd */

// published\sdk\inc\winfax.h
#define FAX_READ                (FAX_JOB_QUERY               |\
                                 FAX_CONFIG_QUERY            |\
                                 FAX_PORT_QUERY)
#define FAX_ALL_ACCESS          (FAX_JOB_SUBMIT              |\
                                 FAX_JOB_QUERY               |\
                                 FAX_CONFIG_QUERY            |\
                                 FAX_CONFIG_SET              |\
                                 FAX_PORT_QUERY              |\
                                 FAX_PORT_SET                |\
                                 FAX_JOB_MANAGE)

// published\sdk\inc\winsnmp.h
#define SNMP_SYNTAX_INT       (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x02)
#define SNMP_SYNTAX_OCTETS    (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x04)
#define SNMP_SYNTAX_OID       (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x06)
#define SNMP_SYNTAX_IPADDR    (ASN_APPLICATION | ASN_PRIMITIVE | 0x00)
#define SNMP_SYNTAX_CNTR32    (ASN_APPLICATION | ASN_PRIMITIVE | 0x01)
#define SNMP_SYNTAX_GAUGE32   (ASN_APPLICATION | ASN_PRIMITIVE | 0x02)
#define SNMP_SYNTAX_OPAQUE    (ASN_APPLICATION | ASN_PRIMITIVE | 0x04)
#define SNMP_SYNTAX_NSAPADDR  (ASN_APPLICATION | ASN_PRIMITIVE | 0x05)
#define SNMP_SYNTAX_CNTR64    (ASN_APPLICATION | ASN_PRIMITIVE | 0x06)
#define SNMP_SYNTAX_UINT32    (ASN_APPLICATION | ASN_PRIMITIVE | 0x07)

// sdktools\build\build.h
#define FILEDB_DBPRESERVE       (FILEDB_SOURCE |       \
                                 FILEDB_DIR |          \
                                 FILEDB_HEADER |       \
                                 FILEDB_ASM |          \
                                 FILEDB_MASM |         \
                                 FILEDB_RC |           \
                                 FILEDB_C |            \
                                 FILEDB_MIDL |         \
                                 FILEDB_ASN |          \
                                 FILEDB_JAVA |         \
                                 FILEDB_MOF |          \
                                 FILEDB_CSHARP |       \
                                 FILEDB_MKTYPLIB |     \
                                 FILEDB_MULTIPLEPASS | \
                                 FILEDB_PASS0)

// sdktools\build\buildscn.c
#define IsTokenPrefix(psz, szToken, cchToken)               \
            (IsTokenPrefix0((psz), (szToken), (cchToken)) && \
             (psz)[cchToken] != '\0')
#define IsTokenMatch(psz, szToken, cchToken) \
            (IsTokenPrefix((psz), (szToken), (cchToken)) && \
             !iscsym((psz)[cchToken]))
#define IsCiTokenPrefix(psz, szToken, cchToken)             \
            (IsCiTokenPrefix0((psz), (szToken), (cchToken)) && \
             (psz)[cchToken] != '\0')
#define IsCiTokenMatch(psz, szToken, cchToken) \
            (IsCiTokenPrefix((psz), (szToken), (cchToken)) && \
             !iscsym((psz)[cchToken]))

// sdktools\diff\diff.c
#define isslash(c)  (c=='/'||c=='\\')

// sdktools\hsplit\hsplit.h
#define HSLM_APPEND         (HSLM_NOLABEL | HSLM_NOEOL)
#define HST_BOTH                (HST_PUBLIC | HST_INTERNAL)
#define HST_USERHEADERTAG       (HST_USERINTERNALTAG | HST_USERBOTHTAG)
#define HSO_OLDPROJSW           (HSO_OLDPROJSW_N | HSO_OLDPROJSW_4 | HSO_OLDPROJSW_E | HSO_OLDPROJSW_P)
#define HSO_USERHEADERTAG       (HSO_USERINTERNALTAG | HSO_USERBOTHTAG)

// sdktools\link16\bndtrn.h
#define IsBadRec(r) (r < 0x6E || r > 0xca)
#define IsBadRec(r) (r < 0x6E || r > 0xca || (r & 1) != 0)
#define UPPER(b)        (b >= 'a' && b <= 'z'? b - 'a' + 'A': b)
#define IsDataFlg(f)    (((f) & OBJ_CODE) == 0)
#define IsCodeFlg(f)    (((f) & OBJ_CODE) != 0)
#define IsDataFlg(x)    (((x) & NSTYPE) == NSDATA)
#define IsCodeFlg(x)    (((x) & NSTYPE) == NSCODE)
#define IsCodeFlg(x)    ((x & FCODE) != 0)
#define IsDataFlg(x)    ((x & FCODE) == 0)
#define TYPEOF(r)       (r&~1)

// sdktools\link16\config.h
#define OEXE            (ODOS3EXE || OSEGEXE)

// sdktools\link16\implib.c
#define UPPER(c)        (((c)>='a' && (c)<='z')? (c) - 'a' + 'A': (c))

// sdktools\link16\newpar.c
#define fPath(s)        (IFind(s,'\\') != INIL || IFind(s,'/') != INIL)

// sdktools\link16\newtp1.c
#define F68KCODE(ch)    ((ch) >= 'A' && (ch) <= 'E')

// sdktools\link16\stdio20.h
#define stdin           (&_iob[0])
#define stdout          (&_iob[1])
#define stderr          (&_iob[2])

// sdktools\link16\undname.hxx
#define TE_isfunction(t)                ((t)&0x8000)
#define TE_setisfunction(t)             ((t)|=0x8000)
#define TE_isnear(t)                    (((t)&0x2000)==0x0000)
#define TE_setisnear(t)                 ((t)&=~0x2000)
#define TE_isfar(t)                             ((t)&0x2000)
#define TE_setisfar(t)                  ((t)|=0x2000)
#define TE_isvirtual(t)                 (TE_isfunction(t)&&(((t)&0x0700)==0x0100))
#define TE_setisvirtual(t)              ((t)=(((t)&~0x0700)|0x0100))
#define TE_isvcall(t)                   (TE_isfunction(t)?(((t)&0x1800)==0x1800):0)
#define TE_setisvcall(t)                ((t)=(((t)&~0x9800)|0x9800))
#define TE_setisadjustor(t)             ((t)=(((t)&~0x0700)|0x0400))
#define TE_setisvtoradj(t)              ((t)=(((t)&~0x0700)|0x0500))
#define TE_setispublic(t)               ((t)=(TE_isfunction(t)?((t)&~0x00C0):((t)&~0x1800)))
#define TE_setisprivate(t)              ((t)=(TE_isfunction(t)?(((t)&~0x00C0)|0x0040):(((t)&~0x1800)|0x0800)))
#define TE_setisprotected(t)    ((t)=(TE_isfunction(t)?(((t)&~0x00C0)|0x0080):(((t)&~0x1800)|0x1000)))
#define TE_setisdata(t)                 ((t)&=~0x8000)
#define TE_isguard(t)                   (TE_isdata(t)&&(((t)&0x7800)==0x6000))
#define TE_setisguard(t)                ((t)=(((t)&~0x7800)|0x6000))
#define TE_ismetaclass(t)               (TE_isdata(t)&&(((t)&0x7800)==0x7800))
#define TE_setismetaclass(t)    ((t)=(((t)&~0x7800)|0x7800))
#define TE_access               (TE_protect|TE_public)
#define TE_access_d             (TE_protect_d|TE_public_d)
#define TE_access_vadj  (TE_protect_vadj|TE_public_vadj)
#define IT_isfunction(it)       ((((it)>='6')&&((it)<='9'))||((it)=='_'))

// sdktools\m4\eval.c
#define peopiBoe (&rgeopi[ieopiBoe])
#define peopiFlush (&rgeopi[ieopiFlush])

// sdktools\m4\m4.h
#define ptokArgv(i) (&argv[i])

// sdktools\m4\mem.h
#define parHead (&g_arHead)

// sdktools\masm\asm86.h
# define BINOPEN        (O_CREAT | O_TRUNC | O_WRONLY | O_BINARY)
# define BINOPEN       (O_CREAT | O_TRUNC | O_WRONLY)
#define CSNEAR          ((USHORT)(~0))    /* type for near proc/label */
#define CSFAR           ((USHORT)(~1))    /* .. far .. */

// sdktools\masm\asmctype.h
#define LEGAL1ST(c)	(_asmctype_[c] & _A1)
#define TOKLEGAL(c)	(_asmctype_[c] & _AT)
#define ISBLANK(c)	(_asmctype_[c] & _AB)
#define ISFILE(c)	(_asmctype_[c] & _AF)
#define ISEOL(c)	(_asmctype_[c] & _AL)
#define ISSIGN(c)	(_asmctype_[c] & _AS)
#define ISTERM(c)	(_asmctype_[c] & _AZ)
#define ISOPER(c)	(_asmctype_[c] & _AO)

// sdktools\masm\asmlst.c
#define setpassed(sym)	(sym)->attr |= (M_PASSED)

// sdktools\mc\mc.h
#define iswcsymf(_c)   (iswalpha(_c) || ((_c) == L'_'))
#define iswcsym(_c)    (iswalnum(_c) || ((_c) == L'_'))

// sdktools\mep\browser\inc\bscsup.h
#define IrefFrBob(bob)	((IREF)((bob) & 0xffffffL))

// sdktools\mep\browser\mbrmake\addtolst.c
    #define FExternAttr(attr) (!!(attr & SBR_ATR_DECL_ONLY))

// sdktools\mep\browser\mbrmake\ord.c
#define HASH_ORD(ord) ((ord)&511)

// sdktools\mep\extens\pmatch\pmatch.c
#define fLeftSide(ch) ((ch) == '[' || (ch) == '{' || (ch) == '(' || (ch) == '<' )

// sdktools\mep\help\htest\cons.c
#define     PMOUSE_EVT(p)   (&(EVENT_DATA(p).MouseEvent))
#define     PKEY_EVT(p)     (&(EVENT_DATA(p).KeyEvent))

// sdktools\mep\help\inc\help.h
#define fUniq(x)   ((x).cn & 0x8000)

// sdktools\mep\inc\ext.h
#define toPIF(x)  (PIF)(void  *)&x

// sdktools\mep\inc\mep.h
#define     ACCESSMODE_RW       (GENERIC_READ | GENERIC_WRITE)
#define     SHAREMODE_RW        (SHAREMODE_READ | SHAREMODE_WRITE)

// sdktools\mep\src\console.c
#define     PMOUSE_EVT(p)   (&(EVENT_DATA(p).MouseEvent))
#define     PKEY_EVT(p)     (&(EVENT_DATA(p).KeyEvent))
#define     PMENU_EVT(p)    (&(EVENT_DATA(p).MenuEvent))
#define     PFOCUS_EVT(p)   (&(EVENT_DATA(p).FocusEvent))

// sdktools\mkmsg\mkmsg.c
        #define SKIP_BLANKS()   for ( ; *pBuf && isspace(*pBuf); pBuf++)
        #define SKIP_TO_BLANKS()        for ( ; *pBuf && !isspace(*pBuf); pBuf++)

// sdktools\mtscript\inc\mtverp.h
#define VER_PRODUCTVERSION_DW           (0x01000000 | VER_PRODUCTBUILD)

// sdktools\mttf\setup\uilstf.h
#define STF_MESSAGE               (WM_USER + 0x8000)

// sdktools\nmake\nmake.h
#define PATH_SEPARATOR(A)   ((A) == '\\' || (A) == '/')
#define DYNAMIC_DEP(A)      ((A)[2] == '('                     \
                    && (A)[3] == '@'                   \
                    && (A)[5] == ')'                   \
                    && (((A)[4] == 'F'                 \
                    || (A)[4] == 'D'               \
                    || (A)[4] == 'B'               \
                    || (A)[4] == 'R')))

// sdktools\perfmon\grafdisp.c
#define dwGraphDisplayClassStyle    (CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC)

// sdktools\perfmon\graph.c
#define dwGraphClassStyle           (CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS)

// sdktools\perfmon\intrline.c
#define dwILineClassStyle     (CS_HREDRAW | CS_VREDRAW)
#define ILBegin(pILine)    \
   (pILine->iBeginValue)
#define ILEnd(pILine)      \
   (pILine->iEndValue)
#define ILStart(pILine)    \
   (pILine->iStartValue)
#define ILStop(pILine)     \
   (pILine->iStopValue)
#define ILMode(pILine)     \
   (pILine->iMode)

// sdktools\perfmon\intrline.h
#define ILN_SELCHANGED        (WM_USER + 0x200)

// sdktools\perfmon\legend.c
#define dwGraphLegendClassStyle     (CS_HREDRAW | CS_VREDRAW)

// sdktools\perfmon\owndraw.h
#define DIIndex(lpDI)               \
   (lpDI->itemID)
#define DIEntire(lpDI)              \
   (lpDI->itemAction & ODA_DRAWENTIRE)
#define DIFocusChanged(lpDI)        \
   (lpDI->itemAction & ODA_FOCUS)
#define DISelectionChanged(lpDI)    \
   (lpDI->itemAction & ODA_SELECT)

// sdktools\perfmon\report.c
#define dwReportClassStyle           (CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS)

// sdktools\ppr\lpr.h
#define BEGINBANNER             "\033&l1o6D\033(8U\033(s0p10h12v3T"
#define BEGINPORTRAIT           "\033&l0o7.7C\033(8U\033(s0p10h12v3T"

// sdktools\profiler\vxd\inc\devioctl.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// sdktools\pview\pviewp.h
#define LBS_MYSTYLE     (LBS_NOTIFY | LBS_OWNERDRAWFIXED | WS_VSCROLL)

// sdktools\rasdiag\private\stlxmem.h
#define _REFERENCE_X(T, A) T _FARQ &

// sdktools\rcdll\p1types.h
#define CLR_SIGNED(P)   ((P) &= ~BT_SIGNED)
#define IVALUE_ISUB(P)                  (PIVALUE_ISUB(&(P)))
#define IVALUE_IFORMALS(P)              (PIVALUE_IFORMALS(&(P)))
#define ANY_MODIFIER(I)         ((I) & (ALL_MODIFIERS))

// sdktools\rcdll\rc.h
#define wcsdigit(w) (w >= 0x0030 && w <= 0x0039)

// sdktools\rcdll\rcppext.h
#define EXTENSION    (Extension || Ehxtension)

// sdktools\rcdll\symbols.h
#define SYM_ISSYMBOL(p)         (SYM_ANYVTAG(p) & SYMV_SYMBOL)
#define SYM_ISFUNCTION(p)       (SYM_ANYVTAG(p) & SYMV_FUNCTION)
#define SYM_ISFORMAL(p)         (SYM_ANYVTAG(p) & SYMV_FORMAL)
#define SYM_ISLABEL(p)          (SYM_ANYVTAG(p) & SYMV_LABEL)
#define SYM_ISTAG(p)            (SYM_ANYVTAG(p) & SYMV_TAG)
#define SYM_ISMOE(p)            (SYM_ANYVTAG(p) & SYMV_MOE)
#define SYM_ISINTRINSIC(p)      (SYM_ANYVTAG(p) & SYMV_INTRINSIC)
#define SYM_ISRAWSYMBOL(p)      (SYM_ANYVTAG(p) & SYMV_RAWSYMBOL)
#define SYM_ISSEGMENT(p)        (SYM_ANYVTAG(p) & SYMV_SEGMENT)

// sdktools\rcdll\trees.h
#define BASIC_SHAPE(S)  ((S) & TTBasicShape)
#define TR_ISZERO(P)    (TR_SHAPE(P) & TTzero)
#define LIAR_LEFT(p)    (&((p)->liar_left))
#define LIAR_RIGHT(p)   (&((p)->liar_right))

// sdktools\restools\inc\rc.h
#define	wcsdigit(w) (w >= 0x0030 && w <= 0x0039)

// sdktools\restools\rlt32\bingen\vktbl.h
#define ISACCFLG(x,y)    ((x & y)==y)

// sdktools\sdv\sdview.h
#define LM_ITEMACTIVATE     (WM_USER + 100) // wParam = iItem
#define LM_GETINFOTIP       (WM_USER + 101) // wParam = iItem, lParam -> NMLVGETINFOTIP

// sdktools\setedit\graph.c
#define dwGraphClassStyle           (CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS)

// sdktools\setedit\legend.c
#define dwGraphLegendClassStyle     (CS_HREDRAW | CS_VREDRAW)

// sdktools\setedit\owndraw.h
#define DIIndex(lpDI)               \
   (lpDI->itemID)
#define DIEntire(lpDI)              \
   (lpDI->itemAction & ODA_DRAWENTIRE)
#define DIFocusChanged(lpDI)        \
   (lpDI->itemAction & ODA_FOCUS)
#define DISelectionChanged(lpDI)    \
   (lpDI->itemAction & ODA_SELECT)

// sdktools\tweakui\desktop.cpp
#define pidlPnsi(pnsi) ((PIDL)&(pnsi)->ridl)
#define pnsiInsi(insi) (&pddii->pnsi[insi])
#define pddii (&ddii)
#define Desktop_IsHereNow(pnsi, ptszClsid) \
    ((pnsi->nsifl & nsiflNormal) ? Desktop_IsNSKey(ptszClsid) \
				 : Desktop_GetNetHood())

// sdktools\tweakui\general.cpp
#define pgdii (&gdii)

// sdktools\tweakui\mouse.cpp
#define fLpdt (lpdt != &dtScratch)
#define fLpdt (SELECTOROF(lpdt) != SELECTOROF((LPDT)&dtScratch))
#define pmdii (&mdii)

// sdktools\tweakui\network.cpp
#define pndii (&ndii)

// sdktools\tweakui\tools.cpp
#define ptiIti(iti) (&ptdii->pti[iti])
#define ptdii (&tdii)
#define ptci (&pftci->tci)
#define pftci (&ftci)

// sdktools\tweakui\tweakui.h
#define phkCU (&c_hkCU)
#define phkLM (&c_hkLM)
#define g_fSmoothScroll         (g_flWeirdStuff & flbsSmoothScroll)
#define g_fOPK2                 (g_flWeirdStuff & flbsOPK2)
#define g_fNT                   (g_flWeirdStuff & flbsNT)
#define g_fBadRun               (g_flWeirdStuff & flbsBadRun)
#define g_fMillennium           (g_flWeirdStuff & flbsMillennium)
#define g_fIE5                  (g_flWeirdStuff & flbsIE5)
#define g_fNT5                  (g_flWeirdStuff & flbsNT5)
#define pcdii (&cdii)

// sdktools\vi\nt.c
#define ALT_PRESSED (RIGHT_ALT_PRESSED | LEFT_ALT_PRESSED)
#define CTL_PRESSED (RIGHT_CTRL_PRESSED | LEFT_CTRL_PRESSED)
#define OMODE (ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT)

// sdktools\vi\regexp.c
#define ISMULT(c)       ((c) == '*' || (c) == '+' || (c) == '?')
#define META    "^$.[()|?+*\\"

// sdktools\vi\search.c
#define C0(c)   (((c) == ' ') || ((c) == '\t') || ((c) == NUL))
#define C1(c)   (isalpha(c) || isdigit(c) || ((c) == '_'))

// sdktools\vmmreg32\pch.h
#define ToUpper(ch)                 ((int)(((ch>='a')&&(ch<='z'))?(ch-'a'+'A'):ch))

// sdktools\windiff\windiff\regexp.c
#define ISMULT(c)       ((c) == '*' || (c) == '+' || (c) == '?')
#define META    "^$.[()|?+*\\"

// sdktools\winobj\wfdisk.h
#define DRIVEID(path) ((path[0] - 'A')&31)

// sdktools\winobj\wfext.h
#define FM_GETFOCUS     (WM_USER + 0x0200)
#define FM_GETDRIVEINFO     (WM_USER + 0x0201)
#define FM_GETFILESEL       (WM_USER + 0x0204)
#define FM_GETFILESELLFN    (WM_USER + 0x0205)  // LFN versions are odd

// sdktools\winobj\wfutil.c
#define ISDIGIT(c)  ((c) >= '0' && (c) <= '9')

// sdktools\winobj\winfile.h
#define FS_CHANGEDISPLAY    (WM_USER+0x100)
#define FS_CHANGEDRIVES     (WM_USER+0x101)
#define FS_GETSELECTION     (WM_USER+0x102)
#define FS_GETDRIVE         (WM_USER+0x104)
#define FS_SETDRIVE         (WM_USER+0x107)
#define FS_GETFILESPEC      (WM_USER+0x108)
#define FS_SETSELECTION     (WM_USER+0x109)
#define ATTR_USED           (0x00BF | ATTR_TYPES)

// sdktools\wsremote\server.c
#define RemoteInfo(prt,flg) {if (!(flg&&0x80000000)) prt;}

// sdktools\z\extens\zextens\pmatch.c
#define fLeftSide(ch) ((ch) == '[' || (ch) == '{' || (ch) == '(' || (ch) == '<' )

// sdktools\z\src\console.c
#define     PMOUSE_EVT(p)   (&(EVENT_DATA(p).MouseEvent))
#define     PKEY_EVT(p)     (&(EVENT_DATA(p).KeyEvent))
#define     PMENU_EVT(p)    (&(EVENT_DATA(p).MenuEvent))
#define     PFOCUS_EVT(p)   (&(EVENT_DATA(p).FocusEvent))

// sdktools\z\src\z.h
#define     ACCESSMODE_RW       (GENERIC_READ | GENERIC_WRITE)
#define     SHAREMODE_RW        (SHAREMODE_READ | SHAREMODE_WRITE)

// sdktools\ztools\inc\tools.h
#define ISTMPDRIVE(x)	(((x)&REALDRIVE)==0)
#define TOKTODRV(x)	((x)&~REALDRIVE)

// termsrv\admtools\c2config\c2acls\aclfuncs.c
#define NTFS_FILE_ADD_READ      (FILE_GENERIC_READ | FILE_GENERIC_WRITE | \
                                 FILE_GENERIC_EXECUTE)
#define NTFS_FILE_READ          (FILE_GENERIC_READ | FILE_GENERIC_EXECUTE)
#define NTFS_FILE_ADD           (FILE_GENERIC_WRITE | FILE_GENERIC_EXECUTE)
#define NTFS_DIR_ADD_READ       (GENERIC_READ | GENERIC_EXECUTE)
#define NTFS_DIR_READ           (GENERIC_READ | GENERIC_EXECUTE)
#define NTFS_DIR_ADD            (GENERIC_WRITE | GENERIC_EXECUTE)

// termsrv\admtools\c2config\inc\c2inc.h
#define MBOK_EXCLAIM            (MB_OK | MB_ICONEXCLAMATION | MB_TASKMODAL)
#define MBOK_INFO               (MB_OK | MB_ICONINFORMATION | MB_TASKMODAL)
#define MBOKCANCEL_EXCLAIM      (MB_OKCANCEL | MB_ICONEXCLAMATION | MB_TASKMODAL)
#define MBOKCANCEL_INFO         (MB_OKCANCEL | MB_ICONINFORMATION | MB_TASKMODAL)
#define MBOKCANCEL_QUESTION     (MB_OKCANCEL | MB_ICONQUESTION | MB_TASKMODAL)
#define MBYESNO_QUESTION        (MB_YESNO | MB_ICONQUESTION | MB_TASKMODAL)
#define MBYESNOCANCEL_QUESTION  (MB_YESNOCANCEL | MB_ICONQUESTION | MB_TASKMODAL)
#define MBYESNOCANCEL_EXCLAIM   (MB_YESNOCANCEL | MB_ICONEXCLAMATION | MB_TASKMODAL)

// termsrv\admtools\tscc\snapin\stdafx.h
#define ALN_APPLY ( WM_USER + 333 )

// termsrv\cdmodem\inc\rasapip.h
#define RAS_DEVICE_TYPE(_x)     ((_x) & 0x0000FFFF)
#define RAS_DEVICE_CLASS(_x)    ((_x) & 0xFFFF0000)

// termsrv\clcreator\copyfile.c
#define     NCDU_START_FILE_COPY    (WM_USER +101)

// termsrv\clcreator\findclnt.c
#define     NCDU_SEARCH_FOR_CLIENTS       (WM_USER+101)

// termsrv\clcreator\fmt_disk.c
#define FS_CANCELUPDATE         (WM_USER+104)

// termsrv\clcreator\netutils.c
#define NCDU_SHARE_DIR              (WM_USER    +101)
#define NCDU_BROWSE_DIST_PATH       (WM_USER    +104)
#define NCDU_BROWSE_DEST_PATH       (WM_USER    +105)

// termsrv\clcreator\otnboot.h
#define NCDU_SHOW_SW_CONFIG_DLG     (WM_USER+11)
#define NCDU_SHOW_TARGET_WS_DLG     (WM_USER+12)
#define NCDU_SHOW_SERVER_CFG_DLG    (WM_USER+13)
#define NCDU_SHOW_CONFIRM_DLG       (WM_USER+14)
#define NCDU_SHOW_CREATE_DISKS_DLG  (WM_USER+15)
#define NCDU_SHOW_SHARE_NET_SW_DLG  (WM_USER+16)
#define NCDU_SHOW_COPYING_DLG       (WM_USER+17)
#define NCDU_SHOW_EXIT_MESSAGE_DLG  (WM_USER+18)
#define NCDU_REGISTER_DLG           (WM_USER+21)
#define     NCDU_CANCEL_STYLE   (MB_ICONQUESTION | MB_YESNOCANCEL | MB_TASKMODAL)
#define MB_OK_TASK_EXCL             (MB_OK | MB_ICONEXCLAMATION | MB_TASKMODAL)
#define MB_OK_TASK_INFO             (MB_OK | MB_ICONINFORMATION | MB_TASKMODAL)
#define MB_OKCANCEL_TASK_EXCL       (MB_OKCANCEL | MB_ICONEXCLAMATION | MB_TASKMODAL)
#define MB_OKCANCEL_TASK_INFO       (MB_OKCANCEL | MB_ICONINFORMATION | MB_TASKMODAL)
#define MB_OKCANCEL_TASK_EXCL_DEF2  (MB_OKCANCEL | MB_ICONEXCLAMATION | MB_TASKMODAL | MB_DEFBUTTON2)

// termsrv\clcreator\servconn.c
#define NCDU_BROWSE_DEST_PATH       (WM_USER    + 101)

// termsrv\clcreator\sharenet.c
#define NCDU_SHARE_DIR              (WM_USER    +101)
#define NCDU_BROWSE_DIST_PATH       (WM_USER    +104)
#define NCDU_BROWSE_DEST_PATH       (WM_USER    +105)

// termsrv\clcreator\sharpath.c
#define     NCDU_MSG_SHARE_DIR  (WM_USER + 101)

// termsrv\drivers\td\tdasync\tdasync.h
#define EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3) // winnt.h

// termsrv\inc\adcgmcro.h
#define DC_TO_WIRE16_INPLACE_UA(A)               \
             {                                   \
                 DCUINT16 val;                   \
                 val = DC_TO_WIRE16(A);          \
                 DC_INSERT_UINT16_UA(&(A), val)  \
             }
#define DC_TO_WIRE32_INPLACE_UA(A)               \
             {                                   \
                 DCUINT32 val;                   \
                 val = DC_TO_WIRE32(A);          \
                 DC_INSERT_UINT32_UA(&(A), val)  \
             }
#define DC_FROM_WIRE16_INPLACE_UA(A)             \
             {                                   \
                 DCUINT16 val;                   \
                 val = DC_FROM_WIRE16(A);        \
                 DC_INSERT_UINT16_UA(&(A), val)  \
             }
#define DC_FROM_WIRE32_INPLACE_UA(A)             \
             {                                   \
                 DCUINT32 val;                   \
                 val = DC_FROM_WIRE32(A);        \
                 DC_INSERT_UINT32_UA(&(A), val)  \
             }

// termsrv\inc\ddcgctyp.h
#define DC_GET_WM_ACTIVATE_ACTIVATION(wParam) (wParam)
#define DC_GET_WM_SCROLL_CODE(wParam) (wParam)

// termsrv\inc\license.h
#define GET_CERTIFICATE_VERSION( x )    ( 0x0FFFFFFF & x )

// termsrv\inc\platform.h
#define GetOSId( _PlatformId ) \
    _PlatformId & 0xFF000000

// termsrv\license\tlserver\server\srvdef.h
#define BEGIN_TRANSACTION(stmt) \
    g_DbWorkSpace->BeginTransaction();
#define ROLLBACK_TRANSACTION(stmt) \
    g_DbWorkSpace->RollbackTransaction();
#define BEGIN_TRANSACTION(pStmt) \
    pStmt->BeginTransaction();
#define ROLLBACK_TRANSACTION(pStmt) \
    pStmt->RollbackTransaction();

// termsrv\remdsk\rds\as\as16\as16.h
#define PATCH_ENABLE        (ENABLE_ON | ENABLE_FORCALL)
#define PATCH_DISABLE       (ENABLE_OFF | ENABLE_FORCALL)

// termsrv\remdsk\rds\as\h\fh.h
#define FH_SC_EXACT_ASCII_MATCH (FH_SC_MATCH | FH_SC_EXACT)

// termsrv\remdsk\rds\as\h\gdc.h
#define GCT_DEFAULT          (GCT_PKZIP | GCT_PERSIST_PKZIP)

// termsrv\remdsk\rds\as\h\s20.h
#define S20_GET_CREATOR(A) ((TSHR_UINT16)(A & 0xFFFF))

// termsrv\remdsk\rds\as\h\sbc.h
#define SBC_TILE_TYPE(TILEID)  \
    (((TILEID) & 0x8000) ? SBC_LARGE_TILE_INDEX : SBC_MEDIUM_TILE_INDEX)

// termsrv\remdsk\rds\as\h\t_share.h
#define S20_ALL_VERSIONS        (S20_2X_VERSION | S20_30_VERSION)

// termsrv\remdsk\rds\dev\inc16\ctype.h
#define isupper(_c) ( (_ctype+1)[_c] & _UPPER )
#define isdigit(_c) ( (_ctype+1)[_c] & _DIGIT )
#define isxdigit(_c)    ( (_ctype+1)[_c] & _HEX )
#define isspace(_c) ( (_ctype+1)[_c] & _SPACE )
#define ispunct(_c) ( (_ctype+1)[_c] & _PUNCT )
#define __toascii(_c)   ( (_c) & 0x7f )
#define __iscsymf(_c)   (isalpha(_c) || ((_c) == '_'))
#define __iscsym(_c)    (isalnum(_c) || ((_c) == '_'))

// termsrv\remdsk\rds\dev\inc16\dos.h
#define _FP_SEG(fp) (*((unsigned __far *)&(fp)+1))
#define _FP_OFF(fp) (*((unsigned __far *)&(fp)))

// termsrv\remdsk\rds\dev\inc16\mmsystem.h
#define MIXER_OBJECTF_HMIXER    (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIXER)
#define MIXER_OBJECTF_HWAVEOUT  (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEOUT)
#define MIXER_OBJECTF_HWAVEIN   (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEIN)
#define MIXER_OBJECTF_HMIDIOUT  (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIOUT)
#define MIXER_OBJECTF_HMIDIIN   (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIIN)

// termsrv\remdsk\rds\dev\inc16\stdio.h
#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])
#define _stdaux (&_iob[3])
#define _stdprn (&_iob[4])

// termsrv\remdsk\rds\h\version.h
#define VER_PRODUCTVERSION_DW       (0x04040000 | 3385)

// termsrv\reskit\lsview\tslsview.cpp
#define TN_MESSAGE ( WM_USER + 60 )

// termsrv\reskit\smc\tclient\clx\clxtshar.h
#define isalpha(c)  ((c >= 'A' && c <= 'Z') ||\
                    (c >= 'a' && c <= 'z'))

// termsrv\reskit\smc\tclient\lib\tclient.c
#define _TOHEX(_d_) ((_d_ <= '9' && _d_ >= '0')?_d_ - '0':       \
                     (_d_ <= 'f' && _d_ >= 'a')?_d_ - 'a' + 10:  \
                     (_d_ <= 'F' && _d_ >= 'F')?_d_ - 'A' + 10:0)

// termsrv\tsuserex\tsusrsht.h
#define ALN_APPLY ( WM_USER + 900 )

// tools\x86\perl\lib\core\av.h
#define AvFILL(av)	((SvRMAGICAL((SV *) (av))) \
			  ? mg_size((SV *) av) : AvFILLp(av))

// tools\x86\perl\lib\core\cop.h
#define PUSHSUB(cx)							\
	cx->blk_sub.cv = cv;						\
	cx->blk_sub.olddepth = CvDEPTH(cv);				\
	cx->blk_sub.hasargs = hasargs;
#define PUSHFORMAT(cx)							\
	cx->blk_sub.cv = cv;						\
	cx->blk_sub.gv = gv;						\
	cx->blk_sub.hasargs = 0;					\
	cx->blk_sub.dfoutgv = PL_defoutgv;				\
	(void)SvREFCNT_inc(cx->blk_sub.dfoutgv)
#define POPFORMAT(cx)							\
	setdefout(cx->blk_sub.dfoutgv);					\
	SvREFCNT_dec(cx->blk_sub.dfoutgv);
#define POPEVAL(cx)							\
	PL_in_eval = cx->blk_eval.old_in_eval;				\
	optype = cx->blk_eval.old_op_type;				\
	PL_eval_root = cx->blk_eval.old_eval_root;
#define CxREALEVAL(c)	(((c)->cx_type & (CXt_EVAL|CXp_REAL)) == (CXt_EVAL|CXp_REAL))

// tools\x86\perl\lib\core\cv.h
#define CvEVAL(cv)		(CvUNIQUE(cv) && !SvFAKE(cv))
#define CvSPECIAL(cv)		(CvUNIQUE(cv) && SvFAKE(cv))

// tools\x86\perl\lib\core\dosish.h
#    define PTHREAD_CREATE_JOINABLE (&err)

// tools\x86\perl\lib\core\gv.h
#define GvIO(gv)	((gv) && SvTYPE((SV*)gv) == SVt_PVGV ? GvIOp(gv) : 0)
#define GvAVn(gv)	(GvGP(gv)->gp_av ? \
			 GvGP(gv)->gp_av : \
			 GvGP(gv_AVadd(gv))->gp_av)
#define GvHVn(gv)	(GvGP(gv)->gp_hv ? \
			 GvGP(gv)->gp_hv : \
			 GvGP(gv_HVadd(gv))->gp_hv)

// tools\x86\perl\lib\core\handy.h
#define isALNUM(c)	(isALPHA(c) || isDIGIT(c) || (c) == '_')
#define isIDFIRST(c)	(isALPHA(c) || (c) == '_')
#define isSPACE(c) \
	((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) =='\r' || (c) == '\f')
#define isDIGIT(c)	((c) >= '0' && (c) <= '9')
#   define isUPPER(c)	((c) >= 'A' && (c) <= 'Z')
#    define isALNUM_LC(c) \
	(isascii(c) && (isalpha(c) || isdigit(c) || (c) == '_'))
#    define isIDFIRST_LC(c)	(isascii(c) && (isalpha(c) || (c) == '_'))
#    define isALPHA_LC(c)	(isascii(c) && isalpha(c))
#    define isSPACE_LC(c)	(isascii(c) && isspace(c))
#    define isDIGIT_LC(c)	(isascii(c) && isdigit(c))
#    define isUPPER_LC(c)	(isascii(c) && isupper(c))
#  define toCTRL(c)    (toUPPER(c) ^ 64)

// tools\x86\perl\lib\core\hv.h
#define HeSVKEY_force(he)	(HeKEY(he) ?				\
				 ((HeKLEN(he) == HEf_SVKEY) ?		\
				  HeKEY_sv(he) :			\
				  sv_2mortal(newSVpv(HeKEY(he),		\
						     HeKLEN(he)))) :	\
				 &PL_sv_undef)

// tools\x86\perl\lib\core\iperlsys.h
#define PerlProc_execl(c, w, x, y, z)					\
	PL_piProc->Execl((c), (w), (x), (y), (z))
#define PerlProc_GetSysMsg(s,l,e)					\
	PL_piProc->GetSysMsg((s), (l), (e))

// tools\x86\perl\lib\core\mg.h
#define SvTIED_obj(sv,mg) \
    ((mg)->mg_obj ? (mg)->mg_obj : sv_2mortal(newRV(sv)))

// tools\x86\perl\lib\core\op.h
#define OPpDEREF_SV		(32|64)	/*   Want ref to SV. */

// tools\x86\perl\lib\core\perl.h
#define RsSIMPLE(sv)  (SvOK(sv) && SvCUR(sv))
#define RsPARA(sv)    (SvOK(sv) && ! SvCUR(sv))
#define PERLDB_SUB	(PL_perldb && (PL_perldb & PERLDBf_SUB))
#define PERLDB_LINE	(PL_perldb && (PL_perldb & PERLDBf_LINE))
#define PERLDB_NOOPT	(PL_perldb && (PL_perldb & PERLDBf_NOOPT))
#define PERLDB_INTER	(PL_perldb && (PL_perldb & PERLDBf_INTER))
#define PERLDB_SUBLINE	(PL_perldb && (PL_perldb & PERLDBf_SUBLINE))
#define PERLDB_SINGLE	(PL_perldb && (PL_perldb & PERLDBf_SINGLE))
#define PERLDB_SUB_NN	(PL_perldb && (PL_perldb & (PERLDBf_NONAME)))

// tools\x86\perl\lib\core\perlsdio.h
#  define PerlIO_getc(f) \
		(feof(f) ? EOF : getc(f))
#  define PerlIO_read(f,buf,count) \
		(feof(f) ? 0 : (SSize_t)fread(buf,1,count,f))

// tools\x86\perl\lib\core\pp.h
#define dPOPXnnrl_ul(X)	\
    double right = POPn;				\
    SV *leftsv = CAT2(X,s);				\
    double left = USE_LEFT(leftsv) ? SvNV(leftsv) : 0.0
#define dPOPXiirl_ul(X) \
    IV right = POPi;					\
    SV *leftsv = CAT2(X,s);				\
    IV left = USE_LEFT(leftsv) ? SvIV(leftsv) : 0
#define AMG_CALLun(sv,meth) amagic_call(sv,&PL_sv_undef,  \
					CAT2(meth,_amg),AMGf_noright | AMGf_unary)
#define RvDEEPCP(rv) STMT_START { SV* tmpRef=SvRV(rv);      \
  if (SvREFCNT(tmpRef)>1) {                 \
    SvREFCNT_dec(tmpRef);                   \
    SvRV(rv)=AMG_CALLun(rv,copy);        \
  } } STMT_END

// tools\x86\perl\lib\core\regexp.h
#define ROPT_ANCH		(ROPT_ANCH_BOL|ROPT_ANCH_MBOL|ROPT_ANCH_GPOS)
#define ROPT_ANCH_SINGLE	(ROPT_ANCH_BOL|ROPT_ANCH_GPOS)
#define RX_MATCH_TAINTED(prog)	((prog)->reganch & ROPT_TAINTED_SEEN)
#define RX_MATCH_TAINTED_on(prog) ((prog)->reganch |= ROPT_TAINTED_SEEN)
#define RX_MATCH_TAINTED_off(prog) ((prog)->reganch &= ~ROPT_TAINTED_SEEN)
#define RX_MATCH_TAINTED_set(prog, t) ((t) \
				       ? RX_MATCH_TAINTED_on(prog) \
				       : RX_MATCH_TAINTED_off(prog))
#define ReREFCNT_inc(re) ((re && re->refcnt++), re)

// tools\x86\perl\lib\core\scope.h
#define SAVEGENERICSV(s)	save_generic_svref((SV**)&(s))

// tools\x86\perl\lib\core\sv.h
#    define ATOMIC_INC(count) atomic_inc(&count)
#    define ATOMIC_DEC_AND_TEST(res,count) (res = atomic_dec_and_test(&count))
#    define SvREFCNT_inc(sv)	\
	((PL_Sv=(SV*)(sv)), (PL_Sv && ATOMIC_INC(SvREFCNT(PL_Sv))), (SV*)PL_Sv)
#define SvUPGRADE(sv, mt) (SvTYPE(sv) >= mt || sv_upgrade(sv, mt))
#define SVf_OK		(SVf_IOK|SVf_NOK|SVf_POK|SVf_ROK| \
			 SVp_IOK|SVp_NOK|SVp_POK)
#define SvOOK_off(sv)		(SvOOK(sv) && sv_backoff(sv))
#define Gv_AMG(stash)           (PL_amagic_generation && Gv_AMupdate(stash))
#define SvTAINTED(sv)	  (SvMAGICAL(sv) && sv_tainted(sv))
#define SvPV_force(sv, lp) sv_pvn_force(sv, &lp)
#define SvPV(sv, lp) sv_pvn(sv, &lp)
#define SvPVx(sv, lp) sv_pvn(sv, &lp)
#define SvPVx_force(sv, lp) sv_pvn_force(sv, &lp)
#define SvPV(sv, lp) \
    (SvPOK(sv) ? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_2pv(sv, &lp))
#  define SvTRUE(sv) (						\
    !sv								\
    ? 0								\
    :    SvPOK(sv)						\
	?   (({XPV *nxpv = (XPV*)SvANY(sv);			\
	     nxpv &&						\
	     (*nxpv->xpv_pv > '0' ||				\
	      nxpv->xpv_cur > 1 ||				\
	      (nxpv->xpv_cur && *nxpv->xpv_pv != '0')); })	\
	     ? 1						\
	     : 0)						\
	:							\
	    SvIOK(sv)						\
	    ? SvIVX(sv) != 0					\
	    :   SvNOK(sv)					\
		? SvNVX(sv) != 0.0				\
		: sv_2bool(sv) )
#  define SvTRUE(sv) (						\
    !sv								\
    ? 0								\
    :    SvPOK(sv)						\
	?   ((PL_Xpv = (XPV*)SvANY(sv)) &&			\
	     (*PL_Xpv->xpv_pv > '0' ||				\
	      PL_Xpv->xpv_cur > 1 ||				\
	      (PL_Xpv->xpv_cur && *PL_Xpv->xpv_pv != '0'))	\
	     ? 1						\
	     : 0)						\
	:							\
	    SvIOK(sv)						\
	    ? SvIVX(sv) != 0					\
	    :   SvNOK(sv)					\
		? SvNVX(sv) != 0.0				\
		: sv_2bool(sv) )
#define SvIMMORTAL(sv) ((sv)==&PL_sv_undef || (sv)==&PL_sv_yes || (sv)==&PL_sv_no)
#define boolSV(b) ((b) ? &PL_sv_yes : &PL_sv_no)

// tools\x86\perl\lib\core\thread.h
#define MUTEX_INIT(m)						\
    STMT_START {						\
	Zero((m), 1, perl_mutex);                               \
	if (pthread_mutex_init((m), pthread_mutexattr_default))	\
	    croak("panic: MUTEX_INIT");				\
    } STMT_END
#define MUTEX_INIT(m)						\
    STMT_START {						\
	if (pthread_mutex_init((m), pthread_mutexattr_default))	\
	    croak("panic: MUTEX_INIT");				\
    } STMT_END
#define COND_INIT(c)						\
    STMT_START {						\
	if (pthread_cond_init((c), pthread_condattr_default))	\
	    croak("panic: COND_INIT");				\
    } STMT_END
#define COND_SIGNAL(c)				\
    STMT_START {				\
	if (pthread_cond_signal((c)))		\
	    croak("panic: COND_SIGNAL");	\
    } STMT_END
#define COND_WAIT(c, m)				\
    STMT_START {				\
	if (pthread_cond_wait((c), (m)))	\
	    croak("panic: COND_WAIT");		\
    } STMT_END
#define JOIN(t, avp) 					\
    STMT_START {					\
	if (pthread_join((t)->self, (void**)(avp)))	\
	    croak("panic: pthread_join");		\
    } STMT_END

// tools\x86\perl\lib\core\xsub.h
#define XST_mNO(i)    (ST(i) = &PL_sv_no   )
#define XST_mYES(i)   (ST(i) = &PL_sv_yes  )
#define XST_mUNDEF(i) (ST(i) = &PL_sv_undef)

// tools\x86\perl\site\lib\xml\parser\expat\xmltok\xmltok.h
#define XmlUtf8Convert(enc, fromP, fromLim, toP, toLim) \
  (((enc)->utf8Convert)(enc, fromP, fromLim, toP, toLim))
#define XmlUtf16Convert(enc, fromP, fromLim, toP, toLim) \
  (((enc)->utf16Convert)(enc, fromP, fromLim, toP, toLim))
```

