#include "Player.h"

static constexpr float MOVE_SPEED = 5.0f;
static constexpr float PLAYER_VERTICAL_CENTER_SIZE = 112 / 2;
static constexpr float PLAYER_SIDEWAYS_CENTER_SIZE = 75 / 2;


Player::Player()
{
	hImage = LoadGraph("data/Image/material/PNG/playerShip2_red.png");
	x = 300;
	y = 500;
	hp = 3;
	isActive = true;
}

Player::Player(float sx, float sy ,bool isActive)
{
	hImage = LoadGraph("data/Image/material/PNG/playerShip2_red.png");
	x = sx;
	y = sy;
	hp = 3;
	isActive = isActive;
}

Player::~Player()
{
}

void Player::Update()
{
	//ˆÚ“®ˆ—
	if (CheckHitKey(KEY_INPUT_W)) y -= MOVE_SPEED;
	if (CheckHitKey(KEY_INPUT_S)) y += MOVE_SPEED;
	if (CheckHitKey(KEY_INPUT_A)) x -= MOVE_SPEED;
	if (CheckHitKey(KEY_INPUT_D)) x += MOVE_SPEED;
	//–³“GŽžŠÔ
	if (unbeatableTime > 0)
	{
		unbeatableTime--;
	}
}

void Player::Draw()
{
	DrawGraph((int)x, (int)y, hImage, TRUE);
}

bool Player::IsHit()
{
	float distance = PLAYER_SIDEWAYS_CENTER_SIZE;
	if (distance < 0)
	{
		TakeDamage();
		return true;
	}
	return false;
}

void Player::TakeDamage()
{
	if (unbeatableTime > 0) return;
	hp--;
}
