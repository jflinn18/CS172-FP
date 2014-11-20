#ifndef _ChampDatabase_h
#define _ChampDatabase_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Champion.h"

using namespace std;

class ChampDatabase
{
private: 
	vector<Champion> champs();
public:
	void completeADraft();
	void addChamp(Champion);
	Champion getChamp();
};

#endif