// Setting.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "Setting.h"
#include "afxdialogex.h"


// Setting 대화 상자

IMPLEMENT_DYNAMIC(Setting, CDialog)

Setting::Setting(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SETTING_DIALOG, pParent)
	, m_back(0)
	, m_effect(0)
{
	back_select = 0;
	effect_select = 0;
}

Setting::Setting(int back_select, int effect_select, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SETTING_DIALOG, pParent)
	, m_back(back_select)
	, m_effect(effect_select)
{
	this->back_select = back_select;
	this->effect_select = effect_select;
}

Setting::~Setting()
{
}

void Setting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_back);
	DDX_Radio(pDX, IDC_RADIO3, m_effect);
	//m_back = back_select;
	//m_effect = effect_select;
}


BEGIN_MESSAGE_MAP(Setting, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, &Setting::OnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Setting::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &Setting::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &Setting::OnBnClickedRadio4)
END_MESSAGE_MAP()


// Setting 메시지 처리기


void Setting::OnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	back_select = m_back;
	UpdateData(FALSE);
}


void Setting::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	back_select = m_back;
	UpdateData(FALSE);
}


void Setting::OnBnClickedRadio3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	effect_select = m_effect;
	UpdateData(FALSE);
}


void Setting::OnBnClickedRadio4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	effect_select = m_effect;
	UpdateData(FALSE);
}
