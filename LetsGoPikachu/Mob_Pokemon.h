#pragma once
#include "Pokemon.h"

class Mob_Pokemon: public Pokemon
{
public:
	Mob_Pokemon();
	~Mob_Pokemon();
	int exp;
	int gold;
	void setbattle();
	void setZero();

private:

};