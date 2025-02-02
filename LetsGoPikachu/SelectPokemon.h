#pragma once


// SelectPokemon 대화 상자

class SelectPokemon : public CDialog
{
	DECLARE_DYNAMIC(SelectPokemon)

public:
	SelectPokemon(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	SelectPokemon(int exist1, int exist2, int exist3, int exist4, int exist5, int exist6
		, int hp1, int hp2, int hp3, int hp4, int hp5, int hp6
		, CString path1, CString path2, CString path3, CString path4, CString path5, CString path6
		,int mode , CWnd* pParent = nullptr);   // 생성자입니다.
	virtual ~SelectPokemon();
	int select;
	int exist[6];
	int hp[6];
	CString path[6];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECTPOKEMON_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
	CStatic m_static4;
	CStatic m_static5;
	CStatic m_static6;
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int mode;
//	int posX;
//	int posY;
};
