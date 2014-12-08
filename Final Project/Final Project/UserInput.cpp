#include "UserInput.h"

using namespace std;




UserInput::UserInput()
{
	vector<vector<string>> temp(7);

	for (int i = 0; i < 7; i++)
		temp[i] = vector<string>(3);

	temp[0][0] = "User:";
	temp[0][1] = "Banned:";
	temp[0][2] = "Computer:";

	for (int i = 1; i < 7; i++) // each row except the first
	{
		for (int j = 0; j < 3; j++) // each column
		{
			temp[i][j] = "-----------";
		}
	}

	draftOutputFormat = temp;
} 

void UserInput::checkBanned(){
	cout << "Champion already banned. Ban a different champ: \n";

}
void UserInput::checkPicked(){
	cout << "Champion already picked. Pick a different champ: \n";
}



// asks the user which type of draft they want to do
string UserInput::whatDraft()
{
	cout << "At any time, write '-help' see the different commands for this program.\n";
	cout << "Which draft would you like to do? \n";
	getInput();

	checkResp(); // checks if the user wants to do anything else than what the computer is asking

	return resp;


	

	/* example of possible input: 
			
			Computer Draft
			User Draft
			//User Draft -l


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


// updates the banned champions in the 2D vector so that we can refresh the command line with new data
void UserInput::updatebans(vector<string> bans)
{
	for (unsigned int i = 0; i < bans.size(); i++) // this reads in the banned champions from the vector that was passed in
		draftOutputFormat[i + 1][1] = bans[i]; // i+1 becasue we want to keep the data in the first row of the vector. 
	
	draftOutput();
}


// updates the picked champions in the 2D vector so that we can refresh the command line with new data
void UserInput::updatepicks(vector<string> user, vector<string> computer)
{
	for (unsigned int i = 0; i < user.size(); i++)
		draftOutputFormat[i + 1][0] = user[i]; // updates the user column in the 2D vector

	draftOutput();

	for (unsigned int j = 0; j < computer.size(); j++)
		draftOutputFormat[j + 1][2] = computer[j]; // updates the computer column in the 2D vector

	draftOutput();
}


// This outputs all of the Data in that specific champion object
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
		for (unsigned int i = 0; i < bad.size(); i++)
		{
			if (i > good.size())
				cout << setw(30) << bad[i] << endl; // formats output
			else
				cout << setw(30) << bad[i] << setw(30) << good[i] << endl; // formats output
		}
	}
	else if (bad.size() < good.size()) // conditional to make sure you won't run outside of the vector
	{
		for (unsigned int i = 0; i > good.size(); i++)
		{
			if (i > bad.size())
				cout << setw(60) << good[i] << endl; // formats output
			else
				cout << setw(30) << bad[i] << setw(30) << good[i] << endl; // formats output
		}
	}
	else
	{
		for (unsigned int i = 0; i < bad.size(); i++)
			cout << setw(30) << bad[i] << setw(30) << good[i]; // formats output
	}


	cout << "\nPrimary Role: " << c.getPrimaryRole() << endl; // prints out the primary role of the champion

	if (!(c.getSecondaryRole() == "na"))
		cout << "Secondary Role: " << c.getSecondaryRole() << endl; // prints out the secondary role of the champion if it has one

	cout << endl; // asthetics

	for (unsigned int i = 0; i < pos.size(); i++)
		cout << pos[i] << endl; // prints out the positions of the champion
}


//void UserInput::outputChamp(string &name)
//{
//	vector<string> bad; // makes a vector to copy data into from c
//	vector<string> good; // makes a vector to copy data into from c
//	vector<string> pos; // makes a vector to copy data into from c
//
//	bad = c.getBadCounter(); // copies data from c
//	good = c.getGoodCounter(); // copies data from c
//	pos = c.getPositions(); // copies data from c
//
//	cout << setw(30) << "Bad counters: " << setw(30) << "Good counters: " << endl;
//
//
//	if (bad.size() > good.size()) // conditional to make sure you won't run outside of the vector
//	{
//		for (unsigned int i = 0; i < bad.size(); i++)
//		{
//			if (i > good.size())
//				cout << setw(30) << bad[i] << endl; // formats output
//			else
//				cout << setw(30) << bad[i] << setw(30) << good[i] << endl; // formats output
//		}
//	}
//	else if (bad.size() < good.size()) // conditional to make sure you won't run outside of the vector
//	{
//		for (unsigned int i = 0; i > good.size(); i++)
//		{
//			if (i > bad.size())
//				cout << setw(60) << good[i] << endl; // formats output
//			else
//				cout << setw(30) << bad[i] << setw(30) << good[i] << endl; // formats output
//		}
//	}
//	else
//	{
//		for (unsigned int i = 0; i < bad.size(); i++)
//			cout << setw(30) << bad[i] << setw(30) << good[i]; // formats output
//	}
//
//
//	cout << "\nPrimary Role: " << c.getPrimaryRole() << endl; // prints out the primary role of the champion
//
//	if (!(c.getSecondaryRole() == "na"))
//		cout << "Secondary Role: " << c.getSecondaryRole() << endl; // prints out the secondary role of the champion if it has one
//
//	cout << endl; // asthetics
//
//	for (unsigned int i = 0; i < pos.size(); i++)
//		cout << pos[i] << endl; // prints out the positions of the champion
//}



// this provides a chart like interface for the draft to keep track of what has been banned and what has been picked. 
void UserInput::draftOutput()
{
	/*
	User:		      Banned:            Computer:
	Kha'zix		      Lee_Sin            Rengar
	Kennen			  Master_Yi          -----------
	--------		  Alistar            -----------
	--------		  Yasuo              -----------
	--------		  Ashe               -----------
	*/

	clearWindow();

	// prints out the 2D vector
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 3; j++) // print the first row
		{
			cout << setw(15) << draftOutputFormat[i][j];
		}
		cout << endl;
	}
}


