#ifndef _UserDraft_h
#define _UserDraft_h

#include <iostream>
#include <string>
#include <vector>
#include "Draft.h"

using namespace std;


class UserDraft : public Draft
{
public: 
	UserDraft(vector<string>, vector<Champion>);
	//~UserDraft();
	void pickChamps();
	void banChamps();
};


#endif