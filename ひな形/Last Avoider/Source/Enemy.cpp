#include "Enemy.h"
#include "EnemyBullet.h"
#include "Screen.h"

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
	FireBullet(x, y);
}

void Enemy::Draw()
{
	DrawGraph((int)x, (int)y, hImage, TRUE);
}

void Enemy::FireBullet(float sx, float sy)
{
	shottimer++;
	if (shottimer < SHOT_INTERVAL) return;

	new EnemyBullet(sx, sy, 0.0f, 5.0f, 13.0f); // ‰º•ûŒü‚É‘¬“x5‚Å”­ŽË
	shottimer = 0;
}