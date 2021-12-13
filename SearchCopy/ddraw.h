#pragma once

#define _FACDD  0x876

#define MAKE_DDHRESULT( code )  MAKE_HRESULT( 1, _FACDD, code )

#define DDBLT_ASYNC                             0x00000200l

#define DDBLT_WAIT                              0x01000000l

#define DDERR_SURFACELOST                       MAKE_DDHRESULT( 450 )

#define DDBLT_DONOTWAIT                         0x08000000l


typedef struct IDirectDrawSurface7      FAR* LPDIRECTDRAWSURFACE7;
typedef struct IDirectDraw7             FAR* LPDIRECTDRAW7;
typedef struct _DDSURFACEDESC2          FAR* LPDDSURFACEDESC2;
class ddraw
{
};


#undef INTERFACE
#define INTERFACE IDirectDrawSurface7
DECLARE_INTERFACE_(IDirectDrawSurface7, IUnknown)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG, Release) (THIS) PURE;
    /*** IDirectDrawSurface methods ***/
   // STDMETHOD(AddAttachedSurface)(THIS_ LPDIRECTDRAWSURFACE7) PURE;
    STDMETHOD(AddOverlayDirtyRect)(THIS_ LPRECT) PURE;
    STDMETHOD(Blt)(THIS_ LPRECT, LPDIRECTDRAWSURFACE7, LPRECT, DWORD, LPDDBLTFX) PURE;
    //STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD) PURE;
    //STDMETHOD(BltFast)(THIS_ DWORD, DWORD, LPDIRECTDRAWSURFACE7, LPRECT, DWORD) PURE;
    //STDMETHOD(DeleteAttachedSurface)(THIS_ DWORD, LPDIRECTDRAWSURFACE7) PURE;
    //STDMETHOD(EnumAttachedSurfaces)(THIS_ LPVOID, LPDDENUMSURFACESCALLBACK7) PURE;
    //STDMETHOD(EnumOverlayZOrders)(THIS_ DWORD, LPVOID, LPDDENUMSURFACESCALLBACK7) PURE;
    //STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE7, DWORD) PURE;
    //STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS2, LPDIRECTDRAWSURFACE7 FAR*) PURE;
    //STDMETHOD(GetBltStatus)(THIS_ DWORD) PURE;
    //STDMETHOD(GetCaps)(THIS_ LPDDSCAPS2) PURE;
    //STDMETHOD(GetClipper)(THIS_ LPDIRECTDRAWCLIPPER FAR*) PURE;
    //STDMETHOD(GetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(GetDC)(THIS_ HDC FAR*) PURE;
    STDMETHOD(GetFlipStatus)(THIS_ DWORD) PURE;
    STDMETHOD(GetOverlayPosition)(THIS_ LPLONG, LPLONG) PURE;
    //STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE FAR*) PURE;
    //STDMETHOD(GetPixelFormat)(THIS_ LPDDPIXELFORMAT) PURE;
    //STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC2) PURE;
    //STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC2) PURE;
    STDMETHOD(IsLost)(THIS) PURE;
    //STDMETHOD(Lock)(THIS_ LPRECT, LPDDSURFACEDESC2, DWORD, HANDLE) PURE;
    STDMETHOD(ReleaseDC)(THIS_ HDC) PURE;
    STDMETHOD(Restore)(THIS) PURE;
    // STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) PURE;
    // STDMETHOD(SetColorKey)(THIS_ DWORD, LPDDCOLORKEY) PURE;
    STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG) PURE;
    //STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE) PURE;
    STDMETHOD(Unlock)(THIS_ LPRECT) PURE;
    //STDMETHOD(UpdateOverlay)(THIS_ LPRECT, LPDIRECTDRAWSURFACE7, LPRECT, DWORD, LPDDOVERLAYFX) PURE;
    STDMETHOD(UpdateOverlayDisplay)(THIS_ DWORD) PURE;
    //STDMETHOD(UpdateOverlayZOrder)(THIS_ DWORD, LPDIRECTDRAWSURFACE7) PURE;
    /*** Added in the v2 interface ***/
    STDMETHOD(GetDDInterface)(THIS_ LPVOID FAR*) PURE;
    STDMETHOD(PageLock)(THIS_ DWORD) PURE;
    STDMETHOD(PageUnlock)(THIS_ DWORD) PURE;
    /*** Added in the v3 interface ***/
    //STDMETHOD(SetSurfaceDesc)(THIS_ LPDDSURFACEDESC2, DWORD) PURE;
    /*** Added in the v4 interface ***/
    STDMETHOD(SetPrivateData)(THIS_ REFGUID, LPVOID, DWORD, DWORD) PURE;
    STDMETHOD(GetPrivateData)(THIS_ REFGUID, LPVOID, LPDWORD) PURE;
    STDMETHOD(FreePrivateData)(THIS_ REFGUID) PURE;
    STDMETHOD(GetUniquenessValue)(THIS_ LPDWORD) PURE;
    STDMETHOD(ChangeUniquenessValue)(THIS) PURE;
    /*** Moved Texture7 methods here ***/
    STDMETHOD(SetPriority)(THIS_ DWORD) PURE;
    STDMETHOD(GetPriority)(THIS_ LPDWORD) PURE;
    STDMETHOD(SetLOD)(THIS_ DWORD) PURE;
    STDMETHOD(GetLOD)(THIS_ LPDWORD) PURE;
};


