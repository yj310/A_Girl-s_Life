#pragma once
#include "school_quiz_pt.h"
#include <d3dx9.h>
#include "page.h"

class SchoolPTQuizPage : public Page
{
public:
	SchoolPTQuizPage();
	void Update() override;
	void Render() override;

	PTQuizs* quizs;
	ID3DXFont* font = NULL;
	int quizCount;

	char arrow[4] = { '<','>','A','V' };


	/* Update */


	/* Render */
	void BackgroundRender();
};