#include "stdafx.h"
#include "Mob_Pokemon.h"

Mob_Pokemon::Mob_Pokemon()
{
	exist = false;
}

Mob_Pokemon::~Mob_Pokemon()
{
}

void Mob_Pokemon::setbattle() {	//���� ���� ����
	exist = true;
	//�����ɵ�
	//listNo = 38;	//�������ֱ�
	//level = 50;		//�������ֱ�
	getStat();
	exp = baseStat * 2 * level / 225;	//����ġ ����
	gold = level * 150;	//��� ����
}

void Mob_Pokemon::setZero() {	//�ʱ�ȭ��Ű��
	exist = false;
	listNo = 0;
	level = 0;
	exp = 0;
	gold = 0;
}