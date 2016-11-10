#pragma once

#include "Table.h"

unsigned int Table::nextID = 0;


void TooManyPlayers::what()
{
	cout << "Error while loading players to table\n";
	cout << "The table already has " << actualNumOfPlayers << "out of " << maxNumberOfPlayers << "\n";
}


Table::Table(unsigned int roundsLeft,unsigned int minBet, unsigned int maxBet, unsigned int moneyOfTable, unsigned int numberOfMaxPlayers, Dealer& newDealer) {
	this->roundsLeft = roundsLeft;
	this->minBet = minBet;
	this->maxBet = maxBet;
	this->moneyOfTable = moneyOfTable;
	this->maxNumberOfPlayers = maxNumberOfPlayers;
	this->dealerOfTable = newDealer;
	initialMoney = moneyOfTable;
	tableID = nextID;
	nextID++;
}

void Table::setMaxBet(unsigned int aMaxBet) {
	this->maxBet = aMaxBet;
}

void Table::setDealer(Dealer dealerOfTable) {
	this->dealerOfTable = dealerOfTable;
}


void Table::addPlayer(Player * newPlayer) {
	this->players.push_back(newPlayer);
	actualBets.resize(players.size());
}

void Table::addPlayers(vector<Player *> newPlayers) {
	if (newPlayers.size() + players.size() > maxNumberOfPlayers) {
		throw TooManyPlayers (maxNumberOfPlayers,players.size());
	}
	players.insert(players.end(), newPlayers.begin(), newPlayers.end());
	actualBets.resize(players.size());
}

