#pragma once

#include "Casino.h"

bool sortFunctionPlayers(Player *p1, Player *p2) {
	return p1->getName() < p2->getName();
}

bool sortFunctionTables(Table *t1, Table *t2) {
	return t1->getTableID() < t2->getTableID();
}

bool sortFunctionDealers(Dealer *d1, Dealer *d2) {
	if (d1->getTableOn() == -1 && d2->getTableOn() != -1)
	{
		return true;
	}
	else if (d1->getTableOn() == -1 && d2->getTableOn() == -1)
	{
		return d1->getID() < d2->getID();
	}
	else if (d1->getTableOn() != -1 && d2->getTableOn() != -1)
	{
		return d1->getID() < d2->getID();
	}
	else
	{
		return false;
	}
}

Casino::Casino(unsigned int totalMoney)
{
	this->totalMoney = totalMoney;
	vector<string> names = { "Albert", "Allen", "Bert", "Bob", "Cecil", "Clarence", "Elliot", "Elmer", "Eugene", "Fergus", "Ferris", "Frank", "Frasier", "Fred", "George", "Graham", "Harvey","Irwin", "Larry", "Lester", "Marvin", "Neil", "Niles", "Oliver", "Opie", "Ryan", "Toby", "Ulric", "Ulysses", "Uri", "Waldo", "Wally", "Walt", "Wesley", "Yanni", "Yogi", "Yuri" };
	for (int i = 0; i < names.size(); i++) {
		pair<string, bool> temp = { names.at(i),false };
		botNames.push(temp);
	}
}

Casino::Casino(unsigned int totalMoney, vector<Table*> &tablesVector, vector<Player *> &playersVector)
{
	addTablesToCasino(tablesVector);
	addPlayersToCasino(playersVector);
	for (size_t i = 0; i < tables.size(); i++) {
		dealers.push_back(tables.at(i)->getDealer());
	}
	this->totalMoney = totalMoney;
	vector<string> names = { "Albert", "Allen", "Bert", "Bob", "Cecil", "Clarence", "Elliot", "Elmer", "Eugene", "Fergus", "Ferris", "Frank", "Frasier", "Fred", "George", "Graham", "Harvey","Irwin", "Larry", "Lester", "Marvin", "Neil", "Niles", "Oliver", "Opie", "Ryan", "Toby", "Ulric", "Ulysses", "Uri", "Waldo", "Wally", "Walt", "Wesley", "Yanni", "Yogi", "Yuri" };
	for (int i = 0; i < names.size(); i++) {
		pair<string, bool> temp = { names.at(i),false };
		botNames.push(temp);
	}
}

bool Casino::login(pair<int, int> xy) {
	drawTitle(xy);
	string text, name, pass;
	cout << setw((xy.first - 36) / 2 - 1) << (char)201; //╔
	for (unsigned int i = 0; i <= 36; i++)
	{
		cout << (char)205; //═
	}
	cout << (char)187 << endl; //╗
	text = "Login";
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 //║
		<< setw((38 + text.length()) / 2) << text
		<< setw(38 - (38 + text.length()) / 2) << (char)186 << endl; //║
	cout << setw((xy.first - 36) / 2 - 1) << (char)204; //╠
	for (unsigned int i = 0; i <= 36; i++)
	{
		cout << (char)205; //═
	}
	cout << (char)185 /*╣*/ << endl;

	text = "UserName:";
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << " " << text << setw(38 - (4 + text.length())) << (char)186 << endl;

	cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)218;
	for (unsigned int i = 0; i <= 28; i++)
	{
		cout << (char)196;
	}
	cout << (char)191 << setw(4) << (char)186 << endl;
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)179 << setw(38 - 8) << (char)179 << setw(4) << (char)186 << endl;
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)192;
	for (unsigned int i = 0; i <= 28; i++)
	{
		cout << (char)196;
	}
	cout << (char)217 << setw(4) << (char)186 << endl;
	text = "Password:";
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << " " << text << setw(38 - (4 + text.length())) << (char)186 << endl;

	cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)218;
	for (unsigned int i = 0; i <= 28; i++)
	{
		cout << (char)196;
	}
	cout << (char)191 << setw(4) << (char)186 << endl;
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)179 << setw(38 - 8) << (char)179 << setw(4) << (char)186 << endl;
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)192;
	for (unsigned int i = 0; i <= 28; i++)
	{
		cout << (char)196;
	}
	cout << (char)217 << setw(4) << (char)186 << endl;

	cout << setw((xy.first - 36) / 2 - 1) << (char)200;
	for (unsigned int i = 0; i <= 36; i++)
	{
		cout << (char)205;
	}
	cout << (char)188 << endl << endl;
	cursorxy((xy.first - 36) / 2 + 4, 17);
	getline(cin, name);

	cursorxy((xy.first - 36) / 2 + 4, 21);
	int x = (xy.first - 36) / 2 + 4;
	char ch = 0;
	while (ch != 13) //character 13 is enter
	{
		ch = _getch();
		cursorxy(x, 21);
		if (ch == 8)
		{
			if (!pass.empty())
			{
				x--;
				cursorxy(x, 21);
				cout << ' ';
				cursorxy(x, 21);
				pass.pop_back();
			}
		}
		else
		{
			cout << '*';
			pass.push_back(ch);
			x++;
		}
	}
	cursorxy(0, 24);
	this->userLOGIN.first = name;
	this->userLOGIN.second = pass;
	if (userslogin.find(this->userLOGIN) != userslogin.end())
	{
		cout << "Login in Sucess" << endl;
		return true;
	}
	else
	{
		cout << "Login Fail" << endl;
		userslogin.insert(this->userLOGIN);
		throw PlayerNotExistException(name);
	}
}

