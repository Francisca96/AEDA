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

string Player::getName()
{
	return name;
}

void Player::setName(string newName)
{
	name = newName;
}

unsigned int Player::getAverageProfit()
{
	return averageProfit;
}

void Player::setCurrentMoney(unsigned int money)
{
	currentMoney = money;
}

void Player::setCurrentCounter(int counter)
{
	currentCounting = counter;
}

unsigned int Player::getCurrentMoney()
{
	return currentMoney;
}

unsigned int Player::getInitialMoney()
{
	return initialMoney;
}

unsigned int Player::getCurrentCounter()
{
	return currentCounting;
}

unsigned int Player::getRoundsPlayed()
{
	return roundsPlayed;
}

void Player::setRoundsPlayed(unsigned int rounds)
{
	roundsPlayed = rounds;
}

void Player::setInitialMoney(unsigned int money)
{
	initialMoney = money;
	currentMoney = initialMoney;
	averageProfit = 0;
	roundsPlayed = 0;
}

void Player::addMoney(unsigned int value)
{
	currentMoney += value;
}

void Player::showStatistics()
{
	averageProfit = (float)((currentMoney - initialMoney) / float(roundsPlayed));
	
	Bot0 *bot0 = dynamic_cast<Bot0*> (this);
	Bot1 *bot1 = dynamic_cast<Bot1*> (this);
	Bot2 *bot2 = dynamic_cast<Bot2*> (this);
	cout << setw(15) << "Bot " << name;
	if (bot0 != nullptr) {
		cout << setw(15) << "0";
	}
	else if (bot1 != nullptr){
		cout << setw(15) << "1";
	}
	else if (bot2 != nullptr) {
		cout << setw(15) << "2";
	}
	cout << setw(15) << roundsPlayed << setw(30) << averageProfit << " $/round\n";

}

unsigned int Player::bet(unsigned int minValue, unsigned int maxValue)
{
	unsigned int betValue = minValue;
	setCurrentMoney(getCurrentMoney() - betValue);
	return betValue;
}

void Player::clearHand()
{
	hand.clear();
}



//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
Bot0::Bot0(string name, unsigned int initialMoney)
{
	this->setName(name);
	this->setInitialMoney(initialMoney);
}

string Bot0::play(Dealer &dealerOfTable)
{
	string options[] = { "hit","stand" };
	unsigned int handScore = getHandScore();
	if (handScore < 17) {
		hit(dealerOfTable.discard());
		return options[0]; // 0 means hit
	}
	return options[1]; // means stand
}

//////////////////////////////////////////////////// BOT 1 ////////////////////////////////////////////////////
string Bot1::play(Dealer &dealerOfTable)
{
	unsigned int handScore = getHandScore();
	vector<Card> discarded = dealerOfTable.getDiscardedDeck(); //fix this ! getDiscardedDeck is implemented in dealer
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