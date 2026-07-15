#include "PlayerBullet.h"
#include"Enemy.h"	
#include"Screen.h"

PlayerBullet::PlayerBullet()
{
	hImage = LoadGraph("data/Image/material/PNG/Lasers/laserRed02.png");
	x = 0;
	y = 0;
	velocityX = 0;
	velocityY = 0;
	isActive = true;	
}

PlayerBullet::PlayerBullet(float sx, float sy, float vx, float vy, float bulletSize)
{
	hImage = LoadGraph("data/Image/material/PNG/Lasers/laserRed02.png");
	x = sx;
	y = sy;
	velocityX = vx;
	velocityY = vy;
	size = bulletSize;
	isActive = true;
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Update()
{
	if(!isActive)return;

	x += velocityX;
	y += velocityY;
	float bulletCenterX, bulletCenterY;
	bulletCenterX = x + 13.0 / 2.0;
	bulletCenterY = y + 37.0 / 2.0;
	float BulletRadius = 37 / 2.0f;
	for (Enemy* e : FindGameObjects<Enemy>()) {

		if (e->IsHit(bulletCenterX, bulletCenterY, BulletRadius))
		{
			DestroyMe();
			return;
		}
	}
	
	// 画面外に出たら非アクティブにする
	if (x < 0 || x > Screen::WIDTH || y < 0 || y > Screen::HEIGHT)
	{
		isActive = false;
		DestroyMe();
	}
}

void PlayerBullet::Draw()
{
	DrawGraph((int)x, (int)y, hImage, TRUE);
}
