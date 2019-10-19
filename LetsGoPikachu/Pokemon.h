#pragma once

/* 포켓몬 클래스(객체 만들지 말 것) */
class Pokemon {
public:
	Pokemon();
	~Pokemon() {};
	bool exist;	//생존여부
	int listNo;	//도감번호
	int baseStat;	//종족값
	int level;	//레벨
	int hPoint;	//총 체력
	int nowHP;	//현재 체력
	int skill[4];	//기술 1,2,3,4의 위력
	CString *skillName = new CString[4];	//기술 1,2,3,4의 이름
	CString koName;
	CString enName;
	CString backPath;
	CString forwardPath;
	int att;	//공격력
	int def;	//방어력
	void getStat();	//값 읽어오기

protected:
	void setAtt();	//공격력 설정
	void setDef();	//방어력 설정
	void setHPoint();	//총 체력 설정
	//TODO 공방설정, 체력설정 도감번호나 레벨 받아오면서 설정해주기
};
