#pragma once

#ifdef _WIN32
#define OS_Windows 0
#include <windows.h>
#include <iomanip> 
#elif __APPLE__
#include "TargetConditionals.h"
#define OS_Windows 1
#elif __linux__
#define OS_Windows 2
#elif __unix__ // all unices not caught above
#define OS_Windows 3
#else
#error "Unknown compiler"
#endif

#include <iostream>
#include "utils.h"

using namespace std;


void clearScreen();

void cursorxy(int x, int y);

pair <int, int> centerWindow();

void start_menu(pair <int, int> xy, int &choise);