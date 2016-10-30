#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Card {
	string rank;
	string suits;
	unsigned int score;
};

vector <Card> creatDeck() {
	vector <string> suits = { "Heart","Diamond","Club","Spade" };
	string ranks = "A234567890JQK";
	Card newCard;
	vector <Card> deck;

	for (unsigned int i = 0; i < ranks.length(); i++)
	{
		for (size_t j = 0; j < suits.size(); j++)
		{
			if (i == 0)
			{
				newCard.suits = suits.at(j);
				newCard.rank = ranks.at(i);
				newCard.score = 1;
			}
			else if (i < 9)
			{
				newCard.suits = suits.at(j);
				newCard.rank = ranks.at(i);
				newCard.score = i + 1;
			}
			else if (i == 9)
			{
				newCard.suits = suits.at(j);
				newCard.rank = "10";
				newCard.score = i + 1;
			}
			else if (i >= 1)
			{
				newCard.suits = suits.at(j);
				newCard.rank = ranks.at(i);
				newCard.score = 10;
			}
			deck.push_back(newCard);
		}
	}
	return deck;
}

void clearScreen();

unsigned short int readUnsignedIntBetween(unsigned int min, unsigned int max);

int readIntBetween(int min, int max);

unsigned int readUnsignedInt();

int readInt();

float readFloat();

char readCharYorN();
