#include "UserDraft.h"

using namespace std;

UserDraft::UserDraft(vector<string> listChamps, vector<Champion> champs) : Draft(listChamps, champs)
{ 
	executeDraft();
}

void UserDraft::pickChamps()
{
	//_ui.pickChamps();

	userPick();
	compPick(0);
	compPick(7);
	userPick();
	userPick();
	compPick(1);
	compPick(2);
	userPick();
	userPick();
	compPick(3);
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