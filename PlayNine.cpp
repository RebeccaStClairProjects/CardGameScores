#include "PlayNine.h"
#include <iostream>
#include <limits>
#include <map>
using namespace std;

void PlayNine::startPlayNine()
{
    getPlayerNamesAndOptions();

    do {
        playHand();
        // After the scheduled # of holes, decide a winner.
        if (round + 1 >= totalHoles) {
            winnerIndex = checkForWinner();
            if (winnerIndex >= 0) {
                gameOver = true;
            }
            else {
                // Tie? keep playing sudden-death extra holes until broken.
                cout << "\nTied for lowest score — playing extra hole(s) until we have a winner!\n";
            }
        }
        round++;
    } while (!gameOver);

    system("cls");
    cout << "\n\n================ FINAL SCOREBOARD ================\n";
    drawBoard();
    cout << "\nAfter " << round << " hole(s), the winner is ... "
        << players[winnerIndex].GetName() << "!\n\n";
}

void PlayNine::getPlayerNamesAndOptions()
{
    system("cls");
    cout << "Setting up Play Nine (Card Game of Golf)\n\n";
    for (int i = 0; i < allPlayers; i++) {
        players[i].SetName(i + 1);
        playerCharCount[i] = players[i].GetNameSize();
    }

    cout << "\nHow many holes would you like to play? (Standard is 9; range 1 - 18): ";
    totalHoles = inputBlock(1, 18, "Pick between 1 and 18, please.");
}

void PlayNine::playHand()
{
    system("cls");
    cout << "\n================ PLAY NINE - HOLE " << (round + 1) << " ================\n";
    drawBoard();

    cout << "\nEnter each player's score for this hole.\n";
    cout << "Choose method per player:\n"
        "  1) Enter the total directly\n"
        "  2) Auto-compute from the 8 card values (supports pairs cancel-to-zero)\n";

    for (int i = 0; i < allPlayers; i++) {
        cout << "\n-- " << players[i].GetName() << " --\n";
        int method = inputBlock(1, 2, "Enter 1 or 2.");
        int holeScore = 0;

        if (method == 1) {
            cout << "Enter this hole's total strokes (-50 to +200): ";
            // Allow negatives for –5 etc if using house rules; clamp input
            holeScore = inputBlock(-50, 200, "Range is -50 to 200.");
        }
        else {
            holeScore = computeHandFromEightCards();
        }

        // Record to Player (your Player.SetScore adds to cumulative and logs per-round points)
        players[i].SetScore(holeScore, round);
    }
}

int PlayNine::computeHandFromEightCards()
{
    cout << "Enter your 8 card values in board order.\n"
        "Rules:\n"
        " Matched column cancels to 0 (EXCEPT -5/-5 = -10).\n"
        " If you have moltiple pares of the SAME value, add a bonus of -5 * the number of matched columns.\n"
        "    (e.g., two 5/5 columns ? -10 total bonus; three 5/5 columns ? -15.)\n";

    int colTotals[4] = { 0,0,0,0 };

    // Count how many matched columns we have for each value
    // key = card value, value = number of matched columns with that value
    std::map<int, int> matchedPairsByValue;

    for (int c = 0; c < 4; c++) {
        cout << " Column " << (c + 1) << " - top value (-5 to 12): ";
        int top = inputBlock(-5, 12, "Please enter between -5 and 12.");
        cout << " Column " << (c + 1) << " - bottom value (-5 to 12): ";
        int bottom = inputBlock(-5, 12, "Please enter between -5 and 12.");

        if (top == bottom) {
            // Record the matched pair for set-bonus accounting
            matchedPairsByValue[top]++;

            // Column scoring
            if (top == -5) {
                // Special case: -5/-5 scores -10, not 0
                colTotals[c] = -10;
            }
            else {
                // Other equal pairs cancel to 0
                colTotals[c] = 0;
            }
        }
        else {
            // Unmatched column: sum the two cards
            colTotals[c] = top + bottom;
        }
    }

    // Base total from columns
    int total = colTotals[0] + colTotals[1] + colTotals[2] + colTotals[3];

    // Apply set bonuses: –5 per matched column for each value when there are >= 2 matched columns
    // (This works for any value, including –5; –5 columns already contribute –10 each, then get the bonus on top.)
    for (const auto& kv : matchedPairsByValue) {
        int value = kv.first;
        int pairs = kv.second;
        if (pairs >= 2) {
            total += (-5 * pairs);
        }
    }

    cout << " Computed hole total = " << total << "\n";
    return total;
}



void PlayNine::drawBoard()
{
    // Header row: names
    cout << "\n|";
    for (int x = 0; x < allPlayers; x++) {
        cout << "       " << players[x].GetName() << "       |";
    }

    // Current totals
    cout << "\n|";
    for (int x = 0; x < allPlayers; x++) {
        cout << "         " << players[x].GetScore() << "          |";
    }

    // Show last up-to-10 holes history
    if (round >= 0) {
        int start = (round > 9) ? (round - 9) : 0;
        for (int r = start; r < round; r++) {
            cout << "\n|";
            for (int x = 0; x < allPlayers; x++) {
                int v = players[x].GetPoints(r);
                cout << "        H" << (r + 1) << (v >= 0 ? " +" : " ") << v << "       |";
            }
        }
    }
    cout << "\n";
}

int PlayNine::checkForWinner()
{
    // Lowest total after scheduled holes wins.
    // If tie, return -1 so caller can trigger sudden-death extras.
    int bestIdx = 0;
    int bestScore = players[0].GetScore();

    // Find min
    for (int i = 1; i < allPlayers; i++) {
        int s = players[i].GetScore();
        if (s < bestScore) {
            bestScore = s;
            bestIdx = i;
        }
    }

    // Check if unique minimum
    int ties = 0;
    for (int i = 0; i < allPlayers; i++) {
        if (players[i].GetScore() == bestScore) ties++;
    }
    if (ties == 1) return bestIdx;
    return -1;
}
