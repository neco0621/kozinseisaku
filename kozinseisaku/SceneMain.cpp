#include "SceneMain.h"
#include "DxLib.h"

SceneMain::SceneMain() : 
	m_frameCount(0)	//�R���X�g���N�^�������q�𗘗p���ď���������
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{

}

//���t���[���s��������Update�ɋL�q����
void SceneMain::Update()
{
	m_frameCount++;
}

//Update�ŏ����������ʂ𔽉f�������\����Darw�ōs��
void SceneMain::Draw() const
{
	DrawFormatString(8, 8, GetColor(255,255,255), "%d", m_frameCount);
	m_player.Draw();
}
