#include "Player.h"
#include "DxLib.h"
#include "Game.h"
#include "SceneMain.h"

namespace
{
	//移動速度
	constexpr float kSpeed = 3.5f;
	//ジャンプの初速度
	constexpr float kJumpV0 = -12.0f;
	//ジャンプの重力
	constexpr float kGravity = 0.3f;

	//キャラクターのサイズ
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
	//padの十字キーを使用してプレイヤーを移動させる
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	bool isMove = false;
	//移動量を持つようにする
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

	//斜め移動の場合も同じ速さで移動するようにする

	//ベクトルの正規化
	move.normalize();

	//ベクトルの長さをkspeedにする
	move *= kSpeed;

	//座標とベクトルの足し算
	m_pos += move;
}

void Player::Draw()
{
	DrawGraph(m_pos.x, m_pos.y, m_handle, true);
}
