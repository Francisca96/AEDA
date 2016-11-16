#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;



struct Card {
	string rank;
	string suits;
	unsigned int score;

	bool operator==(const Card &a) const
	{
		return (this->rank == a.rank);
	}
	bool operator==(const string &a) const
	{
		return (this->rank == a);
	}
	
};
std::ostream& operator<<(std::ostream& out, const Card& c);
std::ostream& operator<<(std::ostream& out, const vector<Card>& v);

vector <Card> createDeck();

string getHumanPlay();

unsigned short int readUnsignedIntBetween(unsigned int min, unsigned int max);

int readIntBetween(int min, int max);

unsigned int readUnsignedInt();

int readInt();

int readBinary();

float readFloat();

char readCharYorN();

void Users(vector <int> &usersVEC, int &user);

void FileCopy(string filetxt, string filetxt_temp);

bool FileExist(string filetxt_temp);

int BinaryInt(int id, vector <int> VEC);

int saveChanges(vector <int> &usersVEC, int &user, pair <int, int> xy, int &save);

int readNameOfFile(string &fileName);
