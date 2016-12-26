#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <exception>
#include "Casino.h"
//#include "utils.h"
#include "cmdUI.h"

using namespace std;


int main(){
	//Center window
	pair <int, int> xy;
	xy = centerWindow();

	//do the code just here
	//creat a casino
	string playersFileName = "players.txt", dealersFileName = "dealers.txt", tablesFileName = "tables.txt", usersFileName = "login.txt";
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
	casino.setUsersFile(usersFileName);

	casino.readPlayersFile();
	casino.readDealersFile();
	casino.readTablesFile();
	casino.readLoginFile();
	/*DEGUB*/
	/*cout << "Players: " << endl;
	casino.showPlayers();
	cout << "Dealers: " << endl;
	casino.showDealers();
	cout << "Tables: " << endl;
	casino.showTables();
	system("pause");*/

	/*unsigned int minBet = 2;
	unsigned int maxBet = 1000;
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
	casino.setTableToPlay(-1);*/

	srand(time(0));
	int tryNumber = 0;
	try
	{
		casino.login(xy);
	}
	catch (PlayerNotExistException)
	{
		//TODO: creat new user
		return 1;
	}

	//users
	vector <int> usersVEC;
	int user = 0;
	Users(usersVEC, user);

	/*END OF DEBUG*/
	int choice, exit = 0;
	unsigned int roundsToPlay;
	bool found = false;
	while (!exit)
	{
		start_menu(xy, choice);
		switch (choice)
		{
		case 1:
			system("CLS");
			//TODO: play (game run in normal mode with a human player)
			try
			{
				casino.getTableToPlay()->play(xy, user);
				system("pause");
			}
			catch (TableNotInCasinoException)
			{
				cout << "Please select a table first" << endl;
				system("pause");
			}
			catch (NoPlayersOnTableException NoPlayersOnTableException)
			{
				cout << "The table: " << NoPlayersOnTableException.getID() << " dont have players" << endl;
				cout << "Please select a table with players first" << endl;
				system("pause");
			}
			catch (TooManyPlayersException)
			{
				cout << "You can't play on table selected" << endl;
				cout << "The table is full" << endl;
				system("pause");
			}
			catch (TooYoungException)
			{
				cout << "You can't play on table selected" << endl;
				cout << "You are too young for play this game" << endl;
				system("pause");
			}
			break;
		case 2:
			//TODO: simulation (game run all alone for n cycles)
			cout << "How many rounds do you want to simulate?" << endl;
			roundsToPlay = readUnsignedInt();
			try
			{
				casino.getTableToPlay()->simulation(roundsToPlay);
				system("pause");
			}
			catch (TableNotInCasinoException)
			{
				cout << "Please select a table first" << endl;
				system("pause");
			}
			catch (NoPlayersOnTableException noPlayerOnTable)
			{
				cout << "The table: " << noPlayerOnTable.getID() << " dont have players" << endl;
				cout << "Please select a table with players first" << endl;
				system("pause");
			}
			catch (HumanOnTableException)
			{
				cout << "The table has a human" << endl;
				cout << "Please select a table with no humans" << endl;
				system("pause");
			}
			break;
		case 3:
			//TODO: choose table (selection one table to play on simulation or normal mode)
			try
			{
				casino.readTablesFile();
				casino.selectTable(xy);
			}
			catch (TableNotInCasinoException)
			{
				cout << "This table not exist" << endl;
			}
			system("pause");
			break;
		case 4:
			//TODO: menu to creat table, define employee of table, and bots to tables, choose files...
			casino.manage(xy);
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
