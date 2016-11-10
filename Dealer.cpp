#pragma once

#include <algorithm>
#include "Dealer.h"

unsigned int Dealer::nextID = 0;

Dealer::Dealer()
{
	deck = createDeck();
	shuffleDeck();
	ID = nextID;
	nextID++;
}

Dealer::Dealer(vector<Card> newDeck) {
	this->deck = newDeck;
	shuffleDeck();
	ID = nextID;
	nextID++;
}

void Dealer::shuffleDeck() {
	random_shuffle(deck.begin(), deck.end());
}

Card Dealer::discard(vector<Player *> players) {
	Card nextCard;
	nextCard = deck.back();
	deckDiscarded.push_back(nextCard);
	deck.pop_back();
	for (size_t i = 0; i < players.size(); i++) {
		players.at(i)->addCount(nextCard);
	}
	return nextCard;
}

Card& Dealer::hit(vector<Player *> players) {
	hand.push_back(discard(players));
	setHandScore();
	return hand.back();
}
/*
void Dealer::stand() {
	nextPlayer++;
}*/

unsigned int Dealer::setHandScore(){
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


vector<Card>& Dealer::getDeck() const
{
	return deck;
}

vector<Card>& Dealer::getHand() const
{
	return hand;
}

void Dealer::addCardsToDeck(vector<Card>& cards)
{
	deck.insert(deck.end(), cards.begin(), cards.end());
	shuffleDeck();
}

vector<Card>& Dealer::getDiscardedDeck() const
{
	return deckDiscarded;
}

unsigned int Dealer::getHandScore() const
{
	return handScore;
}

void Dealer::clearDiscardedDeck()
{
	deckDiscarded.clear();
}

void Dealer::clearHand()
{
	hand.clear();
}

bool Dealer::hasCardInHand(Card & c)
{
	for (size_t i = 0; i < hand.size(); i++) {
		if (hand.at(i) == c) {
			return true;
		}
	}
	return false;
}


string Dealer::play()
{
	if (handScore < 17) {
		hit();
		return "hit"; //means hit
	}
	else return "stand"; //means stand
}


