#pragma once

// NetSocket 명령 대상

class NetSocket : public CSocket
{
public:
	CDialog *pWnd;
	NetSocket();
	virtual ~NetSocket();
	void SetParent(CDialog *pWnd);
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
};


