// SelectAttack.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "SelectAttack.h"
#include "afxdialogex.h"


// SelectAttack 대화 상자

IMPLEMENT_DYNAMIC(SelectAttack, CDialog)

SelectAttack::SelectAttack(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SELECTATTACK_DIALOG, pParent)
{
	select = 0;
}

SelectAttack::SelectAttack(CString skill1, CString skill2, CString skill3, CString skill4, int skillpoint1, int skillpoint2, int skillpoint3, int skillpoint4, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SELECTATTACK_DIALOG, pParent)
{
	this->skill1 = skill1;
	this->skill2 = skill2;
	this->skill3 = skill3;
	this->skill4 = skill4;
	this->skillpoint1 = convertNum(skillpoint1);
	this->skillpoint2 = convertNum(skillpoint2);
	this->skillpoint3 = convertNum(skillpoint3);
	this->skillpoint4 = convertNum(skillpoint4);
	select = 0;
}

SelectAttack::~SelectAttack()
{
}

void SelectAttack::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTT_SKILL1, m_skill1);
	DDX_Control(pDX, IDC_BUTT_SKILL2, m_skill2);
	DDX_Control(pDX, IDC_BUTT_SKILL3, m_skill3);
	DDX_Control(pDX, IDC_BUTT_SKILL4, m_skill4);
	m_skill1.SetWindowTextW(skill1);
	m_skill2.SetWindowTextW(skill2);
	m_skill3.SetWindowTextW(skill3);
	m_skill4.SetWindowTextW(skill4);
	DDX_Control(pDX, IDC_STATIC4, m_static4);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_STATIC2, m_static2);
	DDX_Control(pDX, IDC_STATIC3, m_static3);
	m_static1.SetWindowTextW(skillpoint1 + _T("/20"));
	m_static2.SetWindowTextW(skillpoint2 + _T("/10"));
	m_static3.SetWindowTextW(skillpoint3 + _T("/5"));
	m_static4.SetWindowTextW(skillpoint4 + _T("/3"));
	if (skillpoint1 == "0") {
		m_skill1.EnableWindow(FALSE);
	}
	if (skillpoint2 == "0") {
		m_skill2.EnableWindow(FALSE);
	}
	if (skillpoint3 == "0") {
		m_skill3.EnableWindow(FALSE);
	}
	if (skillpoint4 == "0") {
		m_skill4.EnableWindow(FALSE);
	}
}


BEGIN_MESSAGE_MAP(SelectAttack, CDialog)
	ON_BN_CLICKED(IDC_BUTT_SKILL1, &SelectAttack::OnClickedButtSkill1)
	ON_BN_CLICKED(IDC_BUTT_SKILL2, &SelectAttack::OnClickedButtSkill2)
	ON_BN_CLICKED(IDC_BUTT_SKILL3, &SelectAttack::OnClickedButtSkill3)
	ON_BN_CLICKED(IDC_BUTT_SKILL4, &SelectAttack::OnClickedButtSkill4)
	ON_BN_CLICKED(IDCANCEL, &SelectAttack::OnBnClickedCancel)
END_MESSAGE_MAP()


// SelectAttack 메시지 처리기


void SelectAttack::OnClickedButtSkill1()
{
	select = 1;
	OnOK();
}


void SelectAttack::OnClickedButtSkill2()
{
	select = 2;
	OnOK();
}


void SelectAttack::OnClickedButtSkill3()
{
	select = 3;
	OnOK();
}


void SelectAttack::OnClickedButtSkill4()
{
	select = 4;
	OnOK();
}


void SelectAttack::OnBnClickedCancel()
{
	select = 0;
	OnOK();
	//CDialog::OnCancel();
}


CString SelectAttack::convertNum(int num) {
	CString result;
	switch (num)
	{
	case 0:
		result.Format(_T("1"));
		break;
	case 1:
		result.Format(_T("1"));
		break;
	case 2:
		result.Format(_T("2"));
		break;
	case 3:
		result.Format(_T("3"));
		break;
	case 4:
		result.Format(_T("4"));
		break;
	case 5:
		result.Format(_T("5"));
		break;
	case 6:
		result.Format(_T("6"));
		break;
	case 7:
		result.Format(_T("7"));
		break;
	case 8:
		result.Format(_T("8"));
		break;
	case 9:
		result.Format(_T("9"));
		break;
	case 10:
		result.Format(_T("10"));
		break;
	case 11:
		result.Format(_T("11"));
		break;
	case 12:
		result.Format(_T("12"));
		break;
	case 13:
		result.Format(_T("13"));
		break;
	case 14:
		result.Format(_T("14"));
		break;
	case 15:
		result.Format(_T("15"));
		break;
	case 16:
		result.Format(_T("16"));
		break;
	case 17:
		result.Format(_T("17"));
		break;
	case 18:
		result.Format(_T("18"));
		break;
	case 19:
		result.Format(_T("19"));
		break;
	case 20:
		result.Format(_T("20"));
		break;
	default:
		break;
	}
	return result;
}