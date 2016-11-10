#pragma once

#include <vector>
#include "utils.h"
#include "Player.h"

using namespace std;

class Dealer {
private:
	static unsigned int nextID;
	unsigned int ID;
	vector<Card> hand;
	unsigned int handScore;
	unsigned int nextPlayer;
	vector<Card> deck;
	vector<Card> deckDiscarded;

public:
	//Default constructor - creates a default deck of 52 cards
	Dealer();
	//Instanciates a new Dealer
	Dealer(vector<Card> newDeck);
	//shuffles Dealer's Deck
	void shuffleDeck();
	//Removes a Card from the end of the deck and returns it. Additionaly pushes the Card to the deckDiscarded vector
	Card discard(vector<Player *> players);
	//Places a Card in the Dealer hand and updates the handscore
	Card& hit(vector<Player *> players);
	/*Increases nextPlayer by 1;
	void stand();*/
	//Updates handScore
	unsigned int setHandScore();
	//get deck size to see if reshuffle is needed
	vector<Card>& getDeck() const;
	vector<Card>& getHand() const;
	void addCardsToDeck(vector<Card> &cards);
	vector<Card>& getDiscardedDeck() const;
	unsigned int getHandScore() const;
	void clearDiscardedDeck();
	void clearHand();
	bool hasCardInHand(Card& c);
	string play();
};

