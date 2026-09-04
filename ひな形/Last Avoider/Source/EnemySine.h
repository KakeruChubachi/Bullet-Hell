#pragma once
#include"Enemy.h"
class EnemySine : public Enemy
{
public :
	EnemySine(int sx,int sy,int rad);
	~EnemySine();
	void MoveEnemy()override;
private:
	int elapsedTime;
	float dfaultPosition;
};

