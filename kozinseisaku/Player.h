#pragma once
class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw() const;

private:
	//�\���ʒu
	int m_x;
	int m_y;
};

