#pragma once

#include <string>
using namespace std;

class Table {
	private: string _minBet;
	private: string _maxBet;
	private: string _playersVectors;
	private: string _moneyOfTable;
	private: string _numberMaxOfPlayers;

	public: void getMinBet();

	public: void setMinBet(string aMinBet);

	public: void getMaxBet();

	public: void setMaxBet(string aMaxBet);
};

#endif
