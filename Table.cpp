#pragma once

#include "Table.h"


Table::Table(unsigned int minBet, unsigned int maxBet, unsigned int moneyOfTable, unsigned int numberOfMaxPlayers) {
	this->keepPlaying = true;
	this->minBet = minBet;
	this->maxBet = maxBet;
	this->moneyOfTable = moneyOfTable;
	this->maxNumberOfPlayers = maxNumberOfPlayers;
}


void Table::setMaxBet(unsigned int aMaxBet) {
	this->maxBet = aMaxBet;
}

void Table::setDealer(Dealer &dealerOfTable) {
	this->dealerOfTable = dealerOfTable;
}


void Table::addPlayer(Player * newPlayer) {
	this->players.push_back(newPlayer);
}

void Table::addPlayers(vector<Player *> newPlayers) {
	players.insert(players.end(), newPlayers.begin(), newPlayers.end());
}

void Table::setMinBet(unsigned int aMinBet) {
	this->minBet = aMinBet;
}

unsigned int Table::getMinBet() {
	return this->minBet;
}

unsigned int Table::getMaxBet() {
	return this->maxBet;
}

void Table::play() {
	//sequence : get Initial Bets then deal one card to each player and to the dealer (2x times) (first Dealer card face down)
	//if dealer's card is an Ace, ask players if they want to take insurance()
	//If they do, take each player’s insurance (it should be half of their original bet) and flip over dealer's second card to see whether or not dealer has a blackjack.
	//If dealer has a blackjack, collect bets from anyone that didn’t buy insurance.Players that did buy insurance receive their original bets back.Players with blackjack will receive their original bet, even if they didn’t purchase insurance.
	while (keepPlaying == 1)
	{
		getInitialBets();
		dealOneCardToAllPlayers();
		dealerOfTable.receiveCard();
		dealOneCardToAllPlayers();
		dealerOfTable.receiveCard();
		if (dealerOfTable.visibleCards.at(0) == "A") {
		
		}
	}
}

void Table::getInitialBets()
{
	unsigned int betValue;
	if (actualBets.size() != players.size()) {
		actualBets.resize(players.size());
	}
	
}

void Table::dealOneCardToAllPlayers() {
	for (size_t i = 0; i < players.size(); i++) {
		players.at(i)->receiveCard(dealerOfTable.discard());
	}
}


