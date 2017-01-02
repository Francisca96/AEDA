/**
 * @file	C:\Users\ineeve\Documents\GitHub\aeda-casino\Casino.h
 *
 * @brief	Declares the casino class.
 */

#pragma once

#include <vector>
#include <set>
#include <iomanip>
#include <string>
#include <sstream>
#include <unordered_set>
#include <queue>
#include <conio.h>
#include "Table.h"
#include "utils.h"
#include "cmdUI.h"


using namespace std;


/**
* @struct	userLoginHash
*
* @brief	Used to generate indexs and compare logins. It is only prepared for hash tables of size 47.
*
* @author	Renato Campos
* @date	30/12/2016
*/


struct userLoginHash
{
	/**
	* @fn	size_t operator() (const pair <string, string>& ur) const
	*
	* @brief	Dispersion Function.
	*
	* @author	Francisca Paupério
	* @date	30/12/2016
	*
	* @param	ur A string pair containing username and password.
	*
	* @return	User index on hash table.
	*/
	size_t operator() (const pair <string, string>& ur) const {
		unsigned int hashNumber = 0;
		for (size_t i = 0; i < ur.second.size(); i++)
		{
			hashNumber += ur.second.at(i) % 32 * (i + 1);
		}
		return hashNumber % 47;
	}

	/**
	* @fn	int operator() (const pair <string, string> &ur1, const pair <string, string> &ur2) const
	*
	* @brief	A binary predicate that compairs if two elements are equal.
	*
	* @author	Francisca Paupério
	* @date	30/12/2016
	*
	* @param	ur1 One user.
	* @param	ur2 One user.
	*
	* @return	True if elements have same username, False otherwise.
	*/
	int operator() (const pair <string, string> &ur1, const pair <string, string> &ur2) const {
		return ur1.first == ur2.first;
	}
};

typedef unordered_set< pair<string, string>, userLoginHash, userLoginHash> loginHash; /* @brief loginHash = unordered_set<pair<string,string>,userLoginHash,userLoginHash> */

/**
* @struct	userLoginHash 
*
* @brief	Used to compare dealers.
*
* @author	João Carvalho
* @date	30/12/2016
*/

struct dealersComparasion
{
	/**
	* @fn	bool operator() (const Dealer* d1, const Dealer* d2) const
	*
	* @brief	A binary predicate that performs the less operator.
	*
	* @author	Francisca Paupério
	* @date	30/12/2016
	*
	* @param	d1 Pointer to a Dealer.
	* @param	d2 Pointer to a Dealer.
	*
	* @return	True if d1 < d2.
	*/

	bool operator() (const Dealer* d1, const Dealer* d2) const {
		if (d1->getTableOn() == -1 && d2->getTableOn() != -1)
		{
			return false;
		}
		else if (d1->getTableOn() == -1 && d2->getTableOn() == -1)
		{
			return d1->getID() > d2->getID();
		}
		else if (d1->getTableOn() != -1 && d2->getTableOn() != -1)
		{
			return d1->getID() > d2->getID();
		}
		else
		{
			return true;
		}
	}
};

typedef priority_queue< Dealer*, vector<Dealer*>, dealersComparasion> dealersPriority;

/**
 * @class	PlayerNotLoggedException
 *
 * @brief	Exception for signalling player not logged in.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class PlayerNotLoggedException {
private:
	/** @brief	The name. */
	string name;
public:

	/**
	 * @fn	PlayerNotLoggedException::PlayerNotLoggedException(Player * player1);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	player1 Pointer to the player.
	 */

	PlayerNotLoggedException(Player * player1);

	/**
	 * @fn	void PlayerNotLoggedException::what();
	 *
	 * @brief	Displays in terminal what caused this exception to be thrown.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void what();
};

/**
 * @class	ExistingTableException
 *
 * @brief	Exception for signalling that a table with the specified ID already exists.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class ExistingTableException {
private:
	/** @brief	The identifier. */
	unsigned int id;
public:

	/**
	 * @fn	ExistingTableException::ExistingTableException(Table * table);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	Pointer to the table.
	 */

	ExistingTableException(Table * table);

	/**
	 * @fn	void ExistingTableException::what();
	 *
	 * @brief	Displays in terminal what caused this exception to be thrown.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void what();
};

/**
 * @class	TableNotInCasinoException
 *
 * @brief	Exception for signalling that the table is not in the casino.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

class TableNotInCasinoException {
private:
	/** @brief	The identifier. */
	unsigned int id;
