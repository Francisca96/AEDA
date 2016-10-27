#pragma once

#include <exception>
#include <string>
using namespace std;

class Dealer {
	private: string _deckVector;

	public: void hit();

	public: void stand();
};

