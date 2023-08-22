#include "GameManager.h"
#include "resource.h"
#include "Level/LevelManager.h"
#include "Timer.h"

CGameManager* CGameManager::mInst = nullptr;
bool CGameManager::mLoop = true;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
    CLevelManager::DestroyInst();

    ReleaseDC(mhWnd, mhDC);
}

bool CGameManager::Init(HINSTANCE hInst)
{
	mhInst = hInst;

    mRS.Width = 1280;
    mRS.Height = 720;

	MyRegisterClass();

    AddWindow();

    mhDC = GetDC(mhWnd);

    // 타이머 초기화
    CTimer::Init();

    // 레벨관리자 초기화
    CLevelManager::GetInst()->Init();


	return true;
}

int CGameManager::Run()
{
    MSG msg;

    // 기본 메시지 루프입니다:
    while (mLoop)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // 메세지가 없는 부분.
        else
        {
            Logic();
        }
    }

    return (int)msg.wParam;
}

void CGameManager::Logic()
{
    float DeltaTime = CTimer::Update();

    Input(DeltaTime);

    Update(DeltaTime);

    Collision(DeltaTime);

    Render();
}

void CGameManager::Input(float DeltaTime)
{
    CLevelManager::GetInst()->Input(DeltaTime);
}

void CGameManager::Update(float DeltaTime)
{
    CLevelManager::GetInst()->Update(DeltaTime);
}

void CGameManager::Collision(float DeltaTime)
{
    CLevelManager::GetInst()->Collision(DeltaTime);
}

void CGameManager::Render()
{
    CLevelManager::GetInst()->Render(mhDC);

    char    FPS[256] = {};

    sprintf_s(FPS, "FPS : %.5f", CTimer::GetFPS());

    TextOutA(mhDC, 1000, 30, FPS, strlen(FPS));
}

ATOM CGameManager::MyRegisterClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = mhInst;
    wcex.hIcon = LoadIcon(mhInst, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;// MAKEINTRESOURCEW(IDC_MY230808);
    wcex.lpszClassName = L"TestWindows";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

bool CGameManager::AddWindow()
{
    mhWnd = CreateWindowW(L"TestWindows", L"새싹 메타버스", WS_OVERLAPPEDWINDOW,
        -mRS.Width, 100, 1000, 600, nullptr, nullptr, mhInst, nullptr);

    if (!mhWnd)
    {
        return false;
    }

    RECT    rc = { 0, 0, mRS.Width, mRS.Height };

    // 메뉴, 틱프레임 등을 포함하여 클라이언트 영역의 크기가 지정된 해상도만큼
    // 생성될 수 있게 실제 크기를 구해준다.
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    SetWindowPos(mhWnd, HWND_TOPMOST, -mRS.Width, 100, rc.right - rc.left,
        rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);

    ShowWindow(mhWnd, SW_SHOW);
    UpdateWindow(mhWnd);

    return true;
}

LRESULT CGameManager::WndProc(HWND hWnd, UINT message, WPARAM wParam,
    LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;

        // HDC : 화면에 무언가를 그릴때 사용한다.
        HDC hdc = BeginPaint(hWnd, &ps);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        mLoop = false;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
