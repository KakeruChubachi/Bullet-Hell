#pragma once
#include"../Library/GameObject.h"

class EnemyBullet : GameObject
{
public:
	EnemyBullet();
	EnemyBullet(float sx, float sy, float vx, float vy, float bulletSize = 2.0f);
	~EnemyBullet();
	void Update()override;
	void Draw()override;
	
private:
	float x, y;
	int hImage;
	float velocityX;
	float velocityY;
	float size;
	bool isActive;
};

