#include <iostream>
#include <vector>
#include <string>
#include "TxtFileProof.h"
#include "ChampDatabase.h"
#include "ChampionSearch.h"


using namespace std;



TxtFileProof::TxtFileProof()
{
	ChampDatabase cd;
	ChampionSearch cs(_listOfChamps);

	_cs = cs;
	_cd = cd;

	_champs = _cd.getChamps();
	_listOfChamps = _cd.getList();



	proofChamps();
}


void TxtFileProof::proofChamps()
{
	bool pgc, pbc, pr, pp;
	for (int i = 0; i < _champs.size(); i++)
	{
		cout << _listOfChamps[i] << "\n\t" << endl;
		pgc = proofGoodCounters(i);
		pbc = proofBadCounters(i);
		pr = proofRoles(i);
		pp = proofPositions(i);

		if (pgc && pbc && pr && pp)
		{
			cout << "\t" << _champs[i].getName() << " --------------------------- success" << endl;
		}
	}


}


bool TxtFileProof::proofGoodCounters(int j)
{
	vector<string> goodChamps = _champs[j].getGoodCounter();

	bool pgc = true;


	for (int i = 0; i < goodChamps.size(); i++)
	{
		if (_cs.search(goodChamps[i]) < 0)
		{
			cout << "\tGC ------- " << goodChamps[i] << " -------- fail" << endl;
			pgc = false;
		}
	}

	return pgc;
}


bool TxtFileProof::proofBadCounters(int j)
{
	vector<string> badChamps = _champs[j].getBadCounter();

	bool pbc = true; 


	for (int i = 0; i < badChamps.size(); i++)
	{
		if (_cs.search(badChamps[i]) < 0)
		{
			cout << "\tBC ------- " << badChamps[i] << " -------- fail" << endl;
			pbc = false;
		}
	}

	return pbc;
}


bool TxtFileProof::proofPositions(int j)
{
	vector<string> pos = _champs[j].getPositions();

	bool pp = true;


	for (int i = 0; i < pos.size(); i++)
	{
		if (search(_pos, pos[i]) < 0)
		{
			cout << "\tGC ------- " << pos[i] << " -------- fail" << endl;
			pp = false;
		}
	}

	return pp;
}


bool TxtFileProof::proofRoles(int j)
{
	vector<string> roles;

	roles.push_back(_champs[j].getPrimaryRole());
	roles.push_back(_champs[j].getSecondaryRole());

	bool pr = true;


	for (int i = 0; i < roles.size(); i++)
	{
		if (_cs.search(roles[i]) < 0)
		{
			cout << "\tGC ------- " << roles[i] << " -------- fail" << endl;
			pr = false;
		}
	}

	return pr; 
}


void TxtFileProof::setPos()
{
	_pos.push_back("Top");
	_pos.push_back("Adc");
	_pos.push_back("Mid");
	_pos.push_back("Support");
	_pos.push_back("Jungle");
}


void TxtFileProof::setRoles()
{
	_roles.push_back("Marksman");
	_roles.push_back("Fighter");
	_roles.push_back("Tank");
	_roles.push_back("Support");
	_roles.push_back("Assassin");
	_roles.push_back("Mage");
}


int TxtFileProof::search(vector<string> &vs, string s)
{
	for (int i = 0; i < vs.size(); i++)
	{
		if (vs[0] == s)
			return i; // returns the index of where the champion can be found. 
		else
			return -1; // to say that it was not found
}
