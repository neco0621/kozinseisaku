#pragma once
#include "EnemyBase.h"
class EnemyLeft : public EnemyBase
{
public:
	EnemyLeft();
	virtual ~EnemyLeft();

	//���̂Ƃ���p���������̂܂܎g���̂ŕs�v
	//void Init();
	//void Draw();

	virtual void Update() override;
	virtual void Start() override;
};

