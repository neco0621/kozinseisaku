#include "Input.h"
#include <DxLib.h>

void Input::Update()
{
	//前のフレームの情報を代入
	lastKeyState_ = keyState_;
	//現在の入両区を取得
	GetHitKeyStateAll(keyState_.data());
}

bool Input::IsTriggered(const char* command) const
{
	return !lastKeyState_[KEY_INPUT_RETURN] && keyState_[KEY_INPUT_RETURN];
}
