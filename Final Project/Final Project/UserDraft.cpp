#include "UserDraft.h"

using namespace std;

UserDraft::UserDraft(vector<string> listChamps, vector<Champion> champs): Draft(listChamps, champs){}

void UserDraft::pickChamps()
{
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
	for (int i = 0; i < 3; i++){
		userBan();
		compBan();
	}
}