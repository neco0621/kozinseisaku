#pragma once
#include "EnemyBase.h"
class EnemyLeft : public EnemyBase
{
public:
	EnemyLeft();
	virtual ~EnemyLeft();

	//¡‚Ì‚Æ‚±‚ëŒp³Œ³‚ğ‚»‚Ì‚Ü‚Üg‚¤‚Ì‚Å•s—v
	//void Init();
	//void Draw();

	virtual void Update() override;
	virtual void Start() override;
};

