#ifndef _ChampDatabase_h
#define _ChampDatabase_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Champion.h"
#include "ChampionSearch.h"

using namespace std;


class ChampDatabase
{
private: 
	vector<Champion> _champs;
	vector<string> _listOfChampNames;
	ChampionSearch champSearch;
public:
	ChampDatabase();
	void completeADraft();
	void addChamp(string&);
	Champion getChamp(string&);
	void createChampList();
};

#endif