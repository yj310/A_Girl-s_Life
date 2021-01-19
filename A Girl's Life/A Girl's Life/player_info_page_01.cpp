#include "player_info_page_01.h"
#include "global.h"
#include <tchar.h>
#pragma warning(disable:4996)

#define BACK_BUTTON_WIDTH 320
#define BACK_BUTTON_HEIGHT 110
#define BACK_BUTTON_X 280
#define BACK_BUTTON_Y 1000
#define BACK_BUTTON_HALF_WIDTH BACK_BUTTON_WIDTH / 2
#define BACK_BUTTON_HALF_HEIGHT BACK_BUTTON_HEIGHT / 2

#define NEXT_BUTTON_WIDTH 50
#define NEXT_BUTTON_HEIGHT 50
#define NEXT_BUTTON_X 1700
#define NEXT_BUTTON_Y 800
#define NEXT_BUTTON_HALF_WIDTH NEXT_BUTTON_WIDTH / 2
#define NEXT_BUTTON_HALF_HEIGHT NEXT_BUTTON_HEIGHT / 2

#define EXIT_BUTTON_WIDTH 320
#define EXIT_BUTTON_HEIGHT 110
#define EXIT_BUTTON_X WINDOW_WIDTH-280
#define EXIT_BUTTON_Y 1000
#define EXIT_BUTTON_HALF_WIDTH BACK_BUTTON_WIDTH / 2
#define EXIT_BUTTON_HALF_HEIGHT BACK_BUTTON_HEIGHT / 2

#define REQUESTION_BOX_WIDTH 850
#define REQUESTION_BOX_HEIGHT 350
#define REQUESTION_BOX_X  WINDOW_WIDTH/2
#define REQUESTION_BOX_Y WINDOW_HEIGHT/2

#define YES_BUTTON_WIDTH 320
#define YES_BUTTON_HEIGHT 110
#define YES_BUTTON_X  WINDOW_WIDTH/2-200
#define YES_BUTTON_Y WINDOW_HEIGHT/2+100

#define NO_BUTTON_WIDTH 320
#define NO_BUTTON_HEIGHT 110
#define NO_BUTTON_X  WINDOW_WIDTH/2+200
#define NO_BUTTON_Y WINDOW_HEIGHT/2+100



PlayerInfoPage01::PlayerInfoPage01()
{
	classType = 0;
	BackButtonState = TEX_BACK_BUTTON_NOMAL;
	NextButtonState = TEX_NEXT_BUTTON2_NOMAL;
	ExitButtonState = TEX_EXIT_BUTTON_NOMAL;

	YesButtonState = TEX_YES_BUTTON_NOMAL;
	NoButtonState = TEX_NO_BUTTON_NOMAL;

	popup = 0;


	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);

	int fontSize = 20;
	TCHAR g_strFont[256];
	wcscpy_s(g_strFont, 32, L"맑은고딕");

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


}

void PlayerInfoPage01::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);

	if (popup == 1)
	{
		DoExitUpdate(pt);
	}
	else
	{
		BackButtonUpdate(pt);
		NextButtonUpdate(pt);
		ExitButtonUpdate(pt);
	}

}

void PlayerInfoPage01::Render()
{

	BackgroundRender();
	dataRender();
	BackButtonRender();
	NextButtonRender();
	ExitButtonRender();
	if (popup == 1)
	{
		DoExitRender();
	}

}


/* Update */
void PlayerInfoPage01::BackButtonUpdate(POINT pt)
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
			pageManager.CreateMainHomeGamePage();
		}
	}
	else if (BackButtonState == TEX_BACK_BUTTON_BORD)
	{
		BackButtonState = TEX_BACK_BUTTON_NOMAL;
	}
}

