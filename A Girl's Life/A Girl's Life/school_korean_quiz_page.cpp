#include "school_korean_quiz_page.h"
#include "global.h"
#include "data_manager.h"
#include <fstream>
#include <tchar.h>
#include <string>
#include <cstring>

using namespace std;

#pragma warning(disable:4996)

#define FIRST_ANSWER_WIDTH 400
#define FIRST_ANSWER_HEIGHT 150
#define FIRST_ANSWER_X WINDOW_WIDTH/2-300
#define FIRST_ANSWER_Y 900

#define SECOND_ANSWER_WIDTH 400
#define SECOND_ANSWER_HEIGHT 150
#define SECOND_ANSWER_X WINDOW_WIDTH/2+300
#define SECOND_ANSWER_Y 900

#define TIMER_WIDTH 1500
#define TIMER_HEIGHT 50
#define TIMER_X WINDOW_WIDTH/2
#define TIMER_Y 100

#define OK_BUTTON_WIDTH 320
#define OK_BUTTON_HEIGHT 110
#define OK_BUTTON_X WINDOW_WIDTH/2
#define OK_BUTTON_Y 900
#define OK_BUTTON_HALF_WIDTH OK_BUTTON_WIDTH / 2
#define OK_BUTTON_HALF_HEIGHT OK_BUTTON_HEIGHT / 2

SchoolKoreanQuizPage::SchoolKoreanQuizPage()
{
	classType = TITLE_PAGE;

	const char* subject = "korean";
	quizs = new KoreanQuizs();
	dataManager.LoadKoreanQuizData(quizs);
	quizCount = 0;
	firstAnswerButtonState = TEX_ANSWER_BUTTON_NOMAL;
	secondAnswerButtonState = TEX_ANSWER_BUTTON_NOMAL;
	maxTime = 500;
	timer = maxTime;
	O_Count = 0;
	X_Count = 0;
	rightAnswerCount = 0;
	wrongAnswerCount = 0;
	OKButtonState = TEX_OK_BUTTON_NOMAL;

	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);

	int fontSize = 25;
	TCHAR g_strFont[256];
	wcscpy_s(g_strFont, 32, L"맑은 고딕");

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

