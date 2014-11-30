#ifndef _TxtFileProof_h
#define _TxtFileProof_h

#include <iostream>
#include <vector>
#include <string>
#include "ChampDatabase.h"
#include "ChampionSearch.h"

using namespace std;


class TxtFileProof
{
private: 
	ChampDatabase _cd;
	ChampionSearch _cs;
	vector<Champion> _champs;
	vector<string> _listOfChamps;
	vector<string> _pos;
	vector<string> _roles;



public:
	TxtFileProof();

	void proofChamps();
	bool proofPositions(int);
	bool proofGoodCounters(int);
	bool proofBadCounters(int);
	bool proofRoles(int);

	int search(vector<string>&, string);
	void setPos();
	void setRoles();


};


#endif