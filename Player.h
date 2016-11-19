/**
 * @file	C:\Users\ineeve\Documents\GitHub\aeda-casino\Player.h
 *
 * @brief	Declares the player class.
 */

#pragma once

#include <string>
#include <iomanip>
#include <vector>
#include "utils.h"
#include "Table.h"

using namespace std;


class Table;

class Dealer;

class Player;

/**
 * @class	NameTooShortException
 *
 * @brief	Exception for signalling too short names errors.
 *			The name is considered to be too short if it has
 *			less than 3 characters.
 * @author	Ineeve
 * @date	19/11/2016
 */

class NameTooShortException {
public:

	/**
	 * @fn	void NameTooShortException::what();
	 *
	 * @brief	Displays on terminal what throwed this exception.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void what();
};

/**
 * @class	TooYoungException
 *
 * @brief	Exception for signalling age errors.
 * 			A player is considered to be too young
 * 			if he is less than 18 years old.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class TooYoungException {
public:

	/**
	 * @fn	void TooYoungException::what();
	 *
	 * @brief	Displays on terminal what throwed this exception.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void what();
};

/**
 * @class	PlayerAlreadyExistException
 *
 * @brief	Exception for signalling that the player already exists.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class PlayerAlreadyExistException {
private:
	/** @brief	The name. */
	string name;
public:

	/**
	 * @fn	PlayerAlreadyExistException::PlayerAlreadyExistException(Player *player);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	player	Pointer to the player.
	 */

	PlayerAlreadyExistException(Player *player);
};

/**
 * @class	PlayerNotExistException
 *
 * @brief	Exception for signalling that the player does not exist.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class PlayerNotExistException {
private:
	/** @brief	The player's name. */
	string name;
public:

	/**
	 * @fn	PlayerNotExistException::PlayerNotExistException(string name);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	name	The player's name.
	 */

	PlayerNotExistException(string name);
};

/**
 * @class	PlayerStillOnTableException
 *
 * @brief	Exception for signalling that the player is still on table.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class PlayerStillOnTableException {
private:
	/** @brief	The name. */
	string name;
	/** @brief	Identifier for the table. */
	unsigned int tableID;
public:

	/**
	 * @fn	PlayerStillOnTableException::PlayerStillOnTableException(Player *player);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	player	Pointer to the player.
	 */

	PlayerStillOnTableException(Player *player);

	/**
	 * @fn	unsigned int PlayerStillOnTableException::getTableId() const;
	 *
	 * @brief	Gets table identifier.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The table identifier.
	 */

	unsigned int getTableId() const;
};

/**
 * @class	PlayerIsntOnTableException
 *
 * @brief	Exception for signalling that the player is not on the table.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class PlayerIsntOnTableException {
private:
	/** @brief	The player's name. */
	string name;
public:

	/**
	 * @fn	PlayerIsntOnTableException::PlayerIsntOnTableException(string &name);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	name	The player's name.
	 */

	PlayerIsntOnTableException(string &name);
};

/**
 * @class	HumanOnTableException
 *
 * @brief	Exception for signalling that there is a human on the table.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class HumanOnTableException {
private:
	/** @brief	The human name. */
	string name;
public:

	/**
	 * @fn	HumanOnTableException::HumanOnTableException(Player *player);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	player	Pointer to the player.
	 */

	HumanOnTableException(Player *player);
};

/**
 * @class	Player
 *
 * @brief	A player.
 *			Abstract Class.
 *			Player is the base class
 * @author	Ineeve
 * @date	19/11/2016
 */

class Player {
private:
	/** @brief	The name. */
	string name;
	/** @brief	The initial money. */
	unsigned int initialMoney;
	/** @brief	The current money. */
	float currentMoney;

	/**
	 * @property	vector <Card> hand
	 *
	 * @brief	Gets the hand.
	 *
	 * @return	The hand.
	 */

	vector <Card> hand;

	/**
	 * @property	vector <Card> hand2
	 *
	 * @brief	Gets the second hand.
	 * 			A player only has second hand
	 * 			if he decides to split.
	 *
	 * @return	The second hand.
	 */

	vector <Card> hand2;
	/** @brief	The hand score. */
	unsigned int handScore;
	/** @brief	The second hand score. */
	unsigned int hand2Score;
	/** @brief	The rounds played. */
	unsigned int roundsPlayed;
	/** @brief	The average profit. */
	float averageProfit;
	/** @brief	The age. */
	unsigned int age;
	/** @brief	Like a boolean that tells us if the player is on a table. */
	int onTable;
	/** @brief	The actual bet. */
	int actualBet;
public:

