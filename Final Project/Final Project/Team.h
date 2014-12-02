#ifndef _Team_h_
#define _Team_h_
#include <string>
#include "Champion.h"
using namespace std;




class Team : public Champion{ //inherits from the champion class

public:


	vector<string> bannedChamps(6); //vector of banned champs.
	vector<string> pickedChamps(10); //vector of picked champs.
	
	// Instead of allocating the number here, once someone bans a champion just call
	// "bannedChamps.push_back(champion_name)" to add it to the vector  (Joseph)

	int i = 0;
	int c = 0;


	string name;
	bool comp = false;
	Champion c1, c2, c3, c4, c5;


	int score(); //need to develope scoring techniques
	string getName(); //done
	void setName(string); // done




	void banChamps();// needs comp bann 
	void pickChamps();// needs comp pick
	void outputChamp();
	void outputTeamPoints();
	void outputWinner();
	string getInput();

	void clearWindow();





};

class Team // I don't think it would need to have inheritance with the Champion class
{
private:
	int points;
	vector<string> teamChampNames;

public:
	void addTeamChampNames(string);
	/*
	This would "push_back" the teamChampNames with whatever the function's
	parameter is.
	*/

	int getPoints();
	/*
	This would return the points member.
	*/

	vector<string> getTeamChampNames();
	/*
	This would return the whole vector of champ names that that team has.
	*/

	void setPoints();
	/*
	This could also be an "addPoints()" function that adds 1 to whatever points is
	when this function is called.
	*/
};




#endif