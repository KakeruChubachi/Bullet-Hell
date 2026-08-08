#include "PlayScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Score.h"
#include"Grazed.h"


PlayScene::PlayScene()
{
	Score::Init();
	Grazed::Init();
	player = new Player();
	for(int i = 0; i < 5; i++)
	{
		Enemy* enemy = new Enemy(100 + i * 200, 100, 50);
		enemies.push_back(enemy);
	}
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

	//グレイズ数を表示
	char grazedText[64];
	sprintf_s(grazedText, "GRAZED: %d", Grazed::Get());
	DrawString(600, 20, grazedText, GetColor(255, 255, 255));

	//HPを表示
	char hpText[64];
	sprintf_s(hpText, "HP: %d", player->GetHP());
	DrawString(0, 20, hpText, GetColor(255, 255, 255));
}
