#include "ChampionSearch.h"

using namespace std;


ChampionSearch::ChampionSearch() {} // default constructor

//uses the list of champ names because they have the same indexes as the vector of champions
ChampionSearch::ChampionSearch(vector<string> &champs) 
{
	_champs = champs;
}


// searches for the champion name that is given to the function
int ChampionSearch::search(string &name)
{
	for (int i = 0; i < _champs.size(); i++)
	{
		if (_champs[0] == name)
			return i; // returns the index of where the champion can be found. 
		else
			return -1; // to say that it was not found
	}
}