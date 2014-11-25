#include <iostream>
#include <string>
#include <vector>
#include "Champion.h"

using namespace std;


vector<string> Champion::getBadCounter() { return _badCounter; } // returns a list of champions that are bad counters
vector<string> Champion::getGoodCounter(){ return _goodCounter; } // returns a list of champions that are good counters
string Champion::getPrimaryRole() { return _primaryRole; } // returns the primary role 
string Champion::getSecondaryRole() { return _secondaryRole; } // returns the secondary role
string Champion::getName() { return _name; } // returns the name of the champion



void Champion::setBadCounter(string champ) { _badCounter.push_back(champ); } // adds a champion to the list of bad counters
void Champion::setGoodCounter(string champ) { _goodCounter.push_back(champ); } // adds a champion to the list of good counters
void Champion::setPrimaryRole(string pr) { _primaryRole = pr; } // sets the primary role
void Champion::setSecondaryRole(string sr) { _secondaryRole = sr; } // sets the secondary role
void Champion::setName(string name) { _name = name; } // sets the name