#include "Application.h"
#include "SceneManager.h"
#include  "Input.h"

#include <DxLib.h>
#include <assert.h>

int MyLoadGraph(const wchar_t* path)
{
	int handle = LoadGraph(path);
	assert(handle != -1);
	return handle;
}

void Application::Terminate()
{
	DxLib_End();
}

bool Application::Init()
{
	ChangeWindowMode(true);//ウィンドウモードにします
	SetWindowText(L"ごっついアクションゲーム");
	if (DxLib_Init() == -1)
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

void Application::Run()
{
	SceneManager manager;
	Input input;
	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();
		input.Update();
		manager.Update();
		manager.Draw();
		ScreenFlip();
	}
	Terminate();
}
