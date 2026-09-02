#pragma once
#include "../Library/SceneBase.h"
#include"Player.h"
#include"Enemy.h"
#include<vector>
#include"EnemyManager.h"

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
	EnemyManager* enemyManager;
};