string Casino::getUserLoginName() {
	return userLOGIN.first;
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
				throw ExistingTableException(table);
			}
		}
		tables.push_back(table);
		totalMoney -= table->getInitialMoney();
		sort(tables.begin(), tables.end(), sortFunctionTables);
	}
	catch (ExistingTableException &e) {
		e.what();
	}
}

void Casino::removeTableFromCasino(Table * table) {
	for (size_t i = 0; i < tables.size(); i++)
	{
		if (tables.at(i)->getTableID() == table->getTableID())
		{
			delete tables.at(i);
			tables.erase(tables.begin() + i);
			return;
		}
	}
	throw TableNotInCasinoException(table);
}

void Casino::addPlayerToCasino(Player * player1)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		if (player1->getName() == players.at(i)->getName())
		{
			throw PlayerAlreadyExistException(player1);
		}
	}
	players.push_back(player1);
}

void Casino::removePlayerFromCasino(string name) {
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players.at(i)->getName() == name)
		{
			if (players.at(i)->getOnTable() != -1)
			{
				throw PlayerStillOnTableException(players.at(i));
			}
			delete players.at(i);
			players.erase(players.begin() + i);
			return;
		}
	}
	throw PlayerNotExistException(name);
}

void Casino::addPlayersToCasino(vector<Player*>& newPlayers)
{
	players.insert(players.end(), newPlayers.begin(), newPlayers.end());
}


void Casino::addPlayersToTable(vector<Player*>& playersVector, Table * table)
{
	for (size_t i = 0; i < playersVector.size(); i++) {
		addPlayerToTable(playersVector.at(i), table);
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
			throw TableNotInCasinoException(table);
		}

		for (size_t i = 0; i < players.size(); i++) {
			if (players.at(i) == player1) {
				foundPlayer = true;
				table->addPlayer(player1);
				break;
			}
		}
		if (foundPlayer == false) {
			throw PlayerNotLoggedException(player1);
		}

	}
	catch (TooManyPlayersException &e) {
		e.what();
	}
	catch (PlayerNotLoggedException &p) {
		p.what();
	}
}

void Casino::addDealerToCasino(Dealer * newDealer) {
	for (size_t i = 0; i < dealers.size(); i++)
	{
		if (newDealer->getID() == dealers.at(i)->getID())
		{
			throw DealerAlreadyExistException(newDealer);
		}
	}
	dealers.push_back(newDealer);
}

