#include "CompDraft.h"

using namespace std;

CompDraft::CompDraft(vector<string> listChamps, vector<Champion> champs) : Draft(listChamps, champs)
{
	executeDraft(); // calls the execute draft method in its parent class.
}


void CompDraft::pickChamps()
{
	// executes the correct pick order for the computer draft
	compPick(7, 0); // the ints are commands on how the computer needs to pick
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
	_ui->draftOutput(); // outputs the draft grid

	// calls the correct order of the computer and user bans
	for (int i = 0; i < 3; i++){
		compBan();
		userBan();
	}
}