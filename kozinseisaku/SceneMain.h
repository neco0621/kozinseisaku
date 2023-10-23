#pragma once
#include <vector>
#include "Vec2.h"

class Player;
class Map;

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	void Init();
	void End();

	void Update();
	void Draw();

private:
	//グラフィックのハンドル
	int m_playerHandle;
	int m_mapHandle;


	//プレイヤー
	Player* m_pPlayer;

	//マップ
	Map* m_pMap;
};