void SchoolKoreanQuizPage::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);

	
	

	if (timer <= 0 && X_Count <= 0 && O_Count <= 0)
	{
		if (pt.x > OK_BUTTON_X - OK_BUTTON_HALF_WIDTH && pt.x < OK_BUTTON_X + OK_BUTTON_HALF_WIDTH
			&& pt.y > OK_BUTTON_Y - OK_BUTTON_HALF_HEIGHT && pt.y < OK_BUTTON_Y + OK_BUTTON_HALF_HEIGHT)
		{
			if (OKButtonState == TEX_OK_BUTTON_NOMAL)
			{
				OKButtonState = TEX_OK_BUTTON_BORD;
			}
			if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
				&& inputManager.keyBuffer[VK_LBUTTON] == 0)
			{
				if (rightAnswerCount > wrongAnswerCount)
				{
					gameSystem.player->addKoreanScore(10);
				}
				else if (rightAnswerCount == wrongAnswerCount)
				{
					gameSystem.player->addKoreanScore(5);
				}
				else if (rightAnswerCount < wrongAnswerCount)
				{
					gameSystem.player->addKoreanScore(0);
				}
				gameSystem.player->addStress(10);
				gameSystem.player->addTime(1);
				pageManager.CreateMainHomeGamePage();
			}
		}
		else if (OKButtonState == TEX_OK_BUTTON_BORD)
		{
			OKButtonState = TEX_OK_BUTTON_NOMAL;
		}
	}
	else
	{

		if (O_Count <= 0 && X_Count <= 0)
		{
			timer--;



			if (pt.x > FIRST_ANSWER_X - (FIRST_ANSWER_WIDTH / 2) && pt.x < FIRST_ANSWER_X + (FIRST_ANSWER_WIDTH / 2)
				&& pt.y > FIRST_ANSWER_Y - (FIRST_ANSWER_HEIGHT / 2) && pt.y < FIRST_ANSWER_Y + (FIRST_ANSWER_HEIGHT / 2))
			{
				if (firstAnswerButtonState == TEX_ANSWER_BUTTON_NOMAL)
				{
					firstAnswerButtonState = TEX_ANSWER_BUTTON_MOUSEOVER;
				}
				if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
					&& inputManager.keyBuffer[VK_LBUTTON] == 0)
				{
					if (!strcmp(quizs->quizs[quizCount]->answer, quizs->quizs[quizCount]->choice1))
					{
						O_Count = 100; rightAnswerCount++;
					}
					else
					{
						X_Count = 100; wrongAnswerCount++;
					}
				}
			}
			else if (firstAnswerButtonState == TEX_ANSWER_BUTTON_MOUSEOVER)
			{
				firstAnswerButtonState = TEX_ANSWER_BUTTON_NOMAL;
			}

			if (pt.x > SECOND_ANSWER_X - (SECOND_ANSWER_WIDTH / 2) && pt.x < SECOND_ANSWER_X + (SECOND_ANSWER_WIDTH / 2)
				&& pt.y >  SECOND_ANSWER_Y - (SECOND_ANSWER_HEIGHT / 2) && pt.y < SECOND_ANSWER_Y + (SECOND_ANSWER_HEIGHT / 2))
			{

				if (secondAnswerButtonState == TEX_ANSWER_BUTTON_NOMAL)
				{
					secondAnswerButtonState = TEX_ANSWER_BUTTON_MOUSEOVER;
				}
				if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
					&& inputManager.keyBuffer[VK_LBUTTON] == 0)
				{
					if (!strcmp(quizs->quizs[quizCount]->answer, quizs->quizs[quizCount]->choice2))
					{
						O_Count = 100; rightAnswerCount++;
					}
					else
					{
						X_Count = 100; wrongAnswerCount++;
					}

				}
			}
			else if (secondAnswerButtonState == TEX_ANSWER_BUTTON_MOUSEOVER)
			{
				secondAnswerButtonState = TEX_ANSWER_BUTTON_NOMAL;
			}
		}
		else if (O_Count > 0)
		{
			O_Count--;
			if (O_Count <= 0)
			{
				quizCount++;
			}
		}
		else if (X_Count > 0)
		{
			X_Count--;
			if (X_Count <= 0)
			{
				quizCount++;
			}
		}
	}
	

}


