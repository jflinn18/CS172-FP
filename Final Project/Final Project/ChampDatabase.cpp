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
	// calls the function that will go through a draft.
	completeADraft();
}

// gets a name from the list of champ names and opens the corresponding .txt file and creates a champion object from 
//   that data. It then stores that data into the vector of champions.
void ChampDatabase::addChamp(string &champName)
{
	Champion c;  // creates a new Champion object to make
	fstream filein;
	string s;

	c.setName(champName); // sets the name of the champion

	filein.open(champName + ".txt"); // opens the corresponding champion file

	if (filein.fail()) 
	{
		cout << "Can't find " << champName << ".txt " << endl; // tells the user that the programs couldn't find a certain champ .txt file
		exit(0); // ends the program
	}

	while (!filein.fail()) // reads in all of the data from the file
	{
		while(!(s == "\n")) // reads and adds data into c.goodCounters until the paragraph break
		{
			getline(filein, s);
			c.setGoodCounter(s);
		}

		while (!(s == "\n")) // reads and adds data into c.badCounters until the paragraph break
		{
			getline(filein, s);
			c.setBadCounter(s);
		}

		getline(filein, s); // gets the primary role of the champion and adds it to the champion object
		c.setPrimaryRole(s);

		getline(filein, s);
		c.setSecondaryRole(s); // gets the secondary role of the champion and adds it to the champion object

		getline(filein, s); // clears the \n character in between the roles and the positions in the file

		while (!filein.fail()) // reads and adds data into c.positions until the paragraph break
		{
			getline(filein, s);
			c.setPositions(s);S
		}
	}



	_champs.push_back(c);
}


// returns the specified champion from the vector of champions given the champion's name
Champion ChampDatabase::getChamp(string &champ)
{
	// searches for the champion and returns that champion
	return _champs[champSearch.search(champ)];
}

// this function completes one interation of a draft. 
void ChampDatabase::completeADraft()
{
	/*Draft d;

	d();*/
}


// this gets the list of champions from a .txt file and stores it into a vector
void ChampDatabase::createChampList()
{
	fstream readin; // creates a new filestream

	readin.open("ListChampNames.txt"); // opens the file containing the list of Champion names

	if (readin.fail())
	{
		cout << "Can't find text file containing the list of Champion names. " << endl; // tells the user that it can't find the spcified file
		exit(0);
	}

	string s; 

	// fills the vector of champion names
	while (!readin.fail())
	{
		readin >> s;
		_listOfChampNames.push_back(s);
	}
}