void Casino::removeDealerFromCasino(Dealer *dealer) {
	for (size_t i = 0; i < dealers.size(); i++)
	{
		if (dealers.at(i)->getID() == dealer->getID())
		{
			if (dealers.at(i)->getTableOn() != -1)
			{
				throw DealerStillOnTableException(dealers.at(i));
			}
			delete dealers.at(i);
			dealers.erase(dealers.begin() + i);
			return;
		}
	}
	throw DealerNotExistException(dealer);
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

void Casino::setUsersFile(string usersFile) {
	this->usersFile = usersFile;
}

void Casino::readPlayersFile() {
	ifstream inFile(playersFile);
	string line;
	stringstream ssLine;
	string player;
	string name;
	unsigned int initialMoney, age, tableOnID;

	for (int i = 0; i < 3; i++)
	{
		if (inFile.is_open())
		{
			if (!players.empty()) players.clear();

			while (getline(inFile, line))
			{
				player = line.substr(0, line.find_first_of(" ; "));
				line.erase(0, line.find_first_of(" ; ") + 3);
				name = line.substr(0, line.find_first_of(";") - 1);
				line.erase(0, line.find_first_of(";") + 2);
				initialMoney = stoi(line.substr(0, line.find_first_of(" ; ")), nullptr, 10);
				line.erase(0, line.find_first_of(" ; ") + 3);
				if (player == "3")
				{
					ssLine << line;
					ssLine >> age;
					ssLine.clear();
					Human *newHuman = new Human(name, age, -1);
					newHuman->setInitialMoney(initialMoney);
					players.push_back(newHuman);
				}
				if (player == "0")
				{
					ssLine << line;
					ssLine >> tableOnID;
					ssLine.clear();
					Bot0 *newBot0 = new Bot0(name, initialMoney);
					newBot0->setOnTable(tableOnID);
					players.push_back(newBot0);
				}
				if (player == "1")
				{
					ssLine << line;
					ssLine >> tableOnID;
					ssLine.clear();
					Bot1 *newBot1 = new Bot1(name, initialMoney);
					newBot1->setOnTable(tableOnID);
					players.push_back(newBot1);
				}
				if (player == "2")
				{
					ssLine << line;
					ssLine >> tableOnID;
					ssLine.clear();
					Bot2 *newBot2 = new Bot2(name, initialMoney);
					newBot2->setOnTable(tableOnID);
					players.push_back(newBot2);
				}
			}
			sort(players.begin(), players.end(), sortFunctionPlayers);
			return;
		}
	}
	cout << "Fail to open players file" << endl;
}

void Casino::readDealersFile() {
	ifstream inFile(dealersFile);
	string line;
	unsigned int nextID;
	for (int i = 0; i < 3; i++)
	{
		if (inFile.is_open())
		{
			if (!dealers.empty()) dealers.clear();
			getline(inFile, line);
			nextID = stoi(line);
			while (getline(inFile, line))
			{
				Dealer *newDealer = new Dealer(stoi(line));
				try
				{
					this->addDealerToCasino(newDealer);
				}
				catch (DealerAlreadyExistException dealer)
				{
					cout << "Dealer with ID : " << dealer.getID() << " already exist" << endl;
				}
			}
			Dealer::setNextID(nextID);
			return;
		}
	}
	unsigned int maxID = 0;
	for (size_t i = 0; i < dealers.size(); i++)
	{
		if (dealers.at(i)->getID() >= maxID)
		{
			maxID = dealers.at(i)->getID() + 1;
		}
	}
	Dealer::setNextID(maxID);
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
	unsigned int nextID;
	Dealer *dealerOfTable = new Dealer();

	for (int i = 0; i < 3; i++)
	{
		if (inFile.is_open())
		{
			if (!tables.empty()) tables.clear();
			getline(inFile, line);
			nextID = stoi(line);
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
						dealers.at(i)->setTable(tableID);
						break;
					}
				}
				Table *newTable = new Table(minBet, maxBet, initialMoney, maxNumberOfPlayers, dealerOfTable);
				newTable->setID(tableID);
				if (line == "{")
				{
					while (line != "}")
					{
						getline(inFile, line);
						if (line.substr(0, 1) == "0")
						{
							Player *playerReaded = new Bot0(line);
							newTable->addPlayer(playerReaded);
							try
							{
								players.at(findPlayer(playerReaded->getName())) = playerReaded;
							}
							catch (PlayerNotExistException)
							{
								addPlayerToCasino(playerReaded);
							}
						}
						else if (line.substr(0, 1) == "1")
						{
							Player *playerReaded = new Bot1(line);
							newTable->addPlayer(playerReaded);
							try
							{
								players.at(findPlayer(playerReaded->getName())) = playerReaded;
							}
							catch (PlayerNotExistException)
							{
								addPlayerToCasino(playerReaded);
							}
						}
						else if (line.substr(0, 1) == "2")
						{
							Player *playerReaded = new Bot2(line);
							newTable->addPlayer(playerReaded);
							try
							{
								players.at(findPlayer(playerReaded->getName())) = playerReaded;
							}
							catch (PlayerNotExistException)
							{
								addPlayerToCasino(playerReaded);
							}
						}
						else if (line.substr(0, 1) == "3")
						{
							Player *playerReaded = new Human(line);
							newTable->addPlayer(playerReaded);
							try
							{
								players.at(findPlayer(playerReaded->getName())) = playerReaded;
							}
							catch (PlayerNotExistException)
							{
								addPlayerToCasino(playerReaded);
							}
						}
					}
				}
				this->addTableToCasino(newTable);
			}
			Table::setNextID(nextID);
			sort(dealers.begin(), dealers.end(), sortFunctionDealers);
			return;
		}
	}
	cout << "Fail to read tables file" << endl;
}

void Casino::readLoginFile() {
	ifstream inFile(usersFile);
	string line, name, pass;
	for (int i = 0; i < 3; i++)
	{
		if (inFile.is_open())
		{
			while (getline(inFile, line))
			{
				name = line.substr(0, line.find(";"));
				line.erase(0, line.find(";") + 1);
				pass = line.substr(0, line.find(";"));
				pair <string, string> user(name, pass);
				userslogin.insert(user);
			}
			return;
		}
	}
	cout << "Fail to read tables file" << endl;
}

void Casino::savePlayersFile() {
	ofstream outFile(playersFile);
	for (int j = 0; j < 3; j++)
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
					outFile << "0 ; " << players.at(i)->getName() << " ; " << players.at(i)->getInitialMoney() << " ; " << players.at(i)->getOnTable() << endl;
				}
				if (b1 != NULL)
				{
					outFile << "1 ; " << players.at(i)->getName() << " ; " << players.at(i)->getInitialMoney() << " ; " << players.at(i)->getOnTable() << endl;
				}
				if (b2 != NULL)
				{
					outFile << "2 ; " << players.at(i)->getName() << " ; " << players.at(i)->getInitialMoney() << " ; " << players.at(i)->getOnTable() << endl;
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
			outFile << Dealer::getNextID() << endl;
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
			outFile << Table::getNextId() << endl;
			for (size_t i = 0; i < tables.size(); i++)
			{
				outFile << tables.at(i)->getTableID() << " ; " << tables.at(i)->getMinBet() << " ; " << tables.at(i)->getMaxBet() << " ; " << tables.at(i)->getInitialMoney() << " ; " << tables.at(i)->getNumberMaxOfPlayers() << " ; " << tables.at(i)->getDealer()->getID() << " ; ";
				if (tables.at(i)->getPlayers().size() != 0)
				{
					outFile << "{" << endl;
				}
				else
				{
					outFile << endl;
				}
				for (size_t j = 0; j < tables.at(i)->getPlayers().size(); j++)
				{
					tables.at(i)->getPlayers().at(j)->saveInfo(outFile);
					outFile << endl;
				}
				if (tables.at(i)->getPlayers().size() != 0)
				{
					outFile << "}" << endl;
				}
			}
			return;
		}
	}
	cout << "Fail to open tables file" << endl;
}

