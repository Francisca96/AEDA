#pragma once

#include "cmdUI.h"


void clearScreen() {
	system("CLS");
}

void cursorxy(int x, int y) {
	if (OS_Windows == 0)
	{
		COORD p = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	}
}

pair <int,int> centerWindow() {
	if (OS_Windows == 0)
	{
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

		pair <int, int> xy = { console_x,console_y };
		return xy;
	}
	pair <int, int> xy = {-1,-1};
	return xy;
}

void start_menu(pair <int, int> xy, int &choise) {
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
		cout << setw((xy.first - 78) / 2 - 1) << " " << " _______    _        __      _____  _     _   _____     __     _____  _    _  " << endl
			<< setw((xy.first - 78) / 2 - 1) << " "  << "/_____  |  | |      /  \\    /  __/ | \\   / / |___  |   /  \\   /  __/ | \\  / / " << endl
			<< setw((xy.first - 78) / 2 - 1) << " "  << "  | | | |  | |     /    \\   | |    | |  / /      | |  /    \\  | |    | | / /  " << endl
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
	string text;
	cout << setw((xy.first - 36) / 2 - 1) << (char)201; //╔
	for (unsigned int i = 0; i <= 36; i++)
	{
		cout << (char)205; //═
	}
	cout << (char)187 << endl; //╗
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 //║
		<< setw((36 + 4) / 2) << "MENU"
		<< setw(18) << (char)186 << endl; //║
	cout << setw((xy.first - 36) / 2 - 1) << (char)204; //╠
	for (unsigned int i = 0; i <= 36; i++)
	{
		cout << (char)205; //═
	}
	text = "1. Play";
	cout << (char)185 /*╣*/ << endl
		<< setw((xy.first - 36) / 2 - 1) << (char)186 << setw((38+text.length())/2) << text << setw(38 - (38 + text.length()) / 2) << (char)186 << endl;
	text = "2. Choose Table";
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw((38 + text.length()) / 2) << text << setw(38 - (38 + text.length()) / 2) << (char)186 << endl;
	text = "3. Simulation";
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw((38 + text.length()) / 2) << text << setw(38 - (38 + text.length()) / 2) << (char)186 << endl;
	text = "0. EXIT";
	cout << setw((xy.first - 36) / 2 - 1) << (char)186 << setw((38 + text.length()) / 2) << text << setw(38 - (38 + text.length()) / 2) << (char)186 << endl;
	cout << setw((xy.first - 36) / 2 - 1) << (char)200;
	for (unsigned int i = 0; i <= 36; i++)
	{
		cout << (char)205;
	}
	cout << (char)188 << endl << endl;
	choise = readIntBetween(0, 3);
}
