#include "main_home_game_page.h"
#include "global.h"


MainHomeGamePage::MainHomeGamePage()
{
	classType = MAIN_GAME_PAGE;


}



void MainHomeGamePage::Update()
{
	
	mainGamePageUI.Update();

}


void MainHomeGamePage::Render()
{
	BackgroundRender();
	mainGamePageUI.Render();



}



/* Update */






/* Render */
void MainHomeGamePage::BackgroundRender()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(TEX_MAIN_HOME_GAME_PAGE_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}