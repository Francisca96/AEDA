/**
 * @file	C:\Users\ineeve\Documents\GitHub\aeda-casino\Dealer.h
 *
 * @brief	Declares the dealer class.
 */

#pragma once

#include <vector>
#include "Player.h"


using namespace std;


class Player;
class Table;

/**
 * @class	Dealer
 *
 * @brief	A dealer.
 * 			The dealer is responsible to deal cards to the players and to himself.
 * 			He is the one that holds that deck and reshufles it. 
 *
 * @author	M. Francisca Pauperio
 * @date	19/11/2016
 */

class Dealer {
private:
	/** @brief	Identifier for the next Dealer. */
	static unsigned int nextID;
	/** @brief	The identifier. */
	unsigned int ID;
	/** @brief	The hand. */
	vector<Card> hand;
	/** @brief	The hand score. */
	unsigned int handScore;
	/** @brief	The next player.(Deprecated) */
	unsigned int nextPlayer;
	/** @brief	The deck. */
	vector<Card> deck;
	/** @brief	The discarded deck. */
	vector<Card> deckDiscarded;
	/** @brief	Identifier for the table that the dealer is on. */
	int TableID;

public: 

	/**
	 * @fn	Dealer::Dealer();
	 *
	 * @brief	Default constructor.
	 * 			Creates a default deck of 52 cards
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 */

	Dealer();

	/**
	 * @fn	Dealer::Dealer(unsigned int ID);
	 *
	 * @brief	Constructor.
	 * 			Creates a default deck of 52 cards.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param	ID	The identifier.
	 */

	Dealer(unsigned int ID);
	//Instanciates a new Dealer

	/**
	 * @fn	Dealer::Dealer(vector<Card> newDeck);
	 *
	 * @brief	Constructor.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param	newDeck	The new deck.
	 */

	Dealer(vector<Card> newDeck);
	//shuffles Dealer's Deck

	/**
	 * @fn	void Dealer::shuffleDeck();
	 *
	 * @brief	Shuffle deck.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 */

	void shuffleDeck();

	/**
	 * @fn	Card Dealer::discard(vector<Player *> players);
	 *
	 * @brief	Removes a Card from the end of the deck and returns it.
	 *			Additionaly pushes the Card to the deckDiscarded vector.
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param [in,out]	players A vector of pointers to the players.
	 *
	 * @return	The discarded Card.
	 */

	Card discard(vector<Player *> players);

	/**
	 * @fn	Card& Dealer::hit(vector<Player *> players);
	 *
	 * @brief	Places a Card in the Dealer hand and updates the handscore
	 *			
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param [in,out]	players A vector of pointers to the players.
	 *
	 * @return	A reference to the dealer's new Card.
	 */

	Card& hit(vector<Player *> players);
	/*Increases nextPlayer by 1;
	void stand();*/
	//Updates handScore

	/**
	 * @fn	unsigned int Dealer::setHandScore();
	 *
	 * @brief	Updates dealer's handscore.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @return	The updated handscore.
	 */

	unsigned int setHandScore();

	/**
	 * @fn	vector<Card>& Dealer::getDeck();
	 *
	 * @brief	Gets the deck.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @return	The deck.
	 */

	vector<Card>& getDeck();

	/**
	 * @fn	vector<Card>& Dealer::getHand();
	 *
	 * @brief	Gets the hand.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @return	The hand.
	 */

	vector<Card>& getHand();

	/**
	 * @fn	void Dealer::addCardsToDeck(vector<Card> &cards);
	 *
	 * @brief	Adds cards to the deck.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param [in,out]	cards	Vector of cards to be added to the deck.
	 */

	void addCardsToDeck(vector<Card> &cards);

	/**
	 * @fn	vector<Card>& Dealer::getDiscardedDeck();
	 *
	 * @brief	Gets discarded deck.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @return	The discarded deck.
	 */

	vector<Card>& getDiscardedDeck();

	/**
	 * @fn	unsigned int Dealer::getHandScore() const;
	 *
	 * @brief	Gets handscore.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @return	The handscore.
	 */

	unsigned int getHandScore() const;

	/**
	 * @fn	void Dealer::clearDiscardedDeck();
	 *
	 * @brief	Clears the discarded deck.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 */

	void clearDiscardedDeck();

	/**
	 * @fn	void Dealer::clearHand();
	 *
	 * @brief	Clears the hand.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 */

	void clearHand();

