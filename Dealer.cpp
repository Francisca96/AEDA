#pragma once

#include <algorithm>
#include "Dealer.h"


Dealer::Dealer() {
}

Dealer::Dealer(vector<Card> newDeck) {
	this->deck = newDeck;
	shuffleDeck();
}

void Dealer::shuffleDeck() {
	random_shuffle(deck.begin(), deck.end());
}

Card Dealer::discard() {
	Card nextCard;
	nextCard = deck.back();
	deckDiscarded.push_back(nextCard);
	deck.pop_back();
	return nextCard;
}

void Dealer::hit(Card newCard) {
	hand.push_back(newCard);
	setHandScore();
}

void Dealer::stand() {
	
	nextPlayer++;
}

unsigned int Dealer::setHandScore(){
	this->handScore = 0;
	for (size_t i = 0; i < hand.size(); i++)
	{
		this->handScore += hand.at(i).score;
	}
	return this->handScore;
}

