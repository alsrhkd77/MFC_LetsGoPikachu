#pragma once
#include "Pokemon.h"

class Player_Pokemon: public Pokemon {
public:
	Player_Pokemon ();
	~Player_Pokemon ();
	int exp;
	int nowExp;
	int skillpoint[4];	//��ų1=20, ��ų2=10, ��ų3=5, ��ų4=3
	void setExp();
	void setZero();

private:

};
