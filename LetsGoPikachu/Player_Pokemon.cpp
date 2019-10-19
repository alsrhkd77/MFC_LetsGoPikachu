#include "stdafx.h"
#include "Player_Pokemon.h"

Player_Pokemon::Player_Pokemon()
{
	setZero();
}

Player_Pokemon ::~Player_Pokemon()
{
}

void Player_Pokemon::setExp() {
	exp = baseStat * 2 * level / 75;
}

void Player_Pokemon::setZero() {
	exist = false;
	listNo = 0;
	baseStat = 0;
	level = 0;
	nowHP = 0;
	nowExp = 0;
	skillpoint[0] = 0;
	skillpoint[1] = 0;
	skillpoint[2] = 0;
	skillpoint[3] = 0;
}