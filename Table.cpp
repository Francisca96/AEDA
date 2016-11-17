#pragma once

#include "Table.h"

unsigned int Table::nextID = 0;


void TooManyPlayers::what()
{
	cout << "Error while loading players to table\n";
	cout << "The table already has " << actualNumOfPlayers << "out of " << maxNumberOfPlayers << "\n";
}


Table::Table(int ID) {
	this->tableID = ID;
}

Table::Table(unsigned int minBet, unsigned int maxBet, unsigned int moneyOfTable, unsigned int numberOfMaxPlayers, Dealer * newDealer) {
	this->minBet = minBet;
	this->maxBet = maxBet;
	this->moneyOfTable = moneyOfTable;
	this->maxNumberOfPlayers = maxNumberOfPlayers;
	this->dealerOfTable = newDealer;
	initialMoney = moneyOfTable;
	tableID = nextID;
	nextID++;
	newDealer->setTable(tableID);
}

Table::~Table() {
	this->closeTable();
	for (size_t i = 0; i < players.size(); i++)
	{
		players.at(i)->setOnTable(-1);
	}
	dealerOfTable->setTable(-1);
}

void Table::setMaxBet(unsigned int aMaxBet) {
	this->maxBet = aMaxBet;
}

void Table::setDealer(Dealer *dealerOfTable) {
	this->dealerOfTable->setTable(-1);
	this->dealerOfTable = dealerOfTable;
	dealerOfTable->setTable(tableID);
}

void Table::setID(int ID) {
	this->tableID = ID;
}


void Table::addPlayer(Player * newPlayer) {
	this->players.push_back(newPlayer);
	newPlayer->setOnTable(this->getTableID());
}

void Table::addPlayers(vector<Player *> newPlayers) {
	if (newPlayers.size() + players.size() > maxNumberOfPlayers) {
		throw TooManyPlayers (maxNumberOfPlayers,players.size());
	}
	players.insert(players.end(), newPlayers.begin(), newPlayers.end());
	for (size_t i = 0; i < newPlayers.size(); i++)
	{
		newPlayers.at(i)->setOnTable(this->getTableID());
	}
}

void Table::removePlayer(string &name) {
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players.at(i)->getName() == name)
		{
			players.at(i)->setOnTable(-1);
			players.erase(players.begin() + i);
			return;
		}
	}
	throw PlayerIsntOnTable(name);
}

void Table::play() {
	system("cls");
	if (this->maxNumberOfPlayers == this->getPlayers().size())
	{
		throw TooManyPlayers(maxNumberOfPlayers, maxNumberOfPlayers + 1);
	}
	string nameOfPlayer = "";
	unsigned int ageOfPlayer;
	cout << "What is your name?" << endl;
	while (nameOfPlayer.length() == 0)
	{
		getline(cin, nameOfPlayer);
	}
	cout << "What is your age?" << endl;
	ageOfPlayer = readUnsignedIntBetween(0, 100);
	Human *humanPlayer = new Human(nameOfPlayer, ageOfPlayer);
	this->addPlayer(humanPlayer);
	while (!exit)
	{

	}
}

void Table::setMinBet(unsigned int aMinBet) {
	this->minBet = aMinBet;
}

unsigned int Table::getMinBet() const
{
	return minBet;
}

unsigned int Table::getMaxBet() const
{
	return maxBet;
}

unsigned int Table::getNumberMaxOfPlayers() const {
	return this->maxNumberOfPlayers;
}

