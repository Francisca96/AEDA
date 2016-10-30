#pragma once

#include "Table.h"

unsigned int Table::getMinBet() {
	return this->minBet;
}

unsigned int Table::getMaxBet() {
	return this->maxBet;
}

void Table::setMinBet(unsigned int aMinBet) {
	this->minBet = aMinBet;
}

void Table::setMaxBet(unsigned int aMaxBet) {
	this->maxBet = aMaxBet;
}

