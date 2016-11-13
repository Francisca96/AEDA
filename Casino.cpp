#pragma once

#include "Casino.h"

Casino::Casino(unsigned int totalMoney)
{
	this->totalMoney = totalMoney;
}

Casino::Casino(unsigned int totalMoney,vector<Table*> &tablesVector, vector<Player *> &playersVector)
{
	addTablesToCasino(tablesVector);
	addPlayersToCasino(playersVector);
	for (size_t i = 0; i < tables.size(); i++) {
		dealers.push_back(tables.at(i)->getDealer());
	}
	this->totalMoney = totalMoney;
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
		}
		tables.push_back(table);
		totalMoney -= table->getInitialMoney();
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

void Casino::setPlayersFile(string playerFile) {
	this->playersFile = playerFile;
}

void Casino::setDealersFile(string dealersFile) {
	this->dealersFile = dealersFile;
}

void Casino::setTablesFile(string tablesFile) {
	this->tablesFile = tablesFile;
}

void Casino::readPlayersFile() {
	ifstream inFile(playersFile);
	string line;
	stringstream ssLine;
	string player;
	string name;
	unsigned int initialMoney, age;

	for (int i = 0; i < 3; i++)
	{
		if (inFile.is_open())
		{
			if (!players.empty()) players.clear();

			while (getline(inFile, line))
			{
				player = line.substr(0, line.find_first_of(" ; "));
				line.erase(0, line.find_first_of(" ; ") + 3);
				name = line.substr(0, line.find_first_of(";")-1);
				line.erase(0, line.find_first_of(";") + 2);
				initialMoney = stoi(line.substr(0, line.find_first_of(" ; ")), nullptr, 10);
				line.erase(0, line.find_first_of(" ; ") + 3);
				if (player == "3")
				{
					ssLine << line;
					ssLine >> age;
					Human *newHuman = new Human(name, age);
					newHuman->setInitialMoney(initialMoney);
					players.push_back(newHuman);
				}
				if (player == "0")
				{
					ssLine << line;
					ssLine >> age;
					Bot0 *newBot0 = new Bot0(name, initialMoney);
					players.push_back(newBot0);
				}
				if (player == "1")
				{
					ssLine << line;
					ssLine >> age;
					Bot1 *newBot1 = new Bot1(name, initialMoney);
					players.push_back(newBot1);
				}
				/*if (player == "2")
				{
					ssLine << line;
					ssLine >> age;
					Bot2 *newBot2 = new Bot2();
					players.push_back(newBot2);
				}*/
			}
			return;
		}
	}
	cout << "Fail to open players file" << endl;
}

void Casino::readDealersFile() {
	ifstream inFile(dealersFile);
	string line;
	for (int i = 0; i < 3; i++)
	{
		if (inFile.is_open())
		{
			if (!dealers.empty()) dealers.clear();

			while (getline(inFile, line))
			{
				Dealer *newDealer = new Dealer(stoi(line));
				dealers.push_back(newDealer);
			}
			return;
		}
	}
	cout << "Fail to open dealers file" << endl;
}

void Casino::readTablesFile() {
	ifstream inFile(tablesFile);
	string line;

	unsigned int tableID;
	unsigned int minBet;
	unsigned int maxBet;
	unsigned int initialMoney;
	unsigned int maxNumberOfPlayers;
	unsigned int dealerID;
	Dealer *dealerOfTable = new Dealer();

	for (int i = 0; i < 3; i++)
	{
		if (inFile.is_open())
		{
			if (!tables.empty()) tables.clear();

			while (getline(inFile, line))
			{
				tableID = stoi(line.substr(0, line.find_first_of(" ; ")));
				line.erase(0, line.find_first_of(" ; ") + 3);
				minBet = stoi(line.substr(0, line.find_first_of(" ; ")));
				line.erase(0, line.find_first_of(" ; ") + 3);
				maxBet = stoi(line.substr(0, line.find_first_of(" ; ")));
				line.erase(0, line.find_first_of(" ; ") + 3);
				initialMoney = stoi(line.substr(0, line.find_first_of(" ; ")));
				line.erase(0, line.find_first_of(" ; ") + 3);
				maxNumberOfPlayers = stoi(line.substr(0, line.find_first_of(" ; ")));
				line.erase(0, line.find_first_of(" ; ") + 3);
				dealerID = stoi(line.substr(0, line.find_first_of(" ; ")));
				line.erase(0, line.find_first_of(" ; ") + 3);
				for (size_t i = 0; i < dealers.size(); i++)
				{
					if (dealers.at(i)->getID() == dealerID)
					{
						dealerOfTable = dealers.at(i);
						break;
					}
				}
				Table *newTable = new Table(minBet, maxBet, initialMoney, maxNumberOfPlayers, dealerOfTable);
				newTable->setID(tableID);
				tables.push_back(newTable);
			}
			return;
		}
	}
	cout << "Fail to read tables file" << endl;
}

