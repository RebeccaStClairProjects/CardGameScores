#pragma once
#include "Player.h"
#include <string>
using namespace std;

// Reuse your existing validator
int inputBlock(int lower_range, int upper_range, string outOfRangMessege);

// Matches your style: fixed array of up to 8 players, round-based loop
class PlayNine
{
private:
    int allPlayers = 0;
    int round = 0;           // 0-based hand index
    int totalHoles = 9;      // standard Play Nine = 9 holes
    bool gameOver = false;
    int winnerIndex = -1;

    Player players[8] = {
        Player("null"), Player("null"), Player("null"), Player("null"),
        Player("null"), Player("null"), Player("null"), Player("null")
    };

    int playerCharCount[8] = { 0,0,0,0,0,0,0,0 };

public:
    PlayNine(int numberOfPlayers, int holes = 9) {
        allPlayers = numberOfPlayers;
        totalHoles = holes;
    }
    PlayNine() = default;

    void startPlayNine();
    void getPlayerNamesAndOptions();
    void playHand();
    void drawBoard();
    int  computeHandFromEightCards(); // helper: reads 8 card values and returns total
    int  checkForWinner();            // returns index if decided, else -1
};
