#pragma once

#include "utils.h"
#include <vector>
#include <iomanip>
#include <string>
#include "Dealer.h"
#include "Table.h"
#include "Player.h"


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
	vector<Dealer*> dealers;
	vector<Table *> tables;
	vector<Player*> players;
public:
	Casino();
	Casino(vector<Table*> &tables, vector<Player *> &players);
	void addTablesToCasino(vector<Table*> tables);
	void addTableToCasino(Table* table);
	void addPlayerToCasino(Player * player1);
	void addPlayersToCasino(vector<Player *> &playersVector);
	void addPlayersToTable(vector<Player *> &playersVector, Table * table);
	void addPlayerToTable(Player * player1,Table * table);
	void showStatistics();
};
