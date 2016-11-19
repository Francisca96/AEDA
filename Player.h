#pragma once

#include <string>
#include <iomanip>
#include <vector>
#include "utils.h"
#include "Table.h"

using namespace std;

class Table;
class Dealer;
class Player;

/**
NameTooShortException is thrown when you try to create a player with a name smaller than 3 chars.
*/
class NameTooShortException {
public:
	void what();
};
class TooYoungException {
public:
	void what();
};

class PlayerAlreadyExistException {
private:
	string name;
public:
	PlayerAlreadyExistException(Player *player);
};

class PlayerNotExistException {
private:
	string name;
public:
	PlayerNotExistException(string name);
};

class PlayerStillOnTableException {
private:
	string name;
	unsigned int tableID;
public:
	PlayerStillOnTableException(Player *player);
	unsigned int getTableId() const;
};

class PlayerIsntOnTableException {
private:
	string name;
public:
	PlayerIsntOnTableException(string &name);
};

class HumanOnTableException {
private:
	string name;
public:
	HumanOnTableException(Player *player);
};

class Player {
private:
	string name;
	unsigned int initialMoney;
	float currentMoney;
	vector <Card> hand;
	vector <Card> hand2;
	unsigned int handScore;
	unsigned int hand2Score;
	unsigned int roundsPlayed;
	float averageProfit;
	unsigned int age;
	int onTable;
	int actualBet;
public:
	void hit(Card newCard);
	virtual bool takeInsurance(Table &table);
	virtual bool surrender(Table &table);
	virtual bool split(Dealer *dealerOfTable);
	void doubleDown();
	vector<Card> & getHand();
	vector<Card> & getHand2();
	unsigned int getHandSize() const;
	unsigned int getRoundsPlayed() const;
	unsigned int getCurrentMoney() const;
	float getAverageProfit() const;
	unsigned int getHandScore() const;
	unsigned int getHand2Score() const;
	unsigned int getInitialMoney() const;
	string getName() const;
	void setName(string newName);
	unsigned int setHandScore();
	unsigned int setHand2Score();
	void setCurrentMoney(unsigned int money);
	void setRoundsPlayed(unsigned int rounds);
	void setInitialMoney(unsigned int money);
	void addMoney(float value);
	void showStatistics();
	//bots currently bet's always the minValue
	virtual unsigned int bet(Table &table);
	void clearHand();
	void clearHand2();
	void setActualBet(unsigned int bet);
	unsigned int getActualBet();
	virtual string play(Table &table) = 0;
	virtual int getCurrentCount() const;
	virtual void addCount(Card &card1);
	virtual void resetCount();
	unsigned int getAge() const;
	void setAge(unsigned int age);
	void setOnTable(int tableID);
	int getOnTable() const;
	void removeCardFromFirstHandAndSetItOnSecondHand();


	
};

//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
class Bot0: public Player {
public:
	Bot0() {};
	Bot0(string name, unsigned int initialMoney);
	//play method
	string play(Table &table);
	bool takeInsurance(Table &table);
};

//////////////////////////////////////////////////// BOT 1 ////////////////////////////////////////////////////
class Bot1: public Player {
private:
	int currentCount;
public:
	unsigned int bet(Table &table);
	Bot1(string name, unsigned int initialMoney);
	//play method
	string play(Table &table);
	bool takeInsurance(Table &table);
	int getCurrentCount() const;
	void addCount(Card &card1);
	void resetCount();
	bool split( Dealer *dealerOfTable);
	virtual bool surrender(Table &table);
};

//////////////////////////////////////////////////// BOT 2 ////////////////////////////////////////////////////
class Bot2 : public Player {
private:
	int currentCount;
	unsigned int lastBetValue;
public:
	Bot2(string name, unsigned int initialMoney);
	unsigned int bet(Table &table);
	//play method
	string play(Table &table);
	bool takeInsurance(Table &table);
	bool split(Dealer *dealerOfTable);
	virtual bool surrender(Table &table);
	int getCurrentCount() const;
	void addCount(Card &card1);
	void resetCount();
	void setLastBetValue(unsigned int lastBet);
};

//////////////////////////////////////////////////// HUMAN ////////////////////////////////////////////////////
class Human: public Player {
public:
	Human(string name, unsigned int age);
	unsigned int bet(Table &table);
	string play(Table &table);
	bool takeInsurance(Table &table);
	bool split( Dealer *dealerOfTable);
};





