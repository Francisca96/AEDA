#pragma once

#include <exception>
#include <string>
#include <vector>

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

