// CNetSocket.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "CNetSocket.h"
#include "CNet.h"


// CNetSocket

CNetSocket::CNetSocket()
{
}

CNetSocket::~CNetSocket()
{
}


// CNetSocket 멤버 함수


void CNetSocket::SetParent(CDialog *pWnd) {
	this->pWnd = pWnd;
}

void CNetSocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0) {
		((CNet *)pWnd)->OnAccept();
	}
	CSocket::OnAccept(nErrorCode);
}


void CNetSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0) {
		((CNet *)pWnd)->OnClose();
	}
	CSocket::OnClose(nErrorCode);
}


void CNetSocket::OnConnect(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0) {
		((CNet *)pWnd)->OnConnect();
	}
	CSocket::OnConnect(nErrorCode);
}


void CNetSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0) {
		((CNet *)pWnd)->OnReceive();
	}
	CSocket::OnReceive(nErrorCode);
}


void CNetSocket::OnSend(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0) {
		((CNet *)pWnd)->OnSend();
	}
	CSocket::OnSend(nErrorCode);
}
