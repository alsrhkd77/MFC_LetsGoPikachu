// PokemonCenter.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "PokemonCenter.h"
#include "afxdialogex.h"
#include "Sound.h"


// PokemonCenter 대화 상자

IMPLEMENT_DYNAMIC(PokemonCenter, CDialog)

PokemonCenter::PokemonCenter(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_POKEMONCENTER_DIALOG, pParent)
{

}

PokemonCenter::PokemonCenter(int owngold, int gold, int sOnOff, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_POKEMONCENTER_DIALOG, pParent)
{
	this->gold = gold;
	this->owngold = owngold;
	this->sOnOff = sOnOff;
}

PokemonCenter::~PokemonCenter()
{
}

void PokemonCenter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC2, m_static);
	DDX_Control(pDX, IDC_STATIC6, m_owngold);
	m_static.SetWindowTextW(calcNum(gold));
	m_owngold.SetWindowTextW(calcNum(owngold));
	Sound sound;
	if (sOnOff) {
		sound.PcenterOn();
	}
}


BEGIN_MESSAGE_MAP(PokemonCenter, CDialog)
	ON_BN_CLICKED(IDOK, &PokemonCenter::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &PokemonCenter::OnBnClickedCancel)
END_MESSAGE_MAP()


// PokemonCenter 메시지 처리기

CString PokemonCenter::calcNum(int Num) {
	CString result;
	int dnum = 10000000;
	int temp;
	bool check = false;

	result.Format(_T(""));

	for (int i = 0; i < 8; i++) {
		temp = Num / dnum;
		if (check == true) {
			result.Format(result + convertNum(temp));
		}
		if (check == false && temp != 0) {
			result.Format(result + convertNum(temp));
			check = true;
		}
		Num = Num - (temp * dnum);
		dnum = dnum / 10;
	}
	return result;
}

CString PokemonCenter::convertNum(int Num) {
	CString result;
	switch (Num)
	{
	case 0:
		result.Format(_T("0"));
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
	default:
		result.Format(_T(""));
		break;
	}
	return result;
}

void PokemonCenter::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnOK();
}


void PokemonCenter::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnCancel();
}