	/**
	 * @fn	void Player::hit(Card newCard);
	 *
	 * @brief	Hits the given new card.
	 *			Saves the card on the hand.
	 *			Updates the handscore.
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	newCard	The new card.
	 */

	void hit(Card newCard);

	/**
	 * @fn	virtual bool Player::takeInsurance(Table &table);
	 *
	 * @brief	Take insurance.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table that the player is on.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	virtual bool takeInsurance(Table &table);

	/**
	 * @fn	virtual bool Player::surrender(Table &table);
	 *
	 * @brief	Surrenders or not.
	 *			When this method is called, it will check
	 *			if the player wants to surrender.
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table that the player is on.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	virtual bool surrender(Table &table);

	/**
	 * @fn	virtual bool Player::split(Dealer *dealerOfTable);
	 *
	 * @brief	Splits his hand or not.
	 * 			When this method is called it will apply an algorithm
	 * 			depending on the type of player, to check if the player
	 * 			wants to split his hand.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealerOfTable	Pointer to the dealer of the table.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	virtual bool split(Dealer *dealerOfTable);

	/**
	 * @fn	void Player::doubleDown();
	 *
	 * @brief	Double down.
	 *			Doubles down the current bet.
	 *			When a player doubles down, he will hit a new card, double is bet,
	 *			and won't be allowed to play anymore until the end of the round.
	 *			
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void doubleDown();

	/**
	 * @fn	vector<Card> & Player::getHand();
	 *
	 * @brief	Gets the hand.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The hand.
	 */

	vector<Card> & getHand();

	/**
	 * @fn	vector<Card> & Player::getHand2();
	 *
	 * @brief	Gets the second hand.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The second hand.
	 */

	vector<Card> & getHand2();

	/**
	 * @fn	unsigned int Player::getHandSize() const;
	 *
	 * @brief	Gets hand size.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The hand size.
	 */

	unsigned int getHandSize() const;

	/**
	 * @fn	unsigned int Player::getRoundsPlayed() const;
	 *
	 * @brief	Gets rounds played.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The rounds played.
	 */

	unsigned int getRoundsPlayed() const;

	/**
	 * @fn	unsigned int Player::getCurrentMoney() const;
	 *
	 * @brief	Gets current money.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The current money.
	 */

	unsigned int getCurrentMoney() const;

	/**
	 * @fn	float Player::getAverageProfit() const;
	 *
	 * @brief	Gets average profit.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The average profit.
	 */

	float getAverageProfit() const;

	/**
	 * @fn	unsigned int Player::getHandScore() const;
	 *
	 * @brief	Gets hand score.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The hand score.
	 */

	unsigned int getHandScore() const;

	/**
	 * @fn	unsigned int Player::getHand2Score() const;
	 *
	 * @brief	Gets second hand score.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The second hand score.
	 */

	unsigned int getHand2Score() const;

	/**
	 * @fn	unsigned int Player::getInitialMoney() const;
	 *
	 * @brief	Gets initial money.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The initial money.
	 */

	unsigned int getInitialMoney() const;

	/**
	 * @fn	string Player::getName() const;
	 *
	 * @brief	Gets the name.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The name.
	 */

	string getName() const;

	/**
	 * @fn	void Player::setName(string newName);
	 *
	 * @brief	Sets a name.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	newName	Name of the player.
	 */

	void setName(string newName);

	/**
	 * @fn	unsigned int Player::setHandScore();
	 *
	 * @brief	Sets hand score.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The current hand score.
	 */

	unsigned int setHandScore();

	/**
	 * @fn	unsigned int Player::setHand2Score();
	 *
	 * @brief	Sets second hand score.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The second hand score.
	 */

	unsigned int setHand2Score();

	/**
	 * @fn	void Player::setCurrentMoney(unsigned int money);
	 *
	 * @brief	Sets current money.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	money	The money.
	 */

	void setCurrentMoney(unsigned int money);

	/**
	 * @fn	void Player::setRoundsPlayed(unsigned int rounds);
	 *
	 * @brief	Sets rounds played.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	rounds	The number of rounds.
	 */

	void setRoundsPlayed(unsigned int rounds);

	/**
	 * @fn	void Player::setInitialMoney(unsigned int money);
	 *
	 * @brief	Sets initial money.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	money	The money.
	 */

	void setInitialMoney(unsigned int money);

	/**
	 * @fn	void Player::addMoney(float value);
	 *
	 * @brief	Adds money to the player.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	value	The amount of money to be added.
	 */

