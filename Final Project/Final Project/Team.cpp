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


//not a function within a class. Operates indipendently of a class.
//our main algorythm for running a draft.
//to be called within our Main() function.
void Draft(){
	Team rTeam;
	Team bTeam;
	bTeam.comp = true;


	rTeam.setName("Red Team");
	bTeam.setName("Blue Team");

	// make into a for loop
	rTeam.banChamps();
	bTeam.banChamps();
	rTeam.banChamps();
	bTeam.banChamps();
	rTeam.banChamps();
	bTeam.banChamps();

	rTeam.c1 = rTeam.pickChamps;

	bTeam.c1 = bTeam.pickChamps;
	bTeam.c2 = bTeam.pickChamps;

	rTeam.c2 = rTeam.pickChamps;
	rTeam.c3 = rTeam.pickChamps;

	bTeam.c3 = bTeam.pickChamps;
	bTeam.c4 = bTeam.pickChamps;

	rTeam.c4 = rTeam.pickChamps;
	rTeam.c5 = rTeam.pickChamps;

	bTeam.c5 = bTeam.pickChamps;



