#pragma once
#include "Pokemon.h"

class Player_Pokemon: public Pokemon {
public:
	Player_Pokemon ();
	~Player_Pokemon ();
	int exp;
	int nowExp;
	int skillpoint[4];	//스킬1=20, 스킬2=10, 스킬3=5, 스킬4=3
	void setExp();
	void setZero();

private:

};
