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
	vector<Card> visibleCards;
	//Instanciates a new Dealer
	Dealer(vector<Card> newDeck);
	//shuffles Dealer's Deck
	void shuffleDeck();
	//Removes a Card from the end of the deck and returns it. Additionaly pushes the Card to the deckDiscarded vector
	Card discard();
	//Places a Card in the Dealer hand and updates the handscore
	void hit(Card newCard);
	//Increases nextPlayer by 1;
	void stand();
	//Updates handScore
	unsigned int setHandScore();
	//Receive Card
	void receiveCard();
	//Show Cards
	void setAllCardsVisible();
};

