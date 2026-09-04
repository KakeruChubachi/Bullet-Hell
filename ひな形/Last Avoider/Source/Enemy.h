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
	virtual void MoveEnemy();
	void Draw()override;
	float GetX() { return x; }
	float GetY() { return y; }
	bool IsActive() { return isActive; }	
	bool IsHit(float bx, float by, float rad);
	void TakeDamage();
	void FireBullet(float sx, float sy);
protected:
	float x, y;
	int hImage;
	int hbImage;
	float radius;
	bool isActive;
	int hp;
	float unbeatableTime;
	bool MoveLeft = true;

	float shottimer = 0.0f;
	const float SHOT_INTERVAL = 60.0f;
	float ENEMY_MOVE_SPEED = 2.0f;
	float ENEMY_VERTICAL_CENTER_SIZE = 104 / 2;
	float ENEMY_SIDEWAYS_CENTER_SIZE = 84 / 2;
};

