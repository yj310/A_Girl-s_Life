#pragma once
#include "page.h"
#include "player.h"
#include <d3dx9.h>

class NewPlayerPageSelectCharacter : public Page
{
public:

	NewPlayerPageSelectCharacter();
	void Update() override;
	void Render() override;


	int BackButtonState;

	int CharacterButtonState01;
	int CharacterButtonState02;
	int CharacterButtonState03;
	int CharacterButtonState04;
	int CharacterButtonState05;
	int CharacterButtonState06;



	/* Update */
	void BackButtonUpdate(POINT pt);
	void CharacterButtonUpdate(POINT pt);


	/* Render */
	void BackgroundRender();
	void CharacterButtonRender();
	void BackButtonRender();


};