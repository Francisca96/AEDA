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
 * @author	Joao Carvalho
 * @date	19/11/2016
 */

class NameTooShortException {
public:

	/**
	 * @fn	void NameTooShortException::what();
	 *
	 * @brief	Displays on terminal what throwed this exception.
	 *
	 * @author	Joao Carvalho
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
 * @author	Joao Carvalho
 * @date	19/11/2016
 */

class TooYoungException {
public:

	/**
	 * @fn	void TooYoungException::what();
	 *
	 * @brief	Displays on terminal what throwed this exception.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 */

	void what();
};

/**
 * @class	PlayerAlreadyExistException
 *
 * @brief	Exception for signalling that the player already exists.
 *
 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
 *			Player is the base class.
 * @author	Joao Carvalho
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
	/** @brief	ID of the table that the player is on. -1 if not on any table. */
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
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param	newCard	The new card.
	 */

	void hit(Card newCard);

	/**
	* @fn	void Player::hit2(Card newCard);
	*
	* @brief	Hits the given new card.
	*			Saves the card on the hand2.
	*			Updates the hand2score.
	* @author	Joao Carvalho
	* @date	19/11/2016
	*
	* @param	newCard	The new card.
	*/

	void hit2(Card newCard);

	/**
	 * @fn	virtual bool Player::takeInsurance(Table &table);
	 *
	 * @brief	Take insurance.
	 *
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 */

	void doubleDown();

	/**
	 * @fn	vector<Card> & Player::getHand();
	 *
	 * @brief	Gets the hand.
	 *
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @return	The rounds played.
	 */

	unsigned int getRoundsPlayed() const;

	/**
	 * @fn	float Player::getCurrentMoney() const;
	 *
	 * @brief	Gets current money.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @return	The current money.
	 */

	float getCurrentMoney() const;

	/**
	 * @fn	float Player::getAverageProfit() const;
	 *
	 * @brief	Gets average profit.
	 *
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @return	The name.
	 */

	string getName() const;


	/**
	* @fn	void setAverageProfit(float averageProfit);
	*
	* @brief	Sets the average profit of the player.
	*
	* @author	Joao Carvalho
	* @date	27/12/2016
	*
	* @param	averageProfit	Average profit of the player.
	*/

	void setAverageProfit(float averageProfit);



	/**
	 * @fn	void Player::setName(string newName);
	 *
	 * @brief	Sets a name.
	 *
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @return	The second hand score.
	 */

	unsigned int setHand2Score();

	/**
	 * @fn	void Player::setCurrentMoney(float money);
	 *
	 * @brief	Sets current money.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param	money	The money.
	 */

	void setCurrentMoney(float money);

	/**
	 * @fn	void Player::setRoundsPlayed(unsigned int rounds);
	 *
	 * @brief	Sets rounds played.
	 *
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 */

	void clearHand();

	/**
	 * @fn	void Player::clearHand2();
	 *
	 * @brief	Clears the second hand.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 */

	void clearHand2();

	/**
	 * @fn	void Player::setActualBet(unsigned int bet);
	 *
	 * @brief	Sets actual bet.
	 *
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 */

	virtual void resetCount();

	/**
	 * @fn	unsigned int Player::getAge() const;
	 *
	 * @brief	Gets the age.
	 *
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
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
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @return	ID of the table. -1 if the player is not on any table.
	 */

	int getOnTable() const;

	/**
	 * @fn	void Player::removeCardFromFirstHandAndSetItOnSecondHand();
	 *
	 * @brief	Removes the card from first hand sets it on the second hand.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 */

	void removeCardFromFirstHandAndSetItOnSecondHand();
	/**
	* @fn	virtual void setUserID(unsigned int userID) {}
	*
	* @brief	Does nothing in class Player.
	* 			But it is necessary for the human class.
	*
	* @author	Joao Carvalho
	* @date	19/11/2016
	*/

	virtual void setUserID(unsigned int userID) {}
	/**
	* @fn	virtual unsigned int getUserID() const
	*
	* @brief	Returns 0;
	*
	* @return 0.
	* @author	Joao Carvalho
	* @date	19/11/2016
	*/

	virtual unsigned int getUserID() const { return 0; }

	/**
	* @fn	virtual ostream& saveInfo(ostream& out);
	*
	* @brief	Writes player info to stream.
	* @param [in,out]	out ostream in which player info will be saved.
	* @return Player info in a ostream
	* @author	Joao Carvalho
	* @date	19/11/2016
	*/

	virtual ostream& saveInfo(ostream& out);

};

/**
 * @class	Bot0
 *
 * @brief	Bot of type 0.
 * 			The most basic bot, always bets the minimum allowed, stands on 17 (or more).
 *
 * @author	Joao Carvalho
 * @date	19/11/2016
 */

class Bot0: public Player {
public:

	/**
	 * @fn	Bot0::Bot0()
	 *
	 * @brief	Default constructor.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 */

	Bot0() {};

