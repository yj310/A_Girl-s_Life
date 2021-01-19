#include "cheat.h"
#include "global.h"

Cheat::Cheat()
{

}

void Cheat::Update()
{
	
	if (inputManager.prevKeyBuffer[VK_F1] == 1
		&& inputManager.keyBuffer[VK_F1] == 0)
	{
		pageManager.CreateTitlePage();
	}
	if (inputManager.prevKeyBuffer[VK_F2] == 1
		&& inputManager.keyBuffer[VK_F2] == 0)
	{
		pageManager.CreateMainHomeGamePage();
	}
	if (inputManager.prevKeyBuffer[VK_F3] == 1
		&& inputManager.keyBuffer[VK_F3] == 0)
	{
		pageManager.CreateMainSchoolGamePage();
	}
	if (inputManager.prevKeyBuffer[VK_F4] == 1
		&& inputManager.keyBuffer[VK_F4] == 0)
	{
		pageManager.CreateSchoolScienceQuizPage();
	}
	if (inputManager.prevKeyBuffer[VK_F5] == 1
		&& inputManager.keyBuffer[VK_F5] == 0)
	{
		pageManager.CreateSchoolKoreanQuizPage();
	}
	if (inputManager.prevKeyBuffer[VK_F6] == 1
		&& inputManager.keyBuffer[VK_F6] == 0)
	{
		pageManager.CreateSchoolEnglishQuizPage();
	}
	if (inputManager.prevKeyBuffer[VK_F7] == 1
		&& inputManager.keyBuffer[VK_F7] == 0)
	{
		pageManager.CreateSchoolPTQuizPage();
	}
	
}

