// Including all the necessary header files and links
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

#include "Player.h"
#include "Phase10.h"

int lower_range, upper_range;
string outOfRangMessege;

int inputBlock(int lower_range, int upper_range, string outOfRangMessege);


/* This program is here to help record the scores for diferint famaly card games. 
This program will start of with Phase 10 and Oneo but there will be room to add more games in latter.*/

int main()
{
	
	int allPlayers;
	int chose;

	cout << "This is working\n";
	cout << "How many people will be playing today?\n";	
	allPlayers = inputBlock(2, 8, "You need to have at lest two players but no more then 8.");
	
	cout << "Now that we know how many people are playing now we just need to know what game you will be playing\n";
		
	cout << "1.Phase10\n";
	cout << "2.Oneo\n";
	cout << "3.Exit\n";
	chose = inputBlock(1, 4, "Sorry that is not one of the options, Pleas pick from the options above");
	Phase phase10 = Phase(allPlayers);
	switch (chose) {
	case 1:	
		phase10.startPhase();
		break;
	case 2:
		cout << "That option is still in testing and not ready for use. Pleas Select a diferint option.\n";
		break;
	case 3:
		cout << "Thank you for playing, Good buy!\n";
		return 0;
	}
	cout << "This is the end";
}


/*
I first started by creating the Player.h, Phase10.h and Phase10.cpp header files and including them in the main file.
Next I set up the basic class information for the Phase10 and Player classes. Then I started working on adding some of the 
variables, constructers and creating the metheds of the player and Phase10 classes without adding functionality to the 
metheds juist the outline. After that I filledin the seters and gettinger of the player class. I ran a test and eveything was 
working properly. I then added some basic output statments to start building the start of the program. I then built the 
function for input validation and error handaling. 

*/

//This is a fuction to test if the user input is corect
int inputBlock(int lower_range, int upper_range, string outOfRangMessege) {

	int testInput = 0;
	do {
		try {
			cin >> testInput;

			//This will catch a type mismatch like trying to put a string in to an int
			if (cin.fail())
			{
				//This twors the error to the catch block
				throw runtime_error("Input is not an integer\n");
			}

			// This will test if the input is within nesasary paramiters
			else if (testInput < lower_range or testInput > upper_range) {
				cout << outOfRangMessege << endl;
			}
		}
		//This catches the mismatch type error so the program dose not have to crash.
		catch (const runtime_error& e) {

			//This nect part prevents an infunet loop.
			//clear bad input flag 
			cin.clear();
			//discard input
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Input is not an integer; Please try again:\n";
			testInput = 0;
		}
	} while (testInput < lower_range or testInput > upper_range);
	//Once user input is deamed to be coreact it is returned to where the function was called.
	return testInput;
}