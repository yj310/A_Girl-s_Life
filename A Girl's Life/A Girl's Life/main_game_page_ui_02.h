#pragma once
#include <d3dx9.h>

class MainGamePageUI02
{
public:
	MainGamePageUI02();
	void Update();
	void Render();
	void TableRender();

	int enterClassButtonState;
	int showTableButtonState;
	int NameBarState;
	int closeButtonState;

	int showTableState;

	int charecterTexture;

	ID3DXFont* font = NULL;
	ID3DXFont* font2 = NULL;
};