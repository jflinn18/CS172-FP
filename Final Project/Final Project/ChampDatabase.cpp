#include "ChampDatabase.h"

using namespace std;



ChampDatabase::ChampDatabase()
{
	// sets all of our pointers in ChampDatabase to NULL
	_cd = NULL;
	_ud = NULL;
	_ui = NULL;

	// calls the function that will go through a draft.
	createChampList(); // calls the function that creates the list of names for the champion


	createChamps(); // call the funtion that creates the vector of champion objects

	_ui = new UserInput(_listOfChampNames, _champs); // allocates a new pointer object
	completeADraft(); // function call that handles completeing a draft
}

//Deletes the pointers that we were using.
ChampDatabase::~ChampDatabase()
{
	// checks to see if we were using any of the pointers. Deletes them if we were.
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
	string resp = _ui->whatDraft(); // asks what draft

	allocateDraft(resp); // creates a draft object to the user's specification
}


// checks to see what draft the user wants and allocates that draft
void ChampDatabase::allocateDraft(string& resp)
{
	if (resp == "Computer Draft" || resp == "computer draft") // checks to see if the user wants a computer draft
		_cd = new CompDraft(_listOfChampNames, _champs);
	else if (resp == "User Draft" || resp == "user draft") // checks to see if the user wants a user draft
		_ud = new UserDraft(_listOfChampNames, _champs);
	else
		_ui->draftInputError(); // returns an error if the user doesn't pick one of the above drafts
}



// gets a name from the list of champ names and opens the corresponding .txt file and creates a champion object from 
//   that data. It then stores that data into the vector of champions.
void ChampDatabase::addChamp(string &champName)
{
	Champion c;  // creates a new Champion object to make
	fstream filein;
	string s = "empty"; // sets string to "empty" because of some input issues we were having when we set it to ""

	c.setName(champName); // sets the name of the champion

	filein.open("Champions//" + champName + ".txt", ios::in); // opens the corresponding champion file

	if (filein.fail()) 
	{
		cout << "Can't find " << champName << ".txt " << endl; // tells the user that the programs couldn't find a certain champ .txt file
		exit(0); // ends the program
	}

	while (!filein.fail()) // reads in all of the data from the file
	{
		getline(filein, s); // set it up this way so that there isn't an empty string in any of the vectors
		while(!(s == "")) // reads and adds data into c.goodCounters until the paragraph break ("")

		{
			c.setGoodCounter(s);
			getline(filein, s);
		}

		s = "empty"; // so that s will not == "". If we didn't do this, it would skip this next while loop

		getline(filein, s);
		while (!(s == "")) // reads and adds data into c.badCounters until the paragraph break
		{
			c.setBadCounter(s);
			getline(filein, s);
		}

		getline(filein, s); // gets the primary role of the champion and adds it to the champion object
		c.setPrimaryRole(s);

		getline(filein, s);
		c.setSecondaryRole(s); // gets the secondary role of the champion and adds it to the champion object

		getline(filein, s); // clears the \n character in between the roles and the positions in the file

		getline(filein, s);
		while (!filein.fail()) // reads and adds data into c.positions until the paragraph break
		{
			c.setPositions(s);
			getline(filein, s);
		}

	}

	_champs.push_back(c); // adds Champion c to the vector of Champion Objects
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
	readin >> s;

	// fills the vector of champion names
	while (!readin.fail())
	{
		_listOfChampNames.push_back(s); // adds the string to the vector of strings that hold all of the champ names
		readin >> s;
	}
}


// creates the vector of champion objects
void ChampDatabase::createChamps()
{
	for (unsigned int i = 0; i < _listOfChampNames.size(); i++)
		addChamp(_listOfChampNames[i]); // adds one champion object for each champion in the listOfChampNames vector
}


vector<Champion> ChampDatabase::getChamps() { return _champs; }
vector<string> ChampDatabase::getList() { return _listOfChampNames; }