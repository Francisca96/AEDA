#pragma once

#include "cmdUI.h"


void clearScreen() {
	system("CLS");
}

void cursorxy(short x, short y) {
#ifdef _WIN32
		COORD p = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
#endif
}

void displayMenu0(pair<int, int> xy, string title, vector <string> menuOptions) {
	string text;
	cout << setw((xy.first - 36) / 2 - 1) << (char)201; //╔
	for (unsigned int i = 0; i <= 36; i++)
	{
		cout << (char)205; //═
	}
	cout << (char)187 << endl; //╗
	text = title;
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 //║
		<< setw((38 + text.length()) / 2) << text
		<< setw(38 - (38 + text.length()) / 2) << (char)186 << endl; //║
	cout << setw((xy.first - 36) / 2 - 1) << (char)204; //╠
	for (unsigned int i = 0; i <= 36; i++)
	{
		cout << (char)205; //═
	}
	cout << (char)185 /*╣*/ << endl;
	for (size_t i = 0; i < menuOptions.size(); i++)
	{
		text = menuOptions.at(i);
		cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw(7) << " " << text << setw(38 - (7 + text.length())) << (char)186 << endl;
	}
	cout << setw((xy.first - 36) / 2 - 1) << (char)200;
	for (unsigned int i = 0; i <= 36; i++)
	{
		cout << (char)205;
	}
	cout << (char)188 << endl << endl;
}

pair <int,int> centerWindow() {
#ifdef _WIN32
		HWND hwnd = GetConsoleWindow();
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);
		MoveWindow(hwnd, desktop.right * 0.175, desktop.bottom * 0.2, desktop.right * 0.65, desktop.bottom * 0.6, TRUE);
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD max_size = GetLargestConsoleWindowSize(screen);
		int console_x = max_size.X*desktop.right*0.65 / desktop.right - 1;
		int console_y = max_size.Y*desktop.bottom*0.6 / desktop.bottom - 1;
		if (console_x < 56)
		{
			console_x = max_size.X*desktop.right*0.9 / desktop.right + 3;
			console_y = max_size.Y*desktop.bottom*0.9 / desktop.bottom - 1;
			MoveWindow(hwnd, desktop.right * 0.025, desktop.bottom * 0.025, desktop.right * 0.95, desktop.bottom * 0.9, TRUE);
		}
		else if (console_y <= 15)
		{
			console_y = max_size.Y*desktop.bottom*0.9 / desktop.bottom - 1;
			MoveWindow(hwnd, desktop.right * 0.2, desktop.bottom * 0.1, desktop.right * 0.6, desktop.bottom * 0.8, TRUE);
		}

		/*PCONSOLE_FONT_INFOEX cmd_font;
		GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, cmd_font);
		cout << cmd_font->FaceName << endl;
		system("pause");*/

		pair <int, int> xy = { console_x,console_y };
		return xy;
#else
	pair <int, int> xy = {-1,-1};
	return xy;
#endif
}

