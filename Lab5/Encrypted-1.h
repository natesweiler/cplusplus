#pragma once
/******************************************************************
Lab 5
Author: Nathan Derichsweiler
Class: CIS 22B
Date: 12/1/2018

Propose: header file for delaring varables and functions
*************************************************************/
#include "stdafx.h"
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

/******************************************************************
Purpose: Encrpyted class to be used in other cpp files.

Pre: nothing

Post: nothing
*************************************************************/
class Encrypted
{
protected:
	char *message;   // ptr to hold encrypted message from text.
	char *message2;  // ptr #2 to hold the decrptyted message.
	int length;      // hold message length as int
	int status;      // hold status True of false
	char tempChar;   // temp char
	int i = 0;       // for itieratior in Encrypted.cpp

public:
	Encrypted() {};
	Encrypted(string filename, int MAX_TEXT);
	virtual void decode() = 0;
	virtual ~Encrypted();
	void print() const;
	bool isEmpty() const;
};