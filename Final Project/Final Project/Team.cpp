#include "Team.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


Team::Team(){ _points = 0; }
int Team::getPoints() { return _points; }
vector<string> Team::getTeamChampNames() { return _teamChampNames; }
string Team::getChamp(int i){ return _teamChampNames[i]; }


void Team::setPoints() { _points++; }


void Team::addTeamChampNames(string &champ)
{
	_teamChampNames.push_back(champ);
}
