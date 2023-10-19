#include "SceneMain.h"
#include "DxLib.h"

SceneMain::SceneMain() : 
	m_frameCount(0)	//コンストラクタ初期化子を利用して初期化する
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{

}

//毎フラーム行う処理をUpdateに記述する
void SceneMain::Update()
{
	m_frameCount++;
}

//Updateで処理した結果を反映させた表示をDarwで行う
void SceneMain::Draw() const
{
	DrawFormatString(8, 8, GetColor(255,255,255), "%d", m_frameCount);
	m_player.Draw();
}
