#ifndef _ChampDatabase_h
#define _ChampDatabase_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Champion.h"
#include "UserInput.h"
#include "CompDraft.h"
#include "UserDraft.h"

using namespace std;


class ChampDatabase
{
private: 
	vector<Champion> _champs;
	vector<string> _listOfChampNames;
	UserInput *_ui;
	CompDraft *_cd;
	UserDraft *_ud;
	void addChamp(string&);
	void createChampList();
	void createChamps();
	void allocateDraft(string&);

public:
	ChampDatabase();
	void completeADraft();

	vector<Champion> getChamps();
	vector<string> getList();
};

#endif