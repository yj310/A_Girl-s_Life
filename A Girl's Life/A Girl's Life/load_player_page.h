#pragma once
#include "page.h"
#include <d3dx9.h>



class LoadPlayerPage : public Page
{
public:

	LoadPlayerPage();
	void Update() override;
	void Render() override;


	int BackButtonState;
	int DataButtonState[256];
	ID3DXFont* font = NULL;
	int scrol = 0;




	/* Update */
	void BackButtonUpdate(POINT pt);
	void ScrolUpdate();
	void ClickDataUpdate(POINT pt);

	/* Render */
	void BackgroundRender();
	void DatasRender();
	void BackButtonRender();


};