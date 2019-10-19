#pragma once
#ifndef __POINFO_H__

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class PoInfo
{
public:
	FILE *master;
	int serialNumber;
	int species;
	int damege1;
	int damege2;
	int damege3;
	int damege4;
	CString name;
	CString ename;
	CString skill1;
	CString skill2;
	CString skill3;
	CString skill4;

	PoInfo(int num = 1);
	~PoInfo();
};
#endif // !__POINFO_H__
