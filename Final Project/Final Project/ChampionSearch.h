#ifndef _ChampionSearch_h
#define _ChampionSerach_h


#include <iostream>
#include <string>
#include <vector>
#include "Champion.h"


using namespace std;

class ChampionSearch
{
private: 
	vector<string> _champs;

public:
	//ChampionSearch();
	ChampionSearch(vector<string>&);
	~ChampionSearch();

	int search(string&);
};

#endif