#pragma once

#include <string>
#include <vector>
#include "Dealer.h"
#include "Player.h"

using namespace std;

class Table {
private:
	unsigned int minBet;
	unsigned int maxBet;
	unsigned int moneyOfTable;
	unsigned int numberMaxOfPlayers;
	unsigned int indexNexToPlay;
	Dealer dealerOfTable;
	vector<Player*> players;
	friend Dealer;

public:
	Table(unsigned int, unsigned int, unsigned int, unsigned int); // Table() is a construct of a class Table with 4 args(minBet, maxBet, moneyOfTbale, numberMaxOfPlayers)
	void setMinBet(unsigned int minBet);
	void setMaxBet(unsigned int maxBet);
	void addPlayer(Player *newPlayer);
	void addPlayers(vector <Player *> newPlayers);
	unsigned int getMinBet();
	unsigned int getMaxBet();
};


