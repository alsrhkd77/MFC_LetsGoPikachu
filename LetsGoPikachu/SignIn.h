#pragma once


// SignIn 대화 상자

class SignIn : public CDialog
{
	DECLARE_DYNAMIC(SignIn)

public:
	SignIn(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SignIn();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIGNIN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_input_id;
	CString m_input_pw;
	void makeNewSave(CString playerID);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtSignup();
};
