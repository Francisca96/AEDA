#pragma once

#include <string>
#include <vector>

using namespace std;

class Table {
	unsigned int minBet;
	unsigned int maxBet;
	unsigned int moneyOfTable;
	unsigned int numberMaxOfPlayers;
	vector<Player*> players;

public:
	unsigned int getMinBet();
	unsigned int getMaxBet();
	void setMaxBet(unsigned int aMaxBet);
	void setMinBet(unsigned int aMinBet);
};


