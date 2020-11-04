#include "school_quiz_page.h"
#include "global.h"
#include "data_manager.h"
#include <fstream>


#pragma warning(disable:4996)

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

SchoolQuizPage::SchoolQuizPage()
{
	classType = TITLE_PAGE;
	NewButtonState = TEX_NEW_BUTTON_NOMAL;
	LoadButtonState = TEX_LOAD_BUTTON_NOMAL;
	ExitButtonState = TEX_EXIT_BUTTON_NOMAL;

	const char* subject = "korean";
	quizs = new Quizs(subject);
	dataManager.LoadQuizData(quizs);
	quizCount = 0;


	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);

	int fontSize = 30;
	TCHAR g_strFont[256];
	wcscpy_s(g_strFont, 32, L"¸¼Àº °íµñ");

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

void SchoolQuizPage::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);

	NewButtonUpdate(pt);
	LoadButtonUpdate(pt);
	ExitButtonUpdate(pt);

	if (pt.x > 500 && pt.x < 900
		&& pt.y > 400 && pt.y < 500)
	{
		
		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			if (quizs->quiz[quizCount].answer[0] == '1')
				quizCount++;
		}
	}
	if (pt.x > 900 && pt.x < 1300
		&& pt.y > 400 && pt.y < 500)
	{

		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			if (quizs->quiz[quizCount].answer[0] == '2')
				quizCount++;
		}
	}

}


void SchoolQuizPage::Render()
{
	BackgroundRender();
	NewButtonRender();
	LoadButtonRender();
	ExitButtonRender();

	RECT rc;
	wchar_t p[128] = L"";
	setlocale(LC_ALL, "Korean");

	rc.left = 500;
	rc.top = 200;
	mbstowcs(p, quizs->subject, 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	rc.left = 500;
	rc.top = 300;
	mbstowcs(p, quizs->quiz[quizCount].question, 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	rc.left = 500;
	rc.top = 400;
	mbstowcs(p, quizs->quiz[quizCount].choice1, 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	rc.left = 900;
	rc.top = 400;
	mbstowcs(p, quizs->quiz[quizCount].choice2, 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	/*rc.left = 500;
	rc.top = 500;
	mbstowcs(p, quizs->quiz[quizCount].answer, 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));*/
}


/* Update*/
void SchoolQuizPage::NewButtonUpdate(POINT pt)
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
			//pageManager.CreateNewPlayerPage();
			quizCount++;
		}
	}
	else if (NewButtonState == TEX_NEW_BUTTON_BORD)
	{
		NewButtonState = TEX_NEW_BUTTON_NOMAL;
	}
}

void SchoolQuizPage::LoadButtonUpdate(POINT pt)
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

void SchoolQuizPage::ExitButtonUpdate(POINT pt)
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
void SchoolQuizPage::BackgroundRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(7000);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void SchoolQuizPage::NewButtonRender()
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

void SchoolQuizPage::LoadButtonRender()
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

void SchoolQuizPage::ExitButtonRender()
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


