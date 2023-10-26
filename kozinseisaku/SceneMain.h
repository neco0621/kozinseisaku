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
	//�G�L�����N�^�[�̐���
	void CreateEnemyLeft();

private:
	//�O���t�B�b�N�̃n���h��
	int m_playerHandle;
	int m_enemyHandle;


	//�v���C���[
	Player* m_pPlayer;
	//�G
	std::vector<EnemyBase> m_pEnemy;

	//�G�̓o��Ԋu
	int m_enemyInterval;
	
};
