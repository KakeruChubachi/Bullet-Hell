#include "PlayScene.h"
#include"Player.h"
#include"Enemy.h"


PlayScene::PlayScene()
{
	
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
	player.Update();
}

void PlayScene::Draw()
{
	player.Draw();
	enemy.Draw();
	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
