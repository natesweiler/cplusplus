/************************************************************
CIS 22B - LAB1

Lab1: Calculate Average and Median of a file of test scores.
      
Author: Nathan Derichsweiler

Date: 10/6/2018
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

double calculateAverage(vector <double> &testScores);
double calculateMedian(vector <double> &testScores);
float readData(vector <double> &testScores);
double printReport(double average, double median, vector<double> &testScores);

/************************************************************
Purpose: Function calls

Pre: none

Post: none
*************************************************************/
int main()
{
    vector<double> testScores;
    double median, average;

    readData(testScores);
    average = calculateAverage(testScores);
    median = calculateMedian(testScores);
    printReport(average, median, testScores);

    system("pause");

    return 0;
}

/************************************************************
Purpose: Open file and read data into a vector. Sort the data.

Pre: none

Post: Pass by reference populated and sorted vector.
*************************************************************/

float readData(vector <double> &testScores){
    
    ifstream inputFile;
    string fileName;

    //Promt user to enter file name.
    cout << "Please type the file name: ";
    cin >> fileName;
    inputFile.open(fileName);

    //If fileopen failed add .txt on the end
    if (inputFile.fail())
    {
        inputFile.clear();
        inputFile.open(fileName.append(".txt"));
    }

    //Promt user to re-enter file name if file cannot be found.
    while (inputFile.fail())
    {
        cout << "File isn't found. Please type again:";
        cin >> fileName;
        inputFile.open(fileName);
        if (inputFile.fail())
        {
            inputFile.clear();
            inputFile.open(fileName.append(".txt"));
        }
    }

    //If file opens populate the elements in the file into the vector
    if (inputFile)
    {
        double value;

        // read the elements in the file into a vector  
        while (inputFile >> value) {
            testScores.push_back(value);
        }
    }
    //close file
    inputFile.close();

    //call .size function to get size of testScore vector.
    testScores.size();

    //Call sort function.
    sort(testScores.begin(), testScores.begin() + testScores.size());

    
    return 0;
}

/************************************************************
Purpose: Calulate the AVERAGE of all the test scores

Pre: Accepsts vector with test score values.

Post: Return the calculated Average.
*************************************************************/
double calculateAverage(vector<double> &testScores) {

    double total = 0;
    double average;

    //initialize number scores to the size of testScore vector
    double num_scores = testScores.size();

    //Range based loop for calculating test scores.
    for (double val : testScores)
        total += val;
    average = total / num_scores;

    return average;
}

/************************************************************
Purpose: Calculate the MEDIAN of all the test scores.

Pre: Accepts vector the test score values.

Post: Return the caluclate Median.
*************************************************************/
double calculateMedian(vector<double> &testScores) {

    double median;
    size_t size = testScores.size();

    //Check for ODD size. Add 2 values then divide by 2.
    if (size % 2 == 0)
    {
        median = (testScores[size / 2 - 1] + testScores[size / 2]) / 2;
    }
    //check for EVEN size. Divide size by 2.
    else
    {
        median = testScores[size / 2];
    }

    return median;
}

/************************************************************
Purpose: Print the processed Average and Median values

Pre: Accepts Median and Average from MAIN and passes vector testScores.

Post: none
*************************************************************/
double printReport(double average,double median, vector<double> &testScores) {
    
    cout << '\n';
    cout << "Test Scores:";
    for (vector<double>::iterator it = testScores.begin(); it != testScores.end(); ++it)
    cout << ' ' << *it;
    cout << '\n';
    cout << '\n';
    
    //Print only 2 decimal points for Average and Median
    cout << "Average = " << setprecision(2) << fixed << average;
    cout << '\n';
    cout << "Median = " << setprecision(2) << fixed << median;
    cout << '\n';
    cout << '\n';

    return 0;
}


