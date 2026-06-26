#pragma once
#include"../Library/GameObject.h"

class Enemy : GameObject
{
public:
	Enemy();
	Enemy(int sx, int sy, int rad);
	~Enemy();
	void Update()override;
	void Draw()override;
private:
	float x, y;
	int hImage;
	float radius;
	bool isActive;
};