public:

	/**
	 * @fn	TableNotInCasinoException::TableNotInCasinoException(Table * table);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	Pointer to the table.
	 */

	TableNotInCasinoException(Table * table);

	/**
	 * @fn	void TableNotInCasinoException::what();
	 *
	 * @brief	Displays in terminal what caused this exception to be thrown.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void what();
};

/**
* @struct	CompareByAverageProfit
*
* @brief	Used to compare players by their average profit.
*
* @author	Renato Campos
* @date	30/12/2016
*/


struct CompareByAverageProfit {

	/**
	* @fn	bool operator()(Player *lhs, Player * rhs) const
	*
	* @brief	Operator that will perform the Less Comparison
	*
	* @author	Renato Campos
	* @date	30/12/2016
	*
	* @param	lhs Pointer to a player.
	* @param	rhs Pointer to a player.
	*
	* @return	True if lhs avg.profit > rhs avg.profit;
	*/

	bool operator()(Player * lhs,Player * rhs) const {
		return lhs->getAverageProfit() > rhs->getAverageProfit();
	}
};

/**
* @struct	CompareByAge
*
* @brief	Used to compare players by their age. Players with same age are compared by name.
*
* @author	Renato Campos
* @date	30/12/2016
*/


struct CompareByAge {
	/**
	* @fn	bool operator()(Player *lhs, Player * rhs) const
	*
	* @brief	Operator that will perform the Less Comparison
	*
	* @author	Renato Campos
	* @date	30/12/2016
	*
	* @param	lhs Pointer to a player.
	* @param	rhs Pointer to a player.
	*
	* @return	True if lhs age < rhs age. If ages are equal, players are compared by their name.
	*/

	bool operator()(Player *lhs, Player * rhs) const {
		if (lhs->getAge() == rhs->getAge()) {
			return lhs->getName() < rhs->getName();
		}
		else { 
			return lhs->getAge() < rhs->getAge();
		}
	}
};

/**
* @struct	CompareByName
*
* @brief	Used to compare players by their name.
*
* @author	Renato Campos
* @date	30/12/2016
*/


struct CompareByName {
	/**
	* @fn	bool operator()(Player *lhs, Player * rhs) const
	*
	* @brief	Operator that will perform the Less Comparison
	*
	* @author	Renato Campos
	* @date	30/12/2016
	*
	* @param	lhs Pointer to a player.
	* @param	rhs Pointer to a player.
	*
	* @return	True if lhs name < rhs name;
	*/

	bool operator()(Player *lhs, Player * rhs) const {
		return lhs->getName() < rhs->getName();
	}
};

/**
* @struct	CompareByIntelligence
*
* @brief	Used to compare players by their intelligence.
*
* @author	Renato Campos
* @date	30/12/2016
*/


struct CompareByIntelligence {

	/**
	* @fn	bool operator()(Player *lhs, Player * rhs) const
	*
	* @brief	Operator that will perform the Less Comparison
	*
	* @author	Renato Campos
	* @date	30/12/2016
	*
	* @param	lhs Pointer to a player.
	* @param	rhs Pointer to a player.
	*
	* @return	True if lhs intelligence < rhs intelligence; If players have the same intelligence, they will be ordered by name.
	*/

