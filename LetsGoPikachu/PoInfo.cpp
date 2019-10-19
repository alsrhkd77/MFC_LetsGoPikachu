#include "stdafx.h"
#include "PoInfo.h"
#include <stdio.h>
#include <string.h>	


PoInfo::PoInfo(int num)
{
	char name[20];
	char ename[20];
	char skill1[20];
	char skill2[20];
	char skill3[20];
	char skill4[20];


	fopen_s(&master, "PoList.txt", "r");
	if (master == 0) {
		exit(-1);
	}

	for (int i = 0; i < num; i++) {
		fscanf_s(master, "%d %s  %s %d %s %d %s %d %s %d %s %d\n ",
			&serialNumber, name, sizeof(name), ename, sizeof(ename), &species, skill1, sizeof(skill1), &damege1,
			skill2, sizeof(skill2), &damege2, skill3, sizeof(skill3), &damege3, skill4,
			sizeof(skill4), &damege4);

	}
	this->name = name;
	this->ename = ename;
	this->skill1 = skill1;
	this->skill2 = skill2;
	this->skill3 = skill3;
	this->skill4 = skill4;
	fclose(master);
}

PoInfo::~PoInfo()
{

}

