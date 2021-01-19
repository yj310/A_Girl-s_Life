#include "school_pt_quiz_page.h"
#include "global.h"
#include "data_manager.h"
#include <fstream>
#include <tchar.h>
#include <string>
#include <cstring>

using namespace std;

#pragma warning(disable:4996)



SchoolPTQuizPage::SchoolPTQuizPage()
{
	classType = TITLE_PAGE;

	quizs = new PTQuizs();
	dataManager.LoadPTQuizData(quizs);
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

void SchoolPTQuizPage::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);



}


void SchoolPTQuizPage::Render()
{
	BackgroundRender();


	WCHAR text[256];
	RECT rc;
	wchar_t p[128] = L"";
	setlocale(LC_ALL, "Korean");

	rc.left = 500;
	rc.top = 100;
	_stprintf_s<256>(text, _T("Ã¼À°"));
	font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	/*
	rc.left = 500;
	rc.top = 300;
	mbstowcs(p, quizs->quizs[quizCount]->question, 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	rc.left = 500;
	rc.top = 400;
	mbstowcs(p, quizs->quizs[quizCount]->choice1, 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	rc.left = 900;
	rc.top = 400;
	mbstowcs(p, quizs->quizs[quizCount]->choice2, 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
		*/

}


/* Update*/


/* Render */
void SchoolPTQuizPage::BackgroundRender()
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


