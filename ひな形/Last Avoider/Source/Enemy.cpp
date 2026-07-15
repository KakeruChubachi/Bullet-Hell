#include "Enemy.h"
#include "EnemyBullet.h"
#include "Screen.h"
#include"Score.h"

static constexpr float ENEMY_VERTICAL_CENTER_SIZE = 104 / 2;
static constexpr float ENEMY_SIDEWAYS_CENTER_SIZE = 84 / 2;

Enemy::Enemy()
{
	hImage = LoadGraph("data/Image/material/PNG/Enemies/enemyBlue2.png");
	x = 300;
	y = 100;
	radius = ENEMY_VERTICAL_CENTER_SIZE;
	hp = 3;	
	isActive = true;
	unbeatableTime = 0;
}

Enemy::Enemy(int sx, int sy, int rad)
{
	hImage = LoadGraph("data/Image/material/PNG/Enemies/enemyBlue2.png");
	x = sx;
	y = sy;
	radius = rad;
	hp = 3;
	isActive = true;
	unbeatableTime = 0;
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

bool Enemy::IsHit(float bx, float by, float rad)
{
	if (DestroyRequested()) return false;   // © ’Ç‰Á:‚·‚Å‚ÉŽ€–Sˆ—Ï‚Ý‚È‚ç–³Ž‹
	float dx = bx - (x + ENEMY_SIDEWAYS_CENTER_SIZE);
	float dy = by - (y + ENEMY_VERTICAL_CENTER_SIZE);
	float distance = dx * dx + dy * dy;
	float radsum = radius + rad;
	if (distance < radsum * radsum)
	{
		TakeDamage();
		return true;
	}
	return false;
}

void Enemy::TakeDamage()
{
	if (unbeatableTime > 0) return;
	hp--;
	if (hp <= 0)
	{
		Score::Add(100);
		isActive = false;
		DestroyMe();
	}
}