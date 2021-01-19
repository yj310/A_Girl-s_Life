#include "new_player_page_select_character.h"
#include "global.h"
#include <tchar.h>

#pragma warning(disable:4996)

#define BACK_BUTTON_WIDTH 320
#define BACK_BUTTON_HEIGHT 110
#define BACK_BUTTON_X 200
#define BACK_BUTTON_Y 1000
#define BACK_BUTTON_HALF_WIDTH BACK_BUTTON_WIDTH / 2
#define BACK_BUTTON_HALF_HEIGHT BACK_BUTTON_HEIGHT / 2

#define SELECT_CHARACTER_BUTTON_WIDTH 250
#define SELECT_CHARACTER_BUTTON_HEIGHT 200

#define SELECT_CHARACTER_BUTTON_01_X WINDOW_WIDTH/2 - 400
#define SELECT_CHARACTER_BUTTON_01_Y 450

#define SELECT_CHARACTER_BUTTON_02_X WINDOW_WIDTH/2
#define SELECT_CHARACTER_BUTTON_02_Y 450

#define SELECT_CHARACTER_BUTTON_03_X WINDOW_WIDTH/2 + 400
#define SELECT_CHARACTER_BUTTON_03_Y 450

#define SELECT_CHARACTER_BUTTON_04_X WINDOW_WIDTH/2 - 400
#define SELECT_CHARACTER_BUTTON_04_Y 700

#define SELECT_CHARACTER_BUTTON_05_X WINDOW_WIDTH/2
#define SELECT_CHARACTER_BUTTON_05_Y 700

#define SELECT_CHARACTER_BUTTON_06_X WINDOW_WIDTH/2 + 400
#define SELECT_CHARACTER_BUTTON_06_Y 700


NewPlayerPageSelectCharacter::NewPlayerPageSelectCharacter()
{
	classType = NEW_PLAYER_PAGE_SELECT_CHARACTER;

	BackButtonState = TEX_BACK_BUTTON_NOMAL;

	CharacterButtonState01 = TEX_SELECT_CHARACTER_01;
	CharacterButtonState02 = TEX_SELECT_CHARACTER_02;
	CharacterButtonState03 = TEX_SELECT_CHARACTER_03;
	CharacterButtonState04 = TEX_SELECT_CHARACTER_04;
	CharacterButtonState05 = TEX_SELECT_CHARACTER_05;
	CharacterButtonState06 = TEX_SELECT_CHARACTER_06;
}

void NewPlayerPageSelectCharacter::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);

	CharacterButtonUpdate(pt);
	BackButtonUpdate(pt);

}


void NewPlayerPageSelectCharacter::Render()
{
	BackgroundRender();
	CharacterButtonRender();
	BackButtonRender();
}


/* Update */
void NewPlayerPageSelectCharacter::BackButtonUpdate(POINT pt)
{
	if (pt.x > BACK_BUTTON_X - BACK_BUTTON_HALF_WIDTH && pt.x < BACK_BUTTON_X + BACK_BUTTON_HALF_WIDTH
		&& pt.y > BACK_BUTTON_Y - BACK_BUTTON_HALF_HEIGHT && pt.y < BACK_BUTTON_Y + BACK_BUTTON_HALF_HEIGHT)
	{
		if (BackButtonState == TEX_BACK_BUTTON_NOMAL)
		{
			BackButtonState = TEX_BACK_BUTTON_BORD;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreateNewPlayerPage();
		}
	}
	else if (BackButtonState == TEX_BACK_BUTTON_BORD)
	{
		BackButtonState = TEX_BACK_BUTTON_NOMAL;
	}
}

