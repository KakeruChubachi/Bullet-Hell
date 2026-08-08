#pragma once
#include "../Library/SceneBase.h"
#include"Player.h"
#include"Enemy.h"
#include<vector>

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
	Player *player;
	std::vector<Enemy*>enemies;
};
