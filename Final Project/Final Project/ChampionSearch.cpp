#include "ChampionSearch.h"

using namespace std;


//uses the list of champ names because they have the same indexes as the vector of champions
ChampionSearch::ChampionSearch(vector<string> &champs) 
{
	_champs = champs; // sets the member _champs to 
}


// binary search through the vector of champ names
// returns the index at which the champion is found
int ChampionSearch::search(string &name, int low, int high)
{
	if (low > high)
		return -1; // returns -1 if the champion is not found

	int mid = (low + high) / 2; // sets mid to the mid point between high and low

	// checks to see whether name is left or right of _champs[mid] and calls the function again passing in the correct value
	if (name < _champs[mid])
		search(name, low, mid-1);
	else if (name == _champs[mid])
		return mid; // checks to make sure name doesn't == mid. if it does, it returns it. 
	else
		search(name, mid+1, high);
}