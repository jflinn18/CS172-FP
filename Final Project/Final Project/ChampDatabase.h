#ifndef _ChampDatabase_h
#define _ChampDatabase_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Champion.h"
#include "ChampionSearch.h"
#include "UserInput.h"
#include "CompDraft.h"
#include "UserDraft.h"

using namespace std;


class ChampDatabase
{
private: 
	vector<Champion> _champs;
	vector<string> _listOfChampNames;
	ChampionSearch *champSearch; 
	UserInput *_ui;
	CompDraft *_cd;
	UserDraft *_ud;
	void setChampSearch();
	void addChamp(string&);
	void createChampList();
	void createChamps();
	void allocateDraft(string&);

public:
	ChampDatabase();
	~ChampDatabase();
	void completeADraft();
	Champion getChamp(string&);

	vector<Champion> getChamps();
	vector<string> getList();
	
	
};

#endif