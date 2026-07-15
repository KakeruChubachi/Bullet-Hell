#pragma once
#include"../Library/GameObject.h"
class Player : public GameObject
{
public:
	//基本機能
	Player();
	Player(float sx, float sy ,bool _isActive);
	~Player();
	void Update()override;
	void Draw() override;
	float GetX() { return x; }
	float GetY() { return y; }
	int GetHP() { return hp; }
	bool IsActive() const { return isActive; }
	void FireBullet(float sx, float sy);
	//被弾機能
	bool IsHit(float bx,float by,float rad);
	void TakeDamage();
private:
	float x, y;
	int hImage;
	bool isActive;
	int hp;
	float unbeatableTime;

	float shottimer = 0.0f;
	const float SHOT_INTERVAL = 10.0f;
	bool prevSpaceKey = false; // 前のフレームでSPACEが押されていたか
	const float UNBEATABLE_TIME = 120.0f; // 無敵時間のフレーム数
};

