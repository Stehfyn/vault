# Bitmap, Pixel, Color, And Image Format Math

[Macros index](<macros.md>)

## Curated Candidates

```c
// shell\comctl32\v6\lvtile.c
#define _GetStateCX(plv) \
            ((plv->himlState && !ListView_IsSimpleSelect(plv)) ? plv->cxState:0)

#define _GetStateCY(plv) \
            (plv->himlState ? plv->cyState:0)

// shell\comctl32\v6\blur.cpp
#define ARGB(a,r,g,b)          ((COLORREF)(( \
                         ((BYTE)(r))       | \
                 ((WORD) ((BYTE)(g))<< 8)) | \
                (((DWORD)((BYTE)(b))<<16)) | \
                (((DWORD)((BYTE)(a))<<24))))

#define PREMULTIPLY(c, alpha)  ((( ((c) * (alpha)) + 128) >> 8) + 1)

// drivers\wdm\vbi\nabtsfec\wdm\codmain.h
#define BIT(n)             (((unsigned long)1)<<(n))
#define BITSIZE(v)         (sizeof(v)*8)
#define SETBIT(array,n)    (array[(n)/BITSIZE(*array)] |= BIT((n)%BITSIZE(*array)))
#define CLEARBIT(array,n)  (array[(n)/BITSIZE(*array)] &= ~BIT((n)%BITSIZE(*array)))
#define TESTBIT(array,n)   (BIT((n)%BITSIZE(*array)) == (array[(n)/BITSIZE(*array)] & BIT((n)%BITSIZE(*array))))

// drivers\storage\port\scsi\miniport\mylex\dac2w2k\sys\drlapi.h
#define	BITINDEX(POS)	(POS >> 5)		/* get index in array */
#define	BITMASK(POS)	(1 << (POS & 0x1F))	/* get mask bit in 32 bit */
#define	TESTBIT(ADDR,POS)	(ADDR[BITINDEX(POS)] & BITMASK(POS))
#define	SETBIT(ADDR,POS)	 ADDR[BITINDEX(POS)] |= BITMASK(POS)
#define	RESETBIT(ADDR,POS)	 ADDR[BITINDEX(POS)] &= ~(BITMASK(POS))

// enduser\netmeeting\as\as16\as16.h
#define BitmapWidth(cx, bits)\
    ((((cx)*(bits) + 0x0F) & ~0x0F) >> 3)

#define BitmapSize(cx, cy, planes, bits)\
    (BitmapWidth(cx, bits) * (cy) * (planes))

// admin\wmi\wbem\providers\win32provider\providers\desktop.h
#define CALC_IT(x) (x < 0 ? ((x)/(-15)) : x)

// shell\comctl32\v6\ctlspriv.h
#define CBBITMAPBITS(cx, cy, cPlanes, cBitsPerPixel)    \
        (((((cx) * (cBitsPerPixel) + 15) & ~15) >> 3)   \
        * (cPlanes) * (cy))

// shell\themes\uxtheme\handlers.h
#define CHECK_MSGMASK( prgMsgMask, nMsg )  ((prgMsgMask[nMsg/8] & MAKE_MSGBIT(nMsg)) != 0)

#define CLEAR_MSGMASK( prgMsgMask, nMsg )  (prgMsgMask[nMsg/8] &= ~MAKE_MSGBIT(nMsg))

// enduser\netmeeting\as\h\cm.h
#define CM_BYTES_FROM_WIDTH(width) ((((width)+15)/16)*2)

#define ROW_WORD_PAD(cbUnpaddedRow) \
    (((cbUnpaddedRow) + 1) & ~1)

#define CURSOR_DIB_BITS_SIZE(cx, cy, bpp)   \
                                       (ROW_WORD_PAD(((cx) * (bpp))/8) * (cy))

// windows\core\ntcon\inc\output.h
#define CURSOR_SIZE_IN_PIXELS(FONT_SIZE_Y,SIZE) ((((FONT_SIZE_Y)*(SIZE))+99)/100)
#define CURSOR_Y_OFFSET_IN_PIXELS(FONT_SIZE_Y,YSIZE) ((FONT_SIZE_Y) - (YSIZE))

// printscan\print\drivers\usermode\msplot\plotter\htblt.c
#define DEVTODECI(pPdev, x)     DIVRNDUP((x) * 720, (pPDev)->lCurResolution)

// multimedia\dshow\filters\lin21dec\l21dbase.h
#define DWORDALIGNWIDTH(bmih) (((((bmih).biWidth * (bmih).biBitCount) + 31) & ~31) >> 3)

// enduser\netmeeting\av\codecs\dec\dech261\yuv2rgb.c
#define GetRGB555(in16, r, g, b) b = (in16>>7)&0xF8; \
                                 g = (in16>>2)&0xF8; \
                                 r = (in16<<3)&0xF8

#define AddRGB555(in16, r, g, b) b += (in16>>7)&0xF8; \
                                 g += (in16>>2)&0xF8; \
                                 r += (in16<<3)&0xF8

#define PutRGB565(r, g, b, out16) out16 = ((r&0xf8)<<8)|((g&0xfC)<<3)|((b&0xf8)>>3)

#define PutRGB555(r, g, b, out16) out16 = ((r&0xf8)<<7)|((g&0xf8)<<2)|((b&0xf8)>>3)

// shell\comctl32\v6\image.cpp
#define IS_WHITE_PIXEL(pj,x,y,cScan) \
    ((pj)[((y) * (cScan)) + ((x) >> 3)] & (1 << (7 - ((x) & 7))))

#define BITS_ALL_WHITE(b) (b == 0xff)

// shell\iecontrols\framewrk\util.cpp
#define MAP_PIX_TO_LOGHIM(x,ppli)   ( (HIMETRIC_PER_INCH*(x) + ((ppli)>>1)) / (ppli) )
#define MAP_LOGHIM_TO_PIX(x,ppli)   ( ((ppli)*(x) + HIMETRIC_PER_INCH/2) / HIMETRIC_PER_INCH )

// printscan\print\drivers\usermode\unidrv2\control\init.h
#define MICRON_TO_PIXEL(micron, dpi) MulDiv(micron, dpi, 25400)
#define MICRON_TO_MASTER(size_in_micron, MU) MulDiv(size_in_micron, MU, 25400)
#define MASTER_TO_MICRON(size_in_master, MU) MulDiv(size_in_master, 25400, MU)

// shell\comctl32\commonimagelist.h
#define offsetofclass(base, derived) ((ULONG_PTR)(static_cast<base*>((derived*)8))-8)
#define FindImageListBase(punk) (CImageListBase*)(CImageListValidation*)((UINT_PTR)punk - offsetofclass(CImageListValidation, CImageListBase));

// enduser\netmeeting\as\h\cm.h
#define PALETTE_SIZE(BPP)   (((BPP) > 8) ? 0 : ((1<<(BPP)) * sizeof(RGBQUAD)))

#define POINTER_TO_DIB_BITS(pDIB)                     \
        ((void *) ((LPBYTE)(pDIB) + DIB_BITS_OFFSET(pDIB)) )

#define DIB_BITS_OFFSET(pDIB)                         \
        (PALETTE_SIZE((pDIB)->bmiHeader.biBitCount) +   \
        sizeof(BITMAPINFOHEADER))

// enduser\netmeeting\ui\nmctl1\nmchatctl.h
#define PIX_FROM_DLGU_X( XDLGU, XDBU )  MulDiv(XDLGU, XDBU, 4 )
#define PIX_FROM_DLGU_Y( YDLGU, YDBU )  MulDiv(YDLGU, YDBU, 8 )

// enduser\netmeeting\av\codecs\dec\dech261\idct_scl.c
#define POINT      20
#define POINTROUND (0x101 << (POINT - 1))

#define IDCTAdjust(val)  (((val + POINTROUND) >> POINT) - 128)

#define IDCTAdjust128(val)  ((val + POINTROUND) >> POINT)

// shell\comctl32\v6\image.cpp
#define RGB555(r,g,b)       (((((r)>>3)&0x1F)<<10) | ((((g)>>3)&0x1F)<<5) | (((b)>>3)&0x1F))
#define R_555(w)            (int)(((w) >> 7) & 0xF8)
#define G_555(w)            (int)(((w) >> 2) & 0xF8)
#define B_555(w)            (int)(((w) << 3) & 0xF8)

#define RGB_to_Gray(x) ((54 * GetRValue((x)) + 183 * GetGValue((x)) + 19 * GetBValue((x))) >> 8)

// shell\themes\uxtheme\handlers.h
#define SET_MSGMASK( prgMsgMask, nMsg )    (prgMsgMask[nMsg/8] |= MAKE_MSGBIT(nMsg))

// windows\core\ntgdi\fondrv\tt\mssipotf\fs\scglobal.h
#define SUBPIX          64L             /* sub pixels per pix */
#define SUBHALF         32L             /* one half of SUBPIX */
#define SUBSHFT         6               /* log base two of SUBPIX */

#define ONSCANLINE(y)   ((y) & (SUBPIX - 1L)) == SUBHALF
#define SCANABOVE(y)    ((((y) + SUBHALF) & (-SUBPIX)) + SUBHALF)
#define SCANBELOW(y)    ((((y) - SUBHALF - 1L) & (-SUBPIX)) + SUBHALF)

// shell\comctl32\v6\treeview.h
#define TV_StateIndex(pitem) ((int)(((DWORD)((pitem)->state) >> 12) & 0xF))

#define TV_NextWatchItem(pTree, pwi) \
    ((pwi)->fStale || ((pwi)->hti = (pwi)->hti->hNext)), \
     (pwi)->fStale = FALSE

// multimedia\directx\dxg\dd\ddraw\main\ddalias.c
#define WIDTH_TO_BYTES( bpp, w ) ( ( ( ( w ) * ( bpp ) ) + 7 ) >> 3 )

// shell\osshell\accesory\clipbrd\dib.h
#define WIDTHBYTES(i)        ((i+31)/32*4)

// shell\comctl32\v6\ctlspriv.h
#define WIDTHBYTES(cx, cBitsPerPixel)   \
        ((((cx) * (cBitsPerPixel) + 31) / 32) * 4)

// shell\comdlg32\dlgs.c
#define xDUsToPels(DUs, lDlgBaseUnits) \
   (int)(((DUs) * (int)LOWORD((lDlgBaseUnits))) / 4)

#define yDUsToPels(DUs, lDlgBaseUnits) \
   (int)(((DUs) * (int)HIWORD((lDlgBaseUnits))) / 8)

// enduser\netmeeting\av\codecs\intel\h263\dxap.h
#define YFROM(R, G, B) (U32)((( 16843 * R) + ( 33030 * G) + (  6423 * B) + 65536*16) /65536)
#define UFROM(R, G, B) (U32)((( -9699 * R) + (-19071 * G) + ( 28770 * B) + 65536*128)/65536)
#define VFROM(R, G, B) (U32)((( 28770 * R) + (-24117 * G) + ( -4653 * B) + 65536*128)/65536)

#define CLAMP8(x) (U8)((x) > 255 ? 255 : ((x) < 0 ? 0 : (x)))

// termsrv\remdsk\rds\as\h\bmc.h
#define BYTES_IN_SCANLINE(width, bpp)   ((((width)*(bpp))+31)/32)*4

#define BYTES_IN_BITMAP(width, height, bpp)  (BYTES_IN_SCANLINE(width, bpp)*height)

// printscan\faxsrv\src\setup\win9xupg\awd\resexec\glyph.cpp
#define CEIL32(val) (((val) + 31) & ~31)

// termsrv\remdsk\rds\as\h\winddi40.h
#define FXTOLFLOOR(x)       ((x)>>4)

#define FXTOLCEILING(x)     ((x + 0x0F)>>4)

#define FXTOLROUND(x)       ((((x) >> 3) + 1) >> 1)

// multimedia\danim\src\filters\strmbase\amvideo.h
#define DIBWIDTHBYTES(bi) (DWORD)WIDTHBYTES((DWORD)(bi).biWidth * (DWORD)(bi).biBitCount)

#define _DIBSIZE(bi) (DIBWIDTHBYTES(bi) * (DWORD)(bi).biHeight)

#define DIBSIZE(bi) ((bi).biHeight < 0 ? (-1)*(_DIBSIZE(bi)) : _DIBSIZE(bi))

#define BIT_MASKS_MATCH(pbmi1,pbmi2)                                \
    (((pbmi1)->dwBitMasks[iRED] == (pbmi2)->dwBitMasks[iRED]) &&        \
     ((pbmi1)->dwBitMasks[iGREEN] == (pbmi2)->dwBitMasks[iGREEN]) &&    \
     ((pbmi1)->dwBitMasks[iBLUE] == (pbmi2)->dwBitMasks[iBLUE]))

// windows\advcore\gdiplus\engine\fondrv\tt\scaler\fscdefs.h
#define ROWBYTESLONG(x)     (((x + 31) >> 5) << 2)

// base\ntsetup\textmode\spddlang\fe\fefont.h
#define CJ_DIB8_SCAN(cx) ((((cx) + 7) & ~7) >> 3)

#define CJ_DIB8( cx, cy ) (CJ_DIB8_SCAN(cx) * (cy))

// base\ntsetup\billbrd\animate.c
#define GetInvertRGB(rgb) (RGB(255 - GetRValue(rgb), 255 - GetGValue(rgb), 255 - GetBValue(rgb)))

// base\ntos\cache\cc.h
#define MBCB_BITMAP_RANGE                (MBCB_BITMAP_BLOCK_SIZE * 8 * PAGE_SIZE)

#define MBCB_BITMAP_INITIAL_SIZE         (2 * sizeof(BITMAP_RANGE))
```

## Backlog

```c
// admin\activec\controls\cic\syscolorctrl.h
#define GETPROPS(prop_name) \
    STDMETHOD(get_RGB##prop_name)(/*[out, retval]*/ long *pVal); \
    STDMETHOD(get_HEX##prop_name)(/*[out, retval]*/ BSTR *pVal);

// admin\activec\conui\stdbar.h
#define  MMC_TOOLBTN_COLORREF RGB(255, 0, 255)

// admin\netui\common\h\bltmeter.hxx
#define BLUE    RGB( 0, 0, 255 )

// admin\netui\common\hack\dos\pwin16.h
#define GET_WM_CTLCOLOR_HDC(wp, lp, msg)            (HDC)(wp)

// admin\netui\common\hack\dos\windows.h
#define PALETTERGB(r,g,b)   (0x02000000L | RGB(r,g,b))

// admin\netui\common\src\blt\bltcc\dead\bltmeter.hxx
#define BLUE    RGB( 0, 0, 255 )

// admin\netui\macprint\pstodib\print\psprint\psprint.h
#define PSTODIB_DATATYPE TEXT("PSCRIPT1")
#define PSTODIB_STRING TEXT("PSTODIB_")

// admin\netui\macprint\pstodib\ti\src\bass\fsglue.c
  #define fsg_Max45Trick(x,y)     (x == y || x == -y)
#define ISNOTPOWEROF2(n)        ((n) & ((n)-1))

// admin\netui\macprint\pstodib\ti\src\bass\fsglue.h
#define fsg_KeySize()               (sizeof (fsg_SplineKey))
#define fsg_ScanDataSize()          (sizeof (sc_GlobalData))

// admin\netui\macprint\pstodib\ti\src\bass\sc.c
#define ISORT( pBeg, pVal )                                                             \
{                                                                                               \
  register int16 *pj = pBeg;                                                            \
  register int16 nVal = *pVal - 2;                                                      \
  for (; nVal >= 0; --nVal)                                                             \
  {                                                                                                 \
    register int16 v;                                                                   \
    register int16 *pk, *pi;                                                        \
                                                                                                    \
    pk = pj;                                                                                \
    pi = ++pj;                                                                              \
    v = *pj;                                                                                \
    while (*pk > v && pk >= pBeg)                                                       \
      *pi-- = *pk--;                                                                        \
    *pi = v;                                                                                \
  }                                                                                                 \
}
#define LINE(a)   ( !((a & FRACPART) ^ HALF))
#define EQUAL(a,b,c) (a == b && b == c)

// admin\netui\macprint\pstodib\ti\src\bass\sc.h
#define MAXVECTORS 257  /* must be at least 257  = (2 ^ MAXMAXGY) + 1  */

// admin\netui\macprint\pstodib\ti\src\font\dictdata.h
#define   CD_KEY_SIZE(no)   \
          ( (no)*sizeof(fix16) )

// admin\netui\macprint\pstodib\ti\src\font\fntcache.c
#define FARALLOC(n,type)    /* to allocate far data ... */\
            (type far *) fardata((ufix32)n * sizeof(type))

// admin\netui\macprint\pstodib\ti\src\font\mapping.c
#define         UNEXTRACT(code) \
                {\
                    map_state->unextr_code = code;\
                    map_state->unextracted = TRUE;\
                }

// admin\netui\macprint\pstodib\ti\src\font\qemsupp.c
#   define N_PIXEL  (MAXSCANLINES)          /* size of pixel table */

// admin\netui\macprint\pstodib\ti\src\font\ry_font.c
#define FARALLOC(n,type)     /* to allocate far data ... */\
                             (type far *) fardata((ufix32)n * sizeof(type))

// admin\netui\macprint\pstodib\ti\src\gei\geiio.h
#   define  FMODQ_OPEN(f,mq)            \
                ( *((mq)->fmod->fmod_open)  )( f, mq )
#   define  FMODQ_IOCTL(f,mq,req,arg)   \
                ( *((mq)->fmod->fmod_ioctl) )( f, mq, req, arg )
#   define  FMODQ_NAME(mq)          \
                (                                                           \
                    (mq) != (GEIfmodq_t FAR *)NULL?                         \
                        ( (mq)->fmod->fmod_name )  :  (char FAR *)NULL      \
                )
#   define  FMODQ_READ(f,mq,buf,s)  \
                (                                                           \
                    (mq) != (GEIfmodq_t FAR *)NULL?                         \
                        ( *((mq)->fmod->fmod_read) )( f, mq, buf, s )  :    \
                        GESio_read( f, buf, s )                             \
                )
#   define  FMODQ_WRITE(f,mq,buf,s) \
                (                                                           \
                    (mq) != (GEIfmodq_t FAR *)NULL?                         \
                        ( *((mq)->fmod->fmod_write) )( f, mq, buf, s )  :   \
                        GESio_write( f, buf, s )                            \
                )
#   define  FMODQ_FLUSH(f,mq)       \
                (                                                           \
                    (mq) != (GEIfmodq_t FAR *)NULL?                         \
                        ( *((mq)->fmod->fmod_flush) )( f, mq )  :           \
                        GESio_flush( f )                                    \
                )
#   define  FMODQ_UNGETC(c,f,mq)    \
                (                                                           \
                    (mq) != (GEIfmodq_t FAR *)NULL?                         \
                        ( *((mq)->fmod->fmod_ungetc) )( c, f, mq )  :       \
                        GESio_ungetc( c, f )                                \
                )
#   define  GEIio_isopen( f )       \
                ( (f) != (GEIFILE FAR *)NULL  &&  (f)->f_handle != EOF )
#   define  GEIio_setedit( f )      { (f)->f_oldtype = (f)->f_type;     \
                                      (f)->f_type = _S_IFEDIT; }
#   define         _O_RDWR      ( _O_RDONLY | _O_WRONLY )   /* not support */
#   define  GEIio_source( )         \
            ctty->devname
#   define  GEIio_getc( f )         \
                ( GEIio_isreadable(f)? FMODQ_GETC( f, (f)->f_modq ) : EOF )
#   define  GEIio_ungetc( c, f )    \
                (                                                   \
                        c!=EOF?              \
                        FMODQ_UNGETC( c, f, (f)->f_modq ) : EOF \
                )
#   define  GEIio_putc( f, c )      \
                ( GEIio_iswriteable(f)? FMODQ_PUTC( f, (f)->f_modq, c ) : EOF )
#   define  GEIio_getc( f )         \
                ( FMODQ_GETC( f, (f)->f_modq ) )
#   define  GEIio_ungetc( c, f )    \
                (                                                   \
                    GEIio_isreadable( f )  &&  c!=EOF?              \
                        FMODQ_UNGETC( c, f, (f)->f_modq ) : EOF     \
                )
#   define  GEIio_putc( f, c )      \
                ( FMODQ_PUTC( f, (f)->f_modq, c ) )

// admin\netui\macprint\pstodib\ti\src\gei\geipm.c
#define SIZEmagicnum            sizeof( unsigned long )
#define     SIZEleftmargin      sizeof( unsigned long )
#define     SIZEtopmargin       sizeof( unsigned long )
#define     SIZEbaud            sizeof( unsigned char )
#define     SIZEflowpari        sizeof( unsigned char )
#define     SIZEstopdata        sizeof( unsigned char )
#define     SIZEjobtout         sizeof( unsigned long )
#define     SIZEmanualtout      sizeof( unsigned long )
#define     SIZEwaittout        sizeof( unsigned long )
#define SIZEstsstart            sizeof( unsigned char )
#define SIZEdplylistsize        sizeof( unsigned long )
#define SIZEfontcachesze        sizeof( unsigned long )
#define SIZEatalksize           sizeof( unsigned long )
#define SIZEhwiomode            sizeof( unsigned char )
#define SIZEswiomode            sizeof( unsigned char )
#define SIZEmagicnum            sizeof( unsigned long )
#define     SIZEleftmargin      sizeof( unsigned long )
#define     SIZEtopmargin       sizeof( unsigned long )
#define     SIZEbaud            sizeof( unsigned char )
#define     SIZEflowpari        sizeof( unsigned char )
#define     SIZEstopdata        sizeof( unsigned char )
#define     SIZEjobtout         sizeof( unsigned long )
#define     SIZEmanualtout      sizeof( unsigned long )
#define     SIZEwaittout        sizeof( unsigned long )
#define SIZEstsstart            sizeof( unsigned char )
#define SIZEdplylistsize        sizeof( unsigned long )
#define SIZEfontcachesze        sizeof( unsigned long )
#define SIZEatalksize           sizeof( unsigned long )
#define SIZEhwiomode            sizeof( unsigned char )
#define SIZEswiomode            sizeof( unsigned char )

// admin\netui\macprint\pstodib\ti\src\gei\gesdev.h
#   define  MINdev( dev )           ( 0x00FF & (dev) )

// admin\netui\macprint\pstodib\ti\src\gei\gesmem.c
#define     MBLK_RDUP(n)    (  ((n) + sizeof(mblk_t) - 1) / sizeof(mblk_t)  )
#define     MBLK_RDDN(n)    (  (n) / sizeof(mblk_t)  )
#define     NUMOFMBLK(n)    (  (n) / sizeof(mblk_t)  )

// admin\netui\macprint\pstodib\ti\src\graph\fillproc.h
#define GMA_i186(A)    ((ufix32) (GMS_i186 + (A & 0x0000FFFFL)))
#define AND(X,Y)        (X & Y)
#define OR(X,Y)         (X | Y)

// admin\netui\macprint\pstodib\ti\src\graph\graphics.h
#define         IS_ZERO(f) ((ufix32)  (!((*((long FAR *)(&f))) & 0x7fffffffL)))
#define         IS_NOTZERO(f) ((ufix32)  (((*((long FAR *)(&f))) & 0x7fffffffL)))
#define LFX2F(lfx)      ((real32)(lfx) / 65536)         |* @FIXPNT *|
#define F2SFX12_T(f)    ((sfix_t)((f) *  4096))                  |* @STK_INT *|
#define F_OF_LFX(lfix)  ( (lfix) & 0x0000FFFF )     |* take fraction part    *|
#define F_OF_SFX(sfix)  ( (sfix) & 7)               |* take fraction part    *|
#define SIGN(f)            (((f) & 0x80000000L))
#define EXP(f)  ((ufix32)  (((f) & 0x7f800000L)))
#define MAT(f)  ((ufix32)  (((f) & 0x007fffffL)))
#define MAGN(f) ((ufix32)  (((*((long32 FAR *)(&f))) & 0x7fffffffL)))
#define SIGN_F(f) ((ufix32)  (((*((long FAR *)(&f))) & 0x80000000L)))

// admin\netui\macprint\pstodib\ti\src\graph\halftone.h
#define CGS_SpotOrder  (&spot_table[CGS_SpotIndex])             /* spot order entry             */

// admin\netui\macprint\pstodib\ti\src\lang\arith.h
#define     IS_INFINITY(obj)\
            ((TYPE(obj) == REALTYPE) && (VALUE(obj) == INFINITY))
#define     IS_NUM_OBJ(obj)\
            ((TYPE(obj) == REALTYPE) || (TYPE(obj) == INTEGERTYPE))
#define     IS_ARITH_MUL(val)\
            (!(val & 0xFFFF8000) || ((val & 0xFFFF8000) == 0xFFFF8000))

// admin\netui\macprint\pstodib\ti\src\lang\dict_tab.c
#define     INTOPREUBFD  ((OPERATORTYPE | P1_EXECUTABLE) | P1_ROM)

// admin\netui\macprint\pstodib\ti\src\lang\file.h
#define     F_RW                (F_READ | F_WRITE)

// admin\netui\macprint\pstodib\ti\src\lang\init1pp.h
#define             CACHESTRING     "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK\
LMNOPQRSTUVWXYZ0123456789.,;?:-()\'\"!+[]$%&*/_=@#`{}<>^~|\\"  /* 94 chars */

// admin\netui\macprint\pstodib\ti\src\lang\scanner.h
#define         ISDELIMITOR(c)\
        (ISWHITESPACE(c) || ISSPECIALCH(c))

// admin\netui\macprint\pstodib\ti\src\lang\user.h
#define     SET_NULL_OBJ(obj)\
            {\
                TYPE_SET(obj, NULLTYPE) ;\
                ACCESS_SET(obj, UNLIMITED) ;\
                ATTRIBUTE_SET(obj, LITERAL) ;\
                ROM_RAM_SET(obj, RAM) ;\
                LEVEL_SET(obj, current_save_level) ;\
                (obj)->length = 0 ;\
                (obj)->value = 0 ;\
            }
#define     SET_TRUE_OBJ(obj)\
            {\
                TYPE_SET(obj, BOOLEANTYPE) ;\
                ACCESS_SET(obj, UNLIMITED) ;\
                ATTRIBUTE_SET(obj, LITERAL) ;\
                ROM_RAM_SET(obj, RAM) ;\
                LEVEL_SET(obj, current_save_level) ;\
                (obj)->length = 0 ;\
                (obj)->value = TRUE ;\
            }
#define     SET_FALSE_OBJ(obj)\
            {\
                TYPE_SET(obj, BOOLEANTYPE) ;\
                ACCESS_SET(obj, UNLIMITED) ;\
                ATTRIBUTE_SET(obj, LITERAL) ;\
                ROM_RAM_SET(obj, RAM) ;\
                LEVEL_SET(obj, current_save_level) ;\
                (obj)->length = 0 ;\
                (obj)->value = FALSE ;\
            }

// admin\netui\macprint\pstodib\ti\src\win\trueim.h
#define     F2L(ff)     (*((long32 far *)(&ff)))
#define     L2F(ll)     (*((real32 far *)(&ll)))
#define     VALUE(obj)\
            ((obj)->value)

// admin\netui\macprint\pstodib\ti\src\win\wintt.c
    #define IS_ZERO(f) ((unsigned long)  (!((*((long FAR *)(&f))) & 0x7fffffffL)))

// admin\snapin\wsecmgr\hlpids.h
#define IDH_194_304	19923138	// Directory Replicator: "E&xclude from future configurations and analyses" (Button)
#define IDH_194_236	15466690	// Directory Replicator: "&Manual" (Button)
#define IDH_194_237	15532226	// Directory Replicator: "&Automatic" (Button)
#define IDH_194_307	20119746	// Directory Replicator: "&Edit Security..." (Button)
#define IDH_194_238	15597762	// Directory Replicator: "&Disabled" (Button)
#define IDH_194_308	20185282	// Directory Replicator: "&Service Security" (Button)

// admin\wizards\addgrpw\transbmp.cpp
#define rgbWhite RGB(255,255,255)

// admin\wizards\addusrw\transbmp.cpp
#define rgbWhite RGB(255,255,255)

// admin\wizards\liccomp\transbmp.cpp
#define rgbWhite RGB(255,255,255)

// admin\wmi\wbem\winmgmt\wmitest\toolbarex.cpp
#define RGB_TO_RGBQUAD(r,g,b)   (RGB(b,g,r))
#define CLR_TO_RGBQUAD(clr)     (RGB(GetBValue(clr), GetGValue(clr), GetRValue(clr)))

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\comm.h
#define ColorText(nState)   (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHTTEXT : COLOR_WINDOWTEXT)
#define ColorBk(nState)     (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_WINDOW)
#define ColorMenuText(nState)   (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHTTEXT : COLOR_MENUTEXT)
#define ColorMenuBk(nState)     (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_MENU)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\dobj.c
#define DT_CALC         (DT_CALCRECT | DT_CENTER | DT_SINGLELINE | DT_NOPREFIX)

// com\mobile\syncmgr\test\brfhndlr\rover\filesync\syncui\inc\comctrlp.h
#define BL_GETITEMRECT          (WM_USER+7)

// com\ole2ui32\iconbox.h
#define IBXM_IMAGESET                   (WM_USER+0)
#define IBXM_IMAGEGET                   (WM_USER+1)

// com\ole2ui32\resimage.h
#define RGBTRANSPARENT                  RGB(0, 255, 255)
#define RIM_IMAGESET                   (WM_USER+0)
#define RIM_IMAGEGET                   (WM_USER+1)

// com\ole32\ole232\util\utils.cpp
#define UT_DM_COMPARISON_FIELDS (DM_ORIENTATION  |  \
                                 DM_PAPERSIZE    |  \
                                 DM_PAPERLENGTH  |  \
                                 DM_PAPERWIDTH   |  \
                                 DM_SCALE        |  \
                                 DM_PRINTQUALITY |  \
                                 DM_COLOR)

// com\ole32\olethunk\ole16\inc\olestd.h
#define AreRectsEqual(lprc1, lprc2)     \
    (((lprc1->top == lprc2->top) &&     \
      (lprc1->left == lprc2->left) &&   \
      (lprc1->right == lprc2->right) && \
      (lprc1->bottom == lprc2->bottom)) ? TRUE : FALSE)

// com\ole32\olethunk\ole16\inc\windows.h
#define PALETTERGB(r,g,b)   (0x02000000L | RGB(r,g,b))
#define EM_GETRECT	        (WM_USER+2)
#define EM_SETRECT	        (WM_USER+3)
#define EM_SETRECTNP	        (WM_USER+4)
#define LB_GETITEMRECT	       (WM_USER+25)

// com\ole32\stg\drt\drt.cxx
#define TFE_ANY                 (TFE_DIRECT | TFE_TRANSACTED | TFE_INDEPENDENT)

// com\oleutest\letest\ole2ui\iconbox.h
#define IBXM_IMAGESET                   (WM_USER+0)
#define IBXM_IMAGEGET                   (WM_USER+1)

// com\oleutest\letest\ole2ui\olestd.h
#define AreRectsEqual(lprc1, lprc2)     \
    (((lprc1->top == lprc2->top) &&     \
      (lprc1->left == lprc2->left) &&   \
      (lprc1->right == lprc2->right) && \
      (lprc1->bottom == lprc2->bottom)) ? TRUE : FALSE)

// com\oleutest\letest\ole2ui\resimage.h
#define RGBTRANSPARENT                  RGB(0, 255, 255)
#define RIM_IMAGESET                   (WM_USER+0)
#define RIM_IMAGEGET                   (WM_USER+1)

// com\oleutest\stgdrt\drt.cxx
#define TFE_ANY                 (TFE_DIRECT | TFE_TRANSACTED | TFE_INDEPENDENT)

// com\rpc\midl\analysis\optprop.hxx
#define DIR_IN_OUT		( ANA_CUR_DIRECTION_IN | ANA_CUR_DIR_OUT )

// com\rpc\midl\front\semantic.cxx
#define DIRECT_PARTIAL_IGNORE (DIRECT_IN | DIRECT_OUT | 4 )
#define DIRECT_IN_OUT   (DIRECT_IN | DIRECT_OUT)

// com\rpc\ndrexts\ndrexts\format.cxx
#define PRINT_REDIRECT_TYPE(type,func)      \
void FORMAT_PRINTER::HANDLE_##type() { \
   func();                                  \
}

// drivers\storage\fdc\fdc\fdc_data.h
#define ENABLE_CONTROLLER_IMAGE(FdoExtension) \
{ \
    if (IsNEC_98) { \
        FdoExtension->DriveControlImage &= ~( DRVCTL_ENABLE_CONTROLLER ); \
        FdoExtension->DriveControlImage |= DRVCTL_AI_ENABLE; \
    } else { \
        FdoExtension->DriveControlImage |= DRVCTL_ENABLE_CONTROLLER; \
    } \
}

// drivers\storage\fdc\mode3fdc\desk2fdc\fdc_data.h
#define ENABLE_CONTROLLER_IMAGE(FdoExtension) \
{ \
    if (IsNEC_98) { \
        FdoExtension->DriveControlImage &= ~( DRVCTL_ENABLE_CONTROLLER ); \
        FdoExtension->DriveControlImage |= DRVCTL_AI_ENABLE; \
    } else { \
        FdoExtension->DriveControlImage |= DRVCTL_ENABLE_CONTROLLER; \
    } \
}

// drivers\tpg\hwx\avalanche\src\geofeats.c
#define RECT_OVERLAP(r1, r2) (ONE_D_OVERLAP((r1).left, (r1).right, (r2).left, (r2).right) && ONE_D_OVERLAP((r1).top, (r1).bottom, (r2).top, (r2).bottom))

// drivers\tpg\hwx\holycow\src\nfeature.c
#define RECT_OVERLAP(r1, r2) (ONE_D_OVERLAP((r1).left, (r1).right, (r2).left, (r2).right) && ONE_D_OVERLAP((r1).top, (r1).bottom, (r2).top, (r2).bottom))

// drivers\tpg\hwx\otter\src\otterp.h
#define IsTapRECT(rc)		((rc).right - (rc).left < 25 && (rc).bottom - (rc).top < 25)
#define IsPeriodRECT(rc)	((rc).right - (rc).left < 70 && (rc).bottom - (rc).top < 70)

// drivers\tpg\hwx\tsunami\src\snot\glyphsym.h
#define	LprectGLYPHSYM(gs)			((LPRECT)&((gs)->rect))

// drivers\tpg\hwx\tsunami\src\usa\glyphsym.h
#define	LprectGLYPHSYM(gs)			((LPRECT)&((gs)->rect))

// drivers\video\matrox\mga\disp\bltmil.c
    #define NON_EMPTY_RECT(rcl) ((rcl.right > rcl.left) && (rcl.bottom > rcl.top))

// drivers\video\matrox\mga\disp\mcd.c
#define TOTAL_PIXEL_FORMATS (2 * 2)     // double-buffers * z-buffers

// drivers\video\matrox\mga\disp\mcdclip.c
#define __MCD_CLIP_COLOR(v, a, b, t) \
    v->colors[__MCD_FRONTFACE].r = t*(a->colors[__MCD_FRONTFACE].r      \
        - b->colors[__MCD_FRONTFACE].r) + b->colors[__MCD_FRONTFACE].r; \
    v->colors[__MCD_FRONTFACE].g = t*(a->colors[__MCD_FRONTFACE].g      \
        - b->colors[__MCD_FRONTFACE].g) + b->colors[__MCD_FRONTFACE].g; \
    v->colors[__MCD_FRONTFACE].b = t*(a->colors[__MCD_FRONTFACE].b      \
        - b->colors[__MCD_FRONTFACE].b) + b->colors[__MCD_FRONTFACE].b; \
    v->colors[__MCD_FRONTFACE].a = t*(a->colors[__MCD_FRONTFACE].a      \
        - b->colors[__MCD_FRONTFACE].a) + b->colors[__MCD_FRONTFACE].a
#define __MCD_CLIP_BACKCOLOR(v, a, b, t) \
    v->colors[__MCD_BACKFACE].r = t*(a->colors[__MCD_BACKFACE].r        \
        - b->colors[__MCD_BACKFACE].r) + b->colors[__MCD_BACKFACE].r;   \
    v->colors[__MCD_BACKFACE].g = t*(a->colors[__MCD_BACKFACE].g        \
        - b->colors[__MCD_BACKFACE].g) + b->colors[__MCD_BACKFACE].g;   \
    v->colors[__MCD_BACKFACE].b = t*(a->colors[__MCD_BACKFACE].b        \
        - b->colors[__MCD_BACKFACE].b) + b->colors[__MCD_BACKFACE].b;   \
    v->colors[__MCD_BACKFACE].a = t*(a->colors[__MCD_BACKFACE].a        \
        - b->colors[__MCD_BACKFACE].a) + b->colors[__MCD_BACKFACE].a
#define __MCD_CLIP_INDEX(v, a, b, t) \
    v->colors[__MCD_FRONTFACE].r = t*(a->colors[__MCD_FRONTFACE].r      \
        - b->colors[__MCD_FRONTFACE].r) + b->colors[__MCD_FRONTFACE].r
#define __MCD_CLIP_BACKINDEX(v, a, b, t) \
    v->colors[__MCD_BACKFACE].r = t*(a->colors[__MCD_BACKFACE].r        \
        - b->colors[__MCD_BACKFACE].r) + b->colors[__MCD_BACKFACE].r

// drivers\video\matrox\mga\disp\mcdhw.h
#define SAVE_COLOR(temp, p)\
{\
    temp.r = (p)->colors[0].r;\
    temp.g = (p)->colors[0].g;\
    temp.b = (p)->colors[0].b;\
}
#define RESTORE_COLOR(temp, p)\
{\
    (p)->colors[0].r = temp.r;\
    (p)->colors[0].g = temp.g;\
    (p)->colors[0].b = temp.b;\
}
#define MCDFIXEDRGB(fixColor, fltColor)\
    fixColor.r = (MCDFIXED)(fltColor.r * pRc->rScale);\
    fixColor.g = (MCDFIXED)(fltColor.g * pRc->gScale);\
    fixColor.b = (MCDFIXED)(fltColor.b * pRc->bScale);

// drivers\video\matrox\mga\disp\mcdutil.h
#define MCD_INIT_BUFFER_PARAMS(pMCDSurface, pMCDWnd, pDevWnd, pRc)\
{\
    pRc->hwYOrgBias = pMCDWnd->clipBoundsRect.top;\
\
    if ((pRc)->MCDState.drawBuffer == GL_FRONT) {\
        (pRc)->hwBufferYBias = 0;\
    } else if ((pRc)->MCDState.drawBuffer == GL_BACK) {\
        if (ppdev->pohBackBuffer == pDevWnd->pohBackBuffer) {\
            pRc->hwBufferYBias = pDevWnd->backBufferY;\
        } else {\
            pRc->hwBufferYBias = pDevWnd->backBufferY - \
                                  pMCDWnd->clipBoundsRect.top;\
        }\
    }\
}

// drivers\video\matrox\mga\mini\caddi.h
#define SPANLINE_RGBLeft               (SPANLINE_ZRight + LONG_S)
#define SPANLINE_RGBRight              (SPANLINE_RGBLeft + COLOR3_S)
#define SPANLINE_S                     (SPANLINE_RGBRight + COLOR3_S)
#define TRIANGLE_Vertex0_RGB           (TRIANGLE_Vertex0_XYZ + POINT3_S)
#define TRIANGLE_Vertex1_XYZ           (TRIANGLE_Vertex0_RGB + COLOR3_S)
#define TRIANGLE_Vertex1_RGB           (TRIANGLE_Vertex1_XYZ + POINT3_S)
#define TRIANGLE_Vertex2_XYZ           (TRIANGLE_Vertex1_RGB + COLOR3_S)
#define TRIANGLE_Vertex2_RGB           (TRIANGLE_Vertex2_XYZ + POINT3_S)
#define TRIANGLE_S                     (TRIANGLE_Vertex2_RGB + COLOR3_S)

// drivers\video\matrox\mga\mini\def.h
#define RC_BgColorRGB24             (RC_FgColorRGB24 + LONG_S)
#define RC_ClearColorRGB24          (RC_BgColorRGB24 + LONG_S)
#define RC_FaceRenderMode           (RC_ClearColorRGB24 + LONG_S)
#define LIGHTWS_TmpRGBDiffuse       (LIGHTWS_VV + NORM3_S)
#define LIGHTWS_TmpRGBSpecular      (LIGHTWS_TmpRGBDiffuse + COLOR3_S)
#define LIGHTWS_Tmp                 (LIGHTWS_TmpRGBSpecular + COLOR3_S)
#define VERTEXCACHE_RGB             (VERTEXCACHE_SCoord + ((2*LONG_S)+FLOAT_S))

// drivers\video\ms\3dlabs\perm2\disp\d3dhw.h
#define RGB256_TO_LUMA(r,g,b) (float)(((float)r * 0.001172549019608) + \
                                      ((float)g * 0.002301960784314) + \
                                      ((float)b * 0.000447058823529));

// drivers\video\ms\3dlabs\perm2\disp\dd.h
#define LINEAR_FUDGE(SourcePitch, DestPitch, rectDest) \
((DestPitch - SourcePitch) * (rectDest->top))

// drivers\video\ms\3dlabs\perm2\disp\directx.h
#define CHROMA_UPPER_ALPHA(val) \
    (val | 0xFF000000)
#define CHROMA_332_UPPER(val) \
    (val | 0x001F1F3F)

// drivers\video\ms\3dlabs\perm2\disp\hw.h
#define AREA_STIPPLE_8x8_ENABLE                                             \
    (__PERMEDIA_ENABLE |                                                    \
    AREA_STIPPLE_XSEL(__PERMEDIA_AREA_STIPPLE_8_PIXEL_PATTERN) |            \
    AREA_STIPPLE_YSEL(__PERMEDIA_AREA_STIPPLE_8_PIXEL_PATTERN))
#define AREA_STIPPLE_8x8_ENABLE \
        (__PERMEDIA_ENABLE | \
         AREA_STIPPLE_XSEL(__PERMEDIA_AREA_STIPPLE_8_PIXEL_PATTERN) | \
         AREA_STIPPLE_YSEL(__PERMEDIA_AREA_STIPPLE_8_PIXEL_PATTERN))

// drivers\video\ms\3dlabs\perm2\disp\p2rd.h
#define P2RD_CURSOR_PALETTE_CURSOR_RGB(RGBIndex, Red, Green, Blue) \
{ \
    P2RD_LOAD_INDEX_REG(P2RD_CURSOR_PALETTE_START+3*(int)RGBIndex+0, Red); \
    P2RD_LOAD_INDEX_REG(P2RD_CURSOR_PALETTE_START+3*(int)RGBIndex+1, Green); \
    P2RD_LOAD_INDEX_REG(P2RD_CURSOR_PALETTE_START+3*(int)RGBIndex+2, Blue); \
}
#define P2RD_PALETTE_START_WR(index) \
{ \
    WRITE_P2RDREG_ULONG(P2RD_PAL_WR_ADDR,     (ULONG)(index));    \
}
#define P2RD_PALETTE_START_RD(index) \
{ \
    WRITE_P2RDREG_ULONG(P2RD_PAL_RD_ADDR,     (ULONG)(index));    \
}
#define P2RD_LOAD_PALETTE(red, green, blue) \
{ \
    WRITE_P2RDREG_ULONG(P2RD_PAL_DATA,    (ULONG)(red));      \
    WRITE_P2RDREG_ULONG(P2RD_PAL_DATA,    (ULONG)(green));    \
    WRITE_P2RDREG_ULONG(P2RD_PAL_DATA,    (ULONG)(blue));     \
}
#define P2RD_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    WRITE_P2RDREG_ULONG(P2RD_PAL_WR_ADDR, (ULONG)(index));    \
    WRITE_P2RDREG_ULONG(P2RD_PAL_DATA,    (ULONG)(red));      \
    WRITE_P2RDREG_ULONG(P2RD_PAL_DATA,    (ULONG)(green));    \
    WRITE_P2RDREG_ULONG(P2RD_PAL_DATA,    (ULONG)(blue));     \
}
#define P2RD_READ_PALETTE(red, green, blue) \
{ \
    red   = (UCHAR)(READ_P2RDREG_ULONG(P2RD_PAL_DATA) & 0xff);        \
    green = (UCHAR)(READ_P2RDREG_ULONG(P2RD_PAL_DATA) & 0xff);        \
    blue  = (UCHAR)(READ_P2RDREG_ULONG(P2RD_PAL_DATA) & 0xff);        \
}

// drivers\video\ms\3dlabs\perm2\disp\tvp4020.h
#define TVP4020_PALETTE_START_WR(index) \
{ \
    WRITE_4020REG_ULONG(__TVP4020_PAL_WR_ADDR,     (ULONG)(index));    \
}
#define TVP4020_PALETTE_START_RD(index) \
{ \
    WRITE_4020REG_ULONG(__TVP4020_PAL_RD_ADDR,     (ULONG)(index));    \
}
#define TVP4020_LOAD_PALETTE(red, green, blue) \
{ \
    WRITE_4020REG_ULONG(__TVP4020_PAL_DATA,    (ULONG)(red));      \
    WRITE_4020REG_ULONG(__TVP4020_PAL_DATA,    (ULONG)(green));    \
    WRITE_4020REG_ULONG(__TVP4020_PAL_DATA,    (ULONG)(blue));     \
}
#define TVP4020_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    WRITE_4020REG_ULONG(__TVP4020_PAL_WR_ADDR, (ULONG)(index));    \
    WRITE_4020REG_ULONG(__TVP4020_PAL_DATA,    (ULONG)(red));      \
    WRITE_4020REG_ULONG(__TVP4020_PAL_DATA,    (ULONG)(green));    \
    WRITE_4020REG_ULONG(__TVP4020_PAL_DATA,    (ULONG)(blue));     \
}
#define TVP4020_READ_PALETTE(red, green, blue) \
{ \
    red   = (UCHAR)(READ_4020_ULONG(__TVP4020_PAL_DATA) & 0xff);        \
    green = (UCHAR)(READ_4020_ULONG(__TVP4020_PAL_DATA) & 0xff);        \
    blue  = (UCHAR)(READ_4020_ULONG(__TVP4020_PAL_DATA) & 0xff);        \
}

// drivers\video\ms\3dlabs\perm2\mini\p2rd.h
#define P2RD_PAL_WR_ADDR              ((PULONG)&(pP2RDRegs->RDPaletteWriteAddress.reg))
#define P2RD_PAL_RD_ADDR              ((PULONG)&(pP2RDRegs->RDPaletteAddressRead.reg))
#define P2RD_PAL_DATA                 ((PULONG)&(pP2RDRegs->RDPaletteData.reg))
#define P2RD_CURSOR_PALETTE_CURSOR_RGB(RGBIndex, Red, Green, Blue) \
{ \
    P2RD_LOAD_INDEX_REG(P2RD_CURSOR_PALETTE_START+3*(int)RGBIndex+0, Red); \
    P2RD_LOAD_INDEX_REG(P2RD_CURSOR_PALETTE_START+3*(int)RGBIndex+1, Green); \
    P2RD_LOAD_INDEX_REG(P2RD_CURSOR_PALETTE_START+3*(int)RGBIndex+2, Blue); \
}
#define P2RD_PALETTE_START_WR(index) \
{ \
    VideoPortWriteRegisterUlong(P2RD_PAL_WR_ADDR,     (ULONG)(index));    \
    P2RD_DELAY; \
}
#define P2RD_PALETTE_START_RD(index) \
{ \
    VideoPortWriteRegisterUlong(P2RD_PAL_RD_ADDR,     (ULONG)(index));    \
    P2RD_DELAY; \
}
#define P2RD_LOAD_PALETTE(red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(red));      \
    P2RD_DELAY; \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(green));    \
    P2RD_DELAY; \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(blue));     \
    P2RD_DELAY; \
}
#define P2RD_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(P2RD_PAL_WR_ADDR, (ULONG)(index));    \
    P2RD_DELAY; \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(red));      \
    P2RD_DELAY; \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(green));    \
    P2RD_DELAY; \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(blue));     \
    P2RD_DELAY; \
}
#define P2RD_READ_PALETTE(red, green, blue) \
{ \
    red   = (UCHAR)(VideoPortReadRegisterUlong(P2RD_PAL_DATA) & 0xff);        \
    P2RD_DELAY; \
    green = (UCHAR)(VideoPortReadRegisterUlong(P2RD_PAL_DATA) & 0xff);        \
    P2RD_DELAY; \
    blue  = (UCHAR)(VideoPortReadRegisterUlong(P2RD_PAL_DATA) & 0xff);        \
    P2RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm2\mini\permedia.h
#define LUT_CACHE_SETRGB(idx,zr,zg,zb) {    \
    hwDeviceExtension->LUTCache.LUTCache.LookupTable [idx].RgbArray.Red   = (UCHAR) (zr); \
    hwDeviceExtension->LUTCache.LUTCache.LookupTable [idx].RgbArray.Green = (UCHAR) (zg); \
    hwDeviceExtension->LUTCache.LUTCache.LookupTable [idx].RgbArray.Blue  = (UCHAR) (zb); \
}
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * (VIDEO_MAX_COLOR_REGISTER+1)))

// drivers\video\ms\3dlabs\perm2\mini\tvp4020.h
#define TVP4020_PALETTE_START_WR(index) \
{ \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_WR_ADDR,  (ULONG)(index));    \
    TVP4020_DELAY; \
}
#define TVP4020_PALETTE_START_RD(index) \
{ \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_RD_ADDR,  (ULONG)(index));    \
    TVP4020_DELAY; \
}
#define TVP4020_LOAD_PALETTE(red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(red));      \
    TVP4020_DELAY; \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(green));    \
    TVP4020_DELAY; \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(blue));     \
    TVP4020_DELAY; \
}
#define TVP4020_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_WR_ADDR, (ULONG)(index));    \
    TVP4020_DELAY; \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(red));      \
    TVP4020_DELAY; \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(green));    \
    TVP4020_DELAY; \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(blue));     \
    TVP4020_DELAY; \
}
#define TVP4020_READ_PALETTE(red, green, blue) \
{ \
    red   = (UCHAR)(VideoPortReadRegisterUlong(__TVP4020_PAL_DATA) & 0xff);        \
    TVP4020_DELAY; \
    green = (UCHAR)(VideoPortReadRegisterUlong(__TVP4020_PAL_DATA) & 0xff);        \
    TVP4020_DELAY; \
    blue  = (UCHAR)(VideoPortReadRegisterUlong(__TVP4020_PAL_DATA) & 0xff);        \
    TVP4020_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\dx\directx.h
#define MATCH_GUID(a, b) IsEqualIID(&(a), &(b))
#define CREATE_DRIVER_DC(pGLInfo) (                                     \
    ( ( (pGLInfo)->szDeviceName[7] == '\0' ) &&                         \
        ( (pGLInfo)->szDeviceName[6] == 'Y' ) &&                        \
        ( (pGLInfo)->szDeviceName[5] == 'A' ) &&                        \
        ( (pGLInfo)->szDeviceName[4] == 'L' ) &&                        \
        ( (pGLInfo)->szDeviceName[3] == 'P' ) &&                        \
        ( (pGLInfo)->szDeviceName[2] == 'S' ) &&                        \
        ( (pGLInfo)->szDeviceName[1] == 'I' ) &&                        \
        ( (pGLInfo)->szDeviceName[0] == 'D' ) ) ?                       \
    /* The Win95 and NT4-compatible version */                          \
    ( CreateDC ( "DISPLAY", NULL, NULL, NULL ) ) :                      \
    /* The Win98 and NT5-compatible multimon version */                 \
    ( CreateDC ( NULL, (pGLInfo)->szDeviceName, NULL, NULL ) )          \
    )
#define CHROMA_UPPER_ALPHA(val) \
    (val | 0xFF000000)
#define CHROMA_332_UPPER(val)   \
    (val | 0x001F1F3F)
#define DDSurf_GetPixelFormat(lpLcl)                                   \
                        (&(lpLcl)->lpGbl->ddpfSurface)
#define DDP_LCL(pddp) (((DDRAWI_DDRAWPALETTE_INT *)pdds)->lpLcl)

// drivers\video\ms\3dlabs\perm3\disp\gdi\glint.h
#define READ_ODD_GLINT_SCANLINE_OWNERSHIP(d) \
    ((d) = READ_FAST_ULONG(glintInfo->regs.OddGlintScanlineOwnRd))
#define LOCALBUFFER_PIXEL_WIDTH     (glintInfo->ZBufferWidth)
#define GLINT_GET_VIDEO_SCANLINE(lineNo) \
{ \
    READ_GLINT_CTRL_REG (VTGVLineNumber, lineNo); \
    if (((lineNo) -= glintInfo->scanFudge) < 0) \
        (lineNo) += glintInfo->vtgvLimit; \
}
#define SCANLINE_OWNERSHIP_EVEN_SCANLINES   (GLINT_OWN_SCANLINE_0 | GLINT_SCANLINE_INTERVAL_2)
#define SCANLINE_OWNERSHIP_ODD_SCANLINES    (GLINT_OWN_SCANLINE_1 | GLINT_SCANLINE_INTERVAL_2)

// drivers\video\ms\3dlabs\perm3\disp\gdi\p3rd.h
#define P3RD_CURSOR_PALETTE_CURSOR_RGB(RGBIndex, Red, Green, Blue) \
{ \
    P3RD_LOAD_INDEX_REG(P3RD_CURSOR_PALETTE_START+3*(int)RGBIndex+0, Red); \
    P3RD_LOAD_INDEX_REG(P3RD_CURSOR_PALETTE_START+3*(int)RGBIndex+1, Green); \
    P3RD_LOAD_INDEX_REG(P3RD_CURSOR_PALETTE_START+3*(int)RGBIndex+2, Blue); \
}
#define P3RD_PALETTE_START_WR(index) \
{ \
    WRITE_P3RDREG_ULONG(P3RD_PAL_WR_ADDR,     (ULONG)(index));    \
    P3RD_DELAY; \
}
#define P3RD_PALETTE_START_RD(index) \
{ \
    WRITE_P3RDREG_ULONG(P3RD_PAL_RD_ADDR,     (ULONG)(index));    \
    P3RD_DELAY; \
}
#define P3RD_LOAD_PALETTE(red, green, blue) \
{ \
    WRITE_P3RDREG_ULONG(P3RD_PAL_DATA,    (ULONG)(red));      \
    P3RD_DELAY; \
    WRITE_P3RDREG_ULONG(P3RD_PAL_DATA,    (ULONG)(green));    \
    P3RD_DELAY; \
    WRITE_P3RDREG_ULONG(P3RD_PAL_DATA,    (ULONG)(blue));     \
    P3RD_DELAY; \
}
#define P3RD_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    WRITE_P3RDREG_ULONG(P3RD_PAL_WR_ADDR, (ULONG)(index));    \
    P3RD_DELAY; \
    WRITE_P3RDREG_ULONG(P3RD_PAL_DATA,    (ULONG)(red));      \
    P3RD_DELAY; \
    WRITE_P3RDREG_ULONG(P3RD_PAL_DATA,    (ULONG)(green));    \
    P3RD_DELAY; \
    WRITE_P3RDREG_ULONG(P3RD_PAL_DATA,    (ULONG)(blue));     \
    P3RD_DELAY; \
}
#define P3RD_READ_PALETTE(red, green, blue) \
{ \
    red   = (UCHAR)(READ_P3RDREG_ULONG(P3RD_PAL_DATA) & 0xff);        \
    P3RD_DELAY; \
    green = (UCHAR)(READ_P3RDREG_ULONG(P3RD_PAL_DATA) & 0xff);        \
    P3RD_DELAY; \
    blue  = (UCHAR)(READ_P3RDREG_ULONG(P3RD_PAL_DATA) & 0xff);        \
    P3RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\inc\p2rd.h
#define P2RD_PAL_WR_ADDR              ((PULONG)&(pP2RDRegs->RDPaletteWriteAddress.reg))
#define P2RD_PAL_RD_ADDR              ((PULONG)&(pP2RDRegs->RDPaletteAddressRead.reg))
#define P2RD_PAL_DATA                 ((PULONG)&(pP2RDRegs->RDPaletteData.reg))
#define P2RD_CURSOR_PALETTE_CURSOR_RGB(RGBIndex, Red, Green, Blue) \
{ \
    P2RD_LOAD_INDEX_REG(P2RD_CURSOR_PALETTE_START+3*(int)RGBIndex+0, Red); \
    P2RD_LOAD_INDEX_REG(P2RD_CURSOR_PALETTE_START+3*(int)RGBIndex+1, Green); \
    P2RD_LOAD_INDEX_REG(P2RD_CURSOR_PALETTE_START+3*(int)RGBIndex+2, Blue); \
}
#define P2RD_PALETTE_START_WR(index) \
{ \
    VideoPortWriteRegisterUlong(P2RD_PAL_WR_ADDR,     (ULONG)(index));    \
    P2RD_DELAY; \
}
#define P2RD_PALETTE_START_RD(index) \
{ \
    VideoPortWriteRegisterUlong(P2RD_PAL_RD_ADDR,     (ULONG)(index));    \
    P2RD_DELAY; \
}
#define P2RD_LOAD_PALETTE(red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(red));      \
    P2RD_DELAY; \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(green));    \
    P2RD_DELAY; \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(blue));     \
    P2RD_DELAY; \
}
#define P2RD_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(P2RD_PAL_WR_ADDR, (ULONG)(index));    \
    P2RD_DELAY; \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(red));      \
    P2RD_DELAY; \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(green));    \
    P2RD_DELAY; \
    VideoPortWriteRegisterUlong(P2RD_PAL_DATA,    (ULONG)(blue));     \
    P2RD_DELAY; \
}
#define P2RD_READ_PALETTE(red, green, blue) \
{ \
    red   = (UCHAR)(VideoPortReadRegisterUlong(P2RD_PAL_DATA) & 0xff);        \
    P2RD_DELAY; \
    green = (UCHAR)(VideoPortReadRegisterUlong(P2RD_PAL_DATA) & 0xff);        \
    P2RD_DELAY; \
    blue  = (UCHAR)(VideoPortReadRegisterUlong(P2RD_PAL_DATA) & 0xff);        \
    P2RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\inc\p3rd.h
#define P3RD_PAL_WR_ADDR              ((PULONG)&(pP3RDRegs->RDPaletteWriteAddress.reg))
#define P3RD_PAL_RD_ADDR              ((PULONG)&(pP3RDRegs->RDPaletteAddressRead.reg))
#define P3RD_PAL_DATA                 ((PULONG)&(pP3RDRegs->RDPaletteData.reg))
#define P3RD_CURSOR_PALETTE_CURSOR_RGB(RGBIndex, Red, Green, Blue) \
{ \
    P3RD_LOAD_INDEX_REG(P3RD_CURSOR_PALETTE_START+3*(int)(14 - RGBIndex)+0, Red); \
    P3RD_LOAD_INDEX_REG(P3RD_CURSOR_PALETTE_START+3*(int)(14 - RGBIndex)+1, Green); \
    P3RD_LOAD_INDEX_REG(P3RD_CURSOR_PALETTE_START+3*(int)(14 - RGBIndex)+2, Blue); \
}
#define P3RD_PALETTE_START_WR(index) \
{ \
    VideoPortWriteRegisterUlong(P3RD_PAL_WR_ADDR,     (ULONG)(index));    \
    P3RD_DELAY; \
}
#define P3RD_PALETTE_START_RD(index) \
{ \
    VideoPortWriteRegisterUlong(P3RD_PAL_RD_ADDR,     (ULONG)(index));    \
    P3RD_DELAY; \
}
#define P3RD_LOAD_PALETTE(red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(red));      \
    P3RD_DELAY; \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(green));    \
    P3RD_DELAY; \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(blue));     \
    P3RD_DELAY; \
}
#define P3RD_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(P3RD_PAL_WR_ADDR, (ULONG)(index));    \
    P3RD_DELAY; \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(red));      \
    P3RD_DELAY; \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(green));    \
    P3RD_DELAY; \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(blue));     \
    P3RD_DELAY; \
}
#define P3RD_READ_PALETTE(red, green, blue) \
{ \
    red   = (UCHAR)(VideoPortReadRegisterUlong(P3RD_PAL_DATA) & 0xff);        \
    P3RD_DELAY; \
    green = (UCHAR)(VideoPortReadRegisterUlong(P3RD_PAL_DATA) & 0xff);        \
    P3RD_DELAY; \
    blue  = (UCHAR)(VideoPortReadRegisterUlong(P3RD_PAL_DATA) & 0xff);        \
    P3RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\inc\rgb525.h
#define RGB525_DECL                                                         \
    pRGB525RAMDAC   pRGB525Regs;                                            \
    if (pDev->ChipID == PERMEDIA2_ID || pDev->ChipID == TIPERMEDIA2_ID) {   \
        pRGB525Regs = (pRGB525RAMDAC)&(pDev->pRegisters->Glint.P2ExtVCReg); \
    } else {                                                                \
        pRGB525Regs = (pRGB525RAMDAC)&(pDev->pRegisters->Glint.ExtVCReg);   \
    }
#define RGB525_DECL \
    pRGB525RAMDAC   pRGB525Regs;                                            \
    if (pGLInfo->dwRenderChipID == PERMEDIA2_ID || pGLInfo->dwRenderChipID == TIPERMEDIA2_ID) {   \
        pRGB525Regs = (pRGB525RAMDAC)&(pRegisters->Glint.P2ExtVCReg);       \
    } else {                                                                \
        pRGB525Regs = (pRGB525RAMDAC)&(pRegisters->Glint.ExtVCReg);         \
    }
#define RGB525_PAL_WR_ADDR              ((PULONG)&(pRGB525Regs->palAddrWr.reg))
#define RGB525_PAL_RD_ADDR              ((PULONG)&(pRGB525Regs->palAddrRd.reg))
#define RGB525_PAL_DATA                 ((PULONG)&(pRGB525Regs->palData.reg))
#define RGB525_INDEX_ADDR_LO            ((PULONG)&(pRGB525Regs->indexLow.reg))
#define RGB525_INDEX_ADDR_HI            ((PULONG)&(pRGB525Regs->indexHigh.reg))
#define RGB525_INDEX_DATA               ((PULONG)&(pRGB525Regs->indexData.reg))
#define RGB525_INDEX_CONTROL            ((PULONG)&(pRGB525Regs->indexCtl.reg))
#define RGB525_DELAY \
{ \
    volatile LONG __junk525; \
    __junk525 = pDev->pRegisters->Glint.LineCount; \
}
#define RGB525_DELAY \
{ \
    volatile LONG __junk525; \
    __junk525 = pRegisters->Glint.LineCount; \
}
#define RGB525_LOAD_INDEX_REG_LO(index, data) \
{ \
    VideoPortWriteRegisterUlong(RGB525_INDEX_ADDR_LO, (ULONG)(index));  \
    RGB525_DELAY; \
    VideoPortWriteRegisterUlong(RGB525_INDEX_DATA,    (ULONG)(data));   \
    RGB525_DELAY; \
}
#define RGB525_PALETTE_START_WR(index) \
{ \
    VideoPortWriteRegisterUlong(RGB525_PAL_WR_ADDR,     (ULONG)(index));    \
    RGB525_DELAY; \
}
#define RGB525_PALETTE_START_RD(index) \
{ \
    VideoPortWriteRegisterUlong(RGB525_PAL_RD_ADDR,     (ULONG)(index));    \
    RGB525_DELAY; \
}
#define RGB525_LOAD_PALETTE(red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(RGB525_PAL_DATA,    (ULONG)(red));      \
    RGB525_DELAY; \
    VideoPortWriteRegisterUlong(RGB525_PAL_DATA,    (ULONG)(green));    \
    RGB525_DELAY; \
    VideoPortWriteRegisterUlong(RGB525_PAL_DATA,    (ULONG)(blue));     \
    RGB525_DELAY; \
}
#define RGB525_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(RGB525_PAL_WR_ADDR, (ULONG)(index));    \
    RGB525_DELAY; \
    VideoPortWriteRegisterUlong(RGB525_PAL_DATA,    (ULONG)(red));      \
    RGB525_DELAY; \
    VideoPortWriteRegisterUlong(RGB525_PAL_DATA,    (ULONG)(green));    \
    RGB525_DELAY; \
    VideoPortWriteRegisterUlong(RGB525_PAL_DATA,    (ULONG)(blue));     \
    RGB525_DELAY; \
}
#define RGB525_READ_PALETTE(red, green, blue) \
{ \
    red   = (UCHAR) (VideoPortReadRegisterUlong(RGB525_PAL_DATA) & 0xff);        \
    RGB525_DELAY; \
    green = (UCHAR) (VideoPortReadRegisterUlong(RGB525_PAL_DATA) & 0xff);        \
    RGB525_DELAY; \
    blue  = (UCHAR) (VideoPortReadRegisterUlong(RGB525_PAL_DATA) & 0xff);        \
    RGB525_DELAY; \
}
#define RGB525_CURSOR_HOTSPOT(x, y) \
{ \
    VideoPortWriteRegisterUlong(RGB525_INDEX_ADDR_HI,   (ULONG)(0));    \
    RGB525_DELAY; \
    RGB525_LOAD_INDEX_REG_LO(RGB525_CURSOR_X_HOT_SPOT,  (ULONG)(x));    \
    RGB525_LOAD_INDEX_REG_LO(RGB525_CURSOR_Y_HOT_SPOT,  (ULONG)(y));    \
}
#define PALETTE_PARITION(n)             (n)
#define RGB525_PLL_REFCLK_MHz(n)        ((n)/2)

// drivers\video\ms\3dlabs\perm3\disp\inc\rgb640.h
#define RGB640_INDEX_INCREMENT(n) \
{ \
    /*WRITE_640REG_ULONG (RGB640_INDEX_CONTROL, (ULONG)(n));    */\
    RGB640_DELAY;                                               \
}
#define RGB640_LOAD_DATA(data) \
{ \
    WRITE_640REG_ULONG(RGB640_INDEX_DATA, (ULONG)((data) & 0xff)); \
    RGB640_DELAY; \
}
#define RGB640_LOAD_INDEX_REG(index, data) \
{ \
    RGB640_INDEX_REG(index);                            \
    WRITE_640REG_ULONG(RGB640_INDEX_DATA, (ULONG)((data) & 0xff)); \
    RGB640_DELAY; \
}
#define RGB640_READ_INDEX_REG(index, data) \
{ \
    RGB640_INDEX_REG(index);                            \
    data = (UCHAR) (READ_640REG_ULONG (RGB640_INDEX_DATA) & 0xff);   \
    RGB640_DELAY; \
}
#define RGB640_LOAD_INDEX_REG_LO(index, data) \
{ \
    WRITE_640REG_ULONG(RGB640_INDEX_ADDR_LO, (ULONG)(index));  \
    RGB640_DELAY; \
    WRITE_640REG_ULONG(RGB640_INDEX_DATA,    (ULONG)(data));   \
    RGB640_DELAY; \
}
#define RGB640_PALETTE_START_WR(index) \
    RGB640_INDEX_REG((index) + 0x4000)
#define RGB640_PALETTE_START_RD(index) \
    RGB640_INDEX_REG((index) + 0x8000)
#define RGB640_LOAD_PALETTE(red, green, blue) \
{ \
    RGB640_LOAD_DATA(red);      \
    RGB640_LOAD_DATA(green);    \
    RGB640_LOAD_DATA(blue);     \
}
#define RGB640_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    RGB640_PALETTE_START_WR(index); \
    RGB640_LOAD_PALETTE(red, green, blue); \
}
#define RGB640_READ_PALETTE(red, green, blue) \
{ \
    red   = (UCHAR)(READ_640REG_ULONG (RGB640_INDEX_DATA) & 0xff);        \
    RGB640_DELAY; \
    green = (UCHAR)(READ_640REG_ULONG (RGB640_INDEX_DATA) & 0xff);        \
    RGB640_DELAY; \
    blue  = (UCHAR)(READ_640REG_ULONG (RGB640_INDEX_DATA) & 0xff);        \
    RGB640_DELAY; \
}
#define RGB640_LOAD_PALETTE10_INDEX(index, red, green, blue) \
{ \
    RGB640_PALETTE_START_WR(index); \
    RGB640_LOAD_PALETTE10(red, green, blue); \
}
#define RGB640_CURSOR_HOTSPOT(x, y) \
{ \
    RGB640_INDEX_REG (RGB640_CURSOR_X_HOT_SPOT); \
    RGB640_LOAD_DATA ((ULONG)(x));               \
    RGB640_LOAD_DATA ((ULONG)(y));               \
}
#define RGB640_FRAMEBUFFER_WAT(n)       (0x0100 + (n))
#define RGB640_OVERLAY_WAT(n)           (0x0200 + (n))
#define RGB640_CURSOR_PIXEL_MAP_WR(n)   (0x1000 + (n))
#define RGB640_CURSOR_PIXEL_MAP_RD(n)   (0x2000 + (n))
#define RGB640_MAIN_COLOR_PAL_WR(n)     (0x4000 + (n))
#define RGB640_MAIN_COLOR_PAL_RD(n)     (0x8000 + (n))

// drivers\video\ms\3dlabs\perm3\disp\inc\surf_fmt.h
#define SURFFORMAT_PIXELSIZE(pSurfFormat) ((pSurfFormat)->dwChipPixelSize)

// drivers\video\ms\3dlabs\perm3\disp\inc\tvp3026.h
#define TVP3026_PALETTE_START_WR(index) \
{ \
    VideoPortWriteRegisterUlong(__TVP3026_PAL_WR_ADDR,     (ULONG)(index));    \
    TVP3026_DELAY; \
}
#define TVP3026_PALETTE_START_RD(index) \
{ \
    VideoPortWriteRegisterUlong(__TVP3026_PAL_RD_ADDR,     (ULONG)(index));    \
    TVP3026_DELAY; \
}
#define TVP3026_LOAD_PALETTE(red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(__TVP3026_PAL_DATA,    (ULONG)(red));      \
    TVP3026_DELAY; \
    VideoPortWriteRegisterUlong(__TVP3026_PAL_DATA,    (ULONG)(green));    \
    TVP3026_DELAY; \
    VideoPortWriteRegisterUlong(__TVP3026_PAL_DATA,    (ULONG)(blue));     \
    TVP3026_DELAY; \
}
#define TVP3026_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(__TVP3026_PAL_WR_ADDR, (ULONG)(index));    \
    TVP3026_DELAY; \
    VideoPortWriteRegisterUlong(__TVP3026_PAL_DATA,    (ULONG)(red));      \
    TVP3026_DELAY; \
    VideoPortWriteRegisterUlong(__TVP3026_PAL_DATA,    (ULONG)(green));    \
    TVP3026_DELAY; \
    VideoPortWriteRegisterUlong(__TVP3026_PAL_DATA,    (ULONG)(blue));     \
    TVP3026_DELAY; \
}
#define TVP3026_READ_PALETTE(red, green, blue) \
{ \
    red   = VideoPortReadRegisterUlong(__TVP3026_PAL_DATA) & 0xff;        \
    TVP3026_DELAY; \
    green = VideoPortReadRegisterUlong(__TVP3026_PAL_DATA) & 0xff;        \
    TVP3026_DELAY; \
    blue  = VideoPortReadRegisterUlong(__TVP3026_PAL_DATA) & 0xff;        \
    TVP3026_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\disp\inc\tvp4020.h
#define TVP4020_PALETTE_START_WR(index) \
{ \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_WR_ADDR,     (ULONG)(index));    \
    TVP4020_DELAY; \
}
#define TVP4020_PALETTE_START_RD(index) \
{ \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_RD_ADDR,     (ULONG)(index));    \
    TVP4020_DELAY; \
}
#define TVP4020_LOAD_PALETTE(red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(red));      \
    TVP4020_DELAY; \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(green));    \
    TVP4020_DELAY; \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(blue));     \
    TVP4020_DELAY; \
}
#define TVP4020_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_WR_ADDR, (ULONG)(index));    \
    TVP4020_DELAY; \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(red));      \
    TVP4020_DELAY; \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(green));    \
    TVP4020_DELAY; \
    VideoPortWriteRegisterUlong(__TVP4020_PAL_DATA,    (ULONG)(blue));     \
    TVP4020_DELAY; \
}
#define TVP4020_READ_PALETTE(red, green, blue) \
{ \
    red   = (UCHAR)(VideoPortReadRegisterUlong(__TVP4020_PAL_DATA) & 0xff);        \
    TVP4020_DELAY; \
    green = (UCHAR)(VideoPortReadRegisterUlong(__TVP4020_PAL_DATA) & 0xff);        \
    TVP4020_DELAY; \
    blue  = (UCHAR)(VideoPortReadRegisterUlong(__TVP4020_PAL_DATA) & 0xff);        \
    TVP4020_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\mini\p3rd.h
#define P3RD_PAL_WR_ADDR   ((PULONG)&(pP3RDRegs->RDPaletteWriteAddress.reg))
#define P3RD_PAL_RD_ADDR   ((PULONG)&(pP3RDRegs->RDPaletteAddressRead.reg))
#define P3RD_PAL_DATA      ((PULONG)&(pP3RDRegs->RDPaletteData.reg))
#define P3RD_CURSOR_PALETTE_CURSOR_RGB(RGBIndex, Red, Green, Blue) \
{ \
    P3RD_LOAD_INDEX_REG(P3RD_CURSOR_PALETTE_START+3*(int)RGBIndex+0, Red); \
    P3RD_LOAD_INDEX_REG(P3RD_CURSOR_PALETTE_START+3*(int)RGBIndex+1, Green); \
    P3RD_LOAD_INDEX_REG(P3RD_CURSOR_PALETTE_START+3*(int)RGBIndex+2, Blue); \
}
#define P3RD_PALETTE_START_WR(index) \
{ \
    VideoPortWriteRegisterUlong(P3RD_PAL_WR_ADDR,     (ULONG)(index));    \
    P3RD_DELAY; \
}
#define P3RD_PALETTE_START_RD(index) \
{ \
    VideoPortWriteRegisterUlong(P3RD_PAL_RD_ADDR,     (ULONG)(index));    \
    P3RD_DELAY; \
}
#define P3RD_LOAD_PALETTE(red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(red));      \
    P3RD_DELAY; \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(green));    \
    P3RD_DELAY; \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(blue));     \
    P3RD_DELAY; \
}
#define P3RD_LOAD_PALETTE_INDEX(index, red, green, blue) \
{ \
    VideoPortWriteRegisterUlong(P3RD_PAL_WR_ADDR, (ULONG)(index));    \
    P3RD_DELAY; \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(red));      \
    P3RD_DELAY; \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(green));    \
    P3RD_DELAY; \
    VideoPortWriteRegisterUlong(P3RD_PAL_DATA,    (ULONG)(blue));     \
    P3RD_DELAY; \
}
#define P3RD_READ_PALETTE(red, green, blue) \
{ \
    red   = (UCHAR)(VideoPortReadRegisterUlong(P3RD_PAL_DATA) & 0xff);    \
    P3RD_DELAY; \
    green = (UCHAR)(VideoPortReadRegisterUlong(P3RD_PAL_DATA) & 0xff);    \
    P3RD_DELAY; \
    blue  = (UCHAR)(VideoPortReadRegisterUlong(P3RD_PAL_DATA) & 0xff);    \
    P3RD_DELAY; \
}

// drivers\video\ms\3dlabs\perm3\mini\perm3.h
#define LUT_CACHE_SETRGB(idx,zr,zg,zb) {    \
    hwDeviceExtension->LUTCache.LUTCache.LookupTable [idx].RgbArray.Red   = (UCHAR) (zr); \
    hwDeviceExtension->LUTCache.LUTCache.LookupTable [idx].RgbArray.Green = (UCHAR) (zg); \
    hwDeviceExtension->LUTCache.LUTCache.LookupTable [idx].RgbArray.Blue  = (UCHAR) (zb); \
}
#define MAX_CLUT_SIZE (sizeof(VIDEO_CLUT) + (sizeof(ULONG) * (VIDEO_MAX_COLOR_REGISTER+1)))

// drivers\video\ms\8514a\disp\intline.c
#define DEFAULT_DRAW_CMD	DRAW_LINE | \
                                DRAW | \
                                DIR_TYPE_XY | \
                                MULTIPLE_PIXELS | \
                                WRITE | \
                                LAST_PIXEL_OFF

// drivers\video\ms\ati\disp\hw.h
#define IS_RGB15_R(flRed) \
        (flRed == 0x7c00)

// drivers\video\ms\cirrus\disp\dispint.h
#define CHIPCOLORKEYBLTER   (CHIP5426 | CHIP5428 | CHIP5436 | CHIP5446 |\
                            CHIP754x | CHIPM40)

// drivers\video\ms\laguna\disp\cl5465\blt65.c
	#define BLAM  (DDRAWISURF_HASPIXELFORMAT)
	#define BLAM  (DDRAWISURF_HASPIXELFORMAT | DDRAWISURF_HASOVERLAYDATA)

// drivers\video\ms\laguna\disp\cl5465\ddblt.c
#define MEMCMP(A,B)          memcmp(&ppdev->offscr_YUV.SrcRect, (A),(B))
#define RGB_RESIZEBOF64   RGBResizeBOF64(PDEV* ppdev, DRIVERDATA* lpDDHALData,
#define RGB_16SHRINKBOF64 RGB16ShrinkBOF64(PDEV* ppdev, DRIVERDATA* lpDDHALData,
#define CALL_RGB_RESIZEBOF64(A,B,C,D,E,F,G,H)    RGBResizeBOF64(ppdev,lpDDHALData,(A),(B),(C),(D),(E),(F),(G),(H))
#define CALL_RGB_16SHRINKBOF64(A,B,C,D,E,F,G,H)  RGB16ShrinkBOF64(ppdev,lpDDHALData,(A),(B),(C),(D),(E),(F),(G),(H))
#define MEMCMP(A,B)               memcmp(&offscr_YUV.SrcRect, (A),(B))
#define RGB_RESIZEBOF64           RGBResizeBOF64(
#define RGB_16SHRINKBOF64         RGB16ShrinkBOF64(
#define CALL_RGB_RESIZEBOF64(A,B,C,D,E,F,G,H)         RGBResizeBOF64(lpDDHALData,(A),(B),(C),(D),(E),(F),(G),(H))
#define CALL_RGB_16SHRINKBOF64(A,B,C,D,E,F,G,H)       RGB16ShrinkBOF64(lpDDHALData,(A),(B),(C),(D),(E),(F),(G),(H))

// drivers\video\ms\laguna\disp\cl5465\lines.c
#define DEFAULT_DRAW_CMD (DRAW_LINE | DRAW | DIR_TYPE_XY | MULTIPLE_PIXELS | \
                          WRITE | LAST_PIXEL_OFF)

// drivers\video\ms\laguna\disp\cl5465\mcd.c
#define TOTAL_PIXEL_FORMATS (2 * 2)     // double-buffers * z-buffers

// drivers\video\ms\laguna\disp\cl5465\mcdclip.c
#define __MCD_CLIP_COLOR(v, a, b, t) \
    v->colors[__MCD_FRONTFACE].r = t*(a->colors[__MCD_FRONTFACE].r      \
        - b->colors[__MCD_FRONTFACE].r) + b->colors[__MCD_FRONTFACE].r; \
    v->colors[__MCD_FRONTFACE].g = t*(a->colors[__MCD_FRONTFACE].g      \
        - b->colors[__MCD_FRONTFACE].g) + b->colors[__MCD_FRONTFACE].g; \
    v->colors[__MCD_FRONTFACE].b = t*(a->colors[__MCD_FRONTFACE].b      \
        - b->colors[__MCD_FRONTFACE].b) + b->colors[__MCD_FRONTFACE].b; \
    v->colors[__MCD_FRONTFACE].a = t*(a->colors[__MCD_FRONTFACE].a      \
        - b->colors[__MCD_FRONTFACE].a) + b->colors[__MCD_FRONTFACE].a
#define __MCD_CLIP_BACKCOLOR(v, a, b, t) \
    v->colors[__MCD_BACKFACE].r = t*(a->colors[__MCD_BACKFACE].r        \
        - b->colors[__MCD_BACKFACE].r) + b->colors[__MCD_BACKFACE].r;   \
    v->colors[__MCD_BACKFACE].g = t*(a->colors[__MCD_BACKFACE].g        \
        - b->colors[__MCD_BACKFACE].g) + b->colors[__MCD_BACKFACE].g;   \
    v->colors[__MCD_BACKFACE].b = t*(a->colors[__MCD_BACKFACE].b        \
        - b->colors[__MCD_BACKFACE].b) + b->colors[__MCD_BACKFACE].b;   \
    v->colors[__MCD_BACKFACE].a = t*(a->colors[__MCD_BACKFACE].a        \
        - b->colors[__MCD_BACKFACE].a) + b->colors[__MCD_BACKFACE].a
#define __MCD_CLIP_INDEX(v, a, b, t) \
    v->colors[__MCD_FRONTFACE].r = t*(a->colors[__MCD_FRONTFACE].r      \
        - b->colors[__MCD_FRONTFACE].r) + b->colors[__MCD_FRONTFACE].r
#define __MCD_CLIP_BACKINDEX(v, a, b, t) \
    v->colors[__MCD_BACKFACE].r = t*(a->colors[__MCD_BACKFACE].r        \
        - b->colors[__MCD_BACKFACE].r) + b->colors[__MCD_BACKFACE].r

// drivers\video\ms\laguna\disp\cl5465\mcdhw.h
#define SAVE_COLOR(temp, p)\
{\
    temp.r = (p)->colors[0].r;\
    temp.g = (p)->colors[0].g;\
    temp.b = (p)->colors[0].b;\
}
#define RESTORE_COLOR(temp, p)\
{\
    (p)->colors[0].r = temp.r;\
    (p)->colors[0].g = temp.g;\
    (p)->colors[0].b = temp.b;\
}
#define MCDFIXEDRGB(fixColor, fltColor)\
    fixColor.r = (MCDFIXED)(fltColor.r * pRc->rScale);\
    fixColor.g = (MCDFIXED)(fltColor.g * pRc->gScale);\
    fixColor.b = (MCDFIXED)(fltColor.b * pRc->bScale);

// drivers\video\ms\laguna\disp\cl5465\mcdtri.c
#define FIND_MIDPOINT(start, end, mid) {                                                    \
    float   recip;                                                                          \
	mid->windowCoord.x =  (start->windowCoord.x + end->windowCoord.x) * (float)0.5;         \
	mid->windowCoord.y =  (start->windowCoord.y + end->windowCoord.y) * (float)0.5;         \
	mid->windowCoord.z =  (start->windowCoord.z + end->windowCoord.z) * (float)0.5;         \
    mid->colors[0].r = (start->colors[0].r + end->colors[0].r) * (float)0.5;                \
    mid->colors[0].g = (start->colors[0].g + end->colors[0].g) * (float)0.5;                \
    mid->colors[0].b = (start->colors[0].b + end->colors[0].b) * (float)0.5;                \
    mid->colors[0].a = (start->colors[0].a + end->colors[0].a) * (float)0.5;                \
    mid->fog = (start->fog + end->fog) * (float)0.5;                                        \
	mid->windowCoord.w =  (start->windowCoord.w + end->windowCoord.w) * (float)0.5;         \
    recip = (float)0.5/mid->windowCoord.w;  /* pre-mult by .5 for use below */              \
    mid->texCoord.x = recip * (start->texCoord.x * start->windowCoord.w +                   \
                               end->texCoord.x   * end->windowCoord.w);                     \
    mid->texCoord.y = recip * (start->texCoord.y * start->windowCoord.w +                   \
                               end->texCoord.y   * end->windowCoord.w);                     \
}

// drivers\video\ms\laguna\disp\cl546x\blt65.c
	#define BLAM  (DDRAWISURF_HASPIXELFORMAT)
	#define BLAM  (DDRAWISURF_HASPIXELFORMAT | DDRAWISURF_HASOVERLAYDATA)

// drivers\video\ms\laguna\disp\cl546x\ddblt.c
#define MEMCMP(A,B)          memcmp(&ppdev->offscr_YUV.SrcRect, (A),(B))
#define RGB_RESIZEBOF64   RGBResizeBOF64(PDEV* ppdev, DRIVERDATA* lpDDHALData,
#define RGB_16SHRINKBOF64 RGB16ShrinkBOF64(PDEV* ppdev, DRIVERDATA* lpDDHALData,
#define CALL_RGB_RESIZEBOF64(A,B,C,D,E,F,G,H)    RGBResizeBOF64(ppdev,lpDDHALData,(A),(B),(C),(D),(E),(F),(G),(H))
#define CALL_RGB_16SHRINKBOF64(A,B,C,D,E,F,G,H)  RGB16ShrinkBOF64(ppdev,lpDDHALData,(A),(B),(C),(D),(E),(F),(G),(H))
#define MEMCMP(A,B)               memcmp(&offscr_YUV.SrcRect, (A),(B))
#define RGB_RESIZEBOF64           RGBResizeBOF64(
#define RGB_16SHRINKBOF64         RGB16ShrinkBOF64(
#define CALL_RGB_RESIZEBOF64(A,B,C,D,E,F,G,H)         RGBResizeBOF64(lpDDHALData,(A),(B),(C),(D),(E),(F),(G),(H))
#define CALL_RGB_16SHRINKBOF64(A,B,C,D,E,F,G,H)       RGB16ShrinkBOF64(lpDDHALData,(A),(B),(C),(D),(E),(F),(G),(H))

// drivers\video\ms\laguna\disp\cl546x\lines.c
#define DEFAULT_DRAW_CMD (DRAW_LINE | DRAW | DIR_TYPE_XY | MULTIPLE_PIXELS | \
                          WRITE | LAST_PIXEL_OFF)

// drivers\video\ms\port\pedid.h
#define GET_X_ACTIVE_PIXEL_RANGE(ushort)   ((ushort&0xff)+ 31) * 8
#define GET_RANGE_LIMIT_MAX_PIXELCLOCK_RATE(pMonitorSNorData)    \
    pMonitorSNorData[9]

// drivers\video\ms\s3\disp\driver.h
    #define DIRECT_ACCESS(ppdev)    \
        (!(ppdev->flCaps & (CAPS_NO_DIRECT_ACCESS | CAPS_SPARSE_SPACE)))

// drivers\video\ms\s3\disp\hw.h
#define IO_BKGD_COLOR(ppdev, x)             \
    OUT_FIFO_W(ppdev->ioBkgd_color, (x))
#define IO_FRGD_COLOR(ppdev, x)             \
    OUT_FIFO_W(ppdev->ioFrgd_color, (x))
#define IO_COLOR_CMP(ppdev, x)              \
    OUT_FIFO_W(ppdev->ioColor_cmp, (x))
#define IO_BKGD_COLOR32(ppdev, x)           \
    OUT_FIFO_PSEUDO_D(ppdev, ppdev->ioBkgd_color, (x))
#define IO_FRGD_COLOR32(ppdev, x)           \
    OUT_FIFO_PSEUDO_D(ppdev, ppdev->ioFrgd_color, (x))
#define IO_COLOR_CMP32(ppdev, x)            \
    OUT_FIFO_PSEUDO_D(ppdev, ppdev->ioColor_cmp, (x))
#define IS_RGB15_R(flRed) \
        (flRed == 0x7c00)

// drivers\video\ms\s3\disp\lines.c
#define DEFAULT_DRAW_CMD (DRAW_LINE | DRAW | DIR_TYPE_XY | MULTIPLE_PIXELS | \
                          WRITE | LAST_PIXEL_OFF)

// drivers\video\ms\w32\disp\lines.c
#define DEFAULT_DRAW_CMD (DRAW_LINE | DRAW | DIR_TYPE_XY | MULTIPLE_PIXELS | \
                          WRITE | LAST_PIXEL_OFF)

// drivers\video\ms\weitek\disp\hw.h
#define P9100_TRANSPARENT_EXPAND    (P9100_S | P9100_PIXEL1_TRANSPARENT)
#define CP_PIXEL1_VIA_REGISTER(ppdev, pReg, x)          \
{                                                       \
    /* This EIEIO is to ensure we don't get out of */   \
    /* order with normal full CP_PIXEL1 writes */       \
    CP_EIEIO();                                         \
    WRITE_REGISTER_ULONG(pReg, (x));                    \
}

// drivers\video\ms\weitek\mini\ibm525.h
#define RGB525_REVISION_LEVEL           (0x00)
#define RGB525_ID                       (0x01)
#define RGB525_MISC_CLOCK_CTL           (0x02) // Referenced
#define RGB525_SYNC_CTL                 (0x03)
#define RGB525_HSYNC_POS                (0x04)
#define RGB525_POWER_MGNT               (0x05)
#define RGB525_DAC_OPER                 (0x06) // Referenced
#define RGB525_PAL_CTRL                 (0x07)
#define RGB525_PIXEL_FORMAT             (0x0A) // Referenced
#define RGB525_8BPP_CTL                 (0x0B) // Referenced
#define RGB525_16BPP_CTL                (0x0C) // Referenced
#define RGB525_24BPP_CTL                (0x0D) // Referenced
#define RGB525_32BPP_CTL                (0x0E) // Referenced
#define RGB525_PLL_CTL1                 (0x10) // Referenced
#define RGB525_PLL_CTL2                 (0x11) // Referenced
#define RGB525_FIXED_PLL_REF_DIV        (0x14) // Referenced
#define RGB525_F0                       (0x20) // Referenced
#define RGB525_F1                       (0x21)
#define RGB525_F2                       (0x22)
#define RGB525_F3                       (0x23)
#define RGB525_F4                       (0x24)
#define RGB525_F5                       (0x25)
#define RGB525_F6                       (0x26)
#define RGB525_F7                       (0x27)
#define RGB525_F8                       (0x28)
#define RGB525_F9                       (0x29)
#define RGB525_F10                      (0x2A)
#define RGB525_F11                      (0x2B)
#define RGB525_F12                      (0x2C)
#define RGB525_F13                      (0x2D)
#define RGB525_F14                      (0x2E)
#define RGB525_F15                      (0x2F)
#define RGB525_CURSOR_CTL               (0x30) // Referenced
#define RGB525_CURSOR_X_LOW             (0x31) // Referenced
#define RGB525_CURSOR_X_HIGH            (0x32) // Referenced
#define RGB525_CURSOR_Y_LOW             (0x33) // Referenced
#define RGB525_CURSOR_Y_HIGH            (0x34) // Referenced
#define RGB525_CURSOR_HOT_X             (0x35) // Referenced
#define RGB525_CURSOR_HOT_Y             (0x36) // Referenced
#define RGB525_CURSOR_1_RED             (0x40) // Referenced
#define RGB525_CURSOR_1_GREEN           (0x41) // Referenced
#define RGB525_CURSOR_1_BLUE            (0x42) // Referenced
#define RGB525_CURSOR_2_RED             (0x43) // Referenced
#define RGB525_CURSOR_2_GREEN           (0x44) // Referenced
#define RGB525_CURSOR_2_BLUE            (0x45) // Referenced
#define RGB525_CURSOR_3_RED             (0x46)
#define RGB525_CURSOR_3_GREEN           (0x47)
#define RGB525_CURSOR_3_BLUE            (0x48)
#define RGB525_BORDER_RED               (0x60)
#define RGB525_BORDER_GREEN             (0x61)
#define RGB525_BORDER_BLUE              (0x62)
#define RGB525_MISC_CTL1                (0x70) // Referenced
#define RGB525_MISC_CTL2                (0x71) // Referenced
#define RGB525_MISC_CTL3                (0x72)
#define RGB525_DAC_SENSE                (0x82)
#define RGB525_MISR_RED                 (0x84)
#define RGB525_MISR_GREEN               (0x86)
#define RGB525_MISR_BLUE                (0x88)
#define RGB525_PLL_VCO_DIV              (0x8E)
#define RGB525_PLL_REF_DIV_IN           (0x8F)
#define CURS_IS_ON_IBM525() \
    (ReadIBM525(HwDeviceExtension, RGB525_CURSOR_CTL) & CURS_ACTIVE_IBM525)
#define CURS_ON_IBM525() \
    WriteIBM525(HwDeviceExtension, RGB525_CURSOR_CTL, (UCHAR) (ReadIBM525(HwDeviceExtension, RGB525_CURSOR_CTL) | ENB_CURS_IBM525))
#define CURS_OFF_IBM525() \
    WriteIBM525(HwDeviceExtension, RGB525_CURSOR_CTL, (UCHAR) (ReadIBM525(HwDeviceExtension, RGB525_CURSOR_CTL) & DIS_CURS_IBM525))

// drivers\video\ms\weitek\mini\p9.h
#define DAC_ID_IBM525               (0x8)   // IBMRGB525

// drivers\wdm\dvd\mini\dxr2\avint.h
#define DEFCOLOR_REFERENCE1	RGB( 0, 0, 0 )
#define DEFCOLOR_REFERENCE2	RGB( 255, 255, 255 )

// drivers\wdm\input\legacy\mshgame\gckernel.sys\gckextrn.h
#define GCK_IOCTL_DIRECT_CODE(_x_)	CTL_CODE(				\
									FILE_DEVICE_UNKNOWN,	\
									(0x0800 | _x_),			\
									METHOD_OUT_DIRECT,		\
									FILE_ANY_ACCESS			\
									)

// ds\adsi\ldap\ldapinc\disptmpl.h
#define LDAP_SYN_JPEGIMAGE	( 5 | LDAP_SYN_TYPE_IMAGE )
#define LDAP_SYN_FAXIMAGE	( 7 | LDAP_SYN_TYPE_IMAGE )

// ds\ds\src\common\atq\abw.hxx
# define CIRCULAR_INCREMENT( sm_pB, sm_rgB, size)  \
            (sm_pB) = ((((sm_pB) + 1) < (sm_rgB)+(size)) ? (sm_pB)+1 : (sm_rgB))

// ds\ds\src\inc\w32toplspantree.h
#define TOPL_EX_COLOR_VTX_ERROR           (TOPL_EX_PREFIX | 204)

// ds\ds\src\ntdsa\src\mdupdate.c
#define HVERIFYATTS_GET_PDBTMP(hVerifyAtts) \
    ((NULL != (hVerifyAtts)->pDBTmp_DontAccessDirectly) \
        ? (hVerifyAtts)->pDBTmp_DontAccessDirectly \
        : (DBOpen2(FALSE, &(hVerifyAtts)->pDBTmp_DontAccessDirectly), \
            (hVerifyAtts)->pDBTmp_DontAccessDirectly))

// ds\netapi\svcdlls\upssvc\apcsmart\scan.cxx
#define isBlank(c)      (isspace(c) && !isNewline(c))

// ds\nw\svcdlls\nwwks\client\nwshui.cxx
#define     MAPCOLOR        RGB(0, 255, 0)

// ds\security\cryptoapi\test\capi20\tcrmsg\tcrmsg.cpp
#define cbMsgContentFill sizeof(rgbMsgContentFill)

// ds\security\passport\atlmfc\atlbmid.h
#define COLORSPACE_RGB __uuidof( _CS_RGB )
#define COLORSPACE_RGBA __uuidof( _CS_RGBA )
#define COLORSPACE_IRGB __uuidof( _CS_IRGB )

// ds\security\passport\atlmfc\bmio.h
#define	RGBA_PREMULT	( 0x1 )
#define	DIBTARGET_1BPP	( 0x1 )
#define	DIBTARGET_2BPP	( 0x2 )
#define	DIBTARGET_4BPP	( 0x4 )
#define	DIBTARGET_8BPP	( 0x8 )
#define	DIBTARGET_16BPP	( 0x10 )
#define	DIBTARGET_24BPP	( 0x20 )
#define	DIBTARGET_32BPP	( 0x40 )
#define	DIBTARGET_32BPP_ALPHA	( 0x80 )
#define	DIBTARGET_GS1	( 0x10000 )
#define	DIBTARGET_GS2	( 0x20000 )
#define	DIBTARGET_GS4	( 0x40000 )
#define	DIBTARGET_GS8	( 0x80000 )
#define	DIBTARGET_ANYGS	( DIBTARGET_GS1 | DIBTARGET_GS2 | DIBTARGET_GS4 | DIBTARGET_GS8 )
#define	DIBTARGET_ANYINDEXED	( DIBTARGET_1BPP | DIBTARGET_2BPP | DIBTARGET_4BPP | DIBTARGET_8BPP )
#define	DIBTARGET_ANYRGB	( DIBTARGET_16BPP | DIBTARGET_24BPP | DIBTARGET_32BPP )
#define	DIBTARGET_ANY	( DIBTARGET_ANYRGB | DIBTARGET_ANYINDEXED | DIBTARGET_32BPP_ALPHA )
#define	DIBSOURCE_ALPHA	( 0x1 )

// ds\security\winsafer\test\desktops\deskspc.h
#define TRANSPARENT_BACKCOLOR   RGB(255,0,255)      // purple
#define TRANSPARENT_TEXTCOLOR   RGB(255,255,0)      // yellow

// enduser\netmeeting\as\cpi32\pm.cpp
#define PMADJUSTBUGGEDCOLOR(pColor)                                          \
    if ( ((pColor)->rgbBlue != 0x00) &&                                      \
         ((pColor)->rgbBlue != 0xFF) )                                       \
    {                                                                        \
        (pColor)->rgbBlue += 0x40;                                           \
    }                                                                        \
                                                                             \
    if ( ((pColor)->rgbGreen != 0x00) &&                                     \
         ((pColor)->rgbGreen != 0xFF) )                                      \
    {                                                                        \
        (pColor)->rgbGreen += 0x20;                                          \
    }                                                                        \
                                                                             \
    if ( ((pColor)->rgbRed != 0x00) &&                                       \
         ((pColor)->rgbRed != 0xFF) )                                        \
    {                                                                        \
        (pColor)->rgbRed += 0x20;                                            \
    }

// enduser\netmeeting\as\h\oe.h
#define RECT_FROM_RECTL(dcr, rec) if (rec.right < rec.left)                \
                                    {                                        \
                                        dcr.left   = rec.right;              \
                                        dcr.right  = rec.left;               \
                                    }                                        \
                                    else                                     \
                                    {                                        \
                                        dcr.left   = rec.left;               \
                                        dcr.right  = rec.right;              \
                                    }                                        \
                                    if (rec.bottom < rec.top)                \
                                    {                                        \
                                        dcr.bottom = rec.top;                \
                                        dcr.top    = rec.bottom;             \
                                    }                                        \
                                    else                                     \
                                    {                                        \
                                        dcr.top    = rec.top;                \
                                        dcr.bottom = rec.bottom;             \
                                    }

// enduser\netmeeting\as\h\t_share.h
#define TSHR_RECT16_FROM_RECT(lprcTshr, rc) \
    CopyRect((LPRECT)lprcTshr, &rc)
#define RECT_FROM_TSHR_RECT16(lprc, tshrrc) \
    CopyRect(lprc, (LPRECT)&tshrrc)
#define TSHR_RGBQUAD_TO_TSHR_COLOR(TshrRGBQuad, TshrColor)  \
        TshrColor.red = TshrRGBQuad.rgbRed;           \
        TshrColor.green = TshrRGBQuad.rgbGreen;       \
        TshrColor.blue = TshrRGBQuad.rgbBlue

// enduser\netmeeting\av\codecs\dec\dech261\avi.h
#define AVI_DIBcompressed     TWOCC('d', 'c')

// enduser\netmeeting\av\codecs\dec\dech261\sc.h
#define BI_MSH261DIB            mmioFOURCC('M','2','6','1')
#define BI_MSH263DIB            mmioFOURCC('M','2','6','3')
#define BI_DECH261DIB           mmioFOURCC('D','2','6','1')
#define BI_DECH263DIB           mmioFOURCC('D','2','6','3')
#define BI_DECJPEGDIB           mmioFOURCC('J','P','E','G')
#define BI_DECMJPGDIB           mmioFOURCC('M','J','P','G')
#define BI_DECYUVDIB            mmioFOURCC('D','Y','U','V')
#define BI_DECXIMAGEDIB         mmioFOURCC('D','X','I','M')
#define BI_DECSEPYUVDIB         mmioFOURCC('D','S','Y','U')
#define BI_DECMPEGDIB           mmioFOURCC('D','M','P','G')
#define BI_DECHUFFDIB           mmioFOURCC('D','H','U','F')
#define BI_DECSEPRGBDIB         mmioFOURCC('D','S','R','G')
#define BI_DECGRAYDIB           mmioFOURCC('D','G','R','Y')
#define BI_DECSEPYUV411DIB      mmioFOURCC('Y','U','1','2')
#define IsJPEG(s)         (((s) == JPEG_DIB)            || \
                           ((s) == MJPG_DIB))
#define IsYUV422Sep(s)    (((s) == BI_DECSEPYUVDIB)     || \
                           ((s) == BI_YU16SEP))
#define IsYUV411Sep(s)    (((s) == BI_DECSEPYUV411DIB)  || \
                           ((s) == BI_YU12SEP))
#define IsRGBSep(s)       (((s) == BI_DECSEPRGBDIB))
#define IsGray(s)         (((s) == BI_DECGRAYDIB))

// enduser\netmeeting\av\codecs\dec\dech261\sc_conv.c
#define BI_DECSEPRGBDIB         mmioFOURCC('D','S','R','G')
#define _LoadRGBfrom411() \
         R1 = R2 = R3 = R4 = (int) (              + (1.596 * V)); \
         G1 = G2 = G3 = G4 = (int) (- (0.391 * U) - (0.813 * V)); \
         B1 = B2 = B3 = B4 = (int) (+ (2.018 * U)              ); \
	 Luma = (int) (((int) *(Y1++) - 16) * 1.164); \
         R1 += Luma; G1 +=Luma; B1 += Luma; \
	 Luma = (int) (((int) *(Y1++) - 16) * 1.164); \
         R2 += Luma; G2 +=Luma; B2 += Luma; \
         if ((R1 | G1 | B1 | R2 | G2 | B2) & 0xffffff00) { \
           if (R1<0) R1=0; else if (R1>255) R1=255; \
           if (G1<0) G1=0; else if (G1>255) G1=255; \
           if (B1<0) B1=0; else if (B1>255) B1=255; \
           if (R2<0) R2=0; else if (R2>255) R2=255; \
           if (G2<0) G2=0; else if (G2>255) G2=255; \
           if (B2<0) B2=0; else if (B2>255) B2=255; \
         } \
         Luma = (int) (((int) *(Y2++) - 16) * 1.164); \
         R3 += Luma; G3 +=Luma; B3 += Luma; \
         Luma = (int) (((int) *(Y2++) - 16) * 1.164); \
         R4 += Luma; G4 +=Luma; B4 += Luma; \
         if ((R3 | G3 | B3 | R4 | G4 | B4) & 0xffffff00) { \
           if (R3<0) R3=0; else if (R3>255) R3=255; \
           if (G3<0) G3=0; else if (G3>255) G3=255; \
           if (B3<0) B3=0; else if (B3>255) B3=255; \
           if (R4<0) R4=0; else if (R4>255) R4=255; \
           if (G4<0) G4=0; else if (G4>255) G4=255; \
           if (B4<0) B4=0; else if (B4>255) B4=255; \
         }
#define _LoadRGBfrom422() \
         if (U || V) { \
           R1 = R2 = (int) (              + (1.596 * V)); \
           G1 = G2 = (int) (- (0.391 * U) - (0.813 * V)); \
           B1 = B2 = (int) (+ (2.018 * U)              );  \
         } else { R1=R2=G1=G2=B1=B2=0; } \
	 Luma = (int) (((int) *(Y++) - 16) * 1.164); \
         R1 += Luma; G1 += Luma; B1 += Luma; \
	 Luma = (int) (((int) *(Y++) - 16) * 1.164); \
         R2 += Luma; G2 += Luma; B2 += Luma; \
         if ((R1 | G1 | B1 | R2 | G2 | B2) & 0xffffff00) { \
           if (R1<0) R1=0; else if (R1>255) R1=255; \
           if (G1<0) G1=0; else if (G1>255) G1=255; \
           if (B1<0) B1=0; else if (B1>255) B1=255; \
           if (R2<0) R2=0; else if (R2>255) R2=255; \
           if (G2<0) G2=0; else if (G2>255) G2=255; \
           if (B2<0) B2=0; else if (B2>255) B2=255; \
         }
#define _LoadRGBfrom422() \
	 Luma = *(Y++); \
         R1 = Luma                + (1.4075 * V); \
         G1 = Luma - (0.3455 * U) - (0.7169 * V); \
         B1 = Luma + (1.7790 * U); \
	 Luma = *(Y++); \
         R2 = Luma                + (1.4075 * V); \
         G2 = Luma - (0.3455 * U) - (0.7169 * V); \
         B2 = Luma + (1.7790 * U); \
         if ((R1 | G1 | B1 | R2 | G2 | B2) & 0xffffff00) { \
           if (R1<0) R1=0; else if (R1>255) R1=255; \
           if (G1<0) G1=0; else if (G1>255) G1=255; \
           if (B1<0) B1=0; else if (B1>255) B1=255; \
           if (R2<0) R2=0; else if (R2>255) R2=255; \
           if (G2<0) G2=0; else if (G2>255) G2=255; \
           if (B2<0) B2=0; else if (B2>255) B2=255; \
         }

// enduser\netmeeting\av\codecs\dec\dech261\slib.h
#define SlibTypeIsVideoOnly(stype) (stype==SLIB_TYPE_MPEG1_VIDEO || \
                                    stype==SLIB_TYPE_MPEG2_VIDEO || \
                                    SlibTypeIsH26X(stype) || \
                                    stype==SLIB_TYPE_YUV || \
                                    stype==SLIB_TYPE_RGB || \
                                    stype==SLIB_TYPE_BMP || \
                                    stype==SLIB_TYPE_RASTER)

// enduser\netmeeting\av\codecs\dec\dech263\avi.h
#define AVI_DIBcompressed     TWOCC('d', 'c')

// enduser\netmeeting\av\codecs\dec\dech263\sc.h
#define BI_MSH261DIB            mmioFOURCC('M','2','6','1')
#define BI_MSH263DIB            mmioFOURCC('M','2','6','3')
#define BI_DECH261DIB           mmioFOURCC('D','2','6','1')
#define BI_DECH263DIB           mmioFOURCC('D','2','6','3')
#define BI_DECJPEGDIB           mmioFOURCC('J','P','E','G')
#define BI_DECMJPGDIB           mmioFOURCC('M','J','P','G')
#define BI_DECYUVDIB            mmioFOURCC('D','Y','U','V')
#define BI_DECXIMAGEDIB         mmioFOURCC('D','X','I','M')
#define BI_DECSEPYUVDIB         mmioFOURCC('D','S','Y','U')
#define BI_DECMPEGDIB           mmioFOURCC('D','M','P','G')
#define BI_DECHUFFDIB           mmioFOURCC('D','H','U','F')
#define BI_DECSEPRGBDIB         mmioFOURCC('D','S','R','G')
#define BI_DECGRAYDIB           mmioFOURCC('D','G','R','Y')
#define BI_DECSEPYUV411DIB      mmioFOURCC('Y','U','1','2')
#define IsJPEG(s)         (((s) == JPEG_DIB)            || \
                           ((s) == MJPG_DIB))
#define IsYUV422Sep(s)    (((s) == BI_DECSEPYUVDIB)     || \
                           ((s) == BI_YU16SEP))
#define IsYUV411Sep(s)    (((s) == BI_DECSEPYUV411DIB)  || \
                           ((s) == BI_YU12SEP))
#define IsRGBSep(s)       (((s) == BI_DECSEPRGBDIB))
#define IsGray(s)         (((s) == BI_DECGRAYDIB))

// enduser\netmeeting\av\codecs\dec\dech263\sc_conv.c
#define BI_DECSEPRGBDIB         mmioFOURCC('D','S','R','G')
#define _LoadRGBfrom411() \
         R1 = R2 = R3 = R4 = (int) (              + (1.596 * V)); \
         G1 = G2 = G3 = G4 = (int) (- (0.391 * U) - (0.813 * V)); \
         B1 = B2 = B3 = B4 = (int) (+ (2.018 * U)              ); \
	 Luma = (int) (((int) *(Y1++) - 16) * 1.164); \
         R1 += Luma; G1 +=Luma; B1 += Luma; \
	 Luma = (int) (((int) *(Y1++) - 16) * 1.164); \
         R2 += Luma; G2 +=Luma; B2 += Luma; \
         if ((R1 | G1 | B1 | R2 | G2 | B2) & 0xffffff00) { \
           if (R1<0) R1=0; else if (R1>255) R1=255; \
           if (G1<0) G1=0; else if (G1>255) G1=255; \
           if (B1<0) B1=0; else if (B1>255) B1=255; \
           if (R2<0) R2=0; else if (R2>255) R2=255; \
           if (G2<0) G2=0; else if (G2>255) G2=255; \
           if (B2<0) B2=0; else if (B2>255) B2=255; \
         } \
         Luma = (int) (((int) *(Y2++) - 16) * 1.164); \
         R3 += Luma; G3 +=Luma; B3 += Luma; \
         Luma = (int) (((int) *(Y2++) - 16) * 1.164); \
         R4 += Luma; G4 +=Luma; B4 += Luma; \
         if ((R3 | G3 | B3 | R4 | G4 | B4) & 0xffffff00) { \
           if (R3<0) R3=0; else if (R3>255) R3=255; \
           if (G3<0) G3=0; else if (G3>255) G3=255; \
           if (B3<0) B3=0; else if (B3>255) B3=255; \
           if (R4<0) R4=0; else if (R4>255) R4=255; \
           if (G4<0) G4=0; else if (G4>255) G4=255; \
           if (B4<0) B4=0; else if (B4>255) B4=255; \
         }
#define _LoadRGBfrom422() \
         if (U || V) { \
           R1 = R2 = (int) (              + (1.596 * V)); \
           G1 = G2 = (int) (- (0.391 * U) - (0.813 * V)); \
           B1 = B2 = (int) (+ (2.018 * U)              );  \
         } else { R1=R2=G1=G2=B1=B2=0; } \
	 Luma = (int) (((int) *(Y++) - 16) * 1.164); \
         R1 += Luma; G1 += Luma; B1 += Luma; \
	 Luma = (int) (((int) *(Y++) - 16) * 1.164); \
         R2 += Luma; G2 += Luma; B2 += Luma; \
         if ((R1 | G1 | B1 | R2 | G2 | B2) & 0xffffff00) { \
           if (R1<0) R1=0; else if (R1>255) R1=255; \
           if (G1<0) G1=0; else if (G1>255) G1=255; \
           if (B1<0) B1=0; else if (B1>255) B1=255; \
           if (R2<0) R2=0; else if (R2>255) R2=255; \
           if (G2<0) G2=0; else if (G2>255) G2=255; \
           if (B2<0) B2=0; else if (B2>255) B2=255; \
         }
#define _LoadRGBfrom422() \
	 Luma = *(Y++); \
         R1 = Luma                + (1.4075 * V); \
         G1 = Luma - (0.3455 * U) - (0.7169 * V); \
         B1 = Luma + (1.7790 * U); \
	 Luma = *(Y++); \
         R2 = Luma                + (1.4075 * V); \
         G2 = Luma - (0.3455 * U) - (0.7169 * V); \
         B2 = Luma + (1.7790 * U); \
         if ((R1 | G1 | B1 | R2 | G2 | B2) & 0xffffff00) { \
           if (R1<0) R1=0; else if (R1>255) R1=255; \
           if (G1<0) G1=0; else if (G1>255) G1=255; \
           if (B1<0) B1=0; else if (B1>255) B1=255; \
           if (R2<0) R2=0; else if (R2>255) R2=255; \
           if (G2<0) G2=0; else if (G2>255) G2=255; \
           if (B2<0) B2=0; else if (B2>255) B2=255; \
         }

// enduser\netmeeting\av\codecs\dec\dech263\slib.h
#define SlibTypeIsVideoOnly(stype) (stype==SLIB_TYPE_MPEG1_VIDEO || \
                                    stype==SLIB_TYPE_MPEG2_VIDEO || \
                                    SlibTypeIsH26X(stype) || \
                                    stype==SLIB_TYPE_YUV || \
                                    stype==SLIB_TYPE_RGB || \
                                    stype==SLIB_TYPE_BMP || \
                                    stype==SLIB_TYPE_RASTER)

// enduser\netmeeting\core\video.cpp
#define DibHdrSize(lpbi)		((lpbi)->biSize + (int)(lpbi)->biClrUsed * sizeof(RGBQUAD))

// enduser\netmeeting\h\compddk.h
#define ICM_DECOMPRESS_SET_PALETTE  (ICM_USER+29)   // fill in the DIB color table
#define ICM_DECOMPRESS_GET_PALETTE  (ICM_USER+30)   // fill in the DIB color table
#define ICM_DRAW_GET_PALETTE        (ICM_USER+16)   // get the palette needed for drawing
#define ICM_DRAW_CHANGEPALETTE      (ICM_USER+51)   // for animating palette

// enduser\netmeeting\ui\conf\audiowiz.h
#define 	ISDIRECTSOUNDAVAILABLE(SoundCap) (SoundCap & SOUNDCARD_DIRECTSOUND)

// enduser\netmeeting\ui\conf\global.h
#define TOOLBAR_HIGHLIGHT_COLOR	           (RGB(255, 255, 255)) // WHITE

// enduser\netmeeting\ui\conf\vidview.cpp
#define DibHdrSize(lpbi)		((lpbi)->biSize + (int)(lpbi)->biClrUsed * sizeof(RGBQUAD))

// enduser\netmeeting\ui\msconfwb\cgrp.hpp
#define CLRPANE_BLACK	RGB( 0,0,0 )
#define CLRPANE_WHITE	RGB( 255,255,255 )

// enduser\netmeeting\ui\msconfwb\precomp.h
#define SET_PALETTERGB( c )  (0x02000000 | (0x00ffffff & c))

// enduser\netmeeting\ui\msconfwb\tool.hpp
#define DEF_PENCOLOR        RGB(0, 0, 0)
#define DEF_HIGHLIGHTCOLOR  RGB(255, 255, 0)

// enduser\netmeeting\ui\wb\cgrp.hpp
#define CLRPANE_BLACK	RGB( 0,0,0 )
#define CLRPANE_WHITE	RGB( 255,255,255 )

// enduser\netmeeting\ui\wb\precomp.h
#define SET_PALETTERGB( c )  (0x02000000 | (0x00ffffff & c))

// enduser\netmeeting\ui\wb\tool.hpp
#define DEF_PENCOLOR        RGB(0, 0, 0)
#define DEF_HIGHLIGHTCOLOR  RGB(255, 255, 0)

// enduser\stuff\itircl\inc\font.h
#define coDEFAULT  RGB(1, 1, 0)
#define coBLACK    RGB(  0,   0,   0)
#define coBLUE     RGB(  0,   0, 255)
#define coCYAN     RGB(  0, 255, 255)
#define coGREEN    RGB(  0, 255,   0)
#define coMAGENTA  RGB(255,   0, 255)
#define coRED      RGB(255,   0,   0)
#define coYELLOW   RGB(255, 255,   0)
#define coWHITE    RGB(255, 255, 255)
#define coDARKBLUE		RGB(  0,   0, 128)
#define coDARKCYAN		RGB(  0, 128, 128)
#define coDARKGREEN		RGB(  0, 128,   0)
#define coDARKMAGENTA	RGB(128,   0, 128)
#define coDARKRED		RGB(128,   0,   0)
#define coDARKYELLOW	RGB(128, 128,   0)
#define coDARKGREY		RGB(128, 128, 128)
#define coLIGHTGRAY		RGB(192, 192, 192)

// enduser\stuff\itircl\inc\imvfs.h
#define FBtreeKeyTypeIsSz(c)  ((c) == KT_SZ || (c) == KT_SZMAP || (c) == KT_SZI || \
			    (c) == KT_SZISCAND)

// enduser\stuff\itircl\inc\wrapstor.h
#define FBtreeKeyTypeIsSz(c)  ((c) == KT_SZ || (c) == KT_SZMAP || (c) == KT_SZI || \
			    (c) == KT_SZISCAND)

// inetcore\connectionwizard\icwutil\gifcon.h
#define     COLOR1              (RGB(0,0,255))
#define     COLOR2              (RGB(0,255,0))

// inetcore\mshtml\src\core\include\cdutil.hxx
#define OLECOLOR_FROM_SYSCOLOR(__c) ((__c) | 0x80000000)

// inetcore\mshtml\src\edit\inscmd.cxx
#define BREAK_CONDITION_InsertBackscan (BREAK_CONDITION_OMIT_PHRASE | BREAK_CONDITION_NoScope)

// inetcore\mshtml\src\site\display\pubprint.hxx
#define ColorRefFromRgbQuad(rgbquad)    (*((COLORREF FAR *)&(rgbquad)))
#define cbSDIB                          (sizeof(SDIB))
#define cbRGBQUAD                       (sizeof(RGBQUAD))
#define clrBlack             (RGB(0,0,0))
#define clrWhite             (RGB(255,255,255))

// inetcore\mshtml\src\site\download\imgart.cxx
#define JG_COLORMAP_SIZE8  (sizeof(RGBQUAD) * 256)
#define JG_COLORMAP_SIZE4  (sizeof(RGBQUAD) * 16)
#define JG_COLORMAP_SIZE1  (sizeof(RGBQUAD) * 2)

// inetcore\mshtml\src\site\include\props.hxx
#define ZEROPIXELS MAKEPIXELUNITVALUE(0)

// inetcore\mshtml\src\site\layout\layout.hxx
#define RFE_WIGGLY          (RFE_WIGGLY_RECTS | RFE_ELEMENT_RECT | RFE_IGNORE_RELATIVE | RFE_NESTED_REL_RECTS)

// inetcore\mshtml\src\site\util\shape.cxx
            #define StartVerticalSegment(x, xx, yy) \
                vseg.cx = x; \
                vseg.ptTopLeft.x = xx; \
                vseg.ptTopLeft.y = yy; \
                aryVSegments.AppendIndirect(&vseg);

// inetcore\mshtml\src\time\anim\colorutil.h
#define NUM_RGB_COLORS          (255)

// inetcore\mshtml\tried\triedit\fmtinfo.h
#define RGB_BLACK       RGB(0x00, 0x00, 0x00)
#define RGB_WHITE       RGB(0xFF, 0xFF, 0xFF)
#define RGB_RED         RGB(0xFF, 0x00, 0x00)
#define RGB_GREEN       RGB(0x00, 0xFF, 0x00)
#define RGB_BLUE        RGB(0x00, 0x00, 0xFF)
#define RGB_YELLOW      RGB(0xFF, 0xFF, 0x00)
#define RGB_MAGENTA     RGB(0xFF, 0x00, 0xFF)
#define RGB_CYAN        RGB(0x00, 0xFF, 0xFF)
#define RGB_LIGHTGRAY   RGB(0xC0, 0xC0, 0xC0)
#define RGB_GRAY        RGB(0x80, 0x80, 0x80)
#define RGB_DARKRED     RGB(0x80, 0x00, 0x00)
#define RGB_DARKGREEN   RGB(0x00, 0x80, 0x00)
#define RGB_DARKBLUE    RGB(0x00, 0x00, 0x80)
#define RGB_LIGHTBROWN  RGB(0x80, 0x80, 0x00)
#define RGB_DARKMAGENTA RGB(0x80, 0x00, 0x80)
#define RGB_DARKCYAN    RGB(0x00, 0x80, 0x80)

// inetcore\outlookexpress\inc\msoert.h
#define RGB_AUTOCOLOR       ((COLORREF)-1)

// inetcore\outlookexpress\mailnews\common\util.h
#define TOOLBAR_BKGDCLR     RGB(0xff, 0, 0xff)

// inetcore\outlookexpress\mailnews\mail\header.cpp
#define RGB_TRANSPARENT             RGB(255,0,255)

// inetcore\outlookexpress\msoert\oertutil.cpp
#define RGB_BUTTONTEXT      (RGB(000,000,000))  // black
#define RGB_BUTTONSHADOW    (RGB(128,128,128))  // dark grey
#define RGB_BUTTONFACE      (RGB(192,192,192))  // bright grey
#define RGB_BUTTONHILIGHT   (RGB(255,255,255))  // white
#define RGB_TRANSPARENT     (RGB(255,000,255))  // pink

// inetcore\outlookexpress\wabw\wabapi\uimisc.h
#define RGB_TRANSPARENT (COLORREF)0x00FF00FF

// inetcore\published\inc\dxsurfb.h
#define DECLARE_REGISTER_DX_SURFACE(id)\
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) \
        { \
            CATID cat[2]; \
            cat[0] = CATID_DXSurface; \
            cat[1] = CATID_DXImageTransform; \
            return RegisterSurface(GetObjectCLSID(), (id), 2, cat, 0, NULL, bRegister); \
        }
#define DECLARE_REGISTER_DX_AUTHORING_SURFACE(id)\
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) \
        { \
            CATID cat[3]; \
            cat[0] = CATID_DXSurface; \
            cat[1] = CATID_DXImageTransform; \
            cat[2] = CATID_DXAuthoringTransform; \
            return RegisterSurface(GetObjectCLSID(), (id), 3, cat, 0, NULL, bRegister); \
        }

// inetcore\setup\ieak5\cd\autorun\autorun.c
#define BUTTON_CLEAR_PALETTE_INDEX  (250)
#define BUTTON_SHADOW_PALETTE_INDEX (251)

// inetsrv\iis\admin\certmap\hotlink.cpp
#define COLOR_BLUE          RGB(0, 0, 0xFF)

// inetsrv\iis\admin\certwiz\hotlink.cpp
#define COLOR_BLUE			RGB(0, 0, 0xFF)
#define COLOR_YELLOW		RGB(0xff, 0x80, 0)

// inetsrv\iis\admin\snapin\iisobj.cpp
#define RGB_BK_IMAGES (RGB(255,0,255))      // purple

// inetsrv\iis\admin\snapin\inetmgrapp.h
#define RGB_BK_IMAGES (RGB(255,0,255))      // purple

// inetsrv\iis\admin\snapin\inetprop.h
#define BEGIN_META_DIR_READ(sheet)\
{                                                                        \
    sheet * pSheet = (sheet *)GetSheet();                                \
    do                                                                   \
    {                                                                    \
        if (FAILED(pSheet->QueryDirectoryResult()))                      \
        {                                                                \
            break;                                                       \
        }

// inetsrv\iis\admin\snapin\shts.h
#define BEGIN_META_DIR_READ(sheet)\
{                                                                        \
    sheet * pSheet = (sheet *)GetSheet();                                \
    do                                                                   \
    {                                                                    \
        if (FAILED(pSheet->QueryDirectoryResult()))                      \
        {                                                                \
            break;                                                       \
        }

// inetsrv\iis\svcs\cmp\webdav\inc\statcode.h
#define FRedirectHSC(_h)				(((_h) == 301) ||		\
										 ((_h) == 302) ||		\
										 ((_h) == 303) ||		\
										 ((_h) == 305))

// inetsrv\iis\svcs\infocomm\atq\abw.hxx
# define CIRCULAR_INCREMENT( sm_pB, sm_rgB, size)  \
            (sm_pB) = ((((sm_pB) + 1) < (sm_rgB)+(size)) ? (sm_pB)+1 : (sm_rgB))

// inetsrv\iis\ui\admin\certmap\hotlink.cpp
#define COLOR_BLUE          RGB(0, 0, 0xFF)

// inetsrv\iis\ui\admin\certwiz\hotlink.cpp
#define COLOR_BLUE			RGB(0, 0, 0xFF)
#define COLOR_YELLOW		RGB(0xff, 0x80, 0)

// inetsrv\iis\ui\admin\comprop\inetprop.h
#define BEGIN_META_DIR_READ(sheet)\
{                                                                        \
    sheet * pSheet = (sheet *)GetSheet();                                \
    do                                                                   \
    {                                                                    \
        if (FAILED(pSheet->QueryDirectoryResult()))                      \
        {                                                                \
            break;                                                       \
        }

// inetsrv\iis\ui\admin\mmc\cinetmgr.cpp
#define RGB_BK_IMAGES (RGB(255,0,255))      // purple

// inetsrv\iis\ui\admin\pws\hotlink.cpp
#define COLOR_BLUE          RGB(0, 0, 0xFF)

// inetsrv\iis\ui\admin\pws\tipdlg.cpp
#define COLOR_WHITE         RGB(0xFF, 0xFF, 0xFF)
#define COLOR_BLACK         RGB(0, 0, 0)

// inetsrv\iis\ui\admin\pws\title.cpp
#define COLOR_WHITE         RGB(0xFF, 0xFF, 0xFF)
#define COLOR_BLACK         RGB(0, 0, 0)

// inetsrv\iis\ui\itools\keyring\hotlink.cpp
#define COLOR_BLUE			RGB(0, 0, 0xFF)

// inetsrv\msmq\src\ac\win95\ntddk95.h
#define DIRECTORY_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0xF)

// inetsrv\query\filters\office\src\findfast\dmippst2.c
#define STORAGE_ACCESS (STGM_DIRECT | STGM_SHARE_DENY_WRITE | STGM_READ)

// inetsrv\query\filters\office\src\findfast\dmixlst2.c
   #define STORAGE_ACCESS (STGM_DIRECT | STGM_SHARE_DENY_WRITE | STGM_READ)

// inetsrv\query\filters\office\src\findfast\dmubdst2.c
#define STORAGE_ACCESS (STGM_DIRECT | STGM_SHARE_DENY_WRITE | STGM_READ)

// multimedia\danim\src\daxctl\controls\sgrfx\sgrfx.h
#define DibSize(lpbi)           ((lpbi)->biSize + (lpbi)->biSizeImage + (int)(lpbi)->biClrUsed * sizeof(RGBQUAD))
#define DibPaletteSize(lpbi)    (DibNumColors(lpbi) * sizeof(RGBQUAD))

// multimedia\directx\ddrawex\ddrawex.h
#define IDirectDraw3_Release(p)                      (p)->lpVtbl->Release(p)

// multimedia\directx\ddrawex\dx3inc\d3d.h
#define IDirect3D_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirect3DDevice_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirect3DLight_Release(p)              (p)->lpVtbl->Release(p)
#define IDirect3DMaterial_Release(p)              (p)->lpVtbl->Release(p)
#define IDirect3DTexture_Release(p)              (p)->lpVtbl->Release(p)
#define IDirect3DViewport_Release(p)                       (p)->lpVtbl->Release(p)

// multimedia\directx\ddrawex\dx3inc\d3dtypes.h
#define RGBA_GETBLUE(rgb)       ((rgb) & 0xff)
#define RGB_GETBLUE(rgb)        ((rgb) & 0xff)
#define RGBA_TORGB(rgba)       ((D3DCOLOR) ((rgba) & 0xffffff))
#define RGB_TORGBA(rgb)        ((D3DCOLOR) ((rgb) | 0xff000000))

// multimedia\directx\ddrawex\dx3inc\ddraw.h
#define IDirectDraw_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw2_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDrawPalette_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawClipper_Release(p)               (p)->lpVtbl->Release(p)
#define IDirectDrawSurface_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface2_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface2_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)

// multimedia\directx\ddrawex\dx3inc\ddrawex.h
#define IDirectDraw3_Release(p)                      (p)->lpVtbl->Release(p)

// multimedia\directx\ddrawex\dx3inc\ddrawp.h
#define IDirectDraw_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw2_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDrawPalette_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawClipper_Release(p)               (p)->lpVtbl->Release(p)
#define IDirectDrawSurface_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface2_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface2_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)

// multimedia\directx\ddrawex\dx6\d3d.h
#define IDirect3D_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3D2_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3D3_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DDevice_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DDevice2_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DDevice3_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DLight_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DMaterial_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DMaterial2_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DMaterial3_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DTexture_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DTexture2_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DViewport_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DViewport2_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DViewport3_Release(p) (p)->lpVtbl->Release(p)

// multimedia\directx\ddrawex\dx6\d3dtypes.h
#define RGBA_GETBLUE(rgb)       ((rgb) & 0xff)
#define RGB_GETBLUE(rgb)        ((rgb) & 0xff)
#define RGBA_TORGB(rgba)       ((D3DCOLOR) ((rgba) & 0xffffff))
#define RGB_TORGBA(rgb)        ((D3DCOLOR) ((rgb) | 0xff000000))

// multimedia\directx\ddrawex\dx6\ddraw.h
#define IDirectDraw_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw2_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw4_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDrawPalette_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawClipper_Release(p)               (p)->lpVtbl->Release(p)
#define IDirectDrawSurface_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface2_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface2_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface3_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface3_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface4_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface4_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface4_FreePrivateData(p,a)	 (p)->lpVtbl->FreePrivateData(p,a)
#define IDirectDrawGammaControl_Release(p)               (p)->lpVtbl->Release(p)

// multimedia\directx\ddrawex\dx6\dinput.h
#define IDirectInputEffect_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDevice_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDevice2_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInput_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInput2_Release(p) (p)->lpVtbl->Release(p)

// multimedia\directx\ddrawex\dx6\dmusicf.h
#define DMUS_FOURCC_CHORDPALETTE_LIST		mmioFOURCC('c','h','p','l')

// multimedia\directx\ddrawex\dx6\dplay.h
#define IDirectPlay2_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlay3_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlayX_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlay_Release(p)                      (p)->lpVtbl->Release(p)

// multimedia\directx\ddrawex\dx6\dsound.h
#define IDirectSound_Release(p)                  (p)->lpVtbl->Release(p)
#define IDirectSoundCapture_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectSoundNotify_Release(p)                       (p)->lpVtbl->Release(p)

// multimedia\directx\ddrawex\dx6\dvp.h
#define IVideoPort_Release(p)                   (p)->lpVtbl->Release(p)

// multimedia\directx\dinput\dx8\dimap\dimap.h
#define IDirectInputMapper_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputMapperVendor_Release(p) (p)->lpVtbl->Release(p)

// multimedia\directx\dmusic\dmcompos\dmcompp.h
#define FOURCC_LISTCHORDPALETTE		mmioFOURCC('c','h','p','l')

// multimedia\directx\dmusic\dmcompos\iodmcomp.h
#define FOURCC_LISTCHORDPALETTE		mmioFOURCC('c','h','p','l')

// multimedia\directx\dplay\dnet\inc\dpaddr.h
#define IDirectPlay8Address_Release(p)         			    (p)->lpVtbl->Release(p)
#define IDirectPlay8AddressIP_Release(p)         		    (p)->lpVtbl->Release(p)
#define IDirectPlay8AddressInternal_Release(p)         	    (p)->lpVtbl->Release(p)

// multimedia\directx\dplay\dnet\inc\dplay8.h
#define	IDirectPlay8Client_Release(p)							(p)->lpVtbl->Release(p)
#define	IDirectPlay8Server_Release(p)							(p)->lpVtbl->Release(p)
#define	IDirectPlay8Peer_Release(p)								(p)->lpVtbl->Release(p)

// multimedia\directx\dplay\dnet\inc\dpsp8.h
#define IDP8SPCallback_Release(p)			   		(p)->lpVtbl->Release(p)
#define IDP8ServiceProvider_Release(p)					(p)->lpVtbl->Release(p)

// multimedia\directx\dplay\dplay\dplay\dplay.h
#define IDirectPlay2_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlay3_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlayX_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlay_Release(p)                      (p)->lpVtbl->Release(p)

// multimedia\directx\dplay\dpnathlp\inc\dpnathlp.h
#define	IDirectPlayNATHelp_Release(p)								(p)->lpVtbl->Release(p)

// multimedia\directx\dplay\dvoice\inc\dvoice.h
#define IDirectPlayVoiceClient_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectPlayVoiceServer_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectPlayVoiceTest_Release(p)                	    (p)->lpVtbl->Release(p)
#define IDirectPlayVoiceNotify_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectPlayVoiceTransport_Release(p)                (p)->lpVtbl->Release(p)

// multimedia\directx\dplay\tools\dp8sim\inc\dp8sim.h
#define	IDP8SimControl_Release(p)						(p)->lpVtbl->Release(p)

// multimedia\directx\dsound\dsound\pset.h
#define BEGIN_DECLARE_PROPERTY_HANDLERS(classname, set) \
            const PROPERTYHANDLER classname##::##GET_PROPERTY_HANDLER_NAME(set)##[] = \
            {
#define DECLARE_PROPERTY_SET(classname, set) \
                { \
                    &##set, \
                    NUMELMS(classname##::##GET_PROPERTY_HANDLER_NAME(set)), \
                    classname##::##GET_PROPERTY_HANDLER_NAME(set) \
                },

// multimedia\directx\dxg\d3d8\inc\span.h
#define D3DI_SPANTEX_ALPHAPALETTE          (0x00000008L)
#define MAKE_RGB8(r, g, b) (RGB8_CHANNEL(r) * 36       \
                 + RGB8_CHANNEL(g) * 6                 \
                 + RGB8_CHANNEL(b))

// multimedia\directx\dxg\d3d8\tnl\pvvid.h
#define D3DFE_SET_ALPHA(color, a) ((char*)&color)[3] = (unsigned char)a;

// multimedia\directx\dxg\d3d\dx6\inc\haldrv.hpp
#define LOCK_DIBENGINE(ret, lpDevI) ret = DD_OK
#define UNLOCK_DIBENGINE(lpDevI)
#define CALL_HALONLY_NOLOCK(ret, lpDevI, call, data)                          \
{                                                                             \
    if (lpDevI->lpD3DHALCallbacks->call) {                                    \
        LOCK_DIBENGINE(ret, lpDevI);                                          \
        if (ret != DD_OK) {                                                   \
            D3D_ERR("dibengine was busy, not calling HAL");                   \
        } else {                                                              \
            ret = (*lpDevI->lpD3DHALCallbacks->call)(data);                   \
            TRACK_HAL_CALL(lpDevI)                                            \
            UNLOCK_DIBENGINE(lpDevI);                                         \
        }                                                                     \
    } else {                                                                  \
        D3D_ERR("No HAL call available");                                     \
        ret = DDHAL_DRIVER_NOTHANDLED;                                        \
    }                                                                         \
}
#define CALL_HAL2ONLY_NOLOCK(ret, lpDevI, call, data)                         \
{                                                                             \
    if (lpDevI->lpD3DHALCallbacks2->call) {                                   \
        LOCK_DIBENGINE(ret, lpDevI);                                          \
        if (ret != DD_OK) {                                                   \
            D3D_ERR("dibengine was busy, not calling HAL");                   \
        } else {                                                              \
            ret = (*lpDevI->lpD3DHALCallbacks2->call)(data);                  \
            TRACK_HAL_CALL(lpDevI)                                            \
            UNLOCK_DIBENGINE(lpDevI);                                         \
        }                                                                     \
    } else {                                                                  \
        D3D_ERR("No HAL call available");                                     \
        ret = DDHAL_DRIVER_NOTHANDLED;                                        \
    }                                                                         \
}
#define CALL_HALCBONLY_NOLOCK(ret, lpDevI, call, data)                        \
{                                                                             \
    if (lpDevI->lpD3DHALCommandBufferCallbacks->call) {                       \
        LOCK_DIBENGINE(ret, lpDevI);                                          \
        if (ret != DD_OK) {                                                   \
            D3D_ERR("dibengine was busy, not calling HAL");                   \
        } else {                                                              \
            ret = (*lpDevI->lpD3DHALCommandBufferCallbacks->call)(data);      \
            TRACK_HAL_CALL(lpDevI)                                            \
            UNLOCK_DIBENGINE(lpDevI);                                         \
        }                                                                     \
    } else {                                                                  \
        D3D_ERR("No HAL call available");                                     \
        ret = DDHAL_DRIVER_NOTHANDLED;                                        \
    }                                                                         \
}
#define CALL_HAL3ONLY_NOLOCK(ret, lpDevI, call, data)                         \
{                                                                             \
    if (lpDevI->lpD3DHALCallbacks3->call) {                                   \
        LOCK_DIBENGINE(ret, lpDevI);                                          \
        if (ret != DD_OK) {                                                   \
            D3D_ERR("dibengine was busy, not calling HAL");                   \
        } else {                                                              \
            ret = (*lpDevI->lpD3DHALCallbacks3->call)(data);                  \
            TRACK_HAL_CALL(lpDevI)                                            \
            UNLOCK_DIBENGINE(lpDevI);                                         \
        }                                                                     \
    } else {                                                                  \
        D3D_ERR("No HAL call available");                                     \
        ret = DDHAL_DRIVER_NOTHANDLED;                                        \
    }                                                                         \
}

// multimedia\directx\dxg\d3d\dx6\inc\span.h
#define D3DI_SPANTEX_ALPHAPALETTE       (0x00000008L)
#define MAKE_RGB8(r, g, b) (RGB8_CHANNEL(r) * 36       \
                 + RGB8_CHANNEL(g) * 6                 \
                 + RGB8_CHANNEL(b))

// multimedia\directx\dxg\d3d\dx6\pipeln\inc\light.h
#define D3DFE_SET_ALPHA(color, a) ((char*)&color)[3] = (unsigned char)a;

// multimedia\directx\dxg\d3d\dx6\rast\d3dif\getcaps.h
#define TRISHADECAPS					\
    D3DPSHADECAPS_COLORFLATRGB			|	\
	D3DPSHADECAPS_COLORGOURAUDRGB		|	\
	D3DPSHADECAPS_SPECULARFLATRGB		|	\
	D3DPSHADECAPS_SPECULARGOURAUDRGB	|	\
	D3DPSHADECAPS_ALPHAFLATSTIPPLED		|	\
	D3DPSHADECAPS_ALPHAGOURAUDSTIPPLED	|	\
	D3DPSHADECAPS_FOGFLAT			|	\
	D3DPSHADECAPS_FOGGOURAUD
#define TRIRASTERCAPS					\
    D3DPRASTERCAPS_DITHER			|	\
	D3DPRASTERCAPS_SUBPIXELX		|	\
	D3DPRASTERCAPS_FOGVERTEX		|	\
	D3DPRASTERCAPS_FOGTABLE		|	\
	D3DPRASTERCAPS_ZTEST
#define TRIRASTERCAPS					\
    D3DPRASTERCAPS_DITHER			|	\
	D3DPRASTERCAPS_SUBPIXELX		|	\
	D3DPRASTERCAPS_ZTEST

// multimedia\directx\dxg\d3d\dx6\rast\rampold\dditypes.h
#define RGBA_GET_BLUE(ci)	((ci) & 0xff)
#define RGB_GET_BLUE(ci)	((ci) & 0xff)
#define RGBA_TO_RGB(rgba)	((rgba) & 0xffffff)
#define RGB_TO_RGBA(rgb)	((rgb) | 0xff000000)

// multimedia\directx\dxg\d3d\dx6\rast\setup\line.cpp
#define CLAMP_COLOR(fVal, uVal) \
    if (FLOAT_LTZ(fVal))        \
    {                           \
        uVal = 0;               \
    }                           \
    else                        \
    {                           \
        if (uVal > 0xffff)      \
        {                       \
            uVal = 0xffff;      \
        }                       \
    }                           \

// multimedia\directx\dxg\d3d\dx7\inc\haldrv.hpp
#define LOCK_DIBENGINE(ret, lpDevI) ret = DD_OK
#define UNLOCK_DIBENGINE(lpDevI)
#define CALL_HALONLY_NOLOCK(ret, lpDevI, call, data)                          \
{                                                                             \
    if (lpDevI->lpD3DHALCallbacks->call) {                                    \
        LOCK_DIBENGINE(ret, lpDevI);                                          \
        if (ret != DD_OK) {                                                   \
            D3D_ERR("dibengine was busy, not calling HAL");                   \
        } else {                                                              \
            ret = (*lpDevI->lpD3DHALCallbacks->call)(data);                   \
            TRACK_HAL_CALL(lpDevI)                                            \
            UNLOCK_DIBENGINE(lpDevI);                                         \
        }                                                                     \
    } else {                                                                  \
        D3D_ERR("No HAL call available");                                     \
        ret = DDHAL_DRIVER_NOTHANDLED;                                        \
    }                                                                         \
}
#define CALL_HAL2ONLY_NOLOCK(ret, lpDevI, call, data)                         \
{                                                                             \
    if (lpDevI->lpD3DHALCallbacks2->call) {                                   \
        LOCK_DIBENGINE(ret, lpDevI);                                          \
        if (ret != DD_OK) {                                                   \
            D3D_ERR("dibengine was busy, not calling HAL");                   \
        } else {                                                              \
            ret = (*lpDevI->lpD3DHALCallbacks2->call)(data);                  \
            TRACK_HAL_CALL(lpDevI)                                            \
            UNLOCK_DIBENGINE(lpDevI);                                         \
        }                                                                     \
    } else {                                                                  \
        D3D_ERR("No HAL call available");                                     \
        ret = DDHAL_DRIVER_NOTHANDLED;                                        \
    }                                                                         \
}
#define CALL_HALCBONLY_NOLOCK(ret, lpDevI, call, data)                        \
{                                                                             \
    if (lpDevI->lpD3DHALCommandBufferCallbacks->call) {                       \
        LOCK_DIBENGINE(ret, lpDevI);                                          \
        if (ret != DD_OK) {                                                   \
            D3D_ERR("dibengine was busy, not calling HAL");                   \
        } else {                                                              \
            ret = (*lpDevI->lpD3DHALCommandBufferCallbacks->call)(data);      \
            TRACK_HAL_CALL(lpDevI)                                            \
            UNLOCK_DIBENGINE(lpDevI);                                         \
        }                                                                     \
    } else {                                                                  \
        D3D_ERR("No HAL call available");                                     \
        ret = DDHAL_DRIVER_NOTHANDLED;                                        \
    }                                                                         \
}
#define CALL_HAL3ONLY_NOLOCK(ret, lpDevI, call, data)                         \
{                                                                             \
    if (lpDevI->lpD3DHALCallbacks3->call) {                                   \
        LOCK_DIBENGINE(ret, lpDevI);                                          \
        if (ret != DD_OK) {                                                   \
            D3D_ERR("dibengine was busy, not calling HAL");                   \
        } else {                                                              \
            ret = (*lpDevI->lpD3DHALCallbacks3->call)(data);                  \
            TRACK_HAL_CALL(lpDevI)                                            \
            UNLOCK_DIBENGINE(lpDevI);                                         \
        }                                                                     \
    } else {                                                                  \
        D3D_ERR("No HAL call available");                                     \
        ret = DDHAL_DRIVER_NOTHANDLED;                                        \
    }                                                                         \
}

// multimedia\directx\dxg\d3d\dx7\inc\span.h
#define D3DI_SPANTEX_ALPHAPALETTE          (0x00000008L)
#define MAKE_RGB8(r, g, b) (RGB8_CHANNEL(r) * 36       \
                 + RGB8_CHANNEL(g) * 6                 \
                 + RGB8_CHANNEL(b))

// multimedia\directx\dxg\d3d\dx7\rast\setup\line.cpp
#define CLAMP_COLOR(fVal, uVal) \
    if (FLOAT_LTZ(fVal))        \
    {                           \
        uVal = 0;               \
    }                           \
    else                        \
    {                           \
        if (uVal > 0xffff)      \
        {                       \
            uVal = 0xffff;      \
        }                       \
    }                           \

// multimedia\directx\dxg\d3d\dx7\tnl\pvvid.h
#define D3DFE_SET_ALPHA(color, a) ((char*)&color)[3] = (unsigned char)a;

// multimedia\directx\dxg\d3d\ref\inc\reftnl.hpp
#define RRPV_DIRTY_LIGHTING    (RRPV_DIRTY_MATERIAL     | \
                                RRPV_DIRTY_SETLIGHT     | \
                                RRPV_DIRTY_NEEDXFMLIGHT | \
                                RRPV_DIRTY_COLORVTX)

// multimedia\directx\dxg\d3d\ref\tnl\lighting.cpp
#define RRPV_SET_ALPHA(color, a) ((char*)&color)[3] = (unsigned char)a;

// multimedia\directx\dxg\dd\ddraw\blitlib\dibfx.h
#define DibFromHandle(h)        (PDIB)GlobalLock(h)
#define DibSize(lpbi)           ((lpbi)->biSize + (lpbi)->biSizeImage + \
								(int)(lpbi)->biClrUsed * sizeof(RGBQUAD))
#define DibPaletteSize(lpbi)    (DibNumColors(lpbi) * sizeof(RGBQUAD))

// multimedia\directx\dxg\dd\ddraw\ddraw16\gdihelp.c
#define DPF_PALETTE(x)

// multimedia\directx\dxg\dd\ddraw\main\ddcsurf.c
#define UNDERSTOOD_PF (                \
    DDPF_RGB               |           \
    DDPF_PALETTEINDEXED8   |           \
    DDPF_ALPHAPIXELS       |           \
    DDPF_ZBUFFER           |           \
    DDPF_LUMINANCE         |           \
    DDPF_BUMPDUDV          |           \
    DDPF_BUMPLUMINANCE     |           \
    DDPF_ALPHA             |           \
    DDPF_ZPIXELS)

// multimedia\directx\dxg\dd\ddraw\main\ddgdi32.c
#define CALL_D3DHAL_TAKEBUSY_NOWIN16(ret, pDevice, func, data)          \
{                                                                       \
    if (func)                                                           \
    {                                                                   \
        ret = LockDibEngine((pDevice)->pDD->lpLcl->lpGbl);              \
        if (ret != DD_OK)                                               \
        {                                                               \
            ret = DDHAL_DRIVER_HANDLED;                                 \
        }                                                               \
        else                                                            \
        {                                                               \
            ret = (*(func))(data);                                      \
            UnlockDibEngine((pDevice)->pDD->lpLcl->lpGbl);              \
        }                                                               \
    }                                                                   \
    else                                                                \
    {                                                                   \
        DPF_ERR("No HAL call available");                               \
        ret = DDHAL_DRIVER_NOTHANDLED;                                  \
    }                                                                   \
}

// multimedia\directx\dxg\dd\ddraw\main\ddkernel.h
#define IDirectDrawKernel_ReleaseKernelHandle(p)    (p)->lpVtbl->ReleaseKernelHandle(p)
#define IDirectDrawSurfaceKernel_ReleaseKernelHandle(p)    (p)->lpVtbl->ReleaseKernelHandle(p)

// multimedia\directx\dxg\dd\ddraw\main\ddmcp.h
#define IVideoAccelerator_Release(p)                 (p)->lpVtbl->Release(p)

// multimedia\directx\dxg\dd\ddraw\main\ddraw.c
#define AVAILVIDMEM_BADSCAPS (DDSCAPS_BACKBUFFER   | \
                              DDSCAPS_FRONTBUFFER  | \
                              DDSCAPS_COMPLEX      | \
                              DDSCAPS_FLIP         | \
                              DDSCAPS_OWNDC        | \
                              DDSCAPS_PALETTE      | \
                              DDSCAPS_SYSTEMMEMORY | \
                              DDSCAPS_VISIBLE      | \
                              DDSCAPS_WRITEONLY)

// multimedia\directx\dxg\dd\ddraw\main\ddrawpr.h
        #define DD16_FixupDIBEngine() TRUE

// multimedia\directx\dxg\dd\ddraw\main\dvpp.h
#define IVideoPort_Release(p)                   (p)->lpVtbl->Release(p)
#define IVideoPortNotify_Release(p)                 (p)->lpVtbl->Release(p)
#define IVideoPortNotify_ReleaseNotification(p,a)   (p)->lpVtbl->ReleaseNotification(p,a)
#define IVideoPortNotify_ReleaseNotification(p,a)   (p)->lpVtbl->ReleaseNotification(a)

// multimedia\directx\dxg\ref8\inc\reftnl.hpp
#define RDPV_DIRTY_LIGHTING    (RDPV_DIRTY_MATERIAL     | \
                                RDPV_DIRTY_SETLIGHT     | \
                                RDPV_DIRTY_NEEDXFMLIGHT | \
                                RDPV_DIRTY_COLORVTX)

// multimedia\directx\dxg\swrast\rgb\pch\d3dflt.h
#define ASFLOAT(i) (*(FLOAT *)&(i))
#define ASINT32(f) (*(INT32 *)&(f))
#define ASUINT32(f) (*(UINT32 *)&(f))
#define FPU_MODE_LOW_PRECISION(uMode) \
    ((uMode) & 0xfcff)
#define FLOAT_EQZ(flt)                  ((ASUINT32(flt) & 0x7fffffff) == 0)
#define FLOAT_NEZ(flt)                  ((ASUINT32(flt) & 0x7fffffff) != 0)

// multimedia\directx\dxg\swrast\rgb\pch\setup.hpp
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

// multimedia\directx\dxg\swrast\rgb\pch\span.h
#define D3DI_SPANTEX_ALPHAPALETTE          (0x00000008L)
#define MAKE_RGB8(r, g, b) (RGB8_CHANNEL(r) * 36       \
                 + RGB8_CHANNEL(g) * 6                 \
                 + RGB8_CHANNEL(b))

// multimedia\directx\dxg\swrast\rgb\setup\buffer.cpp
#define AVOID_FLUSH_SPACE (8 * sizeof(D3DI_RASTSPAN))

// multimedia\directx\dxg\swrast\rgb\setup\d3dutil.cpp
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

// multimedia\directx\dxg\swrast\rgb\setup\line.cpp
#define CLAMP_COLOR(fVal, uVal) \
    if (FLOAT_LTZ(fVal))        \
    {                           \
        uVal = 0;               \
    }                           \
    else                        \
    {                           \
        if (uVal > 0xffff)      \
        {                       \
            uVal = 0xffff;      \
        }                       \
    }                           \

// multimedia\directx\dxg\swrast\rgb\setup\lstp.cpp
#define NEEDS_NORMALIZE2(fV0, fV1) \
    ((ASUINT32(fV0) | ASUINT32(fV1)) > INT32_FLOAT_ONE)
#define LINEDIR_CMP( _A, _B ) \
    ( bLineMajorNeg ? ( (_A) > (_B) ) : ( (_A) < (_B) ) )

// multimedia\directx\dxg\swrast\rgb\setup\point.cpp
#define NEEDS_NORMALIZE1(fV0) \
    (ASUINT32(fV0) > INT32_FLOAT_ONE)

// multimedia\directx\dxvb\dx7vb\frmsave.cpp
#define MyD3DRMColorGetBlue(color)  ((float)((color & 0x000000FF))/(float)255)

// multimedia\directx\dxvb\dx7vb\inc\dinput.h
#define IDirectInputEffect_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDevice_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDevice2_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDevice7_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInput_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInput2_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInput7_Release(p) (p)->lpVtbl->Release(p)

// multimedia\directx\dxvb\dx7vb\inc\dmusicf.h
#define DMUS_FOURCC_CHORDPALETTE_LIST   mmioFOURCC('c','h','p','l')

// multimedia\directx\dxvb\dx7vb\inc\dsound.h
#define IUnknown_Release(p)             (p)->lpVtbl->Release(p)

// multimedia\directx\dxvb\dx8vb\frmsave.cpp
#define MyD3DRMColorGetBlue(color)  ((float)((color & 0x000000FF))/(float)255)

// multimedia\directx\gamectrl\client\joyhelp.h
#define IDH_101_1002    65667173    // Game Controllers: "&Properties..." (Button)
#define IDH_101_1010    66191461    // Game Controllers: "A&dd..." (Button)
#define IDH_101_1028    67371109    // Game Controllers: "&Remove..." (Button)
#define IDH_101_1058    69337189    // Game Controllers: "&Game Controllers" (Static)
#define IDH_117_1100    72089717    // -: "P&oll with interrupts enabled" (Button)
#define IDH_117_1101    72155253    // -: "&Port Driver:" (Static)
#define IDH_117_8195    537067637   // -: "&Controller ID's:" (Static)
#define IDH_117_8198    537264245   // -: "Cha&nge..." (Button)
#define IDH_119_1039    68092023    // Add Game Controller: "&Add Other..." (Button)
#define IDH_119_1049    68092025    // Add Game Controller: "&Custom..." (Button)
#define IDH_119_1059    69402743    // Add Game Controller: "&Controllers:" (Static)
#define IDH_4099_1043   68358147    // Custom Game Controller: "&Axes" (Button)
#define IDH_4099_1054   69079043    // Custom Game Controller: "Has a &point of view control" (Button)
#define IDH_117_1101    72155253    // -: "&Port Driver:" (Static)
#define IDH_101_1002    65667173    // Game Controllers: "&Properties..." (Button)
#define IDH_101_1010    66191461    // Game Controllers: "A&dd..." (Button)
#define IDH_101_1028    67371109    // Game Controllers: "&Remove..." (Button)
#define IDH_101_1058    69337189    // Game Controllers: "&Game Controllers" (Static)
#define IDH_117_1101    72155253    // -: "&Port Driver:" (Static)
#define IDH_117_8195    537067637   // -: "&Controller ID's:" (Static)
#define IDH_117_8198    537264245   // -: "Cha&nge..." (Button)
#define IDH_119_1039    68092023    // Add Game Controller: "&Add Other..." (Button)
#define IDH_119_1049    68092025    // Add Game Controller: "&Custom..." (Button)
#define IDH_119_1059    69402743    // Add Game Controller: "&Controllers:" (Static)
#define IDH_4099_1043   68358147    // Custom Game Controller: "&Axes" (Button)
#define IDH_4099_1050   68816899    // Custom Game Controller: "&Special Characteristics" (Button)
#define IDH_4099_1054   69079043    // Custom Game Controller: "Has a &point of view control" (Button)
#define IDH_4101_12328  807931909   // Joystick Calibration: "Capture &POV" (Button)
#define IDH_4101_12329  807997445   // Joystick Calibration: "< &Back" (Button)
#define IDH_4101_12331  808062983   // Joystick Calibration: "&Finish" (Button)
#define IDH_4201_12291  805507177   // Settings: "&Calibrate..." (Button)
#define IDH_4202_12328  807932010   // Game Controller Calibration: "Set &POV" (Button)

// multimedia\directx\gamectrl\client\res\dijoy.h
#define IDH_101_1002	65667173	// Game Controllers: "&Properties..." (Button)
#define IDH_101_1010	66191461	// Game Controllers: "A&dd..." (Button)
#define IDH_101_1028	67371109	// Game Controllers: "&Remove..." (Button)
#define IDH_101_1058	69337189	// Game Controllers: "&Game Controllers" (Static)
#define IDH_117_1101	72155253	// -: "&Port Driver:" (Static)
#define IDH_117_8198	537264245	// -: "Cha&nge..." (Button)
#define IDH_119_1039	68092023	// Add Game Controller: "&Add Other..." (Button)
#define IDH_119_1049	68092025	// Add Game Controller: "&Custom..." (Button)
#define IDH_119_1059	69402743	// Add Game Controller: "&Controllers:" (Static)
#define IDH_4099_1043	68358147	// Custom Game Controller: "&Axes" (Button)
#define IDH_4201_12290	805507175	// Settings: "Reset to &default" (Button)
#define IDH_4201_12291	805507177	// Settings: "&Calibrate..." (Button)

// multimedia\directx\gamectrl\clientnt\joyhelp.h
#define IDH_101_1002    65667173    // Game Controllers: "&Properties..." (Button)
#define IDH_101_1010    66191461    // Game Controllers: "&Add..." (Button)
#define IDH_101_1028    67371109    // Game Controllers: "&Remove..." (Button)
#define IDH_101_1058    69337189    // Game Controllers: "&Game Controllers" (Static)
#define IDH_101_1311    65667174    // Game Controllers: "A&dvanced" (Button)
#define IDH_117_1100    72089717    // -: "P&oll with interrupts enabled" (Button)
#define IDH_117_1101    72155253    // -: "&Port Driver:" (Static)
#define IDH_117_8195    537067637   // -: "&Controller ID's:" (Static)
#define IDH_117_8198    537264245   // -: "Cha&nge..." (Button)
#define IDH_119_1039    68092023    // Add Game Controller: "&Add Other..." (Button)
#define IDH_119_1049    68092025    // Add Game Controller: "&Custom..." (Button)
#define IDH_119_1059    69402743    // Add Game Controller: "&Controllers:" (Static)
#define IDH_4099_1043   68358147    // Custom Game Controller: "&Axes" (Button)
#define IDH_4099_1054   69079043    // Custom Game Controller: "Has a &point of view control" (Button)
#define IDH_117_1101    72155253    // -: "&Port Driver:" (Static)
#define IDH_101_1002    65667173    // Game Controllers: "&Properties..." (Button)
#define IDH_101_1010    66191461    // Game Controllers: "A&dd..." (Button)
#define IDH_101_1028    67371109    // Game Controllers: "&Remove..." (Button)
#define IDH_101_1058    69337189    // Game Controllers: "&Game Controllers" (Static)
#define IDH_117_1101    72155253    // -: "&Port Driver:" (Static)
#define IDH_117_8195    537067637   // -: "&Controller ID's:" (Static)
#define IDH_117_8198    537264245   // -: "Cha&nge..." (Button)
#define IDH_119_1039    68092023    // Add Game Controller: "&Add Other..." (Button)
#define IDH_119_1049    68092025    // Add Game Controller: "&Custom..." (Button)
#define IDH_119_1059    69402743    // Add Game Controller: "&Controllers:" (Static)
#define IDH_4099_1043   68358147    // Custom Game Controller: "&Axes" (Button)
#define IDH_4099_1050   68816899    // Custom Game Controller: "&Special Characteristics" (Button)
#define IDH_4099_1054   69079043    // Custom Game Controller: "Has a &point of view control" (Button)
#define IDH_4101_12328  807931909   // Joystick Calibration: "Capture &POV" (Button)
#define IDH_4101_12329  807997445   // Joystick Calibration: "< &Back" (Button)
#define IDH_4101_12331  808062983   // Joystick Calibration: "&Finish" (Button)
#define IDH_4201_12291  805507177   // Settings: "&Calibrate..." (Button)
#define IDH_4202_12328  807932010   // Game Controller Calibration: "Set &POV" (Button)

// multimedia\directx\gamectrl\clientnt\res\dijoy.h
#define IDH_101_1002	65667173	// Game Controllers: "&Properties..." (Button)
#define IDH_101_1010	66191461	// Game Controllers: "A&dd..." (Button)
#define IDH_101_1028	67371109	// Game Controllers: "&Remove..." (Button)
#define IDH_101_1058	69337189	// Game Controllers: "&Game Controllers" (Static)
#define IDH_117_1101	72155253	// -: "&Port Driver:" (Static)
#define IDH_117_8198	537264245	// -: "Cha&nge..." (Button)
#define IDH_119_1039	68092023	// Add Game Controller: "&Add Other..." (Button)
#define IDH_119_1049	68092025	// Add Game Controller: "&Custom..." (Button)
#define IDH_119_1059	69402743	// Add Game Controller: "&Controllers:" (Static)
#define IDH_4099_1043	68358147	// Custom Game Controller: "&Axes" (Button)
#define IDH_4201_12290	805507175	// Settings: "Reset to &default" (Button)
#define IDH_4201_12291	805507177	// Settings: "&Calibrate..." (Button)

// multimedia\directx\gamectrl\default\button.cpp
#define TEXT_COLOUR  RGB(202,202,202)

// multimedia\directx\gamectrl\default\calocal.h
#define ACTIVE_COLOR	RGB( 255, 0, 0 )
#define INACTIVE_COLOR	RGB( 128, 0, 0 )

// multimedia\directx\gamectrl\default\joyhelp.h
#define IDH_4101_12328	807931909	// Joystick Calibration: "Capture &POV" (Button)
#define IDH_4101_12329	807997445	// Joystick Calibration: "< &Back" (Button)
#define IDH_4201_12291	805507177	// Settings: "&Calibrate..." (Button)
#define IDH_4202_12328	807932010	// Game Controller Calibration: "Set &POV" (Button)
#define IDH_4202_12329	807997546	// Game Controller Calibration: "<&Back" (Button)
#define IDH_4201_12290	805507175	// Settings: "Reset to &default" (Button)

// multimedia\directx\gamectrl\default\pov.h
#define        CIRCLECOLOR                RGB(96, 96, 96)
#define 	   POV1_COLOUR	RGB(255,0,0)
#define 	   POV2_COLOUR	RGB(0,0,255)
#define 	   POV3_COLOUR	RGB(0,0,0)
#define 	   POV4_COLOUR	RGB(0,255,0)

// multimedia\directx\gamectrl\default\test.cpp
#define ACTIVE_COLOR       RGB(255,0,0)
#define INACTIVE_COLOR     RGB(128,0,0)

// multimedia\directx\gamectrl\gcdef\joycpl.h
#define ACTIVE_COLOR	RGB( 255, 0, 0 )
#define INACTIVE_COLOR	RGB( 128, 0, 0 )

// multimedia\directx\gamectrl\gcdef\joyhelp.h
#define IDH_4101_12328	807931909	// Joystick Calibration: "Capture &POV" (Button)
#define IDH_4101_12329	807997445	// Joystick Calibration: "< &Back" (Button)
#define IDH_4201_12291	805507177	// Settings: "&Calibrate..." (Button)
#define IDH_4202_12328	807932010	// Game Controller Calibration: "Set &POV" (Button)
#define IDH_4202_12329	807997546	// Game Controller Calibration: "<&Back" (Button)

// multimedia\directx\gamectrl\gcdef\pov.h
#define        CIRCLECOLOR                RGB(96, 96, 96)

// multimedia\dshow\filters.ks\tests\tstshell\toolbar.c
    #define RGBQ(dw) RGB(GetBValue(dw),GetGValue(dw),GetRValue(dw))

// multimedia\dshow\filters.ks\tests\wavetest\exe\appport.h
    #define GET_WM_CTLCOLOR_HDC(wp, lp, msg)        (HDC)(wp)

// multimedia\dshow\filters\avi\mjpeg\pmjpeg32\tools16_inc\compddk.h
#define ICM_DECOMPRESS_SET_PALETTE  (ICM_USER+29)   // fill in the DIB color table
#define ICM_DECOMPRESS_GET_PALETTE  (ICM_USER+30)   // fill in the DIB color table
#define ICM_DRAW_GET_PALETTE        (ICM_USER+16)   // get the palette needed for drawing
#define ICM_DRAW_CHANGEPALETTE      (ICM_USER+51)   // for animating palette

// multimedia\dshow\filters\avi\mjpeg\pmjpeg32\tools16_inc\msvideo.h
#define DVM_PALETTE			(DVM_CONFIGURE_START + 1)
#define DVM_PALETTERGB555		(DVM_CONFIGURE_START + 3)

// multimedia\dshow\filters\image2\inc\ddva.h
#define IVideoAccelerator_Release(p)                 (p)->lpVtbl->Release(p)

// multimedia\dshow\filters\image2\rndlessplayer\mpgcodec.h
#define MM_CLIPPED      0x20000000L     // Clipped version (RGB8 only at present)
#define MM_RGB24_DIB    0x00010000L     // RGB 8:8:8 DIB   (Not Supported)
#define MM_RGB24_DDB    0x00020000L     // RGB 8:8:8 DDB   (Not Supported)
#define MM_RGB32_DIB    0x00040000L     // RGB a:8:8:8 DIB   (Not Supported)
#define MM_RGB32_DDB    0x00080000L     // RGB a:8:8:8 DDB   (Not Supported)

// multimedia\dshow\filters\image2\vmrplyer\commands.cpp
#define DibSize(lpbi)           ((lpbi)->biSize + (lpbi)->biSizeImage + (int)(lpbi)->biClrUsed * sizeof(RGBQUAD))
#define DibPaletteSize(lpbi)    (DibNumColors(lpbi) * sizeof(RGBQUAD))

// multimedia\dshow\filters\image\colour\rgb24.cpp
#define DITH24(x,y,r,g,b)                    \
    (g_DitherMap[0][((x)&3)][((y)&3)][r] +   \
     g_DitherMap[1][((x)&3)][((y)&3)][g] +   \
     g_DitherMap[2][((x)&3)][((y)&3)][b])

// multimedia\dshow\filters\image\colour\rgb8.h
#define ADJUST(Colour,Adjust)                      \
    if (Colour & Adjust) {                         \
        Colour = min(255,(Colour + Adjust));       \
    }

// multimedia\dshow\filters\image\vidprop\vidprop.h
#define DD_YUVOVR               104     // NON RGB (eg YUV) overlays
#define DD_YUVOFF               106     // NON RGB (eg YUV) offscreen

// multimedia\dshow\filters\mixer\ovmixer\ovmixer.h
#define SOURCE_COLOR_REF                    (RGB(0, 128, 128))          // A shade of green, color used for source-colorkeying to force the card to use pixel-doubling instead of arithmatic stretching
#define DEFAULT_DEST_COLOR_KEY_RGB          (RGB(255, 0, 255))          // magenta

// multimedia\dshow\mfvideo\mswebdvd\ddrawobj.h
#define DibSize(lpbi)           ((lpbi)->biSize + (lpbi)->biSizeImage + (int)(lpbi)->biClrUsed * sizeof(RGBQUAD))
#define DibPaletteSize(lpbi)    (DibNumColors(lpbi) * sizeof(RGBQUAD))

// multimedia\dshow\mfvideo\mswebdvd\imaging.h
#define IMGERR_NOPALETTE        MAKE_IMGERR(2)

// multimedia\dshow\tools\vcdplyer\mpgcodec.h
#define MM_CLIPPED      0x20000000L     // Clipped version (RGB8 only at present)
#define MM_RGB24_DIB    0x00010000L     // RGB 8:8:8 DIB   (Not Supported)
#define MM_RGB24_DDB    0x00020000L     // RGB 8:8:8 DDB   (Not Supported)
#define MM_RGB32_DIB    0x00040000L     // RGB a:8:8:8 DIB   (Not Supported)
#define MM_RGB32_DDB    0x00080000L     // RGB a:8:8:8 DDB   (Not Supported)

// multimedia\media\avi\avicap.16\dibmap.c
#define Check_Axis(l,color)                                     \
        m = 0;                                                  \
        for (l = box->l##min; l <= box->l##max; (l)++) {        \
                m += l * proj_##l[l];                           \
        }                                                       \
        mean = ((double) m) / ((double) w);                     \
                                                                \
        w1 = 0;                                                 \
        m1 = 0;                                                 \
        for (l = box->l##min; l <= box->l##max; l++) {          \
                w1 += proj_##l[l];                              \
                if (w1 == 0)                                    \
                        continue;                               \
                if (w1 == w)                                    \
                        break;                                  \
                m1 += l * proj_##l[l];                          \
                temp1 = mean - (((double) m1) / ((double) w1)); \
                temp2 = (((double) w1) / ((double) (w-w1))) * temp1 * temp1; \
                if (temp2 > currentMax) {                       \
                        bestCut = l;                            \
                        bestAxis = color;                       \
                        currentMax = temp2;                     \
                }                                               \
        }
#define AddAxisVariance(c)                                              \
        sxx = 0; sx2 = 0;                                               \
        for (c = box->c##min; c <= box->c##max; c++) {                  \
                sxx += proj_##c[c] * c * c;                             \
                sx2 += proj_##c[c] * c;                                 \
        }                                                               \
        quotient = sx2 / n; /* This stuff avoids overflow */            \
        remainder = sx2 % n;                                            \
        var += sxx - quotient * sx2 - ((remainder * sx2)/n);

// multimedia\media\avi\avicap.16\iaverage.c
#define Pel24(p,x)  (((RGB24 _huge *)(p))[(x)])

// multimedia\media\avi\avicap.16\msvideo.h
#define DVM_PALETTE			(DVM_CONFIGURE_START + 1)
#define DVM_PALETTERGB555		(DVM_CONFIGURE_START + 3)

// multimedia\media\avi\avicap.io\capdib.c
#define  RESERVE_FOR_RIFF  (512+sizeof(RIFF))

// multimedia\media\avi\avicap.io\dibmap.c
#define IncHistogram(w) if (lpHistogram[(UINT)(w)] < 0xFFFFFFFF) {  \
			    lpHistogram[(UINT)(w)]++;\
			}
#define AddAxisVariance(c)                                              \
        sxx = 0; sx2 = 0;                                               \
        for (c = box->c##min; c <= box->c##max; c++) {                  \
                sxx += proj_##c[c] * c * c;                             \
                sx2 += proj_##c[c] * c;                                 \
        }                                                               \
        quotient = sx2 / n; /* This stuff avoids overflow */            \
        remainder = sx2 % n;                                            \
        var += sxx - quotient * sx2 - ((remainder * sx2)/n);

// multimedia\media\avi\avicap.io\iaverage.c
#define Pel24(p,x)  (((RGB24 HUGE *)(p))[(x)])

// multimedia\media\avi\avicap\capdib.c
#define  RESERVE_FOR_RIFF  (512+sizeof(RIFF))

// multimedia\media\avi\avicap\dibmap.c
#define Check_Axis(l,color)                                     \
        m = 0;                                                  \
        for (l = box->l##min; l <= box->l##max; (l)++) {        \
                m += l * proj_##l[l];                           \
        }                                                       \
        mean = ((double) m) / ((double) w);                     \
                                                                \
        w1 = 0;                                                 \
        m1 = 0;                                                 \
        for (l = box->l##min; l <= box->l##max; l++) {          \
                w1 += proj_##l[l];                              \
                if (w1 == 0)                                    \
                        continue;                               \
                if (w1 == w)                                    \
                        break;                                  \
                m1 += l * proj_##l[l];                          \
                temp1 = mean - (((double) m1) / ((double) w1)); \
                temp2 = (((double) w1) / ((double) (w-w1))) * temp1 * temp1; \
                if (temp2 > currentMax) {                       \
                        bestCut = l;                            \
                        bestAxis = color;                       \
                        currentMax = temp2;                     \
                }                                               \
        }
#define AddAxisVariance(c)                                              \
        sxx = 0; sx2 = 0;                                               \
        for (c = box->c##min; c <= box->c##max; c++) {                  \
                sxx += proj_##c[c] * c * c;                             \
                sx2 += proj_##c[c] * c;                                 \
        }                                                               \
        quotient = sx2 / n; /* This stuff avoids overflow */            \
        remainder = sx2 % n;                                            \
        var += sxx - quotient * sx2 - ((remainder * sx2)/n);

// multimedia\media\avi\avicap\iaverage.c
#define Pel24(p,x)  (((RGB24 HUGE *)(p))[(x)])

// multimedia\media\avi\avifile.16\avifile.h
#define comptypeDIB         mmioFOURCC('D', 'I', 'B', ' ')

// multimedia\media\avi\avifile.16\riffdisp.c
#define DibSize(lpbi) \
    (lpbi->biSize + ((int)lpbi->biClrUsed * sizeof(RGBQUAD)) + lpbi->biSizeImage)

// multimedia\media\avi\avifile\avifile.h
#define comptypeDIB         mmioFOURCC('D', 'I', 'B', ' ')

// multimedia\media\avi\avifile\aviplay\aviball.c
#define DEFAULT_COLOR   RGB(255,0,0)

// multimedia\media\avi\avifile\aviplay\aviplay.c
#define FillR(hdc, x, y, dx, dy, rgb) \
    SetBkColor(hdc, rgb);             \
    SetRect(&rc, x, y, x+dx, y+dy);   \
    ExtTextOut(hdc, 0, 0, ETO_OPAQUE, &rc, NULL, 0, NULL);

// multimedia\media\avi\avifile\aviplay\aviview.c
#define LEFTBRUSH  (RGB(0,0,255))			// left channel
#define RIGHTBRUSH (RGB(0,255,0))			// right channel
#define HPOSBRUSH  (RGB(255,0,0))			// current position

// multimedia\media\avi\avifile\aviview\aviball.c
#define DEFAULT_COLOR   RGB(255,0,0)

// multimedia\media\avi\avifile\aviview\aviview.c
#define BACKBRUSH  (RGB(0, 0, 0))
#define MONOBRUSH  (RGB(0,255,0))
#define LEFTBRUSH  (RGB(0,0,255))
#define RIGHTBRUSH (RGB(0,255,0))
#define HPOSBRUSH  (RGB(255,0,0))
#define LEFTBRUSH  (RGB(0,0,255))
#define RIGHTBRUSH (RGB(0,255,0))
#define HPOSBRUSH  (RGB(255,0,0))

// multimedia\media\avi\avifile\aviview\cdib.c
#define MapVGA(r,g,b) (((r&~3) == (g&~3) && (g&~3) == (b&~3)) ?        \
        ((r < 64) ? 0 : (r <= 128) ? 8 : (r <= 192) ? 7 : 15) :        \
        (((r>192) || (g>192) || (b>192)) ?                             \
           (((r>191) ? 1:0) | ((g>191) ? 2:0) | ((b>191) ? 4:0) | 8) : \
           (((r>64) ? 1:0) | ((g>64) ? 2:0) | ((b>64) ? 4:0))) )
#define Pel24(p,x)  (((RGB24 FAR *)(p))[(x)])

// multimedia\media\avi\avifile\aviview\dibmap.c
#define Check_Axis(l,color)                                     \
        m = 0;                                                  \
        for (l = box->l##min; l <= box->l##max; (l)++) {        \
                m += l * proj_##l[l];                           \
        }                                                       \
        mean = ((double) m) / ((double) w);                     \
                                                                \
        w1 = 0;                                                 \
        m1 = 0;                                                 \
        for (l = box->l##min; l <= box->l##max; l++) {          \
                w1 += proj_##l[l];                              \
                if (w1 == 0)                                    \
                        continue;                               \
                if (w1 == w)                                    \
                        break;                                  \
                m1 += l * proj_##l[l];                          \
                temp1 = mean - (((double) m1) / ((double) w1)); \
                temp2 = (((double) w1) / ((double) (w-w1))) * temp1 * temp1; \
                if (temp2 > currentMax) {                       \
                        bestCut = l;                            \
                        bestAxis = color;                       \
                        currentMax = temp2;                     \
                }                                               \
        }
#define AddAxisVariance(c)                                              \
        sxx = 0; sx2 = 0;                                               \
        for (c = box->c##min; c <= box->c##max; c++) {                  \
                sxx += proj_##c[c] * c * c;                             \
                sx2 += proj_##c[c] * c;                                 \
        }                                                               \
        quotient = sx2 / n; /* This stuff avoids overflow */            \
        remainder = sx2 % n;                                            \
        var += sxx - quotient * sx2 - ((remainder * sx2)/n);

// multimedia\media\avi\avifile\riffdisp.c
#define DibSize(lpbi) \
    (lpbi->biSize + ((int)lpbi->biClrUsed * sizeof(RGBQUAD)) + lpbi->biSizeImage)

// multimedia\media\avi\compman.16\compddk.h
#define ICM_DECOMPRESS_SET_PALETTE  (ICM_USER+29)   // fill in the DIB color table
#define ICM_DECOMPRESS_GET_PALETTE  (ICM_USER+30)   // fill in the DIB color table
#define ICM_DRAW_GET_PALETTE        (ICM_USER+16)   // get the palette needed for drawing
#define ICM_DRAW_CHANGEPALETTE      (ICM_USER+51)   // for animating palette

// multimedia\media\avi\compman.16\icm.c
#define DibSize(lpbi)           ((lpbi)->biSize + (lpbi)->biSizeImage + (int)(lpbi)->biClrUsed * sizeof(RGBQUAD))

// multimedia\media\avi\compman.16\vidthunk.h
#define ThunkHPAL(h16) ((HPALETTE)lpWOWHandle32(WOW_TYPE_HPALETTE, h16))

// multimedia\media\avi\compman\compddk.h
#define ICM_DECOMPRESS_SET_PALETTE  (ICM_USER+29)   // fill in the DIB color table
#define ICM_DECOMPRESS_GET_PALETTE  (ICM_USER+30)   // fill in the DIB color table
#define ICM_DRAW_GET_PALETTE        (ICM_USER+16)   // get the palette needed for drawing
#define ICM_DRAW_CHANGEPALETTE      (ICM_USER+51)   // for animating palette

// multimedia\media\avi\compman\icm.c
#define DibSize(lpbi)           ((lpbi)->biSize + (lpbi)->biSizeImage + (int)(lpbi)->biClrUsed * sizeof(RGBQUAD))

// multimedia\media\avi\compman\thunk.h
#define ThunkHPAL(h16) ((HPALETTE)h16)

// multimedia\media\avi\drawdib.16\dcilib\dciddi.h
#define DCI_CAN_STRETCHXY           		(DCI_CAN_STRETCHX | DCI_CAN_STRETCHY)
#define DCI_CAN_STRETCHXYN          		(DCI_CAN_STRETCHXN | DCI_CAN_STRETCHYN)

// multimedia\media\avi\drawdib.16\dcilib\dva.c
#define GetDS() SELECTOROF((LPVOID)&ScreenSel)

// multimedia\media\avi\drawdib.16\ddt\ddt.c
#define SUCK(bpp,n) \
    displayFPS[bpp/8][n][0]/10, displayFPS[bpp/8][n][0]%10, \
    displayFPS[bpp/8][n][1]/10, displayFPS[bpp/8][n][1]%10, \
    (LPSTR)(displayFPS[bpp/8][n][0] < displayFPS[bpp/8][n][1] ? "** POOR **" : "")

// multimedia\media\avi\drawdib.16\dith666.h
#define DITH256(x,y,r,g,b) aTranslate666[           \
        1  * (r/51 + (r%51 > aHalftone4x4[x][y])) + \
        6  * (g/51 + (g%51 > aHalftone4x4[x][y])) + \
        36 * (b/51 + (b%51 > aHalftone4x4[x][y]))]
#define DITH8(x,y,r,g,b) aTranslate666[   \
        aHalftone8[0][(x)&3][(y)&3][(r)] +\
        aHalftone8[1][(x)&3][(y)&3][(g)] +\
        aHalftone8[2][(x)&3][(y)&3][(b)] ]
#define DITH31(x,y,r,g,b) aTranslate666[                      \
        1  * (d62(r) + (m62(r) > (UINT)aHalftone2x2[x][y])) + \
        6  * (d62(g) + (m62(g) > (UINT)aHalftone2x2[x][y])) + \
        36 * (d62(b) + (m62(b) > (UINT)aHalftone2x2[x][y]))]

// multimedia\media\avi\drawdib.16\dva\dva.c
#define GetDS() SELECTOROF((LPVOID)&ScreenSel)

// multimedia\media\avi\drawdib\dith666.h
#define DITH256(x,y,r,g,b) aTranslate666[           \
        1  * (r/51 + (r%51 > aHalftone4x4[x][y])) + \
        6  * (g/51 + (g%51 > aHalftone4x4[x][y])) + \
        36 * (b/51 + (b%51 > aHalftone4x4[x][y]))]
#define DITH8(x,y,r,g,b) aTranslate666[   \
        aHalftone8[0][(x)&3][(y)&3][(r)] +\
        aHalftone8[1][(x)&3][(y)&3][(g)] +\
        aHalftone8[2][(x)&3][(y)&3][(b)] ]
#define DITH31(x,y,r,g,b) aTranslate666[                      \
        1  * (d62(r) + (m62(r) > (UINT)aHalftone2x2[x][y])) + \
        6  * (d62(g) + (m62(g) > (UINT)aHalftone2x2[x][y])) + \
        36 * (d62(b) + (m62(b) > (UINT)aHalftone2x2[x][y]))]

// multimedia\media\avi\drawdib\drawdib.c
#define GetDS() SELECTOROF((LPVOID)&ScreenSel)

// multimedia\media\avi\drawdib\dva\dva.c
#define GetDS() SELECTOROF((LPVOID)&ScreenSel)

// multimedia\media\avi\inc.16\avifile.h
#define comptypeDIB         mmioFOURCC('D', 'I', 'B', ' ')

// multimedia\media\avi\inc.16\avifmt.h
#define cktypeDIBcompressed     aviTWOCC('d', 'c')

// multimedia\media\avi\inc.16\compddk.h
#define ICM_DECOMPRESS_SET_PALETTE  (ICM_USER+29)   // fill in the DIB color table
#define ICM_DECOMPRESS_GET_PALETTE  (ICM_USER+30)   // fill in the DIB color table
#define ICM_DRAW_GET_PALETTE        (ICM_USER+16)   // get the palette needed for drawing
#define ICM_DRAW_CHANGEPALETTE      (ICM_USER+51)   // for animating palette

// multimedia\media\avi\inc.16\dispdib.h
#define DisplayDibBegin() DisplayDib(NULL, NULL, DISPLAYDIB_BEGIN)
#define DisplayDibEnd()   DisplayDib(NULL, NULL, DISPLAYDIB_END)

// multimedia\media\avi\inc.16\mciwnd.h
#define MCIWNDM_GETPALETTE      (WM_USER + 126)
#define MCIWNDM_SETPALETTE      (WM_USER + 127)
#define MCIWNDM_PALETTEKICK     (WM_USER + 150)

// multimedia\media\avi\inc.16\mmreg.h
#define JPEG_DIB        mmioFOURCC('J','P','E','G')    /* Still image JPEG DIB biCompression */
#define MJPG_DIB        mmioFOURCC('M','J','P','G')    /* Motion JPEG DIB biCompression     */

// multimedia\media\avi\inc.16\mmsystem.h
#define DIBINDEX(n)     MAKELONG((n),0x10FF)

// multimedia\media\avi\inc.16\msvideo.h
#define DVM_PALETTE			(DVM_CONFIGURE_START + 1)
#define DVM_PALETTERGB555		(DVM_CONFIGURE_START + 3)

// multimedia\media\avi\inc.16\penwin.h
#define IESF_PENTIP				(IESF_TIPCOLOR|IESF_TIPWIDTH)
#define IE_GETPALETTE 		(IE_MSGFIRST+26)	// gets the palette
#define IE_SETPALETTE 		(IE_MSGFIRST+27)	// gets the palette

// multimedia\media\avi\inc.16\pwin16.h
#define GET_WM_CTLCOLOR_HDC(wp, lp, msg)            (HDC)(wp)

// multimedia\media\avi\inc.16\win32.h
    #define GET_WM_CTLCOLOR_HDC(wp, lp, msg)            (HDC)(wp)

// multimedia\media\avi\inc.16\windows.h
#define PALETTERGB(r,g,b)   (0x02000000L | RGB(r,g,b))

// multimedia\media\avi\inc.16\windowsx.h
#define GET_WM_CTLCOLOR_HDC(wp, lp, msg)        (HDC)(wp)
#define GET_WM_CTLCOLOR_MSG(type)               WM_CTLCOLOR

// multimedia\media\avi\inc\aviffmt.h
#define comptypeDIB             mmioFOURCC('D','I','B',' ')
#define cktypeDIBcompressed     aviTWOCC('d', 'c')
#define cktypeDIBhalf           aviTWOCC('d', 'x')
#define cktypeDIBheader         aviTWOCC('d', 'h')

// multimedia\media\avi\inc\avifmt.h
#define cktypeDIBcompressed     aviTWOCC('d', 'c')

// multimedia\media\avi\inc\dispdib.h
#define DisplayDibBegin() DisplayDib(NULL, NULL, DISPLAYDIB_BEGIN)
#define DisplayDibEnd()   DisplayDib(NULL, NULL, DISPLAYDIB_END)

// multimedia\media\avi\inc\meddibs.h
#define medtypeDIBSEQ	medFOURCC('D','S','E','Q')	// DIB sequence
#define medtypeAVID	medFOURCC('A','V','I',' ')	// AVI DIBS
#define medtypeAVIMDIB	medFOURCC('M','D','B','A')	// AVI MDIB
#define DIBS_GETINFO		(MED_USER)
#define DIBS_GETSTREAMTYPE	(MED_USER+1)
#define DIBS_STREAM_VIDEO		medFOURCC('v', 'i', 'd', 's')
#define DIBS_STREAM_AUDIO		medFOURCC('a', 'u', 'd', 's')
#define DIBS_STREAM_MIDI 		medFOURCC('m', 'i', 'd', 's')
#define DIBS_STREAM_TEXT 		medFOURCC('t', 'x', 't', 's')
#define DIBS_GETSTREAMFORMAT	(MED_USER+2)
#define DIBS_GETSTREAMHANDLER	(MED_USER+3)
#define DIBS_GETHANDLERDATA	(MED_USER+4)
#define DIBS_GETFRAMEDATA	(MED_USER+5)
#define DIBS_GETKEYFRAMEINFO	(MED_USER+7)
#define DIBS_GETFILESIZE	(MED_USER+8)
#define DIBS_GETFRAMESIZE	(MED_USER+9)
#define DIBS_GETRAWDATA		(MED_USER+10)

// multimedia\media\avi\inc\oldavift.h
#define ckidDIBheader   	mmioFOURCC('d', 'i', 'b', 'h')
#define ckidDIBcompressed	mmioFOURCC('d', 'i', 'b', 'c')
#define ckidDIBhalfframe	mmioFOURCC('d', 'i', 'b', 'x')
#define comptypeDIB		mmioFOURCC('D','I','B',' ')

// multimedia\media\avi\mciavi.16\aviffmt.h
#define comptypeDIB             mmioFOURCC('D','I','B',' ')
#define cktypeDIBcompressed     aviTWOCC('d', 'c')
#define cktypeDIBhalf           aviTWOCC('d', 'x')
#define cktypeDIBheader         aviTWOCC('d', 'h')

// multimedia\media\avi\mciavi32\aviffmt.h
#define comptypeDIB             mmioFOURCC('D','I','B',' ')
#define cktypeDIBcompressed     aviTWOCC('d', 'c')
#define cktypeDIBhalf           aviTWOCC('d', 'x')
#define cktypeDIBheader         aviTWOCC('d', 'h')

// multimedia\media\avi\mciwnd.16\bmpload.c
#define RGB_BUTTONTEXT      (RGB(000,000,000))  // black
#define RGB_BUTTONSHADOW    (RGB(128,128,128))  // dark grey
#define RGB_BUTTONFACE      (RGB(192,192,192))  // bright grey
#define RGB_BUTTONHILIGHT   (RGB(255,255,255))  // white
#define FlipColor(rgb)      (RGB(GetBValue(rgb), GetGValue(rgb), GetRValue(rgb)))

// multimedia\media\avi\mciwnd.16\mciwnd.h
#define MCIWNDM_GETPALETTE      (WM_USER + 126)
#define MCIWNDM_SETPALETTE      (WM_USER + 127)
#define MCIWNDM_PALETTEKICK     (WM_USER + 150)

// multimedia\media\avi\mciwnd.16\preview.c
#define DibSize(lpbi) \
    (lpbi->biSize + ((int)lpbi->biClrUsed * sizeof(RGBQUAD)) + lpbi->biSizeImage)

// multimedia\media\avi\mciwnd\bmpload.c
#define RGB_BUTTONTEXT      (RGB(000,000,000))  // black
#define RGB_BUTTONSHADOW    (RGB(128,128,128))  // dark grey
#define RGB_BUTTONFACE      (RGB(192,192,192))  // bright grey
#define RGB_BUTTONHILIGHT   (RGB(255,255,255))  // white
#define FlipColor(rgb)      (RGB(GetBValue(rgb), GetGValue(rgb), GetRValue(rgb)))

// multimedia\media\avi\mciwnd\mciwnd.h
#define MCIWNDM_GETPALETTE      (WM_USER + 126)
#define MCIWNDM_SETPALETTE      (WM_USER + 127)
#define MCIWNDM_PALETTEKICK     (WM_USER + 150)

// multimedia\media\avi\msrle\msrle.c
#define FOURCC_DIB      mmioFOURCC('D','I','B',' ')
#define TWOCC_DIB       aviTWOCC('d','b')
#define TWOCC_DIBX      aviTWOCC('d','x')

// multimedia\media\avi\msrle\msrle.h
#define DibSize(lpbi)           ((lpbi)->biSize + (lpbi)->biSizeImage + (int)(lpbi)->biClrUsed * sizeof(RGBQUAD))
#define DibPaletteSize(lpbi)    (DibNumColors(lpbi) * sizeof(RGBQUAD))

// multimedia\media\avi\msvidc\compress.c
#define RGBQ16(rgb)    RGB16((rgb).rgbRed,(rgb).rgbGreen,(rgb).rgbBlue)
#define MAPRGB16(rgb16) lpITable[(rgb16)]
#define MAPRGB(rgb)     lpITable[RGBQ16(rgb)]

// multimedia\media\avi\msvidc\invcmap.c
#define maxfill(pbuffer, side)  \
    memset(pbuffer, -1, colormax*colormax*colormax*sizeof(LONG))

// multimedia\media\avi\msvideo.16\msvideo.h
#define DVM_PALETTE			(DVM_CONFIGURE_START + 1)
#define DVM_PALETTERGB555		(DVM_CONFIGURE_START + 3)

// multimedia\media\avi\msvideo.16\vidthunk.h
#define ThunkHPAL(h16) ((HPALETTE)lpWOWHandle32(WOW_TYPE_HPALETTE, h16))

// multimedia\media\avi\vidcap32\toolbar.c
    #define RGBQ(dw) RGB(GetBValue(dw),GetGValue(dw),GetRValue(dw))

// multimedia\media\avi\video\ivideo32.h
#define DVM_PALETTE			(DVM_CONFIGURE_START + 1)
#define DVM_PALETTERGB555		(DVM_CONFIGURE_START + 3)

// multimedia\media\avi\video\msvideo.h
#define DVM_PALETTE			(DVM_CONFIGURE_START + 1)
#define DVM_PALETTERGB555		(DVM_CONFIGURE_START + 3)

// multimedia\media\avi\video\vidthunk.h
#define ThunkHPAL(h16) ((HPALETTE)lpWOWHandle32(h16, WOW_TYPE_HPALETTE))

// multimedia\media\deluxe2\main\mbutton.cpp
#define MBUTTON_TEXT_COLOR RGB(0xFF,0xFF,0xFF)

// multimedia\media\deluxecd\main\mbutton.cpp
#define MBUTTON_TEXT_COLOR RGB(0xFF,0xFF,0xFF)

// multimedia\media\dplayx\dplay\dplay\dplay.h
#define IDirectPlay2_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlay3_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlayX_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlay_Release(p)                      (p)->lpVtbl->Release(p)

// multimedia\media\inc\win32.h
    #define GET_WM_CTLCOLOR_HDC(wp, lp, msg)            (HDC)(wp)

// multimedia\media\mcivisca\mcivisca\appport.h
    #define GET_WM_CTLCOLOR_HDC(wp, lp, msg)        (HDC)(wp)

// multimedia\media\mixerapp\vu.h
#define VU_SETCOLORLIST         (WM_USER + 1)
#define VU_GETCOLORLIST         (WM_USER + 2)

// multimedia\media\mmcaps2k\appport.h
    #define GET_WM_CTLCOLOR_HDC(wp, lp, msg)        (HDC)(wp)

// multimedia\media\msacm\msacm\acmi.h
    #define GET_WM_CTLCOLOR_HDC(wp, lp, msg)        (HDC)(wp)

// multimedia\media\msacm\msacmmap\msacmmap.h
    #define GET_WM_CTLCOLOR_HDC(wp, lp, msg)        (HDC)(wp)

// multimedia\media\msacm\msfilter\codec.c
#define ABOUT_HILIGHTCOLOR                      RGB(0,255,255)

// multimedia\media\samples\acmapp\appport.h
    #define GET_WM_CTLCOLOR_HDC(wp, lp, msg)        (HDC)(wp)

// multimedia\media\samples\mmcapsex\appport.h
    #define GET_WM_CTLCOLOR_HDC(wp, lp, msg)        (HDC)(wp)

// multimedia\media\sndrec32\soundrec\soundrec.h
#define RGB_DARKSHADOW      GetSysColor(COLOR_BTNSHADOW)     // dark 3-D shadow
#define RGB_LIGHTSHADOW     GetSysColor(COLOR_BTNHIGHLIGHT)  // light 3-D shadow

// multimedia\media\winmm\mmwow32.h
#define HPALETTE32(hobj16)         ((HPALETTE)(*lpWOWHandle32)( hobj16, WOW_TYPE_HPALETTE ))
#define GETHPALETTE16(hobj32)      ((*lpWOWHandle16)( hobj32, WOW_TYPE_HPALETTE ))

// multimedia\opengl\client\eval.c
#define COPYMESHCOLOR(m,c)                                          \
{                                                                   \
    (m)->color.r = (c)[0];                                          \
    (m)->color.g = (c)[1];                                          \
    (m)->color.b = (c)[2];                                          \
    (m)->color.a = (c)[3];                                          \
}

// multimedia\opengl\dlist\dl_opt.c
#define VTYPE_C4F	      (POLYDATA_COLOR_VALID | POLYDATA_DLIST_COLOR_4)

// multimedia\opengl\dlist\dl_pdata.h
#define __PDATA_SIZE_C4F         (sizeof(__GLcolor))

// multimedia\opengl\inc\compsize.h
#define __glGetPixelMapfv_size(map)                             \
        (__glGetPixelMap_size(map)*sizeof(GLfloat))
#define __glGetPixelMapuiv_size(map)                            \
        (__glGetPixelMap_size(map)*sizeof(GLuint))
#define __glGetPixelMapusv_size(map)                            \
        (__glGetPixelMap_size(map)*sizeof(GLushort))

// multimedia\opengl\scrsave\3dfo\ss3dfo.c
#define OPT_STD             ( OPT_COLOR_CYCLE | OPT_SMOOTH_SHADE | OPT_TESSEL | OPT_SIZE )

// multimedia\opengl\scrsave\common\palette.cxx
#define BLACK   PALETTERGB(0,0,0)
#define WHITE   PALETTERGB(255,255,255)

// multimedia\opengl\server\generic\genaline.c
#define CHECK_PIXEL(gc, cfb, w, x, y)
#define WRITE_PIX(pPix) \
    pPix[0] = ((__GLGENcontext *)gc)->xlatPalette[r | g | b]
#define WRITE_PIX(pPix) \
    pPix[0] = ((__GLGENcontext *)gc)->xlatPalette[r | g | b]
#define WRITE_PIX(pPix) \
    pPix[0] = ((__GLGENcontext *)gc)->xlatPalette[r | g | b]

// multimedia\opengl\server\generic\genrgb.c
#define DitheredColorToBuffer(col, incr, cfb, dest, type) \
    if( ALPHA_PIXEL_WRITE( cfb ) ) \
        DitheredRGBAColorToBuffer(col, incr, cfb, dest, type); \
    else \
        DitheredRGBColorToBuffer(col, incr, cfb, dest, type);
#define UnditheredColorToBuffer(col, cfb, dest, type) \
    if( ALPHA_PIXEL_WRITE( cfb ) ) \
        UnditheredRGBAColorToBuffer(col, cfb, dest, type); \
    else \
        UnditheredRGBColorToBuffer(col, cfb, dest, type);
#define ACCUM_CLAMP_COLOR_COMPONENT( col, max ) \
    if ((col) < (__GLfloat) 0.0) \
        (col) = (__GLfloat) 0.0; \
    else if ((col) > max ) \
        (col) = max;

// multimedia\opengl\server\generic\pixelfmt.c
#define PALETTE_WATCHER_CLASS __TEXT("Palette Watcher")
#define EnterPixelFormatSection() \
    (EnterCriticalSection(&gcsPixelFormat), TRUE)
#define LeavePixelFormatSection() \
    LeaveCriticalSection(&gcsPixelFormat)

// multimedia\opengl\server\generic\wglsup.c
#define REALIZEPALETTE(hdc) RealizePalette((hdc))
#define REALIZEPALETTE(hdc)

// multimedia\opengl\server\inc\context.h
#define __GL_COLOR_CHECK_CLAMP_RGB(gc, r, g, b)                              \
    ((CASTINT(r) | ((ULONG)(CASTINT(gc->redVertexScale) - CASTINT(r))) |     \
      CASTINT(g) | ((ULONG)(CASTINT(gc->greenVertexScale) - CASTINT(g))) |   \
      CASTINT(b) | ((ULONG)(CASTINT(gc->blueVertexScale) - CASTINT(b)))) &   \
     0x80000000)
#define __GL_CLAMP_R(target, gc, r)                                         \
{                                                                           \
    (gc)->redClampTable[0] = (r);                                           \
    target = (gc)->redClampTable[__GL_COLOR_CLAMP_INDEX_R((gc)->redClampTable[0])]; \
}
#define __GL_CLAMP_G(target, gc, g)                                         \
{                                                                           \
    (gc)->greenClampTable[0] = (g);                                         \
    target = (gc)->greenClampTable[__GL_COLOR_CLAMP_INDEX_G((gc)->greenClampTable[0])]; \
}
#define __GL_CLAMP_B(target, gc, b)                                         \
{                                                                           \
    (gc)->blueClampTable[0] = (b);                                          \
    target = (gc)->blueClampTable[__GL_COLOR_CLAMP_INDEX_B((gc)->blueClampTable[0])]; \
}
#define __GL_CLAMP_A(target, gc, a)                                         \
{                                                                           \
    (gc)->alphaClampTable[0] = (a);                                         \
    target = (gc)->alphaClampTable[__GL_COLOR_CLAMP_INDEX_A((gc)->alphaClampTable[0])]; \
}
#define __GL_SCALE_RGB(rOut, gOut, bOut, gc, r, g, b)                   \
    __GL_SCALE_R(rOut, gc, r);                                    	\
    __GL_SCALE_G(gOut, gc, g);                                    	\
    __GL_SCALE_B(bOut, gc, b);
#define __GL_SCALE_RGBA(rOut, gOut, bOut, aOut, gc, r, g, b, a)         \
    __GL_SCALE_R(rOut, gc, r);                                    	\
    __GL_SCALE_G(gOut, gc, g);                                    	\
    __GL_SCALE_B(bOut, gc, b);                                    	\
    __GL_SCALE_A(aOut, gc, a);
#define __GL_CLAMP_RGB(rOut, gOut, bOut, gc, r, g, b)       		\
    __GL_CLAMP_R(rOut, gc, r);                                    	\
    __GL_CLAMP_G(gOut, gc, g);                                    	\
    __GL_CLAMP_B(bOut, gc, b);
#define __GL_CLAMP_RGBA(rOut, gOut, bOut, aOut, gc, r, g, b, a)         \
    __GL_CLAMP_R(rOut, gc, r);                                          \
    __GL_CLAMP_G(gOut, gc, g);                                    	\
    __GL_CLAMP_B(bOut, gc, b);                                    	\
    __GL_CLAMP_A(aOut, gc, a);
#define __GL_SCALE_RGB(rOut, gOut, bOut, gc, r, g, b)               \
{                                                                   \
    __GLfloat rScale, gScale, bScale;                               \
    __GLfloat rs, gs, bs;                                           \
                                                                    \
    rScale = (gc)->redVertexScale;                                  \
    gScale = (gc)->greenVertexScale;                                \
    bScale = (gc)->blueVertexScale;                                 \
                                                                    \
    rs = (r) * rScale;                                              \
    gs = (g) * gScale;                                              \
    bs = (b) * bScale;                                              \
                                                                    \
    rOut = rs;                                                      \
    gOut = gs;                                                      \
    bOut = bs;                                                      \
}
#define __GL_SCALE_RGBA(rOut, gOut, bOut, aOut, gc, r, g, b, a)     \
{                                                                   \
    __GLfloat rScale, gScale, bScale, aScale;                       \
    __GLfloat rs, gs, bs, as;                                       \
                                                                    \
    rScale = (gc)->redVertexScale;                                  \
    gScale = (gc)->greenVertexScale;                                \
    bScale = (gc)->blueVertexScale;                                 \
    aScale = (gc)->alphaVertexScale;                                \
                                                                    \
    rs = (r) * rScale;                                              \
    gs = (g) * gScale;                                              \
    bs = (b) * bScale;                                              \
    as = (a) * aScale;                                              \
                                                                    \
    rOut = rs;                                                      \
    gOut = gs;                                                      \
    bOut = bs;                                                      \
    aOut = as;                                                      \
}

// multimedia\opengl\server\inc\devlock.h
#define GENERIC_BACKBUFFER_ONLY(gc) \
      ( ((gc)->state.raster.drawBuffer == GL_BACK ) &&\
        ((gc)->state.pixel.readBuffer == GL_BACK ) )

// multimedia\opengl\server\inc\gencx.h
#define MEMORY_DC       0x0008          // set if DIB in memory (ie !display)

// multimedia\opengl\server\inc\listcomp.h
#define __glFogfv_size(pname)					\
    ((pname) == GL_FOG_COLOR					\
	? 4							\
	: (RANGE((pname),GL_FOG_INDEX,GL_FOG_MODE)		\
	    ? 1							\
	    : -1))
#define __glMaterialfv_size(pname)					\
    ((pname) == GL_SHININESS						\
	? 1								\
	: ((pname) == GL_COLOR_INDEXES					\
	    ? 3								\
	    : (((pname) == GL_AMBIENT ||				\
	        (pname) == GL_DIFFUSE ||				\
	        (pname) == GL_SPECULAR ||				\
	        (pname) == GL_EMISSION ||				\
	        (pname) == GL_AMBIENT_AND_DIFFUSE) 			\
		? 4							\
		: -1)))
#define __glTexParameterfv_size(pname)					\
    ((RANGE((pname),GL_TEXTURE_MAG_FILTER,GL_TEXTURE_WRAP_T) ||		\
      (pname) == GL_TEXTURE_PRIORITY)				        \
	? 1								\
	: ((pname) == GL_TEXTURE_BORDER_COLOR				\
	    ? 4								\
	    : -1))
#define __glTexEnvfv_size(pname)					\
    ((pname) == GL_TEXTURE_ENV_MODE					\
	? 1								\
	: ((pname) == GL_TEXTURE_ENV_COLOR				\
	    ? 4								\
	    : -1))

// multimedia\opengl\server\inc\pixel.h
#define __GL_N_PIXEL_MAPS       (GL_PIXEL_MAP_A_TO_A - GL_PIXEL_MAP_I_TO_I + 1)
#define __GL_REMAP_PM(x)        ((x) - GL_PIXEL_MAP_I_TO_I)
#define __GL_PIXEL_MAP_I_TO_I   __GL_REMAP_PM(GL_PIXEL_MAP_I_TO_I)
#define __GL_PIXEL_MAP_S_TO_S   __GL_REMAP_PM(GL_PIXEL_MAP_S_TO_S)
#define __GL_PIXEL_MAP_I_TO_R   __GL_REMAP_PM(GL_PIXEL_MAP_I_TO_R)
#define __GL_PIXEL_MAP_I_TO_G   __GL_REMAP_PM(GL_PIXEL_MAP_I_TO_G)
#define __GL_PIXEL_MAP_I_TO_B   __GL_REMAP_PM(GL_PIXEL_MAP_I_TO_B)
#define __GL_PIXEL_MAP_I_TO_A   __GL_REMAP_PM(GL_PIXEL_MAP_I_TO_A)
#define __GL_PIXEL_MAP_R_TO_R   __GL_REMAP_PM(GL_PIXEL_MAP_R_TO_R)
#define __GL_PIXEL_MAP_G_TO_G   __GL_REMAP_PM(GL_PIXEL_MAP_G_TO_G)
#define __GL_PIXEL_MAP_B_TO_B   __GL_REMAP_PM(GL_PIXEL_MAP_B_TO_B)
#define __GL_PIXEL_MAP_A_TO_A   __GL_REMAP_PM(GL_PIXEL_MAP_A_TO_A)
#define __GL_MAX_SPAN_SIZE	(__GL_MAX_MAX_VIEWPORT * 4 * sizeof(GLfloat))

// multimedia\opengl\server\inc\texspan.h
    #define TEX_PALETTE         GENACCEL(gengc).texImageReplace
    #define TEX_PALETTE     GENACCEL(gengc).texPalette

// multimedia\opengl\server\inc\vertex.h
#define __GL_HAS_BOTH		(__GL_HAS_FRONT_COLOR | __GL_HAS_BACK_COLOR)

// multimedia\opengl\server\soft\so_clip.c
#define __GL_CLIP_COLOR(d,a,b,t)				      \
    d->colors[__GL_FRONTFACE].r = t*(a->colors[__GL_FRONTFACE].r      \
        - b->colors[__GL_FRONTFACE].r) + b->colors[__GL_FRONTFACE].r; \
    d->colors[__GL_FRONTFACE].g = t*(a->colors[__GL_FRONTFACE].g      \
        - b->colors[__GL_FRONTFACE].g) + b->colors[__GL_FRONTFACE].g; \
    d->colors[__GL_FRONTFACE].b = t*(a->colors[__GL_FRONTFACE].b      \
        - b->colors[__GL_FRONTFACE].b) + b->colors[__GL_FRONTFACE].b; \
    d->colors[__GL_FRONTFACE].a = t*(a->colors[__GL_FRONTFACE].a      \
        - b->colors[__GL_FRONTFACE].a) + b->colors[__GL_FRONTFACE].a
#define __GL_CLIP_BACKCOLOR(d,a,b,t)				    \
    d->colors[__GL_BACKFACE].r = t*(a->colors[__GL_BACKFACE].r	    \
        - b->colors[__GL_BACKFACE].r) + b->colors[__GL_BACKFACE].r; \
    d->colors[__GL_BACKFACE].g = t*(a->colors[__GL_BACKFACE].g	    \
        - b->colors[__GL_BACKFACE].g) + b->colors[__GL_BACKFACE].g; \
    d->colors[__GL_BACKFACE].b = t*(a->colors[__GL_BACKFACE].b	    \
        - b->colors[__GL_BACKFACE].b) + b->colors[__GL_BACKFACE].b; \
    d->colors[__GL_BACKFACE].a = t*(a->colors[__GL_BACKFACE].a	    \
        - b->colors[__GL_BACKFACE].a) + b->colors[__GL_BACKFACE].a
#define __GL_CLIP_INDEX(d,a,b,t)				     \
    d->colors[__GL_FRONTFACE].r = t*(a->colors[__GL_FRONTFACE].r     \
        - b->colors[__GL_FRONTFACE].r) + b->colors[__GL_FRONTFACE].r
#define __GL_CLIP_BACKINDEX(d,a,b,t)				   \
    d->colors[__GL_BACKFACE].r = t*(a->colors[__GL_BACKFACE].r	   \
        - b->colors[__GL_BACKFACE].r) + b->colors[__GL_BACKFACE].r

// multimedia\opengl\test\conform\confshel\util.h
#define SETCLEARCOLOR(x) (buffer.colorMode == GL_RGB) ?                   \
			 glClearColor(colorMap[(x)][0], colorMap[(x)][1], \
				      colorMap[(x)][2], 0.0) :            \
			 glClearIndex((float)(x))
#define SETCOLOR(x) (buffer.colorMode == GL_RGB) ? glColor3fv(colorMap[(x)]) : \
						   glIndexi((x))

// multimedia\opengl\test\conform\ctk\ctk.h
#define TK_WIND_IS_RGB(x)	(((x) & TK_WIND_CI) == 0)

// multimedia\opengl\test\conform\ctk\ctkw.c
#define BLACK   PALETTERGB(0,0,0)
#define WHITE   PALETTERGB(255,255,255)

// multimedia\opengl\test\glut\src\gltint.h
#define GLUT_WIND_IS_RGB(x)         (((x) & GLUT_INDEX) == 0)

// multimedia\opengl\test\glut\src\wgltpal.c
#define BLACK PALETTERGB(0, 0, 0)
#define WHITE PALETTERGB(255, 255, 255)

// multimedia\opengl\test\samples\tprim.c
#define PIXEL_CENTER(x) ((long)(x) + 0.5)

// multimedia\opengl\test\simple\rgb\d3dapp\d3dmacs.h
#define MAKE_MATRIX(lpDev, handle, data) \
    if (lpDev->lpVtbl->CreateMatrix(lpDev, &handle) != D3D_OK) \
	return FALSE; \
    if (lpDev->lpVtbl->SetMatrix(lpDev, handle, &data) != D3D_OK) \
	return FALSE
#define RELEASE(x) if (x != NULL) {x->lpVtbl->Release(x); x = NULL;}

// multimedia\opengl\test\simple\rgb\d3dapp\rmdemo.h
#define RELEASE(x) if (x != NULL) {x->lpVtbl->Release(x); x = NULL;}

// multimedia\opengl\test\simple\rgb\gfxperf\rend.h
#define MATRIX_MULTIPLY_REND_DATA(prm1, prm2, prm3, pv) \
    MATRIX_MULTIPLY_DATA((prm1)->Handle(), (prm2)->Handle(), \
                         (prm3)->Handle(), (pv))

// multimedia\opengl\test\simple\rgb\lathe\lathe.rc
#define SBS_VERT_TAB    ( SBS_VERT | WS_TABSTOP )

// multimedia\opengl\test\simple\rgb\timecube\timecube.rc
#define SBS_VERT_TAB    ( SBS_VERT | WS_TABSTOP )

// multimedia\opengl\toolkits\libaux\tk.c
#define BLACK   PALETTERGB(0,0,0)
#define WHITE   PALETTERGB(255,255,255)

// multimedia\opengl\toolkits\libaux\tk.h
#define TK_IS_RGB(x)		(((x) & TK_INDEX) == 0)
#define TK_SETCOLOR(x, y) (TK_IS_RGB((x)) ? \
		           glColor3fv(auxRGBMap[(y)]) : glIndexf((y)))

// multimedia\opengl\toolkits\libmtk\palette.cxx
#define BLACK   PALETTERGB(0,0,0)
#define WHITE   PALETTERGB(255,255,255)

// multimedia\opengl\toolkits\libtk\tk.h
#define TK_IS_RGB(x)		(((x) & TK_INDEX) == 0)
#define TK_SETCOLOR(x, y) (TK_IS_RGB((x)) ? \
		           glColor3fv(auxRGBMap[(y)]) : glIndexf((y)))

// multimedia\published\directx\dmusic\inc\dmusicf.h
#define DMUS_FOURCC_CHORDPALETTE_LIST   mmioFOURCC('c','h','p','l')

// multimedia\published\dxmdev\dshowdev\idl\uuids.h
#define MEDIASUBTYPE_HASALPHA(mt) ( ((mt).subtype == MEDIASUBTYPE_ARGB4444)            || \
                                    ((mt).subtype == MEDIASUBTYPE_ARGB32)              || \
                                    ((mt).subtype == MEDIASUBTYPE_AYUV)                || \
                                    ((mt).subtype == MEDIASUBTYPE_AI44)                || \
                                    ((mt).subtype == MEDIASUBTYPE_IA44)                || \
                                    ((mt).subtype == MEDIASUBTYPE_ARGB1555)            || \
                                    ((mt).subtype == MEDIASUBTYPE_ARGB32_D3D_DX7_RT)   || \
                                    ((mt).subtype == MEDIASUBTYPE_ARGB4444_D3D_DX7_RT) || \
                                    ((mt).subtype == MEDIASUBTYPE_ARGB1555_D3D_DX7_RT) )
#define MEDIASUBTYPE_D3D_DX7_RT(mt) (((mt).subtype == MEDIASUBTYPE_ARGB32_D3D_DX7_RT)   || \
                                     ((mt).subtype == MEDIASUBTYPE_ARGB4444_D3D_DX7_RT) || \
                                     ((mt).subtype == MEDIASUBTYPE_ARGB1555_D3D_DX7_RT) || \
                                     ((mt).subtype == MEDIASUBTYPE_RGB32_D3D_DX7_RT)    || \
                                     ((mt).subtype == MEDIASUBTYPE_RGB16_D3D_DX7_RT))

// multimedia\published\dxmdev\dshowdev\include\amvideo.h
#define AMDDS_RGB (AMDDS_RGBOFF | AMDDS_RGBOVR | AMDDS_RGBFLP)
#define SIZE_EGA_PALETTE (iEGA_COLORS * sizeof(RGBQUAD))
#define SIZE_PALETTE (iPALETTE_COLORS * sizeof(RGBQUAD))
#define RESET_PALETTE(pbmi) (ZeroMemory((PVOID)(pbmi)->bmiColors,SIZE_PALETTE));

// net\config\shell\inc\pch.h
#define LoadIconSize(hInstance, lpszName, dwSize) \
    reinterpret_cast<HICON>(LoadImage(hInstance, lpszName, IMAGE_ICON, dwSize, dwSize, LR_DEFAULTCOLOR))

// net\config\tools\ncbrowse\regexpr.h
#define STATIC_RPATTERN_EX( type, var, params ) \
    static unsigned char s_rgb_##var[ sizeof type ]; \
    static bool s_f_##var = false; \
    static const type & var = *reinterpret_cast<type*>( s_rgb_##var ); \
    static const regex::rpattern_destroyer<type> s_des_##var( s_f_##var, var ); \
    if( ! s_f_##var ) \
    { \
        regex::CRegExLock objLock; \
        if( ! s_f_##var ) \
        { \
            new( s_rgb_##var ) type params; \
            s_f_##var = true; \
        } \
    }

// net\inc\dsacsuse.h
#define	ACS_DIRECTION_BOTH		(ACS_DIRECTION_RECEIVE | ACS_DIRECTION_SEND)

// net\jet500\jet\dae\src\ver.c
#define FRCECorrect( dbid1, srid1, dbid2, srid2 )       \
	( srid1 == srid2 && dbid1 == dbid2 )

// net\jet500\xjet\src\ver.c
#define FRCECorrect( dbid1, srid1, dbid2, srid2 )       \
	( srid1 == srid2 && dbid1 == dbid2 )

// net\rras\ip\nat\director.h
#define DIRECTOR_KEY_PORT(Key)        ((USHORT)((Key) & 0x0000FFFF))

// net\rras\ndis\ndiswan\vjslip.h
#define SPECIAL_D (NEW_S|NEW_A|NEW_W|NEW_U)  /* unidirectional data */

// net\rras\ras\ui\inc\common.h
#define ColorText(nState)           (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHTTEXT : COLOR_WINDOWTEXT)
#define ColorBk(nState)             (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_WINDOW)
#define ColorMenuText(nState)       (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHTTEXT : COLOR_MENUTEXT)
#define ColorMenuBk(nState)         (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_MENU)

// net\rras\ras\ui\rasscrpt\terminal.c
#define TERMINAL_BK_COLOR      (RGB( 0, 0, 0 ))
#define TERMINAL_FR_COLOR      (RGB( 255, 255, 255 ))

// net\sfm\afp\server\fileio.h
#define	FILEIO_OPEN_FILE					(FILE_NON_DIRECTORY_FILE		|\
											 FILE_RANDOM_ACCESS				|\
											 FILE_SYNCHRONOUS_IO_NONALERT)
#define	FILEIO_OPEN_DIR						(FILE_DIRECTORY_FILE			|\
											 FILE_SYNCHRONOUS_IO_NONALERT)

// net\sockets\winsock2\wsp\afdsys\afdprocs.h
#define IS_DATA_ON_CONNECTION(conn)                                           \
            ((conn)->TdiBufferring ?                            \
                IS_DATA_ON_CONNECTION_B(conn) :                 \
                IS_DATA_ON_CONNECTION_NB(conn) )
#define IS_EXPEDITED_DATA_ON_CONNECTION(conn)                                 \
            ((conn)->TdiBufferring ?                            \
                IS_EXPEDITED_DATA_ON_CONNECTION_B(conn) :       \
                IS_EXPEDITED_DATA_ON_CONNECTION_NB(conn) )

// net\tapi\litesabr\filters\inc\compddk.h
#define ICM_DECOMPRESS_SET_PALETTE  (ICM_USER+29)   // fill in the DIB color table
#define ICM_DECOMPRESS_GET_PALETTE  (ICM_USER+30)   // fill in the DIB color table
#define ICM_DRAW_GET_PALETTE        (ICM_USER+16)   // get the palette needed for drawing
#define ICM_DRAW_CHANGEPALETTE      (ICM_USER+51)   // for animating palette

// net\tapi\skywalker\apps\avdialer\avdialer\avdialer.cpp
#define ABOUT_SCROLL_INTERVAL (25 * ABOUT_SCROLL_PIXELS)

// net\tapi\skywalker\apps\avdialer\avdialer\splitter.cpp
#define BLACK        (RGB(0,0,0))

// net\tapi\skywalker\apps\avdialer\avdialer\stdafx.h
#define RGB_TRANS        RGB(255,0,255)

// net\tapi\skywalker\apps\avdialer\avmeter\tmeter.h
#define TMM_GETCOLOR			(WM_USER + 102)
#define TMM_SETCOLOR			(WM_USER + 103)

// net\tapi\skywalker\filters\video\tapivcap\convert.cpp
#define RGBX(rgb)   RGB(GetBValue(rgb), GetGValue(rgb), GetRValue(rgb))
#define RGBQ(r,g,b) RGB(b,g,r)
#define NOCOLLAPSEPALETTERGBQ(r,g,b)   (0x04000000 | RGB(b,g,r))

// net\tapi\skywalker\filters\video\tapivcap\preview.cpp
#define NOCOLLAPSEPALETTERGBQ(r,g,b)   (0x04000000 | RGB(b,g,r))
#define NOCOLLAPSEPALETTERGBQ(r,g,b)   (0x04000000 | RGB(b,g,r))

// net\tapi\thunk\windows.h
#define PALETTERGB(r,g,b)   (0x02000000L | RGB(r,g,b))
#define BF_RECT         (BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM)  // ;Internal 4.0
#define STM_SETIMAGE        (WM_USER+2)     // ;Internal 4.0
#define STM_GETIMAGE        (WM_USER+3)     // ;Internal 4.0
#define BM_GETIMAGE         (WM_USER+6)     // ;Internal 4.0
#define BM_SETIMAGE         (WM_USER+7)     // ;Internal 4.0
#define EM_GETRECT              (WM_USER+2)
#define EM_SETRECT              (WM_USER+3)
#define EM_SETRECTNP            (WM_USER+4)
#define LB_GETITEMRECT          (WM_USER+25)

// net\unimodem\inc\rovcomm.h
#define ColorText(nState)           (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHTTEXT : COLOR_WINDOWTEXT)
#define ColorBk(nState)             (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_WINDOW)
#define ColorMenuText(nState)       (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHTTEXT : COLOR_MENUTEXT)
#define ColorMenuBk(nState)         (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_MENU)

// net\unimodem\src\modemui\util.c
    #define CR_DARK_GRAY    RGB(128, 128, 128)

// net\unimodem\src\tsp\appterm.cpp
#define TERMINAL_BK_COLOR      (RGB( 0, 0, 0 ))
#define TERMINAL_FR_COLOR      (RGB( 255, 255, 255 ))

// printscan\fax\admin\fspext\atlsnap.h
#define END_EXTENSION_SNAPIN_NODEINFO_MAP() \
			return ISnapInDataInterface::GetDataClass(pDataObject); \
	};
#define BEGIN_SNAPINTOOLBARID_MAP(theClass) \
public: \
	static CSnapInToolbarInfo* GetToolbarInfo() \
	{ \
		static CSnapInToolbarInfo m_toolbarInfo[] = \
		{
#define END_SNAPINTOOLBARID_MAP() \
			{ NULL, NULL, NULL, 0, 0, NULL} \
		}; \
		return m_toolbarInfo; \
	}

// printscan\fax\admin\routeext\atlsnap.h
#define END_EXTENSION_SNAPIN_NODEINFO_MAP() \
                        return ISnapInDataInterface::GetDataClass(pDataObject); \
        };
#define BEGIN_SNAPINTOOLBARID_MAP(theClass) \
public: \
        static CSnapInToolbarInfo* GetToolbarInfo() \
        { \
                static CSnapInToolbarInfo m_toolbarInfo[] = \
                {
#define END_SNAPINTOOLBARID_MAP() \
                        { NULL, NULL, NULL, 0, 0, NULL} \
                }; \
                return m_toolbarInfo; \
        }

// printscan\fax\config\dll\faxcpl.h
#define GetPrinterSelName() \
        ((gConfigData->printerSel < gConfigData->cPrinters) ? \
            gConfigData->pPrinterInfo[gConfigData->printerSel].pPrinterName : NULL)

// printscan\fax\faxcover\src\cpeobj.h
#define COLOR_WHITE   RGB(255, 255, 255)
#define COLOR_LTBLUE  RGB(166, 202, 240)
#define COLOR_LTGRAY  RGB(192, 192, 192)
#define COLOR_MDGRAY  RGB(160, 160, 154)
#define COLOR_DKGRAY  RGB(128, 128, 128)
#define COLOR_BLACK   RGB(0, 0, 0)

// printscan\fax\print\faxprint\faxdrv\faxdrv.h
#define RGB_BLACK   RGB(0, 0, 0)
#define RGB_WHITE   RGB(255, 255, 255)

// printscan\fax\print\faxprint\faxui\docevent.c
#define DocEventRequiresDC(iEsc) \
        ((iEsc) >= DOCUMENTEVENT_RESETDCPRE && (iEsc) <= DOCUMENTEVENT_LAST)

// printscan\fax\print\faxprint\faxui\faxui.h
#define MarkPDEVUserMem(p)  \
        { (p)->signature = (p)->devmode.dmPrivate.pUserMem = (p); }

// printscan\fax\print\faxprint\lib\halftone.c
#define ADJ_CA(p,a,i,x) if ((p->a<i)||(p->a>x)){Ok=FALSE;p->a=DefHTClrAdj.a;}

// printscan\fax\provider\t30\class1\class1.h
#define EndMode(pTG)         { pTG->Class1Modem.DriverMode = IDLE;      \
                                                pTG->Class1Modem.ModemMode = COMMAND;        \
                                                pTG->Class1Modem.CurMod = 0; }

// printscan\fax\provider\t30\comm\fcom.c
#define         ALWAYSEVENTS    (EV_BREAK | EV_ERR)
#define         DRAINEVENTS             (ALWAYSEVENTS | EV_TXEMPTY)
#define         WRITEEVENTS             (ALWAYSEVENTS | EV_TXEMPTY)

// printscan\fax\provider\t30\comm\identify.c
#define fMANDATORY (fGOTCMD_Reset|fGOTCMD_Setup|fGOTCAP_CLASSES)
#define fCLASS1MANDATORY (fMANDATORY | fGOTCAP_SENDSPEEDS | fGOTCAP_RECVSPEEDS)

// printscan\fax\provider\t30\headers\awfile.h
#define AWFS_USER_ATTACH    (AWFS_GENERIC|AWFS_PERSISTENT)  // user attachment
#define AWFS_NORM_READ          (AWFS_READ|AWFS_DEFAULT_PREFETCH|AWFS_DEFAULT_BUFSIZE)
#define AWFS_NORM_WRITE         (AWFS_WRITE|AWFS_DEFAULT_BUFSIZE)

// printscan\fax\provider\t30\headers\awnsfcor.h
#define AWRES_ALLT30 (AWRES_mm080_038 | AWRES_mm080_077 | AWRES_mm080_154 | AWRES_mm160_154 | AWRES_200_200 | AWRES_300_300 | AWRES_400_400)

// printscan\fax\provider\t30\headers\awnsfint.h
#define HasRecipSubAddr(lpbc)   ((lpbc)->wRecipSubAddrLen && (lpbc)->wszRecipSubAddr)

// printscan\fax\provider\t30\headers\defs.h
#  define MDDI	// exact ModemDDI (rev 0.90) (need MDRV && !DYNL). REQD if using OEM driver. REQD to diable if using Class1 driver.
#  define MDRV	// monolith drv. REQD for OEM driver (need !WFW & !DYNL). Incompatible with CL2. Optional for Class1.

// printscan\fax\provider\t30\headers\fmtres.h
#define FRSetErrorData(dwerr,data) (((dwerr) & 0xffff00ff) | FRMAKE_ERRDATA(data))
#define CHK_FR_ERR(n) ((n & (FR_SOS_ERR | FR_SYSTEM_ERR)) != 0)

// printscan\fax\provider\t30\headers\nsfmacro.h
#define SetBCSTD0(p, l, n, m, b, i)			\
			(((p)->GroupLength)    = (l));	\
			(((p)->GroupNum)	   = (n));	\
			(((p)->vMsgProtocol)   = (m));	\
			(((p)->fBinaryData)	   = (b));	\
			(((p)->fInwardRouting) = (i));
#define SetBCSTD4(p, s, l)				\
			(((p)->DataSpeed)	= (s));	\
			(((p)->DataLink)	= (l));
#define SetBCIMAGE0(p, l, n, a, r)			\
			(((p)->GroupLength)    = (l));	\
			(((p)->GroupNum)	   = (n));	\
			(((p)->fAnyWidth)      = (a));	\
			(((p)->vRamboVer)	   = (r));
#define SetBCIMAGE2(p, c, a, m)				\
			(((p)->vCoverAttach)   = (c));	\
			(((p)->vAddrAttach)    = (a));	\
			(((p)->vMetaFile)	   = (m));
#define SetBCPOLLCAPS2(p, e, n, m)				\
			(((p)->fExtCapsAvail)	= (e));		\
			(((p)->fNoShortTurn)	= (n));		\
			(((p)->vMsgRelay) 		= (m));
#define SetBCNSS0(p, l, n, m, i)		 		\
			(((p)->GroupLength)    	 = (l));	\
			(((p)->GroupNum)	   	 = (n));	\
			(((p)->vMsgProtocol)   	 = (m));	\
			(((p)->vInteractive)	 = (i));	\

// printscan\fax\provider\t30\headers\protdump.h
#define ISSENDFRAME(lpfr)       \
                ((lpfr->ifr & 0x80))

// printscan\fax\provider\t30\headers\rendserv.h
#define RSGetErrCode(err)     (err & 0x003f)
#define RSGetErrMethod(err)   (err & 0x0fc0)
#define RSGetErrSys(err)      (err & 0xf000)

// printscan\fax\provider\t30\headers\rgndlg.h
#define MakeStem(stt, ss) (stt | ss)

// printscan\fax\provider\t30\headers\t30fail.h
#define T30FAILS_FREEBUF_PHASEC      13 // Error in Freebuf (must be a bug)
#define T30FAILSE_FREEBUF_PHASEC      18 // Error in IFBufFree (muts be a bug)

// printscan\fax\provider\t30\headers\uiutil.h
#define GET_WM_COMMAND_CONTROL_ID(wp, lp)					(wp)

// printscan\fax\provider\t30\main\hdlc.c
#define SF_LASTFR               (SEND_ENDFRAME|SEND_FINAL)

// printscan\fax\provider\t30\main\negot.c
#define ENCODE_CAPS             (MH_DATA | MR_DATA )  // RSL | MMR_DATA)
#  define CAPS_RES  (AWRES_mm080_038 | AWRES_mm080_077 | AWRES_200_200 | AWRES_300_300 | AWRES_mm080_154 | AWRES_160_154 | AWRES_400_400)
#  define CAPS_RES  (AWRES_mm080_038 | AWRES_mm080_077 | AWRES_200_200 | AWRES_300_300)

// printscan\fax\provider\t30\main\t30.h
#define GetDevAndDial(pTG, port, phone)              (GetDev(pTG, port) && Dial(pTG, phone))
#define GetDevAndAnswer(pTG, port)                   (GetDev(pTG, port) && Answer(pTG))
#       define ModemECMRecvMode(pTG, h, mod, t)      ModemRecvMode(pTG, h, mod, TRUE, t, ifrECMPIX)

// printscan\fax\service\faxstat\faxstat.h
#define TRAYCALLBACK        (WM_USER + 200)
#define INITANIMATION       (WM_USER + 201)
#define CONFIGUPDATE        (WM_USER + 203)
#define ACTIVATE            (WM_USER + 204)

// printscan\fax\setup\win9xupg\inc\oleutils.h
#define DIB_EXT			_T("dib")

// printscan\fax\test\faxvrfy\faxvrfy.h
#define UM_FAXVRFY_INITIALIZE   (WM_USER + 1)
#define UM_FAXVRFY_UPDATE       (WM_USER + 2)
#define UM_FAXVRFY_RESET        (WM_USER + 3)
#define UM_FAXSVC_ENDED         (WM_USER + 5)
#define UM_ITERATION_STOPPED    (WM_USER + 6)
#define UM_ITERATION_PASSED     (WM_USER + 7)

// printscan\fax\web\images\ppmtogif.c
#define ARGVAL() (*++(*argv) || (--argc && *++argv))

// printscan\faxsrv\src\admin\inc\atlsnap.h
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

// printscan\faxsrv\src\faxcover\src\cpeobj.h
#define COLOR_WHITE   RGB(255, 255, 255)
#define COLOR_LTBLUE  RGB(166, 202, 240)
#define COLOR_LTGRAY  RGB(192, 192, 192)
#define COLOR_MDGRAY  RGB(160, 160, 154)
#define COLOR_DKGRAY  RGB(128, 128, 128)
#define COLOR_BLACK   RGB(0, 0, 0)

// printscan\faxsrv\src\faxverify\faxvrfy\faxvrfy.h
#define UM_FAXVRFY_INITIALIZE   (WM_USER + 1)
#define UM_FAXVRFY_UPDATE       (WM_USER + 2)
#define UM_FAXVRFY_RESET        (WM_USER + 3)
#define UM_FAXSVC_ENDED         (WM_USER + 5)
#define UM_ITERATION_STOPPED    (WM_USER + 6)
#define UM_ITERATION_PASSED     (WM_USER + 7)

// printscan\faxsrv\src\inc\faxuiconstants.h
#define FXS_STARTSTOP_MAX_SLEEP      1000  //Sec^(-3)
#define FXS_STARTSTOP_MAX_WAIT      20000  //Sec^(-3)

// printscan\faxsrv\src\print\faxprint\faxdrv\faxdrv.h
#define RGB_BLACK   RGB(0, 0, 0)
#define RGB_WHITE   RGB(255, 255, 255)

// printscan\faxsrv\src\print\faxprint\faxui\docevent.c
#define DocEventRequiresDC(iEsc) \
        ((iEsc) >= DOCUMENTEVENT_RESETDCPRE && (iEsc) <= DOCUMENTEVENT_LAST)

// printscan\faxsrv\src\print\faxprint\faxui\faxui.h
#define MarkPDEVUserMem(p)  \
        { (p)->signature = (p)->devmode.dmPrivate.pUserMem = (p); }

// printscan\faxsrv\src\print\faxprint\lib\halftone.c
#define ADJ_CA(p,a,i,x) if ((p->a<i)||(p->a>x)){Ok=FALSE;p->a=DefHTClrAdj.a;}

// printscan\faxsrv\src\print\faxprint\prnwzrd\edkmdb.h
#define ROW_EMPTY			(ROW_ADD|ROW_REMOVE)
#define	rightsReadWrite			(frightsReadAny|frightsEditAny)

// printscan\faxsrv\src\print\faxprint\prnwzrd\faxui.h
#define MarkPDEVWizardUserMem(p)  \
        { (p)->signature = (p); }

// printscan\faxsrv\src\provider\t30\class1\class1.h
#define EndMode(pTG)         { pTG->Class1Modem.DriverMode = IDLE;      \
                                                pTG->Class1Modem.ModemMode = COMMAND;        \
                                                pTG->Class1Modem.CurMod = 0; }

// printscan\faxsrv\src\provider\t30\comm\fcom.c
#define         ALWAYSEVENTS    (EV_BREAK | EV_ERR)
#define         DRAINEVENTS             (ALWAYSEVENTS | EV_TXEMPTY)
#define         WRITEEVENTS             (ALWAYSEVENTS | EV_TXEMPTY)

// printscan\faxsrv\src\provider\t30\comm\identify.c
#define fMANDATORY (fGOTCMD_Reset|fGOTCMD_Setup|fGOTCAP_CLASSES)
#define fCLASS1MANDATORY (fMANDATORY | fGOTCAP_SENDSPEEDS | fGOTCAP_RECVSPEEDS)

// printscan\faxsrv\src\provider\t30\headers\awnsfcor.h
#define AWRES_ALLT30 (AWRES_mm080_038 | AWRES_mm080_077 | AWRES_mm080_154 | AWRES_mm160_154 | AWRES_200_200 | AWRES_300_300 | AWRES_400_400)

// printscan\faxsrv\src\provider\t30\headers\awnsfint.h
#define HasRecipSubAddr(lpbc)   ((lpbc)->wRecipSubAddrLen && (lpbc)->wszRecipSubAddr)

// printscan\faxsrv\src\provider\t30\headers\defs.h
#  define MDRV	// monolith drv. REQD for OEM driver (need !WFW & !DYNL). Incompatible with CL2. Optional for Class1.

// printscan\faxsrv\src\provider\t30\headers\nsfmacro.h
#define SetBCSTD0(p, l, n, m, b, i)			\
			(((p)->GroupLength)    = (l));	\
			(((p)->GroupNum)	   = (n));	\
			(((p)->vMsgProtocol)   = (m));	\
			(((p)->fBinaryData)	   = (b));	\
			(((p)->fInwardRouting) = (i));
#define SetBCSTD4(p, s, l)				\
			(((p)->DataSpeed)	= (s));	\
			(((p)->DataLink)	= (l));
#define SetBCIMAGE0(p, l, n, a, r)			\
			(((p)->GroupLength)    = (l));	\
			(((p)->GroupNum)	   = (n));	\
			(((p)->fAnyWidth)      = (a));	\
			(((p)->vRamboVer)	   = (r));
#define SetBCIMAGE2(p, c, a, m)				\
			(((p)->vCoverAttach)   = (c));	\
			(((p)->vAddrAttach)    = (a));	\
			(((p)->vMetaFile)	   = (m));
#define SetBCPOLLCAPS2(p, e, n, m)				\
			(((p)->fExtCapsAvail)	= (e));		\
			(((p)->fNoShortTurn)	= (n));		\
			(((p)->vMsgRelay) 		= (m));
#define SetBCNSS0(p, l, n, m, i)		 		\
			(((p)->GroupLength)    	 = (l));	\
			(((p)->GroupNum)	   	 = (n));	\
			(((p)->vMsgProtocol)   	 = (m));	\
			(((p)->vInteractive)	 = (i));	\

// printscan\faxsrv\src\provider\t30\headers\protdump.h
#define ISSENDFRAME(lpfr)       \
                ((lpfr->ifr & 0x80))

// printscan\faxsrv\src\provider\t30\headers\rendserv.h
#define RSGetErrCode(err)     (err & 0x003f)
#define RSGetErrMethod(err)   (err & 0x0fc0)
#define RSGetErrSys(err)      (err & 0xf000)

// printscan\faxsrv\src\provider\t30\headers\t30fail.h
#define T30FAILS_FREEBUF_PHASEC      13 // Error in Freebuf (must be a bug)
#define T30FAILSE_FREEBUF_PHASEC      18 // Error in IFBufFree (muts be a bug)

// printscan\faxsrv\src\provider\t30\main\hdlc.c
#define SF_LASTFR               (SEND_ENDFRAME|SEND_FINAL)

// printscan\faxsrv\src\provider\t30\main\negot.c
#define ENCODE_CAPS             (MH_DATA | MR_DATA )  // RSL | MMR_DATA)
#  define CAPS_RES  (AWRES_mm080_038 | AWRES_mm080_077 | AWRES_200_200 | AWRES_300_300 | AWRES_mm080_154 | AWRES_160_154 | AWRES_400_400)
#  define CAPS_RES  (AWRES_mm080_038 | AWRES_mm080_077 | AWRES_200_200 | AWRES_300_300)

// printscan\faxsrv\src\provider\t30\main\t30.h
#define GetDevAndDial(pTG, port, phone)              (GetDev(pTG, port) && Dial(pTG, phone))
#define GetDevAndAnswer(pTG, port)                   (GetDev(pTG, port) && Answer(pTG))
#       define ModemECMRecvMode(pTG, h, mod, t)      ModemRecvMode(pTG, h, mod, TRUE, t, ifrECMPIX)

// printscan\faxsrv\src\sdktools\msvc15\include\commdlg.h
#define CF_BOTH 		     (CF_SCREENFONTS | CF_PRINTERFONTS)

// printscan\faxsrv\src\sdktools\msvc15\include\compobj.h
#define CLSCTX_INPROC           (CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER)

// printscan\faxsrv\src\sdktools\msvc15\include\ctype.h
#define isupper(_c) ( (_ctype+1)[_c] & _UPPER )
#define isdigit(_c) ( (_ctype+1)[_c] & _DIGIT )
#define isxdigit(_c)    ( (_ctype+1)[_c] & _HEX )
#define isspace(_c) ( (_ctype+1)[_c] & _SPACE )
#define ispunct(_c) ( (_ctype+1)[_c] & _PUNCT )
#define iscntrl(_c) ( (_ctype+1)[_c] & _CONTROL )
#define __toascii(_c)   ( (_c) & 0x7f )
#define __iscsymf(_c)   (isalpha(_c) || ((_c) == '_'))
#define __iscsym(_c)    (isalnum(_c) || ((_c) == '_'))

// printscan\faxsrv\src\sdktools\msvc15\include\ddeml.h
#define     XTYP_ADVSTART           (0x0030 | XCLASS_BOOL          )
#define     XTYP_ADVSTOP            (0x0040 | XCLASS_NOTIFICATION)
#define     XTYP_XACT_COMPLETE      (0x0080 | XCLASS_NOTIFICATION  )
#define     XTYP_REQUEST            (0x00B0 | XCLASS_DATA          )

// printscan\faxsrv\src\sdktools\msvc15\include\dispatch.h
#define IsHashValCompatible(lhashval1, lhashval2) \
	((BOOL) ((0x00ff0000 & (lhashval1)) == (0x00ff0000 & (lhashval2))))

// printscan\faxsrv\src\sdktools\msvc15\include\dos.h
#define _FP_SEG(fp) (*((unsigned __far *)&(fp)+1))
#define _FP_OFF(fp) (*((unsigned __far *)&(fp)))

// printscan\faxsrv\src\sdktools\msvc15\include\dvobj.h
#define UPDFCACHE_IFBLANKORONSAVECACHE	(UPDFCACHE_IFBLANK | UPDFCACHE_ONSAVECACHE )
#define UPDFCACHE_ALL					(~UPDFCACHE_ONLYIFBLANK)
#define UPDFCACHE_ALLBUTNODATACACHE		(UPDFCACHE_ALL & ~UPDFCACHE_NODATACACHE)

// printscan\faxsrv\src\sdktools\msvc15\include\mmsystem.h
#define DIBINDEX(n)     MAKELONG((n),0x10FF)

// printscan\faxsrv\src\sdktools\msvc15\include\ole2ui.h
#define isspace(j) (j==' ' || j=='\t' || j=='\n')

// printscan\faxsrv\src\sdktools\msvc15\include\olenls.h
#define PRIMARYLANGID(lgid)    ((unsigned short)(lgid) & 0x3ff)

// printscan\faxsrv\src\sdktools\msvc15\include\olestd.h
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
#define AreRectsEqual(lprc1, lprc2)     \
	(((lprc1->top == lprc2->top) &&     \
	  (lprc1->left == lprc2->left) &&   \
	  (lprc1->right == lprc2->right) && \
	  (lprc1->bottom == lprc2->bottom)) ? TRUE : FALSE)

// printscan\faxsrv\src\sdktools\msvc15\include\penwin.h
#define FIsUpAppGesture(syv)   (syv >= SYV_CIRCLEUPA && syv <= SYV_CIRCLEUPZ)
#define PDK_SWITCHES           (PDK_DOWN|PDK_BARREL1|PDK_BARREL2|PDK_BARREL3)
#define MAP_GESTOGES				(RCRT_GESTURE|RCRT_GESTURETRANSLATED)
#define MAP_GESTOVKEYS			(RCRT_GESTURETOKEYS|RCRT_ALREADYPROCESSED)
#define IsGestureToGesture(lprcresult)	(((lprcresult)->wResultstype & MAP_GESTOGES \
													 ) == MAP_GESTOGES)
#define IsGestureToVkeys(lprcresult)	(((lprcresult)->wResultstype & MAP_GESTOVKEYS \
													 ) == MAP_GESTOVKEYS)
#define SetAlreadyProcessed(lprcresult) ((lprcresult)->wResultsType = ((lprcresult)->wResultsType \
														& ~RCRT_GESTURETOKEYS) | RCRT_ALREADYPROCESSED)

// printscan\faxsrv\src\sdktools\msvc15\include\penwoem.h
#define TRAIN_BOTH             (TRAIN_DEFAULT | TRAIN_CUSTOM)

// printscan\faxsrv\src\sdktools\msvc15\include\scode.h
#define SCODE_CODE(sc)      ((sc) & 0xFFFF)
#define GetScode(hr)        ((SCODE)(hr) & 0x800FFFFF)

// printscan\faxsrv\src\sdktools\msvc15\include\stdio.h
#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])
#define _stdaux (&_iob[3])
#define _stdprn (&_iob[4])

// printscan\faxsrv\src\sdktools\msvc15\include\variant.h
#define V_ISBYREF(X)     (V_VT(X)&VT_BYREF)
#define V_ISVECTOR(X)    (V_VT(X)&VT_VECTOR)

// printscan\faxsrv\src\sdktools\msvc15\include\wfext.h
#define FM_GETFOCUS		(WM_USER + 0x0200)
#define FM_GETDRIVEINFO		(WM_USER + 0x0201)
#define FM_GETFILESEL		(WM_USER + 0x0204)
#define FM_GETFILESELLFN	(WM_USER + 0x0205)	/* LFN versions are odd */
#define FM_REFRESH_WINDOWS	(WM_USER + 0x0206)

// printscan\faxsrv\src\sdktools\msvc15\include\windows.h
#define GHND		    (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define LHND		    (LMEM_MOVEABLE | LMEM_ZEROINIT)
#define PALETTERGB(r,g,b)   (0x02000000L | RGB(r,g,b))
#define QS_MOUSE	(QS_MOUSEMOVE | QS_MOUSEBUTTON)
#define WVR_REDRAW	    (WVR_HREDRAW | WVR_VREDRAW)
#define DM_GETDEFID	    (WM_USER+0)
#define DM_SETDEFID	    (WM_USER+1)
#define STM_SETICON	    (WM_USER+0)
#define STM_GETICON	    (WM_USER+1)
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
#define LB_GETITEMRECT	       (WM_USER+25)
#define LB_GETITEMDATA         (WM_USER+26)
#define LB_SETITEMDATA         (WM_USER+27)
#define LB_SETCARETINDEX       (WM_USER+31)
#define LB_GETCARETINDEX       (WM_USER+32)
#define LB_SETITEMHEIGHT       (WM_USER+33)
#define LB_GETITEMHEIGHT       (WM_USER+34)

// printscan\faxsrv\src\sdktools\msvc15\include\winsock.h
#define IOC_INOUT       (IOC_IN|IOC_OUT)
#define IPPROTO_GGP             2               /* gateway^2 (deprecated) */
#define SO_DONTLINGER   (u_int)(~SO_LINGER)

// printscan\faxsrv\src\sdktools\msvc15\mfc\include\afx.h
#define TRACE              1 ? (void)0 : ::AfxTrace
#define TRACE0             1 ? (void)0 : ::AfxTrace
#define TRACE1             1 ? (void)0 : ::AfxTrace
#define TRACE2             1 ? (void)0 : ::AfxTrace
#define TRACE3             1 ? (void)0 : ::AfxTrace
#define _AFX_FP_SEG(lp) (*((UINT*)&(lp)+1))
#define RUNTIME_CLASS(class_name) \
	(&class_name::class##class_name)
#define DECLARE_DYNAMIC(class_name) \
public: \
	static CRuntimeClass AFXAPP_DATA class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const;
#define CATCH(class, e) \
	else if (::AfxCatchProc(RUNTIME_CLASS(class))) \
	{ class* e = (class*)_afxExceptionLink.m_pException;
#define AND_CATCH(class, e) \
	} else if (::AfxCatchProc(RUNTIME_CLASS(class))) \
	{ class* e = (class*)_afxExceptionLink.m_pException;

// printscan\faxsrv\src\sdktools\msvc15\mfc\include\afxdisp.h
#define DISP_PROPERTY_EX(theClass, szExternalName, pfnGet, pfnSet, vtPropType) \
	{ szExternalName, DISPID_UNKNOWN, "", vtPropType, \
		(AFX_PMSG)(void (theClass::*)(void))pfnGet, \
		(AFX_PMSG)(void (theClass::*)(void))pfnSet, 0 }, \
#define DISP_PROPERTY_PARAM(theClass, szExternalName, pfnGet, pfnSet, vtPropType, vtsParams) \
	{ szExternalName, DISPID_UNKNOWN, vtsParams, vtPropType, \
		(AFX_PMSG)(void (theClass::*)(void))pfnGet, \
		(AFX_PMSG)(void (theClass::*)(void))pfnSet, 0 }, \
#define DISP_PROPERTY_EX_ID(theClass, szExternalName, dispid, pfnGet, pfnSet, vtPropType) \
	{ szExternalName, dispid, "", vtPropType, \
		(AFX_PMSG)(void (theClass::*)(void))pfnGet, \
		(AFX_PMSG)(void (theClass::*)(void))pfnSet, 0 }, \
#define DISP_PROPERTY_PARAM_ID(theClass, szExternalName, dispid, pfnGet, pfnSet, vtPropType, vtsParams) \
	{ szExternalName, dispid, vtsParams, vtPropType, \
		(AFX_PMSG)(void (theClass::*)(void))pfnGet, \
		(AFX_PMSG)(void (theClass::*)(void))pfnSet, 0 }, \

// printscan\faxsrv\src\sdktools\msvc15\mfc\include\afxmsg_.h
#define ON_WM_DESTROY() \
	{ WM_DESTROY, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))OnDestroy },
#define ON_WM_MOVE() \
	{ WM_MOVE, 0, AfxSig_vvii, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(int, int))OnMove },
#define ON_WM_SIZE() \
	{ WM_SIZE, 0, AfxSig_vwii, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, int, int))OnSize },
#define ON_WM_ACTIVATE() \
	{ WM_ACTIVATE, 0, AfxSig_vwWb, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CWnd*, BOOL))OnActivate },
#define ON_WM_SETFOCUS() \
	{ WM_SETFOCUS, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*))OnSetFocus },
#define ON_WM_KILLFOCUS() \
	{ WM_KILLFOCUS, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*))OnKillFocus },
#define ON_WM_ENABLE() \
	{ WM_ENABLE, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL))OnEnable },
#define ON_WM_PAINT() \
	{ WM_PAINT, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))OnPaint },
#define ON_WM_QUERYENDSESSION() \
	{ WM_QUERYENDSESSION, 0, AfxSig_bv, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(void))OnQueryEndSession },
#define ON_WM_QUERYOPEN() \
	{ WM_QUERYOPEN, 0, AfxSig_bv, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(void))OnQueryOpen },
#define ON_WM_ERASEBKGND() \
	{ WM_ERASEBKGND, 0, AfxSig_bD, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(CDC*))OnEraseBkgnd },
#define ON_WM_ENDSESSION() \
	{ WM_ENDSESSION, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL))OnEndSession },
#define ON_WM_SHOWWINDOW() \
	{ WM_SHOWWINDOW, 0, AfxSig_vbw, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL, UINT))OnShowWindow },
#define ON_WM_WININICHANGE() \
	{ WM_WININICHANGE, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(LPCSTR))OnWinIniChange },
#define ON_WM_DEVMODECHANGE() \
	{ WM_DEVMODECHANGE, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(LPSTR))OnDevModeChange },
#define ON_WM_ACTIVATEAPP() \
	{ WM_ACTIVATEAPP, 0, AfxSig_vbh, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL, HTASK))OnActivateApp },
#define ON_WM_FONTCHANGE() \
	{ WM_FONTCHANGE, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))OnFontChange },
#define ON_WM_TIMECHANGE() \
	{ WM_TIMECHANGE, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))OnTimeChange },
#define ON_WM_CANCELMODE() \
	{ WM_CANCELMODE, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))OnCancelMode },
#define ON_WM_SETCURSOR() \
	{ WM_SETCURSOR, 0, AfxSig_bWww, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT))OnSetCursor },
#define ON_WM_MOUSEACTIVATE() \
	{ WM_MOUSEACTIVATE, 0, AfxSig_iWww, \
		(AFX_PMSG)(AFX_PMSGW)(int (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT))OnMouseActivate },
#define ON_WM_GETMINMAXINFO() \
	{ WM_GETMINMAXINFO, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(MINMAXINFO FAR*))OnGetMinMaxInfo },
#define ON_WM_ICONERASEBKGND() \
	{ WM_ICONERASEBKGND, 0, AfxSig_vD, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CDC*))OnIconEraseBkgnd },
#define ON_WM_SPOOLERSTATUS() \
	{ WM_SPOOLERSTATUS, 0, AfxSig_vww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT))OnSpoolerStatus },
#define ON_WM_QUERYDRAGICON() \
	{ WM_QUERYDRAGICON, 0, AfxSig_hv, \
		(AFX_PMSG)(AFX_PMSGW)(HCURSOR (AFX_MSG_CALL CWnd::*)())OnQueryDragIcon },
#define ON_WM_COMPACTING() \
	{ WM_COMPACTING, 0, AfxSig_vw, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT))OnCompacting },
#define ON_WM_NCDESTROY() \
	{ WM_NCDESTROY, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))OnNcDestroy },
#define ON_WM_NCCALCSIZE() \
	{ WM_NCCALCSIZE, 0, AfxSig_vCALC, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL, NCCALCSIZE_PARAMS FAR*))OnNcCalcSize },
#define ON_WM_NCPAINT() \
	{ WM_NCPAINT, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))OnNcPaint },
#define ON_WM_NCACTIVATE() \
	{ WM_NCACTIVATE, 0, AfxSig_bb, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(BOOL))OnNcActivate },
#define ON_WM_GETDLGCODE() \
	{ WM_GETDLGCODE, 0, AfxSig_wv, \
		(AFX_PMSG)(AFX_PMSGW)(UINT (AFX_MSG_CALL CWnd::*)(void))OnGetDlgCode },
#define ON_WM_NCMOUSEMOVE() \
	{ WM_NCMOUSEMOVE, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnNcMouseMove },
#define ON_WM_NCLBUTTONDOWN() \
	{ WM_NCLBUTTONDOWN, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnNcLButtonDown },
#define ON_WM_NCLBUTTONUP() \
	{ WM_NCLBUTTONUP, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnNcLButtonUp },
#define ON_WM_NCLBUTTONDBLCLK() \
	{ WM_NCLBUTTONDBLCLK, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnNcLButtonDblClk },
#define ON_WM_NCRBUTTONDOWN() \
	{ WM_NCRBUTTONDOWN, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnNcRButtonDown },
#define ON_WM_NCRBUTTONUP() \
	{ WM_NCRBUTTONUP, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnNcRButtonUp },
#define ON_WM_NCRBUTTONDBLCLK() \
	{ WM_NCRBUTTONDBLCLK, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnNcRButtonDblClk },
#define ON_WM_NCMBUTTONDOWN() \
	{ WM_NCMBUTTONDOWN, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnNcMButtonDown },
#define ON_WM_NCMBUTTONUP() \
	{ WM_NCMBUTTONUP, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnNcMButtonUp },
#define ON_WM_NCMBUTTONDBLCLK() \
	{ WM_NCMBUTTONDBLCLK, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnNcMButtonDblClk },
#define ON_WM_KEYDOWN() \
	{ WM_KEYDOWN, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))OnKeyDown },
#define ON_WM_KEYUP() \
	{ WM_KEYUP, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))OnKeyUp },
#define ON_WM_CHAR() \
	{ WM_CHAR, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))OnChar },
#define ON_WM_DEADCHAR() \
	{ WM_DEADCHAR, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))OnDeadChar },
#define ON_WM_SYSKEYDOWN() \
	{ WM_SYSKEYDOWN, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))OnSysKeyDown },
#define ON_WM_SYSKEYUP() \
	{ WM_SYSKEYUP, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))OnSysKeyUp },
#define ON_WM_SYSCHAR() \
	{ WM_SYSCHAR, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))OnSysChar },
#define ON_WM_SYSDEADCHAR() \
	{ WM_SYSDEADCHAR, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT))OnSysDeadChar },
#define ON_WM_SYSCOMMAND() \
	{ WM_SYSCOMMAND, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, LPARAM))OnSysCommand },
#define ON_WM_TIMER() \
	{ WM_TIMER, 0, AfxSig_vw, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT))OnTimer },
#define ON_WM_HSCROLL() \
	{ WM_HSCROLL, 0, AfxSig_vwwW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CScrollBar*))OnHScroll },
#define ON_WM_VSCROLL() \
	{ WM_VSCROLL, 0, AfxSig_vwwW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CScrollBar*))OnVScroll },
#define ON_WM_INITMENU() \
	{ WM_INITMENU, 0, AfxSig_vM, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CMenu*))OnInitMenu },
#define ON_WM_INITMENUPOPUP() \
	{ WM_INITMENUPOPUP, 0, AfxSig_vMwb, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CMenu*, UINT, BOOL))OnInitMenuPopup },
#define ON_WM_MENUSELECT() \
	{ WM_MENUSELECT, 0, AfxSig_vwwh, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, UINT, HMENU))OnMenuSelect },
#define ON_WM_MENUCHAR() \
	{ WM_MENUCHAR, 0, AfxSig_lwwM, \
		(AFX_PMSG)(AFX_PMSGW)(LRESULT (AFX_MSG_CALL CWnd::*)(UINT, UINT, CMenu*))OnMenuChar },
#define ON_WM_ENTERIDLE() \
	{ WM_ENTERIDLE, 0, AfxSig_vwW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CWnd*))OnEnterIdle },
#define ON_WM_MOUSEMOVE() \
	{ WM_MOUSEMOVE, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnMouseMove },
#define ON_WM_LBUTTONDOWN() \
	{ WM_LBUTTONDOWN, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnLButtonDown },
#define ON_WM_LBUTTONUP() \
	{ WM_LBUTTONUP, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnLButtonUp },
#define ON_WM_LBUTTONDBLCLK() \
	{ WM_LBUTTONDBLCLK, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnLButtonDblClk },
#define ON_WM_RBUTTONDOWN() \
	{ WM_RBUTTONDOWN, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnRButtonDown },
#define ON_WM_RBUTTONUP() \
	{ WM_RBUTTONUP, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnRButtonUp },
#define ON_WM_RBUTTONDBLCLK() \
	{ WM_RBUTTONDBLCLK, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnRButtonDblClk },
#define ON_WM_MBUTTONDOWN() \
	{ WM_MBUTTONDOWN, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnMButtonDown },
#define ON_WM_MBUTTONUP() \
	{ WM_MBUTTONUP, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnMButtonUp },
#define ON_WM_MBUTTONDBLCLK() \
	{ WM_MBUTTONDBLCLK, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, CPoint))OnMButtonDblClk },
#define ON_WM_PARENTNOTIFY() \
	{ WM_PARENTNOTIFY, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, LPARAM))OnParentNotify },
#define ON_WM_MDIACTIVATE() \
	{ WM_MDIACTIVATE, 0, AfxSig_vbWW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(BOOL, CWnd*, CWnd*))OnMDIActivate },
#define ON_WM_RENDERFORMAT() \
	{ WM_RENDERFORMAT, 0, AfxSig_vw, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT))OnRenderFormat },
#define ON_WM_RENDERALLFORMATS() \
	{ WM_RENDERALLFORMATS, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))OnRenderAllFormats },
#define ON_WM_DESTROYCLIPBOARD() \
	{ WM_DESTROYCLIPBOARD, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))OnDestroyClipboard },
#define ON_WM_DRAWCLIPBOARD() \
	{ WM_DRAWCLIPBOARD, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(void))OnDrawClipboard },
#define ON_WM_VSCROLLCLIPBOARD() \
	{ WM_VSCROLLCLIPBOARD, 0, AfxSig_vWww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT))OnVScrollClipboard },
#define ON_WM_HSCROLLCLIPBOARD() \
	{ WM_HSCROLLCLIPBOARD, 0, AfxSig_vWww, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT))OnHScrollClipboard },
#define ON_WM_QUERYNEWPALETTE() \
	{ WM_QUERYNEWPALETTE, 0, AfxSig_bv, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(void))OnQueryNewPalette },
#define ON_WM_PALETTECHANGED() \
	{ WM_PALETTECHANGED, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*))OnPaletteChanged },
#define ON_WM_PALETTEISCHANGING() \
	{ WM_PALETTEISCHANGING, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*))OnPaletteIsChanging },
#define ON_WM_DROPFILES() \
	{ WM_DROPFILES, 0, AfxSig_vh, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(HDROP))OnDropFiles },
#define ON_WM_WINDOWPOSCHANGING() \
	{ WM_WINDOWPOSCHANGING, 0, AfxSig_vPOS, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(WINDOWPOS FAR*))OnWindowPosChanging },
#define ON_WM_WINDOWPOSCHANGED() \
	{ WM_WINDOWPOSCHANGED, 0, AfxSig_vPOS, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(WINDOWPOS FAR*))OnWindowPosChanged },

// printscan\faxsrv\src\sdktools\msvc15\mfc\include\afxpriv.h
#define IS_COMMAND_ID(nID)  ((nID) & 0x8000)
#define ASSERT_VALID_IDR(nIDR) \
	ASSERT((nIDR) != 0 && (nIDR) < 0x8000)

// printscan\faxsrv\src\sdktools\msvc15\mfc\include\winres.h
#define LBS_STANDARD    (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)
#define LB_ADDSTRING    (WM_USER+1)

// printscan\faxsrv\src\setup\win9xupg\inc\oleutils.h
#define DIB_EXT			_T("dib")

// printscan\faxsrv\src\test\inc\t4ctrl.h
#define FW_RESTOREICON  (FW_FOCUS | FW_RESTORE)

// printscan\faxsrv\src\test\src\bvt\vt_bvt\vtprintfax.h
#define DIAL_EXACTLY_CHECK              "&Dial exactly as typed (no prefixes)"

// printscan\faxsrv\src\test\src\cfgwzrdvt\functionality.cpp
#define CURRENT_POLICY (/*COMPARE_USERINFO |*/ COMPARE_SEND | COMPARE_ROUTING_INFO_WHEN_ENABLED)

// printscan\faxsrv\src\test\src\spooler\faxspooler_bvt\queuing.cpp
#define FAX_ACCESS_RIGHTS_USER     (FAX_ACCESS_SUBMIT               |   \
                                    FAX_ACCESS_SUBMIT_NORMAL)

// printscan\faxsrv\src\test\src\xxxunusedxxx\deviceioctls\fileioctl.h
#define FSCTL_HSM_DATA                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 68, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)

// printscan\faxsrv\src\test\src\xxxunusedxxx\deviceioctls\parallel.h
#define ECR_ECP_PIO_MODE           (ECR_ECP_MODE | ECR_ERRINT_DISABLED | ECR_SVC_INT_DISABLED)
#define ECR_EPP_PIO_MODE           (ECR_EPP_MODE | ECR_ERRINT_DISABLED | ECR_SVC_INT_DISABLED)

// printscan\faxsrv\src\test\src\xxxunusedxxx\deviceioctls\sysaudioioctl.cpp
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// printscan\print\drivers\usermode\ddk\samples\oemdll\watermark\common\devmode.h
#define WATER_MARK_DEFAULT_COLOR        RGB(230, 230, 230)

// printscan\print\drivers\usermode\driverui\driverui.h
#define GETUSERDATASIZE(UserData) \
    ( ((PUSERDATA)(UserData))->dwSize )
#define GETUSERDATAITEM(UserData) \
    ( ((PUSERDATA)(UserData))->dwItemID )
#define SETUSERDATAID(pOptItem, dwID) \
    ( ((PUSERDATA)((pOptItem)->UserData))->dwItemID = dwID)
#define SETUSERDATA_SIZE(pOptItem, dwSize) \
    ( ((PUSERDATA)((pOptItem)->UserData))->dwSize = dwSize)
#define SUPPORTS_DUPLEX(pci) \
        ((!_BFeatureDisabled(pci, 0xFFFFFFFF, GID_DUPLEX)) && \
        (GET_PREDEFINED_FEATURE((pci)->pUIInfo, GID_DUPLEX) != NULL))
#define SUPPORTS_DUPLEX(pci) \
        ((_BSupportFeature(pci, GID_DUPLEX, NULL)) && \
        (GET_PREDEFINED_FEATURE(pci->pUIInfo, GID_DUPLEX) != NULL))
#define PRINTER_SUPPORTS_COLLATE(pci) \
        ((!_BFeatureDisabled(pci, 0xFFFFFFFF, GID_COLLATE)) && \
        (GET_PREDEFINED_FEATURE((pci)->pUIInfo, GID_COLLATE) != NULL))
#define PRINTER_SUPPORTS_COLLATE(pci) \
        ((_BSupportFeature(pci, GID_COLLATE, NULL)) && \
        (GET_PREDEFINED_FEATURE(pci->pUIInfo, GID_COLLATE) != NULL))

// printscan\print\drivers\usermode\gpdres\alpsres\alpsres.h
#define bPlaneSendOrderCMY(p) \
    ((p)->fRequestColor && (p)->iCurrentResolution == DPI1200)
#define bPlaneSendOrderMCY(p) \
    (((p)->iPaperQuality == CMDID_PAPERQUALITY_OHP_EXCL_NORMAL) || \
    ((p)->iPaperQuality == CMDID_PAPERQUALITY_OHP_EXCL_FINE))
#define bPlaneSendOrderCMYK(p) \
    (!bPlaneSendOrderCMY(p) && !bPlaneSendOrderMCY(p) && !bPlaneSendOrderYMC(p))

// printscan\print\drivers\usermode\gpdres\apdlres\pdev.h
#define ABS(n) \
    ((n) > 0 ? (n) : -(n))

// printscan\print\drivers\usermode\gpdres\capplres\capplres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))
#define DRVGETDRIVERSETTING(p, t, o, s, n, r) \
    ((p)->pDrvProcs->DrvGetDriverSetting(p, t, o, s, n, r))

// printscan\print\drivers\usermode\gpdres\casn4res\casn4res.c
#define MasterToDevice(p, i) \
     ((i) / ((PMYPDEV)(p))->iUnitFactor)

// printscan\print\drivers\usermode\gpdres\casn4res\pdev.h
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))
#define UNKNOWN_DLFONT_ID (~0)

// printscan\print\drivers\usermode\gpdres\cnl4jres\cnl4jres.c
#define WRITESPOOLBUF(pdevobj, cmd, len) \
	(pdevobj)->pDrvProcs->DrvWriteSpoolBuf(pdevobj, cmd, len)

// printscan\print\drivers\usermode\gpdres\cnl4jres\pdev.h
#define RcidIsDBCSFont(k) ((k) >= 32 && (k) <= 63)
#define RcidIsDBCSVertFont(k) \
((k) == 41 || (k) == 43 || (k) == 45 || (k) == 47 || (k) == 49 ||\
(k) == 51 || (k) == 53 || (k) == 55 || (k) == 57 || (k) == 59 ||\
(k) == 61 || (k) == 63)

// printscan\print\drivers\usermode\gpdres\csn46res\colmatch.h
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\gpdres\csn46res\csn46res.c
#define MasterToDevice(p, i) \
     ((i) / ((PMYPDEV)(p))->iUnitFactor)

// printscan\print\drivers\usermode\gpdres\csn46res\n403diz.h
#define    N403_CCHRGBSIZ        (N403_CCHNUM * sizeof(RGBS))    // Cache table size(RGB)

// printscan\print\drivers\usermode\gpdres\csn46res\n4diz.h
#define    N4_CCHRGBSIZ        (N4_CCHNUM * sizeof(RGBS))   // Table size(RGB)

// printscan\print\drivers\usermode\gpdres\csn46res\pdev.h
#define DRVGETDRIVERSETTING(p, t, o, s, n, r) \
    ((p)->pDrvProcs->DrvGetDriverSetting(p, t, o, s, n, r))
#define DRVGETGPDDATA(p, t, i, b, s, n) \
  ((p)->pDrvProcs->DrvGetGPDData(p, t, i, b, s, n))
#define UNKNOWN_DLFONT_ID (~0)

// printscan\print\drivers\usermode\gpdres\csn5res\colmatch.h
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))
#define sRGBLUTFILESIZ  16L * 1024L             // N501 Buffer size for LUT file read (sRGB)

// printscan\print\drivers\usermode\gpdres\csn5res\comdiz.h
#define KCGBLA              1                               // Black (RGB=0)
#define LUTSIZRGB           LUTSIZ016 * sizeof(RGBS)        // LUT size
#define CCHRGBSIZ           (CCHTBLSIZ * sizeof(RGBS))      // Cache table size(RGB)

// printscan\print\drivers\usermode\gpdres\csn5res\csn5res.c
#define MasterToDevice(p, i) \
     ((i) / ((PMYPDEV)(p))->iUnitFactor)

// printscan\print\drivers\usermode\gpdres\csn5res\pdev.h
#define DRVGETDRIVERSETTING(p, t, o, s, n, r) \
    ((p)->pDrvProcs->DrvGetDriverSetting(p, t, o, s, n, r))
#define DRVGETGPDDATA(p, t, i, b, s, n) \
  ((p)->pDrvProcs->DrvGetGPDData(p, t, i, b, s, n))
#define UNKNOWN_DLFONT_ID (~0)

// printscan\print\drivers\usermode\gpdres\cswinres\cswinres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))
#define DRVGETDRIVERSETTING(p, t, o, s, n, r) \
    ((p)->pDrvProcs->DrvGetDriverSetting(p, t, o, s, n, r))

// printscan\print\drivers\usermode\gpdres\epagcres\epagcres.c
#define WRITESPOOLBUF(p,s,n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf((p),(s),(n)))

// printscan\print\drivers\usermode\gpdres\fmlbpres\fmlbp.h
#define WRITESPOOLBUF(pdevobj, s, n) \
	((pdevobj)->pDrvProcs->DrvWriteSpoolBuf((pdevobj), s, n))
#define	FUFM_MASTER_TO_DEVICE(p,d) \
	((p)->devData.dwResolution * (d) / FUFM_RESOLUTION_MASTER_UNIT)

// printscan\print\drivers\usermode\gpdres\fuxlres\fuxl.h
#define WRITESPOOLBUF(p, s, n) \
	((p)->pDrvProcs->DrvWriteSpoolBuf((p), (s), (n)))
#define	FUXL_MASTER_TO_DEVICE(p,d) \
	((p)->devData.dwResolution * (d) / FUXL_MASTER_UNIT)

// printscan\print\drivers\usermode\gpdres\fxartres\etc\fxart4.c
#define ISVERTFONT(i) ((i) >= 156 && (i) < 180)

// printscan\print\drivers\usermode\gpdres\fxartres\fxartres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))
#define ISVERTFONT(i) ((i) >= 156 && (i) < 162)
#define ISPROPFONT(i) ((i) >= 172 && (i) < 190)
#define BISMARKSBCS(i) ((i) >= 0 && (i) < 0x20)
#define XMoveAbs(p, i) \
{   ((POEM_EXTRADATA)((p)->pOEMDM))->ptlCur.x = (i); \
    XYMoveUpdate(p); }

// printscan\print\drivers\usermode\gpdres\fxmejres\fxmejres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\gpdres\ib87wres\pdev.h
#define WRITESPOOLBUF(p, s, n) \
    (((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n)) == (n))
#define ABS(n) \
    ((n) > 0 ? (n) : -(n))

// printscan\print\drivers\usermode\gpdres\kpdlres\kpdlres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))
#define ABS(n) \
    ((n) > 0 ? (n) : -(n))

// printscan\print\drivers\usermode\gpdres\kpdlres\pdev.h
#define IsColorPlanar(p) \
    ((MONOCHROME == (p)->jColorMode) \
    || (COLOR_3PLANE == (p)->jColorMode))
#define IsColorTrue8dens(p) \
    ((p)->jColorMode == COLOR_24BPP_8)
#define ColorOutDepth(p) \
    (((p)->jColorMode == COLOR_24BPP_2)?1:\
    (((p)->jColorMode == COLOR_24BPP_4)?2:\
    (((p)->jColorMode == COLOR_24BPP_8)?3:1)))

// printscan\print\drivers\usermode\gpdres\kyp5jres\kyp5jres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\gpdres\lggdires\lgcomp.c
#define MOD8(k) ((k) & 7)
#define MOD64(k) ((k) & 63)

// printscan\print\drivers\usermode\gpdres\lggdires\lggdires.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\gpdres\lggs6res\lggs6res.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\gpdres\nc62jres\nc62jres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\gpdres\ncdljres\ncdljres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\gpdres\ncmwjres\ncmwjres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\gpdres\qplkres\qplkres.c
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\gpdres\rpdlres\ddi.c
#define GETDRIVERSETTING(p1, p2, p3, p4, p5, p6) \
    ((p1)->pDrvProcs->DrvGetDriverSetting((p1), (p2), (p3), (p4), (p5), (p6)))

// printscan\print\drivers\usermode\gpdres\rpdlres\nt4\pdev.h
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))
#define DLFONT_SIZE_SBCS11PT_MU     512 // actual value(Arial&Times 600dpi) @Nov/18/98
#define DLFONT_SIZE_SBCS9PT_MU      192 // actual value(Century 400&600dpi) @Nov/18/98

// printscan\print\drivers\usermode\gpdres\rpdlres\nt4\rpdlres.c
#define MASTER_TO_SPACING_UNIT(p, n) \
    ((n) / (p)->nResoRatio)

// printscan\print\drivers\usermode\gpdres\rpdlres\pdev.h
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))
#define DLFONT_SIZE_SBCS11PT_MU     512 // actual value(Arial&Times 600dpi) @Nov/18/98
#define DLFONT_SIZE_SBCS9PT_MU      192 // actual value(Century 400&600dpi) @Nov/18/98

// printscan\print\drivers\usermode\gpdres\rpdlres\rpdlres.c
#define MASTER_TO_SPACING_UNIT(p, n) \
    ((n) / (p)->nResoRatio)

// printscan\print\drivers\usermode\gpdres\tse3jres\pdev.h
#define WRITESPOOLBUF(p, s, n) \
    ((p)->pDrvProcs->DrvWriteSpoolBuf(p, s, n))

// printscan\print\drivers\usermode\inc\afm2ntm.h
#define EOL(a)  \
    (*a == '\r' || *a == '\n')

// printscan\print\drivers\usermode\lib\ufl\api\uflmath.h
#define UFLFixedMant( x )         ( ((UFLSepFixed*)&x)->mant )
#define UFLFixedFraction( x )     ( ((UFLSepFixed*)&x)->frac )
#define UFLTruncFixed( x )                  ( (x) & 0xffff0000 )

// printscan\print\drivers\usermode\lib\ufl\api\ufo.h
#define HOSTFONT_GETNAME(pUFO, ppName, psize, sfindex) \
    (UFLBool)(pUFO)->pUFL->fontProcs.pfHostFontUFLHandler(HOSTFONT_UFLREQUEST_GET_NAME, \
                                                            (pUFO)->hHostFontData, \
                                                            (ppName), (psize), \
                                                            (pUFO)->hClientData, (sfindex))

// printscan\print\drivers\usermode\lib\xcf\xcf_da.h
#define da_INDEX(da,inx) (&da_GROW(da,inx)[inx])
#define da_INDEXI(da,inx) \
	(&da_GROW(da,inx)[((da).cnt=(((inx)>(da).cnt)?(inx):(da).cnt),(inx))])

// printscan\print\drivers\usermode\lib\xcf\xcf_fp.c
#define Odd(x)		((x) & 1)
#define isdigit(c)  ((c) >= '0' && (c) <= '9')

// printscan\print\drivers\usermode\lib\xcf\xcf_txop.h
#define TXOPSIZE(op) (((op)&0xff00)?2:1)

// printscan\print\drivers\usermode\msplot\inc\plotdm.h
#define DM_GDI_ERRORS               (DM_ORIENTATION     |           \
                                     DM_PAPERSIZE       |           \
                                     DM_PAPERLENGTH     |           \
                                     DM_PAPERWIDTH      |           \
                                     DM_SCALE           |           \
                                     DM_COPIES          |           \
                                     DM_DEFAULTSOURCE   |           \
                                     DM_PRINTQUALITY    |           \
                                     DM_COLOR           |           \
                                     DM_DUPLEX          |           \
                                     DM_YRESOLUTION     |           \
                                     DM_TTOPTION        |           \
                                     DM_COLLATE         |           \
                                     DM_FORMNAME)

// printscan\print\drivers\usermode\msplot\plotter\polygon.c
#define SET_PP_WITH_ROP4(pPDev, Rop4)                                       \
    SetPixelPlacement(pPDev, (ROP4_USE_DEST(Rop4)) ? SPP_MODE_EDGE :        \
                                                     SPP_MODE_CENTER)

// printscan\print\drivers\usermode\parsers\ppd\ppdkwd.c
#define INVOCA_VALUE    (VALUETYPE_QUOTED | VALUETYPE_SYMBOL)

// printscan\print\drivers\usermode\parsers\ppd\ppdparse.h
#define MARK_SYMBOL_INVOC(pInvoc)  ((pInvoc)->dwLength |= SYMBOL_INVOCATION_LENGTH)

// printscan\print\drivers\usermode\tools\uni\pfm2ufm\pfmconv.c
#define DO_DJFONTSIMBOLD(pFInData)  ((pFInData->DI.wPrivateData != 0xFFFF) && (pFInData->DI.wPrivateData & MAKE_BOLD))

// printscan\print\drivers\usermode\tools\uni\udgtt\dgtt.c
#define ISQUOTE(c) \
    (!((c) > 0x20 && (c) < 0x7f && (c) != '<' && (c) != '>'))

// printscan\print\drivers\usermode\unidrv2\control\brush.h
#define CACHE_CURRENT_BRUSH(pPDev, pDevBrush) \
    pPDev->GState.CurrentBrush.dwBrushType = pDevBrush->dwBrushType; \
    pPDev->GState.CurrentBrush.iColor = pDevBrush->iColor;  \

// printscan\print\drivers\usermode\unidrv2\font\fmtxtout.c
#define     DEVICE_FONT(pfo, tod) ( (pfo->flFontType & DEVICE_FONTTYPE) || \
                                    (tod.iSubstFace) )

// printscan\print\drivers\usermode\unidrv2\font\truetype.c
#define OTHERWISE       if (!__bError && !__bHandled && (__bHandled = TRUE))
#define FONTISBOLD(pfm) ((pfm)->pIFIMet->fsSelection & FM_SEL_BOLD)
#define FONTISITALIC(pfm) ((pfm)->pIFIMet->fsSelection & FM_SEL_ITALIC)
#define FONTISSIMULATED(flFontType) \
    ((flFontType & FO_SIM_BOLD) || (flFontType & FO_SIM_ITALIC))

// printscan\print\drivers\usermode\unidrv2\font\xtrafont.c
#define FONT_USABLE( fnt, prt ) (((fnt) & (prt)) == (fnt))

// printscan\print\drivers\usermode\unidrv2\inc\pdev.h
#define DRIVER_DEVICEMANAGED(pPDev) ((pPDev->fMode) & PF_DEVICE_MANAGED)

// printscan\print\drivers\usermode\unidrv2\inc\vectorif.h
#define HANDLE_VECTORPROCS_RET(pdev, pfn, retval, args) \
    if ((pdev)->pVectorProcs != NULL && \
        ((PVMPROCS)(pdev)->pVectorProcs)->pfn != NULL ) \
    { \
        (pdev)->devobj.pdevOEM = (pdev)->pVectorPDEV; \
        retval = (((PVMPROCS)(pdev)->pVectorProcs)->pfn) args;\
    }
#define HANDLE_VECTORPROCS(pdev, pfn, args) \
    if ((pdev)->pVectorProcs != NULL && \
        ((PVMPROCS)(pdev)->pVectorProcs)->pfn != NULL ) \
    { \
        (pdev)->devobj.pdevOEM = (pdev)->pVectorPDEV; \
        (((PVMPROCS)(pdev)->pVectorProcs)->pfn) args;\
    }

// printscan\print\drivers\usermode\unidrv2\vector\pclxl\xlbmpcvt.h
#define GET_COLOR_TABLE(pxlo) \
        (((pxlo)->flXlate & XO_TABLE) ? \
        ((pxlo)->pulXlate ? (pxlo)->pulXlate : XLATEOBJ_piVector(pxlo)) : NULL)

// printscan\print\drivers\usermode\unidrv2\vector\pclxl\xlpdev.h
#define GET_COLOR_TABLE(pxlo) \
        (((pxlo)->flXlate & XO_TABLE) ? \
           ((pxlo)->pulXlate ? (pxlo)->pulXlate : XLATEOBJ_piVector(pxlo)) : \
           NULL)

// printscan\print\spooler\localspl\separate.c
#define CJ_DIB16( cx, cy ) (CJ_DIB16_SCAN(cx) * (cy))

// printscan\print\spooler\monitors\tcpmon\tcpmonui\helpids.h
#define IDH_PORT_NAME	11001	// Port Settings: "&Port Name:" (Static) (Edit) (ctrl id 1001, 1026)
#define IDH_PRINTER_NAME_IP_ADDRESS	11002	// Port Settings: "Printer Name or IP &Address:" (Static) (Edit) (ctrl id 1000, 1027)
#define IDH_PROTOCOL_RAW	11003	// Port Settings: "&Raw" (Button) (ctrl id 1006)
#define IDH_PROTOCOL_LPR	11004	// Port Settings: "&LPR" (Button) (ctrl id 1007)
#define IDH_RAW_SETTINGS_PORT_NUMBER	11005	// Port Settings: "Port &Number:" (Static) (Edit) (ctrl id 1008, 1017)
#define IDH_SNMP_STATUS_ENABLED	11008	// Port Settings: "&SNMP Status Enabled" (Button) (ctrl id 1010)
#define IDH_SNMP_COMMUNITY_NAME	11009	// Port Settings: "&Community Name:" (Static) (Edit) (ctrl id 1011, 1021)
#define IDH_SNMP_DEVICE_INDEX	11010	// Port Settings: "SNMP &Device Index:" (Static) (Edit) (ctrl id 1012, 1022)

// printscan\print\spooler\oleprn\resource.h
#define ERROR_TRUST_E_NOSIGNATURE      (TRUST_E_NOSIGNATURE & 0xFFFF)
#define ERROR_TRUST_E_BAD_DIGEST       (TRUST_E_BAD_DIGEST & 0xFFFF)

// printscan\print\spooler\spllib\webipp.h
#define IPP_RET_PRINTJOB        (IPP_RESPONSE | IPP_REQ_PRINTJOB)
#define IPP_RET_CANCELJOB       (IPP_RESPONSE | IPP_REQ_CANCELJOB)
#define IPP_RET_GETJOB          (IPP_RESPONSE | IPP_REQ_GETJOB)
#define IPP_RET_ENUJOB          (IPP_RESPONSE | IPP_REQ_ENUJOB)
#define IPP_RET_GETPRN          (IPP_RESPONSE | IPP_REQ_GETPRN)
#define IPP_RET_PAUSEJOB        (IPP_RESPONSE | IPP_REQ_PAUSEJOB)
#define IPP_RET_RESUMEJOB       (IPP_RESPONSE | IPP_REQ_RESUMEJOB)
#define IPP_RET_RESTARTJOB      (IPP_RESPONSE | IPP_REQ_RESTARTJOB)
#define IPP_RET_PAUSEPRN        (IPP_RESPONSE | IPP_REQ_PAUSEPRN)
#define IPP_RET_RESUMEPRN       (IPP_RESPONSE | IPP_REQ_RESUMEPRN)
#define IPP_RET_CANCELPRN       (IPP_RESPONSE | IPP_REQ_CANCELPRN)
#define IPP_RET_FORCEAUTH       (IPP_RESPONSE | IPP_REQ_FORCEAUTH)

// printscan\print\spooler\spoolss\client\winspool.c
#define DM_MATCH( dm, sp )  ((((sp)+50)/100-dm)<15&&(((sp)+50)/100-dm)>-15)
#define DM_PAPER_WL         (DM_PAPERWIDTH | DM_PAPERLENGTH)

// printscan\print\spooler\wpnpinst\wow\inc\commdlg.h
#define CF_BOTH 		     (CF_SCREENFONTS | CF_PRINTERFONTS)

// printscan\print\spooler\wpnpinst\wow\inc\ddeml.h
#define     XTYP_ADVSTART           (0x0030 | XCLASS_BOOL          )
#define     XTYP_ADVSTOP            (0x0040 | XCLASS_NOTIFICATION)
#define     XTYP_XACT_COMPLETE      (0x0080 | XCLASS_NOTIFICATION  )
#define     XTYP_REQUEST            (0x00B0 | XCLASS_DATA          )

// printscan\print\spooler\wpnpinst\wow\inc\mmsystem.h
#define DIBINDEX(n)     MAKELONG((n),0x10FF)

// printscan\print\spooler\wpnpinst\wow\inc\penwin.h
#define FIsUpAppGesture(syv)   (syv >= SYV_CIRCLEUPA && syv <= SYV_CIRCLEUPZ)
#define PDK_SWITCHES           (PDK_DOWN|PDK_BARREL1|PDK_BARREL2|PDK_BARREL3)
#define MAP_GESTOGES				(RCRT_GESTURE|RCRT_GESTURETRANSLATED)
#define MAP_GESTOVKEYS			(RCRT_GESTURETOKEYS|RCRT_ALREADYPROCESSED)
#define IsGestureToGesture(lprcresult)	(((lprcresult)->wResultstype & MAP_GESTOGES \
													 ) == MAP_GESTOGES)
#define IsGestureToVkeys(lprcresult)	(((lprcresult)->wResultstype & MAP_GESTOVKEYS \
													 ) == MAP_GESTOVKEYS)
#define SetAlreadyProcessed(lprcresult) ((lprcresult)->wResultsType = ((lprcresult)->wResultsType \
														& ~RCRT_GESTURETOKEYS) | RCRT_ALREADYPROCESSED)

// printscan\print\spooler\wpnpinst\wow\inc\printer.h
#define GHND    (GMEM_MOVEABLE | GMEM_ZEROINIT)

// printscan\print\spooler\wpnpinst\wow\inc\prsht.h
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
#define ID_PSREBOOTSYSTEM       (ID_PSRESTARTWINDOWS | 0x1)

// printscan\print\spooler\wpnpinst\wow\inc\setupx.h
#define DriveAtoI( chDrv )      ((int)(chDrv & 31))
#define VCPFL_BACKUPANDCOPY     (VCPFL_BACKUP | VCPFL_COPY)
#define GENINSTALL_DO_INIREG    (GENINSTALL_DO_INI | \
                                 GENINSTALL_DO_REG | \
                                 GENINSTALL_DO_INI2REG)

// printscan\print\spooler\wpnpinst\wow\inc\stdio.h
#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])
#define stdaux (&_iob[3])
#define stdprn (&_iob[4])

// printscan\print\spooler\wpnpinst\wow\inc\style.h
#define LBS_STANDARD      (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

// printscan\print\spooler\wpnpinst\wow\inc\windows.h
#define GHND                (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define LHND                (LMEM_MOVEABLE | LMEM_ZEROINIT)
#define PALETTERGB(r,g,b)   (0x02000000L | RGB(r,g,b))
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
#define EM_GETRECT              (WM_USER+2)
#define EM_SETRECT              (WM_USER+3)
#define EM_SETRECTNP            (WM_USER+4)
#define EM_SCROLL               (WM_USER+5)     /* ;Internal */
#define EM_LINESCROLL           (WM_USER+6)
#define EM_GETMODIFY            (WM_USER+8)
#define EM_SETMODIFY            (WM_USER+9)
#define EM_LINEINDEX            (WM_USER+11)
#define EM_SETHANDLE            (WM_USER+12)
#define EM_GETHANDLE            (WM_USER+13)
#define EM_GETTHUMB             (WM_USER+14)    /* ;Internal */
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
#define LB_DIR                 (WM_USER+14)
#define LB_GETTOPINDEX         (WM_USER+15)
#define LB_GETSELITEMS         (WM_USER+18)
#define LB_SETTABSTOPS         (WM_USER+19)
#define LB_GETHORIZONTALEXTENT (WM_USER+20)
#define LB_SETHORIZONTALEXTENT (WM_USER+21)
#define LB_SETCOLUMNWIDTH      (WM_USER+22)
#define LB_ADDFILE             (WM_USER+23)     /* ;Internal */
#define LB_SETTOPINDEX         (WM_USER+24)
#define LB_GETITEMRECT         (WM_USER+25)
#define LB_GETITEMDATA         (WM_USER+26)
#define LB_SETITEMDATA         (WM_USER+27)
#define LB_SETANCHORINDEX      (WM_USER+29)     /* ;Internal */
#define LB_GETANCHORINDEX      (WM_USER+30)     /* ;Internal */
#define LB_SETCARETINDEX       (WM_USER+31)
#define LB_GETCARETINDEX       (WM_USER+32)
#define LB_SETITEMHEIGHT       (WM_USER+33)
#define LB_GETITEMHEIGHT       (WM_USER+34)

// printscan\ui\camdlg\camdlg.cpp
#define TQ_GETTHUMBNAIL (WM_USER+2)
#define PWM_POSTINIT         (WM_USER+1)
#define PWM_CHANGETOPARENT   (WM_USER+2)
#define PWM_WIAEVENT         (WM_USER+7)

// printscan\ui\compstui\resource.h
#define GSBUF_ADD_SPACE(c)      GSBufAddSpace(&GSBuf, c)
#define GSBUF_ADDNUM(n,s)       GSBufAddNumber(&GSBuf,n,s)

// printscan\ui\compstui\treeview.c
#define ITVGF_BPCL      (ITVGF_BOLD | ITVGF_COLLAPSE)

// printscan\ui\compstui\treeview.h
#define PIDX_INTOPTITEM(pTVWnd,i)   (&((pTVWnd)->IntOptItem[i-INTIDX_FIRST]))
#define GET_TVLP(l)                 (*((PTVLP)&(l)))
#define GET_PITEMDMPUB(p, i, Idx)                                           \
    ((((i)<=DMPUB_LAST) && (((Idx)=(p)->DMPubIdx[(i)-DMPUB_FIRST])!=0xFFFF))\
        ? ((p)->ComPropSheetUI.pOptItem + (Idx)) : NULL)
#define GET_POPTTYPE(pi)        (((pi)->pOptType) ? (pi)->pOptType :        \
                                                    &OptTypeHdrPush)

// printscan\ui\inc\pviewids.h
#define PWM_SETRESOLUTION         (WM_USER+601)
#define PWM_CLEARSELECTION            (WM_USER+602)
#define PWM_GETIMAGESIZE          (WM_USER+603)
#define PWM_GETRESOLUTION         (WM_USER+606)
#define PWM_GETBORDERSIZE         (WM_USER+607)
#define PWM_GETHANDLESIZE         (WM_USER+608)
#define PWM_GETBGALPHA            (WM_USER+609)
#define PWM_GETHANDLETYPE         (WM_USER+610)
#define PWM_SETBORDERSIZE         (WM_USER+611)
#define PWM_SETHANDLESIZE         (WM_USER+612)
#define PWM_SETBGALPHA            (WM_USER+613)
#define PWM_SETHANDLETYPE         (WM_USER+614)
#define PWM_GETSELEXTENT          (WM_USER+617)
#define PWM_SELECTIONDISABLED     (WM_USER+620)
#define PWM_DISABLESELECTION      (WM_USER+621)
#define PWM_DETECTREGIONS         (WM_USER+622)
#define PWM_GETBKCOLOR            (WM_USER+623)
#define PWM_SETBKCOLOR            (WM_USER+624)
#define PWM_SETDEFASPECTRATIO     (WM_USER+625)
#define PWM_SETBORDERSTYLE        (WM_USER+628)
#define PWM_SETBORDERCOLOR        (WM_USER+629)
#define PWM_SETHANDLECOLOR        (WM_USER+630)
#define PWM_GETCLIENTSIZE         (WM_USER+631)
#define PWM_SETSELEXTENT          (WM_USER+637)
#define PWM_SETPROGRESS          (WM_USER+639)
#define PWM_GETPROGRESS          (WM_USER+640)
#define PWM_SETUSERCHANGEDSELECTION (WM_USER+641)
#define PWM_GETUSERCHANGEDSELECTION (WM_USER+642)

// printscan\ui\photowiz\photosel.h
#define PSP_MSG_SELECT_ITEM         (WM_USER+54)    // wParam = index of item to select

// printscan\ui\prevwnd\prevwnd.cpp
#define DEFAULT_SELECTED_HANDLE_FILL_COLOR     RGB(0,128,0)
#define DEFAULT_UNSELECTED_HANDLE_FILL_COLOR   RGB(128,0,0)
#define DEFAULT_SELECTED_BORDER_COLOR          RGB(0,0,0)
#define DEFAULT_UNSELECTED_BORDER_COLOR        RGB(0,0,0)
#define DEFAULT_SELECTION_HANDLE_SHADOW        RGB(128,128,128)
#define DEFAULT_SELECTION_HANDLE_HIGHLIGHT     RGB(255,255,255)

// printscan\ui\printui\browse.hxx
#define SEND_BROWSE_THREAD_REQUEST(pBrowseDlgData, ReqId, pEnumName, pEnumObj) \
    (pBrowseDlgData)->RequestId = ReqId;            \
    (pBrowseDlgData)->pEnumerateName = pEnumName;   \
    (pBrowseDlgData)->pEnumerateObject = pEnumObj;  \
    SetEvent( (pBrowseDlgData)->Request )
#define RECEIVE_BROWSE_THREAD_REQUEST(pBrowseDlgData, ReqId, pEnumName, pEnumObj)   \
    WaitForSingleObject( (pBrowseDlgData)->Request, INFINITE ), \
    ENTER_CRITICAL( pBrowseDlgData ),               \
    ReqId = (pBrowseDlgData)->RequestId,            \
    pEnumName = (pBrowseDlgData)->pEnumerateName,   \
    pEnumObj = (pBrowseDlgData)->pEnumerateObject,  \
    LEAVE_CRITICAL( pBrowseDlgData )

// printscan\ui\printui\detect.hxx
#define DEFINE_COPY_ASSIGNMENT( Type )          \
            Type( const Type & );               \
            Type & operator =( const Type & )

// printscan\ui\printui\prhlpids.h
#define IDH_PPGENL_COMMENT                1020       // General: "" (Edit), "&Comment:" (Static) (ctrl id 1049, 3005)
#define IDH_PPGENL_PREFERENCES_PERSONAL   1100       // General: "Settin&gs..." (Button) (ctrl id 1031)
#define IDH_PPGENL_MODEL                  1030       // General: "M&odel:" (Static) (Edit) (ctrl id 4632, 4633)
#define IDH_PORTS_ADD                    1210       // Ports: "Add Por&t..." (Button) (ctrl id 3101)
#define IDH_PP_PORTS_ENABLE_POOLING      1250       // Ports: "E&nable printer pooling" (Button) (ctrl id 1052)
#define IDH_PORTS_DELETE                 1220       // Ports: "&Delete Port" (Button) (ctrl id 3102)
#define IDH_PORTS_CONFIGURE              1230       // Ports: "&Configure Port..." (Button) (ctrl id 3103)
#define IDH_PORTS_ENABLE_BIDIRECTIONAL   1240       // Ports: "&Enable bidirectional support" (Button) (ctrl id 3105)
#define IDH_PRINTERPORTS_NEW_PORT           1580       // Printer Ports: "New &Port..." (Button) (ctrl id 4308)
#define IDH_PPADV_START_PRINTING_IMMEDIATELY       1390       // Scheduling: "Start printing &immediately" (Button) (ctrl id 3223)
#define IDH_PPADV_ALWAYS                           1300       // Scheduling: "Al&ways" (Button) (ctrl id 3200)
#define IDH_PPADV_HOLD_MISMATCHED                  1410       // Scheduling: "&Hold mismatched documents" (Button) (ctrl id 3224)
#define IDH_PPADV_FROM_TO                          1310       // Scheduling: "&From" (Button) and Scheduling: "To" (Static) (ctrl id 3201, 3014)
#define IDH_PPADV_PRINT_SPOOLED_DOCS_FIRST         1420       // Scheduling: "P&rint spooled documents first" (Button) (ctrl id 3225)
#define IDH_PPADV_KEEP_PRINTED_JOBS                1430       // Scheduling: "&Keep documents after they have printed" (Button) (ctrl id 3226)
#define IDH_PPADV_SPOOL_PRINT_DOCS                 1370       // Scheduling: "&Spool print documents so program finishes printing faster" (Button) (ctrl id 3220)
#define IDH_PPADV_PRINT_DIRECTLY                   1400       // Scheduling: "Print &directly to the printer" (Button) (ctrl id 3221)
#define IDH_PPADV_NEW_DRIVER                       1360       // General: "&New Driver..." (Button) (ctrl id 3003)
#define IDH_PPADV_DRIVER                           1350       // General: "Dr&iver:" (Static) (ComboBox) (ctrl id 1051, 1045)
#define IDH_PPADV_ADVPRINT_FEATURES                1440       // Advanced: "&Enable advanced printing features" (Button)
#define IDH_PPADV_PRINTING_DEFAULTS                1450       // General: "Setti&ngs..." (Button) (ctrl id 4406, 1145)
#define IDH_PPADV_PRINT_PROCESSOR                  1460       // General: "P&rint Processor..." (Button) (ctrl id 3009)
#define IDH_PPSHARED_NOT                  1150       // Sharing: "N&ot shared" (Button) (ctrl id 3227, 4576)
#define IDH_PPSHARED_AS                   1160       // Sharing: "&Shared as:" (Button) (ctrl id 3228)
#define IDH_PPSHARED_ADDITIONAL_DRIVERS   1190       // Sharing: "A&dditional Drivers..." (Button) (ctrl id 1140)
#define IDH_DPGENL_JOB_START_END         2000       // General: "Only &from" (Button) (ctrl id 4201, 3568)
#define IDH_DPGENL_JOB_ALWAYS            1990       // General: "No time &restriction" (Button) (ctrl id 4232)
#define IDH_PSFORMS_WIDTH          1670       // Forms: "&Width:" (Static), (Edit) (ctrl id 4604, 4605)
#define IDH_PSFORMS_HEIGHT         1680       // Forms: "&Height:" (Static), (Edit) (ctrl id 4606, 4607)
#define IDH_PSFORMS_LEFT           1690       // Forms: "&Left:" (Static), (Edit) (ctrl id 4608, 4609)
#define IDH_PSFORMS_RIGHT          1700       // Forms: "&Right:" (Static), (Edit) (ctrl id 4610, 4611)
#define IDH_PSFORMS_TOP            1710       // Forms: "&Top:" (Static), (Edit) (ctrl id 4612, 4613)
#define IDH_PSFORMS_BOTTOM         1720       // Forms: "&Bottom:" (Static), (Edit) (ctrl id 4614, 4615)
#define IDH_PSFORMS_SAVEFORM       1730       // Forms: "&Save Form" (Button) (ctrl id 4616)
#define IDH_PSFORMS_DELETE         1620       // Forms: "&Delete" (Button) (ctrl id 4617)
#define IDH_PSFORMS_UNIT_METRIC    1650       // Forms: "&Metric" (Button) (ctrl id 4620)
#define IDH_PSFORMS_UNIT_ENGLISH   1660       // Forms: "&English" (Button) (ctrl id 4621)
#define IDH_PSFORMS_CREATE_NEW     1640       // Forms: "&Create a New Form" (Button) (ctrl id 4622)
#define IDH_PORTS_ADD                    1210       // Ports: "Add Por&t..." (Button) (ctrl id 3101)
#define IDH_PORTS_DELETE                 1220       // Ports: "&Delete Port" (Button) (ctrl id 3102)
#define IDH_PORTS_CONFIGURE              1230       // Ports: "&Configure Port..." (Button) (ctrl id 3103)
#define IDH_PORTS_ENABLE_BIDIRECTIONAL   1240       // Ports: "&Enable bidirectional support" (Button) (ctrl id 3105)
#define IDH_PSDRIVERS_UPDATE           1780       // Drivers: "&Update" (Button) (ctrl id 1105)
#define IDH_PSDRIVERS_PROPERTIES       1790       // Drivers: "Prop&erties..." (Button) (ctrl id 1091)
#define IDH_PSDRIVERS_ADD              1760       // Drivers: "A&dd..." (Button) (ctrl id 1080)
#define IDH_PSDRIVERS_REMOVE           1770       // Drivers: "&Remove" (Button) (ctrl id 1081)
#define IDH_PSADV_REMOTE_JOB_NOTIFY             1850       // Advanced: "No&tify when remote documents are printed" (Button) (ctrl id 1013)
#define IDH_PSADV_REMOTE_DOCS_NOTIFY_COMPUTER   1860       // Advanced: "No&tify computer rather than user when remote documents are printed" (Button) (ctrl id 4320)
#define IDH_PSADV_SPOOL_FOLDER                  1800       // Advanced: "" (Edit), &Spool folder (ctrl id 4316, 1008)
#define IDH_PSADV_REMOTE_JOB_ERRORS_BEEP        1840       // Advanced: "&Beep on errors of remote documents" (Button) (ctrl id 1011)
#define IDH_MMC_DM_SETTINGS_PRINTERS_FOLDER   2301       // Settings: "&Printers Folder" (Button) (ctrl id 1141)
#define IDH_CTP_PRINTER                     76000       // Connect to Printer: "&Printer:" (Static) and (Edit) (ctrl id 4589, 4578)
#define IDH_CTP_EXPAND_DEFAULT              76020       // Connect to Printer: "&Expand by Default" (Button) (ctrl id 4588)

// printscan\ui\printui\setup.hxx
#define DEFINE_COPY_ASSIGNMENT( Type )          \
            Type( const Type & );               \
            Type & operator =( const Type & )

// printscan\ui\scanlib\scandlg.cpp
#define PWM_WIAEVENT (WM_USER+1)

// printscan\ui\select\choosdlg.h
#define PWM_WIA_EVENT (WM_USER+111)

// printscan\ui\shellext\src\util.h
#define DC_INITIALIZE       (WM_USER+1)
#define DC_GETDEVICE        (WM_USER+3)  // wParam = lpcr, lParam = Handle of event to signal

// printscan\ui\ssmypics\sscommon\cfgdlg.h
#define UWM_CONFIG_CHANGED (WM_USER+1300)

// printscan\ui\ssmypics\ssmypics\ssmypics.cpp
#define UWM_FINDFILE    (WM_USER+1301)

// printscan\ui\ssmypics\sstest\sstest.cpp
#define UWM_FINDFILE               (WM_USER+1301)

// printscan\ui\unittest\testacqd\main.cpp
#define PWM_DISPLAYNEWIMAGE (WM_USER+122)

// printscan\ui\wiaacmgr\acqmgrcw.h
#define PWM_POSTINITIALIZE       (WM_USER+0x0001)

// printscan\ui\wiaacmgr\comprog.cpp
#define PWM_SETDEFBUTTON (WM_USER+1)

// printscan\ui\wiaacmgr\thrdntfy.h
#define WTM_HANDLE_NOTIFY_MESSAGE( _msg, _handler )\
if (_pThreadNotificationMessage->Message() == (_msg))\
    {\
        _handler( _msg, _pThreadNotificationMessage );\
    }

// printscan\ui\wiadefui\contrast.h
#define BCPWM_SETBRIGHTNESS (WM_USER+3141) // wParam=0, lParam=(int)brightness
#define BCPWM_SETCONTRAST   (WM_USER+3142) // wParam=0, lParam=(int)contrast
#define BCPWM_SETINTENT     (WM_USER+3143) // wParam=0, lParam=(int)intent

// printscan\ui\wiadefui\progdlg.cpp
#define PDM_SHOW           (WM_USER+1)
#define PDM_SETTITLE       (WM_USER+3)
#define PDM_SETMESSAGE     (WM_USER+4)
#define PDM_SETPERCENT     (WM_USER+5)

// printscan\ui\wiavidd\videodlg.h
#define TQ_GETTHUMBNAIL (WM_USER+2)
#define PWM_POSTINIT         (WM_USER+1)
#define PWM_CHANGETOPARENT   (WM_USER+2)
#define VD_NEW_ITEM    (WM_USER+20)
#define VD_DEVICE_DISCONNECTED (WM_USER+22)

// printscan\wia\common\jpeglib\jmemdos.cpp
#define ODD(X)  (((X) & 1L) != 0)

// printscan\wia\common\jpeglib\jmorecfg.h
#define GETJSAMPLE(value)  ((int) (value) & 0xFF)
#define GETJOCTET(value)  ((value) & 0xFF)

// printscan\wia\core\server\wiapropp.h
#define  WIA_PROP_RWNC (WIA_PROP_RW   | WIA_PROP_NONE | WIA_PROP_CACHEABLE)
#define  WIA_PROP_RNC  (WIA_PROP_READ | WIA_PROP_NONE | WIA_PROP_CACHEABLE)

// printscan\wia\drivers\camera\ircamera\irtranp\bftp.h
#define  Match4( pName1, pName2 )    \
             (  ((pName1)[0] == (pName2)[0]) \
             && ((pName1)[1] == (pName2)[1]) \
             && ((pName1)[2] == (pName2)[2]) \
             && ((pName1)[3] == (pName2)[3]) )

// printscan\wia\drivers\scanner\microsft\testdev\defprop.h
#define INITIAL_FORMAT             (GUID*) &WiaImgFmt_MEMORYBMP

// printscan\wia\drivers\scanner\microsft\wiafbdrv\devctrl.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// printscan\wia\drivers\scanner\microsft\wiafbdrv\wiaprop.h
#define INITIAL_FORMAT             (GUID*) &WiaImgFmt_MEMORYBMP

// printscan\wia\drivers\scanner\microsft\wiascanr\wiaprop.h
#define INITIAL_FORMAT             (GUID*) &WiaImgFmt_MEMORYBMP

// printscan\wia\drivers\scanner\microsft\wiascroll\wiaprop.h
#define INITIAL_FORMAT             (GUID*) &WiaImgFmt_MEMORYBMP

// printscan\wia\drivers\video\usd\defprop.h
#define VT_V_UI1   (VT_VECTOR | VT_UI1)

// printscan\wia\inc\sti.h
#define IStillImage_Release(p)                  (p)->lpVtbl->Release(p)
#define IStiDevice_Release(p)                   (p)->lpVtbl->Release(p)

// printscan\wia\inc\stipriv.h
#define fLimpFF(f1, f2) (!(f1) || (f2))
#define __Class_Vtbl(C, I)              &c_##I##_##C##VI.vtbl

// printscan\wia\inc\stisvc.h
#define STI_SVC_SERVICE_TYPE    (SERVICE_WIN32_SHARE_PROCESS | SERVICE_INTERACTIVE_PROCESS)

// printscan\wia\inc\stiusd.h
#define IStiDeviceControl_Release(p)               (p)->lpVtbl->Release(p)
#define IStiUSD_Release(p)               (p)->lpVtbl->Release(p)

// printscan\wia\inc\wiadef.h
#define WIA_PROP_RW              (WIA_PROP_READ | WIA_PROP_WRITE)

// printscan\wia\kernel\usbscan\usbd_api.h
#define UsbBuildAbortPipeRequest(               \
urb,                                            \
length,                                         \
handle) {                                       \
        (urb)->UrbHeader.Function = URB_FUNCTION_ABORT_PIPE;    \
        (urb)->UrbHeader.Length = (USHORT)length;               \
        (urb)->UrbPipeRequest.PipeHandle = handle;              \
}

// printscan\wia\test\devctrl\pmxe3.h
#define FILE_READ_ACCESS          ( 0x0001 )    // file & pipe
#define FILE_WRITE_ACCESS         ( 0x0002 )    // file & pipe

// public\ddk\inc\ntddk.h
#define FILE_READ_EA              ( 0x0008 )    // file & directory
#define FILE_WRITE_EA             ( 0x0010 )    // file & directory
#define DIRECTORY_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0xF)

// public\ddk\inc\ntddvdeo.h
#define VIDEO_MODE_MANAGED_PALETTE  0x0008  // 0 = Palette is fixed (must be

// public\ddk\inc\ntimage.h
#define IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffff)
#define IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)

// public\ddk\inc\sti.h
#define IStillImage_Release(p)                  (p)->lpVtbl->Release(p)

// public\ddk\inc\tdikrnl.h
#define TdiBuildAssociateAddress(Irp, DevObj, FileObj, CompRoutine, Contxt, AddrHandle)                           \
    {                                                                        \
        PTDI_REQUEST_KERNEL_ASSOCIATE p;                                     \
        PIO_STACK_LOCATION _IRPSP;                                           \
        if ( CompRoutine != NULL) {                                          \
            IoSetCompletionRoutine( Irp, CompRoutine, Contxt, TRUE, TRUE, TRUE);\
        } else {                                                             \
            IoSetCompletionRoutine( Irp, NULL, NULL, FALSE, FALSE, FALSE);   \
        }                                                                    \
        _IRPSP = IoGetNextIrpStackLocation (Irp);                            \
        _IRPSP->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;              \
        _IRPSP->MinorFunction = TDI_ASSOCIATE_ADDRESS;                       \
        _IRPSP->DeviceObject = DevObj;                                       \
        _IRPSP->FileObject = FileObj;                                        \
        p = (PTDI_REQUEST_KERNEL_ASSOCIATE)&_IRPSP->Parameters;              \
        p->AddressHandle = (HANDLE)(AddrHandle);                             \
    }
#define TdiBuildDisassociateAddress(Irp, DevObj, FileObj, CompRoutine, Contxt)                                    \
    {                                                                        \
        PTDI_REQUEST_KERNEL_DISASSOCIATE p;                                  \
        PIO_STACK_LOCATION _IRPSP;                                           \
        if ( CompRoutine != NULL) {                                          \
            IoSetCompletionRoutine( Irp, CompRoutine, Contxt, TRUE, TRUE, TRUE);\
        } else {                                                             \
            IoSetCompletionRoutine( Irp, NULL, NULL, FALSE, FALSE, FALSE);   \
        }                                                                    \
        _IRPSP = IoGetNextIrpStackLocation (Irp);                            \
        _IRPSP->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;              \
        _IRPSP->MinorFunction = TDI_DISASSOCIATE_ADDRESS;                    \
        _IRPSP->DeviceObject = DevObj;                                       \
        _IRPSP->FileObject = FileObj;                                        \
        p = (PTDI_REQUEST_KERNEL_DISASSOCIATE)&_IRPSP->Parameters;           \
    }
#define TdiBuildSendDatagram(Irp, DevObj, FileObj, CompRoutine, Contxt, MdlAddr, SendLen, SendDatagramInfo)\
    {                                                                        \
        PTDI_REQUEST_KERNEL_SENDDG p;                                        \
        PIO_STACK_LOCATION _IRPSP;                                           \
        if ( CompRoutine != NULL) {                                          \
            IoSetCompletionRoutine( Irp, CompRoutine, Contxt, TRUE, TRUE, TRUE);\
        } else {                                                             \
            IoSetCompletionRoutine( Irp, NULL, NULL, FALSE, FALSE, FALSE);   \
        }                                                                    \
        _IRPSP = IoGetNextIrpStackLocation (Irp);                            \
        _IRPSP->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;              \
        _IRPSP->MinorFunction = TDI_SEND_DATAGRAM;                           \
        _IRPSP->DeviceObject = DevObj;                                       \
        _IRPSP->FileObject = FileObj;                                        \
        p = (PTDI_REQUEST_KERNEL_SENDDG)&_IRPSP->Parameters;                 \
        p->SendLength = SendLen;                                             \
        p->SendDatagramInformation = SendDatagramInfo;                       \
        Irp->MdlAddress = MdlAddr;                                           \
    }
#define TdiBuildSetEventHandler(Irp, DevObj, FileObj, CompRoutine, Contxt, InEventType, InEventHandler, InEventContext) \
    {                                                                        \
        PTDI_REQUEST_KERNEL_SET_EVENT p;                                     \
        PIO_STACK_LOCATION _IRPSP;                                           \
        if ( CompRoutine != NULL) {                                          \
            IoSetCompletionRoutine( Irp, CompRoutine, Contxt, TRUE, TRUE, TRUE);\
        } else {                                                             \
            IoSetCompletionRoutine( Irp, NULL, NULL, FALSE, FALSE, FALSE);   \
        }                                                                    \
        _IRPSP = IoGetNextIrpStackLocation (Irp);                            \
        _IRPSP->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;              \
        _IRPSP->MinorFunction = TDI_SET_EVENT_HANDLER;                       \
        _IRPSP->DeviceObject = DevObj;                                       \
        _IRPSP->FileObject = FileObj;                                        \
        p = (PTDI_REQUEST_KERNEL_SET_EVENT)&_IRPSP->Parameters;              \
        p->EventType = InEventType;                                          \
        p->EventHandler = (PVOID)InEventHandler;                             \
        p->EventContext = (PVOID)InEventContext;                             \
    }
#define TdiBuildQueryInformation(Irp, DevObj, FileObj, CompRoutine, Contxt, QType, MdlAddr)\
    {                                                                        \
        PTDI_REQUEST_KERNEL_QUERY_INFORMATION p;                             \
        PIO_STACK_LOCATION _IRPSP;                                           \
        Irp->MdlAddress = MdlAddr;                                           \
        if ( CompRoutine != NULL) {                                          \
            IoSetCompletionRoutine( Irp, CompRoutine, Contxt, TRUE, TRUE, TRUE);\
        } else {                                                             \
            IoSetCompletionRoutine( Irp, NULL, NULL, FALSE, FALSE, FALSE);   \
        }                                                                    \
        _IRPSP = IoGetNextIrpStackLocation (Irp);                            \
        _IRPSP->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;              \
        _IRPSP->MinorFunction = TDI_QUERY_INFORMATION;                       \
        _IRPSP->DeviceObject = DevObj;                                       \
        _IRPSP->FileObject = FileObj;                                        \
        p = (PTDI_REQUEST_KERNEL_QUERY_INFORMATION)&_IRPSP->Parameters;      \
        p->QueryType = (ULONG)QType;                                         \
        p->RequestConnectionInformation = NULL;                              \
    }
#define TdiBuildSetInformation(Irp, DevObj, FileObj, CompRoutine, Contxt, SType, MdlAddr)\
    {                                                                        \
        PTDI_REQUEST_KERNEL_SET_INFORMATION p;                                          \
        PIO_STACK_LOCATION _IRPSP;                                           \
        Irp->MdlAddress = MdlAddr;                                           \
        if ( CompRoutine != NULL) {                                          \
            IoSetCompletionRoutine( Irp, CompRoutine, Contxt, TRUE, TRUE, TRUE);\
        } else {                                                             \
            IoSetCompletionRoutine( Irp, NULL, NULL, FALSE, FALSE, FALSE);   \
        }                                                                    \
        _IRPSP = IoGetNextIrpStackLocation (Irp);                            \
        _IRPSP->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;              \
        _IRPSP->MinorFunction = TDI_SET_INFORMATION;                         \
        _IRPSP->DeviceObject = DevObj;                                       \
        _IRPSP->FileObject = FileObj;                                        \
        p = (PTDI_REQUEST_KERNEL_SET_INFORMATION)&_IRPSP->Parameters;                   \
        p->SetType = (ULONG)SType;                                           \
        p->RequestConnectionInformation = NULL;                              \
    }
#define TdiBuildAction(Irp, DevObj, FileObj, CompRoutine, Contxt, MdlAddr)\
    {                                                                        \
        PIO_STACK_LOCATION _IRPSP;                                           \
        if ( CompRoutine != NULL) {                                          \
            IoSetCompletionRoutine( Irp, CompRoutine, Contxt, TRUE, TRUE, TRUE);\
        } else {                                                             \
            IoSetCompletionRoutine( Irp, NULL, NULL, FALSE, FALSE, FALSE);   \
        }                                                                    \
        _IRPSP = IoGetNextIrpStackLocation (Irp);                            \
        _IRPSP->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;              \
        _IRPSP->MinorFunction = TDI_ACTION;                                  \
        _IRPSP->DeviceObject = DevObj;                                       \
        _IRPSP->FileObject = FileObj;                                        \
        Irp->MdlAddress = MdlAddr;                                           \
    }

// public\ddk\inc\wdm\usbdi.h
#define USBD_TRANSFER_DIRECTION(x)            ((x) & USBD_TRANSFER_DIRECTION_IN)

// public\ddk\inc\wdm\wdm.h
#define FILE_READ_EA              ( 0x0008 )    // file & directory
#define FILE_WRITE_EA             ( 0x0010 )    // file & directory
#define DIRECTORY_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0xF)

// public\halkit\inc\nthal.h
#define FILE_READ_EA              ( 0x0008 )    // file & directory
#define FILE_WRITE_EA             ( 0x0010 )    // file & directory
#define DIRECTORY_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0xF)

// public\ifskit\inc\ntifs.h
#define FILE_READ_EA              ( 0x0008 )    // file & directory
#define FILE_WRITE_EA             ( 0x0010 )    // file & directory
#define DIRECTORY_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0xF)

// public\internal\multimedia\inc\ddrawp.h
#define IDirectDraw_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw2_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw4_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw7_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw_Release(p)                                  (p)->lpVtbl->Release(p)
#define IDirectDrawPalette_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawPalette2_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawPalette2_FreePrivateData(p, a)        (p)->lpVtbl->FreePrivateData(p, a)
#define IDirectDrawClipper_Release(p)               (p)->lpVtbl->Release(p)
#define IDirectDrawSurface_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface2_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface2_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface3_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface3_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface4_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface4_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface4_FreePrivateData(p,a)         (p)->lpVtbl->FreePrivateData(p,a)
#define IDirectDrawSurface7_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface7_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface7_FreePrivateData(p,a)         (p)->lpVtbl->FreePrivateData(p,a)
#define IDirectDrawOptSurface_Release(p)               (p)->lpVtbl->Release(p)
#define IDirectDrawGammaControl_Release(p)               (p)->lpVtbl->Release(p)

// public\internal\multimedia\inc\ddrawpr.h
        #define DD16_FixupDIBEngine() TRUE

// public\internal\multimedia\inc\dinputdp.h
#define IDirectInputEffectShepherd_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputMapShepherd_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDeviceCallback_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDeviceCallback_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputActionFramework_Release(p) (p)->lpVtbl->Release(p)

// public\internal\multimedia\inc\dpnathlp.h
#define	IDirectPlayNATHelp_Release(p)								(p)->lpVtbl->Release(p)

// public\internal\multimedia\inc\dsoundp.h
#define IDirectSoundDMOProxy_ReleaseResources(p)       (p)->lpVtbl->ReleaseResources(p)

// public\internal\net\inc\isnkrnl.h
#define MIPX_SEND_DATAGRAM     _TDI_CONTROL_CODE((I_MIPX | 314), METHOD_IN_DIRECT) // send dgram
#define MIPX_RCV_DATAGRAM     _TDI_CONTROL_CODE((I_MIPX | 315), METHOD_OUT_DIRECT) // send dgram

// public\internal\net\inc\nbtioctl.h
#define IOCTL_NETBT_DNS_NAME_RESOLVE _NETBT_CTRL_CODE( 36, METHOD_OUT_DIRECT,\
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_NETBT_WINS_SEND        _NETBT_CTRL_CODE( 39, METHOD_OUT_DIRECT, \
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_NETBT_WINS_RCV         _NETBT_CTRL_CODE( 40, METHOD_OUT_DIRECT, \
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_NETBT_LAST_IOCTL       _NETBT_CTRL_CODE( 58, METHOD_OUT_DIRECT, \
                                                        FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// public\internal\printscan\inc\fxsapip.h
#define DRT_ALL         (DRT_EMAIL | DRT_MSGBOX)            // All possible delivery report types
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

// public\internal\shell\inc\comctrlp.h
#define BL_GETITEMRECT          (WM_USER+7)

// public\internal\windows\inc\duser\duisurface.h
#define ORGB(r, g, b)       ARGB(255, r, g, b)                  // Opaque color

// public\internal\windows\inc\duser\dusercore.h
#define GRIM_VALID         (GRIM_OPTIONS | GRIM_SURFACE | GRIM_PALETTE | GRIM_DROPTARGET)

// public\internal\windows\inc\winconp.h
#define MACHINE_REGISTRY_INITIAL_PALETTE           (L"InitialPalette")

// public\internal\windows\inc\winuserp.h
#define LWA_VALID              (LWA_COLORKEY            | \
                                LWA_ALPHA)
#define ULW_VALID              (ULW_COLORKEY            | \
                                ULW_ALPHA               | \
                                ULW_OPAQUE)
#define FE_FONTSMOOTHINGORIENTATION_VALID          (FE_FONTSMOOTHINGORIENTATIONRGB)

// public\oak\inc\ddrawi.h
#define DDPALETTECALLBACKSSIZE  sizeof( DDHAL_DDPALETTECALLBACKS )
#define DDCOLORCONTROLCALLBACKSSIZE sizeof( DDHAL_DDCOLORCONTROLCALLBACKS )
#define BUMP_PALETTE_STAMP(pal_gbl)                  \
if ( pal_gbl->dwContentsStamp )                      \
{                                                    \
    pal_gbl->dwContentsStamp++;                      \
    if ( 0 == pal_gbl->dwContentsStamp)              \
        pal_gbl->dwContentsStamp++;                  \
}
#define PFINDEX_UNSUPPORTED    (~0UL)   // surface's pixel format is not supported by HEL

// public\oak\inc\dx95type.h
#define DDP_LCL(pddp) (((DDRAWI_DDRAWPALETTE_INT *)(pddp))->lpLcl)

// public\sdk\amovie\inc\amvideo.h
#define AMDDS_RGB (AMDDS_RGBOFF | AMDDS_RGBOVR | AMDDS_RGBFLP)

// public\sdk\amovie\inc\winutil.h
#define REALIZEPALETTE TEXT("WM_REALIZEPALETTE")

// public\sdk\inc16\windows.h
#define PALETTERGB(r,g,b)   (0x02000000L | RGB(r,g,b))
#define EM_GETRECT              (WM_USER+2)
#define EM_SETRECT              (WM_USER+3)
#define EM_SETRECTNP            (WM_USER+4)
#define LB_GETITEMRECT         (WM_USER+25)

// public\sdk\inc16\windowsx.h
#define     DeletePalette(hpal)     DeleteObject((HGDIOBJ)(HPALETTE)(hpal))
#define HANDLE_WM_QUERYNEWPALETTE(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0)
#define HANDLE_WM_PALETTEISCHANGING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTEISCHANGING(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTEISCHANGING, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_PALETTECHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTECHANGED(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTECHANGED, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define Edit_GetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_GETRECT, 0, (LPARAM)(RECT FAR*)(lprc)))
#define Edit_SetRect(hwndCtl, lprc)             ((void)SendMessage((hwndCtl), EM_SETRECT, 0, (LPARAM)(const RECT FAR*)(lprc)))
#define Edit_SetRectNoPaint(hwndCtl, lprc)      ((void)SendMessage((hwndCtl), EM_SETRECTNP, 0, (LPARAM)(const RECT FAR*)(lprc)))

// public\sdk\inc\avifmt.h
#define cktypeDIBcompressed     aviTWOCC('d', 'c')

// public\sdk\inc\certbcli.h
#define	CSBFT_CHECKPOINT_DIR	  ((CSBFT) (TEXT('\x03') | CSBFT_DIRECTORY))

// public\sdk\inc\cierror.h
#define QUERY_E_INVALID_DIRECTORY        ((HRESULT)0x8004160AL)
#define FILTER_S_PARTIAL_CONTENTSCAN_IMMEDIATE ((HRESULT)0x00041731L)
#define FILTER_S_FULL_CONTENTSCAN_IMMEDIATE ((HRESULT)0x00041732L)
#define FILTER_S_CONTENTSCAN_DELAYED     ((HRESULT)0x00041733L)
#define CI_INCORRECT_VERSION             ((HRESULT)0xC0041821L)

// public\sdk\inc\commctrl.h
#define ILC_PALETTE             0x00000800      // (not implemented)
#define TB_GETITEMRECT          (WM_USER + 29)
#define TB_GETRECT              (WM_USER + 51) // wParam is the Cmd instead of index
#define RB_GETRECT      (WM_USER +  9)
#define RB_SETPALETTE   (WM_USER + 37)
#define RB_GETPALETTE   (WM_USER + 38)
#define TTM_NEWTOOLRECTA        (WM_USER + 6)
#define TTM_NEWTOOLRECTW        (WM_USER + 52)
#define TTM_ADJUSTRECT          (WM_USER + 31)
#define SB_GETRECT              (WM_USER+10)
#define TBM_GETTHUMBRECT        (WM_USER+25)
#define TBM_GETCHANNELRECT      (WM_USER+26)
#define TabCtrl_GetItemRect(hwnd, i, prc) \
    (BOOL)SNDMSG((hwnd), TCM_GETITEMRECT, (WPARAM)(int)(i), (LPARAM)(RECT *)(prc))
#define TabCtrl_AdjustRect(hwnd, bLarger, prc) \
    (int)SNDMSG(hwnd, TCM_ADJUSTRECT, (WPARAM)(BOOL)(bLarger), (LPARAM)(RECT *)prc)
#define TabCtrl_RemoveImage(hwnd, i) \
        (void)SNDMSG((hwnd), TCM_REMOVEIMAGE, i, 0L)

// public\sdk\inc\d3d.h
#define IDirect3D_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3D_Release(p) (p)->Release()
#define IDirect3D2_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3D2_Release(p) (p)->Release()
#define IDirect3D3_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3D3_Release(p) (p)->Release()
#define IDirect3D7_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3D7_Release(p) (p)->Release()
#define IDirect3DDevice_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DDevice_Release(p) (p)->Release()
#define IDirect3DDevice2_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DDevice2_Release(p) (p)->Release()
#define IDirect3DDevice3_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DDevice3_Release(p) (p)->Release()
#define IDirect3DDevice7_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DDevice7_Release(p) (p)->Release()
#define IDirect3DLight_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DLight_Release(p) (p)->Release()
#define IDirect3DMaterial_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DMaterial_Release(p) (p)->Release()
#define IDirect3DMaterial2_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DMaterial2_Release(p) (p)->Release()
#define IDirect3DMaterial3_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DMaterial3_Release(p) (p)->Release()
#define IDirect3DTexture_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DTexture_Release(p) (p)->Release()
#define IDirect3DTexture2_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DTexture2_Release(p) (p)->Release()
#define IDirect3DViewport_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DViewport_Release(p) (p)->Release()
#define IDirect3DViewport2_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DViewport2_Release(p) (p)->Release()
#define IDirect3DViewport3_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DViewport3_Release(p) (p)->Release()
#define D3DERR_INVALIDPALETTE           MAKE_DDHRESULT(744)
#define D3DERR_CONFLICTINGTEXTUREPALETTE        MAKE_DDHRESULT(2086)

// public\sdk\inc\d3d8.h
#define IDirect3D8_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3D8_Release(p) (p)->Release()
#define IDirect3DDevice8_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DDevice8_Release(p) (p)->Release()
#define IDirect3DResource8_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DResource8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
#define IDirect3DResource8_Release(p) (p)->Release()
#define IDirect3DResource8_FreePrivateData(p,a) (p)->FreePrivateData(a)
#define IDirect3DTexture8_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DTexture8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
#define IDirect3DTexture8_Release(p) (p)->Release()
#define IDirect3DTexture8_FreePrivateData(p,a) (p)->FreePrivateData(a)
#define IDirect3DVolumeTexture8_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DVolumeTexture8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
#define IDirect3DVolumeTexture8_Release(p) (p)->Release()
#define IDirect3DVolumeTexture8_FreePrivateData(p,a) (p)->FreePrivateData(a)
#define IDirect3DCubeTexture8_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DCubeTexture8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
#define IDirect3DCubeTexture8_Release(p) (p)->Release()
#define IDirect3DCubeTexture8_FreePrivateData(p,a) (p)->FreePrivateData(a)
#define IDirect3DSurface8_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DSurface8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
#define IDirect3DSurface8_Release(p) (p)->Release()
#define IDirect3DSurface8_FreePrivateData(p,a) (p)->FreePrivateData(a)
#define IDirect3DVolume8_Release(p) (p)->lpVtbl->Release(p)
#define IDirect3DVolume8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
#define IDirect3DVolume8_Release(p) (p)->Release()
#define IDirect3DVolume8_FreePrivateData(p,a) (p)->FreePrivateData(a)
#define D3DERR_CONFLICTINGTEXTUREPALETTE        MAKE_D3DHRESULT(2086)

// public\sdk\inc\d3dtypes.h
#define RGBA_GETBLUE(rgb)       ((rgb) & 0xff)
#define RGB_GETBLUE(rgb)        ((rgb) & 0xff)

// public\sdk\inc\d3dxerr.h
#define D3DXERR_NODIRECTDRAWAVAILABLE    ((HRESULT)0xC8770BBBL)
#define D3DXERR_NODIRECT3DAVAILABLE    ((HRESULT)0xC8770BBCL)
#define D3DXERR_NODIRECT3DDEVICEAVAILABLE    ((HRESULT)0xC8770BBDL)
#define D3DXERR_SURFACENOTPALETTED    ((HRESULT)0xC8770BD7L)

// public\sdk\inc\daerror.h
#define DA_MAKE_HRESULT(i)          MAKE_HRESULT(SEVERITY_ERROR,            \
                                                 FACILITY_DIRECTANIMATION,  \
                                                 (DAERR_CODE_BEGIN + i))

// public\sdk\inc\ddkernel.h
#define IDirectDrawKernel_ReleaseKernelHandle(p)    (p)->lpVtbl->ReleaseKernelHandle(p)
#define IDirectDrawSurfaceKernel_ReleaseKernelHandle(p)    (p)->lpVtbl->ReleaseKernelHandle(p)

// public\sdk\inc\ddraw.h
#define IDirectDraw_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw_Release(p)                      (p)->Release()
#define IDirectDraw2_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw2_Release(p)                      (p)->Release()
#define IDirectDraw4_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw4_Release(p)                      (p)->Release()
#define IDirectDraw7_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectDraw7_Release(p)                      (p)->Release()
#define IDirectDrawPalette_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawPalette_Release(p)                   (p)->Release()
#define IDirectDrawClipper_Release(p)               (p)->lpVtbl->Release(p)
#define IDirectDrawClipper_Release(p)               (p)->Release()
#define IDirectDrawSurface_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface_Release(p)                   (p)->Release()
#define IDirectDrawSurface_ReleaseDC(p,a)               (p)->ReleaseDC(a)
#define IDirectDrawSurface2_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface2_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface2_Release(p)                   (p)->Release()
#define IDirectDrawSurface2_ReleaseDC(p,a)               (p)->ReleaseDC(a)
#define IDirectDrawSurface3_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface3_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface3_Release(p)                   (p)->Release()
#define IDirectDrawSurface3_ReleaseDC(p,a)               (p)->ReleaseDC(a)
#define IDirectDrawSurface4_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface4_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface4_FreePrivateData(p,a)         (p)->lpVtbl->FreePrivateData(p,a)
#define IDirectDrawSurface4_Release(p)                   (p)->Release()
#define IDirectDrawSurface4_ReleaseDC(p,a)               (p)->ReleaseDC(a)
#define IDirectDrawSurface4_FreePrivateData(p,a)         (p)->FreePrivateData(a)
#define IDirectDrawSurface7_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectDrawSurface7_ReleaseDC(p,a)               (p)->lpVtbl->ReleaseDC(p,a)
#define IDirectDrawSurface7_FreePrivateData(p,a)         (p)->lpVtbl->FreePrivateData(p,a)
#define IDirectDrawSurface7_Release(p)                   (p)->Release()
#define IDirectDrawSurface7_ReleaseDC(p,a)               (p)->ReleaseDC(a)
#define IDirectDrawSurface7_FreePrivateData(p,a)         (p)->FreePrivateData(a)
#define IDirectDrawGammaControl_Release(p)               (p)->lpVtbl->Release(p)
#define IDirectDrawGammaControl_Release(p)               (p)->Release()
#define DDERR_INVALIDPIXELFORMAT                MAKE_DDHRESULT( 145 )
#define DDERR_INVALIDRECT                       MAKE_DDHRESULT( 150 )
#define DDERR_NODIRECTDRAWSUPPORT               MAKE_DDHRESULT( 222 )
#define DDERR_OVERLAPPINGRECTS                  MAKE_DDHRESULT( 270 )
#define DDERR_PALETTEBUSY                       MAKE_DDHRESULT( 387 )
#define DDERR_INVALIDDIRECTDRAWGUID             MAKE_DDHRESULT( 561 )
#define DDERR_DIRECTDRAWALREADYCREATED          MAKE_DDHRESULT( 562 )
#define DDERR_NODIRECTDRAWHW                    MAKE_DDHRESULT( 563 )
#define DDERR_NOPALETTEATTACHED                 MAKE_DDHRESULT( 572 )
#define DDERR_NOPALETTEHW                       MAKE_DDHRESULT( 573 )

// public\sdk\inc\ddrawex.h
#define IDirectDraw3_Release(p)                      (p)->lpVtbl->Release(p)

// public\sdk\inc\dinput.h
#define IDirectInputEffect_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputEffect_Release(p) (p)->Release()
#define IDirectInputDevice_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDevice_Release(p) (p)->Release()
#define IDirectInputDevice2_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDevice2_Release(p) (p)->Release()
#define IDirectInputDevice7_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDevice7_Release(p) (p)->Release()
#define IDirectInputDevice8_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDevice8_Release(p) (p)->Release()
#define IDirectInput_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInput_Release(p) (p)->Release()
#define IDirectInput2_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInput2_Release(p) (p)->Release()
#define IDirectInput7_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInput7_Release(p) (p)->Release()
#define IDirectInput8_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInput8_Release(p) (p)->Release()
#define DIBUTTON_ANY(instance)                  ( 0xFF004400 | instance )

// public\sdk\inc\dinputd.h
#define IDirectInputEffectDriver_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputEffectDriver_Release(p) (p)->Release()
#define IDirectInputJoyConfig_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputJoyConfig_Release(p) (p)->Release()
#define IDirectInputJoyConfig8_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputJoyConfig8_Release(p) (p)->Release()

// public\sdk\inc\dmusici.h
#define DMUS_SEG_ANYTRACK           0x80000000  /* For IDirectMusicSegment::GetParam() - checks each track until it finds one that returns data (not DMUS_E_NOT_FOUND.) */

// public\sdk\inc\dpaddr.h
#define IDirectPlay8Address_Release(p)         			    (p)->lpVtbl->Release(p)
#define IDirectPlay8AddressIP_Release(p)         		    (p)->lpVtbl->Release(p)
#define IDirectPlay8Address_Release(p)         			    (p)->Release()
#define IDirectPlay8AddressIP_Release(p)         		    (p)->Release()

// public\sdk\inc\dplay.h
#define IDirectPlay2_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlay2_Release(p)                     (p)->Release()
#define IDirectPlay3_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlay3_Release(p)                     (p)->Release()
#define IDirectPlayX_Release(p)                     (p)->lpVtbl->Release(p)
#define IDirectPlayX_Release(p)                     (p)->Release()
#define IDirectPlay_Release(p)                      (p)->lpVtbl->Release(p)
#define IDirectPlay_Release(p)                      (p)->Release()

// public\sdk\inc\dplay8.h
#define	IDirectPlay8Client_Release(p)							(p)->lpVtbl->Release(p)
#define	IDirectPlay8Server_Release(p)							(p)->lpVtbl->Release(p)
#define	IDirectPlay8Peer_Release(p)								(p)->lpVtbl->Release(p)
#define	IDirectPlay8Client_Release(p)							(p)->Release()
#define	IDirectPlay8Server_Release(p)							(p)->Release()
#define	IDirectPlay8Peer_Release(p)								(p)->Release()

// public\sdk\inc\dsetup.h
#define DSETUP_DIRECTX  (DSETUP_DXCORE|DSETUP_DDRAWDRV|DSETUP_DSOUNDDRV)

// public\sdk\inc\dsound.h
#define IDirectSound_Release(p)                  IUnknown_Release(p)
#define IDirectSound8_Release(p)                  IDirectSound_Release(p)
#define IDirectSoundCapture_Release(p)                      IUnknown_Release(p)
#define IDirectSoundNotify_Release(p)                       IUnknown_Release(p)
#define IDirectSoundFXGargle_Release(p)                     IUnknown_Release(p)
#define IDirectSoundFXChorus_Release(p)                     IUnknown_Release(p)
#define IDirectSoundFXFlanger_Release(p)                    IUnknown_Release(p)
#define IDirectSoundFXEcho_Release(p)                       IUnknown_Release(p)
#define IDirectSoundFXDistortion_Release(p)                 IUnknown_Release(p)
#define IDirectSoundFXCompressor_Release(p)                 IUnknown_Release(p)
#define IDirectSoundFXParamEq_Release(p)                 IUnknown_Release(p)
#define IDirectSoundFXI3DL2Reverb_Release(p)                IUnknown_Release(p)
#define IDirectSoundFXWavesReverb_Release(p)                IUnknown_Release(p)
#define IDirectSoundCaptureFXAec_Release(p)                IUnknown_Release(p)
#define IDirectSoundCaptureFXNoiseSuppress_Release(p)                IUnknown_Release(p)
#define IDirectSoundFullDuplex_Release(p)               IUnknown_Release(p)

// public\sdk\inc\dvoice.h
#define IDirectPlayVoiceClient_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectPlayVoiceServer_Release(p)                   (p)->lpVtbl->Release(p)
#define IDirectPlayVoiceTest_Release(p)                	    (p)->lpVtbl->Release(p)
#define IDirectPlayVoiceClient_Release(p)               	(p)->Release()
#define IDirectPlayVoiceServer_Release(p)                   (p)->Release()
#define IDirectPlayVoiceTest_Release(p)                     (p)->Release()

// public\sdk\inc\dxsurfb.h
#define DECLARE_REGISTER_DX_SURFACE(id)\
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) \
        { \
            CATID cat[2]; \
            cat[0] = CATID_DXSurface; \
            cat[1] = CATID_DXImageTransform; \
            return RegisterSurface(GetObjectCLSID(), (id), 2, cat, 0, NULL, bRegister); \
        }
#define DECLARE_REGISTER_DX_AUTHORING_SURFACE(id)\
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) \
        { \
            CATID cat[3]; \
            cat[0] = CATID_DXSurface; \
            cat[1] = CATID_DXImageTransform; \
            cat[2] = CATID_DXAuthoringTransform; \
            return RegisterSurface(GetObjectCLSID(), (id), 3, cat, 0, NULL, bRegister); \
        }

// public\sdk\inc\esebkmsg.h
#define hrNoBackupDirectory              ((HRESULT)0xC80001F7L)
#define hrBackupDirectoryNotEmpty        ((HRESULT)0xC80001F8L)
#define hrMakeBackupDirectoryFail        ((HRESULT)0xC800020DL)

// public\sdk\inc\gl\glaux.h
#define AUX_WIND_IS_RGB(x)      (((x) & AUX_INDEX) == 0)
#define AUX_WIND_IS_INDIRECT(x) (((x) & AUX_INDIRECT) != 0)
#define AUX_WIND_IS_DIRECT(x)   (((x) & AUX_INDIRECT) == 0)

// public\sdk\inc\imagehlp.h
#define UNDNAME_NO_FUNCTION_RETURNS      (0x0004)  // Disable expansion of return type for primary declaration
#define UNDNAME_NO_RETURN_UDT_MODEL      (0x0400)  // Disable expansion of MS model for UDT returns

// public\sdk\inc\ksmedia.h
#define KS_DIBSIZE(bi) ((bi).biHeight < 0 ? (-1)*(KS__DIBSIZE(bi)) : KS__DIBSIZE(bi))

// public\sdk\inc\mfc42\afxctl.h
#define EVENT_STOCK_MOUSEDOWN() \
	{ afxEventStock, DISPID_MOUSEDOWN, _T("MouseDown"), \
	  VTS_I2 VTS_I2 VTS_XPOS_PIXELS VTS_YPOS_PIXELS },
#define EVENT_STOCK_MOUSEMOVE() \
	{ afxEventStock, DISPID_MOUSEMOVE, _T("MouseMove"), \
	  VTS_I2 VTS_I2 VTS_XPOS_PIXELS VTS_YPOS_PIXELS },
#define EVENT_STOCK_MOUSEUP() \
	{ afxEventStock, DISPID_MOUSEUP, _T("MouseUp"), \
	  VTS_I2 VTS_I2 VTS_XPOS_PIXELS VTS_YPOS_PIXELS },

// public\sdk\inc\mfc42\afxmsg_.h
#define ON_WM_QUERYNEWPALETTE() \
	{ WM_QUERYNEWPALETTE, 0, 0, 0, AfxSig_bv, \
		(AFX_PMSG)(AFX_PMSGW)(BOOL (AFX_MSG_CALL CWnd::*)(void))&OnQueryNewPalette },
#define ON_WM_PALETTECHANGED() \
	{ WM_PALETTECHANGED, 0, 0, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*))&OnPaletteChanged },
#define ON_WM_PALETTEISCHANGING() \
	{ WM_PALETTEISCHANGING, 0, 0, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(CWnd*))&OnPaletteIsChanging },
#define ON_WM_SIZING() \
	{ WM_SIZING, 0, 0, 0, AfxSig_vwSIZING, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, LPRECT))&OnSizing },
#define ON_WM_MOVING() \
	{ WM_MOVING, 0, 0, 0, AfxSig_vwMOVING, \
		(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(UINT, LPRECT))&OnMoving },

// public\sdk\inc\mmreg.h
#define JPEG_DIB        mmioFOURCC('J','P','E','G')    /* Still image JPEG DIB biCompression */
#define MJPG_DIB        mmioFOURCC('M','J','P','G')    /* Motion JPEG DIB biCompression     */

// public\sdk\inc\mmsystem.h
#define  WAVE_FORMAT_DIRECT_QUERY  (WAVE_FORMAT_QUERY | WAVE_FORMAT_DIRECT)

// public\sdk\inc\ntddvdeo.h
#define VIDEO_MODE_MANAGED_PALETTE  0x0008  // 0 = Palette is fixed (must be

// public\sdk\inc\ntdsbcli.h
#define	BFT_CHECKPOINT_DIR			(BFT)(TEXT('\x03') | BFT_DIRECTORY)

// public\sdk\inc\ntdsbmsg.h
#define hrNoBackupDirectory              ((HRESULT)0xC80001F7L)
#define hrBackupDirectoryNotEmpty        ((HRESULT)0xC80001F8L)
#define hrMakeBackupDirectoryFail        ((HRESULT)0xC800020DL)

// public\sdk\inc\ntimage.h
#define IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffff)
#define IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)

// public\sdk\inc\ntioapi.h
#define FILE_READ_EA              ( 0x0008 )    // file & directory
#define FILE_WRITE_EA             ( 0x0010 )    // file & directory

// public\sdk\inc\ntlsa.h
#define TRUST_DIRECTION_BIDIRECTIONAL   (TRUST_DIRECTION_INBOUND | TRUST_DIRECTION_OUTBOUND)

// public\sdk\inc\ntobapi.h
#define DIRECTORY_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0xF)

// public\sdk\inc\ntsecapi.h
#define TRUST_DIRECTION_BIDIRECTIONAL   (TRUST_DIRECTION_INBOUND | TRUST_DIRECTION_OUTBOUND)

// public\sdk\inc\olectl.h
#define DISPID_AMBIENT_PALETTE          (-726)

// public\sdk\inc\propset.h
#define IsIndirectVarType(vt)			\
	    ((vt) == VT_STREAM ||		\
	     (vt) == VT_STREAMED_OBJECT ||	\
	     (vt) == VT_STORAGE ||		\
	     (vt) == VT_STORED_OBJECT ||        \
             (vt) == VT_VERSIONED_STREAM)

// public\sdk\inc\pstore.h
#define PST_E_DISK_IMAGE_MISMATCH       _HRESULT_TYPEDEF_(0x800C000BL)

// public\sdk\inc\richedit.h
#define EM_SETPALETTE			(WM_USER + 93)

// public\sdk\inc\richole.h
#define REO_DONTNEEDPALETTE	(0x00000020L)	// Object doesn't need palette

// public\sdk\inc\rtcerr.h
#define RTC_E_STATUS_REDIRECT_MULTIPLE_CHOICES ((HRESULT)0x80EF012CL)
#define RTC_E_STATUS_REDIRECT_MOVED_PERMANENTLY ((HRESULT)0x80EF012DL)
#define RTC_E_STATUS_REDIRECT_MOVED_TEMPORARILY ((HRESULT)0x80EF012EL)
#define RTC_E_STATUS_REDIRECT_SEE_OTHER  ((HRESULT)0x80EF012FL)
#define RTC_E_STATUS_REDIRECT_USE_PROXY  ((HRESULT)0x80EF0131L)
#define RTC_E_STATUS_REDIRECT_ALTERNATIVE_SERVICE ((HRESULT)0x80EF017CL)

// public\sdk\inc\sti.h
#define IStillImage_Release(p)                  (p)->lpVtbl->Release(p)

// public\sdk\inc\tapi3err.h
#define TAPI_E_INVALIDDIRECTION          ((HRESULT)0x8004003AL)

// public\sdk\inc\urlmki.h
#define INET_E_REDIRECT_FAILED           _HRESULT_TYPEDEF_(0x800C0014L)
#define INET_E_REDIRECT_TO_DIR           _HRESULT_TYPEDEF_(0x800C0015L)
#define INET_E_REDIRECTING                 _HRESULT_TYPEDEF_(0x800C0014L)

// public\sdk\inc\urlmon.h
#define INET_E_REDIRECT_FAILED           _HRESULT_TYPEDEF_(0x800C0014L)
#define INET_E_REDIRECT_TO_DIR           _HRESULT_TYPEDEF_(0x800C0015L)
#define INET_E_REDIRECTING                 _HRESULT_TYPEDEF_(0x800C0014L)

// public\sdk\inc\usbdi.h
#define USBD_TRANSFER_DIRECTION(x)            ((x) & USBD_TRANSFER_DIRECTION_IN)

// public\sdk\inc\uuids.h
#define MEDIASUBTYPE_HASALPHA(mt) ( ((mt).subtype == MEDIASUBTYPE_ARGB4444)            || \
                                    ((mt).subtype == MEDIASUBTYPE_ARGB32)              || \
                                    ((mt).subtype == MEDIASUBTYPE_AYUV)                || \
                                    ((mt).subtype == MEDIASUBTYPE_AI44)                || \
                                    ((mt).subtype == MEDIASUBTYPE_IA44)                || \
                                    ((mt).subtype == MEDIASUBTYPE_ARGB1555)            || \
                                    ((mt).subtype == MEDIASUBTYPE_ARGB32_D3D_DX7_RT)   || \
                                    ((mt).subtype == MEDIASUBTYPE_ARGB4444_D3D_DX7_RT) || \
                                    ((mt).subtype == MEDIASUBTYPE_ARGB1555_D3D_DX7_RT) )
#define MEDIASUBTYPE_D3D_DX7_RT(mt) (((mt).subtype == MEDIASUBTYPE_ARGB32_D3D_DX7_RT)   || \
                                     ((mt).subtype == MEDIASUBTYPE_ARGB4444_D3D_DX7_RT) || \
                                     ((mt).subtype == MEDIASUBTYPE_ARGB1555_D3D_DX7_RT) || \
                                     ((mt).subtype == MEDIASUBTYPE_RGB32_D3D_DX7_RT)    || \
                                     ((mt).subtype == MEDIASUBTYPE_RGB16_D3D_DX7_RT))

// public\sdk\inc\vfw.h
#define ICM_DRAW_GET_PALETTE        (ICM_USER+16)   // get the palette needed for drawing
#define ICM_DRAW_CHANGEPALETTE      (ICM_USER+51)   // for animating palette
#define cktypeDIBcompressed     aviTWOCC('d', 'c')
#define comptypeDIB         mmioFOURCC('D', 'I', 'B', ' ')
#define MCIWndPaletteKick(hwnd)     (BOOL)MCIWndSM(hwnd,MCIWNDM_PALETTEKICK,0,0)
#define MCIWndGetPalette(hwnd)      (HPALETTE)MCIWndSM(hwnd, MCIWNDM_GETPALETTE, 0, 0)
#define MCIWNDM_GETPALETTE      (WM_USER + 126)
#define MCIWNDM_SETPALETTE      (WM_USER + 127)
#define MCIWNDM_PALETTEKICK     (WM_USER + 150)
#define DVM_PALETTE			(DVM_CONFIGURE_START + 1)
#define DVM_PALETTERGB555		(DVM_CONFIGURE_START + 3)
#define capFileSaveDIB(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEDIB, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPaletteOpen(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_OPEN, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPaletteSave(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_SAVE, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPalettePaste(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_PASTE, (WPARAM) 0, (LPARAM)0L))

// public\sdk\inc\vfwmsgs.h
#define VFW_E_INVALID_DIRECTION          ((HRESULT)0x80040208L)
#define VFW_E_PALETTE_SET                ((HRESULT)0x8004021DL)
#define VFW_E_NO_PALETTE_AVAILABLE       ((HRESULT)0x80040220L)
#define VFW_E_NO_DISPLAY_PALETTE         ((HRESULT)0x80040221L)
#define VFW_E_INVALID_RECT               ((HRESULT)0x80040229L)

// public\sdk\inc\wdm.h
#define FILE_READ_EA              ( 0x0008 )    // file & directory
#define FILE_WRITE_EA             ( 0x0010 )    // file & directory
#define DIRECTORY_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0xF)

// public\sdk\inc\wincrui.h
#define Credential_GetMinSize(hwnd, rect)\
    (BOOL) SendMessage(hwnd, CRM_GETMINSIZE, 0, (LPARAM) &rect)

// public\sdk\inc\windowsx.h
#define     DeletePalette(hpal)     DeleteObject((HGDIOBJ)(HPALETTE)(hpal))
#define HANDLE_WM_QUERYNEWPALETTE(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0L)
#define HANDLE_WM_PALETTEISCHANGING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTEISCHANGING(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTEISCHANGING, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_PALETTECHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTECHANGED(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTECHANGED, (WPARAM)(HWND)(hwndPaletteChange), 0L)

// public\sdk\inc\winerror.h
#define OLE_E_INVALIDRECT                _HRESULT_TYPEDEF_(0x8004000DL)
#define CERTSRV_E_SUBJECT_DIRECTORY_GUID_REQUIRED _HRESULT_TYPEDEF_(0x8009480EL)
#define SPAPI_E_INCORRECTLY_COPIED_INF   _HRESULT_TYPEDEF_(0x800F0237L)

// public\sdk\inc\winfax.h
#define FAX_E_DIRECTORY_IN_USE               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_DIRECTORY_IN_USE)

// public\sdk\inc\wingdi.h
#define PALETTERGB(r,g,b)   (0x02000000 | RGB(r,g,b))

// public\sdk\inc\wininet.h
#define IS_GOPHER_DIRECTORY(type)       (BOOL)(((type) & GOPHER_TYPE_DIRECTORY) ? TRUE : FALSE)

// public\sdk\inc\winnt.h
#define FILE_READ_EA              ( 0x0008 )    // file & directory
#define FILE_WRITE_EA             ( 0x0010 )    // file & directory
#define IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffff)
#define IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)

// public\sdk\inc\winuser.h
#define BF_RECT         (BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM)

// public\sdk\inc\wownt32.h
#define HPALETTE_32(h16)  ((HPALETTE)  (WOWHandle32(h16, WOW_TYPE_HPALETTE)))
#define HPALETTE_16(h32)  (WOWHandle16(h32, WOW_TYPE_HPALETTE))

// published\sdk\inc\gl\glaux.h
#define AUX_WIND_IS_RGB(x)      (((x) & AUX_INDEX) == 0)
#define AUX_WIND_IS_INDIRECT(x) (((x) & AUX_INDIRECT) != 0)
#define AUX_WIND_IS_DIRECT(x)   (((x) & AUX_INDIRECT) == 0)

// published\sdk\inc\mmreg.h
#define JPEG_DIB        mmioFOURCC('J','P','E','G')    /* Still image JPEG DIB biCompression */
#define MJPG_DIB        mmioFOURCC('M','J','P','G')    /* Motion JPEG DIB biCompression     */

// published\sdk\inc\propset.h
#define IsIndirectVarType(vt)			\
	    ((vt) == VT_STREAM ||		\
	     (vt) == VT_STREAMED_OBJECT ||	\
	     (vt) == VT_STORAGE ||		\
	     (vt) == VT_STORED_OBJECT ||        \
             (vt) == VT_VERSIONED_STREAM)

// published\sdk\inc\pstore.h
#define PST_E_DISK_IMAGE_MISMATCH       _HRESULT_TYPEDEF_(0x800C000BL)

// published\sdk\inc\richole.h
#define REO_DONTNEEDPALETTE	(0x00000020L)	// Object doesn't need palette

// published\sdk\inc\vfw.h
#define ICM_DRAW_GET_PALETTE        (ICM_USER+16)   // get the palette needed for drawing
#define ICM_DRAW_CHANGEPALETTE      (ICM_USER+51)   // for animating palette
#define cktypeDIBcompressed     aviTWOCC('d', 'c')
#define comptypeDIB         mmioFOURCC('D', 'I', 'B', ' ')
#define MCIWndPaletteKick(hwnd)     (BOOL)MCIWndSM(hwnd,MCIWNDM_PALETTEKICK,0,0)
#define MCIWndGetPalette(hwnd)      (HPALETTE)MCIWndSM(hwnd, MCIWNDM_GETPALETTE, 0, 0)
#define MCIWNDM_GETPALETTE      (WM_USER + 126)
#define MCIWNDM_SETPALETTE      (WM_USER + 127)
#define MCIWNDM_PALETTEKICK     (WM_USER + 150)
#define DVM_PALETTE			(DVM_CONFIGURE_START + 1)
#define DVM_PALETTERGB555		(DVM_CONFIGURE_START + 3)
#define capFileSaveDIB(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEDIB, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPaletteOpen(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_OPEN, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPaletteSave(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_SAVE, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPalettePaste(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_PASTE, (WPARAM) 0, (LPARAM)0L))

// published\sdk\inc\windowsx.h
#define     DeletePalette(hpal)     DeleteObject((HGDIOBJ)(HPALETTE)(hpal))
#define HANDLE_WM_QUERYNEWPALETTE(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), 0L)
#define HANDLE_WM_PALETTEISCHANGING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTEISCHANGING(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTEISCHANGING, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define HANDLE_WM_PALETTECHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), 0L)
#define FORWARD_WM_PALETTECHANGED(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTECHANGED, (WPARAM)(HWND)(hwndPaletteChange), 0L)

// published\sdk\inc\wownt32.h
#define HPALETTE_32(h16)  ((HPALETTE)  (WOWHandle32(h16, WOW_TYPE_HPALETTE)))
#define HPALETTE_16(h32)  (WOWHandle16(h32, WOW_TYPE_HPALETTE))

// sdktools\apimon\apimon\apimonp.h
#define UBLACK                          RGB(000, 000, 000)
#define DARK_RED                        RGB(128, 000, 000)
#define DARK_GREEN                      RGB(000, 128, 000)
#define DARK_YELLOW                     RGB(128, 128, 000)
#define DARK_BLUE                       RGB(000, 000, 128)
#define DARK_MAGENTA                    RGB(128, 000, 128)
#define DARK_CYAN                       RGB(000, 128, 128)
#define DARK_GRAY                       RGB(128, 128, 128)
#define LIGHT_GRAY                      RGB(192, 192, 192)
#define LIGHT_RED                       RGB(255, 000, 000)
#define LIGHT_GREEN                     RGB(000, 255, 000)
#define LIGHT_YELLOW                    RGB(255, 255, 000)
#define LIGHT_BLUE                      RGB(000, 000, 255)
#define LIGHT_MAGENTA                   RGB(255, 000, 255)
#define LIGHT_CYAN                      RGB(000, 255, 255)
#define UWHITE                          RGB(255, 255, 255)

// sdktools\filever\filever.h
#define FA_DIR(_x)    ((_x) & FILE_ATTRIBUTE_DIRECTORY)

// sdktools\mep\src\assign.c
#define CINDEX(clr)        ((&clr-&ColorTab[0])+isaUserMin)

// sdktools\mep\src\display.c
#define CINDEX(clr)     (unsigned char) ((&clr-&ColorTab[0])+isaUserMin)

// sdktools\perfmon\intrline.c
#define RectDrawable(lpRect)           \
   ((lpRect->right - lpRect->left) &&  \
    (lpRect->bottom - lpRect->top))
#define ILWidth(pILine)    \
   (pILine->rectBorder.right)
#define ILStartPixel(pILine) \
   (pILine->rectLeftGrab.left)
#define ILStopPixel(pILine)   \
   (pILine->rectRightGrab.right)

// sdktools\perfmon\perfmon.h
#define crLightGray              RGB (0xC0, 0xC0, 0xC0)
#define crDarkGray               RGB (0x40, 0x40, 0x40)
#define crGray                   RGB (0x80, 0x80, 0x80)
#define crRed                    RGB (0xFF, 0x00, 0x00)
#define crGreen                  RGB (0x00, 0xFF, 0x00)
#define crBlue                   RGB (0x00, 0x00, 0xFF)
#define crBlack                  RGB (0x00, 0x00, 0x00)
#define crWhite                  RGB (0xFF, 0xFF, 0xFF)

// sdktools\perfmon\utils.h
#define RectContract(lpRect, xAmt, yAmt)              \
   {                                                  \
   (lpRect)->left += (xAmt) ;                         \
   (lpRect)->top += (yAmt) ;                          \
   (lpRect)->right -= (xAmt) ;                        \
   (lpRect)->bottom -= (yAmt) ;                       \
   }
#define IsBW(hDC)                                     \
   (DeviceNumColors (hDC) <= 2)

// sdktools\rcdll\p0defs.h
#define ANY_EOS                 ( FILE_EOS | ACTUAL_EOS | DEFINITION_EOS \
                                                                         | RESCAN_EOS | BACKSLASH_EOS )

// sdktools\setedit\setedit.h
#define crLightGray              RGB (0xC0, 0xC0, 0xC0)
#define crDarkGray               RGB (0x40, 0x40, 0x40)
#define crGray                   RGB (0x80, 0x80, 0x80)
#define crRed                    RGB (0xFF, 0x00, 0x00)
#define crGreen                  RGB (0x00, 0xFF, 0x00)
#define crBlue                   RGB (0x00, 0x00, 0xFF)
#define crBlack                  RGB (0x00, 0x00, 0x00)
#define crWhite                  RGB (0xFF, 0xFF, 0xFF)

// sdktools\setedit\utils.h
#define RectContract(lpRect, xAmt, yAmt)              \
   {                                                  \
   (lpRect)->left += (xAmt) ;                         \
   (lpRect)->top += (yAmt) ;                          \
   (lpRect)->right -= (xAmt) ;                        \
   (lpRect)->bottom -= (yAmt) ;                       \
   }
#define IsBW(hDC)                                     \
   (DeviceNumColors (hDC) <= 2)

// sdktools\tweakui\explorer.cpp
#define clrDefAlt     RGB(0x00, 0x00, 0xFF)
#define clrDefHot     RGB(0x00, 0x00, 0xFF)

// sdktools\winobj\winfile.h
#define FS_GETDIRECTORY     (WM_USER+0x103)

// sdktools\z\src\assign.c
#define CINDEX(clr) ((&clr-&ColorTab[0])+isaUserMin)

// sdktools\z\src\display.c
#define CINDEX(clr)     (unsigned char) ((&clr-&ColorTab[0])+isaUserMin)

// shell\applets\autorun\dlgapp.cpp
#define CENTER_RGB_VALUES   RGB(90,126,220)
#define PANEL_RGB_VALUES    RGB(59,52,177)
#define TITLE_RGB_VALUES    RGB(255, 255, 255)
#define HEADER_RGB_VALUES   RGB(214, 223, 245)
#define SHADOW_RGB_VALUES   RGB(52,  98,  189)
#define TEXT_RGB_VALUES     RGB(255, 255, 255)
#define DISABLED_RGB_VALUES RGB(128, 128, 128)

// shell\applets\upgrade\dlgapp.cpp
#define CENTER_RGB_VALUES   RGB(90,126,220)
#define PANEL_RGB_VALUES    RGB(0,51,152)
#define TITLE_RGB_VALUES    RGB(255, 255, 255)
#define HEADER_RGB_VALUES   RGB(214, 223, 245)
#define SHADOW_RGB_VALUES   RGB(52,  98,  189)
#define TEXT_RGB_VALUES     RGB(255, 255, 255)
#define DISABLED_RGB_VALUES RGB(128, 128, 128)

// shell\browseui\legacy\channel.cpp
#define COLORBK     RGB(0,0,0)

// shell\browseui\legacy\isfband.cpp
#define COLORTEXT   RGB(255,255,255)
#define COLORBK     RGB(0,0,0)

// shell\browseui\mbutil.h
#define COLOR_BKGND          RGB(71, 80, 158)
#define COLOR_BKGND2         RGB(92, 118, 186)

// shell\browseui\mediaband.cpp
#define COLOR_BKGND16        RGB(192, 192, 192)
#define COLOR_BKGNDMIDDLE   RGB(99, 129, 193)

// shell\browseui\shbrows2.cpp
#define ISRECT_EQUAL(rc1, rc2) (((rc1).top == (rc2).top) && ((rc1).bottom == (rc2).bottom) && ((rc1).left == (rc2).left) && ((rc1).right == (rc2).right))

// shell\comctl32\v5\cutils.c
#define RGB_BUTTONTEXT      (RGB(000,000,000))  // black
#define RGB_BUTTONSHADOW    (RGB(128,128,128))  // dark grey
#define RGB_BUTTONFACE      (RGB(192,192,192))  // bright grey
#define RGB_BUTTONHILIGHT   (RGB(255,255,255))  // white
#define FlipColor(rgb)      (RGB(GetBValue(rgb), GetGValue(rgb), GetRValue(rgb)))

// shell\comctl32\v5\tvpaint.c
#define COLORKEY RGB(0xF4, 0x0, 0x0)

// shell\comctl32\v6\button.c
#define IsValidImage(imageType, realType, max)   \
    ((imageType < max) && (rgbType[imageType] == realType))

// shell\comctl32\v6\cutils.c
#define RGB_BUTTONTEXT      (RGB(000,000,000))  // black
#define RGB_BUTTONSHADOW    (RGB(128,128,128))  // dark grey
#define RGB_BUTTONFACE      (RGB(192,192,192))  // bright grey
#define RGB_BUTTONHILIGHT   (RGB(255,255,255))  // white
#define FlipColor(rgb)      (RGB(GetBValue(rgb), GetGValue(rgb), GetRValue(rgb)))

// shell\comctl32\v6\static.c
#define IsValidImage(imageType, realType, max)  \
            ((imageType < max) && (rgbType[imageType] == realType))

// shell\comctl32\v6\tvpaint.c
#define COLORKEY RGB(0xF4, 0x0, 0x0)

// shell\comctl32\v6\usrctl32.h
#define SYSRGB(i)               GetSysColor(COLOR_##i)
#define SYSRGBRTL(i)            GetSysColor(COLOR_##i)

// shell\cpls\desknt5\desk.h
#define MON_RGB RGB(0, 128, 128)

// shell\cpls\main\mousectl.c
#define MOUSECTL_NORMAL_COLOR         RGB(255, 255, 255)
#define HALFRGB(c)  RGB(GetRValue(c) / 2, GetGValue(c) / 2, GetBValue(c) / 2)

// shell\cpls\utc\clock.c
    #define BLOB_COLOR  RGB(0, 128, 128)

// shell\evtmon\inc\msoem.h
#define CopyLprg(lpvFrom, lpvTo, type, iMax) \
            CopyRgb((lpvFrom), (lpvTo), (unsigned int)(sizeof(type) * (iMax)))

// shell\evtmon\inc\msolex.h
#define FLexEndOfScan(plexs) \
            ((plexs)->cpRun + (plexs)->ccpRun >= (plexs)->cpLim)

// shell\ext\brfcase\filesync\syncui\comm.h
#define ColorText(nState)   (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHTTEXT : COLOR_WINDOWTEXT)
#define ColorBk(nState)     (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_WINDOW)
#define ColorMenuText(nState)   (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHTTEXT : COLOR_MENUTEXT)
#define ColorMenuBk(nState)     (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_MENU)

// shell\ext\brfcase\filesync\syncui\dobj.c
#define DT_CALC         (DT_CALCRECT | DT_CENTER | DT_SINGLELINE | DT_NOPREFIX)

// shell\ext\cdfview\exticon.h
#define     COLOR1              (RGB(0,0,255))
#define     COLOR2              (RGB(0,255,0))

// shell\ext\ftp\priv.h
#define ProtocolIdlInnerData(pidl)  ((LPVOID)&(((PDELEGATEITEMID)(pidl))->rgb[0]))

// shell\inc\evtmon\msoem.h
#define CopyLprg(lpvFrom, lpvTo, type, iMax) \
            CopyRgb((lpvFrom), (lpvTo), (unsigned int)(sizeof(type) * (iMax)))

// shell\inc\evtmon\msolex.h
#define FLexEndOfScan(plexs) \
            ((plexs)->cpRun + (plexs)->ccpRun >= (plexs)->cpLim)

// shell\osshell\accesory\calc\scikeys.c
#define RED         RGB(255,0,0)       /* Red                           */
#define PURPLE      RGB(255,0,255)     /* Dark Purple                   */
#define BLUE        RGB(0,0,255)       /* Blue                          */
#define DKBLUE      RGB(0,0,255)       /* Dark Blue                     */
#define MAGENTA     RGB(255,0,255)     /* Magenta                       */
#define DKRED       RGB(255,0,0)       /* Dark Red.                     */
#define WHITE       RGB(255,255,255)   /* White                         */
#define BLACK       RGB(0,0,0)         /* Black                         */

// shell\osshell\accesory\clock\clock.c
#define BLOB_COLOR  RGB (0,128,128)

// shell\osshell\accesory\eudcedit\eudcedit.h
#define		COLOR_WHITE	RGB(255,255,255) // white
#define		COLOR_BLACK	RGB(  0,  0,  0) // black
#define		COLOR_LGRAY	RGB(192,192,192) // light Gray
#define		COLOR_DGRAY	RGB(128,128,128) // dark Gray
#define		COLOR_YELLO	RGB(255,255,  0) // yellow
#define		COLOR_BLUE	RGB(  0,  0,255) // blue
#define		COLOR_RED	RGB(255,  0,  0) // red

// shell\osshell\accesory\mspaint\global.h
#define CMP_RGB_HILITE      RGB(255, 255, 255)
#define CMP_RGB_LTGRAY      RGB(192, 192, 192)  // instead of BtnFace
#define CMP_RGB_DKGRAY      RGB(128, 128, 128)
#define CMP_RGB_BLACK       RGB(0, 0, 0)        // instead of frame

// shell\osshell\accesory\winchat\winchat.h
#define GET_WM_CTLCOLOREDIT_HDC(wParam,lParam)  (HDC)wParam
#define GET_WM_CTLCOLOREDIT_HDC(wParam,lParam)  (HDC)wParam

// shell\osshell\accessib\accwiz\desk.h
#define MON_RGB RGB(0, 128, 128)

// shell\osshell\accessib\osk\inc\kbmain.h
#define RGB_KEYBGHIGHLIGHT COLOR_HIGHLIGHT /*RGB(0,0,0)*/

// shell\osshell\accessib\osk\src\kbfunc.c
#define RGBBLACK     RGB(0,0,0)
#define RGBWHITE     RGB(255,255,255)
#define RGBBACK     RGB(107,107,107)

// shell\osshell\control\console\console.h
#define AttrToRGB(Attr) (gpStateInfo->ColorTable[(Attr) & 0x0F])

// shell\osshell\control\console\menu.h
#define CM_SETCOLOR       (WM_USER+1)

// shell\osshell\control\joy\joycpl.h
#define ACTIVE_COLOR	RGB( 255, 0, 0 )
#define INACTIVE_COLOR	RGB( 128, 0, 0 )

// shell\osshell\control\mmsys\dib.c
    #define RGBQ(dw) RGB(GetBValue(dw),GetGValue(dw),GetRValue(dw))

// shell\osshell\control\mmsys\utils.h
#define ColorText(nState)   (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHTTEXT : COLOR_WINDOWTEXT)
#define ColorBk(nState)     (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_WINDOW)
#define ColorMenuText(nState)   (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHTTEXT : COLOR_MENUTEXT)
#define ColorMenuBk(nState)     (((nState) & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_MENU)

// shell\osshell\control\mmsys\voicecpl.c
#define IDirectPlayVoiceSetup_Release(p)               (p)->lpVtbl->Release(p)

// shell\osshell\control\scrnsave\flyingobjects\flyingobjects.cpp
#define OPT_STD             ( OPT_COLOR_CYCLE | OPT_SMOOTH_SHADE | OPT_TESSEL | OPT_SIZE )

// shell\osshell\control\scrnsave\marquee\ssmarque.c
#define DEFAULT_TEXT_COLOR      RGB(255,0,255)
#define DEFAULT_SCREEN_COLOR    RGB(0,0,0)

// shell\osshell\control\scrnsave\mystify\ssmyst.c
#define rgbBlack        RGB (0,0,0)
#define rgbWhite        RGB (255,255,255)
#define rgbGrey         RGB (128,128,128)

// shell\osshell\control\t1instal\builder.c
#define ROMAN        (USHORT)2      /* Direction = left,right&neutrals.*/

// shell\osshell\cpls\main\mousectl.c
#define MOUSECTL_NORMAL_COLOR         RGB(255, 255, 255)
#define HALFRGB(c)  RGB(GetRValue(c) / 2, GetGValue(c) / 2, GetBValue(c) / 2)

// shell\osshell\games\sol\sol.c
#define rgbGreen RGB(0x00,0x80,0x00)
#define rgbWhite RGB(0xff,0xff,0xff)

// shell\shell32\copy.c
#define DTNIsDirectory(pdtn) (pdtn->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)

// shell\shell32\copy.h
#define ISDIRFINDDATA(finddata) ((finddata).dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)

// shell\shell32\finddlg.h
#define  DWM_SETHEIGHT      (DWM_FIRST+0)   // WPARAM: height in pixels, LPARAM: n/a, ret: BOOL
#define  DWM_SETBKCOLOR     (DWM_FIRST+1)   // WPARAM: COLORREF, LPARAM: n/a, ret: BOOL

// shell\shell32\lnkcon.h
#define CM_SETCOLOR       (WM_USER+1)
#define CM_COLOR_INIT     (WM_USER+4)
#define AttrToRGB(Attr) (pcpd->lpConsole->ColorTable[(Attr) & 0x0F])

// shell\shell32\menuband\isfband.cpp
#define COLORTEXT   RGB(255,255,255)
#define COLORBK     RGB(0,0,0)

// shell\themes\inc\scanner.h
#define ISNUMSTART(p)   ((isdigit(*p)) || (*p == '-') || (*p == '+'))

// shell\themes\themeui\settings.h
#define MON_RGB RGB(0, 128, 128)

// shell\themes\uxtheme\gradient.h
#define SYSCOLOR(c) (c|0x80000000)

// shell\themes\uxtheme\nctheme.cpp
#define MDIBTNINDEX(ncrc)                ((ncrc)-NCMDIBTNFIRST)
#define CLR_LAMETEXT            RGB(91, 171, 245)

// shell\themes\uxtheme\nctheme.h
    #define NCMDIBTNRECTS ((NCMDIBTNLAST- NCMDIBTNFIRST)+1)

// shell\themes\uxtheme\render.h
#define DEFAULT_TRANSPARENT_COLOR   RGB(255, 0, 255)

// shell\themes\uxtheme\scrollp.h
#define SYSRGB(i)               GetSysColor(COLOR_##i)
#define SYSRGBRTL(i)            GetSysColor(COLOR_##i)

// termsrv\inc\adcgmcro.h
#define DC_PALINDEX(i)      PALETTEINDEX(i)

// termsrv\inc\platform.h
#define GetImageId( _PlatformId ) \
    _PlatformId & 0x00FF0000
#define GetImageRevision( _PlatformId ) \
    _PlatformId & 0x0000FFFF

// termsrv\inc\wdcgmcro.h
#define CO_FROM_DCPALID(dcpalid)       ((HPALETTE)(dcpalid))

// termsrv\remdsk\rds\as\cpi32\pm.cpp
#define PMADJUSTBUGGEDCOLOR(pColor)                                          \
    if ( ((pColor)->rgbBlue != 0x00) &&                                      \
         ((pColor)->rgbBlue != 0xFF) )                                       \
    {                                                                        \
        (pColor)->rgbBlue += 0x40;                                           \
    }                                                                        \
                                                                             \
    if ( ((pColor)->rgbGreen != 0x00) &&                                     \
         ((pColor)->rgbGreen != 0xFF) )                                      \
    {                                                                        \
        (pColor)->rgbGreen += 0x20;                                          \
    }                                                                        \
                                                                             \
    if ( ((pColor)->rgbRed != 0x00) &&                                       \
         ((pColor)->rgbRed != 0xFF) )                                        \
    {                                                                        \
        (pColor)->rgbRed += 0x20;                                            \
    }

// termsrv\remdsk\rds\as\h\ntddvd40.h
#define VIDEO_MODE_MANAGED_PALETTE  0x0008  // 0 = Palette is fixed (must be

// termsrv\remdsk\rds\as\h\oe.h
#define RECT_FROM_RECTL(dcr, rec) if (rec.right < rec.left)                \
                                    {                                        \
                                        dcr.left   = rec.right;              \
                                        dcr.right  = rec.left;               \
                                    }                                        \
                                    else                                     \
                                    {                                        \
                                        dcr.left   = rec.left;               \
                                        dcr.right  = rec.right;              \
                                    }                                        \
                                    if (rec.bottom < rec.top)                \
                                    {                                        \
                                        dcr.bottom = rec.top;                \
                                        dcr.top    = rec.bottom;             \
                                    }                                        \
                                    else                                     \
                                    {                                        \
                                        dcr.top    = rec.top;                \
                                        dcr.bottom = rec.bottom;             \
                                    }

// termsrv\remdsk\rds\as\h\t_share.h
#define TSHR_RECT16_FROM_RECT(lprcTshr, rc) \
    CopyRect((LPRECT)lprcTshr, &rc)
#define RECT_FROM_TSHR_RECT16(lprc, tshrrc) \
    CopyRect(lprc, (LPRECT)&tshrrc)
#define TSHR_RGBQUAD_TO_TSHR_COLOR(TshrRGBQuad, TshrColor)  \
        TshrColor.red = TshrRGBQuad.rgbRed;           \
        TshrColor.green = TshrRGBQuad.rgbGreen;       \
        TshrColor.blue = TshrRGBQuad.rgbBlue

// termsrv\remdsk\rds\dev\inc16\mmsystem.h
#define  WAVE_FORMAT_DIRECT_QUERY  (WAVE_FORMAT_QUERY | WAVE_FORMAT_DIRECT)
#define DIBINDEX(n)     MAKELONG((n),0x10FF)

// termsrv\remdsk\rds\dev\inc16\msvideo.h
#define DVM_PALETTE			(DVM_CONFIGURE_START + 1)
#define DVM_PALETTERGB555		(DVM_CONFIGURE_START + 3)

// termsrv\remdsk\rds\dev\inc16\windows.h
#define PALETTERGB(r,g,b)   (0x02000000L | RGB(r,g,b))
#define BF_RECT         (BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM)  // ;Internal 4.0
#define STM_SETIMAGE        (WM_USER+2)     // ;Internal 4.0
#define STM_GETIMAGE        (WM_USER+3)     // ;Internal 4.0
#define BM_GETIMAGE         (WM_USER+6)     // ;Internal 4.0
#define BM_SETIMAGE         (WM_USER+7)     // ;Internal 4.0
#define EM_GETRECT              (WM_USER+2)
#define EM_SETRECT              (WM_USER+3)
#define EM_SETRECTNP            (WM_USER+4)
#define LB_GETITEMRECT          (WM_USER+25)

// termsrv\remdsk\rds\dev\inc16\windowsx.h
#define GET_WM_CTLCOLOR_HDC(wp, lp, msg)        (HDC)(wp)
#define GET_WM_CTLCOLOR_MSG(type)               WM_CTLCOLOR

// windows\advcore\ctf\cuilib\cuisys.cpp
#define COLOR_WHITE RGB( 0xFF, 0xFF, 0xFF )
#define COLOR_BLACK RGB( 0x00, 0x00, 0x00 )

// windows\advcore\directui\old\inc\directui.h
#define DirectUIMakePropertyMUID(clmuid, pidx) \
            ((DirectUI::PropertyMUID) (0xFF000000 | (0xFFF000 & clmuid) | 0x000 | (0x1FF & pidx)))
#define DirectUIMakeMethodMUID(clmuid, midx) \
            ((DirectUI::MethodMUID)   (0xFF000000 | (0xFFF000 & clmuid) | 0x200 | (0x1FF & midx)))
#define DirectUIMakeEventMUID(clmuid, eidx) \
            ((DirectUI::EventMUID)    (0xFF000000 | (0xFFF000 & clmuid) | 0x400 | (0x1FF & eidx)))

// windows\advcore\duser\directui\test\suite\suite.cpp
#define PASSED(s) { MessageBoxW(NULL, L"Test Passed!", s, MB_OK|MB_ICONINFORMATION); }

// windows\advcore\duser\engine\services\context.h
#define BEGIN_CALLBACK()                \
    __try {                             \
        if (!IsInitThread()) {          \
            AlwaysPromptInvalid("DirectUser has been uninitialized before processing a callback (1)"); \
        }                               \
        GetContext()->BeginCallback();  \

// windows\advcore\gdiplus\engine\entry\facerealization.cpp
#define FONT_GRAYSCALE_OR_CT_OR_MONOUNHINTED (FO_GRAYSCALE | FO_SUBPIXEL_4 | FO_CLEARTYPE_GRID | FO_CLEARTYPE | FO_MONO_UNHINTED | FO_COMPATIBLE_WIDTH)

// windows\advcore\gdiplus\engine\entry\metaplay.cpp
#define GDIP_MINSCALED_DIBSECTION_SIZE   (GDIP_MAX_DIBSECTION_SIZE / 2)

// windows\advcore\gdiplus\engine\fondrv\tt\scaler\fnt.h
#define FNT_PIXELSIZE  ((F26Dot6)0x40)
#define FNT_SP_SUB_PIXEL			0x0001      /* set when calling fs_NewTransformation() */

// windows\advcore\gdiplus\engine\fondrv\tt\scaler\fscaler.h
#define SP_SUB_PIXEL			0x0001          /* set when calling fs_NewTransformation() */

// windows\advcore\gdiplus\engine\fondrv\tt\scaler\fscdefs.h
		#define RunningSubPixel(globalGS)		((uint16)((globalGS)->flHintForSubPixel & FNT_SP_SUB_PIXEL))
		#define CompatibleWidthSP(globalGS)		((uint16)((globalGS)->flHintForSubPixel & FNT_SP_COMPATIBLE_WIDTH))
		#define VerticalSPDirection(globalGS)	((uint16)((globalGS)->flHintForSubPixel & FNT_SP_VERTICAL_DIRECTION))
		#define BGROrderSP(globalGS)			((uint16)((globalGS)->flHintForSubPixel & FNT_SP_BGR_ORDER))
	#define VIRTUAL_PIXELSIZE_RTDG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RDTG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RUTG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RTG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RTHG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_ROFF	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define RGB_OVERSCALE (R_Subpixels + G_Subpixels + B_Subpixels)
	#define RGB_OVERSCALE (SUBPIXEL_OVERSCALE * 3)
	#define FLOOR_RGB_OVERSCALE(x) ((x) < 0) ? -((-(x)+ RGB_OVERSCALE -1) / RGB_OVERSCALE) : ((x) / RGB_OVERSCALE) // by the way, this is NOT a floor operation
	#define CEIL_RGB_OVERSCALE(x) FLOOR_RGB_OVERSCALE((x) + RGB_OVERSCALE -1)
	#define MAX_RGB_INDEX (2 * 16 + 2 * 4 + 2 )
	#define SUBPIXEL_SCALEBACK_UPPER_LIMIT (SUBPIXEL_SCALEBACK_FACTOR *120 /100)
	#define SUBPIXEL_SCALEBACK_LOWER_LIMIT (SUBPIXEL_SCALEBACK_FACTOR *100 /120)

// windows\advcore\gdiplus\engine\fondrv\tt\ttfd\fontfile.h
#define UNHINTED_MODE(pfc)       (pfc->flFontType & (FO_MONO_UNHINTED | FO_SUBPIXEL_4 | FO_CLEARTYPE))

// windows\advcore\gdiplus\engine\gpmf3216\win16api.h
#define bEmitWin16RealizePalette(pLocalDC)                                 \
                   bW16Emit0(pLocalDC, META_REALIZEPALETTE)
#define bEmitWin16SelectPalette(pLocalDC, ihObject)                        \
                   bW16Emit1(pLocalDC, META_SELECTPALETTE, ihObject)
#define bEmitWin16ResizePalette(pLocalDC, cEntries) 	                   \
                   bW16Emit1(pLocalDC, META_RESIZEPALETTE, cEntries)

// windows\advcore\gdiplus\engine\imaging\jpeg\libjpeg\jdcolor.c
#define macroCMYK2RGB(p, r, i) \
   ((i < 192) ? (256*255 - (i)*(r) - 127) : \
   (256*255 - 192*(r) - (((i) - 192)*(255*(p) - 192*(r)) + 31)/63 ))
    #define VALIDX(x) if ( cconvert->x[i] > 255*256)\
      WARNMS(cinfo, JERR_BAD_J_COLORSPACE);
  #define SET(Q) \
    cconvert->g ## Q[i] = macroCMYK2RGB(p ## Q, r ## Q, i);\
    VALIDX(g ## Q)\
    cconvert->g ## Q[i] = macroScale(cconvert->g ## Q[i])

// windows\advcore\gdiplus\engine\imaging\off_tiff\cmyk2rgb.cpp
#define macroCMYK2RGB(p, r, i) \
   ((i < 192) ? (256*255 - (i)*(r) - 127) : \
   (256*255 - 192*(r) - (((i) - 192)*(255*(p) - 192*(r)) + 31)/63 ))
#define SET(Q) \
    g ## Q[i] = macroCMYK2RGB(p ## Q, r ## Q, i);\
    g ## Q[i] = macroScale(g ## Q[i])

// windows\advcore\gdiplus\engine\imaging\png\libpng\spngconf.h
#define PNGsRGB PNGCHUNK('s','R','G','B')
#define cbPNGSignature (sizeof vrgbPNGSignature)
#define cbPNGMSOSignature (sizeof vrgbPNGMSOSignature)
#define cbPNGcmPPSignature (sizeof vrgbPNGcmPPSignature)

// windows\advcore\gdiplus\engine\render\gradientfill.cpp
#define CLAMP_COLOR_CHANNEL(a, b)  \
    if(a < 0)                   \
    {                           \
        a = 0;                  \
    }                           \
    if(a > b)                   \
    {                           \
        a = b;                  \
    }

// windows\advcore\gdiplus\engine\render\soreadrmw.cpp
#define SHOULDCOPY_sRGB64(x) (sRGB::isTranslucent64(x))

// windows\advcore\gdiplus\engine\render\sowritermw.cpp
#define SHOULDCOPY_sRGB(x)   ((x) != 0)
#define SHOULDCOPY_sRGB64(x) ((x) != 0)

// windows\advcore\gdiplus\engine\render\srgb.cpp
#define CLAMP64(input, expr) (((input) <= 0) ? 0 : \
                              (((input) >= SRGB_ONE) ? 255 : \
                              (expr)))

// windows\advcore\gdiplus\privinc\imaging.h
#define IMGERR_NOPALETTE        MAKE_IMGERR(2)

// windows\advcore\gdiplus\test\quadtest\quadtest.cpp
#define MESHCOLOR   RGB(255, 0, 0)

// windows\advcore\gdiplus\test\warpdemo\warpdemo.cxx
#define MESHCOLOR   RGB(255, 0, 0)

// windows\core\dxkernel\inc\dxg.h
#define DxEngSelectPaletteToSurface(pso,hpal) \
                                   ((HPALETTE)(CALL_DXENG(SelectPaletteToSurface)(pso,hpal)))

// windows\core\ntcon\server\consrv.h
#define ConvertAttrToRGB(Con, Attr) ((Con)->ColorTable[(Attr) & 0x0F])

// windows\core\ntgdi\client\gdiicm.h
#define METAFILE_COLORSPACE           (0x000002 | HGDIOBJ_SPECIFIC_COLORSPACE) // DC (metafile)
#define DRIVER_COLORSPACE             (0x000004 | HGDIOBJ_SPECIFIC_COLORSPACE) // DC (source)
#define DIBSECTION_COLORSPACE         (0x000010 | HGDIOBJ_SPECIFIC_COLORSPACE) // DIBSection
#define GET_COLORSPACE_TYPE(x)  ((x) & 0x000FFF)
#define bNeedTranslateColor(pdcattr)                     \
        (IS_ICM_HOST(pdcattr->lIcmMode) &&               \
         (!IS_ICM_LAZY_CORRECTION(pdcattr->lIcmMode)) && \
         (pdcattr->hcmXform != NULL))

// windows\core\ntgdi\client\icm.c
#define IsColorDeviceContext(hdcThis) \
                        (2 < (unsigned) GetDeviceCaps((hdcThis), NUMCOLORS))
#define IsColorSpaceOwnedByGDIObject(pColorSpace,hGDIObj)         \
            ((pColorSpace) ?                                      \
              (((pColorSpace)->hObj == (hGDIObj)) ? TRUE : FALSE) \
               : FALSE)
#define bDeviceCalibrate(pColorSpace)                                                \
            ((pColorSpace) ?                                                         \
              (((pColorSpace)->flInfo & DEVICE_CALIBRATE_COLORSPACE) ? TRUE : FALSE) \
                : FALSE)
#define IcmReferenceColorSpace(pColorSpace)                 \
            if ((pColorSpace))                              \
            {                                               \
                ENTERCRITICALSECTION(&semColorSpaceCache);  \
                (pColorSpace)->cRef++;                      \
                LEAVECRITICALSECTION(&semColorSpaceCache);  \
            }
#define IcmReferenceColorTransform(pCXfrom)                     \
            if ((pCXform))                                      \
            {                                                   \
                ENTERCRITICALSECTION(&semColorTransformCache);  \
                (pCXform)->cRef++;                              \
                LEAVECRITICALSECTION(&semColorTransformCache);  \
            }

// windows\core\ntgdi\client\local.h
#define IS_COLOR_MONO(color) ((color & 0x00ffffff) == 0 || (color & 0x00ffffff) == 0x00ffffff)

// windows\core\ntgdi\client\mfrec.hxx
#define SIZEOF_MRSETPIXELV      (sizeof(MRSETPIXELV))
#define SIZEOF_MRCREATEPALETTE(cEntries)        \
        (sizeof(MRCREATEPALETTE)-sizeof(PALETTEENTRY)+(cEntries)*sizeof(PALETTEENTRY))
#define SIZEOF_MRCREATECOLORSPACE (sizeof(MRCREATECOLORSPACE))
#define SIZEOF_MRSETPALETTEENTRIES(cEntries)    \
        (sizeof(MRSETPALETTEENTRIES)-sizeof(PALETTEENTRY)+(cEntries)*sizeof(PALETTEENTRY))
#define SIZEOF_MREOF(cPalEntries)       \
        (sizeof(MREOF)+(cPalEntries)*sizeof(PALETTEENTRY))
#define SIZEOF_MRSETCOLORADJUSTMENT(pca)        \
        (sizeof(MRSETCOLORADJUSTMENT) - sizeof(COLORADJUSTMENT) + (pca)->caSize)
#define SIZEOF_MRPIXELFORMAT (sizeof(MRPIXELFORMAT))

// windows\core\ntgdi\fondrv\tt\mssipotf\fs\fnt.h
#define FNT_PIXELSIZE  ((F26Dot6)0x40)
#define FNT_SP_SUB_PIXEL			0x0001      /* set when calling fs_NewTransformation() */

// windows\core\ntgdi\fondrv\tt\mssipotf\fs\fscaler.h
#define SP_SUB_PIXEL			0x0001          /* set when calling fs_NewTransformation() */

// windows\core\ntgdi\fondrv\tt\mssipotf\fs\fscdefs.h
		#define RunningSubPixel(globalGS)		((uint16)((globalGS)->flHintForSubPixel & FNT_SP_SUB_PIXEL))
		#define CompatibleWidthSP(globalGS)		((uint16)((globalGS)->flHintForSubPixel & FNT_SP_COMPATIBLE_WIDTH))
		#define VerticalSPDirection(globalGS)	((uint16)((globalGS)->flHintForSubPixel & FNT_SP_VERTICAL_DIRECTION))
		#define BGROrderSP(globalGS)			((uint16)((globalGS)->flHintForSubPixel & FNT_SP_BGR_ORDER))
	#define VIRTUAL_PIXELSIZE_RTDG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RDTG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RUTG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RTG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RTHG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_ROFF	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define RGB_OVERSCALE (R_Subpixels + G_Subpixels + B_Subpixels)
	#define RGB_OVERSCALE (SUBPIXEL_OVERSCALE * 3)
	#define FLOOR_RGB_OVERSCALE(x) ((x) < 0) ? -((-(x)+ RGB_OVERSCALE -1) / RGB_OVERSCALE) : ((x) / RGB_OVERSCALE) // by the way, this is NOT a floor operation
	#define CEIL_RGB_OVERSCALE(x) FLOOR_RGB_OVERSCALE((x) + RGB_OVERSCALE -1)
	#define MAX_RGB_INDEX (2 * 16 + 2 * 4 + 2 )
	#define SUBPIXEL_SCALEBACK_UPPER_LIMIT (SUBPIXEL_SCALEBACK_FACTOR *120 /100)
	#define SUBPIXEL_SCALEBACK_LOWER_LIMIT (SUBPIXEL_SCALEBACK_FACTOR *100 /120)

// windows\core\ntgdi\fondrv\tt\scaler\fnt.h
#define FNT_PIXELSIZE  ((F26Dot6)0x40)
#define FNT_SP_SUB_PIXEL			0x0001      /* set when calling fs_NewTransformation() */

// windows\core\ntgdi\fondrv\tt\scaler\fscaler.h
#define SP_SUB_PIXEL			0x0001          /* set when calling fs_NewTransformation() */

// windows\core\ntgdi\fondrv\tt\scaler\fscdefs.h
		#define RunningSubPixel(globalGS)		((uint16)((globalGS)->flHintForSubPixel & FNT_SP_SUB_PIXEL))
		#define CompatibleWidthSP(globalGS)		((uint16)((globalGS)->flHintForSubPixel & FNT_SP_COMPATIBLE_WIDTH))
		#define VerticalSPDirection(globalGS)	((uint16)((globalGS)->flHintForSubPixel & FNT_SP_VERTICAL_DIRECTION))
		#define BGROrderSP(globalGS)			((uint16)((globalGS)->flHintForSubPixel & FNT_SP_BGR_ORDER))
	#define VIRTUAL_PIXELSIZE_RTDG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RDTG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RUTG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RTG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_RTHG	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define VIRTUAL_PIXELSIZE_ROFF	(FNT_PIXELSIZE/VIRTUAL_OVERSCALE)
	#define RGB_OVERSCALE (R_Subpixels + G_Subpixels + B_Subpixels)
	#define RGB_OVERSCALE (SUBPIXEL_OVERSCALE * 3)
	#define FLOOR_RGB_OVERSCALE(x) ((x) < 0) ? -((-(x)+ RGB_OVERSCALE -1) / RGB_OVERSCALE) : ((x) / RGB_OVERSCALE) // by the way, this is NOT a floor operation
	#define CEIL_RGB_OVERSCALE(x) FLOOR_RGB_OVERSCALE((x) + RGB_OVERSCALE -1)
	#define MAX_RGB_INDEX (2 * 16 + 2 * 4 + 2 )
	#define SUBPIXEL_SCALEBACK_UPPER_LIMIT (SUBPIXEL_SCALEBACK_FACTOR *120 /100)
	#define SUBPIXEL_SCALEBACK_LOWER_LIMIT (SUBPIXEL_SCALEBACK_FACTOR *100 /120)

// windows\core\ntgdi\fondrv\tt\ttfd\fd_query.c
#define CJ_TT_SCAN(cx,p) \
    (4*((((((p)->flFontType & FO_GRAY16)?(8):(1))*(cx))+31)/32))

// windows\core\ntgdi\gre\dcobj.hxx
#define STOCKOBJ_PAL            (HPAL)   gahStockObjects[DEFAULT_PALETTE]

// windows\core\ntgdi\gre\dibapi.cxx
#define IS_PASSTHROUGH_IMAGE(biCompression) \
    (((biCompression) == BI_JPEG) || ((biCompression) == BI_PNG))

// windows\core\ntgdi\gre\engine.h
#define HDIB_INVALID    ((HDIB)    HOBJ_INVALID)

// windows\core\ntgdi\gre\floodgdi.cxx
#define SCANLINEHEADER_SIZE (sizeof(SCANLINE) - sizeof(SPAN))
#define SCRATCH_SCANLINE_SIZE   SCANLINEHEADER_SIZE + 20 * sizeof(SPAN)
#define MERGE_SCANLINE_SIZE     SCANLINEHEADER_SIZE + 20 * sizeof(SPAN)
#define SCANLINE_INC_SIZE       20 * sizeof(SPAN)
#define DOWNSTACK_SIZE          sizeof(STACKOBJ) + 2 * SCRATCH_SCANLINE_SIZE
#define UPSTACK_SIZE            sizeof(STACKOBJ) + 10 * SCRATCH_SCANLINE_SIZE

// windows\core\ntgdi\gre\multi.cxx
#define REALIZE_HALFTONE_PALETTE(hdev) (DrvRealizeHalftonePalette((hdev),FALSE))

// windows\core\ntgdi\gre\tranblt.cxx
#define TC_PUT_DST_16BPP(A)                          \
    if (ulSrc != psb->TransparentColor)              \
        *(PUSHORT)pjDstTemp = (USHORT) A;            \
    pjDstTemp += 2;
#define TC_PUT_DST_32BPP(A)                          \
    if (ulSrc != psb->TransparentColor)              \
    {                                                \
        *(PULONG)pjDstTemp = A;                      \
    }                                                \
    pjDstTemp += 4;

// windows\core\ntgdi\gre\trimesh.cxx
#define LIMIT_COLOR(pv)        \
                               \
    if (pv->Red > 0xff00)      \
    {                          \
        pv->Red = 0xff00;      \
    }                          \
                               \
    if (pv->Green > 0xff00)    \
    {                          \
        pv->Green = 0xff00;    \
    }                          \
                               \
    if (pv->Blue > 0xff00)     \
    {                          \
        pv->Blue = 0xff00;     \
    }

// windows\core\ntgdi\gre\umpdeng.cxx
#define ISPATBRUSH(_pbo) ((_pbo) && (_pbo)->iSolidColor == 0xffffffff)

// windows\core\ntgdi\halftone\ht\htgetbmp.c
#define lR          (AABFData.LShiftRGB[0])
#define lG          (AABFData.LShiftRGB[1])
#define lB          (AABFData.LShiftRGB[2])
#define rR          (AABFData.RShiftRGB[0])
#define rG          (AABFData.RShiftRGB[1])
#define rB          (AABFData.RShiftRGB[2])

// windows\core\ntgdi\halftone\ht\htmapclr.c
#define SCALE_PRIM_RGB(pPrim,py)    ScaleRGB((pPrim))
#define SCALE_PRIM_RGB(pPrim,py)    ScaleRGB((pPrim), (py))

// windows\core\ntgdi\halftone\ht\htmapclr.h
#define VALIDATE_CLR_ADJ(a)         if ((a) < MIN_RGB_COLOR_ADJ) {          \
                                        (a) = MIN_RGB_COLOR_ADJ;            \
                                    } else if ((a) > MAX_RGB_COLOR_ADJ) {   \
                                        (a) = MAX_RGB_COLOR_ADJ; }
#define HT_RGB_B_INC            (HT_RGB_MAX_COUNT * HT_RGB_MAX_COUNT)
#define RGB555_P1_CUBE_INC      (RGB555_C_LEVELS * RGB555_C_LEVELS)
#define CRTX_PRIMMAX_RGB            (HT_RGB_MAX_COUNT - 1)
#define CRTX_SIZE_RGB               (sizeof(FD6XYZ) * (HT_RGB_MAX_COUNT * 3))
#define SIZE_BGR_MAPPING_TABLE      (sizeof(BGR8) * (HT_RGB_CUBE_COUNT + 2))
#define LUTSIZE_ANTI_ALIASING   (sizeof(RGBLUTAA))
#define PDHI_TO_PDCI(x)     (PDEVICECOLORINFO)&(((PHT_DHI)(x))->DCI)

// windows\core\ntgdi\halftone\ht\htpat.h
#define CX_SIZE_RGB555PAT           (CX_RGB555PAT + 1)
#define CB_RGB555PAT                (CX_SIZE_RGB555PAT * CY_RGB555PAT)

// windows\core\ntgdi\halftone\ht\htrender.c
#define bm8i    (*(PBM8BPPINFO)&pAAHdr->prgbLUT->ExtBGR[3])

// windows\core\ntgdi\halftone\ht\htstret.h
#define MULRGB(b,l)     (LONG)((LONG)(b) * (LONG)(l))
#define SHARPEN_RGB_LR(rgbSP, rgbL, rgbC, rgbR, ExtraRS)                    \
{                                                                           \
    _SHARPEN_CLR_LR((rgbSP).b, (rgbL).b, (rgbC).b, (rgbR).b, ExtraRS);      \
    _SHARPEN_CLR_LR((rgbSP).g, (rgbL).g, (rgbC).g, (rgbR).g, ExtraRS);      \
    _SHARPEN_CLR_LR((rgbSP).r, (rgbL).r, (rgbC).r, (rgbR).r, ExtraRS);      \
}
#define SHARPEN_PRGB_LR(prgbSP, rgbL, rgbC, rgbR, ExtraRS)                  \
{                                                                           \
    _SHARPEN_CLR_LR((prgbSP)->b, (rgbL).b, (rgbC).b, (rgbR).b, ExtraRS);    \
    _SHARPEN_CLR_LR((prgbSP)->g, (rgbL).g, (rgbC).g, (rgbR).g, ExtraRS);    \
    _SHARPEN_CLR_LR((prgbSP)->r, (rgbL).r, (rgbC).r, (rgbR).r, ExtraRS);    \
}
#define SHARPEN_PRGB_LRTB(pS, pT, pC, pB, ExtraRS)                          \
{                                                                           \
    _SHARPEN_CLR_LRTB(((pS)    )->b,                                        \
                      ((pC) - 1)->b,                                        \
                      ((pC)    )->b,                                        \
                      ((pC) + 1)->b,                                        \
                      ((pT)    )->b,                                        \
                      ((pB)    )->b,                                        \
                      ExtraRS);                                             \
                                                                            \
    _SHARPEN_CLR_LRTB(((pS)    )->g,                                        \
                      ((pC) - 1)->g,                                        \
                      ((pC)    )->g,                                        \
                      ((pC) + 1)->g,                                        \
                      ((pT)    )->g,                                        \
                      ((pB)    )->g,                                        \
                      ExtraRS);                                             \
                                                                            \
    _SHARPEN_CLR_LRTB(((pS)    )->r,                                        \
                      ((pC) - 1)->r,                                        \
                      ((pC)    )->r,                                        \
                      ((pC) + 1)->r,                                        \
                      ((pT)    )->r,                                        \
                      ((pB)    )->r,                                        \
                      ExtraRS);                                             \
}

// windows\core\ntgdi\halftone\htui\htuidlg.h
#define FILL_MODE_RGB               (1)

// windows\core\ntgdi\halftone\htui\htuimain.c
#define CAS_MIN_GAMMA   ((MIN_RGB_GAMMA + 9) / 10)
#define CAS_MAX_GAMMA   ((MAX_RGB_GAMMA + 9) / 10)

// windows\core\ntgdi\halftone\sample\hp970c\multicolor\intrface.cpp
#define DIB_FILENAME    _TEXT("c:\\hp970c_p%02ldb%02ld.dib")

// windows\core\ntgdi\icm\mscms\sti.h
#define IStillImage_Release(p)                  (p)->lpVtbl->Release(p)

// windows\core\ntgdi\image\tricalc.cxx
#define LIMIT_COLOR(pv)        \
                               \
    if (pv->Red > 0xff00)      \
    {                          \
        pv->Red = 0xff00;      \
    }                          \
                               \
    if (pv->Green > 0xff00)    \
    {                          \
        pv->Green = 0xff00;    \
    }                          \
                               \
    if (pv->Blue > 0xff00)     \
    {                          \
        pv->Blue = 0xff00;     \
    }

// windows\core\ntgdi\inc\hmgshare.h
#define IS_CMYK_COLOR(x)   ((x) & DC_ICM_CMYK_COLOR)

// windows\core\ntgdi\mf3216\win16api.h
#define bEmitWin16RealizePalette(pLocalDC)                                 \
                   bW16Emit0(pLocalDC, META_REALIZEPALETTE)
#define bEmitWin16SelectPalette(pLocalDC, ihObject)                        \
                   bW16Emit1(pLocalDC, META_SELECTPALETTE, ihObject)
#define bEmitWin16ResizePalette(pLocalDC, cEntries) 	                   \
                   bW16Emit1(pLocalDC, META_RESIZEPALETTE, cEntries)

// windows\core\ntgdi\test\fonttest.nt\glyph.c
#define ASCENDERCOLOR  PALETTERGB( 128,   0,   0 )
#define DESCENDERCOLOR PALETTERGB(   0, 128,   0 )

// windows\core\ntgdi\test\ft\ft.h
#define AlphaDIBBlend(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13) 1

// windows\core\ntgdi\test\gdibench\attr.c
#define GTE_ARGS_A  hdc, (LPCTSTR)pszTest,  TestLen, &gsz
#define GTE_ARGS_W  hdc, (LPCWSTR)pwszTest, wTestLen, &gsz

// windows\core\ntgdi\test\gdibench\gdibench.h
#define END_TIMER     StopTime = EndTimeMeasurement(StartTime,Iter); \
                      return (StopTime)

// windows\core\ntgdi\test\icmview\child.h
#define CHILD_CBWNDEXTRA  (sizeof(LPDIBINFO))
#define ICMVIEW_CBWNDEXTRA (sizeof(LPDIBINFO))

// windows\core\ntgdi\test\icmview\dibs.h
#define __FXPT32(d, f)      ( __FXPTMANTISSA(d, f) | __FXPTFRACTION(d, f) )

// windows\core\ntgdi\test\icmview\icmview.h
#define DEFAULT_ICM_PROFILE __TEXT("sRGB Color Space Profile.ICM")

// windows\core\ntgdi\test\imgtest\disp.h
#define AlphaDIBBlend(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13) 1

// windows\core\ntgdi\test\imgtest\tessel.cxx
#define RandColor(c) (0xffff & ( c + ((rand() & (MAX_RAND_COLOR -1)) - (MAX_RAND_COLOR/2))))

// windows\core\ntuser\client\btnctl.c
#define IsValidImage(imageType, realType, max)   \
    ((imageType < max) && (rgbType[imageType] == realType))

// windows\core\ntuser\client\cldib.c
#define RGBQ(r,g,b) RGB(b, g, r)
#define RGBQR(rgb)  GetBValue(rgb)
#define RGBQG(rgb)  GetGValue(rgb)
#define RGBQB(rgb)  GetRValue(rgb)

// windows\core\ntuser\client\lboxctl3.c
#define DDL_TYPE        (DDL_DRIVES | DDL_DIRECTORY | DDL_POSTMSGS)

// windows\core\ntuser\client\statctl.c
#define IsValidImage(imageType, realType, max) \
    ((imageType < max) && (rgbType[imageType] == realType))

// windows\core\ntuser\client\usercli.h
#define SetBestStretchMode(hdc, planes, bpp) \
    SetStretchBltMode(hdc, (((planes) * (bpp)) == 1 ? BLACKONWHITE : COLORONCOLOR))
#define RGBX(rgb)  RGB(GetBValue(rgb), GetGValue(rgb), GetRValue(rgb))

// windows\core\ntuser\inc\user.h
#define SYSRGB(i)             (gpsi->argbSystem[COLOR_##i])
#define SYSRGBRTL(i)          (gpsi->argbSystem[COLOR_##i])
#define TIF_PALETTEAWARE            (UINT)0x00000800

// windows\core\ntuser\kernel\clipbrd.c
#define DUMMY_DIB_HANDLE        (HANDLE)0x0002
#define IsDibHandle(fmt, hdata)      \
    (((fmt) == CF_DIB) && ((hdata) != DUMMY_DIB_HANDLE))

// windows\core\ntuser\kernel\sprite.c
#define COLORKEY_COLOR          RGB(255, 0, 255)

// windows\core\ntuser\kernel\userk.h
#define ProbeAndReadRect(Address)                         \
    (((Address) >= (RECT * const)MM_USER_PROBE_ADDRESS) ? \
        (*(volatile RECT * const)MM_USER_PROBE_ADDRESS) : (*(volatile RECT *)(Address)))

// windows\core\ntuser\kernel\visrgn.c
#define EmptyRect(prc)                        \
    (   prc->left >= prc->right               \
     || prc->top >= prc->bottom)

// windows\feime\chs\ntabc\winabc\abc95def.h
#define CO_LIGHTBLUE RGB(0,255,255)
#define CO_METHOD     RGB(0,40,80)
#define CO_CAP       RGB(255,0,0)
#define TColor1  RGB(0,0,0)
#define TColor2  RGB(0,0,255)
#define TColor4  RGB(0,0,128)
#define TColor3  RGB(64,0,128)

// windows\feime\chs\ntabc\winabc\abc95ui.c
#define SHENHUI RGB(0x80,0x80,0x80)
#define QIANHUI RGB(0xe0,0xe0,0x80)

// windows\feime\kor\imeui.c
#define BGR_BUTTONTEXT      (RGB(000,000,000))  // black
#define BGR_BUTTONSHADOW    (RGB(128,128,128))  // dark grey
#define BGR_BUTTONFACE      (RGB(192,192,192))  // bright grey
#define BGR_BUTTONHILIGHT   (RGB(255,255,255))  // white
#define FlipColor(rgb)      (RGB(GetBValue(rgb), GetGValue(rgb), GetRValue(rgb)))

// windows\netdde\src\netdde\nddegui.c
#define SETUP_HEADING_TEXT(hDC)                 \
        SetBkColor( hDC, RGB(255,255,255) );    \
        SetTextColor( hDC, RGB(0,0,0) )
#define SETUP_INFO_TEXT(hDC)                    \
        SetBkColor( hDC, RGB(255,255,255) );    \
        SetTextColor( hDC, RGB(0,0,0) )

// windows\oleacc\oleacc\statbar.cpp
#define LPRECT_IN_LPRECT(rc1,rc2)   ((rc1->left >= rc2->left) && \
                                     (rc1->right <= rc2->right) && \
                                     (rc1->top >= rc2->top) && \
                                     (rc1->bottom <= rc2->bottom))
#define RECT_IN_RECT(rc1,rc2)   ((rc1.left >= rc2.left) && \
                                 (rc1.right <= rc2.right) && \
                                 (rc1.top >= rc2.top) && \
                                 (rc1.bottom <= rc2.bottom))

// windows\richedit\inc30\imeshare.h
#define RGB_BLACK	(RGB(  0,  0,  0))
#define RGB_BLUE	(RGB(  0,  0,255))
#define RGB_CYAN	(RGB(  0,255,255))
#define RGB_GREEN   (RGB(  0,255,  0))
#define RGB_MAGENTA (RGB(255,  0,255))
#define RGB_RED		(RGB(255,  0,  0))
#define RGB_YELLOW  (RGB(255,255,  0))
#define RGB_WHITE   (RGB(255,255,255))
#define RGB_DKBLUE  (RGB(  0,  0,127))
#define RGB_DKCYAN  (RGB(  0,127,127))
#define RGB_DKGREEN (RGB(  0,127,  0))
#define RGB_DKMAGENTA (RGB(127,  0,127))
#define RGB_DKRED   (RGB(127,  0,  0))
#define RGB_DKYELLOW (RGB(127,127,  0))
#define RGB_DKGRAY  (RGB(127,127,127))
#define RGB_LTGRAY  (RGB(192,192,192))

// windows\richedit\inc30\richole.h
#define REO_DONTNEEDPALETTE	(0x00000020L)	// Object doesn't need palette

// windows\richedit\inc41\imaging.h
#define IMGERR_NOPALETTE        MAKE_IMGERR(2)

// windows\richedit\inc41\imeshare.h
#define RGB_BLACK	(RGB(  0,  0,  0))
#define RGB_BLUE	(RGB(  0,  0,255))
#define RGB_CYAN	(RGB(  0,255,255))
#define RGB_GREEN   (RGB(  0,255,  0))
#define RGB_MAGENTA (RGB(255,  0,255))
#define RGB_RED		(RGB(255,  0,  0))
#define RGB_YELLOW  (RGB(255,255,  0))
#define RGB_WHITE   (RGB(255,255,255))
#define RGB_DKBLUE  (RGB(  0,  0,127))
#define RGB_DKCYAN  (RGB(  0,127,127))
#define RGB_DKGREEN (RGB(  0,127,  0))
#define RGB_DKMAGENTA (RGB(127,  0,127))
#define RGB_DKRED   (RGB(127,  0,  0))
#define RGB_DKYELLOW (RGB(127,127,  0))
#define RGB_DKGRAY  (RGB(127,127,127))
#define RGB_LTGRAY  (RGB(192,192,192))

// windows\richedit\inc41\richole.h
#define REO_DONTNEEDPALETTE	(0x00000020L)	// Object doesn't need palette

// windows\richedit\lssrc\dispmisc.c
#define fUVerticalPlusVDirection	(fUVertical|fVDirection)			// see comments in lstfset.c

// windows\richedit\re41\_common.h
#define EM_GETAUTOCORRECTPROC	(WM_USER + 233)
#define EM_SETAUTOCORRECTPROC	(WM_USER + 234)

// windows\richedit\re41\rtfwrit2.cpp
#define	WHITE	RGB(255, 255, 255)
```

