#pragma once


// ViewInfo 대화 상자

class ViewInfo : public CDialog
{
	DECLARE_DYNAMIC(ViewInfo)

public:
	ViewInfo(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	ViewInfo(int exist1, int exist2, int exist3, int exist4, int exist5, int exist6
		, int nhp1, int nhp2, int nhp3, int nhp4, int nhp5, int nhp6
		, int thp1, int thp2, int thp3, int thp4, int thp5, int thp6
		, int nexp1, int nexp2, int nexp3, int nexp4, int nexp5, int nexp6
		, int texp1, int texp2, int texp3, int texp4, int texp5, int texp6
		, int level1, int level2, int level3, int level4, int level5, int level6
		, CString name1, CString name2, CString name3, CString name4, CString name5, CString name6
		, CString path1, CString path2, CString path3, CString path4, CString path5, CString path6
		, CWnd* pParent = nullptr);   // 생성자입니다.
	virtual ~ViewInfo();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEWINFO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString none;
	int select;
	bool trash;
	afx_msg void OnPaint();
	int calchpProgress();
	int calcexpProgress();
	CComboBox m_combo;
	CProgressCtrl m_expPrograss;
	CProgressCtrl m_hpProgress;
	CStatic m_level;
	CStatic m_name;
	CStatic m_nexp;
	CStatic m_nhp;
	CStatic m_texp;
	CStatic m_thp;
	int exist[6];
	int nhp[6];
	int thp[6];
	int nexp[6];
	int texp[6];
	int level[6];
	CString name[6];
	CString path[6];
	CString temp;
	afx_msg void OnSelchangeCombo();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtTrash();
	afx_msg void OnBnClickedCancel();
};
