#pragma once
/******************************************************************
Lab 5
Author: Nathan Derichsweiler
Class: CIS 22B
Date: 12/1/2018

Propose: Derivied class for CypherB.
*************************************************************/
#include "stdafx.h"
#include "Encrypted.h"
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

class CypherB : public Encrypted
{
public:
	CypherB() : Encrypted() {
		}

	CypherB(string filename, int MAX_TEXT) : Encrypted(filename, MAX_TEXT) {

	}

	virtual void decode() {
	//Sort through message and write to message2 for printing later.
		for (int i = 0; i < length; i++)
		{
			if ((message[i] > 'a') && (message[i] < 'z') )
			{
				// Verify current posisiton of i is not a space
				if (message[i] != ' ')
				{
					// subtracts 4 from the letter of message
					message2[i] = message[i] - 4;
					// verify position is not less than 'a'
					if (message2[i] < 'a') 
						//add 'z' - 'a' - 4 from current i position is i is less than 'a'
						message2[i] = message[i] + 'z' - 'a' - 4;
				}
			}
			 // if all are false keep orignal char in i
				else
					message2[i] = message[i];
			}
		}

/******************************************************************
Purpose: This decstructor frees allocated space

Pre: Accepts the variables to clear

Post: nothing
*******************************************************************/
~CypherB() {
		delete[] message, length, delete[] message2;
	}

};