#pragma once

#include <vector>
#include "Dealer.h"
#include "Player.h"

using namespace std;

class Table {
private:
	static unsigned int nextID;
	unsigned int roundsLeft;
	unsigned int minBet;
	unsigned int maxBet;
	unsigned int moneyOfTable;
	unsigned int maxNumberOfPlayers;
	unsigned int indexNextToPlay;
	unsigned int tableID;
	Dealer dealerOfTable;
	vector<Player*> players;
	vector<int> playersStatus;
	vector<unsigned int> actualBets;

public:
	Table(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, Dealer&); // Table() is a construct of a class Table with 6 args(roudnsLeft,minBet, maxBet, moneyOfTbale, maxNumberOfPlayers, dealerOfTable)
	void setMinBet(unsigned int minBet);
	void setMaxBet(unsigned int maxBet);
	void setDealer(Dealer &dealerOfTable);
	void addPlayer(Player *newPlayer);
	void addPlayers(vector <Player *> newPlayers);
	unsigned int getMinBet();
	unsigned int getMaxBet();
	void play();
	void getInitialBets();
	void dealOneCardToAllPlayers();
	void payToPlayer(Player* player1, unsigned int value);
};


