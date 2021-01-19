#pragma once
#include "page.h"
#include <d3dx9.h>

class PlayerInfoPage02 : public Page
{
public:

	PlayerInfoPage02();
	void Update() override;
	void Render() override;

	ID3DXFont* font = NULL;

	int BackButtonState;
	int PrevButtonState;
	int ExitButtonState;
	int YesButtonState;
	int NoButtonState;

	int popup;


	/* Update */
	void BackButtonUpdate(POINT pt);
	void PrevButtonUpdate(POINT pt);
	void ExitButtonUpdate(POINT pt);

	void DoExitUpdate(POINT pt);

	/* Render */
	void BackgroundRender();
	void dataRender();
	void BackButtonRender();
	void PrevButtonRender();
	void ExitButtonRender();

	void DoExitRender();


};