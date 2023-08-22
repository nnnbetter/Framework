#pragma once

#include "GameInfo.h"

class CGameManager
{
private:
	CGameManager();
	~CGameManager();

private:
	static CGameManager* mInst;

public:
	static CGameManager* GetInst()
	{
		if (!mInst)
			mInst = new CGameManager;

		return mInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(mInst);
	}


private:
	HINSTANCE	mhInst;
	HWND		mhWnd;
	Resolution	mRS;
	HDC			mhDC;

	static bool	mLoop;

public:
	bool Init(HINSTANCE hInst);
	int Run();

private:
	void Logic();
	void Input(float DeltaTime);
	void Update(float DeltaTime);
	void Collision(float DeltaTime);
	void Render();

private:
	ATOM MyRegisterClass();
	bool AddWindow();

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

