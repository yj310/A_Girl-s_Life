#pragma once
#include "page.h"
#include <d3dx9.h>

class ErrandPage : public Page
{
public:

	ErrandPage();
	void Update() override;
	void Render() override;

	ID3DXFont* font = NULL;

	int BackButtonState;
	int shoppingState;
	int washDishState;
	int YesButtonState;
	int NoButtonState;

	int selectErrand;

	/* Update */
	void BackButtonUpdate(POINT pt);
	void ErrandButtonUpdate(POINT pt);

	void DoErrandUpdate(POINT pt);

	/* Render */
	void BackgroundRender();
	void BackButtonRender();
	void ErrandButtonRender();

	void DoErrandRender();


};