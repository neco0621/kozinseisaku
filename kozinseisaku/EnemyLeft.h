#pragma once
#include "EnemyBase.h"
class EnemyLeft : public EnemyBase
{
public:
	EnemyLeft();
	virtual ~EnemyLeft();

	//今のところ継承元をそのまま使うので不要
	//void Init();
	//void Draw();

	virtual void Update() override;
	virtual void Start() override;
};