void Casino::saveLoginFile() {
	ofstream outFile(usersFile);
	for (int i = 0; i < 3; i++)
	{
		if (outFile.is_open())
		{
			for (loginHash::iterator it = userslogin.begin(); it != userslogin.end(); it++)
			{
				outFile << it->first << ";" << it->second << ";" << endl;
			}
			return;
		}
	}
	cout << "Fail to open tables file" << endl;
}

vector<Table*> Casino::getTables() const {
	return this->tables;
}

void Casino::selectTable(pair<short, short> xy) {
	this->showTables(xy);
	cout << "Select table by ID" << endl;
	unsigned int tableID = readInt();
	for (size_t i = 0; i < tables.size(); i++)
	{
		if (tables.at(i)->getTableID() == tableID)
		{
			this->setTableToPlay(tableID);
			cout << "Table select with success" << endl;
			return;
		}
	}
	throw TableNotInCasinoException(new Table(tableID));
}

void Casino::setTableToPlay(int tableID) {
	this->tableToPlay = tableID;
}

Table * Casino::getTableToPlay() const {
	if (this->tableToPlay != -1)
	{
		for (size_t i = 0; i < tables.size(); i++)
		{
			if (this->tableToPlay == tables.at(i)->getTableID())
			{
				return tables.at(i);
			}
		}
	}
	throw TableNotInCasinoException(new Table(tableToPlay));
}

void Casino::manage(pair<short, short> xy) {
	unsigned int exit = 0;
	unsigned int choice, tableID;
	while (!exit)
	{
		manageCasino(xy, choice);
		switch (choice)
		{
		case 0:
			exit = 1;
			break;
		case 1:
			this->create(xy);
			break;
		case 2:
			this->eliminate(xy);
			break;
		case 3:
			this->showTables(xy);
			try
			{
				cout << "Select table by ID" << endl;
				tableID = readUnsignedInt();
				this->findTable(tableID);
				this->manageTables(xy, tableID);
			}
			catch (TableNotInCasinoException)
			{
				cout << "This table not exist" << endl;
				system("pause");
			}
			break;
		case 4:
			system("cls");
			fillBestPlayersSet();
			this->showStatisticsMenu(xy);
			system("pause");
			break;
		default:
			break;
		}
	}
}

