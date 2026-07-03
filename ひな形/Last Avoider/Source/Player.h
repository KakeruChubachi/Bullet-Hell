#pragma once
#include"../Library/GameObject.h"
class Player : GameObject
{
public:
	//基本機能
	Player();
	Player(float sx, float sy ,bool isActive);
	~Player();
	void Update()override;
	void Draw() override;
	float GetX() { return x; }
	float GetY() { return y; }
	bool IsActive() const { return isActive; }
	//被弾機能
	bool IsHit(float bx,float by,float rad);
	void TakeDamage();
private:
	float x, y;
	int hImage;
	bool isActive;
	int hp;
	float unbeatableTime;
};

