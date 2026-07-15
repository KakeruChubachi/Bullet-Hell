#include "PlayScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Score.h"


PlayScene::PlayScene()
{
	Score::Init();
	player = new Player();
	enemy =  new Enemy();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));

	//スコア表示
	char scoreText[64];
	sprintf_s(scoreText, "SCORE: %d", Score::Get());
	DrawString(600, 0, scoreText, GetColor(255, 255, 255));

	//HPを表示
	char hpText[64];
	sprintf_s(hpText, "HP: %d", player->GetHP());
	DrawString(0, 20, hpText, GetColor(255, 255, 255));
}
