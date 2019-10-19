#include "stdafx.h"
#include "Pokemon.h"
#include "PoInfo.h"

Pokemon::Pokemon() {	//생성자

}

void Pokemon::setAtt() {	//공격력 설정
	att = (baseStat * 2 * level) / 153;
}

void Pokemon::setDef() {	//방어력 설정
	def = (baseStat * 2 * level) / 164;
}

void Pokemon::setHPoint() {	//체력 설정
	//hPoint = ((baseStat * 2 * level) / 100) + 10;
	hPoint = baseStat * (level + 24) / 10;
}

void Pokemon::getStat() {
	PoInfo getItem(listNo);
	baseStat = getItem.species;	//종족값 설정
	skill[0] = getItem.damege1;	//위력 설정
	skill[1] = getItem.damege2;
	skill[2] = getItem.damege3;
	skill[3] = getItem.damege4;
	skillName[0] = getItem.skill1;	//스킬이름 설정
	skillName[1] = getItem.skill2;
	skillName[2] = getItem.skill3;
	skillName[3] = getItem.skill4;
	koName = getItem.name;	//이름 설정
	backPath.Format(_T(".\\pokemon\\back\\") + getItem.ename + _T(".png"));	//이미지 경로 설정
	forwardPath.Format(_T(".\\pokemon\\forward\\") + getItem.ename + _T(".png"));
	//읽어오기 끝

	//필요없음
	//TODO: 공격력, 방어력 삭제
	//setAtt();
	//setDef();
	setHPoint();
	nowHP = hPoint;
}