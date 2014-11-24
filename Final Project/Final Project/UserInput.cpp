#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "UserInput.h"

using namespace std;


UserInput::UserInput(){} //default constructor

UserInput::UserInput(Team blue, Team red)
{
	a = red;
	b = blue;
}


// asks the user which type of draft they want to do
string UserInput::whatDraft()
{
	cout << "At any time, write '-man' see the different commands for this program.\n" << endl;
	cout << "What type of draft would you like to do? ";
	getInput();

	checkResp(); // checks if the user wants to do anything else than what the computer is asking

	// maybe include a conditional for an option for the "learning" type of draft
	

	/* example of possible input: 
			
			Computer Draft
			User Draft
			User Draft -l


	*/
}


// asks the user what champions they want to ban
void UserInput::banChamps()
{
	cout << "Ban a Champ" << endl;
}


// asks the user for the champion picks
void UserInput::pickChamps()
{
	cout << "Pick a Champ" << endl;
}


void UserInput::outputChamp(Champion c)
{
	vector<string> bad; // makes a vector to copy data into from c
	vector<string> good; // makes a vector to copy data into from c
	vector<string> pos; // makes a vector to copy data into from c

	bad = c.getBadCounter(); // copies data from c
	good = c.getGoodCounter(); // copies data from c
	pos = c.getPositions(); // copies data from c

	cout << setw(30) << "Bad counters: " << setw(30) << "Good counters: " << endl;


	if (bad.size() > good.size()) // conditional to make sure you won't run outside of the vector
	{
		for (int i = 0; i < bad.size(); i++)
		{
			if (i > good.size())
				cout << setw(30) << bad[i] << endl; // formats output
			else
				cout << setw(30) << bad[i] << setw(30) << good[i] << endl; // formats output
		}
	}
	else if (bad.size() < good.size()) // conditional to make sure you won't run outside of the vector
	{
		for (int i = 0; i > good.size(); i++)
		{
			if (i > bad.size())
				cout << setw(60) << good[i] << endl; // formats output
			else
				cout << setw(30) << bad[i] << setw(30) << good[i] << endl; // formats output
		}
	}
	else
	{
		for (int i = 0; i < bad.size(); i++)
			cout << setw(30) << bad[i] << setw(30) << good[i]; // formats output
	}


	cout << "\nPrimary Role: " << c.getPrimaryRole << endl; // prints out the primary role of the champion

	if (!(c.getSecondaryRole == "na"))
		cout << "Secondary Role: " << c.getSecondaryRole() << endl; // prints out the secondary role of the champion if it has one

	cout << endl; // asthetics

	for (int i = 0; i < pos.size(); i++)
		cout << pos[i] << endl; // prints out the positions of the champion
}


// this provides a chart like interface for the draft to keep track of what has been banned and what has been picked. 
void UserInput::draftOutput()
{
	/*
	Computer:		  Banned:            User:
	Kha'zix		      Lee_Sin            Rengar
	Kennen			  Master_Yi          -----------
	--------		  Alistar            -----------
	--------		  Yasuo              -----------
	--------		  Ashe               -----------
	*/
}


void UserInput::outputTeamPoints(string team)
{

}


void UserInput::outputWinner(string team)
{

}


// gets any of the input in the whole program
string UserInput::getInput()
{
	cout << ">>: "; 
	cin >> resp;

	return resp;
}


void UserInput::clearWindow()
{
	system("cls");
}


void UserInput::printMan()
{
	cout << "-x: \n\t Exits the program" << endl;

	cout << "-man: \n\t Shows the user manual" << endl;

	cout << "-l: \n\t Used after the type of draft to choose the learning draft" << endl;
	cout << "\t <type_of_draft> <-l>" << endl;
}

// checks to make sure that the user doesn't want something that the computer isn't asking for. 
void UserInput::checkResp()
{
	if (resp.find("-x") > 0)
		exit(0);
	
	if (resp.find("-man") > 0)
		printMan();
}