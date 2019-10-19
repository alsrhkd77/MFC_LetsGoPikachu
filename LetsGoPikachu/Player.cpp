#include "stdafx.h"
#include "Player.h"
#include "Player_Pokemon.h"

Player::Player() {
	//TODO : �ʱ�ȭ �� �� �ִ��� Ȯ���ϱ�(���� �����Ұ��->������ �о���� / ����Ұ�-> �ʱ⼳������)
	pPokemon = new Player_Pokemon[6];
	//�ӽû��
	gold = 1000000;
}

Player::~Player() {
	delete[] pPokemon;
}

void Player::setPokemon() {
	for (int i = 0; i < 5; i++) {	//���ϸ� ��ü �ʱ�ȭ �ϱ�
		pPokemon[i].listNo = 40 + i;	//������ȣ ����
		pPokemon[i].level = 50;		//���� ����
		pPokemon[i].getStat();
		pPokemon[i].setExp();
		//TODO: ����ü�� �������ֱ�, ���翩�� �������ֱ�
		pPokemon[i].exist = true;	//�ӽ�(���̺� ���Ͽ��� �ε��� ��)
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

	setAvePoLevel();	//��շ��� ���ϱ�=>�׳ɽᵵ��
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