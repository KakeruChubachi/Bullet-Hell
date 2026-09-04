#include "EnemyStraight.h"
#include"Screen.h"

EnemyStraight::EnemyStraight(int sx, int sy, int rad) : Enemy(sx, sy, rad)
{
}

EnemyStraight::~EnemyStraight()
{
}

void EnemyStraight::MoveEnemy()
{
	y += ENEMY_MOVE_SPEED /2;
	if(y >= Screen::HEIGHT + ENEMY_VERTICAL_CENTER_SIZE)
	{
		isActive = false;
		DestroyMe();
	}
}