	void addMoney(float value);

	/**
	 * @fn	void Player::showStatistics();
	 *
	 * @brief	Shows the statistics.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void showStatistics();

	/**
	 * @fn	virtual unsigned int Player::bet(Table &table);
	 *
	 * @brief	Bets an amount of money.
	 * 			If player is a kind of bot, it will bet accordingly to algorithms that are available on the internet
	 * 
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	An int.
	 */

	virtual unsigned int bet(Table &table);

	/**
	 * @fn	void Player::clearHand();
	 *
	 * @brief	Clears the hand.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void clearHand();

	/**
	 * @fn	void Player::clearHand2();
	 *
	 * @brief	Clears the second hand.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void clearHand2();

	/**
	 * @fn	void Player::setActualBet(unsigned int bet);
	 *
	 * @brief	Sets actual bet.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	bet	The money to bet.
	 */

	void setActualBet(unsigned int bet);

	/**
	 * @fn	unsigned int Player::getActualBet();
	 *
	 * @brief	Gets actual bet.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The actual bet.
	 */

	unsigned int getActualBet();

	/**
	 * @fn	virtual string Player::play(Table &table) = 0;
	 *
	 * @brief	Play consists of a method that decides what is the best move.
	 * 			All the bots have different implementations of this method.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table that the player is on.
	 *
	 * @return	A string with the option selected, "hit","stand" or "double".
	 */

	virtual string play(Table &table) = 0;

	/**
	 * @fn	virtual int Player::getCurrentCount() const;
	 *
	 * @brief	Gets current count.
	 *			Different kinds of players may hold different counts.
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The current count.
	 */

	virtual int getCurrentCount() const;

	/**
	 * @fn	virtual void Player::addCount(Card &card1);
	 *
	 * @brief	Updates the current count with a given card.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	card1	The card that will try to update the count.
	 */

	virtual void addCount(Card &card1);

	/**
	 * @fn	virtual void Player::resetCount();
	 *
	 * @brief	Resets the current count.
	 * 			Should be called when the deck is reshuffled or the table closes.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	virtual void resetCount();

	/**
	 * @fn	unsigned int Player::getAge() const;
	 *
	 * @brief	Gets the age.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The player's age.
	 */

	unsigned int getAge() const;

	/**
	 * @fn	void Player::setAge(unsigned int age);
	 *
	 * @brief	Sets an age.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	age	The age.
	 */

	void setAge(unsigned int age);

	/**
	 * @fn	void Player::setOnTable(int tableID);
	 *
	 * @brief	Sits on a table.
	 *			-1 if the player is not on any table.
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	tableID	Identifier for the table.
	 */

	void setOnTable(int tableID);

	/**
	 * @fn	int Player::getOnTable() const;
	 *
	 * @brief	Gets if the player is on table or not.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	.
	 */

	int getOnTable() const;

	/**
	 * @fn	void Player::removeCardFromFirstHandAndSetItOnSecondHand();
	 *
	 * @brief	Removes the card from first hand set iterator on second hand.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void removeCardFromFirstHandAndSetItOnSecondHand();


	
};

/**
 * @class	Bot0
 *
 * @brief	///////////////////////////////////////////////// BOT 0
 * 			////////////////////////////////////////////////////.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class Bot0: public Player {
public:

	/**
	 * @fn	Bot0::Bot0()
	 *
	 * @brief	Default constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	Bot0() {};

	/**
	 * @fn	Bot0::Bot0(string name, unsigned int initialMoney);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	name			The name.
	 * @param	initialMoney	The initial money.
	 */

	Bot0(string name, unsigned int initialMoney);
	//play method

	/**
	 * @fn	string Bot0::play(Table &table);
	 *
	 * @brief	Plays the given table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	A string.
	 */

	string play(Table &table);

	/**
	 * @fn	bool Bot0::takeInsurance(Table &table);
	 *
	 * @brief	Take insurance.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool takeInsurance(Table &table);
};

/**
 * @class	Bot1
 *
 * @brief	///////////////////////////////////////////////// BOT 1
 * 			////////////////////////////////////////////////////.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class Bot1: public Player {
private:
	/** @brief	Number of currents. */
	int currentCount;
public:

	/**
	 * @fn	unsigned int Bot1::bet(Table &table);
	 *
	 * @brief	Bets the given table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	An int.
	 */

	unsigned int bet(Table &table);

	/**
	 * @fn	Bot1::Bot1(string name, unsigned int initialMoney);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	name			The name.
	 * @param	initialMoney	The initial money.
	 */

