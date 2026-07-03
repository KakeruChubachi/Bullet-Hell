#include "Enemy.h"

Enemy::Enemy()
{
	hImage = LoadGraph("data/Image/material/PNG/Enemies/enemyBlue2.png");
	x = 300;
	y = 100;

}

Enemy::Enemy(int sx, int sy, int rad)
{
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	DrawGraph((int)x, (int)y, hImage, TRUE);
}
