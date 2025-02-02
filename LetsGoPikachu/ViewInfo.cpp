// ViewInfo.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "ViewInfo.h"
#include "afxdialogex.h"


// ViewInfo 대화 상자

IMPLEMENT_DYNAMIC(ViewInfo, CDialog)

ViewInfo::ViewInfo(CWnd* pParent /*=nullptr*/)	//기존 생성자
	: CDialog(IDD_VIEWINFO_DIALOG, pParent)
{

}

ViewInfo::ViewInfo(int exist1, int exist2, int exist3, int exist4, int exist5, int exist6
	, int nhp1, int nhp2, int nhp3, int nhp4, int nhp5, int nhp6
	, int thp1, int thp2, int thp3, int thp4, int thp5, int thp6
	, int nexp1, int nexp2, int nexp3, int nexp4, int nexp5, int nexp6
	, int texp1, int texp2, int texp3, int texp4, int texp5, int texp6
	, int level1, int level2, int level3, int level4, int level5, int level6
	, CString name1, CString name2, CString name3, CString name4, CString name5, CString name6
	, CString path1, CString path2, CString path3, CString path4, CString path5, CString path6
	, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_VIEWINFO_DIALOG, pParent)
{
	exist[0] = exist1;
	exist[1] = exist2;
	exist[2] = exist3;
	exist[3] = exist4;
	exist[4] = exist5;
	exist[5] = exist6;

	nhp[0] = nhp1;
	nhp[1] = nhp2;
	nhp[2] = nhp3;
	nhp[3] = nhp4;
	nhp[4] = nhp5;
	nhp[5] = nhp6;

	thp[0] = thp1;
	thp[1] = thp2;
	thp[2] = thp3;
	thp[3] = thp4;
	thp[4] = thp5;
	thp[5] = thp6;

	nexp[0] = nexp1;
	nexp[1] = nexp2;
	nexp[2] = nexp3;
	nexp[3] = nexp4;
	nexp[4] = nexp5;
	nexp[5] = nexp6;

	texp[0] = texp1;
	texp[1] = texp2;
	texp[2] = texp3;
	texp[3] = texp4;
	texp[4] = texp5;
	texp[5] = texp6;

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

	path[0] = path1;
	path[1] = path2;
	path[2] = path3;
	path[3] = path4;
	path[4] = path5;
	path[5] = path6;

	select = 0;
	trash = false;
	none.Format(_T("-"));
}

ViewInfo::~ViewInfo()
{
}

void ViewInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO, m_combo);
	DDX_Control(pDX, IDC_PROGRESS_EXP, m_expPrograss);
	DDX_Control(pDX, IDC_PROGRESS_HP, m_hpProgress);
	DDX_Control(pDX, IDC_STATIC_LEVEL, m_level);
	DDX_Control(pDX, IDC_STATIC_NAME, m_name);
	DDX_Control(pDX, IDC_STATIC_NEXP, m_nexp);
	DDX_Control(pDX, IDC_STATIC_NHP, m_nhp);
	DDX_Control(pDX, IDC_STATIC_TEXP, m_texp);
	DDX_Control(pDX, IDC_STATIC_THP, m_thp);

	m_hpProgress.SetRange(0,100);
	m_expPrograss.SetRange(0, 100);

	for (int i = 0; i < 6; i++) {	//이름 넣어주기
		if (exist[i] == 1) {
			m_combo.AddString(name[i]);
		}
		else {
			m_combo.AddString(none);
		}
	}

	//설정해주기
	m_combo.SetCurSel(0);
	if (exist[0] == 1){
		m_name.SetWindowTextW(name[0]);	//이름
		temp.Format(_T("%d"), level[0]);	//레벨
		m_level.SetWindowTextW(temp);
		temp.Format(_T("%d"), nhp[0]);	//현재체력
		m_nhp.SetWindowTextW(temp);
		temp.Format(_T("%d"), thp[0]);	//총 체력
		m_thp.SetWindowTextW(temp);
		temp.Format(_T("%d"), nexp[0]);	//현제경험치
		m_nexp.SetWindowTextW(temp);
		temp.Format(_T("%d"), texp[0]);	//총 경험치
		m_texp.SetWindowTextW(temp);
		m_hpProgress.SetPos(calchpProgress());
		m_expPrograss.SetPos(calcexpProgress());
	}
}


