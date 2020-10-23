#include "main_game_page_ui.h"
#include "global.h"
#include <tchar.h>
#pragma warning(disable:4996)

#define ENERGY_BAR_WIDTH 370
#define ENERGY_BAR_HEIGHT 50

#define ACTIVITY_BUTTON_WIDTH 500
#define ACTIVITY_BUTTON_HEIGHT 150
#define ACTIVITY_BUTTON_X 1300

#define ERRAND_BUTTON_WIDTH ACTIVITY_BUTTON_WIDTH
#define ERRAND_BUTTON_HEIGHT ACTIVITY_BUTTON_HEIGHT
#define ERRAND_BUTTON_X ACTIVITY_BUTTON_X
#define ERRAND_BUtTON_Y 400

#define LEISURE_BUTTON_WIDTH ACTIVITY_BUTTON_WIDTH
#define LEISURE_BUTTON_HEIGHT ACTIVITY_BUTTON_HEIGHT
#define LEISURE_BUTTON_X ACTIVITY_BUTTON_X
#define LEISURE_BUtTON_Y 600

#define HOMEWORK_BUTTON_WIDTH ACTIVITY_BUTTON_WIDTH
#define HOMEWORK_BUTTON_HEIGHT ACTIVITY_BUTTON_HEIGHT
#define HOMEWORK_BUTTON_X ACTIVITY_BUTTON_X
#define HOMEWORK_BUtTON_Y 800

MainGamePageUI::MainGamePageUI()
{
	errandButtonState = TEX_ERRAND_BUTTON_NOMAL;
	leisureButtonState = TEX_LEISURE_BUTTON_NOMAL;
	homeworkButtonState = TEX_HOMEWORK_BUTTON_NOMAL;

	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);

	int fontSize = 30;
	TCHAR g_strFont[256];
	wcscpy_s(g_strFont, 32, L"±¼¸²");

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
			//pageManager.CreateTitlePage();
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
			//pageManager.CreateTitlePage();
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


	element = textureManager.getTexture(TEX_NAME_BAR);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = 500;
	rc.bottom = 140;
	pos = { 100, 20, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();



	element = textureManager.getTexture(TEX_CLOCK);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = 200;
	rc.bottom = 200;
	pos = { 20, 20, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();


	

	rc.left = 400;
	rc.top = 40;
	rc.right = 1000;
	rc.bottom = 10;

	mbstowcs(p, gameSystem.player->getName(), 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	rc.top = 100;
	rc.left = 350;
	_stprintf_s<256>(text, _T("%d"), gameSystem.player->getDays());
	font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	rc.left = 450;
	_stprintf_s<256>(text, _T("ÀÏÂ÷"));
	font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));




	



	element = textureManager.getTexture(TEX_ENERGY_BAR_EMPTY);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = ENERGY_BAR_WIDTH;
	rc.bottom = ENERGY_BAR_HEIGHT;
	pos = { 680, 20, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

	element = textureManager.getTexture(TEX_ENERGY_BAR_FULL);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.right = 50 + ((ENERGY_BAR_WIDTH - 50) / 100 * gameSystem.player->getEnergy());
	rc.bottom = ENERGY_BAR_HEIGHT;
	pos = { 680, 20, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();



	element = textureManager.getTexture(TEX_STRESS_BAR_EMPTY);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = ENERGY_BAR_WIDTH;
	rc.bottom = ENERGY_BAR_HEIGHT;
	pos = { 1080, 20, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

	element = textureManager.getTexture(TEX_STRESS_BAR_FULL);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.right = 50 + ((ENERGY_BAR_WIDTH - 50) / 100 * gameSystem.player->getStress());
	rc.bottom = ENERGY_BAR_HEIGHT;
	pos = { 1080, 20, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

	

	element = textureManager.getTexture(TEX_MONEY_BAR);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = ENERGY_BAR_WIDTH;
	rc.bottom = ENERGY_BAR_HEIGHT;
	pos = { 1480, 20, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();



	element = textureManager.getTexture(TEX_GIRL_YOUN);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = 800;
	rc.bottom = 800;
	pos = { WINDOW_WIDTH / 2, 280, 0 };
	cen = { 400, 0, 0 };
	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();


	rc.top = 20;
	rc.left = 1680;
	_stprintf_s<256>(text, _T("%d"), gameSystem.player->getMoney());
	font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));








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

	element = textureManager.getTexture(homeworkButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = HOMEWORK_BUTTON_WIDTH;
	rc.bottom = HOMEWORK_BUTTON_HEIGHT;
	pos = { HOMEWORK_BUTTON_X, HOMEWORK_BUtTON_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();

}