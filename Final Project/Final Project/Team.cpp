#include "Team.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;



void Team::setName(string s){
	name = s;

}

string Team::getName(){
	return name;
}


void Team::banChamps(){
	string banned = "";
	if (comp = false){
		cout << "Enter a champion to ban: ";
		cin >> banned;
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
	if (comp = true){
		//pick a random champ out of the champs vector?
		//bannedChamps[i] = banned;
		//i++;

		;
	}




}

void Team::pickChamps(){
	string picked = "";
	if (comp = false){ //checks to see if it is the computer picking
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
	if (comp = true){
		//pick a random champ out of the champs vector?
		//pickedChamps[i] = banned;
		//c++;
	}

}


//not a function within a class. Operates indipendently of a class.
//our main algorythm for running a draft.
//to be called within our Main() function. 11/22

//ran into an error calling this from main(). might need to 
//define it within the same source page as main() 11/25
void Draft(){
	Team rTeam;
	Team bTeam;
	bTeam.comp = true;


	rTeam.setName("Red Team");
	bTeam.setName("Blue Team");

	rTeam.banChamps(); //turn into loop
	bTeam.banChamps();
	rTeam.banChamps();
	bTeam.banChamps();
	rTeam.banChamps();
	bTeam.banChamps();

	rTeam.c1 = rTeam.pickChamps();

	bTeam.c1 = bTeam.pickChamps;
	bTeam.c2 = bTeam.pickChamps;

	rTeam.c2 = rTeam.pickChamps;
	rTeam.c3 = rTeam.pickChamps;

	bTeam.c3 = bTeam.pickChamps;
	bTeam.c4 = bTeam.pickChamps;

	rTeam.c4 = rTeam.pickChamps;
	rTeam.c5 = rTeam.pickChamps;

	bTeam.c5 = bTeam.pickChamps;











}