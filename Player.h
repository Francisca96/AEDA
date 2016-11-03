#pragma once

#include <string>
#include <iomanip>
#include <vector>
#include "utils.h"
#include "Dealer.h"

using namespace std;
extern int bot1RunningCount;
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
	int currentCounting;

public:
	static void updateBot1RunningCount(Card &aCard) {
		string tempRank = aCard.rank;
		if (tempRank <= "6") {
			bot1RunningCount++;
		}
		else if (tempRank >= "A") {
			bot1RunningCount--;
		}
	}
	static void resetBot1RunningCount() {
		bot1RunningCount = 0;
	}
	static int getBot1RunningCount() {
		return bot1RunningCount;
	}
	void hit(Card newCard);
	void takeInsurance();
	void surrender();
	void split();
	void doubleDown();
	vector<Card> & getHand();
	unsigned int getHandSize();
	unsigned int getRoundsPlayed();
	unsigned int getCurrentMoney();
	unsigned int getAverageProfit();
	unsigned int getHandScore();
	unsigned int getInitialMoney();
	unsigned int getCurrentCounter();
	string getName();
	void setName(string newName);
	unsigned int setHandScore();
	void setCurrentMoney(unsigned int money);
	void setCurrentCounter(int counter);
	void setRoundsPlayed(unsigned int rounds);
	void setInitialMoney(unsigned int money);
	void addMoney(unsigned int value);
	void showStatistics();
	//bots currently bet's always the minValue
	virtual unsigned int bet(unsigned int minValue, unsigned int maxValue);
	virtual void clearHand();
	virtual string play(Dealer &dealerOfTable) = 0;
	
};

//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
class Bot0: public Player {
public:
	Bot0() {};
	Bot0(string name, unsigned int initialMoney);
	//play method
	string play(Dealer &dealerOfTable);
};

//////////////////////////////////////////////////// BOT 1 ////////////////////////////////////////////////////
class Bot1: public Player {
public:
	unsigned int bet(unsigned int minValue, unsigned int maxValue);
	Bot1(string name, unsigned int initialMoney);
	//play method
	string play(Dealer &dealerOfTable);
};

//////////////////////////////////////////////////// BOT 2 ////////////////////////////////////////////////////
class Bot2 : public Player {
public:
	//play method
	string play(Dealer &dealerOfTable);
};
//////////////////////////////////////////////////// HUMAN ////////////////////////////////////////////////////
class Human: public Player {
private:
	unsigned int age;
public:
	Human(string name, unsigned int age);
	unsigned int bet(unsigned int minValue, unsigned int maxValue);
	string play(Dealer &dealerOfTable);
};