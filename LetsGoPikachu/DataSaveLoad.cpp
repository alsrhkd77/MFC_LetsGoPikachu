#include "stdafx.h"
#include "DataSaveLoad.h"


DataSaveLoad::DataSaveLoad()
{
}


DataSaveLoad::~DataSaveLoad()
{
}

void DataSaveLoad::dataset(CString playerID, int playerLevel, int playerGold, int playerExp, int item1, int item2, int item3, int item4, int item5, int monsterBall1, int monsterBall2, int monsterBall3, int monsterBall4, int selectMonster, int pocketmon1, int exist1, int number1, int poLevel1, int poExp1, int poSkillPoint11, int poSkillPoint12, int poSkillPoint13, int poSkillPoint14, int pocketmon2, int exist2, int number2, int poLevel2, int poExp2, int poSkillPoint21, int poSkillPoint22, int poSkillPoint23, int poSkillPoint24, int pocketmon3, int exist3, int number3, int poLevel3, int poExp3, int poSkillPoint31, int poSkillPoint32, int poSkillPoint33, int poSkillPoint34, int pocketmon4, int exist4, int number4, int poLevel4, int poExp4, int poSkillPoint41, int poSkillPoint42, int poSkillPoint43, int poSkillPoint44, int pocketmon5, int exist5, int number5, int poLevel5, int poExp5, int poSkillPoint51, int poSkillPoint52, int poSkillPoint53, int poSkillPoint54, int pocketmon6, int exist6, int number6, int poLevel6, int poExp6, int poSkillPoint61, int poSkillPoint62, int poSkillPoint63, int poSkillPoint64)
{
	// 객체만들고 set으로 저장할 데이터 넣어주면 됨 (매개변수 ㅈㄴ많음) 아 배열쓰고싶다
	this->playerID = playerID;
	this->playerLevel = playerLevel;
	this->playerGold = playerGold;
	this->playerExp = playerExp;
	this->item1 = item1;
	this->item2 = item2;
	this->item3 = item3;
	this->item4 = item4;
	this->item5 = item5;
	this->monsterBall1 = monsterBall1;
	this->monsterBall2 = monsterBall2;
	this->monsterBall3 = monsterBall3;
	this->monsterBall4 = monsterBall4;
	this->selectMonster = selectMonster;

	this->pocketmon1 = pocketmon1;
	this->exist1 = exist1;
	this->number1 = number1;
	this->poLevel1 = poLevel1;
	this->poExp1 = poExp1;
	this->poSkillPoint11 = poSkillPoint11;
	this->poSkillPoint12 = poSkillPoint12;
	this->poSkillPoint13 = poSkillPoint13;
	this->poSkillPoint14 = poSkillPoint14;

	this->pocketmon2 = pocketmon2;
	this->exist2 = exist2;
	this->number2 = number2;
	this->poLevel2 = poLevel2;
	this->poExp2 = poExp2;
	this->poSkillPoint21 = poSkillPoint21;
	this->poSkillPoint22 = poSkillPoint22;
	this->poSkillPoint23= poSkillPoint23;
	this->poSkillPoint24= poSkillPoint24;

	this->pocketmon3= pocketmon3;
	this->exist3= exist3;
	this->number3= number3;
	this->poLevel3= poLevel3;
	this->poExp3= poExp3;
	this->poSkillPoint31= poSkillPoint31;
	this->poSkillPoint32 = poSkillPoint32;
	this->poSkillPoint33 = poSkillPoint33;
	this->poSkillPoint34 = poSkillPoint34;

	this->pocketmon4 = pocketmon4;
	this->exist4 = exist4;
	this->number4 = number4;
	this->poLevel4 = poLevel4;
	this->poExp4 = poExp4;
	this->poSkillPoint41 = poSkillPoint41;
	this->poSkillPoint42 = poSkillPoint42;
	this->poSkillPoint43 = poSkillPoint43;
	this->poSkillPoint44 = poSkillPoint44;

	this->pocketmon5 = pocketmon5;
	this->exist5 = exist5;
	this->number5 = number5;
	this->poLevel5 = poLevel5;
	this->poExp5 = poExp5;
	this->poSkillPoint51 = poSkillPoint51;
	this->poSkillPoint52 = poSkillPoint52;
	this->poSkillPoint53 = poSkillPoint53;
	this->poSkillPoint54 = poSkillPoint54;

	this->pocketmon6 = pocketmon6;
	this->exist6 = exist6;
	this->number6 = number6;
	this->poLevel6 = poLevel6;
	this->poExp6 = poExp6;
	this->poSkillPoint61 = poSkillPoint61;
	this->poSkillPoint62 = poSkillPoint62;
	this->poSkillPoint63 = poSkillPoint63;
	this->poSkillPoint64 = poSkillPoint64;

}

