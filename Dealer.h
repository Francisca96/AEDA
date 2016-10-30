#pragma once

#include <vector>
#include "Table.h"
#include "utils.h"

using namespace std;

class Dealer {
private:
	vector<Card> hand;
	unsigned int handScore;
	unsigned int nextPlayer;
	vector<Card> deck;
	vector<Card> deckDiscarded;

public:
	Dealer();
	void shuffleDeck();
	void hit();
	void stand();
	unsigned int handScore();
};

