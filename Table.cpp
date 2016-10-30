#pragma once

#include "Table.h"

Table::Table(unsigned int minBet, unsigned int maxBet, unsigned int moneyOfTable, unsigned int numberOfMaxPlayers) {
	this->minBet = minBet;
	this->maxBet = maxBet;
	this->moneyOfTable = moneyOfTable;
	this->numberMaxOfPlayers = numberMaxOfPlayers;
}


void Table::setMaxBet(unsigned int aMaxBet) {
	this->maxBet = aMaxBet;
}

void Table::setMoneyOfTable(unsigned int moneyOfTable) {
	this->moneyOfTable = moneyOfTable;
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

