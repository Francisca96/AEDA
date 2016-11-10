#pragma once

#include "Player.h"


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


unsigned int Player::getCurrentMoney()
{
	return currentMoney;
}

unsigned int Player::getInitialMoney()
{
	return initialMoney;
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

<<<<<<< HEAD
int Player::getCurrentCount() const
{
	return 0;
}

void Player::addCount(Card &card)
{

}

void Player::resetCount()
{
}

bool Player::takeInsurance(Dealer &dealerOfTable){
=======
bool Player::takeInsurance(Table &table){
	return false;
}

bool Player::split(vector<Card> * secHand){
>>>>>>> origin/master
	return false;
}


//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
Bot0::Bot0(string name, unsigned int initialMoney)
{
	this->setName(name);
	this->setInitialMoney(initialMoney);
}

string Bot0::play(Table &table)
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
bool Bot1::takeInsurance(Table &table) {
    unsigned int insurance;

	//TODO: alterar algoritmo
    insurance = bet()/2;
    getCurrentMoney() -= insurance;

    return true;
}

bool Bot1::split(vector<Card> * secHand) {

}

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

int Bot1::getCurrentCount() const
{
	return currentCount;
}

void Bot1::addCount(Card &card1)
{
	int score = card1.score;
	if (card1.score <= 6) {
		currentCount++;
	}
	else if (card1.score >= 10) {
		currentCount--;
	}
}

void Bot1::resetCount()
{
	currentCount = 0;
}

//////////////////////////////////////////////////// BOT 2 ////////////////////////////////////////////////////
bool Bot2::takeInsurance(Table &table) {
	//TODO: fazer algoritmo
}

bool Bot2::split(vector<Card> * secHand) {
	//TODO: fazer algoritmo
}

//////////////////////////////////////////////////// HUMAN ////////////////////////////////////////////////////
bool Human::takeInsurance(Table &table) {
    unsigned int insurance;
    cout << "Do you want insurance?\n 0 - No    1 - Yes\n";
    cin >> insurance;

    if(insurance == 1){
        insurance = bet()/2;
        getCurrentMoney() -= insurance;
        return true;
    }

    return false;
}

bool Human::split(vector<Card> * secHand) {
	cout << "Do you want to split?\n 0 - No    1 - Yes\n";
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
