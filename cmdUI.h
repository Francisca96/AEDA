/**
 * @file	C:\Users\ineeve\Documents\GitHub\aeda-casino\cmdUI.h
 *
 * @brief	Declares the command user interface.
 */

#pragma once

#ifdef _WIN32
#define OS_Windows 0
#include <windows.h>
#else
#define OS_Windows 1
#endif

#include <iostream>
#include "utils.h"
#include <iomanip> 


using namespace std;

/**
 * @fn	void clearScreen();
 *
 * @brief	Clears the terminal.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

void clearScreen();

/**
 * @fn	void cursorxy(short x, short y);
 *
 * @brief	Set cursor on <x,y> coordinates.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param	x	The x coordinate.
 * @param	y	The y coordinate.
 */

void cursorxy(short x, short y);

/**
 * @fn	pair <int, int> centerWindow();
 *
 * @brief	Center the terminal window.
 *			The returned length is measured in characters.
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @return	A pair <x,y>. x= terminal horizontal length, y = terminal vertical length.
 */

pair <int, int> centerWindow();

/**
* @fn	void drawTitle(pair <short, short> xy);
*
* @brief	Displays the title.
*
* @author	João Carvalho
* @date	26/12/2016
*
* @param 		  	xy	  	A pair containing the horizontal and vertical lengths of the terminal.
*/

void drawTitle(pair <short, short> xy);

/**
 * @fn	void start_menu(pair <short, short> xy, int &choice);
 *
 * @brief	Displays the main menu.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param 		  	xy	  	A pair containing the horizontal and vertical lengths of the terminal.
 * @param [in,out]	choice	The user choice.
 */

void start_menu(pair <short, short> xy, int &choice);

/**
 * @fn	void manageCasino(pair <short, short> xy, unsigned int &choice);
 *
 * @brief	Displays the manage casino menu and reads user choice.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param 		  	xy	  	A pair containing the horizontal and vertical lengths of the terminal.
 * @param [in,out]	choice	The user choice.
 */

void manageCasino(pair <short, short> xy, unsigned int &choice);

/**
 * @fn	void createMenu(pair <short, short> xy, unsigned int &choice);
 *
 * @brief	Creates a menu.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param 		  	xy	  	A pair containing the horizontal and vertical lengths of the terminal.
 * @param [in,out]	choice	The user choice.
 */

void createMenu(pair <short, short> xy, unsigned int &choice);

/**
 * @fn	void deleteMenu(pair <short, short> xy, unsigned int &choice);
 *
 * @brief	Displays a delete menu and reads user choice.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param 		  	xy	  	A pair containing the horizontal and vertical lengths of the terminal.
 * @param [in,out]	choice	The user choice.
 */

void deleteMenu(pair <short, short> xy, unsigned int &choice);

/**
 * @fn	void manageTableMenu(pair <short, short> xy, unsigned int &choice);
 *
 * @brief	Displays the manage table menu and reads user choice.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param 		  	xy	  	A pair containing the horizontal and vertical lengths of the terminal.
 * @param [in,out]	choice	The user choice.
 */

void manageTableMenu(pair <short, short> xy, unsigned int &choice);

/**
* @fn	void statisticsMenu(pair <short, short> xy, unsigned int &choice);
*
* @brief	Displays the statistics menu and reads user choice.
*
* @author	Ineeve
* @date	30/12/2016
*
* @param 		  	xy	  	A pair containing the horizontal and vertical lengths of the terminal.
* @param [in,out]	choice	The user choice.
*/

void statisticsMenu(pair<short, short> xy, unsigned int &choice);