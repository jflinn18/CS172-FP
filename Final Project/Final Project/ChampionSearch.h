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
	//string _champNameSearch;

public:
	ChampionSearch();
	ChampionSearch(vector<string>&);
	//void setChampNameSearch(string);
	//string getChampNameSearch();

	int search(string&);
};

#endif