void Table::simulation(unsigned int roundsLeft) {
	//sequence : get Initial Bets then deal one card to each player and to the dealer (2x times) (first Dealer card face down)
	//if dealer's card is an Ace, ask players if they want to take insurance()
	//If they do, take each player�s insurance (it should be half of their original bet) and flip over dealer's second card to see whether or not dealer has a blackjack.
	//If dealer has a blackjack, collect bets from anyone that didn�t buy insurance.Players that did buy insurance receive their original bets back.Players with blackjack will receive their original bet, even if they didn�t purchase insurance.
	//Ask players with both cards equal if they want to split.
	bool dealerBlackJack = false;
	string lastOptionSelected;
	unsigned int actualBet;
	if (players.size() == 0)
	{
		throw NoPlayersOnTable(new Table(this->getTableID()));
	}
	while (roundsLeft > 0)
	{
		dealerBlackJack = false;
		cout << "Rounds left." << roundsLeft << "\n";
		restartDeck();
		getInitialBets();
		dealOneCardToAllPlayers();
		restartDeck();
		dealerOfTable->hit(players);
		dealOneCardToAllPlayers();
		restartDeck();
		if (dealerOfTable->hit(players) == "A") {
			for(size_t i = 0; i < actualPlayers.size(); i++){
				if(actualPlayers.at(i)->takeInsurance(*this)){
					moneyOfTable += actualPlayers.at(i)->getActualBet() / 2;
					if ((dealerOfTable->getHandScore() == 21) && (actualPlayers.at(i)->getHandScore() == 21)) {
						dealerBlackJack = true;
						payToPlayer(actualPlayers.at(i), actualPlayers.at(i)->getActualBet());
					}
				}
			}
			
		}
		if (dealerBlackJack == true) {
			actualPlayers.clear();
		}
		for (size_t i = 0; i < actualPlayers.size(); i++) {
			if (actualPlayers.at(i)->surrender(*this)) {
				actualPlayers.erase(actualPlayers.begin(), actualPlayers.begin() + i);
				i--;
			}
		}

		for(size_t j=0; j < actualPlayers.size(); j++) {
			actualPlayers.at(j)->split(dealerOfTable); //carefull, when splitting you have to bet again
		}
		for (size_t i = 0; i < players.size(); i++) {
			do {
				restartDeck(); 
				if (lastOptionSelected == "double" || players.at(i)->getHandScore() == 21) {
					lastOptionSelected = "stand";
					break; //break of do while
				}
			}
				while (lastOptionSelected == players.at(i)->play(*this) && lastOptionSelected != "stand");
			cout << "Name: " << players.at(i)->getName() << "; Money:" << players.at(i)->getCurrentMoney() << "; Handscore: " << players.at(i)->getHandScore() << "\n";
			cout << "In " << players.at(i)->getName() << "'s hand: ";
			cout << players.at(i)->getHand();
			cout << "\n";
		}
		if (dealerBlackJack == false) {
			do {
				restartDeck();
				//cout << "Dealer handscore. " << dealerOfTable->getHandScore() << "\n";
			} while (dealerOfTable->play(*this) != "stand");
		}
		
		cout << "Dealer stands, with " << dealerOfTable->getHandScore() << " points. In his hand:\n";
		cout << dealerOfTable->getHand();
		for (size_t i = 0; i < players.size(); i++) {
			actualBet = players.at(i)->getActualBet();
			if (players.at(i)->getHandScore() > 21) {
				//cout  << players.at(i)->getName() << " has " << players.at(i)->getHandScore() << " points, so he got busted!\n";
			}
			if (players.at(i)->getHandScore() == 21 && players.at(i)->getHandSize() == 2 && dealerOfTable->getHandScore() < 21) {
				payToPlayer(players.at(i), actualBet * 2.5);
				//cout << players.at(i)->getName() << " has " << players.at(i)->getHandScore() << " so he did a blackjack!\n";
			}
			else if (players.at(i)->getHandScore() <= 21 && players.at(i)->getHandScore() == dealerOfTable->getHandScore() ) {
				payToPlayer(players.at(i), actualBet);
				//cout << players.at(i)->getName() << " has " << players.at(i)->getHandScore() << " points, which is equal to the Dealer!\n";
			}
			else if (players.at(i)->getHandScore() > dealerOfTable->getHandScore() && players.at(i)->getHandScore() < 21) {
				payToPlayer(players.at(i), actualBet * 2);
				//cout << players.at(i)->getName() << " has " << players.at(i)->getHandScore() << " points, so he won the bet!\n";
			}
			else if (dealerOfTable->getHandScore() > 21 && players.at(i)->getHandScore() <= 21) {
				payToPlayer(players.at(i), actualBet * 2);
				//cout << "Dealer got busted! Player " << players.at(i)->getName() << " will receive 2 times his original bet!\n";
			}
			else if (players.at(i)->getHandScore() != 21 && dealerOfTable->getHandScore() == 21) {
				//cout << "Dealer has blackjack! " << players.at(i)->getName() << " lost his bet!\n";
			}
			players.at(i)->clearHand();
			players.at(i)->clearHand2();
			players.at(i)->setRoundsPlayed(players.at(i)->getRoundsPlayed() + 1);
			dealerOfTable->clearHand();
		}
		
		roundsLeft--;
	}
	for (size_t i = 0; i < players.size(); i++) {
		cout << players.at(i)->getName() << " has finished with " << players.at(i)->getCurrentMoney() << "$ in his hand!\n";
	}
	this->closeTable();
}

unsigned int Table::getInitialMoney() const
{
	return initialMoney;
}

int Table::getTableID() const
{
	return tableID;
}

