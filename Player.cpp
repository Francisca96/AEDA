#pragma once

#include "Player.h"


int bot1RunningCount = 0;
void Player::updateBot1RunningCount(Card &aCard) {

	unsigned int tempScore = aCard.score;
	if (tempScore <= 6) {
		bot1RunningCount++;
	}
	else if (tempScore >= 10) {
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

unsigned int Player::bet(Table currentTable)
{
	if (getCurrentMoney() < currentTable.getMinBet()) {
		return 0; //0 means kick the player from the table;
	}
	unsigned int betValue = currentTable.getMinBet();
	setCurrentMoney(getCurrentMoney() - betValue);
	cout << name << " bets " << betValue << "$\n";
	return betValue;
}

void Player::clearHand()
{
	hand.clear();
}

bool Player::takeInsurance(Dealer &dealerOfTable){
	return false;
}


//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
Bot0::Bot0(string name, unsigned int initialMoney)
{
	this->setName(name);
	this->setInitialMoney(initialMoney);
}

bool Bot0::takeInsurance(Dealer &dealerOfTable, Table &currentTable) {
    return false;
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
bool Bot1::takeInsurance(Dealer &dealerOfTable, Table &currentTable) {
    unsigned int insurance;

    insurance = bet(currentTable)/2;
    setCurrentMoney(getCurrentMoney()-insurance);

    return true;
}

unsigned int Bot1::bet(Table &currentTable) {
	unsigned int currentMoney = getCurrentMoney();
	if (currentMoney < currentTable.getMinBet()){
		return 0; //0 means kick the player from the table;
	}
	int trueCount = getBot1RunningCount();
	cout << "Current running count =" << trueCount << ".\n";
	unsigned int betValue;
	if (trueCount <= 0) {
		betValue = currentTable.getMinBet();
	}
	else if (trueCount == 1) {
		if (2 * currentTable.getMinBet() > currentTable.getMaxBet()) {
			betValue = currentTable.getMaxBet();
		}
		else {
			betValue = 2 * currentTable.getMinBet();
		}
	}
	else if (trueCount == 2) {
		if (3 * currentTable.getMinBet() > currentTable.getMaxBet()) {
			betValue = currentTable.getMaxBet();
		}
		else { betValue = 3 * currentTable.getMinBet(); }
	}
	else if (trueCount == 3) {
		if (4 * currentTable.getMinBet() > currentTable.getMaxBet()) {
			betValue = currentTable.getMaxBet();
		}
		else {
			betValue = 4 * currentTable.getMinBet();
		}
	}
	else if (trueCount == 4) {
		if (5 * currentTable.getMinBet() > currentTable.getMaxBet()) {
			betValue = currentTable.getMaxBet();
		}
		else {
			betValue = 5 * currentTable.getMinBet();
		}
	}
	else if (trueCount >= 5) {
		if (6 * currentTable.getMinBet() > currentTable.getMaxBet()) {
			betValue = currentTable.getMaxBet();
		}
		else {
			betValue = 6 * currentTable.getMinBet();
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
	string options[] = {"hit", "stand"};
	string option;
	unsigned int botHandScore = getHandScore();
	unsigned int dealerHandScore = dealerOfTable.getHandScore();
	int runningCount = getBot1RunningCount();
	if (botHandScore == 16 && dealerHandScore == 10) {
		if (runningCount < 0) {
			option = options[0];
		}else option = options[1];
	}
	else if (botHandScore == 15 && dealerHandScore == 10) {
		if (runningCount < 4) {
			option =  options[0];
		} else option = options[1];
			
	}
	else if (botHandScore == 12 && dealerHandScore == 3) {
		if (runningCount < 2) {
			option =  options[0];
		}else
		option =  options[1];
	}
	else if (botHandScore == 12 && dealerHandScore == 2) {
		if (runningCount < 3) {
			option =  options[0];
		}else
		option =  options[1];
	}
	else if (botHandScore == 13 && dealerHandScore == 2) {
		if (runningCount < -1) {
			option =  options[0];
		}else
		option =  options[1];
	}
	else if (botHandScore == 12 && dealerHandScore == 4) {
			if (runningCount < 0) {
				option =  options[0];
			}else
			option =  options[1];
		}
	else if (botHandScore == 12 && dealerHandScore == 5) {
			if (runningCount < -2) {
				option =  options[0];
			}else
			option =  options[1];
		}
	else if (botHandScore == 12 && dealerHandScore == 6) {
			if (runningCount < -1) {
				option =  options[0];
			}else
			option =  options[1];
	}
	else if (botHandScore == 13 && dealerHandScore == 3){
		if (runningCount < -2){
			option =  options[0];
		}else
		option =  options[1];
	}
	else if (botHandScore < 17) {
		option =  options[0];
	}
	else {
		option = options[1];
	}
	if (option == options[0]) {
		hit(dealerOfTable.discard());
	}
	return option; // means stand
}

//////////////////////////////////////////////////// BOT 2 ////////////////////////////////////////////////////
bool Bot2::takeInsurance(Dealer &dealerOfTable, Table &currentTable) {

}

//////////////////////////////////////////////////// HUMAN ////////////////////////////////////////////////////
bool Human::takeInsurance(Dealer &dealerOfTable, Table &currentTable) {
    unsigned int insurance;
    cout << "Do you want insurance?\n 0 - No    1 - Yes\n";
    cin >> insurance;

    if(insurance == 1){
        insurance = bet(currentTable)/2;
        setCurrentMoney(getCurrentMoney() - insurance);
        return true;
    }

    return false;
}

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


unsigned int Human::bet(Table &currentTable)
{
	if (getCurrentMoney() < currentTable.getMinBet()) {
		return 0; //0 means kick the player from the table;
	}
	unsigned int betValue;
	cout << "Your Turn " << getName() << "\n";
	betValue = readUnsignedIntBetween(currentTable.getMinBet(), currentTable.getMaxBet());
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
