#include "CompDraft.h"

using namespace std;

CompDraft::CompDraft(vector<string> listChamps, vector<Champion> champs) : Draft(listChamps, champs)
{
	executeDraft();
}

//CompDraft::~CompDraft()
//{
//	delete _champSearch;
//	delete _ui;
//}

void CompDraft::pickChamps()
{
	compPick(7, 0);
	userPick();
	userPick();
	compPick(0, 1);
	compPick(1, 2);
	userPick();
	userPick();
	compPick(2, 3);
	compPick(3, 4);
	userPick();
}

void CompDraft::banChamps()
{
	_ui->draftOutput();
	for (int i = 0; i < 3; i++){
		compBan();
		userBan();
	}
}