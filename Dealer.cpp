#pragma once

#include <algorithm>
#include "Dealer.h"


Dealer::Dealer() {
	deck = creatDeck();
	shuffleDeck();
}

void Dealer::shuffleDeck() {
	random_shuffle(deck.begin(), deck.end());
}

void Dealer::hit() {	
	deckDiscarded.push_back(deck.back());
	hand.push_back(deck.back());
	deck.pop_back();
	this->handScore = handScore();
}

void Dealer::stand() {
	
	nextPlayer++;
}

unsigned int Dealer::handScore(){
	unsigned int score = 0;

	for(int i=0; i<hand.size(); i++){
		score += hand[i].score;
	}

	return score;
}

