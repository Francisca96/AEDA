#pragma once

#include <vector>
#include "Player.h"

using namespace std;
class Player;
class Table;

class Dealer {
private:
	static unsigned int nextID;
	unsigned int ID;
	vector<Card> hand;
	unsigned int handScore;
	unsigned int nextPlayer;
	vector<Card> deck;
	vector<Card> deckDiscarded;
	int TableID;

public:
	//Default constructor - creates a default deck of 52 cards
	Dealer();
	Dealer(unsigned int ID);
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
	vector<Card>& getDeck();
	vector<Card>& getHand();
	void addCardsToDeck(vector<Card> &cards);
	vector<Card>& getDiscardedDeck();
	unsigned int getHandScore() const;
	void clearDiscardedDeck();
	void clearHand();
	bool hasCardInHand(Card& c);
	string play(Table &table);
	unsigned int getID() const;
	void setTable(int tableID);
	int getTableOn() const;
	static void setNextID(unsigned int ID);
	static unsigned int getNextID();
};

class DealerNotExist {
private:
	int dealerID;
public:
	DealerNotExist(Dealer * dealer);
};

class DealerAlreadyExist {
private:
	int dealerID;
public:
	DealerAlreadyExist(Dealer * dealer);
	int getID() const;
};

class DealerIsOnTableAlready {
private:
	int dealerID;
public:
	DealerIsOnTableAlready(Dealer * dealer);
};

class DealerStillOnTable {
private:
	int dealerID;
	unsigned int tableID;
public:
	DealerStillOnTable(Dealer *dealer);
	unsigned int getTableID() const;
};