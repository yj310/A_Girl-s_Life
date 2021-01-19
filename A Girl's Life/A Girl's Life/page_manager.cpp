#include "page_manager.h"
#include "global.h"
#include "title_page.h"
#include "new_player_page.h"
#include "load_player_page.h"
#include "main_home_game_page.h"
#include "main_school_game_page.h"
#include "school_science_quiz_page.h"
#include "school_korean_quiz_page.h"
#include "school_english_quiz_page.h"
#include "school_history_quiz_page.h"
#include "school_pt_quiz_page.h"
#include "new_player_page_select_character.h"
#include "new_player_page_game_start.h"
#include "errand_page.h"
#include "player_info_page_01.h"
#include "player_info_page_02.h"
#include "leisurely_page.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

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

void PageManager::CreateNewPlayerSelectCharacterPage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}
	NewPlayerPageSelectCharacter* newPage = new NewPlayerPageSelectCharacter();
	currentPage = newPage;
}

void PageManager::CreateNewPlayerGameStartPage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}
	NewPlayerPageGameStart* newPage = new NewPlayerPageGameStart();
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

void PageManager::CreatePlayerInfo01Page()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}

	PlayerInfoPage01* newPage = new PlayerInfoPage01();
	currentPage = newPage;
}

void PageManager::CreatePlayerInfo02Page()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}

	PlayerInfoPage02* newPage = new PlayerInfoPage02();
	currentPage = newPage;
}

void PageManager::CreateMainHomeGamePage()
{
	if (gameSystem.player->getTime() >= 20)
	{
		gameSystem.player->setTime(8);
		gameSystem.player->nexyDay();
	}
	if (gameSystem.player->getTime() < 15)
	{
		if (currentPage != nullptr) {
			delete currentPage;
		}

		MainSchoolGamePage* newPage = new MainSchoolGamePage();
		currentPage = newPage;
	}
	else
	{
		if (currentPage != nullptr) {
			delete currentPage;
		}

		MainHomeGamePage* newPage = new MainHomeGamePage();
		currentPage = newPage;
	}
	
}

void PageManager::CreateMainSchoolGamePage()
{
	if (gameSystem.player->getTime() >= 20)
	{
		gameSystem.player->setTime(8);
		gameSystem.player->nexyDay();
	}
	if (gameSystem.player->getTime() < 15)
	{
		if (currentPage != nullptr) {
			delete currentPage;
		}

		MainSchoolGamePage* newPage = new MainSchoolGamePage();
		currentPage = newPage;
	}
	else
	{
		if (currentPage != nullptr) {
			delete currentPage;
		}

		MainHomeGamePage* newPage = new MainHomeGamePage();
		currentPage = newPage;
	}
}




void PageManager::CreateErrandPage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}

	ErrandPage* newPage = new ErrandPage();
	currentPage = newPage;
}

void PageManager::CreateLeisurelyPage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}

	LeisurelyPage* newPage = new LeisurelyPage();
	currentPage = newPage;
}


void PageManager::CreateSchoolQuizPage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}
	srand((unsigned int)time(NULL));
	int i = 3;
	int num = rand() % i + 1;
	switch(num)
	{
		case 1: 
		{
			SchoolKoreanQuizPage* newPage = new SchoolKoreanQuizPage();
			currentPage = newPage;
			break;
		}
		case 2:
		{
			SchoolHistoryQuizPage* newPage = new SchoolHistoryQuizPage();
			currentPage = newPage;
			break;
		}
		case 3:
		{
			SchoolEnglishQuizPage* newPage = new SchoolEnglishQuizPage();
			currentPage = newPage;
			break;
		}
		default:
		{
			SchoolKoreanQuizPage* newPage = new SchoolKoreanQuizPage();
			currentPage = newPage;
			break;
		}
			

	}

	
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

void PageManager::CreateSchoolEnglishQuizPage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}

	SchoolEnglishQuizPage* newPage = new SchoolEnglishQuizPage();
	currentPage = newPage;
}

void PageManager::CreateSchoolPTQuizPage()
{
	if (currentPage != nullptr) {
		delete currentPage;
	}

	//SchoolPTQuizPage* newPage = new SchoolPTQuizPage();
	//currentPage = newPage;
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