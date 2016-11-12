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
	string name;
	unsigned int initialMoney;
	unsigned int currentMoney;
	vector <Card> hand;
	unsigned int handScore;
	unsigned int roundsPlayed;
	float averageProfit;
	for (int i = 0; i < 3; i++)
	{
		if (inFile.is_open())
		{
			if (!players.empty()) players.clear();

			while (getline(inFile, line))
			{
				name = line.substr(0, line.find_first_of(" ; "));
				line.erase(0, line.find_first_of(" ; ") + 3);
				ssLine << line;
				ssLine >> initialMoney;
				line.erase(0, line.find_first_of(" ; ") + 3);
				ssLine << line;
				ssLine >> currentMoney;
				line.erase(0, line.find_first_of(" ; ") + 3);
				if (line.find_first_of("/") != string::npos)
				{

				}
				line.erase(0, line.find_first_of(" ; ") + 3);
				ssLine << line;
				ssLine >> handScore;
				line.erase(0, line.find_first_of(" ; ") + 3);
				ssLine << line;
				ssLine >> roundsPlayed;
				line.erase(0, line.find_first_of(" ; ") + 3);
				ssLine << line;
				ssLine >> averageProfit;
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

			}
			return;
		}
	}
	cout << "Fail to open dealers file" << endl;
}

void Casino::readTablesFile() {
	ifstream inFile(tablesFile);
	string line;
	stringstream ssLine;
	for (int i = 0; i < 3; i++)
	{
		if (inFile.is_open())
		{
			if (!tables.empty()) tables.clear();

			while (getline(inFile, line))
			{

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
				outFile << players.at(i)->getName() << " ; " << players.at(i)->getInitialMoney() << " ; " << players.at(i)->getCurrentMoney() << " ; ";
				for (size_t j = 0; j < players.at(i)->getHand().size(); j++)
				{
					outFile << " /" << players.at(i)->getHand().at(j);
				}
				outFile << " ; " << players.at(i)->getHandScore() << " ; " << players.at(i)->getRoundsPlayed() << " ; " << setprecision(2) << fixed << players.at(i)->getAverageProfit() << endl;
			}
			return;
		}
	}
	cout << "Fail to open delaers file" << endl;
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
