#pragma once
// Including all the necessary header files and links
#include "Player.h"

int inputBlock(int lower_range, int upper_range, string outOfRangMessege);

//This is the body of the Phase Class
class Phase
{
	//This is the privet portion of the class that can only be accessed by the class itself.
private:
	//These are variables and arrays
	int currentPlayer;
	int lastPlayer;
	int allPlayers = 0;
	int round = 0;
	int theWinner;
	int starter = 0;
	string goDown;
	bool winner = false;

	Player players[8] = {
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
		    Player("null"),
	};
	int playerCharCount[8] = { 0,0,0,0,0,0,0,0 };
	int flipedPlayerCount[8] = { 0,0,0,0,0,0,0,0 };

public:

	Phase(int numberOfPlayers) {
		allPlayers = numberOfPlayers;
	}
	Phase() = default;

	//These are the declarations for the classes methods witch are defined in the PhaseLoop.cpp file.
	void playerHistory();
	void getPlayerName();        //
	void buildBord();
	void startPhase();            //
	void playEachRound();        //
	int Winner();   //This method checks who won once a bid has been rejected. 	

	
};