	Bot1(string name, unsigned int initialMoney);
	//play method

	/**
	 * @fn	string Bot1::play(Table &table);
	 *
	 * @brief	Plays the given table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	A string.
	 */

	string play(Table &table);

	/**
	 * @fn	bool Bot1::takeInsurance(Table &table);
	 *
	 * @brief	Take insurance.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool takeInsurance(Table &table);

	/**
	 * @fn	int Bot1::getCurrentCount() const;
	 *
	 * @brief	Gets current count.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The current count.
	 */

	int getCurrentCount() const;

	/**
	 * @fn	void Bot1::addCount(Card &card1);
	 *
	 * @brief	Adds a count.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	card1	The first card.
	 */

	void addCount(Card &card1);

	/**
	 * @fn	void Bot1::resetCount();
	 *
	 * @brief	Resets the count.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void resetCount();

	/**
	 * @fn	bool Bot1::split( Dealer *dealerOfTable);
	 *
	 * @brief	Splits the given dealer of table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealerOfTable	If non-null, the dealer of table.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool split( Dealer *dealerOfTable);

	/**
	 * @fn	virtual bool Bot1::surrender(Table &table);
	 *
	 * @brief	Surrenders the given table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	virtual bool surrender(Table &table);
};

/**
 * @class	Bot2
 *
 * @brief	///////////////////////////////////////////////// BOT 2
 * 			////////////////////////////////////////////////////.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class Bot2 : public Player {
private:
	/** @brief	Number of currents. */
	int currentCount;
	/** @brief	The last bet value. */
	unsigned int lastBetValue;
public:

	/**
	 * @fn	Bot2::Bot2(string name, unsigned int initialMoney);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	name			The name.
	 * @param	initialMoney	The initial money.
	 */

	Bot2(string name, unsigned int initialMoney);

	/**
	 * @fn	unsigned int Bot2::bet(Table &table);
	 *
	 * @brief	Bets the given table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	An int.
	 */

	unsigned int bet(Table &table);
	//play method

	/**
	 * @fn	string Bot2::play(Table &table);
	 *
	 * @brief	Plays the given table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	A string.
	 */

	string play(Table &table);

	/**
	 * @fn	bool Bot2::takeInsurance(Table &table);
	 *
	 * @brief	Take insurance.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool takeInsurance(Table &table);

	/**
	 * @fn	bool Bot2::split(Dealer *dealerOfTable);
	 *
	 * @brief	Splits the given dealer of table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealerOfTable	If non-null, the dealer of table.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool split(Dealer *dealerOfTable);

	/**
	 * @fn	virtual bool Bot2::surrender(Table &table);
	 *
	 * @brief	Surrenders the given table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	virtual bool surrender(Table &table);

	/**
	 * @fn	int Bot2::getCurrentCount() const;
	 *
	 * @brief	Gets current count.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	The current count.
	 */

	int getCurrentCount() const;

	/**
	 * @fn	void Bot2::addCount(Card &card1);
	 *
	 * @brief	Adds a count.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	card1	The first card.
	 */

	void addCount(Card &card1);

	/**
	 * @fn	void Bot2::resetCount();
	 *
	 * @brief	Resets the count.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void resetCount();

	/**
	 * @fn	void Bot2::setLastBetValue(unsigned int lastBet);
	 *
	 * @brief	Sets last bet value.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	lastBet	The last bet.
	 */

	void setLastBetValue(unsigned int lastBet);
};

/**
 * @class	Human
 *
 * @brief	///////////////////////////////////////////////// HUMAN
 * 			////////////////////////////////////////////////////.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class Human: public Player {
public:

	/**
	 * @fn	Human::Human(string name, unsigned int age);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	name	The name.
	 * @param	age 	The age.
	 */

	Human(string name, unsigned int age);

	/**
	 * @fn	unsigned int Human::bet(Table &table);
	 *
	 * @brief	Bets the given table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	An int.
	 */

	unsigned int bet(Table &table);

	/**
	 * @fn	string Human::play(Table &table);
	 *
	 * @brief	Plays the given table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	A string.
	 */

	string play(Table &table);

	/**
	 * @fn	bool Human::takeInsurance(Table &table);
	 *
	 * @brief	Take insurance.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool takeInsurance(Table &table);

	/**
	 * @fn	bool Human::split( Dealer *dealerOfTable);
	 *
	 * @brief	Splits the given dealer of table.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealerOfTable	If non-null, the dealer of table.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool split( Dealer *dealerOfTable);
};





