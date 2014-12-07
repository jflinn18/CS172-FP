#ifndef _UserInput_h
#define _UserInput_h

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Champion.h"
#include "Team.h"

using namespace std;


class UserInput
{
private:
	string resp;
	vector<vector<string>> draftOutputFormat;

	void checkResp();
	void outputWinner(int, int);


public:
	UserInput();
	string whatDraft();
	string getInput();
	vector<vector<string>> getDraftOutputFormat();

	void banChamps();
	void pickChamps();
	void outputChamp(Champion);
	void outputTeamPoints(Team, Team);
	void checkBanned();
	void checkPicked();

	void updatebans(vector<string>);
	void updatepicks(vector<string>, vector<string>);

	void printMan();
	void clearWindow();
	void draftInputError();
	void draftOutput();
};

#endif