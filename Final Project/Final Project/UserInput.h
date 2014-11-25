#ifndef _UserInput_h
#define _UserInput_h

#include <iostream>
#include "Team.h"
#include <string>

using namespace std;


class UserInput
{
public:
	string resp;
	Team a;
	Team b;

	UserInput(Team a, Team b);
	void draft();
	void banChamps();
	void pickChamps();
	void outputChamp();
	void outputTeamPoints();
	void outputWinner();
	string getInput();

	void clearWindow();
};

#endif