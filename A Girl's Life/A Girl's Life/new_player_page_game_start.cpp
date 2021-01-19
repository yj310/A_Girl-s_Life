#include "new_player_page_game_start.h"
#include "global.h"
#include <tchar.h>

#pragma warning(disable:4996)

#define BACK_BUTTON_WIDTH 320
#define BACK_BUTTON_HEIGHT 110
#define BACK_BUTTON_X 200
#define BACK_BUTTON_Y 1000
#define BACK_BUTTON_HALF_WIDTH BACK_BUTTON_WIDTH / 2
#define BACK_BUTTON_HALF_HEIGHT BACK_BUTTON_HEIGHT / 2

#define YES_BUTTON_WIDTH 320
#define YES_BUTTON_HEIGHT 110
#define YES_BUTTON_X WINDOW_WIDTH/2 + 200
#define YES_BUTTON_Y 600
#define YES_BUTTON_HALF_WIDTH YES_BUTTON_WIDTH / 2
#define YES_BUTTON_HALF_HEIGHT YES_BUTTON_HEIGHT / 2

#define NO_BUTTON_WIDTH 320
#define NO_BUTTON_HEIGHT 110
#define NO_BUTTON_X WINDOW_WIDTH/2 - 200
#define NO_BUTTON_Y 600
#define NO_BUTTON_HALF_WIDTH NO_BUTTON_WIDTH / 2
#define NO_BUTTON_HALF_HEIGHT NO_BUTTON_HEIGHT / 2


NewPlayerPageGameStart::NewPlayerPageGameStart()
{
	classType = NEW_PLAYER_PAGE;

	BackButtonState = TEX_BACK_BUTTON_NOMAL;
	NoButtonState = TEX_NO_BUTTON_NOMAL;
	YesButtonState = TEX_YES_BUTTON_NOMAL;

}

void NewPlayerPageGameStart::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);

	BackButtonUpdate(pt);
	YesButtonUpdate(pt);
	NoButtonUpdate(pt);

}


void NewPlayerPageGameStart::Render()
{
	BackgroundRender();


	BackButtonRender();
	YesButtonRender();
	NoButtonRender();
}


/* Update */
void NewPlayerPageGameStart::BackButtonUpdate(POINT pt)
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
			pageManager.CreateNewPlayerSelectCharacterPage();
		}
	}
	else if (BackButtonState == TEX_BACK_BUTTON_BORD)
	{
		BackButtonState = TEX_BACK_BUTTON_NOMAL;
	}
}

void NewPlayerPageGameStart::YesButtonUpdate(POINT pt)
{
	if (pt.x > YES_BUTTON_X - YES_BUTTON_HALF_WIDTH && pt.x < YES_BUTTON_X + YES_BUTTON_HALF_WIDTH
		&& pt.y > YES_BUTTON_Y - YES_BUTTON_HALF_HEIGHT && pt.y < YES_BUTTON_Y + YES_BUTTON_HALF_HEIGHT)
	{
		if (YesButtonState == TEX_YES_BUTTON_NOMAL)
		{
			YesButtonState = TEX_YES_BUTTON_BORD;
		}

		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{

			PlayerInfo* playerInfo = dataManager.AddPlayer(gameSystem.player->getName(), gameSystem.player->getCharacter());

			Player player = dataManager.LoadPlayerData(playerInfo);
			gameSystem.player = new Player(player);

			pageManager.CreateMainHomeGamePage();

		}
	}
	else if (YesButtonState == TEX_YES_BUTTON_BORD)
	{
		YesButtonState = TEX_YES_BUTTON_NOMAL;
	}
}

void NewPlayerPageGameStart::NoButtonUpdate(POINT pt)
{
	if (pt.x > NO_BUTTON_X - NO_BUTTON_HALF_WIDTH && pt.x < NO_BUTTON_X + NO_BUTTON_HALF_WIDTH
		&& pt.y > NO_BUTTON_Y - NO_BUTTON_HALF_HEIGHT && pt.y < NO_BUTTON_Y + NO_BUTTON_HALF_HEIGHT)
	{
		if (NoButtonState == TEX_NO_BUTTON_NOMAL)
		{
			NoButtonState = TEX_NO_BUTTON_BORD;
		}

		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreateTitlePage();

		}
	}
	else if (NoButtonState == TEX_NO_BUTTON_BORD)
	{
		NoButtonState = TEX_NO_BUTTON_NOMAL;
	}
}






/* Render */
void NewPlayerPageGameStart::BackgroundRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(TEX_NEW_PLAYER_GAME_START_PAGE_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void NewPlayerPageGameStart::BackButtonRender()
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

void NewPlayerPageGameStart::YesButtonRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(YesButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = YES_BUTTON_WIDTH;
	rc.bottom = YES_BUTTON_HEIGHT;

	pos = { YES_BUTTON_X, YES_BUTTON_Y, 0 };
	cen = { YES_BUTTON_HALF_WIDTH, YES_BUTTON_HALF_HEIGHT, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void NewPlayerPageGameStart::NoButtonRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(NoButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = NO_BUTTON_WIDTH;
	rc.bottom = NO_BUTTON_HEIGHT;

	pos = { NO_BUTTON_X, NO_BUTTON_Y, 0 };
	cen = { NO_BUTTON_HALF_WIDTH, NO_BUTTON_HALF_HEIGHT, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}
