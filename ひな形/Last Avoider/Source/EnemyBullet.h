#pragma once
#include"../Library/GameObject.h"
#include"Player.h"

class EnemyBullet : public GameObject
{
public:
	EnemyBullet();
	EnemyBullet(float sx, float sy, float vx, float vy, float bulletSize = 2.0f);
	~EnemyBullet();
	void Update()override;
	void Draw()override;
	bool CheckGraze(float px, float py, float grazerad);
	Player* p;
	
private:
	float x, y;
	int hImage;
	float velocityX;
	float velocityY;
	float size;
	bool isActive = true;
	bool isGrazed = false;
};

