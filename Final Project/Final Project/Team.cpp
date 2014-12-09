#include "Team.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


Team::Team(){ _points = 0; } //creates a team and initializes score to 0
int Team::getPoints() { return _points; } //simple get function
vector<string> Team::getTeamChampNames() { return _teamChampNames; }// simple get function
string Team::getChamp(int i){ return _teamChampNames[i]; }// simpe get function


void Team::setPoints() { _points++; } //updates the score

//creates a list of the teams' champions names
void Team::addTeamChampNames(string &champ)
{
	_teamChampNames.push_back(champ);
}