void start_menu(pair <short, short> xy, int &choise) {
	//display author rights
	system("CLS");
	cursorxy((xy.first - 50) / 2 - 2, xy.second - 2);
	cout << (char)201; //╔
	for (unsigned int i = 0; i <= 50; i++)
	{
		cout << (char)205; //═
	}
	cout << (char)187 << endl; //╗
	cout << setw((xy.first - 50) / 2 - 1) << (char)186 /*║*/ << setw((50 - 31) / 2) << " " << "BlackJack " << (char)184 << " Console Application" << setw(12) << (char)186 /*║*/ << endl;
	cout << setw((xy.first - 50) / 2 - 1) << (char)186 /*║*/ << setw((50 + 43) / 2) << "AEDA 2016/2017 Grupo D, All Rights Reserved" << setw(6) << (char)186 /*║*/ << endl;
	cursorxy(0, 0);

	//draw of title (different draw if screen is small)
	cout << endl << endl;
	if (xy.first >= 78)
	{
		cout << setw((xy.first - 78) / 2 - 1) << " " << " _______    _        __      _____  _    _    _____     __     _____  _    _  " << endl
			<< setw((xy.first - 78) / 2 - 1) << " "  << "/_____  |  | |      /  \\    /  __/ | \\  / /  |___  |   /  \\   /  __/ | \\  / / " << endl
			<< setw((xy.first - 78) / 2 - 1) << " "  << "  | | | |  | |     /    \\   | |    | | / /       | |  /    \\  | |    | | / /  " << endl
			<< setw((xy.first - 78) / 2 - 1) << " "  << "  | |_| |  | |    |  /\\  |  | |    | |/ /        | | |  /\\  | | |    | |/ /   " << endl
			<< setw((xy.first - 78) / 2 - 1) << " "  << "  |  __  | | |    | |__| |  | |    |    |    _   | | | |__| | | |    |    |   " << endl
			<< setw((xy.first - 78) / 2 - 1) << " "  << "  | |  | | | |    |  __  |  | |    | |\\ \\   | |  | | |  __  | | |    | |\\ \\   " << endl
			<< setw((xy.first - 78) / 2 - 1) << " "  << "  | |__| | | \\__  | |  | |  | |__  | | \\ \\  | |__| | | |  | | | |__  | | \\ \\  " << endl
			<< setw((xy.first - 78) / 2 - 1) << " "  << "  |______|  \\___/ |_|  |_|  \\____\\ |_/  \\_\\ |______| |_|  |_| \\____\\ |_/  \\_\\ " << endl;
	}
	else
	{
		cout << setw((xy.first - 44) / 2) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191 << (char)218 << (char)191 << " " << (char)218 << (char)196 << (char)196 << (char)196 << (char)191 << (char)218 << (char)196 << (char)196 << (char)196 << (char)191 << (char)218 << (char)191 << "     " << (char)218 << (char)191 << (char)218 << (char)196 << (char)196 << (char)196 << (char)191 << (char)218 << (char)196 << (char)196 << (char)196 << (char)191 << (char)218 << (char)191 << endl
			<< setw((xy.first - 44) / 2) << (char)192 << (char)191 << (char)218 << (char)196 << (char)191 << (char)179 << (char)179 << (char)179 << " " << (char)179 << (char)218 << (char)196 << (char)191 << (char)179 << (char)179 << (char)218 << (char)196 << (char)196 << (char)217 << (char)179 << (char)179 << (char)218 << (char)191 << "   " << (char)179 << (char)179 << (char)179 << (char)218 << (char)196 << (char)191 << (char)179 << (char)179 << (char)218 << (char)196 << (char)196 << (char)217 << (char)179 << (char)179 << (char)218 << (char)191 << endl
			<< setw((xy.first - 44) / 2) << " " << (char)179 << (char)192 << (char)196 << (char)217 << (char)179 << (char)179 << (char)179 << " " << (char)179 << (char)192 << (char)196 << (char)217 << (char)179 << (char)179 << (char)179 << "   " << (char)179 << (char)192 << (char)217 << (char)192 << (char)191 << "  " << (char)179 << (char)179 << (char)179 << (char)192 << (char)196 << (char)217 << (char)179 << (char)179 << (char)179 << "   " << (char)179 << (char)192 << (char)217 << (char)192 << (char)191 << endl
			<< setw((xy.first - 44) / 2) << " " << (char)179 << (char)218 << (char)196 << (char)191 << (char)179 << (char)179 << (char)179 << " " << (char)179 << (char)218 << (char)196 << (char)191 << (char)179 << (char)179 << (char)179 << "   " << (char)179 << (char)218 << (char)196 << (char)191 << (char)179 << (char)218 << (char)191 << (char)179 << (char)179 << (char)179 << (char)218 << (char)196 << (char)191 << (char)179 << (char)179 << (char)179 << "   " << (char)179 << (char)218 << (char)196 << (char)191 << (char)179 << endl
			<< setw((xy.first - 44) / 2) << (char)218 << (char)217 << (char)192 << (char)196 << (char)217 << (char)179 << (char)179 << (char)192 << (char)191 << (char)179 << (char)179 << " " << (char)179 << (char)179 << (char)179 << (char)192 << (char)196 << (char)196 << (char)191 << (char)179 << (char)179 << " " << (char)179 << (char)179 << (char)179 << (char)192 << (char)217 << (char)179 << (char)179 << (char)179 << " " << (char)179 << (char)179 << (char)179 << (char)192 << (char)196 << (char)196 << (char)191 << (char)179 << (char)179 << " " << (char)179 << (char)179 << endl
			<< setw((xy.first - 44) / 2) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217 << (char)192 << (char)196 << (char)217 << (char)192 << (char)217 << " " << (char)192 << (char)217 << (char)192 << (char)196 << (char)196 << (char)196 << (char)217 << (char)192 << (char)217 << " " << (char)192 << (char)217 << (char)192 << (char)196 << (char)196 << (char)217 << (char)192 << (char)217 << " " << (char)192 << (char)217 << (char)192 << (char)196 << (char)196 << (char)196 << (char)217 << (char)192 << (char)217 << " " << (char)192 << (char)217 << endl;
	}
	cout << endl << endl;

	//display menu
	vector <string> options = {"1. Play" ,"2. Simulation", "3. Choose Table", "4. Manage Casino", "" ,"0. EXIT"};
	displayMenu0(xy, "MENU", options);
	choise = readIntBetween(0, 4);
}

void manageCasino(pair<short, short> xy, unsigned int &choise) {
	vector <string> options = {"1. Create ..." ,"2. Delete...", "3. Manage Tables", "4. Stats" , "" , "0. Return to MENU" };
	system("CLS");
	displayMenu0(xy, "MANAGE CASINO", options);
	choise = readIntBetween(0, 4);
}

void createMenu(pair<short, short> xy, unsigned int &choise) {
	vector <string> options = { "-. Create ..." ,"  1. Table" ,"  2. Dealer", "  3. Player (BOT)", "-. Delete...", "-. Manage Tables", "-. Stats" , "" ,"0. Back" };
	system("CLS");
	displayMenu0(xy, "1. Create ...", options);
	choise = readIntBetween(0, 3);
}

void deleteMenu(pair<short, short> xy, unsigned int &choise) {
	vector <string> options = { "-. Create ..." , "-. Delete...", "  1. Table" ,"  2. Dealer", "  3. Player (BOT)", "-. Manage Tables", "-. Stats" ,"" , "0. Back" };
	system("CLS");
	displayMenu0(xy, "2. Delete ...", options);
	choise = readIntBetween(0, 3);
}

void manageTableMenu(pair<short, short> xy, unsigned int & choise) {
	vector <string> options = { "-. Create ..." , "-. Delete...", "-. Manage Tables","  1. Set dealer", "  2. Add Player", "  3. Remove Player" , "-. Stats" ,"" , "0. Back" };
	system("CLS");
	displayMenu0(xy, "3. Manage Tables ...", options);
	choise = readIntBetween(0, 3);
}
