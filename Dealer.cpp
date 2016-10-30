#pragma once

#include "Dealer.h"

void Dealer::hit() {
	Card nextCard;
	nextCard = deck[deck.size()];
	deckDiscarded.push_back(nextCard);
	deck.erase(deck.begin + deck.size());
	hand.push_back(nextCard);
	handScore = handScore();
}

void Dealer::stand() {
	//TODO: alterar variável de jogador atual
}

unsigned int Dealer::handScore(){
	unsigned int score = 0;

	for(int i=0; i<hand.size(); i++){
		score += hand[i].score;
	}

	return score;
}

