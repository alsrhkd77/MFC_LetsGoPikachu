#pragma once


// StartAdventure 대화 상자

class StartAdventure : public CDialog
{
	DECLARE_DYNAMIC(StartAdventure)

public:
	StartAdventure(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	StartAdventure(int listNo1, int listNo2, int listNo3, int listNo4, int listNo5, int listNo6
		, int level1, int level2, int level3, int level4, int level5, int level6
		, CString name1, CString name2, CString name3, CString name4, CString name5, CString name6
		, CWnd* pParent = nullptr);   // 생성자입니다.
	virtual ~StartAdventure();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STARTADVENTURE_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	int select;	//0=선택안함, 1=stage1, 2=stage2, 3=stage3, 4=대전
	int startNet();
	bool runSever();
	bool runClient();
	int listNo[6];
	int level[6];
	CString name[6];
	int changePo;
	int getListNo;
	int getLevel;
};
