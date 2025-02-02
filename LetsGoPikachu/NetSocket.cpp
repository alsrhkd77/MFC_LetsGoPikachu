// NetSocket.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "NetSocket.h"
#include "SNet.h"


// NetSocket

NetSocket::NetSocket()
{
}

NetSocket::~NetSocket()
{
}


// NetSocket 멤버 함수

void NetSocket::SetParent(CDialog *pWnd) {
	this->pWnd = pWnd;
}

void NetSocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0) {
		((SNet *)pWnd)->OnAccept();
	}
	CSocket::OnAccept(nErrorCode);
}


void NetSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0) {
		((SNet *)pWnd)->OnClose();
	}
	CSocket::OnClose(nErrorCode);
}


void NetSocket::OnConnect(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0) {
		//((SNet *)pWnd)->OnConnect();
	}
	CSocket::OnConnect(nErrorCode);
}


void NetSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0) {
		((SNet *)pWnd)->OnReceive();
	}
	CSocket::OnReceive(nErrorCode);
}


void NetSocket::OnSend(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0) {
		((SNet *)pWnd)->OnSend();
	}
	CSocket::OnSend(nErrorCode);
}
