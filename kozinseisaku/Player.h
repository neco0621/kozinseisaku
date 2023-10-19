#pragma once
#include "Vec2.h"
#include "Rect.h"

class SceneMain;
class Player
{
public:
	Player(SceneMain* pMain);
	~Player();

	//メンバー変数にアクセスする
	void SetHandle(int handle) { m_handle = handle; }
	//プレイヤーの現在位置を取得する
	Vec2 GetPos() const { return m_pos; }
	//プレイヤーの当たり判定を取得する
	Rect GetColRect() const { return m_colRect; }


	void Init();
	void Update();
	void Draw() ;

private:

private:
	SceneMain* m_pMain;

	int m_handle;	//グラフィックのハンドル

	//表示位置
	Vec2 m_pos;

	//当たり判定用の矩形
	Rect m_colRect;
};

