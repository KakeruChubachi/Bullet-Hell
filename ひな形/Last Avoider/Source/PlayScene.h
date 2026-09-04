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
private:
	Player* player;
	EnemyManager* enemyManager; // 既にあるはず
	int playTimer = 0;
	static constexpr int TIME_LIMIT = 3600; // 例：60秒（60fps想定）
};
