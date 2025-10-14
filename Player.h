#pragma once
// Including all the necessary header files and links
using namespace std;
#include <iostream>


//This is the Player class
class Player {
private:
	string name;
	int nameSize;
	int points[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int phase[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int hands = 1;
	int score = 0;

public:
	Player(string p_name) {
		name = p_name;
	}

	void SetName(int x) {
		int count;
		cout << "What is the name of player " << x << "\n";
		cin >> name;
		nameSize = name.length();
	}
	string GetName() {
		return name;
	}
	int GetNameSize() {
		return nameSize;
	}
	void SetScore(int p_Score, int thisRound) {
		score = score + p_Score;
		points[thisRound] = p_Score;
	}
	
	int GetScore() {
		return score;
	}
	int GetPoints(int r) {
		return points[r];
	}
	bool SetPhase(string p_phase, int thisRound, int lastRound) 
	{
		if (p_phase == "yes" or p_phase == "Yes" or p_phase == "YES") {					
			if (thisRound == 0) {
				phase[thisRound] = 1;
			}
			phase[thisRound] = phase[lastRound] + 1;
			return true;
		}		
		else if (p_phase == "no" or p_phase == "No" or p_phase == "NO")
		{
			phase[thisRound] = phase[lastRound];
			return true;
		}
		else {
			cout << "\nThat is not a valed answer, Pleas type yes or no.\n";
			return false;
		}
		return false;
	}

	int GetPhase(int thisRound) {
		return phase[thisRound];
	}

};