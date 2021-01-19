#pragma once
#include "page.h"
#include <d3dx9.h>

class PlayerInfoPage01 : public Page
{
public:

	PlayerInfoPage01();
	void Update() override;
	void Render() override;

	ID3DXFont* font = NULL;

	int BackButtonState;
	int NextButtonState;
	int ExitButtonState;
	int YesButtonState;
	int NoButtonState;

	int popup;


	/* Update */
	void BackButtonUpdate(POINT pt);
	void NextButtonUpdate(POINT pt);
	void ExitButtonUpdate(POINT pt);

	void DoExitUpdate(POINT pt);

	/* Render */
	void BackgroundRender();
	void dataRender();
	void BackButtonRender();
	void NextButtonRender();
	void ExitButtonRender();

	void DoExitRender();


};