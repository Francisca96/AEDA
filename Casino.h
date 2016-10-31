#pragma once

#include <vector>
#include <string>
#include "Dealer.h"
#include "Table.h"
#include "Player.h"

using namespace std;

class Casino {
private:
	string playersFile;
	string dealersFile;
	string tablesFile;
	unsigned int totalMoney;
	vector<Dealer> dealers;
	vector<Table> tables;
	vector<Player*> players;
public:
};
