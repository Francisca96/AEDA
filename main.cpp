#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <exception>
#include "Casino.h"
#include "utils.h"
#include "cmdUI.h"

using namespace std;

int testFunction1() {
	unsigned int minBet = 2;
	unsigned int maxBet = 1000;
	unsigned int roundsToPlay = 200;
	unsigned int moneyOfTable = 30000;
	unsigned int maxNumberOfPlayers = 8;
	unsigned int casinoMoney = 1000000;
	vector<Table*> tablesVector;
	vector<Player *> playersVector;
	Dealer *pro = new Dealer;
	Table * table1 = new Table(roundsToPlay, minBet, maxBet, moneyOfTable, maxNumberOfPlayers, pro);
	tablesVector.push_back(table1);
	Casino estoril(casinoMoney);
	playersVector.push_back(new Bot0("Kika", 1000));
	playersVector.push_back(new Bot1("Renato", 1000));
	playersVector.push_back(new Bot1("Joao", 1000));
	playersVector.push_back(new Human("Rui", 18));
	estoril.addTableToCasino(table1);
	estoril.addPlayersToCasino(playersVector);
	estoril.addPlayersToTable(playersVector,table1);
	table1->play();
	table1->closeTable();
	estoril.showStatistics();
	
	return 0;
}



int main(){
	//Center window
	pair <int, int> xy;
	xy = centerWindow();

	//users
	vector <int> usersVEC;
	int user = 0;
	Users(usersVEC, user);

	//do the code just here
	//creat a casino
	string playersFileName = "players.txt", dealersFileName = "dealers.txt", tablesFileName = "tables.txt";
	Casino casino(100000);

	//read files names
	/*cout << "Write file name of players" << endl;
	readNameOfFile(playersFileName);
	cout << "Write file name of dealers" << endl;
	readNameOfFile(dealersFileName);
	cout << "Write file name of tables" << endl;
	readNameOfFile(tablesFileName);*/

	//set files name on casino
	casino.setPlayersFile(playersFileName);
	casino.setDealersFile(dealersFileName);
	casino.setTablesFile(tablesFileName);

		
	int choise, exit = 0;
	while (!exit)
	{
		start_menu(xy, choise);
		switch (choise)
		{
		case 1:
			system("CLS");
			//TODO: play (game run in normal mode with a human player)
			testFunction1();
			break;
		case 2:
			//TODO: simulation (game run all alone for n cycles)
			break;
		case 3:
			//TODO: choose table (selection one table to play on simulation or normal mode)
			break;
		case 4:
			//TODO: menu to creat table, define employee of table, and bots to tables, choose files...
			manageCasino(xy);
			break;
		case 0:
			exit = 1;
			break;
		default:
			break;
		}
	}

	//save changes of files
	int save;
	saveChanges(usersVEC, user, xy, save);
	if (save)
	{
		casino.savePlayersFile();
		//casino.saveDealersFile();
		//casino.saveTablesFile();
	}

	return 0;
}