void NewPlayerPageSelectCharacter::CharacterButtonUpdate(POINT pt)
{
	//01
	if (pt.x > SELECT_CHARACTER_BUTTON_01_X - (SELECT_CHARACTER_BUTTON_WIDTH / 2) && pt.x < SELECT_CHARACTER_BUTTON_01_X + (SELECT_CHARACTER_BUTTON_WIDTH / 2)
		&& pt.y > SELECT_CHARACTER_BUTTON_01_Y - (SELECT_CHARACTER_BUTTON_HEIGHT / 2) && pt.y < SELECT_CHARACTER_BUTTON_01_Y + (SELECT_CHARACTER_BUTTON_HEIGHT / 2))
	{
		if (CharacterButtonState01 == TEX_SELECT_CHARACTER_01)
		{
			CharacterButtonState01 = TEX_SELECT_CHARACTER_01_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			gameSystem.player->setCharacter(1);
			pageManager.CreateNewPlayerGameStartPage();


		}
	}
	else if (CharacterButtonState01 == TEX_SELECT_CHARACTER_01_MOUSEOVER)
	{
		CharacterButtonState01 = TEX_SELECT_CHARACTER_01;
	}

	//02
	if (pt.x > SELECT_CHARACTER_BUTTON_02_X - (SELECT_CHARACTER_BUTTON_WIDTH / 2) && pt.x < SELECT_CHARACTER_BUTTON_02_X + (SELECT_CHARACTER_BUTTON_WIDTH / 2)
		&& pt.y > SELECT_CHARACTER_BUTTON_02_Y - (SELECT_CHARACTER_BUTTON_HEIGHT / 2) && pt.y < SELECT_CHARACTER_BUTTON_02_Y + (SELECT_CHARACTER_BUTTON_HEIGHT / 2))
	{
		if (CharacterButtonState02 == TEX_SELECT_CHARACTER_02)
		{
			CharacterButtonState02 = TEX_SELECT_CHARACTER_02_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{

			gameSystem.player->setCharacter(2);
			pageManager.CreateNewPlayerGameStartPage();

		}
	}
	else if (CharacterButtonState02 == TEX_SELECT_CHARACTER_02_MOUSEOVER)
	{
		CharacterButtonState02 = TEX_SELECT_CHARACTER_02;
	}

	//03
	if (pt.x > SELECT_CHARACTER_BUTTON_03_X - (SELECT_CHARACTER_BUTTON_WIDTH / 2) && pt.x < SELECT_CHARACTER_BUTTON_03_X + (SELECT_CHARACTER_BUTTON_WIDTH / 2)
		&& pt.y > SELECT_CHARACTER_BUTTON_03_Y - (SELECT_CHARACTER_BUTTON_HEIGHT / 2) && pt.y < SELECT_CHARACTER_BUTTON_03_Y + (SELECT_CHARACTER_BUTTON_HEIGHT / 2))
	{
		if (CharacterButtonState03 == TEX_SELECT_CHARACTER_03)
		{
			CharacterButtonState03 = TEX_SELECT_CHARACTER_03_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			gameSystem.player->setCharacter(3);
			pageManager.CreateNewPlayerGameStartPage();

		}
	}
	else if (CharacterButtonState03 == TEX_SELECT_CHARACTER_03_MOUSEOVER)
	{
		CharacterButtonState03 = TEX_SELECT_CHARACTER_03;
	}

	//04
	if (pt.x > SELECT_CHARACTER_BUTTON_04_X - (SELECT_CHARACTER_BUTTON_WIDTH / 2) && pt.x < SELECT_CHARACTER_BUTTON_04_X + (SELECT_CHARACTER_BUTTON_WIDTH / 2)
		&& pt.y > SELECT_CHARACTER_BUTTON_04_Y - (SELECT_CHARACTER_BUTTON_HEIGHT / 2) && pt.y < SELECT_CHARACTER_BUTTON_04_Y + (SELECT_CHARACTER_BUTTON_HEIGHT / 2))
	{
		if (CharacterButtonState04 == TEX_SELECT_CHARACTER_04)
		{
			CharacterButtonState04 = TEX_SELECT_CHARACTER_04_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			gameSystem.player->setCharacter(4);
			pageManager.CreateNewPlayerGameStartPage();

		}
	}
	else if (CharacterButtonState04 == TEX_SELECT_CHARACTER_04_MOUSEOVER)
	{
		CharacterButtonState04 = TEX_SELECT_CHARACTER_04;
	}

	//05
	if (pt.x > SELECT_CHARACTER_BUTTON_05_X - (SELECT_CHARACTER_BUTTON_WIDTH / 2) && pt.x < SELECT_CHARACTER_BUTTON_05_X + (SELECT_CHARACTER_BUTTON_WIDTH / 2)
		&& pt.y > SELECT_CHARACTER_BUTTON_05_Y - (SELECT_CHARACTER_BUTTON_HEIGHT / 2) && pt.y < SELECT_CHARACTER_BUTTON_05_Y + (SELECT_CHARACTER_BUTTON_HEIGHT / 2))
	{
		if (CharacterButtonState05 == TEX_SELECT_CHARACTER_05)
		{
			CharacterButtonState05 = TEX_SELECT_CHARACTER_05_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			gameSystem.player->setCharacter(5);
			pageManager.CreateNewPlayerGameStartPage();

		}
	}
	else if (CharacterButtonState05 == TEX_SELECT_CHARACTER_05_MOUSEOVER)
	{
		CharacterButtonState05 = TEX_SELECT_CHARACTER_05;
	}

	//06
	if (pt.x > SELECT_CHARACTER_BUTTON_06_X - (SELECT_CHARACTER_BUTTON_WIDTH / 2) && pt.x < SELECT_CHARACTER_BUTTON_06_X + (SELECT_CHARACTER_BUTTON_WIDTH / 2)
		&& pt.y > SELECT_CHARACTER_BUTTON_06_Y - (SELECT_CHARACTER_BUTTON_HEIGHT / 2) && pt.y < SELECT_CHARACTER_BUTTON_06_Y + (SELECT_CHARACTER_BUTTON_HEIGHT / 2))
	{
		if (CharacterButtonState06 == TEX_SELECT_CHARACTER_06)
		{
			CharacterButtonState06 = TEX_SELECT_CHARACTER_06_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			gameSystem.player->setCharacter(6);
			pageManager.CreateNewPlayerGameStartPage();

		}
	}
	else if (CharacterButtonState06 == TEX_SELECT_CHARACTER_06_MOUSEOVER)
	{
		CharacterButtonState06 = TEX_SELECT_CHARACTER_06;
	}



}



/* Render */
void NewPlayerPageSelectCharacter::BackgroundRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(TEX_NEW_PLAYER_SELECT_CHARACTER_PAGE_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void NewPlayerPageSelectCharacter::CharacterButtonRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(CharacterButtonState01);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = SELECT_CHARACTER_BUTTON_WIDTH;
	rc.bottom = SELECT_CHARACTER_BUTTON_HEIGHT;

	pos = { SELECT_CHARACTER_BUTTON_01_X, SELECT_CHARACTER_BUTTON_01_Y, 0 };
	cen = { SELECT_CHARACTER_BUTTON_WIDTH / 2, SELECT_CHARACTER_BUTTON_HEIGHT / 2, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();



	element = textureManager.getTexture(CharacterButtonState02);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	pos = { SELECT_CHARACTER_BUTTON_02_X, SELECT_CHARACTER_BUTTON_02_Y, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();



	element = textureManager.getTexture(CharacterButtonState03);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	pos = { SELECT_CHARACTER_BUTTON_03_X, SELECT_CHARACTER_BUTTON_03_Y, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();



	element = textureManager.getTexture(CharacterButtonState04);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	pos = { SELECT_CHARACTER_BUTTON_04_X, SELECT_CHARACTER_BUTTON_04_Y, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();



	element = textureManager.getTexture(CharacterButtonState05);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	pos = { SELECT_CHARACTER_BUTTON_05_X, SELECT_CHARACTER_BUTTON_05_Y, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();



	element = textureManager.getTexture(CharacterButtonState06);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	pos = { SELECT_CHARACTER_BUTTON_06_X, SELECT_CHARACTER_BUTTON_06_Y, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();


}

void NewPlayerPageSelectCharacter::BackButtonRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(BackButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = BACK_BUTTON_WIDTH;
	rc.bottom = BACK_BUTTON_HEIGHT;

	pos = { BACK_BUTTON_X, BACK_BUTTON_Y, 0 };
	cen = { BACK_BUTTON_HALF_WIDTH, BACK_BUTTON_HALF_HEIGHT, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}
