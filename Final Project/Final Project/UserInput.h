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
	//Team a;
	//Team b;
	vector<vector<string>> draftOutputFormat;

	void checkResp();
	void draftOutput();
    void outputWinner(int, int);


public:
	UserInput();
	//UserInput(Team, Team);
	string whatDraft();
	string getInput();

	void banChamps();
	void pickChamps();
	void outputChamp(Champion);
	void outputTeamPoints(Team, Team);
	
	void updatebans(vector<string>);
	void updatepicks(vector<string>, vector<string>);

	void printMan();
	void clearWindow();
};

#endif