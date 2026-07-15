#pragma once
#include"../Library/GameObject.h"

class PlayerBullet : public GameObject
{
private:
	float x, y;
	int hImage;
	float velocityX;
	float velocityY;
	float size;
	bool isActive = true;
public:
	PlayerBullet();
	PlayerBullet(float sx, float sy, float vx, float vy, float bulletSize = 2.0f);
	~PlayerBullet();
	void Update()override;
	void Draw()override;
	bool IsActive() { return isActive; }
	float GetX() { return x; }
	float GetY() { return y; }
	float GetSize() { return size; }
};

