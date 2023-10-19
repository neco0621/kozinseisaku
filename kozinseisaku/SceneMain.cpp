#include "SceneMain.h"
#include "DxLib.h"
#include "Player.h"
#include "Pad.h"
#include "Rect.h"
#include <cassert>

namespace
{
	//��x�ɓo��ł���ő�̐�
	constexpr int kEnemyMax = 64;
	//���t���[�����ɓG���o�ꂷ�邩
	constexpr int kEnemyInterval = 60;

	//��ʓ��Ɉ�x�ɏo�Ă���e�̍ő吔
	constexpr int kShotMax = 256;
}

SceneMain::SceneMain()
{
	//�O���t�B�b�N�̃��[�h
	m_playerHandle = LoadGraph(L"data/player.png");
	assert(m_playerHandle != -1);
	//�v���C���[�̃������m��
	m_pPlayer = new Player{ this };
	m_pPlayer->SetHandle(m_playerHandle);	//Player�ɃO���t�B�b�N�n���h����n��
}

SceneMain::~SceneMain()
{
	//����������O���t�B�b�N���폜
	DeleteGraph(m_playerHandle);
	

	//�v���C���[�̃��������
	delete m_pPlayer;
	m_pPlayer = nullptr;
}

void SceneMain::Init()
{
	assert(m_pPlayer);	//m_pPlayer == nullptr �̏ꍇ�~�܂�

	m_pPlayer->Init();
}

void SceneMain::End()
{

}

void SceneMain::Update()
{
	m_pPlayer->Update();


	Rect playerRect = m_pPlayer->GetColRect();
}

void SceneMain::Draw()
{
	m_pPlayer->Draw();
}
