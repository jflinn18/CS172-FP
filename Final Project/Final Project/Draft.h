#ifndef _Draft_h
#define _Draft_h


#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Team.h"
#include "UserInput.h"
#include "ChampionSearch.h"
using namespace std;



class Draft
{
protected:
	Team _user; // maybe Team user and Team computer
	Team _computer;
	UserInput _ui;
	vector<string> pickedChamps; // this stores all of the champions picked so far in the draft (for both sides)
	vector<string> bannedChamps; //vector of all banned champs.
	vector<Champion> _champs;
	vector<string> _listChampNames;
	ChampionSearch *_champSearch;
public:
	Draft(vector<string>, vector<Champion>);
	~Draft();
	/*
	Constructor for the draft object.  I would be calling this function from
	the ChampDatabase class.
	*/

	void addpickedChamps(string&);
	void addbannedChamps(string&);
	vector<string> getpickedChamps();
	vector<string> getbannedChamps();

	void executeDraft();
	virtual void banChamps() = 0;// needs comp bann 
	virtual void pickChamps() = 0;// needs comp pick

	void compBan();
	void userBan();
	void userPick();
	void compPick(int);
	bool checkPick(string&);
	bool checkBan(string&);
	//bool checkPos(string&); //need for compPick. check that the champ fulfills a certain position.
	string compChampPick(int&);

	void score(); //need to develope scoring techniques
};


#endif