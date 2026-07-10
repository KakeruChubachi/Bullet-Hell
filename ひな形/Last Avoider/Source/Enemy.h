#pragma once
#include"../Library/GameObject.h"
#include"EnemyBullet.h"

class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(int sx, int sy, int rad);
	~Enemy();
	void Update()override;
	void Draw()override;
	void FireBullet(float sx, float sy);
private:
	float x, y;
	int hImage;
	int hbImage;
	float radius;
	bool isActive;

	float shottimer = 0.0f;
	const float SHOT_INTERVAL = 60.0f;
};

