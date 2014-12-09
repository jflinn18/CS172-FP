#include "Draft.h"


//our constructor. creates a draft
Draft::Draft(vector<string> listchamps, vector<Champion> champs)
{
	_ui = NULL;				//initializing pointers
	_champSearch = NULL;

	srand(time(NULL));
	_listChampNames = listchamps;
	_champs = champs;
	_champSearch = new ChampionSearch(listchamps);		
	_ui = new UserInput(_listChampNames, _champs);

	compPositions = { "Top", "Adc", "Support", "Mid", "Jungle" };


}
// our draft deconstructor
Draft::~Draft()
{
	if (_champSearch == NULL)
		delete _champSearch;
	if (_ui == NULL)
		delete _ui;
}

// these functions update our banned and picked vectors
void Draft::addpickedChamps(string &champ) { pickedChamps.push_back(champ); }
void Draft::addbannedChamps(string &champ) { bannedChamps.push_back(champ); }

// simple get functions
vector<string> Draft::getpickedChamps() { return pickedChamps; }
vector<string> Draft::getbannedChamps() { return bannedChamps; }

//called when the computer needs to ban a champion
void Draft::compBan()
{
	int k = rand() % 121;

	string banned = "";
	banned = _listChampNames[k];

	while (!checkBan(banned)){ //checks that the champion hasn't been banned already.
		k = rand() % 121;
		banned = _listChampNames[k];
	}
	addbannedChamps(banned); // updates vectors
	_ui->updatebans(bannedChamps); //outputs to the console
}

//called when the user needs to ban a champion
void Draft::userBan()
{
	string banned = "";
	_ui->banChamps();
	banned = _ui->getInput();


	while (!checkBan(banned)){ //checks that the champion hasn't been banned already.
		_ui->checkBanned();
		banned = _ui->getInput();	
	}


	addbannedChamps(banned);	//updates our vectors
	_ui->updatebans(bannedChamps); //outputs to the console
}

//checks that the champion hasn't been banned already.
bool Draft::checkBan(string& ban){
	for (unsigned int i = 0; i < bannedChamps.size(); i++){  //searches through banned vector

		if (bannedChamps[i] == ban){
			return false;
		}
	}
	return true;
}

//checks that the champion hasn't been picked already.
bool Draft::checkPick(string& pick){
	for (unsigned int i = 0; i < pickedChamps.size(); i++){ //searches through picked vector

		if (pickedChamps[i] == pick){
			return false;
		}
	}
	return true;
}

// called when the user needs to pick a champion
void Draft::userPick(){
	string picked = "";
	_ui->pickChamps(); //prompts user to pick a champ
	picked = _ui->getInput(); //recieves user input
	

	while (!checkPick(picked) || !checkBan(picked)){ //checks that the champion hasn't been picked or banned already.
		_ui->checkPicked();
		picked = _ui->getInput();	
	}

	addpickedChamps(picked); //updates vectors
	_user.addTeamChampNames(picked); //updates vectors
	_ui->updatepicks(_user.getTeamChampNames(), _computer.getTeamChampNames()); //displays current champion picks/bans
}

//called when the computer needs to ban a champion
void Draft::compPick(int i, int j){
	int k = rand() % 121;

	string picked = "";
	picked = compChampPick(i, j, picked); //calls the picking function.
	
	while (!checkPick(picked) || !checkBan(picked)){ //checks that the champion hasn't been picked already.
		picked = compChampPick(i, j, picked);
	}

	addpickedChamps(picked); //updates vectors
	_computer.addTeamChampNames(picked);//updates vectors
	_ui->updatepicks(_user.getTeamChampNames(), _computer.getTeamChampNames()); //displays current champion picks/bans
}

// called when the computer needs to ban a champion
string Draft::compChampPick(int& counter, int& pos, string picked)
{
	Champion champIn;
	Champion champOut;

	vector<string> positions;

	if (counter < 4) //searches for a champion that counters the user's champion
	{
		int index = _champSearch->search(_user.getChamp(counter), 0, _champs.size()); //returns number of champion counters

		champIn = _champs[index];

		for (int i = 0; i < champIn.getGoodCounter().size() - 1; i++)//checks that the counter fulfills the required position
		{
			index = _champSearch->search(champIn.getGoodChamp(i), 0, _champs.size());
			champOut = _champs[index];

			positions = champOut.getPositions();

			for (int j = 0; j < positions.size() - 1; j++)
			{
				if (positions[j] == compPositions[pos] && !checkPick(picked) || !checkBan(picked))// checks for bans/picks
					return champOut.getName();
			}
		}
	}

	int r = rand() % 121;

	for (;;) //infinite loop that will keep looking for a new champion until the required position is filled.
	{
		r = rand() % 121;
		champOut = _champs[r];

		positions = champOut.getPositions();

		for (int j = 0; j < positions.size() - 1; j++)
		{
			if (positions[j] == compPositions[pos])
				return champOut.getName();
		}
	}

	return _listChampNames[r];
}

//initiates a draft
void Draft::executeDraft(){
	banChamps();
	pickChamps();
	score();
}

// decides the  score and winners
void Draft::score(){
	Champion temp;
	int index;

	for (unsigned int i = 0; i < _user.getTeamChampNames().size(); i++) // for each of the user's champions
	{
		for (unsigned int j = 0; j < _computer.getTeamChampNames().size(); j++) //go through each of the computer's champions
		{
			index = _champSearch->search(_computer.getChamp(j), 0, _champs.size());

			temp = _champs[index];
			for (unsigned int k = 0; k < temp.getGoodCounter().size(); k++)//and find out if they are a good counter for that champion
			{
				if (_user.getChamp(j) == temp.getGoodChamp(k))
				{
					_user.setPoints(); //updates score if it is a good counter
				}
			}
		}
	}


	for (unsigned int i = 0; i < _computer.getTeamChampNames().size(); i++) //for each of the computer's champions
	{
		for (unsigned int j = 0; j < _user.getTeamChampNames().size(); j++)//go through each of the user's champions
		{
			index = _champSearch->search(_user.getChamp(j), 0, _champs.size());

			temp = _champs[index];
			for (unsigned int k = 0; k < temp.getGoodCounter().size(); k++)// and find out if they are a good counter for that champion.
			{
				if (_computer.getChamp(j) == temp.getGoodChamp(k))
				{
					_computer.setPoints(); //updates score if it is a good counter
				}
			}
		}
	}

	_ui->outputTeamPoints(_user, _computer); //returns the results
}