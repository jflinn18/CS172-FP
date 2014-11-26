#ifndef _Team_h_
#define _Team_h_

#include <string>
#include <vector>
#include "Champion.h"
using namespace std;


class Team : public Champion{ // I don't think we need to inherit the champion object (Joseph)

public:

	vector<string> bannedChamps(6); /* instead of allocating the number here, once someone bans a champion just call 
									"bannedChamps.push_back(champion_name)" to add it to the vector  (Joseph) */
	vector<string> pickedChamps(10);
	int i = 0;
	// there was another variable here that I can't remember.....(Joseph)

	// These red squigglies can be fixed by not declaring how big these vectors are. 
	// Then you use a constructor for the Team class and create a temp vector of the correct size and allocate the above vectors to the temp vectors. 
	// See UserInput.h and the constructor in UserInput.cpp (Joseph)

	string name;
	bool comp = false;
	Champion c1;
	Champion c2;
	Champion c3;
	Champion c4;
	Champion c5;



	int score(); //need to develope scoring techniques
	string getName(); //done
	void setName(string); // done




	void banChamps();
	void pickChamps();
	void outputChamp();
	void outputTeamPoints();
	void outputWinner();
	string getInput();

	void clearWindow();





};



#endif