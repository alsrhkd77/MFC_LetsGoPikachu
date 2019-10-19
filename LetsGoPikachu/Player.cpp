#include "stdafx.h"
#include "Player.h"
#include "Player_Pokemon.h"

Player::Player() {
	//TODO : 초기화 할 값 있는지 확인하기(저장 가능할경우->데이터 읽어오기 / 저장불가-> 초기설정ㄱㄱ)
	pPokemon = new Player_Pokemon[6];
	//임시사용
	gold = 1000000;
}

Player::~Player() {
	delete[] pPokemon;
}

void Player::setPokemon() {
	for (int i = 0; i < 5; i++) {	//포켓몬 객체 초기화 하기
		pPokemon[i].listNo = 40 + i;	//도감번호 설정
		pPokemon[i].level = 50;		//레벨 설정
		pPokemon[i].getStat();
		pPokemon[i].setExp();
		//TODO: 현재체력 설정해주기, 존재여부 설정해주기
		pPokemon[i].exist = true;	//임시(세이브 파일에서 로드할 것)
		pPokemon[i].skillpoint[0] = 20;
		pPokemon[i].skillpoint[1] = 10;
		pPokemon[i].skillpoint[2] = 5;
		pPokemon[i].skillpoint[3] = 3;
		pPokemon[i].nowExp = 0;
	}
	ownBall[0] = 100;
	ownBall[1] = 100;
	ownBall[2] = 100;
	ownBall[3] = 100;
	ownItem[0] = 100;
	ownItem[1] = 100;
	ownItem[2] = 100;
	ownItem[3] = 100;
	ownItem[4] = 100;

	setAvePoLevel();	//평균레벨 구하기=>그냥써도됨
}

void Player::setLevel(int level) {
	this->level = level;
}

void Player::addPlayerExp(int getexp) {
	nowexp = nowexp + 4;
	if (nowexp >= exp) {
		level++;
		setPlayerExp();
		exp = 0;
	}
}

void Player::getPokemon(int listNo, int level) {
	for (int i = 0; i < 6; i++) {
		if (pPokemon[i].exist == false) {
			pPokemon[i].exist = true;
			pPokemon[i].listNo = listNo;
			pPokemon[i].level = level;
			pPokemon[i].getStat();
			pPokemon[i].setExp();
			pPokemon[i].skillpoint[0] = 20;
			pPokemon[i].skillpoint[1] = 10;
			pPokemon[i].skillpoint[2] = 5;
			pPokemon[i].skillpoint[3] = 3;
			break;
		}
	}
}

void Player::setAvePoLevel() {
	int result = 0;
	ownPoNum = 0;
	for (int i = 0; i < 6; i++) {
		if (pPokemon[i].exist == true) {
			result = result + pPokemon[i].level;
			ownPoNum++;
		}
	}
	avePoLevel = result / ownPoNum;
}

int Player::getPlayerLevel() {
	return level;
}

int Player::getPlayerExp() {
	return exp;
}

int Player::getPlayerOwnPoNum() {
	return ownPoNum;
}

int Player::getPlayerOwnItem(int ownItem) {
	return this->ownItem[ownItem];
}

int Player::getPlayerOwnBall(int ownBall) {
	return this->ownBall[ownBall];
}

void Player::setPlayerExp() {
	exp = level * 12;
}