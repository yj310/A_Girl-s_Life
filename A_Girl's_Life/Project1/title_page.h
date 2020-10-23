#pragma once
#include "page.h"
#include <d3dx9.h>

class TitlePage : public Page
{
public:

	TitlePage();
	void Update() override;
	void Render() override;


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