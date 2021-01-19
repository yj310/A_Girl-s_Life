#include "main_game_page_ui.h"
#include "global.h"
#include <tchar.h>
#pragma warning(disable:4996)

#define NAME_BAR_X 0
#define NAME_BAR_Y 0
#define NAME_BAR_WIDTH 500
#define NAME_BAR_HEIGHT 140

#define ENERGY_BAR_X 35
#define ENERGY_BAR_Y 200
#define ENERGY_BAR_WIDTH 370
#define ENERGY_BAR_HEIGHT 50

#define STRESS_BAR_X 35
#define STRESS_BAR_Y 300
#define STRESS_BAR_WIDTH 370
#define STRESS_BAR_HEIGHT 50

#define MONEY_BAR_X 35
#define MONEY_BAR_Y 400
#define MONEY_BAR_WIDTH 370
#define MONEY_BAR_HEIGHT 50

#define ACTIVITY_BUTTON_WIDTH 500
#define ACTIVITY_BUTTON_HEIGHT 150
#define ACTIVITY_BUTTON_X 1300

#define ERRAND_BUTTON_WIDTH ACTIVITY_BUTTON_WIDTH
#define ERRAND_BUTTON_HEIGHT ACTIVITY_BUTTON_HEIGHT
#define ERRAND_BUTTON_X ACTIVITY_BUTTON_X
#define ERRAND_BUtTON_Y 600

#define LEISURE_BUTTON_WIDTH ACTIVITY_BUTTON_WIDTH
#define LEISURE_BUTTON_HEIGHT ACTIVITY_BUTTON_HEIGHT
#define LEISURE_BUTTON_X ACTIVITY_BUTTON_X
#define LEISURE_BUtTON_Y 800

#define HOMEWORK_BUTTON_WIDTH ACTIVITY_BUTTON_WIDTH
#define HOMEWORK_BUTTON_HEIGHT ACTIVITY_BUTTON_HEIGHT
#define HOMEWORK_BUTTON_X ACTIVITY_BUTTON_X
#define HOMEWORK_BUtTON_Y 800

MainGamePageUI::MainGamePageUI()
{
	errandButtonState = TEX_ERRAND_BUTTON_NOMAL;
	leisureButtonState = TEX_LEISURE_BUTTON_NOMAL;
	homeworkButtonState = TEX_HOMEWORK_BUTTON_NOMAL;
	charecterTexture = TEX_CHARACTER_01;
	NameBarState = TEX_NAME_BAR;

	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);

	int fontSize = 25;
	TCHAR g_strFont[256];
	wcscpy_s(g_strFont, 32, L"�������");

	int nHeight = -fontSize * nLogPixelsY / 72;
	D3DXCreateFont(g_pd3dDevice,
		nHeight,
		0,
		FW_NORMAL,
		1,
		FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		g_strFont,
		&font);


	fontSize = 20;
	nHeight = -fontSize * nLogPixelsY / 72;
	D3DXCreateFont(g_pd3dDevice,
		nHeight,
		0,
		FW_NORMAL,
		1,
		FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		g_strFont,
		&font2);
}

