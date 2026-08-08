#include "GameOverScene.h"
#include"Score.h"
#include"Grazed.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
	if (CheckHitKey(KEY_INPUT_R))
	{
		SceneManager::ChangeScene("PLAY");
	}
}

void GameOverScene::Draw()
{
	DrawString(0, 0, "GAME OVER", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
	DrawString(100, 300, "Push [R]Key To RETRY", GetColor(255, 255, 255));
	//スコア表示
	char scoreText[64];
	sprintf_s(scoreText, "SCORE: %d", Score::Get());
	DrawString(600, 0, scoreText, GetColor(255, 255, 255));
	//グレイズ数を表示
	char grazedText[64];
	sprintf_s(grazedText, "GRAZED: %d", Grazed::Get());
	DrawString(600, 20, grazedText, GetColor(255, 255, 255));
}
