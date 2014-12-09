#ifndef _CompDraft_h
#define _CompDraft_h

#include <iostream>
#include <string>
#include <vector>
#include "Draft.h"

using namespace std;


class CompDraft : public Draft
{
public:
	CompDraft(vector<string>, vector<Champion>);
	void pickChamps();
	void banChamps();
};


#endif