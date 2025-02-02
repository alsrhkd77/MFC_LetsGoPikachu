// BattleBag.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "BattleBag.h"
#include "afxdialogex.h"


// BattleBag 대화 상자

IMPLEMENT_DYNAMIC(BattleBag, CDialog)

BattleBag::BattleBag(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_BATTLEBAG_DIALOG, pParent)
{
	select = 0;
}

BattleBag::BattleBag(int item1, int item2, int item3, int item4, int item5, int item6, int item7, int item8, int item9
	, CString path1, CString path2, CString path3, CString path4, CString path5, CString path6, CString path7, CString path8, CString path9
	,int mode , CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_BATTLEBAG_DIALOG, pParent)
{
	this->item[0] = item1;
	this->item[1] = item2;
	this->item[2] = item3;
	this->item[3] = item4;
	this->item[4] = item5;
	this->item[5] = item6;
	this->item[6] = item7;
	this->item[7] = item8;
	this->item[8] = item9;
	this->path[0] = path1;
	this->path[1] = path2;
	this->path[2] = path3;
	this->path[3] = path4;
	this->path[4] = path5;
	this->path[5] = path6;
	this->path[6] = path7;
	this->path[7] = path8;
	this->path[8] = path9;
	this->mode = mode;
	select = 0;
}

BattleBag::~BattleBag()
{
}

void BattleBag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_item1);
	DDX_Control(pDX, IDC_STATIC2, m_item2);
	DDX_Control(pDX, IDC_STATIC3, m_item3);
	DDX_Control(pDX, IDC_STATIC4, m_item4);
	DDX_Control(pDX, IDC_STATIC5, m_item5);
	DDX_Control(pDX, IDC_STATIC6, m_item6);
	DDX_Control(pDX, IDC_STATIC7, m_item7);
	DDX_Control(pDX, IDC_STATIC8, m_item8);
	DDX_Control(pDX, IDC_STATIC9, m_item9);
	m_item1.SetWindowTextW(calcNum(item[0]));
	m_item2.SetWindowTextW(calcNum(item[1]));
	m_item3.SetWindowTextW(calcNum(item[2]));
	m_item4.SetWindowTextW(calcNum(item[3]));
	m_item5.SetWindowTextW(calcNum(item[4]));
	m_item6.SetWindowTextW(calcNum(item[5]));
	m_item7.SetWindowTextW(calcNum(item[6]));
	m_item8.SetWindowTextW(calcNum(item[7]));
	m_item9.SetWindowTextW(calcNum(item[8]));

	DDX_Control(pDX, IDC_BUTTON1, m_use1);
	DDX_Control(pDX, IDC_BUTTON2, m_use2);
	DDX_Control(pDX, IDC_BUTTON3, m_use3);
	DDX_Control(pDX, IDC_BUTTON4, m_use4);
	DDX_Control(pDX, IDC_BUTTON5, m_use5);
	DDX_Control(pDX, IDC_BUTTON6, m_use6);
	DDX_Control(pDX, IDC_BUTTON7, m_use7);
	DDX_Control(pDX, IDC_BUTTON8, m_use8);
	DDX_Control(pDX, IDC_BUTTON9, m_use9);
	if (item[0] == 0 || mode == 0) {
		m_use1.EnableWindow(FALSE);
	}
	if (item[1] == 0 || mode == 0) {
		m_use2.EnableWindow(FALSE);
	}
	if (item[2] == 0 || mode == 0) {
		m_use3.EnableWindow(FALSE);
	}
	if (item[3] == 0 || mode == 0) {
		m_use4.EnableWindow(FALSE);
	}
	if (item[4] == 0) {
		m_use5.EnableWindow(FALSE);
	}
	if (item[5] == 0) {
		m_use6.EnableWindow(FALSE);
	}
	if (item[6] == 0) {
		m_use7.EnableWindow(FALSE);
	}
	if (item[7] == 0) {
		m_use8.EnableWindow(FALSE);
	}
	if (item[8] == 0) {
		m_use9.EnableWindow(FALSE);
	}
}


BEGIN_MESSAGE_MAP(BattleBag, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &BattleBag::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &BattleBag::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &BattleBag::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &BattleBag::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &BattleBag::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &BattleBag::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &BattleBag::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &BattleBag::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &BattleBag::OnBnClickedButton9)
END_MESSAGE_MAP()


// BattleBag 메시지 처리기


void BattleBag::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	CBitmap bitmap[9];
	BITMAP bmpinfo;
	CImage itemimg[9];

	for (int i = 0; i < 9; i++) {
		itemimg[i].Load(path[i]);	//파일 경로 형식(상대경로)
		bitmap[i].Attach(itemimg[i].Detach());
		bitmap[i].GetBitmap(&bmpinfo);
		MemDC.SelectObject(&bitmap[i]);
		dc.TransparentBlt(30, 30 + (i * 40), 25, 25, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
	}
	MemDC.DeleteDC();
}

CString BattleBag::calcNum(int Num) {
	CString result;
	int dnum = 10000;
	int temp;
	bool check=false;

	result.Format(_T(""));

	for (int i = 0; i < 5; i++) {
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

CString BattleBag::convertNum(int Num) {
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

void BattleBag::OnBnClickedButton1()
{
	select = 1;
	OnOK();
}


void BattleBag::OnBnClickedButton2()
{
	select = 2;
	OnOK();
}


void BattleBag::OnBnClickedButton3()
{
	select = 3;
	OnOK();
}


void BattleBag::OnBnClickedButton4()
{
	select = 4;
	OnOK();
}


void BattleBag::OnBnClickedButton5()
{
	select = 5;
	OnOK();
}


void BattleBag::OnBnClickedButton6()
{
	select = 6;
	OnOK();
}


void BattleBag::OnBnClickedButton7()
{
	select = 7;
	OnOK();
}


void BattleBag::OnBnClickedButton8()
{
	select = 8;
	OnOK();
}


void BattleBag::OnBnClickedButton9()
{
	select = 9;
	OnOK();
}
