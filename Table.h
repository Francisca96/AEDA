#pragma once

#include <vector>
#include "Dealer.h"
#include "Player.h"

using namespace std;

class Table {
private:
	static unsigned int nextID;
	bool continuingPlay;
	unsigned int minBet;
	unsigned int maxBet;
	unsigned int moneyOfTable;
	unsigned int numberMaxOfPlayers;
	unsigned int indexNextToPlay;
	unsigned int tableID;
	Dealer dealerOfTable;
	vector<Player*> players;

public:
	Table();
	Table(bool, unsigned int, unsigned int, unsigned int, unsigned int); // Table() is a construct of a class Table with 6 args(continuingPlay, minBet, maxBet, moneyOfTbale, numberMaxOfPlayers, dealerOfTable)
	void setMinBet(unsigned int minBet);
	void setMaxBet(unsigned int maxBet);
	void setDealer(Dealer dealerOfTable);
	void addPlayer(Player *newPlayer);
	void addPlayers(vector <Player *> newPlayers);
	unsigned int getMinBet();
	unsigned int getMaxBet();
	void play();
};


