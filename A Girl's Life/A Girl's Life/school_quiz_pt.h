#pragma once

#include <iostream>
#include <vector>
using namespace std;

class PTQuiz
{
public:
	char question[128];
	char answer[128];
	char choice1[128];
	char choice2[128];

	PTQuiz() {}

	void setQuizInfo(char* question, char* answer, char* choice1, char* choice2)
	{
		strcpy_s<128>(this->question, question);
		strcpy_s<128>(this->answer, answer);
		strcpy_s<128>(this->choice1, choice1);
		strcpy_s<128>(this->choice2, choice2);
	}

	~PTQuiz()
	{
		delete[] question;
		delete[] answer;
		delete[] choice1;
		delete[] choice2;
	}
};

class PTQuizs
{
public:
	vector<PTQuiz*> quizs;
};