void UserInput::outputTeamPoints(Team user, Team computer)
{
	cout << "User's team points: " << user.getPoints() << endl;;  // prints the team points for user
	cout << "Computer's team points: " << computer.getPoints() << endl; // prints the team points for the computer

	outputWinner(user.getPoints(), computer.getPoints());
}


void UserInput::outputWinner(int user, int computer)
{
	if (user > computer)
		cout << "Good job! Your team has the pick advantage\n"; // the user's team has the advantage.
	else if (user == computer)
		cout << "It's a tie. It comes down to skill.\n";
	else
	{
		cout << "I'm sorry, the other team has the pick advantage.\n"; // the computer's team has the advantage.
		cout << "But don't worry, your team may still win.\n";
	}

}


// gets any of the input in the whole program
string UserInput::getInput()
{
	cout << ">>: "; 
	getline(cin, resp);

	checkResp();

	return resp;
}


void UserInput::clearWindow()
{
	system("cls");
}


void UserInput::printMan()
{
	cout << "\n\nThere are two types of drafts:\n" << endl;
	cout << "Computer Draft - where the computer generates good champion counters.\n <Computer Draft> / <computer draft>\n\n";
	cout << "User Draft - where the user picks the counters.\n <User Draft> / <user draft>\n\n\n";

	cout << "-x: \n\t Exits the program" << endl;

	cout << endl;

	cout << "-man: \n\t Shows the user manual" << endl;

	cout << endl;

	cout << "-q to exit\n";

	//cout << "-l: \n\t Used after the type of draft to choose the learning draft" << endl;
	//cout << "\t<type_of_draft> <-l>" << endl;

	getInput();
	checkResp();
	getInput();
}

// checks to make sure that the user doesn't want something that the computer isn't asking for. 
void UserInput::checkResp()
{
	if (resp == "-x")
		exit(0);
	
	if (resp == "-help")
		printMan();

	if (resp == "-q")
		clearWindow();

	//if (resp.find("-s") < resp.size())
	//	outputChamp(resp.replace(resp.size()-2, ""));


	//getInput();
}


vector<vector<string>> UserInput::getDraftOutputFormat()
{
	return draftOutputFormat;
}

void UserInput::draftInputError() { cout << "You have not selected a draft.\n"; }