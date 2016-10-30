//#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Card
{
	string ranks;
	char suits;
	unsigned int score;
};

void clearScreen();

unsigned short int readUnsignedIntBetween(unsigned int min, unsigned int max);

int readIntBetween(int min, int max);

unsigned int readUnsignedInt();

int readInt();

float readFloat();

char readCharYorN();
