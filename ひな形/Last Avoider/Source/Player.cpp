#include "Player.h"
#include"PlayerBullet.h"
#include"GameOverScene.h"
#include"Score.h"
#include"Screen.h"

Player::Player()
{
	hImage = LoadGraph("data/Image/material/PNG/playerShip2_red.png");
	x = 300;
	y = 500;
	hp = 10;
	isActive = true;
	unbeatableTime = 0;
}

Player::Player(float sx, float sy ,bool _isActive)
{
	hImage = LoadGraph("data/Image/material/PNG/playerShip2_red.png");
	x = sx;
	y = sy;
	hp = 10;
	isActive = _isActive;
	unbeatableTime = 0;
}

Player::~Player()
{
}

void Player::Update()
{
	if(CheckHitKey(KEY_INPUT_LSHIFT))
	{
		if(CheckHitKey(KEY_INPUT_W)) y -= LOW_MOVE_SPPED;
		if(CheckHitKey(KEY_INPUT_S)) y += LOW_MOVE_SPPED;
		if(CheckHitKey(KEY_INPUT_A)) x -= LOW_MOVE_SPPED;
		if(CheckHitKey(KEY_INPUT_D)) x += LOW_MOVE_SPPED;
	}
	else
	{
	//à⁄ìÆèàóù
	if (CheckHitKey(KEY_INPUT_W)) y -= MOVE_SPEED;
	if (CheckHitKey(KEY_INPUT_S)) y += MOVE_SPEED;
	if (CheckHitKey(KEY_INPUT_A)) x -= MOVE_SPEED;
	if (CheckHitKey(KEY_INPUT_D)) x += MOVE_SPEED;
	}
	if (x < 0) x = 0;
	if (x > Screen::WIDTH - 112) x = Screen::WIDTH - 112;
	if (y < 0) y = 0;
	if (y > Screen::HEIGHT - 75) y = Screen::HEIGHT - 75;
	//ñ≥ìGéûä‘
	if (unbeatableTime > 0)
	{
		unbeatableTime--;
	}
	bool nowSpaceKey = CheckHitKey(KEY_INPUT_SPACE) != 0;
	if(nowSpaceKey && !prevSpaceKey)
	{
		FireBullet(x + PLAYER_SIDEWAYS_CENTER_SIZE, y);
	}
	prevSpaceKey = nowSpaceKey;
}

void Player::Draw()
{
	if(unbeatableTime > 0)
	{
		if(((int)unbeatableTime / 4) % 2 == 0)
		{
			return;//ï`âÊÇµÇ»Ç¢ÉtÉåÅ[ÉÄ
		}
	}
	DrawGraph((int)x, (int)y, hImage, TRUE);
}

bool Player::IsHit(float bx,float by,float rad)
{
	float dx = bx - (x + PLAYER_VERTICAL_CENTER_SIZE);
	float dy = by - (y + PLAYER_SIDEWAYS_CENTER_SIZE);
	float distance = dx * dx + dy * dy;
	float radsum = PLAYER_VERTICAL_CENTER_SIZE + rad;
	if (distance < radsum * radsum)
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
	if(hp <= 0)
	{
		SceneManager::ChangeScene("GAMEOVER");
		isActive = false;
		return;
	}
	unbeatableTime = UNBEATABLE_TIME;
}

void Player::FireBullet(float sx, float sy)
{
	new PlayerBullet(sx, sy, 0.0f, -5.0f, 13.0f); // è„ï˚å¸Ç…ë¨ìx5Ç≈î≠éÀ
}
