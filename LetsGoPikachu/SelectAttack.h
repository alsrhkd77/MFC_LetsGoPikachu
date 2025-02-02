#pragma once


// SelectAttack 대화 상자

class SelectAttack : public CDialog
{
	DECLARE_DYNAMIC(SelectAttack)

public:
	SelectAttack(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	SelectAttack(CString skill1, CString skill2, CString skill3, CString skill4
		, int skillpoint1, int skillpoint2, int skillpoint3, int skillpoint4
		, CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SelectAttack();
	int select;	//0=선택안함, 1,2,3,4=스킬

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECTATTACK_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString skill1;
	CString skill2;
	CString skill3;
	CString skill4;
	CString skillpoint1;
	CString skillpoint2;
	CString skillpoint3;
	CString skillpoint4;
	afx_msg void OnClickedButtSkill1();
	afx_msg void OnClickedButtSkill2();
	afx_msg void OnClickedButtSkill3();
	afx_msg void OnClickedButtSkill4();
	afx_msg void OnBnClickedCancel();
	CButton m_skill1;
	CButton m_skill2;
	CButton m_skill3;
	CButton m_skill4;
	CStatic m_static4;
	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
	CString convertNum(int num);
};
