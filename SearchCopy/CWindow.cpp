// CWindow.cpp: 구현 파일
//

#include "pch.h"
#include "SearchCopy.h"
#include "CWindow.h"

CDrawVideoClass* CWindow::m_ddraw;

// CWindow

IMPLEMENT_DYNAMIC(CWindow, CButton)

CWindow::CWindow()
{

}

CWindow::~CWindow()
{
}


void CWindow::SetArea(CRect* rc)
{
	m_ddraw->SetArea(m_pOwner->m_ScreenRect, m_nScreenNo, rc); //t
}

void CWindow::DrawImage()
{
	if (m_bShow == FALSE)
	{
		return;
	}

	//t	CDC			*pDC = GetDC();
	CDC* pDC = m_pOwner->m_ViewPan->GetDC();
	char		infoTxt[128];
	CString		strCamera;
	int			ch_no; //t


/*t	if (m_pOwner->m_iPanoPush == ID_BT_CHPANORAMA)
	{
		sprintf(infoTxt, "%02d", m_pOwner->m_nCurCam+1);
	}
	else
	{
		if (m_pOwner->m_ViewChannel[m_nScreenNo] == FALSE)
			return;

		m_pOwner->m_BtnCamGroup.GetCameraID(m_nScreenNo, strCamera);

		sprintf(infoTxt, "%02d.%s\x1f%02d:%02d:%02d", m_nScreenNo+1, (LPCTSTR) strCamera, m_chunkLast.tm.wHour, m_chunkLast.tm.wMinute, m_chunkLast.tm.wSecond);
	}
t*/
//t ---------------------------------------------------------------
	//if (m_pOwner->m_iPanoPush == ID_BT_CHPANORAMA)
	//{
	//	ch_no = m_pOwner->m_nCurCam;
	//}
	//else
	//{
		ch_no = m_nScreenNo;
	//}
	//m_pOwner->m_BtnCamGroup.GetCameraID(ch_no, strCamera);


	char		infoChannel[64];
	char		infoTime[64];
	memset(infoChannel, 0x00, sizeof(infoChannel));
	memset(infoTime, 0x00, sizeof(infoTime));
	memset(infoTxt, 0x00, sizeof(infoTxt));

	if (m_pOwner->m_nOSDChannel != 6)
	{
		sprintf(infoChannel, "%s", (LPCTSTR)strCamera);
		sprintf(infoTxt, "%s", infoChannel);
	}
	if (m_pOwner->m_nOSDTime != 6)
	{
		//sprintf(infoTime, "\x1f%02d:%02d:%02d", m_chunkLast.tm.wHour, m_chunkLast.tm.wMinute, m_chunkLast.tm.wSecond);
		sprintf(infoTxt, "%s%s", infoChannel, infoTime);
	}

	switch (m_pOwner->m_Split)
	{
	case 4:
		// change GSS
		//if (m_pOwner->m_iZoom != ID_BT_ZOOM)
		//{
		//	//t				m_ddraw->SetZoom(FALSE, NULL);
			m_ddraw->SetZoom(m_nScreenNo, FALSE, NULL); //t
		//}
		/*if (IsColorAdjust() == TRUE && m_pOwner->m_nCurCam == m_nScreenNo)
		{
			DrawAdjustImage(pDC->m_hDC, m_rectPlaySelectArea, 0, 0, 0, infoTxt);
		}*/
		//else
		//{
			DrawImageSplit(pDC->m_hDC, infoTxt);
		//}
		break;
	}
	ReleaseDC(pDC);
}

