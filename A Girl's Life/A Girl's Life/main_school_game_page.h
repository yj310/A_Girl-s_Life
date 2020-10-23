#pragma once
#include "page.h"
#include "player.h"
#include "main_game_page_ui.h"

class MainSchoolGamePage : public Page
{
public:
	MainSchoolGamePage();
	void Update() override;
	void Render() override;

	MainGamePageUI mainGamePageUI;




	/* Update */


	/* Render */
	void BackgroundRender();


};