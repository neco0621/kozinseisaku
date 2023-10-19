#include "Application.h"
#include <DxLib.h>



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application& application = Application::GetInstance();

	//ダメな例
	//↓
	//Application application2 = Application::GetInstance();

	//実は表示される描画先には２枚のスクリーンがあります
	//これを高速でフリップ(入れ替える)を行うことで
	// 画面のちらつきをなくしています
	// SetDrawScreen等の関数はDXLib_Init()の後でないと
	// 有効ではないため注意してください
	if (!application.Init())
	{
		return -1;
	}
	//メインループの開始
	application.Run();

	return 0;				// ソフトの終了 
}