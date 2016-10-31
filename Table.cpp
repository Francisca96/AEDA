#pragma once

#include "Table.h"

unsigned int Table::nextID = 0;

Table::Table(unsigned int roundsLeft,unsigned int minBet, unsigned int maxBet, unsigned int moneyOfTable, unsigned int numberOfMaxPlayers, Dealer& newDealer) {
	this->roundsLeft = roundsLeft;
	this->minBet = minBet;
	this->maxBet = maxBet;
	this->moneyOfTable = moneyOfTable;
	this->maxNumberOfPlayers = maxNumberOfPlayers;
	this->dealerOfTable = newDealer;
	tableID = nextID;
	nextID++;
}

void Table::setMaxBet(unsigned int aMaxBet) {
	this->maxBet = aMaxBet;
}

void Table::setDealer(Dealer &dealerOfTable) {
	this->dealerOfTable = dealerOfTable;
}


void Table::addPlayer(Player * newPlayer) {
	this->players.push_back(newPlayer);
	playersStatus.resize(players.size());
}

void Table::addPlayers(vector<Player *> newPlayers) {
	players.insert(players.end(), newPlayers.begin(), newPlayers.end());
	playersStatus.resize(players.size());
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
	while (roundsLeft > 0)
	{
		unsigned int dealerStatus = 0;
		unsigned int playerHandScore;
		bool runPlayersAgain = true;
		getInitialBets();
		dealOneCardToAllPlayers();
		dealerOfTable.hit(dealerOfTable.discard());
		dealOneCardToAllPlayers();
		dealerOfTable.hit(dealerOfTable.discard());
		if (dealerOfTable.visibleCards.at(0) == "A") {
			//askPlayersForInsurance
		}
		dealerOfTable.setAllCardsVisible();
		while(runPlayersAgain == true)
		for (size_t i = 0; i < players.size(); i++) {
			if (playersStatus.at(i) != 0) {
				continue;
			}
			unsigned int playersChoice = players.at(i)->play();
			if (playersChoice == 0)//hit
			{
				players.at(i)->hit(dealerOfTable.discard());
			}
			else if (playersChoice == 1) //stand
			{
				playersStatus.at(i) == players.at(i)->getHandScore(); //only sets status when stand, or blackjack, or busted (>21)
				continue;
			}
			playerHandScore = players.at(i)->getHandScore();
			if (playerHandScore >= 21) {
				playersStatus.at(i) == playerHandScore;
			}
			runPlayersAgain = false;
		}
		if (dealerOfTable.play() == 1) //stand
		{
			dealerStatus = 1;
		}
		
		for (size_t i = 0; i < playersStatus.size(); i++) {
			if (playersStatus.at(i) == 0) {
				runPlayersAgain = true;
			}
		}

		//continue developing here ...
	}
}

void Table::getInitialBets()
{
	if (actualBets.size() != players.size()) {
		actualBets.resize(players.size());
	}
	for (size_t i = 0; i < players.size(); i++) {
		actualBets.at(i) = players.at(i)->bet();
		moneyOfTable += actualBets.at(i);
	}
}

void Table::dealOneCardToAllPlayers() {
	//check if deck has cards for all the players + dealer
	if (dealerOfTable.getDeck().size() < players.size() + 1) {
		dealerOfTable.addCardsToDeck(dealerOfTable.getDiscardedDeck());
		//inform players to reset counters because the deck has been reshuffled
	}
	for (size_t i = 0; i < players.size(); i++) {
		players.at(i)->hit(dealerOfTable.discard());
	}
}


