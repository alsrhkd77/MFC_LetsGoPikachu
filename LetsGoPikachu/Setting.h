#pragma once


// Setting 대화 상자

class Setting : public CDialog
{
	DECLARE_DYNAMIC(Setting)

public:
	Setting(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	Setting(int back_select, int effect_select, CWnd* pParent = nullptr);   // 생성자입니다.
	virtual ~Setting();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	DECLARE_MESSAGE_MAP()
public:
	int back_select;
	int effect_select;
	int m_back;
	int m_effect;
	afx_msg void OnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
};