void DataSaveLoad::datasave(){

	fopen_s(&master, "saveload.txt", "r+");
	if (master == 0) {
		exit(-1);
	}

	int count = 0;

	CT2CA pszConvertedAnsiString(playerID);
	string s1(pszConvertedAnsiString);
	const char *a = s1.c_str();
	
	int num1 = playerLevel;
	int num2 = playerGold;
	int num3 = playerExp;
	int num4 = item1;
	int num5 = item2;
	int num6 = item3;
	int num7 = item4;
	int num8 = item5;
	int num9 = monsterBall1;
	int num10 = monsterBall2;
	int num11 = monsterBall3;
	int num12 = monsterBall4;
	int num13 = selectMonster;

	int num14 = pocketmon1;
	int num15 = exist1;
	int num16 = number1;
	int num17 = poLevel1;
	int num18 = poExp1;
	int num19 = poSkillPoint11;
	int num20 = poSkillPoint12;
	int num21 = poSkillPoint13;
	int num22 = poSkillPoint14;

	int num23 = pocketmon2;
	int num24 = exist2;
	int num25 = number2;
	int num26 = poLevel2;
	int num27 = poExp2;
	int num28 = poSkillPoint21;
	int num29 = poSkillPoint22;
	int num30 = poSkillPoint23;
	int num31 = poSkillPoint24;

	int num32 = pocketmon3;
	int num33 = exist3;
	int num34 = number3;
	int num35 = poLevel3;
	int num36 = poExp3;
	int num37 = poSkillPoint31;
	int num38 = poSkillPoint32;
	int num39 = poSkillPoint33;
	int num40 = poSkillPoint34;

	int num41 = pocketmon4;
	int num42 = exist4;
	int num43 = number4;
	int num44 = poLevel4;
	int num45 = poExp4;
	int num46 = poSkillPoint41;
	int num47 = poSkillPoint42;
	int num48 = poSkillPoint43;
	int num49 = poSkillPoint44;

	int num50 = pocketmon5;
	int num51 = exist5;
	int num52 = number5;
	int num53 = poLevel5;
	int num54 = poExp5;
	int num55 = poSkillPoint51;
	int num56 = poSkillPoint52;
	int num57 = poSkillPoint53;
	int num58 = poSkillPoint54;

	int num59 = pocketmon6;
	int num60 = exist6;
	int num61 = number6;
	int num62 = poLevel6;
	int num63 = poExp6;
	int num64 = poSkillPoint61;
	int num65 = poSkillPoint62;
	int num66 = poSkillPoint63;
	int num67 = poSkillPoint64;

	while (1) {			
		mas = fscanf_s(master, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
			player, sizeof(player), &playerLevel, &playerGold, &playerExp, &item1, &item2, &item3, &item4, &item5,
			&monsterBall1, &monsterBall2, &monsterBall3, &monsterBall4, &selectMonster,
			&pocketmon1, &exist1, &number1, &poLevel1, &poExp1, &poSkillPoint11, &poSkillPoint12, &poSkillPoint13, &poSkillPoint14,
			&pocketmon2, &exist2, &number2, &poLevel2, &poExp2, &poSkillPoint21, &poSkillPoint22, &poSkillPoint23, &poSkillPoint24,
			&pocketmon3, &exist3, &number3, &poLevel3, &poExp3, &poSkillPoint31, &poSkillPoint32, &poSkillPoint33, &poSkillPoint34,
			&pocketmon4, &exist4, &number4, &poLevel4, &poExp4, &poSkillPoint41, &poSkillPoint42, &poSkillPoint43, &poSkillPoint44,
			&pocketmon5, &exist5, &number5, &poLevel5, &poExp5, &poSkillPoint51, &poSkillPoint52, &poSkillPoint53, &poSkillPoint54,
			&pocketmon6, &exist6, &number6, &poLevel6, &poExp6, &poSkillPoint61, &poSkillPoint62, &poSkillPoint63, &poSkillPoint64
		);		
		b = (CString)player;
		if (player == playerID) {
			fseek(master, count+1,SEEK_SET);
			fprintf_s(master, "xxxxxxxxxxx");
			break;
		}
		count = ftell(master);
		if (mas == EOF) {		
			break;
		}
	}
	fseek(master, 0, SEEK_END);
	fprintf_s(master, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
		a, num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13,
		num14, num15, num16, num17, num18, num19, num20, num21, num22,
		num23, num24, num25, num26, num27, num28, num29, num30, num31,
		num32, num33, num34, num35, num36, num37, num38, num39, num40,
		num41, num42, num43, num44, num45, num46, num47, num48, num49,
		num50, num51, num52, num53, num54, num55, num56, num57, num58,
		num59, num60, num61, num62, num63, num64, num65, num66, num67
	);
	fclose(master);
}

void DataSaveLoad::dataload(CString playerID)
{
	
	string a;

	fopen_s(&master, "saveload.txt", "r");
	if (master == 0) {
		exit(-1);
	}

	while(1) {
		if (b == playerID) {
			break;
		}
		mas = fscanf_s(master, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
			player, sizeof(player),  &playerLevel, &playerGold, &playerExp, &item1, &item2, &item3, &item4, &item5,
			&monsterBall1, &monsterBall2, &monsterBall3, &monsterBall4, &selectMonster,
			&pocketmon1, &exist1, &number1, &poLevel1, &poExp1, &poSkillPoint11, &poSkillPoint12, &poSkillPoint13, &poSkillPoint14,
			&pocketmon2, &exist2, &number2, &poLevel2, &poExp2, &poSkillPoint21, &poSkillPoint22, &poSkillPoint23, &poSkillPoint24,
			&pocketmon3, &exist3, &number3, &poLevel3, &poExp3, &poSkillPoint31, &poSkillPoint32, &poSkillPoint33, &poSkillPoint34,
			&pocketmon4, &exist4, &number4, &poLevel4, &poExp4, &poSkillPoint41, &poSkillPoint42, &poSkillPoint43, &poSkillPoint44,
			&pocketmon5, &exist5, &number5, &poLevel5, &poExp5, &poSkillPoint51, &poSkillPoint52, &poSkillPoint53, &poSkillPoint54,
			&pocketmon6, &exist6, &number6, &poLevel6, &poExp6, &poSkillPoint61, &poSkillPoint62, &poSkillPoint63, &poSkillPoint64
			);
		b = (CString)player;
		if (mas == EOF) {
			break;
		}
	}
	this->playerID = b;
	fclose(master);
}