void Table::removePlayer(Player * player1)
{

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

void Table::play() {
	//sequence : get Initial Bets then deal one card to each player and to the dealer (2x times) (first Dealer card face down)
	//if dealer's card is an Ace, ask players if they want to take insurance()
	//If they do, take each player�s insurance (it should be half of their original bet) and flip over dealer's second card to see whether or not dealer has a blackjack.
	//If dealer has a blackjack, collect bets from anyone that didn�t buy insurance.Players that did buy insurance receive their original bets back.Players with blackjack will receive their original bet, even if they didn�t purchase insurance.
	while (roundsLeft > 0)
	{	
		cout << "Rounds left." << roundsLeft << "\n";
		if (restartDeck() == 0) { cout << "Deck has been restarted\n"; void resetBot1Counters();}
		getInitialBets();
		dealOneCardToAllPlayers();
		if (restartDeck() == 0) { cout << "Deck has been restarted\n"; void resetBot1Counters();}
		dealerOfTable.hit(players);
		dealOneCardToAllPlayers();
		if (restartDeck() == 0) { cout << "Deck has been restarted\n"; void resetBot1Counters();}
		if (dealerOfTable.hit(players) == "A") {
			for(int i = 0; i < actualPlayers.size(); i++){
				if(actualPlayers.at(i)->takeInsurance(*this)){
					moneyOfTable += actualBets.at(i)/2;
				}
			}
		}
		for(int j=0; j < actualPlayers.size(); j++) {
			if (actualPlayers.at(j)->getHand().at(0) == actualPlayers.at(j)->getHand().at(1)) {
				vector<Card> *secHand;
				actualPlayers.at(j)->split(secHand);
			}
		}
		for (size_t i = 0; i < players.size(); i++) {
			do {
				if (restartDeck() == 0) { cout << "Deck has been restarted\n"; void resetBot1Counters();}
			}
				while (players.at(i)->play(dealerOfTable) != "stand");
			cout << "Name: " << players.at(i)->getName() << "; Money:" << players.at(i)->getCurrentMoney() << "; Handscore: " << players.at(i)->getHandScore() << "\n";
			cout << "In " << players.at(i)->getName() << "'s hand: ";
			cout << players.at(i)->getHand();
			cout << "\n";
		}
		do {
			if (restartDeck() == 0) { cout << "Deck has been restarted\n"; void resetBot1Counters();}
			//cout << "Dealer handscore. " << dealerOfTable.getHandScore() << "\n";
		} while (dealerOfTable.play() != "stand");
		
		cout << "Dealer stands, with " << dealerOfTable.getHandScore() << " points. In his hand:\n";
		cout << dealerOfTable.getHand();
		for (size_t i = 0; i < players.size(); i++) {
			if (players.at(i)->getHandScore() > 21) {
				//cout  << players.at(i)->getName() << " has " << players.at(i)->getHandScore() << " points, so he got busted!\n";
			}
			if (players.at(i)->getHandScore() == 21 && players.at(i)->getHandSize() == 2 && dealerOfTable.getHandScore() < 21) {
				payToPlayer(players.at(i), actualBets.at(i) * 2.5);
				//cout << players.at(i)->getName() << " has " << players.at(i)->getHandScore() << " so he did a blackjack!\n";
			}
			else if (players.at(i)->getHandScore() <= 21 && players.at(i)->getHandScore() == dealerOfTable.getHandScore() ) {
				payToPlayer(players.at(i), actualBets.at(i));
				//cout << players.at(i)->getName() << " has " << players.at(i)->getHandScore() << " points, which is equal to the Dealer!\n";
			}
			else if (players.at(i)->getHandScore() > dealerOfTable.getHandScore() && players.at(i)->getHandScore() < 21) {
				payToPlayer(players.at(i), actualBets.at(i) * 2);
				//cout << players.at(i)->getName() << " has " << players.at(i)->getHandScore() << " points, so he won the bet!\n";
			}
			else if (dealerOfTable.getHandScore() > 21 && players.at(i)->getHandScore() <= 21) {
				payToPlayer(players.at(i), actualBets.at(i) * 2);
				//cout << "Dealer got busted! Player " << players.at(i)->getName() << " will receive 2 times his original bet!\n";
			}
			else if (players.at(i)->getHandScore() != 21 && dealerOfTable.getHandScore() == 21) {
				//cout << "Dealer has blackjack! " << players.at(i)->getName() << " lost his bet!\n";
			}
			players.at(i)->clearHand();
			players.at(i)->setRoundsPlayed(players.at(i)->getRoundsPlayed() + 1);
			dealerOfTable.clearHand();
		}
		
		roundsLeft--;
	}
	for (size_t i = 0; i < players.size(); i++) {
		cout << players.at(i)->getName() << " has finished with " << players.at(i)->getCurrentMoney() << "$ in his hand!\n";
	}
}

unsigned int Table::getInitialMoney() const
{
	return initialMoney;
}

unsigned int Table::getTableID() const
{
	return tableID;
}

void Table::getInitialBets()
{
	if (actualBets.size() != players.size()) {
		actualBets.resize(players.size());
	}
	for (size_t i = 0; i < players.size(); i++) {
		actualBets.at(i) = players.at(i)->bet(*this);
		if (actualBets.at(i) == 0) { //kick the player
			cout << players.at(i)->getName() << " we enjoyed your money ! Come back when you have some more...\n";
			kickPlayer(i);
			cout << players.at(i)->getName() << " has been kicked from table " << tableID << ".\n";
			i--;
		}
		moneyOfTable += actualBets.at(i);
	}
}

Dealer * Table::getDealer() const
{
	return &dealerOfTable;
}

vector<Player*> Table::getPlayers() const
{
	return players;
}

void Table::dealOneCardToAllPlayers() {
	for (size_t i = 0; i < players.size(); i++) {
		Card discarded = dealerOfTable.discard(players);
		players.at(i)->hit(discarded);
	}
}

void Table::payToPlayer(Player * player1, float value)
{
	player1->addMoney(value);
	moneyOfTable -= value;
}

unsigned int Table::restartDeck()
{
	if (dealerOfTable.getDiscardedDeck().size() >= 3 * dealerOfTable.getDeck().size()) {
		dealerOfTable.addCardsToDeck(dealerOfTable.getDiscardedDeck()); //already shuffles the deck
		for (size_t i = 0; i < players.size(); i++) {
			players.at(i)->resetCount();
		}
		dealerOfTable.clearDiscardedDeck();
		return 0;
	}
	return 1;
}

void Table::kickPlayer(unsigned int index)
{
	players.erase(players.begin() + index);
}

void Table::resetBot1Counters()
{
	for (size_t i = 0; i < players.size(); i++) {
		players.at(i)->resetCount();
	}
}

float Table::closeTable()
{
	players.clear();
	actualBets.clear();
	cout << "Table ID." << tableID << " has been CLOSED\n";
	cout << "Profit of table " << tableID << " : " << setprecision(2) <<moneyOfTable - initialMoney << "$\n";
	return moneyOfTable;
}



TooManyPlayers::TooManyPlayers(unsigned int maxNumberOfPlayers, unsigned int actualNumOfPlayers)
{
	this->maxNumberOfPlayers = maxNumberOfPlayers;
	this->actualNumOfPlayers = actualNumOfPlayers;
}

