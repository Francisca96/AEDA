#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <exception>
#include "Casino.h"
#include "utils.h"
#include "cmdUI.h"

using namespace std;


int main(){
	//Center window
	pair <int, int> xy;
	xy = centerWindow();

	//users
	vector <int> usersVEC;
	int user = 0;
	Users(usersVEC, user);

	//TODO: implement fuction of display menu

	//verify users and changes of files
	char decision;
	Users(usersVEC, user);
	if (usersVEC.size() == 1)
	{
		system("cls");
		cout << setw((xy.first - 50) / 2) << (char)201;
		for (int i = 0; i < 50; i++)
		{
			cout << (char)205;
		}
		cout << (char)187 << endl;
		cout << setw((xy.first - 50) / 2) << (char)186 << setw(51) << (char)186 << endl;
		cout << setw((xy.first - 50) / 2) << (char)186 << setw((50 + 35) / 2) << "Deseja Guarda as Alteracoes Feitas?" << setw(9) << (char)186 << endl;
		cout << setw((xy.first - 50) / 2) << (char)186 << setw(51) << (char)186 << endl;
		cout << setw((xy.first - 50) / 2) << (char)200;
		for (int i = 0; i < 50; i++)
		{
			cout << (char)205;
		}
		cout << (char)188 << endl;
		cout << endl << "Se Sim digite 'Y', caso contrario digite 'N': ";
		cin >> decision;
		while (!(decision == 'Y' || decision == 'y' || decision == 'N' || decision == 'n'))
		{
			cout << endl << "Se Sim digite 'Y', caso contrario digite 'N': ";
			cin >> decision;
		}

		//alteracao
		if (decision == 'Y' || decision == 'y')
		{
			FileCopy("","");//copy file temp for original
			remove("");//delete file temp
			remove("users_temp.txt");

		}
		else if (decision == 'N' || decision == 'n')
		{
			remove("users_temp.txt");//delete file temp
		}
	}
	else
	{
		//elimina usuario no vetor
		usersVEC.erase(usersVEC.begin() + BinaryInt(user, usersVEC));

		ofstream UserFileO("users_temp.txt");
		if (UserFileO.is_open())
		{
			for (unsigned int i = 0; i < usersVEC.size(); i++)
			{
				UserFileO << usersVEC.at(i) << endl;
			}
			UserFileO.close();
		}
	}

	return 0;
}
