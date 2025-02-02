
// LetsGoPikachuDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "LetsGoPikachuDlg.h"
#include "afxdialogex.h"
#include "StartAdventure.h"
#include "SelectAttack.h"
#include <stdlib.h>
#include <time.h>
#include "PoInfo.h"
#include "SignUp.h"
#include "SignIn.h"
#include "SelectPokemon.h"
#include "BattleBag.h"
#include "PokemonCenter.h"
#include "Store.h"
#include "ViewInfo.h"
#include "DataSaveLoad.h"
#include "Setting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLetsGoPikachuDlg 대화 상자



CLetsGoPikachuDlg::CLetsGoPikachuDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LETSGOPIKACHU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLetsGoPikachuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_posxinfo);
	//  DDX_Text(pDX, IDC_EDIT2, m_posinfoy);
}

BEGIN_MESSAGE_MAP(CLetsGoPikachuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_SAVE_EXIT, &CLetsGoPikachuDlg::OnSaveExit)
	ON_COMMAND(ID_SAVE_LOGOUT, &CLetsGoPikachuDlg::OnSaveLogout)
	ON_COMMAND(ID_SAVE_SAVE, &CLetsGoPikachuDlg::OnSaveSave)
	ON_COMMAND(ID_FILE_EXIT, &CLetsGoPikachuDlg::OnFileExit)
	ON_COMMAND(ID_INFO_MAKERS, &CLetsGoPikachuDlg::OnInfoMakers)
	ON_COMMAND(ID_HELP_HELP, &CLetsGoPikachuDlg::OnHelpHelp)
	ON_COMMAND(ID_OPTION_SOUNDOPTION, &CLetsGoPikachuDlg::OnOptionSoundoption)
END_MESSAGE_MAP()


// CLetsGoPikachuDlg 메시지 처리기

