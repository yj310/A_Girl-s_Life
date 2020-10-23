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
	
}