typedef struct _DDBLTFX
{
    DWORD       dwSize;                         // size of structure
    DWORD       dwDDFX;                         // FX operations
    DWORD       dwROP;                          // Win32 raster operations
    DWORD       dwDDROP;                        // Raster operations new for DirectDraw
    DWORD       dwRotationAngle;                // Rotation angle for blt
    DWORD       dwZBufferOpCode;                // ZBuffer compares
    DWORD       dwZBufferLow;                   // Low limit of Z buffer
    DWORD       dwZBufferHigh;                  // High limit of Z buffer
    DWORD       dwZBufferBaseDest;              // Destination base value
    DWORD       dwZDestConstBitDepth;           // Bit depth used to specify Z constant for destination
    //union
    //{
    //    DWORD   dwZDestConst;                   // Constant to use as Z buffer for dest
    //    LPDIRECTDRAWSURFACE lpDDSZBufferDest;   // Surface to use as Z buffer for dest
    //} DUMMYUNIONNAMEN(1);
    //DWORD       dwZSrcConstBitDepth;            // Bit depth used to specify Z constant for source
    //union
    //{
    //    DWORD   dwZSrcConst;                    // Constant to use as Z buffer for src
    //    LPDIRECTDRAWSURFACE lpDDSZBufferSrc;    // Surface to use as Z buffer for src
    //} DUMMYUNIONNAMEN(2);
    //DWORD       dwAlphaEdgeBlendBitDepth;       // Bit depth used to specify constant for alpha edge blend
    //DWORD       dwAlphaEdgeBlend;               // Alpha for edge blending
    //DWORD       dwReserved;
    //DWORD       dwAlphaDestConstBitDepth;       // Bit depth used to specify alpha constant for destination
    //union
    //{
    //    DWORD   dwAlphaDestConst;               // Constant to use as Alpha Channel
    //    LPDIRECTDRAWSURFACE lpDDSAlphaDest;     // Surface to use as Alpha Channel
    //} DUMMYUNIONNAMEN(3);
    //DWORD       dwAlphaSrcConstBitDepth;        // Bit depth used to specify alpha constant for source
    //union
    //{
    //    DWORD   dwAlphaSrcConst;                // Constant to use as Alpha Channel
    //    LPDIRECTDRAWSURFACE lpDDSAlphaSrc;      // Surface to use as Alpha Channel
    //} DUMMYUNIONNAMEN(4);
    //union
    //{
    //    DWORD   dwFillColor;                    // color in RGB or Palettized
    //    DWORD   dwFillDepth;                    // depth value for z-buffer
    //    DWORD   dwFillPixel;                    // pixel value for RGBA or RGBZ
    //    LPDIRECTDRAWSURFACE lpDDSPattern;       // Surface to use as pattern
    //} DUMMYUNIONNAMEN(5);
    //DDCOLORKEY  ddckDestColorkey;               // DestColorkey override
    //DDCOLORKEY  ddckSrcColorkey;                // SrcColorkey override
} DDBLTFX;

typedef DDBLTFX FAR* LPDDBLTFX;

typedef struct _DDSURFACEDESC2
{
    DWORD               dwSize;                 // size of the DDSURFACEDESC structure
    DWORD               dwFlags;                // determines what fields are valid
    DWORD               dwHeight;               // height of surface to be created
    DWORD               dwWidth;                // width of input surface
    //union
    //{
    //    LONG            lPitch;                 // distance to start of next line (return value only)
    //    DWORD           dwLinearSize;           // Formless late-allocated optimized surface size
    //} DUMMYUNIONNAMEN(1);
    //union
    //{
    //    DWORD           dwBackBufferCount;      // number of back buffers requested
    //    DWORD           dwDepth;                // the depth if this is a volume texture 
    //} DUMMYUNIONNAMEN(5);
    //union
    //{
    //    DWORD           dwMipMapCount;          // number of mip-map levels requestde
    //                                            // dwZBufferBitDepth removed, use ddpfPixelFormat one instead
    //    DWORD           dwRefreshRate;          // refresh rate (used when display mode is described)
    //    DWORD           dwSrcVBHandle;          // The source used in VB::Optimize
    //} DUMMYUNIONNAMEN(2);
    //DWORD               dwAlphaBitDepth;        // depth of alpha buffer requested
    //DWORD               dwReserved;             // reserved
    //LPVOID              lpSurface;              // pointer to the associated surface memory
    //union
    //{
    //    DDCOLORKEY      ddckCKDestOverlay;      // color key for destination overlay use
    //    DWORD           dwEmptyFaceColor;       // Physical color for empty cubemap faces
    //} DUMMYUNIONNAMEN(3);
    //DDCOLORKEY          ddckCKDestBlt;          // color key for destination blt use
    //DDCOLORKEY          ddckCKSrcOverlay;       // color key for source overlay use
    //DDCOLORKEY          ddckCKSrcBlt;           // color key for source blt use
    //union
    //{
    //    DDPIXELFORMAT   ddpfPixelFormat;        // pixel format description of the surface
    //    DWORD           dwFVF;                  // vertex format description of vertex buffers
    //} DUMMYUNIONNAMEN(4);
    //DDSCAPS2            ddsCaps;                // direct draw surface capabilities
    //DWORD               dwTextureStage;         // stage in multitexture cascade
} DDSURFACEDESC2;