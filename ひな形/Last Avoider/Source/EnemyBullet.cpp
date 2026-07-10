#include "EnemyBullet.h"
#include"Player.h"
static constexpr float PLAYER_VERTICAL_CENTER_SIZE = 112 / 2;
static constexpr float PLAYER_SIDEWAYS_CENTER_SIZE = 75 / 2;

EnemyBullet::EnemyBullet()
{
	hImage = LoadGraph("data/Image/material/PNG/Lasers/laserBlue12.png");
	x = 0;
	y = 0;
	velocityX = 0;
	velocityY = 0;
	isActive = true;
}

EnemyBullet::EnemyBullet(float sx, float sy, float vx, float vy, float bulletSize)
{
	hImage = LoadGraph("data/Image/material/PNG/Lasers/laserBlue12.png");
	x = sx;
	y = sy;
	velocityX = vx;
	velocityY = vy;
	size = bulletSize;
	isActive = true;
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update()
{
	if (!isActive)return;

	x += velocityX;
	y += velocityY;
	float bulletCenterX, bulletCenterY;
	bulletCenterX = x + 13.0 / 2.0;
	bulletCenterY = y + 57.0 / 2.0;

	Player* p = FindGameObject<Player>();
	if (p == nullptr) return;   // © ’Ç‰ÁFPlayer‚ªŒ©‚Â‚©‚ç‚È‚¢ê‡‚Í‰½‚à‚µ‚È‚¢
	float BulletRadius = 13 / 2.0f;

	if (p->IsHit(bulletCenterX, bulletCenterY, BulletRadius))
	{
		DestroyMe();
		return;
	}
}

void EnemyBullet::Draw()
{
	DrawGraph((int)x, (int)y, hImage, TRUE);
}
