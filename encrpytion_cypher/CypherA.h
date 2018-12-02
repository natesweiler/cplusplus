#pragma once
/******************************************************************
Lab 5
Author: Nathan Derichsweiler
Class: CIS 22B
Date: 12/1/2018

Propose: Derivied class for CypherA.
*************************************************************/
#include "stdafx.h"
#include "Encrypted.h"
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class CypherA : public Encrypted
{

public:
	CypherA() : Encrypted() {
		
	}

	CypherA(string filename, int MAX_TEXT) : Encrypted(filename, MAX_TEXT) {
		
	}

	virtual void decode() {
		//Key for decoding
		char KEY[] = { 'i','z','t','o','h','n','d','b','e','q','r','k','g','l','m','a','c','s','v','w','f','u','y','p','j','x' };

		//Sort through message and write to ness message2 for printing later.
		for (int i = 0; i < length; i++)
		{
			if (message[i] < 'a' || message[i] > 'z')
				message2[i] = message[i];
			else
				message2[i] = KEY[(int)message[i] - 'a'];
		}
	}

/******************************************************************
Purpose: This decstructor frees allocated space

Pre: Accepts the variables to clear

Post: nothing
*******************************************************************/

~CypherA() {
	delete[] message, length, delete[] message2;
	}

};