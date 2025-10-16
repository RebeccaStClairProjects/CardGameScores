#include "Phase10.h"
//#include "GameHistory.txt"

void Phase::playerHistory()
{
    string fileLine;
    //ifstream file("GameHistory.txt"); //This part will open the file
    /*if (file.is_open())
	{
		while (getline(file, fileLine)) //continue while there are still lines left in the file
		{
			cout << fileLine << ' ';
		}
		file.close(); //closing the file when done with it
	}
	else
	{
		cout << endl << "Cannot open file\n\n";
	} */
}

void Phase::getPlayerName()
{
	for (int x = 0; x < allPlayers; x++) {
        players[x].SetName(x+1);
	}    
}

void Phase::startPhase()
{
    int langth = 0, starting = 0;
    getPlayerName();
    do {
        playEachRound();
    } while (winner == false);

    system("cls");
    cout << endl << endl;
    cout << "\n\n\n|";
    for (int x = 0; x < allPlayers; x++)
    {
        if (x == 1) { cout << " "; }
        cout << "       " << players[x].GetName() << "       |";
        langth = langth + playerCharCount[x] + 14;
    }    

    cout << "\n|";
    for (int x = 0; x < allPlayers; x++)
    {
        cout << "    Phase:" << players[x].GetPhase(round);
        cout << " Score:" << players[x].GetScore();
        cout << "  |";
    }
    cout << "\n\n\n\n";
    cout << "And the winning player is ... ";
    cout << endl << "............." << players[theWinner].GetName();
    cout << "\n\n\n\n\n";
}

void Phase::playEachRound()
{
    buildBord();
    string roundString = "";
    int roundScore = 0;
    bool corectPhase = false;

    switch (round + 1) {
    case 1:      roundString = "first";         break;
    case 2:      roundString = "second";        break;
    case 3:      roundString = "third";         break;
    case 4:      roundString = "fourth";        break;
    case 5:      roundString = "fifth";         break;
    case 6:      roundString = "sixth";         break;
    case 7:      roundString = "seventh";       break;
    case 8:      roundString = "eighth";        break;
    case 9:      roundString = "ninth";         break;
    case 10:     roundString = "tenth";         break;
    case 11:     roundString = "eleventh";      break;
    case 12:     roundString = "twelfth";       break;
    case 13:     roundString = "thirteenth";    break;
    case 14:     roundString = "fourteenth";    break;
    case 15:     roundString = "fiftenth";      break;
    case 16:     roundString = "sixteenth";     break;
    case 17:     roundString = "seventeenth";   break;
    case 18:     roundString = "eighteenth";    break;
    case 19:     roundString = "nineteenth";    break;
    case 20:     roundString = "twentieth";     break;
    }
    for (int x = 0; x < allPlayers; x++) {
        cout << "\nFor the " << roundString << " round what was the score for " << players[x].GetName() << "\n";

        roundScore = inputBlock(0, 400, "That is not a valed score rang ");

        players[x].SetScore(roundScore, round);

        if (roundScore == 0) {
            cout << "Seeing as how " << players[x].GetName() << " got 0 points it is safe to assume they went down as that is the only way to get 0\n";
            players[x].SetPhase("Yes", round, (round - 1));
        }
        else {
            do {
                cout << "Did " << players[x].GetName() << " go down this round?\n";
                cin >> goDown;
                corectPhase = players[x].SetPhase(goDown, round, (round - 1));
            } while (corectPhase == false);
        }


    }

    theWinner = Winner();
    if (winner == false)
    { 
        round++;
    }
    
    /*int test;
    cin >> test;*/
}

void Phase::buildBord()
{
    string p_Score;
    int bracing;
    int spacing;
    int langth = 0, starting = 0, Laps = 0;

    system("cls");
    cout << "\n\n\n|";
    /*playerCharCount[x] = players[x].GetNameSize();
    flipedPlayerCount[x] = playerCharCount[x];
    cout << "Player " << x + 1 << " has " << playerCharCount[x] << " Letters in their name.\n";
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (flipedPlayerCount[i] > flipedPlayerCount[j]) {
                int temp = flipedPlayerCount[i];
                flipedPlayerCount[i] = flipedPlayerCount[j];
                flipedPlayerCount[j] = temp;
            }
        }
    }*/
    /* This loop prints the players name at the top */
    for (int x = 0; x < allPlayers; x++)
    {
        if (x == 1) { cout << " "; }
        cout << "       " << players[x].GetName() << "       |";
        langth = langth + playerCharCount[x] + 14;
    }
    
    if (round != 0) {
        cout << "\n|";
        for (int x = 0; x < allPlayers; x++)
        {
            cout << "         " << players[x].GetScore();
            cout << "          |";
        }
    
        cout << endl;
        if (round > 9) {
            starting = round - 9;
        }
        
        for (int r = starting; r < round; r++) {
            cout << "\n|";
            for (int x = 0; x < allPlayers; x++)
            {
                cout << "    Phase:" << players[x].GetPhase(r);
                cout << " Score:" << players[x].GetPoints(r);
                cout << "  |";

            }
        }
    }
}
int Phase::Winner()
{
    int Allwinner[5] = { 0,0,0,0,0 };
   
    int numberOfWinners = 0;
    int testPhase, testScore, lastScore;
    int winnerNumber = 0;

    for (int x = 0; x < allPlayers; x++) {
        testPhase = players[x].GetPhase(round - 1);
        if (testPhase == 9) {
            Allwinner[numberOfWinners] = x;
            numberOfWinners++;
            cout << "This is working";

            
        }
    }
    if (numberOfWinners > 0) {
        if (numberOfWinners > 1) {
            for (int y = 0; y < numberOfWinners; y++) {
                testScore = players[Allwinner[y]].GetScore();
                if (y == 0) {
                    lastScore = testScore;
                } 
                else {
                    if (testScore < lastScore) {
                        lastScore = testScore;
                        winnerNumber = y;
                    }
                }
            }
            winner = true;
            return winnerNumber;
        }
        else {
            winnerNumber = Allwinner[0];
            winner = true;
            return winnerNumber;
        }
    }
    else {
        winner = false;
    }
    return 0;
}
