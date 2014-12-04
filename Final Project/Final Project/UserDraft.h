#ifndef _UserDraft_h
#define _UserDraft_h

#include <iostream>
#include <string>
#include <vector>
#include "Team.h"
#include "Draft.h"
#include "UserInput.h"
#include "ChampionSearch.h"

using namespace std;


class UserDraft : public Draft
{
public: 
	UserDraft(vector<string>, vector<Champion>);
	void pickChamps();
	void banChamps();
};


#endif