void MainGamePageUI::Update()
{

	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);

	if (pt.x > ERRAND_BUTTON_X && pt.x < ERRAND_BUTTON_X + ERRAND_BUTTON_WIDTH
		&& pt.y > ERRAND_BUtTON_Y && pt.y < ERRAND_BUtTON_Y + ERRAND_BUTTON_HEIGHT)
	{
		if (errandButtonState == TEX_ERRAND_BUTTON_NOMAL)
		{
			errandButtonState = TEX_ERRAND_BUTTON_ONMOUSE;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreateErrandPage();
		}
	}
	else if (errandButtonState == TEX_ERRAND_BUTTON_ONMOUSE)
	{
		errandButtonState = TEX_ERRAND_BUTTON_NOMAL;
	}


	if (pt.x > LEISURE_BUTTON_X && pt.x < LEISURE_BUTTON_X + LEISURE_BUTTON_WIDTH
		&& pt.y > LEISURE_BUtTON_Y && pt.y < LEISURE_BUtTON_Y + LEISURE_BUTTON_HEIGHT)
	{
		if (leisureButtonState == TEX_LEISURE_BUTTON_NOMAL)
		{
			leisureButtonState = TEX_LEISURE_BUTTON_ONMOUSE;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreateLeisurelyPage();
		}
	}
	else if (leisureButtonState == TEX_LEISURE_BUTTON_ONMOUSE)
	{
		leisureButtonState = TEX_LEISURE_BUTTON_NOMAL;
	}


	if (pt.x > HOMEWORK_BUTTON_X && pt.x < HOMEWORK_BUTTON_X + HOMEWORK_BUTTON_WIDTH
		&& pt.y > HOMEWORK_BUtTON_Y && pt.y < HOMEWORK_BUtTON_Y + HOMEWORK_BUTTON_HEIGHT)
	{
		if (homeworkButtonState == TEX_HOMEWORK_BUTTON_NOMAL)
		{
			homeworkButtonState = TEX_HOMEWORK_BUTTON_ONMOUSE;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			//pageManager.CreateTitlePage();
		}
	}
	else if (homeworkButtonState == TEX_HOMEWORK_BUTTON_ONMOUSE)
	{
		homeworkButtonState = TEX_HOMEWORK_BUTTON_NOMAL;
	}


	// ���ӹ�
	if (pt.x > NAME_BAR_X&& pt.x < NAME_BAR_X + NAME_BAR_WIDTH
		&& pt.y > NAME_BAR_Y&& pt.y < NAME_BAR_Y + NAME_BAR_HEIGHT)
	{
		if (NameBarState == TEX_NAME_BAR)
		{
			NameBarState = TEX_NAME_BAR_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreatePlayerInfo01Page();
		}
	}
	else if (NameBarState == TEX_NAME_BAR_MOUSEOVER)
	{
		NameBarState = TEX_NAME_BAR;
	}

}

