
// LetsGoPikachuDlg.h: 헤더 파일
//

#include "Player.h"
#include "Sound.h"
#include "Mob_Pokemon.h"

#pragma once


// CLetsGoPikachuDlg 대화 상자
class CLetsGoPikachuDlg : public CDialogEx
{
// 생성입니다.
public:
	CLetsGoPikachuDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LETSGOPIKACHU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	int mode;	//0=시작화면, 1=메인화면, 2=맵, 3=배틀(AI)
	int stage;	//0=맵상태 아님, 1부터 시작
	int moveCheck;	//이동 타이머가 작동중인지 아닌지(0= 미작동, 1=걷기1단계 2=걷기2단계)
	int charDir;	//캐릭터 방향(0=위, 1=아래, 2=왼쪽, 3=오른쪽)
	int charFoot;	//캐릭터 왼발오른발(1=왼발, -1=오른발)
	int charPosX;
	int charPosY;
	CString charPath;
	Player player;
	Mob_Pokemon mob_pokemon;
public:
	Sound sound;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//	int m_posxinfo;
//	int m_posinfoy;
	int mobBarPoint;
	int playerBarPoint;
	int revolution15[8] = { 6,9,18,21,27,30,33,36 };
	int revolution20[6] = { 2,4,12,14,16,25 };
	int revolution25[8] = { 7,10,16,22,28,31,34,37 };
	int playerSkill;
	int mobSkill;
	int effectScale;
	bool turn;	//true=플레이어 공격, false=상대 공격
	void DataLoad();
	void DataSave();
	void replacePo(int select, int listNo, int level);
	CString itemPath[9];
	CString skillEffectPath[4];
	CString playerHpNum[8];
	CString mobHpNum[8];
	CString playerLevelNum[2];
	CString mobLevelNum[2];
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	bool healPlayer(int heal);
	void playerAttack(int skillNum);
	bool mobAttack(); //모두 죽을경우 true, 한마리라도 남아있으면 false
	bool checkPlayerPokemon();	//모두 죽을경우 true, 한마리라도 남아있으면 false
	bool changePokemon();	//포켓몬 교체
	void getMobReward();	//몹잡을시 보상 획득
	bool checkRevolution();	//진화 체크(진화=>true, 진화x=>false)
	bool useBall(int point);	//몬스터볼 사용
	void setWildPokemon();	//stage별 출현 포켓몬 설정
	void usePoCenter();	//포켓몬 센터 이용(회복시키기)
	static UINT mobAttackEffect(LPVOID pParam);	//몹 스킬이펙트 쓰레드
	CWinThread *m_mobAttackEffect;
	static UINT playerAttackEffect(LPVOID pParam);	//플레이어 스킬이펙트 쓰레드
	CWinThread *m_playerAttackEffect;
	static UINT mobHpBarThread(LPVOID pParam);	//몹 hp감소 쓰레드
	CWinThread *m_mobHpBar;
	static UINT playerHpBarThread(LPVOID pParam);	//플레이어 hp감소 쓰레드
	CWinThread *m_playerHpBar;
	static UINT mobHpIncreaseThread(LPVOID pParm);
	CWinThread *m_mobIncreaseHpBar;
	static UINT playerHpIncreaseThread(LPVOID pParm);
	CWinThread *m_playerIncreaseHpBar;
	void calcHpNum();
	CString convertNumPath(int num);
	afx_msg void OnSaveExit();
	afx_msg void OnSaveLogout();
	afx_msg void OnSaveSave();
	afx_msg void OnFileExit();
	afx_msg void OnInfoMakers();
	afx_msg void OnHelpHelp();
	afx_msg void OnOptionSoundoption();
};
