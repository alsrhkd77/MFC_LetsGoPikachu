// CNet.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "CNet.h"
#include "afxdialogex.h"


// CNet 대화 상자

IMPLEMENT_DYNAMIC(CNet, CDialog)

CNet::CNet(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CNET_DIALOG, pParent)
{

}

CNet::CNet(int listNo1, int listNo2, int listNo3, int listNo4, int listNo5, int listNo6
	, int level1, int level2, int level3, int level4, int level5, int level6
	, CString name1, CString name2, CString name3, CString name4, CString name5, CString name6
	, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CNET_DIALOG, pParent)
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
	client.SetParent(this);
	sever.SetParent(this);
	getchange = false;
	sendchange = false;
	select = 0;
	//getListNo = 0;
	//getLevel = 0;
	selectNo = 0;
	selectlevel = 0;
	adress.Format(_T("localhost"));
}

CNet::~CNet()
{
	//OnClose();
}

void CNet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
	DDX_Control(pDX, IDC_BUTT_CON, butt_con);
	
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, ID_BUTT_OK, butt_ok);
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
	DDX_Control(pDX, IDC_IPADDRESS1, addrCon);
	DDX_Control(pDX, IDC_STATUS, m_status);
	m_status.SetWindowTextW(_T("ip주소를 입력한 후\n연결 버튼을 눌러주세여!\n미입력시 localhost로 연결됩니다."));
}


BEGIN_MESSAGE_MAP(CNet, CDialog)
	ON_BN_CLICKED(IDOK, &CNet::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTT_CON, &CNet::OnBnClickedButtCon)
	ON_BN_CLICKED(ID_BUTT_OK, &CNet::OnBnClickedButtOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CNet::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CNet 메시지 처리기


void CNet::OnBnClickedOk()
{
}

void CNet::OnAccept() {
	sever.Accept(client);
}
void CNet::OnSend() {

}
void CNet::OnReceive() {
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
			butt_con.EnableWindow(FALSE);
			butt_ok.EnableWindow(TRUE);
			m_status.SetWindowTextW(_T("교환 할 포켓몬을 선택해주세요!"));
		}
		if (strMsg[0] == D[0]) {
			//Num = ((int)strMsg[2] * 10) + (int)strMsg[2];
			//48
			//1=53
			//2=56
			//3=57
			//4=55
			//getListNo = (((int)strMsg[1] * 10) - 48) + (int)strMsg[2] - 48;
			//getLevel = (((int)strMsg[3] * 10) - 48) + (int)strMsg[4] - 48;
			getListNo = (((int)strMsg[1] - 48) * 10) + (int)strMsg[2] - 48;
			getLevel = (((int)strMsg[3]  - 48) * 10) + (int)strMsg[4] - 48;
			
			getchange = true;
			butt_con.EnableWindow(FALSE);
			if (getchange == true && sendchange == true) {
				MessageBox(_T("통신교환성공!"));
				OnClose();
				OnOK();
			}
		}
	}
}
void CNet::OnClose() {
	MessageBox(_T("연결이 종료되었습니다."));
	m_status.SetWindowTextW(_T("ip주소를 입력한 후\n연결 버튼을 눌러주세여!\n미입력시 localhost로 연결됩니다."));
	sever.Close();
	client.Close();
	butt_con.EnableWindow(TRUE);
	butt_ok.EnableWindow(FALSE);
}

void CNet::OnConnect() {
	MessageBox(_T("클라이언트connect"));
}

void CNet::OnBnClickedButtCon()	//연결버튼
{
	m_status.SetWindowTextW(_T("연결중입니다. 잠시만 기다려주세요.."));
	UpdateData(TRUE);
	addrCon.GetWindowTextW(adress);
	if (adress == "0.0.0.0") {
		adress.Format(_T("localhost"));
	}
	UpdateData(FALSE);
	client.Create();
	client.Connect(adress, 6058);
	int iSent;
	char strMsg[20];
	ZeroMemory(strMsg, sizeof(strMsg));
	strcpy_s(strMsg, "netok");
	int iLen = strlen(strMsg);
	iSent = client.Send(LPCTSTR(strMsg), iLen);
	if (iSent == SOCKET_ERROR)
	{
		MessageBox(_T("연결 실패. 다시 시도해주십시오"));
		m_status.SetWindowTextW(_T("다시 시도해주세요!"));
		OnClose();
	}
}


void CNet::OnBnClickedButtOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iSent;
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
		m_status.SetWindowTextW(_T("다시 시도해주세요!"));
	}
	else {
		sendchange = true;
		butt_ok.EnableWindow(FALSE);
		m_status.SetWindowTextW(_T("상대방의 응답을 기다리고있습니다\n잠시만 기다려주세요.."));
	}
	if (getchange == true && sendchange == true) {
		MessageBox(_T("통신교환성공!"));
		OnClose();
		OnOK();
	}
}


void CNet::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString temp;
	UpdateData(TRUE);
	select = m_combo.GetCurSel();
	m_combo.GetLBText(select, temp);
	if (temp == "none") {
		selectNo = 0;
		selectlevel = 0;
		butt_ok.EnableWindow(FALSE);
	}
	else {
		selectNo = listNo[select];
		selectlevel = level[select];
		butt_ok.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}
