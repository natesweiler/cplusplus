/******************************************************************
Lab 5
Author: Nathan Derichsweiler
Class: CIS 22B
Date: 12/1/2018

Propose: Read and decode encrpytped file.

*************************************************************/
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

#include "Encrypted.h"

using namespace std;

/******************************************************************
Purpose: This constrtor reads a file and stores it in pointer for processing.

Pre: Accepts filestring from user input and predefined MAX_TEXT varaible from main.

Post: nothing
*************************************************************/
Encrypted::Encrypted(string filename, int MAX_TEXT) {
	
	//Allocate space to store message from file.
	message = new char[MAX_TEXT + 1];
	message2 = new char[MAX_TEXT + 1];

	//Prepare to read file
	ifstream fp;
	fp.open(filename);

	//Read file until EOF. If
	while ((tempChar = fp.get()) != EOF)
	{
		//Set status flag to "false" if equal to MAX_TEXT
		if (i == MAX_TEXT)
		{
			status = false;
			break;
		}
		//store into temp;
		message[i++] = tempChar;

	}

	//set flag to "True" if read sucessfully.
	status = true;
	//to aviod garabage date set message to null
	message[i++] = NULL;
	//set the length to I
	length = i;

	//print out encrypted contents.
	cout << "Your encrpyted message is:\n" << message << endl;
	
	//close file
	fp.close();

}

/******************************************************************
Purpose: This decstructor frees allocated space

Pre: Accepts the variables to clear

Post: nothing
*******************************************************************/
Encrypted::~Encrypted() {
	delete[] message, length, delete[] message2;

}

/******************************************************************
Purpose: Print the decrptped message

Pre: nonthing

Post: nothing
*******************************************************************/
void Encrypted::print() const {

	cout << message2 << endl;

}
/******************************************************************
Purpose: Check to see if the message in the file is empty.

Pre: nonthing

Post: return true
*******************************************************************/
bool Encrypted::isEmpty() const {
	if (length != 0) {
		return 0;
	}
	else
		return 1;

}