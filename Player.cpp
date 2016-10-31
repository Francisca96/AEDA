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

unsigned int Player::getHandSize()
{
	return hand.size();
}

unsigned int Player::setHandScore() {
	this->handScore = 0;
	for (size_t i = 0; i < hand.size(); i++)
	{
		this->handScore += hand.at(i).score;
	}
	return this->handScore;
}

unsigned int Player::getHandScore() {
	return handScore;
}

void Player::setCurrentMoney(unsigned int money)
{
	currentMoney = money;
}

unsigned int Player::getCurrentMoney()
{
	return currentMoney;
}

void Player::addMoney(unsigned int value)
{
	currentMoney += value;
}

unsigned int Player::bet(unsigned int minValue, unsigned int maxValue)
{
	unsigned int betValue = minValue;
	setCurrentMoney(getCurrentMoney() - betValue);
	return betValue;
}

//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
string Bot0::play()
{
	unsigned int handScore = getHandScore();
	if (handScore < 17) {

		return "hit"; // 0 means hit
	}
	return "stand"; // means stand
}

//////////////////////////////////////////////////// BOT 1 ////////////////////////////////////////////////////
string Bot1::play()
{
	unsigned int handScore = getHandScore();
	vector<Card> discarded = getDiscardedDeck(); //fix this ! getDiscardedDeck is implemented in dealer
	int hitCards = 0;
	for(int i=0; i<discarded.size(); i++){
		if(discarded.at(i).score <= 5){
			hitCards++;
		}
	}
	return "hit"; // 0 means hit
}

//////////////////////////////////////////////////// BOT 2 ////////////////////////////////////////////////////
//////////////////////////////////////////////////// HUMAN ////////////////////////////////////////////////////