void Casino::create(pair<short, short> xy) {
	unsigned int exit = 0;
	unsigned int choice;
	string newBotName;
	vector<Player*> tempBots;
	int numberOfBots;
	string text, name, pass;
	int x = (xy.first - 36) / 2 + 4;
	char ch = 0;
	pair <string, string> newUser;
	loginHash::iterator it;
	while (!exit)
	{
		createMenu(xy, choice);
		switch (choice)
		{
		case 0:
			exit = 1;
			break;
		case 1:
			try
			{
				unsigned int minBet, maxBet, numberMaxOfPlayer, initialMoney, dealerID, found = 0;
				Dealer *dealerOfTable;
				dealersPriority dq;
				for (size_t i = 0; i < dealers.size(); i++)
				{
					dq.push(dealers.at(i));
				}
				system("CLS");
				cout << "Initial Money?" << endl;
				initialMoney = readUnsignedIntBetween(10000, 50000);
				cout << "Min Bet?" << endl;
				minBet = readUnsignedIntBetween(1, initialMoney / 1000);
				cout << "Max Bet?" << endl;
				maxBet = readUnsignedIntBetween(minBet, 32 * minBet);
				cout << "Number Max Of Players?" << endl;
				numberMaxOfPlayer = readUnsignedIntBetween(1, 6);
				this->showDealers(xy);
				dealerID = dq.top()->getID();
				cout << "The dealers with ID: " << dealerID << " will be set for this table" << endl;
				dealerOfTable = dq.top();

				if (dealerOfTable->getTableOn() == -1)
				{
					Table *newTable = new Table(minBet, maxBet, initialMoney, numberMaxOfPlayer, dealerOfTable);
					this->addTableToCasino(newTable);
				}
				else
				{
					throw DealerIsOnTableAlreadyException(new Dealer(dealerID));
				}
				cout << "Tables was created with success" << endl;
				system("pause");
			}
			catch (DealerNotExistException)
			{
				cout << "Tables wasn't created with success" << endl;
				cout << "The Dealer doesn't exist, pls try again" << endl;
				system("pause");
			}
			catch (DealerIsOnTableAlreadyException)
			{
				cout << "Tables wasn't created with success" << endl;
				cout << "The Dealer have one table already, pls try again" << endl;
				system("pause");
			}
			break;
		case 2:
			try
			{
				Dealer *newDealer = new Dealer();
				this->addDealerToCasino(newDealer);
				cout << "Dealer was created with success" << endl;
				system("pause");
			}
			catch (DealerAlreadyExistException)
			{
				cout << "Dealer wasn't created with success" << endl;
				cout << "This Dealer already Exist" << endl;
				system("pause");
			}
			break;
		case 3:
			try
			{
				Player *newBot = new Bot0();
				string name;
				while (name.length() == 0)
				{
					cout << "What name do you want for bot?" << endl;
					getline(cin, name);
				}
				cout << "How many initial money do you want for bot?" << endl;
				unsigned int money = readUnsignedInt();
				cout << "What Bot do you want create (0 , 1 , 2)?" << endl;
				unsigned int botInteligent = readUnsignedIntBetween(0, 2);
				if (botInteligent == 0)
				{
					newBot = new Bot0(name, money);
				}
				if (botInteligent == 1)
				{
					newBot = new Bot1(name, money);
				}
				if (botInteligent == 2)
				{
					newBot = new Bot2(name, money);
				}
				this->addPlayerToCasino(newBot);
				cout << "Player was created with success" << endl;
				system("pause");
			}
			catch (PlayerAlreadyExistException)
			{
				cout << "Player wasn't created with success" << endl;
				cout << "This Player already Exist" << endl;
				system("pause");
			}
			break;
		case 4:
			system("CLS");
			cout << setw((xy.first - 36) / 2 - 1) << (char)201; //╔
			for (unsigned int i = 0; i <= 36; i++)
			{
				cout << (char)205; //═
			}
			cout << (char)187 << endl; //╗
			text = "Login";
			cout << setw((xy.first - 36) / 2 - 1) << (char)186 //║
				<< setw((38 + text.length()) / 2) << text
				<< setw(38 - (38 + text.length()) / 2) << (char)186 << endl; //║
			cout << setw((xy.first - 36) / 2 - 1) << (char)204; //╠
			for (unsigned int i = 0; i <= 36; i++)
			{
				cout << (char)205; //═
			}
			cout << (char)185 /*╣*/ << endl;
			text = "UserName:";
			cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << " " << text << setw(38 - (4 + text.length())) << (char)186 << endl;
			cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)218;
			for (unsigned int i = 0; i <= 28; i++)
			{
				cout << (char)196;
			}
			cout << (char)191 << setw(4) << (char)186 << endl;
			cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)179 << setw(38 - 8) << (char)179 << setw(4) << (char)186 << endl;
			cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)192;
			for (unsigned int i = 0; i <= 28; i++)
			{
				cout << (char)196;
			}
			cout << (char)217 << setw(4) << (char)186 << endl;
			text = "Password:";
			cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << " " << text << setw(38 - (4 + text.length())) << (char)186 << endl;
			cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)218;
			for (unsigned int i = 0; i <= 28; i++)
			{
				cout << (char)196;
			}
			cout << (char)191 << setw(4) << (char)186 << endl;
			cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)179 << setw(38 - 8) << (char)179 << setw(4) << (char)186 << endl;
			cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(4) << (char)192;
			for (unsigned int i = 0; i <= 28; i++)
			{
				cout << (char)196;
			}
			cout << (char)217 << setw(4) << (char)186 << endl;
			cout << setw((xy.first - 36) / 2 - 1) << (char)200;
			for (unsigned int i = 0; i <= 36; i++)
			{
				cout << (char)205;
			}
			cout << (char)188 << endl << endl;
			cursorxy((xy.first - 36) / 2 + 4, 5);
			getline(cin, name);
			cursorxy((xy.first - 36) / 2 + 4, 9);
			while (ch != 13) //character 13 is enter
			{
				ch = _getch();
				cursorxy(x, 9);
				if (ch == 8)
				{
					if (!pass.empty())
					{
						x--;
						cursorxy(x, 9);
						cout << ' ';
						cursorxy(x, 9);
						pass.pop_back();
					}
				}
				else
				{
					cout << '*';
					pass.push_back(ch);
					x++;
				}
			}
			cursorxy(0, 24);
			newUser.first = name;
			newUser.second = pass;
			it = userslogin.find(newUser);
			if (it == userslogin.end())
			{
				userslogin.insert(newUser);
				cout << "Account was created with success!" << endl;
				system("pause");
			}
			else {
				cout << "Account wasn't created with success!" << endl;
				system("pause");
			}
			break;
		case 5:
		{
			Player * newBot = new Bot0();
			cout << "Number of bots to create (Max =" << botNames.size() << " ) :";
			numberOfBots = readIntBetween(1, botNames.size());
			if (numberOfBots > botNames.size()) {
				cout << "There are only " << botNames.size() << " names available in the database.\n";
				cout << botNames.size() << " bots will be added to this casino.\n";
				numberOfBots = botNames.size();
			}
			for (int i = 0; i < numberOfBots; i++) {
				if (botNames.empty()) {
					cout << "There are no more names in the database\n";
					break;
				}
				newBotName = botNames.top().first;
				botNames.pop();
				int randomIntelligence = rand() % 3;
				if (randomIntelligence == 0) {
					newBot = new Bot0(newBotName, 1000);
				}
				else if (randomIntelligence == 1) {
					newBot = new Bot1(newBotName, 1000);
				}
				else if (randomIntelligence == 2) {
					newBot = new Bot2(newBotName, 1000);
				}
				newBot->setAge(rand() % 82 + 18);
				tempBots.push_back(newBot);
			}
			addPlayersToCasino(tempBots);
			system("pause");
			break;
		}
		default:
			break;
		}
	}
}

