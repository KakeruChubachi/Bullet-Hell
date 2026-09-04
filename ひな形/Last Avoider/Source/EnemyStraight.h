#pragma once
#include"Enemy.h"
class EnemyStraight : public Enemy
{
public:
	EnemyStraight(int sx, int sy, int rad);
	~EnemyStraight();
	void MoveEnemy() override;
};

