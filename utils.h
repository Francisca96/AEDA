#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

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



vector <Card> createDeck();

string getHumanPlay();

unsigned short int readUnsignedIntBetween(unsigned int min, unsigned int max);

int readIntBetween(int min, int max);

unsigned int readUnsignedInt();

int readInt();

float readFloat();

char readCharYorN();

void Users(vector <int> &usersVEC, int &user);

void FileCopy(string filetxt, string filetxt_temp);

bool FileExist(string filetxt_temp);

int BinaryInt(int id, vector <int> VEC);