#ifndef _Team_h_
#define _Team_h_
#include <string>
#include "Champion.h"
using namespace std;


class Team // I don't think it would need to have inheritance with the Champion class
{
private:
	int _points;
	vector<string> _teamChampNames;

public:
	void addTeamChampNames(string&);
	int getPoints();
	vector<string> getTeamChampNames();
	void setPoints(int);
	string getChamp(int);

};


#endif