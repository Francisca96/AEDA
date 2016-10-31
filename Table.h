#pragma once

#include "Dealer.h"
#include "Player.h"
#include "utils.h"

using namespace std;

class Table {
private:
	bool keepPlaying;
	unsigned int minBet;
	unsigned int maxBet;
	unsigned int moneyOfTable;
	unsigned int maxNumberOfPlayers;
	unsigned int indexNextToPlay;
	Dealer dealerOfTable;
	vector<Player*> players;
	vector<unsigned int> actualBets;

public:
	//removed keepPlaying from the constructor (Quando criamos a mesa acho que faz sentido o keepPlaying ser true;
	Table(unsigned int, unsigned int, unsigned int, unsigned int); // Table() is a construct of a class Table with 6 args(minBet, maxBet, moneyOfTbale, maxNumberOfPlayers, dealerOfTable)
	void setMinBet(unsigned int minBet);
	void setMaxBet(unsigned int maxBet);
	void setDealer(Dealer &dealerOfTable);
	void addPlayer(Player *newPlayer);
	void addPlayers(vector <Player *> newPlayers);
	unsigned int getMinBet();
	unsigned int getMaxBet();
	void play(); //Please comment the functionality of this method;
	void getInitialBets();
	void dealOneCardToAllPlayers();
};


