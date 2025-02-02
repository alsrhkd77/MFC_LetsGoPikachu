// SNet.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "SNet.h"
#include "afxdialogex.h"


// SNet 대화 상자

IMPLEMENT_DYNAMIC(SNet, CDialog)

SNet::SNet(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SNET_DIALOG, pParent)
{

}

SNet::SNet(int listNo1, int listNo2, int listNo3, int listNo4, int listNo5, int listNo6
	, int level1, int level2, int level3, int level4, int level5, int level6
	, CString name1, CString name2, CString name3, CString name4, CString name5, CString name6
	, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SNET_DIALOG, pParent)
{
	listNo[0] = listNo1;
	listNo[1] = listNo2;
	listNo[2] = listNo3;
	listNo[3] = listNo4;
	listNo[4] = listNo5;
	listNo[5] = listNo6;

	level[0] = level1;
	level[1] = level2;
	level[2] = level3;
	level[3] = level4;
	level[4] = level5;
	level[5] = level6;

	name[0] = name1;
	name[1] = name2;
	name[2] = name3;
	name[3] = name4;
	name[4] = name5;
	name[5] = name6;

	firstFlag = true;
	getchange = false;
	sendchange = false;
	select = 0;
	//getListNo = 0;
	//getLevel = 0;
	selectNo = 0;
	selectlevel = 0;
	sever.SetParent(this);
	client.SetParent(this);
	sever.Create(6058);
	sever.Listen();
}

SNet::~SNet()
{
	//OnClose();
}

void SNet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);


	
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	//  DDX_Control(pDX, IDOK, m_butt_ok);
	DDX_Control(pDX, ID_BUTT_OK, m_buttok);

	if (firstFlag) {
		CString temp;
		for (int i = 0; i < 6; i++) {
			if (listNo[i] != 0 && level[i] != 0) {
				temp.Format(name[i] + _T("-Lv: %d"), level[i]);
			}
			else {
				temp.Format(_T("none"));
			}
			m_combo.AddString(temp);
		}
		firstFlag = false;
	}
	DDX_Control(pDX, IDC_STATUS, m_statue);
	m_statue.SetWindowTextW(_T("입장을 기다리는 중입니다."));
}


BEGIN_MESSAGE_MAP(SNet, CDialog)
	ON_BN_CLICKED(IDOK, &SNet::OnBnClickedOk)
	ON_BN_CLICKED(ID_BUTT_OK, &SNet::OnBnClickedButtOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &SNet::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// SNet 메시지 처리기


void SNet::OnBnClickedOk()
{
	
}

void SNet::OnAccept() {
	sever.Accept(client);
	//MessageBox(_T("연결 성공!"));
	m_buttok.EnableWindow(TRUE);
	m_statue.SetWindowTextW(_T("보낼 포켓몬을 선택해주세요!"));
}

void SNet::OnSend() {
	int iSent;
	char strMsg[20];
	ZeroMemory(strMsg, sizeof(strMsg));
	strcpy_s(strMsg, "netok");
	int iLen = strlen(strMsg);
	iSent = client.Send(LPCTSTR(strMsg), iLen);
	if (iSent == SOCKET_ERROR)
	{
		MessageBox(_T("연결 실패."));
	}
}
void SNet::OnReceive() {
	char strMsg[100];
	char D[2];
	char *pBuf = new char[1025];
	int iBufSize = 1024;
	int iRcvd;
	strcpy_s(D, "D");
	iRcvd = client.Receive(pBuf, iBufSize);
	if (iRcvd == SOCKET_ERROR)
	{
		MessageBox(_T("받기 실패"));
	}
	else
	{
		pBuf[iRcvd] = NULL;
		strcpy_s(strMsg, pBuf);
		if (strcmp(pBuf, "netok") == 0) {
			MessageBox(_T("연결 성공!"));
			m_buttok.EnableWindow(TRUE);
		}
		if (strMsg[0] == D[0]) {
			//Num = ((int)strMsg[2] * 10) + (int)strMsg[2];
			//48
			//1=53
			//2=56
			//3=57
			//4=55
			//4=55
			//getListNo = (((int)strMsg[1] * 10) - 48) + (int)strMsg[2] - 48;
			//getLevel = (((int)strMsg[3] * 10) - 48) + (int)strMsg[4] - 48;
			getListNo = (((int)strMsg[1] - 48) * 10) + (int)strMsg[2] - 48;
			getLevel = (((int)strMsg[3] - 48) * 10) + (int)strMsg[4] - 48;
			getchange = true;
			m_statue.SetWindowTextW(_T("잠시만 기다려주세요.."));
			if (getchange == true && sendchange == true) {
				MessageBox(_T("통신교환성공!"));
				OnClose();
				OnOK();
			}
		}
	}
}
void SNet::OnClose() {
	sever.Close();
	client.Close();
	m_statue.SetWindowTextW(_T("입장을 기다리는 중입니다."));
	m_buttok.EnableWindow(FALSE);
}

void SNet::OnBnClickedButtOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iSent;
	//char strMsg[50];
	char strMsg[6];
	CString temp;
	ZeroMemory(strMsg, sizeof(strMsg));
	strMsg[0] = (char)68;
	strMsg[1] = (char)((selectNo / 10) + 48);
	strMsg[2] = (char)((selectNo % 10) + 48);
	strMsg[3] = (char)((selectlevel / 10) + 48);
	strMsg[4] = (char)((selectlevel % 10) + 48);
	strMsg[5] = NULL;
	int iLen = strlen(strMsg);
	iSent = client.Send(LPCTSTR(strMsg), iLen);
	if (iSent == SOCKET_ERROR)
	{
		MessageBox(_T("전송 실패. 다시 전송해주십시오"));
	}
	else {
		sendchange = true;
		m_buttok.EnableWindow(FALSE);
	}
	if (getchange == true && sendchange == true) {
		MessageBox(_T("통신교환성공!"));
		CString temp;
		temp.Format(_T("NO:%d lv: %d"), getListNo, getLevel);
		//MessageBox(temp);
		OnClose();
		OnOK();
	}
}


void SNet::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString temp;
	UpdateData(TRUE);
	select = m_combo.GetCurSel();
	m_combo.GetLBText(select, temp);
	if (temp == "none") {
		selectNo = 0;
		selectlevel = 0;
		m_buttok.EnableWindow(FALSE);
	}
	else {
		selectNo = listNo[select];
		selectlevel = level[select];
		m_buttok.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}
