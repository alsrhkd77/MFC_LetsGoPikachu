#include "stdafx.h"
#include "Pokemon.h"
#include "PoInfo.h"

Pokemon::Pokemon() {	//������

}

void Pokemon::setAtt() {	//���ݷ� ����
	att = (baseStat * 2 * level) / 153;
}

void Pokemon::setDef() {	//���� ����
	def = (baseStat * 2 * level) / 164;
}

void Pokemon::setHPoint() {	//ü�� ����
	//hPoint = ((baseStat * 2 * level) / 100) + 10;
	hPoint = baseStat * (level + 24) / 10;
}

void Pokemon::getStat() {
	PoInfo getItem(listNo);
	baseStat = getItem.species;	//������ ����
	skill[0] = getItem.damege1;	//���� ����
	skill[1] = getItem.damege2;
	skill[2] = getItem.damege3;
	skill[3] = getItem.damege4;
	skillName[0] = getItem.skill1;	//��ų�̸� ����
	skillName[1] = getItem.skill2;
	skillName[2] = getItem.skill3;
	skillName[3] = getItem.skill4;
	koName = getItem.name;	//�̸� ����
	backPath.Format(_T(".\\pokemon\\back\\") + getItem.ename + _T(".png"));	//�̹��� ��� ����
	forwardPath.Format(_T(".\\pokemon\\forward\\") + getItem.ename + _T(".png"));
	//�о���� ��

	//�ʿ����
	//TODO: ���ݷ�, ���� ����
	//setAtt();
	//setDef();
	setHPoint();
	nowHP = hPoint;
}