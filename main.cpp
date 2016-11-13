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

	casino.readPlayersFile();
	casino.readDealersFile();
	casino.readTablesFile();
	/*DEGUB*/
	/*cout << "Players: " << endl;
	casino.showPlayers();
	cout << "Dealers: " << endl;
	casino.showDealers();
	cout << "Tables: " << endl;
	casino.showTables();
	system("pause");*/

	unsigned int minBet = 2;
	unsigned int maxBet = 1000;
	unsigned int roundsToPlay = 200;
	unsigned int moneyOfTable = 30000;
	unsigned int maxNumberOfPlayers = 6;
	Dealer *pro = new Dealer;
	Table * table1 = new Table(minBet, maxBet, moneyOfTable, maxNumberOfPlayers, pro);
	vector<Player *> playersVector;
	playersVector.push_back(new Bot0("Kika", 1000));
	playersVector.push_back(new Bot1("Renato", 1000));
	playersVector.push_back(new Bot1("Joao", 1000));
	playersVector.push_back(new Bot0("Rui", 1000));
	casino.addTableToCasino(table1);
	casino.addPlayersToCasino(playersVector);
	casino.addPlayersToTable(playersVector, table1);
	casino.setTableToPlay(-1);

	/*END OF DEBUG*/
	int choise, exit = 0;
	pair <short, short> coordXY;
	coordXY.first = (xy.first % 32) / 2 - 1;
	bool found = false;
	while (!exit)
	{
		start_menu(xy, choise);
		switch (choise)
		{
		case 1:
			system("CLS");
			//TODO: play (game run in normal mode with a human player)
			try
			{
				//casino.getTableToPlay()->play();
				casino.showStatistics();
				system("pause");
			}
			catch (TableNotInCasino)
			{
				cout << "Please select a table first" << endl;
				system("pause");
			}
			catch (NoPlayersOnTable noPlayersOnTable)
			{
				cout << "The table: " << noPlayersOnTable.getID() << " dont have players" << endl;
				cout << "Please select a table with players first" << endl;
				system("pause");
			}
			break;
		case 2:
			//TODO: simulation (game run all alone for n cycles)
			try
			{
				casino.getTableToPlay()->simulation(roundsToPlay);
				casino.showStatistics();
				system("pause");
			}
			catch (TableNotInCasino)
			{
				cout << "Please select a table first" << endl;
				system("pause");
			}
			catch (NoPlayersOnTable noPlayerOnTable)
			{
				cout << "The table: " << noPlayerOnTable.getID() << " dont have players" << endl;
				cout << "Please select a table with players first" << endl;
				system("pause");
			}
			break;
		case 3:
			//TODO: choose table (selection one table to play on simulation or normal mode)
			system("CLS");
			unsigned int tableID;
			found = false;

			for (size_t i = 0; i < casino.getTables().size(); i++)
			{
				casino.getTables().at(i)->showTableInfo(coordXY);
				coordXY.first += 32;
				if (coordXY.first + 32 > xy.first)
				{
					coordXY.first = (xy.first % 32) / 2;
					coordXY.second += 13;
				}
			}
			cout << endl << endl << endl;
			while (!found)
			{
				cout  << "Select table by ID" << endl;
				tableID = readInt();
				for (size_t i = 0; i < casino.getTables().size(); i++)
				{
					if (casino.getTables().at(i)->getTableID() == tableID)
					{
						found = true;
						casino.setTableToPlay(tableID);
						cout << "Table select with success" << endl;
						break;
					}
				}
			}
			system("pause");
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
		casino.saveDealersFile();
		casino.saveTablesFile();
	}

	return 0;
}
