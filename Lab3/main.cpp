/************************************************************

Lab 3: Trivia Game

Author: Nathan Derichsweiler

Date: 10/27/2018
*************************************************************/
#include "Question.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <ostream>
#include <cstdio>

using namespace std;

//
void printAnswers(Question [], int);

/************************************************************
Purpose: Main. Controls program.

Pre: Use construtor and objects provided in question.cpp

Post: none

KNOWN BUG: I cant figure out why the question will not print out. Seems be related to the constructor part "question = question"
*************************************************************/
int main() {

	//Local Variables
	int count = 0; //store count to itterating through array
	int playersChoice; //store players choice
	
	//set number of elemnts for array
	const int NUM_ITEMS = 10;

	//populate elements in array with trivia questions answers
	Question trivia[NUM_ITEMS] = {
		Question("What is the capital of California?", "1. Rancho Cucamonga", "2. Sacramento", "3. Las Vegas", "4. Merced", 2),
		Question("What is the capital of Washington State?", "1. Seattle", "2. Redmond", "3. Microsoft", "4. Olympia", 4),
		Question("What is the capital of Florida?", "1. Gainsville", "2. Disney World", "3. Tallahassee", "4. Tampa Bay", 2),
		Question("What is the capital of Texas?", "1. Chuck Norris", "2. Austin", "3. Armadillio", "4. El Paso", 2),
		Question("What is the capital of Arizaon?", "1. Phoenix", "2. The Desert", "3. Tuscan", "4. Tempe", 2),
		Question("What is the capital of New York?", "1. New York", "2. Yankees Suck", "3. Albany", "4. Rochchester", 3),
		Question("What is the capital of Georgia?", "1. Atlanta", "2. Savannah", "3. Aguusta", "4. Athens", 1),
		Question("What is the capital of Navada?", "1. Rancho Cucamonga", "2. Carson City", "3. Las Vegas", "4. Merced", 2),
		Question("What is the capital of New Mexico?", "1. Rancho Cucamonga", "2. Sacramento", "3. Las Vegas", "4. Santa Fe", 4),
		Question("What is the capital of Ohio?", "1. Rancho Cucamonga", "2. Sacramento", "3. Columbus", "4. Merced", 3)
		};

	cout << "Let's play guess the state capital game!!!!";

	//Itterate through array with while loop.
	while (count < 10) {
	
		cout << setw(10) << "Question # " << (count + 1) << endl;
		printAnswers(trivia, count);
		cout << "Please enter answer: ";
		cin >> playersChoice; 
	
		//Check to see if answer is correct.
		if (trivia[count].getCorrectAnswer() == playersChoice) {
			cout << "CORRECT!!" << endl;
		}
		else {
			cout << "Sorry that is incorrect! The correct answer is: " << trivia[count].getCorrectAnswer() << endl;
		}
		cout << endl;
		count++; //iterate count to move to next element in Array.
	}
	
	return 0;
}

/************************************************************
Purpose: Print out Array of Trivia

Pre: accepts Questions class and int count of Array

Post: prints out objects from the questions
*************************************************************/
void printAnswers(Question q[], int count) {
	cout << q[count].getQuestion() << endl;
	cout << q[count].getAnswer1() << endl;
	cout << q[count].getAnswer2() << endl;
	cout << q[count].getAnswer3() << endl;
	cout << q[count].getAnswer4() << endl;
	}
