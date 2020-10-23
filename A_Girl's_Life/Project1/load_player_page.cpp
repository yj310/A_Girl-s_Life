#include "load_player_page.h"
#include "global.h"
#include <tchar.h>
#include <string>
#include <fstream>

#pragma warning(disable:4996)

#define BACK_BUTTON_WIDTH 320
#define BACK_BUTTON_HEIGHT 110
#define BACK_BUTTON_X 1700
#define BACK_BUTTON_Y 1000
#define BACK_BUTTON_HALF_WIDTH BACK_BUTTON_WIDTH / 2
#define BACK_BUTTON_HALF_HEIGHT BACK_BUTTON_HEIGHT / 2

#define SELECT_DATA_PANEL_X 200
#define SELECT_DATA_PANEL_Y 350
#define SELECT_DATA_PANEL_WIDTH 1520
#define SELECT_DATA_PANEL_HEIGHT 500

LoadPlayerPage::LoadPlayerPage()
{
	classType = LOAD_PLAYER_PAGE;
	BackButtonState = TEX_BACK_BUTTON_NOMAL;
	for (int i = 0; i < 5; i++) { DataButtonState[i] = 0; }

	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);

	int fontSize = 30;
	TCHAR g_strFont[256];
	wcscpy_s(g_strFont, 32, L"둥근모꼴");

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

	dataManager.LoadPlayersData();


}

void LoadPlayerPage::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);

	ClickDataUpdate(pt);
	BackButtonUpdate(pt);
	ScrolUpdate();

}

void LoadPlayerPage::Render()
{
	/*TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;


	element = textureManager.getTexture(TEX_LOAD_GAME_PAGE_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0; rc.top = 0; rc.right = WINDOW_WIDTH; rc.bottom = WINDOW_HEIGHT;
	pos = { 0, 0, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();*/

	DatasRender();
	BackgroundRender();
	BackButtonRender();

}


/* Update */
void LoadPlayerPage::BackButtonUpdate(POINT pt)
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

void LoadPlayerPage::ScrolUpdate()
{
	if (inputManager.mouseWheel <= -1 && (dataManager.playerInfos.size() + scrol - 1) * 100 >= 500)
	{	// 스크롤 내리기 내려가기
		scrol -= 1;
	}
	else if (inputManager.mouseWheel >= 1 && scrol <= -1)
	{	// 스크롤 올리기 위로 올라가기
		scrol += 1;
	}
}

void LoadPlayerPage::ClickDataUpdate(POINT pt)
{

	if (pt.x > SELECT_DATA_PANEL_X && pt.x < SELECT_DATA_PANEL_X + SELECT_DATA_PANEL_WIDTH
		&& pt.y > SELECT_DATA_PANEL_Y && pt.y < SELECT_DATA_PANEL_Y + SELECT_DATA_PANEL_HEIGHT)
	{
		for (int i = 0; i < dataManager.playerInfos.size(); i++)
		{
			if (pt.y > SELECT_DATA_PANEL_Y + ((i + scrol) * 100) && pt.y < SELECT_DATA_PANEL_Y + ((i + scrol + 1) * 100))
			{
				if (DataButtonState[i] == 0)
				{
					DataButtonState[i] = 1;
				}


				if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
					&& inputManager.keyBuffer[VK_LBUTTON] == 0)
				{
					Player player = dataManager.LoadPlayerData(dataManager.playerInfos[i]);
					gameSystem.player = new Player(player);
					pageManager.CreateMainHomeGamePage();
				}
			}
			else if (DataButtonState[i] == 1)
			{
				DataButtonState[i] = 0;
			}
		}



	}
	else
	{
		for (int i = 0; i < dataManager.playerInfos.size(); i++)
		{
			if (DataButtonState[i] == 1)
			{
			DataButtonState[i] = 0;
			}
		}
	}
	
}



/* Render */
void LoadPlayerPage::BackgroundRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(TEX_LOAD_PLAYER_PAGE_BACKGROUND);

	// 좌
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0; rc.top = 0; rc.right = SELECT_DATA_PANEL_X; rc.bottom = WINDOW_HEIGHT;
	pos = { 0, 0, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

	// 우
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = SELECT_DATA_PANEL_X + SELECT_DATA_PANEL_WIDTH;
	rc.top = 0; rc.right = WINDOW_WIDTH; rc.bottom = WINDOW_HEIGHT;
	pos = { SELECT_DATA_PANEL_X + SELECT_DATA_PANEL_WIDTH, 0, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

	// 상
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0; rc.top = 0; rc.right = WINDOW_WIDTH; rc.bottom = SELECT_DATA_PANEL_Y;
	pos = { 0, 0, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

	// 하
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0; rc.top = SELECT_DATA_PANEL_Y + SELECT_DATA_PANEL_HEIGHT; rc.right = WINDOW_WIDTH; rc.bottom = WINDOW_HEIGHT;
	pos = { 0, SELECT_DATA_PANEL_Y + SELECT_DATA_PANEL_HEIGHT, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();


}

void LoadPlayerPage::DatasRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;
	WCHAR text[256];
	wchar_t p[128] = L"";
	setlocale(LC_ALL, "Korean");

	for (int i = 0; i < dataManager.playerInfos.size(); i++)
	{
		// 버튼
		element = textureManager.getTexture(TEX_CHARECTER_SELETE_BUTTON_UP);
		element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
		rc.top = 0;	rc.left = 0; rc.right = 1520; rc.bottom = 100;
		pos = { 200, float(350 + (100 * i) + (scrol * 100)), 0 };
		element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
		element->sprite->End();

		// 글씨
		rc.left = 200;
		rc.top = 350 + 100 * i + scrol * 100;
		rc.right = 700;
		rc.bottom = 700;

		mbstowcs(p, dataManager.playerInfos[i]->name, 128);
		font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));

		rc.left = 500;
		_stprintf_s<256>(text, _T("%d 일차"), dataManager.playerInfos[i]->days);
		font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));

		if (DataButtonState[i] == 1)
		{
			element = textureManager.getTexture(TEX_CHARECTER_SELETE_BUTTON_UP);
			element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
			rc.top = 0;	rc.left = 0; rc.right = 1520; rc.bottom = 100;
			pos = { 200, float(350 + (100 * i) + (scrol * 100)), 0 };
			element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(100, 255, 255, 255));
			element->sprite->End();
		}
		


	}
}

void LoadPlayerPage::BackButtonRender()
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