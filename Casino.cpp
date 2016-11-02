#pragma once

#include "Casino.h"

Casino::Casino()
{
}

Casino::Casino(vector<Table*> &tablesVector, vector<Player *> &playersVector)
{
	tables = tablesVector;
	players = playersVector;
	for (size_t i = 0; i < tables.size(); i++) {
		dealers.push_back(tables.at(i)->getDealer());
	}
}

void Casino::addTablesToCasino(vector<Table*> tables)
{
	for (size_t i = 0; i < tables.size(); i++) {
		addTableToCasino(tables.at(i));
	}
}

void Casino::addTableToCasino(Table * table)
{
	try {
		for (size_t i = 0; i < tables.size(); i++) {
			if (tables.at(i) == table) {
				throw ExistingTable(table);
			}
			tables.push_back(table);
		}
		tables.push_back(table);
	}
	catch (ExistingTable &e) {
		e.what();
	}
}

void Casino::addPlayerToCasino(Player * player1)
{
	players.push_back(player1);
}

void Casino::addPlayersToCasino(vector<Player*>& newPlayers)
{
	players.insert(players.end(), newPlayers.begin(), newPlayers.end());
}


void Casino::addPlayersToTable(vector<Player*>& playersVector, Table * table)
{
	for (size_t i = 0; i < playersVector.size(); i++) {
		addPlayerToTable(playersVector.at(i),table);
	}
}

void Casino::addPlayerToTable(Player * player1, Table * table)
{
	bool foundPlayer = false;
	bool foundTable = false;
	try {
		for (size_t i = 0; i < tables.size(); i++) {
			if (tables.at(i) == table) {
				foundTable = true;
			}
		}
		if (foundTable == false) {
			throw TableNotInCasino(table);
		}

		for (size_t i = 0; i < players.size(); i++) {
			if (players.at(i) == player1) {
				foundPlayer = true;
				table->addPlayer(player1);
				break;
			}
		}
		if (foundPlayer == false) {
			throw PlayerNotLogged(player1);
		}
		
	}
	catch (TooManyPlayers &e) {
		e.what();
	}
	catch (PlayerNotLogged &p) {
		p.what();
	}
}

void Casino::showStatistics()
{
	cout << "Statistics\n\n\n\n";
	cout << setw(15) << "NAME" << setw(15) << "BRAIN LEVEL" << setw(15) << "ROUNDS PLAYED" << setw(30) << "AVG. PROFIT" << endl;
	for (size_t i = 0; i < players.size(); i++) {
		players.at(i)->showStatistics();
	}

}

PlayerNotLogged::PlayerNotLogged(Player * player1)
{
	name = player1->getName();
}

void PlayerNotLogged::what()
{
	cout << name << " is not logged in this Casino, try to log in first.\n";
}

ExistingTable::ExistingTable(Table * table)
{
	id = table->getTableID();
}

void ExistingTable::what()
{
	cout << "Table ID." << id << " already exists in this casino\n";
}

TableNotInCasino::TableNotInCasino(Table * table)
{
	id = table->getTableID();
}

void TableNotInCasino::what()
{
	cout << "Table Id." << id << " is not registered in this casino\n";
}
