#pragma once

#include <exception>
#include <string>
#include <vector>

using namespace std;

struct Card {
	string rank;
	char suits;
	unsigned int score;
};

class Dealer {
private:
	vector<Card> deck;
	vector<Card> deckDiscarded;
	vector<Card> hand;
	unsigned handScore;
public:
	void hit();
	void stand();
	unsigned int handScore;
};

