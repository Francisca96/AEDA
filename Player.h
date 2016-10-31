#pragma once

#include <string>
#include <vector>
#include "utils.h"

using namespace std;

class Player {
private:
	string name;
	unsigned int initialMoney;
	unsigned int currentMoney;
	vector <Card> hand;
	unsigned int handScore;
	int averageProfit;

public:
	void hit(Card newCard);
	void takeInsurance();
	void surrender();
	void split();
	void doubleDown();
	unsigned int setHandScore();
	unsigned int getHandScore();
	void setCurrentMoney(unsigned int money);
	unsigned int getCurrentMoney();
	virtual unsigned int bet() = 0;
	virtual unsigned int play() = 0;
};

//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
class Bot0: public Player {
public:
	//bot 0 currently bet's always the minValue
	unsigned int bet(unsigned int minValue, unsigned int maxValue);
	//play method
	unsigned int play();
};

//////////////////////////////////////////////////// BOT 1 ////////////////////////////////////////////////////
class Bot1: public Player {
public:
	unsigned int bet();
};

//////////////////////////////////////////////////// BOT 2 ////////////////////////////////////////////////////
class Bot2: public Player {
public:
	unsigned int bet();
};

//////////////////////////////////////////////////// HUMAN ////////////////////////////////////////////////////
class Human: public Player {
public:
	unsigned int bet();
};