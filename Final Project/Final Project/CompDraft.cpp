#include "CompDraft.h"

using namespace std;

CompDraft::CompDraft(vector<string> listChamps, vector<Champion> champs) : Draft(listChamps, champs)
{
	executeDraft();
}

void CompDraft::pickChamps()
{
	compPick(7);
	userPick();
	userPick();
	compPick(0);
	compPick(1);
	userPick();
	userPick();
	compPick(2);
	compPick(3);
	userPick();
}

void CompDraft::banChamps()
{
	_ui.draftOutput();
	for (int i = 0; i < 3; i++){
		compBan();
		userBan();
	}
}