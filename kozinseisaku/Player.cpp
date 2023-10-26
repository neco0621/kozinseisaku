#include "Player.h"
#include "DxLib.h"
#include "Game.h"
#include "SceneMain.h"

namespace
{
	//�ړ����x
	constexpr float kSpeed = 3.5f;
	//�W�����v�̏����x
	constexpr float kJumpV0 = -12.0f;
	//�W�����v�̏d��
	constexpr float kGravity = 0.3f;

	//�L�����N�^�[�̃T�C�Y
	constexpr int kWidth = 32;
	constexpr int kHeight = 32;
}

Player::Player(SceneMain* pMain) :
	m_pMain(pMain),
	m_handle(-1),
	m_pos(Game::kScreenWidth / 2, Game::kScreenHeight - 50)
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
	//pad�̏\���L�[���g�p���ăv���C���[���ړ�������
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	bool isMove = false;
	//�ړ��ʂ����悤�ɂ���
	Vec2 move{ 0.0f,0.0f };

	if ((pad & PAD_INPUT_LEFT) != 0)
	{
		//m_pos.x -= kSpeed;
		move.x -= kSpeed;
		isMove = true;
	}
	if ((pad & PAD_INPUT_RIGHT) != 0)
	{
		//m_pos.x += kSpeed;
		move.x += kSpeed;
		isMove = true;
	}
	if ((PAD_INPUT_A & KEY_INPUT_SPACE) != 0)
	{

	}

	//�΂߈ړ��̏ꍇ�����������ňړ�����悤�ɂ���

	//�x�N�g���̐��K��
	move.normalize();

	//�x�N�g���̒�����kspeed�ɂ���
	move *= kSpeed;

	//���W�ƃx�N�g���̑����Z
	m_pos += move;
}

void Player::Draw()
{
	DrawGraph(m_pos.x, m_pos.y, m_handle, true);
}
