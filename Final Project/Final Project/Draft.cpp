#include "Draft.h"
#include "Team.h"
#include "UserInput.h"
#include <string>
#include <vector>
#include <iostream>



Draft::Draft(vector<string> champs)
{
	UserInput ui();

	_ui.setUI(ui); // figure this out at least by/on Thursday

	vector<string> vecstr;
}


void Draft::addpickedChamps(string &champ) { pickedChamps.push_back(champ); }
void Draft::addbannedChamps(string &champ) { bannedChamps.push_back(champ); }
vector<string> Draft::getpickedChamps() {}
vector<string> Draft::getbannedChamps() {}


void Draft::computerBan()
{

}

void Draft::userBan()
{
	string banned = "";
	_ui.banChamps();
	banned = _ui.getInput();

	for (int i = 0; i < bannedChamps.size(); i++){ //checks that the champion hasn't been banned already.
		if (bannedChamps[i] == banned){
			cout << "Champion already banned. Pick a different champ: ";
			banned.clear;
			cin >> banned;
		}

		bannedChamps[i] = banned;
		i++;
	}
}


void Draft::banChamps(){
	string banned = "";
	if (_compFirst = false){
		_ui.banChamps();
		banned = _ui.getInput();

		for (int i = 0; i < 6; i++){ //checks that the champion hasn't been banned already.
			if (bannedChamps[i] == banned){
				cout << "Champion already banned. Pick a different champ: ";
				banned.clear;
				cin >> banned;
			}

		}
		bannedChamps[i] = banned;
		i++;
	}
	if (_compFirst = true){
		//pick a random champ out of the champs vector?
		//bannedChamps[i] = banned;
		//i++;

		;
	}




}

void Draft::pickChamps(){
	int c = 0;
	int i = 0;
	string picked = "";
	if (_compFirst = false){ //checks to see if it is the computer picking
		cout << "Enter a champion to pick: ";
		cin >> picked;
		for (int i = 0; i < 10; i++){ //checks to see if the champ has been picked already
			if (pickedChamps[i] == picked){
				cout << "Champion already picked. Pick a new Champ: ";
				picked.clear;
				cin >> picked;
			}
		}
		pickedChamps[i] = picked;
		c++;
	}
	if (_compFirst = true){
		//pick a random champ out of the champs vector?
		//pickedChamps[i] = banned;
		//c++;
	}

}