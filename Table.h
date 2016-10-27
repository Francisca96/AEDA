#pragma once

#include <string>
using namespace std;

class Table {
	unsigned int minBet;
	unsigned int maxBet;
	vector<Player*> players;
	unsigned int moneyOfTable;
	unsigned int numberMaxOfPlayers;

public:
	void getMinBet();
	void setMinBet(string aMinBet);
	void getMaxBet();
	void setMaxBet(string aMaxBet);
};


