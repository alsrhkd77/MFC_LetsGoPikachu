#pragma once


// PokemonCenter 대화 상자

class PokemonCenter : public CDialog
{
	DECLARE_DYNAMIC(PokemonCenter)

public:
	PokemonCenter(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	PokemonCenter(int owngold, int gold, int sOnOff, CWnd* pParent = nullptr);   // 생성자입니다.
	virtual ~PokemonCenter();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POKEMONCENTER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CStatic m_static;
	int getgold;
	int getowngold;
	int gold;
	int owngold;
	int sOnOff;
	CString calcNum(int Num);
	CString convertNum(int Num);
	CStatic m_owngold;
};
