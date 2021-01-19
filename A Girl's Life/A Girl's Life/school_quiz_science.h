#pragma once

#include <vector>
using namespace std;

class ScienceQuiz
{
public:
	vector<char> question;
	vector<char> answer;

	ScienceQuiz() {}

	

	~ScienceQuiz(){}
};

class ScienceQuizs
{
public:
	vector<ScienceQuiz*> quizs;
};