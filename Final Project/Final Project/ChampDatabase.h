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
	vector<Champion> _champs;
public:
	ChampDatabase();
	void completeADraft();
	void addChamp(string);
	Champion getChamp(Champion);
	void createChampList();
};

#endif