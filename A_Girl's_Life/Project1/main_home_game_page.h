#pragma once
#include "page.h"
#include "main_game_page_ui.h"

class MainHomeGamePage : public Page
{
public:
	MainHomeGamePage();
	void Update() override;
	void Render() override;


	MainGamePageUI mainGamePageUI;



	/* Update */


	/* Render */
	void BackgroundRender();


};