void Casino::eliminate(pair<short, short> xy) {
	unsigned int exit = 0;
	unsigned int choice;
	while (!exit)
	{
		deleteMenu(xy, choice);
		switch (choice)
		{
		case 0:
			exit = 1;
			break;
		case 1:
			try
			{
				this->showTables(xy);
				unsigned int tableID = readUnsignedInt();
				Table *table = new Table(tableID);
				this->removeTableFromCasino(table);
				cout << "The tablet was deleted with success" << endl;
				system("pause");
			}
			catch (TableNotInCasinoException)
			{
				cout << "The tablet wasn´t deleted with success" << endl;
				cout << "The tablet doesn't exist" << endl;
				system("pause");
			}
			break;
		case 2:
			try
			{
				this->showDealers(xy);
				unsigned int dealerID = readUnsignedInt();
				Dealer *dealer = new Dealer(dealerID);
				this->removeDealerFromCasino(dealer);
				cout << "The dealer was deleted with success" << endl;
				system("pause");
			}
			catch (DealerNotExistException)
			{
				cout << "The dealer wasn´t deleted with success" << endl;
				cout << "The dealer doesn't exist" << endl;
				system("pause");
			}
			catch (DealerStillOnTableException dealer)
			{
				cout << "The dealer wasn´t deleted with success" << endl;
				cout << "The dealer still on table : " << dealer.getTableID() << " please remove from table first" << endl;
				system("pause");
			}
			break;
		case 3:
			try
			{
				this->showPlayers(xy);
				string name;
				while (name.length() == 0)
				{
					cout << "What is the name of bot to remove?" << endl;
					getline(cin, name);
				}
				this->removePlayerFromCasino(name);
				pair<string, bool> p = {name, true};
				botNames.push(p);
				cout << "The player was deleted with success" << endl;
				system("pause");
			}
			catch (PlayerNotExistException)
			{
				cout << "The player wasn´t deleted with success" << endl;
				cout << "The player doesn't exist" << endl;
				system("pause");
			}
			catch (PlayerStillOnTableException player)
			{
				cout << "The player wasn´t deleted with success" << endl;
				cout << "The player still on table : " << player.getTableId() << " please remove from table first" << endl;
				system("pause");
			}
			break;
		case 4:
			try
			{
				system("cls");
				cout << "How many accounts do you want to show?" << endl;
				int n;
				stringstream ss;
				string line;
				getline(cin, line);
				ss << line;
				ss >> n;
				this->showUsers(n);
				cout << "What is the username?" << endl;
				string name;
				getline(cin, name);
				cout << "What is the password?" << endl;
				string pass;
				getline(cin, pass);
				pair<string, string> user(name, pass);
				loginHash::iterator it = userslogin.find(user);
				if (it != userslogin.end())
				{
					cout << "Do you want remove(0)/edit(1)?" << endl;
					stringstream ss2;
					string line2;
					getline(cin, line2);
					ss2 << line2;
					ss2 >> n;
					if (n == 0)
					{
						userslogin.erase(it);
						cout << "Account was removed with success!" << endl;
						system("pause");
					}
					else if(n == 1) {
						cout << "What is the new password?" << endl;
						getline(cin, pass);
						pair<string, string> newUser(name, pass);
						userslogin.erase(it);
						userslogin.insert(newUser);
					}
				}
				else
				{
					cout << "Account wasn´t removed with success!" << endl;
					system("pause");
				}

			}
			catch (exception& e)
			{
				cout << e.what() << endl;
			}
			break;
		default:
			break;
		}
	}
}

