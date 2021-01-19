#pragma once

#include <vector>
using namespace std;

class EnglishQuiz
{
public:
	vector<char> question;
	vector<char> answer;
	char mean[128];

	EnglishQuiz() {}



	~EnglishQuiz() {}
};

class EnglishQuizs
{
public:
	vector<EnglishQuiz*> quizs;
};
