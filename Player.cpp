#pragma once

#include "Player.h"



//Exceptions
void NameTooShortException::what()
{
	cout << "Error - A name shoud have no less than 3 characters\n";
}

void TooYoungException::what()
{
	cout << "Error - In order to play you should be at least 18 years old\n";
}

//Player

void Player::hit(Card newCard) {
	hand.push_back(newCard);
	setHandScore();
}

void Player::hit2(Card newCard) {
	hand2.push_back(newCard);
	setHand2Score();
}

bool surrender(Table &table) {
	return false;
}


void Player::doubleDown() {
	throw "Not yet implemented";
}

vector<Card>& Player::getHand()
{
	return hand;
}

vector<Card>& Player::getHand2()
{
	return hand2;
}

unsigned int Player::getHandSize() const
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

unsigned int Player::setHand2Score()
{
	this->hand2Score = 0;
	for (size_t i = 0; i < hand2.size(); i++)
	{
		this->hand2Score += hand2.at(i).score;
	}
	if (hand2Score > 21) {
		for (size_t i = 0; i < hand2.size(); i++) {
			if (hand2.at(i).score == 11 && hand2Score > 21) {
				this->hand2Score -= 10;
			}
		}
	}
	return this->hand2Score;
}

unsigned int Player::getHandScore() const
{
	return handScore;
}

unsigned int Player::getHand2Score() const
{
	return hand2Score;
}

string Player::getName() const
{
	return name;
}

void Player::setName(string newName)
{
	name = newName;
}

float Player::getAverageProfit() const
{
	return averageProfit;
}

void Player::setCurrentMoney(float money)
{
	currentMoney = money;
}


float Player::getCurrentMoney() const
{
	return currentMoney;
}

unsigned int Player::getInitialMoney() const
{
	return initialMoney;
}



unsigned int Player::getRoundsPlayed() const
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

void Player::addMoney(float value)
{
	currentMoney += value;
}

void Player::showStatistics()
{
	if (roundsPlayed == 0)
	{
		averageProfit = 0;
	}
	else
	{
		averageProfit = (float)((currentMoney - initialMoney) / float(roundsPlayed));
	}
	
	Bot0 *bot0 = dynamic_cast<Bot0*> (this);
	Bot1 *bot1 = dynamic_cast<Bot1*> (this);
	Bot2 *bot2 = dynamic_cast<Bot2*> (this);
	cout << setw(15) << "Bot " << name;
	if (bot0 != nullptr) {
		cout << setw(25-name.length()) << "0";
	}
	else if (bot1 != nullptr){
		cout << setw(25 - name.length()) << "1";
	}
	else if (bot2 != nullptr) {
		cout << setw(25 - name.length()) << "2";
	}
	cout << setw(15) << roundsPlayed << setw(10) << setprecision(2) <<averageProfit << " $/round\n";

}

unsigned int Player::bet(Table &table)
{
	if (getCurrentMoney() < table.getMinBet()) {
		return 0; //0 means kick the player from the table;
	}
	unsigned int betValue = table.getMinBet();
	setCurrentMoney(getCurrentMoney() - betValue);
	cout << name << " bets " << betValue << "$\n";
	setActualBet(betValue);
	return betValue;
}

void Player::clearHand()
{
	hand.clear();
	this->setHandScore();
}

void Player::clearHand2()
{
	hand2.clear();
	this->setHand2Score();
}

void Player::setActualBet(unsigned int bet)
{
	actualBet = bet;
}

unsigned int Player::getActualBet()
{
	return actualBet;
}

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


unsigned int Player::getAge() const {
	return this->age;
}

void Player::setAge(unsigned int age) {
	this->age = age;
}

void Player::setOnTable(int tableID) {
	this->onTable = tableID;
}

int Player::getOnTable() const {
	return this->onTable;
}

void Player::removeCardFromFirstHandAndSetItOnSecondHand()
{
	Card secondCard = hand.at(1);
	hand.pop_back();
	hand2.push_back(secondCard);
}

