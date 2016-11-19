/**
 * @file	C:\Users\ineeve\Documents\GitHub\aeda-casino\utils.h
 *
 * @brief	Declares the utilities.
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

/**
 * @struct	Card
 *
 * @brief	A card.
 *
 * @author	Ineeve
 * @date	19/11/2016
 */

struct Card {
	/** @brief	The rank. */
	string rank;
	/** @brief	The suits. */
	string suits;
	/** @brief	The score. */
	unsigned int score;

	/**
	 * @fn	bool operator==(const Card &a) const
	 *
	 * @brief	Equality operator.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	a	The Card to process.
	 *
	 * @return	True if the parameters are considered equivalent.
	 */

	bool operator==(const Card &a) const
	{
		return (this->rank == a.rank);
	}

	/**
	 * @fn	bool operator==(const string &a) const
	 *
	 * @brief	Equality operator.
	 *
	 * @author	Ineeve
	 * @date	19/11/2016
	 *
	 * @param	a	The rank to process.
	 *
	 * @return	True if the parameters are considered equivalent.
	 */

	bool operator==(const string &a) const
	{
		return (this->rank == a);
	}
	
};

/**
 * @fn	std::ostream& operator<<(std::ostream& out, const Card& c);
 *
 * @brief	Stream insertion operator.
 *			Makes the display of a card on the terminal.
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param [in,out]	out	The outstream.
 * @param 		  	c  	The Card to process.
 *
 * @return	The ostream produced.
 */

std::ostream& operator<<(std::ostream& out, const Card& c);

/**
 * @fn	std::ostream& operator<<(std::ostream& out, const vector<Card>& v);
 *
 * @brief	Stream insertion operator.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param [in,out]	out	The outstream.
 * @param 		  	v  	The vector of cards to process.
 *
 * @return	The ostream produced.
 */

std::ostream& operator<<(std::ostream& out, const vector<Card>& v);

/**
 * @fn	vector <Card> createDeck();
 *
 * @brief	Creates the deck.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @return	The new deck.
 */

vector <Card> createDeck();

/**
 * @fn	string getHumanPlay();
 *
 * @brief	Gets human play.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @return	The human play.
 */

string getHumanPlay();

/**
 * @fn	unsigned short int readUnsignedIntBetween(unsigned int minValue, unsigned int maxValue);
 *
 * @brief	Reads unsigned int between a minimum and a maximum values.
 *			Ask for user input.
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param	minValue	The minimum value.
 * @param	maxValue	The maximum value.
 *
 * @return	A unsigned int between the parameters set.
 */

unsigned short int readUnsignedIntBetween(unsigned int minValue, unsigned int maxValue);

/**
 * @fn	int readIntBetween(int min, int max);
 *
 * @brief	Reads int between a minimum and a maximum values.
 *			Ask for user input.
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param	min	The minimum.
 * @param	max	The maximum.
 *
 * @return	The int between the parameters set.
 */

int readIntBetween(int min, int max);

/**
 * @fn	unsigned int readUnsignedInt();
 *
 * @brief	Reads unsigned int.
 *			Asks for user input.
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @return	The unsigned int.
 */

unsigned int readUnsignedInt();

/**
 * @fn	int readInt();
 *
 * @brief	Reads a int value.
 *			Asks for user input.
 *			
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @return	The int inserted by the user.
 */

int readInt();

/**
 * @fn	int readBinary();
 *
 * @brief	Reads a 0 or a 1 from user input.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @return	The user input.
 */

int readBinary();

/**
 * @fn	float readFloat();
 *
 * @brief	Reads a float from user input.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @return	The float inputed by the user.
 */

float readFloat();

/**
 * @fn	char readCharYorN();
 *
 * @brief	Reads character "y" or "n".
 *			Case insensitive.
 *			
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @return	The character inserted by the user: "y" or "n".
 */

char readCharYorN();

/**
 * @fn	void Users(vector <int> &usersVEC, int &user);
 *
 * @brief	Reads and parses the users file to usersVec.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param [in,out]	usersVEC	The users vector.
 * @param [in,out]	user		The user id.
 */

void Users(vector <int> &usersVEC, int &user);

/**
 * @fn	void FileCopy(string filetxt, string filetxt_temp);
 *
 * @brief	Copies text between files.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param	filetxt			The file name;
 * @param	filetxt_temp	The temporary file name;
 */

void FileCopy(string filetxt, string filetxt_temp);

/**
 * @fn	bool FileExist(string filetxt_temp);
 *
 * @brief	Checks if the file with name filetxt_temp exists.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param	filetxt_temp	The temporary file name;
 *
 * @return	True if it exists, false otherwise.
 */

bool FileExist(string filetxt_temp);

/**
 * @fn	int BinaryInt(int id, vector <int> VEC);
 *
 * @brief	Performs a binary search of id in VEC.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param	id 	The identifier.
 * @param	VEC	The vector.
 *
 * @return	The index of id in Vec, or -1 if id was not found.
 */

int BinaryInt(int id, vector <int> VEC);

/**
 * @fn	int saveChanges(vector <int> &usersVEC, int &user, pair <int, int> xy, int &save);
 *
 * @brief	Asks user to save the current status when exiting.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param [in,out]	usersVEC	The users vector.
 * @param [in,out]	user		The user id.
 * @param 		  	xy			Pair with horizontal and vertical lengths of the terminal.
 * @param [in,out]	save		Boolean that holds user option to save or not the changes made.
 *
 * @return	0 in case of operation success.
 */

int saveChanges(vector <int> &usersVEC, int &user, pair <int, int> xy, int &save);

/**
 * @fn	int readNameOfFile(string &fileName);
 *
 * @brief	Ask user to input a file name.
 *
 * @author	Ineeve
 * @date	19/11/2016
 *
 * @param [in,out]	fileName	A string that will be updated with the user input.
 *
 * @return	0 in case of success.
 */

int readNameOfFile(string &fileName);
