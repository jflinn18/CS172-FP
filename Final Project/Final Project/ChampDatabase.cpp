#include "ChampDatabase.h"

using namespace std;



ChampDatabase::ChampDatabase()
{
	_cd = NULL;
	_ud = NULL;
	_ui = NULL;

	// calls the function that will go through a draft.
	createChampList(); // calls the function that creates the list of names for the champion

	//setChampSearch();
	//_champSearch = new ChampionSearch(_listOfChampNames);

	createChamps(); // call the funtion that creates the vector of champion objects

	_ui = new UserInput(_listOfChampNames, _champs);
	completeADraft();
	
}

ChampDatabase::~ChampDatabase()
{
	if (_cd == NULL)
		delete _cd;
	if (_ud == NULL)
		delete _ud;
	if (_ui == NULL)
		delete _ui;
}


// this function completes one iteration of a draft. 
void ChampDatabase::completeADraft()
{
	string resp = _ui->whatDraft();

	allocateDraft(resp);
}


void ChampDatabase::allocateDraft(string& resp)
{
	if (resp == "Computer Draft" || resp == "computer draft")
		_cd = new CompDraft(_listOfChampNames, _champs);
	else if (resp == "User Draft" || resp == "user draft")
		_ud = new UserDraft(_listOfChampNames, _champs);
	else
		_ui->draftInputError();
}



// gets a name from the list of champ names and opens the corresponding .txt file and creates a champion object from 
//   that data. It then stores that data into the vector of champions.
void ChampDatabase::addChamp(string &champName)
{
	Champion c;  // creates a new Champion object to make
	fstream filein;
	string s = "empty";

	c.setName(champName); // sets the name of the champion

	filein.open("Champions//" + champName + ".txt", ios::in); // opens the corresponding champion file

	if (filein.fail()) 
	{
		cout << "Can't find " << champName << ".txt " << endl; // tells the user that the programs couldn't find a certain champ .txt file
		exit(0); // ends the program
	}

	while (!filein.fail()) // reads in all of the data from the file
	{

		while(!(s == "")) // reads and adds data into c.goodCounters until the paragraph break

		{
			getline(filein, s);
			c.setGoodCounter(s);
		}

		s = "empty";

		while (!(s == "")) // reads and adds data into c.badCounters until the paragraph break
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
			c.setPositions(s);
		}

	}

	_champs.push_back(c);
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


// creates the vector of champion objects
void ChampDatabase::createChamps()
{
	for (unsigned int i = 0; i < _listOfChampNames.size(); i++)
		addChamp(_listOfChampNames[i]); // adds one champion object for each champion in the listOfChampNames vector
}


//void ChampDatabase::setChampSearch()
//{
//	_champSearch = new ChampionSearch(_listOfChampNames);
//}


// returns the specified champion from the vector of champions given the champion's name
//Champion ChampDatabase::getChamp(string &champ)
//{
//	// searches for the champion and returns that champion
//	return _champs[_champSearch->search(champ)];
//}

vector<Champion> ChampDatabase::getChamps() { return _champs; }
vector<string> ChampDatabase::getList() { return _listOfChampNames; }