BOOL CLetsGoPikachuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	sound.LoginOn();	//사운드
	itemPath[0].Format(_T(".\\item\\ball1.png"));
	itemPath[1].Format(_T(".\\item\\ball2.png"));
	itemPath[2].Format(_T(".\\item\\ball3.png"));
	itemPath[3].Format(_T(".\\item\\ball4.png"));
	itemPath[4].Format(_T(".\\item\\item1.png"));
	itemPath[5].Format(_T(".\\item\\item2.png"));
	itemPath[6].Format(_T(".\\item\\item3.png"));
	itemPath[7].Format(_T(".\\item\\item4.png"));
	itemPath[8].Format(_T(".\\item\\item5.png"));
	skillEffectPath[0].Format(_T(".\\effect\\skilleffect1.png"));
	skillEffectPath[1].Format(_T(".\\effect\\skilleffect2.png"));
	skillEffectPath[2].Format(_T(".\\effect\\skilleffect3.png"));
	skillEffectPath[3].Format(_T(".\\effect\\skilleffect4.png"));
	m_mobHpBar = nullptr;
	m_playerHpBar = nullptr;
	m_mobIncreaseHpBar = nullptr;
	m_playerIncreaseHpBar = nullptr;
	m_mobAttackEffect = nullptr;
	m_playerAttackEffect = nullptr;
	mode = 0;
	stage = 0;
	moveCheck = 0;
	playerSkill = 0;
	mobSkill = 0;
	effectScale = 0;
	turn = true;
	//player.nowPokemon = 1;	//임시
	charDir = 0;
	charFoot = 1;
	charPosX = 105;
	charPosY = 470;
	charPath.Format(_T(".\\character\\character_forward_stop.png"));
	srand((unsigned int)time(NULL));

	//player.setPokemon();	//임시

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CLetsGoPikachuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CLetsGoPikachuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		CClientDC dc(this);
		CDC MemDC;
		MemDC.CreateCompatibleDC(&dc);
		CBitmap bitmap, charbit, pobit1, pobit2, pobit3, pobit4, pobit5, pobit6, pHpbit[8], mHpbit[8], moblevelbit[2], playerlevelbit[2], effectbit;
		BITMAP bmpinfo;
		CBitmap *oldBitmap;
		CImage Player_char, po1, po2, po3, po4, po5, po6, pHp[8], mHp[8], moblevel[2], playerlevel[2], effectimg;
		CPen pEn;

		dc.SetStretchBltMode(COLORONCOLOR);	//색깔 안깨지게하기

		switch (mode)
		{
		case 0:	//시작화면
			bitmap.LoadBitmapW(bg_login);
			bitmap.GetBitmap(&bmpinfo);
			oldBitmap = MemDC.SelectObject(&bitmap);
			dc.StretchBlt(0, 0, 1000, 600, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
			dc.SelectObject(oldBitmap);
			break;
		case 1:	//메인화면
			bitmap.LoadBitmapW(bg_main);
			bitmap.GetBitmap(&bmpinfo);
			oldBitmap = MemDC.SelectObject(&bitmap);
			dc.StretchBlt(0, 0, 1000, 600, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

			//메인화면에 포켓몬 표시하기
			if (player.pPokemon[0].exist == true) {
				po1.Load(player.pPokemon[0].forwardPath);	//파일 경로 형식(상대경로)
				pobit1.Attach(po1.Detach());
				pobit1.GetBitmap(&bmpinfo);
				MemDC.SelectObject(&pobit1);
				dc.TransparentBlt(100, 30, 200, 200, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
			}

			if (player.pPokemon[1].exist == true) {
				po2.Load(player.pPokemon[1].forwardPath);	//파일 경로 형식(상대경로)
				pobit2.Attach(po2.Detach());
				pobit2.GetBitmap(&bmpinfo);
				MemDC.SelectObject(&pobit2);
				dc.TransparentBlt(400, 30, 180, 180, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
			}

			if (player.pPokemon[2].exist == true) {
				po3.Load(player.pPokemon[2].forwardPath);	//파일 경로 형식(상대경로)
				pobit3.Attach(po3.Detach());
				pobit3.GetBitmap(&bmpinfo);
				MemDC.SelectObject(&pobit3);
				dc.TransparentBlt(700, 30, 180, 180, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
			}

			if (player.pPokemon[3].exist == true) {
				po4.Load(player.pPokemon[3].forwardPath);	//파일 경로 형식(상대경로)
				pobit4.Attach(po4.Detach());
				pobit4.GetBitmap(&bmpinfo);
				MemDC.SelectObject(&pobit4);
				dc.TransparentBlt(100, 230, 180, 180, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
			}

			if (player.pPokemon[4].exist == true) {
				po5.Load(player.pPokemon[4].forwardPath);	//파일 경로 형식(상대경로)
				pobit5.Attach(po5.Detach());
				pobit5.GetBitmap(&bmpinfo);
				MemDC.SelectObject(&pobit5);
				dc.TransparentBlt(400, 230, 180, 180, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
			}

			if (player.pPokemon[5].exist == true) {
				po6.Load(player.pPokemon[5].forwardPath);	//파일 경로 형식(상대경로)
				pobit6.Attach(po6.Detach());
				pobit6.GetBitmap(&bmpinfo);
				MemDC.SelectObject(&pobit6);
				dc.TransparentBlt(700, 230, 180, 180, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
			}

			dc.SelectObject(oldBitmap);
			break;
		case 2:	//맵 상태일 때
			//맵 출력하기
			if (stage == 1) {
				bitmap.LoadBitmapW(map1);
				bitmap.GetBitmap(&bmpinfo);
				//oldBitmap = MemDC.SelectObject(&bitmap);
				MemDC.SelectObject(&bitmap);
				dc.StretchBlt(0, 0, 1000, 600, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
				//dc.SelectObject(oldBitmap);
			}
			if (stage == 2) {
				bitmap.LoadBitmapW(map2);
				bitmap.GetBitmap(&bmpinfo);
				//oldBitmap = MemDC.SelectObject(&bitmap);
				MemDC.SelectObject(&bitmap);
				dc.StretchBlt(0, 0, 1000, 600, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
				//dc.SelectObject(oldBitmap);
			}
			if (stage == 3) {
				bitmap.LoadBitmapW(map3);
				bitmap.GetBitmap(&bmpinfo);
				//oldBitmap = MemDC.SelectObject(&bitmap);
				MemDC.SelectObject(&bitmap);
				dc.StretchBlt(0, 0, 1000, 600, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
				//dc.SelectObject(oldBitmap);
			}
			//캐릭터 출력하기
			Player_char.Load(charPath);	//파일 경로 형식(상대경로)
			charbit.Attach(Player_char.Detach());
			charbit.GetBitmap(&bmpinfo);
			oldBitmap = MemDC.SelectObject(&charbit);
			dc.TransparentBlt(charPosX, charPosY, 50, 50, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
			dc.SelectObject(oldBitmap);
			break;
		case 3:	//배틀화면
			bitmap.LoadBitmapW(bg_battle);
			bitmap.GetBitmap(&bmpinfo);
			oldBitmap = MemDC.SelectObject(&bitmap);
			dc.StretchBlt(0, 0, 1000, 600, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

			//플레이어 포켓몬
			po1.Load(player.pPokemon[player.nowPokemon].backPath);	//파일 경로 형식(상대경로)
			pobit1.Attach(po1.Detach());
			pobit1.GetBitmap(&bmpinfo);
			MemDC.SelectObject(&pobit1);
			dc.TransparentBlt(50, 280, 200, 200, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));

			//상대 포켓몬
			po2.Load(mob_pokemon.forwardPath);	//파일 경로 형식(상대경로)
			pobit2.Attach(po2.Detach());
			pobit2.GetBitmap(&bmpinfo);
			MemDC.SelectObject(&pobit2);
			dc.TransparentBlt(770, 0, 200, 200, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));

			if (turn) {
				effectimg.Load(skillEffectPath[playerSkill]);
			}
			else {
				effectimg.Load(skillEffectPath[mobSkill]);
			}
			effectbit.Attach(effectimg.Detach());
			effectbit.GetBitmap(&bmpinfo);
			MemDC.SelectObject(&effectbit);
			if (turn) {	//플레이어 공격일때
				dc.TransparentBlt(870 - (effectScale / 2), 100 - (effectScale / 2), effectScale, effectScale, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
			}
			else {	//상대 공격일때
				dc.TransparentBlt(125 - (effectScale / 2), 380 - (effectScale / 2), effectScale, effectScale, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
			}

			for (int i = 0; i < 4; i++) {
				pHp[i].Load(playerHpNum[i]);	//파일 경로 형식(상대경로)
				pHpbit[i].Attach(pHp[i].Detach());
				pHpbit[i].GetBitmap(&bmpinfo);
				MemDC.SelectObject(&pHpbit[i]);
				dc.TransparentBlt(890+(i*12), 413, 35, 35, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));

				pHp[i+4].Load(playerHpNum[i+4]);	//파일 경로 형식(상대경로)
				pHpbit[i+4].Attach(pHp[i+4].Detach());
				pHpbit[i+4].GetBitmap(&bmpinfo);
				MemDC.SelectObject(&pHpbit[i+4]);
				dc.TransparentBlt(815 + (i * 12), 413, 35, 35, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));

				mHp[i].Load(mobHpNum[i+4]);	//파일 경로 형식(상대경로)
				mHpbit[i].Attach(mHp[i].Detach());
				mHpbit[i].GetBitmap(&bmpinfo);
				MemDC.SelectObject(&mHpbit[i]);
				dc.TransparentBlt(202 + (i * 12), 112, 35, 35, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));

				mHp[i + 4].Load(mobHpNum[i]);	//파일 경로 형식(상대경로)
				mHpbit[i + 4].Attach(mHp[i + 4].Detach());
				mHpbit[i + 4].GetBitmap(&bmpinfo);
				MemDC.SelectObject(&mHpbit[i + 4]);
				dc.TransparentBlt(277 + (i * 12), 112, 35, 35, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
			}

			//레벨 표시
			moblevel[0].Load(mobLevelNum[0]);	//파일 경로 형식(상대경로)
			moblevelbit[0].Attach(moblevel[0].Detach());
			moblevelbit[0].GetBitmap(&bmpinfo);
			MemDC.SelectObject(&moblevelbit[0]);
			dc.TransparentBlt(270, 37, 40, 40, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));

			moblevel[1].Load(mobLevelNum[1]);	//파일 경로 형식(상대경로)
			moblevelbit[1].Attach(moblevel[1].Detach());
			moblevelbit[1].GetBitmap(&bmpinfo);
			MemDC.SelectObject(&moblevelbit[1]);
			dc.TransparentBlt(290, 37, 40, 40, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));

			playerlevel[0].Load(playerLevelNum[0]);	//파일 경로 형식(상대경로)
			playerlevelbit[0].Attach(playerlevel[0].Detach());
			playerlevelbit[0].GetBitmap(&bmpinfo);
			MemDC.SelectObject(&playerlevelbit[0]);
			dc.TransparentBlt(880, 337, 40, 40, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));

			playerlevel[1].Load(playerLevelNum[1]);	//파일 경로 형식(상대경로)
			playerlevelbit[1].Attach(playerlevel[1].Detach());
			playerlevelbit[1].GetBitmap(&bmpinfo);
			MemDC.SelectObject(&playerlevelbit[1]);
			dc.TransparentBlt(900, 337, 40, 40, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));

			//상대포켓몬 체력바
			if ((mob_pokemon.nowHP * 100 / mob_pokemon.hPoint) > 50) {	//체력바 색깔 설정
				pEn.CreatePen(PS_SOLID, 10, RGB(85, 241, 86));
			}
			else if ((mob_pokemon.nowHP * 100 / mob_pokemon.hPoint) > 10) {
				pEn.CreatePen(PS_SOLID, 10, RGB(243, 209, 19));
			}
			else {
				pEn.CreatePen(PS_SOLID, 10, RGB(163, 32, 39));
			}
			dc.SelectObject(&pEn);
			dc.MoveTo(98, 96);
			dc.LineTo(98 + (int)(mobBarPoint * 2.4), 96);
			pEn.DeleteObject();

			//플레이어포켓몬 체력바
			if ((player.pPokemon[player.nowPokemon].nowHP * 100 / player.pPokemon[player.nowPokemon].hPoint) > 50) {	//체력바 색깔 설정
				pEn.CreatePen(PS_SOLID, 10, RGB(85, 241, 86));
			}
			else if ((player.pPokemon[player.nowPokemon].nowHP * 100 / player.pPokemon[player.nowPokemon].hPoint) > 10) {
				pEn.CreatePen(PS_SOLID, 10, RGB(243, 209, 19));
			}
			else {
				pEn.CreatePen(PS_SOLID, 10, RGB(163, 32, 39));
			}
			dc.SelectObject(&pEn);
			dc.MoveTo(713, 396);
			dc.LineTo(713 + (int)(playerBarPoint * 2.4), 396);
			pEn.DeleteObject();

			dc.SelectObject(oldBitmap);
			break;
		default:
			break;
		}

		MemDC.DeleteDC();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CLetsGoPikachuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLetsGoPikachuDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDialogEx::OnMouseMove(nFlags, point);
}


void CLetsGoPikachuDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	/*CClientDC dc(this);
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	CBitmap bitmap;
	BITMAP bmpinfo;
	CImage Player_char;
	Player_char.Load(_T(".\\res\\temp.png"));	//파일 경로 형식(상대경로)
	bitmap.Attach(Player_char.Detach());
	bitmap.GetBitmap(&bmpinfo);
	CBitmap *oldBitmap = MemDC.SelectObject(&bitmap);
	dc.TransparentBlt(point.x, point.y, 22, 22, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
	dc.SelectObject(oldBitmap);
	MemDC.DeleteDC();*/

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CLetsGoPikachuDlg::OnLButtonUp(UINT nFlags, CPoint point)	//마우스 이벤트
{
	if (mode == 0 && point.x > 365 && point.x < 633) {	//로그인 창일때
		if (point.y > 344 && point.y < 404) {	//게임시작
			int idcheck = 0, pwcheck = 0, mas;
			char id[20];
			char pw[20];
			FILE *IDPW;
			CString rString;
			SignIn in;

			if (in.DoModal() == IDOK) {
				fopen_s(&IDPW, "IDPW.txt", "r");  // 마스터 파일 Open 
				while (1) {
					mas = fscanf_s(IDPW, "%s %s", id, sizeof(id), pw, sizeof(pw));
					if (in.m_input_id == id)
						idcheck = 1;
					if (in.m_input_pw == pw)
						pwcheck = 1;
					if (mas == EOF)
						break;
				}

				fclose(IDPW);

				if (idcheck == 1 && pwcheck == 1) {
					player.playerID = in.m_input_id;
					DataLoad();
					rString.Format(_T("로그인이 되었습니다."));
					AfxMessageBox(rString);
					mode = 1;
					sound.MainOn();	//사운드
					Invalidate(TRUE);
				}
				else {
					rString.Format(_T("아이디 또는 비밀번호가 잘못 되었습니다."));
					AfxMessageBox(rString);
				}
				UpdateData(FALSE);
			}
		}
		if (point.y > 430 && point.y < 490) {	//설정
			Setting setting((int)sound.backGround, (int)sound.effect);
			if (setting.DoModal() == IDOK) {
				if (setting.back_select == 1) {
					sound.Off();
					sound.backGround = true;
					sound.LoginOn();
				}
				else {
					sound.backGround = false;
					sound.Off();
				}
				if (setting.effect_select == 1) {
					sound.effect = true;
				}
				else {
					sound.effect = false;
				}
				UpdateData(FALSE);
			}
		}
		if (point.y > 517 && point.y < 577) {	//게임종료
			MessageBox(_T("게임을 종료합니다."));
			OnOK();
		}
	}
	if (mode == 1) {	//메인 창일때
		if (point.x > 35 && point.x < 160 && point.y > 455 && point.y < 575) {	//포켓몬 정보
			ViewInfo viewinfo((int)player.pPokemon[0].exist, (int)player.pPokemon[1].exist, (int)player.pPokemon[2].exist, (int)player.pPokemon[3].exist, (int)player.pPokemon[4].exist, (int)player.pPokemon[5].exist
				, player.pPokemon[0].nowHP, player.pPokemon[1].nowHP, player.pPokemon[2].nowHP, player.pPokemon[3].nowHP, player.pPokemon[4].nowHP, player.pPokemon[5].nowHP
				, player.pPokemon[0].hPoint, player.pPokemon[1].hPoint, player.pPokemon[2].hPoint, player.pPokemon[3].hPoint, player.pPokemon[4].hPoint, player.pPokemon[5].hPoint
				, player.pPokemon[0].nowExp, player.pPokemon[1].nowExp, player.pPokemon[2].nowExp, player.pPokemon[3].nowExp, player.pPokemon[4].nowExp, player.pPokemon[5].nowExp
				, player.pPokemon[0].exp, player.pPokemon[1].exp, player.pPokemon[2].exp, player.pPokemon[3].exp, player.pPokemon[4].exp, player.pPokemon[5].exp
				, player.pPokemon[0].level, player.pPokemon[1].level, player.pPokemon[2].level, player.pPokemon[3].level, player.pPokemon[4].level, player.pPokemon[5].level
				, player.pPokemon[0].koName, player.pPokemon[1].koName, player.pPokemon[2].koName, player.pPokemon[3].koName, player.pPokemon[4].koName, player.pPokemon[5].koName
				, player.pPokemon[0].forwardPath, player.pPokemon[1].forwardPath, player.pPokemon[2].forwardPath, player.pPokemon[3].forwardPath, player.pPokemon[4].forwardPath, player.pPokemon[5].forwardPath);
			if (viewinfo.DoModal() == IDOK) {
				if (viewinfo.trash == true) {
					if (player.ownPoNum == 1) {
						MessageBox(_T("실패"));
						MessageBox(_T("포켓몬을 1마리 이상 보유 해야합니다."));
					}
					else {
						player.pPokemon[viewinfo.select].setZero();
						player.ownPoNum--;
						if (viewinfo.select == player.nowPokemon) {
							for (int i = 0; i < 6; i++) {
								if (player.pPokemon[i].exist == true) {
									player.nowPokemon = i;
								}
							}
						}
						Invalidate(TRUE);
					}
					
				}
				else {
					player.nowPokemon = viewinfo.select;
				}
				UpdateData(FALSE);
			}
		}
		if (point.x > 185 && point.x < 315 && point.y > 435 && point.y < 575) {	//도구
			BattleBag battleBag(player.ownBall[0], player.ownBall[1], player.ownBall[2], player.ownBall[3]
				, player.ownItem[0], player.ownItem[1], player.ownItem[2], player.ownItem[3], player.ownItem[4]
				, itemPath[0], itemPath[1], itemPath[2], itemPath[3], itemPath[4], itemPath[5], itemPath[6], itemPath[7], itemPath[8], 0);
			if (battleBag.DoModal() == IDOK) {
				switch (battleBag.select)
				{
				case 0:
					//선택안했음
					break;
				case 5:
					if (healPlayer(1100)) {
						player.ownItem[0]--;
						MessageBox(_T("상처약을 사용했다."));
					}
					break;
				case 6:
					if (healPlayer(2700)) {
						player.ownItem[1]--;
						MessageBox(_T("좋은 상처약을 사용했다."));
					}
					break;
				case 7:
					if (healPlayer(4600)) {
						player.ownItem[2]--;
						MessageBox(_T("기력의 조각을 사용했다."));
					}
					break;
				case 8:
					if (healPlayer(6300)) {
						player.ownItem[3]--;
						MessageBox(_T("기력의 덩어리를 사용했다."));
					}
					break;
				case 9:
					if (healPlayer(9000)) {
						player.ownItem[4]--;
						MessageBox(_T("숲의 양갱을 사용했다."));
					}
					break;
				default:
					break;
				}
				UpdateData(FALSE);
			}
		}
		if (point.x > 355 && point.x < 500 && point.y > 455 && point.y < 575) {	//상점
			Store store(itemPath[0], itemPath[1], itemPath[2], itemPath[3], itemPath[4], itemPath[5], itemPath[6], itemPath[7], itemPath[8]);
			if (store.DoModal() == IDOK) {
				if (store.m_total <= player.gold) {
					player.gold = player.gold - store.m_total;
					player.ownBall[0] = player.ownBall[0] + store.m_countitem1;
					player.ownBall[1] = player.ownBall[1] + store.m_countitem2;
					player.ownBall[2] = player.ownBall[2] + store.m_countitem3;
					player.ownBall[3] = player.ownBall[3] + store.m_countitem4;
					player.ownItem[0] = player.ownItem[0] + store.m_countitem5;
					player.ownItem[1] = player.ownItem[1] + store.m_countitem6;
					player.ownItem[2] = player.ownItem[2] + store.m_countitem7;
					player.ownItem[3] = player.ownItem[3] + store.m_countitem8;
					player.ownItem[4] = player.ownItem[4] + store.m_countitem9;
					MessageBox(_T("구매가 완료되었습니다."));
				}
				else {
					MessageBox(_T("보유 골드가 모자랍니다."));
				}
			}
			UpdateData(FALSE);
		}
		if (point.x > 520 && point.x < 655 && point.y > 450 && point.y < 570) {	//포켓몬 센터
			sound.PcenterOn();	//사운드
			player.setAvePoLevel();
			PokemonCenter center(player.gold, (int) (player.avePoLevel * player.ownPoNum * 400), (int)sound.backGround);
			if (center.DoModal() == IDOK) {
				if (player.gold < player.avePoLevel * player.ownPoNum * 400) {
					MessageBox(_T("보유 골드가 모자랍니다."));
				}
				else {
					sound.HealOn();	//사운드
					player.gold = player.gold - player.avePoLevel * player.ownPoNum * 400;
					usePoCenter();
					MessageBox(_T("회복이 완료되었습니다."));
					sound.MainOn();
				}
			}
			UpdateData(FALSE);
			sound.MainOn();	//사운드
		}
		if (point.x > 695 && point.x < 960 && point.y > 400 && point.y < 565) {	//모험 시작
			StartAdventure adventure(player.pPokemon[0].listNo, player.pPokemon[1].listNo, player.pPokemon[2].listNo, player.pPokemon[3].listNo, player.pPokemon[4].listNo, player.pPokemon[5].listNo
				, player.pPokemon[0].level, player.pPokemon[1].level, player.pPokemon[2].level, player.pPokemon[3].level, player.pPokemon[4].level, player.pPokemon[5].level
				, player.pPokemon[0].koName, player.pPokemon[1].koName, player.pPokemon[2].koName, player.pPokemon[3].koName, player.pPokemon[4].koName, player.pPokemon[5].koName);
			if (adventure.DoModal() == IDOK) {
				if (adventure.select == 4) {
					mode = mode;
					replacePo(adventure.changePo, adventure.getListNo, adventure.getLevel);
					//TODO: 모드 대전으로 변경하기
				}
				else {
					stage = adventure.select;
					if (stage != 0) {
						mode = 2;
						sound.MapOn();	//사운드
					}
				}
				Invalidate(TRUE);
				UpdateData(FALSE);
			}
		}
	}
	if (mode == 2) {	//맵 상태일때
		if (point.x > 880 && point.x < 975 && point.y > 550 && point.y < 600) {
			mode = 1;
			stage = 0;
			sound.MainOn();	//사운드
			Invalidate(TRUE);
		}
	}
	if (mode == 3) {	//배틀상태
		if (point.y > 510 && point.y < 575 && point.x > 65 && point.x < 230) {	//싸운다

			SelectAttack selectAttack(player.pPokemon[player.nowPokemon].skillName[0],
				player.pPokemon[player.nowPokemon].skillName[1],
				player.pPokemon[player.nowPokemon].skillName[2],
				player.pPokemon[player.nowPokemon].skillName[3],
				player.pPokemon[player.nowPokemon].skillpoint[0],
				player.pPokemon[player.nowPokemon].skillpoint[1],
				player.pPokemon[player.nowPokemon].skillpoint[2],
				player.pPokemon[player.nowPokemon].skillpoint[3]);

			if (selectAttack.DoModal() == IDOK) {	//공격버튼 클릭
				if (selectAttack.select == 1) {
					player.pPokemon[player.nowPokemon].skillpoint[0]--;
					playerSkill = 0;
					playerAttack(0);
				}
				if (selectAttack.select == 2) {
					player.pPokemon[player.nowPokemon].skillpoint[1]--;
					playerSkill = 1;
					playerAttack(1);
				}
				if (selectAttack.select == 3) {
					player.pPokemon[player.nowPokemon].skillpoint[2]--;
					playerSkill = 2;
					playerAttack(2);
				}
				if (selectAttack.select == 4) {
					player.pPokemon[player.nowPokemon].skillpoint[3]--;
					playerSkill = 3;
					playerAttack(3);
				}
				UpdateData(FALSE);
			}
		}
		if (point.y > 510 && point.y < 575 && point.x > 300 && point.x < 465) {	//가방
			BattleBag battleBag(player.ownBall[0], player.ownBall[1], player.ownBall[2], player.ownBall[3]
				,player.ownItem[0], player.ownItem[1], player.ownItem[2], player.ownItem[3], player.ownItem[4]
				, itemPath[0], itemPath[1], itemPath[2], itemPath[3], itemPath[4], itemPath[5], itemPath[6], itemPath[7], itemPath[8], 1);
			if (battleBag.DoModal() == IDOK) {
				switch (battleBag.select)
				{
				case 0:
					//선택안했음
					break;
				case 1:	//몬스터볼
					if (player.ownPoNum != 6) {
						player.ownBall[0]--;
						if (useBall(10)) {	//잡기 성공했을 시
							//TODO: 전투 종료시키기
							MessageBox(_T("잡았다"));
							mob_pokemon.exist = false;
							mob_pokemon.setZero();
							mode = 2;
							sound.MapOn();	//사운드
							Invalidate(TRUE);
						}
						else {
							MessageBox(_T("볼에서 튀어나와버렸다."));
							if (mobAttack()) {
								mob_pokemon.exist = false;
								mob_pokemon.setZero();
								//TODO: 다죽었으니 전투 종료
								//TODO: 전투 종료시키고, 메인창 보내고, 몹 초기화 시키고, 돈 털고, 치료시켜주고
								player.gold = player.gold - player.avePoLevel * player.ownPoNum * 400;
								usePoCenter();
								if (player.gold < 0) {
									player.gold = 0;
								}

								mode = 1;
								sound.MainOn();	//사운드
								Invalidate(TRUE);
							}
						}
					}
					else {
						MessageBox(_T("보유한 포켓몬이 너무 많다."));
					}
					break;
				case 2:	//수퍼볼
					if (player.ownPoNum != 6) {
						player.ownBall[1]--;
						if (useBall(30)) {	//잡기 성공했을 시
							//TODO: 전투 종료시키기
							MessageBox(_T("잡았다"));
							mob_pokemon.exist = false;
							mob_pokemon.setZero();
							mode = 2;
							sound.MapOn();	//사운드
							Invalidate(TRUE);
						}
						else {
							MessageBox(_T("볼에서 튀어나와버렸다."));
							if (mobAttack()) {
								mob_pokemon.exist = false;
								mob_pokemon.setZero();
								//TODO: 다죽었으니 전투 종료
								//TODO: 전투 종료시키고, 메인창 보내고, 몹 초기화 시키고, 돈 털고, 치료시켜주고
								player.gold = player.gold - player.avePoLevel * player.ownPoNum * 400;
								usePoCenter();
								if (player.gold < 0) {
									player.gold = 0;
								}

								mode = 1;
								sound.MainOn();	//사운드
								Invalidate(TRUE);
							}
						}
					}
					else {
						MessageBox(_T("보유한 포켓몬이 너무 많다."));
					}
					break;
				case 3:	//하이퍼볼
					if (player.ownPoNum != 6) {
						player.ownBall[2]--;
						if (useBall(50)) {	//잡기 성공했을 시
							//TODO: 전투 종료시키기
							MessageBox(_T("잡았다"));
							mob_pokemon.exist = false;
							mob_pokemon.setZero();
							mode = 2;
							sound.MapOn();	//사운드
							Invalidate(TRUE);
						}
						else {
							MessageBox(_T("볼에서 튀어나와버렸다."));
							if (mobAttack()) {
								mob_pokemon.exist = false;
								mob_pokemon.setZero();
								//TODO: 다죽었으니 전투 종료
								//TODO: 전투 종료시키고, 메인창 보내고, 몹 초기화 시키고, 돈 털고, 치료시켜주고
								player.gold = player.gold - player.avePoLevel * player.ownPoNum * 400;
								usePoCenter();
								if (player.gold < 0) {
									player.gold = 0;
								}

								mode = 1;
								sound.MainOn();	//사운드
								Invalidate(TRUE);
							}
						}
					}
					else {
						MessageBox(_T("보유한 포켓몬이 너무 많다."));
					}
					break;
				case 4:	//마스터볼
					if (player.ownPoNum != 6) {
						MessageBox(_T("잡았다"));
						player.ownBall[3]--;
						useBall(100);	//무조건 잡으니 쳐맞을 필요 없음
						mob_pokemon.exist = false;
						mob_pokemon.setZero();
						mode = 2;
						sound.MapOn();	//사운드
						Invalidate(TRUE);
					}
					else {
						MessageBox(_T("보유한 포켓몬이 너무 많다."));
					}
					break;
				case 5:
					player.ownItem[0]--;
					healPlayer(200);
					MessageBox(_T("상처약을 사용했다."));
					if (mobAttack()) {
						mob_pokemon.exist = false;
						mob_pokemon.setZero();
						//TODO: 다죽었으니 전투 종료
						//TODO: 전투 종료시키고, 메인창 보내고, 몹 초기화 시키고, 돈 털고, 치료시켜주고
						player.gold = player.gold - player.avePoLevel * player.ownPoNum * 400;
						usePoCenter();
						if (player.gold < 0) {
							player.gold = 0;
						}

						mode = 1;
						sound.MainOn();	//사운드
						Invalidate(TRUE);
					}
					break;
				case 6:
					player.ownItem[1]--;
					healPlayer(500);
					MessageBox(_T("좋은 상처약을 사용했다."));
					if (mobAttack()) {
						mob_pokemon.exist = false;
						mob_pokemon.setZero();
						//TODO: 다죽었으니 전투 종료
						//TODO: 전투 종료시키고, 메인창 보내고, 몹 초기화 시키고, 돈 털고, 치료시켜주고
						player.gold = player.gold - player.avePoLevel * player.ownPoNum * 400;
						usePoCenter();
						if (player.gold < 0) {
							player.gold = 0;
						}

						mode = 1;
						sound.MainOn();	//사운드
						Invalidate(TRUE);
					}
					break;
				case 7:
					player.ownItem[2]--;
					healPlayer(800);
					MessageBox(_T("기력의 조각을 사용했다."));
					if (mobAttack()) {
						mob_pokemon.exist = false;
						mob_pokemon.setZero();
						//TODO: 다죽었으니 전투 종료
						//TODO: 전투 종료시키고, 메인창 보내고, 몹 초기화 시키고, 돈 털고, 치료시켜주고
						player.gold = player.gold - player.avePoLevel * player.ownPoNum * 400;
						usePoCenter();
						if (player.gold < 0) {
							player.gold = 0;
						}

						mode = 1;
						sound.MainOn();	//사운드
						Invalidate(TRUE);
					}
					break;
				case 8:
					player.ownItem[3]--;
					healPlayer(1000);
					MessageBox(_T("기력의 덩어리를 사용했다."));
					if (mobAttack()) {
						mob_pokemon.exist = false;
						mob_pokemon.setZero();
						//TODO: 다죽었으니 전투 종료
						//TODO: 전투 종료시키고, 메인창 보내고, 몹 초기화 시키고, 돈 털고, 치료시켜주고
						player.gold = player.gold - player.avePoLevel * player.ownPoNum * 400;
						usePoCenter();
						if (player.gold < 0) {
							player.gold = 0;
						}

						mode = 1;
						sound.MainOn();	//사운드
						Invalidate(TRUE);
					}
					break;
				case 9:
					player.ownItem[4]--;
					healPlayer(1300);
					MessageBox(_T("숲의 양갱을 사용했다."));
					if (mobAttack()) {
						mob_pokemon.exist = false;
						mob_pokemon.setZero();
						//TODO: 다죽었으니 전투 종료
						//TODO: 전투 종료시키고, 메인창 보내고, 몹 초기화 시키고, 돈 털고, 치료시켜주고
						player.gold = player.gold - player.avePoLevel * player.ownPoNum * 400;
						usePoCenter();
						if (player.gold < 0) {
							player.gold = 0;
						}

						mode = 1;
						sound.MainOn();	//사운드
						Invalidate(TRUE);
					}
					break;
				default:
					break;
				}
				UpdateData(FALSE);
			}
		}
		if (point.y > 510 && point.y < 575 && point.x > 530 && point.x < 700) {	//교체
			if (changePokemon()) {
				if (mobAttack()) {
					mob_pokemon.exist = false;
					mob_pokemon.setZero();
					//TODO: 다죽었으니 전투 종료
					//TODO: 전투 종료시키고, 메인창 보내고, 몹 초기화 시키고, 돈 털고, 치료시켜주고
					player.gold = player.gold - player.avePoLevel * player.ownPoNum * 400;
					usePoCenter();
					if (player.gold < 0) {
						player.gold = 0;
					}

					mode = 1;
					sound.MainOn();	//사운드
					Invalidate(TRUE);
				}
			}
		}
		if (point.y > 510 && point.y < 575 && point.x > 765 && point.x < 930) {	//도망
			MessageBox(_T("무사히 도망쳤다."));
			//TODO: 적 상태 초기화 시키기
			mob_pokemon.exist = false;
			mob_pokemon.setZero();
			mode = 2;
			sound.MapOn();	//사운드
			Invalidate(TRUE);
		}
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CLetsGoPikachuDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)	//안쓰는거
{
	//안씀
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CLetsGoPikachuDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1) {	//캐릭터 이동 타이머
		switch (charDir)
		{
		case 0:
			charPath.Format(_T(".\\character\\character_back_"));
			break;
		case 1:
			charPath.Format(_T(".\\character\\character_forward_"));
			break;
		case 2:
			charPath.Format(_T(".\\character\\character_left_"));
			break;
		case 3:
			charPath.Format(_T(".\\character\\character_right_"));
			break;
		default:
			break;
		}
		if (moveCheck == 1) {
			if (charFoot == 1) {
				charPath.Format(charPath + _T("left.png"));
			}
			else {
				charPath.Format(charPath + _T("right.png"));
			}
			charFoot = -charFoot;
			moveCheck++;
			Invalidate(FALSE);
		}
		else if (moveCheck == 2) {
			charPath.Format(charPath + _T("stop.png"));
			moveCheck = 0;
			KillTimer(1);
			Invalidate(FALSE);
			srand((unsigned int)time(NULL));
			if ((rand() % 7) == 0) {			//몬스터 출현(확률 설정하기)
				//TODO: 배틀 시작
				sound.StartBattleOn();	//사운드
				MessageBox(_T("야생의 포켓몬이 출현했다!"));
				sound.BattleOn();	//사운드
				mode = 3;
				setWildPokemon();
				mob_pokemon.setbattle();
				mobBarPoint = 100;
				try{
					if (player.pPokemon[player.nowPokemon].hPoint == 0) {
						throw player.pPokemon[player.nowPokemon].hPoint;
					}
					playerBarPoint = player.pPokemon[player.nowPokemon].nowHP * 100 / player.pPokemon[player.nowPokemon].hPoint;
				}
				catch(int a){	// The "outer" catch block
										// Pointer e is invalid because
										// it was deleted in the inner catch block.
					MessageBox(_T("심각한 오류!!"));
					MessageBox(_T("플레이어 hp 설정이 잘못됨!"));
				}
				
				calcHpNum();
				Invalidate(TRUE);
			}
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}


BOOL CLetsGoPikachuDlg::PreTranslateMessage(MSG* pMsg)	//방향키 입력
{
	if (moveCheck == 0 && mode == 2) {
		switch (pMsg->wParam)
		{
		case VK_UP:
			charDir = 0;
			moveCheck = 1;
			SetTimer(1, 50, NULL);
			if (charPosY == 425 && charPosX >= 660 && charPosX <= 675) {	//튀어나가는거 막기
				charPosY = charPosY - 15;
			}
			if (charPosY != 425 && charPosY != 35) {
				charPosY = charPosY - 15;
			}
			break;
		case VK_DOWN:
			charDir = 1;
			moveCheck = 1;
			SetTimer(1, 50, NULL);
			if (charPosY == 335 && charPosX >= 660 && charPosX <= 675) {	//튀어나가는거 막기
				charPosY = charPosY + 15;
			}
			if (charPosY != 335 && charPosY != 500) {
				charPosY = charPosY + 15;
			}
			break;
		case VK_LEFT:
			charDir = 2;
			moveCheck = 1;
			SetTimer(1, 50, NULL);
			if (charPosY > 335 && charPosY < 425 && charPosX>660) {	//튀어나가는거 막기
				charPosX = charPosX - 15;
			}
			if (charPosY <= 335 && charPosX > 60) {
				charPosX = charPosX - 15;
			}
			if (charPosY >= 425 && charPosX > 60) {
				charPosX = charPosX - 15;
			}
			break;
		case VK_RIGHT:
			charDir = 3;
			moveCheck = 1;
			SetTimer(1, 50, NULL);
			if (charPosY > 335 && charPosY < 425 && charPosX<675) {	//튀어나가는거 막기
				charPosX = charPosX + 15;
			}
			if (charPosY <= 335 && charPosX < 885) {
				charPosX = charPosX + 15;
			}
			if (charPosY >= 425 && charPosX < 885) {
				charPosX = charPosX + 15;
			}
			break;
		default:
			break;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CLetsGoPikachuDlg::setWildPokemon() {	//출현 할 야생포켓몬 설정
	srand((unsigned int)time(NULL));

	int regend = rand() % 100;	//전포 출현확률
	int regendNo = rand() % 3;
	int level = rand() % 10;	//출현 몹 레벨

	if (stage == 1) {
		if (regend == 0) {	//전포출현
			switch (regendNo)
			{
			case 0:
				mob_pokemon.listNo = 36;
				break;
			case 1:
				mob_pokemon.listNo = 37;
				break;
			case 2:
				mob_pokemon.listNo = 38;
				break;
			default:
				break;
			}
		}
		else {
			int randNo = rand() % 11 + 1;
			mob_pokemon.listNo = randNo;
		}
	}
	if (stage == 2) {
		if (regend == 0) {	//전포출현
			switch (regendNo)
			{
			case 0:
				mob_pokemon.listNo = 39;
				break;
			case 1:
				mob_pokemon.listNo = 42;
				break;
			case 2:
				mob_pokemon.listNo = 44;
				break;
			default:
				break;
			}
		}
		else {
			int randNo = rand() % 12 + 12;
			mob_pokemon.listNo = randNo;
		}
	}
	if (stage == 3) {
		if (regend == 0) {	//전포출현
			switch (regendNo)
			{
			case 0:
				mob_pokemon.listNo = 40;
				break;
			case 1:
				mob_pokemon.listNo = 41;
				break;
			case 2:
				mob_pokemon.listNo = 43;
				break;
			default:
				break;
			}
		}
		else {
			int randNo = rand() % 12 + 24;
			mob_pokemon.listNo = randNo;
		}
	}
	player.setAvePoLevel();
	mob_pokemon.level = player.avePoLevel - 5 + level;
	if (mob_pokemon.level > 99) {
		mob_pokemon.level = 99;
	}
}

UINT CLetsGoPikachuDlg::mobHpBarThread(LPVOID pParam) {	//상대 체력바 감소 쓰레드
	CLetsGoPikachuDlg *pWnd = (CLetsGoPikachuDlg*)pParam;

	while (pWnd->mobBarPoint >= (pWnd->mob_pokemon.nowHP * 100 / pWnd->mob_pokemon.hPoint))
	{
		pWnd->mobBarPoint = pWnd->mobBarPoint - 5;
		if (pWnd->mobBarPoint < (pWnd->mob_pokemon.nowHP * 100 / pWnd->mob_pokemon.hPoint)) {
			pWnd->mobBarPoint = (pWnd->mob_pokemon.nowHP * 100 / pWnd->mob_pokemon.hPoint) - 1;
		}
		pWnd->calcHpNum();
		pWnd->Invalidate(FALSE);
		Sleep(50);
	}

	pWnd->m_mobHpBar->SuspendThread();

	return 0;
}

UINT CLetsGoPikachuDlg::playerHpBarThread(LPVOID pParam) {	//플레이어 체력바 감소 쓰레드
	CLetsGoPikachuDlg *pWnd = (CLetsGoPikachuDlg*)pParam;

	while (pWnd->playerBarPoint >= (pWnd->player.pPokemon[pWnd->player.nowPokemon].nowHP * 100 / pWnd->player.pPokemon[pWnd->player.nowPokemon].hPoint))
	{
		pWnd->playerBarPoint = pWnd->playerBarPoint - 5;
		if (pWnd->playerBarPoint < (pWnd->player.pPokemon[pWnd->player.nowPokemon].nowHP * 100 / pWnd->player.pPokemon[pWnd->player.nowPokemon].hPoint)) {
			pWnd->playerBarPoint = (pWnd->player.pPokemon[pWnd->player.nowPokemon].nowHP * 100 / pWnd->player.pPokemon[pWnd->player.nowPokemon].hPoint) - 1;
		}
		pWnd->Invalidate(FALSE);
		Sleep(50);
	}

	pWnd->m_playerHpBar->SuspendThread();

	return 0;
}

void CLetsGoPikachuDlg::playerAttack(int skillNum)
{
	//CString temp;
	MessageBox(player.pPokemon[player.nowPokemon].koName + _T("는(은) ") + player.pPokemon[player.nowPokemon].skillName[skillNum] + _T("를(을) 사용했다!"));
	//mob_pokemon.nowHP = mob_pokemon.nowHP - ((player.pPokemon[player.nowPokemon].att * player.pPokemon[player.nowPokemon].skill[skillNum] / 100) - mob_pokemon.def);	
	mob_pokemon.nowHP = mob_pokemon.nowHP - ((player.pPokemon[player.nowPokemon].baseStat + player.pPokemon[player.nowPokemon].level) * player.pPokemon[player.nowPokemon].skill[skillNum] / 65);	//체력 깎기
	//temp.Format(_T("내 체력 %d //// 적 체력 %d"), player.pPokemon[player.nowPokemon].nowHP, mob_pokemon.nowHP);	//임시사용
	//MessageBox(temp);
	if (mob_pokemon.nowHP < 0) {	//체력 0보다 작아질경우 0으로 만들기
		mob_pokemon.nowHP = 0;
	}

	turn = true;
	sound.HitOn();	//사운드
	m_playerAttackEffect = AfxBeginThread(playerAttackEffect, this);	//플레이어 스킬이펙트 쓰레드

	calcHpNum();
	m_mobHpBar = AfxBeginThread(mobHpBarThread, this);	//몹 체력 쓰레드

	//Sleep(1500);	//딜레이 주기

	if (mob_pokemon.nowHP == 0) {	//적 몬스터 죽었을 경우
		mob_pokemon.exist = false;
		//보상 추가하기
		MessageBox(_T("쓰러트렸다!"));
		getMobReward();	//보상
		mob_pokemon.setZero();
		mode = 2;
		Invalidate(TRUE);
		sound.MapOn();	//사운드
	}
	else {	//안죽었을 경우 반격
		bool mobturn;
		//MessageBox(_T("반격"));
		mobturn = mobAttack();
		//temp.Format(_T("내 체력 %d //// 적 체력 %d"), player.pPokemon[player.nowPokemon].nowHP, mob_pokemon.nowHP);	//임시사용
		//MessageBox(temp);
		if (mobturn) {
			mob_pokemon.exist = false;
			mob_pokemon.setZero();
			//TODO: 다죽었으니 전투 종료
			//TODO: 전투 종료시키고, 메인창 보내고, 몹 초기화 시키고, 돈 털고, 치료시켜주고
			player.gold = player.gold - player.avePoLevel * player.ownPoNum * 400;
			usePoCenter();
			if (player.gold < 0) {
				player.gold = 0;
			}
			mode = 1;
			sound.MainOn();	//사운드
			Invalidate(TRUE);
		}
	}
}


void CLetsGoPikachuDlg::calcHpNum()	//체력 숫자로 바꾸기
{
	int mobtemp[2];
	int playertemp[2];
	int mobhpoint = mob_pokemon.hPoint;
	int mobnowhp = mob_pokemon.nowHP;
	int playerhpoint = player.pPokemon[player.nowPokemon].hPoint;
	int playernowhp = player.pPokemon[player.nowPokemon].nowHP;
	int dnum = 1000;

	for (int i = 0; i < 4; i++) {
		mobtemp[0] = mobhpoint / dnum;
		mobHpNum[i] = convertNumPath(mobtemp[0]);
		mobhpoint = mobhpoint - (mobtemp[0] * dnum);

		mobtemp[1] = mobnowhp / dnum;
		mobHpNum[i + 4] = convertNumPath(mobtemp[1]);
		mobnowhp = mobnowhp - (mobtemp[1] * dnum);

		playertemp[0] = playerhpoint / dnum;
		playerHpNum[i] = convertNumPath(playertemp[0]);
		playerhpoint = playerhpoint - (playertemp[0] * dnum);

		playertemp[1] = playernowhp / dnum;
		playerHpNum[i + 4] = convertNumPath(playertemp[1]);
		playernowhp = playernowhp - (playertemp[1] * dnum);

		dnum = dnum / 10;
	}

	playerLevelNum[0] = convertNumPath(player.pPokemon[player.nowPokemon].level / 10);
	playerLevelNum[1] = convertNumPath(player.pPokemon[player.nowPokemon].level % 10);

	mobLevelNum[0] = convertNumPath(mob_pokemon.level / 10);
	mobLevelNum[1] = convertNumPath(mob_pokemon.level % 10);
}


CString CLetsGoPikachuDlg::convertNumPath(int num)	//각 숫자에 맞는 path반환
{
	CString result;
	switch (num)
	{
	case 0:
		result.Format(_T(".\\numlist\\num0.png"));
		break;
	case 1:
		result.Format(_T(".\\numlist\\num1.png"));
		break;
	case 2:
		result.Format(_T(".\\numlist\\num2.png"));
		break;
	case 3:
		result.Format(_T(".\\numlist\\num3.png"));
		break;
	case 4:
		result.Format(_T(".\\numlist\\num4.png"));
		break;
	case 5:
		result.Format(_T(".\\numlist\\num5.png"));
		break;
	case 6:
		result.Format(_T(".\\numlist\\num6.png"));
		break;
	case 7:
		result.Format(_T(".\\numlist\\num7.png"));
		break;
	case 8:
		result.Format(_T(".\\numlist\\num8.png"));
		break;
	case 9:
		result.Format(_T(".\\numlist\\num9.png"));
		break;
	default:
		break;
	}
	return result;
}


bool CLetsGoPikachuDlg::mobAttack() {
	int skill;
	bool check = false;

	srand((unsigned int)time(NULL));

	int temp = rand() % 100;	//사용할 스킬 정하기
	if (temp < 10) {
		skill = 3;
		mobSkill = 3;
	}
	else if (temp < 30) {
		skill = 2;
		mobSkill = 2;
	}
	else if (temp < 60) {
		skill = 1;
		mobSkill = 1;
	}
	else {
		skill = 0;
		mobSkill = 0;
	}

	MessageBox(mob_pokemon.koName + _T("는(은) ") + mob_pokemon.skillName[skill] + _T("를(을) 사용했다!"));
	//player.pPokemon[player.nowPokemon].nowHP = player.pPokemon[player.nowPokemon].nowHP - ((mob_pokemon.att * mob_pokemon.skill[skill] / 100) - player.pPokemon[player.nowPokemon].def);
	player.pPokemon[player.nowPokemon].nowHP = player.pPokemon[player.nowPokemon].nowHP - ((mob_pokemon.baseStat + mob_pokemon.level) * mob_pokemon.skill[skill] / 65);	//체력 깎기
	
	if (player.pPokemon[player.nowPokemon].nowHP < 0) {	//체력 0보다 작아질경우 0으로 만들기
		player.pPokemon[player.nowPokemon].nowHP = 0;
	}

	turn = false;
	sound.HitOn();	//사운드
	m_mobAttackEffect = AfxBeginThread(mobAttackEffect, this);	//몹 스킬이펙트 쓰레드

	calcHpNum();
	m_playerHpBar = AfxBeginThread(playerHpBarThread, this);	//플레이어 체력바 스레드

	if (player.pPokemon[player.nowPokemon].nowHP == 0) {	//죽었을 경우
		MessageBox(player.pPokemon[player.nowPokemon].koName + _T("는(은) 쓰러졌다."));
		check = checkPlayerPokemon();
		if (check) {	//모두 죽었을 경우
			MessageBox(_T("더 이상 싸울 포켓몬이 없다."));
			MessageBox(_T("눈앞이 캄캄해졌다."));
		}
		else {
			changePokemon();
		}
	}
	return check;
}


bool CLetsGoPikachuDlg::checkPlayerPokemon() {	//모두 죽을경우 true, 한마리라도 남아있으면 false
	bool check = true;
	for (int i = 0; i < 6; i++) {
		if (player.pPokemon[i].exist == true && player.pPokemon[i].nowHP != 0) {
			check = false;
			break;
		}
	}
	return check;
}


bool CLetsGoPikachuDlg::changePokemon() {	//현재 포켓몬 교체
	bool check = false;
	SelectPokemon selectPokemon((int)player.pPokemon[0].exist, (int)player.pPokemon[1].exist, (int)player.pPokemon[2].exist
		, (int)player.pPokemon[3].exist, (int)player.pPokemon[4].exist, (int)player.pPokemon[5].exist
		, player.pPokemon[0].nowHP, player.pPokemon[1].nowHP, player.pPokemon[2].nowHP
		, player.pPokemon[3].nowHP, player.pPokemon[4].nowHP, player.pPokemon[5].nowHP
		, player.pPokemon[0].forwardPath, player.pPokemon[1].forwardPath, player.pPokemon[2].forwardPath
		, player.pPokemon[3].forwardPath, player.pPokemon[4].forwardPath, player.pPokemon[5].forwardPath, mode);

	if (selectPokemon.DoModal() == IDOK) {
		if (player.nowPokemon != selectPokemon.select) {
			player.nowPokemon = selectPokemon.select;
			check = true;
			calcHpNum();
			Invalidate(TRUE);
		}
	}
	UpdateData(FALSE);

	calcHpNum();
	if (playerBarPoint < (player.pPokemon[player.nowPokemon].nowHP * 100 / player.pPokemon[player.nowPokemon].hPoint)) {
		m_playerIncreaseHpBar = AfxBeginThread(playerHpIncreaseThread, this);	//플레이어 체력바 증가 스레드
	}
	if (playerBarPoint > (player.pPokemon[player.nowPokemon].nowHP * 100 / player.pPokemon[player.nowPokemon].hPoint)) {
		m_playerHpBar = AfxBeginThread(playerHpBarThread, this);	//플레이어 체력바 스레드
	}

	MessageBox(_T("가랏! ") + player.pPokemon[player.nowPokemon].koName + _T("!"));

	return check;
}


void CLetsGoPikachuDlg::getMobReward() {	//보상 획득하기
	CString rewardMess;
	player.gold = player.gold + mob_pokemon.gold;	//골드 획득
	rewardMess.Format(_T("%dG 를 획득했다!"), mob_pokemon.gold);
	MessageBox(rewardMess);

	player.nowexp = player.nowexp + mob_pokemon.exp;	//플레이어 경험치 획득
	if (player.nowexp >= player.exp) {	//플레이어 레벨업 판단
		//MessageBox(_T("플레이어 는(은) 레벨업 했다!"));
		player.level++;
		player.setPlayerExp();
		player.nowexp = 0;
	}
	if (player.pPokemon[player.nowPokemon].level < 99) {	//레벨 99로 제한
		player.pPokemon[player.nowPokemon].nowExp = player.pPokemon[player.nowPokemon].nowExp + mob_pokemon.exp;	//포켓몬 경험치 획득
	}
	if (player.pPokemon[player.nowPokemon].nowExp >= player.pPokemon[player.nowPokemon].exp) {
		rewardMess.Format(player.pPokemon[player.nowPokemon].koName + _T("는(은) 레벨업 했다!"));
		MessageBox(rewardMess);
		player.pPokemon[player.nowPokemon].level++;
		player.pPokemon[player.nowPokemon].nowExp = 0;
		if (checkRevolution()) {	//진화시 실행 할 조건
			rewardMess.Format(player.pPokemon[player.nowPokemon].koName + _T("는(은) 진화 했다!!"));
			MessageBox(rewardMess);
			player.pPokemon[player.nowPokemon].listNo++;
		}
		player.pPokemon[player.nowPokemon].getStat();
		player.pPokemon[player.nowPokemon].setExp();
		player.pPokemon[player.nowPokemon].skillpoint[0] = 20;
		player.pPokemon[player.nowPokemon].skillpoint[1] = 10;
		player.pPokemon[player.nowPokemon].skillpoint[2] = 5;
		player.pPokemon[player.nowPokemon].skillpoint[3] = 3;

		player.setAvePoLevel();
	}
}


bool CLetsGoPikachuDlg::checkRevolution() {	//진화 체크(진화=>true, 진화x=>false)
	for (int i = 0; i < 8; i++) {
		if (player.pPokemon[player.nowPokemon].listNo == revolution15[i] && player.pPokemon[player.nowPokemon].level >= 15) {
			return true;
		}
		if (player.pPokemon[player.nowPokemon].listNo == revolution25[i] && player.pPokemon[player.nowPokemon].level >= 25) {
			return true;
		}
	}
	for (int j = 0; j < 6; j++) {
		if (player.pPokemon[player.nowPokemon].listNo == revolution20[j] && player.pPokemon[player.nowPokemon].level >= 20) {
			return true;
		}
	}
	return false;
}


bool CLetsGoPikachuDlg::useBall(int point) {	//볼 사용
	srand((unsigned int)time(NULL));
	bool result = false;
	int temp = rand() % 100;

	if (temp <= point) {
		//TODO: 잡기에 성공했다.
		player.getPokemon(mob_pokemon.listNo, mob_pokemon.level);	//사용자한테 포켓몬 넣어주기
		player.setAvePoLevel();
		result = true;
	}

	return result;
}

bool CLetsGoPikachuDlg::healPlayer(int heal) {	//플레이어 체력 회복
	bool check = false;
	if (mode == 3) {	//배틀중일경우
		player.pPokemon[player.nowPokemon].nowHP = player.pPokemon[player.nowPokemon].nowHP + heal;
		if (player.pPokemon[player.nowPokemon].nowHP > player.pPokemon[player.nowPokemon].hPoint) {
			player.pPokemon[player.nowPokemon].nowHP = player.pPokemon[player.nowPokemon].hPoint;
		}
		calcHpNum();
		m_playerIncreaseHpBar = AfxBeginThread(playerHpIncreaseThread, this);
	}
	else {	//배틀중이 아닐경우
		SelectPokemon selectPokemon((int)player.pPokemon[0].exist, (int)player.pPokemon[1].exist, (int)player.pPokemon[2].exist
			, (int)player.pPokemon[3].exist, (int)player.pPokemon[4].exist, (int)player.pPokemon[5].exist
			, player.pPokemon[0].nowHP, player.pPokemon[1].nowHP, player.pPokemon[2].nowHP
			, player.pPokemon[3].nowHP, player.pPokemon[4].nowHP, player.pPokemon[5].nowHP
			, player.pPokemon[0].forwardPath, player.pPokemon[1].forwardPath, player.pPokemon[2].forwardPath
			, player.pPokemon[3].forwardPath, player.pPokemon[4].forwardPath, player.pPokemon[5].forwardPath, mode);
		if (selectPokemon.DoModal() == IDOK) {
			player.pPokemon[selectPokemon.select].nowHP = player.pPokemon[selectPokemon.select].nowHP + heal;
			if (player.pPokemon[selectPokemon.select].nowHP > player.pPokemon[selectPokemon.select].hPoint) {
				player.pPokemon[selectPokemon.select].nowHP = player.pPokemon[selectPokemon.select].hPoint;
			}
			UpdateData(FALSE);
			check = true;
		}
	}
	return check;
}

UINT CLetsGoPikachuDlg::mobAttackEffect(LPVOID pParam) {	//몹 공격이펙트 쓰레드
	CLetsGoPikachuDlg *pWnd = (CLetsGoPikachuDlg*)pParam;
	pWnd->turn = false;

	while (pWnd->effectScale<=200)
	{
		pWnd->effectScale = pWnd->effectScale + 20;
		pWnd->Invalidate(FALSE);
		Sleep(100);
	}
	pWnd->effectScale = 0;
	pWnd->sound.BattleOn();	//사운드
	pWnd->Invalidate(FALSE);
	pWnd->m_mobAttackEffect->SuspendThread();

	return 0;
}

UINT CLetsGoPikachuDlg::playerAttackEffect(LPVOID pParam) {	//플레이어 공격이펙트 쓰레드
	CLetsGoPikachuDlg *pWnd = (CLetsGoPikachuDlg*)pParam;
	pWnd->turn = true;
	while (pWnd->effectScale <= 200)
	{
		pWnd->effectScale = pWnd->effectScale + 20;
		pWnd->Invalidate(FALSE);
		Sleep(100);
	}
	pWnd->effectScale = 0;
	pWnd->sound.BattleOn();	//사운드
	pWnd->Invalidate(FALSE);
	pWnd->m_playerAttackEffect->SuspendThread();

	return 0;
}

UINT CLetsGoPikachuDlg::playerHpIncreaseThread(LPVOID pParam) {	//플레이어 체력바 증가 쓰레드
	CLetsGoPikachuDlg *pWnd = (CLetsGoPikachuDlg*)pParam;

	while (pWnd->playerBarPoint < (pWnd->player.pPokemon[pWnd->player.nowPokemon].nowHP * 100 / pWnd->player.pPokemon[pWnd->player.nowPokemon].hPoint))
	{
		pWnd->playerBarPoint = pWnd->playerBarPoint + 5;
		if (pWnd->playerBarPoint > (pWnd->player.pPokemon[pWnd->player.nowPokemon].nowHP * 100 / pWnd->player.pPokemon[pWnd->player.nowPokemon].hPoint)) {
			pWnd->playerBarPoint = (pWnd->player.pPokemon[pWnd->player.nowPokemon].nowHP * 100 / pWnd->player.pPokemon[pWnd->player.nowPokemon].hPoint);
		}
		pWnd->Invalidate(FALSE);
		Sleep(50);
	}

	pWnd->m_playerIncreaseHpBar->SuspendThread();

	return 0;
}

UINT CLetsGoPikachuDlg::mobHpIncreaseThread(LPVOID pParam) {	//상대 체력바 증가 쓰레드
	CLetsGoPikachuDlg *pWnd = (CLetsGoPikachuDlg*)pParam;

	while (pWnd->mobBarPoint < (pWnd->mob_pokemon.nowHP * 100 / pWnd->mob_pokemon.hPoint))
	{
		pWnd->mobBarPoint = pWnd->mobBarPoint + 5;
		if (pWnd->mobBarPoint > (pWnd->mob_pokemon.nowHP * 100 / pWnd->mob_pokemon.hPoint)) {
			pWnd->mobBarPoint = (pWnd->mob_pokemon.nowHP * 100 / pWnd->mob_pokemon.hPoint);
		}
		pWnd->calcHpNum();
		pWnd->Invalidate(FALSE);
		Sleep(50);
	}

	pWnd->m_mobIncreaseHpBar->SuspendThread();

	return 0;
}

void CLetsGoPikachuDlg::usePoCenter() {	//포켓몬센터 이용(회복시키기)
	for (int i = 0; i < 6; i++) {
		if (player.pPokemon[i].exist == true) {
			player.pPokemon[i].nowHP = player.pPokemon[i].hPoint;
			player.pPokemon[i].skillpoint[0] = 20;
			player.pPokemon[i].skillpoint[1] = 10;
			player.pPokemon[i].skillpoint[2] = 5;
			player.pPokemon[i].skillpoint[3] = 3;
		}
	}
}

void CLetsGoPikachuDlg::DataLoad() {
	DataSaveLoad *pData = new DataSaveLoad;
	pData->dataload(player.playerID);

	player.level = pData->playerLevel;
	player.setPlayerExp();
	player.gold = pData->playerGold;
	player.nowexp = pData->playerExp;
	player.ownItem[0] = pData->item1;
	player.ownItem[1] = pData->item2;
	player.ownItem[2] = pData->item3;
	player.ownItem[3] = pData->item4;
	player.ownItem[4] = pData->item5;
	player.ownBall[0] = pData->monsterBall1;
	player.ownBall[1] = pData->monsterBall2;
	player.ownBall[2] = pData->monsterBall3;
	player.ownBall[3] = pData->monsterBall4;
	player.nowPokemon = pData->selectMonster;

	player.pPokemon[0].exist = (bool)pData->exist1;
	player.pPokemon[0].listNo = pData->number1;
	player.pPokemon[0].level = pData->poLevel1;
	player.pPokemon[0].getStat();
	player.pPokemon[0].setExp();
	player.pPokemon[0].nowHP = pData->pocketmon1;
	player.pPokemon[0].nowExp = pData->poExp1;
	player.pPokemon[0].skillpoint[0] = pData->poSkillPoint11;
	player.pPokemon[0].skillpoint[1] = pData->poSkillPoint12;
	player.pPokemon[0].skillpoint[2] = pData->poSkillPoint13;
	player.pPokemon[0].skillpoint[3] = pData->poSkillPoint14;

	player.pPokemon[1].exist = (bool)pData->exist2;
	player.pPokemon[1].listNo = pData->number2;
	player.pPokemon[1].level = pData->poLevel2;
	player.pPokemon[1].getStat();
	player.pPokemon[1].setExp();
	player.pPokemon[1].nowHP = pData->pocketmon2;
	player.pPokemon[1].nowExp = pData->poExp2;
	player.pPokemon[1].skillpoint[0] = pData->poSkillPoint21;
	player.pPokemon[1].skillpoint[1] = pData->poSkillPoint22;
	player.pPokemon[1].skillpoint[2] = pData->poSkillPoint23;
	player.pPokemon[1].skillpoint[3] = pData->poSkillPoint24;

	player.pPokemon[2].exist = (bool)pData->exist3;
	player.pPokemon[2].listNo = pData->number3;
	player.pPokemon[2].level = pData->poLevel3;
	player.pPokemon[2].getStat();
	player.pPokemon[2].setExp();
	player.pPokemon[2].nowHP = pData->pocketmon3;
	player.pPokemon[2].nowExp = pData->poExp3;
	player.pPokemon[2].skillpoint[0] = pData->poSkillPoint31;
	player.pPokemon[2].skillpoint[1] = pData->poSkillPoint32;
	player.pPokemon[2].skillpoint[2] = pData->poSkillPoint33;
	player.pPokemon[2].skillpoint[3] = pData->poSkillPoint34;

	player.pPokemon[3].exist = (bool)pData->exist4;
	player.pPokemon[3].listNo = pData->number4;
	player.pPokemon[3].level = pData->poLevel4;
	player.pPokemon[3].getStat();
	player.pPokemon[3].setExp();
	player.pPokemon[3].nowHP = pData->pocketmon4;
	player.pPokemon[3].nowExp = pData->poExp4;
	player.pPokemon[3].skillpoint[0] = pData->poSkillPoint41;
	player.pPokemon[3].skillpoint[1] = pData->poSkillPoint42;
	player.pPokemon[3].skillpoint[2] = pData->poSkillPoint43;
	player.pPokemon[3].skillpoint[3] = pData->poSkillPoint44;

	player.pPokemon[4].exist = (bool)pData->exist5;
	player.pPokemon[4].listNo = pData->number5;
	player.pPokemon[4].level = pData->poLevel5;
	player.pPokemon[4].getStat();
	player.pPokemon[4].setExp();
	player.pPokemon[4].nowHP = pData->pocketmon5;
	player.pPokemon[4].nowExp = pData->poExp5;
	player.pPokemon[4].skillpoint[0] = pData->poSkillPoint51;
	player.pPokemon[4].skillpoint[1] = pData->poSkillPoint52;
	player.pPokemon[4].skillpoint[2] = pData->poSkillPoint53;
	player.pPokemon[4].skillpoint[3] = pData->poSkillPoint54;

	player.pPokemon[5].exist = (bool)pData->exist6;
	player.pPokemon[5].listNo = pData->number6;
	player.pPokemon[5].level = pData->poLevel6;
	player.pPokemon[5].getStat();
	player.pPokemon[5].setExp();
	player.pPokemon[5].nowHP = pData->pocketmon6;
	player.pPokemon[5].nowExp = pData->poExp6;
	player.pPokemon[5].skillpoint[0] = pData->poSkillPoint61;
	player.pPokemon[5].skillpoint[1] = pData->poSkillPoint62;
	player.pPokemon[5].skillpoint[2] = pData->poSkillPoint63;
	player.pPokemon[5].skillpoint[3] = pData->poSkillPoint64;

	player.setAvePoLevel();
	delete pData;
}

void CLetsGoPikachuDlg::DataSave() {
	DataSaveLoad *pData = new DataSaveLoad;

	pData->dataset(player.playerID, player.level, player.gold, player.nowexp, player.ownItem[0], player.ownItem[1], player.ownItem[2], player.ownItem[3], player.ownItem[4]
		, player.ownBall[0], player.ownBall[1], player.ownBall[2], player.ownBall[3], player.nowPokemon
		, player.pPokemon[0].nowHP, (int)player.pPokemon[0].exist, player.pPokemon[0].listNo, player.pPokemon[0].level, player.pPokemon[0].nowExp
		, player.pPokemon[0].skillpoint[0], player.pPokemon[0].skillpoint[1], player.pPokemon[0].skillpoint[2], player.pPokemon[0].skillpoint[3]
		, player.pPokemon[1].nowHP, (int)player.pPokemon[1].exist, player.pPokemon[1].listNo, player.pPokemon[1].level, player.pPokemon[1].nowExp
		, player.pPokemon[1].skillpoint[0], player.pPokemon[1].skillpoint[1], player.pPokemon[1].skillpoint[2], player.pPokemon[1].skillpoint[3]
		, player.pPokemon[2].nowHP, (int)player.pPokemon[2].exist, player.pPokemon[2].listNo, player.pPokemon[2].level, player.pPokemon[2].nowExp
		, player.pPokemon[2].skillpoint[0], player.pPokemon[2].skillpoint[1], player.pPokemon[2].skillpoint[2], player.pPokemon[2].skillpoint[3]
		, player.pPokemon[3].nowHP, (int)player.pPokemon[3].exist, player.pPokemon[3].listNo, player.pPokemon[3].level, player.pPokemon[3].nowExp
		, player.pPokemon[3].skillpoint[0], player.pPokemon[3].skillpoint[1], player.pPokemon[3].skillpoint[2], player.pPokemon[3].skillpoint[3]
		, player.pPokemon[4].nowHP, (int)player.pPokemon[4].exist, player.pPokemon[4].listNo, player.pPokemon[4].level, player.pPokemon[4].nowExp
		, player.pPokemon[4].skillpoint[0], player.pPokemon[4].skillpoint[1], player.pPokemon[4].skillpoint[2], player.pPokemon[4].skillpoint[3]
		, player.pPokemon[5].nowHP, (int)player.pPokemon[5].exist, player.pPokemon[5].listNo, player.pPokemon[5].level, player.pPokemon[5].nowExp
		, player.pPokemon[5].skillpoint[0], player.pPokemon[5].skillpoint[1], player.pPokemon[5].skillpoint[2], player.pPokemon[5].skillpoint[3]);

	pData->datasave();
	delete pData;
}

void CLetsGoPikachuDlg::OnSaveExit()	//세이브 후 종료
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (mode == 0) {
		MessageBox(_T("로그인 후 이용 가능합니다."));
	}
	else {
		DataSave();
		MessageBox(_T("저장을 완료했습니다!"));
		MessageBox(_T("게임을 종료합니다."));
		OnOK();
	}
}


void CLetsGoPikachuDlg::OnSaveLogout()	//세이브 후 로그아웃
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (mode == 0) {
		MessageBox(_T("로그인 후 이용 가능합니다."));
	}
	else {
		DataSave();
		MessageBox(_T("저장 후 로그아웃합니다."));
		mode = 0;
		stage = 0;
		//TODO: 초기화 시켜야할게 더 있나?
		sound.LoginOn();
		Invalidate(TRUE);
	}
}



void CLetsGoPikachuDlg::OnSaveSave()	//세이브
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (mode == 0) {
		MessageBox(_T("로그인 후 이용 가능합니다."));
	}
	else {
		DataSave();
		MessageBox(_T("저장을 완료했습니다!"));
	}
}


void CLetsGoPikachuDlg::OnFileExit()	//종료
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	MessageBox(_T("게임을 종료합니다."));
	OnOK();
}


void CLetsGoPikachuDlg::OnInfoMakers()	//정보
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	MessageBox(_T("2018 동의대학교 컴퓨터소프트웨어 공학과 \n MFC 비주얼 프로그래밍 \n     송민광   김동현   정인환"), _T("CopyRight _ 2018 DEU-CSE"));
}


void CLetsGoPikachuDlg::OnHelpHelp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	MessageBox(_T("말도다 말도"));
}

void CLetsGoPikachuDlg::replacePo(int select, int listNo, int level) {
	player.pPokemon[select].setZero();
	player.pPokemon[select].exist = true;
	player.pPokemon[select].listNo = listNo;
	player.pPokemon[select].level = level;
	player.pPokemon[select].getStat();
	player.pPokemon[select].setExp();
	player.pPokemon[select].nowExp = 0;
	player.pPokemon[select].skillpoint[0] = 20;
	player.pPokemon[select].skillpoint[1] = 10;
	player.pPokemon[select].skillpoint[2] = 5;
	player.pPokemon[select].skillpoint[3] = 3;
	MessageBox(_T("자동 저장을 실행합니다!"));
	OnSaveSave();
}

void CLetsGoPikachuDlg::OnOptionSoundoption()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Setting setting((int)sound.backGround, (int)sound.effect);
	if (setting.DoModal() == IDOK) {
		if (setting.back_select == 1) {
			sound.Off();
			sound.backGround = true;
			switch (mode)
			{
			case 0:
				sound.LoginOn();
				break;
			case 1:
				sound.MainOn();
				break;
			case 2:
				sound.MapOn();
				break;
			case 3:
				sound.BattleOn();
				break;
			default:
				break;
			}
		}
		else {
			sound.backGround = false;
			sound.Off();
		}
		if (setting.effect_select == 1) {
			sound.effect = true;
		}
		else {
			sound.effect = false;
		}
		UpdateData(FALSE);
	}
}
