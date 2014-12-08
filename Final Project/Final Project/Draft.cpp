#include "Draft.h"



Draft::Draft(vector<string> listchamps, vector<Champion> champs)
{
	srand(time(NULL));
	_listChampNames = listchamps;
	_champs = champs;
	_champSearch = new ChampionSearch(listchamps);

}

Draft::~Draft()
{
	delete _champSearch;
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
	_ui.updatebans(bannedChamps);
}

void Draft::userBan()
{
	string banned = "";
	_ui.banChamps();
	banned = _ui.getInput();


	while (!checkBan(banned)){ //checks that the champion hasn't been banned already.
		_ui.checkBanned();
		banned = _ui.getInput();	//check again????
	}


	addbannedChamps(banned);
	_ui.updatebans(bannedChamps);
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
	_ui.pickChamps();
	picked = _ui.getInput();
	

	while (!checkPick(picked) || !checkBan(picked)){ //checks that the champion hasn't been picked or banned already.
		_ui.checkPicked();
		picked = _ui.getInput();	//check again????
	}

	addpickedChamps(picked);
	_user.addTeamChampNames(picked);
	_ui.updatepicks(_user.getTeamChampNames(), _computer.getTeamChampNames());
}


void Draft::compPick(int i){
	int k = rand() % 121;

	string picked = "";
	picked = compChampPick(i);
	//picked = _listChampNames[k];


	while (!checkPick(picked) || !checkBan(picked)){ //checks that the champion hasn't been picked already.
		picked = compChampPick(i);
	}

	addpickedChamps(picked);
	_computer.addTeamChampNames(picked);
	_ui.updatepicks(_user.getTeamChampNames(), _computer.getTeamChampNames());
}


string Draft::compChampPick(int& i)
{
	Champion c;

	if (i < 4)
	{
		int index = _champSearch->search(_user.getChamp(i));

		c = _champs[index];

		int r = rand() % ( c.getGoodCounter().size() - 1 );

		return c.getGoodChamp(r);
		// check if they have been picked or banned???
	}
	else
	{
		int r = rand() % 121;
		return _listChampNames[r];
	}
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
			index = _champSearch->search(_computer.getChamp(j));

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
			index = _champSearch->search(_user.getChamp(j));

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

	_ui.outputTeamPoints(_user, _computer);
}