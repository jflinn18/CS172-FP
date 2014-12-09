#include "UserDraft.h"

using namespace std;

UserDraft::UserDraft(vector<string> listChamps, vector<Champion> champs) : Draft(listChamps, champs)
{ 
	executeDraft();
}

//UserDraft::~UserDraft()
//{
//	delete _champSearch;
//	delete _ui;
//}

void UserDraft::pickChamps()
{
	//_ui.pickChamps();

	userPick();
	compPick(0, 0);
	compPick(7, 1);
	userPick();
	userPick();
	compPick(1, 2);
	compPick(2, 3);
	userPick();
	userPick();
	compPick(3, 4);
}

void UserDraft::banChamps()
{
	_ui->draftOutput();
	//_ui.banChamps();
	for (int i = 0; i < 3; i++){
		userBan();
		compBan();
	}
}