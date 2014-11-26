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



#endif