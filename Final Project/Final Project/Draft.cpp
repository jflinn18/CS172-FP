#include "Draft.h"
#include "Team.h"
#include "UserInput.h"
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>



Draft::Draft(vector<string> listchamps, vector<Champion> champs)
{
	_listChampNames = listchamps;
	_champs = champs;


	executeDraft();
}


void Draft::addpickedChamps(string &champ) { pickedChamps.push_back(champ); }
void Draft::addbannedChamps(string &champ) { bannedChamps.push_back(champ); }
vector<string> Draft::getpickedChamps() { return pickedChamps; }
vector<string> Draft::getbannedChamps() { return bannedChamps; }


void Draft::compBan()
{
	srand(time(NULL)); // move to constructor??
	int k = rand() % 121;

	string banned = "";
	banned = _listChampNames[k];

	while (!checkBan(banned)){ //checks that the champion hasn't been banned already.
		k = rand() % 121;
		banned = _listChampNames[k];
	}
	addbannedChamps(banned);
	_ui.updatebans(bannedChamps);
}

void Draft::userBan()
{
	string banned = "";
	_ui.banChamps();
	banned = _ui.getInput();


	while (!checkBan(banned)){ //checks that the champion hasn't been banned already.
		_ui.checkBanned();
		banned = _ui.getInput();	//check again????
	}
	addbannedChamps(banned);
	_ui.updatebans(bannedChamps);
}

bool Draft::checkBan(string& ban){
	for (int i = 0; i < bannedChamps.size(); i++){ //checks that the champion hasn't been banned already.

		if (bannedChamps[i] == ban){
			return false;
		}
	}
}

bool Draft::checkPick(string& pick){
	for (int i = 0; i < pickedChamps.size(); i++){ //checks that the champion hasn't been picked already.

		if (pickedChamps[i] == pick){
			return false;
		}
	}
}

void Draft::banChamps(){// need to finish
	if (){//conditional for whoever is going first.

		for (int i = 0; i < 3; i++){
			userBan();
			compBan();
		}
	}
	else{
		for (int i = 0; i < 3; i++){
			compBan();
			userBan();
		}
	}
}


void Draft::userPick(){
	string picked = "";
	_ui.banChamps();
	picked = _ui.getInput();


	while (!checkPick(picked)){ //checks that the champion hasn't been banned already.


		_ui.checkPicked();
		picked = _ui.getInput();	//check again????
	}
	addpickedChamps(picked);
	_user.addTeamChampNames(picked);
	_ui.updatepicks(_user.getTeamChampNames, _computer.getTeamChampNames);
}


void Draft::compPick(){
	int k = rand() % 121;

	string picked = "";
	picked = _listChampNames[k];

	while (!checkPick(picked)){ //checks that the champion hasn't been banned already.
		k = rand() % 121;
		picked = _listChampNames[k];
	}
	addpickedChamps(picked);
	_computer.addTeamChampNames(picked);
	_ui.updatepicks(_user.getTeamChampNames, _computer.getTeamChampNames);
}


void Draft::pickChamps(){
	if (){ //user is going first
		userPick();
		compPick();
		compPick();
		userPick();
		userPick();
		compPick();
		compPick();
		userPick();
		userPick();
		compPick();
	
	}

	else{
		compPick();
		userPick();
		userPick();
		compPick();
		compPick();
		userPick();
		userPick();
		compPick();
		compPick();
		userPick();
	}
}

bool Draft::checkPos(string&){}

void Draft::executeDraft(){
	banChamps();
	pickChamps();
	score();
}
/*
Like we talked about in class, this is the "main" for this class.  This will be
doing all of the executing of different functions to get through a draft.

This will probably look like:
virtual void executeDraft();

If it looks like the above line, there would not be a body for this function.
It would be overrode in both of the subclasses of Draft.  Thus, no body for this
function.  It would be in the two subclasses.
*/




int Draft::score(){} //need to develope scoring techniques