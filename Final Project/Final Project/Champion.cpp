#include <iostream>
#include <string>
#include <vector>
#include "Champion.h"

using namespace std;


vector<string> Champion::getBadChamps() { return _badChamps; }
vector<string> Champion::getGoodChapms(){ return _goodChamps; }
string Champion::getPrimaryRole() { return _primaryRole; }
string Champion::getSecondaryRole() { return _secondaryRole; }
string Champion::getName() { return _name; }



void Champion::setBadChamps(string champ) { _badChamps.push_back(champ); }
void Champion::setGoodChamps(string champ) { _goodChamps.push_back(champ); }
void Champion::setPrimaryRole(string pr) { _primaryRole = pr; }
void Champion::setSecondaryRole(string sr) { _secondaryRole = sr; }
void Champion::setName(string name) { _name = name; }