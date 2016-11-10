#pragma once

#include <string>
#include <iomanip>
#include <vector>
#include "utils.h"
#include "Dealer.h"
#include "Table.h"

using namespace std;

class Dealer;

class NameTooShort {
public:
	void what();
};
class TooYoung {
public:
	void what();
};
class Player {
private:
	
	string name;
	unsigned int initialMoney;
	float currentMoney;
	vector <Card> hand;
	unsigned int handScore;
	unsigned int roundsPlayed;
	float averageProfit;

public:
	void hit(Card newCard);
	virtual bool takeInsurance(Table &table);
	void surrender();
	virtual bool split(vector<Card> * secHand);
	void doubleDown();
	vector<Card> & getHand();
	unsigned int getHandSize();
	unsigned int getRoundsPlayed();
	unsigned int getCurrentMoney();
	unsigned int getAverageProfit();
	unsigned int getHandScore();
	unsigned int getInitialMoney();
	string getName();
	void setName(string newName);
	unsigned int setHandScore();
	void setCurrentMoney(unsigned int money);
	void setRoundsPlayed(unsigned int rounds);
	void setInitialMoney(unsigned int money);
	void addMoney(unsigned int value);
	void showStatistics();
	//bots currently bet's always the minValue
	virtual unsigned int bet(Table &currentTable);
	virtual void clearHand();
	virtual string play(Dealer &dealerOfTable) = 0;
	virtual int getCurrentCount() const;
	virtual void addCount(Card &card1);
	virtual void resetCount();
	
};

//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
class Bot0: public Player {
public:
	Bot0() {};
	Bot0(string name, unsigned int initialMoney);
	//play method
	string play(Dealer &dealerOfTable);
	bool takeInsurance(Table &currentTable);
};

//////////////////////////////////////////////////// BOT 1 ////////////////////////////////////////////////////
class Bot1: public Player {
private:
	int currentCount;
public:
	unsigned int bet(Table &currentTable);
	Bot1(string name, unsigned int initialMoney);
	//play method
	string play(Dealer &dealerOfTable);
	bool takeInsurance(Table &currentTable);
	int getCurrentCount() const;
	void addCount(Card &card1);
	void resetCount();
	bool split(vector<Card> * secHand);
};

//////////////////////////////////////////////////// BOT 2 ////////////////////////////////////////////////////
class Bot2 : public Player {
public:
	//play method
	string play(Dealer &dealerOfTable);
	bool takeInsurance(Table &table);
	bool split(vector<Card> * secHand);
};

//////////////////////////////////////////////////// HUMAN ////////////////////////////////////////////////////
class Human: public Player {
private:
	unsigned int age;
public:
	Human(string name, unsigned int age);
	unsigned int bet(Table &currentTable);
	string play(Dealer &dealerOfTable);
	unsigned int bet(Table &table);
	string play(Table &table);
	bool takeInsurance(Table &table);
	bool split(vector<Card> * secHand);
};