ostream & Player::saveInfo(ostream & out) {
	out << name << "; " << initialMoney << "; " << setprecision(2) << fixed << currentMoney << "; ";
	if (hand.size() != 0)
	{
		out << "{";
	}
	for (size_t i = 0; i < hand.size(); i++)
	{
		out << hand.at(i).rank << "/" << hand.at(i).suits << "/" << hand.at(i).score << "; ";
	}
	if (hand.size() != 0)
	{
		out << "}; ";
	}
	if (hand2.size() != 0)
	{
		out << "{";
	}
	for (size_t i = 0; i < hand2.size(); i++)
	{
		out << hand2.at(i).rank << "/" << hand2.at(i).suits << "/" << hand2.at(i).score << "; ";
	}
	if (hand2.size() != 0)
	{
		out << "}; ";
	}
	out << roundsPlayed << "; " << age << "; " << onTable << "; " << actualBet << "; ";
	return out;
}

bool Player::takeInsurance(Table &table){
	return false;
}

bool Player::surrender(Table & table)
{
	return false;
}

bool Player::split(Dealer *dealerOfTable){
	return false;
}


Bot0::Bot0(string & line) {
	line.erase(0, line.find_first_of(";") + 2);
	this->setName(line.substr(0, line.find_first_of(";")));
	line.erase(0, line.find_first_of(";") + 2);
	this->setInitialMoney(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setCurrentMoney(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->clearHand();
	if (line.at(0) == '{')
	{
		line.erase(0, 1);
		Card newCard;
		while (line.at(0) != '}')
		{
			newCard.rank = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.suits = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.score = stoi(line.substr(0, line.find_first_of(";")));
			line.erase(0, line.find_first_of(";") + 2);
			this->hit(newCard);
		}
		line.erase(0, line.find_first_of(";") + 2);
	}
	this->clearHand2();
	if (line.at(0) == '{')
	{
		line.erase(0, 1);
		Card newCard;
		while (line.at(0) != '}')
		{
			newCard.rank = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.suits = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.score = stoi(line.substr(0, line.find_first_of(";")));
			line.erase(0, line.find_first_of(";") + 2);
			this->hit2(newCard);
		}
		line.erase(0, line.find_first_of(";") + 2);
	}
	this->setRoundsPlayed(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setAge(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setOnTable(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setActualBet(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
}

//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
Bot0::Bot0(string name, unsigned int initialMoney)
{
	this->setOnTable(-1);
	this->setName(name);
	this->setInitialMoney(initialMoney);
}

bool Bot0::takeInsurance(Table &table) {
    return false;
}

ostream & Bot0::saveInfo(ostream & out) {
	out << "0; ";
	Player::saveInfo(out);
	return out;
}

string Bot0::play(Table &table)
{
	string options[] = { "hit","stand" };
	unsigned int handScore = getHandScore();
	if (handScore < 17) {
		hit(table.getDealer()->discard(table.getPlayers()));
		return options[0]; // 0 means hit
	}
	return options[1]; // means stand
}

//////////////////////////////////////////////////// BOT 1 ////////////////////////////////////////////////////
bool Bot1::takeInsurance(Table &table) {
	unsigned int insurance = getActualBet() / 2;
	if (currentCount >= 3) {
		setCurrentMoney(getCurrentMoney() - insurance);
		return true;
	}
	return false;;
}

bool Bot1::split(Dealer *dealerOfTable) {
	vector<Card> hand1 = getHand();
	Card dealerFirstCard = dealerOfTable->getHand().at(0);
	if (hand1.at(0) == hand1.at(1)) {
		if (hand1.at(0).score == 10) {
			if (currentCount >= 5 && dealerFirstCard.score == 5) {
				removeCardFromFirstHandAndSetItOnSecondHand();
				setHand2Score();
				setHandScore();
				return true;
			}
			else if (currentCount >= 4 && dealerFirstCard.score == 6) {
				removeCardFromFirstHandAndSetItOnSecondHand();
				setHand2Score();
				setHandScore();
				return true;
			}
		}

	}
	return false;
}

bool Bot1::surrender(Table & table)
{	//based on fab4 surrender guides
	unsigned int dealerHandScore = table.getDealer()->getHandScore();
	unsigned int personalScore = getHandScore();
	if (personalScore == 14 && dealerHandScore == 10 && currentCount >= 3) {
		return true;
	}
	else if (personalScore == 15 && dealerHandScore == 10 && currentCount >= 0) {
		return true;
	}
	else if (personalScore == 15 && dealerHandScore == 9 && currentCount >= 2) {
		return true;
	}
	else if (personalScore == 15 && dealerHandScore == 11 && currentCount >= 1) {
		return true;
	}
	return false;
}

ostream & Bot1::saveInfo(ostream & out) {
	out << "1; ";
	Player::saveInfo(out);
	out << currentCount << "; ";
	return out;
}

unsigned int Bot1::bet(Table &table) {
	float currentMoney = getCurrentMoney();
	if (currentMoney < table.getMinBet()){
		return 0; //0 means kick the player from the table;
	}
	int trueCount = currentCount;
	cout << "Current running count =" << trueCount << ".\n";
	unsigned int betValue;
	if (trueCount <= 0) {
		betValue = table.getMinBet();
	}
	else if (trueCount == 1) {
		if (2 * table.getMinBet() > table.getMaxBet()) {
			betValue = table.getMaxBet();
		}
		else {
			betValue = 2 * table.getMinBet();
		}
	}
	else if (trueCount == 2) {
		if (3 * table.getMinBet() > table.getMaxBet()) {
			betValue = table.getMaxBet();
		}
		else { betValue = 3 * table.getMinBet(); }
	}
	else if (trueCount == 3) {
		if (4 * table.getMinBet() > table.getMaxBet()) {
			betValue = table.getMaxBet();
		}
		else {
			betValue = 4 * table.getMinBet();
		}
	}
	else if (trueCount == 4) {
		if (5 * table.getMinBet() > table.getMaxBet()) {
			betValue = table.getMaxBet();
		}
		else {
			betValue = 5 * table.getMinBet();
		}
	}
	else if (trueCount >= 5) {
		if (6 * table.getMinBet() > table.getMaxBet()) {
			betValue = table.getMaxBet();
		}
		else {
			betValue = 6 * table.getMinBet();
		}
	}
	if (betValue > currentMoney) {
		betValue = currentMoney;
	}
	setCurrentMoney(currentMoney - betValue);
	cout << getName() << " bets " << betValue << "$\n";
	setActualBet(betValue);
	return betValue;
}

Bot1::Bot1(string name, unsigned int initialMoney)
{
	this->setOnTable(-1);
	this->setName(name);
	this->setInitialMoney(initialMoney);
}

Bot1::Bot1(string & line) {
	line.erase(0, line.find_first_of(";") + 2);
	this->setName(line.substr(0, line.find_first_of(";")));
	line.erase(0, line.find_first_of(";") + 2);
	this->setInitialMoney(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setCurrentMoney(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->clearHand();
	if (line.at(0) == '{')
	{
		line.erase(0, 1);
		Card newCard;
		while (line.at(0) != '}')
		{
			newCard.rank = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.suits = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.score = stoi(line.substr(0, line.find_first_of(";")));
			line.erase(0, line.find_first_of(";") + 2);
			this->hit(newCard);
		}
		line.erase(0, line.find_first_of(";") + 2);
	}
	this->clearHand2();
	if (line.at(0) == '{')
	{
		line.erase(0, 1);
		Card newCard;
		while (line.at(0) != '}')
		{
			newCard.rank = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.suits = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.score = stoi(line.substr(0, line.find_first_of(";")));
			line.erase(0, line.find_first_of(";") + 2);
			this->hit2(newCard);
		}
		line.erase(0, line.find_first_of(";") + 2);
	}
	this->setRoundsPlayed(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setAge(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setOnTable(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setActualBet(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->currentCount = stoi(line.substr(0, line.find_first_of(";")));
	line.erase(0, line.find_first_of(";") + 2);
}

string Bot1::play(Table &table)
{
	string options[] = {"hit", "stand","double"};
	string option;
	Dealer * dealerOfTable = table.getDealer();
	unsigned int botHandScore = getHandScore();
	Card dealerCard1 = dealerOfTable->getHand().at(0);

	int runningCount = currentCount;
	if (botHandScore == 16 && dealerCard1.score == 10) {
		if (runningCount < 0) {
			option = options[0];
		}else option = options[1];
	}
	else if (botHandScore == 15 && dealerCard1.score == 10) {
		if (runningCount < 4) {
			option =  options[0];
		} else option = options[1];
			
	}
	else if (botHandScore == 10 && dealerCard1.score == 10) {
		if (runningCount < 4) {
			option = options[0];
		}
		else option = options[2];

	}
	else if (botHandScore == 12 && dealerCard1.score == 3) {
		if (runningCount < 2) {
			option =  options[0];
		}else
		option =  options[1];
	}
	else if (botHandScore == 12 && dealerCard1.score == 2) {
		if (runningCount < 3) {
			option =  options[0];
		}else
		option =  options[1];
	}
	else if (botHandScore == 11 && dealerCard1.score == 11) {
		if (runningCount < 1) {
			option = options[0];
		}
		else
			option = options[2];
	}
	else if (botHandScore == 9 && dealerCard1.score==2) {
		if (runningCount < 1) {
			option = options[0];
		}
		else
			option = options[2];
	}
	else if (botHandScore == 10 && dealerCard1.score == 11){
		if (runningCount < 4) {
			option = options[0];
		}
		else
			option = options[2];
	}
	else if (botHandScore == 9 && dealerCard1.score == 7) {
		if (runningCount < 3) {
			option = options[0];
		}
		else
			option = options[2];
	}
	else if (botHandScore == 13 && dealerCard1.score == 2) {
		if (runningCount < -1) {
			option =  options[0];
		}else
		option =  options[1];
	}
	else if (botHandScore == 12 && dealerCard1.score == 4) {
			if (runningCount < 0) {
				option =  options[0];
			}else
			option =  options[1];
		}
	else if (botHandScore == 12 && dealerCard1.score == 5) {
			if (runningCount < -2) {
				option =  options[0];
			}else
			option =  options[1];
		}
	else if (botHandScore == 12 && dealerCard1.score == 6) {
			if (runningCount < -1) {
				option =  options[0];
			}else
			option =  options[1];
	}
	else if (botHandScore == 13 && dealerCard1.score == 3){
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
		hit(dealerOfTable->discard(table.getPlayers()));
	}
	if (option == options[2]) {
		hit(dealerOfTable->discard(table.getPlayers()));
		setCurrentMoney(getCurrentMoney() - getActualBet());
		table.addMoneyToTable(getActualBet());
		setActualBet(2 * getActualBet());
		
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

Bot2::Bot2(string name, unsigned int initialMoney)
{
	this->setOnTable(-1);
	setName(name);
	setInitialMoney(initialMoney);
	currentCount = 0;
}

Bot2::Bot2(string & line) {
	line.erase(0, line.find_first_of(";") + 2);
	this->setName(line.substr(0, line.find_first_of(";")));
	line.erase(0, line.find_first_of(";") + 2);
	this->setInitialMoney(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setCurrentMoney(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->clearHand();
	if (line.at(0) == '{')
	{
		line.erase(0, 1);
		Card newCard;
		while (line.at(0) != '}')
		{
			newCard.rank = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.suits = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.score = stoi(line.substr(0, line.find_first_of(";")));
			line.erase(0, line.find_first_of(";") + 2);
			this->hit(newCard);
		}
		line.erase(0, line.find_first_of(";") + 2);
	}
	this->clearHand2();
	if (line.at(0) == '{')
	{
		line.erase(0, 1);
		Card newCard;
		while (line.at(0) != '}')
		{
			newCard.rank = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.suits = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.score = stoi(line.substr(0, line.find_first_of(";")));
			line.erase(0, line.find_first_of(";") + 2);
			this->hit2(newCard);
		}
		line.erase(0, line.find_first_of(";") + 2);
	}
	this->setRoundsPlayed(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setAge(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setOnTable(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setActualBet(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->currentCount = stoi(line.substr(0, line.find_first_of(";")));
	line.erase(0, line.find_first_of(";") + 2);
	this->lastBetValue = stoi(line.substr(0, line.find_first_of(";")));
	line.erase(0, line.find_first_of(";") + 2);
}

unsigned int Bot2::bet(Table & table)
{
	unsigned int betValue;
	if (getCurrentMoney() < table.getMinBet()) {
		return 0; //0 means kick the player from the table;
	}
	if (currentCount < 2) {
		betValue = table.getMinBet();
	}
	else
	{
		betValue = 2 * lastBetValue;
		if (betValue > table.getMaxBet()) {
			betValue = table.getMaxBet();
		}
	}
	if (betValue > getCurrentMoney()) {
		betValue = getCurrentMoney();
	}
	lastBetValue = betValue;
	setCurrentMoney(getCurrentMoney() - betValue);
	setActualBet(betValue);
	return betValue;
}

string Bot2::play(Table & table)
{
	string options[] = { "hit","stand" };
	unsigned int handScore = getHandScore();
	if (handScore < 17) {
		hit(table.getDealer()->discard(table.getPlayers()));
		return options[0]; // 0 means hit
	}
	return options[1]; // means stand
}

bool Bot2::takeInsurance(Table &table) {
	return false;
}

bool Bot2::split(Dealer *dealerOfTable) {
	return false;
}

bool Bot2::surrender(Table & table)
{
	//based on fab4 surrender guides
	unsigned int dealerHandScore = table.getDealer()->getHandScore();
	unsigned int personalScore = getHandScore();
	if (personalScore == 14 && dealerHandScore == 10 && currentCount >= 3) {
		return true;
	}
	else if (personalScore == 15 && dealerHandScore == 10 && currentCount >= 0) {
		return true;
	}
	else if (personalScore == 15 && dealerHandScore == 9 && currentCount >= 2) {
		return true;
	}
	else if (personalScore == 15 && dealerHandScore == 11 && currentCount >= 1) {
		return true;
	}
	return false;
	
}

int Bot2::getCurrentCount() const
{
	return currentCount;
}

void Bot2::addCount(Card & card1)
{
	if (card1.score == 5) {
		currentCount++;
	}
	else if (card1.score == 11) {
		currentCount--;
	}
}

void Bot2::resetCount()
{
	currentCount = 0;
}

void Bot2::setLastBetValue(unsigned int lastBet)
{
	lastBetValue = lastBet;
}

ostream & Bot2::saveInfo(ostream & out) {
	out << "2; ";
	Player::saveInfo(out);
	out << currentCount << "; " << lastBetValue << "; ";
	return out;
}

//////////////////////////////////////////////////// HUMAN ////////////////////////////////////////////////////
bool Human::takeInsurance(Table &table) {
    unsigned int insurance;
    cout << "Do you want insurance?\n 0 - No    1 - Yes\n";
    insurance=readBinary();

    if(insurance == 1){
        insurance = bet(table)/2;
        setCurrentMoney(getCurrentMoney() - insurance);
        return true;
    }

    return false;
}

bool Human::split(Dealer *dealerOfTable) {
	unsigned int split;
	vector<Card> hand = getHand();
	if (hand.at(0) == hand.at(1)) {
		cout << "Do you want split?\n 0 - No    1 - Yes\n";
		split = readBinary();
		vector<Card> hand = getHand();

		if (split == 1) {
			removeCardFromFirstHandAndSetItOnSecondHand();
			return true;
		}
	}
	return false;
	
}

void Human::setUserID(unsigned int userID) {
	this->userID = userID;
}

unsigned int Human::getUserID() const {
	return this->userID;
}

ostream & Human::saveInfo(ostream & out) {
	out << "3; ";
	Player::saveInfo(out);
	out << userID << "; ";
	return out;
}

Human::Human(string name, unsigned int age, int userID)
{
	try {
		if (name.length() < 3) {
			throw NameTooShortException();
		}
		setName(name);
		if (age < 18) {
			throw TooYoungException();
		}
		this->setAge(age);
		setInitialMoney(1000);
		this->setOnTable(-1);
		this->userID = userID;
	}
	catch (NameTooShortException &n) {
		n.what();
	}
	catch (TooYoungException &y) {
		y.what();
	}
}

Human::Human(string & line) {
	line.erase(0, line.find_first_of(";") + 2);
	this->setName(line.substr(0, line.find_first_of(";")));
	line.erase(0, line.find_first_of(";") + 2);
	this->setInitialMoney(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setCurrentMoney(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->clearHand();
	if (line.at(0) == '{')
	{
		line.erase(0, 1);
		Card newCard;
		while (line.at(0) != '}')
		{
			newCard.rank = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.suits = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.score = stoi(line.substr(0, line.find_first_of(";")));
			line.erase(0, line.find_first_of(";") + 2);
			this->hit(newCard);
		}
		line.erase(0, line.find_first_of(";") + 2);
	}
	this->clearHand2();
	if (line.at(0) == '{')
	{
		line.erase(0, 1);
		Card newCard;
		while (line.at(0) != '}')
		{
			newCard.rank = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.suits = line.substr(0, line.find_first_of("/"));
			line.erase(0, line.find_first_of("/") + 1);
			newCard.score = stoi(line.substr(0, line.find_first_of(";")));
			line.erase(0, line.find_first_of(";") + 2);
			this->hit2(newCard);
		}
		line.erase(0, line.find_first_of(";") + 2);
	}
	this->setRoundsPlayed(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setAge(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setOnTable(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->setActualBet(stoi(line.substr(0, line.find_first_of(";"))));
	line.erase(0, line.find_first_of(";") + 2);
	this->userID = stoi(line.substr(0, line.find_first_of(";")));
	line.erase(0, line.find_first_of(";") + 2);
}


unsigned int Human::bet(Table &table)
{
	float maxbet = getCurrentMoney();
	if (maxbet < table.getMinBet()) {
		return 0; //0 means kick the player from the table;
	}
	unsigned int betValue;
	cout << "Your Turn " << getName() << "\n";
	if (maxbet > table.getMaxBet())
	{
		maxbet = table.getMaxBet();
	}
	betValue = readUnsignedIntBetween(table.getMinBet(), maxbet);
	this->setActualBet(betValue);
	this->setCurrentMoney(this->getCurrentMoney() - betValue);
	return betValue;
}

string Human::play(Table &table)
{
	if (getHandScore() >= 21)
	{
		return "stand";
	}
	string option;
	cout << "Your Turn -> In your hand you have the following:\n";
	for (size_t i = 0; i < getHandSize(); i++)
	{
		cout << getHand().at(i).rank << " of " << getHand().at(i).suits << "\n";
	}
	cout << "Current hand score-> " << getHandScore() << "\n";
	cout << "Current money-> " << getCurrentMoney() << "\n";
	cout << "To hit write 'hit' to stand write 'stand' : ";
	option = getHumanPlay();
	if (option == "hit")
	{
		hit(table.getDealer()->discard(table.getPlayers()));
	}
	return option;
}

PlayerAlreadyExistException::PlayerAlreadyExistException(Player * player) {
	this->name = player->getName();
}

PlayerNotExistException::PlayerNotExistException(string name) {
	this->name = name;
}

PlayerStillOnTableException::PlayerStillOnTableException(Player * player) {
	this->name = player->getName();
	this->tableID = player->getOnTable();
}

unsigned int PlayerStillOnTableException::getTableId() const {
	return this->tableID;
}

PlayerIsntOnTableException::PlayerIsntOnTableException(string & name) {
	this->name = name;
}

HumanOnTableException::HumanOnTableException(Player * player) {
	this->name = player->getName();
}
