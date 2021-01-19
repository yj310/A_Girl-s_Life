#pragma once
#include "page.h"
#include "player.h"
#include "main_game_page_ui_02.h"

class MainSchoolGamePage : public Page
{
public:
	MainSchoolGamePage();
	void Update() override;
	void Render() override;

	MainGamePageUI02 mainGamePageUI;


	/* Update */


	/* Render */
	void BackgroundRender();


};