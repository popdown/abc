#pragma once

#include "ddraw.h"

// CDrawVideoClass

#define MAX_CHANNEL		64

#define DDSD_CAPS               0x00000001l     // default

/*
 * dwHeight field is valid.
 */
#define DDSD_HEIGHT             0x00000002l

 /*
  * dwWidth field is valid.
  */
#define DDSD_WIDTH              0x00000004l

#define DDSD_PIXELFORMAT        0x00001000l

#define DD_OK                                   S_OK


class CDrawVideoClass : public CWnd
{


    DECLARE_DYNAMIC(CDrawVideoClass)

    


public:
    LPDIRECTDRAWSURFACE7	m_lpDDSBackBuffer;

private:

	int						m_chNum;
	CRect					m_chArea[MAX_CHANNEL];
	COLORREF				m_rgbBackground;
    COLORREF				m_rgbOSD;
    COLORREF				m_rgbRectCurrent;
    COLORREF				m_rgbRectNormal;

public:
	CDrawVideoClass();
	virtual ~CDrawVideoClass();
    //typedef struct IDirectDrawSurface7      FAR* LPDIRECTDRAWSURFACE7;
	void					SetArea(RECT Canvas, int ch, CRect Rect);
	void                    EmptyCanvas();

    BOOL					DrawImage(int ch, LPVOID pImg, int w, int h, int img_type, LPSTR pInfoTxt, BOOL cur_ch);
    void					SetZoom(int ch,BOOL bZoom, LPRECT rcZoom);

    UINT                    m_uiFontSize;
    UINT					m_uiDTFormatChannel;
    UINT					m_uiDTFormatTime;
    UINT					m_uiDTFormatSpeed;

	CRect					m_Canvas;
    HRESULT					SetImageSize(int ch, int w, int h);

    CPoint					m_iView[MAX_CHANNEL];

   

	//HWND m_hWnd;
    STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC2, LPDIRECTDRAWSURFACE7 FAR*, IUnknown FAR*) PURE;

    LPDIRECTDRAW7			m_lpDD7;
    LPDIRECTDRAWSURFACE7	m_lpDDS7Primary;
    BOOL					m_bZoom[MAX_CHANNEL];		// Zoom
    CRect					m_rcZoom[MAX_CHANNEL];

    DDSURFACEDESC2			m_DDSd2;

    void					DrawOSD(HDC hDC, int ch, LPSTR pInfoTxt);
    void					DrawRectangle(HDC hDC, int ch, BOOL bCurrent);
protected:
	DECLARE_MESSAGE_MAP()
};