void PlayerInfoPage01::NextButtonUpdate(POINT pt)
{
	if (pt.x > NEXT_BUTTON_X - NEXT_BUTTON_HALF_WIDTH && pt.x < NEXT_BUTTON_X + NEXT_BUTTON_HALF_WIDTH
		&& pt.y > NEXT_BUTTON_Y - NEXT_BUTTON_HALF_HEIGHT && pt.y < NEXT_BUTTON_Y + NEXT_BUTTON_HALF_HEIGHT)
	{
		if (NextButtonState == TEX_NEXT_BUTTON2_NOMAL)
		{
			NextButtonState = TEX_NEXT_BUTTON2_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreatePlayerInfo02Page();
		}
	}
	else if (NextButtonState == TEX_NEXT_BUTTON2_MOUSEOVER)
	{
		NextButtonState = TEX_NEXT_BUTTON2_NOMAL;
	}
}

void PlayerInfoPage01::ExitButtonUpdate(POINT pt)
{
	if (pt.x > EXIT_BUTTON_X - EXIT_BUTTON_HALF_WIDTH && pt.x < EXIT_BUTTON_X + EXIT_BUTTON_HALF_WIDTH
		&& pt.y > EXIT_BUTTON_Y - EXIT_BUTTON_HALF_HEIGHT && pt.y < EXIT_BUTTON_Y + EXIT_BUTTON_HALF_HEIGHT)
	{
		if (ExitButtonState == TEX_EXIT_BUTTON_NOMAL)
		{
			ExitButtonState = TEX_EXIT_BUTTON_BORD;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			popup = 1;
		}
	}
	else if (ExitButtonState == TEX_EXIT_BUTTON_BORD)
	{
		ExitButtonState = TEX_EXIT_BUTTON_NOMAL;
	}
}

void PlayerInfoPage01::DoExitUpdate(POINT pt)
{

	if (pt.x > YES_BUTTON_X - (YES_BUTTON_WIDTH / 2) && pt.x < YES_BUTTON_X + (YES_BUTTON_WIDTH / 2)
		&& pt.y > YES_BUTTON_Y - (YES_BUTTON_HEIGHT / 2) && pt.y < YES_BUTTON_Y + (YES_BUTTON_HEIGHT / 2))
	{
		if (YesButtonState == TEX_YES_BUTTON_NOMAL)
		{
			YesButtonState = TEX_YES_BUTTON_BORD;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			dataManager.SavePlayerData();
			pageManager.CreateTitlePage();
		}
	}
	else if (YesButtonState == TEX_YES_BUTTON_BORD)
	{
		YesButtonState = TEX_YES_BUTTON_NOMAL;
	}

	if (pt.x > NO_BUTTON_X - (NO_BUTTON_WIDTH / 2) && pt.x < NO_BUTTON_X + (NO_BUTTON_WIDTH / 2)
		&& pt.y > NO_BUTTON_Y - (NO_BUTTON_HEIGHT / 2) && pt.y < NO_BUTTON_Y + (NO_BUTTON_HEIGHT / 2))
	{
		if (NoButtonState == TEX_NO_BUTTON_NOMAL)
		{
			NoButtonState = TEX_NO_BUTTON_BORD;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			popup = 0;
		}
	}
	else if (NoButtonState == TEX_NO_BUTTON_BORD)
	{
		NoButtonState = TEX_NO_BUTTON_NOMAL;
	}


}

/* Render */
void PlayerInfoPage01::BackgroundRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(TEX_PLAYER_INFO_01_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();

}

