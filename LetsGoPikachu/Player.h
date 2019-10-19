#include "Player_Pokemon.h"

#pragma once

class Player {
public:
	Player();	//������
	~Player();	//�Ҹ���
	CString playerID;
	int level;		//����
	int gold;		//���(��)
	int exp;		//�� ����ġ
	int nowexp;		//���� ����ġ
	int ownPoNum;	//������ ���ϸ� ����
	int avePoLevel;	//������ ���ϸ� ��շ���
	int ownItem[5];	//������ ������ ����(��ó�� / ���� ��ó�� / ����� ���� / ����� ��� / ���� �簻)
	int ownBall[4];	//������ ���ͺ� ����(���ͺ� / ���ۺ� / �����ۺ� / �����ͺ�)
	int nowPokemon;
	void setPokemon();	//���ϸ� ���� ���� �������ֱ�
	void setPlayerExp();	//���� �� ����ġ ����
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
