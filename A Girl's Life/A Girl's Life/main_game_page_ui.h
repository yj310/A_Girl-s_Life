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
	int NameBarState;

	int charecterTexture;

	ID3DXFont* font = NULL;
	ID3DXFont* font2 = NULL;
};