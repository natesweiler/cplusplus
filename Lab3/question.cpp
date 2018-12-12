// question.cpp
// Lab 3: State Capital Triva Game
// Nathan Derichsweiler
// 10/27/2018

#include <iostream>
#include <string>
#include "Question.h"
using namespace std;

//Question constructor
Question::Question(string question, string ans1, string ans2, string ans3, string ans4, unsigned short int correct) {
	question = question;
	answer1 = ans1;
	answer2 = ans2;
	answer3 = ans3;
	answer4 = ans4;
	correctAnswer = correct;
}

//Add set functions
void Question::setQuestion(string question) {
	string question1 = question;
}

void Question::setAnswer1(string ans) {
	answer1 = ans;
}

void Question::setAnswer2(string ans) {
	answer2 = ans;
}

void Question::setAnswer3(string ans) {
	answer3 = ans;
}

void Question::setAnswer4(string ans) {
	answer4 = ans;
}

void Question::setCorrect(unsigned short int correct) {
	correctAnswer = correct;
}


//Add get functions
string Question::getQuestion() {
	return question;
}

string Question::getAnswer1() {
	return answer1;
}

string Question::getAnswer2() {
	return answer2;
}

string Question::getAnswer3() {
	return answer3;
}

string Question::getAnswer4() {
	return answer4;
}

unsigned short int Question::getCorrectAnswer() {
	return correctAnswer;
}