void SchoolKoreanQuizPage::Render()
{
	BackgroundRender();

	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;


	WCHAR text[256];
	wchar_t p[128] = L"";
	setlocale(LC_ALL, "Korean");

	rc.left = 0;
	rc.right = 1920;
	rc.top = 500;
	rc.bottom = 800;
	mbstowcs(p, quizs->quizs[quizCount]->question, 128);
	font->DrawText(NULL, p, -1, &rc, DT_CENTER,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));


	element = textureManager.getTexture(firstAnswerButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = FIRST_ANSWER_WIDTH;
	rc.bottom = FIRST_ANSWER_HEIGHT;

	pos = { FIRST_ANSWER_X, FIRST_ANSWER_Y, 0 };
	cen = { FIRST_ANSWER_WIDTH / 2, FIRST_ANSWER_HEIGHT / 2, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();

	rc.left = FIRST_ANSWER_X - (FIRST_ANSWER_WIDTH / 2);
	rc.top = FIRST_ANSWER_Y - (FIRST_ANSWER_HEIGHT / 2) + 40;
	rc.right = FIRST_ANSWER_X + (FIRST_ANSWER_WIDTH / 2);
	rc.bottom = FIRST_ANSWER_Y + (FIRST_ANSWER_HEIGHT / 2);
	mbstowcs(p, quizs->quizs[quizCount]->choice1, 128);
	font->DrawText(NULL, p, -1, &rc, DT_CENTER,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));



	element = textureManager.getTexture(secondAnswerButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = SECOND_ANSWER_WIDTH;
	rc.bottom = SECOND_ANSWER_HEIGHT;

	pos = { SECOND_ANSWER_X, SECOND_ANSWER_Y, 0 };
	cen = { SECOND_ANSWER_WIDTH / 2, SECOND_ANSWER_HEIGHT / 2, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();

	rc.left = SECOND_ANSWER_X - (SECOND_ANSWER_WIDTH / 2);
	rc.top = SECOND_ANSWER_Y - (SECOND_ANSWER_HEIGHT / 2) + 40;
	rc.right = SECOND_ANSWER_X + (SECOND_ANSWER_WIDTH / 2);
	rc.bottom = SECOND_ANSWER_Y + (SECOND_ANSWER_HEIGHT / 2);
	mbstowcs(p, quizs->quizs[quizCount]->choice2, 128);
	font->DrawText(NULL, p, -1, &rc, DT_CENTER,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));




	element = textureManager.getTexture(TEX_QUIZ_TIMER_EMPTY);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = TIMER_WIDTH;
	rc.bottom = TIMER_HEIGHT;

	pos = { TIMER_X, TIMER_Y, 0 };
	cen = { TIMER_WIDTH / 2, TIMER_HEIGHT / 2, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();



	element = textureManager.getTexture(TEX_QUIZ_TIMER_FULL);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	if (timer > 0)
	{
		rc.right = (int)((TIMER_WIDTH / (maxTime*1.0)) * timer);
	}
	else 
	{
		rc.right = 0;
	}
	rc.bottom = TIMER_HEIGHT;

	pos = { TIMER_X, TIMER_Y, 0 };
	cen = { TIMER_WIDTH / 2, TIMER_HEIGHT / 2, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();



	
	if (O_Count > 0)
	{
		element = textureManager.getTexture(TEX_O);
		element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

		rc.left = 0;
		rc.top = 0;
		rc.right = 700;
		rc.bottom = 700;

		pos = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0 };
		cen = { 350, 350, 0 };

		element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

		element->sprite->End();

	} 
	else if (X_Count > 0)
	{
		element = textureManager.getTexture(TEX_X);
		element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

		rc.left = 0;
		rc.top = 0;
		rc.right = 700;
		rc.bottom = 700;

		pos = { WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0 };
		cen = { 350, 350, 0 };

		element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

		element->sprite->End();

	}

	if (timer <= 0 && X_Count <= 0 && O_Count <= 0)
	{

		element = textureManager.getTexture(TEX_QUIZ_RESULT_PAGE_BACKGROUND);
		element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

		rc.left = 0;
		rc.top = 0;
		rc.right = 1300;
		rc.bottom = 900;

		pos = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0 };
		cen = { 1300/2, 900/2, 0 };

		element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

		element->sprite->End();


		rc.left = 500;
		rc.right = 1420;
		rc.bottom = WINDOW_HEIGHT;


		rc.top = 350;
		_stprintf_s<256>(text, _T("과목"));
		font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

		_stprintf_s<256>(text, _T("국어"));
		font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
			D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));


		rc.top = 420;
		_stprintf_s<256>(text, _T("총 문항수"));
		font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

		_stprintf_s<256>(text, _T("%d 문항"), quizCount);
		font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
			D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

		rc.top = 490;
		_stprintf_s<256>(text, _T("맞춘 문항수"));
		font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

		_stprintf_s<256>(text, _T("%d 문항"), rightAnswerCount);
		font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
			D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));


		rc.top = 560;
		_stprintf_s<256>(text, _T("틀린 문항수"));
		font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

		_stprintf_s<256>(text, _T("%d 문항"), wrongAnswerCount);
		font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
			D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

		int score = 0;
		if (rightAnswerCount > wrongAnswerCount)
		{
			score = 10;
		}
		else if (rightAnswerCount == wrongAnswerCount)
		{
			score = 5;
		}
		else if (rightAnswerCount < wrongAnswerCount)
		{
			score = 0;
		}

		rc.top = 630;
		_stprintf_s<256>(text, _T("총점"));
		font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));

		_stprintf_s<256>(text, _T("%d 점"), score);
		font->DrawText(NULL, text, -1, &rc, DT_RIGHT,
			D3DXCOLOR(0.0f, 0.00f, 0.0f, 1.0f));


		element = textureManager.getTexture(OKButtonState);
		element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

		rc.left = 0;
		rc.top = 0;
		rc.right = OK_BUTTON_WIDTH;
		rc.bottom = OK_BUTTON_HEIGHT;

		pos = { OK_BUTTON_X, OK_BUTTON_Y, 0 };
		cen = { OK_BUTTON_HALF_WIDTH, OK_BUTTON_HALF_HEIGHT, 0 };

		element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

		element->sprite->End();



	}

}


/* Update*/


/* Render */
void SchoolKoreanQuizPage::BackgroundRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(TEX_KOREAN_QUIZ_PAGE_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}


