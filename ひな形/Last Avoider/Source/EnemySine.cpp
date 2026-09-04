#include "EnemySine.h"
#include"Screen.h"
#include<cmath>

EnemySine::EnemySine(int sx,int sy,int rad) : Enemy(sx, sy, rad)
{
	elapsedTime = 0;
	dfaultPosition = sx;
}

EnemySine::~EnemySine()
{
}

void EnemySine::MoveEnemy()
{
	elapsedTime++;
	y += ENEMY_MOVE_SPEED/2;
	x = dfaultPosition + sin(elapsedTime * 0.06f) * 80.0f;
	if (y >= Screen::HEIGHT + ENEMY_VERTICAL_CENTER_SIZE)
	{
		isActive = false;
		DestroyMe();
	}
}
