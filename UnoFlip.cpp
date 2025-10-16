#include "UnoFlip.h"
#include <iostream>
#include <limits>

using namespace std;

void UnoFlip::startUnoFlip()
{
    getPlayerNames();

    do {
        playHand();
        winnerIndex = checkForWinner();
        if (winnerIndex >= 0) {
            gameOver = true;
        }
        else {
            round++;
        }
    } while (!gameOver);

    system("cls");
    cout << "\n\n================ FINAL SCOREBOARD ================\n";
    drawBoard(true);
    cout << "\nTarget Score: " << targetScore << "\n";
    cout << "And the winning player is ... " << players[winnerIndex].GetName() << "!\n\n";
}

void UnoFlip::getPlayerNames()
{
    system("cls");
    cout << "Great! Let's set up UNO Flip.\n\n";
    for (int i = 0; i < allPlayers; i++) {
        players[i].SetName(i + 1);
        playerCharCount[i] = players[i].GetNameSize();
    }

    cout << "\nDefault target score is 500 (standard). If you want to change it, enter a value between 100 and 2000.\n";
    cout << "Otherwise, enter 500: ";
    int chosenTarget = inputBlock(100, 2000, "Please pick a target between 100 and 2000.");
    targetScore = chosenTarget;
}

void UnoFlip::playHand()
{
    system("cls");
    cout << "\n================ UNO FLIP — HAND " << (round + 1) << " ================\n";
    drawBoard(false);

    // Ask which player went out (the hand winner)
    cout << "\nWho went out this hand?\n";
    for (int i = 0; i < allPlayers; i++) {
        cout << (i + 1) << ". " << players[i].GetName() << "\n";
    }
    int wentOutIndex = inputBlock(1, allPlayers, "Please choose a valid player number.") - 1;

    // Collect remaining-point totals for everyone else
    // (House rule neutral: you enter the totals directly—no need to itemize cards)
    int totalAward = 0;
    for (int i = 0; i < allPlayers; i++) {
        if (i == wentOutIndex) continue;

        cout << "Enter remaining points in " << players[i].GetName() << "'s hand (0–1000): ";
        int rem = inputBlock(0, 1000, "Enter a number from 0 to 1000.");
        totalAward += rem;

        // Record round points for non-winners as 0 (they didn't earn points this hand)
        players[i].SetScore(0, round);
    }

    // Award the sum to the hand winner
    cout << players[wentOutIndex].GetName() << " earns " << totalAward << " points this hand!\n";
    players[wentOutIndex].SetScore(totalAward, round);

    cout << "\nHand complete. Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void UnoFlip::drawBoard(bool showHistoryThisRound)
{
    // Top name row
    cout << "\n|";
    for (int x = 0; x < allPlayers; x++) {
        cout << "       " << players[x].GetName() << "       |";
    }

    // Current totals
    cout << "\n|";
    for (int x = 0; x < allPlayers; x++) {
        cout << "         " << players[x].GetScore() << "          |";
    }

    // Recent per-round rows (show a sliding window of up to last 10 rounds)
    if (round >= 0) {
        int start = (round > 9) ? (round - 9) : 0;
        for (int r = start; r <= round; r++) {
            cout << "\n|";
            for (int x = 0; x < allPlayers; x++) {
                cout << "   R" << (r + 1) << " +" << players[x].GetPoints(r) << "       |";
            }
        }
    }

    cout << "\n";
}

int UnoFlip::checkForWinner()
{
    // Winner is any player whose score >= targetScore,
    // and among those, the one with the highest score wins.
    // If multiple players cross in the same hand, take the highest total.
    int topIndex = -1;
    int topScore = -1;
    bool anyReached = false;

    for (int i = 0; i < allPlayers; i++) {
        int s = players[i].GetScore();
        if (s >= targetScore) {
            anyReached = true;
            if (s > topScore) {
                topScore = s;
                topIndex = i;
            }
        }
    }

    if (anyReached) return topIndex;
    return -1;
}
