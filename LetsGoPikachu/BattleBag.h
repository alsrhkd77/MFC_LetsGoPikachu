#pragma once


// BattleBag 대화 상자

class BattleBag : public CDialog
{
	DECLARE_DYNAMIC(BattleBag)

public:
	BattleBag(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	BattleBag(int item1, int item2, int item3, int item4, int item5, int item6, int item7, int item8, int item9
		,CString path1, CString path2, CString path3, CString path4, CString path5, CString path6, CString path7, CString path8, CString path9
		, int mode, CWnd* pParent = nullptr);   // 생성자입니다.
	virtual ~BattleBag();
	int select;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BATTLEBAG_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int mode;	//1=배틀중, 0=메인화면
	int item[9];
	CString path[9];
	afx_msg void OnPaint();
	CString calcNum(int Num);
	CString convertNum(int Num);
	CStatic m_item1;
	CStatic m_item2;
	CStatic m_item3;
	CStatic m_item4;
	CStatic m_item5;
	CStatic m_item6;
	CStatic m_item7;
	CStatic m_item8;
	CStatic m_item9;
	CButton m_use1;
	CButton m_use2;
	CButton m_use3;
	CButton m_use4;
	CButton m_use5;
	CButton m_use6;
	CButton m_use7;
	CButton m_use8;
	CButton m_use9;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
};
