#pragma once
#include "player.h"
#include "data_manager.h"

class Page;

class PageManager
{
public:

	enum State
	{
		FadeIn,
		FadeOut,
		Playing
	};

	Page* prevPage;
	Page* currentPage;
	Page* nextPage;

	State pageState;
	int FadingCount;

	void CreateTitlePage();
	void CreateNewPlayerPage();
	void CreateNewPlayerSelectCharacterPage();
	void CreateNewPlayerGameStartPage();
	void CreateLoadPlayerPage();
	void CreateMainHomeGamePage();
	void CreateMainSchoolGamePage();
	void CreatePlayerInfo01Page();
	void CreatePlayerInfo02Page();

	void CreateErrandPage();
	void CreateLeisurelyPage();

	void CreateSchoolQuizPage();

	void CreateSchoolScienceQuizPage();
	void CreateSchoolKoreanQuizPage();
	void CreateSchoolEnglishQuizPage();
	void CreateSchoolPTQuizPage();

	void Update();
	void Render();


};