	bool operator()(Player *lhs, Player * rhs) const {
		Bot0 *bot0l = dynamic_cast<Bot0*> (lhs);
		Bot1 *bot1l = dynamic_cast<Bot1*> (lhs);
		Bot2 *bot2l = dynamic_cast<Bot2*> (lhs);
		Human *humanl = dynamic_cast<Human*> (lhs);
		Bot0 *bot0r = dynamic_cast<Bot0*> (rhs);
		Bot1 *bot1r = dynamic_cast<Bot1*> (rhs);
		Bot2 *bot2r = dynamic_cast<Bot2*> (rhs);
		Human *humanr = dynamic_cast<Human*> (rhs);
		if (bot0l != nullptr && bot0r != nullptr) {
			return bot0l->getName() < bot0r->getName();
		}
		else if (bot1l != nullptr && bot1r != nullptr) {
			return bot1l->getName() < bot1r->getName();
		}
		else if (bot2l != nullptr && bot2r != nullptr) {
			return bot2l->getName() < bot2r->getName();
		}
		else if (humanl != nullptr && humanr != nullptr) {
			return humanl->getName() < humanr->getName();
		}
		else if (bot0l != nullptr ) {
			return true;
		}
		else if (bot1l != nullptr && (bot2r != nullptr || humanr != nullptr)) {
			return true;
		}
		else if (bot2l != nullptr && humanr != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
};


/**
* @class	Casino
*
* @brief	A casino.
*
* @author	Ineeve
* @date	19/11/2016
*/

class Casino {
private:
	/** @brief	The players file. */
	string playersFile;
	/** @brief	The dealers file. */
	string dealersFile;
	/** @brief	The tables file. */
	string tablesFile;
	/** @brief	The users file. */
	string usersFile;
	/** @brief	The total money. */
	unsigned int totalMoney;
	/** @brief	The table to play. */
	int tableToPlay;
	/** @brief	The dealers. */
	vector<Dealer*> dealers;
	/** @brief	The tables. */
	vector<Table *> tables;
	/** @brief	The players. */
	vector<Player*> players;
	/** @brief	An unordered_set representing the hash table. */
	loginHash userslogin;
	/** @brief	The users actual logged */
	pair <string, string> userLOGIN;
	//* @brief Binary Search Tree ordered by average profit */
	set<Player *, CompareByAverageProfit> bestPlayers;
public:
	
	/**
	* @fn	void showUsers(int n);
	*
	* @brief	Display accounts infos.
	*
	* @author	Joao Carvalho
	* @date	30/12/2016
	*
	* @param	n	Number of users.
	*/

	void showUsers(int n);

	/**
	 * @fn	Casino::Casino(unsigned int totalMoney);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	totalMoney	The total money.
	 */

	Casino(unsigned int totalMoney);

	/**
	 * @fn	Casino::Casino(unsigned int totalMoney,vector<Table*> &tables, vector<Player *> &players);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param 		  	totalMoney	The total money.
	 * @param [in,out]	tables	  	Vector of pointers to tables.
	 * @param [in,out]	players   	Vector of pointers to players.
	 */

	Casino(unsigned int totalMoney,vector<Table*> &tables, vector<Player *> &players);

	/**
	* @fn	bool Casino::login();
	*
	* @brief	login system.
	*
	* @author	João Carvalho
	* @date	26/12/2016
	*
	 * @param 	xy	A pair containing the horizontal and vertical lengths of the terminal.
	*/

	bool login(pair<int, int> xy);

	/**
	* @fn	string getUserLoginName();
	*
	* @brief	login system.
	*
	* @author	João Carvalho
	* @date	26/12/2016
	*
	*/

	string getUserLoginName();

	/**
	 * @fn	void Casino::addTablesToCasino(vector<Table*> tables);
	 *
	 * @brief	Adds the tables to casino.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	tables	Vector of pointers to tables.
	 */

	void addTablesToCasino(vector<Table*> tables);

	/**
	 * @fn	void Casino::addTableToCasino(Table* table);
	 *
	 * @brief	Adds a table to casino.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	 Pointer of the table to be added.
	 */

	void addTableToCasino(Table* table);

	/**
	 * @fn	void Casino::removeTableFromCasino(Table* table);
	 *
	 * @brief	Removes the table from casino.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	table	Pointer of the table to be removed.
	 */

	void removeTableFromCasino(Table* table);

	/**
	 * @fn	void Casino::addPlayerToCasino(Player * player1);
	 *
	 * @brief	Adds a player to casino.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	player1	Pointer to the player to be logged in the casino.
	 */

	void addPlayerToCasino(Player * player1);

	/**
	 * @fn	void Casino::removePlayerFromCasino(string name);
	 *
	 * @brief	Removes the player from casino.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	name	The name of the player to be removed.
	 */

	void removePlayerFromCasino(string name);

	/**
	 * @fn	void Casino::addPlayersToCasino(vector<Player *> &playersVector);
	 *
	 * @brief	Adds the players to casino.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	playersVector	 Vector of pointers to the players that should be added.
	 */

	void addPlayersToCasino(vector<Player *> &playersVector);

	/**
	 * @fn	void Casino::addPlayersToTable(vector<Player *> &playersVector, Table * table);
	 *
	 * @brief	Adds the players to a Table of the casino.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	playersVector	Vector of pointers to players.
	 * @param [in,out]	table		 	Pointer to the table in which the players will be added.
	 */

	void addPlayersToTable(vector<Player *> &playersVector, Table * table);

	/**
	 * @fn	void Casino::addPlayerToTable(Player * player1,Table * table);
	 *
	 * @brief	Adds a player to a table of the casino.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	player1	Pointer to the player that should be added to the table.
	 * @param [in,out]	table  	Pointer to the table.
	 */

	void addPlayerToTable(Player * player1,Table * table);

	/**
	 * @fn	void Casino::addDealerToCasino(Dealer *newDealer);
	 *
	 * @brief	Adds a dealer to the casino.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	newDealer	Pointer to the dealer that should be added to the casino.
	 */

	void addDealerToCasino(Dealer *newDealer);

	/**
	 * @fn	void Casino::removeDealerFromCasino(Dealer *dealer);
	 *
	 * @brief	Removes a dealer from the casino.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param [in,out]	dealer	Pointer to the dealer that should be removed from the casino.
	 */

	void removeDealerFromCasino(Dealer *dealer);

	/**
	 * @fn	void Casino::setPlayersFile(string playerFile);
	 *
	 * @brief	Sets players file.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	playerFile	A string already formatted to save the players in a file.
	 */

	void setPlayersFile(string playerFile);

	/**
	 * @fn	void Casino::setDealersFile(string dealersFile);
	 *
	 * @brief	Sets dealers file.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	dealersFile	A string already formatted to save the dealers in a file.
	 */

	void setDealersFile(string dealersFile);

	/**
	 * @fn	void Casino::setTablesFile(string tablesFile);
	 *
	 * @brief	Sets tables file.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	tablesFile	A string already formatted to save the tables in a file.
	 */

	void setTablesFile(string tablesFile);

	/**
	* @fn	void Casino::setUsersFile(string usersFile);
	*
	* @brief	Sets users file.
	*
	* @author	Joao Carvalho
	* @date	26/12/2016
	*
	* @param	usersFile	A string already formatted to save players in a file.
	*/

	void setUsersFile(string usersFile);

	/**
	 * @fn	void Casino::readPlayersFile();
	 *
	 * @brief	Reads players .txt file. The players file should be placed in the project directory.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void readPlayersFile();

	/**
	 * @fn	void Casino::readDealersFile();
	 *
	 * @brief	Reads dealers .txt file. The dealers file should be placed in the project directory.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void readDealersFile();

	/**
	 * @fn	void Casino::readTablesFile();
	 *
	 * @brief	Reads tables .txt file. The tables file should be placed in the project directory.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void readTablesFile();

	/**
	* @fn	void Casino::readLoginFile();
	*
	* @brief	Reads login .txt file. The login file should be placed in the project directory.
	*
	* @author	João Carvalho
	* @date	26/12/2016
	*/

	void readLoginFile();

	/**
	 * @fn	void Casino::savePlayersFile();
	 *
	 * @brief	Saves the players in a txt file.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void savePlayersFile();

	/**
	 * @fn	void Casino::saveDealersFile();
	 *
	 * @brief	Saves the dealers in a txt file.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void saveDealersFile();

	/**
	 * @fn	void Casino::saveTablesFile();
	 *
	 * @brief	Saves the tables in a txt file.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 */

	void saveTablesFile();

	/**
	* @fn	void Casino::saveLoginFile();
	*
	* @brief	Saves login .txt file.
	*
	* @author	João Carvalho
	* @date	26/12/2016
	*/

	void saveLoginFile();

	/**
	* @fn	void Casino::fillBestPlayersSet();
	*
	* @brief	Fills best players set with player that have played at least 1 round.
	* @author	Ineeve
	* @date	30/12/2016
	*/

	void fillBestPlayersSet();

	/**
	 * @fn	void Casino::showStatistics(set<Player*, T> setOfPlayers,int numberOfPlayersToShow) const;
	 *
	 * @brief	Displays casino's statistics in a user friendly way on the terminal.
	 * @param	setOfPlayers a std::set of players order as user selected.
	 * @param	numberOfPlayersToShow Number of players to display.
	 * @author	Ineeve
	 * @date	19/11/2016
	 */
	template <class T>
	void showStatistics(set<Player*, T> setOfPlayers,int numberOfPlayersToShow) const;

	/**
	* @fn	void Casino::showStatisticsMenu(pair<short, short> xy);
	*
	* @brief	Lets user select the order that the players will be dispayed on the scoreboard.
	* @param	xy Cursor coordinates.
	* @author	Ineeve
	* @date	30/12/2016
	*/

	void showStatisticsMenu(pair<short, short> xy);

	/**
	 * @fn	void Casino::showPlayers(pair <short, short> xy) const;
	 *
	 * @brief	Displays the players that are logged in a user friendly way on the terminal.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	xy	The cursor coordinates.
	 */

	void showPlayers(pair <short, short> xy) const;

	/**
	 * @fn	void Casino::showDealers(pair <short, short> xy) const;
	 *
	 * @brief	Displays casino's dealers in a user friendly way on the terminal.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	xy	The cursor coordinates.
	 */

	void showDealers(pair <short, short> xy) const;

	/**
	 * @fn	void Casino::showTables(pair <short, short> xy);
	 *
	 * @brief	Displays casino's tables in a user friendly way on the terminal.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	xy	The cursor coordinates.
	 */

	void showTables(pair <short, short> xy);

	/**
	 * @fn	vector<Table*> Casino::getTables() const;
	 *
	 * @brief	Gets the tables.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	A vector of pointers to the casino's tables.
	 */

	vector<Table*> getTables() const;

	/**
	 * @fn	void Casino::selectTable(pair <short, short> xy);
	 *
	 * @brief	Select table using the given <x,y> coordinates.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	xy	The <x,y> coordinates.
	 */

	void selectTable(pair <short, short> xy);

	/**
	 * @fn	void Casino::setTableToPlay(int tableID);
	 *
	 * @brief	Sets table to play.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	tableID	Identifier for the table.
	 */

	void setTableToPlay(int tableID);

	/**
	 * @fn	Table * Casino::getTableToPlay() const;
	 *
	 * @brief	Gets table to play.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @return	Pointer to the table to play.
	 */

	Table * getTableToPlay() const;

	/**
	 * @fn	void Casino::manage(pair <short, short> xy);
	 *
	 * @brief	Manages casino.
	 * 			Enables the user to select between menus.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	xy	The <x,y> coordinates.
	 */

	void manage(pair <short, short> xy);

	/**
	 * @fn	void Casino::create(pair <short, short> xy);
	 *
	 * @brief	Creates a menu for casino.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	xy	The <x,y> coordinates.
	 */

	void create(pair <short, short> xy);

	/**
	 * @fn	void Casino::eliminate(pair <short, short> xy);
	 *
	 * @brief	Open a delete menu.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	xy	The <x,y> coordinates.
	 */

	void eliminate(pair <short, short> xy);

	/**
	 * @fn	void Casino::manageTables(pair <short, short> xy, unsigned int tableID);
	 *
	 * @brief	Manage tables.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	xy	   	The <x,y> coordinates.
	 * @param	tableID	Identifier for the table.
	 */

	void manageTables(pair <short, short> xy, unsigned int tableID);

	/**
	 * @fn	unsigned int Casino::findTable(unsigned int tableID);
	 *
	 * @brief	Searches for a table (sequential search).
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	tableID	Identifier for the table.
	 *
	 * @return	The index of the table on the tables vector.
	 */

	unsigned int findTable(unsigned int tableID);

	/**
	 * @fn	unsigned int Casino::findDealer(unsigned int dealerID);
	 *
	 * @brief	Searches for a dealer (sequential search).
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	dealerID	Identifier for the dealer.
	 *
	 * @return	The index of the dealer on the dealers vector.
	 */

	unsigned int findDealer(unsigned int dealerID);

	/**
	 * @fn	unsigned int Casino::findPlayer(string name);
	 *
	 * @brief	Searches for a player (sequential search).
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	name	The name of the player.
	 *
	 * @return	The index of the player in the players vector.
	 */

	unsigned int findPlayer(string name);
};

template<class T>
void Casino::showStatistics(set<Player*,T> setOfPlayers, int numberOfPlayersToShow) const
{
	int userInput;
	system("CLS");
	cout << "Statistics\n\n\n\n";
	cout << setw(15) << "NAME" << setw(25) << "BRAIN LEVEL" << setw(15) << "ROUNDS PLAYED" << setw(18) << "AVG. PROFIT" << setw(15) << "AGE" << endl;
	int counter = 0;
	for (auto i = setOfPlayers.begin(); i != setOfPlayers.end(); i++) {
		if (counter >= numberOfPlayersToShow) {
			break;
		}
		(*i)->showStatistics();
		counter++;
	}
	cout << "0. Back\n";
	while ((userInput = readInt()) != 0) {
		cout << "Please insert a valid option\n";
	}
	return;
	
}
