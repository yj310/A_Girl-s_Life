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
	int inputState;		// Ű���� �Է��� ���� ����

	vector<char> cname;	// �Է¹��� �̸�
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