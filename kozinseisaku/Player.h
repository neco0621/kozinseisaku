#pragma once
#include "Vec2.h"
#include "Rect.h"

class SceneMain;
class Player
{
public:
	Player(SceneMain* pMain);
	~Player();

	//�����o�[�ϐ��ɃA�N�Z�X����
	void SetHandle(int handle) { m_handle = handle; }
	//�v���C���[�̌��݈ʒu���擾����
	Vec2 GetPos() const { return m_pos; }
	//�v���C���[�̓����蔻����擾����
	Rect GetColRect() const { return m_colRect; }


	void Init();
	void Update();
	void Draw() ;

private:

private:
	SceneMain* m_pMain;

	int m_handle;	//�O���t�B�b�N�̃n���h��

	//�\���ʒu
	Vec2 m_pos;

	//�����蔻��p�̋�`
	Rect m_colRect;
};