void Casino::manageTables(pair<short, short> xy, unsigned int tableID) {
	unsigned int exit = 0;
	unsigned int choice, dealerID;
	string playerName;
	while (!exit)
	{
		manageTableMenu(xy, choice);
		switch (choice)
		{
		case 0:
			exit = 1;
			break;
		case 1:
			try
			{
				showDealers(xy);
				dealerID = readUnsignedInt();
				unsigned int dealerIndex = this->findDealer(dealerID);
				if (dealers.at(dealerIndex)->getTableOn() != -1)
				{
					throw DealerIsOnTableAlreadyException(dealers.at(dealerIndex));
				}
				tables.at(this->findTable(tableID))->setDealer(dealers.at(dealerIndex));
				cout << "Dealer was set with success" << endl;
				system("pause");
			}
			catch (DealerNotExistException)
			{
				cout << "Dealer wasn't set with success" << endl;
				cout << "This Dealer not exist" << endl;
				system("pause");
			}
			catch (DealerIsOnTableAlreadyException)
			{
				cout << "Dealer wasn't set with success" << endl;
				cout << "This Dealer have one table for him already" << endl;
				system("pause");
			}
			catch (TableNotInCasinoException &table)
			{
				throw table;
			}
			break;
		case 2:
			try
			{
				if (tables.at(findTable(tableID))->getPlayers().size() == tables.at(findTable(tableID))->getNumberMaxOfPlayers())
				{
					throw TooManyPlayersException(tables.at(findTable(tableID))->getNumberMaxOfPlayers(), tables.at(findTable(tableID))->getNumberMaxOfPlayers() + 1);
				}
				showPlayers(xy);
				cout << "Select the player that you want to add to the table" << endl;
				playerName = "";
				while (playerName.length() == 0)
				{
					getline(cin, playerName);
				}
				unsigned int playerIndex = findPlayer(playerName);
				if (players.at(playerIndex)->getOnTable() != -1)
				{
					throw PlayerStillOnTableException(players.at(playerIndex));
				}
				tables.at(findTable(tableID))->addPlayer(players.at(playerIndex));
				cout << "Player was added with success to table" << endl;
				system("pause");
			}
			catch (TableNotInCasinoException &table)
			{
				throw table;
			}
			catch (PlayerNotExistException)
			{
				cout << "The player wasn't added to table" << endl;
				cout << "The player does not exist" << endl;
				system("pause");
			}
			catch (PlayerStillOnTableException)
			{
				cout << "The player wasn't added to table" << endl;
				cout << "The player is on other table already" << endl;
				system("pause");
			}
			catch (TooManyPlayersException)
			{
				cout << "The player wasn't added to table" << endl;
				cout << "The table is full" << endl;
				system("pause");
			}
			break;
		case 3:
			try
			{
				Table *table = tables.at(findTable(tableID));
				if (table->getPlayers().size() == 0)
				{
					throw NoPlayersOnTableException(table);
				}
				for (size_t i = 0; i < table->getPlayers().size(); i++)
				{
					cout << table->getPlayers().at(i)->getName() << endl;
				}
				playerName = "";
				while (playerName.length() == 0)
				{
					getline(cin, playerName);
				}
				table = tables.at(findTable(tableID));
				table->removePlayer(playerName);
				cout << "Player was removed from table with success" << endl;
				system("pause");
			}
			catch (TableNotInCasinoException &table)
			{
				throw table;
			}
			catch (PlayerNotExistException)
			{
				cout << "The player wasn't remove from table" << endl;
				cout << "The player does not exist" << endl;
				system("pause");
			}
			catch (PlayerIsntOnTableException)
			{
				cout << "The player wasn't remove from table" << endl;
				cout << "The player wasn't on table" << endl;
				system("pause");
			}
			catch (NoPlayersOnTableException)
			{
				cout << "The table dont have players to remove" << endl;
				system("pause");
			}
			break;
		default:
			break;
		}
	}

}

unsigned int Casino::findTable(unsigned int tableID) {
	for (size_t i = 0; i < tables.size(); i++)
	{
		if (tables.at(i)->getTableID() == tableID)
		{
			return i;
		}
	}
	throw TableNotInCasinoException(new Table(tableID));
}

unsigned int Casino::findDealer(unsigned int dealerID) {
	for (size_t i = 0; i < dealers.size(); i++)
	{
		if (dealers.at(i)->getID() == dealerID)
		{
			return i;
		}
	}
	throw DealerNotExistException(new Dealer(dealerID));
}

unsigned int Casino::findPlayer(string name) {
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players.at(i)->getName() == name)
		{
			return i;
		}
	}
	throw PlayerNotExistException(name);
}


void Casino::fillBestPlayersSet() {
	for (auto i = players.begin(); i != players.end(); i++) {
		if (bestPlayers.find((*i)) == bestPlayers.end() && (*i)->getRoundsPlayed() > 0) {
			bestPlayers.insert((*i));
		}
	}
}

void Casino::showUsers(int n) {
	system("cls");
	string text, name;
	stringstream sstext;
	int i = 0;
	cout << (char)218; //┌
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)191 << endl; //┐
	cout << (char)179; //│
	cout << setw((50 + 13) / 2 + 1) << "Accounts Info" << setw(50 - (50 + 13) / 2 + 1) << (char)179 << endl;
	cout << (char)195; //├
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)180 << endl; //┤
	cout << (char)179; //│
	cout << setw(13) << "username" << setw(21) << "pass" << setw(18) << (char)179 << endl;
	cout << (char)195; //├
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)180 << endl; //┤
	for (loginHash::iterator it = userslogin.begin(); it != userslogin.end() && i < n; it++)
	{
		i++;
		name = it->first;
		text = it->second;
		cout << setw(5) << " " << name << setw(26-name.length()) << " " << text << endl;
	}
	cout << (char)192; //└
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)217 << endl; //┘
}

void Casino::showStatisticsMenu(pair<short, short> xy)
{

	set<Player*, CompareByAge> setByAge;
	set<Player*, CompareByName> setByName;
	set<Player*, CompareByIntelligence> setBySmart;
	int r, exit = 0;
	unsigned int choice;
	int numberOfPlayers;
	
	while (!exit)
	{
		statisticsMenu(xy, choice);
		numberOfPlayers = bestPlayers.size();
		if (choice != 0) {
			cout << "How many players do you want to see? ";
			if ((r = readIntBetween(0,65536)) < numberOfPlayers) {
				numberOfPlayers = r;
			}
		}
		switch (choice)
		{
		case 0: //break
			exit = 1;
			break;
		case 1: //Order by avg.profit
			showStatistics(bestPlayers, numberOfPlayers);
			break;
		case 2: //Order by age

			for (auto i = bestPlayers.begin(); i != bestPlayers.end(); i++) {
					setByAge.insert((*i));
			}
			showStatistics(setByAge, numberOfPlayers);
			break;
		case 3: //Order by name

			for (auto i = bestPlayers.begin(); i != bestPlayers.end(); i++) {
				setByName.insert((*i));
			}
			showStatistics(setByName, numberOfPlayers);
			break;
		case 4: //Order by Intelligence

			for (auto i = bestPlayers.begin(); i != bestPlayers.end(); i++) {
				setBySmart.insert((*i));
			}
			showStatistics(setBySmart, numberOfPlayers);
			break;
		default:
			break;
		}
	}
}

