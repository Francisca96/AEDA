#pragma once

#include <vector>
#include <sstream>
#include "Dealer.h"
#include "cmdUI.h"

class Player;
class Dealer;
class Table;

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

class NoPlayersOnTable {
private:
	unsigned int tableID;
public:
	NoPlayersOnTable(Table *noPlayersOnTable);
	unsigned int getID() const;
};

class Table {
private:
	static unsigned int nextID;
	//unsigned int roundsLeft;
	unsigned int minBet;
	unsigned int maxBet;
	unsigned int initialMoney;
	float moneyOfTable;
	unsigned int maxNumberOfPlayers;
	int tableID;
	Dealer * dealerOfTable;
	vector<Player*> players;
	vector<Player*> actualPlayers;

public:
	Table(int ID);
	Table( unsigned int, unsigned int, unsigned int, unsigned int, Dealer*); // Table() is a construct of a class Table with 6 args(minBet, maxBet, moneyOfTbale, maxNumberOfPlayers, dealerOfTable)
	~Table();
	void setMinBet(unsigned int minBet);
	void setMaxBet(unsigned int maxBet);
	void setDealer(Dealer *dealerOfTable);
	void setID(int ID);
	void addPlayer(Player *newPlayer);
	void addPlayers(vector <Player *> newPlayers);
	void removePlayer(string &name);
	void play(unsigned int userID);
	void simulation(unsigned int roundsLeft);
	unsigned int getInitialMoney() const;
	int getTableID() const;
	unsigned int getMinBet() const;
	unsigned int getMaxBet() const;
	unsigned int getNumberMaxOfPlayers() const;
	void getInitialBets();
	Dealer * getDealer();
	vector <Player *> getPlayers() const;
	void dealOneCardToAllPlayers();
	void payToPlayer(Player* player1, float value);
	unsigned int restartDeck();
	void showTableInfo(pair <short, short> xy);
	void kickPlayer(unsigned int index);
	void resetBot1Counters();
	void addMoneyToTable(unsigned int money);
	/**
	*@return moneyOfTable
	*clears bots Counters
	*/
	float closeTable();
	static void setNextID(unsigned int tableNextID);
	static unsigned int getNextId();
	
};