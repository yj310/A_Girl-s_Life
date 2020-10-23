#pragma once

#include <d3d9.h>
#include <d3dx9core.h>
#include <Windows.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <vector>

// Manager
#include "texture_manager.h"
#include "input_manager.h"
#include "page_manager.h"
#include "data_manager.h"

#include "game_system.h"
#include "cheat.h"



/*  */
// basic
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080


// Class Types
#define TITLE_PAGE 2000
#define NEW_PLAYER_PAGE 2001
#define LOAD_PLAYER_PAGE 2002
#define MAIN_GAME_PAGE 2003


/* Texture ID */
// Background
#define TEX_TITLE_PAGE_BACKGROUND 1000
#define TEX_NEW_PLAYER_PAGE_BACKGROUND 1001
#define TEX_LOAD_PLAYER_PAGE_BACKGROUND 1002
#define TEX_MAIN_HOME_GAME_PAGE_BACKGROUND 1003
#define TEX_MAIN_SCHOOL_GAME_PAGE_BACKGROUND 1004


// Object
#define TEX_CHARECTER_SELETE_BUTTON_UP 2000
#define TEX_CLOCK 2001
#define TEX_NAME_BAR 2002


// UI
#define TEX_NEW_BUTTON_NOMAL 3000
#define TEX_NEW_BUTTON_BORD 3001
#define TEX_LOAD_BUTTON_NOMAL 3002
#define TEX_LOAD_BUTTON_BORD 3003
#define TEX_EXIT_BUTTON_NOMAL 3004
#define TEX_EXIT_BUTTON_BORD 3005
#define TEX_BACK_BUTTON_NOMAL 3006
#define TEX_BACK_BUTTON_BORD 3007
#define TEX_NEXT_BUTTON_NOMAL 3008
#define TEX_NEXT_BUTTON_BORD 3009
#define TEX_ENERGY_BAR_FULL 3010
#define TEX_ENERGY_BAR_EMPTY 3011
#define TEX_STRESS_BAR_FULL 3012
#define TEX_STRESS_BAR_EMPTY 3013
#define TEX_MONEY_BAR 3014
#define TEX_ERRAND_BUTTON_NOMAL 3015
#define TEX_ERRAND_BUTTON_ONMOUSE 3016
#define TEX_LEISURE_BUTTON_NOMAL 3017
#define TEX_LEISURE_BUTTON_ONMOUSE 3018
#define TEX_HOMEWORK_BUTTON_NOMAL 3019
#define TEX_HOMEWORK_BUTTON_ONMOUSE 3020

// Character
#define TEX_GIRL_YOUN 4000



// Other





/* class */




/* global */
// basic
extern LPDIRECT3D9         g_pD3D;
extern LPDIRECT3DDEVICE9   g_pd3dDevice;
extern HWND MyHWND;

// Manager
extern TextureManager textureManager;
extern InputManager inputManager;
extern PageManager pageManager;
extern DataManager dataManager;

// Other
extern float deltaTime;
extern DWORD prevTime;
extern GameSystem gameSystem;
extern Cheat cheat;