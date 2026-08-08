#include "EnemyBullet.h"
#include"Player.h"
#include"Score.h"
#include"Grazed.h"

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
	else if (!p->IsHit(bulletCenterX, bulletCenterY, BulletRadius))
	{
		CheckGraze(p->GetCenterX(),p->GetCenterY(),p->GetGrazeRad());
	}
}

void EnemyBullet::Draw()
{
	DrawGraph((int)x, (int)y, hImage, TRUE);
}

bool EnemyBullet::CheckGraze(float px, float py, float grazerad)
{
	float bulletCenterX, bulletCenterY,bulletRadius;
	bulletCenterX = x + 13.0 / 2.0;
	bulletCenterY = y + 57.0 / 2.0;
	float dx = px -  bulletCenterX;
	float dy = py - bulletCenterY;
	float distance = dx * dx + dy * dy;
	bulletRadius = 13.0 / 2.0;
	float radsum = grazerad + bulletRadius;
	if (distance < radsum * radsum)
	{
		if (!isGrazed) 
		{
			isGrazed = true;
			Score::Add(10);
			Grazed::AddGrazed(1);
			return true;
		}
	}
	return false;
}
