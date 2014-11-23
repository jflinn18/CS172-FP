#ifndef _Champion_h
#define _Champion_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Champion
{
private:
	string _name;
	string _primaryRole;
	string _secondaryRole;
	vector<string> _badCounter;
	vector<string> _goodCounter;

public:
	vector<string> getBadCounter();
	vector<string> getGoodCounter();
	string getPrimaryRole();
	string getSecondaryRole();
	string getName();
	
	void setBadCounter(string);
	void setGoodCounter(string);
	void setPrimaryRole(string);
	void setSecondaryRole(string);
	void setName(string);
};

#endif