void PlayerInfoPage01::dataRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;
	WCHAR text[256];
	wchar_t p[128] = L"";
	setlocale(LC_ALL, "Korean");

	int charecterTexture = TEX_LOAD_DATA_CHARACTER_01;
	switch (gameSystem.player->getCharacter())
	{
	case 1: charecterTexture = TEX_PLAYER_DATA_CHARACTER_01; break;
	case 2: charecterTexture = TEX_PLAYER_DATA_CHARACTER_02; break;
	case 3: charecterTexture = TEX_PLAYER_DATA_CHARACTER_03; break;
	case 4: charecterTexture = TEX_PLAYER_DATA_CHARACTER_04; break;
	case 5: charecterTexture = TEX_PLAYER_DATA_CHARACTER_05; break;
	case 6: charecterTexture = TEX_PLAYER_DATA_CHARACTER_06; break;
	}

	element = textureManager.getTexture(charecterTexture);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 380;
	rc.bottom = 380;

	pos = { 320, 320, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();

	rc.left = 400;
	rc.top = 400;
	rc.bottom = 500;

	rc.right = 1400;
	_stprintf_s<256>(text, _T("이름"));
	font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
		D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

	rc.right = 1600;
	mbstowcs(p, gameSystem.player->getName(), 128);
	font->DrawText(NULL, p, -1, &rc, DT_RIGHT,
		D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

	rc.top = 450;
	rc.bottom = 500;
	rc.right = 1600;
	_stprintf_s<256>(text, _T("%d 일차"), gameSystem.player->getDays());
	font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
		D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

	rc.top = 500;
	rc.bottom = 550;
	rc.right = 1400;
	_stprintf_s<256>(text, _T("스트레스"));
	font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
		D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

	rc.right = 1600;
	_stprintf_s<256>(text, _T("%d"), gameSystem.player->getStress());
	font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
		D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

	rc.top = 550;
	rc.bottom = 600;
	rc.right = 1400;
	_stprintf_s<256>(text, _T("체력"));
	font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
		D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

	rc.right = 1600;
	_stprintf_s<256>(text, _T("%d"), gameSystem.player->getEnergy());
	font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
		D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

	rc.top = 600;
	rc.bottom = 650;
	rc.right = 1400;
	_stprintf_s<256>(text, _T("용돈"));
	font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
		D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

	rc.right = 1600;
	_stprintf_s<256>(text, _T("%d원"), gameSystem.player->getMoney());
	font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
		D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

}

void PlayerInfoPage01::BackButtonRender()
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

void PlayerInfoPage01::NextButtonRender()
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


void PlayerInfoPage01::ExitButtonRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(ExitButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = EXIT_BUTTON_WIDTH;
	rc.bottom = EXIT_BUTTON_HEIGHT;

	pos = { EXIT_BUTTON_X, EXIT_BUTTON_Y, 0 };
	cen = { EXIT_BUTTON_HALF_WIDTH, EXIT_BUTTON_HALF_HEIGHT, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}


void PlayerInfoPage01::DoExitRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;
	WCHAR text[256];
	setlocale(LC_ALL, "Korean");

	rc.left = 0;
	rc.top = 0;

	element = textureManager.getTexture(TEX_REQUESTION_BOX);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.right = REQUESTION_BOX_WIDTH;
	rc.bottom = REQUESTION_BOX_HEIGHT;

	pos = { REQUESTION_BOX_X, REQUESTION_BOX_Y, 0 };
	cen = { REQUESTION_BOX_WIDTH / 2, REQUESTION_BOX_HEIGHT / 2, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();




	element = textureManager.getTexture(YesButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.right = YES_BUTTON_WIDTH;
	rc.bottom = YES_BUTTON_HEIGHT;

	pos = { YES_BUTTON_X, YES_BUTTON_Y, 0 };
	cen = { YES_BUTTON_WIDTH / 2, YES_BUTTON_HEIGHT / 2, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();




	element = textureManager.getTexture(NoButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.right = NO_BUTTON_WIDTH;
	rc.bottom = NO_BUTTON_HEIGHT;

	pos = { NO_BUTTON_X, NO_BUTTON_Y, 0 };
	cen = { NO_BUTTON_WIDTH / 2, NO_BUTTON_HEIGHT / 2, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();


	rc.left = WINDOW_WIDTH / 2 - 300;
	rc.top = WINDOW_HEIGHT / 2 - 100;
	rc.right = WINDOW_WIDTH / 2 + 300;
	rc.bottom = WINDOW_HEIGHT / 2;


	_stprintf_s<256>(text, _T("게임을 종료하시겠습니까?"));
	font->DrawText(NULL, text, -1, &rc, DT_CENTER,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));



}