BEGIN_MESSAGE_MAP(ViewInfo, CDialog)
	ON_WM_PAINT()
	ON_CBN_SELCHANGE(IDC_COMBO, &ViewInfo::OnSelchangeCombo)
	ON_BN_CLICKED(IDOK, &ViewInfo::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTT_Trash, &ViewInfo::OnBnClickedButtTrash)
	ON_BN_CLICKED(IDCANCEL, &ViewInfo::OnBnClickedCancel)
END_MESSAGE_MAP()


// ViewInfo 메시지 처리기


void ViewInfo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	CBitmap bitmap;
	BITMAP bmpinfo;
	CImage poimg;
	if (exist[select] == 1) {	//존재할때만 출력
		poimg.Load(path[select]);
		bitmap.Attach(poimg.Detach());
		bitmap.GetBitmap(&bmpinfo);
		MemDC.SelectObject(&bitmap);
		dc.TransparentBlt(80, 90, 100, 100, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
	}
	MemDC.DeleteDC();
}

int ViewInfo::calchpProgress() {
	int result = 0;
	result = (int)(nhp[select] * 100 / thp[select]);
	return result;
}

int ViewInfo::calcexpProgress() {
	int result = 0;
	result = (int)(nexp[select] * 100 / texp[select]);
	return result;
}



void ViewInfo::OnSelchangeCombo()	//콤보 클릭 시 동작
{
	select = m_combo.GetCurSel();
	if (exist[select] == 1) {
		m_name.SetWindowTextW(name[select]);	//이름
		temp.Format(_T("%d"), level[select]);	//레벨
		m_level.SetWindowTextW(temp);
		temp.Format(_T("%d"), nhp[select]);	//현재체력
		m_nhp.SetWindowTextW(temp);
		temp.Format(_T("%d"), thp[select]);	//총 체력
		m_thp.SetWindowTextW(temp);
		temp.Format(_T("%d"), nexp[select]);	//현제경험치
		m_nexp.SetWindowTextW(temp);
		temp.Format(_T("%d"), texp[select]);	//총 경험치
		m_texp.SetWindowTextW(temp);
		m_hpProgress.SetPos(calchpProgress());
		m_expPrograss.SetPos(calcexpProgress());
	}
	else {
		m_name.SetWindowTextW(none);
		m_level.SetWindowTextW(none);
		m_nhp.SetWindowTextW(none);
		m_thp.SetWindowTextW(none);
		m_nexp.SetWindowTextW(none);
		m_texp.SetWindowTextW(none);
		m_hpProgress.SetPos(0);
		m_expPrograss.SetPos(0);
	}
	Invalidate(TRUE);
}


void ViewInfo::OnBnClickedOk()	//선택버튼
{
	CString mess;
	if (exist[select] == 1) {
		mess.Format(name[select] + _T(" 선택!"));
		MessageBox(mess);
		OnOK();
	}
	else {
		mess.Format(_T("포켓몬이 존재하지 않습니다."));
		MessageBox(mess);
	}
}


void ViewInfo::OnBnClickedButtTrash()	//풀어주기 버튼
{
	CString mess;
	if (exist[select] == 1) {
		mess.Format(name[select] + _T("를(을) 풀어줍니다!"));
		MessageBox(mess);
		trash = true;
		OnOK();
	}
	else {
		mess.Format(_T("포켓몬이 존재하지 않습니다."));
		MessageBox(mess);
	}
}


void ViewInfo::OnBnClickedCancel()	//나가기 버튼
{
	CDialog::OnCancel();
}
