#pragma once
#include "school_quiz_science.h"
#include <d3dx9.h>
#include "page.h"

class SchoolScienceQuizPage : public Page
{
public:
	SchoolScienceQuizPage(); 
	void Update() override;
	void Render() override;

	ScienceQuizs* quizs;
	ID3DXFont* font = NULL;
	int quizCount;
	int colorCount;

	char colors[8][10] = { "violet", "blue", "red", "yello", "green", "dark", "white", "pink" };

	int NewButtonState;
	int LoadButtonState;
	int ExitButtonState;

	/* Update */


	/* Render */
	void BackgroundRender();
};