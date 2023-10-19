#include "Player.h"
#include "DxLib.h"

Player::Player():

	m_x(120),
	m_y(120)
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
}

void Player::Draw() const
{
	DrawCircle(m_x, m_y, 32, GetColor(255, 255, 0), true);
}
