#include "stdafx.h"
#include "Mob_Pokemon.h"

Mob_Pokemon::Mob_Pokemon()
{
	exist = false;
}

Mob_Pokemon::~Mob_Pokemon()
{
}

void Mob_Pokemon::setbattle() {	//몬스터 출현 설정
	exist = true;
	//뺴도될듯
	//listNo = 38;	//설정해주기
	//level = 50;		//설정해주기
	getStat();
	exp = baseStat * 2 * level / 225;	//경험치 설정
	gold = level * 150;	//골드 설정
}

void Mob_Pokemon::setZero() {	//초기화시키기
	exist = false;
	listNo = 0;
	level = 0;
	exp = 0;
	gold = 0;
}