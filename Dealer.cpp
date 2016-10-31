#pragma once

#include <algorithm>
#include "Dealer.h"


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

void Dealer::receiveCard()
{
	hand.push_back(discard());
	if (hand.size() == 2) {
		visibleCards.push_back(hand.at(1));
	}
}

void Dealer::setAllCardsVisible()
{
	visibleCards.resize(hand.size());
	for (size_t i = 0; i < hand.size(); i++) {
		visibleCards.at(i) = hand.at(i);
	}
}

