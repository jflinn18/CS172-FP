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
	ChampionSearch(vector<string>&);

	int search(string&, int, int);
};

#endif