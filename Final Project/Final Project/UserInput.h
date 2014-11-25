#ifndef _UserInput_h
#define _UserInput_h

#include <iostream>
#include "Champion.h"
#include "Team.h"
#include <string>

using namespace std;


class UserInput
{
private:
	string resp;
	Team a;
	Team b;

	void checkResp();


public:
	UserInput();
	UserInput(Team, Team);
	string whatDraft();
	string getInput();

	void banChamps();
	void pickChamps();
	void outputChamp(Champion);
	void outputTeamPoints(string);
	void outputWinner(string);
	void draftOutput();

	void printMan();
	void clearWindow();
};

#endif