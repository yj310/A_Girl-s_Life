#pragma once
#include "school_quiz_korean.h"
#include <d3dx9.h>
#include "page.h"


class SchoolKoreanQuizPage : public Page
{
public:
	SchoolKoreanQuizPage();
	void Update() override;
	void Render() override;

	KoreanQuizs* quizs;
	ID3DXFont* font = NULL;
	int quizCount;
	int firstAnswerButtonState;
	int secondAnswerButtonState;
	int OKButtonState;
	int timer;
	int maxTime;
	int O_Count;
	int X_Count;
	int rightAnswerCount;
	int wrongAnswerCount;


	void BackgroundRender();
};