#include "school_science_quiz_page.h"
#include "global.h"
#include "data_manager.h"
#include <fstream>
#include <tchar.h>
#include <string>

using namespace std;

#pragma warning(disable:4996)



SchoolScienceQuizPage::SchoolScienceQuizPage()
{
	//classType = TITLE_PAGE;

	//const char* subject = "science";
	//scQuizs = new ScienceQuizs(subject);
	quizs = new ScienceQuizs();
	dataManager.LoadScienceQuizData(quizs);
	quizCount = 0;
	colorCount = 0;


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

void SchoolScienceQuizPage::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(MyHWND, &pt);



	for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++)
	{

		int top = 400 + (i / 3) * 100;
		int bottom = top + 100;
		int left = 500 + (i % 3) * 300;
		int right = left + 300;

		if (pt.x > left&& pt.x < right
			&& pt.y > top&& pt.y < bottom)
		{

			if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
				&& inputManager.keyBuffer[VK_LBUTTON] == 0)
			{
				quizs->quizs[quizCount]->answer.push_back(colors[i][0]);
				
				if (quizs->quizs[quizCount]->answer.size() == quizs->quizs[quizCount]->qustion.size())
				{
					int same = 1;
					for (int i = 0; i < quizs->quizs[quizCount]->answer.size(); ++i)
					{
						if (quizs->quizs[quizCount]->answer[i] != quizs->quizs[quizCount]->qustion[i])
						{
							same = 0;
						}
					}
					if (same == 1)
					{
						quizCount++;
					}
				}
				
			}
		}
	}
	if (pt.x > 400 && pt.x < 1300
		&& pt.y > 400 && pt.y < 500)
	{

		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			//if (quizs->quiz[quizCount].answer[0] == '2')
			//	quizCount++;
		}
	}

}


void SchoolScienceQuizPage::Render()
{
	BackgroundRender();
	

	WCHAR text[256];
	RECT rc;
	wchar_t p[128] = L"";
	setlocale(LC_ALL, "Korean");
		

	rc.left = 500;
	rc.top = 100;
	_stprintf_s<256>(text, _T("°úÇÐ"));
	font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	rc.top = 200;
	for (int i = 0; i < quizs->quizs[quizCount]->qustion.size(); i++)
	{
		rc.left = 500 + i*100;
		_stprintf_s<256>(text, _T("%c"), quizs->quizs[quizCount]->qustion[i]);
		font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	}
	



	for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++)
	{
		rc.top = 400 + (i / 3) * 100;
		rc.left = 500 + (i % 3) * 300;
		mbstowcs(p, colors[i], 10);
		font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	}

	rc.top = 700;
	for (int i = 0; i < quizs->quizs[quizCount]->answer.size(); i++)
	{
		rc.left = 500 + i * 100;
		_stprintf_s<256>(text, _T("%c"), quizs->quizs[quizCount]->answer[i]);
		font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	}


	/*rc.left = 500;
	rc.top = 500;
	mbstowcs(p, quizs->quiz[quizCount].answer, 128);
	font->DrawText(NULL, p, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));*/
}


/* Update*/



/* Render */
void SchoolScienceQuizPage::BackgroundRender()
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




