#pragma once


// CFileSystem

class CFileSystem : public CWnd
{
	DECLARE_DYNAMIC(CFileSystem)

public:
	CFileSystem();
	virtual ~CFileSystem();

	int		Open(CWnd* hWnd, LPCTSTR szFileSystemPath, BYTE* fAvailableChannel);
	int		Open(CWnd* hWnd, LPCTSTR szDBIP, int nDBPort, LPCTSTR szDBID, LPCTSTR szDBPasswd);
	int		Close(void);
	int		GetOldestTime(SYSTEMTIME* OldestTime);
	int		GetNewestTime(SYSTEMTIME* NewestTime);
	int		GetSaveDateInfo(long nYear, long nMonth, BYTE* lpSaveFlags);
	int		GetSaveTimeInfo(long nYear, long nMonth, long nDay, BYTE* lpSaveFlags);
	int		GetSaveMinuteInfo(long nYear, long nMonth, long nDay, long nHour, BYTE* lpSaveFlags);
	int		GetSaveSecondInfo(long nYear, long nMonth, long nDay, long nHour, long nMinute, BYTE* lpSaveFlags);
	int		SetUsedChannels(BYTE* fChannel);
	int		SetUsedChannel(BYTE nChannel, BOOL bFlag);
	int		ReadData(DWORD nOption, BYTE* Buffer, SYSTEMTIME* tm, WORD* nChannel, DWORD* nSize, WORD* nWidth, WORD* nHeight, WORD* nFrameType, WORD* nDataType, WORD* nSaveMode, WORD* nCodecType, __int64* dts);
	int		ReadNextData(DWORD nOption, BYTE* Buffer, SYSTEMTIME* tm, WORD* nChannel, DWORD* nSize, WORD* nWidth, WORD* nHeight, WORD* nFrameType, WORD* nDataType, WORD* nSaveMode, WORD* nCodecType, __int64* dts);
	int		ReadPrevData(DWORD nOption, BYTE* Buffer, SYSTEMTIME* tm, WORD* nChannel, DWORD* nSize, WORD* nWidth, WORD* nHeight, WORD* nFrameType, WORD* nDataType, WORD* nSaveMode, WORD* nCodecType, __int64* dts);
	int		GetViewerInfo(LPCTSTR szTargetFileName, BOOL bfOverWrite);

	int SetUsedChannels(BYTE *fChannel);
private:
	CWnd* m_pWnd;
	long			m_FSKind;			// 0 = None, 1 = Local, 2 = Remote

	BYTE			m_btAvailableChannel[128];

	//CDBHandler* m_FSLocal;
	//CRDBHandler* m_FSRemote;
	BOOL			m_bfSocketInit;

	void	Printf(LPCTSTR FileName, const char* format, ...);


protected:
	DECLARE_MESSAGE_MAP()
};


