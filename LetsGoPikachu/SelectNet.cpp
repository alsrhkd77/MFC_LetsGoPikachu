// SelectNet.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "SelectNet.h"
#include "afxdialogex.h"


// SelectNet 대화 상자

IMPLEMENT_DYNAMIC(SelectNet, CDialog)

SelectNet::SelectNet(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SELECTNET_DIALOG, pParent)
{
	select = 0;
}

SelectNet::~SelectNet()
{
}

void SelectNet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SelectNet, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &SelectNet::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &SelectNet::OnBnClickedButton2)
END_MESSAGE_MAP()


// SelectNet 메시지 처리기


void SelectNet::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	select = 1;
	OnOK();
}


void SelectNet::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	select = 2;
	OnOK();
}
