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
	//�O���t�B�b�N�̃n���h��
	int m_playerHandle;
	int m_mapHandle;


	//�v���C���[
	Player* m_pPlayer;

	//�}�b�v
	Map* m_pMap;
};
