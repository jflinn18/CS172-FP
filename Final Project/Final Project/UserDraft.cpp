#include "UserDraft.h"

using namespace std;
//creates a draft in which the user gets the first pick
UserDraft::UserDraft(vector<string> listChamps, vector<Champion> champs) : Draft(listChamps, champs)
{ 
	executeDraft();
}

//starts picking champions, with the user first
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
//starts banning champions, with the user banning first
void UserDraft::banChamps()
{
	_ui->draftOutput();
	//_ui.banChamps();
	for (int i = 0; i < 3; i++){
		userBan();
		compBan();
	}
}