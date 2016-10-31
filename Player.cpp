#pragma once

#include "Player.h"


void Player::hit(Card newCard) {
	hand.push_back(newCard);
	setHandScore();
}

void Player::takeInsurance() {
	throw "Not yet implemented";
}

void Player::surrender() {
	throw "Not yet implemented";
}

void Player::split() {
	throw "Not yet implemented";
}

void Player::doubleDown() {
	throw "Not yet implemented";
}

void Player::canUseSideRules() {
	throw "Not yet implemented";
}

unsigned int Player::setHandScore() {
	this->handScore = 0;
	for (size_t i = 0; i < hand.size(); i++)
	{
		this->handScore += hand.at(i).score;
	}
	return this->handScore;
}
