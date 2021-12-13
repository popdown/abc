#pragma once

#include "CDrawVideoClass.h"
#include "SearchCopyDlg.h"
// CWindow

class CWindow : public CButton
{
	DECLARE_DYNAMIC(CWindow)

public:
	CWindow();
	virtual ~CWindow();
	static CDrawVideoClass* m_ddraw;

	void FlushBuffer(void);
	void SetArea(CRect* rc);
	void DrawImage();
	void DrawImageSplit(HDC hDC, LPSTR strText);

	CSearchCopyDlg* m_pOwner;
	BITMAPINFO m_bmi;

	BOOL				m_bShow;
	BOOL				m_bImageReady;
	CRect				m_rectImageArea;

	int m_nScreenNo;
protected:
	DECLARE_MESSAGE_MAP()
};


