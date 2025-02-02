#pragma once


// SignUp 대화 상자

class SignUp : public CDialog
{
	DECLARE_DYNAMIC(SignUp)

public:
	SignUp(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SignUp();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIGNUP_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	FILE *IDPW;
	afx_msg void OnClickedButtCheck();
	CString m_input_id;
	CString m_input_pw;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
