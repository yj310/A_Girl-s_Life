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


	void BackgroundRender();
};