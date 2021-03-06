#include "ChampionSearch.h"

using namespace std;


//ChampionSearch::ChampionSearch() {} // default constructor

//uses the list of champ names because they have the same indexes as the vector of champions
ChampionSearch::ChampionSearch(vector<string> &champs) 
{
	_champs = champs;
}

ChampionSearch::~ChampionSearch(){}


// searches for the champion name that is given to the function
//int ChampionSearch::search(string &name)
//{
//	for (unsigned int i = 0; i < _champs.size(); i++)
//	{
//		if (_champs[i] == name)
//			return i; // returns the index of where the champion can be found. 
//	}
//		return -1; // to say that it was not found
//}

int ChampionSearch::search(string &name, int low, int high)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;
	if (name < _champs[mid])
		search(name, low, mid-1);
	else if (name == _champs[mid])
		return mid;
	else
		search(name, mid+1, high);
}