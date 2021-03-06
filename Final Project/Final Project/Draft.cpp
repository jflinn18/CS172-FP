#include "Draft.h"



Draft::Draft(vector<string> listchamps, vector<Champion> champs)
{
	_ui = NULL;
	_champSearch = NULL;

	srand(time(NULL));
	_listChampNames = listchamps;
	_champs = champs;
	_champSearch = new ChampionSearch(listchamps);
	_ui = new UserInput(_listChampNames, _champs);

	compPositions = { "Top", "Adc", "Support", "Mid", "Jungle" };


}

Draft::~Draft()
{
	if (_champSearch == NULL)
		delete _champSearch;
	if (_ui == NULL)
		delete _ui;
}


void Draft::addpickedChamps(string &champ) { pickedChamps.push_back(champ); }
void Draft::addbannedChamps(string &champ) { bannedChamps.push_back(champ); }
vector<string> Draft::getpickedChamps() { return pickedChamps; }
vector<string> Draft::getbannedChamps() { return bannedChamps; }


void Draft::compBan()
{
	int k = rand() % 121;

	string banned = "";
	banned = _listChampNames[k];

	while (!checkBan(banned)){ //checks that the champion hasn't been banned already.
		k = rand() % 121;
		banned = _listChampNames[k];
	}
	addbannedChamps(banned);
	_ui->updatebans(bannedChamps);
}

void Draft::userBan()
{
	string banned = "";
	_ui->banChamps();
	banned = _ui->getInput();


	while (!checkBan(banned)){ //checks that the champion hasn't been banned already.
		_ui->checkBanned();
		banned = _ui->getInput();	//check again????
	}


	addbannedChamps(banned);
	_ui->updatebans(bannedChamps);
}

bool Draft::checkBan(string& ban){
	for (unsigned int i = 0; i < bannedChamps.size(); i++){ //checks that the champion hasn't been banned already.

		if (bannedChamps[i] == ban){
			return false;
		}
	}
	return true;
}

bool Draft::checkPick(string& pick){
	for (unsigned int i = 0; i < pickedChamps.size(); i++){ //checks that the champion hasn't been picked already.

		if (pickedChamps[i] == pick){
			return false;
		}
	}
	return true;
}


void Draft::userPick(){
	string picked = "";
	_ui->pickChamps();
	picked = _ui->getInput();
	

	while (!checkPick(picked) || !checkBan(picked)){ //checks that the champion hasn't been picked or banned already.
		_ui->checkPicked();
		picked = _ui->getInput();	//check again????
	}

	addpickedChamps(picked);
	_user.addTeamChampNames(picked);
	_ui->updatepicks(_user.getTeamChampNames(), _computer.getTeamChampNames());
}


void Draft::compPick(int i, int j){
	int k = rand() % 121;

	string picked = "";
	picked = compChampPick(i, j, picked);
	//picked = _listChampNames[k];


	while (!checkPick(picked) || !checkBan(picked)){ //checks that the champion hasn't been picked already.
		picked = compChampPick(i, j, picked);
	}

	addpickedChamps(picked);
	_computer.addTeamChampNames(picked);
	_ui->updatepicks(_user.getTeamChampNames(), _computer.getTeamChampNames());
}


string Draft::compChampPick(int& counter, int& pos, string picked)
{
	Champion champIn;
	Champion champOut;

	vector<string> positions;

	if (counter < 4)
	{
		int index = _champSearch->search(_user.getChamp(counter), 0, _champs.size());

		champIn = _champs[index];

		for (int i = 0; i < champIn.getGoodCounter().size() - 1; i++)
		{
			index = _champSearch->search(champIn.getGoodChamp(i), 0, _champs.size());
			champOut = _champs[index];

			positions = champOut.getPositions();

			for (int j = 0; j < positions.size() - 1; j++)
			{
				if (positions[j] == compPositions[pos] && !checkPick(picked) || !checkBan(picked))
					return champOut.getName();
			}
		}
	}

	int r = rand() % 121;

	for (;;)
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


void Draft::executeDraft(){
	banChamps();
	pickChamps();
	score();
}


void Draft::score(){
	Champion temp;
	int index;

	for (unsigned int i = 0; i < _user.getTeamChampNames().size(); i++)
	{
		for (unsigned int j = 0; j < _computer.getTeamChampNames().size(); j++)
		{
			index = _champSearch->search(_computer.getChamp(j), 0, _champs.size());

			temp = _champs[index];
			for (unsigned int k = 0; k < temp.getGoodCounter().size(); k++)
			{
				if (_user.getChamp(j) == temp.getGoodChamp(k))
				{
					_user.setPoints();
				}
			}
		}
	}


	for (unsigned int i = 0; i < _computer.getTeamChampNames().size(); i++)
	{
		for (unsigned int j = 0; j < _user.getTeamChampNames().size(); j++)
		{
			index = _champSearch->search(_user.getChamp(j), 0, _champs.size());

			temp = _champs[index];
			for (unsigned int k = 0; k < temp.getGoodCounter().size(); k++)
			{
				if (_computer.getChamp(j) == temp.getGoodChamp(k))
				{
					_computer.setPoints();
				}
			}
		}
	}

	_ui->outputTeamPoints(_user, _computer);
}