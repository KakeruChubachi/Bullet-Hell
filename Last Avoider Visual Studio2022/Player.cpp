#include "Player.h"

Player::Player()
{
	hImage = LoadGraph("Data/Image/material/PNG/playerShip2_red.png");
	x = 200;
	y = 200;
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Draw()
{
	DrawGraph(x, y, hImage,TRUE);
}
