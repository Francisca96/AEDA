#pragma once

#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include "Table.h"
#include "utils.h"


using namespace std;

class PlayerNotLogged {
private:
	string name;
public:
	PlayerNotLogged(Player * player1);
	void what();
};

class ExistingTable {
private:
	unsigned int id;
public:
	ExistingTable(Table * table);
	void what();
};

class TableNotInCasino {
private:
	unsigned int id;
public:
	TableNotInCasino(Table * table);
	void what();
};

class Casino {
private:
	string playersFile;
	string dealersFile;
	string tablesFile;
	unsigned int totalMoney;
	int tableToPlay;
	vector<Dealer*> dealers;
	vector<Table *> tables;
	vector<Player*> players;
public:
	Casino(unsigned int totalMoney);
	Casino(unsigned int totalMoney,vector<Table*> &tables, vector<Player *> &players);
	void addTablesToCasino(vector<Table*> tables);
	void addTableToCasino(Table* table);
	void addPlayerToCasino(Player * player1);
	void addPlayersToCasino(vector<Player *> &playersVector);
	void addPlayersToTable(vector<Player *> &playersVector, Table * table);
	void addPlayerToTable(Player * player1,Table * table);
	void setPlayersFile(string playerFile);
	void setDealersFile(string dealersFile);
	void setTablesFile(string tablesFile);
	void readPlayersFile();
	void readDealersFile();
	void readTablesFile();
	void savePlayersFile();
	void saveDealersFile();
	void saveTablesFile();
	void showStatistics() const;
	void showPlayers() const;
	void showDealers() const;
	void showTables() const;
	vector<Table*> getTables() const;
	void setTableToPlay(int tableID);
	Table * getTableToPlay() const;
	void manage(pair <short, short> xy);
	void create(pair <short, short> xy);
	void eliminate(pair <short, short> xy);
};