	/**
	* @fn	Bot0::Bot0(string name, unsigned int initialMoney);
	*
	* @brief	Constructor.
	*
	* @author	Joao Carvalho
	* @date	19/11/2016
	*
	* @param	name			The name.
	* @param	initialMoney	The initial money.
	*/

	Bot0(string name, unsigned int initialMoney);

	/**
	* @fn	Bot0::Bot0(string &line);
	*
	* @brief	Constructor.
	*
	* @author	Joao Carvalho
	* @date	19/11/2016
	*
	* @param	line		Line containes all information.
	*/

	Bot0(string &line);

	/**
	 * @fn	string Bot0::play(Table &table);
	 *
	 * @brief	Plays accordingly to an algorithm.
	 * 			Never doubles, always stands on 17 or higher, always hits if less than 17.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	A string, "hit" or "stand".
	 */

	string play(Table &table);

	/**
	 * @fn	bool Bot0::takeInsurance(Table &table);
	 *
	 * @brief	Take insurance always returns false on Bot0.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	False.
	 */

	bool takeInsurance(Table &table);

	/**
	* @fn	virtual ostream& saveInfo(ostream& out);
	*
	* @brief	Writes Bot0 info to stream.
	* @param [in,out]	out ostream in which Bot0 info will be saved.
	* @return Bot0 info in a ostream.
	* @author	Joao Carvalho
	* @date	19/11/2016
	*/


	virtual ostream& saveInfo(ostream& out);
};

/**
 * @class	Bot1
 *
 * @brief	Bot of type 1.
 * 			This bot plays using the hi-lo counting system. His decisions are based on the illustrious18 and the fab4 surrender guides.
 * 			
 *
 * @author	Joao Carvalho
 * @date	19/11/2016
 */

class Bot1: public Player {
private:
	/** @brief	The current count. */
	int currentCount;
public:

	/**
	 * @fn	unsigned int Bot1::bet(Table &table);
	 *
	 * @brief	Places an initial bet that depends on the current count.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	The amount bet.
	 */

	unsigned int bet(Table &table);

	/**
	 * @fn	Bot1::Bot1(string name, unsigned int initialMoney);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param	name			The name.
	 * @param	initialMoney	The initial money.
	 */

	Bot1(string name, unsigned int initialMoney);

	/**
	* @fn	Bot1::Bot1(string &line);
	*
	* @brief	Constructor.
	*
	* @author	Joao Carvalho
	* @date	19/11/2016
	*
	* @param	line		Line containes all information.
	*/

	Bot1(string &line);

	/**
	 * @fn	string Bot1::play(Table &table);
	 *
	 * @brief	Plays using the illustrious18 guides.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	A string: "hit","stand" or "double"
	 */

	string play(Table &table);

	/**
	 * @fn	bool Bot1::takeInsurance(Table &table);
	 *
	 * @brief	Take insurance if current count >= 3;
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	True if it takes insurance, false if it does not.
	 */

	bool takeInsurance(Table &table);

	/**
	 * @fn	int Bot1::getCurrentCount() const;
	 *
	 * @brief	Gets current count.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @return	The current count.
	 */

	int getCurrentCount() const;

	/**
	 * @fn	void Bot1::addCount(Card &card1);
	 *
	 * @brief	Updates the current counter with a new card.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	card1	The card to update the counter.
	 */

	void addCount(Card &card1);

	/**
	 * @fn	void Bot1::resetCount();
	 *
	 * @brief	Resets the current counter.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 */

	void resetCount();

	/**
	 * @fn	bool Bot1::split( Dealer *dealerOfTable);
	 *
	 * @brief	Splits the hand or not.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealerOfTable	Poiner to the dealer of the table.
	 *
	 * @return	True if it splits, false if it does not.
	 */

	bool split( Dealer *dealerOfTable);

	/**
	 * @fn	virtual bool Bot1::surrender(Table &table);
	 *
	 * @brief	Surrenders or not.
	 * 			Surrender algorithm is based on the fab4 surrender guides. 
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	True if it surrenders, false if it does not.
	 */

	virtual bool surrender(Table &table);

	/**
	* @fn	virtual ostream& saveInfo(ostream& out);
	*
	* @brief	Writes Bot1 info to stream.
	* @author	Joao Carvalho
	* @date	19/11/2016
	* @param	out ostream in which Bot1 info will be saved.
	* @return [in,out] Bot1 info in a ostream.
	*/


	virtual ostream& saveInfo(ostream& out);
};

/**
 * @class	Bot2
 *
 * @brief	Bot of type 2.
 * 			This bot plays using the Ace/Five Count strategy guide.
 *
 * @author	Joao Carvalho
 * @date	19/11/2016
 */

class Bot2 : public Player {
private:
	/** @brief	Current counter. */
	int currentCount;
	/** @brief	The last bet value. */
	unsigned int lastBetValue;
public:

	/**
	 * @fn	Bot2::Bot2(string name, unsigned int initialMoney);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param	name			The name.
	 * @param	initialMoney	The initial money.
	 */

	Bot2(string name, unsigned int initialMoney);

	/**
	* @fn	Bot2::Bot2(string &line);
	*
	* @brief	Constructor.
	*
	* @author	Joao Carvalho
	* @date	19/11/2016
	*
	* @param	line			Line contains all information.
	*/

