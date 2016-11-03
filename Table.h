#pragma once

#include <vector>
#include "Dealer.h"
#include "Player.h"
#include "utils.h"

using namespace std;

//Exception Class- (maxNumberOfPlayers,actualNumOfPlayers)
class TooManyPlayers {
private:
	unsigned int maxNumberOfPlayers;
	unsigned int actualNumOfPlayers;
public:
	TooManyPlayers(unsigned int maxNumberOfPlayers, unsigned int actualNumOfPlayers);
	void what();
};

class Table {
private:
	static unsigned int nextID;
	unsigned int roundsLeft;
	unsigned int minBet;
	unsigned int maxBet;
	unsigned int initialMoney;
	float moneyOfTable;
	unsigned int maxNumberOfPlayers;
	unsigned int tableID;
	Dealer dealerOfTable;
	vector<Player*> players;
	vector<unsigned int> actualBets;

public:
	Table(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, Dealer&); // Table() is a construct of a class Table with 6 args(roudnsLeft,minBet, maxBet, moneyOfTbale, maxNumberOfPlayers, dealerOfTable)
	void setMinBet(unsigned int minBet);
	void setMaxBet(unsigned int maxBet);
	void setDealer(Dealer dealerOfTable);
	void addPlayer(Player *newPlayer);
	void addPlayers(vector <Player *> newPlayers);
	void removePlayer(Player * player1);
	void play();
	unsigned int getInitialMoney();
	unsigned int getTableID();
	unsigned int getMinBet();
	unsigned int getMaxBet();
	void getInitialBets();
	Dealer * getDealer();
	void dealOneCardToAllPlayers();
	void payToPlayer(Player* player1, float value);
	unsigned int restartDeck();
	void showTableInfo();
	void kickPlayer(unsigned int index);
	/**
	*@return moneyOfTable
	*removes all players from the Table
	*/
	float closeTable();
	
};

