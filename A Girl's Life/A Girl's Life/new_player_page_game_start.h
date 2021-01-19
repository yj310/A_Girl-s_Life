#pragma once
#include "page.h"
#include "player.h"
#include <d3dx9.h>
using namespace std;

class NewPlayerPageGameStart : public Page
{
public:

	NewPlayerPageGameStart();
	void Update() override;
	void Render() override;


	int BackButtonState;
	int YesButtonState;
	int NoButtonState;
	

	/* Update */
	void BackButtonUpdate(POINT pt);
	void YesButtonUpdate(POINT pt);
	void NoButtonUpdate(POINT pt);


	/* Render */
	void BackgroundRender();

	void BackButtonRender();
	void YesButtonRender();
	void NoButtonRender();


};