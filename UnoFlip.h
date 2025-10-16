#pragma once
#include "Player.h"
#include <string>
using namespace std;

// Reuse your input validation function from main
int inputBlock(int lower_range, int upper_range, string outOfRangMessege);

class UnoFlip
{
private:
    int allPlayers = 0;
    int round = 0;
    int targetScore = 500;       // standard UNO/UNO Flip target
    bool gameOver = false;
    int winnerIndex = -1;

    Player players[8] = {
        Player("null"), Player("null"), Player("null"), Player("null"),
        Player("null"), Player("null"), Player("null"), Player("null")
    };

    int playerCharCount[8] = { 0,0,0,0,0,0,0,0 };

public:
    UnoFlip(int numberOfPlayers, int target = 500) {
        allPlayers = numberOfPlayers;
        targetScore = target;
    }
    UnoFlip() = default;

    void startUnoFlip();
    void getPlayerNames();
    void playHand();
    void drawBoard(bool showHistoryThisRound);
    int  checkForWinner();   // returns winner index or -1

    // Optional: allow changing target mid-run if you want
    void setTargetScore(int t) { targetScore = t; }
    int  getTargetScore() const { return targetScore; }
};
