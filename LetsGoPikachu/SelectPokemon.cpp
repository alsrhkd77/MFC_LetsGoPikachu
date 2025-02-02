// SelectPokemon.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "SelectPokemon.h"
#include "afxdialogex.h"


// SelectPokemon 대화 상자

IMPLEMENT_DYNAMIC(SelectPokemon, CDialog)

SelectPokemon::SelectPokemon(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SELECTPOKEMON_DIALOG, pParent)
{
	select = 0;
}

SelectPokemon::SelectPokemon(int exist1, int exist2, int exist3, int exist4, int exist5, int exist6
	, int hp1, int hp2, int hp3, int hp4, int hp5, int hp6
	, CString path1, CString path2, CString path3, CString path4, CString path5, CString path6
	,int mode ,CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SELECTPOKEMON_DIALOG, pParent)
{
	exist[0] = exist1;
	exist[1] = exist2;
	exist[2] = exist3;
	exist[3] = exist4;
	exist[4] = exist5;
	exist[5] = exist6;

	hp[0] = hp1;
	hp[1] = hp2;
	hp[2] = hp3;
	hp[3] = hp4;
	hp[4] = hp5;
	hp[5] = hp6;

	path[0] = path1;
	path[1] = path2;
	path[2] = path3;
	path[3] = path4;
	path[4] = path5;
	path[5] = path6;
	select = 0;
	this->mode = mode;
}

SelectPokemon::~SelectPokemon()
{
}

void SelectPokemon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_STATIC2, m_static2);
	DDX_Control(pDX, IDC_STATIC3, m_static3);
	DDX_Control(pDX, IDC_STATIC4, m_static4);
	DDX_Control(pDX, IDC_STATIC5, m_static5);
	DDX_Control(pDX, IDC_STATIC6, m_static6);
	//스테틱 설정
	if (exist[0] == 0 || mode != 3) {
		m_static1.SetWindowTextW(_T(""));
	}
	else {
		if (hp[0] == 0) {
			m_static1.SetWindowTextW(_T("사용 불가"));
		}
		else {
			m_static1.SetWindowTextW(_T("사용 가능"));
		}
	}
	if (exist[1] == 0 || mode != 3) {
		m_static2.SetWindowTextW(_T(""));
	}
	else {
		if (hp[1] == 0) {
			m_static2.SetWindowTextW(_T("사용 불가"));
		}
		else {
			m_static2.SetWindowTextW(_T("사용 가능"));
		}
	}
	if (exist[2] == 0 || mode != 3) {
		m_static3.SetWindowTextW(_T(""));
	}
	else {
		if (hp[2] == 0) {
			m_static3.SetWindowTextW(_T("사용 불가"));
		}
		else {
			m_static3.SetWindowTextW(_T("사용 가능"));
		}
	}
	if (exist[3] == 0 || mode != 3) {
		m_static4.SetWindowTextW(_T(""));
	}
	else {
		if (hp[3] == 0) {
			m_static4.SetWindowTextW(_T("사용 불가"));
		}
		else {
			m_static4.SetWindowTextW(_T("사용 가능"));
		}
	}
	if (exist[4] == 0 || mode != 3) {
		m_static5.SetWindowTextW(_T(""));
	}
	else {
		if (hp[4] == 0) {
			m_static5.SetWindowTextW(_T("사용 불가"));
		}
		else {
			m_static5.SetWindowTextW(_T("사용 가능"));
		}
	}
	if (exist[5] == 0 || mode != 3) {
		m_static6.SetWindowTextW(_T(""));
	}
	else {
		if (hp[5] == 0) {
			m_static6.SetWindowTextW(_T("사용 불가"));
		}
		else {
			m_static6.SetWindowTextW(_T("사용 가능"));
		}
	}
	//  DDX_Text(pDX, IDC_EDIT1, posX);
	//  DDX_Text(pDX, IDC_EDIT2, posY);
}


BEGIN_MESSAGE_MAP(SelectPokemon, CDialog)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// SelectPokemon 메시지 처리기


void SelectPokemon::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	CBitmap bitmap[6];
	BITMAP bmpinfo;
	CImage poimg[6];

	for (int i = 0; i < 3; i++) {
		if (exist[i] != 0) {
			poimg[i].Load(path[i]);	//파일 경로 형식(상대경로)
			bitmap[i].Attach(poimg[i].Detach());
			bitmap[i].GetBitmap(&bmpinfo);
			MemDC.SelectObject(&bitmap[i]);
			dc.TransparentBlt(45 + (i*105), 50, 50, 50, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
		}
		if (exist[i+3] != 0) {
			poimg[i+3].Load(path[i+3]);	//파일 경로 형식(상대경로)
			bitmap[i+3].Attach(poimg[i+3].Detach());
			bitmap[i+3].GetBitmap(&bmpinfo);
			MemDC.SelectObject(&bitmap[i+3]);
			dc.TransparentBlt(45 + (i * 105), 165, 50, 50, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
		}
	}
	MemDC.DeleteDC();
}


void SelectPokemon::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (point.x > 45 && point.x < 90 && point.y > 50 && point.y < 115) {
		if (exist[0] == 1 && hp[0] != 0) {
			select = 0;
			OnOK();
		}
		if (exist[0] == 1 && hp[0] == 0) {
			MessageBox(_T("선택할 수 없습니다."));
		}
	}
	if (point.x > 150 && point.x < 195 && point.y > 50 && point.y < 115) {
		if (exist[1] == 1 && hp[1] != 0) {
			select = 1;
			OnOK();
		}
		if (exist[1] == 1 && hp[1] == 0) {
			MessageBox(_T("선택할 수 없습니다."));
		}
	}
	if (point.x > 255 && point.x < 300 && point.y > 50 && point.y < 115) {
		if (exist[2] == 1 && hp[2] != 0) {
			select = 2;
			OnOK();
		}
		if (exist[2] == 1 && hp[2] == 0) {
			MessageBox(_T("선택할 수 없습니다."));
		}
	}
	if (point.x > 45 && point.x < 90 && point.y > 165 && point.y < 215) {
		if (exist[3] == 1 && hp[3] != 0) {
			select = 3;
			OnOK();
		}
		if (exist[3] == 1 && hp[3] == 0) {
			MessageBox(_T("선택할 수 없습니다."));
		}
	}
	if (point.x > 150 && point.x < 195 && point.y > 165 && point.y < 215) {
		if (exist[4] == 1 && hp[4] != 0) {
			select = 4;
			OnOK();
		}
		if (exist[4] == 1 && hp[4] == 0) {
			MessageBox(_T("선택할 수 없습니다."));
		}
	}
	if (point.x > 255 && point.x < 300 && point.y > 165 && point.y < 215) {
		if (exist[5] == 1 && hp[5] != 0) {
			select = 5;
			OnOK();
		}
		if (exist[5] == 1 && hp[5] == 0) {
			MessageBox(_T("선택할 수 없습니다."));
		}
	}
	CDialog::OnLButtonUp(nFlags, point);
}


void SelectPokemon::OnMouseMove(UINT nFlags, CPoint point)	//안씀
{
	// TODO: 다이얼로그에 에디터박스 지우기
	/*UpdateData(TRUE);
	posX = point.x;
	posY = point.y;
	UpdateData(FALSE);*/
	CDialog::OnMouseMove(nFlags, point);
}
