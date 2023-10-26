#pragma once
#include <vector>
#include "Vec2.h"

class Player;
class EnemyBase;

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
	//敵キャラクターの生成
	void CreateEnemyLeft();

private:
	//グラフィックのハンドル
	int m_playerHandle;
	int m_enemyHandle;


	//プレイヤー
	Player* m_pPlayer;
	//敵
	std::vector<EnemyBase> m_pEnemy;

	//敵の登場間隔
	int m_enemyInterval;
	
};
