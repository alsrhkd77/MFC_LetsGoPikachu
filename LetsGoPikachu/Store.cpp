// Store.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "Store.h"
#include "afxdialogex.h"


// Store 대화 상자

IMPLEMENT_DYNAMIC(Store, CDialog)

Store::Store(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_STORE_DIALOG, pParent)
	, m_countitem1(0)
	, m_countitem2(0)
	, m_countitem3(0)
	, m_countitem4(0)
	, m_countitem5(0)
	, m_countitem6(0)
	, m_countitem7(0)
	, m_countitem8(0)
	, m_countitem9(0)
	, m_total(0)
{
	m_countitem1 = 0;
	m_countitem2 = 0;
	m_countitem3 = 0;
	m_countitem4 = 0;
	m_countitem5 = 0;
	m_countitem6 = 0;
	m_countitem7 = 0;
	m_countitem8 = 0;
	m_countitem9 = 0;
	m_total = 0;
}

Store::Store(CString path1, CString path2, CString path3, CString path4, CString path5, CString path6, CString path7, CString path8, CString path9, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_STORE_DIALOG, pParent)
	, m_countitem1(0)
	, m_countitem2(0)
	, m_countitem3(0)
	, m_countitem4(0)
	, m_countitem5(0)
	, m_countitem6(0)
	, m_countitem7(0)
	, m_countitem8(0)
	, m_countitem9(0)
	, m_total(0)
{
	path[0] = path1;
	path[1] = path2;
	path[2] = path3;
	path[3] = path4;
	path[4] = path5;
	path[5] = path6;
	path[6] = path7;
	path[7] = path8;
	path[8] = path9;

	m_countitem1 = 0;
	m_countitem2 = 0;
	m_countitem3 = 0;
	m_countitem4 = 0;
	m_countitem5 = 0;
	m_countitem6 = 0;
	m_countitem7 = 0;
	m_countitem8 = 0;
	m_countitem9 = 0;
	m_total = 0;
}

Store::~Store()
{
}

void Store::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_countitem1);
	DDX_Text(pDX, IDC_EDIT3, m_countitem2);
	DDX_Text(pDX, IDC_EDIT4, m_countitem3);
	DDX_Text(pDX, IDC_EDIT5, m_countitem4);
	DDX_Text(pDX, IDC_EDIT6, m_countitem5);
	DDX_Text(pDX, IDC_EDIT7, m_countitem6);
	DDX_Text(pDX, IDC_EDIT8, m_countitem7);
	DDX_Text(pDX, IDC_EDIT9, m_countitem8);
	DDX_Text(pDX, IDC_EDIT10, m_countitem9);
	DDX_Text(pDX, IDC_EDIT_Total, m_total);
}


BEGIN_MESSAGE_MAP(Store, CDialog)
	ON_BN_CLICKED(IDCANCEL, &Store::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTT_BUY, &Store::OnBnClickedButtBuy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, &Store::OnDeltaposSpin3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN4, &Store::OnDeltaposSpin4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN5, &Store::OnDeltaposSpin5)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN6, &Store::OnDeltaposSpin6)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN7, &Store::OnDeltaposSpin7)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN8, &Store::OnDeltaposSpin8)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN9, &Store::OnDeltaposSpin9)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN10, &Store::OnDeltaposSpin10)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN11, &Store::OnDeltaposSpin11)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN12, &Store::OnDeltaposSpin12)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN13, &Store::OnDeltaposSpin13)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN14, &Store::OnDeltaposSpin14)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN15, &Store::OnDeltaposSpin15)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN16, &Store::OnDeltaposSpin16)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN17, &Store::OnDeltaposSpin17)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN18, &Store::OnDeltaposSpin18)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN19, &Store::OnDeltaposSpin19)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN20, &Store::OnDeltaposSpin20)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Store 메시지 처리기


void Store::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnCancel();
}


