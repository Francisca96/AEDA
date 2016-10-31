#pragma once

#include "utils.h"


vector<Card>& createDeck() {
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



void clearScreen(){
	system("CLS");
}

unsigned short int readUnsignedIntBetween(unsigned int minValue, unsigned int  maxValue){
	unsigned int short newInt;
	cout << "Insira um valor: ";
	while (!(cin >> newInt) || newInt > maxValue || newInt < minValue) {
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Valor invalido. Introduza um novo unsigned short int: ";
	}
	cin.ignore();
	cout << endl;
	return newInt;
}


int readIntBetween(int min, int max){
	int newInt;
	cout << "Insira um valor: ";
	while(!(cin >> newInt) || newInt > max || newInt < min) {
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Valor invalido. Introduza um novo int: ";
	}
	cin.ignore();
	cout << endl;
	return newInt;
}

unsigned int readUnsignedInt() {
	unsigned int newUnsignedInt;
	cout << "Insira um valor: ";
	while (!(cin >> newUnsignedInt)) {
		cout << endl;
		cin.clear();
		cin.ignore();

		cout << "Valor invalido, insira um novo valor unsigned int: ";
	}
	cin.ignore();
	cout << endl;
	return newUnsignedInt;
}
int readInt() {
	int newInt;
	cout << "Insira um valor: ";
	while (!(cin >> newInt)) {
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Valor invalido, insira um novo valor unsigned int: ";
	}
	cin.ignore();
	cout << endl;
	return newInt;
}
float readFloat() {
	float newFloat;
	cout << "Insira um novo valor: ";
	while (!(cin >> newFloat)) {
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Valor invalido, insira um novo valor: ";
	}
	cin.ignore();
	cout << endl;
	return newFloat;
}
char readCharYorN() {
	char newChar;
	cout << "Insira o caracter: ";
	while (!(cin >> newChar) || (newChar != 'n' && newChar != 'N' && newChar != 'Y' && newChar != 'y')) {
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Caracter invalido, insira um novo caracter: ";
	}
	cin.ignore();
	cout << endl;
	return newChar;
}
