#include "Team.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


int Team::getPoints() { return _points; }
vector<string> Team::getTeamChampNames() { return _teamChampNames; }


void Team::setPoints(int &pts) { _points = pts; }


void Team::addTeamChampNames(string &champ)
{
	_teamChampNames.push_back(champ);
}
