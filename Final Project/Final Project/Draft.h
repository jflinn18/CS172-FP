#ifndef _Draft_h_
#define _Draft_h_
using namespace std;






class Draft
{
private:
	Team blue; // maybe Team user and Team computer
	Team red;
	UserInput ui;


public:
	Draft(vector<string> champs);
	/*
	Constructor for the draft object.  I would be calling this function from
	the ChampDatabase class.
	*/

	void examineUserInput();
	/*
	This function would examine the string that is returned from ui.getInput().
	I really don't know what I was thinking when I wrote this.  You could probably
	hard code what this would do when you call the ui.getInput() function
	*/

	void executeDraft();
	/*
	Like we talked about in class, this is the "main" for this class.  This will be
	doing all of the executing of different functions to get through a draft.

	This will probably look like:
	virtual void executeDraft();

	If it looks like the above line, there would not be a body for this function.
	It would be overrode in both of the subclasses of Draft.  Thus, no body for this
	function.  It would be in the two subclasses.
	*/

	Champion generateChamp();
	/*
	This would be for the computer to generate a champ depending on what is needed for
	its team.  This could mean that there needs to be a vector in team that has
	the positions that are already filled for the team.  But this could also be for
	generating a good counter.  Or maybe that should be another function.
	*/

	string getChampName();
	/*
	I don't remember what I was thinking here.  You don't need to return the names in
	teamChampNames.  That is already in the Team class.  You also don't need to get
	the user input because ui.getInput and examineUserInput already do more than
	enough for that.
	*/

	void setChampName(string);
	/*
	This would give the champion name to the team that it goes with.  For example:
	when I input that I want Kha'zix, this function would store "Kha'zix" into the
	vector<string> teamChampNames in the Team Class.

	Or maybe this would call the function addTeamChampNames("ChampName") in the Team
	class.
	*/

	void takeTurn();
	/*
	I was thinking that this could be one turn.  But you made a really good point in
	class today that each turn was different.  You know, 1 pick -> 2 pick, 2 pick ->
	2 pick, etc.

	This changes the inheritence and polymorphism of the two different drafts.  But
	more on when I get there.


	I woke up this morning thinking about the project (11/26).  I was thinking, the
	pattern of turn taking is for either draft:
	1) 1 pick -> 2 pick
	2) 2 pick -> 2 pick
	3) 2 pick -> 1 pick

	You might think about creating three turn methods; one for each of the above.
	It would have to have a conditional to figure out who is going first. But other
	than that, they would be the same framework for a turn.
	Plus it would help me with the draftOutput function of UserInput.

	I was thinking that we could use a 2D vector or array that is set to 6 rows and 3
	columns. We could initialize it to:

	Computer:           Banned:           User:
	---------           -------           -----
	---------           -------           -----
	---------           -------           -----
	---------           -------           -----
	---------           -------           -----

	And then when you go through the turns, you could use a for loop to place both
	Team's vector<string> teamChampNames and the banned champs into there designated
	columns and then pass that 2D vector into the ui.draftOutput function.  Or....you
	could pass in the three above mentioned 1D vectors and I could do what I just said
	in the draftOutput function.  This is how I'm going to code it for now.

	When either Team's teamChampNames change or the banned champs you could call the
	the correct "update" method in UI.  There is a method to update the banned champs
	and then there is a method to update the picked champions.

	NOTE: in UserInput::updatepicks, the user's picks is always passed in first.

	If, however, you decide to 2D vector and pass it in to me, you might consider
	using a variable in the public section in the Draft header file for the 2D vector.



	More on this topic.  You might want to think about creating a function for a user
	pick and a computer pick.  All that function will do is what it takes for a user
	or computer to pick one champion.  Then in the take a turn function, you could call
	the pick functions once or twice depending on how many champions they get to pick
	during that turn. Again, another morning dream coding session :)  (12/2)
	*/

	int whoseTurn();
	/*
	This was really to go hand in hand with the above function.  Without that function
	it really isn't needed.
	*/
};


#endif