#include "Player_Pokemon.h"

#pragma once

class Player {
public:
	Player();	//생성자
	~Player();	//소멸자
	CString playerID;
	int level;		//레벨
	int gold;		//골드(돈)
	int exp;		//총 경험치
	int nowexp;		//보유 경험치
	int ownPoNum;	//보유한 포켓몬 갯수
	int avePoLevel;	//보유한 포켓몬 평균레벨
	int ownItem[5];	//보유한 아이템 갯수(상처약 / 좋은 상처약 / 기력의 조각 / 기력의 덩어리 / 숲의 양갱)
	int ownBall[4];	//보유한 몬스터볼 갯수(몬스터볼 / 수퍼볼 / 하이퍼볼 / 마스터볼)
	int nowPokemon;
	void setPokemon();	//포켓몬 각각 값들 설정해주기
	void setPlayerExp();	//유저 총 경험치 설정
	void setAvePoLevel();
	void setLevel(int level = 1);
	void addPlayerExp(int getexp);
	void getPokemon(int listNo, int level);
	int getPlayerLevel();
	int getPlayerExp();
	int getPlayerOwnPoNum();
	int getPlayerOwnItem(int ownItem);
	int getPlayerOwnBall(int ownBall);
	Player_Pokemon *pPokemon;
private:
};