void Table::getInitialBets()
{
	unsigned int actualBet;
	for (size_t i = 0; i < players.size(); i++) {
		actualBet = players.at(i)->bet(*this);
		if (actualBet == 0) { //kick the player
			cout << players.at(i)->getName() << " we enjoyed your money ! Come back when you have some more...\n";
			kickPlayer(i);
			cout << players.at(i)->getName() << " has been kicked from table " << tableID << ".\n";
			i--;
		}
		moneyOfTable += actualBet;
	}
}

Dealer * Table::getDealer()
{
	return dealerOfTable;
}

vector<Player*> Table::getPlayers() const
{
	return players;
}

void Table::dealOneCardToAllPlayers() {
	for (size_t i = 0; i < players.size(); i++) {
		Card discarded = dealerOfTable->discard(players);
		players.at(i)->hit(discarded);
	}
}



unsigned int Table::restartDeck()
{
	if (dealerOfTable->getDiscardedDeck().size() >= 3 * dealerOfTable->getDeck().size()) {
		dealerOfTable->addCardsToDeck(dealerOfTable->getDiscardedDeck()); //already shuffles the deck
		for (size_t i = 0; i < players.size(); i++) {
			players.at(i)->resetCount();
		}
		dealerOfTable->clearDiscardedDeck();
		return 0;
	}
	return 1;
}

void Table::showTableInfo(pair<short, short> xy) {
	string text;
	cursorxy(xy.first, xy.second);
	cout << (char)201; //╔
	for (unsigned int i = 0; i <= 28; i++)
	{
		cout << (char)205; //═
	}
	cout << (char)187; //╗
	xy.second++;
	cursorxy(xy.first, xy.second);
	text = "  TableID: ";
	cout << (char)186 //║
		<< text << setw(30 - text.length()) << (char)186; //║
	cursorxy(xy.first + text.length() + 1, xy.second);
	cout << this->getTableID();
	xy.second++;
	cursorxy(xy.first, xy.second);
	cout << (char)204; //╠
	for (unsigned int i = 0; i <= 28; i++)
	{
		cout << (char)205; //═
	}
	cout << (char)185 /*╣*/;
	xy.second++;
	cursorxy(xy.first, xy.second);
	text = "  Players:";
	cout << (char)186  << text << setw(30 - text.length()) << (char)186;
	xy.second++;
	cursorxy(xy.first, xy.second);
	for (size_t i = 0; i < this->getPlayers().size(); i++)
	{
		text = this->getPlayers().at(i)->getName();
		cout << (char)186  << "   " << text << setw(30 - (3 + text.length())) << (char)186;
		xy.second++;
		cursorxy(xy.first, xy.second);
	}
	cout << (char)186 << setw(30) << (char)186;
	xy.second++;
	cursorxy(xy.first, xy.second);
	text = "  Money of Table: ";
	cout << (char)186 << text << setw(30 - text.length()) << (char)186;
	cursorxy(xy.first+ text.length()+1, xy.second);
	cout << this->getInitialMoney();
	xy.second++;
	cursorxy(xy.first, xy.second);
	cout << (char)200;
	for (unsigned int i = 0; i <= 28; i++)
	{
		cout << (char)205;
	}
	cout << (char)188;
}

void Table::kickPlayer(unsigned int index)
{
	players.at(index)->setOnTable(-1);
	players.erase(players.begin() + index);
}

void Table::resetBot1Counters()
{
	for (size_t i = 0; i < players.size(); i++) {
		players.at(i)->resetCount();
	}
}

void Table::payToPlayer(Player * player1, float value)
{
	player1->addMoney(value);
	moneyOfTable -= value;
}



float Table::closeTable()
{
	for (size_t i = 0; i < players.size(); i++) {
		players.at(i)->resetCount();
	}
	cout << "Table ID." << tableID << " has been CLOSED\n";
	cout << "Profit of table " << tableID << " : " << setprecision(2) <<moneyOfTable - initialMoney << "$\n";
	return moneyOfTable;
}

void Table::setNextID(unsigned int tableNextID) {
	nextID = tableNextID;
}

unsigned int Table::getNextId() {
	return nextID;
}

TooManyPlayers::TooManyPlayers(unsigned int maxNumberOfPlayers, unsigned int actualNumOfPlayers)
{
	this->maxNumberOfPlayers = maxNumberOfPlayers;
	this->actualNumOfPlayers = actualNumOfPlayers;
}

NoPlayersOnTable::NoPlayersOnTable(Table *table) {
	this->tableID = table->getTableID();
}

unsigned int NoPlayersOnTable::getID() const {
	return this->tableID;
}
