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

Card& Dealer::hit() {
	hand.push_back(discard());
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
	return this->handScore;
}

void Dealer::setAllCardsVisible()
{
	visibleCards.resize(hand.size());
	for (size_t i = 0; i < hand.size(); i++) {
		visibleCards.at(i) = hand.at(i);
	}
}

vector<Card>& Dealer::getDeck()
{
	return deck;
}

void Dealer::addCardsToDeck(vector<Card>& cards)
{
	deck.insert(deck.end(), cards.begin(), cards.end());
	shuffleDeck();
}

vector<Card>& Dealer::getDiscardedDeck()
{
	return deckDiscarded;
}

unsigned int Dealer::getHandScore()
{
	return handScore;
}


string Dealer::play()
{
	if (handScore < 17) {
		hit();
		return "hit"; //means hit
	}
	else return "stand"; //means stand
}