void MainGamePageUI::Render()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;
	WCHAR text[256];
	wchar_t p[128] = L"";
	setlocale(LC_ALL, "Korean");

	element = textureManager.getTexture(TEX_MAIN_HOME_GAME_PAGE_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = 100;
	pos = { 0, 0, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(20, 0, 0, 0));
	element->sprite->End();


	element = textureManager.getTexture(NameBarState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = NAME_BAR_WIDTH;
	rc.bottom = NAME_BAR_HEIGHT;
	pos = { NAME_BAR_X, NAME_BAR_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();



	rc.left = 70;
	rc.top = 45;
	rc.right = 1000;
	rc.bottom = 10;

	mbstowcs(p, gameSystem.player->getName(), 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	rc.left = 300;
	_stprintf_s<256>(text, _T("%d����"), gameSystem.player->getDays());
	font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));






	element = textureManager.getTexture(TEX_TIME_STATE_BAR);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = 350;
	rc.bottom = 110;
	pos = { WINDOW_WIDTH/2, 145, 0 };
	cen = { 350 / 2, 110 / 2, 0 };
	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();


	rc.left = WINDOW_WIDTH / 2 - 60;
	rc.top = 110;
	rc.right = WINDOW_WIDTH / 2 + 60;
	rc.bottom = 200;

	switch (gameSystem.player->getDays() % 5)
	{
	case 1:
		_stprintf_s<256>(text, _T("������"));
		break;
	case 2:
		_stprintf_s<256>(text, _T("ȭ����"));
		break;
	case 3:
		_stprintf_s<256>(text, _T("������"));
		break;
	case 4:
		_stprintf_s<256>(text, _T("�����"));
		break;
	case 0:
		_stprintf_s<256>(text, _T("�ݿ���"));
		break;
	}
	font2->DrawText(NULL, text, -1, &rc, DT_CENTER,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));


	rc.top = 150;
	rc.bottom = 250;

	_stprintf_s<256>(text, _T("%02d:00"), gameSystem.player->getTime());
	font->DrawText(NULL, text, -1, &rc, DT_CENTER,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));











	element = textureManager.getTexture(TEX_STATE_BAR);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = 450;
	rc.bottom = 370;
	pos = { 0, 140, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();


	element = textureManager.getTexture(TEX_ENERGY_BAR_EMPTY);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = ENERGY_BAR_WIDTH;
	rc.bottom = ENERGY_BAR_HEIGHT;
	pos = { ENERGY_BAR_X, ENERGY_BAR_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

	element = textureManager.getTexture(TEX_ENERGY_BAR_FULL);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.right = (int)(50 + ((ENERGY_BAR_WIDTH - 50) / 100.0 * gameSystem.player->getEnergy()));
	rc.bottom = ENERGY_BAR_HEIGHT;
	pos = { ENERGY_BAR_X, ENERGY_BAR_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();



	element = textureManager.getTexture(TEX_STRESS_BAR_EMPTY);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = STRESS_BAR_WIDTH;
	rc.bottom = STRESS_BAR_HEIGHT;
	pos = { STRESS_BAR_X, STRESS_BAR_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

	element = textureManager.getTexture(TEX_STRESS_BAR_FULL);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.right = (int)(50 + ((STRESS_BAR_WIDTH - 50) / 100.0 * gameSystem.player->getStress()));
	rc.bottom = ENERGY_BAR_HEIGHT;
	pos = { STRESS_BAR_X, STRESS_BAR_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

	

	element = textureManager.getTexture(TEX_MONEY_BAR);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = MONEY_BAR_WIDTH;
	rc.bottom = MONEY_BAR_HEIGHT;
	pos = { MONEY_BAR_X, MONEY_BAR_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

	rc.left = MONEY_BAR_X;
	rc.top = MONEY_BAR_Y+10;
	rc.right = MONEY_BAR_X + MONEY_BAR_WIDTH-10;
	rc.bottom = MONEY_BAR_Y + MONEY_BAR_HEIGHT;
	_stprintf_s<256>(text, _T("%d��"), gameSystem.player->getMoney());
	font2->DrawText(NULL, text, -1, &rc, DT_RIGHT,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));








	switch(gameSystem.player->getCharacter())
	{
	case 1: charecterTexture = TEX_CHARACTER_01; break;
	case 2: charecterTexture = TEX_CHARACTER_02; break;
	case 3: charecterTexture = TEX_CHARACTER_03; break;
	case 4: charecterTexture = TEX_CHARACTER_04; break;
	case 5: charecterTexture = TEX_CHARACTER_05; break;
	case 6: charecterTexture = TEX_CHARACTER_06; break;

	}
	element = textureManager.getTexture(charecterTexture);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = 800;
	rc.bottom = 800;
	pos = { WINDOW_WIDTH / 2, 280, 0 };
	cen = { 400, 0, 0 };
	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();







	element = textureManager.getTexture(errandButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = ERRAND_BUTTON_WIDTH;
	rc.bottom = ERRAND_BUTTON_HEIGHT;
	pos = { ERRAND_BUTTON_X, ERRAND_BUtTON_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

	element = textureManager.getTexture(leisureButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = LEISURE_BUTTON_WIDTH;
	rc.bottom = LEISURE_BUTTON_HEIGHT;
	pos = { LEISURE_BUTTON_X, LEISURE_BUtTON_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();
	/*
	element = textureManager.getTexture(homeworkButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = HOMEWORK_BUTTON_WIDTH;
	rc.bottom = HOMEWORK_BUTTON_HEIGHT;
	pos = { HOMEWORK_BUTTON_X, HOMEWORK_BUtTON_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();*/

}