void Casino::showPlayers(pair <short, short> xy) const {
	system("cls");
	string text, name;
	stringstream sstext;
	cout << setw((xy.first - 50) / 2 - 1) << (char)218; //┌
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)191 << endl; //┐
	cout << setw((xy.first - 50) / 2 - 1) << (char)179; //│
	cout << setw((50 + 12) / 2 + 1) << "Players Info" << setw(50 - (50 + 12) / 2 + 1) << (char)179 << endl;
	cout << setw((xy.first - 50) / 2 - 1) << (char)195; //├
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)180 << endl; //┤
	cout << setw((xy.first - 50) / 2 - 1) << (char)179; //│
	cout << setw(13) << "Player Name" << setw(21) << "On Table" << setw(18) << (char)179 << endl;
	cout << setw((xy.first - 50) / 2 - 1) << (char)195; //├
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)180 << endl; //┤
	for (size_t i = 0; i < players.size(); i++)
	{
		cout << setw((xy.first - 50) / 2 - 1) << (char)179; //│
		name = players.at(i)->getName();
		cout << setw(2) << " " << name << setw(24 - name.length()) << " ";
		if (players.at(i)->getOnTable() != -1)
		{
			sstext.clear();
			sstext << players.at(i)->getOnTable();
			sstext >> text;
		}
		else
		{
			text = "Player isn't allocated";
		}
		cout << text << setw(26 - text.length()) << (char)179 << endl;
	}
	cout << setw((xy.first - 50) / 2 - 1) << (char)192; //└
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)217 << endl; //┘
}

void Casino::showDealers(pair <short, short> xy) const {
	system("cls");
	dealersPriority dq;
	for (size_t i = 0; i < dealers.size(); i++)
	{
		dq.push(dealers.at(i));
	}
	string text;
	stringstream sstext;
	cout << setw((xy.first - 50) / 2 - 1) << (char)218; //┌
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)191 << endl; //┐
	cout << setw((xy.first - 50) / 2 - 1) << (char)179; //│
	cout << setw((50 + 12) / 2 + 1) << "Dealers Info" << setw(50 - (50 + 12) / 2 + 1) << (char)179 << endl;
	cout << setw((xy.first - 50) / 2 - 1) << (char)195; //├
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)180 << endl; //┤
	cout << setw((xy.first - 50) / 2 - 1) << (char)179; //│
	cout << setw(10) << "DealerID" << setw(15) << "On Table" << setw(27) << (char)179 << endl;
	cout << setw((xy.first - 50) / 2 - 1) << (char)195; //├
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)180 << endl; //┤
	while (!dq.empty())
	{
		cout << setw((xy.first - 50) / 2 - 1) << (char)179; //│
		if (dq.top()->getTableOn() != -1)
		{
			sstext.clear();
			sstext << dq.top()->getTableOn();
			sstext >> text;
		}
		else
		{
			text = "Dealer isn't allocated";
		}
		cout << setw(10) << dq.top()->getID() << setw(7) << " " << text << setw(35-text.length()) << (char)179 << endl;
		dq.pop();
	}
	cout << setw((xy.first - 50) / 2 - 1) << (char)192; //└
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)196; //─
	}
	cout << (char)217 << endl; //┘
}

void Casino::showTables(pair <short, short> xy) {
	system("CLS");
	bool found = false;
	pair <short, short> coordXY;
	coordXY.first = (xy.first % 32) / 2 - 1;

	for (size_t i = 0; i < tables.size(); i++)
	{
		tables.at(i)->showTableInfo(coordXY);
		coordXY.first += 32;
		if (coordXY.first + 32 > xy.first)
		{
			coordXY.first = (xy.first % 32) / 2 - 1;
			coordXY.second += 14;
		}
	}
	cout << endl << endl << endl;
}

PlayerNotLoggedException::PlayerNotLoggedException(Player * player1)
{
	name = player1->getName();
}

void PlayerNotLoggedException::what()
{
	cout << name << " is not logged in this Casino, try to log in first.\n";
}

ExistingTableException::ExistingTableException(Table * table)
{
	id = table->getTableID();
}

void ExistingTableException::what()
{
	cout << "Table ID." << id << " already exists in this casino\n";
}

TableNotInCasinoException::TableNotInCasinoException(Table * table)
{
	id = table->getTableID();
}

void TableNotInCasinoException::what()
{
	cout << "Table Id." << id << " is not registered in this casino\n";
}

bool cmpPlayerPointers(Player * p1, Player * p2)
{
	return p1->getAverageProfit() <= p2->getAverageProfit();
}