	Bot2(string &line);

	/**
	 * @fn	unsigned int Bot2::bet(Table &table);
	 *
	 * @brief	Bets according to the Ace/Five guidelines.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	The initial bet value.
	 */

	unsigned int bet(Table &table);
	//play method

	/**
	 * @fn	string Bot2::play(Table &table);
	 *
	 * @brief	Plays according to the Ace/Five rules.
	 *
	 * @author	Joao Carvalho
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
	 * @brief	Ckeck if bot2 wants to take insurance.
	 *			Bot2 never takes insurance.
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	False.
	 */

	bool takeInsurance(Table &table);

	/**
	 * @fn	bool Bot2::split(Dealer *dealerOfTable);
	 *
	 * @brief	Checks if the bot wants to split.
	 *			Bot2 never splits.
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealerOfTable	Pointer to the dealer of the table.
	 *
	 * @return	False.
	 */

	bool split(Dealer *dealerOfTable);

	/**
	 * @fn	virtual bool Bot2::surrender(Table &table);
	 *
	 * @brief	Surrenders or not.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	True if it surrenders, false if it does not.
	 */

	virtual bool surrender(Table &table);

	/**
	 * @fn	int Bot2::getCurrentCount() const;
	 *
	 * @brief	Gets the current count.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @return	The current count.
	 */

	int getCurrentCount() const;

	/**
	 * @fn	void Bot2::addCount(Card &card1);
	 *
	 * @brief	Updates the counter with a given card.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	card1	The card to update the counter.
	 */

	void addCount(Card &card1);

	/**
	 * @fn	void Bot2::resetCount();
	 *
	 * @brief	Resets the counter.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 */

	void resetCount();

	/**
	 * @fn	void Bot2::setLastBetValue(unsigned int lastBet);
	 *
	 * @brief	Sets last bet value.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param	lastBet	The last bet.
	 */

	void setLastBetValue(unsigned int lastBet);

	/**
	* @fn	virtual ostream& saveInfo(ostream& out);
	*
	* @brief	Writes Bot2 info to stream.
	* 			
	* @author	Joao Carvalho
	* @date	19/11/2016
	* 		
	* @param [in,out]	out ostream in which Bot2 info will be saved.
	* @return Bot2 info in a ostream.
	*/


	virtual ostream& saveInfo(ostream& out);
};

/**
 * @class	Human
 *
 * @brief	A Human player.
 * 			
 *
 * @author	Joao Carvalho
 * @date	19/11/2016
 */

class Human: public Player {
private:
	/** @brief	User identifier. */
	unsigned int userID;
public:

	/**
	 * @fn	Human::Human(string name, unsigned int age, int userID);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param	name	The name.
	 * @param	age 	The age.
	 * @param	userID	The user identifier.
	 */

	Human(string name, unsigned int age, int userID);

	/**
	* @fn	Human::Human(string &line);
	*
	* @brief	Constructor.
	*
	* @author	Joao Carvalho
	* @date	19/11/2016
	*
	* @param	line	Line that contains all information.
	*/

	Human(string &line);

	/**
	 * @fn	unsigned int Human::bet(Table &table);
	 *
	 * @brief	Asks the human player to place his bet.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	The human bet.
	 */

	unsigned int bet(Table &table);

	/**
	 * @fn	string Human::play(Table &table);
	 *
	 * @brief	Ask the human player to hit or stand.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	A string: "hit" or "stand";
	 */

	string play(Table &table);

	/**
	 * @fn	bool Human::takeInsurance(Table &table);
	 *
	 * @brief	Ask the human player for insurance.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	The table.
	 *
	 * @return	True if human takes insurance, false if it does not.
	 */

	bool takeInsurance(Table &table);

	/**
	 * @fn	bool Human::split( Dealer *dealerOfTable);
	 *
	 * @brief	Ask human if he want to split his hand.
	 *
	 * @author	Joao Carvalho
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealerOfTable	Pointer to the dealer of the table.
	 *
	 * @return	True if human splits, false otherwise.
	 */

	bool split( Dealer *dealerOfTable);

	/**
	* @fn	void setUserID(unsigned int userID);
	*
	* @brief	Sets user identifier.
	*
	* @author	Joao Carvalho
	* @date	19/11/2016
	*
	* @param	userID	New user identifier.
	*/

	void setUserID(unsigned int userID);

	/**
	* @fn	unsigned int getUserID() const;
	*
	* @brief	Gets user identifier.
	*
	* @author	Joao Carvalho
	* @date	19/11/2016
	*
	* @return	User identifier.
	*/

	unsigned int getUserID() const;

	/**
	* @fn	virtual ostream& saveInfo(ostream& out);
	*
	* @brief	Writes Human info to stream.
	*
	* @author	Joao Carvalho
	* @date	19/11/2016
	*
	* @param [in,out]	out ostream in which Human info will be saved.
	* @return Human info in a ostream.
	*/

	virtual ostream& saveInfo(ostream& out);
};





