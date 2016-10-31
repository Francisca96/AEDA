#pragma once

#include "Dealer.h"
#include "Player.h"
#include "utils.h"

using namespace std;

class Table {
private:
	bool continuingPlay;
	unsigned int minBet;
	unsigned int maxBet;
	unsigned int moneyOfTable;
	unsigned int numberMaxOfPlayers;
	unsigned int indexNextToPlay;
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


