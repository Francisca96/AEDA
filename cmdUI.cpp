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
		MoveWindow(hwnd, desktop.right * 0.2, desktop.bottom * 0.2, desktop.right * 0.6, desktop.bottom * 0.6, TRUE);
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD max_size = GetLargestConsoleWindowSize(screen);
		int console_x = max_size.X*desktop.right*0.6 / desktop.right - 1;
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