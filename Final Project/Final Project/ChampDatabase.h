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
	void setChampSearch();
	void addChamp(string&);
	void createChampList();
	void createChamps();

public:
	ChampDatabase();
	void completeADraft();
	Champion getChamp(string&);
	
	
};

#endif