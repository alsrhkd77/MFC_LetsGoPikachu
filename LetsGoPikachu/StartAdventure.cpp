// StartAdventure.cpp: 구현 파일
//

#include "stdafx.h"
#include "LetsGoPikachu.h"
#include "StartAdventure.h"
#include "afxdialogex.h"
#include "SelectNet.h"
#include "CNet.h"
#include "SNet.h"


// StartAdventure 대화 상자

IMPLEMENT_DYNAMIC(StartAdventure, CDialog)

StartAdventure::StartAdventure(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_STARTADVENTURE_DIALOG1, pParent)
{
	select = 0;
}

StartAdventure::StartAdventure(int listNo1, int listNo2, int listNo3, int listNo4, int listNo5, int listNo6
	, int level1, int level2, int level3, int level4, int level5, int level6
	, CString name1, CString name2, CString name3, CString name4, CString name5, CString name6
	, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_STARTADVENTURE_DIALOG1, pParent)
{
	listNo[0] = listNo1;
	listNo[1] = listNo2;
	listNo[2] = listNo3;
	listNo[3] = listNo4;
	listNo[4] = listNo5;
	listNo[5] = listNo6;

	level[0] = level1;
	level[1] = level2;
	level[2] = level3;
	level[3] = level4;
	level[4] = level5;
	level[5] = level6;

	name[0] = name1;
	name[1] = name2;
	name[2] = name3;
	name[3] = name4;
	name[4] = name5;
	name[5] = name6;

	select = 0;
	getListNo = 0;
	getLevel = 0;
}

StartAdventure::~StartAdventure()
{

}

void StartAdventure::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(StartAdventure, CDialog)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// StartAdventure 메시지 처리기


void StartAdventure::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	CBitmap bitmap1, bitmap2, bitmap3, bitmap4;
	BITMAP bmpinfo;

	dc.SetStretchBltMode(COLORONCOLOR);	//색깔 안깨지게하기

	bitmap1.LoadBitmapW(adventureButton1);
	bitmap1.GetBitmap(&bmpinfo);
	CBitmap *oldBitmap = MemDC.SelectObject(&bitmap1);
	dc.StretchBlt(50, 70, 200, 120, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

	bitmap2.LoadBitmapW(adventureButton2);
	bitmap2.GetBitmap(&bmpinfo);
	MemDC.SelectObject(&bitmap2);
	dc.StretchBlt(300, 70, 200, 120, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

	bitmap3.LoadBitmapW(adventureButton3);
	bitmap3.GetBitmap(&bmpinfo);
	MemDC.SelectObject(&bitmap3);
	dc.StretchBlt(550, 70, 200, 120, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

	bitmap4.LoadBitmapW(adventureButton4);
	bitmap4.GetBitmap(&bmpinfo);
	MemDC.SelectObject(&bitmap4);
	dc.StretchBlt(800, 70, 200, 120, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

	dc.SelectObject(oldBitmap);
	MemDC.DeleteDC();
}


void StartAdventure::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (point.x > 50 && point.x < 250 && point.y>70 && point.y < 190) {		//stage1
		select = 1;
		OnOK();
	}
	else if (point.x > 300 && point.x < 500 && point.y>70 && point.y < 190) {	//stage2
		select = 2;
		OnOK();
	}
	else if (point.x > 550 && point.x < 750 && point.y>70 && point.y < 190) {	//stage3
		select = 3;
		OnOK();
	}
	else if (point.x > 800 && point.x < 1000 && point.y>70 && point.y < 190) {	//통신 대전
		int net = startNet();
		
		if (net == 1) {
			//서버
			if (runSever()) {;
				select = 4;
				OnOK();
			}
		}
		if (net == 2) {
			//클라이언트
			if (runClient()) {
				select = 4;
				OnOK();
			}
		}
		
	}
	else {
		select = 0;
		OnOK();
	}
	CDialog::OnLButtonUp(nFlags, point);
}

int StartAdventure::startNet() {
	int result = 0;;

	SelectNet selectnet;
	if (selectnet.DoModal() == IDOK) {
		result = selectnet.select;
		UpdateData(FALSE);
	}
	return result;
}

bool StartAdventure::runSever() {
	bool result = false;
	SNet net(listNo[0], listNo[1], listNo[2], listNo[3], listNo[4], listNo[5],level[0], level[1], level[2], level[3], level[4], level[5],name[0], name[1], name[2], name[3], name[4], name[5]);
	if (net.DoModal() == IDOK) {
		if (net.getchange == true && net.sendchange == true) {
			this->getListNo = net.getListNo;
			this->getLevel = net.getLevel;
			changePo = net.select;
			result = true;
		}
		UpdateData(FALSE);
	}
	return result;
}

bool StartAdventure::runClient() {
	bool result = false;
	CNet net(listNo[0], listNo[1], listNo[2], listNo[3], listNo[4], listNo[5], level[0], level[1], level[2], level[3], level[4], level[5], name[0], name[1], name[2], name[3], name[4], name[5]);
	if (net.DoModal() == IDOK) {
		if (net.getchange == true && net.sendchange == true) {
			this->getListNo = net.getListNo;
			this->getLevel = net.getLevel;
			changePo = net.select;
			result = true;
		}
		UpdateData(FALSE);
	}
	return result;
}