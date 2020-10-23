#include "title_page.h"
#include "global.h"

#define NEW_BUTTON_WIDTH 320
#define NEW_BUTTON_HEIGHT 110
#define NEW_BUTTON_X WINDOW_WIDTH / 2 - 420
#define NEW_BUTTON_Y 900
#define NEW_BUTTON_HALF_WIDTH NEW_BUTTON_WIDTH / 2
#define NEW_BUTTON_HALF_HEIGHT NEW_BUTTON_HEIGHT / 2

#define LOAD_BUTTON_WIDTH 320
#define LOAD_BUTTON_HEIGHT 110
#define LOAD_BUTTON_X WINDOW_WIDTH / 2
#define LOAD_BUTTON_Y 900
#define LOAD_BUTTON_HALF_WIDTH LOAD_BUTTON_WIDTH / 2
#define LOAD_BUTTON_HALF_HEIGHT LOAD_BUTTON_HEIGHT / 2

#define EXIT_BUTTON_WIDTH 320
#define EXIT_BUTTON_HEIGHT 110
#define EXIT_BUTTON_X WINDOW_WIDTH / 2 + 420
#define EXIT_BUTTON_Y 900
#define EXIT_BUTTON_HALF_WIDTH LOAD_BUTTON_WIDTH / 2
#define EXIT_BUTTON_HALF_HEIGHT LOAD_BUTTON_HEIGHT / 2

TitlePage::TitlePage() 
{
	classType = TITLE_PAGE;
	NewButtonState = TEX_NEW_BUTTON_NOMAL;
	LoadButtonState = TEX_LOAD_BUTTON_NOMAL;
	ExitButtonState = TEX_EXIT_BUTTON_NOMAL;


}

void TitlePage::Update() 
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);

	NewButtonUpdate(pt);
	LoadButtonUpdate(pt);
	ExitButtonUpdate(pt);

}


void TitlePage::Render() 
{
	BackgroundRender();
	NewButtonRender();
	LoadButtonRender();
	ExitButtonRender();
}


/* Update*/
void TitlePage::NewButtonUpdate(POINT pt)
{
	if (pt.x > NEW_BUTTON_X - NEW_BUTTON_HALF_WIDTH && pt.x < NEW_BUTTON_X + NEW_BUTTON_HALF_WIDTH
		&& pt.y > NEW_BUTTON_Y - NEW_BUTTON_HALF_HEIGHT && pt.y < NEW_BUTTON_Y + NEW_BUTTON_HALF_HEIGHT)
	{
		if (NewButtonState == TEX_NEW_BUTTON_NOMAL)
		{
			NewButtonState = TEX_NEW_BUTTON_BORD;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreateNewPlayerPage();
		}
	}
	else if (NewButtonState == TEX_NEW_BUTTON_BORD)
	{
		NewButtonState = TEX_NEW_BUTTON_NOMAL;
	}
}

void TitlePage::LoadButtonUpdate(POINT pt)
{
	if (pt.x > LOAD_BUTTON_X - LOAD_BUTTON_HALF_WIDTH && pt.x < LOAD_BUTTON_X + LOAD_BUTTON_HALF_WIDTH
		&& pt.y > LOAD_BUTTON_Y - LOAD_BUTTON_HALF_HEIGHT && pt.y < LOAD_BUTTON_Y + LOAD_BUTTON_HALF_HEIGHT)
	{
		if (LoadButtonState == TEX_LOAD_BUTTON_NOMAL)
		{
			LoadButtonState = TEX_LOAD_BUTTON_BORD;
		}

		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreateLoadPlayerPage();
		}
	}
	else if (LoadButtonState == TEX_LOAD_BUTTON_BORD)
	{
		LoadButtonState = TEX_LOAD_BUTTON_NOMAL;
	}
}

void TitlePage::ExitButtonUpdate(POINT pt)
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
			PostQuitMessage(0);
		}
	}
	else if (ExitButtonState == TEX_EXIT_BUTTON_BORD)
	{
		ExitButtonState = TEX_EXIT_BUTTON_NOMAL;
	}
}




/* Render */
void TitlePage::BackgroundRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(TEX_TITLE_PAGE_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void TitlePage::NewButtonRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(NewButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = NEW_BUTTON_WIDTH;
	rc.bottom = NEW_BUTTON_HEIGHT;

	pos = { NEW_BUTTON_X, NEW_BUTTON_Y, 0 };
	cen = { NEW_BUTTON_HALF_WIDTH, NEW_BUTTON_HALF_HEIGHT, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();


}

void TitlePage::LoadButtonRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(LoadButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = LOAD_BUTTON_WIDTH;
	rc.bottom = LOAD_BUTTON_HEIGHT;

	pos = { LOAD_BUTTON_X, LOAD_BUTTON_Y, 0 };
	cen = { LOAD_BUTTON_HALF_WIDTH, LOAD_BUTTON_HALF_HEIGHT, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();

}

void TitlePage::ExitButtonRender()
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


