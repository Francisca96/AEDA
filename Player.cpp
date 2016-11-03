#pragma once

#include "Player.h"


int bot1RunningCount = 0;
void Player::updateBot1RunningCount(Card &aCard) {
	string tempRank = aCard.rank;
	if (tempRank <= "6") {
		bot1RunningCount++;
	}
	else if (tempRank >= "A") {
		bot1RunningCount--;
	}
}
void Player::resetBot1RunningCount() {
	bot1RunningCount = 0;
}

int Player::getBot1RunningCount()
{
	return bot1RunningCount;
}

//Exceptions
void NameTooShort::what()
{
	cout << "Error - A name shoud have no less than 3 characters\n";
}

void TooYoung::what()
{
	cout << "Error - In order to play you should be at least 18 years old\n";
}

//Player

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

vector<Card>& Player::getHand()
{
	return hand;
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
	if (handScore > 21) {
		for (size_t i = 0; i < hand.size(); i++) {
			if (hand.at(i).score == 11 && handScore > 21) {
				this->handScore -= 10;
			}
		}
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
	cout << setw(15) << roundsPlayed << setw(30) << setprecision(2) <<averageProfit << " $/round\n";

}

unsigned int Player::bet(unsigned int minValue, unsigned int maxValue)
{
	if (getCurrentMoney() < minValue) {
		return 0; //0 means kick the player from the table;
	}
	unsigned int betValue = minValue;
	setCurrentMoney(getCurrentMoney() - betValue);
	cout << name << " bets " << betValue << "$\n";
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

unsigned int Bot1::bet(unsigned int minValue, unsigned int maxValue) {
	unsigned int currentMoney = getCurrentMoney();
	if (currentMoney < minValue){
		return 0; //0 means kick the player from the table;
	}
	int trueCount = getBot1RunningCount();
	cout << "Current running count =" << trueCount << ".\n";
	unsigned int betValue;
	if (trueCount <= 0) {
		betValue = minValue;
	}
	else if (trueCount == 1) {
		if (2 * minValue > maxValue) {
			betValue = maxValue;
		}
		else {
			betValue = 2 * minValue;
		}
	}
	else if (trueCount == 2) {
		if (3 * minValue > maxValue) {
			betValue = maxValue;
		}
		else { betValue = 3 * minValue; }
	}
	else if (trueCount == 3) {
		if (4 * minValue > maxValue) {
			betValue = maxValue;
		}
		else {
			betValue = 4 * minValue;
		}
	}
	else if (trueCount == 4) {
		if (5 * minValue > maxValue) {
			betValue = maxValue;
		}
		else {
			betValue = 5 * minValue;
		}
	}
	else if (trueCount >= 5) {
		if (6 * minValue > maxValue) {
			betValue = maxValue;
		}
		else {
			betValue = 6 * minValue;
		}
	}
	if (betValue > currentMoney) {
		betValue = currentMoney;
	}
	setCurrentMoney(currentMoney - betValue);
	cout << getName() << " bets " << betValue << "$\n";
	return betValue;
}

Bot1::Bot1(string name, unsigned int initialMoney)
{
	this->setName(name);
	this->setInitialMoney(initialMoney);
}

string Bot1::play(Dealer &dealerOfTable)
{
	string options[] = { "hit","stand" };
	unsigned int handScore = getHandScore();
	if (handScore < 17) {
		hit(dealerOfTable.discard());
		return options[0]; // 0 means hit
	}
	return options[1]; // means stand
}

//////////////////////////////////////////////////// BOT 2 ////////////////////////////////////////////////////
//////////////////////////////////////////////////// HUMAN ////////////////////////////////////////////////////

Human::Human(string name, unsigned int age)
{
	try {
		if (name.length() < 3) {
			throw NameTooShort();
		}
		setName(name);
		if (age < 18) {
			throw TooYoung();
		}
		this->age = age;
		setInitialMoney(1000);
	}
	catch (NameTooShort &n) {
		n.what();
	}
	catch (TooYoung &y) {
		y.what();
	}
}


unsigned int Human::bet(unsigned int minValue, unsigned int maxValue)
{
	if (getCurrentMoney() < minValue) {
		return 0; //0 means kick the player from the table;
	}
	unsigned int betValue;
	cout << "Your Turn " << getName() << "\n";
	betValue = readUnsignedIntBetween(minValue, maxValue);
	setCurrentMoney(getCurrentMoney() - betValue);
	return betValue;
}

string Human::play(Dealer &dealerOfTable)
{
	string option;
	cout << "Your Turn -> In your hand you have the following:\n";
	for (size_t i = 0; i < getHandSize(); i++) {
		cout << getHand().at(i).rank << " of " << getHand().at(i).suits << "\n";
	}
	cout << "Current hand score-> " << getHandScore() << "\n";
	cout << "Current money-> " << getCurrentMoney() << "\n";
	cout << "To hit write 'hit' to stand write 'stand' : ";
	option = getHumanPlay();
	if (option == "hit") {
		hit(dealerOfTable.discard());
	}
	return option;
}
