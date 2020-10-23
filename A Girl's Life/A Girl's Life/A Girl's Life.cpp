
#include "framework.h"
#include "A Girl's Life.h"
#include "global.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);


/* global */
// basic
HWND MyHWND;
LPDIRECT3D9         g_pD3D = NULL;
LPDIRECT3DDEVICE9   g_pd3dDevice = NULL;

// Manager
TextureManager textureManager;
InputManager inputManager;
PageManager pageManager;
DataManager dataManager;

// Other
float deltaTime = 0.3f;
DWORD prevTime;
GameSystem gameSystem;
vector<PlayerInfo*> playerInfos;
Cheat cheat;

HRESULT InitD3D(HWND hWnd)
{
	if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	/*d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;*/

	d3dpp.Windowed = false;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferWidth = WINDOW_WIDTH;
	d3dpp.BackBufferHeight = WINDOW_HEIGHT;

	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_pd3dDevice)))
	{
		return E_FAIL;
	}

	return S_OK;
}

void InitMyStuff()
{

	/* Texture Load */
	// Background
	textureManager.LoadTexture(L"resource/image/Background/Title_Page.png", TEX_TITLE_PAGE_BACKGROUND);
	textureManager.LoadTexture(L"resource/image/Background/Create_Character_Page.png", TEX_NEW_PLAYER_PAGE_BACKGROUND);
	textureManager.LoadTexture(L"resource/image/Background/Load_Character_page.png", TEX_LOAD_PLAYER_PAGE_BACKGROUND);
	textureManager.LoadTexture(L"resource/image/Background/Main_Home_Game_Page.png", TEX_MAIN_HOME_GAME_PAGE_BACKGROUND);
	textureManager.LoadTexture(L"resource/image/Background/Main_School_Game_Page.png", TEX_MAIN_SCHOOL_GAME_PAGE_BACKGROUND);



	// UI
	textureManager.LoadTexture(L"resource/image/UI/NEW_Button_Nomal.png", TEX_NEW_BUTTON_NOMAL);
	textureManager.LoadTexture(L"resource/image/UI/NEW_Button_Bord.png", TEX_NEW_BUTTON_BORD);
	textureManager.LoadTexture(L"resource/image/UI/LOAD_Button_Nomal.png", TEX_LOAD_BUTTON_NOMAL);
	textureManager.LoadTexture(L"resource/image/UI/LOAD_Button_Bord.png", TEX_LOAD_BUTTON_BORD);
	textureManager.LoadTexture(L"resource/image/UI/EXIT_Button_Nomal.png", TEX_EXIT_BUTTON_NOMAL);
	textureManager.LoadTexture(L"resource/image/UI/EXIT_Button_Bord.png", TEX_EXIT_BUTTON_BORD);
	textureManager.LoadTexture(L"resource/image/UI/BACK_Button_Nomal.png", TEX_BACK_BUTTON_NOMAL);
	textureManager.LoadTexture(L"resource/image/UI/BACK_Button_Bord.png", TEX_BACK_BUTTON_BORD);
	textureManager.LoadTexture(L"resource/image/UI/NEXT_Button_Nomal.png", TEX_NEXT_BUTTON_NOMAL);
	textureManager.LoadTexture(L"resource/image/UI/NEXT_Button_Bord.png", TEX_NEXT_BUTTON_BORD);
	textureManager.LoadTexture(L"resource/image/UI/energy_bar_full.png", TEX_ENERGY_BAR_FULL);
	textureManager.LoadTexture(L"resource/image/UI/energy_bar_empty.png", TEX_ENERGY_BAR_EMPTY);
	textureManager.LoadTexture(L"resource/image/UI/stress_bar_full.png", TEX_STRESS_BAR_FULL);
	textureManager.LoadTexture(L"resource/image/UI/stress_bar_empty.png", TEX_STRESS_BAR_EMPTY);
	textureManager.LoadTexture(L"resource/image/UI/money_bar.png", TEX_MONEY_BAR);
	textureManager.LoadTexture(L"resource/image/UI/errand_button.png", TEX_ERRAND_BUTTON_NOMAL);
	textureManager.LoadTexture(L"resource/image/UI/errand_button_onmouse.png", TEX_ERRAND_BUTTON_ONMOUSE);
	textureManager.LoadTexture(L"resource/image/UI/leisure_button.png", TEX_LEISURE_BUTTON_NOMAL);
	textureManager.LoadTexture(L"resource/image/UI/leisure_button_onmouse.png", TEX_LEISURE_BUTTON_ONMOUSE);
	textureManager.LoadTexture(L"resource/image/UI/homework_button.png", TEX_HOMEWORK_BUTTON_NOMAL);
	textureManager.LoadTexture(L"resource/image/UI/homework_button_onmouse.png", TEX_HOMEWORK_BUTTON_ONMOUSE);


	// Object
	textureManager.LoadTexture(L"resource/image/Object/CharecterSelectButtonUp.png", TEX_CHARECTER_SELETE_BUTTON_UP);
	textureManager.LoadTexture(L"resource/image/Object/Clock.png", TEX_CLOCK);
	textureManager.LoadTexture(L"resource/image/Object/NameBar.png", TEX_NAME_BAR);

	// Character
	textureManager.LoadTexture(L"resource/image/Character/girl_youn.png", TEX_GIRL_YOUN);



	dataManager.LoadPlayersData();
	pageManager.CreateTitlePage();
	prevTime = GetTickCount();
}

void Update()
{
	DWORD cur = GetTickCount();
	DWORD diff = cur - prevTime;
	deltaTime = diff / 1000.0f;
	if (deltaTime > 0.016f)
	{
		deltaTime = 0.016f;
	}
	prevTime = cur;


	if (inputManager.prevKeyBuffer[VK_ESCAPE] == 1
		&& inputManager.keyBuffer[VK_ESCAPE] == 0)
	{
		PostQuitMessage(0);
	}


	cheat.Update();
	pageManager.Update();
	inputManager.Update();
}

void Render()
{
	if (NULL == g_pd3dDevice)
		return;

	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		pageManager.Render();

		g_pd3dDevice->EndScene();
	}

	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_AGIRLSLIFE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_AGIRLSLIFE));

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Update();
			Render();
		}
	}

	return (int)msg.wParam;
}



ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_AGIRLSLIFE));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance;

	MyHWND = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

	if (!MyHWND)
	{
		return FALSE;
	}


	InitD3D(MyHWND);
	InitMyStuff();

	ShowWindow(MyHWND, nCmdShow);
	UpdateWindow(MyHWND);

	return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_MOUSEWHEEL:
		inputManager.mouseWheel = HIWORD(wParam);
		break;
	case WM_KEYDOWN:
		inputManager.keyBuffer[wParam] = 1;
		break;
	case WM_KEYUP:
		inputManager.keyBuffer[wParam] = 0;
		break;
	case WM_LBUTTONDOWN:		inputManager.keyBuffer[VK_LBUTTON] = 1;
		break;
	case WM_LBUTTONUP:
		inputManager.keyBuffer[VK_LBUTTON] = 0;
		break;
	case WM_RBUTTONDOWN:
		inputManager.keyBuffer[VK_RBUTTON] = 1;
		break;
	case WM_RBUTTONUP:
		inputManager.keyBuffer[VK_RBUTTON] = 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
