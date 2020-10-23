#pragma once
#include <d3dx9.h>

class MainGamePageUI
{
public:
	MainGamePageUI();
	void Update();
	void Render();

	int errandButtonState;
	int leisureButtonState;
	int homeworkButtonState;

	ID3DXFont* font = NULL;
};