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
	void CreateLoadPlayerPage();
	void CreateMainHomeGamePage();
	void CreateMainSchoolGamePage();
	void CreateSchoolScienceQuizPage();
	void CreateSchoolKoreanQuizPage();

	void Update();
	void Render();


};