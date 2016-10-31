#pragma once

#include <vector>
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
	Dealer(vector<Card> newDeck);
	void shuffleDeck();
	Card discard();
	void hit(Card newCard);
	void stand();
	unsigned int setHandScore();
};

