// SignUp.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "SignUp.h"
#include "afxdialogex.h"


// SignUp 대화 상자

IMPLEMENT_DYNAMIC(SignUp, CDialog)

SignUp::SignUp(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SIGNUP_DIALOG, pParent)
	, m_input_id(_T(""))
	, m_input_pw(_T(""))
{

}

SignUp::~SignUp()
{
}

void SignUp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_input_id);
	DDX_Text(pDX, IDC_EDIT_PW, m_input_pw);
}


BEGIN_MESSAGE_MAP(SignUp, CDialog)
	ON_BN_CLICKED(IDC_BUTT_CHECK, &SignUp::OnClickedButtCheck)
	ON_BN_CLICKED(IDOK, &SignUp::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &SignUp::OnBnClickedCancel)
END_MESSAGE_MAP()


// SignUp 메시지 처리기


void SignUp::OnClickedButtCheck()	//중복체크
{
	int check = 0, mas;
	char id[20];
	char pw[20];
	

	fopen_s(&IDPW, "IDPW.txt", "r");  			// 마스터 파일 Open 
	UpdateData(TRUE);

	while (1) {
		mas = fscanf_s(IDPW, "%s %s", id, sizeof(id), pw, sizeof(pw));
		if (m_input_id == id)
			check++;
		if (mas == EOF)
			break;
	}

	fclose(IDPW);

	if (check == 0) {
		MessageBox(_T("사용 가능한 아이디입니다."));
		GetDlgItem(IDOK)->EnableWindow(TRUE);
	}
	else {
		CString rString;
		rString.Format(_T("아이디가 중복됩니다."));
		AfxMessageBox(rString);
	}
	UpdateData(FALSE);
}


void SignUp::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnOK();
}


void SignUp::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnCancel();
}
