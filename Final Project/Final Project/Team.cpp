#include "Team.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


int Team::getPoints() { return _points; }
vector<string> Team::getTeamChampNames() { return _teamChampNames; }
string Team::getChamp(int& i){ return _teamChampNames[i]; }


void Team::setPoints(int pts) { _points = pts; }


void Team::addTeamChampNames(string &champ)
{
	_teamChampNames.push_back(champ);
}
