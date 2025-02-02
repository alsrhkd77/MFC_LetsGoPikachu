#pragma once


// Store 대화 상자

class Store : public CDialog
{
	DECLARE_DYNAMIC(Store)

public:
	Store(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	Store(CString path1, CString path2, CString path3, CString path4, CString path5, CString path6, CString path7, CString path8, CString path9, CWnd* pParent = nullptr);   // 생성자입니다.
	virtual ~Store();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STORE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	int m_countitem1;
	int m_countitem2;
	int m_countitem3;
	int m_countitem4;
	int m_countitem5;
	int m_countitem6;
	int m_countitem7;
	int m_countitem8;
	int m_countitem9;
	int m_total;
	int getTotal();
	CString path[9];
	afx_msg void OnBnClickedButtBuy();
	afx_msg void OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin7(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin8(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin9(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin10(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin11(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin12(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin13(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin14(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin15(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin16(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin17(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin18(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin19(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin20(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnPaint();
};
