#pragma once
#include "Player.h"
class SceneMain
{
public:
	SceneMain();	//�R���X�g���N�^	���������m�ۂ��ꂽ�Ƃ��ɌĂ΂��֐�
	~SceneMain();	//�f�X�g���N�^		���������������鎞�ɌĂ΂��֐�

	void Init();
	void Update();
	void Draw() const;	//�֐���const��t���邱�Ƃł��̊֐��̓�����
						//�����o�[�ϐ���ύX�ł��Ȃ��Ȃ�

private:

	int m_frameCount;

	Player m_player;

};

