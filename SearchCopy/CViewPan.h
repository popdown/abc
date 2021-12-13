#pragma once


// CViewPan

class CViewPan : public CWnd
{
	DECLARE_DYNAMIC(CViewPan)

public:
	CViewPan();
	virtual ~CViewPan();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


