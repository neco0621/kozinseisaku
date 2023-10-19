#include "Input.h"
#include <DxLib.h>

void Input::Update()
{
	//‘O‚ÌƒtƒŒ[ƒ€‚Ìî•ñ‚ğ‘ã“ü
	lastKeyState_ = keyState_;
	//Œ»İ‚Ì“ü—¼‹æ‚ğæ“¾
	GetHitKeyStateAll(keyState_.data());
}

bool Input::IsTriggered(const char* command) const
{
	return !lastKeyState_[KEY_INPUT_RETURN] && keyState_[KEY_INPUT_RETURN];
}
