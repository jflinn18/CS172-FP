#ifndef _Champion_h
#define _Champion_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Champion
{
public:
	string _name;
	string _primaryRole;
	string _secondaryRole;
	vector<string> _badChamps();
	vector<string> _goodChamps();
private:
	vector<string> getBadChamps();
	vector<string> getGoodChapms();
	void setBadChamps();
	void getGoodChamps();
};

#endif