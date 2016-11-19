/**
 * @file	C:\Users\ineeve\Documents\GitHub\aeda-casino\Table.h
 *
 * @brief	Declares the table class.
 */

#pragma once

#include <vector>
#include "Dealer.h"
#include "cmdUI.h"

/**
 * @class	Player
 *
 * @brief	A player, human or bot.
 *
 * @author	Renato Campos
 * @date	18/11/2016
 */

class Player;

/**
 * @class	Dealer
 *
 * @brief	A Casino's dealer.
 *
 * @author	Renato Campos
 * @date	18/11/2016
 */

class Dealer;

/**
 * @class	Table
 *
 * @brief	A table.
 *
 * @author	Renato Campos
 * @date	18/11/2016
 */

class Table;

using namespace std;


/**
 * @class	TooManyPlayersException
 *
 * @brief	Exception for signalling too many players in a table errors.
 *
 * @author	Renato Campos
 * @date	18/11/2016
 */

class TooManyPlayersException {
private:
	/** @brief	The maximum number of players. */
	unsigned int maxNumberOfPlayers;
	/** @brief	The actual number of players. */
	unsigned int actualNumOfPlayers;
public:

	/**
	 * @fn	TooManyPlayersException::TooManyPlayersException(unsigned int maxNumberOfPlayers, unsigned int actualNumOfPlayers);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param	maxNumberOfPlayers	The maximum number of players.
	 * @param	actualNumOfPlayers	The actual number of players.
	 */

	TooManyPlayersException(unsigned int maxNumberOfPlayers, unsigned int actualNumOfPlayers);

	/**
	 * @fn	void TooManyPlayersException::what();
	 *
	 * @brief	Displays information about this exception.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 */

	void what();
};

/**
 * @class	NoPlayersOnTableException
 *
 * @brief	Exception for signalling no players on table errors.
 *
 * @author	Renato Campos
 * @date	18/11/2016
 */

class NoPlayersOnTableException {
private:
	/** @brief	Identifier for the table. */
	unsigned int tableID;
public:

	/**
	 * @fn	NoPlayersOnTableException::NoPlayersOnTableException(Table *NoPlayersOnTableException);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param [in]	NoPlayersOnTableException
	 */

	NoPlayersOnTableException(Table *NoPlayersOnTableException);

	/**
	 * @fn	unsigned int NoPlayersOnTableException::getID() const;
	 *
	 * @brief	Gets the identifier.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @return	The identifier.
	 */

	unsigned int getID() const;
};

/**
 * @class	Table
 *
 * @brief	A table.
 *
 * @author	Renato Campos
 * @date	18/11/2016
 */

class Table {
private:
	/** @brief	Identifier of the next table. */
	static unsigned int nextID;
	//unsigned int roundsLeft;
	/** @brief	The minimum bet. */
	unsigned int minBet;
	/** @brief	The maximum bet. */
	unsigned int maxBet;
	/** @brief	The initial money. */
	unsigned int initialMoney;
	/** @brief	The money of the table. */
	float moneyOfTable;
	/** @brief	The maximum number of players. */
	unsigned int maxNumberOfPlayers;
	/** @brief	Identifier for the table. */
	int tableID;
	/** @brief	The dealer of table. */
	Dealer * dealerOfTable;
	/** @brief	The players. */
	vector<Player*> players;
	/** @brief	The actual players. */
	vector<Player*> actualPlayers;

public:

	/**
	 * @fn	Table::Table(int ID);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param	ID	The identifier.
	 */

	Table(int ID);

	/**
	 * @fn	Table::Table( unsigned int, unsigned int, unsigned int, unsigned int, Dealer*);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param 		  	minBet		  	The minimum bet.
	 * @param 		  	maxBet		  	The maximum bet.
	 * @param 		  	moneyOfTable		  	Initial money of the table.
	 * @param 		  	numberOfMaxPlayers	  	The maximum number of players allowed to join the table.
	 * @param [in,out]	newDealer			Pointer to the Dealer to be assigned to this table.
	 */

	Table( unsigned int , unsigned int, unsigned int, unsigned int, Dealer*); // Table() is a construct of a class Table with 6 args(minBet, maxBet, moneyOfTbale, maxNumberOfPlayers, dealerOfTable)

	/**
	 * @fn	Table::~Table();
	 *
	 * @brief	Destructor.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 */

	~Table();

	/**
	 * @fn	void Table::setMinBet(unsigned int minBet);
	 *
	 * @brief	Sets minimum bet.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param	minBet	The minimum bet.
	 */

	void setMinBet(unsigned int minBet);

	/**
	 * @fn	void Table::setMaxBet(unsigned int maxBet);
	 *
	 * @brief	Sets maximum bet.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param	maxBet	The maximum bet.
	 */

	void setMaxBet(unsigned int maxBet);

	/**
	 * @fn	void Table::setDealer(Dealer *dealerOfTable);
	 *
	 * @brief	Sets a dealer.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param [in,out]	dealerOfTable	Pointer to the dealer of table.
	 */

	void setDealer(Dealer *dealerOfTable);

