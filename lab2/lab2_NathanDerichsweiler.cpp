/************************************************************
CIS 22B - LAB2

Lab2: This programs imports a list of books then sorts them
according to users request.

Author: Nathan Derichsweiler

Date: 10/21/2018
*************************************************************/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

struct Book {
	string title;
	string author;
	string genre;
};

/******************************************************************
Purpose: These functions handle the comparing of data in structures.

Pre: Accepts vector of structures for books

Post: returns the updated and sorted vector
*************************************************************/
bool compareByTitle(Book book1, Book book2) { return (book1.title < book2.title); }
bool compareByAuthor(Book book1, Book book2) { return (book1.author < book2.author); }
bool compareByGenre(Book book1, Book book2) { return (book1.genre < book2.genre); }

//function proto
void printReport(const vector<Book> &myBooks);

/************************************************************
Purpose: Open, read file, and handle user input cases

Pre: none

Post: none
*************************************************************/

int main()
{
	ifstream inputFile;
	string line;

	Book book;
	vector<Book> myBooks;

	int userSelection = 0;
	char userSelectionYN = ' ';

	inputFile.open("Books.txt");

	//Open file and read line by line.
	while (getline(inputFile, line))   // reads a line from the file
	{

		stringstream lineStream(line);   // transforms the line into a string stream

		// get fields from the string stream to the struct fields; data is separated by comma
		getline(lineStream, book.title, ',');
		getline(lineStream, book.author, ',');
		getline(lineStream, book.genre, ',');

		//push each line to the vector
		myBooks.push_back(book);


		// DEBUG
		/*cout << "\tTitle: " << book.title << endl;
		cout << "\tAuthor: " << book.director << endl;
		cout << "\tGenre: " << book.genre << endl;
		*/
	}
	inputFile.close();

	//Do loop for handling user's Yes or No input
	do {

		cout << "Would you like to sort the books by: " << endl;
		cout << "1. Title\n" << "2. Author\n" << "3. Genre\n" << endl;
		cout << "Please Enter #: ";
		cin >> userSelection;

		//Switch handles each case of the user input. Then calls the approirate function for sorting and printing.
		switch (userSelection) {

		case 1:
			sort(myBooks.begin(), myBooks.end(), compareByTitle);
			printReport(myBooks);

			break;

		case 2:
			sort(myBooks.begin(), myBooks.end(), compareByAuthor);
			printReport(myBooks);

			break;
		case 3:
			sort(myBooks.begin(), myBooks.end(), compareByGenre);
			printReport(myBooks);

			break;

		case 4:

			exit(0);

			break;

		}
		cout << "\n";
		cout << "Do you want to try again? (y/n): ";
		cin >> userSelectionYN;

	} while (userSelectionYN == 'y' || userSelectionYN == 'Y');

	system("pause");
	return 0;
}

/************************************************************
Purpose: Print the vector of structure

Pre: Accepts the Vector of data.

Post: none
*************************************************************/
void printReport(const vector<Book> &myBooks) {

	cout << "\n";
	cout << left << setw(42) << "Title" << setw(26) << "Author" << setw(35) << "Genre" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	cout << "\n";
	for (int i = 0; i<myBooks.size(); ++i) {
		cout << left << setw(40) << myBooks[i].title << " " << setw(25) << myBooks[i].author << " " << setw(25) << myBooks[i].genre << " " << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
	}
}