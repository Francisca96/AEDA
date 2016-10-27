#pragma once

#include "Table.h"

void Table::getMinBet() {
	return this->_minBet;
}

void Table::setMinBet(string aMinBet) {
	this->_minBet = aMinBet;
}

void Table::getMaxBet() {
	return this->_maxBet;
}

void Table::setMaxBet(string aMaxBet) {
	this->_maxBet = aMaxBet;
}

