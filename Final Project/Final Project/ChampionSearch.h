#ifndef _ChampionSearch_h
#define _ChampionSerach_h


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ChampionSearch
{
private: 
	string champNameSearch;

public:
	void setChampName(string);
	string getChampName();

	void search(string);
};

#endif