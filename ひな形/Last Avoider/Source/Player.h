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
	float GetCenterX() { return GetX() + PLAYER_SIDEWAYS_CENTER_SIZE; }
	float GetY() { return y; }
	float GetCenterY() { return GetY() + PLAYER_VERTICAL_CENTER_SIZE ;}
	int GetHP() { return hp; }
	bool IsActive() const { return isActive; }
	void FireBullet(float sx, float sy);
	//被弾機能
	bool IsHit(float bx,float by,float rad);
	void TakeDamage();
private:
	static constexpr float MOVE_SPEED = 5.0f;
	static constexpr float PLAYER_SIDEWAYS_CENTER_SIZE = 112 / 2;
	static constexpr float PLAYER_VERTICAL_CENTER_SIZE = 75 / 2;
	static constexpr float PLAYER_GRAZE_RAD_SIZE = (75 / 2) * 1.5f;


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

