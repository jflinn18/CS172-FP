#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ChampDatabase.h"
#include "Champion.h"
#include "ChampionSearch.h"

using namespace std;



ChampDatabase::ChampDatabase()
{
	completeADraft();
}

// gets a name from the list of champ names and opens the corresponding .txt file and creates a champion object from 
//   that data. It then stores that data into the vector of champions.
void ChampDatabase::addChamp(string champName)
{
	Champion c; 
	fstream filein;

	_champs.push_back(c);
}


// returns the specified champion from the vector of champions
Champion ChampDatabase::getChamp(Champion champ)
{

}

// this function completes one interation of a draft. 
void ChampDatabase::completeADraft()
{

}


// this gets the list of champions from a .txt file and stores it into a vector
void ChampDatabase::createChampList()
{

}