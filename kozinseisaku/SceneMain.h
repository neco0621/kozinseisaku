#pragma once
#include "Player.h"
class SceneMain
{
public:
	SceneMain();	//コンストラクタ	メモリが確保されたときに呼ばれる関数
	~SceneMain();	//デストラクタ		メモリが解放される時に呼ばれる関数

	void Init();
	void Update();
	void Draw() const;	//関数にconstを付けることでその関数の内部で
						//メンバー変数を変更できなくなる

private:

	int m_frameCount;

	Player m_player;

};