void Store::OnBnClickedButtBuy()
{
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

int Store::getTotal() {
	int result = 0;
	//TODO: 가격 설정하기
	result = result + (m_countitem1 * 100);
	result = result + (m_countitem2 * 200);
	result = result + (m_countitem3 * 300);
	result = result + (m_countitem4 * 400);
	result = result + (m_countitem5 * 500);
	result = result + (m_countitem6 * 600);
	result = result + (m_countitem7 * 700);
	result = result + (m_countitem8 * 800);
	result = result + (m_countitem9 * 900);
	return result;
}

void Store::OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult)	//몬스터볼
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem1++;
	}
	else {
		if (m_countitem1 > 0) {
			m_countitem1--;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem1 = m_countitem1 + 10;
	}
	else {
		m_countitem1 = m_countitem1 - 10;
		if (m_countitem1 < 0) {
			m_countitem1 = 0;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin5(NMHDR *pNMHDR, LRESULT *pResult)	//수퍼볼
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem2++;
	}
	else {
		if (m_countitem2 > 0) {
			m_countitem2--;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem2 = m_countitem2 + 10;
	}
	else {
		m_countitem2 = m_countitem2 - 10;
		if (m_countitem2 < 0) {
			m_countitem2 = 0;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin7(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem3++;
	}
	else {
		if (m_countitem3 > 0) {
			m_countitem3--;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin8(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem3 = m_countitem3 + 10;
	}
	else {
		m_countitem3 = m_countitem3 - 10;
		if (m_countitem3 < 0) {
			m_countitem3 = 0;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin9(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem4++;
	}
	else {
		if (m_countitem4 > 0) {
			m_countitem4--;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin10(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem4 = m_countitem4 + 10;
	}
	else {
		m_countitem4 = m_countitem4 - 10;
		if (m_countitem4 < 0) {
			m_countitem4 = 0;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin11(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem5++;
	}
	else {
		if (m_countitem5 > 0) {
			m_countitem5--;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin12(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem5 = m_countitem5 + 10;
	}
	else {
		m_countitem5 = m_countitem5 - 10;
		if (m_countitem5 < 0) {
			m_countitem5 = 0;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin13(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem6++;
	}
	else {
		if (m_countitem6 > 0) {
			m_countitem6--;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin14(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem6 = m_countitem6 + 10;
	}
	else {
		m_countitem6 = m_countitem6 - 10;
		if (m_countitem6 < 0) {
			m_countitem6 = 0;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin15(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem7++;
	}
	else {
		if (m_countitem7 > 0) {
			m_countitem7--;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin16(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem7 = m_countitem7 + 10;
	}
	else {
		m_countitem7 = m_countitem7 - 10;
		if (m_countitem7 < 0) {
			m_countitem7 = 0;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin17(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem8++;
	}
	else {
		if (m_countitem8 > 0) {
			m_countitem8--;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin18(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem8 = m_countitem8 + 10;
	}
	else {
		m_countitem8 = m_countitem8 - 10;
		if (m_countitem8 < 0) {
			m_countitem8 = 0;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin19(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem9++;
	}
	else {
		if (m_countitem9 > 0) {
			m_countitem9--;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnDeltaposSpin20(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData(TRUE);
	if (pNMUpDown->iDelta < 0) {
		m_countitem9 = m_countitem9 + 10;
	}
	else {
		m_countitem9 = m_countitem9 - 10;
		if (m_countitem9 < 0) {
			m_countitem9 = 0;
		}
	}
	m_total = getTotal();
	UpdateData(FALSE);
	*pResult = 0;
}


void Store::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	CBitmap bitmap[9];
	BITMAP bmpinfo;
	CImage itemimg[9];

	for (int i = 0; i < 9; i++) {
		itemimg[i].Load(path[i]);	//파일 경로 형식(상대경로)
		bitmap[i].Attach(itemimg[i].Detach());
		bitmap[i].GetBitmap(&bmpinfo);
		MemDC.SelectObject(&bitmap[i]);
		dc.TransparentBlt(45, 32 + (i * 46), 30, 30, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(96, 136, 104));
	}
	MemDC.DeleteDC();
}
