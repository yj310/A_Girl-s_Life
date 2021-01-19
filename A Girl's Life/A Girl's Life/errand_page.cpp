#include "errand_page.h"
#include "global.h"
#include <tchar.h>
#pragma warning(disable:4996)

#define BACK_BUTTON_WIDTH 320
#define BACK_BUTTON_HEIGHT 110
#define BACK_BUTTON_X 280
#define BACK_BUTTON_Y 1000
#define BACK_BUTTON_HALF_WIDTH BACK_BUTTON_WIDTH / 2
#define BACK_BUTTON_HALF_HEIGHT BACK_BUTTON_HEIGHT / 2

#define ERREND_SHOPPING_WIDTH 400
#define ERREND_SHOPPING_HEIGHT 400
#define ERREND_SHOPPING_X  WINDOW_WIDTH/2-400
#define ERREND_SHOPPING_Y 550

#define ERREND_WASH_DISH_WIDTH 400
#define ERREND_WASH_DISH_HEIGHT 400
#define ERREND_WASH_DISH_X  WINDOW_WIDTH/2+400
#define ERREND_WASH_DISH_Y 550

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

#define ERREND_SHOPPING 1
#define ERREND_WASH_DISH 2


ErrandPage::ErrandPage()
{
	classType = ERRAND_PAGE;
	BackButtonState = TEX_BACK_BUTTON_NOMAL;
	
	shoppingState = TEX_ERRAND_SHOPPING;
	washDishState = TEX_ERRAND_WASH_DISH;

	YesButtonState = TEX_YES_BUTTON_NOMAL;
	NoButtonState = TEX_NO_BUTTON_NOMAL;

	selectErrand = -1;


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

void ErrandPage::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);

	if (selectErrand == ERREND_SHOPPING || selectErrand == ERREND_WASH_DISH)
	{
		DoErrandUpdate(pt);
	}
	else
	{
		BackButtonUpdate(pt);
		ErrandButtonUpdate(pt);
	}
	
}

void ErrandPage::Render()
{
	
	BackgroundRender();
	BackButtonRender();
	ErrandButtonRender();
	if (selectErrand == ERREND_SHOPPING || selectErrand == ERREND_WASH_DISH)
	{
		DoErrandRender();
	}

}


/* Update */
void ErrandPage::BackButtonUpdate(POINT pt)
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

void ErrandPage::ErrandButtonUpdate(POINT pt)
{
	if (pt.x > ERREND_SHOPPING_X - (ERREND_SHOPPING_WIDTH / 2) && pt.x < ERREND_SHOPPING_X + (ERREND_SHOPPING_WIDTH / 2)
		&& pt.y > ERREND_SHOPPING_Y - (ERREND_SHOPPING_HEIGHT / 2) && pt.y < ERREND_SHOPPING_Y + (ERREND_SHOPPING_HEIGHT / 2))
	{
		if (shoppingState == TEX_ERRAND_SHOPPING)
		{
			shoppingState = TEX_ERRAND_SHOPPING_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			selectErrand = ERREND_SHOPPING;
		}
	}
	else if (shoppingState == TEX_ERRAND_SHOPPING_MOUSEOVER)
	{
		shoppingState = TEX_ERRAND_SHOPPING;
	}



	if (pt.x > ERREND_WASH_DISH_X - (ERREND_WASH_DISH_WIDTH / 2) && pt.x < ERREND_WASH_DISH_X + (ERREND_WASH_DISH_WIDTH / 2)
		&& pt.y > ERREND_WASH_DISH_Y - (ERREND_WASH_DISH_HEIGHT / 2) && pt.y < ERREND_WASH_DISH_Y + (ERREND_WASH_DISH_HEIGHT / 2))
	{
		if (washDishState == TEX_ERRAND_WASH_DISH)
		{
			washDishState = TEX_ERRAND_WASH_DISH_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			selectErrand = ERREND_WASH_DISH;
		}
	}
	else if (washDishState == TEX_ERRAND_WASH_DISH_MOUSEOVER)
	{
		washDishState = TEX_ERRAND_WASH_DISH;
	}
}

void ErrandPage::DoErrandUpdate(POINT pt)
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
			if (selectErrand == ERREND_SHOPPING)
			{
				gameSystem.player->addTime(2);
				gameSystem.player->addMoney(5000);
			}
			else if (selectErrand == ERREND_WASH_DISH)
			{
				gameSystem.player->addTime(1);
				gameSystem.player->addMoney(2000);
			}
			pageManager.CreateMainHomeGamePage();
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
			selectErrand = -1;
		}
	}
	else if (NoButtonState == TEX_NO_BUTTON_BORD)
	{
		NoButtonState = TEX_NO_BUTTON_NOMAL;
	}


}

/* Render */
void ErrandPage::BackgroundRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(TEX_ERRAND_PAGE_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();

}

void ErrandPage::BackButtonRender()
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

void ErrandPage::ErrandButtonRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;
	rc.left = 0;
	rc.top = 0;

	element = textureManager.getTexture(shoppingState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.right = ERREND_SHOPPING_WIDTH;
	rc.bottom = ERREND_SHOPPING_HEIGHT;

	pos = { ERREND_SHOPPING_X, ERREND_SHOPPING_Y, 0 };
	cen = { ERREND_SHOPPING_WIDTH / 2, ERREND_SHOPPING_HEIGHT / 2, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();



	element = textureManager.getTexture(washDishState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.right = ERREND_WASH_DISH_WIDTH;
	rc.bottom = ERREND_WASH_DISH_HEIGHT;

	pos = { ERREND_WASH_DISH_X, ERREND_WASH_DISH_Y, 0 };
	cen = { ERREND_WASH_DISH_WIDTH / 2, ERREND_WASH_DISH_HEIGHT / 2, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void ErrandPage::DoErrandRender()
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
	rc.top = WINDOW_HEIGHT / 2-100;
	rc.right = WINDOW_WIDTH / 2 + 300;
	rc.bottom = WINDOW_HEIGHT / 2;


	if (selectErrand == ERREND_SHOPPING) {
		_stprintf_s<256>(text, _T("장봐오기를 하시겠습니까?\n(소요시간 02:00, 용돈 5000원)"));
		font->DrawText(NULL, text, -1, &rc, DT_CENTER,
			D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	}
	else if (selectErrand == ERREND_WASH_DISH) {
		_stprintf_s<256>(text, _T("설거지하기를 하시겠습니까?\n(소요시간 01:00, 용돈 2000원)"));
		font->DrawText(NULL, text, -1, &rc, DT_CENTER,
			D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	}



}