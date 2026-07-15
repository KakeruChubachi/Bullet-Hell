#pragma once
#include "../Library/SceneBase.h"
#include"Player.h"
#include"Enemy.h"

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
	Enemy *enemy;
};
