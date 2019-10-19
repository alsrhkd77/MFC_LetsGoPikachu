#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class DataSaveLoad
{
public:
	int mas;
	char player[20];
	CString b;
	FILE *master;

	CString playerID;
	int playerLevel;
	int playerGold;
	int playerExp;
	int item1;
	int item2;
	int item3;
	int item4;
	int item5;
	int monsterBall1;
	int monsterBall2;
	int monsterBall3;
	int monsterBall4;
	int selectMonster;
	
	int pocketmon1;
	int exist1;
	int number1;
	int poLevel1;
	int poExp1;
	int poSkillPoint11;
	int poSkillPoint12;
	int poSkillPoint13;
	int poSkillPoint14;

	int pocketmon2;
	int exist2;
	int number2;
	int poLevel2;
	int poExp2;
	int poSkillPoint21;
	int poSkillPoint22;
	int poSkillPoint23;
	int poSkillPoint24;

	int pocketmon3;
	int exist3;
	int number3;
	int poLevel3;
	int poExp3;
	int poSkillPoint31;
	int poSkillPoint32;
	int poSkillPoint33;
	int poSkillPoint34;

	int pocketmon4;
	int exist4;
	int number4;
	int poLevel4;
	int poExp4;
	int poSkillPoint41;
	int poSkillPoint42;
	int poSkillPoint43;
	int poSkillPoint44;

	int pocketmon5;
	int exist5;
	int number5;
	int poLevel5;
	int poExp5;
	int poSkillPoint51;
	int poSkillPoint52;
	int poSkillPoint53;
	int poSkillPoint54;

	int pocketmon6;
	int exist6;
	int number6;
	int poLevel6;
	int poExp6;
	int poSkillPoint61;
	int poSkillPoint62;
	int poSkillPoint63;
	int poSkillPoint64;

	DataSaveLoad();
	~DataSaveLoad();
	
	void dataset(CString playerID,int playerLevel,int playerGold,int playerExp,int item1,int item2,int item3,int item4,int item5,
	int monsterBall1,int monsterBall2,int monsterBall3,int monsterBall4,int selectMonster,
	int pocketmon1,int exist1,int number1,int poLevel1,int poExp1,int poSkillPoint11,int poSkillPoint12,int poSkillPoint13,int poSkillPoint14,
	int pocketmon2,int exist2,int number2,int poLevel2,int poExp2,int poSkillPoint21,int poSkillPoint22,int poSkillPoint23,int poSkillPoint24,
	int pocketmon3,int exist3,int number3,int poLevel3,int poExp3,int poSkillPoint31,int poSkillPoint32,int poSkillPoint33,int poSkillPoint34,
	int pocketmon4,int exist4,int number4,int poLevel4,int poExp4,int poSkillPoint41,int poSkillPoint42,int poSkillPoint43,int poSkillPoint44,
	int pocketmon5,int exist5,int number5,int poLevel5,int poExp5,int poSkillPoint51,int poSkillPoint52,int poSkillPoint53,int poSkillPoint54,
	int pocketmon6,int exist6,int number6,int poLevel6,int poExp6,int poSkillPoint61,int poSkillPoint62,int poSkillPoint63,int poSkillPoint64);
	void datasave();
	void dataload(CString playerID);
};

