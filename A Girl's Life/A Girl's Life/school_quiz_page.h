#pragma once
#include "page.h"
#include <d3dx9.h>
#include "data_manager.h"

class SchoolQuizPage : public Page
{
public:

	SchoolQuizPage();
	void Update() override;
	void Render() override;

	Quizs* quizs;
	ID3DXFont* font = NULL;
	int quizCount;

	int NewButtonState;
	int LoadButtonState;
	int ExitButtonState;

	/* Update */
	void NewButtonUpdate(POINT pt);
	void LoadButtonUpdate(POINT pt);
	void ExitButtonUpdate(POINT pt);


	/* Render */
	void BackgroundRender();
	void NewButtonRender();
	void LoadButtonRender();
	void ExitButtonRender();


};