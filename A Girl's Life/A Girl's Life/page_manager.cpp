#include "page_manager.h"
#include "global.h"
#include "title_page.h"
#include "new_player_page.h"
#include "load_player_page.h"
#include "main_home_game_page.h"
#include "main_school_game_page.h"
#include "school_science_quiz_page.h"
#include "school_korean_quiz_page.h"


void PageManager::CreateTitlePage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}
	TitlePage* newPage = new TitlePage();
	currentPage = newPage;
}

void PageManager::CreateNewPlayerPage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}
	NewPlayerPage* newPage = new NewPlayerPage();
	currentPage = newPage;
}

void PageManager::CreateLoadPlayerPage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}
	LoadPlayerPage* newPage = new LoadPlayerPage();
	currentPage = newPage;
}

void PageManager::CreateMainHomeGamePage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}
	
	MainHomeGamePage* newPage = new MainHomeGamePage();
	currentPage = newPage;
}

void PageManager::CreateMainSchoolGamePage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}

	MainSchoolGamePage* newPage = new MainSchoolGamePage();
	currentPage = newPage;
}

void PageManager::CreateSchoolScienceQuizPage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}

	SchoolScienceQuizPage* newPage = new SchoolScienceQuizPage();
	currentPage = newPage;
}

void PageManager::CreateSchoolKoreanQuizPage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}

	SchoolKoreanQuizPage* newPage = new SchoolKoreanQuizPage();
	currentPage = newPage;
}

void PageManager::Update()
{
	if (currentPage != nullptr)
	{
		currentPage->Update();
		/*if (pageState == FadeOut)
		{
			
			if (FadingCount >= 50)
			{
				//pageState = FadeIn;
			}
		}
		else if (pageState == FadeIn)
		{
			
			if (FadingCount <= 0)
			{
				//pageState = Playing;
			}
		}
		else
		{
			currentPage->Update();
		}*/

	}

}

void PageManager::Render()
{
	if (currentPage != nullptr)
	{
		currentPage->Render();
		/*if (pageState == FadeOut)
		{
			//prevPage->Render();
		}
		else if (pageState == FadeIn)
		{
			currentPage->Render();
		}
		else
		{
			currentPage->Render();
		}*/
	}
}