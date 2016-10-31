#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Card {
	string rank;
	string suits;
	unsigned int score;

	bool operator==(const string &a) const
	{
		return (this->rank == a);
	}
};

vector <Card>& createDeck();


void clearScreen();

unsigned short int readUnsignedIntBetween(unsigned int min, unsigned int max);

int readIntBetween(int min, int max);

unsigned int readUnsignedInt();

int readInt();

float readFloat();

char readCharYorN();