	/**
	 * @fn	void Table::setID(int ID);
	 *
	 * @brief	Sets an identifier.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param	ID	The identifier.
	 */

	void setID(int ID);

	/**
	 * @fn	void Table::addPlayer(Player *newPlayer);
	 *
	 * @brief	Adds a player to this table.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param [in,out]	newPlayer	Pointer to the new player.
	 */

	void addPlayer(Player *newPlayer);

	/**
	 * @fn	void Table::addPlayers(vector <Player *> newPlayers);
	 *
	 * @brief	Adds the players to this table.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param [in,out]	newPlayers	Vector of pointers to the new players.
	 */

	void addPlayers(vector <Player *> newPlayers);

	/**
	 * @fn	void Table::removePlayer(string &name);
	 *
	 * @brief	Removes the player described by his name.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param [in]	name	The player's name.
	 */

	void removePlayer(string &name);

	/**
	 * @fn	void Table::play();
	 *
	 * @brief	Plays Blackjack allowing humans to play against bots and other humans too.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 */

	void play();

	/**
	 * @fn	void Table::simulation(unsigned int roundsLeft);
	 *
	 * @brief	Simulates a blackjack game for the given rounds.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param	roundsLeft	The rounds to be played.
	 */

	void simulation(unsigned int roundsLeft);

	/**
	 * @fn	unsigned int Table::getInitialMoney() const;
	 *
	 * @brief	Gets initial money of this table.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @return	The initial money.
	 */

	unsigned int getInitialMoney() const;

	/**
	 * @fn	int Table::getTableID() const;
	 *
	 * @brief	Gets table identifier.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @return	The table identifier.
	 */

	int getTableID() const;

	/**
	 * @fn	unsigned int Table::getMinBet() const;
	 *
	 * @brief	Gets minimum bet.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @return	The minimum bet.
	 */

	unsigned int getMinBet() const;

	/**
	 * @fn	unsigned int Table::getMaxBet() const;
	 *
	 * @brief	Gets maximum bet.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @return	The maximum bet.
	 */

	unsigned int getMaxBet() const;

	/**
	 * @fn	unsigned int Table::getNumberMaxOfPlayers() const;
	 *
	 * @brief	Gets maximum number of players.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @return	The maximum number of players.
	 */

	unsigned int getNumberMaxOfPlayers() const;

	/**
	 * @fn	void Table::getInitialBets();
	 *
	 * @brief	Ask players for their initial bets.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 */

	void getInitialBets();

	/**
	 * @fn	Dealer * Table::getDealer();
	 *
	 * @brief	Gets the dealer.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @return	A pointer to the dealer.
	 */

	Dealer * getDealer();

	/**
	 * @fn	vector <Player *> Table::getPlayers() const;
	 *
	 * @brief	Gets the players.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @return	A vector of pointers to the players in the table.
	 */

	vector <Player *> getPlayers() const;

	/**
	 * @fn	void Table::dealOneCardToAllPlayers();
	 *
	 * @brief	Deal one card to all players.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 */

	void dealOneCardToAllPlayers();

	/**
	 * @fn	void Table::payToPlayer(Player* player1, float value);
	 *
	 * @brief	Pay to player a given amount.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param [in,out] player1	A pointer to a player.
	 * @param 		  	value  	The value to pay to the player.
	 */

	void payToPlayer(Player* player1, float value);

	/**
	 * @fn	unsigned int Table::restartDeck();
	 *
	 * @brief	Restart deck.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @return	0 - deck restarted sucessfully; 1 - deck not ready to be restarted.  
	 */

	unsigned int restartDeck();

	/**
	 * @fn	void Table::showTableInfo(pair <short, short> xy);
	 *
	 * @brief	Shows the table information.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param	xy - the coordinates to set the cursor.
	 */

	void showTableInfo(pair <short, short> xy);

	/**
	 * @fn	void Table::kickPlayer(unsigned int index);
	 *
	 * @brief	Kicks a player.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param	index	Zero-based index of the player to kick.
	 */

	void kickPlayer(unsigned int index);

	/**
	 * @fn	void Table::resetBot1Counters();
	 *
	 * @brief	Resets All bots of type 1 counters.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 */

	void resetBot1Counters();

	/**
	 * @fn	void Table::addMoneyToTable(unsigned int money);
	 *
	 * @brief	Adds money to this table.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param	money	The amount of money to be added.
	 */

	void addMoneyToTable(unsigned int money);

	/**
	 * @fn	float Table::closeTable();
	 *
	 * @brief	Closes the table. Resets all bot counters.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @return	moneyOfTable The final money of the table that should be added to the casino.
	 */

	float closeTable();

	/**
	 * @fn	static void Table::setNextID(unsigned int tableNextID);
	 *
	 * @brief	Sets next identifier.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @param	tableNextID	Identifier for the next table.
	 */

	static void setNextID(unsigned int tableNextID);

	/**
	 * @fn	static unsigned int Table::getNextId();
	 *
	 * @brief	Gets the next identifier of the tables.
	 *
	 * @author	Renato Campos
	 * @date	18/11/2016
	 *
	 * @return	The next identifier.
	 */

	static unsigned int getNextId();
	
};