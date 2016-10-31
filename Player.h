#pragma once

#include <string>
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
	void canUseSideRules();
	unsigned int setHandScore();
	virtual unsigned int bet() = 0;
};

//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
class Bot0: public Player {
public:
	unsigned int bet();
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