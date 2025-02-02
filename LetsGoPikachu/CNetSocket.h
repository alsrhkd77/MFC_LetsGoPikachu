#pragma once

// CNetSocket 명령 대상

class CNetSocket : public CSocket
{
public:
	CDialog *pWnd;
	CNetSocket();
	void SetParent(CDialog *pWnd);
	virtual ~CNetSocket();
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
};


