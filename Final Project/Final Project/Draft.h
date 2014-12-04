#ifndef _Draft_h_
#define _Draft_h_


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
private:
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
	/*
	Constructor for the draft object.  I would be calling this function from
	the ChampDatabase class.
	*/

	void addpickedChamps(string&);
	void addbannedChamps(string&);
	vector<string> getpickedChamps();
	vector<string> getbannedChamps();
	void executeDraft();
	Champion generateChamp();
	string getChampName();
	void setChampName(string&);
	void takeTurn();
	virtual void banChamps();// needs comp bann 
	virtual void pickChamps();// needs comp pick

	void compBan();
	void userBan();
	void userPick();
	void compPick(int);
	bool checkPick(string&);
	bool checkBan(string&);
	//bool checkPos(string&); //need for compPick. check that the champ fulfills a certain position.
	string compChampPick(int&);
	

	int whoseTurn();
	

	int score(); //need to develope scoring techniques
};


#endif