void CWindow::DrawImageSplit(HDC hDC, LPSTR strText)
{
	//if (m_bImageReady)
	//{

	//	m_ddraw->SetImageSize(m_nScreenNo, m_bmi.bmiHeader.biWidth, m_bmi.bmiHeader.biHeight); //t
	//	if (m_pOwner->m_iPanoPush == ID_BT_CHPANORAMA)
	//	{
	//		if (m_pImageYUV != NULL)
	//		{
	//			if (m_bPanoramaEndDisplay)
	//				m_ddraw->DrawImage(m_nScreenNo, m_pImageYUV, m_bmi.bmiHeader.biWidth, m_bmi.bmiHeader.biHeight, 0, strText, TRUE); //t
	//			else
	//				m_ddraw->DrawImage(m_nScreenNo, m_pImageYUV, m_bmi.bmiHeader.biWidth, m_bmi.bmiHeader.biHeight, 0, strText, FALSE); //t
	//		}
	//	}
	//	else if (m_pOwner->m_nCurCam == m_nScreenNo)
	//	{
	//		if (m_pImageYUV != NULL)
	//		{
	//			if (m_bmi.bmiHeader.biWidth > IMAGE_WIDTH_640 && m_bmi.bmiHeader.biHeight > IMAGE_HEIGHT_480)
	//			{
	//				//					LPBYTE	yuvRescale	= new BYTE[IMAGE_WIDTH_640*IMAGE_HEIGHT_480*2];
	//				//					m_Decoder->RescaleYUY2(m_pImageYUV, m_bmi.bmiHeader.biWidth, m_bmi.bmiHeader.biHeight, yuvRescale, IMAGE_WIDTH_640, IMAGE_HEIGHT_480);
	//				//					m_ddraw->SetImageSize(m_nScreenNo, IMAGE_WIDTH_640, IMAGE_HEIGHT_480); //t
	//				//					m_ddraw->DrawImage(m_nScreenNo, yuvRescale, IMAGE_WIDTH_640, IMAGE_HEIGHT_480, 0, strText, TRUE); //t
	//				//					delete [] yuvRescale;
	//				m_ddraw->DrawImage(m_nScreenNo, m_pImageYUV, m_bmi.bmiHeader.biWidth, m_bmi.bmiHeader.biHeight, 0, strText, TRUE); //t
	//			}
	//			else
	//			{
	//				m_ddraw->DrawImage(m_nScreenNo, m_pImageYUV, m_bmi.bmiHeader.biWidth, m_bmi.bmiHeader.biHeight, 0, strText, TRUE); //t
	//			}
	//		}
	//	}
	//	else
	//	{
	//		if (m_pImageYUV != NULL)
	//		{
	//			if (m_bmi.bmiHeader.biWidth > IMAGE_WIDTH_640 && m_bmi.bmiHeader.biHeight > IMAGE_HEIGHT_480)
	//			{
	//				//					LPBYTE	yuvRescale	= new BYTE[IMAGE_WIDTH_640*IMAGE_HEIGHT_480*2];
	//				//					m_Decoder->RescaleYUY2(m_pImageYUV, m_bmi.bmiHeader.biWidth, m_bmi.bmiHeader.biHeight, yuvRescale, IMAGE_WIDTH_640, IMAGE_HEIGHT_480);
	//				//					m_ddraw->SetImageSize(m_nScreenNo, IMAGE_WIDTH_640, IMAGE_HEIGHT_480); //t
	//				//					m_ddraw->DrawImage(m_nScreenNo, yuvRescale, IMAGE_WIDTH_640, IMAGE_HEIGHT_480, 0, strText, TRUE); //t
	//				//					delete [] yuvRescale;
	//				m_ddraw->DrawImage(m_nScreenNo, m_pImageYUV, m_bmi.bmiHeader.biWidth, m_bmi.bmiHeader.biHeight, 0, strText, TRUE); //t
	//			}
	//			else
	//			{
	//				m_ddraw->DrawImage(m_nScreenNo, m_pImageYUV, m_bmi.bmiHeader.biWidth, m_bmi.bmiHeader.biHeight, 0, strText, TRUE); //t
	//			}
	//		}
	//	}
	//}
	//else
	//{
		m_ddraw->SetImageSize(m_nScreenNo, 320, 240); //t
		m_ddraw->DrawImage(m_nScreenNo, m_pOwner->m_hMainLogoBitmap, 320, 240, 10, strText, FALSE); //t
	//}
}

BEGIN_MESSAGE_MAP(CWindow, CButton)
END_MESSAGE_MAP()



// CWindow 메시지 처리기


