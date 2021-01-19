#pragma once
#include "page.h"
#include "player.h"
#include <vector>
#include <d3dx9.h>
using namespace std;

class NewPlayerPage : public Page
{
public:

	NewPlayerPage();
	void Update() override;
	void Render() override;


	int BackButtonState;
	int NextButtonState;
	int inputState;		// 키보드 입력을 받을 문항

	vector<char> cname;	// 입력받은 이름
	Player player;

	ID3DXFont* font = NULL;
	int cursorCount;



	/* Update */
	void BackButtonUpdate(POINT pt);
	void NextButtonUpdate(POINT pt);


	/* Render */
	void BackgroundRender();
	void NameRender();


	void BackButtonRender();
	void NextButtonRender();


};