	/**
	 * @fn	bool Dealer::hasCardInHand(Card& c);
	 *
	 * @brief	Query if dealer has card in hand.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param [in,out]	c	The Card to process.
	 *
	 * @return	True if the card is in the dealer's hand, false if not.
	 */

	bool hasCardInHand(Card& c);

	/**
	 * @fn	string Dealer::play(Table &table);
	 *
	 * @brief	Calculates dealer next move.
	 * 			Dealer will stand if handscore >= 17.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table that the dealer is on.
	 *
	 * @return	A string: "hit" or "stand"
	 */

	string play(Table &table);

	/**
	 * @fn	unsigned int Dealer::getID() const;
	 *
	 * @brief	Gets the Dealer's identifier.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @return	The identifier.
	 */

	unsigned int getID() const;

	/**
	 * @fn	void Dealer::setTable(int tableID);
	 *
	 * @brief	Associates a table to this dealer.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param	tableID	Identifier for the table.
	 */

	void setTable(int tableID);

	/**
	 * @fn	int Dealer::getTableOn() const;
	 *
	 * @brief	Gets identifier of the table that the dealer is on.
	 * 			
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @return	The table that the dealer is on. -1 if Dealer is not on any table.
	 */

	int getTableOn() const;

	/**
	 * @fn	static void Dealer::setNextID(unsigned int ID);
	 *
	 * @brief	Sets next identifier.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param	ID	The identifier.
	 */

	static void setNextID(unsigned int ID);

	/**
	 * @fn	static unsigned int Dealer::getNextID();
	 *
	 * @brief	Gets the next identifier.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @return	The next identifier.
	 */

	static unsigned int getNextID();
};

/**
 * @class	DealerNotExistException
 *
 * @brief	Exception for signalling that the dealer doest not exist.
 *
 * @author	M. Francisca Pauperio
 * @date	19/11/2016
 */

class DealerNotExistException {
private:
	/** @brief	Identifier for the dealer. */
	int dealerID;
public:

	/**
	 * @fn	DealerNotExistException::DealerNotExistException(Dealer * dealer);
	 *
	 * @brief	Constructor.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealer	Pointer to the dealer.
	 */

	DealerNotExistException(Dealer * dealer);
};

/**
 * @class	DealerAlreadyExistException
 *
 * @brief	Exception for signalling that the dealer already exists.
 *
 * @author	M. Francisca Pauperio
 * @date	19/11/2016
 */

class DealerAlreadyExistException {
private:
	/** @brief	Identifier for the dealer. */
	int dealerID;
public:

	/**
	 * @fn	DealerAlreadyExistException::DealerAlreadyExistException(Dealer * dealer);
	 *
	 * @brief	Constructor.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealer	A pointer to the dealer.
	 */

	DealerAlreadyExistException(Dealer * dealer);

	/**
	 * @fn	int DealerAlreadyExistException::getID() const;
	 *
	 * @brief	Gets the identifier.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @return	The identifier.
	 */

	int getID() const;
};

/**
 * @class	DealerIsOnTableAlreadyException
 *
 * @brief	Exception for signalling that the dealer is already on a table.
 *
 * @author	M. Francisca Pauperio
 * @date	19/11/2016
 */

class DealerIsOnTableAlreadyException {
private:
	/** @brief	Identifier for the dealer. */
	int dealerID;
public:

	/**
	 * @fn	DealerIsOnTableAlreadyException::DealerIsOnTableAlreadyException(Dealer * dealer);
	 *
	 * @brief	Constructor.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealer	Pointer to the dealer.
	 */

	DealerIsOnTableAlreadyException(Dealer * dealer);
};

/**
 * @class	DealerStillOnTableException
 *
 * @brief	Exception for signalling that dealer is still on a table.
 *
 * @author	M. Francisca Pauperio
 * @date	19/11/2016
 */

class DealerStillOnTableException {
private:
	/** @brief	Identifier for the dealer. */
	int dealerID;
	/** @brief	Identifier for the table. */
	unsigned int tableID;
public:

	/**
	 * @fn	DealerStillOnTableException::DealerStillOnTableException(Dealer *dealer);
	 *
	 * @brief	Constructor.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealer	Pointer to the dealer.
	 */

	DealerStillOnTableException(Dealer *dealer);

	/**
	 * @fn	unsigned int DealerStillOnTableException::getTableID() const;
	 *
	 * @brief	Gets table identifier.
	 *
	 * @author	M. Francisca Pauperio
	 * @date	19/11/2016
	 *
	 * @return	The table identifier.
	 */

	unsigned int getTableID() const;
};