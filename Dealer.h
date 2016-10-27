#pragma once

#include <exception>
#include <string>
using namespace std;

struct Carta {

};

class Dealer {
	vector<Carta*> deck;
	vector<Carta*> hand;

public:
	void hit();
	void stand();
};