void Casino::savePlayersFile() {
	ofstream outFile(playersFile);
	for (int i = 0; i < 3; i++)
	{
		if (outFile.is_open())
		{
			for (size_t i = 0; i < players.size(); i++)
			{
				Human *h = dynamic_cast<Human *>(players.at(i));
				Bot0 *b0 = dynamic_cast<Bot0 *>(players.at(i));
				Bot1 *b1 = dynamic_cast<Bot1 *>(players.at(i));
				Bot2 *b2 = dynamic_cast<Bot2 *>(players.at(i));
				if (h != NULL)
				{
					outFile << "3 ; " << players.at(i)->getName() << " ; " << players.at(i)->getInitialMoney() << " ; " << players.at(i)->getAge() << endl;
				}
				if (b0 != NULL)
				{
					outFile << "0 ; " << players.at(i)->getName() << " ; " << players.at(i)->getInitialMoney() << " ; " << players.at(i)->getAge() << endl;
				}
				if (b1 != NULL)
				{
					outFile << "1 ; " << players.at(i)->getName() << " ; " << players.at(i)->getInitialMoney() << " ; " << players.at(i)->getAge() << endl;
				}
				if (b2 != NULL)
				{
					outFile << "2 ; " << players.at(i)->getName() << " ; " << players.at(i)->getInitialMoney() << " ; " << players.at(i)->getAge() << endl;
				}
			}
			return;
		}
	}
	cout << "Fail to open players file" << endl;
}

void Casino::saveDealersFile() {
	ofstream outFile(dealersFile);
	for (int i = 0; i < 3; i++)
	{
		if (outFile.is_open())
		{
			for (size_t i = 0; i < dealers.size(); i++)
			{
				outFile << dealers.at(i)->getID() << endl;
			}
			return;
		}
	}
	cout << "Fail to open dealers file" << endl;
}

void Casino::saveTablesFile() {
	ofstream outFile(tablesFile);
	for (int i = 0; i < 3; i++)
	{
		if (outFile.is_open())
		{
			for (size_t i = 0; i < dealers.size(); i++)
			{
				outFile << tables.at(i)->getTableID() << " ; " << tables.at(i)->getMinBet() << " ; " << tables.at(i)->getMaxBet() << " ; " << tables.at(i)->getInitialMoney() << " ; " << tables.at(i)->getNumberMaxOfPlayers() << " ; " << tables.at(i)->getDealer()->getID() << " ; " << endl;
			}
			return;
		}
	}
	cout << "Fail to open tables file" << endl;
}

vector<Table*> Casino::getTables() const {
	return this->tables;
}

void Casino::setTableToPlay(unsigned int tableID) {
	this->tableToPlay = tableID;
}

void Casino::showStatistics() const {
	cout << "Statistics\n\n\n\n";
	cout << setw(15) << "NAME" << setw(15) << "BRAIN LEVEL" << setw(15) << "ROUNDS PLAYED" << setw(30) << "AVG. PROFIT" << endl;
	for (size_t i = 0; i < players.size(); i++) {
		players.at(i)->showStatistics();
	}

}

void Casino::showPlayers() const {
	for (size_t i = 0; i < players.size(); i++)
	{
		cout << players.at(i)->getName() << endl;
	}
}

void Casino::showDealers() const {
	for (size_t i = 0; i < dealers.size(); i++)
	{
		cout << dealers.at(i)->getID() << endl;
	}
}

void Casino::showTables() const {
	for (size_t i = 0; i < tables.size(); i++)
	{
		cout << tables.at(i)->getTableID() << endl;
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
