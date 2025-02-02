// SignIn.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "SignIn.h"
#include "afxdialogex.h"
#include "SignUp.h"
#include <string>
#include "DataSaveLoad.h"


// SignIn 대화 상자

IMPLEMENT_DYNAMIC(SignIn, CDialog)

SignIn::SignIn(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SIGNIN_DIALOG, pParent)
	, m_input_id(_T(""))
	, m_input_pw(_T(""))
{

}

SignIn::~SignIn()
{
}

void SignIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_input_id);
	DDX_Text(pDX, IDC_EDIT_PW, m_input_pw);
}


BEGIN_MESSAGE_MAP(SignIn, CDialog)
	ON_BN_CLICKED(IDOK, &SignIn::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &SignIn::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTT_SIGNUP, &SignIn::OnBnClickedButtSignup)
END_MESSAGE_MAP()


// SignIn 메시지 처리기


void SignIn::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnOK();
}


void SignIn::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnCancel();
}


void SignIn::OnBnClickedButtSignup()	//확인(회원가입)
{
	SignUp Dlg;
	FILE *IDPW;
	CString rString;

	if (Dlg.DoModal() == IDOK) {
		fopen_s(&IDPW, "IDPW.txt", "a");

		CT2CA pszConvertedAnsiString(Dlg.m_input_id);
		std::string s1(pszConvertedAnsiString);
		CT2CA pszConvertedAnsiString2(Dlg.m_input_pw);
		std::string s2(pszConvertedAnsiString2);
		const char *a = s1.c_str();
		const char *b = s2.c_str();

		fprintf_s(IDPW, "%s %s\n", a, b);

		fclose(IDPW);

		makeNewSave(Dlg.m_input_id);

		rString.Format(_T("회원가입이 되었습니다."));
		AfxMessageBox(rString);

		
		UpdateData(FALSE);
	}
}

void SignIn::makeNewSave(CString playerID) {
	DataSaveLoad *pData = new DataSaveLoad;

	pData->dataset(playerID, 1, 10000, 0, 50, 0, 0, 0, 0, 100, 10, 5, 1, 0, 1649, 1, 1, 10, 0, 20, 10, 5, 3
		, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	pData->datasave();

	delete pData;
}