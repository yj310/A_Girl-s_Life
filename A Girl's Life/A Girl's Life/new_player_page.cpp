#include "new_player_page.h"
#include "global.h"
#include <tchar.h>

#pragma warning(disable:4996)

#define BACK_BUTTON_WIDTH 320
#define BACK_BUTTON_HEIGHT 110
#define BACK_BUTTON_X 200
#define BACK_BUTTON_Y 1000
#define BACK_BUTTON_HALF_WIDTH BACK_BUTTON_WIDTH / 2
#define BACK_BUTTON_HALF_HEIGHT BACK_BUTTON_HEIGHT / 2

#define NEXT_BUTTON_WIDTH 320
#define NEXT_BUTTON_HEIGHT 110
#define NEXT_BUTTON_X 1700
#define NEXT_BUTTON_Y 1000
#define NEXT_BUTTON_HALF_WIDTH BACK_BUTTON_WIDTH / 2
#define NEXT_BUTTON_HALF_HEIGHT BACK_BUTTON_HEIGHT / 2

#define INPUT_NAME_BOX 1

#define MAX_INPUT_NAME	20

NewPlayerPage::NewPlayerPage()
{
	classType = NEW_PLAYER_PAGE;

	BackButtonState = TEX_BACK_BUTTON_NOMAL;
	NextButtonState = TEX_NEXT_BUTTON_NOMAL;

	inputState = INPUT_NAME_BOX;

	cursorCount = 0;

	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);

	int fontSize = 30;
	TCHAR g_strFont[256];
	wcscpy_s(g_strFont, 32, L"Calibri");

	int nHeight = -fontSize * nLogPixelsY / 72;
	D3DXCreateFont(g_pd3dDevice,
		nHeight,
		0,
		FW_BOLD,
		1,
		FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		g_strFont,
		&font);

	if (gameSystem.player == nullptr)
	{
		int a = 0;
		int b = 1;
	}

	if (gameSystem.player != nullptr)
	{
		int a = sizeof(gameSystem.player->getName()) / sizeof(char);
		for (int i = 0; i < a; i++)
		{
			cname.push_back(gameSystem.player->getName()[i]);
		}
	}

}

void NewPlayerPage::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);

	if (inputManager.prevKeyBuffer[VK_BACK] == 1
		&& inputManager.keyBuffer[VK_BACK] == 0)
	{
		if (cname.size() > 0)
			cname.pop_back();
	}

	for (int i = 'A'; i < 'Z'; i++)
	{
		if (inputManager.prevKeyBuffer[i] == 1
			&& inputManager.keyBuffer[i] == 0
			&& cname.size() <= MAX_INPUT_NAME)
		{
			cname.push_back((char)i);
		}
	}

	cursorCount++;
	if (cursorCount > 100)
		cursorCount = 0;

	BackButtonUpdate(pt);
	NextButtonUpdate(pt);

}


void NewPlayerPage::Render()
{
	BackgroundRender();


	NameRender();


	BackButtonRender();
	NextButtonRender();
}


/* Update */
void NewPlayerPage::BackButtonUpdate(POINT pt)
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
			pageManager.CreateTitlePage();
		}
	}
	else if (BackButtonState == TEX_BACK_BUTTON_BORD)
	{
		BackButtonState = TEX_BACK_BUTTON_NOMAL;
	}
}

void NewPlayerPage::NextButtonUpdate(POINT pt)
{
	if (pt.x > NEXT_BUTTON_X - NEXT_BUTTON_HALF_WIDTH && pt.x < NEXT_BUTTON_X + NEXT_BUTTON_HALF_WIDTH
		&& pt.y > NEXT_BUTTON_Y - NEXT_BUTTON_HALF_HEIGHT && pt.y < NEXT_BUTTON_Y + NEXT_BUTTON_HALF_HEIGHT)
	{
		if (NextButtonState == TEX_NEXT_BUTTON_NOMAL)
		{
			NextButtonState = TEX_NEXT_BUTTON_BORD;
		}

		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			char rname[128] = "";
			for (int i = 0; i < cname.size(); i++)
			{
				rname[i] = cname[i];
			}


			gameSystem.player = new Player();
			gameSystem.player->setName(rname);

			pageManager.CreateNewPlayerSelectCharacterPage();

		}
	}
	else if (NextButtonState == TEX_NEXT_BUTTON_BORD)
	{
		NextButtonState = TEX_NEXT_BUTTON_NOMAL;
	}
}






/* Render */
void NewPlayerPage::BackgroundRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(TEX_NEW_PLAYER_PAGE_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void NewPlayerPage::NameRender()
{
	RECT rc;

	wchar_t p[128] = L"";
	char rname[128] = "";
	int i = 0;
	for (i = 0; i < cname.size(); i++)
	{
		rname[i] = cname[i];
	}

	rc.left = 530;
	rc.top = 600;
	rc.right = 750;
	rc.bottom = 15;

	mbstowcs(p, rname, 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	if (cursorCount <= 50)
	{
		rname[i] = '|';
		//rname[i] = ' ';

		mbstowcs(p, rname, 128);
		font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	}
	

}

void NewPlayerPage::BackButtonRender()
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

void NewPlayerPage::NextButtonRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(NextButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = NEXT_BUTTON_WIDTH;
	rc.bottom = NEXT_BUTTON_HEIGHT;

	pos = { NEXT_BUTTON_X, NEXT_BUTTON_Y, 0 };
	cen = { NEXT_BUTTON_HALF_WIDTH, NEXT_BUTTON_HALF_HEIGHT, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}
